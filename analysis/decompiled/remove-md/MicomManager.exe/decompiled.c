/* Automatic Ghidra pseudocode. Not original source; not runtime-verified. */

/* 00011000 FUN_00011000 */

/* Boundary evidence: original MIPS .pdata 00011000..000110b3. Semantic name remains unreviewed. */

undefined4 *
FUN_00011000(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  FUN_0002d7e0(param_1,param_2,param_3);
  *param_1 = &PTR_FUN_000459c8;
  param_1[3] = param_4;
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[6] = 0;
  param_1[7] = 0;
  param_1[8] = 0;
  param_1[9] = 0;
  param_1[10] = 0;
  param_1[0xb] = 0;
  param_1[0xc] = 0;
  param_1[0x10] = 0;
  param_1[0x13] = 0;
  param_1[0x14] = 0;
  param_1[0x12] = 0;
  param_1[0x16] = 0;
  param_1[0x17] = 0;
  param_1[0x18] = 0;
  param_1[0x15] = 1;
  param_1[0x11] = 0;
  param_1[0xe] = 0;
  param_1[0xf] = 0;
  *(undefined1 *)(param_1 + 0x1a) = 0;
  *(undefined1 *)((int)param_1 + 0x69) = 0;
  *(undefined1 *)((int)param_1 + 0x6a) = 0;
  *(undefined1 *)((int)param_1 + 0x6b) = 0;
  *(undefined1 *)(param_1 + 0x1b) = 0;
  param_1[0x19] = 0;
  return param_1;
}



/* 000110b4 FUN_000110b4 */

void FUN_000110b4(int param_1)

{
  if (*(int *)(param_1 + 100) == 1) {
    DAT_00057354 = (uint)*(byte *)(param_1 + 0x69) << 0x15 |
                   (uint)*(byte *)(param_1 + 0x68) << 0xd | DAT_00057354 & 0xe0001fff;
    DAT_00057358 = *(undefined1 *)(param_1 + 0x6a);
    DAT_00057359 = *(undefined1 *)(param_1 + 0x6b);
    DAT_0005735a = *(undefined1 *)(param_1 + 0x6c);
  }
  return;
}



/* 00011128 FUN_00011128 */

/* Boundary evidence: original MIPS .pdata 00011128..00011217. Semantic name remains unreviewed. */

void FUN_00011128(int param_1,uint param_2)

{
  int iVar1;
  undefined1 local_20 [8];
  
  iVar1 = FUN_0001c860(DAT_00055498);
  if ((iVar1 == 1) && ((*(uint *)(param_1 + 0x40) < 6 || (10 < *(uint *)(param_1 + 0x40))))) {
    DAT_00057364 = (param_2 ^ DAT_00057364) & 0x3f ^ DAT_00057364;
    if (*(int *)(param_1 + 0x4c) == 1) {
      *(undefined4 *)(param_1 + 0x4c) = 0;
    }
    local_20[0] = (undefined1)param_2;
    if (*(int *)(DAT_00055498 + 0x5c) == 0) {
      FUN_00019030(DAT_000553dc,param_2,*(undefined4 *)(param_1 + 0x4c));
    }
    FUN_00015f10(DAT_000553cc,5,1,0x12,(int)local_20,1,0x32);
  }
  return;
}



/* 00011218 FUN_00011218 */

uint FUN_00011218(void)

{
  return DAT_00057364 & 0x3f;
}



/* 0001122c FUN_0001122c */

/* Boundary evidence: original MIPS .pdata 0001122c..0001129b. Semantic name remains unreviewed. */

void FUN_0001122c(int param_1,int param_2)

{
  undefined1 local_res4 [12];
  
  DAT_00057354 = (param_2 << 10 ^ DAT_00057354) & 0x400 ^ DAT_00057354;
  local_res4[0] = (undefined1)param_2;
  *(undefined1 *)(*(int *)(param_1 + 0xc) + 0x679) = local_res4[0];
  FUN_00015f10(DAT_000553cc,5,1,0x13,(int)local_res4,1,0x32);
  return;
}



/* 0001129c FUN_0001129c */

/* Boundary evidence: original MIPS .pdata 0001129c..00011303. Semantic name remains unreviewed. */

void FUN_0001129c(int param_1,int param_2)

{
  undefined1 local_res4 [12];
  
  DAT_00057354 = (param_2 << 7 ^ DAT_00057354) & 0x380 ^ DAT_00057354;
  local_res4[0] = (undefined1)param_2;
  *(undefined1 *)(*(int *)(param_1 + 0xc) + 0x673) = local_res4[0];
  FUN_00015b90(DAT_000553cc,9,0x40,(int)local_res4,1,0x32);
  return;
}



/* 00011304 FUN_00011304 */

/* Boundary evidence: original MIPS .pdata 00011304..00011377. Semantic name remains unreviewed. */

void FUN_00011304(int param_1,int param_2)

{
  undefined1 local_res4 [12];
  
  DAT_00057354 = param_2 << 0x15 | DAT_00057354 & 0xe01fffff;
  local_res4[0] = (undefined1)param_2;
  *(undefined1 *)(*(int *)(param_1 + 0xc) + 0x675) = local_res4[0];
  FUN_00015f10(DAT_000553cc,5,1,0x20,(int)local_res4,1,0x32);
  return;
}



/* 00011378 FUN_00011378 */

/* Boundary evidence: original MIPS .pdata 00011378..000113eb. Semantic name remains unreviewed. */

void FUN_00011378(int param_1,int param_2)

{
  undefined1 local_res4 [12];
  
  DAT_00057354 = param_2 << 0xd | DAT_00057354 & 0xffe01fff;
  local_res4[0] = (undefined1)param_2;
  *(undefined1 *)(*(int *)(param_1 + 0xc) + 0x674) = local_res4[0];
  FUN_00015f10(DAT_000553cc,5,1,0x21,(int)local_res4,1,0x32);
  return;
}



/* 000113ec FUN_000113ec */

/* Boundary evidence: original MIPS .pdata 000113ec..00011447. Semantic name remains unreviewed. */

void FUN_000113ec(int param_1,undefined1 param_2)

{
  undefined1 local_res4 [12];
  
  DAT_00057358 = param_2;
  *(undefined1 *)(*(int *)(param_1 + 0xc) + 0x676) = param_2;
  local_res4[0] = param_2;
  FUN_00015f10(DAT_000553cc,5,1,0x22,(int)local_res4,1,0x32);
  return;
}



/* 00011448 FUN_00011448 */

/* Boundary evidence: original MIPS .pdata 00011448..000114a3. Semantic name remains unreviewed. */

void FUN_00011448(int param_1,undefined1 param_2)

{
  undefined1 local_res4 [12];
  
  DAT_00057359 = param_2;
  *(undefined1 *)(*(int *)(param_1 + 0xc) + 0x677) = param_2;
  local_res4[0] = param_2;
  FUN_00015f10(DAT_000553cc,5,1,0x23,(int)local_res4,1,0x32);
  return;
}



/* 000114a4 FUN_000114a4 */

/* Boundary evidence: original MIPS .pdata 000114a4..000114ff. Semantic name remains unreviewed. */

void FUN_000114a4(int param_1,undefined1 param_2)

{
  undefined1 local_res4 [12];
  
  DAT_0005735a = param_2;
  *(undefined1 *)(*(int *)(param_1 + 0xc) + 0x678) = param_2;
  local_res4[0] = param_2;
  FUN_00015f10(DAT_000553cc,5,1,0x24,(int)local_res4,1,0x32);
  return;
}



/* 00011500 FUN_00011500 */

/* Boundary evidence: original MIPS .pdata 00011500..000115cf. Semantic name remains unreviewed. */

void FUN_00011500(int param_1,int param_2,uint param_3)

{
  int iVar1;
  undefined1 local_18 [8];
  
  if (*(int *)(param_1 + 0x4c) == 1) {
    if (param_3 == 0) {
      param_3 = DAT_00057364 & 0x3f;
    }
    *(undefined4 *)(param_1 + 0x4c) = 0;
    local_18[0] = (undefined1)param_3;
    if ((*(int *)(DAT_00055498 + 0x5c) == 0) && (param_2 == 1)) {
      FUN_00019030(DAT_000553dc,param_3,0);
    }
    FUN_00015f10(DAT_000553cc,5,1,0x12,(int)local_18,1,0x32);
    iVar1 = *(int *)(param_1 + 0x4c);
    if (*(int *)(param_1 + 0x50) != iVar1) {
      *(int *)(param_1 + 0x50) = iVar1;
      FUN_000338ac(0x75,iVar1);
    }
  }
  return;
}



/* 000115d0 FUN_000115d0 */

/* Boundary evidence: original MIPS .pdata 000115d0..000118e7. Semantic name remains unreviewed. */

void FUN_000115d0(int param_1,int param_2,int param_3)

{
  BOOL BVar1;
  wchar_t *pwVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  byte local_28 [2];
  byte local_26;
  byte local_25;
  
  if (*(int *)(param_1 + 0x34) == 1) {
    local_25 = 0;
  }
  else {
    local_25 = (byte)DAT_00057364 & 0x3f;
  }
  if (param_2 == 0) {
    NKDbgPrintfW(L"MGRMCM_AUDIOSRC_RADIO\r\n");
    local_26 = 0;
  }
  else if (param_2 == 1) {
    NKDbgPrintfW(L"MGRMCM_AUDIOSRC_AUX\r\n");
    local_26 = 2;
  }
  else {
    if (param_2 == 2) {
      pwVar2 = L"MGRMCM_AUDIOSRC_USB\r\n";
    }
    else {
      if (param_2 != 3) {
        if (param_2 == 4) {
          NKDbgPrintfW(L"MGRMCM_AUDIOSRC_DAB\r\n");
          local_26 = 1;
        }
        else if (param_2 == 5) {
          NKDbgPrintfW(L"MGRMCM_AUDIOSRC_BTAUDIO\r\n");
          local_26 = 5;
        }
        else {
          NKDbgPrintfW(L"MGRMCM_AUDIOSRC_NONE\r\n");
          local_26 = 3;
          local_25 = 0;
        }
        goto LAB_000116e8;
      }
      pwVar2 = L"MGRMCM_AUDIOSRC_IPOD\r\n";
    }
    NKDbgPrintfW(pwVar2);
    local_26 = 3;
  }
LAB_000116e8:
  FUN_00015f10(DAT_000553cc,5,1,0,(int)&local_26,2,0x32);
  *(uint *)(param_1 + 0x40) = (uint)local_26;
  if (param_3 != 0) {
    local_28[0] = 0;
    Sleep(0xfa);
    FUN_00015f10(DAT_000553cc,5,1,0x12,(int)local_28,1,0x32);
    FUN_00015f10(DAT_000553cc,5,1,0x1b,(int)local_28,1,0x32);
    goto LAB_000118b0;
  }
  if (*(int *)(param_1 + 0x4c) != 1) goto LAB_000118b0;
  NKDbgPrintfW(L"Audio Source CHANGED!!!!! VOL status: MUTE %d \n",
               *(undefined4 *)(DAT_00055498 + 0x5c));
  uVar5 = DAT_00057364;
  if (*(int *)(param_1 + 0x34) == 1) {
    uVar5 = DAT_00057364 >> 0x12;
  }
  uVar5 = uVar5 & 0x3f;
  *(undefined4 *)(param_1 + 0x4c) = 0;
  local_28[0] = (byte)uVar5;
  if (*(int *)(DAT_00055498 + 0x5c) == 0) {
    uVar4 = 0;
LAB_00011820:
    FUN_00019030(DAT_000553dc,uVar5,uVar4);
  }
  else {
    BVar1 = IsWindowVisible(*(HWND *)(param_1 + 4));
    if ((BVar1 != 0) && (*(int *)(DAT_000553dc + 0x18) == 3)) {
      uVar5 = (uint)local_28[0];
      uVar4 = *(undefined4 *)(param_1 + 0x4c);
      goto LAB_00011820;
    }
  }
  Sleep(0xfa);
  if (*(int *)(param_1 + 0x34) == 1) {
    FUN_00015f10(DAT_000553cc,5,1,0x1b,(int)local_28,1,0x32);
  }
  else {
    FUN_00015f10(DAT_000553cc,5,1,0x12,(int)local_28,1,0x32);
  }
  iVar3 = *(int *)(param_1 + 0x4c);
  if (*(int *)(param_1 + 0x50) != iVar3) {
    *(int *)(param_1 + 0x50) = iVar3;
    FUN_000338ac(0x75,iVar3);
    NKDbgPrintfW(L"Audio : Send IDM_MMCM_AMAIN_MUTE : 0x%x\r\n",*(undefined4 *)(param_1 + 0x4c));
  }
LAB_000118b0:
  *(undefined4 *)(param_1 + 0x54) = 1;
  FUN_0002d6b0(DAT_00057130);
  return;
}



/* 000118e8 FUN_000118e8 */

/* Boundary evidence: original MIPS .pdata 000118e8..000119ef. Semantic name remains unreviewed. */

void FUN_000118e8(int param_1,uint param_2)

{
  undefined1 local_18 [8];
  
  if (*(byte *)(*(int *)(param_1 + 0xc) + 0x66c) != param_2) {
    if (((((*(int *)(param_1 + 0x10) == 0) && (*(int *)(param_1 + 0x14) == 0)) &&
         (*(int *)(param_1 + 0x18) == 0)) &&
        ((*(int *)(param_1 + 0x1c) == 0 && (*(int *)(param_1 + 0x20) == 0)))) &&
       ((*(int *)(param_1 + 0x24) == 0 &&
        ((*(int *)(param_1 + 0x28) == 0 && (*(int *)(param_1 + 0x2c) == 0)))))) {
      FUN_00026cd8(DAT_00057130,1);
      *(undefined4 *)(param_1 + 0x44) = 1;
      *(uint *)(param_1 + 0x5c) = param_2;
      *(undefined4 *)(param_1 + 0x58) = 1;
      FUN_0002d814(param_1,0xfa);
      local_18[0] = 0;
      FUN_00015f10(DAT_000553cc,5,1,0x12,(int)local_18,1,100);
    }
    *(char *)(*(int *)(param_1 + 0xc) + 0x66c) = (char)param_2;
  }
  return;
}



/* 000119f0 FUN_000119f0 */

/* Boundary evidence: original MIPS .pdata 000119f0..00011cab. Semantic name remains unreviewed. */

void FUN_000119f0(int param_1,uint param_2,int param_3)

{
  uint uVar1;
  int *piVar2;
  uint uVar3;
  int *piVar4;
  undefined1 local_28 [8];
  
  piVar2 = (int *)((param_2 + 4) * 4 + param_1);
  if (*piVar2 != param_3) {
    *piVar2 = param_3;
    if (param_3 == 1) {
      uVar3 = 0;
      if (param_2 != 0) {
        piVar2 = (int *)(param_1 + 0x10);
        do {
          if (*piVar2 == 1) break;
          uVar3 = uVar3 + 1;
          piVar2 = piVar2 + 1;
        } while (uVar3 < param_2);
      }
      if (uVar3 == param_2) {
        FUN_00026cd8(DAT_00057130,1);
        *(undefined4 *)(param_1 + 0x44) = 1;
        *(uint *)(param_1 + 0x5c) = param_2;
        *(undefined4 *)(param_1 + 0x58) = 2;
        FUN_0002d814(param_1,0xfa);
        local_28[0] = 0;
        FUN_00015f10(DAT_000553cc,5,1,0x12,(int)local_28,1,0x32);
        if (param_2 == 0) {
          DAT_00055380 = 0;
          StartEC();
          DAT_00055380 = '\x01';
        }
      }
    }
    else {
      uVar3 = 0;
      if (param_2 != 0) {
        piVar4 = (int *)(param_1 + 0x10);
        do {
          if (*piVar4 == 1) break;
          uVar3 = uVar3 + 1;
          piVar4 = piVar4 + 1;
        } while (uVar3 < param_2);
      }
      uVar1 = param_2;
      if (uVar3 == param_2) {
        for (; (uVar1 < 8 && (*piVar2 != 1)); piVar2 = piVar2 + 1) {
          uVar1 = uVar1 + 1;
        }
        if (uVar1 == 8) {
          FUN_00026cd8(DAT_00057130,1);
          *(undefined4 *)(param_1 + 0x44) = 1;
          *(uint *)(param_1 + 0x5c) = (uint)*(byte *)(*(int *)(param_1 + 0xc) + 0x66c);
          *(undefined4 *)(param_1 + 0x58) = 1;
          if (*(int *)(param_1 + 0x4c) == 1) {
            *(undefined4 *)(param_1 + 0x58) = 3;
            FUN_0002d814(param_1,0);
          }
          else {
            FUN_0002d814(param_1,0xfa);
            local_28[0] = 0;
            FUN_00015f10(DAT_000553cc,5,1,0x12,(int)local_28,1,0x32);
          }
        }
        else {
          FUN_00026cd8(DAT_00057130,1);
          *(undefined4 *)(param_1 + 0x44) = 1;
          *(uint *)(param_1 + 0x5c) = uVar1;
          *(undefined4 *)(param_1 + 0x58) = 2;
          FUN_0002d814(param_1,0xfa);
          local_28[0] = 0;
          FUN_00015f10(DAT_000553cc,5,1,0x12,(int)local_28,1,0x32);
        }
      }
      if (param_2 == 0) {
        if (DAT_00055380 != '\x02') {
          EndEC();
        }
      }
      else if ((param_2 == 2) && (FUN_0002bf0c(DAT_00057130,0), *(int *)(param_1 + 0x4c) == 0)) {
        FUN_000338ac(0x75,0);
      }
    }
  }
  return;
}



/* 00011cac FUN_00011cac */

/* Boundary evidence: original MIPS .pdata 00011cac..00011d77. Semantic name remains unreviewed. */

void FUN_00011cac(int param_1)

{
  byte local_20 [8];
  
  if ((*(uint *)(param_1 + 0x40) < 6) || (*(uint *)(param_1 + 0x40) == 9)) {
    local_20[0] = 0;
    FUN_00015f10(DAT_000553cc,5,1,0x12,(int)local_20,1,0x32);
  }
  local_20[0] = (byte)(DAT_00057364 >> 0x12) & 0x3f;
  if (*(int *)(param_1 + 0x4c) == 1) {
    local_20[0] = 0;
  }
  FUN_00015f10(DAT_000553cc,5,1,0x1b,(int)local_20,1,0x32);
  return;
}



/* 00011d78 FUN_00011d78 */

/* Boundary evidence: original MIPS .pdata 00011d78..00011e37. Semantic name remains unreviewed. */

void FUN_00011d78(int param_1)

{
  byte local_10 [8];
  
  if (*(uint *)(param_1 + 0x40) < 6) {
    local_10[0] = (byte)DAT_00057364 & 0x3f;
    FUN_00015f10(DAT_000553cc,5,1,0x12,(int)local_10,1,0x32);
  }
  else if (*(uint *)(param_1 + 0x40) == 9) {
    local_10[0] = DAT_00057364._3_1_ & 0x3f;
    FUN_00015f10(DAT_000553cc,5,1,0x12,(int)local_10,1,0x32);
  }
  return;
}



/* 00011e38 FUN_00011e38 */

undefined4 FUN_00011e38(int param_1)

{
  return *(undefined4 *)(param_1 + 0x40);
}



/* 00011e40 FUN_00011e40 */

undefined4 FUN_00011e40(int param_1)

{
  return *(undefined4 *)(param_1 + 0x44);
}



/* 00011e48 FUN_00011e48 */

/* Boundary evidence: original MIPS .pdata 00011e48..00011eab. Semantic name remains unreviewed. */

void FUN_00011e48(int param_1)

{
  undefined1 local_10 [8];
  
  if (*(int *)(param_1 + 0x34) == 1) {
    local_10[0] = 0;
    FUN_00015f10(DAT_000553cc,5,1,0x1b,(int)local_10,1,0x32);
    *(undefined4 *)(param_1 + 0x34) = 0;
  }
  return;
}



/* 00011eac FUN_00011eac */

/* Boundary evidence: original MIPS .pdata 00011eac..0001211b. Semantic name remains unreviewed. */

void FUN_00011eac(void)

{
  errno_t eVar1;
  long lVar2;
  undefined1 *puVar3;
  uint uVar4;
  FILE *local_428;
  char local_424 [12];
  undefined1 local_418 [1024];
  uint local_18;
  
  local_18 = DAT_00055374;
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
    FUN_00015b90(DAT_000553cc,0xf,0x21,(int)local_418,0x80,300);
    FUN_00015b90(DAT_000553cc,0xf,0x22,(int)(local_418 + 0x80),0x80,300);
    FUN_00015b90(DAT_000553cc,0xf,0x23,(int)(local_418 + 0x100),0x80,300);
    FUN_00015b90(DAT_000553cc,0xf,0x24,(int)(local_418 + 0x180),0x80,300);
    FUN_00015b90(DAT_000553cc,0xf,0x25,(int)(local_418 + 0x200),0x80,300);
    FUN_00015b90(DAT_000553cc,0xf,0x26,(int)(local_418 + 0x280),0x80,300);
    FUN_00015b90(DAT_000553cc,0xf,0x27,(int)(local_418 + 0x300),0x80,300);
    FUN_00015b90(DAT_000553cc,0xf,0x28,(int)(local_418 + 0x380),0x80,300);
    FUN_00015f10(DAT_000553cc,5,1,0x60,0,0,200);
    DeleteFileW(L".\\Storage Card\\system\\arkamys_update.dat");
  }
  FUN_00043604(local_18);
  return;
}



/* 0001211c FUN_0001211c */

/* Boundary evidence: original MIPS .pdata 0001211c..000122db. Semantic name remains unreviewed. */

void FUN_0001211c(int param_1,int param_2)

{
  uint uVar1;
  byte local_10 [8];
  
  if (param_2 == 0) {
LAB_0001220c:
  }
  else {
    if (0xf < (DAT_00057364 & 0x3f)) {
      DAT_00057364 = DAT_00057364 & 0xffffffcf | 0xf;
    }
    if (0x3c0 < (DAT_00057364 & 0xfc0)) {
      DAT_00057364 = DAT_00057364 & 0xfffff3ff | 0x3c0;
    }
    if (0xf000 < (DAT_00057364 & 0x3f000)) {
      DAT_00057364 = DAT_00057364 & 0xfffcffff | 0xf000;
    }
    if (0x3c0000 < (DAT_00057364 & 0xfc0000)) {
      DAT_00057364 = DAT_00057364 & 0xff3fffff | 0x3c0000;
    }
    if (0xf < (DAT_00057364._3_1_ & 0x3f)) {
      DAT_00057364 = DAT_00057364 & 0xcfffffff | 0xf000000;
      goto LAB_0001220c;
    }
  }
  if (*(int *)(param_1 + 0x30) == 1) {
    FUN_00011cac(param_1);
    return;
  }
  uVar1 = *(uint *)(param_1 + 0x40);
  if (uVar1 < 6) {
    local_10[0] = (byte)DAT_00057364 & 0x3f;
  }
  else if (uVar1 == 7) {
    local_10[0] = (byte)(DAT_00057364 >> 6) & 0x3f;
  }
  else {
    if (uVar1 != 8) {
      if (uVar1 == 9) {
        local_10[0] = DAT_00057364._3_1_ & 0x3f;
        goto LAB_000122a4;
      }
      if (uVar1 != 10) goto LAB_000122a4;
    }
    local_10[0] = (byte)(DAT_00057364 >> 0xc) & 0x3f;
  }
LAB_000122a4:
  FUN_00015f10(DAT_000553cc,5,1,0x12,(int)local_10,1,0x32);
  return;
}



/* 000122dc FUN_000122dc */

/* Boundary evidence: original MIPS .pdata 000122dc..00012333. Semantic name remains unreviewed. */

undefined4 * FUN_000122dc(undefined4 *param_1,uint param_2)

{
  *param_1 = &PTR_FUN_000459c8;
  FUN_0002d85c(param_1);
  if ((param_2 & 1) != 0) {
    __3_YAXPAX_Z(param_1);
  }
  return param_1;
}



/* 00012334 FUN_00012334 */

/* Boundary evidence: original MIPS .pdata 00012334..00012833. Semantic name remains unreviewed. */

void FUN_00012334(int param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  undefined1 local_20;
  undefined1 local_1f [7];
  
  iVar1 = FUN_0001c8ac(DAT_00055498);
  if (iVar1 != 1) {
    return;
  }
  if ((((*(int *)(param_1 + 0x30) == 1) && (iVar1 = *(int *)(param_1 + 0x40), iVar1 != 7)) &&
      (iVar1 != 8)) && (iVar1 != 10)) {
    if (param_2 == 6) {
      if (*(int *)(param_1 + 0x4c) == 0) {
        *(undefined4 *)(param_1 + 0x4c) = 1;
      }
      else {
LAB_000123e0:
        *(undefined4 *)(param_1 + 0x4c) = 0;
      }
    }
    else {
      if (*(int *)(param_1 + 0x4c) == 1) goto LAB_000123e0;
      if ((param_2 == 2) || (param_2 == 4)) {
        iVar1 = 1;
      }
      else {
        iVar1 = -1;
      }
      iVar1 = iVar1 + (DAT_00057364 >> 0x12 & 0x3f);
      if (iVar1 < 1) {
        iVar1 = 1;
      }
      else if (0x1f < iVar1) {
        iVar1 = 0x1f;
      }
      DAT_00057364 = (iVar1 << 0x12 ^ DAT_00057364) & 0xfc0000 ^ DAT_00057364;
    }
    if (*(int *)(DAT_00055498 + 0x5c) == 0) {
      iVar1 = *(int *)(param_1 + 0x4c);
      if (iVar1 == 1) {
        iVar1 = 1;
        uVar2 = DAT_00057364;
      }
      else {
        uVar2 = DAT_00057364 >> 0x12;
      }
      FUN_00019030(DAT_000553dc,uVar2 & 0x3f,iVar1);
    }
    FUN_00011cac(param_1);
    goto LAB_000127e8;
  }
  iVar1 = *(int *)(param_1 + 0x40);
  if (iVar1 == 6) {
    uVar2 = DAT_00057364 >> 0x12;
LAB_00012510:
    uVar2 = uVar2 & 0x3f;
  }
  else if (iVar1 == 7) {
    uVar2 = DAT_00057364 >> 6 & 0x3f;
  }
  else {
    if (iVar1 == 8) {
LAB_000124f8:
      uVar2 = DAT_00057364 >> 0xc;
      goto LAB_00012510;
    }
    if (iVar1 == 9) {
      uVar2 = DAT_00057364 >> 0x18 & 0x3f;
    }
    else {
      if (iVar1 == 10) goto LAB_000124f8;
      uVar2 = DAT_00057364 & 0x3f;
    }
  }
  if (param_2 == 6) {
    if (iVar1 == 9) {
      FUN_000338ac(0x6e,0);
      return;
    }
    if (iVar1 == 7) {
      if (*(int *)(param_1 + 0x4c) == 0) {
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
      if (*(int *)(param_1 + 0x4c) == 0) {
        *(undefined4 *)(param_1 + 0x4c) = 1;
        goto LAB_00012718;
      }
    }
LAB_00012588:
    *(undefined4 *)(param_1 + 0x4c) = 0;
  }
  else {
    if (*(int *)(param_1 + 0x4c) == 1) goto LAB_00012588;
    if ((param_2 == 2) || (iVar4 = -1, param_2 == 4)) {
      iVar4 = 1;
    }
    if (iVar1 == 7) {
      uVar2 = (DAT_00057364 >> 6 & 0x3f) + iVar4;
      if ((int)uVar2 < 0) {
        uVar2 = 0;
      }
      else if (0x1f < (int)uVar2) {
        uVar2 = 0x1f;
      }
      DAT_00057364 = (uVar2 << 6 ^ DAT_00057364) & 0xfc0 ^ DAT_00057364;
    }
    else {
      if (iVar1 == 8) {
LAB_0001268c:
        uVar2 = (DAT_00057364 >> 0xc & 0x3f) + iVar4;
        if ((int)uVar2 < 0) {
          uVar2 = 0;
        }
        else if (0x1f < (int)uVar2) {
          uVar2 = 0x1f;
        }
        uVar3 = (uVar2 << 0xc ^ DAT_00057364) & 0x3f000;
      }
      else {
        if (iVar1 == 9) {
          uVar2 = (DAT_00057364 >> 0x18 & 0x3f) + iVar4;
          if ((int)uVar2 < 1) {
            uVar2 = 1;
          }
          else if (0x1f < (int)uVar2) {
            uVar2 = 0x1f;
          }
          uVar3 = (uVar2 - (DAT_00057364 & 0x3f)) + 5;
          if ((int)uVar3 < 0) {
            uVar3 = 0;
          }
          else if (0xf < (int)uVar3) {
            uVar3 = 0xf;
          }
          DAT_00057368 = (DAT_00057368 ^ uVar3) & 0x1f ^ DAT_00057368;
          DAT_00057364 = (uVar2 << 0x18 ^ DAT_00057364) & 0x3f000000 ^ DAT_00057364;
          goto LAB_00012718;
        }
        if (iVar1 == 10) goto LAB_0001268c;
        uVar2 = (DAT_00057364 & 0x3f) + iVar4;
        if ((int)uVar2 < 0) {
          uVar2 = 0;
        }
        else if (0x1f < (int)uVar2) {
          uVar2 = 0x1f;
        }
        uVar3 = (DAT_00057364 ^ uVar2) & 0x3f;
      }
      DAT_00057364 = uVar3 ^ DAT_00057364;
    }
  }
LAB_00012718:
  Sleep(1);
  local_20 = (undefined1)uVar2;
  if (*(int *)(DAT_00055498 + 0x5c) == 0) {
    FUN_00019030(DAT_000553dc,uVar2 & 0xff,*(undefined4 *)(param_1 + 0x4c));
  }
  if (*(int *)(param_1 + 0x4c) != 0) {
    local_20 = 0;
  }
  if (DAT_00059350 == 1) {
    local_1f[0] = 0;
    FUN_00015b90(DAT_000553cc,0,0x30,(int)local_1f,1,0x32);
  }
  FUN_00015f10(DAT_000553cc,5,1,0x12,(int)&local_20,1,0x32);
  if (DAT_00059350 == 1) {
    local_1f[0] = 1;
    FUN_00015b90(DAT_000553cc,0,0x30,(int)local_1f,1,0x32);
  }
LAB_000127e8:
  iVar1 = *(int *)(param_1 + 0x4c);
  if (*(int *)(param_1 + 0x50) != iVar1) {
    *(int *)(param_1 + 0x50) = iVar1;
    FUN_000338ac(0x75,iVar1);
    NKDbgPrintfW(L"Audio : Send IDM_MMCM_AMAIN_MUTE : 0x%x\r\n",*(undefined4 *)(param_1 + 0x4c));
  }
  return;
}



/* 00012834 FUN_00012834 */

/* Boundary evidence: original MIPS .pdata 00012834..00012a3b. Semantic name remains unreviewed. */

void FUN_00012834(int param_1,uint *param_2)

{
  bool bVar1;
  undefined3 extraout_var;
  uint uVar2;
  int iVar3;
  
  if ((*param_2 & 0xf00) == 0x200) {
    if (*(char *)((int)param_2 + 2) == '\0') {
      FUN_00011eac();
      FUN_0001129c(param_1,DAT_00057354 >> 7 & 7);
      FUN_0001122c(param_1,DAT_00057354 >> 10 & 1);
      FUN_00011304(param_1,DAT_00057354 >> 0x15 & 0xff);
      FUN_00011378(param_1,DAT_00057354 >> 0xd & 0xff);
      FUN_000113ec(param_1,DAT_00057358);
      FUN_00011448(param_1,DAT_00057359);
      FUN_000114a4(param_1,DAT_0005735a);
    }
    else if ((((*(char *)((int)param_2 + 2) == ' ') &&
              (bVar1 = FUN_0001c9b4(DAT_00055498), CONCAT31(extraout_var,bVar1) == 0)) &&
             (DAT_00059354 == 0)) && (uVar2 = (uint)(byte)param_2[1], 1 < uVar2)) {
      if (uVar2 < 4) {
        if (*(int *)(param_1 + 0x44) != 0) {
          return;
        }
        *(undefined4 *)(param_1 + 0x54) = 0;
        if (*(char *)(*(int *)(param_1 + 0xc) + 0x66c) == '\x06') {
          return;
        }
        if (*(int *)(DAT_00055498 + 0x60) != 0) {
          return;
        }
        uVar2 = (uint)(byte)param_2[1];
      }
      else {
        if (uVar2 < 6) {
          if (*(int *)(param_1 + 0x44) != 0) {
            return;
          }
          if (*(int *)(param_1 + 0x54) != 0) {
            return;
          }
          if (*(char *)(*(int *)(param_1 + 0xc) + 0x66c) == '\x06') {
            return;
          }
          iVar3 = *(int *)(DAT_00055498 + 0x60);
        }
        else {
          if (uVar2 != 6) {
            return;
          }
          if (*(int *)(param_1 + 0x44) != 0) {
            return;
          }
          if (*(char *)(*(int *)(param_1 + 0xc) + 0x66c) == '\x06') {
            return;
          }
          iVar3 = *(int *)(DAT_00055498 + 0x60);
        }
        if (iVar3 != 0) {
          return;
        }
      }
      FUN_00012334(param_1,uVar2);
    }
  }
  return;
}



/* 00012a3c FUN_00012a3c */

/* Boundary evidence: original MIPS .pdata 00012a3c..00012c6f. Semantic name remains unreviewed. */

void FUN_00012a3c(int param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  byte bVar3;
  uint uVar4;
  byte local_20;
  byte local_1f;
  
  if (param_2 == 0) {
    if ((DAT_00057354 & 1) == 0) {
      local_20 = 8;
      bVar3 = (byte)(DAT_00057364 >> 0xc);
    }
    else {
      local_20 = 10;
      bVar3 = (byte)(DAT_00057364 >> 0xc);
    }
LAB_00012b7c:
    local_1f = bVar3 & 0x3f;
    FUN_00011e48(param_1);
  }
  else {
    if (param_2 == 1) {
      local_20 = 7;
      bVar3 = (byte)(DAT_00057364 >> 6);
      goto LAB_00012b7c;
    }
    if (param_2 == 2) {
      local_20 = 9;
      iVar1 = (DAT_00057364 & 0x3f) + (DAT_00057368 & 0x1f) + -5;
      if (iVar1 < 10) {
        iVar1 = 10;
      }
      else if (0x1f < iVar1) {
        iVar1 = 0x1f;
      }
      DAT_00057364 = (iVar1 << 0x18 ^ DAT_00057364) & 0x3f000000 ^ DAT_00057364;
      uVar4 = DAT_00057364 >> 0x18 & 0x3f;
      bVar3 = (byte)uVar4;
      local_1f = bVar3;
      if ((*(int *)(param_1 + 0x34) == 1) &&
         (uVar2 = (DAT_00057364 >> 0x12 & 0x3f) - (DAT_00057368 >> 5 & 0x1f), local_1f = (byte)uVar2
         , uVar4 < (uVar2 & 0xff))) {
        local_1f = bVar3;
      }
    }
  }
  if (*(int *)(param_1 + 0x4c) == 1) {
    local_1f = 0;
  }
  FUN_00015f10(DAT_000553cc,5,1,0,(int)&local_20,2,0x32);
  if (*(int *)(param_1 + 0x4c) == 1) {
    if (param_2 == 1) {
      uVar4 = DAT_00057364 >> 6;
    }
    else {
      if (param_2 != 0) goto LAB_00012c18;
      uVar4 = DAT_00057364 >> 0xc;
    }
    Sleep(500);
    FUN_00011500(param_1,1,uVar4 & 0x3f);
  }
LAB_00012c18:
  *(uint *)(param_1 + 0x40) = (uint)local_20;
  *(undefined4 *)(param_1 + 0x54) = 1;
  FUN_0002d6b0(DAT_00057130);
  if (param_2 == 2) {
    FUN_0002bf0c(DAT_00057130,1);
    FUN_000338ac(0x75,1);
  }
  return;
}



/* 00012c70 FUN_00012c70 */

/* Boundary evidence: original MIPS .pdata 00012c70..00012d47. Semantic name remains unreviewed. */

void FUN_00012c70(int param_1,int param_2)

{
  if (*(int *)(param_1 + 0x30) != param_2) {
    NKDbgPrintfW(L"EnableNaviPrompt\r\n");
    *(int *)(param_1 + 0x30) = param_2;
    *(undefined4 *)(param_1 + 0x54) = 1;
    if (param_2 == 1) {
      *(undefined4 *)(param_1 + 0x34) = 1;
      if (*(int *)(param_1 + 0x58) == 4) {
        *(undefined4 *)(param_1 + 0x3c) = 1;
      }
      else {
        FUN_00011cac(param_1);
        Sleep(100);
      }
    }
    else if (*(int *)(param_1 + 0x4c) == 1) {
      FUN_00011e48(param_1);
    }
    else {
      FUN_00011e48(param_1);
      if (*(int *)(param_1 + 0x58) == 4) {
        *(undefined4 *)(param_1 + 0x38) = 1;
      }
      else {
        FUN_00011d78(param_1);
      }
    }
  }
  return;
}



/* 00012d48 FUN_00012d48 */

/* Boundary evidence: original MIPS .pdata 00012d48..00012df7. Semantic name remains unreviewed. */

void FUN_00012d48(int param_1)

{
  FUN_0001129c(param_1,DAT_00057354 >> 7 & 7);
  FUN_0001122c(param_1,DAT_00057354 >> 10 & 1);
  FUN_00011304(param_1,DAT_00057354 >> 0x15 & 0xff);
  FUN_00011378(param_1,DAT_00057354 >> 0xd & 0xff);
  FUN_000113ec(param_1,DAT_00057358);
  FUN_00011448(param_1,DAT_00057359);
  FUN_000114a4(param_1,DAT_0005735a);
  FUN_0001211c(param_1,0);
  return;
}



/* 00012df8 FUN_00012df8 */

/* Boundary evidence: original MIPS .pdata 00012df8..000131ff. Semantic name remains unreviewed. */

void FUN_00012df8(int param_1,undefined4 param_2,uint param_3)

{
  uint uVar1;
  int iVar2;
  undefined1 uVar3;
  
  uVar3 = (undefined1)param_3;
  switch(param_2) {
  case 100:
    FUN_000118e8(param_1,param_3);
    break;
  case 0x66:
    uVar1 = 1;
    goto LAB_00012ebc;
  case 0x67:
    uVar1 = 0;
LAB_00012ebc:
    FUN_000119f0(param_1,uVar1,(uint)(param_3 != 0));
    break;
  case 0x68:
    NKDbgPrintfW(L"%S : IDM_X_MMCM_SOEN_TA : %d\r\n","CAudio::OnMessage",param_3);
    if (param_3 == 0) {
      FUN_000119f0(param_1,2,0);
      *(undefined1 *)(*(int *)(param_1 + 0xc) + 0x669) = 0;
    }
    else {
      iVar2 = FUN_00027434(DAT_00057130);
      if (iVar2 == 1) {
        FUN_000119f0(param_1,2,1);
        *(undefined1 *)(*(int *)(param_1 + 0xc) + 0x669) = 1;
      }
      else {
        FUN_000119f0(param_1,2,0);
        NKDbgPrintfW(L"%S : IDM_X_MMCM_SOEN_TA : g_pRadio->IsTA() returns FALSE. Check out!!\r\n",
                     "CAudio::OnMessage");
      }
    }
    break;
  case 0x69:
    FUN_00012c70(param_1,(uint)(param_3 != 0));
    break;
  case 0x72:
    *(undefined1 *)(*(int *)(param_1 + 0xc) + 0x66e) = uVar3;
    FUN_00015f10(DAT_000553cc,5,1,0x12,*(int *)(param_1 + 0xc) + 0x66e,1,0x32);
    break;
  case 0x73:
    *(undefined1 *)(*(int *)(param_1 + 0xc) + 0x66f) = uVar3;
    break;
  case 0x74:
    *(undefined1 *)(*(int *)(param_1 + 0xc) + 0x670) = uVar3;
    break;
  case 0x75:
    *(undefined1 *)(*(int *)(param_1 + 0xc) + 0x671) = uVar3;
    break;
  case 0x76:
    *(undefined1 *)(*(int *)(param_1 + 0xc) + 0x672) = uVar3;
    break;
  case 0x77:
    FUN_0001129c(param_1,param_3 & 0xff);
    break;
  case 0x78:
    FUN_00011378(param_1,param_3 & 0xff);
    break;
  case 0x79:
    FUN_00011304(param_1,param_3 & 0xff);
    break;
  case 0x7a:
    FUN_000113ec(param_1,uVar3);
    break;
  case 0x7b:
    FUN_00011448(param_1,uVar3);
    break;
  case 0x7c:
    FUN_000114a4(param_1,uVar3);
    break;
  case 0x7d:
    FUN_0001122c(param_1,param_3 & 0xff);
    break;
  case 0x7f:
    FUN_00011378(param_1,(uint)*(byte *)(param_1 + 0x68));
    FUN_00011304(param_1,(uint)*(byte *)(param_1 + 0x69));
    FUN_000113ec(param_1,*(undefined1 *)(param_1 + 0x6a));
    FUN_00011448(param_1,*(undefined1 *)(param_1 + 0x6b));
    FUN_000114a4(param_1,*(undefined1 *)(param_1 + 0x6c));
  case 0x7e:
    *(undefined4 *)(param_1 + 100) = 0;
    break;
  case 0x80:
    iVar2 = *(int *)(param_1 + 0xc);
    *(undefined1 *)(param_1 + 0x68) = *(undefined1 *)(iVar2 + 0x674);
    *(undefined1 *)(param_1 + 0x69) = *(undefined1 *)(iVar2 + 0x675);
    *(undefined1 *)(param_1 + 0x6a) = *(undefined1 *)(iVar2 + 0x676);
    *(undefined1 *)(param_1 + 0x6b) = *(undefined1 *)(iVar2 + 0x677);
    *(undefined1 *)(param_1 + 0x6c) = *(undefined1 *)(iVar2 + 0x678);
    *(undefined4 *)(param_1 + 100) = 1;
    break;
  case 0x8a:
    if (param_3 == 0) {
      FUN_00015f10(DAT_000553cc,5,1,0x16,0,0,0x32);
    }
    else {
      FUN_00015f10(DAT_000553cc,5,1,0x15,0,0,0x32);
    }
    break;
  case 0x8b:
    if (param_3 == 0) {
      FUN_00015f10(DAT_000553cc,5,1,0x1f,0,0,0x32);
    }
    else {
      FUN_00015f10(DAT_000553cc,5,1,0x1e,0,0,0x32);
    }
    break;
  case 0x8c:
    if (param_3 == 0) {
      FUN_00011500(param_1,1,0);
      NKDbgPrintfW(L" [Micom manager]IDM_X_MMCM_VOL_MUTE : Unmute!!\r\n");
    }
  }
  return;
}



/* 00013200 FUN_00013200 */

/* Boundary evidence: original MIPS .pdata 00013200..00013343. Semantic name remains unreviewed. */

void FUN_00013200(int param_1)

{
  int iVar1;
  
  FUN_0002d83c(param_1);
  iVar1 = *(int *)(param_1 + 0x58);
  if (iVar1 == 1) {
    FUN_00026cd8(DAT_00057130,0);
    *(undefined4 *)(param_1 + 0x44) = 0;
    FUN_000115d0(param_1,*(int *)(param_1 + 0x5c),0);
    *(undefined4 *)(param_1 + 0x58) = 4;
    FUN_0002d814(param_1,300);
  }
  else {
    if (iVar1 == 2) {
      FUN_00026cd8(DAT_00057130,0);
      *(undefined4 *)(param_1 + 0x44) = 0;
      FUN_00012a3c(param_1,*(int *)(param_1 + 0x5c));
    }
    else if (iVar1 == 3) {
      FUN_00026cd8(DAT_00057130,0);
      *(undefined4 *)(param_1 + 0x44) = 0;
      FUN_000115d0(param_1,*(int *)(param_1 + 0x5c),1);
    }
    else {
      if (iVar1 != 4) {
        return;
      }
      if (*(int *)(param_1 + 0x38) == 1) {
        if (*(int *)(param_1 + 0x34) == 0) {
          FUN_00011d78(param_1);
        }
        *(undefined4 *)(param_1 + 0x38) = 0;
      }
      if (*(int *)(param_1 + 0x3c) == 1) {
        FUN_00011cac(param_1);
        Sleep(100);
        *(undefined4 *)(param_1 + 0x3c) = 0;
      }
    }
    *(undefined4 *)(param_1 + 0x58) = 0;
  }
  return;
}



/* 00013344 FUN_00013344 */

/* Boundary evidence: original MIPS .pdata 00013344..000133db. Semantic name remains unreviewed. */

undefined4 *
FUN_00013344(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  FUN_0002d7e0(param_1,param_2,param_3);
  param_1[3] = param_4;
  *param_1 = &PTR_FUN_00045e7c;
  param_1[4] = 0xff;
  *(undefined1 *)(param_1 + 6) = 0;
  *(undefined1 *)((int)param_1 + 0x19) = 1;
  param_1[5] = 0xff;
  param_1[7] = 0;
  param_1[8] = 0;
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
  return param_1;
}



/* 000133dc FUN_000133dc */

/* Boundary evidence: original MIPS .pdata 000133dc..0001358f. Semantic name remains unreviewed. */

void FUN_000133dc(int param_1,undefined1 param_2,undefined1 param_3)

{
  undefined1 *puVar1;
  uint uVar2;
  HANDLE hFile;
  BOOL BVar3;
  wchar_t *pwVar4;
  DWORD DStack_38;
  DWORD DStack_34;
  uint local_30;
  undefined1 local_2c [4];
  byte local_28;
  
  *(undefined1 *)(param_1 + 0x19) = param_3;
  *(undefined1 *)(param_1 + 0x18) = param_2;
  hFile = CreateFileW(L"\\Storage Card2\\EcoDrive.cfg",0x80000000,0,(LPSECURITY_ATTRIBUTES)0x0,3,
                      0x80,(HANDLE)0x0);
  if (hFile == (HANDLE)0xffffffff) {
    hFile = CreateFileW(L"\\Storage Card2\\EcoDrive.cfg",0x40000000,0,(LPSECURITY_ATTRIBUTES)0x0,2,
                        0x80,(HANDLE)0x0);
    local_30 = (uint)*(byte *)(param_1 + 0x19);
    local_2c = (undefined1  [4])(uint)*(byte *)(param_1 + 0x18);
    puVar1 = local_2c + 3;
    uVar2 = (uint)puVar1 & 3;
    *(uint *)(puVar1 + -uVar2) =
         *(uint *)(puVar1 + -uVar2) & -1 << (uVar2 + 1) * 8 |
         (uint)(*(byte *)(param_1 + 0x18) >> (3 - uVar2) * 8);
    local_28 = FUN_0002fac0((int)&local_30,8);
    BVar3 = WriteFile(hFile,&local_30,9,&DStack_38,(LPOVERLAPPED)0x0);
    if (BVar3 == 0) {
      pwVar4 = L"EcoDrive.cfg write error\r\n";
    }
    else {
      pwVar4 = L"EcoDrive.cfg Create by micom manager\r\n";
    }
    NKDbgPrintfW(pwVar4);
  }
  else {
    BVar3 = ReadFile(hFile,&local_30,9,&DStack_34,(LPOVERLAPPED)0x0);
    if (BVar3 != 0) {
      if ((uint)local_2c < 3) {
        *(char *)(param_1 + 0x18) = local_2c[0];
      }
      else {
        *(undefined1 *)(param_1 + 0x18) = param_2;
      }
      *(char *)(param_1 + 0x19) = (char)local_30;
    }
    CloseHandle(hFile);
  }
  CloseHandle(hFile);
  return;
}



/* 00013590 FUN_00013590 */

void FUN_00013590(int param_1,undefined1 param_2)

{
  if (3 < *(byte *)(param_1 + 0x18)) {
    *(undefined1 *)(param_1 + 0x18) = 0;
  }
  *(undefined1 *)(param_1 + 0x18) = param_2;
  DAT_000553ac = 1;
  return;
}



/* 000135b8 FUN_000135b8 */

void FUN_000135b8(int param_1,undefined1 param_2)

{
  *(undefined1 *)(param_1 + 0x19) = param_2;
  return;
}



/* 000135c0 FUN_000135c0 */

/* Boundary evidence: original MIPS .pdata 000135c0..000136b3. Semantic name remains unreviewed. */

undefined4 FUN_000135c0(int param_1,int param_2,int param_3)

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
      iVar2 = __dptoli((int)uVar3,(int)((ulonglong)uVar3 >> 0x20));
    }
    if (DAT_000553ac != 0) {
      DAT_000553ac = 0;
      FUN_000338ac(0xce,0);
    }
    if (*(int *)(param_1 + 0x50) != 0) {
      FUN_000338ac(0xc9,(uint)*(byte *)(param_1 + 0x18) | iVar2 << 8);
    }
    uVar1 = 1;
  }
  return uVar1;
}



/* 000136b4 FUN_000136b4 */

/* Boundary evidence: original MIPS .pdata 000136b4..0001387f. Semantic name remains unreviewed. */

undefined4 FUN_000136b4(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  undefined8 uVar5;
  
  if ((((*(char *)(*(int *)(param_1 + 0xc) + 0x687) == '\x01') ||
       (iVar1 = *(int *)(param_1 + 0x10), iVar1 == 0xff)) || (param_2 == 0xff)) ||
     (iVar1 == *(int *)(param_1 + 0x14))) {
LAB_00013860:
    uVar3 = 0;
  }
  else {
    uVar3 = 0xffffffff;
    if (iVar1 - param_2 < 0) {
      iVar2 = 1;
    }
    else {
      iVar2 = -1;
      if (iVar1 - param_2 < 1) {
        iVar2 = 0;
      }
    }
    if (DAT_000553b0 == iVar2) {
      DAT_000553b4 = DAT_000553b4 + 1;
    }
    else {
      DAT_000553b4 = 0;
      DAT_000553b0 = iVar2;
    }
    if ((DAT_000553b0 < 0) && (DAT_000553b4 == 1)) {
      iVar1 = *(int *)(param_1 + 0x10);
      iVar2 = iVar1 + -1;
    }
    else {
      if ((DAT_000553b0 < 1) || (DAT_000553b4 != 0x14)) goto LAB_00013860;
      iVar1 = *(int *)(param_1 + 0x10);
      uVar3 = 1;
      iVar2 = iVar1 + 1;
    }
    DAT_000553b4 = 0;
    iVar4 = iVar2 + -0x28;
    if (iVar1 != iVar2) {
      *(int *)(param_1 + 0x10) = iVar2;
      if (iVar2 == 0xff) {
        iVar4 = 0x1a2;
      }
      else if (*(char *)(param_1 + 0x18) == '\x02') {
        uVar5 = __litodp(iVar4);
        uVar5 = __dpmul((int)uVar5,(int)((ulonglong)uVar5 >> 0x20),0xcccccccd,0x3ffccccc);
        uVar5 = __dpadd((int)uVar5,(int)((ulonglong)uVar5 >> 0x20),0,0x40400000);
        iVar4 = __dptoli((int)uVar5,(int)((ulonglong)uVar5 >> 0x20));
      }
      if (DAT_000553ac != 0) {
        DAT_000553ac = 0;
        FUN_000338ac(0xce,0);
      }
      if (*(int *)(param_1 + 0x50) != 0) {
        FUN_000338ac(0xc9,(uint)*(byte *)(param_1 + 0x18) | iVar4 << 8);
      }
    }
  }
  return uVar3;
}



/* 00013880 FUN_00013880 */

/* Boundary evidence: original MIPS .pdata 00013880..00013b97. Semantic name remains unreviewed. */

void FUN_00013880(int param_1,HDC param_2)

{
  HDC hdc;
  HBITMAP h;
  HGDIOBJ h_00;
  HDC hdc_00;
  HGDIOBJ pvVar1;
  uint x;
  uint uVar2;
  tagRECT local_c0;
  WCHAR aWStack_b0 [64];
  uint local_30;
  
  local_30 = DAT_00055374;
  hdc = CreateCompatibleDC(param_2);
  h = CreateCompatibleBitmap(param_2,0x246,0x3f);
  h_00 = SelectObject(hdc,h);
  hdc_00 = CreateCompatibleDC(param_2);
  pvVar1 = (HGDIOBJ)FUN_00017c18(DAT_000553dc,0xf);
  pvVar1 = SelectObject(hdc_00,pvVar1);
  BitBlt(hdc,0,0,0x246,0x3f,hdc_00,0,0,0xcc0020);
  SelectObject(hdc_00,pvVar1);
  uVar2 = 0;
  pvVar1 = (HGDIOBJ)FUN_00017c18(DAT_000553dc,0x10);
  pvVar1 = SelectObject(hdc_00,pvVar1);
  if ((0 < *(int *)(param_1 + 0x34)) && (uVar2 = 0, *(int *)(param_1 + 0x34) != 0)) {
    x = 0x49;
    do {
      if (0x210 < x) break;
      BitBlt(hdc,x,0x11,0x39,0x1d,hdc_00,0,0,0xcc0020);
      uVar2 = uVar2 + 1;
      x = x + 0x39;
    } while (uVar2 < *(uint *)(param_1 + 0x34));
  }
  NKDbgPrintfW(L"1.  %d-%d \n\r",*(undefined4 *)(param_1 + 0x34),uVar2);
  SelectObject(hdc_00,pvVar1);
  pvVar1 = (HGDIOBJ)FUN_00017c18(DAT_000553dc,0x11);
  pvVar1 = SelectObject(hdc_00,pvVar1);
  TransparentImage(hdc,0xb,8,0x2e,0x2e,hdc_00,0,0,0x2e,0x2e,0xffff00);
  SelectObject(hdc_00,pvVar1);
  DeleteDC(hdc_00);
  SetBkMode(hdc,1);
  SetTextColor(hdc,0xe6e6e6);
  pvVar1 = (HGDIOBJ)FUN_00017c94(DAT_000553dc,4);
  pvVar1 = SelectObject(hdc,pvVar1);
  local_c0.left = 0x240;
  local_c0.top = 9;
  local_c0.right = 0x201;
  local_c0.bottom = 0x33;
  wsprintfW(aWStack_b0,L"%d",*(undefined4 *)(param_1 + 0x34));
  DrawTextW(hdc,aWStack_b0,-1,&local_c0,0x101);
  SelectObject(hdc,pvVar1);
  BitBlt(param_2,0,0,0x246,0x3f,hdc,0,0,0xcc0020);
  SelectObject(hdc,h_00);
  DeleteObject(h);
  DeleteDC(hdc);
  FUN_00043604(local_30);
  return;
}



/* 00013b98 FUN_00013b98 */

/* Boundary evidence: original MIPS .pdata 00013b98..000140bf. Semantic name remains unreviewed. */

void FUN_00013b98(int param_1,HDC param_2,int param_3)

{
  HDC hdc;
  HBITMAP h;
  HGDIOBJ h_00;
  HDC hdc_00;
  HGDIOBJ pvVar1;
  UINT UVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined8 uVar6;
  tagRECT local_150;
  tagRECT local_140;
  WCHAR aWStack_130 [64];
  WCHAR aWStack_b0 [64];
  uint local_30;
  
  local_30 = DAT_00055374;
  if (((param_3 != 8) && (param_3 != 10)) && ((param_3 < 0x14 || (0xff < param_3))))
  goto LAB_00014088;
  hdc = CreateCompatibleDC(param_2);
  h = CreateCompatibleBitmap(param_2,0x246,0x3f);
  h_00 = SelectObject(hdc,h);
  hdc_00 = CreateCompatibleDC(param_2);
  pvVar1 = (HGDIOBJ)FUN_00017c18(DAT_000553dc,0);
  pvVar1 = SelectObject(hdc_00,pvVar1);
  BitBlt(hdc,0,0,0x246,0x3f,hdc_00,0,0,0xcc0020);
  SelectObject(hdc_00,pvVar1);
  pvVar1 = (HGDIOBJ)FUN_00017c18(DAT_000553dc,0x15);
  pvVar1 = SelectObject(hdc_00,pvVar1);
  TransparentImage(hdc,0xb,8,0x2e,0x2e,hdc_00,0,0,0x2e,0x2e,0xffff00);
  SelectObject(hdc_00,pvVar1);
  SetBkMode(hdc,1);
  SetTextColor(hdc,0xe6e6e6);
  pvVar1 = (HGDIOBJ)FUN_00017c94(DAT_000553dc,3);
  pvVar1 = SelectObject(hdc,pvVar1);
  local_140.left = 0x3c;
  local_140.bottom = 0x37;
  local_140.top = 4;
  local_140.right = 0x20a;
  if (param_3 == 8) {
    UVar2 = 0x872;
LAB_00013d88:
    FUN_00017b70(DAT_000553dc,UVar2,aWStack_130,0x104);
  }
  else {
    if (param_3 == 10) {
      UVar2 = 0x871;
      goto LAB_00013d88;
    }
    if ((0x13 < param_3) && (param_3 < 0x100)) {
      if (*(char *)(param_1 + 0x18) == '\x02') {
        uVar6 = __litodp(param_3);
        uVar6 = __dpmul((int)uVar6,(int)((ulonglong)uVar6 >> 0x20),0,0x3fe00000);
        uVar6 = __dpmul((int)uVar6,(int)((ulonglong)uVar6 >> 0x20),0xcccccccd,0x3ffccccc);
        __dpadd((int)uVar6,(int)((ulonglong)uVar6 >> 0x20),0,0x40400000);
      }
      else {
        uVar6 = __litodp(param_3);
        __dpmul((int)uVar6,(int)((ulonglong)uVar6 >> 0x20),0,0x3fe00000);
      }
      FUN_00017b70(DAT_000553dc,0x870,aWStack_b0,0x104);
      wsprintfW(aWStack_130,L"%s%.1f",aWStack_b0);
    }
  }
  DrawTextW(hdc,aWStack_130,-1,&local_150,0x505);
  DrawTextW(hdc,aWStack_130,-1,&local_140,0x105);
  SelectObject(hdc,pvVar1);
  if ((0x13 < param_3) && (param_3 < 0x100)) {
    iVar5 = local_150.right - local_150.left;
    iVar4 = local_150.bottom - local_150.top;
    iVar3 = 0x1d;
    if (*(char *)(param_1 + 0x18) != '\x02') {
      iVar3 = 0x1e;
    }
    pvVar1 = (HGDIOBJ)FUN_00017c18(DAT_000553dc,iVar3);
    pvVar1 = SelectObject(hdc_00,pvVar1);
    iVar3 = iVar4 >> 1;
    if ((DAT_0005450c == 0) || (DAT_0005450c == 0x15)) {
      if (iVar4 < 0) {
        iVar3 = iVar4 + 1 >> 1;
      }
      iVar4 = iVar3 + 10;
      if (iVar4 < 0) {
        iVar4 = iVar3 + 0xb;
      }
      iVar3 = -iVar5 + 0x1ce;
      if (iVar3 < 0) {
        iVar3 = -iVar5 + 0x1cf;
      }
      TransparentImage(hdc,(iVar3 >> 1) + 0x19,iVar4 >> 1,0x1e,0x1e,hdc_00,0,0,0x1e,0x1e,0xffff00);
    }
    else {
      if (iVar4 < 0) {
        iVar3 = iVar4 + 1 >> 1;
      }
      iVar4 = iVar3 + 10;
      if (iVar4 < 0) {
        iVar4 = iVar3 + 0xb;
      }
      iVar3 = -iVar5 + 0x1ce;
      if (iVar3 < 0) {
        iVar3 = -iVar5 + 0x1cf;
      }
      TransparentImage(hdc,(iVar3 >> 1) + iVar5 + 0x41,iVar4 >> 1,0x1e,0x1e,hdc_00,0,0,0x1e,0x1e,
                       0xffff00);
    }
    SelectObject(hdc_00,pvVar1);
  }
  DeleteDC(hdc_00);
  BitBlt(param_2,0,0,0x246,0x3f,hdc,0,0,0xcc0020);
  SelectObject(hdc,h_00);
  DeleteObject(h);
  DeleteDC(hdc);
LAB_00014088:
  FUN_00043604(local_30);
  return;
}



/* 000140c0 FUN_000140c0 */

/* Boundary evidence: original MIPS .pdata 000140c0..00014643. Semantic name remains unreviewed. */

void FUN_000140c0(undefined4 param_1,HDC param_2,int param_3,int param_4)

{
  HDC hdc;
  HBITMAP h;
  HGDIOBJ h_00;
  HDC hdc_00;
  HGDIOBJ pvVar1;
  int iVar2;
  UINT UVar3;
  tagRECT local_d0;
  tagRECT local_c0;
  WCHAR aWStack_b0 [64];
  uint local_30;
  
  local_30 = DAT_00055374;
  hdc = CreateCompatibleDC(param_2);
  h = CreateCompatibleBitmap(param_2,0x246,0x3f);
  h_00 = SelectObject(hdc,h);
  hdc_00 = CreateCompatibleDC(param_2);
  pvVar1 = (HGDIOBJ)FUN_00017c18(DAT_000553dc,0);
  pvVar1 = SelectObject(hdc_00,pvVar1);
  BitBlt(hdc,0,0,0x246,0x3f,hdc_00,0,0,0xcc0020);
  SelectObject(hdc_00,pvVar1);
  if (param_3 == 0) {
    pvVar1 = (HGDIOBJ)FUN_00017c18(DAT_000553dc,0x14);
    pvVar1 = SelectObject(hdc_00,pvVar1);
    TransparentImage(hdc,0xb,8,0x2e,0x2e,hdc_00,0,0,0x2e,0x2e,0xffff00);
LAB_0001435c:
    SelectObject(hdc_00,pvVar1);
    DeleteDC(hdc_00);
  }
  else {
    if (param_3 == 4) {
      pvVar1 = (HGDIOBJ)FUN_00017c18(DAT_000553dc,0x13);
      pvVar1 = SelectObject(hdc_00,pvVar1);
      TransparentImage(hdc,0xb,8,0x2e,0x2e,hdc_00,0,0,0x2e,0x2e,0xffff00);
      goto LAB_0001435c;
    }
    if (param_3 == 6) {
      pvVar1 = (HGDIOBJ)FUN_00017c18(DAT_000553dc,0x11);
      pvVar1 = SelectObject(hdc_00,pvVar1);
      TransparentImage(hdc,0xb,8,0x2e,0x2e,hdc_00,0,0,0x2e,0x2e,0xffff00);
      SelectObject(hdc_00,pvVar1);
    }
    else if (param_3 == 0xb) {
      pvVar1 = (HGDIOBJ)FUN_00017c18(DAT_000553dc,0x12);
      pvVar1 = SelectObject(hdc_00,pvVar1);
      TransparentImage(hdc,0xb,8,0x2e,0x2e,hdc_00,0,0,0x2e,0x2e,0xffff00);
      goto LAB_0001435c;
    }
  }
  DeleteDC(hdc_00);
  local_c0.left = 0x3c;
  local_c0.top = 4;
  local_c0.right = 0x20a;
  local_c0.bottom = 0x37;
  local_d0.left = 0x5a;
  local_d0.top = 4;
  local_d0.right = 0x20a;
  local_d0.bottom = 0x37;
  SetBkMode(hdc,1);
  SetTextColor(hdc,0xe6e6e6);
  iVar2 = 1;
  if (DAT_0005450c != 0) {
    iVar2 = 3;
  }
  pvVar1 = (HGDIOBJ)FUN_00017c94(DAT_000553dc,iVar2);
  pvVar1 = SelectObject(hdc,pvVar1);
  wsprintfW(aWStack_b0,L"");
  if (param_3 == 0xb) {
    if (param_4 == 1) {
      UVar3 = 0x86b;
    }
    else {
      if (param_4 != 2) goto LAB_00014594;
      UVar3 = 0x86c;
    }
    goto LAB_00014584;
  }
  if (param_3 != 9) {
    if (param_3 == 10) {
      if (param_4 == 1) {
        UVar3 = 0x87a;
      }
      else {
        if (param_4 != 2) goto LAB_00014544;
        UVar3 = 0x87b;
      }
      goto LAB_00014534;
    }
    if (param_3 == 4) {
      if (param_4 == 1) {
        UVar3 = 0x873;
      }
      else {
        if (param_4 != 2) goto LAB_00014594;
        UVar3 = 0x874;
      }
LAB_00014584:
      FUN_00017b70(DAT_000553dc,UVar3,aWStack_b0,0x104);
    }
    else {
      if (param_3 != 0) {
        if (param_3 == 5) {
          if (param_4 == 1) {
            UVar3 = 0x875;
          }
          else {
            if (param_4 != 2) goto LAB_00014544;
            UVar3 = 0x876;
          }
          goto LAB_00014534;
        }
        if ((param_3 != 6) || (param_4 != 0xf)) goto LAB_00014594;
        UVar3 = 0x877;
        goto LAB_00014584;
      }
      if (param_4 == 1) {
        UVar3 = 0x86d;
        goto LAB_00014584;
      }
      if (param_4 == 2) {
        UVar3 = 0x86e;
        goto LAB_00014584;
      }
    }
LAB_00014594:
    DrawTextW(hdc,aWStack_b0,-1,&local_d0,0x105);
    goto LAB_000145b0;
  }
  if (param_4 == 1) {
    UVar3 = 0x878;
LAB_00014534:
    FUN_00017b70(DAT_000553dc,UVar3,aWStack_b0,0x104);
  }
  else if (param_4 == 2) {
    UVar3 = 0x879;
    goto LAB_00014534;
  }
LAB_00014544:
  DrawTextW(hdc,aWStack_b0,-1,&local_c0,0x105);
LAB_000145b0:
  SelectObject(hdc,pvVar1);
  BitBlt(param_2,0,0,0x246,0x3f,hdc,0,0,0xcc0020);
  SelectObject(hdc,h_00);
  DeleteObject(h);
  DeleteDC(hdc);
  FUN_00043604(local_30);
  return;
}



/* 00014644 FUN_00014644 */

/* Boundary evidence: original MIPS .pdata 00014644..00014dc3. Semantic name remains unreviewed. */

void FUN_00014644(undefined4 param_1,HDC param_2,undefined4 param_3,uint param_4)

{
  HDC hdc;
  HBITMAP h;
  HGDIOBJ h_00;
  HDC hdc_00;
  HGDIOBJ pvVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  tagRECT local_c0;
  WCHAR aWStack_b0 [64];
  uint local_30;
  
  local_30 = DAT_00055374;
  hdc = CreateCompatibleDC(param_2);
  h = CreateCompatibleBitmap(param_2,0x246,0x3f);
  h_00 = SelectObject(hdc,h);
  hdc_00 = CreateCompatibleDC(param_2);
  pvVar1 = (HGDIOBJ)FUN_00017c18(DAT_000553dc,0);
  pvVar1 = SelectObject(hdc_00,pvVar1);
  BitBlt(hdc,0,0,0x246,0x3f,hdc_00,0,0,0xcc0020);
  SelectObject(hdc_00,pvVar1);
  uVar4 = param_4 & 2;
  uVar3 = param_4 & 4;
  uVar2 = param_4 & 8;
  if ((param_4 & 1) == 0) {
LAB_00014a00:
    if (uVar4 != 0) {
      if (uVar2 == 0) {
        if (uVar3 == 0) {
          pvVar1 = (HGDIOBJ)FUN_00017c18(DAT_000553dc,0x17);
          pvVar1 = SelectObject(hdc_00,pvVar1);
          TransparentImage(hdc,0xb,8,0x2e,0x2e,hdc_00,0,0,0x2e,0x2e,0xffff00);
        }
        else {
          pvVar1 = (HGDIOBJ)FUN_00017c18(DAT_000553dc,0x1c);
          pvVar1 = SelectObject(hdc_00,pvVar1);
          TransparentImage(hdc,0xb,8,0x2e,0x2e,hdc_00,0,0,0x2e,0x2e,0xffff00);
        }
      }
      else if (uVar3 == 0) {
        pvVar1 = (HGDIOBJ)FUN_00017c18(DAT_000553dc,0x1c);
        pvVar1 = SelectObject(hdc_00,pvVar1);
        TransparentImage(hdc,0xb,8,0x2e,0x2e,hdc_00,0,0,0x2e,0x2e,0xffff00);
      }
      else {
        pvVar1 = (HGDIOBJ)FUN_00017c18(DAT_000553dc,0x1c);
        pvVar1 = SelectObject(hdc_00,pvVar1);
        TransparentImage(hdc,0xb,8,0x2e,0x2e,hdc_00,0,0,0x2e,0x2e,0xffff00);
      }
LAB_00014b18:
      SelectObject(hdc_00,pvVar1);
    }
    if (uVar3 == 0) goto LAB_00014c40;
    if (uVar2 == 0) {
      pvVar1 = (HGDIOBJ)FUN_00017c18(DAT_000553dc,0x18);
      pvVar1 = SelectObject(hdc_00,pvVar1);
      TransparentImage(hdc,0xb,8,0x2e,0x2e,hdc_00,0,0,0x2e,0x2e,0xffff00);
    }
    else {
      pvVar1 = (HGDIOBJ)FUN_00017c18(DAT_000553dc,0x18);
      pvVar1 = SelectObject(hdc_00,pvVar1);
      TransparentImage(hdc,0xb,8,0x2e,0x2e,hdc_00,0,0,0x2e,0x2e,0xffff00);
    }
  }
  else {
    if ((uVar4 != 0) && (uVar2 != 0)) {
      if (uVar3 == 0) {
        pvVar1 = (HGDIOBJ)FUN_00017c18(DAT_000553dc,0x1b);
        pvVar1 = SelectObject(hdc_00,pvVar1);
        TransparentImage(hdc,0xb,8,0x2e,0x2e,hdc_00,0,0,0x2e,0x2e,0xffff00);
      }
      else {
        pvVar1 = (HGDIOBJ)FUN_00017c18(DAT_000553dc,0x1b);
        pvVar1 = SelectObject(hdc_00,pvVar1);
        TransparentImage(hdc,0xb,8,0x2e,0x2e,hdc_00,0,0,0x2e,0x2e,0xffff00);
      }
LAB_000149f4:
      SelectObject(hdc_00,pvVar1);
      goto LAB_00014a00;
    }
    if ((uVar3 != 0) && (uVar2 != 0)) {
      pvVar1 = (HGDIOBJ)FUN_00017c18(DAT_000553dc,0x1a);
      pvVar1 = SelectObject(hdc_00,pvVar1);
      TransparentImage(hdc,0xb,8,0x2e,0x2e,hdc_00,0,0,0x2e,0x2e,0xffff00);
      goto LAB_000149f4;
    }
    if (uVar4 != 0) {
      pvVar1 = (HGDIOBJ)FUN_00017c18(DAT_000553dc,0x19);
      pvVar1 = SelectObject(hdc_00,pvVar1);
      TransparentImage(hdc,0xb,8,0x2e,0x2e,hdc_00,0,0,0x2e,0x2e,0xffff00);
      goto LAB_000149f4;
    }
    if (uVar3 != 0) {
      pvVar1 = (HGDIOBJ)FUN_00017c18(DAT_000553dc,0x1a);
      pvVar1 = SelectObject(hdc_00,pvVar1);
      TransparentImage(hdc,0xb,8,0x2e,0x2e,hdc_00,0,0,0x2e,0x2e,0xffff00);
      goto LAB_00014b18;
    }
    if (uVar2 == 0) {
      pvVar1 = (HGDIOBJ)FUN_00017c18(DAT_000553dc,0x16);
      pvVar1 = SelectObject(hdc_00,pvVar1);
      TransparentImage(hdc,0xb,8,0x2e,0x2e,hdc_00,0,0,0x2e,0x2e,0xffff00);
      goto LAB_000149f4;
    }
    pvVar1 = (HGDIOBJ)FUN_00017c18(DAT_000553dc,0x1a);
    pvVar1 = SelectObject(hdc_00,pvVar1);
    TransparentImage(hdc,0xb,8,0x2e,0x2e,hdc_00,0,0,0x2e,0x2e,0xffff00);
  }
  SelectObject(hdc_00,pvVar1);
LAB_00014c40:
  if (uVar2 != 0) {
    pvVar1 = (HGDIOBJ)FUN_00017c18(DAT_000553dc,0x18);
    pvVar1 = SelectObject(hdc_00,pvVar1);
    TransparentImage(hdc,0xb,8,0x2e,0x2e,hdc_00,0,0,0x2e,0x2e,0xffff00);
    SelectObject(hdc_00,pvVar1);
  }
  DeleteDC(hdc_00);
  SetBkMode(hdc,1);
  SetTextColor(hdc,0xe6e6e6);
  pvVar1 = (HGDIOBJ)FUN_00017c94(DAT_000553dc,3);
  pvVar1 = SelectObject(hdc,pvVar1);
  local_c0.left = 0x3c;
  local_c0.top = 4;
  local_c0.right = 0x20a;
  local_c0.bottom = 0x37;
  FUN_00017b70(DAT_000553dc,0x86f,aWStack_b0,0x104);
  DrawTextW(hdc,aWStack_b0,-1,&local_c0,0x105);
  SelectObject(hdc,pvVar1);
  BitBlt(param_2,0,0,0x246,0x3f,hdc,0,0,0xcc0020);
  SelectObject(hdc,h_00);
  DeleteObject(h);
  DeleteDC(hdc);
  FUN_00043604(local_30);
  return;
}



/* 00014dc4 FUN_00014dc4 */

/* Boundary evidence: original MIPS .pdata 00014dc4..00014df7. Semantic name remains unreviewed. */

void FUN_00014dc4(int param_1)

{
  FUN_0002d83c(param_1);
  ShowWindow(*(HWND *)(param_1 + 4),0);
  return;
}



/* 00014df8 FUN_00014df8 */

/* Boundary evidence: original MIPS .pdata 00014df8..00014e13. Semantic name remains unreviewed. */

void FUN_00014df8(int param_1)

{
  FUN_000136b4(param_1,*(int *)(param_1 + 0x14));
  return;
}



/* 00014e14 FUN_00014e14 */

/* Boundary evidence: original MIPS .pdata 00014e14..00014e4b. Semantic name remains unreviewed. */

void FUN_00014e14(int param_1,int param_2)

{
  if (param_2 != 0) {
    ShowWindow(*(HWND *)(param_1 + 4),0);
  }
  FUN_0002d83c(param_1);
  return;
}



/* 00014e4c FUN_00014e4c */

/* Boundary evidence: original MIPS .pdata 00014e4c..00014edb. Semantic name remains unreviewed. */

void FUN_00014e4c(int param_1,int param_2)

{
  int iVar1;
  
  *(int *)(param_1 + 0x4c) = param_2;
  if (param_2 == 1) {
    *(undefined4 *)(param_1 + 0x10) = 0xff;
    if (*(int *)(param_1 + 0x50) != 0) {
      FUN_000338ac(0xc9,*(byte *)(param_1 + 0x18) | 0x1a200);
    }
  }
  else {
    iVar1 = FUN_0001b654(DAT_00055408);
    if (iVar1 == 0) {
      FUN_00015f10(DAT_000553cc,1,1,0xb,0,0,100);
    }
  }
  return;
}



/* 00014edc FUN_00014edc */

/* Boundary evidence: original MIPS .pdata 00014edc..00014f2f. Semantic name remains unreviewed. */

void FUN_00014edc(int param_1,int param_2)

{
  *(int *)(param_1 + 0x50) = param_2;
  if (param_2 == 0) {
    KillTimer(*(HWND *)(param_1 + 4),0x709);
    FUN_0002d83c(param_1);
  }
  else {
    SetTimer(*(HWND *)(param_1 + 4),0x709,1000,(TIMERPROC)0x0);
  }
  return;
}



/* 00014f30 FUN_00014f30 */

/* Boundary evidence: original MIPS .pdata 00014f30..00014f87. Semantic name remains unreviewed. */

undefined4 * FUN_00014f30(undefined4 *param_1,uint param_2)

{
  *param_1 = &PTR_FUN_00045e7c;
  FUN_0002d85c(param_1);
  if ((param_2 & 1) != 0) {
    __3_YAXPAX_Z(param_1);
  }
  return param_1;
}



/* 00014f88 FUN_00014f88 */

/* Boundary evidence: original MIPS .pdata 00014f88..00015977. Semantic name remains unreviewed. */

void FUN_00014f88(int param_1,uint *param_2)

{
  char cVar1;
  byte bVar2;
  uint uVar3;
  HDC hDC;
  uint uVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  undefined8 uVar14;
  byte local_68;
  byte local_67;
  byte local_66;
  byte local_65;
  byte local_64;
  byte local_62;
  byte local_61;
  uint local_60;
  undefined4 local_58;
  uint local_50;
  undefined1 uStack_48;
  undefined1 auStack_47 [3];
  byte local_44;
  byte local_33;
  uint local_2c;
  
  local_2c = DAT_00055374;
  if ((*param_2 & 0xf00) != 0x200) goto switchD_00015370_caseD_2;
  cVar1 = *(char *)((int)param_2 + 2);
  if (cVar1 == 'e') {
    if (((*(char *)(*(int *)(param_1 + 0xc) + 0x687) != '\0') ||
        (bVar2 = *(byte *)((int)param_2 + 3), bVar2 == 0)) || (*(int *)(param_1 + 0x4c) != 0))
    goto switchD_00015370_caseD_2;
    memset((void *)((int)&local_58 + 1),0,7);
    memcpy(&local_58,param_2 + 1,(uint)bVar2);
    uVar4 = local_58 >> 0x10 & 0xff;
    *(uint *)(param_1 + 0x14) = uVar4;
    if (*(int *)(param_1 + 0x10) == 0xff) {
      iVar6 = uVar4 - 0x28;
      if (uVar4 == 0xff) goto switchD_00015370_caseD_2;
      *(uint *)(param_1 + 0x10) = uVar4;
      if (*(char *)(param_1 + 0x18) == '\x02') {
        uVar14 = __litodp(iVar6);
        uVar14 = __dpmul((int)uVar14,(int)((ulonglong)uVar14 >> 0x20),0xcccccccd,0x3ffccccc);
        uVar14 = __dpadd((int)uVar14,(int)((ulonglong)uVar14 >> 0x20),0,0x40400000);
        iVar6 = __dptoli((int)uVar14,(int)((ulonglong)uVar14 >> 0x20));
      }
      if (DAT_000553ac != 0) {
        DAT_000553ac = 0;
        FUN_000338ac(0xce,0);
      }
      if (*(int *)(param_1 + 0x50) == 0) goto switchD_00015370_caseD_2;
      uVar4 = iVar6 << 8 | (uint)*(byte *)(param_1 + 0x18);
    }
    else {
      if ((uVar4 != 0xff) || (*(undefined4 *)(param_1 + 0x10) = 0xff, *(int *)(param_1 + 0x50) == 0)
         ) goto switchD_00015370_caseD_2;
      uVar4 = *(byte *)(param_1 + 0x18) | 0x1a200;
    }
    FUN_000338ac(0xc9,uVar4);
    goto switchD_00015370_caseD_2;
  }
  if (cVar1 != 'h') {
    if (((cVar1 == 'i') && (bVar2 = *(byte *)((int)param_2 + 3), bVar2 != 0)) &&
       (*(char *)(*(int *)(param_1 + 0xc) + 0x687) == '\0')) {
      memset(auStack_47,0,0x1b);
      memcpy(&uStack_48,param_2 + 1,(uint)bVar2);
      uVar4 = (uint)local_44;
      *(uint *)(param_1 + 0x14) = uVar4;
      if ((*(int *)(param_1 + 0x10) == 0xff) && (iVar6 = uVar4 - 0x28, uVar4 != 0xff)) {
        *(uint *)(param_1 + 0x10) = uVar4;
        if (*(char *)(param_1 + 0x18) == '\x02') {
          uVar14 = __litodp(iVar6);
          uVar14 = __dpmul((int)uVar14,(int)((ulonglong)uVar14 >> 0x20),0xcccccccd,0x3ffccccc);
          uVar14 = __dpadd((int)uVar14,(int)((ulonglong)uVar14 >> 0x20),0,0x40400000);
          iVar6 = __dptoli((int)uVar14,(int)((ulonglong)uVar14 >> 0x20));
        }
        if (DAT_000553ac != 0) {
          DAT_000553ac = 0;
          FUN_000338ac(0xce,0);
        }
        if (*(int *)(param_1 + 0x50) != 0) {
          FUN_000338ac(0xc9,iVar6 << 8 | (uint)*(byte *)(param_1 + 0x18));
        }
      }
      *(uint *)(param_1 + 0x30) = local_33 & 3;
    }
    goto switchD_00015370_caseD_2;
  }
  bVar2 = *(byte *)((int)param_2 + 3);
  if ((bVar2 == 0) || (*(int *)(param_1 + 0x4c) != 0)) goto switchD_00015370_caseD_2;
  local_68 = 0;
  memset(&local_67,0,7);
  memcpy(&local_68,param_2 + 1,(uint)bVar2);
  local_50 = (uint)local_67;
  uVar4 = local_68 >> 4 & 3;
  local_58 = (uint)(local_66 >> 4);
  uVar9 = local_66 >> 2 & 3;
  uVar8 = local_66 & 3;
  uVar7 = (uint)(local_64 >> 6);
  local_60 = (uint)(local_65 >> 4);
  uVar13 = local_65 & 0xf;
  uVar10 = local_62 >> 2 & 3;
  uVar11 = local_62 & 3;
  uVar12 = (uint)(local_61 >> 6);
  NKDbgPrintfW(L"[eClimBlowerLevelDisplay] [eClimLastFuncModifiedByCustomer] : [%x, %x]\r\n",
               local_60,uVar13);
  if (*(uint *)(param_1 + 0x34) != local_60) {
    *(uint *)(param_1 + 0x34) = local_60;
  }
  if (*(uint *)(param_1 + 0x3c) != uVar7) {
    *(uint *)(param_1 + 0x3c) = uVar7;
  }
  if ((*(char *)(param_1 + 0x19) != '\x01') || (uVar7 != 2)) goto switchD_00015370_caseD_2;
  if (*(uint *)(param_1 + 0x38) != uVar13) {
    *(uint *)(param_1 + 0x38) = uVar13;
  }
  iVar6 = DAT_000553dc;
  iVar5 = *(int *)(DAT_000553dc + 0x18);
  if (((((iVar5 == 1) || (iVar5 == 2)) || (iVar5 == 6)) ||
      ((*(int *)(DAT_00055498 + 0x5c) == 1 || (*(int *)(DAT_00055498 + 0x50) == 1)))) ||
     (iVar5 == 4)) {
    if (*(uint *)(param_1 + 0x30) != uVar8) {
      *(uint *)(param_1 + 0x30) = uVar8;
    }
    FUN_0002d83c(param_1);
    goto switchD_00015370_caseD_2;
  }
  if (iVar5 == 3) {
    *(undefined4 *)(DAT_000553dc + 0x18) = 0;
    FUN_0002d83c(iVar6);
  }
  uVar3 = local_50;
  uVar7 = local_58;
  if (*(uint *)(param_1 + 0x30) != uVar8) {
    *(uint *)(param_1 + 0x30) = uVar8;
    if ((uVar8 != 1) && (uVar8 != 2)) {
      SetWindowPos(*(HWND *)(param_1 + 4),(HWND)0xffffffff,0x6c,0x10,0x246,0x3f,0x80);
      goto switchD_00015370_caseD_2;
    }
    hDC = GetDC(*(HWND *)(param_1 + 4));
    SetWindowPos(*(HWND *)(param_1 + 4),(HWND)0xffffffff,0x6c,0x10,0x246,0x3f,0x40);
    iVar6 = 5;
    uVar4 = uVar8;
    goto LAB_00015320;
  }
  switch(uVar13) {
  case 1:
    if (local_50 == 0) {
      SetWindowPos(*(HWND *)(param_1 + 4),(HWND)0xffffffff,0x6c,0x10,0x246,0x3f,0x80);
      goto switchD_00015370_caseD_2;
    }
    hDC = GetDC(*(HWND *)(param_1 + 4));
    SetWindowPos(*(HWND *)(param_1 + 4),(HWND)0xffffffff,0x6c,0x10,0x246,0x3f,0x40);
    FUN_00013b98(param_1,hDC,uVar3);
    goto LAB_00015328;
  default:
    goto switchD_00015370_caseD_2;
  case 3:
    if ((uVar4 != 1) && (uVar4 != 2)) {
      SetWindowPos(*(HWND *)(param_1 + 4),(HWND)0xffffffff,0x6c,0x10,0x246,0x3f,0x80);
      goto switchD_00015370_caseD_2;
    }
    hDC = GetDC(*(HWND *)(param_1 + 4));
    SetWindowPos(*(HWND *)(param_1 + 4),(HWND)0xffffffff,0x6c,0x10,0x246,0x3f,0x40);
    iVar6 = 0;
    break;
  case 4:
    if ((uVar12 != 1) && (uVar12 != 2)) {
      SetWindowPos(*(HWND *)(param_1 + 4),(HWND)0xffffffff,0x6c,0x10,0x246,0x3f,0x80);
      goto switchD_00015370_caseD_2;
    }
    hDC = GetDC(*(HWND *)(param_1 + 4));
    SetWindowPos(*(HWND *)(param_1 + 4),(HWND)0xffffffff,0x6c,0x10,0x246,0x3f,0x40);
    iVar6 = 0xb;
    uVar4 = uVar12;
    break;
  case 5:
    if (local_58 == 0) {
      SetWindowPos(*(HWND *)(param_1 + 4),(HWND)0xffffffff,0x6c,0x10,0x246,0x3f,0x80);
      goto switchD_00015370_caseD_2;
    }
    hDC = GetDC(*(HWND *)(param_1 + 4));
    SetWindowPos(*(HWND *)(param_1 + 4),(HWND)0xffffffff,0x6c,0x10,0x246,0x3f,0x40);
    FUN_00014644(param_1,hDC,3,uVar7);
    goto LAB_00015328;
  case 6:
    if ((uVar9 != 1) && (uVar9 != 2)) {
      SetWindowPos(*(HWND *)(param_1 + 4),(HWND)0xffffffff,0x6c,0x10,0x246,0x3f,0x80);
      goto switchD_00015370_caseD_2;
    }
    hDC = GetDC(*(HWND *)(param_1 + 4));
    SetWindowPos(*(HWND *)(param_1 + 4),(HWND)0xffffffff,0x6c,0x10,0x246,0x3f,0x40);
    iVar6 = 4;
    uVar4 = uVar9;
    break;
  case 8:
    if (*(int *)(param_1 + 0x34) == 0) {
      SetWindowPos(*(HWND *)(param_1 + 4),(HWND)0xffffffff,0x6c,0x10,0x246,0x3f,0x80);
      goto switchD_00015370_caseD_2;
    }
    hDC = GetDC(*(HWND *)(param_1 + 4));
    SetWindowPos(*(HWND *)(param_1 + 4),(HWND)0xffffffff,0x6c,0x10,0x246,0x3f,0x40);
    if (*(int *)(param_1 + 0x34) == 0xf) {
      iVar6 = 6;
      uVar4 = local_60;
      break;
    }
    FUN_00013880(param_1,hDC);
    goto LAB_00015328;
  case 10:
    if ((uVar10 != 1) && (uVar10 != 2)) {
      SetWindowPos(*(HWND *)(param_1 + 4),(HWND)0xffffffff,0x6c,0x10,0x246,0x3f,0x80);
      goto switchD_00015370_caseD_2;
    }
    hDC = GetDC(*(HWND *)(param_1 + 4));
    SetWindowPos(*(HWND *)(param_1 + 4),(HWND)0xffffffff,0x6c,0x10,0x246,0x3f,0x40);
    iVar6 = 9;
    uVar4 = uVar10;
    break;
  case 0xb:
    if ((uVar11 != 1) && (uVar11 != 2)) {
      SetWindowPos(*(HWND *)(param_1 + 4),(HWND)0xffffffff,0x6c,0x10,0x246,0x3f,0x80);
      goto switchD_00015370_caseD_2;
    }
    hDC = GetDC(*(HWND *)(param_1 + 4));
    SetWindowPos(*(HWND *)(param_1 + 4),(HWND)0xffffffff,0x6c,0x10,0x246,0x3f,0x40);
    iVar6 = 10;
    uVar4 = uVar11;
  }
LAB_00015320:
  FUN_000140c0(param_1,hDC,iVar6,uVar4);
LAB_00015328:
  ReleaseDC(*(HWND *)(param_1 + 4),hDC);
  FUN_0002d814(param_1,3000);
switchD_00015370_caseD_2:
  FUN_00043604(local_2c);
  return;
}



/* 00015978 FUN_00015978 */

/* Boundary evidence: original MIPS .pdata 00015978..000159ff. Semantic name remains unreviewed. */

undefined4 * FUN_00015978(undefined4 *param_1,undefined4 param_2,undefined4 param_3)

{
  HANDLE pvVar1;
  
  FUN_0002d7e0(param_1,param_2,param_3);
  *param_1 = &PTR_FUN_00046018;
  param_1[5] = 0;
  param_1[7] = 0;
  param_1[6] = 0;
  memset(param_1 + 8,0,0x90);
  *(undefined1 *)((int)param_1 + 0x12) = 0;
  *(undefined1 *)((int)param_1 + 0x11) = 0;
  *(undefined1 *)(param_1 + 4) = 0;
  pvVar1 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,1,0,(LPCWSTR)0x0);
  param_1[3] = pvVar1;
  InitializeCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x2c));
  return param_1;
}



/* 00015a00 FUN_00015a00 */

/* Boundary evidence: original MIPS .pdata 00015a00..00015a4b. Semantic name remains unreviewed. */

void FUN_00015a00(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_00046018;
  DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x2c));
  CloseHandle((HANDLE)param_1[3]);
  FUN_0002d85c(param_1);
  return;
}



/* 00015a4c FUN_00015a4c */

/* Boundary evidence: original MIPS .pdata 00015a4c..00015b8f. Semantic name remains unreviewed. */

void FUN_00015a4c(int param_1,uint param_2,uint param_3,uint param_4,void *param_5,byte param_6,
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
    FUN_0002629c(&DAT_00055638,param_2,param_3,param_4,(int)param_5,param_6);
    *(byte *)(param_1 + 0x10) = (byte)param_3;
    *(char *)(param_1 + 0x11) = (char)param_2;
    *(char *)(param_1 + 0x12) = (char)param_4;
    *(undefined4 *)(param_1 + 0x14) = 1;
    FUN_0002d814(param_1,param_7);
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xb0));
  return;
}



/* 00015b90 FUN_00015b90 */

/* Boundary evidence: original MIPS .pdata 00015b90..00015d43. Semantic name remains unreviewed. */

undefined4
FUN_00015b90(int param_1,uint param_2,undefined4 param_3,int param_4,byte param_5,DWORD param_6)

{
  DWORD DVar1;
  byte bVar2;
  uint uVar3;
  undefined4 uVar4;
  undefined1 local_f0;
  undefined1 local_ef;
  undefined1 local_ee;
  undefined1 local_ed;
  undefined1 local_ec [188];
  uint local_30;
  
  local_30 = DAT_00055374;
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xb0));
  local_ef = (undefined1)((uint)param_3 >> 8);
  local_f0 = (undefined1)param_3;
  uVar3 = 0;
  local_ee = (undefined1)((uint)param_3 >> 0x10);
  local_ed = (undefined1)((uint)param_3 >> 0x18);
  if (param_5 != 0) {
    do {
      local_ec[uVar3] = *(undefined1 *)(uVar3 + param_4);
      uVar3 = uVar3 + 1 & 0xff;
    } while (uVar3 < param_5);
  }
  EventModify(*(undefined4 *)(param_1 + 0xc),2);
  bVar2 = 0;
  do {
    FUN_0002629c(&DAT_00055638,param_2,6,(uint)param_5,(int)&local_f0,param_5 + 4);
    DVar1 = WaitForSingleObject(*(HANDLE *)(param_1 + 0xc),param_6);
    if (DVar1 == 0) {
      uVar4 = 1;
      goto LAB_00015d00;
    }
    NKDbgPrintfW(L"%S(ret = 0x%x)\r\n","CCmd::SendWriteCmd",DVar1);
    bVar2 = bVar2 + 1;
  } while (bVar2 < 3);
  NKDbgPrintfW(L"MGRMCM : SendWriteCmd(0x%02X, 0x%08X) timeout!!!!!!!!!!!!!\r\n",param_2,param_3);
  uVar4 = 0;
LAB_00015d00:
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xb0));
  FUN_00043604(local_30);
  return uVar4;
}



/* 00015d44 FUN_00015d44 */

/* Boundary evidence: original MIPS .pdata 00015d44..00015dd3. Semantic name remains unreviewed. */

void FUN_00015d44(int param_1)

{
  int iVar1;
  
  if (*(int *)(param_1 + 0x1c) != 0) {
    iVar1 = *(int *)(param_1 + 0x18) * 0x24 + param_1;
    FUN_00015a4c(param_1,(uint)(*(byte *)(iVar1 + 0x20) >> 4),*(byte *)(iVar1 + 0x20) & 0xf,
                 (uint)*(byte *)(iVar1 + 0x21),(void *)(iVar1 + 0x23),*(byte *)(iVar1 + 0x22),
                 *(UINT *)(iVar1 + 0x40));
    *(uint *)(param_1 + 0x18) = *(int *)(param_1 + 0x18) + 1U & 3;
    *(int *)(param_1 + 0x1c) = *(int *)(param_1 + 0x1c) + -1;
  }
  return;
}



/* 00015dd4 FUN_00015dd4 */

/* Boundary evidence: original MIPS .pdata 00015dd4..00015e23. Semantic name remains unreviewed. */

void FUN_00015dd4(int param_1)

{
  *(undefined4 *)(param_1 + 0x14) = 0;
  FUN_0002d83c(param_1);
  FUN_00015d44(param_1);
  NKDbgPrintfW(L"ERROR : The request timeout is occured. Please figure out problems. GRP=0x%02X, CMD=0x%02X\r\n"
               ,*(undefined1 *)(param_1 + 0x10),*(undefined1 *)(param_1 + 0x12));
  return;
}



/* 00015e24 FUN_00015e24 */

/* Boundary evidence: original MIPS .pdata 00015e24..00015e8f. Semantic name remains unreviewed. */

void FUN_00015e24(int param_1,uint *param_2)

{
  if (((*(int *)(param_1 + 0x14) == 1) && ((uint)*(byte *)(param_1 + 0x10) == (*param_2 >> 8 & 0xf))
      ) && (*(char *)(param_1 + 0x12) == *(char *)((int)param_2 + 2))) {
    *(undefined4 *)(param_1 + 0x14) = 0;
    FUN_0002d83c(param_1);
    FUN_00015d44(param_1);
  }
  return;
}



/* 00015e90 FUN_00015e90 */

/* Boundary evidence: original MIPS .pdata 00015e90..00015ec3. Semantic name remains unreviewed. */

void FUN_00015e90(int param_1)

{
  *(undefined4 *)(param_1 + 0x14) = 0;
  FUN_0002d83c(param_1);
  FUN_00015d44(param_1);
  return;
}



/* 00015ec4 FUN_00015ec4 */

/* Boundary evidence: original MIPS .pdata 00015ec4..00015f0f. Semantic name remains unreviewed. */

undefined4 * FUN_00015ec4(undefined4 *param_1,uint param_2)

{
  FUN_00015a00(param_1);
  if ((param_2 & 1) != 0) {
    __3_YAXPAX_Z(param_1);
  }
  return param_1;
}



/* 00015f10 FUN_00015f10 */

/* Boundary evidence: original MIPS .pdata 00015f10..00016067. Semantic name remains unreviewed. */

undefined4
FUN_00015f10(int param_1,uint param_2,uint param_3,uint param_4,int param_5,byte param_6,int param_7
            )

{
  DWORD DVar1;
  uint uVar2;
  undefined4 uVar3;
  
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xb0));
  EventModify(*(undefined4 *)(param_1 + 0xc),2);
  uVar2 = 0;
  do {
    FUN_0002629c(&DAT_00055638,param_2,param_3,param_4,param_5,param_6);
    DVar1 = WaitForSingleObject(*(HANDLE *)(param_1 + 0xc),param_7 + 0x32);
    if (DVar1 == 0) {
      uVar3 = 1;
      goto LAB_0001602c;
    }
    NKDbgPrintfW(L"%S(ret = 0x%x)\r\n","CCmd::SendCommandEx",DVar1);
    uVar2 = uVar2 + 1;
  } while (uVar2 < 3);
  NKDbgPrintfW(L"%S(mgr=%d,grp=%d,cmd=0x%02X,buf,len=%d,tout=%d) : TIMEOUT!!!!!!!!\r\n",
               "CCmd::SendCommandEx",param_2,param_3,param_4,param_6,param_7);
  uVar3 = 0;
LAB_0001602c:
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xb0));
  return uVar3;
}



/* 00016068 FUN_00016068 */

/* Boundary evidence: original MIPS .pdata 00016068..00016263. Semantic name remains unreviewed. */

uint FUN_00016068(int param_1,uint param_2,undefined4 param_3,void *param_4,byte param_5,
                 DWORD param_6)

{
  DWORD DVar1;
  void *pvVar2;
  uint _Size;
  LPCRITICAL_SECTION lpCriticalSection;
  undefined1 local_1e8;
  undefined1 local_1e7;
  undefined1 local_1e6;
  undefined1 local_1e5;
  uint local_1e4;
  int local_1e0;
  undefined1 auStack_1d8 [144];
  undefined1 auStack_148 [144];
  uint local_b8;
  undefined1 auStack_b4 [136];
  uint local_2c;
  
  local_2c = DAT_00055374;
  lpCriticalSection = (LPCRITICAL_SECTION)(param_1 + 0xb0);
  local_1e0 = param_1;
  EnterCriticalSection(lpCriticalSection);
  local_1e8 = (undefined1)param_3;
  local_1e7 = (undefined1)((uint)param_3 >> 8);
  local_1e6 = (undefined1)((uint)param_3 >> 0x10);
  local_1e5 = (undefined1)((uint)param_3 >> 0x18);
  EventModify(*(undefined4 *)(param_1 + 0xc),2);
  local_1e4 = 0;
  do {
    FUN_0002629c(&DAT_00055638,param_2,5,(uint)param_5,(int)&local_1e8,4);
    DVar1 = WaitForSingleObject(*(HANDLE *)(param_1 + 0xc),param_6);
    if (DVar1 == 0) {
      pvVar2 = FUN_00026658(0x55638,auStack_148);
      memcpy(&local_b8,pvVar2,0x8c);
      _Size = local_b8 >> 0x18;
      memcpy(param_4,auStack_b4,_Size);
      goto LAB_00016220;
    }
    pvVar2 = FUN_00026658(0x55638,auStack_1d8);
    memcpy(&local_b8,pvVar2,0x8c);
    NKDbgPrintfW(L"%S(ret = 0x%x)\r\n","CCmd::SendReadCmd",DVar1);
    NKDbgPrintfW(L"stItem(mgr = %d, grp = %d, cmd = %d, len = %d)\r\n",local_b8 >> 0xc & 0xf,
                 local_b8 >> 8 & 0xf,local_b8 >> 0x10 & 0xff,local_b8 >> 0x18);
    local_1e4 = local_1e4 + 1;
    param_1 = local_1e0;
  } while (local_1e4 < 3);
  NKDbgPrintfW(L"%S(mgr=%d,addr=0x%08X,buf,len=%d,tout=%d) : TIMEOUT!!!!!!!!!!\r\n",
               "CCmd::SendReadCmd",param_2,param_3,(uint)param_5,param_6);
  _Size = 0;
LAB_00016220:
  LeaveCriticalSection(lpCriticalSection);
  FUN_00043604(local_2c);
  return _Size;
}



/* 00016264 FUN_00016264 */

undefined4 * FUN_00016264(undefined4 *param_1,undefined4 param_2)

{
  *param_1 = &PTR_FUN_0004637c;
  param_1[1] = param_2;
  param_1[3] = 0;
  param_1[4] = 0;
  return param_1;
}



/* 00016284 FUN_00016284 */

/* Boundary evidence: original MIPS .pdata 00016284..000162ef. Semantic name remains unreviewed. */

void FUN_00016284(int param_1)

{
  if (*(int *)(param_1 + 0xc) == 0) {
    SetWindowPos(*(HWND *)(param_1 + 8),(HWND)0xffffffff,10,0,0x30c,0x3c,0x10);
    ShowWindow(*(HWND *)(param_1 + 8),5);
    *(undefined4 *)(param_1 + 0xc) = 1;
  }
  return;
}



/* 000162f0 FUN_000162f0 */

/* Boundary evidence: original MIPS .pdata 000162f0..00016317. Semantic name remains unreviewed. */

void FUN_000162f0(int param_1)

{
  SetTimer(*(HWND *)(param_1 + 8),0x432,2000,(TIMERPROC)0x0);
  return;
}



/* 00016318 FUN_00016318 */

/* Boundary evidence: original MIPS .pdata 00016318..000163db. Semantic name remains unreviewed. */

void FUN_00016318(int param_1)

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



/* 000163dc FUN_000163dc */

/* Boundary evidence: original MIPS .pdata 000163dc..0001643f. Semantic name remains unreviewed. */

undefined4 * FUN_000163dc(undefined4 *param_1,uint param_2)

{
  *param_1 = &PTR_FUN_0004637c;
  SendMessageW((HWND)param_1[2],0x10,0,0);
  if ((param_2 & 1) != 0) {
    __3_YAXPAX_Z(param_1);
  }
  return param_1;
}



/* 00016440 FUN_00016440 */

/* Boundary evidence: original MIPS .pdata 00016440..000164a7. Semantic name remains unreviewed. */

LRESULT FUN_00016440(HWND param_1,UINT param_2,WPARAM param_3,LPARAM param_4)

{
  int iVar1;
  LRESULT LVar2;
  
  if (param_2 == 0x113) {
    KillTimer(param_1,0x432);
    iVar1 = DAT_000553d0;
    if (*(int *)(DAT_000553d0 + 0xc) != 0) {
      ShowWindow(*(HWND *)(DAT_000553d0 + 8),0);
      *(undefined4 *)(iVar1 + 0xc) = 0;
    }
    LVar2 = 0;
  }
  else {
    LVar2 = DefWindowProcW(param_1,param_2,param_3,param_4);
  }
  return LVar2;
}



/* 000164a8 FUN_000164a8 */

/* Boundary evidence: original MIPS .pdata 000164a8..000165ef. Semantic name remains unreviewed. */

undefined4 FUN_000164a8(int param_1)

{
  HWND hWnd;
  BOOL BVar1;
  WNDCLASSW local_40;
  
  local_40.hInstance = *(HINSTANCE *)(param_1 + 4);
  if (local_40.hInstance != (HINSTANCE)0xffffffff) {
    local_40.lpfnWndProc = FUN_00016440;
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



/* 000165f0 FUN_000165f0 */

/* Boundary evidence: original MIPS .pdata 000165f0..00016667. Semantic name remains unreviewed. */

undefined4 FUN_000165f0(int param_1,LPARAM param_2)

{
  WPARAM wParam;
  
  if (*(HWND *)(param_1 + 8) != (HWND)0x0) {
    wParam = SendDlgItemMessageW(*(HWND *)(param_1 + 8),3,0x180,0,param_2);
    if (wParam != 0xffffffff) {
      SendDlgItemMessageW(*(HWND *)(param_1 + 8),3,0x197,wParam,param_2);
    }
    FUN_00016284(param_1);
  }
  return 0;
}



/* 00016668 FUN_00016668 */

/* Boundary evidence: original MIPS .pdata 00016668..0001680b. Semantic name remains unreviewed. */

undefined4 *
FUN_00016668(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5)

{
  undefined4 *puVar1;
  
  FUN_0002d7e0(param_1,param_3,param_4);
  *param_1 = &PTR_FUN_00046478;
  param_1[4] = 100;
  param_1[6] = 0;
  param_1[0xd] = param_2;
  param_1[0xe] = 1;
  param_1[3] = 0;
  param_1[5] = 0;
  *(undefined1 *)(param_1 + 8) = 0;
  param_1[7] = 0;
  param_1[9] = 0;
  param_1[10] = 0;
  param_1[0xc] = 0;
  param_1[0xf] = param_5;
  puVar1 = (undefined4 *)__2_YAPAXI_Z(0x634);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    puVar1 = FUN_0002e020(puVar1);
  }
  param_1[0xb] = puVar1;
  if (puVar1 != (undefined4 *)0x0) {
    FUN_0002da7c((int)puVar1,0,L"Tahoma",0x20,0,'\0','\0');
    FUN_0002da7c(param_1[0xb],1,L"Tahoma",0x21,0,'\0','\0');
    FUN_0002da7c(param_1[0xb],2,L"Tahoma",0x24,0,'\0','\0');
    FUN_0002da7c(param_1[0xb],3,L"Tahoma",0x26,0,'\0','\0');
    FUN_0002da7c(param_1[0xb],4,L"Tahoma",0x2a,0,'\0','\0');
    FUN_0002da7c(param_1[0xb],5,L"Tahoma",0x34,0,'\0','\0');
  }
  return param_1;
}



/* 0001680c Unwind@0001680c */

/* Boundary evidence: original MIPS .pdata 0001680c..0001683b. Semantic name remains unreviewed. */

void Unwind_0001680c(void)

{
  undefined4 *in_v0;
  
  FUN_0002d85c((undefined4 *)*in_v0);
  return;
}



/* 0001683c Unwind@0001683c */

/* Boundary evidence: original MIPS .pdata 0001683c..0001686b. Semantic name remains unreviewed. */

void Unwind_0001683c(void)

{
  int in_v0;
  
  __3_YAXPAX_Z(*(undefined4 *)(in_v0 + -0x18));
  return;
}



/* 0001686c FUN_0001686c */

/* Boundary evidence: original MIPS .pdata 0001686c..000168db. Semantic name remains unreviewed. */

void FUN_0001686c(undefined4 *param_1)

{
  int *piVar1;
  
  *param_1 = &PTR_FUN_00046478;
  piVar1 = (int *)param_1[0xb];
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1,1);
    param_1[0xb] = 0;
  }
  FUN_0002d85c(param_1);
  return;
}



/* 000168dc Unwind@000168dc */

/* Boundary evidence: original MIPS .pdata 000168dc..0001690b. Semantic name remains unreviewed. */

void Unwind_000168dc(void)

{
  undefined4 *in_v0;
  
  FUN_0002d85c((undefined4 *)*in_v0);
  return;
}



/* 0001690c FUN_0001690c */

/* Boundary evidence: original MIPS .pdata 0001690c..0001697f. Semantic name remains unreviewed. */

void FUN_0001690c(int param_1,HDC param_2)

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



/* 00016980 FUN_00016980 */

/* Boundary evidence: original MIPS .pdata 00016980..00016baf. Semantic name remains unreviewed. */

void FUN_00016980(int param_1,HDC param_2)

{
  HDC hdc;
  HBITMAP h;
  HGDIOBJ h_00;
  HBRUSH hbr;
  int iVar1;
  int *piVar2;
  UINT format;
  tagRECT local_40;
  tagRECT local_30;
  
  format = 5;
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
  if ((DAT_0005450c == 0) || (DAT_0005450c == 0x15)) {
    format = 0x20005;
  }
  DrawTextW(hdc,L"Carefully press and Repeat as the target moves around the screen.",-1,&local_30,
            format);
  iVar1 = *(int *)(param_1 + 0x1c);
  if (iVar1 == 0) {
LAB_00016afc:
    piVar2 = &DAT_00054528 + iVar1 * 4;
LAB_00016b0c:
    if (piVar2 == (int *)0x0) goto LAB_00016b30;
  }
  else {
    if (iVar1 == 1) {
LAB_00016af0:
      piVar2 = &DAT_00054528 + iVar1 * 4;
      goto LAB_00016b0c;
    }
    if (iVar1 == 2) goto LAB_00016afc;
    if (iVar1 == 3) goto LAB_00016af0;
    if (iVar1 == 4) {
      piVar2 = (int *)0x54568;
      goto LAB_00016b0c;
    }
    piVar2 = &DAT_00054528;
    *(undefined4 *)(param_1 + 0x1c) = 0;
  }
  Rectangle(hdc,*piVar2,piVar2[1],piVar2[2],piVar2[3]);
LAB_00016b30:
  BitBlt(param_2,local_40.left,local_40.top,local_40.right - local_40.left,
         local_40.bottom - local_40.top,hdc,0,0,0xcc0020);
  SelectObject(hdc,h_00);
  DeleteObject(h);
  DeleteDC(hdc);
  return;
}



/* 00016bb0 FUN_00016bb0 */

/* Boundary evidence: original MIPS .pdata 00016bb0..00016c73. Semantic name remains unreviewed. */

void FUN_00016bb0(int param_1,HDC param_2)

{
  char cVar1;
  HBRUSH hbr;
  COLORREF color;
  tagRECT tStack_20;
  
  GetWindowRect(*(HWND *)(param_1 + 4),&tStack_20);
  cVar1 = *(char *)(param_1 + 0x20);
  if (cVar1 != '\0') {
    if (cVar1 == '\x01') {
      color = 0xff00;
      goto LAB_00016c3c;
    }
    if (cVar1 == '\x02') {
      color = 0xff0000;
      goto LAB_00016c3c;
    }
    if (cVar1 == '\x03') {
      color = 0;
      goto LAB_00016c3c;
    }
    if (cVar1 == '\x04') {
      color = 0xffffff;
      goto LAB_00016c3c;
    }
  }
  color = 0xff;
LAB_00016c3c:
  hbr = CreateSolidBrush(color);
  FillRect(param_2,&tStack_20,hbr);
  DeleteObject(hbr);
  return;
}



/* 00016c74 FUN_00016c74 */

/* Boundary evidence: original MIPS .pdata 00016c74..00016cef. Semantic name remains unreviewed. */

void FUN_00016c74(int param_1)

{
  if (*(int *)(param_1 + 0x18) == 2) {
    FUN_000338ac(0x70,0);
    PostMessageW((HWND)0xffff,DAT_00055400,0,0);
    StopRVC();
  }
  FUN_0002d83c(param_1);
  ShowWindow(*(HWND *)(param_1 + 4),0);
  *(undefined4 *)(param_1 + 0x18) = 0;
  return;
}



/* 00016cf0 FUN_00016cf0 */

/* Boundary evidence: original MIPS .pdata 00016cf0..00016dbb. Semantic name remains unreviewed. */

void FUN_00016cf0(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x18);
  if ((iVar1 != 2) && (iVar1 != 6)) {
    if ((iVar1 == 3) || (iVar1 == 1)) {
      FUN_0002d83c(param_1);
    }
    FUN_000338ac(0x70,1);
    PostMessageW((HWND)0xffff,DAT_00055400,0,1);
    *(undefined4 *)(param_1 + 0x18) = 2;
    SetWindowPos(*(HWND *)(param_1 + 4),(HWND)0xffffffff,0,0,800,0x1e0,0);
    ShowWindow(*(HWND *)(param_1 + 4),5);
    StartRVC();
  }
  return;
}



/* 00016dbc FUN_00016dbc */

/* Boundary evidence: original MIPS .pdata 00016dbc..00016e7b. Semantic name remains unreviewed. */

void FUN_00016dbc(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x18);
  if ((iVar1 != 1) && (iVar1 != 6)) {
    if (iVar1 == 3) {
      FUN_0002d83c(param_1);
    }
    FUN_000338ac(0x70,1);
    PostMessageW((HWND)0xffff,DAT_00055400,0,1);
    *(undefined4 *)(param_1 + 0x18) = 2;
    SetWindowPos(*(HWND *)(param_1 + 4),(HWND)0xffffffff,0,0,800,0x1e0,0);
    ShowWindow(*(HWND *)(param_1 + 4),5);
    StartRVC();
  }
  return;
}



/* 00016e7c FUN_00016e7c */

/* Boundary evidence: original MIPS .pdata 00016e7c..00016f4b. Semantic name remains unreviewed. */

void FUN_00016e7c(int param_1)

{
  FUN_00014e14(DAT_000553a8,0);
  if (*(int *)(param_1 + 0x18) == 2) {
    FUN_000338ac(0x70,0);
    PostMessageW((HWND)0xffff,DAT_00055400,0,0);
    StopRVC();
  }
  *(undefined4 *)(param_1 + 0x18) = 1;
  PostMessageW((HWND)0xffff,0x9e62,0,0);
  SetWindowPos(*(HWND *)(param_1 + 4),(HWND)0xffffffff,0,0,800,0x1e0,0);
  ShowWindow(*(HWND *)(param_1 + 4),5);
  FUN_0002d814(param_1,1000);
  return;
}



/* 00016f4c FUN_00016f4c */

/* Boundary evidence: original MIPS .pdata 00016f4c..00017027. Semantic name remains unreviewed. */

void FUN_00016f4c(int param_1)

{
  if (*(int *)(param_1 + 0x18) != 4) {
    if (*(int *)(param_1 + 0x18) == 2) {
      FUN_000338ac(0x70,0);
      PostMessageW((HWND)0xffff,DAT_00055400,0,0);
      StopRVC();
    }
    *(undefined4 *)(param_1 + 0x18) = 4;
    if (*(int *)(DAT_00055498 + 0x50) == 1) {
      ShowWindow(*(HWND *)(param_1 + 4),0);
    }
    else {
      SetWindowPos(*(HWND *)(param_1 + 4),(HWND)0xffffffff,0,0,800,0x1e0,0x40);
      InvalidateRect(*(HWND *)(param_1 + 4),(RECT *)0x0,0);
    }
  }
  return;
}



/* 00017028 FUN_00017028 */

/* Boundary evidence: original MIPS .pdata 00017028..000170cb. Semantic name remains unreviewed. */

void FUN_00017028(int param_1)

{
  if (*(int *)(param_1 + 0x18) == 6) {
    InvalidateRect(*(HWND *)(param_1 + 4),(RECT *)0x0,0);
  }
  else {
    *(undefined4 *)(param_1 + 0x18) = 6;
    SetWindowPos(*(HWND *)(param_1 + 4),(HWND)0xfffffffe,0,0,800,0x1e0,0x40);
    SetWindowPos(*(HWND *)(param_1 + 4),(HWND)0x0,0,0,800,0x1e0,0x40);
  }
  return;
}



/* 000170cc FUN_000170cc */

/* Boundary evidence: original MIPS .pdata 000170cc..000171fb. Semantic name remains unreviewed. */

undefined4 FUN_000170cc(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = *(int *)(param_1 + 0x18);
  uVar2 = 0;
  if (((iVar1 == 2) || (iVar1 == 1)) || (iVar1 == 6)) {
    uVar2 = 0;
  }
  else {
    *(undefined4 *)(param_1 + 0x1c) = 0;
    if (param_2 == 1) {
      if (iVar1 != 7) {
        *(undefined4 *)(param_1 + 0x18) = 7;
        SetWindowPos(*(HWND *)(param_1 + 4),(HWND)0xffffffff,0,0,800,0x1e0,0x40);
        FUN_0002d814(param_1,60000);
      }
    }
    else if (iVar1 == 7) {
      *(undefined4 *)(param_1 + 0x18) = 0;
      FUN_0002d83c(param_1);
      SetWindowPos(*(HWND *)(param_1 + 4),(HWND)0xfffffffe,0,0,800,0x1e0,0x80);
      SetWindowPos(*(HWND *)(param_1 + 4),(HWND)0x1,0,0,800,0x1e0,0x80);
      uVar2 = 1;
    }
  }
  return uVar2;
}



/* 000171fc FUN_000171fc */

/* Boundary evidence: original MIPS .pdata 000171fc..00017327. Semantic name remains unreviewed. */

undefined4 FUN_000171fc(int param_1,int param_2,undefined1 param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = *(int *)(param_1 + 0x18);
  uVar2 = 0;
  if (((iVar1 == 2) || (iVar1 == 1)) || (iVar1 == 6)) {
    uVar2 = 0;
  }
  else if (param_2 == 1) {
    *(undefined1 *)(param_1 + 0x20) = param_3;
    if (iVar1 != 8) {
      *(undefined4 *)(param_1 + 0x18) = 8;
      SetWindowPos(*(HWND *)(param_1 + 4),(HWND)0xffffffff,0,0,800,0x1e0,0x40);
    }
    uVar2 = 1;
    InvalidateRect(*(HWND *)(param_1 + 4),(RECT *)0x0,0);
  }
  else if (iVar1 == 8) {
    *(undefined4 *)(param_1 + 0x18) = 0;
    SetWindowPos(*(HWND *)(param_1 + 4),(HWND)0xfffffffe,0,0,800,0x1e0,0x80);
    SetWindowPos(*(HWND *)(param_1 + 4),(HWND)0x1,0,0,800,0x1e0,0x80);
    uVar2 = 1;
  }
  return uVar2;
}



/* 00017328 FUN_00017328 */

/* Boundary evidence: original MIPS .pdata 00017328..00017457. Semantic name remains unreviewed. */

undefined4 FUN_00017328(int param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = *(int *)(param_1 + 0x18);
  uVar2 = 0;
  if (((iVar1 != 2) && (iVar1 != 1)) && (iVar1 != 6)) {
    if (param_2 == 2) {
      if (iVar1 == 9) {
        *(undefined4 *)(param_1 + 0x18) = 0;
        SetWindowPos(*(HWND *)(param_1 + 4),(HWND)0xfffffffe,0,0,800,0x1e0,0x80);
        SetWindowPos(*(HWND *)(param_1 + 4),(HWND)0x1,0,0,800,0x1e0,0x80);
        uVar2 = 1;
      }
    }
    else {
      *(int *)(param_1 + 0x24) = param_2;
      *(undefined4 *)(param_1 + 0x28) = param_3;
      if (iVar1 != 9) {
        *(undefined4 *)(param_1 + 0x18) = 9;
        SetWindowPos(*(HWND *)(param_1 + 4),(HWND)0xffffffff,0,0,800,0x1e0,0x40);
      }
      uVar2 = 1;
      InvalidateRect(*(HWND *)(param_1 + 4),(RECT *)0x0,0);
    }
  }
  return uVar2;
}



/* 00017458 FUN_00017458 */

void FUN_00017458(int param_1,undefined4 param_2,uint param_3)

{
  int iVar1;
  
  if (*(int *)(param_1 + 0x18) == 7) {
    iVar1 = *(int *)(param_1 + 0x1c);
    if (((((int)(param_3 & 0xffff) < (int)(&DAT_00054528)[iVar1 * 4]) ||
         ((int)(&DAT_00054530)[iVar1 * 4] < (int)(param_3 & 0xffff))) ||
        ((int)(param_3 >> 0x10) < (int)(&DAT_0005452c)[iVar1 * 4])) ||
       ((int)(&DAT_00054534)[iVar1 * 4] < (int)(param_3 >> 0x10))) {
      DAT_000553e8 = 0;
    }
    else {
      DAT_000553e8 = 1;
    }
  }
  return;
}



/* 00017500 FUN_00017500 */

/* Boundary evidence: original MIPS .pdata 00017500..000175fb. Semantic name remains unreviewed. */

void FUN_00017500(int param_1,undefined4 param_2,uint param_3)

{
  int iVar1;
  LPARAM lParam;
  
  if (*(int *)(param_1 + 0x18) != 7) {
    return;
  }
  if (DAT_000553e8 == 0) {
LAB_000175c8:
    lParam = 0xf00000;
  }
  else {
    DAT_000553e8 = 0;
    iVar1 = *(int *)(param_1 + 0x1c);
    if (((((int)(param_3 & 0xffff) < (int)(&DAT_00054528)[iVar1 * 4]) ||
         ((int)(&DAT_00054530)[iVar1 * 4] < (int)(param_3 & 0xffff))) ||
        ((int)(param_3 >> 0x10) < (int)(&DAT_0005452c)[iVar1 * 4])) ||
       ((int)(&DAT_00054534)[iVar1 * 4] < (int)(param_3 >> 0x10))) goto LAB_000175c8;
    *(uint *)(param_1 + 0x1c) = iVar1 + 1U;
    if (iVar1 + 1U < 5) goto LAB_000175dc;
    lParam = 0xf00001;
  }
  PostMessageW(*(HWND *)(param_1 + 4),0x8064,0xb50000,lParam);
LAB_000175dc:
  InvalidateRect(*(HWND *)(param_1 + 4),(RECT *)0x0,0);
  return;
}



/* 000175fc FUN_000175fc */

/* Boundary evidence: original MIPS .pdata 000175fc..000178d3. Semantic name remains unreviewed. */

void FUN_000175fc(int param_1)

{
  HANDLE hFile;
  BOOL BVar1;
  HMODULE pHVar2;
  wchar_t *lpLibFileName;
  DWORD aDStack_70 [2];
  undefined1 auStack_68 [80];
  int local_18;
  
  hFile = CreateFileW(L"\\Storage Card2\\MgrSys.cfg",0x80000000,0,(LPSECURITY_ATTRIBUTES)0x0,3,0x80,
                      (HANDLE)0x0);
  if (hFile == (HANDLE)0xffffffff) {
    pHVar2 = LoadLibraryW(L"\\Storage Card\\system\\data\\LangDllEng.dll");
    *(HMODULE *)(param_1 + 0x30) = pHVar2;
    return;
  }
  memset(auStack_68,0,0x55);
  BVar1 = ReadFile(hFile,auStack_68,0x55,aDStack_70,(LPOVERLAPPED)0x0);
  NKDbgPrintfW(L"~~~ [[MgrMCM]] LOAD RESOURCE DLL [%d, %d]\r\n",BVar1,local_18);
  if (BVar1 == 0) {
switchD_000176f8_caseD_2:
    lpLibFileName = L"\\Storage Card\\system\\data\\LangDllEng.dll";
  }
  else {
    if (local_18 < 0x1d) {
      DAT_0005450c = local_18;
    }
    switch(DAT_0005450c) {
    case 0:
      lpLibFileName = L"\\Storage Card\\system\\data\\LangDllAra.dll";
      break;
    case 1:
      lpLibFileName = L"\\Storage Card\\system\\data\\LangDllDut.dll";
      break;
    default:
      goto switchD_000176f8_caseD_2;
    case 3:
      lpLibFileName = L"\\Storage Card\\system\\data\\LangDllFre.dll";
      break;
    case 4:
      lpLibFileName = L"\\Storage Card\\system\\data\\LangDllGer.dll";
      break;
    case 5:
      lpLibFileName = L"\\Storage Card\\system\\data\\LangDllIta.dll";
      break;
    case 6:
      lpLibFileName = L"\\Storage Card\\system\\data\\LangDllPor.dll";
      break;
    case 7:
      lpLibFileName = L"\\Storage Card\\system\\data\\LangDllRus.dll";
      break;
    case 8:
      lpLibFileName = L"\\Storage Card\\system\\data\\LangDllSpa.dll";
      break;
    case 9:
      lpLibFileName = L"\\Storage Card\\system\\data\\LangDllRom.dll";
      break;
    case 10:
      lpLibFileName = L"\\Storage Card\\system\\data\\LangDllTur.dll";
      break;
    case 0xb:
      lpLibFileName = L"\\Storage Card\\system\\data\\LangDllPol.dll";
      break;
    case 0xc:
      lpLibFileName = L"\\Storage Card\\system\\data\\LangDllPTBR.dll";
      break;
    case 0xd:
      lpLibFileName = L"\\Storage Card\\system\\data\\LangDllJap.dll";
      break;
    case 0xe:
      lpLibFileName = L"\\Storage Card\\system\\data\\LangDllGre.dll";
      break;
    case 0xf:
      lpLibFileName = L"\\Storage Card\\system\\data\\LangDllCro.dll";
      break;
    case 0x10:
      lpLibFileName = L"\\Storage Card\\system\\data\\LangDllCze.dll";
      break;
    case 0x11:
      lpLibFileName = L"\\Storage Card\\system\\data\\LangDllSloven.dll";
      break;
    case 0x12:
      lpLibFileName = L"\\Storage Card\\system\\data\\LangDllHun.dll";
      break;
    case 0x13:
      lpLibFileName = L"\\Storage Card\\system\\data\\LangDllSlo.dll";
      break;
    case 0x14:
      lpLibFileName = L"\\Storage Card\\system\\data\\LangDllBul.dll";
      break;
    case 0x15:
      lpLibFileName = L"\\Storage Card\\system\\data\\LangDllHeb.dll";
      break;
    case 0x16:
      lpLibFileName = L"\\Storage Card\\system\\data\\LangDllSer.dll";
      break;
    case 0x17:
      lpLibFileName = L"\\Storage Card\\system\\data\\LangDllUka.dll";
      break;
    case 0x18:
      lpLibFileName = L"\\Storage Card\\system\\data\\LangDllSwe.dll";
      break;
    case 0x19:
      lpLibFileName = L"\\Storage Card\\system\\data\\LangDllDan.dll";
      break;
    case 0x1a:
      lpLibFileName = L"\\Storage Card\\system\\data\\LangDllFin.dll";
      break;
    case 0x1b:
      lpLibFileName = L"\\Storage Card\\system\\data\\LangDllNor.dll";
    }
  }
  pHVar2 = LoadLibraryW(lpLibFileName);
  *(HMODULE *)(param_1 + 0x30) = pHVar2;
  CloseHandle(hFile);
  return;
}



/* 000178d4 FUN_000178d4 */

/* Boundary evidence: original MIPS .pdata 000178d4..00017b6f. Semantic name remains unreviewed. */

void FUN_000178d4(int param_1,uint param_2)

{
  HMODULE pHVar1;
  LSTATUS LVar2;
  wchar_t *lpLibFileName;
  uint local_res4 [3];
  HKEY local_10 [2];
  
  local_res4[0] = param_2;
  if (*(HMODULE *)(param_1 + 0x30) != (HMODULE)0x0) {
    FreeLibrary(*(HMODULE *)(param_1 + 0x30));
    *(undefined4 *)(param_1 + 0x30) = 0;
  }
  DAT_0005450c = local_res4[0];
  if (0x1c < local_res4[0]) {
    DAT_0005450c = 2;
  }
  switch(DAT_0005450c) {
  case 0:
    lpLibFileName = L"\\Storage Card\\system\\data\\LangDllAra.dll";
    break;
  case 1:
    lpLibFileName = L"\\Storage Card\\system\\data\\LangDllDut.dll";
    break;
  default:
    lpLibFileName = L"\\Storage Card\\system\\data\\LangDllEng.dll";
    break;
  case 3:
    lpLibFileName = L"\\Storage Card\\system\\data\\LangDllFre.dll";
    break;
  case 4:
    lpLibFileName = L"\\Storage Card\\system\\data\\LangDllGer.dll";
    break;
  case 5:
    lpLibFileName = L"\\Storage Card\\system\\data\\LangDllIta.dll";
    break;
  case 6:
    lpLibFileName = L"\\Storage Card\\system\\data\\LangDllPor.dll";
    break;
  case 7:
    lpLibFileName = L"\\Storage Card\\system\\data\\LangDllRus.dll";
    break;
  case 8:
    lpLibFileName = L"\\Storage Card\\system\\data\\LangDllSpa.dll";
    break;
  case 9:
    lpLibFileName = L"\\Storage Card\\system\\data\\LangDllRom.dll";
    break;
  case 10:
    lpLibFileName = L"\\Storage Card\\system\\data\\LangDllTur.dll";
    break;
  case 0xb:
    lpLibFileName = L"\\Storage Card\\system\\data\\LangDllPol.dll";
    break;
  case 0xc:
    lpLibFileName = L"\\Storage Card\\system\\data\\LangDllPTBR.dll";
    break;
  case 0xd:
    lpLibFileName = L"\\Storage Card\\system\\data\\LangDllJap.dll";
    break;
  case 0xe:
    lpLibFileName = L"\\Storage Card\\system\\data\\LangDllGre.dll";
    break;
  case 0xf:
    lpLibFileName = L"\\Storage Card\\system\\data\\LangDllCro.dll";
    break;
  case 0x10:
    lpLibFileName = L"\\Storage Card\\system\\data\\LangDllCze.dll";
    break;
  case 0x11:
    lpLibFileName = L"\\Storage Card\\system\\data\\LangDllSloven.dll";
    break;
  case 0x12:
    lpLibFileName = L"\\Storage Card\\system\\data\\LangDllHun.dll";
    break;
  case 0x13:
    lpLibFileName = L"\\Storage Card\\system\\data\\LangDllSlo.dll";
    break;
  case 0x14:
    lpLibFileName = L"\\Storage Card\\system\\data\\LangDllBul.dll";
    break;
  case 0x15:
    lpLibFileName = L"\\Storage Card\\system\\data\\LangDllHeb.dll";
    break;
  case 0x16:
    lpLibFileName = L"\\Storage Card\\system\\data\\LangDllSer.dll";
    break;
  case 0x17:
    lpLibFileName = L"\\Storage Card\\system\\data\\LangDllUka.dll";
    break;
  case 0x18:
    lpLibFileName = L"\\Storage Card\\system\\data\\LangDllSwe.dll";
    break;
  case 0x19:
    lpLibFileName = L"\\Storage Card\\system\\data\\LangDllDan.dll";
    break;
  case 0x1a:
    lpLibFileName = L"\\Storage Card\\system\\data\\LangDllFin.dll";
    break;
  case 0x1b:
    lpLibFileName = L"\\Storage Card\\system\\data\\LangDllNor.dll";
  }
  pHVar1 = LoadLibraryW(lpLibFileName);
  *(HMODULE *)(param_1 + 0x30) = pHVar1;
  LVar2 = RegOpenKeyExW((HKEY)0x80000002,L"LGE\\SystemInfo",0,0,local_10);
  if (LVar2 == 0) {
    RegSetValueExW(local_10[0],L"SYS_LANG_TYPE",0,4,(BYTE *)local_res4,4);
    RegCloseKey(local_10[0]);
  }
  return;
}



/* 00017b70 FUN_00017b70 */

/* Boundary evidence: original MIPS .pdata 00017b70..00017bd7. Semantic name remains unreviewed. */

undefined4 FUN_00017b70(int param_1,UINT param_2,LPWSTR param_3,int param_4)

{
  wchar_t *pwVar1;
  
  if (*(HINSTANCE *)(param_1 + 0x30) == (HINSTANCE)0x0) {
    if (param_2 == 0x4ba) {
      pwVar1 = L"Software Update";
    }
    else {
      if (param_2 != 0x4bb) {
        return 0;
      }
      pwVar1 = L"Update in progress\r\nDo not disconnect the USB\r\nor turn off the engine";
    }
    wsprintfW(param_3,pwVar1);
  }
  else {
    LoadStringW(*(HINSTANCE *)(param_1 + 0x30),param_2,param_3,param_4);
  }
  return 0;
}



/* 00017bd8 FUN_00017bd8 */

/* Boundary evidence: original MIPS .pdata 00017bd8..00017c17. Semantic name remains unreviewed. */

void FUN_00017bd8(int param_1)

{
  if (*(HMODULE *)(param_1 + 0x30) != (HMODULE)0x0) {
    FreeLibrary(*(HMODULE *)(param_1 + 0x30));
  }
  *(undefined4 *)(param_1 + 0x30) = 0;
  return;
}



/* 00017c18 FUN_00017c18 */

/* Boundary evidence: original MIPS .pdata 00017c18..00017c4b. Semantic name remains unreviewed. */

int FUN_00017c18(int param_1,int param_2)

{
  int iVar1;
  
  if (*(int **)(param_1 + 0x2c) == (int *)0x0) {
    iVar1 = 0;
  }
  else {
    iVar1 = FUN_0002df24(*(int **)(param_1 + 0x2c),param_2);
  }
  return iVar1;
}



/* 00017c4c FUN_00017c4c */

undefined4 FUN_00017c4c(int param_1)

{
  undefined4 uVar1;
  
  if (*(int *)(param_1 + 0x2c) == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = *(undefined4 *)(*(int *)(param_1 + 0x2c) + 0x61c);
  }
  return uVar1;
}



/* 00017c6c FUN_00017c6c */

/* Boundary evidence: original MIPS .pdata 00017c6c..00017c93. Semantic name remains unreviewed. */

void FUN_00017c6c(int param_1,int param_2)

{
  if (*(int **)(param_1 + 0x2c) != (int *)0x0) {
    FUN_0002dec0(*(int **)(param_1 + 0x2c),param_2);
  }
  return;
}



/* 00017c94 FUN_00017c94 */

/* Boundary evidence: original MIPS .pdata 00017c94..00017cc7. Semantic name remains unreviewed. */

undefined4 FUN_00017c94(int param_1,int param_2)

{
  undefined4 uVar1;
  
  if (*(int *)(param_1 + 0x2c) == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = FUN_0002da4c(*(int *)(param_1 + 0x2c),param_2);
  }
  return uVar1;
}



/* 00017cc8 FUN_00017cc8 */

/* Boundary evidence: original MIPS .pdata 00017cc8..00017d13. Semantic name remains unreviewed. */

undefined4 * FUN_00017cc8(undefined4 *param_1,uint param_2)

{
  FUN_0001686c(param_1);
  if ((param_2 & 1) != 0) {
    __3_YAXPAX_Z(param_1);
  }
  return param_1;
}



/* 00017d14 FUN_00017d14 */

/* Boundary evidence: original MIPS .pdata 00017d14..00017d9f. Semantic name remains unreviewed. */

void FUN_00017d14(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x18);
  if (iVar1 == 1) {
    InvalidateRect(*(HWND *)(param_1 + 4),(RECT *)0x0,0);
  }
  else if (iVar1 == 3) {
    FUN_00016c74(param_1);
  }
  else if (iVar1 == 7) {
    FUN_0002d83c(param_1);
    PostMessageW(*(HWND *)(param_1 + 4),0x8064,0xb50000,0xf00000);
  }
  return;
}



/* 00017da0 FUN_00017da0 */

/* Boundary evidence: original MIPS .pdata 00017da0..00018243. Semantic name remains unreviewed. */

void FUN_00017da0(int param_1,HDC param_2)

{
  HDC hdc;
  HBITMAP h;
  HGDIOBJ h_00;
  HDC hdc_00;
  HGDIOBJ pvVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  tagRECT local_c0;
  WCHAR aWStack_b0 [64];
  uint local_30;
  
  local_30 = DAT_00055374;
  hdc = CreateCompatibleDC(param_2);
  h = CreateCompatibleBitmap(param_2,0x246,0x3f);
  h_00 = SelectObject(hdc,h);
  hdc_00 = CreateCompatibleDC(param_2);
  if (*(int **)(param_1 + 0x2c) == (int *)0x0) {
    pvVar1 = (HGDIOBJ)0x0;
  }
  else {
    pvVar1 = (HGDIOBJ)FUN_0002df24(*(int **)(param_1 + 0x2c),0);
  }
  pvVar1 = SelectObject(hdc_00,pvVar1);
  BitBlt(hdc,0,0,0x246,0x3f,hdc_00,0,0,0xcc0020);
  SelectObject(hdc_00,pvVar1);
  if (*(int **)(param_1 + 0x2c) == (int *)0x0) {
    pvVar1 = (HGDIOBJ)0x0;
  }
  else {
    pvVar1 = (HGDIOBJ)FUN_0002df24(*(int **)(param_1 + 0x2c),1);
  }
  pvVar1 = SelectObject(hdc_00,pvVar1);
  uVar4 = 0;
  if (*(int *)(param_1 + 0xc) != 0) {
    iVar3 = 0x3f;
    do {
      BitBlt(hdc,iVar3,0xe,8,0x20,hdc_00,8,0,0xcc0020);
      uVar4 = uVar4 + 1;
      iVar3 = iVar3 + 0xe;
    } while (uVar4 < *(uint *)(param_1 + 0xc));
  }
  uVar4 = *(uint *)(param_1 + 0xc);
  if (uVar4 < 0x1f) {
    iVar5 = 0x1f - uVar4;
    iVar3 = uVar4 * 0xe + 0x3f;
    do {
      BitBlt(hdc,iVar3,0xe,8,0x20,hdc_00,0,0,0xcc0020);
      iVar5 = iVar5 + -1;
      iVar3 = iVar3 + 0xe;
    } while (iVar5 != 0);
  }
  SelectObject(hdc_00,pvVar1);
  iVar3 = FUN_00011e38(DAT_00055384);
  if (*(int *)(DAT_00055384 + 0x34) == 0) {
    if (iVar3 == 7) {
      piVar2 = *(int **)(param_1 + 0x2c);
      if (piVar2 == (int *)0x0) goto LAB_00018060;
      iVar3 = 5;
    }
    else if (iVar3 == 8) {
LAB_0001802c:
      piVar2 = *(int **)(param_1 + 0x2c);
      if (piVar2 == (int *)0x0) goto LAB_00018060;
      iVar3 = 6;
    }
    else if (iVar3 == 9) {
      piVar2 = *(int **)(param_1 + 0x2c);
      if (piVar2 == (int *)0x0) goto LAB_00018060;
      iVar3 = 4;
    }
    else {
      if (iVar3 == 10) goto LAB_0001802c;
      piVar2 = *(int **)(param_1 + 0x2c);
      if (piVar2 == (int *)0x0) goto LAB_00018060;
      iVar3 = 2;
    }
  }
  else {
    piVar2 = *(int **)(param_1 + 0x2c);
    if (piVar2 == (int *)0x0) {
LAB_00018060:
      pvVar1 = (HGDIOBJ)0x0;
      goto LAB_00018064;
    }
    iVar3 = 3;
  }
  pvVar1 = (HGDIOBJ)FUN_0002df24(piVar2,iVar3);
LAB_00018064:
  pvVar1 = SelectObject(hdc_00,pvVar1);
  if ((*(int *)(param_1 + 0xc) == 0) || (*(int *)(param_1 + 0x14) == 1)) {
    TransparentImage(hdc,0x12,0xe,0x20,0x20,hdc_00,0x20,0,0x20,0x20,0xffff00);
  }
  else {
    TransparentImage(hdc,0x12,0xe,0x20,0x20,hdc_00,0,0,0x20,0x20,0xffff00);
  }
  SelectObject(hdc_00,pvVar1);
  DeleteDC(hdc_00);
  SetBkMode(hdc,1);
  SetTextColor(hdc,0xe6e6e6);
  if (*(int *)(param_1 + 0x2c) == 0) {
    pvVar1 = (HGDIOBJ)0x0;
  }
  else {
    pvVar1 = (HGDIOBJ)FUN_0002da4c(*(int *)(param_1 + 0x2c),4);
  }
  pvVar1 = SelectObject(hdc,pvVar1);
  local_c0.left = 0x201;
  local_c0.top = 9;
  local_c0.right = 0x233;
  local_c0.bottom = 0x33;
  wsprintfW(aWStack_b0,L"%02d",*(undefined4 *)(param_1 + 0xc));
  DrawTextW(hdc,aWStack_b0,-1,&local_c0,0);
  SelectObject(hdc,pvVar1);
  BitBlt(param_2,0,0,0x246,0x3f,hdc,0,0,0xcc0020);
  SelectObject(hdc,h_00);
  DeleteObject(h);
  DeleteDC(hdc);
  FUN_00043604(local_30);
  return;
}



/* 00018244 FUN_00018244 */

/* Boundary evidence: original MIPS .pdata 00018244..000184ef. Semantic name remains unreviewed. */

void FUN_00018244(int param_1,HDC param_2,int param_3)

{
  char cVar1;
  int iVar2;
  HDC hdc;
  HGDIOBJ pvVar3;
  int iVar4;
  int iVar5;
  undefined8 uVar6;
  tagRECT local_c0;
  WCHAR local_b0;
  undefined1 auStack_ae [126];
  uint local_30;
  
  iVar2 = DAT_000553a8;
  local_30 = DAT_00055374;
  if (DAT_000553a8 != 0) {
    local_b0 = L'\0';
    memset(auStack_ae,0,0x7e);
    cVar1 = *(char *)(iVar2 + 0x18);
    iVar5 = *(int *)(iVar2 + 0x10) + -0x28;
    iVar2 = iVar5;
    if (cVar1 == '\x02') {
      uVar6 = __litodp(iVar5);
      uVar6 = __dpmul((int)uVar6,(int)((ulonglong)uVar6 >> 0x20),0xcccccccd,0x3ffccccc);
      uVar6 = __dpadd((int)uVar6,(int)((ulonglong)uVar6 >> 0x20),0,0x40400000);
      iVar2 = __dptoli((int)uVar6,(int)((ulonglong)uVar6 >> 0x20));
    }
    if (((param_3 == 0) ||
        ((((cVar1 != '\x01' || (iVar2 < -3)) || (3 < iVar2)) &&
         (((cVar1 != '\x02' || (iVar2 < 0x1b)) || (0x25 < iVar2)))))) && (cVar1 != '\0')) {
      hdc = CreateCompatibleDC(param_2);
      if (*(int **)(param_1 + 0x2c) == (int *)0x0) {
        pvVar3 = (HGDIOBJ)0x0;
      }
      else {
        iVar4 = 0xd;
        if (cVar1 != '\x02') {
          iVar4 = 0xe;
        }
        pvVar3 = (HGDIOBJ)FUN_0002df24(*(int **)(param_1 + 0x2c),iVar4);
      }
      pvVar3 = SelectObject(hdc,pvVar3);
      TransparentImage(param_2,0x2f0,0x32,0x1e,0x1d,hdc,0,0,0x1e,0x1d,0xffff00);
      SelectObject(hdc,pvVar3);
      DeleteDC(hdc);
    }
    if (iVar5 < 0xd7) {
      wsprintfW(&local_b0,L"%d",iVar2);
    }
    else {
      wsprintfW(&local_b0,L"--");
    }
    SetBkMode(param_2,1);
    SetTextColor(param_2,0xe6e6e6);
    if (*(int *)(param_1 + 0x2c) == 0) {
      pvVar3 = (HGDIOBJ)0x0;
    }
    else {
      pvVar3 = (HGDIOBJ)FUN_0002da4c(*(int *)(param_1 + 0x2c),0);
    }
    pvVar3 = SelectObject(param_2,pvVar3);
    local_c0.left = 700;
    local_c0.top = 0x32;
    local_c0.right = 0x2ee;
    local_c0.bottom = 100;
    DrawTextW(param_2,&local_b0,-1,&local_c0,0x102);
    SelectObject(param_2,pvVar3);
  }
  FUN_00043604(local_30);
  return;
}



/* 000184f0 FUN_000184f0 */

/* Boundary evidence: original MIPS .pdata 000184f0..00018abf. Semantic name remains unreviewed. */

void FUN_000184f0(int param_1,HDC param_2)

{
  HDC hdc;
  HBITMAP h;
  HDC hdc_00;
  HGDIOBJ pvVar1;
  uint uVar2;
  UINT format;
  int iVar3;
  int iVar4;
  int iVar5;
  tagRECT local_250;
  HGDIOBJ local_240;
  WCHAR aWStack_238 [260];
  uint local_30;
  
  local_30 = DAT_00055374;
  format = 1;
  if ((DAT_0005450c == 0) || (DAT_0005450c == 0x15)) {
    format = 0x20001;
  }
  hdc = CreateCompatibleDC(param_2);
  h = CreateCompatibleBitmap(param_2,800,0x1e0);
  local_240 = SelectObject(hdc,h);
  hdc_00 = CreateCompatibleDC(param_2);
  if (*(int **)(param_1 + 0x2c) == (int *)0x0) {
    pvVar1 = (HGDIOBJ)0x0;
  }
  else {
    pvVar1 = (HGDIOBJ)FUN_0002df24(*(int **)(param_1 + 0x2c),0xb);
  }
  pvVar1 = SelectObject(hdc_00,pvVar1);
  BitBlt(hdc,0,0,800,0x1e0,hdc_00,0,0,0xcc0020);
  SelectObject(hdc_00,pvVar1);
  SetBkMode(hdc,1);
  SetTextColor(hdc,0xe1e1e1);
  if (*(int *)(param_1 + 0x2c) == 0) {
    pvVar1 = (HGDIOBJ)0x0;
  }
  else {
    pvVar1 = (HGDIOBJ)FUN_0002da4c(*(int *)(param_1 + 0x2c),2);
  }
  pvVar1 = SelectObject(hdc,pvVar1);
  local_250.left = 0;
  local_250.top = 0x15;
  local_250.right = 800;
  local_250.bottom = 0x42;
  if (*(HINSTANCE *)(param_1 + 0x30) == (HINSTANCE)0x0) {
    wsprintfW(aWStack_238,L"Software Update");
  }
  else {
    LoadStringW(*(HINSTANCE *)(param_1 + 0x30),0x4ba,aWStack_238,0x40);
  }
  DrawTextW(hdc,aWStack_238,-1,&local_250,1);
  local_250.top = 0x8b;
  local_250.bottom = 0x103;
  if (*(HINSTANCE *)(param_1 + 0x30) == (HINSTANCE)0x0) {
    wsprintfW(aWStack_238,
              L"Update in progress\r\nDo not disconnect the USB\r\nor turn off the engine");
  }
  else {
    LoadStringW(*(HINSTANCE *)(param_1 + 0x30),0x4bb,aWStack_238,0x104);
  }
  DrawTextW(hdc,aWStack_238,-1,&local_250,format);
  SelectObject(hdc,pvVar1);
  if (*(int **)(param_1 + 0x2c) == (int *)0x0) {
    pvVar1 = (HGDIOBJ)0x0;
  }
  else {
    pvVar1 = (HGDIOBJ)FUN_0002df24(*(int **)(param_1 + 0x2c),0xc);
  }
  pvVar1 = SelectObject(hdc_00,pvVar1);
  uVar2 = 7;
  iVar5 = 7;
  iVar3 = 0;
  do {
    iVar4 = iVar3;
    TransparentImage(hdc,iVar4 + 0xd8,0x128,0x24,0x12,hdc_00,0x24,0,0x24,0x12,0xffff00);
    iVar5 = iVar5 + -1;
    iVar3 = iVar4 + 0x25;
  } while (iVar5 != 0);
  if (*(uint *)(param_1 + 0x10) == 1000) {
    iVar4 = iVar4 + 0xfd;
    do {
      TransparentImage(hdc,iVar4,0x128,0x24,0x12,hdc_00,0x24,0,0x24,0x12,0xffff00);
      iVar4 = iVar4 + 0x25;
      if (uVar2 < 9) {
        iVar5 = 9 - uVar2;
        iVar3 = iVar4;
        do {
          TransparentImage(hdc,iVar3,0x128,0x24,0x12,hdc_00,0,0,0x24,0x12,0xffff00);
          iVar5 = iVar5 + -1;
          iVar3 = iVar3 + 0x25;
        } while (iVar5 != 0);
      }
      BitBlt(param_2,0,0,800,0x1e0,hdc,0,0,0xcc0020);
      Sleep(1000);
      uVar2 = uVar2 + 1;
    } while (uVar2 < 10);
  }
  else {
    if (*(uint *)(param_1 + 0x10) < 0x21) {
      iVar5 = 3;
      uVar2 = 10;
      do {
        TransparentImage(hdc,iVar3 + 0xd8,0x128,0x24,0x12,hdc_00,0,0,0x24,0x12,0xffff00);
        iVar5 = iVar5 + -1;
        iVar3 = iVar3 + 0x25;
      } while (iVar5 != 0);
    }
    if (uVar2 < 10) {
      iVar3 = iVar3 + 0xd8;
      do {
        if (uVar2 < *(uint *)(param_1 + 0x10) / 0x21 + 7) {
          TransparentImage(hdc,iVar3,0x128,0x24,0x12,hdc_00,0x24,0,0x24,0x12,0xffff00);
          iVar3 = iVar3 + 0x25;
          if (uVar2 < 9) {
            iVar4 = 9 - uVar2;
            iVar5 = iVar3;
            do {
              TransparentImage(hdc,iVar5,0x128,0x24,0x12,hdc_00,0,0,0x24,0x12,0xffff00);
              iVar4 = iVar4 + -1;
              iVar5 = iVar5 + 0x25;
            } while (iVar4 != 0);
          }
        }
        uVar2 = uVar2 + 1;
      } while (uVar2 < 10);
    }
  }
  SelectObject(hdc_00,pvVar1);
  DeleteDC(hdc_00);
  BitBlt(param_2,0,0,800,0x1e0,hdc,0,0,0xcc0020);
  SelectObject(hdc,local_240);
  DeleteObject(h);
  DeleteDC(hdc);
  FUN_00043604(local_30);
  return;
}



/* 00018ac0 FUN_00018ac0 */

/* Boundary evidence: original MIPS .pdata 00018ac0..00018ccf. Semantic name remains unreviewed. */

void FUN_00018ac0(int param_1,HDC param_2)

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
  SetTextColor(hdc,0xe6e6e6);
  if (*(int *)(param_1 + 0x2c) == 0) {
    pvVar1 = (HGDIOBJ)0x0;
  }
  else {
    pvVar1 = (HGDIOBJ)FUN_0002da4c(*(int *)(param_1 + 0x2c),2);
  }
  pvVar1 = SelectObject(hdc,pvVar1);
  local_48.top = 0xbe;
  local_48.left = 100;
  local_38.left = 100;
  local_38.bottom = 0x118;
  local_38.top = 0xf0;
  local_48.bottom = 0xe6;
  local_48.right = 700;
  local_38.right = 700;
  DrawTextW(hdc,(LPCWSTR)(&PTR_u_Connect_Diag_tool__00054510)[DAT_000553e0 * 2],-1,&local_48,1);
  DrawTextW(hdc,(LPCWSTR)(&PTR_DAT_00054514)[DAT_000553e0 * 2],-1,&local_38,1);
  SelectObject(hdc,pvVar1);
  BitBlt(param_2,local_58.left,local_58.top,local_58.right - local_58.left,
         local_58.bottom - local_58.top,hdc,0,0,0xcc0020);
  SelectObject(hdc,h_00);
  DeleteObject(h);
  DeleteDC(hdc);
  return;
}



/* 00018cd0 FUN_00018cd0 */

/* Boundary evidence: original MIPS .pdata 00018cd0..0001902f. Semantic name remains unreviewed. */

void FUN_00018cd0(int param_1,HDC param_2)

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
  
  GetWindowRect(*(HWND *)(param_1 + 4),&local_48);
  hdc = CreateCompatibleDC(param_2);
  h = CreateCompatibleBitmap(param_2,local_48.right - local_48.left,local_48.bottom - local_48.top);
  h_00 = SelectObject(hdc,h);
  hbr = CreateSolidBrush(0);
  FillRect(hdc,&local_48,hbr);
  DeleteObject(hbr);
  SetBkMode(hdc,1);
  SetTextColor(hdc,0xe6e6e6);
  if (*(int *)(param_1 + 0x2c) == 0) {
    pvVar1 = (HGDIOBJ)0x0;
  }
  else {
    pvVar1 = (HGDIOBJ)FUN_0002da4c(*(int *)(param_1 + 0x2c),2);
  }
  pvVar1 = SelectObject(hdc,pvVar1);
  local_38.top = 0xbe;
  local_38.left = 100;
  local_58.left = 100;
  local_58.bottom = 0x140;
  local_38.right = 700;
  local_38.bottom = 0xe6;
  local_58.top = 0xf0;
  local_58.right = 700;
  if (*(int *)(param_1 + 0x24) == 0) {
    DrawTextW(hdc,L"FRONT BUTTON TEST",-1,&local_38,1);
  }
  else if (*(int *)(param_1 + 0x24) == 1) {
    DrawTextW(hdc,L"SWRC BUTTON TEST",-1,&local_38,1);
  }
  else {
    DrawTextW(hdc,L"UNKNOWN BUTTON TEST",-1,&local_38,1);
  }
  SelectObject(hdc,pvVar1);
  if (*(int *)(param_1 + 0x2c) == 0) {
    pvVar1 = (HGDIOBJ)0x0;
  }
  else {
    pvVar1 = (HGDIOBJ)FUN_0002da4c(*(int *)(param_1 + 0x2c),5);
  }
  pvVar1 = SelectObject(hdc,pvVar1);
  SetTextColor(hdc,0x1919ff);
  iVar2 = *(int *)(param_1 + 0x28);
  if (iVar2 == 0) {
    DrawTextW(hdc,L"START",-1,&local_58,1);
  }
  else if (iVar2 == 1) {
    DrawTextW(hdc,L"KEY #1",-1,&local_58,1);
  }
  else if (iVar2 == 2) {
    DrawTextW(hdc,L"KEY #2",-1,&local_58,1);
  }
  else if (iVar2 == 3) {
    DrawTextW(hdc,L"KEY #3",-1,&local_58,1);
  }
  else if (iVar2 == 4) {
    DrawTextW(hdc,L"END",-1,&local_58,1);
  }
  else if (iVar2 == 5) {
    DrawTextW(hdc,L"TIMEOUT",-1,&local_58,1);
  }
  else {
    DrawTextW(hdc,L"UNKNOWN",-1,&local_58,1);
  }
  SelectObject(hdc,pvVar1);
  BitBlt(param_2,local_48.left,local_48.top,local_48.right - local_48.left,
         local_48.bottom - local_48.top,hdc,0,0,0xcc0020);
  SelectObject(hdc,h_00);
  DeleteObject(h);
  DeleteDC(hdc);
  return;
}



/* 00019030 FUN_00019030 */

/* Boundary evidence: original MIPS .pdata 00019030..00019163. Semantic name remains unreviewed. */

void FUN_00019030(int param_1,undefined4 param_2,undefined4 param_3)

{
  HWND pHVar1;
  HDC hDC;
  int iVar2;
  HWND hWnd;
  
  iVar2 = *(int *)(param_1 + 0x18);
  if (((iVar2 != 1) && (iVar2 != 2)) && (iVar2 != 6)) {
    FUN_00014e14(DAT_000553a8,0);
    *(undefined4 *)(param_1 + 0xc) = param_2;
    *(undefined4 *)(param_1 + 0x14) = param_3;
    if (*(int *)(param_1 + 0x18) == 3) {
      hWnd = *(HWND *)(param_1 + 4);
      pHVar1 = GetForegroundWindow();
      if (pHVar1 != hWnd) {
        SetWindowPos(hWnd,(HWND)0xffffffff,0x6c,0x10,0x246,0x3f,0x40);
      }
    }
    else {
      *(undefined4 *)(param_1 + 0x18) = 3;
      SetWindowPos(*(HWND *)(param_1 + 4),(HWND)0xffffffff,0x6c,0x10,0x246,0x3f,0x40);
      hDC = GetDC(*(HWND *)(param_1 + 4));
      FUN_00017da0(param_1,hDC);
      ReleaseDC(*(HWND *)(param_1 + 4),hDC);
    }
    InvalidateRect(*(HWND *)(param_1 + 4),(RECT *)0x0,0);
    FUN_0002d814(param_1,3000);
  }
  return;
}



/* 00019164 FUN_00019164 */

/* Boundary evidence: original MIPS .pdata 00019164..00019213. Semantic name remains unreviewed. */

void FUN_00019164(int param_1,int param_2)

{
  HDC hDC;
  
  if (*(int *)(param_1 + 0x10) != param_2) {
    *(int *)(param_1 + 0x10) = param_2;
    if (*(int *)(param_1 + 0x18) != 5) {
      FUN_0002d83c(param_1);
      *(undefined4 *)(param_1 + 0x18) = 5;
      SetWindowPos(*(HWND *)(param_1 + 4),(HWND)0xffffffff,0,0,800,0x1e0,0x40);
    }
    InvalidateRect(*(HWND *)(param_1 + 4),(RECT *)0x0,0);
    hDC = GetDC(*(HWND *)(param_1 + 4));
    FUN_000184f0(param_1,hDC);
    ReleaseDC(*(HWND *)(param_1 + 4),hDC);
  }
  return;
}



/* 00019214 FUN_00019214 */

/* Boundary evidence: original MIPS .pdata 00019214..00019a0f. Semantic name remains unreviewed. */

void FUN_00019214(int param_1,HDC param_2)

{
  HDC hdc;
  HBITMAP h;
  HGDIOBJ h_00;
  HDC hdc_00;
  HGDIOBJ pvVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  _SYSTEMTIME _Stack_38;
  
  hdc = CreateCompatibleDC(param_2);
  h = CreateCompatibleBitmap(param_2,800,0x1e0);
  h_00 = SelectObject(hdc,h);
  hdc_00 = CreateCompatibleDC(param_2);
  if (*(int **)(param_1 + 0x2c) == (int *)0x0) {
    pvVar1 = (HGDIOBJ)0x0;
  }
  else {
    pvVar1 = (HGDIOBJ)FUN_0002df24(*(int **)(param_1 + 0x2c),7);
  }
  pvVar1 = SelectObject(hdc_00,pvVar1);
  BitBlt(hdc,0,0,800,0x1e0,hdc_00,0,0,0xcc0020);
  SelectObject(hdc_00,pvVar1);
  GetLocalTime(&_Stack_38);
  iVar5 = 0;
  if (DAT_000553e4 == 1) {
    iVar5 = 0x56;
  }
  uVar4 = (uint)_Stack_38.wMinute;
  uVar3 = (uint)_Stack_38.wHour;
  if (*(int **)(param_1 + 0x2c) == (int *)0x0) {
    pvVar1 = (HGDIOBJ)0x0;
  }
  else {
    pvVar1 = (HGDIOBJ)FUN_0002df24(*(int **)(param_1 + 0x2c),8);
  }
  pvVar1 = SelectObject(hdc_00,pvVar1);
  if (*(char *)(*(int *)(param_1 + 0x3c) + 0x682) == '\0') {
    if (uVar3 == 0) {
      uVar3 = 0xc;
    }
    if (0xc < uVar3) {
      uVar3 = uVar3 - 0xc;
    }
    if ((int)uVar3 < 10) {
      TransparentImage(hdc,iVar5 + 0xea,0xbc,0x3c,0x55,hdc_00,((int)uVar3 % 10) * 0x3c,0,0x3c,0x55,
                       0xffff00);
      TransparentImage(hdc,iVar5 + 0x14f,0xbc,0x3c,0x55,hdc_00,(uVar4 / 10) * 0x3c,0,0x3c,0x55,
                       0xffff00);
      TransparentImage(hdc,iVar5 + 0x193,0xbc,0x3c,0x55,hdc_00,(uVar4 % 10) * 0x3c,0,0x3c,0x55,
                       0xffff00);
    }
    else {
      TransparentImage(hdc,iVar5 + 0xa6,0xbc,0x3c,0x55,hdc_00,((int)uVar3 / 10) * 0x3c,0,0x3c,0x55,
                       0xffff00);
      TransparentImage(hdc,iVar5 + 0xea,0xbc,0x3c,0x55,hdc_00,((int)uVar3 % 10) * 0x3c,0,0x3c,0x55,
                       0xffff00);
      TransparentImage(hdc,iVar5 + 0x14f,0xbc,0x3c,0x55,hdc_00,(uVar4 / 10) * 0x3c,0,0x3c,0x55,
                       0xffff00);
      TransparentImage(hdc,iVar5 + 0x193,0xbc,0x3c,0x55,hdc_00,(uVar4 % 10) * 0x3c,0,0x3c,0x55,
                       0xffff00);
    }
  }
  else {
    TransparentImage(hdc,0xfc,0xbc,0x3c,0x55,hdc_00,(uVar3 / 10) * 0x3c,0,0x3c,0x55,0xffff00);
    TransparentImage(hdc,0x140,0xbc,0x3c,0x55,hdc_00,(uVar3 % 10) * 0x3c,0,0x3c,0x55,0xffff00);
    TransparentImage(hdc,0x1a5,0xbc,0x3c,0x55,hdc_00,(uVar4 / 10) * 0x3c,0,0x3c,0x55,0xffff00);
    TransparentImage(hdc,0x1e9,0xbc,0x3c,0x55,hdc_00,(uVar4 % 10) * 0x3c,0,0x3c,0x55,0xffff00);
  }
  SelectObject(hdc_00,pvVar1);
  if (*(char *)(*(int *)(param_1 + 0x3c) + 0x682) == '\0') {
    if (*(int **)(param_1 + 0x2c) == (int *)0x0) {
      pvVar1 = (HGDIOBJ)0x0;
    }
    else {
      pvVar1 = (HGDIOBJ)FUN_0002df24(*(int **)(param_1 + 0x2c),9);
    }
    pvVar1 = SelectObject(hdc_00,pvVar1);
    iVar2 = iVar5 + 0x1e1;
    if (_Stack_38.wHour < 0xc) {
      if ((int)uVar3 < 10) {
        TransparentImage(hdc,iVar2,0xbc,0x9b,0x55,hdc_00,0,0,0x9b,0x55,0xffff00);
      }
      else {
        TransparentImage(hdc,iVar2,0xbc,0x9b,0x55,hdc_00,0,0,0x9b,0x55,0xffff00);
      }
    }
    else if ((int)uVar3 < 10) {
      TransparentImage(hdc,iVar2,0xbc,0x9b,0x55,hdc_00,0x9b,0,0x9b,0x55,0xffff00);
    }
    else {
      TransparentImage(hdc,iVar2,0xbc,0x9b,0x55,hdc_00,0x9b,0,0x9b,0x55,0xffff00);
    }
    SelectObject(hdc_00,pvVar1);
  }
  if (*(int *)(param_1 + 0x38) == 1) {
    if (*(int **)(param_1 + 0x2c) == (int *)0x0) {
      pvVar1 = (HGDIOBJ)0x0;
    }
    else {
      pvVar1 = (HGDIOBJ)FUN_0002df24(*(int **)(param_1 + 0x2c),10);
    }
    pvVar1 = SelectObject(hdc_00,pvVar1);
    if (*(char *)(*(int *)(param_1 + 0x3c) + 0x682) == '\0') {
      if ((int)uVar3 < 10) {
        TransparentImage(hdc,iVar5 + 0x12e,0xbc,0x19,0x55,hdc_00,0,0,0x19,0x55,0xffff00);
      }
      else {
        TransparentImage(hdc,iVar5 + 0x12e,0xbc,0x19,0x55,hdc_00,0,0,0x19,0x55,0xffff00);
      }
    }
    else {
      TransparentImage(hdc,0x184,0xbc,0x19,0x55,hdc_00,0,0,0x19,0x55,0xffff00);
    }
    SelectObject(hdc_00,pvVar1);
    if ((*(char *)(DAT_000553a8 + 0x18) == '\x01') || (*(char *)(DAT_000553a8 + 0x18) == '\x02')) {
      FUN_00018244(param_1,hdc,0);
    }
    *(undefined4 *)(param_1 + 0x38) = 0;
  }
  else {
    if ((*(char *)(DAT_000553a8 + 0x18) == '\x01') || (*(char *)(DAT_000553a8 + 0x18) == '\x02')) {
      FUN_00018244(param_1,hdc,1);
    }
    *(undefined4 *)(param_1 + 0x38) = 1;
  }
  DeleteDC(hdc_00);
  BitBlt(param_2,0,0,800,0x1e0,hdc,0,0,0xcc0020);
  SelectObject(hdc,h_00);
  DeleteObject(h);
  DeleteDC(hdc);
  return;
}



/* 00019a10 FUN_00019a10 */

/* Boundary evidence: original MIPS .pdata 00019a10..00019b3b. Semantic name remains unreviewed. */

void FUN_00019a10(int param_1,HDC param_2)

{
  switch(*(undefined4 *)(param_1 + 0x18)) {
  case 1:
    if (*(int *)(DAT_00055498 + 0x60) == 0) {
      FUN_00019214(param_1,param_2);
    }
    break;
  case 2:
    FUN_0001690c(param_1,param_2);
    break;
  case 3:
    FUN_00017da0(param_1,param_2);
    break;
  case 4:
    if (*(int *)(DAT_00055498 + 0x50) == 1) {
      NKDbgPrintfW(L" CDisp::OnDraw() %d, %d\r\n",*(undefined4 *)(param_1 + 0x18),1);
    }
    else {
      FUN_0001690c(param_1,param_2);
    }
    break;
  case 5:
    FUN_000184f0(param_1,param_2);
    break;
  case 6:
    FUN_00018ac0(param_1,param_2);
    break;
  case 7:
    FUN_00016980(param_1,param_2);
    break;
  case 8:
    FUN_00016bb0(param_1,param_2);
    break;
  case 9:
    FUN_00018cd0(param_1,param_2);
  }
  return;
}



/* 00019b3c FUN_00019b3c */

/* Boundary evidence: original MIPS .pdata 00019b3c..00019bef. Semantic name remains unreviewed. */

undefined4 FUN_00019b3c(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined8 uVar1;
  
  uVar1 = CONCAT44(DAT_00055414,DAT_00055410);
  if (param_1 == DAT_00055440) {
    DAT_00055444 = DAT_00055444 + 1;
  }
  else {
    DAT_00055444 = 0;
  }
  DAT_00055440 = param_1;
  if (4 < DAT_00055444) {
    DAT_00055444 = 0;
    uVar1 = __dpmul(param_3,param_4,0,0x40140000);
    uVar1 = __dpmul((int)uVar1,(int)((ulonglong)uVar1 >> 0x20),0x5a912e32,0x3efd208a);
    uVar1 = __dpadd((int)uVar1,(int)((ulonglong)uVar1 >> 0x20),DAT_00055410,DAT_00055414);
  }
  DAT_00055414 = (undefined4)((ulonglong)uVar1 >> 0x20);
  DAT_00055410 = (undefined4)uVar1;
  return DAT_00055410;
}



/* 00019bf0 FUN_00019bf0 */

/* Boundary evidence: original MIPS .pdata 00019bf0..00019ed3. Semantic name remains unreviewed. */

longlong FUN_00019bf0(int param_1)

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
    DAT_00055458 = GetTickCount();
    uVar8 = 0xbff00000;
  }
  else {
    DVar1 = GetTickCount();
    iVar6 = DAT_00055458;
    if (DAT_00055458 == 0) {
      iVar6 = DVar1 - 100;
    }
    uVar9 = __ultodp(DVar1 - iVar6);
    uVar9 = __dpmul((int)uVar9,(int)((ulonglong)uVar9 >> 0x20),0xd2f1a9fc,0x3f50624d);
    uVar9 = __dpmul((int)uVar9,(int)((ulonglong)uVar9 >> 0x20),*(undefined4 *)(DAT_00055408 + 0x10),
                    *(undefined4 *)(DAT_00055408 + 0x14));
    uVar10 = __dpmul((int)uVar9,(int)((ulonglong)uVar9 >> 0x20),0x789abcdf,0x3f323456);
    uVar7 = (undefined4)((ulonglong)uVar10 >> 0x20);
    DAT_00055458 = DVar1;
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
    uVar12 = __dpadd((int)uVar12,(int)((ulonglong)uVar12 >> 0x20),DAT_00055418,DAT_0005541c);
    uVar5 = (undefined4)((ulonglong)uVar12 >> 0x20);
    uVar2 = (undefined4)uVar12;
    DAT_00055418 = uVar2;
    DAT_0005541c = uVar5;
    uVar9 = __dpmul((int)uVar11,uVar3,(int)uVar9,uVar4);
    uVar9 = __dpmul((int)uVar9,(int)((ulonglong)uVar9 >> 0x20),(int)uVar10,uVar7);
    uVar9 = __dpadd((int)uVar9,(int)((ulonglong)uVar9 >> 0x20),DAT_00055420,DAT_00055424);
    uVar7 = (undefined4)((ulonglong)uVar9 >> 0x20);
    DAT_00055420 = (int)uVar9;
    DAT_00055424 = uVar7;
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



/* 00019ed4 FUN_00019ed4 */

/* Boundary evidence: original MIPS .pdata 00019ed4..0001a1b7. Semantic name remains unreviewed. */

longlong FUN_00019ed4(int param_1)

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
    DAT_00055468 = GetTickCount();
    uVar8 = 0xbff00000;
  }
  else {
    DVar1 = GetTickCount();
    iVar6 = DAT_00055468;
    if (DAT_00055468 == 0) {
      iVar6 = DVar1 - 100;
    }
    uVar9 = __ultodp(DVar1 - iVar6);
    uVar9 = __dpmul((int)uVar9,(int)((ulonglong)uVar9 >> 0x20),0xd2f1a9fc,0x3f50624d);
    uVar9 = __dpmul((int)uVar9,(int)((ulonglong)uVar9 >> 0x20),*(undefined4 *)(DAT_00055408 + 0x10),
                    *(undefined4 *)(DAT_00055408 + 0x14));
    uVar10 = __dpmul((int)uVar9,(int)((ulonglong)uVar9 >> 0x20),0x789abcdf,0x3f323456);
    uVar7 = (undefined4)((ulonglong)uVar10 >> 0x20);
    DAT_00055468 = DVar1;
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
    uVar12 = __dpadd((int)uVar12,(int)((ulonglong)uVar12 >> 0x20),DAT_00055428,DAT_0005542c);
    uVar5 = (undefined4)((ulonglong)uVar12 >> 0x20);
    uVar2 = (undefined4)uVar12;
    DAT_00055428 = uVar2;
    DAT_0005542c = uVar5;
    uVar9 = __dpmul((int)uVar11,uVar3,(int)uVar9,uVar4);
    uVar9 = __dpmul((int)uVar9,(int)((ulonglong)uVar9 >> 0x20),(int)uVar10,uVar7);
    uVar9 = __dpadd((int)uVar9,(int)((ulonglong)uVar9 >> 0x20),DAT_00055430,DAT_00055434);
    uVar7 = (undefined4)((ulonglong)uVar9 >> 0x20);
    DAT_00055430 = (int)uVar9;
    DAT_00055434 = uVar7;
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



/* 0001a1b8 FUN_0001a1b8 */

/* Boundary evidence: original MIPS .pdata 0001a1b8..0001a2e3. Semantic name remains unreviewed. */

longlong FUN_0001a1b8(void)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  longlong lVar6;
  
  uVar4 = __litodp();
  uVar4 = __dpadd((int)uVar4,(int)((ulonglong)uVar4 >> 0x20),DAT_00055438,DAT_0005543c);
  uVar2 = (undefined4)((ulonglong)uVar4 >> 0x20);
  DAT_0005540c = DAT_0005540c + 1;
  DAT_00055438 = (int)uVar4;
  DAT_0005543c = uVar2;
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



/* 0001a2e4 FUN_0001a2e4 */

/* Boundary evidence: original MIPS .pdata 0001a2e4..0001a3f3. Semantic name remains unreviewed. */

longlong FUN_0001a2e4(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
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



/* 0001a3f4 FUN_0001a3f4 */

/* Boundary evidence: original MIPS .pdata 0001a3f4..0001a497. Semantic name remains unreviewed. */

longlong FUN_0001a3f4(void)

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



/* 0001a498 FUN_0001a498 */

/* Boundary evidence: original MIPS .pdata 0001a498..0001a68f. Semantic name remains unreviewed. */

void FUN_0001a498(int param_1)

{
  DWORD DVar1;
  int iVar2;
  
  *(undefined4 *)(param_1 + 0x50) = 1;
  *(undefined4 *)(param_1 + 0x2c) = 1;
  iVar2 = *(int *)(param_1 + 0x1c);
  *(undefined4 *)(iVar2 + 0x698) = 0;
  *(undefined4 *)(iVar2 + 0x69c) = 0;
  iVar2 = *(int *)(param_1 + 0x1c);
  *(undefined4 *)(param_1 + 0x30) = *(undefined4 *)(iVar2 + 0x6b8);
  *(undefined4 *)(param_1 + 0x34) = *(undefined4 *)(iVar2 + 0x6bc);
  *(undefined4 *)(param_1 + 0x5c) = 0x65;
  *(undefined4 *)(iVar2 + 0x6b8) = 0;
  *(undefined4 *)(iVar2 + 0x6bc) = 0;
  iVar2 = *(int *)(param_1 + 0x1c);
  *(undefined4 *)(iVar2 + 0x6c0) = 0;
  *(undefined4 *)(iVar2 + 0x6c4) = 0;
  iVar2 = *(int *)(param_1 + 0x1c);
  *(undefined4 *)(iVar2 + 0x6b0) = 0xcccccccd;
  *(undefined4 *)(iVar2 + 0x6b4) = 0x40598ccc;
  iVar2 = *(int *)(param_1 + 0x1c);
  *(undefined4 *)(iVar2 + 0x6c8) = 0x66666666;
  *(undefined4 *)(iVar2 + 0x6cc) = 0x40799666;
  DAT_00055410 = 0;
  DAT_00055418 = 0;
  DAT_00055420 = 0;
  DAT_00055428 = 0;
  DAT_00055430 = 0;
  DAT_00055438 = 0;
  *(undefined4 *)(param_1 + 0x44) = 0;
  *(undefined4 *)(param_1 + 0x48) = 0;
  *(undefined4 *)(param_1 + 0x40) = 0x3fe;
  *(undefined4 *)(param_1 + 0x4c) = 0xffe;
  *(undefined4 *)(param_1 + 0x60) = 0;
  DAT_00055414 = 0;
  DAT_00055444 = 0;
  DAT_0005541c = 0;
  DAT_00055424 = 0;
  DAT_0005542c = 0;
  DAT_00055434 = 0;
  DAT_0005543c = 0;
  DAT_0005540c = 0;
  memset(&DAT_00054628,100,0x140);
  DAT_00055450 = 0;
  DAT_00055448 = 0;
  DAT_0005544c = 0;
  DAT_00055454 = 0;
  memset(&DAT_00054768,100,0x140);
  DAT_00055460 = 0;
  DAT_0005545c = 0;
  DAT_0005544d = 0;
  DAT_00055464 = 0;
  memset(&DAT_000548a8,100,0x140);
  iVar2 = *(int *)(param_1 + 0x1c);
  *(undefined4 *)(iVar2 + 0x6e0) = 0;
  *(undefined4 *)(iVar2 + 0x6e4) = 0;
  DAT_0005544e = 0;
  *(undefined4 *)(*(int *)(param_1 + 0x1c) + 0x6d0) = 100;
  *(undefined4 *)(*(int *)(param_1 + 0x1c) + 0x6d4) = 100;
  *(undefined4 *)(*(int *)(param_1 + 0x1c) + 0x6d8) = 100;
  DAT_00055470 = 0;
  DAT_0005546c = 0;
  DAT_00055474 = 0;
  *(undefined4 *)(*(int *)(param_1 + 0x1c) + 0x6dc) = 0x65;
  DVar1 = GetTickCount();
  *(DWORD *)(param_1 + 0x18) = DVar1;
  *(undefined4 *)(param_1 + 100) = 0;
  *(undefined4 *)(param_1 + 0x68) = 0;
  *(undefined4 *)(param_1 + 0x58) = 0;
  *(undefined4 *)(param_1 + 0x54) = 0;
  DAT_00055440 = 0;
  DAT_00055458 = 0;
  DAT_00055468 = 0;
  return;
}



/* 0001a690 FUN_0001a690 */

/* Boundary evidence: original MIPS .pdata 0001a690..0001a72f. Semantic name remains unreviewed. */

bool FUN_0001a690(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined8 uVar2;
  
  uVar2 = __litodp(param_2);
  uVar2 = __dpmul((int)uVar2,(int)((ulonglong)uVar2 >> 0x20),0x47ae147b,0x3f847ae1);
  iVar1 = __ned(*(undefined4 *)(param_1 + 0x10),*(undefined4 *)(param_1 + 0x14),(int)uVar2,
                (int)((ulonglong)uVar2 >> 0x20));
  if (iVar1 != 0) {
    *(undefined8 *)(param_1 + 0x10) = uVar2;
    *(undefined8 *)(*(int *)(param_1 + 0x1c) + 0x690) = uVar2;
  }
  return iVar1 != 0;
}



/* 0001a730 FUN_0001a730 */

/* Boundary evidence: original MIPS .pdata 0001a730..0001a7e7. Semantic name remains unreviewed. */

undefined4 FUN_0001a730(int param_1,int param_2)

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
      *(undefined8 *)(*(int *)(param_1 + 0x1c) + 0x6b0) = uVar3;
      *(int *)(param_1 + 0x40) = param_2;
    }
    else {
      iVar2 = *(int *)(param_1 + 0x1c);
      *(undefined4 *)(iVar2 + 0x6b0) = 0xcccccccd;
      *(undefined4 *)(iVar2 + 0x6b4) = 0x40598ccc;
      *(undefined4 *)(param_1 + 0x40) = 0x3fe;
    }
    uVar1 = 1;
  }
  return uVar1;
}



/* 0001a7e8 FUN_0001a7e8 */

/* Boundary evidence: original MIPS .pdata 0001a7e8..0001a88b. Semantic name remains unreviewed. */

undefined4 FUN_0001a7e8(int param_1,int param_2)

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
      *(undefined8 *)(*(int *)(param_1 + 0x1c) + 0x6b8) = uVar3;
    }
    else {
      iVar2 = *(int *)(param_1 + 0x1c);
      *(undefined4 *)(param_1 + 0x44) = 0;
      *(undefined4 *)(iVar2 + 0x6b8) = 0;
      *(undefined4 *)(iVar2 + 0x6bc) = 0;
    }
    uVar1 = 1;
  }
  return uVar1;
}



/* 0001a88c FUN_0001a88c */

/* Boundary evidence: original MIPS .pdata 0001a88c..0001a9a7. Semantic name remains unreviewed. */

undefined4 FUN_0001a88c(int param_1,int param_2)

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
        *(undefined8 *)(*(int *)(param_1 + 0x1c) + 0x6c0) = uVar3;
      }
      else {
        uVar3 = __litodp(param_2);
        uVar3 = __dpmul((int)uVar3,(int)((ulonglong)uVar3 >> 0x20),0x9999999a,0x3fb99999);
        iVar1 = __gtd((int)uVar3,(int)((ulonglong)uVar3 >> 0x20),0x33333333,0x40a99933);
        if (iVar1 != 0) {
          uVar3 = 0;
        }
        *(undefined8 *)(*(int *)(param_1 + 0x1c) + 0x6c0) = uVar3;
      }
    }
    else {
      iVar1 = *(int *)(param_1 + 0x1c);
      *(undefined4 *)(param_1 + 0x48) = 0;
      *(undefined4 *)(iVar1 + 0x6c0) = 0;
      *(undefined4 *)(iVar1 + 0x6c4) = 0;
    }
    uVar2 = 1;
  }
  return uVar2;
}



/* 0001a9a8 FUN_0001a9a8 */

/* Boundary evidence: original MIPS .pdata 0001a9a8..0001aa5f. Semantic name remains unreviewed. */

undefined4 FUN_0001a9a8(int param_1,int param_2)

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
      *(undefined8 *)(*(int *)(param_1 + 0x1c) + 0x6c8) = uVar3;
      *(int *)(param_1 + 0x4c) = param_2;
    }
    else {
      iVar2 = *(int *)(param_1 + 0x1c);
      *(undefined4 *)(iVar2 + 0x6c8) = 0x66666666;
      *(undefined4 *)(iVar2 + 0x6cc) = 0x40799666;
      *(undefined4 *)(param_1 + 0x4c) = 0xffe;
    }
    uVar1 = 1;
  }
  return uVar1;
}



/* 0001aa60 FUN_0001aa60 */

/* Boundary evidence: original MIPS .pdata 0001aa60..0001ab67. Semantic name remains unreviewed. */

void FUN_0001aa60(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  longlong lVar4;
  
  iVar1 = __led(*(undefined4 *)(param_1 + 0x10),*(undefined4 *)(param_1 + 0x14),0,0);
  if ((((iVar1 == 0) && (*(int *)(DAT_00055498 + 0x1c) == 0)) &&
      (*(int *)(DAT_00055498 + 0x30) == 0)) &&
     ((*(int *)(param_1 + 0x28) == 0 && (*(int *)(param_1 + 0x2c) == 0)))) {
    iVar2 = *(int *)(param_1 + 0x1c);
    iVar1 = __ltd(*(undefined4 *)(iVar2 + 0x6b8),*(undefined4 *)(iVar2 + 0x6bc),0x9999999a,
                  0x3fd99999);
    if (iVar1 == 0) {
      __dptofp(*(undefined4 *)(iVar2 + 0x698),*(undefined4 *)(iVar2 + 0x69c));
      lVar4 = FUN_00019ed4(*(int *)(param_1 + 0x58));
      uVar3 = (undefined4)((ulonglong)lVar4 >> 0x20);
      iVar1 = __ged((int)lVar4,uVar3,0,0);
      if ((iVar1 != 0) && (0 < *(int *)(param_1 + 0x40))) {
        uVar3 = __dptoli((int)lVar4,uVar3);
        *(undefined4 *)(*(int *)(param_1 + 0x1c) + 0x6d4) = uVar3;
      }
    }
  }
  return;
}



/* 0001ab68 FUN_0001ab68 */

/* Boundary evidence: original MIPS .pdata 0001ab68..0001ac6f. Semantic name remains unreviewed. */

void FUN_0001ab68(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  longlong lVar4;
  
  iVar1 = __led(*(undefined4 *)(param_1 + 0x10),*(undefined4 *)(param_1 + 0x14),0,0);
  if ((((iVar1 == 0) && (*(int *)(DAT_00055498 + 0x1c) == 0)) &&
      (*(int *)(DAT_00055498 + 0x30) == 0)) &&
     ((*(int *)(param_1 + 0x28) == 0 && (*(int *)(param_1 + 0x2c) == 0)))) {
    iVar2 = *(int *)(param_1 + 0x1c);
    iVar1 = __ltd(*(undefined4 *)(iVar2 + 0x6b8),*(undefined4 *)(iVar2 + 0x6bc),0x9999999a,
                  0x3fd99999);
    if (iVar1 == 0) {
      __dptofp(*(undefined4 *)(iVar2 + 0x698),*(undefined4 *)(iVar2 + 0x69c));
      lVar4 = FUN_00019bf0(*(int *)(param_1 + 0x54));
      uVar3 = (undefined4)((ulonglong)lVar4 >> 0x20);
      iVar1 = __ged((int)lVar4,uVar3,0,0);
      if ((iVar1 != 0) && (0 < *(int *)(param_1 + 0x40))) {
        uVar3 = __dptoli((int)lVar4,uVar3);
        *(undefined4 *)(*(int *)(param_1 + 0x1c) + 0x6d0) = uVar3;
      }
    }
  }
  return;
}



/* 0001ac70 FUN_0001ac70 */

/* Boundary evidence: original MIPS .pdata 0001ac70..0001ae8f. Semantic name remains unreviewed. */

void FUN_0001ac70(int param_1)

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
  if (*(int *)(DAT_00055498 + 0x1c) != 0) {
    return;
  }
  if (*(int *)(DAT_00055498 + 0x30) != 0) {
    return;
  }
  if (*(int *)(param_1 + 0x28) != 0) {
    return;
  }
  uVar5 = __dpmul(uVar2,uVar4,0x5a912e32,0x3efd208a);
  iVar1 = *(int *)(param_1 + 0x1c);
  uVar5 = __dpadd(*(undefined4 *)(iVar1 + 0x698),*(undefined4 *)(iVar1 + 0x69c),(int)uVar5,
                  (int)((ulonglong)uVar5 >> 0x20));
  *(undefined8 *)(iVar1 + 0x698) = uVar5;
  iVar3 = *(int *)(param_1 + 0x1c);
  iVar1 = __ged(*(undefined4 *)(iVar3 + 0x698),*(undefined4 *)(iVar3 + 0x69c),0x9999999a,0x3fd99999)
  ;
  if (iVar1 != 0) {
    *(undefined4 *)(iVar3 + 0x698) = 0x9999999a;
    *(undefined4 *)(iVar3 + 0x69c) = 0x3fd99999;
  }
  iVar3 = *(int *)(param_1 + 0x1c);
  iVar1 = __ged(*(undefined4 *)(iVar3 + 0x698),*(undefined4 *)(iVar3 + 0x69c),0x9999999a,0x3fd99999)
  ;
  if ((iVar1 == 0) || (*(int *)(param_1 + 0x2c) == 0)) {
    uVar5 = __dpsub(*(undefined4 *)(iVar3 + 0x6b8),*(undefined4 *)(iVar3 + 0x6bc),
                    *(undefined4 *)(param_1 + 0x30),*(undefined4 *)(param_1 + 0x34));
    iVar1 = __ged((int)uVar5,(int)((ulonglong)uVar5 >> 0x20),0x9999999a,0x3fd99999);
    if ((iVar1 == 0) || (*(int *)(param_1 + 0x2c) == 0)) goto LAB_0001adec;
  }
  *(undefined4 *)(param_1 + 0x30) = 0;
  *(undefined4 *)(param_1 + 0x34) = 0;
  *(undefined4 *)(param_1 + 0x2c) = 0;
  FUN_00015f10(DAT_000553cc,1,1,0xb,0,0,100);
LAB_0001adec:
  if (*(int *)(param_1 + 0x2c) == 0) {
    iVar3 = *(int *)(param_1 + 0x1c);
    iVar1 = __ltd(*(undefined4 *)(iVar3 + 0x6b8),*(undefined4 *)(iVar3 + 0x6bc),0x9999999a,
                  0x3fd99999);
    if (iVar1 == 0) {
      uVar2 = *(undefined4 *)(iVar3 + 0x694);
      iVar1 = __gtd(*(undefined4 *)(iVar3 + 0x690),uVar2,0,0);
      if (iVar1 != 0) {
        uVar2 = FUN_00019b3c(*(int *)(param_1 + 0x60),uVar2,*(undefined4 *)(param_1 + 0x10),
                             *(undefined4 *)(param_1 + 0x14));
        iVar1 = __ged(uVar2,extraout_v1,0,0);
        if (iVar1 != 0) {
          iVar1 = *(int *)(param_1 + 0x1c);
          *(undefined4 *)(iVar1 + 0x6e0) = uVar2;
          *(undefined4 *)(iVar1 + 0x6e4) = extraout_v1;
        }
      }
    }
  }
  return;
}



/* 0001ae90 FUN_0001ae90 */

/* Boundary evidence: original MIPS .pdata 0001ae90..0001affb. Semantic name remains unreviewed. */

void FUN_0001ae90(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  longlong lVar7;
  
  iVar1 = __led(*(undefined4 *)(param_1 + 0x10),*(undefined4 *)(param_1 + 0x14),0,0);
  if ((((iVar1 == 0) && (*(int *)(DAT_00055498 + 0x1c) == 0)) &&
      (*(int *)(DAT_00055498 + 0x30) == 0)) &&
     ((*(int *)(param_1 + 0x28) == 0 && (*(int *)(param_1 + 0x2c) == 0)))) {
    iVar3 = *(int *)(param_1 + 0x1c);
    iVar1 = __ltd(*(undefined4 *)(iVar3 + 0x6b8),*(undefined4 *)(iVar3 + 0x6bc),0x9999999a,
                  0x3fd99999);
    if ((iVar1 == 0) && (*(int *)(param_1 + 0x50) == 0)) {
      if (*(int *)(param_1 + 0x24) == 0) {
        iVar1 = *(int *)(param_1 + 0x1c);
        __litodp(*(undefined4 *)(iVar1 + 0x6d0));
        __litodp(*(undefined4 *)(iVar1 + 0x6d4));
        lVar7 = FUN_0001a3f4();
      }
      else {
        uVar4 = __litodp(*(undefined4 *)(iVar3 + 0x6d0));
        uVar5 = __litodp(*(undefined4 *)(iVar3 + 0x6d4));
        uVar6 = __litodp(*(undefined4 *)(iVar3 + 0x6d8));
        lVar7 = FUN_0001a2e4((int)uVar6,(int)((ulonglong)uVar6 >> 0x20),(int)uVar5,
                             (int)((ulonglong)uVar5 >> 0x20),(int)uVar4,
                             (int)((ulonglong)uVar4 >> 0x20));
      }
      uVar2 = __dptoli((int)lVar7,(int)((ulonglong)lVar7 >> 0x20));
      *(undefined4 *)(iVar3 + 0x6dc) = uVar2;
    }
  }
  return;
}



/* 0001affc FUN_0001affc */

/* Boundary evidence: original MIPS .pdata 0001affc..0001b11b. Semantic name remains unreviewed. */

void FUN_0001affc(int param_1)

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
    if (iVar2 < DAT_00054624) {
      DAT_00054624 = iVar2;
    }
  }
  else {
    iVar3 = 0;
    if (iVar2 != 0) {
      iVar3 = DAT_00054624;
    }
    uVar5 = 0xbff0000000000000;
    if (((-1 < iVar3) && (uVar5 = 0xbff0000000000000, iVar3 < 0x65)) &&
       (iVar2 = __ged(*(undefined4 *)(*(int *)(param_1 + 0x1c) + 0x6b8),
                      *(undefined4 *)(*(int *)(param_1 + 0x1c) + 0x6bc),0x9999999a,0x3fd99999),
       uVar5 = 0xbff0000000000000, iVar2 != 0)) {
      lVar4 = FUN_0001a1b8();
      iVar2 = __dptoli((int)lVar4,(int)((ulonglong)lVar4 >> 0x20));
      uVar5 = 0xbff0000000000000;
      if ((-1 < iVar2) && (uVar5 = uVar1, 0 < *(int *)(param_1 + 0x40))) {
        uVar5 = __litodp(iVar2);
      }
    }
    DAT_00054624 = 0x65;
  }
  iVar2 = __dptoli((int)uVar5,(int)((ulonglong)uVar5 >> 0x20));
  if (-1 < iVar2) {
    *(int *)(*(int *)(param_1 + 0x1c) + 0x6d8) = iVar2;
  }
  return;
}



/* 0001b11c FUN_0001b11c */

/* Boundary evidence: original MIPS .pdata 0001b11c..0001b19f. Semantic name remains unreviewed. */

void FUN_0001b11c(int param_1,int param_2,undefined1 param_3)

{
  undefined1 local_18 [8];
  
  if (param_2 == 0xcc) {
    FUN_0001a498(param_1);
    local_18[0] = param_3;
    FUN_00015f10(DAT_000553cc,1,1,0xc,(int)local_18,1,100);
    SetTimer(*(HWND *)(param_1 + 4),0x70b,0x5dc,(TIMERPROC)0x0);
  }
  return;
}



/* 0001b1a0 FUN_0001b1a0 */

/* Boundary evidence: original MIPS .pdata 0001b1a0..0001b26b. Semantic name remains unreviewed. */

void FUN_0001b1a0(int param_1)

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
  *(uint *)(*(int *)(param_1 + 0x1c) + 0x6a0) = uVar2;
  *(undefined4 *)(*(int *)(param_1 + 0x1c) + 0x6a4) = *(undefined4 *)(param_1 + 100);
  return;
}



/* 0001b26c FUN_0001b26c */

/* Boundary evidence: original MIPS .pdata 0001b26c..0001b41f. Semantic name remains unreviewed. */

void FUN_0001b26c(int param_1)

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
      FUN_0001b1a0(param_1);
      iVar2 = *(int *)(param_1 + 0x1c);
      *(undefined4 *)(iVar2 + 0x6e0) = local_60;
      DAT_00055410 = local_60;
      DAT_00055414 = local_5c;
      *(undefined4 *)(iVar2 + 0x6e4) = local_5c;
      DAT_00055418 = local_58;
      DAT_00055420 = local_50;
      DAT_0005541c = local_54;
      DAT_00055428 = local_48;
      DAT_00055430 = local_40;
      DAT_00055424 = local_4c;
      DAT_0005542c = local_44;
      DAT_00055438 = local_38;
      DAT_00055434 = local_3c;
      DAT_0005540c = local_30;
      DAT_0005543c = local_34;
      iVar2 = *(int *)(param_1 + 0x1c);
      *(undefined4 *)(iVar2 + 0x698) = local_28;
      *(undefined4 *)(iVar2 + 0x69c) = local_24;
      *(undefined4 *)(*(int *)(param_1 + 0x1c) + 0x6dc) = local_20;
      *(undefined4 *)(*(int *)(param_1 + 0x1c) + 0x6d8) = local_1c;
      *(undefined4 *)(*(int *)(param_1 + 0x1c) + 0x6d0) = local_18;
      *(undefined4 *)(*(int *)(param_1 + 0x1c) + 0x6d4) = local_14;
    }
    NKDbgPrintfW(L"read dwDay : %d  dwTime : %d \r\n",local_64,local_68);
  }
  CloseHandle(hFile);
  return;
}



/* 0001b420 FUN_0001b420 */

/* Boundary evidence: original MIPS .pdata 0001b420..0001b60b. Semantic name remains unreviewed. */

void FUN_0001b420(int param_1)

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
    local_68 = DAT_00055410;
    local_60 = DAT_00055418;
    local_5c = DAT_0005541c;
    local_64 = DAT_00055414;
    local_58 = DAT_00055420;
    local_50 = DAT_00055428;
    local_4c = DAT_0005542c;
    local_54 = DAT_00055424;
    local_48 = DAT_00055430;
    local_40 = DAT_00055438;
    iVar6 = *(int *)(param_1 + 0x1c);
    local_3c = DAT_0005543c;
    local_44 = DAT_00055434;
    local_38 = DAT_0005540c;
    local_30 = *(undefined4 *)(iVar6 + 0x698);
    local_2c = *(undefined4 *)(iVar6 + 0x69c);
    local_28 = *(undefined4 *)(iVar6 + 0x6dc);
    if (*(int *)(param_1 + 0x24) == 0) {
      local_24 = 100;
    }
    else {
      local_24 = *(undefined4 *)(*(int *)(param_1 + 0x1c) + 0x6d8);
    }
    local_20 = *(undefined4 *)(*(int *)(param_1 + 0x1c) + 0x6d0);
    local_1c = *(undefined4 *)(*(int *)(param_1 + 0x1c) + 0x6d4);
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



/* 0001b60c FUN_0001b60c */

/* Boundary evidence: original MIPS .pdata 0001b60c..0001b653. Semantic name remains unreviewed. */

void FUN_0001b60c(int param_1,int param_2)

{
  if (*(int *)(param_1 + 0x20) != param_2) {
    *(int *)(param_1 + 0x20) = param_2;
    if (param_2 == 0) {
      FUN_0002d83c(param_1);
    }
    else {
      *(undefined4 *)(param_1 + 8) = 100;
      FUN_0002d814(param_1,100);
    }
  }
  return;
}



/* 0001b654 FUN_0001b654 */

undefined4 FUN_0001b654(int param_1)

{
  return *(undefined4 *)(param_1 + 0x20);
}



/* 0001b65c FUN_0001b65c */

/* Boundary evidence: original MIPS .pdata 0001b65c..0001b697. Semantic name remains unreviewed. */

void FUN_0001b65c(int param_1)

{
  if (*(int *)(param_1 + 0x50) != 0) {
    *(undefined4 *)(param_1 + 0x50) = 0;
    FUN_000338ac(0xcb,0);
    NKDbgPrintfW(L"[MicomMgr]send IDM_MMCM_AMAIN_ECO_CLUSTER_RESET_DONE message!!! \r\n");
  }
  return;
}



/* 0001b698 FUN_0001b698 */

/* Boundary evidence: original MIPS .pdata 0001b698..0001b8bf. Semantic name remains unreviewed. */

void FUN_0001b698(int param_1,byte *param_2)

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
  if (DAT_0005547c == 0) {
    DAT_0005547c = 1;
    if ((((uVar6 == 0xffe) && (uVar2 == 0x3fe)) && (uVar4 == 0)) && (uVar5 == 0)) {
      FUN_0001a498(param_1);
      *(undefined4 *)(param_1 + 0x50) = 0;
      goto LAB_0001b820;
    }
    if (*(uint *)(param_1 + 0x38) != uVar3) {
      *(uint *)(param_1 + 0x38) = uVar3;
      *(uint *)(*(int *)(param_1 + 0x1c) + 0x6a8) = uVar3;
    }
    if (*(uint *)(param_1 + 0x3c) != uVar7) {
      *(uint *)(param_1 + 0x3c) = uVar7;
      *(uint *)(*(int *)(param_1 + 0x1c) + 0x6ac) = uVar7;
    }
  }
  else {
    if (*(int *)(param_1 + 0x50) != 0) goto LAB_0001b820;
    if (*(uint *)(param_1 + 0x38) != uVar3) {
      *(uint *)(param_1 + 0x38) = uVar3;
      *(uint *)(*(int *)(param_1 + 0x1c) + 0x6a8) = uVar3;
    }
    if (*(uint *)(param_1 + 0x3c) != uVar7) {
      *(uint *)(param_1 + 0x3c) = uVar7;
      *(uint *)(*(int *)(param_1 + 0x1c) + 0x6ac) = uVar7;
    }
  }
  FUN_0001a730(param_1,uVar2);
  FUN_0001a7e8(param_1,uVar4);
  FUN_0001a88c(param_1,uVar5);
  FUN_0001a9a8(param_1,uVar6);
LAB_0001b820:
  if ((char)bVar1 < '\0') {
    FUN_0001a498(param_1);
    FUN_000338ac(0xca,0);
    local_28[0] = 0;
    FUN_00015f10(DAT_000553cc,1,1,0xc,(int)local_28,1,100);
  }
  else if (*(int *)(param_1 + 0x50) != 0) {
    *(undefined4 *)(param_1 + 0x50) = 0;
    FUN_000338ac(0xcb,0);
    NKDbgPrintfW(L"[MicomMgr]send IDM_MMCM_AMAIN_ECO_CLUSTER_RESET_DONE message!!! \r\n");
  }
  return;
}



/* 0001b8c0 FUN_0001b8c0 */

/* Boundary evidence: original MIPS .pdata 0001b8c0..0001b987. Semantic name remains unreviewed. */

void FUN_0001b8c0(int param_1,int param_2)

{
  int iVar1;
  
  *(int *)(param_1 + 0x28) = param_2;
  if (param_2 == 0) {
    FUN_00015f10(DAT_000553cc,1,1,0xb,0,0,100);
  }
  else {
    *(undefined4 *)(param_1 + 0x5c) = 0x65;
    iVar1 = *(int *)(param_1 + 0x1c);
    *(undefined4 *)(iVar1 + 0x6b8) = 0;
    *(undefined4 *)(iVar1 + 0x6bc) = 0;
    iVar1 = *(int *)(param_1 + 0x1c);
    *(undefined4 *)(iVar1 + 0x6c0) = 0;
    *(undefined4 *)(iVar1 + 0x6c4) = 0;
    iVar1 = *(int *)(param_1 + 0x1c);
    *(undefined4 *)(iVar1 + 0x6b0) = 0xcccccccd;
    *(undefined4 *)(iVar1 + 0x6b4) = 0x40598ccc;
    iVar1 = *(int *)(param_1 + 0x1c);
    *(undefined4 *)(iVar1 + 0x6c8) = 0x66666666;
    *(undefined4 *)(iVar1 + 0x6cc) = 0x40799666;
    *(undefined4 *)(param_1 + 0x44) = 0;
    *(undefined4 *)(param_1 + 0x48) = 0;
    *(undefined4 *)(param_1 + 0x40) = 0x3fe;
    *(undefined4 *)(param_1 + 0x4c) = 0xffe;
    *(undefined4 *)(param_1 + 0x60) = 0;
    FUN_0001a690(param_1,0);
  }
  return;
}



/* 0001b988 FUN_0001b988 */

/* Boundary evidence: original MIPS .pdata 0001b988..0001bad3. Semantic name remains unreviewed. */

undefined4 * FUN_0001b988(undefined4 *param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  DWORD DVar1;
  int iVar2;
  
  FUN_0002d7e0(param_1,param_2,param_3);
  *param_1 = &PTR_FUN_00047188;
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
  *(undefined4 *)(param_4 + 0x698) = 0;
  *(undefined4 *)(param_4 + 0x69c) = 0;
  iVar2 = param_1[7];
  *(undefined4 *)(iVar2 + 0x6e0) = 0;
  *(undefined4 *)(iVar2 + 0x6e4) = 0;
  *(undefined4 *)(param_1[7] + 0x6d0) = 100;
  *(undefined4 *)(param_1[7] + 0x6d4) = 100;
  *(undefined4 *)(param_1[7] + 0x6d8) = 100;
  *(undefined4 *)(param_1[7] + 0x6dc) = 0x65;
  iVar2 = param_1[7];
  *(undefined4 *)(iVar2 + 0x6b0) = 0xcccccccd;
  *(undefined4 *)(iVar2 + 0x6b4) = 0x40598ccc;
  iVar2 = param_1[7];
  *(undefined4 *)(iVar2 + 0x6c8) = 0x66666666;
  *(undefined4 *)(iVar2 + 0x6cc) = 0x40799666;
  *(undefined4 *)(param_1[7] + 0x6a8) = param_1[0xe];
  *(undefined4 *)(param_1[7] + 0x6ac) = param_1[0xf];
  DVar1 = GetTickCount();
  param_1[6] = DVar1;
  FUN_0001b26c((int)param_1);
  param_1[0x17] = 0x65;
  param_1[10] = 0;
  param_1[0xb] = 0;
  param_1[0xc] = 0;
  param_1[0xd] = 0;
  return param_1;
}



/* 0001bad4 FUN_0001bad4 */

/* Boundary evidence: original MIPS .pdata 0001bad4..0001bb2b. Semantic name remains unreviewed. */

undefined4 * FUN_0001bad4(undefined4 *param_1,uint param_2)

{
  *param_1 = &PTR_FUN_00047188;
  FUN_0002d85c(param_1);
  if ((param_2 & 1) != 0) {
    __3_YAXPAX_Z(param_1);
  }
  return param_1;
}



/* 0001bb2c FUN_0001bb2c */

/* Boundary evidence: original MIPS .pdata 0001bb2c..0001bbb3. Semantic name remains unreviewed. */

void FUN_0001bb2c(int param_1)

{
  int iVar1;
  
  iVar1 = __led(*(undefined4 *)(param_1 + 0x10),*(undefined4 *)(param_1 + 0x14),0,0);
  if ((((iVar1 == 0) && (*(int *)(DAT_00055498 + 0x1c) == 0)) &&
      (*(int *)(DAT_00055498 + 0x30) == 0)) &&
     (((*(int *)(param_1 + 0x28) == 0 && (*(int *)(param_1 + 0x2c) == 0)) &&
      (*(int *)(param_1 + 0x24) != 0)))) {
    FUN_0001affc(param_1);
  }
  return;
}



/* 0001bbb4 FUN_0001bbb4 */

/* Boundary evidence: original MIPS .pdata 0001bbb4..0001bc27. Semantic name remains unreviewed. */

void FUN_0001bbb4(int param_1)

{
  if ((99 < *(uint *)(param_1 + 8)) && (*(uint *)(param_1 + 8) < 0x66)) {
    if (DAT_0005547c != 0) {
      FUN_0001ac70(param_1);
    }
    FUN_0001b1a0(param_1);
    FUN_0001ab68(param_1);
    FUN_0001aa60(param_1);
    FUN_0001ae90(param_1);
  }
  return;
}



/* 0001bc28 FUN_0001bc28 */

/* Boundary evidence: original MIPS .pdata 0001bc28..0001bcff. Semantic name remains unreviewed. */

void FUN_0001bc28(int param_1,byte *param_2)

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
      FUN_0001bb2c(param_1);
      DAT_00055494 = DAT_00055494 + 1;
    }
    if (DAT_00055478 == 0) {
      DAT_00055478 = 1;
      *(undefined4 *)(param_1 + 8) = 0x65;
      FUN_0002d814(param_1,100);
    }
  }
  return;
}



/* 0001bd00 FUN_0001bd00 */

/* Boundary evidence: original MIPS .pdata 0001bd00..0001bf53. Semantic name remains unreviewed. */

void FUN_0001bd00(int param_1,uint *param_2)

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
  
  local_14 = DAT_00055374;
  if ((*param_2 & 0xf00) == 0x200) {
    cVar1 = *(char *)((int)param_2 + 2);
    if (cVar1 == 'd') {
      if (*(char *)(*(int *)(param_1 + 0x1c) + 0x687) == '\0') {
        local_38 = 0;
        memset(&local_37,0,1);
        memset(auStack_36,0,3);
        memcpy(&local_38,param_2 + 1,(uint)*(byte *)((int)param_2 + 3));
        if (*(int *)(param_1 + 0x50) == 0) {
          FUN_0001a690(param_1,(uint)CONCAT11(local_38,local_37));
        }
      }
    }
    else if (cVar1 == 'f') {
      if (*(char *)(*(int *)(param_1 + 0x1c) + 0x687) == '\0') {
        local_48 = 0;
        memset(auStack_47,0,7);
        memcpy(&local_48,param_2 + 1,(uint)*(byte *)((int)param_2 + 3));
        FUN_0001b698(param_1,&local_48);
      }
    }
    else {
      if (cVar1 == 'g') {
        if (*(char *)(*(int *)(param_1 + 0x1c) + 0x687) != '\0') goto LAB_0001bf34;
        local_58 = 0;
        memset(auStack_57,0,4);
        memcpy(&local_58,param_2 + 1,(uint)*(byte *)((int)param_2 + 3));
        pbVar3 = &local_58;
      }
      else {
        if (((cVar1 != 'i') || (bVar2 = *(byte *)((int)param_2 + 3), bVar2 == 0)) ||
           (*(char *)(*(int *)(param_1 + 0x1c) + 0x687) != '\0')) goto LAB_0001bf34;
        local_30 = 0;
        memset(local_2f,0,0x1a);
        memcpy(&local_30,param_2 + 1,(uint)bVar2);
        if (*(int *)(param_1 + 0x50) == 0) {
          FUN_0001a690(param_1,(uint)CONCAT11(local_30,local_2f[0]));
        }
        local_40 = local_29;
        local_3c = local_25;
        FUN_0001b698(param_1,(byte *)&local_40);
        memset((void *)((int)&local_50 + 1),0,4);
        local_50 = local_21;
        pbVar3 = (byte *)&local_50;
      }
      FUN_0001bc28(param_1,pbVar3);
    }
  }
LAB_0001bf34:
  FUN_00043604(local_14);
  return;
}



/* 0001bf54 FUN_0001bf54 */

int FUN_0001bf54(undefined4 param_1,int param_2)

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



/* 0001bfbc FUN_0001bfbc */

/* Boundary evidence: original MIPS .pdata 0001bfbc..0001c02f. Semantic name remains unreviewed. */

void FUN_0001bfbc(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_0004757c;
  if ((HANDLE)param_1[0x1d] != (HANDLE)0x0) {
    CloseHandle((HANDLE)param_1[0x1d]);
  }
  if ((HANDLE)param_1[0x1e] != (HANDLE)0x0) {
    CloseHandle((HANDLE)param_1[0x1e]);
  }
  param_1[0x1d] = 0;
  param_1[0x1e] = 0;
  FUN_0002d85c(param_1);
  return;
}



/* 0001c030 FUN_0001c030 */

/* Boundary evidence: original MIPS .pdata 0001c030..0001c1db. Semantic name remains unreviewed. */

void FUN_0001c030(void)

{
  HANDLE hFindFile;
  wchar_t *pwVar1;
  DWORD DVar2;
  BOOL BVar3;
  _WIN32_FIND_DATAW local_670;
  wchar_t awStack_238 [260];
  uint local_30;
  
  local_30 = DAT_00055374;
  NKDbgPrintfW(L"[Micom Manager] [INFO] DeleteBrandPOIFile() \r\n");
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
          if (BVar3 == 0) {
            DVar2 = GetLastError();
            NKDbgPrintfW(L"[Info] DeleteBrandPOIFile() - error DeleteFile : [%s][0x%08X]\r\n",
                         local_670.cFileName + 0x102,DVar2);
          }
        }
      }
      else {
        NKDbgPrintfW(L"DeleteBrandPOIFile() - Directory : [%s]\r\n",&local_670.dwReserved1);
      }
      BVar3 = FindNextFileW(hFindFile,&local_670);
    } while (BVar3 != 0);
    FindClose(hFindFile);
  }
  FUN_00043604(local_30);
  return;
}



/* 0001c1dc FUN_0001c1dc */

/* Boundary evidence: original MIPS .pdata 0001c1dc..0001c397. Semantic name remains unreviewed. */

void FUN_0001c1dc(int param_1,int param_2)

{
  byte bVar1;
  int iVar2;
  char cVar3;
  uint uVar5;
  undefined1 auStack_420 [1024];
  uint local_20;
  uint uVar4;
  
  local_20 = DAT_00055374;
  if (*(int *)(param_1 + 0x20) != 1) goto LAB_0001c374;
  Sleep(0x32);
  if (param_2 == 0x21) {
    NKDbgPrintfW(L"CMicom:OnRequest - checksum fail : %d, %d\r\n",*(undefined4 *)(param_1 + 0x24),
                 0x21);
    iVar2 = *(int *)(param_1 + 0x24);
LAB_0001c280:
    *(int *)(param_1 + 0x24) = iVar2 + -1;
  }
  else if (param_2 == 0x22) {
    NKDbgPrintfW(L"CMicom:OnRequest - flash write fail : %d, %d\r\n",*(undefined4 *)(param_1 + 0x24)
                 ,0x22);
    iVar2 = *(int *)(param_1 + 0x24);
    goto LAB_0001c280;
  }
  if (*(int **)(param_1 + 0x28) == (int *)0x0) {
    FUN_000260c4((undefined4 *)&DAT_00055638,1,'\b',auStack_420);
    goto LAB_0001c374;
  }
  uVar5 = *(int *)(param_1 + 0x24) + 0xffU & 0xff;
  if (0xde < uVar5) {
    uVar5 = 0xdf;
  }
  iVar2 = **(int **)(param_1 + 0x28);
  FUN_00019164(DAT_000553dc,(uint)(*(int *)(param_1 + 0x24) * 100) / 0xe0);
  if (uVar5 < 8) {
    uVar4 = uVar5 + 8 & 0xff;
LAB_0001c34c:
    cVar3 = (char)uVar4;
    bVar1 = 0;
  }
  else {
    cVar3 = (char)uVar5;
    uVar4 = uVar5;
    if (uVar5 < 0xdf) goto LAB_0001c34c;
    bVar1 = 4;
  }
  FUN_000260c4((undefined4 *)&DAT_00055638,bVar1,cVar3,(LPCVOID)(uVar5 * 0x400 + iVar2));
  iVar2 = *(int *)(param_1 + 0x24);
  *(int *)(param_1 + 0x24) = iVar2 + 1;
  if (uVar5 == 7) {
    *(int *)(param_1 + 0x24) = iVar2 + 9;
  }
LAB_0001c374:
  FUN_00043604(local_20);
  return;
}



/* 0001c398 FUN_0001c398 */

/* Boundary evidence: original MIPS .pdata 0001c398..0001c647. Semantic name remains unreviewed. */

void FUN_0001c398(int param_1)

{
  wchar_t *pwVar1;
  int iVar2;
  undefined1 local_18 [8];
  
  FUN_0002d6b0(DAT_00057130);
  NKDbgPrintfW(L"\n\n[**UpdatePwrState** %d]  m_bIsAccOff-%d, m_bIsPowerOff-%d, m_bIsLowVoltage-%d, m_bIsLocked-%d\n\n"
               ,*(undefined4 *)(param_1 + 0x2c),*(undefined4 *)(param_1 + 0x30),
               *(undefined4 *)(param_1 + 0x34),*(undefined4 *)(param_1 + 0x38),
               *(undefined4 *)(param_1 + 0x50));
  if ((((*(int *)(param_1 + 0x30) == 1) || (*(int *)(param_1 + 0x34) == 1)) ||
      (*(int *)(param_1 + 0x38) == 1)) || (*(int *)(param_1 + 0x50) == 1)) {
    *(undefined1 *)(*(int *)(param_1 + 0x10) + 0x688) = 1;
    if (*(int *)(param_1 + 0x34) == 0) {
      FUN_00033908(0x71,0);
    }
    FUN_000339cc(0x3030104,0);
    FUN_00016f4c(DAT_000553dc);
    return;
  }
  iVar2 = *(int *)(param_1 + 0x2c);
  if (iVar2 == 1) {
    *(undefined1 *)(*(int *)(param_1 + 0x10) + 0x688) = 0;
    if (*(int *)(param_1 + 0x1c) == 1) {
      FUN_00016cf0(DAT_000553dc);
    }
    else {
      FUN_00016c74(DAT_000553dc);
    }
    if (*(int *)(param_1 + 0x60) == 1) {
      NKDbgPrintfW(L"\r\n~(7)~%s~ PWRSTATE_NORMAL unmuted\r\n","CMicom::UpdatePwrState");
      return;
    }
    Sleep(100);
    FUN_000339cc(0x3030105,0);
    FUN_00033908(0x72,0);
    local_18[0] = 0;
    FUN_00015f10(DAT_000553cc,1,1,1,(int)local_18,1,100);
    pwVar1 = L"\r\n~(7)~PWRSTATE_NORMAL unmuted\r\n";
  }
  else {
    if (iVar2 == 2) {
      FUN_00016c74(DAT_000553dc);
      FUN_00033908(0x72,0);
      local_18[0] = 0;
      FUN_00015f10(DAT_000553cc,1,1,1,(int)local_18,1,100);
      NKDbgPrintfW(L"\r\n~(9)~PWRSTATE_NORMAL unmuted\r\n");
      FUN_00042e64(*(undefined4 *)(param_1 + 4));
      return;
    }
    if (iVar2 != 3) {
      return;
    }
    *(undefined1 *)(*(int *)(param_1 + 0x10) + 0x688) = 1;
    FUN_00033908(0x71,0);
    FUN_000339cc(0x3030104,0);
    if (*(int *)(param_1 + 0x1c) == 1) {
      FUN_00016cf0(DAT_000553dc);
    }
    else {
      FUN_00016e7c(DAT_000553dc);
    }
    local_18[0] = 1;
    FUN_00015f10(DAT_000553cc,1,1,1,(int)local_18,1,100);
    pwVar1 = L"\r\n~(8)~PWRSTATE_NORMAL muted\r\n";
  }
  NKDbgPrintfW(pwVar1);
  return;
}



/* 0001c648 FUN_0001c648 */

/* Boundary evidence: original MIPS .pdata 0001c648..0001c85f. Semantic name remains unreviewed. */

void FUN_0001c648(void)

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



/* 0001c860 FUN_0001c860 */

undefined4 FUN_0001c860(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = 1;
  if ((((*(int *)(param_1 + 0x2c) != 1) && (*(int *)(param_1 + 0x2c) != 2)) ||
      (*(int *)(param_1 + 0x30) != 0)) ||
     ((*(int *)(param_1 + 0x50) != 0 || (*(int *)(param_1 + 0x5c) != 0)))) {
    uVar1 = 0;
  }
  return uVar1;
}



/* 0001c8ac FUN_0001c8ac */

undefined4 FUN_0001c8ac(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = 1;
  if ((((*(int *)(param_1 + 0x2c) != 1) && (*(int *)(param_1 + 0x2c) != 2)) ||
      (*(int *)(param_1 + 0x30) != 0)) || (*(int *)(param_1 + 0x50) != 0)) {
    uVar1 = 0;
  }
  return uVar1;
}



/* 0001c8ec FUN_0001c8ec */

/* Boundary evidence: original MIPS .pdata 0001c8ec..0001c9b3. Semantic name remains unreviewed. */

void FUN_0001c8ec(int param_1)

{
  if (*(int *)(param_1 + 0x68) == 2) {
    FUN_00015f10(DAT_000553cc,7,1,2,
                 (int)(&UNK_00047574 +
                      (uint)*(byte *)(*(int *)(param_1 + 0x10) + 0x67c) +
                      *(int *)(param_1 + 100) * 3),1,100);
  }
  else {
    FUN_00015f10(DAT_000553cc,7,1,2,
                 (int)(&UNK_00047574 +
                      (uint)*(byte *)(*(int *)(param_1 + 0x10) + *(int *)(param_1 + 0x68) + 0x67a) +
                      *(int *)(param_1 + 0x68) * 3),1,100);
  }
  return;
}



/* 0001c9b4 FUN_0001c9b4 */

bool FUN_0001c9b4(int param_1)

{
  return *(int *)(param_1 + 0x2c) == 2;
}



/* 0001c9d0 FUN_0001c9d0 */

/* Boundary evidence: original MIPS .pdata 0001c9d0..0001cd13. Semantic name remains unreviewed. */

void FUN_0001c9d0(int param_1)

{
  ushort uVar1;
  HANDLE hFile;
  BOOL BVar2;
  undefined1 local_48;
  undefined1 local_47;
  UINT local_44;
  DWORD aDStack_40 [2];
  _PROCESS_INFORMATION local_38;
  
  uVar1 = *(ushort *)(param_1 + 0x98);
  NKDbgPrintfW(L"~~~~~~~~~~~::~~~~~~~~~~~~FCODE TIMEOUT code-%d, factory-%d, pwr_state-%d, m_nTimerID-%d\r\n"
               ,uVar1 >> 2 & 1,uVar1 & 1,uVar1 >> 4 & 1,*(undefined4 *)(param_1 + 0x4c));
  if ((*(ushort *)(param_1 + 0x98) & 4) != 0) {
    return;
  }
  if ((*(ushort *)(param_1 + 0x98) & 1) != 0) {
    *(undefined4 *)(param_1 + 0x50) = 1;
    FUN_0001c398(param_1);
    local_48 = 1;
    FUN_00015f10(DAT_000553cc,1,1,1,(int)&local_48,1,100);
    NKDbgPrintfW(L"\r\n~(10)~PWRSTATE_NORMAL muted\r\n");
    if (*(int *)(param_1 + 0x90) != 0) {
      return;
    }
    BVar2 = CreateProcessW(L"\\Storage Card\\system\\CodeChecker.exe",
                           L"(bd9r2a@_4G2g=1.5_J2tq7X@app",(LPSECURITY_ATTRIBUTES)0x0,
                           (LPSECURITY_ATTRIBUTES)0x0,0,0,(LPVOID)0x0,(LPCWSTR)0x0,
                           (LPSTARTUPINFOW)0x0,&local_38);
    if (BVar2 == 0) {
      FUN_00016c74(DAT_000553dc);
      MessageBoxW((HWND)0x0,L"CodeChecker.exe did not excute!!",L"Warning",0);
      return;
    }
    CloseHandle(local_38.hProcess);
    CloseHandle(local_38.hThread);
    return;
  }
  local_44 = 120000;
  if (*(int *)(param_1 + 0x70) == 1) {
    return;
  }
  FUN_00015f10(DAT_000553cc,5,1,0x41,0,0,100);
  hFile = CreateFileW(L"\\Storage Card2\\Antitheft.cfg",0x80000000,0,(LPSECURITY_ATTRIBUTES)0x0,3,
                      0x80,(HANDLE)0x0);
  if (hFile == (HANDLE)0xffffffff) goto LAB_0001cba4;
  BVar2 = ReadFile(hFile,&local_44,4,aDStack_40,(LPOVERLAPPED)0x0);
  if (BVar2 == 0) {
    NKDbgPrintfW(L"~~~~~~~~~~~::~~~~~~~~~~~~FCODE TIMEOUT ERROR - 2min\r\n");
LAB_0001cb90:
    local_44 = 120000;
  }
  else if (local_44 == 0) {
    local_44 = 60000;
  }
  else if ((int)local_44 < 1) {
LAB_0001cb6c:
    local_44 = 0x1d4c00;
  }
  else {
    if ((int)local_44 < 4) goto LAB_0001cb90;
    if (local_44 == 4) {
      local_44 = 240000;
    }
    else if (local_44 == 5) {
      local_44 = 480000;
    }
    else {
      if (local_44 != 6) goto LAB_0001cb6c;
      local_44 = 960000;
    }
  }
  CloseHandle(hFile);
LAB_0001cba4:
  NKDbgPrintfW(L"~~~~~~~~~~~::~~~~~~~~~~~~FCODE TIMEOUT timeout-%d\r\n",local_44);
  *(undefined4 *)(param_1 + 0x70) = 1;
  SetTimer(*(HWND *)(param_1 + 4),3,local_44,(TIMERPROC)0x0);
  local_48 = 0;
  local_47 = 0x14;
  FUN_00015f10(DAT_000553cc,5,1,0x40,(int)&local_48,2,100);
  return;
}



/* 0001cd14 FUN_0001cd14 */

/* Boundary evidence: original MIPS .pdata 0001cd14..0001d857. Semantic name remains unreviewed. */

void FUN_0001cd14(undefined4 param_1,uint param_2,LPWSTR param_3,int param_4)

{
  wchar_t *pwVar1;
  uint uVar2;
  
  if (param_3 == (LPWSTR)0x0) {
    return;
  }
  uVar2 = param_2 * 0x100 + (param_2 >> 8 & 0xff) & 0xffff;
  if (uVar2 < 0x4743) {
    if (uVar2 == 0x4742) {
      if (param_4 == 0) {
        pwVar1 = L"iGBNQ@11Q2";
      }
      else if (param_4 == 2) {
        pwVar1 = L"iGBHM@13Q4";
      }
      else {
        pwVar1 = L"iGBNQ@12Q4";
      }
      goto LAB_0001d844;
    }
    if (uVar2 < 0x434d) {
      if (uVar2 == 0x434c) {
        if (param_4 == 0) {
          pwVar1 = L"iCLNQ@11Q3";
        }
        else if (param_4 == 2) {
          pwVar1 = L"iCLHM@13Q4";
        }
        else {
          pwVar1 = L"iCLNQ@12Q4";
        }
        goto LAB_0001d844;
      }
      if (uVar2 < 0x4156) {
        if (uVar2 == 0x4155) {
          if (param_4 != 0) {
            if (param_4 == 2) {
              pwVar1 = L"iAUHM@13Q4";
            }
            else {
              pwVar1 = L"iAUNQ@12Q4";
            }
            goto LAB_0001d844;
          }
        }
        else if (uVar2 != 0x2323) {
          if (uVar2 == 0x2a2a) {
            pwVar1 = L"iNotActivated";
            goto LAB_0001d844;
          }
          if (uVar2 == 0x4141) {
            if (param_4 == 0) {
              pwVar1 = L"iAANQ@11Q4";
            }
            else if (param_4 == 2) {
              pwVar1 = L"iAAHM@13Q4";
            }
            else {
              pwVar1 = L"iAANQ@12Q4";
            }
            goto LAB_0001d844;
          }
          if (uVar2 == 0x4152) {
            if (param_4 == 0) {
              pwVar1 = L"iARNQ@11Q3";
            }
            else if (param_4 == 2) {
              pwVar1 = L"iARHM@13Q4";
            }
            else {
              pwVar1 = L"iARNQ@12Q4";
            }
            goto LAB_0001d844;
          }
          if (uVar2 == 0x4154) {
            if (param_4 == 0) {
              pwVar1 = L"iATNQ@11Q2";
            }
            else if (param_4 == 2) {
              pwVar1 = L"iATHM@13Q4";
            }
            else {
              pwVar1 = L"iATNQ@12Q4";
            }
            goto LAB_0001d844;
          }
          goto LAB_0001d764;
        }
LAB_0001ce7c:
        pwVar1 = L"iNOMAP";
        goto LAB_0001d844;
      }
      if (uVar2 == 0x4245) {
        if (param_4 == 0) {
          pwVar1 = L"iBENQ@11Q2";
        }
        else if (param_4 == 2) {
          pwVar1 = L"iBEHM@13Q4";
        }
        else {
          pwVar1 = L"iBENQ@12Q4";
        }
        goto LAB_0001d844;
      }
      if (uVar2 == 0x424b) {
        if (param_4 == 0) {
          pwVar1 = L"iBKNQ@11Q2";
        }
        else if (param_4 == 2) {
          pwVar1 = L"iBKHM@13Q4";
        }
        else {
          pwVar1 = L"iBKNQ@12Q4";
        }
        goto LAB_0001d844;
      }
      if (uVar2 == 0x4252) {
        if (param_4 == 0) {
          pwVar1 = L"iBRNQ@11Q4";
        }
        else if (param_4 == 2) {
          pwVar1 = L"iBRHM@13Q4";
        }
        else {
          pwVar1 = L"iBRNQ@12Q4";
        }
        goto LAB_0001d844;
      }
      if (uVar2 == 0x4348) {
        if (param_4 == 0) {
          pwVar1 = L"iCHNQ@11Q2";
        }
        else if (param_4 == 2) {
          pwVar1 = L"iCHHM@13Q4";
        }
        else {
          pwVar1 = L"iCHNQ@12Q4";
        }
        goto LAB_0001d844;
      }
    }
    else if (uVar2 < 0x4554) {
      if (uVar2 == 0x4553) {
        if (param_4 == 0) {
          pwVar1 = L"iESNQ@11Q2";
        }
        else if (param_4 == 2) {
          pwVar1 = L"iESHM@13Q4";
        }
        else {
          pwVar1 = L"iESNQ@12Q4";
        }
        goto LAB_0001d844;
      }
      if (uVar2 == 0x434f) {
        if (param_4 == 0) {
          pwVar1 = L"iCOCT@1104";
        }
        else if (param_4 == 2) {
          pwVar1 = L"iCOHM@13Q4";
        }
        else {
          pwVar1 = L"iCOCT@13Q1";
        }
        goto LAB_0001d844;
      }
      if (uVar2 == 0x435a) {
        if (param_4 == 0) {
          pwVar1 = L"iCZNQ@11Q2";
        }
        else if (param_4 == 2) {
          pwVar1 = L"iCZHM@13Q4";
        }
        else {
          pwVar1 = L"iCZNQ@12Q4";
        }
        goto LAB_0001d844;
      }
      if (uVar2 == 0x4441) {
        if (param_4 == 0) {
          pwVar1 = L"iDANQ@11Q2";
        }
        else if (param_4 == 2) {
          pwVar1 = L"iDAHM@13Q4";
        }
        else {
          pwVar1 = L"iDANQ@12Q4";
        }
        goto LAB_0001d844;
      }
      if (uVar2 == 0x4445) {
        if (param_4 == 0) {
          pwVar1 = L"iDENQ@11Q2";
        }
        else if (param_4 == 2) {
          pwVar1 = L"iDEHM@13Q4";
        }
        else {
          pwVar1 = L"iDENQ@12Q4";
        }
        goto LAB_0001d844;
      }
      if (uVar2 == 0x445a) {
        if (param_4 != 0) {
          if (param_4 == 2) {
            pwVar1 = L"iDZHM@13Q4";
          }
          else {
            pwVar1 = L"iDZTH@12Q4";
          }
          goto LAB_0001d844;
        }
        goto LAB_0001ce7c;
      }
    }
    else {
      if (uVar2 == 0x4631) {
        if (param_4 == 0) {
          pwVar1 = L"iFEUNQ@11Q2";
        }
        else if (param_4 == 2) {
          pwVar1 = L"iFEUHM@13Q4";
        }
        else {
          pwVar1 = L"iFEUNQ@12Q4";
        }
        goto LAB_0001d844;
      }
      if (uVar2 == 0x4632) {
        if (param_4 == 0) {
          pwVar1 = L"iAMRNQ@11Q3";
        }
        else if (param_4 == 2) {
          pwVar1 = L"iAMRHM@13Q4";
        }
        else {
          pwVar1 = L"iAMRNQ@12Q4";
        }
        goto LAB_0001d844;
      }
      if (uVar2 == 0x4633) {
        if (param_4 == 0) {
          pwVar1 = L"iOTHNQ@11Q3";
        }
        else if (param_4 == 2) {
          pwVar1 = L"iOTHHM@13Q4";
        }
        else {
          pwVar1 = L"iOTHNQ@12Q4";
        }
        goto LAB_0001d844;
      }
      if (uVar2 == 0x4652) {
        if (param_4 == 0) {
          pwVar1 = L"iFRNQ@11Q2";
        }
        else if (param_4 == 2) {
          pwVar1 = L"iFRHM@13Q4";
        }
        else {
          pwVar1 = L"iFRNQ@12Q4";
        }
        goto LAB_0001d844;
      }
    }
  }
  else if (uVar2 < 0x4e4d) {
    if (uVar2 == 0x4e4c) {
      if (param_4 == 0) {
        pwVar1 = L"iNLNQ@11Q2";
      }
      else if (param_4 == 2) {
        pwVar1 = L"iNLHM@13Q4";
      }
      else {
        pwVar1 = L"iNLNQ@12Q4";
      }
      goto LAB_0001d844;
    }
    if (uVar2 < 0x4955) {
      if (uVar2 == 0x4954) {
        if (param_4 == 0) {
          pwVar1 = L"iITNQ@11Q2";
        }
        else if (param_4 == 2) {
          pwVar1 = L"iITHM@13Q4";
        }
        else {
          pwVar1 = L"iITNQ@12Q4";
        }
        goto LAB_0001d844;
      }
      if (uVar2 == 0x4743) {
        if (param_4 == 0) {
          pwVar1 = L"iGCNQ@11Q4";
        }
        else if (param_4 == 2) {
          pwVar1 = L"iGCHM@13Q4";
        }
        else {
          pwVar1 = L"iGCNQ@12Q4";
        }
        goto LAB_0001d844;
      }
      if (uVar2 == 0x4752) {
        if (param_4 == 0) {
          pwVar1 = L"iGRNQ@11Q2";
        }
        else if (param_4 == 2) {
          pwVar1 = L"iGRHM@13Q4";
        }
        else {
          pwVar1 = L"iGRNQ@12Q4";
        }
        goto LAB_0001d844;
      }
      if (uVar2 == 0x4945) {
        if (param_4 == 0) {
          pwVar1 = L"iIENQ@11Q2";
        }
        else if (param_4 == 2) {
          pwVar1 = L"iIEHM@13Q4";
        }
        else {
          pwVar1 = L"iIENQ@12Q4";
        }
        goto LAB_0001d844;
      }
      if (uVar2 == 0x494c) {
        if (param_4 == 0) {
          pwVar1 = L"iILGP@1203";
        }
        else if (param_4 == 2) {
          pwVar1 = L"iILHM@13Q4";
        }
        else {
          pwVar1 = L"iILGP@1301";
        }
        goto LAB_0001d844;
      }
      if (uVar2 == 0x494e) {
        if (param_4 == 0) {
          pwVar1 = L"iINNQ@11Q2";
        }
        else if (param_4 == 2) {
          pwVar1 = L"iINHM@13Q4";
        }
        else {
          pwVar1 = L"iINNQ@12Q4";
        }
        goto LAB_0001d844;
      }
    }
    else {
      if (uVar2 == 0x4c4c) {
        if (param_4 == 0) {
          pwVar1 = L"iLLNQ@11Q2";
        }
        else if (param_4 == 2) {
          pwVar1 = L"iLLHM@13Q4";
        }
        else {
          pwVar1 = L"iLLNQ@12Q4";
        }
        goto LAB_0001d844;
      }
      if (uVar2 == 0x4d41) {
        if (param_4 == 0) {
          pwVar1 = L"iMANQ@11Q2";
        }
        else if (param_4 == 2) {
          pwVar1 = L"iMAHM@13Q4";
        }
        else {
          pwVar1 = L"iMANQ@12Q4";
        }
        goto LAB_0001d844;
      }
      if (uVar2 == 0x4d58) {
        if (param_4 == 0) {
          pwVar1 = L"iMXNQ@11Q4";
        }
        else if (param_4 == 2) {
          pwVar1 = L"iMXHM@13Q4";
        }
        else {
          pwVar1 = L"iMXNQ@12Q4";
        }
        goto LAB_0001d844;
      }
      if (uVar2 == 0x4d59) {
        if (param_4 != 0) {
          if (param_4 == 2) {
            pwVar1 = L"iMYHM@13Q4";
          }
          else {
            pwVar1 = L"iMYNQ@12Q4";
          }
          goto LAB_0001d844;
        }
        goto LAB_0001ce7c;
      }
    }
  }
  else if (uVar2 < 0x5250) {
    if (uVar2 == 0x524f) {
      if (param_4 == 0) {
        pwVar1 = L"iRONQ@11Q2";
      }
      else if (param_4 == 2) {
        pwVar1 = L"iROHM@13Q4";
      }
      else {
        pwVar1 = L"iRONQ@12Q4";
      }
      goto LAB_0001d844;
    }
    if (uVar2 == 0x4e4f) {
      if (param_4 == 0) {
        pwVar1 = L"iNONQ@11Q2";
      }
      else if (param_4 == 2) {
        pwVar1 = L"iNOHM@13Q4";
      }
      else {
        pwVar1 = L"iNONQ@12Q4";
      }
      goto LAB_0001d844;
    }
    if (uVar2 == 0x5045) {
      if (param_4 == 0) {
        pwVar1 = L"iPENS@1109";
      }
      else if (param_4 == 2) {
        pwVar1 = L"iNOMAP";
      }
      else {
        pwVar1 = L"iNOMAP";
      }
      goto LAB_0001d844;
    }
    if (uVar2 == 0x504f) {
      if (param_4 == 0) {
        pwVar1 = L"iPONQ@11Q2";
      }
      else if (param_4 == 2) {
        pwVar1 = L"iPOHM@13Q4";
      }
      else {
        pwVar1 = L"iPONQ@12Q4";
      }
      goto LAB_0001d844;
    }
    if (uVar2 == 0x5054) {
      if (param_4 == 0) {
        pwVar1 = L"iPTNQ@11Q2";
      }
      else if (param_4 == 2) {
        pwVar1 = L"iPTHM@13Q4";
      }
      else {
        pwVar1 = L"iPTNQ@12Q4";
      }
      goto LAB_0001d844;
    }
  }
  else {
    if (uVar2 == 0x5255) {
      if (param_4 == 0) {
        pwVar1 = L"iRUNQ@11Q3";
      }
      else if (param_4 == 2) {
        pwVar1 = L"iRUHM@13Q4";
      }
      else {
        pwVar1 = L"iRUNQ@12Q4";
      }
      goto LAB_0001d844;
    }
    if (uVar2 == 0x5347) {
      if (param_4 != 0) {
        if (param_4 == 2) {
          pwVar1 = L"iSGHM@13Q4";
        }
        else {
          pwVar1 = L"iSGNQ@12Q4";
        }
        goto LAB_0001d844;
      }
      goto LAB_0001ce7c;
    }
    if (uVar2 == 0x5452) {
      if (param_4 == 0) {
        pwVar1 = L"iTRNQ@11Q2";
      }
      else if (param_4 == 2) {
        pwVar1 = L"iTRHM@13Q4";
      }
      else {
        pwVar1 = L"iTRNQ@12Q4";
      }
      goto LAB_0001d844;
    }
    if (uVar2 == 0x5a41) {
      if (param_4 == 0) {
        pwVar1 = L"iZANQ@11Q2";
      }
      else if (param_4 == 2) {
        pwVar1 = L"iZAHM@13Q4";
      }
      else {
        pwVar1 = L"iZANQ@12Q4";
      }
      goto LAB_0001d844;
    }
  }
LAB_0001d764:
  pwVar1 = L"NO MAP";
LAB_0001d844:
  wsprintfW(param_3,pwVar1);
  return;
}



/* 0001d858 FUN_0001d858 */

/* Boundary evidence: original MIPS .pdata 0001d858..0001d8bf. Semantic name remains unreviewed. */

void FUN_0001d858(void)

{
  DWORD DVar1;
  BOOL BVar2;
  
  DVar1 = GetFileAttributesW(L"\\Storage Card\\system\\ULC_DTC.tbl");
  if (DVar1 != 0xffffffff) {
    BVar2 = DeleteFileW(L"\\Storage Card\\system\\ULC_DTC.tbl");
    NKDbgPrintfW(L"[DeleteDTCTable %s] [%d] ULC_DTC_NAME is deleted!!!\n",
                 L"\\Storage Card\\system\\ULC_DTC.tbl",BVar2);
  }
  return;
}



/* 0001d8c0 FUN_0001d8c0 */

/* Boundary evidence: original MIPS .pdata 0001d8c0..0001d9b3. Semantic name remains unreviewed. */

DWORD FUN_0001d8c0(undefined4 param_1,LPVOID param_2,DWORD param_3)

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



/* 0001d9b4 FUN_0001d9b4 */

bool FUN_0001d9b4(int param_1)

{
  return (*(ushort *)(param_1 + 0x98) & 4) == 0;
}



/* 0001d9d0 FUN_0001d9d0 */

/* Boundary evidence: original MIPS .pdata 0001d9d0..0001da13. Semantic name remains unreviewed. */

void FUN_0001d9d0(int param_1)

{
  if ((*(int *)(param_1 + 0x2c) == 3) || (*(int *)(param_1 + 0x50) == 1)) {
    FUN_000339cc(0x3030104,0);
  }
  return;
}



/* 0001da14 FUN_0001da14 */

/* Boundary evidence: original MIPS .pdata 0001da14..0001db77. Semantic name remains unreviewed. */

void FUN_0001da14(void)

{
  HANDLE pvVar1;
  int iVar2;
  DWORD local_188;
  DWORD DStack_184;
  undefined1 auStack_180 [176];
  _TIME_ZONE_INFORMATION _Stack_d0;
  uint local_24;
  
  local_24 = DAT_00055374;
  local_188 = 0;
  GetTimeZoneInformation(&_Stack_d0);
  memset(auStack_180,0,0xac);
  pvVar1 = CreateFileW(L"\\Storage Card2\\RTC_Clock.bin",0x80000000,0,(LPSECURITY_ATTRIBUTES)0x0,3,
                       0x80,(HANDLE)0x0);
  if (pvVar1 != (HANDLE)0xffffffff) {
    ReadFile(pvVar1,auStack_180,0xac,&local_188,(LPOVERLAPPED)0x0);
    CloseHandle(pvVar1);
  }
  iVar2 = memcmp(&_Stack_d0,auStack_180,0xac);
  if (iVar2 != 0) {
    pvVar1 = CreateFileW(L"\\Storage Card2\\RTC_Clock.bin",0x40000000,0,(LPSECURITY_ATTRIBUTES)0x0,2
                         ,0x80,(HANDLE)0x0);
    if (pvVar1 != (HANDLE)0xffffffff) {
      WriteFile(pvVar1,&_Stack_d0,0xac,&DStack_184,(LPOVERLAPPED)0x0);
      CloseHandle(pvVar1);
    }
  }
  FUN_00043604(local_24);
  return;
}



/* 0001db78 FUN_0001db78 */

/* Boundary evidence: original MIPS .pdata 0001db78..0001dc37. Semantic name remains unreviewed. */

void FUN_0001db78(void)

{
  errno_t eVar1;
  int iVar2;
  FILE *local_a0 [2];
  undefined1 auStack_98 [128];
  uint local_18;
  
  local_18 = DAT_00055374;
  eVar1 = fopen_s(local_a0,".\\Storage Card\\system\\mapcode_update.bin","rb");
  if (eVar1 == 0) {
    fread(auStack_98,0x80,1,local_a0[0]);
    fclose(local_a0[0]);
    iVar2 = FUN_00015b90(DAT_000553cc,0xf,8,(int)auStack_98,0x80,300);
    if (iVar2 == 1) {
      DeleteFileW(L".\\Storage Card\\system\\mapcode_update.bin");
    }
  }
  FUN_00043604(local_18);
  return;
}



/* 0001dc38 FUN_0001dc38 */

/* Boundary evidence: original MIPS .pdata 0001dc38..0001dd43. Semantic name remains unreviewed. */

void FUN_0001dc38(int param_1)

{
  BOOL BVar1;
  undefined1 local_28 [8];
  _PROCESS_INFORMATION local_20;
  
  *(undefined4 *)(param_1 + 0x50) = 1;
  FUN_0001c398(param_1);
  local_28[0] = 1;
  FUN_00015f10(DAT_000553cc,1,1,1,(int)local_28,1,100);
  NKDbgPrintfW(L"\r\n~(6)~PWRSTATE_NORMAL muted\r\n");
  if (*(int *)(param_1 + 0x90) == 0) {
    BVar1 = CreateProcessW(L"\\Storage Card\\system\\CodeChecker.exe",
                           L"(bd9r2a@_4G2g=1.5_J2tq7X@app",(LPSECURITY_ATTRIBUTES)0x0,
                           (LPSECURITY_ATTRIBUTES)0x0,0,0,(LPVOID)0x0,(LPCWSTR)0x0,
                           (LPSTARTUPINFOW)0x0,&local_20);
    if (BVar1 == 0) {
      FUN_00016c74(DAT_000553dc);
      MessageBoxW((HWND)0x0,L"CodeChecker.exe did not excute!!",L"Warning",0);
    }
    else {
      CloseHandle(local_20.hProcess);
      CloseHandle(local_20.hThread);
    }
  }
  return;
}



/* 0001dd44 FUN_0001dd44 */

/* Boundary evidence: original MIPS .pdata 0001dd44..0001ddf3. Semantic name remains unreviewed. */

void FUN_0001dd44(void)

{
  LSTATUS LVar1;
  HKEY local_10;
  int local_c;
  
  NKDbgPrintfW(L"~~~~~~~~~~~~\n\n[McmMgr] SetAutoTime()\r\n");
  FUN_000237bc(0);
  FUN_000238a0(1);
  LVar1 = RegOpenKeyExW((HKEY)0x80000002,L"LGE\\SystemInfo",0,0,&local_10);
  if (LVar1 == 0) {
    local_c = FUN_000236e4();
    RegSetValueExW(local_10,L"ManualTimeSet",0,4,(BYTE *)&local_c,4);
    RegCloseKey(local_10);
  }
  return;
}



/* 0001ddf4 FUN_0001ddf4 */

/* Boundary evidence: original MIPS .pdata 0001ddf4..0001df47. Semantic name remains unreviewed. */

void FUN_0001ddf4(int param_1)

{
  byte local_18 [8];
  
  if (DAT_00055384 != 0) {
    FUN_0001211c(DAT_00055384,1);
  }
  if ((*(int *)(param_1 + 0x88) != 0) || (*(int *)(param_1 + 0x84) != 0)) {
    local_18[0] = 0;
    FUN_00016068(DAT_000553cc,0,0x44,local_18,1,100);
    if (local_18[0] != *(byte *)(*(int *)(param_1 + 0x10) + 0x687)) {
      *(byte *)(*(int *)(param_1 + 0x10) + 0x687) = local_18[0];
      if (*(int *)(param_1 + 0x84) != 0) {
        FUN_0001b8c0(DAT_00055408,(uint)local_18[0]);
      }
      if (*(int *)(param_1 + 0x88) != 0) {
        FUN_00014e4c(DAT_000553a8,(uint)local_18[0]);
      }
      if ((*(int *)(param_1 + 0x88) != 0) || (*(int *)(param_1 + 0x84) != 0)) {
        FUN_000338ac(0xcd,(uint)local_18[0]);
      }
    }
  }
  FUN_000338ac(0x78,0);
  *(undefined4 *)(param_1 + 0x30) = 0;
  *(undefined4 *)(param_1 + 0x58) = 0;
  NKDbgPrintfW(L"[**NOTI_APP_ACC_ON**]  m_bIsPowerOff-%d, m_bIsAccOff-%d\n",
               *(undefined4 *)(param_1 + 0x34),0);
  FUN_0001c398(param_1);
  *(undefined4 *)(param_1 + 0x4c) = 0;
  FUN_0002d83c(param_1);
  FUN_00011500(DAT_00055384,1,0);
  return;
}



/* 0001df48 FUN_0001df48 */

/* Boundary evidence: original MIPS .pdata 0001df48..0001df9f. Semantic name remains unreviewed. */

void FUN_0001df48(int param_1,undefined2 param_2)

{
  *(undefined2 *)(*(int *)(param_1 + 0x10) + 0x67e) = param_2;
  FUN_000338ac(0x7a,(uint)*(ushort *)(*(int *)(param_1 + 0x10) + 0x67e));
  if (*(HWND *)(param_1 + 0x18) != (HWND)0x0) {
    PostMessageW(*(HWND *)(param_1 + 0x18),0x403,0,0);
  }
  return;
}



/* 0001dfa0 FUN_0001dfa0 */

/* Boundary evidence: original MIPS .pdata 0001dfa0..0001e55f. Semantic name remains unreviewed. */

void FUN_0001dfa0(undefined4 param_1,int param_2,int param_3,int param_4,int param_5,int param_6,
                 int param_7,int param_8,int param_9)

{
  undefined1 *puVar1;
  uint uVar2;
  HANDLE hObject;
  DWORD DVar3;
  int iVar4;
  int iVar5;
  DWORD DVar6;
  int iVar7;
  wchar_t *pwVar8;
  code *pcVar9;
  HANDLE hObject_00;
  HANDLE hObject_01;
  HANDLE hObject_02;
  HMODULE hLibModule;
  HANDLE hObject_03;
  int local_254;
  int local_250;
  undefined1 auStack_248 [8];
  int local_240;
  int local_23c;
  undefined1 auStack_238 [4];
  undefined1 auStack_234 [4];
  undefined1 auStack_230 [4];
  undefined1 auStack_22c [508];
  uint local_30;
  
  local_30 = DAT_00055374;
  NKDbgPrintfW(L"[**OnDiskDismount()**]  [%d, %d, %d, %d] \r\n",param_2,param_3,param_4,param_5);
  puVar1 = auStack_238 + 3;
  uVar2 = (uint)puVar1 & 3;
  *(uint *)(puVar1 + -uVar2) =
       *(uint *)(puVar1 + -uVar2) & -1 << (uVar2 + 1) * 8 | 0x530044U >> (3 - uVar2) * 8;
  puVar1 = auStack_234 + 3;
  uVar2 = (uint)puVar1 & 3;
  *(uint *)(puVar1 + -uVar2) =
       *(uint *)(puVar1 + -uVar2) & -1 << (uVar2 + 1) * 8 | 0x31004bU >> (3 - uVar2) * 8;
  puVar1 = auStack_230 + 3;
  uVar2 = (uint)puVar1 & 3;
  *(uint *)(puVar1 + -uVar2) =
       *(uint *)(puVar1 + -uVar2) & -1 << (uVar2 + 1) * 8 | 0x3aU >> (3 - uVar2) * 8;
  hObject_00 = (HANDLE)0xffffffff;
  hObject_01 = (HANDLE)0xffffffff;
  hObject_02 = (HANDLE)0xffffffff;
  hObject_03 = (HANDLE)0xffffffff;
  auStack_238 = (undefined1  [4])0x530044;
  auStack_234 = (undefined1  [4])0x31004b;
  auStack_230 = (undefined1  [4])0x3a;
  memset(auStack_22c,0,0x1fc);
  hObject = (HANDLE)OpenStore(auStack_238);
  if (hObject == (HANDLE)0xffffffff) goto LAB_0001e528;
  local_250 = 0;
  local_254 = 0;
  hLibModule = (HMODULE)0x0;
  local_240 = 0;
  pcVar9 = (code *)0x0;
  local_23c = 0;
  if (param_2 != 0) {
    hObject_00 = (HANDLE)OpenPartition(hObject,L"PART00");
  }
  if (param_3 != 0) {
    hObject_01 = (HANDLE)OpenPartition(hObject,L"PART01");
  }
  if (param_4 != 0) {
    hObject_02 = (HANDLE)OpenPartition(hObject,L"PART02");
  }
  if (param_5 != 0) {
    hObject_03 = (HANDLE)OpenPartition(hObject,L"PART03");
  }
  if ((((param_6 != 0) || (param_7 != 0)) || (param_8 != 0)) || (param_9 != 0)) {
    memset(auStack_248,0,8);
    hLibModule = LoadLibraryW(L"FATUTIL.DLL");
    if (hLibModule != (HMODULE)0x0) {
      pcVar9 = (code *)GetProcAddressW(hLibModule,L"ScanVolume");
    }
  }
  if (hObject_00 != (HANDLE)0xffffffff) {
    local_250 = DismountPartition(hObject_00);
    if (local_250 == 0) {
      DVar3 = GetLastError();
      pwVar8 = L"[Error][**OnDiskDismount()**] Storage Card  [0x%08X] \r\n";
LAB_0001e1a0:
      NKDbgPrintfW(pwVar8,DVar3);
    }
    else if ((param_6 != 0) && (pcVar9 != (code *)0x0)) {
      DVar3 = GetTickCount();
      iVar4 = (*pcVar9)(hObject_00,0,auStack_248,0,0);
      if (iVar4 == 0) {
        DVar3 = GetLastError();
        pwVar8 = L"[Error][**ScanVolume()**] Storage Card  [0x%08X] \r\n";
        goto LAB_0001e1a0;
      }
      DVar6 = GetTickCount();
      NKDbgPrintfW(L"[Total Time][**ScanVolume()**] Storage Card  [%d]msec \r\n",DVar6 - DVar3);
    }
    CloseHandle(hObject_00);
  }
  if (hObject_01 != (HANDLE)0xffffffff) {
    local_254 = DismountPartition(hObject_01);
    if (local_254 == 0) {
      DVar3 = GetLastError();
      NKDbgPrintfW(L"[Error][**OnDiskDismount()**] Storage Card2 [0x%08X] \r\n",DVar3);
    }
    else if ((param_7 != 0) && (pcVar9 != (code *)0x0)) {
      DVar3 = GetTickCount();
      iVar4 = (*pcVar9)(hObject_01,0,auStack_248,0,0);
      if (iVar4 == 0) {
        DVar6 = GetLastError();
        pwVar8 = L"[Error][**ScanVolume()**] Storage Card2  [0x%08X] \r\n";
      }
      else {
        DVar6 = GetTickCount();
        DVar6 = DVar6 - DVar3;
        pwVar8 = L"[Total Time][**ScanVolume()**] Storage Card2  [%d]msec \r\n";
      }
      NKDbgPrintfW(pwVar8,DVar6);
    }
    CloseHandle(hObject_01);
  }
  iVar4 = local_240;
  if (hObject_02 != (HANDLE)0xffffffff) {
    iVar4 = DismountPartition(hObject_02);
    if (iVar4 == 0) {
      DVar3 = GetLastError();
      NKDbgPrintfW(L"[Error][**OnDiskDismount()**] Storage Card3 [0x%08X] \r\n",DVar3);
    }
    else if ((param_8 != 0) && (pcVar9 != (code *)0x0)) {
      DVar3 = GetTickCount();
      iVar5 = (*pcVar9)(hObject_02,0,auStack_248,0,0);
      if (iVar5 == 0) {
        DVar6 = GetLastError();
        pwVar8 = L"[Error][**ScanVolume()**] Storage Card3  [0x%08X] \r\n";
      }
      else {
        DVar6 = GetTickCount();
        DVar6 = DVar6 - DVar3;
        pwVar8 = L"[Total Time][**ScanVolume()**] Storage Card3  [%d]msec \r\n";
      }
      NKDbgPrintfW(pwVar8,DVar6);
    }
    CloseHandle(hObject_02);
  }
  iVar5 = local_23c;
  if (hObject_03 != (HANDLE)0xffffffff) {
    iVar5 = DismountPartition(hObject_03);
    if (iVar5 == 0) {
      DVar6 = GetLastError();
      pwVar8 = L"[Error][**OnDiskDismount()**] Storage Card4 [0x%08X] \r\n";
LAB_0001e4c8:
      NKDbgPrintfW(pwVar8,DVar6);
    }
    else if ((param_9 != 0) && (pcVar9 != (code *)0x0)) {
      DVar3 = GetTickCount();
      iVar7 = (*pcVar9)(hObject_03,0,auStack_248,0,0);
      if (iVar7 == 0) {
        DVar6 = GetLastError();
        pwVar8 = L"[Error][**ScanVolume()**] Storage Card4  [0x%08X] \r\n";
      }
      else {
        DVar6 = GetTickCount();
        DVar6 = DVar6 - DVar3;
        pwVar8 = L"[Total Time][**ScanVolume()**] Storage Card4  [%d]msec \r\n";
      }
      goto LAB_0001e4c8;
    }
    CloseHandle(hObject_03);
  }
  if (hLibModule != (HMODULE)0x0) {
    FreeLibrary(hLibModule);
  }
  NKDbgPrintfW(L"[**OnDiskDismount()**] Result  [%d, %d, %d, %d] \r\n",local_250,local_254,iVar4,
               iVar5);
  CloseHandle(hObject);
LAB_0001e528:
  FUN_00043604(local_30);
  return;
}



/* 0001e560 FUN_0001e560 */

/* Boundary evidence: original MIPS .pdata 0001e560..0001e62b. Semantic name remains unreviewed. */

void FUN_0001e560(undefined4 param_1,undefined1 param_2,int param_3)

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



/* 0001e62c FUN_0001e62c */

/* Boundary evidence: original MIPS .pdata 0001e62c..0001e727. Semantic name remains unreviewed. */

int FUN_0001e62c(undefined4 param_1,undefined4 param_2)

{
  HANDLE hDevice;
  BOOL BVar1;
  wchar_t *pwVar2;
  undefined4 local_res4 [3];
  int local_18;
  DWORD DStack_14;
  
  local_res4[0] = param_2;
  hDevice = CreateFileW(L"DSK1:",0x40000000,2,(LPSECURITY_ATTRIBUTES)0x0,3,0x40000080,
                        (HANDLE)0xffffffff);
  if (hDevice == (HANDLE)0xffffffff) {
    NKDbgPrintfW(L"DSK1 Open error\r\n");
  }
  else {
    BVar1 = DeviceIoControl(hDevice,0x71f84,local_res4,1,&local_18,4,&DStack_14,(LPOVERLAPPED)0x0);
    if (local_18 == 0) {
      pwVar2 = L"eMMC Sleep OK[%d]\r\n";
    }
    else {
      pwVar2 = L"eMMC Sleep NG[%d]\r\n";
    }
    NKDbgPrintfW(pwVar2,BVar1);
    CloseHandle(hDevice);
  }
  return local_18;
}



/* 0001e728 FUN_0001e728 */

/* Boundary evidence: original MIPS .pdata 0001e728..0001e8e7. Semantic name remains unreviewed. */

BOOL FUN_0001e728(void)

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
  
  local_14 = DAT_00055374;
  BVar1 = 0;
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
    SetCommState(hFile,&_Stack_40);
    CloseHandle(hFile);
    NKDbgPrintfW(L"[%d-%d][GPS Port Close] \r\n",BVar1,local_80[0]);
  }
  FUN_00043604(local_14);
  return BVar1;
}



/* 0001e8e8 FUN_0001e8e8 */

/* Boundary evidence: original MIPS .pdata 0001e8e8..0001ea47. Semantic name remains unreviewed. */

void FUN_0001e8e8(undefined4 param_1,void *param_2)

{
  uint uVar1;
  wchar_t *pwVar2;
  undefined4 uVar3;
  undefined1 local_40 [36];
  uint local_1c;
  
  local_1c = DAT_00055374;
  uVar1 = FUN_00030de8(param_2);
  if (uVar1 != 0) {
    uVar1 = FUN_00016068(DAT_000553cc,0xd,0xf1,local_40,0xc,0x96);
    uVar1 = uVar1 & 0xff;
    if (uVar1 == 0xc) {
      uVar1 = FUN_00016068(DAT_000553cc,0xd,0xf2,local_40 + 0xc,0x14,0x96);
      uVar1 = uVar1 & 0xff;
      if (uVar1 == 0x14) {
        NKDbgPrintfW(L"\n ****Receiving Data******************  \n");
        uVar1 = 0;
        do {
          NKDbgPrintfW(L" %2X",local_40[uVar1]);
          uVar1 = uVar1 + 1;
        } while (uVar1 < 0x20);
        NKDbgPrintfW(&DAT_000494e0);
        FUN_0002fdc0(local_40,0x20);
        if (param_2 != (void *)0x0) {
          memcpy(param_2,local_40,0x20);
        }
        goto LAB_0001ea24;
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
LAB_0001ea24:
  FUN_00043604(local_1c);
  return;
}



/* 0001ea48 FUN_0001ea48 */

/* Boundary evidence: original MIPS .pdata 0001ea48..0001ebb3. Semantic name remains unreviewed. */

undefined4 FUN_0001ea48(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  switch(param_2) {
  default:
    uVar1 = 2;
    break;
  case 1:
    uVar1 = 3;
    break;
  case 2:
    uVar1 = 4;
    break;
  case 3:
    uVar1 = 8;
    break;
  case 4:
    uVar1 = 6;
    break;
  case 5:
    uVar1 = 5;
    break;
  case 6:
    uVar1 = 1;
    break;
  case 7:
    uVar1 = 10;
    break;
  case 8:
    uVar1 = 7;
    break;
  case 9:
    uVar1 = 0;
    break;
  case 10:
    uVar1 = 9;
    break;
  case 0xb:
    uVar1 = 0xe;
    break;
  case 0xc:
    uVar1 = 0xb;
    break;
  case 0xd:
    uVar1 = 0x19;
    break;
  case 0xe:
    uVar1 = 0x18;
    break;
  case 0xf:
    uVar1 = 0x1a;
    break;
  case 0x10:
    uVar1 = 0x1b;
    break;
  case 0x11:
    uVar1 = 0x14;
    break;
  case 0x12:
    uVar1 = 0xf;
    break;
  case 0x13:
    uVar1 = 0x10;
    break;
  case 0x15:
    uVar1 = 0x12;
    break;
  case 0x18:
    uVar1 = 0x13;
    break;
  case 0x19:
    uVar1 = 0x11;
    break;
  case 0x1a:
    uVar1 = 0xc;
    break;
  case 0x1b:
    uVar1 = 0x15;
    break;
  case 0x1c:
    uVar1 = 0x16;
    break;
  case 0x1d:
    uVar1 = 0x17;
    break;
  case 0x1e:
    uVar1 = 0xd;
    break;
  case 0x21:
    uVar1 = 0x1c;
  }
  return uVar1;
}



/* 0001ebb4 FUN_0001ebb4 */

/* Boundary evidence: original MIPS .pdata 0001ebb4..0001eefb. Semantic name remains unreviewed. */

undefined4 FUN_0001ebb4(int *param_1,char *param_2)

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
  
  local_30 = DAT_00055374;
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
        goto LAB_0001eeb8;
        uVar11 = sVar3 - 1 >> 1;
        iVar13 = 0;
        if (uVar11 != 0) {
          pcVar2 = local_70;
          do {
            pcVar2 = pcVar2 + 2;
            iVar4 = FUN_0001bf54(param_1,(int)pcVar2[-1]);
            iVar5 = FUN_0001bf54(param_1,(int)*pcVar2);
            iVar13 = (iVar4 * 0x10 + iVar5 + iVar13) * 0x1000000 >> 0x18;
            uVar11 = uVar11 - 1;
          } while (uVar11 != 0);
        }
        if (iVar13 != 0) goto LAB_0001eeb8;
        iVar13 = FUN_0001bf54(param_1,(int)local_70[1]);
        iVar4 = FUN_0001bf54(param_1,(int)local_70[2]);
        uVar11 = iVar13 * 0x10 + iVar4;
        iVar13 = FUN_0001bf54(param_1,(int)local_70[3]);
        iVar4 = FUN_0001bf54(param_1,(int)local_70[4]);
        iVar5 = FUN_0001bf54(param_1,(int)local_70[5]);
        iVar6 = FUN_0001bf54(param_1,(int)local_6a);
        iVar7 = FUN_0001bf54(param_1,(int)local_68);
        if (iVar7 == 0) {
          iVar4 = local_7c * 0x10 + ((iVar13 * 0x10 + iVar4) * 0x10 + iVar5) * 0x10 + iVar6 +
                  local_78[0];
          iVar13 = *param_1;
          uVar12 = 0;
          if (uVar11 != 0) {
            pcVar2 = local_67 + 1;
            do {
              iVar5 = FUN_0001bf54(param_1,(int)pcVar2[-1]);
              iVar6 = FUN_0001bf54(param_1,(int)*pcVar2);
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
LAB_0001eeb8:
            fclose(local_80);
            FUN_00043604(local_30);
            return uVar10;
          }
          if (iVar7 == 2) {
            local_67[uVar11 * 2] = '\0';
            local_70[uVar11 * 2 + 9 | 1] = '\0';
            piVar8 = &local_7c;
          }
          else {
            if (iVar7 != 3) {
              if ((iVar7 == 4) || (iVar7 == 5)) goto LAB_0001ee94;
              goto LAB_0001eeb8;
            }
            local_67[uVar11 * 2] = '\0';
            local_67[uVar11 * 2 + 1] = '\0';
            piVar8 = local_78;
          }
          sscanf_s(local_67,"%x",piVar8);
        }
LAB_0001ee94:
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
  FUN_00043604(local_30);
  return 0;
}



/* 0001eefc FUN_0001eefc */

/* Boundary evidence: original MIPS .pdata 0001eefc..0001efef. Semantic name remains unreviewed. */

undefined4 *
FUN_0001eefc(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  FUN_0002d7e0(param_1,param_2,param_3);
  *param_1 = &PTR_FUN_0004757c;
  *(undefined1 *)(param_1 + 5) = 0;
  param_1[9] = 0;
  memset(param_1 + 3,0,4);
  param_1[0xb] = 0;
  param_1[0xc] = 0;
  param_1[0xd] = 0;
  param_1[0xe] = 0;
  param_1[7] = 0;
  param_1[8] = 0;
  param_1[4] = param_4;
  param_1[10] = 0;
  param_1[0x14] = 0;
  param_1[0x16] = 0;
  param_1[0x17] = 1;
  param_1[0x18] = 0;
  param_1[0x1c] = 0;
  param_1[0x19] = 0;
  param_1[0x1a] = 2;
  param_1[0x1b] = 0;
  param_1[0x15] = 0;
  memset(param_1 + 0x1d,0,0x10);
  param_1[0x13] = 6;
  FUN_0002d814((int)param_1,500);
  param_1[0x24] = 0;
  param_1[0x25] = 0;
  param_1[0x21] = 0;
  param_1[0x22] = 0;
  return param_1;
}



/* 0001eff0 Unwind@0001eff0 */

/* Boundary evidence: original MIPS .pdata 0001eff0..0001f01f. Semantic name remains unreviewed. */

void Unwind_0001eff0(void)

{
  undefined4 *in_v0;
  
  FUN_0002d85c((undefined4 *)*in_v0);
  return;
}



/* 0001f020 FUN_0001f020 */

/* Boundary evidence: original MIPS .pdata 0001f020..0001f06b. Semantic name remains unreviewed. */

undefined4 * FUN_0001f020(undefined4 *param_1,uint param_2)

{
  FUN_0001bfbc(param_1);
  if ((param_2 & 1) != 0) {
    __3_YAXPAX_Z(param_1);
  }
  return param_1;
}



/* 0001f06c FUN_0001f06c */

/* Boundary evidence: original MIPS .pdata 0001f06c..00020503. Semantic name remains unreviewed. */

void FUN_0001f06c(int param_1,int param_2)

{
  uint uVar1;
  LSTATUS LVar2;
  uint uVar3;
  HANDLE pvVar4;
  size_t sVar5;
  HWND pHVar6;
  DWORD DVar7;
  BOOL BVar8;
  wchar_t *pwVar9;
  char cVar10;
  byte bVar11;
  uint *lpData;
  int iVar12;
  ushort *puVar13;
  int *lpData_00;
  int *lpData_01;
  wchar_t *lpSubKey;
  byte local_808 [4];
  HKEY local_804;
  char local_800;
  byte local_7ff;
  undefined1 local_7fe;
  byte local_7fd;
  char local_7fc;
  char local_7fb;
  byte local_7fa [2];
  BYTE aBStack_7f8 [4];
  undefined1 local_7f4;
  undefined1 local_7f3 [3];
  uint local_7f0;
  uint local_7ec;
  FILE *local_7e8;
  uint local_7e4;
  uint local_7e0;
  uint local_7dc;
  uint local_7d8;
  uint local_7d4;
  uint local_7d0;
  uint local_7cc;
  HKEY local_7c8;
  uint local_7c4;
  uint local_7c0;
  undefined4 local_7bc;
  uint local_7b8;
  uint local_7b4;
  uint local_7b0;
  HKEY local_7ac;
  uint local_7a8;
  uint local_7a4;
  uint local_7a0;
  BYTE local_79c [4];
  _PROCESS_INFORMATION local_798;
  undefined1 local_788;
  undefined1 auStack_787 [2];
  byte local_785;
  byte local_784;
  byte local_783;
  byte local_782;
  byte local_781;
  ushort local_780;
  byte local_77e;
  byte local_77d;
  _WIN32_FIND_DATAW _Stack_760;
  undefined1 local_510;
  WCHAR aWStack_508 [20];
  char acStack_4e0 [32];
  wchar_t awStack_4c0 [32];
  WCHAR aWStack_480 [32];
  wchar_t awStack_440 [260];
  wchar_t awStack_238 [260];
  uint local_30;
  
  local_30 = DAT_00055374;
  local_7fc = '\0';
  local_788 = 0;
  memset(auStack_787,0,2);
  memset(&local_785,0,0x21);
  puVar13 = (ushort *)(param_1 + 0x98);
  *puVar13 = *(ushort *)(param_2 + 4);
  *(undefined4 *)(param_1 + 0x4c) = 0;
  FUN_0002d83c(param_1);
  FUN_0001db78();
  lpData_00 = (int *)(param_1 + 0x90);
  uVar1 = FUN_00016068(DAT_000553cc,1,8,lpData_00,1,100);
  if ((uVar1 != 0) &&
     (NKDbgPrintfW(L"[PRODUCT PILOT TEST TOOL] VAL(%d)\n",*lpData_00), *lpData_00 != 0)) {
    FUN_0001e728();
  }
  lpData_01 = (int *)(param_1 + 0x94);
  uVar1 = FUN_00016068(DAT_000553cc,1,0xca,lpData_01,1,100);
  if (uVar1 != 0) {
    NKDbgPrintfW(L"[PRODUCT GUIDELINE TYPE] VAL(%d)\n",*lpData_01);
  }
  uVar1 = FUN_00016068(DAT_000553cc,1,0xd5,&local_7fe,1,0x96);
  if (uVar1 != 0) {
    NKDbgPrintfW(L"[HW REVISION] VAL(%d)\n",local_7fe);
  }
  if (DAT_00057c84 == '\x01') {
    *(undefined4 *)(param_1 + 0x2c) = 1;
    *puVar13 = *puVar13 | 0x10;
  }
  else {
    *(undefined4 *)(param_1 + 0x2c) = 3;
    *puVar13 = *puVar13 & 0xffef;
  }
  FUN_0001e8e8(param_1,&local_788);
  local_800 = '\0';
  uVar1 = FUN_00016068(DAT_000553cc,0,0x44,&local_800,1,100);
  if (uVar1 == 1) {
    *(char *)(*(int *)(param_1 + 0x10) + 0x687) = local_800;
    if (local_800 != '\0') {
      *(undefined4 *)(param_1 + 0x2c) = 1;
      *puVar13 = *puVar13 | 0x10;
    }
  }
  else {
    *(undefined1 *)(*(int *)(param_1 + 0x10) + 0x687) = 0;
  }
  NKDbgPrintfW(L"\r\n\r\npwr_state-%d, tempo_on-%d\r\n\r\n",*puVar13 >> 4 & 1,local_800);
  local_7fd = 0;
  lpSubKey = L"LGE\\SystemInfo";
  local_7d8 = 0;
  local_7e0 = 0;
  local_7b4 = 0;
  local_7e8 = (FILE *)0x46394;
  LVar2 = RegOpenKeyExW((HKEY)0x80000002,L"LGE\\SystemInfo",0,0,&local_804);
  if (LVar2 == 0) {
    local_7bc = 2;
    local_7b8 = 0;
    local_7b0 = 0;
    local_7c0 = 0;
    uVar1 = FUN_00016068(DAT_000553cc,1,0xc9,&local_7fd,1,0x96);
    if (uVar1 != 0) {
      memset(awStack_4c0,0,0x40);
      if (local_7fd < 0x28) {
        pwVar9 = (wchar_t *)(&PTR_u_ULC1_0_FEU__d__00054a94)[local_7fd];
      }
      else {
        pwVar9 = L"ULC1.x unknown(%d)";
      }
      _snwprintf(awStack_4c0,0x1f,pwVar9);
      local_7b4 = (uint)local_7fd;
      NKDbgPrintfW(L"[SKU REGION] (%s)\n",awStack_4c0);
    }
    local_808[0] = 0;
    uVar1 = FUN_00016068(DAT_000553cc,0xd,0xd,local_808,1,0xfa);
    if (uVar1 == 1) {
      NKDbgPrintfW(L"~~ OK Read boot logo type from Micom:[%d]\r\n",local_808[0]);
      local_7a4 = (uint)local_808[0];
      if (local_7a4 < 5) {
        FUN_0002fc28(local_808[0]);
        local_7a4 = (uint)local_808[0];
      }
    }
    else {
      NKDbgPrintfW(L"~~ Error Read boot logo type from Micom[%d] \r\n",local_808[0]);
      local_7a4 = (uint)local_782;
      local_808[0] = local_782;
    }
    if (4 < local_7a4) {
      local_7a4 = 0;
      local_808[0] = 0;
    }
    RegSetValueExW(local_804,L"BOOT_LOGO",0,4,(BYTE *)&local_7a4,4);
    local_7ff = 0;
    local_7cc = 0;
    local_7e4 = 0;
    local_7dc = 0;
    local_7d4 = 0;
    if (*lpData_00 == 0) {
      FUN_00016068(DAT_000553cc,1,0xcc,&local_7ff,1,0xfa);
    }
    else {
      FUN_00016068(DAT_000553cc,1,10,&local_7ff,1,0xfa);
    }
    lpData = (uint *)(param_1 + 0x84);
    *lpData = (uint)(local_7ff >> 7);
    local_7dc = local_7ff >> 5 & 1;
    local_7cc = local_7ff & 7;
    local_7e4 = local_7ff >> 3 & 3;
    local_7d4 = local_7ff >> 6 & 1;
    *(uint *)(param_1 + 0x88) = local_7e4;
    RegSetValueExW(local_804,L"HMI_ADAC_CNF",0,4,(BYTE *)&local_7cc,4);
    RegSetValueExW(local_804,L"HMI_TEMP_CNF",0,4,(BYTE *)&local_7e4,4);
    RegSetValueExW(local_804,L"HMI_AIR_CNF",0,4,(BYTE *)&local_7dc,4);
    RegSetValueExW(local_804,L"HMI_ENG_CNF",0,4,(BYTE *)&local_7d4,4);
    RegSetValueExW(local_804,L"HMI_ECO_CNF",0,4,(BYTE *)lpData,4);
    NKDbgPrintfW(L"Specific HMI[0x%02X] : [%d][%d][%d][%d][%d] \r\n",local_7ff,local_7cc,local_7e4,
                 local_7dc,local_7d4,*lpData);
    FUN_0001b60c(DAT_00055408,*lpData);
    FUN_00014edc(DAT_000553a8,local_7e4);
    FUN_000133dc(DAT_000553a8,(char)local_7e4,(char)local_7dc);
    *(uint *)(DAT_00055408 + 0x24) = (uint)(local_7d4 == 0);
    local_7d8 = (uint)(local_781 >> 6);
    local_7a0 = local_781 >> 2 & 1;
    local_7c0 = (uint)((local_781 & 1) == 0);
    local_7b8 = (uint)local_783;
    uVar1 = (uint)local_780;
    local_7e0 = (uint)local_784;
    local_7b0 = local_781 >> 1 & 1;
    local_7bc = FUN_0001ea48(param_1,(uint)local_785);
    local_7ec = (uint)((local_77e & 2) == 0);
    local_7f0 = (uint)((local_77e & 4) == 0);
    local_7c4 = (uint)((local_77d & 2) != 0);
    if (*lpData_00 != 0) {
      local_7fa[0] = 0;
      uVar3 = FUN_00016068(DAT_000553cc,1,9,local_7fa,1,100);
      if (uVar3 != 0) {
        local_7d8 = (uint)local_7fa[0];
        NKDbgPrintfW(L"[PRODUCT PILOT TEST TOOL UI_TYPE] VAL(%d)\n",local_7d8);
      }
    }
    uVar3 = FUN_00017c4c(DAT_000553dc);
    if (uVar3 != local_7d8) {
      FUN_00017c6c(DAT_000553dc,local_7d8);
    }
    memset(aWStack_508,0,0x28);
    if (*lpData_00 == 1) {
      uVar1 = 0x2a2a;
      NKDbgPrintfW(L"\n\n[Tool] Connect map code = %x\n\n",0x2a2a);
      FUN_0001d858();
    }
    else {
      NKDbgPrintfW(L"\n\n[Tool] disConnect map code = %x\n\n",uVar1);
    }
    iVar12 = 0;
    swprintf_s(awStack_440,0x104,L"\\Storage Card4\\NNG\\license\\LGe_Renault_ULC_13CY_Primo_*.*");
    swprintf_s(awStack_238,0x104,L"\\Storage Card4\\NNG\\license\\LGe_Renault_ULC_14CY_Primo_*.*");
    pvVar4 = FindFirstFileW(awStack_440,&_Stack_760);
    if (pvVar4 == (HANDLE)0xffffffff) {
      pvVar4 = FindFirstFileW(awStack_238,&_Stack_760);
      lpSubKey = (wchar_t *)local_7e8;
      if (pvVar4 != (HANDLE)0xffffffff) {
        wcsstr((wchar_t *)&_Stack_760.dwReserved1,L"13Q4");
        iVar12 = 2;
        FindClose(pvVar4);
        lpSubKey = (wchar_t *)local_7e8;
      }
    }
    else {
      iVar12 = 1;
      FindClose(pvVar4);
    }
    NKDbgPrintfW(L"\n\r\n\r ulMapIndex %d, %s\n\r\n\r",iVar12,&_Stack_760.dwReserved1);
    FUN_0001cd14(param_1,uVar1,aWStack_508,iVar12);
    sVar5 = wcslen(aWStack_508);
    RegSetValueExW(local_804,L"MAPCODE",0,1,(BYTE *)aWStack_508,(sVar5 + 1) * 2);
    RegSetValueExW(local_804,L"UI_TYPE",0,4,(BYTE *)&local_7d8,4);
    RegSetValueExW(local_804,L"NONAVI",0,4,(BYTE *)&local_7a0,4);
    RegSetValueExW(local_804,L"LANG_TYPE",0,4,(BYTE *)&local_7bc,4);
    RegSetValueExW(local_804,L"CLOCK_TYPE",0,4,(BYTE *)&local_7c0,4);
    RegSetValueExW(local_804,L"METER_TYPE",0,4,(BYTE *)&local_7b0,4);
    RegSetValueExW(local_804,L"SDVC_TYPE",0,4,(BYTE *)&local_7b8,4);
    local_7a8 = *puVar13 & 1;
    RegSetValueExW(local_804,L"FACTORY_TYPE",0,4,(BYTE *)&local_7a8,4);
    RegSetValueExW(local_804,L"RAD_CONTRY",0,4,(BYTE *)&local_7e0,4);
    RegSetValueExW(local_804,L"TOOL_CONNECTED",0,4,(BYTE *)lpData_00,4);
    if ((*lpData_00 != 0) && (*lpData_01 == 0)) {
      *lpData_01 = 1;
    }
    RegSetValueExW(local_804,L"GUIDELINE_TYPE",0,4,(BYTE *)lpData_01,4);
    FUN_00016068(DAT_000553cc,1,0xcd,aBStack_7f8,1,0xfa);
    RegSetValueExW(local_804,L"RVC_BRIGHTNESS",0,4,aBStack_7f8,4);
    FUN_00016068(DAT_000553cc,1,0xce,aBStack_7f8,1,0xfa);
    RegSetValueExW(local_804,L"RVC_CONTRAST",0,4,aBStack_7f8,4);
    FUN_00016068(DAT_000553cc,1,0xcf,aBStack_7f8,1,0xfa);
    RegSetValueExW(local_804,L"RVC_HUE",0,4,aBStack_7f8,4);
    FUN_00016068(DAT_000553cc,1,0xd0,aBStack_7f8,1,0xfa);
    RegSetValueExW(local_804,L"RVC_SATU",0,4,aBStack_7f8,4);
    FUN_00016068(DAT_000553cc,1,0xd1,aBStack_7f8,1,0xfa);
    RegSetValueExW(local_804,L"RVC_SATV",0,4,aBStack_7f8,4);
    FUN_00030fcc(1,&local_77e);
    NKDbgPrintfW(L"[RADIO SETTING]AM(MW)=%d, AM(LW)=%d, DR=%d\n",local_7ec,local_7f0,local_7c4);
    RegSetValueExW(local_804,L"AM_MW",0,4,(BYTE *)&local_7ec,4);
    RegSetValueExW(local_804,L"AM_LW",0,4,(BYTE *)&local_7f0,4);
    RegSetValueExW(local_804,L"DAB_EN",0,4,(BYTE *)&local_7c4,4);
    local_7d0 = (uint)((local_77d & 0x10) == 0);
    NKDbgPrintfW(L"[Rear Speaker Absence] REAR=%d\n");
    RegSetValueExW(local_804,L"REAR_SPK",0,4,(BYTE *)&local_7d0,4);
    if (local_7d0 == 0) {
      DAT_00057354 = DAT_00057354 & 0xfff01fff | 0x100000;
    }
    RegSetValueExW(local_804,L"SKU_REGION",0,4,(BYTE *)&local_7b4,4);
    if (local_7f0 == 1) {
      cVar10 = '\x02';
    }
    else {
      cVar10 = '\0';
    }
    cVar10 = (local_7ec == 1) + cVar10;
    if ((DAT_00054c94 != local_7e0) || (DAT_00054c95 != cVar10)) {
      NKDbgPrintfW(L"\r\n<=>[Rebuild Radio config] Country=%d, MW/LW=%d\r\n",(uint)DAT_00054c94,
                   local_7e0,DAT_00054c95,cVar10);
      DAT_00054c94 = (byte)local_7e0;
      DAT_00054c95 = cVar10;
      FUN_0002faf0();
    }
    FUN_00026894(DAT_00057130,local_7e0,(uint)(local_7f0 == 1),(uint)(local_7ec == 1));
    RegCloseKey(local_804);
  }
  if (DAT_00057c86 != '\0') {
    DAT_00057c86 = '\0';
    *puVar13 = ((ushort)DAT_00057c85 << 2 ^ *puVar13) & 4 ^ *puVar13;
    FUN_0003e4c8();
    FUN_0002f484();
  }
  if ((*puVar13 & 4) == 0) {
    FUN_00016068(DAT_000553cc,1,2,(void *)(*(int *)(param_1 + 0x10) + 0x683),4,0xfa);
    iVar12 = *(int *)(param_1 + 0x10);
    NKDbgPrintfW(L"~!@#$% 0x%02X, 0x%02X, 0x%02X, 0x%02X \r\n",*(undefined1 *)(iVar12 + 0x683),
                 *(undefined1 *)(iVar12 + 0x684),*(undefined1 *)(iVar12 + 0x685),
                 *(undefined1 *)(iVar12 + 0x686));
    if (*lpData_00 == 0) {
      FUN_0001c9d0(param_1);
      FUN_0001dd44();
    }
  }
  FUN_00015b90(DAT_000553cc,1,1,(int)puVar13,2,0x96);
  uVar1 = FUN_00016068(DAT_000553cc,9,0,&local_7fe,1,0x96);
  if (uVar1 == 1) {
    *(undefined1 *)(*(int *)(param_1 + 0x10) + 0x66d) = local_7fe;
  }
  else {
    *(undefined1 *)(*(int *)(param_1 + 0x10) + 0x66d) = 0;
  }
  local_7fb = '\0';
  FUN_00016068(DAT_000553cc,9,0x42,&local_7fb,1,0x96);
  iVar12 = *(int *)(param_1 + 0x10);
  if (local_7fb == '\0') {
    *(undefined4 *)(param_1 + 100) = 0;
    bVar11 = *(byte *)(iVar12 + 0x680) & 0xfd;
    pwVar9 = L"\n\n ========================== [ILL OFF] ========================== \n\n";
  }
  else {
    *(undefined4 *)(param_1 + 100) = 1;
    bVar11 = *(byte *)(iVar12 + 0x680) | 2;
    pwVar9 = L"\n\n ========================== [ILL ON] ===========================] \n\n";
  }
  *(byte *)(iVar12 + 0x680) = bVar11;
  NKDbgPrintfW(pwVar9);
  pHVar6 = FindWindowW(L"AppMain",(LPCWSTR)0x0);
  if (pHVar6 == (HWND)0x0) {
    memset(_Stack_760.cFileName + 0x102,0,0x10);
    FUN_00016068(DAT_000553cc,1,4,_Stack_760.cFileName + 0x102,0xf,0x32);
    _Stack_760.cAlternateFileName[5]._1_1_ = 0x31;
    LVar2 = RegOpenKeyExW((HKEY)0x80000002,lpSubKey,0,0,&local_7c8);
    if (LVar2 == 0) {
      RegSetValueExW(local_7c8,L"UUID",0,3,(BYTE *)(_Stack_760.cFileName + 0x102),0x10);
      local_79c[0] = '\0';
      local_79c[1] = '\0';
      local_79c[2] = '\0';
      local_79c[3] = '\0';
      RegSetValueExW(local_7c8,L"TEST_MODE",0,4,local_79c,4);
      RegCloseKey(local_7c8);
    }
    iVar12 = 0;
    do {
      if (DAT_00054be0 == 0) break;
      Sleep(100);
      iVar12 = iVar12 + 1;
    } while (iVar12 < 0x1e);
    Sleep(1000);
    pvVar4 = CreateFileW(L"\\Storage Card4\\NNG\\license\\device.nng",0x80000000,0,
                         (LPSECURITY_ATTRIBUTES)0x0,3,0x80,(HANDLE)0x0);
    if (pvVar4 != (HANDLE)0xffffffff) {
      DVar7 = GetFileSize(pvVar4,(LPDWORD)0x0);
      CloseHandle(pvVar4);
      NKDbgPrintfW(L"\r\n file name[%s][%d]\r\n",L"\\Storage Card4\\NNG\\license\\device.nng",DVar7)
      ;
      if (DVar7 == 0) {
        iVar12 = FUN_0002ee5c(L"\\Storage Card\\device.nng");
        if (iVar12 == 2) {
          DeleteFileW(L"\\Storage Card\\device.nng");
        }
        DeleteFileW(L"\\Storage Card4\\NNG\\license\\device.nng");
      }
    }
    BVar8 = CreateProcessW(L"\\Storage Card\\system\\AppMain.exe",L"(bd9r2a@_4G2g=1.5_J2tq7X@app",
                           (LPSECURITY_ATTRIBUTES)0x0,(LPSECURITY_ATTRIBUTES)0x0,0,0,(LPVOID)0x0,
                           (LPCWSTR)0x0,(LPSTARTUPINFOW)0x0,(LPPROCESS_INFORMATION)(param_1 + 0x74))
    ;
    if (BVar8 == 0) {
      DVar7 = GetLastError();
      NKDbgPrintfW(L"\r\n[%s(%d) - %s] AppMain.exe did not excute!!, err code = &d \r\n",
                   ".\\Micom.cpp",0x39c,"CMicom::OnCmdAppBootStatNoti",DVar7);
    }
    DVar7 = GetFileAttributesW(L"\\Storage Card\\ATSA.exe");
    if ((DVar7 != 0xffffffff) &&
       (BVar8 = CreateProcessW(L"\\Storage Card\\ATSA.exe",L"",(LPSECURITY_ATTRIBUTES)0x0,
                               (LPSECURITY_ATTRIBUTES)0x0,0,0,(LPVOID)0x0,(LPCWSTR)0x0,
                               (LPSTARTUPINFOW)0x0,&local_798), BVar8 != 0)) {
      if (local_798.hProcess != (HANDLE)0x0) {
        CloseHandle(local_798.hProcess);
      }
      if (local_798.hThread != (HANDLE)0x0) {
        CloseHandle(local_798.hThread);
      }
    }
  }
  FUN_00016068(DAT_000553cc,9,1,&local_7fc,1,0x96);
  if (local_7fc == '\0') {
    *(undefined4 *)(param_1 + 0x1c) = 0;
  }
  else {
    *(undefined4 *)(param_1 + 0x1c) = 1;
  }
  FUN_0002d6b0(DAT_00057130);
  if (*(int *)(param_1 + 0x2c) == 1) {
    *(undefined1 *)(*(int *)(param_1 + 0x10) + 0x688) = 0;
    FUN_00016c74(DAT_000553dc);
    Sleep(100);
    FUN_000339cc(0x3030105,0);
    FUN_00033908(0x72,0);
    if (*(int *)(param_1 + 0x50) != 0) goto LAB_000203cc;
    local_7f4 = 0;
    FUN_00015f10(DAT_000553cc,1,1,1,(int)&local_7f4,1,100);
    pwVar9 = L"\r\n~(1)~PWRSTATE_NORMAL unmuted\r\n";
  }
  else {
    if (*(int *)(param_1 + 0x2c) != 3) goto LAB_000203cc;
    *(undefined1 *)(*(int *)(param_1 + 0x10) + 0x688) = 1;
    FUN_00033908(0x71,0);
    FUN_000339cc(0x3030104,0);
    FUN_00016e7c(DAT_000553dc);
    if (*(int *)(param_1 + 0x50) != 0) goto LAB_000203cc;
    local_7f3[0] = 1;
    FUN_00015f10(DAT_000553cc,1,1,1,(int)local_7f3,1,100);
    pwVar9 = L"\r\n~(2)~PWRSTATE_OFF muted\r\n";
  }
  NKDbgPrintfW(pwVar9);
LAB_000203cc:
  FUN_0001c398(param_1);
  local_7e8 = (FILE *)0x0;
  FUN_00016068(DAT_000553cc,1,0,_Stack_760.cAlternateFileName + 6,0x10,0x96);
  local_510 = 0;
  sprintf_s(acStack_4e0,0x20,"\\mcm %s.ver",_Stack_760.cAlternateFileName + 6);
  fopen_s(&local_7e8,acStack_4e0,"wt");
  if (local_7e8 != (FILE *)0x0) {
    fclose(local_7e8);
  }
  LVar2 = RegOpenKeyExW((HKEY)0x80000002,lpSubKey,0,0,&local_7ac);
  if (LVar2 == 0) {
    wsprintfW(aWStack_480,L"%S",_Stack_760.cAlternateFileName + 6);
    sVar5 = wcslen(aWStack_480);
    RegSetValueExW(local_7ac,L"VerMicomFW",0,1,(BYTE *)aWStack_480,sVar5 << 1);
    RegCloseKey(local_7ac);
  }
  FUN_0001c8ec(param_1);
  FUN_00043604(local_30);
  return;
}



/* 00020504 FUN_00020504 */

/* Boundary evidence: original MIPS .pdata 00020504..000206af. Semantic name remains unreviewed. */

void FUN_00020504(void)

{
  int iVar1;
  
  iVar1 = FUN_0002ee5c(L"\\Storage Card2\\GudieLineData.bin");
  if (iVar1 == 2) {
    DeleteFileW(L"\\Storage Card2\\GudieLineData.bin");
  }
  iVar1 = FUN_0002ee5c(L"\\Storage Card2\\RvcData.bin");
  if (iVar1 == 2) {
    DeleteFileW(L"\\Storage Card2\\RvcData.bin");
  }
  iVar1 = FUN_0002ee5c(L"\\Storage Card2\\GuideData.bin");
  if (iVar1 == 2) {
    DeleteFileW(L"\\Storage Card2\\GuideData.bin");
  }
  iVar1 = FUN_0002ee5c(L"\\Storage Card2\\RVC_CFG_PARAM.DAT");
  if (iVar1 == 2) {
    DeleteFileW(L"\\Storage Card2\\RVC_CFG_PARAM.DAT");
  }
  iVar1 = FUN_0002ee5c(L"\\Storage Card2\\MgrSys.cfg");
  if (iVar1 == 2) {
    DeleteFileW(L"\\Storage Card2\\MgrSys.cfg");
  }
  iVar1 = FUN_0002ee5c(L"\\Storage Card2\\stationlist.cfg");
  if (iVar1 == 2) {
    DeleteFileW(L"\\Storage Card2\\stationlist.cfg");
  }
  iVar1 = FUN_0002ee5c(L"\\Storage Card2\\stationorder.cfg");
  if (iVar1 == 2) {
    DeleteFileW(L"\\Storage Card2\\stationorder.cfg");
  }
  iVar1 = FUN_0002ee5c(L"\\Storage Card\\device.nng");
  if (iVar1 == 2) {
    DeleteFileW(L"\\Storage Card\\device.nng");
  }
  iVar1 = FUN_0002ee5c(L"\\Storage Card4\\NNG\\license\\device.nng");
  if (iVar1 == 2) {
    DeleteFileW(L"\\Storage Card4\\NNG\\license\\device.nng");
  }
  iVar1 = FUN_0002ee5c(L"\\Storage card2\\pwr_count.bin");
  if (iVar1 == 2) {
    DeleteFileW(L"\\Storage card2\\pwr_count.bin");
  }
  FUN_0001c030();
  return;
}



/* 000206b0 FUN_000206b0 */

/* Boundary evidence: original MIPS .pdata 000206b0..000207df. Semantic name remains unreviewed. */

void FUN_000206b0(int param_1,int param_2)

{
  byte local_18 [8];
  
  if (*(int *)(param_1 + 0x2c) != param_2) {
    if ((*(int *)(param_1 + 0x2c) == 3) && (DAT_00055384 != 0)) {
      FUN_0001211c(DAT_00055384,1);
    }
    if ((*(int *)(param_1 + 0x88) != 0) || (*(int *)(param_1 + 0x84) != 0)) {
      local_18[0] = 0;
      FUN_00016068(DAT_000553cc,0,0x44,local_18,1,100);
      if (local_18[0] != *(byte *)(*(int *)(param_1 + 0x10) + 0x687)) {
        *(byte *)(*(int *)(param_1 + 0x10) + 0x687) = local_18[0];
        if (*(int *)(param_1 + 0x84) != 0) {
          FUN_0001b8c0(DAT_00055408,(uint)local_18[0]);
        }
        if (*(int *)(param_1 + 0x88) != 0) {
          FUN_00014e4c(DAT_000553a8,(uint)local_18[0]);
        }
        if ((*(int *)(param_1 + 0x88) != 0) || (*(int *)(param_1 + 0x84) != 0)) {
          FUN_000338ac(0xcd,(uint)local_18[0]);
        }
      }
    }
    *(int *)(param_1 + 0x2c) = param_2;
    FUN_0001c398(param_1);
  }
  return;
}



/* 000207e0 FUN_000207e0 */

/* Boundary evidence: original MIPS .pdata 000207e0..000207fb. Semantic name remains unreviewed. */

void FUN_000207e0(int param_1)

{
  FUN_000206b0(param_1,3);
  return;
}



/* 000207fc FUN_000207fc */

/* Boundary evidence: original MIPS .pdata 000207fc..0002097b. Semantic name remains unreviewed. */

void FUN_000207fc(int param_1,void *param_2,size_t param_3)

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
  else if (*(int *)(param_1 + 0x90) == 1) {
    pwVar3 = L"[SaveDTCTable]Tool connected!!! Not saved DTC!!\n";
  }
  else {
    _Dst = (void *)__2_YAPAXI_Z(param_3);
    if (_Dst != (void *)0x0) {
      memset(_Dst,0x10,param_3);
      FUN_0001d8c0(param_1,_Dst,param_3);
      iVar1 = memcmp(_Dst,param_2,param_3);
      __3_YAXPAX_Z(_Dst);
      if (iVar1 == 0) {
        return;
      }
    }
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



/* 0002097c FUN_0002097c */

/* Boundary evidence: original MIPS .pdata 0002097c..00021e37. Semantic name remains unreviewed. */

void FUN_0002097c(double param_1,int param_2,uint *param_3)

{
  char cVar1;
  byte bVar2;
  HANDLE pvVar3;
  BOOL BVar4;
  DWORD DVar5;
  byte *_Dst;
  HANDLE hFile;
  void *_Dst_00;
  HWND hWnd;
  wchar_t *pwVar6;
  int iVar7;
  UINT UVar8;
  int iVar9;
  code *pcVar10;
  uint uVar11;
  byte local_38 [2];
  char local_36;
  undefined1 local_35;
  DWORD local_34;
  DWORD aDStack_30 [2];
  
  uVar11 = *param_3 >> 8 & 0xf;
  if (uVar11 != 2) {
    if (uVar11 != 3) {
      if (uVar11 != 0xf) {
        return;
      }
      cVar1 = *(char *)((int)param_3 + 2);
      if (cVar1 == '\0') {
        if (DAT_000553dc == 0) {
          return;
        }
        iVar9 = 0;
LAB_00020a38:
        FUN_00017328(DAT_000553dc,iVar9,(uint)(byte)param_3[1]);
        return;
      }
      if (cVar1 == '\x01') {
        if (DAT_000553dc == 0) {
          return;
        }
        iVar9 = 1;
        goto LAB_00020a38;
      }
      if (cVar1 != '\x02') {
        return;
      }
      *(undefined4 *)(param_2 + 0x4c) = 7;
      UVar8 = 1000;
      goto LAB_00020c50;
    }
    cVar1 = *(char *)((int)param_3 + 2);
    if (cVar1 == ' ') {
      if ((*(int *)(param_2 + 0x50) != 1) && ((*(ushort *)(param_2 + 0x98) & 4) != 0)) {
        if (*(int *)(param_2 + 0x34) != 0) {
          return;
        }
        if (*(int *)(param_2 + 0x30) != 0) {
          return;
        }
        FUN_000338ac(0x77,0);
        FUN_0001b420(DAT_00055408);
        *(undefined4 *)(param_2 + 0x30) = 1;
        FUN_0001c398(param_2);
        *(undefined4 *)(param_2 + 0x4c) = 1;
        FUN_0002d814(param_2,10000);
        FUN_0003e4c8();
        FUN_0002f484();
        return;
      }
      *(undefined4 *)(param_2 + 0x30) = 1;
      *(undefined4 *)(param_2 + 0x34) = 1;
    }
    else {
      if (cVar1 == '!') {
        if (*(int *)(param_2 + 0x34) != 0) {
          return;
        }
        if (*(int *)(param_2 + 0x30) != 1) {
          return;
        }
        *(undefined4 *)(param_2 + 0x30) = 0;
        FUN_0001c398(param_2);
        *(undefined4 *)(param_2 + 0x4c) = 0;
        FUN_0002d83c(param_2);
        FUN_00015f10(DAT_000553cc,0,1,0x10,0,0,0x32);
        return;
      }
      if (cVar1 != '\"') {
        if (cVar1 != '#') {
          return;
        }
        if ((char)param_3[1] == '\0') {
          *(undefined4 *)(param_2 + 0x38) = 0;
        }
        else {
          *(undefined4 *)(param_2 + 0x38) = 1;
        }
        goto LAB_00020a94;
      }
LAB_00020c28:
      *(undefined4 *)(param_2 + 0x30) = 1;
      *(undefined4 *)(param_2 + 0x34) = 1;
      FUN_0001c398(param_2);
    }
    FUN_000338ac(0x79,0);
    *(undefined4 *)(param_2 + 0x54) = 0;
    *(undefined4 *)(param_2 + 0x4c) = 2;
    UVar8 = 5000;
LAB_00020c50:
    FUN_0002d814(param_2,UVar8);
    return;
  }
  bVar2 = *(byte *)((int)param_3 + 2);
  if (bVar2 < 0x32) {
    if (bVar2 == 0x31) {
      if (*(uint *)(param_2 + 0x1c) != (uint)(byte)param_3[1]) {
        if ((byte)param_3[1] == 0) {
          *(undefined4 *)(param_2 + 0x1c) = 0;
        }
        else {
          *(undefined4 *)(param_2 + 0x1c) = 1;
        }
        NKDbgPrintfW(L"[INFO][%d] Rear gear detection %d\r\n",*(undefined4 *)(param_2 + 0x5c),
                     *(undefined4 *)(param_2 + 0x1c));
        if ((*(int *)(param_2 + 0x5c) != 0) && (*(int *)(param_2 + 0x1c) != 0)) {
          DAT_000554a8 = 1;
          return;
        }
LAB_00020a94:
        FUN_0001c398(param_2);
        return;
      }
      pwVar6 = L"~!@#$ Gear detect !!!! Oh~~~~ My god!!!!!\r\n";
    }
    else if (bVar2 < 0xb) {
      if (bVar2 == 10) {
        cVar1 = *(char *)((int)param_3 + 5);
        if (cVar1 == '\0') {
          FUN_0002fdc0(param_3 + 2,(byte)param_3[1] + 0xfd & 0xff);
          FUN_00030244();
          pwVar6 = L"\\Storage Card2\\EcoDrive.cfg";
          pcVar10 = DeleteFileW_exref;
        }
        else {
          if (cVar1 != '\x01') {
            if (cVar1 != '\x02') {
              if (cVar1 == '\x03') {
                uVar11 = (uint)(byte)param_3[1];
                NKDbgPrintfW(L"\n ---< DTC Table >--- \n");
                iVar9 = 0;
                if (uVar11 != 0) {
                  do {
                    NKDbgPrintfW(L"[%d]0x%X ",iVar9,*(undefined1 *)(iVar9 + (int)(param_3 + 2)));
                    iVar9 = iVar9 + 1;
                  } while (iVar9 < (int)uVar11);
                }
                NKDbgPrintfW(&DAT_0004b190);
                FUN_000207fc(param_2,param_3 + 2,uVar11);
              }
              goto LAB_00021364;
            }
            pvVar3 = CreateFileW(L"\\Storage Card\\system\\DSI_EC_config.bsd",0xc0000000,0,
                                 (LPSECURITY_ATTRIBUTES)0x0,3,0x80,(HANDLE)0x0);
            if (pvVar3 == (HANDLE)0xffffffff) {
              NKDbgPrintfW(L"File open error - DSI_EC_config.bsd");
            }
            else {
              SetFilePointer(pvVar3,0,(PLONG)0x0,2);
              BVar4 = WriteFile(pvVar3,param_3 + 2,(byte)param_3[1] - 3,aDStack_30,(LPOVERLAPPED)0x0
                               );
              if (BVar4 == 0) {
                DVar5 = GetLastError();
                NKDbgPrintfW(L"Write Error - DSI_EC_config.bsd [err=%d]\n",DVar5);
              }
              SetEndOfFile(pvVar3);
              CloseHandle(pvVar3);
            }
            if (*(byte *)((int)param_3 + 6) + 1 < (uint)*(byte *)((int)param_3 + 7))
            goto LAB_00021364;
            _Dst = malloc(2000);
            if (_Dst == (byte *)0x0) {
              pwVar6 = L"[EC bsd write] Memory allocation Fileure!!\n";
              goto LAB_00021320;
            }
            memset(_Dst,0,2000);
            pvVar3 = CreateFileW(L"\\Storage Card\\system\\DSI_EC_config.bsd",0x80000000,0,
                                 (LPSECURITY_ATTRIBUTES)0x0,3,0x80,(HANDLE)0x0);
            if (pvVar3 != (HANDLE)0xffffffff) {
              BVar4 = ReadFile(pvVar3,_Dst,0x648,&local_34,(LPOVERLAPPED)0x0);
              if (BVar4 == 0) {
                DVar5 = GetLastError();
                pwVar6 = L"Read Error - DSI_EC_config.bsd [err=%d]\n";
LAB_00021210:
                NKDbgPrintfW(pwVar6,DVar5);
              }
              else {
                uVar11 = (uint)*_Dst * 0x100 + (uint)_Dst[1];
                if (uVar11 < 0x647) {
                  if (uVar11 != 0) {
                    hFile = CreateFileW(L"\\Storage Card\\system\\EC_config.bsd",0x40000000,0,
                                        (LPSECURITY_ATTRIBUTES)0x0,2,0x80,(HANDLE)0x0);
                    if (hFile == (HANDLE)0xffffffff) {
                      DVar5 = GetLastError();
                      pwVar6 = L"File open error - EC_config.bsd [err=%d]\n";
                      goto LAB_00021210;
                    }
                    NKDbgPrintfW(L"MOVE to EC bsd file (packet Sz=%d, FileSz=%d)\n",uVar11,local_34)
                    ;
                    BVar4 = WriteFile(hFile,_Dst + 2,uVar11,aDStack_30,(LPOVERLAPPED)0x0);
                    if (BVar4 == 0) {
                      DVar5 = GetLastError();
                      NKDbgPrintfW(L"Write Error - EC_config.bsd (err=%d)\n",DVar5);
                    }
                    CloseHandle(hFile);
                    goto LAB_00021218;
                  }
                  pwVar6 = 
                  L"Cancel to write - Wrong size(size=0) in first word of DSI_EC_config.bsd..\n";
                }
                else {
                  pwVar6 = 
                  L"Cancel to write - EC_config.bsd because data in DSI_EC_config.bsd are initailized..\n"
                  ;
                }
                NKDbgPrintfW(pwVar6);
              }
LAB_00021218:
              CloseHandle(pvVar3);
            }
            free(_Dst);
            goto LAB_00021364;
          }
          DVar5 = 2;
          if (*(char *)((int)param_3 + 6) != '\0') {
            DVar5 = 3;
          }
          pwVar6 = CreateFileW(L"\\Storage Card\\system\\DSI_EC_config.bsd",0xc0000000,0,
                               (LPSECURITY_ATTRIBUTES)0x0,DVar5,0x80,(HANDLE)0x0);
          if (pwVar6 == (wchar_t *)0xffffffff) {
            pwVar6 = L"File open error - DSI_EC_config.bsd";
LAB_00021320:
            NKDbgPrintfW(pwVar6);
            goto LAB_00021364;
          }
          if (*(char *)((int)param_3 + 6) != '\0') {
            SetFilePointer(pwVar6,0,(PLONG)0x0,2);
          }
          BVar4 = WriteFile(pwVar6,param_3 + 2,(byte)param_3[1] - 3,aDStack_30,(LPOVERLAPPED)0x0);
          pcVar10 = CloseHandle_exref;
          if (BVar4 == 0) {
            DVar5 = GetLastError();
            NKDbgPrintfW(L"Write Error - DSI_EC_config.bsd [err=%d]\n",DVar5);
            pcVar10 = CloseHandle_exref;
          }
        }
        (*pcVar10)(pwVar6);
LAB_00021364:
        if (*(byte *)((int)param_3 + 6) + 1 < (uint)*(byte *)((int)param_3 + 7)) {
          local_36 = *(char *)((int)param_3 + 5);
          uVar11 = *(byte *)((int)param_3 + 6) + 1 & 0xff;
        }
        else {
          local_36 = *(char *)((int)param_3 + 5) + '\x01';
          uVar11 = 0;
        }
        local_35 = (undefined1)uVar11;
        NKDbgPrintfW(L"[^^To Micom^^]CMD_APP_CAN_CONF (index=%d, %d)\n",local_36,uVar11);
        FUN_00015f10(DAT_000553cc,1,1,10,(int)&local_36,2,100);
        return;
      }
      if (bVar2 == 0) {
        if (*(int *)(param_2 + 0x2c) != 0) {
          return;
        }
        FUN_0001f06c(param_2,(int)param_3);
        return;
      }
      if (bVar2 == 1) {
        FUN_00015f10(DAT_000553cc,0,1,0x10,0,0,0x32);
        if ((*(int *)(param_2 + 0x34) == 0) && (*(int *)(param_2 + 0x30) == 1)) {
          *(undefined4 *)(param_2 + 0x4c) = 0;
          FUN_0002d83c(param_2);
          *(undefined4 *)(param_2 + 0x30) = 0;
          *(undefined4 *)(param_2 + 0x58) = 0;
          SetTimer(*(HWND *)(param_2 + 4),0x70a,400,(TIMERPROC)0x0);
        }
        else if ((*(int *)(param_2 + 0x88) != 0) || (*(int *)(param_2 + 0x84) != 0)) {
          local_38[0] = 0;
          FUN_00016068(DAT_000553cc,0,0x44,local_38,1,100);
          if (local_38[0] != *(byte *)(*(int *)(param_2 + 0x10) + 0x687)) {
            *(byte *)(*(int *)(param_2 + 0x10) + 0x687) = local_38[0];
            if (*(int *)(param_2 + 0x84) != 0) {
              FUN_0001b8c0(DAT_00055408,(uint)local_38[0]);
            }
            if (*(int *)(param_2 + 0x88) != 0) {
              FUN_00014e4c(DAT_000553a8,(uint)local_38[0]);
            }
            if ((*(int *)(param_2 + 0x88) != 0) || (*(int *)(param_2 + 0x84) != 0)) {
              FUN_000338ac(0xcd,(uint)local_38[0]);
            }
          }
        }
        PostMessageW((HWND)0xffff,DAT_000554b4,0,0);
        return;
      }
      if (bVar2 != 2) {
        if (bVar2 != 3) {
          return;
        }
        PostMessageW((HWND)0xffff,DAT_000554b4,0,1);
        goto LAB_00020c28;
      }
      NKDbgPrintfW(L"\r\nACC OFF - lock : 0x%x, timerID : 0x%x\r\n",*(undefined4 *)(param_2 + 0x50),
                   *(undefined4 *)(param_2 + 0x4c));
      PostMessageW((HWND)0xffff,DAT_000554b4,0,1);
      KillTimer(*(HWND *)(param_2 + 4),0x70a);
      FUN_00015f10(DAT_000553cc,0,1,0x11,0,0,0x32);
      if (*(int *)(param_2 + 0x60) != 1) {
        if ((*(int *)(param_2 + 0x34) == 0) && (*(int *)(param_2 + 0x30) == 0)) {
          FUN_000338ac(0x77,0);
          FUN_0001b420(DAT_00055408);
          *(undefined4 *)(param_2 + 0x30) = 1;
          FUN_0001c398(param_2);
          if (*(int *)(param_2 + 0x58) == 0) {
            UVar8 = 10000;
          }
          else {
            NKDbgPrintfW(L"~~~~~ GOTO SLEEP!!!!! \r\n");
            UVar8 = 0x9c4;
          }
          *(undefined4 *)(param_2 + 0x4c) = 1;
          FUN_0002d814(param_2,UVar8);
        }
        FUN_0001da14();
        return;
      }
      pwVar6 = L"\r\n~!@#$ NOTI_APP_ACC_OFF detected!!!!!!! \r\n";
    }
    else {
      if (bVar2 != 0x20) {
        if (bVar2 == 0x21) {
          cVar1 = (char)param_3[1];
          if (cVar1 == '\0') {
            *(undefined4 *)(param_2 + 0x3c) = 1;
            NKDbgPrintfW(L"===========================================\n");
            NKDbgPrintfW(L"======  START CONFIGURATION DISPLAY  ======\n");
            NKDbgPrintfW(L"===========================================\n");
            DAT_000553e0 = 1;
            FUN_00017028(DAT_000553dc);
            KillTimer(*(HWND *)(param_2 + 4),2);
          }
          else {
            if (cVar1 == '\x01') {
              *(undefined4 *)(param_2 + 0x3c) = 0;
              DAT_000553e0 = 2;
              FUN_00017028(DAT_000553dc);
              NKDbgPrintfW(L"===========================================\n");
              NKDbgPrintfW(L"======     COMPLETE CONFIGURATION    ======\n");
              NKDbgPrintfW(L"===========================================\n");
              local_36 = '\x04';
              FUN_00015f10(DAT_000553cc,1,1,8,(int)&local_36,1,0x32);
              return;
            }
            if (cVar1 != '\x02') {
              return;
            }
            *(undefined4 *)(param_2 + 0x3c) = 1;
            NKDbgPrintfW(L"===========================================\n");
            NKDbgPrintfW(L"======     CONNECTED TOOL DISPLAY    ======\n");
            NKDbgPrintfW(L"===========================================\n");
            DAT_000553e0 = 0;
            FUN_00017028(DAT_000553dc);
          }
          FUN_00020504();
          return;
        }
        if (bVar2 != 0x30) {
          return;
        }
        iVar9 = 0;
        if ((char)param_3[1] == '\0') {
          iVar7 = 0x74;
          *(undefined1 *)(*(int *)(param_2 + 0x10) + 0x66d) = 0;
        }
        else {
          iVar7 = 0x73;
          *(undefined1 *)(*(int *)(param_2 + 0x10) + 0x66d) = 1;
        }
        goto LAB_00021db4;
      }
      NKDbgPrintfW(L"%s - button : %d \r\n","CMicom::OnCommand",(char)param_3[1]);
      uVar11 = (uint)(byte)param_3[1];
      if (uVar11 == 0) {
        if (((*(int *)(param_2 + 0x30) == 0) && (*(int *)(param_2 + 0x50) == 0)) &&
           (*(int *)(param_2 + 0x5c) == 0)) {
          iVar9 = *(int *)(param_2 + 0x2c);
          if (iVar9 == 1) {
            local_38[0] = 0;
            uVar11 = FUN_00016068(DAT_000553cc,0,0x44,local_38,1,100);
            if (uVar11 == 1) {
              if (local_38[0] == 0) {
                *(ushort *)(param_2 + 0x98) = *(ushort *)(param_2 + 0x98) & 0xffef;
                iVar9 = 3;
              }
              else {
                *(undefined4 *)(param_2 + 0x4c) = 0;
                FUN_0002d83c(param_2);
                iVar9 = 1;
                *(ushort *)(param_2 + 0x98) = *(ushort *)(param_2 + 0x98) | 0x10;
              }
              FUN_000206b0(param_2,iVar9);
            }
          }
          else if (iVar9 == 2) {
            FUN_0003e9ec(0);
          }
          else if (iVar9 == 3) {
            *(ushort *)(param_2 + 0x98) = *(ushort *)(param_2 + 0x98) | 0x10;
            FUN_000206b0(param_2,1);
            FUN_00011500(DAT_00055384,1,0);
          }
        }
        FUN_00015b90(DAT_000553cc,1,1,param_2 + 0x98,2,0x96);
        FUN_0003e4c8();
        FUN_0002f484();
        if (*(int *)(param_2 + 0x90) == 0) {
          FUN_0001c9d0(param_2);
        }
      }
      else if (((1 < uVar11) && (uVar11 < 4)) && (*(int *)(param_2 + 0x2c) == 2)) {
        FUN_0003e9ec(uVar11);
      }
      iVar9 = FUN_0001c860(param_2);
      if (iVar9 != 1) {
        return;
      }
      iVar9 = FUN_00011e38(DAT_00055384);
      if ((iVar9 == 9) && (iVar9 = FUN_00011e40(DAT_00055384), iVar9 == 1)) {
        return;
      }
      switch((char)param_3[1]) {
      case '\a':
        FUN_000338ac(0x76,5);
        pwVar6 = L"MGRMCM : Send IDM_MMCM_AMAIN_KEY_EVENT(KEYEVT_VALID)\r\n";
        break;
      case '\b':
        FUN_000338ac(0x76,3);
        pwVar6 = L"MGRMCM : Send IDM_MMCM_AMAIN_KEY_EVENT(KEYEVT_MEDIA)\r\n";
        break;
      case '\t':
        FUN_000338ac(0x76,0);
        pwVar6 = L"MGRMCM : Send IDM_MMCM_AMAIN_KEY_EVENT(KEYEVT_TEL)\r\n";
        break;
      case '\n':
        FUN_000338ac(0x76,7);
        pwVar6 = L"MGRMCM : Send IDM_MMCM_AMAIN_KEY_EVENT(KEYEVT_PREV)\r\n";
        break;
      case '\v':
        FUN_000338ac(0x76,6);
        pwVar6 = L"MGRMCM : Send IDM_MMCM_AMAIN_KEY_EVENT(KEYEVT_NEXT)\r\n";
        break;
      case '\f':
        FUN_000338ac(0x76,1);
        pwVar6 = L"MGRMCM : Send IDM_MMCM_AMAIN_KEY_EVENT(KEYEVT_TEL_LONG)\r\n";
        break;
      case '\r':
        FUN_000338ac(0x76,8);
        pwVar6 = L"MGRMCM : Send IDM_MMCM_AMAIN_KEY_EVENT(_KEYEVT_RADIO_)\r\n";
        break;
      case '\x0e':
        FUN_000338ac(0x76,9);
        pwVar6 = L"MGRMCM : Send IDM_MMCM_AMAIN_KEY_EVENT(_KEYEVT_MEDIA_)\r\n";
        break;
      default:
        goto switchD_00021774_default;
      }
    }
  }
  else {
    if (bVar2 == 0x33) {
      uVar11 = param_3[1];
      *(uint *)(param_2 + 100) = (uint)(byte)uVar11;
      if ((byte)uVar11 == 1) {
        *(byte *)(*(int *)(param_2 + 0x10) + 0x680) =
             *(byte *)(*(int *)(param_2 + 0x10) + 0x680) | 2;
      }
      else {
        *(byte *)(*(int *)(param_2 + 0x10) + 0x680) =
             *(byte *)(*(int *)(param_2 + 0x10) + 0x680) & 0xfd;
      }
      FUN_00033908(0x80,0);
      FUN_0001c8ec(param_2);
      return;
    }
    if (bVar2 == 0x34) {
      local_38[0] = 0;
      iVar9 = FUN_00040840(param_1);
      NKDbgPrintfW(L"\r\n~!@#$ NOTI_APP_TEMP_OVER [0x%02X, 0x%02X] [%d]\r\n",(char)param_3[1],
                   *(undefined1 *)((int)param_3 + 5),iVar9);
      if (iVar9 < 0x78) {
        local_36 = '\x05';
        FUN_00015f10(DAT_000553cc,5,1,0x12,(int)&local_36,1,0x32);
        NKDbgPrintfW(L"\r\n~!@#$  decrease volume volume = [ %d ][%d] \r\n",local_36,DAT_0005549c);
        if (DAT_0005549c == 1) {
          local_38[0] = 1;
          DAT_0005549c = 0;
          FUN_00015f10(DAT_000553cc,6,1,3,(int)local_38,1,0xfa);
        }
      }
      else {
        NKDbgPrintfW(L"\r\n~!@#$  AMP STANDBY ON (%d) volume\r\n",DAT_0005549c);
        if (DAT_0005549c == 0) {
          local_38[0] = 0;
          DAT_0005549c = 1;
          FUN_00015f10(DAT_000553cc,6,1,3,(int)local_38,1,0xfa);
        }
      }
      iVar7 = 200;
LAB_00021db4:
      FUN_000338ac(iVar7,iVar9);
      return;
    }
    if (bVar2 == 0x35) {
      if (DAT_0005549c == 1) {
        DAT_0005549c = 0;
        local_36 = '\x01';
        FUN_00015f10(DAT_000553cc,6,1,3,(int)&local_36,1,0xfa);
      }
      pwVar6 = L"\r\n~!@#$ NOTI_APP_TEMP_NORMAL\r\n";
    }
    else {
      if (bVar2 == 0x60) {
        FUN_00031f20(param_2,(byte *)(param_3 + 1));
        return;
      }
      if (bVar2 == 0x61) {
        FUN_00033058(param_2,(byte *)(param_3 + 1));
        FUN_00032eb4(param_2,(byte *)(param_3 + 1));
        return;
      }
      if (bVar2 == 0x62) {
        cVar1 = (char)param_3[1];
        if (cVar1 == '\x05') {
          iVar9 = (uint)(byte)param_3[2] * 0x100 + (uint)*(byte *)((int)param_3 + 7);
          uVar11 = (uint)*(byte *)(*(int *)(param_2 + 0x10) + 4);
          if (uVar11 == *(byte *)((int)param_3 + 6)) {
            if (uVar11 == 0) {
              iVar9 = iVar9 * 10;
            }
            (**(code **)(*DAT_00057130 + 8))(DAT_00057130,0x6f,iVar9);
            return;
          }
          FUN_000338ac(0x7b,(uint)*(byte *)((int)param_3 + 6) << 0x10);
          *(int *)(param_2 + 0x8c) = iVar9;
          *(undefined4 *)(param_2 + 0x4c) = 4;
          UVar8 = 500;
          goto LAB_00020c50;
        }
        if (cVar1 != '\a') {
          if (cVar1 != '\b') {
            if (cVar1 != ')') {
              return;
            }
            iVar7 = 0x7b;
            if (*(char *)((int)param_3 + 6) == '\x01') {
              iVar9 = 0x290000;
            }
            else {
              iVar9 = 0;
            }
            goto LAB_00021db4;
          }
          if (*(char *)((int)param_3 + 6) == '\x01') {
            if (*(int *)(DAT_000553dc + 0x18) == 2) {
              return;
            }
            FUN_00016dbc(DAT_000553dc);
            return;
          }
          if (*(char *)((int)param_3 + 6) != '\x02') {
            return;
          }
LAB_00021a34:
          FUN_00016c74(DAT_000553dc);
          return;
        }
        hWnd = FindWindowW((LPCWSTR)0x0,L"RVC WND");
        if (*(int *)(DAT_000553dc + 0x18) == 2) {
          if (*(char *)((int)param_3 + 6) == '\x11') {
            uVar11 = (uint)*(byte *)((int)param_3 + 7);
            if ((uVar11 == 0x20) || (uVar11 == 0x40)) {
              SendMessageW(hWnd,0x9e61,0,uVar11);
            }
            goto LAB_00021a34;
          }
          if (*(char *)((int)param_3 + 6) != '\0') {
            return;
          }
          if (hWnd == (HWND)0xffffffff) {
            return;
          }
          NKDbgPrintfW(L" :: RVC config...func code=0x%x\n",*(undefined1 *)((int)param_3 + 7));
        }
        else {
          if (hWnd == (HWND)0xffffffff) {
            return;
          }
          if (*(char *)((int)param_3 + 6) != '\0') {
            return;
          }
          FUN_00016dbc(DAT_000553dc);
        }
        SendMessageW(hWnd,0x9e61,0,(uint)*(byte *)((int)param_3 + 7));
        return;
      }
      if (bVar2 != 99) {
        return;
      }
      uVar11 = (uint)*(byte *)((int)param_3 + 3);
      NKDbgPrintfW(
                  L"\n---< DTC Table >---------------------------------------------------------------------\n"
                  );
      iVar9 = 0;
      if (uVar11 != 0) {
        do {
          NKDbgPrintfW(L"[%d]0x%X ",iVar9,*(undefined1 *)((int)param_3 + iVar9 + 4));
          iVar9 = iVar9 + 1;
        } while (iVar9 < (int)uVar11);
      }
      NKDbgPrintfW(&DAT_0004b190);
      _Dst_00 = malloc(uVar11 + 1);
      if (_Dst_00 != (void *)0x0) {
        memcpy(_Dst_00,param_3 + 1,uVar11);
        FUN_000207fc(param_2,_Dst_00,uVar11);
        free(_Dst_00);
        return;
      }
      pwVar6 = L"Fail to allocation memory for saving DTC values..Canceled\n";
    }
  }
  NKDbgPrintfW(pwVar6);
switchD_00021774_default:
  return;
}



/* 00021e38 FUN_00021e38 */

/* Boundary evidence: original MIPS .pdata 00021e38..00021f93. Semantic name remains unreviewed. */

undefined4 FUN_00021e38(int param_1,char *param_2)

{
  int *piVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  
  uVar4 = 1;
  KillTimer(*(HWND *)(param_1 + 4),1);
  KillTimer(*(HWND *)(param_1 + 4),2);
  KillTimer(*(HWND *)(param_1 + 4),3);
  piVar1 = (int *)__2_YAPAXI_Z(4);
  if (piVar1 == (int *)0x0) {
    piVar1 = (int *)0x0;
  }
  else {
    *piVar1 = 0;
  }
  *(int **)(param_1 + 0x28) = piVar1;
  iVar2 = FUN_0001ebb4(piVar1,param_2);
  if (iVar2 == 1) {
    *(undefined4 *)(param_1 + 0x20) = 1;
    FUN_00015f10(DAT_000553cc,1,1,5,0,0,0x32);
    *(undefined4 *)(param_1 + 0x24) = 1;
    FUN_00019164(DAT_000553dc,0);
  }
  else {
    puVar3 = *(undefined4 **)(param_1 + 0x28);
    if (puVar3 != (undefined4 *)0x0) {
      if ((void *)*puVar3 != (void *)0x0) {
        free((void *)*puVar3);
        *puVar3 = 0;
      }
      __3_YAXPAX_Z(puVar3);
    }
    *(undefined4 *)(param_1 + 0x28) = 0;
    *(undefined4 *)(param_1 + 0x20) = 1;
    FUN_00015f10(DAT_000553cc,1,1,5,0,0,0x32);
    *(undefined4 *)(param_1 + 0x24) = 1;
    FUN_00019164(DAT_000553dc,1000);
    uVar4 = 0;
  }
  FUN_0001c1dc(param_1,0x20);
  return uVar4;
}



/* 00021f94 FUN_00021f94 */

/* Boundary evidence: original MIPS .pdata 00021f94..0002244b. Semantic name remains unreviewed. */

void FUN_00021f94(int param_1)

{
  bool bVar1;
  uint uVar2;
  HWND hWnd;
  LSTATUS LVar3;
  DWORD DVar4;
  DWORD DVar5;
  wchar_t *pwVar6;
  wchar_t *lpNewFileName;
  int iVar7;
  ushort *puVar8;
  HKEY local_68;
  int local_64 [3];
  undefined1 local_58 [40];
  uint local_30;
  
  local_30 = DAT_00055374;
  KillTimer(*(HWND *)(param_1 + 4),1);
  KillTimer(*(HWND *)(param_1 + 4),2);
  KillTimer(*(HWND *)(param_1 + 4),3);
  memset(local_58,0x10,0x24);
  uVar2 = FUN_00016068(DAT_000553cc,0xd,0x2c,local_58,0x24,300);
  if (uVar2 == 0x24) {
    NKDbgPrintfW(L"\n---< Save DTC Table >---\n");
    iVar7 = 0;
    do {
      NKDbgPrintfW(L"[%d]0x%X ",iVar7,local_58[iVar7]);
      iVar7 = iVar7 + 1;
    } while (iVar7 < 0x24);
    NKDbgPrintfW(&DAT_0004b190);
    FUN_000207fc(param_1,local_58,0x24);
  }
  else {
    NKDbgPrintfW(L"\n[ERROR]---< Save DTC Table %d>---\n",uVar2);
  }
  puVar8 = (ushort *)(param_1 + 0x98);
  uVar2 = ((uint)(*(int *)(param_1 + 0x2c) == 1) << 4 ^ (uint)*puVar8) & 0x10 ^ (uint)*puVar8;
  *puVar8 = (ushort)uVar2;
  DAT_00057c84 = (byte)(uVar2 >> 4) & 1;
  FUN_000110b4(DAT_00055384);
  FUN_0003e4c8();
  FUN_0002f484();
  FUN_0002e8a0(DAT_00057348);
  FUN_00015b90(DAT_000553cc,1,1,(int)puVar8,2,0x32);
  FUN_000238a0(0);
  FUN_0001c648();
  FUN_0001e560(param_1,0,1);
  uVar2 = 0;
  do {
    hWnd = FindWindowW(L"NAVI",L"NAVI");
    if (hWnd == (HWND)0x0) break;
    PostMessageW(hWnd,0x10,0,0);
    NKDbgPrintfW(L"\r\n---< %s >--- NNG Still alive == %d\n","CMicom::PowerOff",uVar2);
    Sleep(100);
    bVar1 = uVar2 < 0x14;
    uVar2 = uVar2 + 1;
  } while (bVar1);
  local_64[2] = 4;
  local_64[1] = 4;
  local_64[0] = 0;
  LVar3 = RegOpenKeyExW((HKEY)0x80000002,L"LGE\\SystemInfo",0,0,&local_68);
  if (LVar3 != 0) goto LAB_00022388;
  DVar4 = GetTickCount();
  LVar3 = RegQueryValueExW(local_68,L"BootSequence",(LPDWORD)0x0,(LPDWORD)(local_64 + 2),
                           (LPBYTE)local_64,(LPDWORD)(local_64 + 1));
  if (LVar3 != 0) {
    NKDbgPrintfW(L"\r\n---< %s >--- ==> Registery is not present.... <==\r\n","CMicom::PowerOff");
  }
  RegCloseKey(local_68);
  if (local_64[0] == 0) {
    NKDbgPrintfW(L"\r\n---< %s >--- ==> Kernel loading OK <==\r\n","CMicom::PowerOff");
  }
  else {
    if (local_64[0] == 1) {
      NKDbgPrintfW(L"\r\n---< %s >--- ==> Kernel loading error %d <==\r\n","CMicom::PowerOff",1);
      lpNewFileName = L"\\Storage Card\\NK.bin";
      pwVar6 = L"\\Storage Card\\NA.bin";
    }
    else {
      if (local_64[0] != 2) {
        if (local_64[0] == 3) {
          iVar7 = 3;
          pwVar6 = L"\r\n---< %s >--- ==> NC Kernel loading %d <==\r\n";
        }
        else {
          pwVar6 = L"\r\n---< %s >--- ==> Kernel loading Unknown %d <==\r\n";
          iVar7 = local_64[0];
        }
        NKDbgPrintfW(pwVar6,"CMicom::PowerOff",iVar7);
        goto LAB_00022368;
      }
      NKDbgPrintfW(L"\r\n---< %s >--- ==> Kernel loading error %d <==\r\n","CMicom::PowerOff",2);
      pwVar6 = L"\\Storage Card\\NB.bin";
      CopyFileW(L"\\Storage Card\\NB.bin",L"\\Storage Card\\NK.bin",0);
      lpNewFileName = L"\\Storage Card\\NA.bin";
    }
    CopyFileW(pwVar6,lpNewFileName,0);
  }
LAB_00022368:
  DVar5 = GetTickCount();
  NKDbgPrintfW(L"\r\n---< %s >--- ==> Total Time %d[msec] <==\r\n","CMicom::PowerOff",DVar5 - DVar4)
  ;
LAB_00022388:
  Sleep(0x96);
  FUN_0001dfa0(param_1,0,1,0,1,0,0,0,0);
  Sleep(100);
  FUN_00015f10(DAT_000553cc,0,1,1,0,0,0x96);
  FUN_0001e62c(param_1,0);
  Sleep(100);
  SetSystemPowerState(0,0x200000);
  FUN_00043604(local_30);
  return;
}



/* 0002244c FUN_0002244c */

/* Boundary evidence: original MIPS .pdata 0002244c..00023173. Semantic name remains unreviewed. */

void FUN_0002244c(int param_1,uint param_2,uint param_3)

{
  LSTATUS LVar1;
  HANDLE hFile;
  BOOL BVar2;
  wchar_t *pwVar3;
  undefined4 uVar4;
  char *pcVar5;
  int iVar6;
  undefined1 uVar7;
  uint uVar8;
  undefined1 local_58 [4];
  undefined4 local_54;
  UINT local_50;
  HKEY local_4c;
  HKEY local_48;
  DWORD local_44 [3];
  _SYSTEMTIME _Stack_38;
  
  uVar7 = (undefined1)param_3;
  if (param_2 < 0xb9) {
    if (param_2 == 0xb8) {
      NKDbgPrintfW(L"\r\n~!@#$ IDM_X_MMCM_SPEED_ALARM %d\r\n",param_3);
      if (param_3 != 0) {
        local_54 = CONCAT31(local_54._1_3_,2);
        if (param_3 == 1) goto LAB_00022ba0;
      }
      local_54 = CONCAT31(local_54._1_3_,1);
LAB_00022ba0:
      local_54 = CONCAT22(local_54._2_2_,CONCAT11((char)(DAT_00057364 >> 0x12),(BYTE)local_54)) &
                 0xffff3fff;
      FUN_00015f10(DAT_000553cc,5,1,0x40,(int)&local_54,2,100);
      return;
    }
    if (param_2 < 0x8a) {
      if (param_2 == 0x89) {
        *(undefined1 *)(*(int *)(param_1 + 0x10) + 0x682) = uVar7;
        return;
      }
      if (param_2 == 0x71) {
        if (param_3 != 0) {
          FUN_00015f10(DAT_000553cc,7,1,0,0,0,100);
          return;
        }
        FUN_00015f10(DAT_000553cc,7,1,1,0,0,100);
        return;
      }
      if (param_2 != 0x86) {
        if (param_2 == 0x87) {
          FUN_00027458(DAT_00057130,1);
          FUN_00024814();
          if (DAT_000554ac == 0) {
            FUN_0001c030();
            DAT_000554ac = 1;
          }
          PostMessageW((HWND)0xffff,DAT_000554b8,0,0);
          return;
        }
        if (param_2 == 0x88) {
          NKDbgPrintfW(L"\n=======  IDM_X_MMCM_PWR_OFF_CONFIRM :: m_bIsPowerOff - %d  ===============\n"
                       ,*(undefined4 *)(param_1 + 0x34));
          if (*(int *)(param_1 + 0x34) == 1) {
            FUN_00021f94(param_1);
            return;
          }
          return;
        }
        return;
      }
      if (2 < *(int *)(param_1 + 0x68)) {
        *(undefined4 *)(param_1 + 0x68) = 2;
      }
      if (2 < param_3) {
        param_3 = 1;
      }
      (&DAT_0005735c)[*(int *)(param_1 + 0x68)] = (char)param_3;
      *(undefined1 *)(*(int *)(param_1 + 0x10) + *(int *)(param_1 + 0x68) + 0x67a) =
           (&DAT_0005735c)[*(int *)(param_1 + 0x68)];
      goto LAB_000225bc;
    }
    if (param_2 != 0xb4) {
      if (param_2 == 0xb5) {
        FUN_00032cc4(param_1,param_3);
        return;
      }
      if (param_2 == 0xb6) {
        NKDbgPrintfW(L"\r\n~!@#$ IDM_X_MMCM_DARKMODE %d\r\n",param_3);
        if (param_3 == 0) {
          *(undefined4 *)(param_1 + 0x6c) = 0;
          return;
        }
        if (param_3 == 1) {
          *(undefined4 *)(param_1 + 0x6c) = 1;
          return;
        }
        return;
      }
      if (param_2 != 0xb7) {
        return;
      }
      NKDbgPrintfW(L"\r\n~!@#$ IDM_X_MMCM_MAINEXCUTE_DONE %d\r\n",*(undefined4 *)(param_1 + 0x5c));
      if (*(int *)(param_1 + 0x5c) == 1) {
        *(undefined4 *)(param_1 + 0x5c) = 0;
        FUN_0002d6b0(DAT_00057130);
        if ((*(int *)(param_1 + 0x2c) == 3) || (*(int *)(param_1 + 0x50) == 1)) {
          FUN_00033908(0x71,0);
          FUN_000339cc(0x3030104,0);
        }
        else if (DAT_000554a8 != 0) {
          NKDbgPrintfW(L"  \r\n\r\n\r\n  [Micom]  RVC Update  !!!!!!!   \r\n\r\n\r\n");
          DAT_000554a8 = 0;
          FUN_0001c398(param_1);
        }
        SetTimer(*(HWND *)(param_1 + 4),2,200,(TIMERPROC)0x0);
        SetTimer(*(HWND *)(param_1 + 4),0x708,0x1c20,(TIMERPROC)0x0);
        return;
      }
      return;
    }
    local_44[1] = 4;
    local_4c = (HKEY)0xffffffff;
    local_44[0] = 4;
    FUN_00015f10(DAT_000553cc,5,1,0x41,0,0,100);
    LVar1 = RegOpenKeyExW((HKEY)0x80000002,L"LGE\\SystemInfo",0,0,&local_48);
    if (LVar1 == 0) {
      RegQueryValueExW(local_48,L"FACTORY_TYPE",(LPDWORD)0x0,local_44 + 1,(LPBYTE)&local_4c,local_44
                      );
      RegCloseKey(local_48);
    }
    if ((local_4c == (HKEY)0x0) && (param_3 == 0)) {
      local_50 = 120000;
      hFile = CreateFileW(L"\\Storage Card2\\Antitheft.cfg",0x80000000,0,(LPSECURITY_ATTRIBUTES)0x0,
                          3,0x80,(HANDLE)0x0);
      if (hFile != (HANDLE)0xffffffff) {
        BVar2 = ReadFile(hFile,&local_50,4,local_44 + 2,(LPOVERLAPPED)0x0);
        if (BVar2 == 0) {
          NKDbgPrintfW(L"~~~~~~~~~~~::~~~~~~~~~~~~FCODE TIMEOUT 111 ERROR - 2min");
LAB_00022940:
          local_50 = 120000;
        }
        else if (local_50 == 0) {
          local_50 = 60000;
        }
        else if ((int)local_50 < 1) {
LAB_0002291c:
          local_50 = 0x1d4c00;
        }
        else {
          if ((int)local_50 < 4) goto LAB_00022940;
          if (local_50 == 4) {
            local_50 = 240000;
          }
          else if (local_50 == 5) {
            local_50 = 480000;
          }
          else {
            if (local_50 != 6) goto LAB_0002291c;
            local_50 = 960000;
          }
        }
        CloseHandle(hFile);
      }
      NKDbgPrintfW(L"~~~~~~~~~~~::~~~~~~~~~~~~FCODE TIMEOUT 111 timeout-%d\r\n",local_50);
      *(undefined4 *)(param_1 + 0x70) = 1;
      SetTimer(*(HWND *)(param_1 + 4),3,local_50,(TIMERPROC)0x0);
      local_54 = CONCAT22(local_54._2_2_,0x1400);
      FUN_00015f10(DAT_000553cc,5,1,0x40,(int)&local_54,2,100);
    }
    uVar8 = (uint)(param_3 == 0);
    local_54 = CONCAT31(local_54._1_3_,uVar7);
    if (param_3 != 0) {
      *(ushort *)(param_1 + 0x98) = *(ushort *)(param_1 + 0x98) | 4;
    }
    if (((*(ushort *)(param_1 + 0x98) & 1) == 0) && (param_3 == 0)) {
      uVar8 = 0;
    }
    NKDbgPrintfW(L"~~~~~~~~~~~::~~~~~~~~~~~~FCODE TIMEOUT 111 m_bIsLocked-%d, bIsLocked-%d, factory-%d, m_nPwrState-%d\r\n"
                 ,*(undefined4 *)(param_1 + 0x50),uVar8,local_4c,*(undefined4 *)(param_1 + 0x2c));
    if (*(uint *)(param_1 + 0x50) == uVar8) {
      if ((uVar8 != 0) && (local_4c == (HKEY)0x0)) {
        if (*(int *)(param_1 + 0x2c) == 1) {
          *(undefined1 *)(*(int *)(param_1 + 0x10) + 0x688) = 0;
          FUN_00016c74(DAT_000553dc);
          if (*(int *)(param_1 + 0x1c) == 1) {
            FUN_00016dbc(DAT_000553dc);
          }
          Sleep(100);
          FUN_000339cc(0x3030105,0);
          FUN_00033908(0x72,0);
          local_58[0] = 0;
          FUN_00015f10(DAT_000553cc,1,1,1,(int)local_58,1,100);
          pwVar3 = L"\r\n~(3)~PWRSTATE_NORMAL unmuted\r\n";
        }
        else {
          if (*(int *)(param_1 + 0x2c) != 3) goto LAB_00022b4c;
          *(undefined1 *)(*(int *)(param_1 + 0x10) + 0x688) = 1;
          FUN_00033908(0x71,0);
          FUN_000339cc(0x3030104,0);
          FUN_00016e7c(DAT_000553dc);
          local_58[0] = 1;
          FUN_00015f10(DAT_000553cc,1,1,1,(int)local_58,1,100);
          pwVar3 = L"\r\n~(4)~PWRSTATE_NORMAL muted\r\n";
        }
        NKDbgPrintfW(pwVar3);
      }
    }
    else {
      *(uint *)(param_1 + 0x50) = uVar8;
      FUN_0001c398(param_1);
    }
LAB_00022b4c:
    FUN_00015f10(DAT_000553cc,1,1,0x10,(int)&local_54,1,100);
    return;
  }
  switch(param_2) {
  case 0xb9:
    if (param_3 == 1) {
      FUN_000338ac(0x77,0);
      FUN_0001b420(DAT_00055408);
LAB_00022ce8:
      local_4c = (HKEY)0x1;
      DAT_00057c86 = 1;
    }
    else {
      FUN_000338ac(0x78,0);
      if (param_3 != 0) goto LAB_00022ce8;
      local_4c = (HKEY)0x0;
      DAT_00057c86 = 0;
    }
    DAT_00057c85 = (byte)(*(ushort *)(param_1 + 0x98) >> 2) & 1;
    FUN_0003e4c8();
    FUN_0002f484();
    FUN_00015f10(DAT_000553cc,1,1,7,(int)&local_4c,1,0x32);
    FUN_00014e14(DAT_000553a8,1);
    if (*(HKEY *)(param_1 + 0x60) != local_4c) {
      local_58[0] = 0;
      *(HKEY *)(param_1 + 0x60) = local_4c;
      *(HKEY *)(param_1 + 0x5c) = local_4c;
      if (local_4c == (HKEY)0x0) {
        if (*(int *)(param_1 + 0x2c) == 3) {
          local_58[0] = 1;
          FUN_00016e7c(DAT_000553dc);
        }
        else {
          FUN_000339cc(0x3030105,0);
          FUN_00033908(0x72,0);
          FUN_00016c74(DAT_000553dc);
          if (*(int *)(param_1 + 0x1c) == 1) {
            FUN_00016dbc(DAT_000553dc);
          }
        }
      }
      else {
        local_58[0] = 1;
        FUN_00033908(0x71,0);
        FUN_000339cc(0x3030104,0);
        if (*(int *)(param_1 + 0x1c) == 1) {
          FUN_00016c74(DAT_000553dc);
        }
      }
      FUN_00015f10(DAT_000553cc,1,1,1,(int)local_58,1,100);
      NKDbgPrintfW(L"\r\n CMD_APP_CLOCK_MODE : %d\r\n",local_58[0]);
    }
    NKDbgPrintfW(L"\r\nIDM_X_MMCM_FW_UPDATE ==> value : %d, bUpgrade : %d, m_bUpdateStart : %d, m_bEventBlock : %d, m_nPwrState : %d, m_bRearGearDetect : %d\r\n"
                 ,param_3,local_4c,*(undefined4 *)(param_1 + 0x60),*(undefined4 *)(param_1 + 0x5c),
                 *(undefined4 *)(param_1 + 0x2c),*(undefined4 *)(param_1 + 0x1c));
    break;
  case 0xba:
    if (param_3 == 0) {
      *(undefined4 *)(param_1 + 0x68) = 0;
    }
    else if (param_3 == 1) {
      *(undefined4 *)(param_1 + 0x68) = 1;
    }
    else if (param_3 == 2) {
      *(undefined4 *)(param_1 + 0x68) = 2;
    }
LAB_000225bc:
    FUN_0001c8ec(param_1);
    return;
  case 0xbb:
    if (((param_3 != 0) && (param_3 != 2)) && (param_3 != 4)) {
      return;
    }
    if (*(int *)(param_1 + 0x30) != 0) {
      return;
    }
    if (*(int *)(param_1 + 0x50) != 0) {
      return;
    }
    if (*(int *)(param_1 + 0x60) != 0) {
      return;
    }
    if (*(int *)(param_1 + 0x2c) != 3) {
      return;
    }
    iVar6 = 1;
    goto LAB_00022f40;
  case 0xbc:
    local_44[0] = 4;
    local_54 = -1;
    local_50 = 0xffffffff;
    local_48 = (HKEY)0x4;
    LVar1 = RegOpenKeyExW((HKEY)0x80000002,L"LGE\\SystemInfo",0,0,&local_4c);
    if (LVar1 == 0) {
      RegQueryValueExW(local_4c,L"Manual_Time_Hour",(LPDWORD)0x0,local_44,(LPBYTE)&local_54,
                       (LPDWORD)&local_48);
      RegQueryValueExW(local_4c,L"Manual_Time_Minute",(LPDWORD)0x0,local_44,(LPBYTE)&local_50,
                       (LPDWORD)&local_48);
      RegCloseKey(local_4c);
      if (param_3 == 1000) {
        uVar4 = 0;
      }
      else {
        if (param_3 != 0x3ea) goto LAB_00023088;
        GetLocalTime(&_Stack_38);
        _Stack_38.wMinute = (WORD)local_50;
        _Stack_38.wHour = (WORD)local_54;
        iVar6 = local_54 * 0x3c + local_50 + 2000;
        FUN_000338ac(0xbc,iVar6);
        NKDbgPrintfW(L"[McmMgr]  MgrMcmPostMessage(IDM_X_MMCM_USER_TIME_SET, %d)\r\n",iVar6);
        uVar4 = 2;
      }
      FUN_000237bc(uVar4);
      FUN_000238a0(1);
    }
LAB_00023088:
    NKDbgPrintfW(L"\r\n[McmMgr] IDM_X_MMCM_USER_TIME_SET(%d) :: Manual_Time_Hour(%d), Manual_Time_Minute(%d)\r\n"
                 ,param_3,local_54,local_50);
    break;
  case 0xc6:
    if (param_3 == 4) {
      FUN_0003e2b8(*(undefined4 *)(param_1 + 4));
      return;
    }
    if (param_3 == 5) {
      FUN_00036b34(*(undefined4 *)(param_1 + 4));
      return;
    }
    if (param_3 == 6) {
      FUN_0003b4a4(*(undefined4 *)(param_1 + 4));
      return;
    }
    if (param_3 != 8) {
      return;
    }
    iVar6 = 2;
LAB_00022f40:
    FUN_000206b0(param_1,iVar6);
    break;
  case 199:
    if (param_3 == 0x1234) {
      FUN_0001da14();
      FUN_000238a0(0);
      pcVar5 = "\\Storage Card3\\upgrade\\firmware.hex";
    }
    else if (param_3 == 0x1235) {
      pcVar5 = "\\MD\\firmware.hex";
    }
    else {
      if (param_3 != 0x1236) {
        return;
      }
      pcVar5 = "\\Storage Card\\firmware.hex";
    }
    FUN_00021e38(param_1,pcVar5);
    FUN_000338ac(0x79,0);
    break;
  case 200:
    FUN_00013590(DAT_000553a8,uVar7);
    FUN_000135c0(DAT_000553a8,*(int *)(DAT_000553a8 + 0x10),1);
    break;
  case 0xca:
    FUN_000135b8(DAT_000553a8,uVar7);
  }
  return;
}



/* 00023174 FUN_00023174 */

/* Boundary evidence: original MIPS .pdata 00023174..000234af. Semantic name remains unreviewed. */

void FUN_00023174(int param_1)

{
  uint uVar1;
  void *_Dst;
  DWORD DVar2;
  UINT UVar3;
  code *pcVar4;
  undefined4 uVar5;
  int iVar6;
  char local_20 [8];
  
  switch(*(undefined4 *)(param_1 + 0x4c)) {
  case 0:
    *(undefined4 *)(param_1 + 0x4c) = 0;
    FUN_0002d83c(param_1);
    break;
  case 1:
    *(undefined4 *)(param_1 + 0x4c) = 0;
    FUN_0002d83c(param_1);
    FUN_00015f10(DAT_000553cc,0,1,0x20,0,0,0xfa);
    *(undefined4 *)(param_1 + 0x34) = 1;
    local_20[0] = '\0';
    uVar1 = FUN_00016068(DAT_000553cc,0,0x50,local_20,1,200);
    if ((uVar1 == 1) &&
       (NKDbgPrintfW(L"[[ ====> TIMER_ACC_OFF <==== ]]  state=%d\r\n",local_20[0]),
       local_20[0] == '\x01')) {
      FUN_00015f10(DAT_000553cc,0,1,0x20,0,0,0xfa);
    }
    FUN_000338ac(0x79,0);
    *(undefined4 *)(param_1 + 0x54) = 0;
    uVar5 = 2;
    UVar3 = 5000;
    goto LAB_000232a4;
  case 2:
    if (*(uint *)(param_1 + 0x54) < 8) {
      FUN_000338ac(0x79,0);
    }
    else {
      *(undefined4 *)(param_1 + 0x4c) = 0;
      FUN_0002d83c(param_1);
      FUN_00021f94(param_1);
    }
    *(int *)(param_1 + 0x54) = *(int *)(param_1 + 0x54) + 1;
    break;
  case 3:
    *(undefined4 *)(param_1 + 0x4c) = 0;
    FUN_0002d83c(param_1);
    FUN_00021f94(param_1);
    break;
  case 4:
    *(undefined4 *)(param_1 + 0x4c) = 0;
    FUN_0002d83c(param_1);
    iVar6 = *(int *)(param_1 + 0x8c);
    NKDbgPrintfW(L"After set band.... freq=%d\n",iVar6);
    if (*(char *)(*(int *)(param_1 + 0x10) + 4) == '\0') {
      iVar6 = iVar6 * 10;
      pcVar4 = *(code **)(*DAT_00057130 + 8);
    }
    else {
      pcVar4 = *(code **)(*DAT_00057130 + 8);
    }
    (*pcVar4)(DAT_00057130,0x6f,iVar6);
    break;
  case 5:
    FUN_00015f10(DAT_000553cc,1,1,0,0,0,100);
    break;
  case 6:
    *(undefined4 *)(param_1 + 0x4c) = 0;
    FUN_0002d83c(param_1);
    NKDbgPrintfW(L"Restore DTC table to MICOM\n");
    _Dst = malloc(0x25);
    if (_Dst != (void *)0x0) {
      memset(_Dst,0x10,0x24);
      DVar2 = FUN_0001d8c0(param_1,_Dst,0x24);
      if (DVar2 < 0x24) {
        NKDbgPrintfW(L"Fail to load DTC table to file - ULC_DTC.tbl\n");
      }
      else {
        FUN_00015b90(DAT_000553cc,0xd,0x2b,(int)_Dst,0x24,200);
      }
      free(_Dst);
    }
    uVar5 = 5;
    UVar3 = 1000;
LAB_000232a4:
    *(undefined4 *)(param_1 + 0x4c) = uVar5;
    FUN_0002d814(param_1,UVar3);
    break;
  case 7:
    if (DAT_000553dc != 0) {
      *(undefined4 *)(param_1 + 0x4c) = 0;
      FUN_0002d83c(param_1);
      FUN_00017328(DAT_000553dc,2,0);
    }
  }
  return;
}



/* 000234b0 FUN_000234b0 */

/* Boundary evidence: original MIPS .pdata 000234b0..0002357f. Semantic name remains unreviewed. */

undefined4 FUN_000234b0(int param_1)

{
  undefined4 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  
  uVar1 = 0;
  if (param_1 == 0) {
    QueryPerformanceFrequency((LARGE_INTEGER *)&DAT_000554f8);
    QueryPerformanceCounter((LARGE_INTEGER *)&DAT_000554f0);
    uVar1 = 0;
  }
  else if (param_1 == 1) {
    QueryPerformanceCounter((LARGE_INTEGER *)&DAT_000554e8);
    uVar2 = __ll_to_d(DAT_000554e8 - DAT_000554f0,
                      (DAT_000554ec - DAT_000554f4) - (uint)(DAT_000554e8 < DAT_000554f0));
    uVar3 = __ll_to_d(DAT_000554f8,DAT_000554fc);
    uVar2 = __dpdiv((int)uVar2,(int)((ulonglong)uVar2 >> 0x20),(int)uVar3,
                    (int)((ulonglong)uVar3 >> 0x20));
    uVar1 = __dptoul((int)uVar2,(int)((ulonglong)uVar2 >> 0x20));
  }
  return uVar1;
}



/* 00023580 FUN_00023580 */

/* Boundary evidence: original MIPS .pdata 00023580..000236e3. Semantic name remains unreviewed. */

undefined4 FUN_00023580(int param_1,LPVOID param_2,DWORD param_3)

{
  HANDLE hFile;
  BOOL BVar1;
  wchar_t *pwVar2;
  undefined4 uVar3;
  DWORD aDStack_28 [2];
  
  uVar3 = 0;
  hFile = CreateFileW(L"\\Storage Card2\\UserTimeInfo.cfg",0xc0000000,0,(LPSECURITY_ATTRIBUTES)0x0,4
                      ,0x80,(HANDLE)0x0);
  if (hFile == (HANDLE)0xffffffff) {
    NKDbgPrintfW(L"[McmMgr] [ERROR] Open :: UserTimeInfo.cfg \r\n");
    return 0xffffffff;
  }
  if (param_1 == 0) {
    BVar1 = ReadFile(hFile,param_2,param_3,aDStack_28,(LPOVERLAPPED)0x0);
    if (BVar1 != 0) goto LAB_000236a8;
    pwVar2 = L"[McmMgr] [ERROR] Read :: UserTimeInfo.cfg \r\n";
  }
  else {
    if (param_1 != 1) {
      NKDbgPrintfW(L"[McmMgr] [ERROR] Undefine Type : %d \r\n");
      goto LAB_000236a8;
    }
    BVar1 = WriteFile(hFile,param_2,param_3,aDStack_28,(LPOVERLAPPED)0x0);
    if (BVar1 != 0) goto LAB_000236a8;
    pwVar2 = L"[McmMgr] [ERROR] Write :: UserTimeInfo.cfg \r\n";
  }
  NKDbgPrintfW(pwVar2);
  uVar3 = 0xffffffff;
LAB_000236a8:
  CloseHandle(hFile);
  return uVar3;
}



/* 000236e4 FUN_000236e4 */

/* Boundary evidence: original MIPS .pdata 000236e4..000237bb. Semantic name remains unreviewed. */

int FUN_000236e4(void)

{
  HANDLE hFile;
  BOOL BVar1;
  int iVar2;
  DWORD aDStack_20 [2];
  undefined1 auStack_18 [4];
  int local_14;
  
  iVar2 = 0;
  hFile = CreateFileW(L"\\Storage Card2\\Navi_Time.cfg",0x80000000,0,(LPSECURITY_ATTRIBUTES)0x0,3,
                      0x80,(HANDLE)0x0);
  if (hFile != (HANDLE)0xffffffff) {
    BVar1 = ReadFile(hFile,auStack_18,8,aDStack_20,(LPOVERLAPPED)0x0);
    if (((BVar1 != 0) && (-1 < local_14)) && (local_14 < 3)) {
      iVar2 = local_14;
    }
    CloseHandle(hFile);
  }
  NKDbgPrintfW(L"[McmMgr] ReadUserTimeSetting ->> Manual time set: %d \r\n",iVar2);
  return iVar2;
}



/* 000237bc FUN_000237bc */

/* Boundary evidence: original MIPS .pdata 000237bc..0002389f. Semantic name remains unreviewed. */

undefined4 FUN_000237bc(undefined4 param_1)

{
  HANDLE hFile;
  DWORD DStack_20;
  DWORD DStack_1c;
  undefined1 auStack_18 [4];
  undefined4 local_14;
  
  hFile = CreateFileW(L"\\Storage Card2\\Navi_Time.cfg",0xc0000000,0,(LPSECURITY_ATTRIBUTES)0x0,3,
                      0x80,(HANDLE)0x0);
  if (hFile != (HANDLE)0xffffffff) {
    ReadFile(hFile,auStack_18,8,&DStack_20,(LPOVERLAPPED)0x0);
    local_14 = param_1;
    SetFilePointer(hFile,0,(PLONG)0x0,0);
    WriteFile(hFile,auStack_18,8,&DStack_1c,(LPOVERLAPPED)0x0);
    CloseHandle(hFile);
  }
  return param_1;
}



/* 000238a0 FUN_000238a0 */

/* Boundary evidence: original MIPS .pdata 000238a0..00023abf. Semantic name remains unreviewed. */

undefined4 FUN_000238a0(int param_1)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  _SYSTEMTIME _Stack_e8;
  char local_d8 [4];
  int local_d4;
  _SYSTEMTIME _Stack_d0;
  _TIME_ZONE_INFORMATION local_c0;
  uint local_14;
  
  local_14 = DAT_00055374;
  if (param_1 == 0) {
    GetSystemTime(&_Stack_d0);
    GetLocalTime(&_Stack_e8);
    uVar1 = FUN_000234b0(1);
    if ((((DAT_00055614 == 0x7dc) && (DAT_00055610 == '\x01')) && (DAT_00055607 == '\x01')) ||
       (DAT_00055614 == 0)) {
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
      iVar4 = ((uint)DAT_00055604 * 0x3c + (uint)DAT_00055605) * 0x3c + (uVar1 & 0xffff) +
              (uint)DAT_00055606;
      iVar3 = ((uint)_Stack_e8.wHour * 0x3c + (uint)_Stack_e8.wMinute) * 0x3c +
              (uint)_Stack_e8.wSecond;
    }
    iVar3 = iVar3 - iVar4;
  }
  else {
    iVar3 = 0;
  }
  iVar4 = FUN_000236e4();
  local_d8[0] = (char)iVar4;
  local_d8[1] = 0;
  local_d4 = iVar3;
  NKDbgPrintfW(L"[McmMgr]  userTimeInfo.userTimeSetFlag : %d, userTimeInfo.offset  %d \r\n",
               (int)local_d8[0],iVar3);
  uVar2 = FUN_00023580(1,local_d8,8);
  FUN_00043604(local_14);
  return uVar2;
}



/* 00023ac0 FUN_00023ac0 */

/* Boundary evidence: original MIPS .pdata 00023ac0..00023bc7. Semantic name remains unreviewed. */

undefined4 FUN_00023ac0(char *param_1,undefined1 *param_2,int param_3,int param_4)

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
        if (cVar2 == '\0') goto LAB_00023b90;
      } while (iVar3 != param_3);
    }
    pcVar5 = param_1 + iVar4;
    if ((*pcVar5 != ',') && (*pcVar5 != '*')) {
      iVar3 = 0;
      while( true ) {
        cVar2 = *pcVar5;
        if ((cVar2 == '*') || (cVar2 == '\0')) goto LAB_00023b9c;
        pcVar1 = param_2 + iVar3;
        iVar3 = iVar3 + 1;
        *pcVar1 = cVar2;
        pcVar5 = pcVar5 + 1;
        if (param_4 <= iVar3) break;
        if (*pcVar5 == ',') {
LAB_00023b9c:
          param_2[iVar3] = 0;
          return 1;
        }
      }
      iVar3 = param_4 + -1;
      goto LAB_00023b9c;
    }
LAB_00023b90:
    *param_2 = 0;
  }
  return 0;
}



/* 00023bc8 FUN_00023bc8 */

/* Boundary evidence: original MIPS .pdata 00023bc8..00023da3. Semantic name remains unreviewed. */

void FUN_00023bc8(char *param_1)

{
  int iVar1;
  char local_38;
  undefined1 local_37;
  char local_36 [14];
  char local_28;
  undefined1 local_27;
  char local_26;
  undefined1 local_25;
  char local_24;
  undefined1 local_23;
  uint local_c;
  
  local_c = DAT_00055374;
  iVar1 = FUN_00023ac0(param_1,&local_28,0,0x19);
  if (iVar1 != 0) {
    local_38 = local_28;
    local_37 = local_27;
    local_36[0] = '\0';
    iVar1 = atoi(&local_38);
    DAT_00055604 = (undefined1)iVar1;
    local_38 = local_26;
    local_37 = local_25;
    local_36[0] = '\0';
    iVar1 = atoi(&local_38);
    DAT_00055605 = (undefined1)iVar1;
    local_38 = local_24;
    local_37 = local_23;
    local_36[0] = '\0';
    iVar1 = atoi(&local_38);
    DAT_00055606 = (undefined1)iVar1;
    atoi(local_36);
  }
  FUN_00023ac0(param_1,&local_28,1,0x19);
  FUN_00023ac0(param_1,&local_28,2,0x19);
  FUN_00023ac0(param_1,&local_28,3,0x19);
  FUN_00023ac0(param_1,&local_28,4,0x19);
  FUN_00023ac0(param_1,&local_28,5,0x19);
  FUN_00023ac0(param_1,&local_28,6,0x19);
  FUN_00023ac0(param_1,&local_28,7,0x19);
  iVar1 = FUN_00023ac0(param_1,&local_28,8,0x19);
  if (iVar1 != 0) {
    local_38 = local_28;
    local_37 = local_27;
    local_36[0] = '\0';
    iVar1 = atoi(&local_38);
    DAT_00055607 = (undefined1)iVar1;
    local_38 = local_26;
    local_37 = local_25;
    local_36[0] = '\0';
    iVar1 = atoi(&local_38);
    DAT_00055610 = (undefined1)iVar1;
    local_38 = local_24;
    local_37 = local_23;
    local_36[0] = '\0';
    iVar1 = atoi(&local_38);
    DAT_00055614 = (short)iVar1 + 2000;
  }
  FUN_00043604(local_c);
  return;
}



/* 00023da4 FUN_00023da4 */

/* Boundary evidence: original MIPS .pdata 00023da4..000244d7. Semantic name remains unreviewed. */

undefined4 FUN_00023da4(void)

{
  HANDLE pvVar1;
  int iVar2;
  BOOL BVar3;
  LSTATUS LVar4;
  DWORD DVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  DWORD local_298 [2];
  _SYSTEMTIME local_290;
  HKEY local_280 [2];
  char local_278 [4];
  int local_274;
  int local_270 [2];
  _DCB _Stack_268;
  _COMMTIMEOUTS local_248;
  DWORD DStack_234;
  _DCB _Stack_230;
  TIME_ZONE_INFORMATION TStack_210;
  TIME_ZONE_INFORMATION local_160;
  char local_b0;
  char local_af;
  char local_ae;
  char local_ad;
  char local_ac;
  uint local_30;
  
  local_30 = DAT_00055374;
  pvVar1 = CreateFileW(L"COM4:",0x80000000,0,(LPSECURITY_ATTRIBUTES)0x0,3,0x80,(HANDLE)0x0);
  if (pvVar1 != (HANDLE)0xffffffff) {
    GetCommState(pvVar1,&_Stack_268);
    memcpy(&_Stack_230,&_Stack_268,0x1c);
    _Stack_268.BaudRate = 0x2580;
    _Stack_268.fNull = 0;
    _Stack_268.fParity = 0;
    _Stack_268.ByteSize = '\b';
    _Stack_268.Parity = '\0';
    _Stack_268.StopBits = '\0';
    SetCommState(pvVar1,&_Stack_268);
    local_248.ReadIntervalTimeout = 2000;
    local_248.ReadTotalTimeoutMultiplier = 3000;
    local_248.ReadTotalTimeoutConstant = 1;
    local_248.WriteTotalTimeoutMultiplier = 0;
    local_248.WriteTotalTimeoutConstant = 0;
    SetCommTimeouts(pvVar1,&local_248);
    iVar2 = ReadFile(pvVar1,&local_b0,1,local_298,(LPOVERLAPPED)0x0);
    while (iVar2 == 1) {
      if (local_298[0] != 1) break;
      if (local_b0 == '$') {
        BVar3 = ReadFile(pvVar1,&local_b0,5,local_298,(LPOVERLAPPED)0x0);
        if ((BVar3 != 1) || (local_298[0] != 5)) break;
        if ((local_b0 == 'G') &&
           ((((local_af == 'P' && (local_ae == 'R')) && (local_ad == 'M')) && (local_ac == 'C')))) {
          BVar3 = ReadFile(pvVar1,&local_b0,1,local_298,(LPOVERLAPPED)0x0);
          if ((BVar3 != 1) || (local_298[0] != 1)) break;
          if (local_b0 == ',') {
            BVar3 = ReadFile(pvVar1,&DAT_00055500,1,local_298,(LPOVERLAPPED)0x0);
            uVar6 = 0;
            if (BVar3 == 1) goto LAB_00024008;
            break;
          }
        }
      }
      iVar2 = ReadFile(pvVar1,&local_b0,1,local_298,(LPOVERLAPPED)0x0);
    }
  }
  goto LAB_00024090;
  while( true ) {
    if (((uVar6 != 0) && (*(char *)((int)&DAT_000554fc + uVar6 + 3) == '\r')) &&
       ((&DAT_00055500)[uVar6] == '\n')) {
      FUN_00023bc8(&DAT_00055500);
      FUN_000234b0(0);
      break;
    }
    if (0x100 < uVar6 + 1) break;
    BVar3 = ReadFile(pvVar1,&DAT_00055501 + uVar6,1,local_298,(LPOVERLAPPED)0x0);
    uVar6 = uVar6 + 1;
    if (BVar3 != 1) break;
LAB_00024008:
    if (local_298[0] != 1) break;
  }
LAB_00024090:
  SetCommState(pvVar1,&_Stack_230);
  CloseHandle(pvVar1);
  DAT_00054be0 = 0;
  NKDbgPrintfW(L"[GPS Port Close] \r\n");
  GetSystemTime(&local_290);
  pvVar1 = CreateFileW(L"\\Storage Card2\\RTC_Clock.bin",0x80000000,0,(LPSECURITY_ATTRIBUTES)0x0,3,
                       0x80,(HANDLE)0x0);
  if (pvVar1 != (HANDLE)0xffffffff) {
    ReadFile(pvVar1,&TStack_210,0xac,&DStack_234,(LPOVERLAPPED)0x0);
    if (((((DAT_00055604 == 0) && (DAT_00055605 == 0)) && (DAT_00055606 == 0)) &&
        ((DAT_00055607 == 0 && (DAT_00055610 == 0)))) && (DAT_00055614 == 0)) {
      DAT_00055605 = (byte)TStack_210.StandardDate.wMinute;
      DAT_00055604 = (byte)TStack_210.StandardDate.wHour;
      DAT_00055610 = (byte)TStack_210.StandardDate.wMonth;
      DAT_00055606 = (byte)TStack_210.StandardDate.wSecond;
      DAT_00055607 = (byte)TStack_210.StandardDate.wDay;
      DAT_00055614 = TStack_210.StandardDate.wYear;
    }
    SetTimeZoneInformation(&TStack_210);
    CloseHandle(pvVar1);
  }
  if (((DAT_00055607 == 0) || (DAT_00055610 == 0)) || (DAT_00055614 == 0)) {
    DAT_00055614 = 0x7dd;
    DAT_00055610 = 1;
    DAT_00055607 = 1;
    NKDbgPrintfW(L"[McmMgr]  if(g_bRMCDay == 0 || g_bRMCMonth == 0 || g_wRMCYear == 0) \r\n");
  }
  local_290.wDay = (WORD)DAT_00055607;
  local_290.wMonth = (WORD)DAT_00055610;
  local_290.wYear = DAT_00055614;
  local_290.wHour = (WORD)DAT_00055604;
  local_290.wMinute = (WORD)DAT_00055605;
  local_290.wSecond = (WORD)DAT_00055606;
  local_290.wMilliseconds = 0;
  SetSystemTime(&local_290);
  FUN_00023580(0,local_278,8);
  if (local_278[0] != '\0') {
    local_160.Bias = 0;
    local_160.StandardBias = 0;
    local_160.DaylightBias = 0;
    memset(&local_160.StandardDate,0,0x10);
    memset(&local_160.DaylightDate,0,0x10);
    SetTimeZoneInformation(&local_160);
    uVar6 = (uint)DAT_00055604;
    uVar9 = (uint)DAT_00055605;
    iVar10 = (uVar6 * 0x3c + uVar9) * 0x3c + (uint)DAT_00055606;
    iVar2 = local_274 + iVar10;
    if (iVar2 < 0) {
      iVar2 = iVar2 + 0x15180;
      NKDbgPrintfW(L"[McmMgr]  sSystemTime = sSystemTime + (1440 * 60) \r\n");
      uVar6 = (uint)DAT_00055604;
      uVar9 = (uint)DAT_00055605;
    }
    uVar8 = iVar2 / 0xe10 & 0xffff;
    local_290.wHour = (WORD)(iVar2 / 0xe10);
    if (0x17 < uVar8) {
      uVar7 = uVar8 + 0xffe8;
      uVar8 = uVar7 & 0xffff;
      local_290.wHour = (WORD)uVar7;
    }
    uVar7 = (iVar2 / 0x3c) % 0x3c;
    local_290.wMinute = (WORD)uVar7;
    NKDbgPrintfW(L"[McmMgr]  UTC time-> %2d:%2d, UTCTime(%d), userTimeInfo.offset(%d) system time -> %d:%d \r\n"
                 ,uVar6,uVar9,iVar10,local_274,uVar8,uVar7 & 0xffff);
  }
  LVar4 = RegOpenKeyExW((HKEY)0x80000002,L"LGE\\SystemInfo",0,0,local_280);
  if (LVar4 == 0) {
    local_270[0] = FUN_000236e4();
    RegSetValueExW(local_280[0],L"ManualTimeSet",0,4,(BYTE *)local_270,4);
    RegCloseKey(local_280[0]);
  }
  if (local_278[0] != '\0') {
    BVar3 = SetLocalTime(&local_290);
    if (BVar3 == 0) {
      DVar5 = GetLastError();
      NKDbgPrintfW(L"[McmMgr]  SetLocalTime FAIL -> [%d] \r\n",DVar5);
    }
    NKDbgPrintfW(L"[McmMgr]  set local time(Manual) -> %02d:%02d: \r\n",local_290.wHour,
                 local_290.wMinute);
  }
  NKDbgPrintfW(L"\n======================================================================\r\n");
  NKDbgPrintfW(L"[RTC Date] %04d:%02d:%02d \r\n",local_290.wYear,local_290.wMonth,local_290.wDay);
  NKDbgPrintfW(L"[RTC Time] %02d:%02d:%02d \r\n",local_290.wHour,local_290.wMinute,local_290.wSecond
              );
  NKDbgPrintfW(L"======================================================================\r\n\n");
  FUN_00043604(local_30);
  return 0;
}



/* 000244d8 FUN_000244d8 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Boundary evidence: original MIPS .pdata 000244d8..00024813. Semantic name remains unreviewed. */

void FUN_000244d8(void)

{
  int iVar1;
  byte *pbVar2;
  uint uVar3;
  
  uVar3 = 0;
  do {
    FUN_0002f6e8(0,uVar3);
    FUN_0002f6e8(1,uVar3);
    uVar3 = uVar3 + 1;
  } while (uVar3 < 0xc);
  uVar3 = 0;
  do {
    FUN_0002f8d4(0,uVar3);
    FUN_0002f8d4(1,uVar3);
    uVar3 = uVar3 + 1;
  } while (uVar3 < 0x24);
  *(byte *)(DAT_00055618 + 4) = (byte)(DAT_00057354 >> 0xb) & 3;
  *(undefined1 *)(DAT_00055618 + 0x613) = (&DAT_0005736c)[(DAT_00057354 >> 0xb & 3) * 0x48c];
  uVar3 = DAT_00057354 >> 0xb & 3;
  if ((DAT_00057354 & 2) == 2) {
    uVar3 = (uint)(ushort)(&DAT_00057370)[uVar3 * 0x246];
    if (uVar3 == 0) {
      *(undefined4 *)(DAT_00055618 + 8) = 0;
    }
    else {
      iVar1 = FUN_0002e300(DAT_00057348,uVar3);
      *(int *)(DAT_00055618 + 8) = iVar1;
    }
    if (*(int *)(DAT_00055618 + 8) == 0) {
      *(undefined4 *)(DAT_00055618 + 8) = (&DAT_00057374)[(DAT_00057354 >> 0xb & 3) * 0x123];
    }
    FUN_0002e27c(DAT_00057348,uVar3,(undefined4 *)(DAT_00055618 + 0x617));
  }
  else {
    *(undefined4 *)(DAT_00055618 + 8) = (&DAT_00057374)[uVar3 * 0x123];
    *(undefined1 *)(DAT_00055618 + 0x617) = 0;
  }
  *(bool *)(DAT_00055618 + 0x60c) = (DAT_00057354 & 2) == 2;
  *(bool *)(DAT_00055618 + 0x60d) = (DAT_00057354 & 8) == 8;
  *(bool *)(DAT_00055618 + 0x60e) = (DAT_00057354 & 0x10) == 0x10;
  *(bool *)(DAT_00055618 + 0x60f) = (DAT_00057354 & 0x20) == 0x20;
  *(bool *)(DAT_00055618 + 0x610) = (DAT_00057354 & 0x40) == 0x40;
  *(undefined1 *)(DAT_00055618 + 0x66c) = 6;
  *(byte *)(DAT_00055618 + 0x673) = (byte)(DAT_00057354 >> 7) & 7;
  *(byte *)(DAT_00055618 + 0x679) = (byte)(DAT_00057354 >> 10) & 1;
  *(char *)(DAT_00055618 + 0x675) = (char)(DAT_00057354 >> 0x15);
  *(char *)(DAT_00055618 + 0x674) = (char)(DAT_00057354 >> 0xd);
  uVar3 = 0;
  *(char *)(DAT_00055618 + 0x676) = (char)_DAT_00057358;
  *(undefined1 *)(DAT_00055618 + 0x677) = DAT_00057359;
  *(undefined1 *)(DAT_00055618 + 0x678) = DAT_0005735a;
  do {
    pbVar2 = &DAT_0005735c + uVar3;
    if (2 < *pbVar2) {
      *pbVar2 = 1;
    }
    iVar1 = DAT_00055618 + uVar3;
    uVar3 = uVar3 + 1;
    *(byte *)(iVar1 + 0x67a) = *pbVar2;
  } while (uVar3 < 3);
  *(byte *)(DAT_00055618 + 0x682) = (byte)DAT_00057360 & 1;
  return;
}



/* 00024814 FUN_00024814 */

/* Boundary evidence: original MIPS .pdata 00024814..00024897. Semantic name remains unreviewed. */

void FUN_00024814(void)

{
  FUN_00029d80((int)DAT_00057130);
  FUN_0002eea8();
  (**(code **)(*DAT_00057130 + 8))(DAT_00057130,0x81,(DAT_00057354 & 2) == 2);
  FUN_000244d8();
  FUN_0002d788((int)DAT_00057130);
  FUN_00012d48(DAT_00055384);
  return;
}



/* 00024898 FUN_00024898 */

/* Boundary evidence: original MIPS .pdata 00024898..00024a07. Semantic name remains unreviewed. */

undefined4 FUN_00024898(HWND param_1)

{
  uint *puVar1;
  int iVar2;
  UINT Msg;
  uint uVar3;
  WPARAM wParam;
  
joined_r0x000248c8:
  while( true ) {
    do {
      if (DAT_0005561c == 0) {
        return 0;
      }
      puVar1 = (uint *)FUN_000266d0(0x556dc);
      iVar2 = FUN_0002635c((undefined4 *)&DAT_00055638,(byte *)puVar1);
    } while (iVar2 != 1);
    uVar3 = *puVar1 & 0xff;
    if (uVar3 != 0xa6) break;
LAB_00024970:
    EventModify(*(undefined4 *)(DAT_000553cc + 0xc),3);
  }
  if (uVar3 == 0xaa) {
    if ((*puVar1 & 0xf00) == 0xd00) {
      FUN_00026638(0x55638,puVar1);
      goto LAB_00024970;
    }
    iVar2 = FUN_000266ec(0x556dc);
    if (iVar2 == 0) {
      NKDbgPrintfW(L"%S : Q Push Error(0x%02X, 0x%02X)\r\n","CommandThread",*puVar1 >> 8 & 0xf,
                   *(byte *)((int)puVar1 + 2));
    }
    wParam = 0;
    Msg = 0x401;
  }
  else {
    if (uVar3 != 0xab) goto joined_r0x000248c8;
    wParam = (WPARAM)*(byte *)((int)puVar1 + 1);
    Msg = 0x402;
  }
  PostMessageW(param_1,Msg,wParam,0);
  goto joined_r0x000248c8;
}



/* 00024a08 FUN_00024a08 */

/* Boundary evidence: original MIPS .pdata 00024a08..00025913. Semantic name remains unreviewed. */

LRESULT FUN_00024a08(HWND param_1,uint param_2,uint param_3,uint param_4)

{
  bool bVar1;
  uint uVar2;
  int iVar3;
  undefined3 extraout_var;
  HDC pHVar4;
  DWORD DVar5;
  HANDLE hThread;
  LSTATUS LVar6;
  size_t sVar7;
  size_t sVar8;
  LRESULT LVar9;
  wchar_t *pwVar10;
  undefined4 *puVar11;
  int *piVar12;
  UINT_PTR nIDEvent;
  UINT uElapse;
  int *piVar13;
  FILE *local_100;
  HKEY local_fc;
  undefined1 local_f8;
  undefined1 local_f7;
  undefined2 local_f6 [3];
  tagPAINTSTRUCT tStack_f0;
  char acStack_b0 [32];
  char acStack_90 [32];
  WCHAR aWStack_70 [32];
  uint local_30;
  
  local_30 = DAT_00055374;
  if (0x202 < param_2) {
    if (param_2 == 0x400) goto LAB_000258d0;
    if (param_2 == 0x401) {
      piVar13 = FUN_00026748((int *)&DAT_000556dc);
      while (piVar13 != (int *)0x0) {
        uVar2 = 0;
        do {
          piVar12 = *(int **)((int)&DAT_000554c8 + uVar2);
          if (piVar12 != (int *)0x0) {
            (**(code **)(*piVar12 + 0xc))(piVar12,piVar13);
          }
          uVar2 = uVar2 + 4;
        } while (uVar2 < 0x1c);
        piVar13 = FUN_00026748((int *)&DAT_000556dc);
      }
      goto LAB_000258d0;
    }
    if (param_2 == 0x402) {
      FUN_00015e90((int)DAT_000553cc);
      FUN_0001c1dc((int)DAT_00055498,param_3 & 0xff);
      goto LAB_000258d0;
    }
    if (param_2 == 0x8064) {
      uVar2 = 0;
      do {
        piVar13 = *(int **)((int)&DAT_000554c8 + uVar2);
        if (piVar13 != (int *)0x0) {
          (**(code **)(*piVar13 + 8))(piVar13,param_3 >> 0x10,param_4);
        }
        uVar2 = uVar2 + 4;
      } while (uVar2 < 0x1c);
      goto LAB_000258d0;
    }
    if (param_2 == 0x8067) {
      NKDbgPrintfW(L"BLUE Message [0x%08X, 0x%08X]\n\r",param_3,param_4);
      if ((param_3 == 0x3040101) && (DAT_00055498 != (int *)0x0)) {
        (**(code **)(*DAT_00055498 + 8))(DAT_00055498,0xb5,param_4 & 0xffff | 0xf10000);
      }
      goto LAB_000258d0;
    }
LAB_000256e8:
    if (param_2 == DAT_00055620) {
      if (DAT_000553dc != (undefined4 *)0x0) {
        FUN_000178d4((int)DAT_000553dc,param_4);
      }
    }
    else {
      if (param_2 != DAT_00055634) {
        LVar9 = DefWindowProcW(param_1,param_2,param_3,param_4);
        FUN_00043604(local_30);
        return LVar9;
      }
      NKDbgPrintfW(L"[[[ MGRMCM ]]]   g_uPowerDownMsg [%d, %d] \r\n",param_3,param_4);
      FUN_00015f10((int)DAT_000553cc,1,1,0xfc,0,0,100);
    }
    goto LAB_000258d0;
  }
  if (param_2 == 0x202) {
    FUN_00017500((int)DAT_000553dc,param_3,param_4);
    goto LAB_000258d0;
  }
  if (param_2 == 1) {
    FUN_0002f250();
    FUN_00031264();
    DAT_000554e4 = CreateFileMappingW((HANDLE)0xffffffff,(LPSECURITY_ATTRIBUTES)0x0,4,0,0x6e8,
                                      L"MgrMcmShm");
    if (DAT_000554e4 == (HANDLE)0x0) {
      DVar5 = GetLastError();
      NKDbgPrintfW(L"%S lpName=%s, CreateFileMapping fail, error=%d","WndProc",L"MgrMcmShm",DVar5);
      if (DVar5 == 0xb7) {
        NKDbgPrintfW(L"%S has already been made","WndProc");
      }
    }
    else {
      DAT_00055618 = MapViewOfFile(DAT_000554e4,0xf001f,0,0,0);
      if (DAT_00055618 == (LPVOID)0x0) {
        DVar5 = GetLastError();
        NKDbgPrintfW(L"%S lpName=%s, MapViewOfFile fail, error=%d","WndProc",L"MgrMcmShm",DVar5);
        CloseHandle(DAT_000554e4);
        DAT_00055618 = (LPCVOID)0x0;
      }
      else {
        local_100 = (FILE *)__2_YAPAXI_Z(0x8c);
        if (local_100 == (FILE *)0x0) {
          DAT_00057348 = (undefined1 *)0x0;
        }
        else {
          DAT_00057348 = FUN_0002ee24((undefined1 *)local_100);
        }
        FUN_000244d8();
        DAT_0005561c = 1;
        hThread = CreateThread((LPSECURITY_ATTRIBUTES)0x0,0,FUN_00024898,param_1,4,(LPDWORD)0x0);
        if (hThread != (HANDLE)0x0) {
          SetThreadPriority(hThread,0);
          ResumeThread(hThread);
          CloseHandle(hThread);
        }
        SetRVCWnd(DAT_00055600,param_1);
        LVar6 = RegOpenKeyExW((HKEY)0x80000002,L"LGE\\SystemInfo",0,0,&local_fc);
        if (LVar6 == 0) {
          local_100 = (FILE *)0x0;
          sprintf_s(acStack_b0,0x20,"\\mgrmcm %d.%d.%d.%s.ver",4,0,6,&DAT_0004cb9c);
          fopen_s(&local_100,acStack_b0,"wt");
          if (local_100 != (FILE *)0x0) {
            fclose(local_100);
            local_100 = (FILE *)0x0;
          }
          wsprintfW(aWStack_70,L"%d.%d.%d.%s",4,0,6,L"0410");
          sVar7 = wcslen(aWStack_70);
          RegSetValueExW(local_fc,L"VerMgrMcm",0,1,(BYTE *)aWStack_70,sVar7 << 1);
          sprintf_s(acStack_90,0x20,"\\voconsse ");
          sprintf_s(acStack_b0,0x20,"\\ec ");
          sVar7 = strlen(acStack_90);
          sVar8 = strlen(acStack_b0);
          GetECVersion(acStack_b0 + sVar8,0x18,acStack_90 + sVar7,0x10);
          sVar7 = strlen(acStack_b0);
          sprintf_s(acStack_b0 + sVar7,5,".ver");
          sVar7 = strlen(acStack_90);
          sprintf_s(acStack_90 + sVar7,5,".ver");
          fopen_s(&local_100,acStack_b0,"wt");
          if (local_100 != (FILE *)0x0) {
            fclose(local_100);
            local_100 = (FILE *)0x0;
          }
          fopen_s(&local_100,acStack_90,"wt");
          if (local_100 != (FILE *)0x0) {
            fclose(local_100);
            local_100 = (FILE *)0x0;
          }
          GetECVersion(acStack_b0,0x20,acStack_90,0x10);
          wsprintfW(aWStack_70,L"%S",acStack_b0);
          sVar7 = wcslen(aWStack_70);
          RegSetValueExW(local_fc,L"VerEC",0,1,(BYTE *)aWStack_70,sVar7 << 1);
          wsprintfW(aWStack_70,L"%S",acStack_90);
          sVar7 = wcslen(aWStack_70);
          RegSetValueExW(local_fc,L"VerVoConSSE",0,1,(BYTE *)aWStack_70,sVar7 << 1);
          sprintf_s(acStack_b0,0x20,"\\rvc ");
          sVar7 = strlen(acStack_b0);
          GetRVCVersion(acStack_b0 + sVar7,0x18);
          sVar7 = strlen(acStack_b0);
          sprintf_s(acStack_b0 + sVar7,5,".ver");
          fopen_s(&local_100,acStack_b0,"wt");
          if (local_100 != (FILE *)0x0) {
            fclose(local_100);
            local_100 = (FILE *)0x0;
          }
          GetRVCVersion(acStack_b0,0x20);
          wsprintfW(aWStack_70,L"%S",acStack_b0);
          sVar7 = wcslen(aWStack_70);
          RegSetValueExW(local_fc,L"VerRVC",0,1,(BYTE *)aWStack_70,sVar7 << 1);
          RegCloseKey(local_fc);
        }
        Sleep(100);
        NKDbgPrintfW(L"%S : Start MicomManager\r\n","WndProc");
        local_fc = (HKEY)__2_YAPAXI_Z(0xc4);
        if (local_fc == (HKEY)0x0) {
          DAT_000553cc = (undefined4 *)0x0;
        }
        else {
          DAT_000553cc = FUN_00015978(local_fc,param_1,10);
        }
        DAT_000554c8 = DAT_000553cc;
        local_fc = (HKEY)__2_YAPAXI_Z(0x40);
        if (local_fc == (HKEY)0x0) {
          DAT_000553dc = (undefined4 *)0x0;
        }
        else {
          DAT_000553dc = FUN_00016668(local_fc,DAT_00055600,param_1,0xb,DAT_00055618);
        }
        DAT_000554cc = DAT_000553dc;
        local_fc = (HKEY)__2_YAPAXI_Z(0x9c);
        if (local_fc == (HKEY)0x0) {
          DAT_00055498 = (int *)0x0;
        }
        else {
          DAT_00055498 = FUN_0001eefc(local_fc,param_1,0xc,DAT_00055618);
        }
        DAT_000554d0 = DAT_00055498;
        local_fc = (HKEY)__2_YAPAXI_Z(0x70);
        if (local_fc == (HKEY)0x0) {
          DAT_00055384 = (undefined4 *)0x0;
        }
        else {
          DAT_00055384 = FUN_00011000(local_fc,param_1,0xd,DAT_00055618);
        }
        DAT_000554d4 = DAT_00055384;
        local_fc = (HKEY)__2_YAPAXI_Z(0x294);
        if (local_fc == (HKEY)0x0) {
          DAT_000554d8 = (undefined4 *)0x0;
        }
        else {
          DAT_000554d8 = FUN_0002679c(local_fc,param_1,0xe,DAT_00055618);
        }
        DAT_00057130 = DAT_000554d8;
        local_fc = (HKEY)__2_YAPAXI_Z(0x54);
        if (local_fc == (HKEY)0x0) {
          DAT_000553a8 = (undefined4 *)0x0;
        }
        else {
          DAT_000553a8 = FUN_00013344(local_fc,param_1,0xf,DAT_00055618);
        }
        DAT_000554dc = DAT_000553a8;
        local_fc = (HKEY)__2_YAPAXI_Z(0x70);
        if (local_fc == (HKEY)0x0) {
          DAT_00055408 = (undefined4 *)0x0;
        }
        else {
          DAT_00055408 = FUN_0001b988(local_fc,param_1,0x10,(int)DAT_00055618);
        }
        DAT_000554e0 = DAT_00055408;
        SetTimer(param_1,1,1000,(TIMERPROC)0x0);
        FUN_000175fc((int)DAT_000553dc);
      }
    }
    goto LAB_000258d0;
  }
  if (param_2 == 2) {
    KillTimer(param_1,1);
    KillTimer(param_1,2);
    KillTimer(param_1,3);
    KillTimer(param_1,0x709);
    KillTimer(param_1,0x708);
    FUN_00017bd8((int)DAT_000553dc);
    uVar2 = 0;
    do {
      piVar13 = (int *)((int)&DAT_000554c8 + uVar2);
      puVar11 = (undefined4 *)*piVar13;
      if (puVar11 != (undefined4 *)0x0) {
        (**(code **)*puVar11)(puVar11,1);
      }
      uVar2 = uVar2 + 4;
      *piVar13 = 0;
    } while (uVar2 < 0x1c);
    DAT_0005561c = 0;
    FUN_0002602c((undefined4 *)&DAT_00055638);
    Sleep(0x32);
    UnmapViewOfFile(DAT_00055618);
    CloseHandle(DAT_000554e4);
    PostQuitMessage(0);
    goto LAB_000258d0;
  }
  if (param_2 == 0xf) {
    pHVar4 = BeginPaint(param_1,&tStack_f0);
    FUN_00019a10((int)DAT_000553dc,pHVar4);
    EndPaint(param_1,&tStack_f0);
    goto LAB_000258d0;
  }
  if (param_2 != 0x113) {
    if (param_2 == 0x201) {
      FUN_00017458((int)DAT_000553dc,param_3,param_4);
      goto LAB_000258d0;
    }
    goto LAB_000256e8;
  }
  if (param_3 == 1) {
    FUN_00015f10((int)DAT_000553cc,1,1,0xff,0,0,100);
    goto LAB_000258d0;
  }
  if (param_3 == 2) {
    if (DAT_0005712c == 0) {
      DAT_0005712c = 1;
      FUN_00015f10((int)DAT_000553cc,1,1,0xb,0,0,100);
    }
    local_f6[0] = 0;
    uElapse = 200;
    KillTimer(param_1,2);
    uVar2 = FUN_00016068((int)DAT_000553cc,9,4,local_f6,2,0x96);
    if (uVar2 == 2) {
      FUN_0001df48((int)DAT_00055498,local_f6[0]);
    }
    else {
      uElapse = 400;
    }
    nIDEvent = 2;
LAB_00024b94:
    SetTimer(param_1,nIDEvent,uElapse,(TIMERPROC)0x0);
    goto LAB_000258d0;
  }
  if (param_3 == 3) {
    KillTimer(param_1,3);
    DAT_00055498[0x1c] = 0;
    FUN_0001dc38((int)DAT_00055498);
    goto LAB_000258d0;
  }
  if (param_3 != 0x708) {
    if (param_3 == 0x709) {
      FUN_00014df8((int)DAT_000553a8);
    }
    else if (param_3 == 0x70a) {
      KillTimer(param_1,0x70a);
      FUN_0001ddf4((int)DAT_00055498);
    }
    else if (param_3 == 0x70b) {
      KillTimer(param_1,0x70b);
      FUN_0001b65c((int)DAT_00055408);
    }
    else if (param_3 == 0x76c) {
      KillTimer(param_1,0x76c);
      local_f7 = 1;
      NKDbgPrintfW(
                  L"\n==>TIMER_MAKE_VIRGIN - All clear CAN configuration including Map code(0x2D2D) forcely..\n"
                  );
      FUN_00015f10((int)DAT_000553cc,0xd,1,2,(int)&local_f7,1,0xfa);
    }
    else if (param_3 == 0x76d) {
      KillTimer(param_1,0x76d);
      NKDbgPrintfW(L"\n==>TIMER_MAPMODE_CHG - Change MAP MODE..\n");
      FUN_000338ac(0x7b,0x90000);
    }
    else {
      uVar2 = 0;
      piVar13 = (int *)&DAT_000554c8;
      do {
        if ((*piVar13 != 0) &&
           (bVar1 = FUN_0002d7fc(*piVar13,param_3), CONCAT31(extraout_var,bVar1) == 1)) {
          (**(code **)(*(&DAT_000554c8)[uVar2] + 4))();
          break;
        }
        uVar2 = uVar2 + 1;
        piVar13 = piVar13 + 1;
      } while (uVar2 < 7);
    }
    goto LAB_000258d0;
  }
  if (DAT_00055498 == (int *)0x0) goto LAB_000258d0;
  local_f8 = 0;
  KillTimer(param_1,0x708);
  iVar3 = FUN_00033730();
  if (iVar3 == 0) {
    pwVar10 = L"\n++++++++Success to initail Bluetooht module\r\n";
LAB_00024c60:
    NKDbgPrintfW(pwVar10);
  }
  else {
    if (iVar3 == 1) {
      pwVar10 = L"\n++++++++Fail to initail Bluetooht module\r\n";
      goto LAB_00024c60;
    }
    if (iVar3 == 2) {
      NKDbgPrintfW(L"\n++++++++Not ready Bluetooth module...%d\r\n",DAT_00057128);
      uElapse = 5000;
      nIDEvent = 0x708;
      goto LAB_00024b94;
    }
  }
  local_f8 = (undefined1)iVar3;
  FUN_00015b90((int)DAT_000553cc,0xd,0x2a,(int)&local_f8,1,100);
  FUN_0001d9d0((int)DAT_00055498);
LAB_000258d0:
  FUN_00043604(local_30);
  return 0;
}



/* 00025914 Unwind@00025914 */

/* Boundary evidence: original MIPS .pdata 00025914..00025943. Semantic name remains unreviewed. */

void Unwind_00025914(void)

{
  int in_v0;
  
  __3_YAXPAX_Z(*(undefined4 *)(in_v0 + -0x100));
  return;
}



/* 00025944 Unwind@00025944 */

/* Boundary evidence: original MIPS .pdata 00025944..00025973. Semantic name remains unreviewed. */

void Unwind_00025944(void)

{
  int in_v0;
  
  __3_YAXPAX_Z(*(undefined4 *)(in_v0 + -0xfc));
  return;
}



/* 00025974 Unwind@00025974 */

/* Boundary evidence: original MIPS .pdata 00025974..000259a3. Semantic name remains unreviewed. */

void Unwind_00025974(void)

{
  int in_v0;
  
  __3_YAXPAX_Z(*(undefined4 *)(in_v0 + -0xfc));
  return;
}



/* 000259a4 Unwind@000259a4 */

/* Boundary evidence: original MIPS .pdata 000259a4..000259d3. Semantic name remains unreviewed. */

void Unwind_000259a4(void)

{
  int in_v0;
  
  __3_YAXPAX_Z(*(undefined4 *)(in_v0 + -0xfc));
  return;
}



/* 000259d4 Unwind@000259d4 */

/* Boundary evidence: original MIPS .pdata 000259d4..00025a03. Semantic name remains unreviewed. */

void Unwind_000259d4(void)

{
  int in_v0;
  
  __3_YAXPAX_Z(*(undefined4 *)(in_v0 + -0xfc));
  return;
}



/* 00025a04 Unwind@00025a04 */

/* Boundary evidence: original MIPS .pdata 00025a04..00025a33. Semantic name remains unreviewed. */

void Unwind_00025a04(void)

{
  int in_v0;
  
  __3_YAXPAX_Z(*(undefined4 *)(in_v0 + -0xfc));
  return;
}



/* 00025a34 Unwind@00025a34 */

/* Boundary evidence: original MIPS .pdata 00025a34..00025a63. Semantic name remains unreviewed. */

void Unwind_00025a34(void)

{
  int in_v0;
  
  __3_YAXPAX_Z(*(undefined4 *)(in_v0 + -0xfc));
  return;
}



/* 00025a64 Unwind@00025a64 */

/* Boundary evidence: original MIPS .pdata 00025a64..00025a93. Semantic name remains unreviewed. */

void Unwind_00025a64(void)

{
  int in_v0;
  
  __3_YAXPAX_Z(*(undefined4 *)(in_v0 + -0xfc));
  return;
}



/* 00025a94 FUN_00025a94 */

/* Boundary evidence: original MIPS .pdata 00025a94..00025af7. Semantic name remains unreviewed. */

void FUN_00025a94(HINSTANCE param_1,LPCWSTR param_2)

{
  WNDCLASSW local_30;
  
  local_30.style = 3;
  local_30.lpfnWndProc = FUN_00024a08;
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



/* 00025af8 FUN_00025af8 */

/* Boundary evidence: original MIPS .pdata 00025af8..00025bcf. Semantic name remains unreviewed. */

undefined4 FUN_00025af8(HINSTANCE param_1)

{
  bool bVar1;
  undefined3 extraout_var;
  int iVar2;
  HWND hWnd;
  
  bVar1 = FUN_00025f54((undefined4 *)&DAT_00055638);
  if (CONCAT31(extraout_var,bVar1) == 0) {
    NKDbgPrintfW(L"[MICOM MANAGER:%S] Can\'t open serial port","InitInstance");
  }
  else {
    DAT_00055600 = param_1;
    iVar2 = FUN_00025a94(param_1,L"MGRMCM");
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



/* 00025bd0 FUN_00025bd0 */

/* Boundary evidence: original MIPS .pdata 00025bd0..00025d03. Semantic name remains unreviewed. */

undefined4 FUN_00025bd0(HINSTANCE param_1,undefined4 param_2,wchar_t *param_3)

{
  int iVar1;
  HANDLE hThread;
  BOOL BVar2;
  MSG MStack_38;
  
  if ((param_3 != (wchar_t *)0x0) &&
     (iVar1 = wcsncmp(param_3,L"$er10q4c$=4G2g1.5_-H2tq9X@mid",0x1d), iVar1 == 0)) {
    hThread = CreateThread((LPSECURITY_ATTRIBUTES)0x0,0,FUN_00023da4,(LPVOID)0x0,4,(LPDWORD)0x0);
    if (hThread != (HANDLE)0x0) {
      SetThreadPriority(hThread,0);
      ResumeThread(hThread);
      CloseHandle(hThread);
      Sleep(0);
    }
    iVar1 = FUN_00025af8(param_1);
    if (iVar1 != 0) {
      SetThreadPriority((HANDLE)0x41,0);
      while (BVar2 = GetMessageW(&MStack_38,(HWND)0x0,0,0), BVar2 != 0) {
        TranslateMessage(&MStack_38);
        DispatchMessageW(&MStack_38);
      }
      return MStack_38.wParam;
    }
  }
  return 0;
}



/* 00025d04 FUN_00025d04 */

/* Boundary evidence: original MIPS .pdata 00025d04..00025dc3. Semantic name remains unreviewed. */

undefined4 FUN_00025d04(void)

{
  DWORD DVar1;
  wchar_t *pwVar2;
  
  if (DAT_00054be4 == (HANDLE)0xffffffff) {
    DAT_00054be4 = CreateFileW(L"PHM1:",0,0,(LPSECURITY_ATTRIBUTES)0x0,3,0x80,(HANDLE)0x0);
    if (DAT_00054be4 == (HANDLE)0xffffffff) {
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



/* 00025dc4 FUN_00025dc4 */

/* Boundary evidence: original MIPS .pdata 00025dc4..00025e13. Semantic name remains unreviewed. */

void FUN_00025dc4(void)

{
  if (DAT_00054be4 != -1) {
    CloseHandle((HANDLE)DAT_00054be4);
    DAT_00054be4 = -1;
  }
  return;
}



/* 00025e14 FUN_00025e14 */

/* Boundary evidence: original MIPS .pdata 00025e14..00025e67. Semantic name remains unreviewed. */

void FUN_00025e14(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  DWORD aDStack_20 [2];
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  
  local_18 = param_2;
  local_14 = param_1;
  local_10 = param_3;
  DeviceIoControl(DAT_00054be4,1,&local_18,0xc,(LPVOID)0x0,0,aDStack_20,(LPOVERLAPPED)0x0);
  return;
}



/* 00025e68 FUN_00025e68 */

/* Boundary evidence: original MIPS .pdata 00025e68..00025ebb. Semantic name remains unreviewed. */

void FUN_00025e68(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  DWORD aDStack_20 [2];
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  
  local_18 = param_1;
  local_14 = param_2;
  local_10 = param_3;
  DeviceIoControl(DAT_00054be4,2,&local_18,0xc,(LPVOID)0x0,0,aDStack_20,(LPOVERLAPPED)0x0);
  return;
}



/* 00025ebc FUN_00025ebc */

/* Boundary evidence: original MIPS .pdata 00025ebc..00025f0b. Semantic name remains unreviewed. */

void FUN_00025ebc(undefined4 param_1,undefined4 param_2)

{
  DWORD aDStack_20 [2];
  undefined1 auStack_18 [4];
  undefined4 local_14;
  undefined4 local_10;
  
  local_14 = param_1;
  local_10 = param_2;
  DeviceIoControl(DAT_00054be4,0,auStack_18,0xc,(LPVOID)0x0,0,aDStack_20,(LPOVERLAPPED)0x0);
  return;
}



/* 00025f0c FUN_00025f0c */

/* Boundary evidence: original MIPS .pdata 00025f0c..00025f53. Semantic name remains unreviewed. */

undefined4 * FUN_00025f0c(undefined4 *param_1)

{
  *param_1 = 0;
  memset(param_1 + 1,0,0x14);
  memset(param_1 + 6,0,0x8c);
  return param_1;
}



/* 00025f54 FUN_00025f54 */

/* Boundary evidence: original MIPS .pdata 00025f54..0002602b. Semantic name remains unreviewed. */

bool FUN_00025f54(undefined4 *param_1)

{
  HANDLE hFile;
  HANDLE hFile_00;
  _DCB _Stack_28;
  
  hFile = CreateFileW(L"COM2:",0xc0000000,0,(LPSECURITY_ATTRIBUTES)0x0,3,0x80,(HANDLE)0x0);
  *param_1 = hFile;
  if (hFile != (HANDLE)0xffffffff) {
    GetCommState(hFile,&_Stack_28);
    _Stack_28.BaudRate = 300000;
    _Stack_28.fNull = 0;
    _Stack_28.fParity = 0;
    _Stack_28.ByteSize = '\b';
    _Stack_28.Parity = '\0';
    _Stack_28.StopBits = '\0';
    SetCommState((HANDLE)*param_1,&_Stack_28);
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



/* 0002602c FUN_0002602c */

/* Boundary evidence: original MIPS .pdata 0002602c..00026063. Semantic name remains unreviewed. */

void FUN_0002602c(undefined4 *param_1)

{
  CloseHandle((HANDLE)*param_1);
  *param_1 = 0xffffffff;
  return;
}



/* 00026064 FUN_00026064 */

/* Boundary evidence: original MIPS .pdata 00026064..000260c3. Semantic name remains unreviewed. */

void FUN_00026064(undefined4 *param_1)

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



/* 000260c4 FUN_000260c4 */

/* Boundary evidence: original MIPS .pdata 000260c4..000261fb. Semantic name remains unreviewed. */

BOOL FUN_000260c4(undefined4 *param_1,byte param_2,char param_3,LPCVOID param_4)

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
    FUN_00026064(param_1);
  }
  return BVar1;
}



/* 000261fc FUN_000261fc */

/* Boundary evidence: original MIPS .pdata 000261fc..0002629b. Semantic name remains unreviewed. */

BOOL FUN_000261fc(undefined4 *param_1,byte *param_2)

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
    FUN_00026064(param_1);
  }
  return BVar1;
}



/* 0002629c FUN_0002629c */

/* Boundary evidence: original MIPS .pdata 0002629c..0002635b. Semantic name remains unreviewed. */

BOOL FUN_0002629c(undefined4 param_1,uint param_2,uint param_3,uint param_4,int param_5,byte param_6
                 )

{
  BOOL BVar1;
  uint uVar2;
  uint uVar3;
  uint local_98;
  undefined1 local_94 [136];
  uint local_c;
  
  local_c = DAT_00055374;
  uVar2 = (uint)param_6;
  local_98 = ((param_2 & 0xf | (param_4 & 0xff) << 4 | uVar2 << 0xc) << 4 | param_3 & 0xf) << 8 |
             0xaa;
  uVar3 = 0;
  if (uVar2 != 0) {
    do {
      local_94[uVar3] = *(undefined1 *)(uVar3 + param_5);
      uVar3 = uVar3 + 1 & 0xff;
    } while (uVar3 < uVar2);
  }
  BVar1 = FUN_000261fc((undefined4 *)&DAT_00055638,(byte *)&local_98);
  FUN_00043604(local_c);
  return BVar1;
}



/* 0002635c FUN_0002635c */

/* Boundary evidence: original MIPS .pdata 0002635c..00026637. Semantic name remains unreviewed. */

undefined4 FUN_0002635c(undefined4 *param_1,byte *param_2)

{
  bool bVar1;
  BOOL BVar2;
  HANDLE pvVar3;
  uint uVar4;
  wchar_t *pwVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  LPCOMMTIMEOUTS lpCommTimeouts;
  char local_70 [4];
  uint local_6c;
  _COMMPROP _Stack_68;
  uint local_28;
  
  local_28 = DAT_00055374;
  lpCommTimeouts = (LPCOMMTIMEOUTS)(param_1 + 1);
  pvVar3 = (HANDLE)*param_1;
  lpCommTimeouts->ReadIntervalTimeout = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  SetCommTimeouts(pvVar3,lpCommTimeouts);
  iVar9 = 1;
  BVar2 = ReadFile((HANDLE)*param_1,local_70,1,&local_6c,(LPOVERLAPPED)0x0);
  if (BVar2 != 0) {
    if (local_70[0] == -0x5a) {
      *param_2 = 0xa6;
LAB_00026608:
      FUN_00043604(local_28);
      return 1;
    }
    if (local_70[0] == -0x56) {
      *param_2 = 0xaa;
      pvVar3 = (HANDLE)*param_1;
      lpCommTimeouts->ReadIntervalTimeout = 2;
      param_1[2] = 6;
      param_1[3] = 1;
      SetCommTimeouts(pvVar3,lpCommTimeouts);
      BVar2 = ReadFile((HANDLE)*param_1,param_2 + 1,3,&local_6c,(LPOVERLAPPED)0x0);
      if (BVar2 != 0) {
        if (local_6c != 3) goto LAB_000263e0;
        param_1[2] = (param_2[3] + 1) * 2;
        SetCommTimeouts((HANDLE)*param_1,lpCommTimeouts);
        BVar2 = ReadFile((HANDLE)*param_1,param_2 + 4,param_2[3] + 1,&local_6c,(LPOVERLAPPED)0x0);
        if (BVar2 != 0) {
          GetCommProperties((HANDLE)*param_1,&_Stack_68);
          uVar4 = (uint)param_2[3];
          uVar6 = uVar4 + 1;
          if (local_6c == uVar6) {
            uVar6 = (uint)*param_2;
            bVar1 = 1 < uVar4 + 4;
            iVar8 = 1;
            uVar7 = uVar6;
            if (bVar1) {
              do {
                uVar7 = param_2[iVar8] ^ uVar7;
                iVar8 = iVar8 + 1;
              } while (iVar8 < (int)(param_2[3] + 4));
            }
            local_6c = (uint)param_2[uVar4 + 4];
            if (local_6c == uVar7) goto LAB_00026608;
            if (bVar1) {
              do {
                uVar6 = param_2[iVar9] ^ uVar6;
                iVar9 = iVar9 + 1;
              } while (iVar9 < (int)(param_2[3] + 4));
            }
            pwVar5 = L"%S : Checksum Error 0x%02:0x%02\r\n";
          }
          else {
            pwVar5 = L"%S : Data Length Error : %d/%d\r\n";
          }
          NKDbgPrintfW(pwVar5,"CProtocol::ReadCommand",local_6c,uVar6);
          goto LAB_000263e0;
        }
      }
    }
    else {
      if (local_70[0] != -0x55) {
        NKDbgPrintfW(L"%S : Data Error? 0x%02X\r\n","CProtocol::ReadCommand");
        goto LAB_000263e0;
      }
      *param_2 = 0xab;
      pvVar3 = (HANDLE)*param_1;
      lpCommTimeouts->ReadIntervalTimeout = 2;
      param_1[2] = 2;
      param_1[3] = 1;
      SetCommTimeouts(pvVar3,lpCommTimeouts);
      BVar2 = ReadFile((HANDLE)*param_1,param_2 + 1,1,&local_6c,(LPOVERLAPPED)0x0);
      if (BVar2 != 0) {
        if (local_6c == 1) goto LAB_00026608;
        goto LAB_000263e0;
      }
    }
  }
  FUN_00026064(param_1);
LAB_000263e0:
  FUN_00043604(local_28);
  return 0;
}



/* 00026638 FUN_00026638 */

/* Boundary evidence: original MIPS .pdata 00026638..00026657. Semantic name remains unreviewed. */

void FUN_00026638(int param_1,void *param_2)

{
  memcpy((void *)(param_1 + 0x18),param_2,0x8c);
  return;
}



/* 00026658 FUN_00026658 */

/* Boundary evidence: original MIPS .pdata 00026658..0002668b. Semantic name remains unreviewed. */

void * FUN_00026658(int param_1,void *param_2)

{
  memcpy(param_2,(void *)(param_1 + 0x18),0x8c);
  return param_2;
}



/* 0002668c FUN_0002668c */

/* Boundary evidence: original MIPS .pdata 0002668c..000266cf. Semantic name remains unreviewed. */

undefined4 * FUN_0002668c(undefined4 *param_1)

{
  *param_1 = 0;
  param_1[1] = 1;
  param_1[2] = 0;
  memset(param_1 + 3,0,0x1a40);
  return param_1;
}



/* 000266d0 FUN_000266d0 */

int FUN_000266d0(int param_1)

{
  return *(int *)(param_1 + 4) * 0x8c + param_1 + 0xc;
}



/* 000266ec FUN_000266ec */

/* Boundary evidence: original MIPS .pdata 000266ec..00026747. Semantic name remains unreviewed. */

undefined4 FUN_000266ec(int param_1)

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



/* 00026748 FUN_00026748 */

int * FUN_00026748(int *param_1)

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



/* 0002679c FUN_0002679c */

/* Boundary evidence: original MIPS .pdata 0002679c..00026893. Semantic name remains unreviewed. */

undefined4 *
FUN_0002679c(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  FUN_0002d7e0(param_1,param_2,param_3);
  *param_1 = &PTR_FUN_0004d380;
  param_1[0x11] = param_4;
  param_1[0x17] = 0;
  param_1[0xa4] = 0;
  memset(param_1 + 0x18,0,0x80);
  memset(param_1 + 0x38,0,0xd8);
  memset(param_1 + 3,0,0x20);
  param_1[0x73] = 0xffffffff;
  param_1[0x16] = 0;
  param_1[0x13] = 0;
  param_1[0x14] = 0;
  param_1[0x15] = 0;
  param_1[0x6f] = 2;
  param_1[0x70] = 0;
  *(undefined2 *)(param_1 + 0x72) = 0;
  *(undefined2 *)(param_1 + 0xb) = 0;
  *(undefined2 *)((int)param_1 + 0x2e) = 0;
  *(undefined2 *)(param_1 + 0xc) = 0;
  *(undefined2 *)((int)param_1 + 0x32) = 0;
  *(undefined2 *)(param_1 + 0xd) = 0;
  param_1[0x6e] = 0;
  *(undefined1 *)(param_1 + 0x80) = 0;
  *(undefined1 *)(param_1 + 0x90) = 0;
  param_1[0x76] = 0;
  param_1[0x77] = 0;
  param_1[0xa1] = 0;
  param_1[0x7e] = 0;
  param_1[0x7f] = 0;
  param_1[0x7a] = 0;
  param_1[0x7b] = 0;
  param_1[0x7c] = 0;
  param_1[0xa0] = 0;
  param_1[0xa2] = 100000;
  return param_1;
}



/* 00026894 FUN_00026894 */

/* Boundary evidence: original MIPS .pdata 00026894..000268cf. Semantic name remains unreviewed. */

void FUN_00026894(int param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  
  iVar1 = 2;
  if (param_3 != 1) {
    iVar1 = 0;
  }
  FUN_00033a24((undefined4 *)(param_1 + 0x60),param_2,(uint)(param_4 == 1) + iVar1);
  return;
}



/* 000268d0 FUN_000268d0 */

/* Boundary evidence: original MIPS .pdata 000268d0..0002695f. Semantic name remains unreviewed. */

void FUN_000268d0(int param_1,undefined4 param_2,UINT param_3)

{
  NKDbgPrintfW(L"%S(nID=%d,nTout=%d)\r\n","CRadio::SetTimer",param_2,param_3);
  if (*(int *)(param_1 + 0x48) != 0) {
    NKDbgPrintfW(L"%S : Timer is already started. Check it out.!!!!!!!!!!!(OLD:%d, NEW:%d)\r\n",
                 "CRadio::SetTimer",*(int *)(param_1 + 0x48),param_2);
  }
  *(undefined4 *)(param_1 + 0x48) = param_2;
  FUN_0002d814(param_1,param_3);
  return;
}



/* 00026960 FUN_00026960 */

/* Boundary evidence: original MIPS .pdata 00026960..000269e7. Semantic name remains unreviewed. */

void FUN_00026960(int param_1,int param_2)

{
  NKDbgPrintfW(L"%S(nID=%d)\r\n","CRadio::KillTimer",param_2);
  if ((param_2 == 0) || (*(int *)(param_1 + 0x48) == param_2)) {
    *(undefined4 *)(param_1 + 0x48) = 0;
    FUN_0002d83c(param_1);
  }
  else {
    NKDbgPrintfW(L"%S : Already Killed or another timer running.\r\n","CRadio::KillTimer");
  }
  return;
}



/* 000269e8 FUN_000269e8 */

/* Boundary evidence: original MIPS .pdata 000269e8..00026c1b. Semantic name remains unreviewed. */

void FUN_000269e8(int param_1,uint param_2)

{
  int iVar1;
  bool bVar2;
  undefined4 uVar3;
  undefined3 extraout_var;
  int iVar4;
  undefined8 uVar5;
  undefined1 local_28;
  undefined1 local_27;
  
  if ((param_2 < 0xc) && (*(int *)(param_1 + 0x50) != 3)) {
    iVar1 = param_2 * 0x18;
    (&DAT_0005737c)[param_2 * 6 + *(int *)(param_1 + 0x1bc) * 0x123] =
         *(undefined4 *)(param_1 + 0x1c0);
    (&DAT_00057378)[param_2 * 0xc + *(int *)(param_1 + 0x1bc) * 0x246] =
         *(undefined2 *)(param_1 + 0x1c8);
    (&DAT_0005736c)[*(int *)(param_1 + 0x1bc) * 0x48c] = (char)param_2;
    iVar4 = *(int *)(param_1 + 0x1bc);
    if (iVar4 == 1) {
      sprintf_s(&DAT_0005780c + iVar1,0x10,"%dkHz",*(undefined4 *)(param_1 + 0x1c0));
    }
    else if (*(ushort *)(param_1 + 0x1c8) == 0) {
      uVar3 = __ultofp(*(undefined4 *)(param_1 + 0x1c0));
      uVar5 = __fptodp(uVar3);
      __dpmul((int)uVar5,(int)((ulonglong)uVar5 >> 0x20),0xd2f1a9fc,0x3f50624d);
      sprintf_s(&DAT_00057380 + iVar4 * 0x48c + iVar1,0x10,"%6.2fMHz");
    }
    else {
      FUN_0002e27c(DAT_00057348,(uint)*(ushort *)(param_1 + 0x1c8),
                   (undefined4 *)(&DAT_00057380 + iVar4 * 0x48c + iVar1));
    }
    *(uint *)(param_1 + 0x1d0) = param_2;
    *(char *)(*(int *)(param_1 + 0x44) + 0x613) = (char)param_2;
    FUN_0002f6e8(*(int *)(param_1 + 0x1bc),param_2);
    if ((*(int *)(DAT_00055384 + 0x4c) == 0) &&
       (bVar2 = FUN_0001d9b4(DAT_00055498), CONCAT31(extraout_var,bVar2) == 0)) {
      local_27 = (undefined1)(DAT_00057364 & 0x3f);
      local_28 = 3;
      if ((DAT_00057364 & 0x3f) < 10) {
        local_27 = 10;
      }
      FUN_00015f10(DAT_000553cc,5,1,0x40,(int)&local_28,2,100);
    }
  }
  return;
}



/* 00026c1c FUN_00026c1c */

/* Boundary evidence: original MIPS .pdata 00026c1c..00026cd7. Semantic name remains unreviewed. */

void FUN_00026c1c(int param_1)

{
  int iVar1;
  
  *(undefined4 *)(param_1 + 0x1ec) = 0;
  *(undefined4 *)(param_1 + 0x1f0) = 0;
  if (((*(int *)(param_1 + 0x50) == 5) && (iVar1 = *(int *)(param_1 + 0x1d8), iVar1 != 0)) &&
     ((iVar1 == 1 || ((iVar1 == 2 && (*(int *)(param_1 + 0x48) != 2)))))) {
    FUN_00026960(param_1,6);
    if ((*(int *)(param_1 + 0x1dc) == 0) || (*(int *)(param_1 + 0x1d8) != 1)) {
      FUN_000268d0(param_1,5,500);
    }
    else {
      *(undefined4 *)(param_1 + 0x1d8) = 0;
      FUN_000338ac(0x6d,*(int *)(param_1 + 0x1dc) + 2);
    }
  }
  *(undefined4 *)(param_1 + 0x1f8) = 0;
  return;
}



/* 00026cd8 FUN_00026cd8 */

/* Boundary evidence: original MIPS .pdata 00026cd8..00026d77. Semantic name remains unreviewed. */

void FUN_00026cd8(int param_1,undefined4 param_2)

{
  uint uVar1;
  
  uVar1 = *(uint *)(param_1 + 0x54);
  *(undefined4 *)(param_1 + 0x1b8) = param_2;
  if (uVar1 == 2) {
    NKDbgPrintfW(L"%S(nID=%d)\r\n","CRadio::KillTimer",0);
    *(undefined4 *)(param_1 + 0x48) = 0;
    FUN_0002d83c(param_1);
  }
  else {
    if (uVar1 < 3) {
      return;
    }
    if (4 < uVar1) {
      return;
    }
    FUN_00015f10(DAT_000553cc,3,1,7,0,0,0x32);
  }
  *(undefined4 *)(param_1 + 0x54) = 0;
  return;
}



/* 00026d78 FUN_00026d78 */

undefined4 FUN_00026d78(int param_1)

{
  return *(undefined4 *)(param_1 + 0x1c0);
}



/* 00026d80 FUN_00026d80 */

undefined2 FUN_00026d80(int param_1)

{
  return *(undefined2 *)(param_1 + 0x1c8);
}



/* 00026d88 FUN_00026d88 */

undefined4 FUN_00026d88(int param_1,undefined4 *param_2)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x44);
  *param_2 = *(undefined4 *)(iVar1 + 0x617);
  param_2[1] = *(undefined4 *)(iVar1 + 0x61b);
  return 8;
}



/* 00026db8 FUN_00026db8 */

/* Boundary evidence: original MIPS .pdata 00026db8..00026e3b. Semantic name remains unreviewed. */

void FUN_00026db8(int param_1)

{
  if ((*(int *)(param_1 + 0x4c) == 1) &&
     ((*(int *)(param_1 + 0x50) != 5 || (*(int *)(param_1 + 0x1d8) != 2)))) {
    *(undefined4 *)(*(int *)(param_1 + 0x44) + 8) = *(undefined4 *)(param_1 + 0x1c0);
    FUN_000338ac(0x65,*(LPARAM *)(param_1 + 0x1c0));
    if (*(HWND *)(param_1 + 0x5c) != (HWND)0x0) {
      PostMessageW(*(HWND *)(param_1 + 0x5c),0x403,0,*(LPARAM *)(param_1 + 0x1c0));
    }
  }
  return;
}



/* 00026e3c FUN_00026e3c */

uint FUN_00026e3c(int param_1)

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



/* 00026eac FUN_00026eac */

/* Boundary evidence: original MIPS .pdata 00026eac..00026f0b. Semantic name remains unreviewed. */

void FUN_00026eac(int param_1)

{
  *(undefined1 *)(param_1 + 0x200) = 0;
  *(undefined1 *)(param_1 + 0x240) = 0;
  *(undefined1 *)(*(int *)(param_1 + 0x44) + 0x617) = 0;
  *(undefined1 *)(*(int *)(param_1 + 0x44) + 0x615) = 0;
  *(undefined1 *)(*(int *)(param_1 + 0x44) + 0x623) = 0;
  *(undefined4 *)(param_1 + 0x1d8) = 0;
  *(undefined4 *)(param_1 + 0x1dc) = 0;
  FUN_000338ac(0x6a,0);
  FUN_000338ac(0x6b,0);
  FUN_000338ac(0x6c,0);
  return;
}



/* 00026f0c FUN_00026f0c */

/* Boundary evidence: original MIPS .pdata 00026f0c..00027123. Semantic name remains unreviewed. */

void FUN_00026f0c(int param_1)

{
  ushort uVar1;
  uint uVar2;
  int iVar3;
  int *piVar4;
  ushort *puVar5;
  uint uVar6;
  uint uVar7;
  
  iVar3 = *(int *)(param_1 + 0x1bc);
  uVar6 = (uint)(byte)(&DAT_0005736c)[iVar3 * 0x48c];
  if ((DAT_00057354 & 2) == 2) {
    uVar1 = *(ushort *)(param_1 + 0x1c8);
    uVar2 = 0xc;
    uVar7 = 0;
    if (uVar1 == 0) {
      piVar4 = &DAT_0005737c + iVar3 * 0x123;
      do {
        if (((short)piVar4[-1] == 0) && (*piVar4 == *(int *)(param_1 + 0x1c0))) {
          if ((uVar6 < 0xc) &&
             (((&DAT_00057378)[iVar3 * 0x246 + uVar6 * 0xc] == 0 &&
              ((&DAT_0005737c)[iVar3 * 0x123 + uVar6 * 6] == *(int *)(param_1 + 0x1c0))))) {
            uVar7 = uVar6;
          }
          break;
        }
        uVar7 = uVar7 + 1;
        piVar4 = piVar4 + 6;
      } while (uVar7 < 0xc);
    }
    else {
      puVar5 = &DAT_00057378 + iVar3 * 0x246;
      do {
        if (*puVar5 == uVar1) {
          if ((uVar6 < 0xc) && ((&DAT_00057378)[iVar3 * 0x246 + uVar6 * 0xc] == uVar1)) {
            uVar7 = uVar6;
          }
          break;
        }
        if ((uVar2 == 0xc) && (((*puVar5 ^ uVar1) & 0xf0ff) == 0)) {
          uVar2 = uVar7;
        }
        uVar7 = uVar7 + 1;
        puVar5 = puVar5 + 0xc;
      } while (uVar7 < 0xc);
    }
    if (uVar7 < 0xc) {
      *(uint *)(param_1 + 0x1d0) = uVar7;
    }
    else {
      *(uint *)(param_1 + 0x1d0) = uVar2;
    }
  }
  else {
    uVar2 = 0;
    piVar4 = &DAT_0005737c + iVar3 * 0x123;
    do {
      if (*piVar4 == *(int *)(param_1 + 0x1c0)) {
        if ((uVar6 < 0xc) &&
           ((&DAT_0005737c)[iVar3 * 0x123 + uVar6 * 6] == *(int *)(param_1 + 0x1c0))) {
          uVar2 = uVar6;
        }
        break;
      }
      uVar2 = uVar2 + 1;
      piVar4 = piVar4 + 6;
    } while (uVar2 < 0xc);
    *(uint *)(param_1 + 0x1d0) = uVar2;
  }
  *(char *)(*(int *)(param_1 + 0x44) + 0x613) = (char)*(undefined4 *)(param_1 + 0x1d0);
  FUN_000338ac(0x66,0);
  return;
}



/* 00027124 FUN_00027124 */

/* Boundary evidence: original MIPS .pdata 00027124..000272d7. Semantic name remains unreviewed. */

void FUN_00027124(int param_1)

{
  ushort uVar1;
  uint uVar2;
  int *piVar3;
  int iVar4;
  uint uVar5;
  ushort *puVar6;
  
  if ((DAT_00057354 & 2) == 2) {
    uVar1 = *(ushort *)(param_1 + 0x1c8);
    uVar5 = 0x24;
    uVar2 = 0;
    if (uVar1 == 0) {
      iVar4 = *(int *)(param_1 + 0x1bc) * 0x48c;
      piVar3 = &DAT_0005749c + *(int *)(param_1 + 0x1bc) * 0x123;
      do {
        if (((short)piVar3[-1] == 0) && (*piVar3 == *(int *)(param_1 + 0x1c0))) break;
        uVar2 = uVar2 + 1;
        piVar3 = piVar3 + 6;
      } while (uVar2 < 0x24);
    }
    else {
      iVar4 = *(int *)(param_1 + 0x1bc) * 0x48c;
      puVar6 = &DAT_00057498 + *(int *)(param_1 + 0x1bc) * 0x246;
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
      *(uint *)(param_1 + 0x1d4) = uVar2;
    }
    else {
      *(uint *)(param_1 + 0x1d4) = uVar5;
    }
  }
  else {
    iVar4 = *(int *)(param_1 + 0x1bc) * 0x48c;
    uVar5 = 0;
    piVar3 = &DAT_0005749c + *(int *)(param_1 + 0x1bc) * 0x123;
    do {
      if (*piVar3 == *(int *)(param_1 + 0x1c0)) break;
      uVar5 = uVar5 + 1;
      piVar3 = piVar3 + 6;
    } while (uVar5 < 0x24);
    *(uint *)(param_1 + 0x1d4) = uVar5;
  }
  uVar5 = *(uint *)(param_1 + 0x1d4);
  if (uVar5 < 0x24) {
    iVar4 = uVar5 * 0x18 + iVar4;
    NKDbgPrintfW(L"\n\n [ Freauency = %d  ] [ List Index = %d] [ PSN = %S] [PI 0x%04x)\n\n",
                 *(undefined4 *)((int)&DAT_0005749c + iVar4),uVar5,&DAT_000574a0 + iVar4,
                 *(undefined2 *)(param_1 + 0x1c8));
  }
  if ((uint)*(byte *)(*(int *)(param_1 + 0x44) + 0x614) != *(uint *)(param_1 + 0x1d4)) {
    *(char *)(*(int *)(param_1 + 0x44) + 0x614) = (char)*(uint *)(param_1 + 0x1d4);
    FUN_000338ac(0x66,0);
  }
  return;
}



/* 000272d8 FUN_000272d8 */

/* Boundary evidence: original MIPS .pdata 000272d8..00027433. Semantic name remains unreviewed. */

void FUN_000272d8(undefined4 param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  undefined4 uVar3;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  uint local_1c;
  
  local_1c = DAT_00055374;
  memset(&uStack_40,0,0x24);
  uVar3 = 3;
  if (param_2 != 1) {
    uVar3 = 4;
  }
  uVar2 = 0;
  do {
    uVar1 = FUN_00016068(DAT_000553cc,3,uVar3,&uStack_40,0x24,300);
    if (uVar1 == 0x24) break;
    uVar2 = uVar2 + 1;
  } while (uVar2 < 3);
  if (uVar2 < 3) {
    FUN_0002ec30(DAT_00057348,uStack_40,uStack_3c,uStack_38);
  }
  else {
    NKDbgPrintfW(L"%S : Can\'t read Station Info\r\n","CRadio::UpdateStationInfo");
  }
  FUN_00043604(local_1c);
  return;
}



/* 00027434 FUN_00027434 */

undefined4 FUN_00027434(int param_1)

{
  undefined4 uVar1;
  
  if ((0 < *(int *)(param_1 + 0x1d8)) || (uVar1 = 0, 0 < *(int *)(param_1 + 0x1dc))) {
    uVar1 = 1;
  }
  return uVar1;
}



/* 00027458 FUN_00027458 */

void FUN_00027458(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x1bc) * 0x48c;
  if (param_2 == 0) {
    (&DAT_0005736c)[iVar1] = (char)*(undefined4 *)(param_1 + 0x1d0);
  }
  else {
    *(undefined4 *)(param_1 + 0x1d0) = 0xc;
    (&DAT_0005736c)[iVar1] = 0xc;
  }
  if ((DAT_00057354 & 2) == 2) {
    (&DAT_00057370)[*(int *)(param_1 + 0x1bc) * 0x246] = *(undefined2 *)(param_1 + 0x1c8);
  }
  else {
    (&DAT_00057370)[*(int *)(param_1 + 0x1bc) * 0x246] = 0;
  }
  (&DAT_00057374)[*(int *)(param_1 + 0x1bc) * 0x123] = *(undefined4 *)(param_1 + 0x1c0);
  return;
}



/* 00027500 FUN_00027500 */

/* Boundary evidence: original MIPS .pdata 00027500..00027653. Semantic name remains unreviewed. */

void FUN_00027500(int param_1)

{
  ushort uVar1;
  int iVar2;
  uint uVar3;
  
  uVar3 = DAT_00057354 >> 0xb & 3;
  *(uint *)(param_1 + 0x1bc) = uVar3;
  *(uint *)(param_1 + 0x1d0) = (uint)(byte)(&DAT_0005736c)[uVar3 * 0x48c];
  if ((DAT_00057354 & 2) == 2) {
    uVar1 = (&DAT_00057370)[*(int *)(param_1 + 0x1bc) * 0x246];
    *(ushort *)(param_1 + 0x1c8) = uVar1;
    *(undefined4 *)(param_1 + 0x1c0) = 0;
    if (uVar1 != 0) {
      iVar2 = FUN_0002e300(DAT_00057348,(uint)uVar1);
      *(int *)(param_1 + 0x1c0) = iVar2;
    }
    if (*(int *)(param_1 + 0x1c0) == 0) {
      *(undefined4 *)(param_1 + 0x1c0) = (&DAT_00057374)[*(int *)(param_1 + 0x1bc) * 0x123];
    }
  }
  else {
    *(undefined2 *)(param_1 + 0x1c8) = 0;
    *(undefined4 *)(param_1 + 0x1c0) = (&DAT_00057374)[*(int *)(param_1 + 0x1bc) * 0x123];
  }
  *(char *)(*(int *)(param_1 + 0x44) + 0x613) = (char)*(undefined4 *)(param_1 + 0x1d0);
  *(char *)(*(int *)(param_1 + 0x44) + 4) = (char)*(undefined4 *)(param_1 + 0x1bc);
  *(undefined4 *)(*(int *)(param_1 + 0x44) + 8) = *(undefined4 *)(param_1 + 0x1c0);
  if (*(ushort *)(param_1 + 0x1c8) == 0) {
    *(undefined1 *)(*(int *)(param_1 + 0x44) + 0x617) = 0;
  }
  else {
    FUN_0002e27c(DAT_00057348,(uint)*(ushort *)(param_1 + 0x1c8),
                 (undefined4 *)(*(int *)(param_1 + 0x44) + 0x617));
  }
  FUN_000338ac(0x6a,0);
  FUN_00027124(param_1);
  return;
}



/* 00027654 FUN_00027654 */

/* Boundary evidence: original MIPS .pdata 00027654..00027913. Semantic name remains unreviewed. */

void FUN_00027654(int param_1,int param_2,int param_3)

{
  uint uVar1;
  int iVar2;
  uint *puVar3;
  
  iVar2 = *(int *)(param_1 + 0x50);
  if ((iVar2 == 3) || (iVar2 == 4)) {
    NKDbgPrintfW(L"%S : SubMode is SEEK or AST(%d)\r\n","CRadio::StartSubModeTune");
  }
  else {
    if (iVar2 != 2) goto LAB_000276dc;
    FUN_00026960(param_1,1);
  }
  *(undefined4 *)(param_1 + 0x50) = 0;
LAB_000276dc:
  if (*(int *)(param_1 + 0x50) != 0) {
    NKDbgPrintfW(L"%S : SubMode is not NONE. Current SubMode=%d!!!!!!!!!!\r\n",
                 "CRadio::StartSubModeTune");
  }
  puVar3 = (uint *)(param_1 + 0x1c0);
  NKDbgPrintfW(L"%S : CurPI=%04X, CurFreq=%d)\r\n","CRadio::StartSubModeTune",
               *(undefined2 *)(param_1 + 0x1c8),*puVar3);
  if (param_3 == 1) {
    *(undefined4 *)(param_1 + 0x50) = 9;
  }
  else {
    *(undefined4 *)(param_1 + 0x50) = 1;
  }
  *(undefined4 *)(param_1 + 0x1cc) = 0xffffffff;
  if (*(int *)(param_1 + 0x1bc) == 0) {
    iVar2 = FUN_0002ebb0(DAT_00057348,(uint)*(ushort *)(param_1 + 0x1c8),*puVar3);
    *(int *)(param_1 + 0x1cc) = iVar2;
    if (-1 < iVar2) {
      uVar1 = FUN_0002e36c(DAT_00057348);
      *puVar3 = uVar1;
    }
  }
  if (*(int *)(param_1 + 0x1cc) < 0) {
    uVar1 = FUN_00026e3c(param_1);
    iVar2 = *(int *)((uVar1 + 5) * 0x14 + *(int *)(param_1 + 0x1bc) * 0x40 + param_1);
    if (iVar2 == 0) {
      FUN_00015f10(DAT_000553cc,3,1,0x33,(int)puVar3,4,100);
    }
    else if (iVar2 == 1) {
      FUN_00015f10(DAT_000553cc,3,1,0x34,(int)puVar3,4,100);
    }
    else if (iVar2 == 4) {
      FUN_00015f10(DAT_000553cc,3,1,0x32,(int)puVar3,4,100);
    }
  }
  else {
    iVar2 = FUN_0002e454(DAT_00057348);
    if (param_2 == 1) {
      FUN_00015f10(DAT_000553cc,3,1,0x31,iVar2,0x24,100);
    }
    else {
      FUN_00015f10(DAT_000553cc,3,1,0x30,iVar2,0x24,100);
    }
  }
  if (*(int *)(param_1 + 0x1e4) == 1) {
    FUN_000272d8(param_1,0);
    *(undefined4 *)(param_1 + 0x1e4) = 0;
  }
  if (*(short *)(param_1 + 0x1c8) != 0) {
    *(undefined4 *)(param_1 + 0x1e4) = 1;
  }
  *(undefined4 *)(param_1 + 0x1f0) = 0;
  *(undefined4 *)(param_1 + 0x1ec) = 0;
  *(undefined4 *)(param_1 + 500) = 0;
  FUN_00026f0c(param_1);
  FUN_00027124(param_1);
  return;
}



/* 00027914 FUN_00027914 */

/* Boundary evidence: original MIPS .pdata 00027914..00027c7f. Semantic name remains unreviewed. */

void FUN_00027914(int param_1,int param_2)

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
  
  local_28 = DAT_00055374;
  bVar3 = false;
  bVar2 = true;
  if (*(int *)(param_1 + 0x50) != 3) {
    if (*(int *)(param_1 + 0x50) != 2) goto LAB_00027988;
    FUN_00026960(param_1,1);
    bVar3 = true;
  }
  bVar2 = false;
  *(undefined4 *)(param_1 + 0x50) = 0;
LAB_00027988:
  if (*(int *)(param_1 + 0x50) != 0) {
    NKDbgPrintfW(L"%S : SubMode is not NONE. Current SubMode=%d!!!!!!!!!!\r\n",
                 "CRadio::StartSubModeSeek");
  }
  NKDbgPrintfW(L"%S : CurPI=%04X, CurFreq=%d)\r\n","CRadio::StartSubModeSeek",
               *(undefined2 *)(param_1 + 0x1c8),*(undefined4 *)(param_1 + 0x1c0));
  *(undefined4 *)(param_1 + 0x50) = 3;
  *(undefined2 *)(param_1 + 0x1c8) = 0;
  *(undefined4 *)(param_1 + 0x1cc) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x1d0) = 0xc;
  *(undefined4 *)(param_1 + 0x1d4) = 0x24;
  if (bVar2) {
    *(undefined4 *)(param_1 + 0x1c4) = *(undefined4 *)(param_1 + 0x1c0);
  }
  uVar4 = FUN_00026e3c(param_1);
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
    FUN_00015f10(DAT_000553cc,3,1,1,(int)&local_68,0x14,100);
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
    FUN_00015f10(DAT_000553cc,3,1,2,(int)local_50,0x28,100);
  }
  *(char *)(*(int *)(param_1 + 0x44) + 0x613) = (char)*(undefined4 *)(param_1 + 0x1d0);
  *(char *)(*(int *)(param_1 + 0x44) + 0x614) = (char)*(undefined4 *)(param_1 + 0x1d4);
  if (*(int *)(param_1 + 0x1e4) == 1) {
    FUN_000272d8(param_1,0);
    *(undefined4 *)(param_1 + 0x1e4) = 0;
  }
  *(undefined4 *)(param_1 + 0x1f0) = 0;
  *(undefined4 *)(param_1 + 0x1ec) = 0;
  *(undefined4 *)(param_1 + 500) = 0;
  if (bVar3) {
    FUN_00015f10(DAT_000553cc,3,1,0x21,0,0,100);
  }
  FUN_00043604(local_28);
  return;
}



/* 00027c80 FUN_00027c80 */

/* Boundary evidence: original MIPS .pdata 00027c80..00027dcf. Semantic name remains unreviewed. */

void FUN_00027c80(int param_1)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  char local_60 [68];
  uint local_1c;
  
  local_1c = DAT_00055374;
  iVar6 = 0;
  iVar5 = 0;
  memcpy(local_60,(void *)(*(int *)(param_1 + 0x44) + 0x623),0x40);
  uVar2 = 0;
  do {
    iVar3 = uVar2 + *(int *)(param_1 + 0x44);
    uVar2 = uVar2 + 1;
    *(undefined1 *)(iVar3 + 0x623) = 0;
  } while (uVar2 < 0x44);
  uVar2 = 0;
  do {
    cVar1 = local_60[uVar2];
    if ((((cVar1 != ' ') && (cVar1 != '\0')) && (cVar1 != '\n')) && (cVar1 != '\r')) break;
    uVar2 = uVar2 + 1;
    iVar6 = iVar6 + 1;
  } while (uVar2 < 0x40);
  iVar3 = 0x3f;
  do {
    cVar1 = local_60[iVar3];
    if (((cVar1 != ' ') && (cVar1 != '\0')) && ((cVar1 != '\n' && (cVar1 != '\r')))) break;
    iVar3 = iVar3 + -1;
    iVar5 = iVar5 + 1;
  } while (iVar3 != 0);
  uVar2 = 0;
  if (iVar5 != 0x40) {
    do {
      iVar3 = uVar2 + iVar6;
      iVar4 = uVar2 + *(int *)(param_1 + 0x44);
      uVar2 = uVar2 + 1;
      *(char *)(iVar4 + 0x623) = local_60[iVar3];
    } while (uVar2 < 0x40U - iVar5);
  }
  FUN_00043604(local_1c);
  return;
}



/* 00027dd0 FUN_00027dd0 */

/* Boundary evidence: original MIPS .pdata 00027dd0..00028af7. Semantic name remains unreviewed. */

void FUN_00027dd0(int param_1,int param_2)

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
  
  local_30 = DAT_00055374;
  local_70 = '\0';
  memset(auStack_6f,0,0xf);
  uVar8 = 0;
  do {
    _snprintf_s(&DAT_00058364 + uVar8,0x10,0xf,"%s",
                &DAT_000574a0 + *(int *)(param_1 + 0x1bc) * 0x48c + uVar8);
    *(undefined2 *)((int)&DAT_0005835c + uVar8) =
         *(undefined2 *)((int)&DAT_00057498 + *(int *)(param_1 + 0x1bc) * 0x48c + uVar8);
    uVar12 = uVar8 + 0x18;
    *(undefined4 *)((int)&DAT_00058360 + uVar8) =
         *(undefined4 *)((int)&DAT_0005749c + *(int *)(param_1 + 0x1bc) * 0x48c + uVar8);
    uVar8 = uVar12;
  } while (uVar12 < 0x360);
  uVar12 = 0;
  uVar8 = 0;
  do {
    uVar12 = uVar12 + 1;
    if (uVar12 < 0x24) {
      piVar9 = (int *)((int)&DAT_00058378 + uVar8);
      iVar16 = 0x24 - uVar12;
      do {
        if ((*(int *)(param_1 + 0x1bc) == 0) && (param_2 == 1)) {
          if (((*(int *)((int)&DAT_00058360 + uVar8) == *piVar9) ||
              (*(short *)((int)&DAT_0005835c + uVar8) == (short)piVar9[-1])) &&
             (*(short *)((int)&DAT_0005835c + uVar8) != 0)) {
            *(short *)((int)&DAT_0005835c + uVar8) = 0;
            *(int *)((int)&DAT_00058360 + uVar8) = 0;
LAB_00027fa0:
            (&DAT_00058364)[uVar8] = 0;
          }
        }
        else if (((param_2 == 0) || (*(int *)(param_1 + 0x1bc) == 1)) &&
                (*(int *)((int)&DAT_00058360 + uVar8) == *piVar9)) {
          *(undefined2 *)((int)&DAT_0005835c + uVar8) = 0;
          *(int *)((int)&DAT_00058360 + uVar8) = 0;
          goto LAB_00027fa0;
        }
        iVar16 = iVar16 + -1;
        piVar9 = piVar9 + 6;
      } while (iVar16 != 0);
    }
    uVar8 = uVar8 + 0x18;
  } while (uVar8 < 0x348);
  if ((*(int *)(param_1 + 0x1bc) == 0) && (param_2 == 1)) {
    DAT_00057c8c = 0;
    DAT_00057c90 = 0;
    DAT_00057c94 = 0;
    DAT_00057c98 = 0;
    uVar12 = 0;
    uVar8 = 0;
    do {
      uVar12 = uVar12 + 1;
      if (uVar12 < 0x24) {
        _DstBuf = &DAT_0005837c + uVar8;
        pcVar10 = &DAT_00058364 + uVar8;
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
            *(undefined2 *)(_DstBuf + -8) = *(undefined2 *)((int)&DAT_0005835c + uVar8);
            *(undefined4 *)(_DstBuf + -4) = *(undefined4 *)((int)&DAT_00058360 + uVar8);
            _snprintf_s(pcVar10,0x10,0xf,"%s",&local_70);
            *(undefined4 *)((int)&DAT_00058360 + uVar8) = uVar13;
            *(undefined2 *)((int)&DAT_0005835c + uVar8) = uVar4;
          }
          iVar16 = iVar16 + -1;
          _DstBuf = _DstBuf + 0x18;
        } while (iVar16 != 0);
      }
      uVar8 = uVar8 + 0x18;
    } while (uVar8 < 0x348);
    uVar11 = 0;
    uVar8 = DAT_00057c94;
    uVar12 = DAT_00057c90;
    uVar7 = DAT_00057c98;
    do {
      pcVar10 = &DAT_00058364 + uVar11;
      iVar16 = *(int *)((int)&DAT_00058360 + uVar11);
      if (iVar16 == 0) {
LAB_0002834c:
        if (*(short *)((int)&DAT_0005835c + uVar11) == 0) {
          DAT_00057c98 = uVar7 + 1;
          uVar7 = DAT_00057c98;
        }
      }
      else if ((*(short *)((int)&DAT_0005835c + uVar11) == 0) ||
              ((*pcVar10 != '\0' && (*pcVar10 != '[')))) {
        if (iVar16 == 0) goto LAB_0002834c;
        if (*(short *)((int)&DAT_0005835c + uVar11) == 0) {
          _snprintf_s(&DAT_00057ca4 + uVar8 * 0x18,0x10,0xf,"%s",pcVar10);
          (&DAT_00057c9c)[DAT_00057c94 * 0xc] = *(short *)((int)&DAT_0005835c + uVar11);
          (&DAT_00057ca0)[DAT_00057c94 * 6] = *(undefined4 *)((int)&DAT_00058360 + uVar11);
          uVar8 = DAT_00057c94 + 1;
          uVar12 = DAT_00057c90;
          uVar7 = DAT_00057c98;
          DAT_00057c94 = uVar8;
        }
        else if (iVar16 == 0) goto LAB_0002834c;
      }
      else {
        _snprintf_s(&DAT_00058004 + uVar12 * 0x18,0x10,0xf,"%s",pcVar10);
        (&DAT_00057ffc)[DAT_00057c90 * 0xc] = *(short *)((int)&DAT_0005835c + uVar11);
        (&DAT_00058000)[DAT_00057c90 * 6] = *(undefined4 *)((int)&DAT_00058360 + uVar11);
        DAT_00057c90 = DAT_00057c90 + 1;
        uVar8 = DAT_00057c94;
        uVar12 = DAT_00057c90;
        uVar7 = DAT_00057c98;
      }
      uVar11 = uVar11 + 0x18;
    } while (uVar11 < 0x360);
    if ((uVar12 != 0) && (uVar7 = 0, uVar12 != 1)) {
      local_84 = 0;
      puVar15 = &DAT_00058014;
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
              _snprintf_s((char *)(puVar14 + 4),0x10,0xf,"%s",&DAT_00058004 + local_84);
              *puVar14 = *(undefined2 *)((int)&DAT_00057ffc + local_84);
              *(undefined4 *)(puVar14 + 2) = *(undefined4 *)(puVar15 + -10);
              _snprintf_s(&DAT_00058004 + local_84,0x10,0xf,"%s",&local_70);
              *(undefined2 *)((int)&DAT_00057ffc + local_84) = uVar4;
              *(undefined4 *)(puVar15 + -10) = uVar13;
              uVar12 = DAT_00057c90;
            }
            uVar8 = uVar8 + 1;
            puVar14 = puVar14 + 0xc;
          } while (uVar8 < uVar12);
        }
        local_84 = local_84 + 0x18;
        puVar15 = puVar15 + 0xc;
        uVar8 = DAT_00057c94;
      } while (uVar7 < uVar12 - 1);
    }
    if ((uVar8 != 0) && (uVar12 = 0, uVar8 != 1)) {
      local_84 = 0;
      puVar15 = &DAT_00057cb4;
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
              _snprintf_s((char *)(puVar14 + 4),0x10,0xf,"%s",&DAT_00057ca4 + local_84);
              *puVar14 = *(undefined2 *)((int)&DAT_00057c9c + local_84);
              *(undefined4 *)(puVar14 + 2) = *(undefined4 *)(puVar15 + -10);
              _snprintf_s(&DAT_00057ca4 + local_84,0x10,0xf,"%s",&local_70);
              *(undefined2 *)((int)&DAT_00057c9c + local_84) = uVar4;
              *(undefined4 *)(puVar15 + -10) = uVar13;
              uVar8 = DAT_00057c94;
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
    uVar8 = DAT_00057c8c;
    do {
      if ((*(int *)((int)&DAT_00058360 + uVar12) != 0) &&
         (*(short *)((int)&DAT_0005835c + uVar12) != 0)) {
        cVar3 = (&DAT_00058364)[uVar12];
        if ((cVar3 != '\0') && (cVar3 != '[')) {
          _snprintf_s(&DAT_000586c4 + uVar8 * 0x18,0x10,0xf,"%s",&DAT_00058364 + uVar12);
          (&DAT_000586bc)[DAT_00057c8c * 0xc] = *(short *)((int)&DAT_0005835c + uVar12);
          (&DAT_000586c0)[DAT_00057c8c * 6] = *(int *)((int)&DAT_00058360 + uVar12);
          uVar8 = DAT_00057c8c + 1;
          DAT_00057c8c = uVar8;
        }
      }
      uVar12 = uVar12 + 0x18;
    } while (uVar12 < 0x360);
    uVar7 = 0;
    uVar12 = uVar8;
    if (uVar8 < 0x24) {
      puVar14 = &DAT_00057ffc;
      puVar15 = &DAT_000586bc + uVar8 * 0xc;
      do {
        uVar12 = DAT_00057c8c;
        if (DAT_00057c90 <= uVar7) break;
        _snprintf_s((char *)(puVar15 + 4),0x10,0xf,"%s",puVar14 + 4);
        uVar8 = uVar8 + 1;
        *puVar15 = *puVar14;
        uVar7 = uVar7 + 1;
        *(undefined4 *)(puVar15 + 2) = *(undefined4 *)(puVar14 + 2);
        puVar15 = puVar15 + 0xc;
        puVar14 = puVar14 + 0xc;
        uVar12 = DAT_00057c8c;
      } while (uVar8 < 0x24);
    }
    uVar8 = DAT_00057c90 + uVar12;
    uVar7 = 0;
    if (uVar8 < 0x24) {
      puVar14 = &DAT_00057c9c;
      puVar15 = &DAT_000586bc + uVar8 * 0xc;
      do {
        uVar12 = DAT_00057c8c;
        if (DAT_00057c94 <= uVar7) break;
        _snprintf_s((char *)(puVar15 + 4),0x10,0xf,"%s",puVar14 + 4);
        uVar8 = uVar8 + 1;
        *puVar15 = *puVar14;
        uVar7 = uVar7 + 1;
        *(undefined4 *)(puVar15 + 2) = *(undefined4 *)(puVar14 + 2);
        puVar15 = puVar15 + 0xc;
        puVar14 = puVar14 + 0xc;
        uVar12 = DAT_00057c8c;
      } while (uVar8 < 0x24);
    }
    uVar12 = DAT_00057c94 + DAT_00057c90 + uVar12;
    uVar8 = 0;
    if (uVar12 < 0x24) {
      puVar15 = &DAT_000586bc + uVar12 * 0xc;
      do {
        if (DAT_00057c98 <= uVar8) break;
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
      *(undefined4 *)((int)&DAT_0005749c + *(int *)(param_1 + 0x1bc) * 0x48c + uVar8) =
           *(undefined4 *)((int)&DAT_000586c0 + uVar8);
      *(undefined2 *)((int)&DAT_00057498 + *(int *)(param_1 + 0x1bc) * 0x48c + uVar8) =
           *(undefined2 *)((int)&DAT_000586bc + uVar8);
      _snprintf_s(&DAT_000574a0 + *(int *)(param_1 + 0x1bc) * 0x48c + uVar8,0x10,0xf,"%s",
                  &DAT_000586c4 + uVar8);
      FUN_0002f8d4(*(int *)(param_1 + 0x1bc),iVar16);
      uVar8 = uVar8 + 0x18;
      iVar16 = iVar16 + 1;
    } while (uVar8 < 0x360);
  }
  else if ((param_2 == 0) || (*(int *)(param_1 + 0x1bc) == 1)) {
    DAT_00057c8c = 0;
    DAT_00057c90 = 0;
    DAT_00057c94 = 0;
    DAT_00057c98 = 0;
    uVar12 = 0;
    uVar8 = 0;
    do {
      uVar7 = uVar8;
      if (*(int *)((int)&DAT_00058360 + uVar12) == 0) break;
      uVar12 = uVar12 + 0x18;
      uVar8 = uVar7 + 1;
      DAT_00057c8c = uVar7;
    } while (uVar12 < 0x360);
    if (DAT_00057c8c != 0) {
      uVar8 = DAT_00057c8c + 1;
      bVar1 = DAT_00057c8c != 0;
      uVar12 = 0;
      DAT_00057c8c = uVar8;
      if (bVar1) {
        local_84 = 0;
        puVar15 = &DAT_00058374;
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
                _snprintf_s((char *)(puVar14 + 4),0x10,0xf,"%s",&DAT_00058364 + local_84);
                *puVar14 = *(undefined2 *)((int)&DAT_0005835c + local_84);
                *(undefined4 *)(puVar14 + 2) = *(undefined4 *)(puVar15 + -10);
                _snprintf_s(&DAT_00058364 + local_84,0x10,0xf,"%s",&local_70);
                *(undefined2 *)((int)&DAT_0005835c + local_84) = uVar4;
                *(undefined4 *)(puVar15 + -10) = uVar13;
                uVar8 = DAT_00057c8c;
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
      *(undefined4 *)((int)&DAT_0005749c + *(int *)(param_1 + 0x1bc) * 0x48c + uVar8) =
           *(undefined4 *)((int)&DAT_00058360 + uVar8);
      *(undefined2 *)((int)&DAT_00057498 + *(int *)(param_1 + 0x1bc) * 0x48c + uVar8) =
           *(undefined2 *)((int)&DAT_0005835c + uVar8);
      _snprintf_s(&DAT_000574a0 + *(int *)(param_1 + 0x1bc) * 0x48c + uVar8,0x10,0xf,"%s",
                  &DAT_00058364 + uVar8);
      FUN_0002f8d4(*(int *)(param_1 + 0x1bc),iVar16);
      uVar8 = uVar8 + 0x18;
      iVar16 = iVar16 + 1;
    } while (uVar8 < 0x360);
  }
  FUN_00043604(local_30);
  return;
}



/* 00028af8 FUN_00028af8 */

/* Boundary evidence: original MIPS .pdata 00028af8..00028c9b. Semantic name remains unreviewed. */

void FUN_00028af8(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  UINT UVar3;
  
  if (*(int *)(param_1 + 0x50) != 0) {
    NKDbgPrintfW(L"%S : SubMode is not NONE. Current SubMode=%d!!!!!!!!!!\r\n",
                 "CRadio::StartSubModeTA");
  }
  NKDbgPrintfW(L"%S : CurPI=%04X, EONPI=0x%04X, CurFreq=%d, Type=%d,%d)\r\n",
               "CRadio::StartSubModeTA",*(undefined2 *)(param_1 + 0x1c8),
               *(undefined2 *)(param_1 + 0x1e0),*(undefined4 *)(param_1 + 0x1c0),
               *(undefined4 *)(param_1 + 0x1d8),*(undefined4 *)(param_1 + 0x1dc));
  if (*(int *)(param_1 + 0x4c) == 2) {
    *(undefined4 *)(param_1 + 0x284) = 0;
    FUN_00026960(param_1,4);
  }
  *(undefined4 *)(param_1 + 0x50) = 5;
  if (*(int *)(param_1 + 0x1d8) == 2) {
    if (*(int *)(param_1 + 0x4c) == 1) {
      FUN_00027458(param_1,0);
    }
    *(ushort *)(param_1 + 0x1c8) = *(ushort *)(param_1 + 0x1e0);
    uVar1 = FUN_0002e3e8(DAT_00057348,(uint)*(ushort *)(param_1 + 0x1e0));
    *(undefined4 *)(param_1 + 0x1cc) = uVar1;
    iVar2 = FUN_0002e36c(DAT_00057348);
    *(int *)(param_1 + 0x1c0) = iVar2;
    iVar2 = FUN_0002e454(DAT_00057348);
    FUN_00015f10(DAT_000553cc,3,1,0x37,iVar2,0x24,100);
    if (*(int *)(param_1 + 0x1e4) == 1) {
      FUN_000272d8(param_1,0);
      *(undefined4 *)(param_1 + 0x1e4) = 0;
    }
    *(undefined4 *)(param_1 + 0x1e4) = 1;
    UVar3 = 3000;
    uVar1 = 2;
  }
  else {
    if (*(int *)(param_1 + 0x1d8) != 1) goto LAB_00028c5c;
    UVar3 = 1000;
    uVar1 = 6;
  }
  FUN_000268d0(param_1,uVar1,UVar3);
LAB_00028c5c:
  FUN_00015f10(DAT_000553cc,3,1,0x21,0,0,100);
  return;
}



/* 00028c9c FUN_00028c9c */

/* Boundary evidence: original MIPS .pdata 00028c9c..00028deb. Semantic name remains unreviewed. */

void FUN_00028c9c(int param_1)

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
               *(undefined2 *)(param_1 + 0x1c8),*(undefined4 *)(param_1 + 0x1c0));
  *(undefined4 *)(param_1 + 0x50) = 8;
  *(undefined4 *)(param_1 + 0x1bc) = 0;
  *(undefined2 *)(param_1 + 0x1c8) = 0;
  *(undefined4 *)(param_1 + 0x1cc) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x1d0) = 0xc;
  *(undefined4 *)(param_1 + 0x1d4) = 0x24;
  uVar1 = FUN_00026e3c(param_1);
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
  FUN_00015f10(DAT_000553cc,3,1,0x35,(int)&local_28,0x14,0x32);
  if (*(int *)(param_1 + 0x1e4) == 1) {
    FUN_000272d8(param_1,0);
    *(undefined4 *)(param_1 + 0x1e4) = 0;
  }
  *(undefined4 *)(param_1 + 0x1f0) = 0;
  *(undefined4 *)(param_1 + 0x1ec) = 0;
  *(undefined4 *)(param_1 + 500) = 0;
  return;
}



/* 00028dec FUN_00028dec */

/* Boundary evidence: original MIPS .pdata 00028dec..00028e4b. Semantic name remains unreviewed. */

void FUN_00028dec(void)

{
  undefined1 local_10 [8];
  
  local_10[0] = (DAT_00057354 & 4) == 4;
  FUN_00015b90(DAT_000553cc,3,0,(int)local_10,1,0x32);
  return;
}



/* 00028e4c FUN_00028e4c */

/* Boundary evidence: original MIPS .pdata 00028e4c..00028eab. Semantic name remains unreviewed. */

void FUN_00028e4c(void)

{
  undefined1 local_10 [8];
  
  local_10[0] = (DAT_00057354 & 0x10) == 0x10;
  FUN_00015b90(DAT_000553cc,3,1,(int)local_10,1,0x32);
  return;
}



/* 00028eac FUN_00028eac */

/* Boundary evidence: original MIPS .pdata 00028eac..00028fe3. Semantic name remains unreviewed. */

void FUN_00028eac(void)

{
  errno_t eVar1;
  uint uVar2;
  undefined1 *puVar3;
  FILE *local_420 [2];
  undefined1 auStack_418 [1024];
  uint local_18;
  
  local_18 = DAT_00055374;
  eVar1 = fopen_s(local_420,".\\Storage Card\\system\\radparam_update.bin","rb");
  if (eVar1 == 0) {
    fread(auStack_418,0x400,1,local_420[0]);
    fclose(local_420[0]);
    uVar2 = 0;
    puVar3 = auStack_418;
    do {
      FUN_00015b90(DAT_000553cc,3,uVar2 + 0xe0,(int)puVar3,0x80,300);
      uVar2 = uVar2 + 1;
      puVar3 = puVar3 + 0x80;
    } while (uVar2 < 8);
    FUN_00015f10(DAT_000553cc,3,1,0xe1,0,0,1000);
    FUN_00015f10(DAT_000553cc,3,1,0xe0,0,0,1000);
    FUN_00015f10(DAT_000553cc,3,1,0xe2,0,0,100);
    DeleteFileW(L".\\Storage Card\\system\\radparam_update.bin");
  }
  FUN_00043604(local_18);
  return;
}



/* 00028fe4 FUN_00028fe4 */

/* Boundary evidence: original MIPS .pdata 00028fe4..0002903b. Semantic name remains unreviewed. */

undefined4 * FUN_00028fe4(undefined4 *param_1,uint param_2)

{
  *param_1 = &PTR_FUN_0004d380;
  FUN_0002d85c(param_1);
  if ((param_2 & 1) != 0) {
    __3_YAXPAX_Z(param_1);
  }
  return param_1;
}



/* 0002903c FUN_0002903c */

/* Boundary evidence: original MIPS .pdata 0002903c..000299b7. Semantic name remains unreviewed. */

void FUN_0002903c(int param_1,uint param_2)

{
  ushort uVar1;
  short sVar2;
  bool bVar3;
  bool bVar4;
  bool bVar5;
  undefined4 uVar6;
  uint uVar7;
  int iVar8;
  uint *puVar9;
  short *psVar10;
  int iVar11;
  int iVar12;
  uint uVar13;
  int iVar14;
  uint uVar15;
  uint uVar16;
  int *piVar17;
  uint uVar18;
  undefined8 uVar19;
  
  bVar3 = false;
  bVar4 = false;
  bVar5 = false;
  if ((*(int *)(param_1 + 0x50) == 0) || (*(int *)(param_1 + 0x50) == 5)) {
    uVar13 = param_2 >> 0xc & 0xf;
    uVar18 = param_2 >> 4 & 0xf;
    uVar16 = param_2 >> 8 & 0xf;
    *(short *)(param_1 + 0x1c8) = (short)param_2;
    uVar15 = 0;
    do {
      iVar11 = *(int *)(param_1 + 0x1bc) * 0x48c + uVar15;
      uVar1 = *(ushort *)((int)&DAT_00057498 + iVar11);
      if ((uint)uVar1 == (uint)*(ushort *)(param_1 + 0x1c8)) {
        bVar3 = true;
        bVar4 = true;
      }
      piVar17 = (int *)((int)&DAT_0005749c + iVar11);
      iVar11 = *piVar17;
      uVar7 = uVar1 >> 8 & 0xf;
      if (((((uVar13 == uVar1 >> 0xc) && (uVar16 != uVar7)) && (uVar18 == (uVar1 >> 4 & 0xf))) &&
          (((param_2 & 0xf) == (uVar1 & 0xf) && (uVar16 == 3)))) && (uVar7 != 3)) {
        *piVar17 = *(int *)(param_1 + 0x1c0);
        uVar7 = 0;
        bVar5 = true;
        *(undefined2 *)((int)&DAT_00057498 + *(int *)(param_1 + 0x1bc) * 0x48c + uVar15) =
             *(undefined2 *)(param_1 + 0x1c8);
        do {
          iVar8 = *(int *)(param_1 + 0x1bc) * 0x48c + uVar7;
          uVar1 = *(ushort *)((int)&DAT_00057498 + iVar8);
          if (((uVar13 == uVar1 >> 0xc) && ((uVar1 >> 8 & 0xf) != 3)) &&
             ((uVar18 == (uVar1 >> 4 & 0xf) && ((param_2 & 0xf) == (uVar1 & 0xf))))) {
            NKDbgPrintfW(L"\n%S : Rempve regional Frequncy : [Frequncy :%d ] [PI : 0x%04X] [PSN : %s]\r\n\n"
                         ,"CRadio::CmdSubUpdatedPI",*(undefined4 *)((int)&DAT_0005749c + iVar8),
                         (uint)uVar1,&DAT_000574a0 + iVar8);
            *(undefined2 *)((int)&DAT_00057498 + *(int *)(param_1 + 0x1bc) * 0x48c + uVar7) = 0;
            *(undefined4 *)((int)&DAT_0005749c + *(int *)(param_1 + 0x1bc) * 0x48c + uVar7) = 0;
            (&DAT_000574a0)[*(int *)(param_1 + 0x1bc) * 0x48c + uVar7] = 0;
          }
          uVar7 = uVar7 + 0x18;
          bVar3 = bVar4;
        } while (uVar7 < 0x360);
      }
      uVar15 = uVar15 + 0x18;
    } while (uVar15 < 0x360);
    iVar8 = 0;
    uVar13 = 0;
    do {
      iVar14 = *(int *)(param_1 + 0x1bc) * 0x48c + uVar13;
      uVar15 = *(uint *)((int)&DAT_0005749c + iVar14);
      if (uVar15 == *(uint *)(param_1 + 0x1c0)) {
        if (*(short *)((int)&DAT_00057498 + iVar14) == 0) {
          iVar14 = iVar8 * 0x18;
          (&DAT_00057498)[iVar8 * 0xc + *(int *)(param_1 + 0x1bc) * 0x246] =
               *(undefined2 *)(param_1 + 0x1c8);
          iVar12 = *(int *)(param_1 + 0x1bc);
          if (iVar12 == 1) {
            sprintf_s(&DAT_0005792c + iVar14,0x10,"%dkHz",(&DAT_00057928)[iVar8 * 6]);
          }
          else if ((ushort)(&DAT_00057498)[iVar8 * 0xc + iVar12 * 0x246] == 0) {
            uVar6 = __ultofp((&DAT_0005749c)[iVar8 * 6 + iVar12 * 0x123]);
            uVar19 = __fptodp(uVar6);
            __dpmul((int)uVar19,(int)((ulonglong)uVar19 >> 0x20),0xd2f1a9fc,0x3f50624d);
            sprintf_s(&DAT_000574a0 + iVar12 * 0x48c + iVar14,0x10,"%6.2fMHz");
          }
          else {
            FUN_0002ed04(DAT_00057348,(uint)(ushort)(&DAT_00057498)[iVar8 * 0xc + iVar12 * 0x246],
                         (&DAT_0005749c)[iVar8 * 6 + iVar12 * 0x123]);
            FUN_0002e27c(DAT_00057348,
                         (uint)(ushort)(&DAT_00057498)
                                       [iVar8 * 0xc + *(int *)(param_1 + 0x1bc) * 0x246],
                         (undefined4 *)(&DAT_000574a0 + *(int *)(param_1 + 0x1bc) * 0x48c + iVar14))
            ;
          }
          if (bVar3) {
            (&DAT_00057498)[iVar8 * 0xc + *(int *)(param_1 + 0x1bc) * 0x246] = 0;
            (&DAT_0005749c)[iVar8 * 6 + *(int *)(param_1 + 0x1bc) * 0x123] = 0;
            (&DAT_000574a0)[*(int *)(param_1 + 0x1bc) * 0x48c + iVar14] = 0;
          }
          break;
        }
        if ((uVar15 == *(uint *)(param_1 + 0x1c0)) &&
           (uVar16 = (uint)*(ushort *)((int)&DAT_00057498 + iVar14),
           uVar16 == *(ushort *)(param_1 + 0x1c8))) {
          if (*(int *)(param_1 + 0x1bc) == 1) {
            sprintf_s(&DAT_000574a0 + iVar14,0x10,"%dkHz",uVar15);
          }
          else if (uVar16 == 0) {
            uVar6 = __ultofp(uVar15);
            uVar19 = __fptodp(uVar6);
            __dpmul((int)uVar19,(int)((ulonglong)uVar19 >> 0x20),0xd2f1a9fc,0x3f50624d);
            sprintf_s(&DAT_000574a0 + iVar14,0x10,"%6.2fMHz");
          }
          else {
            FUN_0002ed04(DAT_00057348,uVar16,uVar15);
            iVar14 = *(int *)(param_1 + 0x1bc) * 0x48c + uVar13;
            FUN_0002e27c(DAT_00057348,(uint)*(ushort *)((int)&DAT_00057498 + iVar14),
                         (undefined4 *)(&DAT_000574a0 + iVar14));
          }
        }
      }
      uVar13 = uVar13 + 0x18;
      iVar8 = iVar8 + 1;
    } while (uVar13 < 0x360);
    if ((!bVar5) && (!bVar3)) {
      iVar8 = *(int *)(param_1 + 0x1bc);
      iVar14 = *(int *)(param_1 + 0x1c0);
      uVar13 = 0;
      psVar10 = &DAT_00057498 + iVar8 * 0x246;
      do {
        if ((*(int *)(psVar10 + 2) == iVar14) ||
           (sVar2 = *psVar10, sVar2 == *(short *)(param_1 + 0x1c8))) break;
        if (*(int *)(psVar10 + 2) == 0) {
          if (sVar2 == 0) {
            (&DAT_0005749c)[iVar8 * 0x123 + uVar13 * 6] = iVar14;
            (&DAT_00057498)[uVar13 * 0xc + *(int *)(param_1 + 0x1bc) * 0x246] =
                 *(undefined2 *)(param_1 + 0x1c8);
            iVar11 = *(int *)(param_1 + 0x1bc);
            uVar15 = (uint)(ushort)(&DAT_00057498)[uVar13 * 0xc + iVar11 * 0x246];
            puVar9 = &DAT_0005749c + uVar13 * 6 + iVar11 * 0x123;
            if (uVar15 == 0) {
              uVar6 = __ultofp(*puVar9);
              uVar19 = __fptodp(uVar6);
              __dpmul((int)uVar19,(int)((ulonglong)uVar19 >> 0x20),0xd2f1a9fc,0x3f50624d);
              sprintf_s(&DAT_000574a0 + iVar11 * 0x48c + uVar13 * 0x18,0x10,"%6.2fMHz");
            }
            else {
LAB_00029784:
              FUN_0002ed04(DAT_00057348,uVar15,*puVar9);
              FUN_0002e27c(DAT_00057348,
                           (uint)(ushort)(&DAT_00057498)
                                         [uVar13 * 0xc + *(int *)(param_1 + 0x1bc) * 0x246],
                           (undefined4 *)
                           (&DAT_000574a0 + *(int *)(param_1 + 0x1bc) * 0x48c + uVar13 * 0x18));
            }
            break;
          }
        }
        else if ((sVar2 == 0) && (iVar11 != 0)) {
          (&DAT_0005749c)[iVar8 * 0x123 + uVar13 * 6] = iVar14;
          (&DAT_00057498)[uVar13 * 0xc + *(int *)(param_1 + 0x1bc) * 0x246] =
               *(undefined2 *)(param_1 + 0x1c8);
          iVar11 = *(int *)(param_1 + 0x1bc);
          uVar15 = (uint)(ushort)(&DAT_00057498)[uVar13 * 0xc + iVar11 * 0x246];
          puVar9 = &DAT_0005749c + uVar13 * 6 + iVar11 * 0x123;
          if (uVar15 != 0) goto LAB_00029784;
          uVar6 = __ultofp(*puVar9);
          uVar19 = __fptodp(uVar6);
          __dpmul((int)uVar19,(int)((ulonglong)uVar19 >> 0x20),0xd2f1a9fc,0x3f50624d);
          sprintf_s(&DAT_000574a0 + iVar11 * 0x48c + uVar13 * 0x18,0x10,"%6.2fMHz");
          break;
        }
        uVar13 = uVar13 + 1;
        psVar10 = psVar10 + 0xc;
      } while (uVar13 < 0x24);
    }
    FUN_00027dd0(param_1,DAT_00057354 >> 1 & 1);
    uVar13 = 0;
    do {
      FUN_0002f8d4(*(int *)(param_1 + 0x1bc),uVar13);
      uVar13 = uVar13 + 1;
    } while (uVar13 < 0x24);
    if (*(int *)(param_1 + 0x280) == 0) {
      FUN_00026f0c(param_1);
      FUN_00027124(param_1);
    }
    if (*(HWND *)(param_1 + 0x5c) != (HWND)0x0) {
      PostMessageW(*(HWND *)(param_1 + 0x5c),0x403,5,(uint)*(ushort *)(param_1 + 0x1c8));
    }
    uVar6 = FUN_0002ebb0(DAT_00057348,(uint)*(ushort *)(param_1 + 0x1c8),*(uint *)(param_1 + 0x1c0))
    ;
    *(undefined4 *)(param_1 + 0x1cc) = uVar6;
    iVar11 = FUN_0002e454(DAT_00057348);
    FUN_00015b90(DAT_000553cc,3,3,iVar11,0x24,300);
    FUN_00026db8(param_1);
    if ((*(int *)(param_1 + 0x4c) == 1) && ((DAT_00057354 & 2) == 2)) {
      FUN_0002e27c(DAT_00057348,(uint)*(ushort *)(param_1 + 0x1c8),
                   (undefined4 *)(*(int *)(param_1 + 0x44) + 0x617));
      FUN_000338ac(0x6a,0);
    }
    *(undefined4 *)(param_1 + 0x1e4) = 1;
  }
  return;
}



/* 000299b8 FUN_000299b8 */

/* Boundary evidence: original MIPS .pdata 000299b8..00029af7. Semantic name remains unreviewed. */

void FUN_000299b8(int param_1,int param_2,int param_3)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  
  uVar5 = *(uint *)(param_1 + 0x1c0);
  uVar1 = FUN_00026e3c(param_1);
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



/* 00029af8 FUN_00029af8 */

/* Boundary evidence: original MIPS .pdata 00029af8..00029d7f. Semantic name remains unreviewed. */

void FUN_00029af8(int param_1)

{
  ushort uVar1;
  int iVar2;
  
  NKDbgPrintfW(L"%S : main mode=%d, main mode step=%d, m_nSubMode=%d)\r\n",
               "CRadio::StartSubModeNone",*(undefined4 *)(param_1 + 0x4c),
               *(undefined4 *)(param_1 + 0x284),*(undefined4 *)(param_1 + 0x50));
  *(undefined4 *)(param_1 + 0x50) = 0;
  *(undefined1 *)(*(int *)(param_1 + 0x44) + 0x667) = 0;
  *(undefined1 *)(*(int *)(param_1 + 0x44) + 0x668) = 0;
  iVar2 = *(int *)(param_1 + 0x4c);
  if (iVar2 == 0) {
    if (*(int *)(param_1 + 0x284) == 0) {
      FUN_00015f10(DAT_000553cc,3,1,0x20,0,0,100);
      FUN_00027500(param_1);
      FUN_00027654(param_1,0,1);
      *(int *)(param_1 + 0x284) = *(int *)(param_1 + 0x284) + 1;
      FUN_00028dec();
    }
  }
  else if (iVar2 == 1) {
    if (*(int *)(param_1 + 0x284) == 0) {
      *(undefined1 *)(*(int *)(param_1 + 0x44) + 0x617) = 0;
      *(undefined1 *)(*(int *)(param_1 + 0x44) + 0x615) = 0;
      *(undefined1 *)(*(int *)(param_1 + 0x44) + 0x623) = 0;
      FUN_00027500(param_1);
      FUN_00027654(param_1,0,1);
      *(int *)(param_1 + 0x284) = *(int *)(param_1 + 0x284) + 1;
      FUN_00028dec();
      FUN_00015f10(DAT_000553cc,3,1,0x21,0,0,100);
      FUN_000338ac(0x6a,0);
      FUN_000338ac(0x6b,0);
      FUN_000338ac(0x6c,0);
    }
  }
  else if ((iVar2 == 2) && (*(int *)(param_1 + 0x284) == 0)) {
    FUN_00015f10(DAT_000553cc,3,1,0x20,0,0,100);
    FUN_00028dec();
    uVar1 = (&DAT_00057370)[*(int *)(param_1 + 0x1bc) * 0x246];
    *(ushort *)(param_1 + 0x1c8) = uVar1;
    *(undefined4 *)(param_1 + 0x1c0) = 0;
    if (uVar1 != 0) {
      iVar2 = FUN_0002e300(DAT_00057348,(uint)uVar1);
      *(int *)(param_1 + 0x1c0) = iVar2;
    }
    if (*(int *)(param_1 + 0x1c0) == 0) {
      *(undefined4 *)(param_1 + 0x1c0) = (&DAT_00057374)[*(int *)(param_1 + 0x1bc) * 0x123];
    }
    *(undefined2 *)(param_1 + 0x1c8) = 0;
    if (*(uint *)(param_1 + 0x1c0) < 0x15630) {
      *(undefined4 *)(param_1 + 0x1c0) = 0x2a30;
    }
    else {
      *(uint *)(param_1 + 0x1c0) = *(uint *)(param_1 + 0x1c0) - 100;
    }
    if (*(int *)(param_1 + 0x1bc) == 0) {
      FUN_00028c9c(param_1);
    }
    *(undefined4 *)(param_1 + 0x284) = 1;
  }
  return;
}



/* 00029d80 FUN_00029d80 */

/* Boundary evidence: original MIPS .pdata 00029d80..00029e2f. Semantic name remains unreviewed. */

void FUN_00029d80(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x50);
  if ((iVar1 == 3) || (iVar1 == 2)) {
    if (iVar1 == 2) {
      FUN_00015f10(DAT_000553cc,3,1,0x21,0,0,100);
    }
    *(undefined4 *)(param_1 + 0x1c0) = *(undefined4 *)(param_1 + 0x1c4);
  }
  iVar1 = *(int *)(param_1 + 0x50);
  if (((iVar1 == 3) || (iVar1 == 4)) || (iVar1 == 2)) {
    FUN_00027654(param_1,0,1);
  }
  return;
}



/* 00029e30 FUN_00029e30 */

/* Boundary evidence: original MIPS .pdata 00029e30..00029eeb. Semantic name remains unreviewed. */

void FUN_00029e30(int param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x50);
  if (iVar1 != 1) {
    if (iVar1 == 5) {
      *(undefined4 *)(param_1 + 0x1c0) = param_2;
      NKDbgPrintfW(L"%S : NOTI_APP_FREQCHG_TUNE_COMPLETE(TA) : %d\r\n","CRadio::StopSubModeTune",
                   param_2);
      FUN_00026db8(param_1);
      return;
    }
    if (iVar1 != 9) {
      NKDbgPrintfW(L"%S : Sub-Mode is not SUBMODE_TUNE or SUBMODE_TA Check it out.!!!\r\n",
                   "CRadio::StopSubModeTune");
      return;
    }
  }
  *(undefined4 *)(param_1 + 0x1c0) = param_2;
  NKDbgPrintfW(L"%S : SUBMODE_TUNE %d\r\n","CRadio::StopSubModeTune",param_2);
  FUN_00026db8(param_1);
  FUN_00029af8(param_1);
  return;
}



/* 00029eec FUN_00029eec */

/* Boundary evidence: original MIPS .pdata 00029eec..00029f8f. Semantic name remains unreviewed. */

void FUN_00029eec(int param_1,undefined4 param_2)

{
  if (*(int *)(param_1 + 0x50) == 3) {
    *(undefined4 *)(param_1 + 0x1cc) = 0xffffffff;
    *(undefined4 *)(param_1 + 0x1c0) = param_2;
    *(undefined2 *)(param_1 + 0x1c8) = 0;
    NKDbgPrintfW(L"%S : m_nCurFreq-%d\r\n","CRadio::StopSubModeSeekFail",param_2);
    if (0xb < *(uint *)(param_1 + 0x1d0)) {
      FUN_00026f0c(param_1);
    }
    FUN_00027124(param_1);
    FUN_00026db8(param_1);
    FUN_00029af8(param_1);
  }
  else {
    NKDbgPrintfW(L"%S : Sub-Mode is not SUBMODE_SEEK. Check it out.!!!\r\n",
                 "CRadio::StopSubModeSeekFail");
  }
  return;
}



/* 00029f90 FUN_00029f90 */

/* Boundary evidence: original MIPS .pdata 00029f90..0002a0c7. Semantic name remains unreviewed. */

void FUN_00029f90(int param_1,int param_2,int param_3)

{
  uint uVar1;
  char *pcVar2;
  uint uVar3;
  
  uVar1 = DAT_00055374;
  if ((param_2 == 1) || (*(int *)(param_1 + 0x1bc) == 0)) {
    uVar3 = 0;
    pcVar2 = &DAT_000574a0 + *(int *)(param_1 + 0x1bc) * 0x48c;
    do {
      if ((*(int *)(pcVar2 + -4) == param_3) && (*pcVar2 == '\0')) {
        (&DAT_0005749c)[uVar3 * 6 + *(int *)(param_1 + 0x1bc) * 0x123] = 0;
        (&DAT_00057498)[uVar3 * 0xc + *(int *)(param_1 + 0x1bc) * 0x246] = 0;
        (&DAT_000574a0)[*(int *)(param_1 + 0x1bc) * 0x48c + uVar3 * 0x18] = 0;
        break;
      }
      uVar3 = uVar3 + 1;
      pcVar2 = pcVar2 + 0x18;
    } while (uVar3 < 0x24);
  }
  FUN_00027dd0(param_1,param_2);
  uVar3 = 0;
  do {
    FUN_0002f8d4(*(int *)(param_1 + 0x1bc),uVar3);
    uVar3 = uVar3 + 1;
  } while (uVar3 < 0x24);
  FUN_00043604(uVar1);
  return;
}



/* 0002a0c8 FUN_0002a0c8 */

/* Boundary evidence: original MIPS .pdata 0002a0c8..0002a30b. Semantic name remains unreviewed. */

void FUN_0002a0c8(int param_1,int param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  int *piVar5;
  uint uVar6;
  undefined8 uVar7;
  
  uVar2 = DAT_00055374;
  if ((param_2 == 0) || (*(int *)(param_1 + 0x1bc) == 1)) {
    uVar6 = 0;
    piVar5 = &DAT_0005749c + *(int *)(param_1 + 0x1bc) * 0x123;
    while (*piVar5 != param_3) {
      if ((*piVar5 == 0) && ((short)piVar5[-1] == 0)) {
        iVar1 = uVar6 * 0x18;
        (&DAT_0005749c)[uVar6 * 6 + *(int *)(param_1 + 0x1bc) * 0x123] = param_3;
        if (*(int *)(param_1 + 0x1bc) == 1) {
          sprintf_s(&DAT_0005792c + iVar1,0x10,"%dkHz",(&DAT_00057928)[uVar6 * 6]);
        }
        else {
          iVar4 = *(int *)(param_1 + 0x1bc);
          if ((&DAT_00057498)[uVar6 * 0xc + *(int *)(param_1 + 0x1bc) * 0x246] == 0) {
            uVar3 = __ultofp((&DAT_0005749c)[uVar6 * 6 + iVar4 * 0x123]);
            uVar7 = __fptodp(uVar3);
            __dpmul((int)uVar7,(int)((ulonglong)uVar7 >> 0x20),0xd2f1a9fc,0x3f50624d);
            sprintf_s(&DAT_000574a0 + iVar4 * 0x48c + iVar1,0x10,"%6.2fMHz");
          }
          else {
            FUN_0002ed04(DAT_00057348,(uint)(ushort)(&DAT_00057498)[uVar6 * 0xc + iVar4 * 0x246],
                         (&DAT_0005749c)[uVar6 * 6 + iVar4 * 0x123]);
            FUN_0002e27c(DAT_00057348,
                         (uint)(ushort)(&DAT_00057498)
                                       [uVar6 * 0xc + *(int *)(param_1 + 0x1bc) * 0x246],
                         (undefined4 *)(&DAT_000574a0 + *(int *)(param_1 + 0x1bc) * 0x48c + iVar1));
          }
        }
        break;
      }
      uVar6 = uVar6 + 1;
      piVar5 = piVar5 + 6;
      if (0x23 < uVar6) break;
    }
  }
  FUN_00027dd0(param_1,param_2);
  uVar6 = 0;
  do {
    FUN_0002f8d4(*(int *)(param_1 + 0x1bc),uVar6);
    uVar6 = uVar6 + 1;
  } while (uVar6 < 0x24);
  FUN_00043604(uVar2);
  return;
}



/* 0002a30c FUN_0002a30c */

/* Boundary evidence: original MIPS .pdata 0002a30c..0002a5b3. Semantic name remains unreviewed. */

void FUN_0002a30c(int param_1)

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
  
  local_20 = DAT_00055374;
  if (*(int *)(param_1 + 0x50) != 0) {
    NKDbgPrintfW(L"%S : SubMode is not NONE. Current SubMode=%d!!!!!!!!!!\r\n",
                 "CRadio::StartSubModeAST");
    if (*(int *)(param_1 + 0x50) == 2) {
      FUN_00026960(param_1,1);
    }
    else if (*(int *)(param_1 + 0x50) != 3) goto LAB_0002a398;
    *(undefined4 *)(param_1 + 0x1c0) = *(undefined4 *)(param_1 + 0x1c4);
    FUN_00029af8(param_1);
  }
LAB_0002a398:
  NKDbgPrintfW(L"%S : CurPI=%04X, CurFreq=%d)\r\n","CRadio::StartSubModeAST",
               *(undefined2 *)(param_1 + 0x1c8),*(undefined4 *)(param_1 + 0x1c0));
  *(undefined4 *)(param_1 + 0x50) = 4;
  *(undefined2 *)(param_1 + 0x1c8) = 0;
  *(undefined4 *)(param_1 + 0x1cc) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x1d0) = 0xc;
  *(undefined4 *)(param_1 + 0x1d4) = 0x24;
  uVar2 = FUN_00026e3c(param_1);
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
    FUN_00015f10(DAT_000553cc,3,1,5,(int)&local_60,0x14,100);
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
    FUN_00015f10(DAT_000553cc,3,1,6,(int)local_48,0x28,100);
  }
  *(undefined1 *)(*(int *)(param_1 + 0x44) + 0x667) = 1;
  *(undefined1 *)(*(int *)(param_1 + 0x44) + 0x668) = 0;
  *(char *)(*(int *)(param_1 + 0x44) + 0x613) = (char)*(undefined4 *)(param_1 + 0x1d0);
  *(char *)(*(int *)(param_1 + 0x44) + 0x614) = (char)*(undefined4 *)(param_1 + 0x1d4);
  if (*(int *)(param_1 + 0x1e4) == 1) {
    FUN_000272d8(param_1,0);
    *(undefined4 *)(param_1 + 0x1e4) = 0;
  }
  if (*(int *)(param_1 + 0x1ec) == 1) {
    *(undefined4 *)(param_1 + 0x1f8) = 1;
  }
  if ((*(int *)(param_1 + 500) == 1) || (*(int *)(param_1 + 500) == 0x1f)) {
    *(undefined4 *)(param_1 + 0x1fc) = 1;
  }
  FUN_00043604(local_20);
  return;
}



/* 0002a5b4 FUN_0002a5b4 */

/* Boundary evidence: original MIPS .pdata 0002a5b4..0002ab8f. Semantic name remains unreviewed. */

void FUN_0002a5b4(int param_1,undefined4 param_2)

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
    *(undefined4 *)(param_1 + 0x1cc) = 0xffffffff;
    if (*(int *)(param_1 + 0x4c) == 1) {
      *(undefined2 *)(param_1 + 0x1c8) = 0;
      *(undefined4 *)(param_1 + 0x1c0) = param_2;
    }
    else {
      (&DAT_0005736c)[*(int *)(param_1 + 0x1bc) * 0x48c] = 0xc;
      (&DAT_00057370)[*(int *)(param_1 + 0x1bc) * 0x246] = 0;
      (&DAT_00057374)[*(int *)(param_1 + 0x1bc) * 0x123] = param_2;
    }
    NKDbgPrintfW(L"%S : NOTI_APP_FREQCHG_AST_COMPLETE : %d (SRC=%d)\r\n","CRadio::StopSubModeAST",
                 param_2,*(undefined4 *)(param_1 + 0x1bc));
    iVar6 = 0;
    *(undefined4 *)(param_1 + 0x54) = 0;
    uVar4 = 0;
    do {
      uVar5 = 0;
      do {
        uVar1 = FUN_00016068(DAT_000553cc,3,iVar6 + 0x20,local_30,8,300);
        if (uVar1 == 8) break;
        uVar5 = uVar5 + 1;
      } while (uVar5 < 3);
      if (uVar5 == 3) {
        NKDbgPrintfW(L"%S : Can\'t read AST Result.\r\n","CRadio::StopSubModeAST");
        break;
      }
      NKDbgPrintfW(L"%S : AST result get success.\r\n","CRadio::StopSubModeAST");
      if (local_30[0] == 0) {
        *(undefined4 *)((int)&DAT_0005749c + *(int *)(param_1 + 0x1bc) * 0x48c + uVar4) = 0;
        *(undefined2 *)((int)&DAT_00057498 + *(int *)(param_1 + 0x1bc) * 0x48c + uVar4) = 0;
        (&DAT_000574a0)[*(int *)(param_1 + 0x1bc) * 0x48c + uVar4] = 0;
      }
      else {
        *(int *)((int)&DAT_0005749c + *(int *)(param_1 + 0x1bc) * 0x48c + uVar4) = local_30[0];
        *(short *)((int)&DAT_00057498 + *(int *)(param_1 + 0x1bc) * 0x48c + uVar4) =
             (short)local_30[1];
        iVar3 = *(int *)(param_1 + 0x1bc) * 0x48c + uVar4;
        NKDbgPrintfW(L"%S : %d : FREQ-%d, PI-0x%04X\r\n","CRadio::StopSubModeAST",iVar6,
                     *(undefined4 *)((int)&DAT_0005749c + iVar3),
                     *(undefined2 *)((int)&DAT_00057498 + iVar3));
        if (*(int *)(param_1 + 0x1bc) == 1) {
          sprintf_s(&DAT_0005792c + uVar4,0x10,"%dkHz",*(undefined4 *)((int)&DAT_00057928 + uVar4));
        }
        else {
          iVar3 = *(int *)(param_1 + 0x1bc) * 0x48c + uVar4;
          if (*(ushort *)((int)&DAT_00057498 + iVar3) == 0) {
            uVar2 = __ultofp(*(undefined4 *)((int)&DAT_0005749c + iVar3));
            uVar7 = __fptodp(uVar2);
            __dpmul((int)uVar7,(int)((ulonglong)uVar7 >> 0x20),0xd2f1a9fc,0x3f50624d);
            sprintf_s(&DAT_000574a0 + iVar3,0x10,"%6.2fMHz");
          }
          else {
            FUN_0002ed04(DAT_00057348,(uint)*(ushort *)((int)&DAT_00057498 + iVar3),
                         *(uint *)((int)&DAT_0005749c + iVar3));
            iVar3 = *(int *)(param_1 + 0x1bc) * 0x48c + uVar4;
            FUN_0002e27c(DAT_00057348,(uint)*(ushort *)((int)&DAT_00057498 + iVar3),
                         (undefined4 *)(&DAT_000574a0 + iVar3));
          }
        }
      }
      uVar4 = uVar4 + 0x18;
      iVar6 = iVar6 + 1;
    } while (uVar4 < 0x360);
    FUN_00027dd0(param_1,DAT_00057354 >> 1 & 1);
    uVar4 = 0;
    do {
      FUN_0002f6e8(*(int *)(param_1 + 0x1bc),uVar4);
      uVar4 = uVar4 + 1;
    } while (uVar4 < 0xc);
    FUN_00026eac(param_1);
    iVar6 = *(int *)(param_1 + 0x1bc);
    if (((&DAT_0005749c)[iVar6 * 0x123] != 0) &&
       (*(int *)(param_1 + 0x1c0) = (&DAT_0005749c)[iVar6 * 0x123], iVar6 == 0)) {
      *(ushort *)(param_1 + 0x1c8) = DAT_00057498;
    }
    if (*(int *)(param_1 + 0x4c) == 1) {
      if ((iVar6 == 0) && ((DAT_00057354 & 2) == 2)) {
        if (DAT_0005749c != 0) {
          uVar4 = (uint)DAT_00057498;
          *(ushort *)(param_1 + 0x1c8) = DAT_00057498;
          iVar6 = FUN_0002e300(DAT_00057348,uVar4);
          *(int *)(param_1 + 0x1c0) = iVar6;
          if (iVar6 == 0) {
            *(int *)(param_1 + 0x1c0) = (&DAT_0005749c)[*(int *)(param_1 + 0x1bc) * 0x123];
          }
        }
        *(undefined4 *)(param_1 + 0x1d4) = 0;
        *(undefined1 *)(*(int *)(param_1 + 0x44) + 0x614) = 0;
        FUN_00027654(param_1,1,0);
        if (*(ushort *)(param_1 + 0x1c8) != 0) {
          FUN_0002e27c(DAT_00057348,(uint)*(ushort *)(param_1 + 0x1c8),
                       (undefined4 *)(*(int *)(param_1 + 0x44) + 0x617));
        }
      }
      else {
        *(undefined4 *)(param_1 + 0x1d4) = 0;
        *(undefined1 *)(*(int *)(param_1 + 0x44) + 0x614) = 0;
        FUN_00027654(param_1,1,0);
      }
    }
    else {
      (&DAT_00057370)[iVar6 * 0x246] = *(undefined2 *)(param_1 + 0x1c8);
      (&DAT_00057374)[*(int *)(param_1 + 0x1bc) * 0x123] = *(undefined4 *)(param_1 + 0x1c0);
      FUN_00029af8(param_1);
    }
    FUN_00015b90(DAT_000553cc,3,0x20,0,0,0x1e);
    *(undefined1 *)(*(int *)(param_1 + 0x44) + 0x667) = 0;
    *(undefined1 *)(*(int *)(param_1 + 0x44) + 0x668) = 0;
    FUN_000338ac(0x69,0);
    FUN_00015f10(DAT_000553cc,3,1,0x21,0,0,100);
    *(undefined4 *)(param_1 + 0x1f0) = 0;
    *(undefined4 *)(param_1 + 0x1ec) = 0;
    *(undefined4 *)(param_1 + 500) = 0;
    *(undefined4 *)(param_1 + 0x1f8) = 0;
    *(undefined4 *)(param_1 + 0x1fc) = 0;
    *(undefined4 *)(param_1 + 0x1d8) = 0;
    *(undefined4 *)(param_1 + 0x1dc) = 0;
  }
  else {
    NKDbgPrintfW(L"%S : Sub-Mode is not SUBMODE_AST. Check it out.!!!\r\n","CRadio::StopSubModeAST")
    ;
  }
  return;
}



/* 0002ab90 FUN_0002ab90 */

/* Boundary evidence: original MIPS .pdata 0002ab90..0002acb3. Semantic name remains unreviewed. */

void FUN_0002ab90(int param_1)

{
  if (*(int *)(param_1 + 0x50) != 5) {
    NKDbgPrintfW(L"%S : SubMode is not SUBMODE_TA. Current SubMode=%d!!!!!!!!!!\r\n",
                 "CRadio::StopSubModeTA");
  }
  if (*(int *)(param_1 + 0x4c) != 1) {
    Sleep(200);
    FUN_00015f10(DAT_000553cc,3,1,0x20,0,0,100);
  }
  if (*(int *)(param_1 + 0x4c) == 2) {
    *(undefined1 *)(*(int *)(param_1 + 0x44) + 0x617) = 0;
  }
  if (*(int *)(param_1 + 0x1d8) == 2) {
    NKDbgPrintfW(L"%S : Return to original frequency)\r\n","CRadio::StopSubModeTA",
                 *(undefined4 *)(param_1 + 0x4c));
    *(undefined4 *)(param_1 + 0x284) = 0;
  }
  *(undefined4 *)(param_1 + 0x1d8) = 0;
  if (*(int *)(param_1 + 500) == 1) {
    *(undefined4 *)(param_1 + 0x1dc) = 2;
  }
  else if (*(int *)(param_1 + 500) == 0x1f) {
    *(undefined4 *)(param_1 + 0x1dc) = 1;
  }
  else {
    *(undefined4 *)(param_1 + 0x1dc) = 0;
  }
  *(undefined2 *)(param_1 + 0x1e0) = 0;
  FUN_00026960(param_1,6);
  FUN_00029af8(param_1);
  return;
}



/* 0002acb4 FUN_0002acb4 */

/* Boundary evidence: original MIPS .pdata 0002acb4..0002aec3. Semantic name remains unreviewed. */

void FUN_0002acb4(int param_1,int param_2)

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
  *(undefined2 *)(param_1 + 0x1c8) = 0;
  *(undefined4 *)(param_1 + 0x1cc) = 0xffffffff;
  if (*(int *)(param_1 + 0x1d0) != 0xc) {
    *(undefined4 *)(param_1 + 0x1d0) = 0xc;
    *(undefined1 *)(*(int *)(param_1 + 0x44) + 0x613) = 0xc;
    FUN_000338ac(0x66,0);
  }
  *(undefined4 *)(param_1 + 0x1d4) = 0x24;
  *(undefined4 *)(param_1 + 0x1c4) = *(undefined4 *)(param_1 + 0x1c0);
  FUN_00015f10(DAT_000553cc,3,1,0x20,0,0,100);
  uVar1 = FUN_00026e3c(param_1);
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
  FUN_000299b8(param_1,param_2,1);
  FUN_00026db8(param_1);
  if (*(int *)(param_1 + 0x1e4) == 1) {
    FUN_000272d8(param_1,0);
    *(undefined4 *)(param_1 + 0x1e4) = 0;
  }
  FUN_000268d0(param_1,1,0x32);
  *(undefined4 *)(param_1 + 0x1f0) = 0;
  *(undefined4 *)(param_1 + 0x1ec) = 0;
  *(undefined4 *)(param_1 + 500) = 0;
  return;
}



/* 0002aec4 FUN_0002aec4 */

/* Boundary evidence: original MIPS .pdata 0002aec4..0002af1f. Semantic name remains unreviewed. */

void FUN_0002aec4(int param_1,undefined4 param_2)

{
  NKDbgPrintfW(L"%S : CurFreq=%d)\r\n","CRadio::StopSubModeTPSeek",param_2);
  *(undefined4 *)(param_1 + 0x1cc) = 0xffffffff;
  *(undefined2 *)(param_1 + 0x1c8) = 0;
  *(undefined4 *)(param_1 + 0x1c0) = param_2;
  FUN_00029af8(param_1);
  return;
}



/* 0002af20 FUN_0002af20 */

/* Boundary evidence: original MIPS .pdata 0002af20..0002af97. Semantic name remains unreviewed. */

void FUN_0002af20(int param_1,undefined4 param_2)

{
  NKDbgPrintfW(L"%S\r\n","CRadio::StopSubModeOffSeek");
  *(undefined4 *)(param_1 + 0x1cc) = 0xffffffff;
  *(undefined2 *)(param_1 + 0x1c8) = 0;
  *(undefined4 *)(param_1 + 0x1c0) = param_2;
  NKDbgPrintfW(L"%S : NOTI_APP_FREQCHG_SEEK_COMPLETE : m_nCurFreq-%d\r\n",
               "CRadio::StopSubModeOffSeek",param_2);
  FUN_00029af8(param_1);
  return;
}



/* 0002af98 FUN_0002af98 */

/* Boundary evidence: original MIPS .pdata 0002af98..0002b1a3. Semantic name remains unreviewed. */

void FUN_0002af98(int param_1)

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
        FUN_0002d83c(param_1);
        *(undefined4 *)(param_1 + 0x54) = 0;
      }
      else {
        NKDbgPrintfW(L"%S(nID=%d)\r\n","CRadio::KillTimer",0);
        *(undefined4 *)(param_1 + 0x48) = 0;
        FUN_0002d83c(param_1);
      }
    }
  }
  else if (iVar2 == 1) {
    FUN_000299b8(param_1,*(int *)(param_1 + 0x58),1);
    FUN_000299b8(param_1,*(int *)(param_1 + 0x58),1);
    FUN_00026db8(param_1);
  }
  else if (iVar2 == 2) {
    FUN_00026960(param_1,2);
    FUN_000268d0(param_1,6,500);
  }
  else {
    if (iVar2 == 3) {
      iVar2 = 3;
    }
    else {
      if (iVar2 != 4) {
        if (iVar2 == 5) {
          FUN_00026960(param_1,5);
          NKDbgPrintfW(L"%S : NOTI_APP_TA : Send IDM_MMCM_AMAIN_TA_PTY31_STOP\r\n","CRadio::OnTimer"
                      );
          FUN_000338ac(0x6e,0);
          return;
        }
        if (iVar2 != 6) {
          return;
        }
        NKDbgPrintfW(L"%S : TT_CHECK_TA_OFF : Running\r\n","CRadio::OnTimer");
        uVar1 = FUN_00016068(DAT_000553cc,4,0x12,local_18,1,0x32);
        if (uVar1 != 1) {
          return;
        }
        if ((local_18[0] != '\0') && (local_18[0] != '\x02')) {
          return;
        }
        FUN_00026960(param_1,6);
        FUN_00026c1c(param_1);
        return;
      }
      iVar2 = 4;
    }
    FUN_00026960(param_1,iVar2);
    FUN_00029af8(param_1);
  }
  return;
}



/* 0002b1a4 FUN_0002b1a4 */

/* Boundary evidence: original MIPS .pdata 0002b1a4..0002bb7b. Semantic name remains unreviewed. */

void FUN_0002b1a4(int param_1,undefined4 param_2,uint param_3)

{
  ushort uVar1;
  int iVar2;
  int iVar3;
  undefined1 uVar4;
  uint uVar5;
  undefined1 local_28;
  undefined1 local_27 [7];
  
  switch(param_2) {
  case 0x65:
    if ((DAT_00057354 >> 0xb & 3) != param_3) {
      *(undefined1 *)(param_1 + 0x200) = 0;
      *(undefined1 *)(param_1 + 0x240) = 0;
      *(undefined1 *)(*(int *)(param_1 + 0x44) + 0x617) = 0;
      *(undefined1 *)(*(int *)(param_1 + 0x44) + 0x615) = 0;
      *(undefined1 *)(*(int *)(param_1 + 0x44) + 0x623) = 0;
      iVar2 = *(int *)(param_1 + 0x50);
      if ((iVar2 == 3) || (iVar2 == 2)) {
        if (iVar2 == 2) {
          FUN_00015f10(DAT_000553cc,3,1,0x21,0,0,100);
        }
        *(undefined4 *)(param_1 + 0x1c0) = *(undefined4 *)(param_1 + 0x1c4);
      }
      if (*(int *)(param_1 + 0x4c) == 1) {
        FUN_00027458(param_1,0);
      }
      DAT_00057354 = (param_3 << 0xb ^ DAT_00057354) & 0x1800 ^ DAT_00057354;
      FUN_00027500(param_1);
      FUN_00027654(param_1,0,1);
      FUN_00011500(DAT_00055384,1,0);
    }
    break;
  case 0x6a:
    if (*(int *)(param_1 + 0x4c) == 1) {
      FUN_00026eac(param_1);
      FUN_00027914(param_1,param_3);
    }
    break;
  case 0x6b:
    FUN_00026eac(param_1);
    iVar2 = *(int *)(param_1 + 0x50);
    *(undefined2 *)(param_1 + 0x1c8) = 0;
    if (((iVar2 != 2) && (iVar2 != 3)) && (iVar2 != 4)) {
      FUN_000299b8(param_1,param_3,0);
    }
    goto LAB_0002b7d4;
  case 0x6c:
    FUN_00026eac(param_1);
    FUN_0002acb4(param_1,param_3);
    break;
  case 0x6d:
    FUN_0002a30c(param_1);
    break;
  case 0x6e:
    if (*(int *)(param_1 + 0x50) != 4) {
      return;
    }
    *(undefined2 *)(param_1 + 0x1c8) = 0;
    *(undefined1 *)(*(int *)(param_1 + 0x44) + 0x667) = 0;
    *(undefined1 *)(*(int *)(param_1 + 0x44) + 0x668) = 0;
LAB_0002b7d4:
    FUN_00027654(param_1,0,0);
    break;
  case 0x6f:
    if (param_3 < 0x30) {
      if (param_3 < 0xc) {
        if (*(uint *)(param_1 + 0x1d0) == param_3) {
          return;
        }
        if ((&DAT_0005737c)[param_3 * 6 + *(int *)(param_1 + 0x1bc) * 0x123] == 0) {
          return;
        }
        uVar4 = (undefined1)param_3;
        if ((DAT_00057354 & 2) != 2) {
          *(undefined1 *)(param_1 + 0x200) = 0;
          *(undefined1 *)(param_1 + 0x240) = 0;
          *(undefined1 *)(*(int *)(param_1 + 0x44) + 0x617) = 0;
          *(undefined1 *)(*(int *)(param_1 + 0x44) + 0x615) = 0;
          *(undefined1 *)(*(int *)(param_1 + 0x44) + 0x623) = 0;
          *(undefined2 *)(param_1 + 0x1c8) = 0;
          *(undefined4 *)(param_1 + 0x1c0) =
               (&DAT_0005737c)[param_3 * 6 + *(int *)(param_1 + 0x1bc) * 0x123];
          *(uint *)(param_1 + 0x1d0) = param_3;
          *(undefined1 *)(*(int *)(param_1 + 0x44) + 0x613) = uVar4;
          (&DAT_0005736c)[*(int *)(param_1 + 0x1bc) * 0x48c] =
               (char)*(undefined4 *)(param_1 + 0x1d0);
LAB_0002b6d4:
          FUN_00027654(param_1,1,0);
          goto LAB_0002b6e4;
        }
        if (*(ushort *)(param_1 + 0x1c8) != 0) {
          uVar1 = (&DAT_00057378)[param_3 * 0xc + *(int *)(param_1 + 0x1bc) * 0x246];
          if ((uint)*(ushort *)(param_1 + 0x1c8) == (uint)uVar1) {
            *(ushort *)(param_1 + 0x1c8) = uVar1;
            iVar2 = FUN_0002e300(DAT_00057348,(uint)uVar1);
            *(uint *)(param_1 + 0x1d0) = param_3;
            *(int *)(param_1 + 0x1c0) = iVar2;
            *(undefined1 *)(*(int *)(param_1 + 0x44) + 0x613) = uVar4;
            (&DAT_0005736c)[*(int *)(param_1 + 0x1bc) * 0x48c] =
                 (char)*(undefined4 *)(param_1 + 0x1d0);
            return;
          }
        }
        *(undefined1 *)(param_1 + 0x200) = 0;
        *(undefined1 *)(param_1 + 0x240) = 0;
        *(undefined1 *)(*(int *)(param_1 + 0x44) + 0x617) = 0;
        *(undefined1 *)(*(int *)(param_1 + 0x44) + 0x615) = 0;
        *(undefined1 *)(*(int *)(param_1 + 0x44) + 0x623) = 0;
        uVar1 = (&DAT_00057378)[param_3 * 0xc + *(int *)(param_1 + 0x1bc) * 0x246];
        *(ushort *)(param_1 + 0x1c8) = uVar1;
        iVar2 = FUN_0002e300(DAT_00057348,(uint)uVar1);
        *(int *)(param_1 + 0x1c0) = iVar2;
        if (iVar2 == 0) {
          *(undefined4 *)(param_1 + 0x1c0) =
               (&DAT_0005737c)[param_3 * 6 + *(int *)(param_1 + 0x1bc) * 0x123];
        }
        *(uint *)(param_1 + 0x1d0) = param_3;
        *(undefined1 *)(*(int *)(param_1 + 0x44) + 0x613) = uVar4;
        (&DAT_0005736c)[*(int *)(param_1 + 0x1bc) * 0x48c] = (char)*(undefined4 *)(param_1 + 0x1d0);
      }
      else {
        iVar2 = param_3 - 0xc;
        if (*(int *)(param_1 + 0x1d4) == iVar2) {
          return;
        }
        if ((&DAT_0005737c)[param_3 * 6 + *(int *)(param_1 + 0x1bc) * 0x123] == 0) {
          return;
        }
        uVar4 = (undefined1)iVar2;
        if ((DAT_00057354 & 2) != 2) {
          *(undefined1 *)(param_1 + 0x200) = 0;
          *(undefined1 *)(param_1 + 0x240) = 0;
          *(undefined1 *)(*(int *)(param_1 + 0x44) + 0x617) = 0;
          *(undefined1 *)(*(int *)(param_1 + 0x44) + 0x615) = 0;
          *(undefined1 *)(*(int *)(param_1 + 0x44) + 0x623) = 0;
          *(undefined2 *)(param_1 + 0x1c8) = 0;
          *(undefined4 *)(param_1 + 0x1c0) =
               (&DAT_0005737c)[param_3 * 6 + *(int *)(param_1 + 0x1bc) * 0x123];
          *(int *)(param_1 + 0x1d4) = iVar2;
          *(undefined1 *)(*(int *)(param_1 + 0x44) + 0x614) = uVar4;
          goto LAB_0002b6d4;
        }
        if ((*(short *)(param_1 + 0x1c8) != 0) &&
           (*(short *)(param_1 + 0x1c8) ==
            (&DAT_00057378)[param_3 * 0xc + *(int *)(param_1 + 0x1bc) * 0x246])) {
          *(int *)(param_1 + 0x1d4) = iVar2;
          *(undefined1 *)(*(int *)(param_1 + 0x44) + 0x614) = uVar4;
          return;
        }
        *(undefined1 *)(param_1 + 0x200) = 0;
        *(undefined1 *)(param_1 + 0x240) = 0;
        *(undefined1 *)(*(int *)(param_1 + 0x44) + 0x617) = 0;
        *(undefined1 *)(*(int *)(param_1 + 0x44) + 0x615) = 0;
        *(undefined1 *)(*(int *)(param_1 + 0x44) + 0x623) = 0;
        uVar1 = (&DAT_00057378)[param_3 * 0xc + *(int *)(param_1 + 0x1bc) * 0x246];
        *(ushort *)(param_1 + 0x1c8) = uVar1;
        iVar3 = FUN_0002e300(DAT_00057348,(uint)uVar1);
        *(int *)(param_1 + 0x1c0) = iVar3;
        if (iVar3 == 0) {
          *(undefined4 *)(param_1 + 0x1c0) =
               (&DAT_0005737c)[param_3 * 6 + *(int *)(param_1 + 0x1bc) * 0x123];
        }
        *(int *)(param_1 + 0x1d4) = iVar2;
        *(undefined1 *)(*(int *)(param_1 + 0x44) + 0x614) = uVar4;
      }
      FUN_00027654(param_1,1,0);
      if (*(ushort *)(param_1 + 0x1c8) != 0) {
        FUN_0002e27c(DAT_00057348,(uint)*(ushort *)(param_1 + 0x1c8),
                     (undefined4 *)(*(int *)(param_1 + 0x44) + 0x617));
      }
LAB_0002b6e4:
      FUN_000338ac(0x6a,0);
      FUN_000338ac(0x6b,0);
      FUN_000338ac(0x6c,0);
      *(undefined4 *)(param_1 + 0x1f8) = 0;
      *(undefined4 *)(param_1 + 0x1fc) = 0;
      *(undefined4 *)(param_1 + 0x1d8) = 0;
      *(undefined4 *)(param_1 + 0x1dc) = 0;
      return;
    }
    if (param_3 < 0x65) {
      return;
    }
    if (199999 < param_3) {
      return;
    }
    *(uint *)(param_1 + 0x1c0) = param_3;
    goto LAB_0002b740;
  case 0x70:
    if (*(int *)(param_1 + 0x50) == 2) {
      FUN_00026960(param_1,1);
LAB_0002b870:
      FUN_00029af8(param_1);
      FUN_00026db8(param_1);
      FUN_00027654(param_1,1,0);
    }
    else if (*(int *)(param_1 + 0x50) == 3) goto LAB_0002b870;
    FUN_000269e8(param_1,param_3);
    break;
  case 0x81:
    if (*(byte *)(*(int *)(param_1 + 0x44) + 0x60c) == param_3) {
      return;
    }
    *(bool *)(*(int *)(param_1 + 0x44) + 0x60c) = param_3 != 0;
    DAT_00057354 = ((uint)(param_3 != 0) << 1 ^ DAT_00057354) & 2 ^ DAT_00057354;
    if (DAT_00054c94 != '\x04') {
      DAT_00057354 = (DAT_00057354 << 1 ^ DAT_00057354) & 4 ^ DAT_00057354;
    }
    FUN_00027dd0(param_1,DAT_00057354 >> 1 & 1);
    uVar5 = 0;
    do {
      FUN_0002f6e8(0,uVar5);
      uVar5 = uVar5 + 1;
    } while (uVar5 < 0xc);
    FUN_00028e4c();
    FUN_00028dec();
    if ((DAT_00057354 & 2) == 2) {
      local_28 = 0;
      FUN_00015b90(DAT_000553cc,4,0x80,(int)&local_28,1,0x32);
      local_27[0] = 0;
      FUN_00015b90(DAT_000553cc,3,8,(int)local_27,1,100);
    }
    else {
      local_27[0] = 1;
      FUN_00015b90(DAT_000553cc,4,0x80,(int)local_27,1,0x32);
      local_28 = 1;
      FUN_00015b90(DAT_000553cc,3,8,(int)&local_28,1,100);
    }
LAB_0002b740:
    *(undefined2 *)(param_1 + 0x1c8) = 0;
    FUN_00027654(param_1,1,0);
    FUN_00026eac(param_1);
    *(undefined4 *)(param_1 + 0x1f8) = 0;
    *(undefined4 *)(param_1 + 0x1fc) = 0;
    break;
  case 0x82:
    DAT_00057354 = ((uint)(param_3 != 0) << 3 ^ DAT_00057354) & 8 ^ DAT_00057354;
    *(bool *)(*(int *)(param_1 + 0x44) + 0x60d) = param_3 != 0;
    break;
  case 0x83:
    DAT_00057354 = ((uint)(param_3 != 0) << 4 ^ DAT_00057354) & 0x10 ^ DAT_00057354;
    FUN_00028e4c();
    *(bool *)(*(int *)(param_1 + 0x44) + 0x60e) = param_3 != 0;
    break;
  case 0x84:
    DAT_00057354 = ((uint)(param_3 != 0) << 5 ^ DAT_00057354) & 0x20 ^ DAT_00057354;
    *(bool *)(*(int *)(param_1 + 0x44) + 0x60f) = param_3 != 0;
    break;
  case 0x85:
    DAT_00057354 = ((uint)(param_3 != 0) << 6 ^ DAT_00057354) & 0x40 ^ DAT_00057354;
    *(bool *)(*(int *)(param_1 + 0x44) + 0x610) = param_3 != 0;
    break;
  case 0x8d:
    DAT_00057354 = ((uint)(param_3 != 0) << 2 ^ DAT_00057354) & 4 ^ DAT_00057354;
    FUN_00028dec();
  }
  return;
}



/* 0002bb7c FUN_0002bb7c */

/* Boundary evidence: original MIPS .pdata 0002bb7c..0002bca3. Semantic name remains unreviewed. */

void FUN_0002bb7c(int param_1)

{
  int iVar1;
  
  NKDbgPrintfW(L"%S : Current main mode = %d\r\n","CRadio::ChangeToOffMode",
               *(undefined4 *)(param_1 + 0x4c));
  if (*(int *)(param_1 + 0x4c) == 1) {
    if ((*(int *)(param_1 + 0x50) == 3) || (*(int *)(param_1 + 0x50) == 2)) {
      *(undefined4 *)(param_1 + 0x1c0) = *(undefined4 *)(param_1 + 0x1c4);
      FUN_00026db8(param_1);
    }
    FUN_00027458(param_1,0);
    if (*(int *)(param_1 + 0x1e4) == 1) {
      FUN_000272d8(param_1,1);
    }
    iVar1 = *(int *)(param_1 + 0x50);
    *(undefined4 *)(param_1 + 0x284) = 0;
    *(undefined4 *)(param_1 + 0x4c) = 0;
    if ((iVar1 != 0) && (iVar1 != 3)) {
      if (iVar1 != 2) {
        return;
      }
      FUN_00026960(param_1,1);
    }
  }
  else {
    if (*(int *)(param_1 + 0x4c) != 2) {
      return;
    }
    if (*(int *)(param_1 + 0x1e4) == 1) {
      FUN_000272d8(param_1,1);
    }
    *(undefined4 *)(param_1 + 0x284) = 0;
    *(undefined4 *)(param_1 + 0x4c) = 0;
    if ((*(int *)(param_1 + 0x50) != 0) && (*(int *)(param_1 + 0x50) != 8)) {
      return;
    }
  }
  FUN_00029af8(param_1);
  return;
}



/* 0002bca4 FUN_0002bca4 */

/* Boundary evidence: original MIPS .pdata 0002bca4..0002bdaf. Semantic name remains unreviewed. */

void FUN_0002bca4(int param_1)

{
  int iVar1;
  
  NKDbgPrintfW(L"%S : Current main mode = %d)\r\n","CRadio::ChangeToFgMode",
               *(undefined4 *)(param_1 + 0x4c));
  if (*(int *)(param_1 + 0x4c) == 0) {
    iVar1 = *(int *)(param_1 + 0x50);
    *(undefined4 *)(param_1 + 0x284) = 0;
    *(undefined4 *)(param_1 + 0x4c) = 1;
    if (iVar1 != 0) {
      if (iVar1 == 4) goto LAB_0002bd84;
      if (iVar1 == 6) goto LAB_0002bd98;
      if (iVar1 == 7) goto LAB_0002bd30;
joined_r0x0002bd74:
      if (iVar1 != 8) {
        return;
      }
      goto LAB_0002bd98;
    }
LAB_0002bd8c:
    iVar1 = 4;
  }
  else {
    if (*(int *)(param_1 + 0x4c) != 2) {
      return;
    }
    iVar1 = *(int *)(param_1 + 0x50);
    *(undefined4 *)(param_1 + 0x284) = 0;
    *(undefined4 *)(param_1 + 0x4c) = 1;
    if (iVar1 == 0) goto LAB_0002bd8c;
    if (iVar1 == 4) {
LAB_0002bd84:
      *(undefined4 *)(param_1 + 0x284) = 1;
      return;
    }
    if (iVar1 == 6) goto LAB_0002bd98;
    if (iVar1 != 7) goto joined_r0x0002bd74;
LAB_0002bd30:
    iVar1 = 3;
  }
  FUN_00026960(param_1,iVar1);
LAB_0002bd98:
  FUN_00029af8(param_1);
  return;
}



/* 0002bdb0 FUN_0002bdb0 */

/* Boundary evidence: original MIPS .pdata 0002bdb0..0002bf0b. Semantic name remains unreviewed. */

void FUN_0002bdb0(int param_1)

{
  int iVar1;
  
  NKDbgPrintfW(L"%S : Current main mode = %d\r\n","CRadio::ChangeToBgMode",
               *(undefined4 *)(param_1 + 0x4c));
  if (*(int *)(param_1 + 0x4c) == 0) {
    if (*(int *)(param_1 + 0x1e4) == 1) {
      FUN_000272d8(param_1,1);
    }
    *(undefined4 *)(param_1 + 0x288) = DAT_00057374;
    *(undefined4 *)(param_1 + 0x284) = 0;
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
      *(undefined4 *)(param_1 + 0x1c0) = *(undefined4 *)(param_1 + 0x1c4);
      FUN_00026db8(param_1);
    }
    else if (iVar1 == 0) {
      *(undefined1 *)(*(int *)(param_1 + 0x44) + 0x617) = 0;
      *(undefined1 *)(*(int *)(param_1 + 0x44) + 0x615) = 0;
      *(undefined1 *)(*(int *)(param_1 + 0x44) + 0x623) = 0;
    }
    FUN_00027458(param_1,0);
    if (*(int *)(param_1 + 0x1e4) == 1) {
      FUN_000272d8(param_1,1);
    }
    iVar1 = *(int *)(param_1 + 0x50);
    *(undefined4 *)(param_1 + 0x288) = DAT_00057374;
    *(undefined4 *)(param_1 + 0x284) = 0;
    *(undefined4 *)(param_1 + 0x4c) = 2;
    if ((iVar1 != 0) && (iVar1 != 3)) {
      if (iVar1 != 2) {
        return;
      }
      FUN_00026960(param_1,1);
    }
  }
  FUN_00029af8(param_1);
  return;
}



/* 0002bf0c FUN_0002bf0c */

/* Boundary evidence: original MIPS .pdata 0002bf0c..0002bfd3. Semantic name remains unreviewed. */

void FUN_0002bf0c(int param_1,int param_2)

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
    if ((((*(int *)(param_1 + 0x1ec) == 1) || (*(int *)(param_1 + 500) == 1)) ||
        (*(int *)(param_1 + 500) == 0x1f)) || (*(int *)(param_1 + 0x1f0) == 1)) {
      FUN_00028af8(param_1);
    }
    else {
      FUN_000338ac(0x6e,0);
    }
  }
  else {
    FUN_0002ab90(param_1);
  }
  return;
}



/* 0002bfd4 FUN_0002bfd4 */

/* Boundary evidence: original MIPS .pdata 0002bfd4..0002c09f. Semantic name remains unreviewed. */

void FUN_0002bfd4(int param_1,int param_2)

{
  if (*(int *)(param_1 + 0x50) == 3) {
    *(undefined4 *)(param_1 + 0x1cc) = 0xffffffff;
    *(undefined2 *)(param_1 + 0x1c8) = 0;
    *(int *)(param_1 + 0x1c0) = param_2;
    NKDbgPrintfW(L"%S : m_nCurFreq-%d\r\n","CRadio::StopSubModeSeek",param_2);
    FUN_0002a0c8(param_1,DAT_00057354 >> 1 & 1,param_2);
    if (0xb < *(uint *)(param_1 + 0x1d0)) {
      FUN_00026f0c(param_1);
    }
    FUN_00027124(param_1);
    FUN_00026db8(param_1);
    FUN_00029af8(param_1);
  }
  else {
    NKDbgPrintfW(L"%S : Sub-Mode is not SUBMODE_SEEK. Check it out.!!!\r\n",
                 "CRadio::StopSubModeSeek");
  }
  return;
}



/* 0002c0a0 FUN_0002c0a0 */

/* Boundary evidence: original MIPS .pdata 0002c0a0..0002d6af. Semantic name remains unreviewed. */

void FUN_0002c0a0(int param_1,uint *param_2)

{
  byte bVar1;
  ushort uVar2;
  HWND hWnd;
  wchar_t *pwVar3;
  LPARAM LVar4;
  WPARAM wParam;
  int iVar5;
  size_t _Size;
  uint uVar6;
  int iVar7;
  uint uVar8;
  char *_Src;
  uint *puVar9;
  undefined8 uVar10;
  undefined8 uVar11;
  undefined8 uVar12;
  undefined8 uVar13;
  undefined8 uVar14;
  undefined1 local_30 [4];
  FILE *local_2c;
  
  uVar6 = *param_2 >> 8 & 0xf;
  if (uVar6 != 2) {
    if (uVar6 != 3) {
      return;
    }
    if (*(char *)((int)param_2 + 2) != '\x02') {
      return;
    }
    NKDbgPrintfW(L"%S : CMD_APP_RADIO_ALIGNMENT_NOTI : %d : ","CRadio::OnCommand",
                 *(undefined1 *)((int)param_2 + 5));
    uVar6 = param_2[1];
    uVar8 = 0;
    if ((byte)uVar6 != 2) {
      puVar9 = param_2 + 2;
      do {
        *(undefined1 *)(param_1 + 0xc + uVar8) = *(undefined1 *)((int)param_2 + uVar8 + 6);
        NKDbgPrintfW(L"0x%02X ",(short)*puVar9);
        uVar8 = uVar8 + 1;
        puVar9 = (uint *)((int)puVar9 + 2);
      } while (uVar8 < (byte)uVar6 - 2);
    }
    NKDbgPrintfW(&DAT_0004e8b4);
    hWnd = *(HWND *)(param_1 + 0x5c);
    if (hWnd == (HWND)0x0) {
      return;
    }
    uVar6 = (uint)*(byte *)((int)param_2 + 5);
    wParam = 4;
    goto LAB_0002d554;
  }
  bVar1 = *(byte *)((int)param_2 + 2);
  if (bVar1 < 0x4e) {
    if (bVar1 != 0x4d) {
      if (bVar1 < 0x46) {
        if (bVar1 != 0x45) {
          if (0x41 < bVar1) {
            if (bVar1 == 0x42) {
              *(undefined2 *)(param_1 + 0x1c8) = 0;
              *(undefined4 *)(param_1 + 0x1e4) = 0;
              NKDbgPrintfW(L"%S : NOTI_APP_FREQCHG_STATION_TUNE_FAIL : %d\r\n","CRadio::OnCommand",
                           param_2[1]);
              uVar6 = param_2[1];
              goto LAB_0002c498;
            }
            if (bVar1 != 0x43) {
              if (bVar1 != 0x44) {
                return;
              }
              FUN_0002a5b4(param_1,param_2[1]);
              return;
            }
            if (*(int *)(param_1 + 0x4c) != 1) {
              return;
            }
            iVar5 = *(int *)(param_1 + 0x50);
            if ((iVar5 == 3) || (iVar5 == 2)) {
              FUN_0002bfd4(param_1,param_2[1]);
              return;
            }
            if (iVar5 != 6) {
              NKDbgPrintfW(L"%S : Sub-Mode(%d) is not SUBMODE_SEEK/SUBMODE_OFF_SEEK. Check it out.!!! m_nCurFreq %d\r\n"
                           ,"CRadio::OnCommand",iVar5,*(undefined4 *)(param_1 + 0x1c0));
              if (param_2[1] == *(uint *)(param_1 + 0x1c0)) {
                return;
              }
              goto LAB_0002c560;
            }
            goto LAB_0002c524;
          }
          if (bVar1 == 0x41) {
            *(undefined4 *)(param_1 + 0x1e4) = 0;
            *(uint *)(param_1 + 0x1c0) = (*(ushort *)((int)param_2 + 6) + 0x36b) * 100;
            NKDbgPrintfW(L"%S : NOTI_APP_FREQCHG_STATION_TUNE_RGN : %04X, %d\r\n",
                         "CRadio::OnCommand",(short)param_2[1]);
            FUN_0002903c(param_1,(uint)(ushort)param_2[1]);
            uVar6 = *(uint *)(param_1 + 0x1c0);
LAB_0002c498:
            FUN_00029e30(param_1,uVar6);
            FUN_00026f0c(param_1);
            FUN_00027124(param_1);
            return;
          }
          if (bVar1 == 0) {
            FUN_00028eac();
            if (DAT_00054c94 == '\0') {
              local_30[0] = (DAT_00057354 & 2) != 2;
              FUN_00015b90(DAT_000553cc,4,0x80,(int)local_30,1,0x32);
              DAT_00057354 = (DAT_00057354 << 1 ^ DAT_00057354) & 4 ^ DAT_00057354;
              pwVar3 = L"[RADIO RDS] case CMD_APP_BOOT_STAT_NOTI : g_stData.en_rds = %d\r\n";
            }
            else if (DAT_00054c94 == '\x04') {
              local_30[0] = (DAT_00057354 & 2) != 2;
              FUN_00015b90(DAT_000553cc,4,0x80,(int)local_30,1,0x32);
              DAT_00057354 = DAT_00057354 & 0xfffffffb;
              pwVar3 = 
              L"[RADIO RDS] case CMD_APP_BOOT_STAT_NOTI ( America ) : g_stData.en_rds = %d\r\n";
            }
            else {
              local_30[0] = (DAT_00057354 & 2) != 2;
              FUN_00015b90(DAT_000553cc,4,0x80,(int)local_30,1,0x32);
              DAT_00057354 = (DAT_00057354 << 1 ^ DAT_00057354) & 4 ^ DAT_00057354;
              pwVar3 = 
              L"[RADIO RDS] case CMD_APP_BOOT_STAT_NOTI :(Asia / Africa) g_stData.en_rds = %d\r\n";
            }
            NKDbgPrintfW(pwVar3,DAT_00057354 >> 1 & 1);
            FUN_00028e4c();
            FUN_00028dec();
            if ((DAT_00057354 & 2) == 2) {
              local_30[0] = 0;
              FUN_00015b90(DAT_000553cc,3,8,(int)local_30,1,100);
              return;
            }
            local_30[0] = 1;
            FUN_00015b90(DAT_000553cc,3,8,(int)local_30,1,100);
            return;
          }
          if (bVar1 != 0x1e) {
            if (bVar1 != 0x1f) {
              if (bVar1 != 0x40) {
                return;
              }
              FUN_00029e30(param_1,param_2[1]);
              return;
            }
            if (*(int *)(param_1 + 0x5c) == 0) {
              return;
            }
            wParam = 9;
            *(uint *)(param_1 + 0x2c) = param_2[1];
            *(uint *)(param_1 + 0x30) = param_2[2];
            *(uint *)(param_1 + 0x34) = param_2[3];
            *(short *)(param_1 + 0x38) = (short)param_2[4];
            goto LAB_0002d54c;
          }
          hWnd = *(HWND *)(param_1 + 0x5c);
          if (hWnd == (HWND)0x0) {
            return;
          }
          wParam = 10;
          goto LAB_0002d550;
        }
        if (*(int *)(param_1 + 0x1bc) != 0) {
          return;
        }
        if (*(int *)(param_1 + 0x4c) != 1) {
          return;
        }
        uVar6 = ((byte)param_2[1] + 0x36b) * 100;
      }
      else {
        if (bVar1 == 0x46) {
          if ((DAT_00057354 & 2) != 2) {
            return;
          }
          if (*(int *)(param_1 + 0x1bc) != 0) {
            return;
          }
          if (*(int *)(param_1 + 0x50) == 3) {
            return;
          }
          if (*(int *)(param_1 + 0x50) == 4) {
            return;
          }
          if (*(int *)(param_1 + 0x1e4) == 1) {
            FUN_000272d8(param_1,0);
            *(undefined4 *)(param_1 + 0x1e4) = 0;
          }
          *(uint *)(param_1 + 0x1c0) = (*(ushort *)((int)param_2 + 6) + 0x36b) * 100;
          NKDbgPrintfW(L"%S : NOTI_APP_FREQCHG_RGN_JUMP_COMPLETE : %04X, %d\r\n","CRadio::OnCommand"
                       ,(short)param_2[1]);
          FUN_0002903c(param_1,(uint)(ushort)param_2[1]);
          return;
        }
        if (bVar1 == 0x47) {
          if (*(int *)(param_1 + 0x4c) != 2) {
            return;
          }
          FUN_0002aec4(param_1,param_2[1]);
          return;
        }
        if (bVar1 != 0x48) {
          if (bVar1 != 0x49) {
            if (bVar1 != 0x4a) {
              if (bVar1 == 0x4b) {
                if ((DAT_00057354 & 2) != 2) {
                  return;
                }
                FUN_00026eac(param_1);
                FUN_0002903c(param_1,(uint)(ushort)param_2[1]);
                FUN_000272d8(param_1,0);
                return;
              }
              if (bVar1 != 0x4c) {
                return;
              }
              NKDbgPrintfW(L"%S : NOTI_APP_UPDATE_CUR_FREQ_OF_PI : 0x%04X, %d\r\n",
                           "CRadio::OnCommand",(short)param_2[1],
                           (*(ushort *)((int)param_2 + 6) + 0x36b) * 100);
              if (*(int *)(param_1 + 0x4c) != 1) {
                return;
              }
              FUN_0002ed04(DAT_00057348,(uint)(ushort)param_2[1],
                           (*(ushort *)((int)param_2 + 6) + 0x36b) * 100);
              return;
            }
            if ((DAT_00057354 & 2) != 2) {
              return;
            }
            if (((*(int *)(param_1 + 0x1bc) != 0) || (*(int *)(param_1 + 0x50) == 3)) ||
               (*(int *)(param_1 + 0x50) == 4)) {
              NKDbgPrintfW(L"%S : NOTI_APP_RAD_UPDATE_PI : Check it out.!!!\r\n","CRadio::OnCommand"
                          );
              return;
            }
            FUN_0002903c(param_1,(uint)(ushort)param_2[1]);
            FUN_0002e27c(DAT_00057348,(uint)*(ushort *)(param_1 + 0x1c8),
                         (undefined4 *)(*(int *)(param_1 + 0x44) + 0x617));
            iVar5 = 0x6a;
            goto LAB_0002c8ac;
          }
          *(char *)(*(int *)(param_1 + 0x44) + 0x668) = (char)param_2[1];
          FUN_000338ac(0x68,(uint)(byte)param_2[1]);
          hWnd = *(HWND *)(param_1 + 0x5c);
          if (hWnd == (HWND)0x0) {
            return;
          }
          uVar6 = (uint)(byte)param_2[1];
          wParam = 3;
          goto LAB_0002d554;
        }
        if (*(int *)(param_1 + 0x4c) != 1) {
          return;
        }
        if (*(int *)(param_1 + 0x50) != 3) {
          return;
        }
        uVar6 = param_2[1];
      }
      *(uint *)(param_1 + 0x1c0) = uVar6;
LAB_0002d508:
      FUN_00026db8(param_1);
      return;
    }
    *(char *)(*(int *)(param_1 + 0x44) + 0x612) = (char)param_2[1];
LAB_0002c8a8:
    iVar5 = 0x6f;
    goto LAB_0002c8ac;
  }
  if (0x80 < bVar1) {
    return;
  }
  if (bVar1 == 0x80) {
    local_2c = *(FILE **)(param_1 + 0x290);
    if (local_2c == (FILE *)0x0) {
      return;
    }
    uVar10 = __litodp((int)(short)param_2[3]);
    uVar10 = __dpmul((int)uVar10,(int)((ulonglong)uVar10 >> 0x20),0,0x3f690000);
    uVar11 = __litodp((int)*(short *)((int)param_2 + 10));
    uVar11 = __dpmul((int)uVar11,(int)((ulonglong)uVar11 >> 0x20),0,0x3f690000);
    uVar12 = __litodp((int)(short)param_2[2]);
    uVar12 = __dpmul((int)uVar12,(int)((ulonglong)uVar12 >> 0x20),0,0x3f745000);
    uVar13 = __litodp((int)*(short *)((int)param_2 + 6));
    uVar13 = __dpmul((int)uVar13,(int)((ulonglong)uVar13 >> 0x20),0,0x3f690000);
    uVar14 = __litodp((uint)(ushort)param_2[1] * 5);
    uVar14 = __dpmul((int)uVar14,(int)((ulonglong)uVar14 >> 0x20),0xd2f1a9fc,0x3f50624d);
    fprintf_s(local_2c,"%6.2f\t%5.1f\t%5.1f\t%5.1f\t%5.1f\n",(int)uVar14,
              (int)((ulonglong)uVar14 >> 0x20),(int)uVar13,(int)((ulonglong)uVar13 >> 0x20),
              (int)uVar12,(int)((ulonglong)uVar12 >> 0x20),(int)uVar11,
              (int)((ulonglong)uVar11 >> 0x20),(int)uVar10,(int)((ulonglong)uVar10 >> 0x20));
    return;
  }
  switch(bVar1) {
  case 0x4e:
    uVar6 = param_2[1];
    NKDbgPrintfW(L"%S : NOTI_APP_TA : %d\r\n","CRadio::OnCommand",(char)uVar6);
    if ((char)uVar6 == '\0') {
      FUN_00026c1c(param_1);
      return;
    }
    if (*(int *)(param_1 + 0x1f8) == 1) {
      *(undefined4 *)(param_1 + 0x1f8) = 0;
      return;
    }
    *(undefined4 *)(param_1 + 0x1ec) = 1;
    if ((((DAT_00057354 & 8) != 8) ||
        ((*(int *)(param_1 + 0x4c) != 1 && (*(int *)(param_1 + 0x4c) != 2)))) ||
       ((*(int *)(param_1 + 0x50) != 0 &&
        ((*(int *)(param_1 + 0x50) != 5 || (*(int *)(param_1 + 0x1d8) == 2)))))) {
      if ((*(int *)(param_1 + 0x50) == 5) && (*(int *)(param_1 + 0x1d8) == 2)) {
        FUN_00026960(param_1,2);
        FUN_000268d0(param_1,6,500);
        return;
      }
      iVar5 = FUN_00011e38(DAT_00055384);
      if (((iVar5 != 8) && (iVar5 = FUN_00011e38(DAT_00055384), iVar5 != 10)) &&
         (iVar5 = FUN_00011e38(DAT_00055384), iVar5 != 7)) {
        return;
      }
      *(undefined4 *)(param_1 + 0x1fc) = 1;
      return;
    }
    *(undefined4 *)(param_1 + 0x1d8) = 1;
    *(undefined2 *)(param_1 + 0x1e0) = 0;
    FUN_0002e27c(DAT_00057348,(uint)*(ushort *)(param_1 + 0x1c8),
                 (undefined4 *)(*(int *)(param_1 + 0x44) + 0x617));
    goto LAB_0002d274;
  case 0x4f:
    if ((DAT_00057354 & 8) != 8) {
      return;
    }
    if ((*(int *)(param_1 + 0x4c) != 1) && (*(int *)(param_1 + 0x4c) != 2)) {
      return;
    }
    if (*(int *)(param_1 + 0x50) != 0) {
      return;
    }
    *(undefined4 *)(param_1 + 0x1ec) = 1;
    *(undefined4 *)(param_1 + 0x1d8) = 1;
    *(undefined2 *)(param_1 + 0x1e0) = 0;
LAB_0002d274:
    NKDbgPrintfW(L"%S : NOTI_APP_TA : Send IDM_MMCM_AMAIN_TA_PTY31_START\r\n","CRadio::OnCommand");
    LVar4 = *(LPARAM *)(param_1 + 0x1d8);
    iVar5 = 0x6d;
LAB_0002c8b0:
    FUN_000338ac(iVar5,LVar4);
    break;
  case 0x50:
    uVar2 = (ushort)param_2[1];
    if (uVar2 != 0) {
      if (*(short *)(param_1 + 0x1e0) != 0) {
        return;
      }
      *(ushort *)(param_1 + 0x1e0) = uVar2;
      if (((((DAT_00057354 & 8) != 8) || (*(int *)(param_1 + 0x50) != 0)) ||
          (*(int *)(param_1 + 0x4c) != 1)) ||
         (uVar6 = FUN_0002e3b0(DAT_00057348,(uint)uVar2), (int)uVar6 < 0)) {
        *(undefined2 *)(param_1 + 0x1e0) = 0;
        return;
      }
      *(undefined4 *)(param_1 + 0x1f0) = 1;
      *(undefined4 *)(param_1 + 0x1d8) = 2;
      FUN_0002e27c(DAT_00057348,(uint)*(ushort *)(param_1 + 0x1e0),
                   (undefined4 *)(*(int *)(param_1 + 0x44) + 0x617));
      goto LAB_0002d274;
    }
    *(undefined4 *)(param_1 + 0x1f0) = 0;
    iVar5 = 0x6e;
    *(undefined2 *)(param_1 + 0x1e0) = 0;
    goto LAB_0002c8ac;
  case 0x51:
    if (*(int *)(param_1 + 0x280) != 0) {
      return;
    }
    puVar9 = param_2 + 1;
    NKDbgPrintfW(L"%S : Update PSN(%d,%c%c%c%c%c%c%c%c).\r\n","CRadio::OnCommand",(ushort)*puVar9,
                 *(undefined1 *)((int)param_2 + 6),*(undefined1 *)((int)param_2 + 7),
                 (char)param_2[2],*(undefined1 *)((int)param_2 + 9),
                 *(undefined1 *)((int)param_2 + 10),*(undefined1 *)((int)param_2 + 0xb),
                 (char)param_2[3],*(undefined1 *)((int)param_2 + 0xd));
    iVar5 = FUN_0002e488(DAT_00057348,(uint)(ushort)*puVar9,(undefined4 *)((int)param_2 + 6));
    if (iVar5 == 1) {
      iVar5 = 0;
      uVar6 = 0;
      do {
        if ((*(int *)((int)&DAT_0005737c + uVar6) != 0) &&
           ((uint)*(ushort *)((int)&DAT_00057378 + uVar6) == (uint)(ushort)*puVar9)) {
          FUN_0002e27c(DAT_00057348,(uint)(ushort)*puVar9,(undefined4 *)(&DAT_00057380 + uVar6));
          FUN_0002f6e8(0,iVar5);
        }
        uVar6 = uVar6 + 0x18;
        iVar5 = iVar5 + 1;
      } while (uVar6 < 0x120);
      uVar6 = 0;
      do {
        if ((*(int *)((int)&DAT_0005749c + uVar6) != 0) &&
           ((uint)*(ushort *)((int)&DAT_00057498 + uVar6) == (uint)(ushort)*puVar9)) {
          FUN_0002e27c(DAT_00057348,(uint)(ushort)*puVar9,(undefined4 *)(&DAT_000574a0 + uVar6));
        }
        uVar6 = uVar6 + 0x18;
      } while (uVar6 < 0x360);
    }
    FUN_00027dd0(param_1,DAT_00057354 >> 1 & 1);
    uVar6 = 0;
    do {
      FUN_0002f8d4(*(int *)(param_1 + 0x1bc),uVar6);
      uVar6 = uVar6 + 1;
    } while (uVar6 < 0x24);
    FUN_00027124(param_1);
    goto LAB_0002cd5c;
  case 0x52:
    *(undefined1 *)(*(int *)(param_1 + 0x44) + 0x611) = 0;
    *(undefined1 *)(*(int *)(param_1 + 0x44) + 0x612) = 0;
    goto LAB_0002c8a8;
  case 0x53:
    iVar5 = *(int *)(param_1 + 0x44);
    *(uint *)(param_1 + 500) = (uint)(byte)param_2[1];
    if ((*(char *)(iVar5 + 0x615) != (char)param_2[1]) && ((DAT_00057354 & 2) == 2)) {
      iVar7 = *(int *)(param_1 + 0x4c);
joined_r0x0002cf1c:
      if ((iVar7 == 1) || (*(int *)(param_1 + 0x280) == 0)) {
        *(char *)(iVar5 + 0x615) = (char)param_2[1];
        FUN_000338ac(0x6b,0);
      }
    }
    goto LAB_0002cf44;
  case 0x54:
    if (*(int *)(param_1 + 0x1d8) != 2) {
      if ((char)param_2[1] == '\x01') {
        if (*(int *)(param_1 + 0x1fc) != 1) {
          if (((((DAT_00057354 & 0x20) == 0x20) &&
               ((*(int *)(param_1 + 0x4c) == 1 || (*(int *)(param_1 + 0x4c) == 2)))) &&
              ((*(int *)(param_1 + 0x50) == 0 || (*(int *)(param_1 + 0x50) == 5)))) &&
             (iVar5 = *(int *)(param_1 + 0x48), iVar5 != 4)) {
            if (iVar5 == 5) {
              FUN_00026960(param_1,5);
            }
            else if ((iVar5 != 6) && (iVar5 != 0)) {
              NKDbgPrintfW(L"%S : Other Timer is already started. Check it out.!!!!!!!!(OLD:%d)\r\n"
                           ,"CRadio::OnCommand");
            }
            *(undefined4 *)(param_1 + 0x1dc) = 2;
            if (*(int *)(param_1 + 0x1d8) == 0) {
              iVar5 = *(int *)(param_1 + 0x44);
              goto LAB_0002d018;
            }
          }
          else {
            iVar5 = FUN_00011e38(DAT_00055384);
            if (((iVar5 == 8) || (iVar5 = FUN_00011e38(DAT_00055384), iVar5 == 10)) ||
               (iVar5 = FUN_00011e38(DAT_00055384), iVar5 == 7)) {
LAB_0002cee8:
              *(undefined4 *)(param_1 + 0x1fc) = 1;
            }
            else if (*(int *)(param_1 + 0x1dc) == 1) {
              *(undefined4 *)(param_1 + 0x1dc) = 0;
              FUN_000338ac(0x6e,0);
              if (*(int *)(param_1 + 0x1d8) != 0) {
                FUN_000268d0(param_1,6,1000);
                LVar4 = *(LPARAM *)(param_1 + 0x1d8);
                goto LAB_0002d02c;
              }
            }
          }
          goto LAB_0002ceec;
        }
      }
      else {
        if ((char)param_2[1] == '\x1f') {
          if (*(int *)(param_1 + 0x1fc) == 1) goto LAB_0002cf68;
          if ((((DAT_00057354 & 2) == 0) ||
              ((*(int *)(param_1 + 0x50) != 0 && (*(int *)(param_1 + 0x50) != 5)))) ||
             (iVar5 = *(int *)(param_1 + 0x48), iVar5 == 4)) {
            iVar5 = FUN_00011e38(DAT_00055384);
            if (((iVar5 == 8) || (iVar5 = FUN_00011e38(DAT_00055384), iVar5 == 10)) ||
               (iVar5 = FUN_00011e38(DAT_00055384), iVar5 == 7)) goto LAB_0002cee8;
          }
          else {
            if (iVar5 == 5) {
              FUN_00026960(param_1,5);
            }
            else if ((iVar5 != 6) && (iVar5 != 0)) {
              NKDbgPrintfW(L"%S : Other Timer is already started. Check it out.!!!!!!!!(OLD:%d)\r\n"
                           ,"CRadio::OnCommand");
            }
            iVar5 = *(int *)(param_1 + 0x44);
            *(undefined4 *)(param_1 + 0x1dc) = 1;
LAB_0002d018:
            FUN_0002e27c(DAT_00057348,(uint)*(ushort *)(param_1 + 0x1c8),
                         (undefined4 *)(iVar5 + 0x617));
            LVar4 = *(int *)(param_1 + 0x1dc) + 2;
LAB_0002d02c:
            FUN_000338ac(0x6d,LVar4);
          }
          goto LAB_0002ceec;
        }
        if ((*(int *)(param_1 + 0x50) == 5) && (*(int *)(param_1 + 0x1dc) != 0)) {
          if (*(int *)(param_1 + 0x1d8) == 0) goto LAB_0002cdf8;
          *(undefined4 *)(param_1 + 0x1dc) = 0;
          FUN_000268d0(param_1,6,1000);
          FUN_000338ac(0x6e,0);
          LVar4 = *(LPARAM *)(param_1 + 0x1d8);
          iVar5 = 0x6d;
        }
        else {
          if (*(int *)(param_1 + 0x1dc) == 0) goto LAB_0002cf68;
          *(undefined4 *)(param_1 + 0x1dc) = 0;
LAB_0002cdf8:
          iVar5 = 0x6e;
          LVar4 = 0;
        }
        FUN_000338ac(iVar5,LVar4);
      }
LAB_0002cf68:
      *(undefined4 *)(param_1 + 0x1fc) = 0;
    }
LAB_0002ceec:
    iVar5 = *(int *)(param_1 + 0x44);
    *(uint *)(param_1 + 500) = (uint)(byte)param_2[1];
    if ((*(char *)(iVar5 + 0x615) != (char)param_2[1]) && ((DAT_00057354 & 2) == 2)) {
      iVar7 = *(int *)(param_1 + 0x4c);
      goto joined_r0x0002cf1c;
    }
LAB_0002cf44:
    hWnd = *(HWND *)(param_1 + 0x5c);
    if (hWnd != (HWND)0x0) {
      uVar6 = *(uint *)(param_1 + 500);
      wParam = 6;
LAB_0002d554:
      PostMessageW(hWnd,0x403,wParam,uVar6);
    }
    break;
  case 0x55:
    NKDbgPrintfW(L"%S : PSN(%c%c%c%c%c%c%c%c).\r\n","CRadio::OnCommand",(char)param_2[1],
                 *(undefined1 *)((int)param_2 + 5),*(undefined1 *)((int)param_2 + 6),
                 *(undefined1 *)((int)param_2 + 7),(char)param_2[2],
                 *(undefined1 *)((int)param_2 + 9),*(undefined1 *)((int)param_2 + 10),
                 *(undefined1 *)((int)param_2 + 0xb));
    if (*(int *)(param_1 + 0x280) != 0) {
      return;
    }
    if ((DAT_00057354 & 2) != 2) {
      return;
    }
    if ((*(int *)(param_1 + 0x50) != 0) && (*(int *)(param_1 + 0x50) != 5)) {
      return;
    }
    iVar5 = *(int *)(param_1 + 0x44);
    *(uint *)(iVar5 + 0x617) = param_2[1];
    *(uint *)(iVar5 + 0x61b) = param_2[2];
    *(undefined1 *)(*(int *)(param_1 + 0x44) + 0x61f) = 0;
    iVar5 = FUN_0002e488(DAT_00057348,(uint)*(ushort *)(param_1 + 0x1c8),
                         (undefined4 *)(*(int *)(param_1 + 0x44) + 0x617));
    if (iVar5 != 0) {
      iVar5 = 0;
      uVar6 = 0;
      do {
        if ((*(int *)((int)&DAT_0005737c + uVar6) != 0) &&
           ((uint)*(ushort *)((int)&DAT_00057378 + uVar6) == (uint)*(ushort *)(param_1 + 0x1c8))) {
          FUN_0002e27c(DAT_00057348,(uint)*(ushort *)(param_1 + 0x1c8),
                       (undefined4 *)(&DAT_00057380 + uVar6));
          FUN_0002f6e8(0,iVar5);
        }
        uVar6 = uVar6 + 0x18;
        iVar5 = iVar5 + 1;
      } while (uVar6 < 0x120);
      iVar5 = 0;
      uVar6 = 0;
      do {
        if ((*(int *)((int)&DAT_0005749c + uVar6) != 0) &&
           ((uint)*(ushort *)((int)&DAT_00057498 + uVar6) == (uint)*(ushort *)(param_1 + 0x1c8))) {
          FUN_0002e27c(DAT_00057348,(uint)*(ushort *)(param_1 + 0x1c8),
                       (undefined4 *)(&DAT_000574a0 + uVar6));
          FUN_0002f8d4(0,iVar5);
        }
        uVar6 = uVar6 + 0x18;
        iVar5 = iVar5 + 1;
      } while (uVar6 < 0x360);
    }
    FUN_000338ac(0x6a,0);
LAB_0002cd5c:
    iVar5 = 0x67;
LAB_0002c8ac:
    LVar4 = 0;
    goto LAB_0002c8b0;
  case 0x56:
    if ((DAT_00057354 & 2) != 2) {
      return;
    }
    if (*(int *)(param_1 + 0x280) != 0) {
      return;
    }
    if (*(int *)(param_1 + 0x50) != 0) {
      return;
    }
    _Src = (char *)(((byte)param_2[1] + 8) * 0x40 + param_1);
    if (*_Src == '\0') {
      return;
    }
    iVar5 = *(int *)(param_1 + 0x44);
    goto LAB_0002d1e8;
  case 0x57:
    if ((DAT_00057354 & 2) != 2) {
      return;
    }
    if (*(int *)(param_1 + 0x280) != 0) {
      return;
    }
    if (*(int *)(param_1 + 0x50) != 0) {
      return;
    }
    _Src = (char *)(((byte)param_2[1] + 8) * 0x40 + param_1);
    FUN_00016068(DAT_000553cc,4,(byte)param_2[1] + 0x15,_Src,0x40,100);
    iVar5 = *(int *)(param_1 + 0x44);
LAB_0002d1e8:
    memcpy((void *)(iVar5 + 0x623),_Src,0x40);
    *(undefined1 *)(*(int *)(param_1 + 0x44) + 0x663) = 0;
    if (*(char *)(*(int *)(param_1 + 0x44) + 0x623) != '\0') {
      FUN_00027c80(param_1);
      *(undefined1 *)(*(int *)(param_1 + 0x44) + 0x663) = 0;
    }
    iVar5 = 0x6c;
    goto LAB_0002c8ac;
  case 0x58:
    *(char *)(*(int *)(param_1 + 0x44) + 0x611) = (char)param_2[1];
    FUN_000338ac(0x6f,0);
    if ((char)param_2[1] != '\0') {
      return;
    }
    if ((*(int *)(param_1 + 0x4c) == 2) && (*(int *)(param_1 + 0x284) == 1)) {
      FUN_00028c9c(param_1);
      return;
    }
    if (*(int *)(param_1 + 0x4c) != 1) {
      return;
    }
    FUN_00026eac(param_1);
    *(undefined2 *)(param_1 + 0x1c8) = 0;
    FUN_00027654(param_1,0,0);
    goto LAB_0002d508;
  case 0x59:
    if ((DAT_00057354 & 2) == 2) {
      *(undefined4 *)(param_1 + 0x1e4) = 0;
      FUN_00029f90(param_1,DAT_00057354 >> 1 & 1,*(int *)(param_1 + 0x1c0));
      *(undefined2 *)(param_1 + 0x1c8) = 0;
      FUN_00026f0c(param_1);
      FUN_00027124(param_1);
      FUN_00026db8(param_1);
      FUN_00026eac(param_1);
    }
    break;
  case 0x5a:
    if (*(int *)(param_1 + 0x5c) == 0) {
      return;
    }
    _Size = (size_t)*(byte *)((int)param_2 + 3);
    if (8 < _Size) {
      _Size = 8;
    }
    memcpy((void *)(param_1 + 0x3a),param_2 + 1,_Size);
    wParam = 0xb;
LAB_0002d54c:
    hWnd = *(HWND *)(param_1 + 0x5c);
LAB_0002d550:
    uVar6 = 0;
    goto LAB_0002d554;
  case 0x5b:
    NKDbgPrintfW(L"========================================================================\r\n");
    NKDbgPrintfW(L"[Seek] Fail Freq %d\r\n",param_2[1]);
    NKDbgPrintfW(L"========================================================================\r\n");
    if (*(int *)(param_1 + 0x4c) != 1) {
      return;
    }
    iVar5 = *(int *)(param_1 + 0x50);
    if ((iVar5 == 3) || (iVar5 == 2)) {
      FUN_00029eec(param_1,param_2[1]);
      return;
    }
    if (iVar5 != 6) {
      NKDbgPrintfW(L"%S : Sub-Mode(%d) is not SUBMODE_SEEK/SUBMODE_OFF_SEEK. Check it out. m_nCurFreq %d!!!\r\n"
                   ,"CRadio::OnCommand",iVar5,*(undefined4 *)(param_1 + 0x1c0));
      if (param_2[1] == *(uint *)(param_1 + 0x1c0)) {
        return;
      }
      *(uint *)(param_1 + 0x1c0) = param_2[1];
LAB_0002c560:
      FUN_00027654(param_1,1,0);
      return;
    }
LAB_0002c524:
    FUN_0002af20(param_1,param_2[1]);
  }
  return;
}



/* 0002d6b0 FUN_0002d6b0 */

/* Boundary evidence: original MIPS .pdata 0002d6b0..0002d787. Semantic name remains unreviewed. */

void FUN_0002d6b0(int param_1)

{
  int iVar1;
  uint uVar2;
  
  NKDbgPrintfW(L"%S\r\n","CRadio::ModeChange");
  iVar1 = FUN_0001c8ac(DAT_00055498);
  if (iVar1 != 0) {
    uVar2 = FUN_00011e38(DAT_00055384);
    if (uVar2 == 0) {
      FUN_0002bca4(param_1);
      return;
    }
    if (uVar2 != 0) {
      if (uVar2 < 6) {
        if (((DAT_00057354 & 8) == 8) || ((DAT_00057354 & 0x20) != 0)) {
          FUN_0002bdb0(param_1);
          return;
        }
      }
      else {
        if (uVar2 == 6) {
          return;
        }
        if (uVar2 == 9) {
          return;
        }
      }
    }
  }
  FUN_0002bb7c(param_1);
  return;
}



/* 0002d788 FUN_0002d788 */

/* Boundary evidence: original MIPS .pdata 0002d788..0002d7df. Semantic name remains unreviewed. */

void FUN_0002d788(int param_1)

{
  if (*(int *)(param_1 + 0x4c) == 0) {
    FUN_0002d6b0(param_1);
  }
  else if (*(int *)(param_1 + 0x4c) == 1) {
    FUN_00028dec();
    FUN_00026db8(param_1);
  }
  return;
}



/* 0002d7e0 FUN_0002d7e0 */

undefined4 * FUN_0002d7e0(undefined4 *param_1,undefined4 param_2,undefined4 param_3)

{
  *param_1 = &PTR_FUN_0004e948;
  param_1[1] = param_2;
  param_1[2] = param_3;
  return param_1;
}



/* 0002d7fc FUN_0002d7fc */

bool FUN_0002d7fc(int param_1,int param_2)

{
  return *(int *)(param_1 + 8) == param_2;
}



/* 0002d814 FUN_0002d814 */

/* Boundary evidence: original MIPS .pdata 0002d814..0002d83b. Semantic name remains unreviewed. */

void FUN_0002d814(int param_1,UINT param_2)

{
  SetTimer(*(HWND *)(param_1 + 4),*(UINT_PTR *)(param_1 + 8),param_2,(TIMERPROC)0x0);
  return;
}



/* 0002d83c FUN_0002d83c */

/* Boundary evidence: original MIPS .pdata 0002d83c..0002d85b. Semantic name remains unreviewed. */

void FUN_0002d83c(int param_1)

{
  KillTimer(*(HWND *)(param_1 + 4),*(UINT_PTR *)(param_1 + 8));
  return;
}



/* 0002d85c FUN_0002d85c */

/* Boundary evidence: original MIPS .pdata 0002d85c..0002d887. Semantic name remains unreviewed. */

void FUN_0002d85c(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_0004e948;
  KillTimer((HWND)param_1[1],param_1[2]);
  return;
}



/* 0002d888 FUN_0002d888 */

/* Boundary evidence: original MIPS .pdata 0002d888..0002d8e3. Semantic name remains unreviewed. */

undefined4 * FUN_0002d888(undefined4 *param_1,uint param_2)

{
  *param_1 = &PTR_FUN_0004e948;
  KillTimer((HWND)param_1[1],param_1[2]);
  if ((param_2 & 1) != 0) {
    __3_YAXPAX_Z(param_1);
  }
  return param_1;
}



/* 0002d8f0 FUN_0002d8f0 */

/* Boundary evidence: original MIPS .pdata 0002d8f0..0002d957. Semantic name remains unreviewed. */

undefined * FUN_0002d8f0(undefined4 *param_1,int param_2)

{
  undefined4 uVar1;
  
  uVar1 = (**(code **)*param_1)();
  _snwprintf((wchar_t *)&DAT_00057134,99,L"%s%s\\",uVar1,(&PTR_DAT_00054c8c)[param_2]);
  return &DAT_00057134;
}



/* 0002d958 FUN_0002d958 */

/* Boundary evidence: original MIPS .pdata 0002d958..0002d9bf. Semantic name remains unreviewed. */

LPWSTR FUN_0002d958(int param_1,int param_2)

{
  undefined *puVar1;
  
  if (param_2 < *(int *)(param_1 + 0x630)) {
    puVar1 = (&PTR_u_mgrmcm_volume_bg_bmp_00054be8)[param_2];
  }
  else {
    puVar1 = &DAT_00045f80;
  }
  wsprintfW((LPWSTR)(param_1 + 0x414),L"%s%s",param_1 + 0x20c,puVar1);
  return (LPWSTR)(param_1 + 0x414);
}



/* 0002d9c0 FUN_0002d9c0 */

void FUN_0002d9c0(undefined4 *param_1)

{
  *param_1 = &PTR_LAB_0004e97c;
  return;
}



/* 0002d9d0 FUN_0002d9d0 */

/* Boundary evidence: original MIPS .pdata 0002d9d0..0002da4b. Semantic name remains unreviewed. */

void FUN_0002d9d0(int param_1)

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



/* 0002da4c FUN_0002da4c */

undefined4 FUN_0002da4c(int param_1,int param_2)

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



/* 0002da7c FUN_0002da7c */

/* Boundary evidence: original MIPS .pdata 0002da7c..0002db7f. Semantic name remains unreviewed. */

undefined4
FUN_0002da7c(int param_1,int param_2,LPCWSTR param_3,LONG param_4,undefined4 param_5,BYTE param_6,
            BYTE param_7)

{
  undefined4 uVar1;
  HFONT pHVar2;
  int iVar3;
  LOGFONTW local_78;
  uint local_1c;
  
  local_1c = DAT_00055374;
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
    FUN_00043604(local_1c);
    uVar1 = 1;
  }
  else {
    FUN_00043604(DAT_00055374);
    uVar1 = 0;
  }
  return uVar1;
}



/* 0002db80 FUN_0002db80 */

/* Boundary evidence: original MIPS .pdata 0002db80..0002dbcf. Semantic name remains unreviewed. */

int FUN_0002db80(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = SHLoadDIBitmap(param_2);
  if (iVar1 == 0) {
    NKDbgPrintfW(L"\r\n~~~~~~~~ (%s) file not found!!!!\r\n",param_2);
  }
  return iVar1;
}



/* 0002dbd0 FUN_0002dbd0 */

/* Boundary evidence: original MIPS .pdata 0002dbd0..0002dc87. Semantic name remains unreviewed. */

void FUN_0002dbd0(int param_1)

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
        wcsncpy((wchar_t *)(param_1 + 0x20c),lpFilename,0x104);
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



/* 0002dc88 FUN_0002dc88 */

/* Boundary evidence: original MIPS .pdata 0002dc88..0002dcdb. Semantic name remains unreviewed. */

void FUN_0002dc88(int param_1,short *param_2)

{
  undefined *puVar1;
  
  if (param_2 != (short *)0x0) {
    if (*param_2 == 0x5c) {
      puVar1 = &DAT_00045f80;
    }
    else {
      puVar1 = (undefined *)(param_1 + 4);
    }
    _snwprintf((wchar_t *)(param_1 + 0x20c),0x103,L"%s%s",puVar1,param_2);
  }
  return;
}



/* 0002dcdc FUN_0002dcdc */

/* Boundary evidence: original MIPS .pdata 0002dcdc..0002dd7b. Semantic name remains unreviewed. */

void FUN_0002dcdc(undefined4 *param_1)

{
  *param_1 = &PTR_LAB_0004e9d8;
  if (param_1[0x18b] != 0) {
    FUN_0002d9d0((int)param_1);
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
  *param_1 = &PTR_LAB_0004e97c;
  return;
}



/* 0002dd7c Unwind@0002dd7c */

/* Boundary evidence: original MIPS .pdata 0002dd7c..0002ddab. Semantic name remains unreviewed. */

void Unwind_0002dd7c(void)

{
  undefined4 *in_v0;
  
  FUN_0002d9c0((undefined4 *)*in_v0);
  return;
}



/* 0002ddac FUN_0002ddac */

/* Boundary evidence: original MIPS .pdata 0002ddac..0002ddf7. Semantic name remains unreviewed. */

undefined4 * FUN_0002ddac(undefined4 *param_1)

{
  *param_1 = &PTR_LAB_0004e97c;
  param_1[0x18b] = 0;
  param_1[0x188] = 0;
  param_1[0x189] = 0;
  param_1[0x18c] = 0;
  param_1[0x18a] = 0;
  FUN_0002dbd0((int)param_1);
  return param_1;
}



/* 0002ddf8 FUN_0002ddf8 */

/* Boundary evidence: original MIPS .pdata 0002ddf8..0002de3b. Semantic name remains unreviewed. */

undefined4 * FUN_0002ddf8(undefined4 *param_1,uint param_2)

{
  *param_1 = &PTR_LAB_0004e97c;
  if ((param_2 & 1) != 0) {
    __3_YAXPAX_Z(param_1);
  }
  return param_1;
}



/* 0002de3c FUN_0002de3c */

/* Boundary evidence: original MIPS .pdata 0002de3c..0002debf. Semantic name remains unreviewed. */

void FUN_0002de3c(int param_1,short *param_2)

{
  HGDIOBJ ho;
  int iVar1;
  int iVar2;
  
  FUN_0002dc88(param_1,param_2);
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



/* 0002dec0 FUN_0002dec0 */

/* Boundary evidence: original MIPS .pdata 0002dec0..0002df23. Semantic name remains unreviewed. */

void FUN_0002dec0(int *param_1,int param_2)

{
  short *psVar1;
  
  if ((param_1[0x187] != param_2) &&
     (psVar1 = (short *)(**(code **)(*param_1 + 4))(param_1,param_2), psVar1 != (short *)0x0)) {
    param_1[0x187] = param_2;
    FUN_0002de3c((int)param_1,psVar1);
  }
  return;
}



/* 0002df24 FUN_0002df24 */

/* Boundary evidence: original MIPS .pdata 0002df24..0002e01f. Semantic name remains unreviewed. */

int FUN_0002df24(int *param_1,int param_2)

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
          iVar3 = FUN_0002db80(param_1,_Str);
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



/* 0002e020 FUN_0002e020 */

/* Boundary evidence: original MIPS .pdata 0002e020..0002e12f. Semantic name remains unreviewed. */

undefined4 * FUN_0002e020(undefined4 *param_1)

{
  void *_Dst;
  int iVar1;
  undefined4 uVar2;
  wchar_t local_220;
  undefined1 auStack_21e [518];
  uint local_18;
  
  local_18 = DAT_00055374;
  FUN_0002ddac(param_1);
  *param_1 = &PTR_LAB_0004e9d8;
  local_220 = L'\0';
  memset(auStack_21e,0,0x206);
  param_1[0x187] = 0;
  _snwprintf(&local_220,99,L"%s%s\\",L"Img\\",PTR_DAT_00054c8c);
  FUN_0002dc88((int)param_1,&local_220);
  _Dst = (void *)__2_YAPAXI_Z(0xa4);
  param_1[0x18b] = _Dst;
  if (_Dst != (void *)0x0) {
    memset(_Dst,0,0xa4);
    param_1[0x18c] = 0x29;
  }
  iVar1 = __2_YAPAXI_Z(0x18);
  param_1[0x188] = iVar1;
  if (iVar1 != 0) {
    uVar2 = __2_YAPAXI_Z(0x18);
    param_1[0x189] = uVar2;
    memset((void *)param_1[0x188],0,0x18);
    param_1[0x18a] = 6;
  }
  FUN_00043604(local_18);
  return param_1;
}



/* 0002e130 Unwind@0002e130 */

/* Boundary evidence: original MIPS .pdata 0002e130..0002e15f. Semantic name remains unreviewed. */

void Unwind_0002e130(void)

{
  int in_v0;
  
  FUN_0002d9c0(*(undefined4 **)(in_v0 + -0x228));
  return;
}



/* 0002e160 FUN_0002e160 */

/* Boundary evidence: original MIPS .pdata 0002e160..0002e1ab. Semantic name remains unreviewed. */

undefined4 * FUN_0002e160(undefined4 *param_1,uint param_2)

{
  FUN_0002dcdc(param_1);
  if ((param_2 & 1) != 0) {
    __3_YAXPAX_Z(param_1);
  }
  return param_1;
}



/* 0002e1ac FUN_0002e1ac */

/* Boundary evidence: original MIPS .pdata 0002e1ac..0002e1cf. Semantic name remains unreviewed. */

void FUN_0002e1ac(int param_1)

{
  memset(*(void **)(param_1 + 4),0,0x1600);
  return;
}



/* 0002e1d0 FUN_0002e1d0 */

/* Boundary evidence: original MIPS .pdata 0002e1d0..0002e27b. Semantic name remains unreviewed. */

void FUN_0002e1d0(int param_1,uint param_2)

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



/* 0002e27c FUN_0002e27c */

/* Boundary evidence: original MIPS .pdata 0002e27c..0002e2ff. Semantic name remains unreviewed. */

void FUN_0002e27c(int param_1,uint param_2,undefined4 *param_3)

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
      FUN_0002e1d0(param_1,uVar3);
      return;
    }
    uVar3 = uVar3 + 1;
    puVar1 = puVar1 + 0x16;
  } while (uVar3 < 0x80);
  return;
}



/* 0002e300 FUN_0002e300 */

int FUN_0002e300(int param_1,uint param_2)

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



/* 0002e36c FUN_0002e36c */

int FUN_0002e36c(int param_1)

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



/* 0002e3b0 FUN_0002e3b0 */

uint FUN_0002e3b0(int param_1,uint param_2)

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



/* 0002e3e8 FUN_0002e3e8 */

/* Boundary evidence: original MIPS .pdata 0002e3e8..0002e453. Semantic name remains unreviewed. */

undefined4 FUN_0002e3e8(int param_1,uint param_2)

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
      if (param_2 == *puVar3) goto LAB_0002e434;
      uVar2 = uVar2 + 1;
      puVar3 = puVar3 + 0x16;
    } while (uVar2 < 0x80);
    uVar2 = 0xffffffff;
LAB_0002e434:
    *(uint *)(param_1 + 0x88) = uVar2;
    FUN_0002e1d0(param_1,uVar2);
    uVar1 = *(undefined4 *)(param_1 + 0x88);
  }
  return uVar1;
}



/* 0002e454 FUN_0002e454 */

int FUN_0002e454(int param_1)

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



/* 0002e488 FUN_0002e488 */

/* Boundary evidence: original MIPS .pdata 0002e488..0002e53b. Semantic name remains unreviewed. */

undefined4 FUN_0002e488(int param_1,uint param_2,undefined4 *param_3)

{
  int iVar1;
  uint uVar2;
  ushort *puVar3;
  undefined4 *_Buf1;
  
  uVar2 = 0;
  puVar3 = (ushort *)(*(int *)(param_1 + 4) + 8);
  do {
    if (param_2 == *puVar3) goto LAB_0002e4cc;
    uVar2 = uVar2 + 1;
    puVar3 = puVar3 + 0x16;
  } while (uVar2 < 0x80);
  uVar2 = 0xffffffff;
LAB_0002e4cc:
  if (-1 < (int)uVar2) {
    _Buf1 = (undefined4 *)(uVar2 * 0x2c + *(int *)(param_1 + 4));
    iVar1 = memcmp(_Buf1,param_3,8);
    if (iVar1 != 0) {
      *_Buf1 = *param_3;
      _Buf1[1] = param_3[1];
      return 1;
    }
  }
  return 0;
}



/* 0002e53c FUN_0002e53c */

/* Boundary evidence: original MIPS .pdata 0002e53c..0002e693. Semantic name remains unreviewed. */

void FUN_0002e53c(undefined4 param_1,uint param_2,undefined4 *param_3)

{
  HANDLE hFile;
  DWORD local_30 [2];
  ushort local_28;
  undefined4 local_26;
  undefined4 local_22;
  uint local_1c;
  
  local_1c = DAT_00055374;
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
  FUN_00043604(local_1c);
  return;
}



/* 0002e694 FUN_0002e694 */

/* Boundary evidence: original MIPS .pdata 0002e694..0002e89f. Semantic name remains unreviewed. */

void FUN_0002e694(undefined1 *param_1)

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



/* 0002e8a0 FUN_0002e8a0 */

/* Boundary evidence: original MIPS .pdata 0002e8a0..0002ead7. Semantic name remains unreviewed. */

void FUN_0002e8a0(byte *param_1)

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
LAB_0002e964:
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
      if (hFile == (HANDLE)0xffffffff) goto LAB_0002e964;
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



/* 0002ead8 FUN_0002ead8 */

/* Boundary evidence: original MIPS .pdata 0002ead8..0002ebaf. Semantic name remains unreviewed. */

uint FUN_0002ead8(int param_1,uint param_2,uint param_3)

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
  FUN_0002e53c(param_1,param_2,_Dst);
  return uVar2;
}



/* 0002ebb0 FUN_0002ebb0 */

/* Boundary evidence: original MIPS .pdata 0002ebb0..0002ec2f. Semantic name remains unreviewed. */

undefined4 FUN_0002ebb0(int param_1,uint param_2,uint param_3)

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
      if (param_2 == *puVar3) goto LAB_0002ebfc;
      uVar2 = uVar2 + 1;
      puVar3 = puVar3 + 0x16;
    } while (uVar2 < 0x80);
    uVar2 = 0xffffffff;
LAB_0002ebfc:
    *(uint *)(param_1 + 0x88) = uVar2;
    if (uVar2 == 0xffffffff) {
      uVar2 = FUN_0002ead8(param_1,param_2,param_3);
      *(uint *)(param_1 + 0x88) = uVar2;
    }
    FUN_0002e1d0(param_1,*(uint *)(param_1 + 0x88));
    uVar1 = *(undefined4 *)(param_1 + 0x88);
  }
  return uVar1;
}



/* 0002ec30 FUN_0002ec30 */

/* Boundary evidence: original MIPS .pdata 0002ec30..0002ed03. Semantic name remains unreviewed. */

void FUN_0002ec30(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

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
  
  local_14 = DAT_00055374;
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
      if (uVar2 == *puVar3) goto LAB_0002ecb4;
      uVar1 = uVar1 + 1;
      puVar3 = puVar3 + 0x16;
    } while (uVar1 < 0x80);
    uVar1 = 0xffffffff;
LAB_0002ecb4:
    if ((int)uVar1 < 0) {
      uVar1 = FUN_0002ead8(param_1,uVar2,0);
    }
    memcpy((void *)(uVar1 * 0x2c + iVar4 + 8),local_38,0x24);
  }
  FUN_00043604(local_14);
  return;
}



/* 0002ed04 FUN_0002ed04 */

/* Boundary evidence: original MIPS .pdata 0002ed04..0002ee23. Semantic name remains unreviewed. */

void FUN_0002ed04(int param_1,uint param_2,uint param_3)

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
    if (param_2 == *puVar4) goto LAB_0002ed3c;
    uVar2 = uVar2 + 1;
    puVar4 = puVar4 + 0x16;
  } while (uVar2 < 0x80);
  uVar2 = 0xffffffff;
LAB_0002ed3c:
  if ((int)uVar2 < 0) {
    FUN_0002ead8(param_1,param_2,param_3);
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



/* 0002ee24 FUN_0002ee24 */

/* Boundary evidence: original MIPS .pdata 0002ee24..0002ee5b. Semantic name remains unreviewed. */

undefined1 * FUN_0002ee24(undefined1 *param_1)

{
  void *pvVar1;
  
  pvVar1 = malloc(0x1600);
  *(void **)(param_1 + 4) = pvVar1;
  FUN_0002e694(param_1);
  return param_1;
}



/* 0002ee5c FUN_0002ee5c */

/* Boundary evidence: original MIPS .pdata 0002ee5c..0002eea7. Semantic name remains unreviewed. */

undefined4 FUN_0002ee5c(LPCWSTR param_1)

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



/* 0002eea8 FUN_0002eea8 */

void FUN_0002eea8(void)

{
  undefined1 *puVar1;
  undefined4 *puVar2;
  uint uVar3;
  undefined2 *puVar4;
  
  if (DAT_00054c94 == '\0') {
    uVar3 = DAT_00057354 & 0xffffffd7 | 0x16;
  }
  else if (DAT_00054c94 == '\x04') {
    uVar3 = DAT_00057354 & 0xffffffc3 | 2;
  }
  else {
    uVar3 = DAT_00057354 & 0xffffffc7 | 6;
  }
  DAT_00057354 = uVar3 & 0xf010187f | 0x10100040;
  DAT_00057358 = 0x80;
  DAT_00057359 = 0x80;
  DAT_0005735a = 0x80;
  DAT_00057364 = DAT_00057364 & 0xcf3cf3cf | 0xf3cf3cf;
  DAT_00057368 = DAT_00057368 & 0xfffffcc0 | 0xc0;
  puVar1 = &DAT_0005735c;
  do {
    *puVar1 = 1;
    puVar1 = puVar1 + 1;
  } while (puVar1 != (undefined1 *)0x5735f);
  DAT_00057360 = DAT_00057360 | 1;
  DAT_0005736c = 0xc;
  uVar3 = 0;
  do {
    puVar2 = (undefined4 *)((int)&DAT_0005737c + uVar3);
    puVar4 = (undefined2 *)((int)&DAT_00057378 + uVar3);
    puVar1 = &DAT_00057380 + uVar3;
    uVar3 = uVar3 + 0x18;
    *puVar2 = 0;
    *puVar4 = 0;
    *puVar1 = 0;
  } while (uVar3 < 0x120);
  uVar3 = 0;
  do {
    puVar2 = (undefined4 *)((int)&DAT_0005749c + uVar3);
    puVar4 = (undefined2 *)((int)&DAT_00057498 + uVar3);
    puVar1 = &DAT_000574a0 + uVar3;
    uVar3 = uVar3 + 0x18;
    *puVar2 = 0;
    *puVar4 = 0;
    *puVar1 = 0;
  } while (uVar3 < 0x360);
  DAT_000577f8 = 0xc;
  uVar3 = 0;
  do {
    *(undefined4 *)((int)&DAT_00057808 + uVar3) = 0;
    *(undefined2 *)((int)&DAT_00057804 + uVar3) = 0;
    puVar1 = &DAT_0005780c + uVar3;
    uVar3 = uVar3 + 0x18;
    *puVar1 = 0;
  } while (uVar3 < 0x120);
  uVar3 = 0;
  do {
    *(undefined4 *)((int)&DAT_00057928 + uVar3) = 0;
    *(undefined2 *)((int)&DAT_00057924 + uVar3) = 0;
    puVar1 = &DAT_0005792c + uVar3;
    uVar3 = uVar3 + 0x18;
    *puVar1 = 0;
  } while (uVar3 < 0x360);
  return;
}



/* 0002f084 FUN_0002f084 */

/* Boundary evidence: original MIPS .pdata 0002f084..0002f113. Semantic name remains unreviewed. */

void FUN_0002f084(void)

{
  memset(&DAT_0005734c,0,0x940);
  DAT_00057350 = 0x13;
  DAT_00057354 = DAT_00057354 & 0xffffe7ff | 1;
  DAT_0005736c = 0xc;
  DAT_00057370 = 0;
  DAT_00057374 = 0x15630;
  DAT_000577f8 = 0xc;
  DAT_000577fc = 0;
  DAT_00057800 = 900;
  DAT_00057c84 = 1;
  FUN_0002eea8();
  return;
}



/* 0002f114 FUN_0002f114 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Boundary evidence: original MIPS .pdata 0002f114..0002f24f. Semantic name remains unreviewed. */

void FUN_0002f114(void)

{
  uint uVar1;
  byte *pbVar2;
  int iVar3;
  uint uVar4;
  byte bVar5;
  
  _DAT_0005734c = (_DAT_0005734c ^ DAT_00058a1c) & 1 ^ _DAT_0005734c;
  DAT_00057350 = DAT_00058a20;
  DAT_00057354 = (DAT_00057354 ^ DAT_00058a24) & 0x1fffffff ^ DAT_00057354;
  DAT_00057358 = (undefined1)DAT_00058a28;
  DAT_00057359 = (undefined1)(DAT_00058a28 >> 8);
  iVar3 = 0;
  DAT_0005735a = (undefined1)(DAT_00058a28 >> 0x10);
  uVar4 = DAT_00058a28;
  bVar5 = DAT_00058a28._3_1_;
  do {
    uVar1 = DAT_00058a28;
    if (2 < (bVar5 & 0xf)) {
      uVar4 = uVar4 & 0xf1ffffff | 0x1000000;
      DAT_00058a28._3_1_ = (byte)(uVar4 >> 0x18);
      uVar1 = uVar4;
      bVar5 = DAT_00058a28._3_1_;
    }
    DAT_00058a28 = uVar1;
    pbVar2 = &DAT_0005735c + iVar3;
    iVar3 = iVar3 + 1;
    *pbVar2 = bVar5 & 0xf;
  } while (iVar3 < 3);
  DAT_00057360 = (uVar4 >> 0x1c ^ DAT_00057360) & 1 ^ DAT_00057360;
  DAT_00057364 = DAT_00058a2c;
  DAT_00057368 = DAT_00058a30;
  memcpy(&DAT_0005736c,&DAT_00058a34,0x48c);
  memcpy(&DAT_000577f8,&DAT_00058ec0,0x48c);
  DAT_00057c84 = DAT_0005934c;
  DAT_00057c85 = DAT_0005934d;
  DAT_00057c86 = DAT_0005934e;
  return;
}



/* 0002f250 FUN_0002f250 */

/* Boundary evidence: original MIPS .pdata 0002f250..0002f483. Semantic name remains unreviewed. */

void FUN_0002f250(void)

{
  DWORD DVar1;
  HANDLE pvVar2;
  BOOL BVar3;
  undefined1 local_30 [4];
  DWORD local_2c;
  
  DVar1 = GetFileAttributesW(L"\\Storage Card2\\radcountry");
  if (DVar1 != 0xffffffff) {
    CopyFileW(L"\\Storage Card2\\radcountry",L"\\Storage Card\\System\\radcountry",0);
    DeleteFileW(L"\\Storage Card2\\radcountry");
  }
  DVar1 = GetFileAttributesW(L"\\Storage Card2\\amtype");
  if (DVar1 != 0xffffffff) {
    CopyFileW(L"\\Storage Card2\\amtype",L"\\Storage Card\\System\\amtype",0);
    DeleteFileW(L"\\Storage Card2\\amtype");
  }
  pvVar2 = CreateFileW(L"\\Storage Card\\System\\radcountry",0x80000000,0,(LPSECURITY_ATTRIBUTES)0x0
                       ,3,0x80,(HANDLE)0x0);
  if (pvVar2 == (HANDLE)0xffffffff) {
    DAT_00054c94 = 0;
  }
  else {
    BVar3 = ReadFile(pvVar2,local_30,1,&local_2c,(LPOVERLAPPED)0x0);
    if ((BVar3 == 0) || (local_2c != 1)) {
      DAT_00054c94 = 0;
    }
    else {
      DAT_00054c94 = local_30[0];
    }
    CloseHandle(pvVar2);
  }
  pvVar2 = CreateFileW(L"\\Storage Card\\System\\amtype",0x80000000,0,(LPSECURITY_ATTRIBUTES)0x0,3,
                       0x80,(HANDLE)0x0);
  if (pvVar2 == (HANDLE)0xffffffff) {
    DAT_00054c95 = 3;
  }
  else {
    BVar3 = ReadFile(pvVar2,local_30,1,&local_2c,(LPOVERLAPPED)0x0);
    if ((BVar3 == 0) || (local_2c != 1)) {
      DAT_00054c95 = 3;
    }
    else {
      DAT_00054c95 = local_30[0];
    }
    CloseHandle(pvVar2);
  }
  return;
}



/* 0002f484 FUN_0002f484 */

/* Boundary evidence: original MIPS .pdata 0002f484..0002f6e7. Semantic name remains unreviewed. */

void FUN_0002f484(void)

{
  byte bVar1;
  HANDLE hFile;
  HANDLE hFile_00;
  BOOL BVar2;
  BOOL BVar3;
  byte *pbVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  byte *pbVar9;
  byte bVar10;
  DWORD local_30;
  DWORD local_2c;
  
  uVar7 = 0x93b;
  uVar6 = 0;
  pbVar9 = &DAT_0005734c;
  do {
    pbVar4 = &DAT_0005734c + uVar6;
    uVar5 = uVar6 & 3;
    uVar6 = uVar6 + 1;
    uVar7 = (uint)*pbVar4 * (uVar5 + 1) + uVar7;
  } while (uVar6 < 0x93b);
  iVar8 = 0x93c;
  bVar10 = (byte)uVar7;
  uVar6 = 0xffffffff;
  do {
    iVar8 = iVar8 + -1;
    uVar6 = *(uint *)(&DAT_00054ca8 + ((*pbVar9 ^ uVar6) & 0xff) * 4) ^ uVar6 >> 8;
    pbVar9 = pbVar9 + 1;
  } while (iVar8 != 0);
  uVar6 = ~uVar6;
  DAT_00057c87 = bVar10;
  if (((uint)DAT_00059358 != (uVar7 & 0xff)) ||
     (bVar1 = DAT_00059358, uVar7 = DAT_0005935c, DAT_0005935c != uVar6)) {
    hFile = CreateFileW(L"\\Storage Card2\\mgrmcm2.cfg",0x40000000,0,(LPSECURITY_ATTRIBUTES)0x0,2,
                        0x80,(HANDLE)0x0);
    hFile_00 = CreateFileW(L"\\Storage Card2\\mgrmcm2_backup.cfg",0x40000000,0,
                           (LPSECURITY_ATTRIBUTES)0x0,2,0x80,(HANDLE)0x0);
    if ((hFile == (HANDLE)0xffffffff) && (hFile_00 == (HANDLE)0xffffffff)) {
      NKDbgPrintfW(L"McmMgr : File write error.\r\n");
      bVar1 = DAT_00059358;
      uVar7 = DAT_0005935c;
    }
    else {
      DAT_00057c88 = uVar6;
      BVar2 = WriteFile(hFile,&DAT_0005734c,0x940,&local_30,(LPOVERLAPPED)0x0);
      BVar3 = WriteFile(hFile_00,&DAT_0005734c,0x940,&local_2c,(LPOVERLAPPED)0x0);
      if (((BVar2 == 0) || (local_30 != 0x940)) && ((BVar3 == 0 || (local_2c != 0x940)))) {
        NKDbgPrintfW(L"McmMgr : File write error.");
        if (hFile != (HANDLE)0xffffffff) {
          CloseHandle(hFile);
        }
        bVar1 = DAT_00059358;
        uVar7 = DAT_0005935c;
        if (hFile_00 != (HANDLE)0xffffffff) {
          CloseHandle(hFile_00);
          bVar1 = DAT_00059358;
          uVar7 = DAT_0005935c;
        }
      }
      else {
        if (hFile != (HANDLE)0xffffffff) {
          CloseHandle(hFile);
        }
        bVar1 = bVar10;
        uVar7 = uVar6;
        if (hFile_00 != (HANDLE)0xffffffff) {
          CloseHandle(hFile_00);
        }
      }
    }
  }
  DAT_0005935c = uVar7;
  DAT_00059358 = bVar1;
  return;
}



/* 0002f6e8 FUN_0002f6e8 */

/* Boundary evidence: original MIPS .pdata 0002f6e8..0002f8d3. Semantic name remains unreviewed. */

void FUN_0002f6e8(int param_1,int param_2)

{
  undefined4 uVar1;
  char *_Format;
  char *_DstBuf;
  undefined8 uVar2;
  
  _DstBuf = (char *)((param_1 * 0x30 + param_2) * 0x10 + DAT_00055618 + 0xc);
  if ((DAT_00057354 & 2) == 0) {
    if ((&DAT_0005737c)[param_2 * 6 + param_1 * 0x123] == 0) {
LAB_0002f8c0:
      *_DstBuf = '\0';
      return;
    }
    if (param_1 != 1) {
      uVar1 = __ultofp((&DAT_0005737c)[param_2 * 6 + param_1 * 0x123]);
      uVar2 = __fptodp(uVar1);
      __dpmul((int)uVar2,(int)((ulonglong)uVar2 >> 0x20),0xd2f1a9fc,0x3f50624d);
      sprintf_s(_DstBuf,0x10,"%6.2fMHz");
      return;
    }
    _Format = "%dkHz";
  }
  else {
    if ((&DAT_00057380)[param_1 * 0x48c + param_2 * 0x18] != '\0') {
      strncpy_s(_DstBuf,0x10,&DAT_00057380 + param_1 * 0x48c + param_2 * 0x18,0xf);
      return;
    }
    if ((&DAT_0005737c)[param_2 * 6 + param_1 * 0x123] == 0) goto LAB_0002f8c0;
    if (param_1 != 1) {
      uVar1 = __ultofp((&DAT_0005737c)[param_2 * 6 + param_1 * 0x123]);
      uVar2 = __fptodp(uVar1);
      __dpmul((int)uVar2,(int)((ulonglong)uVar2 >> 0x20),0xd2f1a9fc,0x3f50624d);
      sprintf_s(_DstBuf,0x10,"[%6.2fMHz]");
      return;
    }
    _Format = "[%dkHz]";
  }
  sprintf_s(_DstBuf,0x10,_Format,(&DAT_00057808)[param_2 * 6]);
  return;
}



/* 0002f8d4 FUN_0002f8d4 */

/* Boundary evidence: original MIPS .pdata 0002f8d4..0002fabf. Semantic name remains unreviewed. */

void FUN_0002f8d4(int param_1,int param_2)

{
  undefined4 uVar1;
  char *_Format;
  char *_DstBuf;
  undefined8 uVar2;
  
  _DstBuf = (char *)((param_1 * 0x30 + param_2) * 0x10 + DAT_00055618 + 0xcc);
  if ((DAT_00057354 & 2) == 0) {
    if ((&DAT_0005749c)[param_2 * 6 + param_1 * 0x123] == 0) {
LAB_0002faac:
      *_DstBuf = '\0';
      return;
    }
    if (param_1 != 1) {
      uVar1 = __ultofp((&DAT_0005749c)[param_2 * 6 + param_1 * 0x123]);
      uVar2 = __fptodp(uVar1);
      __dpmul((int)uVar2,(int)((ulonglong)uVar2 >> 0x20),0xd2f1a9fc,0x3f50624d);
      sprintf_s(_DstBuf,0x10,"%6.2fMHz");
      return;
    }
    _Format = "%dkHz";
  }
  else {
    if ((&DAT_000574a0)[param_1 * 0x48c + param_2 * 0x18] != '\0') {
      strncpy_s(_DstBuf,0x10,&DAT_000574a0 + param_1 * 0x48c + param_2 * 0x18,0xf);
      return;
    }
    if ((&DAT_0005749c)[param_2 * 6 + param_1 * 0x123] == 0) goto LAB_0002faac;
    if (param_1 != 1) {
      uVar1 = __ultofp((&DAT_0005749c)[param_2 * 6 + param_1 * 0x123]);
      uVar2 = __fptodp(uVar1);
      __dpmul((int)uVar2,(int)((ulonglong)uVar2 >> 0x20),0xd2f1a9fc,0x3f50624d);
      sprintf_s(_DstBuf,0x10,"[%6.2fMHz]");
      return;
    }
    _Format = "[%dkHz]";
  }
  sprintf_s(_DstBuf,0x10,_Format,(&DAT_00057928)[param_2 * 6]);
  return;
}



/* 0002fac0 FUN_0002fac0 */

byte FUN_0002fac0(int param_1,int param_2)

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



/* 0002faf0 FUN_0002faf0 */

/* Boundary evidence: original MIPS .pdata 0002faf0..0002fc27. Semantic name remains unreviewed. */

void FUN_0002faf0(void)

{
  HANDLE pvVar1;
  DWORD aDStack_30 [2];
  
  pvVar1 = CreateFileW(L"\\Storage Card\\System\\radcountry",0x40000000,0,(LPSECURITY_ATTRIBUTES)0x0
                       ,3,0x80,(HANDLE)0x0);
  if (pvVar1 != (HANDLE)0xffffffff) {
    WriteFile(pvVar1,&DAT_00054c94,1,aDStack_30,(LPOVERLAPPED)0x0);
    CloseHandle(pvVar1);
  }
  pvVar1 = CreateFileW(L"\\Storage Card\\System\\amtype",0x40000000,0,(LPSECURITY_ATTRIBUTES)0x0,3,
                       0x80,(HANDLE)0x0);
  if (pvVar1 != (HANDLE)0xffffffff) {
    WriteFile(pvVar1,&DAT_00054c95,1,aDStack_30,(LPOVERLAPPED)0x0);
    CloseHandle(pvVar1);
  }
  return;
}



/* 0002fc28 FUN_0002fc28 */

/* Boundary evidence: original MIPS .pdata 0002fc28..0002fdbf. Semantic name remains unreviewed. */

char FUN_0002fc28(char param_1)

{
  int iVar1;
  wchar_t *pwVar2;
  char cVar3;
  
  cVar3 = -1;
  memset(&DAT_00059364,0xff,4);
  memset(&DAT_00059360,0xff,4);
  iVar1 = FUN_00025d04();
  if (iVar1 != 0) {
    DAT_00059360 = param_1;
    DAT_00059363 = param_1;
    iVar1 = FUN_00025e68(&DAT_00059364,0xbfeee000,4);
    if (iVar1 != 0) {
      NKDbgPrintfW(L"** Storead CAR TYPE= %d, Changing CAR TYPE= %d\r\n",DAT_00059364,DAT_00059360);
    }
    if (DAT_00059364 == DAT_00059360) {
      NKDbgPrintfW(L"Car Maker is same !!! [%d] \r\n",DAT_00059364);
    }
    else {
      iVar1 = FUN_00025ebc(0xbfeee000,4);
      if (iVar1 == 0) {
        pwVar2 = L"ERROR! Fail to erase NOR flash..\n";
      }
      else {
        iVar1 = FUN_00025e14(0xbfeee000,&DAT_00059360,4);
        if (iVar1 == 0) {
          pwVar2 = L"Failed to write flash\r\n";
        }
        else {
          pwVar2 = L"Success to write flash\r\n";
        }
      }
      NKDbgPrintfW(pwVar2);
      iVar1 = FUN_00025e68(&DAT_00059364,0xbfeee000,4);
      if (iVar1 != 0) {
        NKDbgPrintfW(L"** Validation Car TYPE changed from %d to %d\r\n",DAT_00059360,DAT_00059364);
      }
    }
    cVar3 = DAT_00059364;
    FUN_00025dc4();
    NKDbgPrintfW(L"[INFO] %s errCode %d \r\n","SetCarType",cVar3);
  }
  return cVar3;
}



/* 0002fdc0 FUN_0002fdc0 */

/* Boundary evidence: original MIPS .pdata 0002fdc0..0002ff2b. Semantic name remains unreviewed. */

bool FUN_0002fdc0(void *param_1,size_t param_2)

{
  HANDLE hFile;
  DWORD DVar1;
  int iVar2;
  byte *pbVar3;
  DWORD aDStack_40 [2];
  byte local_38 [32];
  uint local_18;
  uint local_14;
  
  local_14 = DAT_00055374;
  memset(local_38,0,0x24);
  memcpy(local_38,param_1,param_2);
  iVar2 = 0x20;
  pbVar3 = local_38;
  local_18 = ~local_18;
  do {
    iVar2 = iVar2 + -1;
    local_18 = *(uint *)(&DAT_00054ca8 + ((*pbVar3 ^ local_18) & 0xff) * 4) ^ local_18 >> 8;
    pbVar3 = pbVar3 + 1;
  } while (iVar2 != 0);
  local_18 = ~local_18;
  hFile = CreateFileW(L"\\Storage Card\\system\\DSI_config.bsd",0x40000000,0,
                      (LPSECURITY_ATTRIBUTES)0x0,2,0x80,(HANDLE)0x0);
  if (hFile == (HANDLE)0xffffffff) {
    DVar1 = GetLastError();
    NKDbgPrintfW(L"Error!! %s [%s]file open error [0x%08X]!!!\n","SetDSIConfigData",
                 L"\\Storage Card\\system\\DSI_config.bsd",DVar1);
  }
  else {
    WriteFile(hFile,local_38,0x24,aDStack_40,(LPOVERLAPPED)0x0);
    CloseHandle(hFile);
  }
  FUN_00043604(local_14);
  return hFile != (HANDLE)0xffffffff;
}



/* 0002ff2c FUN_0002ff2c */

/* Boundary evidence: original MIPS .pdata 0002ff2c..00030243. Semantic name remains unreviewed. */

undefined4
FUN_0002ff2c(undefined4 *param_1,undefined4 *param_2,uint *param_3,uint *param_4,uint *param_5,
            uint *param_6)

{
  HANDLE hFile;
  undefined4 uVar1;
  DWORD aDStack_40 [2];
  undefined1 auStack_38 [3];
  undefined1 local_35;
  byte local_34;
  byte local_33;
  byte local_31;
  ushort local_30;
  uint local_2c;
  
  local_2c = DAT_00055374;
  memset(auStack_38,0,0xc);
  local_30 = 0x2a2a;
  hFile = CreateFileW(L"\\Storage Card\\system\\DSI_config.bsd",0x80000000,0,
                      (LPSECURITY_ATTRIBUTES)0x0,3,0x80,(HANDLE)0x0);
  if (hFile == (HANDLE)0xffffffff) {
    NKDbgPrintfW(L"%s : File open error.\r\n",L"\\Storage Card\\system\\DSI_config.bsd");
    FUN_00043604(local_2c);
    return 0;
  }
  ReadFile(hFile,auStack_38,0xc,aDStack_40,(LPOVERLAPPED)0x0);
  CloseHandle(hFile);
  if (param_1 == (undefined4 *)0x0) goto LAB_000301a4;
  switch(local_35) {
  case 0:
    uVar1 = 2;
    break;
  case 1:
    *param_1 = 3;
    goto LAB_000301a4;
  case 2:
    uVar1 = 4;
    break;
  case 3:
    uVar1 = 8;
    goto LAB_000301a0;
  case 4:
    uVar1 = 6;
    break;
  case 5:
    uVar1 = 5;
    goto LAB_000301a0;
  case 6:
    *param_1 = 1;
    goto LAB_000301a4;
  case 7:
    uVar1 = 10;
    break;
  case 8:
    uVar1 = 7;
    goto LAB_000301a0;
  case 9:
    *param_1 = 0;
    goto LAB_000301a4;
  case 10:
    uVar1 = 9;
    break;
  case 0xb:
    uVar1 = 0xe;
    break;
  case 0xc:
    uVar1 = 0xb;
    goto LAB_000301a0;
  case 0xd:
    uVar1 = 0x19;
    goto LAB_000301a0;
  case 0xe:
    uVar1 = 0x18;
    break;
  case 0xf:
    uVar1 = 0x1a;
    goto LAB_000301a0;
  case 0x10:
    uVar1 = 0x1b;
    break;
  case 0x11:
    uVar1 = 0x14;
    goto LAB_000301a0;
  case 0x12:
    uVar1 = 0xf;
    break;
  case 0x13:
    uVar1 = 0x10;
    goto LAB_000301a0;
  default:
    uVar1 = 2;
    goto LAB_000301a0;
  case 0x15:
    uVar1 = 0x12;
    break;
  case 0x18:
    uVar1 = 0x13;
    goto LAB_000301a0;
  case 0x19:
    uVar1 = 0x11;
    break;
  case 0x1a:
    uVar1 = 0xc;
    goto LAB_000301a0;
  case 0x1b:
    uVar1 = 0x15;
    goto LAB_000301a0;
  case 0x1c:
    uVar1 = 0x16;
    break;
  case 0x1d:
    uVar1 = 0x17;
LAB_000301a0:
    *param_1 = uVar1;
    goto LAB_000301a4;
  case 0x1e:
    uVar1 = 0xd;
    break;
  case 0x21:
    uVar1 = 0x1c;
  }
  *param_1 = uVar1;
LAB_000301a4:
  if (param_2 != (undefined4 *)0x0) {
    if ((local_31 & 1) == 0) {
      *param_2 = 1;
    }
    else {
      *param_2 = 0;
    }
  }
  if (param_3 != (uint *)0x0) {
    *param_3 = local_31 >> 1 & 1;
  }
  if (param_4 != (uint *)0x0) {
    *param_4 = (uint)local_33;
  }
  if (param_5 != (uint *)0x0) {
    *param_5 = (uint)local_30;
  }
  if (param_6 != (uint *)0x0) {
    *param_6 = (uint)local_34;
  }
  FUN_00043604(local_2c);
  return 1;
}



/* 00030244 FUN_00030244 */

/* Boundary evidence: original MIPS .pdata 00030244..0003045b. Semantic name remains unreviewed. */

void FUN_00030244(void)

{
  int iVar1;
  HANDLE hFile;
  BOOL BVar2;
  wchar_t *pwVar3;
  DWORD DVar4;
  DWORD DVar5;
  uint uVar6;
  uint uVar7;
  DWORD local_d8;
  DWORD local_d4;
  uint local_d0;
  uint local_cc;
  byte local_c8 [56];
  DWORD local_90;
  uint local_8c;
  DWORD local_78;
  byte local_74;
  undefined1 auStack_70 [88];
  
  iVar1 = FUN_0002ff2c(&local_d4,&local_d8,&local_d0,&local_cc,(uint *)0x0,(uint *)0x0);
  DVar4 = local_d4;
  DVar5 = local_d8;
  uVar6 = local_d0;
  uVar7 = local_cc;
  if (iVar1 == 0) {
    NKDbgPrintfW(L"Fail to get DSI setting Info.. default setting\n");
    DVar4 = 2;
    DVar5 = 1;
    uVar6 = 0;
    uVar7 = 0;
  }
  hFile = CreateFileW(L"\\Storage Card2\\MgrSys.cfg",0xc0000000,0,(LPSECURITY_ATTRIBUTES)0x0,3,0x80,
                      (HANDLE)0x0);
  if (hFile == (HANDLE)0xffffffff) {
    NKDbgPrintfW(L"[SetUserData]Fail to open file : MgrSys.cfg\n");
    goto LAB_0003040c;
  }
  ReadFile(hFile,auStack_70,0x55,&local_d4,(LPOVERLAPPED)0x0);
  memcpy(local_c8,auStack_70,0x55);
  local_90 = DVar5;
  local_8c = uVar6;
  local_78 = DVar4;
  local_74 = 0;
  iVar1 = 0;
  do {
    local_74 = local_c8[iVar1] ^ local_74;
    iVar1 = iVar1 + 1;
  } while (iVar1 < 0x54);
  iVar1 = memcmp(auStack_70,local_c8,0x55);
  if (iVar1 == 0) {
    pwVar3 = L"[SetUserData] MgrSys configuration changed !!!\n";
LAB_000303e0:
    NKDbgPrintfW(pwVar3);
  }
  else {
    SetFilePointer(hFile,0,(PLONG)0x0,0);
    BVar2 = WriteFile(hFile,local_c8,0x55,&local_d8,(LPOVERLAPPED)0x0);
    if (BVar2 == 0) {
      pwVar3 = L"MgrSys.cfg write error\r\n";
      goto LAB_000303e0;
    }
  }
  CloseHandle(hFile);
LAB_0003040c:
  DAT_00057354 = (uVar7 << 7 ^ DAT_00057354) & 0x380 ^ DAT_00057354;
  *(char *)(DAT_00055618 + 0x673) = (char)uVar7;
  FUN_0002f484();
  return;
}



/* 0003045c FUN_0003045c */

/* Boundary evidence: original MIPS .pdata 0003045c..0003074b. Semantic name remains unreviewed. */

void FUN_0003045c(uint param_1,undefined1 *param_2)

{
  HANDLE pvVar1;
  BOOL BVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  DWORD DStack_88;
  DWORD DStack_84;
  byte local_80 [80];
  uint local_30;
  byte local_2c;
  
  if (param_1 < 0x22) {
    switch(param_1) {
    default:
      uVar5 = 2;
      break;
    case 1:
      uVar5 = 3;
      break;
    case 2:
      uVar5 = 4;
      break;
    case 3:
      uVar5 = 8;
      break;
    case 4:
      uVar5 = 6;
      break;
    case 5:
      uVar5 = 5;
      break;
    case 6:
      uVar5 = 1;
      break;
    case 7:
      uVar5 = 10;
      break;
    case 8:
      uVar5 = 7;
      break;
    case 9:
      uVar5 = 0;
      break;
    case 10:
      uVar5 = 9;
      break;
    case 0xb:
      uVar5 = 0xe;
      break;
    case 0xc:
      uVar5 = 0xb;
      break;
    case 0xd:
      uVar5 = 0x19;
      break;
    case 0xe:
      uVar5 = 0x18;
      break;
    case 0xf:
      uVar5 = 0x1a;
      break;
    case 0x10:
      uVar5 = 0x1b;
      break;
    case 0x11:
      uVar5 = 0x14;
      break;
    case 0x12:
      uVar5 = 0xf;
      break;
    case 0x13:
      uVar5 = 0x10;
      break;
    case 0x15:
      uVar5 = 0x12;
      break;
    case 0x18:
      uVar5 = 0x13;
      break;
    case 0x19:
      uVar5 = 0x11;
      break;
    case 0x1a:
      uVar5 = 0xc;
      break;
    case 0x1b:
      uVar5 = 0x15;
      break;
    case 0x1c:
      uVar5 = 0x16;
      break;
    case 0x1d:
      uVar5 = 0x17;
      break;
    case 0x1e:
      uVar5 = 0xd;
      break;
    case 0x21:
      uVar5 = 0x1c;
    }
    *param_2 = (char)uVar5;
    pvVar1 = CreateFileW(L"\\Storage Card2\\MgrSys.cfg",0x80000000,0,(LPSECURITY_ATTRIBUTES)0x0,3,
                         0x80,(HANDLE)0x0);
    if (pvVar1 != (HANDLE)0xffffffff) {
      BVar2 = ReadFile(pvVar1,local_80,0x55,&DStack_88,(LPOVERLAPPED)0x0);
      uVar3 = uVar5;
      if (BVar2 != 0) {
        uVar3 = local_30 & 0xff;
      }
      CloseHandle(pvVar1);
      if ((uVar3 != uVar5) &&
         (pvVar1 = CreateFileW(L"\\Storage Card2\\MgrSys.cfg",0x40000000,0,
                               (LPSECURITY_ATTRIBUTES)0x0,3,0x80,(HANDLE)0x0),
         pvVar1 != (HANDLE)0xffffffff)) {
        local_2c = 0;
        local_30 = uVar5;
        iVar4 = 0;
        do {
          local_2c = local_80[iVar4] ^ local_2c;
          iVar4 = iVar4 + 1;
        } while (iVar4 < 0x54);
        WriteFile(pvVar1,local_80,0x55,&DStack_84,(LPOVERLAPPED)0x0);
        CloseHandle(pvVar1);
      }
    }
  }
  else {
    *param_2 = 2;
  }
  return;
}



/* 0003074c FUN_0003074c */

/* Boundary evidence: original MIPS .pdata 0003074c..00030983. Semantic name remains unreviewed. */

void FUN_0003074c(uint param_1,byte *param_2,byte *param_3,byte *param_4)

{
  HANDLE pvVar1;
  int iVar2;
  DWORD DStack_90;
  DWORD DStack_8c;
  uint local_88 [2];
  byte local_80 [56];
  uint local_48;
  uint local_44;
  byte local_2c;
  
  *param_3 = (param_1 & 1) == 0;
  *param_2 = (byte)((param_1 & 2) >> 1);
  *param_4 = (byte)((param_1 & 4) >> 2);
  pvVar1 = CreateFileW(L"\\Storage Card2\\MgrSys.cfg",0xc0000000,0,(LPSECURITY_ATTRIBUTES)0x0,3,0x80
                       ,(HANDLE)0x0);
  if (pvVar1 != (HANDLE)0xffffffff) {
    ReadFile(pvVar1,local_80,0x55,&DStack_90,(LPOVERLAPPED)0x0);
    local_2c = 0;
    iVar2 = 0;
    local_48 = (uint)*param_3;
    local_44 = (uint)*param_2;
    do {
      local_2c = local_80[iVar2] ^ local_2c;
      iVar2 = iVar2 + 1;
    } while (iVar2 < 0x54);
    SetFilePointer(pvVar1,0,(PLONG)0x0,0);
    WriteFile(pvVar1,local_80,0x55,&DStack_8c,(LPOVERLAPPED)0x0);
    CloseHandle(pvVar1);
  }
  pvVar1 = CreateFileW(L"\\Storage Card2\\Navi_Time.cfg",0xc0000000,0,(LPSECURITY_ATTRIBUTES)0x0,3,
                       0x80,(HANDLE)0x0);
  if (pvVar1 != (HANDLE)0xffffffff) {
    ReadFile(pvVar1,local_88,8,&DStack_90,(LPOVERLAPPED)0x0);
    local_88[0] = (uint)*param_4;
    SetFilePointer(pvVar1,0,(PLONG)0x0,0);
    WriteFile(pvVar1,local_88,8,&DStack_8c,(LPOVERLAPPED)0x0);
    CloseHandle(pvVar1);
  }
  return;
}



/* 00030984 FUN_00030984 */

/* Boundary evidence: original MIPS .pdata 00030984..000309cb. Semantic name remains unreviewed. */

void FUN_00030984(uint param_1)

{
  if (param_1 < 6) {
    DAT_00057354 = (param_1 << 7 ^ DAT_00057354) & 0x380 ^ DAT_00057354;
    FUN_0002f484();
  }
  return;
}



/* 000309cc FUN_000309cc */

/* Boundary evidence: original MIPS .pdata 000309cc..00030bd7. Semantic name remains unreviewed. */

void FUN_000309cc(void *param_1,size_t param_2)

{
  HANDLE pvVar1;
  char cVar2;
  DWORD DStack_48;
  DWORD DStack_44;
  DWORD aDStack_40 [2];
  undefined1 auStack_38 [10];
  byte local_2e [2];
  uint local_2c;
  
  local_2c = DAT_00055374;
  pvVar1 = CreateFileW(L"\\Storage Card\\system\\DSI_config.bsd",0xc0000000,0,
                       (LPSECURITY_ATTRIBUTES)0x0,3,0x80,(HANDLE)0x0);
  if (pvVar1 == (HANDLE)0xffffffff) {
    memcpy(local_2e,param_1,param_2);
  }
  else {
    ReadFile(pvVar1,auStack_38,0xc,aDStack_40,(LPOVERLAPPED)0x0);
    memcpy(local_2e,param_1,param_2);
    SetFilePointer(pvVar1,0,(PLONG)0x0,0);
    WriteFile(pvVar1,auStack_38,0xc,&DStack_48,(LPOVERLAPPED)0x0);
    CloseHandle(pvVar1);
  }
  cVar2 = '\x02';
  if ((local_2e[0] & 4) != 0) {
    cVar2 = '\0';
  }
  DAT_00054c95 = ((local_2e[0] & 2) == 0) + cVar2;
  pvVar1 = CreateFileW(L"\\Storage Card\\System\\amtype",0x40000000,0,(LPSECURITY_ATTRIBUTES)0x0,4,
                       0x80,(HANDLE)0x0);
  if (pvVar1 != (HANDLE)0xffffffff) {
    WriteFile(pvVar1,&DAT_00054c95,1,&DStack_44,(LPOVERLAPPED)0x0);
    CloseHandle(pvVar1);
  }
  FUN_00043604(local_2c);
  return;
}



/* 00030bd8 FUN_00030bd8 */

/* Boundary evidence: original MIPS .pdata 00030bd8..00030d5b. Semantic name remains unreviewed. */

void FUN_00030bd8(undefined1 param_1)

{
  HANDLE pvVar1;
  DWORD DStack_40;
  DWORD DStack_3c;
  DWORD aDStack_38 [2];
  undefined1 auStack_30 [4];
  undefined1 local_2c;
  uint local_24;
  
  local_24 = DAT_00055374;
  pvVar1 = CreateFileW(L"\\Storage Card\\system\\DSI_config.bsd",0xc0000000,0,
                       (LPSECURITY_ATTRIBUTES)0x0,3,0x80,(HANDLE)0x0);
  if (pvVar1 != (HANDLE)0xffffffff) {
    ReadFile(pvVar1,auStack_30,0xc,aDStack_38,(LPOVERLAPPED)0x0);
    local_2c = param_1;
    SetFilePointer(pvVar1,0,(PLONG)0x0,0);
    WriteFile(pvVar1,auStack_30,0xc,&DStack_40,(LPOVERLAPPED)0x0);
    CloseHandle(pvVar1);
  }
  DAT_00054c94 = param_1;
  pvVar1 = CreateFileW(L"\\Storage Card\\System\\radcountry",0x40000000,0,(LPSECURITY_ATTRIBUTES)0x0
                       ,4,0x80,(HANDLE)0x0);
  if (pvVar1 != (HANDLE)0xffffffff) {
    WriteFile(pvVar1,&DAT_00054c94,1,&DStack_3c,(LPOVERLAPPED)0x0);
    CloseHandle(pvVar1);
  }
  FUN_00043604(local_24);
  return;
}



/* 00030d5c FUN_00030d5c */

undefined4 FUN_00030d5c(byte *param_1)

{
  undefined4 uVar1;
  
  if (((((0x1f < *param_1) || (0xc < param_1[1])) || (99 < param_1[2])) ||
      ((0x21 < param_1[3] || (5 < param_1[4])))) ||
     ((5 < param_1[5] || ((4 < param_1[6] || (uVar1 = 1, (param_1[7] & 0x30) != 0)))))) {
    uVar1 = 0xffffffff;
  }
  return uVar1;
}



/* 00030de8 FUN_00030de8 */

/* Boundary evidence: original MIPS .pdata 00030de8..00030fcb. Semantic name remains unreviewed. */

uint FUN_00030de8(void *param_1)

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
  
  local_1c = DAT_00055374;
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
        iVar2 = FUN_00030d5c(local_40);
        if (iVar2 != -1) {
          iVar2 = 0x20;
          pbVar3 = local_40;
          do {
            iVar2 = iVar2 + -1;
            uVar4 = *(uint *)(&DAT_00054ca8 + ((*pbVar3 ^ uVar4) & 0xff) * 4) ^ uVar4 >> 8;
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
  FUN_00043604(local_1c);
  return uVar4;
}



/* 00030fcc FUN_00030fcc */

/* Boundary evidence: original MIPS .pdata 00030fcc..00031263. Semantic name remains unreviewed. */

void FUN_00030fcc(int param_1,byte *param_2)

{
  byte bVar1;
  wchar_t *pwVar2;
  wchar_t *pwVar3;
  wchar_t *pwVar4;
  wchar_t *pwVar5;
  wchar_t awStack_f0 [100];
  uint local_28;
  
  local_28 = DAT_00055374;
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
  FUN_00043604(local_28);
  return;
}



/* 00031264 FUN_00031264 */

/* Boundary evidence: original MIPS .pdata 00031264..00031b47. Semantic name remains unreviewed. */

void FUN_00031264(void)

{
  HANDLE pvVar1;
  HANDLE hObject;
  BOOL BVar2;
  byte *pbVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  byte *pbVar9;
  uint uVar10;
  uint uVar11;
  HANDLE hFile;
  int iVar12;
  bool bVar13;
  uint uVar14;
  DWORD local_980;
  undefined *local_97c;
  DWORD local_978 [2];
  byte local_970 [2364];
  uint local_34;
  uint local_30;
  
  local_30 = DAT_00055374;
  pvVar1 = CreateFileW(L"\\Storage Card2\\mgrmcm2.cfg",0x80000000,0,(LPSECURITY_ATTRIBUTES)0x0,3,
                       0x80,(HANDLE)0x0);
  uVar14 = 0x80;
  hObject = CreateFileW(L"\\Storage Card2\\mgrmcm2_backup.cfg",0x80000000,0,
                        (LPSECURITY_ATTRIBUTES)0x0,3,0x80,(HANDLE)0x0);
  uVar10 = 0xffffffff;
  pbVar9 = &DAT_0005734c;
  local_97c = &DAT_00054ca8;
  if ((pvVar1 == (HANDLE)0xffffffff) && (hObject == (HANDLE)0xffffffff)) {
    FUN_0002f084();
    bVar13 = true;
  }
  else {
    bVar13 = pvVar1 == (HANDLE)0xffffffff;
    hFile = hObject;
    if (!bVar13) {
      hFile = pvVar1;
    }
    BVar2 = ReadFile(hFile,&DAT_0005734c,0x940,&local_980,(LPOVERLAPPED)0x0);
    if (local_980 != 0x940) {
      SetFilePointer(hFile,0,(PLONG)0x0,0);
      ReadFile(hFile,&DAT_00058a1c,0x934,local_978,(LPOVERLAPPED)0x0);
      if (local_978[0] != 0x934) {
        NKDbgPrintfW(L"Oh.. my god!! Fuck you!!! %d, %d, %d, %d\r\n",local_980,0x940,local_978[0],
                     0x934);
      }
    }
    if (pvVar1 != (HANDLE)0xffffffff) {
      CloseHandle(pvVar1);
    }
    if (hObject != (HANDLE)0xffffffff) {
      CloseHandle(hObject);
    }
    uVar11 = 0x93b;
    uVar7 = 0;
    do {
      pbVar3 = &DAT_0005734c + uVar7;
      uVar4 = uVar7 & 3;
      uVar7 = uVar7 + 1;
      uVar11 = (uint)*pbVar3 * (uVar4 + 1) + uVar11;
    } while (uVar7 < 0x93b);
    uVar11 = uVar11 & 0xff;
    iVar12 = 0x93c;
    uVar7 = uVar10;
    pbVar3 = pbVar9;
    do {
      iVar12 = iVar12 + -1;
      uVar7 = *(uint *)(local_97c + ((*pbVar3 ^ uVar7) & 0xff) * 4) ^ uVar7 >> 8;
      pbVar3 = pbVar3 + 1;
    } while (iVar12 != 0);
    uVar7 = ~uVar7;
    if ((BVar2 == 0) || (local_980 != 0x940)) {
      if (local_980 == 0x934) {
        FUN_0002f114();
      }
      else if (local_980 == 0x93c) {
        uVar14 = DAT_00057c88;
        NKDbgPrintfW(L"\r\n[****] %s : Old configuration[%d][0x%02X][0x%08X, 0x%08X]\n",
                     "LoadGlobalDataFile",0x93c,DAT_00057c87,uVar7,DAT_00057c88);
        DAT_00057c88 = uVar7;
      }
      else {
        FUN_0002f084();
      }
      bVar13 = true;
    }
    else {
      uVar4 = (uint)DAT_00057c87;
      if (DAT_00057350 == 0x13) {
        if (uVar11 == uVar4) {
          if (uVar7 == DAT_00057c88) goto LAB_00031744;
          goto LAB_000314f0;
        }
LAB_00031550:
        uVar14 = uVar7;
        NKDbgPrintfW(L"[ERROR] %s : Checksum value [%d][0x%02X, 0x%02X][0x%08X, 0x%08X]\n",
                     "LoadGlobalDataFile",!bVar13,uVar11,uVar4,uVar7,DAT_00057c88);
        if ((uVar7 != DAT_00057c88) && (!bVar13)) {
          uVar14 = 0x80;
          pvVar1 = CreateFileW(L"\\Storage Card2\\mgrmcm2_backup.cfg",0x80000000,0,
                               (LPSECURITY_ATTRIBUTES)0x0,3,0x80,(HANDLE)0x0);
          if (pvVar1 != (HANDLE)0xffffffff) {
            ReadFile(pvVar1,local_970,0x940,&local_980,(LPOVERLAPPED)0x0);
            CloseHandle(pvVar1);
            iVar12 = 0x93c;
            pbVar3 = local_970;
            uVar7 = uVar10;
            do {
              iVar12 = iVar12 + -1;
              uVar7 = *(uint *)(local_97c + ((*pbVar3 ^ uVar7) & 0xff) * 4) ^ uVar7 >> 8;
              pbVar3 = pbVar3 + 1;
            } while (iVar12 != 0);
            if (~uVar7 == local_34) {
              memcpy(&DAT_0005734c,local_970,0x940);
              NKDbgPrintfW(L"[OK] %s : backup configuration loaded!!!\n","LoadGlobalDataFile");
            }
            else {
              NKDbgPrintfW(L"[ERROR] %s : backup configuration loaded!!!\n","LoadGlobalDataFile");
              CopyFileW(L"\\Storage Card2\\mgrmcm2.cfg",L"\\Storage Card3\\mgrmcm2.cfg",0);
              CopyFileW(L"\\Storage Card2\\mgrmcm2_backup.cfg",
                        L"\\Storage Card3\\mgrmcm2_backup.cfg",0);
            }
          }
        }
      }
      else {
LAB_000314f0:
        if ((uVar11 != uVar4) || (uVar7 != DAT_00057c88)) goto LAB_00031550;
        DAT_00057350 = 0x13;
        CopyFileW(L"\\Storage Card2\\mgrmcm2.cfg",L"\\Storage Card3\\DATA\\mgrmcm2.cfg",0);
        CopyFileW(L"\\Storage Card2\\mgrmcm2_backup.cfg",
                  L"\\Storage Card3\\DATA\\mgrmcm2_backup.cfg",0);
      }
      bVar13 = true;
    }
LAB_00031744:
    if (0xf < (DAT_00057364 & 0x3f)) {
      DAT_00057364 = DAT_00057364 & 0xffffffcf | 0xf;
    }
    if (0x3c0 < (DAT_00057364 & 0xfc0)) {
      DAT_00057364 = DAT_00057364 & 0xfffff3ff | 0x3c0;
    }
    if (0xf000 < (DAT_00057364 & 0x3f000)) {
      DAT_00057364 = DAT_00057364 & 0xfffcffff | 0xf000;
    }
    if (0x3c0000 < (DAT_00057364 & 0xfc0000)) {
      DAT_00057364 = DAT_00057364 & 0xff3fffff | 0x3c0000;
    }
    if (0xf < (DAT_00057364._3_1_ & 0x3f)) {
      DAT_00057364 = DAT_00057364 & 0xcfffffff | 0xf000000;
    }
    DAT_00057c84 = DAT_00057c84 != '\0';
    if (DAT_00057c86 != '\x01') {
      DAT_00057c86 = '\0';
    }
    if (DAT_00057c85 != '\x01') {
      DAT_00057c85 = '\0';
    }
    uVar7 = 0;
    do {
      if (2 < (byte)(&DAT_0005735c)[uVar7]) {
        (&DAT_0005735c)[uVar7] = 1;
      }
      uVar7 = uVar7 + 1;
    } while (uVar7 < 3);
    uVar7 = 0;
    uVar11 = 0;
    if (DAT_00054c94 == '\x03') {
      uVar4 = 76000;
      uVar8 = 0x172b4;
    }
    else if (DAT_00054c94 == '\x04') {
      uVar4 = 0x15694;
      uVar8 = 0x1a57c;
    }
    else {
      uVar4 = 0x155cc;
      uVar8 = 0x1a5e0;
    }
    if (DAT_00054c94 == '\x01') {
LAB_0003199c:
      uVar6 = 0x642;
LAB_000319a0:
      uVar5 = 0x213;
    }
    else if (DAT_00054c94 == '\x02') {
      if (DAT_00054c95 == '\x01') goto LAB_0003199c;
      uVar5 = 0x95;
      if (DAT_00054c95 == '\x02') {
LAB_00031940:
        uVar5 = 0x95;
        uVar6 = 0x11b;
      }
      else {
        uVar6 = 0x11b;
        uVar7 = 0x213;
        uVar11 = 0x642;
      }
    }
    else if (DAT_00054c94 == '\x03') {
      uVar5 = 0x20a;
      uVar6 = 0x65d;
    }
    else if (DAT_00054c94 == '\x04') {
      uVar5 = 0x212;
      uVar6 = 0x6ae;
    }
    else {
      if (DAT_00054c94 == '\x05') {
        uVar6 = 0x6ae;
        goto LAB_000319a0;
      }
      if (DAT_00054c95 == '\x01') {
        uVar5 = 0x20a;
        uVar6 = 0x64b;
      }
      else {
        uVar5 = 0x95;
        if (DAT_00054c95 == '\x02') goto LAB_00031940;
        uVar6 = 0x11b;
        uVar7 = 0x20a;
        uVar11 = 0x64b;
      }
    }
    if (DAT_00057374 < uVar4) {
      DAT_00057370 = 0;
      DAT_00057374 = uVar4;
    }
    else if (uVar8 < DAT_00057374) {
      DAT_00057370 = 0;
      DAT_00057374 = uVar8;
    }
    if (DAT_00057800 < uVar5) {
      DAT_000577fc = 0;
      DAT_00057800 = uVar5;
    }
    else if (uVar7 == 0) {
LAB_00031a2c:
      if (((uVar6 < DAT_00057800) && (uVar11 < DAT_00057800)) &&
         (DAT_000577fc = 0, DAT_00057800 = uVar11, uVar11 < uVar6)) {
        DAT_00057800 = uVar6;
      }
    }
    else if (uVar6 < DAT_00057800) {
      if (uVar7 <= DAT_00057800) goto LAB_00031a2c;
      DAT_000577fc = 0;
      DAT_00057800 = uVar7;
    }
    if (bVar13 == false) goto LAB_00031a70;
  }
  FUN_0002f484();
LAB_00031a70:
  iVar12 = 0x93c;
  uVar7 = 0;
  uVar11 = 0x93b;
  do {
    pbVar3 = &DAT_0005734c + uVar7;
    uVar4 = uVar7 & 3;
    uVar7 = uVar7 + 1;
    uVar11 = (uint)*pbVar3 * (uVar4 + 1) + uVar11;
  } while (uVar7 < 0x93b);
  DAT_00059358 = (undefined1)uVar11;
  do {
    iVar12 = iVar12 + -1;
    uVar10 = *(uint *)(local_97c + ((*pbVar9 ^ uVar10) & 0xff) * 4) ^ uVar10 >> 8;
    pbVar9 = pbVar9 + 1;
  } while (iVar12 != 0);
  DAT_0005935c = ~uVar10;
  NKDbgPrintfW(L"[!!!!] %s : [%d] Checksum value [0x%02X, 0x%08X]\n","LoadGlobalDataFile",bVar13,
               uVar11 & 0xff,DAT_0005935c,uVar14);
  FUN_00043604(local_30);
  return;
}



/* 00031b48 FUN_00031b48 */

/* Boundary evidence: original MIPS .pdata 00031b48..00031c1b. Semantic name remains unreviewed. */

undefined4 FUN_00031b48(HKEY param_1,LPCWSTR param_2,LPCWSTR param_3,undefined4 param_4)

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



/* 00031c1c FUN_00031c1c */

/* Boundary evidence: original MIPS .pdata 00031c1c..00031d17. Semantic name remains unreviewed. */

bool FUN_00031c1c(HKEY param_1,LPCWSTR param_2,LPCWSTR param_3,wchar_t *param_4,wchar_t *param_5,
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



/* 00031d18 FUN_00031d18 */

/* Boundary evidence: original MIPS .pdata 00031d18..00031de7. Semantic name remains unreviewed. */

bool FUN_00031d18(HKEY param_1,LPCWSTR param_2,LPCWSTR param_3,LPBYTE param_4,DWORD param_5)

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



/* 00031de8 FUN_00031de8 */

/* Boundary evidence: original MIPS .pdata 00031de8..00031ea7. Semantic name remains unreviewed. */

bool FUN_00031de8(HKEY param_1,LPCWSTR param_2,LPCWSTR param_3,BYTE *param_4,DWORD param_5)

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



/* 00031ea8 FUN_00031ea8 */

/* Boundary evidence: original MIPS .pdata 00031ea8..00031f1f. Semantic name remains unreviewed. */

size_t FUN_00031ea8(wchar_t *param_1,LPSTR param_2)

{
  size_t cbMultiByte;
  
  cbMultiByte = 0;
  if (param_2 != (LPSTR)0x0) {
    cbMultiByte = wcslen(param_1);
    WideCharToMultiByte(0,0,param_1,-1,param_2,cbMultiByte,(LPCSTR)0x0,(LPBOOL)0x0);
  }
  return cbMultiByte;
}



/* 00031f20 FUN_00031f20 */

/* Boundary evidence: original MIPS .pdata 00031f20..00032cc3. Semantic name remains unreviewed. */

void FUN_00031f20(int param_1,byte *param_2)

{
  bool bVar1;
  char cVar2;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  undefined3 extraout_var_01;
  int iVar3;
  undefined3 extraout_var_02;
  undefined3 extraout_var_03;
  undefined3 extraout_var_04;
  size_t _Size;
  LSTATUS LVar4;
  HWND hWnd;
  DWORD DVar5;
  UINT Msg;
  LPARAM LVar6;
  undefined4 uVar7;
  undefined *puVar8;
  WPARAM wParam;
  uint uVar9;
  byte bVar10;
  uint uVar11;
  byte bVar12;
  undefined2 uVar13;
  HKEY local_368 [2];
  uint local_360;
  byte local_35c;
  undefined2 local_35a;
  uint local_358 [2];
  byte local_350;
  char local_34f;
  byte local_34e;
  undefined4 local_34d;
  undefined4 local_349;
  uint local_338;
  undefined4 local_334;
  wchar_t awStack_230 [10];
  undefined2 local_21c;
  undefined2 local_21a;
  uint local_28;
  
  local_28 = DAT_00055374;
  uVar11 = 0;
  memset(&local_350,0,0x14);
  memset(awStack_230,0,0x208);
  memset(&local_338,0,0x104);
  bVar10 = *param_2;
  bVar12 = 1;
  switch(bVar10) {
  case 2:
    bVar10 = param_2[2];
    if (bVar10 == 0) {
      iVar3 = FUN_000170cc(DAT_000553dc,0);
    }
    else {
      if (bVar10 == 1) {
        FUN_000170cc(DAT_000553dc,1);
        break;
      }
      if (bVar10 != 2) {
        if (bVar10 != 3) break;
        iVar3 = FUN_000171fc(DAT_000553dc,1,param_2[3]);
        local_350 = *param_2;
        local_34e = param_2[2];
        local_34d._0_2_ = CONCAT11(iVar3 != 0,param_2[3]);
        goto LAB_00032088;
      }
      iVar3 = FUN_000171fc(DAT_000553dc,0,0);
    }
    local_34f = '\x02';
    local_34e = param_2[2];
    local_350 = *param_2 | 0x80;
    if (iVar3 == 0) {
      bVar12 = 0;
    }
    goto LAB_000320f8;
  case 6:
    bVar10 = param_2[2];
    if (bVar10 != 0) {
      if (bVar10 == 1) {
        if (*(char *)(*(int *)(param_1 + 0x10) + 4) == '\0') {
          uVar11 = FUN_00026d78((int)DAT_00057130);
          uVar13 = (undefined2)(uVar11 / 10);
        }
        else {
          uVar7 = FUN_00026d78((int)DAT_00057130);
          uVar13 = (undefined2)uVar7;
        }
        local_350 = *param_2;
        local_34e = param_2[2];
        local_34d = CONCAT22(local_34d._2_2_,uVar13);
LAB_00032088:
        local_350 = local_350 | 0x80;
        local_34f = '\x03';
        uVar11 = 5;
        break;
      }
      if (bVar10 == 2) {
        uVar7 = 0;
      }
      else {
        if (bVar10 != 3) {
          if (bVar10 == 4) {
            uVar7 = 0;
          }
          else {
            if (bVar10 != 5) break;
            uVar7 = 1;
          }
          (**(code **)(*DAT_00057130 + 8))(DAT_00057130,0x6a,uVar7);
LAB_0003216c:
          local_34f = '\x02';
          local_34e = param_2[2];
          uVar11 = 4;
          local_34d = CONCAT31(local_34d._1_3_,1);
          goto LAB_00032c60;
        }
        uVar7 = 1;
      }
      (**(code **)(*DAT_00057130 + 8))(DAT_00057130,0x6b,uVar7);
      goto LAB_000321a8;
    }
    iVar3 = (uint)param_2[4] * 0x100 + (uint)param_2[3];
    if (*(char *)(*(int *)(param_1 + 0x10) + 4) == '\0') {
      iVar3 = iVar3 * 10;
    }
    (**(code **)(*DAT_00057130 + 8))(DAT_00057130,0x6f,iVar3);
    local_34f = '\x02';
    local_34e = param_2[2];
    local_350 = *param_2 | 0x80;
    goto LAB_000320f8;
  case 7:
    bVar12 = param_2[2];
    if (bVar12 == 0) {
      uVar7 = 0;
LAB_00032360:
      (**(code **)(*DAT_00057130 + 8))(DAT_00057130,0x81,uVar7);
      goto LAB_000321a8;
    }
    if (bVar12 == 1) {
      uVar7 = 1;
      goto LAB_00032360;
    }
    if (bVar12 < 2) break;
    if (3 < bVar12) {
      if (bVar12 == 4) {
        uVar7 = 0;
      }
      else {
        if (bVar12 != 5) {
          if (bVar12 != 6) break;
          local_350 = bVar10 | 0x80;
          local_34f = '\t';
          local_34e = bVar12;
          FUN_00026d88((int)DAT_00057130,&local_34d);
          goto LAB_00032308;
        }
        uVar7 = 1;
      }
      (**(code **)(*DAT_00057130 + 8))(DAT_00057130,0x82,uVar7);
      goto LAB_0003216c;
    }
    local_34f = '\x02';
    local_34d = local_34d & 0xffffff00;
    uVar11 = 4;
    local_34e = bVar12;
    goto LAB_00032c68;
  case 8:
    LVar6 = 0x280000;
    goto LAB_00032390;
  case 9:
    if (10 < param_2[2]) break;
    LVar6 = (uint)param_2[2] << 0x10;
    goto LAB_00032390;
  case 0xb:
    if (6 < param_2[2]) break;
    LVar6 = (param_2[2] + 0x14) * 0x10000;
    goto LAB_00032390;
  case 0xc:
    uVar9 = (uint)param_2[2];
    if (uVar9 == 0) {
      bVar1 = FUN_00031d18((HKEY)0x80000002,L"LGE\\SystemStatus\\BT",L"BTAddress",(LPBYTE)&local_338
                           ,6);
      if (CONCAT31(extraout_var,bVar1) != 0) {
        local_350 = *param_2 | 0x80;
        local_34f = '\a';
        local_34e = param_2[2];
        uVar11 = 9;
        local_34d = local_338;
        local_349._0_2_ = (undefined2)local_334;
        break;
      }
      bVar1 = FUN_00031d18((HKEY)0x80000002,L"LGE\\SystemStatus\\BT",L"BTAddress",(LPBYTE)&local_338
                           ,8);
      if (CONCAT31(extraout_var_00,bVar1) != 0) {
        local_350 = *param_2 | 0x80;
        local_34d = local_338;
        local_349 = local_334;
        local_34f = '\t';
        local_34e = param_2[2];
LAB_00032308:
        uVar11 = 0xb;
        break;
      }
      local_350 = *param_2 | 0x80;
LAB_00032554:
      local_34e = param_2[2];
      goto LAB_0003255c;
    }
    if (uVar9 == 0) break;
    if (6 < uVar9) {
      if (uVar9 != 7) break;
      FUN_00033964(0x70,0x1030101,0);
      goto LAB_000321a8;
    }
    LVar6 = (uVar9 + 0x1e) * 0x10000;
    goto LAB_00032390;
  case 0xd:
    bVar10 = param_2[2];
    if (bVar10 == 0) {
      FUN_00012334(DAT_00055384,3);
    }
    else {
      if (bVar10 != 1) {
        if (bVar10 != 2) break;
        iVar3 = *(int *)(DAT_00055384 + 0x4c);
        FUN_00011128(DAT_00055384,(uint)param_2[3]);
        if (iVar3 != 0) {
          FUN_000338ac(0x75,*(LPARAM *)(DAT_00055384 + 0x4c));
        }
        local_34e = param_2[2];
        local_350 = *param_2 | 0x80;
        local_34f = '\x02';
        uVar11 = FUN_00011218();
        cVar2 = (char)uVar11;
        goto LAB_00032ae0;
      }
      FUN_00012334(DAT_00055384,2);
    }
LAB_000321a8:
    local_34f = '\x02';
    local_34e = param_2[2];
    uVar11 = 4;
    local_34d = CONCAT31(local_34d._1_3_,1);
    goto LAB_00032c60;
  case 0xe:
    bVar12 = param_2[2];
    if (bVar12 == 1) {
      local_350 = bVar10 | 0x80;
      bVar1 = FUN_00031c1c((HKEY)0x80000002,L"LGE\\SystemInfo",L"VerMicomFW",L"no info",awStack_230,
                           0x103);
      iVar3 = CONCAT31(extraout_var_04,bVar1);
joined_r0x00032788:
      if (iVar3 == 0) goto LAB_00032554;
    }
    else {
      if (bVar12 == 2) {
        local_350 = bVar10 | 0x80;
        bVar1 = FUN_00031c1c((HKEY)0x80000002,L"LGE\\SystemInfo",L"VerAppmain",L"no info",
                             awStack_230,0x103);
        iVar3 = CONCAT31(extraout_var_03,bVar1);
        goto joined_r0x00032788;
      }
      if (bVar12 == 3) {
        local_350 = bVar10 | 0x80;
        bVar1 = FUN_00031c1c((HKEY)0x80000002,L"LGE\\SystemInfo",L"NaviVersion",L"no info",
                             awStack_230,0x103);
        iVar3 = CONCAT31(extraout_var_02,bVar1);
        goto joined_r0x00032788;
      }
      if (bVar12 != 4) break;
      local_350 = bVar10 | 0x80;
      bVar1 = FUN_00031c1c((HKEY)0x80000002,L"LGE\\SystemInfo",L"OSVersion2",L"no info",awStack_230,
                           0x103);
      if (CONCAT31(extraout_var_01,bVar1) == 0) {
        local_34e = param_2[2];
        uVar11 = 4;
        local_34f = '\x02';
        local_34d = local_34d & 0xffffff00;
        break;
      }
      iVar3 = FUN_00031b48((HKEY)0x80000002,L"LGE\\SystemInfo",L"OSsub",0);
      if (iVar3 == 1) {
        local_21a = 0x31;
      }
      else {
        local_21a = 0x42;
      }
      local_21c = 0x2e;
      NKDbgPrintfW(L"\r\n OSSub %d, %s\n",iVar3,awStack_230);
    }
    _Size = FUN_00031ea8(awStack_230,(LPSTR)&local_338);
    if (0xf < _Size) {
      _Size = 0xf;
    }
    local_34e = param_2[2];
    local_34f = (char)_Size + '\x01';
    memcpy(&local_34d,&local_338,_Size);
    uVar11 = _Size + 3 & 0xff;
    break;
  case 0x13:
    if (param_2[2] == 0) {
      hWnd = FindWindowW(L"TESTWND",(LPCWSTR)0x0);
      local_34e = param_2[2];
      local_350 = *param_2 | 0x80;
      if (hWnd != (HWND)0x0) {
        wParam = 0x13;
LAB_000328ac:
        local_34f = '\x02';
        uVar11 = 0;
        Msg = 0x111;
LAB_00032a80:
        PostMessageW(hWnd,Msg,wParam,uVar11);
        goto LAB_000320f8;
      }
    }
    else {
      if (param_2[2] != 1) break;
      hWnd = FindWindowW(L"TESTWND",(LPCWSTR)0x0);
      local_34e = param_2[2];
      local_350 = *param_2 | 0x80;
      if (hWnd != (HWND)0x0) {
        wParam = 0x14;
        goto LAB_000328ac;
      }
    }
    goto LAB_0003255c;
  case 0x14:
    *(undefined4 *)(DAT_00055498 + 0x58) = 1;
    local_350 = *param_2 | 0x80;
    local_34e = bVar12;
    goto LAB_000328d8;
  case 0x17:
    local_34f = '\x02';
    local_34e = param_2[2];
    local_350 = bVar10 | 0x80;
    if (5 < local_34e) goto LAB_0003255c;
    FUN_0001129c(DAT_00055384,(uint)local_34e);
LAB_000320f8:
    local_34d = CONCAT31(local_34d._1_3_,bVar12);
LAB_000320fc:
    uVar11 = 4;
    break;
  case 0x20:
    LVar6 = 0x320000;
LAB_00032390:
    FUN_000338ac(0x7b,LVar6);
    break;
  case 0x27:
    local_34f = '\x02';
    local_34e = param_2[2];
    local_350 = bVar10 | 0x80;
    uVar9 = (uint)param_2[2];
    if (local_34e < 0xc) {
      uVar11 = 4;
      local_34d = CONCAT31(local_34d._1_3_,1);
      local_358[0] = uVar9;
      LVar4 = RegOpenKeyExW((HKEY)0x80000002,L"LGE\\SystemInfo",0,0,local_368);
      if (LVar4 == 0) {
        RegSetValueExW(local_368[0],L"GUIDELINE_TYPE",0,4,(BYTE *)local_358,4);
        RegCloseKey(local_368[0]);
      }
      break;
    }
    if ((uVar9 == 0xfe) || (uVar9 == 0xff)) {
      hWnd = FindWindowW(L"RVC WND",L"RVC WND");
      if (param_2[2] == 0xfe) {
        puVar8 = &DAT_0005078c;
      }
      else {
        puVar8 = &DAT_00050784;
      }
      NKDbgPrintfW(L"[INFO] [0x%08X]rvc guideline on/off [%s]\n",hWnd,puVar8);
      DVar5 = GetLastError();
      NKDbgPrintfW(L"[INFO] [0x%08X][0x%08X]rvc guideline on/off [0x%08X]\n",hWnd,DAT_00059380,DVar5
                  );
      uVar11 = (uint)param_2[2];
      wParam = 0;
      Msg = DAT_00059380;
      if (hWnd == (HWND)0x0) {
        hWnd = (HWND)0xffff;
      }
      goto LAB_00032a80;
    }
LAB_0003255c:
    local_34f = '\x02';
    local_34d = local_34d & 0xffffff00;
    goto LAB_000320fc;
  case 0x28:
    local_34f = '\x02';
    local_34e = param_2[2];
    local_350 = bVar10 | 0x80;
    if ((local_34e < 5) || (param_2[2] == 0x1f)) {
      FUN_0001c030();
      cVar2 = FUN_0002fc28(param_2[2]);
LAB_00032ae0:
      local_34d = CONCAT31(local_34d._1_3_,cVar2);
    }
    else {
      local_34d = CONCAT31(local_34d._1_3_,0xff);
    }
    goto LAB_000320fc;
  case 0x2a:
    memset(&local_360,0,8);
    local_360 = (uint)CONCAT21(CONCAT11(param_2[2],param_2[3]),param_2[4]);
    local_35a = CONCAT11(param_2[6],param_2[7]);
    local_35c = param_2[5];
    FUN_00031de8((HKEY)0x80000002,L"LGE\\SystemStatus\\BTDirect",L"DirectAddress",(BYTE *)&local_360
                 ,8);
    FUN_000339cc(0x3040101,0);
    DAT_00059368 = 1;
    break;
  case 0x2b:
    NKDbgPrintfW(L"\r\n Get Mute  0x%08X : ",DAT_00055384);
    if (DAT_00055384 == 0) break;
    NKDbgPrintfW(L"GetIsMute() -> %d\r\n",*(undefined4 *)(DAT_00055384 + 0x4c));
    local_350 = *param_2 | 0x80;
    local_34e = bVar12;
    if (*(int *)(DAT_00055384 + 0x4c) != 1) {
      local_34e = 0;
    }
LAB_000328d8:
    local_34f = '\x01';
    uVar11 = 3;
    break;
  case 0x2e:
    bVar10 = 0;
    DVar5 = GetFileAttributesW(L"\\Storage Card4\\NNG\\content\\map\\France.fbl");
    if (DVar5 == 0xffffffff) {
      DVar5 = GetFileAttributesW(L"\\Storage Card4\\NNG\\content\\map\\India.fbl");
      if (DVar5 == 0xffffffff) {
        DVar5 = GetFileAttributesW(L"\\Storage Card4\\NNG\\content\\map\\Brazil.fbl");
        if (DVar5 != 0xffffffff) {
          bVar10 = 3;
        }
      }
      else {
        bVar10 = 2;
      }
    }
    else {
      bVar10 = 1;
    }
    NKDbgPrintfW(L"\r\n Check Map package ....%d\r\n",bVar10);
    uVar11 = 3;
    local_34f = '\x01';
    local_34e = bVar10;
LAB_00032c60:
    bVar10 = *param_2;
LAB_00032c68:
    local_350 = bVar10 | 0x80;
  }
  if (uVar11 != 0) {
    FUN_00015b90(DAT_000553cc,1,0x80,(int)&local_350,(byte)uVar11,0x32);
  }
  FUN_00043604(local_28);
  return;
}



/* 00032cc4 FUN_00032cc4 */

/* Boundary evidence: original MIPS .pdata 00032cc4..00032eb3. Semantic name remains unreviewed. */

void FUN_00032cc4(undefined4 param_1,uint param_2)

{
  uint uVar1;
  char cVar2;
  uint uVar3;
  byte bVar4;
  undefined1 local_28;
  undefined1 local_27;
  char local_26;
  undefined1 local_25;
  uint local_14;
  
  local_14 = DAT_00055374;
  uVar1 = param_2 >> 0x10;
  uVar3 = param_2 & 0xffff;
  bVar4 = 0;
  cVar2 = '\x01';
  if (uVar1 < 0x29) {
    if (uVar1 == 0x28) {
      local_28 = 0x88;
      local_26 = (char)(uVar3 >> 8);
      local_25 = (undefined1)uVar3;
    }
    else {
      cVar2 = (char)(param_2 >> 0x10);
      if (uVar1 < 0xb) {
        local_28 = 0x89;
        local_26 = cVar2;
      }
      else {
        if (uVar1 < 0x14) goto LAB_00032e70;
        if (uVar1 < 0x1b) {
          local_28 = 0x8b;
          local_26 = cVar2 + -0x14;
        }
        else {
          if ((uVar1 < 0x1f) || (0x24 < uVar1)) goto LAB_00032e70;
          local_28 = 0x8c;
          local_26 = cVar2 + -0x1e;
        }
      }
      local_25 = uVar3 != 0;
    }
    local_27 = 2;
    bVar4 = 4;
    goto LAB_00032e70;
  }
  if (uVar1 == 0x32) {
    local_28 = 0xa0;
  }
  else {
    if (uVar1 == 0xf0) {
      local_28 = 0x82;
      local_27 = 2;
      local_25 = uVar3 != 0;
      local_26 = '\x01';
      bVar4 = 4;
      FUN_000170cc(DAT_000553dc,0);
      goto LAB_00032e70;
    }
    if ((uVar1 != 0xf1) || (DAT_00059368 == 0)) goto LAB_00032e70;
    DAT_00059368 = 0;
    local_28 = 0xaa;
    if (uVar3 == 0) {
      cVar2 = '\0';
    }
  }
  local_27 = 1;
  bVar4 = 3;
  local_26 = cVar2;
LAB_00032e70:
  if (bVar4 != 0) {
    FUN_00015b90(DAT_000553cc,1,0x80,(int)&local_28,bVar4,0x32);
  }
  FUN_00043604(local_14);
  return;
}



/* 00032eb4 FUN_00032eb4 */

/* Boundary evidence: original MIPS .pdata 00032eb4..00033027. Semantic name remains unreviewed. */

void FUN_00032eb4(undefined4 param_1,byte *param_2)

{
  undefined4 *puVar1;
  int iVar2;
  wchar_t awStack_220 [260];
  uint local_18;
  
  local_18 = DAT_00055374;
  if (0x4d < *param_2) goto LAB_00033008;
  StringCchPrintfW(awStack_220,0x104,L"%s",(&PTR_u_DSI_TBD_TBC_00055154)[*param_2]);
  if (DAT_000553d0 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)__2_YAPAXI_Z(0x14);
    if (puVar1 == (undefined4 *)0x0) {
      DAT_000553d0 = (undefined4 *)0x0;
    }
    else {
      DAT_000553d0 = FUN_00016264(puVar1,DAT_00055600);
    }
    if ((DAT_000553d0 == (undefined4 *)0x0) || (DAT_000553d0[3] != 0)) goto LAB_00033008;
    FUN_00016318((int)DAT_000553d0);
    if (DAT_000553d0[4] == 0) goto LAB_00033008;
    iVar2 = FUN_000164a8((int)DAT_000553d0);
    if (iVar2 == 0) {
      if (DAT_000553d0 != (undefined4 *)0x0) {
        (**(code **)*DAT_000553d0)(DAT_000553d0,1);
      }
      DAT_000553d0 = (undefined4 *)0x0;
      goto LAB_00033008;
    }
  }
  else {
    FUN_00016318((int)DAT_000553d0);
    if (DAT_000553d0[4] != 1) goto LAB_00033008;
    if (DAT_000553d0[3] == 1) {
      FUN_000165f0((int)DAT_000553d0,(LPARAM)awStack_220);
      goto LAB_00033008;
    }
  }
  FUN_00016284((int)DAT_000553d0);
  FUN_000165f0((int)DAT_000553d0,(LPARAM)awStack_220);
  FUN_000162f0((int)DAT_000553d0);
LAB_00033008:
  FUN_00043604(local_18);
  return;
}



/* 00033028 Unwind@00033028 */

/* Boundary evidence: original MIPS .pdata 00033028..00033057. Semantic name remains unreviewed. */

void Unwind_00033028(void)

{
  int in_v0;
  
  __3_YAXPAX_Z(*(undefined4 *)(in_v0 + -0x228));
  return;
}



/* 00033058 FUN_00033058 */

/* Boundary evidence: original MIPS .pdata 00033058..0003372f. Semantic name remains unreviewed. */

void FUN_00033058(int param_1,byte *param_2)

{
  byte bVar1;
  undefined2 uVar2;
  HWND hWnd;
  LSTATUS LVar3;
  int iVar4;
  wchar_t *pwVar5;
  uint wParam;
  byte *pbVar6;
  byte local_48;
  byte local_47;
  byte local_46;
  byte local_45;
  byte local_44 [4];
  HKEY local_40 [2];
  undefined1 auStack_38 [36];
  uint local_14;
  
  local_14 = DAT_00055374;
  wParam = (uint)*param_2;
  local_46 = 0;
  local_45 = 0;
  local_47 = 0;
  local_44[0] = 0;
  if (wParam < 0x3c) {
    if (wParam != 0x3b) {
      if (wParam < 0x13) {
        if (wParam == 0x12) {
          NKDbgPrintfW(L"[DsiSaveUIConfProc] SDVC - 0x%X",param_2[1]);
          if (*(int *)(param_1 + 0x3c) == 1) {
            NKDbgPrintfW(L"- in VIRGIN\n");
            *(byte *)(param_1 + 0x45) = param_2[1];
          }
          else {
            NKDbgPrintfW(&DAT_0004b190);
            FUN_000338ac(0x7d,(uint)param_2[1]);
          }
          FUN_00030984((uint)param_2[1]);
        }
        else if (wParam == 7) {
          NKDbgPrintfW(L"[DsiSaveUIConfProc] CLR DTC - 0x%X",param_2[1]);
          memset(auStack_38,0x10,0x24);
          FUN_000207fc(param_1,auStack_38,0x24);
        }
        else {
          if (wParam == 0xf) {
            NKDbgPrintfW(L"[DsiSaveUIConfProc] MMI Language - 0x%X",param_2[1]);
            if (*(int *)(param_1 + 0x3c) == 1) {
              NKDbgPrintfW(L"- in VIRGIN\n");
              *(byte *)(param_1 + 0x43) = param_2[1];
              goto switchD_000334fc_caseD_3f;
            }
            NKDbgPrintfW(&DAT_0004b190);
            FUN_0003045c((uint)param_2[1],&local_46);
            iVar4 = 0x7c;
            bVar1 = local_46;
          }
          else {
            if (wParam != 0x10) {
              if (wParam == 0x11) {
                NKDbgPrintfW(L"[DsiSaveUIConfProc] Radio Contry - 0x%X",param_2[1]);
                if (*(int *)(param_1 + 0x3c) == 1) {
                  NKDbgPrintfW(L"- in VIRGIN\n");
                  *(byte *)(param_1 + 0x44) = param_2[1];
                }
                else {
                  NKDbgPrintfW(&DAT_0004b190);
                }
                FUN_00030bd8(param_2[1]);
              }
              goto switchD_000334fc_caseD_3f;
            }
            NKDbgPrintfW(L"[DsiSaveUIConfProc] UI(Dist&Spd, Nav, Coloring etc - 0x%X",param_2[1]);
            if (*(int *)(param_1 + 0x3c) == 1) {
              NKDbgPrintfW(L"- in VIRGIN\n");
              *(byte *)(param_1 + 0x47) = param_2[1];
              goto switchD_000334fc_caseD_3f;
            }
            NKDbgPrintfW(&DAT_0004b190);
            FUN_0003074c((uint)param_2[1],&local_45,&local_47,local_44);
            FUN_000338ac(0x81,(uint)local_44[0]);
            FUN_000338ac(0x7e,(uint)local_45);
            iVar4 = 0x7f;
            bVar1 = local_47;
          }
          FUN_000338ac(iVar4,(uint)bVar1);
        }
      }
      else if (wParam == 0x13) {
        NKDbgPrintfW(L"[DsiSaveUIConfProc] CAR Maker - 0x%X",param_2[1]);
        if (*(int *)(param_1 + 0x3c) == 1) {
          NKDbgPrintfW(L"- in VIRGIN\n");
          *(byte *)(param_1 + 0x46) = param_2[1];
        }
        else {
          FUN_0001c030();
          NKDbgPrintfW(&DAT_0004b190);
        }
        FUN_0002fc28(param_2[1]);
      }
      else if (wParam == 0x14) {
        pbVar6 = param_2 + 1;
        NKDbgPrintfW(L"[DsiSaveUIConfProc] CNF_ECU - 0x%X, 0x%X",*pbVar6,param_2[2]);
        if (*(int *)(param_1 + 0x3c) == 1) {
          NKDbgPrintfW(L"- in VIRGIN\n");
          *(byte *)(param_1 + 0x47) = *pbVar6;
        }
        else {
          NKDbgPrintfW(&DAT_0004b190);
        }
        FUN_000309cc(pbVar6,2);
      }
      else {
        if (wParam == 0x19) {
          NKDbgPrintfW(L"[DsiSaveUIConfProc] Map code - 0x%X",param_2[1]);
          uVar2 = *(undefined2 *)(param_2 + 1);
          if (*(int *)(param_1 + 0x3c) == 1) {
            NKDbgPrintfW(L"- in VIRGIN\n");
            *(undefined2 *)(param_1 + 0x48) = uVar2;
            goto switchD_000334fc_caseD_3f;
          }
          pwVar5 = L"\n";
        }
        else {
          if (wParam != 0x3a) goto switchD_000334fc_caseD_3f;
          if (*(int *)(param_1 + 0x3c) != 1) {
            hWnd = FindWindowW((LPCWSTR)0x0,L"RVC WND");
            NKDbgPrintfW(L"[DsiSaveUIConfProc] Write RVC Type - 0x%02X\n",param_2[1]);
            if (hWnd != (HWND)0x0) {
              SendMessageW(hWnd,0x9e64,0,(uint)param_2[1]);
            }
            goto switchD_000334fc_caseD_3f;
          }
          pwVar5 = L"- in VIRGIN\n";
        }
        NKDbgPrintfW(pwVar5);
      }
      goto switchD_000334fc_caseD_3f;
    }
    pwVar5 = L"[DsiSaveUIConfProc] Read RVC Type - 0x%02X\n";
LAB_000334bc:
    bVar1 = param_2[1];
LAB_000334c4:
    NKDbgPrintfW(pwVar5,bVar1);
  }
  else {
    switch(wParam) {
    case 0x3c:
      bVar1 = param_2[1];
      pwVar5 = L"[DsiSaveUIConfProc] Write CAR Type - 0x%02X\n";
      goto LAB_000334c4;
    case 0x3d:
      pwVar5 = L"[DsiSaveUIConfProc] Read CAR Type - 0x%02X\n";
      goto LAB_000334bc;
    case 0x3e:
      DeleteFileW(L"\\Storage Card2\\EcoDrive.cfg");
      break;
    case 0x40:
    case 0x42:
    case 0x44:
    case 0x46:
    case 0x48:
      LVar3 = RegOpenKeyExW((HKEY)0x80000002,L"LGE\\SystemInfo",0,0,local_40);
      if (LVar3 == 0) {
        local_48 = param_2[1];
        if (wParam == 0x40) {
          RegSetValueExW(local_40[0],L"RVC_BRIGHTNESS",0,4,&local_48,4);
        }
        else if (wParam == 0x42) {
          RegSetValueExW(local_40[0],L"RVC_CONTRAST",0,4,&local_48,4);
        }
        else if (wParam == 0x44) {
          RegSetValueExW(local_40[0],L"RVC_HUE",0,4,&local_48,4);
        }
        else if (wParam == 0x46) {
          RegSetValueExW(local_40[0],L"RVC_SATU",0,4,&local_48,4);
        }
        else if (wParam == 0x48) {
          RegSetValueExW(local_40[0],L"RVC_SATV",0,4,&local_48,4);
        }
        RegCloseKey(local_40[0]);
        PostMessageW((HWND)0xffff,DAT_0005937c,wParam,(uint)local_48);
      }
    }
  }
switchD_000334fc_caseD_3f:
  FUN_00043604(local_14);
  return;
}



/* 00033730 FUN_00033730 */

/* Boundary evidence: original MIPS .pdata 00033730..000338ab. Semantic name remains unreviewed. */

undefined4 FUN_00033730(void)

{
  bool bVar1;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  BYTE local_120 [260];
  uint local_1c;
  
  local_1c = DAT_00055374;
  iVar5 = 6;
  iVar3 = 0;
  bVar1 = FUN_00031d18((HKEY)0x80000002,L"LGE\\SystemStatus\\BT",L"BTAddress",local_120,6);
  if (CONCAT31(extraout_var,bVar1) == 0) {
    iVar5 = 8;
    bVar1 = FUN_00031d18((HKEY)0x80000002,L"LGE\\SystemStatus\\BT",L"BTAddress",local_120,8);
    if (CONCAT31(extraout_var_00,bVar1) == 0) {
      uVar2 = 2;
      goto LAB_00033880;
    }
    NKDbgPrintfW(L"[CheckBTInit] ");
    iVar4 = 0;
    do {
      NKDbgPrintfW(L"0x%02X ",local_120[iVar4]);
      if (local_120[iVar4] == '\0') {
        iVar3 = iVar3 + 1;
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < 8);
  }
  else {
    NKDbgPrintfW(L"[CheckBTInit] ");
    iVar4 = 0;
    do {
      NKDbgPrintfW(L"0x%02X ",local_120[iVar4]);
      if (local_120[iVar4] == '\0') {
        iVar3 = iVar3 + 1;
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < 6);
  }
  if (iVar3 == iVar5) {
    uVar2 = 1;
  }
  else {
    uVar2 = 0;
  }
LAB_00033880:
  FUN_00043604(local_1c);
  return uVar2;
}



/* 000338ac FUN_000338ac */

/* Boundary evidence: original MIPS .pdata 000338ac..00033907. Semantic name remains unreviewed. */

void FUN_000338ac(int param_1,LPARAM param_2)

{
  HWND hWnd;
  
  hWnd = FindWindowW(L"AppMain",(LPCWSTR)0x0);
  if (hWnd != (HWND)0x0) {
    PostMessageW(hWnd,0x8064,param_1 << 0x10 | 0x300,param_2);
  }
  return;
}



/* 00033908 FUN_00033908 */

/* Boundary evidence: original MIPS .pdata 00033908..00033963. Semantic name remains unreviewed. */

void FUN_00033908(int param_1,LPARAM param_2)

{
  HWND hWnd;
  
  hWnd = FindWindowW(L"AppMain",(LPCWSTR)0x0);
  if (hWnd != (HWND)0x0) {
    SendMessageW(hWnd,0x8064,param_1 << 0x10 | 0x300,param_2);
  }
  return;
}



/* 00033964 FUN_00033964 */

/* Boundary evidence: original MIPS .pdata 00033964..000339cb. Semantic name remains unreviewed. */

void FUN_00033964(int param_1,WPARAM param_2,LPARAM param_3)

{
  HWND hWnd;
  
  hWnd = FindWindowW(L"Blue",(LPCWSTR)0x0);
  if (hWnd != (HWND)0x0) {
    PostMessageW(hWnd,param_1 + 0x8000,param_2,param_3);
  }
  return;
}



/* 000339cc FUN_000339cc */

/* Boundary evidence: original MIPS .pdata 000339cc..00033a23. Semantic name remains unreviewed. */

void FUN_000339cc(WPARAM param_1,LPARAM param_2)

{
  HWND hWnd;
  
  hWnd = FindWindowW(L"Blue",(LPCWSTR)0x0);
  if (hWnd != (HWND)0x0) {
    PostMessageW(hWnd,0x8082,param_1,param_2);
  }
  return;
}



/* 00033a24 FUN_00033a24 */

void FUN_00033a24(undefined4 *param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  param_1[1] = 4;
  *param_1 = 1;
  param_1[4] = 100;
  if (param_2 == 3) {
    uVar1 = 76000;
    param_1[5] = 100;
    uVar2 = 0x172b4;
LAB_00033aa0:
    param_1[3] = uVar2;
    param_1[2] = uVar1;
    if (param_2 == 1) {
LAB_00033b90:
      uVar2 = 0x642;
      uVar1 = 0x213;
LAB_00033b98:
      param_1[0x12] = uVar1;
      param_1[0x14] = 9;
      param_1[0x15] = 1;
    }
    else {
      if (param_2 == 2) {
        if (param_3 != 1) {
          param_1[0x11] = 0;
          param_1[0x14] = 1;
          param_1[0x15] = 1;
          param_1[0x12] = 0x95;
          param_1[0x13] = 0x11b;
          if (param_3 != 2) {
            param_1[0x10] = 2;
            uVar2 = 0x213;
            uVar1 = 0x642;
LAB_00033b08:
            param_1[0x17] = uVar2;
            param_1[0x16] = 1;
            param_1[0x18] = uVar1;
            param_1[0x19] = 9;
            param_1[0x1a] = 1;
            return;
          }
          goto LAB_00033bb0;
        }
        goto LAB_00033b90;
      }
      if (param_2 != 3) {
        if (param_2 == 4) goto LAB_00033a74;
        if (param_2 == 5) {
          uVar1 = 0x213;
          uVar2 = 0x6ae;
          goto LAB_00033b38;
        }
        if (param_3 != 1) {
          param_1[0x11] = 0;
          param_1[0x14] = 1;
          param_1[0x15] = 1;
          param_1[0x12] = 0x95;
          param_1[0x13] = 0x11b;
          if (param_3 != 2) {
            param_1[0x10] = 2;
            uVar2 = 0x20a;
            uVar1 = 0x64b;
            goto LAB_00033b08;
          }
          goto LAB_00033bb0;
        }
        uVar1 = 0x20a;
        uVar2 = 0x64b;
        goto LAB_00033b98;
      }
      uVar1 = 0x20a;
      uVar2 = 0x65d;
LAB_00033b38:
      param_1[0x12] = uVar1;
      param_1[0x14] = 9;
      param_1[0x15] = 9;
    }
    param_1[0x13] = uVar2;
  }
  else {
    param_1[5] = 0x32;
    if (param_2 != 4) {
      uVar1 = 0x155cc;
      uVar2 = 0x1a5e0;
      goto LAB_00033aa0;
    }
    param_1[2] = 0x15694;
    param_1[3] = 0x1a57c;
LAB_00033a74:
    param_1[0x12] = 0x212;
    param_1[0x13] = 0x6ae;
    param_1[0x14] = 10;
    param_1[0x15] = 1;
  }
  param_1[0x11] = 1;
LAB_00033bb0:
  param_1[0x10] = 1;
  return;
}



/* 00033bbc FUN_00033bbc */

/* Boundary evidence: original MIPS .pdata 00033bbc..00033cef. Semantic name remains unreviewed. */

undefined4 * FUN_00033bbc(undefined4 *param_1)

{
  undefined4 *puVar1;
  int iVar2;
  uint uVar3;
  char *_DstBuf;
  
  FUN_0003e4a8(param_1);
  *param_1 = &PTR_FUN_00051230;
  param_1[0x13] = 0x32;
  param_1[0x14] = 0x1e;
  param_1[0x15] = 0xfffffff6;
  param_1[0x16] = 0x19;
  param_1[0x17] = 0x19;
  param_1[0x18] = 0;
  puVar1 = param_1 + 0x22;
  param_1[0x19] = 0;
  iVar2 = 0x20;
  param_1[0x1a] = 0;
  param_1[0x1b] = 0;
  *(undefined1 *)(param_1 + 0x6a) = 0;
  *(undefined1 *)((int)param_1 + 0x1a9) = 0;
  *(undefined1 *)((int)param_1 + 0x1aa) = 0;
  *(undefined1 *)((int)param_1 + 0x1ab) = 0;
  *(undefined1 *)(param_1 + 0x6b) = 0;
  param_1[0x11] = 0;
  param_1[0x1d] = 0;
  *(undefined1 *)(param_1 + 0x1c) = 0;
  do {
    *puVar1 = 0;
    puVar1[0x20] = 0;
    iVar2 = iVar2 + -1;
    puVar1 = puVar1 + 1;
  } while (iVar2 != 0);
  param_1[0x67] = 0x50;
  param_1[0x65] = 9;
  *(undefined1 *)(param_1 + 0x12) = 0;
  param_1[0x1e] = 0;
  uVar3 = 0;
  param_1[0xd] = 0;
  _DstBuf = (char *)((int)param_1 + 0x1ad);
  param_1[0xe] = 0;
  param_1[0x10] = 0;
  param_1[0xf] = 0;
  param_1[0x66] = 0;
  param_1[0x20] = 1;
  param_1[0x69] = 0;
  param_1[0x68] = 0xffffffff;
  do {
    sprintf_s(_DstBuf,0x80,"No Log...(%d)",uVar3);
    uVar3 = uVar3 + 1;
    _DstBuf = _DstBuf + 0x80;
  } while (uVar3 < 0x10);
  return param_1;
}



/* 00033cf0 FUN_00033cf0 */

/* Boundary evidence: original MIPS .pdata 00033cf0..00033dd3. Semantic name remains unreviewed. */

void FUN_00033cf0(int param_1)

{
  undefined1 local_18 [8];
  
  FUN_0003e8b8(param_1,100);
  FUN_0003e8b8(param_1,0x65);
  FUN_0003e8b8(param_1,0x66);
  FUN_0003e8b8(param_1,0x67);
  FUN_0003e8b8(param_1,0x6c);
  FUN_0003e8b8(param_1,0x6d);
  *(undefined4 *)(DAT_00057130 + 0x5c) = 0;
  if (*(int *)(param_1 + 0x80) == 0) {
    local_18[0] = 0;
    FUN_00015b90(DAT_000553cc,0,0x30,(int)local_18,1,0x32);
  }
  local_18[0] = 0;
  FUN_00015b90(DAT_000553cc,3,0xf0,(int)local_18,1,0x32);
  DAT_00059354 = 0;
  return;
}



/* 00033dd4 FUN_00033dd4 */

/* Boundary evidence: original MIPS .pdata 00033dd4..00033fe7. Semantic name remains unreviewed. */

void FUN_00033dd4(int param_1,HDC param_2,int param_3,LONG param_4,COLORREF param_5,COLORREF param_6
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
  if (*(int *)(param_1 + 0x194) == param_3) {
    param_6 = 0x50503c;
  }
  else if (*(int *)(param_1 + 0x19c) == param_3) {
    param_6 = 0x323232;
  }
  lprc = (RECT *)(&DAT_00050d20 + param_3 * 4);
  FUN_0003a114(param_1,hdc,lprc,param_6);
  SetBkMode(hdc,1);
  SetTextColor(hdc,param_5);
  h_01 = FUN_0003a02c(param_4,0,0,0,0,'\0','\0','\0','\0','\0','\0','\x06','\x02',L"Tahoma");
  h_02 = SelectObject(hdc,h_01);
  DrawTextW(hdc,param_7,-1,lprc,5);
  SelectObject(hdc,h_02);
  DeleteObject(h_01);
  y = (&DAT_00050d24)[param_3 * 4];
  x = lprc->left;
  BitBlt(param_2,x,y,(&DAT_00050d28)[param_3 * 4] - x,(&DAT_00050d2c)[param_3 * 4] - y,hdc,x,y,
         0xcc0020);
  SelectObject(hdc,h_00);
  DeleteObject(h);
  DeleteDC(hdc);
  return;
}



/* 00033fe8 FUN_00033fe8 */

/* Boundary evidence: original MIPS .pdata 00033fe8..000341fb. Semantic name remains unreviewed. */

void FUN_00033fe8(int param_1,HDC param_2,int param_3,LONG param_4,COLORREF param_5,COLORREF param_6
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
  if (*(int *)(param_1 + 0x194) == param_3) {
    param_6 = 0x50503c;
  }
  else if (*(int *)(param_1 + 0x19c) == param_3) {
    param_6 = 0x323232;
  }
  lprc = (RECT *)(&DAT_00050d20 + param_3 * 4);
  FUN_0003a114(param_1,hdc,lprc,param_6);
  SetBkMode(hdc,1);
  SetTextColor(hdc,param_5);
  h_01 = FUN_0003a02c(param_4,0,0,0,0,'\0','\0','\0','\0','\0','\0','\x06','\x02',L"Tahoma");
  h_02 = SelectObject(hdc,h_01);
  DrawTextW(hdc,param_7,-1,lprc,4);
  SelectObject(hdc,h_02);
  DeleteObject(h_01);
  y = (&DAT_00050d24)[param_3 * 4];
  x = lprc->left;
  BitBlt(param_2,x,y,(&DAT_00050d28)[param_3 * 4] - x,(&DAT_00050d2c)[param_3 * 4] - y,hdc,x,y,
         0xcc0020);
  SelectObject(hdc,h_00);
  DeleteObject(h);
  DeleteDC(hdc);
  return;
}



/* 000341fc FUN_000341fc */

/* Boundary evidence: original MIPS .pdata 000341fc..000344af. Semantic name remains unreviewed. */

void FUN_000341fc(int param_1,HDC param_2,int param_3,LONG param_4,LONG param_5,COLORREF param_6,
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
  if (*(int *)(param_1 + 0x194) == param_3) {
    param_8 = 0x50503c;
  }
  else if (*(int *)(param_1 + 0x19c) == param_3) {
    param_8 = 0x323232;
  }
  lprc = (RECT *)(&DAT_00050d20 + param_3 * 4);
  FUN_0003a114(param_1,hdc,lprc,param_8);
  SetBkMode(hdc,1);
  SetTextColor(hdc,param_6);
  pHVar1 = FUN_0003a02c(param_4,0,0,0,0,'\0','\0','\0','\0','\0','\0','\x06','\x02',L"Tahoma");
  pvVar2 = SelectObject(hdc,pHVar1);
  DrawTextW(hdc,param_9,-1,lprc,1);
  SelectObject(hdc,pvVar2);
  DeleteObject(pHVar1);
  SetBkMode(hdc,1);
  SetTextColor(hdc,param_7);
  pHVar1 = FUN_0003a02c(param_5,0,0,0,0,'\0','\0','\0','\0','\0','\0','\x06','\x02',L"Tahoma");
  pvVar2 = SelectObject(hdc,pHVar1);
  DrawTextW(hdc,param_10,-1,lprc,9);
  SelectObject(hdc,pvVar2);
  DeleteObject(pHVar1);
  y = (&DAT_00050d24)[param_3 * 4];
  x = lprc->left;
  BitBlt(param_2,x,y,(&DAT_00050d28)[param_3 * 4] - x,(&DAT_00050d2c)[param_3 * 4] - y,hdc,x,y,
         0xcc0020);
  SelectObject(hdc,h_00);
  DeleteObject(h);
  DeleteDC(hdc);
  return;
}



/* 000344b0 FUN_000344b0 */

/* Boundary evidence: original MIPS .pdata 000344b0..000345b7. Semantic name remains unreviewed. */

void FUN_000344b0(int param_1,HDC param_2)

{
  undefined4 uVar1;
  COLORREF CVar2;
  undefined8 uVar3;
  WCHAR aWStack_98 [64];
  uint local_18;
  
  local_18 = DAT_00055374;
  uVar1 = FUN_00026d78(DAT_00057130);
  if ((DAT_00057354 & 0x1800) == 0) {
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
  FUN_00033dd4(param_1,param_2,0xb,0x2e,CVar2,0,aWStack_98);
  FUN_00043604(local_18);
  return;
}



/* 000345b8 FUN_000345b8 */

/* Boundary evidence: original MIPS .pdata 000345b8..00034c47. Semantic name remains unreviewed. */

void FUN_000345b8(int param_1,int param_2,HDC param_3)

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
  
  local_30 = DAT_00055374;
  hdc = CreateCompatibleDC(param_3);
  local_154 = CreateCompatibleBitmap(param_3,800,0x1e0);
  local_158 = SelectObject(hdc,local_154);
  iVar8 = param_2 * 0x10;
  local_14c = (RECT *)(&DAT_00050e20 + iVar8);
  hbr = GetStockObject(4);
  FillRect(hdc,(RECT *)(&DAT_00050e20 + iVar8),hbr);
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
    goto LAB_00034740;
  case 4:
    iVar7 = *(int *)(param_1 + 0x5c);
LAB_00034740:
    iVar7 = 0x3a - (iVar7 * 0x3a) / 0x32;
    break;
  case 5:
    iVar5 = *(int *)(param_1 + 0x60) * 0x3a;
    iVar7 = iVar5 >> 4;
    if (iVar5 < 0) {
      iVar7 = iVar5 + 0xf >> 4;
    }
  }
  local_150 = (int *)(&DAT_00050e24 + iVar8);
  local_168.right = *(LONG *)(&DAT_00050e28 + iVar8);
  local_168.left = local_168.right + -0x12;
  local_168.top = *local_150 + 1;
  local_148 = (int *)(&DAT_00050e2c + iVar8);
  local_168.right = local_168.right + -5;
  local_168.bottom = *local_148 + -1;
  FUN_0003a114(param_1,hdc,&local_168,0xff);
  if (0 < iVar7) {
    if (local_168.top < local_168.bottom - iVar7) {
      local_168.top = local_168.bottom - iVar7;
    }
    FUN_0003a114(param_1,hdc,&local_168,0xff00);
  }
  SetBkMode(hdc,1);
  SetTextColor(hdc,0xb4b4b4);
  pHVar3 = FUN_0003a02c(0x10,0,0,0,0,'\0','\0','\0','\0','\0','\0','\x06','\x02',L"Tahoma");
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
  pHVar3 = FUN_0003a02c(0x24,0,0,0,0,'\0','\0','\0','\0','\0','\0','\x06','\x02',L"Tahoma");
  pvVar4 = SelectObject(hdc,pHVar3);
  wsprintfW(aWStack_b0,L"%3d",*(undefined4 *)((param_2 + 0x13) * 4 + param_1));
  DrawTextW(hdc,aWStack_b0,-1,lprc,8);
  SelectObject(hdc,pvVar4);
  DeleteObject(pHVar3);
  iVar5 = *local_150;
  iVar7 = lprc->left;
  BitBlt(param_3,iVar7,iVar5,*(int *)(&DAT_00050e28 + iVar8) - iVar7,*local_148 - iVar5,hdc,iVar7,
         iVar5,0xcc0020);
  SelectObject(hdc,local_158);
  DeleteObject(local_154);
  DeleteDC(hdc);
  FUN_00043604(local_30);
  return;
}



/* 00034c48 FUN_00034c48 */

/* Boundary evidence: original MIPS .pdata 00034c48..00034d57. Semantic name remains unreviewed. */

void FUN_00034c48(int param_1,int param_2,HDC param_3)

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
  
  local_18 = DAT_00055374;
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
  FUN_00033dd4(param_1,param_3,param_2 + 1,0x20,0xffffff,0,local_58 + param_2 * 8);
  FUN_00043604(local_18);
  return;
}



/* 00034d58 FUN_00034d58 */

/* Boundary evidence: original MIPS .pdata 00034d58..00034db7. Semantic name remains unreviewed. */

void FUN_00034d58(int param_1,HDC param_2)

{
  LPCWSTR pWVar1;
  
  if ((DAT_00057354 & 0x1800) == 0) {
    pWVar1 = L"FM";
  }
  else {
    pWVar1 = L"AM";
  }
  FUN_00033dd4(param_1,param_2,0,0x24,0xffffff,0,pWVar1);
  return;
}



/* 00034db8 FUN_00034db8 */

/* Boundary evidence: original MIPS .pdata 00034db8..00034e17. Semantic name remains unreviewed. */

void FUN_00034db8(int param_1,HDC param_2)

{
  COLORREF CVar1;
  
  if ((DAT_00057354 & 4) == 0) {
    CVar1 = 0x808080;
  }
  else {
    CVar1 = 0xffffff;
  }
  FUN_00033dd4(param_1,param_2,5,0x18,CVar1,0,L"AF");
  return;
}



/* 00034e18 FUN_00034e18 */

/* Boundary evidence: original MIPS .pdata 00034e18..00034e77. Semantic name remains unreviewed. */

void FUN_00034e18(int param_1,HDC param_2)

{
  COLORREF CVar1;
  
  if ((DAT_00057354 & 0x10) == 0) {
    CVar1 = 0x808080;
  }
  else {
    CVar1 = 0xffffff;
  }
  FUN_00033dd4(param_1,param_2,6,0x18,CVar1,0,L"RGN");
  return;
}



/* 00034e78 FUN_00034e78 */

/* Boundary evidence: original MIPS .pdata 00034e78..00034ed7. Semantic name remains unreviewed. */

void FUN_00034e78(int param_1,HDC param_2)

{
  COLORREF CVar1;
  
  if ((DAT_00057354 & 2) == 0) {
    CVar1 = 0x808080;
  }
  else {
    CVar1 = 0xffffff;
  }
  FUN_00033dd4(param_1,param_2,7,0x18,CVar1,0,L"RDS");
  return;
}



/* 00034ed8 FUN_00034ed8 */

/* Boundary evidence: original MIPS .pdata 00034ed8..00034f9b. Semantic name remains unreviewed. */

void FUN_00034ed8(int param_1,HDC param_2)

{
  undefined4 uVar1;
  undefined8 uVar2;
  WCHAR aWStack_98 [64];
  uint local_18;
  
  local_18 = DAT_00055374;
  uVar1 = __ultofp(*(undefined4 *)(param_1 + 0x78));
  uVar1 = __fpmul(uVar1,0x3951b717);
  uVar2 = __fptodp(uVar1);
  wsprintfW(aWStack_98,L"%5.2f",(int)uVar2,(int)((ulonglong)uVar2 >> 0x20));
  FUN_000341fc(param_1,param_2,10,0x18,0x26,0xb4b4b4,0xffffff,0,L"DIST(Km)",aWStack_98);
  FUN_00043604(local_18);
  return;
}



/* 00034f9c FUN_00034f9c */

/* Boundary evidence: original MIPS .pdata 00034f9c..0003509b. Semantic name remains unreviewed. */

void FUN_00034f9c(int param_1,HDC param_2)

{
  undefined2 uVar1;
  undefined2 extraout_var;
  undefined2 extraout_var_00;
  undefined2 extraout_var_01;
  char local_a8 [16];
  WCHAR aWStack_98 [64];
  uint local_18;
  
  local_18 = DAT_00055374;
  builtin_strncpy(local_a8,"--------",9);
  memset(local_a8 + 9,0,7);
  uVar1 = FUN_00026d80(DAT_00057130);
  if (CONCAT22(extraout_var,uVar1) != 0) {
    uVar1 = FUN_00026d80(DAT_00057130);
    FUN_0002e27c(DAT_00057348,CONCAT22(extraout_var_00,uVar1),(undefined4 *)local_a8);
  }
  uVar1 = FUN_00026d80(DAT_00057130);
  wsprintfW(aWStack_98,L"%04X(%S)",CONCAT22(extraout_var_01,uVar1),local_a8);
  FUN_00033dd4(param_1,param_2,0xc,0x20,0xffffff,0,aWStack_98);
  FUN_00043604(local_18);
  return;
}



/* 0003509c FUN_0003509c */

/* Boundary evidence: original MIPS .pdata 0003509c..0003574b. Semantic name remains unreviewed. */

void FUN_0003509c(int param_1,HDC param_2)

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
  
  local_18 = DAT_00055374;
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
  wsprintfW((LPWSTR)(auStack_9d + 5),L"%S",(int)&local_1b8 + *(int *)(param_1 + 0x74) * 9);
  FUN_00033dd4(param_1,param_2,0xd,0x20,0xffffff,0,(LPCWSTR)(auStack_9d + 5));
  FUN_00043604(local_18);
  return;
}



/* 0003574c FUN_0003574c */

/* Boundary evidence: original MIPS .pdata 0003574c..0003583b. Semantic name remains unreviewed. */

void FUN_0003574c(int param_1,HDC param_2)

{
  byte bVar1;
  WCHAR aWStack_218 [256];
  uint local_18;
  
  local_18 = DAT_00055374;
  bVar1 = *(byte *)(param_1 + 0x70);
  wsprintfW(aWStack_218,L"%d/%d/%d/%d",(uint)((bVar1 & 1) != 0),(uint)((bVar1 & 2) != 0),
            (uint)((bVar1 & 4) != 0),(uint)((bVar1 & 8) != 0));
  FUN_000341fc(param_1,param_2,0xe,0xe,0x18,0xb4b4b4,0xffffff,0,L"TP/TA/ETP/ETA",aWStack_218);
  FUN_00043604(local_18);
  return;
}



/* 0003583c FUN_0003583c */

/* Boundary evidence: original MIPS .pdata 0003583c..00035d87. Semantic name remains unreviewed. */

void FUN_0003583c(int param_1,HDC param_2)

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
  
  local_30 = DAT_00055374;
  hdc = CreateCompatibleDC(param_2);
  h = CreateCompatibleBitmap(param_2,800,0x1e0);
  h_00 = SelectObject(hdc,h);
  h_01 = FUN_0003a02c(0x10,0,0,0,0,'\0','\0','\0','\0','\0','\0','\x06','\x02',L"Tahoma");
  h_02 = SelectObject(hdc,h_01);
  lprc = (LPRECT)&DAT_00050ec0;
  piVar4 = (int *)(param_1 + 0x88);
  iVar1 = 0;
  do {
    iVar3 = iVar1;
    if ((*piVar4 == 0) || (0x1f < iVar3)) {
      FUN_00033dd4(param_1,hdc,iVar3 + 0x1a,0x16,
                   ((uint)(piVar4[0x20] * 0x96) / 100 + 100 & 0xff) << 8 | 0x640064,0,L"-");
    }
    else {
      uVar2 = __ultofp();
      uVar2 = __fpmul(uVar2,0x3a83126f);
      uVar5 = __fptodp(uVar2);
      wsprintfW(aWStack_b0,L"%4.1f",(int)uVar5,(int)((ulonglong)uVar5 >> 0x20));
      FUN_00033dd4(param_1,hdc,iVar3 + 0x1a,0x16,
                   ((uint)(piVar4[0x20] * 0x96) / 100 + 100 & 0xff) << 8 | 0x640064,0,aWStack_b0);
      SetBkMode(hdc,1);
      SetTextColor(hdc,0x808080);
      wsprintfW(aWStack_b0,L"%d",piVar4[0x20]);
      DrawTextW(hdc,aWStack_b0,-1,lprc,9);
    }
    lprc = lprc + 1;
    piVar4 = piVar4 + 1;
    iVar1 = iVar3 + 1;
  } while ((int)lprc < 0x510b0);
  if ((*(int *)((*(int *)(param_1 + 0x198) + 0x41) * 4 + param_1) == 0) ||
     (0x1f < *(int *)(param_1 + 0x198) + 0x1fU)) {
    FUN_00033dd4(param_1,hdc,0x39,0x16,
                 ((uint)(*(int *)((iVar3 + 0x43) * 4 + param_1) * 0x96) / 100 + 100 & 0xff) << 8 |
                 0x640064,0,L"-");
  }
  else {
    uVar2 = __ultofp();
    uVar2 = __fpmul(uVar2,0x3a83126f);
    uVar5 = __fptodp(uVar2);
    wsprintfW(aWStack_b0,L"%4.1f",(int)uVar5,(int)((ulonglong)uVar5 >> 0x20));
    FUN_00033dd4(param_1,hdc,0x39,0x16,
                 ((uint)(*(int *)((iVar3 + 0x43) * 4 + param_1) * 0x96) / 100 + 100 & 0xff) << 8 |
                 0x640064,0,aWStack_b0);
  }
  SetBkMode(hdc,1);
  SetTextColor(hdc,0xb4b4b4);
  wsprintfW(aWStack_b0,L"%d(%d)",*(int *)(param_1 + 0x198) + 0x20,(uint)*(byte *)(param_1 + 0x12));
  DrawTextW(hdc,aWStack_b0,-1,(LPRECT)&DAT_000510b0,9);
  SelectObject(hdc,h_02);
  DeleteObject(h_01);
  uVar2 = __ultofp(*(undefined4 *)(param_1 + 0x44));
  uVar2 = __fpmul(uVar2,0x3a83126f);
  uVar5 = __fptodp(uVar2);
  wsprintfW(aWStack_b0,L"%4.1f",(int)uVar5,(int)((ulonglong)uVar5 >> 0x20));
  FUN_00033dd4(param_1,hdc,0xf,0x1e,0xc8c8c8,0,aWStack_b0);
  BitBlt(param_2,0,0xb4,800,0x5a,hdc,0,0xb4,0xcc0020);
  BitBlt(param_2,700,0x3c,100,0x3c,hdc,700,0x3c,0xcc0020);
  SelectObject(hdc,h_00);
  DeleteObject(h);
  DeleteDC(hdc);
  FUN_00043604(local_30);
  return;
}



/* 00035d88 FUN_00035d88 */

/* Boundary evidence: original MIPS .pdata 00035d88..00035e7b. Semantic name remains unreviewed. */

void FUN_00035d88(int param_1,HDC param_2)

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
    FUN_000345b8(param_1,iVar1,hdc);
    iVar1 = iVar1 + 1;
  } while (iVar1 < 9);
  BitBlt(param_2,0,0x78,0x276,0x3c,hdc,0,0x78,0xcc0020);
  SelectObject(hdc,h_00);
  DeleteObject(h);
  DeleteDC(hdc);
  return;
}



/* 00035e7c FUN_00035e7c */

/* Boundary evidence: original MIPS .pdata 00035e7c..00035ff7. Semantic name remains unreviewed. */

void FUN_00035e7c(int param_1,int param_2,HDC param_3)

{
  wchar_t *pwVar1;
  WCHAR aWStack_118 [64];
  WCHAR aWStack_98 [64];
  uint local_18;
  
  local_18 = DAT_00055374;
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
    goto switchD_00035ecc_default;
  }
  wsprintfW(aWStack_118,pwVar1);
switchD_00035ecc_default:
  wsprintfW(aWStack_98,L"%d",(uint)*(byte *)(param_2 + param_1 + 0x188));
  FUN_000341fc(param_1,param_3,param_2 + 0x3a,0xc,0x1c,0xb4b4b4,0xffffff,0,aWStack_118,aWStack_98);
  FUN_00043604(local_18);
  return;
}



/* 00035ff8 FUN_00035ff8 */

/* Boundary evidence: original MIPS .pdata 00035ff8..000360eb. Semantic name remains unreviewed. */

void FUN_00035ff8(int param_1,HDC param_2)

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
    FUN_00035e7c(param_1,iVar1,hdc);
    iVar1 = iVar1 + 1;
  } while (iVar1 < 0xb);
  BitBlt(param_2,0,0x118,0x226,0x28,hdc,0,0x118,0xcc0020);
  SelectObject(hdc,h_00);
  DeleteObject(h);
  DeleteDC(hdc);
  return;
}



/* 000360ec FUN_000360ec */

/* Boundary evidence: original MIPS .pdata 000360ec..00036183. Semantic name remains unreviewed. */

void FUN_000360ec(int param_1,HDC param_2)

{
  int iVar1;
  WCHAR aWStack_218 [256];
  uint local_18;
  
  local_18 = DAT_00055374;
  iVar1 = *(int *)(param_1 + 0x1a4);
  if (-1 < iVar1) {
    wsprintfW(aWStack_218,L"%d : %S",iVar1,iVar1 * 0x80 + param_1 + 0x1ad);
    FUN_00033fe8(param_1,param_2,0x45,0x18,0xb4b4b4,0,aWStack_218);
  }
  FUN_00043604(local_18);
  return;
}



/* 00036184 FUN_00036184 */

/* Boundary evidence: original MIPS .pdata 00036184..000361df. Semantic name remains unreviewed. */

void FUN_00036184(int param_1,HDC param_2)

{
  FUN_000341fc(param_1,param_2,0x46,0xc,0x1a,0xb4b4b4,0xffffff,0,L"STATION",L"ERASE");
  return;
}



/* 000361e0 FUN_000361e0 */

/* Boundary evidence: original MIPS .pdata 000361e0..0003623b. Semantic name remains unreviewed. */

void FUN_000361e0(int param_1,HDC param_2)

{
  FUN_000341fc(param_1,param_2,0x47,0xc,0x1a,0xb4b4b4,0xffffff,0,L"STATION",L"SAVE");
  return;
}



/* 0003623c FUN_0003623c */

/* Boundary evidence: original MIPS .pdata 0003623c..000362af. Semantic name remains unreviewed. */

void FUN_0003623c(int param_1,HDC param_2)

{
  COLORREF CVar1;
  
  if (*(int *)(param_1 + 0x40) == 1) {
    CVar1 = 0xff00;
  }
  else {
    CVar1 = 0xffffff;
  }
  FUN_000341fc(param_1,param_2,0x4b,0xc,0x1a,0xb4b4b4,CVar1,0,L"LOG",L"QUAL");
  return;
}



/* 000362b0 FUN_000362b0 */

/* Boundary evidence: original MIPS .pdata 000362b0..00036323. Semantic name remains unreviewed. */

void FUN_000362b0(int param_1,HDC param_2)

{
  COLORREF CVar1;
  
  if (*(int *)(param_1 + 0x40) == 1) {
    CVar1 = 0xff00;
  }
  else {
    CVar1 = 0xffffff;
  }
  FUN_000341fc(param_1,param_2,0x4c,0xc,0x1a,0xb4b4b4,CVar1,0,L"LOG",L"EVENT");
  return;
}



/* 00036324 FUN_00036324 */

/* Boundary evidence: original MIPS .pdata 00036324..00036427. Semantic name remains unreviewed. */

void FUN_00036324(int param_1,HDC param_2)

{
  FUN_000341fc(param_1,param_2,0x48,0xc,0x1a,0xb4b4b4,0xffffff,0,L"PARAM",L"APPLY");
  FUN_000341fc(param_1,param_2,0x49,0xc,0x1a,0xb4b4b4,0xffffff,0,L"PARAM",L"SAVE");
  FUN_000341fc(param_1,param_2,0x4a,0xc,0x1a,0xb4b4b4,0xffffff,0,L"PARAM",L"RESET");
  return;
}



/* 00036428 FUN_00036428 */

/* Boundary evidence: original MIPS .pdata 00036428..0003649f. Semantic name remains unreviewed. */

void FUN_00036428(int param_1,HDC param_2)

{
  wchar_t *pwVar1;
  
  if (*(int *)(param_1 + 0x80) == 1) {
    pwVar1 = L"MICOM";
  }
  else {
    pwVar1 = L"PC";
  }
  FUN_000341fc(param_1,param_2,0x4d,0xc,0x1a,0xb4b4b4,0xffffff,0,L"GUI SELECT",pwVar1);
  return;
}



/* 000364a0 FUN_000364a0 */

/* Boundary evidence: original MIPS .pdata 000364a0..00036517. Semantic name remains unreviewed. */

void FUN_000364a0(int param_1,HDC param_2)

{
  LPCWSTR pWVar1;
  
  if (*(int *)(param_1 + 0x84) == 1) {
    pWVar1 = L"ON";
  }
  else {
    pWVar1 = L"OFF";
  }
  FUN_000341fc(param_1,param_2,0x4e,0xc,0x1a,0xb4b4b4,0xffffff,0,L"TUNER FREQ",pWVar1);
  return;
}



/* 00036518 FUN_00036518 */

/* Boundary evidence: original MIPS .pdata 00036518..000365db. Semantic name remains unreviewed. */

void FUN_00036518(int param_1,HDC param_2)

{
  WCHAR aWStack_218 [256];
  uint local_18;
  
  local_18 = DAT_00055374;
  wsprintfW(aWStack_218,L"%d/%d/%d/%d/(%d)",(uint)*(byte *)(param_1 + 0x1a8),
            (uint)*(byte *)(param_1 + 0x1a9),(uint)*(byte *)(param_1 + 0x1aa),
            (uint)*(byte *)(param_1 + 0x1ab),(uint)*(byte *)(param_1 + 0x1ac));
  FUN_000341fc(param_1,param_2,0x19,0x10,0x1c,0xb4b4b4,0xffffff,0,L"RIATT/RGATT/MFATT/IFATT",
               aWStack_218);
  FUN_00043604(local_18);
  return;
}



/* 000365dc FUN_000365dc */

/* Boundary evidence: original MIPS .pdata 000365dc..00036893. Semantic name remains unreviewed. */

void FUN_000365dc(int param_1,HDC param_2)

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
  FUN_0003a114(param_1,hdc,&local_30,0);
  FUN_00034d58(param_1,hdc);
  FUN_00034c48(param_1,0,hdc);
  FUN_00034c48(param_1,1,hdc);
  FUN_00034c48(param_1,2,hdc);
  FUN_00034c48(param_1,3,hdc);
  FUN_00034db8(param_1,hdc);
  FUN_00034e18(param_1,hdc);
  FUN_00034e78(param_1,hdc);
  FUN_00033dd4(param_1,hdc,8,0x18,0xffffff,0,L"PST1");
  FUN_00033dd4(param_1,hdc,9,0x18,0xffffff,0,L"VOL");
  FUN_00034ed8(param_1,hdc);
  FUN_000344b0(param_1,hdc);
  FUN_00034f9c(param_1,hdc);
  FUN_0003509c(param_1,hdc);
  FUN_0003574c(param_1,hdc);
  FUN_00035d88(param_1,hdc);
  FUN_00036518(param_1,hdc);
  FUN_0003583c(param_1,hdc);
  FUN_00035ff8(param_1,hdc);
  FUN_000360ec(param_1,hdc);
  FUN_00036184(param_1,hdc);
  FUN_000361e0(param_1,hdc);
  FUN_00036324(param_1,hdc);
  FUN_0003623c(param_1,hdc);
  FUN_000362b0(param_1,hdc);
  FUN_00036428(param_1,hdc);
  FUN_000364a0(param_1,hdc);
  FUN_00033dd4(param_1,hdc,0x4f,0x20,0xffffff,0,L"EXIT");
  BitBlt(param_2,0,0,800,0x1e0,hdc,0,0,0xcc0020);
  SelectObject(hdc,h_00);
  DeleteObject(h);
  DeleteDC(hdc);
  return;
}



/* 00036894 FUN_00036894 */

void FUN_00036894(undefined4 param_1,int param_2,int param_3)

{
  uint uVar1;
  int *piVar2;
  
  uVar1 = 0;
  piVar2 = &DAT_00050d20;
  while ((((param_2 <= *piVar2 || (piVar2[2] <= param_2)) || (param_3 <= piVar2[1])) ||
         (piVar2[3] <= param_3))) {
    uVar1 = uVar1 + 1;
    piVar2 = piVar2 + 4;
    if (0x4f < uVar1) {
      return;
    }
  }
  return;
}



/* 00036900 FUN_00036900 */

/* Boundary evidence: original MIPS .pdata 00036900..00036a17. Semantic name remains unreviewed. */

void FUN_00036900(int param_1)

{
  HDC pHVar1;
  uint uVar2;
  
  uVar2 = *(uint *)(param_1 + 0x194);
  if (uVar2 == 9) {
    FUN_00012334(DAT_00055384,3);
  }
  else if (uVar2 == 0x45) {
    if (0 < *(int *)(param_1 + 0x1a4)) {
      *(int *)(param_1 + 0x1a4) = *(int *)(param_1 + 0x1a4) + -1;
      pHVar1 = GetDC(*(HWND *)(param_1 + 0xc));
      FUN_000360ec(param_1,pHVar1);
      ReleaseDC(*(HWND *)(param_1 + 0xc),pHVar1);
    }
  }
  else if ((0x39 < uVar2) && (uVar2 < 0x45)) {
    *(char *)(uVar2 + param_1 + 0x14e) = *(char *)(uVar2 + param_1 + 0x14e) + -1;
    pHVar1 = GetDC(*(HWND *)(param_1 + 0xc));
    FUN_00035e7c(param_1,*(int *)(param_1 + 0x194) + -0x3a,pHVar1);
    ReleaseDC(*(HWND *)(param_1 + 0xc),pHVar1);
    FUN_00015b90(DAT_000553cc,3,0xc0,param_1 + 0x188,0xb,0x32);
  }
  return;
}



/* 00036a18 FUN_00036a18 */

/* Boundary evidence: original MIPS .pdata 00036a18..00036b33. Semantic name remains unreviewed. */

void FUN_00036a18(int param_1)

{
  HDC pHVar1;
  uint uVar2;
  
  uVar2 = *(uint *)(param_1 + 0x194);
  if (uVar2 == 9) {
    FUN_00012334(DAT_00055384,2);
  }
  else if (uVar2 == 0x45) {
    if (*(int *)(param_1 + 0x1a4) < 0xf) {
      *(int *)(param_1 + 0x1a4) = *(int *)(param_1 + 0x1a4) + 1;
      pHVar1 = GetDC(*(HWND *)(param_1 + 0xc));
      FUN_000360ec(param_1,pHVar1);
      ReleaseDC(*(HWND *)(param_1 + 0xc),pHVar1);
    }
  }
  else if ((0x39 < uVar2) && (uVar2 < 0x45)) {
    *(char *)(uVar2 + param_1 + 0x14e) = *(char *)(uVar2 + param_1 + 0x14e) + '\x01';
    pHVar1 = GetDC(*(HWND *)(param_1 + 0xc));
    FUN_00035e7c(param_1,*(int *)(param_1 + 0x194) + -0x3a,pHVar1);
    ReleaseDC(*(HWND *)(param_1 + 0xc),pHVar1);
    FUN_00015b90(DAT_000553cc,3,0xc0,param_1 + 0x188,0xb,0x32);
  }
  return;
}



/* 00036b34 FUN_00036b34 */

/* Boundary evidence: original MIPS .pdata 00036b34..00036bb3. Semantic name remains unreviewed. */

void FUN_00036b34(undefined4 param_1)

{
  undefined4 *puVar1;
  
  FUN_0003ea24();
  puVar1 = (undefined4 *)__2_YAPAXI_Z(0x9b0);
  if (puVar1 == (undefined4 *)0x0) {
    DAT_00059384 = (undefined4 *)0x0;
  }
  else {
    DAT_00059384 = FUN_00033bbc(puVar1);
  }
  FUN_0003e4e0((int)DAT_00059384,DAT_00055600,param_1);
  return;
}



/* 00036bb4 Unwind@00036bb4 */

/* Boundary evidence: original MIPS .pdata 00036bb4..00036be3. Semantic name remains unreviewed. */

void Unwind_00036bb4(void)

{
  int in_v0;
  
  __3_YAXPAX_Z(*(undefined4 *)(in_v0 + -0x18));
  return;
}



/* 00036be4 FUN_00036be4 */

/* Boundary evidence: original MIPS .pdata 00036be4..00036c3b. Semantic name remains unreviewed. */

undefined4 * FUN_00036be4(undefined4 *param_1,uint param_2)

{
  *param_1 = &PTR_FUN_00051230;
  FUN_0003e4d0(param_1);
  if ((param_2 & 1) != 0) {
    __3_YAXPAX_Z(param_1);
  }
  return param_1;
}



/* 00036c3c FUN_00036c3c */

/* Boundary evidence: original MIPS .pdata 00036c3c..00036d67. Semantic name remains unreviewed. */

void FUN_00036c3c(int param_1)

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
    uVar1 = FUN_00016068(DAT_000553cc,3,3,(void *)(param_1 + 0x10),0x24,300);
    if (uVar1 == 0x24) break;
    uVar6 = uVar6 + 1;
  } while (uVar6 < 3);
  if (uVar6 < 3) {
    hDC = GetDC(*(HWND *)(param_1 + 0xc));
    piVar5 = (int *)(param_1 + 0x88);
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
    FUN_0003583c(param_1,hDC);
    ReleaseDC(*(HWND *)(param_1 + 0xc),hDC);
  }
  return;
}



/* 00036d68 FUN_00036d68 */

/* Boundary evidence: original MIPS .pdata 00036d68..0003769b. Semantic name remains unreviewed. */

void FUN_00036d68(int param_1,UINT_PTR param_2)

{
  uint uVar1;
  HDC pHVar2;
  byte *pbVar3;
  int iVar4;
  uint *puVar5;
  int iVar6;
  byte local_78;
  byte local_77;
  byte local_76;
  char local_74;
  byte local_73;
  byte local_72;
  char local_71;
  byte local_70;
  byte local_6f;
  ushort local_6c [2];
  RECT local_68;
  short local_58;
  short local_56;
  short local_54;
  short local_52;
  short local_50;
  byte local_48 [32];
  uint local_28;
  
  local_28 = DAT_00055374;
  switch(param_2) {
  case 100:
    FUN_0003e8b8(param_1,param_2);
    FUN_00036c3c(param_1);
    goto switchD_00036dc4_default;
  case 0x65:
    if (*(int *)(param_1 + 0x80) == 1) {
      uVar1 = FUN_00016068(DAT_000553cc,3,0xd0,&local_58,10,100);
      if (uVar1 == 10) {
        *(int *)(param_1 + 0x4c) = (int)local_50;
        *(int *)(param_1 + 0x50) = (int)local_58 / 0x147;
        *(int *)(param_1 + 0x54) = (int)local_56 / 200;
        if ((DAT_00057354 & 0x1800) == 0) {
          *(int *)(param_1 + 0x58) = (int)local_54 / 0x147;
        }
        else {
          *(int *)(param_1 + 0x58) = (int)local_54;
        }
        *(int *)(param_1 + 0x5c) = (int)local_52 / 0x147;
      }
      if ((DAT_00057354 & 0x1800) != 0) {
        uVar1 = FUN_00016068(DAT_000553cc,2,0x100ce,&local_70,3,100);
        if (uVar1 == 3) {
          *(int *)(param_1 + 100) =
               (int)((int)((uint)local_70 << 0x18) >> 0x10 | (uint)local_6f) / 0x148;
        }
        *(undefined4 *)(param_1 + 0x68) = 0;
        *(undefined4 *)(param_1 + 0x6c) = 0;
        goto LAB_0003708c;
      }
      uVar1 = FUN_00016068(DAT_000553cc,2,0x10070,&local_78,3,100);
      if (uVar1 == 3) {
        *(uint *)(param_1 + 0x60) = (uint)local_76;
      }
      uVar1 = FUN_00016068(DAT_000553cc,2,0x31030,&local_78,2,100);
      if (uVar1 == 2) {
        iVar4 = ((int)((uint)local_78 << 0x18) >> 0x10 | (uint)local_77) * 100;
        iVar6 = iVar4 + 0x3ff;
        if (iVar6 < 0) {
          iVar6 = iVar4 + 0xbfe;
        }
        *(int *)(param_1 + 100) = iVar6 >> 0xb;
      }
      uVar1 = FUN_00016068(DAT_000553cc,2,0x3102b,&local_78,2,100);
      if (uVar1 == 2) {
        iVar4 = ((int)((uint)local_78 << 0x18) >> 0x10 | (uint)local_77) * 100;
        iVar6 = iVar4 + 0x3ff;
        if (iVar6 < 0) {
          iVar6 = iVar4 + 0xbfe;
        }
        *(int *)(param_1 + 0x68) = iVar6 >> 0xb;
      }
      uVar1 = FUN_00016068(DAT_000553cc,2,0x31020,&local_78,2,100);
      if (uVar1 == 2) {
        iVar4 = ((int)((uint)local_78 << 0x18) >> 0x10 | (uint)local_77) * 100;
        iVar6 = iVar4 + 0x3ff;
        if (iVar6 < 0) {
          iVar6 = iVar4 + 0xbfe;
        }
        *(int *)(param_1 + 0x6c) = iVar6 >> 0xb;
      }
    }
    else {
      *(undefined4 *)(param_1 + 0x4c) = 0;
      *(undefined4 *)(param_1 + 0x50) = 0;
      *(undefined4 *)(param_1 + 0x54) = 0;
      *(undefined4 *)(param_1 + 0x58) = 0;
      *(undefined4 *)(param_1 + 0x5c) = 0;
      *(undefined4 *)(param_1 + 100) = 0;
LAB_0003708c:
      *(undefined4 *)(param_1 + 0x60) = 0;
    }
    uVar1 = FUN_00016068(DAT_000553cc,9,5,local_6c,2,100);
    if (uVar1 == 2) {
      *(uint *)(param_1 + 0x78) =
           ((uint)local_6c[0] - (uint)*(ushort *)(param_1 + 0x7c) & 0xffff) +
           *(int *)(param_1 + 0x78);
      *(ushort *)(param_1 + 0x7c) = local_6c[0];
    }
    pHVar2 = GetDC(*(HWND *)(param_1 + 0xc));
    if (*(int *)(param_1 + 0x80) == 1) {
      FUN_00035d88(param_1,pHVar2);
    }
    FUN_00034ed8(param_1,pHVar2);
    ReleaseDC(*(HWND *)(param_1 + 0xc),pHVar2);
    if (*(int *)(param_1 + 0x34) != 0) {
      uVar1 = FUN_00026d78(DAT_00057130);
      fprintf(*(FILE **)(param_1 + 0x34),"%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
              *(uint *)(param_1 + 0x78) / 5,uVar1 / 100,*(undefined4 *)(param_1 + 0x4c),
              *(undefined4 *)(param_1 + 0x50),*(undefined4 *)(param_1 + 0x54),
              *(undefined4 *)(param_1 + 0x58),*(undefined4 *)(param_1 + 0x5c),
              *(undefined4 *)(param_1 + 0x60));
    }
    goto switchD_00036dc4_default;
  case 0x66:
    if ((DAT_00057354 & 0x1800) != 0) goto switchD_00036dc4_default;
    uVar1 = FUN_00016068(DAT_000553cc,3,0xd1,local_48,0x20,100);
    if (uVar1 == 0x20) {
      iVar4 = 0;
      puVar5 = (uint *)(param_1 + 0x108);
      do {
        pbVar3 = local_48 + iVar4;
        iVar4 = iVar4 + 1;
        *puVar5 = (uint)*pbVar3;
        puVar5 = puVar5 + 1;
      } while (iVar4 < 0x20);
    }
    FUN_00016068(DAT_000553cc,3,0x12,(void *)(param_1 + 0x44),4,100);
    pHVar2 = GetDC(*(HWND *)(param_1 + 0xc));
    FUN_0003583c(param_1,pHVar2);
    break;
  case 0x67:
    uVar1 = FUN_00016068(DAT_000553cc,3,0xd3,(void *)(param_1 + 0x48),1,100);
    if (uVar1 != 1) goto switchD_00036dc4_default;
    pHVar2 = GetDC(*(HWND *)(param_1 + 0xc));
    FUN_000344b0(param_1,pHVar2);
    break;
  case 0x68:
    FUN_0003e8b8(param_1,0x68);
    *(undefined4 *)(param_1 + 0x19c) = 0x50;
    local_68.left = 0;
    local_68.top = 0;
    local_68.right = 800;
    local_68.bottom = 0x1e0;
    InvalidateRect(*(HWND *)(param_1 + 0xc),&local_68,0);
    goto switchD_00036dc4_default;
  case 0x69:
    FUN_0003e8b8(param_1,0x69);
    FUN_00015f10(DAT_000553cc,3,1,0xe1,0,0,1000);
    FUN_00015f10(DAT_000553cc,3,1,0xe0,0,0,1000);
    FUN_00015f10(DAT_000553cc,3,1,0xe2,0,0,100);
    FUN_00016068(DAT_000553cc,3,0xc0,(void *)(param_1 + 0x188),0xb,0x32);
    goto LAB_0003736c;
  case 0x6a:
    FUN_0003e8b8(param_1,0x6a);
    FUN_00015f10(DAT_000553cc,3,1,0xe0,0,0,1000);
    FUN_00015f10(DAT_000553cc,3,1,0xe2,0,0,100);
    FUN_00016068(DAT_000553cc,3,0xc0,(void *)(param_1 + 0x188),0xb,0x32);
LAB_0003736c:
    pHVar2 = GetDC(*(HWND *)(param_1 + 0xc));
    FUN_00035e7c(param_1,0,pHVar2);
    FUN_00035e7c(param_1,1,pHVar2);
    FUN_00035e7c(param_1,2,pHVar2);
    FUN_00035e7c(param_1,3,pHVar2);
    FUN_00035e7c(param_1,4,pHVar2);
    FUN_00035e7c(param_1,5,pHVar2);
    FUN_00035e7c(param_1,6,pHVar2);
    FUN_00035e7c(param_1,7,pHVar2);
    FUN_00035e7c(param_1,8,pHVar2);
    break;
  case 0x6b:
    if ((*(int *)(param_1 + 0x34) == 0) && (*(int *)(param_1 + 0x38) == 0))
    goto switchD_00036dc4_default;
    *(uint *)(param_1 + 0x40) = (uint)(*(int *)(param_1 + 0x40) == 0);
    pHVar2 = GetDC(*(HWND *)(param_1 + 0xc));
    if (*(int *)(param_1 + 0x34) != 0) {
      FUN_0003623c(param_1,pHVar2);
    }
    if (*(int *)(param_1 + 0x38) != 0) {
      FUN_000362b0(param_1,pHVar2);
    }
    break;
  case 0x6c:
    uVar1 = FUN_00016068(DAT_000553cc,2,0x10000c0,&local_74,3,100);
    if (uVar1 == 3) {
      *(byte *)(param_1 + 0x1a8) = local_72 >> 5;
      *(char *)(param_1 + 0x1a9) = (char)((local_72 & 0x1c) >> 2);
      *(byte *)(param_1 + 0x1aa) = local_72 & 1;
      *(char *)(param_1 + 0x1ab) = (char)((local_73 & 0xc) >> 2);
      pHVar2 = GetDC(*(HWND *)(param_1 + 0xc));
      FUN_00036518(param_1,pHVar2);
      ReleaseDC(*(HWND *)(param_1 + 0xc),pHVar2);
    }
    uVar1 = FUN_00016068(DAT_000553cc,2,0x312a0,&local_74,2,100);
    if (uVar1 == 2) {
      if ((local_74 == '\0') && (local_73 == 0)) {
        *(undefined1 *)(param_1 + 0x1ac) = 0;
      }
      else if ((local_74 == '\a') && (local_73 == 0xff)) {
        *(undefined1 *)(param_1 + 0x1ac) = 1;
      }
      else {
        *(undefined1 *)(param_1 + 0x1ac) = 2;
      }
    }
    goto switchD_00036dc4_default;
  case 0x6d:
    uVar1 = FUN_00016068(DAT_000553cc,4,0x40,&local_71,1,100);
    if ((uVar1 != 1) || (local_71 == *(char *)(param_1 + 0x70))) goto switchD_00036dc4_default;
    *(char *)(param_1 + 0x70) = local_71;
    pHVar2 = GetDC(*(HWND *)(param_1 + 0xc));
    FUN_0003574c(param_1,pHVar2);
    break;
  default:
    goto switchD_00036dc4_default;
  }
  ReleaseDC(*(HWND *)(param_1 + 0xc),pHVar2);
switchD_00036dc4_default:
  FUN_00043604(local_28);
  return;
}



/* 0003769c FUN_0003769c */

/* Boundary evidence: original MIPS .pdata 0003769c..00037c8b. Semantic name remains unreviewed. */

void FUN_0003769c(int param_1,int param_2,undefined4 param_3)

{
  undefined4 uVar1;
  HDC pHVar2;
  int iVar3;
  char *pcVar4;
  
  if (param_2 == 0) {
    pHVar2 = GetDC(*(HWND *)(param_1 + 0xc));
    FUN_000344b0(param_1,pHVar2);
    ReleaseDC(*(HWND *)(param_1 + 0xc),pHVar2);
    FUN_0003e89c(param_1,100,1000,(TIMERPROC)0x0);
  }
  else {
    if (param_2 == 5) {
      pHVar2 = GetDC(*(HWND *)(param_1 + 0xc));
      FUN_00034f9c(param_1,pHVar2);
    }
    else if (param_2 == 6) {
      *(undefined4 *)(param_1 + 0x74) = param_3;
      pHVar2 = GetDC(*(HWND *)(param_1 + 0xc));
      FUN_0003509c(param_1,pHVar2);
    }
    else {
      if (param_2 != 0xb) {
        return;
      }
      iVar3 = *(int *)(param_1 + 0x1a0) + 1;
      *(int *)(param_1 + 0x1a0) = iVar3;
      if (0xf < iVar3) {
        iVar3 = 0xf;
        pcVar4 = (char *)(param_1 + 0x1ad);
        do {
          strcpy_s(pcVar4,0x80,pcVar4 + 0x80);
          iVar3 = iVar3 + -1;
          pcVar4 = pcVar4 + 0x80;
        } while (iVar3 != 0);
        *(int *)(param_1 + 0x1a0) = *(int *)(param_1 + 0x1a0) + -1;
      }
      pcVar4 = (char *)(*(int *)(param_1 + 0x1a0) * 0x80 + param_1 + 0x1ad);
      switch(*(undefined1 *)(DAT_00057130 + 0x3a)) {
      case 0:
        uVar1 = __ultofp(*(undefined4 *)(param_1 + 0x78));
        uVar1 = __fpmul(uVar1,0x3951b717);
        __fptodp(uVar1);
        sprintf_s(pcVar4,0x80,"%4.2f : %sAF Jump(without PI check) Success - from %d(%d) to %d(%d)")
        ;
        break;
      case 1:
        uVar1 = __ultofp(*(undefined4 *)(param_1 + 0x78));
        uVar1 = __fpmul(uVar1,0x3951b717);
        __fptodp(uVar1);
        sprintf_s(pcVar4,0x80,"%4.2f : %sAF Jump(with PI check) Success - %d(%d) -> %d(%d)");
        break;
      case 2:
        uVar1 = __ultofp(*(undefined4 *)(param_1 + 0x78));
        uVar1 = __fpmul(uVar1,0x3951b717);
        __fptodp(uVar1);
        sprintf_s(pcVar4,0x80,"%4.2f : AF Jump Success(Old Recent Freq) - %d(%d) -> %d(%d)");
        break;
      case 3:
        uVar1 = __ultofp(*(undefined4 *)(param_1 + 0x78));
        uVar1 = __fpmul(uVar1,0x3951b717);
        __fptodp(uVar1);
        sprintf_s(pcVar4,0x80,"%4.2f : AF Jump Fail(PI Check error) - %d(%d) -> %d(%d)");
        break;
      case 4:
        uVar1 = __ultofp(*(undefined4 *)(param_1 + 0x78));
        uVar1 = __fpmul(uVar1,0x3951b717);
        __fptodp(uVar1);
        sprintf_s(pcVar4,0x80,"%4.2f : AF Jump Fail(Wrong PI) - %d(%d) -> %d(%d)");
        break;
      case 5:
        uVar1 = __ultofp(*(undefined4 *)(param_1 + 0x78));
        uVar1 = __fpmul(uVar1,0x3951b717);
        __fptodp(uVar1);
        sprintf_s(pcVar4,0x80,
                  "%4.2f : Emergency AF Jump Success(Old Recent Freq) - %d(%d) -> %d(%d)");
        break;
      case 6:
        uVar1 = __ultofp(*(undefined4 *)(param_1 + 0x78));
        uVar1 = __fpmul(uVar1,0x3951b717);
        __fptodp(uVar1);
        sprintf_s(pcVar4,0x80,"%4.2f : PI(Regional) changed - %04X -> %04X");
        break;
      case 7:
        uVar1 = __ultofp(*(undefined4 *)(param_1 + 0x78));
        uVar1 = __fpmul(uVar1,0x3951b717);
        __fptodp(uVar1);
        sprintf_s(pcVar4,0x80,"%4.2f : PI(Wrong) changed - %04X -> %04X");
        break;
      case 8:
        uVar1 = __ultofp(*(undefined4 *)(param_1 + 0x78));
        uVar1 = __fpmul(uVar1,0x3951b717);
        __fptodp(uVar1);
        sprintf_s(pcVar4,0x80,"%4.2f : Return to Last Freq - %d -> %d");
      }
      if (*(FILE **)(param_1 + 0x38) != (FILE *)0x0) {
        fprintf(*(FILE **)(param_1 + 0x38),"%s\n",pcVar4);
      }
      *(undefined4 *)(param_1 + 0x1a4) = *(undefined4 *)(param_1 + 0x1a0);
      pHVar2 = GetDC(*(HWND *)(param_1 + 0xc));
      FUN_000360ec(param_1,pHVar2);
    }
    ReleaseDC(*(HWND *)(param_1 + 0xc),pHVar2);
  }
  return;
}



/* 00037c8c FUN_00037c8c */

/* Boundary evidence: original MIPS .pdata 00037c8c..000384af. Semantic name remains unreviewed. */

void FUN_00037c8c(int param_1,int param_2,int param_3)

{
  bool bVar1;
  uint uVar2;
  HDC pHVar3;
  errno_t eVar4;
  undefined4 uVar5;
  UINT_PTR UVar6;
  char *pcVar7;
  RECT *lpRect;
  undefined4 uVar8;
  UINT UVar9;
  code *pcVar10;
  int iVar11;
  int *piVar12;
  FILE **_File;
  uint uVar13;
  undefined1 *puVar14;
  undefined1 local_4a0;
  undefined1 local_49f;
  undefined1 local_49e;
  undefined1 local_49d;
  undefined1 local_49c;
  undefined1 local_49b [3];
  FILE *local_498 [2];
  RECT local_490;
  RECT local_480;
  RECT local_470;
  char acStack_460 [64];
  undefined1 auStack_420 [1024];
  uint local_20;
  
  local_20 = DAT_00055374;
  uVar2 = FUN_00036894(param_1,param_2,param_3);
  if (uVar2 < 0x3a) {
    if (uVar2 == 0x39) {
      iVar11 = *(int *)(param_1 + 0x198);
      *(int *)(param_1 + 0x198) = iVar11 + 1;
      if (0x1f < iVar11 + 0x20U) {
        *(undefined4 *)(param_1 + 0x198) = 0;
      }
switchD_00037d00_caseD_b:
      FUN_00036c3c(param_1);
      goto LAB_00038488;
    }
    switch(uVar2) {
    case 0:
      (**(code **)(*DAT_00057130 + 8))(DAT_00057130,0x65,(DAT_00057354 & 0x1800) == 0);
      pHVar3 = GetDC(*(HWND *)(param_1 + 0xc));
      FUN_00034d58(param_1,pHVar3);
      break;
    case 1:
      uVar8 = 1;
      goto LAB_00037df4;
    case 2:
      uVar8 = 1;
      goto LAB_00037e4c;
    case 3:
      uVar8 = 0;
LAB_00037e4c:
      uVar5 = 0x6b;
      goto LAB_00037df8;
    case 4:
      uVar8 = 0;
LAB_00037df4:
      uVar5 = 0x6a;
LAB_00037df8:
      (**(code **)(*DAT_00057130 + 8))(DAT_00057130,uVar5,uVar8);
      *(undefined4 *)(param_1 + 0x74) = 0;
      pHVar3 = GetDC(*(HWND *)(param_1 + 0xc));
      FUN_00034f9c(param_1,pHVar3);
      FUN_0003509c(param_1,pHVar3);
      break;
    case 5:
      if ((DAT_00057354 & 4) == 0) {
        DAT_00057354 = DAT_00057354 | 4;
      }
      else {
        DAT_00057354 = DAT_00057354 & 0xfffffffb;
      }
      local_49b[0] = (DAT_00057354 & 4) == 4;
      FUN_00015b90(DAT_000553cc,3,0,(int)local_49b,1,0x32);
      pHVar3 = GetDC(*(HWND *)(param_1 + 0xc));
      FUN_00034db8(param_1,pHVar3);
      break;
    case 6:
      if ((DAT_00057354 & 0x10) == 0) {
        DAT_00057354 = DAT_00057354 | 0x10;
      }
      else {
        DAT_00057354 = DAT_00057354 & 0xffffffef;
      }
      local_49e = (DAT_00057354 & 0x10) == 0x10;
      FUN_00015b90(DAT_000553cc,3,1,(int)&local_49e,1,0x32);
      pHVar3 = GetDC(*(HWND *)(param_1 + 0xc));
      FUN_00034e18(param_1,pHVar3);
      break;
    case 7:
      bVar1 = (DAT_00057354 & 2) != 0;
      if (bVar1) {
        pcVar10 = *(code **)(*DAT_00057130 + 8);
      }
      else {
        pcVar10 = *(code **)(*DAT_00057130 + 8);
      }
      (*pcVar10)(DAT_00057130,0x81,!bVar1);
      pHVar3 = GetDC(*(HWND *)(param_1 + 0xc));
      FUN_00034e78(param_1,pHVar3);
      break;
    case 8:
      (**(code **)(*DAT_00057130 + 8))(DAT_00057130,0x6f,0);
      goto LAB_00038488;
    case 9:
      *(undefined4 *)(param_1 + 0x194) = 9;
      local_480.left = 0;
      local_480.top = 0;
      local_480.right = 800;
      lpRect = &local_480;
      local_480.bottom = 0x1e0;
      goto LAB_0003847c;
    case 10:
      *(undefined4 *)(param_1 + 0x78) = 0;
      pHVar3 = GetDC(*(HWND *)(param_1 + 0xc));
      FUN_00034ed8(param_1,pHVar3);
      break;
    case 0xb:
      goto switchD_00037d00_caseD_b;
    default:
      goto switchD_00037d00_default;
    }
    goto LAB_00037d70;
  }
  switch(uVar2) {
  case 0x45:
    *(undefined4 *)(param_1 + 0x194) = 0x45;
    local_470.left = 0;
    local_470.top = 0;
    local_470.right = 800;
    lpRect = &local_470;
    local_470.bottom = 0x1e0;
    goto LAB_0003847c;
  case 0x46:
    FUN_0002e1ac(DAT_00057348);
    goto LAB_00038488;
  default:
switchD_00037d00_default:
    if ((0x19 < uVar2) && (uVar2 < 0x39)) {
      piVar12 = (int *)((uVar2 + 8) * 4 + param_1);
      if (*piVar12 != 0) {
        FUN_00015f10(DAT_000553cc,3,1,0xf1,(int)piVar12,4,0x1e);
      }
      goto LAB_00038488;
    }
    if ((uVar2 < 0x3a) || (0x44 < uVar2)) goto LAB_00038488;
    *(uint *)(param_1 + 0x194) = uVar2;
    local_490.left = 0;
    local_490.top = 0;
    lpRect = &local_490;
    local_490.right = 800;
    local_490.bottom = 0x1e0;
LAB_0003847c:
    InvalidateRect(*(HWND *)(param_1 + 0xc),lpRect,0);
    goto LAB_00038488;
  case 0x48:
  case 0x49:
  case 0x4a:
    *(uint *)(param_1 + 0x19c) = uVar2;
    pHVar3 = GetDC(*(HWND *)(param_1 + 0xc));
    FUN_00036324(param_1,pHVar3);
    ReleaseDC(*(HWND *)(param_1 + 0xc),pHVar3);
    FUN_0003e89c(param_1,0x68,500,(TIMERPROC)0x0);
    if (uVar2 == 0x4a) {
      pcVar7 = ".\\Storage Card\\system\\radparam.bin";
    }
    else {
      pcVar7 = ".\\Storage Card\\ULC_RAD_PARAM.bin";
    }
    strcpy_s(acStack_460,0x40,pcVar7);
    eVar4 = fopen_s(local_498,acStack_460,"rb");
    if (eVar4 != 0) goto LAB_00038488;
    fread(auStack_420,0x400,1,local_498[0]);
    fclose(local_498[0]);
    uVar13 = 0;
    puVar14 = auStack_420;
    do {
      FUN_00015b90(DAT_000553cc,3,uVar13 + 0xe0,(int)puVar14,0x80,300);
      uVar13 = uVar13 + 1;
      puVar14 = puVar14 + 0x80;
    } while (uVar13 < 8);
    UVar9 = 0x96;
    UVar6 = 0x69;
    if (uVar2 == 0x48) {
      UVar6 = 0x6a;
    }
    goto LAB_000382b4;
  case 0x4b:
    if ((*(int *)(param_1 + 0x80) != 1) || (*(int *)(param_1 + 0x38) != 0)) goto LAB_00038488;
    _File = (FILE **)(param_1 + 0x34);
    if (*_File != (FILE *)0x0) {
      fclose(*_File);
      FUN_0003e8b8(param_1,0x6b);
      *_File = (FILE *)0x0;
      *(undefined4 *)(param_1 + 0x3c) = 0;
      *(undefined4 *)(param_1 + 0x40) = 0;
      pHVar3 = GetDC(*(HWND *)(param_1 + 0xc));
      FUN_0003623c(param_1,pHVar3);
      break;
    }
    pcVar7 = "\\Storage Card\\qlog.txt";
LAB_00038098:
    eVar4 = fopen_s(_File,pcVar7,"wt");
    if (eVar4 != 0) {
      *_File = (FILE *)0x0;
      goto LAB_00038488;
    }
    UVar9 = 500;
    UVar6 = 0x6b;
LAB_000382b4:
    FUN_0003e89c(param_1,UVar6,UVar9,(TIMERPROC)0x0);
    goto LAB_00038488;
  case 0x4c:
    if ((*(int *)(param_1 + 0x80) != 1) || (*(int *)(param_1 + 0x34) != 0)) goto LAB_00038488;
    _File = (FILE **)(param_1 + 0x38);
    if (*_File == (FILE *)0x0) {
      pcVar7 = "\\Storage Card\\evtlog.txt";
      goto LAB_00038098;
    }
    fclose(*_File);
    FUN_0003e8b8(param_1,0x6b);
    *_File = (FILE *)0x0;
    *(undefined4 *)(param_1 + 0x40) = 0;
    pHVar3 = GetDC(*(HWND *)(param_1 + 0xc));
    FUN_000362b0(param_1,pHVar3);
    break;
  case 0x4d:
    if (*(int *)(param_1 + 0x34) != 0) goto LAB_00038488;
    if (*(int *)(param_1 + 0x80) == 1) {
      local_49c = 1;
      FUN_00015b90(DAT_000553cc,0,0x30,(int)&local_49c,1,0x32);
      *(undefined4 *)(param_1 + 0x80) = 0;
    }
    else {
      local_49f = 0;
      FUN_00015b90(DAT_000553cc,0,0x30,(int)&local_49f,1,0x32);
      *(undefined4 *)(param_1 + 0x80) = 1;
    }
    pHVar3 = GetDC(*(HWND *)(param_1 + 0xc));
    FUN_00036428(param_1,pHVar3);
    break;
  case 0x4e:
    if (*(int *)(param_1 + 0x84) == 0) {
      local_49d = 1;
      FUN_00015b90(DAT_000553cc,0,0x31,(int)&local_49d,1,0x32);
      *(undefined4 *)(param_1 + 0x84) = 1;
    }
    else {
      local_4a0 = 0;
      FUN_00015b90(DAT_000553cc,0,0x31,(int)&local_4a0,1,0x32);
      *(undefined4 *)(param_1 + 0x84) = 0;
    }
    pHVar3 = GetDC(*(HWND *)(param_1 + 0xc));
    FUN_000364a0(param_1,pHVar3);
    break;
  case 0x4f:
    DestroyWindow(*(HWND *)(param_1 + 0xc));
    goto LAB_00038488;
  }
LAB_00037d70:
  ReleaseDC(*(HWND *)(param_1 + 0xc),pHVar3);
LAB_00038488:
  FUN_00043604(local_20);
  return;
}



/* 000384b0 FUN_000384b0 */

/* Boundary evidence: original MIPS .pdata 000384b0..000385f3. Semantic name remains unreviewed. */

void FUN_000384b0(int param_1)

{
  undefined1 local_20 [8];
  
  *(undefined4 *)(DAT_00057130 + 0x5c) = *(undefined4 *)(param_1 + 0xc);
  DAT_00059354 = 1;
  FUN_00016068(DAT_000553cc,3,0xc0,(void *)(param_1 + 0x188),0xb,0x32);
  FUN_00016068(DAT_000553cc,9,5,(void *)(param_1 + 0x7c),2,100);
  local_20[0] = 1;
  FUN_00015b90(DAT_000553cc,3,0xf0,(int)local_20,1,0x32);
  FUN_00036c3c(param_1);
  FUN_0003e89c(param_1,0x65,0xfa,(TIMERPROC)0x0);
  if ((DAT_00057354 & 0x1800) == 0) {
    FUN_0003e89c(param_1,0x66,0x14a,(TIMERPROC)0x0);
    FUN_0003e89c(param_1,0x67,300,(TIMERPROC)0x0);
    FUN_0003e89c(param_1,0x6c,1000,(TIMERPROC)0x0);
    FUN_0003e89c(param_1,0x6d,1000,(TIMERPROC)0x0);
  }
  return;
}



/* 000385f4 FUN_000385f4 */

/* Boundary evidence: original MIPS .pdata 000385f4..0003866b. Semantic name remains unreviewed. */

undefined4 * FUN_000385f4(undefined4 *param_1)

{
  FUN_0003e4a8(param_1);
  *param_1 = &PTR_FUN_00051970;
  param_1[4] = 0;
  param_1[6] = 0;
  param_1[5] = 0;
  param_1[7] = 0;
  param_1[8] = 0;
  param_1[0x13] = 0;
  param_1[0x14] = 0;
  param_1[0x15] = 0;
  param_1[0x16] = 0;
  param_1[0x17] = 0;
  param_1[0x18] = 0;
  param_1[9] = 0;
  param_1[10] = 0;
  param_1[0xf] = 0;
  param_1[0x12] = 0x62;
  return param_1;
}



/* 0003866c FUN_0003866c */

/* Boundary evidence: original MIPS .pdata 0003866c..000386cb. Semantic name remains unreviewed. */

void FUN_0003866c(int param_1)

{
  WCHAR aWStack_30 [16];
  uint local_10;
  
  local_10 = DAT_00055374;
  wsprintfW(aWStack_30,L"%d",*(byte *)(DAT_00055618 + 0x675) - 0x80);
  SetWindowTextW(*(HWND *)(param_1 + 0x24),aWStack_30);
  FUN_00043604(local_10);
  return;
}



/* 000386cc FUN_000386cc */

/* Boundary evidence: original MIPS .pdata 000386cc..0003872b. Semantic name remains unreviewed. */

void FUN_000386cc(int param_1)

{
  WCHAR aWStack_30 [16];
  uint local_10;
  
  local_10 = DAT_00055374;
  wsprintfW(aWStack_30,L"%d",*(byte *)(DAT_00055618 + 0x674) - 0x80);
  SetWindowTextW(*(HWND *)(param_1 + 0x28),aWStack_30);
  FUN_00043604(local_10);
  return;
}



/* 0003872c FUN_0003872c */

/* Boundary evidence: original MIPS .pdata 0003872c..0003878b. Semantic name remains unreviewed. */

void FUN_0003872c(int param_1)

{
  WCHAR aWStack_30 [16];
  uint local_10;
  
  local_10 = DAT_00055374;
  wsprintfW(aWStack_30,L"%d",*(byte *)(DAT_00055618 + 0x676) - 0x80);
  SetWindowTextW(*(HWND *)(param_1 + 0x2c),aWStack_30);
  FUN_00043604(local_10);
  return;
}



/* 0003878c FUN_0003878c */

/* Boundary evidence: original MIPS .pdata 0003878c..000387eb. Semantic name remains unreviewed. */

void FUN_0003878c(int param_1)

{
  WCHAR aWStack_30 [16];
  uint local_10;
  
  local_10 = DAT_00055374;
  wsprintfW(aWStack_30,L"%d",*(byte *)(DAT_00055618 + 0x677) - 0x80);
  SetWindowTextW(*(HWND *)(param_1 + 0x30),aWStack_30);
  FUN_00043604(local_10);
  return;
}



/* 000387ec FUN_000387ec */

/* Boundary evidence: original MIPS .pdata 000387ec..0003884b. Semantic name remains unreviewed. */

void FUN_000387ec(int param_1)

{
  WCHAR aWStack_30 [16];
  uint local_10;
  
  local_10 = DAT_00055374;
  wsprintfW(aWStack_30,L"%d",*(byte *)(DAT_00055618 + 0x678) - 0x80);
  SetWindowTextW(*(HWND *)(param_1 + 0x34),aWStack_30);
  FUN_00043604(local_10);
  return;
}



/* 0003884c FUN_0003884c */

/* Boundary evidence: original MIPS .pdata 0003884c..000388a3. Semantic name remains unreviewed. */

undefined4 * FUN_0003884c(undefined4 *param_1,uint param_2)

{
  *param_1 = &PTR_FUN_00051970;
  FUN_0003e4d0(param_1);
  if ((param_2 & 1) != 0) {
    __3_YAXPAX_Z(param_1);
  }
  return param_1;
}



/* 000388a4 FUN_000388a4 */

/* Boundary evidence: original MIPS .pdata 000388a4..00039163. Semantic name remains unreviewed. */

void FUN_000388a4(int param_1)

{
  undefined4 uVar1;
  uint uVar2;
  HWND pHVar3;
  undefined4 auStack_98 [8];
  undefined1 local_78;
  undefined1 local_77;
  undefined1 local_76;
  undefined1 local_75;
  WCHAR aWStack_70 [16];
  WCHAR aWStack_50 [16];
  uint local_30;
  
  local_30 = DAT_00055374;
  uVar1 = FUN_0003e894();
  uVar2 = FUN_0003e88c();
  FUN_0003b5d0(auStack_98,*(undefined4 *)(param_1 + 4),*(undefined4 *)(param_1 + 0xc),uVar2,uVar1);
  FUN_0003b6ac(auStack_98,1,L"LOAD EOL FILE",3,(HMENU)0x1);
  FUN_0003b604((int)auStack_98,0);
  FUN_0003b6ac(auStack_98,0,L"AUDIO SOURCE",0,(HMENU)0x0);
  FUN_0003b6ac(auStack_98,1,L"RADIO",1,(HMENU)0x2);
  FUN_0003b6ac(auStack_98,1,L"DAB",1,(HMENU)0x3);
  FUN_0003b6ac(auStack_98,1,L"AUX",1,(HMENU)0x4);
  FUN_0003b6ac(auStack_98,1,L"USB",1,(HMENU)0x5);
  FUN_0003b6ac(auStack_98,1,L"IPOD",1,(HMENU)0x6);
  pHVar3 = FUN_0003b6ac(auStack_98,1,L"CALL\r\n(OFF)",1,(HMENU)0x7);
  *(HWND *)(param_1 + 0x14) = pHVar3;
  pHVar3 = FUN_0003b6ac(auStack_98,1,L"NAVI\r\n(OFF)",1,(HMENU)0x8);
  *(HWND *)(param_1 + 0x1c) = pHVar3;
  FUN_0003b604((int)auStack_98,0);
  FUN_0003b6ac(auStack_98,0,L"Sound",0,(HMENU)0x0);
  FUN_0003b6ac(auStack_98,1,L"BALANCE",2,(HMENU)0x0);
  FUN_0003b604((int)auStack_98,1);
  FUN_0003b6ac(auStack_98,1,L"-",1,(HMENU)0xa);
  pHVar3 = FUN_0003b6ac(auStack_98,2,L"",1,(HMENU)0x0);
  *(HWND *)(param_1 + 0x24) = pHVar3;
  FUN_0003b6ac(auStack_98,1,L"+",1,(HMENU)0xb);
  FUN_0003b664((int)auStack_98);
  FUN_0003b6ac(auStack_98,1,L"FADER",2,(HMENU)0x0);
  FUN_0003b604((int)auStack_98,1);
  FUN_0003b6ac(auStack_98,1,L"-",1,(HMENU)0xc);
  pHVar3 = FUN_0003b6ac(auStack_98,2,L"",1,(HMENU)0x0);
  *(HWND *)(param_1 + 0x28) = pHVar3;
  FUN_0003b6ac(auStack_98,1,L"+",1,(HMENU)0xd);
  FUN_0003b664((int)auStack_98);
  FUN_0003b6ac(auStack_98,1,L"BASS",2,(HMENU)0x0);
  FUN_0003b604((int)auStack_98,1);
  FUN_0003b6ac(auStack_98,1,L"-",1,(HMENU)0xe);
  pHVar3 = FUN_0003b6ac(auStack_98,2,L"",1,(HMENU)0x0);
  *(HWND *)(param_1 + 0x2c) = pHVar3;
  FUN_0003b6ac(auStack_98,1,L"+",1,(HMENU)0xf);
  FUN_0003b664((int)auStack_98);
  FUN_0003b6ac(auStack_98,1,L"MID",2,(HMENU)0x0);
  FUN_0003b604((int)auStack_98,1);
  FUN_0003b6ac(auStack_98,1,L"-",1,(HMENU)0x10);
  pHVar3 = FUN_0003b6ac(auStack_98,2,L"",1,(HMENU)0x0);
  *(HWND *)(param_1 + 0x30) = pHVar3;
  FUN_0003b6ac(auStack_98,1,L"+",1,(HMENU)0x11);
  FUN_0003b664((int)auStack_98);
  FUN_0003b6ac(auStack_98,1,L"TREBLE",2,(HMENU)0x0);
  FUN_0003b604((int)auStack_98,1);
  FUN_0003b6ac(auStack_98,1,L"-",1,(HMENU)0x12);
  pHVar3 = FUN_0003b6ac(auStack_98,2,L"",1,(HMENU)0x0);
  *(HWND *)(param_1 + 0x34) = pHVar3;
  FUN_0003b6ac(auStack_98,1,L"+",1,(HMENU)0x13);
  FUN_0003b68c((int)auStack_98);
  if ((DAT_00057354 & 1) == 0) {
    pHVar3 = FUN_0003b6ac(auStack_98,1,L"MIC(INT)",2,(HMENU)0x0);
  }
  else {
    pHVar3 = FUN_0003b6ac(auStack_98,1,L"MIC(EXT)",2,(HMENU)0x0);
  }
  *(HWND *)(param_1 + 0x38) = pHVar3;
  FUN_0003b604((int)auStack_98,1);
  FUN_0003b6ac(auStack_98,1,L"INTERNAL",2,(HMENU)0x14);
  FUN_0003b6ac(auStack_98,1,L"EXTERNAL",2,(HMENU)0x15);
  FUN_0003b604((int)auStack_98,0);
  FUN_0003b6ac(auStack_98,1,L"LOUDNESS",2,(HMENU)0x0);
  FUN_0003b604((int)auStack_98,1);
  FUN_0003b6ac(auStack_98,1,L"ON",1,(HMENU)0x16);
  FUN_0003b6ac(auStack_98,1,L"OFF",1,(HMENU)0x17);
  FUN_0003b604((int)auStack_98,0);
  FUN_0003b6ac(auStack_98,1,L"SDVC",1,(HMENU)0x0);
  FUN_0003b604((int)auStack_98,1);
  FUN_0003b6ac(auStack_98,1,L"0",1,(HMENU)0x18);
  FUN_0003b6ac(auStack_98,1,L"1",1,(HMENU)0x19);
  FUN_0003b6ac(auStack_98,1,L"2",1,(HMENU)0x1a);
  FUN_0003b6ac(auStack_98,1,L"3",1,(HMENU)0x1b);
  FUN_0003b6ac(auStack_98,1,L"4",1,(HMENU)0x1c);
  FUN_0003b6ac(auStack_98,1,L"5",1,(HMENU)0x1d);
  FUN_0003b664((int)auStack_98);
  FUN_0003b6ac(auStack_98,1,L"-",1,(HMENU)0x1e);
  pHVar3 = FUN_0003b6ac(auStack_98,2,L"",1,(HMENU)0x0);
  *(HWND *)(param_1 + 0x3c) = pHVar3;
  wsprintfW(aWStack_70,L"%03X",*(undefined4 *)(param_1 + 0x48));
  SetWindowTextW(*(HWND *)(param_1 + 0x3c),aWStack_70);
  local_78 = *(undefined1 *)(param_1 + 0x49);
  local_77 = (undefined1)*(undefined4 *)(param_1 + 0x48);
  FUN_00015b90(DAT_000553cc,2,0xd1086,(int)&local_78,2,100);
  FUN_0003b6ac(auStack_98,1,L"+",1,(HMENU)0x1f);
  FUN_0003b664((int)auStack_98);
  pHVar3 = FUN_0003b6ac(auStack_98,1,L"REC MICIN\r\n(OFF)",2,(HMENU)0x20);
  *(HWND *)(param_1 + 0x50) = pHVar3;
  pHVar3 = FUN_0003b6ac(auStack_98,1,L"REC MICOUT\r\n(OFF)",2,(HMENU)0x21);
  *(HWND *)(param_1 + 0x58) = pHVar3;
  pHVar3 = FUN_0003b6ac(auStack_98,1,L"REC RECVIN\r\n(OFF)",2,(HMENU)0x22);
  *(HWND *)(param_1 + 0x60) = pHVar3;
  FUN_0003b664((int)auStack_98);
  FUN_0003b6ac(auStack_98,1,L"-",1,(HMENU)0x23);
  pHVar3 = FUN_0003b6ac(auStack_98,2,L"",1,(HMENU)0x0);
  *(HWND *)(param_1 + 0x40) = pHVar3;
  wsprintfW(aWStack_50,L"%03X",*(undefined4 *)(param_1 + 0x44));
  SetWindowTextW(*(HWND *)(param_1 + 0x40),aWStack_50);
  local_76 = *(undefined1 *)(param_1 + 0x45);
  local_75 = (undefined1)*(undefined4 *)(param_1 + 0x44);
  FUN_00015b90(DAT_000553cc,2,0xd1086,(int)&local_76,2,100);
  FUN_0003b6ac(auStack_98,1,L"+",1,(HMENU)0x24);
  FUN_0003866c(param_1);
  FUN_000386cc(param_1);
  FUN_0003872c(param_1);
  FUN_0003878c(param_1);
  FUN_000387ec(param_1);
  FUN_0003e4c8();
  FUN_00043604(local_30);
  return;
}



/* 00039164 Unwind@00039164 */

/* Boundary evidence: original MIPS .pdata 00039164..00039193. Semantic name remains unreviewed. */

void Unwind_00039164(void)

{
  FUN_0003e4c8();
  return;
}



/* 00039194 FUN_00039194 */

/* Boundary evidence: original MIPS .pdata 00039194..00039bc3. Semantic name remains unreviewed. */

void FUN_00039194(int param_1,undefined4 param_2)

{
  errno_t eVar1;
  long lVar2;
  uint uVar3;
  LPCWSTR lpString;
  int iVar4;
  undefined *puVar5;
  byte bVar6;
  char cVar7;
  undefined1 *puVar8;
  code *pcVar9;
  FILE *local_5f0;
  char local_5ec [5];
  undefined1 local_5e7;
  undefined1 local_5e6;
  undefined1 local_5e5;
  undefined1 local_5e4;
  undefined1 local_5e3;
  undefined1 local_5e2;
  undefined1 local_5e1;
  undefined1 local_5e0 [8];
  WCHAR aWStack_5d8 [16];
  WCHAR aWStack_5b8 [16];
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
  
  local_18 = DAT_00055374;
  switch(param_2) {
  case 1:
    memset(local_418,0,0x400);
    eVar1 = fopen_s(&local_5f0,".\\MD\\arkamys_eol.dat","rb");
    if (((eVar1 == 0) ||
        (eVar1 = fopen_s(&local_5f0,".\\Storage Card\\system\\arkamys_default.dat","rb"), eVar1 == 0
        )) && (local_5f0 != (FILE *)0x0)) {
      fseek(local_5f0,0,2);
      lVar2 = ftell(local_5f0);
      fseek(local_5f0,0,0);
      if (lVar2 == 0x395) {
        fread(local_418,0x395,1,local_5f0);
      }
      else if (lVar2 == 0x72a) {
        uVar3 = 0;
        local_5ec[0] = '\0';
        local_5ec[1] = 0;
        local_5ec[2] = 0;
        local_5ec[3] = 0;
        do {
          fread(local_5ec,2,1,local_5f0);
          local_5ec[3] = 0;
          sscanf_s(local_5ec,"%x",local_5e0);
          puVar8 = local_418 + uVar3;
          uVar3 = uVar3 + 1;
          *puVar8 = (char)local_5e0._0_4_;
        } while (uVar3 < 0x395);
      }
      fclose(local_5f0);
      FUN_00015b90(DAT_000553cc,0xf,0x21,(int)local_418,0x80,300);
      FUN_00015b90(DAT_000553cc,0xf,0x22,(int)(local_418 + 0x80),0x80,300);
      FUN_00015b90(DAT_000553cc,0xf,0x23,(int)(local_418 + 0x100),0x80,300);
      FUN_00015b90(DAT_000553cc,0xf,0x24,(int)(local_418 + 0x180),0x80,300);
      FUN_00015b90(DAT_000553cc,0xf,0x25,(int)(local_418 + 0x200),0x80,300);
      FUN_00015b90(DAT_000553cc,0xf,0x26,(int)(local_418 + 0x280),0x80,300);
      FUN_00015b90(DAT_000553cc,0xf,0x27,(int)(local_418 + 0x300),0x80,300);
      FUN_00015b90(DAT_000553cc,0xf,0x28,(int)(local_418 + 0x380),0x80,300);
      FUN_00015f10(DAT_000553cc,5,1,0x60,0,0,200);
    }
    break;
  case 2:
    uVar3 = 0;
    goto LAB_0003946c;
  case 3:
    uVar3 = 4;
    goto LAB_0003946c;
  case 4:
    uVar3 = 1;
    goto LAB_0003946c;
  case 5:
    uVar3 = 2;
    goto LAB_0003946c;
  case 6:
    uVar3 = 3;
LAB_0003946c:
    FUN_000118e8(DAT_00055384,uVar3);
    break;
  case 7:
    if (*(int *)(param_1 + 0x10) == 1) {
      *(undefined4 *)(param_1 + 0x10) = 0;
    }
    else {
      *(undefined4 *)(param_1 + 0x10) = 1;
    }
    if (*(int *)(param_1 + 0x10) == 0) {
      puVar5 = &DAT_00051620;
    }
    else {
      puVar5 = &DAT_00051628;
    }
    wsprintfW(aWStack_538,L"CALL\r\n(%s)",puVar5);
    SetWindowTextW(*(HWND *)(param_1 + 0x14),aWStack_538);
    iVar4 = *(int *)(param_1 + 0x10);
    uVar3 = 0;
    goto LAB_00039500;
  case 8:
    if (*(int *)(param_1 + 0x18) == 1) {
      *(undefined4 *)(param_1 + 0x18) = 0;
    }
    else {
      *(undefined4 *)(param_1 + 0x18) = 1;
    }
    if (*(int *)(param_1 + 0x18) == 0) {
      puVar5 = &DAT_00051620;
    }
    else {
      puVar5 = &DAT_00051628;
    }
    wsprintfW(aWStack_598,L"NAVI\r\n(%s)",puVar5);
    SetWindowTextW(*(HWND *)(param_1 + 0x1c),aWStack_598);
    iVar4 = *(int *)(param_1 + 0x18);
    uVar3 = 3;
LAB_00039500:
    FUN_000119f0(DAT_00055384,uVar3,iVar4);
    break;
  case 10:
    if (*(byte *)(DAT_00055618 + 0x675) < 0x7c) {
      uVar3 = 0x7b;
    }
    else {
      bVar6 = *(byte *)(DAT_00055618 + 0x675) - 1;
LAB_000395a8:
      uVar3 = (uint)bVar6;
    }
    goto LAB_000395b4;
  case 0xb:
    if (*(byte *)(DAT_00055618 + 0x675) < 0x85) {
      bVar6 = *(byte *)(DAT_00055618 + 0x675) + 1;
      goto LAB_000395a8;
    }
    uVar3 = 0x85;
LAB_000395b4:
    FUN_00011304(DAT_00055384,uVar3);
    FUN_0003866c(param_1);
    break;
  case 0xc:
    if (*(byte *)(DAT_00055618 + 0x674) < 0x7c) {
      uVar3 = 0x7b;
    }
    else {
      bVar6 = *(byte *)(DAT_00055618 + 0x674) - 1;
LAB_00039628:
      uVar3 = (uint)bVar6;
    }
    goto LAB_00039634;
  case 0xd:
    if (*(byte *)(DAT_00055618 + 0x674) < 0x85) {
      bVar6 = *(byte *)(DAT_00055618 + 0x674) + 1;
      goto LAB_00039628;
    }
    uVar3 = 0x85;
LAB_00039634:
    FUN_00011378(DAT_00055384,uVar3);
    FUN_000386cc(param_1);
    break;
  case 0xe:
    if (*(byte *)(DAT_00055618 + 0x676) < 0x7c) {
      cVar7 = '{';
    }
    else {
      cVar7 = *(byte *)(DAT_00055618 + 0x676) - 1;
    }
    goto LAB_000396b4;
  case 0xf:
    if (*(byte *)(DAT_00055618 + 0x676) < 0x85) {
      cVar7 = *(byte *)(DAT_00055618 + 0x676) + 1;
    }
    else {
      cVar7 = -0x7b;
    }
LAB_000396b4:
    FUN_000113ec(DAT_00055384,cVar7);
    FUN_0003872c(param_1);
    break;
  case 0x10:
    if (*(byte *)(DAT_00055618 + 0x677) < 0x7c) {
      cVar7 = '{';
    }
    else {
      cVar7 = *(byte *)(DAT_00055618 + 0x677) - 1;
    }
    goto LAB_00039734;
  case 0x11:
    if (*(byte *)(DAT_00055618 + 0x677) < 0x85) {
      cVar7 = *(byte *)(DAT_00055618 + 0x677) + 1;
    }
    else {
      cVar7 = -0x7b;
    }
LAB_00039734:
    FUN_00011448(DAT_00055384,cVar7);
    FUN_0003878c(param_1);
    break;
  case 0x12:
    if (*(byte *)(DAT_00055618 + 0x678) < 0x7c) {
      cVar7 = '{';
    }
    else {
      cVar7 = *(byte *)(DAT_00055618 + 0x678) - 1;
    }
    goto LAB_000397b4;
  case 0x13:
    if (*(byte *)(DAT_00055618 + 0x678) < 0x85) {
      cVar7 = *(byte *)(DAT_00055618 + 0x678) + 1;
    }
    else {
      cVar7 = -0x7b;
    }
LAB_000397b4:
    FUN_000114a4(DAT_00055384,cVar7);
    FUN_000387ec(param_1);
    break;
  case 0x14:
    DAT_00057354 = DAT_00057354 & 0xfffffffe;
    wsprintfW(aWStack_5d8,L"MIC(INT)");
    lpString = aWStack_5d8;
    goto LAB_00039828;
  case 0x15:
    DAT_00057354 = DAT_00057354 | 1;
    wsprintfW(aWStack_558,L"MIC(EXT)");
    lpString = aWStack_558;
LAB_00039828:
    SetWindowTextW(*(HWND *)(param_1 + 0x38),lpString);
    break;
  case 0x16:
    iVar4 = 1;
    goto LAB_00039868;
  case 0x17:
    iVar4 = 0;
LAB_00039868:
    FUN_0001122c(DAT_00055384,iVar4);
    break;
  case 0x18:
    iVar4 = 0;
    goto LAB_00039888;
  case 0x19:
    iVar4 = 1;
    goto LAB_00039888;
  case 0x1a:
    iVar4 = 2;
    goto LAB_00039888;
  case 0x1b:
    iVar4 = 3;
    goto LAB_00039888;
  case 0x1c:
    iVar4 = 4;
    goto LAB_00039888;
  case 0x1d:
    iVar4 = 5;
LAB_00039888:
    FUN_0001129c(DAT_00055384,iVar4);
    break;
  case 0x1e:
    *(int *)(param_1 + 0x48) = *(int *)(param_1 + 0x48) + -1;
    wsprintfW(aWStack_4f8,L"%03X");
    SetWindowTextW(*(HWND *)(param_1 + 0x3c),aWStack_4f8);
    local_5e2 = *(undefined1 *)(param_1 + 0x49);
    local_5e1 = (undefined1)*(undefined4 *)(param_1 + 0x48);
    FUN_00015b90(DAT_000553cc,2,0xd1086,(int)&local_5e2,2,100);
    break;
  case 0x1f:
    *(int *)(param_1 + 0x48) = *(int *)(param_1 + 0x48) + 1;
    wsprintfW(aWStack_518,L"%03X");
    SetWindowTextW(*(HWND *)(param_1 + 0x3c),aWStack_518);
    local_5e6 = *(undefined1 *)(param_1 + 0x49);
    local_5e5 = (undefined1)*(undefined4 *)(param_1 + 0x48);
    FUN_00015b90(DAT_000553cc,2,0xd1086,(int)&local_5e6,2,100);
    break;
  case 0x20:
    if (*(int *)(param_1 + 0x4c) == 1) {
      *(undefined4 *)(param_1 + 0x4c) = 0;
    }
    else {
      *(undefined4 *)(param_1 + 0x4c) = 1;
    }
    if (*(int *)(param_1 + 0x4c) == 0) {
      puVar5 = &DAT_00051620;
    }
    else {
      puVar5 = &DAT_00051628;
    }
    wsprintfW(aWStack_4d8,L"REC MICIN\r\n(%s)",puVar5);
    SetWindowTextW(*(HWND *)(param_1 + 0x50),aWStack_4d8);
    pcVar9 = OnRecMicInBNT_exref;
    goto LAB_00039b9c;
  case 0x21:
    if (*(int *)(param_1 + 0x54) == 1) {
      *(undefined4 *)(param_1 + 0x54) = 0;
    }
    else {
      *(undefined4 *)(param_1 + 0x54) = 1;
    }
    if (*(int *)(param_1 + 0x54) == 0) {
      puVar5 = &DAT_00051620;
    }
    else {
      puVar5 = &DAT_00051628;
    }
    wsprintfW(aWStack_458,L"REC MICOUT\r\n(%s)",puVar5);
    SetWindowTextW(*(HWND *)(param_1 + 0x58),aWStack_458);
    pcVar9 = OnRecMicOutBNT_exref;
    goto LAB_00039b9c;
  case 0x22:
    if (*(int *)(param_1 + 0x5c) == 1) {
      *(undefined4 *)(param_1 + 0x5c) = 0;
    }
    else {
      *(undefined4 *)(param_1 + 0x5c) = 1;
    }
    if (*(int *)(param_1 + 0x5c) == 0) {
      puVar5 = &DAT_00051620;
    }
    else {
      puVar5 = &DAT_00051628;
    }
    wsprintfW(aWStack_498,L"REC RECVIN\r\n(%s)",puVar5);
    SetWindowTextW(*(HWND *)(param_1 + 0x60),aWStack_498);
    pcVar9 = OnRecRecvInBNT_exref;
LAB_00039b9c:
    (*pcVar9)();
    break;
  case 0x23:
    *(int *)(param_1 + 0x44) = *(int *)(param_1 + 0x44) + -1;
    wsprintfW(aWStack_5b8,L"%03X");
    SetWindowTextW(*(HWND *)(param_1 + 0x40),aWStack_5b8);
    local_5e4 = *(undefined1 *)(param_1 + 0x45);
    local_5e3 = (undefined1)*(undefined4 *)(param_1 + 0x44);
    FUN_00015b90(DAT_000553cc,2,0xd1086,(int)&local_5e4,2,100);
    break;
  case 0x24:
    *(int *)(param_1 + 0x44) = *(int *)(param_1 + 0x44) + 1;
    wsprintfW(aWStack_578,L"%03X");
    SetWindowTextW(*(HWND *)(param_1 + 0x40),aWStack_578);
    local_5ec[4] = *(undefined1 *)(param_1 + 0x45);
    local_5e7 = (undefined1)*(undefined4 *)(param_1 + 0x44);
    FUN_00015b90(DAT_000553cc,2,0xd1086,(int)(local_5ec + 4),2,100);
  }
  FUN_00043604(local_18);
  return;
}



/* 00039bc4 FUN_00039bc4 */

/* Boundary evidence: original MIPS .pdata 00039bc4..00039c2f. Semantic name remains unreviewed. */

undefined4 * FUN_00039bc4(undefined4 *param_1)

{
  FUN_0003e4a8(param_1);
  *param_1 = &PTR_FUN_00051d34;
  param_1[6] = 9;
  param_1[5] = 1;
  param_1[4] = 1;
  param_1[9] = 0;
  param_1[10] = 0;
  param_1[0xb] = 0;
  param_1[0xc] = 0;
  *(undefined2 *)(param_1 + 7) = 0;
  *(undefined2 *)((int)param_1 + 0x1e) = 0;
  *(undefined2 *)(param_1 + 8) = 0;
  *(undefined2 *)((int)param_1 + 0x22) = 0;
  return param_1;
}



/* 00039c30 FUN_00039c30 */

/* Boundary evidence: original MIPS .pdata 00039c30..00039c93. Semantic name remains unreviewed. */

void FUN_00039c30(int param_1,int param_2)

{
  RECT local_18;
  
  if (param_2 == 100) {
    FUN_0003e8b8(param_1,100);
    *(undefined4 *)(param_1 + 0x18) = 9;
    local_18.left = 0;
    local_18.top = 0;
    local_18.right = 800;
    local_18.bottom = 0x1e0;
    InvalidateRect(*(HWND *)(param_1 + 0xc),&local_18,0);
  }
  return;
}



/* 00039c94 FUN_00039c94 */

/* Boundary evidence: original MIPS .pdata 00039c94..00039d1f. Semantic name remains unreviewed. */

void FUN_00039c94(int param_1)

{
  undefined1 local_18 [8];
  
  if (*(int *)(param_1 + 0x10) == 0) {
    local_18[0] = 0;
    FUN_00015b90(DAT_000553cc,0,0x30,(int)local_18,1,0x32);
  }
  local_18[0] = 0;
  FUN_00015b90(DAT_000553cc,3,0xf0,(int)local_18,1,0x32);
  DAT_00059354 = 0;
  return;
}



/* 00039d20 FUN_00039d20 */

/* Boundary evidence: original MIPS .pdata 00039d20..00039db3. Semantic name remains unreviewed. */

undefined2 FUN_00039d20(double param_1,double param_2,undefined4 param_3,undefined4 param_4)

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



/* 00039db4 FUN_00039db4 */

/* Boundary evidence: original MIPS .pdata 00039db4..0003a02b. Semantic name remains unreviewed. */

void FUN_00039db4(double param_1,int param_2)

{
  uint uVar1;
  undefined4 uVar2;
  undefined4 extraout_v0;
  undefined4 extraout_v0_00;
  undefined4 extraout_v0_01;
  undefined4 extraout_v0_02;
  undefined4 extraout_v1;
  undefined4 extraout_v1_00;
  undefined4 extraout_v1_01;
  undefined4 extraout_v1_02;
  byte local_20;
  byte local_1f;
  byte local_1e;
  byte local_1d;
  
  uVar1 = FUN_00016068(DAT_000553cc,2,0xd102d,&local_20,2,200);
  if (uVar1 == 2) {
    *(ushort *)(param_2 + 0x1c) = (ushort)local_20 * 0x100 + (ushort)local_1f;
  }
  uVar1 = FUN_00016068(DAT_000553cc,2,0xd105e,&local_20,4,200);
  if (uVar1 == 4) {
    *(ushort *)(param_2 + 0x1e) = (ushort)local_20 * 0x100 + (ushort)local_1f;
    *(ushort *)(param_2 + 0x20) = (ushort)local_1e * 0x100 + (ushort)local_1d;
  }
  uVar1 = FUN_00016068(DAT_000553cc,2,0xd10d5,&local_20,2,200);
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
  *(undefined4 *)(param_2 + 0x24) = uVar2;
  uVar2 = __litofp(*(undefined2 *)(param_2 + 0x1e));
  uVar2 = __fpmul(uVar2,0x3a000000);
  __fptodp(uVar2);
  log10(param_1);
  uVar2 = __dptofp(extraout_v0_00,extraout_v1_00);
  uVar2 = __fpmul(uVar2,0x41a00000);
  uVar2 = __fpadd(uVar2,0x40c0a3d7);
  *(undefined4 *)(param_2 + 0x28) = uVar2;
  uVar2 = __litofp(*(undefined2 *)(param_2 + 0x20));
  uVar2 = __fpmul(uVar2,0x3a000000);
  __fptodp(uVar2);
  log10(param_1);
  uVar2 = __dptofp(extraout_v0_01,extraout_v1_01);
  uVar2 = __fpmul(uVar2,0x41a00000);
  uVar2 = __fpadd(uVar2,0x40c0a3d7);
  *(undefined4 *)(param_2 + 0x2c) = uVar2;
  uVar2 = __litofp(*(undefined2 *)(param_2 + 0x22));
  uVar2 = __fpmul(uVar2,0x3a000000);
  __fptodp(uVar2);
  log10(param_1);
  uVar2 = __dptofp(extraout_v0_02,extraout_v1_02);
  uVar2 = __fpmul(uVar2,0x41a00000);
  uVar2 = __fpadd(uVar2,0x40c0a3d7);
  *(undefined4 *)(param_2 + 0x30) = uVar2;
  return;
}



/* 0003a02c FUN_0003a02c */

/* Boundary evidence: original MIPS .pdata 0003a02c..0003a113. Semantic name remains unreviewed. */

HFONT FUN_0003a02c(LONG param_1,LONG param_2,LONG param_3,LONG param_4,LONG param_5,BYTE param_6,
                  BYTE param_7,BYTE param_8,BYTE param_9,BYTE param_10,BYTE param_11,BYTE param_12,
                  BYTE param_13,LPCWSTR param_14)

{
  HFONT pHVar1;
  LOGFONTW local_78;
  uint local_1c;
  
  local_1c = DAT_00055374;
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
  FUN_00043604(local_1c);
  return pHVar1;
}



/* 0003a114 FUN_0003a114 */

/* Boundary evidence: original MIPS .pdata 0003a114..0003a1ab. Semantic name remains unreviewed. */

BOOL FUN_0003a114(undefined4 param_1,HDC param_2,RECT *param_3,COLORREF param_4)

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



/* 0003a1ac FUN_0003a1ac */

/* Boundary evidence: original MIPS .pdata 0003a1ac..0003a3bf. Semantic name remains unreviewed. */

void FUN_0003a1ac(int param_1,HDC param_2,int param_3,LONG param_4,COLORREF param_5,COLORREF param_6
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
  lprc = (RECT *)(&DAT_00051ca4 + param_3 * 4);
  FUN_0003a114(param_1,hdc,lprc,param_6);
  SetBkMode(hdc,1);
  SetTextColor(hdc,param_5);
  h_01 = FUN_0003a02c(param_4,0,0,0,0,'\0','\0','\0','\0','\0','\0','\x06','\x02',L"Tahoma");
  h_02 = SelectObject(hdc,h_01);
  DrawTextW(hdc,param_7,-1,lprc,5);
  SelectObject(hdc,h_02);
  DeleteObject(h_01);
  y = (&DAT_00051ca8)[param_3 * 4];
  x = lprc->left;
  BitBlt(param_2,x,y,(&DAT_00051cac)[param_3 * 4] - x,(&DAT_00051cb0)[param_3 * 4] - y,hdc,x,y,
         0xcc0020);
  SelectObject(hdc,h_00);
  DeleteObject(h);
  DeleteDC(hdc);
  return;
}



/* 0003a3c0 FUN_0003a3c0 */

/* Boundary evidence: original MIPS .pdata 0003a3c0..0003a673. Semantic name remains unreviewed. */

void FUN_0003a3c0(int param_1,HDC param_2,int param_3,LONG param_4,LONG param_5,COLORREF param_6,
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
  lprc = (RECT *)(&DAT_00051ca4 + param_3 * 4);
  FUN_0003a114(param_1,hdc,lprc,param_8);
  SetBkMode(hdc,1);
  SetTextColor(hdc,param_6);
  pHVar1 = FUN_0003a02c(param_4,0,0,0,0,'\0','\0','\0','\0','\0','\0','\x06','\x02',L"Tahoma");
  pvVar2 = SelectObject(hdc,pHVar1);
  DrawTextW(hdc,param_9,-1,lprc,1);
  SelectObject(hdc,pvVar2);
  DeleteObject(pHVar1);
  SetBkMode(hdc,1);
  SetTextColor(hdc,param_7);
  pHVar1 = FUN_0003a02c(param_5,0,0,0,0,'\0','\0','\0','\0','\0','\0','\x06','\x02',L"Tahoma");
  pvVar2 = SelectObject(hdc,pHVar1);
  DrawTextW(hdc,param_10,-1,lprc,9);
  SelectObject(hdc,pvVar2);
  DeleteObject(pHVar1);
  y = (&DAT_00051ca8)[param_3 * 4];
  x = lprc->left;
  BitBlt(param_2,x,y,(&DAT_00051cac)[param_3 * 4] - x,(&DAT_00051cb0)[param_3 * 4] - y,hdc,x,y,
         0xcc0020);
  SelectObject(hdc,h_00);
  DeleteObject(h);
  DeleteDC(hdc);
  return;
}



/* 0003a674 FUN_0003a674 */

/* Boundary evidence: original MIPS .pdata 0003a674..0003a72f. Semantic name remains unreviewed. */

void FUN_0003a674(int param_1,HDC param_2)

{
  ushort uVar1;
  undefined8 uVar2;
  WCHAR aWStack_98 [64];
  uint local_18;
  
  local_18 = DAT_00055374;
  uVar1 = *(ushort *)(param_1 + 0x1c);
  uVar2 = __fptodp(*(undefined4 *)(param_1 + 0x24));
  wsprintfW(aWStack_98,L"%5.1f(%04X)",(int)uVar2,(int)((ulonglong)uVar2 >> 0x20),(uint)uVar1);
  FUN_0003a3c0(param_1,param_2,4,0x12,0x1c,0xb4b4b4,0xffffff,0,L"Primary",aWStack_98);
  FUN_00043604(local_18);
  return;
}



/* 0003a730 FUN_0003a730 */

/* Boundary evidence: original MIPS .pdata 0003a730..0003a7eb. Semantic name remains unreviewed. */

void FUN_0003a730(int param_1,HDC param_2)

{
  ushort uVar1;
  undefined8 uVar2;
  WCHAR aWStack_98 [64];
  uint local_18;
  
  local_18 = DAT_00055374;
  uVar1 = *(ushort *)(param_1 + 0x1e);
  uVar2 = __fptodp(*(undefined4 *)(param_1 + 0x28));
  wsprintfW(aWStack_98,L"%5.1f(%04X)",(int)uVar2,(int)((ulonglong)uVar2 >> 0x20),(uint)uVar1);
  FUN_0003a3c0(param_1,param_2,5,0x12,0x1c,0xb4b4b4,0xffffff,0,L"Navi",aWStack_98);
  FUN_00043604(local_18);
  return;
}



/* 0003a7ec FUN_0003a7ec */

/* Boundary evidence: original MIPS .pdata 0003a7ec..0003a8a7. Semantic name remains unreviewed. */

void FUN_0003a7ec(int param_1,HDC param_2)

{
  ushort uVar1;
  undefined8 uVar2;
  WCHAR aWStack_98 [64];
  uint local_18;
  
  local_18 = DAT_00055374;
  uVar1 = *(ushort *)(param_1 + 0x20);
  uVar2 = __fptodp(*(undefined4 *)(param_1 + 0x2c));
  wsprintfW(aWStack_98,L"%5.1f(%04X)",(int)uVar2,(int)((ulonglong)uVar2 >> 0x20),(uint)uVar1);
  FUN_0003a3c0(param_1,param_2,6,0x12,0x1c,0xb4b4b4,0xffffff,0,L"Phone",aWStack_98);
  FUN_00043604(local_18);
  return;
}



/* 0003a8a8 FUN_0003a8a8 */

/* Boundary evidence: original MIPS .pdata 0003a8a8..0003a963. Semantic name remains unreviewed. */

void FUN_0003a8a8(int param_1,HDC param_2)

{
  ushort uVar1;
  undefined8 uVar2;
  WCHAR aWStack_98 [64];
  uint local_18;
  
  local_18 = DAT_00055374;
  uVar1 = *(ushort *)(param_1 + 0x22);
  uVar2 = __fptodp(*(undefined4 *)(param_1 + 0x30));
  wsprintfW(aWStack_98,L"%5.1f(%04X)",(int)uVar2,(int)((ulonglong)uVar2 >> 0x20),(uint)uVar1);
  FUN_0003a3c0(param_1,param_2,7,0x12,0x1c,0xb4b4b4,0xffffff,0,L"Beep",aWStack_98);
  FUN_00043604(local_18);
  return;
}



/* 0003a964 FUN_0003a964 */

/* Boundary evidence: original MIPS .pdata 0003a964..0003a9db. Semantic name remains unreviewed. */

void FUN_0003a964(int param_1,HDC param_2)

{
  wchar_t *pwVar1;
  
  if (*(int *)(param_1 + 0x10) == 1) {
    pwVar1 = L"MICOM";
  }
  else {
    pwVar1 = L"PC";
  }
  FUN_0003a3c0(param_1,param_2,8,0xc,0x1a,0xb4b4b4,0xffffff,0,L"GUI SELECT",pwVar1);
  return;
}



/* 0003a9dc FUN_0003a9dc */

/* Boundary evidence: original MIPS .pdata 0003a9dc..0003abc3. Semantic name remains unreviewed. */

void FUN_0003a9dc(int param_1,HDC param_2)

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
  FUN_0003a114(param_1,hdc,&local_30,0);
  FUN_0003a1ac(param_1,hdc,0,0x24,0xffffff,0,L"Debug Mode - Audio");
  FUN_0003a1ac(param_1,hdc,1,0x18,0xffffff,0,L"VOL");
  FUN_0003a1ac(param_1,hdc,2,0x20,0xffffff,0,L"X");
  FUN_0003a1ac(param_1,hdc,3,0x1c,0xffffff,0x505050,L"SOURCE GAIN");
  FUN_0003a674(param_1,hdc);
  FUN_0003a730(param_1,hdc);
  FUN_0003a7ec(param_1,hdc);
  FUN_0003a8a8(param_1,hdc);
  FUN_0003a964(param_1,hdc);
  BitBlt(param_2,0,0,800,0x1e0,hdc,0,0,0xcc0020);
  SelectObject(hdc,h_00);
  DeleteObject(h);
  DeleteDC(hdc);
  return;
}



/* 0003abc4 FUN_0003abc4 */

void FUN_0003abc4(undefined4 param_1,int param_2,int param_3)

{
  uint uVar1;
  int *piVar2;
  
  uVar1 = 0;
  piVar2 = &DAT_00051ca4;
  while ((((param_2 <= *piVar2 || (piVar2[2] <= param_2)) || (param_3 <= piVar2[1])) ||
         (piVar2[3] <= param_3))) {
    uVar1 = uVar1 + 1;
    piVar2 = piVar2 + 4;
    if (8 < uVar1) {
      return;
    }
  }
  return;
}



/* 0003ac30 FUN_0003ac30 */

/* Boundary evidence: original MIPS .pdata 0003ac30..0003adbb. Semantic name remains unreviewed. */

void FUN_0003ac30(double param_1,int param_2,int param_3,int param_4)

{
  uint uVar1;
  HDC hDC;
  undefined1 local_28 [8];
  RECT local_20;
  
  uVar1 = FUN_0003abc4(param_2,param_3,param_4);
  if (uVar1 == 1) {
    *(undefined4 *)(param_2 + 0x14) = 1;
LAB_0003ad80:
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
      FUN_00039db4(param_1,param_2);
      hDC = GetDC(*(HWND *)(param_2 + 0xc));
      FUN_0003a674(param_2,hDC);
      FUN_0003a730(param_2,hDC);
      FUN_0003a7ec(param_2,hDC);
      FUN_0003a8a8(param_2,hDC);
    }
    else {
      if (uVar1 < 4) {
        return;
      }
      if (uVar1 < 8) {
        *(uint *)(param_2 + 0x14) = uVar1;
        goto LAB_0003ad80;
      }
      if (uVar1 != 8) {
        return;
      }
      if (*(int *)(param_2 + 0x10) == 1) {
        local_28[0] = 1;
        FUN_00015b90(DAT_000553cc,0,0x30,(int)local_28,1,0x32);
        *(undefined4 *)(param_2 + 0x10) = 0;
      }
      else {
        local_28[0] = 0;
        FUN_00015b90(DAT_000553cc,0,0x30,(int)local_28,1,0x32);
        *(undefined4 *)(param_2 + 0x10) = 1;
      }
      hDC = GetDC(*(HWND *)(param_2 + 0xc));
      FUN_0003a964(param_2,hDC);
    }
    ReleaseDC(*(HWND *)(param_2 + 0xc),hDC);
  }
  return;
}



/* 0003adbc FUN_0003adbc */

/* Boundary evidence: original MIPS .pdata 0003adbc..0003b12f. Semantic name remains unreviewed. */

void FUN_0003adbc(double param_1,double param_2,int param_3)

{
  undefined2 uVar1;
  undefined4 uVar2;
  HDC pHVar3;
  int iVar4;
  undefined8 uVar5;
  undefined1 local_20;
  undefined1 local_1f;
  undefined1 local_1e;
  undefined1 local_1d;
  
  iVar4 = *(int *)(param_3 + 0x14);
  if (iVar4 == 1) {
    FUN_00012334(DAT_00055384,3);
  }
  else {
    if (iVar4 == 4) {
      uVar5 = __fptodp(*(undefined4 *)(param_3 + 0x24));
      uVar5 = __dpsub((int)uVar5,(int)((ulonglong)uVar5 >> 0x20),0x9999999a,0x3fc99999);
      uVar2 = __dptofp((int)uVar5,(int)((ulonglong)uVar5 >> 0x20));
      *(undefined4 *)(param_3 + 0x24) = uVar2;
      uVar1 = FUN_00039d20(param_1,param_2,param_3,uVar2);
      local_20 = (undefined1)((ushort)uVar1 >> 8);
      *(undefined2 *)(param_3 + 0x1c) = uVar1;
      local_1f = (undefined1)uVar1;
      FUN_00015b90(DAT_000553cc,2,0xd102d,(int)&local_20,2,200);
      pHVar3 = GetDC(*(HWND *)(param_3 + 0xc));
      FUN_0003a674(param_3,pHVar3);
    }
    else if (iVar4 == 5) {
      uVar5 = __fptodp(*(undefined4 *)(param_3 + 0x28));
      uVar5 = __dpsub((int)uVar5,(int)((ulonglong)uVar5 >> 0x20),0x9999999a,0x3fc99999);
      uVar2 = __dptofp((int)uVar5,(int)((ulonglong)uVar5 >> 0x20));
      *(undefined4 *)(param_3 + 0x28) = uVar2;
      uVar1 = FUN_00039d20(param_1,param_2,param_3,uVar2);
      local_20 = (undefined1)((ushort)uVar1 >> 8);
      *(undefined2 *)(param_3 + 0x1e) = uVar1;
      local_1f = (undefined1)uVar1;
      FUN_00015b90(DAT_000553cc,2,0xd105e,(int)&local_20,2,200);
      pHVar3 = GetDC(*(HWND *)(param_3 + 0xc));
      FUN_0003a730(param_3,pHVar3);
    }
    else {
      if (iVar4 != 6) {
        if (iVar4 != 7) {
          return;
        }
        uVar5 = __fptodp(*(undefined4 *)(param_3 + 0x30));
        uVar5 = __dpsub((int)uVar5,(int)((ulonglong)uVar5 >> 0x20),0x9999999a,0x3fc99999);
        uVar2 = __dptofp((int)uVar5,(int)((ulonglong)uVar5 >> 0x20));
        *(undefined4 *)(param_3 + 0x30) = uVar2;
        uVar1 = FUN_00039d20(param_1,param_2,param_3,uVar2);
        *(undefined2 *)(param_3 + 0x22) = uVar1;
        local_20 = (undefined1)((ushort)uVar1 >> 8);
        local_1f = (undefined1)uVar1;
        local_1e = local_20;
        local_1d = local_1f;
        FUN_00015b90(DAT_000553cc,2,0xd10d5,(int)&local_20,4,200);
        pHVar3 = GetDC(*(HWND *)(param_3 + 0xc));
        FUN_0003a8a8(param_3,pHVar3);
        ReleaseDC(*(HWND *)(param_3 + 0xc),pHVar3);
        local_1f = (undefined1)(DAT_00057364 & 0x3f);
        local_20 = 3;
        if ((DAT_00057364 & 0x3f) < 10) {
          local_1f = 10;
        }
        FUN_00015f10(DAT_000553cc,5,1,0x40,(int)&local_20,2,100);
        return;
      }
      uVar5 = __fptodp(*(undefined4 *)(param_3 + 0x2c));
      uVar5 = __dpsub((int)uVar5,(int)((ulonglong)uVar5 >> 0x20),0x9999999a,0x3fc99999);
      uVar2 = __dptofp((int)uVar5,(int)((ulonglong)uVar5 >> 0x20));
      *(undefined4 *)(param_3 + 0x2c) = uVar2;
      uVar1 = FUN_00039d20(param_1,param_2,param_3,uVar2);
      local_20 = (undefined1)((ushort)uVar1 >> 8);
      *(undefined2 *)(param_3 + 0x20) = uVar1;
      local_1f = (undefined1)uVar1;
      FUN_00015b90(DAT_000553cc,2,0xd105f,(int)&local_20,2,200);
      pHVar3 = GetDC(*(HWND *)(param_3 + 0xc));
      FUN_0003a7ec(param_3,pHVar3);
    }
    ReleaseDC(*(HWND *)(param_3 + 0xc),pHVar3);
  }
  return;
}



/* 0003b130 FUN_0003b130 */

/* Boundary evidence: original MIPS .pdata 0003b130..0003b4a3. Semantic name remains unreviewed. */

void FUN_0003b130(double param_1,double param_2,int param_3)

{
  undefined2 uVar1;
  undefined4 uVar2;
  HDC pHVar3;
  int iVar4;
  undefined8 uVar5;
  undefined1 local_20;
  undefined1 local_1f;
  undefined1 local_1e;
  undefined1 local_1d;
  
  iVar4 = *(int *)(param_3 + 0x14);
  if (iVar4 == 1) {
    FUN_00012334(DAT_00055384,2);
  }
  else {
    if (iVar4 == 4) {
      uVar5 = __fptodp(*(undefined4 *)(param_3 + 0x24));
      uVar5 = __dpadd((int)uVar5,(int)((ulonglong)uVar5 >> 0x20),0x9999999a,0x3fc99999);
      uVar2 = __dptofp((int)uVar5,(int)((ulonglong)uVar5 >> 0x20));
      *(undefined4 *)(param_3 + 0x24) = uVar2;
      uVar1 = FUN_00039d20(param_1,param_2,param_3,uVar2);
      local_20 = (undefined1)((ushort)uVar1 >> 8);
      *(undefined2 *)(param_3 + 0x1c) = uVar1;
      local_1f = (undefined1)uVar1;
      FUN_00015b90(DAT_000553cc,2,0xd102d,(int)&local_20,2,200);
      pHVar3 = GetDC(*(HWND *)(param_3 + 0xc));
      FUN_0003a674(param_3,pHVar3);
    }
    else if (iVar4 == 5) {
      uVar5 = __fptodp(*(undefined4 *)(param_3 + 0x28));
      uVar5 = __dpadd((int)uVar5,(int)((ulonglong)uVar5 >> 0x20),0x9999999a,0x3fc99999);
      uVar2 = __dptofp((int)uVar5,(int)((ulonglong)uVar5 >> 0x20));
      *(undefined4 *)(param_3 + 0x28) = uVar2;
      uVar1 = FUN_00039d20(param_1,param_2,param_3,uVar2);
      local_20 = (undefined1)((ushort)uVar1 >> 8);
      *(undefined2 *)(param_3 + 0x1e) = uVar1;
      local_1f = (undefined1)uVar1;
      FUN_00015b90(DAT_000553cc,2,0xd105e,(int)&local_20,2,200);
      pHVar3 = GetDC(*(HWND *)(param_3 + 0xc));
      FUN_0003a730(param_3,pHVar3);
    }
    else {
      if (iVar4 != 6) {
        if (iVar4 != 7) {
          return;
        }
        uVar5 = __fptodp(*(undefined4 *)(param_3 + 0x30));
        uVar5 = __dpadd((int)uVar5,(int)((ulonglong)uVar5 >> 0x20),0x9999999a,0x3fc99999);
        uVar2 = __dptofp((int)uVar5,(int)((ulonglong)uVar5 >> 0x20));
        *(undefined4 *)(param_3 + 0x30) = uVar2;
        uVar1 = FUN_00039d20(param_1,param_2,param_3,uVar2);
        *(undefined2 *)(param_3 + 0x22) = uVar1;
        local_20 = (undefined1)((ushort)uVar1 >> 8);
        local_1f = (undefined1)uVar1;
        local_1e = local_20;
        local_1d = local_1f;
        FUN_00015b90(DAT_000553cc,2,0xd10d5,(int)&local_20,4,200);
        pHVar3 = GetDC(*(HWND *)(param_3 + 0xc));
        FUN_0003a8a8(param_3,pHVar3);
        ReleaseDC(*(HWND *)(param_3 + 0xc),pHVar3);
        local_1f = (undefined1)(DAT_00057364 & 0x3f);
        local_20 = 3;
        if ((DAT_00057364 & 0x3f) < 10) {
          local_1f = 10;
        }
        FUN_00015f10(DAT_000553cc,5,1,0x40,(int)&local_20,2,100);
        return;
      }
      uVar5 = __fptodp(*(undefined4 *)(param_3 + 0x2c));
      uVar5 = __dpadd((int)uVar5,(int)((ulonglong)uVar5 >> 0x20),0x9999999a,0x3fc99999);
      uVar2 = __dptofp((int)uVar5,(int)((ulonglong)uVar5 >> 0x20));
      *(undefined4 *)(param_3 + 0x2c) = uVar2;
      uVar1 = FUN_00039d20(param_1,param_2,param_3,uVar2);
      local_20 = (undefined1)((ushort)uVar1 >> 8);
      *(undefined2 *)(param_3 + 0x20) = uVar1;
      local_1f = (undefined1)uVar1;
      FUN_00015b90(DAT_000553cc,2,0xd105f,(int)&local_20,2,200);
      pHVar3 = GetDC(*(HWND *)(param_3 + 0xc));
      FUN_0003a7ec(param_3,pHVar3);
    }
    ReleaseDC(*(HWND *)(param_3 + 0xc),pHVar3);
  }
  return;
}



/* 0003b4a4 FUN_0003b4a4 */

/* Boundary evidence: original MIPS .pdata 0003b4a4..0003b523. Semantic name remains unreviewed. */

void FUN_0003b4a4(undefined4 param_1)

{
  undefined4 *puVar1;
  
  FUN_0003ea24();
  puVar1 = (undefined4 *)__2_YAPAXI_Z(0x34);
  if (puVar1 == (undefined4 *)0x0) {
    DAT_00059388 = (undefined4 *)0x0;
  }
  else {
    DAT_00059388 = FUN_00039bc4(puVar1);
  }
  FUN_0003e4e0((int)DAT_00059388,DAT_00055600,param_1);
  return;
}



/* 0003b524 Unwind@0003b524 */

/* Boundary evidence: original MIPS .pdata 0003b524..0003b553. Semantic name remains unreviewed. */

void Unwind_0003b524(void)

{
  int in_v0;
  
  __3_YAXPAX_Z(*(undefined4 *)(in_v0 + -0x18));
  return;
}



/* 0003b554 FUN_0003b554 */

/* Boundary evidence: original MIPS .pdata 0003b554..0003b5ab. Semantic name remains unreviewed. */

undefined4 * FUN_0003b554(undefined4 *param_1,uint param_2)

{
  *param_1 = &PTR_FUN_00051d34;
  FUN_0003e4d0(param_1);
  if ((param_2 & 1) != 0) {
    __3_YAXPAX_Z(param_1);
  }
  return param_1;
}



/* 0003b5ac FUN_0003b5ac */

/* Boundary evidence: original MIPS .pdata 0003b5ac..0003b5cf. Semantic name remains unreviewed. */

void FUN_0003b5ac(double param_1,int param_2)

{
  DAT_00059354 = 1;
  FUN_00039db4(param_1,param_2);
  return;
}



/* 0003b5d0 FUN_0003b5d0 */

undefined4 *
FUN_0003b5d0(undefined4 *param_1,undefined4 param_2,undefined4 param_3,uint param_4,
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



/* 0003b604 FUN_0003b604 */

void FUN_0003b604(int param_1,int param_2)

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



/* 0003b664 FUN_0003b664 */

void FUN_0003b664(int param_1)

{
  *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + 0x30;
  *(int *)(param_1 + 8) = *(int *)(param_1 + 0x1c) * *(int *)(param_1 + 0x18) + 0x18;
  return;
}



/* 0003b68c FUN_0003b68c */

void FUN_0003b68c(int param_1)

{
  *(undefined4 *)(param_1 + 0x1c) = 1;
  *(int *)(param_1 + 8) = *(int *)(param_1 + 0x18) + 0x18;
  *(undefined4 *)(param_1 + 0xc) = 0x18;
  return;
}



/* 0003b6ac FUN_0003b6ac */

/* Boundary evidence: original MIPS .pdata 0003b6ac..0003b867. Semantic name remains unreviewed. */

HWND FUN_0003b6ac(undefined4 *param_1,int param_2,LPCWSTR param_3,int param_4,HMENU param_5)

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
                               param_4 * 0x30 + -2,0x2e,(HWND)param_1[1],param_5,(HINSTANCE)*param_1
                               ,(LPVOID)0x0);
    }
    else {
      if (param_2 != 2) {
        return (HWND)0x0;
      }
      pHVar1 = CreateWindowExW(0,L"button",param_3,0x50002000,param_1[2] + 2,param_1[3] + 2,
                               param_4 * 0x30 + -2,0x2e,(HWND)param_1[1],param_5,(HINSTANCE)*param_1
                               ,(LPVOID)0x0);
    }
    param_1[2] = param_1[2] + param_4 * 0x30;
  }
  return pHVar1;
}



/* 0003b868 FUN_0003b868 */

/* Boundary evidence: original MIPS .pdata 0003b868..0003b8d3. Semantic name remains unreviewed. */

undefined4 * FUN_0003b868(undefined4 *param_1)

{
  FUN_0003e4a8(param_1);
  *param_1 = &PTR_FUN_00051ebc;
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[6] = 0;
  param_1[7] = 0;
  param_1[8] = 0;
  param_1[0xc] = 0;
  param_1[0xd] = 0;
  param_1[0xf] = 0;
  param_1[0x10] = 0;
  param_1[0x11] = 0;
  param_1[0x12] = 0;
  param_1[0x13] = 0;
  *(undefined1 *)(param_1 + 0x14) = 0;
  return param_1;
}



/* 0003b8d4 FUN_0003b8d4 */

/* Boundary evidence: original MIPS .pdata 0003b8d4..0003bbb7. Semantic name remains unreviewed. */

undefined4 FUN_0003b8d4(int param_1,int param_2,undefined4 param_3,char *param_4)

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
  
  local_30 = DAT_00055374;
  local_b0 = L'\0';
  uVar4 = 0;
  memset(auStack_ae,0,0x7e);
  wsprintfW(&local_b0,L"Start-RD-%s",param_3);
  SetWindowTextW(*(HWND *)(param_1 + 0x28),&local_b0);
  _File = fopen(param_4,"wb");
  if (_File == (FILE *)0x0) {
    NKDbgPrintfW(L"File open error.\r\n");
    wsprintfW(&local_b0,L"ERR-open-RD-%s",param_3);
    SetWindowTextW(*(HWND *)(param_1 + 0x28),&local_b0);
LAB_0003bb78:
    FUN_00043604(local_30);
    uVar5 = 0;
  }
  else {
    uVar3 = 0;
    uVar5 = 1;
    do {
      local_f0[0] = (byte)uVar3;
      uVar1 = FUN_00016068(DAT_000553cc,0xd,param_2,local_f0,0x40,100);
      if (uVar1 == 0) {
        NKDbgPrintfW(L"send timeout.");
        wsprintfW(&local_b0,L"ERR-send-RD-%s",param_3);
        SetWindowTextW(*(HWND *)(param_1 + 0x28),&local_b0);
        fclose(_File);
        goto LAB_0003bb78;
      }
      if (uVar3 == 0) {
        if (param_2 == 0x24) {
          uVar4 = 0x20;
        }
        else if (param_2 == 0x25) {
          uVar4 = (uint)local_ec * 0x100 + (uint)local_eb;
          DAT_0005938c = (ushort)uVar4;
        }
        else if (param_2 == 0x26) {
          uVar4 = DAT_0005938c + 0xfcdd & 0xffff;
        }
        else if (param_2 == 0x27) {
          uVar4 = 0x395;
        }
        else if (param_2 == 0x28) {
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
        SetWindowTextW(*(HWND *)(param_1 + 0x28),&local_b0);
        uVar5 = 0;
        break;
      }
      if ((int)(local_f0[0] - 3) <= (int)uVar4) break;
      uVar3 = uVar3 + 1 & 0xff;
      uVar4 = uVar4 + 0xffc4 & 0xffff;
    } while ((int)(uint)local_ed <= (int)(uVar3 - 1));
    fclose(_File);
    FUN_00043604(local_30);
  }
  return uVar5;
}



/* 0003bbb8 FUN_0003bbb8 */

/* Boundary evidence: original MIPS .pdata 0003bbb8..0003c203. Semantic name remains unreviewed. */

undefined4 FUN_0003bbb8(int param_1,int param_2,undefined4 param_3,char *param_4)

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
  
  local_30 = DAT_00055374;
  local_418 = 0;
  memset(local_417,0,999);
  local_498 = L'\0';
  _ElementSize = 0;
  memset(auStack_496,0,0x7e);
  wsprintfW(&local_498,L"Start-WD-%s",param_3);
  SetWindowTextW(*(HWND *)(param_1 + 0x2c),&local_498);
  _File = fopen(param_4,"rb");
  if (_File == (FILE *)0x0) {
    NKDbgPrintfW(L"File open error.\r\n");
    wsprintfW(&local_498,L"ERR-open-WD-%s",param_3);
    SetWindowTextW(*(HWND *)(param_1 + 0x2c),&local_498);
    goto LAB_0003bc94;
  }
  if (param_2 == 0x24) {
LAB_0003bce8:
    _ElementSize = 0x20;
  }
  else if (param_2 == 0x25) {
    _ElementSize = 0x23;
  }
  else if (param_2 == 0x26) {
    _ElementSize = (int)(DAT_00059390 - 0x323) % 0x80 & 0xff;
  }
  else if (param_2 == 0x27) {
    _ElementSize = 0x15;
  }
  else if (param_2 == 0x28) goto LAB_0003bce8;
  uVar3 = 1;
  sVar1 = fread(&local_418,_ElementSize,1,_File);
  if (sVar1 != 0) {
    if (param_2 == 0x25) {
      DAT_00059390 = (ushort)local_418 * 0x100 + (ushort)local_417[0];
    }
    bVar2 = (byte)_ElementSize;
    if (param_2 == 0x24) {
      FUN_00015b90(DAT_000553cc,0xf,0x2b,(int)&local_418,bVar2,300);
LAB_0003c1c0:
      fclose(_File);
      FUN_00043604(local_30);
      return uVar3;
    }
    if (param_2 != 0x25) {
      if (param_2 == 0x26) {
        if (DAT_00059390 == 0) {
          NKDbgPrintfW(L"File write error.");
          wsprintfW(&local_498,L"ERR-save-WD-%s",param_3);
          SetWindowTextW(*(HWND *)(param_1 + 0x2c),&local_498);
          uVar3 = 0;
        }
        else {
          FUN_00015b90(DAT_000553cc,0xf,0x33,(int)&local_418,0x80,300);
          FUN_00015b90(DAT_000553cc,0xf,0x34,(int)auStack_398,0x80,300);
          FUN_00015b90(DAT_000553cc,0xf,0x35,(int)auStack_318,0x80,300);
          FUN_00015b90(DAT_000553cc,0xf,0x36,(int)auStack_298,0x80,300);
          FUN_00015b90(DAT_000553cc,0xf,0x37,(int)auStack_218,0x80,300);
          FUN_00015b90(DAT_000553cc,0xf,0x38,(int)auStack_198,0x80,300);
          FUN_00015b90(DAT_000553cc,0xf,0x39,(int)auStack_118,bVar2,300);
        }
      }
      else if (param_2 == 0x27) {
        FUN_00015b90(DAT_000553cc,0xf,0x21,(int)&local_418,0x80,300);
        FUN_00015b90(DAT_000553cc,0xf,0x22,(int)auStack_398,0x80,300);
        FUN_00015b90(DAT_000553cc,0xf,0x23,(int)auStack_318,0x80,300);
        FUN_00015b90(DAT_000553cc,0xf,0x24,(int)auStack_298,0x80,300);
        FUN_00015b90(DAT_000553cc,0xf,0x25,(int)auStack_218,0x80,300);
        FUN_00015b90(DAT_000553cc,0xf,0x26,(int)auStack_198,0x80,300);
        FUN_00015b90(DAT_000553cc,0xf,0x27,(int)auStack_118,0x80,300);
        FUN_00015b90(DAT_000553cc,0xf,0x28,(int)auStack_98,bVar2,300);
      }
      else if (param_2 == 0x28) {
        FUN_00015b90(DAT_000553cc,0xf,0x11,(int)&local_418,0x80,300);
        FUN_00015b90(DAT_000553cc,0xf,0x12,(int)auStack_398,0x80,300);
        FUN_00015b90(DAT_000553cc,0xf,0x13,(int)auStack_318,0x80,300);
        FUN_00015b90(DAT_000553cc,0xf,0x14,(int)auStack_298,0x80,300);
        FUN_00015b90(DAT_000553cc,0xf,0x15,(int)auStack_218,0x80,300);
        FUN_00015b90(DAT_000553cc,0xf,0x16,(int)auStack_198,0x80,300);
        FUN_00015b90(DAT_000553cc,0xf,0x17,(int)auStack_118,0x80,300);
        FUN_00015b90(DAT_000553cc,0xf,0x18,(int)auStack_98,bVar2,300);
      }
      goto LAB_0003c1c0;
    }
    if (DAT_00059390 != 0) {
      FUN_00015b90(DAT_000553cc,0xf,0x2c,(int)&local_418,0x80,300);
      FUN_00015b90(DAT_000553cc,0xf,0x2d,(int)auStack_398,0x80,300);
      FUN_00015b90(DAT_000553cc,0xf,0x2e,(int)auStack_318,0x80,300);
      FUN_00015b90(DAT_000553cc,0xf,0x2f,(int)auStack_298,0x80,300);
      FUN_00015b90(DAT_000553cc,0xf,0x30,(int)auStack_218,0x80,300);
      FUN_00015b90(DAT_000553cc,0xf,0x31,(int)auStack_198,0x80,300);
      FUN_00015b90(DAT_000553cc,0xf,0x32,(int)auStack_118,bVar2,300);
      goto LAB_0003c1c0;
    }
  }
  NKDbgPrintfW(L"File write error.");
  wsprintfW(&local_498,L"ERR-save-WD-%s",param_3);
  SetWindowTextW(*(HWND *)(param_1 + 0x2c),&local_498);
  fclose(_File);
LAB_0003bc94:
  FUN_00043604(local_30);
  return 0;
}



/* 0003c204 FUN_0003c204 */

/* Boundary evidence: original MIPS .pdata 0003c204..0003c2ab. Semantic name remains unreviewed. */

void FUN_0003c204(int param_1)

{
  undefined4 uVar1;
  char local_a0 [8];
  WCHAR aWStack_98 [64];
  uint local_18;
  
  local_18 = DAT_00055374;
  FUN_00016068(DAT_000553cc,1,6,local_a0,1,0x32);
  uVar1 = 0x41;
  if (local_a0[0] != '\x01') {
    uVar1 = 0x50;
  }
  wsprintfW(aWStack_98,L"ANT(%c)",uVar1);
  SetWindowTextW(*(HWND *)(param_1 + 0x20),aWStack_98);
  *(uint *)(param_1 + 0x24) = (uint)(local_a0[0] == '\x01');
  FUN_00043604(local_18);
  return;
}



/* 0003c2ac FUN_0003c2ac */

/* Boundary evidence: original MIPS .pdata 0003c2ac..0003d303. Semantic name remains unreviewed. */

void FUN_0003c2ac(int param_1,int param_2)

{
  int iVar1;
  HWND hWnd;
  wchar_t *pwVar2;
  byte bVar3;
  LPCWSTR lpString;
  char *pcVar4;
  undefined4 uVar5;
  uint uVar6;
  byte *pbVar7;
  undefined1 *puVar8;
  undefined8 uVar9;
  char local_3d8;
  char local_3d7;
  byte local_3d6;
  bool local_3d5;
  byte local_3d4 [7];
  undefined1 local_3cd;
  undefined1 local_3cc;
  undefined1 local_3cb;
  undefined1 local_3ca [2];
  undefined1 local_3c8;
  undefined1 local_3c7;
  undefined1 local_3c6;
  undefined1 local_3c5;
  byte local_3c4;
  byte local_3c3;
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
  byte local_3b6;
  undefined1 local_3b5;
  undefined1 local_3b4;
  undefined1 local_3b3;
  undefined1 local_3b2;
  byte local_3b1;
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
  WCHAR local_3a0;
  undefined1 auStack_39e [126];
  WCHAR local_320;
  undefined1 auStack_31e [126];
  WCHAR aWStack_2a0 [64];
  WCHAR aWStack_220 [64];
  WCHAR aWStack_1a0 [64];
  WCHAR aWStack_120 [64];
  WCHAR aWStack_a0 [64];
  uint local_20;
  
  local_20 = DAT_00055374;
  switch(param_2) {
  case 1:
    local_3d8 = *(int *)(param_1 + 0x24) != 1;
    FUN_00015b90(DAT_000553cc,1,6,(int)&local_3d8,1,0x32);
    FUN_00015f10(DAT_000553cc,1,1,0x19,0,0,100);
    uVar5 = 0x41;
    if (local_3d8 != '\x01') {
      uVar5 = 0x50;
    }
    wsprintfW(aWStack_120,L"ANT(%c)",uVar5);
    SetWindowTextW(*(HWND *)(param_1 + 0x20),aWStack_120);
    *(uint *)(param_1 + 0x24) = (uint)(local_3d8 == '\x01');
    break;
  case 2:
    local_3cd = 0;
    FUN_00015f10(DAT_000553cc,1,1,0x1f,(int)&local_3cd,1,100);
    break;
  case 3:
    FUN_00016068(DAT_000553cc,9,0x10,&local_3b2,2,0x32);
    uVar9 = __ultodp(local_3b2);
    uVar9 = __dpmul((int)uVar9,(int)((ulonglong)uVar9 >> 0x20),0x9999999a,0x3fb99999);
    wsprintfW(aWStack_2a0,L"BAT : %6.2fV(%d)",(int)uVar9,(int)((ulonglong)uVar9 >> 0x20),
              (uint)local_3b1);
    hWnd = *(HWND *)(param_1 + 0x10);
    lpString = aWStack_2a0;
    goto LAB_0003c728;
  case 4:
    FUN_00016068(DAT_000553cc,1,0xf0,&local_3c4,2,0x32);
    wsprintfW(aWStack_220,L"%d,%d",(uint)local_3c4,(uint)local_3c3);
    hWnd = *(HWND *)(param_1 + 0x1c);
    lpString = aWStack_220;
    goto LAB_0003c728;
  case 6:
    local_3d4[3] = 0;
    NKDbgPrintfW(L"\n==>CONTROL_REQ_CAN_CONF - DSI config\n");
    FUN_00015f10(DAT_000553cc,1,1,10,(int)(local_3d4 + 3),1,100);
    break;
  case 7:
    local_3d4[1] = 1;
    NKDbgPrintfW(L"\n==>CONTROL_REQ_CLEAR_VIRGIN - Clear Virgin\n");
    FUN_00015f10(DAT_000553cc,1,1,0x1f,(int)(local_3d4 + 1),1,100);
    break;
  case 8:
    local_3d4[5] = 1;
    NKDbgPrintfW(
                L"\n==>CONTROL_REQ_CLR_ALLCNF - All clear CAN configuration including Map code(0x2D2D) forcely..\n"
                );
    FUN_00015f10(DAT_000553cc,0xd,1,2,(int)(local_3d4 + 5),1,0xfa);
    break;
  case 9:
    local_3cb = 2;
    NKDbgPrintfW(
                L"\n==>CONTROL_REQ_CLR_ALLCNF2 - All clear CAN configuration including Map code(0x2A2A) forcely..\n"
                );
    FUN_00015f10(DAT_000553cc,0xd,1,2,(int)&local_3cb,1,0xfa);
    break;
  case 10:
    local_3d4[2] = 3;
    NKDbgPrintfW(L"\n==>CONTROL_REQ_RVC_SWRC - Set active....RVC, SWRC \n");
    FUN_00015f10(DAT_000553cc,0xd,1,2,(int)(local_3d4 + 2),1,0xfa);
    break;
  case 0xb:
    local_3a0 = L'\0';
    memset(auStack_39e,0,0x7e);
    if (DAT_00059393 == '\0') {
      pcVar4 = "\\Storage Card2\\ReadDsiDataConfig.bin";
      pwVar2 = L"CNF";
      iVar1 = 0x24;
    }
    else if (DAT_00059393 == '\x01') {
      pcVar4 = "\\Storage Card2\\ReadDsiDataPact1.bin";
      pwVar2 = L"PACT1";
      iVar1 = 0x25;
    }
    else if (DAT_00059393 == '\x02') {
      pcVar4 = "\\Storage Card2\\ReadDsiDataPact2.bin";
      pwVar2 = L"PACT2";
      iVar1 = 0x26;
    }
    else if (DAT_00059393 == '\x03') {
      pcVar4 = "\\Storage Card2\\ReadDsiDataAudio.bin";
      pwVar2 = L"AUDIO";
      iVar1 = 0x27;
    }
    else {
      if (DAT_00059393 != '\x04') {
        DAT_00059393 = '\0';
        wsprintfW(&local_3a0,L"Complete-RD-DSI");
        hWnd = *(HWND *)(param_1 + 0x28);
        lpString = &local_3a0;
        goto LAB_0003c728;
      }
      pcVar4 = "\\Storage Card2\\ReadDsiDataRadio.bin";
      pwVar2 = L"RADIO";
      iVar1 = 0x28;
    }
    iVar1 = FUN_0003b8d4(param_1,iVar1,pwVar2,pcVar4);
    if (iVar1 == 0) {
      DAT_00059393 = '\0';
      break;
    }
    DAT_00059393 = DAT_00059393 + '\x01';
    goto LAB_0003c4d4;
  case 0xc:
    local_320 = L'\0';
    memset(auStack_31e,0,0x7e);
    if (DAT_00059392 == '\0') {
      pcVar4 = "\\Storage Card2\\WriteDsiDataConfig.bin";
      pwVar2 = L"CNF";
      iVar1 = 0x24;
    }
    else if (DAT_00059392 == '\x01') {
      pcVar4 = "\\Storage Card2\\WriteDsiDataPact1.bin";
      pwVar2 = L"PACT1";
      iVar1 = 0x25;
    }
    else if (DAT_00059392 == '\x02') {
      pcVar4 = "\\Storage Card2\\WriteDsiDataPact2.bin";
      pwVar2 = L"PACT2";
      iVar1 = 0x26;
    }
    else if (DAT_00059392 == '\x03') {
      pcVar4 = "\\Storage Card2\\WriteDsiDataAudio.bin";
      pwVar2 = L"AUDIO";
      iVar1 = 0x27;
    }
    else {
      if (DAT_00059392 != '\x04') {
        DAT_00059392 = '\0';
        wsprintfW(&local_320,L"Complete-WD-DSI");
        hWnd = *(HWND *)(param_1 + 0x2c);
        lpString = &local_320;
        goto LAB_0003c728;
      }
      pcVar4 = "\\Storage Card2\\WriteDsiDataRadio.bin";
      pwVar2 = L"RADIO";
      iVar1 = 0x28;
    }
    iVar1 = FUN_0003bbb8(param_1,iVar1,pwVar2,pcVar4);
    if (iVar1 == 0) {
      DAT_00059392 = '\0';
      break;
    }
    DAT_00059392 = DAT_00059392 + '\x01';
LAB_0003c4d4:
    PostMessageW(*(HWND *)(param_1 + 0xc),0xb,0,0);
    break;
  case 0xd:
    local_3d6 = 0;
    FUN_00016068(DAT_000553cc,9,0x42,&local_3d6,1,0x96);
    wsprintfW(aWStack_1a0,L"ILL[%d]",(uint)local_3d6);
    hWnd = *(HWND *)(param_1 + 0x30);
    lpString = aWStack_1a0;
    goto LAB_0003c728;
  case 0xe:
    local_3ae = 0;
    local_3ad = 0x55;
    NKDbgPrintfW(L"Set ULC1.0 EU region..\n");
    FUN_00015b90(DAT_000553cc,1,0xc9,(int)&local_3ae,2,100);
    break;
  case 0xf:
    local_3c0 = 1;
    local_3bf = 0x55;
    NKDbgPrintfW(L"Set ULC1.0 SA region..\n");
    FUN_00015b90(DAT_000553cc,1,0xc9,(int)&local_3c0,2,100);
    break;
  case 0x10:
    local_3c8 = 2;
    local_3c7 = 0x55;
    NKDbgPrintfW(L"Set ULC1.0 OTH region..\n");
    FUN_00015b90(DAT_000553cc,1,0xc9,(int)&local_3c8,2,100);
    break;
  case 0x11:
    local_3bc = 3;
    local_3bb = 0x55;
    NKDbgPrintfW(L"Set X87 EU region..\n");
    FUN_00015b90(DAT_000553cc,1,0xc9,(int)&local_3bc,2,100);
    break;
  case 0x12:
    local_3b0 = 4;
    local_3af = 0x55;
    NKDbgPrintfW(L"Set X87 SA region..\n");
    FUN_00015b90(DAT_000553cc,1,0xc9,(int)&local_3b0,2,100);
    break;
  case 0x13:
    local_3b8 = 5;
    local_3b7 = 0x55;
    NKDbgPrintfW(L"Set X87 OTH region..\n");
    FUN_00015b90(DAT_000553cc,1,0xc9,(int)&local_3b8,2,100);
    break;
  case 0x14:
    local_3ac = 6;
    local_3ab = 0x55;
    NKDbgPrintfW(L"Set ULC11 M0 EU region.\n");
    FUN_00015b90(DAT_000553cc,1,0xc9,(int)&local_3ac,2,100);
    break;
  case 0x15:
    local_3b4 = 7;
    local_3b3 = 0x55;
    NKDbgPrintfW(L"Set ULC11 M0 SA region..\n");
    FUN_00015b90(DAT_000553cc,1,0xc9,(int)&local_3b4,2,100);
    break;
  case 0x16:
    local_3a8 = 8;
    local_3a7 = 0x55;
    NKDbgPrintfW(L"Set ULC11 M0 OTH region..\n");
    FUN_00015b90(DAT_000553cc,1,0xc9,(int)&local_3a8,2,100);
    break;
  case 0x17:
    local_3aa = 9;
    local_3a9 = 0x55;
    NKDbgPrintfW(L"Set ULC11 MI EU region..\n");
    FUN_00015b90(DAT_000553cc,1,0xc9,(int)&local_3aa,2,100);
    break;
  case 0x18:
    local_3c6 = 10;
    local_3c5 = 0x55;
    NKDbgPrintfW(L"Set ULC11 MI SA region..\n");
    FUN_00015b90(DAT_000553cc,1,0xc9,(int)&local_3c6,2,100);
    break;
  case 0x19:
    local_3c2 = 0xb;
    local_3c1 = 0x55;
    NKDbgPrintfW(L"Set ULC11 MI OTH region..\n");
    FUN_00015b90(DAT_000553cc,1,0xc9,(int)&local_3c2,2,100);
    break;
  case 0x1a:
    local_3be = 0xd;
    local_3bd = 0x55;
    NKDbgPrintfW(L"Set ULC12 M0 SA region..\n");
    FUN_00015b90(DAT_000553cc,1,0xc9,(int)&local_3be,2,100);
    break;
  case 0x1b:
  case 0x1c:
  case 0x1d:
  case 0x1e:
  case 0x1f:
  case 0x20:
  case 0x21:
  case 0x22:
  case 0x23:
  case 0x24:
  case 0x25:
  case 0x26:
  case 0x27:
  case 0x28:
  case 0x29:
  case 0x2a:
  case 0x2b:
  case 0x2c:
  case 0x2d:
    local_3ba = (undefined1)(param_2 + 0xfaU);
    local_3b9 = 0x55;
    NKDbgPrintfW(L"Set ULC1x SKU region [%d].\n",param_2 + 0xfaU & 0xff);
    FUN_00015b90(DAT_000553cc,1,0xc9,(int)&local_3ba,2,100);
    break;
  case 0x2e:
    local_3d4[4] = 4;
    NKDbgPrintfW(L"\n==>CONTROL_REQ_RVC_SWRC2 - Set active....RVC, new SWRC \n");
    FUN_00015f10(DAT_000553cc,0xd,1,2,(int)(local_3d4 + 4),1,0xfa);
    break;
  case 0x2f:
    GetWindowTextW(*(HWND *)(param_1 + 0x34),aWStack_a0,10);
    pwVar2 = L"STB ON";
    iVar1 = wcscmp(aWStack_a0,L"STB ON");
    local_3d5 = iVar1 == 0;
    if (local_3d5) {
      pwVar2 = L"STB OFF";
    }
    SetWindowTextW(*(HWND *)(param_1 + 0x34),pwVar2);
    FUN_00015f10(DAT_000553cc,6,1,3,(int)&local_3d5,1,0xfa);
    break;
  case 0x30:
  case 0x31:
  case 0x32:
  case 0x33:
  case 0x34:
    local_3d4[6] = (char)param_2 + -0x30;
    FUN_00015b90(DAT_000553cc,1,0xca,(int)(local_3d4 + 6),1,100);
    break;
  case 0x35:
    local_3d7 = '\0';
    FUN_00016068(DAT_000553cc,1,0xcb,&local_3d7,1,100);
    NKDbgPrintfW(L"Get LHD Configuration .%d.\n",local_3d7);
    if (local_3d7 == '\0') {
      lpString = L"LHD";
    }
    else {
      lpString = L"RHD";
    }
    hWnd = *(HWND *)(param_1 + 0x38);
LAB_0003c728:
    SetWindowTextW(hWnd,lpString);
    break;
  case 0x36:
    local_3cc = 0;
    FUN_00015b90(DAT_000553cc,1,0xcb,(int)&local_3cc,1,100);
    break;
  case 0x37:
    local_3ca[0] = 1;
    FUN_00015b90(DAT_000553cc,1,0xcb,(int)local_3ca,1,100);
    break;
  case 0x38:
    pbVar7 = (byte *)(param_1 + 0x50);
    FUN_00016068(DAT_000553cc,1,0xcc,pbVar7,1,0xfa);
    *(char *)(param_1 + 0x51) = (char)(*pbVar7 & 7);
    SetWindowTextW(*(HWND *)(param_1 + 0x3c),(LPCWSTR)(&PTR_u_L_100_km_00055338)[*pbVar7 & 7]);
    uVar6 = (*pbVar7 & 0x18) >> 3;
    *(char *)(param_1 + 0x52) = (char)uVar6;
    SetWindowTextW(*(HWND *)(param_1 + 0x40),(LPCWSTR)(&PTR_u_No_Disp_0005534c)[uVar6]);
    uVar6 = (*pbVar7 & 0x20) >> 5;
    *(char *)(param_1 + 0x53) = (char)uVar6;
    SetWindowTextW(*(HWND *)(param_1 + 0x44),(LPCWSTR)(&PTR_u_Deactive_00055358)[uVar6]);
    uVar6 = (*pbVar7 & 0x40) >> 6;
    *(char *)(param_1 + 0x54) = (char)uVar6;
    SetWindowTextW(*(HWND *)(param_1 + 0x48),(LPCWSTR)(&PTR_DAT_00055360)[uVar6]);
    *(byte *)(param_1 + 0x55) = *pbVar7 >> 7;
    SetWindowTextW(*(HWND *)(param_1 + 0x4c),(LPCWSTR)(&PTR_u_Deactive_00055368)[*pbVar7 >> 7]);
    bVar3 = *pbVar7;
    pwVar2 = L"CONTROL_GET_ECO... [0x%02X]\n";
    goto LAB_0003d2d8;
  case 0x39:
    puVar8 = (undefined1 *)(param_1 + 0x50);
    local_3d4[0] = (((*(char *)(param_1 + 0x55) << 1 | *(byte *)(param_1 + 0x54) & 1) << 1 |
                    *(byte *)(param_1 + 0x53) & 1) << 2 | *(byte *)(param_1 + 0x52) & 3) << 3 |
                   *(byte *)(param_1 + 0x51) & 7;
    NKDbgPrintfW(L"CONTROL_SET_ECO... [0x%02X]->",*puVar8);
    FUN_00015b90(DAT_000553cc,1,0xcc,(int)local_3d4,1,0xfa);
    FUN_00016068(DAT_000553cc,1,0xcc,puVar8,1,0xfa);
    local_3b5 = *puVar8;
    local_3b6 = 0x3e;
    FUN_00033058(DAT_00055498,&local_3b6);
    NKDbgPrintfW(L"[0x%02X]/[0x%02X]\n",local_3d4[0],*puVar8);
    break;
  case 0x3a:
    if (*(byte *)(param_1 + 0x51) < 4) {
      *(byte *)(param_1 + 0x51) = *(byte *)(param_1 + 0x51) + 1;
    }
    else {
      *(undefined1 *)(param_1 + 0x51) = 0;
    }
    SetWindowTextW(*(HWND *)(param_1 + 0x3c),
                   (LPCWSTR)(&PTR_u_L_100_km_00055338)[*(byte *)(param_1 + 0x51)]);
    bVar3 = *(byte *)(param_1 + 0x51);
    pwVar2 = L"CONTROL_SET_ADAC... [%d]\n";
    goto LAB_0003d2d8;
  case 0x3b:
    if (*(byte *)(param_1 + 0x52) < 2) {
      *(byte *)(param_1 + 0x52) = *(byte *)(param_1 + 0x52) + 1;
    }
    else {
      *(undefined1 *)(param_1 + 0x52) = 0;
    }
    SetWindowTextW(*(HWND *)(param_1 + 0x40),
                   (LPCWSTR)(&PTR_u_No_Disp_0005534c)[*(byte *)(param_1 + 0x52)]);
    bVar3 = *(byte *)(param_1 + 0x52);
    goto LAB_0003d1e8;
  case 0x3c:
    if (*(char *)(param_1 + 0x53) == '\0') {
      *(undefined1 *)(param_1 + 0x53) = 1;
    }
    else {
      *(undefined1 *)(param_1 + 0x53) = 0;
    }
    SetWindowTextW(*(HWND *)(param_1 + 0x44),
                   (LPCWSTR)(&PTR_u_Deactive_00055358)[*(byte *)(param_1 + 0x53)]);
    bVar3 = *(byte *)(param_1 + 0x53);
LAB_0003d1e8:
    pwVar2 = L"CONTROL_SET_TEMP... [%d]\n";
    goto LAB_0003d2d8;
  case 0x3d:
    if (*(char *)(param_1 + 0x54) == '\0') {
      *(undefined1 *)(param_1 + 0x54) = 1;
    }
    else {
      *(undefined1 *)(param_1 + 0x54) = 0;
    }
    SetWindowTextW(*(HWND *)(param_1 + 0x48),(LPCWSTR)(&PTR_DAT_00055360)[*(byte *)(param_1 + 0x54)]
                  );
    bVar3 = *(byte *)(param_1 + 0x54);
    pwVar2 = L"CONTROL_SET_ENG... [%d]\n";
    goto LAB_0003d2d8;
  case 0x3e:
    if (*(char *)(param_1 + 0x55) == '\0') {
      *(undefined1 *)(param_1 + 0x55) = 1;
    }
    else {
      *(undefined1 *)(param_1 + 0x55) = 0;
    }
    SetWindowTextW(*(HWND *)(param_1 + 0x4c),
                   (LPCWSTR)(&PTR_u_Deactive_00055368)[*(byte *)(param_1 + 0x55)]);
    bVar3 = *(byte *)(param_1 + 0x55);
    pwVar2 = L"CONTROL_SET_ECODISP... [%d]\n";
LAB_0003d2d8:
    NKDbgPrintfW(pwVar2,bVar3);
  }
  FUN_00043604(local_20);
  return;
}



/* 0003d314 FUN_0003d314 */

/* Boundary evidence: original MIPS .pdata 0003d314..0003d37b. Semantic name remains unreviewed. */

void FUN_0003d314(int param_1,int param_2)

{
  WCHAR aWStack_90 [64];
  uint local_10;
  
  local_10 = DAT_00055374;
  if (param_2 == 0) {
    wsprintfW(aWStack_90,L"SPEED : %dcm/s",(uint)*(ushort *)(DAT_00055618 + 0x67e));
    SetWindowTextW(*(HWND *)(param_1 + 0x18),aWStack_90);
  }
  FUN_00043604(local_10);
  return;
}



/* 0003d37c FUN_0003d37c */

/* Boundary evidence: original MIPS .pdata 0003d37c..0003d3d3. Semantic name remains unreviewed. */

undefined4 * FUN_0003d37c(undefined4 *param_1,uint param_2)

{
  *param_1 = &PTR_FUN_00051ebc;
  FUN_0003e4d0(param_1);
  if ((param_2 & 1) != 0) {
    __3_YAXPAX_Z(param_1);
  }
  return param_1;
}



/* 0003d3d4 FUN_0003d3d4 */

/* Boundary evidence: original MIPS .pdata 0003d3d4..0003dacf. Semantic name remains unreviewed. */

void FUN_0003d3d4(int param_1)

{
  undefined4 uVar1;
  uint uVar2;
  HWND pHVar3;
  undefined4 auStack_30 [8];
  
  *(undefined4 *)(DAT_00055498 + 0x18) = *(undefined4 *)(param_1 + 0xc);
  uVar1 = FUN_0003e894();
  uVar2 = FUN_0003e88c();
  FUN_0003b5d0(auStack_30,*(undefined4 *)(param_1 + 4),*(undefined4 *)(param_1 + 0xc),uVar2,uVar1);
  pHVar3 = FUN_0003b6ac(auStack_30,2,L"ANT(X)",2,(HMENU)0x1);
  *(HWND *)(param_1 + 0x20) = pHVar3;
  FUN_0003b6ac(auStack_30,2,L"DSI Config",2,(HMENU)0x6);
  FUN_0003b6ac(auStack_30,2,L"Clear Virgin",2,(HMENU)0x7);
  FUN_0003b6ac(auStack_30,2,L"ClrCnf(2D)",2,(HMENU)0x8);
  FUN_0003b6ac(auStack_30,2,L"ClrCnf(2A)",2,(HMENU)0x9);
  pHVar3 = FUN_0003b6ac(auStack_30,2,L"STB OFF",2,(HMENU)0x2f);
  *(HWND *)(param_1 + 0x34) = pHVar3;
  FUN_0003b664((int)auStack_30);
  pHVar3 = FUN_0003b6ac(auStack_30,2,L"BAT : 00.0V",3,(HMENU)0x3);
  *(HWND *)(param_1 + 0x10) = pHVar3;
  pHVar3 = FUN_0003b6ac(auStack_30,2,L"BAT_LV : 1",3,(HMENU)0x0);
  *(HWND *)(param_1 + 0x14) = pHVar3;
  pHVar3 = FUN_0003b6ac(auStack_30,2,L"SPEED : 0cm/s",3,(HMENU)0x0);
  *(HWND *)(param_1 + 0x18) = pHVar3;
  pHVar3 = FUN_0003b6ac(auStack_30,2,L"0,0",3,(HMENU)0x4);
  *(HWND *)(param_1 + 0x1c) = pHVar3;
  pHVar3 = FUN_0003b6ac(auStack_30,2,L"ILL[0]",3,(HMENU)0xd);
  *(HWND *)(param_1 + 0x30) = pHVar3;
  FUN_0003b664((int)auStack_30);
  FUN_0003b604((int)auStack_30,0);
  FUN_0003b6ac(auStack_30,2,L"ULC13 M0 EU",1,(HMENU)0x1b);
  FUN_0003b6ac(auStack_30,2,L"ULC13 M0 SA",1,(HMENU)0x1c);
  FUN_0003b6ac(auStack_30,2,L"ULC13 M0 OTH",1,(HMENU)0x1d);
  FUN_0003b6ac(auStack_30,2,L"ULC13 MI EU",1,(HMENU)0x1e);
  FUN_0003b6ac(auStack_30,2,L"ULC13 MI SA",1,(HMENU)0x1f);
  FUN_0003b6ac(auStack_30,2,L"ULC13 MI OTH",1,(HMENU)0x20);
  FUN_0003b6ac(auStack_30,2,L"ULC13 X87 EU",1,(HMENU)0x21);
  FUN_0003b6ac(auStack_30,2,L"ULC13 X87 SA",1,(HMENU)0x22);
  FUN_0003b6ac(auStack_30,2,L"ULC13 X87 OTH",1,(HMENU)0x23);
  FUN_0003b6ac(auStack_30,2,L"ULC14P X87 OTH",1,(HMENU)0x24);
  FUN_0003b664((int)auStack_30);
  FUN_0003b604((int)auStack_30,0);
  FUN_0003b6ac(auStack_30,2,L"ULC15 M0 EU",1,(HMENU)0x25);
  FUN_0003b6ac(auStack_30,2,L"ULC15 M0 SA",1,(HMENU)0x26);
  FUN_0003b6ac(auStack_30,2,L"ULC15 M0 OTH",1,(HMENU)0x27);
  FUN_0003b6ac(auStack_30,2,L"ULC15 MI EU",1,(HMENU)0x28);
  FUN_0003b6ac(auStack_30,2,L"ULC15 MI SA",1,(HMENU)0x29);
  FUN_0003b6ac(auStack_30,2,L"ULC15 MI OTH",1,(HMENU)0x2a);
  FUN_0003b6ac(auStack_30,2,L"ULC15 X87 EU",1,(HMENU)0x2b);
  FUN_0003b6ac(auStack_30,2,L"ULC15 X87 SA",1,(HMENU)0x2c);
  FUN_0003b6ac(auStack_30,2,L"ULC15 X87 OTH",1,(HMENU)0x2d);
  FUN_0003b664((int)auStack_30);
  FUN_0003b604((int)auStack_30,0);
  FUN_0003b6ac(auStack_30,2,L"RVC_SWRC #2(2A)",3,(HMENU)0xa);
  FUN_0003b6ac(auStack_30,2,L"RVC_SWRC #1(2A)",3,(HMENU)0x2e);
  FUN_0003b664((int)auStack_30);
  FUN_0003b604((int)auStack_30,0);
  FUN_0003b6ac(auStack_30,2,L"None",1,(HMENU)0x30);
  FUN_0003b6ac(auStack_30,2,L"For X87",1,(HMENU)0x31);
  FUN_0003b6ac(auStack_30,2,L"For B98",1,(HMENU)0x32);
  FUN_0003b6ac(auStack_30,2,L"For K98",1,(HMENU)0x33);
  FUN_0003b664((int)auStack_30);
  FUN_0003b604((int)auStack_30,0);
  pHVar3 = FUN_0003b6ac(auStack_30,2,L"LHD",1,(HMENU)0x35);
  *(HWND *)(param_1 + 0x38) = pHVar3;
  FUN_0003b6ac(auStack_30,2,L"Set LHD",1,(HMENU)0x36);
  FUN_0003b6ac(auStack_30,2,L"Set RHD",1,(HMENU)0x37);
  FUN_0003b664((int)auStack_30);
  FUN_0003b604((int)auStack_30,0);
  FUN_0003b6ac(auStack_30,2,L"GET ECO",1,(HMENU)0x38);
  pHVar3 = FUN_0003b6ac(auStack_30,2,L"ADAC",1,(HMENU)0x3a);
  *(HWND *)(param_1 + 0x3c) = pHVar3;
  pHVar3 = FUN_0003b6ac(auStack_30,2,L"TEMP",1,(HMENU)0x3b);
  *(HWND *)(param_1 + 0x40) = pHVar3;
  pHVar3 = FUN_0003b6ac(auStack_30,2,L"AIR",1,(HMENU)0x3c);
  *(HWND *)(param_1 + 0x44) = pHVar3;
  pHVar3 = FUN_0003b6ac(auStack_30,2,L"ENG",1,(HMENU)0x3d);
  *(HWND *)(param_1 + 0x48) = pHVar3;
  pHVar3 = FUN_0003b6ac(auStack_30,2,L"ECO",1,(HMENU)0x3e);
  *(HWND *)(param_1 + 0x4c) = pHVar3;
  FUN_0003b6ac(auStack_30,2,L"SET ECO",1,(HMENU)0x39);
  FUN_0003c204(param_1);
  FUN_0003e4c8();
  return;
}



/* 0003dad0 Unwind@0003dad0 */

/* Boundary evidence: original MIPS .pdata 0003dad0..0003daff. Semantic name remains unreviewed. */

void Unwind_0003dad0(void)

{
  FUN_0003e4c8();
  return;
}



/* 0003db00 FUN_0003db00 */

/* Boundary evidence: original MIPS .pdata 0003db00..0003db23. Semantic name remains unreviewed. */

void FUN_0003db00(int param_1)

{
  FUN_0003e89c(param_1,100,500,(TIMERPROC)0x0);
  return;
}



/* 0003db24 FUN_0003db24 */

/* Boundary evidence: original MIPS .pdata 0003db24..0003db3f. Semantic name remains unreviewed. */

void FUN_0003db24(int param_1)

{
  FUN_0003e8b8(param_1,100);
  return;
}



/* 0003db40 FUN_0003db40 */

/* Boundary evidence: original MIPS .pdata 0003db40..0003dd23. Semantic name remains unreviewed. */

void FUN_0003db40(undefined4 param_1,HDC param_2,int param_3,LONG param_4,COLORREF param_5,
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
  lprc = (RECT *)(&DAT_00052e58 + param_3 * 4);
  FUN_0003a114(param_1,hdc,lprc,param_6);
  SetBkMode(hdc,1);
  SetTextColor(hdc,param_5);
  h_01 = FUN_0003a02c(param_4,0,0,0,0,'\0','\0','\0','\0','\0','\0','\x06','\x02',L"Tahoma");
  h_02 = SelectObject(hdc,h_01);
  DrawTextW(hdc,param_7,-1,lprc,5);
  SelectObject(hdc,h_02);
  DeleteObject(h_01);
  y = (&DAT_00052e5c)[param_3 * 4];
  x = lprc->left;
  BitBlt(param_2,x,y,(&DAT_00052e60)[param_3 * 4] - x,(&DAT_00052e64)[param_3 * 4] - y,hdc,x,y,
         0xcc0020);
  SelectObject(hdc,h_00);
  DeleteObject(h);
  DeleteDC(hdc);
  return;
}



/* 0003dd24 FUN_0003dd24 */

/* Boundary evidence: original MIPS .pdata 0003dd24..0003de17. Semantic name remains unreviewed. */

void FUN_0003dd24(undefined4 param_1,HDC param_2)

{
  if (DAT_00059350 == 1) {
    FUN_0003db40(param_1,param_2,2,0x1c,0xc8c8c8,0,L"MICOM");
    FUN_0003db40(param_1,param_2,3,0x1c,0xc8c8c8,0xb43232,L"PC");
  }
  else {
    FUN_0003db40(param_1,param_2,2,0x1c,0xc8c8c8,0xb43232,L"MICOM");
    FUN_0003db40(param_1,param_2,3,0x1c,0xc8c8c8,0,L"PC");
  }
  return;
}



/* 0003de18 FUN_0003de18 */

/* Boundary evidence: original MIPS .pdata 0003de18..0003dfc3. Semantic name remains unreviewed. */

void FUN_0003de18(undefined4 param_1,HDC param_2)

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
  
  local_30 = DAT_00055374;
  uVar5 = 0;
  uVar4 = 0;
  uVar3 = 0;
  uVar1 = FUN_00016068(DAT_000553cc,9,4,&local_138,2,200);
  if (uVar1 == 2) {
    uVar5 = __ultofp((uint)local_137 * 0x100 + (uint)local_138);
  }
  uVar1 = FUN_00016068(DAT_000553cc,9,0x40,&local_138,1,200);
  if (uVar1 == 1) {
    uVar4 = (uint)local_138;
  }
  uVar1 = FUN_00016068(DAT_000553cc,9,3,&local_138,1,200);
  if (uVar1 == 1) {
    uVar3 = (uint)local_138;
  }
  uVar2 = __fpmul(uVar5,0x3d1374bc);
  uVar6 = __fptodp(uVar2);
  uVar5 = __fpmul(uVar5,0x3c23d70a);
  uVar7 = __fptodp(uVar5);
  wsprintfW(aWStack_130,L"%6.2fm/s   %6.2fKm/h   %d   %d",(int)uVar7,(int)((ulonglong)uVar7 >> 0x20)
            ,(int)uVar6,(int)((ulonglong)uVar6 >> 0x20),uVar4,uVar3);
  FUN_0003db40(param_1,param_2,5,0x1c,0xffffff,0,aWStack_130);
  FUN_00043604(local_30);
  return;
}



/* 0003dfc4 FUN_0003dfc4 */

/* Boundary evidence: original MIPS .pdata 0003dfc4..0003e15b. Semantic name remains unreviewed. */

void FUN_0003dfc4(undefined4 param_1,HDC param_2)

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
  FUN_0003a114(param_1,hdc,&local_30,0);
  FUN_0003db40(param_1,hdc,0,0x2e,0xffffff,0,L"BACK");
  FUN_0003db40(param_1,hdc,1,0x24,0xffffff,0,L"DSP target device");
  FUN_0003dd24(param_1,hdc);
  FUN_0003db40(param_1,hdc,4,0x24,0xffffff,0,L"Vehicle Speed");
  FUN_0003de18(param_1,hdc);
  BitBlt(param_2,0,0,800,0x1e0,hdc,0,0,0xcc0020);
  SelectObject(hdc,h_00);
  DeleteObject(h);
  DeleteDC(hdc);
  return;
}



/* 0003e15c FUN_0003e15c */

void FUN_0003e15c(undefined4 param_1,int param_2,int param_3)

{
  uint uVar1;
  int *piVar2;
  
  uVar1 = 0;
  piVar2 = &DAT_00052e58;
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



/* 0003e1c8 FUN_0003e1c8 */

/* Boundary evidence: original MIPS .pdata 0003e1c8..0003e2b7. Semantic name remains unreviewed. */

void FUN_0003e1c8(int param_1,int param_2,int param_3)

{
  int iVar1;
  HDC hDC;
  undefined1 local_18 [8];
  
  iVar1 = FUN_0003e15c(param_1,param_2,param_3);
  if (iVar1 == 0) {
    DestroyWindow(*(HWND *)(param_1 + 0xc));
  }
  else {
    if (iVar1 == 2) {
      local_18[0] = 0;
      FUN_00015b90(DAT_000553cc,0,0x30,(int)local_18,1,0x32);
      DAT_00059350 = 0;
    }
    else {
      if (iVar1 != 3) {
        return;
      }
      local_18[0] = 1;
      FUN_00015b90(DAT_000553cc,0,0x30,(int)local_18,1,0x32);
      DAT_00059350 = 1;
    }
    hDC = GetDC(*(HWND *)(param_1 + 0xc));
    FUN_0003dd24(param_1,hDC);
    ReleaseDC(*(HWND *)(param_1 + 0xc),hDC);
  }
  return;
}



/* 0003e2b8 FUN_0003e2b8 */

/* Boundary evidence: original MIPS .pdata 0003e2b8..0003e34b. Semantic name remains unreviewed. */

void FUN_0003e2b8(undefined4 param_1)

{
  undefined4 *puVar1;
  
  FUN_0003ea24();
  puVar1 = (undefined4 *)__2_YAPAXI_Z(0x10);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    FUN_0003e4a8(puVar1);
    *puVar1 = &PTR_FUN_00052eb8;
  }
  DAT_000593a8 = puVar1;
  FUN_0003e4e0((int)puVar1,DAT_00055600,param_1);
  return;
}



/* 0003e34c Unwind@0003e34c */

/* Boundary evidence: original MIPS .pdata 0003e34c..0003e37b. Semantic name remains unreviewed. */

void Unwind_0003e34c(void)

{
  int in_v0;
  
  __3_YAXPAX_Z(*(undefined4 *)(in_v0 + -0x18));
  return;
}



/* 0003e37c FUN_0003e37c */

/* Boundary evidence: original MIPS .pdata 0003e37c..0003e3d3. Semantic name remains unreviewed. */

undefined4 * FUN_0003e37c(undefined4 *param_1,uint param_2)

{
  *param_1 = &PTR_FUN_00052eb8;
  FUN_0003e4d0(param_1);
  if ((param_2 & 1) != 0) {
    __3_YAXPAX_Z(param_1);
  }
  return param_1;
}



/* 0003e3d4 FUN_0003e3d4 */

/* Boundary evidence: original MIPS .pdata 0003e3d4..0003e427. Semantic name remains unreviewed. */

void FUN_0003e3d4(int param_1,int param_2)

{
  HDC hDC;
  
  if (param_2 == 100) {
    hDC = GetDC(*(HWND *)(param_1 + 0xc));
    FUN_0003de18(param_1,hDC);
    ReleaseDC(*(HWND *)(param_1 + 0xc),hDC);
  }
  return;
}



/* 0003e428 FUN_0003e428 */

/* Boundary evidence: original MIPS .pdata 0003e428..0003e4a7. Semantic name remains unreviewed. */

void FUN_0003e428(void)

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



/* 0003e4a8 FUN_0003e4a8 */

undefined4 * FUN_0003e4a8(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_00052fc4;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  return param_1;
}



/* 0003e4c8 FUN_0003e4c8 */

void FUN_0003e4c8(void)

{
  return;
}



/* 0003e4d0 FUN_0003e4d0 */

void FUN_0003e4d0(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_00052fc4;
  return;
}



/* 0003e4e0 FUN_0003e4e0 */

/* Boundary evidence: original MIPS .pdata 0003e4e0..0003e5cf. Semantic name remains unreviewed. */

void FUN_0003e4e0(int param_1,undefined4 param_2,undefined4 param_3)

{
  HWND hWnd;
  int *piVar1;
  
  DAT_00055370 = DAT_00055370 + 1;
  piVar1 = &DAT_000593b0 + DAT_00055370;
  *(undefined4 *)(param_1 + 4) = param_2;
  *(undefined4 *)(param_1 + 8) = param_3;
  *piVar1 = param_1;
  hWnd = CreateWindowExW(0,L"TESTWND",L"",0x10000000,0,0,800,0x1e0,(HWND)0x0,(HMENU)0x0,DAT_00055600
                         ,(LPVOID)0x0);
  SetWindowPos(hWnd,(HWND)0xffffffff,0,0,0,0,3);
  ShowWindow(hWnd,1);
  SetWindowPos(hWnd,(HWND)0x0,0,0,0,0,3);
  return;
}



/* 0003e5d0 FUN_0003e5d0 */

/* Boundary evidence: original MIPS .pdata 0003e5d0..0003e6bf. Semantic name remains unreviewed. */

void FUN_0003e5d0(int param_1,undefined4 param_2,undefined4 param_3)

{
  HWND hWnd;
  int *piVar1;
  
  DAT_00055370 = DAT_00055370 + 1;
  piVar1 = &DAT_000593b0 + DAT_00055370;
  *(undefined4 *)(param_1 + 4) = param_2;
  *(undefined4 *)(param_1 + 8) = param_3;
  *piVar1 = param_1;
  hWnd = CreateWindowExW(0,L"TESTWND2",L"",0x10000000,0,0,800,0x1e0,(HWND)0x0,(HMENU)0x0,
                         DAT_00055600,(LPVOID)0x0);
  SetWindowPos(hWnd,(HWND)0xffffffff,0,0,0,0,3);
  ShowWindow(hWnd,1);
  SetWindowPos(hWnd,(HWND)0x0,0,0,0,0,3);
  return;
}



/* 0003e6c0 FUN_0003e6c0 */

/* Boundary evidence: original MIPS .pdata 0003e6c0..0003e88b. Semantic name remains unreviewed. */

LRESULT FUN_0003e6c0(int *param_1,HWND param_2,uint param_3,uint param_4,uint param_5)

{
  HDC pHVar1;
  code *pcVar2;
  LRESULT LVar3;
  tagPAINTSTRUCT tStack_58;
  uint local_18;
  
  local_18 = DAT_00055374;
  LVar3 = 0;
  if (param_3 < 0x114) {
    if (param_3 == 0x113) {
      (**(code **)(*param_1 + 0x1c))(param_1,param_4);
      goto LAB_0003e868;
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
          goto LAB_0003e868;
        }
        if (param_3 == 0x111) {
          (**(code **)(*param_1 + 0x20))(param_1,param_4 & 0xffff);
          goto LAB_0003e868;
        }
        goto LAB_0003e7f4;
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
          goto LAB_0003e868;
        }
LAB_0003e7f4:
        LVar3 = DefWindowProcW(param_2,param_3,param_4,param_5);
        goto LAB_0003e868;
      }
      pcVar2 = *(code **)(*param_1 + 0x18);
    }
    (*pcVar2)(param_1,param_5 & 0xffff,param_5 >> 0x10);
  }
LAB_0003e868:
  FUN_00043604(local_18);
  return LVar3;
}



/* 0003e88c FUN_0003e88c */

undefined4 FUN_0003e88c(void)

{
  return 800;
}



/* 0003e894 FUN_0003e894 */

undefined4 FUN_0003e894(void)

{
  return 0x1e0;
}



/* 0003e89c FUN_0003e89c */

/* Boundary evidence: original MIPS .pdata 0003e89c..0003e8b7. Semantic name remains unreviewed. */

void FUN_0003e89c(int param_1,UINT_PTR param_2,UINT param_3,TIMERPROC param_4)

{
  SetTimer(*(HWND *)(param_1 + 0xc),param_2,param_3,param_4);
  return;
}



/* 0003e8b8 FUN_0003e8b8 */

/* Boundary evidence: original MIPS .pdata 0003e8b8..0003e8d3. Semantic name remains unreviewed. */

void FUN_0003e8b8(int param_1,UINT_PTR param_2)

{
  KillTimer(*(HWND *)(param_1 + 0xc),param_2);
  return;
}



/* 0003e8d4 FUN_0003e8d4 */

/* Boundary evidence: original MIPS .pdata 0003e8d4..0003e933. Semantic name remains unreviewed. */

void FUN_0003e8d4(int *param_1,int param_2)

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



/* 0003e934 FUN_0003e934 */

/* Boundary evidence: original MIPS .pdata 0003e934..0003e9eb. Semantic name remains unreviewed. */

LRESULT FUN_0003e934(HWND param_1,uint param_2,uint param_3,uint param_4)

{
  LRESULT LVar1;
  undefined4 *puVar2;
  
  LVar1 = FUN_0003e6c0((int *)(&DAT_000593b0)[DAT_00055370],param_1,param_2,param_3,param_4);
  if (param_2 == 2) {
    puVar2 = (undefined4 *)(&DAT_000593b0)[DAT_00055370];
    if (puVar2 != (undefined4 *)0x0) {
      (**(code **)*puVar2)(puVar2,1);
    }
    puVar2 = &DAT_000593b0 + DAT_00055370;
    DAT_00055370 = DAT_00055370 + -1;
    *puVar2 = 0;
  }
  return LVar1;
}



/* 0003e9ec FUN_0003e9ec */

/* Boundary evidence: original MIPS .pdata 0003e9ec..0003ea23. Semantic name remains unreviewed. */

void FUN_0003e9ec(int param_1)

{
  FUN_0003e8d4((int *)(&DAT_000593b0)[DAT_00055370],param_1);
  return;
}



/* 0003ea24 FUN_0003ea24 */

/* Boundary evidence: original MIPS .pdata 0003ea24..0003eb27. Semantic name remains unreviewed. */

void FUN_0003ea24(void)

{
  WNDCLASSW local_40;
  
  if (DAT_000593ac == 0) {
    local_40.cbClsExtra = 0;
    local_40.cbWndExtra = 0;
    local_40.hbrBackground = GetStockObject(1);
    local_40.hCursor = LoadCursorW((HINSTANCE)0x0,(LPCWSTR)0x7f00);
    local_40.hIcon = (HICON)0x0;
    local_40.hInstance = DAT_00055600;
    local_40.lpfnWndProc = FUN_0003e934;
    local_40.lpszClassName = L"TESTWND";
    local_40.lpszMenuName = (LPCWSTR)0x0;
    local_40.style = 3;
    RegisterClassW(&local_40);
    local_40.cbClsExtra = 0;
    local_40.cbWndExtra = 0;
    local_40.hbrBackground = GetStockObject(4);
    local_40.hCursor = LoadCursorW((HINSTANCE)0x0,(LPCWSTR)0x7f00);
    local_40.hIcon = (HICON)0x0;
    local_40.hInstance = DAT_00055600;
    local_40.lpfnWndProc = FUN_0003e934;
    local_40.lpszClassName = L"TESTWND2";
    local_40.lpszMenuName = (LPCWSTR)0x0;
    local_40.style = 3;
    RegisterClassW(&local_40);
    DAT_000593ac = 1;
  }
  return;
}



/* 0003eb28 FUN_0003eb28 */

/* Boundary evidence: original MIPS .pdata 0003eb28..0003eb6b. Semantic name remains unreviewed. */

undefined4 * FUN_0003eb28(undefined4 *param_1,uint param_2)

{
  *param_1 = &PTR_FUN_00052fc4;
  if ((param_2 & 1) != 0) {
    __3_YAXPAX_Z(param_1);
  }
  return param_1;
}



/* 0003eb6c FUN_0003eb6c */

/* Boundary evidence: original MIPS .pdata 0003eb6c..0003ebd3. Semantic name remains unreviewed. */

undefined4 * FUN_0003eb6c(undefined4 *param_1)

{
  FUN_0003e4a8(param_1);
  *param_1 = &PTR_FUN_00052ff0;
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[6] = 0;
  param_1[7] = 0;
  param_1[8] = 0;
  param_1[9] = 0;
  param_1[10] = 0;
  param_1[0xb] = 0;
  param_1[0xc] = 0;
  param_1[0xd] = 0;
  param_1[0xe] = 0;
  param_1[0xf] = 0;
  return param_1;
}



/* 0003ebd4 FUN_0003ebd4 */

/* Boundary evidence: original MIPS .pdata 0003ebd4..0003f04f. Semantic name remains unreviewed. */

void FUN_0003ebd4(int param_1)

{
  undefined4 uVar1;
  HWND pHVar2;
  uint uVar3;
  uint uVar4;
  undefined1 *puVar5;
  undefined8 uVar6;
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
  WCHAR aWStack_b0 [64];
  uint local_30;
  
  local_30 = DAT_00055374;
  *(undefined4 *)(DAT_00057130 + 0x5c) = *(undefined4 *)(param_1 + 0xc);
  puVar5 = auStack_168;
  FUN_00015f10(DAT_000553cc,0xf,1,3,0,0,0x32);
  uVar3 = 0xb4;
  do {
    uVar4 = 0x20;
    if (uVar3 < 0x21) {
      uVar4 = uVar3;
    }
    uVar3 = uVar3 - uVar4;
    FUN_00016068(DAT_000553cc,0xf,1,puVar5,(byte)uVar4,100);
    puVar5 = puVar5 + uVar4;
  } while (uVar3 != 0);
  uVar1 = FUN_0003e894();
  uVar3 = FUN_0003e88c();
  FUN_0003b5d0(auStack_188,*(undefined4 *)(param_1 + 4),*(undefined4 *)(param_1 + 0xc),uVar3,uVar1);
  FUN_0003b6ac(auStack_188,1,L"IF FILTER(FM/AM)",3,(HMENU)0x0);
  wsprintfW(aWStack_b0,L"0x%02X",(uint)local_164);
  pHVar2 = FUN_0003b6ac(auStack_188,1,aWStack_b0,2,(HMENU)0x0);
  *(HWND *)(param_1 + 0x1c) = pHVar2;
  wsprintfW(aWStack_b0,L"0x%02X",(uint)local_163);
  pHVar2 = FUN_0003b6ac(auStack_188,1,aWStack_b0,2,(HMENU)0x0);
  *(HWND *)(param_1 + 0x20) = pHVar2;
  FUN_0003b664((int)auStack_188);
  FUN_0003b6ac(auStack_188,1,L"DSP-Xtal Error",3,(HMENU)0x0);
  if ((local_162 & 0x800) != 0) {
    local_162 = local_162 | 0xf000;
  }
  uVar6 = __litodp((int)(short)local_162);
  uVar6 = __dpmul((int)uVar6,(int)((ulonglong)uVar6 >> 0x20),0,0x3fa90000);
  wsprintfW(aWStack_b0,L"%5.2f",(int)uVar6,(int)((ulonglong)uVar6 >> 0x20));
  pHVar2 = FUN_0003b6ac(auStack_188,1,aWStack_b0,2,(HMENU)0x0);
  *(HWND *)(param_1 + 0x24) = pHVar2;
  FUN_0003b664((int)auStack_188);
  FUN_0003b6ac(auStack_188,1,L"FM OFFSET",3,(HMENU)0x0);
  wsprintfW(aWStack_b0,L"0x%06X",local_140);
  pHVar2 = FUN_0003b6ac(auStack_188,1,aWStack_b0,2,(HMENU)0x0);
  *(HWND *)(param_1 + 0x28) = pHVar2;
  wsprintfW(aWStack_b0,L"0x%06X",local_13c);
  pHVar2 = FUN_0003b6ac(auStack_188,1,aWStack_b0,2,(HMENU)0x0);
  *(HWND *)(param_1 + 0x2c) = pHVar2;
  FUN_0003b664((int)auStack_188);
  FUN_0003b6ac(auStack_188,1,L"LV(FM/MW/LW)",3,(HMENU)0x0);
  wsprintfW(aWStack_b0,L"0x%02X",(uint)local_118);
  pHVar2 = FUN_0003b6ac(auStack_188,1,aWStack_b0,1,(HMENU)0x0);
  *(HWND *)(param_1 + 0x30) = pHVar2;
  wsprintfW(aWStack_b0,L"0x%02X",(uint)local_11e);
  pHVar2 = FUN_0003b6ac(auStack_188,1,aWStack_b0,1,(HMENU)0x0);
  *(HWND *)(param_1 + 0x34) = pHVar2;
  wsprintfW(aWStack_b0,L"0x%02X",(uint)local_120);
  pHVar2 = FUN_0003b6ac(auStack_188,1,aWStack_b0,1,(HMENU)0x0);
  *(HWND *)(param_1 + 0x38) = pHVar2;
  FUN_0003b664((int)auStack_188);
  FUN_0003b6ac(auStack_188,1,L"FM CH SEP",3,(HMENU)0x0);
  wsprintfW(aWStack_b0,L"0x%02X",(uint)local_110);
  pHVar2 = FUN_0003b6ac(auStack_188,1,aWStack_b0,2,(HMENU)0x0);
  *(HWND *)(param_1 + 0x3c) = pHVar2;
  FUN_0003b68c((int)auStack_188);
  pHVar2 = FUN_0003b6ac(auStack_188,1,L"START",7,(HMENU)0x1);
  *(HWND *)(param_1 + 0x10) = pHVar2;
  FUN_0003b664((int)auStack_188);
  pHVar2 = FUN_0003b6ac(auStack_188,1,L"NEXT",7,(HMENU)0x2);
  *(HWND *)(param_1 + 0x14) = pHVar2;
  FUN_0003b664((int)auStack_188);
  pHVar2 = FUN_0003b6ac(auStack_188,1,L"SAVE",7,(HMENU)0x3);
  *(HWND *)(param_1 + 0x18) = pHVar2;
  EnableWindow(*(HWND *)(param_1 + 0x10),1);
  EnableWindow(*(HWND *)(param_1 + 0x14),0);
  EnableWindow(*(HWND *)(param_1 + 0x18),0);
  FUN_0003e4c8();
  FUN_00043604(local_30);
  return;
}



/* 0003f050 Unwind@0003f050 */

/* Boundary evidence: original MIPS .pdata 0003f050..0003f07f. Semantic name remains unreviewed. */

void Unwind_0003f050(void)

{
  FUN_0003e4c8();
  return;
}



/* 0003f080 FUN_0003f080 */

/* Boundary evidence: original MIPS .pdata 0003f080..0003f1b7. Semantic name remains unreviewed. */

void FUN_0003f080(int param_1,int param_2)

{
  if (param_2 == 1) {
    FUN_00015f10(DAT_000553cc,3,1,0x80,0,0,100);
    EnableWindow(*(HWND *)(param_1 + 0x10),0);
    EnableWindow(*(HWND *)(param_1 + 0x14),0);
    EnableWindow(*(HWND *)(param_1 + 0x18),0);
    Sleep(0x1e);
    FUN_00015f10(DAT_000553cc,3,1,0x80,0,0,100);
  }
  else if (param_2 == 2) {
    FUN_00015f10(DAT_000553cc,3,1,0x81,0,0,100);
    EnableWindow(*(HWND *)(param_1 + 0x14),0);
  }
  else if (param_2 == 3) {
    FUN_00015f10(DAT_000553cc,3,1,0x83,0,0,100);
  }
  return;
}



/* 0003f1b8 FUN_0003f1b8 */

/* Boundary evidence: original MIPS .pdata 0003f1b8..0003f693. Semantic name remains unreviewed. */

void FUN_0003f1b8(int param_1,int param_2,undefined4 param_3)

{
  HWND hWnd;
  LPCWSTR lpString;
  ushort uVar1;
  undefined8 uVar2;
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
  
  local_18 = DAT_00055374;
  if (param_2 != 4) goto switchD_0003f210_caseD_5;
  switch(param_3) {
  case 4:
    uVar1 = CONCAT11(*(byte *)(DAT_00057130 + 0xc),*(undefined1 *)(DAT_00057130 + 0xd));
    if ((*(byte *)(DAT_00057130 + 0xc) & 8) != 0) {
      uVar1 = uVar1 | 0xf000;
    }
    uVar2 = __litodp((int)(short)uVar1);
    uVar2 = __dpmul((int)uVar2,(int)((ulonglong)uVar2 >> 0x20),0,0x3fa90000);
    wsprintfW(aWStack_598,L"%5.2f",(int)uVar2,(int)((ulonglong)uVar2 >> 0x20));
    SetWindowTextW(*(HWND *)(param_1 + 0x24),aWStack_598);
    wsprintfW(aWStack_598,L"0x%06X",
              ((uint)*(byte *)(DAT_00057130 + 0xe) * 0x100 + (uint)*(byte *)(DAT_00057130 + 0xf)) *
              0x100 + (uint)*(byte *)(DAT_00057130 + 0x10));
    SetWindowTextW(*(HWND *)(param_1 + 0x28),aWStack_598);
    wsprintfW(aWStack_598,L"0x%06X",
              ((uint)*(byte *)(DAT_00057130 + 0x11) * 0x100 + (uint)*(byte *)(DAT_00057130 + 0x12))
              * 0x100 + (uint)*(byte *)(DAT_00057130 + 0x13));
    SetWindowTextW(*(HWND *)(param_1 + 0x2c),aWStack_598);
    FUN_00015f10(DAT_000553cc,3,1,0x81,0,0,100);
    break;
  case 7:
    wsprintfW(aWStack_118,L"MAIN TUNER : 97.7MHz, 200uV, MOD(OFF)");
    lpString = aWStack_118;
    goto LAB_0003f270;
  case 8:
    wsprintfW(aWStack_418,L"0x%02X",(uint)*(byte *)(DAT_00057130 + 0xc));
    SetWindowTextW(*(HWND *)(param_1 + 0x1c),aWStack_418);
    FUN_00015f10(DAT_000553cc,3,1,0x81,0,0,100);
    break;
  case 10:
    wsprintfW(aWStack_218,L"0x%02X",
              (uint)*(byte *)(DAT_00057130 + 0xc) * 0x100 + (uint)*(byte *)(DAT_00057130 + 0xd));
    SetWindowTextW(*(HWND *)(param_1 + 0x30),aWStack_218);
    FUN_00015f10(DAT_000553cc,3,1,0x81,0,0,100);
    break;
  case 0xb:
    wsprintfW(aWStack_318,L"MAIN TUNER : 97.7MHz, 1mV, MOD(ON,40kHz), AF(1kHz)");
    lpString = aWStack_318;
    goto LAB_0003f270;
  case 0xc:
    wsprintfW(aWStack_518,L"0x%02X",
              (uint)*(byte *)(DAT_00057130 + 0xc) * 0x100 + (uint)*(byte *)(DAT_00057130 + 0xd));
    SetWindowTextW(*(HWND *)(param_1 + 0x3c),aWStack_518);
    FUN_00015f10(DAT_000553cc,3,1,0x81,0,0,100);
    break;
  case 0x20:
    wsprintfW(aWStack_498,L"MAIN TUNER : 1080kHz, 1mV, MOD(OFF)");
    lpString = aWStack_498;
    goto LAB_0003f270;
  case 0x21:
    wsprintfW(aWStack_398,L"0x%02X",(uint)*(byte *)(DAT_00057130 + 0xc));
    SetWindowTextW(*(HWND *)(param_1 + 0x20),aWStack_398);
    FUN_00015f10(DAT_000553cc,3,1,0x81,0,0,100);
    break;
  case 0x22:
    FUN_00015f10(DAT_000553cc,3,1,0x81,0,0,100);
    break;
  case 0x23:
    wsprintfW(aWStack_298,L"0x%02X",
              (uint)*(byte *)(DAT_00057130 + 0xc) * 0x100 + (uint)*(byte *)(DAT_00057130 + 0xd));
    SetWindowTextW(*(HWND *)(param_1 + 0x34),aWStack_298);
    FUN_00015f10(DAT_000553cc,3,1,0x81,0,0,100);
    break;
  case 0x24:
    wsprintfW(aWStack_198,L"MAIN TUNER : 216kHz, 1mV, MOD(OFF)");
    lpString = aWStack_198;
LAB_0003f270:
    SetWindowTextW(*(HWND *)(param_1 + 0x14),lpString);
    hWnd = *(HWND *)(param_1 + 0x14);
LAB_0003f66c:
    EnableWindow(hWnd,1);
    break;
  case 0x25:
    wsprintfW(aWStack_98,L"0x%02X",
              (uint)*(byte *)(DAT_00057130 + 0xc) * 0x100 + (uint)*(byte *)(DAT_00057130 + 0xd));
    SetWindowTextW(*(HWND *)(param_1 + 0x38),aWStack_98);
    FUN_00015f10(DAT_000553cc,3,1,0x81,0,0,100);
    EnableWindow(*(HWND *)(param_1 + 0x10),1);
    hWnd = *(HWND *)(param_1 + 0x18);
    goto LAB_0003f66c;
  }
switchD_0003f210_caseD_5:
  FUN_00043604(local_18);
  return;
}



/* 0003f6a4 FUN_0003f6a4 */

/* Boundary evidence: original MIPS .pdata 0003f6a4..0003f6fb. Semantic name remains unreviewed. */

undefined4 * FUN_0003f6a4(undefined4 *param_1,uint param_2)

{
  *param_1 = &PTR_FUN_00052ff0;
  FUN_0003e4d0(param_1);
  if ((param_2 & 1) != 0) {
    __3_YAXPAX_Z(param_1);
  }
  return param_1;
}



/* 0003f6fc FUN_0003f6fc */

/* Boundary evidence: original MIPS .pdata 0003f6fc..0003f78f. Semantic name remains unreviewed. */

undefined4 * FUN_0003f6fc(undefined4 *param_1)

{
  undefined4 *puVar1;
  
  FUN_0003e4a8(param_1);
  puVar1 = param_1 + 6;
  *param_1 = &PTR_FUN_00053254;
  param_1[0x24] = 0;
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



/* 0003f790 FUN_0003f790 */

/* Boundary evidence: original MIPS .pdata 0003f790..0003f7db. Semantic name remains unreviewed. */

void FUN_0003f790(int param_1)

{
  if (*(int *)(param_1 + 0x90) == 1) {
    FUN_0003e8b8(param_1,0xb);
    *(undefined4 *)(param_1 + 0x90) = 0;
  }
  *(undefined4 *)(DAT_00057130 + 0x5c) = 0;
  return;
}



/* 0003f7dc FUN_0003f7dc */

/* Boundary evidence: original MIPS .pdata 0003f7dc..0003f883. Semantic name remains unreviewed. */

void FUN_0003f7dc(int param_1)

{
  uint uVar1;
  undefined4 *puVar2;
  WCHAR aWStack_40 [16];
  uint local_20;
  
  local_20 = DAT_00055374;
  uVar1 = 0;
  puVar2 = (undefined4 *)(param_1 + 0x18);
  do {
    wsprintfW(aWStack_40,L"%S",
              ((uint)*(byte *)(DAT_00055618 + 4) * 0x30 + uVar1) * 0x10 + DAT_00055618 + 0xc);
    SetWindowTextW((HWND)*puVar2,aWStack_40);
    uVar1 = uVar1 + 1;
    puVar2 = puVar2 + 1;
  } while (uVar1 < 0xc);
  FUN_00043604(local_20);
  return;
}



/* 0003f884 FUN_0003f884 */

/* Boundary evidence: original MIPS .pdata 0003f884..0003f8db. Semantic name remains unreviewed. */

undefined4 * FUN_0003f884(undefined4 *param_1,uint param_2)

{
  *param_1 = &PTR_FUN_00053254;
  FUN_0003e4d0(param_1);
  if ((param_2 & 1) != 0) {
    __3_YAXPAX_Z(param_1);
  }
  return param_1;
}



/* 0003f8dc FUN_0003f8dc */

/* Boundary evidence: original MIPS .pdata 0003f8dc..0003ff2f. Semantic name remains unreviewed. */

void FUN_0003f8dc(int param_1)

{
  undefined4 uVar1;
  uint uVar2;
  HWND pHVar3;
  byte local_258;
  byte local_257;
  undefined4 auStack_250 [8];
  WCHAR aWStack_230 [260];
  uint local_28;
  
  local_28 = DAT_00055374;
  *(undefined4 *)(DAT_00057130 + 0x5c) = *(undefined4 *)(param_1 + 0xc);
  uVar1 = FUN_0003e894();
  uVar2 = FUN_0003e88c();
  FUN_0003b5d0(auStack_250,*(undefined4 *)(param_1 + 4),*(undefined4 *)(param_1 + 0xc),uVar2,uVar1);
  FUN_0003b6ac(auStack_250,1,L"FM",1,(HMENU)0x1);
  FUN_0003b6ac(auStack_250,1,L"AM",1,(HMENU)0x2);
  FUN_0003b604((int)auStack_250,1);
  FUN_0003b604((int)auStack_250,1);
  FUN_0003b6ac(auStack_250,1,L"A",1,(HMENU)0x1a);
  FUN_0003b6ac(auStack_250,1,L"S",1,(HMENU)0x1b);
  FUN_0003b6ac(auStack_250,1,L"R",1,(HMENU)0x1c);
  FUN_0003b604((int)auStack_250,0);
  FUN_0003b6ac(auStack_250,0,L"SEEK/TUNE",0,(HMENU)0x0);
  FUN_0003b604((int)auStack_250,1);
  FUN_0003b6ac(auStack_250,1,L"<<",1,(HMENU)0x3);
  FUN_0003b6ac(auStack_250,1,L"<",1,(HMENU)0x5);
  pHVar3 = FUN_0003b6ac(auStack_250,2,L"",3,(HMENU)0x0);
  *(HWND *)(param_1 + 0x14) = pHVar3;
  FUN_0003b6ac(auStack_250,1,L">",1,(HMENU)0x6);
  FUN_0003b6ac(auStack_250,1,L">>",1,(HMENU)0x4);
  FUN_0003b604((int)auStack_250,0);
  FUN_0003b6ac(auStack_250,0,L"PRESET",0,(HMENU)0x0);
  FUN_0003b604((int)auStack_250,1);
  FUN_0003b6ac(auStack_250,1,L"P1",1,(HMENU)0x7);
  pHVar3 = FUN_0003b6ac(auStack_250,1,L"",2,(HMENU)0x13);
  *(HWND *)(param_1 + 0x18) = pHVar3;
  FUN_0003b604((int)auStack_250,1);
  FUN_0003b6ac(auStack_250,1,L"P2",1,(HMENU)0x8);
  pHVar3 = FUN_0003b6ac(auStack_250,1,L"",2,(HMENU)0x14);
  *(HWND *)(param_1 + 0x1c) = pHVar3;
  FUN_0003b664((int)auStack_250);
  FUN_0003b604((int)auStack_250,1);
  FUN_0003b6ac(auStack_250,1,L"P3",1,(HMENU)0x9);
  pHVar3 = FUN_0003b6ac(auStack_250,1,L"",2,(HMENU)0x15);
  *(HWND *)(param_1 + 0x20) = pHVar3;
  FUN_0003b604((int)auStack_250,1);
  FUN_0003b6ac(auStack_250,1,L"P4",1,(HMENU)0xa);
  pHVar3 = FUN_0003b6ac(auStack_250,1,L"",2,(HMENU)0x16);
  *(HWND *)(param_1 + 0x24) = pHVar3;
  FUN_0003b664((int)auStack_250);
  FUN_0003b604((int)auStack_250,1);
  FUN_0003b6ac(auStack_250,1,L"P5",1,(HMENU)0xb);
  pHVar3 = FUN_0003b6ac(auStack_250,1,L"",2,(HMENU)0x17);
  *(HWND *)(param_1 + 0x28) = pHVar3;
  FUN_0003b604((int)auStack_250,1);
  FUN_0003b6ac(auStack_250,1,L"P6",1,(HMENU)0xc);
  pHVar3 = FUN_0003b6ac(auStack_250,1,L"",2,(HMENU)0x18);
  *(HWND *)(param_1 + 0x2c) = pHVar3;
  FUN_0003b664((int)auStack_250);
  FUN_0003b604((int)auStack_250,0);
  pHVar3 = FUN_0003b6ac(auStack_250,1,L"0000",2,(HMENU)0x0);
  *(HWND *)(param_1 + 0x7c) = pHVar3;
  pHVar3 = FUN_0003b6ac(auStack_250,1,L"00",1,(HMENU)0x0);
  *(HWND *)(param_1 + 0x80) = pHVar3;
  pHVar3 = FUN_0003b6ac(auStack_250,1,L"X",1,(HMENU)0x0);
  *(HWND *)(param_1 + 0x84) = pHVar3;
  pHVar3 = FUN_0003b6ac(auStack_250,1,L"X",1,(HMENU)0x0);
  *(HWND *)(param_1 + 0x88) = pHVar3;
  FUN_0003b68c((int)auStack_250);
  pHVar3 = FUN_0003b6ac(auStack_250,1,L"0dBuV",2,(HMENU)0x0);
  *(HWND *)(param_1 + 0x8c) = pHVar3;
  FUN_0003f7dc(param_1);
  FUN_0003b604((int)auStack_250,0);
  FUN_0003b604((int)auStack_250,0);
  FUN_00016068(DAT_000553cc,2,0x31282,&local_258,3,500);
  wsprintfW(aWStack_230,L"0x%02X%02X",(uint)local_258,(uint)local_257);
  FUN_0003b6ac(auStack_250,2,aWStack_230,2,(HMENU)0x0);
  FUN_0003b604((int)auStack_250,1);
  FUN_00016068(DAT_000553cc,2,0x31283,&local_258,3,500);
  wsprintfW(aWStack_230,L"0x%02X%02X",(uint)local_258,(uint)local_257);
  FUN_0003b6ac(auStack_250,2,aWStack_230,2,(HMENU)0x0);
  FUN_0003b604((int)auStack_250,1);
  FUN_00016068(DAT_000553cc,2,0x31284,&local_258,3,500);
  wsprintfW(aWStack_230,L"0x%02X%02X",(uint)local_258,(uint)local_257);
  FUN_0003b6ac(auStack_250,2,aWStack_230,2,(HMENU)0x0);
  FUN_0003e89c(param_1,0xb,300,(TIMERPROC)0x0);
  FUN_0003e4c8();
  FUN_00043604(local_28);
  return;
}



/* 0003ff30 Unwind@0003ff30 */

/* Boundary evidence: original MIPS .pdata 0003ff30..0003ff5f. Semantic name remains unreviewed. */

void Unwind_0003ff30(void)

{
  FUN_0003e4c8();
  return;
}



/* 0003ff60 FUN_0003ff60 */

/* Boundary evidence: original MIPS .pdata 0003ff60..00040153. Semantic name remains unreviewed. */

void FUN_0003ff60(int param_1,int param_2)

{
  errno_t eVar1;
  char *_Src;
  uint uVar2;
  undefined1 *puVar3;
  FILE *local_468 [2];
  char acStack_460 [64];
  undefined1 auStack_420 [1024];
  uint local_20;
  
  local_20 = DAT_00055374;
  switch(param_2) {
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
    FUN_000269e8(DAT_00057130,param_2 - 7);
  case 1:
  case 2:
    FUN_0003f7dc(param_1);
    break;
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
      puVar3 = auStack_420;
      do {
        FUN_00015b90(DAT_000553cc,3,uVar2 + 0xe0,(int)puVar3,0x80,300);
        uVar2 = uVar2 + 1;
        puVar3 = puVar3 + 0x80;
      } while (uVar2 < 8);
      if (param_2 != 0x1a) {
        FUN_00015f10(DAT_000553cc,3,1,0xe1,0,0,500);
      }
      FUN_00015f10(DAT_000553cc,3,1,0xe0,0,0,500);
      FUN_00015f10(DAT_000553cc,3,1,0xe2,0,0,0x1e);
    }
  }
  FUN_00043604(local_20);
  return;
}



/* 00040154 FUN_00040154 */

/* Boundary evidence: original MIPS .pdata 00040154..000402d3. Semantic name remains unreviewed. */

void FUN_00040154(int param_1,int param_2,int param_3)

{
  HWND hWnd;
  LPCWSTR pWVar1;
  WCHAR aWStack_298 [64];
  WCHAR aWStack_218 [64];
  WCHAR aWStack_198 [64];
  WCHAR aWStack_118 [64];
  WCHAR aWStack_98 [64];
  uint local_18;
  
  local_18 = DAT_00055374;
  if (param_2 == 0) {
    SetWindowTextW(*(HWND *)(param_1 + 0x7c),L"0000");
    SetWindowTextW(*(HWND *)(param_1 + 0x80),L"00");
    pWVar1 = L"X";
    SetWindowTextW(*(HWND *)(param_1 + 0x84),L"X");
LAB_000402ac:
    hWnd = *(HWND *)(param_1 + 0x88);
  }
  else {
    if (param_2 == 1) goto LAB_000402b8;
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
        if (param_2 != 8) goto LAB_000402b8;
        if (param_3 == 1) {
          pWVar1 = L"O";
        }
        else {
          pWVar1 = L"X";
        }
        wsprintfW(aWStack_218,pWVar1);
        pWVar1 = aWStack_218;
        goto LAB_000402ac;
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
LAB_000402b8:
  FUN_00043604(local_18);
  return;
}



/* 000402d4 FUN_000402d4 */

/* Boundary evidence: original MIPS .pdata 000402d4..0004030b. Semantic name remains unreviewed. */

undefined4 * FUN_000402d4(undefined4 *param_1)

{
  FUN_0003e4a8(param_1);
  *param_1 = &PTR_FUN_0005336c;
  return param_1;
}



/* 0004030c FUN_0004030c */

/* Boundary evidence: original MIPS .pdata 0004030c..00040417. Semantic name remains unreviewed. */

void FUN_0004030c(int param_1)

{
  int iVar1;
  int iVar2;
  
  if (DAT_000593d0 == 1) {
    iVar1 = FUN_0003e894();
    iVar2 = FUN_0003e88c();
    CreateWindowExW(0,L"button",
                    L"Radio Tuning...(Current DSP --- PC)\r\nIf you press this button DSP will be connected to MICOM.\r\nIf you want to go back to main menu, press power button."
                    ,0x50802000,100,100,iVar2 + -200,iVar1 + -200,*(HWND *)(param_1 + 0xc),
                    (HMENU)0x0,*(HINSTANCE *)(param_1 + 4),(LPVOID)0x0);
  }
  else {
    iVar1 = FUN_0003e894();
    iVar2 = FUN_0003e88c();
    CreateWindowExW(0,L"button",
                    L"Radio Tuning...(Current DSP --- MICOM)\r\nIf you press this button DSP will be connected to PC.\r\nIf you want to go back to main menu, press power button."
                    ,0x50802000,100,100,iVar2 + -200,iVar1 + -200,*(HWND *)(param_1 + 0xc),
                    (HMENU)0x0,*(HINSTANCE *)(param_1 + 4),(LPVOID)0x0);
  }
  return;
}



/* 00040418 FUN_00040418 */

/* Boundary evidence: original MIPS .pdata 00040418..000404af. Semantic name remains unreviewed. */

void FUN_00040418(int param_1)

{
  bool bVar1;
  undefined1 local_18 [8];
  
  bVar1 = DAT_000593d0 != 1;
  if (bVar1) {
    local_18[0] = 1;
    FUN_00015b90(DAT_000553cc,0,0x30,(int)local_18,1,0x32);
  }
  else {
    local_18[0] = 0;
    FUN_00015b90(DAT_000553cc,0,0x30,(int)local_18,1,0x32);
  }
  DAT_000593d0 = (uint)bVar1;
  DestroyWindow(*(HWND *)(param_1 + 0xc));
  return;
}



/* 000404b0 FUN_000404b0 */

/* Boundary evidence: original MIPS .pdata 000404b0..00040507. Semantic name remains unreviewed. */

undefined4 * FUN_000404b0(undefined4 *param_1,uint param_2)

{
  *param_1 = &PTR_FUN_0005336c;
  FUN_0003e4d0(param_1);
  if ((param_2 & 1) != 0) {
    __3_YAXPAX_Z(param_1);
  }
  return param_1;
}



/* 00040508 FUN_00040508 */

/* Boundary evidence: original MIPS .pdata 00040508..0004080f. Semantic name remains unreviewed. */

void FUN_00040508(int param_1)

{
  undefined4 uVar1;
  uint uVar2;
  undefined4 auStack_c8 [8];
  WCHAR aWStack_a8 [64];
  uint local_28;
  
  local_28 = DAT_00055374;
  uVar1 = FUN_0003e894();
  uVar2 = FUN_0003e88c();
  FUN_0003b5d0(auStack_c8,*(undefined4 *)(param_1 + 4),*(undefined4 *)(param_1 + 0xc),uVar2,uVar1);
  wsprintfW(aWStack_a8,L"MICOM MANAGER VERSION : %d.%d.%d.%s",4,0,6,L"0410");
  FUN_0003b6ac(auStack_c8,0,aWStack_a8,0,(HMENU)0x0);
  FUN_0003b6ac(auStack_c8,1,L"SET ROM for 6.5.1.DV2-2",7,(HMENU)0xa);
  FUN_0003b604((int)auStack_c8,0);
  DAT_000593d4 = FUN_0003b6ac(auStack_c8,1,L"TEMP :",7,(HMENU)0xd);
  FUN_0003b68c((int)auStack_c8);
  FUN_0003b6ac(auStack_c8,1,L"RADIO TEST",7,(HMENU)0x1);
  FUN_0003b604((int)auStack_c8,0);
  FUN_0003b6ac(auStack_c8,1,L"AF TEST",7,(HMENU)0x2);
  FUN_0003b604((int)auStack_c8,0);
  FUN_0003b6ac(auStack_c8,1,L"AUDIO TEST",7,(HMENU)0x3);
  FUN_0003b604((int)auStack_c8,0);
  FUN_0003b6ac(auStack_c8,1,L"MICOM TEST",7,(HMENU)0x4);
  FUN_0003b604((int)auStack_c8,0);
  FUN_0003b6ac(auStack_c8,1,L"RADIO TUNING",7,(HMENU)0x5);
  FUN_0003b604((int)auStack_c8,0);
  FUN_0003b6ac(auStack_c8,1,L"TUNER ALIGNMENT",7,(HMENU)0x6);
  FUN_0003b604((int)auStack_c8,0);
  FUN_0003b6ac(auStack_c8,1,L"UPDATE FIRMWARE",6,(HMENU)0x7);
  FUN_0003b6ac(auStack_c8,1,L"XXXXX",1,(HMENU)0x8);
  FUN_0003b604((int)auStack_c8,0);
  FUN_0003b6ac(auStack_c8,1,L"MgrLog",2,(HMENU)0x9);
  FUN_0003b6ac(auStack_c8,1,L"BT Test Mode",3,(HMENU)0xb);
  FUN_0003b6ac(auStack_c8,1,L"BT RF MODE TX",3,(HMENU)0xc);
  SetTimer(*(HWND *)(param_1 + 0xc),1000,0x5dc,(TIMERPROC)0x0);
  FUN_0003e4c8();
  FUN_00043604(local_28);
  return;
}



/* 00040810 Unwind@00040810 */

/* Boundary evidence: original MIPS .pdata 00040810..0004083f. Semantic name remains unreviewed. */

void Unwind_00040810(void)

{
  FUN_0003e4c8();
  return;
}



/* 00040840 FUN_00040840 */

/* Boundary evidence: original MIPS .pdata 00040840..00040947. Semantic name remains unreviewed. */

void FUN_00040840(double param_1)

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



/* 00040948 FUN_00040948 */

/* Boundary evidence: original MIPS .pdata 00040948..000409df. Semantic name remains unreviewed. */

void FUN_00040948(double param_1,undefined4 param_2,int param_3)

{
  undefined4 uVar1;
  ushort local_220 [4];
  WCHAR aWStack_218 [260];
  uint local_10;
  
  local_10 = DAT_00055374;
  if (param_3 == 1000) {
    FUN_00016068(DAT_000553cc,9,6,local_220,2,100);
    uVar1 = FUN_00040840(param_1);
    wsprintfW(aWStack_218,L"ULC_TEMP %d,(%d)",(uint)local_220[0],uVar1);
    SetWindowTextW(DAT_000593d4,aWStack_218);
  }
  FUN_00043604(local_10);
  return;
}



/* 000409e0 FUN_000409e0 */

/* Boundary evidence: original MIPS .pdata 000409e0..00042d0f. Semantic name remains unreviewed. */

void FUN_000409e0(int param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  HWND hWnd;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  WPARAM wParam;
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
  
  local_30 = DAT_00055374;
  switch(param_2) {
  case 1:
    puVar1 = (undefined4 *)__2_YAPAXI_Z(0x94);
    if (puVar1 == (undefined4 *)0x0) {
      puVar1 = (undefined4 *)0x0;
    }
    else {
      puVar1 = FUN_0003f6fc(puVar1);
    }
    uVar4 = *(undefined4 *)(param_1 + 0xc);
    uVar3 = *(undefined4 *)(param_1 + 4);
    break;
  case 2:
    puVar1 = (undefined4 *)__2_YAPAXI_Z(0x9b0);
    if (puVar1 == (undefined4 *)0x0) {
      puVar1 = (undefined4 *)0x0;
    }
    else {
      puVar1 = FUN_00033bbc(puVar1);
    }
    FUN_0003e5d0((int)puVar1,*(undefined4 *)(param_1 + 4),*(undefined4 *)(param_1 + 0xc));
    goto switchD_00040a48_default;
  case 3:
    puVar1 = (undefined4 *)__2_YAPAXI_Z(100);
    if (puVar1 == (undefined4 *)0x0) {
      puVar1 = (undefined4 *)0x0;
    }
    else {
      puVar1 = FUN_000385f4(puVar1);
    }
    uVar4 = *(undefined4 *)(param_1 + 0xc);
    uVar3 = *(undefined4 *)(param_1 + 4);
    break;
  case 4:
    puVar1 = (undefined4 *)__2_YAPAXI_Z(0x58);
    if (puVar1 == (undefined4 *)0x0) {
      puVar1 = (undefined4 *)0x0;
    }
    else {
      puVar1 = FUN_0003b868(puVar1);
    }
    uVar4 = *(undefined4 *)(param_1 + 0xc);
    uVar3 = *(undefined4 *)(param_1 + 4);
    break;
  case 5:
    puVar1 = (undefined4 *)__2_YAPAXI_Z(0x10);
    if (puVar1 == (undefined4 *)0x0) {
      puVar1 = (undefined4 *)0x0;
    }
    else {
      puVar1 = FUN_000402d4(puVar1);
    }
    uVar4 = *(undefined4 *)(param_1 + 0xc);
    uVar3 = *(undefined4 *)(param_1 + 4);
    break;
  case 6:
    puVar1 = (undefined4 *)__2_YAPAXI_Z(0x40);
    if (puVar1 == (undefined4 *)0x0) {
      puVar1 = (undefined4 *)0x0;
    }
    else {
      puVar1 = FUN_0003eb6c(puVar1);
    }
    uVar4 = *(undefined4 *)(param_1 + 0xc);
    uVar3 = *(undefined4 *)(param_1 + 4);
    break;
  case 7:
    DestroyWindow(*(HWND *)(param_1 + 0xc));
    lParam = 0x1235;
    goto LAB_00040c04;
  case 8:
    DestroyWindow(*(HWND *)(param_1 + 0xc));
    lParam = 0x1236;
LAB_00040c04:
    hWnd = *(HWND *)(param_1 + 8);
    wParam = 0xc70300;
LAB_00040c10:
    PostMessageW(hWnd,0x8064,wParam,lParam);
    goto switchD_00040a48_default;
  case 9:
    hWnd = FindWindowW((LPCWSTR)0x0,L"cMgrLog");
    lParam = 0;
    wParam = 0;
    goto LAB_00040c10;
  case 10:
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
    FUN_00015b90(DAT_000553cc,0xf,0x11,(int)&local_430,0x80,300);
    FUN_00015b90(DAT_000553cc,0xf,0x12,(int)&local_3b0,0x80,300);
    FUN_00015b90(DAT_000553cc,0xf,0x13,(int)&local_330,0x80,300);
    FUN_00015b90(DAT_000553cc,0xf,0x14,(int)&local_2b0,0x80,300);
    FUN_00015b90(DAT_000553cc,0xf,0x15,(int)&local_230,0x80,300);
    FUN_00015b90(DAT_000553cc,0xf,0x16,(int)&local_1b0,0x80,300);
    FUN_00015b90(DAT_000553cc,0xf,0x17,(int)auStack_130,0x80,300);
    FUN_00015b90(DAT_000553cc,0xf,0x18,(int)auStack_b0,0x80,300);
    FUN_00015b90(DAT_000553cc,0xf,0x21,(int)&local_830,0x80,300);
    FUN_00015b90(DAT_000553cc,0xf,0x22,(int)&local_7b0,0x80,300);
    FUN_00015b90(DAT_000553cc,0xf,0x23,(int)&local_730,0x80,300);
    FUN_00015b90(DAT_000553cc,0xf,0x24,(int)&local_6b0,0x80,300);
    FUN_00015b90(DAT_000553cc,0xf,0x25,(int)&local_630,0x80,300);
    FUN_00015b90(DAT_000553cc,0xf,0x26,(int)&local_5b0,0x80,300);
    FUN_00015b90(DAT_000553cc,0xf,0x27,(int)&local_530,0x80,300);
    FUN_00015b90(DAT_000553cc,0xf,0x28,(int)&local_4b0,0x80,300);
    goto switchD_00040a48_default;
  case 0xb:
    iVar2 = 0x1010b01;
    goto LAB_00040c5c;
  case 0xc:
    iVar2 = 0x3010c02;
LAB_00040c5c:
    FUN_00033964(iVar2,0,0);
  default:
    goto switchD_00040a48_default;
  }
  FUN_0003e4e0((int)puVar1,uVar3,uVar4);
switchD_00040a48_default:
  FUN_00043604(local_30);
  return;
}



/* 00042d10 Unwind@00042d10 */

/* Boundary evidence: original MIPS .pdata 00042d10..00042d3f. Semantic name remains unreviewed. */

void Unwind_00042d10(void)

{
  int in_v0;
  
  __3_YAXPAX_Z(*(undefined4 *)(in_v0 + -0x838));
  return;
}



/* 00042d40 Unwind@00042d40 */

/* Boundary evidence: original MIPS .pdata 00042d40..00042d6f. Semantic name remains unreviewed. */

void Unwind_00042d40(void)

{
  int in_v0;
  
  __3_YAXPAX_Z(*(undefined4 *)(in_v0 + -0x838));
  return;
}



/* 00042d70 Unwind@00042d70 */

/* Boundary evidence: original MIPS .pdata 00042d70..00042d9f. Semantic name remains unreviewed. */

void Unwind_00042d70(void)

{
  int in_v0;
  
  __3_YAXPAX_Z(*(undefined4 *)(in_v0 + -0x838));
  return;
}



/* 00042da0 Unwind@00042da0 */

/* Boundary evidence: original MIPS .pdata 00042da0..00042dcf. Semantic name remains unreviewed. */

void Unwind_00042da0(void)

{
  int in_v0;
  
  __3_YAXPAX_Z(*(undefined4 *)(in_v0 + -0x838));
  return;
}



/* 00042dd0 Unwind@00042dd0 */

/* Boundary evidence: original MIPS .pdata 00042dd0..00042dff. Semantic name remains unreviewed. */

void Unwind_00042dd0(void)

{
  int in_v0;
  
  __3_YAXPAX_Z(*(undefined4 *)(in_v0 + -0x838));
  return;
}



/* 00042e00 Unwind@00042e00 */

/* Boundary evidence: original MIPS .pdata 00042e00..00042e2f. Semantic name remains unreviewed. */

void Unwind_00042e00(void)

{
  int in_v0;
  
  __3_YAXPAX_Z(*(undefined4 *)(in_v0 + -0x838));
  return;
}



/* 00042e30 FUN_00042e30 */

/* Boundary evidence: original MIPS .pdata 00042e30..00042e63. Semantic name remains unreviewed. */

void FUN_00042e30(int param_1)

{
  KillTimer(*(HWND *)(param_1 + 0xc),1000);
  FUN_000207e0(DAT_00055498);
  FUN_0003e428();
  return;
}



/* 00042e64 FUN_00042e64 */

/* Boundary evidence: original MIPS .pdata 00042e64..00042ef7. Semantic name remains unreviewed. */

void FUN_00042e64(undefined4 param_1)

{
  undefined4 *puVar1;
  
  FUN_0003ea24();
  puVar1 = (undefined4 *)__2_YAPAXI_Z(0x10);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    FUN_0003e4a8(puVar1);
    *puVar1 = &PTR_FUN_000535f8;
  }
  DAT_000593d8 = puVar1;
  FUN_0003e4e0((int)puVar1,DAT_00055600,param_1);
  return;
}



/* 00042ef8 Unwind@00042ef8 */

/* Boundary evidence: original MIPS .pdata 00042ef8..00042f27. Semantic name remains unreviewed. */

void Unwind_00042ef8(void)

{
  int in_v0;
  
  __3_YAXPAX_Z(*(undefined4 *)(in_v0 + -0x18));
  return;
}



/* 00042f28 FUN_00042f28 */

/* Boundary evidence: original MIPS .pdata 00042f28..00042f7f. Semantic name remains unreviewed. */

undefined4 * FUN_00042f28(undefined4 *param_1,uint param_2)

{
  *param_1 = &PTR_FUN_000535f8;
  FUN_0003e4d0(param_1);
  if ((param_2 & 1) != 0) {
    __3_YAXPAX_Z(param_1);
  }
  return param_1;
}



/* 00043500 FUN_00043500 */

/* Boundary evidence: original MIPS .pdata 00043500..00043573. Semantic name remains unreviewed. */

void FUN_00043500(void)

{
  uint uVar1;
  
  if ((DAT_00055374 == 0) || (DAT_00055374 == 0xb064)) {
    uVar1 = __security_gen_cookie2();
    DAT_00055374 = uVar1 >> 0x10 ^ uVar1 & 0xffff;
    if (DAT_00055374 == 0) {
      DAT_00055374 = 0xb064;
    }
  }
  DAT_00055378 = ~DAT_00055374;
  return;
}



/* 00043574 FUN_00043574 */

/* Boundary evidence: original MIPS .pdata 00043574..000435c7. Semantic name remains unreviewed. */

void FUN_00043574(int param_1,undefined4 param_2,uint *param_3)

{
  if ((*param_3 & 1) != 0) {
    param_1 = ((-param_3[2] & param_3[1] + param_1) - (param_3[1] + param_1)) + param_1;
  }
  FUN_00043604(*(uint *)(param_1 + (*param_3 & 0xfffffffc)));
  return;
}



/* 000435c8 FUN_000435c8 */

/* Boundary evidence: original MIPS .pdata 000435c8..000435f3. Semantic name remains unreviewed. */

undefined4 FUN_000435c8(undefined4 param_1,int param_2,undefined4 param_3,int param_4)

{
  FUN_00043574(param_2,param_4,*(uint **)(*(int *)(param_4 + 4) + 0xc));
  return 1;
}



/* 00043604 FUN_00043604 */

/* Boundary evidence: original MIPS .pdata 00043604..0004364b. Semantic name remains unreviewed. */

void FUN_00043604(uint param_1)

{
  if ((param_1 == DAT_00055374) && (param_1 >> 0x10 == 0)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __report_gsfailure();
}



/* 0004382c FUN_0004382c */

/* Boundary evidence: original MIPS .pdata 0004382c..0004389b. Semantic name remains unreviewed. */

void FUN_0004382c(undefined4 param_1,int param_2,undefined4 param_3,int param_4)

{
  FUN_00043574(param_2,param_4,(uint *)(*(int *)(*(int *)(param_4 + 4) + 0xc) + 0x24));
                    /* WARNING: Subroutine does not return */
  __CxxFrameHandler3(param_1,param_2,param_3,param_4);
}



/* 000438ac FUN_000438ac */

/* Boundary evidence: original MIPS .pdata 000438ac..000439b7. Semantic name remains unreviewed. */

undefined4 FUN_000438ac(undefined4 param_1)

{
  void *_Memory;
  uint uVar1;
  void *pvVar2;
  uint _NewSize;
  undefined4 *puVar3;
  int iVar4;
  
  _Memory = DAT_000593e4;
  puVar3 = DAT_000593e0;
  iVar4 = (int)DAT_000593e0 - (int)DAT_000593e4;
  uVar1 = 0;
  if (iVar4 < 0) {
LAB_000438f0:
    param_1 = 0;
  }
  else {
    if (DAT_000593e4 != (void *)0x0) {
      uVar1 = _msize(DAT_000593e4);
    }
    pvVar2 = _Memory;
    if (uVar1 < iVar4 + 4U) {
      if (_Memory == (void *)0x0) {
        pvVar2 = malloc(0x10);
LAB_00043964:
        if (pvVar2 == (void *)0x0) goto LAB_000438f0;
      }
      else {
        _NewSize = uVar1 << 1;
        if (0x200 < uVar1) {
          _NewSize = uVar1 + 0x200;
        }
        if ((_NewSize <= uVar1) || (pvVar2 = realloc(_Memory,_NewSize), pvVar2 == (void *)0x0)) {
          pvVar2 = realloc(_Memory,iVar4 + 4U);
          goto LAB_00043964;
        }
      }
      puVar3 = (undefined4 *)((iVar4 >> 2) * 4 + (int)pvVar2);
    }
    DAT_000593e0 = puVar3 + 1;
    *puVar3 = param_1;
    DAT_000593e4 = pvVar2;
  }
  return param_1;
}



/* 000439b8 FUN_000439b8 */

/* Boundary evidence: original MIPS .pdata 000439b8..00043aa3. Semantic name remains unreviewed. */

undefined4 FUN_000439b8(undefined4 param_1)

{
  LPCRITICAL_SECTION lpCriticalSection;
  LONG LVar1;
  undefined4 uVar2;
  
  if (DAT_000593e8 == (LPCRITICAL_SECTION)0x0) {
    lpCriticalSection = malloc(0x14);
    if (lpCriticalSection != (LPCRITICAL_SECTION)0x0) {
      InitializeCriticalSection(lpCriticalSection);
      LVar1 = InterlockedCompareExchange((LONG *)&DAT_000593e8,(LONG)lpCriticalSection,0);
      if (LVar1 != 0) {
        DeleteCriticalSection(lpCriticalSection);
        free(lpCriticalSection);
      }
    }
    if (DAT_000593e8 == (LPCRITICAL_SECTION)0x0) goto LAB_00043a5c;
  }
  EnterCriticalSection(DAT_000593e8);
LAB_00043a5c:
  uVar2 = FUN_000438ac(param_1);
  FUN_00043aa4();
  return uVar2;
}



/* 00043aa4 FUN_00043aa4 */

/* Boundary evidence: original MIPS .pdata 00043aa4..00043aef. Semantic name remains unreviewed. */

void FUN_00043aa4(void)

{
  if (DAT_000593e8 != (LPCRITICAL_SECTION)0x0) {
    LeaveCriticalSection(DAT_000593e8);
  }
  return;
}



/* 00043af0 FUN_00043af0 */

/* Boundary evidence: original MIPS .pdata 00043af0..00043b1f. Semantic name remains unreviewed. */

undefined4 FUN_00043af0(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_000439b8(param_1);
  if (iVar1 == 0) {
    uVar2 = 0xffffffff;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}



/* 00043c60 FUN_00043c60 */

/* Boundary evidence: original MIPS .pdata 00043c60..00043cf3. Semantic name remains unreviewed. */

void FUN_00043c60(HINSTANCE param_1,undefined4 param_2,wchar_t *param_3)

{
  UINT UVar1;
  
  FUN_00043fd0();
  UVar1 = FUN_00025bd0(param_1,param_2,param_3);
  FUN_00043f10(UVar1);
  FUN_00043f30(UVar1);
  return;
}



/* 00043cf4 FUN_00043cf4 */

/* Boundary evidence: original MIPS .pdata 00043cf4..00043d33. Semantic name remains unreviewed. */

void FUN_00043cf4(_EXCEPTION_POINTERS *param_1)

{
  int in_v0;
  
  *(DWORD *)(in_v0 + -0x20) = param_1->ExceptionRecord->ExceptionCode;
  _XcptFilter(*(ulong *)(in_v0 + -0x20),param_1);
  return;
}



/* 00043d34 entry */

/* Boundary evidence: original MIPS .pdata 00043d34..00043d8f. Semantic name remains unreviewed. */

void entry(HINSTANCE param_1,undefined4 param_2,wchar_t *param_3)

{
  FUN_00043500();
  FUN_00043c60(param_1,param_2,param_3);
  return;
}



/* 00043df0 FUN_00043df0 */

/* Boundary evidence: original MIPS .pdata 00043df0..00043f0f. Semantic name remains unreviewed. */

void FUN_00043df0(UINT param_1,int param_2,int param_3)

{
  LPCRITICAL_SECTION lpCriticalSection;
  undefined4 *_Memory;
  
  DAT_000593dc = (undefined1)param_3;
  if (param_2 == 0) {
    _Memory = DAT_000593e4;
    if (DAT_000593e4 != (undefined4 *)0x0) {
      while (DAT_000593e0 = DAT_000593e0 + -1, _Memory <= DAT_000593e0) {
        if ((code *)*DAT_000593e0 != (code *)0x0) {
          (*(code *)*DAT_000593e0)();
          _Memory = DAT_000593e4;
        }
      }
      free(_Memory);
      DAT_000593e0 = (undefined4 *)0x0;
      DAT_000593e4 = (undefined4 *)0x0;
    }
    FUN_00043f7c((undefined4 *)&DAT_000450d4,(undefined4 *)&DAT_000450d8);
  }
  FUN_00043f7c((undefined4 *)&DAT_000450dc,(undefined4 *)&DAT_000450e0);
  if (param_3 == 0) {
    TerminateProcess((HANDLE)0x42,param_1);
  }
  else {
    lpCriticalSection = (LPCRITICAL_SECTION)InterlockedExchange(&DAT_000593e8,0);
    if (lpCriticalSection != (LPCRITICAL_SECTION)0x0) {
      DeleteCriticalSection(lpCriticalSection);
      free(lpCriticalSection);
    }
  }
  return;
}



/* 00043f10 FUN_00043f10 */

/* Boundary evidence: original MIPS .pdata 00043f10..00043f2f. Semantic name remains unreviewed. */

void FUN_00043f10(UINT param_1)

{
  FUN_00043df0(param_1,0,0);
  return;
}



/* 00043f30 FUN_00043f30 */

/* Boundary evidence: original MIPS .pdata 00043f30..00043f7b. Semantic name remains unreviewed. */

void FUN_00043f30(UINT param_1)

{
  DAT_000593dc = 0;
  FUN_00043f7c((undefined4 *)&DAT_000450dc,(undefined4 *)&DAT_000450e0);
  TerminateProcess((HANDLE)0x42,param_1);
  return;
}



/* 00043f7c FUN_00043f7c */

/* Boundary evidence: original MIPS .pdata 00043f7c..00043fcf. Semantic name remains unreviewed. */

void FUN_00043f7c(undefined4 *param_1,undefined4 *param_2)

{
  for (; param_1 < param_2; param_1 = param_1 + 1) {
    if ((code *)*param_1 != (code *)0x0) {
      (*(code *)*param_1)();
    }
  }
  return;
}



/* 00043fd0 FUN_00043fd0 */

/* Boundary evidence: original MIPS .pdata 00043fd0..0004400b. Semantic name remains unreviewed. */

void FUN_00043fd0(void)

{
  FUN_00043f7c((undefined4 *)&DAT_000450cc,(undefined4 *)&DAT_000450d0);
  FUN_00043f7c((undefined4 *)&DAT_00045000,(undefined4 *)&DAT_000450c8);
  return;
}



/* 0004404c FUN_0004404c */

/* Boundary evidence: original MIPS .pdata 0004404c..00044073. Semantic name remains unreviewed. */

void FUN_0004404c(void)

{
  DAT_00055388 = RegisterWindowMessageW(L"System Language Change");
  return;
}



/* 00044074 FUN_00044074 */

/* Boundary evidence: original MIPS .pdata 00044074..0004409b. Semantic name remains unreviewed. */

void FUN_00044074(void)

{
  DAT_0005538c = RegisterWindowMessageW(L"ULC ACC OFF STATE");
  return;
}



/* 0004409c FUN_0004409c */

/* Boundary evidence: original MIPS .pdata 0004409c..000440c3. Semantic name remains unreviewed. */

void FUN_0004409c(void)

{
  DAT_00055390 = RegisterWindowMessageW(L"ULC FACTORY RESET");
  return;
}



/* 000440c4 FUN_000440c4 */

/* Boundary evidence: original MIPS .pdata 000440c4..000440eb. Semantic name remains unreviewed. */

void FUN_000440c4(void)

{
  DAT_00055394 = RegisterWindowMessageW(L"ULC RVC COLOR");
  return;
}



/* 000440ec FUN_000440ec */

/* Boundary evidence: original MIPS .pdata 000440ec..00044113. Semantic name remains unreviewed. */

void FUN_000440ec(void)

{
  DAT_00055398 = RegisterWindowMessageW(L"ULC TESTTOOL");
  return;
}



/* 00044114 FUN_00044114 */

/* Boundary evidence: original MIPS .pdata 00044114..0004413b. Semantic name remains unreviewed. */

void FUN_00044114(void)

{
  DAT_000553b8 = RegisterWindowMessageW(L"System Language Change");
  return;
}



/* 0004413c FUN_0004413c */

/* Boundary evidence: original MIPS .pdata 0004413c..00044163. Semantic name remains unreviewed. */

void FUN_0004413c(void)

{
  DAT_000553bc = RegisterWindowMessageW(L"ULC ACC OFF STATE");
  return;
}



/* 00044164 FUN_00044164 */

/* Boundary evidence: original MIPS .pdata 00044164..0004418b. Semantic name remains unreviewed. */

void FUN_00044164(void)

{
  DAT_000553c0 = RegisterWindowMessageW(L"ULC FACTORY RESET");
  return;
}



/* 0004418c FUN_0004418c */

/* Boundary evidence: original MIPS .pdata 0004418c..000441b3. Semantic name remains unreviewed. */

void FUN_0004418c(void)

{
  DAT_000553c4 = RegisterWindowMessageW(L"ULC RVC COLOR");
  return;
}



/* 000441b4 FUN_000441b4 */

/* Boundary evidence: original MIPS .pdata 000441b4..000441db. Semantic name remains unreviewed. */

void FUN_000441b4(void)

{
  DAT_000553c8 = RegisterWindowMessageW(L"ULC TESTTOOL");
  return;
}



/* 000441dc FUN_000441dc */

/* Boundary evidence: original MIPS .pdata 000441dc..00044203. Semantic name remains unreviewed. */

void FUN_000441dc(void)

{
  DAT_000553ec = RegisterWindowMessageW(L"System Language Change");
  return;
}



/* 00044204 FUN_00044204 */

/* Boundary evidence: original MIPS .pdata 00044204..0004422b. Semantic name remains unreviewed. */

void FUN_00044204(void)

{
  DAT_000553f0 = RegisterWindowMessageW(L"ULC ACC OFF STATE");
  return;
}



/* 0004422c FUN_0004422c */

/* Boundary evidence: original MIPS .pdata 0004422c..00044253. Semantic name remains unreviewed. */

void FUN_0004422c(void)

{
  DAT_000553f4 = RegisterWindowMessageW(L"ULC FACTORY RESET");
  return;
}



/* 00044254 FUN_00044254 */

/* Boundary evidence: original MIPS .pdata 00044254..0004427b. Semantic name remains unreviewed. */

void FUN_00044254(void)

{
  DAT_000553f8 = RegisterWindowMessageW(L"ULC RVC COLOR");
  return;
}



/* 0004427c FUN_0004427c */

/* Boundary evidence: original MIPS .pdata 0004427c..000442a3. Semantic name remains unreviewed. */

void FUN_0004427c(void)

{
  DAT_000553fc = RegisterWindowMessageW(L"ULC TESTTOOL");
  return;
}



/* 000442a4 FUN_000442a4 */

/* Boundary evidence: original MIPS .pdata 000442a4..000442cb. Semantic name remains unreviewed. */

void FUN_000442a4(void)

{
  DAT_00055400 = RegisterWindowMessageW(L"RVC MODE");
  return;
}



/* 000442cc FUN_000442cc */

/* Boundary evidence: original MIPS .pdata 000442cc..000442f3. Semantic name remains unreviewed. */

void FUN_000442cc(void)

{
  DAT_00055480 = RegisterWindowMessageW(L"System Language Change");
  return;
}



/* 000442f4 FUN_000442f4 */

/* Boundary evidence: original MIPS .pdata 000442f4..0004431b. Semantic name remains unreviewed. */

void FUN_000442f4(void)

{
  DAT_00055484 = RegisterWindowMessageW(L"ULC ACC OFF STATE");
  return;
}



/* 0004431c FUN_0004431c */

/* Boundary evidence: original MIPS .pdata 0004431c..00044343. Semantic name remains unreviewed. */

void FUN_0004431c(void)

{
  DAT_00055488 = RegisterWindowMessageW(L"ULC FACTORY RESET");
  return;
}



/* 00044344 FUN_00044344 */

/* Boundary evidence: original MIPS .pdata 00044344..0004436b. Semantic name remains unreviewed. */

void FUN_00044344(void)

{
  DAT_0005548c = RegisterWindowMessageW(L"ULC RVC COLOR");
  return;
}



/* 0004436c FUN_0004436c */

/* Boundary evidence: original MIPS .pdata 0004436c..00044393. Semantic name remains unreviewed. */

void FUN_0004436c(void)

{
  DAT_00055490 = RegisterWindowMessageW(L"ULC TESTTOOL");
  return;
}



/* 00044394 FUN_00044394 */

/* Boundary evidence: original MIPS .pdata 00044394..000443bb. Semantic name remains unreviewed. */

void FUN_00044394(void)

{
  DAT_000554b0 = RegisterWindowMessageW(L"System Language Change");
  return;
}



/* 000443bc FUN_000443bc */

/* Boundary evidence: original MIPS .pdata 000443bc..000443e3. Semantic name remains unreviewed. */

void FUN_000443bc(void)

{
  DAT_000554b4 = RegisterWindowMessageW(L"ULC ACC OFF STATE");
  return;
}



/* 000443e4 FUN_000443e4 */

/* Boundary evidence: original MIPS .pdata 000443e4..0004440b. Semantic name remains unreviewed. */

void FUN_000443e4(void)

{
  DAT_000554b8 = RegisterWindowMessageW(L"ULC FACTORY RESET");
  return;
}



/* 0004440c FUN_0004440c */

/* Boundary evidence: original MIPS .pdata 0004440c..00044433. Semantic name remains unreviewed. */

void FUN_0004440c(void)

{
  DAT_000554bc = RegisterWindowMessageW(L"ULC RVC COLOR");
  return;
}



/* 00044434 FUN_00044434 */

/* Boundary evidence: original MIPS .pdata 00044434..0004445b. Semantic name remains unreviewed. */

void FUN_00044434(void)

{
  DAT_000554c0 = RegisterWindowMessageW(L"ULC TESTTOOL");
  return;
}



/* 0004445c FUN_0004445c */

/* Boundary evidence: original MIPS .pdata 0004445c..00044483. Semantic name remains unreviewed. */

void FUN_0004445c(void)

{
  DAT_00055620 = RegisterWindowMessageW(L"System Language Change");
  return;
}



/* 00044484 FUN_00044484 */

/* Boundary evidence: original MIPS .pdata 00044484..000444ab. Semantic name remains unreviewed. */

void FUN_00044484(void)

{
  DAT_00055624 = RegisterWindowMessageW(L"ULC ACC OFF STATE");
  return;
}



/* 000444ac FUN_000444ac */

/* Boundary evidence: original MIPS .pdata 000444ac..000444d3. Semantic name remains unreviewed. */

void FUN_000444ac(void)

{
  DAT_00055628 = RegisterWindowMessageW(L"ULC FACTORY RESET");
  return;
}



/* 000444d4 FUN_000444d4 */

/* Boundary evidence: original MIPS .pdata 000444d4..000444fb. Semantic name remains unreviewed. */

void FUN_000444d4(void)

{
  DAT_0005562c = RegisterWindowMessageW(L"ULC RVC COLOR");
  return;
}



/* 000444fc FUN_000444fc */

/* Boundary evidence: original MIPS .pdata 000444fc..00044523. Semantic name remains unreviewed. */

void FUN_000444fc(void)

{
  DAT_00055630 = RegisterWindowMessageW(L"ULC TESTTOOL");
  return;
}



/* 00044524 FUN_00044524 */

/* Boundary evidence: original MIPS .pdata 00044524..0004454b. Semantic name remains unreviewed. */

void FUN_00044524(void)

{
  DAT_00055634 = RegisterWindowMessageW(L"Sudden Power down");
  return;
}



/* 0004454c FUN_0004454c */

/* Boundary evidence: original MIPS .pdata 0004454c..00044577. Semantic name remains unreviewed. */

void FUN_0004454c(void)

{
  FUN_00025f0c((undefined4 *)&DAT_00055638);
  FUN_00043af0(FUN_000447fc);
  return;
}



/* 00044578 FUN_00044578 */

/* Boundary evidence: original MIPS .pdata 00044578..000445a3. Semantic name remains unreviewed. */

void FUN_00044578(void)

{
  FUN_0002668c((undefined4 *)&DAT_000556dc);
  FUN_00043af0(FUN_0004481c);
  return;
}



/* 000445a4 FUN_000445a4 */

/* Boundary evidence: original MIPS .pdata 000445a4..000445cb. Semantic name remains unreviewed. */

void FUN_000445a4(void)

{
  DAT_00057334 = RegisterWindowMessageW(L"System Language Change");
  return;
}



/* 000445cc FUN_000445cc */

/* Boundary evidence: original MIPS .pdata 000445cc..000445f3. Semantic name remains unreviewed. */

void FUN_000445cc(void)

{
  DAT_00057338 = RegisterWindowMessageW(L"ULC ACC OFF STATE");
  return;
}



/* 000445f4 FUN_000445f4 */

/* Boundary evidence: original MIPS .pdata 000445f4..0004461b. Semantic name remains unreviewed. */

void FUN_000445f4(void)

{
  DAT_0005733c = RegisterWindowMessageW(L"ULC FACTORY RESET");
  return;
}



/* 0004461c FUN_0004461c */

/* Boundary evidence: original MIPS .pdata 0004461c..00044643. Semantic name remains unreviewed. */

void FUN_0004461c(void)

{
  DAT_00057340 = RegisterWindowMessageW(L"ULC RVC COLOR");
  return;
}



/* 00044644 FUN_00044644 */

/* Boundary evidence: original MIPS .pdata 00044644..0004466b. Semantic name remains unreviewed. */

void FUN_00044644(void)

{
  DAT_00057344 = RegisterWindowMessageW(L"ULC TESTTOOL");
  return;
}



/* 0004466c FUN_0004466c */

/* Boundary evidence: original MIPS .pdata 0004466c..00044693. Semantic name remains unreviewed. */

void FUN_0004466c(void)

{
  DAT_00059370 = RegisterWindowMessageW(L"System Language Change");
  return;
}



/* 00044694 FUN_00044694 */

/* Boundary evidence: original MIPS .pdata 00044694..000446bb. Semantic name remains unreviewed. */

void FUN_00044694(void)

{
  DAT_00059374 = RegisterWindowMessageW(L"ULC ACC OFF STATE");
  return;
}



/* 000446bc FUN_000446bc */

/* Boundary evidence: original MIPS .pdata 000446bc..000446e3. Semantic name remains unreviewed. */

void FUN_000446bc(void)

{
  DAT_00059378 = RegisterWindowMessageW(L"ULC FACTORY RESET");
  return;
}



/* 000446e4 FUN_000446e4 */

/* Boundary evidence: original MIPS .pdata 000446e4..0004470b. Semantic name remains unreviewed. */

void FUN_000446e4(void)

{
  DAT_0005937c = RegisterWindowMessageW(L"ULC RVC COLOR");
  return;
}



/* 0004470c FUN_0004470c */

/* Boundary evidence: original MIPS .pdata 0004470c..00044733. Semantic name remains unreviewed. */

void FUN_0004470c(void)

{
  DAT_00059380 = RegisterWindowMessageW(L"ULC TESTTOOL");
  return;
}



/* 00044734 FUN_00044734 */

/* Boundary evidence: original MIPS .pdata 00044734..0004475b. Semantic name remains unreviewed. */

void FUN_00044734(void)

{
  DAT_00059394 = RegisterWindowMessageW(L"System Language Change");
  return;
}



/* 0004475c FUN_0004475c */

/* Boundary evidence: original MIPS .pdata 0004475c..00044783. Semantic name remains unreviewed. */

void FUN_0004475c(void)

{
  DAT_00059398 = RegisterWindowMessageW(L"ULC ACC OFF STATE");
  return;
}



/* 00044784 FUN_00044784 */

/* Boundary evidence: original MIPS .pdata 00044784..000447ab. Semantic name remains unreviewed. */

void FUN_00044784(void)

{
  DAT_0005939c = RegisterWindowMessageW(L"ULC FACTORY RESET");
  return;
}



/* 000447ac FUN_000447ac */

/* Boundary evidence: original MIPS .pdata 000447ac..000447d3. Semantic name remains unreviewed. */

void FUN_000447ac(void)

{
  DAT_000593a0 = RegisterWindowMessageW(L"ULC RVC COLOR");
  return;
}



/* 000447d4 FUN_000447d4 */

/* Boundary evidence: original MIPS .pdata 000447d4..000447fb. Semantic name remains unreviewed. */

void FUN_000447d4(void)

{
  DAT_000593a4 = RegisterWindowMessageW(L"ULC TESTTOOL");
  return;
}



/* 000447fc FUN_000447fc */

/* Boundary evidence: original MIPS .pdata 000447fc..0004481b. Semantic name remains unreviewed. */

void FUN_000447fc(void)

{
  FUN_0003e4c8();
  return;
}



/* 0004481c FUN_0004481c */

/* Boundary evidence: original MIPS .pdata 0004481c..0004483b. Semantic name remains unreviewed. */

void FUN_0004481c(void)

{
  FUN_0003e4c8();
  return;
}


