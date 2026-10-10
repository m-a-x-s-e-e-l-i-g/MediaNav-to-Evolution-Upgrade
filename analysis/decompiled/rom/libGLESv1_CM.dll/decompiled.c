/* Automatic Ghidra pseudocode. Not original source; not runtime-verified. */

/* 409636ac FUN_409636ac */

/* Boundary evidence: original MIPS .pdata 409636ac..409636d7. Semantic name remains unreviewed. */

undefined4 FUN_409636ac(HMODULE param_1,int param_2)

{
  if (param_2 == 1) {
    DisableThreadLibraryCalls(param_1);
  }
  return 1;
}



/* 409636d8 FUN_409636d8 */

/* Boundary evidence: original MIPS .pdata 409636d8..40963813. Semantic name remains unreviewed. */

int FUN_409636d8(HMODULE param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 1;
  if (param_2 == 1) {
    if (DAT_40996370 != (code *)0x0) {
      iVar2 = (*DAT_40996370)(param_1,1,param_3);
    }
    iVar1 = 0;
    if (iVar2 == 0) goto LAB_40963788;
    FUN_40963a44();
  }
  iVar1 = 0;
  if (iVar2 != 0) {
    iVar1 = FUN_409636ac(param_1,param_2);
  }
LAB_40963788:
  if (((param_2 == 0) && (FUN_409639cc(), iVar1 != 0)) && (DAT_40996370 != (code *)0x0)) {
    iVar1 = (*DAT_40996370)(param_1,0,param_3);
  }
  return iVar1;
}



/* 40963814 FUN_40963814 */

/* Boundary evidence: original MIPS .pdata 40963814..4096383f. Semantic name remains unreviewed. */

void FUN_40963814(_EXCEPTION_POINTERS *param_1)

{
  _XcptFilter(param_1->ExceptionRecord->ExceptionCode,param_1);
  return;
}



/* 40963840 entry */

/* Boundary evidence: original MIPS .pdata 40963840..40963897. Semantic name remains unreviewed. */

void entry(HMODULE param_1,int param_2,undefined4 param_3)

{
  if (param_2 == 1) {
    FUN_40963a80();
  }
  FUN_409636d8(param_1,param_2,param_3);
  return;
}



/* 40963898 FUN_40963898 */

/* Boundary evidence: original MIPS .pdata 40963898..409638df. Semantic name remains unreviewed. */

void FUN_40963898(uint param_1)

{
  if ((param_1 == DAT_40996268) && (param_1 >> 0x10 == 0)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __report_gsfailure();
}



/* 409638e0 FUN_409638e0 */

/* Boundary evidence: original MIPS .pdata 409638e0..409639cb. Semantic name remains unreviewed. */

void FUN_409638e0(UINT param_1,int param_2,int param_3)

{
  undefined4 *_Memory;
  
  DAT_40996360 = (undefined1)param_3;
  if (param_2 == 0) {
    _Memory = DAT_4099636c;
    if (DAT_4099636c != (undefined4 *)0x0) {
      while (DAT_40996368 = DAT_40996368 + -1, _Memory <= DAT_40996368) {
        if ((code *)*DAT_40996368 != (code *)0x0) {
          (*(code *)*DAT_40996368)();
          _Memory = DAT_4099636c;
        }
      }
      free(_Memory);
      DAT_40996368 = (undefined4 *)0x0;
      DAT_4099636c = (undefined4 *)0x0;
    }
    FUN_409639f0((undefined4 *)&DAT_40961010,(undefined4 *)&DAT_40961014);
  }
  FUN_409639f0((undefined4 *)&DAT_40961018,(undefined4 *)&DAT_4096101c);
  if (param_3 == 0) {
    TerminateProcess((HANDLE)0x42,param_1);
  }
  return;
}



/* 409639cc FUN_409639cc */

/* Boundary evidence: original MIPS .pdata 409639cc..409639ef. Semantic name remains unreviewed. */

void FUN_409639cc(void)

{
  FUN_409638e0(0,0,1);
  return;
}



/* 409639f0 FUN_409639f0 */

/* Boundary evidence: original MIPS .pdata 409639f0..40963a43. Semantic name remains unreviewed. */

void FUN_409639f0(undefined4 *param_1,undefined4 *param_2)

{
  for (; param_1 < param_2; param_1 = param_1 + 1) {
    if ((code *)*param_1 != (code *)0x0) {
      (*(code *)*param_1)();
    }
  }
  return;
}



/* 40963a44 FUN_40963a44 */

/* Boundary evidence: original MIPS .pdata 40963a44..40963a7f. Semantic name remains unreviewed. */

void FUN_40963a44(void)

{
  FUN_409639f0((undefined4 *)&DAT_40961008,(undefined4 *)&DAT_4096100c);
  FUN_409639f0((undefined4 *)&DAT_40961000,(undefined4 *)&DAT_40961004);
  return;
}



/* 40963a80 FUN_40963a80 */

/* Boundary evidence: original MIPS .pdata 40963a80..40963af3. Semantic name remains unreviewed. */

void FUN_40963a80(void)

{
  uint uVar1;
  
  if ((DAT_40996268 == 0) || (DAT_40996268 == 0xb064)) {
    uVar1 = __security_gen_cookie2();
    DAT_40996268 = uVar1 >> 0x10 ^ uVar1 & 0xffff;
    if (DAT_40996268 == 0) {
      DAT_40996268 = 0xb064;
    }
  }
  DAT_4099626c = ~DAT_40996268;
  return;
}



/* 40963b64 FUN_40963b64 */

undefined4 FUN_40963b64(uint param_1)

{
  uint uVar1;
  
  if ((param_1 & 8) != 0) {
    return 0x400;
  }
  uVar1 = 0x10;
  do {
    if ((param_1 >> (uVar1 & 0x1f) & 3) == 2) {
      return 0x1f0;
    }
    uVar1 = uVar1 + 2;
  } while ((int)uVar1 < 0x20);
  if (0x200 < (param_1 & 0x600)) {
    return 0x170;
  }
  return 0xa4;
}



/* 40963bd4 FUN_40963bd4 */

/* Boundary evidence: original MIPS .pdata 40963bd4..40963c3b. Semantic name remains unreviewed. */

void FUN_40963bd4(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  
  uVar1 = __fpadd(*param_2,*param_3);
  *param_1 = uVar1;
  uVar1 = __fpadd(param_2[1],param_3[1]);
  param_1[1] = uVar1;
  uVar1 = __fpadd(param_2[2],param_3[2]);
  param_1[2] = uVar1;
  return;
}



/* 40963c3c FUN_40963c3c */

/* Boundary evidence: original MIPS .pdata 40963c3c..40963ca3. Semantic name remains unreviewed. */

void FUN_40963c3c(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  uVar1 = __fpmul(*param_2,*param_3);
  uVar3 = param_3[1];
  uVar2 = param_2[1];
  *param_1 = uVar1;
  uVar1 = __fpmul(uVar2,uVar3);
  uVar3 = param_3[2];
  uVar2 = param_2[2];
  param_1[1] = uVar1;
  uVar1 = __fpmul(uVar2,uVar3);
  param_1[2] = uVar1;
  return;
}



/* 40963ce4 FUN_40963ce4 */

/* Boundary evidence: original MIPS .pdata 40963ce4..40963ddb. Semantic name remains unreviewed. */

void FUN_40963ce4(undefined4 *param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  
  uVar4 = param_2[2];
  uVar3 = param_2[1];
  uVar1 = __fpmul(*param_2,*param_2);
  uVar3 = __fpmul(uVar3,uVar3);
  uVar1 = __fpadd(uVar1,uVar3);
  uVar3 = __fpmul(uVar4,uVar4);
  uVar1 = __fpadd(uVar1,uVar3);
  uVar1 = mali_sys_sqrt(uVar1);
  iVar2 = __nes(uVar1,0);
  if (iVar2 == 0) {
    uVar1 = 0x3f800000;
  }
  else {
    uVar1 = __fpdiv(0x3f800000,uVar1);
  }
  uVar3 = __fpmul(*param_2,uVar1);
  uVar4 = param_2[1];
  *param_1 = uVar3;
  uVar3 = __fpmul(uVar1,uVar4);
  uVar4 = param_2[2];
  param_1[1] = uVar3;
  uVar1 = __fpmul(uVar1,uVar4);
  param_1[2] = uVar1;
  return;
}



/* 40963ddc FUN_40963ddc */

/* Boundary evidence: original MIPS .pdata 40963ddc..40963e67. Semantic name remains unreviewed. */

void FUN_40963ddc(int param_1)

{
  int iVar1;
  int iVar2;
  
  mali_sys_memcpy(param_1 + 0x58,*(int *)(param_1 + 0x4cc) + 0x90,0xc);
  mali_sys_memcpy(param_1 + 0x88,*(undefined4 *)(param_1 + 0x4cc),0x10);
  iVar1 = 0;
  iVar2 = param_1 + 0x148;
  do {
    mali_sys_memcpy(iVar2,iVar1 + *(int *)(param_1 + 0x4cc) + 0x10,0x10);
    iVar1 = iVar1 + 0x10;
    iVar2 = iVar2 + 0x30;
  } while (iVar1 < 0x80);
  *(undefined4 *)(param_1 + 0xb8) = *(undefined4 *)(param_1 + 1000);
  return;
}



/* 40963e68 FUN_40963e68 */

void FUN_40963e68(uint param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  uint uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  
  *param_2 = 0;
  uVar2 = param_1 >> 9 & 3;
  uVar4 = 2;
  uVar3 = 3;
  if ((uVar2 == 2) || (uVar1 = 0xffffffff, uVar2 == 3)) {
    uVar1 = 0xc;
  }
  param_2[1] = uVar1;
  if ((uVar2 == 0) || (uVar1 = 0xffffffff, (param_1 & 0x10) != 0)) {
    uVar1 = 1;
  }
  param_2[2] = uVar1;
  uVar1 = 0xd;
  if ((param_1 & 0x1000) == 0) {
    uVar1 = 0xffffffff;
  }
  uVar2 = param_1 >> 3 & 1;
  param_2[3] = uVar1;
  if (uVar2 == 0) {
    uVar3 = 0xffffffff;
  }
  param_2[4] = uVar3;
  if (uVar2 == 0) {
    uVar4 = 0xffffffff;
  }
  param_2[5] = uVar4;
  uVar3 = 4;
  if ((param_1 & 0x30000) == 0) {
    uVar3 = 0xffffffff;
  }
  param_2[6] = uVar3;
  uVar3 = 5;
  if ((param_1 & 0xc0000) == 0) {
    uVar3 = 0xffffffff;
  }
  param_2[7] = uVar3;
  uVar3 = 6;
  if ((param_1 & 0x300000) == 0) {
    uVar3 = 0xffffffff;
  }
  param_2[8] = uVar3;
  uVar3 = 7;
  if ((param_1 & 0xc00000) == 0) {
    uVar3 = 0xffffffff;
  }
  param_2[9] = uVar3;
  uVar3 = 8;
  if ((param_1 & 0x3000000) == 0) {
    uVar3 = 0xffffffff;
  }
  param_2[10] = uVar3;
  uVar3 = 9;
  if ((param_1 & 0xc000000) == 0) {
    uVar3 = 0xffffffff;
  }
  param_2[0xb] = uVar3;
  uVar3 = 10;
  if ((param_1 & 0x30000000) == 0) {
    uVar3 = 0xffffffff;
  }
  param_2[0xc] = uVar3;
  uVar3 = 0xb;
  if ((param_1 & 0xc0000000) == 0) {
    uVar3 = 0xffffffff;
  }
  param_2[0xd] = uVar3;
  param_2[0xe] = 0xffffffff;
  param_2[0xf] = 0xffffffff;
  return;
}



/* 40963fac FUN_40963fac */

/* Boundary evidence: original MIPS .pdata 40963fac..40964107. Semantic name remains unreviewed. */

undefined4 FUN_40963fac(uint *param_1)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar4 = *param_1;
  uVar2 = 0;
  iVar1 = __gts(uVar4,0);
  if (iVar1 == 0) {
    iVar1 = __gts(uVar4 ^ 0x80000000,0);
    uVar3 = 0;
    if (iVar1 != 0) {
      uVar2 = 0xbf800000;
      uVar3 = uVar4 ^ 0x80000000;
    }
  }
  else {
    uVar2 = 0x3f800000;
    uVar3 = uVar4;
  }
  uVar4 = param_1[1];
  iVar1 = __gts(uVar4,uVar3);
  if (iVar1 == 0) {
    iVar1 = __gts(uVar4 ^ 0x80000000,uVar3);
    if (iVar1 != 0) {
      uVar2 = 0xbf800000;
      uVar3 = uVar4 ^ 0x80000000;
    }
  }
  else {
    uVar2 = 0x3f800000;
    uVar3 = uVar4;
  }
  uVar4 = param_1[2];
  iVar1 = __gts(uVar4,uVar3);
  if (iVar1 == 0) {
    iVar1 = __gts(uVar4 ^ 0x80000000,uVar3);
    if (iVar1 != 0) {
      uVar2 = 0xbf800000;
      uVar3 = uVar4 ^ 0x80000000;
    }
  }
  else {
    uVar2 = 0x3f800000;
    uVar3 = uVar4;
  }
  uVar4 = param_1[3];
  iVar1 = __gts(uVar4,uVar3);
  if (iVar1 == 0) {
    iVar1 = __gts(uVar4 ^ 0x80000000,uVar3);
    if (iVar1 != 0) {
      uVar2 = 0xbf800000;
    }
  }
  else {
    uVar2 = 0x3f800000;
  }
  return uVar2;
}



/* 40964154 FUN_40964154 */

/* Boundary evidence: original MIPS .pdata 40964154..40964ae3. Semantic name remains unreviewed. */

void FUN_40964154(int param_1,uint param_2,int param_3,int param_4)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  int iVar7;
  int iVar8;
  undefined4 *puVar9;
  undefined4 *puVar10;
  undefined4 *puVar11;
  int iVar12;
  uint *puVar13;
  undefined4 *puVar14;
  int iVar15;
  int iVar16;
  uint uVar17;
  int iVar18;
  undefined4 *local_a8;
  int local_a0;
  undefined4 local_88 [8];
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
  undefined4 local_2c;
  
  iVar16 = *(int *)(param_1 + 0x4d8);
  puVar13 = (uint *)(param_1 + 0xc);
  if (*(char *)(iVar16 + 0x5f10) != '\0') {
    iVar7 = 0;
    puVar9 = (undefined4 *)(param_3 + 0x290);
    uVar17 = 0;
    local_a0 = 0;
    puVar14 = (undefined4 *)(iVar16 + 0x5f70);
    local_a8 = puVar9;
    do {
      if ((puVar13[(int)uVar17 >> 5] >> (uVar17 & 0x1f) & 1) != 0) {
        if ((*(uint *)(*(int *)(param_1 + 0x508) + 0x1c) & 0x10) == 0x10) {
          puVar11 = puVar9 + 0x2c;
          *puVar11 = puVar14[-2];
          puVar9[0x2d] = puVar14[-1];
          puVar9[0x2e] = *puVar14;
          puVar9[0x6c] = puVar14[2];
          puVar9[0x6d] = puVar14[3];
          puVar9[0x6e] = puVar14[4];
          puVar10 = puVar9;
        }
        else {
          uVar4 = __fpmul(puVar14[-2],*(undefined4 *)(iVar16 + 0x5f14));
          uVar5 = __fpmul(puVar14[-1],*(undefined4 *)(iVar16 + 0x5f18));
          uVar6 = __fpmul(*(undefined4 *)(iVar16 + 0x5f1c),*puVar14);
          uVar1 = __fpmul(puVar14[2],*(undefined4 *)(iVar16 + 0x5f24));
          uVar2 = __fpmul(puVar14[3],*(undefined4 *)(iVar16 + 0x5f28));
          uVar3 = __fpmul(*(undefined4 *)(iVar16 + 0x5f2c),puVar14[4]);
          puVar11 = local_a8 + 0x2c;
          *puVar11 = uVar4;
          local_a8[0x2d] = uVar5;
          local_a8[0x2e] = uVar6;
          local_a8[0x6c] = uVar1;
          local_a8[0x6d] = uVar2;
          local_a8[0x6e] = uVar3;
          puVar10 = local_a8;
        }
        uVar4 = __fpmul(puVar14[6],*(undefined4 *)(iVar16 + 0x5f34));
        uVar5 = __fpmul(puVar14[7],*(undefined4 *)(iVar16 + 0x5f38));
        uVar6 = __fpmul(puVar14[8],*(undefined4 *)(iVar16 + 0x5f3c));
        puVar10[0x8d] = uVar5;
        puVar11[0x60] = uVar4;
        puVar10[0x8e] = uVar6;
        *local_a8 = puVar14[10];
        puVar10[1] = puVar14[0xb];
        puVar10[2] = puVar14[0xc];
        puVar10[3] = puVar14[0xd];
        FUN_40963ce4(local_88,puVar14 + 0x11);
        local_a8[0xac] = local_88[0];
        puVar10[0xad] = local_88[1];
        puVar10[0xae] = local_88[2];
        local_a8[0x43] = puVar14[0x14];
        local_a8[0x23] = puVar14[0x15];
        local_a8[0x4c] = puVar14[0xe];
        puVar9 = local_a8 + 4;
        puVar10[0x4d] = puVar14[0xf];
        iVar7 = local_a0 + 1;
        puVar10[0x4e] = puVar14[0x10];
        local_a8 = puVar9;
        local_a0 = iVar7;
      }
      uVar17 = uVar17 + 1;
      puVar14 = puVar14 + 0x18;
    } while ((int)uVar17 < 8);
    uVar4 = __litofp(iVar7);
    *(undefined4 *)(param_3 + 0x42c) = uVar4;
    uVar4 = __fpmul(*(undefined4 *)(iVar16 + 0x5f14),*(undefined4 *)(iVar16 + 0x5f58));
    uVar5 = __fpmul(*(undefined4 *)(iVar16 + 0x5f18),*(undefined4 *)(iVar16 + 0x5f5c));
    uVar6 = __fpmul(*(undefined4 *)(iVar16 + 0x5f1c),*(undefined4 *)(iVar16 + 0x5f60));
    uVar4 = __fpadd(uVar4,*(undefined4 *)(iVar16 + 0x5f44));
    uVar5 = __fpadd(*(undefined4 *)(iVar16 + 0x5f48),uVar5);
    uVar6 = __fpadd(*(undefined4 *)(iVar16 + 0x5f4c),uVar6);
    *(undefined4 *)(param_3 + 0x270) = *(undefined4 *)(iVar16 + 0x5f58);
    *(undefined4 *)(param_3 + 0x274) = *(undefined4 *)(iVar16 + 0x5f5c);
    *(undefined4 *)(param_3 + 0x278) = *(undefined4 *)(iVar16 + 0x5f60);
    *(undefined4 *)(param_3 + 0x280) = uVar4;
    *(undefined4 *)(param_3 + 0x284) = uVar5;
    *(undefined4 *)(param_3 + 0x288) = uVar6;
    *(undefined4 *)(param_3 + 0x26c) = *(undefined4 *)(iVar16 + 0x5f30);
    *(undefined4 *)(param_3 + 0x250) = *(undefined4 *)(iVar16 + 0x5f44);
    *(undefined4 *)(param_3 + 0x254) = *(undefined4 *)(iVar16 + 0x5f48);
    *(undefined4 *)(param_3 + 600) = *(undefined4 *)(iVar16 + 0x5f4c);
    *(undefined4 *)(param_3 + 0x41c) = *(undefined4 *)(iVar16 + 0x5f54);
  }
  iVar18 = 4;
  *(undefined4 *)(param_3 + 0x260) = *(undefined4 *)(iVar16 + 0x6294);
  *(undefined4 *)(param_3 + 0x264) = *(undefined4 *)(iVar16 + 0x6298);
  *(undefined4 *)(param_3 + 0x268) = *(undefined4 *)(iVar16 + 0x629c);
  iVar7 = *(int *)(iVar16 + 0x55b0);
  iVar8 = *(int *)(iVar16 + 0x55ac) * 0x40 + iVar16;
  puVar9 = (undefined4 *)(iVar8 + 0x5c);
  if ((*puVar13 & 0x200000) != 0) {
    FUN_409684ec(param_1,local_88);
    puVar14 = (undefined4 *)(iVar16 + 0x5e7c);
    iVar15 = 4;
    do {
      puVar11 = local_88;
      puVar10 = puVar14 + -3;
      iVar12 = 3;
      do {
        uVar4 = __fpmul(puVar10[iVar7 * 0x10 + -0x1585],*puVar11);
        iVar12 = iVar12 + -1;
        *puVar10 = uVar4;
        puVar10 = puVar10 + 1;
        puVar11 = puVar11 + 1;
      } while (iVar12 != 0);
      iVar15 = iVar15 + -1;
      *puVar14 = puVar14[iVar7 * 0x10 + -0x1585];
      puVar14 = puVar14 + 4;
    } while (iVar15 != 0);
  }
  if ((*(uint *)(*(int *)(param_1 + 0x508) + 0x1c) & 8) == 0) {
    *(undefined4 *)(param_3 + 400) = *puVar9;
    *(undefined4 *)(param_3 + 0x194) = *(undefined4 *)(iVar8 + 0x60);
    *(undefined4 *)(param_3 + 0x198) = *(undefined4 *)(iVar8 + 100);
    *(undefined4 *)(param_3 + 0x19c) = *(undefined4 *)(iVar8 + 0x68);
    *(undefined4 *)(param_3 + 0x1a0) = *(undefined4 *)(iVar8 + 0x6c);
    *(undefined4 *)(param_3 + 0x1a4) = *(undefined4 *)(iVar8 + 0x70);
    *(undefined4 *)(param_3 + 0x1a8) = *(undefined4 *)(iVar8 + 0x74);
    *(undefined4 *)(param_3 + 0x1ac) = *(undefined4 *)(iVar8 + 0x78);
    *(undefined4 *)(param_3 + 0x1b0) = *(undefined4 *)(iVar8 + 0x7c);
    *(undefined4 *)(param_3 + 0x1b4) = *(undefined4 *)(iVar8 + 0x80);
    *(undefined4 *)(param_3 + 0x1b8) = *(undefined4 *)(iVar8 + 0x84);
    *(undefined4 *)(param_3 + 0x1bc) = *(undefined4 *)(iVar8 + 0x88);
    *(undefined4 *)(param_3 + 0x1c0) = *(undefined4 *)(iVar8 + 0x8c);
    *(undefined4 *)(param_3 + 0x1c4) = *(undefined4 *)(iVar8 + 0x90);
    *(undefined4 *)(param_3 + 0x1c8) = *(undefined4 *)(iVar8 + 0x94);
    *(undefined4 *)(param_3 + 0x1cc) = *(undefined4 *)(iVar8 + 0x98);
    if (((*puVar13 & 0x200000) != 0) || ((*puVar13 & 0x100000) != 0)) {
      FUN_40969e90((undefined4 *)(iVar16 + 0x5eb0),(undefined4 *)(iVar16 + 0x5e70),puVar9);
      *(undefined4 *)(param_3 + 0x1d0) = *(undefined4 *)(iVar16 + 0x5eb0);
      *(undefined4 *)(param_3 + 0x1d4) = *(undefined4 *)(iVar16 + 0x5eb4);
      *(undefined4 *)(param_3 + 0x1d8) = *(undefined4 *)(iVar16 + 0x5eb8);
      *(undefined4 *)(param_3 + 0x1dc) = *(undefined4 *)(iVar16 + 0x5ebc);
      *(undefined4 *)(param_3 + 0x1e0) = *(undefined4 *)(iVar16 + 0x5ec0);
      *(undefined4 *)(param_3 + 0x1e4) = *(undefined4 *)(iVar16 + 0x5ec4);
      *(undefined4 *)(param_3 + 0x1e8) = *(undefined4 *)(iVar16 + 0x5ec8);
      *(undefined4 *)(param_3 + 0x1ec) = *(undefined4 *)(iVar16 + 0x5ecc);
      *(undefined4 *)(param_3 + 0x1f0) = *(undefined4 *)(iVar16 + 0x5ed0);
      *(undefined4 *)(param_3 + 500) = *(undefined4 *)(iVar16 + 0x5ed4);
      *(undefined4 *)(param_3 + 0x1f8) = *(undefined4 *)(iVar16 + 0x5ed8);
      *(undefined4 *)(param_3 + 0x1fc) = *(undefined4 *)(iVar16 + 0x5edc);
      *(undefined4 *)(param_3 + 0x200) = *(undefined4 *)(iVar16 + 0x5ee0);
      *(undefined4 *)(param_3 + 0x204) = *(undefined4 *)(iVar16 + 0x5ee4);
      *(undefined4 *)(param_3 + 0x208) = *(undefined4 *)(iVar16 + 0x5ee8);
      *(undefined4 *)(param_3 + 0x20c) = *(undefined4 *)(iVar16 + 0x5eec);
      uVar17 = *puVar13;
      *puVar13 = uVar17 & 0xffdfffff;
      *puVar13 = uVar17 & 0xffcfffff;
    }
    if (*(char *)(iVar16 + 0x5f10) != '\0') {
      FUN_40969ca0(&local_68,puVar9);
      uVar4 = 0x3f800000;
      local_5c = 0;
      local_4c = 0;
      local_3c = 0;
      local_38 = 0;
      local_34 = 0;
      local_30 = 0;
      local_2c = 0x3f800000;
      FUN_4096a92c(&local_68);
      if (*(char *)(iVar16 + 0x55d9) != '\0') {
        uVar5 = __fpmul(local_40,local_40);
        uVar6 = __fpmul(local_50,local_50);
        uVar5 = __fpadd(uVar5,uVar6);
        uVar6 = __fpmul(local_60,local_60);
        uVar5 = __fpadd(uVar5,uVar6);
        uVar5 = mali_sys_sqrt(uVar5);
        iVar7 = __nes(uVar5,0);
        if (iVar7 != 0) {
          uVar4 = __fpdiv(0x3f800000,uVar5);
        }
        puVar9 = &local_68;
        iVar7 = 3;
        do {
          iVar8 = 3;
          puVar14 = puVar9;
          do {
            uVar5 = __fpmul(*puVar14,uVar4);
            iVar8 = iVar8 + -1;
            *puVar14 = uVar5;
            puVar14 = puVar14 + 1;
          } while (iVar8 != 0);
          iVar7 = iVar7 + -1;
          puVar9 = puVar9 + 4;
        } while (iVar7 != 0);
      }
      *(undefined4 *)(param_3 + 0x310) = local_68;
      *(undefined4 *)(param_3 + 0x314) = local_64;
      *(undefined4 *)(param_3 + 0x318) = local_60;
      *(undefined4 *)(param_3 + 800) = local_58;
      *(undefined4 *)(param_3 + 0x324) = local_54;
      *(undefined4 *)(param_3 + 0x328) = local_50;
      *(undefined4 *)(param_3 + 0x330) = local_48;
      *(undefined4 *)(param_3 + 0x334) = local_44;
      *(undefined4 *)(param_3 + 0x338) = local_40;
    }
  }
  else {
    uVar4 = *(undefined4 *)(param_1 + 0x108);
    puVar14 = (undefined4 *)(param_3 + 0x7c0);
    iVar7 = 0x80;
    puVar9 = (undefined4 *)(iVar16 + 0x55f4);
    do {
      iVar7 = iVar7 + -1;
      *puVar14 = puVar9[-2];
      puVar14[1] = puVar9[-1];
      puVar14[2] = *puVar9;
      puVar14[3] = puVar9[1];
      prefetch(puVar9 + 6,0);
      puVar14 = puVar14 + 4;
      puVar9 = puVar9 + 4;
    } while (iVar7 != 0);
    *(undefined4 *)(param_3 + 0xfc0) = *(undefined4 *)(iVar16 + 0x5e70);
    *(undefined4 *)(param_3 + 0xfc4) = *(undefined4 *)(iVar16 + 0x5e74);
    *(undefined4 *)(param_3 + 0xfc8) = *(undefined4 *)(iVar16 + 0x5e78);
    *(undefined4 *)(param_3 + 0xfcc) = *(undefined4 *)(iVar16 + 0x5e7c);
    *(undefined4 *)(param_3 + 0xfd0) = *(undefined4 *)(iVar16 + 0x5e80);
    *(undefined4 *)(param_3 + 0xfd4) = *(undefined4 *)(iVar16 + 0x5e84);
    *(undefined4 *)(param_3 + 0xfd8) = *(undefined4 *)(iVar16 + 0x5e88);
    *(undefined4 *)(param_3 + 0xfdc) = *(undefined4 *)(iVar16 + 0x5e8c);
    *(undefined4 *)(param_3 + 0xfe0) = *(undefined4 *)(iVar16 + 0x5e90);
    *(undefined4 *)(param_3 + 0xfe4) = *(undefined4 *)(iVar16 + 0x5e94);
    *(undefined4 *)(param_3 + 0xfe8) = *(undefined4 *)(iVar16 + 0x5e98);
    *(undefined4 *)(param_3 + 0xfec) = *(undefined4 *)(iVar16 + 0x5e9c);
    *(undefined4 *)(param_3 + 0xff0) = *(undefined4 *)(iVar16 + 0x5ea0);
    *(undefined4 *)(param_3 + 0xff4) = *(undefined4 *)(iVar16 + 0x5ea4);
    *(undefined4 *)(param_3 + 0xff8) = *(undefined4 *)(iVar16 + 0x5ea8);
    *(undefined4 *)(param_3 + 0xffc) = *(undefined4 *)(iVar16 + 0x5eac);
    uVar4 = __litofp(uVar4);
    *(undefined4 *)(param_3 + 0x27c) = uVar4;
  }
  if ((*(uint *)(*(int *)(param_1 + 0x508) + 0x1c) & 0x2000) == 0) goto LAB_4096493c;
  iVar7 = *(int *)(iVar16 + 0x5f0c);
  if (iVar7 == 0x800) {
    uVar4 = 0x3fb8aa3b;
LAB_40964930:
    uVar4 = __fpmul(*(undefined4 *)(iVar16 + 0x5f00),uVar4);
  }
  else {
    if (iVar7 == 0x801) {
      uVar4 = 0x3f99be61;
      goto LAB_40964930;
    }
    if (iVar7 != 0x2601) goto LAB_4096493c;
    uVar4 = __fpsub(*(undefined4 *)(iVar16 + 0x5f08),*(undefined4 *)(iVar16 + 0x5f04));
    iVar7 = __nes(uVar4,0);
    if (iVar7 == 0) {
      uVar4 = 0xbf800000;
    }
    else {
      uVar4 = __fpdiv(0xbf800000,uVar4);
    }
  }
  *(undefined4 *)(param_3 + 0x25c) = uVar4;
LAB_4096493c:
  if ((param_2 & 0x4000) != 0) {
    puVar13 = (uint *)(iVar16 + 0x55dc);
    uVar4 = FUN_40963fac(puVar13);
    puVar9 = local_88;
    do {
      uVar5 = __fpmul(*puVar13,uVar4);
      iVar18 = iVar18 + -1;
      *puVar9 = uVar5;
      puVar9 = puVar9 + 1;
      puVar13 = puVar13 + 1;
    } while (iVar18 != 0);
    *(undefined4 *)(param_3 + 0x230) = local_88[0];
    *(undefined4 *)(param_3 + 0x234) = local_88[1];
    *(undefined4 *)(param_3 + 0x238) = local_88[2];
    *(undefined4 *)(param_3 + 0x23c) = local_88[3];
  }
  iVar7 = 0;
  uVar17 = 0;
  if (*(int *)(param_4 + 0x10) != 0) {
    puVar9 = (undefined4 *)(param_3 + 0x5c0);
    iVar8 = 0;
    do {
      iVar18 = *(int *)(iVar8 + *(int *)(param_4 + 0xc) + 0xc);
      if ((param_2 >> ((iVar18 + 8) * 2 & 0x1fU) & 3) == 2) {
        iVar18 = (*(int *)((iVar18 + 0x156d) * 4 + iVar16) + iVar18 * 0x20) * 0x40 + iVar16;
        iVar7 = iVar7 + 1;
        *puVar9 = *(undefined4 *)(iVar18 + 0x105c);
        puVar9[1] = *(undefined4 *)(iVar18 + 0x1060);
        puVar9[2] = *(undefined4 *)(iVar18 + 0x1064);
        puVar9[3] = *(undefined4 *)(iVar18 + 0x1068);
        puVar9[4] = *(undefined4 *)(iVar18 + 0x106c);
        puVar9[5] = *(undefined4 *)(iVar18 + 0x1070);
        puVar9[6] = *(undefined4 *)(iVar18 + 0x1074);
        puVar9[7] = *(undefined4 *)(iVar18 + 0x1078);
        puVar9[8] = *(undefined4 *)(iVar18 + 0x107c);
        puVar9[9] = *(undefined4 *)(iVar18 + 0x1080);
        puVar9[10] = *(undefined4 *)(iVar18 + 0x1084);
        puVar9[0xb] = *(undefined4 *)(iVar18 + 0x1088);
        puVar9[0xc] = *(undefined4 *)(iVar18 + 0x108c);
        puVar9[0xd] = *(undefined4 *)(iVar18 + 0x1090);
        puVar9[0xe] = *(undefined4 *)(iVar18 + 0x1094);
        puVar9[0xf] = *(undefined4 *)(iVar18 + 0x1098);
        puVar9 = puVar9 + 0x10;
      }
      uVar17 = uVar17 + 1;
      iVar8 = iVar8 + 0x10;
    } while (uVar17 < *(uint *)(param_4 + 0x10));
  }
  uVar4 = __ultofp(iVar7);
  *(undefined4 *)(param_3 + 0x28c) = uVar4;
  return;
}



/* 40964ae4 FUN_40964ae4 */

/* Boundary evidence: original MIPS .pdata 40964ae4..40964c1f. Semantic name remains unreviewed. */

undefined4 FUN_40964ae4(int param_1,int param_2,int param_3)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  
  if (((param_3 == 0) || (*(char *)(*(int *)(param_1 + 0x4cc) + 0x6580) == '\0')) ||
     (*(char *)(param_2 * 0x5c + *(int *)(param_1 + 0x4cc) + 0x62a0) == '\0')) {
    iVar3 = param_2 * 0x30 + param_1;
    cVar1 = *(char *)(iVar3 + 0x128);
    if (((cVar1 != '\x01') || (*(int *)(iVar3 + 300) != 4)) &&
       ((cVar1 != '\0' ||
        (iVar3 = __nes(0x3f800000,*(undefined4 *)(*(int *)(param_1 + 0x4cc) + param_2 * 0x10 + 0x1c)
                      ), iVar3 == 0)))) {
      iVar4 = (*(int *)((param_2 + 0x156d) * 4 + *(int *)(param_1 + 0x4cc)) + param_2 * 0x20) * 0x40
              + *(int *)(param_1 + 0x4cc);
      iVar3 = __nes(*(undefined4 *)(iVar4 + 0x108c),0);
      if (((iVar3 == 0) && (iVar3 = __nes(*(undefined4 *)(iVar4 + 0x1090),0), iVar3 == 0)) &&
         ((iVar3 = __nes(*(undefined4 *)(iVar4 + 0x1094),0), iVar3 == 0 &&
          (iVar3 = __nes(*(undefined4 *)(iVar4 + 0x1098),0x3f800000), iVar3 == 0))))
      goto LAB_40964b2c;
    }
    uVar2 = 1;
  }
  else {
LAB_40964b2c:
    uVar2 = 0;
  }
  return uVar2;
}



/* 40964c20 FUN_40964c20 */

/* Boundary evidence: original MIPS .pdata 40964c20..40964d7b. Semantic name remains unreviewed. */

undefined4 FUN_40964c20(uint *param_1)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar4 = *param_1;
  uVar2 = 0;
  iVar1 = __gts(uVar4,0);
  if (iVar1 == 0) {
    iVar1 = __gts(uVar4 ^ 0x80000000,0);
    uVar3 = 0;
    if (iVar1 != 0) {
      uVar2 = 0xbf800000;
      uVar3 = uVar4 ^ 0x80000000;
    }
  }
  else {
    uVar2 = 0x3f800000;
    uVar3 = uVar4;
  }
  uVar4 = param_1[1];
  iVar1 = __gts(uVar4,uVar3);
  if (iVar1 == 0) {
    iVar1 = __gts(uVar4 ^ 0x80000000,uVar3);
    if (iVar1 != 0) {
      uVar2 = 0xbf800000;
      uVar3 = uVar4 ^ 0x80000000;
    }
  }
  else {
    uVar2 = 0x3f800000;
    uVar3 = uVar4;
  }
  uVar4 = param_1[2];
  iVar1 = __gts(uVar4,uVar3);
  if (iVar1 == 0) {
    iVar1 = __gts(uVar4 ^ 0x80000000,uVar3);
    if (iVar1 != 0) {
      uVar2 = 0xbf800000;
      uVar3 = uVar4 ^ 0x80000000;
    }
  }
  else {
    uVar2 = 0x3f800000;
    uVar3 = uVar4;
  }
  uVar4 = param_1[3];
  iVar1 = __gts(uVar4,uVar3);
  if (iVar1 == 0) {
    iVar1 = __gts(uVar4 ^ 0x80000000,uVar3);
    if (iVar1 != 0) {
      uVar2 = 0xbf800000;
    }
  }
  else {
    uVar2 = 0x3f800000;
  }
  return uVar2;
}



/* 40964dcc FUN_40964dcc */

void FUN_40964dcc(int param_1,uint param_2,int *param_3,int param_4)

{
  int iVar1;
  
  while( true ) {
    while ((int)param_2 < 0x15) {
      if (param_2 != 0x14) {
        if (0 < (int)param_2) {
          if ((int)param_2 < 9) {
            iVar1 = (param_2 + 6) * 4;
            if (*param_3 < iVar1) {
              *param_3 = iVar1;
            }
          }
          else if ((param_2 == 9) && (*param_3 < 0xc)) {
            *param_3 = 0xc;
            return;
          }
        }
        return;
      }
      param_2 = *(ushort *)(param_1 + 2) & 0x1f;
    }
    if (param_2 != 0x1d) {
      return;
    }
    if (param_4 != 0) break;
    param_2 = 0x14;
  }
  return;
}



/* 40964e70 FUN_40964e70 */

/* Boundary evidence: original MIPS .pdata 40964e70..4096511f. Semantic name remains unreviewed. */

void FUN_40964e70(int param_1,int *param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  uint *puVar5;
  char *pcVar6;
  int iVar7;
  uint uVar8;
  uint *puVar9;
  int iVar10;
  
  iVar1 = *(int *)(param_1 + 0x508);
  puVar9 = (uint *)(iVar1 + 0x20);
  iVar10 = 0;
  *(undefined2 *)puVar9 = 0;
  uVar8 = 0;
  iVar7 = 0;
  pcVar6 = (char *)(param_1 + 0x32c);
  puVar5 = (uint *)(iVar1 + 0x28);
  do {
    if ((*param_2 != 0) && (*pcVar6 != '\0')) {
      iVar1 = *(int *)(param_1 + 0x4d8) + iVar7;
      if (*(int *)(iVar1 + 0x62a4) == 0x8570) {
switchD_40964f60_caseD_1908:
        iVar3 = 1;
LAB_40964fd4:
        iVar4 = 1;
      }
      else {
        uVar2 = *(uint *)(**(int **)(*(int *)(pcVar6 + 4) + 0x1c) + 0xc);
        if (uVar2 < 0x8b91) {
          if (uVar2 != 0x8b90) {
            switch(uVar2) {
            case 0x1906:
              iVar3 = 0;
              goto LAB_40964fd4;
            case 0x1907:
            case 0x1909:
              break;
            default:
              goto switchD_40964f60_caseD_1908;
            }
          }
        }
        else {
          if (0x8d64 < uVar2) goto switchD_40964f60_caseD_1908;
          if (uVar2 != 0x8d64) {
            switch(uVar2) {
            default:
              goto switchD_40964f60_caseD_1908;
            case 0x8b92:
            case 0x8b95:
            case 0x8b97:
              break;
            }
          }
        }
        iVar3 = 1;
        iVar4 = 0;
      }
      *puVar9 = (~(1 << (uVar8 & 0x1f)) & *puVar9 ^ iVar3 << (uVar8 & 0x1f)) &
                ~(1 << (uVar8 + 1 & 0x1f)) ^ iVar4 << (uVar8 + 1 & 0x1f);
      iVar3 = FUN_40964ae4(param_1 + 0xc,iVar10,(uint)(param_3 == 0));
      if (iVar3 == 0) {
        puVar5[-1] = puVar5[-1] & 0x1fffffff ^ 0x20000000;
      }
      else {
        puVar5[-1] = puVar5[-1] & 0x1fffffff ^ 0x80000000;
      }
      if ((((param_3 == 0) == 0) || (*(char *)(*(int *)(param_1 + 0x4d8) + 0x6580) == '\0')) ||
         (*(char *)(iVar1 + 0x62a0) == '\0')) {
        iVar1 = 0;
      }
      else {
        iVar1 = 1;
      }
      *puVar5 = *puVar5 & 0xdfffffff ^ iVar1 << 0x1d;
    }
    param_2 = param_2 + 1;
    iVar7 = iVar7 + 0x5c;
    iVar10 = iVar10 + 1;
    pcVar6 = pcVar6 + 0x14;
    uVar8 = uVar8 + 2;
    puVar5 = puVar5 + 2;
    if (0x2df < iVar7) {
      return;
    }
  } while( true );
}



/* 4096515c FUN_4096515c */

/* Boundary evidence: original MIPS .pdata 4096515c..40965363. Semantic name remains unreviewed. */

int FUN_4096515c(uint *param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  int local_30 [2];
  
  uVar3 = *param_1;
  uVar2 = 0;
  uVar1 = uVar3 >> 0x1b & 3;
  local_30[0] = 0;
  if ((uVar1 != 0) && (uVar1 < 4)) {
    uVar2 = 0x10;
    local_30[0] = 0x10;
  }
  if (((uVar3 & 0x40000000) != 0) && (uVar2 < 0x18)) {
    local_30[0] = 0x18;
  }
  FUN_40964dcc((int)param_1,uVar3 >> 0x15 & 0x1f,local_30,8);
  iVar4 = 0;
  do {
    uVar1 = iVar4 * 2;
    uVar2 = (1 << (uVar1 & 0x1f) & *param_1) >> (uVar1 & 0x1f);
    uVar1 = (1 << (uVar1 + 1 & 0x1f) & *param_1) >> (uVar1 + 1 & 0x1f);
    if (uVar2 != 0) {
      uVar3 = 0;
      do {
        FUN_40964dcc((int)param_1,
                     (0x1f << (uVar3 & 0x1f) & param_1[iVar4 * 2 + 1]) >> (uVar3 & 0x1f),local_30,
                     iVar4);
        uVar3 = uVar3 + 8;
      } while ((int)uVar3 < 0x18);
    }
    if (uVar1 != 0) {
      uVar3 = 0;
      do {
        FUN_40964dcc((int)param_1,
                     (0x1f << (uVar3 & 0x1f) & param_1[(iVar4 + 1) * 2]) >> (uVar3 & 0x1f),local_30,
                     iVar4);
        uVar3 = uVar3 + 8;
      } while ((int)uVar3 < 0x18);
    }
    if ((uVar2 == 0) && (uVar1 == 0)) {
LAB_40965304:
      if (iVar4 == 0) {
        FUN_40964dcc((int)param_1,0x14,local_30,0);
      }
    }
    else {
      if (((param_1[(iVar4 + 1) * 2] & 0x20000000) != 0) && (local_30[0] < 0x14)) {
        local_30[0] = 0x14;
      }
      if ((uVar2 == 0) || (uVar1 == 0)) goto LAB_40965304;
    }
    iVar4 = iVar4 + 1;
    if (7 < iVar4) {
      return local_30[0];
    }
  } while( true );
}



/* 40965364 FUN_40965364 */

uint FUN_40965364(uint param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar1 = (int)param_1 >> 0x17 & 0xff;
  if ((uVar1 == 0xff) && ((param_1 & 0x7fffff) != 0)) {
    return 0xffff;
  }
  uVar4 = (param_1 & 0x7fffff | 0x800000) >> 0xd;
  uVar2 = uVar1 - 0x70;
  uVar3 = (uint)((param_1 & 0x80000000) != 0) << 0xf;
  if (0x7ff < uVar4) {
    uVar4 = 0;
    uVar2 = uVar1 - 0x6f;
  }
  if (0x1f < (int)uVar2) {
    return uVar3 | 0x7c00;
  }
  if ((int)uVar2 < 0) {
    return uVar3;
  }
  return uVar4 & 0xfbff | (uVar2 & 0x3f) << 10 | uVar3;
}



/* 40965418 FUN_40965418 */

/* Boundary evidence: original MIPS .pdata 40965418..40965473. Semantic name remains unreviewed. */

void FUN_40965418(undefined2 *param_1,uint *param_2)

{
  uint uVar1;
  
  uVar1 = FUN_40965364(*param_2);
  *param_1 = (short)uVar1;
  uVar1 = FUN_40965364(param_2[1]);
  param_1[1] = (short)uVar1;
  uVar1 = FUN_40965364(param_2[2]);
  param_1[2] = (short)uVar1;
  uVar1 = FUN_40965364(param_2[3]);
  param_1[3] = (short)uVar1;
  return;
}



/* 40965474 FUN_40965474 */

/* Boundary evidence: original MIPS .pdata 40965474..409654c3. Semantic name remains unreviewed. */

void FUN_40965474(undefined2 *param_1,uint *param_2)

{
  uint uVar1;
  
  uVar1 = FUN_40965364(*param_2);
  *param_1 = (short)uVar1;
  uVar1 = FUN_40965364(param_2[1]);
  param_1[1] = (short)uVar1;
  uVar1 = FUN_40965364(param_2[2]);
  param_1[2] = (short)uVar1;
  return;
}



/* 409654c4 FUN_409654c4 */

/* Boundary evidence: original MIPS .pdata 409654c4..409656e3. Semantic name remains unreviewed. */

void FUN_409654c4(int param_1,uint *param_2,int param_3,int param_4)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  undefined2 *puVar4;
  undefined4 uVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  
  if ((0x17 < *(uint *)(param_4 + 0xb0)) && (uVar7 = 0, *(int *)(param_4 + 0x10) != 0)) {
    iVar8 = 0;
    do {
      iVar3 = *(int *)(*(int *)(param_4 + 0xc) + iVar8 + 0xc);
      iVar6 = iVar3 * 0x5c + *(int *)(param_1 + 0x4d8);
      puVar4 = (undefined2 *)((iVar3 + 6) * 8 + param_3);
      uVar1 = FUN_40965364(*(uint *)(iVar6 + 0x62e8));
      *puVar4 = (short)uVar1;
      uVar1 = FUN_40965364(*(uint *)(iVar6 + 0x62ec));
      puVar4[1] = (short)uVar1;
      uVar1 = FUN_40965364(*(uint *)(iVar6 + 0x62f0));
      puVar4[2] = (short)uVar1;
      uVar1 = FUN_40965364(*(uint *)(iVar6 + 0x62f4));
      uVar7 = uVar7 + 1;
      puVar4[3] = (short)uVar1;
      iVar8 = iVar8 + 0x10;
    } while (uVar7 < *(uint *)(param_4 + 0x10));
  }
  uVar7 = 0;
  puVar4 = (undefined2 *)(param_3 + 0x10);
  do {
    uVar1 = *(uint *)(*(int *)(param_1 + 0x4d8) + uVar7);
    iVar8 = __lts(uVar1,0);
    if (iVar8 == 0) {
      iVar8 = __gts(uVar1,0x3f800000);
      if (iVar8 != 0) {
        uVar1 = 0x3f800000;
      }
    }
    else {
      uVar1 = 0;
    }
    uVar1 = FUN_40965364(uVar1);
    uVar7 = uVar7 + 4;
    *puVar4 = (short)uVar1;
    puVar4 = puVar4 + 1;
  } while (uVar7 < 0x10);
  if ((*param_2 & 0x40000000) != 0) {
    uVar7 = FUN_40964c20((uint *)(*(int *)(param_1 + 0x4d8) + 0x55dc));
    uVar7 = FUN_40965364(uVar7);
    *(short *)(param_3 + 0x28) = (short)uVar7;
  }
  if ((*(uint *)(*(int *)(param_1 + 0x508) + 0x1c) & 0x2000) != 0) {
    uVar2 = __fpsub(*(undefined4 *)(*(int *)(param_1 + 0x4d8) + 0x5f08),
                    *(undefined4 *)(*(int *)(param_1 + 0x4d8) + 0x5f04));
    iVar8 = __nes(uVar2,0);
    if (iVar8 == 0) {
      uVar7 = 0;
    }
    else {
      uVar5 = *(undefined4 *)(*(int *)(param_1 + 0x4d8) + 0x5f08);
      uVar2 = __fpsub(uVar5,*(undefined4 *)(*(int *)(param_1 + 0x4d8) + 0x5f04));
      uVar7 = __fpdiv(uVar5,uVar2);
    }
    iVar8 = *(int *)(param_1 + 0x4d8);
    uVar1 = FUN_40965364(*(uint *)(iVar8 + 0x5ef0));
    *(short *)(param_3 + 0x18) = (short)uVar1;
    uVar1 = FUN_40965364(*(uint *)(iVar8 + 0x5ef4));
    *(short *)(param_3 + 0x1a) = (short)uVar1;
    uVar1 = FUN_40965364(*(uint *)(iVar8 + 0x5ef8));
    *(short *)(param_3 + 0x1c) = (short)uVar1;
    uVar7 = FUN_40965364(uVar7);
    *(short *)(param_3 + 0x1e) = (short)uVar7;
  }
  return;
}



/* 409656e4 FUN_409656e4 */

/* Boundary evidence: original MIPS .pdata 409656e4..40965823. Semantic name remains unreviewed. */

undefined4 * FUN_409656e4(undefined4 param_1)

{
  undefined4 *puVar1;
  int iVar2;
  int *piVar3;
  uint uVar4;
  uint local_18 [2];
  
  puVar1 = (undefined4 *)mali_sys_malloc(0x11b4);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = param_1;
    puVar1[6] = 0;
    iVar2 = mali_sys_malloc(0x6c);
    puVar1[1] = iVar2;
    if (iVar2 != 0) {
      iVar2 = mali_sys_malloc(0xac);
      puVar1[2] = iVar2;
      if (iVar2 != 0) {
        mali_sys_memset(puVar1[1],0,0x6c);
        mali_sys_memset(puVar1[2],0,0xac);
        mali_sys_memset(puVar1 + 8,0,0x44);
        mali_sys_memset(puVar1 + 0x451,0,0x70);
        puVar1[3] = 0;
        puVar1[4] = 0;
        puVar1[5] = 0;
        mali_sys_memset(puVar1 + 0x19,0,0x1000);
        mali_sys_memset(puVar1 + 0x419,0,0xe0);
        piVar3 = (int *)gles_piecegen_get_uniform_initializers(local_18);
        uVar4 = 0;
        if (local_18[0] == 0) {
          return puVar1;
        }
        do {
          puVar1[*piVar3 + 0x19] = piVar3[1];
          piVar3 = piVar3 + 2;
          uVar4 = uVar4 + 1;
        } while (uVar4 < local_18[0]);
        return puVar1;
      }
      mali_sys_free();
    }
    mali_sys_free(puVar1);
  }
  return (undefined4 *)0x0;
}



/* 40965858 FUN_40965858 */

/* Boundary evidence: original MIPS .pdata 40965858..409658d3. Semantic name remains unreviewed. */

void FUN_40965858(int param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int local_48 [16];
  
  piVar1 = local_48;
  iVar4 = 0;
  do {
    *piVar1 = -1;
    piVar1 = piVar1 + 1;
  } while (piVar1 != (int *)&stack0xfffffff8);
  iVar3 = 0x10;
  piVar1 = (int *)(param_1 + 0xb8);
  do {
    iVar2 = *piVar1;
    if (-1 < iVar2) {
      *piVar1 = iVar4;
      local_48[iVar2] = iVar4;
      iVar4 = iVar4 + 1;
    }
    iVar3 = iVar3 + -1;
    prefetch(piVar1 + 2,0);
    piVar1 = piVar1 + 1;
  } while (iVar3 != 0);
  mali_gp2_link_attribs(param_1,local_48,1);
  return;
}



/* 409658d4 FUN_409658d4 */

/* Boundary evidence: original MIPS .pdata 409658d4..40965907. Semantic name remains unreviewed. */

void FUN_409658d4(int param_1)

{
  __mali_shader_binary_state_reset(param_1);
  mali_sys_free(*(undefined4 *)(param_1 + 0xc));
  *(undefined4 *)(param_1 + 0xc) = 0;
  return;
}



/* 409659c4 FUN_409659c4 */

void FUN_409659c4(int param_1,int param_2,int param_3)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  
  iVar3 = param_3 * 8 + param_2;
  uVar2 = *(uint *)(iVar3 + 4);
  uVar1 = uVar2 >> 0x18 & 7;
  if (uVar1 != 0) {
    if (uVar1 == 0) goto LAB_40965aac;
    if (3 < uVar1) {
      if (uVar1 == 4) {
        uVar1 = uVar2 >> 0x10 & 0x1f;
        if ((0xb < uVar1) && (uVar1 < 0x14)) {
          *(undefined4 *)((uVar1 - 0xc) * 4 + param_1) = 1;
        }
      }
      else if ((uVar1 < 5) || (7 < uVar1)) goto LAB_40965aac;
    }
    uVar1 = uVar2 >> 8 & 0x1f;
    if ((0xb < uVar1) && (uVar1 < 0x14)) {
      *(undefined4 *)((uVar1 - 0xc) * 4 + param_1) = 1;
    }
  }
  uVar2 = uVar2 & 0x1f;
  if ((0xb < uVar2) && (uVar2 < 0x14)) {
    *(undefined4 *)((uVar2 - 0xc) * 4 + param_1) = 1;
  }
LAB_40965aac:
  uVar2 = *(uint *)(iVar3 + 8);
  uVar1 = uVar2 >> 0x18 & 7;
  if (uVar1 != 0) {
    if (uVar1 == 0) {
      return;
    }
    if (3 < uVar1) {
      if (uVar1 == 4) {
        uVar1 = uVar2 >> 0x10 & 0x1f;
        if ((0xb < uVar1) && (uVar1 < 0x14)) {
          *(undefined4 *)((uVar1 - 0xc) * 4 + param_1) = 1;
        }
      }
      else {
        if (uVar1 < 5) {
          return;
        }
        if (7 < uVar1) {
          return;
        }
      }
    }
    uVar1 = uVar2 >> 8 & 0x1f;
    if ((0xb < uVar1) && (uVar1 < 0x14)) {
      *(undefined4 *)((uVar1 - 0xc) * 4 + param_1) = 1;
    }
  }
  uVar2 = uVar2 & 0x1f;
  if ((0xb < uVar2) && (uVar2 < 0x14)) {
    *(undefined4 *)((uVar2 - 0xc) * 4 + param_1) = 1;
  }
  return;
}



/* 40965b90 FUN_40965b90 */

/* Boundary evidence: original MIPS .pdata 40965b90..40965ccf. Semantic name remains unreviewed. */

void FUN_40965b90(int param_1,int param_2,int *param_3,int param_4,undefined4 param_5,
                 undefined4 param_6,undefined4 param_7)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  int *piVar5;
  
  FUN_40993230();
  piVar5 = *(int **)(param_2 + 8);
  FUN_40964e70(param_1,param_3,param_4);
  piVar4 = (int *)(param_2 + 0x10);
  if (*piVar4 != 0) {
    piVar3 = piVar4;
    do {
      iVar1 = gles_fragment_shadergen_states_equivalent(*piVar3 + 4,param_2 + 0x20);
      if (iVar1 != 0) {
        piVar5 = (int *)*piVar3;
        *piVar3 = *piVar5;
        *piVar5 = *piVar4;
        *piVar4 = (int)piVar5;
        goto LAB_40965cc4;
      }
      piVar3 = (int *)*piVar3;
    } while (*piVar3 != 0);
  }
  memcpy(piVar5 + 1,(void *)(param_2 + 0x20),0x44);
  iVar1 = mali_sys_malloc(0xac);
  if (iVar1 != 0) {
    iVar2 = gles_fragment_shadergen_generate_shader
                      ((void *)(param_2 + 0x20),&param_7,4,mali_sys_malloc);
    if (iVar2 == 0) {
      mali_sys_free(iVar1);
    }
    else {
      *(int *)(param_2 + 8) = iVar1;
      *piVar5 = *piVar4;
      *piVar4 = (int)piVar5;
      piVar5[0x13] = 0;
      __mali_shader_binary_state_init(piVar5 + 0x14);
      __mali_binary_shader_load(piVar5 + 0x14,0x8b30,iVar2,param_7);
      mali_sys_free(iVar2);
    }
  }
LAB_40965cc4:
                    /* WARNING: Subroutine does not return */
  FUN_40993258(0x20);
}



/* 40965cd0 FUN_40965cd0 */

/* Boundary evidence: original MIPS .pdata 40965cd0..40965ddf. Semantic name remains unreviewed. */

void FUN_40965cd0(undefined4 param_1,int param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  int *piVar5;
  int *piVar6;
  
  FUN_40993230();
  piVar5 = (int *)(param_2 + 0xc);
  piVar6 = *(int **)(param_2 + 4);
  if (*piVar5 != 0) {
    piVar4 = piVar5;
    do {
      piVar3 = (int *)*piVar4;
      if (piVar3[1] == *(int *)(param_2 + 0x1c)) {
        piVar6 = (int *)*piVar4;
        *piVar4 = *piVar6;
        *piVar6 = *piVar5;
        *piVar5 = (int)piVar6;
        goto LAB_40965dd4;
      }
      piVar4 = piVar3;
    } while (*piVar3 != 0);
  }
  piVar6[1] = *(int *)(param_2 + 0x1c);
  iVar1 = mali_sys_malloc(0x6c);
  if (iVar1 != 0) {
    iVar2 = gles_vertex_shadergen_generate_shader
                      (*(undefined4 *)(param_2 + 0x1c),&param_5,mali_sys_malloc,mali_sys_free);
    if (iVar2 == 0) {
      mali_sys_free(iVar1);
    }
    else {
      *(int *)(param_2 + 4) = iVar1;
      *piVar6 = *piVar5;
      *piVar5 = (int)piVar6;
      piVar6[3] = 0;
      __mali_shader_binary_state_init(piVar6 + 4);
      __mali_binary_shader_load(piVar6 + 4,0x8b31,iVar2,param_5);
      mali_sys_free(iVar2);
    }
  }
LAB_40965dd4:
                    /* WARNING: Subroutine does not return */
  FUN_40993258(0x18);
}



/* 40965de0 FUN_40965de0 */

/* Boundary evidence: original MIPS .pdata 40965de0..40965e33. Semantic name remains unreviewed. */

void FUN_40965de0(undefined4 param_1,int param_2)

{
  int iVar1;
  
  *(undefined4 *)(param_2 + 0x68) = 0;
  *(undefined4 *)(param_2 + 0x6c) = 0;
  *(undefined4 *)(param_2 + 0xac) = 0;
  *(undefined4 *)(param_2 + 0xb0) = 0;
  *(undefined4 *)(param_2 + 0x17c) = 0;
  __mali_program_binary_state_reset(param_2);
  iVar1 = mali_sys_atomic_dec_and_return(param_2 + 0x180);
  if (iVar1 == 0) {
    FUN_40973390(param_2);
  }
  return;
}



/* 40965e34 FUN_40965e34 */

/* Boundary evidence: original MIPS .pdata 40965e34..40965f27. Semantic name remains unreviewed. */

void FUN_40965e34(undefined4 *param_1,uint *param_2)

{
  undefined4 *puVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  
  puVar1 = param_1;
  do {
    *puVar1 = 0;
    puVar1 = puVar1 + 1;
  } while (puVar1 != param_1 + 8);
  uVar3 = *param_2;
  iVar4 = 0;
  uVar2 = 0;
  do {
    if (((1 << (uVar2 & 0x1f) & uVar3) >> (uVar2 & 0x1f) != 0) ||
       ((1 << (uVar2 + 1 & 0x1f) & uVar3) >> (uVar2 + 1 & 0x1f) != 0)) {
      FUN_409659c4((int)param_1,(int)param_2,iVar4);
    }
    uVar2 = uVar2 + 2;
    iVar4 = iVar4 + 1;
  } while ((int)uVar2 < 0x10);
  uVar2 = uVar3 >> 0x15 & 0x1f;
  if ((0xb < uVar2) && (uVar2 < 0x14)) {
    param_1[uVar2 - 0xc] = 1;
  }
  return;
}



/* 40965f28 FUN_40965f28 */

/* Boundary evidence: original MIPS .pdata 40965f28..4096607f. Semantic name remains unreviewed. */

void FUN_40965f28(int param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  
  FUN_40993230();
  piVar3 = (int *)(param_1 + 0x14);
  while (piVar2 = piVar3, *piVar2 != 0) {
    if (((param_2 == 0) || (piVar3 = (int *)*piVar2, *(int *)(piVar3[1] + 0xc) != 0)) ||
       (*(int *)(piVar3[2] + 0x4c) != 0)) {
      piVar3 = (int *)*piVar2;
      *piVar2 = *piVar3;
      FUN_40965de0(param_1,piVar3[3]);
      piVar3[3] = 0;
      mali_sys_free(piVar3);
      piVar3 = piVar2;
    }
  }
  iVar1 = *(int *)(param_1 + 0xc);
  piVar3 = (int *)(param_1 + 0xc);
  while (iVar1 != 0) {
    if ((param_2 == 0) || (piVar2 = (int *)*piVar3, piVar2[3] != 0)) {
      piVar2 = (int *)*piVar3;
      *piVar3 = *piVar2;
      __mali_shader_binary_state_reset(piVar2 + 4);
      mali_sys_free(piVar2[7]);
      piVar2[7] = 0;
      mali_sys_free(piVar2);
      piVar2 = piVar3;
    }
    piVar3 = piVar2;
    iVar1 = *piVar2;
  }
  iVar1 = *(int *)(param_1 + 0x10);
  piVar3 = (int *)(param_1 + 0x10);
  while (iVar1 != 0) {
    if ((param_2 == 0) || (piVar2 = (int *)*piVar3, piVar2[0x13] != 0)) {
      piVar2 = (int *)*piVar3;
      *piVar3 = *piVar2;
      __mali_shader_binary_state_reset(piVar2 + 0x14);
      mali_sys_free(piVar2[0x17]);
      piVar2[0x17] = 0;
      mali_sys_free(piVar2);
      piVar2 = piVar3;
    }
    piVar3 = piVar2;
    iVar1 = *piVar2;
  }
                    /* WARNING: Subroutine does not return */
  FUN_40993258(0x10);
}



/* 40966080 FUN_40966080 */

/* Boundary evidence: original MIPS .pdata 40966080..409660e3. Semantic name remains unreviewed. */

void FUN_40966080(int param_1)

{
  if (*(int *)(param_1 + 4) != 0) {
    mali_sys_free();
    *(undefined4 *)(param_1 + 4) = 0;
  }
  if (*(int *)(param_1 + 8) != 0) {
    mali_sys_free();
    *(undefined4 *)(param_1 + 8) = 0;
  }
  FUN_40965f28(param_1,0);
  mali_sys_free(param_1);
  return;
}



/* 409660e4 FUN_409660e4 */

/* Boundary evidence: original MIPS .pdata 409660e4..409661a7. Semantic name remains unreviewed. */

void FUN_409660e4(int param_1)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  uint uVar4;
  uint uVar5;
  
  piVar2 = *(int **)(param_1 + 0xc);
  uVar4 = 0;
  piVar1 = *(int **)(param_1 + 0x10);
  uVar5 = 0;
  piVar3 = piVar2;
  if (piVar2 != (int *)0x0) {
    do {
      uVar4 = uVar4 + 1;
      if ((uint)piVar2[2] < (uint)piVar3[2]) {
        piVar3 = piVar2;
      }
      piVar2 = (int *)*piVar2;
    } while (piVar2 != (int *)0x0);
    if (8 < uVar4) {
      piVar3[3] = 1;
    }
  }
  piVar2 = *(int **)(param_1 + 0x10);
  if (piVar2 != (int *)0x0) {
    do {
      uVar5 = uVar5 + 1;
      if ((uint)piVar2[0x12] < (uint)piVar1[0x12]) {
        piVar1 = piVar2;
      }
      piVar2 = (int *)*piVar2;
    } while (piVar2 != (int *)0x0);
    if (8 < uVar5) {
      piVar1[0x13] = 1;
    }
  }
  if ((piVar1[0x13] != 0) || (piVar3[3] != 0)) {
    FUN_40965f28(param_1,1);
  }
  return;
}



/* 409661a8 FUN_409661a8 */

/* Boundary evidence: original MIPS .pdata 409661a8..4096638b. Semantic name remains unreviewed. */

undefined4 FUN_409661a8(int param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  undefined4 uVar7;
  
  iVar6 = *(int *)(param_2 + 0xc);
  if (*(int *)(iVar6 + 0x68) != 0) {
    mali_sys_free();
  }
  *(int *)(iVar6 + 0x68) = param_1 + 100;
  uVar1 = FUN_40963b64(*(uint *)(*(int *)(param_2 + 4) + 4));
  *(undefined4 *)(iVar6 + 0x6c) = uVar1;
  *(undefined4 *)(iVar6 + 0x70) = 1;
  if (*(int *)(iVar6 + 0xac) != 0) {
    mali_sys_free();
  }
  *(int *)(iVar6 + 0xac) = param_1 + 0x1064;
  iVar2 = FUN_4096515c((uint *)(*(int *)(param_2 + 8) + 4));
  uVar5 = 0;
  *(int *)(iVar6 + 0xb0) = iVar2;
  *(undefined4 *)(iVar6 + 0xb4) = 1;
  *(int *)(iVar6 + 0x17c) = param_1 + 0x1144;
  if (*(int *)(iVar6 + 0x10) != 0) {
    iVar2 = 0;
    do {
      *(uint *)(iVar2 + *(int *)(iVar6 + 0xc) + 0xc) = uVar5;
      uVar5 = uVar5 + 1;
      iVar2 = iVar2 + 0x10;
    } while (uVar5 < *(uint *)(iVar6 + 0x10));
  }
  if ((*(uint *)(*(int *)(param_2 + 4) + 4) & 0x1000) == 0) {
    *(undefined4 *)(iVar6 + 0x4c) = 0xffffffff;
    if (*(int *)(iVar6 + 0x38) != 0) {
      bs_symbol_free();
    }
    *(undefined4 *)(iVar6 + 0x38) = 0;
  }
  if (0x13 < *(uint *)(iVar6 + 0xb0)) {
    *(undefined4 *)(iVar6 + 0x14c) = 0x10;
    *(undefined4 *)(iVar6 + 0x170) = 1;
  }
  *(undefined4 *)(iVar6 + 0x140) = 0x84;
  *(undefined4 *)(iVar6 + 0x144) = 0x90;
  FUN_40963e68(*(uint *)(*(int *)(param_2 + 4) + 4),(int *)(iVar6 + 0xb8));
  uVar1 = FUN_40965858(iVar6);
  *(undefined4 *)(iVar6 + 0x2c) = 0;
  iVar2 = 0;
  uVar5 = 0;
  piVar3 = (int *)(iVar6 + 0xb8);
  do {
    if (-1 < *piVar3) {
      *(int *)((*piVar3 + 0x3e) * 4 + iVar6) = iVar2;
      *(int *)(iVar6 + 0x2c) = *(int *)(iVar6 + 0x2c) + 1;
    }
    *(int *)(*(int *)(iVar6 + 0x30) + uVar5) = iVar2;
    prefetch(piVar3 + 2,0);
    iVar4 = *(int *)(iVar6 + 0x30) + uVar5;
    uVar5 = uVar5 + 8;
    iVar2 = iVar2 + 1;
    *(undefined4 *)(iVar4 + 4) = 0;
    piVar3 = piVar3 + 1;
  } while (uVar5 < 0x80);
  *(undefined4 *)(iVar6 + 0x54) = *(undefined4 *)(iVar6 + 0x2c);
  iVar2 = FUN_4096b7ac(iVar6);
  *(int *)(iVar6 + 0x174) = iVar2;
  uVar7 = 0xffffffff;
  if (iVar2 != 0) {
    piVar3 = FUN_40967e2c(iVar6);
    *(int **)(iVar6 + 0x178) = piVar3;
    if (piVar3 != (int *)0x0) {
      uVar7 = uVar1;
    }
  }
  return uVar7;
}



/* 4096638c FUN_4096638c */

/* Boundary evidence: original MIPS .pdata 4096638c..409664ff. Semantic name remains unreviewed. */

int FUN_4096638c(undefined4 *param_1)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  
  piVar4 = param_1 + 5;
  if (*piVar4 != 0) {
    piVar1 = piVar4;
    do {
      piVar2 = (int *)*piVar1;
      if ((piVar2[1] == param_1[3]) && (piVar2[2] == param_1[4])) {
        piVar2 = (int *)*piVar1;
        *piVar1 = *piVar2;
        *piVar2 = *piVar4;
        *piVar4 = (int)piVar2;
        return 0;
      }
      piVar1 = piVar2;
    } while (*piVar2 != 0);
  }
  piVar1 = (int *)mali_sys_malloc(0x10);
  if (piVar1 == (int *)0x0) {
    iVar3 = -1;
  }
  else {
    iVar3 = FUN_40973420();
    piVar1[3] = iVar3;
    if (iVar3 == 0) {
      iVar3 = -1;
    }
    else {
      __mali_program_binary_state_init(iVar3);
      iVar3 = __mali_link_binary_shaders(*param_1,piVar1[3],param_1[3] + 0x10,param_1[4] + 0x50);
      if (iVar3 == 0) {
        piVar1[1] = param_1[3];
        piVar1[2] = param_1[4];
        iVar3 = FUN_409661a8((int)param_1,(int)piVar1);
        if (iVar3 == 0) {
          *piVar1 = *piVar4;
          *piVar4 = (int)piVar1;
          return 0;
        }
        FUN_40965de0(param_1,piVar1[3]);
        piVar1[3] = 0;
      }
      else {
        __mali_program_binary_state_reset(piVar1[3]);
        mali_sys_free(piVar1[3]);
      }
    }
    mali_sys_free(piVar1);
  }
  return iVar3;
}



/* 40966500 FUN_40966500 */

/* Boundary evidence: original MIPS .pdata 40966500..40966617. Semantic name remains unreviewed. */

int FUN_40966500(int param_1,undefined4 *param_2,int *param_3,int param_4)

{
  int iVar1;
  uint uVar2;
  int *piVar3;
  int iVar4;
  undefined4 unaff_s1;
  undefined4 unaff_s2;
  undefined4 unaff_s3;
  
  iVar4 = param_2[6] + 1;
  param_2[6] = iVar4;
  piVar3 = param_3;
  iVar1 = param_4;
  if ((iVar4 == 0) || (iVar4 == -1)) {
    FUN_40965f28((int)param_2,0);
    param_2[6] = 0;
  }
  iVar1 = FUN_40965cd0(param_1,(int)param_2,piVar3,iVar1,unaff_s3);
  if (iVar1 == 0) {
    *(undefined4 *)(param_2[3] + 8) = param_2[6];
    iVar1 = FUN_40965b90(param_1,(int)param_2,param_3,param_4,unaff_s3,unaff_s2,unaff_s1);
    if (iVar1 == 0) {
      *(undefined4 *)(param_2[4] + 0x48) = param_2[6];
      FUN_409660e4((int)param_2);
      iVar1 = FUN_4096638c(param_2);
      if (iVar1 == 0) {
        iVar1 = *(int *)(param_2[5] + 0xc);
        uVar2 = param_2[7];
        *(int *)(param_1 + 0x4d4) = iVar1;
        FUN_40964154(param_1,uVar2,*(int *)(iVar1 + 0x68),iVar1);
        FUN_40963ddc(param_1 + 0xc);
        FUN_409654c4(param_1,param_2 + 8,*(int *)(iVar1 + 0x17c),iVar1);
        iVar1 = 0;
      }
    }
  }
  return iVar1;
}



/* 40966618 FUN_40966618 */

void FUN_40966618(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  uint uVar4;
  
  iVar2 = *(int *)(param_1 + 0x20);
  iVar1 = *(int *)(param_3 + 0x24);
  uVar4 = 0;
  if (*(int *)(param_3 + 0x20) != 0) {
    piVar3 = (int *)(param_2 + 0x80);
    do {
      uVar4 = uVar4 + 1;
      *piVar3 = *(int *)(param_1 + 0x84) + *piVar3 + iVar2 * iVar1;
      prefetch(piVar3 + 4,0);
      piVar3 = piVar3 + 2;
    } while (uVar4 < *(uint *)(param_3 + 0x20));
  }
  return;
}



/* 4096669c FUN_4096669c */

/* Boundary evidence: original MIPS .pdata 4096669c..409666cf. Semantic name remains unreviewed. */

undefined4 FUN_4096669c(undefined4 *param_1)

{
  undefined4 uVar1;
  
  if (param_1[1] == 0) {
    uVar1 = mali_mem_mali_addr_get_full(param_1,0);
  }
  else {
    uVar1 = *param_1;
  }
  return uVar1;
}



/* 409666d0 FUN_409666d0 */

/* Boundary evidence: original MIPS .pdata 409666d0..409667cb. Semantic name remains unreviewed. */

undefined4 FUN_409666d0(int param_1,int param_2,int param_3)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  if ((*(int *)(param_1 + 4) == 0) && (-1 < param_3)) {
    puVar1 = (undefined4 *)
             mali_mem_alloc(*(undefined4 *)(param_1 + 0x78),(*(int *)(param_1 + 0x14) + 3) * 4,0x10,
                            0x2c);
    if (puVar1 == (undefined4 *)0x0) {
      return 0xffffffff;
    }
    mali_frame_builder_add_gp_job_mem(*(undefined4 *)(param_1 + 0x7c),puVar1);
    *(undefined4 **)(param_1 + 0x8c) = puVar1;
    if (puVar1[1] == 0) {
      uVar2 = mali_mem_mali_addr_get_full(puVar1,0);
    }
    else {
      uVar2 = *puVar1;
    }
    *(undefined4 *)((param_3 + 0x10) * 8 + param_2) = uVar2;
    if (*(int *)(param_1 + 8) == 1) {
      *(undefined4 *)(param_3 * 8 + param_2 + 0x84) = 0x2000;
    }
    else {
      *(undefined4 *)(param_3 * 8 + param_2 + 0x84) = 0x2021;
    }
  }
  return 0;
}



/* 409667cc FUN_409667cc */

/* Boundary evidence: original MIPS .pdata 409667cc..4096685f. Semantic name remains unreviewed. */

void FUN_409667cc(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  FUN_40993370();
  iVar2 = *(int *)(param_1 + 0x80);
  mali_sys_memcpy(param_2 + 0x80,*(int *)(iVar2 + 0x178) + 200,0x80);
  iVar1 = *(int *)(iVar2 + 0x50);
  *(int *)((iVar1 + 0x10) * 8 + param_2) =
       *(int *)(param_1 + 0x20) * 0x10 + *(int *)(param_1 + 0x88);
  *(undefined4 *)(iVar1 * 8 + param_2 + 0x84) = 0x8020;
  iVar1 = FUN_409666d0(param_1,param_2,*(int *)(iVar2 + 0x4c));
  if (iVar1 == 0) {
    FUN_40966618(param_1,param_2,iVar2);
  }
                    /* WARNING: Subroutine does not return */
  FUN_40993390(0x10);
}



/* 40966860 FUN_40966860 */

/* Boundary evidence: original MIPS .pdata 40966860..4096688f. Semantic name remains unreviewed. */

void FUN_40966860(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  uVar1 = mali_frame_builder_get_gp_job(*(undefined4 *)(param_1 + 0x7c));
  mali_gp_job_add_plbu_cmd(uVar1);
  return;
}



/* 40966890 FUN_40966890 */

/* Boundary evidence: original MIPS .pdata 40966890..409668bf. Semantic name remains unreviewed. */

void FUN_40966890(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  uVar1 = mali_frame_builder_get_gp_job(*(undefined4 *)(param_1 + 0x7c));
  mali_gp_job_add_plbu_cmd(uVar1);
  return;
}



/* 409668c0 FUN_409668c0 */

void FUN_409668c0(int param_1,undefined4 *param_2,undefined4 *param_3)

{
  char cVar1;
  int iVar2;
  
  cVar1 = *(char *)(param_1 + 0x4c);
  *param_2 = 0;
  *param_3 = 0;
  if (cVar1 != '\x01') {
    return;
  }
  iVar2 = *(int *)(param_1 + 0x50);
  if (iVar2 == 0x404) {
    if (*(int *)(param_1 + 0x54) == 0x901) {
LAB_40966934:
      *param_3 = 1;
      return;
    }
  }
  else if (iVar2 == 0x405) {
    if (*(int *)(param_1 + 0x54) != 0x901) goto LAB_40966934;
  }
  else {
    if (iVar2 != 0x408) {
      return;
    }
    *param_3 = 1;
  }
  *param_2 = 1;
  return;
}



/* 4096693c FUN_4096693c */

/* Boundary evidence: original MIPS .pdata 4096693c..409669df. Semantic name remains unreviewed. */

void FUN_4096693c(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  int iStack00000010;
  
  FUN_40993230();
  uVar5 = *(undefined4 *)(param_1 + 0x7c);
  iVar1 = __litofp(*(undefined4 *)(param_1 + 0x3c));
  uVar2 = __litofp(*(undefined4 *)(param_1 + 0x40));
  uVar3 = __litofp(*(undefined4 *)(param_1 + 0x34));
  uVar4 = __litofp(*(undefined4 *)(param_1 + 0x38));
  iStack00000010 = iVar1;
  iVar1 = mali_frame_builder_viewport(uVar5,uVar4,uVar3,uVar2);
  if (iVar1 == 0) {
    iStack00000010 = *(int *)(param_1 + 0x2c) + -1;
    if (iStack00000010 < 1) {
      iStack00000010 = 0;
    }
    iVar1 = *(int *)(param_1 + 0x30) + -1;
    if (iVar1 < 1) {
      iVar1 = 0;
    }
    mali_frame_builder_scissor
              (uVar5,*(undefined4 *)(param_1 + 0x28),*(undefined4 *)(param_1 + 0x24),iVar1);
  }
                    /* WARNING: Subroutine does not return */
  FUN_40993258(0x18);
}



/* 409669e8 FUN_409669e8 */

/* Boundary evidence: original MIPS .pdata 409669e8..40966a03. Semantic name remains unreviewed. */

void FUN_409669e8(undefined4 param_1,undefined4 param_2)

{
  mali_sys_memcpy(param_1,param_2,1);
  return;
}



/* 40966a04 FUN_40966a04 */

/* Boundary evidence: original MIPS .pdata 40966a04..40966a1f. Semantic name remains unreviewed. */

void FUN_40966a04(undefined4 param_1,undefined4 param_2)

{
  mali_sys_memcpy(param_1,param_2,1);
  return;
}



/* 40966a6c FUN_40966a6c */

/* Boundary evidence: original MIPS .pdata 40966a6c..40966a87. Semantic name remains unreviewed. */

void FUN_40966a6c(void)

{
  mali_sys_atomic_inc();
  return;
}



/* 40966a90 FUN_40966a90 */

/* Boundary evidence: original MIPS .pdata 40966a90..40966ac7. Semantic name remains unreviewed. */

int FUN_40966a90(int *param_1,int param_2)

{
  int iVar1;
  
  if (param_1[1] == 0) {
    iVar1 = mali_mem_mali_addr_get_full();
  }
  else {
    iVar1 = *param_1 + param_2;
  }
  return iVar1;
}



/* 40966ac8 FUN_40966ac8 */

/* Boundary evidence: original MIPS .pdata 40966ac8..40966b57. Semantic name remains unreviewed. */

uint FUN_40966ac8(int param_1)

{
  uint uVar1;
  int local_18;
  uint local_14;
  
  local_14 = 0;
  local_18 = 0;
  if ((*(int *)(param_1 + 8) != 1) || (uVar1 = 0x400, *(int *)(param_1 + 0xc) == 0x1401)) {
    uVar1 = 0;
  }
  FUN_409668c0(param_1,&local_14,&local_18);
  return (((local_18 << 1 | local_14) << 5 | *(uint *)(param_1 + 0x6c)) << 4 |
         *(uint *)(param_1 + 0x58)) << 8 | uVar1;
}



/* 40966b58 FUN_40966b58 */

/* Boundary evidence: original MIPS .pdata 40966b58..40966b8f. Semantic name remains unreviewed. */

void FUN_40966b58(int param_1)

{
  if ((*(uint *)(param_1 + 0xc) & 0x4000000) != 0) {
    __fpmul(*(undefined4 *)(*(int *)(param_1 + 0x4fc) + 0x70),0x40000000);
  }
  return;
}



/* 40966b90 FUN_40966b90 */

/* Boundary evidence: original MIPS .pdata 40966b90..40966c8f. Semantic name remains unreviewed. */

void FUN_40966b90(int param_1,undefined4 param_2,int param_3,int *param_4)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  int iVar6;
  
  FUN_40993370();
  uVar5 = *(uint *)(param_1 + 0xc);
  iVar6 = *param_4;
  iVar3 = *(int *)(param_1 + 0x4fc);
  if ((uVar5 & 0x20000000) == 0) {
    if ((uVar5 & 0x10000000) == 0) goto LAB_40966c80;
    puVar2 = (undefined4 *)(iVar6 * 8 + param_3);
    *puVar2 = *(undefined4 *)(iVar3 + 0x5c);
    puVar2[1] = 0x1000010d;
  }
  else {
    if (*(int *)(iVar3 + 0x6c) == 1) {
      uVar1 = *(undefined4 *)(iVar3 + 0x70);
      if ((uVar5 & 0x4000000) != 0) {
        uVar1 = __fpmul(uVar1,0x40000000);
      }
      uVar4 = 0x1000010d;
    }
    else {
      if ((uVar5 & 0x40000000) == 0) goto LAB_40966c80;
      puVar2 = *(undefined4 **)(iVar3 + 0x8c);
      if (puVar2[1] == 0) {
        uVar1 = mali_mem_mali_addr_get_full(puVar2,0);
      }
      else {
        uVar1 = *puVar2;
      }
      uVar4 = 0x10000102;
    }
    puVar2 = (undefined4 *)(iVar6 * 8 + param_3);
    *puVar2 = uVar1;
    puVar2[1] = uVar4;
  }
  iVar6 = iVar6 + 1;
LAB_40966c80:
  *param_4 = iVar6;
                    /* WARNING: Subroutine does not return */
  FUN_40993390(0x10);
}



/* 40966c90 FUN_40966c90 */

/* Boundary evidence: original MIPS .pdata 40966c90..40966de7. Semantic name remains unreviewed. */

void FUN_40966c90(int param_1,undefined4 param_2,int param_3,int *param_4)

{
  uint uVar1;
  uint *puVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  
  FUN_40993230();
  iVar7 = *(int *)(param_1 + 0x4fc);
  iVar5 = *param_4;
  uVar1 = FUN_40966ac8(iVar7);
  puVar2 = (uint *)(iVar5 * 8 + param_3);
  puVar2[1] = 0x1000010b;
  *puVar2 = uVar1;
  uVar1 = *(uint *)(iVar7 + 0x48) >> 6;
  puVar2 = (uint *)((iVar5 + 1) * 8 + param_3);
  *puVar2 = *(uint *)(iVar7 + 0x44) & 0xffffffe0;
  puVar2[1] = ((uVar1 | 0xe0000000) >> 3) << 5 | (uVar1 & 7) << 2;
  uVar1 = *(uint *)(param_1 + 0xc);
  iVar6 = iVar5 + 2;
  if (((uVar1 >> 1 | uVar1) & 0x400000) != 0) {
    if (((uVar1 & 0x400000) != 0) && (iVar7 = FUN_4096693c(iVar7), iVar7 != 0)) goto LAB_40966de0;
    puVar3 = (undefined4 *)(iVar6 * 8 + param_3);
    puVar3[1] = 0x1000010a;
    *puVar3 = 0;
    puVar3 = (undefined4 *)((iVar5 + 3) * 8 + param_3);
    uVar4 = *(undefined4 *)(param_1 + 0x420);
    *puVar3 = *(undefined4 *)(param_1 + 0x41c);
    puVar3[1] = 0x1000010e;
    puVar3 = (undefined4 *)((iVar5 + 4) * 8 + param_3);
    puVar3[1] = 0x1000010f;
    *puVar3 = uVar4;
    iVar6 = iVar5 + 5;
    uVar1 = *(uint *)(param_1 + 0xc);
    *(uint *)(param_1 + 0xc) = uVar1 & 0xffbfffff;
    *(uint *)(param_1 + 0xc) = uVar1 & 0xff3fffff;
  }
  *param_4 = iVar6;
LAB_40966de0:
                    /* WARNING: Subroutine does not return */
  FUN_40993258(0x10);
}



/* 40966de8 FUN_40966de8 */

/* Boundary evidence: original MIPS .pdata 40966de8..40966eb7. Semantic name remains unreviewed. */

void FUN_40966de8(int param_1,undefined4 param_2,int param_3,int *param_4)

{
  int iVar1;
  undefined4 *puVar2;
  int *piVar3;
  
  FUN_40993370();
  puVar2 = *(undefined4 **)(*(int *)(param_1 + 0x90) + 0x30c);
  if (puVar2 == (undefined4 *)0x0) {
    iVar1 = FUN_40974b50(*(undefined4 **)(param_1 + 0x74),param_3,param_4);
    if (iVar1 != 0) {
      mali_sys_memcpy(iVar1,*(undefined4 *)(param_1 + 0x10),param_3);
    }
  }
  else {
    piVar3 = (int *)*puVar2;
    mali_sys_atomic_inc(*piVar3);
    iVar1 = mali_frame_builder_add_callback
                      (*(undefined4 *)(param_1 + 0x7c),mali_mem_ref_deref,*piVar3);
    if (iVar1 == 0) {
      iVar1 = piVar3[1] + *(int *)(param_1 + 0x10);
      piVar3 = *(int **)(*piVar3 + 4);
      if (piVar3[1] == 0) {
        iVar1 = mali_mem_mali_addr_get_full(piVar3,iVar1);
      }
      else {
        iVar1 = *piVar3 + iVar1;
      }
      *param_4 = iVar1;
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_40993390(0x10);
}



/* 40966eb8 FUN_40966eb8 */

/* Boundary evidence: original MIPS .pdata 40966eb8..40966f23. Semantic name remains unreviewed. */

void FUN_40966eb8(int param_1,undefined4 param_2,int *param_3)

{
  uint uVar1;
  
  uVar1 = 0;
  if (*(int *)(param_1 + 0xc) == 0x1401) {
    uVar1 = *(int *)(param_1 + 0x18) + 3U & 0xfffffffc;
  }
  else if (*(int *)(param_1 + 0xc) == 0x1403) {
    uVar1 = *(int *)(param_1 + 0x18) * 2 + 3U & 0xfffffffc;
  }
  FUN_40966de8(param_1,param_2,uVar1,param_3);
  return;
}



/* 40966f24 FUN_40966f24 */

/* Boundary evidence: original MIPS .pdata 40966f24..40967027. Semantic name remains unreviewed. */

void FUN_40966f24(int param_1,undefined4 param_2,int param_3,int *param_4,int param_5)

{
  int iVar1;
  undefined4 *puVar2;
  uint uVar3;
  uint *puVar4;
  uint uVar5;
  int *piVar6;
  uint *puVar7;
  int iVar8;
  uint uVar9;
  
  FUN_40993230();
  iVar8 = *param_4;
  puVar7 = *(uint **)(param_1 + 0x4fc);
  uVar9 = *(uint *)(param_1 + 0xc) >> 0x1e & 1;
  if (uVar9 != 0) {
    iVar1 = FUN_40966eb8((int)puVar7,param_2,&param_5);
    if (iVar1 != 0) goto LAB_40967020;
    puVar4 = (uint *)(iVar8 * 8 + param_3);
    *puVar4 = puVar7[0x22];
    puVar4[1] = 0x10000100;
    piVar6 = (int *)((iVar8 + 1) * 8 + param_3);
    *piVar6 = param_5;
    piVar6[1] = 0x10000101;
    puVar2 = (undefined4 *)((iVar8 + 2) * 8 + param_3);
    iVar8 = iVar8 + 3;
    *puVar2 = 0x10001;
    puVar2[1] = 0x60000000;
  }
  uVar3 = puVar7[1];
  uVar5 = puVar7[6];
  puVar4 = (uint *)(iVar8 * 8 + param_3);
  *puVar4 = uVar5 << 0x18 | *puVar7 & 0xffffff;
  puVar4[1] = ((uVar9 << 5 | uVar3 & 0x1f) << 0x18 | uVar5 & 0xffffff) >> 8;
  *param_4 = iVar8 + 1;
LAB_40967020:
                    /* WARNING: Subroutine does not return */
  FUN_40993258(0x18);
}



/* 40967028 FUN_40967028 */

/* Boundary evidence: original MIPS .pdata 40967028..4096712b. Semantic name remains unreviewed. */

void FUN_40967028(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  uint *puVar5;
  
  FUN_409933b0();
  iVar3 = *(int *)(param_1 + 0x4fc);
  uVar1 = mali_frame_builder_get_gp_job(*(undefined4 *)(iVar3 + 0x7c));
  puVar5 = (uint *)(param_1 + 0xc);
  mali_sys_memcpy(&stack0x00000018,puVar5,1);
  piVar4 = (int *)(iVar3 + 0x158);
  iVar3 = iVar3 + 0xd8;
  *piVar4 = 0;
  iVar2 = FUN_40966c90(param_1,uVar1,iVar3,piVar4);
  if (((iVar2 != 0) ||
      ((((*puVar5 & 0x8000000) == 0 &&
        (iVar2 = FUN_40966b90(param_1,uVar1,iVar3,piVar4), iVar2 != 0)) ||
       (iVar2 = FUN_40966f24(param_1,uVar1,iVar3,piVar4,0x10), iVar2 != 0)))) ||
     (iVar2 = mali_gp_job_add_plbu_cmds(uVar1,iVar3,*piVar4), iVar2 != 0)) {
    mali_sys_memcpy(puVar5,&stack0x00000018,1);
  }
                    /* WARNING: Subroutine does not return */
  FUN_409933e0(0x20);
}



/* 4096712c FUN_4096712c */

/* Boundary evidence: original MIPS .pdata 4096712c..409671ab. Semantic name remains unreviewed. */

void FUN_4096712c(int param_1,undefined4 *param_2,int param_3,int param_4,int param_5)

{
  undefined4 uVar1;
  
  if (param_3 != -1) {
    *(undefined4 *)(param_3 * 4 + param_1) = *param_2;
  }
  if (param_4 != -1) {
    *(undefined4 *)(param_4 * 4 + param_1) = param_2[1];
  }
  if (param_5 != -1) {
    uVar1 = __fpsub(param_2[1],*param_2);
    *(undefined4 *)(param_5 * 4 + param_1) = uVar1;
  }
  return;
}



/* 409671ac FUN_409671ac */

/* Boundary evidence: original MIPS .pdata 409671ac..4096732b. Semantic name remains unreviewed. */

void FUN_409671ac(int param_1,uint param_2,uint param_3,uint param_4)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  uint local_60 [16];
  
  uVar1 = mali_frame_builder_get_gp_job(*(undefined4 *)(param_1 + 0x7c));
  if (param_4 != 0) {
    local_60[1] = (param_4 >> 2 & 0xfff) << 0x10 | 0x30000000;
    local_60[0] = param_3;
  }
  uVar6 = (uint)(param_4 != 0);
  local_60[uVar6 * 2 + 1] = 0x20400000;
  local_60[uVar6 * 2] = param_2;
  uVar4 = *(uint *)(param_1 + 8);
  local_60[(uVar6 + 1) * 2] = 3;
  local_60[(uVar6 + 1) * 2 + 1] = 0x10000041;
  uVar3 = *(uint *)(param_1 + 0x14);
  iVar5 = uVar6 + 3;
  local_60[(uVar6 + 2) * 2] = uVar3 << 0x18 | uVar4 & 1;
  local_60[(uVar6 + 2) * 2 + 1] = (uVar3 & 0xffffff) >> 8;
  if (uVar4 == 0) {
    local_60[iVar5 * 2] = 0;
    local_60[iVar5 * 2 + 1] = 0x60000000;
  }
  else {
    uVar3 = mali_frame_builder_get_flush_subroutine(*(undefined4 *)(param_1 + 0x7c));
    local_60[iVar5 * 2] = uVar3;
    local_60[iVar5 * 2 + 1] = 0x70000000;
  }
  iVar2 = uVar6 + 4;
  iVar5 = iVar2;
  if (*(int *)(param_1 + 8) != 0) {
    iVar5 = uVar6 + 5;
    local_60[iVar2 * 2] = 0x18000;
    local_60[iVar2 * 2 + 1] = 0x50000000;
  }
  mali_gp_job_add_vs_cmds(uVar1,local_60,iVar5);
  return;
}



/* 4096732c FUN_4096732c */

/* Boundary evidence: original MIPS .pdata 4096732c..40967357. Semantic name remains unreviewed. */

void FUN_4096732c(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  uVar1 = mali_frame_builder_get_gp_job(*(undefined4 *)(param_1 + 0x7c));
  mali_gp_job_add_vs_cmd(uVar1);
  return;
}



/* 40967358 FUN_40967358 */

/* Boundary evidence: original MIPS .pdata 40967358..409673b7. Semantic name remains unreviewed. */

void FUN_40967358(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = mali_frame_builder_get_gp_job(*(undefined4 *)(param_1 + 0x7c));
  iVar2 = mali_gp_job_add_vs_cmd(uVar1);
  if (iVar2 == 0) {
    mali_gp_job_add_vs_cmd(uVar1);
  }
  return;
}



/* 409673c8 FUN_409673c8 */

/* Boundary evidence: original MIPS .pdata 409673c8..409674f7. Semantic name remains unreviewed. */

undefined4 FUN_409673c8(int param_1,int *param_2,uint *param_3)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  
  iVar3 = *(int *)(param_1 + 0x4fc);
  iVar1 = *(int *)(iVar3 + 0x80);
  iVar5 = *(int *)(iVar1 + 0x6c);
  uVar4 = 0;
  if (0 < iVar5) {
    iVar6 = *(int *)(iVar1 + 0x68);
    iVar7 = *(int *)(iVar1 + 0x144);
    uVar4 = iVar5 + 3U & 0xfffffffc;
    FUN_409684ec(param_1,(undefined4 *)(*(int *)(iVar1 + 0x140) * 4 + iVar6));
    iVar1 = *(int *)(iVar3 + 0x80);
    FUN_4096712c(iVar6,(undefined4 *)(param_1 + 0x414),*(int *)(iVar1 + 0x150),
                 *(int *)(iVar1 + 0x154),*(int *)(iVar1 + 0x158));
    if (iVar7 != -1) {
      puVar2 = (undefined4 *)(iVar7 * 4 + iVar6);
      *puVar2 = *(undefined4 *)(iVar3 + 100);
      puVar2[1] = *(undefined4 *)(iVar3 + 0x68);
      *(undefined4 *)((iVar7 + 2) * 4 + iVar6) = *(undefined4 *)(iVar3 + 0x60);
    }
    iVar1 = FUN_40974b50(*(undefined4 **)(iVar3 + 0x74),uVar4 << 2,param_2);
    if (iVar1 == 0) {
      return 0xffffffff;
    }
    mali_sys_memcpy(iVar1,iVar6,iVar5 << 2);
  }
  *param_3 = uVar4;
  return 0;
}



/* 409674f8 FUN_409674f8 */

/* Boundary evidence: original MIPS .pdata 409674f8..40967583. Semantic name remains unreviewed. */

void FUN_409674f8(int param_1,int *param_2)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int iVar3;
  
  FUN_40993370();
  uVar1 = mali_frame_builder_get_gp_job(*(undefined4 *)(param_1 + 0x7c));
  puVar2 = (undefined4 *)FUN_40974b50(*(undefined4 **)(param_1 + 0x74),0x100,param_2);
  if (((puVar2 != (undefined4 *)0x0) && (iVar3 = FUN_40969868(param_1,puVar2), iVar3 == 0)) &&
     (iVar3 = FUN_409667cc(param_1,(int)puVar2), iVar3 == 0)) {
    iVar3 = *(int *)(*(int *)(param_1 + 0x80) + 0x178);
    mali_gp_job_add_vs_cmds(uVar1,iVar3 + 0x10,*(undefined4 *)(iVar3 + 8));
  }
                    /* WARNING: Subroutine does not return */
  FUN_40993390(0x10);
}



/* 40967584 FUN_40967584 */

/* Boundary evidence: original MIPS .pdata 40967584..409675df. Semantic name remains unreviewed. */

void FUN_40967584(int param_1)

{
  int iVar1;
  int iVar2;
  uint local_18;
  uint local_14;
  uint local_10 [2];
  
  iVar2 = *(int *)(param_1 + 0x4fc);
  iVar1 = FUN_409673c8(param_1,(int *)&local_14,&local_18);
  if ((iVar1 == 0) && (iVar1 = FUN_409674f8(iVar2,(int *)local_10), iVar1 == 0)) {
    FUN_409671ac(iVar2,local_10[0],local_14,local_18);
  }
  return;
}



/* 40967634 FUN_40967634 */

/* Boundary evidence: original MIPS .pdata 40967634..40967667. Semantic name remains unreviewed. */

undefined4 FUN_40967634(undefined4 *param_1)

{
  undefined4 uVar1;
  
  if (param_1[1] == 0) {
    uVar1 = mali_mem_mali_addr_get_full(param_1,0);
  }
  else {
    uVar1 = *param_1;
  }
  return uVar1;
}



/* 40967668 FUN_40967668 */

/* Boundary evidence: original MIPS .pdata 40967668..409678d7. Semantic name remains unreviewed. */

void FUN_40967668(undefined4 *param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  undefined4 uStack00000018;
  undefined4 uStack0000001c;
  undefined4 uStack00000020;
  undefined4 uStack00000024;
  
  FUN_409933b0();
  uVar4 = param_1[0x13d];
  puVar5 = (undefined4 *)param_1[0x140];
  uStack00000018 = 0xb08b06c0;
  uStack0000001c = 0x438002c3;
  uStack00000020 = 0x40010d00;
  uStack00000024 = 0x1c08;
  iVar1 = mali_mem_alloc(*param_1,0x10,0x40,0x34);
  if (iVar1 != 0) {
    mali_frame_builder_add_gp_job_mem(uVar4,iVar1);
    mali_mem_write(iVar1,0,&stack0x00000018,0x10);
    if (*(int *)(iVar1 + 4) == 0) {
      mali_mem_mali_addr_get_full(iVar1,0);
    }
    iVar1 = mali_gp_job_add_vs_cmd(param_2);
    if ((iVar1 == 0) &&
       (puVar2 = (undefined4 *)mali_mem_alloc(*param_1,0xc,0x40,0x34), puVar2 != (undefined4 *)0x0))
    {
      mali_frame_builder_add_gp_job_mem(uVar4,puVar2);
      mali_mem_write(puVar2,0,param_3,0x24);
      iVar1 = mali_mem_alloc(*param_1,0x88,0x40,0x3c);
      if (iVar1 != 0) {
        mali_frame_builder_add_gp_job_mem(uVar4,iVar1);
        puVar3 = (undefined4 *)mali_mem_ptr_map_area(iVar1,0,0x88,0x40);
        if (puVar3 != (undefined4 *)0x0) {
          if (puVar2[1] == 0) {
            uVar4 = mali_mem_mali_addr_get_full(puVar2,0);
          }
          else {
            uVar4 = *puVar2;
          }
          *puVar3 = uVar4;
          puVar3[1] = 0x6002;
          puVar3[0x20] = *puVar5;
          puVar3[0x21] = 0x8020;
          mali_mem_ptr_unmap_area(iVar1);
          if (*(int *)(iVar1 + 4) == 0) {
            mali_mem_mali_addr_get_full(iVar1,0);
          }
          iVar1 = mali_gp_job_add_vs_cmd(param_2);
          if ((((iVar1 == 0) && (iVar1 = mali_gp_job_add_vs_cmd(param_2), iVar1 == 0)) &&
              (iVar1 = mali_gp_job_add_vs_cmd(param_2), iVar1 == 0)) &&
             ((iVar1 = mali_gp_job_add_vs_cmd(param_2), iVar1 == 0 &&
              (iVar1 = mali_gp_job_add_vs_cmd(param_2), iVar1 == 0)))) {
            mali_gp_job_add_vs_cmd(param_2);
          }
        }
      }
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_409933e0(0x28);
}



/* 409678d8 FUN_409678d8 */

/* Boundary evidence: original MIPS .pdata 409678d8..40967aab. Semantic name remains unreviewed. */

void FUN_409678d8(int param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  uint uVar5;
  int iVar6;
  undefined4 uVar7;
  
  iVar6 = *(int *)(param_1 + 0x4fc);
  uVar5 = *(uint *)(iVar6 + 0x48) >> 6;
  uVar7 = *(undefined4 *)(param_1 + 0x4f4);
  iVar1 = mali_gp_job_add_plbu_cmd
                    (param_2,param_2,*(uint *)(iVar6 + 0x44) & 0xffffffe0,
                     ((uVar5 | 0xe0000000) >> 3) << 5 | (uVar5 & 7) << 2);
  if (iVar1 == 0) {
    mali_frame_builder_get_tile_list_block_scale(uVar7);
    iVar1 = mali_gp_job_add_plbu_cmd(param_2);
    if ((((iVar1 == 0) && (iVar1 = mali_gp_job_add_plbu_cmd(param_2), iVar1 == 0)) &&
        (iVar1 = mali_gp_job_add_plbu_cmd(param_2), iVar1 == 0)) &&
       (iVar1 = mali_gp_job_add_plbu_cmd(param_2), iVar1 == 0)) {
      iVar1 = 1;
      if ((*(uint *)(param_1 + 0xc) & 0x4000000) != 0) {
        iVar1 = 2;
      }
      iVar2 = mali_frame_builder_get_frame_height(uVar7);
      uVar3 = __ultofp(iVar2 * iVar1);
      iVar2 = mali_frame_builder_get_frame_width(uVar7);
      uVar4 = __ultofp(iVar2 * iVar1);
      iVar1 = mali_frame_builder_viewport(uVar7,0,0,uVar4,uVar3);
      if (iVar1 == 0) {
        iVar1 = mali_frame_builder_scissor
                          (uVar7,*(undefined4 *)(iVar6 + 0x28),*(undefined4 *)(iVar6 + 0x24),
                           *(int *)(iVar6 + 0x30) + -1,*(int *)(iVar6 + 0x2c) + -1);
        if (iVar1 == 0) {
          mali_gp_job_add_plbu_cmd(param_2);
        }
      }
    }
  }
  return;
}



/* 40967aec FUN_40967aec */

/* Boundary evidence: original MIPS .pdata 40967aec..40967d07. Semantic name remains unreviewed. */

void FUN_40967aec(undefined4 *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uStack00000010;
  undefined4 uStack00000014;
  undefined4 uStack00000018;
  undefined4 uStack0000001c;
  undefined4 uStack00000020;
  undefined4 uStack00000024;
  undefined4 uStack00000028;
  undefined4 uStack0000002c;
  undefined4 uStack00000030;
  
  FUN_409933b0();
  uVar6 = param_1[0x13d];
  iVar4 = param_1[0x13f];
  *(undefined4 *)(iVar4 + 0x7c) = uVar6;
  *(undefined4 *)(iVar4 + 8) = 0;
  iVar1 = mali_frame_builder_get_frame_width(uVar6);
  iVar2 = mali_frame_builder_get_frame_height(uVar6);
  uVar7 = param_1[0x11c];
  iVar3 = __lts(uVar7,0);
  if (iVar3 == 0) {
    iVar3 = __gts(uVar7,0x3f800000);
    uVar5 = 0x3f800000;
    if (iVar3 == 0) {
      uVar5 = uVar7;
    }
  }
  else {
    uVar5 = 0;
  }
  iVar3 = mali_frame_builder_get_supersample_factor(uVar6);
  if (iVar3 == 2) {
    param_1[3] = param_1[3] | 0x4000000;
  }
  else {
    param_1[3] = param_1[3] & 0xfbffffff;
  }
  if ((param_1[3] & 0x4000000) != 0) {
    iVar1 = iVar1 << 1;
    iVar2 = iVar2 << 1;
  }
  uStack00000010 = 0;
  uStack00000014 = 0;
  uStack0000001c = __litofp(iVar1);
  uStack00000020 = 0;
  uStack00000028 = uStack0000001c;
  uStack0000002c = __litofp(iVar2);
  iVar1 = iVar4;
  uStack00000018 = uVar5;
  uStack00000024 = uVar5;
  uStack00000030 = uVar5;
  FUN_40968264((int)param_1,iVar4,uVar6,0);
  if (((*(int *)(iVar4 + 0x28) < *(int *)(iVar4 + 0x30)) &&
      (*(int *)(iVar4 + 0x24) < *(int *)(iVar4 + 0x2c))) &&
     (iVar1 = FUN_40967358(iVar4,iVar1), iVar1 == 0)) {
    uVar7 = mali_frame_builder_get_gp_job(*(undefined4 *)(iVar4 + 0x7c));
    iVar1 = mali_gp_job_add_plbu_cmd(uVar7);
    if (iVar1 == 0) {
      uVar7 = mali_frame_builder_get_gp_job(uVar6);
      iVar1 = FUN_40967668(param_1,uVar7,&stack0x00000010);
      if (iVar1 == 0) {
        uVar7 = mali_frame_builder_get_gp_job(uVar6);
        iVar1 = FUN_409678d8((int)param_1,uVar7);
        if ((iVar1 == 0) && (iVar1 = mali_frame_builder_flush_gp(uVar6,0,0), iVar1 == 0)) {
          uVar6 = mali_frame_builder_get_gp_job(*(undefined4 *)(iVar4 + 0x7c));
          iVar1 = mali_gp_job_add_vs_cmd(uVar6);
          if (iVar1 == 0) {
            uVar6 = mali_frame_builder_get_gp_job(*(undefined4 *)(iVar4 + 0x7c));
            mali_gp_job_add_plbu_cmd(uVar6);
          }
        }
      }
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_409933e0(0x38);
}



/* 40967d08 FUN_40967d08 */

/* Boundary evidence: original MIPS .pdata 40967d08..40967d23. Semantic name remains unreviewed. */

void FUN_40967d08(void)

{
  mali_sys_free();
  return;
}



/* 40967d24 FUN_40967d24 */

/* Boundary evidence: original MIPS .pdata 40967d24..40967d43. Semantic name remains unreviewed. */

void FUN_40967d24(undefined4 param_1,int param_2)

{
  mali_gp_job_add_vs_cmds(param_1,param_2 + 0x10,*(undefined4 *)(param_2 + 8));
  return;
}



/* 40967d44 FUN_40967d44 */

/* Boundary evidence: original MIPS .pdata 40967d44..40967d67. Semantic name remains unreviewed. */

void FUN_40967d44(int param_1,int param_2)

{
  mali_sys_memcpy(param_1 + 0x80,param_2 + 200,0x80);
  return;
}



/* 40967d68 FUN_40967d68 */

void FUN_40967d68(int param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 *puVar5;
  uint uVar6;
  
  puVar5 = (undefined4 *)(param_2 + 0x80);
  iVar2 = 0x10;
  puVar3 = puVar5;
  do {
    *puVar3 = 0;
    puVar3[1] = 0x3f;
    iVar2 = iVar2 + -1;
    puVar3 = puVar3 + 2;
  } while (iVar2 != 0);
  uVar6 = 0;
  if (*(int *)(param_1 + 0x20) != 0) {
    iVar2 = 0;
    do {
      puVar3 = (undefined4 *)(*(int *)(param_1 + 0x28) + iVar2);
      uVar1 = puVar3[1] - 1;
      if (puVar3[2] != 4) {
        uVar1 = uVar1 | 0xc;
      }
      iVar4 = *(int *)(param_1 + 0x24);
      *puVar5 = *puVar3;
      puVar5[1] = iVar4 << 0xb | uVar1 & 0x3f;
      uVar6 = uVar6 + 1;
      iVar2 = iVar2 + 0xc;
      puVar5 = puVar5 + 2;
    } while (uVar6 < *(uint *)(param_1 + 0x20));
  }
  return;
}



/* 40967df8 FUN_40967df8 */

/* Boundary evidence: original MIPS .pdata 40967df8..40967e2b. Semantic name remains unreviewed. */

undefined4 FUN_40967df8(undefined4 *param_1)

{
  undefined4 uVar1;
  
  if (param_1[1] == 0) {
    uVar1 = mali_mem_mali_addr_get_full(param_1,0);
  }
  else {
    uVar1 = *param_1;
  }
  return uVar1;
}



/* 40967e2c FUN_40967e2c */

/* Boundary evidence: original MIPS .pdata 40967e2c..40967f97. Semantic name remains unreviewed. */

int * FUN_40967e2c(int param_1)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  
  piVar1 = (int *)mali_sys_malloc(0x148);
  if (piVar1 == (int *)0x0) {
    piVar1 = (int *)0x0;
  }
  else {
    mali_sys_memset(piVar1,0,0x148);
    piVar4 = *(int **)(*(int *)(param_1 + 0x3c) + 4);
    if (piVar4[1] == 0) {
      iVar2 = mali_mem_mali_addr_get_full(piVar4,0);
    }
    else {
      iVar2 = *piVar4;
    }
    uVar3 = *(uint *)(param_1 + 0x60);
    iVar5 = piVar1[2];
    piVar1[(iVar5 + 2) * 2] = iVar2;
    (piVar1 + (iVar5 + 2) * 2)[1] = (uVar3 & 0xfff) << 0x10 | 0x40000000;
    iVar2 = piVar1[2];
    piVar1[2] = iVar2 + 1;
    piVar1[(iVar2 + 3) * 2] =
         ((*(int *)(param_1 + 100) + -1) * 0x400 | *(int *)(param_1 + 0x60) - 1U) << 10 |
         *(uint *)(param_1 + 0x5c);
    (piVar1 + (iVar2 + 3) * 2)[1] = 0x10000040;
    iVar2 = piVar1[2];
    piVar1[2] = iVar2 + 1;
    iVar5 = *(int *)(param_1 + 0x54);
    *piVar1 = iVar5;
    iVar6 = *(int *)(param_1 + 0x58);
    piVar1[1] = iVar6;
    piVar1[(iVar2 + 3) * 2] = ((iVar5 - 1U & 0xf) << 0x10 | iVar6 - 1U & 0xf) << 8;
    (piVar1 + (iVar2 + 3) * 2)[1] = 0x10000042;
    piVar1[2] = piVar1[2] + 1;
    FUN_40967d68(param_1,(int)(piVar1 + 0x12));
  }
  return piVar1;
}



/* 40967fac FUN_40967fac */

/* Boundary evidence: original MIPS .pdata 40967fac..409680b7. Semantic name remains unreviewed. */

void FUN_40967fac(int param_1,int param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  
  FUN_40993230();
  iVar7 = 2;
  if (param_4 != 2) {
    iVar7 = 1;
  }
  iVar2 = mali_frame_builder_get_frame_height(param_3);
  iVar2 = iVar2 * iVar7;
  iVar3 = mali_frame_builder_get_frame_width(param_3);
  iVar3 = iVar3 * iVar7;
  iVar6 = *(int *)(param_1 + 0x404) * iVar7;
  iVar5 = *(int *)(param_1 + 0x408) * iVar7;
  iVar1 = *(int *)(param_1 + 0x410) * iVar7;
  if (*(int *)(param_1 + 0x490) == 0) {
    iVar4 = iVar1 + iVar5;
  }
  else {
    iVar4 = iVar2 - iVar5;
    iVar5 = iVar4 - iVar1;
  }
  iVar7 = *(int *)(param_1 + 0x40c) * iVar7 + iVar6;
  if (iVar4 < 0) {
    iVar4 = 0;
  }
  else if (iVar2 < iVar4) {
    iVar4 = iVar2;
  }
  if (iVar5 < 0) {
    iVar5 = 0;
  }
  else if (iVar2 < iVar5) {
    iVar5 = iVar2;
  }
  if (iVar6 < 0) {
    iVar6 = 0;
  }
  else if (iVar3 < iVar6) {
    iVar6 = iVar3;
  }
  if (iVar7 < 0) {
    iVar7 = 0;
  }
  else if (iVar3 < iVar7) {
    iVar7 = iVar3;
  }
  *(int *)(param_2 + 0x3c) = iVar4;
  *(int *)(param_2 + 0x34) = iVar5;
  *(int *)(param_2 + 0x38) = iVar6;
                    /* WARNING: Subroutine does not return */
  *(int *)(param_2 + 0x40) = iVar7;
  FUN_40993258(0x10);
}



/* 40968144 FUN_40968144 */

/* Boundary evidence: original MIPS .pdata 40968144..4096815f. Semantic name remains unreviewed. */

void FUN_40968144(void)

{
  mali_sys_atomic_inc();
  return;
}



/* 40968160 FUN_40968160 */

/* Boundary evidence: original MIPS .pdata 40968160..40968263. Semantic name remains unreviewed. */

void FUN_40968160(int param_1,int param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  
  FUN_40993230();
  uVar4 = 0x40000000;
  if (param_3 != 2) {
    uVar4 = 0x3f800000;
  }
  *(undefined4 *)(param_2 + 0x6c) = 1;
  *(undefined4 *)(param_2 + 0x70) = 0x3f800000;
  if ((*(uint *)(param_1 + 0xc) & 0x20000000) != 0) {
    if (*(int *)(*(int *)(param_2 + 0x80) + 0x4c) == -1) {
      uVar3 = *(undefined4 *)(param_1 + 0x3f4);
      uVar2 = *(undefined4 *)(param_1 + 0x3f8);
      iVar1 = __lts(uVar3,uVar2);
      if (iVar1 == 0) {
        uVar2 = *(undefined4 *)(param_1 + 0x3fc);
        iVar1 = __gts(uVar3,uVar2);
        if (iVar1 == 0) {
          uVar2 = uVar3;
        }
      }
      *(undefined4 *)(param_2 + 0x70) = uVar2;
    }
    else {
      *(undefined4 *)(param_2 + 0x6c) = 0;
    }
  }
  *(undefined4 *)(param_2 + 0x60) = uVar4;
  *(undefined4 *)(param_2 + 100) = *(undefined4 *)(param_1 + 0x3f8);
  *(undefined4 *)(param_2 + 0x68) = *(undefined4 *)(param_1 + 0x3fc);
  uVar3 = *(undefined4 *)(param_1 + 0x400);
  iVar1 = __lts(uVar3,0x3e800000);
  uVar2 = 0x3e800000;
  if (iVar1 == 0) {
    iVar1 = __gts(uVar3,0x42c80000);
    uVar2 = 0x42c80000;
    if (iVar1 == 0) {
      uVar2 = uVar3;
    }
  }
  uVar4 = __fpmul(uVar2,uVar4);
  *(undefined4 *)(param_2 + 0x5c) = uVar4;
                    /* WARNING: Subroutine does not return */
  FUN_40993258(0x10);
}



/* 40968264 FUN_40968264 */

/* Boundary evidence: original MIPS .pdata 40968264..409684eb. Semantic name remains unreviewed. */

void FUN_40968264(int param_1,int param_2,undefined4 param_3,uint param_4)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  uint uVar12;
  int iVar13;
  int iVar14;
  
  FUN_40993230();
  iVar2 = mali_frame_builder_get_frame_width(param_3);
  iVar3 = mali_frame_builder_get_frame_height(param_3);
  uVar6 = *(uint *)(param_1 + 0xc);
  uVar12 = uVar6 >> 0x10 & 1;
  iVar10 = 1;
  if (((((uVar6 >> 0x13 & 1) != 0) || ((uVar6 >> 0x11 & 1 & uVar12) != 0)) ||
      ((uVar6 >> 0x19 & 1) != 0)) || (bVar1 = false, (uVar6 >> 0x18 & 1) != 0)) {
    bVar1 = true;
  }
  uVar12 = (((uint)(*(int *)(param_1 + 0x488) == 0) << 1 | param_4) << 1 | uVar6 >> 0x1a & 1) << 1 |
           uVar12;
  if ((bVar1) || (*(uint *)(param_1 + 0x3e4) != uVar12)) {
    *(uint *)(param_1 + 0x3e4) = uVar12;
    uVar6 = *(uint *)(param_1 + 0xc);
    *(uint *)(param_1 + 0xc) = uVar6 & 0xfffdffff;
    *(uint *)(param_1 + 0xc) = uVar6 & 0xfff5ffff;
    *(uint *)(param_1 + 0xc) = uVar6 & 0xfef5ffff;
    *(uint *)(param_1 + 0xc) = uVar6 & 0xfcf5ffff;
    if ((*(ushort *)(param_1 + 0xe) & 1) == 0) {
      iVar11 = 0;
      iVar9 = 0;
      iVar5 = iVar3;
      iVar8 = iVar2;
    }
    else {
      iVar11 = *(int *)(param_1 + 0x3d4);
      iVar9 = *(int *)(param_1 + 0x3d8);
      iVar5 = *(int *)(param_1 + 0x3e0) + iVar9;
      iVar8 = *(int *)(param_1 + 0x3dc) + iVar11;
    }
    if (param_4 == 1) {
      iVar13 = *(int *)(param_1 + 0x404);
      iVar7 = *(int *)(param_1 + 0x408);
      iVar14 = *(int *)(param_1 + 0x40c) + iVar13;
      iVar4 = *(int *)(param_1 + 0x410) + iVar7;
      if (iVar11 <= iVar13) {
        iVar11 = iVar13;
      }
      if (iVar14 <= iVar8) {
        iVar8 = iVar14;
      }
      if (iVar9 <= iVar7) {
        iVar9 = iVar7;
      }
      if (iVar4 <= iVar5) {
        iVar5 = iVar4;
      }
    }
    if ((*(uint *)(param_1 + 0xc) & 0x4000000) != 0) {
      iVar10 = 2;
    }
    if (*(int *)(param_1 + 0x490) != 0) {
      iVar4 = iVar3 - iVar9;
      iVar9 = iVar3 - iVar5;
      iVar5 = iVar4;
    }
    iVar11 = iVar11 * iVar10;
    iVar8 = iVar8 * iVar10;
    iVar5 = iVar5 * iVar10;
    iVar9 = iVar9 * iVar10;
    iVar2 = iVar10 * iVar2;
    iVar10 = iVar10 * iVar3;
    if (iVar11 < 0) {
      iVar11 = 0;
    }
    if (iVar2 < iVar11) {
      iVar11 = iVar2;
    }
    *(int *)(param_2 + 0x28) = iVar11;
    if (iVar8 < 0) {
      iVar8 = 0;
    }
    if (iVar2 < iVar8) {
      iVar8 = iVar2;
    }
    *(int *)(param_2 + 0x30) = iVar8;
    if (iVar5 < 0) {
      iVar5 = 0;
    }
    if (iVar10 < iVar5) {
      iVar5 = iVar10;
    }
    *(int *)(param_2 + 0x2c) = iVar5;
    if (iVar9 < 0) {
      iVar9 = 0;
    }
    if (iVar10 < iVar9) {
      iVar9 = iVar10;
    }
    *(int *)(param_2 + 0x24) = iVar9;
    *(uint *)(param_1 + 0xc) = *(uint *)(param_1 + 0xc) | 0x400000;
  }
                    /* WARNING: Subroutine does not return */
  FUN_40993258(0x10);
}



/* 409684ec FUN_409684ec */

/* Boundary evidence: original MIPS .pdata 409684ec..409686ef. Semantic name remains unreviewed. */

void FUN_409684ec(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  uint uVar6;
  uint *puVar7;
  
  FUN_40993300();
  puVar7 = (uint *)(param_1 + 0xc);
  uVar6 = 0x3f800000;
  if ((*puVar7 & 0x40000) != 0) {
    uVar1 = __litofp(*(undefined4 *)(param_1 + 0x40c));
    uVar1 = __fpmul(uVar1,0x3f000000);
    *(undefined4 *)(param_1 + 0x444) = uVar1;
    uVar2 = __litofp(*(undefined4 *)(param_1 + 0x410));
    uVar2 = __fpmul(uVar2,0x3f000000);
    *(undefined4 *)(param_1 + 0x448) = uVar2;
    uVar3 = __litofp(*(undefined4 *)(param_1 + 0x404));
    uVar3 = __fpadd(uVar3,uVar1);
    *(undefined4 *)(param_1 + 0x44c) = uVar3;
    uVar4 = __litofp(*(undefined4 *)(param_1 + 0x408));
    uVar2 = __fpadd(uVar4,uVar2);
    *(undefined4 *)(param_1 + 0x424) = uVar1;
    uVar5 = *(undefined4 *)(param_1 + 0x418);
    uVar4 = *(undefined4 *)(param_1 + 0x414);
    *(undefined4 *)(param_1 + 0x450) = uVar2;
    uVar1 = __fpsub(uVar5,uVar4);
    uVar1 = __fpmul(uVar1,0x3f000000);
    *(undefined4 *)(param_1 + 0x42c) = uVar1;
    *(undefined4 *)(param_1 + 0x430) = 0x3f800000;
    *(undefined4 *)(param_1 + 0x434) = uVar3;
    uVar1 = __fpadd(uVar4,uVar5);
    uVar1 = __fpmul(uVar1,0x3f000000);
    *(undefined4 *)(param_1 + 0x43c) = uVar1;
    *(undefined4 *)(param_1 + 0x440) = 0;
    *puVar7 = *puVar7 & 0xfffbffff;
  }
  mali_sys_memcpy(param_2,param_1 + 0x424,0x20);
  uVar1 = *(undefined4 *)(param_1 + 0x4f4);
  if ((*puVar7 & 0x4000000) != 0) {
    uVar6 = 0x40000000;
    uVar2 = __fpmul(*param_2,0x40000000);
    *param_2 = uVar2;
    uVar2 = __fpmul(param_2[4],0x40000000);
    param_2[4] = uVar2;
  }
  if (*(int *)(param_1 + 0x490) == 0) {
    uVar1 = __fpmul(*(undefined4 *)(param_1 + 0x448),uVar6);
    param_2[1] = uVar1;
    uVar1 = *(undefined4 *)(param_1 + 0x450);
  }
  else {
    uVar6 = uVar6 ^ 0x80000000;
    uVar2 = __fpmul(*(undefined4 *)(param_1 + 0x448),uVar6);
    param_2[1] = uVar2;
    uVar1 = mali_frame_builder_get_frame_height(uVar1);
    uVar1 = __ultofp(uVar1);
    uVar1 = __fpsub(*(undefined4 *)(param_1 + 0x450),uVar1);
  }
  uVar1 = __fpmul(uVar1,uVar6);
  param_2[5] = uVar1;
  if (((*(uint *)(*(int *)(param_1 + 0x504) + 0x40) & 0x80) != 0) && ((*puVar7 & 0x8000000) != 0)) {
    uVar1 = __fpmul(*(undefined4 *)(*(int *)(param_1 + 0x504) + 0x80),0x33800001);
    uVar1 = __fpadd(uVar1,param_2[6]);
    param_2[6] = uVar1;
  }
                    /* WARNING: Subroutine does not return */
  FUN_40993338(0x10);
}



/* 409686f0 FUN_409686f0 */

/* Boundary evidence: original MIPS .pdata 409686f0..4096876b. Semantic name remains unreviewed. */

int FUN_409686f0(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  iVar3 = *(int *)(param_1 + 0x4fc);
  uVar2 = *(undefined4 *)(param_1 + 0x4f4);
  *(undefined4 *)(iVar3 + 0x7c) = uVar2;
  mali_sys_atomic_inc(*(undefined4 *)(*(int *)(iVar3 + 0x80) + 0x3c));
  iVar1 = mali_frame_builder_add_callback
                    (uVar2,mali_mem_ref_deref,*(undefined4 *)(*(int *)(iVar3 + 0x80) + 0x3c));
  if (iVar1 == 0) {
    iVar1 = 0;
  }
  else {
    mali_mem_ref_deref(*(undefined4 *)(*(int *)(iVar3 + 0x80) + 0x3c));
  }
  return iVar1;
}



/* 4096876c FUN_4096876c */

/* Boundary evidence: original MIPS .pdata 4096876c..40968867. Semantic name remains unreviewed. */

void FUN_4096876c(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  
  puVar4 = *(undefined4 **)(param_1 + 0x4fc);
  uVar5 = *(undefined4 *)(param_1 + 0x4f4);
  iVar3 = *(int *)(param_1 + 0x500);
  FUN_40968264(param_1,(int)puVar4,uVar5,*(uint *)(param_1 + 0xc) >> 0x1b & 1);
  iVar1 = mali_frame_builder_get_supersample_factor(uVar5);
  FUN_40967fac(param_1,(int)puVar4,uVar5,iVar1);
  puVar4[0x24] = param_1 + 0x14;
  *puVar4 = *(undefined4 *)(iVar3 + 0xc);
  if ((*(uint *)(param_1 + 0xc) & 0x8000000) == 0) {
    iVar1 = mali_frame_builder_get_supersample_factor(uVar5);
    FUN_40968160(param_1,(int)puVar4,iVar1);
  }
  *(undefined1 *)(puVar4 + 0x13) = *(undefined1 *)(param_1 + 0x3ec);
  puVar4[0x14] = *(undefined4 *)(param_1 + 0x3f0);
  iVar1 = *(int *)(param_1 + 1000);
  puVar4[0x15] = iVar1;
  if (*(int *)(param_1 + 0x490) == 0) {
    uVar2 = 0x901;
    if (iVar1 == 0x901) {
      uVar2 = 0x900;
    }
    puVar4[0x15] = uVar2;
  }
  uVar5 = mali_frame_builder_get_tile_list_block_scale(uVar5);
  puVar4[0x16] = uVar5;
  return;
}



/* 40968868 FUN_40968868 */

/* Boundary evidence: original MIPS .pdata 40968868..4096894b. Semantic name remains unreviewed. */

void FUN_40968868(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  FUN_40993370();
  iVar3 = *(int *)(param_1 + 0x4fc);
  if (((*(int *)(iVar3 + 0x28) < *(int *)(iVar3 + 0x30)) &&
      (*(int *)(iVar3 + 0x24) < *(int *)(iVar3 + 0x2c))) &&
     (iVar1 = FUN_40967358(iVar3,param_2), iVar1 == 0)) {
    uVar2 = mali_frame_builder_get_gp_job(*(undefined4 *)(iVar3 + 0x7c));
    iVar1 = mali_gp_job_add_plbu_cmd(uVar2);
    if (((iVar1 == 0) && (iVar1 = FUN_40967584(param_1), iVar1 == 0)) &&
       (iVar1 = FUN_40967028(param_1), iVar1 == 0)) {
      uVar2 = mali_frame_builder_get_gp_job(*(undefined4 *)(iVar3 + 0x7c));
      iVar1 = mali_gp_job_add_vs_cmd(uVar2);
      if (iVar1 == 0) {
        uVar2 = mali_frame_builder_get_gp_job(*(undefined4 *)(iVar3 + 0x7c));
        mali_gp_job_add_plbu_cmd(uVar2);
      }
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_40993390(0x10);
}



/* 4096894c FUN_4096894c */

/* Boundary evidence: original MIPS .pdata 4096894c..40968c57. Semantic name remains unreviewed. */

void FUN_4096894c(int param_1,uint param_2,int param_3,uint param_4)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  undefined4 *puVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iStack00000010;
  int iStack00000014;
  uint uStack00000018;
  
  FUN_40993300();
  iVar5 = *(int *)(param_1 + 0x4fc);
  iVar7 = 0;
  iVar6 = 0;
  iVar8 = 0;
  *(undefined4 *)(iVar5 + 0x80) = *(undefined4 *)(param_1 + 0x4d4);
  if (param_2 == 0) goto LAB_409689e0;
  if (param_2 == 1) {
    iVar6 = 2;
    goto LAB_409689e4;
  }
  if (param_2 == 2) {
    *(undefined4 *)(iVar5 + 4) = 3;
LAB_40968b64:
    iVar7 = 1;
LAB_409689e0:
    iVar6 = 1;
  }
  else {
    if (param_2 == 3) goto LAB_40968b64;
    if (param_2 != 4) {
      if (param_2 == 5) {
        iVar7 = 2;
      }
      else {
        if (param_2 != 6) goto LAB_409689e4;
        iVar7 = 2;
        iVar8 = 1;
      }
      goto LAB_409689e0;
    }
    iVar6 = 3;
  }
LAB_409689e4:
  uVar3 = param_2;
  iStack00000010 = param_3;
  iStack00000014 = param_3;
  uStack00000018 = param_4;
  iVar1 = FUN_409686f0(param_1);
  if (iVar1 == 0) {
    FUN_4096876c(param_1);
    *(undefined4 *)(iVar5 + 0x80) = *(undefined4 *)(param_1 + 0x4d4);
    if (((*(int *)(iVar5 + 0x28) < *(int *)(iVar5 + 0x30)) &&
        (*(int *)(iVar5 + 0x24) < *(int *)(iVar5 + 0x2c))) &&
       (iVar1 = FUN_40967358(iVar5,uVar3), iVar1 == 0)) {
      uVar2 = mali_frame_builder_get_gp_job(*(undefined4 *)(iVar5 + 0x7c));
      iVar1 = mali_gp_job_add_plbu_cmd(uVar2);
      if (iVar1 == 0) {
        for (; (uint)(iVar6 + iVar7) <= param_4; param_4 = (iVar7 - uVar3) + param_4) {
          uVar3 = 0x10000;
          if (param_4 < 0x10001) {
            uVar3 = param_4;
          }
          uVar3 = FUN_40974e18(param_2,uVar3);
          iVar1 = FUN_4096d6a8(param_1,uVar3);
          if (iVar1 != 0) goto LAB_40968c50;
          puVar4 = *(undefined4 **)(param_1 + 0x500);
          *(undefined4 *)(iVar5 + 0x88) = *puVar4;
          *(undefined4 *)(iVar5 + 0x84) = puVar4[1];
          if (iVar8 != 0) {
            *(int *)(iVar5 + 0x14) = iVar8;
            *(int *)(iVar5 + 0x1c) = iStack00000014;
            *(undefined4 *)(iVar5 + 0x20) = 0;
            iVar1 = FUN_40967584(param_1);
            if (iVar1 != 0) goto LAB_40968c50;
          }
          *(uint *)(iVar5 + 0x14) = uVar3 - iVar8;
          *(int *)(iVar5 + 0x1c) = iVar8 + iStack00000010;
          *(int *)(iVar5 + 0x20) = iVar8;
          iVar1 = FUN_40967584(param_1);
          if (iVar1 != 0) goto LAB_40968c50;
          *(int *)(iVar5 + 0x1c) = iStack00000010;
          *(uint *)(iVar5 + 0x18) = uVar3;
          iVar1 = FUN_40967028(param_1);
          if (iVar1 != 0) goto LAB_40968c50;
          iStack00000010 = (uVar3 - iVar7) + iStack00000010;
        }
        if (param_2 == 2) {
          iVar7 = FUN_4096d6a8(param_1,2);
          iVar6 = iStack00000014;
          if (iVar7 != 0) goto LAB_40968c50;
          puVar4 = *(undefined4 **)(param_1 + 0x500);
          *(undefined4 *)(iVar5 + 0x88) = *puVar4;
          *(undefined4 *)(iVar5 + 0x84) = puVar4[1];
          *(undefined4 *)(iVar5 + 0x14) = 1;
          *(uint *)(iVar5 + 0x1c) = uStack00000018 + iStack00000014 + -1;
          *(undefined4 *)(iVar5 + 0x20) = 0;
          iVar7 = FUN_40967584(param_1);
          if (iVar7 != 0) goto LAB_40968c50;
          *(undefined4 *)(iVar5 + 0x14) = 1;
          *(int *)(iVar5 + 0x1c) = iVar6;
          *(undefined4 *)(iVar5 + 0x20) = 1;
          iVar6 = FUN_40967584(param_1);
          if (iVar6 != 0) goto LAB_40968c50;
          *(undefined4 *)(iVar5 + 0x18) = 2;
          *(undefined4 *)(iVar5 + 0x1c) = 0;
          iVar6 = FUN_40967028(param_1);
          if (iVar6 != 0) goto LAB_40968c50;
        }
        uVar2 = mali_frame_builder_get_gp_job(*(undefined4 *)(iVar5 + 0x7c));
        iVar6 = mali_gp_job_add_vs_cmd(uVar2);
        if (iVar6 == 0) {
          uVar2 = mali_frame_builder_get_gp_job(*(undefined4 *)(iVar5 + 0x7c));
          mali_gp_job_add_plbu_cmd(uVar2);
        }
      }
    }
  }
LAB_40968c50:
                    /* WARNING: Subroutine does not return */
  FUN_40993338(0x20);
}



/* 40968c58 FUN_40968c58 */

/* Boundary evidence: original MIPS .pdata 40968c58..40968d7f. Semantic name remains unreviewed. */

void FUN_40968c58(undefined4 *param_1,undefined4 param_2,int param_3,int param_4)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 in_stack_00000030;
  undefined4 in_stack_00000034;
  undefined4 in_stack_00000038;
  
  FUN_40993370();
  iVar4 = param_1[0x13f];
  *(undefined4 *)(iVar4 + 0x74) = param_1[0x144];
  uVar2 = param_1[0x135];
  *(undefined4 *)(iVar4 + 8) = 1;
  *(undefined4 *)(iVar4 + 0x80) = uVar2;
  *(undefined4 *)(iVar4 + 4) = param_2;
  iVar1 = (param_4 - param_3) + 1;
  *(int *)(iVar4 + 0x14) = iVar1;
  *(undefined4 *)(iVar4 + 0xc) = in_stack_00000034;
  *(undefined4 *)(iVar4 + 0x10) = in_stack_00000038;
  *(int *)(iVar4 + 0x1c) = param_3;
  *(undefined4 *)(iVar4 + 0x18) = in_stack_00000030;
  *(undefined4 *)(iVar4 + 0x20) = 0;
  iVar1 = FUN_4096d6a8((int)param_1,iVar1);
  if (iVar1 == 0) {
    puVar3 = (undefined4 *)param_1[0x140];
    *(undefined4 *)(iVar4 + 0x88) = *puVar3;
    *(undefined4 *)(iVar4 + 0x84) = puVar3[1];
    iVar1 = FUN_409686f0((int)param_1);
    if ((((iVar1 == 0) &&
         (FUN_4096876c((int)param_1), *(int *)(iVar4 + 0x28) < *(int *)(iVar4 + 0x30))) &&
        (*(int *)(iVar4 + 0x24) < *(int *)(iVar4 + 0x2c))) &&
       ((iVar1 = FUN_40967584((int)param_1), iVar1 != 0 ||
        (iVar1 = FUN_40967028((int)param_1), iVar1 != 0)))) {
      mali_frame_builder_reset(param_1[0x13d]);
      iVar1 = FUN_40978694(param_1);
      if (iVar1 == 0) {
        FUN_40974c48((undefined4 *)param_1[0x144]);
      }
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_40993390(0x10);
}



/* 40968d80 FUN_40968d80 */

/* Boundary evidence: original MIPS .pdata 40968d80..40968e83. Semantic name remains unreviewed. */

void FUN_40968d80(undefined4 *param_1,uint param_2,int param_3,uint param_4)

{
  int iVar1;
  uint uVar2;
  undefined4 *puVar3;
  int iVar4;
  
  FUN_40993230();
  iVar4 = param_1[0x13f];
  *(undefined4 *)(iVar4 + 0x74) = param_1[0x144];
  *(uint *)(iVar4 + 4) = param_2;
  *(undefined4 *)(iVar4 + 8) = 0;
  *(undefined4 *)(iVar4 + 0xc) = 0;
  *(undefined4 *)(iVar4 + 0x10) = 0;
  if (param_4 < 0x10001) {
    uVar2 = param_4;
    iVar1 = FUN_4096d6a8((int)param_1,param_4);
    if (iVar1 != 0) goto LAB_40968e78;
    puVar3 = (undefined4 *)param_1[0x140];
    *(undefined4 *)(iVar4 + 0x88) = *puVar3;
    *(undefined4 *)(iVar4 + 0x84) = puVar3[1];
    *(uint *)(iVar4 + 0x14) = param_4;
    *(int *)(iVar4 + 0x1c) = param_3;
    *(uint *)(iVar4 + 0x18) = param_4;
    *(undefined4 *)(iVar4 + 0x20) = 0;
    *(undefined4 *)(iVar4 + 0x80) = param_1[0x135];
    iVar4 = FUN_409686f0((int)param_1);
    if (iVar4 != 0) goto LAB_40968e78;
    FUN_4096876c((int)param_1);
    iVar4 = FUN_40968868((int)param_1,uVar2);
  }
  else {
    iVar4 = FUN_4096894c((int)param_1,param_2,param_3,param_4);
  }
  if (iVar4 != 0) {
    mali_frame_builder_reset(param_1[0x13d]);
    iVar4 = FUN_40978694(param_1);
    if (iVar4 == 0) {
      FUN_40974c48((undefined4 *)param_1[0x144]);
    }
  }
LAB_40968e78:
                    /* WARNING: Subroutine does not return */
  FUN_40993258(0x10);
}



/* 40968eac FUN_40968eac */

/* Boundary evidence: original MIPS .pdata 40968eac..409690c7. Semantic name remains unreviewed. */

void FUN_40968eac(int *param_1,uint param_2,uint param_3,uint param_4)

{
  uint uVar1;
  uint uVar2;
  ushort *puVar3;
  int *piVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint *puStack00000010;
  int *piStack00000014;
  uint *puStack00000018;
  int *piStack0000001c;
  uint *in_stack_00000260;
  uint *in_stack_00000264;
  
  FUN_40993300();
  uVar1 = DAT_40996268;
  piVar4 = param_1 + ((param_2 >> 2 ^ param_3 ^ param_4) & 0xff) * 5;
  piStack00000014 = param_1;
  piStack0000001c = piVar4;
  if (((((uint)piVar4[6] < (uint)piVar4[5]) || (piVar4[2] != param_2)) || (piVar4[4] != param_4)) ||
     (piVar4[3] != param_3)) {
    uVar8 = 0;
    uVar9 = 0xffffffff;
    puStack00000010 = in_stack_00000260;
    puStack00000018 = in_stack_00000264;
    if (param_4 == 0x1401) {
      uVar6 = 0;
      if (param_3 != 0) {
        do {
          uVar7 = param_3 - uVar6;
          if (0x200 < uVar7) {
            uVar7 = 0x200;
          }
          mali_mem_read(&stack0x00000020,*(undefined4 *)(*param_1 + 4),uVar6 + param_2,uVar7);
          uVar5 = 0;
          if (uVar7 != 0) {
            do {
              uVar2 = (uint)(byte)(&stack0x00000020)[uVar5];
              if (uVar2 < uVar9) {
                uVar9 = uVar2;
              }
              if (uVar8 < uVar2) {
                uVar8 = uVar2;
              }
              uVar5 = uVar5 + 1;
            } while (uVar5 < uVar7);
          }
          uVar6 = uVar6 + 0x200;
        } while (uVar6 < param_3);
      }
    }
    else if ((param_4 == 0x1403) && (uVar7 = 0, uVar6 = param_2, param_3 != 0)) {
      do {
        uVar5 = param_3 - uVar7;
        if (0x100 < uVar5) {
          uVar5 = 0x100;
        }
        mali_mem_read(&stack0x00000020,*(undefined4 *)(*param_1 + 4),uVar6,uVar5 << 1);
        if (uVar5 != 0) {
          puVar3 = (ushort *)&stack0x00000020;
          do {
            uVar2 = (uint)*puVar3;
            if (uVar2 < uVar9) {
              uVar9 = uVar2;
            }
            if (uVar8 < uVar2) {
              uVar8 = uVar2;
            }
            uVar5 = uVar5 - 1;
            prefetch(puVar3 + 2,0);
            puVar3 = puVar3 + 1;
          } while (uVar5 != 0);
        }
        uVar7 = uVar7 + 0x100;
        piVar4 = piStack0000001c;
        uVar6 = uVar6 + 0x200;
      } while (uVar7 < param_3);
    }
    piVar4[2] = param_2;
    piVar4[3] = param_3;
    piVar4[4] = param_4;
    piVar4[5] = uVar9;
    piVar4[6] = uVar8;
    *puStack00000010 = uVar9;
    *puStack00000018 = uVar8;
  }
  else {
    *in_stack_00000260 = piVar4[5];
    *in_stack_00000264 = piVar4[6];
  }
  FUN_40963898(uVar1);
                    /* WARNING: Subroutine does not return */
  FUN_40993338(0x228);
}



/* 409690c8 FUN_409690c8 */

/* Boundary evidence: original MIPS .pdata 409690c8..409690fb. Semantic name remains unreviewed. */

void FUN_409690c8(undefined4 *param_1)

{
  mali_mem_ref_deref(*param_1);
  *param_1 = 0;
  mali_sys_free(param_1);
  return;
}



/* 409690fc FUN_409690fc */

/* Boundary evidence: original MIPS .pdata 409690fc..40969187. Semantic name remains unreviewed. */

void FUN_409690fc(undefined4 param_1,undefined4 param_2,int param_3,int *param_4)

{
  int iVar1;
  int *piVar2;
  
  FUN_40993370();
  param_4[1] = 0;
  iVar1 = mali_mem_ref_alloc_mem();
  *param_4 = iVar1;
  if (iVar1 == 0) {
    mali_sys_free(param_4);
  }
  else {
    if (param_3 != 0) {
      mali_mem_write(*(undefined4 *)(iVar1 + 4),0,param_3,param_2);
    }
    piVar2 = param_4 + 6;
    iVar1 = 0x100;
    do {
      piVar2[-1] = 1;
      iVar1 = iVar1 + -1;
      *piVar2 = 0;
      piVar2 = piVar2 + 5;
    } while (iVar1 != 0);
  }
                    /* WARNING: Subroutine does not return */
  FUN_40993390(0x10);
}



/* 40969188 FUN_40969188 */

/* Boundary evidence: original MIPS .pdata 40969188..409691a3. Semantic name remains unreviewed. */

void FUN_40969188(void)

{
  mali_sys_atomic_get();
  return;
}



/* 409691a4 FUN_409691a4 */

/* Boundary evidence: original MIPS .pdata 409691a4..409692cb. Semantic name remains unreviewed. */

int * FUN_409691a4(undefined4 param_1,int *param_2,int param_3,undefined4 param_4,int param_5,
                  undefined4 param_6,undefined4 param_7)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = mali_sys_atomic_get(*param_2);
  if (iVar1 == 1) {
    mali_mem_write(*(undefined4 *)(*param_2 + 4),param_2[1] + param_5,param_7,param_6);
    piVar2 = param_2 + 6;
    iVar1 = 0x100;
    do {
      piVar2[-1] = 1;
      iVar1 = iVar1 + -1;
      *piVar2 = 0;
      piVar2 = piVar2 + 5;
    } while (iVar1 != 0);
  }
  else {
    iVar1 = mali_mem_ref_alloc_mem(param_1,param_2[1] + param_3,4,0x34);
    if (iVar1 == 0) {
      param_2 = (int *)0x0;
    }
    else {
      mali_mem_copy(*(undefined4 *)(iVar1 + 4),param_2[1],*(undefined4 *)(*param_2 + 4),param_2[1],
                    param_3);
      mali_mem_write(*(undefined4 *)(iVar1 + 4),param_2[1] + param_5,param_7,param_6);
      mali_mem_ref_deref(*param_2);
      piVar2 = param_2 + 6;
      *param_2 = iVar1;
      iVar1 = 0x100;
      do {
        piVar2[-1] = 1;
        iVar1 = iVar1 + -1;
        *piVar2 = 0;
        piVar2 = piVar2 + 5;
      } while (iVar1 != 0);
    }
  }
  return param_2;
}



/* 409692cc FUN_409692cc */

uint FUN_409692cc(int param_1,int param_2,int param_3,uint param_4)

{
  uint uVar1;
  
  uVar1 = 0;
  if (param_2 == 0x1400) {
    uVar1 = 0x18;
    if (param_3 == 1) {
      uVar1 = 0x1d8;
    }
  }
  else if (param_2 == 0x1401) {
    uVar1 = 0x1c;
    if (param_3 == 1) {
      uVar1 = 0x21c;
    }
  }
  else if (param_2 == 0x1402) {
    uVar1 = 0x10;
    if (param_3 == 1) {
      uVar1 = 0x3d0;
    }
  }
  else if (param_2 == 0x1403) {
    uVar1 = 0x14;
    if (param_3 == 1) {
      uVar1 = 0x414;
    }
  }
  else if (param_2 == 0x1406) {
    uVar1 = 0;
  }
  else if (param_2 == 0x140c) {
    uVar1 = 0x404;
  }
  return (param_4 & 0xfffff) << 0xb | param_1 - 1U | uVar1;
}



/* 409693c0 FUN_409693c0 */

/* Boundary evidence: original MIPS .pdata 409693c0..409693db. Semantic name remains unreviewed. */

void FUN_409693c0(void)

{
  mali_sys_atomic_inc();
  return;
}



/* 409693dc FUN_409693dc */

/* Boundary evidence: original MIPS .pdata 409693dc..4096940f. Semantic name remains unreviewed. */

undefined4 FUN_409693dc(undefined4 *param_1)

{
  undefined4 uVar1;
  
  if (param_1[1] == 0) {
    uVar1 = mali_mem_mali_addr_get_full(param_1,0);
  }
  else {
    uVar1 = *param_1;
  }
  return uVar1;
}



/* 40969410 FUN_40969410 */

/* Boundary evidence: original MIPS .pdata 40969410..40969497. Semantic name remains unreviewed. */

void FUN_40969410(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  
  FUN_40993370();
  piVar3 = (int *)((param_3 + 0x25) * 4 + param_1);
  if (*piVar3 != 0) {
    *(int *)(param_1 + 0xd4) = *(int *)(param_1 + 0xd4) + -1;
  }
  *piVar3 = 0;
  iVar2 = param_3 * 0x30 + param_2;
  if ((*(int *)(iVar2 + 0x18) == 0) &&
     (iVar1 = FUN_409769fc(*(uint *)(iVar2 + 0xc)),
     *(int *)(iVar2 + 8) != iVar1 * *(int *)(iVar2 + 4))) {
    *(int *)(param_1 + 0xd4) = *(int *)(param_1 + 0xd4) + 1;
    *piVar3 = 1;
  }
                    /* WARNING: Subroutine does not return */
  FUN_40993390(0x10);
}



/* 40969498 FUN_40969498 */

/* Boundary evidence: original MIPS .pdata 40969498..4096958b. Semantic name remains unreviewed. */

void FUN_40969498(int param_1,int param_2,int param_3,int param_4,undefined4 param_5,
                 undefined4 param_6,int param_7)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint in_stack_00000058;
  int *in_stack_0000005c;
  int *in_stack_00000060;
  int *in_stack_00000064;
  
  FUN_40993300();
  iVar1 = FUN_409769fc(in_stack_00000058);
  iVar1 = iVar1 * param_4;
  iVar4 = *(int *)(param_1 + 0x14);
  iVar5 = *in_stack_0000005c;
  iVar2 = FUN_40974b50(*(undefined4 **)(param_1 + 0x74),iVar1 * iVar4,&param_7);
  if (iVar2 != 0) {
    if (param_3 != 0) {
      param_2 = mali_mem_ptr_map_area
                          (*(undefined4 *)(param_3 + 4),*in_stack_00000064,iVar5 * iVar4,0x40);
    }
    if (0 < iVar4) {
      iVar3 = 0;
      do {
        mali_sys_memcpy(iVar2,iVar3 + *in_stack_00000064 + param_2,iVar1);
        iVar2 = iVar2 + iVar1;
        iVar4 = iVar4 + -1;
        iVar3 = iVar3 + iVar5;
      } while (iVar4 != 0);
    }
    if (param_3 != 0) {
      mali_mem_ptr_unmap_area(*(undefined4 *)(param_3 + 4));
    }
    *in_stack_00000060 = param_7;
    *in_stack_0000005c = iVar1;
    *in_stack_00000064 = 0;
  }
                    /* WARNING: Subroutine does not return */
  FUN_40993338(0x20);
}



/* 4096958c FUN_4096958c */

/* Boundary evidence: original MIPS .pdata 4096958c..409695df. Semantic name remains unreviewed. */

void FUN_4096958c(int param_1,int param_2,undefined4 param_3,int *param_4)

{
  int iVar1;
  
  FUN_40993370();
  iVar1 = FUN_40974b50(*(undefined4 **)(param_1 + 0x74),param_2,param_4);
  if (iVar1 != 0) {
    mali_sys_memcpy(iVar1,param_3,param_2);
  }
                    /* WARNING: Subroutine does not return */
  FUN_40993390(0x10);
}



/* 409695e0 FUN_409695e0 */

/* Boundary evidence: original MIPS .pdata 409695e0..40969867. Semantic name remains unreviewed. */

void FUN_409695e0(int param_1,int param_2,int param_3,uint *param_4)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  int *piVar8;
  uint uVar9;
  int iVar10;
  uint uVar11;
  int iVar12;
  uint *puVar13;
  int iVar14;
  int iVar15;
  int iVar16;
  int iVar17;
  uint *puVar18;
  uint *puVar19;
  uint uVar20;
  int iStack00000018;
  int in_stack_00000098;
  int *in_stack_0000009c;
  
  FUN_40993300();
  iVar17 = 0;
  iVar16 = 0;
  iStack00000018 = param_2;
  if (1 < *(int *)(param_1 + 0xd4)) {
    iVar6 = 0;
    piVar3 = (int *)&stack0x00000020;
    piVar4 = (int *)(param_1 + 0x94);
    do {
      if (*piVar4 != 0) {
        *piVar3 = iVar6;
        iVar16 = iVar16 + 1;
        piVar3 = piVar3 + 1;
      }
      iVar6 = iVar6 + 1;
      prefetch(piVar4 + 2,0);
      piVar4 = piVar4 + 1;
    } while (iVar6 < 0x10);
    if (0 < iVar16) {
      piVar4 = (int *)&stack0x00000020;
      iVar6 = -1;
      puVar13 = param_4;
      do {
        iVar12 = *piVar4;
        iVar5 = iVar12 * 0x30 + iStack00000018;
        iVar14 = *(int *)(iVar5 + 8);
        iVar1 = FUN_409769fc(*(uint *)(iVar5 + 0xc));
        iVar15 = iVar6 + 1;
        iVar10 = 0;
        iVar2 = *(int *)(iVar5 + 4);
        piVar3 = (int *)(iVar12 * 4 + in_stack_00000098);
        *piVar3 = iVar17;
        iVar17 = iVar17 + 1;
        uVar20 = iVar1 * iVar2 + (param_3 + -1) * iVar14;
        iVar1 = *(int *)(param_1 + 0x1c);
        iVar2 = *(int *)(iVar5 + 0x14);
        puVar13[1] = uVar20;
        *puVar13 = iVar1 * iVar14 + iVar2;
        puVar18 = puVar13 + 4;
        in_stack_0000009c[iVar12] = 0;
        iVar1 = iVar15;
        if (0 < iVar15) {
          uVar9 = *(uint *)(iVar5 + 0x14);
          puVar19 = param_4;
LAB_409696f4:
          uVar11 = *puVar19;
          if ((uVar9 < uVar11) || (puVar19[1] + uVar11 <= uVar9)) {
            if ((uVar11 < uVar9) || (uVar9 + *(int *)(iVar5 + 8) <= uVar11)) goto LAB_40969738;
            puVar18 = param_4 + iVar10 * 4;
            uVar11 = *puVar18;
            uVar7 = puVar18[1] + (uVar11 - uVar9);
            *puVar18 = uVar9;
            if (uVar20 < uVar7) {
              puVar18[1] = uVar7;
            }
            else {
              puVar18[1] = uVar20;
            }
            iVar17 = 0x10;
            piVar8 = in_stack_0000009c;
            do {
              if (*(int *)((in_stack_00000098 - (int)in_stack_0000009c) + (int)piVar8) == iVar10) {
                *piVar8 = *piVar8 + (uVar11 - uVar9);
              }
              iVar17 = iVar17 + -1;
              piVar8 = piVar8 + 1;
            } while (iVar17 != 0);
            *piVar3 = iVar10;
            iVar1 = iVar6;
            iVar17 = iVar15;
            puVar18 = puVar13;
          }
          else {
            iVar2 = *(int *)(iVar5 + 0x14);
            puVar19 = param_4 + iVar10 * 4;
            uVar11 = *puVar19;
            uVar9 = puVar19[1];
            iVar5 = iVar2 - uVar11;
            *piVar3 = iVar10;
            in_stack_0000009c[iVar12] = iVar5;
            iVar1 = iVar6;
            iVar17 = iVar15;
            puVar18 = puVar13;
            if (uVar9 + uVar11 < iVar2 + uVar20) {
              puVar19[1] = iVar5 + uVar20;
            }
          }
        }
LAB_40969804:
        iVar16 = iVar16 + -1;
        piVar4 = piVar4 + 1;
        iVar6 = iVar1;
        puVar13 = puVar18;
      } while (iVar16 != 0);
    }
    iVar16 = 0;
    if (0 < iVar17) {
      puVar13 = param_4 + 2;
      do {
        uVar20 = FUN_4096958c(param_1,puVar13[-1],puVar13[-2],(int *)(puVar13 + 1));
        *puVar13 = uVar20;
        if (uVar20 == 0) break;
        iVar16 = iVar16 + 1;
        puVar13 = puVar13 + 4;
      } while (iVar16 < iVar17);
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_40993338(0x60);
LAB_40969738:
  iVar10 = iVar10 + 1;
  prefetch(puVar19 + 8,0);
  puVar19 = puVar19 + 4;
  if (iVar15 <= iVar10) goto LAB_40969804;
  goto LAB_409696f4;
}



/* 40969868 FUN_40969868 */

/* Boundary evidence: original MIPS .pdata 40969868..40969bc3. Semantic name remains unreviewed. */

void FUN_40969868(int param_1,undefined4 *param_2)

{
  byte bVar1;
  uint uVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  int iVar8;
  char *pcVar9;
  int iVar10;
  int iVar11;
  code *pcVar12;
  uint uVar13;
  int in_stack_00000024;
  int in_stack_00000028;
  int in_stack_0000002c;
  uint in_stack_00000030;
  code *in_stack_00000034;
  uint in_stack_00000038;
  int in_stack_0000003c;
  undefined4 *puStack00000040;
  int in_stack_00000044;
  int iStack00000048;
  
  FUN_40993300();
  iStack00000048 = *(int *)(param_1 + 0x14);
  iVar4 = 0x10;
  puVar3 = param_2;
  do {
    *puVar3 = 0;
    puVar3[1] = 0x3f;
    iVar4 = iVar4 + -1;
    puVar3 = puVar3 + 2;
  } while (iVar4 != 0);
  puVar3 = (undefined4 *)&stack0x00000090;
  do {
    *puVar3 = 0;
    puVar3 = puVar3 + 1;
  } while (puVar3 != (undefined4 *)&stack0x000000d0);
  puVar3 = (undefined4 *)&stack0x00000050;
  do {
    *puVar3 = 0xffffffff;
    puVar3 = puVar3 + 1;
  } while (puVar3 != (undefined4 *)&stack0x00000090);
  puStack00000040 = param_2;
  FUN_409695e0(param_1,*(int *)(param_1 + 0x90),iStack00000048,(uint *)&stack0x000000d0);
  uVar13 = 0;
  if (*(int *)(*(int *)(param_1 + 0x80) + 0x2c) != 0) {
    iVar4 = 0;
    in_stack_00000034 = mali_mem_ref_deref;
    do {
      pcVar12 = in_stack_00000034;
      iVar11 = 0;
      in_stack_00000044 = 0;
      in_stack_0000003c = *(int *)(*(int *)(*(int *)(param_1 + 0x80) + 0x30) + iVar4);
      iVar10 = 0;
      in_stack_00000024 = 0;
      iVar8 = *(int *)((in_stack_0000003c + 0x3e) * 4 + *(int *)(param_1 + 0x80));
      pcVar9 = (char *)(iVar8 * 0x30 + *(int *)(param_1 + 0x90));
      in_stack_00000028 = 0;
      if (*pcVar9 == '\0') {
        iVar11 = FUN_4096958c(param_1,0x10,pcVar9 + 0x20,&stack0x00000024);
        if (iVar11 == 0) break;
        iVar11 = 0;
        uVar2 = 3;
LAB_40969b44:
        (puStack00000040 + in_stack_0000003c * 2)[1] = uVar2;
        puStack00000040[in_stack_0000003c * 2] = iVar11 + in_stack_00000024;
        if (iVar10 != 0) {
          mali_sys_atomic_inc(iVar10);
          iVar11 = mali_frame_builder_add_callback(*(undefined4 *)(param_1 + 0x7c),pcVar12,iVar10);
          if (iVar11 != 0) {
            mali_mem_ref_deref(iVar10);
            break;
          }
        }
      }
      else {
        bVar1 = pcVar9[0x10];
        uVar2 = *(uint *)(pcVar9 + 8);
        in_stack_0000002c = *(int *)(pcVar9 + 4);
        in_stack_00000030 = *(uint *)(pcVar9 + 0xc);
        in_stack_00000038 = uVar2;
        if (*(int *)(pcVar9 + 0x18) == 0) {
          iVar8 = iVar8 * 4;
          if (*(int *)(&stack0x00000050 + iVar8) == -1) {
            iVar5 = *(int *)(param_1 + 0x1c);
            iVar6 = *(int *)(pcVar9 + 0x14);
            iVar8 = FUN_409769fc(in_stack_00000030);
            iVar8 = FUN_4096958c(param_1,iVar8 * in_stack_0000002c + (iStack00000048 + -1) * uVar2,
                                 iVar5 * uVar2 + iVar6,&stack0x00000024);
            if (iVar8 == 0) break;
          }
          else {
            iVar5 = *(int *)(&stack0x00000050 + iVar8) * 0x10;
            in_stack_00000024 = *(int *)(&stack0x000000dc + iVar5);
            iVar11 = *(int *)(&stack0x00000090 + iVar8);
            iVar8 = *(int *)(&stack0x000000d8 + iVar5);
            in_stack_00000028 = iVar11;
          }
LAB_40969ad4:
          if (((uVar2 & 0xfff00000) == 0) ||
             (iVar8 = FUN_40969498(param_1,iVar8,iVar10,in_stack_0000002c,in_stack_00000030,
                                   &stack0x00000038,(int)&stack0x00000024),
             iVar11 = in_stack_00000028, uVar2 = in_stack_00000038, iVar8 == 0)) {
            uVar2 = FUN_409692cc(in_stack_0000002c,in_stack_00000030,(uint)bVar1,uVar2);
            pcVar12 = in_stack_00000034;
            goto LAB_40969b44;
          }
          break;
        }
        if ((int *)**(int **)(pcVar9 + 0x1c) != (int *)0x0) {
          iVar10 = *(int *)**(int **)(pcVar9 + 0x1c);
          piVar7 = *(int **)(iVar10 + 4);
          if (piVar7[1] == 0) {
            in_stack_00000024 = mali_mem_mali_addr_get_full(piVar7,0);
          }
          else {
            in_stack_00000024 = *piVar7;
          }
          iVar11 = *(int *)(param_1 + 0x1c) * uVar2 + *(int *)(**(int **)(pcVar9 + 0x1c) + 4) +
                   *(int *)(pcVar9 + 0x14);
          iVar8 = in_stack_00000044;
          in_stack_00000028 = iVar11;
          goto LAB_40969ad4;
        }
      }
      uVar13 = uVar13 + 1;
      iVar4 = iVar4 + 8;
    } while (uVar13 < *(uint *)(*(int *)(param_1 + 0x80) + 0x2c));
  }
                    /* WARNING: Subroutine does not return */
  FUN_40993338(0x1d0);
}



/* 40969bdc FUN_40969bdc */

/* Boundary evidence: original MIPS .pdata 40969bdc..40969c27. Semantic name remains unreviewed. */

void FUN_40969bdc(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x4fc);
  if (iVar1 != 0) {
    if (*(int *)(iVar1 + 0x8c) != 0) {
      *(undefined4 *)(iVar1 + 0x8c) = 0;
    }
    *(undefined4 *)(iVar1 + 0x88) = 0;
    mali_sys_free(*(undefined4 *)(param_1 + 0x4fc));
    *(undefined4 *)(param_1 + 0x4fc) = 0;
  }
  return;
}



/* 40969c28 FUN_40969c28 */

/* Boundary evidence: original MIPS .pdata 40969c28..40969c9f. Semantic name remains unreviewed. */

undefined4 FUN_40969c28(undefined4 *param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  if (param_1[0x13f] != 0) {
    FUN_40969bdc((int)param_1);
  }
  iVar1 = mali_sys_malloc(0x160);
  if (iVar1 == 0) {
    uVar2 = 0xffffffff;
  }
  else {
    mali_sys_memset(iVar1,0,0x160);
    *(undefined4 *)(iVar1 + 0x78) = *param_1;
    uVar2 = 0;
    param_1[0x13f] = iVar1;
  }
  return uVar2;
}



/* 40969ca0 FUN_40969ca0 */

void FUN_40969ca0(undefined4 *param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  uint uVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  
  if (param_1 == param_2) {
    uVar9 = 0;
    uVar2 = 0;
    puVar3 = param_1 + 8;
    puVar1 = param_1;
    do {
      uVar8 = 0;
      if (3 < (int)uVar9) {
        iVar7 = (uVar9 - 4 >> 2) + 1;
        uVar8 = iVar7 * 4;
        puVar5 = puVar1;
        puVar6 = puVar3;
        do {
          iVar7 = iVar7 + -1;
          uVar4 = *puVar5;
          *puVar5 = puVar6[-8];
          puVar6[-8] = uVar4;
          uVar4 = puVar5[1];
          puVar5[1] = puVar6[-4];
          puVar6[-4] = uVar4;
          uVar4 = puVar5[2];
          puVar5[2] = *puVar6;
          *puVar6 = uVar4;
          uVar4 = puVar5[3];
          puVar5[3] = puVar6[4];
          puVar6[4] = uVar4;
          prefetch(puVar6 + 0x18,0);
          prefetch(puVar5 + 8,0);
          puVar5 = puVar5 + 4;
          puVar6 = puVar6 + 0x10;
        } while (iVar7 != 0);
      }
      if (uVar8 < uVar9) {
        puVar5 = param_1 + uVar2 + uVar8;
        puVar6 = param_1 + uVar8 * 4 + uVar9;
        iVar7 = uVar9 - uVar8;
        do {
          iVar7 = iVar7 + -1;
          uVar4 = *puVar5;
          *puVar5 = *puVar6;
          *puVar6 = uVar4;
          puVar6 = puVar6 + 4;
          puVar5 = puVar5 + 1;
        } while (iVar7 != 0);
      }
      uVar2 = uVar2 + 4;
      uVar9 = uVar9 + 1;
      puVar1 = puVar1 + 4;
      puVar3 = puVar3 + 1;
    } while (uVar2 < 0x10);
    return;
  }
  puVar3 = param_1 + 2;
  iVar7 = 4;
  puVar1 = param_2 + 4;
  do {
    iVar7 = iVar7 + -1;
    puVar3[-2] = puVar1[-4];
    puVar3[-1] = *puVar1;
    *puVar3 = puVar1[4];
    puVar3[1] = puVar1[8];
    prefetch(puVar1 + -2,0);
    puVar3 = puVar3 + 4;
    puVar1 = puVar1 + 1;
  } while (iVar7 != 0);
  return;
}



/* 40969e74 FUN_40969e74 */

/* Boundary evidence: original MIPS .pdata 40969e74..40969e8f. Semantic name remains unreviewed. */

void FUN_40969e74(undefined4 param_1,undefined4 param_2)

{
  mali_sys_memcpy(param_1,param_2,0x40);
  return;
}



/* 40969e90 FUN_40969e90 */

/* Boundary evidence: original MIPS .pdata 40969e90..4096a56f. Semantic name remains unreviewed. */

void FUN_40969e90(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  
  uVar6 = param_2[4];
  uVar5 = *param_2;
  uVar4 = param_2[8];
  uVar3 = param_2[0xc];
  uVar1 = __fpmul(param_3[1],uVar6);
  uVar2 = __fpmul(param_3[3],uVar3);
  uVar1 = __fpadd(uVar1,uVar2);
  uVar2 = __fpmul(param_3[2],uVar4);
  uVar1 = __fpadd(uVar1,uVar2);
  uVar2 = __fpmul(*param_3,uVar5);
  uVar1 = __fpadd(uVar1,uVar2);
  *param_1 = uVar1;
  uVar1 = __fpmul(param_3[4],uVar5);
  uVar2 = __fpmul(param_3[5],uVar6);
  uVar1 = __fpadd(uVar1,uVar2);
  uVar2 = __fpmul(param_3[7],uVar3);
  uVar1 = __fpadd(uVar1,uVar2);
  uVar2 = __fpmul(param_3[6],uVar4);
  uVar1 = __fpadd(uVar1,uVar2);
  param_1[4] = uVar1;
  uVar1 = __fpmul(param_3[9],uVar6);
  uVar2 = __fpmul(param_3[0xb],uVar3);
  uVar1 = __fpadd(uVar1,uVar2);
  uVar2 = __fpmul(param_3[10],uVar4);
  uVar1 = __fpadd(uVar1,uVar2);
  uVar2 = __fpmul(uVar5,param_3[8]);
  uVar1 = __fpadd(uVar1,uVar2);
  param_1[8] = uVar1;
  uVar1 = __fpmul(param_3[0xf],uVar3);
  uVar2 = __fpmul(param_3[0xe],uVar4);
  uVar1 = __fpadd(uVar1,uVar2);
  uVar2 = __fpmul(param_3[0xc],uVar5);
  uVar1 = __fpadd(uVar1,uVar2);
  uVar2 = __fpmul(uVar6,param_3[0xd]);
  uVar1 = __fpadd(uVar1,uVar2);
  param_1[0xc] = uVar1;
  uVar6 = param_2[5];
  uVar5 = param_2[1];
  uVar4 = param_2[9];
  uVar3 = param_2[0xd];
  uVar1 = __fpmul(param_3[1],uVar6);
  uVar2 = __fpmul(param_3[3],uVar3);
  uVar1 = __fpadd(uVar1,uVar2);
  uVar2 = __fpmul(param_3[2],uVar4);
  uVar1 = __fpadd(uVar1,uVar2);
  uVar2 = __fpmul(*param_3,uVar5);
  uVar1 = __fpadd(uVar1,uVar2);
  param_1[1] = uVar1;
  uVar1 = __fpmul(param_3[4],uVar5);
  uVar2 = __fpmul(param_3[5],uVar6);
  uVar1 = __fpadd(uVar1,uVar2);
  uVar2 = __fpmul(param_3[7],uVar3);
  uVar1 = __fpadd(uVar1,uVar2);
  uVar2 = __fpmul(param_3[6],uVar4);
  uVar1 = __fpadd(uVar1,uVar2);
  param_1[5] = uVar1;
  uVar1 = __fpmul(param_3[9],uVar6);
  uVar2 = __fpmul(param_3[0xb],uVar3);
  uVar1 = __fpadd(uVar1,uVar2);
  uVar2 = __fpmul(param_3[10],uVar4);
  uVar1 = __fpadd(uVar1,uVar2);
  uVar2 = __fpmul(uVar5,param_3[8]);
  uVar1 = __fpadd(uVar1,uVar2);
  param_1[9] = uVar1;
  uVar1 = __fpmul(param_3[0xf],uVar3);
  uVar2 = __fpmul(param_3[0xe],uVar4);
  uVar1 = __fpadd(uVar1,uVar2);
  uVar2 = __fpmul(param_3[0xc],uVar5);
  uVar1 = __fpadd(uVar1,uVar2);
  uVar2 = __fpmul(uVar6,param_3[0xd]);
  uVar1 = __fpadd(uVar1,uVar2);
  param_1[0xd] = uVar1;
  uVar6 = param_2[6];
  uVar5 = param_2[2];
  uVar4 = param_2[10];
  uVar3 = param_2[0xe];
  uVar1 = __fpmul(param_3[1],uVar6);
  uVar2 = __fpmul(param_3[3],uVar3);
  uVar1 = __fpadd(uVar1,uVar2);
  uVar2 = __fpmul(param_3[2],uVar4);
  uVar1 = __fpadd(uVar1,uVar2);
  uVar2 = __fpmul(*param_3,uVar5);
  uVar1 = __fpadd(uVar1,uVar2);
  param_1[2] = uVar1;
  uVar1 = __fpmul(param_3[4],uVar5);
  uVar2 = __fpmul(param_3[5],uVar6);
  uVar1 = __fpadd(uVar1,uVar2);
  uVar2 = __fpmul(param_3[7],uVar3);
  uVar1 = __fpadd(uVar1,uVar2);
  uVar2 = __fpmul(param_3[6],uVar4);
  uVar1 = __fpadd(uVar1,uVar2);
  param_1[6] = uVar1;
  uVar1 = __fpmul(param_3[9],uVar6);
  uVar2 = __fpmul(param_3[0xb],uVar3);
  uVar1 = __fpadd(uVar1,uVar2);
  uVar2 = __fpmul(param_3[10],uVar4);
  uVar1 = __fpadd(uVar1,uVar2);
  uVar2 = __fpmul(uVar5,param_3[8]);
  uVar1 = __fpadd(uVar1,uVar2);
  param_1[10] = uVar1;
  uVar1 = __fpmul(param_3[0xf],uVar3);
  uVar2 = __fpmul(param_3[0xe],uVar4);
  uVar1 = __fpadd(uVar1,uVar2);
  uVar2 = __fpmul(param_3[0xc],uVar5);
  uVar1 = __fpadd(uVar1,uVar2);
  uVar2 = __fpmul(uVar6,param_3[0xd]);
  uVar1 = __fpadd(uVar1,uVar2);
  param_1[0xe] = uVar1;
  uVar6 = param_2[7];
  uVar5 = param_2[3];
  uVar4 = param_2[0xb];
  uVar3 = param_2[0xf];
  uVar1 = __fpmul(param_3[1],uVar6);
  uVar2 = __fpmul(param_3[3],uVar3);
  uVar1 = __fpadd(uVar1,uVar2);
  uVar2 = __fpmul(param_3[2],uVar4);
  uVar1 = __fpadd(uVar1,uVar2);
  uVar2 = __fpmul(*param_3,uVar5);
  uVar1 = __fpadd(uVar1,uVar2);
  param_1[3] = uVar1;
  uVar1 = __fpmul(param_3[4],uVar5);
  uVar2 = __fpmul(param_3[5],uVar6);
  uVar1 = __fpadd(uVar1,uVar2);
  uVar2 = __fpmul(param_3[7],uVar3);
  uVar1 = __fpadd(uVar1,uVar2);
  uVar2 = __fpmul(param_3[6],uVar4);
  uVar1 = __fpadd(uVar1,uVar2);
  param_1[7] = uVar1;
  uVar1 = __fpmul(param_3[9],uVar6);
  uVar2 = __fpmul(param_3[0xb],uVar3);
  uVar1 = __fpadd(uVar1,uVar2);
  uVar2 = __fpmul(param_3[10],uVar4);
  uVar1 = __fpadd(uVar1,uVar2);
  uVar2 = __fpmul(uVar5,param_3[8]);
  uVar1 = __fpadd(uVar1,uVar2);
  param_1[0xb] = uVar1;
  uVar1 = __fpmul(param_3[0xf],uVar3);
  uVar2 = __fpmul(param_3[0xe],uVar4);
  uVar1 = __fpadd(uVar1,uVar2);
  uVar2 = __fpmul(param_3[0xc],uVar5);
  uVar1 = __fpadd(uVar1,uVar2);
  uVar2 = __fpmul(uVar6,param_3[0xd]);
  uVar1 = __fpadd(uVar1,uVar2);
  param_1[0xf] = uVar1;
  return;
}



/* 4096a570 FUN_4096a570 */

/* Boundary evidence: original MIPS .pdata 4096a570..4096a713. Semantic name remains unreviewed. */

void FUN_4096a570(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,undefined4 param_7)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  uint uVar5;
  
  uVar1 = __fpsub(param_3,param_2);
  uVar1 = __fpdiv(0x3f800000,uVar1);
  uVar2 = __fpsub(param_5,param_4);
  uVar2 = __fpdiv(0x3f800000,uVar2);
  uVar3 = __fpsub(param_7,param_6);
  uVar3 = __fpdiv(0x3f800000,uVar3);
  uVar4 = __fpmul(uVar1,0x40000000);
  *param_1 = uVar4;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  uVar4 = __fpmul(uVar2,0x40000000);
  param_1[5] = uVar4;
  param_1[6] = 0;
  param_1[7] = 0;
  param_1[8] = 0;
  param_1[9] = 0;
  uVar4 = __fpmul(uVar3,0xc0000000);
  param_1[10] = uVar4;
  param_1[0xb] = 0;
  uVar4 = __fpadd(param_2,param_3);
  uVar5 = __fpmul(uVar4,uVar1);
  param_1[0xc] = uVar5 ^ 0x80000000;
  uVar1 = __fpadd(param_4,param_5);
  uVar5 = __fpmul(uVar1,uVar2);
  param_1[0xd] = uVar5 ^ 0x80000000;
  uVar1 = __fpadd(param_6,param_7);
  uVar5 = __fpmul(uVar1,uVar3);
  param_1[0xe] = uVar5 ^ 0x80000000;
  param_1[0xf] = 0x3f800000;
  return;
}



/* 4096a714 FUN_4096a714 */

/* Boundary evidence: original MIPS .pdata 4096a714..4096a8e3. Semantic name remains unreviewed. */

void FUN_4096a714(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,undefined4 param_7)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  uint uVar5;
  
  uVar1 = __fpsub(param_3,param_2);
  uVar1 = __fpdiv(0x3f800000,uVar1);
  uVar2 = __fpsub(param_5,param_4);
  uVar2 = __fpdiv(0x3f800000,uVar2);
  uVar3 = __fpsub(param_7,param_6);
  uVar3 = __fpdiv(0x3f800000,uVar3);
  uVar4 = __fpmul(uVar1,param_6);
  uVar4 = __fpmul(uVar4,0x40000000);
  *param_1 = uVar4;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  uVar4 = __fpmul(uVar2,param_6);
  uVar4 = __fpmul(uVar4,0x40000000);
  param_1[5] = uVar4;
  param_1[6] = 0;
  param_1[7] = 0;
  uVar4 = __fpadd(param_2,param_3);
  uVar1 = __fpmul(uVar4,uVar1);
  param_1[8] = uVar1;
  uVar1 = __fpadd(param_4,param_5);
  uVar1 = __fpmul(uVar1,uVar2);
  param_1[9] = uVar1;
  uVar1 = __fpadd(param_6,param_7);
  uVar5 = __fpmul(uVar1,uVar3);
  param_1[10] = uVar5 ^ 0x80000000;
  param_1[0xb] = 0xbf800000;
  param_1[0xc] = 0;
  param_1[0xd] = 0;
  uVar1 = __fpmul(param_6,param_7);
  uVar1 = __fpmul(uVar1,0x40000000);
  uVar5 = __fpmul(uVar1,uVar3);
  param_1[0xe] = uVar5 ^ 0x80000000;
  param_1[0xf] = 0;
  return;
}



/* 4096a92c FUN_4096a92c */

/* Boundary evidence: original MIPS .pdata 4096a92c..4096b007. Semantic name remains unreviewed. */

undefined4 FUN_4096a92c(undefined4 *param_1)

{
  bool bVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  undefined4 *puVar8;
  undefined4 *puVar9;
  int iVar10;
  undefined4 *puVar11;
  undefined4 *puVar12;
  undefined4 uVar13;
  undefined4 *puVar14;
  undefined4 uVar15;
  int iVar16;
  undefined4 *puVar17;
  undefined8 uVar18;
  int local_9c;
  int local_94;
  undefined4 *local_8c;
  int local_84;
  undefined4 local_68 [16];
  
  iVar5 = (int)local_68 - (int)param_1;
  iVar6 = (int)local_68 + (4 - (int)param_1);
  puVar14 = local_68;
  puVar12 = param_1 + 2;
  local_68[0] = 0x3f800000;
  local_68[1] = 0;
  local_68[2] = 0;
  local_68[3] = 0;
  local_68[4] = 0;
  local_68[5] = 0x3f800000;
  local_68[6] = 0;
  local_68[7] = 0;
  local_68[8] = 0;
  local_68[9] = 0;
  local_68[10] = 0x3f800000;
  local_68[0xb] = 0;
  local_68[0xc] = 0;
  local_68[0xd] = 0;
  local_68[0xe] = 0;
  local_68[0xf] = 0x3f800000;
  local_84 = 0;
  local_9c = 4;
  puVar11 = param_1;
  local_8c = param_1;
  do {
    local_8c = local_8c + 4;
    iVar7 = local_84 + 1;
    uVar15 = *puVar11;
    if (iVar7 < 4) {
      puVar17 = param_1 + local_9c + local_84;
      iVar10 = iVar7;
      iVar16 = local_84;
      do {
        uVar13 = *puVar17;
        uVar2 = mali_sys_fabs(uVar13);
        uVar3 = mali_sys_fabs(uVar15);
        iVar4 = __gts(uVar2,uVar3);
        if (iVar4 != 0) {
          uVar15 = uVar13;
          iVar16 = iVar10;
        }
        iVar10 = iVar10 + 1;
        puVar17 = puVar17 + 4;
      } while (iVar10 < 4);
      if (iVar16 != local_84) {
        uVar2 = puVar12[-2];
        puVar17 = param_1 + iVar16 * 4;
        puVar12[-2] = *puVar17;
        *puVar17 = uVar2;
        uVar2 = puVar12[-1];
        puVar12[-1] = puVar17[1];
        puVar17[1] = uVar2;
        uVar2 = *puVar12;
        *puVar12 = param_1[iVar16 * 4 + 2];
        param_1[iVar16 * 4 + 2] = uVar2;
        uVar2 = local_68[iVar16 * 4];
        uVar3 = *puVar14;
        uVar13 = puVar12[1];
        puVar12[1] = param_1[iVar16 * 4 + 3];
        *puVar14 = uVar2;
        local_68[iVar16 * 4] = uVar3;
        uVar2 = local_68[iVar16 * 4 + 1];
        param_1[iVar16 * 4 + 3] = uVar13;
        uVar3 = puVar14[1];
        puVar14[1] = uVar2;
        local_68[iVar16 * 4 + 1] = uVar3;
        uVar2 = *(undefined4 *)((int)puVar12 + iVar5);
        *(undefined4 *)((int)puVar12 + iVar5) = local_68[iVar16 * 4 + 2];
        local_68[iVar16 * 4 + 2] = uVar2;
        uVar2 = *(undefined4 *)((int)puVar12 + iVar6);
        *(undefined4 *)((int)puVar12 + iVar6) = local_68[iVar16 * 4 + 3];
        local_68[iVar16 * 4 + 3] = uVar2;
      }
    }
    uVar2 = mali_sys_fabs(*puVar11);
    uVar18 = __fptodp(uVar2);
    iVar10 = __ged((int)uVar18,(int)((ulonglong)uVar18 >> 0x20),0x9ee75616,0x3cd203af);
    if (iVar10 == 0) {
      return 0xfffffffe;
    }
    uVar15 = __fpdiv(0x3f800000,uVar15);
    uVar2 = __fpmul(*puVar14,uVar15);
    uVar3 = puVar12[-2];
    *puVar14 = uVar2;
    uVar2 = __fpmul(uVar3,uVar15);
    uVar3 = puVar14[1];
    puVar12[-2] = uVar2;
    uVar2 = __fpmul(uVar15,uVar3);
    uVar3 = puVar12[-1];
    puVar14[1] = uVar2;
    uVar2 = __fpmul(uVar3,uVar15);
    uVar3 = *(undefined4 *)((int)puVar12 + iVar5);
    puVar12[-1] = uVar2;
    uVar2 = __fpmul(uVar15,uVar3);
    *(undefined4 *)((int)puVar12 + iVar5) = uVar2;
    uVar2 = __fpmul(*puVar12,uVar15);
    uVar3 = *(undefined4 *)((int)puVar12 + iVar6);
    *puVar12 = uVar2;
    uVar2 = __fpmul(uVar3,uVar15);
    *(undefined4 *)((int)puVar12 + iVar6) = uVar2;
    uVar15 = __fpmul(uVar15,puVar12[1]);
    puVar12[1] = uVar15;
    if (iVar7 < 4) {
      puVar8 = param_1 + local_9c + local_84;
      local_84 = 4 - iVar7;
      puVar17 = local_8c;
      do {
        uVar3 = *puVar8;
        uVar15 = __fpmul(puVar12[-2],uVar3);
        uVar15 = __fpsub(*puVar17,uVar15);
        uVar2 = *puVar14;
        *puVar17 = uVar15;
        uVar15 = __fpmul(uVar2,uVar3);
        uVar15 = __fpsub(*(undefined4 *)((int)puVar17 + iVar5),uVar15);
        uVar2 = puVar12[-1];
        *(undefined4 *)((int)puVar17 + iVar5) = uVar15;
        uVar15 = __fpmul(uVar2,uVar3);
        uVar15 = __fpsub(puVar17[1],uVar15);
        uVar2 = puVar14[1];
        puVar17[1] = uVar15;
        uVar15 = __fpmul(uVar3,uVar2);
        uVar15 = __fpsub(*(undefined4 *)((int)puVar17 + iVar6),uVar15);
        uVar2 = *puVar12;
        *(undefined4 *)((int)puVar17 + iVar6) = uVar15;
        uVar15 = __fpmul(uVar2,uVar3);
        uVar15 = __fpsub(puVar17[2],uVar15);
        uVar2 = *(undefined4 *)((int)puVar12 + iVar5);
        puVar9 = (undefined4 *)((int)puVar17 + (int)local_68 + (8 - (int)param_1));
        puVar17[2] = uVar15;
        uVar15 = __fpmul(uVar3,uVar2);
        uVar15 = __fpsub(*puVar9,uVar15);
        uVar2 = puVar12[1];
        *puVar9 = uVar15;
        uVar15 = __fpmul(uVar3,uVar2);
        uVar15 = __fpsub(puVar17[3],uVar15);
        uVar2 = *(undefined4 *)((int)puVar12 + iVar6);
        puVar9 = (undefined4 *)((int)puVar17 + (int)local_68 + (0xc - (int)param_1));
        puVar17[3] = uVar15;
        uVar15 = __fpmul(uVar2,uVar3);
        uVar15 = __fpsub(*puVar9,uVar15);
        puVar17 = puVar17 + 4;
        puVar8 = puVar8 + 4;
        local_84 = local_84 + -1;
        *puVar9 = uVar15;
      } while (local_84 != 0);
    }
    local_9c = local_9c + 4;
    puVar11 = puVar11 + 5;
    puVar14 = puVar14 + 4;
    puVar12 = puVar12 + 4;
    local_84 = iVar7;
  } while (local_9c < 0x14);
  puVar12 = param_1 + 8;
  iVar7 = (int)local_68 + (8 - (int)param_1);
  iVar10 = (int)local_68 + (0xc - (int)param_1);
  puVar11 = param_1 + 0xc;
  local_8c = (undefined4 *)0x2;
  local_94 = 8;
  do {
    if (-1 < (int)local_8c) {
      puVar8 = param_1 + local_94 + (int)local_8c + 1;
      puVar14 = puVar12;
      puVar17 = local_8c;
      do {
        uVar3 = *puVar8;
        uVar15 = __fpmul(uVar3,*puVar11);
        uVar15 = __fpsub(*puVar14,uVar15);
        uVar2 = *(undefined4 *)((int)puVar11 + iVar5);
        *puVar14 = uVar15;
        uVar15 = __fpmul(uVar2,uVar3);
        uVar15 = __fpsub(*(undefined4 *)((int)puVar14 + iVar5),uVar15);
        uVar2 = puVar11[1];
        *(undefined4 *)((int)puVar14 + iVar5) = uVar15;
        uVar15 = __fpmul(uVar3,uVar2);
        uVar15 = __fpsub(puVar14[1],uVar15);
        uVar2 = *(undefined4 *)((int)puVar11 + iVar6);
        puVar14[1] = uVar15;
        uVar15 = __fpmul(uVar2,uVar3);
        uVar15 = __fpsub(*(undefined4 *)(iVar6 + (int)puVar14),uVar15);
        uVar2 = puVar11[2];
        *(undefined4 *)(iVar6 + (int)puVar14) = uVar15;
        uVar15 = __fpmul(uVar2,uVar3);
        uVar15 = __fpsub(puVar14[2],uVar15);
        uVar2 = *(undefined4 *)((int)puVar11 + iVar7);
        puVar9 = (undefined4 *)(iVar7 + (int)puVar14);
        puVar14[2] = uVar15;
        uVar15 = __fpmul(uVar2,uVar3);
        uVar15 = __fpsub(*puVar9,uVar15);
        uVar2 = puVar11[3];
        *puVar9 = uVar15;
        uVar15 = __fpmul(uVar2,uVar3);
        uVar15 = __fpsub(puVar14[3],uVar15);
        puVar9 = (undefined4 *)(iVar10 + (int)puVar14);
        uVar2 = *(undefined4 *)((int)puVar11 + iVar10);
        puVar14[3] = uVar15;
        uVar15 = __fpmul(uVar2,uVar3);
        uVar15 = __fpsub(*puVar9,uVar15);
        puVar17 = (undefined4 *)((int)puVar17 + -1);
        puVar8 = puVar8 + -4;
        puVar14 = puVar14 + -4;
        *puVar9 = uVar15;
      } while (-1 < (int)puVar17);
    }
    puVar12 = puVar12 + -4;
    local_94 = local_94 + -4;
    puVar11 = puVar11 + -4;
    bVar1 = -1 < (int)local_8c;
    local_8c = (undefined4 *)((int)local_8c + -1);
  } while (bVar1);
  mali_sys_memcpy(param_1,local_68,0x40);
  return 0;
}



/* 4096b008 FUN_4096b008 */

/* Boundary evidence: original MIPS .pdata 4096b008..4096b043. Semantic name remains unreviewed. */

void FUN_4096b008(undefined4 *param_1,undefined4 *param_2)

{
  if (param_1 != param_2) {
    mali_sys_memcpy(param_1,param_2,0x40);
  }
  FUN_4096a92c(param_1);
  return;
}



/* 4096b044 FUN_4096b044 */

/* Boundary evidence: original MIPS .pdata 4096b044..4096b07b. Semantic name remains unreviewed. */

void FUN_4096b044(int param_1)

{
  if (*(int *)(param_1 + 0xbc) != 0) {
    mali_mem_ref_deref();
    *(undefined4 *)(param_1 + 0x68) = 0;
  }
  return;
}



/* 4096b084 FUN_4096b084 */

/* Boundary evidence: original MIPS .pdata 4096b084..4096b09f. Semantic name remains unreviewed. */

void FUN_4096b084(void)

{
  mali_sys_atomic_inc();
  return;
}



/* 4096b0cc FUN_4096b0cc */

/* Boundary evidence: original MIPS .pdata 4096b0cc..4096b0ff. Semantic name remains unreviewed. */

undefined4 FUN_4096b0cc(undefined4 *param_1)

{
  undefined4 uVar1;
  
  if (param_1[1] == 0) {
    uVar1 = mali_mem_mali_addr_get_full(param_1,0);
  }
  else {
    uVar1 = *param_1;
  }
  return uVar1;
}



/* 4096b100 FUN_4096b100 */

/* Boundary evidence: original MIPS .pdata 4096b100..4096b183. Semantic name remains unreviewed. */

void FUN_4096b100(int param_1,uint *param_2,uint param_3)

{
  uint uVar1;
  
  *(uint *)(param_1 + 0x34) = *(uint *)(param_1 + 0x34) & 0xffffffbf;
  *(uint *)(param_1 + 0x24) = *(uint *)(param_1 + 0x24) & 0xffffffe0 ^ param_3;
  if (param_2[1] == 0) {
    uVar1 = mali_mem_mali_addr_get_full(param_2,0);
  }
  else {
    uVar1 = *param_2;
  }
  *(uint *)(param_1 + 0x24) = *(uint *)(param_1 + 0x24) & 0x3f ^ uVar1;
  return;
}



/* 4096b184 FUN_4096b184 */

void FUN_4096b184(int param_1)

{
  *(undefined4 *)(param_1 + 0x10) = 0xffff0000;
  *(undefined2 *)(param_1 + 0x3a) = 0;
  *(uint *)(param_1 + 0x20) = *(uint *)(param_1 + 0x20) & 0xffff0ff8 ^ 0xf007;
  *(uint *)(param_1 + 8) = *(uint *)(param_1 + 8) & 0xf3000000 ^ 0xc321892;
  *(uint *)(param_1 + 0xc) = *(uint *)(param_1 + 0xc) & 0xffffffc1 ^ 0x30;
  *(uint *)(param_1 + 0x34) = *(uint *)(param_1 + 0x34) & 0xf0003d40 ^ 0x200;
  return;
}



/* 4096b1f8 FUN_4096b1f8 */

/* Boundary evidence: original MIPS .pdata 4096b1f8..4096b243. Semantic name remains unreviewed. */

undefined4 FUN_4096b1f8(int param_1)

{
  mali_sys_memset(param_1 + 0x7c,0,0x40);
  FUN_4096b184(param_1 + 0x7c);
  *(undefined4 *)(param_1 + 0xbc) = 0;
  return 0;
}



/* 4096b244 FUN_4096b244 */

/* Boundary evidence: original MIPS .pdata 4096b244..4096b34b. Semantic name remains unreviewed. */

void FUN_4096b244(undefined4 *param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  uint uStack00000010;
  undefined4 uStack00000014;
  undefined4 uStack00000018;
  undefined4 uStack0000001c;
  undefined4 uStack00000020;
  
  FUN_40993370();
  iVar2 = param_1[0x140];
  uStack00000010 = 0x20425;
  uStack00000014 = 0xc;
  uStack00000018 = 0x1e007cf;
  uStack0000001c = 0xb0000000;
  uStack00000020 = 0x5f5;
  uVar3 = param_1[0x13d];
  if (*(int *)(iVar2 + 0xbc) == 0) {
    iVar1 = mali_mem_ref_alloc_mem(*param_1,0x14,0x40,1);
    *(int *)(iVar2 + 0xbc) = iVar1;
    if (iVar1 == 0) goto LAB_4096b344;
    mali_mem_write(*(undefined4 *)(iVar1 + 4),0,&stack0x00000010,0x14);
  }
  iVar1 = mali_frame_builder_add_callback(uVar3,mali_mem_ref_deref,*(undefined4 *)(iVar2 + 0xbc));
  if (iVar1 == 0) {
    FUN_4096b100(iVar2 + 0x7c,*(uint **)(*(int *)(iVar2 + 0xbc) + 4),uStack00000010 & 0x1f);
    mali_sys_atomic_inc(*(undefined4 *)(iVar2 + 0xbc));
    iVar1 = FUN_4099311c((int)param_1,3,0);
    if ((iVar1 == 0) && (iVar1 = FUN_4096d464((int)param_1,iVar2 + 0x7c), iVar1 == 0)) {
      *(undefined4 *)(iVar2 + 0xc) = 0;
      FUN_40967aec(param_1);
    }
  }
LAB_4096b344:
                    /* WARNING: Subroutine does not return */
  FUN_40993390(0x28);
}



/* 4096b34c FUN_4096b34c */

/* Boundary evidence: original MIPS .pdata 4096b34c..4096b367. Semantic name remains unreviewed. */

void FUN_4096b34c(void)

{
  mali_sys_free();
  return;
}



/* 4096b394 FUN_4096b394 */

/* Boundary evidence: original MIPS .pdata 4096b394..4096b3c7. Semantic name remains unreviewed. */

undefined4 FUN_4096b394(undefined4 *param_1)

{
  undefined4 uVar1;
  
  if (param_1[1] == 0) {
    uVar1 = mali_mem_mali_addr_get_full(param_1,0);
  }
  else {
    uVar1 = *param_1;
  }
  return uVar1;
}



/* 4096b3c8 FUN_4096b3c8 */

uint FUN_4096b3c8(uint param_1)

{
  uint uVar1;
  
  uVar1 = 0;
  if ((param_1 & 0x7fff0000) != 0) {
    uVar1 = 0x10;
  }
  if ((param_1 & 0x7f00ff00) != 0) {
    uVar1 = uVar1 | 8;
  }
  if ((param_1 & 0x70f0f0f0) != 0) {
    uVar1 = uVar1 | 4;
  }
  if ((param_1 & 0x3ccccccc) != 0) {
    uVar1 = uVar1 | 2;
  }
  if ((param_1 & 0x2aaaaaaa) != 0) {
    uVar1 = uVar1 | 1;
  }
  return uVar1;
}



/* 4096b4bc FUN_4096b4bc */

/* Boundary evidence: original MIPS .pdata 4096b4bc..4096b6f3. Semantic name remains unreviewed. */

void FUN_4096b4bc(int param_1,undefined4 param_2,uint param_3)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  switch(param_2) {
  case 0:
    *(uint *)(param_1 + 0x28) = *(uint *)(param_1 + 0x28) & 0xfffffff8 ^ param_3;
    uVar1 = *(uint *)(param_1 + 0x68) & 0xfffffff8 ^ 7;
    break;
  case 1:
    *(uint *)(param_1 + 0x28) = *(uint *)(param_1 + 0x28) & 0xffffffc7 ^ param_3 << 3;
    uVar1 = *(uint *)(param_1 + 0x68) & 0xffffffc7 ^ 0x38;
    break;
  case 2:
    *(uint *)(param_1 + 0x28) = *(uint *)(param_1 + 0x28) & 0xfffffe3f ^ param_3 << 6;
    uVar1 = *(uint *)(param_1 + 0x68) & 0xfffffe3f ^ 0x1c0;
    break;
  case 3:
    *(uint *)(param_1 + 0x28) = *(uint *)(param_1 + 0x28) & 0xfffff1ff ^ param_3 << 9;
    uVar1 = *(uint *)(param_1 + 0x68) & 0xfffff1ff ^ 0xe00;
    break;
  case 4:
    *(uint *)(param_1 + 0x28) = *(uint *)(param_1 + 0x28) & 0xffff8fff ^ param_3 << 0xc;
    uVar1 = *(uint *)(param_1 + 0x68) & 0xffff8fff ^ 0x7000;
    break;
  case 5:
    uVar3 = 0xfffc7fff;
    uVar1 = param_3 << 0xf;
    uVar2 = 0x38000;
    goto LAB_4096b5a4;
  case 6:
    uVar3 = 0xffe30000;
    uVar1 = param_3 << 0x12;
    uVar2 = 0x1c0000;
    goto LAB_4096b5a0;
  case 7:
    uVar3 = 0xff1f0000;
    uVar1 = param_3 << 0x15;
    uVar2 = 0xe00000;
    goto LAB_4096b5a0;
  case 8:
    uVar3 = 0xf8ff0000;
    uVar1 = param_3 << 0x18;
    uVar2 = 0x7000000;
    goto LAB_4096b5a0;
  case 9:
    uVar3 = 0xc7ff0000;
    uVar1 = param_3 << 0x1b;
    uVar2 = 0x38000000;
LAB_4096b5a0:
    uVar3 = uVar3 | 0xffff;
LAB_4096b5a4:
    *(uint *)(param_1 + 0x28) = *(uint *)(param_1 + 0x28) & uVar3 ^ uVar1;
    *(uint *)(param_1 + 0x68) = *(uint *)(param_1 + 0x68) & uVar3 ^ uVar2;
    return;
  case 10:
    *(uint *)(param_1 + 0x28) = param_3 << 0x1e ^ *(uint *)(param_1 + 0x28) & 0x3fffffff;
    *(uint *)(param_1 + 0x68) = *(uint *)(param_1 + 0x68) & 0x3fffffff ^ 0xc0000000;
    *(uint *)(param_1 + 0x3c) = (int)param_3 >> 2 ^ *(uint *)(param_1 + 0x3c) & 0xfffffffe;
    uVar1 = *(uint *)(param_1 + 0x7c) & 0xfffffffe ^ 1;
    goto LAB_4096b530;
  case 0xb:
    *(uint *)(param_1 + 0x3c) = *(uint *)(param_1 + 0x3c) & 0xfffffff1 ^ param_3 << 1;
    uVar1 = *(uint *)(param_1 + 0x7c) & 0xfffffff1 ^ 0xe;
LAB_4096b530:
    *(uint *)(param_1 + 0x7c) = uVar1;
  default:
    goto switchD_4096b4e8_default;
  }
  *(uint *)(param_1 + 0x68) = uVar1;
switchD_4096b4e8_default:
  return;
}



/* 4096b6f4 FUN_4096b6f4 */

/* Boundary evidence: original MIPS .pdata 4096b6f4..4096b7ab. Semantic name remains unreviewed. */

void FUN_4096b6f4(int param_1,int param_2)

{
  bool bVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  FUN_40993230();
  iVar5 = *(int *)(param_2 + 0x20);
  iVar6 = 0;
  if (0 < iVar5) {
    iVar4 = 0;
    do {
      iVar3 = *(int *)(param_2 + 0x28) + iVar4;
      bVar1 = *(uint *)(iVar3 + 4) < 3;
      if (*(int *)(iVar3 + 8) == 4) {
        if (bVar1) {
          uVar2 = 1;
        }
        else {
          uVar2 = 0;
        }
      }
      else {
        uVar2 = 2;
        if (bVar1) {
          uVar2 = 3;
        }
      }
      FUN_4096b4bc(param_1,iVar6,uVar2);
      iVar6 = iVar6 + 1;
      iVar4 = iVar4 + 0xc;
    } while (iVar6 < iVar5);
  }
  *(uint *)(param_1 + 0x34) =
       *(uint *)(param_1 + 0x34) & 0xffffffe0 ^ *(uint *)(param_2 + 0x24) >> 3;
                    /* WARNING: Subroutine does not return */
  *(uint *)(param_1 + 0x74) = *(uint *)(param_1 + 0x74) & 0xffffffe0 ^ 0x1f;
  FUN_40993258(0x10);
}



/* 4096b7ac FUN_4096b7ac */

/* Boundary evidence: original MIPS .pdata 4096b7ac..4096bb5b. Semantic name remains unreviewed. */

int FUN_4096b7ac(int param_1)

{
  int iVar1;
  uint uVar2;
  uint *puVar3;
  
  iVar1 = mali_sys_malloc(0x80);
  if (iVar1 == 0) {
    iVar1 = 0;
  }
  else {
    mali_sys_memset(iVar1,0,0x80);
    *(uint *)(iVar1 + 0xc) =
         *(uint *)(iVar1 + 0xc) & 0xfffff7ff ^ (uint)(*(int *)(param_1 + 0x90) != 0) << 0xb;
    *(uint *)(iVar1 + 0x4c) = *(uint *)(iVar1 + 0x4c) & 0xfffff7ff ^ 0x800;
    *(uint *)(iVar1 + 0xc) =
         *(uint *)(iVar1 + 0xc) & 0xffffefff ^ (uint)(*(int *)(param_1 + 0x98) != 0) << 0xc;
    *(uint *)(iVar1 + 0x4c) = *(uint *)(iVar1 + 0x4c) & 0xffffefff ^ 0x1000;
    puVar3 = *(uint **)(*(int *)(param_1 + 0x74) + 4);
    if (puVar3[1] == 0) {
      uVar2 = mali_mem_mali_addr_get_full(puVar3,0);
    }
    else {
      uVar2 = *puVar3;
    }
    *(uint *)(iVar1 + 0x24) = *(uint *)(iVar1 + 0x24) & 0x3f ^ uVar2;
    *(uint *)(iVar1 + 100) = *(uint *)(iVar1 + 100) & 0x3f ^ 0xffffffc0;
    *(uint *)(iVar1 + 0x24) = *(uint *)(iVar1 + 0x24) & 0xffffffe0 ^ *(uint *)(param_1 + 0x80);
    *(uint *)(iVar1 + 100) = *(uint *)(iVar1 + 100) & 0xffffffe0 ^ 0x1f;
    FUN_4096b6f4(iVar1,param_1);
    if (*(int *)(param_1 + 0xb0) == 0) {
      *(undefined2 *)(iVar1 + 0x3a) = 0;
      *(uint *)(iVar1 + 0x78) = *(uint *)(iVar1 + 0x78) & 0xffff ^ 0xffff0000;
      *(uint *)(iVar1 + 0x2c) = *(uint *)(iVar1 + 0x2c) & 0xfffffff0;
      *(uint *)(iVar1 + 0x6c) = *(uint *)(iVar1 + 0x6c) & 0xfffffff0 ^ 0xf;
      *(uint *)(iVar1 + 0x34) = *(uint *)(iVar1 + 0x34) & 0xffffff7f;
      *(uint *)(iVar1 + 0x74) = *(uint *)(iVar1 + 0x74) & 0xffffff7f ^ 0x80;
    }
    else {
      uVar2 = (*(int *)(param_1 + 0xb0) + 3U >> 2) - 1;
      uVar2 = uVar2 >> 1 | uVar2;
      uVar2 = uVar2 >> 2 | uVar2;
      uVar2 = uVar2 >> 4 | uVar2;
      *(uint *)(iVar1 + 0x38) = *(uint *)(iVar1 + 0x38) & 0xffff ^ 0x10000;
      uVar2 = uVar2 >> 8 | uVar2;
      *(uint *)(iVar1 + 0x78) = *(uint *)(iVar1 + 0x78) & 0xffff ^ 0xffff0000;
      uVar2 = FUN_4096b3c8((uVar2 >> 0x10 | uVar2) + 1);
      *(uint *)(iVar1 + 0x2c) = uVar2 ^ *(uint *)(iVar1 + 0x2c) & 0xfffffff0;
      *(uint *)(iVar1 + 0x6c) = *(uint *)(iVar1 + 0x6c) & 0xfffffff0 ^ 0xf;
      *(uint *)(iVar1 + 0x34) = *(uint *)(iVar1 + 0x34) & 0xffffff7f ^ 0x80;
      *(uint *)(iVar1 + 0x74) = *(uint *)(iVar1 + 0x74) & 0xffffff7f ^ 0x80;
    }
    if (*(int *)(param_1 + 0x10) == 0) {
      *(uint *)(iVar1 + 0x34) = *(uint *)(iVar1 + 0x34) & 0xf0003fff;
      *(uint *)(iVar1 + 0x74) = *(uint *)(iVar1 + 0x74) & 0xf0003fff ^ 0xfffc000;
      *(uint *)(iVar1 + 0x30) = *(uint *)(iVar1 + 0x30) & 0xfffffff0;
      *(uint *)(iVar1 + 0x70) = *(uint *)(iVar1 + 0x70) & 0xfffffff0 ^ 0xf;
      *(uint *)(iVar1 + 0x34) = *(uint *)(iVar1 + 0x34) & 0xffffffdf;
      *(uint *)(iVar1 + 0x74) = *(uint *)(iVar1 + 0x74) & 0xffffffdf ^ 0x20;
    }
    else {
      *(uint *)(iVar1 + 0x34) =
           *(uint *)(iVar1 + 0x34) & 0xf0003fff ^ *(int *)(param_1 + 0x10) << 0xe;
      *(uint *)(iVar1 + 0x74) = *(uint *)(iVar1 + 0x74) & 0xf0003fff ^ 0xfffc000;
      *(uint *)(iVar1 + 0x30) = *(uint *)(iVar1 + 0x30) & 0xfffffff0;
      *(uint *)(iVar1 + 0x70) = *(uint *)(iVar1 + 0x70) & 0xfffffff0 ^ 0xf;
      *(uint *)(iVar1 + 0x34) = *(uint *)(iVar1 + 0x34) & 0xffffffdf ^ 0x20;
      *(uint *)(iVar1 + 0x74) = *(uint *)(iVar1 + 0x74) & 0xffffffdf ^ 0x20;
    }
    *(uint *)(iVar1 + 0x34) = *(uint *)(iVar1 + 0x34) & 0xfffffeff;
    *(uint *)(iVar1 + 0x74) = *(uint *)(iVar1 + 0x74) & 0xfffffeff ^ 0x100;
    *(uint *)(iVar1 + 0x34) = *(uint *)(iVar1 + 0x34) & 0xffffffbf;
    *(uint *)(iVar1 + 0x74) = *(uint *)(iVar1 + 0x74) & 0xffffffbf ^ 0x40;
  }
  return iVar1;
}



/* 4096bb5c FUN_4096bb5c */

/* Boundary evidence: original MIPS .pdata 4096bb5c..4096bb8b. Semantic name remains unreviewed. */

int FUN_4096bb5c(void)

{
  int iVar1;
  int iVar2;
  
  iVar1 = __m200_texel_format_get_bpp();
  iVar2 = iVar1 + 7;
  if (iVar2 < 0) {
    iVar2 = iVar1 + 0xe;
  }
  return iVar2 >> 3;
}



/* 4096bb8c FUN_4096bb8c */

/* Boundary evidence: original MIPS .pdata 4096bb8c..4096bba7. Semantic name remains unreviewed. */

void FUN_4096bb8c(int param_1)

{
  mali_sys_atomic_inc(param_1 + 4);
  return;
}



/* 4096bbcc FUN_4096bbcc */

/* Boundary evidence: original MIPS .pdata 4096bbcc..4096be77. Semantic name remains unreviewed. */

void FUN_4096bbcc(undefined4 *param_1,int param_2,int param_3)

{
  uint *puVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  undefined4 *puVar5;
  int iVar6;
  int *piVar7;
  int iVar8;
  undefined4 uVar9;
  undefined4 *puStack00000038;
  
  FUN_40993300();
  iVar6 = 0;
  puStack00000038 = param_1;
  puVar1 = (uint *)FUN_4097a63c(param_2,param_3,0);
  if (((((puVar1 == (uint *)0x0) || (uVar4 = puVar1[1], uVar4 == 0)) ||
       (uVar3 = *puVar1, uVar3 == 0)) ||
      ((puVar1[4] == 0x1403 && ((puVar1[3] == 0x1908 || (puVar1[3] == 0x190a)))))) ||
     ((puVar1[3] == 0x8d64 || (((uVar3 - 1 & uVar3) != 0 || ((uVar4 - 1 & uVar4) != 0))))))
  goto LAB_4096be6c;
  iVar2 = FUN_40979e34(param_3);
  piVar7 = *(int **)(iVar2 * 0x34 + *(int *)(param_2 + 0x34));
  uVar9 = *(undefined4 *)(*piVar7 + 0x2c);
  __m200_texel_format_get_bpp(*(undefined4 *)(*piVar7 + 0x18));
  puVar5 = *(undefined4 **)*piVar7;
  mali_sys_atomic_inc(puVar5 + 1);
  iVar2 = mali_mem_ptr_map_area(*puVar5,*(undefined4 *)(*piVar7 + 4),uVar9,0);
  if (iVar2 == 0) {
LAB_4096bd00:
    mali_shared_mem_ref_owner_deref(puVar5);
  }
  else {
    if (*(int *)(*piVar7 + 0x20) != 0) {
      iVar6 = mali_sys_malloc(uVar9);
      if (iVar6 == 0) {
        mali_mem_ptr_unmap_area(**(undefined4 **)*piVar7);
        goto LAB_4096bd00;
      }
      iVar8 = *(int *)(*piVar7 + 0x20);
      if (iVar8 != 0) {
        FUN_4096fc00(*puVar1,puVar1[1],iVar8);
      }
      iVar2 = m200_texture_swizzle(iVar6,0,iVar2,iVar8);
      mali_mem_ptr_unmap_area(*puVar5);
      mali_shared_mem_ref_owner_deref(puVar5);
      puVar5 = (undefined4 *)0x0;
      if (iVar2 != 0) {
        mali_sys_free(iVar6);
        goto LAB_4096be6c;
      }
    }
    FUN_40975a38(param_2,puStack00000038,param_3);
    if (iVar6 != 0) {
      mali_sys_free(iVar6);
    }
    if (puVar5 != (undefined4 *)0x0) {
      mali_mem_ptr_unmap_area(*puVar5);
      mali_shared_mem_ref_owner_deref(puVar5);
    }
  }
LAB_4096be6c:
                    /* WARNING: Subroutine does not return */
  FUN_40993338(0x40);
}



/* 4096be78 FUN_4096be78 */

/* Boundary evidence: original MIPS .pdata 4096be78..4096bf67. Semantic name remains unreviewed. */

undefined4 FUN_4096be78(undefined4 param_1)

{
  undefined4 uVar1;
  
  switch(param_1) {
  case 0:
    uVar1 = 0x300;
    break;
  case 1:
    uVar1 = 0x306;
    break;
  case 2:
    uVar1 = 0x8001;
    break;
  default:
    uVar1 = 0;
    break;
  case 4:
    uVar1 = 0x308;
    break;
  case 8:
    uVar1 = 0x301;
    break;
  case 9:
    uVar1 = 0x307;
    break;
  case 10:
    uVar1 = 0x8002;
    break;
  case 0xb:
    uVar1 = 1;
    break;
  case 0x10:
    uVar1 = 0x302;
    break;
  case 0x11:
    uVar1 = 0x304;
    break;
  case 0x12:
    uVar1 = 0x8003;
    break;
  case 0x18:
    uVar1 = 0x303;
    break;
  case 0x19:
    uVar1 = 0x305;
    break;
  case 0x1a:
    uVar1 = 0x8004;
  }
  return uVar1;
}



/* 4096bf68 FUN_4096bf68 */

undefined4 FUN_4096bf68(uint param_1)

{
  if (param_1 < 0x306) {
    if (param_1 == 0x305) {
      return 0x19;
    }
    if (param_1 == 0) {
      return 3;
    }
    if (param_1 == 1) {
      return 0xb;
    }
    if (param_1 != 0x300) {
      if (param_1 == 0x301) {
        return 8;
      }
      if (param_1 == 0x302) {
        return 0x10;
      }
      if (param_1 == 0x303) {
        return 0x18;
      }
      if (param_1 == 0x304) {
        return 0x11;
      }
    }
  }
  else {
    if (param_1 == 0x306) {
      return 1;
    }
    if (param_1 == 0x307) {
      return 9;
    }
    if (param_1 == 0x308) {
      return 4;
    }
    if (param_1 == 0x8001) {
      return 2;
    }
    if (param_1 == 0x8002) {
      return 10;
    }
    if (param_1 == 0x8003) {
      return 0x12;
    }
    if (param_1 == 0x8004) {
      return 0x1a;
    }
  }
  return 0;
}



/* 4096c0a0 FUN_4096c0a0 */

/* Boundary evidence: original MIPS .pdata 4096c0a0..4096c123. Semantic name remains unreviewed. */

undefined4 FUN_4096c0a0(undefined4 param_1)

{
  undefined4 uVar1;
  
  switch(param_1) {
  case 0:
    uVar1 = 0x1e00;
    break;
  case 1:
    uVar1 = 0x1e01;
    break;
  default:
    uVar1 = 0;
    break;
  case 3:
    uVar1 = 0x150a;
    break;
  case 4:
    uVar1 = 0x8507;
    break;
  case 5:
    uVar1 = 0x8508;
    break;
  case 6:
    uVar1 = 0x1e02;
    break;
  case 7:
    uVar1 = 0x1e03;
  }
  return uVar1;
}



/* 4096c124 FUN_4096c124 */

undefined4 FUN_4096c124(uint param_1)

{
  if (param_1 < 0x1e03) {
    if (param_1 == 0x1e02) {
      return 6;
    }
    if (param_1 == 0) {
      return 2;
    }
    if (param_1 == 0x150a) {
      return 3;
    }
    if ((param_1 != 0x1e00) && (param_1 == 0x1e01)) {
      return 1;
    }
  }
  else {
    if (param_1 == 0x1e03) {
      return 7;
    }
    if (param_1 == 0x8507) {
      return 4;
    }
    if (param_1 == 0x8508) {
      return 5;
    }
  }
  return 0;
}



/* 4096c1d0 FUN_4096c1d0 */

/* Boundary evidence: original MIPS .pdata 4096c1d0..4096c25b. Semantic name remains unreviewed. */

undefined4 FUN_4096c1d0(undefined4 param_1)

{
  undefined4 uVar1;
  
  switch(param_1) {
  case 0:
    uVar1 = 0x200;
    break;
  case 1:
    uVar1 = 0x201;
    break;
  case 2:
    uVar1 = 0x202;
    break;
  case 3:
    uVar1 = 0x203;
    break;
  case 4:
    uVar1 = 0x204;
    break;
  case 5:
    uVar1 = 0x205;
    break;
  case 6:
    uVar1 = 0x206;
    break;
  case 7:
    uVar1 = 0x207;
    break;
  default:
    uVar1 = 0;
  }
  return uVar1;
}



/* 4096c25c FUN_4096c25c */

/* Boundary evidence: original MIPS .pdata 4096c25c..4096c2df. Semantic name remains unreviewed. */

undefined4 FUN_4096c25c(undefined4 param_1)

{
  undefined4 uVar1;
  
  switch(param_1) {
  default:
    uVar1 = 0;
    break;
  case 0x201:
    uVar1 = 1;
    break;
  case 0x202:
    uVar1 = 2;
    break;
  case 0x203:
    uVar1 = 3;
    break;
  case 0x204:
    uVar1 = 4;
    break;
  case 0x205:
    uVar1 = 5;
    break;
  case 0x206:
    uVar1 = 6;
    break;
  case 0x207:
    uVar1 = 7;
  }
  return uVar1;
}



/* 4096c2e0 FUN_4096c2e0 */

/* Boundary evidence: original MIPS .pdata 4096c2e0..4096c3c7. Semantic name remains unreviewed. */

undefined4 FUN_4096c2e0(undefined4 param_1)

{
  undefined4 uVar1;
  
  switch(param_1) {
  case 0:
    uVar1 = 0x1500;
    break;
  case 1:
    uVar1 = 0x1508;
    break;
  case 2:
    uVar1 = 0x1504;
    break;
  case 3:
    uVar1 = 0x150c;
    break;
  case 4:
    uVar1 = 0x1502;
    break;
  case 5:
    uVar1 = 0x150a;
    break;
  case 6:
    uVar1 = 0x1506;
    break;
  case 7:
    uVar1 = 0x150e;
    break;
  case 8:
    uVar1 = 0x1501;
    break;
  case 9:
    uVar1 = 0x1509;
    break;
  case 10:
    uVar1 = 0x1505;
    break;
  case 0xb:
    uVar1 = 0x150d;
    break;
  case 0xc:
    uVar1 = 0x1503;
    break;
  case 0xd:
    uVar1 = 0x150b;
    break;
  case 0xe:
    uVar1 = 0x1507;
    break;
  case 0xf:
    uVar1 = 0x150f;
    break;
  default:
    uVar1 = 0;
  }
  return uVar1;
}



/* 4096c3c8 FUN_4096c3c8 */

/* Boundary evidence: original MIPS .pdata 4096c3c8..4096c4a7. Semantic name remains unreviewed. */

undefined4 FUN_4096c3c8(undefined4 param_1)

{
  undefined4 uVar1;
  
  switch(param_1) {
  default:
    uVar1 = 0;
    break;
  case 0x1501:
    uVar1 = 8;
    break;
  case 0x1502:
    uVar1 = 4;
    break;
  case 0x1503:
    uVar1 = 0xc;
    break;
  case 0x1504:
    uVar1 = 2;
    break;
  case 0x1505:
    uVar1 = 10;
    break;
  case 0x1506:
    uVar1 = 6;
    break;
  case 0x1507:
    uVar1 = 0xe;
    break;
  case 0x1508:
    uVar1 = 1;
    break;
  case 0x1509:
    uVar1 = 9;
    break;
  case 0x150a:
    uVar1 = 5;
    break;
  case 0x150b:
    uVar1 = 0xd;
    break;
  case 0x150c:
    uVar1 = 3;
    break;
  case 0x150d:
    uVar1 = 0xb;
    break;
  case 0x150e:
    uVar1 = 7;
    break;
  case 0x150f:
    uVar1 = 0xf;
  }
  return uVar1;
}



/* 4096c4a8 FUN_4096c4a8 */

/* Boundary evidence: original MIPS .pdata 4096c4a8..4096c4df. Semantic name remains unreviewed. */

void FUN_4096c4a8(int param_1)

{
  if (*(int *)(param_1 + 0x68) != 0) {
    mali_mem_ref_deref();
    *(undefined4 *)(param_1 + 0x68) = 0;
  }
  return;
}



/* 4096c4e8 FUN_4096c4e8 */

/* Boundary evidence: original MIPS .pdata 4096c4e8..4096c503. Semantic name remains unreviewed. */

void FUN_4096c4e8(void)

{
  mali_sys_atomic_inc();
  return;
}



/* 4096c530 FUN_4096c530 */

/* Boundary evidence: original MIPS .pdata 4096c530..4096c563. Semantic name remains unreviewed. */

undefined4 FUN_4096c530(undefined4 *param_1)

{
  undefined4 uVar1;
  
  if (param_1[1] == 0) {
    uVar1 = mali_mem_mali_addr_get_full(param_1,0);
  }
  else {
    uVar1 = *param_1;
  }
  return uVar1;
}



/* 4096c564 FUN_4096c564 */

/* Boundary evidence: original MIPS .pdata 4096c564..4096c64b. Semantic name remains unreviewed. */

void FUN_4096c564(uint *param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  
  FUN_409933b0();
  uVar1 = __fpmul(*param_2,0x437f0000);
  uVar1 = __fpadd(uVar1,0x3f000000);
  uVar2 = __fptoul(uVar1);
  uVar2 = param_1[1] & 0xffff0000 ^ uVar2;
  param_1[1] = uVar2;
  uVar1 = __fpmul(param_2[1],0x437f0000);
  uVar1 = __fpadd(uVar1,0x3f000000);
  iVar3 = __fptoul(uVar1);
  uVar5 = *param_1 & 0xffff ^ iVar3 << 0x10;
  *param_1 = uVar5;
  uVar1 = __fpmul(param_2[2],0x437f0000);
  uVar1 = __fpadd(uVar1,0x3f000000);
  uVar4 = __fptoul(uVar1);
  *param_1 = uVar5 & 0xffff0000 ^ uVar4;
  uVar1 = __fpmul(param_2[3],0x437f0000);
  uVar1 = __fpadd(uVar1,0x3f000000);
  iVar3 = __fptoul(uVar1);
  param_1[1] = uVar2 & 0xffff ^ iVar3 << 0x10;
                    /* WARNING: Subroutine does not return */
  FUN_409933e0(0x10);
}



/* 4096c64c FUN_4096c64c */

void FUN_4096c64c(int param_1,uint param_2,int param_3)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  if ((param_2 & 0x4000) == 0) {
    *(uint *)(param_1 + 8) = *(uint *)(param_1 + 8) & 0xfffffff;
  }
  else {
    uVar2 = *(uint *)(param_1 + 8) & 0xefffffff ^ (uint)*(byte *)(param_3 + 0x454) << 0x1c;
    *(uint *)(param_1 + 8) = uVar2;
    uVar2 = uVar2 & 0xdfffffff ^ (uint)*(byte *)(param_3 + 0x455) << 0x1d;
    *(uint *)(param_1 + 8) = uVar2;
    uVar2 = uVar2 & 0xbfffffff ^ (uint)*(byte *)(param_3 + 0x456) << 0x1e;
    *(uint *)(param_1 + 8) = uVar2;
    *(uint *)(param_1 + 8) = uVar2 & 0x7fffffff ^ (uint)*(byte *)(param_3 + 0x457) << 0x1f;
  }
  uVar2 = *(uint *)(param_1 + 0xc) & 0xfffffff1 ^ 0xe;
  *(uint *)(param_1 + 0xc) = uVar2;
  if ((param_2 & 0x100) == 0) {
    *(uint *)(param_1 + 0xc) = uVar2 & 0xfffffffe;
  }
  else {
    *(uint *)(param_1 + 0xc) = uVar2 & 0xfffffffe ^ 1;
  }
  uVar2 = *(uint *)(param_1 + 0x14) & 0xfffffff8 ^ 7;
  *(uint *)(param_1 + 0x14) = uVar2;
  uVar3 = *(uint *)(param_1 + 0x18) & 0xfffffff8 ^ 7;
  uVar2 = uVar2 & 0xfffff1ff;
  uVar1 = uVar3 & 0xfffff1ff;
  *(uint *)(param_1 + 0x18) = uVar3;
  if ((param_2 & 0x400) == 0) {
    *(uint *)(param_1 + 0x14) = uVar2;
    *(uint *)(param_1 + 0x18) = uVar1;
  }
  else {
    uVar2 = uVar2 ^ 0x200;
    uVar1 = uVar1 ^ 0x200;
    *(uint *)(param_1 + 0x14) = uVar2;
    *(uint *)(param_1 + 0x18) = uVar1;
    uVar3 = *(uint *)(param_1 + 0x1c) & 0xffffff00 ^ *(uint *)(param_3 + 0x45c);
    *(uint *)(param_1 + 0x1c) = uVar3;
    *(uint *)(param_1 + 0x1c) = uVar3 & 0xffff00ff ^ *(int *)(param_3 + 0x45c) << 8;
    *(uint *)(param_1 + 0x14) = uVar2 & 0xff00ffff ^ (*(uint *)(param_3 + 0x474) & 0xff) << 0x10;
    *(uint *)(param_1 + 0x18) = uVar1 & 0xff00ffff ^ (*(uint *)(param_3 + 0x474) & 0xff) << 0x10;
  }
  return;
}



/* 4096c810 FUN_4096c810 */

/* Boundary evidence: original MIPS .pdata 4096c810..4096c893. Semantic name remains unreviewed. */

void FUN_4096c810(int param_1,uint *param_2)

{
  uint uVar1;
  
  *(uint *)(param_1 + 0x34) = *(uint *)(param_1 + 0x34) & 0xffffffbf;
  *(uint *)(param_1 + 0x24) = *(uint *)(param_1 + 0x24) & 0xffffffe0 ^ 5;
  if (param_2[1] == 0) {
    uVar1 = mali_mem_mali_addr_get_full(param_2,0);
  }
  else {
    uVar1 = *param_2;
  }
  *(uint *)(param_1 + 0x24) = *(uint *)(param_1 + 0x24) & 0x3f ^ uVar1;
  return;
}



/* 4096c904 FUN_4096c904 */

/* Boundary evidence: original MIPS .pdata 4096c904..4096c9b3. Semantic name remains unreviewed. */

undefined4 FUN_4096c904(int param_1)

{
  mali_sys_memset(param_1 + 0x28,0,0x40);
  *(undefined4 *)(param_1 + 0x38) = 0xffff0000;
  *(uint *)(param_1 + 0x5c) = *(uint *)(param_1 + 0x5c) & 0xf0003f40;
  *(uint *)(param_1 + 0x34) = *(uint *)(param_1 + 0x34) & 0xffffffcf ^ 0x30;
  *(undefined2 *)(param_1 + 0x62) = 0;
  *(uint *)(param_1 + 0x48) = *(uint *)(param_1 + 0x48) & 0xffff0ff8 ^ 0xf007;
  *(uint *)(param_1 + 0x30) = *(uint *)(param_1 + 0x30) & 0xf3000000 ^ 0xc321892;
  *(undefined4 *)(param_1 + 0x68) = 0;
  return 0;
}



/* 4096c9b4 FUN_4096c9b4 */

/* Boundary evidence: original MIPS .pdata 4096c9b4..4096cb07. Semantic name remains unreviewed. */

void FUN_4096c9b4(undefined4 *param_1,uint param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  
  FUN_40993230();
  iVar3 = param_1[0x140];
  uVar4 = param_1[0x13d];
  if ((*(int *)(iVar3 + 0x68) == 0) ||
     (iVar1 = mali_sys_memcmp(iVar3 + 0x6c,param_1 + 0x118,0x10), iVar1 != 0)) {
    if (*(int *)(iVar3 + 0x68) != 0) {
      mali_mem_ref_deref();
      *(undefined4 *)(iVar3 + 0x68) = 0;
    }
    iVar1 = mali_mem_ref_alloc_mem(*param_1,0x78,0x40,1);
    *(int *)(iVar3 + 0x68) = iVar1;
    if (iVar1 == 0) goto LAB_4096cb00;
    FUN_4096c564((uint *)(iVar3 + 0x28),param_1 + 0x118);
    mali_mem_write(*(undefined4 *)(*(int *)(iVar3 + 0x68) + 4),0,&DAT_409621a0,0x14);
    *(undefined4 *)(iVar3 + 0x6c) = param_1[0x118];
    *(undefined4 *)(iVar3 + 0x70) = param_1[0x119];
    *(undefined4 *)(iVar3 + 0x74) = param_1[0x11a];
    *(undefined4 *)(iVar3 + 0x78) = param_1[0x11b];
  }
  iVar1 = mali_frame_builder_add_callback(uVar4,mali_mem_ref_deref,*(undefined4 *)(iVar3 + 0x68));
  if (iVar1 == 0) {
    iVar2 = iVar3 + 0x28;
    FUN_4096c810(iVar2,*(uint **)(*(int *)(iVar3 + 0x68) + 4));
    mali_sys_atomic_inc(*(undefined4 *)(iVar3 + 0x68));
    FUN_4096c64c(iVar2,param_2,(int)param_1);
    iVar1 = FUN_4099311c((int)param_1,3,0);
    if ((iVar1 == 0) && (iVar1 = FUN_4096d464((int)param_1,iVar2), iVar1 == 0)) {
      *(undefined4 *)(iVar3 + 0xc) = 0;
      FUN_40967aec(param_1);
    }
  }
LAB_4096cb00:
                    /* WARNING: Subroutine does not return */
  FUN_40993258(0x10);
}



/* 4096cb08 FUN_4096cb08 */

/* Boundary evidence: original MIPS .pdata 4096cb08..4096cb23. Semantic name remains unreviewed. */

void FUN_4096cb08(void)

{
  mali_sys_atomic_inc();
  return;
}



/* 4096cb24 FUN_4096cb24 */

/* Boundary evidence: original MIPS .pdata 4096cb24..4096cb6b. Semantic name remains unreviewed. */

undefined4 FUN_4096cb24(undefined4 param_1,int param_2)

{
  mali_sys_atomic_inc(*(undefined4 *)(param_2 + 0x74));
  mali_frame_builder_update_fragment_stack
            (param_1,*(undefined4 *)(param_2 + 0xa8),*(undefined4 *)(param_2 + 0xa4));
  return 0;
}



/* 4096cc48 FUN_4096cc48 */

void FUN_4096cc48(int param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  
  iVar3 = *(int *)(param_1 + 0x504);
  uVar1 = (uint)*(byte *)(iVar3 + 0x65);
  uVar2 = (uint)*(byte *)(iVar3 + 0x66);
  if (((*(uint *)(iVar3 + 0x40) & 0x80) == 0) || (param_2 == 0)) {
    uVar1 = 0;
    uVar2 = 0;
  }
  *(uint *)(iVar3 + 0xc) = uVar1 << 0x10 ^ *(uint *)(iVar3 + 0xc) & 0xffff ^ uVar2 << 0x18;
  return;
}



/* 4096ccbc FUN_4096ccbc */

undefined4 FUN_4096ccbc(int param_1,int param_2)

{
  undefined4 uVar1;
  
  if (((((*(uint *)(param_1 + 0x20) & 0xf000) != 0xf000) ||
       ((*(uint *)(param_1 + 8) & 0xf0000000) != 0xf0000000)) ||
      ((*(uint *)(param_1 + 0x20) & 7) != 7)) ||
     ((((*(uint *)(param_1 + 0x34) & 0x200) != 0 || (*(int *)(param_2 + 8) != 0)) ||
      (((*(uint *)(param_1 + 0x34) & 0x400) != 0 ||
       (uVar1 = 1, (*(uint *)(param_1 + 0x38) & 0x4000) != 0)))))) {
    uVar1 = 0;
  }
  return uVar1;
}



/* 4096cd7c FUN_4096cd7c */

/* Boundary evidence: original MIPS .pdata 4096cd7c..4096ce33. Semantic name remains unreviewed. */

void FUN_4096cd7c(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  iVar1 = *(int *)(param_1 + 0x4d4);
  if (*(int *)(iVar1 + 0x9c) == 0) {
    iVar2 = 0;
    if ((*(uint *)(*(int *)(param_1 + 0x504) + 0x40) & 1) == 0) {
      iVar2 = 1;
    }
  }
  else {
    iVar2 = 0;
  }
  uVar3 = *(uint *)(param_2 + 0x34) & 0xfffffdff ^ iVar2 << 9;
  *(uint *)(param_2 + 0x34) = uVar3;
  if ((*(uint *)(*(int *)(param_1 + 0x504) + 0x40) & 4) == 0) {
    iVar1 = FUN_4096ccbc(param_2,iVar1 + 0x7c);
  }
  else {
    iVar1 = 0;
  }
  *(uint *)(param_2 + 0x34) = (iVar1 << 0xc ^ uVar3) & 0xffffedff;
  return;
}



/* 4096ce34 FUN_4096ce34 */

void FUN_4096ce34(int param_1,int param_2,int param_3)

{
  bool bVar1;
  bool bVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  
  iVar6 = *(int *)(param_1 + 0x504);
  iVar5 = 1;
  if ((*(int *)(param_1 + 0x484) != 0) || (bVar1 = true, *(int *)(param_1 + 0x4b0) < 1)) {
    bVar1 = false;
  }
  if (((*(uint *)(iVar6 + 0x40) & 0x20) == 0) || (bVar2 = true, !bVar1)) {
    bVar2 = false;
  }
  if (((param_2 == 0) || ((*(uint *)(iVar6 + 0x40) & 0x200) == 0)) &&
     ((param_3 == 0 || ((*(uint *)(iVar6 + 0x40) & 0x100) == 0)))) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  if ((bVar2) || (iVar3 = 0, bVar1)) {
    iVar3 = 1;
  }
  uVar4 = iVar3 << 3 ^ *(uint *)(iVar6 + 0x20) & 0xfffffff7;
  *(uint *)(iVar6 + 0x20) = uVar4;
  if ((!bVar2) || (iVar3 = 1, (*(uint *)(iVar6 + 0x40) & 0x400) == 0)) {
    iVar3 = 0;
  }
  uVar4 = uVar4 & 0xffffff7f ^ iVar3 << 7;
  *(uint *)(iVar6 + 0x20) = uVar4;
  if ((!bVar2) || ((*(uint *)(iVar6 + 0x40) & 0x800) == 0)) {
    iVar5 = 0;
  }
  *(uint *)(iVar6 + 0x20) = uVar4 & 0xfffffeff ^ iVar5 << 8;
  return;
}



/* 4096cf40 FUN_4096cf40 */

/* Boundary evidence: original MIPS .pdata 4096cf40..4096d087. Semantic name remains unreviewed. */

void FUN_4096cf40(int param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  int local_38 [8];
  
  local_38[4] = 2;
  local_38[5] = 2;
  iVar1 = 1;
  local_38[6] = 2;
  local_38[0] = 0;
  local_38[1] = 1;
  local_38[2] = 1;
  local_38[3] = 1;
  *(uint *)(param_3 + 0x20) = local_38[param_4] << 10 ^ *(uint *)(param_3 + 0x20) & 0xfffff3ff;
  FUN_4096cc48(param_1,*(uint *)(param_1 + 0xc) >> 0x1b & 1);
  FUN_4096ce34(param_1,*(uint *)(param_1 + 0xc) >> 0x1d & 1,*(uint *)(param_1 + 0xc) >> 0x1c & 1);
  if (*(int *)(param_1 + 0x490) == 0) {
    if (*(int *)(param_1 + 1000) != 0x901) goto LAB_4096d01c;
  }
  else if (*(int *)(param_1 + 1000) == 0x901) goto LAB_4096d01c;
  iVar1 = 0;
LAB_4096d01c:
  *(uint *)(param_3 + 0x38) = *(uint *)(param_3 + 0x38) & 0xffffefff ^ iVar1 << 0xc;
  *(uint *)(param_3 + 0x30) = *(uint *)(param_3 + 0x30) & 0xf ^ *(uint *)(param_2 + 0x14);
  *(uint *)(param_3 + 0x2c) = *(uint *)(param_3 + 0x2c) & 0xf ^ *(uint *)(param_2 + 0x20);
  FUN_4096cd7c(param_1,param_3);
  return;
}



/* 4096d088 FUN_4096d088 */

/* Boundary evidence: original MIPS .pdata 4096d088..4096d0db. Semantic name remains unreviewed. */

void FUN_4096d088(undefined4 *param_1)

{
  *param_1 = 0;
  param_1[1] = 0;
  if (param_1[0x1a] != 0) {
    mali_mem_ref_deref();
    param_1[0x1a] = 0;
  }
  if (param_1[0x2f] != 0) {
    mali_mem_ref_deref();
    param_1[0x1a] = 0;
  }
  return;
}



/* 4096d150 FUN_4096d150 */

/* Boundary evidence: original MIPS .pdata 4096d150..4096d17f. Semantic name remains unreviewed. */

void FUN_4096d150(undefined4 *param_1)

{
  FUN_4096d088(param_1);
  mali_sys_free(param_1);
  return;
}



/* 4096d180 FUN_4096d180 */

/* Boundary evidence: original MIPS .pdata 4096d180..4096d1d7. Semantic name remains unreviewed. */

void FUN_4096d180(undefined4 *param_1)

{
  int iVar1;
  
  mali_sys_memset(param_1,0,0xc0);
  *param_1 = 0;
  param_1[1] = 0;
  param_1[5] = 0;
  param_1[8] = 0;
  iVar1 = FUN_4096b1f8((int)param_1);
  if (iVar1 == 0) {
    FUN_4096c904((int)param_1);
  }
  return;
}



/* 4096d23c FUN_4096d23c */

/* Boundary evidence: original MIPS .pdata 4096d23c..4096d293. Semantic name remains unreviewed. */

undefined4 * FUN_4096d23c(void)

{
  undefined4 *puVar1;
  int iVar2;
  
  puVar1 = (undefined4 *)mali_sys_malloc(0xc0);
  if (puVar1 != (undefined4 *)0x0) {
    iVar2 = FUN_4096d180(puVar1);
    if (iVar2 == 0) {
      return puVar1;
    }
    FUN_4096d088(puVar1);
    mali_sys_free(puVar1);
  }
  return (undefined4 *)0x0;
}



/* 4096d294 FUN_4096d294 */

void FUN_4096d294(int param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = 1;
  if ((((*(char *)(param_1 + 0x454) != '\0') || (*(char *)(param_1 + 0x455) != '\0')) ||
      (*(char *)(param_1 + 0x456) != '\0')) || (uVar1 = 0, *(char *)(param_1 + 0x457) != '\0')) {
    uVar1 = 1;
  }
  *(uint *)(param_1 + 0x4c4) = *(uint *)(param_1 + 0x4c4) | uVar1;
  if ((*(char *)(param_1 + 0x458) == '\0') ||
     (uVar1 = 1, (*(uint *)(*(int *)(param_1 + 0x504) + 0x40) & 2) == 0)) {
    uVar1 = 0;
  }
  *(uint *)(param_1 + 0x4c8) = *(uint *)(param_1 + 0x4c8) | uVar1;
  if ((*(int *)(param_1 + 0x45c) == 0) ||
     ((*(uint *)(*(int *)(param_1 + 0x504) + 0x40) & 0x10) == 0)) {
    uVar2 = 0;
  }
  *(uint *)(param_1 + 0x4cc) = *(uint *)(param_1 + 0x4cc) | uVar2;
  return;
}



/* 4096d338 FUN_4096d338 */

uint FUN_4096d338(uint param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar2 = (int)param_1 >> 0x17 & 0xff;
  if ((uVar2 == 0xff) && ((param_1 & 0x7fffff) != 0)) {
    uVar1 = 0xffff;
  }
  else {
    uVar4 = (param_1 & 0x7fffff | 0x800000) >> 0xd;
    uVar3 = uVar2 - 0x70;
    uVar1 = (uint)((param_1 & 0x80000000) != 0) << 0xf;
    if (0x7ff < uVar4) {
      uVar4 = 0;
      uVar3 = uVar2 - 0x6f;
    }
    if ((int)uVar3 < 0x20) {
      if (-1 < (int)uVar3) {
        uVar1 = uVar4 & 0xfbff | (uVar3 & 0x3f) << 10 | uVar1;
      }
    }
    else {
      uVar1 = uVar1 | 0x7c00;
    }
  }
  return uVar1;
}



/* 4096d3e4 FUN_4096d3e4 */

/* Boundary evidence: original MIPS .pdata 4096d3e4..4096d463. Semantic name remains unreviewed. */

void FUN_4096d3e4(int param_1,int param_2,int param_3,uint param_4)

{
  int iVar1;
  uint uVar2;
  uint *puVar3;
  
  if (-1 < param_3) {
    puVar3 = (uint *)(*(int *)(param_1 + 0xac) + param_3 * 4);
    iVar1 = __nes(*puVar3,param_4);
    if (iVar1 != 0) {
      *puVar3 = param_4;
      uVar2 = FUN_4096d338(param_4);
      *(short *)(*(int *)(param_2 + 0x17c) + param_3 * 2) = (short)uVar2;
    }
  }
  return;
}



/* 4096d464 FUN_4096d464 */

/* Boundary evidence: original MIPS .pdata 4096d464..4096d4ef. Semantic name remains unreviewed. */

undefined4 FUN_4096d464(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 *puVar4;
  int *piVar5;
  
  puVar4 = *(undefined4 **)(param_1 + 0x500);
  piVar5 = puVar4 + 2;
  iVar1 = FUN_40974b50(*(undefined4 **)(param_1 + 0x510),0x40,piVar5);
  if (iVar1 == 0) {
    uVar2 = 0xffffffff;
  }
  else {
    mali_sys_memcpy(iVar1,param_2,0x40);
    iVar1 = *piVar5;
    iVar3 = *(int *)(param_1 + 0x4fc);
    uVar2 = 0;
    *(undefined4 *)(iVar3 + 0x48) = *puVar4;
    *(int *)(iVar3 + 0x44) = iVar1;
  }
  return uVar2;
}



/* 4096d4f0 FUN_4096d4f0 */

/* Boundary evidence: original MIPS .pdata 4096d4f0..4096d6a7. Semantic name remains unreviewed. */

void FUN_4096d4f0(int param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  undefined4 uVar4;
  int iVar5;
  
  FUN_40993300();
  iVar5 = *(int *)(param_2 + 0x168);
  uVar4 = 1;
  uVar3 = 0x3f800000;
  if (iVar5 != -1) {
    uVar2 = 0;
    if ((*(uint *)(param_1 + 0xc) & 0x4000000) != 0) {
      uVar2 = 2;
    }
    uVar1 = __litofp(1 << (uVar2 >> 1));
    uVar2 = __fpdiv(0x3f800000,uVar1);
    FUN_4096d3e4(param_3,param_2,iVar5,uVar2);
    FUN_4096d3e4(param_3,param_2,*(int *)(param_2 + 0x168) + 1,uVar2);
    FUN_4096d3e4(param_3,param_2,*(int *)(param_2 + 0x168) + 2,0x3f800000);
  }
  iVar5 = *(int *)(param_2 + 0x14c);
  if (iVar5 != -1) {
    if (*(int *)(param_1 + 0x490) == 0) {
      FUN_4096d3e4(param_3,param_2,iVar5,0x3f800000);
      FUN_4096d3e4(param_3,param_2,iVar5 + 1,0xbf800000);
      FUN_4096d3e4(param_3,param_2,iVar5 + 2,0);
      uVar2 = 0x3f800000;
    }
    else {
      FUN_4096d3e4(param_3,param_2,iVar5,0x3f800000);
      FUN_4096d3e4(param_3,param_2,iVar5 + 1,0x3f800000);
      FUN_4096d3e4(param_3,param_2,iVar5 + 2,0);
      uVar2 = 0;
    }
    FUN_4096d3e4(param_3,param_2,iVar5 + 3,uVar2);
  }
  if (*(int *)(param_2 + 0x148) != -1) {
    if (*(int *)(param_1 + 0x490) != 0) {
      uVar4 = 0xffffffff;
    }
    if ((*(uint *)(param_1 + 0xc) & 0x4000000) != 0) {
      uVar3 = 0x40000000;
    }
    FUN_4096d3e4(param_3,param_2,*(int *)(param_2 + 0x148),uVar3);
    uVar4 = __litofp(uVar4);
    uVar3 = __fpmul(uVar4,uVar3);
    FUN_4096d3e4(param_3,param_2,*(int *)(param_2 + 0x148) + 1,uVar3);
  }
                    /* WARNING: Subroutine does not return */
  FUN_40993338(0x10);
}



/* 4096d6a8 FUN_4096d6a8 */

/* Boundary evidence: original MIPS .pdata 4096d6a8..4096d723. Semantic name remains unreviewed. */

void FUN_4096d6a8(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  FUN_40993370();
  iVar2 = *(int *)(param_1 + 0x4d4);
  iVar3 = *(int *)(param_1 + 0x500);
  iVar1 = FUN_4099311c(param_1,param_2,*(int *)(iVar2 + 0x24));
  if (iVar1 == 0) {
    iVar1 = *(int *)(param_1 + 0x504);
    if ((*(uint *)(iVar2 + 0x24) & 0xfffffff8) == 0) {
      *(uint *)(iVar1 + 0x3c) = *(uint *)(iVar1 + 0x3c) & 0xf;
    }
    else {
      *(uint *)(iVar1 + 0x3c) = *(uint *)(iVar1 + 0x3c) & 0xf ^ *(uint *)(iVar3 + 4);
    }
    FUN_4096d464(param_1,*(undefined4 *)(param_1 + 0x504));
  }
                    /* WARNING: Subroutine does not return */
  FUN_40993390(0x10);
}



/* 4096d724 FUN_4096d724 */

/* Boundary evidence: original MIPS .pdata 4096d724..4096d8d3. Semantic name remains unreviewed. */

void FUN_4096d724(undefined4 *param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  uint uVar2;
  uint *puVar3;
  uint *puVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  int iVar8;
  uint *puVar9;
  
  FUN_409933b0();
  uVar7 = param_1[0x13d];
  iVar6 = param_1[0x135];
  iVar8 = param_1[0x140];
  puVar9 = (uint *)param_1[0x141];
  iVar1 = mali_frame_builder_incremental_rendering_requested(uVar7);
  if ((iVar1 != 1) || (iVar1 = FUN_409931b4(param_1,uVar7), iVar1 == 0)) {
    iVar1 = *(int *)(iVar6 + 0x174);
    iVar5 = 0xf;
    puVar4 = puVar9;
    do {
      puVar3 = (uint *)((iVar1 - (int)puVar9) + (int)puVar4);
      prefetch(puVar3 + 0x11,0);
      *puVar4 = *puVar3 | ~puVar3[0x10] & *puVar4;
      iVar5 = iVar5 + -1;
      prefetch(puVar4 + 2,0);
      puVar4 = puVar4 + 1;
    } while (-1 < iVar5);
    iVar1 = FUN_4096e330(param_1,iVar8,uVar7,(int)(param_1 + 3));
    if (iVar1 == 0) {
      if (*(int *)(iVar6 + 0x16c) != 0) {
        FUN_4096d3e4(iVar6,iVar6,*(int *)(iVar6 + 0x15c),param_1[0x105]);
        FUN_4096d3e4(iVar6,iVar6,*(int *)(iVar6 + 0x160),param_1[0x106]);
        uVar2 = __fpsub(param_1[0x106],param_1[0x105]);
        FUN_4096d3e4(iVar6,iVar6,*(int *)(iVar6 + 0x164),uVar2);
      }
      if (*(int *)(iVar6 + 0x170) != 0) {
        FUN_4096d4f0((int)param_1,iVar6,iVar6);
      }
      iVar1 = FUN_4096d98c((undefined4 *)param_1[0x144],iVar8,uVar7,iVar6);
      if (iVar1 == 0) {
        *(undefined4 *)(iVar6 + 0xb4) = 0;
        iVar1 = mali_frame_builder_add_callback
                          (uVar7,mali_mem_ref_deref,*(undefined4 *)(iVar6 + 0x74));
        if (iVar1 == 0) {
          mali_sys_atomic_inc(*(undefined4 *)(iVar6 + 0x74));
          mali_frame_builder_update_fragment_stack
                    (uVar7,*(undefined4 *)(iVar6 + 0xa8),*(undefined4 *)(iVar6 + 0xa4));
          *(undefined4 *)(iVar8 + 0xc) = param_2;
          FUN_4096cf40((int)param_1,iVar8,(int)puVar9,param_4);
          FUN_4096d294((int)param_1);
        }
      }
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_409933e0(0x18);
}



/* 4096d8dc FUN_4096d8dc */

uint FUN_4096d8dc(uint param_1)

{
  uint uVar1;
  
  uVar1 = 0;
  if ((param_1 & 0x7fff0000) != 0) {
    uVar1 = 0x10;
  }
  if ((param_1 & 0x7f00ff00) != 0) {
    uVar1 = uVar1 | 8;
  }
  if ((param_1 & 0x70f0f0f0) != 0) {
    uVar1 = uVar1 | 4;
  }
  if ((param_1 & 0x3ccccccc) != 0) {
    uVar1 = uVar1 | 2;
  }
  if ((param_1 & 0x2aaaaaaa) != 0) {
    uVar1 = uVar1 | 1;
  }
  return uVar1;
}



/* 4096d98c FUN_4096d98c */

/* Boundary evidence: original MIPS .pdata 4096d98c..4096da8b. Semantic name remains unreviewed. */

undefined4 FUN_4096d98c(undefined4 *param_1,int param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  int *piVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int local_28 [2];
  
  iVar5 = *(int *)(param_4 + 0xb0);
  local_28[0] = 0;
  if (iVar5 == 0) {
    *(undefined4 *)(param_2 + 0x20) = 0;
    *(undefined4 *)(param_2 + 0x24) = 0;
  }
  else {
    uVar4 = iVar5 + 3U >> 2;
    uVar3 = uVar4 - 1;
    uVar3 = uVar3 >> 1 | uVar3;
    uVar3 = uVar3 >> 2 | uVar3;
    uVar3 = uVar3 >> 4 | uVar3;
    uVar3 = uVar3 >> 8 | uVar3;
    iVar1 = FUN_40974b50(param_1,uVar4 << 3,local_28);
    piVar2 = (int *)FUN_40974b50(param_1,4,(int *)(param_2 + 0x20));
    if ((iVar1 == 0) || (piVar2 == (int *)0x0)) {
      return 0xffffffff;
    }
    *piVar2 = local_28[0];
    mali_sys_memcpy(iVar1,*(undefined4 *)(param_4 + 0x17c),iVar5 << 1);
    uVar3 = FUN_4096d8dc((uVar3 >> 0x10 | uVar3) + 1);
    *(uint *)(param_2 + 0x24) = uVar3;
  }
  return 0;
}



/* 4096da8c FUN_4096da8c */

/* Boundary evidence: original MIPS .pdata 4096da8c..4096db6b. Semantic name remains unreviewed. */

int FUN_4096da8c(int param_1,int param_2,undefined4 param_3,undefined4 param_4,int param_5)

{
  int iVar1;
  int iVar2;
  
  if (param_5 == 0) {
    iVar1 = __m200_texel_format_get_bpp(param_4);
    iVar1 = iVar1 * param_1 * param_2;
  }
  else if (param_5 == 1) {
    if (param_1 <= param_2) {
      param_1 = param_2;
    }
    iVar1 = __m200_texel_format_get_bpp(param_4);
    iVar1 = iVar1 * param_1 * param_1;
  }
  else {
    if ((param_5 == 2) || (param_5 != 3)) {
      return 0;
    }
    iVar1 = __m200_texel_format_get_bpp(param_4);
    iVar1 = iVar1 * (param_1 + 0xfU & 0xfffffff0) * (param_2 + 0xfU & 0xfffffff0);
  }
  iVar2 = iVar1 + 7;
  if (iVar2 < 0) {
    iVar2 = iVar1 + 0xe;
  }
  return iVar2 >> 3;
}



/* 4096db80 FUN_4096db80 */

/* Boundary evidence: original MIPS .pdata 4096db80..4096dbef. Semantic name remains unreviewed. */

int FUN_4096db80(int param_1)

{
  int iVar1;
  
  iVar1 = mali_sys_atomic_dec_and_return(param_1 + 0x34);
  if (iVar1 == 0) {
    if (*(code **)(param_1 + 0x40) != (code *)0x0) {
      if (*(int *)(param_1 + 0x48) == 0) {
        *(int *)(param_1 + 0x48) = param_1;
      }
      (**(code **)(param_1 + 0x40))(*(undefined4 *)(param_1 + 0x48),*(undefined4 *)(param_1 + 0x44))
      ;
    }
    mali_surface_free(param_1);
  }
  return iVar1;
}



/* 4096dbf0 FUN_4096dbf0 */

/* Boundary evidence: original MIPS .pdata 4096dbf0..4096dc2b. Semantic name remains unreviewed. */

undefined4 * FUN_4096dbf0(void)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)mali_sys_malloc(0x10);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    puVar1[3] = 0;
    *puVar1 = 0;
    puVar1[1] = 0;
    puVar1[2] = 0;
  }
  return puVar1;
}



/* 4096dc2c FUN_4096dc2c */

/* Boundary evidence: original MIPS .pdata 4096dc2c..4096dc7b. Semantic name remains unreviewed. */

void FUN_4096dc2c(int *param_1)

{
  if (*param_1 != 0) {
    FUN_4096db80(*param_1);
    *param_1 = 0;
  }
  if (param_1[1] != 0) {
    FUN_4096db80(param_1[1]);
    param_1[1] = 0;
  }
  return;
}



/* 4096dc7c FUN_4096dc7c */

/* Boundary evidence: original MIPS .pdata 4096dc7c..4096dcab. Semantic name remains unreviewed. */

void FUN_4096dc7c(int *param_1)

{
  FUN_4096dc2c(param_1);
  mali_sys_free(param_1);
  return;
}



/* 4096dcac FUN_4096dcac */

/* Boundary evidence: original MIPS .pdata 4096dcac..4096dd27. Semantic name remains unreviewed. */

void FUN_4096dcac(undefined4 param_1,undefined4 *param_2)

{
  int *piVar1;
  int iVar2;
  
  FUN_40993370();
  piVar1 = (int *)mali_sys_malloc(0x10);
  if (piVar1 != (int *)0x0) {
    piVar1[3] = 0;
    *piVar1 = 0;
    piVar1[1] = 0;
    piVar1[2] = 0;
    iVar2 = mali_surface_alloc_surface(*param_2,1,param_1);
    *piVar1 = iVar2;
    if (iVar2 == 0) {
      FUN_4096dc2c(piVar1);
      mali_sys_free(piVar1);
    }
    else {
      piVar1[3] = param_2[3];
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_40993390(0x10);
}



/* 4096dd28 FUN_4096dd28 */

undefined4 FUN_4096dd28(int param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  
  piVar4 = (int *)(*(int *)(param_2 + 0xc) + param_3 * 0x10);
  iVar2 = piVar4[3];
  if ((iVar2 < 0) || (7 < iVar2)) {
    uVar1 = 0;
  }
  else {
    iVar5 = *(int *)(*piVar4 + 4);
    iVar3 = -1;
    if (iVar5 == 5) {
      iVar3 = 0;
    }
    else if (iVar5 == 6) {
      iVar3 = 1;
    }
    uVar1 = *(undefined4 *)((iVar3 + 1) * 4 + (iVar2 + 0x28) * 0x14 + param_1);
  }
  return uVar1;
}



/* 4096dda8 FUN_4096dda8 */

/* Boundary evidence: original MIPS .pdata 4096dda8..4096ddfb. Semantic name remains unreviewed. */

void FUN_4096dda8(uint *param_1)

{
  mali_sys_memset(param_1,0,0x40);
  *param_1 = *param_1 | 0x3f;
  param_1[1] = param_1[1] & 0xfffff7ff | 0x400;
  return;
}



/* 4096ddfc FUN_4096ddfc */

/* Boundary evidence: original MIPS .pdata 4096ddfc..4096de17. Semantic name remains unreviewed. */

void FUN_4096ddfc(int param_1)

{
  mali_sys_atomic_inc(param_1 + 0x188);
  return;
}



/* 4096de18 FUN_4096de18 */

/* Boundary evidence: original MIPS .pdata 4096de18..4096de47. Semantic name remains unreviewed. */

void FUN_4096de18(int param_1)

{
  mali_sys_atomic_inc(param_1 + 4);
  mali_sys_atomic_inc(param_1 + 8);
  return;
}



/* 4096de48 FUN_4096de48 */

/* Boundary evidence: original MIPS .pdata 4096de48..4096de63. Semantic name remains unreviewed. */

void FUN_4096de48(void)

{
  mali_sys_atomic_inc();
  return;
}



/* 4096de64 FUN_4096de64 */

/* Boundary evidence: original MIPS .pdata 4096de64..4096de97. Semantic name remains unreviewed. */

undefined4 FUN_4096de64(undefined4 *param_1)

{
  undefined4 uVar1;
  
  if (param_1[1] == 0) {
    uVar1 = mali_mem_mali_addr_get_full(param_1,0);
  }
  else {
    uVar1 = *param_1;
  }
  return uVar1;
}



/* 4096de98 FUN_4096de98 */

/* Boundary evidence: original MIPS .pdata 4096de98..4096df57. Semantic name remains unreviewed. */

void FUN_4096de98(uint *param_1,uint param_2)

{
  FUN_4096dda8(param_1);
  param_1[3] = param_1[3] & 0xe0010008 | 0x10008;
  param_1[1] = param_1[1] & 0xf000047f | 0x400;
  param_1[2] = param_1[2] & 0x3ff9ff | 0x400000;
  param_1[6] = param_1[6] & 0x3fff9fff | (param_2 >> 6) << 0x1e;
  param_1[7] = param_1[7] & 0xff000000 | param_2 >> 8;
  return;
}



/* 4096df58 FUN_4096df58 */

/* Boundary evidence: original MIPS .pdata 4096df58..4096df9f. Semantic name remains unreviewed. */

undefined4 FUN_4096df58(int *param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  if ((((int *)param_1[7] == (int *)0x0) || (*(int *)param_1[7] == 0)) ||
     (iVar1 = FUN_4097a3e0(param_1), iVar1 == 0)) {
    uVar2 = 0;
  }
  else {
    uVar2 = 1;
  }
  return uVar2;
}



/* 4096dfa0 FUN_4096dfa0 */

/* Boundary evidence: original MIPS .pdata 4096dfa0..4096e14b. Semantic name remains unreviewed. */

int FUN_4096dfa0(undefined4 *param_1,undefined4 param_2,int *param_3,undefined4 *param_4)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  undefined4 *puVar4;
  uint *puVar5;
  uint auStack_58 [16];
  
  if (*(int *)(param_3[0xd] + 0x178) != 0) {
    mali_mem_ref_deref();
    *(undefined4 *)(param_3[0xd] + 0x178) = 0;
  }
  iVar1 = FUN_4096df58(param_3);
  if (iVar1 == 0) {
    uVar2 = mali_mem_ref_alloc_mem(*param_1,0x40,0x40,1);
    *(undefined4 *)(param_3[0xd] + 0x178) = uVar2;
    if (*(int *)(param_3[0xd] + 0x178) == 0) {
      return -1;
    }
    puVar5 = *(uint **)(*(int *)(param_3[0xd] + 0x178) + 4);
    if (puVar5[1] == 0) {
      uVar3 = mali_mem_mali_addr_get_full(puVar5,0);
    }
    else {
      uVar3 = *puVar5;
    }
    FUN_4096de98(auStack_58,uVar3);
    mali_mem_write(*(undefined4 *)(*(int *)(param_3[0xd] + 0x178) + 4),0,auStack_58,0x40);
  }
  else if (*(int *)(param_3[0xd] + 0x184) == 1) {
    uVar2 = mali_mem_ref_alloc_mem(*param_1,0x40,0x40,1);
    *(undefined4 *)(param_3[0xd] + 0x178) = uVar2;
    if (*(int *)(param_3[0xd] + 0x178) == 0) {
      return -1;
    }
    iVar1 = FUN_4096ed8c(*param_1,param_3);
    if (iVar1 != 0) {
      return iVar1;
    }
    mali_mem_write(*(undefined4 *)(*(int *)(param_3[0xd] + 0x178) + 4),0,param_2,0x40);
    puVar4 = *(undefined4 **)(*(int *)(param_3[0xd] + 0x178) + 4);
    if (puVar4[1] == 0) {
      uVar2 = mali_mem_mali_addr_get_full(puVar4,0);
    }
    else {
      uVar2 = *puVar4;
    }
    *param_4 = uVar2;
  }
  return 0;
}



/* 4096e14c FUN_4096e14c */

/* Boundary evidence: original MIPS .pdata 4096e14c..4096e32f. Semantic name remains unreviewed. */

void FUN_4096e14c(undefined4 *param_1,undefined4 param_2,int param_3,int param_4,uint param_5)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint *puVar4;
  int *piVar5;
  int *in_stack_00000090;
  
  FUN_40993300();
  if (in_stack_00000090 == (int *)0x0) {
    iVar1 = FUN_40974b50((undefined4 *)param_1[0x144],0x40,(int *)&param_5);
    uVar3 = param_5;
    if (iVar1 == 0) goto LAB_4096e328;
    FUN_4096de98((uint *)&stack0x00000018,param_5);
    mali_sys_memcpy(iVar1,&stack0x00000018,0x40);
  }
  else {
    iVar1 = mali_frame_builder_add_callback(param_2,FUN_40970e4c,in_stack_00000090[0xd]);
    if (iVar1 != 0) goto LAB_4096e328;
    mali_sys_atomic_inc(in_stack_00000090[0xd] + 0x188);
    iVar1 = 0;
    if (0 < in_stack_00000090[0x15]) {
      piVar5 = in_stack_00000090 + 0x16;
      do {
        iVar2 = mali_frame_builder_add_callback(param_2,&LAB_409634dc,*(undefined4 *)*piVar5);
        if (iVar2 != 0) goto LAB_4096e328;
        iVar2 = *(int *)*piVar5;
        mali_sys_atomic_inc(iVar2 + 4);
        mali_sys_atomic_inc(iVar2 + 8);
        iVar1 = iVar1 + 1;
        piVar5 = piVar5 + 1;
      } while (iVar1 < in_stack_00000090[0x15]);
    }
    if ((in_stack_00000090[0xe] != 0) || (*(int *)(in_stack_00000090[0xd] + 0x184) != 0)) {
      iVar1 = FUN_4096dfa0(param_1,in_stack_00000090[0xd] + 0x138,in_stack_00000090,&param_5);
      if (iVar1 != 0) goto LAB_4096e328;
      in_stack_00000090[0xe] = 0;
    }
    if (*(int *)(in_stack_00000090[0xd] + 0x178) == 0) {
      iVar1 = FUN_40974b50((undefined4 *)param_1[0x144],0x40,(int *)&param_5);
      if (iVar1 == 0) goto LAB_4096e328;
      mali_sys_memcpy(iVar1,in_stack_00000090[0xd] + 0x138,0x40);
      uVar3 = param_5;
    }
    else {
      iVar1 = mali_frame_builder_add_callback(param_2,mali_mem_ref_deref);
      if (iVar1 != 0) goto LAB_4096e328;
      mali_sys_atomic_inc(*(undefined4 *)(in_stack_00000090[0xd] + 0x178));
      puVar4 = *(uint **)(*(int *)(in_stack_00000090[0xd] + 0x178) + 4);
      if (puVar4[1] == 0) {
        uVar3 = mali_mem_mali_addr_get_full(puVar4,0);
      }
      else {
        uVar3 = *puVar4;
      }
    }
  }
  *(uint *)(param_4 * 4 + param_3) = uVar3;
LAB_4096e328:
                    /* WARNING: Subroutine does not return */
  FUN_40993338(0x58);
}



/* 4096e330 FUN_4096e330 */

/* Boundary evidence: original MIPS .pdata 4096e330..4096e413. Semantic name remains unreviewed. */

void FUN_4096e330(undefined4 *param_1,int param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  char *pcVar5;
  int iVar6;
  int iVar7;
  undefined4 uStack00000018;
  int in_stack_0000001c;
  int in_stack_00000058;
  
  FUN_40993300();
  iVar4 = *(int *)(in_stack_00000058 + 0x10);
  uStack00000018 = param_3;
  if (iVar4 == 0) {
    *(undefined4 *)(param_2 + 0x14) = 0;
    *(undefined4 *)(param_2 + 0x1c) = 0;
  }
  else {
    iVar1 = FUN_40974b50((undefined4 *)param_1[0x144],iVar4,&stack0x0000001c);
    if (iVar1 == 0) goto LAB_4096e40c;
    iVar6 = 0;
    if (0 < iVar4) {
      iVar7 = 0;
      pcVar5 = (char *)(param_4 + 800);
      do {
        if (*pcVar5 != '\0') {
          uVar2 = FUN_4096dd28(param_4,in_stack_00000058,iVar6);
          iVar3 = FUN_4096e14c(param_1,uStack00000018,iVar1,
                               *(int *)(*(int *)(in_stack_00000058 + 0xc) + iVar7 + 4),uVar2);
          if (iVar3 != 0) goto LAB_4096e40c;
        }
        iVar6 = iVar6 + 1;
        pcVar5 = pcVar5 + 0x14;
        iVar7 = iVar7 + 0x10;
      } while (iVar6 < iVar4);
    }
    *(int *)(param_2 + 0x14) = in_stack_0000001c;
    *(int *)(param_2 + 0x1c) = iVar4;
  }
  *(undefined4 *)(param_2 + 0x18) = 0;
LAB_4096e40c:
                    /* WARNING: Subroutine does not return */
  FUN_40993338(0x20);
}



/* 4096e498 FUN_4096e498 */

/* Boundary evidence: original MIPS .pdata 4096e498..4096e4b3. Semantic name remains unreviewed. */

void FUN_4096e498(int param_1)

{
  mali_sys_atomic_inc(param_1 + 4);
  return;
}



/* 4096e4b4 FUN_4096e4b4 */

/* Boundary evidence: original MIPS .pdata 4096e4b4..4096e4e3. Semantic name remains unreviewed. */

int FUN_4096e4b4(void)

{
  int iVar1;
  int iVar2;
  
  iVar1 = __m200_texel_format_get_bpp();
  iVar2 = iVar1 + 7;
  if (iVar2 < 0) {
    iVar2 = iVar1 + 0xe;
  }
  return iVar2 >> 3;
}



/* 4096e4e4 FUN_4096e4e4 */

/* Boundary evidence: original MIPS .pdata 4096e4e4..4096e51b. Semantic name remains unreviewed. */

int FUN_4096e4e4(int *param_1,int param_2)

{
  int iVar1;
  
  if (param_1[1] == 0) {
    iVar1 = mali_mem_mali_addr_get_full();
  }
  else {
    iVar1 = *param_1 + param_2;
  }
  return iVar1;
}



/* 4096e51c FUN_4096e51c */

uint FUN_4096e51c(uint param_1)

{
  uint uVar1;
  
  uVar1 = 0;
  if ((param_1 & 0x7fff0000) != 0) {
    uVar1 = 0x10;
  }
  if ((param_1 & 0x7f00ff00) != 0) {
    uVar1 = uVar1 | 8;
  }
  if ((param_1 & 0x70f0f0f0) != 0) {
    uVar1 = uVar1 | 4;
  }
  if ((param_1 & 0x3ccccccc) != 0) {
    uVar1 = uVar1 | 2;
  }
  if ((param_1 & 0x2aaaaaaa) != 0) {
    uVar1 = uVar1 | 1;
  }
  return uVar1;
}



/* 4096e5cc FUN_4096e5cc */

/* Boundary evidence: original MIPS .pdata 4096e5cc..4096e737. Semantic name remains unreviewed. */

void FUN_4096e5cc(int param_1)

{
  uint uVar1;
  int *piVar2;
  int iVar3;
  
  if ((*(int *)(param_1 + 0xc) == 0x2600) && (*(int *)(param_1 + 0x10) == 0x2601)) {
    *(uint *)(*(int *)(param_1 + 0x34) + 0x13c) =
         *(uint *)(*(int *)(param_1 + 0x34) + 0x13c) & 0xfffffff | 0x80000000;
    *(uint *)(*(int *)(param_1 + 0x34) + 0x140) =
         *(uint *)(*(int *)(param_1 + 0x34) + 0x140) & 0xffffffe0;
  }
  else {
    *(uint *)(*(int *)(param_1 + 0x34) + 0x13c) =
         *(uint *)(*(int *)(param_1 + 0x34) + 0x13c) & 0xfffffff;
    *(uint *)(*(int *)(param_1 + 0x34) + 0x140) =
         *(uint *)(*(int *)(param_1 + 0x34) + 0x140) & 0xffffffe0;
  }
  if ((*(int *)(param_1 + 0xc) == 0x2600) || (*(int *)(param_1 + 0xc) == 0x2601)) {
    *(uint *)(*(int *)(param_1 + 0x34) + 0x13c) =
         *(uint *)(*(int *)(param_1 + 0x34) + 0x13c) & 0xf00fffff;
  }
  else {
    piVar2 = *(int **)(param_1 + 0x1c);
    if ((piVar2 != (int *)0x0) && ((uint *)*piVar2 != (uint *)0x0)) {
      if (((int *)*piVar2)[1] < *(int *)*piVar2) {
        uVar1 = *(uint *)*piVar2;
      }
      else {
        uVar1 = *(uint *)(*piVar2 + 4);
      }
      iVar3 = *(int *)(param_1 + 0x34);
      uVar1 = uVar1 >> 1 | uVar1;
      uVar1 = uVar1 >> 2 | uVar1;
      uVar1 = uVar1 >> 4 | uVar1;
      uVar1 = uVar1 >> 8 | uVar1;
      uVar1 = FUN_4096e51c(((uVar1 >> 0x10 | uVar1) >> 1) + 1);
      *(uint *)(iVar3 + 0x13c) = uVar1 << 0x18 | *(uint *)(iVar3 + 0x13c) & 0xf00fffff;
    }
  }
  return;
}



/* 4096e738 FUN_4096e738 */

/* Boundary evidence: original MIPS .pdata 4096e738..4096e95b. Semantic name remains unreviewed. */

void FUN_4096e738(undefined4 *param_1,undefined4 param_2,int *param_3,int param_4)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int iStack0000002c;
  int in_stack_00000068;
  undefined4 in_stack_0000006c;
  int in_stack_00000070;
  
  FUN_40993300();
  uVar3 = *(undefined4 *)(*param_3 + 4);
  mali_surface_access_lock();
  iVar1 = FUN_4096da8c(param_4,in_stack_00000068,in_stack_0000006c,*(undefined4 *)(*param_3 + 0x18),
                       *(int *)(*param_3 + 0x20));
  iStack0000002c = mali_mem_ptr_map_area(**(undefined4 **)*param_3,uVar3,iVar1,1);
  if (iStack0000002c == 0) {
    mali_surface_access_unlock(*param_3);
  }
  else {
    iVar1 = FUN_4096da8c(param_4,in_stack_00000068,in_stack_0000006c,
                         *(undefined4 *)(*param_3 + 0x18),in_stack_00000070);
    iVar1 = mali_mem_ptr_map_area(*param_1,param_2,iVar1,1);
    if (iVar1 == 0) {
      mali_mem_ptr_unmap_area(**(undefined4 **)*param_3);
    }
    else {
      iVar4 = *param_3;
      iVar2 = *(int *)(iVar4 + 0x20);
      if (iVar2 != 0) {
        FUN_4096fc00(param_4,in_stack_00000068,iVar2);
      }
      __m200_texel_format_get_bpp(*(undefined4 *)(iVar4 + 0x18));
      if (in_stack_00000070 != 0) {
        FUN_4096fc00(param_4,in_stack_00000068,in_stack_00000070);
      }
      __m200_texel_format_get_bpp(*(undefined4 *)(*param_3 + 0x18));
      iVar1 = m200_texture_swizzle
                        (iVar1,in_stack_00000070,iStack0000002c,*(undefined4 *)(*param_3 + 0x20));
      mali_mem_ptr_unmap_area(**(undefined4 **)*param_3);
      mali_mem_ptr_unmap_area(*param_1);
      if (iVar1 == 0) {
        mali_sys_atomic_inc(param_1 + 1);
        mali_shared_mem_ref_owner_deref(*(undefined4 *)*param_3);
        *(undefined4 *)*param_3 = 0;
        *(undefined4 **)*param_3 = param_1;
        *(undefined4 *)(*param_3 + 4) = param_2;
      }
    }
    mali_surface_access_unlock(*param_3);
  }
                    /* WARNING: Subroutine does not return */
  FUN_40993338(0x30);
}



/* 4096e95c FUN_4096e95c */

/* Boundary evidence: original MIPS .pdata 4096e95c..4096ed8b. Semantic name remains unreviewed. */

void FUN_4096e95c(int param_1,int param_2)

{
  uint uVar1;
  undefined4 *puVar2;
  int *piVar3;
  uint *puVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  
  puVar2 = *(undefined4 **)(param_2 * 4 + *(int *)(param_1 + 0x34));
  if (puVar2 != (undefined4 *)0x0) {
    puVar2 = (undefined4 *)*puVar2;
    piVar3 = *(int **)*puVar2;
    if (piVar3[1] == 0) {
      uVar1 = mali_mem_mali_addr_get_full(piVar3,puVar2[1]);
    }
    else {
      uVar1 = *piVar3 + puVar2[1];
    }
    uVar9 = uVar1 >> 6;
    switch(param_2) {
    case 0:
      puVar4 = (uint *)**(int **)(param_1 + 0x1c);
      uVar5 = *puVar4;
      uVar7 = puVar4[1];
      uVar8 = puVar4[2];
      *(uint *)(*(int *)(param_1 + 0x34) + 0x140) =
           *(uint *)(*(int *)(param_1 + 0x34) + 0x140) & 0x3fffff | uVar5 << 0x16;
      *(uint *)(*(int *)(param_1 + 0x34) + 0x144) =
           uVar5 >> 10 | *(uint *)(*(int *)(param_1 + 0x34) + 0x144) & 0xfffffff8;
      *(uint *)(*(int *)(param_1 + 0x34) + 0x144) =
           uVar7 << 3 | *(uint *)(*(int *)(param_1 + 0x34) + 0x144) & 0xffff0007;
      *(uint *)(*(int *)(param_1 + 0x34) + 0x144) =
           *(uint *)(*(int *)(param_1 + 0x34) + 0x144) & 0xe000ffff | uVar8 << 0x10;
      FUN_4096e5cc(param_1);
      *(uint *)(*(int *)(param_1 + 0x34) + 0x138) =
           *(uint *)(*(int *)(param_1 + 0x34) + 0x138) & 0xffffffc0 | puVar2[6];
      iVar6 = *(int *)(param_1 + 0x34);
      *(uint *)(iVar6 + 0x138) =
           *(int *)(iVar6 + 0x17c) << 7 | *(uint *)(iVar6 + 0x138) & 0xffffff7f;
      iVar6 = *(int *)(param_1 + 0x34);
      *(uint *)(iVar6 + 0x138) =
           *(int *)(iVar6 + 0x180) << 6 | *(uint *)(iVar6 + 0x138) & 0xffffffbf;
      *(uint *)(*(int *)(param_1 + 0x34) + 0x150) =
           puVar2[8] << 0xd | *(uint *)(*(int *)(param_1 + 0x34) + 0x150) & 0xffff9fff;
      *(uint *)(*(int *)(param_1 + 0x34) + 0x150) =
           uVar9 << 0x1e | *(uint *)(*(int *)(param_1 + 0x34) + 0x150) & 0x3fffffff;
      *(uint *)(*(int *)(param_1 + 0x34) + 0x154) =
           *(uint *)(*(int *)(param_1 + 0x34) + 0x154) & 0xff000000 | uVar1 >> 8;
      break;
    case 1:
      *(char *)(*(int *)(param_1 + 0x34) + 0x157) = (char)uVar9;
      *(uint *)(*(int *)(param_1 + 0x34) + 0x158) =
           *(uint *)(*(int *)(param_1 + 0x34) + 0x158) & 0xfffc0000 | uVar1 >> 0xe;
      break;
    case 2:
      *(uint *)(*(int *)(param_1 + 0x34) + 0x158) =
           *(uint *)(*(int *)(param_1 + 0x34) + 0x158) & 0x3ffff | uVar9 << 0x12;
      *(uint *)(*(int *)(param_1 + 0x34) + 0x15c) =
           *(uint *)(*(int *)(param_1 + 0x34) + 0x15c) & 0xfffff000 | uVar1 >> 0x14;
      break;
    case 3:
      *(uint *)(*(int *)(param_1 + 0x34) + 0x15c) =
           *(uint *)(*(int *)(param_1 + 0x34) + 0x15c) & 0xfff | uVar9 << 0xc;
      *(uint *)(*(int *)(param_1 + 0x34) + 0x160) =
           *(uint *)(*(int *)(param_1 + 0x34) + 0x160) & 0xffffffc0 | uVar1 >> 0x1a;
      break;
    case 4:
      *(uint *)(*(int *)(param_1 + 0x34) + 0x160) =
           *(uint *)(*(int *)(param_1 + 0x34) + 0x160) & 0x3f | uVar9 << 6;
      break;
    case 5:
      *(uint *)(*(int *)(param_1 + 0x34) + 0x164) =
           *(uint *)(*(int *)(param_1 + 0x34) + 0x164) & 0xfc000000 | uVar9;
      break;
    case 6:
      *(uint *)(*(int *)(param_1 + 0x34) + 0x164) =
           *(uint *)(*(int *)(param_1 + 0x34) + 0x164) & 0x3ffffff | uVar9 << 0x1a;
      *(uint *)(*(int *)(param_1 + 0x34) + 0x168) =
           uVar1 >> 0xc | *(uint *)(*(int *)(param_1 + 0x34) + 0x168) & 0xfff00000;
      break;
    case 7:
      *(uint *)(*(int *)(param_1 + 0x34) + 0x168) =
           uVar9 << 0x14 | *(uint *)(*(int *)(param_1 + 0x34) + 0x168) & 0xfffff;
      *(uint *)(*(int *)(param_1 + 0x34) + 0x16c) =
           uVar1 >> 0x12 | *(uint *)(*(int *)(param_1 + 0x34) + 0x16c) & 0xffffc000;
      break;
    case 8:
      *(uint *)(*(int *)(param_1 + 0x34) + 0x16c) =
           uVar9 << 0xe | *(uint *)(*(int *)(param_1 + 0x34) + 0x16c) & 0x3fff;
      *(uint *)(*(int *)(param_1 + 0x34) + 0x170) =
           *(uint *)(*(int *)(param_1 + 0x34) + 0x170) & 0xffffff00 | uVar1 >> 0x18;
      break;
    case 9:
      *(uint *)(*(int *)(param_1 + 0x34) + 0x170) =
           *(uint *)(*(int *)(param_1 + 0x34) + 0x170) & 0xff | uVar9 << 8;
      *(uint *)(*(int *)(param_1 + 0x34) + 0x174) =
           *(uint *)(*(int *)(param_1 + 0x34) + 0x174) & 0xfffffffc | uVar1 >> 0x1e;
      break;
    case 10:
      *(uint *)(*(int *)(param_1 + 0x34) + 0x174) =
           *(uint *)(*(int *)(param_1 + 0x34) + 0x174) & 0xf0000003 | uVar9 << 2;
    }
  }
  return;
}



/* 4096ed8c FUN_4096ed8c */

/* Boundary evidence: original MIPS .pdata 4096ed8c..4096f167. Semantic name remains unreviewed. */

void FUN_4096ed8c(undefined4 param_1,int *param_2)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  int *piVar6;
  int iVar7;
  uint *puVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  undefined4 *puVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  int iVar16;
  int iStack00000020;
  int iStack00000028;
  int iStack00000030;
  undefined4 uStack0000003c;
  
  FUN_40993300();
  puVar12 = (undefined4 *)0x0;
  uStack0000003c = param_1;
  iVar1 = FUN_4097a3e0(param_2);
  if (iVar1 != 0) {
    if (((uint)param_2[3] < 0x2600) || (0x2601 < (uint)param_2[3])) {
      piVar6 = *(int **)param_2[7];
      if (piVar6[1] < *piVar6) {
        puVar8 = *(uint **)param_2[7];
        uVar4 = *puVar8;
      }
      else {
        puVar8 = *(uint **)param_2[7];
        uVar4 = puVar8[1];
      }
      uVar5 = puVar8[2];
      if ((int)uVar5 < (int)uVar4) {
        if ((*(int **)param_2[7])[1] < **(int **)param_2[7]) {
          uVar5 = *puVar8;
        }
        else {
          uVar5 = puVar8[1];
        }
      }
      uVar5 = uVar5 >> 1 | uVar5;
      uVar5 = uVar5 >> 2 | uVar5;
      uVar5 = uVar5 >> 4 | uVar5;
      uVar5 = uVar5 >> 8 | uVar5;
      uVar4 = FUN_4096e51c(((uVar5 >> 0x10 | uVar5) >> 1) + 1);
      iVar1 = uVar4 + 1;
    }
    else {
      iVar1 = 1;
    }
    if (((int *)param_2[7] == (int *)0x0) || (*(int *)param_2[7] == 0)) {
      *(undefined4 *)(param_2[0xd] + 0x184) = 0;
      goto LAB_4096f15c;
    }
    iVar11 = *(int *)(**(int **)param_2[0xd] + 0x20);
    iVar9 = *param_2;
    if (iVar9 != 1) {
      iVar16 = 0x400;
      iVar15 = 1;
    }
    else {
      iVar16 = 0x3000;
      iVar15 = 6;
    }
    if ((9 < iVar1) &&
       (puVar12 = (undefined4 *)
                  mali_shared_mem_ref_alloc_mem(param_1,(iVar1 + -9) * iVar16,0x40,0x33),
       puVar12 == (undefined4 *)0x0)) goto LAB_4096f15c;
    iVar13 = 0;
    if (0 < iVar1) {
      iStack00000028 = iVar16 * -10;
      iVar14 = 0;
      do {
        iStack00000020 = 0;
        if (((iVar15 != 1) || (9 < iVar13)) ||
           (iVar11 != *(int *)(**(int **)(iVar14 + param_2[0xd]) + 0x20))) {
          piVar6 = *(int **)(iVar14 + param_2[7]);
          if (iVar9 != 1) {
            iVar10 = *(int *)(**(int **)(iVar14 + param_2[0xd]) + 0x2c);
          }
          else {
            iVar7 = *piVar6;
            iVar10 = iVar7 + 0xf;
            if (iVar10 < 0) {
              iVar10 = iVar7 + 0x1e;
            }
            iVar7 = (iVar10 >> 4) * 0x10;
            iVar10 = __m200_texel_format_get_bpp(*(undefined4 *)(**(int **)param_2[0xd] + 0x18));
            iVar7 = iVar10 * iVar7 * iVar7;
            iVar10 = iVar7 + 7;
            if (iVar10 < 0) {
              iVar10 = iVar7 + 0xe;
            }
            iVar10 = iVar10 >> 3;
          }
          if (iVar13 < 10) {
            puVar2 = (undefined4 *)
                     mali_shared_mem_ref_alloc_mem(uStack0000003c,iVar10 * iVar15,0x40,0x33);
            if (puVar2 == (undefined4 *)0x0) {
              if (puVar12 != (undefined4 *)0x0) {
                mali_shared_mem_ref_owner_deref(puVar12);
              }
              goto LAB_4096f15c;
            }
          }
          else {
            mali_sys_atomic_inc(puVar12 + 1);
            iStack00000020 = iStack00000028;
            puVar2 = puVar12;
          }
          iStack00000030 = 0;
          iVar7 = iVar14;
          if (iVar15 != 0) {
            do {
              iVar3 = FUN_4096e738(puVar2,iStack00000020,*(int **)(iVar7 + param_2[0xd]),*piVar6);
              if (iVar3 != 0) {
                mali_shared_mem_ref_owner_deref(puVar2);
                if (puVar12 != (undefined4 *)0x0) {
                  mali_shared_mem_ref_owner_deref(puVar12);
                }
                goto LAB_4096f15c;
              }
              iStack00000020 = iVar10 + iStack00000020;
              iStack00000030 = iStack00000030 + 1;
              iVar7 = iVar7 + 0x34;
            } while (iStack00000030 < iVar15);
          }
          FUN_4096e95c((int)param_2,iVar13);
          mali_shared_mem_ref_owner_deref(puVar2);
        }
        iVar13 = iVar13 + 1;
        iStack00000028 = iStack00000028 + iVar16;
        iVar14 = iVar14 + 4;
      } while (iVar13 < iVar1);
    }
    if (puVar12 != (undefined4 *)0x0) {
      mali_shared_mem_ref_owner_deref(puVar12);
    }
  }
  *(undefined4 *)(param_2[0xd] + 0x184) = 0;
LAB_4096f15c:
                    /* WARNING: Subroutine does not return */
  FUN_40993338(0x48);
}



/* 4096f168 FUN_4096f168 */

/* Boundary evidence: original MIPS .pdata 4096f168..4096f227. Semantic name remains unreviewed. */

void FUN_4096f168(int *param_1,int param_2)

{
  undefined4 uVar1;
  int *piVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  undefined4 *puVar6;
  int iVar7;
  
  FUN_409933b0();
  iVar7 = param_2 - (int)param_1;
  iVar4 = 6;
  do {
    iVar5 = 0xd;
    do {
      if ((*param_1 != 0) && (puVar6 = *(undefined4 **)(*param_1 + 4), puVar6 != (undefined4 *)0x0))
      {
        piVar2 = (int *)(iVar7 + (int)param_1);
        puVar3 = *(undefined4 **)*piVar2;
        mali_surface_access_lock(puVar3);
        mali_surface_access_lock(puVar6);
        *(undefined4 **)*piVar2 = puVar6;
        *(undefined4 **)*param_1 = puVar3;
        uVar1 = *puVar3;
        *puVar3 = *puVar6;
        *puVar6 = uVar1;
        *(undefined4 *)(*piVar2 + 4) = *(undefined4 *)(*param_1 + 4);
        *(undefined4 *)(*param_1 + 4) = 0;
        mali_surface_access_unlock(puVar6);
        mali_surface_access_unlock(puVar3);
      }
      param_1 = param_1 + 1;
      iVar5 = iVar5 + -1;
    } while (iVar5 != 0);
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
                    /* WARNING: Subroutine does not return */
  FUN_409933e0(0x10);
}



/* 4096f228 FUN_4096f228 */

/* Boundary evidence: original MIPS .pdata 4096f228..4096f2b7. Semantic name remains unreviewed. */

undefined4 FUN_4096f228(int param_1)

{
  int *piVar1;
  uint uVar2;
  int local_28 [10];
  
  local_28[2] = 0xb;
  local_28[3] = 0xe;
  local_28[0] = 9;
  local_28[1] = 10;
  local_28[4] = 0xf;
  local_28[7] = 0x15;
  local_28[8] = 0x16;
  uVar2 = 0;
  local_28[5] = 0x10;
  local_28[6] = 0x11;
  local_28[9] = 0x17;
  piVar1 = local_28;
  do {
    if (param_1 == *piVar1) {
      return 1;
    }
    uVar2 = uVar2 + 1;
    prefetch(piVar1 + 2,0);
    piVar1 = piVar1 + 1;
  } while (uVar2 < 10);
  return 0;
}



/* 4096f2d4 FUN_4096f2d4 */

/* Boundary evidence: original MIPS .pdata 4096f2d4..4096f373. Semantic name remains unreviewed. */

int FUN_4096f2d4(int *param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar5 = 0;
  iVar3 = 6;
  do {
    iVar4 = 0xd;
    do {
      piVar1 = (int *)*param_1;
      if (piVar1 != (int *)0x0) {
        iVar2 = *piVar1;
        iVar2 = FUN_4096da8c((uint)*(ushort *)(iVar2 + 0xc),(uint)*(ushort *)(iVar2 + 0xe),piVar1[3]
                             ,*(undefined4 *)(iVar2 + 0x18),*(int *)(iVar2 + 0x20));
        iVar5 = iVar2 + iVar5;
      }
      param_1 = param_1 + 1;
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  return iVar5;
}



/* 4096f374 FUN_4096f374 */

/* Boundary evidence: original MIPS .pdata 4096f374..4096f467. Semantic name remains unreviewed. */

void FUN_4096f374(int param_1,undefined1 *param_2,uint param_3,uint param_4,int param_5,int param_6)

{
  undefined1 uVar1;
  undefined1 uVar2;
  undefined1 uVar3;
  int iVar4;
  undefined1 *puVar5;
  
  uVar1 = (&DAT_40962378)[(int)param_3 >> 8 & 0xf];
  uVar2 = (&DAT_40962378)[(int)param_3 >> 4 & 0xf];
  uVar3 = (&DAT_40962378)[param_3 & 0xf];
  if (0 < param_5) {
    do {
      puVar5 = (undefined1 *)
               ((uint)(uint3)(CONCAT21(CONCAT11((&DAT_40962388)[(int)param_4 >> 8 & 0xf],
                                                (&DAT_40962388)[(int)param_4 >> 4 & 0xf]),
                                       (&DAT_40962388)[param_4 & 0xf]) ^
                             CONCAT21(CONCAT11(uVar1,uVar2),uVar3)) * param_6 + param_1);
      iVar4 = param_6;
      while (iVar4 = iVar4 + -1, -1 < iVar4) {
        *puVar5 = *param_2;
        prefetch(param_2 + 2,0);
        puVar5 = puVar5 + 1;
        param_2 = param_2 + 1;
      }
      param_5 = param_5 + -1;
      param_4 = param_4 + 1;
    } while (param_5 != 0);
  }
  return;
}



/* 4096f468 FUN_4096f468 */

/* Boundary evidence: original MIPS .pdata 4096f468..4096f54b. Semantic name remains unreviewed. */

void FUN_4096f468(int param_1,int param_2,undefined1 *param_3,int param_4)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined1 *puVar5;
  int in_stack_00000020;
  int in_stack_00000024;
  int in_stack_00000028;
  
  FUN_40993370();
  iVar2 = param_2 + 0xf;
  if (iVar2 < 0) {
    iVar2 = param_2 + 0x1e;
  }
  iVar3 = param_4;
  if (param_4 < 0) {
    iVar3 = param_4 + 0xf;
  }
  bVar1 = (&DAT_40962378)[param_4 % 0x10];
  if (0 < in_stack_00000024) {
    do {
      iVar4 = in_stack_00000020;
      if (in_stack_00000020 < 0) {
        iVar4 = in_stack_00000020 + 0xf;
      }
      puVar5 = (undefined1 *)
               ((uint)((&DAT_40962388)[in_stack_00000020 % 0x10] ^ bVar1) * in_stack_00000028 +
                ((iVar4 >> 4) + (iVar2 >> 4) * (iVar3 >> 4)) * in_stack_00000028 * 0x100 + param_1);
      iVar4 = in_stack_00000028;
      while (iVar4 = iVar4 + -1, -1 < iVar4) {
        *puVar5 = *param_3;
        prefetch(param_3 + 2,0);
        puVar5 = puVar5 + 1;
        param_3 = param_3 + 1;
      }
      in_stack_00000024 = in_stack_00000024 + -1;
      in_stack_00000020 = in_stack_00000020 + 1;
    } while (in_stack_00000024 != 0);
  }
                    /* WARNING: Subroutine does not return */
  FUN_40993390(0);
}



/* 4096f588 FUN_4096f588 */

/* Boundary evidence: original MIPS .pdata 4096f588..4096f5db. Semantic name remains unreviewed. */

void FUN_4096f588(uint *param_1)

{
  mali_sys_memset(param_1,0,0x40);
  *param_1 = *param_1 | 0x3f;
  param_1[1] = param_1[1] & 0xfffff7ff | 0x400;
  return;
}



/* 4096f5dc FUN_4096f5dc */

/* Boundary evidence: original MIPS .pdata 4096f5dc..4096f64b. Semantic name remains unreviewed. */

int FUN_4096f5dc(int param_1)

{
  int iVar1;
  
  iVar1 = mali_sys_atomic_dec_and_return(param_1 + 0x34);
  if (iVar1 == 0) {
    if (*(code **)(param_1 + 0x40) != (code *)0x0) {
      if (*(int *)(param_1 + 0x48) == 0) {
        *(int *)(param_1 + 0x48) = param_1;
      }
      (**(code **)(param_1 + 0x40))(*(undefined4 *)(param_1 + 0x48),*(undefined4 *)(param_1 + 0x44))
      ;
    }
    mali_surface_free(param_1);
  }
  return iVar1;
}



/* 4096f64c FUN_4096f64c */

/* Boundary evidence: original MIPS .pdata 4096f64c..4096f667. Semantic name remains unreviewed. */

void FUN_4096f64c(int param_1)

{
  mali_sys_atomic_inc(param_1 + 0x34);
  return;
}



/* 4096f694 FUN_4096f694 */

/* Boundary evidence: original MIPS .pdata 4096f694..4096f6af. Semantic name remains unreviewed. */

void FUN_4096f694(int param_1)

{
  mali_sys_atomic_get(param_1 + 8);
  return;
}



/* 4096f6e4 FUN_4096f6e4 */

/* Boundary evidence: original MIPS .pdata 4096f6e4..4096f713. Semantic name remains unreviewed. */

int FUN_4096f6e4(void)

{
  int iVar1;
  int iVar2;
  
  iVar1 = __m200_texel_format_get_bpp();
  iVar2 = iVar1 + 7;
  if (iVar2 < 0) {
    iVar2 = iVar1 + 0xe;
  }
  return iVar2 >> 3;
}



/* 4096f714 FUN_4096f714 */

/* Boundary evidence: original MIPS .pdata 4096f714..4096f74b. Semantic name remains unreviewed. */

int FUN_4096f714(int *param_1,int param_2)

{
  int iVar1;
  
  if (param_1[1] == 0) {
    iVar1 = mali_mem_mali_addr_get_full();
  }
  else {
    iVar1 = *param_1 + param_2;
  }
  return iVar1;
}



/* 4096f74c FUN_4096f74c */

/* Boundary evidence: original MIPS .pdata 4096f74c..4096f7ff. Semantic name remains unreviewed. */

void FUN_4096f74c(int param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  int *piVar2;
  undefined4 in_stack_00000030;
  int *in_stack_00000034;
  
  FUN_40993370();
  piVar2 = *(int **)((param_2 * 0xd + param_3) * 4 + param_1);
  iVar1 = piVar2[1];
  *in_stack_00000034 = iVar1;
  if (iVar1 != 0) {
    FUN_4096f5dc(iVar1);
    piVar2[1] = 0;
  }
  mali_sys_atomic_inc(*piVar2 + 0x34);
  piVar2[1] = *piVar2;
  mali_sys_atomic_inc(*piVar2 + 0x34);
  iVar1 = mali_image_create_from_surface(*piVar2,in_stack_00000030);
  *(int *)(param_4 + 0x20) = iVar1;
  if (iVar1 == 0) {
    FUN_4096f5dc(*piVar2);
    FUN_4096f5dc(*piVar2);
    piVar2[1] = 0;
  }
  else {
    iVar1 = *(int *)(iVar1 + 0x10);
    *(undefined4 *)(iVar1 + 0x28) = *(undefined4 *)(param_1 + 0x180);
    *(undefined4 *)(iVar1 + 0x24) = *(undefined4 *)(param_1 + 0x17c);
  }
                    /* WARNING: Subroutine does not return */
  FUN_40993390(0x10);
}



/* 4096f800 FUN_4096f800 */

/* Boundary evidence: original MIPS .pdata 4096f800..4096f81b. Semantic name remains unreviewed. */

void FUN_4096f800(undefined4 param_1,undefined4 *param_2,undefined4 *param_3)

{
  FUN_40970e84(param_1,param_2,param_3);
  return;
}



/* 4096f81c FUN_4096f81c */

/* Boundary evidence: original MIPS .pdata 4096f81c..4096f867. Semantic name remains unreviewed. */

undefined4 FUN_4096f81c(int param_1,int param_2,int param_3)

{
  int iVar1;
  
  iVar1 = FUN_40979e34(param_2);
  return *(undefined4 *)((iVar1 * 0xd + param_3) * 4 + param_1);
}



/* 4096f868 FUN_4096f868 */

/* Boundary evidence: original MIPS .pdata 4096f868..4096f8c7. Semantic name remains unreviewed. */

undefined4 FUN_4096f868(int param_1,int param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  
  iVar1 = FUN_40979e34(param_2);
  piVar3 = (int *)((iVar1 * 0xd + param_3) * 4 + param_1);
  FUN_4096f5dc(*(int *)(*piVar3 + 4));
  iVar1 = *piVar3;
  uVar2 = *(undefined4 *)(iVar1 + 4);
  *(undefined4 *)(iVar1 + 4) = 0;
  return uVar2;
}



/* 4096f8c8 FUN_4096f8c8 */

/* Boundary evidence: original MIPS .pdata 4096f8c8..4096f947. Semantic name remains unreviewed. */

undefined4 FUN_4096f8c8(int param_1,int param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  
  iVar1 = FUN_40979e34(param_2);
  iVar1 = *(int *)((iVar1 * 0xd + param_3) * 4 + param_1);
  if (((iVar1 == 0) || (piVar3 = *(int **)(iVar1 + 4), piVar3 == (int *)0x0)) ||
     (iVar1 = mali_sys_atomic_get(*piVar3 + 8), iVar1 < 1)) {
    uVar2 = 0;
  }
  else {
    uVar2 = 1;
  }
  return uVar2;
}



/* 4096f948 FUN_4096f948 */

/* Boundary evidence: original MIPS .pdata 4096f948..4096f9a7. Semantic name remains unreviewed. */

undefined4 FUN_4096f948(int param_1,int param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_40979e34(param_2);
  iVar1 = *(int *)((iVar1 * 0xd + param_3) * 4 + param_1);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = *(undefined4 *)(iVar1 + 8);
  }
  return uVar2;
}



/* 4096f9a8 FUN_4096f9a8 */

/* Boundary evidence: original MIPS .pdata 4096f9a8..4096fa0b. Semantic name remains unreviewed. */

undefined4 FUN_4096f9a8(int param_1,int param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_40979e34(param_2);
  iVar1 = *(int *)((iVar1 * 0xd + param_3) * 4 + param_1);
  if ((iVar1 == 0) || (uVar2 = 1, *(int *)(iVar1 + 4) == 0)) {
    uVar2 = 0;
  }
  return uVar2;
}



/* 4096fa0c FUN_4096fa0c */

/* Boundary evidence: original MIPS .pdata 4096fa0c..4096fbff. Semantic name remains unreviewed. */

void FUN_4096fa0c(undefined4 param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  undefined1 *puStack00000020;
  int *piStack00000024;
  uint in_stack_00000060;
  int in_stack_00000064;
  int in_stack_00000068;
  int in_stack_0000006c;
  undefined1 *in_stack_00000078;
  int in_stack_0000007c;
  
  FUN_40993300();
  piVar3 = *(int **)((param_3 * 0xd + param_4) * 4 + param_2);
  iVar4 = *piVar3;
  piStack00000024 = piVar3;
  iVar1 = __m200_texel_format_get_bpp(*(undefined4 *)(iVar4 + 0x18));
  iVar2 = iVar1 + 7;
  if (iVar2 < 0) {
    iVar2 = iVar1 + 0xe;
  }
  iVar2 = iVar2 >> 3;
  puStack00000020 = in_stack_00000078;
  if (in_stack_00000078 != (undefined1 *)0x0) {
    if ((int)in_stack_00000060 < 0) {
      in_stack_00000068 = in_stack_00000060 + in_stack_00000068;
      in_stack_00000060 = 0;
    }
    if (in_stack_00000064 < 0) {
      in_stack_0000006c = in_stack_00000064 + in_stack_0000006c;
      in_stack_00000064 = 0;
    }
    iVar1 = mali_surface_write_lock(*piVar3,0);
    if (iVar1 == 0) {
      iVar1 = mali_surface_map(*piVar3,3);
      if (iVar1 == 0) {
        mali_surface_write_unlock(*piVar3);
      }
      else {
        iVar4 = *(int *)(iVar4 + 0x20);
        if (iVar4 == 0) {
          iVar4 = 0;
          if (0 < in_stack_0000006c) {
            do {
              mali_sys_memcpy((uint)*(ushort *)(*piVar3 + 0xc) * (iVar4 + in_stack_00000064) * iVar2
                              + iVar1 + iVar2 * in_stack_00000060,puStack00000020,
                              in_stack_00000068 * iVar2);
              iVar4 = iVar4 + 1;
              puStack00000020 = puStack00000020 + in_stack_0000007c;
            } while (iVar4 < in_stack_0000006c);
          }
        }
        else if (iVar4 == 1) {
          iVar4 = 0;
          if (0 < in_stack_0000006c) {
            do {
              FUN_4096f374(iVar1,in_stack_00000078,iVar4 + in_stack_00000064,in_stack_00000060,
                           in_stack_00000068,iVar2);
              iVar4 = iVar4 + 1;
              in_stack_00000078 = in_stack_00000078 + in_stack_0000007c;
              piVar3 = piStack00000024;
            } while (iVar4 < in_stack_0000006c);
          }
        }
        else if ((iVar4 == 3) && (iVar2 = 0, 0 < in_stack_0000006c)) {
          do {
            FUN_4096f468(iVar1,(uint)*(ushort *)(*piVar3 + 0xc),puStack00000020,
                         iVar2 + in_stack_00000064);
            iVar2 = iVar2 + 1;
            puStack00000020 = puStack00000020 + in_stack_0000007c;
          } while (iVar2 < in_stack_0000006c);
        }
        mali_surface_unmap(*piVar3);
        mali_surface_write_unlock(*piVar3);
      }
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_40993338(0x28);
}



/* 4096fc00 FUN_4096fc00 */

uint FUN_4096fc00(int param_1,int param_2,int param_3)

{
  uint uVar1;
  
  if (param_3 == 1) {
    if (param_1 <= param_2) {
      param_1 = param_2;
    }
    uVar1 = param_1 - 1U >> 1 | param_1 - 1U;
    uVar1 = uVar1 >> 2 | uVar1;
    uVar1 = uVar1 >> 4 | uVar1;
    uVar1 = uVar1 >> 8 | uVar1;
    uVar1 = (uVar1 >> 0x10 | uVar1) + 1;
  }
  else if (param_3 == 3) {
    uVar1 = param_1 + 0xfU & 0xfffffff0;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}



/* 4096fc78 FUN_4096fc78 */

/* Boundary evidence: original MIPS .pdata 4096fc78..4096fccb. Semantic name remains unreviewed. */

void FUN_4096fc78(int param_1,int param_2,int param_3)

{
  int iVar1;
  
  iVar1 = FUN_40979e34(param_2);
  mali_surface_write_unlock(**(undefined4 **)((iVar1 * 0xd + param_3) * 4 + param_1));
  return;
}



/* 4096fccc FUN_4096fccc */

/* Boundary evidence: original MIPS .pdata 4096fccc..4096fd23. Semantic name remains unreviewed. */

void FUN_4096fccc(int param_1,int param_2,int param_3)

{
  int iVar1;
  
  iVar1 = FUN_40979e34(param_2);
  mali_surface_write_lock(**(undefined4 **)((iVar1 * 0xd + param_3) * 4 + param_1),0);
  return;
}



/* 4096fd24 FUN_4096fd24 */

/* Boundary evidence: original MIPS .pdata 4096fd24..4096fd8b. Semantic name remains unreviewed. */

void FUN_4096fd24(undefined4 *param_1)

{
  undefined4 *puVar1;
  
  puVar1 = param_1;
  do {
    *puVar1 = 0;
    puVar1 = puVar1 + 1;
  } while (puVar1 != param_1 + 0x4e);
  FUN_4096f588(param_1 + 0x4e);
  param_1[0x61] = 1;
  param_1[0x5f] = 0;
  param_1[0x60] = 0;
  mali_sys_atomic_initialize(param_1 + 0x62,1);
  param_1[0x5e] = 0;
  param_1[99] = 0;
  return;
}



/* 4096fd8c FUN_4096fd8c */

/* Boundary evidence: original MIPS .pdata 4096fd8c..4096ffdb. Semantic name remains unreviewed. */

void FUN_4096fd8c(int param_1,int param_2,int param_3,int param_4)

{
  undefined2 *puVar1;
  uint uVar2;
  byte *pbVar3;
  undefined1 *puVar4;
  int iVar5;
  undefined2 *puVar6;
  int iVar7;
  undefined2 *puVar8;
  int iVar9;
  uint uVar10;
  int in_stack_00000038;
  undefined2 *in_stack_0000003c;
  
  FUN_40993300();
  iVar9 = param_1 + param_2;
  if (0 < in_stack_00000038) {
    uVar10 = 0;
    puVar8 = in_stack_0000003c;
    do {
      switch(param_3) {
      case 0x8b90:
      case 0x8b91:
        iVar5 = 3;
        if (param_3 != 0x8b90) {
          iVar5 = 4;
        }
        puVar1 = (undefined2 *)(uVar10 * iVar5 + (int)in_stack_0000003c);
        iVar7 = param_4;
        uVar2 = uVar10;
        if (0 < param_4) {
          do {
            puVar4 = (undefined1 *)
                     ((*(byte *)((uVar2 >> 1) + iVar9) >> ((1 - (uVar2 & 1)) * 4 & 0x1f) & 0xf) *
                      iVar5 + param_1);
            *(undefined1 *)puVar1 = *puVar4;
            puVar6 = (undefined2 *)((int)puVar1 + 3);
            *(undefined1 *)((int)puVar1 + 1) = puVar4[1];
            *(undefined1 *)(puVar1 + 1) = puVar4[2];
            if (iVar5 == 4) {
              *(undefined1 *)puVar6 = puVar4[3];
              puVar6 = puVar1 + 2;
            }
            iVar7 = iVar7 + -1;
            puVar1 = puVar6;
            uVar2 = uVar2 + 1;
          } while (iVar7 != 0);
        }
        break;
      case 0x8b92:
      case 0x8b93:
      case 0x8b94:
        puVar1 = puVar8;
        iVar5 = param_4;
        uVar2 = uVar10;
        if (0 < param_4) {
          do {
            iVar5 = iVar5 + -1;
            *puVar1 = *(undefined2 *)
                       ((*(byte *)((uVar2 >> 1) + iVar9) >> ((1 - (uVar2 & 1)) * 4 & 0x1f) & 0xf) *
                        2 + param_1);
            puVar1 = puVar1 + 1;
            uVar2 = uVar2 + 1;
          } while (iVar5 != 0);
        }
        break;
      case 0x8b95:
      case 0x8b96:
        iVar5 = 3;
        if (param_3 != 0x8b95) {
          iVar5 = 4;
        }
        iVar7 = 0;
        if (0 < param_4) {
          puVar1 = (undefined2 *)(uVar10 * iVar5 + (int)in_stack_0000003c);
          do {
            puVar4 = (undefined1 *)((uint)*(byte *)(uVar10 + iVar9 + iVar7) * iVar5 + param_1);
            *(undefined1 *)puVar1 = *puVar4;
            *(undefined1 *)((int)puVar1 + 1) = puVar4[1];
            puVar6 = (undefined2 *)((int)puVar1 + 3);
            *(undefined1 *)(puVar1 + 1) = puVar4[2];
            if (iVar5 == 4) {
              *(undefined1 *)puVar6 = puVar4[3];
              puVar6 = puVar1 + 2;
            }
            iVar7 = iVar7 + 1;
            puVar1 = puVar6;
          } while (iVar7 < param_4);
        }
        break;
      case 0x8b97:
      case 0x8b98:
      case 0x8b99:
        iVar5 = 0;
        if (0 < param_4) {
          puVar1 = puVar8;
          do {
            pbVar3 = (byte *)(uVar10 + iVar9 + iVar5);
            iVar5 = iVar5 + 1;
            *puVar1 = *(undefined2 *)((uint)*pbVar3 * 2 + param_1);
            puVar1 = puVar1 + 1;
          } while (iVar5 < param_4);
        }
      }
      in_stack_00000038 = in_stack_00000038 + -1;
      uVar10 = uVar10 + param_4;
      puVar8 = puVar8 + param_4;
    } while (in_stack_00000038 != 0);
  }
                    /* WARNING: Subroutine does not return */
  FUN_40993338(0);
}



/* 4096ffdc FUN_4096ffdc */

/* Boundary evidence: original MIPS .pdata 4096ffdc..409702a3. Semantic name remains unreviewed. */

void FUN_4096ffdc(int param_1,int param_2)

{
  uint uVar1;
  undefined4 *puVar2;
  int *piVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  
  mali_sys_memcpy(param_1 + 0x138,param_2 + 0x138,0x40);
  iVar6 = 0;
  do {
    puVar2 = *(undefined4 **)(iVar6 * 4 + param_1);
    if (puVar2 != (undefined4 *)0x0) {
      puVar2 = (undefined4 *)*puVar2;
      piVar3 = *(int **)*puVar2;
      iVar4 = puVar2[1];
      if (piVar3[1] == 0) {
        uVar1 = mali_mem_mali_addr_get_full(piVar3,iVar4);
      }
      else {
        uVar1 = *piVar3 + iVar4;
      }
      uVar5 = uVar1 >> 6;
      switch(iVar6) {
      case 0:
        *(uint *)(param_1 + 0x150) = *(uint *)(param_1 + 0x150) & 0x3fffffff | uVar5 << 0x1e;
        *(uint *)(param_1 + 0x154) = *(uint *)(param_1 + 0x154) & 0xff000000 | uVar1 >> 8;
        break;
      case 1:
        *(char *)(param_1 + 0x157) = (char)uVar5;
        *(uint *)(param_1 + 0x158) = *(uint *)(param_1 + 0x158) & 0xfffc0000 | uVar1 >> 0xe;
        break;
      case 2:
        *(uint *)(param_1 + 0x158) = *(uint *)(param_1 + 0x158) & 0x3ffff | uVar5 << 0x12;
        *(uint *)(param_1 + 0x15c) = *(uint *)(param_1 + 0x15c) & 0xfffff000 | uVar1 >> 0x14;
        break;
      case 3:
        *(uint *)(param_1 + 0x15c) = *(uint *)(param_1 + 0x15c) & 0xfff | uVar5 << 0xc;
        *(uint *)(param_1 + 0x160) = *(uint *)(param_1 + 0x160) & 0xffffffc0 | uVar1 >> 0x1a;
        break;
      case 4:
        *(uint *)(param_1 + 0x160) = *(uint *)(param_1 + 0x160) & 0x3f | uVar5 << 6;
        break;
      case 5:
        *(uint *)(param_1 + 0x164) = *(uint *)(param_1 + 0x164) & 0xfc000000 | uVar5;
        break;
      case 6:
        *(uint *)(param_1 + 0x164) = *(uint *)(param_1 + 0x164) & 0x3ffffff | uVar5 << 0x1a;
        *(uint *)(param_1 + 0x168) = *(uint *)(param_1 + 0x168) & 0xfff00000 | uVar1 >> 0xc;
        break;
      case 7:
        *(uint *)(param_1 + 0x168) = *(uint *)(param_1 + 0x168) & 0xfffff | uVar5 << 0x14;
        *(uint *)(param_1 + 0x16c) = *(uint *)(param_1 + 0x16c) & 0xffffc000 | uVar1 >> 0x12;
        break;
      case 8:
        *(uint *)(param_1 + 0x16c) = *(uint *)(param_1 + 0x16c) & 0x3fff | uVar5 << 0xe;
        *(uint *)(param_1 + 0x170) = *(uint *)(param_1 + 0x170) & 0xffffff00 | uVar1 >> 0x18;
        break;
      case 9:
        *(uint *)(param_1 + 0x170) = *(uint *)(param_1 + 0x170) & 0xff | uVar5 << 8;
        *(uint *)(param_1 + 0x174) = *(uint *)(param_1 + 0x174) & 0xfffffffc | uVar1 >> 0x1e;
        break;
      case 10:
        *(uint *)(param_1 + 0x174) = *(uint *)(param_1 + 0x174) & 0xf0000003 | uVar5 << 2;
      }
    }
    iVar6 = iVar6 + 1;
  } while (iVar6 < 0xb);
  return;
}



/* 409702a4 FUN_409702a4 */

/* Boundary evidence: original MIPS .pdata 409702a4..4097032f. Semantic name remains unreviewed. */

void FUN_409702a4(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int *piVar1;
  int iVar2;
  
  FUN_40993230();
  piVar1 = (int *)mali_sys_malloc(0x10);
  if (piVar1 != (int *)0x0) {
    piVar1[3] = 0;
    *piVar1 = 0;
    piVar1[1] = 0;
    piVar1[2] = 0;
    iVar2 = mali_surface_alloc(param_2,param_3,0,param_4);
    *piVar1 = iVar2;
    if (iVar2 == 0) {
      FUN_4096dc2c(piVar1);
      mali_sys_free(piVar1);
    }
    else {
      piVar1[3] = 0;
      *(undefined4 *)(iVar2 + 4) = 0;
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_40993258(0x18);
}



/* 40970330 FUN_40970330 */

/* Boundary evidence: original MIPS .pdata 40970330..40970383. Semantic name remains unreviewed. */

void FUN_40970330(int param_1,int param_2,int param_3)

{
  int *piVar1;
  undefined4 *puVar2;
  
  FUN_40993370();
  puVar2 = (undefined4 *)((param_2 * 0xd + param_3) * 4 + param_1);
  piVar1 = (int *)*puVar2;
  if (piVar1 != (int *)0x0) {
    FUN_4096dc2c(piVar1);
    mali_sys_free(piVar1);
    *puVar2 = 0;
  }
                    /* WARNING: Subroutine does not return */
  *(undefined4 *)(param_1 + 0x184) = 1;
  FUN_40993390(0x10);
}



/* 40970384 FUN_40970384 */

/* Boundary evidence: original MIPS .pdata 40970384..409703c7. Semantic name remains unreviewed. */

undefined4 * FUN_40970384(void)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)mali_sys_malloc(400);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    FUN_4096fd24(puVar1);
  }
  return puVar1;
}



/* 409703c8 FUN_409703c8 */

/* Boundary evidence: original MIPS .pdata 409703c8..4097043b. Semantic name remains unreviewed. */

void FUN_409703c8(undefined4 *param_1)

{
  undefined4 *puVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  
  FUN_40993230();
  iVar2 = 6;
  puVar1 = param_1;
  do {
    iVar4 = 0xd;
    do {
      piVar3 = (int *)*puVar1;
      if (piVar3 != (int *)0x0) {
        FUN_4096dc2c(piVar3);
        mali_sys_free(piVar3);
        *puVar1 = 0;
      }
      iVar4 = iVar4 + -1;
      puVar1 = puVar1 + 1;
    } while (iVar4 != 0);
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  if (param_1[0x5e] != 0) {
    mali_mem_ref_deref();
  }
  param_1[0x5e] = 0;
                    /* WARNING: Subroutine does not return */
  FUN_40993258(0x10);
}



/* 4097043c FUN_4097043c */

/* Boundary evidence: original MIPS .pdata 4097043c..40970587. Semantic name remains unreviewed. */

undefined4 FUN_4097043c(int param_1,int param_2,int param_3,int param_4,int param_5)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  
  iVar1 = FUN_40979e34(param_2);
  piVar2 = (int *)mali_sys_malloc(0x10);
  if (piVar2 == (int *)0x0) {
    uVar3 = 0x505;
  }
  else {
    piVar2[3] = 0;
    *piVar2 = 0;
    piVar2[1] = 0;
    piVar2[2] = 0;
    piVar2[3] = 1;
    *piVar2 = param_4;
    piVar2[1] = param_4;
    piVar2[2] = param_5;
    mali_sys_atomic_inc(param_4 + 0x34);
    mali_sys_atomic_inc(param_4 + 0x34);
    FUN_40970330(param_1,iVar1,param_3);
    *(int **)((iVar1 * 0xd + param_3) * 4 + param_1) = piVar2;
    *(undefined4 *)(param_1 + 0x184) = 1;
    if (param_5 == 0) {
      *(undefined4 *)(param_1 + 0x17c) = *(undefined4 *)(param_4 + 0x24);
    }
    else {
      iVar1 = *(int *)(param_4 + 0x18);
      if ((iVar1 < 0xf) || ((0x10 < iVar1 && ((iVar1 < 0x16 || (0x17 < iVar1)))))) {
        *(undefined4 *)(param_1 + 0x17c) = 0;
      }
      else {
        *(undefined4 *)(param_1 + 0x17c) = 1;
      }
    }
    uVar3 = 0;
    *(undefined4 *)(param_1 + 0x180) = *(undefined4 *)(param_4 + 0x28);
  }
  return uVar3;
}



/* 40970588 FUN_40970588 */

/* Boundary evidence: original MIPS .pdata 40970588..40970b83. Semantic name remains unreviewed. */

void FUN_40970588(undefined4 param_1,int param_2,int param_3,int param_4)

{
  bool bVar1;
  int *piVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  int *piVar8;
  int iVar9;
  int iVar10;
  uint uVar11;
  int iVar12;
  int iVar13;
  int *piVar14;
  undefined4 uStack00000028;
  int iStack0000002c;
  int iStack00000030;
  int iStack00000034;
  int iStack0000003c;
  int iStack00000040;
  undefined4 in_stack_00000050;
  undefined4 in_stack_00000054;
  undefined4 in_stack_00000058;
  int in_stack_0000005c;
  undefined4 in_stack_00000060;
  undefined4 in_stack_00000064;
  uint in_stack_000000a0;
  uint in_stack_000000a4;
  uint in_stack_000000a8;
  int in_stack_000000ac;
  int in_stack_000000b0;
  
  FUN_40993300();
  iVar10 = 0;
  uStack00000028 = param_1;
  iStack00000030 = param_2;
  iStack00000040 = param_3;
  if (in_stack_000000a0 == 0x8d64) {
    iStack0000003c = param_4;
    if (param_4 < 0) goto LAB_40970b6c;
  }
  else {
    if (0 < param_4) goto LAB_40970b6c;
    param_4 = -param_4;
    iStack0000003c = 0;
    if (param_4 < 0) {
      param_4 = 0;
    }
  }
  uVar3 = in_stack_000000a0 - 0x8b90;
  if ((in_stack_000000a0 != 0x8b90) && (4 < uVar3)) {
    if ((uVar3 == 5) || (in_stack_000000a0 - 0x8b95 < 5)) {
      iStack0000002c = 1;
      iVar13 = 0x100;
      goto LAB_40970904;
    }
    if (uVar3 != 0x1d4) goto LAB_40970b6c;
    iVar9 = 4;
    iStack0000002c = 2;
LAB_40970644:
    iVar10 = 0;
    in_stack_00000050 = 0xffffffff;
    in_stack_00000054 = 0x20;
    in_stack_00000058 = 2;
    in_stack_0000005c = 3;
    in_stack_00000060 = 0;
    in_stack_00000064 = 0;
    goto switchD_40970944_default;
  }
  iVar13 = 0x10;
  iStack0000002c = 2;
LAB_40970904:
  iVar9 = 1;
  if (0x8d64 < in_stack_000000a0) goto switchD_40970944_default;
  if (in_stack_000000a0 == 0x8d64) goto LAB_40970644;
  switch(in_stack_000000a0) {
  case 0x8b90:
  case 0x8b95:
    FUN_40971004(&stack0x00000050,0x1401,0x1907);
    iVar10 = iVar13 * 3;
    goto LAB_4097097c;
  case 0x8b91:
  case 0x8b96:
    FUN_40971004(&stack0x00000050,0x1401,0x1908);
    iVar10 = iVar13 << 2;
    goto LAB_4097097c;
  case 0x8b92:
  case 0x8b97:
    iVar12 = 0x1907;
    iVar10 = 0x8363;
    break;
  case 0x8b93:
  case 0x8b98:
    iVar12 = 0x1908;
    iVar10 = 0x8033;
    break;
  case 0x8b94:
  case 0x8b99:
    iVar12 = 0x1908;
    iVar10 = 0x8034;
    break;
  default:
    goto switchD_40970944_default;
  }
  FUN_40971004(&stack0x00000050,iVar10,iVar12);
  iVar10 = iVar13 << 1;
LAB_4097097c:
  in_stack_0000005c = 0;
  in_stack_00000058 = 0;
switchD_40970944_default:
  bVar1 = iStack0000003c <= param_4;
  iVar13 = iVar10;
  if (bVar1) {
    iVar12 = (param_4 - iStack0000003c) + 1;
    uVar6 = in_stack_000000a8;
    uVar3 = in_stack_000000a4;
    do {
      iVar4 = iVar9 + -1 + uVar6;
      if (iVar9 == 0) {
        trap(0x1c00);
      }
      if ((iVar9 == -1) && (iVar4 == -0x80000000)) {
        trap(0x1800);
      }
      iVar7 = iVar9 + -1 + uVar3;
      if (iVar9 == 0) {
        trap(0x1c00);
      }
      if ((iVar9 == -1) && (iVar7 == -0x80000000)) {
        trap(0x1800);
      }
      iVar4 = (iVar4 / iVar9) * (iVar7 / iVar9) * iVar9 * iVar9;
      iVar7 = iVar4 / iStack0000002c;
      if (iStack0000002c == 0) {
        trap(0x1c00);
      }
      if ((iStack0000002c == -1) && (iVar4 == -0x80000000)) {
        trap(0x1800);
      }
      if (iVar7 == 0) {
        iVar7 = 1;
      }
      iVar13 = iVar7 + iVar13;
      if ((int)uVar3 < 0) {
        uVar3 = uVar3 + 1;
      }
      uVar5 = (int)uVar3 >> 1;
      uVar3 = 1;
      if (0 < (int)uVar5) {
        uVar3 = uVar5;
      }
      if ((int)uVar6 < 0) {
        uVar6 = uVar6 + 1;
      }
      uVar5 = (int)uVar6 >> 1;
      uVar6 = 1;
      if (0 < (int)uVar5) {
        uVar6 = uVar5;
      }
      iVar12 = iVar12 + -1;
      param_2 = iStack00000030;
    } while (iVar12 != 0);
  }
  iVar12 = iStack0000003c;
  uVar3 = in_stack_000000a4;
  uVar6 = in_stack_000000a8;
  if (in_stack_000000ac == iVar13) {
    while (bVar1) {
      iStack00000034 = 0;
      piVar2 = (int *)FUN_409702a4(uStack00000028,uVar3 & 0xffff,uVar6 & 0xffff,&stack0x00000050);
      if (piVar2 == (int *)0x0) goto LAB_40970b6c;
      piVar2[3] = 1;
      piVar14 = (int *)((iStack00000040 * 0xd + iVar12) * 4 + param_2);
      piVar8 = (int *)*piVar14;
      if (piVar8 != (int *)0x0) {
        FUN_4096dc2c(piVar8);
        mali_sys_free(piVar8);
        *piVar14 = 0;
      }
      *piVar14 = (int)piVar2;
      mali_surface_access_lock(*piVar2);
      iVar13 = mali_mem_ptr_map_area(**(undefined4 **)*piVar2,0,((undefined4 *)*piVar2)[0xb],0x40);
      if (iVar13 == 0) {
        mali_surface_access_unlock(*piVar2);
        goto LAB_40970b6c;
      }
      if (in_stack_000000b0 != 0) {
        if (in_stack_000000a0 == 0x8d64) {
          iVar4 = iVar9 + -1 + uVar3;
          if (iVar9 == 0) {
            trap(0x1c00);
          }
          if ((iVar9 == -1) && (iVar4 == -0x80000000)) {
            trap(0x1800);
          }
          iVar7 = iVar9 + -1 + uVar6;
          if (iVar9 == 0) {
            trap(0x1c00);
          }
          if ((iVar9 == -1) && (iVar7 == -0x80000000)) {
            trap(0x1800);
          }
          if (in_stack_0000005c != 0) {
            FUN_4096fc00((iVar4 / iVar9) * iVar9,(iVar7 / iVar9) * iVar9,in_stack_0000005c);
          }
          __m200_texel_format_get_bpp(in_stack_00000054);
          __m200_texel_format_get_bpp(in_stack_00000054);
          iStack00000034 = m200_texture_swizzle(iVar13,in_stack_0000005c,in_stack_000000b0,0);
          iVar10 = *(int *)(*piVar2 + 0x2c) + iVar10;
        }
        else {
          FUN_4096fd8c(in_stack_000000b0,iVar10,in_stack_000000a0,uVar3);
          if (iStack0000002c == 0) {
            trap(0x1c00);
          }
          if ((iStack0000002c == -1) && (uVar6 * uVar3 == -0x80000000)) {
            trap(0x1800);
          }
          iVar10 = (int)(uVar6 * uVar3) / iStack0000002c + iVar10;
        }
      }
      mali_mem_ptr_unmap_area(**(undefined4 **)*piVar2);
      mali_surface_access_unlock(*piVar2);
      if (iStack00000034 != 0) goto LAB_40970b6c;
      if ((int)uVar3 < 0) {
        uVar3 = uVar3 + 1;
      }
      uVar5 = 1;
      if (0 < (int)uVar3 >> 1) {
        uVar5 = (int)uVar3 >> 1;
      }
      if ((int)uVar6 < 0) {
        uVar6 = uVar6 + 1;
      }
      uVar11 = 1;
      if (0 < (int)uVar6 >> 1) {
        uVar11 = (int)uVar6 >> 1;
      }
      bVar1 = iVar12 + 1 <= param_4;
      param_2 = iStack00000030;
      iVar12 = iVar12 + 1;
      uVar3 = uVar5;
      uVar6 = uVar11;
    }
    *(undefined4 *)(param_2 + 0x184) = 1;
    if (iStack0000003c == 0) {
      *(undefined4 *)(param_2 + 0x17c) = in_stack_00000060;
      *(undefined4 *)(param_2 + 0x180) = in_stack_00000064;
    }
  }
LAB_40970b6c:
                    /* WARNING: Subroutine does not return */
  FUN_40993338(0x68);
}



/* 40970b84 FUN_40970b84 */

/* Boundary evidence: original MIPS .pdata 40970b84..40970cfb. Semantic name remains unreviewed. */

void FUN_40970b84(undefined4 param_1,int param_2,int param_3,int param_4)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  undefined4 in_stack_00000034;
  undefined4 in_stack_00000038;
  undefined4 in_stack_0000003c;
  uint in_stack_00000078;
  uint in_stack_0000007c;
  int in_stack_00000080;
  int in_stack_00000084;
  int in_stack_00000088;
  
  FUN_40993300();
  FUN_40971004((undefined4 *)&stack0x00000028,in_stack_00000084,in_stack_00000080);
  if ((0 < (int)in_stack_00000078) && (0 < (int)in_stack_0000007c)) {
    piVar1 = (int *)FUN_409702a4(param_1,in_stack_00000078 & 0xffff,in_stack_0000007c & 0xffff,
                                 &stack0x00000028);
    if (piVar1 == (int *)0x0) goto LAB_40970cf0;
    piVar1[3] = 1;
    FUN_40970330(param_2,param_3,param_4);
    piVar5 = (int *)((param_3 * 0xd + param_4) * 4 + param_2);
    *piVar5 = (int)piVar1;
    if (in_stack_00000088 != 0) {
      iVar3 = *piVar1;
      iVar4 = 0;
      mali_surface_access_lock(iVar3);
      iVar2 = mali_surface_map(iVar3,2);
      if (iVar2 == 0) {
        iVar4 = -1;
      }
      *(undefined4 *)(iVar3 + 8) = 0;
      *(undefined4 *)(iVar3 + 0x3c) = 0;
      if (iVar4 == 0) {
        iVar4 = m200_texture_swizzle(iVar2,in_stack_00000034,in_stack_00000088,0);
        mali_surface_unmap(iVar3);
      }
      mali_surface_access_unlock(iVar3);
      if (iVar4 != 0) {
        piVar1 = (int *)*piVar5;
        FUN_4096dc2c(piVar1);
        mali_sys_free(piVar1);
        *piVar5 = 0;
        goto LAB_40970cf0;
      }
    }
  }
  *(undefined4 *)(param_2 + 0x184) = 1;
  if (param_4 == 0) {
    *(undefined4 *)(param_2 + 0x180) = in_stack_0000003c;
    *(undefined4 *)(param_2 + 0x17c) = in_stack_00000038;
  }
LAB_40970cf0:
                    /* WARNING: Subroutine does not return */
  FUN_40993338(0x40);
}



/* 40970cfc FUN_40970cfc */

/* Boundary evidence: original MIPS .pdata 40970cfc..40970d3f. Semantic name remains unreviewed. */

void FUN_40970cfc(undefined4 *param_1)

{
  if (param_1[99] != 0) {
    mali_cmu_dec_cow_memory_usage();
  }
  FUN_409703c8(param_1);
  mali_sys_free(param_1);
  return;
}



/* 40970d40 FUN_40970d40 */

/* Boundary evidence: original MIPS .pdata 40970d40..40970e4b. Semantic name remains unreviewed. */

int * FUN_40970d40(undefined4 param_1,undefined4 *param_2)

{
  int *piVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  int iVar5;
  int iVar6;
  
  piVar1 = FUN_40970384();
  if (piVar1 == (int *)0x0) {
LAB_40970d80:
    piVar1 = (int *)0x0;
  }
  else {
    iVar5 = 0;
    puVar3 = param_2;
    do {
      iVar6 = 0;
      puVar4 = puVar3;
      do {
        if ((undefined4 *)*puVar4 != (undefined4 *)0x0) {
          iVar2 = FUN_4096dcac(param_1,(undefined4 *)*puVar4);
          *(int *)(((int)piVar1 - (int)param_2) + (int)puVar4) = iVar2;
          if (iVar2 == 0) {
            FUN_40970cfc(piVar1);
            goto LAB_40970d80;
          }
        }
        iVar6 = iVar6 + 1;
        puVar4 = puVar4 + 1;
      } while (iVar6 < 0xd);
      iVar5 = iVar5 + 1;
      puVar3 = puVar3 + 0xd;
    } while (iVar5 < 6);
    FUN_4096ffdc((int)piVar1,(int)param_2);
    iVar5 = FUN_4096f2d4(piVar1);
    piVar1[99] = iVar5;
    mali_cmu_inc_cow_memory_usage(iVar5);
    piVar1[0x60] = param_2[0x60];
    piVar1[0x5f] = param_2[0x5f];
  }
  return piVar1;
}



/* 40970e4c FUN_40970e4c */

/* Boundary evidence: original MIPS .pdata 40970e4c..40970e83. Semantic name remains unreviewed. */

void FUN_40970e4c(undefined4 *param_1)

{
  int iVar1;
  
  iVar1 = mali_sys_atomic_dec_and_return(param_1 + 0x62);
  if (iVar1 == 0) {
    FUN_40970cfc(param_1);
  }
  return;
}



/* 40970e84 FUN_40970e84 */

/* Boundary evidence: original MIPS .pdata 40970e84..40970f6b. Semantic name remains unreviewed. */

void FUN_40970e84(undefined4 param_1,undefined4 *param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  switch(param_1) {
  case 9:
    uVar1 = 0x1909;
    *param_2 = 0x1401;
    goto LAB_40970f5c;
  case 10:
    uVar2 = 0x1906;
    break;
  case 0xb:
    uVar2 = 0x1401;
    uVar1 = 0x1906;
    goto LAB_40970f08;
  default:
    goto switchD_40970eb4_caseD_c;
  case 0xe:
    uVar2 = 0x8363;
    goto LAB_40970f54;
  case 0xf:
    uVar1 = 0x8034;
    uVar2 = 0x1908;
    goto LAB_40970ef4;
  case 0x10:
    uVar2 = 0x8033;
    goto LAB_40970f2c;
  case 0x11:
    uVar2 = 0x1401;
    uVar1 = 0x190a;
    goto LAB_40970f58;
  case 0x15:
    uVar2 = 0x1907;
    break;
  case 0x16:
    uVar2 = 0x1401;
LAB_40970f2c:
    uVar1 = 0x1908;
LAB_40970f08:
    *param_2 = uVar2;
    *param_3 = uVar1;
    return;
  case 0x17:
    uVar2 = 0x1401;
LAB_40970f54:
    uVar1 = 0x1907;
LAB_40970f58:
    *param_2 = uVar2;
LAB_40970f5c:
    *param_3 = uVar1;
    goto switchD_40970eb4_caseD_c;
  }
  uVar1 = 0x1401;
LAB_40970ef4:
  *param_2 = uVar1;
  *param_3 = uVar2;
switchD_40970eb4_caseD_c:
  return;
}



/* 40970f98 FUN_40970f98 */

/* Boundary evidence: original MIPS .pdata 40970f98..40971003. Semantic name remains unreviewed. */

void FUN_40970f98(undefined4 *param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  uVar1 = mali_pixel_layout_to_texel_layout(2);
  uVar2 = mali_pixel_to_texel_format(0xffffffff);
  *param_1 = 0xffffffff;
  param_1[2] = 2;
  param_1[3] = uVar1;
  param_1[1] = uVar2;
  param_1[4] = 0;
  param_1[5] = 0;
  return;
}



/* 40971004 FUN_40971004 */

/* Boundary evidence: original MIPS .pdata 40971004..409710cb. Semantic name remains unreviewed. */

void FUN_40971004(undefined4 *param_1,int param_2,int param_3)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  
  iVar3 = 0;
  uVar1 = 0;
  while ((*(int *)((int)&DAT_40996270 + uVar1) != param_2 ||
         (*(int *)((int)&DAT_40996274 + uVar1) != param_3))) {
    uVar1 = uVar1 + 0x18;
    iVar3 = iVar3 + 1;
    if (0xef < uVar1) {
      FUN_40970f98(param_1);
      return;
    }
  }
  iVar3 = iVar3 * 0x18;
  uVar5 = *(undefined4 *)(iVar3 + 0x40996284);
  uVar4 = *(undefined4 *)(iVar3 + 0x40996280);
  uVar2 = *(undefined4 *)(iVar3 + 0x4099627c);
  *param_1 = *(undefined4 *)(iVar3 + 0x40996278);
  param_1[1] = uVar2;
  param_1[2] = 2;
  param_1[3] = 3;
  param_1[4] = uVar4;
  param_1[5] = uVar5;
  return;
}



/* 40971218 FUN_40971218 */

/* Boundary evidence: original MIPS .pdata 40971218..40971287. Semantic name remains unreviewed. */

int FUN_40971218(int param_1)

{
  int iVar1;
  
  iVar1 = mali_sys_atomic_dec_and_return(param_1 + 0x34);
  if (iVar1 == 0) {
    if (*(code **)(param_1 + 0x40) != (code *)0x0) {
      if (*(int *)(param_1 + 0x48) == 0) {
        *(int *)(param_1 + 0x48) = param_1;
      }
      (**(code **)(param_1 + 0x40))(*(undefined4 *)(param_1 + 0x48),*(undefined4 *)(param_1 + 0x44))
      ;
    }
    mali_surface_free(param_1);
  }
  return iVar1;
}



/* 40971288 FUN_40971288 */

/* Boundary evidence: original MIPS .pdata 40971288..409712a3. Semantic name remains unreviewed. */

void FUN_40971288(int param_1)

{
  mali_sys_atomic_inc(param_1 + 0x34);
  return;
}



/* 409712a4 FUN_409712a4 */

/* Boundary evidence: original MIPS .pdata 409712a4..4097132b. Semantic name remains unreviewed. */

void FUN_409712a4(int param_1,undefined4 *param_2,undefined4 *param_3,undefined4 *param_4)

{
  undefined4 uVar1;
  
  if (*(int *)(param_1 + 8) != 0) {
    uVar1 = mali_render_attachment_is_dirty(*(undefined4 *)(param_1 + 0x20));
    *param_2 = uVar1;
  }
  if (*(int *)(param_1 + 0x2c) != 0) {
    uVar1 = mali_render_attachment_is_dirty(*(undefined4 *)(param_1 + 0x44));
    *param_3 = uVar1;
  }
  if (*(int *)(param_1 + 0x50) != 0) {
    uVar1 = mali_render_attachment_is_dirty(*(undefined4 *)(param_1 + 0x68));
    *param_4 = uVar1;
  }
  return;
}



/* 4097132c FUN_4097132c */

/* Boundary evidence: original MIPS .pdata 4097132c..4097138b. Semantic name remains unreviewed. */

void FUN_4097132c(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  FUN_40993370();
  if (*(int *)(param_1 + 8) != 0) {
    mali_render_attachment_set_dirty(*(undefined4 *)(param_1 + 0x20));
  }
  if (*(int *)(param_1 + 0x2c) != 0) {
    mali_render_attachment_set_dirty(*(undefined4 *)(param_1 + 0x44),param_3);
  }
  if (*(int *)(param_1 + 0x50) != 0) {
    mali_render_attachment_set_dirty(*(undefined4 *)(param_1 + 0x68),param_4);
  }
                    /* WARNING: Subroutine does not return */
  FUN_40993390(0x10);
}



/* 4097138c FUN_4097138c */

undefined4 FUN_4097138c(int param_1,int param_2)

{
  uint uVar1;
  
  if (param_2 == 0x8ce0) {
    uVar1 = 0;
    do {
      if (param_1 == *(int *)((int)&DAT_40962398 + uVar1)) {
        return 0x8cd5;
      }
      uVar1 = uVar1 + 4;
    } while (uVar1 < 0xc);
  }
  else if (param_2 == 0x8d00) {
    uVar1 = 0;
    do {
      if (param_1 == *(int *)((int)&DAT_409623a4 + uVar1)) {
        return 0x8cd5;
      }
      uVar1 = uVar1 + 4;
    } while (uVar1 < 8);
  }
  else {
    if (param_2 != 0x8d20) {
      return 0x8cd5;
    }
    uVar1 = 0;
    do {
      if (param_1 == *(int *)((int)&DAT_409623ac + uVar1)) {
        return 0x8cd5;
      }
      uVar1 = uVar1 + 4;
    } while (uVar1 < 4);
  }
  return 0x8cd6;
}



/* 40971460 FUN_40971460 */

/* Boundary evidence: original MIPS .pdata 40971460..409715fb. Semantic name remains unreviewed. */

undefined4 FUN_40971460(int param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  
  if ((param_2 != 0xd52) && (3 < param_2 - 0xd52U)) {
    if (param_2 == 0xd56) {
      param_1 = param_1 + 0x24;
    }
    else {
      if (param_2 != 0xd57) {
        return 0;
      }
      param_1 = param_1 + 0x48;
    }
  }
  if (param_1 != 0) {
    if (*(int *)(param_1 + 8) == 0x1702) {
      iVar1 = FUN_40979e34(*(int *)(param_1 + 0x1c));
      piVar2 = *(int **)((iVar1 * 0xd + *(int *)(param_1 + 0x18)) * 4 +
                        *(int *)(*(int *)(param_1 + 0x10) + 0x34));
      if (piVar2 == (int *)0x0) {
        return 0;
      }
      iVar1 = *piVar2;
    }
    else {
      if (*(int *)(param_1 + 8) != 0x8d41) {
        return 0;
      }
      iVar1 = *(int *)(*(int *)(param_1 + 0x10) + 0x28);
    }
    if (iVar1 != 0) {
      mali_pixel_format_get_bpc
                (*(undefined4 *)(iVar1 + 0x14),&local_14,&local_18,&local_1c,&local_20,&local_24,
                 &local_28);
      if (param_2 == 0xd52) {
        return local_14;
      }
      if (param_2 == 0xd53) {
        return local_18;
      }
      if (param_2 == 0xd54) {
        return local_1c;
      }
      if (param_2 == 0xd55) {
        return local_20;
      }
      if (param_2 == 0xd56) {
        return local_24;
      }
      if (param_2 == 0xd57) {
        return local_28;
      }
    }
  }
  return 0;
}



/* 409715fc FUN_409715fc */

void FUN_409715fc(int param_1,uint param_2,int param_3)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x504);
  *(char *)(iVar1 + 0x46) = (char)param_2;
  *(char *)(iVar1 + 0x47) = (char)param_3;
  if ((*(uint *)(iVar1 + 0x40) & 8) != 8) {
    if ((*(uint *)(iVar1 + 0x40) & 4) == 0) {
      param_3 = 2;
      param_2 = 2;
    }
    *(uint *)(iVar1 + 8) = (*(uint *)(iVar1 + 8) & 0xfffffff8 ^ param_2) & 0xffffffc7 ^ param_3 << 3
    ;
  }
  return;
}



/* 40971660 FUN_40971660 */

/* Boundary evidence: original MIPS .pdata 40971660..40971827. Semantic name remains unreviewed. */

int FUN_40971660(int param_1,undefined4 *param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int local_20 [2];
  
  uVar3 = 0;
  local_20[0] = 0;
  if (param_2[5] == 0) {
LAB_40971808:
    iVar1 = 0;
  }
  else {
    if (param_2[8] != 0) {
      iVar1 = mali_render_attachment_get_target(param_2[8],0,0);
      if (iVar1 != 0) {
        iVar2 = mali_surface_write_lock(iVar1,0);
        if (iVar2 != 0) {
          return iVar2;
        }
        mali_surface_write_unlock(iVar1);
        FUN_40971218(iVar1);
      }
      mali_render_attachment_free(param_2[8]);
      param_2[8] = 0;
      mali_frame_builder_set_attachment(*(undefined4 *)(param_1 + 0x6c),param_2[1],0);
    }
    if (param_2[2] == 0x1702) {
      iVar1 = FUN_4097a63c(param_2[4],param_2[7],param_2[6]);
      if (iVar1 != 0) {
        iVar1 = FUN_40979e34(param_2[7]);
        local_20[0] = **(int **)((iVar1 * 0xd + param_2[6]) * 4 + *(int *)(param_2[4] + 0x34));
        goto LAB_40971784;
      }
    }
    else if ((param_2[2] != 0x8d41) || (local_20[0] = *(int *)(param_2[4] + 0x28), local_20[0] != 0)
            ) {
LAB_40971784:
      if (local_20[0] != 0) {
        iVar1 = mali_render_attachment_alloc(local_20,1,1,0,*param_2);
        param_2[8] = iVar1;
        if (iVar1 == 0) {
          return -1;
        }
        if (*(int *)(local_20[0] + 0x24) != 0) {
          uVar3 = 4;
        }
        if (*(int *)(local_20[0] + 0x28) != 0) {
          uVar3 = uVar3 | 2;
        }
        mali_render_attachment_set_modifier_flags(iVar1,uVar3);
        mali_sys_atomic_inc(local_20[0] + 0x34);
      }
      mali_frame_builder_set_attachment(*(undefined4 *)(param_1 + 0x6c),param_2[1],param_2[8]);
      param_2[5] = 0;
      goto LAB_40971808;
    }
    iVar1 = -2;
  }
  return iVar1;
}



/* 40971828 FUN_40971828 */

/* Boundary evidence: original MIPS .pdata 40971828..40971977. Semantic name remains unreviewed. */

void FUN_40971828(int param_1,int *param_2,int *param_3,int param_4)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  FUN_409933b0();
  iVar5 = 0;
  iVar3 = 0;
  if (*(int *)(param_1 + 8) == 0x1702) {
    iVar4 = *(int *)(param_1 + 0x10);
    if ((*(int **)(iVar4 + 0x1c) != (int *)0x0) && (**(int **)(iVar4 + 0x1c) != 0)) {
      iVar1 = FUN_40979e34(*(int *)(param_1 + 0x1c));
      piVar2 = *(int **)(*(int *)((iVar1 + 7) * 4 + iVar4) + *(int *)(param_1 + 0x18) * 4);
      iVar5 = *piVar2;
      iVar3 = piVar2[1];
      if ((param_4 != 0x8ce0) ||
         (*(int *)(**(int **)((iVar1 * 0xd + *(int *)(param_1 + 0x18)) * 4 + *(int *)(iVar4 + 0x34))
                  + 0x14) == -1)) goto LAB_4097196c;
    }
  }
  else if (*(int *)(param_1 + 8) == 0x8d41) {
    FUN_4097138c(**(int **)(param_1 + 0x10),param_4);
    iVar5 = *(int *)(*(int *)(param_1 + 0x10) + 4);
    iVar3 = *(int *)(*(int *)(param_1 + 0x10) + 8);
  }
  if (*param_2 == -1) {
    *param_2 = iVar5;
  }
  if (*param_3 == -1) {
    *param_3 = iVar3;
  }
LAB_4097196c:
                    /* WARNING: Subroutine does not return */
  FUN_409933e0(0x10);
}



/* 409719bc FUN_409719bc */

/* Boundary evidence: original MIPS .pdata 409719bc..40971ad3. Semantic name remains unreviewed. */

undefined4 FUN_409719bc(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int *piVar4;
  int local_28;
  undefined1 auStack_24 [4];
  undefined1 auStack_20 [4];
  undefined1 auStack_1c [4];
  undefined1 auStack_18 [4];
  undefined1 auStack_14 [4];
  
  iVar3 = *(int *)(param_1 + 0x484);
  if (iVar3 == 0) {
    local_28 = *(int *)(param_1 + 0x4a8);
    goto LAB_40971a90;
  }
  if (iVar3 != -0x48) {
    if (*(int *)(iVar3 + 0x50) == 0x1702) {
      iVar1 = FUN_40979e34(*(int *)(iVar3 + 100));
      piVar4 = *(int **)((iVar1 * 0xd + *(int *)(iVar3 + 0x60)) * 4 +
                        *(int *)(*(int *)(iVar3 + 0x58) + 0x34));
      if (piVar4 != (int *)0x0) {
        iVar3 = *piVar4;
        goto LAB_40971a48;
      }
    }
    else if (*(int *)(iVar3 + 0x50) == 0x8d41) {
      iVar3 = *(int *)(*(int *)(iVar3 + 0x58) + 0x28);
LAB_40971a48:
      if (iVar3 != 0) {
        mali_pixel_format_get_bpc
                  (*(undefined4 *)(iVar3 + 0x14),auStack_14,auStack_18,auStack_1c,auStack_20,
                   auStack_24,&local_28);
        goto LAB_40971a90;
      }
    }
  }
  local_28 = 0;
LAB_40971a90:
  uVar2 = 1;
  if (((*(uint *)(*(int *)(param_1 + 0x504) + 0x40) & 0x10) == 0) || (local_28 < 1)) {
    uVar2 = 0;
  }
  return uVar2;
}



/* 40971ad4 FUN_40971ad4 */

/* Boundary evidence: original MIPS .pdata 40971ad4..40971beb. Semantic name remains unreviewed. */

undefined4 FUN_40971ad4(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int *piVar4;
  int local_28;
  undefined1 auStack_24 [4];
  undefined1 auStack_20 [4];
  undefined1 auStack_1c [4];
  undefined1 auStack_18 [4];
  undefined1 auStack_14 [4];
  
  iVar3 = *(int *)(param_1 + 0x484);
  if (iVar3 == 0) {
    local_28 = *(int *)(param_1 + 0x4a4);
    goto LAB_40971ba8;
  }
  if (iVar3 != -0x24) {
    if (*(int *)(iVar3 + 0x2c) == 0x1702) {
      iVar1 = FUN_40979e34(*(int *)(iVar3 + 0x40));
      piVar4 = *(int **)((iVar1 * 0xd + *(int *)(iVar3 + 0x3c)) * 4 +
                        *(int *)(*(int *)(iVar3 + 0x34) + 0x34));
      if (piVar4 != (int *)0x0) {
        iVar3 = *piVar4;
        goto LAB_40971b60;
      }
    }
    else if (*(int *)(iVar3 + 0x2c) == 0x8d41) {
      iVar3 = *(int *)(*(int *)(iVar3 + 0x34) + 0x28);
LAB_40971b60:
      if (iVar3 != 0) {
        mali_pixel_format_get_bpc
                  (*(undefined4 *)(iVar3 + 0x14),auStack_14,auStack_18,auStack_1c,auStack_20,
                   &local_28,auStack_24);
        goto LAB_40971ba8;
      }
    }
  }
  local_28 = 0;
LAB_40971ba8:
  uVar2 = 1;
  if (((*(uint *)(*(int *)(param_1 + 0x504) + 0x40) & 2) == 0) || (local_28 < 1)) {
    uVar2 = 0;
  }
  return uVar2;
}



/* 40971bec FUN_40971bec */

/* Boundary evidence: original MIPS .pdata 40971bec..40971dbf. Semantic name remains unreviewed. */

void FUN_40971bec(int param_1,uint param_2,int param_3,uint param_4,byte param_5)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  
  iVar3 = *(int *)(param_1 + 0x504);
  uVar2 = (uint)param_5;
  *(char *)(iVar3 + 0x48) = (char)param_2;
  *(char *)(iVar3 + 0x49) = (char)param_3;
  *(char *)(iVar3 + 0x4a) = (char)param_4;
  *(byte *)(iVar3 + 0x4b) = param_5;
  if ((*(uint *)(iVar3 + 0x40) & 8) == 8) {
    return;
  }
  if ((*(uint *)(iVar3 + 0x40) & 4) == 0) {
    param_4 = 0xb;
    param_2 = 0xb;
    uVar2 = 3;
    param_3 = 3;
  }
  FUN_409715fc(param_1,(uint)*(byte *)(iVar3 + 0x46),(uint)*(byte *)(iVar3 + 0x47));
  if (*(int *)(param_1 + 0x484) == 0) {
    iVar1 = *(int *)(param_1 + 0x4a0);
  }
  else {
    iVar1 = FUN_40971460(*(int *)(param_1 + 0x484),0xd55);
  }
  if (iVar1 != 0) goto LAB_40971d3c;
  if (param_2 == 4) {
LAB_40971cb8:
    param_2 = 3;
  }
  else if (param_2 == 0x11) {
    param_2 = 0xb;
  }
  else if (param_2 == 0x19) goto LAB_40971cb8;
  if (param_3 == 4) {
LAB_40971cd8:
    param_3 = 3;
  }
  else if (param_3 == 0x11) {
    param_3 = 0xb;
  }
  else if (param_3 == 0x19) goto LAB_40971cd8;
  if ((param_4 == 4) || (param_4 == 0x11)) {
    param_4 = 0xb;
  }
  else if (param_4 == 0x19) {
    param_4 = 3;
  }
  if ((uVar2 == 4) || (uVar2 == 0x11)) {
    uVar2 = 0xb;
  }
  else if (uVar2 == 0x19) {
    uVar2 = 3;
  }
LAB_40971d3c:
  if (param_4 == 4) {
    param_4 = 0xb;
  }
  *(uint *)(iVar3 + 8) =
       ((param_2 & 0xffffc01f ^ param_3 << 5) << 6 ^ *(uint *)(iVar3 + 8) & 0xfff0003f) & 0xff0fffff
       ^ ((uVar2 & 0xf) << 4 ^ param_4 & 0xf) << 0x10;
  return;
}



/* 40971dc0 FUN_40971dc0 */

/* Boundary evidence: original MIPS .pdata 40971dc0..40971e23. Semantic name remains unreviewed. */

int FUN_40971dc0(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_40971660(param_1,(undefined4 *)param_1);
  if (((iVar1 == 0) && (iVar1 = FUN_40971660(param_1,(undefined4 *)(param_1 + 0x24)), iVar1 == 0))
     && (iVar1 = FUN_40971660(param_1,(undefined4 *)(param_1 + 0x48)), iVar1 == 0)) {
    *(undefined4 *)(param_1 + 0x7c) = 0;
    iVar1 = 0;
  }
  return iVar1;
}



/* 40971e24 FUN_40971e24 */

/* Boundary evidence: original MIPS .pdata 40971e24..40971edf. Semantic name remains unreviewed. */

void FUN_40971e24(int param_1)

{
  int iVar1;
  int iStack00000010;
  int iStack00000014;
  
  FUN_40993370();
  iStack00000014 = -1;
  iStack00000010 = -1;
  if ((((*(int *)(param_1 + 8) == 0) ||
       (iVar1 = FUN_40971828(param_1,&stack0x00000014,&stack0x00000010,0x8ce0), iVar1 == 0x8cd5)) &&
      ((*(int *)(param_1 + 0x2c) == 0 ||
       (iVar1 = FUN_40971828(param_1 + 0x24,&stack0x00000014,&stack0x00000010,0x8d00),
       iVar1 == 0x8cd5)))) && (*(int *)(param_1 + 0x50) != 0)) {
    FUN_40971828(param_1 + 0x48,&stack0x00000014,&stack0x00000010,0x8d20);
  }
                    /* WARNING: Subroutine does not return */
  FUN_40993390(0x18);
}



/* 40971ee0 FUN_40971ee0 */

void FUN_40971ee0(int param_1,int param_2)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = *(int *)(param_1 + 0x504);
  *(uint *)(iVar3 + 0x40) = *(uint *)(iVar3 + 0x40) & 0xfffff7ff | param_2 << 0xb;
  if (param_2 != 0) {
    iVar2 = 1;
    if ((*(int *)(param_1 + 0x484) != 0) || (bVar1 = true, *(int *)(param_1 + 0x4b0) < 1)) {
      bVar1 = false;
    }
    if (((*(uint *)(*(int *)(param_1 + 0x504) + 0x40) & 0x20) != 0) && (bVar1)) goto LAB_40971f40;
  }
  iVar2 = 0;
LAB_40971f40:
  *(uint *)(iVar3 + 0x20) = *(uint *)(iVar3 + 0x20) & 0xfffffeff ^ iVar2 << 8;
  return;
}



/* 40971f60 FUN_40971f60 */

void FUN_40971f60(int param_1,int param_2)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = *(int *)(param_1 + 0x504);
  *(uint *)(iVar3 + 0x40) = *(uint *)(iVar3 + 0x40) & 0xfffffbff | param_2 << 10;
  if (param_2 != 0) {
    iVar2 = 1;
    if ((*(int *)(param_1 + 0x484) != 0) || (bVar1 = true, *(int *)(param_1 + 0x4b0) < 1)) {
      bVar1 = false;
    }
    if (((*(uint *)(*(int *)(param_1 + 0x504) + 0x40) & 0x20) != 0) && (bVar1)) goto LAB_40971fc0;
  }
  iVar2 = 0;
LAB_40971fc0:
  *(uint *)(iVar3 + 0x20) = *(uint *)(iVar3 + 0x20) & 0xffffff7f ^ iVar2 << 7;
  return;
}



/* 40971fe0 FUN_40971fe0 */

void FUN_40971fe0(int param_1)

{
  bool bVar1;
  uint uVar2;
  int iVar3;
  
  iVar3 = *(int *)(param_1 + 0x504);
  uVar2 = 1;
  if ((*(int *)(param_1 + 0x484) != 0) || (bVar1 = true, *(int *)(param_1 + 0x4b0) < 1)) {
    bVar1 = false;
  }
  if (((*(uint *)(iVar3 + 0x40) & 0x20) == 0) || (!bVar1)) {
    uVar2 = 0;
  }
  *(uint *)(iVar3 + 0x20) =
       ((uVar2 ^ uVar2 << 2) << 3 ^ *(uint *)(iVar3 + 0x20) & 0xffffffd7) & 0xffffffbf ^ uVar2 << 6;
  return;
}



/* 40972064 FUN_40972064 */

/* Boundary evidence: original MIPS .pdata 40972064..40972187. Semantic name remains unreviewed. */

void FUN_40972064(int param_1,undefined4 param_2,int param_3)

{
  bool bVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  
  iVar4 = *(int *)(param_1 + 0x504);
  *(undefined4 *)(iVar4 + 0x60) = param_2;
  *(char *)(iVar4 + 100) = (char)param_3;
  uVar3 = 0;
  if ((*(int *)(param_1 + 0x484) != 0) || (bVar1 = true, *(int *)(param_1 + 0x4b0) < 1)) {
    bVar1 = false;
  }
  if ((((*(uint *)(*(int *)(param_1 + 0x504) + 0x40) & 0x20) == 0) || (!bVar1)) ||
     ((*(uint *)(iVar4 + 0x40) & 0x40) == 0)) {
    param_2 = 0x3f800000;
    param_3 = 0;
  }
  iVar2 = __gts(param_2,0x3f600000);
  if (iVar2 != 0) {
    uVar3 = 8;
  }
  iVar2 = __gts(param_2,0x3f200000);
  if (iVar2 != 0) {
    uVar3 = uVar3 | 4;
  }
  iVar2 = __gts(param_2,0x3ec00000);
  if (iVar2 != 0) {
    uVar3 = uVar3 | 2;
  }
  iVar2 = __gts(param_2,0x3e000000);
  if (iVar2 != 0) {
    uVar3 = uVar3 | 1;
  }
  if (param_3 != 0) {
    uVar3 = uVar3 ^ 0xf;
  }
  *(uint *)(iVar4 + 0x20) = uVar3 << 0xc ^ *(uint *)(iVar4 + 0x20) & 0xffff0fff;
  return;
}



/* 40972188 FUN_40972188 */

/* Boundary evidence: original MIPS .pdata 40972188..409721e3. Semantic name remains unreviewed. */

void FUN_40972188(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0x504);
  *(char *)(iVar2 + 0x59) = (char)param_2;
  iVar1 = FUN_409719bc(param_1);
  if (iVar1 == 0) {
    param_2 = 0;
  }
  *(uint *)(iVar2 + 0x1c) = param_2 << 8 ^ *(uint *)(iVar2 + 0x1c) & 0xffff00ff;
  return;
}



/* 409721e4 FUN_409721e4 */

/* Boundary evidence: original MIPS .pdata 409721e4..4097223b. Semantic name remains unreviewed. */

void FUN_409721e4(int param_1,uint param_2)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0x504);
  *(char *)(iVar2 + 0x52) = (char)param_2;
  iVar1 = FUN_409719bc(param_1);
  if (iVar1 == 0) {
    param_2 = 0;
  }
  *(uint *)(iVar2 + 0x1c) = *(uint *)(iVar2 + 0x1c) & 0xffffff00 ^ param_2;
  return;
}



/* 4097223c FUN_4097223c */

/* Boundary evidence: original MIPS .pdata 4097223c..409722e3. Semantic name remains unreviewed. */

void FUN_4097223c(int param_1,uint param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0x504);
  *(char *)(iVar2 + 0x5a) = (char)param_2;
  *(char *)(iVar2 + 0x5b) = (char)param_3;
  *(char *)(iVar2 + 0x5c) = (char)param_4;
  iVar1 = FUN_409719bc(param_1);
  if (iVar1 == 0) {
    param_3 = 0;
    param_4 = 0;
  }
  *(uint *)(iVar2 + 0x18) =
       ((param_2 & 0xffffffc7 ^ param_3 << 3) << 3 ^ *(uint *)(iVar2 + 0x18) & 0xfffffe07) &
       0xfffff1ff ^ param_4 << 9;
  return;
}



/* 409722e4 FUN_409722e4 */

/* Boundary evidence: original MIPS .pdata 409722e4..4097238b. Semantic name remains unreviewed. */

void FUN_409722e4(int param_1,uint param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0x504);
  *(char *)(iVar2 + 0x53) = (char)param_2;
  *(char *)(iVar2 + 0x54) = (char)param_3;
  *(char *)(iVar2 + 0x55) = (char)param_4;
  iVar1 = FUN_409719bc(param_1);
  if (iVar1 == 0) {
    param_3 = 0;
    param_4 = 0;
  }
  *(uint *)(iVar2 + 0x14) =
       ((param_2 & 0xffffffc7 ^ param_3 << 3) << 3 ^ *(uint *)(iVar2 + 0x14) & 0xfffffe07) &
       0xfffff1ff ^ param_4 << 9;
  return;
}



/* 4097238c FUN_4097238c */

/* Boundary evidence: original MIPS .pdata 4097238c..4097243f. Semantic name remains unreviewed. */

void FUN_4097238c(int param_1,uint param_2,uint param_3,uint param_4)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  
  iVar3 = *(int *)(param_1 + 0x504);
  *(uint *)(iVar3 + 0x88) = param_4;
  *(char *)(iVar3 + 0x56) = (char)param_2;
  *(char *)(iVar3 + 0x57) = (char)param_3;
  *(char *)(iVar3 + 0x58) = (char)param_4;
  iVar1 = FUN_409719bc(param_1);
  if (iVar1 == 0) {
    param_2 = 7;
  }
  uVar2 = (*(uint *)(iVar3 + 0x18) & 0xfffffff8 ^ param_2) & 0xff00ffff ^
          (param_3 & param_4) << 0x10;
  *(uint *)(iVar3 + 0x18) = uVar2;
  *(uint *)(iVar3 + 0x18) = uVar2 & 0xffffff ^ (uint)*(byte *)(iVar3 + 0x51) << 0x18;
  return;
}



/* 40972440 FUN_40972440 */

/* Boundary evidence: original MIPS .pdata 40972440..409724f3. Semantic name remains unreviewed. */

void FUN_40972440(int param_1,uint param_2,uint param_3,uint param_4)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  
  iVar3 = *(int *)(param_1 + 0x504);
  *(uint *)(iVar3 + 0x84) = param_4;
  *(char *)(iVar3 + 0x4f) = (char)param_2;
  *(char *)(iVar3 + 0x50) = (char)param_3;
  *(char *)(iVar3 + 0x51) = (char)param_4;
  iVar1 = FUN_409719bc(param_1);
  if (iVar1 == 0) {
    param_2 = 7;
  }
  uVar2 = (*(uint *)(iVar3 + 0x14) & 0xfffffff8 ^ param_2) & 0xff00ffff ^
          (param_3 & param_4) << 0x10;
  *(uint *)(iVar3 + 0x14) = uVar2;
  *(uint *)(iVar3 + 0x14) = uVar2 & 0xffffff ^ (uint)*(byte *)(iVar3 + 0x51) << 0x18;
  return;
}



/* 409724f4 FUN_409724f4 */

/* Boundary evidence: original MIPS .pdata 409724f4..4097254f. Semantic name remains unreviewed. */

void FUN_409724f4(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0x504);
  *(char *)(iVar2 + 0x4d) = (char)param_2;
  iVar1 = FUN_40971ad4(param_1);
  if (iVar1 == 0) {
    param_2 = 7;
  }
  *(uint *)(iVar2 + 0xc) = param_2 << 1 ^ *(uint *)(iVar2 + 0xc) & 0xfffffff1;
  return;
}



/* 40972550 FUN_40972550 */

/* Boundary evidence: original MIPS .pdata 40972550..4097259f. Semantic name remains unreviewed. */

void FUN_40972550(int param_1,uint param_2)

{
  uint uVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0x504);
  *(char *)(iVar2 + 0x4e) = (char)param_2;
  uVar1 = FUN_40971ad4(param_1);
  *(uint *)(iVar2 + 0xc) = *(uint *)(iVar2 + 0xc) & 0xfffffffe ^ uVar1 & param_2;
  return;
}



/* 409725a0 FUN_409725a0 */

/* Boundary evidence: original MIPS .pdata 409725a0..409725eb. Semantic name remains unreviewed. */

void FUN_409725a0(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x504);
  *(uint *)(iVar1 + 0x40) = *(uint *)(iVar1 + 0x40) & 0xfffffffb | param_2 << 2;
  FUN_40971bec(param_1,(uint)*(byte *)(iVar1 + 0x48),(uint)*(byte *)(iVar1 + 0x49),
               (uint)*(byte *)(iVar1 + 0x4a),*(byte *)(iVar1 + 0x4b));
  return;
}



/* 409725ec FUN_409725ec */

/* Boundary evidence: original MIPS .pdata 409725ec..40972677. Semantic name remains unreviewed. */

void FUN_409725ec(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x504);
  *(uint *)(iVar1 + 0x40) = *(uint *)(iVar1 + 0x40) & 0xffffffdf | param_2 << 5;
  FUN_40971fe0(param_1);
  FUN_40972064(param_1,*(undefined4 *)(iVar1 + 0x60),(uint)*(byte *)(iVar1 + 100));
  FUN_40971ee0(param_1,*(uint *)(iVar1 + 0x40) >> 0xb & 1);
  FUN_40971f60(param_1,*(uint *)(iVar1 + 0x40) >> 10 & 1);
  return;
}



/* 40972678 FUN_40972678 */

/* Boundary evidence: original MIPS .pdata 40972678..4097272f. Semantic name remains unreviewed. */

void FUN_40972678(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x504);
  *(uint *)(iVar1 + 0x40) = *(uint *)(iVar1 + 0x40) & 0xffffffef | param_2 << 4;
  FUN_40972440(param_1,(uint)*(byte *)(iVar1 + 0x4f),(uint)*(byte *)(iVar1 + 0x50),
               (uint)*(byte *)(iVar1 + 0x51));
  FUN_409721e4(param_1,(uint)*(byte *)(iVar1 + 0x52));
  FUN_409722e4(param_1,(uint)*(byte *)(iVar1 + 0x53),(uint)*(byte *)(iVar1 + 0x54),
               (uint)*(byte *)(iVar1 + 0x55));
  FUN_4097238c(param_1,(uint)*(byte *)(iVar1 + 0x56),(uint)*(byte *)(iVar1 + 0x57),
               (uint)*(byte *)(iVar1 + 0x58));
  FUN_40972188(param_1,(uint)*(byte *)(iVar1 + 0x59));
  FUN_4097223c(param_1,(uint)*(byte *)(iVar1 + 0x5a),(uint)*(byte *)(iVar1 + 0x5b),
               (uint)*(byte *)(iVar1 + 0x5c));
  return;
}



/* 40972730 FUN_40972730 */

/* Boundary evidence: original MIPS .pdata 40972730..4097278f. Semantic name remains unreviewed. */

void FUN_40972730(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x504);
  *(uint *)(iVar1 + 0x40) = *(uint *)(iVar1 + 0x40) & 0xfffffffd | param_2 << 1;
  FUN_409724f4(param_1,(uint)*(byte *)(iVar1 + 0x4d));
  FUN_40972550(param_1,(uint)*(byte *)(iVar1 + 0x4e));
  return;
}



/* 40972790 FUN_40972790 */

/* Boundary evidence: original MIPS .pdata 40972790..4097283f. Semantic name remains unreviewed. */

void FUN_40972790(int param_1)

{
  int iVar1;
  
  FUN_40972730(param_1,*(uint *)(*(int *)(param_1 + 0x504) + 0x40) >> 1 & 1);
  FUN_40972678(param_1,*(uint *)(*(int *)(param_1 + 0x504) + 0x40) >> 4 & 1);
  iVar1 = *(int *)(param_1 + 0x504);
  *(uint *)(iVar1 + 0x40) =
       *(uint *)(iVar1 + 0x40) & 0xfffffffb | (*(uint *)(iVar1 + 0x40) >> 2 & 1) << 2;
  FUN_40971bec(param_1,(uint)*(byte *)(iVar1 + 0x48),(uint)*(byte *)(iVar1 + 0x49),
               (uint)*(byte *)(iVar1 + 0x4a),*(byte *)(iVar1 + 0x4b));
  FUN_409725ec(param_1,*(uint *)(*(int *)(param_1 + 0x504) + 0x40) >> 5 & 1);
  return;
}



/* 40972840 FUN_40972840 */

/* Boundary evidence: original MIPS .pdata 40972840..40972903. Semantic name remains unreviewed. */

undefined4 FUN_40972840(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0x484);
  if (*(int *)(iVar2 + 0x7c) == 1) {
    iVar1 = FUN_40971e24(iVar2);
    if (iVar1 != 0x8cd5) {
      return 0x506;
    }
    iVar1 = mali_frame_builder_flush(*(undefined4 *)(iVar2 + 0x6c),0,0);
    if ((iVar1 == 0) && (iVar1 = FUN_40971dc0(iVar2), iVar1 == 0)) {
      FUN_40972790(param_1);
      *(uint *)(param_1 + 0xc) = *(uint *)(param_1 + 0xc) | 0x2000000;
    }
    else if ((iVar1 != -3) && ((-3 < iVar1 && (iVar1 < 0)))) {
      return 0x505;
    }
  }
  return 0;
}



/* 40972904 FUN_40972904 */

/* Boundary evidence: original MIPS .pdata 40972904..40972957. Semantic name remains unreviewed. */

void FUN_40972904(void)

{
  int iVar1;
  int *piVar2;
  
  for (iVar1 = __mali_linked_list_get_first_entry(); iVar1 != 0;
      iVar1 = __mali_linked_list_get_next_entry(iVar1)) {
    piVar2 = *(int **)(iVar1 + 8);
    *(undefined4 *)(*piVar2 + 0x7c) = 1;
    *(undefined4 *)(piVar2[1] + 0x14) = 1;
  }
  return;
}



/* 40972958 FUN_40972958 */

/* Boundary evidence: original MIPS .pdata 40972958..40972973. Semantic name remains unreviewed. */

void FUN_40972958(void)

{
  __mali_linked_list_free();
  return;
}



/* 40972974 FUN_40972974 */

/* Boundary evidence: original MIPS .pdata 40972974..409729ab. Semantic name remains unreviewed. */

void FUN_40972974(int *param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  mali_mem_write(*(undefined4 *)(*(int *)*param_1 + 4),((int *)*param_1)[1] + param_2,param_4,
                 param_3);
  return;
}



/* 409729ac FUN_409729ac */

/* Boundary evidence: original MIPS .pdata 409729ac..40972e77. Semantic name remains unreviewed. */

void FUN_409729ac(int *param_1,int param_2,int param_3,uint param_4,short *param_5,int param_6,
                 short param_7)

{
  char cVar1;
  char cVar2;
  short sVar3;
  char cVar4;
  undefined4 uVar5;
  short *psVar6;
  int iVar7;
  short *psVar8;
  char *pcVar9;
  uint uVar10;
  uint uVar11;
  int iVar12;
  short *psVar13;
  uint uVar14;
  undefined2 local_310;
  char local_30e [254];
  short local_210 [256];
  uint local_10;
  
  local_10 = DAT_40996268;
  if (param_3 == 0x1403) {
    uVar10 = 0;
    uVar11 = uVar10;
    if (param_2 == 3) {
      if (1 < param_4) {
        psVar6 = local_210;
        psVar8 = param_5 + 1;
        iVar12 = param_4 - 1;
        do {
          *psVar6 = psVar8[-1] + param_7;
          psVar6[1] = *psVar8 + param_7;
          psVar8 = psVar8 + 1;
          prefetch(psVar8,0);
          uVar10 = uVar10 + 2;
          iVar12 = iVar12 + -1;
          psVar6 = psVar6 + 2;
          uVar11 = uVar10;
        } while (iVar12 != 0);
      }
    }
    else if (param_2 == 4) {
      if (param_4 != 0) {
        psVar6 = local_210;
        uVar10 = param_4;
        do {
          psVar8 = (short *)(((int)param_5 - (int)local_210) + (int)psVar6);
          prefetch(psVar8 + 1,0);
          *psVar6 = *psVar8 + param_7;
          uVar10 = uVar10 - 1;
          psVar6 = psVar6 + 1;
          uVar11 = param_4;
        } while (uVar10 != 0);
      }
    }
    else if (param_2 == 5) {
      uVar14 = 2;
      if (2 < param_4) {
        psVar8 = local_210;
        psVar6 = param_5;
        do {
          psVar13 = psVar6 + 2;
          *psVar8 = *param_5 + param_7;
          psVar8[1] = psVar6[1] + param_7;
          psVar8[2] = *psVar13 + param_7;
          uVar11 = uVar10 + 3;
          if (param_4 <= uVar14 + 1) break;
          sVar3 = param_5[1];
          psVar8[3] = *psVar13 + param_7;
          psVar8[4] = sVar3 + param_7;
          psVar8[5] = psVar6[3] + param_7;
          uVar14 = uVar14 + 2;
          param_5 = param_5 + 2;
          uVar10 = uVar10 + 6;
          psVar8 = psVar8 + 6;
          uVar11 = uVar10;
          psVar6 = psVar13;
        } while (uVar14 < param_4);
      }
    }
    else if ((param_2 == 6) && (2 < param_4)) {
      psVar6 = local_210;
      sVar3 = *param_5;
      psVar8 = param_5 + 2;
      iVar12 = param_4 - 2;
      do {
        *psVar6 = sVar3 + param_7;
        psVar6[1] = psVar8[-1] + param_7;
        psVar6[2] = *psVar8 + param_7;
        psVar8 = psVar8 + 1;
        prefetch(psVar8,0);
        uVar11 = uVar11 + 3;
        iVar12 = iVar12 + -1;
        psVar6 = psVar6 + 3;
      } while (iVar12 != 0);
    }
    iVar7 = uVar11 << 1;
    psVar6 = local_210;
    iVar12 = ((int *)*param_1)[1];
    uVar5 = *(undefined4 *)(*(int *)*param_1 + 4);
  }
  else {
    iVar12 = 0;
    cVar4 = (char)param_7;
    iVar7 = iVar12;
    if (param_2 == 3) {
      uVar11 = 1;
      if (1 < param_4) {
        do {
          prefetch(uVar11 + (int)param_5,0);
          cVar1 = *(char *)(uVar11 + (int)param_5);
          *(char *)((int)&local_310 + iVar12) = *(char *)(uVar11 + (int)param_5 + -1) + cVar4;
          prefetch((char *)(uVar11 + (int)param_5) + 1,0);
          iVar7 = iVar12 + 1;
          uVar11 = uVar11 + 1;
          iVar12 = iVar12 + 2;
          *(char *)((int)&local_310 + iVar7) = cVar1 + cVar4;
          iVar7 = iVar12;
        } while (uVar11 < param_4);
      }
    }
    else if (param_2 == 4) {
      for (; iVar7 = iVar12, param_4 != 0; param_4 = param_4 - 1) {
        *(char *)((int)&local_310 + iVar12) = *(char *)((int)param_5 + iVar12) + cVar4;
        iVar12 = iVar12 + 1;
      }
    }
    else if (param_2 == 5) {
      uVar11 = 2;
      if (2 < param_4) {
        do {
          cVar1 = *(char *)((int)param_5 + (uVar11 - 1));
          *(char *)((int)&local_310 + iVar12) = *(char *)((int)param_5 + (uVar11 - 2)) + cVar4;
          cVar2 = *(char *)(uVar11 + (int)param_5);
          *(char *)((int)&local_310 + iVar12 + 1) = cVar1 + cVar4;
          local_30e[iVar12] = cVar2 + cVar4;
          iVar7 = iVar12 + 3;
          if (param_4 <= uVar11 + 1) break;
          cVar1 = *(char *)((int)param_5 + (uVar11 - 1));
          local_30e[iVar12 + 1] = *(char *)((int)param_5 + uVar11) + cVar4;
          cVar2 = *(char *)(uVar11 + 1 + (int)param_5);
          local_30e[iVar12 + 2] = cVar1 + cVar4;
          iVar7 = iVar12 + 3;
          uVar11 = uVar11 + 2;
          iVar12 = iVar12 + 6;
          local_30e[iVar7] = cVar2 + cVar4;
          iVar7 = iVar12;
        } while (uVar11 < param_4);
      }
    }
    else if ((param_2 == 6) && (uVar11 = 2, 2 < param_4)) {
      sVar3 = *param_5;
      do {
        cVar1 = *(char *)(uVar11 + (int)param_5 + -1);
        prefetch(uVar11 + (int)param_5,0);
        *(char *)((int)&local_310 + iVar7) = (char)sVar3 + cVar4;
        prefetch((char *)(uVar11 + (int)param_5) + 1,0);
        cVar2 = *(char *)(uVar11 + (int)param_5);
        *(char *)((int)&local_310 + iVar7 + 1) = cVar1 + cVar4;
        pcVar9 = local_30e + iVar7;
        uVar11 = uVar11 + 1;
        iVar7 = iVar7 + 3;
        *pcVar9 = cVar2 + cVar4;
      } while (uVar11 < param_4);
    }
    psVar6 = &local_310;
    iVar12 = ((int *)*param_1)[1];
    uVar5 = *(undefined4 *)(*(int *)*param_1 + 4);
  }
  mali_mem_write(uVar5,iVar12 + param_6,psVar6,iVar7);
  FUN_40963898(local_10);
  return;
}



/* 40972e78 FUN_40972e78 */

/* Boundary evidence: original MIPS .pdata 40972e78..40973073. Semantic name remains unreviewed. */

void FUN_40972e78(int *param_1,int param_2,uint param_3,int param_4,short param_5)

{
  short *psVar1;
  uint uVar2;
  uint uVar3;
  short sVar4;
  short sVar5;
  int iVar6;
  uint uVar7;
  short local_210 [256];
  uint local_10;
  
  local_10 = DAT_40996268;
  uVar2 = 0;
  uVar3 = uVar2;
  if (param_2 == 3) {
    if (1 < param_3) {
      iVar6 = param_3 - 1;
      psVar1 = local_210;
      do {
        *psVar1 = param_5;
        psVar1[1] = param_5 + 1;
        uVar2 = uVar2 + 2;
        psVar1 = psVar1 + 2;
        iVar6 = iVar6 + -1;
        param_5 = param_5 + 1;
        uVar3 = uVar2;
      } while (iVar6 != 0);
    }
  }
  else if (param_2 == 4) {
    uVar2 = 0;
    uVar3 = param_3;
    if (param_3 != 0) {
      psVar1 = local_210;
      do {
        sVar4 = (short)uVar2;
        uVar2 = uVar2 + 1;
        *psVar1 = sVar4 + param_5;
        psVar1 = psVar1 + 1;
      } while (uVar2 < param_3);
    }
  }
  else if (param_2 == 5) {
    uVar7 = 2;
    if (2 < param_3) {
      psVar1 = local_210;
      sVar4 = param_5;
      sVar5 = param_5;
      do {
        *psVar1 = sVar5;
        psVar1[1] = param_5 + 1;
        psVar1[2] = sVar4 + 2;
        param_5 = param_5 + 2;
        uVar3 = uVar2 + 3;
        if (param_3 <= uVar7 + 1) break;
        psVar1[3] = param_5;
        psVar1[4] = sVar5 + 1;
        uVar7 = uVar7 + 2;
        psVar1[5] = sVar4 + 3;
        uVar2 = uVar2 + 6;
        psVar1 = psVar1 + 6;
        sVar5 = sVar5 + 2;
        uVar3 = uVar2;
        sVar4 = sVar4 + 2;
      } while (uVar7 < param_3);
    }
  }
  else if ((param_2 == 6) && (2 < param_3)) {
    sVar4 = param_5 + 2;
    psVar1 = local_210;
    iVar6 = param_3 - 2;
    do {
      *psVar1 = param_5;
      psVar1[1] = sVar4 + -1;
      psVar1[2] = sVar4;
      uVar3 = uVar3 + 3;
      psVar1 = psVar1 + 3;
      iVar6 = iVar6 + -1;
      sVar4 = sVar4 + 1;
    } while (iVar6 != 0);
  }
  mali_mem_write(*(undefined4 *)(*(int *)*param_1 + 4),((int *)*param_1)[1] + param_4,local_210,
                 uVar3 << 1);
  FUN_40963898(local_10);
  return;
}



/* 40973074 FUN_40973074 */

/* Boundary evidence: original MIPS .pdata 40973074..40973163. Semantic name remains unreviewed. */

void FUN_40973074(int *param_1,int param_2,int param_3,uint param_4)

{
  int iVar1;
  undefined1 *puVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  int in_stack_00000848;
  
  FUN_40993300();
  iVar3 = *(int *)(in_stack_00000848 + 8);
  iVar1 = FUN_409769fc(*(uint *)(in_stack_00000848 + 0xc));
  iVar1 = iVar1 * *(int *)(in_stack_00000848 + 4);
  if (iVar1 == iVar3) {
    mali_mem_write(*(undefined4 *)(*(int *)*param_1 + 4),((int *)*param_1)[1] + param_3,
                   *(int *)(in_stack_00000848 + 0x14) + iVar3 * param_2,iVar3 * param_4);
  }
  else {
    iVar3 = *(int *)(in_stack_00000848 + 0x14) + iVar3 * param_2;
    for (; param_4 != 0; param_4 = param_4 - uVar4) {
      uVar4 = param_4;
      if (0x80 < param_4) {
        uVar4 = 0x80;
      }
      puVar2 = &stack0x00000010;
      for (uVar5 = uVar4; uVar5 != 0; uVar5 = uVar5 - 1) {
        mali_sys_memcpy(puVar2,iVar3,iVar1);
        puVar2 = puVar2 + iVar1;
        iVar3 = iVar3 + *(int *)(in_stack_00000848 + 8);
      }
      mali_mem_write(*(undefined4 *)(*(int *)*param_1 + 4),((int *)*param_1)[1] + param_3,
                     &stack0x00000010,uVar4 * iVar1);
      param_3 = uVar4 * iVar1 + param_3;
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_40993338(0x810);
}



/* 409731dc FUN_409731dc */

/* Boundary evidence: original MIPS .pdata 409731dc..409732ff. Semantic name remains unreviewed. */

void FUN_409731dc(int param_1,undefined4 param_2,int param_3)

{
  bool bVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  
  iVar4 = *(int *)(param_1 + 0x504);
  *(undefined4 *)(iVar4 + 0x60) = param_2;
  *(char *)(iVar4 + 100) = (char)param_3;
  uVar3 = 0;
  if ((*(int *)(param_1 + 0x484) != 0) || (bVar1 = true, *(int *)(param_1 + 0x4b0) < 1)) {
    bVar1 = false;
  }
  if ((((*(uint *)(*(int *)(param_1 + 0x504) + 0x40) & 0x20) == 0) || (!bVar1)) ||
     ((*(uint *)(iVar4 + 0x40) & 0x40) == 0)) {
    param_2 = 0x3f800000;
    param_3 = 0;
  }
  iVar2 = __gts(param_2,0x3f600000);
  if (iVar2 != 0) {
    uVar3 = 8;
  }
  iVar2 = __gts(param_2,0x3f200000);
  if (iVar2 != 0) {
    uVar3 = uVar3 | 4;
  }
  iVar2 = __gts(param_2,0x3ec00000);
  if (iVar2 != 0) {
    uVar3 = uVar3 | 2;
  }
  iVar2 = __gts(param_2,0x3e000000);
  if (iVar2 != 0) {
    uVar3 = uVar3 | 1;
  }
  if (param_3 != 0) {
    uVar3 = uVar3 ^ 0xf;
  }
  *(uint *)(iVar4 + 0x20) = uVar3 << 0xc ^ *(uint *)(iVar4 + 0x20) & 0xffff0fff;
  return;
}



/* 40973300 FUN_40973300 */

/* Boundary evidence: original MIPS .pdata 40973300..4097338f. Semantic name remains unreviewed. */

void FUN_40973300(int param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = __lts(param_2,0);
  if (iVar1 == 0) {
    iVar1 = __gts(param_2,0x3f800000);
    uVar2 = 0x3f800000;
    if (iVar1 == 0) {
      uVar2 = param_2;
    }
  }
  else {
    uVar2 = 0;
  }
  FUN_409731dc(param_1,uVar2,(uint)(param_3 != 0));
  return;
}



/* 40973390 FUN_40973390 */

/* Boundary evidence: original MIPS .pdata 40973390..4097341f. Semantic name remains unreviewed. */

void FUN_40973390(int param_1)

{
  __mali_program_binary_state_reset(param_1);
  if (*(int *)(param_1 + 0x174) != 0) {
    mali_sys_free();
    *(undefined4 *)(param_1 + 0x174) = 0;
  }
  if (*(int *)(param_1 + 0x178) != 0) {
    mali_sys_free();
    *(undefined4 *)(param_1 + 0x178) = 0;
  }
  if (*(int *)(param_1 + 0x138) != 0) {
    mali_sys_free();
    *(undefined4 *)(param_1 + 0x138) = 0;
  }
  if (*(int *)(param_1 + 0x17c) != 0) {
    mali_sys_free();
    *(undefined4 *)(param_1 + 0x17c) = 0;
  }
  mali_sys_free(param_1);
  return;
}



/* 40973420 FUN_40973420 */

/* Boundary evidence: original MIPS .pdata 40973420..409734ff. Semantic name remains unreviewed. */

int FUN_40973420(void)

{
  int iVar1;
  undefined4 *puVar2;
  
  iVar1 = mali_sys_malloc(0x184);
  if (iVar1 == 0) {
    iVar1 = 0;
  }
  else {
    mali_sys_memset(iVar1,0,0x184);
    __mali_program_binary_state_init(iVar1);
    *(undefined4 *)(iVar1 + 0x138) = 0;
    *(undefined4 *)(iVar1 + 0x13c) = 0;
    *(undefined4 *)(iVar1 + 0x140) = 0xffffffff;
    *(undefined4 *)(iVar1 + 0x144) = 0xffffffff;
    *(undefined4 *)(iVar1 + 0x14c) = 0xffffffff;
    *(undefined4 *)(iVar1 + 0x148) = 0xffffffff;
    *(undefined4 *)(iVar1 + 0x150) = 0xffffffff;
    *(undefined4 *)(iVar1 + 0x154) = 0xffffffff;
    *(undefined4 *)(iVar1 + 0x158) = 0xffffffff;
    *(undefined4 *)(iVar1 + 0x15c) = 0xffffffff;
    *(undefined4 *)(iVar1 + 0x160) = 0xffffffff;
    *(undefined4 *)(iVar1 + 0x164) = 0xffffffff;
    *(undefined4 *)(iVar1 + 0x168) = 0xffffffff;
    *(undefined4 *)(iVar1 + 0x16c) = 0;
    *(undefined4 *)(iVar1 + 0x170) = 0;
    *(undefined4 *)(iVar1 + 0x174) = 0;
    *(undefined4 *)(iVar1 + 0x178) = 0;
    mali_sys_atomic_initialize(iVar1 + 0x180,1);
    puVar2 = (undefined4 *)(iVar1 + 0xb8);
    do {
      *puVar2 = 0xffffffff;
      puVar2 = puVar2 + 1;
    } while (puVar2 != (undefined4 *)(iVar1 + 0xf8));
    puVar2 = (undefined4 *)(iVar1 + 0xf8);
    do {
      *puVar2 = 0xffffffff;
      puVar2 = puVar2 + 1;
    } while (puVar2 != (undefined4 *)(iVar1 + 0x138));
  }
  return iVar1;
}



/* 40973500 FUN_40973500 */

/* Boundary evidence: original MIPS .pdata 40973500..40973537. Semantic name remains unreviewed. */

void FUN_40973500(int param_1)

{
  int iVar1;
  
  iVar1 = mali_sys_atomic_dec_and_return(param_1 + 0x180);
  if (iVar1 == 0) {
    FUN_40973390(param_1);
  }
  return;
}



/* 40973584 FUN_40973584 */

/* Boundary evidence: original MIPS .pdata 40973584..40973663. Semantic name remains unreviewed. */

int FUN_40973584(int *param_1,uint param_2)

{
  int iVar1;
  
  if (*param_1 != 0) {
    iVar1 = FUN_40971460(*param_1,param_2);
    return iVar1;
  }
  if (param_2 < 0xd57) {
    if (param_2 == 0xd56) {
      return param_1[8];
    }
    if (param_2 == 0xd52) {
      return param_1[4];
    }
    if (param_2 == 0xd53) {
      return param_1[5];
    }
    if (param_2 == 0xd54) {
      return param_1[6];
    }
    if (param_2 == 0xd55) {
      return param_1[7];
    }
  }
  else {
    if (param_2 == 0xd57) {
      return param_1[9];
    }
    if (param_2 == 0x80a8) {
      return param_1[0xb];
    }
    if (param_2 == 0x80a9) {
      return param_1[10];
    }
  }
  return 0;
}



/* 4097366c FUN_4097366c */

/* Boundary evidence: original MIPS .pdata 4097366c..409736c3. Semantic name remains unreviewed. */

void FUN_4097366c(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  FUN_40993370();
  iVar1 = __lts(param_2,0);
  if (iVar1 == 0) {
    iVar1 = __gts(param_2,0x3f800000);
    uVar2 = 0x3f800000;
    if (iVar1 == 0) {
      uVar2 = param_2;
    }
  }
  else {
    uVar2 = 0;
  }
  *(undefined4 *)(param_1 + 0x1c) = uVar2;
                    /* WARNING: Subroutine does not return */
  FUN_40993390(0x10);
}



/* 409736c4 FUN_409736c4 */

/* Boundary evidence: original MIPS .pdata 409736c4..409737cb. Semantic name remains unreviewed. */

void FUN_409736c4(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 in_stack_00000038;
  
  FUN_40993230();
  iVar1 = __lts(param_2,0);
  if (iVar1 == 0) {
    iVar1 = __gts(param_2,0x3f800000);
    if (iVar1 != 0) {
      param_2 = 0x3f800000;
    }
  }
  else {
    param_2 = 0;
  }
  *(undefined4 *)(param_1 + 0xc) = param_2;
  iVar1 = __lts(param_3,0);
  if (iVar1 == 0) {
    iVar1 = __gts(param_3,0x3f800000);
    if (iVar1 != 0) {
      param_3 = 0x3f800000;
    }
  }
  else {
    param_3 = 0;
  }
  *(undefined4 *)(param_1 + 0x10) = param_3;
  iVar1 = __lts(param_4,0);
  if (iVar1 == 0) {
    iVar1 = __gts(param_4,0x3f800000);
    if (iVar1 != 0) {
      param_4 = 0x3f800000;
    }
  }
  else {
    param_4 = 0;
  }
  *(undefined4 *)(param_1 + 0x14) = param_4;
  iVar1 = __lts(in_stack_00000038,0);
  if (iVar1 == 0) {
    iVar1 = __gts(in_stack_00000038,0x3f800000);
    uVar2 = 0x3f800000;
    if (iVar1 == 0) {
      uVar2 = in_stack_00000038;
    }
  }
  else {
    uVar2 = 0;
  }
  *(undefined4 *)(param_1 + 0x18) = uVar2;
                    /* WARNING: Subroutine does not return */
  FUN_40993258(0x10);
}



/* 40973808 FUN_40973808 */

/* Boundary evidence: original MIPS .pdata 40973808..4097391f. Semantic name remains unreviewed. */

undefined4 FUN_40973808(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int *piVar4;
  int local_28;
  undefined1 auStack_24 [4];
  undefined1 auStack_20 [4];
  undefined1 auStack_1c [4];
  undefined1 auStack_18 [4];
  undefined1 auStack_14 [4];
  
  iVar3 = *(int *)(param_1 + 0x484);
  if (iVar3 == 0) {
    local_28 = *(int *)(param_1 + 0x4a8);
    goto LAB_409738dc;
  }
  if (iVar3 != -0x48) {
    if (*(int *)(iVar3 + 0x50) == 0x1702) {
      iVar1 = FUN_40979e34(*(int *)(iVar3 + 100));
      piVar4 = *(int **)((iVar1 * 0xd + *(int *)(iVar3 + 0x60)) * 4 +
                        *(int *)(*(int *)(iVar3 + 0x58) + 0x34));
      if (piVar4 != (int *)0x0) {
        iVar3 = *piVar4;
        goto LAB_40973894;
      }
    }
    else if (*(int *)(iVar3 + 0x50) == 0x8d41) {
      iVar3 = *(int *)(*(int *)(iVar3 + 0x58) + 0x28);
LAB_40973894:
      if (iVar3 != 0) {
        mali_pixel_format_get_bpc
                  (*(undefined4 *)(iVar3 + 0x14),auStack_14,auStack_18,auStack_1c,auStack_20,
                   auStack_24,&local_28);
        goto LAB_409738dc;
      }
    }
  }
  local_28 = 0;
LAB_409738dc:
  uVar2 = 1;
  if (((*(uint *)(*(int *)(param_1 + 0x504) + 0x40) & 0x10) == 0) || (local_28 < 1)) {
    uVar2 = 0;
  }
  return uVar2;
}



/* 40973920 FUN_40973920 */

/* Boundary evidence: original MIPS .pdata 40973920..40973a37. Semantic name remains unreviewed. */

undefined4 FUN_40973920(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int *piVar4;
  int local_28;
  undefined1 auStack_24 [4];
  undefined1 auStack_20 [4];
  undefined1 auStack_1c [4];
  undefined1 auStack_18 [4];
  undefined1 auStack_14 [4];
  
  iVar3 = *(int *)(param_1 + 0x484);
  if (iVar3 == 0) {
    local_28 = *(int *)(param_1 + 0x4a4);
    goto LAB_409739f4;
  }
  if (iVar3 != -0x24) {
    if (*(int *)(iVar3 + 0x2c) == 0x1702) {
      iVar1 = FUN_40979e34(*(int *)(iVar3 + 0x40));
      piVar4 = *(int **)((iVar1 * 0xd + *(int *)(iVar3 + 0x3c)) * 4 +
                        *(int *)(*(int *)(iVar3 + 0x34) + 0x34));
      if (piVar4 != (int *)0x0) {
        iVar3 = *piVar4;
        goto LAB_409739ac;
      }
    }
    else if (*(int *)(iVar3 + 0x2c) == 0x8d41) {
      iVar3 = *(int *)(*(int *)(iVar3 + 0x34) + 0x28);
LAB_409739ac:
      if (iVar3 != 0) {
        mali_pixel_format_get_bpc
                  (*(undefined4 *)(iVar3 + 0x14),auStack_14,auStack_18,auStack_1c,auStack_20,
                   &local_28,auStack_24);
        goto LAB_409739f4;
      }
    }
  }
  local_28 = 0;
LAB_409739f4:
  uVar2 = 1;
  if (((*(uint *)(*(int *)(param_1 + 0x504) + 0x40) & 2) == 0) || (local_28 < 1)) {
    uVar2 = 0;
  }
  return uVar2;
}



/* 40973a8c FUN_40973a8c */

void FUN_40973a8c(int param_1,int param_2,int param_3,int param_4,char param_5)

{
  *(bool *)(param_1 + 0x456) = param_4 != 0;
  *(bool *)(param_1 + 0x457) = param_5 != '\0';
  *(bool *)(param_1 + 0x455) = param_3 != 0;
  *(bool *)(param_1 + 0x454) = param_2 != 0;
  *(uint *)(*(int *)(param_1 + 0x504) + 8) =
       ((uint)(param_4 != 0) << 1 ^ (uint)(param_3 != 0)) << 0x1d ^
       *(uint *)(*(int *)(param_1 + 0x504) + 8) & 0xfffffff ^
       ((uint)(param_5 != '\0') << 3 ^ (uint)(param_2 != 0)) << 0x1c;
  return;
}



/* 40973b24 FUN_40973b24 */

/* Boundary evidence: original MIPS .pdata 40973b24..40973b7f. Semantic name remains unreviewed. */

void FUN_40973b24(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0x504);
  *(char *)(iVar2 + 0x59) = (char)param_2;
  iVar1 = FUN_40973808(param_1);
  if (iVar1 == 0) {
    param_2 = 0;
  }
  *(uint *)(iVar2 + 0x1c) = param_2 << 8 ^ *(uint *)(iVar2 + 0x1c) & 0xffff00ff;
  return;
}



/* 40973b80 FUN_40973b80 */

/* Boundary evidence: original MIPS .pdata 40973b80..40973bd7. Semantic name remains unreviewed. */

void FUN_40973b80(int param_1,uint param_2)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0x504);
  *(char *)(iVar2 + 0x52) = (char)param_2;
  iVar1 = FUN_40973808(param_1);
  if (iVar1 == 0) {
    param_2 = 0;
  }
  *(uint *)(iVar2 + 0x1c) = *(uint *)(iVar2 + 0x1c) & 0xffffff00 ^ param_2;
  return;
}



/* 40973bd8 FUN_40973bd8 */

/* Boundary evidence: original MIPS .pdata 40973bd8..40973c27. Semantic name remains unreviewed. */

void FUN_40973bd8(int param_1,uint param_2)

{
  uint uVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0x504);
  *(char *)(iVar2 + 0x4e) = (char)param_2;
  uVar1 = FUN_40973920(param_1);
  *(uint *)(iVar2 + 0xc) = *(uint *)(iVar2 + 0xc) & 0xfffffffe ^ uVar1 & param_2;
  return;
}



/* 40973c28 FUN_40973c28 */

/* Boundary evidence: original MIPS .pdata 40973c28..40973ccf. Semantic name remains unreviewed. */

void FUN_40973c28(int param_1,int param_2,uint param_3,undefined4 param_4,int param_5,
                 undefined4 param_6,undefined4 param_7)

{
  int *piVar1;
  uint uVar2;
  
  FUN_40993230();
  param_5 = 0x404;
  param_6 = 0x405;
  uVar2 = 0;
  param_7 = 0x408;
  piVar1 = &param_5;
  do {
    if (param_2 == *piVar1) {
      uVar2 = param_3 & 0xff;
      if ((param_2 == 0x404) || (param_2 == 0x408)) {
        *(uint *)(param_1 + 0x45c) = uVar2;
        FUN_40973b80(param_1,uVar2);
      }
      if ((param_2 == 0x405) || (param_2 == 0x408)) {
        *(uint *)(param_1 + 0x478) = uVar2;
        FUN_40973b24(param_1,uVar2);
      }
      break;
    }
    uVar2 = uVar2 + 1;
    prefetch(piVar1 + 2,0);
    piVar1 = piVar1 + 1;
  } while (uVar2 < 3);
                    /* WARNING: Subroutine does not return */
  FUN_40993258(0x20);
}



/* 40973cd0 FUN_40973cd0 */

/* Boundary evidence: original MIPS .pdata 40973cd0..40973cff. Semantic name remains unreviewed. */

void FUN_40973cd0(int param_1,int param_2)

{
  *(bool *)(param_1 + 0x458) = param_2 != 0;
  FUN_40973bd8(param_1,(uint)(param_2 != 0));
  return;
}



/* 40973d00 FUN_40973d00 */

/* Boundary evidence: original MIPS .pdata 40973d00..40973d7f. Semantic name remains unreviewed. */

void FUN_40973d00(int param_1)

{
  undefined4 uVar1;
  int in_stack_00000010;
  undefined4 in_stack_00000014;
  undefined4 in_stack_00000018;
  
  FUN_40993370();
  uVar1 = 1;
  in_stack_00000010 = CONCAT31(in_stack_00000010._1_3_,1);
  FUN_40973a8c(param_1,1,1,1,'\x01');
  *(undefined1 *)(param_1 + 0x458) = 1;
  FUN_40973bd8(param_1,1);
  FUN_40973c28(param_1,0x408,0xff,uVar1,in_stack_00000010,in_stack_00000014,in_stack_00000018);
  FUN_409736c4(param_1 + 0x454,0,0,0);
  FUN_4097366c(param_1 + 0x454,0x3f800000);
  *(undefined4 *)(param_1 + 0x474) = 0;
                    /* WARNING: Subroutine does not return */
  FUN_40993390(0x18);
}



/* 40973d90 FUN_40973d90 */

/* Boundary evidence: original MIPS .pdata 40973d90..40973e2f. Semantic name remains unreviewed. */

undefined1 FUN_40973d90(undefined4 param_1)

{
  undefined1 uVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar2 = __lts(param_1,0xc1fe0000);
  if (iVar2 == 0) {
    iVar2 = __gts(param_1,0x41fe0000);
    if (iVar2 == 0) {
      iVar2 = __lts(param_1,0x3e800000);
      if ((iVar2 == 0) || (iVar2 = __gts(param_1,0xbe800000), iVar2 == 0)) {
        uVar3 = __fpmul(param_1,0x40800000);
        uVar1 = __fptoli(uVar3);
      }
      else {
        uVar1 = 0;
      }
    }
    else {
      uVar1 = 0x7f;
    }
  }
  else {
    uVar1 = 0x80;
  }
  return uVar1;
}



/* 40973e30 FUN_40973e30 */

/* Boundary evidence: original MIPS .pdata 40973e30..40973e67. Semantic name remains unreviewed. */

void FUN_40973e30(int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined1 uVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0x504);
  *(undefined4 *)(iVar2 + 0x7c) = param_2;
  *(undefined4 *)(iVar2 + 0x80) = param_3;
  uVar1 = FUN_40973d90(param_2);
  *(undefined1 *)(iVar2 + 0x65) = uVar1;
  *(undefined1 *)(iVar2 + 0x66) = 0;
  return;
}



/* 40973e68 FUN_40973e68 */

/* Boundary evidence: original MIPS .pdata 40973e68..40973ea3. Semantic name remains unreviewed. */

undefined4 FUN_40973e68(int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined1 uVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0x504);
  *(undefined4 *)(iVar2 + 0x7c) = param_2;
  *(undefined4 *)(iVar2 + 0x80) = param_3;
  uVar1 = FUN_40973d90(param_2);
  *(undefined1 *)(iVar2 + 0x65) = uVar1;
  *(undefined1 *)(iVar2 + 0x66) = 0;
  return 0;
}



/* 40973f94 FUN_40973f94 */

/* Boundary evidence: original MIPS .pdata 40973f94..409740ab. Semantic name remains unreviewed. */

undefined4 FUN_40973f94(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int *piVar4;
  int local_28;
  undefined1 auStack_24 [4];
  undefined1 auStack_20 [4];
  undefined1 auStack_1c [4];
  undefined1 auStack_18 [4];
  undefined1 auStack_14 [4];
  
  iVar3 = *(int *)(param_1 + 0x484);
  if (iVar3 == 0) {
    local_28 = *(int *)(param_1 + 0x4a8);
    goto LAB_40974068;
  }
  if (iVar3 != -0x48) {
    if (*(int *)(iVar3 + 0x50) == 0x1702) {
      iVar1 = FUN_40979e34(*(int *)(iVar3 + 100));
      piVar4 = *(int **)((iVar1 * 0xd + *(int *)(iVar3 + 0x60)) * 4 +
                        *(int *)(*(int *)(iVar3 + 0x58) + 0x34));
      if (piVar4 != (int *)0x0) {
        iVar3 = *piVar4;
        goto LAB_40974020;
      }
    }
    else if (*(int *)(iVar3 + 0x50) == 0x8d41) {
      iVar3 = *(int *)(*(int *)(iVar3 + 0x58) + 0x28);
LAB_40974020:
      if (iVar3 != 0) {
        mali_pixel_format_get_bpc
                  (*(undefined4 *)(iVar3 + 0x14),auStack_14,auStack_18,auStack_1c,auStack_20,
                   auStack_24,&local_28);
        goto LAB_40974068;
      }
    }
  }
  local_28 = 0;
LAB_40974068:
  uVar2 = 1;
  if (((*(uint *)(*(int *)(param_1 + 0x504) + 0x40) & 0x10) == 0) || (local_28 < 1)) {
    uVar2 = 0;
  }
  return uVar2;
}



/* 409740ac FUN_409740ac */

/* Boundary evidence: original MIPS .pdata 409740ac..409741c3. Semantic name remains unreviewed. */

undefined4 FUN_409740ac(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int *piVar4;
  int local_28;
  undefined1 auStack_24 [4];
  undefined1 auStack_20 [4];
  undefined1 auStack_1c [4];
  undefined1 auStack_18 [4];
  undefined1 auStack_14 [4];
  
  iVar3 = *(int *)(param_1 + 0x484);
  if (iVar3 == 0) {
    local_28 = *(int *)(param_1 + 0x4a4);
    goto LAB_40974180;
  }
  if (iVar3 != -0x24) {
    if (*(int *)(iVar3 + 0x2c) == 0x1702) {
      iVar1 = FUN_40979e34(*(int *)(iVar3 + 0x40));
      piVar4 = *(int **)((iVar1 * 0xd + *(int *)(iVar3 + 0x3c)) * 4 +
                        *(int *)(*(int *)(iVar3 + 0x34) + 0x34));
      if (piVar4 != (int *)0x0) {
        iVar3 = *piVar4;
        goto LAB_40974138;
      }
    }
    else if (*(int *)(iVar3 + 0x2c) == 0x8d41) {
      iVar3 = *(int *)(*(int *)(iVar3 + 0x34) + 0x28);
LAB_40974138:
      if (iVar3 != 0) {
        mali_pixel_format_get_bpc
                  (*(undefined4 *)(iVar3 + 0x14),auStack_14,auStack_18,auStack_1c,auStack_20,
                   &local_28,auStack_24);
        goto LAB_40974180;
      }
    }
  }
  local_28 = 0;
LAB_40974180:
  uVar2 = 1;
  if (((*(uint *)(*(int *)(param_1 + 0x504) + 0x40) & 2) == 0) || (local_28 < 1)) {
    uVar2 = 0;
  }
  return uVar2;
}



/* 409741c4 FUN_409741c4 */

/* Boundary evidence: original MIPS .pdata 409741c4..40974277. Semantic name remains unreviewed. */

void FUN_409741c4(int param_1,uint param_2,uint param_3,uint param_4)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  
  iVar3 = *(int *)(param_1 + 0x504);
  *(uint *)(iVar3 + 0x88) = param_4;
  *(char *)(iVar3 + 0x56) = (char)param_2;
  *(char *)(iVar3 + 0x57) = (char)param_3;
  *(char *)(iVar3 + 0x58) = (char)param_4;
  iVar1 = FUN_40973f94(param_1);
  if (iVar1 == 0) {
    param_2 = 7;
  }
  uVar2 = (*(uint *)(iVar3 + 0x18) & 0xfffffff8 ^ param_2) & 0xff00ffff ^
          (param_3 & param_4) << 0x10;
  *(uint *)(iVar3 + 0x18) = uVar2;
  *(uint *)(iVar3 + 0x18) = uVar2 & 0xffffff ^ (uint)*(byte *)(iVar3 + 0x51) << 0x18;
  return;
}



/* 40974278 FUN_40974278 */

/* Boundary evidence: original MIPS .pdata 40974278..4097432b. Semantic name remains unreviewed. */

void FUN_40974278(int param_1,uint param_2,uint param_3,uint param_4)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  
  iVar3 = *(int *)(param_1 + 0x504);
  *(uint *)(iVar3 + 0x84) = param_4;
  *(char *)(iVar3 + 0x4f) = (char)param_2;
  *(char *)(iVar3 + 0x50) = (char)param_3;
  *(char *)(iVar3 + 0x51) = (char)param_4;
  iVar1 = FUN_40973f94(param_1);
  if (iVar1 == 0) {
    param_2 = 7;
  }
  uVar2 = (*(uint *)(iVar3 + 0x14) & 0xfffffff8 ^ param_2) & 0xff00ffff ^
          (param_3 & param_4) << 0x10;
  *(uint *)(iVar3 + 0x14) = uVar2;
  *(uint *)(iVar3 + 0x14) = uVar2 & 0xffffff ^ (uint)*(byte *)(iVar3 + 0x51) << 0x18;
  return;
}



/* 4097432c FUN_4097432c */

/* Boundary evidence: original MIPS .pdata 4097432c..40974387. Semantic name remains unreviewed. */

void FUN_4097432c(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0x504);
  *(char *)(iVar2 + 0x4d) = (char)param_2;
  iVar1 = FUN_409740ac(param_1);
  if (iVar1 == 0) {
    param_2 = 7;
  }
  *(uint *)(iVar2 + 0xc) = param_2 << 1 ^ *(uint *)(iVar2 + 0xc) & 0xfffffff1;
  return;
}



/* 40974388 FUN_40974388 */

/* Boundary evidence: original MIPS .pdata 40974388..409743f3. Semantic name remains unreviewed. */

undefined4 FUN_40974388(int param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = 0;
  do {
    if (param_2 == *(int *)((int)&DAT_4096258c + uVar2)) {
      iVar1 = FUN_4096c25c(param_2);
      FUN_4097432c(param_1,iVar1);
      return 0;
    }
    uVar2 = uVar2 + 4;
  } while (uVar2 < 0x20);
  return 0x500;
}



/* 409743f4 FUN_409743f4 */

/* Boundary evidence: original MIPS .pdata 409743f4..4097452b. Semantic name remains unreviewed. */

undefined4 FUN_409743f4(int param_1,int param_2,int param_3,uint param_4,uint param_5)

{
  uint uVar1;
  
  uVar1 = 0;
  while (param_3 != *(int *)((int)&DAT_4096258c + uVar1)) {
    uVar1 = uVar1 + 4;
    if (0x1f < uVar1) {
      return 0x500;
    }
  }
  uVar1 = 0;
  do {
    if (param_2 == *(int *)((int)&DAT_409625b0 + uVar1)) {
      uVar1 = FUN_4096c25c(param_3);
      if ((int)param_4 < 0) {
        param_4 = 0;
      }
      else if (0xff < (int)param_4) {
        param_4 = 0xff;
      }
      if ((param_2 == 0x404) || (param_2 == 0x408)) {
        FUN_40974278(param_1,uVar1,param_4 & 0xff,param_5);
      }
      if ((param_2 == 0x405) || (param_2 == 0x408)) {
        FUN_409741c4(param_1,uVar1,param_4 & 0xff,param_5);
      }
      return 0;
    }
    uVar1 = uVar1 + 4;
  } while (uVar1 < 0xc);
  return 0x500;
}



/* 40974570 FUN_40974570 */

/* Boundary evidence: original MIPS .pdata 40974570..4097458b. Semantic name remains unreviewed. */

void FUN_40974570(int param_1)

{
  mali_sys_atomic_inc(param_1 + 0x14);
  return;
}



/* 4097458c FUN_4097458c */

/* Boundary evidence: original MIPS .pdata 4097458c..409745fb. Semantic name remains unreviewed. */

void FUN_4097458c(int param_1,int param_2,undefined4 param_3,int param_4)

{
  undefined4 *puVar1;
  
  if (param_2 == 0x8892) {
    puVar1 = *(undefined4 **)(param_1 + 0x308);
    *(int *)(param_1 + 0x308) = param_4;
    *(undefined4 *)(param_1 + 0x300) = param_3;
  }
  else {
    if (param_2 != 0x8893) {
      return;
    }
    puVar1 = *(undefined4 **)(param_1 + 0x30c);
    *(int *)(param_1 + 0x30c) = param_4;
    *(undefined4 *)(param_1 + 0x304) = param_3;
  }
  if (param_4 != 0) {
    mali_sys_atomic_inc(param_4 + 0x14);
  }
  if (puVar1 != (undefined4 *)0x0) {
    FUN_409794cc(puVar1);
  }
  return;
}



/* 409745fc FUN_409745fc */

/* Boundary evidence: original MIPS .pdata 409745fc..4097467f. Semantic name remains unreviewed. */

void FUN_409745fc(int param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  
  FUN_40993370();
  if (param_2 == *(int *)(param_1 + 0x300)) {
    FUN_409794cc(*(undefined4 **)(param_1 + 0x308));
    *(undefined4 *)(param_1 + 0x300) = 0;
    *(undefined4 *)(param_1 + 0x308) = 0;
  }
  if (param_2 == *(int *)(param_1 + 0x304)) {
    FUN_409794cc(*(undefined4 **)(param_1 + 0x30c));
    *(undefined4 *)(param_1 + 0x304) = 0;
    *(undefined4 *)(param_1 + 0x30c) = 0;
  }
  piVar1 = (int *)(param_1 + 0x18);
  iVar2 = 0x10;
  do {
    if (param_2 == *piVar1) {
      FUN_409794cc((undefined4 *)piVar1[1]);
      *piVar1 = 0;
      piVar1[1] = 0;
    }
    iVar2 = iVar2 + -1;
    piVar1 = piVar1 + 0xc;
  } while (iVar2 != 0);
                    /* WARNING: Subroutine does not return */
  FUN_40993390(0x10);
}



/* 40974680 FUN_40974680 */

/* Boundary evidence: original MIPS .pdata 40974680..4097473b. Semantic name remains unreviewed. */

void FUN_40974680(int param_1,int param_2,int param_3,uint param_4)

{
  int iVar1;
  undefined1 in_stack_00000040;
  int in_stack_00000044;
  undefined4 in_stack_00000048;
  
  FUN_409933b0();
  if (in_stack_00000044 == 0) {
    iVar1 = FUN_409769fc(param_4);
    in_stack_00000044 = iVar1 * param_3;
  }
  iVar1 = param_2 * 0x30 + param_1 + 0x14;
  if (*(int *)(param_1 + 0x314) != *(int *)(iVar1 + 0x18)) {
    if (*(int *)(param_1 + 0x31c) != 0) {
      mali_sys_atomic_inc(*(int *)(param_1 + 0x31c) + 0x14);
    }
    if (*(undefined4 **)(iVar1 + 0x1c) != (undefined4 *)0x0) {
      FUN_409794cc(*(undefined4 **)(iVar1 + 0x1c));
    }
    *(undefined4 *)(iVar1 + 0x18) = *(undefined4 *)(param_1 + 0x314);
    *(undefined4 *)(iVar1 + 0x1c) = *(undefined4 *)(param_1 + 0x31c);
  }
  *(int *)(iVar1 + 4) = param_3;
  *(uint *)(iVar1 + 0xc) = param_4;
  *(undefined1 *)(iVar1 + 0x10) = in_stack_00000040;
  *(int *)(iVar1 + 8) = in_stack_00000044;
  *(undefined4 *)(iVar1 + 0x14) = in_stack_00000048;
  FUN_40969410(*(int *)(param_1 + 0x4fc),param_1 + 0x14,param_2);
                    /* WARNING: Subroutine does not return */
  FUN_409933e0(0x10);
}



/* 4097473c FUN_4097473c */

/* Boundary evidence: original MIPS .pdata 4097473c..409747b3. Semantic name remains unreviewed. */

void FUN_4097473c(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  
  FUN_40993370();
  puVar1 = (undefined4 *)(param_1 + 0x18);
  iVar2 = 0x10;
  do {
    if ((undefined4 *)puVar1[1] != (undefined4 *)0x0) {
      FUN_409794cc((undefined4 *)puVar1[1]);
    }
    *puVar1 = 0;
    iVar2 = iVar2 + -1;
    puVar1[1] = 0;
    puVar1 = puVar1 + 0xc;
  } while (iVar2 != 0);
  *(undefined4 *)(param_1 + 0x300) = 0;
  *(undefined4 *)(param_1 + 0x304) = 0;
  if (*(undefined4 **)(param_1 + 0x308) != (undefined4 *)0x0) {
    FUN_409794cc(*(undefined4 **)(param_1 + 0x308));
  }
  *(undefined4 *)(param_1 + 0x308) = 0;
  if (*(undefined4 **)(param_1 + 0x30c) != (undefined4 *)0x0) {
    FUN_409794cc(*(undefined4 **)(param_1 + 0x30c));
  }
  *(undefined4 *)(param_1 + 0x30c) = 0;
                    /* WARNING: Subroutine does not return */
  FUN_40993390(0x10);
}



/* 40974808 FUN_40974808 */

/* Boundary evidence: original MIPS .pdata 40974808..40974833. Semantic name remains unreviewed. */

void FUN_40974808(undefined4 param_1,undefined4 *param_2)

{
  mali_mem_ptr_unmap_area(*param_2);
  param_2[2] = 0;
  return;
}



/* 40974834 FUN_40974834 */

/* Boundary evidence: original MIPS .pdata 40974834..4097488f. Semantic name remains unreviewed. */

bool FUN_40974834(undefined4 param_1,undefined4 *param_2)

{
  int iVar1;
  
  iVar1 = mali_mem_ptr_map_area(*param_2,param_2[4],param_2[3] - param_2[4],0x40,0x10002);
  if (iVar1 != 0) {
    param_2[2] = iVar1;
  }
  return iVar1 != 0;
}



/* 40974890 FUN_40974890 */

/* Boundary evidence: original MIPS .pdata 40974890..409748c3. Semantic name remains unreviewed. */

undefined4 * FUN_40974890(void)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)mali_sys_malloc(0xa08);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    *puVar1 = 0;
    puVar1[1] = 0;
  }
  return puVar1;
}



/* 409748c4 FUN_409748c4 */

/* Boundary evidence: original MIPS .pdata 409748c4..409748f7. Semantic name remains unreviewed. */

undefined4 FUN_409748c4(undefined4 *param_1)

{
  undefined4 uVar1;
  
  if (param_1[1] == 0) {
    uVar1 = mali_mem_mali_addr_get_full(param_1,0);
  }
  else {
    uVar1 = *param_1;
  }
  return uVar1;
}



/* 409748f8 FUN_409748f8 */

/* Boundary evidence: original MIPS .pdata 409748f8..409749bf. Semantic name remains unreviewed. */

void FUN_409748f8(int param_1)

{
  int iVar1;
  int *piVar2;
  undefined4 *puVar3;
  int *piVar4;
  
  iVar1 = *(int *)(param_1 + 0xc) + -1;
  *(int *)(param_1 + 0xc) = iVar1;
  if (iVar1 < 1) {
    for (piVar2 = *(int **)(param_1 + 4); piVar2 != (int *)0x0; piVar2 = (int *)piVar2[1]) {
      iVar1 = *piVar2 + -1;
      if (-1 < iVar1) {
        piVar4 = piVar2 + iVar1 * 5 + 4;
        do {
          if (*piVar4 == 0) break;
          mali_mem_ptr_unmap_area(piVar4[-2]);
          iVar1 = iVar1 + -1;
          *piVar4 = 0;
          piVar4 = piVar4 + -5;
        } while (-1 < iVar1);
      }
    }
    puVar3 = *(undefined4 **)(param_1 + 8);
    if ((puVar3 != (undefined4 *)0x0) && (puVar3[2] != 0)) {
      mali_mem_ptr_unmap_area(*puVar3);
      puVar3[2] = 0;
    }
  }
  return;
}



/* 409749c0 FUN_409749c0 */

/* Boundary evidence: original MIPS .pdata 409749c0..40974a7b. Semantic name remains unreviewed. */

void FUN_409749c0(int param_1)

{
  uint *puVar1;
  int iVar2;
  uint *puVar3;
  uint uVar4;
  
  if (*(int *)(param_1 + 4) != 0) {
    iVar2 = *(int *)(param_1 + 0xc);
    while (0 < iVar2) {
      FUN_409748f8(param_1);
      iVar2 = *(int *)(param_1 + 0xc);
    }
    puVar1 = *(uint **)(param_1 + 4);
    while (puVar1 != (uint *)0x0) {
      uVar4 = 0;
      if (*puVar1 != 0) {
        puVar3 = puVar1 + 2;
        do {
          mali_mem_free(*puVar3);
          uVar4 = uVar4 + 1;
          *puVar3 = 0;
          puVar3 = puVar3 + 5;
        } while (uVar4 < *puVar1);
      }
      puVar3 = (uint *)puVar1[1];
      mali_sys_free(puVar1);
      puVar1 = puVar3;
    }
    *(undefined4 *)(param_1 + 4) = 0;
    *(undefined4 *)(param_1 + 8) = 0;
  }
  return;
}



/* 40974a7c FUN_40974a7c */

/* Boundary evidence: original MIPS .pdata 40974a7c..40974b4f. Semantic name remains unreviewed. */

void FUN_40974a7c(undefined4 *param_1,int param_2)

{
  undefined4 *puVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  
  FUN_40993370();
  if (*(int *)param_1[1] == 0x80) {
    puVar1 = (undefined4 *)mali_sys_malloc(0xa08);
    if (puVar1 == (undefined4 *)0x0) goto LAB_40974b44;
    *puVar1 = 0;
    puVar1[1] = 0;
    puVar1[1] = param_1[1];
    param_1[1] = puVar1;
  }
  piVar5 = (int *)param_1[1];
  iVar4 = *piVar5;
  piVar2 = (int *)mali_mem_alloc(*param_1,param_2,0x40,0x2d);
  piVar5[iVar4 * 5 + 2] = (int)piVar2;
  if (piVar2 != (int *)0x0) {
    if (piVar2[1] == 0) {
      iVar3 = mali_mem_mali_addr_get_full(piVar2,0);
    }
    else {
      iVar3 = *piVar2;
    }
    piVar5[iVar4 * 5 + 3] = iVar3;
    piVar5[iVar4 * 5 + 4] = 0;
    piVar5[iVar4 * 5 + 5] = param_2;
    piVar5[iVar4 * 5 + 6] = 0;
    *(int *)param_1[1] = *(int *)param_1[1] + 1;
  }
LAB_40974b44:
                    /* WARNING: Subroutine does not return */
  FUN_40993390(0x10);
}



/* 40974b50 FUN_40974b50 */

/* Boundary evidence: original MIPS .pdata 40974b50..40974c47. Semantic name remains unreviewed. */

undefined4 FUN_40974b50(undefined4 *param_1,int param_2,int *param_3)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  uint uVar3;
  
  puVar2 = (undefined4 *)param_1[2];
  uVar3 = param_2 + 0x3fU & 0xffffffc0;
  if ((uint)(puVar2[3] - puVar2[4]) < uVar3) {
    if (((uint)(puVar2[3] - puVar2[4]) < 0x1001) && (uVar3 < 0x10001)) {
      puVar2 = (undefined4 *)FUN_40974a7c(param_1,0x10000);
      if (puVar2 == (undefined4 *)0x0) {
        return 0;
      }
      param_1[2] = puVar2;
    }
    else {
      puVar2 = (undefined4 *)FUN_40974a7c(param_1,uVar3);
      if (puVar2 == (undefined4 *)0x0) {
        return 0;
      }
    }
    FUN_40974834(param_1,puVar2);
  }
  uVar1 = puVar2[2];
  *param_3 = puVar2[1] + puVar2[4];
  puVar2[4] = puVar2[4] + uVar3;
  puVar2[2] = puVar2[2] + uVar3;
  return uVar1;
}



/* 40974c48 FUN_40974c48 */

/* Boundary evidence: original MIPS .pdata 40974c48..40974ce7. Semantic name remains unreviewed. */

undefined4 FUN_40974c48(undefined4 *param_1)

{
  bool bVar1;
  undefined3 extraout_var;
  int iVar2;
  
  if ((int)param_1[3] < 1) {
    iVar2 = param_1[2];
    if (iVar2 == 0) {
      return 0xffffffff;
    }
    if (*(int *)(iVar2 + 0x10) == *(int *)(iVar2 + 0xc)) {
      iVar2 = FUN_40974a7c(param_1,0x10000);
      if (iVar2 == 0) {
        return 0xffffffff;
      }
      param_1[2] = iVar2;
    }
    bVar1 = FUN_40974834(param_1,(undefined4 *)param_1[2]);
    if (CONCAT31(extraout_var,bVar1) == 0) {
      return 0xfffffffe;
    }
    param_1[3] = param_1[3] + 1;
  }
  else {
    param_1[3] = param_1[3] + 1;
  }
  return 0;
}



/* 40974ce8 FUN_40974ce8 */

/* Boundary evidence: original MIPS .pdata 40974ce8..40974d6b. Semantic name remains unreviewed. */

undefined4 FUN_40974ce8(undefined4 *param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  int iVar2;
  
  *param_1 = param_2;
  param_1[2] = 0;
  param_1[3] = 0;
  puVar1 = (undefined4 *)mali_sys_malloc(0xa08);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    *puVar1 = 0;
    puVar1[1] = 0;
  }
  param_1[1] = puVar1;
  if (puVar1 != (undefined4 *)0x0) {
    iVar2 = FUN_40974a7c(param_1,0x10000);
    param_1[2] = iVar2;
    if (iVar2 != 0) {
      return 0;
    }
    FUN_409749c0((int)param_1);
  }
  return 0xffffffff;
}



/* 40974d6c FUN_40974d6c */

void FUN_40974d6c(uint *param_1,uint *param_2,int param_3,int param_4,ushort *param_5)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar2 = 0;
  uVar3 = 0xffffffff;
  if (param_4 == 0x1401) {
    for (; param_3 != 0; param_3 = param_3 + -1) {
      uVar1 = (uint)(byte)*param_5;
      param_5 = (ushort *)((int)param_5 + 1);
      if (uVar1 < uVar3) {
        uVar3 = uVar1;
      }
      if (uVar2 < uVar1) {
        uVar2 = uVar1;
      }
    }
  }
  else if (param_4 == 0x1403) {
    for (; param_3 != 0; param_3 = param_3 + -1) {
      uVar1 = (uint)*param_5;
      param_5 = param_5 + 1;
      if (uVar1 < uVar3) {
        uVar3 = uVar1;
      }
      if (uVar2 < uVar1) {
        uVar2 = uVar1;
      }
    }
  }
  *param_1 = uVar2;
  *param_2 = uVar3;
  return;
}



/* 40974e18 FUN_40974e18 */

uint FUN_40974e18(uint param_1,uint param_2)

{
  bool bVar1;
  
  if (param_1 == 1) {
    param_2 = param_2 & 0xfffffffe;
  }
  else if (1 < param_1) {
    if (param_1 < 4) {
      bVar1 = (int)param_2 < 2;
    }
    else {
      if (param_1 == 4) {
        return param_2 - (int)param_2 % 3;
      }
      if (param_1 < 5) {
        return param_2;
      }
      if (6 < param_1) {
        return param_2;
      }
      bVar1 = (int)param_2 < 3;
    }
    if (bVar1) {
      param_2 = 0;
    }
  }
  return param_2;
}



/* 40974f34 FUN_40974f34 */

/* Boundary evidence: original MIPS .pdata 40974f34..40975027. Semantic name remains unreviewed. */

void FUN_40974f34(int param_1,undefined4 param_2)

{
  FUN_40993370();
  if ((((*(ushort *)(param_1 + 0xe) & 1) != 0) && (*(int *)(param_1 + 0x3dc) != 0)) &&
     (*(int *)(param_1 + 0x3e0) != 0)) {
    mali_frame_builder_get_frame_height(param_2);
    mali_frame_builder_get_frame_width(param_2);
  }
                    /* WARNING: Subroutine does not return */
  FUN_40993390(0x10);
}



/* 40975028 FUN_40975028 */

/* Boundary evidence: original MIPS .pdata 40975028..409750a3. Semantic name remains unreviewed. */

undefined4 FUN_40975028(int param_1,int param_2)

{
  int *piVar1;
  uint uVar2;
  int local_20 [8];
  
  local_20[0] = 4;
  local_20[2] = 5;
  local_20[3] = 1;
  uVar2 = 0;
  local_20[1] = 6;
  local_20[4] = 3;
  local_20[5] = 2;
  local_20[6] = 0;
  piVar1 = local_20;
  do {
    if (param_1 == *piVar1) {
      if (param_2 < 0) {
        return 0x501;
      }
      return 0;
    }
    uVar2 = uVar2 + 1;
    prefetch(piVar1 + 2,0);
    piVar1 = piVar1 + 1;
  } while (uVar2 < 7);
  return 0x500;
}



/* 409750a4 FUN_409750a4 */

uint FUN_409750a4(int param_1,uint param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  uint *puVar3;
  uint uVar4;
  
  uVar2 = *(uint *)(((int)param_2 >> 5) * 4 + param_1);
  uVar4 = param_2 & 0x1f;
  iVar1 = ((int)param_2 >> 5) * 4;
  if (param_3 == 0) {
    puVar3 = (uint *)(iVar1 + param_1);
    *puVar3 = ~(1 << uVar4) & *puVar3;
  }
  else {
    puVar3 = (uint *)(iVar1 + param_1);
    *puVar3 = 1 << uVar4 | *puVar3;
  }
  return uVar2 >> uVar4 & 1;
}



/* 40975104 FUN_40975104 */

/* Boundary evidence: original MIPS .pdata 40975104..409751d7. Semantic name remains unreviewed. */

void FUN_40975104(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  FUN_409933b0();
  if (((param_2 == 5) || (param_2 == 4)) || (iVar1 = 0, param_2 == 6)) {
    iVar1 = 1;
  }
  if (((param_2 == 1) || (param_2 == 3)) || (iVar2 = 0, param_2 == 2)) {
    iVar2 = 1;
  }
  iVar3 = param_1 + 0xc;
  FUN_409750a4(iVar3,0x1b,iVar1);
  FUN_409750a4(iVar3,0x1c,iVar2);
  FUN_409750a4(iVar3,0x1d,(uint)(param_2 == 0));
  FUN_409750a4(iVar3,0x1e,param_3);
  iVar1 = mali_frame_builder_get_supersample_factor(*(undefined4 *)(param_1 + 0x4f4));
  FUN_409750a4(iVar3,0x1a,(uint)(iVar1 == 2));
                    /* WARNING: Subroutine does not return */
  FUN_409933e0(0x10);
}



/* 409751d8 FUN_409751d8 */

/* Boundary evidence: original MIPS .pdata 409751d8..40975213. Semantic name remains unreviewed. */

int FUN_409751d8(int param_1,int param_2,int param_3)

{
  int iVar1;
  
  iVar1 = FUN_40975028(param_1,param_3);
  if ((iVar1 == 0) && (iVar1 = 0x501, -1 < param_2)) {
    iVar1 = 0;
  }
  return iVar1;
}



/* 40975214 FUN_40975214 */

/* Boundary evidence: original MIPS .pdata 40975214..4097525b. Semantic name remains unreviewed. */

int FUN_40975214(int param_1,int param_2,int param_3)

{
  int iVar1;
  
  iVar1 = FUN_40975028(param_1,param_2);
  if ((iVar1 == 0) && ((param_3 == 0x1401 || (iVar1 = 0x500, param_3 == 0x1403)))) {
    iVar1 = 0;
  }
  return iVar1;
}



/* 4097525c FUN_4097525c */

/* Boundary evidence: original MIPS .pdata 4097525c..409752bb. Semantic name remains unreviewed. */

undefined4 FUN_4097525c(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_40974f34(param_1,*(undefined4 *)(param_1 + 0x4f4));
  if (iVar1 == 1) {
    uVar2 = 0xfffffffd;
  }
  else {
    FUN_40975104(param_1,param_2,0);
    uVar2 = 0;
  }
  return uVar2;
}



/* 409752bc FUN_409752bc */

/* Boundary evidence: original MIPS .pdata 409752bc..409753df. Semantic name remains unreviewed. */

void FUN_409752bc(int param_1,uint param_2,uint param_3,int param_4)

{
  int iVar1;
  int *piVar2;
  undefined4 *puVar3;
  ushort *in_stack_00000040;
  uint *in_stack_00000044;
  uint *in_stack_00000048;
  
  FUN_40993230();
  iVar1 = FUN_40974f34(param_1,*(undefined4 *)(param_1 + 0x4f4));
  if (iVar1 != 1) {
    FUN_40975104(param_1,param_4,1);
    puVar3 = *(undefined4 **)(param_1 + 800);
    if (puVar3 == (undefined4 *)0x0) {
      if ((in_stack_00000040 != (ushort *)0x0) && (in_stack_00000044 != (uint *)0x0)) {
        FUN_40974d6c(in_stack_00000048,in_stack_00000044,param_2,param_3,in_stack_00000040);
      }
    }
    else {
      piVar2 = (int *)*puVar3;
      iVar1 = 0;
      if (piVar2 != (int *)0x0) {
        if (param_3 == 0x1401) {
          iVar1 = 1;
        }
        else if (param_3 == 0x1403) {
          iVar1 = 2;
        }
        if ((((piVar2[1] + (int)in_stack_00000040 & iVar1 - 1U) == 0) &&
            (iVar1 * param_2 <= (uint)puVar3[1])) && (in_stack_00000044 != (uint *)0x0)) {
          FUN_40968eac(piVar2,(uint)in_stack_00000040,param_2,param_3);
        }
      }
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_40993258(0x18);
}



/* 409753e0 FUN_409753e0 */

/* Boundary evidence: original MIPS .pdata 409753e0..4097540f. Semantic name remains unreviewed. */

void FUN_409753e0(undefined4 *param_1,undefined4 param_2)

{
  int in_stack_00000014;
  int in_stack_00000018;
  
  FUN_40968c58(param_1,param_2,in_stack_00000014,in_stack_00000018);
  return;
}



/* 40975410 FUN_40975410 */

/* Boundary evidence: original MIPS .pdata 40975410..4097542b. Semantic name remains unreviewed. */

void FUN_40975410(undefined4 *param_1,uint param_2,int param_3,uint param_4)

{
  FUN_40968d80(param_1,param_2,param_3,param_4);
  return;
}



/* 4097542c FUN_4097542c */

/* Boundary evidence: original MIPS .pdata 4097542c..4097560b. Semantic name remains unreviewed. */

void FUN_4097542c(int param_1,undefined4 param_2,undefined1 *param_3,int param_4,int param_5,
                 int param_6,int param_7)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  byte bVar5;
  byte bVar6;
  byte bVar7;
  byte bVar8;
  byte bVar9;
  byte bVar10;
  byte bVar11;
  byte bVar12;
  byte *pbVar13;
  int iVar14;
  int iVar15;
  undefined1 *puVar16;
  int iVar17;
  int *piVar18;
  int iVar19;
  int iVar20;
  int iVar21;
  int local_18 [4];
  
  if ((param_5 == 2) && (param_6 == 2)) {
    if (0 < param_4) {
      iVar15 = (param_4 - 1U >> 1) + 1;
      pbVar13 = (byte *)(param_1 + 0x200);
      do {
        bVar1 = pbVar13[-0x1ff];
        iVar15 = iVar15 + -1;
        bVar2 = pbVar13[-0x1fb];
        bVar3 = pbVar13[-0x1fe];
        bVar4 = pbVar13[5];
        bVar5 = pbVar13[6];
        bVar6 = pbVar13[1];
        bVar7 = pbVar13[2];
        bVar8 = pbVar13[-0x1fa];
        bVar9 = pbVar13[-0x1fd];
        bVar10 = pbVar13[-0x1f9];
        bVar11 = pbVar13[7];
        bVar12 = pbVar13[3];
        prefetch(pbVar13 + -0x1ef,0);
        *param_3 = (char)(((uint)pbVar13[-0x200] + (uint)pbVar13[4] + (uint)pbVar13[-0x1fc] +
                          (uint)*pbVar13) * param_7 >> 0x18);
        param_3[1] = (char)(((uint)bVar1 + (uint)bVar2 + (uint)bVar4 + (uint)bVar6) * param_7 >>
                           0x18);
        param_3[2] = (char)(((uint)bVar3 + (uint)bVar8 + (uint)bVar5 + (uint)bVar7) * param_7 >>
                           0x18);
        param_3[3] = (char)(((uint)bVar9 + (uint)bVar10 + (uint)bVar11 + (uint)bVar12) * param_7 >>
                           0x18);
        param_3 = param_3 + 4;
        pbVar13 = pbVar13 + 8;
      } while (iVar15 != 0);
    }
  }
  else {
    iVar15 = 0;
    if (0 < param_4) {
      do {
        local_18[0] = 0;
        local_18[1] = 0;
        local_18[2] = 0;
        local_18[3] = 0;
        iVar19 = param_1;
        iVar20 = param_6;
        if (0 < param_6) {
          do {
            iVar14 = iVar19;
            iVar21 = param_5;
            if (0 < param_5) {
              do {
                iVar17 = 0;
                piVar18 = local_18;
                do {
                  prefetch((byte *)(iVar14 + iVar17) + 1,0);
                  *piVar18 = (uint)*(byte *)(iVar14 + iVar17) + *piVar18;
                  iVar17 = iVar17 + 1;
                  prefetch(piVar18 + 2,0);
                  piVar18 = piVar18 + 1;
                } while (iVar17 < 4);
                iVar21 = iVar21 + -1;
                iVar14 = iVar14 + 4;
              } while (iVar21 != 0);
            }
            iVar20 = iVar20 + -1;
            iVar19 = iVar19 + 0x200;
          } while (iVar20 != 0);
        }
        iVar19 = 0;
        piVar18 = local_18;
        do {
          iVar20 = *piVar18;
          puVar16 = param_3 + iVar19;
          iVar19 = iVar19 + 1;
          piVar18 = piVar18 + 1;
          *puVar16 = (char)((uint)(param_7 * iVar20) >> 0x18);
        } while (iVar19 < 4);
        iVar15 = iVar15 + param_5;
        param_1 = param_5 * 4 + param_1;
        param_3 = param_3 + 4;
      } while (iVar15 < param_4);
    }
  }
  return;
}



/* 4097560c FUN_4097560c */

/* WARNING: Removing unreachable block (ram,0x409756f8) */
/* Boundary evidence: original MIPS .pdata 4097560c..409758d7. Semantic name remains unreviewed. */

void FUN_4097560c(int param_1,int param_2,int param_3,int param_4)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iStack00000020;
  int iStack00000024;
  int iStack00000028;
  int iStack0000002c;
  int iStack00000030;
  int iStack00000034;
  int iStack0000003c;
  int in_stack_00000680;
  int in_stack_00000684;
  int in_stack_00000688;
  int in_stack_0000068c;
  undefined4 in_stack_00000690;
  
  FUN_40993300();
  uVar1 = DAT_40996268;
  iStack00000020 = in_stack_00000680;
  iStack00000030 = param_4;
  iStack0000003c = param_2;
  iVar2 = mali_convert_pixel_format_get_convert_method(in_stack_00000690);
  iVar3 = mali_convert_pixel_format_get_size(in_stack_00000690);
  iVar7 = param_2 / in_stack_00000684;
  if (in_stack_00000684 == 0) {
    trap(0x1c00);
  }
  if ((in_stack_00000684 == -1) && (param_2 == -0x80000000)) {
    trap(0x1800);
  }
  iVar8 = param_3 / in_stack_00000688;
  if (in_stack_00000688 == 0) {
    trap(0x1c00);
  }
  if ((in_stack_00000688 == -1) && (param_3 == -0x80000000)) {
    trap(0x1800);
  }
  iStack00000034 = 0x1000000 / (iVar8 * iVar7);
  if (iVar8 * iVar7 == 0) {
    trap(0x1c00);
  }
  iStack00000024 = iVar3;
  iStack00000028 = iVar7;
  iStack0000002c = in_stack_00000688;
  if (0 < in_stack_00000688) {
    do {
      iVar5 = 0;
      iVar6 = 0;
      if (0 < in_stack_00000684) {
        do {
          iVar4 = iStack0000003c - iVar5;
          if (0x80 < iVar4) {
            iVar4 = 0x80;
          }
          iVar9 = iVar4 / iVar7;
          if (iVar7 == 0) {
            trap(0x1c00);
          }
          if ((iVar7 == -1) && (iVar4 == -0x80000000)) {
            trap(0x1800);
          }
          if (iVar2 == 0) {
            mali_convert_8bit_to_rgba8888
                      (&stack0x00000240,iVar5 * iVar3 + param_1,iVar4,in_stack_00000690);
            in_stack_00000680 = iStack00000020;
            if (1 < iVar8) {
              mali_convert_8bit_to_rgba8888
                        (&stack0x00000440,iVar5 * iVar3 + iStack00000030 + param_1,iVar4,
                         in_stack_00000690);
              in_stack_00000680 = iStack00000020;
            }
          }
          else if (iVar2 == 2) {
            mali_convert_16bit_to_rgba8888
                      (&stack0x00000240,iVar5 * iVar3 + param_1,iVar4,in_stack_00000690);
            in_stack_00000680 = iStack00000020;
            if (1 < iVar8) {
              mali_convert_16bit_to_rgba8888
                        (&stack0x00000440,iVar5 * iVar3 + iStack00000030 + param_1,iVar4,
                         in_stack_00000690);
              in_stack_00000680 = iStack00000020;
            }
          }
          FUN_4097542c((int)&stack0x00000240,0x200,&stack0x00000040,iVar4,iStack00000028,iVar8,
                       iStack00000034);
          if (iVar2 == 0) {
            mali_convert_rgba8888_to_8bit
                      (iVar6 * iStack00000024 + in_stack_00000680,&stack0x00000040,iVar9,
                       in_stack_00000690);
          }
          else if (iVar2 == 2) {
            mali_convert_rgba8888_to_16bit
                      (iVar6 * iStack00000024 + in_stack_00000680,&stack0x00000040,iVar9,
                       in_stack_00000690);
          }
          iVar6 = iVar9 + iVar6;
          iVar5 = iVar4 + iVar5;
          iVar3 = iStack00000024;
          iVar7 = iStack00000028;
        } while (iVar6 < in_stack_00000684);
      }
      in_stack_00000680 = in_stack_00000680 + in_stack_0000068c;
      iStack0000002c = iStack0000002c + -1;
      param_1 = param_4 * iVar8 + param_1;
      iStack00000020 = in_stack_00000680;
    } while (iStack0000002c != 0);
  }
  FUN_40963898(uVar1);
                    /* WARNING: Subroutine does not return */
  FUN_40993338(0x648);
}



/* 409758d8 FUN_409758d8 */

undefined4 FUN_409758d8(int param_1,int param_2)

{
  if (param_2 == 0x1401) {
    if (param_1 == 0x1906) {
      return 9;
    }
    if (param_1 == 0x1907) {
      return 5;
    }
    if (param_1 == 0x1908) {
      return 6;
    }
    if (param_1 != 0x1909) {
      if (param_1 != 0x190a) {
        return 0;
      }
      return 8;
    }
  }
  else if (param_2 == 0x1403) {
    if (param_1 == 0x1908) {
      return 4;
    }
    if (param_1 == 0x190a) {
      return 3;
    }
  }
  else {
    if (param_2 == 0x8033) {
      return 1;
    }
    if (param_2 == 0x8034) {
      return 2;
    }
    if (param_2 == 0x8363) {
      return 0;
    }
  }
  return 7;
}



/* 409759bc FUN_409759bc */

uint FUN_409759bc(uint param_1)

{
  uint uVar1;
  
  uVar1 = 0;
  if ((param_1 & 0x7fff0000) != 0) {
    uVar1 = 0x10;
  }
  if ((param_1 & 0x7f00ff00) != 0) {
    uVar1 = uVar1 | 8;
  }
  if ((param_1 & 0x70f0f0f0) != 0) {
    uVar1 = uVar1 | 4;
  }
  if ((param_1 & 0x3ccccccc) != 0) {
    uVar1 = uVar1 | 2;
  }
  if ((param_1 & 0x2aaaaaaa) != 0) {
    uVar1 = uVar1 | 1;
  }
  return uVar1;
}



/* 40975a38 FUN_40975a38 */

/* Boundary evidence: original MIPS .pdata 40975a38..40975d0f. Semantic name remains unreviewed. */

void FUN_40975a38(int param_1,undefined4 *param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  undefined4 uStack0000002c;
  int iStack00000030;
  undefined4 *puStack00000034;
  int iStack00000038;
  int iStack00000040;
  int iStack00000044;
  uint in_stack_00000080;
  uint in_stack_00000084;
  int in_stack_0000008c;
  int in_stack_00000090;
  int in_stack_00000094;
  int in_stack_00000098;
  
  FUN_40993300();
  iStack00000040 = 0;
  iStack00000044 = 0;
  iStack00000030 = param_3;
  puStack00000034 = param_2;
  iStack00000038 = param_1;
  uStack0000002c = FUN_409758d8(in_stack_0000008c,in_stack_00000090);
  uVar2 = in_stack_00000080;
  if ((int)in_stack_00000080 <= (int)in_stack_00000084) {
    uVar2 = in_stack_00000084;
  }
  if ((((1 < (int)uVar2) && (in_stack_00000094 != 0)) &&
      (iVar1 = FUN_40976924(in_stack_0000008c,in_stack_00000090), iVar1 != 0)) &&
     (uVar2 = FUN_409759bc(uVar2), -1 < (int)uVar2)) {
    uVar7 = in_stack_00000080;
    if ((int)in_stack_00000080 < 0) {
      uVar7 = in_stack_00000080 + 3;
    }
    iVar6 = (int)uVar7 >> 2;
    if (iVar6 < 2) {
      iVar6 = 1;
    }
    uVar7 = in_stack_00000084;
    if ((int)in_stack_00000084 < 0) {
      uVar7 = in_stack_00000084 + 3;
    }
    iVar4 = (int)uVar7 >> 2;
    if (iVar4 < 2) {
      iVar4 = 1;
    }
    iVar6 = mali_sys_malloc(iVar4 * iVar6 * iVar1);
    uVar7 = in_stack_00000080;
    if ((int)in_stack_00000080 < 0) {
      uVar7 = in_stack_00000080 + 1;
    }
    iVar4 = (int)uVar7 >> 1;
    if (iVar4 < 2) {
      iVar4 = 1;
    }
    uVar7 = in_stack_00000084;
    if ((int)in_stack_00000084 < 0) {
      uVar7 = in_stack_00000084 + 1;
    }
    iVar5 = (int)uVar7 >> 1;
    if (iVar5 < 2) {
      iVar5 = 1;
    }
    iStack00000040 = iVar6;
    iVar4 = mali_sys_malloc(iVar5 * iVar4 * iVar1);
    iStack00000044 = iVar4;
    if (iVar6 != 0) {
      if (iVar4 != 0) {
        uVar7 = 1;
        if (0 < (int)uVar2) {
          do {
            iVar5 = *(int *)((int)&stack0x00000040 + (uVar7 & 1) * 4);
            uVar9 = in_stack_00000080;
            if ((int)in_stack_00000080 < 0) {
              uVar9 = in_stack_00000080 + 1;
            }
            uVar9 = (int)uVar9 >> 1;
            if ((int)uVar9 < 2) {
              uVar9 = 1;
            }
            uVar8 = in_stack_00000084;
            if ((int)in_stack_00000084 < 0) {
              uVar8 = in_stack_00000084 + 1;
            }
            uVar8 = (int)uVar8 >> 1;
            if ((int)uVar8 < 2) {
              uVar8 = 1;
            }
            FUN_4097560c(in_stack_00000094,in_stack_00000080,in_stack_00000084,in_stack_00000098);
            iVar3 = FUN_4097bbc8(iStack00000038,puStack00000034,iStack00000030,uVar7);
            if (iVar3 != 0) {
              mali_sys_free(iVar6);
              mali_sys_free(iVar4);
              goto LAB_40975d04;
            }
            uVar7 = uVar7 + 1;
            in_stack_00000094 = iVar5;
            in_stack_00000098 = uVar9 * iVar1;
            in_stack_00000084 = uVar8;
            in_stack_00000080 = uVar9;
          } while ((int)uVar7 <= (int)uVar2);
        }
        mali_sys_free(iVar6);
        mali_sys_free(iVar4);
        goto LAB_40975d04;
      }
      mali_sys_free(iVar6);
    }
    if (iVar4 != 0) {
      mali_sys_free(iVar4);
    }
  }
LAB_40975d04:
                    /* WARNING: Subroutine does not return */
  FUN_40993338(0x48);
}



/* 40975d10 FUN_40975d10 */

/* Boundary evidence: original MIPS .pdata 40975d10..40975d2b. Semantic name remains unreviewed. */

void FUN_40975d10(void)

{
  mali_sys_free();
  return;
}



/* 40975d2c FUN_40975d2c */

/* Boundary evidence: original MIPS .pdata 40975d2c..40975d6b. Semantic name remains unreviewed. */

undefined4 * FUN_40975d2c(undefined4 param_1)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)mali_sys_malloc(8);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    *puVar1 = param_1;
    puVar1[1] = 0;
  }
  return puVar1;
}



/* 40975d6c FUN_40975d6c */

/* Boundary evidence: original MIPS .pdata 40975d6c..40975da7. Semantic name remains unreviewed. */

undefined4 FUN_40975d6c(int param_1,uint param_2)

{
  undefined4 uVar1;
  
  if (param_2 < 0x100) {
    uVar1 = *(undefined4 *)((param_2 + 7) * 4 + param_1);
  }
  else {
    uVar1 = __mali_named_list_get_non_flat();
  }
  return uVar1;
}



/* 40975da8 FUN_40975da8 */

/* Boundary evidence: original MIPS .pdata 40975da8..40975e07. Semantic name remains unreviewed. */

undefined4 FUN_40975da8(int param_1,uint param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  if (param_2 < 0x100) {
    iVar1 = *(int *)((param_2 + 7) * 4 + param_1);
  }
  else {
    iVar1 = __mali_named_list_get_non_flat();
  }
  if ((iVar1 != 0) && (*(int *)(iVar1 + 4) != 0)) {
    uVar2 = 1;
  }
  return uVar2;
}



/* 40975e08 FUN_40975e08 */

/* Boundary evidence: original MIPS .pdata 40975e08..40975e53. Semantic name remains unreviewed. */

void FUN_40975e08(undefined4 param_1,int param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  
  FUN_40993370();
  if (0 < param_2) {
    do {
      uVar1 = __mali_named_list_remove(param_1,*param_3);
      mali_sys_free(uVar1);
      param_3 = param_3 + 1;
      param_2 = param_2 + -1;
    } while (param_2 != 0);
  }
                    /* WARNING: Subroutine does not return */
  FUN_40993390(0x10);
}



/* 40975e54 FUN_40975e54 */

/* Boundary evidence: original MIPS .pdata 40975e54..40975f53. Semantic name remains unreviewed. */

undefined4 FUN_40975e54(undefined4 param_1,int param_2,int *param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  
  if (param_3 != (int *)0x0) {
    if (param_2 < 0) {
      return 0x501;
    }
    iVar4 = 0;
    piVar5 = param_3;
    if (0 < param_2) {
      do {
        iVar1 = __mali_named_list_get_unused_name(param_1);
        if ((iVar1 == 0) || (puVar2 = (undefined4 *)mali_sys_malloc(8), puVar2 == (undefined4 *)0x0)
           ) {
LAB_40975f40:
          FUN_40975e08(param_1,iVar4,param_3);
          return 0x505;
        }
        *puVar2 = param_4;
        puVar2[1] = 0;
        iVar3 = __mali_named_list_insert(param_1,iVar1,puVar2);
        if (iVar3 != 0) {
          mali_sys_free(puVar2);
          goto LAB_40975f40;
        }
        iVar4 = iVar4 + 1;
        *piVar5 = iVar1;
        piVar5 = piVar5 + 1;
      } while (iVar4 < param_2);
    }
  }
  return 0;
}



/* 40975f94 FUN_40975f94 */

/* Boundary evidence: original MIPS .pdata 40975f94..40975feb. Semantic name remains unreviewed. */

void FUN_40975f94(int *param_1,int param_2,int param_3,int param_4,int param_5)

{
  if (param_1[1] == 0) {
    param_1[0x11] = param_4;
    param_1[0x10] = param_3;
    param_1[0x12] = param_5;
  }
  else if (param_2 == 2) {
    FUN_4097132c(*param_1,param_3,param_4,param_5);
  }
  return;
}



/* 40975fec FUN_40975fec */

/* Boundary evidence: original MIPS .pdata 40975fec..4097604f. Semantic name remains unreviewed. */

void FUN_40975fec(int *param_1,int param_2,int *param_3,int *param_4,int *param_5)

{
  if (param_1[1] == 0) {
    *param_3 = param_1[0x10];
    *param_4 = param_1[0x11];
    *param_5 = param_1[0x12];
  }
  else if (param_2 == 2) {
    FUN_409712a4(*param_1,param_3,param_4,param_5);
  }
  return;
}



/* 40976050 FUN_40976050 */

/* Boundary evidence: original MIPS .pdata 40976050..409766bf. Semantic name remains unreviewed. */

void FUN_40976050(undefined4 *param_1,uint param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  undefined4 uVar10;
  int *piVar11;
  uint uVar12;
  uint uVar13;
  undefined8 uVar14;
  uint uStack00000018;
  uint uStack0000001c;
  uint uStack00000020;
  int in_stack_00000024;
  int in_stack_00000028;
  int in_stack_0000002c;
  uint in_stack_00000030;
  int in_stack_00000034;
  uint in_stack_00000038;
  uint in_stack_0000003c;
  uint in_stack_00000040;
  uint in_stack_00000044;
  
  FUN_40993300();
  uStack00000018 = 0;
  uStack0000001c = 0;
  uStack00000020 = 0;
  if (((param_1[1] == 2) && (param_1[0x122] != 0)) &&
     (iVar1 = FUN_40972840((int)param_1), iVar1 != 0)) goto LAB_409766b8;
  iVar1 = 0;
  if ((param_2 & 0xffffbaff) != 0) {
    iVar1 = 0x501;
  }
  if (iVar1 != 0) goto LAB_409766b8;
  uVar10 = param_1[0x13d];
  iVar1 = FUN_40978ffc(param_1);
  if (iVar1 != 0) goto LAB_409766b8;
  piVar11 = param_1 + 0x121;
  FUN_40975fec(piVar11,param_1[1],(int *)&stack0x00000018,(int *)&stack0x0000001c,
               (int *)&stack0x00000020);
  if ((((param_2 & 0x4000) == 0) || (*(char *)(param_1 + 0x115) == '\0')) ||
     ((*(char *)((int)param_1 + 0x455) == '\0' ||
      ((*(char *)((int)param_1 + 0x456) == '\0' ||
       (iVar1 = 1, *(char *)((int)param_1 + 0x457) == '\0')))))) {
    iVar1 = 0;
  }
  if (((param_2 & 0x100) == 0) || (iVar8 = 1, *(char *)(param_1 + 0x116) == '\0')) {
    iVar8 = 0;
  }
  if (((param_2 & 0x400) == 0) || (param_1[0x117] != 0xff)) {
    in_stack_00000024 = 0;
  }
  else {
    in_stack_00000024 = 1;
  }
  in_stack_00000028 = iVar1;
  in_stack_0000002c = iVar8;
  iVar2 = FUN_40974f34((int)param_1,param_1[0x13d]);
  if (iVar2 == 1) {
    if (param_1[0x144] != 0) {
      FUN_409748f8(param_1[0x144]);
    }
    mali_frame_builder_write_unlock(param_1[0x13d]);
    goto LAB_409766b8;
  }
  if (((*(ushort *)((int)param_1 + 0xe) & 1) != 0) &&
     ((((param_1[0xf5] != 0 || (param_1[0xf6] != 0)) ||
       (iVar2 = mali_frame_builder_get_frame_width(uVar10), param_1[0xf7] != iVar2)) ||
      (iVar2 = mali_frame_builder_get_frame_height(uVar10), param_1[0xf8] != iVar2)))) {
    FUN_40975f94(piVar11,param_1[1],(param_2 & 0x4000) != 0 | uStack00000018,
                 (param_2 & 0x100) != 0 | uStack0000001c,(param_2 & 0x400) != 0 | uStack00000020);
    FUN_4096c9b4(param_1,param_2);
    if (param_1[0x144] != 0) {
      FUN_409748f8(param_1[0x144]);
    }
    mali_frame_builder_write_unlock(param_1[0x13d]);
    goto LAB_409766b8;
  }
  if ((iVar1 != 0) || (uStack00000018 == 0)) {
    uVar3 = __fpmul(param_1[0x118],0x437f0000);
    uVar3 = __fpadd(uVar3,0x3f000000);
    iVar2 = __fptoli(uVar3);
    in_stack_00000030 = iVar2 << 8;
    in_stack_00000034 = (int)in_stack_00000030 >> 0x1f;
    uVar3 = __fpmul(param_1[0x119],0x437f0000);
    uVar3 = __fpadd(uVar3,0x3f000000);
    iVar2 = __fptoli(uVar3);
    in_stack_00000038 = iVar2 << 8;
    in_stack_0000003c = (int)in_stack_00000038 >> 0x1f;
    uVar3 = __fpmul(param_1[0x11a],0x437f0000);
    uVar3 = __fpadd(uVar3,0x3f000000);
    iVar2 = __fptoli(uVar3);
    in_stack_00000040 = iVar2 << 8;
    in_stack_00000044 = (int)in_stack_00000040 >> 0x1f;
    uVar3 = __fpmul(param_1[0x11b],0x437f0000);
    uVar3 = __fpadd(uVar3,0x3f000000);
    iVar2 = __fptoli(uVar3);
    uVar12 = iVar2 << 8;
    if (*piVar11 == 0) {
      iVar2 = param_1[0x128];
    }
    else {
      iVar2 = FUN_40971460(*piVar11,0xd55);
    }
    if (iVar2 == 0) {
      uVar12 = 0xffff;
    }
    uVar14 = mali_frame_builder_get_clear_value(uVar10,0);
    uVar7 = (uint)((ulonglong)uVar14 >> 0x20);
    uVar5 = in_stack_00000030;
    if (*(char *)(param_1 + 0x115) == '\0') {
      uVar5 = uVar7 & 0xffff;
    }
    uVar9 = in_stack_00000038;
    uVar6 = in_stack_0000003c;
    if (*(char *)((int)param_1 + 0x455) == '\0') {
      uVar9 = (uint)uVar14 >> 0x10;
      uVar6 = 0;
    }
    uVar4 = in_stack_00000044;
    uVar13 = in_stack_00000040;
    if (*(char *)((int)param_1 + 0x456) == '\0') {
      uVar4 = 0;
      uVar13 = (uint)uVar14 & 0xffff;
    }
    if (*(char *)((int)param_1 + 0x457) == '\0') {
      uVar12 = uVar7 >> 0x10;
    }
    mali_frame_builder_set_clear_value
              (uVar10,0,uVar9 << 0x10 | uVar13,
               ((uVar12 << 0x10 | uVar5) >> 0x10 | uVar6) << 0x10 | (uVar5 << 0x10 | uVar9) >> 0x10
               | uVar4);
  }
  uVar12 = uStack0000001c;
  if ((iVar8 != 0) || (uStack0000001c == 0)) {
    uVar3 = __fpmul(param_1[0x11c],0x4b7fffff);
    uVar3 = __fptoul(uVar3);
    mali_frame_builder_set_clear_value(uVar10,1,uVar3,0);
  }
  uVar5 = uStack00000020;
  if ((in_stack_00000024 != 0) || (uStack00000020 == 0)) {
    uVar9 = param_1[0x11d];
    uVar7 = param_1[0x117];
    mali_frame_builder_get_clear_value(uVar10,2);
    mali_frame_builder_set_clear_value(uVar10,2,uVar7 & uVar9,0);
    iVar1 = in_stack_00000028;
    iVar8 = in_stack_0000002c;
  }
  if ((iVar1 == 0) && (uStack00000018 != 0)) {
LAB_40976578:
    iVar1 = 1;
LAB_40976584:
    if ((uVar12 == 0) || (iVar2 = 1, iVar8 != 0)) {
      iVar2 = 0;
    }
    if ((uVar5 == 0) || (iVar8 = 1, in_stack_00000024 != 0)) {
      iVar8 = 0;
    }
    FUN_40975f94(piVar11,param_1[1],iVar1,iVar2,iVar8);
    iVar1 = FUN_4096c9b4(param_1,param_2);
    if (param_1[0x144] != 0) {
      FUN_409748f8(param_1[0x144]);
    }
    mali_frame_builder_write_unlock(param_1[0x13d]);
  }
  else {
    if (((iVar8 == 0) && (uVar12 != 0)) || ((in_stack_00000024 == 0 && (uVar5 != 0)))) {
      if ((uStack00000018 != 0) && (iVar1 == 0)) goto LAB_40976578;
      iVar1 = 0;
      goto LAB_40976584;
    }
    FUN_40975f94(piVar11,param_1[1],0,0,0);
    if (param_1[0x144] != 0) {
      FUN_409748f8(param_1[0x144]);
    }
    mali_frame_builder_write_unlock(param_1[0x13d]);
    mali_frame_builder_reset(param_1[0x13d]);
    iVar1 = FUN_40978694(param_1);
    if (iVar1 != 0) goto LAB_409766b8;
    iVar1 = FUN_40974c48((undefined4 *)param_1[0x144]);
  }
  if (iVar1 == 0) {
    if (param_1[1] == 2) {
      if (param_1[0x122] == 0) {
        param_1[0x134] = 0;
      }
      else {
        *(undefined4 *)(*piVar11 + 0x84) = 0;
      }
    }
    if (param_1[1] == 1) {
      param_1[0x134] = 0;
    }
  }
LAB_409766b8:
                    /* WARNING: Subroutine does not return */
  FUN_40993338(0x48);
}



/* 409766fc gles_finish */

/* Boundary evidence: original MIPS .pdata 409766fc..40976823. Semantic name remains unreviewed.
   gles_finish */

void gles_finish(undefined4 *param_1)

{
  int iVar1;
  int iVar2;
  
                    /* 0x166fc  7  _gles_finish */
  FUN_40993370();
  if (*(code **)(param_1[2] + 0x3b4) != (code *)0x0) {
    (**(code **)(param_1[2] + 0x3b4))(param_1);
  }
  if ((((param_1[1] != 2) || (param_1[0x122] == 0)) ||
      (iVar1 = FUN_40972840((int)param_1), iVar1 == 0)) &&
     ((iVar1 = param_1[0x13e], iVar1 != 0 && ((param_1[0x122] != 0 || (param_1[0x12e] != 0)))))) {
    iVar2 = mali_frame_builder_flush(iVar1,0,0);
    if (iVar2 == 0) {
      mali_frame_builder_wait(iVar1);
      FUN_40978128((int)param_1);
    }
    else {
      mali_frame_builder_reset(param_1[0x13d]);
      iVar1 = FUN_40978694(param_1);
      if (iVar1 == 0) {
        FUN_40974c48((undefined4 *)param_1[0x144]);
      }
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_40993390(0x10);
}



/* 40976824 gles_flush */

/* Boundary evidence: original MIPS .pdata 40976824..40976923. Semantic name remains unreviewed.
   gles_flush */

int gles_flush(undefined4 *param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
                    /* 0x16824  8  _gles_flush */
  uVar3 = 0;
  if (*(code **)(param_1[2] + 0x3b4) != (code *)0x0) {
    (**(code **)(param_1[2] + 0x3b4))(param_1);
  }
  if ((param_1[1] == 2) && (param_1[0x122] != 0)) {
    iVar1 = FUN_40972840((int)param_1);
    if (iVar1 != 0) {
      return iVar1;
    }
    uVar3 = param_1[0x121];
  }
  iVar1 = mali_frame_builder_flush(param_1[0x13d],0,uVar3);
  if (iVar1 != 0) {
    mali_frame_builder_reset(param_1[0x13d]);
    iVar2 = FUN_40978694(param_1);
    if ((iVar2 == 0) && (iVar2 = FUN_40974c48((undefined4 *)param_1[0x144]), iVar2 == 0)) {
      iVar2 = iVar1;
    }
    if (((iVar2 != -3) && (-3 < iVar2)) && (iVar2 < 0)) {
      return 0x505;
    }
  }
  return 0;
}



/* 40976924 FUN_40976924 */

undefined4 FUN_40976924(int param_1,int param_2)

{
  int iVar1;
  
  if (param_2 == 0x1401) {
    if (param_1 == 0x1906) {
      return 1;
    }
    if (param_1 == 0x1907) {
      return 3;
    }
    if (param_1 == 0x1908) {
      return 4;
    }
    if (param_1 == 0x1909) {
      return 1;
    }
    if (param_1 == 0x190a) {
      return 2;
    }
  }
  else if (param_2 == 0x1403) {
    if (param_1 == 0x1908) {
      return 8;
    }
    if (param_1 == 0x190a) {
      return 4;
    }
  }
  else {
    if ((param_2 == 0x8033) || (param_2 - 0x8033U < 2)) {
      iVar1 = 0x1908;
    }
    else {
      if (param_2 != 0x8363) {
        return 0;
      }
      iVar1 = 0x1907;
    }
    if (param_1 == iVar1) {
      return 2;
    }
  }
  return 0;
}



/* 409769fc FUN_409769fc */

undefined4 FUN_409769fc(uint param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (0x13ff < param_1) {
    if (param_1 < 0x1402) {
      uVar1 = 1;
    }
    else if (param_1 < 0x1404) {
      uVar1 = 2;
    }
    else if ((param_1 == 0x1406) || (param_1 == 0x140c)) {
      uVar1 = 4;
    }
  }
  return uVar1;
}



/* 40976ab8 FUN_40976ab8 */

/* Boundary evidence: original MIPS .pdata 40976ab8..40976b5b. Semantic name remains unreviewed. */

void FUN_40976ab8(int param_1,int param_2,undefined1 *param_3,int param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined1 *puVar4;
  undefined1 in_stack_00000020;
  int iStack00000024;
  int in_stack_00000060;
  int in_stack_00000064;
  code *in_stack_00000070;
  
  FUN_40993300();
  iVar3 = in_stack_00000060;
  iStack00000024 = param_4;
  if (0 < in_stack_00000064) {
    do {
      iVar1 = param_1;
      iVar2 = iVar3;
      puVar4 = param_3;
      if (0 < iVar3) {
        do {
          iVar1 = (*in_stack_00000070)(iVar1,&stack0x00000020,&stack0x00000023,&stack0x00000022);
          iVar3 = iVar3 + -1;
          *puVar4 = in_stack_00000020;
          iVar2 = in_stack_00000060;
          param_4 = iStack00000024;
          puVar4 = puVar4 + 1;
        } while (iVar3 != 0);
      }
      in_stack_00000064 = in_stack_00000064 + -1;
      param_1 = param_1 + param_2;
      param_3 = param_3 + param_4;
      iVar3 = iVar2;
    } while (in_stack_00000064 != 0);
  }
                    /* WARNING: Subroutine does not return */
  FUN_40993338(0x28);
}



/* 40976b5c FUN_40976b5c */

/* Boundary evidence: original MIPS .pdata 40976b5c..40976c0b. Semantic name remains unreviewed. */

void FUN_40976b5c(int param_1,int param_2,undefined1 *param_3,int param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined1 *puVar4;
  undefined1 in_stack_00000020;
  undefined1 in_stack_00000021;
  int iStack00000024;
  int in_stack_00000060;
  int in_stack_00000064;
  code *in_stack_00000070;
  
  FUN_40993300();
  iVar3 = in_stack_00000060;
  iStack00000024 = param_4;
  if (0 < in_stack_00000064) {
    do {
      iVar1 = param_1;
      iVar2 = iVar3;
      puVar4 = param_3;
      if (0 < iVar3) {
        do {
          iVar1 = (*in_stack_00000070)(iVar1,&stack0x00000021,&stack0x00000020,&stack0x00000023);
          iVar3 = iVar3 + -1;
          *puVar4 = in_stack_00000020;
          puVar4[1] = in_stack_00000021;
          iVar2 = in_stack_00000060;
          param_4 = iStack00000024;
          puVar4 = puVar4 + 2;
        } while (iVar3 != 0);
      }
      in_stack_00000064 = in_stack_00000064 + -1;
      param_1 = param_1 + param_2;
      param_3 = param_3 + param_4;
      iVar3 = iVar2;
    } while (in_stack_00000064 != 0);
  }
                    /* WARNING: Subroutine does not return */
  FUN_40993338(0x28);
}



/* 40976c0c FUN_40976c0c */

/* Boundary evidence: original MIPS .pdata 40976c0c..40976caf. Semantic name remains unreviewed. */

void FUN_40976c0c(int param_1,int param_2,undefined1 *param_3,int param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined1 *puVar4;
  undefined1 in_stack_00000020;
  int iStack00000024;
  int in_stack_00000060;
  int in_stack_00000064;
  code *in_stack_00000070;
  
  FUN_40993300();
  iVar3 = in_stack_00000060;
  iStack00000024 = param_4;
  if (0 < in_stack_00000064) {
    do {
      iVar1 = param_1;
      iVar2 = iVar3;
      puVar4 = param_3;
      if (0 < iVar3) {
        do {
          iVar1 = (*in_stack_00000070)(iVar1,&stack0x00000023,&stack0x00000020,&stack0x00000022);
          iVar3 = iVar3 + -1;
          *puVar4 = in_stack_00000020;
          iVar2 = in_stack_00000060;
          param_4 = iStack00000024;
          puVar4 = puVar4 + 1;
        } while (iVar3 != 0);
      }
      in_stack_00000064 = in_stack_00000064 + -1;
      param_1 = param_1 + param_2;
      param_3 = param_3 + param_4;
      iVar3 = iVar2;
    } while (in_stack_00000064 != 0);
  }
                    /* WARNING: Subroutine does not return */
  FUN_40993338(0x28);
}



/* 40976cb0 FUN_40976cb0 */

/* Boundary evidence: original MIPS .pdata 40976cb0..40976d6b. Semantic name remains unreviewed. */

void FUN_40976cb0(int param_1,int param_2,undefined1 *param_3,int param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined1 *puVar4;
  undefined1 in_stack_00000020;
  undefined1 in_stack_00000021;
  undefined1 in_stack_00000022;
  int iStack00000024;
  int in_stack_00000060;
  int in_stack_00000064;
  code *in_stack_00000070;
  
  FUN_40993300();
  iVar3 = in_stack_00000060;
  iStack00000024 = param_4;
  if (0 < in_stack_00000064) {
    do {
      iVar1 = param_1;
      iVar2 = iVar3;
      puVar4 = param_3;
      if (0 < iVar3) {
        do {
          iVar1 = (*in_stack_00000070)(iVar1,&stack0x00000023,&stack0x00000020,&stack0x00000021);
          iVar3 = iVar3 + -1;
          *puVar4 = in_stack_00000020;
          puVar4[1] = in_stack_00000021;
          puVar4[2] = in_stack_00000022;
          iVar2 = in_stack_00000060;
          param_4 = iStack00000024;
          puVar4 = puVar4 + 3;
        } while (iVar3 != 0);
      }
      in_stack_00000064 = in_stack_00000064 + -1;
      param_1 = param_1 + param_2;
      param_3 = param_3 + param_4;
      iVar3 = iVar2;
    } while (in_stack_00000064 != 0);
  }
                    /* WARNING: Subroutine does not return */
  FUN_40993338(0x28);
}



/* 40976d6c FUN_40976d6c */

/* Boundary evidence: original MIPS .pdata 40976d6c..40976e33. Semantic name remains unreviewed. */

void FUN_40976d6c(int param_1,int param_2,undefined1 *param_3,int param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined1 *puVar4;
  undefined1 in_stack_00000020;
  undefined1 in_stack_00000021;
  undefined1 in_stack_00000022;
  undefined1 in_stack_00000023;
  int iStack00000024;
  int in_stack_00000060;
  int in_stack_00000064;
  code *in_stack_00000070;
  
  FUN_40993300();
  iVar3 = in_stack_00000060;
  iStack00000024 = param_4;
  if (0 < in_stack_00000064) {
    do {
      iVar1 = param_1;
      iVar2 = iVar3;
      puVar4 = param_3;
      if (0 < iVar3) {
        do {
          iVar1 = (*in_stack_00000070)(iVar1,&stack0x00000023,&stack0x00000020,&stack0x00000021);
          iVar3 = iVar3 + -1;
          *puVar4 = in_stack_00000020;
          puVar4[1] = in_stack_00000021;
          puVar4[2] = in_stack_00000022;
          puVar4[3] = in_stack_00000023;
          iVar2 = in_stack_00000060;
          param_4 = iStack00000024;
          puVar4 = puVar4 + 4;
        } while (iVar3 != 0);
      }
      in_stack_00000064 = in_stack_00000064 + -1;
      param_1 = param_1 + param_2;
      param_3 = param_3 + param_4;
      iVar3 = iVar2;
    } while (in_stack_00000064 != 0);
  }
                    /* WARNING: Subroutine does not return */
  FUN_40993338(0x28);
}



/* 40976e34 FUN_40976e34 */

/* Boundary evidence: original MIPS .pdata 40976e34..40976f3b. Semantic name remains unreviewed. */

void FUN_40976e34(int param_1,int param_2,byte *param_3,int param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  byte *pbVar4;
  byte in_stack_00000020;
  byte in_stack_00000021;
  byte in_stack_00000022;
  byte in_stack_00000023;
  int iStack00000024;
  int in_stack_00000060;
  int in_stack_00000064;
  code *in_stack_00000070;
  
  FUN_40993300();
  iVar3 = in_stack_00000060;
  iStack00000024 = param_4;
  if (0 < in_stack_00000064) {
    do {
      iVar1 = param_1;
      iVar2 = iVar3;
      pbVar4 = param_3;
      if (0 < iVar3) {
        do {
          iVar1 = (*in_stack_00000070)(iVar1,&stack0x00000023,&stack0x00000020,&stack0x00000021);
          iVar3 = iVar3 + -1;
          in_stack_00000020 = in_stack_00000020 >> 3;
          in_stack_00000021 = in_stack_00000021 >> 3;
          in_stack_00000022 = in_stack_00000022 >> 3;
          in_stack_00000023 = in_stack_00000023 >> 7;
          iVar2 = (((uint)in_stack_00000020 << 5 | (uint)in_stack_00000021) << 5 |
                  (uint)in_stack_00000022) << 1;
          *pbVar4 = (byte)iVar2 | in_stack_00000023;
          pbVar4[1] = (byte)((uint)iVar2 >> 8);
          iVar2 = in_stack_00000060;
          param_4 = iStack00000024;
          pbVar4 = pbVar4 + 2;
        } while (iVar3 != 0);
      }
      in_stack_00000064 = in_stack_00000064 + -1;
      param_1 = param_1 + param_2;
      param_3 = param_3 + param_4;
      iVar3 = iVar2;
    } while (in_stack_00000064 != 0);
  }
                    /* WARNING: Subroutine does not return */
  FUN_40993338(0x28);
}



/* 40976f3c FUN_40976f3c */

/* Boundary evidence: original MIPS .pdata 40976f3c..40977043. Semantic name remains unreviewed. */

void FUN_40976f3c(int param_1,int param_2,byte *param_3,int param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  byte *pbVar4;
  byte in_stack_00000020;
  byte in_stack_00000021;
  byte in_stack_00000022;
  byte in_stack_00000023;
  int iStack00000024;
  int in_stack_00000060;
  int in_stack_00000064;
  code *in_stack_00000070;
  
  FUN_40993300();
  iVar3 = in_stack_00000060;
  iStack00000024 = param_4;
  if (0 < in_stack_00000064) {
    do {
      iVar1 = param_1;
      iVar2 = iVar3;
      pbVar4 = param_3;
      if (0 < iVar3) {
        do {
          iVar1 = (*in_stack_00000070)(iVar1,&stack0x00000023,&stack0x00000020,&stack0x00000021);
          iVar3 = iVar3 + -1;
          in_stack_00000020 = in_stack_00000020 >> 4;
          in_stack_00000021 = in_stack_00000021 >> 4;
          in_stack_00000022 = in_stack_00000022 >> 4;
          in_stack_00000023 = in_stack_00000023 >> 4;
          iVar2 = (((uint)in_stack_00000020 << 4 | (uint)in_stack_00000021) << 4 |
                  (uint)in_stack_00000022) << 4;
          *pbVar4 = (byte)iVar2 | in_stack_00000023;
          pbVar4[1] = (byte)((uint)iVar2 >> 8);
          iVar2 = in_stack_00000060;
          param_4 = iStack00000024;
          pbVar4 = pbVar4 + 2;
        } while (iVar3 != 0);
      }
      in_stack_00000064 = in_stack_00000064 + -1;
      param_1 = param_1 + param_2;
      param_3 = param_3 + param_4;
      iVar3 = iVar2;
    } while (in_stack_00000064 != 0);
  }
                    /* WARNING: Subroutine does not return */
  FUN_40993338(0x28);
}



/* 40977044 FUN_40977044 */

/* Boundary evidence: original MIPS .pdata 40977044..40977133. Semantic name remains unreviewed. */

void FUN_40977044(int param_1,int param_2,byte *param_3,int param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  byte *pbVar4;
  byte in_stack_00000020;
  byte in_stack_00000021;
  byte in_stack_00000022;
  int iStack00000024;
  int in_stack_00000060;
  int in_stack_00000064;
  code *in_stack_00000070;
  
  FUN_40993300();
  iVar3 = in_stack_00000060;
  iStack00000024 = param_4;
  if (0 < in_stack_00000064) {
    do {
      iVar1 = param_1;
      iVar2 = iVar3;
      pbVar4 = param_3;
      if (0 < iVar3) {
        do {
          iVar1 = (*in_stack_00000070)(iVar1,&stack0x00000023,&stack0x00000020,&stack0x00000021);
          iVar3 = iVar3 + -1;
          in_stack_00000020 = in_stack_00000020 >> 3;
          in_stack_00000021 = in_stack_00000021 >> 2;
          in_stack_00000022 = in_stack_00000022 >> 3;
          iVar2 = ((uint)in_stack_00000020 << 6 | (uint)in_stack_00000021) << 5;
          *pbVar4 = (byte)iVar2 | in_stack_00000022;
          pbVar4[1] = (byte)((uint)iVar2 >> 8);
          iVar2 = in_stack_00000060;
          param_4 = iStack00000024;
          pbVar4 = pbVar4 + 2;
        } while (iVar3 != 0);
      }
      in_stack_00000064 = in_stack_00000064 + -1;
      param_1 = param_1 + param_2;
      param_3 = param_3 + param_4;
      iVar3 = iVar2;
    } while (in_stack_00000064 != 0);
  }
                    /* WARNING: Subroutine does not return */
  FUN_40993338(0x28);
}



/* 409773d4 FUN_409773d4 */

/* Boundary evidence: original MIPS .pdata 409773d4..4097742b. Semantic name remains unreviewed. */

undefined4 FUN_409773d4(int *param_1)

{
  undefined4 uVar1;
  
  if (*param_1 == -1) {
    if (param_1[1] == 0x3f) {
      uVar1 = 0;
    }
    else {
      uVar1 = __m200_texel_format_get_bpp();
    }
  }
  else {
    uVar1 = __mali_pixel_format_get_bpp(*param_1);
  }
  return uVar1;
}



/* 4097742c FUN_4097742c */

/* Boundary evidence: original MIPS .pdata 4097742c..409774cb. Semantic name remains unreviewed. */

void FUN_4097742c(undefined4 *param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  FUN_40993370();
  uVar2 = param_1[0x13e];
  iVar1 = mali_frame_builder_flush(uVar2,0,0);
  if (iVar1 == 0) {
    mali_frame_builder_wait(uVar2);
    FUN_40978128((int)param_1);
  }
  else {
    mali_frame_builder_reset(param_1[0x13d]);
    iVar1 = FUN_40978694(param_1);
    if (iVar1 == 0) {
      FUN_40974c48((undefined4 *)param_1[0x144]);
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_40993390(0x10);
}



/* 409774cc FUN_409774cc */

/* Boundary evidence: original MIPS .pdata 409774cc..40977b17. Semantic name remains unreviewed. */

void FUN_409774cc(undefined4 *param_1,int param_2,int param_3,int param_4)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  int iStack00000028;
  int iStack0000002c;
  undefined4 *puStack00000038;
  int iStack00000048;
  int iStack0000004c;
  int in_stack_00000088;
  int in_stack_0000008c;
  int in_stack_00000090;
  byte *in_stack_00000094;
  uint in_stack_00000098;
  
  FUN_40993300();
  puStack00000038 = param_1;
  iStack00000048 = param_2;
  iStack0000004c = param_3;
  if (((((in_stack_00000090 != 0x1401) ||
        ((((in_stack_0000008c != 0x1906 && (in_stack_0000008c != 0x1909)) &&
          (in_stack_0000008c != 0x190a)) &&
         ((in_stack_0000008c != 0x1908 && (in_stack_0000008c != 0x1907)))))) &&
       ((in_stack_00000090 != 0x8033 || (in_stack_0000008c != 0x1908)))) &&
      (((in_stack_00000090 != 0x8034 || (in_stack_0000008c != 0x1908)) &&
       ((in_stack_00000090 != 0x8363 || (in_stack_0000008c != 0x1907)))))) ||
     (((((param_1[1] == 2 && (param_1[0x122] != 0)) &&
        (iVar2 = FUN_40972840((int)param_1), iVar2 != 0)) ||
       ((iVar2 = FUN_4097742c(param_1), iVar2 != 0 ||
        (iVar2 = mali_frame_builder_get_attachment(param_1[0x13e],0), iVar2 == 0)))) ||
      (iVar3 = mali_render_attachment_get_target(iVar2,0,0), iVar3 == 0)))) goto LAB_40977b0c;
  uVar5 = (uint)*(ushort *)(iVar3 + 0xc);
  uVar7 = (uint)*(ushort *)(iVar3 + 0xe);
  iVar9 = *(int *)(iVar3 + 0x14);
  if ((uVar5 == 0) || (uVar7 == 0)) goto LAB_40977b0c;
  mali_surface_access_lock(iVar3);
  iVar4 = mali_surface_map(iVar3,1);
  if (iVar4 == 0) {
LAB_40977764:
    mali_surface_access_unlock(iVar3);
  }
  else {
    iStack0000002c = 0;
    mali_render_attachment_get_modifier_flags(iVar2);
    mali_render_attachment_get_modifier_flags(iVar2);
    uVar6 = (uint)*(ushort *)(iVar3 + 0x10);
    if (iVar9 == 0) {
      iStack00000028 = 2;
    }
    else if (iVar9 == 1) {
      iStack00000028 = 2;
    }
    else if (iVar9 == 2) {
      iStack00000028 = 2;
    }
    else {
      if (iVar9 != 3) {
        mali_surface_unmap(iVar3);
        goto LAB_40977764;
      }
      iStack00000028 = 4;
    }
    iVar2 = iVar4;
    if ((puStack00000038[1] == 2) && (puStack00000038[0x122] != 0)) {
      iVar2 = mali_sys_malloc(*(undefined4 *)(iVar3 + 0x2c));
      if (iVar2 == 0) {
        mali_surface_unmap(iVar3);
        goto LAB_40977764;
      }
      uVar6 = FUN_409773d4((int *)(iVar3 + 0x14));
      uVar6 = (uVar6 >> 3) * (uint)*(ushort *)(iVar3 + 0xc);
      mali_pixel_to_texel_format(iVar9);
      iVar9 = m200_texture_swizzle(iVar2,0,iVar4,*(undefined4 *)(iVar3 + 0x20));
      iStack0000002c = iVar2;
      if (iVar9 != 0) {
        mali_surface_unmap(iVar3);
        mali_surface_access_unlock(iVar3);
        goto LAB_40977b0c;
      }
    }
    puVar1 = puStack00000038;
    iVar9 = 2;
    if (puStack00000038[0x123] != 0) {
      iVar2 = (uVar7 - 1) * uVar6 + iVar2;
      uVar6 = -uVar6;
    }
    if (in_stack_00000090 == 0x1401) {
      if ((in_stack_0000008c == 0x1906) || (in_stack_0000008c == 0x1909)) {
        iVar9 = 1;
      }
      else if (in_stack_0000008c != 0x190a) {
        if (in_stack_0000008c == 0x1907) {
          iVar9 = 3;
        }
        else {
          iVar9 = 4;
          if (in_stack_0000008c != 0x1908) {
            iVar9 = 0;
          }
        }
      }
    }
    if (in_stack_00000098 == 0) {
      trap(0x1c00);
    }
    iVar4 = (((iVar9 * param_4 + in_stack_00000098) - 1) / in_stack_00000098) * in_stack_00000098;
    iVar8 = iStack00000048;
    if (iStack00000048 < 0) {
      param_4 = iStack00000048 + param_4;
      in_stack_00000094 = in_stack_00000094 + -(iVar9 * iStack00000048);
      iVar8 = 0;
    }
    iVar9 = iStack0000004c;
    if (iStack0000004c < 0) {
      in_stack_00000088 = iStack0000004c + in_stack_00000088;
      in_stack_00000094 = in_stack_00000094 + -(iVar4 * iStack0000004c);
      iVar9 = 0;
    }
    if ((int)uVar5 < iVar8 + param_4) {
      param_4 = uVar5 - iVar8;
    }
    if ((int)uVar7 < iVar9 + in_stack_00000088) {
      in_stack_00000088 = uVar7 - iVar9;
    }
    iVar2 = iStack00000028 * iVar8 + uVar6 * iVar9 + iVar2;
    if ((0 < param_4) && (0 < in_stack_00000088)) {
      if (in_stack_00000090 == 0x1401) {
        if (in_stack_0000008c == 0x1906) {
          FUN_40976ab8(iVar2,uVar6,in_stack_00000094,iVar4);
        }
        else if (in_stack_0000008c == 0x1907) {
          FUN_40976cb0(iVar2,uVar6,in_stack_00000094,iVar4);
        }
        else if (in_stack_0000008c == 0x1908) {
          FUN_40976d6c(iVar2,uVar6,in_stack_00000094,iVar4);
        }
        else if (in_stack_0000008c == 0x1909) {
          FUN_40976c0c(iVar2,uVar6,in_stack_00000094,iVar4);
        }
        else if (in_stack_0000008c == 0x190a) {
          FUN_40976b5c(iVar2,uVar6,in_stack_00000094,iVar4);
        }
      }
      else if (in_stack_00000090 == 0x8033) {
        FUN_40976f3c(iVar2,uVar6,in_stack_00000094,iVar4);
      }
      else if (in_stack_00000090 == 0x8034) {
        FUN_40976e34(iVar2,uVar6,in_stack_00000094,iVar4);
      }
      else if (in_stack_00000090 == 0x8363) {
        FUN_40977044(iVar2,uVar6,in_stack_00000094,iVar4);
      }
    }
    if ((puVar1[1] == 2) && (iStack0000002c != 0)) {
      mali_sys_free(iStack0000002c);
    }
    mali_surface_unmap(iVar3);
    mali_surface_access_unlock(iVar3);
  }
LAB_40977b0c:
                    /* WARNING: Subroutine does not return */
  FUN_40993338(0x50);
}



/* 40977b18 FUN_40977b18 */

/* Boundary evidence: original MIPS .pdata 40977b18..40977bd3. Semantic name remains unreviewed. */

undefined4
FUN_40977b18(undefined4 *param_1,int param_2,int param_3,int param_4,int param_5,int param_6,
            int param_7,int param_8)

{
  undefined4 uVar1;
  
  if (((param_6 == 0x1908) || (param_6 == 0x1907)) && ((param_7 == 0x1401 || (param_7 == 0x8363))))
  {
    if ((param_4 < 0) || (param_5 < 0)) {
      return 0x501;
    }
    if (param_6 == 0x1908) {
      if (param_7 != 0x1401) {
        return 0x502;
      }
    }
    else if ((param_6 == 0x1907) && (param_7 != 0x8363)) {
      return 0x502;
    }
    if (param_8 == 0) {
      return 0x502;
    }
    uVar1 = FUN_409774cc(param_1,param_2,param_3,param_4);
    return uVar1;
  }
  return 0x500;
}



/* 40977bd4 FUN_40977bd4 */

/* Boundary evidence: original MIPS .pdata 40977bd4..40977c6b. Semantic name remains unreviewed. */

undefined4 FUN_40977bd4(int param_1)

{
  int iVar1;
  undefined **ppuVar2;
  int iVar3;
  
  if (param_1 != 0) {
    iVar3 = 1;
    ppuVar2 = &PTR_s_glQueryMatrixxOES_40962a14;
    do {
      iVar1 = mali_sys_strcmp(*ppuVar2,param_1);
      if (iVar1 == 0) {
        return *(undefined4 *)(&UNK_40962a10 + iVar3 * 8);
      }
      ppuVar2 = ppuVar2 + 2;
      iVar3 = iVar3 + 1;
    } while ((int)ppuVar2 < 0x40962a44);
  }
  return 0;
}



/* 40977c6c FUN_40977c6c */

/* Boundary evidence: original MIPS .pdata 40977c6c..40977ca3. Semantic name remains unreviewed. */

void FUN_40977c6c(int param_1,int param_2)

{
  if (param_2 == 2) {
    mali_sys_atomic_inc(param_1 + 0xc);
  }
  mali_sys_atomic_inc(param_1);
  return;
}



/* 40977ca4 FUN_40977ca4 */

/* Boundary evidence: original MIPS .pdata 40977ca4..40977d5b. Semantic name remains unreviewed. */

undefined4 FUN_40977ca4(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = __mali_named_list_allocate();
  *(int *)(param_1 + 4) = iVar1;
  if (iVar1 != 0) {
    iVar1 = __mali_named_list_allocate();
    *(int *)(param_1 + 8) = iVar1;
    if (iVar1 != 0) {
      iVar1 = __mali_named_list_allocate();
      *(int *)(param_1 + 0x10) = iVar1;
      if (iVar1 != 0) {
        iVar1 = __mali_named_list_allocate();
        *(int *)(param_1 + 0x14) = iVar1;
        if (iVar1 != 0) {
          iVar1 = __mali_named_list_allocate();
          *(int *)(param_1 + 0x18) = iVar1;
          if (iVar1 != 0) {
            mali_sys_atomic_initialize(param_1,1);
            mali_sys_atomic_initialize(param_1 + 0xc,param_2 == 2);
            iVar1 = mali_sys_mutex_create();
            *(int *)(param_1 + 0x1c) = iVar1;
            if (iVar1 != 0) {
              return 0;
            }
          }
        }
      }
    }
  }
  return 0xffffffff;
}



/* 40977d5c FUN_40977d5c */

/* Boundary evidence: original MIPS .pdata 40977d5c..40977d77. Semantic name remains unreviewed. */

void FUN_40977d5c(int param_1)

{
  mali_sys_mutex_unlock(*(undefined4 *)(param_1 + 0x1c));
  return;
}



/* 40977d78 FUN_40977d78 */

/* Boundary evidence: original MIPS .pdata 40977d78..40977d93. Semantic name remains unreviewed. */

void FUN_40977d78(int param_1)

{
  mali_sys_mutex_lock(*(undefined4 *)(param_1 + 0x1c));
  return;
}



/* 40977d94 FUN_40977d94 */

/* Boundary evidence: original MIPS .pdata 40977d94..40977e3f. Semantic name remains unreviewed. */

void FUN_40977d94(int param_1)

{
  if (*(int *)(param_1 + 4) != 0) {
    __mali_named_list_free(*(int *)(param_1 + 4),FUN_4097c058);
  }
  *(undefined4 *)(param_1 + 4) = 0;
  if (*(int *)(param_1 + 8) != 0) {
    __mali_named_list_free(*(int *)(param_1 + 8),FUN_409797b8);
  }
  *(undefined4 *)(param_1 + 8) = 0;
  if (*(int *)(param_1 + 0x10) != 0) {
    __mali_named_list_free(*(int *)(param_1 + 0x10),0);
  }
  *(undefined4 *)(param_1 + 0x10) = 0;
  if (*(int *)(param_1 + 0x14) != 0) {
    __mali_named_list_free(*(int *)(param_1 + 0x14),0);
  }
  *(undefined4 *)(param_1 + 0x14) = 0;
  if (*(int *)(param_1 + 0x18) != 0) {
    __mali_named_list_free(*(int *)(param_1 + 0x18),0);
  }
  *(undefined4 *)(param_1 + 0x18) = 0;
  if (*(int *)(param_1 + 0x1c) != 0) {
    mali_sys_mutex_destroy();
  }
  *(undefined4 *)(param_1 + 0x1c) = 0;
  mali_sys_free(param_1);
  return;
}



/* 40977e40 FUN_40977e40 */

/* Boundary evidence: original MIPS .pdata 40977e40..40977e9f. Semantic name remains unreviewed. */

void FUN_40977e40(int param_1,int param_2)

{
  int iVar1;
  
  if ((param_2 == 2) && (iVar1 = mali_sys_atomic_dec_and_return(param_1 + 0xc), iVar1 == 0)) {
    mali_sys_mutex_lock(*(undefined4 *)(param_1 + 0x1c));
    mali_sys_mutex_unlock(*(undefined4 *)(param_1 + 0x1c));
  }
  iVar1 = mali_sys_atomic_dec_and_return(param_1);
  if (iVar1 == 0) {
    FUN_40977d94(param_1);
  }
  return;
}



/* 40977ea0 FUN_40977ea0 */

/* Boundary evidence: original MIPS .pdata 40977ea0..40977f0f. Semantic name remains unreviewed. */

int FUN_40977ea0(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = mali_sys_malloc(0x20);
  if (iVar1 != 0) {
    mali_sys_memset(iVar1,0,0x20);
    iVar2 = FUN_40977ca4(iVar1,param_1);
    if (iVar2 == 0) {
      return iVar1;
    }
    FUN_40977d94(iVar1);
  }
  return 0;
}



/* 40977f10 FUN_40977f10 */

/* Boundary evidence: original MIPS .pdata 40977f10..40977f6b. Semantic name remains unreviewed. */

void FUN_40977f10(int param_1)

{
  uint uVar1;
  
  uVar1 = mali_pp_get_core_product_id();
  if (uVar1 >> 8 == 0xcd) {
    mali_sys_snprintf(param_1,0x20,"Mali-400 MP");
  }
  else {
    mali_sys_snprintf(param_1,0x20,"Mali-%d");
  }
  *(undefined1 *)(param_1 + 0x1f) = 0;
  return;
}



/* 40977f6c gles_shutdown */

/* Boundary evidence: original MIPS .pdata 40977f6c..40977fa3. Semantic name remains unreviewed.
   gles_shutdown */

void gles_shutdown(int *param_1)

{
                    /* 0x17f6c  14  _gles_shutdown */
  if (*param_1 != 0) {
    mali_sys_mutex_destroy();
    *param_1 = 0;
  }
  return;
}



/* 40977fa4 gles_initialize */

/* Boundary evidence: original MIPS .pdata 40977fa4..40977fff. Semantic name remains unreviewed.
   gles_initialize */

undefined4 gles_initialize(int *param_1)

{
  int iVar1;
  
                    /* 0x17fa4  9  _gles_initialize */
  DAT_40996364 = param_1;
  if (*param_1 == 0) {
    iVar1 = mali_sys_mutex_create();
    *param_1 = iVar1;
    if (iVar1 == 0) {
      return 0xfffffffe;
    }
    param_1[1] = 0;
    param_1[2] = 0;
    param_1[3] = 0;
  }
  return 0;
}



/* 40978000 gles_make_current */

/* Boundary evidence: original MIPS .pdata 40978000..409780d3. Semantic name remains unreviewed.
   gles_make_current */

int gles_make_current(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  
                    /* 0x18000  10  _gles_make_current */
  puVar1 = DAT_40996364;
  iVar2 = mali_sys_thread_key_get_data(4);
  iVar3 = mali_sys_thread_key_set_data(4,param_1);
  if (iVar3 == 0) {
    mali_sys_mutex_lock(*DAT_40996364);
    if ((iVar2 != 0) && (iVar2 = puVar1[1], puVar1[1] = iVar2 + -1, iVar2 + -1 == 0)) {
      puVar1[2] = 0;
      puVar1[3] = 0;
    }
    if (param_1 != 0) {
      iVar2 = puVar1[1];
      puVar1[1] = iVar2 + 1U;
      if (1 < iVar2 + 1U) {
        puVar1[2] = 1;
      }
      if (puVar1[2] == 0) {
        puVar1[3] = param_1;
      }
    }
    mali_sys_mutex_unlock(*DAT_40996364);
    iVar3 = 0;
  }
  return iVar3;
}



/* 409780d4 FUN_409780d4 */

/* Boundary evidence: original MIPS .pdata 409780d4..4097811f. Semantic name remains unreviewed. */

undefined4 FUN_409780d4(void)

{
  undefined4 uVar1;
  
  if (DAT_40996364 == 0) {
    uVar1 = 0;
  }
  else if (*(int *)(DAT_40996364 + 8) == 0) {
    uVar1 = *(undefined4 *)(DAT_40996364 + 0xc);
  }
  else {
    uVar1 = mali_sys_thread_key_get_data(4);
  }
  return uVar1;
}



/* 40978128 FUN_40978128 */

/* Boundary evidence: original MIPS .pdata 40978128..409781d3. Semantic name remains unreviewed. */

void FUN_40978128(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 in_stack_00000010;
  
  FUN_40993370();
  uVar2 = 0;
  iVar1 = mali_frame_builder_get_framebuilder_completion_status(*(undefined4 *)(param_1 + 0x4f0));
  if (iVar1 != 0x10000) {
    uVar2 = 0x505;
  }
  if ((*(int *)(param_1 + 0x4e8) != 0) &&
     (iVar1 = *(int *)(*(int *)(param_1 + 0x4e8) + 0x10), iVar1 != 0)) {
    in_stack_00000010 = 0;
    iVar1 = __mali_named_list_iterate_begin(iVar1,&stack0x00000010);
    while (iVar1 != 0) {
      if ((*(int *)(iVar1 + 4) != 0) &&
         (iVar1 = mali_frame_builder_get_framebuilder_completion_status
                            (*(undefined4 *)(*(int *)(iVar1 + 4) + 0x6c)), iVar1 != 0x10000)) {
        uVar2 = 0x505;
      }
      iVar1 = __mali_named_list_iterate_next
                        (*(undefined4 *)(*(int *)(param_1 + 0x4e8) + 0x10),&stack0x00000010);
    }
  }
  if (*(int *)(param_1 + 0x10) == 0) {
    *(undefined4 *)(param_1 + 0x10) = uVar2;
  }
                    /* WARNING: Subroutine does not return */
  FUN_40993390(0x18);
}



/* 409782e4 gles_set_read_frame_builder */

/* Boundary evidence: original MIPS .pdata 409782e4..4097834f. Semantic name remains unreviewed.
   gles_set_read_frame_builder */

void gles_set_read_frame_builder(int param_1,undefined4 param_2,int param_3)

{
                    /* 0x182e4  12  _gles_set_read_frame_builder */
  FUN_40993370();
  if (*(int *)(param_1 + 0x4f8) == *(int *)(param_1 + 0x4ec)) {
    *(undefined4 *)(param_1 + 0x4f8) = param_2;
    mali_frame_builder_use(param_2);
  }
  *(undefined4 *)(param_1 + 0x4ec) = param_2;
  *(int *)(param_1 + 0x4b8) = param_3;
  if (param_3 == 1) {
    *(undefined4 *)(param_1 + 0x4bc) = 0;
  }
  else {
    *(undefined4 *)(param_1 + 0x4bc) = 1;
  }
  if (*(int *)(param_1 + 0x488) == 0) {
    *(undefined4 *)(param_1 + 0x48c) = *(undefined4 *)(param_1 + 0x4bc);
  }
                    /* WARNING: Subroutine does not return */
  FUN_40993390(0x10);
}



/* 40978350 FUN_40978350 */

/* Boundary evidence: original MIPS .pdata 40978350..4097838b. Semantic name remains unreviewed. */

void FUN_40978350(int param_1)

{
  if (*(int *)(param_1 + 0x510) != 0) {
    FUN_409748f8(*(int *)(param_1 + 0x510));
  }
  mali_frame_builder_write_unlock(*(undefined4 *)(param_1 + 0x4f4));
  return;
}



/* 4097838c FUN_4097838c */

/* Boundary evidence: original MIPS .pdata 4097838c..409783bb. Semantic name remains unreviewed. */

void FUN_4097838c(int param_1)

{
  FUN_409749c0(param_1);
  mali_sys_free(param_1);
  return;
}



/* 40978400 FUN_40978400 */

/* Boundary evidence: original MIPS .pdata 40978400..40978517. Semantic name remains unreviewed. */

undefined4 FUN_40978400(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int *piVar4;
  int local_28;
  undefined1 auStack_24 [4];
  undefined1 auStack_20 [4];
  undefined1 auStack_1c [4];
  undefined1 auStack_18 [4];
  undefined1 auStack_14 [4];
  
  iVar3 = *(int *)(param_1 + 0x484);
  if (iVar3 == 0) {
    local_28 = *(int *)(param_1 + 0x4a8);
    goto LAB_409784d4;
  }
  if (iVar3 != -0x48) {
    if (*(int *)(iVar3 + 0x50) == 0x1702) {
      iVar1 = FUN_40979e34(*(int *)(iVar3 + 100));
      piVar4 = *(int **)((iVar1 * 0xd + *(int *)(iVar3 + 0x60)) * 4 +
                        *(int *)(*(int *)(iVar3 + 0x58) + 0x34));
      if (piVar4 != (int *)0x0) {
        iVar3 = *piVar4;
        goto LAB_4097848c;
      }
    }
    else if (*(int *)(iVar3 + 0x50) == 0x8d41) {
      iVar3 = *(int *)(*(int *)(iVar3 + 0x58) + 0x28);
LAB_4097848c:
      if (iVar3 != 0) {
        mali_pixel_format_get_bpc
                  (*(undefined4 *)(iVar3 + 0x14),auStack_14,auStack_18,auStack_1c,auStack_20,
                   auStack_24,&local_28);
        goto LAB_409784d4;
      }
    }
  }
  local_28 = 0;
LAB_409784d4:
  uVar2 = 1;
  if (((*(uint *)(*(int *)(param_1 + 0x504) + 0x40) & 0x10) == 0) || (local_28 < 1)) {
    uVar2 = 0;
  }
  return uVar2;
}



/* 40978518 FUN_40978518 */

/* Boundary evidence: original MIPS .pdata 40978518..4097862f. Semantic name remains unreviewed. */

undefined4 FUN_40978518(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int *piVar4;
  int local_28;
  undefined1 auStack_24 [4];
  undefined1 auStack_20 [4];
  undefined1 auStack_1c [4];
  undefined1 auStack_18 [4];
  undefined1 auStack_14 [4];
  
  iVar3 = *(int *)(param_1 + 0x484);
  if (iVar3 == 0) {
    local_28 = *(int *)(param_1 + 0x4a4);
    goto LAB_409785ec;
  }
  if (iVar3 != -0x24) {
    if (*(int *)(iVar3 + 0x2c) == 0x1702) {
      iVar1 = FUN_40979e34(*(int *)(iVar3 + 0x40));
      piVar4 = *(int **)((iVar1 * 0xd + *(int *)(iVar3 + 0x3c)) * 4 +
                        *(int *)(*(int *)(iVar3 + 0x34) + 0x34));
      if (piVar4 != (int *)0x0) {
        iVar3 = *piVar4;
        goto LAB_409785a4;
      }
    }
    else if (*(int *)(iVar3 + 0x2c) == 0x8d41) {
      iVar3 = *(int *)(*(int *)(iVar3 + 0x34) + 0x28);
LAB_409785a4:
      if (iVar3 != 0) {
        mali_pixel_format_get_bpc
                  (*(undefined4 *)(iVar3 + 0x14),auStack_14,auStack_18,auStack_1c,auStack_20,
                   &local_28,auStack_24);
        goto LAB_409785ec;
      }
    }
  }
  local_28 = 0;
LAB_409785ec:
  uVar2 = 1;
  if (((*(uint *)(*(int *)(param_1 + 0x504) + 0x40) & 2) == 0) || (local_28 < 1)) {
    uVar2 = 0;
  }
  return uVar2;
}



/* 40978630 FUN_40978630 */

void FUN_40978630(int param_1,uint param_2,int param_3)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x504);
  *(char *)(iVar1 + 0x46) = (char)param_2;
  *(char *)(iVar1 + 0x47) = (char)param_3;
  if ((*(uint *)(iVar1 + 0x40) & 8) != 8) {
    if ((*(uint *)(iVar1 + 0x40) & 4) == 0) {
      param_3 = 2;
      param_2 = 2;
    }
    *(uint *)(iVar1 + 8) = (*(uint *)(iVar1 + 8) & 0xfffffff8 ^ param_2) & 0xffffffc7 ^ param_3 << 3
    ;
  }
  return;
}



/* 40978694 FUN_40978694 */

/* Boundary evidence: original MIPS .pdata 40978694..40978767. Semantic name remains unreviewed. */

int FUN_40978694(undefined4 *param_1)

{
  undefined4 *puVar1;
  uint uVar2;
  int iVar3;
  
  mali_frame_builder_wait(param_1[0x13d]);
  param_1[0x144] = 0;
  param_1[0x134] = 0;
  FUN_40978128((int)param_1);
  uVar2 = param_1[3];
  param_1[3] = uVar2 | 0x800000;
  param_1[3] = uVar2 | 0x1800000;
  puVar1 = (undefined4 *)mali_sys_malloc(0x10);
  param_1[0x144] = puVar1;
  if (puVar1 == (undefined4 *)0x0) {
    iVar3 = -1;
  }
  else {
    iVar3 = FUN_40974ce8(puVar1,*param_1);
    if (((iVar3 != 0) ||
        (iVar3 = mali_frame_builder_add_callback(param_1[0x13d],FUN_4097838c,param_1[0x144]),
        iVar3 != 0)) && (param_1[0x144] != 0)) {
      FUN_409749c0(param_1[0x144]);
      mali_sys_free(param_1[0x144]);
      param_1[0x144] = 0;
    }
  }
  return iVar3;
}



/* 40978768 FUN_40978768 */

void FUN_40978768(int param_1,int param_2)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = *(int *)(param_1 + 0x504);
  *(uint *)(iVar3 + 0x40) = *(uint *)(iVar3 + 0x40) & 0xfffff7ff | param_2 << 0xb;
  if (param_2 != 0) {
    iVar2 = 1;
    if ((*(int *)(param_1 + 0x484) != 0) || (bVar1 = true, *(int *)(param_1 + 0x4b0) < 1)) {
      bVar1 = false;
    }
    if (((*(uint *)(*(int *)(param_1 + 0x504) + 0x40) & 0x20) != 0) && (bVar1)) goto LAB_409787c8;
  }
  iVar2 = 0;
LAB_409787c8:
  *(uint *)(iVar3 + 0x20) = *(uint *)(iVar3 + 0x20) & 0xfffffeff ^ iVar2 << 8;
  return;
}



/* 409787e8 FUN_409787e8 */

void FUN_409787e8(int param_1,int param_2)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = *(int *)(param_1 + 0x504);
  *(uint *)(iVar3 + 0x40) = *(uint *)(iVar3 + 0x40) & 0xfffffbff | param_2 << 10;
  if (param_2 != 0) {
    iVar2 = 1;
    if ((*(int *)(param_1 + 0x484) != 0) || (bVar1 = true, *(int *)(param_1 + 0x4b0) < 1)) {
      bVar1 = false;
    }
    if (((*(uint *)(*(int *)(param_1 + 0x504) + 0x40) & 0x20) != 0) && (bVar1)) goto LAB_40978848;
  }
  iVar2 = 0;
LAB_40978848:
  *(uint *)(iVar3 + 0x20) = *(uint *)(iVar3 + 0x20) & 0xffffff7f ^ iVar2 << 7;
  return;
}



/* 40978868 FUN_40978868 */

void FUN_40978868(int param_1)

{
  bool bVar1;
  uint uVar2;
  int iVar3;
  
  iVar3 = *(int *)(param_1 + 0x504);
  uVar2 = 1;
  if ((*(int *)(param_1 + 0x484) != 0) || (bVar1 = true, *(int *)(param_1 + 0x4b0) < 1)) {
    bVar1 = false;
  }
  if (((*(uint *)(iVar3 + 0x40) & 0x20) == 0) || (!bVar1)) {
    uVar2 = 0;
  }
  *(uint *)(iVar3 + 0x20) =
       ((uVar2 ^ uVar2 << 2) << 3 ^ *(uint *)(iVar3 + 0x20) & 0xffffffd7) & 0xffffffbf ^ uVar2 << 6;
  return;
}



/* 409788ec FUN_409788ec */

/* Boundary evidence: original MIPS .pdata 409788ec..40978a0f. Semantic name remains unreviewed. */

void FUN_409788ec(int param_1,undefined4 param_2,int param_3)

{
  bool bVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  
  iVar4 = *(int *)(param_1 + 0x504);
  *(undefined4 *)(iVar4 + 0x60) = param_2;
  *(char *)(iVar4 + 100) = (char)param_3;
  uVar3 = 0;
  if ((*(int *)(param_1 + 0x484) != 0) || (bVar1 = true, *(int *)(param_1 + 0x4b0) < 1)) {
    bVar1 = false;
  }
  if ((((*(uint *)(*(int *)(param_1 + 0x504) + 0x40) & 0x20) == 0) || (!bVar1)) ||
     ((*(uint *)(iVar4 + 0x40) & 0x40) == 0)) {
    param_2 = 0x3f800000;
    param_3 = 0;
  }
  iVar2 = __gts(param_2,0x3f600000);
  if (iVar2 != 0) {
    uVar3 = 8;
  }
  iVar2 = __gts(param_2,0x3f200000);
  if (iVar2 != 0) {
    uVar3 = uVar3 | 4;
  }
  iVar2 = __gts(param_2,0x3ec00000);
  if (iVar2 != 0) {
    uVar3 = uVar3 | 2;
  }
  iVar2 = __gts(param_2,0x3e000000);
  if (iVar2 != 0) {
    uVar3 = uVar3 | 1;
  }
  if (param_3 != 0) {
    uVar3 = uVar3 ^ 0xf;
  }
  *(uint *)(iVar4 + 0x20) = uVar3 << 0xc ^ *(uint *)(iVar4 + 0x20) & 0xffff0fff;
  return;
}



/* 40978a10 FUN_40978a10 */

/* Boundary evidence: original MIPS .pdata 40978a10..40978a6b. Semantic name remains unreviewed. */

void FUN_40978a10(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0x504);
  *(char *)(iVar2 + 0x59) = (char)param_2;
  iVar1 = FUN_40978400(param_1);
  if (iVar1 == 0) {
    param_2 = 0;
  }
  *(uint *)(iVar2 + 0x1c) = param_2 << 8 ^ *(uint *)(iVar2 + 0x1c) & 0xffff00ff;
  return;
}



/* 40978a6c FUN_40978a6c */

/* Boundary evidence: original MIPS .pdata 40978a6c..40978ac3. Semantic name remains unreviewed. */

void FUN_40978a6c(int param_1,uint param_2)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0x504);
  *(char *)(iVar2 + 0x52) = (char)param_2;
  iVar1 = FUN_40978400(param_1);
  if (iVar1 == 0) {
    param_2 = 0;
  }
  *(uint *)(iVar2 + 0x1c) = *(uint *)(iVar2 + 0x1c) & 0xffffff00 ^ param_2;
  return;
}



/* 40978ac4 FUN_40978ac4 */

/* Boundary evidence: original MIPS .pdata 40978ac4..40978b6b. Semantic name remains unreviewed. */

void FUN_40978ac4(int param_1,uint param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0x504);
  *(char *)(iVar2 + 0x5a) = (char)param_2;
  *(char *)(iVar2 + 0x5b) = (char)param_3;
  *(char *)(iVar2 + 0x5c) = (char)param_4;
  iVar1 = FUN_40978400(param_1);
  if (iVar1 == 0) {
    param_3 = 0;
    param_4 = 0;
  }
  *(uint *)(iVar2 + 0x18) =
       ((param_2 & 0xffffffc7 ^ param_3 << 3) << 3 ^ *(uint *)(iVar2 + 0x18) & 0xfffffe07) &
       0xfffff1ff ^ param_4 << 9;
  return;
}



/* 40978b6c FUN_40978b6c */

/* Boundary evidence: original MIPS .pdata 40978b6c..40978c13. Semantic name remains unreviewed. */

void FUN_40978b6c(int param_1,uint param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0x504);
  *(char *)(iVar2 + 0x53) = (char)param_2;
  *(char *)(iVar2 + 0x54) = (char)param_3;
  *(char *)(iVar2 + 0x55) = (char)param_4;
  iVar1 = FUN_40978400(param_1);
  if (iVar1 == 0) {
    param_3 = 0;
    param_4 = 0;
  }
  *(uint *)(iVar2 + 0x14) =
       ((param_2 & 0xffffffc7 ^ param_3 << 3) << 3 ^ *(uint *)(iVar2 + 0x14) & 0xfffffe07) &
       0xfffff1ff ^ param_4 << 9;
  return;
}



/* 40978c14 FUN_40978c14 */

/* Boundary evidence: original MIPS .pdata 40978c14..40978cc7. Semantic name remains unreviewed. */

void FUN_40978c14(int param_1,uint param_2,uint param_3,uint param_4)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  
  iVar3 = *(int *)(param_1 + 0x504);
  *(uint *)(iVar3 + 0x88) = param_4;
  *(char *)(iVar3 + 0x56) = (char)param_2;
  *(char *)(iVar3 + 0x57) = (char)param_3;
  *(char *)(iVar3 + 0x58) = (char)param_4;
  iVar1 = FUN_40978400(param_1);
  if (iVar1 == 0) {
    param_2 = 7;
  }
  uVar2 = (*(uint *)(iVar3 + 0x18) & 0xfffffff8 ^ param_2) & 0xff00ffff ^
          (param_3 & param_4) << 0x10;
  *(uint *)(iVar3 + 0x18) = uVar2;
  *(uint *)(iVar3 + 0x18) = uVar2 & 0xffffff ^ (uint)*(byte *)(iVar3 + 0x51) << 0x18;
  return;
}



/* 40978cc8 FUN_40978cc8 */

/* Boundary evidence: original MIPS .pdata 40978cc8..40978d7b. Semantic name remains unreviewed. */

void FUN_40978cc8(int param_1,uint param_2,uint param_3,uint param_4)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  
  iVar3 = *(int *)(param_1 + 0x504);
  *(uint *)(iVar3 + 0x84) = param_4;
  *(char *)(iVar3 + 0x4f) = (char)param_2;
  *(char *)(iVar3 + 0x50) = (char)param_3;
  *(char *)(iVar3 + 0x51) = (char)param_4;
  iVar1 = FUN_40978400(param_1);
  if (iVar1 == 0) {
    param_2 = 7;
  }
  uVar2 = (*(uint *)(iVar3 + 0x14) & 0xfffffff8 ^ param_2) & 0xff00ffff ^
          (param_3 & param_4) << 0x10;
  *(uint *)(iVar3 + 0x14) = uVar2;
  *(uint *)(iVar3 + 0x14) = uVar2 & 0xffffff ^ (uint)*(byte *)(iVar3 + 0x51) << 0x18;
  return;
}



/* 40978d7c FUN_40978d7c */

/* Boundary evidence: original MIPS .pdata 40978d7c..40978dd7. Semantic name remains unreviewed. */

void FUN_40978d7c(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0x504);
  *(char *)(iVar2 + 0x4d) = (char)param_2;
  iVar1 = FUN_40978518(param_1);
  if (iVar1 == 0) {
    param_2 = 7;
  }
  *(uint *)(iVar2 + 0xc) = param_2 << 1 ^ *(uint *)(iVar2 + 0xc) & 0xfffffff1;
  return;
}



/* 40978dd8 FUN_40978dd8 */

/* Boundary evidence: original MIPS .pdata 40978dd8..40978e27. Semantic name remains unreviewed. */

void FUN_40978dd8(int param_1,uint param_2)

{
  uint uVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0x504);
  *(char *)(iVar2 + 0x4e) = (char)param_2;
  uVar1 = FUN_40978518(param_1);
  *(uint *)(iVar2 + 0xc) = *(uint *)(iVar2 + 0xc) & 0xfffffffe ^ uVar1 & param_2;
  return;
}



/* 40978e28 FUN_40978e28 */

/* Boundary evidence: original MIPS .pdata 40978e28..40978ffb. Semantic name remains unreviewed. */

void FUN_40978e28(int param_1,uint param_2,int param_3,uint param_4,byte param_5)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  
  iVar3 = *(int *)(param_1 + 0x504);
  uVar2 = (uint)param_5;
  *(char *)(iVar3 + 0x48) = (char)param_2;
  *(char *)(iVar3 + 0x49) = (char)param_3;
  *(char *)(iVar3 + 0x4a) = (char)param_4;
  *(byte *)(iVar3 + 0x4b) = param_5;
  if ((*(uint *)(iVar3 + 0x40) & 8) == 8) {
    return;
  }
  if ((*(uint *)(iVar3 + 0x40) & 4) == 0) {
    param_4 = 0xb;
    param_2 = 0xb;
    uVar2 = 3;
    param_3 = 3;
  }
  FUN_40978630(param_1,(uint)*(byte *)(iVar3 + 0x46),(uint)*(byte *)(iVar3 + 0x47));
  if (*(int *)(param_1 + 0x484) == 0) {
    iVar1 = *(int *)(param_1 + 0x4a0);
  }
  else {
    iVar1 = FUN_40971460(*(int *)(param_1 + 0x484),0xd55);
  }
  if (iVar1 != 0) goto LAB_40978f78;
  if (param_2 == 4) {
LAB_40978ef4:
    param_2 = 3;
  }
  else if (param_2 == 0x11) {
    param_2 = 0xb;
  }
  else if (param_2 == 0x19) goto LAB_40978ef4;
  if (param_3 == 4) {
LAB_40978f14:
    param_3 = 3;
  }
  else if (param_3 == 0x11) {
    param_3 = 0xb;
  }
  else if (param_3 == 0x19) goto LAB_40978f14;
  if ((param_4 == 4) || (param_4 == 0x11)) {
    param_4 = 0xb;
  }
  else if (param_4 == 0x19) {
    param_4 = 3;
  }
  if ((uVar2 == 4) || (uVar2 == 0x11)) {
    uVar2 = 0xb;
  }
  else if (uVar2 == 0x19) {
    uVar2 = 3;
  }
LAB_40978f78:
  if (param_4 == 4) {
    param_4 = 0xb;
  }
  *(uint *)(iVar3 + 8) =
       ((param_2 & 0xffffc01f ^ param_3 << 5) << 6 ^ *(uint *)(iVar3 + 8) & 0xfff0003f) & 0xff0fffff
       ^ ((uVar2 & 0xf) << 4 ^ param_4 & 0xf) << 0x10;
  return;
}



/* 40978ffc FUN_40978ffc */

/* Boundary evidence: original MIPS .pdata 40978ffc..4097907f. Semantic name remains unreviewed. */

int FUN_40978ffc(undefined4 *param_1)

{
  int iVar1;
  
  if (((param_1[0x144] != 0) || (iVar1 = FUN_40978694(param_1), iVar1 == 0)) &&
     (iVar1 = mali_frame_builder_write_lock(param_1[0x13d]), iVar1 == 0)) {
    iVar1 = FUN_40974c48((undefined4 *)param_1[0x144]);
    if (iVar1 == 0) {
      iVar1 = 0;
    }
    else {
      mali_frame_builder_write_unlock(param_1[0x13d]);
    }
  }
  return iVar1;
}



/* 40979080 FUN_40979080 */

/* Boundary evidence: original MIPS .pdata 40979080..409790bf. Semantic name remains unreviewed. */

void FUN_40979080(undefined4 *param_1)

{
  int iVar1;
  
  mali_frame_builder_reset(param_1[0x13d]);
  iVar1 = FUN_40978694(param_1);
  if (iVar1 == 0) {
    FUN_40974c48((undefined4 *)param_1[0x144]);
  }
  return;
}



/* 409790c0 FUN_409790c0 */

/* Boundary evidence: original MIPS .pdata 409790c0..4097914b. Semantic name remains unreviewed. */

void FUN_409790c0(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x504);
  *(uint *)(iVar1 + 0x40) = *(uint *)(iVar1 + 0x40) & 0xffffffdf | param_2 << 5;
  FUN_40978868(param_1);
  FUN_409788ec(param_1,*(undefined4 *)(iVar1 + 0x60),(uint)*(byte *)(iVar1 + 100));
  FUN_40978768(param_1,*(uint *)(iVar1 + 0x40) >> 0xb & 1);
  FUN_409787e8(param_1,*(uint *)(iVar1 + 0x40) >> 10 & 1);
  return;
}



/* 4097914c FUN_4097914c */

/* Boundary evidence: original MIPS .pdata 4097914c..40979203. Semantic name remains unreviewed. */

void FUN_4097914c(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x504);
  *(uint *)(iVar1 + 0x40) = *(uint *)(iVar1 + 0x40) & 0xffffffef | param_2 << 4;
  FUN_40978cc8(param_1,(uint)*(byte *)(iVar1 + 0x4f),(uint)*(byte *)(iVar1 + 0x50),
               (uint)*(byte *)(iVar1 + 0x51));
  FUN_40978a6c(param_1,(uint)*(byte *)(iVar1 + 0x52));
  FUN_40978b6c(param_1,(uint)*(byte *)(iVar1 + 0x53),(uint)*(byte *)(iVar1 + 0x54),
               (uint)*(byte *)(iVar1 + 0x55));
  FUN_40978c14(param_1,(uint)*(byte *)(iVar1 + 0x56),(uint)*(byte *)(iVar1 + 0x57),
               (uint)*(byte *)(iVar1 + 0x58));
  FUN_40978a10(param_1,(uint)*(byte *)(iVar1 + 0x59));
  FUN_40978ac4(param_1,(uint)*(byte *)(iVar1 + 0x5a),(uint)*(byte *)(iVar1 + 0x5b),
               (uint)*(byte *)(iVar1 + 0x5c));
  return;
}



/* 40979204 FUN_40979204 */

/* Boundary evidence: original MIPS .pdata 40979204..40979263. Semantic name remains unreviewed. */

void FUN_40979204(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x504);
  *(uint *)(iVar1 + 0x40) = *(uint *)(iVar1 + 0x40) & 0xfffffffd | param_2 << 1;
  FUN_40978d7c(param_1,(uint)*(byte *)(iVar1 + 0x4d));
  FUN_40978dd8(param_1,(uint)*(byte *)(iVar1 + 0x4e));
  return;
}



/* 40979264 FUN_40979264 */

/* Boundary evidence: original MIPS .pdata 40979264..409792af. Semantic name remains unreviewed. */

void FUN_40979264(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x504);
  *(uint *)(iVar1 + 0x40) = *(uint *)(iVar1 + 0x40) & 0xfffffffb | param_2 << 2;
  FUN_40978e28(param_1,(uint)*(byte *)(iVar1 + 0x48),(uint)*(byte *)(iVar1 + 0x49),
               (uint)*(byte *)(iVar1 + 0x4a),*(byte *)(iVar1 + 0x4b));
  return;
}



/* 409792b0 FUN_409792b0 */

/* Boundary evidence: original MIPS .pdata 409792b0..40979307. Semantic name remains unreviewed. */

void FUN_409792b0(int param_1,int param_2)

{
  undefined4 *puVar1;
  
  if ((param_1 != 0) && (FUN_40979a70(param_1,param_2,0x8893,0), *(int *)(param_2 + 0x300) != 0)) {
    puVar1 = *(undefined4 **)(param_2 + 0x308);
    *(undefined4 *)(param_2 + 0x308) = 0;
    *(undefined4 *)(param_2 + 0x300) = 0;
    if (puVar1 != (undefined4 *)0x0) {
      FUN_409794cc(puVar1);
    }
  }
  return;
}



/* 40979308 FUN_40979308 */

/* Boundary evidence: original MIPS .pdata 40979308..409793b7. Semantic name remains unreviewed. */

void FUN_40979308(int param_1)

{
  int iVar1;
  
  FUN_40979204(param_1,*(uint *)(*(int *)(param_1 + 0x504) + 0x40) >> 1 & 1);
  FUN_4097914c(param_1,*(uint *)(*(int *)(param_1 + 0x504) + 0x40) >> 4 & 1);
  iVar1 = *(int *)(param_1 + 0x504);
  *(uint *)(iVar1 + 0x40) =
       *(uint *)(iVar1 + 0x40) & 0xfffffffb | (*(uint *)(iVar1 + 0x40) >> 2 & 1) << 2;
  FUN_40978e28(param_1,(uint)*(byte *)(iVar1 + 0x48),(uint)*(byte *)(iVar1 + 0x49),
               (uint)*(byte *)(iVar1 + 0x4a),*(byte *)(iVar1 + 0x4b));
  FUN_409790c0(param_1,*(uint *)(*(int *)(param_1 + 0x504) + 0x40) >> 5 & 1);
  return;
}



/* 409793b8 FUN_409793b8 */

/* Boundary evidence: original MIPS .pdata 409793b8..409793eb. Semantic name remains unreviewed. */

void FUN_409793b8(undefined4 *param_1,undefined4 param_2)

{
  param_1[0x13d] = param_2;
  FUN_40979308((int)param_1);
  FUN_40978694(param_1);
  return;
}



/* 409793ec gles_set_draw_frame_builder */

/* Boundary evidence: original MIPS .pdata 409793ec..409794cb. Semantic name remains unreviewed.
   gles_set_draw_frame_builder */

int gles_set_draw_frame_builder
              (undefined4 *param_1,undefined4 param_2,int param_3,undefined4 param_4,
              undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
              undefined4 param_9,undefined4 param_10,undefined4 param_11)

{
  int iVar1;
  
                    /* 0x193ec  11  _gles_set_draw_frame_builder */
  param_1[0x126] = param_5;
  param_1[0x127] = param_6;
  param_1[0x128] = param_7;
  iVar1 = param_1[0x13c];
  param_1[0x125] = param_4;
  param_1[0x129] = param_8;
  param_1[0x12a] = param_9;
  param_1[299] = param_10;
  param_1[300] = param_11;
  param_1[0x12d] = param_3;
  if (param_3 == 1) {
    param_1[0x130] = 0;
  }
  else {
    param_1[0x130] = 1;
  }
  if (param_1[0x122] == 0) {
    param_1[0x124] = param_1[0x130];
  }
  param_1[0x13c] = param_2;
  if (param_1[0x13d] == iVar1) {
    param_1[0x13d] = param_2;
    FUN_40979308((int)param_1);
  }
  iVar1 = FUN_40978694(param_1);
  if (iVar1 == 0) {
    mali_frame_builder_set_subpixel_bits(param_2,5);
    iVar1 = 0;
  }
  else {
    param_1[4] = 0x505;
  }
  return iVar1;
}



/* 409794cc FUN_409794cc */

/* Boundary evidence: original MIPS .pdata 409794cc..4097952f. Semantic name remains unreviewed. */

void FUN_409794cc(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  
  iVar1 = mali_sys_atomic_dec_and_return(param_1 + 5);
  if (iVar1 == 0) {
    puVar2 = (undefined4 *)*param_1;
    if (puVar2 != (undefined4 *)0x0) {
      mali_mem_ref_deref(*puVar2);
      *puVar2 = 0;
      mali_sys_free(puVar2);
      *param_1 = 0;
    }
    mali_sys_free(param_1);
  }
  return;
}



/* 40979530 FUN_40979530 */

/* Boundary evidence: original MIPS .pdata 40979530..4097956b. Semantic name remains unreviewed. */

void FUN_40979530(undefined4 *param_1)

{
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0x88e4;
  param_1[3] = 0x88b9;
  param_1[4] = 0;
  mali_sys_atomic_initialize(param_1 + 5,1);
  return;
}



/* 4097957c FUN_4097957c */

/* Boundary evidence: original MIPS .pdata 4097957c..409795b7. Semantic name remains unreviewed. */

undefined4 FUN_4097957c(int param_1,uint param_2)

{
  undefined4 uVar1;
  
  if (param_2 < 0x100) {
    uVar1 = *(undefined4 *)((param_2 + 7) * 4 + param_1);
  }
  else {
    uVar1 = __mali_named_list_get_non_flat();
  }
  return uVar1;
}



/* 409795b8 FUN_409795b8 */

/* Boundary evidence: original MIPS .pdata 409795b8..40979697. Semantic name remains unreviewed. */

undefined4
FUN_409795b8(undefined4 param_1,int param_2,int param_3,int param_4,int param_5,int param_6)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 *puVar4;
  
  if (param_3 == 0x8892) {
    puVar4 = *(undefined4 **)(param_2 + 0x308);
    iVar3 = *(int *)(param_2 + 0x300);
  }
  else {
    if (param_3 != 0x8893) {
      return 0x500;
    }
    puVar4 = *(undefined4 **)(param_2 + 0x30c);
    iVar3 = *(int *)(param_2 + 0x304);
  }
  if ((puVar4 == (undefined4 *)0x0) || (iVar3 == 0)) {
    uVar2 = 0x502;
  }
  else if (((param_4 < 0) || (param_5 < 0)) || ((uint)puVar4[1] < (uint)(param_4 + param_5))) {
    uVar2 = 0x501;
  }
  else {
    if (((int *)*puVar4 != (int *)0x0) && (param_6 != 0)) {
      piVar1 = FUN_409691a4(param_1,(int *)*puVar4,puVar4[1],param_3,param_4,param_5,param_6);
      if (piVar1 == (int *)0x0) {
        return 0x505;
      }
      *puVar4 = piVar1;
    }
    uVar2 = 0;
  }
  return uVar2;
}



/* 40979698 FUN_40979698 */

/* Boundary evidence: original MIPS .pdata 40979698..409797b7. Semantic name remains unreviewed. */

void FUN_40979698(undefined4 param_1,int param_2,int param_3,int param_4)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  undefined4 *puVar4;
  int in_stack_00000038;
  int in_stack_0000003c;
  int in_stack_00000040;
  
  FUN_40993230();
  if ((-1 < in_stack_00000038) && ((param_4 == 0x8892 || (param_4 == 0x8893)))) {
    if (in_stack_00000040 == 0x88e0) {
      if (param_3 != 2) goto LAB_409796f8;
    }
    else if ((in_stack_00000040 != 0x88e4) && (in_stack_00000040 != 0x88e8)) goto LAB_409796f8;
    if (param_4 == 0x8892) {
      piVar3 = *(int **)(param_2 + 0x308);
      iVar2 = *(int *)(param_2 + 0x300);
    }
    else {
      if (param_4 != 0x8893) goto LAB_409796f8;
      piVar3 = *(int **)(param_2 + 0x30c);
      iVar2 = *(int *)(param_2 + 0x304);
    }
    if ((piVar3 != (int *)0x0) && (iVar2 != 0)) {
      puVar4 = (undefined4 *)*piVar3;
      piVar1 = (int *)mali_sys_malloc(0x1408);
      if (piVar1 == (int *)0x0) {
        iVar2 = 0;
      }
      else {
        iVar2 = FUN_409690fc(param_1,in_stack_00000038,in_stack_0000003c,piVar1);
      }
      *piVar3 = iVar2;
      if (iVar2 == 0) {
        *piVar3 = (int)puVar4;
      }
      else {
        if (puVar4 != (undefined4 *)0x0) {
          mali_mem_ref_deref(*puVar4);
          *puVar4 = 0;
          mali_sys_free(puVar4);
        }
        piVar3[2] = in_stack_00000040;
        piVar3[1] = in_stack_00000038;
      }
    }
  }
LAB_409796f8:
                    /* WARNING: Subroutine does not return */
  FUN_40993258(0x10);
}



/* 409797b8 FUN_409797b8 */

/* Boundary evidence: original MIPS .pdata 409797b8..409797ff. Semantic name remains unreviewed. */

void FUN_409797b8(int param_1)

{
  if (param_1 != 0) {
    if (*(undefined4 **)(param_1 + 4) != (undefined4 *)0x0) {
      FUN_409794cc(*(undefined4 **)(param_1 + 4));
      *(undefined4 *)(param_1 + 4) = 0;
    }
    mali_sys_free(param_1);
  }
  return;
}



/* 40979800 FUN_40979800 */

/* Boundary evidence: original MIPS .pdata 40979800..40979903. Semantic name remains unreviewed. */

undefined4 FUN_40979800(int param_1,int param_2,int param_3,uint *param_4)

{
  uint uVar1;
  int iVar2;
  
  if (param_4 != (uint *)0x0) {
    if (param_3 < 0) {
      return 0x501;
    }
    if (0 < param_3) {
      do {
        uVar1 = *param_4;
        if (uVar1 != 0) {
          if (uVar1 < 0x100) {
            iVar2 = *(int *)((uVar1 + 7) * 4 + param_1);
          }
          else {
            iVar2 = __mali_named_list_get_non_flat(param_1,uVar1);
          }
          if (iVar2 != 0) {
            if (*(int *)(iVar2 + 4) != 0) {
              FUN_409745fc(param_2,uVar1);
              FUN_409794cc(*(undefined4 **)(iVar2 + 4));
              *(undefined4 *)(iVar2 + 4) = 0;
            }
            __mali_named_list_remove(param_1,uVar1);
            mali_sys_free(iVar2);
          }
        }
        param_4 = param_4 + 1;
        param_3 = param_3 + -1;
      } while (param_3 != 0);
    }
  }
  return 0;
}



/* 40979904 FUN_40979904 */

/* Boundary evidence: original MIPS .pdata 40979904..40979967. Semantic name remains unreviewed. */

undefined4 * FUN_40979904(void)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)mali_sys_malloc(0x18);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    *puVar1 = 0;
    puVar1[1] = 0;
    puVar1[2] = 0x88e4;
    puVar1[3] = 0x88b9;
    puVar1[4] = 0;
    mali_sys_atomic_initialize(puVar1 + 5,1);
  }
  return puVar1;
}



/* 40979968 FUN_40979968 */

/* Boundary evidence: original MIPS .pdata 40979968..40979a6f. Semantic name remains unreviewed. */

undefined4 * FUN_40979968(int param_1,uint param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  
  if (param_2 < 0x100) {
    iVar3 = *(int *)((param_2 + 7) * 4 + param_1);
  }
  else {
    iVar3 = __mali_named_list_get_non_flat(param_1,param_2);
  }
  if ((iVar3 == 0) || (puVar2 = *(undefined4 **)(iVar3 + 4), puVar2 == (undefined4 *)0x0)) {
    puVar2 = FUN_40979904();
    if (puVar2 != (undefined4 *)0x0) {
      if (iVar3 != 0) {
        *(undefined4 **)(iVar3 + 4) = puVar2;
        return puVar2;
      }
      puVar1 = (undefined4 *)mali_sys_malloc(8);
      if (puVar1 == (undefined4 *)0x0) {
        FUN_409794cc(puVar2);
      }
      else {
        *puVar1 = 4;
        puVar1[1] = 0;
        puVar1[1] = puVar2;
        iVar3 = __mali_named_list_insert(param_1,param_2,puVar1);
        if (iVar3 == 0) {
          return puVar2;
        }
        FUN_409794cc(puVar2);
        puVar1[1] = 0;
        mali_sys_free(puVar1);
      }
    }
    puVar2 = (undefined4 *)0x0;
  }
  return puVar2;
}



/* 40979a70 FUN_40979a70 */

/* Boundary evidence: original MIPS .pdata 40979a70..40979b03. Semantic name remains unreviewed. */

void FUN_40979a70(int param_1,int param_2,int param_3,uint param_4)

{
  undefined4 *puVar1;
  uint uVar2;
  
  FUN_40993370();
  if (param_3 == 0x8892) {
    uVar2 = *(uint *)(param_2 + 0x300);
  }
  else {
    if (param_3 != 0x8893) goto LAB_40979afc;
    uVar2 = *(uint *)(param_2 + 0x304);
  }
  if (uVar2 != param_4) {
    if (param_4 == 0) {
      puVar1 = (undefined4 *)0x0;
      param_4 = 0;
    }
    else {
      puVar1 = FUN_40979968(param_1,param_4);
      if (puVar1 == (undefined4 *)0x0) goto LAB_40979afc;
    }
    FUN_4097458c(param_2,param_3,param_4,(int)puVar1);
  }
LAB_40979afc:
                    /* WARNING: Subroutine does not return */
  FUN_40993390(0x18);
}



/* 40979b04 FUN_40979b04 */

undefined4 FUN_40979b04(int param_1)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  
  if ((*(int **)(param_1 + 0x1c) != (int *)0x0) && (**(int **)(param_1 + 0x1c) != 0)) {
    piVar1 = (int *)**(int **)(param_1 + 0x1c);
    iVar3 = *piVar1;
    if ((iVar3 == piVar1[1]) && (-1 < iVar3)) {
      iVar5 = 1;
      piVar4 = (int *)(param_1 + 0x20);
      while (((((undefined4 *)*piVar4 != (undefined4 *)0x0 &&
               (piVar2 = *(int **)*piVar4, piVar2 != (int *)0x0)) && (iVar3 == *piVar2)) &&
             (((piVar1[1] == piVar2[1] && (piVar1[3] == piVar2[3])) && (piVar1[4] == piVar2[4])))))
      {
        iVar5 = iVar5 + 1;
        prefetch(piVar4 + 2,0);
        piVar4 = piVar4 + 1;
        if (5 < iVar5) {
          return 1;
        }
      }
    }
  }
  return 0;
}



/* 40979bbc FUN_40979bbc */

int FUN_40979bbc(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  if (((param_2 == 0x8363) || (param_2 == 0x8033)) || (param_2 == 0x8034)) {
    return 2;
  }
  if ((param_2 == 0x1401) && (iVar2 = 1, param_1 != 0x1906)) {
    if (param_1 == 0x1907) {
      iVar1 = 3;
      goto LAB_40979c70;
    }
    if (param_1 != 0x1908) {
      if (param_1 != 0x1909) {
        if (param_1 != 0x190a) {
          return 1;
        }
        iVar1 = 2;
        goto LAB_40979c70;
      }
      goto LAB_40979c40;
    }
  }
  else {
LAB_40979c40:
    iVar2 = 1;
    iVar1 = 1;
    if (param_2 != 0x1403) goto LAB_40979c70;
    iVar1 = 2;
    iVar2 = 2;
    if (param_1 != 0x1908) {
      if (param_1 != 0x190a) {
        return 1;
      }
      goto LAB_40979c70;
    }
  }
  iVar1 = 4;
LAB_40979c70:
  return iVar2 * iVar1;
}



/* 40979c84 FUN_40979c84 */

undefined4 FUN_40979c84(uint param_1,uint param_2,int param_3)

{
  int iVar1;
  
  if ((param_2 < 0x1906) || (0x190a < param_2)) {
    return 0x501;
  }
  if ((((param_3 != 0x1401) && (param_3 != 0x1403)) && (param_3 != 0x8033)) &&
     ((1 < param_3 - 0x8033U && (param_3 != 0x8363)))) {
    return 0x500;
  }
  if (param_1 != param_2) {
    return 0x502;
  }
  if (param_1 != 0x1906) {
    if (param_1 == 0x1907) {
      if (param_3 == 0x1401) {
        return 0;
      }
      if (param_3 == 0x8363) {
        return 0;
      }
      return 0x502;
    }
    if (param_1 == 0x1908) {
      if (param_3 == 0x1401) {
        return 0;
      }
      if (param_3 == 0x1403) {
        return 0;
      }
      if (param_3 == 0x8034) {
        return 0;
      }
      if (param_3 != 0x8033) {
        return 0x502;
      }
      return 0;
    }
    if (param_1 != 0x1909) {
      if (param_1 != 0x190a) {
        return 0x502;
      }
      if (param_3 == 0x1401) {
        return 0;
      }
      iVar1 = 0x1403;
      goto LAB_40979d9c;
    }
  }
  iVar1 = 0x1401;
LAB_40979d9c:
  if (param_3 == iVar1) {
    return 0;
  }
  return 0x502;
}



/* 40979dc8 FUN_40979dc8 */

/* Boundary evidence: original MIPS .pdata 40979dc8..40979e33. Semantic name remains unreviewed. */

int FUN_40979dc8(int param_1,int param_2)

{
  int iVar1;
  undefined4 *puVar2;
  int *piVar3;
  
  piVar3 = (int *)((param_2 + 7) * 4 + param_1);
  if (*piVar3 == 0) {
    iVar1 = mali_sys_malloc(0x34);
    *piVar3 = iVar1;
    if (iVar1 == 0) {
      return 0;
    }
    iVar1 = 0;
    do {
      puVar2 = (undefined4 *)(*piVar3 + iVar1);
      iVar1 = iVar1 + 4;
      *puVar2 = 0;
    } while (iVar1 < 0x34);
  }
  return *piVar3;
}



/* 40979e34 FUN_40979e34 */

undefined4 FUN_40979e34(int param_1)

{
  if ((param_1 != 0xde1) && (param_1 != 0x8515)) {
    if (param_1 == 0x8516) {
      return 1;
    }
    if (param_1 == 0x8517) {
      return 2;
    }
    if (param_1 == 0x8518) {
      return 3;
    }
    if (param_1 == 0x8519) {
      return 4;
    }
    if (param_1 == 0x851a) {
      return 5;
    }
  }
  return 0;
}



/* 40979ebc FUN_40979ebc */

/* Boundary evidence: original MIPS .pdata 40979ebc..40979f13. Semantic name remains unreviewed. */

void FUN_40979ebc(int param_1,int param_2)

{
  int *piVar1;
  
  piVar1 = (int *)(param_1 * 4 + param_2);
  if (*piVar1 != 0) {
    if (*(int *)(*piVar1 + 0x14) != 0) {
      __mali_linked_list_free();
      *(undefined4 *)(*piVar1 + 0x14) = 0;
    }
    mali_sys_free(*piVar1);
    *piVar1 = 0;
  }
  return;
}



/* 40979f14 FUN_40979f14 */

/* Boundary evidence: original MIPS .pdata 40979f14..40979fb3. Semantic name remains unreviewed. */

void FUN_40979f14(undefined4 *param_1)

{
  undefined4 *puVar1;
  
  param_1[1] = 0x2901;
  param_1[2] = 0x2901;
  param_1[3] = 0x2702;
  puVar1 = param_1 + 7;
  param_1[4] = 0x2601;
  *(undefined1 *)(param_1 + 5) = 0;
  param_1[6] = 0;
  param_1[0x12] = 0;
  param_1[0x13] = 0;
  do {
    *puVar1 = 0;
    puVar1 = puVar1 + 1;
  } while (puVar1 != param_1 + 0xd);
  *param_1 = 0xffffffff;
  mali_sys_atomic_initialize(param_1 + 0x14,1);
  param_1[0xe] = 1;
  param_1[0xf] = 1;
  param_1[0xd] = 0;
  param_1[0x15] = 0;
  param_1[0x10] = 0;
  param_1[0x11] = 0;
  return;
}



/* 40979fb4 FUN_40979fb4 */

undefined4 FUN_40979fb4(int *param_1)

{
  undefined4 uVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  
  piVar2 = (int *)*param_1;
  if (piVar2 == (int *)0x0) {
LAB_4097a094:
    uVar1 = 0;
  }
  else {
    uVar7 = 0;
    uVar1 = 1;
    do {
      iVar6 = *piVar2 >> (uVar7 & 0x1f);
      if (iVar6 < 2) {
        iVar6 = 1;
      }
      iVar5 = piVar2[1] >> (uVar7 & 0x1f);
      if (iVar5 < 2) {
        iVar5 = 1;
      }
      iVar4 = piVar2[2] >> (uVar7 & 0x1f);
      if (iVar4 < 2) {
        iVar4 = 1;
      }
      piVar3 = (int *)*param_1;
      if (((((piVar3 == (int *)0x0) || (*piVar3 != iVar6)) || (piVar3[1] != iVar5)) ||
          ((piVar3[2] != iVar4 || (piVar3[4] != piVar2[4])))) || (piVar3[3] != piVar2[3]))
      goto LAB_4097a094;
      if (((iVar6 == 1) && (iVar5 == 1)) && (iVar4 == 1)) {
        return 1;
      }
      uVar7 = uVar7 + 1;
      param_1 = param_1 + 1;
    } while ((int)uVar7 < 0xd);
  }
  return uVar1;
}



/* 4097a0a0 FUN_4097a0a0 */

/* Boundary evidence: original MIPS .pdata 4097a0a0..4097a12b. Semantic name remains unreviewed. */

int FUN_4097a0a0(int param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  
  if (param_4 == 0x1401) {
    iVar1 = FUN_40976924(param_3,0x1401);
    iVar1 = iVar1 * param_2 + param_1 + -1;
    if (param_1 == 0) {
      trap(0x1c00);
    }
    if ((param_1 == -1) && (iVar1 == -0x80000000)) {
      trap(0x1800);
    }
    iVar1 = (iVar1 / param_1) * param_1;
  }
  else {
    iVar1 = FUN_40976924(param_3,param_4);
    iVar1 = iVar1 * param_2;
  }
  return iVar1;
}



/* 4097a1b0 FUN_4097a1b0 */

void FUN_4097a1b0(int *param_1)

{
  if (*param_1 == 0) {
    *(uint *)(param_1[0xd] + 0x13c) = *(uint *)(param_1[0xd] + 0x13c) & 0xfffffc7f;
    *(uint *)(param_1[0xd] + 0x13c) = *(uint *)(param_1[0xd] + 0x13c) & 0xfffff7ff | 0x400;
  }
  else if (*param_1 == 1) {
    *(uint *)(param_1[0xd] + 0x13c) = *(uint *)(param_1[0xd] + 0x13c) & 0xfffffe7f | 0x200;
    *(uint *)(param_1[0xd] + 0x13c) = *(uint *)(param_1[0xd] + 0x13c) & 0xfffffbff | 0x800;
  }
  return;
}



/* 4097a240 FUN_4097a240 */

/* Boundary evidence: original MIPS .pdata 4097a240..4097a25b. Semantic name remains unreviewed. */

void FUN_4097a240(int param_1)

{
  mali_sys_atomic_inc(param_1 + 0x188);
  return;
}



/* 4097a298 FUN_4097a298 */

/* Boundary evidence: original MIPS .pdata 4097a298..4097a2cf. Semantic name remains unreviewed. */

int FUN_4097a298(int *param_1,int param_2)

{
  int iVar1;
  
  if (param_1[1] == 0) {
    iVar1 = mali_mem_mali_addr_get_full();
  }
  else {
    iVar1 = *param_1 + param_2;
  }
  return iVar1;
}



/* 4097a2d0 FUN_4097a2d0 */

/* Boundary evidence: original MIPS .pdata 4097a2d0..4097a30b. Semantic name remains unreviewed. */

undefined4 FUN_4097a2d0(int param_1,uint param_2)

{
  undefined4 uVar1;
  
  if (param_2 < 0x100) {
    uVar1 = *(undefined4 *)((param_2 + 7) * 4 + param_1);
  }
  else {
    uVar1 = __mali_named_list_get_non_flat();
  }
  return uVar1;
}



/* 4097a30c FUN_4097a30c */

uint FUN_4097a30c(uint param_1)

{
  uint uVar1;
  
  uVar1 = 0;
  if ((param_1 & 0x7fff0000) != 0) {
    uVar1 = 0x10;
  }
  if ((param_1 & 0x7f00ff00) != 0) {
    uVar1 = uVar1 | 8;
  }
  if ((param_1 & 0x70f0f0f0) != 0) {
    uVar1 = uVar1 | 4;
  }
  if ((param_1 & 0x3ccccccc) != 0) {
    uVar1 = uVar1 | 2;
  }
  if ((param_1 & 0x2aaaaaaa) != 0) {
    uVar1 = uVar1 | 1;
  }
  return uVar1;
}



/* 4097a3e0 FUN_4097a3e0 */

/* Boundary evidence: original MIPS .pdata 4097a3e0..4097a59f. Semantic name remains unreviewed. */

void FUN_4097a3e0(int *param_1)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  uint *puVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  int *piVar8;
  
  FUN_40993230();
  iVar6 = 1;
  iVar7 = 1;
  if (param_1[0xf] == 0) goto LAB_4097a4d0;
  param_1[0xf] = 0;
  if ((param_1[3] == 0x2600) || (param_1[3] == 0x2601)) {
    if (*param_1 == 0) {
      if (((int *)param_1[7] == (int *)0x0) ||
         (puVar4 = *(uint **)param_1[7], puVar4 == (uint *)0x0)) goto LAB_4097a4ac;
      uVar5 = *puVar4;
      if ((((uVar5 != 0) && ((uVar5 - 1 & uVar5) != 0)) ||
          ((uVar5 = puVar4[1], uVar5 != 0 && ((uVar5 - 1 & uVar5) != 0)))) &&
         ((param_1[1] != 0x812f || (param_1[2] != 0x812f)))) {
LAB_4097a4a0:
        param_1[0x10] = 0;
        goto LAB_4097a4d0;
      }
    }
    else {
      if (*param_1 != 1) goto LAB_4097a4dc;
      iVar6 = FUN_40979b04((int)param_1);
    }
  }
  else {
LAB_4097a4dc:
    if (param_1[0x12] == 1) {
      iVar6 = param_1[0x13];
    }
    else {
      if (*param_1 != 0) {
        if (*param_1 == 1) {
          iVar7 = 6;
          iVar1 = FUN_40979b04((int)param_1);
          if (iVar1 != 0) goto LAB_4097a518;
        }
LAB_4097a4ac:
        param_1[0x10] = 0;
        goto LAB_4097a4d0;
      }
LAB_4097a518:
      iVar1 = 0;
      if (iVar7 != 0) {
        piVar8 = param_1 + 7;
        do {
          piVar3 = (int *)*piVar8;
          if ((piVar3 == (int *)0x0) || (puVar4 = (uint *)*piVar3, puVar4 == (uint *)0x0))
          goto LAB_4097a4a0;
          uVar5 = *puVar4;
          if ((((uVar5 != 0) && ((uVar5 - 1 & uVar5) != 0)) ||
              ((uVar5 = puVar4[1], uVar5 != 0 && ((uVar5 - 1 & uVar5) != 0)))) ||
             (iVar2 = FUN_40979fb4(piVar3), iVar2 == 0)) goto LAB_4097a4ac;
          iVar1 = iVar1 + 1;
          piVar8 = piVar8 + 1;
        } while (iVar1 < iVar7);
      }
    }
  }
  param_1[0x10] = iVar6;
LAB_4097a4d0:
                    /* WARNING: Subroutine does not return */
  FUN_40993258(0x10);
}



/* 4097a5a0 FUN_4097a5a0 */

/* Boundary evidence: original MIPS .pdata 4097a5a0..4097a5e7. Semantic name remains unreviewed. */

undefined4 FUN_4097a5a0(int param_1,int param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = FUN_4096f8c8(param_1,param_2,param_3);
  if ((iVar1 == 0) && (uVar2 = mali_sys_atomic_get(param_1 + 0x188), uVar2 < 2)) {
    return 0;
  }
  return 1;
}



/* 4097a5e8 FUN_4097a5e8 */

/* Boundary evidence: original MIPS .pdata 4097a5e8..4097a63b. Semantic name remains unreviewed. */

void FUN_4097a5e8(int param_1,int param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  
  FUN_40993370();
  iVar1 = FUN_40979e34(param_2);
  iVar1 = FUN_40979dc8(param_1,iVar1);
  if (iVar1 != 0) {
    *(undefined4 *)(param_3 * 4 + iVar1) = param_4;
  }
                    /* WARNING: Subroutine does not return */
  FUN_40993390(0x10);
}



/* 4097a63c FUN_4097a63c */

/* Boundary evidence: original MIPS .pdata 4097a63c..4097a697. Semantic name remains unreviewed. */

undefined4 FUN_4097a63c(int param_1,int param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_40979e34(param_2);
  iVar1 = FUN_40979dc8(param_1,iVar1);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = *(undefined4 *)(param_3 * 4 + iVar1);
  }
  return uVar2;
}



/* 4097a698 FUN_4097a698 */

/* Boundary evidence: original MIPS .pdata 4097a698..4097a803. Semantic name remains unreviewed. */

void FUN_4097a698(int param_1)

{
  uint uVar1;
  int *piVar2;
  int iVar3;
  
  if ((*(int *)(param_1 + 0xc) == 0x2600) && (*(int *)(param_1 + 0x10) == 0x2601)) {
    *(uint *)(*(int *)(param_1 + 0x34) + 0x13c) =
         *(uint *)(*(int *)(param_1 + 0x34) + 0x13c) & 0xfffffff | 0x80000000;
    *(uint *)(*(int *)(param_1 + 0x34) + 0x140) =
         *(uint *)(*(int *)(param_1 + 0x34) + 0x140) & 0xffffffe0;
  }
  else {
    *(uint *)(*(int *)(param_1 + 0x34) + 0x13c) =
         *(uint *)(*(int *)(param_1 + 0x34) + 0x13c) & 0xfffffff;
    *(uint *)(*(int *)(param_1 + 0x34) + 0x140) =
         *(uint *)(*(int *)(param_1 + 0x34) + 0x140) & 0xffffffe0;
  }
  if ((*(int *)(param_1 + 0xc) == 0x2600) || (*(int *)(param_1 + 0xc) == 0x2601)) {
    *(uint *)(*(int *)(param_1 + 0x34) + 0x13c) =
         *(uint *)(*(int *)(param_1 + 0x34) + 0x13c) & 0xf00fffff;
  }
  else {
    piVar2 = *(int **)(param_1 + 0x1c);
    if ((piVar2 != (int *)0x0) && ((uint *)*piVar2 != (uint *)0x0)) {
      if (((int *)*piVar2)[1] < *(int *)*piVar2) {
        uVar1 = *(uint *)*piVar2;
      }
      else {
        uVar1 = *(uint *)(*piVar2 + 4);
      }
      iVar3 = *(int *)(param_1 + 0x34);
      uVar1 = uVar1 >> 1 | uVar1;
      uVar1 = uVar1 >> 2 | uVar1;
      uVar1 = uVar1 >> 4 | uVar1;
      uVar1 = uVar1 >> 8 | uVar1;
      uVar1 = FUN_4097a30c(((uVar1 >> 0x10 | uVar1) >> 1) + 1);
      *(uint *)(iVar3 + 0x13c) = uVar1 << 0x18 | *(uint *)(iVar3 + 0x13c) & 0xf00fffff;
    }
  }
  return;
}



/* 4097a804 gles_setup_egl_image_from_texture */

/* Boundary evidence: original MIPS .pdata 4097a804..4097aaef. Semantic name remains unreviewed.
   gles_setup_egl_image_from_texture */

void gles_setup_egl_image_from_texture
               (int param_1,int param_2,uint param_3,uint param_4,undefined4 param_5,
               undefined4 param_6,int param_7)

{
  bool bVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  int in_stack_00000058;
  
                    /* 0x1a804  13  _gles_setup_egl_image_from_texture */
  FUN_40993300();
  bVar1 = false;
  iVar6 = 0;
  if (param_2 == 1) {
    iVar6 = 0xde1;
  }
  else if (param_2 == 2) {
    iVar6 = 0x8515;
  }
  else if (param_2 == 3) {
    iVar6 = 0x8516;
  }
  else if (param_2 == 4) {
    iVar6 = 0x8517;
  }
  else if (param_2 == 5) {
    iVar6 = 0x8518;
  }
  else if (param_2 == 6) {
    iVar6 = 0x8519;
  }
  else if (param_2 == 7) {
    iVar6 = 0x851a;
  }
  if ((param_4 < 0xd) && (param_3 != 0)) {
    iVar2 = *(int *)(*(int *)(param_1 + 0x4e8) + 4);
    if (param_3 < 0x100) {
      iVar2 = *(int *)((param_3 + 7) * 4 + iVar2);
    }
    else {
      iVar2 = __mali_named_list_get_non_flat(iVar2,param_3);
    }
    if (((iVar2 != 0) && (piVar5 = *(int **)(iVar2 + 4), piVar5 != (int *)0x0)) &&
       (iVar2 = FUN_4096f9a8(piVar5[0xd],iVar6,param_4), iVar2 == 0)) {
      if (iVar6 == 0xde1) {
        iVar6 = FUN_40979e34(0xde1);
        if ((piVar5[iVar6 + 7] != 0) && (*(int *)(param_4 * 4 + piVar5[iVar6 + 7]) != 0)) {
          bVar1 = true;
        }
        if (*piVar5 != 0) goto LAB_4097a998;
      }
      else {
        if ((iVar6 != 0x8515) && (5 < iVar6 - 0x8515U)) goto LAB_4097a998;
        iVar6 = FUN_40979e34(iVar6);
        if ((piVar5[iVar6 + 7] != 0) && (*(int *)(param_4 * 4 + piVar5[iVar6 + 7]) != 0)) {
          bVar1 = true;
        }
        if (*piVar5 != 1) goto LAB_4097a998;
      }
      iVar2 = FUN_4097a3e0(piVar5);
      if (((iVar2 == 1) && (bVar1)) && (param_4 < 10)) {
        iVar6 = FUN_4096f74c(piVar5[0xd],iVar6,param_4,in_stack_00000058);
        if (param_7 != 0) {
          iVar4 = piVar5[0x15];
          iVar2 = 0;
          if (0 < iVar4) {
            piVar3 = piVar5 + 0x16;
            do {
              if (param_7 == *piVar3) {
                piVar5[0x15] = iVar4 + -1;
                piVar5[iVar2 + 0x16] = piVar5[iVar4 + 0x15];
                break;
              }
              iVar2 = iVar2 + 1;
              prefetch(piVar3 + 2,0);
              piVar3 = piVar3 + 1;
            } while (iVar2 < iVar4);
          }
          if (iVar2 == iVar4) {
            iVar6 = 0;
          }
        }
        if (iVar6 == 1) {
          piVar5[piVar5[0x15] + 0x16] = *(int *)(*(int *)(in_stack_00000058 + 0x20) + 0x10);
          piVar5[0x15] = piVar5[0x15] + 1;
        }
      }
    }
  }
LAB_4097a998:
                    /* WARNING: Subroutine does not return */
  FUN_40993338(0x20);
}



/* 4097aaf0 FUN_4097aaf0 */

/* Boundary evidence: original MIPS .pdata 4097aaf0..4097ab5b. Semantic name remains unreviewed. */

undefined4 FUN_4097aaf0(int param_1,undefined4 param_2,int param_3,int param_4)

{
  int iVar1;
  int in_stack_00000020;
  
  iVar1 = FUN_4097a63c(param_1,param_3,0);
  if (iVar1 != 0) {
    if ((param_4 < 0) || (0xc < param_4)) {
      return 0x501;
    }
    if (in_stack_00000020 != 0x8d64) {
      return 0x500;
    }
  }
  return 0x502;
}



/* 4097ab5c FUN_4097ab5c */

/* Boundary evidence: original MIPS .pdata 4097ab5c..4097abfb. Semantic name remains unreviewed. */

int FUN_4097ab5c(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  
  iVar1 = FUN_4097a63c(param_1,param_2,param_3);
  if (iVar1 == 0) {
    iVar1 = mali_sys_malloc(0x18);
    if (iVar1 != 0) {
      *(undefined4 *)(iVar1 + 0x14) = 0;
      iVar2 = FUN_4097a5e8(param_1,param_2,param_3,iVar1);
      if (iVar2 == 0) {
        return iVar1;
      }
      mali_sys_free(iVar1);
    }
    iVar1 = 0;
  }
  return iVar1;
}



/* 4097abfc FUN_4097abfc */

/* Boundary evidence: original MIPS .pdata 4097abfc..4097ac53. Semantic name remains unreviewed. */

undefined4 * FUN_4097abfc(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  puVar1 = (undefined4 *)mali_sys_malloc(400);
  if (puVar1 != (undefined4 *)0x0) {
    FUN_40979f14(puVar1);
    puVar2 = FUN_40970384();
    puVar1[0xd] = puVar2;
    if (puVar2 != (undefined4 *)0x0) {
      return puVar1;
    }
    mali_sys_free(puVar1);
  }
  return (undefined4 *)0x0;
}



/* 4097ac54 FUN_4097ac54 */

/* Boundary evidence: original MIPS .pdata 4097ac54..4097b083. Semantic name remains unreviewed. */

void FUN_4097ac54(int param_1,int param_2)

{
  uint uVar1;
  undefined4 *puVar2;
  int *piVar3;
  uint *puVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  
  puVar2 = *(undefined4 **)(param_2 * 4 + *(int *)(param_1 + 0x34));
  if (puVar2 != (undefined4 *)0x0) {
    puVar2 = (undefined4 *)*puVar2;
    piVar3 = *(int **)*puVar2;
    if (piVar3[1] == 0) {
      uVar1 = mali_mem_mali_addr_get_full(piVar3,puVar2[1]);
    }
    else {
      uVar1 = *piVar3 + puVar2[1];
    }
    uVar9 = uVar1 >> 6;
    switch(param_2) {
    case 0:
      puVar4 = (uint *)**(int **)(param_1 + 0x1c);
      uVar5 = *puVar4;
      uVar7 = puVar4[1];
      uVar8 = puVar4[2];
      *(uint *)(*(int *)(param_1 + 0x34) + 0x140) =
           *(uint *)(*(int *)(param_1 + 0x34) + 0x140) & 0x3fffff | uVar5 << 0x16;
      *(uint *)(*(int *)(param_1 + 0x34) + 0x144) =
           uVar5 >> 10 | *(uint *)(*(int *)(param_1 + 0x34) + 0x144) & 0xfffffff8;
      *(uint *)(*(int *)(param_1 + 0x34) + 0x144) =
           uVar7 << 3 | *(uint *)(*(int *)(param_1 + 0x34) + 0x144) & 0xffff0007;
      *(uint *)(*(int *)(param_1 + 0x34) + 0x144) =
           *(uint *)(*(int *)(param_1 + 0x34) + 0x144) & 0xe000ffff | uVar8 << 0x10;
      FUN_4097a698(param_1);
      *(uint *)(*(int *)(param_1 + 0x34) + 0x138) =
           *(uint *)(*(int *)(param_1 + 0x34) + 0x138) & 0xffffffc0 | puVar2[6];
      iVar6 = *(int *)(param_1 + 0x34);
      *(uint *)(iVar6 + 0x138) =
           *(int *)(iVar6 + 0x17c) << 7 | *(uint *)(iVar6 + 0x138) & 0xffffff7f;
      iVar6 = *(int *)(param_1 + 0x34);
      *(uint *)(iVar6 + 0x138) =
           *(int *)(iVar6 + 0x180) << 6 | *(uint *)(iVar6 + 0x138) & 0xffffffbf;
      *(uint *)(*(int *)(param_1 + 0x34) + 0x150) =
           puVar2[8] << 0xd | *(uint *)(*(int *)(param_1 + 0x34) + 0x150) & 0xffff9fff;
      *(uint *)(*(int *)(param_1 + 0x34) + 0x150) =
           uVar9 << 0x1e | *(uint *)(*(int *)(param_1 + 0x34) + 0x150) & 0x3fffffff;
      *(uint *)(*(int *)(param_1 + 0x34) + 0x154) =
           *(uint *)(*(int *)(param_1 + 0x34) + 0x154) & 0xff000000 | uVar1 >> 8;
      break;
    case 1:
      *(char *)(*(int *)(param_1 + 0x34) + 0x157) = (char)uVar9;
      *(uint *)(*(int *)(param_1 + 0x34) + 0x158) =
           *(uint *)(*(int *)(param_1 + 0x34) + 0x158) & 0xfffc0000 | uVar1 >> 0xe;
      break;
    case 2:
      *(uint *)(*(int *)(param_1 + 0x34) + 0x158) =
           *(uint *)(*(int *)(param_1 + 0x34) + 0x158) & 0x3ffff | uVar9 << 0x12;
      *(uint *)(*(int *)(param_1 + 0x34) + 0x15c) =
           *(uint *)(*(int *)(param_1 + 0x34) + 0x15c) & 0xfffff000 | uVar1 >> 0x14;
      break;
    case 3:
      *(uint *)(*(int *)(param_1 + 0x34) + 0x15c) =
           *(uint *)(*(int *)(param_1 + 0x34) + 0x15c) & 0xfff | uVar9 << 0xc;
      *(uint *)(*(int *)(param_1 + 0x34) + 0x160) =
           *(uint *)(*(int *)(param_1 + 0x34) + 0x160) & 0xffffffc0 | uVar1 >> 0x1a;
      break;
    case 4:
      *(uint *)(*(int *)(param_1 + 0x34) + 0x160) =
           *(uint *)(*(int *)(param_1 + 0x34) + 0x160) & 0x3f | uVar9 << 6;
      break;
    case 5:
      *(uint *)(*(int *)(param_1 + 0x34) + 0x164) =
           *(uint *)(*(int *)(param_1 + 0x34) + 0x164) & 0xfc000000 | uVar9;
      break;
    case 6:
      *(uint *)(*(int *)(param_1 + 0x34) + 0x164) =
           *(uint *)(*(int *)(param_1 + 0x34) + 0x164) & 0x3ffffff | uVar9 << 0x1a;
      *(uint *)(*(int *)(param_1 + 0x34) + 0x168) =
           uVar1 >> 0xc | *(uint *)(*(int *)(param_1 + 0x34) + 0x168) & 0xfff00000;
      break;
    case 7:
      *(uint *)(*(int *)(param_1 + 0x34) + 0x168) =
           uVar9 << 0x14 | *(uint *)(*(int *)(param_1 + 0x34) + 0x168) & 0xfffff;
      *(uint *)(*(int *)(param_1 + 0x34) + 0x16c) =
           uVar1 >> 0x12 | *(uint *)(*(int *)(param_1 + 0x34) + 0x16c) & 0xffffc000;
      break;
    case 8:
      *(uint *)(*(int *)(param_1 + 0x34) + 0x16c) =
           uVar9 << 0xe | *(uint *)(*(int *)(param_1 + 0x34) + 0x16c) & 0x3fff;
      *(uint *)(*(int *)(param_1 + 0x34) + 0x170) =
           *(uint *)(*(int *)(param_1 + 0x34) + 0x170) & 0xffffff00 | uVar1 >> 0x18;
      break;
    case 9:
      *(uint *)(*(int *)(param_1 + 0x34) + 0x170) =
           *(uint *)(*(int *)(param_1 + 0x34) + 0x170) & 0xff | uVar9 << 8;
      *(uint *)(*(int *)(param_1 + 0x34) + 0x174) =
           *(uint *)(*(int *)(param_1 + 0x34) + 0x174) & 0xfffffffc | uVar1 >> 0x1e;
      break;
    case 10:
      *(uint *)(*(int *)(param_1 + 0x34) + 0x174) =
           *(uint *)(*(int *)(param_1 + 0x34) + 0x174) & 0xf0000003 | uVar9 << 2;
    }
  }
  return;
}



/* 4097b084 FUN_4097b084 */

/* Boundary evidence: original MIPS .pdata 4097b084..4097b143. Semantic name remains unreviewed. */

void FUN_4097b084(int *param_1,undefined4 *param_2,int param_3,int param_4)

{
  int iVar1;
  uint uVar2;
  
  FUN_40993230();
  iVar1 = FUN_4096f948((int)param_1,param_3,param_4);
  if ((iVar1 == 0) && (iVar1 = FUN_4096f9a8((int)param_1,param_3,param_4), iVar1 == 0)) {
    uVar2 = mali_sys_atomic_get(param_1 + 0x62);
    if (1 < uVar2) {
      iVar1 = FUN_4096f2d4(param_1);
      iVar1 = mali_cmu_is_cow_space_available(iVar1);
      if ((iVar1 == 0) && (iVar1 = FUN_409931b4(param_2,param_2[0x13d]), iVar1 == 0)) {
        mali_sys_atomic_get(param_1 + 0x62);
      }
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_40993258(0x10);
}



/* 4097b144 FUN_4097b144 */

/* Boundary evidence: original MIPS .pdata 4097b144..4097b167. Semantic name remains unreviewed. */

void FUN_4097b144(undefined4 *param_1,undefined4 param_2)

{
  FUN_40970d40(param_2,param_1);
  return;
}



/* 4097b168 FUN_4097b168 */

/* Boundary evidence: original MIPS .pdata 4097b168..4097b20b. Semantic name remains unreviewed. */

void FUN_4097b168(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  
  FUN_40993230();
  if (param_1 != 0) {
    puVar2 = *(undefined4 **)(param_1 + 0x34);
    if ((puVar2 != (undefined4 *)0x0) &&
       (iVar1 = mali_sys_atomic_dec_and_return(puVar2 + 0x62), iVar1 == 0)) {
      FUN_40970cfc(puVar2);
    }
    *(undefined4 *)(param_1 + 0x34) = 0;
    piVar3 = (int *)(param_1 + 0x1c);
    iVar1 = 6;
    do {
      iVar4 = *piVar3;
      if (iVar4 != 0) {
        iVar5 = 0;
        do {
          if (*piVar3 != 0) {
            FUN_40979ebc(iVar5,*piVar3);
          }
          iVar5 = iVar5 + 1;
        } while (iVar5 < 0xd);
        mali_sys_free(iVar4);
        *piVar3 = 0;
      }
      iVar1 = iVar1 + -1;
      piVar3 = piVar3 + 1;
    } while (iVar1 != 0);
    mali_sys_free(param_1);
  }
                    /* WARNING: Subroutine does not return */
  FUN_40993258(0x10);
}



/* 4097b20c FUN_4097b20c */

/* Boundary evidence: original MIPS .pdata 4097b20c..4097b4ab. Semantic name remains unreviewed. */

void FUN_4097b20c(int param_1,undefined4 *param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  uint *puVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  undefined4 *puVar8;
  undefined4 *puVar9;
  
  FUN_40993300();
  iVar1 = (*(code *)param_2[0x143])(param_4);
  if (((iVar1 != 0) && (*(int *)(iVar1 + 0x20) != 0)) &&
     (iVar7 = *(int *)(*(int *)(iVar1 + 0x20) + 0x10), iVar7 != 0)) {
    iVar6 = *(int *)(iVar7 + 0x18);
    iVar2 = FUN_4096f228(iVar6);
    if ((iVar2 == 1) && ((iVar6 != 0xe || (*(int *)(iVar7 + 0x28) != 1)))) {
      *(undefined4 *)(param_1 + 0x3c) = 1;
      iVar2 = FUN_4097b084(*(int **)(param_1 + 0x34),param_2,param_3,0);
      if (iVar2 == 0) {
        piVar3 = *(int **)(param_1 + 0x34);
        mali_sys_atomic_inc(piVar3 + 0x62);
      }
      else {
        piVar3 = FUN_40970d40(*param_2,*(undefined4 **)(param_1 + 0x34));
        if (piVar3 == (int *)0x0) goto LAB_4097b4a0;
      }
      puVar4 = (uint *)mali_sys_malloc(0x18);
      if (puVar4 == (uint *)0x0) {
        iVar1 = mali_sys_atomic_dec_and_return(piVar3 + 0x62);
        if (iVar1 == 0) {
          FUN_40970cfc(piVar3);
        }
      }
      else {
        *puVar4 = (uint)*(ushort *)(iVar7 + 0xc);
        puVar4[1] = (uint)*(ushort *)(iVar7 + 0xe);
        puVar4[2] = 1;
        puVar4[5] = 0;
        FUN_40970e84(*(undefined4 *)(iVar7 + 0x18),puVar4 + 4,puVar4 + 3);
        iVar2 = FUN_40979e34(param_3);
        iVar6 = 0;
        do {
          FUN_40970330((int)piVar3,iVar2,iVar6);
          iVar5 = *(int *)((iVar2 + 7) * 4 + param_1);
          if (iVar5 != 0) {
            FUN_40979ebc(iVar6,iVar5);
          }
          iVar6 = iVar6 + 1;
        } while (iVar6 < 0xd);
        puVar8 = (undefined4 *)((iVar2 + 7) * 4 + param_1);
        puVar9 = (undefined4 *)*puVar8;
        iVar2 = FUN_4097a5e8(param_1,param_3,0,puVar4);
        if (iVar2 == 0) {
          iVar1 = FUN_4097043c((int)piVar3,param_3,0,iVar7,*(int *)(iVar1 + 0x10));
          if (iVar1 == 0) {
            puVar8 = *(undefined4 **)(param_1 + 0x34);
            iVar1 = mali_sys_atomic_dec_and_return(puVar8 + 0x62);
            if (iVar1 == 0) {
              FUN_40970cfc(puVar8);
            }
            *(int **)(param_1 + 0x34) = piVar3;
            FUN_4097ac54(param_1,0);
            *(undefined4 *)(param_1 + 0x38) = 1;
            *(undefined4 *)(param_1 + 0x48) = 0;
            *(int *)((*(int *)(param_1 + 0x54) + 0x16) * 4 + param_1) = iVar7;
            *(int *)(param_1 + 0x54) = *(int *)(param_1 + 0x54) + 1;
          }
          else {
            iVar1 = mali_sys_atomic_dec_and_return(piVar3 + 0x62);
            if (iVar1 == 0) {
              FUN_40970cfc(piVar3);
            }
            mali_sys_free(puVar4);
            if (puVar9 == (undefined4 *)0x0) {
              mali_sys_free(*puVar8);
              *puVar8 = 0;
            }
            else {
              *puVar9 = 0;
            }
          }
        }
        else {
          iVar1 = mali_sys_atomic_dec_and_return(piVar3 + 0x62);
          if (iVar1 == 0) {
            FUN_40970cfc(piVar3);
          }
          mali_sys_free(puVar4);
        }
      }
    }
  }
LAB_4097b4a0:
                    /* WARNING: Subroutine does not return */
  FUN_40993338(0x18);
}



/* 4097b4ac FUN_4097b4ac */

/* Boundary evidence: original MIPS .pdata 4097b4ac..4097b90f. Semantic name remains unreviewed. */

void FUN_4097b4ac(int param_1,undefined4 *param_2,int param_3,uint param_4)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  undefined4 *puVar8;
  int iVar9;
  int iStack00000028;
  undefined4 *puStack00000030;
  int in_stack_00000070;
  int in_stack_00000074;
  int in_stack_00000078;
  
  FUN_40993300();
  iStack00000028 = param_3;
  puStack00000030 = param_2;
  if ((-1 < in_stack_00000074) && (-1 < in_stack_00000078)) {
    if (in_stack_00000070 == 0x8d64) {
      if ((((int)param_4 < 0) || (0xc < (int)param_4)) ||
         ((0x1000 < in_stack_00000074 ||
          ((0x1000 < in_stack_00000078 || (0x1000 < in_stack_00000074 << (param_4 & 0x1f)))))))
      goto LAB_4097b544;
      iVar1 = in_stack_00000078 << (param_4 & 0x1f);
    }
    else if (((0 < (int)param_4) || (0xc < (int)-param_4)) ||
            (iVar1 = in_stack_00000078, 0x1000 < in_stack_00000074)) goto LAB_4097b544;
    if (iVar1 < 0x1001) {
      *(undefined4 *)(param_1 + 0x3c) = 1;
      if (*(int **)(param_1 + 0x34) != (int *)0x0) {
        uVar5 = param_4;
        if ((int)param_4 < 0) {
          uVar5 = 0;
        }
        iVar1 = FUN_4097b084(*(int **)(param_1 + 0x34),param_2,param_3,uVar5);
        if (iVar1 != 0) {
          piVar2 = FUN_40970d40(*param_2,*(undefined4 **)(param_1 + 0x34));
          if (piVar2 == (int *)0x0) goto LAB_4097b544;
          puVar8 = *(undefined4 **)(param_1 + 0x34);
          iVar1 = mali_sys_atomic_dec_and_return(puVar8 + 0x62);
          if (iVar1 == 0) {
            FUN_40970cfc(puVar8);
          }
          *(int **)(param_1 + 0x34) = piVar2;
        }
        if (in_stack_00000070 != 0x8d64) {
          *(undefined4 *)(param_1 + 0x48) = 1;
          *(uint *)(param_1 + 0x4c) = (uint)(param_4 != 0);
        }
        uVar5 = -param_4;
        iVar1 = 0;
        if (-1 < (int)uVar5) {
          do {
            iVar9 = *(int *)(param_1 + 0x34);
            iVar3 = FUN_4096f9a8(iVar9,param_3,iVar1);
            if ((iVar3 != 0) && (iVar3 = FUN_4096f868(iVar9,param_3,iVar1), iVar3 != 0)) {
              iVar9 = *(int *)(param_1 + 0x54);
              iVar7 = 0;
              if (0 < iVar9) {
                piVar2 = (int *)(param_1 + 0x58);
                do {
                  if (*piVar2 == iVar3) {
                    *(int *)(param_1 + 0x54) = iVar9 + -1;
                    *(undefined4 *)((iVar7 + 0x16) * 4 + param_1) =
                         *(undefined4 *)((iVar9 + 0x15) * 4 + param_1);
                    break;
                  }
                  iVar7 = iVar7 + 1;
                  prefetch(piVar2 + 2,0);
                  piVar2 = piVar2 + 1;
                } while (iVar7 < iVar9);
              }
            }
            iVar1 = iVar1 + 1;
          } while (iVar1 <= (int)uVar5);
        }
        iVar1 = iStack00000028;
        piVar2 = (int *)0x0;
        iVar9 = 0;
        iVar3 = 0;
        if (in_stack_00000070 == 0x8d64) {
          iVar3 = FUN_40979e34(iStack00000028);
          iVar3 = *(int *)((iVar3 + 7) * 4 + param_1);
          if (iVar3 != 0) {
            iVar9 = *(int *)(param_4 * 4 + iVar3);
          }
          piVar2 = (int *)FUN_4097ab5c(param_1,iVar1,param_4);
          if (piVar2 == (int *)0x0) goto LAB_4097b544;
        }
        iVar7 = FUN_40979e34(iStack00000028);
        iVar4 = FUN_40970588(*puStack00000030,*(int *)(param_1 + 0x34),iVar7,param_4);
        iVar1 = iStack00000028;
        if (iVar4 == 0) {
          if (in_stack_00000070 == 0x8d64) {
            *piVar2 = in_stack_00000074;
            piVar2[1] = in_stack_00000078;
            piVar2[2] = 1;
            piVar2[4] = 0;
            piVar2[3] = 0x8d64;
            *(undefined4 *)(param_1 + 0x38) = 1;
            FUN_4097ac54(param_1,param_4);
            iVar1 = iStack00000028;
            uVar5 = param_4;
LAB_4097b8d8:
            iVar1 = FUN_4097a63c(param_1,iVar1,uVar5);
            if ((iVar1 != 0) && (*(int *)(iVar1 + 0x14) != 0)) {
              FUN_40972904();
            }
            FUN_4097ac54(param_1,param_4);
          }
          else {
            iVar3 = 0;
            while( true ) {
              uVar6 = 1;
              if (0 < (int)uVar5) {
                uVar6 = uVar5;
              }
              if ((int)uVar6 < iVar3) goto LAB_4097b8d8;
              piVar2 = (int *)FUN_4097ab5c(param_1,iVar1,iVar3);
              if (piVar2 == (int *)0x0) break;
              *piVar2 = in_stack_00000074;
              piVar2[1] = in_stack_00000078;
              piVar2[2] = 1;
              piVar2[4] = 0;
              piVar2[3] = in_stack_00000070;
              if (in_stack_00000074 < 0) {
                in_stack_00000074 = in_stack_00000074 + 1;
              }
              iVar9 = in_stack_00000074 >> 1;
              in_stack_00000074 = 1;
              if (0 < iVar9) {
                in_stack_00000074 = iVar9;
              }
              if (in_stack_00000078 < 0) {
                in_stack_00000078 = in_stack_00000078 + 1;
              }
              iVar9 = in_stack_00000078 >> 1;
              in_stack_00000078 = 1;
              if (0 < iVar9) {
                in_stack_00000078 = iVar9;
              }
              *(undefined4 *)(param_1 + 0x38) = 1;
              FUN_4097ac54(param_1,iVar3);
              iVar3 = iVar3 + 1;
            }
            *(undefined4 *)(param_1 + 0x4c) = 0;
          }
        }
        else if ((iVar3 == 0) && (in_stack_00000070 == 0x8d64)) {
          if (iVar9 == 0) {
            piVar2 = (int *)((iVar7 + 7) * 4 + param_1);
            mali_sys_free(*(undefined4 *)(param_4 * 4 + *piVar2));
            *(undefined4 *)(param_4 * 4 + *piVar2) = 0;
          }
          puVar8 = (undefined4 *)((iVar7 + 7) * 4 + param_1);
          mali_sys_free(*puVar8);
          *puVar8 = 0;
        }
      }
    }
  }
LAB_4097b544:
                    /* WARNING: Subroutine does not return */
  FUN_40993338(0x38);
}



/* 4097b910 FUN_4097b910 */

/* WARNING: Type propagation algorithm not settling */
/* Boundary evidence: original MIPS .pdata 4097b910..4097bbc7. Semantic name remains unreviewed. */

int FUN_4097b910(int param_1,undefined4 *param_2,int param_3,int param_4)

{
  bool bVar1;
  int iVar2;
  uint uVar3;
  int *piVar4;
  int iVar5;
  int *piVar6;
  
  piVar6 = *(int **)(param_1 + 0x34);
  bVar1 = false;
  iVar2 = FUN_4096fccc((int)piVar6,param_3,param_4);
  if (iVar2 != 0) goto joined_r0x4097ba80;
  iVar5 = *(int *)(param_1 + 0x34);
  iVar2 = FUN_4096f8c8(iVar5,param_3,param_4);
  if ((iVar2 == 0) && (uVar3 = mali_sys_atomic_get(iVar5 + 0x188), uVar3 < 2)) {
LAB_4097baac:
    FUN_4096fc78((int)piVar6,param_3,param_4);
    iVar2 = FUN_40979e34(param_3);
    iVar2 = FUN_4096fa0c(*param_2,*(int *)(param_1 + 0x34),iVar2,param_4);
    if (iVar2 == 0) {
      iVar2 = FUN_4097a63c(param_1,param_3,param_4);
      if (*(int *)(iVar2 + 0x14) != 0) {
        FUN_40972904();
      }
      FUN_4097ac54(param_1,param_4);
      *(undefined4 *)(param_1 + 0x38) = 1;
      if (!bVar1) {
        return 0;
      }
      iVar2 = mali_sys_atomic_dec_and_return(piVar6 + 0x62);
      if (iVar2 != 0) {
        return 0;
      }
      FUN_40970cfc(piVar6);
      return 0;
    }
    if (!bVar1) goto joined_r0x4097ba80;
    iVar5 = mali_sys_atomic_dec_and_return(piVar6 + 0x62);
  }
  else {
    piVar4 = FUN_40970d40(*param_2,*(undefined4 **)(param_1 + 0x34));
    if (piVar4 == (int *)0x0) {
      FUN_4096fc78((int)piVar6,param_3,param_4);
      return 0x505;
    }
    iVar2 = FUN_4096f9a8(*(int *)(param_1 + 0x34),param_3,param_4);
    if (iVar2 == 0) {
LAB_4097baa4:
      *(int **)(param_1 + 0x34) = piVar4;
      bVar1 = true;
      goto LAB_4097baac;
    }
    FUN_4096fc78((int)piVar6,param_3,param_4);
    iVar2 = FUN_4096f168(*(int **)(param_1 + 0x34),(int)piVar4);
    if (iVar2 != 0) {
      iVar5 = mali_sys_atomic_dec_and_return(piVar4 + 0x62);
      if (iVar5 == 0) {
        FUN_40970cfc(piVar4);
        return iVar2;
      }
      return iVar2;
    }
    iVar2 = FUN_4096fccc((int)piVar6,param_3,param_4);
    if (iVar2 == 0) goto LAB_4097baa4;
    iVar5 = mali_sys_atomic_dec_and_return(piVar4 + 0x62);
    piVar6 = piVar4;
  }
  if (iVar5 == 0) {
    FUN_40970cfc(piVar6);
  }
joined_r0x4097ba80:
  if (((iVar2 != -3) && (-3 < iVar2)) && (iVar2 < 0)) {
    return 0x505;
  }
  return 0;
}



/* 4097bbc8 FUN_4097bbc8 */

/* Boundary evidence: original MIPS .pdata 4097bbc8..4097befb. Semantic name remains unreviewed. */

void FUN_4097bbc8(int param_1,undefined4 *param_2,int param_3,int param_4)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  undefined4 *puVar6;
  int *piVar7;
  undefined4 *puStack0000002c;
  int in_stack_00000068;
  int in_stack_0000006c;
  int in_stack_00000070;
  int in_stack_00000074;
  
  FUN_40993300();
  *(undefined4 *)(param_1 + 0x3c) = 1;
  puStack0000002c = param_2;
  iVar1 = FUN_4097b084(*(int **)(param_1 + 0x34),param_2,param_3,param_4);
  if (iVar1 == 0) {
    piVar2 = *(int **)(param_1 + 0x34);
    mali_sys_atomic_inc(piVar2 + 0x62);
  }
  else {
    piVar2 = FUN_40970d40(*param_2,*(undefined4 **)(param_1 + 0x34));
    if (piVar2 == (int *)0x0) goto LAB_4097bef4;
  }
  iVar5 = *(int *)(param_1 + 0x34);
  iVar1 = FUN_4096f9a8(iVar5,param_3,param_4);
  if ((iVar1 != 0) && (iVar1 = FUN_4096f868(iVar5,param_3,param_4), iVar1 != 0)) {
    iVar4 = *(int *)(param_1 + 0x54);
    iVar5 = 0;
    if (0 < iVar4) {
      piVar7 = (int *)(param_1 + 0x58);
      do {
        if (*piVar7 == iVar1) {
          *(int *)(param_1 + 0x54) = iVar4 + -1;
          *(undefined4 *)((iVar5 + 0x16) * 4 + param_1) =
               *(undefined4 *)((iVar4 + 0x15) * 4 + param_1);
          break;
        }
        iVar5 = iVar5 + 1;
        prefetch(piVar7 + 2,0);
        piVar7 = piVar7 + 1;
      } while (iVar5 < iVar4);
    }
  }
  if ((in_stack_00000068 < 1) || (in_stack_0000006c < 1)) {
    iVar1 = FUN_40979e34(param_3);
    FUN_40970330((int)piVar2,iVar1,param_4);
    puVar6 = (undefined4 *)FUN_4097a63c(param_1,param_3,param_4);
    if (puVar6 != (undefined4 *)0x0) {
      *puVar6 = 0;
      puVar6[1] = 0;
    }
  }
  else {
    iVar4 = 0;
    iVar1 = FUN_40979e34(param_3);
    piVar7 = (int *)((iVar1 + 7) * 4 + param_1);
    iVar5 = *piVar7;
    if (iVar5 != 0) {
      iVar4 = *(int *)(param_4 * 4 + iVar5);
    }
    piVar3 = (int *)FUN_4097ab5c(param_1,param_3,param_4);
    if (piVar3 == (int *)0x0) {
      iVar1 = mali_sys_atomic_dec_and_return(piVar2 + 0x62);
      if (iVar1 == 0) {
        FUN_40970cfc(piVar2);
      }
      goto LAB_4097bef4;
    }
    iVar1 = FUN_40970b84(*puStack0000002c,(int)piVar2,iVar1,param_4);
    if (iVar1 != 0) {
      iVar1 = mali_sys_atomic_dec_and_return(piVar2 + 0x62);
      if (iVar1 == 0) {
        FUN_40970cfc(piVar2);
      }
      if (iVar4 == 0) {
        mali_sys_free(*(undefined4 *)(param_4 * 4 + *piVar7));
        *(undefined4 *)(param_4 * 4 + *piVar7) = 0;
      }
      if (iVar5 == 0) {
        mali_sys_free(*piVar7);
        *piVar7 = 0;
      }
      else {
        *(int *)(param_4 * 4 + iVar5) = iVar4;
      }
      goto LAB_4097bef4;
    }
    *piVar3 = in_stack_00000068;
    piVar3[1] = in_stack_0000006c;
    piVar3[2] = 1;
    piVar3[4] = in_stack_00000074;
    piVar3[3] = in_stack_00000070;
  }
  mali_sys_atomic_inc(piVar2 + 0x62);
  puVar6 = *(undefined4 **)(param_1 + 0x34);
  iVar1 = mali_sys_atomic_dec_and_return(puVar6 + 0x62);
  if (iVar1 == 0) {
    FUN_40970cfc(puVar6);
  }
  *(int **)(param_1 + 0x34) = piVar2;
  FUN_4097ac54(param_1,param_4);
  iVar1 = mali_sys_atomic_dec_and_return(piVar2 + 0x62);
  if (iVar1 == 0) {
    FUN_40970cfc(piVar2);
  }
  *(undefined4 *)(param_1 + 0x48) = 0;
  *(undefined4 *)(param_1 + 0x38) = 1;
  iVar1 = FUN_4097a63c(param_1,param_3,param_4);
  if ((iVar1 != 0) && (*(int *)(iVar1 + 0x14) != 0)) {
    FUN_40972904();
  }
LAB_4097bef4:
                    /* WARNING: Subroutine does not return */
  FUN_40993338(0x30);
}



/* 4097befc FUN_4097befc */

/* Boundary evidence: original MIPS .pdata 4097befc..4097c01f. Semantic name remains unreviewed. */

void FUN_4097befc(int param_1,uint param_2,int param_3)

{
  int *piVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  
  FUN_40993230();
  iVar4 = 0;
  if (param_2 == 0) {
    iVar3 = *(int *)((param_3 + 0x137) * 4 + param_1);
  }
  else {
    iVar4 = *(int *)(*(int *)(param_1 + 0x4e8) + 4);
    if (param_2 < 0x100) {
      iVar4 = *(int *)((param_2 + 7) * 4 + iVar4);
    }
    else {
      iVar4 = __mali_named_list_get_non_flat(iVar4,param_2);
    }
    if (iVar4 == 0) {
      iVar3 = 0;
    }
    else {
      iVar3 = *(int *)(iVar4 + 4);
    }
  }
  if ((iVar3 == 0) && (piVar1 = FUN_4097abfc(), piVar1 != (int *)0x0)) {
    *piVar1 = param_3;
    FUN_4097a1b0(piVar1);
    if (iVar4 == 0) {
      puVar2 = (undefined4 *)mali_sys_malloc(8);
      if (puVar2 == (undefined4 *)0x0) {
        FUN_4097b168((int)piVar1);
      }
      else {
        *puVar2 = 1;
        puVar2[1] = 0;
        puVar2[1] = piVar1;
        iVar4 = __mali_named_list_insert
                          (*(undefined4 *)(*(int *)(param_1 + 0x4e8) + 4),param_2,puVar2);
        if (iVar4 != 0) {
          FUN_4097b168((int)piVar1);
          puVar2[1] = 0;
          mali_sys_free(puVar2);
        }
      }
    }
    else {
      *(int **)(iVar4 + 4) = piVar1;
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_40993258(0x10);
}



/* 4097c020 FUN_4097c020 */

/* Boundary evidence: original MIPS .pdata 4097c020..4097c057. Semantic name remains unreviewed. */

void FUN_4097c020(int param_1)

{
  int iVar1;
  
  iVar1 = mali_sys_atomic_dec_and_return(param_1 + 0x50);
  if (iVar1 == 0) {
    FUN_4097b168(param_1);
  }
  return;
}



/* 4097c058 FUN_4097c058 */

/* Boundary evidence: original MIPS .pdata 4097c058..4097c0b7. Semantic name remains unreviewed. */

void FUN_4097c058(int param_1)

{
  int iVar1;
  int iVar2;
  
  if (param_1 != 0) {
    iVar2 = *(int *)(param_1 + 4);
    if (iVar2 != 0) {
      iVar1 = mali_sys_atomic_dec_and_return(iVar2 + 0x50);
      if (iVar1 == 0) {
        FUN_4097b168(iVar2);
      }
      *(undefined4 *)(param_1 + 4) = 0;
    }
    mali_sys_free(param_1);
  }
  return;
}



/* 4097c0b8 FUN_4097c0b8 */

/* Boundary evidence: original MIPS .pdata 4097c0b8..4097c373. Semantic name remains unreviewed. */

void FUN_4097c0b8(int param_1,undefined4 *param_2,int param_3,int param_4)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iStack00000038;
  int iStack0000003c;
  int in_stack_00000078;
  int in_stack_0000007c;
  int in_stack_00000080;
  int in_stack_00000084;
  int in_stack_00000088;
  int in_stack_0000008c;
  
  FUN_40993300();
  iStack00000038 = param_3;
  iStack0000003c = param_1;
  if (((((param_4 < 0) || (0xc < param_4)) || (in_stack_00000078 < 0)) ||
      (((in_stack_0000007c < 0 || (in_stack_00000080 < 0)) ||
       ((in_stack_00000084 < 0 || ((in_stack_00000088 < 0 || (in_stack_0000008c < 0)))))))) ||
     ((0x1000 < in_stack_00000088 ||
      ((((0x1000 < in_stack_0000008c ||
         (piVar1 = (int *)FUN_4097a63c(param_1,param_3,param_4), piVar1 == (int *)0x0)) ||
        (*piVar1 < in_stack_00000078 + in_stack_00000088)) ||
       (piVar1[1] < in_stack_0000007c + in_stack_0000008c)))))) goto LAB_4097c368;
  iVar3 = piVar1[3];
  if (iVar3 == 0x1906) {
LAB_4097c1e8:
    if (param_2[0x121] == 0) {
      iVar3 = param_2[0x128];
    }
    else {
      iVar3 = FUN_40971460(param_2[0x121],0xd55);
    }
    if (iVar3 == 0) {
      if (param_2[0x121] != 0) {
        FUN_40971460(param_2[0x121],0xd52);
      }
      if (param_2[0x121] != 0) {
        FUN_40971460(param_2[0x121],0xd53);
      }
      if (param_2[0x121] != 0) {
        FUN_40971460(param_2[0x121],0xd54);
      }
      goto LAB_4097c368;
    }
  }
  else if (iVar3 != 0x1907) {
    if (iVar3 != 0x1908) {
      if (iVar3 == 0x1909) goto LAB_4097c290;
      if (iVar3 != 0x190a) goto LAB_4097c368;
    }
    if (piVar1[4] == 0x1403) goto LAB_4097c368;
    goto LAB_4097c1e8;
  }
LAB_4097c290:
  if (*(int *)(param_1 + 0x34) != 0) {
    iVar3 = FUN_40979bbc(piVar1[3],piVar1[4]);
    iVar3 = mali_sys_malloc(iVar3 * in_stack_00000088 * in_stack_0000008c);
    if (iVar3 != 0) {
      iVar2 = FUN_409774cc(param_2,in_stack_00000080,in_stack_00000084,in_stack_00000088);
      if (iVar2 == 0) {
        FUN_4097b910(iStack0000003c,param_2,iStack00000038,param_4);
      }
      mali_sys_free(iVar3);
    }
  }
LAB_4097c368:
                    /* WARNING: Subroutine does not return */
  FUN_40993338(0x40);
}



/* 4097c374 FUN_4097c374 */

/* Boundary evidence: original MIPS .pdata 4097c374..4097c627. Semantic name remains unreviewed. */

void FUN_4097c374(int param_1,undefined4 *param_2,int param_3,uint param_4)

{
  int iVar1;
  int iVar2;
  uint *puVar3;
  int in_stack_00000068;
  int in_stack_0000006c;
  int in_stack_00000070;
  uint in_stack_00000074;
  uint in_stack_00000078;
  int in_stack_0000007c;
  
  FUN_40993300();
  if (((((((((int)param_4 < 0) || (0xc < (int)param_4)) || (in_stack_0000006c < 0)) ||
         ((in_stack_00000070 < 0 || ((int)in_stack_00000074 < 0)))) ||
        (((int)in_stack_00000078 < 0 ||
         ((0x1000 < (int)in_stack_00000074 || (0x1000 < (int)in_stack_00000078)))))) ||
       (0x1000 < (int)(in_stack_00000074 << (param_4 & 0x1f)))) ||
      (((0x1000 < (int)(in_stack_00000078 << (param_4 & 0x1f)) ||
        ((in_stack_00000074 != 0 && ((in_stack_00000074 - 1 & in_stack_00000074) != 0)))) ||
       ((in_stack_00000078 != 0 && ((in_stack_00000078 - 1 & in_stack_00000078) != 0)))))) ||
     (in_stack_0000007c != 0)) goto LAB_4097c61c;
  if (in_stack_00000068 == 0x1906) {
LAB_4097c48c:
    if (param_2[0x121] == 0) {
      iVar1 = param_2[0x128];
    }
    else {
      iVar1 = FUN_40971460(param_2[0x121],0xd55);
    }
    if (iVar1 == 0) {
      if (param_2[0x121] != 0) {
        FUN_40971e24(param_2[0x121]);
      }
      goto LAB_4097c61c;
    }
  }
  else if (in_stack_00000068 != 0x1907) {
    if (in_stack_00000068 != 0x1908) {
      if (in_stack_00000068 == 0x1909) goto LAB_4097c4e4;
      if (in_stack_00000068 != 0x190a) goto LAB_4097c61c;
    }
    goto LAB_4097c48c;
  }
LAB_4097c4e4:
  if (*(int *)(param_1 + 0x34) != 0) {
    iVar1 = FUN_40979bbc(in_stack_00000068,0x1401);
    iVar1 = mali_sys_malloc(iVar1 * in_stack_00000074 * in_stack_00000078);
    if (iVar1 != 0) {
      iVar2 = FUN_409774cc(param_2,in_stack_0000006c,in_stack_00000070,in_stack_00000074);
      if (iVar2 == 0) {
        iVar2 = FUN_4097bbc8(param_1,param_2,param_3,param_4);
        mali_sys_free(iVar1);
        if ((iVar2 == 0) &&
           (puVar3 = (uint *)FUN_4097ab5c(param_1,param_3,param_4), puVar3 != (uint *)0x0)) {
          *puVar3 = in_stack_00000074;
          puVar3[1] = in_stack_00000078;
          puVar3[2] = 1;
          iVar1 = FUN_4097a63c(param_1,param_3,param_4);
          if ((iVar1 != 0) && (*(int *)(iVar1 + 0x14) != 0)) {
            FUN_40972904();
          }
        }
      }
      else {
        mali_sys_free(iVar1);
      }
    }
  }
LAB_4097c61c:
                    /* WARNING: Subroutine does not return */
  FUN_40993338(0x30);
}



/* 4097c628 FUN_4097c628 */

/* Boundary evidence: original MIPS .pdata 4097c628..4097c7cf. Semantic name remains unreviewed. */

void FUN_4097c628(int param_1,undefined4 *param_2,int param_3,int param_4)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iStack00000030;
  undefined4 *puStack00000034;
  int in_stack_00000070;
  int in_stack_00000074;
  int in_stack_00000078;
  int in_stack_0000007c;
  uint in_stack_00000080;
  int in_stack_00000084;
  int in_stack_0000008c;
  
  FUN_40993300();
  iStack00000030 = param_3;
  puStack00000034 = param_2;
  if (((((((-1 < param_4) && (param_4 < 0xd)) && (-1 < in_stack_00000070)) &&
        ((-1 < in_stack_00000074 && (-1 < in_stack_00000078)))) &&
       (((-1 < in_stack_0000007c &&
         ((*(int *)(param_1 + 0x1c) != 0 &&
          (piVar2 = *(int **)(param_4 * 4 + *(int *)(param_1 + 0x1c)), piVar2 != (int *)0x0)))) &&
        (iVar1 = FUN_40979c84(in_stack_00000080,piVar2[3],in_stack_00000084), iVar1 == 0)))) &&
      ((((in_stack_00000080 == piVar2[3] && (in_stack_00000084 == piVar2[4])) &&
        (iVar1 = *piVar2, in_stack_00000070 <= iVar1)) &&
       (((iVar3 = piVar2[1], in_stack_00000074 <= iVar3 && (in_stack_00000078 <= iVar1)) &&
        ((in_stack_0000007c <= iVar3 &&
         ((in_stack_00000070 + in_stack_00000078 <= iVar1 &&
          (in_stack_00000074 + in_stack_0000007c <= iVar3)))))))))) &&
     ((*(int *)(param_1 + 0x34) != 0 && ((in_stack_00000078 != 0 && (in_stack_0000007c != 0)))))) {
    FUN_4097a0a0(in_stack_0000008c,in_stack_00000078,in_stack_00000080,in_stack_00000084);
    FUN_4097b910(param_1,puStack00000034,iStack00000030,param_4);
  }
                    /* WARNING: Subroutine does not return */
  FUN_40993338(0x38);
}



/* 4097c7d0 FUN_4097c7d0 */

/* Boundary evidence: original MIPS .pdata 4097c7d0..4097c92b. Semantic name remains unreviewed. */

void FUN_4097c7d0(int param_1,undefined4 *param_2,int param_3,uint param_4)

{
  int iVar1;
  uint uVar2;
  uint in_stack_00000058;
  int in_stack_0000005c;
  int in_stack_00000060;
  int in_stack_00000064;
  uint in_stack_00000068;
  int in_stack_0000006c;
  
  FUN_409933b0();
  iVar1 = FUN_40979c84(in_stack_00000068,in_stack_00000058,in_stack_0000006c);
  if ((((iVar1 != 0) || ((int)param_4 < 0)) || (0xc < (int)param_4)) ||
     ((in_stack_00000064 != 0 || (in_stack_00000068 != in_stack_00000058)))) goto LAB_4097c924;
  if (in_stack_0000006c == 0x8363) {
    uVar2 = 0x1907;
LAB_4097c850:
    if (in_stack_00000068 != uVar2) goto LAB_4097c924;
  }
  else if ((in_stack_0000006c == 0x8033) || (in_stack_0000006c == 0x8034)) {
    uVar2 = 0x1908;
    goto LAB_4097c850;
  }
  if (((((-1 < in_stack_0000005c) && (-1 < in_stack_00000060)) && (in_stack_0000005c < 0x1001)) &&
      ((in_stack_00000060 < 0x1001 && (in_stack_0000005c << (param_4 & 0x1f) < 0x1001)))) &&
     ((in_stack_00000060 << (param_4 & 0x1f) < 0x1001 && (*(int *)(param_1 + 0x34) != 0)))) {
    FUN_4097bbc8(param_1,param_2,param_3,param_4);
  }
LAB_4097c924:
                    /* WARNING: Subroutine does not return */
  FUN_409933e0(0x28);
}



/* 4097c92c FUN_4097c92c */

/* Boundary evidence: original MIPS .pdata 4097c92c..4097cbcb. Semantic name remains unreviewed. */

void FUN_4097c92c(int param_1,undefined4 *param_2,int param_3,int param_4)

{
  int iVar1;
  int *piVar2;
  uint *puVar3;
  int iVar4;
  int iVar5;
  undefined4 *puVar6;
  int in_stack_0000005c;
  int in_stack_00000060;
  
  FUN_40993300();
  if (in_stack_00000060 != 0) {
    iVar5 = *(int *)(in_stack_00000060 + 0x18);
    iVar1 = FUN_4096f228(iVar5);
    if ((iVar1 == 1) && ((iVar5 != 0xe || (*(int *)(in_stack_00000060 + 0x28) != 1)))) {
      *(undefined4 *)(param_1 + 0x3c) = 1;
      iVar1 = FUN_4097b084(*(int **)(param_1 + 0x34),param_2,param_3,param_4);
      if (iVar1 == 0) {
        piVar2 = *(int **)(param_1 + 0x34);
        mali_sys_atomic_inc(piVar2 + 0x62);
      }
      else {
        piVar2 = FUN_40970d40(*param_2,*(undefined4 **)(param_1 + 0x34));
        if (piVar2 == (int *)0x0) goto LAB_4097cbc0;
      }
      puVar3 = (uint *)mali_sys_malloc(0x18);
      if (puVar3 == (uint *)0x0) {
        iVar1 = mali_sys_atomic_dec_and_return(piVar2 + 0x62);
        if (iVar1 == 0) {
          FUN_40970cfc(piVar2);
        }
      }
      else {
        *puVar3 = (uint)*(ushort *)(in_stack_00000060 + 0xc);
        puVar3[1] = (uint)*(ushort *)(in_stack_00000060 + 0xe);
        puVar3[2] = 1;
        puVar3[5] = 0;
        FUN_40970e84(*(undefined4 *)(in_stack_00000060 + 0x18),puVar3 + 4,puVar3 + 3);
        iVar1 = FUN_40979e34(param_3);
        iVar5 = 0;
        do {
          FUN_40970330((int)piVar2,iVar1,iVar5);
          iVar4 = *(int *)((iVar1 + 7) * 4 + param_1);
          if (iVar4 != 0) {
            FUN_40979ebc(iVar5,iVar4);
          }
          iVar5 = iVar5 + 1;
        } while (iVar5 < 0xd);
        iVar5 = FUN_4097043c((int)piVar2,param_3,param_4,in_stack_00000060,0);
        if (iVar5 == 0) {
          iVar5 = FUN_4097a5e8(param_1,param_3,param_4,puVar3);
          if (iVar5 == 0) {
            puVar6 = *(undefined4 **)(param_1 + 0x34);
            iVar1 = mali_sys_atomic_dec_and_return(puVar6 + 0x62);
            if (iVar1 == 0) {
              FUN_40970cfc(puVar6);
            }
            *(int **)(param_1 + 0x34) = piVar2;
            FUN_4097ac54(param_1,param_4);
            *(undefined4 *)(param_1 + 0x48) = 0;
            *(undefined4 *)(param_1 + 0x38) = 1;
            if ((((in_stack_0000005c != 1) || (*(char *)(param_1 + 0x14) == '\0')) || (param_4 != 0)
                ) || (iVar1 = FUN_4096bbcc(param_2,param_1,param_3), iVar1 == 0)) {
              *(int *)((*(int *)(param_1 + 0x54) + 0x16) * 4 + param_1) = in_stack_00000060;
              *(int *)(param_1 + 0x54) = *(int *)(param_1 + 0x54) + 1;
            }
            goto LAB_4097cbc0;
          }
          FUN_40970330((int)piVar2,iVar1,param_4);
          iVar1 = *(int *)((iVar1 + 7) * 4 + param_1);
          if (iVar1 != 0) {
            FUN_40979ebc(param_4,iVar1);
          }
        }
        iVar1 = mali_sys_atomic_dec_and_return(piVar2 + 0x62);
        if (iVar1 == 0) {
          FUN_40970cfc(piVar2);
        }
        mali_sys_free(puVar3);
      }
    }
  }
LAB_4097cbc0:
                    /* WARNING: Subroutine does not return */
  FUN_40993338(0x20);
}



/* 4097cbcc glViewport */

/* Boundary evidence: original MIPS .pdata 4097cbcc..4097cc9f. Semantic name remains unreviewed. */

void glViewport(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  code *pcVar3;
  
                    /* 0x1cbcc  166  glViewport */
  if (DAT_40996364 != 0) {
    if (*(int *)(DAT_40996364 + 8) == 0) {
      iVar1 = *(int *)(DAT_40996364 + 0xc);
    }
    else {
      iVar1 = mali_sys_thread_key_get_data(4);
    }
    if (iVar1 != 0) {
      pcVar3 = *(code **)(*(int *)(iVar1 + 8) + 0x3b4);
      if (pcVar3 != (code *)0x0) {
        (*pcVar3)(iVar1);
      }
      iVar2 = (**(code **)(*(int *)(iVar1 + 8) + 0xe4))(iVar1 + 0xc,param_1,param_2,param_3,param_4)
      ;
      if (iVar2 != 0) {
        (**(code **)(*(int *)(iVar1 + 8) + 0x3b8))(iVar1,iVar2);
      }
    }
  }
  return;
}



/* 4097cca0 glStencilOp */

/* Boundary evidence: original MIPS .pdata 4097cca0..4097cd67. Semantic name remains unreviewed. */

void glStencilOp(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  code *pcVar3;
  
                    /* 0x1cca0  147  glStencilOp */
  if (DAT_40996364 != 0) {
    if (*(int *)(DAT_40996364 + 8) == 0) {
      iVar1 = *(int *)(DAT_40996364 + 0xc);
    }
    else {
      iVar1 = mali_sys_thread_key_get_data(4);
    }
    if (iVar1 != 0) {
      pcVar3 = *(code **)(*(int *)(iVar1 + 8) + 0x3b4);
      if (pcVar3 != (code *)0x0) {
        (*pcVar3)(iVar1);
      }
      iVar2 = (**(code **)(*(int *)(iVar1 + 8) + 200))(iVar1,0x408,param_1,param_2,param_3);
      if (iVar2 != 0) {
        (**(code **)(*(int *)(iVar1 + 8) + 0x3b8))(iVar1,iVar2);
      }
    }
  }
  return;
}



/* 4097cd68 glStencilMask */

/* Boundary evidence: original MIPS .pdata 4097cd68..4097ce0f. Semantic name remains unreviewed. */

void glStencilMask(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  code *pcVar3;
  
                    /* 0x1cd68  146  glStencilMask */
  if (DAT_40996364 != 0) {
    if (*(int *)(DAT_40996364 + 8) == 0) {
      iVar1 = *(int *)(DAT_40996364 + 0xc);
    }
    else {
      iVar1 = mali_sys_thread_key_get_data(4);
    }
    if (iVar1 != 0) {
      pcVar3 = *(code **)(*(int *)(iVar1 + 8) + 0x3b4);
      if (pcVar3 != (code *)0x0) {
        (*pcVar3)(iVar1);
      }
      iVar2 = (**(code **)(*(int *)(iVar1 + 8) + 0xc4))(iVar1,0x408,param_1);
      if (iVar2 != 0) {
        (**(code **)(*(int *)(iVar1 + 8) + 0x3b8))(iVar1,iVar2);
      }
    }
  }
  return;
}



/* 4097ce10 glStencilFunc */

/* Boundary evidence: original MIPS .pdata 4097ce10..4097ced7. Semantic name remains unreviewed. */

void glStencilFunc(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  code *pcVar3;
  
                    /* 0x1ce10  145  glStencilFunc */
  if (DAT_40996364 != 0) {
    if (*(int *)(DAT_40996364 + 8) == 0) {
      iVar1 = *(int *)(DAT_40996364 + 0xc);
    }
    else {
      iVar1 = mali_sys_thread_key_get_data(4);
    }
    if (iVar1 != 0) {
      pcVar3 = *(code **)(*(int *)(iVar1 + 8) + 0x3b4);
      if (pcVar3 != (code *)0x0) {
        (*pcVar3)(iVar1);
      }
      iVar2 = (**(code **)(*(int *)(iVar1 + 8) + 0xc0))(iVar1,0x408,param_1,param_2,param_3);
      if (iVar2 != 0) {
        (**(code **)(*(int *)(iVar1 + 8) + 0x3b8))(iVar1,iVar2);
      }
    }
  }
  return;
}



/* 4097ced8 glScissor */

/* Boundary evidence: original MIPS .pdata 4097ced8..4097cfab. Semantic name remains unreviewed. */

void glScissor(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  code *pcVar3;
  
                    /* 0x1ced8  143  glScissor */
  if (DAT_40996364 != 0) {
    if (*(int *)(DAT_40996364 + 8) == 0) {
      iVar1 = *(int *)(DAT_40996364 + 0xc);
    }
    else {
      iVar1 = mali_sys_thread_key_get_data(4);
    }
    if (iVar1 != 0) {
      pcVar3 = *(code **)(*(int *)(iVar1 + 8) + 0x3b4);
      if (pcVar3 != (code *)0x0) {
        (*pcVar3)(iVar1);
      }
      iVar2 = (**(code **)(*(int *)(iVar1 + 8) + 0xbc))(iVar1,param_1,param_2,param_3,param_4);
      if (iVar2 != 0) {
        (**(code **)(*(int *)(iVar1 + 8) + 0x3b8))(iVar1,iVar2);
      }
    }
  }
  return;
}



/* 4097cfac glSampleCoverage */

/* Boundary evidence: original MIPS .pdata 4097cfac..4097d043. Semantic name remains unreviewed. */

void glSampleCoverage(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  code *pcVar2;
  
                    /* 0x1cfac  139  glSampleCoverage */
  if (DAT_40996364 != 0) {
    if (*(int *)(DAT_40996364 + 8) == 0) {
      iVar1 = *(int *)(DAT_40996364 + 0xc);
    }
    else {
      iVar1 = mali_sys_thread_key_get_data(4);
    }
    if (iVar1 != 0) {
      pcVar2 = *(code **)(*(int *)(iVar1 + 8) + 0x3b4);
      if (pcVar2 != (code *)0x0) {
        (*pcVar2)(iVar1);
      }
      (**(code **)(*(int *)(iVar1 + 8) + 0xb8))(iVar1,param_1,param_2);
    }
  }
  return;
}



/* 4097d044 glPolygonOffset */

/* Boundary evidence: original MIPS .pdata 4097d044..4097d0f7. Semantic name remains unreviewed. */

void glPolygonOffset(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  code *pcVar3;
  
                    /* 0x1d044  131  glPolygonOffset */
  if (DAT_40996364 != 0) {
    if (*(int *)(DAT_40996364 + 8) == 0) {
      iVar1 = *(int *)(DAT_40996364 + 0xc);
    }
    else {
      iVar1 = mali_sys_thread_key_get_data(4);
    }
    if (iVar1 != 0) {
      pcVar3 = *(code **)(*(int *)(iVar1 + 8) + 0x3b4);
      if (pcVar3 != (code *)0x0) {
        (*pcVar3)(iVar1);
      }
      iVar2 = (**(code **)(*(int *)(iVar1 + 8) + 0xb0))(iVar1,param_1,param_2);
      if (iVar2 != 0) {
        (**(code **)(*(int *)(iVar1 + 8) + 0x3b8))(iVar1,iVar2);
      }
    }
  }
  return;
}



/* 4097d0f8 glPixelStorei */

/* Boundary evidence: original MIPS .pdata 4097d0f8..4097d1ab. Semantic name remains unreviewed. */

void glPixelStorei(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  code *pcVar3;
  
                    /* 0x1d0f8  123  glPixelStorei */
  if (DAT_40996364 != 0) {
    if (*(int *)(DAT_40996364 + 8) == 0) {
      iVar1 = *(int *)(DAT_40996364 + 0xc);
    }
    else {
      iVar1 = mali_sys_thread_key_get_data(4);
    }
    if (iVar1 != 0) {
      pcVar3 = *(code **)(*(int *)(iVar1 + 8) + 0x3b4);
      if (pcVar3 != (code *)0x0) {
        (*pcVar3)(iVar1);
      }
      iVar2 = (**(code **)(*(int *)(iVar1 + 8) + 0xac))(iVar1 + 0x3cc,param_1,param_2);
      if (iVar2 != 0) {
        (**(code **)(*(int *)(iVar1 + 8) + 0x3b8))(iVar1,iVar2);
      }
    }
  }
  return;
}



/* 4097d1ac glLineWidth */

/* Boundary evidence: original MIPS .pdata 4097d1ac..4097d237. Semantic name remains unreviewed. */

void glLineWidth(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  
                    /* 0x1d1ac  100  glLineWidth */
  if (DAT_40996364 != 0) {
    if (*(int *)(DAT_40996364 + 8) == 0) {
      iVar1 = *(int *)(DAT_40996364 + 0xc);
    }
    else {
      iVar1 = mali_sys_thread_key_get_data(4);
    }
    if ((iVar1 != 0) &&
       (iVar2 = (**(code **)(*(int *)(iVar1 + 8) + 0xa8))(iVar1,param_1), iVar2 != 0)) {
      (**(code **)(*(int *)(iVar1 + 8) + 0x3b8))(iVar1,iVar2);
    }
  }
  return;
}



/* 4097d238 glIsEnabled */

/* Boundary evidence: original MIPS .pdata 4097d238..4097d2fb. Semantic name remains unreviewed. */

undefined1 glIsEnabled(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  code *pcVar3;
  undefined1 local_18 [8];
  
                    /* 0x1d238  90  glIsEnabled */
  if (DAT_40996364 != 0) {
    if (*(int *)(DAT_40996364 + 8) == 0) {
      iVar1 = *(int *)(DAT_40996364 + 0xc);
    }
    else {
      iVar1 = mali_sys_thread_key_get_data(4);
    }
    if (iVar1 != 0) {
      pcVar3 = *(code **)(*(int *)(iVar1 + 8) + 0x3b4);
      if (pcVar3 != (code *)0x0) {
        (*pcVar3)(iVar1);
      }
      iVar2 = (**(code **)(*(int *)(iVar1 + 8) + 0xa0))(iVar1,param_1,local_18);
      if (iVar2 != 0) {
        (**(code **)(*(int *)(iVar1 + 8) + 0x3b8))(iVar1,iVar2);
      }
      return local_18[0];
    }
  }
  return 0;
}



/* 4097d2fc glHint */

/* Boundary evidence: original MIPS .pdata 4097d2fc..4097d3af. Semantic name remains unreviewed. */

void glHint(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  code *pcVar3;
  
                    /* 0x1d2fc  88  glHint */
  if (DAT_40996364 != 0) {
    if (*(int *)(DAT_40996364 + 8) == 0) {
      iVar1 = *(int *)(DAT_40996364 + 0xc);
    }
    else {
      iVar1 = mali_sys_thread_key_get_data(4);
    }
    if (iVar1 != 0) {
      pcVar3 = *(code **)(*(int *)(iVar1 + 8) + 0x3b4);
      if (pcVar3 != (code *)0x0) {
        (*pcVar3)(iVar1);
      }
      iVar2 = (**(code **)(*(int *)(iVar1 + 8) + 0x98))(iVar1 + 0xc,param_1,param_2);
      if (iVar2 != 0) {
        (**(code **)(*(int *)(iVar1 + 8) + 0x3b8))(iVar1,iVar2);
      }
    }
  }
  return;
}



/* 4097d3b0 glGetString */

/* Boundary evidence: original MIPS .pdata 4097d3b0..4097d473. Semantic name remains unreviewed. */

undefined4 glGetString(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  code *pcVar3;
  undefined4 local_18 [2];
  
                    /* 0x1d3b0  81  glGetString */
  if (DAT_40996364 != 0) {
    if (*(int *)(DAT_40996364 + 8) == 0) {
      iVar1 = *(int *)(DAT_40996364 + 0xc);
    }
    else {
      iVar1 = mali_sys_thread_key_get_data(4);
    }
    if (iVar1 != 0) {
      pcVar3 = *(code **)(*(int *)(iVar1 + 8) + 0x3b4);
      if (pcVar3 != (code *)0x0) {
        (*pcVar3)(iVar1);
      }
      iVar2 = (**(code **)(*(int *)(iVar1 + 8) + 0x8c))(iVar1,param_1,local_18);
      if (iVar2 != 0) {
        (**(code **)(*(int *)(iVar1 + 8) + 0x3b8))(iVar1,iVar2);
      }
      return local_18[0];
    }
  }
  return 0;
}



/* 4097d474 glGetError */

/* Boundary evidence: original MIPS .pdata 4097d474..4097d503. Semantic name remains unreviewed. */

undefined4 glGetError(void)

{
  int iVar1;
  undefined4 uVar2;
  code *pcVar3;
  
                    /* 0x1d474  72  glGetError */
  if (DAT_40996364 != 0) {
    if (*(int *)(DAT_40996364 + 8) == 0) {
      iVar1 = *(int *)(DAT_40996364 + 0xc);
    }
    else {
      iVar1 = mali_sys_thread_key_get_data(4);
    }
    if (iVar1 != 0) {
      pcVar3 = *(code **)(*(int *)(iVar1 + 8) + 0x3b4);
      if (pcVar3 != (code *)0x0) {
        (*pcVar3)(iVar1);
      }
      uVar2 = (**(code **)(*(int *)(iVar1 + 8) + 0x80))(iVar1);
      return uVar2;
    }
  }
  return 0;
}



/* 4097d504 glFrontFace */

/* Boundary evidence: original MIPS .pdata 4097d504..4097d5a7. Semantic name remains unreviewed. */

void glFrontFace(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  code *pcVar3;
  
                    /* 0x1d504  63  glFrontFace */
  if (DAT_40996364 != 0) {
    if (*(int *)(DAT_40996364 + 8) == 0) {
      iVar1 = *(int *)(DAT_40996364 + 0xc);
    }
    else {
      iVar1 = mali_sys_thread_key_get_data(4);
    }
    if (iVar1 != 0) {
      pcVar3 = *(code **)(*(int *)(iVar1 + 8) + 0x3b4);
      if (pcVar3 != (code *)0x0) {
        (*pcVar3)(iVar1);
      }
      iVar2 = (**(code **)(*(int *)(iVar1 + 8) + 0x6c))(iVar1 + 1000,param_1);
      if (iVar2 != 0) {
        (**(code **)(*(int *)(iVar1 + 8) + 0x3b8))(iVar1,iVar2);
      }
    }
  }
  return;
}



/* 4097d5a8 glEnable */

/* Boundary evidence: original MIPS .pdata 4097d5a8..4097d637. Semantic name remains unreviewed. */

void glEnable(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  
                    /* 0x1d5a8  55  glEnable */
  if (DAT_40996364 != 0) {
    if (*(int *)(DAT_40996364 + 8) == 0) {
      iVar1 = *(int *)(DAT_40996364 + 0xc);
    }
    else {
      iVar1 = mali_sys_thread_key_get_data(4);
    }
    if ((iVar1 != 0) &&
       (iVar2 = (**(code **)(*(int *)(iVar1 + 8) + 0x60))(iVar1,param_1,1), iVar2 != 0)) {
      (**(code **)(*(int *)(iVar1 + 8) + 0x3b8))(iVar1,iVar2);
    }
  }
  return;
}



/* 4097d638 glDisable */

/* Boundary evidence: original MIPS .pdata 4097d638..4097d6df. Semantic name remains unreviewed. */

void glDisable(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  code *pcVar3;
  
                    /* 0x1d638  49  glDisable */
  if (DAT_40996364 != 0) {
    if (*(int *)(DAT_40996364 + 8) == 0) {
      iVar1 = *(int *)(DAT_40996364 + 0xc);
    }
    else {
      iVar1 = mali_sys_thread_key_get_data(4);
    }
    if (iVar1 != 0) {
      pcVar3 = *(code **)(*(int *)(iVar1 + 8) + 0x3b4);
      if (pcVar3 != (code *)0x0) {
        (*pcVar3)(iVar1);
      }
      iVar2 = (**(code **)(*(int *)(iVar1 + 8) + 0x54))(iVar1,param_1,0);
      if (iVar2 != 0) {
        (**(code **)(*(int *)(iVar1 + 8) + 0x3b8))(iVar1,iVar2);
      }
    }
  }
  return;
}



/* 4097d6e0 glDepthRangef */

/* Boundary evidence: original MIPS .pdata 4097d6e0..4097d777. Semantic name remains unreviewed. */

void glDepthRangef(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  code *pcVar2;
  
                    /* 0x1d6e0  47  glDepthRangef */
  if (DAT_40996364 != 0) {
    if (*(int *)(DAT_40996364 + 8) == 0) {
      iVar1 = *(int *)(DAT_40996364 + 0xc);
    }
    else {
      iVar1 = mali_sys_thread_key_get_data(4);
    }
    if (iVar1 != 0) {
      pcVar2 = *(code **)(*(int *)(iVar1 + 8) + 0x3b4);
      if (pcVar2 != (code *)0x0) {
        (*pcVar2)(iVar1);
      }
      (**(code **)(*(int *)(iVar1 + 8) + 0x50))(iVar1,param_1,param_2);
    }
  }
  return;
}



/* 4097d778 glDepthMask */

/* Boundary evidence: original MIPS .pdata 4097d778..4097d7ff. Semantic name remains unreviewed. */

void glDepthMask(undefined4 param_1)

{
  int iVar1;
  code *pcVar2;
  
                    /* 0x1d778  46  glDepthMask */
  if (DAT_40996364 != 0) {
    if (*(int *)(DAT_40996364 + 8) == 0) {
      iVar1 = *(int *)(DAT_40996364 + 0xc);
    }
    else {
      iVar1 = mali_sys_thread_key_get_data(4);
    }
    if (iVar1 != 0) {
      pcVar2 = *(code **)(*(int *)(iVar1 + 8) + 0x3b4);
      if (pcVar2 != (code *)0x0) {
        (*pcVar2)(iVar1);
      }
      (**(code **)(*(int *)(iVar1 + 8) + 0x4c))(iVar1,param_1);
    }
  }
  return;
}



/* 4097d800 glDepthFunc */

/* Boundary evidence: original MIPS .pdata 4097d800..4097d8a3. Semantic name remains unreviewed. */

void glDepthFunc(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  code *pcVar3;
  
                    /* 0x1d800  45  glDepthFunc */
  if (DAT_40996364 != 0) {
    if (*(int *)(DAT_40996364 + 8) == 0) {
      iVar1 = *(int *)(DAT_40996364 + 0xc);
    }
    else {
      iVar1 = mali_sys_thread_key_get_data(4);
    }
    if (iVar1 != 0) {
      pcVar3 = *(code **)(*(int *)(iVar1 + 8) + 0x3b4);
      if (pcVar3 != (code *)0x0) {
        (*pcVar3)(iVar1);
      }
      iVar2 = (**(code **)(*(int *)(iVar1 + 8) + 0x48))(iVar1,param_1);
      if (iVar2 != 0) {
        (**(code **)(*(int *)(iVar1 + 8) + 0x3b8))(iVar1,iVar2);
      }
    }
  }
  return;
}



/* 4097d8a4 glCullFace */

/* Boundary evidence: original MIPS .pdata 4097d8a4..4097d947. Semantic name remains unreviewed. */

void glCullFace(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  code *pcVar3;
  
                    /* 0x1d8a4  41  glCullFace */
  if (DAT_40996364 != 0) {
    if (*(int *)(DAT_40996364 + 8) == 0) {
      iVar1 = *(int *)(DAT_40996364 + 0xc);
    }
    else {
      iVar1 = mali_sys_thread_key_get_data(4);
    }
    if (iVar1 != 0) {
      pcVar3 = *(code **)(*(int *)(iVar1 + 8) + 0x3b4);
      if (pcVar3 != (code *)0x0) {
        (*pcVar3)(iVar1);
      }
      iVar2 = (**(code **)(*(int *)(iVar1 + 8) + 0x3c))(iVar1 + 1000,param_1);
      if (iVar2 != 0) {
        (**(code **)(*(int *)(iVar1 + 8) + 0x3b8))(iVar1,iVar2);
      }
    }
  }
  return;
}



/* 4097d948 glColorMask */

/* Boundary evidence: original MIPS .pdata 4097d948..4097d9ff. Semantic name remains unreviewed. */

void glColorMask(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined1 param_4)

{
  int iVar1;
  code *pcVar2;
  
                    /* 0x1d948  35  glColorMask */
  if (DAT_40996364 != 0) {
    if (*(int *)(DAT_40996364 + 8) == 0) {
      iVar1 = *(int *)(DAT_40996364 + 0xc);
    }
    else {
      iVar1 = mali_sys_thread_key_get_data(4);
    }
    if (iVar1 != 0) {
      pcVar2 = *(code **)(*(int *)(iVar1 + 8) + 0x3b4);
      if (pcVar2 != (code *)0x0) {
        (*pcVar2)(iVar1);
      }
      (**(code **)(*(int *)(iVar1 + 8) + 0x28))(iVar1,param_1,param_2,param_3,param_4);
    }
  }
  return;
}



/* 4097da00 glClearStencil */

/* Boundary evidence: original MIPS .pdata 4097da00..4097da87. Semantic name remains unreviewed. */

void glClearStencil(undefined4 param_1)

{
  int iVar1;
  code *pcVar2;
  
                    /* 0x1da00  28  glClearStencil */
  if (DAT_40996364 != 0) {
    if (*(int *)(DAT_40996364 + 8) == 0) {
      iVar1 = *(int *)(DAT_40996364 + 0xc);
    }
    else {
      iVar1 = mali_sys_thread_key_get_data(4);
    }
    if (iVar1 != 0) {
      pcVar2 = *(code **)(*(int *)(iVar1 + 8) + 0x3b4);
      if (pcVar2 != (code *)0x0) {
        (*pcVar2)(iVar1);
      }
      (**(code **)(*(int *)(iVar1 + 8) + 0x24))(iVar1 + 0x454,param_1);
    }
  }
  return;
}



/* 4097da88 glClearDepthf */

/* Boundary evidence: original MIPS .pdata 4097da88..4097db0f. Semantic name remains unreviewed. */

void glClearDepthf(undefined4 param_1)

{
  int iVar1;
  code *pcVar2;
  
                    /* 0x1da88  26  glClearDepthf */
  if (DAT_40996364 != 0) {
    if (*(int *)(DAT_40996364 + 8) == 0) {
      iVar1 = *(int *)(DAT_40996364 + 0xc);
    }
    else {
      iVar1 = mali_sys_thread_key_get_data(4);
    }
    if (iVar1 != 0) {
      pcVar2 = *(code **)(*(int *)(iVar1 + 8) + 0x3b4);
      if (pcVar2 != (code *)0x0) {
        (*pcVar2)(iVar1);
      }
      (**(code **)(*(int *)(iVar1 + 8) + 0x20))(iVar1 + 0x454,param_1);
    }
  }
  return;
}



/* 4097db10 glClearColor */

/* Boundary evidence: original MIPS .pdata 4097db10..4097dbc7. Semantic name remains unreviewed. */

void glClearColor(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  code *pcVar2;
  
                    /* 0x1db10  24  glClearColor */
  if (DAT_40996364 != 0) {
    if (*(int *)(DAT_40996364 + 8) == 0) {
      iVar1 = *(int *)(DAT_40996364 + 0xc);
    }
    else {
      iVar1 = mali_sys_thread_key_get_data(4);
    }
    if (iVar1 != 0) {
      pcVar2 = *(code **)(*(int *)(iVar1 + 8) + 0x3b4);
      if (pcVar2 != (code *)0x0) {
        (*pcVar2)(iVar1);
      }
      (**(code **)(*(int *)(iVar1 + 8) + 0x1c))(iVar1 + 0x454,param_1,param_2,param_3,param_4);
    }
  }
  return;
}



/* 4097dbc8 glBlendFunc */

/* Boundary evidence: original MIPS .pdata 4097dbc8..4097dc83. Semantic name remains unreviewed. */

void glBlendFunc(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  code *pcVar3;
  
                    /* 0x1dbc8  20  glBlendFunc */
  if (DAT_40996364 != 0) {
    if (*(int *)(DAT_40996364 + 8) == 0) {
      iVar1 = *(int *)(DAT_40996364 + 0xc);
    }
    else {
      iVar1 = mali_sys_thread_key_get_data(4);
    }
    if (iVar1 != 0) {
      pcVar3 = *(code **)(*(int *)(iVar1 + 8) + 0x3b4);
      if (pcVar3 != (code *)0x0) {
        (*pcVar3)(iVar1);
      }
      iVar2 = (**(code **)(*(int *)(iVar1 + 8) + 0xc))(iVar1,param_1,param_2,param_1,param_2);
      if (iVar2 != 0) {
        (**(code **)(*(int *)(iVar1 + 8) + 0x3b8))(iVar1,iVar2);
      }
    }
  }
  return;
}



/* 4097dc84 FUN_4097dc84 */

/* Boundary evidence: original MIPS .pdata 4097dc84..4097dc9f. Semantic name remains unreviewed. */

void FUN_4097dc84(int param_1)

{
  mali_sys_mutex_unlock(*(undefined4 *)(param_1 + 0x1c));
  return;
}



/* 4097dca0 FUN_4097dca0 */

/* Boundary evidence: original MIPS .pdata 4097dca0..4097dcbb. Semantic name remains unreviewed. */

void FUN_4097dca0(int param_1)

{
  mali_sys_mutex_lock(*(undefined4 *)(param_1 + 0x1c));
  return;
}



/* 4097dcbc glEGLImageTargetRenderbufferStorageOES */

/* Boundary evidence: original MIPS .pdata 4097dcbc..4097dd8b. Semantic name remains unreviewed. */

void glEGLImageTargetRenderbufferStorageOES(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  code *pcVar3;
  
                    /* 0x1dcbc  53  glEGLImageTargetRenderbufferStorageOES */
  if (DAT_40996364 != 0) {
    if (*(int *)(DAT_40996364 + 8) == 0) {
      iVar1 = *(int *)(DAT_40996364 + 0xc);
    }
    else {
      iVar1 = mali_sys_thread_key_get_data(4);
    }
    if (iVar1 != 0) {
      pcVar3 = *(code **)(*(int *)(iVar1 + 8) + 0x3b4);
      if (pcVar3 != (code *)0x0) {
        (*pcVar3)(iVar1);
      }
      mali_sys_mutex_lock(*(undefined4 *)(*(int *)(iVar1 + 0x4e8) + 0x1c));
      iVar2 = (**(code **)(*(int *)(iVar1 + 8) + 0x128))(iVar1,param_1,param_2);
      mali_sys_mutex_unlock(*(undefined4 *)(*(int *)(iVar1 + 0x4e8) + 0x1c));
      if (iVar2 != 0) {
        (**(code **)(*(int *)(iVar1 + 8) + 0x3b8))(iVar1,iVar2);
      }
    }
  }
  return;
}



/* 4097dd8c glEGLImageTargetTexture2DOES */

/* Boundary evidence: original MIPS .pdata 4097dd8c..4097de5b. Semantic name remains unreviewed. */

void glEGLImageTargetTexture2DOES(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  code *pcVar3;
  
                    /* 0x1dd8c  54  glEGLImageTargetTexture2DOES */
  if (DAT_40996364 != 0) {
    if (*(int *)(DAT_40996364 + 8) == 0) {
      iVar1 = *(int *)(DAT_40996364 + 0xc);
    }
    else {
      iVar1 = mali_sys_thread_key_get_data(4);
    }
    if (iVar1 != 0) {
      pcVar3 = *(code **)(*(int *)(iVar1 + 8) + 0x3b4);
      if (pcVar3 != (code *)0x0) {
        (*pcVar3)(iVar1);
      }
      mali_sys_mutex_lock(*(undefined4 *)(*(int *)(iVar1 + 0x4e8) + 0x1c));
      iVar2 = (**(code **)(*(int *)(iVar1 + 8) + 0x124))(iVar1,param_1,param_2);
      mali_sys_mutex_unlock(*(undefined4 *)(*(int *)(iVar1 + 0x4e8) + 0x1c));
      if (iVar2 != 0) {
        (**(code **)(*(int *)(iVar1 + 8) + 0x3b8))(iVar1,iVar2);
      }
    }
  }
  return;
}



/* 4097de5c glTexSubImage2D */

/* Boundary evidence: original MIPS .pdata 4097de5c..4097df7b. Semantic name remains unreviewed. */

void glTexSubImage2D(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                    undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
                    undefined4 param_9)

{
  int iVar1;
  int iVar2;
  code *pcVar3;
  
                    /* 0x1de5c  162  glTexSubImage2D */
  if (DAT_40996364 != 0) {
    if (*(int *)(DAT_40996364 + 8) == 0) {
      iVar1 = *(int *)(DAT_40996364 + 0xc);
    }
    else {
      iVar1 = mali_sys_thread_key_get_data(4);
    }
    if (iVar1 != 0) {
      pcVar3 = *(code **)(*(int *)(iVar1 + 8) + 0x3b4);
      if (pcVar3 != (code *)0x0) {
        (*pcVar3)(iVar1);
      }
      mali_sys_mutex_lock(*(undefined4 *)(*(int *)(iVar1 + 0x4e8) + 0x1c));
      iVar2 = (**(code **)(*(int *)(iVar1 + 8) + 0xe0))
                        (iVar1,param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,
                         param_9,*(undefined4 *)(iVar1 + 0x3d0));
      mali_sys_mutex_unlock(*(undefined4 *)(*(int *)(iVar1 + 0x4e8) + 0x1c));
      if (iVar2 != 0) {
        (**(code **)(*(int *)(iVar1 + 8) + 0x3b8))(iVar1,iVar2);
      }
    }
  }
  return;
}



/* 4097df7c glTexParameteriv */

/* Boundary evidence: original MIPS .pdata 4097df7c..4097e063. Semantic name remains unreviewed. */

void glTexParameteriv(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  code *pcVar3;
  
                    /* 0x1df7c  159  glTexParameteriv */
  if (DAT_40996364 != 0) {
    if (*(int *)(DAT_40996364 + 8) == 0) {
      iVar1 = *(int *)(DAT_40996364 + 0xc);
    }
    else {
      iVar1 = mali_sys_thread_key_get_data(4);
    }
    if (iVar1 != 0) {
      pcVar3 = *(code **)(*(int *)(iVar1 + 8) + 0x3b4);
      if (pcVar3 != (code *)0x0) {
        (*pcVar3)(iVar1);
      }
      mali_sys_mutex_lock(*(undefined4 *)(*(int *)(iVar1 + 0x4e8) + 0x1c));
      iVar2 = (**(code **)(*(int *)(iVar1 + 8) + 0xdc))(iVar1 + 0x328,param_1,param_2,param_3,3);
      mali_sys_mutex_unlock(*(undefined4 *)(*(int *)(iVar1 + 0x4e8) + 0x1c));
      if (iVar2 != 0) {
        (**(code **)(*(int *)(iVar1 + 8) + 0x3b8))(iVar1,iVar2);
      }
    }
  }
  return;
}



/* 4097e064 glTexParameteri */

/* Boundary evidence: original MIPS .pdata 4097e064..4097e143. Semantic name remains unreviewed. */

void glTexParameteri(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  code *pcVar3;
  undefined4 local_res8 [2];
  
                    /* 0x1e064  158  glTexParameteri */
  if (DAT_40996364 != 0) {
    local_res8[0] = param_3;
    if (*(int *)(DAT_40996364 + 8) == 0) {
      iVar1 = *(int *)(DAT_40996364 + 0xc);
    }
    else {
      iVar1 = mali_sys_thread_key_get_data(4);
    }
    if (iVar1 != 0) {
      pcVar3 = *(code **)(*(int *)(iVar1 + 8) + 0x3b4);
      if (pcVar3 != (code *)0x0) {
        (*pcVar3)(iVar1);
      }
      mali_sys_mutex_lock(*(undefined4 *)(*(int *)(iVar1 + 0x4e8) + 0x1c));
      iVar2 = (**(code **)(*(int *)(iVar1 + 8) + 0xd8))(iVar1 + 0x328,param_1,param_2,local_res8,3);
      mali_sys_mutex_unlock(*(undefined4 *)(*(int *)(iVar1 + 0x4e8) + 0x1c));
      if (iVar2 != 0) {
        (**(code **)(*(int *)(iVar1 + 8) + 0x3b8))(iVar1,iVar2);
      }
    }
  }
  return;
}



/* 4097e144 glTexParameterfv */

/* Boundary evidence: original MIPS .pdata 4097e144..4097e227. Semantic name remains unreviewed. */

void glTexParameterfv(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  code *pcVar3;
  
                    /* 0x1e144  157  glTexParameterfv */
  if (DAT_40996364 != 0) {
    if (*(int *)(DAT_40996364 + 8) == 0) {
      iVar1 = *(int *)(DAT_40996364 + 0xc);
    }
    else {
      iVar1 = mali_sys_thread_key_get_data(4);
    }
    if (iVar1 != 0) {
      pcVar3 = *(code **)(*(int *)(iVar1 + 8) + 0x3b4);
      if (pcVar3 != (code *)0x0) {
        (*pcVar3)(iVar1);
      }
      mali_sys_mutex_lock(*(undefined4 *)(*(int *)(iVar1 + 0x4e8) + 0x1c));
      iVar2 = (**(code **)(*(int *)(iVar1 + 8) + 0xd4))(iVar1 + 0x328,param_1,param_2,param_3,0);
      mali_sys_mutex_unlock(*(undefined4 *)(*(int *)(iVar1 + 0x4e8) + 0x1c));
      if (iVar2 != 0) {
        (**(code **)(*(int *)(iVar1 + 8) + 0x3b8))(iVar1,iVar2);
      }
    }
  }
  return;
}



/* 4097e228 glTexParameterf */

/* Boundary evidence: original MIPS .pdata 4097e228..4097e303. Semantic name remains unreviewed. */

void glTexParameterf(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  code *pcVar3;
  undefined4 local_res8 [2];
  
                    /* 0x1e228  156  glTexParameterf */
  if (DAT_40996364 != 0) {
    local_res8[0] = param_3;
    if (*(int *)(DAT_40996364 + 8) == 0) {
      iVar1 = *(int *)(DAT_40996364 + 0xc);
    }
    else {
      iVar1 = mali_sys_thread_key_get_data(4);
    }
    if (iVar1 != 0) {
      pcVar3 = *(code **)(*(int *)(iVar1 + 8) + 0x3b4);
      if (pcVar3 != (code *)0x0) {
        (*pcVar3)(iVar1);
      }
      mali_sys_mutex_lock(*(undefined4 *)(*(int *)(iVar1 + 0x4e8) + 0x1c));
      iVar2 = (**(code **)(*(int *)(iVar1 + 8) + 0xd0))(iVar1 + 0x328,param_1,param_2,local_res8,0);
      mali_sys_mutex_unlock(*(undefined4 *)(*(int *)(iVar1 + 0x4e8) + 0x1c));
      if (iVar2 != 0) {
        (**(code **)(*(int *)(iVar1 + 8) + 0x3b8))(iVar1,iVar2);
      }
    }
  }
  return;
}



/* 4097e304 glTexImage2D */

/* Boundary evidence: original MIPS .pdata 4097e304..4097e423. Semantic name remains unreviewed. */

void glTexImage2D(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
                 undefined4 param_9)

{
  int iVar1;
  int iVar2;
  code *pcVar3;
  
                    /* 0x1e304  155  glTexImage2D */
  if (DAT_40996364 != 0) {
    if (*(int *)(DAT_40996364 + 8) == 0) {
      iVar1 = *(int *)(DAT_40996364 + 0xc);
    }
    else {
      iVar1 = mali_sys_thread_key_get_data(4);
    }
    if (iVar1 != 0) {
      pcVar3 = *(code **)(*(int *)(iVar1 + 8) + 0x3b4);
      if (pcVar3 != (code *)0x0) {
        (*pcVar3)(iVar1);
      }
      mali_sys_mutex_lock(*(undefined4 *)(*(int *)(iVar1 + 0x4e8) + 0x1c));
      iVar2 = (**(code **)(*(int *)(iVar1 + 8) + 0xcc))
                        (iVar1,param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,
                         param_9,*(undefined4 *)(iVar1 + 0x3d0));
      mali_sys_mutex_unlock(*(undefined4 *)(*(int *)(iVar1 + 0x4e8) + 0x1c));
      if (iVar2 != 0) {
        (**(code **)(*(int *)(iVar1 + 8) + 0x3b8))(iVar1,iVar2);
      }
    }
  }
  return;
}



/* 4097e424 glReadPixels */

/* Boundary evidence: original MIPS .pdata 4097e424..4097e52b. Semantic name remains unreviewed. */

void glReadPixels(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,undefined4 param_7)

{
  int iVar1;
  int iVar2;
  code *pcVar3;
  
                    /* 0x1e424  136  glReadPixels */
  if (DAT_40996364 != 0) {
    if (*(int *)(DAT_40996364 + 8) == 0) {
      iVar1 = *(int *)(DAT_40996364 + 0xc);
    }
    else {
      iVar1 = mali_sys_thread_key_get_data(4);
    }
    if (iVar1 != 0) {
      pcVar3 = *(code **)(*(int *)(iVar1 + 8) + 0x3b4);
      if (pcVar3 != (code *)0x0) {
        (*pcVar3)(iVar1);
      }
      mali_sys_mutex_lock(*(undefined4 *)(*(int *)(iVar1 + 0x4e8) + 0x1c));
      iVar2 = (**(code **)(*(int *)(iVar1 + 8) + 0xb4))
                        (iVar1,param_1,param_2,param_3,param_4,param_5,param_6,param_7);
      mali_sys_mutex_unlock(*(undefined4 *)(*(int *)(iVar1 + 0x4e8) + 0x1c));
      if (iVar2 != 0) {
        (**(code **)(*(int *)(iVar1 + 8) + 0x3b8))(iVar1,iVar2);
      }
    }
  }
  return;
}



/* 4097e52c glIsTexture */

/* Boundary evidence: original MIPS .pdata 4097e52c..4097e5ef. Semantic name remains unreviewed. */

undefined4 glIsTexture(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  code *pcVar3;
  
                    /* 0x1e52c  91  glIsTexture */
  if (DAT_40996364 != 0) {
    if (*(int *)(DAT_40996364 + 8) == 0) {
      iVar1 = *(int *)(DAT_40996364 + 0xc);
    }
    else {
      iVar1 = mali_sys_thread_key_get_data(4);
    }
    if (iVar1 != 0) {
      pcVar3 = *(code **)(*(int *)(iVar1 + 8) + 0x3b4);
      if (pcVar3 != (code *)0x0) {
        (*pcVar3)(iVar1);
      }
      mali_sys_mutex_lock(*(undefined4 *)(*(int *)(iVar1 + 0x4e8) + 0x1c));
      uVar2 = (**(code **)(*(int *)(iVar1 + 8) + 0xa4))
                        (*(undefined4 *)(*(int *)(iVar1 + 0x4e8) + 4),param_1);
      mali_sys_mutex_unlock(*(undefined4 *)(*(int *)(iVar1 + 0x4e8) + 0x1c));
      return uVar2;
    }
  }
  return 0;
}



/* 4097e5f0 glIsBuffer */

/* Boundary evidence: original MIPS .pdata 4097e5f0..4097e6b3. Semantic name remains unreviewed. */

undefined4 glIsBuffer(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  code *pcVar3;
  
                    /* 0x1e5f0  89  glIsBuffer */
  if (DAT_40996364 != 0) {
    if (*(int *)(DAT_40996364 + 8) == 0) {
      iVar1 = *(int *)(DAT_40996364 + 0xc);
    }
    else {
      iVar1 = mali_sys_thread_key_get_data(4);
    }
    if (iVar1 != 0) {
      pcVar3 = *(code **)(*(int *)(iVar1 + 8) + 0x3b4);
      if (pcVar3 != (code *)0x0) {
        (*pcVar3)(iVar1);
      }
      mali_sys_mutex_lock(*(undefined4 *)(*(int *)(iVar1 + 0x4e8) + 0x1c));
      uVar2 = (**(code **)(*(int *)(iVar1 + 8) + 0x9c))
                        (*(undefined4 *)(*(int *)(iVar1 + 0x4e8) + 8),param_1);
      mali_sys_mutex_unlock(*(undefined4 *)(*(int *)(iVar1 + 0x4e8) + 0x1c));
      return uVar2;
    }
  }
  return 0;
}



/* 4097e6b4 glGetTexParameteriv */

/* Boundary evidence: original MIPS .pdata 4097e6b4..4097e79b. Semantic name remains unreviewed. */

void glGetTexParameteriv(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  code *pcVar3;
  
                    /* 0x1e6b4  86  glGetTexParameteriv */
  if (DAT_40996364 != 0) {
    if (*(int *)(DAT_40996364 + 8) == 0) {
      iVar1 = *(int *)(DAT_40996364 + 0xc);
    }
    else {
      iVar1 = mali_sys_thread_key_get_data(4);
    }
    if (iVar1 != 0) {
      pcVar3 = *(code **)(*(int *)(iVar1 + 8) + 0x3b4);
      if (pcVar3 != (code *)0x0) {
        (*pcVar3)(iVar1);
      }
      mali_sys_mutex_lock(*(undefined4 *)(*(int *)(iVar1 + 0x4e8) + 0x1c));
      iVar2 = (**(code **)(*(int *)(iVar1 + 8) + 0x94))(iVar1 + 0xc,param_1,param_2,param_3,3);
      mali_sys_mutex_unlock(*(undefined4 *)(*(int *)(iVar1 + 0x4e8) + 0x1c));
      if (iVar2 != 0) {
        (**(code **)(*(int *)(iVar1 + 8) + 0x3b8))(iVar1,iVar2);
      }
    }
  }
  return;
}



/* 4097e79c glGetTexParameterfv */

/* Boundary evidence: original MIPS .pdata 4097e79c..4097e87f. Semantic name remains unreviewed. */

void glGetTexParameterfv(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  code *pcVar3;
  
                    /* 0x1e79c  85  glGetTexParameterfv */
  if (DAT_40996364 != 0) {
    if (*(int *)(DAT_40996364 + 8) == 0) {
      iVar1 = *(int *)(DAT_40996364 + 0xc);
    }
    else {
      iVar1 = mali_sys_thread_key_get_data(4);
    }
    if (iVar1 != 0) {
      pcVar3 = *(code **)(*(int *)(iVar1 + 8) + 0x3b4);
      if (pcVar3 != (code *)0x0) {
        (*pcVar3)(iVar1);
      }
      mali_sys_mutex_lock(*(undefined4 *)(*(int *)(iVar1 + 0x4e8) + 0x1c));
      iVar2 = (**(code **)(*(int *)(iVar1 + 8) + 0x90))(iVar1 + 0xc,param_1,param_2,param_3,0);
      mali_sys_mutex_unlock(*(undefined4 *)(*(int *)(iVar1 + 0x4e8) + 0x1c));
      if (iVar2 != 0) {
        (**(code **)(*(int *)(iVar1 + 8) + 0x3b8))(iVar1,iVar2);
      }
    }
  }
  return;
}



/* 4097e880 glGetIntegerv */

/* Boundary evidence: original MIPS .pdata 4097e880..4097e953. Semantic name remains unreviewed. */

void glGetIntegerv(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  code *pcVar3;
  
                    /* 0x1e880  75  glGetIntegerv */
  if (DAT_40996364 != 0) {
    if (*(int *)(DAT_40996364 + 8) == 0) {
      iVar1 = *(int *)(DAT_40996364 + 0xc);
    }
    else {
      iVar1 = mali_sys_thread_key_get_data(4);
    }
    if (iVar1 != 0) {
      pcVar3 = *(code **)(*(int *)(iVar1 + 8) + 0x3b4);
      if (pcVar3 != (code *)0x0) {
        (*pcVar3)(iVar1);
      }
      mali_sys_mutex_lock(*(undefined4 *)(*(int *)(iVar1 + 0x4e8) + 0x1c));
      iVar2 = (**(code **)(*(int *)(iVar1 + 8) + 0x88))(iVar1,param_1,param_2,3);
      mali_sys_mutex_unlock(*(undefined4 *)(*(int *)(iVar1 + 0x4e8) + 0x1c));
      if (iVar2 != 0) {
        (**(code **)(*(int *)(iVar1 + 8) + 0x3b8))(iVar1,iVar2);
      }
    }
  }
  return;
}



/* 4097e954 glGetFloatv */

/* Boundary evidence: original MIPS .pdata 4097e954..4097ea27. Semantic name remains unreviewed. */

void glGetFloatv(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  code *pcVar3;
  
                    /* 0x1e954  74  glGetFloatv */
  if (DAT_40996364 != 0) {
    if (*(int *)(DAT_40996364 + 8) == 0) {
      iVar1 = *(int *)(DAT_40996364 + 0xc);
    }
    else {
      iVar1 = mali_sys_thread_key_get_data(4);
    }
    if (iVar1 != 0) {
      pcVar3 = *(code **)(*(int *)(iVar1 + 8) + 0x3b4);
      if (pcVar3 != (code *)0x0) {
        (*pcVar3)(iVar1);
      }
      mali_sys_mutex_lock(*(undefined4 *)(*(int *)(iVar1 + 0x4e8) + 0x1c));
      iVar2 = (**(code **)(*(int *)(iVar1 + 8) + 0x84))(iVar1,param_1,param_2,0);
      mali_sys_mutex_unlock(*(undefined4 *)(*(int *)(iVar1 + 0x4e8) + 0x1c));
      if (iVar2 != 0) {
        (**(code **)(*(int *)(iVar1 + 8) + 0x3b8))(iVar1,iVar2);
      }
    }
  }
  return;
}



/* 4097ea28 glGetBufferParameteriv */

/* Boundary evidence: original MIPS .pdata 4097ea28..4097eb07. Semantic name remains unreviewed. */

void glGetBufferParameteriv(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  code *pcVar3;
  
                    /* 0x1ea28  69  glGetBufferParameteriv */
  if (DAT_40996364 != 0) {
    if (*(int *)(DAT_40996364 + 8) == 0) {
      iVar1 = *(int *)(DAT_40996364 + 0xc);
    }
    else {
      iVar1 = mali_sys_thread_key_get_data(4);
    }
    if (iVar1 != 0) {
      pcVar3 = *(code **)(*(int *)(iVar1 + 8) + 0x3b4);
      if (pcVar3 != (code *)0x0) {
        (*pcVar3)(iVar1);
      }
      mali_sys_mutex_lock(*(undefined4 *)(*(int *)(iVar1 + 0x4e8) + 0x1c));
      iVar2 = (**(code **)(*(int *)(iVar1 + 8) + 0x7c))(iVar1 + 0xc,param_1,param_2,param_3);
      mali_sys_mutex_unlock(*(undefined4 *)(*(int *)(iVar1 + 0x4e8) + 0x1c));
      if (iVar2 != 0) {
        (**(code **)(*(int *)(iVar1 + 8) + 0x3b8))(iVar1,iVar2);
      }
    }
  }
  return;
}



/* 4097eb08 glGetBooleanv */

/* Boundary evidence: original MIPS .pdata 4097eb08..4097ebdb. Semantic name remains unreviewed. */

void glGetBooleanv(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  code *pcVar3;
  
                    /* 0x1eb08  68  glGetBooleanv */
  if (DAT_40996364 != 0) {
    if (*(int *)(DAT_40996364 + 8) == 0) {
      iVar1 = *(int *)(DAT_40996364 + 0xc);
    }
    else {
      iVar1 = mali_sys_thread_key_get_data(4);
    }
    if (iVar1 != 0) {
      pcVar3 = *(code **)(*(int *)(iVar1 + 8) + 0x3b4);
      if (pcVar3 != (code *)0x0) {
        (*pcVar3)(iVar1);
      }
      mali_sys_mutex_lock(*(undefined4 *)(*(int *)(iVar1 + 0x4e8) + 0x1c));
      iVar2 = (**(code **)(*(int *)(iVar1 + 8) + 0x78))(iVar1,param_1,param_2,4);
      mali_sys_mutex_unlock(*(undefined4 *)(*(int *)(iVar1 + 0x4e8) + 0x1c));
      if (iVar2 != 0) {
        (**(code **)(*(int *)(iVar1 + 8) + 0x3b8))(iVar1,iVar2);
      }
    }
  }
  return;
}



/* 4097ebdc glGenTextures */

/* Boundary evidence: original MIPS .pdata 4097ebdc..4097ecb3. Semantic name remains unreviewed. */

void glGenTextures(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  code *pcVar3;
  
                    /* 0x1ebdc  67  glGenTextures */
  if (DAT_40996364 != 0) {
    if (*(int *)(DAT_40996364 + 8) == 0) {
      iVar1 = *(int *)(DAT_40996364 + 0xc);
    }
    else {
      iVar1 = mali_sys_thread_key_get_data(4);
    }
    if (iVar1 != 0) {
      pcVar3 = *(code **)(*(int *)(iVar1 + 8) + 0x3b4);
      if (pcVar3 != (code *)0x0) {
        (*pcVar3)(iVar1);
      }
      mali_sys_mutex_lock(*(undefined4 *)(*(int *)(iVar1 + 0x4e8) + 0x1c));
      iVar2 = (**(code **)(*(int *)(iVar1 + 8) + 0x74))
                        (*(undefined4 *)(*(int *)(iVar1 + 0x4e8) + 4),param_1,param_2,1);
      mali_sys_mutex_unlock(*(undefined4 *)(*(int *)(iVar1 + 0x4e8) + 0x1c));
      if (iVar2 != 0) {
        (**(code **)(*(int *)(iVar1 + 8) + 0x3b8))(iVar1,iVar2);
      }
    }
  }
  return;
}



/* 4097ecb4 glGenBuffers */

/* Boundary evidence: original MIPS .pdata 4097ecb4..4097ed8b. Semantic name remains unreviewed. */

void glGenBuffers(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  code *pcVar3;
  
                    /* 0x1ecb4  66  glGenBuffers */
  if (DAT_40996364 != 0) {
    if (*(int *)(DAT_40996364 + 8) == 0) {
      iVar1 = *(int *)(DAT_40996364 + 0xc);
    }
    else {
      iVar1 = mali_sys_thread_key_get_data(4);
    }
    if (iVar1 != 0) {
      pcVar3 = *(code **)(*(int *)(iVar1 + 8) + 0x3b4);
      if (pcVar3 != (code *)0x0) {
        (*pcVar3)(iVar1);
      }
      mali_sys_mutex_lock(*(undefined4 *)(*(int *)(iVar1 + 0x4e8) + 0x1c));
      iVar2 = (**(code **)(*(int *)(iVar1 + 8) + 0x70))
                        (*(undefined4 *)(*(int *)(iVar1 + 0x4e8) + 8),param_1,param_2,4);
      mali_sys_mutex_unlock(*(undefined4 *)(*(int *)(iVar1 + 0x4e8) + 0x1c));
      if (iVar2 != 0) {
        (**(code **)(*(int *)(iVar1 + 8) + 0x3b8))(iVar1,iVar2);
      }
    }
  }
  return;
}



/* 4097ed8c glFlush */

/* Boundary evidence: original MIPS .pdata 4097ed8c..4097ee47. Semantic name remains unreviewed. */

void glFlush(void)

{
  int iVar1;
  int iVar2;
  code *pcVar3;
  
                    /* 0x1ed8c  58  glFlush */
  if (DAT_40996364 != 0) {
    if (*(int *)(DAT_40996364 + 8) == 0) {
      iVar1 = *(int *)(DAT_40996364 + 0xc);
    }
    else {
      iVar1 = mali_sys_thread_key_get_data(4);
    }
    if (iVar1 != 0) {
      pcVar3 = *(code **)(*(int *)(iVar1 + 8) + 0x3b4);
      if (pcVar3 != (code *)0x0) {
        (*pcVar3)(iVar1);
      }
      mali_sys_mutex_lock(*(undefined4 *)(*(int *)(iVar1 + 0x4e8) + 0x1c));
      iVar2 = (**(code **)(*(int *)(iVar1 + 8) + 0x68))(iVar1);
      mali_sys_mutex_unlock(*(undefined4 *)(*(int *)(iVar1 + 0x4e8) + 0x1c));
      if (iVar2 != 0) {
        (**(code **)(*(int *)(iVar1 + 8) + 0x3b8))(iVar1,iVar2);
      }
    }
  }
  return;
}



/* 4097ee48 glFinish */

/* Boundary evidence: original MIPS .pdata 4097ee48..4097ef03. Semantic name remains unreviewed. */

void glFinish(void)

{
  int iVar1;
  int iVar2;
  code *pcVar3;
  
                    /* 0x1ee48  57  glFinish */
  if (DAT_40996364 != 0) {
    if (*(int *)(DAT_40996364 + 8) == 0) {
      iVar1 = *(int *)(DAT_40996364 + 0xc);
    }
    else {
      iVar1 = mali_sys_thread_key_get_data(4);
    }
    if (iVar1 != 0) {
      pcVar3 = *(code **)(*(int *)(iVar1 + 8) + 0x3b4);
      if (pcVar3 != (code *)0x0) {
        (*pcVar3)(iVar1);
      }
      mali_sys_mutex_lock(*(undefined4 *)(*(int *)(iVar1 + 0x4e8) + 0x1c));
      iVar2 = (**(code **)(*(int *)(iVar1 + 8) + 100))(iVar1);
      mali_sys_mutex_unlock(*(undefined4 *)(*(int *)(iVar1 + 0x4e8) + 0x1c));
      if (iVar2 != 0) {
        (**(code **)(*(int *)(iVar1 + 8) + 0x3b8))(iVar1,iVar2);
      }
    }
  }
  return;
}



/* 4097ef04 glDrawElements */

/* Boundary evidence: original MIPS .pdata 4097ef04..4097efd7. Semantic name remains unreviewed. */

void glDrawElements(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  
                    /* 0x1ef04  52  glDrawElements */
  if (DAT_40996364 != 0) {
    if (*(int *)(DAT_40996364 + 8) == 0) {
      iVar1 = *(int *)(DAT_40996364 + 0xc);
    }
    else {
      iVar1 = mali_sys_thread_key_get_data(4);
    }
    if (iVar1 != 0) {
      mali_sys_mutex_lock(*(undefined4 *)(*(int *)(iVar1 + 0x4e8) + 0x1c));
      iVar2 = (**(code **)(*(int *)(iVar1 + 8) + 0x5c))(iVar1,param_1,param_2,param_3,param_4);
      if (iVar2 != 0) {
        (**(code **)(*(int *)(iVar1 + 8) + 0x3b8))(iVar1,iVar2);
      }
      mali_sys_mutex_unlock(*(undefined4 *)(*(int *)(iVar1 + 0x4e8) + 0x1c));
    }
  }
  return;
}



/* 4097efd8 glDrawArrays */

/* Boundary evidence: original MIPS .pdata 4097efd8..4097f09b. Semantic name remains unreviewed. */

void glDrawArrays(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  
                    /* 0x1efd8  51  glDrawArrays */
  if (DAT_40996364 != 0) {
    if (*(int *)(DAT_40996364 + 8) == 0) {
      iVar1 = *(int *)(DAT_40996364 + 0xc);
    }
    else {
      iVar1 = mali_sys_thread_key_get_data(4);
    }
    if (iVar1 != 0) {
      mali_sys_mutex_lock(*(undefined4 *)(*(int *)(iVar1 + 0x4e8) + 0x1c));
      iVar2 = (**(code **)(*(int *)(iVar1 + 8) + 0x58))(iVar1,param_1,param_2,param_3);
      if (iVar2 != 0) {
        (**(code **)(*(int *)(iVar1 + 8) + 0x3b8))(iVar1,iVar2);
      }
      mali_sys_mutex_unlock(*(undefined4 *)(*(int *)(iVar1 + 0x4e8) + 0x1c));
    }
  }
  return;
}



/* 4097f09c glDeleteTextures */

/* Boundary evidence: original MIPS .pdata 4097f09c..4097f16b. Semantic name remains unreviewed. */

void glDeleteTextures(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  code *pcVar3;
  
                    /* 0x1f09c  44  glDeleteTextures */
  if (DAT_40996364 != 0) {
    if (*(int *)(DAT_40996364 + 8) == 0) {
      iVar1 = *(int *)(DAT_40996364 + 0xc);
    }
    else {
      iVar1 = mali_sys_thread_key_get_data(4);
    }
    if (iVar1 != 0) {
      pcVar3 = *(code **)(*(int *)(iVar1 + 8) + 0x3b4);
      if (pcVar3 != (code *)0x0) {
        (*pcVar3)(iVar1);
      }
      mali_sys_mutex_lock(*(undefined4 *)(*(int *)(iVar1 + 0x4e8) + 0x1c));
      iVar2 = (**(code **)(*(int *)(iVar1 + 8) + 0x44))(iVar1,param_1,param_2);
      mali_sys_mutex_unlock(*(undefined4 *)(*(int *)(iVar1 + 0x4e8) + 0x1c));
      if (iVar2 != 0) {
        (**(code **)(*(int *)(iVar1 + 8) + 0x3b8))(iVar1,iVar2);
      }
    }
  }
  return;
}



/* 4097f16c glDeleteBuffers */

/* Boundary evidence: original MIPS .pdata 4097f16c..4097f243. Semantic name remains unreviewed. */

void glDeleteBuffers(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  code *pcVar3;
  
                    /* 0x1f16c  43  glDeleteBuffers */
  if (DAT_40996364 != 0) {
    if (*(int *)(DAT_40996364 + 8) == 0) {
      iVar1 = *(int *)(DAT_40996364 + 0xc);
    }
    else {
      iVar1 = mali_sys_thread_key_get_data(4);
    }
    if (iVar1 != 0) {
      pcVar3 = *(code **)(*(int *)(iVar1 + 8) + 0x3b4);
      if (pcVar3 != (code *)0x0) {
        (*pcVar3)(iVar1);
      }
      mali_sys_mutex_lock(*(undefined4 *)(*(int *)(iVar1 + 0x4e8) + 0x1c));
      iVar2 = (**(code **)(*(int *)(iVar1 + 8) + 0x40))
                        (*(undefined4 *)(*(int *)(iVar1 + 0x4e8) + 8),iVar1 + 0x14,param_1,param_2);
      mali_sys_mutex_unlock(*(undefined4 *)(*(int *)(iVar1 + 0x4e8) + 0x1c));
      if (iVar2 != 0) {
        (**(code **)(*(int *)(iVar1 + 8) + 0x3b8))(iVar1,iVar2);
      }
    }
  }
  return;
}



/* 4097f244 glCopyTexSubImage2D */

/* Boundary evidence: original MIPS .pdata 4097f244..4097f353. Semantic name remains unreviewed. */

void glCopyTexSubImage2D(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4
                        ,undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8
                        )

{
  int iVar1;
  int iVar2;
  code *pcVar3;
  
                    /* 0x1f244  40  glCopyTexSubImage2D */
  if (DAT_40996364 != 0) {
    if (*(int *)(DAT_40996364 + 8) == 0) {
      iVar1 = *(int *)(DAT_40996364 + 0xc);
    }
    else {
      iVar1 = mali_sys_thread_key_get_data(4);
    }
    if (iVar1 != 0) {
      pcVar3 = *(code **)(*(int *)(iVar1 + 8) + 0x3b4);
      if (pcVar3 != (code *)0x0) {
        (*pcVar3)(iVar1);
      }
      mali_sys_mutex_lock(*(undefined4 *)(*(int *)(iVar1 + 0x4e8) + 0x1c));
      iVar2 = (**(code **)(*(int *)(iVar1 + 8) + 0x38))
                        (iVar1,param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8);
      mali_sys_mutex_unlock(*(undefined4 *)(*(int *)(iVar1 + 0x4e8) + 0x1c));
      if (iVar2 != 0) {
        (**(code **)(*(int *)(iVar1 + 8) + 0x3b8))(iVar1,iVar2);
      }
    }
  }
  return;
}



/* 4097f354 glCopyTexImage2D */

/* Boundary evidence: original MIPS .pdata 4097f354..4097f463. Semantic name remains unreviewed. */

void glCopyTexImage2D(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                     undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8)

{
  int iVar1;
  int iVar2;
  code *pcVar3;
  
                    /* 0x1f354  39  glCopyTexImage2D */
  if (DAT_40996364 != 0) {
    if (*(int *)(DAT_40996364 + 8) == 0) {
      iVar1 = *(int *)(DAT_40996364 + 0xc);
    }
    else {
      iVar1 = mali_sys_thread_key_get_data(4);
    }
    if (iVar1 != 0) {
      pcVar3 = *(code **)(*(int *)(iVar1 + 8) + 0x3b4);
      if (pcVar3 != (code *)0x0) {
        (*pcVar3)(iVar1);
      }
      mali_sys_mutex_lock(*(undefined4 *)(*(int *)(iVar1 + 0x4e8) + 0x1c));
      iVar2 = (**(code **)(*(int *)(iVar1 + 8) + 0x34))
                        (iVar1,param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8);
      mali_sys_mutex_unlock(*(undefined4 *)(*(int *)(iVar1 + 0x4e8) + 0x1c));
      if (iVar2 != 0) {
        (**(code **)(*(int *)(iVar1 + 8) + 0x3b8))(iVar1,iVar2);
      }
    }
  }
  return;
}



/* 4097f464 glCompressedTexSubImage2D */

/* Boundary evidence: original MIPS .pdata 4097f464..4097f57b. Semantic name remains unreviewed. */

void glCompressedTexSubImage2D
               (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
               undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
               undefined4 param_9)

{
  int iVar1;
  int iVar2;
  code *pcVar3;
  
                    /* 0x1f464  38  glCompressedTexSubImage2D */
  if (DAT_40996364 != 0) {
    if (*(int *)(DAT_40996364 + 8) == 0) {
      iVar1 = *(int *)(DAT_40996364 + 0xc);
    }
    else {
      iVar1 = mali_sys_thread_key_get_data(4);
    }
    if (iVar1 != 0) {
      pcVar3 = *(code **)(*(int *)(iVar1 + 8) + 0x3b4);
      if (pcVar3 != (code *)0x0) {
        (*pcVar3)(iVar1);
      }
      mali_sys_mutex_lock(*(undefined4 *)(*(int *)(iVar1 + 0x4e8) + 0x1c));
      iVar2 = (**(code **)(*(int *)(iVar1 + 8) + 0x30))
                        (iVar1,param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,
                         param_9);
      mali_sys_mutex_unlock(*(undefined4 *)(*(int *)(iVar1 + 0x4e8) + 0x1c));
      if (iVar2 != 0) {
        (**(code **)(*(int *)(iVar1 + 8) + 0x3b8))(iVar1,iVar2);
      }
    }
  }
  return;
}



/* 4097f57c glCompressedTexImage2D */

/* Boundary evidence: original MIPS .pdata 4097f57c..4097f68b. Semantic name remains unreviewed. */

void glCompressedTexImage2D
               (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
               undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8)

{
  int iVar1;
  int iVar2;
  code *pcVar3;
  
                    /* 0x1f57c  37  glCompressedTexImage2D */
  if (DAT_40996364 != 0) {
    if (*(int *)(DAT_40996364 + 8) == 0) {
      iVar1 = *(int *)(DAT_40996364 + 0xc);
    }
    else {
      iVar1 = mali_sys_thread_key_get_data(4);
    }
    if (iVar1 != 0) {
      pcVar3 = *(code **)(*(int *)(iVar1 + 8) + 0x3b4);
      if (pcVar3 != (code *)0x0) {
        (*pcVar3)(iVar1);
      }
      mali_sys_mutex_lock(*(undefined4 *)(*(int *)(iVar1 + 0x4e8) + 0x1c));
      iVar2 = (**(code **)(*(int *)(iVar1 + 8) + 0x2c))
                        (iVar1,param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8);
      mali_sys_mutex_unlock(*(undefined4 *)(*(int *)(iVar1 + 0x4e8) + 0x1c));
      if (iVar2 != 0) {
        (**(code **)(*(int *)(iVar1 + 8) + 0x3b8))(iVar1,iVar2);
      }
    }
  }
  return;
}



/* 4097f68c glClear */

/* Boundary evidence: original MIPS .pdata 4097f68c..4097f74b. Semantic name remains unreviewed. */

void glClear(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  code *pcVar3;
  
                    /* 0x1f68c  23  glClear */
  if (DAT_40996364 != 0) {
    if (*(int *)(DAT_40996364 + 8) == 0) {
      iVar1 = *(int *)(DAT_40996364 + 0xc);
    }
    else {
      iVar1 = mali_sys_thread_key_get_data(4);
    }
    if (iVar1 != 0) {
      pcVar3 = *(code **)(*(int *)(iVar1 + 8) + 0x3b4);
      if (pcVar3 != (code *)0x0) {
        (*pcVar3)(iVar1);
      }
      mali_sys_mutex_lock(*(undefined4 *)(*(int *)(iVar1 + 0x4e8) + 0x1c));
      iVar2 = (**(code **)(*(int *)(iVar1 + 8) + 0x18))(iVar1,param_1);
      mali_sys_mutex_unlock(*(undefined4 *)(*(int *)(iVar1 + 0x4e8) + 0x1c));
      if (iVar2 != 0) {
        (**(code **)(*(int *)(iVar1 + 8) + 0x3b8))(iVar1,iVar2);
      }
    }
  }
  return;
}



/* 4097f74c glBufferSubData */

/* Boundary evidence: original MIPS .pdata 4097f74c..4097f83f. Semantic name remains unreviewed. */

void glBufferSubData(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 *puVar1;
  int iVar2;
  
                    /* 0x1f74c  22  glBufferSubData */
  if (DAT_40996364 != 0) {
    if (*(int *)(DAT_40996364 + 8) == 0) {
      puVar1 = *(undefined4 **)(DAT_40996364 + 0xc);
    }
    else {
      puVar1 = (undefined4 *)mali_sys_thread_key_get_data(4);
    }
    if (puVar1 != (undefined4 *)0x0) {
      if (*(code **)(puVar1[2] + 0x3b4) != (code *)0x0) {
        (**(code **)(puVar1[2] + 0x3b4))(puVar1);
      }
      mali_sys_mutex_lock(*(undefined4 *)(puVar1[0x13a] + 0x1c));
      iVar2 = (**(code **)(puVar1[2] + 0x14))(*puVar1,puVar1 + 5,param_1,param_2,param_3,param_4);
      mali_sys_mutex_unlock(*(undefined4 *)(puVar1[0x13a] + 0x1c));
      if (iVar2 != 0) {
        (**(code **)(puVar1[2] + 0x3b8))(puVar1,iVar2);
      }
    }
  }
  return;
}



/* 4097f840 glBufferData */

/* Boundary evidence: original MIPS .pdata 4097f840..4097f937. Semantic name remains unreviewed. */

void glBufferData(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 *puVar1;
  int iVar2;
  
                    /* 0x1f840  21  glBufferData */
  if (DAT_40996364 != 0) {
    if (*(int *)(DAT_40996364 + 8) == 0) {
      puVar1 = *(undefined4 **)(DAT_40996364 + 0xc);
    }
    else {
      puVar1 = (undefined4 *)mali_sys_thread_key_get_data(4);
    }
    if (puVar1 != (undefined4 *)0x0) {
      if (*(code **)(puVar1[2] + 0x3b4) != (code *)0x0) {
        (**(code **)(puVar1[2] + 0x3b4))(puVar1);
      }
      mali_sys_mutex_lock(*(undefined4 *)(puVar1[0x13a] + 0x1c));
      iVar2 = (**(code **)(puVar1[2] + 0x10))
                        (*puVar1,puVar1 + 5,puVar1[1],param_1,param_2,param_3,param_4);
      mali_sys_mutex_unlock(*(undefined4 *)(puVar1[0x13a] + 0x1c));
      if (iVar2 != 0) {
        (**(code **)(puVar1[2] + 0x3b8))(puVar1,iVar2);
      }
    }
  }
  return;
}



/* 4097f938 glBindTexture */

/* Boundary evidence: original MIPS .pdata 4097f938..4097f9ef. Semantic name remains unreviewed. */

void glBindTexture(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  
                    /* 0x1f938  19  glBindTexture */
  if (DAT_40996364 != 0) {
    if (*(int *)(DAT_40996364 + 8) == 0) {
      iVar1 = *(int *)(DAT_40996364 + 0xc);
    }
    else {
      iVar1 = mali_sys_thread_key_get_data(4);
    }
    if (iVar1 != 0) {
      mali_sys_mutex_lock(*(undefined4 *)(*(int *)(iVar1 + 0x4e8) + 0x1c));
      iVar2 = (**(code **)(*(int *)(iVar1 + 8) + 8))(iVar1,param_1,param_2);
      mali_sys_mutex_unlock(*(undefined4 *)(*(int *)(iVar1 + 0x4e8) + 0x1c));
      if (iVar2 != 0) {
        (**(code **)(*(int *)(iVar1 + 8) + 0x3b8))(iVar1,iVar2);
      }
    }
  }
  return;
}



/* 4097f9f0 glBindBuffer */

/* Boundary evidence: original MIPS .pdata 4097f9f0..4097fac7. Semantic name remains unreviewed. */

void glBindBuffer(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  code *pcVar3;
  
                    /* 0x1f9f0  18  glBindBuffer */
  if (DAT_40996364 != 0) {
    if (*(int *)(DAT_40996364 + 8) == 0) {
      iVar1 = *(int *)(DAT_40996364 + 0xc);
    }
    else {
      iVar1 = mali_sys_thread_key_get_data(4);
    }
    if (iVar1 != 0) {
      pcVar3 = *(code **)(*(int *)(iVar1 + 8) + 0x3b4);
      if (pcVar3 != (code *)0x0) {
        (*pcVar3)(iVar1);
      }
      mali_sys_mutex_lock(*(undefined4 *)(*(int *)(iVar1 + 0x4e8) + 0x1c));
      iVar2 = (**(code **)(*(int *)(iVar1 + 8) + 4))
                        (*(undefined4 *)(*(int *)(iVar1 + 0x4e8) + 8),iVar1 + 0x14,param_1,param_2);
      mali_sys_mutex_unlock(*(undefined4 *)(*(int *)(iVar1 + 0x4e8) + 0x1c));
      if (iVar2 != 0) {
        (**(code **)(*(int *)(iVar1 + 8) + 0x3b8))(iVar1,iVar2);
      }
    }
  }
  return;
}



/* 4097fac8 glActiveTexture */

/* Boundary evidence: original MIPS .pdata 4097fac8..4097fb87. Semantic name remains unreviewed. */

void glActiveTexture(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  code *pcVar3;
  
                    /* 0x1fac8  15  glActiveTexture */
  if (DAT_40996364 != 0) {
    if (*(int *)(DAT_40996364 + 8) == 0) {
      iVar1 = *(int *)(DAT_40996364 + 0xc);
    }
    else {
      iVar1 = mali_sys_thread_key_get_data(4);
    }
    if (iVar1 != 0) {
      pcVar3 = *(code **)(*(int *)(iVar1 + 8) + 0x3b4);
      if (pcVar3 != (code *)0x0) {
        (*pcVar3)(iVar1);
      }
      mali_sys_mutex_lock(*(undefined4 *)(*(int *)(iVar1 + 0x4e8) + 0x1c));
      iVar2 = (*(code *)**(undefined4 **)(iVar1 + 8))(iVar1,param_1);
      mali_sys_mutex_unlock(*(undefined4 *)(*(int *)(iVar1 + 0x4e8) + 0x1c));
      if (iVar2 != 0) {
        (**(code **)(*(int *)(iVar1 + 8) + 0x3b8))(iVar1,iVar2);
      }
    }
  }
  return;
}



/* 4097fb90 FUN_4097fb90 */

/* Boundary evidence: original MIPS .pdata 4097fb90..4097fbbf. Semantic name remains unreviewed. */

bool FUN_4097fb90(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = mali_sys_memcmp(param_1,param_2,0x60);
  return iVar1 == 0;
}



/* 4097fbc0 FUN_4097fbc0 */

/* Boundary evidence: original MIPS .pdata 4097fbc0..4097fbdf. Semantic name remains unreviewed. */

void FUN_4097fbc0(undefined4 param_1)

{
  mali_sys_memset(param_1,0,0x98);
  return;
}



/* 4097fbe0 FUN_4097fbe0 */

/* Boundary evidence: original MIPS .pdata 4097fbe0..4097fc2f. Semantic name remains unreviewed. */

void FUN_4097fbe0(undefined4 param_1,undefined4 *param_2)

{
  if ((undefined4 *)*param_2 != (undefined4 *)0x0) {
    FUN_409794cc((undefined4 *)*param_2);
    *param_2 = 0;
  }
  if ((undefined4 *)param_2[1] != (undefined4 *)0x0) {
    FUN_409794cc((undefined4 *)param_2[1]);
    param_2[1] = 0;
  }
  return;
}



/* 4097fca0 FUN_4097fca0 */

undefined4 FUN_4097fca0(uint param_1,int param_2,int *param_3,undefined4 *param_4)

{
  undefined4 uVar1;
  
  if (param_2 < 0x101) {
    if (param_1 == 3) {
      *param_3 = param_2 * 2 + -2;
      *param_4 = 1;
      return 1;
    }
    if (param_1 == 4) {
      *param_3 = param_2;
    }
    else {
      if ((param_1 < 5) || (6 < param_1)) goto LAB_4097fcac;
      *param_3 = (param_2 + -2) * 3;
    }
    *param_4 = 4;
    uVar1 = 1;
  }
  else {
LAB_4097fcac:
    uVar1 = 0;
  }
  return uVar1;
}



/* 4097fd20 FUN_4097fd20 */

undefined4 FUN_4097fd20(char *param_1)

{
  int iVar1;
  
  if (*param_1 != '\0') {
    if ((*(int *)(param_1 + 0x1c) != 0) || (*(int *)(param_1 + 0x14) == 0)) {
      return 0;
    }
    iVar1 = *(int *)(param_1 + 0xc);
    if (((iVar1 != 0x1406) && (iVar1 != 0x140c)) && (iVar1 != 0x1402)) {
      return 0;
    }
  }
  return 1;
}



/* 4097fde4 FUN_4097fde4 */

/* Boundary evidence: original MIPS .pdata 4097fde4..4097ffc3. Semantic name remains unreviewed. */

void FUN_4097fde4(undefined4 *param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  int *piVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uStack00000010;
  
  FUN_40993300();
  uVar4 = param_1[200];
  uVar7 = param_1[0xc5];
  uVar8 = param_1[199];
  uVar9 = param_1[0xc6];
  uStack00000010 = uVar4;
  puVar1 = FUN_40979904();
  *param_2 = puVar1;
  if (puVar1 != (undefined4 *)0x0) {
    param_1[0xc5] = 0xffffffff;
    param_1[199] = puVar1;
    param_2[0x21] = 0;
    param_2[0x20] = 0;
    param_2[0x23] = 0x20000;
    param_2[0x22] = 0x20000;
    param_2[0x25] = 0x30000;
    param_2[0x24] = 0x30000;
    uVar6 = *param_1;
    piVar5 = (int *)param_1[199];
    if ((piVar5 != (int *)0x0) && (param_1[0xc5] != 0)) {
      puVar1 = (undefined4 *)*piVar5;
      piVar2 = (int *)mali_sys_malloc(0x1408);
      if (piVar2 == (int *)0x0) {
        iVar3 = 0;
      }
      else {
        iVar3 = FUN_409690fc(uVar6,0x38000,0,piVar2);
      }
      *piVar5 = iVar3;
      if (iVar3 == 0) {
        *piVar5 = (int)puVar1;
        uVar4 = uStack00000010;
      }
      else {
        if (puVar1 != (undefined4 *)0x0) {
          mali_mem_ref_deref(*puVar1);
          *puVar1 = 0;
          mali_sys_free(puVar1);
        }
        piVar5[2] = 0x88e4;
        piVar5[1] = 0x38000;
        puVar1 = FUN_40979904();
        param_2[1] = puVar1;
        uVar4 = uStack00000010;
        if (puVar1 != (undefined4 *)0x0) {
          param_1[0xc6] = 0xffffffff;
          param_1[200] = puVar1;
          param_2[5] = 0;
          param_2[4] = 0;
          uVar4 = *param_1;
          piVar5 = (int *)param_1[200];
          if ((piVar5 != (int *)0x0) && (param_1[0xc6] != 0)) {
            puVar1 = (undefined4 *)*piVar5;
            piVar2 = (int *)mali_sys_malloc(0x1408);
            if (piVar2 == (int *)0x0) {
              iVar3 = 0;
            }
            else {
              iVar3 = FUN_409690fc(uVar4,0x8000,0,piVar2);
            }
            *piVar5 = iVar3;
            if (iVar3 != 0) {
              if (puVar1 != (undefined4 *)0x0) {
                mali_mem_ref_deref(*puVar1);
                *puVar1 = 0;
                mali_sys_free(puVar1);
              }
              piVar5[2] = 0x88e4;
              piVar5[1] = 0x8000;
              param_1[0xc5] = uVar7;
              param_1[199] = uVar8;
              param_1[0xc6] = uVar9;
              param_1[200] = uStack00000010;
              goto LAB_4097ff70;
            }
            *piVar5 = (int)puVar1;
          }
          FUN_409794cc((undefined4 *)param_2[1]);
          uVar4 = uStack00000010;
        }
      }
    }
    FUN_409794cc((undefined4 *)*param_2);
  }
  param_1[0xc5] = uVar7;
  param_1[199] = uVar8;
  param_1[0xc6] = uVar9;
  param_1[200] = uVar4;
  param_2[1] = 0;
  *param_2 = 0;
LAB_4097ff70:
                    /* WARNING: Subroutine does not return */
  FUN_40993338(0x18);
}



/* 4097ffc4 FUN_4097ffc4 */

/* Boundary evidence: original MIPS .pdata 4097ffc4..40980073. Semantic name remains unreviewed. */

void FUN_4097ffc4(uint *param_1,uint *param_2)

{
  param_1[0xc3] = *param_2;
  param_1[0xc5] = param_2[1];
  memcpy(param_1 + 2,param_2 + 2,0x30);
  memcpy(param_1 + 0x4a,param_2 + 0xe,0x30);
  memcpy(param_1 + 0x1a,param_2 + 0x1a,0x30);
  if (param_2[0x36] == 1) {
    *param_1 = *param_1 | 0x100000;
  }
  mali_sys_memcpy(*(int *)(param_1[0x133] + 0x55ac) * 0x40 + param_1[0x133] + 0x5c,param_2 + 0x26,
                  0x40);
  return;
}



/* 40980074 FUN_40980074 */

/* Boundary evidence: original MIPS .pdata 40980074..40980127. Semantic name remains unreviewed. */

void FUN_40980074(uint *param_1,uint *param_2)

{
  *param_2 = param_1[0xc3];
  param_2[1] = param_1[0xc5];
  memcpy(param_2 + 2,param_1 + 2,0x30);
  memcpy(param_2 + 0xe,param_1 + 0x4a,0x30);
  memcpy(param_2 + 0x1a,param_1 + 0x1a,0x30);
  if ((*param_1 & 0x100000) == 0) {
    param_2[0x36] = 0;
  }
  else {
    param_2[0x36] = 1;
  }
  mali_sys_memcpy(param_2 + 0x26,*(int *)(param_1[0x133] + 0x55ac) * 0x40 + param_1[0x133] + 0x5c,
                  0x40);
  return;
}



/* 40980128 FUN_40980128 */

/* Boundary evidence: original MIPS .pdata 40980128..409801d3. Semantic name remains unreviewed. */

void FUN_40980128(undefined4 param_1,undefined4 *param_2,int param_3,uint param_4)

{
  FUN_40973074((int *)*param_2,param_3,param_2[0x21],param_4);
  if (param_2[0xb] != 0) {
    FUN_40973074((int *)*param_2,param_3,param_2[0x23],param_4);
  }
  if (param_2[0xd] != 0) {
    FUN_40973074((int *)*param_2,param_3,param_2[0x25],param_4);
  }
  return;
}



/* 409801d4 FUN_409801d4 */

/* Boundary evidence: original MIPS .pdata 409801d4..4098025f. Semantic name remains unreviewed. */

void FUN_409801d4(int param_1,int param_2,uint param_3,undefined4 param_4,undefined4 param_5)

{
  int iVar1;
  
  *(uint *)(param_1 + 0x80) = param_3;
  *(undefined4 *)(param_1 + 0x8c) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x90) = param_5;
  *(int *)(param_1 + 0x78) = param_2;
  *(undefined1 *)(param_1 + 0x84) = 1;
  iVar1 = FUN_409769fc(param_3);
  *(int *)(param_1 + 0x7c) = iVar1 * param_2;
  *(undefined4 *)(param_1 + 0x88) = param_4;
  FUN_40969410(*(int *)(param_1 + 0x4fc),param_1 + 0x14,2);
  *(undefined1 *)(param_1 + 0x74) = 1;
  return;
}



/* 40980260 FUN_40980260 */

/* Boundary evidence: original MIPS .pdata 40980260..409802cb. Semantic name remains unreviewed. */

void FUN_40980260(int param_1,int param_2,uint param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 in_stack_00000030;
  
  FUN_40993370();
  *(uint *)(param_1 + 0x140) = param_3;
  *(undefined4 *)(param_1 + 0x14c) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x150) = in_stack_00000030;
  *(int *)(param_1 + 0x138) = param_2;
  *(undefined1 *)(param_1 + 0x144) = 0;
  iVar1 = FUN_409769fc(param_3);
  *(int *)(param_1 + 0x13c) = iVar1 * param_2;
  *(undefined4 *)(param_1 + 0x148) = param_4;
  FUN_40969410(*(int *)(param_1 + 0x4fc),param_1 + 0x14,6);
  *(undefined1 *)(param_1 + 0x134) = 1;
                    /* WARNING: Subroutine does not return */
  FUN_40993390(0x10);
}



/* 409802cc FUN_409802cc */

/* Boundary evidence: original MIPS .pdata 409802cc..4098035b. Semantic name remains unreviewed. */

void FUN_409802cc(int param_1,int param_2,uint param_3,undefined4 param_4,undefined4 param_5)

{
  int iVar1;
  
  *(undefined4 *)(param_1 + 0x2c) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x30) = param_5;
  *(int *)(param_1 + 0x18) = param_2;
  *(uint *)(param_1 + 0x20) = param_3;
  *(undefined1 *)(param_1 + 0x24) = 0;
  iVar1 = FUN_409769fc(param_3);
  *(int *)(param_1 + 0x1c) = iVar1 * param_2;
  *(undefined4 *)(param_1 + 0x28) = param_4;
  FUN_40969410(*(int *)(param_1 + 0x4fc),param_1 + 0x14,0);
  *(undefined1 *)(param_1 + 0x14) = 1;
  return;
}



/* 4098035c FUN_4098035c */

/* Boundary evidence: original MIPS .pdata 4098035c..4098042f. Semantic name remains unreviewed. */

void FUN_4098035c(int param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4)

{
  mali_sys_memset(param_2,0,0x60);
  *param_2 = *(undefined4 *)(param_1 + 0x14);
  param_2[1] = *(undefined4 *)(param_1 + 0xc);
  if ((*(char *)(param_1 + 0x128) != '\0') && (*(char *)(param_1 + 800) != '\0')) {
    param_2[2] = *(undefined4 *)(param_1 + 0x134);
    param_2[3] = *(undefined4 *)(param_1 + 300);
  }
  if (*(char *)(param_1 + 0x68) != '\0') {
    param_2[4] = *(undefined4 *)(param_1 + 0x74);
    param_2[5] = *(undefined4 *)(param_1 + 0x6c);
  }
  mali_sys_memcpy(param_2 + 8,
                  *(int *)(*(int *)(param_1 + 0x4cc) + 0x55ac) * 0x40 + *(int *)(param_1 + 0x4cc) +
                  0x5c,0x40);
  param_2[6] = param_4;
  param_2[7] = param_3;
  return;
}



/* 40980430 FUN_40980430 */

/* Boundary evidence: original MIPS .pdata 40980430..40980503. Semantic name remains unreviewed. */

void FUN_40980430(int param_1)

{
  int iVar1;
  char *pcVar2;
  uint uVar3;
  
  FUN_40993370();
  if (((((*(char *)(param_1 + 0x38) == '\0') && (*(char *)(param_1 + 0x98) == '\0')) &&
       (*(char *)(param_1 + 200) == '\0')) &&
      ((*(char *)(param_1 + 0xf8) == '\0' && (*(int *)(param_1 + 0x314) == 0)))) &&
     ((*(char *)(param_1 + 8) != '\0' && (iVar1 = FUN_4097fd20((char *)(param_1 + 8)), iVar1 != 0)))
     ) {
    uVar3 = 1;
    pcVar2 = (char *)(param_1 + 0x334);
    do {
      if (*pcVar2 != '\0') goto LAB_409804f8;
      uVar3 = uVar3 + 1;
      prefetch(pcVar2 + 0x28,0);
      pcVar2 = pcVar2 + 0x14;
    } while (uVar3 < 8);
    if ((*(char *)(param_1 + 800) == '\0') ||
       (iVar1 = FUN_4097fd20((char *)(param_1 + 0x128)), iVar1 != 0)) {
      FUN_4097fd20((char *)(param_1 + 0x68));
    }
  }
LAB_409804f8:
                    /* WARNING: Subroutine does not return */
  FUN_40993390(0x10);
}



/* 40980504 FUN_40980504 */

/* Boundary evidence: original MIPS .pdata 40980504..409806d3. Semantic name remains unreviewed. */

void FUN_40980504(undefined4 *param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint auStack_f8 [56];
  
  iVar3 = param_1[0x136];
  if (*(int *)(iVar3 + 0x65a0) != 0) {
    FUN_40980074(param_1 + 3,auStack_f8);
    uVar2 = *(undefined4 *)(iVar3 + 0x659c);
    param_1[0xc6] = 0xffffffff;
    param_1[200] = uVar2;
    FUN_409802cc((int)param_1,*(int *)(iVar3 + 0x65bc),*(uint *)(iVar3 + 0x65b8),
                 *(undefined4 *)(iVar3 + 0x6618),*(undefined4 *)(iVar3 + 0x6598));
    if (*(int *)(iVar3 + 0x65c4) == 0) {
      *(undefined1 *)(param_1 + 0x4d) = 0;
    }
    else {
      FUN_40980260((int)param_1,*(int *)(iVar3 + 0x65c4),*(uint *)(iVar3 + 0x65c0),
                   *(undefined4 *)(iVar3 + 0x6620));
    }
    if (*(int *)(iVar3 + 0x65cc) == 0) {
      *(undefined1 *)(param_1 + 0x1d) = 0;
    }
    else {
      FUN_409801d4((int)param_1,*(int *)(iVar3 + 0x65cc),*(uint *)(iVar3 + 0x65c8),
                   *(undefined4 *)(iVar3 + 0x6628),*(undefined4 *)(iVar3 + 0x6598));
    }
    mali_sys_memcpy(*(int *)(param_1[0x136] + 0x55ac) * 0x40 + param_1[0x136] + 0x5c,iVar3 + 0x65d8,
                    0x40);
    iVar1 = FUN_4098d2d8(param_1,*(uint *)(iVar3 + 0x65d4),*(uint *)(iVar3 + 0x65a4),
                         *(uint *)(iVar3 + 0x65d0),*(undefined4 *)(iVar3 + 0x65a8),0,
                         *(int *)(iVar3 + 0x65a0) + -1);
    FUN_4097ffc4(param_1 + 3,auStack_f8);
    *(int *)(iVar3 + 0x65b4) = *(int *)(iVar3 + 0x65b4) + 1;
    *(undefined4 *)(iVar3 + 0x65a0) = 0;
    *(undefined4 *)(iVar3 + 0x65a4) = 0;
    uVar7 = *(int *)(iVar3 + 0x661c) + 3U & 0xfffffffc;
    uVar6 = *(int *)(iVar3 + 0x6624) + 3U & 0xfffffffc;
    *(uint *)(iVar3 + 0x661c) = uVar7;
    *(uint *)(iVar3 + 0x6624) = uVar6;
    uVar5 = *(int *)(iVar3 + 0x662c) + 3U & 0xfffffffc;
    uVar4 = *(int *)(iVar3 + 0x65ac) + 3U & 0xfffffffc;
    *(uint *)(iVar3 + 0x662c) = uVar5;
    *(uint *)(iVar3 + 0x65ac) = uVar4;
    *(uint *)(iVar3 + 0x6618) = uVar7;
    *(uint *)(iVar3 + 0x6620) = uVar6;
    *(uint *)(iVar3 + 0x6628) = uVar5;
    *(uint *)(iVar3 + 0x65a8) = uVar4;
    if (iVar1 != 0) {
      FUN_40980e38((int)param_1,iVar1);
    }
  }
  return;
}



/* 409806d4 FUN_409806d4 */

/* Boundary evidence: original MIPS .pdata 409806d4..4098071f. Semantic name remains unreviewed. */

void FUN_409806d4(undefined4 *param_1)

{
  int iVar1;
  
  iVar1 = param_1[0x136];
  if (iVar1 != 0) {
    FUN_40980504(param_1);
    FUN_4097fbe0(param_1,(undefined4 *)(iVar1 + 0x6598));
  }
  return;
}



/* 40980720 FUN_40980720 */

/* Boundary evidence: original MIPS .pdata 40980720..4098096b. Semantic name remains unreviewed. */

void FUN_40980720(undefined4 *param_1,int *param_2,uint *param_3,int param_4)

{
  bool bVar1;
  int iVar2;
  uint uVar3;
  int in_stack_00000048;
  int *in_stack_0000004c;
  int *in_stack_00000050;
  int *in_stack_00000054;
  int *in_stack_00000058;
  
  FUN_40993300();
  bVar1 = false;
  iVar2 = FUN_409769fc(*param_3);
  uVar3 = param_3[3];
  *in_stack_0000004c = iVar2 * param_3[1] * param_4;
  if (uVar3 == 0) {
    *in_stack_00000050 = 0;
  }
  else {
    iVar2 = FUN_409769fc(param_3[2]);
    *in_stack_00000050 = iVar2 * uVar3 * param_4;
  }
  uVar3 = param_3[5];
  if (uVar3 == 0) {
    *in_stack_00000054 = 0;
  }
  else {
    iVar2 = FUN_409769fc(param_3[4]);
    *in_stack_00000054 = iVar2 * uVar3 * param_4;
  }
  iVar2 = FUN_409769fc(param_3[6]);
  *in_stack_00000058 = iVar2 * in_stack_00000048;
  if (*param_2 == 0) {
    iVar2 = FUN_4097fde4(param_1,param_2);
  }
  else {
    if ((param_2[2] != 0) && (iVar2 = mali_sys_memcmp(param_3,param_2 + 8,0x60), iVar2 != 0)) {
      FUN_40980504(param_1);
      bVar1 = true;
    }
    if (((((0x20000 < (uint)(param_2[0x21] + *in_stack_0000004c)) ||
          (0x30000 < (uint)(param_2[0x23] + *in_stack_00000050))) ||
         (0x38000 < (uint)(param_2[0x25] + *in_stack_00000054))) ||
        ((0x8000 < (uint)(param_2[5] + *in_stack_00000058) ||
         ((param_3[6] == 0x1401 && (0xff < (uint)(param_2[2] + param_4))))))) ||
       ((param_3[6] == 0x1403 && (0xffff < (uint)(param_2[2] + param_4))))) {
      if (!bVar1) {
        FUN_40980504(param_1);
      }
      FUN_4097fbe0(param_1,param_2);
      iVar2 = FUN_4097fde4(param_1,param_2);
      if (iVar2 != 0) goto LAB_40980964;
    }
    iVar2 = param_2[2];
  }
  if (iVar2 == 0) {
    memcpy(param_2 + 8,param_3,0x60);
  }
LAB_40980964:
                    /* WARNING: Subroutine does not return */
  FUN_40993338(0x10);
}



/* 4098096c FUN_4098096c */

/* Boundary evidence: original MIPS .pdata 4098096c..40980b93. Semantic name remains unreviewed. */

void FUN_4098096c(undefined4 *param_1,uint param_2,int param_3,uint param_4)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iStack00000028;
  int in_stack_0000002c;
  int in_stack_00000030;
  int in_stack_00000034;
  
  FUN_409933b0();
  iStack00000028 = 0;
  iVar1 = FUN_40975028(param_2,param_4);
  if (((iVar1 == 0) && (-1 < param_3)) && (uVar2 = FUN_40974e18(param_2,param_4), uVar2 != 0)) {
    iVar4 = param_1[0x136];
    *(int *)(iVar4 + 0x65b0) = *(int *)(iVar4 + 0x65b0) + 1;
    iVar1 = FUN_40980430((int)(param_1 + 3));
    if (((iVar1 == 0) || (0x80 < (int)uVar2)) ||
       ((iVar3 = FUN_4097fca0(param_2,uVar2,&stack0x00000028,&stack0x0000002c),
        iVar1 = iStack00000028, iVar3 == 0 || (0x100 < iStack00000028)))) {
      if ((param_1[1] == 1) && (*(int *)(param_1[0x136] + 0x65a0) != 0)) {
        FUN_40980504(param_1);
      }
      *(int *)(iVar4 + 0x65b4) = *(int *)(iVar4 + 0x65b4) + 1;
      FUN_4098d160(param_1,param_2,param_3,uVar2);
    }
    else {
      FUN_4098035c((int)(param_1 + 3),(undefined4 *)&stack0x00000038,in_stack_0000002c,0x1403);
      iVar3 = FUN_40980720(param_1,(int *)(iVar4 + 0x6598),(uint *)&stack0x00000038,uVar2);
      if (iVar3 == 0) {
        FUN_40972e78(*(int **)(iVar4 + 0x659c),param_2,uVar2,*(int *)(iVar4 + 0x65ac),
                     (short)*(undefined4 *)(iVar4 + 0x65a0));
        FUN_40980128(param_1,(int *)(iVar4 + 0x6598),param_3,uVar2);
        *(int *)(iVar4 + 0x661c) = *(int *)(iVar4 + 0x661c) + in_stack_0000002c;
        *(int *)(iVar4 + 0x662c) = *(int *)(iVar4 + 0x662c) + in_stack_00000030;
        *(int *)(iVar4 + 0x6624) = *(int *)(iVar4 + 0x6624) + iStack00000028;
        *(int *)(iVar4 + 0x65ac) = in_stack_00000034 + *(int *)(iVar4 + 0x65ac);
        *(int *)(iVar4 + 0x65a4) = *(int *)(iVar4 + 0x65a4) + iVar1;
        *(uint *)(iVar4 + 0x65a0) = *(int *)(iVar4 + 0x65a0) + uVar2;
      }
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_409933e0(0x98);
}



/* 40980b94 FUN_40980b94 */

/* Boundary evidence: original MIPS .pdata 40980b94..40980e1f. Semantic name remains unreviewed. */

void FUN_40980b94(undefined4 *param_1,uint param_2,uint param_3,uint param_4)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  uint uStack00000028;
  uint in_stack_0000002c;
  int in_stack_00000030;
  int in_stack_00000034;
  int in_stack_00000038;
  ushort *in_stack_000000d8;
  
  FUN_40993300();
  iVar5 = param_1[0x136];
  uStack00000028 = 0;
  *(int *)(iVar5 + 0x65b0) = *(int *)(iVar5 + 0x65b0) + 1;
  iVar3 = FUN_40975028(param_2,param_3);
  if ((iVar3 != 0) ||
     (((param_4 != 0x1401 && (param_4 != 0x1403)) ||
      (uVar4 = FUN_40974e18(param_2,param_3), uVar4 == 0)))) goto LAB_40980e18;
  iVar3 = FUN_40980430((int)(param_1 + 3));
  if ((iVar3 != 0) &&
     (((param_4 == 0x1403 || (param_4 == 0x1401)) &&
      ((iVar3 = FUN_4097fca0(param_2,uVar4,(int *)&stack0x00000028,&stack0x00000030),
       uVar1 = uStack00000028, iVar3 != 0 && ((int)uStack00000028 < 0x101)))))) {
    if (in_stack_000000d8 == (ushort *)0x0) goto LAB_40980e18;
    FUN_40974d6c(&stack0x0000002c,&stack0x00000028,uVar4,param_4,in_stack_000000d8);
    uVar6 = (in_stack_0000002c - uStack00000028) + 1;
    if ((int)uVar6 < 0x81) {
      FUN_4098035c((int)(param_1 + 3),(undefined4 *)&stack0x00000040,in_stack_00000030,param_4);
      iVar3 = FUN_40980720(param_1,(int *)(iVar5 + 0x6598),(uint *)&stack0x00000040,uVar6);
      uVar2 = uStack00000028;
      if (iVar3 == 0) {
        FUN_409729ac(*(int **)(iVar5 + 0x659c),param_2,param_4,uVar4,(short *)in_stack_000000d8,
                     *(int *)(iVar5 + 0x65ac),
                     (short)*(undefined4 *)(iVar5 + 0x65a0) - (short)uStack00000028);
        FUN_40980128(param_1,(int *)(iVar5 + 0x6598),uVar2,uVar6);
        *(int *)(iVar5 + 0x661c) = in_stack_00000030 + *(int *)(iVar5 + 0x661c);
        *(int *)(iVar5 + 0x662c) = in_stack_00000034 + *(int *)(iVar5 + 0x662c);
        *(uint *)(iVar5 + 0x6624) = in_stack_0000002c + *(int *)(iVar5 + 0x6624);
        *(int *)(iVar5 + 0x65ac) = *(int *)(iVar5 + 0x65ac) + in_stack_00000038;
        *(uint *)(iVar5 + 0x65a4) = *(int *)(iVar5 + 0x65a4) + uVar1;
        *(uint *)(iVar5 + 0x65a0) = *(int *)(iVar5 + 0x65a0) + uVar6;
      }
      goto LAB_40980e18;
    }
  }
  if ((param_1[1] == 1) && (*(int *)(param_1[0x136] + 0x65a0) != 0)) {
    FUN_40980504(param_1);
  }
  *(int *)(iVar5 + 0x65b4) = *(int *)(iVar5 + 0x65b4) + 1;
  FUN_4098d488(param_1,param_2,uVar4,param_4);
LAB_40980e18:
                    /* WARNING: Subroutine does not return */
  FUN_40993338(0xa0);
}



/* 40980e38 FUN_40980e38 */

/* Boundary evidence: original MIPS .pdata 40980e38..40980e97. Semantic name remains unreviewed. */

void FUN_40980e38(int param_1,undefined4 param_2)

{
  if (*(int *)(param_1 + 0x10) == 0) {
    if ((*(int *)(param_1 + 4) == 1) && (*(int *)(*(int *)(param_1 + 0x4d8) + 0x65a0) != 0)) {
      FUN_40980504((undefined4 *)param_1);
    }
    *(undefined4 *)(param_1 + 0x10) = param_2;
  }
  return;
}



/* 40980ea0 FUN_40980ea0 */

/* Boundary evidence: original MIPS .pdata 40980ea0..40980ebb. Semantic name remains unreviewed. */

void FUN_40980ea0(int param_1)

{
  FUN_4097473c(param_1 + 0x14);
  return;
}



/* 40980ebc FUN_40980ebc */

/* Boundary evidence: original MIPS .pdata 40980ebc..4098105f. Semantic name remains unreviewed. */

void FUN_40980ebc(int param_1)

{
  uint uVar1;
  undefined4 *puVar2;
  uint *puVar3;
  
  puVar3 = (uint *)(param_1 + 0xc);
  puVar2 = *(undefined4 **)(param_1 + 0x4d8);
  *puVar3 = 0;
  FUN_409861b8(puVar2);
  FUN_40981208((undefined1 *)(param_1 + 0x14));
  FUN_40982330(param_1);
  FUN_40981b38((int)(puVar2 + 0x27));
  puVar2[0x17bc] = 0;
  puVar2[0x17bd] = 0;
  puVar2[0x17be] = 0;
  puVar2[0x17bf] = 0;
  puVar2[0x17c0] = 0x3f800000;
  puVar2[0x17c1] = 0;
  puVar2[0x17c2] = 0x3f800000;
  puVar2[0x17c3] = 0x800;
  FUN_409852e0((int)puVar3);
  *(undefined1 *)(param_1 + 0x3ec) = 0;
  *(undefined4 *)(param_1 + 0x3f0) = 0x405;
  *(undefined4 *)(param_1 + 1000) = 0x901;
  *(undefined4 *)(param_1 + 0x3f4) = 0x3f800000;
  *(undefined4 *)(param_1 + 0x3f8) = 0x3e800000;
  *(undefined4 *)(param_1 + 0x3fc) = 0x42c80000;
  *(undefined4 *)(param_1 + 0x400) = 0x3f800000;
  puVar2[0x18a4] = 0x3f800000;
  puVar2[0x18a5] = 0x3f800000;
  puVar2[0x18a6] = 0;
  puVar2[0x18a7] = 0;
  FUN_40973d00(param_1);
  *(undefined4 *)(param_1 + 0x3e4) = 0x80000000;
  *(undefined4 *)(param_1 + 0x3d4) = 0;
  *(undefined4 *)(param_1 + 0x3d8) = 0;
  *(undefined4 *)(param_1 + 0x3dc) = 0;
  *(undefined4 *)(param_1 + 0x3e0) = 0;
  uVar1 = *puVar3;
  *puVar3 = uVar1 & 0xfffeffff;
  *puVar3 = uVar1 & 0xfffeffff | 0x20000;
  *(undefined4 *)(param_1 + 0x3cc) = 4;
  *(undefined4 *)(param_1 + 0x3d0) = 4;
  puVar2[0x1961] = 0x1100;
  puVar2[0x1962] = 0x1100;
  puVar2[0x1963] = 0x1100;
  puVar2[0x1964] = 0x1100;
  puVar2[0x1965] = 0x1100;
  FUN_40982fd0(param_1,(int *)(param_1 + 0x4dc));
  mali_sys_memset(puVar2 + 0x1966,0,0x98);
  *(undefined4 *)(param_1 + 0x484) = 0;
  *(undefined4 *)(param_1 + 0x488) = 0;
  *(undefined4 *)(param_1 + 0x48c) = 1;
  *(undefined4 *)(param_1 + 0x490) = 1;
  *(undefined4 *)(param_1 + 0x4c4) = 0;
  *(undefined4 *)(param_1 + 0x4c8) = 0;
  *(undefined4 *)(param_1 + 0x4cc) = 0;
  *(undefined4 *)(param_1 + 0x494) = 0;
  *(undefined4 *)(param_1 + 0x498) = 0;
  *(undefined4 *)(param_1 + 0x49c) = 0;
  *(undefined4 *)(param_1 + 0x4a0) = 0;
  *(undefined4 *)(param_1 + 0x4a4) = 0;
  *(undefined4 *)(param_1 + 0x4a8) = 0;
  *(undefined4 *)(param_1 + 0x4ac) = 0;
  *(undefined4 *)(param_1 + 0x4b0) = 0;
  *(undefined4 *)(param_1 + 0x4bc) = 1;
  *(undefined4 *)(param_1 + 0x4c0) = 1;
  *(undefined4 *)(param_1 + 0x4d4) = 0;
  *(undefined4 *)(param_1 + 0x10) = 0;
  return;
}



/* 40981060 FUN_40981060 */

/* Boundary evidence: original MIPS .pdata 40981060..40981147. Semantic name remains unreviewed. */

undefined4 FUN_40981060(char *param_1,int *param_2,int param_3,int param_4)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  
  if ((*param_1 != '\0') && (param_4 != 0)) {
    iVar5 = *(int *)(param_1 + 0x1c);
    if (iVar5 == 0) {
      if (*(int *)(param_1 + 0x14) == 0) {
        return 0;
      }
    }
    else {
      iVar2 = FUN_409769fc(*(uint *)(param_1 + 0xc));
      uVar1 = *(int *)(param_1 + 4) * iVar2;
      iVar2 = *(int *)(param_1 + 8);
      uVar3 = *(uint *)(param_1 + 0x14);
      uVar4 = *(uint *)(iVar5 + 4);
      if (uVar4 < *param_2 * iVar2 + uVar1 + uVar3) {
        if (param_3 == 0) {
          iVar5 = -(uint)(uVar4 - uVar1 < uVar3) - (uint)(uVar4 < uVar1);
          if (-1 < iVar5) {
            iVar5 = __ll_div((uVar4 - uVar1) - uVar3,iVar5,iVar2,iVar2 >> 0x1f);
            *param_2 = iVar5;
            return 1;
          }
        }
        return 0;
      }
    }
  }
  return 1;
}



/* 4098119c FUN_4098119c */

/* Boundary evidence: original MIPS .pdata 4098119c..40981207. Semantic name remains unreviewed. */

void FUN_4098119c(char *param_1,int *param_2,int param_3,int *param_4)

{
  int iVar1;
  uint uVar2;
  
  FUN_40993230();
  uVar2 = 0;
  do {
    iVar1 = FUN_40981060(param_1,param_2,param_3,*param_4);
    if (iVar1 == 0) break;
    uVar2 = uVar2 + 1;
    param_4 = param_4 + 1;
    param_1 = param_1 + 0x30;
  } while (uVar2 < 0xe);
                    /* WARNING: Subroutine does not return */
  FUN_40993258(0x10);
}



/* 40981208 FUN_40981208 */

void FUN_40981208(undefined1 *param_1)

{
  undefined1 *puVar1;
  int iVar2;
  
  param_1[0x310] = 0;
  *(undefined4 *)(param_1 + 0xc) = 0x1406;
  *(undefined4 *)(param_1 + 4) = 4;
  *(undefined4 *)(param_1 + 8) = 0;
  iVar2 = 10;
  *(undefined4 *)(param_1 + 0x14) = 0;
  *param_1 = 0;
  *(undefined4 *)(param_1 + 0x18) = 0;
  *(undefined4 *)(param_1 + 0x1c) = 0;
  *(undefined4 *)(param_1 + 0x34) = 3;
  *(undefined4 *)(param_1 + 0x3c) = 0x1406;
  *(undefined4 *)(param_1 + 0x38) = 0;
  *(undefined4 *)(param_1 + 0x44) = 0;
  param_1[0x30] = 0;
  *(undefined4 *)(param_1 + 0x48) = 0;
  *(undefined4 *)(param_1 + 0x4c) = 0;
  *(undefined4 *)(param_1 + 100) = 4;
  *(undefined4 *)(param_1 + 0x6c) = 0x1406;
  *(undefined4 *)(param_1 + 0x68) = 0;
  *(undefined4 *)(param_1 + 0x74) = 0;
  param_1[0x60] = 0;
  *(undefined4 *)(param_1 + 0x78) = 0;
  *(undefined4 *)(param_1 + 0x7c) = 0;
  *(undefined4 *)(param_1 + 0x94) = 1;
  puVar1 = param_1 + 0x120;
  *(undefined4 *)(param_1 + 0x9c) = 0x1406;
  *(undefined4 *)(param_1 + 0x98) = 0;
  *(undefined4 *)(param_1 + 0xa4) = 0;
  param_1[0x90] = 0;
  *(undefined4 *)(param_1 + 0xa8) = 0;
  *(undefined4 *)(param_1 + 0xac) = 0;
  do {
    *(undefined4 *)(puVar1 + 4) = 4;
    iVar2 = iVar2 + -1;
    *(undefined4 *)(puVar1 + 0xc) = 0x1406;
    *(undefined4 *)(puVar1 + 8) = 0;
    *(undefined4 *)(puVar1 + 0x14) = 0;
    *puVar1 = 0;
    *(undefined4 *)(puVar1 + 0x18) = 0;
    *(undefined4 *)(puVar1 + 0x1c) = 0;
    puVar1 = puVar1 + 0x30;
  } while (iVar2 != 0);
  *(undefined4 *)(param_1 + 0xf4) = 0;
  *(undefined4 *)(param_1 + 0xfc) = 0x1401;
  *(undefined4 *)(param_1 + 0xf8) = 0;
  *(undefined4 *)(param_1 + 0x104) = 0;
  param_1[0xf0] = 0;
  *(undefined4 *)(param_1 + 0x108) = 0;
  *(undefined4 *)(param_1 + 0x10c) = 0;
  *(undefined4 *)(param_1 + 0xc4) = 0;
  *(undefined4 *)(param_1 + 0xcc) = 0x1406;
  *(undefined4 *)(param_1 + 200) = 0;
  *(undefined4 *)(param_1 + 0xd4) = 0;
  param_1[0xc0] = 0;
  *(undefined4 *)(param_1 + 0xd8) = 0;
  *(undefined4 *)(param_1 + 0xdc) = 0;
  *(undefined4 *)(param_1 + 0x300) = 0;
  *(undefined4 *)(param_1 + 0x304) = 0;
  *(undefined4 *)(param_1 + 0x308) = 0;
  *(undefined4 *)(param_1 + 0x30c) = 0;
  return;
}



/* 4098130c FUN_4098130c */

/* Boundary evidence: original MIPS .pdata 4098130c..4098137b. Semantic name remains unreviewed. */

undefined4 FUN_4098130c(int param_1,int param_2,int param_3,int param_4)

{
  if ((0 < param_2) && (param_2 < 5)) {
    if (param_3 != 0x1401) {
      return 0x500;
    }
    if (-1 < param_4) {
      FUN_40974680(param_1,5,param_2,0x1401);
      return 0;
    }
  }
  return 0x501;
}



/* 4098137c FUN_4098137c */

/* Boundary evidence: original MIPS .pdata 4098137c..409813fb. Semantic name remains unreviewed. */

undefined4 FUN_4098137c(int param_1,int param_2,uint param_3,int param_4)

{
  if ((0 < param_2) && (param_2 < 5)) {
    if ((param_3 != 0x1406) && (param_3 != 0x140c)) {
      return 0x500;
    }
    if (-1 < param_4) {
      FUN_40974680(param_1,4,param_2,param_3);
      return 0;
    }
  }
  return 0x501;
}



/* 409813fc FUN_409813fc */

/* Boundary evidence: original MIPS .pdata 409813fc..4098149b. Semantic name remains unreviewed. */

undefined4 FUN_409813fc(int param_1,int param_2,uint param_3,int param_4)

{
  if ((param_2 < 5) && (1 < param_2)) {
    if ((param_3 != 0x1400) && (((param_3 != 0x1402 && (param_3 != 0x1406)) && (param_3 != 0x140c)))
       ) {
      return 0x500;
    }
    if (-1 < param_4) {
      FUN_40974680(param_1,*(byte *)(param_1 + 0x324) + 6,param_2,param_3);
      return 0;
    }
  }
  return 0x501;
}



/* 4098149c FUN_4098149c */

/* Boundary evidence: original MIPS .pdata 4098149c..40981517. Semantic name remains unreviewed. */

undefined4 FUN_4098149c(int param_1,uint param_2,int param_3)

{
  undefined4 uVar1;
  
  if ((((param_2 == 0x1400) || (param_2 == 0x1402)) || (param_2 == 0x1406)) || (param_2 == 0x140c))
  {
    if (param_3 < 0) {
      uVar1 = 0x501;
    }
    else {
      FUN_40974680(param_1,3,1,param_2);
      uVar1 = 0;
    }
  }
  else {
    uVar1 = 0x500;
  }
  return uVar1;
}



/* 40981518 FUN_40981518 */

/* Boundary evidence: original MIPS .pdata 40981518..4098159b. Semantic name remains unreviewed. */

undefined4 FUN_40981518(int param_1,int param_2,uint param_3,int param_4)

{
  if (param_2 == 4) {
    if (((param_3 != 0x1401) && (param_3 != 0x1406)) && (param_3 != 0x140c)) {
      return 0x500;
    }
    if (-1 < param_4) {
      FUN_40974680(param_1,2,4,param_3);
      return 0;
    }
  }
  return 0x501;
}



/* 4098159c FUN_4098159c */

/* Boundary evidence: original MIPS .pdata 4098159c..4098161b. Semantic name remains unreviewed. */

undefined4 FUN_4098159c(int param_1,uint param_2,int param_3)

{
  undefined4 uVar1;
  
  if ((((param_2 == 0x1400) || (param_2 == 0x1402)) || (param_2 == 0x1406)) || (param_2 == 0x140c))
  {
    if (param_3 < 0) {
      uVar1 = 0x501;
    }
    else {
      FUN_40974680(param_1,1,3,param_2);
      uVar1 = 0;
    }
  }
  else {
    uVar1 = 0x500;
  }
  return uVar1;
}



/* 4098161c FUN_4098161c */

/* Boundary evidence: original MIPS .pdata 4098161c..409816b3. Semantic name remains unreviewed. */

undefined4 FUN_4098161c(int param_1,int param_2,uint param_3,int param_4)

{
  if ((param_2 < 5) && (1 < param_2)) {
    if ((param_3 != 0x1400) && (((param_3 != 0x1402 && (param_3 != 0x1406)) && (param_3 != 0x140c)))
       ) {
      return 0x500;
    }
    if (-1 < param_4) {
      FUN_40974680(param_1,0,param_2,param_3);
      return 0;
    }
  }
  return 0x501;
}



/* 40981828 FUN_40981828 */

/* Boundary evidence: original MIPS .pdata 40981828..4098184f. Semantic name remains unreviewed. */

void FUN_40981828(void)

{
  undefined4 uVar1;
  
  uVar1 = __litofp();
  __fpmul(uVar1,0x30000000);
  return;
}



/* 40981850 FUN_40981850 */

/* Boundary evidence: original MIPS .pdata 40981850..4098186b. Semantic name remains unreviewed. */

void FUN_40981850(undefined4 *param_1,undefined4 *param_2)

{
  FUN_40969ca0(param_1,param_2);
  return;
}



/* 4098186c FUN_4098186c */

/* Boundary evidence: original MIPS .pdata 4098186c..40981887. Semantic name remains unreviewed. */

void FUN_4098186c(undefined4 param_1,undefined4 param_2)

{
  mali_sys_memcpy(param_1,param_2,0x40);
  return;
}



/* 409818d0 FUN_409818d0 */

/* Boundary evidence: original MIPS .pdata 409818d0..40981a8f. Semantic name remains unreviewed. */

void FUN_409818d0(undefined4 *param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 in_stack_00000040;
  undefined4 in_stack_00000044;
  
  FUN_409933b0();
  uVar1 = __fpmul(param_2[0xc],in_stack_00000044);
  uVar2 = __fpmul(param_2[8],in_stack_00000040);
  uVar1 = __fpadd(uVar1,uVar2);
  uVar2 = __fpmul(param_2[4],param_4);
  uVar1 = __fpadd(uVar1,uVar2);
  uVar2 = __fpmul(*param_2,param_3);
  uVar1 = __fpadd(uVar1,uVar2);
  uVar2 = param_2[0xd];
  *param_1 = uVar1;
  uVar1 = __fpmul(uVar2,in_stack_00000044);
  uVar2 = __fpmul(param_2[9],in_stack_00000040);
  uVar1 = __fpadd(uVar1,uVar2);
  uVar2 = __fpmul(param_2[5],param_4);
  uVar1 = __fpadd(uVar1,uVar2);
  uVar2 = __fpmul(param_2[1],param_3);
  uVar1 = __fpadd(uVar1,uVar2);
  uVar2 = param_2[0xe];
  param_1[1] = uVar1;
  uVar1 = __fpmul(uVar2,in_stack_00000044);
  uVar2 = __fpmul(param_2[10],in_stack_00000040);
  uVar1 = __fpadd(uVar1,uVar2);
  uVar2 = __fpmul(param_2[6],param_4);
  uVar1 = __fpadd(uVar1,uVar2);
  uVar2 = __fpmul(param_2[2],param_3);
  uVar1 = __fpadd(uVar1,uVar2);
  param_1[2] = uVar1;
  uVar1 = __fpmul(param_2[0xf],in_stack_00000044);
  uVar2 = __fpmul(param_2[0xb],in_stack_00000040);
  uVar1 = __fpadd(uVar1,uVar2);
  uVar2 = __fpmul(param_2[7],param_4);
  uVar1 = __fpadd(uVar1,uVar2);
  uVar2 = __fpmul(param_2[3],param_3);
  uVar1 = __fpadd(uVar1,uVar2);
  param_1[3] = uVar1;
                    /* WARNING: Subroutine does not return */
  FUN_409933e0(0x10);
}



/* 40981a90 FUN_40981a90 */

int FUN_40981a90(uint param_1)

{
  int iVar1;
  
  iVar1 = 0;
  if ((param_1 & 0xffff0000) == 0) {
    iVar1 = 0x10;
  }
  else {
    param_1 = param_1 >> 0x10;
  }
  if ((param_1 & 0xff00) == 0) {
    iVar1 = iVar1 + 8;
  }
  else {
    param_1 = param_1 >> 8;
  }
  return (uint)(byte)(&DAT_4096203c)[param_1] + iVar1;
}



/* 40981adc FUN_40981adc */

/* Boundary evidence: original MIPS .pdata 40981adc..40981b37. Semantic name remains unreviewed. */

void FUN_40981adc(int param_1)

{
  mali_sys_memcpy(*(int *)(param_1 + 0x5dd0) * 0x40 + param_1 + 0x5550,
                  *(int *)(param_1 + 0x5510) * 0x40 + param_1 + -0x40,0x40);
  *(undefined4 *)((*(int *)(param_1 + 0x5dd0) + 0x1754) * 4 + param_1) = 0;
  return;
}



/* 40981b38 FUN_40981b38 */

void FUN_40981b38(int param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar5 = 0x20;
  puVar2 = (undefined4 *)(param_1 + 0x5010);
  puVar1 = (undefined4 *)(param_1 + 0x10);
  iVar3 = 0x20;
  do {
    puVar1[-4] = 0x3f800000;
    iVar3 = iVar3 + -1;
    puVar1[-3] = 0;
    puVar1[-2] = 0;
    puVar1[-1] = 0;
    *puVar1 = 0;
    puVar1[1] = 0x3f800000;
    puVar1[2] = 0;
    puVar1[3] = 0;
    puVar1[4] = 0;
    puVar1[5] = 0;
    puVar1[6] = 0x3f800000;
    puVar1[7] = 0;
    puVar1[8] = 0;
    puVar1[9] = 0;
    puVar1[10] = 0;
    puVar1[0xb] = 0x3f800000;
    *puVar2 = 1;
    puVar2 = puVar2 + 1;
    puVar1 = puVar1 + 0x10;
  } while (iVar3 != 0);
  puVar2 = (undefined4 *)(param_1 + 0x5090);
  puVar1 = (undefined4 *)(param_1 + 0x800);
  iVar3 = 0x20;
  do {
    *puVar1 = 0x3f800000;
    iVar3 = iVar3 + -1;
    puVar1[1] = 0;
    puVar1[2] = 0;
    puVar1[3] = 0;
    puVar1[4] = 0;
    puVar1[5] = 0x3f800000;
    puVar1[6] = 0;
    puVar1[7] = 0;
    puVar1[8] = 0;
    puVar1[9] = 0;
    puVar1[10] = 0x3f800000;
    puVar1[0xb] = 0;
    puVar1[0xc] = 0;
    puVar1[0xd] = 0;
    puVar1[0xe] = 0;
    puVar1[0xf] = 0x3f800000;
    puVar1 = puVar1 + 0x10;
    *puVar2 = 1;
    puVar2 = puVar2 + 1;
  } while (iVar3 != 0);
  puVar1 = (undefined4 *)(param_1 + 0x1000);
  puVar2 = (undefined4 *)(param_1 + 0x5110);
  iVar3 = 8;
  do {
    iVar4 = 0x20;
    do {
      *puVar1 = 0x3f800000;
      iVar4 = iVar4 + -1;
      puVar1[1] = 0;
      puVar1[2] = 0;
      puVar1[3] = 0;
      puVar1[4] = 0;
      puVar1[5] = 0x3f800000;
      puVar1[6] = 0;
      puVar1[7] = 0;
      puVar1[8] = 0;
      puVar1[9] = 0;
      puVar1[10] = 0x3f800000;
      puVar1[0xb] = 0;
      puVar1[0xc] = 0;
      puVar1[0xd] = 0;
      puVar1[0xe] = 0;
      puVar1[0xf] = 0x3f800000;
      puVar1 = puVar1 + 0x10;
      *puVar2 = 1;
      puVar2 = puVar2 + 1;
    } while (iVar4 != 0);
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  puVar1 = (undefined4 *)(param_1 + 0x5518);
  *(undefined4 *)(param_1 + 0x5510) = 1;
  *(undefined4 *)(param_1 + 0x5514) = 1;
  do {
    *puVar1 = 1;
    puVar1 = puVar1 + 1;
  } while (puVar1 != (undefined4 *)(param_1 + 0x5538));
  *(undefined1 *)(param_1 + 0x553c) = 0;
  *(undefined1 *)(param_1 + 0x553d) = 0;
  *(undefined4 *)(param_1 + 0x500c) = 0;
  *(undefined4 *)(param_1 + 0x5538) = 0x1700;
  *(int *)(param_1 + 0x5000) = *(int *)(param_1 + 0x5510) * 0x40 + param_1 + -0x40;
  puVar2 = (undefined4 *)(param_1 + 0x5d50);
  *(int *)(param_1 + 0x5004) = (*(int *)(param_1 + 0x5510) + 0x1403) * 4 + param_1;
  puVar1 = (undefined4 *)(param_1 + 0x5550);
  *(undefined4 *)(param_1 + 0x5540) = 0;
  *(undefined4 *)(param_1 + 0x5544) = 0;
  *(undefined4 *)(param_1 + 0x5548) = 0;
  *(undefined4 *)(param_1 + 0x554c) = 0;
  do {
    *puVar1 = 0x3f800000;
    iVar5 = iVar5 + -1;
    puVar1[1] = 0;
    puVar1[2] = 0;
    puVar1[3] = 0;
    puVar1[4] = 0;
    puVar1[5] = 0x3f800000;
    puVar1[6] = 0;
    puVar1[7] = 0;
    puVar1[8] = 0;
    puVar1[9] = 0;
    puVar1[10] = 0x3f800000;
    puVar1[0xb] = 0;
    puVar1[0xc] = 0;
    puVar1[0xd] = 0;
    puVar1[0xe] = 0;
    puVar1[0xf] = 0x3f800000;
    *puVar2 = 1;
    puVar2 = puVar2 + 1;
    puVar1 = puVar1 + 0x10;
  } while (iVar5 != 0);
  *(undefined4 *)(param_1 + 0x5dd0) = 0;
  *(undefined4 *)(param_1 + 0x5dd4) = 0x3f800000;
  *(undefined4 *)(param_1 + 0x5dd8) = 0;
  *(undefined4 *)(param_1 + 0x5ddc) = 0;
  *(undefined4 *)(param_1 + 0x5de0) = 0;
  *(undefined4 *)(param_1 + 0x5de4) = 0;
  *(undefined4 *)(param_1 + 0x5de8) = 0x3f800000;
  *(undefined4 *)(param_1 + 0x5dec) = 0;
  *(undefined4 *)(param_1 + 0x5df0) = 0;
  *(undefined4 *)(param_1 + 0x5df4) = 0;
  *(undefined4 *)(param_1 + 0x5df8) = 0;
  *(undefined4 *)(param_1 + 0x5dfc) = 0x3f800000;
  *(undefined4 *)(param_1 + 0x5e00) = 0;
  *(undefined4 *)(param_1 + 0x5e04) = 0;
  *(undefined4 *)(param_1 + 0x5e08) = 0;
  *(undefined4 *)(param_1 + 0x5e0c) = 0;
  *(undefined4 *)(param_1 + 0x5e10) = 0x3f800000;
  *(undefined4 *)(param_1 + 0x5e14) = 0x3f800000;
  *(undefined4 *)(param_1 + 0x5e18) = 0;
  *(undefined4 *)(param_1 + 0x5e1c) = 0;
  *(undefined4 *)(param_1 + 0x5e20) = 0;
  *(undefined4 *)(param_1 + 0x5e24) = 0;
  *(undefined4 *)(param_1 + 0x5e28) = 0x3f800000;
  *(undefined4 *)(param_1 + 0x5e2c) = 0;
  *(undefined4 *)(param_1 + 0x5e30) = 0;
  *(undefined4 *)(param_1 + 0x5e34) = 0;
  *(undefined4 *)(param_1 + 0x5e38) = 0;
  *(undefined4 *)(param_1 + 0x5e3c) = 0x3f800000;
  *(undefined4 *)(param_1 + 0x5e40) = 0;
  *(undefined4 *)(param_1 + 0x5e44) = 0;
  *(undefined4 *)(param_1 + 0x5e48) = 0;
  *(undefined4 *)(param_1 + 0x5e4c) = 0;
  *(undefined4 *)(param_1 + 0x5e50) = 0x3f800000;
  return;
}



/* 40981dc0 FUN_40981dc0 */

/* Boundary evidence: original MIPS .pdata 40981dc0..40981e37. Semantic name remains unreviewed. */

void FUN_40981dc0(uint param_1)

{
  FUN_40993370();
  if (param_1 != 0) {
    if ((int)param_1 < 0) {
      param_1 = -param_1;
    }
    FUN_40981a90(param_1);
  }
                    /* WARNING: Subroutine does not return */
  FUN_40993390(0x10);
}



/* 40981e38 FUN_40981e38 */

/* Boundary evidence: original MIPS .pdata 40981e38..40981e93. Semantic name remains unreviewed. */

undefined4 *
FUN_40981e38(undefined4 *param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 auStack_18 [4];
  
  puVar1 = (undefined4 *)FUN_409818d0(auStack_18,param_2,param_3,param_4);
  uVar2 = puVar1[1];
  uVar3 = puVar1[2];
  uVar4 = puVar1[3];
  *param_1 = *puVar1;
  param_1[1] = uVar2;
  param_1[2] = uVar3;
  param_1[3] = uVar4;
  return param_1;
}



/* 40981e94 FUN_40981e94 */

/* Boundary evidence: original MIPS .pdata 40981e94..40981f43. Semantic name remains unreviewed. */

undefined4 FUN_40981e94(int param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  
  if (param_1 != 0) {
    if (param_3 == 0) {
      return *(undefined4 *)(param_2 * 4 + param_1);
    }
    if (param_3 == 1) {
      uVar1 = FUN_40981dc0(*(uint *)(param_2 * 4 + param_1));
      return uVar1;
    }
    if (param_3 == 2) {
      uVar1 = __litofp(*(undefined4 *)(param_2 * 4 + param_1));
      uVar1 = __fpmul(uVar1,0x30000000);
      return uVar1;
    }
    if (param_3 == 3) {
      uVar1 = __litofp(*(undefined4 *)(param_2 * 4 + param_1));
      return uVar1;
    }
  }
  return 0;
}



/* 40981f44 FUN_40981f44 */

/* Boundary evidence: original MIPS .pdata 40981f44..40981f7f. Semantic name remains unreviewed. */

void FUN_40981f44(undefined4 *param_1,undefined4 *param_2)

{
  if (param_1 != param_2) {
    mali_sys_memcpy(param_1,param_2,0x40);
  }
  FUN_4096a92c(param_1);
  return;
}



/* 40981f80 FUN_40981f80 */

/* Boundary evidence: original MIPS .pdata 40981f80..40981fef. Semantic name remains unreviewed. */

void FUN_40981f80(undefined4 *param_1,int param_2,undefined4 param_3,int param_4)

{
  undefined4 uVar1;
  int iVar2;
  
  if (param_1 != (undefined4 *)0x0) {
    iVar2 = 0;
    do {
      uVar1 = FUN_40981e94(param_2,iVar2,param_4);
      iVar2 = iVar2 + 1;
      *param_1 = uVar1;
      param_1 = param_1 + 1;
    } while (iVar2 < 4);
  }
  return;
}



/* 40981ff0 FUN_40981ff0 */

/* Boundary evidence: original MIPS .pdata 40981ff0..409820df. Semantic name remains unreviewed. */

undefined4 FUN_40981ff0(int param_1,int param_2,int param_3,int param_4)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 local_a0;
  undefined4 local_9c;
  undefined4 auStack_90 [16];
  undefined1 auStack_50 [64];
  
  if (param_2 == 0x3000) {
    if (param_3 != 0) {
      FUN_40981f80(&local_a0,param_3,4,param_4);
      mali_sys_memcpy(auStack_50,*(int *)(param_1 + 0x5510) * 0x40 + param_1 + -0x40,0x40);
      mali_sys_memcpy(auStack_90,auStack_50,0x40);
      iVar2 = FUN_4096a92c(auStack_90);
      if (iVar2 == 0) {
        FUN_40969ca0(auStack_90,auStack_90);
        puVar3 = FUN_40981e38(&local_a0,auStack_90,local_a0,local_9c);
        uVar5 = puVar3[1];
        uVar4 = puVar3[2];
        uVar1 = puVar3[3];
        *(undefined4 *)(param_1 + 0x5540) = *puVar3;
        *(undefined4 *)(param_1 + 0x5544) = uVar5;
        *(undefined4 *)(param_1 + 0x5548) = uVar4;
        *(undefined4 *)(param_1 + 0x554c) = uVar1;
      }
    }
    uVar1 = 0;
  }
  else {
    uVar1 = 0x500;
  }
  return uVar1;
}



/* 40982198 FUN_40982198 */

/* Boundary evidence: original MIPS .pdata 40982198..4098221f. Semantic name remains unreviewed. */

void FUN_40982198(int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  
  FUN_40993370();
  iVar4 = *(int *)(param_1 + 0x504);
  uVar1 = __fpmul(param_2,0x477fff00);
  uVar1 = mali_sys_floor(uVar1);
  uVar2 = __fptoul(uVar1);
  *(uint *)(iVar4 + 0x10) = *(uint *)(iVar4 + 0x10) & 0xffff0000 ^ uVar2;
  uVar1 = __fpmul(param_3,0x477fff00);
  uVar1 = mali_sys_ceil(uVar1);
  iVar3 = __fptoul(uVar1);
  *(uint *)(iVar4 + 0x10) = *(uint *)(iVar4 + 0x10) & 0xffff ^ iVar3 << 0x10;
                    /* WARNING: Subroutine does not return */
  FUN_40993390(0x10);
}



/* 40982220 FUN_40982220 */

/* Boundary evidence: original MIPS .pdata 40982220..4098232f. Semantic name remains unreviewed. */

void FUN_40982220(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = __gts(param_2,0x3f800000);
  if (iVar1 != 0) {
    param_2 = 0x3f800000;
  }
  iVar1 = __lts(param_2,0);
  if (iVar1 != 0) {
    param_2 = 0;
  }
  iVar1 = __gts(param_3,0x3f800000);
  if (iVar1 != 0) {
    param_3 = 0x3f800000;
  }
  iVar1 = __lts(param_3,0);
  if (iVar1 != 0) {
    param_3 = 0;
  }
  *(undefined4 *)(param_1 + 0x414) = param_2;
  *(undefined4 *)(param_1 + 0x418) = param_3;
  *(undefined4 *)(param_1 + 0x41c) = param_2;
  *(undefined4 *)(param_1 + 0x420) = param_3;
  iVar1 = __gts(param_2,param_3);
  if (iVar1 != 0) {
    *(undefined4 *)(param_1 + 0x41c) = param_3;
    *(undefined4 *)(param_1 + 0x420) = param_2;
  }
  FUN_40982198(param_1,*(undefined4 *)(param_1 + 0x41c),*(undefined4 *)(param_1 + 0x420));
  uVar2 = *(uint *)(param_1 + 0xc);
  *(uint *)(param_1 + 0xc) = uVar2 | 0x40000;
  *(uint *)(param_1 + 0xc) = uVar2 | 0x840000;
  *(uint *)(param_1 + 0xc) = uVar2 | 0xa40000;
  return;
}



/* 40982330 FUN_40982330 */

/* Boundary evidence: original MIPS .pdata 40982330..4098238f. Semantic name remains unreviewed. */

void FUN_40982330(int param_1)

{
  uint uVar1;
  
  *(undefined4 *)(param_1 + 0x404) = 0;
  *(undefined4 *)(param_1 + 0x408) = 0;
  *(undefined4 *)(param_1 + 0x40c) = 0;
  *(undefined4 *)(param_1 + 0x410) = 0;
  uVar1 = *(uint *)(param_1 + 0xc);
  *(uint *)(param_1 + 0xc) = uVar1 | 0x40000;
  *(uint *)(param_1 + 0xc) = uVar1 | 0xc0000;
  *(uint *)(param_1 + 0xc) = uVar1 | 0x2c0000;
  FUN_40982220(param_1,0,0x3f800000);
  return;
}



/* 40982390 FUN_40982390 */

int FUN_40982390(int param_1,int param_2)

{
  int iVar1;
  
  if (param_1 == 0x1702) {
    iVar1 = param_2 + 0xc;
  }
  else if (param_1 == 0x8576) {
    iVar1 = param_2 + 1;
  }
  else if (param_1 == 0x8577) {
    iVar1 = 0x14;
  }
  else {
    iVar1 = 0x1d;
  }
  return iVar1;
}



/* 409823dc FUN_409823dc */

undefined4 FUN_409823dc(int param_1)

{
  if (param_1 != 0x300) {
    if (param_1 == 0x301) {
      return 1;
    }
    if (param_1 == 0x302) {
      return 2;
    }
    if (param_1 == 0x303) {
      return 3;
    }
  }
  return 0;
}



/* 40982430 FUN_40982430 */

undefined4 FUN_40982430(uint param_1)

{
  if (param_1 < 0x8575) {
    if (param_1 == 0x8574) {
      return 3;
    }
    if (param_1 == 0x104) {
      return 2;
    }
    if (param_1 != 0x1e01) {
      if (param_1 == 0x2100) {
        return 1;
      }
      if (param_1 == 0x84e7) {
        return 5;
      }
    }
  }
  else {
    if (param_1 == 0x8575) {
      return 4;
    }
    if (param_1 == 0x86ae) {
      return 6;
    }
    if (param_1 == 0x86af) {
      return 7;
    }
  }
  return 0;
}



/* 4098267c FUN_4098267c */

/* Boundary evidence: original MIPS .pdata 4098267c..409826db. Semantic name remains unreviewed. */

undefined4 FUN_4098267c(undefined4 *param_1,int param_2)

{
  undefined4 uVar1;
  
  if (param_1 != (undefined4 *)0x0) {
    if (param_2 == 0) {
      uVar1 = __fptoul(*param_1);
      return uVar1;
    }
    if ((param_2 == 1) || ((1 < param_2 && (param_2 < 4)))) {
      return *param_1;
    }
  }
  return 0;
}



/* 409826dc FUN_409826dc */

/* Boundary evidence: original MIPS .pdata 409826dc..409826f7. Semantic name remains unreviewed. */

void FUN_409826dc(int param_1)

{
  mali_sys_atomic_inc(param_1 + 0x50);
  return;
}



/* 409826f8 FUN_409826f8 */

/* Boundary evidence: original MIPS .pdata 409826f8..4098271f. Semantic name remains unreviewed. */

void FUN_409826f8(void)

{
  undefined4 uVar1;
  
  uVar1 = __litofp();
  __fpmul(uVar1,0x30000000);
  return;
}



/* 40982720 FUN_40982720 */

uint FUN_40982720(uint param_1)

{
  uint uVar1;
  
  uVar1 = 0;
  if ((param_1 & 0x7fff0000) != 0) {
    uVar1 = 0x10;
  }
  if ((param_1 & 0x7f00ff00) != 0) {
    uVar1 = uVar1 | 8;
  }
  if ((param_1 & 0x70f0f0f0) != 0) {
    uVar1 = uVar1 | 4;
  }
  if ((param_1 & 0x3ccccccc) != 0) {
    uVar1 = uVar1 | 2;
  }
  if ((param_1 & 0x2aaaaaaa) != 0) {
    uVar1 = uVar1 | 1;
  }
  return uVar1;
}



/* 409827d0 FUN_409827d0 */

int FUN_409827d0(uint param_1)

{
  int iVar1;
  
  iVar1 = 0;
  if ((param_1 & 0xffff0000) == 0) {
    iVar1 = 0x10;
  }
  else {
    param_1 = param_1 >> 0x10;
  }
  if ((param_1 & 0xff00) == 0) {
    iVar1 = iVar1 + 8;
  }
  else {
    param_1 = param_1 >> 8;
  }
  return (uint)(byte)(&DAT_4096203c)[param_1] + iVar1;
}



/* 4098284c FUN_4098284c */

void FUN_4098284c(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 8);
  if (iVar1 != 0x2901) {
    if (iVar1 == 0x812f) {
      iVar1 = 1;
      goto LAB_40982888;
    }
    if (iVar1 == 0x8370) {
      iVar1 = 4;
      goto LAB_40982888;
    }
  }
  iVar1 = 0;
LAB_40982888:
  *(uint *)(*(int *)(param_1 + 0x34) + 0x140) =
       *(uint *)(*(int *)(param_1 + 0x34) + 0x140) & 0xfff8ffff | iVar1 << 0x10;
  return;
}



/* 409828ac FUN_409828ac */

void FUN_409828ac(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 4);
  if (iVar1 != 0x2901) {
    if (iVar1 == 0x812f) {
      iVar1 = 1;
      goto LAB_409828e8;
    }
    if (iVar1 == 0x8370) {
      iVar1 = 4;
      goto LAB_409828e8;
    }
  }
  iVar1 = 0;
LAB_409828e8:
  *(uint *)(*(int *)(param_1 + 0x34) + 0x140) =
       *(uint *)(*(int *)(param_1 + 0x34) + 0x140) & 0xffff1fff | iVar1 << 0xd;
  return;
}



/* 4098290c FUN_4098290c */

/* Boundary evidence: original MIPS .pdata 4098290c..40982a77. Semantic name remains unreviewed. */

void FUN_4098290c(int param_1)

{
  uint uVar1;
  int *piVar2;
  int iVar3;
  
  if ((*(int *)(param_1 + 0xc) == 0x2600) && (*(int *)(param_1 + 0x10) == 0x2601)) {
    *(uint *)(*(int *)(param_1 + 0x34) + 0x13c) =
         *(uint *)(*(int *)(param_1 + 0x34) + 0x13c) & 0xfffffff | 0x80000000;
    *(uint *)(*(int *)(param_1 + 0x34) + 0x140) =
         *(uint *)(*(int *)(param_1 + 0x34) + 0x140) & 0xffffffe0;
  }
  else {
    *(uint *)(*(int *)(param_1 + 0x34) + 0x13c) =
         *(uint *)(*(int *)(param_1 + 0x34) + 0x13c) & 0xfffffff;
    *(uint *)(*(int *)(param_1 + 0x34) + 0x140) =
         *(uint *)(*(int *)(param_1 + 0x34) + 0x140) & 0xffffffe0;
  }
  if ((*(int *)(param_1 + 0xc) == 0x2600) || (*(int *)(param_1 + 0xc) == 0x2601)) {
    *(uint *)(*(int *)(param_1 + 0x34) + 0x13c) =
         *(uint *)(*(int *)(param_1 + 0x34) + 0x13c) & 0xf00fffff;
  }
  else {
    piVar2 = *(int **)(param_1 + 0x1c);
    if ((piVar2 != (int *)0x0) && ((uint *)*piVar2 != (uint *)0x0)) {
      if (((int *)*piVar2)[1] < *(int *)*piVar2) {
        uVar1 = *(uint *)*piVar2;
      }
      else {
        uVar1 = *(uint *)(*piVar2 + 4);
      }
      iVar3 = *(int *)(param_1 + 0x34);
      uVar1 = uVar1 >> 1 | uVar1;
      uVar1 = uVar1 >> 2 | uVar1;
      uVar1 = uVar1 >> 4 | uVar1;
      uVar1 = uVar1 >> 8 | uVar1;
      uVar1 = FUN_40982720(((uVar1 >> 0x10 | uVar1) >> 1) + 1);
      *(uint *)(iVar3 + 0x13c) = uVar1 << 0x18 | *(uint *)(iVar3 + 0x13c) & 0xf00fffff;
    }
  }
  return;
}



/* 40982a78 FUN_40982a78 */

/* Boundary evidence: original MIPS .pdata 40982a78..40982aef. Semantic name remains unreviewed. */

void FUN_40982a78(uint param_1)

{
  FUN_40993370();
  if (param_1 != 0) {
    if ((int)param_1 < 0) {
      param_1 = -param_1;
    }
    FUN_409827d0(param_1);
  }
                    /* WARNING: Subroutine does not return */
  FUN_40993390(0x10);
}



/* 40982af0 FUN_40982af0 */

/* Boundary evidence: original MIPS .pdata 40982af0..40982f97. Semantic name remains unreviewed. */

void FUN_40982af0(int param_1,int param_2)

{
  int iVar1;
  uint *puVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  int *piVar10;
  int iStack00000010;
  
  FUN_40993300();
  iVar1 = *(int *)(param_1 + 0x4d8) + param_2 * 0x5c;
  iVar8 = param_2 * 2 + 1;
  iStack00000010 = iVar1 + 0x62a0;
  puVar2 = (uint *)(iVar8 * 4 + *(int *)(param_1 + 0x508) + 0x20);
  *puVar2 = *puVar2 & 0xe0000000;
  iVar7 = param_2 * 2 + 2;
  puVar2 = (uint *)(iVar7 * 4 + *(int *)(param_1 + 0x508) + 0x20);
  *puVar2 = *puVar2 & 0xe0000000;
  iVar3 = *(int *)(iVar1 + 0x62a4);
  uVar9 = param_2 + 0xc;
  if (iVar3 == 0x104) {
    puVar2 = (uint *)(iVar8 * 4 + *(int *)(param_1 + 0x508) + 0x20);
    *puVar2 = (uVar9 * 0x100 | 0x200001d) ^ *puVar2 & 0xe0000000;
    puVar2 = (uint *)(iVar7 * 4 + *(int *)(param_1 + 0x508) + 0x20);
    uVar9 = *puVar2 & 0xe0000000 ^ (uVar9 * 0x100 | 0x140405d);
  }
  else {
    if (iVar3 == 0xbe2) {
      puVar2 = (uint *)(iVar8 * 4 + *(int *)(param_1 + 0x508) + 0x20);
      *puVar2 = ((param_2 + 1) * 0x100 | uVar9 * 0x10000 | 0x420001d) ^ *puVar2 & 0xe0000000;
      puVar2 = (uint *)(iVar7 * 4 + *(int *)(param_1 + 0x508) + 0x20);
      *puVar2 = (uVar9 * 0x100 | 0x140405d) ^ *puVar2 & 0xe0000000;
      goto LAB_40982f90;
    }
    if (iVar3 != 0x1e01) {
      if (iVar3 == 0x2100) {
        puVar2 = (uint *)(iVar8 * 4 + *(int *)(param_1 + 0x508) + 0x20);
        *puVar2 = *puVar2 & 0xe0000000 ^ (uVar9 * 0x100 | 0x100001d);
        puVar2 = (uint *)(iVar7 * 4 + *(int *)(param_1 + 0x508) + 0x20);
        *puVar2 = *puVar2 & 0xe0000000 ^ (uVar9 * 0x100 | 0x140405d);
        goto LAB_40982f90;
      }
      if (iVar3 == 0x2101) {
        puVar2 = (uint *)(iVar8 * 4 + *(int *)(param_1 + 0x508) + 0x20);
        *puVar2 = (uVar9 * 0x10000 | uVar9 | 0x4401d00) ^ *puVar2 & 0xe0000000;
        puVar2 = (uint *)(iVar7 * 4 + *(int *)(param_1 + 0x508) + 0x20);
        *puVar2 = *puVar2 & 0xe0000000 ^ 0x40405d;
        goto LAB_40982f90;
      }
      if (iVar3 != 0x8570) goto LAB_40982f90;
      piVar10 = (int *)(iVar1 + 0x62b0);
      uVar9 = 0;
      do {
        iVar1 = FUN_40982390(*piVar10,param_2);
        iVar3 = FUN_40982390(piVar10[3],param_2);
        puVar2 = (uint *)(iVar8 * 4 + *(int *)(param_1 + 0x508) + 0x20);
        uVar5 = ~(0x1f << (uVar9 & 0x1f));
        *puVar2 = iVar1 << (uVar9 & 0x1f) ^ uVar5 & *puVar2;
        puVar2 = (uint *)(iVar7 * 4 + *(int *)(param_1 + 0x508) + 0x20);
        *puVar2 = uVar5 & *puVar2 ^ iVar3 << (uVar9 & 0x1f);
        iVar1 = FUN_409823dc(piVar10[6]);
        uVar6 = uVar9 + 5;
        puVar2 = (uint *)(*(int *)(param_1 + 0x508) + 0x20 + iVar8 * 4);
        uVar5 = ~(7 << (uVar6 & 0x1f));
        *puVar2 = iVar1 << (uVar6 & 0x1f) ^ uVar5 & *puVar2;
        iVar3 = FUN_409823dc(piVar10[9]);
        iVar1 = iStack00000010;
        puVar2 = (uint *)(*(int *)(param_1 + 0x508) + 0x20 + iVar7 * 4);
        uVar9 = uVar9 + 8;
        piVar10 = piVar10 + 1;
        *puVar2 = *puVar2 & uVar5 ^ iVar3 << (uVar6 & 0x1f);
      } while ((int)uVar9 < 0x18);
      iVar3 = FUN_40982430(*(uint *)(iStack00000010 + 8));
      puVar2 = (uint *)(iVar8 * 4 + *(int *)(param_1 + 0x508) + 0x20);
      *puVar2 = *puVar2 & 0xf8ffffff ^ iVar3 << 0x18;
      iVar3 = FUN_40982430(*(uint *)(iVar1 + 0xc));
      puVar2 = (uint *)(iVar7 * 4 + *(int *)(param_1 + 0x508) + 0x20);
      *puVar2 = *puVar2 & 0xf8ffffff ^ iVar3 << 0x18;
      iVar3 = *(int *)(iVar1 + 0x40);
      iVar4 = 2;
      if (iVar3 == 1) {
LAB_40982d38:
        iVar3 = 0;
      }
      else if (iVar3 == 2) {
        iVar3 = 1;
      }
      else {
        if (iVar3 != 4) goto LAB_40982d38;
        iVar3 = 2;
      }
      puVar2 = (uint *)(iVar8 * 4 + *(int *)(param_1 + 0x508) + 0x20);
      *puVar2 = *puVar2 & 0xe7ffffff ^ iVar3 << 0x1b;
      iVar1 = *(int *)(iVar1 + 0x44);
      if (iVar1 == 1) {
LAB_40982d84:
        iVar4 = 0;
      }
      else if (iVar1 == 2) {
        iVar4 = 1;
      }
      else if (iVar1 != 4) goto LAB_40982d84;
      puVar2 = (uint *)(iVar7 * 4 + *(int *)(param_1 + 0x508) + 0x20);
      *puVar2 = iVar4 << 0x1b ^ *puVar2 & 0xe7ffffff;
      goto LAB_40982f90;
    }
    puVar2 = (uint *)(iVar8 * 4 + *(int *)(param_1 + 0x508) + 0x20);
    *puVar2 = *puVar2 & 0xe0000000 ^ uVar9;
    puVar2 = (uint *)(iVar7 * 4 + *(int *)(param_1 + 0x508) + 0x20);
    uVar9 = *puVar2 & 0xe0000000 ^ (uVar9 | 0x404040);
  }
  *puVar2 = uVar9;
LAB_40982f90:
                    /* WARNING: Subroutine does not return */
  FUN_40993338(0x18);
}



/* 40982fd0 FUN_40982fd0 */

/* Boundary evidence: original MIPS .pdata 40982fd0..409830d3. Semantic name remains unreviewed. */

void FUN_40982fd0(int param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  undefined1 *puVar3;
  uint uVar4;
  int iVar5;
  
  FUN_40993300();
  iVar5 = 0;
  *(undefined1 *)(*(int *)(param_1 + 0x4d8) + 0x6580) = 0;
  uVar4 = 0;
  puVar3 = (undefined1 *)(param_1 + 0x32c);
  *(undefined4 *)(param_1 + 0x328) = 0;
  do {
    iVar1 = *param_2;
    iVar2 = uVar4 + *(int *)(param_1 + 0x4d8);
    *puVar3 = 0;
    *(int *)(puVar3 + 4) = iVar1;
    *(undefined4 *)(puVar3 + 0xc) = 0;
    *(undefined1 *)(iVar2 + 0x62a0) = 0;
    *(undefined4 *)(iVar2 + 0x62a4) = 0x2100;
    *(undefined4 *)(iVar2 + 0x62a8) = 0x2100;
    *(undefined4 *)(iVar2 + 0x62ac) = 0x2100;
    *(undefined4 *)(iVar2 + 0x62b0) = 0x1702;
    *(undefined4 *)(iVar2 + 0x62b4) = 0x8578;
    *(undefined4 *)(iVar2 + 0x62b8) = 0x8576;
    *(undefined4 *)(iVar2 + 0x62bc) = 0x1702;
    *(undefined4 *)(iVar2 + 0x62c0) = 0x8578;
    *(undefined4 *)(iVar2 + 0x62c4) = 0x8576;
    *(undefined4 *)(iVar2 + 0x62c8) = 0x300;
    *(undefined4 *)(iVar2 + 0x62cc) = 0x300;
    *(undefined4 *)(iVar2 + 0x62d0) = 0x302;
    *(undefined4 *)(iVar2 + 0x62d4) = 0x302;
    *(undefined4 *)(iVar2 + 0x62d8) = 0x302;
    *(undefined4 *)(iVar2 + 0x62dc) = 0x302;
    *(undefined4 *)(iVar2 + 0x62e0) = 1;
    *(undefined4 *)(iVar2 + 0x62e4) = 1;
    *(undefined4 *)(iVar2 + 0x62e8) = 0;
    *(undefined4 *)(iVar2 + 0x62ec) = 0;
    *(undefined4 *)(iVar2 + 0x62f0) = 0;
    *(undefined4 *)(iVar2 + 0x62f4) = 0;
    *(undefined4 *)(iVar2 + 0x62f8) = 0;
    mali_sys_atomic_inc(iVar1 + 0x50);
    FUN_40982af0(param_1,iVar5);
    uVar4 = uVar4 + 0x5c;
    iVar5 = iVar5 + 1;
    puVar3 = puVar3 + 0x14;
  } while (uVar4 < 0x2e0);
                    /* WARNING: Subroutine does not return */
  FUN_40993338(0x10);
}



/* 409830d4 FUN_409830d4 */

/* Boundary evidence: original MIPS .pdata 409830d4..4098311f. Semantic name remains unreviewed. */

void FUN_409830d4(int param_1)

{
  *(uint *)(*(int *)(param_1 + 0x34) + 0x140) =
       *(uint *)(*(int *)(param_1 + 0x34) + 0x140) & 0xffffefff |
       (uint)(*(int *)(param_1 + 0x10) == 0x2600) << 0xc;
  FUN_4098290c(param_1);
  return;
}



/* 40983120 FUN_40983120 */

/* Boundary evidence: original MIPS .pdata 40983120..409831ff. Semantic name remains unreviewed. */

void FUN_40983120(int param_1)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  
  uVar2 = *(uint *)(param_1 + 0xc);
  iVar1 = 0;
  iVar3 = 0;
  if ((uVar2 == 0x2600) ||
     ((uVar2 != 0x2601 && ((uVar2 == 0x2700 || ((uVar2 != 0x2701 && (uVar2 == 0x2702)))))))) {
    iVar1 = 1;
  }
  *(uint *)(*(int *)(param_1 + 0x34) + 0x140) =
       *(uint *)(*(int *)(param_1 + 0x34) + 0x140) & 0xfffff7ff | iVar1 << 0xb;
  if ((((0x25ff < uVar2) && (0x2601 < uVar2)) && (0x26ff < uVar2)) &&
     ((0x2701 < uVar2 && (uVar2 < 0x2704)))) {
    iVar3 = 3;
  }
  *(uint *)(*(int *)(param_1 + 0x34) + 0x140) =
       *(uint *)(*(int *)(param_1 + 0x34) + 0x140) & 0xfffff9ff | iVar3 << 9;
  FUN_4098290c(param_1);
  return;
}



/* 40983200 FUN_40983200 */

/* Boundary evidence: original MIPS .pdata 40983200..409832af. Semantic name remains unreviewed. */

undefined4 FUN_40983200(int param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  
  if (param_1 != 0) {
    if (param_3 == 0) {
      return *(undefined4 *)(param_2 * 4 + param_1);
    }
    if (param_3 == 1) {
      uVar1 = FUN_40982a78(*(uint *)(param_2 * 4 + param_1));
      return uVar1;
    }
    if (param_3 == 2) {
      uVar1 = __litofp(*(undefined4 *)(param_2 * 4 + param_1));
      uVar1 = __fpmul(uVar1,0x30000000);
      return uVar1;
    }
    if (param_3 == 3) {
      uVar1 = __litofp(*(undefined4 *)(param_2 * 4 + param_1));
      return uVar1;
    }
  }
  return 0;
}



/* 409832b0 FUN_409832b0 */

/* Boundary evidence: original MIPS .pdata 409832b0..409834a3. Semantic name remains unreviewed. */

void FUN_409832b0(int *param_1,int param_2,int param_3,undefined4 *param_4)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  int in_stack_00000030;
  
  FUN_40993370();
  if ((param_2 == 0xde1) && (param_4 != (undefined4 *)0x0)) {
    iVar3 = param_1[*param_1 * 5 + 2];
    iVar1 = FUN_4098267c(param_4,in_stack_00000030);
    if (param_3 == 0x2800) {
      uVar2 = 0;
      do {
        if (iVar1 == *(int *)((int)&DAT_40962818 + uVar2)) {
          *(int *)(iVar3 + 0x10) = iVar1;
          FUN_409830d4(iVar3);
          goto LAB_40983494;
        }
        uVar2 = uVar2 + 4;
      } while (uVar2 < 8);
    }
    else if (param_3 == 0x2801) {
      uVar2 = 0;
      do {
        if (iVar1 == *(int *)((int)&DAT_40962800 + uVar2)) {
          if ((*(int *)(iVar3 + 0xc) == 0x2600) || (*(int *)(iVar3 + 0xc) == 0x2601)) {
            *(undefined4 *)(*(int *)(iVar3 + 0x34) + 0x184) = 1;
          }
          *(int *)(iVar3 + 0xc) = iVar1;
          FUN_40983120(iVar3);
          *(undefined4 *)(iVar3 + 0x3c) = 1;
          goto LAB_40983494;
        }
        uVar2 = uVar2 + 4;
      } while (uVar2 < 0x18);
    }
    else if (param_3 == 0x2802) {
      uVar2 = 0;
      do {
        if (iVar1 == *(int *)((int)&DAT_409627f8 + uVar2)) {
          *(int *)(iVar3 + 4) = iVar1;
          FUN_409828ac(iVar3);
          goto LAB_40983494;
        }
        uVar2 = uVar2 + 4;
      } while (uVar2 < 8);
    }
    else if (param_3 == 0x2803) {
      uVar2 = 0;
      do {
        if (iVar1 == *(int *)((int)&DAT_409627f8 + uVar2)) {
          *(int *)(iVar3 + 8) = iVar1;
          FUN_4098284c(iVar3);
          goto LAB_40983494;
        }
        uVar2 = uVar2 + 4;
      } while (uVar2 < 8);
    }
    else if ((param_3 == 0x8191) && ((iVar1 == 1 || (iVar1 == 0)))) {
      *(char *)(iVar3 + 0x14) = (char)iVar1;
LAB_40983494:
      *(undefined4 *)(iVar3 + 0x38) = 1;
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_40993390(0x10);
}



/* 409834a4 FUN_409834a4 */

/* Boundary evidence: original MIPS .pdata 409834a4..409834f7. Semantic name remains unreviewed. */

void FUN_409834a4(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  
  FUN_40993370();
  puVar3 = (undefined4 *)(param_1 + 0x10);
  iVar4 = 8;
  do {
    iVar2 = puVar3[-2];
    if (iVar2 != 0) {
      puVar3[-2] = 0;
      *puVar3 = 0;
      iVar1 = mali_sys_atomic_dec_and_return(iVar2 + 0x50);
      if (iVar1 == 0) {
        FUN_4097b168(iVar2);
      }
    }
    iVar4 = iVar4 + -1;
    puVar3 = puVar3 + 5;
  } while (iVar4 != 0);
                    /* WARNING: Subroutine does not return */
  FUN_40993390(0x10);
}



/* 409834f8 FUN_409834f8 */

/* Boundary evidence: original MIPS .pdata 409834f8..40983567. Semantic name remains unreviewed. */

void FUN_409834f8(int param_1,int param_2,int *param_3)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  
  FUN_40993230();
  piVar2 = (int *)(param_1 + 0x10);
  iVar3 = 8;
  do {
    if (*piVar2 == param_2) {
      iVar4 = piVar2[-2];
      piVar2[-2] = *param_3;
      *piVar2 = 0;
      mali_sys_atomic_inc(*param_3 + 0x50);
      iVar1 = mali_sys_atomic_dec_and_return(iVar4 + 0x50);
      if (iVar1 == 0) {
        FUN_4097b168(iVar4);
      }
    }
    iVar3 = iVar3 + -1;
    piVar2 = piVar2 + 5;
  } while (iVar3 != 0);
                    /* WARNING: Subroutine does not return */
  FUN_40993258(0x10);
}



/* 40983568 FUN_40983568 */

/* Boundary evidence: original MIPS .pdata 40983568..40983c2f. Semantic name remains unreviewed. */

undefined4
FUN_40983568(undefined4 *param_1,int param_2,uint param_3,undefined4 *param_4,int param_5)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  uint uVar6;
  byte *pbVar7;
  undefined4 *puVar8;
  int iVar9;
  
  iVar9 = param_1[0x136];
  iVar5 = param_1[0xca] * 0x5c + iVar9;
  pbVar7 = (byte *)(iVar5 + 0x62a0);
  uVar1 = FUN_4098267c(param_4,param_5);
  if (param_2 != 0x2300) {
    if (((param_2 == 0x8861) && (param_3 == 0x8862)) && ((uVar1 == 1 || (uVar1 == 0)))) {
      if (uVar1 == *pbVar7) {
        return 0;
      }
      if ((param_1[1] == 1) && (*(int *)(iVar9 + 0x65a0) != 0)) {
        FUN_40980504(param_1);
      }
      *pbVar7 = (byte)uVar1;
      return 0;
    }
    return 0x500;
  }
  if (param_3 < 0x8574) {
    if (param_3 == 0x8573) {
      uVar2 = FUN_40983200((int)param_4,0,param_5);
      iVar3 = __nes(uVar2,0x3f800000);
      if (((iVar3 != 0) && (iVar3 = __nes(uVar2,0x40000000), iVar3 != 0)) &&
         (iVar3 = __nes(uVar2,0x40800000), iVar3 != 0)) {
        return 0x501;
      }
      if ((param_1[1] == 1) && (*(int *)(iVar9 + 0x65a0) != 0)) {
        FUN_40980504(param_1);
      }
      iVar9 = __gts(uVar2,0);
      uVar4 = 0x3f000000;
      if (iVar9 == 0) {
        uVar4 = 0xbf000000;
      }
      uVar2 = __fpadd(uVar4,uVar2);
      uVar2 = __fptoli(uVar2);
      *(undefined4 *)(iVar5 + 0x62e0) = uVar2;
    }
    else {
      if (param_3 != 0xd1c) {
        if (param_3 == 0x2200) {
          uVar6 = 0;
          while (uVar1 != *(uint *)((int)&DAT_40962780 + uVar6)) {
            uVar6 = uVar6 + 4;
            if (0x17 < uVar6) {
              return 0x500;
            }
          }
          if (uVar1 == *(uint *)(iVar5 + 0x62a4)) {
            return 0;
          }
          if ((param_1[1] == 1) && (*(int *)(iVar9 + 0x65a0) != 0)) {
            FUN_40980504(param_1);
          }
          *(uint *)(iVar5 + 0x62a4) = uVar1;
        }
        else {
          if (param_3 == 0x2201) {
            if (param_5 == 3) {
              param_5 = 2;
            }
            if ((param_1[1] == 1) && (*(int *)(iVar9 + 0x65a0) != 0)) {
              FUN_40980504(param_1);
            }
            uVar1 = 0;
            puVar8 = (undefined4 *)(iVar5 + 0x62e8);
            do {
              uVar2 = FUN_40983200((int)param_4,uVar1,param_5);
              iVar5 = __lts(uVar2,0);
              if (iVar5 == 0) {
                iVar5 = __gts(uVar2,0x3f800000);
                if (iVar5 != 0) {
                  uVar2 = 0x3f800000;
                }
              }
              else {
                uVar2 = 0;
              }
              uVar1 = uVar1 + 1;
              *puVar8 = uVar2;
              puVar8 = puVar8 + 1;
            } while (uVar1 < 4);
            return 0;
          }
          if (param_3 == 0x8571) {
            if ((param_1[1] == 1) && (*(int *)(iVar9 + 0x65a0) != 0)) {
              FUN_40980504(param_1);
            }
            uVar6 = 0;
            while (uVar1 != *(uint *)((int)&DAT_40962798 + uVar6)) {
              uVar6 = uVar6 + 4;
              if (0x1f < uVar6) {
                return 0x500;
              }
            }
            if (*(uint *)(iVar5 + 0x62a8) == uVar1) {
              return 0;
            }
            *(uint *)(iVar5 + 0x62a8) = uVar1;
          }
          else {
            if (param_3 != 0x8572) {
              return 0x500;
            }
            if ((param_1[1] == 1) && (*(int *)(iVar9 + 0x65a0) != 0)) {
              FUN_40980504(param_1);
            }
            uVar6 = 0;
            while (uVar1 != *(uint *)((int)&DAT_409627b8 + uVar6)) {
              uVar6 = uVar6 + 4;
              if (0x17 < uVar6) {
                return 0x500;
              }
            }
            if (*(uint *)(iVar5 + 0x62ac) == uVar1) {
              return 0;
            }
            *(uint *)(iVar5 + 0x62ac) = uVar1;
          }
        }
        goto LAB_40983c1c;
      }
      uVar2 = FUN_40983200((int)param_4,0,param_5);
      iVar3 = __nes(uVar2,0x3f800000);
      if (((iVar3 != 0) && (iVar3 = __nes(uVar2,0x40000000), iVar3 != 0)) &&
         (iVar3 = __nes(uVar2,0x40800000), iVar3 != 0)) {
        return 0x501;
      }
      if ((param_1[1] == 1) && (*(int *)(iVar9 + 0x65a0) != 0)) {
        FUN_40980504(param_1);
      }
      iVar9 = __gts(uVar2,0);
      uVar4 = 0x3f000000;
      if (iVar9 == 0) {
        uVar4 = 0xbf000000;
      }
      uVar2 = __fpadd(uVar4,uVar2);
      uVar2 = __fptoli(uVar2);
      *(undefined4 *)(iVar5 + 0x62e4) = uVar2;
    }
    if (*(int *)(iVar5 + 0x62a4) != 0x8570) {
      return 0;
    }
  }
  else {
    switch(param_3) {
    case 0x8580:
    case 0x8581:
    case 0x8582:
      if ((param_1[1] == 1) && (*(int *)(iVar9 + 0x65a0) != 0)) {
        FUN_40980504(param_1);
      }
      uVar6 = 0;
      while (uVar1 != *(uint *)((int)&DAT_409627d0 + uVar6)) {
        uVar6 = uVar6 + 4;
        if (0xf < uVar6) {
          return 0x500;
        }
      }
      iVar5 = 0x857c;
      break;
    default:
      return 0x500;
    case 0x8588:
    case 0x8589:
    case 0x858a:
      if ((param_1[1] == 1) && (*(int *)(iVar9 + 0x65a0) != 0)) {
        FUN_40980504(param_1);
      }
      uVar6 = 0;
      while (uVar1 != *(uint *)((int)&DAT_409627d0 + uVar6)) {
        uVar6 = uVar6 + 4;
        if (0xf < uVar6) {
          return 0x500;
        }
      }
      iVar5 = 0x8581;
      break;
    case 0x8590:
    case 0x8591:
    case 0x8592:
      if ((param_1[1] == 1) && (*(int *)(iVar9 + 0x65a0) != 0)) {
        FUN_40980504(param_1);
      }
      uVar6 = 0;
      while (uVar1 != *(uint *)((int)&DAT_409627e0 + uVar6)) {
        uVar6 = uVar6 + 4;
        if (0xf < uVar6) {
          return 0x500;
        }
      }
      iVar5 = 0x8586;
      break;
    case 0x8598:
    case 0x8599:
    case 0x859a:
      if ((param_1[1] == 1) && (*(int *)(iVar9 + 0x65a0) != 0)) {
        FUN_40980504(param_1);
      }
      uVar6 = 0;
      while (uVar1 != *(uint *)((int)&DAT_409627f0 + uVar6)) {
        uVar6 = uVar6 + 4;
        if (7 < uVar6) {
          return 0x500;
        }
      }
      iVar5 = 0x858b;
    }
    if (*(uint *)(pbVar7 + (param_3 - iVar5) * 4) == uVar1) {
      return 0;
    }
    *(uint *)(pbVar7 + (param_3 - iVar5) * 4) = uVar1;
  }
LAB_40983c1c:
  FUN_40982af0((int)param_1,param_1[0xca]);
  return 0;
}



/* 40983c30 FUN_40983c30 */

/* Boundary evidence: original MIPS .pdata 40983c30..40983c73. Semantic name remains unreviewed. */

undefined4
FUN_40983c30(undefined4 *param_1,int param_2,uint param_3,undefined4 *param_4,int param_5)

{
  undefined4 uVar1;
  
  if (param_3 == 0x2201) {
    uVar1 = 0x500;
  }
  else if (param_4 == (undefined4 *)0x0) {
    uVar1 = 0;
  }
  else {
    uVar1 = FUN_40983568(param_1,param_2,param_3,param_4,param_5);
  }
  return uVar1;
}



/* 40983c74 FUN_40983c74 */

/* Boundary evidence: original MIPS .pdata 40983c74..40983cc3. Semantic name remains unreviewed. */

undefined4 FUN_40983c74(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = __les(param_2,0);
  if (iVar1 == 0) {
    *(undefined4 *)(param_1 + 0xc) = param_2;
    uVar2 = 0;
  }
  else {
    uVar2 = 0x501;
  }
  return uVar2;
}



/* 40983d74 FUN_40983d74 */

/* Boundary evidence: original MIPS .pdata 40983d74..40983d9b. Semantic name remains unreviewed. */

void FUN_40983d74(void)

{
  undefined4 uVar1;
  
  uVar1 = __litofp();
  __fpmul(uVar1,0x30000000);
  return;
}



/* 40983d9c FUN_40983d9c */

int FUN_40983d9c(uint param_1)

{
  int iVar1;
  
  iVar1 = 0;
  if ((param_1 & 0xffff0000) == 0) {
    iVar1 = 0x10;
  }
  else {
    param_1 = param_1 >> 0x10;
  }
  if ((param_1 & 0xff00) == 0) {
    iVar1 = iVar1 + 8;
  }
  else {
    param_1 = param_1 >> 8;
  }
  return (uint)(byte)(&DAT_4096203c)[param_1] + iVar1;
}



/* 40983de8 FUN_40983de8 */

/* Boundary evidence: original MIPS .pdata 40983de8..40983e5f. Semantic name remains unreviewed. */

void FUN_40983de8(uint param_1)

{
  FUN_40993370();
  if (param_1 != 0) {
    if ((int)param_1 < 0) {
      param_1 = -param_1;
    }
    FUN_40983d9c(param_1);
  }
                    /* WARNING: Subroutine does not return */
  FUN_40993390(0x10);
}



/* 40983e60 FUN_40983e60 */

/* Boundary evidence: original MIPS .pdata 40983e60..40983f0f. Semantic name remains unreviewed. */

undefined4 FUN_40983e60(int param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  
  if (param_1 != 0) {
    if (param_3 == 0) {
      return *(undefined4 *)(param_2 * 4 + param_1);
    }
    if (param_3 == 1) {
      uVar1 = FUN_40983de8(*(uint *)(param_2 * 4 + param_1));
      return uVar1;
    }
    if (param_3 == 2) {
      uVar1 = __litofp(*(undefined4 *)(param_2 * 4 + param_1));
      uVar1 = __fpmul(uVar1,0x30000000);
      return uVar1;
    }
    if (param_3 == 3) {
      uVar1 = __litofp(*(undefined4 *)(param_2 * 4 + param_1));
      return uVar1;
    }
  }
  return 0;
}



/* 40983f10 FUN_40983f10 */

/* Boundary evidence: original MIPS .pdata 40983f10..40983f7f. Semantic name remains unreviewed. */

void FUN_40983f10(undefined4 *param_1,int param_2,undefined4 param_3,int param_4)

{
  undefined4 uVar1;
  int iVar2;
  
  if (param_1 != (undefined4 *)0x0) {
    iVar2 = 0;
    do {
      uVar1 = FUN_40983e60(param_2,iVar2,param_4);
      iVar2 = iVar2 + 1;
      *param_1 = uVar1;
      param_1 = param_1 + 1;
    } while (iVar2 < 3);
  }
  return;
}



/* 40983f80 FUN_40983f80 */

/* Boundary evidence: original MIPS .pdata 40983f80..4098418b. Semantic name remains unreviewed. */

void FUN_40983f80(int param_1,int param_2,int param_3,int param_4)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  FUN_40993370();
  iVar3 = *(int *)(param_1 + 0x4d8);
  if (param_2 != 0x8126) {
    if (param_2 != 0x8127) {
      if (param_2 == 0x8128) {
        uVar2 = FUN_40983e60(param_3,0,param_4);
        iVar4 = __lts(uVar2,0);
        if (iVar4 == 0) {
          *(undefined4 *)(iVar3 + 0x6290) = uVar2;
        }
        goto LAB_40984184;
      }
      if (param_2 != 0x8129) goto LAB_40984184;
      FUN_40983f10((undefined4 *)(iVar3 + 0x6294),param_3,3,param_4);
      iVar5 = *(int *)(param_1 + 0x4d8);
      iVar3 = __nes(*(undefined4 *)(iVar5 + 0x6294),0x3f800000);
      iVar4 = 1;
      if ((iVar3 == 0) && (iVar3 = __nes(*(undefined4 *)(iVar5 + 0x6298),0), iVar3 == 0)) {
        iVar3 = __nes(*(undefined4 *)(iVar5 + 0x629c),0);
        iVar5 = 0;
        if (iVar3 != 0) goto LAB_40984024;
      }
      else {
LAB_40984024:
        iVar5 = 1;
      }
      *(uint *)(*(int *)(param_1 + 0x508) + 0x1c) =
           *(uint *)(*(int *)(param_1 + 0x508) + 0x1c) & 0xfffff7ff | iVar5 << 0xb;
      if ((iVar5 == 0) && (*(char *)(param_1 + 0xa4) == '\0')) {
        iVar4 = 0;
      }
      *(uint *)(*(int *)(param_1 + 0x508) + 0x1c) =
           *(uint *)(*(int *)(param_1 + 0x508) + 0x1c) & 0xffffefff | iVar4 << 0xc;
      goto LAB_40984184;
    }
    uVar2 = FUN_40983e60(param_3,0,param_4);
    iVar3 = __lts(uVar2,0);
    if (iVar3 != 0) goto LAB_40984184;
    iVar3 = __lts(uVar2,0x3e800000);
    uVar1 = 0x3e800000;
    if (iVar3 == 0) {
      iVar3 = __gts(uVar2,0x42c80000);
      uVar1 = 0x42c80000;
      if (iVar3 != 0) goto LAB_4098410c;
    }
    else {
LAB_4098410c:
      uVar2 = uVar1;
    }
    *(undefined4 *)(param_1 + 0x3fc) = uVar2;
    goto LAB_40984184;
  }
  uVar2 = FUN_40983e60(param_3,0,param_4);
  iVar3 = __lts(uVar2,0);
  if (iVar3 != 0) goto LAB_40984184;
  iVar3 = __lts(uVar2,0x3e800000);
  uVar1 = 0x3e800000;
  if (iVar3 == 0) {
    iVar3 = __gts(uVar2,0x42c80000);
    uVar1 = 0x42c80000;
    if (iVar3 != 0) goto LAB_40984178;
  }
  else {
LAB_40984178:
    uVar2 = uVar1;
  }
  *(undefined4 *)(param_1 + 0x3f8) = uVar2;
LAB_40984184:
                    /* WARNING: Subroutine does not return */
  FUN_40993390(0x10);
}



/* 4098418c FUN_4098418c */

/* Boundary evidence: original MIPS .pdata 4098418c..409841bb. Semantic name remains unreviewed. */

undefined4 FUN_4098418c(int param_1,int param_2,int param_3,int param_4)

{
  undefined4 uVar1;
  
  if (param_2 == 0x8129) {
    uVar1 = 0x500;
  }
  else {
    uVar1 = FUN_40983f80(param_1,param_2,param_3,param_4);
  }
  return uVar1;
}



/* 409841bc FUN_409841bc */

/* Boundary evidence: original MIPS .pdata 409841bc..40984247. Semantic name remains unreviewed. */

undefined4 FUN_409841bc(undefined4 *param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = __les(param_2,0);
  if (iVar1 == 0) {
    iVar1 = __nes(param_2,param_1[0x100]);
    if (iVar1 != 0) {
      if ((param_1[1] == 1) && (*(int *)(param_1[0x136] + 0x65a0) != 0)) {
        FUN_40980504(param_1);
      }
      param_1[0x100] = param_2;
    }
    uVar2 = 0;
  }
  else {
    uVar2 = 0x501;
  }
  return uVar2;
}



/* 409842fc FUN_409842fc */

uint FUN_409842fc(uint param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar2 = param_1 >> 10 & 0x1f;
  uVar3 = param_1 & 0x3ff | 0x400;
  uVar1 = 0xe - (param_1 >> 10 & 0xf);
  if ((((param_1 & 0xffff8000) == 0) && (uVar2 != 0)) && ((uVar2 != 0x1f || (param_1 != 0x400)))) {
    if (uVar2 < 0xf) {
      uVar2 = uVar3 << 5;
      if ((uVar1 & 1) != 0) {
        uVar2 = uVar3 << 4;
      }
      if ((uVar1 & 2) != 0) {
        uVar2 = uVar2 >> 2;
      }
      if ((uVar1 & 4) != 0) {
        uVar2 = uVar2 >> 4;
      }
      if ((uVar1 & 8) != 0) {
        uVar2 = uVar2 >> 8;
      }
      uVar1 = (uVar2 - (uVar2 >> 8)) + 0x80 >> 8;
      if (uVar1 < 0x100) {
        return uVar1;
      }
    }
    uVar1 = 0xff;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}



/* 40984424 FUN_40984424 */

/* Boundary evidence: original MIPS .pdata 40984424..4098453b. Semantic name remains unreviewed. */

undefined4 FUN_40984424(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int *piVar4;
  int local_28;
  undefined1 auStack_24 [4];
  undefined1 auStack_20 [4];
  undefined1 auStack_1c [4];
  undefined1 auStack_18 [4];
  undefined1 auStack_14 [4];
  
  iVar3 = *(int *)(param_1 + 0x484);
  if (iVar3 == 0) {
    local_28 = *(int *)(param_1 + 0x4a8);
    goto LAB_409844f8;
  }
  if (iVar3 != -0x48) {
    if (*(int *)(iVar3 + 0x50) == 0x1702) {
      iVar1 = FUN_40979e34(*(int *)(iVar3 + 100));
      piVar4 = *(int **)((iVar1 * 0xd + *(int *)(iVar3 + 0x60)) * 4 +
                        *(int *)(*(int *)(iVar3 + 0x58) + 0x34));
      if (piVar4 != (int *)0x0) {
        iVar3 = *piVar4;
        goto LAB_409844b0;
      }
    }
    else if (*(int *)(iVar3 + 0x50) == 0x8d41) {
      iVar3 = *(int *)(*(int *)(iVar3 + 0x58) + 0x28);
LAB_409844b0:
      if (iVar3 != 0) {
        mali_pixel_format_get_bpc
                  (*(undefined4 *)(iVar3 + 0x14),auStack_14,auStack_18,auStack_1c,auStack_20,
                   auStack_24,&local_28);
        goto LAB_409844f8;
      }
    }
  }
  local_28 = 0;
LAB_409844f8:
  uVar2 = 1;
  if (((*(uint *)(*(int *)(param_1 + 0x504) + 0x40) & 0x10) == 0) || (local_28 < 1)) {
    uVar2 = 0;
  }
  return uVar2;
}



/* 4098453c FUN_4098453c */

void FUN_4098453c(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x504);
  *(char *)(iVar1 + 0x4c) = (char)param_2;
  if ((*(uint *)(iVar1 + 0x40) & 8) == 8) {
    *(uint *)(iVar1 + 8) =
         (*(uint *)(iVar1 + 8) & 0xfffffc00 ^ param_2 << 6 ^ 0x1b) & 0xfff0ffff ^ param_2 << 0x10;
  }
  return;
}



/* 40984594 FUN_40984594 */

void FUN_40984594(int param_1,uint param_2,int param_3)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x504);
  *(char *)(iVar1 + 0x46) = (char)param_2;
  *(char *)(iVar1 + 0x47) = (char)param_3;
  if ((*(uint *)(iVar1 + 0x40) & 8) != 8) {
    if ((*(uint *)(iVar1 + 0x40) & 4) == 0) {
      param_3 = 2;
      param_2 = 2;
    }
    *(uint *)(iVar1 + 8) = (*(uint *)(iVar1 + 8) & 0xfffffff8 ^ param_2) & 0xffffffc7 ^ param_3 << 3
    ;
  }
  return;
}



/* 40984634 FUN_40984634 */

/* Boundary evidence: original MIPS .pdata 40984634..4098469f. Semantic name remains unreviewed. */

undefined4 FUN_40984634(int param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = 0;
  do {
    if (param_2 == *(int *)((int)&DAT_4096289c + uVar2)) {
      iVar1 = FUN_4096c3c8(param_2);
      FUN_4098453c(param_1,iVar1);
      return 0;
    }
    uVar2 = uVar2 + 4;
  } while (uVar2 < 0x40);
  return 0x500;
}



/* 409846a0 FUN_409846a0 */

/* Boundary evidence: original MIPS .pdata 409846a0..40984747. Semantic name remains unreviewed. */

void FUN_409846a0(int param_1,uint param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0x504);
  *(char *)(iVar2 + 0x5a) = (char)param_2;
  *(char *)(iVar2 + 0x5b) = (char)param_3;
  *(char *)(iVar2 + 0x5c) = (char)param_4;
  iVar1 = FUN_40984424(param_1);
  if (iVar1 == 0) {
    param_3 = 0;
    param_4 = 0;
  }
  *(uint *)(iVar2 + 0x18) =
       ((param_2 & 0xffffffc7 ^ param_3 << 3) << 3 ^ *(uint *)(iVar2 + 0x18) & 0xfffffe07) &
       0xfffff1ff ^ param_4 << 9;
  return;
}



/* 40984748 FUN_40984748 */

/* Boundary evidence: original MIPS .pdata 40984748..409847ef. Semantic name remains unreviewed. */

void FUN_40984748(int param_1,uint param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0x504);
  *(char *)(iVar2 + 0x53) = (char)param_2;
  *(char *)(iVar2 + 0x54) = (char)param_3;
  *(char *)(iVar2 + 0x55) = (char)param_4;
  iVar1 = FUN_40984424(param_1);
  if (iVar1 == 0) {
    param_3 = 0;
    param_4 = 0;
  }
  *(uint *)(iVar2 + 0x14) =
       ((param_2 & 0xffffffc7 ^ param_3 << 3) << 3 ^ *(uint *)(iVar2 + 0x14) & 0xfffffe07) &
       0xfffff1ff ^ param_4 << 9;
  return;
}



/* 409847f0 FUN_409847f0 */

/* Boundary evidence: original MIPS .pdata 409847f0..409849c3. Semantic name remains unreviewed. */

void FUN_409847f0(int param_1,uint param_2,int param_3,uint param_4,byte param_5)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  
  iVar3 = *(int *)(param_1 + 0x504);
  uVar2 = (uint)param_5;
  *(char *)(iVar3 + 0x48) = (char)param_2;
  *(char *)(iVar3 + 0x49) = (char)param_3;
  *(char *)(iVar3 + 0x4a) = (char)param_4;
  *(byte *)(iVar3 + 0x4b) = param_5;
  if ((*(uint *)(iVar3 + 0x40) & 8) == 8) {
    return;
  }
  if ((*(uint *)(iVar3 + 0x40) & 4) == 0) {
    param_4 = 0xb;
    param_2 = 0xb;
    uVar2 = 3;
    param_3 = 3;
  }
  FUN_40984594(param_1,(uint)*(byte *)(iVar3 + 0x46),(uint)*(byte *)(iVar3 + 0x47));
  if (*(int *)(param_1 + 0x484) == 0) {
    iVar1 = *(int *)(param_1 + 0x4a0);
  }
  else {
    iVar1 = FUN_40971460(*(int *)(param_1 + 0x484),0xd55);
  }
  if (iVar1 != 0) goto LAB_40984940;
  if (param_2 == 4) {
LAB_409848bc:
    param_2 = 3;
  }
  else if (param_2 == 0x11) {
    param_2 = 0xb;
  }
  else if (param_2 == 0x19) goto LAB_409848bc;
  if (param_3 == 4) {
LAB_409848dc:
    param_3 = 3;
  }
  else if (param_3 == 0x11) {
    param_3 = 0xb;
  }
  else if (param_3 == 0x19) goto LAB_409848dc;
  if ((param_4 == 4) || (param_4 == 0x11)) {
    param_4 = 0xb;
  }
  else if (param_4 == 0x19) {
    param_4 = 3;
  }
  if ((uVar2 == 4) || (uVar2 == 0x11)) {
    uVar2 = 0xb;
  }
  else if (uVar2 == 0x19) {
    uVar2 = 3;
  }
LAB_40984940:
  if (param_4 == 4) {
    param_4 = 0xb;
  }
  *(uint *)(iVar3 + 8) =
       ((param_2 & 0xffffc01f ^ param_3 << 5) << 6 ^ *(uint *)(iVar3 + 8) & 0xfff0003f) & 0xff0fffff
       ^ ((uVar2 & 0xf) << 4 ^ param_4 & 0xf) << 0x10;
  return;
}



/* 409849c4 FUN_409849c4 */

uint FUN_409849c4(uint param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar2 = (int)param_1 >> 0x17 & 0xff;
  if ((uVar2 == 0xff) && ((param_1 & 0x7fffff) != 0)) {
    uVar1 = 0xffff;
  }
  else {
    uVar4 = (param_1 & 0x7fffff | 0x800000) >> 0xd;
    uVar3 = uVar2 - 0x70;
    uVar1 = (uint)((param_1 & 0x80000000) != 0) << 0xf;
    if (0x7ff < uVar4) {
      uVar4 = 0;
      uVar3 = uVar2 - 0x6f;
    }
    if ((int)uVar3 < 0x20) {
      if (-1 < (int)uVar3) {
        uVar1 = uVar4 & 0xfbff | (uVar3 & 0x3f) << 10 | uVar1;
      }
    }
    else {
      uVar1 = uVar1 | 0x7c00;
    }
  }
  return uVar1;
}



/* 40984a70 FUN_40984a70 */

/* Boundary evidence: original MIPS .pdata 40984a70..40984b1f. Semantic name remains unreviewed. */

void FUN_40984a70(int param_1,uint param_2,uint param_3)

{
  int iVar1;
  uint uVar2;
  
  FUN_40993370();
  uVar2 = 0;
  do {
    if (param_2 == *(uint *)((int)&DAT_40962858 + uVar2)) {
      uVar2 = 0;
      goto LAB_40984abc;
    }
    uVar2 = uVar2 + 4;
  } while (uVar2 < 0x24);
  goto LAB_40984b18;
  while (uVar2 = uVar2 + 4, uVar2 < 0x20) {
LAB_40984abc:
    if (param_3 == *(uint *)((int)&DAT_4096287c + uVar2)) {
      iVar1 = FUN_4096bf68(param_3);
      uVar2 = FUN_4096bf68(param_2);
      FUN_409847f0(param_1,uVar2,iVar1,uVar2,(byte)iVar1);
      break;
    }
  }
LAB_40984b18:
                    /* WARNING: Subroutine does not return */
  FUN_40993390(0x18);
}



/* 40984b20 FUN_40984b20 */

/* Boundary evidence: original MIPS .pdata 40984b20..40984c3b. Semantic name remains unreviewed. */

undefined4 FUN_40984b20(int param_1,undefined4 param_2,uint param_3,uint param_4,uint param_5)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  uVar3 = 0;
  do {
    if (param_3 == *(uint *)((int)&DAT_40962840 + uVar3)) {
      uVar3 = 0;
      do {
        if (param_4 == *(uint *)((int)&DAT_40962840 + uVar3)) {
          uVar3 = 0;
          do {
            if (param_5 == *(uint *)((int)&DAT_40962840 + uVar3)) {
              uVar3 = FUN_4096c124(param_3);
              iVar1 = FUN_4096c124(param_4);
              iVar2 = FUN_4096c124(param_5);
              FUN_40984748(param_1,uVar3,iVar1,iVar2);
              FUN_409846a0(param_1,uVar3,iVar1,iVar2);
              return 0;
            }
            uVar3 = uVar3 + 4;
          } while (uVar3 < 0x18);
          return 0x500;
        }
        uVar3 = uVar3 + 4;
      } while (uVar3 < 0x18);
      return 0x500;
    }
    uVar3 = uVar3 + 4;
  } while (uVar3 < 0x18);
  return 0x500;
}



/* 40984c3c FUN_40984c3c */

/* Boundary evidence: original MIPS .pdata 40984c3c..40984cbf. Semantic name remains unreviewed. */

void FUN_40984c3c(int param_1,uint param_2,uint param_3)

{
  uint uVar1;
  int iVar2;
  
  FUN_40993370();
  uVar1 = FUN_409849c4(param_3);
  uVar1 = FUN_409842fc(uVar1);
  *(uint *)(*(int *)(param_1 + 0x504) + 0x78) = param_3;
  iVar2 = *(int *)(param_1 + 0x504);
  *(char *)(iVar2 + 0x44) = (char)param_2;
  *(char *)(iVar2 + 0x45) = (char)uVar1;
  if ((*(uint *)(iVar2 + 0x40) & 1) == 0) {
    param_2 = 7;
  }
  *(uint *)(iVar2 + 0x20) = *(uint *)(iVar2 + 0x20) & 0xfffffff8 ^ param_2;
                    /* WARNING: Subroutine does not return */
  *(uint *)(iVar2 + 0x1c) = (uVar1 & 0xff) << 0x10 ^ *(uint *)(iVar2 + 0x1c) & 0xffff;
  FUN_40993390(0x10);
}



/* 40984cc0 FUN_40984cc0 */

/* Boundary evidence: original MIPS .pdata 40984cc0..40984d87. Semantic name remains unreviewed. */

undefined4 FUN_40984cc0(int param_1,int param_2,uint param_3)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  
  uVar2 = 0;
  do {
    if (param_2 == *(int *)((int)&DAT_40962820 + uVar2)) {
      uVar2 = FUN_4096c25c(param_2);
      iVar1 = __lts(param_3,0);
      if (iVar1 == 0) {
        iVar1 = __gts(param_3,0x3f800000);
        uVar3 = 0x3f800000;
        if (iVar1 == 0) {
          uVar3 = param_3;
        }
      }
      else {
        uVar3 = 0;
      }
      FUN_40984c3c(param_1,uVar2,uVar3);
      return 0;
    }
    uVar2 = uVar2 + 4;
  } while (uVar2 < 0x20);
  return 0x500;
}



/* 40984e08 FUN_40984e08 */

/* Boundary evidence: original MIPS .pdata 40984e08..40984efb. Semantic name remains unreviewed. */

void FUN_40984e08(int param_1,int param_2,uint param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  
  iVar2 = *(int *)(param_1 + 0x4d8);
  uVar4 = ~(1 << (param_3 & 0x1f)) & (uint)*(byte *)(iVar2 + 0x626b);
  *(char *)(iVar2 + 0x626b) = (char)uVar4;
  iVar1 = __eqs(0x3f800000,*(undefined4 *)(param_2 + 0x40));
  if ((iVar1 != 0) && (iVar1 = __eqs(0,*(undefined4 *)(param_2 + 0x44)), iVar1 != 0)) {
    iVar1 = __eqs(0,*(undefined4 *)(param_2 + 0x48));
    iVar3 = 0;
    if (iVar1 != 0) goto LAB_40984e94;
  }
  iVar3 = 1;
LAB_40984e94:
  uVar4 = iVar3 << (param_3 & 0x1f) & 0xffU | uVar4;
  *(char *)(iVar2 + 0x626b) = (char)uVar4;
  *(uint *)(*(int *)(param_1 + 0x508) + 0x1c) =
       *(uint *)(*(int *)(param_1 + 0x508) + 0x1c) & 0xffffffdf |
       (uint)((*(byte *)(iVar2 + 0x626c) & uVar4) != 0) << 5;
  return;
}



/* 40984f80 FUN_40984f80 */

/* Boundary evidence: original MIPS .pdata 40984f80..40984fa7. Semantic name remains unreviewed. */

void FUN_40984f80(void)

{
  undefined4 uVar1;
  
  uVar1 = __litofp();
  __fpmul(uVar1,0x30000000);
  return;
}



/* 40984fa8 FUN_40984fa8 */

int FUN_40984fa8(uint param_1)

{
  int iVar1;
  
  iVar1 = 0;
  if ((param_1 & 0xffff0000) == 0) {
    iVar1 = 0x10;
  }
  else {
    param_1 = param_1 >> 0x10;
  }
  if ((param_1 & 0xff00) == 0) {
    iVar1 = iVar1 + 8;
  }
  else {
    param_1 = param_1 >> 8;
  }
  return (uint)(byte)(&DAT_4096203c)[param_1] + iVar1;
}



/* 40984ff4 FUN_40984ff4 */

/* Boundary evidence: original MIPS .pdata 40984ff4..409851af. Semantic name remains unreviewed. */

void FUN_40984ff4(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  
  FUN_409933b0();
  uVar4 = param_3[1];
  uVar6 = param_3[3];
  uVar5 = param_3[2];
  uVar3 = *param_3;
  uVar1 = __fpmul(param_2[4],uVar4);
  uVar2 = __fpmul(param_2[8],uVar5);
  uVar1 = __fpadd(uVar1,uVar2);
  uVar2 = __fpmul(param_2[0xc],uVar6);
  uVar1 = __fpadd(uVar1,uVar2);
  uVar2 = __fpmul(*param_2,uVar3);
  uVar1 = __fpadd(uVar1,uVar2);
  *param_1 = uVar1;
  uVar1 = __fpmul(param_2[1],uVar3);
  uVar2 = __fpmul(param_2[5],uVar4);
  uVar1 = __fpadd(uVar1,uVar2);
  uVar2 = __fpmul(param_2[9],uVar5);
  uVar1 = __fpadd(uVar1,uVar2);
  uVar2 = __fpmul(param_2[0xd],uVar6);
  uVar1 = __fpadd(uVar1,uVar2);
  param_1[1] = uVar1;
  uVar1 = __fpmul(param_2[2],uVar3);
  uVar2 = __fpmul(param_2[6],uVar4);
  uVar1 = __fpadd(uVar1,uVar2);
  uVar2 = __fpmul(param_2[10],uVar5);
  uVar1 = __fpadd(uVar1,uVar2);
  uVar2 = __fpmul(param_2[0xe],uVar6);
  uVar1 = __fpadd(uVar1,uVar2);
  param_1[2] = uVar1;
  uVar1 = __fpmul(param_2[3],uVar3);
  uVar2 = __fpmul(param_2[7],uVar4);
  uVar1 = __fpadd(uVar1,uVar2);
  uVar2 = __fpmul(param_2[0xb],uVar5);
  uVar1 = __fpadd(uVar1,uVar2);
  uVar2 = __fpmul(param_2[0xf],uVar6);
  uVar1 = __fpadd(uVar1,uVar2);
  param_1[3] = uVar1;
                    /* WARNING: Subroutine does not return */
  FUN_409933e0(0x10);
}



/* 409851b0 FUN_409851b0 */

/* Boundary evidence: original MIPS .pdata 409851b0..409852df. Semantic name remains unreviewed. */

void FUN_409851b0(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  
  uVar4 = param_3[1];
  uVar5 = param_3[2];
  uVar3 = *param_3;
  uVar1 = __fpmul(param_2[4],uVar4);
  uVar2 = __fpmul(param_2[8],uVar5);
  uVar1 = __fpadd(uVar1,uVar2);
  uVar2 = __fpmul(*param_2,uVar3);
  uVar1 = __fpadd(uVar1,uVar2);
  *param_1 = uVar1;
  uVar1 = __fpmul(param_2[1],uVar3);
  uVar2 = __fpmul(param_2[5],uVar4);
  uVar1 = __fpadd(uVar1,uVar2);
  uVar2 = __fpmul(param_2[9],uVar5);
  uVar1 = __fpadd(uVar1,uVar2);
  param_1[1] = uVar1;
  uVar1 = __fpmul(param_2[2],uVar3);
  uVar2 = __fpmul(param_2[6],uVar4);
  uVar1 = __fpadd(uVar1,uVar2);
  uVar2 = __fpmul(param_2[10],uVar5);
  uVar1 = __fpadd(uVar1,uVar2);
  param_1[2] = uVar1;
  return;
}



/* 409852e0 FUN_409852e0 */

void FUN_409852e0(int param_1)

{
  int iVar1;
  uint *puVar2;
  undefined1 *puVar3;
  uint uVar4;
  uint uVar5;
  
  iVar1 = *(int *)(param_1 + 0x4cc);
  puVar3 = (undefined1 *)(iVar1 + 0x5f10);
  *puVar3 = 0;
  *(undefined4 *)(iVar1 + 0x5f14) = 0x3e4ccccd;
  *(undefined4 *)(iVar1 + 0x5f18) = 0x3e4ccccd;
  *(undefined4 *)(iVar1 + 0x5f1c) = 0x3e4ccccd;
  *(undefined4 *)(iVar1 + 0x5f20) = 0x3f800000;
  *(undefined4 *)(iVar1 + 0x5f24) = 0x3f4ccccd;
  *(undefined4 *)(iVar1 + 0x5f28) = 0x3f4ccccd;
  *(undefined4 *)(iVar1 + 0x5f2c) = 0x3f4ccccd;
  *(undefined4 *)(iVar1 + 0x5f30) = 0x3f800000;
  *(undefined4 *)(iVar1 + 0x5f34) = 0;
  *(undefined4 *)(iVar1 + 0x5f38) = 0;
  *(undefined4 *)(iVar1 + 0x5f3c) = 0;
  *(undefined4 *)(iVar1 + 0x5f40) = 0x3f800000;
  *(undefined4 *)(iVar1 + 0x5f44) = 0;
  *(undefined4 *)(iVar1 + 0x5f48) = 0;
  *(undefined4 *)(iVar1 + 0x5f4c) = 0;
  *(undefined4 *)(iVar1 + 0x5f50) = 0x3f800000;
  *(undefined4 *)(iVar1 + 0x5f54) = 0;
  *(undefined4 *)(iVar1 + 0x5f58) = 0x3e4ccccd;
  *(undefined4 *)(iVar1 + 0x5f5c) = 0x3e4ccccd;
  *(undefined4 *)(iVar1 + 0x5f60) = 0x3e4ccccd;
  *(undefined4 *)(iVar1 + 0x5f64) = 0x3f800000;
  uVar4 = 0;
  do {
    puVar2 = (uint *)(((int)uVar4 >> 5) * 4 + param_1);
    *puVar2 = ~(1 << (uVar4 & 0x1f)) & *puVar2;
    *(undefined4 *)(puVar3 + uVar4 * 0x60 + 0x58) = 0;
    *(undefined4 *)(puVar3 + uVar4 * 0x60 + 0x5c) = 0;
    *(undefined4 *)(puVar3 + uVar4 * 0x60 + 0x60) = 0;
    *(undefined4 *)(puVar3 + uVar4 * 0x60 + 100) = 0x3f800000;
    *(undefined4 *)(puVar3 + uVar4 * 0x60 + 0x74) = 0x3f800000;
    *(undefined4 *)(puVar3 + uVar4 * 0x60 + 0x84) = 0x3f800000;
    if (uVar4 == 0) {
      *(undefined4 *)(puVar3 + 0x68) = 0x3f800000;
      *(undefined4 *)(puVar3 + 0x6c) = 0x3f800000;
      *(undefined4 *)(puVar3 + 0x70) = 0x3f800000;
      *(undefined4 *)(puVar3 + 0x78) = 0x3f800000;
      *(undefined4 *)(puVar3 + 0x7c) = 0x3f800000;
      *(undefined4 *)(puVar3 + 0x80) = 0x3f800000;
    }
    else {
      *(undefined4 *)(puVar3 + uVar4 * 0x60 + 0x68) = 0;
      *(undefined4 *)(puVar3 + uVar4 * 0x60 + 0x6c) = 0;
      *(undefined4 *)(puVar3 + uVar4 * 0x60 + 0x70) = 0;
      *(undefined4 *)(puVar3 + uVar4 * 0x60 + 0x78) = 0;
      *(undefined4 *)(puVar3 + uVar4 * 0x60 + 0x7c) = 0;
      *(undefined4 *)(puVar3 + uVar4 * 0x60 + 0x80) = 0;
    }
    *(undefined4 *)(puVar3 + uVar4 * 0x60 + 0x88) = 0;
    *(undefined4 *)(puVar3 + uVar4 * 0x60 + 0x8c) = 0;
    uVar5 = uVar4 + 1;
    *(undefined4 *)(puVar3 + uVar4 * 0x60 + 0x90) = 0x3f800000;
    *(undefined4 *)(puVar3 + uVar4 * 0x60 + 0x94) = 0;
    *(undefined4 *)(puVar3 + uVar4 * 0x60 + 0x98) = 0x3f800000;
    *(undefined4 *)(puVar3 + uVar4 * 0x60 + 0x9c) = 0;
    *(undefined4 *)(puVar3 + uVar4 * 0x60 + 0xa0) = 0;
    *(undefined4 *)(puVar3 + uVar4 * 0x60 + 0xa4) = 0;
    *(undefined4 *)(puVar3 + uVar4 * 0x60 + 0xa8) = 0;
    *(undefined4 *)(puVar3 + uVar4 * 0x60 + 0xac) = 0xbf800000;
    *(undefined4 *)(puVar3 + uVar4 * 0x60 + 0xb0) = 0;
    *(undefined4 *)(puVar3 + uVar4 * 0x60 + 0xb4) = 0xbf800000;
    *(undefined4 *)(puVar3 + (uVar4 + 0xd8) * 4) = 0x43340000;
    uVar4 = uVar5;
  } while (uVar5 < 8);
  *(undefined1 *)(iVar1 + 0x6268) = 0;
  *(undefined1 *)(iVar1 + 0x6269) = 0;
  *(undefined1 *)(iVar1 + 0x626b) = 0;
  *(undefined1 *)(iVar1 + 0x626a) = 0;
  *(undefined1 *)(iVar1 + 0x626c) = 0;
  return;
}



/* 40985470 FUN_40985470 */

/* Boundary evidence: original MIPS .pdata 40985470..409854db. Semantic name remains unreviewed. */

void FUN_40985470(uint param_1)

{
  FUN_40993370();
  if ((int)param_1 < 0) {
    param_1 = -param_1;
  }
  FUN_40984fa8(param_1);
                    /* WARNING: Subroutine does not return */
  FUN_40993390(0x10);
}



/* 409854dc FUN_409854dc */

/* Boundary evidence: original MIPS .pdata 409854dc..409854f7. Semantic name remains unreviewed. */

void FUN_409854dc(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3)

{
  FUN_40984ff4(param_1,param_2,param_3);
  return;
}



/* 409854f8 FUN_409854f8 */

void FUN_409854f8(int param_1)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = *(int *)(param_1 + 0x508);
  iVar2 = 0;
  if (((*(uint *)(iVar3 + 0x1c) & 0x100) != 0) &&
     (*(char *)(*(int *)(param_1 + 0x4d8) + 0x5f10) != '\0')) {
    uVar1 = 0;
    do {
      if ((*(uint *)(((int)uVar1 >> 5) * 4 + param_1 + 0xc) >> (uVar1 & 0x1f) & 1) != 0) {
        iVar2 = 1;
        break;
      }
      uVar1 = uVar1 + 1;
    } while ((int)uVar1 < 8);
  }
  *(uint *)(iVar3 + 0x20) = *(uint *)(iVar3 + 0x20) & 0xdfffffff ^ iVar2 << 0x1d;
  return;
}



/* 40985584 FUN_40985584 */

/* Boundary evidence: original MIPS .pdata 40985584..4098563f. Semantic name remains unreviewed. */

undefined4 FUN_40985584(int param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  uint uVar2;
  
  if (param_1 != 0) {
    if (param_3 == 0) {
      return *(undefined4 *)(param_2 * 4 + param_1);
    }
    if (param_3 == 1) {
      uVar2 = *(uint *)(param_2 * 4 + param_1);
      if (uVar2 != 0) {
        uVar1 = FUN_40985470(uVar2);
        return uVar1;
      }
    }
    else {
      if (param_3 == 2) {
        uVar1 = __litofp(*(undefined4 *)(param_2 * 4 + param_1));
        uVar1 = __fpmul(uVar1,0x30000000);
        return uVar1;
      }
      if (param_3 == 3) {
        uVar1 = __litofp(*(undefined4 *)(param_2 * 4 + param_1));
        return uVar1;
      }
    }
  }
  return 0;
}



/* 40985640 FUN_40985640 */

/* Boundary evidence: original MIPS .pdata 40985640..40985697. Semantic name remains unreviewed. */

void FUN_40985640(undefined4 *param_1,int param_2,int param_3,int param_4)

{
  undefined4 uVar1;
  int iVar2;
  
  FUN_40993230();
  if ((param_1 != (undefined4 *)0x0) && (iVar2 = 0, 0 < param_3)) {
    do {
      uVar1 = FUN_40985584(param_2,iVar2,param_4);
      iVar2 = iVar2 + 1;
      *param_1 = uVar1;
      param_1 = param_1 + 1;
    } while (iVar2 < param_3);
  }
                    /* WARNING: Subroutine does not return */
  FUN_40993258(0x10);
}



/* 40985698 FUN_40985698 */

/* Boundary evidence: original MIPS .pdata 40985698..40985b73. Semantic name remains unreviewed. */

void FUN_40985698(int param_1,int param_2,undefined4 param_3,int param_4)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  undefined4 *puVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  undefined4 *puVar10;
  undefined8 uVar11;
  undefined1 auStackX_0 [16];
  int in_stack_00000058;
  
  FUN_40993300();
  uVar8 = param_2 - 0x4000;
  if (((int)uVar8 < 0) || (7 < (int)uVar8)) goto switchD_409856fc_default;
  iVar5 = *(int *)(param_1 + 0x4d8);
  iVar4 = uVar8 * 0x60 + iVar5 + 0x5f10;
  puVar6 = (undefined4 *)(iVar4 + 0x58);
  switch(param_3) {
  case 0x1200:
    if (puVar6 != (undefined4 *)0x0) {
      iVar4 = 0;
      do {
        uVar1 = FUN_40985584(param_4,iVar4,in_stack_00000058);
        iVar4 = iVar4 + 1;
        *puVar6 = uVar1;
        puVar6 = puVar6 + 1;
      } while (iVar4 < 4);
    }
    break;
  case 0x1201:
    if ((undefined4 *)(iVar4 + 0x68) != (undefined4 *)0x0) {
      iVar5 = 0;
      puVar6 = (undefined4 *)(iVar4 + 0x68);
      do {
        uVar1 = FUN_40985584(param_4,iVar5,in_stack_00000058);
        iVar5 = iVar5 + 1;
        *puVar6 = uVar1;
        puVar6 = puVar6 + 1;
      } while (iVar5 < 4);
    }
    break;
  case 0x1202:
    puVar6 = (undefined4 *)(iVar4 + 0x78);
    if (puVar6 != (undefined4 *)0x0) {
      iVar2 = 0;
      puVar10 = puVar6;
      do {
        uVar1 = FUN_40985584(param_4,iVar2,in_stack_00000058);
        iVar2 = iVar2 + 1;
        *puVar10 = uVar1;
        puVar10 = puVar10 + 1;
      } while (iVar2 < 4);
    }
    uVar9 = ~(1 << (uVar8 & 0x1f)) & (uint)*(byte *)(iVar5 + 0x6269);
    *(char *)(iVar5 + 0x6269) = (char)uVar9;
    uVar1 = __fpmul(*(undefined4 *)(iVar5 + 0x5f34),*puVar6);
    iVar2 = __eqs(uVar1,0);
    if (iVar2 == 0) {
LAB_40985850:
      iVar2 = 1;
    }
    else {
      uVar1 = __fpmul(*(undefined4 *)(iVar4 + 0x7c),*(undefined4 *)(iVar5 + 0x5f38));
      iVar2 = __eqs(uVar1,0);
      if (iVar2 == 0) goto LAB_40985850;
      uVar1 = __fpmul(*(undefined4 *)(iVar4 + 0x80),*(undefined4 *)(iVar5 + 0x5f3c));
      iVar4 = __eqs(uVar1,0);
      iVar2 = 0;
      if (iVar4 == 0) goto LAB_40985850;
    }
    uVar9 = iVar2 << (uVar8 & 0x1f) & 0xffU | uVar9;
    *(char *)(iVar5 + 0x6269) = (char)uVar9;
    *(uint *)(*(int *)(param_1 + 0x508) + 0x1c) =
         *(uint *)(*(int *)(param_1 + 0x508) + 0x1c) & 0xffffffbf |
         (uint)((*(byte *)(iVar5 + 0x626c) & uVar9) != 0) << 6;
    break;
  case 0x1203:
    iVar2 = *(int *)(iVar5 + 0x55ac);
    if (auStackX_0 != (undefined1 *)0xfffffff0) {
      iVar7 = 0;
      puVar6 = (undefined4 *)&stack0x00000010;
      do {
        uVar1 = FUN_40985584(param_4,iVar7,in_stack_00000058);
        iVar7 = iVar7 + 1;
        *puVar6 = uVar1;
        puVar6 = puVar6 + 1;
      } while (iVar7 < 4);
    }
    FUN_40984ff4((undefined4 *)(iVar4 + 0x88),(undefined4 *)(iVar2 * 0x40 + iVar5 + 0x5c),
                 (undefined4 *)&stack0x00000010);
    break;
  case 0x1204:
    iVar2 = *(int *)(iVar5 + 0x55ac);
    if (auStackX_0 != (undefined1 *)0xfffffff0) {
      iVar7 = 0;
      puVar6 = (undefined4 *)&stack0x00000010;
      do {
        uVar1 = FUN_40985584(param_4,iVar7,in_stack_00000058);
        iVar7 = iVar7 + 1;
        *puVar6 = uVar1;
        puVar6 = puVar6 + 1;
      } while (iVar7 < 3);
    }
    FUN_409851b0((undefined4 *)(iVar4 + 0xa4),(undefined4 *)(iVar2 * 0x40 + iVar5 + 0x5c),
                 (undefined4 *)&stack0x00000010);
    break;
  case 0x1205:
    uVar1 = FUN_40985584(param_4,0,in_stack_00000058);
    iVar5 = __lts(uVar1,0);
    if ((iVar5 == 0) && (iVar5 = __gts(uVar1,0x43000000), iVar5 == 0)) {
      *(undefined4 *)(iVar4 + 0xb0) = uVar1;
    }
    break;
  case 0x1206:
    uVar1 = FUN_40985584(param_4,0,in_stack_00000058);
    iVar2 = __eqs(0x43340000,uVar1);
    if (iVar2 == 0) {
      iVar2 = __ges(0x42b40000,uVar1);
      if ((iVar2 == 0) || (iVar2 = __les(0,uVar1), iVar2 == 0)) break;
      *(byte *)(iVar5 + 0x6268) = (byte)(1 << (uVar8 & 0x1f)) | *(byte *)(iVar5 + 0x6268);
      uVar11 = __fptodp(uVar1);
      uVar11 = __dpmul((int)uVar11,(int)((ulonglong)uVar11 >> 0x20),0xa2529d39,0x3f91df46);
      uVar3 = __dptofp((int)uVar11,(int)((ulonglong)uVar11 >> 0x20));
      uVar3 = mali_sys_cos(uVar3);
      *(undefined4 *)(iVar4 + 0xb4) = uVar3;
    }
    else {
      *(byte *)(iVar5 + 0x6268) = ~(byte)(1 << (uVar8 & 0x1f)) & *(byte *)(iVar5 + 0x6268);
      *(undefined4 *)(iVar4 + 0xb4) = 0xbf800000;
    }
    *(uint *)(*(int *)(param_1 + 0x508) + 0x1c) =
         *(uint *)(*(int *)(param_1 + 0x508) + 0x1c) & 0xffffff7f |
         (uint)((*(byte *)(iVar5 + 0x626c) & *(byte *)(iVar5 + 0x6268)) != 0) << 7;
    *(undefined4 *)((param_2 + -0x3f28) * 4 + iVar5 + 0x5f10) = uVar1;
    break;
  case 0x1207:
    uVar1 = FUN_40985584(param_4,0,in_stack_00000058);
    iVar5 = __lts(uVar1,0);
    if (iVar5 != 0) break;
    *(undefined4 *)(iVar4 + 0x98) = uVar1;
    goto LAB_40985934;
  case 0x1208:
    uVar1 = FUN_40985584(param_4,0,in_stack_00000058);
    iVar5 = __lts(uVar1,0);
    if (iVar5 != 0) break;
    *(undefined4 *)(iVar4 + 0x9c) = uVar1;
    goto LAB_40985934;
  case 0x1209:
    uVar1 = FUN_40985584(param_4,0,in_stack_00000058);
    iVar5 = __lts(uVar1,0);
    if (iVar5 != 0) break;
    *(undefined4 *)(iVar4 + 0xa0) = uVar1;
LAB_40985934:
    FUN_40984e08(param_1,(int)puVar6,uVar8);
  }
switchD_409856fc_default:
                    /* WARNING: Subroutine does not return */
  FUN_40993338(0x20);
}



/* 40985b74 FUN_40985b74 */

/* Boundary evidence: original MIPS .pdata 40985b74..40985c67. Semantic name remains unreviewed. */

undefined4 FUN_40985b74(int param_1,int param_2,int param_3,int param_4)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int iVar3;
  
  if (param_2 == 0xb52) {
    uVar1 = FUN_40985584(param_3,0,param_4);
    iVar3 = __nes(uVar1,0);
    *(uint *)(*(int *)(param_1 + 0x508) + 0x1c) =
         (uint)(iVar3 != 0) << 8 | *(uint *)(*(int *)(param_1 + 0x508) + 0x1c) & 0xfffffeff;
    FUN_409854f8(param_1);
  }
  else {
    if (param_2 != 0xb53) {
      return 0x500;
    }
    puVar2 = (undefined4 *)(*(int *)(param_1 + 0x4d8) + 0x5f58);
    if (puVar2 != (undefined4 *)0x0) {
      iVar3 = 0;
      do {
        uVar1 = FUN_40985584(param_3,iVar3,param_4);
        iVar3 = iVar3 + 1;
        *puVar2 = uVar1;
        puVar2 = puVar2 + 1;
      } while (iVar3 < 4);
    }
  }
  return 0;
}



/* 40985c68 FUN_40985c68 */

/* Boundary evidence: original MIPS .pdata 40985c68..40985fc7. Semantic name remains unreviewed. */

void FUN_40985c68(int param_1,int param_2,int param_3,int param_4)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  undefined4 *puVar8;
  int in_stack_00000040;
  
  FUN_409933b0();
  iVar2 = *(int *)(param_1 + 0x4d8);
  if (param_2 == 0x408) {
    if (param_3 == 0x1200) {
      if (((*(uint *)(*(int *)(param_1 + 0x508) + 0x1c) & 0x10) == 0) &&
         ((undefined4 *)(iVar2 + 0x5f14) != (undefined4 *)0x0)) {
        iVar5 = 0;
        puVar8 = (undefined4 *)(iVar2 + 0x5f14);
        do {
          uVar1 = FUN_40985584(param_4,iVar5,in_stack_00000040);
          iVar5 = iVar5 + 1;
          *puVar8 = uVar1;
          puVar8 = puVar8 + 1;
        } while (iVar5 < 4);
      }
    }
    else if (param_3 == 0x1201) {
      if (((*(uint *)(*(int *)(param_1 + 0x508) + 0x1c) & 0x10) == 0) &&
         ((undefined4 *)(iVar2 + 0x5f24) != (undefined4 *)0x0)) {
        iVar5 = 0;
        puVar8 = (undefined4 *)(iVar2 + 0x5f24);
        do {
          uVar1 = FUN_40985584(param_4,iVar5,in_stack_00000040);
          iVar5 = iVar5 + 1;
          *puVar8 = uVar1;
          puVar8 = puVar8 + 1;
        } while (iVar5 < 4);
      }
    }
    else if (param_3 == 0x1202) {
      puVar8 = (undefined4 *)(iVar2 + 0x5f34);
      if (puVar8 != (undefined4 *)0x0) {
        iVar5 = 0;
        puVar4 = puVar8;
        do {
          uVar1 = FUN_40985584(param_4,iVar5,in_stack_00000040);
          iVar5 = iVar5 + 1;
          *puVar4 = uVar1;
          puVar4 = puVar4 + 1;
        } while (iVar5 < 4);
      }
      uVar6 = 0;
      puVar4 = (undefined4 *)(iVar2 + 0x5f90);
      do {
        uVar7 = ~(1 << (uVar6 & 0x1f)) & (uint)*(byte *)(iVar2 + 0x6269);
        *(char *)(iVar2 + 0x6269) = (char)uVar7;
        uVar1 = __fpmul(puVar4[-2],*puVar8);
        iVar5 = __eqs(uVar1,0);
        if (iVar5 == 0) {
LAB_40985eb4:
          iVar3 = 1;
        }
        else {
          uVar1 = __fpmul(puVar4[-1],*(undefined4 *)(iVar2 + 0x5f38));
          iVar5 = __eqs(uVar1,0);
          if (iVar5 == 0) goto LAB_40985eb4;
          uVar1 = __fpmul(*(undefined4 *)(iVar2 + 0x5f3c),*puVar4);
          iVar5 = __eqs(uVar1,0);
          iVar3 = 0;
          if (iVar5 == 0) goto LAB_40985eb4;
        }
        uVar7 = iVar3 << (uVar6 & 0x1f) & 0xffU | uVar7;
        *(char *)(iVar2 + 0x6269) = (char)uVar7;
        uVar6 = uVar6 + 1;
        *(uint *)(*(int *)(param_1 + 0x508) + 0x1c) =
             *(uint *)(*(int *)(param_1 + 0x508) + 0x1c) & 0xffffffbf |
             (uint)((*(byte *)(iVar2 + 0x626c) & uVar7) != 0) << 6;
        puVar4 = puVar4 + 0x18;
      } while ((int)uVar6 < 8);
    }
    else if (param_3 == 0x1600) {
      if ((undefined4 *)(iVar2 + 0x5f44) != (undefined4 *)0x0) {
        iVar5 = 0;
        puVar8 = (undefined4 *)(iVar2 + 0x5f44);
        do {
          uVar1 = FUN_40985584(param_4,iVar5,in_stack_00000040);
          iVar5 = iVar5 + 1;
          *puVar8 = uVar1;
          puVar8 = puVar8 + 1;
        } while (iVar5 < 4);
      }
    }
    else if (param_3 == 0x1601) {
      uVar1 = FUN_40985584(param_4,0,in_stack_00000040);
      iVar5 = __lts(uVar1,0);
      if ((iVar5 == 0) && (iVar5 = __gts(uVar1,0x43000000), iVar5 == 0)) {
        *(undefined4 *)(iVar2 + 0x5f54) = uVar1;
      }
    }
    else if ((param_3 == 0x1602) && ((*(uint *)(*(int *)(param_1 + 0x508) + 0x1c) & 0x10) == 0)) {
      if ((undefined4 *)(iVar2 + 0x5f14) != (undefined4 *)0x0) {
        iVar5 = 0;
        puVar8 = (undefined4 *)(iVar2 + 0x5f14);
        do {
          uVar1 = FUN_40985584(param_4,iVar5,in_stack_00000040);
          iVar5 = iVar5 + 1;
          *puVar8 = uVar1;
          puVar8 = puVar8 + 1;
        } while (iVar5 < 4);
      }
      if ((undefined4 *)(iVar2 + 0x5f24) != (undefined4 *)0x0) {
        iVar5 = 0;
        puVar8 = (undefined4 *)(iVar2 + 0x5f24);
        do {
          uVar1 = FUN_40985584(param_4,iVar5,in_stack_00000040);
          iVar5 = iVar5 + 1;
          *puVar8 = uVar1;
          puVar8 = puVar8 + 1;
        } while (iVar5 < 4);
      }
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_409933e0(0x10);
}



/* 40985fc8 FUN_40985fc8 */

/* Boundary evidence: original MIPS .pdata 40985fc8..4098600b. Semantic name remains unreviewed. */

undefined4 FUN_40985fc8(int param_1,int param_2,uint param_3,int param_4)

{
  undefined4 uVar1;
  
  if ((param_3 < 0x1205) || (0x1209 < param_3)) {
    uVar1 = 0x500;
  }
  else {
    uVar1 = FUN_40985698(param_1,param_2,param_3,param_4);
  }
  return uVar1;
}



/* 4098600c FUN_4098600c */

/* Boundary evidence: original MIPS .pdata 4098600c..40986053. Semantic name remains unreviewed. */

undefined4 FUN_4098600c(int param_1,int param_2,int param_3,int param_4)

{
  undefined4 uVar1;
  
  if (param_4 == 0) {
    uVar1 = 0;
  }
  else if (param_3 == 0x1601) {
    uVar1 = FUN_40985c68(param_1,param_2,0x1601,param_4);
  }
  else {
    uVar1 = 0x500;
  }
  return uVar1;
}



/* 40986054 FUN_40986054 */

/* Boundary evidence: original MIPS .pdata 40986054..40986083. Semantic name remains unreviewed. */

undefined4 FUN_40986054(int param_1,int param_2,int param_3,int param_4)

{
  undefined4 uVar1;
  
  if (param_2 == 0xb52) {
    uVar1 = FUN_40985b74(param_1,0xb52,param_3,param_4);
  }
  else {
    uVar1 = 0x500;
  }
  return uVar1;
}



/* 40986084 FUN_40986084 */

/* Boundary evidence: original MIPS .pdata 40986084..4098613f. Semantic name remains unreviewed. */

undefined4 FUN_40986084(int param_1,int param_2,int param_3)

{
  int iVar1;
  int *piVar2;
  uint uVar3;
  int local_10 [4];
  
  local_10[2] = 0x1100;
  iVar1 = *(int *)(param_1 + 0x4cc);
  uVar3 = 0;
  local_10[0] = 0x1101;
  local_10[1] = 0x1102;
  piVar2 = local_10;
  do {
    if (param_3 == *piVar2) {
      if (param_2 == 0xc50) {
        *(int *)(iVar1 + 26000) = param_3;
      }
      else if (param_2 == 0xc51) {
        *(int *)(iVar1 + 0x6594) = param_3;
      }
      else if (param_2 == 0xc52) {
        *(int *)(iVar1 + 0x658c) = param_3;
      }
      else if (param_2 == 0xc54) {
        *(int *)(iVar1 + 0x6584) = param_3;
      }
      else {
        if (param_2 != 0x8192) {
          return 0x500;
        }
        *(int *)(iVar1 + 0x6588) = param_3;
      }
      return 0;
    }
    uVar3 = uVar3 + 1;
    prefetch(piVar2 + 2,0);
    piVar2 = piVar2 + 1;
  } while (uVar3 < 3);
  return 0x500;
}



/* 409861b8 FUN_409861b8 */

void FUN_409861b8(undefined4 *param_1)

{
  undefined4 *puVar1;
  int iVar2;
  
  iVar2 = 8;
  *param_1 = 0x3f800000;
  param_1[1] = 0x3f800000;
  param_1[2] = 0x3f800000;
  param_1[3] = 0x3f800000;
  puVar1 = param_1;
  do {
    puVar1[4] = 0;
    iVar2 = iVar2 + -1;
    puVar1[5] = 0;
    puVar1[6] = 0;
    puVar1[7] = 0x3f800000;
    puVar1 = puVar1 + 4;
  } while (iVar2 != 0);
  param_1[0x24] = 0;
  param_1[0x25] = 0;
  param_1[0x26] = 0x3f800000;
  return;
}



/* 40986200 FUN_40986200 */

/* Boundary evidence: original MIPS .pdata 40986200..409862fb. Semantic name remains unreviewed. */

void FUN_40986200(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 in_stack_00000040;
  
  FUN_409933b0();
  puVar3 = (undefined4 *)param_1[0x136];
  iVar1 = __nes(*puVar3,param_2);
  if ((((iVar1 != 0) || (iVar1 = __nes(puVar3[1],param_3), iVar1 != 0)) ||
      (iVar1 = __nes(puVar3[2],param_4), iVar1 != 0)) ||
     (iVar1 = __nes(puVar3[3],in_stack_00000040), iVar1 != 0)) {
    if ((param_1[1] == 1) && (*(int *)(param_1[0x136] + 0x65a0) != 0)) {
      FUN_40980504(param_1);
    }
    *puVar3 = param_2;
    puVar3[1] = param_3;
    puVar3[2] = param_4;
    puVar3[3] = in_stack_00000040;
    if ((*(uint *)(param_1[0x142] + 0x1c) & 0x10) == 0x10) {
      puVar2 = puVar3 + 0x17c5;
      iVar1 = 4;
      do {
        iVar1 = iVar1 + -1;
        *puVar2 = *puVar3;
        puVar2[4] = *puVar3;
        puVar2 = puVar2 + 1;
        puVar3 = puVar3 + 1;
      } while (iVar1 != 0);
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_409933e0(0x10);
}



/* 40986328 FUN_40986328 */

/* Boundary evidence: original MIPS .pdata 40986328..40986387. Semantic name remains unreviewed. */

undefined4 FUN_40986328(undefined4 *param_1,int param_2)

{
  undefined4 uVar1;
  
  if (param_1 != (undefined4 *)0x0) {
    if (param_2 == 0) {
      uVar1 = __fptoul(*param_1);
      return uVar1;
    }
    if ((param_2 == 1) || ((1 < param_2 && (param_2 < 4)))) {
      return *param_1;
    }
  }
  return 0;
}



/* 409863ac FUN_409863ac */

/* Boundary evidence: original MIPS .pdata 409863ac..409863d3. Semantic name remains unreviewed. */

void FUN_409863ac(void)

{
  undefined4 uVar1;
  
  uVar1 = __litofp();
  __fpmul(uVar1,0x30000000);
  return;
}



/* 409863d4 FUN_409863d4 */

int FUN_409863d4(uint param_1)

{
  int iVar1;
  
  iVar1 = 0;
  if ((param_1 & 0xffff0000) == 0) {
    iVar1 = 0x10;
  }
  else {
    param_1 = param_1 >> 0x10;
  }
  if ((param_1 & 0xff00) == 0) {
    iVar1 = iVar1 + 8;
  }
  else {
    param_1 = param_1 >> 8;
  }
  return (uint)(byte)(&DAT_4096203c)[param_1] + iVar1;
}



/* 40986444 FUN_40986444 */

/* Boundary evidence: original MIPS .pdata 40986444..409864bb. Semantic name remains unreviewed. */

void FUN_40986444(uint param_1)

{
  FUN_40993370();
  if (param_1 != 0) {
    if ((int)param_1 < 0) {
      param_1 = -param_1;
    }
    FUN_409863d4(param_1);
  }
                    /* WARNING: Subroutine does not return */
  FUN_40993390(0x10);
}



/* 40986514 FUN_40986514 */

/* Boundary evidence: original MIPS .pdata 40986514..409865c3. Semantic name remains unreviewed. */

undefined4 FUN_40986514(int param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  
  if (param_1 != 0) {
    if (param_3 == 0) {
      return *(undefined4 *)(param_2 * 4 + param_1);
    }
    if (param_3 == 1) {
      uVar1 = FUN_40986444(*(uint *)(param_2 * 4 + param_1));
      return uVar1;
    }
    if (param_3 == 2) {
      uVar1 = __litofp(*(undefined4 *)(param_2 * 4 + param_1));
      uVar1 = __fpmul(uVar1,0x30000000);
      return uVar1;
    }
    if (param_3 == 3) {
      uVar1 = __litofp(*(undefined4 *)(param_2 * 4 + param_1));
      return uVar1;
    }
  }
  return 0;
}



/* 409865c4 FUN_409865c4 */

/* Boundary evidence: original MIPS .pdata 409865c4..40986633. Semantic name remains unreviewed. */

void FUN_409865c4(undefined4 *param_1,int param_2,undefined4 param_3,int param_4)

{
  undefined4 uVar1;
  int iVar2;
  
  if (param_1 != (undefined4 *)0x0) {
    iVar2 = 0;
    do {
      uVar1 = FUN_40986514(param_2,iVar2,param_4);
      iVar2 = iVar2 + 1;
      *param_1 = uVar1;
      param_1 = param_1 + 1;
    } while (iVar2 < 4);
  }
  return;
}



/* 40986634 FUN_40986634 */

/* Boundary evidence: original MIPS .pdata 40986634..409867c7. Semantic name remains unreviewed. */

undefined4 FUN_40986634(int param_1,int param_2,undefined4 *param_3,int param_4)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = *(int *)(param_1 + 0x4d8);
  if (param_2 == 0xb62) {
    uVar2 = FUN_40986514((int)param_3,0,param_4);
    iVar1 = __lts(uVar2,0);
    if (iVar1 != 0) {
      return 0x501;
    }
    *(undefined4 *)(iVar3 + 0x5f00) = uVar2;
  }
  else if (param_2 == 0xb63) {
    uVar2 = FUN_40986514((int)param_3,0,param_4);
    *(undefined4 *)(iVar3 + 0x5f04) = uVar2;
  }
  else if (param_2 == 0xb64) {
    uVar2 = FUN_40986514((int)param_3,0,param_4);
    *(undefined4 *)(iVar3 + 0x5f08) = uVar2;
  }
  else if (param_2 == 0xb65) {
    iVar1 = FUN_40986328(param_3,param_4);
    if (*(int *)(iVar3 + 0x5f0c) != iVar1) {
      if (iVar1 == 0x800) {
        iVar4 = 2;
      }
      else if (iVar1 == 0x801) {
        iVar4 = 3;
      }
      else {
        if (iVar1 != 0x2601) {
          return 0x500;
        }
        iVar4 = 1;
      }
      *(int *)(iVar3 + 0x5f0c) = iVar1;
      iVar3 = *(int *)(param_1 + 0x508);
      if ((*(uint *)(iVar3 + 0x1c) & 0x2000) == 0) {
        *(uint *)(iVar3 + 0x20) = *(uint *)(iVar3 + 0x20) & 0xe7ffffff;
      }
      else {
        *(uint *)(iVar3 + 0x20) = *(uint *)(iVar3 + 0x20) & 0xe7ffffff ^ iVar4 << 0x1b;
      }
    }
  }
  else {
    if (param_2 != 0xb66) {
      return 0x500;
    }
    FUN_409865c4((undefined4 *)(iVar3 + 0x5ef0),(int)param_3,4,param_4);
  }
  return 0;
}



/* 409867c8 FUN_409867c8 */

/* Boundary evidence: original MIPS .pdata 409867c8..409867f7. Semantic name remains unreviewed. */

undefined4 FUN_409867c8(int param_1,int param_2,undefined4 *param_3,int param_4)

{
  undefined4 uVar1;
  
  if (param_2 == 0xb66) {
    uVar1 = 0x500;
  }
  else {
    uVar1 = FUN_40986634(param_1,param_2,param_3,param_4);
  }
  return uVar1;
}



/* 409869b4 FUN_409869b4 */

/* Boundary evidence: original MIPS .pdata 409869b4..40986a5b. Semantic name remains unreviewed. */

void FUN_409869b4(int param_1,int param_2,int param_3,int param_4)

{
  undefined4 uVar1;
  
  if (param_1 != 0) {
    if (param_4 == 0) {
      uVar1 = __ultofp(param_3);
      *(undefined4 *)(param_2 * 4 + param_1) = uVar1;
    }
    else if (param_4 == 1) {
      *(int *)(param_2 * 4 + param_1) = param_3;
    }
    else if (param_4 == 3) {
      *(int *)(param_2 * 4 + param_1) = param_3;
    }
    else if (param_4 == 4) {
      *(bool *)(param_1 + param_2) = param_3 != 0;
    }
  }
  return;
}



/* 40986a5c FUN_40986a5c */

/* Boundary evidence: original MIPS .pdata 40986a5c..40986b07. Semantic name remains unreviewed. */

void FUN_40986a5c(int param_1,int param_2,int param_3,int param_4)

{
  undefined4 uVar1;
  
  if (param_1 != 0) {
    if (param_4 == 0) {
      uVar1 = __litofp(param_3);
      *(undefined4 *)(param_2 * 4 + param_1) = uVar1;
    }
    else if (param_4 == 1) {
      *(int *)(param_2 * 4 + param_1) = param_3 << 0x10;
    }
    else if (param_4 == 3) {
      *(int *)(param_2 * 4 + param_1) = param_3;
    }
    else if (param_4 == 4) {
      *(bool *)(param_1 + param_2) = param_3 != 0;
    }
  }
  return;
}



/* 40986b08 FUN_40986b08 */

void FUN_40986b08(int param_1,int param_2,int param_3,int param_4)

{
  undefined4 uVar1;
  
  if (param_1 != 0) {
    if (param_4 == 0) {
      if (param_3 == 1) {
        uVar1 = 0x3f800000;
      }
      else {
        uVar1 = 0;
      }
      *(undefined4 *)(param_2 * 4 + param_1) = uVar1;
    }
    else if (param_4 == 1) {
      uVar1 = 0x10000;
      if (param_3 != 1) {
        uVar1 = 0;
      }
      *(undefined4 *)(param_2 * 4 + param_1) = uVar1;
    }
    else if (param_4 == 3) {
      *(int *)(param_2 * 4 + param_1) = param_3;
    }
    else if (param_4 == 4) {
      *(char *)(param_1 + param_2) = (char)param_3;
    }
  }
  return;
}



/* 40986cc8 FUN_40986cc8 */

/* Boundary evidence: original MIPS .pdata 40986cc8..40986d37. Semantic name remains unreviewed. */

undefined4 FUN_40986cc8(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = __eqs(param_1,0x3f800000);
  if (iVar1 == 0) {
    iVar1 = __eqs(param_1,0xbf800000);
    if (iVar1 == 0) {
      uVar2 = __fpmul(param_1,0x4f000000);
      uVar2 = __fptoli(uVar2);
    }
    else {
      uVar2 = 0x80000000;
    }
  }
  else {
    uVar2 = 0x7fffffff;
  }
  return uVar2;
}



/* 40986d38 FUN_40986d38 */

/* Boundary evidence: original MIPS .pdata 40986d38..40986d5b. Semantic name remains unreviewed. */

void FUN_40986d38(undefined4 param_1)

{
  undefined4 uVar1;
  
  uVar1 = __fpmul(param_1,0x47800000);
  __fptoli(uVar1);
  return;
}



/* 40986d5c FUN_40986d5c */

/* Boundary evidence: original MIPS .pdata 40986d5c..40986e1b. Semantic name remains unreviewed. */

undefined4 FUN_40986d5c(int param_1,int param_2,int param_3,int param_4,int param_5)

{
  int iVar1;
  
  if (param_2 != 0xde1) {
    return 0x500;
  }
  iVar1 = *(int *)(*(int *)(param_1 + 0x31c) * 0x14 + param_1 + 0x324);
  if (param_3 == 0x2800) {
    iVar1 = *(int *)(iVar1 + 0x10);
  }
  else if (param_3 == 0x2801) {
    iVar1 = *(int *)(iVar1 + 0xc);
  }
  else if (param_3 == 0x2802) {
    iVar1 = *(int *)(iVar1 + 4);
  }
  else {
    if (param_3 != 0x2803) {
      if (param_3 == 0x8191) {
        FUN_40986b08(param_4,0,(uint)*(byte *)(iVar1 + 0x14),param_5);
        return 0;
      }
      return 0x500;
    }
    iVar1 = *(int *)(iVar1 + 8);
  }
  FUN_409869b4(param_4,0,iVar1,param_5);
  return 0;
}



/* 40986e1c FUN_40986e1c */

/* Boundary evidence: original MIPS .pdata 40986e1c..40986f23. Semantic name remains unreviewed. */

void FUN_40986e1c(int param_1,int param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  undefined4 uVar2;
  
  if (param_1 == 0) {
    return;
  }
  if (param_4 == 0) {
    *(undefined4 *)(param_2 * 4 + param_1) = param_3;
    return;
  }
  if (param_4 == 1) {
    uVar2 = __fpmul(param_3,0x47800000);
  }
  else {
    if (param_4 == 2) {
      uVar2 = FUN_40986cc8(param_3);
      goto LAB_40986eec;
    }
    if (param_4 != 3) {
      if (param_4 != 4) {
        return;
      }
      iVar1 = __nes(param_3,0);
      *(bool *)(param_1 + param_2) = iVar1 != 0;
      return;
    }
    iVar1 = __gts(param_3,0);
    uVar2 = 0x3f000000;
    if (iVar1 == 0) {
      uVar2 = 0xbf000000;
    }
    uVar2 = __fpadd(uVar2,param_3);
  }
  uVar2 = __fptoli(uVar2);
LAB_40986eec:
  *(undefined4 *)(param_2 * 4 + param_1) = uVar2;
  return;
}



/* 40987034 FUN_40987034 */

/* Boundary evidence: original MIPS .pdata 40987034..40987093. Semantic name remains unreviewed. */

void FUN_40987034(undefined4 *param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  
  FUN_40993230();
  iVar1 = 0;
  do {
    iVar2 = 0;
    do {
      FUN_40986e1c(param_2,iVar1 + iVar2,*param_1,param_3);
      iVar2 = iVar2 + 1;
      param_1 = param_1 + 1;
    } while (iVar2 < 4);
    iVar1 = iVar1 + 4;
  } while (iVar1 < 0x10);
                    /* WARNING: Subroutine does not return */
  FUN_40993258(0x10);
}



/* 40987094 FUN_40987094 */

/* Boundary evidence: original MIPS .pdata 40987094..409872cb. Semantic name remains unreviewed. */

undefined4 FUN_40987094(int param_1,int param_2,undefined4 param_3,int param_4,int param_5)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  
  iVar2 = param_2 + -0x4000;
  if ((-1 < iVar2) && (iVar2 < 8)) {
    iVar3 = *(int *)(param_1 + 0x4cc) + 0x5f10;
    iVar2 = iVar2 * 0x60 + iVar3;
    puVar4 = (undefined4 *)(iVar2 + 0x58);
    switch(param_3) {
    case 0x1200:
      if (param_5 == 3) {
        param_5 = 2;
      }
      iVar2 = 0;
      do {
        FUN_40986e1c(param_4,iVar2,*puVar4,param_5);
        iVar2 = iVar2 + 1;
        puVar4 = puVar4 + 1;
      } while (iVar2 < 4);
      return 0;
    case 0x1201:
      if (param_5 == 3) {
        param_5 = 2;
      }
      iVar3 = 0;
      puVar4 = (undefined4 *)(iVar2 + 0x68);
      do {
        FUN_40986e1c(param_4,iVar3,*puVar4,param_5);
        iVar3 = iVar3 + 1;
        puVar4 = puVar4 + 1;
      } while (iVar3 < 4);
      return 0;
    case 0x1202:
      if (param_5 == 3) {
        param_5 = 2;
      }
      iVar3 = 0;
      puVar4 = (undefined4 *)(iVar2 + 0x78);
      do {
        FUN_40986e1c(param_4,iVar3,*puVar4,param_5);
        iVar3 = iVar3 + 1;
        puVar4 = puVar4 + 1;
      } while (iVar3 < 4);
      return 0;
    case 0x1203:
      iVar3 = 0;
      puVar4 = (undefined4 *)(iVar2 + 0x88);
      do {
        FUN_40986e1c(param_4,iVar3,*puVar4,param_5);
        iVar3 = iVar3 + 1;
        puVar4 = puVar4 + 1;
      } while (iVar3 < 4);
      return 0;
    case 0x1204:
      iVar3 = 0;
      puVar4 = (undefined4 *)(iVar2 + 0xa4);
      do {
        FUN_40986e1c(param_4,iVar3,*puVar4,param_5);
        iVar3 = iVar3 + 1;
        puVar4 = puVar4 + 1;
      } while (iVar3 < 3);
      return 0;
    case 0x1205:
      uVar1 = *(undefined4 *)(iVar2 + 0xb0);
      break;
    case 0x1206:
      uVar1 = *(undefined4 *)((param_2 + -0x3f28) * 4 + iVar3);
      break;
    case 0x1207:
      uVar1 = *(undefined4 *)(iVar2 + 0x98);
      break;
    case 0x1208:
      uVar1 = *(undefined4 *)(iVar2 + 0x9c);
      break;
    case 0x1209:
      uVar1 = *(undefined4 *)(iVar2 + 0xa0);
      break;
    default:
      goto LAB_409872b0;
    }
    FUN_40986e1c(param_4,0,uVar1,param_5);
    return 0;
  }
LAB_409872b0:
  return 0x500;
}



/* 409872cc FUN_409872cc */

/* Boundary evidence: original MIPS .pdata 409872cc..409873db. Semantic name remains unreviewed. */

void FUN_409872cc(int param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  int in_stack_00000038;
  
  FUN_40993230();
  if ((param_2 != 0x404) && (param_2 != 0x405)) goto LAB_409873d4;
  if (param_3 == 0xb53) {
    puVar2 = (undefined4 *)(*(int *)(param_1 + 0x4cc) + 0x5f58);
LAB_40987388:
    iVar1 = 4;
  }
  else {
    if (param_3 == 0x1200) {
      puVar2 = (undefined4 *)(*(int *)(param_1 + 0x4cc) + 0x5f14);
      goto LAB_40987388;
    }
    if (param_3 == 0x1201) {
      puVar2 = (undefined4 *)(*(int *)(param_1 + 0x4cc) + 0x5f24);
      goto LAB_40987388;
    }
    if (param_3 == 0x1202) {
      puVar2 = (undefined4 *)(*(int *)(param_1 + 0x4cc) + 0x5f34);
      goto LAB_40987388;
    }
    if (param_3 == 0x1600) {
      puVar2 = (undefined4 *)(*(int *)(param_1 + 0x4cc) + 0x5f44);
      goto LAB_40987388;
    }
    if (param_3 != 0x1601) goto LAB_409873d4;
    puVar2 = (undefined4 *)(*(int *)(param_1 + 0x4cc) + 0x5f54);
    iVar1 = 1;
  }
  if (in_stack_00000038 == 3) {
    in_stack_00000038 = 2;
  }
  iVar3 = 0;
  if (iVar1 != 0) {
    do {
      FUN_40986e1c(param_4,iVar3,*puVar2,in_stack_00000038);
      iVar3 = iVar3 + 1;
      puVar2 = puVar2 + 1;
    } while (iVar3 < iVar1);
  }
LAB_409873d4:
                    /* WARNING: Subroutine does not return */
  FUN_40993258(0x10);
}



/* 409873dc FUN_409873dc */

/* Boundary evidence: original MIPS .pdata 409873dc..40987467. Semantic name remains unreviewed. */

void FUN_409873dc(int param_1,uint param_2,int param_3,int param_4)

{
  int iVar1;
  
  FUN_40993230();
  if ((0x2fff < param_2) && (param_2 < 0x3001)) {
    iVar1 = 0;
    do {
      if (param_2 != 0x3000) break;
      FUN_40986e1c(param_3,iVar1,*(undefined4 *)((iVar1 + 0x1577) * 4 + *(int *)(param_1 + 0x4cc)),
                   param_4);
      iVar1 = iVar1 + 1;
    } while (iVar1 < 4);
  }
                    /* WARNING: Subroutine does not return */
  FUN_40993258(0x10);
}



/* 40987468 FUN_40987468 */

/* Boundary evidence: original MIPS .pdata 40987468..40987683. Semantic name remains unreviewed. */

undefined4 FUN_40987468(int param_1,int param_2,uint param_3,int param_4,int param_5)

{
  uint uVar1;
  int iVar2;
  byte *pbVar3;
  int iVar4;
  undefined4 *puVar5;
  
  iVar2 = *(int *)(param_1 + 0x31c) * 0x5c + *(int *)(param_1 + 0x4cc);
  pbVar3 = (byte *)(iVar2 + 0x62a0);
  if (param_2 != 0x2300) {
    if ((param_2 != 0x8861) || (param_3 != 0x8862)) {
LAB_40987668:
      return 0x500;
    }
    uVar1 = (uint)*pbVar3;
LAB_4098758c:
    FUN_40986a5c(param_4,0,uVar1,param_5);
    return 0;
  }
  if (param_3 < 0x8574) {
    if (param_3 == 0x8573) {
      uVar1 = *(uint *)(iVar2 + 0x62e0);
    }
    else {
      if (param_3 != 0xd1c) {
        if (param_3 == 0x2200) {
          iVar2 = *(int *)(iVar2 + 0x62a4);
        }
        else {
          if (param_3 == 0x2201) {
            if (param_5 == 3) {
              param_5 = 2;
            }
            iVar4 = 0;
            puVar5 = (undefined4 *)(iVar2 + 0x62e8);
            do {
              FUN_40986e1c(param_4,iVar4,*puVar5,param_5);
              iVar4 = iVar4 + 1;
              puVar5 = puVar5 + 1;
            } while (iVar4 < 4);
            return 0;
          }
          if (param_3 == 0x8571) {
            iVar2 = *(int *)(iVar2 + 0x62a8);
          }
          else {
            if (param_3 != 0x8572) {
              return 0x500;
            }
            iVar2 = *(int *)(iVar2 + 0x62ac);
          }
        }
        goto LAB_4098764c;
      }
      uVar1 = *(uint *)(iVar2 + 0x62e4);
    }
    goto LAB_4098758c;
  }
  switch(param_3) {
  case 0x8580:
  case 0x8581:
  case 0x8582:
    iVar2 = *(int *)(pbVar3 + (param_3 - 0x857c) * 4);
    goto LAB_4098764c;
  default:
    goto LAB_40987668;
  case 0x8588:
  case 0x8589:
  case 0x858a:
    iVar2 = 0x8581;
    break;
  case 0x8590:
  case 0x8591:
  case 0x8592:
    iVar2 = 0x8586;
    break;
  case 0x8598:
  case 0x8599:
  case 0x859a:
    iVar2 = 0x858b;
  }
  iVar2 = *(int *)(pbVar3 + (param_3 - iVar2) * 4);
LAB_4098764c:
  FUN_409869b4(param_4,0,iVar2,param_5);
  return 0;
}



/* 40987ab8 FUN_40987ab8 */

/* Boundary evidence: original MIPS .pdata 40987ab8..409889bb. Semantic name remains unreviewed. */

undefined4 FUN_40987ab8(int param_1,uint param_2,int param_3,int param_4)

{
  byte bVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  undefined4 *puVar5;
  int *piVar6;
  int local_48 [12];
  
  local_48[0] = 0x8b90;
  local_48[5] = 0x8b95;
  local_48[1] = 0x8b91;
  local_48[2] = 0x8b92;
  local_48[3] = 0x8b93;
  local_48[4] = 0x8b94;
  local_48[10] = 0x8d64;
  iVar4 = param_1 + 0xc;
  puVar5 = *(undefined4 **)(param_1 + 0x4d8);
  local_48[6] = 0x8b96;
  local_48[7] = 0x8b97;
  local_48[8] = 0x8b98;
  local_48[9] = 0x8b99;
  if (param_2 < 0xd3b) {
    if (param_2 == 0xd3a) {
      FUN_40986a5c(param_3,0,0x1000,param_4);
      uVar3 = 0x1000;
      iVar4 = 1;
      goto LAB_40988670;
    }
    if (param_2 < 0xb99) {
      if (param_2 == 0xb98) {
        bVar1 = *(byte *)(*(int *)(param_1 + 0x504) + 0x52);
LAB_40987f60:
        uVar3 = (uint)bVar1;
      }
      else {
        if (param_2 < 0xb65) {
          if (param_2 == 0xb64) {
            uVar2 = puVar5[0x17c2];
          }
          else if (param_2 < 0xb46) {
            if (param_2 == 0xb45) {
              iVar4 = *(int *)(param_1 + 0x3f0);
              goto LAB_4098846c;
            }
            if (param_2 == 0xb00) {
              if (param_4 == 3) {
                param_4 = 2;
              }
              iVar4 = 0;
              do {
                FUN_40986e1c(param_3,iVar4,*puVar5,param_4);
                iVar4 = iVar4 + 1;
                puVar5 = puVar5 + 1;
              } while (iVar4 < 4);
              return 0;
            }
            if (param_2 == 0xb02) {
              if (param_4 == 3) {
                param_4 = 2;
              }
              iVar4 = 0;
              puVar5 = puVar5 + 0x24;
              do {
                FUN_40986e1c(param_3,iVar4,*puVar5,param_4);
                iVar4 = iVar4 + 1;
                puVar5 = puVar5 + 1;
              } while (iVar4 < 3);
              return 0;
            }
            if (param_2 == 0xb03) {
              iVar4 = 0;
              puVar5 = puVar5 + (*(int *)(param_1 + 0x328) + 1) * 4;
              do {
                FUN_40986e1c(param_3,iVar4,*puVar5,param_4);
                iVar4 = iVar4 + 1;
                puVar5 = puVar5 + 1;
              } while (iVar4 < 4);
              return 0;
            }
            if (param_2 == 0xb11) {
              uVar2 = *(undefined4 *)(param_1 + 0x3f4);
            }
            else {
              if (param_2 == 0xb12) goto LAB_40987c0c;
              if (param_2 != 0xb21) {
                if (param_2 != 0xb22) {
                  return 0x500;
                }
                goto LAB_40987be8;
              }
              uVar2 = *(undefined4 *)(param_1 + 0x400);
            }
          }
          else {
            if (param_2 == 0xb46) {
              iVar4 = *(int *)(param_1 + 1000);
              goto LAB_4098846c;
            }
            if (param_2 == 0xb52) {
              uVar3 = *(uint *)(*(int *)(param_1 + 0x508) + 0x1c) >> 8 & 1;
LAB_40987dbc:
              FUN_40986b08(param_3,0,uVar3,param_4);
              return 0;
            }
            if (param_2 == 0xb53) {
              if (param_4 == 3) {
                param_4 = 2;
              }
              iVar4 = 0;
              puVar5 = puVar5 + 0x17d6;
              do {
                FUN_40986e1c(param_3,iVar4,*puVar5,param_4);
                iVar4 = iVar4 + 1;
                puVar5 = puVar5 + 1;
              } while (iVar4 < 4);
              return 0;
            }
            if (param_2 == 0xb54) {
              iVar4 = 0x1d00;
              if ((*(uint *)(*(int *)(param_1 + 0x508) + 0x20) & 0x4000000) == 0) {
                iVar4 = 0x1d01;
              }
              goto LAB_4098846c;
            }
            if (param_2 == 0xb62) {
              uVar2 = puVar5[0x17c0];
            }
            else {
              if (param_2 != 0xb63) {
                return 0x500;
              }
              uVar2 = puVar5[0x17c1];
            }
          }
          goto LAB_40987d40;
        }
        if (param_2 < 0xb92) {
          if (param_2 != 0xb91) {
            if (param_2 == 0xb65) {
              iVar4 = puVar5[0x17c3];
              goto LAB_4098846c;
            }
            if (param_2 == 0xb66) {
              if (param_4 == 3) {
                param_4 = 2;
              }
              iVar4 = 0;
              puVar5 = puVar5 + 0x17bc;
              do {
                FUN_40986e1c(param_3,iVar4,*puVar5,param_4);
                iVar4 = iVar4 + 1;
                puVar5 = puVar5 + 1;
              } while (iVar4 < 4);
              return 0;
            }
            if (param_2 != 0xb70) {
              if (param_2 == 0xb72) {
                uVar3 = (uint)*(byte *)(param_1 + 0x458);
                goto LAB_40987dbc;
              }
              if (param_2 == 0xb73) {
                if (param_4 == 3) {
                  param_4 = 2;
                }
                uVar2 = *(undefined4 *)(param_1 + 0x470);
                goto LAB_40987d40;
              }
              if (param_2 != 0xb74) {
                return 0x500;
              }
              uVar3 = (uint)*(byte *)(*(int *)(param_1 + 0x504) + 0x4d);
              goto LAB_40987e4c;
            }
            if (param_4 == 3) {
              param_4 = 2;
            }
            FUN_40986e1c(param_3,0,*(undefined4 *)(param_1 + 0x414),param_4);
            uVar2 = *(undefined4 *)(param_1 + 0x418);
            goto LAB_40987ea4;
          }
          uVar3 = *(uint *)(param_1 + 0x474);
        }
        else {
          if (param_2 == 0xb92) {
            uVar3 = (uint)*(byte *)(*(int *)(param_1 + 0x504) + 0x4f);
LAB_40987e4c:
            iVar4 = FUN_4096c1d0(uVar3);
LAB_4098846c:
            FUN_409869b4(param_3,0,iVar4,param_4);
            return 0;
          }
          if (param_2 != 0xb93) {
            if (param_2 == 0xb94) {
              uVar3 = (uint)*(byte *)(*(int *)(param_1 + 0x504) + 0x53);
            }
            else if (param_2 == 0xb95) {
              uVar3 = (uint)*(byte *)(*(int *)(param_1 + 0x504) + 0x54);
            }
            else {
              if (param_2 != 0xb96) {
                if (param_2 != 0xb97) {
                  return 0x500;
                }
                bVar1 = *(byte *)(*(int *)(param_1 + 0x504) + 0x50);
                goto LAB_40987f60;
              }
              uVar3 = (uint)*(byte *)(*(int *)(param_1 + 0x504) + 0x55);
            }
            iVar4 = FUN_4096c0a0(uVar3);
            goto LAB_4098846c;
          }
          uVar3 = *(uint *)(*(int *)(param_1 + 0x504) + 0x84);
        }
      }
    }
    else if (param_2 < 0xc23) {
      if (param_2 == 0xc22) {
        if (param_4 == 3) {
          param_4 = 2;
        }
        iVar4 = 0;
        puVar5 = (undefined4 *)(param_1 + 0x460);
        do {
          FUN_40986e1c(param_3,iVar4,*puVar5,param_4);
          iVar4 = iVar4 + 1;
          puVar5 = puVar5 + 1;
        } while (iVar4 < 4);
        return 0;
      }
      if (0xba8 < param_2) {
        if (param_2 == 0xbc1) {
          uVar3 = (uint)*(byte *)(*(int *)(param_1 + 0x504) + 0x44);
          goto LAB_40987e4c;
        }
        if (param_2 != 0xbc2) {
          if (param_2 == 0xbe0) {
            bVar1 = *(byte *)(*(int *)(param_1 + 0x504) + 0x49);
          }
          else {
            if (param_2 != 0xbe1) {
              if (param_2 == 0xbf0) {
                iVar4 = FUN_4096c2e0((uint)*(byte *)(*(int *)(param_1 + 0x504) + 0x4c));
                goto LAB_4098846c;
              }
              if (param_2 != 0xc10) {
                return 0x500;
              }
              FUN_40986a5c(param_3,0,*(int *)(param_1 + 0x3d4),param_4);
              FUN_40986a5c(param_3,1,*(int *)(param_1 + 0x3d8),param_4);
              FUN_40986a5c(param_3,2,*(int *)(param_1 + 0x3dc),param_4);
              uVar3 = *(uint *)(param_1 + 0x3e0);
              goto LAB_409880c8;
            }
            bVar1 = *(byte *)(*(int *)(param_1 + 0x504) + 0x48);
          }
          iVar4 = FUN_4096be78((uint)bVar1);
          goto LAB_4098846c;
        }
        if (param_4 == 3) {
          param_4 = 2;
        }
        uVar2 = *(undefined4 *)(*(int *)(param_1 + 0x504) + 0x78);
        goto LAB_40987d40;
      }
      if (param_2 == 0xba8) {
        puVar5 = puVar5 + (puVar5[*(int *)(param_1 + 0x328) + 0x156d] +
                          *(int *)(param_1 + 0x328) * 0x20) * 0x10 + 0x417;
        goto LAB_40988994;
      }
      if (param_2 == 0xba0) {
        iVar4 = puVar5[0x1575];
        goto LAB_4098846c;
      }
      if (param_2 == 0xba2) {
        FUN_40986a5c(param_3,0,*(int *)(param_1 + 0x404),param_4);
        FUN_40986a5c(param_3,1,*(int *)(param_1 + 0x408),param_4);
        FUN_40986a5c(param_3,2,*(int *)(param_1 + 0x40c),param_4);
        uVar3 = *(uint *)(param_1 + 0x410);
LAB_409880c8:
        iVar4 = 3;
        goto LAB_40988670;
      }
      if (param_2 == 0xba3) {
        uVar3 = puVar5[0x156b];
      }
      else if (param_2 == 0xba4) {
        uVar3 = puVar5[0x156c];
      }
      else {
        if (param_2 != 0xba5) {
          if (param_2 == 0xba6) {
            puVar5 = puVar5 + puVar5[0x156b] * 0x10 + 0x17;
            goto LAB_40988994;
          }
          if (param_2 != 0xba7) {
            return 0x500;
          }
          goto LAB_40988984;
        }
        uVar3 = puVar5[*(int *)(param_1 + 0x328) + 0x156d];
      }
    }
    else if (param_2 < 0xd06) {
      if (param_2 == 0xd05) {
        uVar3 = *(uint *)(param_1 + 0x3cc);
      }
      else {
        if (param_2 == 0xc23) {
          iVar4 = 0;
          do {
            FUN_40986b08(param_3,iVar4,(uint)*(byte *)(param_1 + 0x454 + iVar4),param_4);
            iVar4 = iVar4 + 1;
          } while (iVar4 < 4);
          return 0;
        }
        if (param_2 == 0xc50) {
          iVar4 = puVar5[0x1964];
          goto LAB_4098846c;
        }
        if (param_2 == 0xc51) {
          iVar4 = puVar5[0x1965];
          goto LAB_4098846c;
        }
        if (param_2 == 0xc52) {
          iVar4 = puVar5[0x1963];
          goto LAB_4098846c;
        }
        if (param_2 == 0xc54) {
          iVar4 = puVar5[0x1961];
          goto LAB_4098846c;
        }
        if (param_2 != 0xcf5) {
          return 0x500;
        }
        uVar3 = *(uint *)(param_1 + 0x3d0);
      }
    }
    else {
      if (param_2 == 0xd31) goto LAB_4098835c;
      if (param_2 == 0xd32) {
        uVar3 = 1;
      }
      else {
        if (param_2 != 0xd33) {
          if (((param_2 != 0xd36) && (param_2 != 0xd38)) && (param_2 != 0xd39)) {
            return 0x500;
          }
          goto LAB_40988344;
        }
        uVar3 = 0x1000;
      }
    }
  }
  else if (param_2 < 0x84e3) {
    if (param_2 == 0x84e2) {
LAB_4098835c:
      uVar3 = 8;
    }
    else if (param_2 < 0x808a) {
      if (param_2 == 0x8089) {
        iVar4 = *(int *)((uint)*(byte *)(param_1 + 0x324) * 0x30 + iVar4 + 0x134);
        goto LAB_4098846c;
      }
      if (param_2 < 0x807d) {
        if (param_2 == 0x807c) {
          uVar3 = *(uint *)(param_1 + 0x1c);
        }
        else {
          if (param_2 < 0x8039) {
            if (param_2 == 0x8038) {
              uVar2 = *(undefined4 *)(*(int *)(param_1 + 0x504) + 0x7c);
            }
            else {
              if (param_2 == 0xd50) goto LAB_40988430;
              if (param_2 < 0xd52) {
                return 0x500;
              }
              if (param_2 < 0xd58) goto LAB_409885e8;
              if (param_2 != 0x2a00) {
                return 0x500;
              }
              uVar2 = *(undefined4 *)(*(int *)(param_1 + 0x504) + 0x80);
            }
            goto LAB_40987d40;
          }
          if (param_2 == 0x8069) {
            uVar3 = *(uint *)(*(int *)(param_1 + 0x328) * 0x14 + iVar4 + 0x32c);
          }
          else {
            if (param_2 != 0x807a) {
              if (param_2 != 0x807b) {
                return 0x500;
              }
              iVar4 = *(int *)(param_1 + 0x20);
              goto LAB_4098846c;
            }
            uVar3 = *(uint *)(param_1 + 0x18);
          }
        }
      }
      else {
        if (param_2 == 0x807e) {
          iVar4 = *(int *)(param_1 + 0x50);
          goto LAB_4098846c;
        }
        if (param_2 == 0x807f) {
          uVar3 = *(uint *)(param_1 + 0x4c);
        }
        else if (param_2 == 0x8081) {
          uVar3 = *(uint *)(param_1 + 0x78);
        }
        else {
          if (param_2 == 0x8082) {
            iVar4 = *(int *)(param_1 + 0x80);
            goto LAB_4098846c;
          }
          if (param_2 == 0x8083) {
            uVar3 = *(uint *)(param_1 + 0x7c);
          }
          else {
            if (param_2 != 0x8088) {
              return 0x500;
            }
            uVar3 = *(uint *)((uint)*(byte *)(param_1 + 0x324) * 0x30 + iVar4 + 300);
          }
        }
      }
    }
    else {
      if (0x8128 < param_2) {
        if (param_2 == 0x8129) {
          iVar4 = 0;
          puVar5 = puVar5 + 0x18a5;
          do {
            FUN_40986e1c(param_3,iVar4,*puVar5,param_4);
            iVar4 = iVar4 + 1;
            puVar5 = puVar5 + 1;
          } while (iVar4 < 3);
          return 0;
        }
        if (param_2 == 0x8192) {
          iVar4 = puVar5[0x1962];
          goto LAB_4098846c;
        }
        if (param_2 == 0x846d) {
LAB_40987c0c:
          uVar2 = 0x3f800000;
        }
        else {
          if (param_2 != 0x846e) {
            if (param_2 == 0x84e0) {
              iVar4 = *(int *)(param_1 + 0x328) + 0x84c0;
              goto LAB_4098846c;
            }
            if (param_2 != 0x84e1) {
              return 0x500;
            }
            uVar3 = *(byte *)(param_1 + 0x324) + 0x84c0;
            goto LAB_4098866c;
          }
LAB_40987be8:
          uVar2 = 0x3e800000;
        }
        FUN_40986e1c(param_3,0,uVar2,param_4);
        uVar2 = 0x42c80000;
LAB_40987ea4:
        iVar4 = 1;
        goto LAB_40987ea8;
      }
      if (param_2 == 0x8128) {
        uVar2 = puVar5[0x18a4];
LAB_40987d40:
        iVar4 = 0;
LAB_40987ea8:
        FUN_40986e1c(param_3,iVar4,uVar2,param_4);
        return 0;
      }
      if (param_2 == 0x808a) {
        uVar3 = *(uint *)((uint)*(byte *)(param_1 + 0x324) * 0x30 + iVar4 + 0x130);
      }
      else {
        if ((param_2 != 0x80a8) && (1 < param_2 - 0x80a8)) {
          if (param_2 == 0x80aa) {
            uVar2 = *(undefined4 *)(*(int *)(param_1 + 0x504) + 0x60);
          }
          else {
            if (param_2 == 0x80ab) {
              uVar3 = (uint)*(byte *)(*(int *)(param_1 + 0x504) + 100);
              goto LAB_40987dbc;
            }
            if (param_2 == 0x8126) {
              uVar2 = *(undefined4 *)(param_1 + 0x3f8);
            }
            else {
              if (param_2 != 0x8127) {
                return 0x500;
              }
              uVar2 = *(undefined4 *)(param_1 + 0x3fc);
            }
          }
          goto LAB_40987d40;
        }
LAB_409885e8:
        uVar3 = FUN_40973584((int *)(param_1 + 0x484),param_2);
      }
    }
  }
  else if (param_2 < 0x8897) {
    if (param_2 == 0x8896) {
      uVar3 = *(uint *)(param_1 + 0x2c);
    }
    else if (param_2 < 0x8843) {
      if (param_2 == 0x8842) {
LAB_40988344:
        uVar3 = 0x20;
      }
      else if (param_2 == 0x86a2) {
        uVar3 = 0xb;
      }
      else {
        if (param_2 == 0x86a3) {
          iVar4 = 0;
          piVar6 = local_48;
          do {
            FUN_409869b4(param_3,iVar4,*piVar6,param_4);
            iVar4 = iVar4 + 1;
            piVar6 = piVar6 + 1;
          } while (iVar4 < 0xb);
          return 0;
        }
        if (param_2 == 0x86a4) {
LAB_40988430:
          uVar3 = 4;
        }
        else {
          if (param_2 == 0x86a9) {
            iVar4 = *(int *)(param_1 + 0xe0);
            goto LAB_4098846c;
          }
          if (param_2 == 0x86aa) {
            uVar3 = *(uint *)(param_1 + 0xdc);
          }
          else {
            if (param_2 != 0x86ab) {
              return 0x500;
            }
            uVar3 = *(uint *)(param_1 + 0xd8);
          }
        }
      }
    }
    else if (param_2 == 0x8843) {
      uVar3 = puVar5[0x179b];
    }
    else if (param_2 == 0x8846) {
      uVar3 = *(uint *)(param_1 + 0x108);
    }
    else {
      if (param_2 == 0x8847) {
        iVar4 = *(int *)(param_1 + 0x110);
        goto LAB_4098846c;
      }
      if (param_2 == 0x8848) {
        uVar3 = *(uint *)(param_1 + 0x10c);
      }
      else if (param_2 == 0x8894) {
        uVar3 = *(uint *)(param_1 + 0x314);
      }
      else {
        if (param_2 != 0x8895) {
          return 0x500;
        }
        uVar3 = *(uint *)(param_1 + 0x318);
      }
    }
  }
  else if (param_2 < 0x898e) {
    if (param_2 == 0x898d) {
      iVar4 = puVar5[0x156b] * 0x10 + 0x17;
LAB_409888dc:
      puVar5 = puVar5 + iVar4;
      param_4 = 0;
LAB_40988994:
      FUN_40987034(puVar5,param_3,param_4);
      return 0;
    }
    if (param_2 == 0x8897) {
      uVar3 = *(uint *)(param_1 + 0x5c);
    }
    else if (param_2 == 0x8898) {
      uVar3 = *(uint *)(param_1 + 0x8c);
    }
    else if (param_2 == 0x889a) {
      uVar3 = *(uint *)((uint)*(byte *)(param_1 + 0x324) * 0x30 + iVar4 + 0x140);
    }
    else if (param_2 == 0x889e) {
      uVar3 = *(uint *)(param_1 + 0xec);
    }
    else {
      if (param_2 == 0x898a) {
        iVar4 = *(int *)(param_1 + 0xb0);
        goto LAB_4098846c;
      }
      if (param_2 != 0x898b) {
        return 0x500;
      }
      uVar3 = *(uint *)(param_1 + 0xac);
    }
  }
  else {
    if (param_2 == 0x898e) {
      param_4 = 0;
LAB_40988984:
      puVar5 = puVar5 + puVar5[0x156c] * 0x10 + 0x217;
      goto LAB_40988994;
    }
    if (param_2 == 0x898f) {
      iVar4 = (puVar5[*(int *)(param_1 + 0x328) + 0x156d] + *(int *)(param_1 + 0x328) * 0x20) * 0x10
              + 0x417;
      goto LAB_409888dc;
    }
    if (param_2 == 0x8b9a) {
      iVar4 = 0x8363;
      goto LAB_4098846c;
    }
    if (param_2 == 0x8b9b) {
      iVar4 = 0x1907;
      goto LAB_4098846c;
    }
    if (param_2 == 0x8b9e) {
      uVar3 = *(uint *)(param_1 + 0x11c);
    }
    else {
      if (param_2 != 0x8b9f) {
        return 0x500;
      }
      uVar3 = *(uint *)(param_1 + 0xbc);
    }
  }
LAB_4098866c:
  iVar4 = 0;
LAB_40988670:
  FUN_40986a5c(param_3,iVar4,uVar3,param_4);
  return 0;
}



/* 40988b88 FUN_40988b88 */

/* Boundary evidence: original MIPS .pdata 40988b88..40988c27. Semantic name remains unreviewed. */

undefined1 FUN_40988b88(undefined4 param_1)

{
  undefined1 uVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar2 = __lts(param_1,0xc1fe0000);
  if (iVar2 == 0) {
    iVar2 = __gts(param_1,0x41fe0000);
    if (iVar2 == 0) {
      iVar2 = __lts(param_1,0x3e800000);
      if ((iVar2 == 0) || (iVar2 = __gts(param_1,0xbe800000), iVar2 == 0)) {
        uVar3 = __fpmul(param_1,0x40800000);
        uVar1 = __fptoli(uVar3);
      }
      else {
        uVar1 = 0;
      }
    }
    else {
      uVar1 = 0x7f;
    }
  }
  else {
    uVar1 = 0x80;
  }
  return uVar1;
}



/* 40988e48 FUN_40988e48 */

/* Boundary evidence: original MIPS .pdata 40988e48..40988f5f. Semantic name remains unreviewed. */

undefined4 FUN_40988e48(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int *piVar4;
  int local_28;
  undefined1 auStack_24 [4];
  undefined1 auStack_20 [4];
  undefined1 auStack_1c [4];
  undefined1 auStack_18 [4];
  undefined1 auStack_14 [4];
  
  iVar3 = *(int *)(param_1 + 0x484);
  if (iVar3 == 0) {
    local_28 = *(int *)(param_1 + 0x4a8);
    goto LAB_40988f1c;
  }
  if (iVar3 != -0x48) {
    if (*(int *)(iVar3 + 0x50) == 0x1702) {
      iVar1 = FUN_40979e34(*(int *)(iVar3 + 100));
      piVar4 = *(int **)((iVar1 * 0xd + *(int *)(iVar3 + 0x60)) * 4 +
                        *(int *)(*(int *)(iVar3 + 0x58) + 0x34));
      if (piVar4 != (int *)0x0) {
        iVar3 = *piVar4;
        goto LAB_40988ed4;
      }
    }
    else if (*(int *)(iVar3 + 0x50) == 0x8d41) {
      iVar3 = *(int *)(*(int *)(iVar3 + 0x58) + 0x28);
LAB_40988ed4:
      if (iVar3 != 0) {
        mali_pixel_format_get_bpc
                  (*(undefined4 *)(iVar3 + 0x14),auStack_14,auStack_18,auStack_1c,auStack_20,
                   auStack_24,&local_28);
        goto LAB_40988f1c;
      }
    }
  }
  local_28 = 0;
LAB_40988f1c:
  uVar2 = 1;
  if (((*(uint *)(*(int *)(param_1 + 0x504) + 0x40) & 0x10) == 0) || (local_28 < 1)) {
    uVar2 = 0;
  }
  return uVar2;
}



/* 40988f60 FUN_40988f60 */

/* Boundary evidence: original MIPS .pdata 40988f60..40989077. Semantic name remains unreviewed. */

undefined4 FUN_40988f60(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int *piVar4;
  int local_28;
  undefined1 auStack_24 [4];
  undefined1 auStack_20 [4];
  undefined1 auStack_1c [4];
  undefined1 auStack_18 [4];
  undefined1 auStack_14 [4];
  
  iVar3 = *(int *)(param_1 + 0x484);
  if (iVar3 == 0) {
    local_28 = *(int *)(param_1 + 0x4a4);
    goto LAB_40989034;
  }
  if (iVar3 != -0x24) {
    if (*(int *)(iVar3 + 0x2c) == 0x1702) {
      iVar1 = FUN_40979e34(*(int *)(iVar3 + 0x40));
      piVar4 = *(int **)((iVar1 * 0xd + *(int *)(iVar3 + 0x3c)) * 4 +
                        *(int *)(*(int *)(iVar3 + 0x34) + 0x34));
      if (piVar4 != (int *)0x0) {
        iVar3 = *piVar4;
        goto LAB_40988fec;
      }
    }
    else if (*(int *)(iVar3 + 0x2c) == 0x8d41) {
      iVar3 = *(int *)(*(int *)(iVar3 + 0x34) + 0x28);
LAB_40988fec:
      if (iVar3 != 0) {
        mali_pixel_format_get_bpc
                  (*(undefined4 *)(iVar3 + 0x14),auStack_14,auStack_18,auStack_1c,auStack_20,
                   &local_28,auStack_24);
        goto LAB_40989034;
      }
    }
  }
  local_28 = 0;
LAB_40989034:
  uVar2 = 1;
  if (((*(uint *)(*(int *)(param_1 + 0x504) + 0x40) & 2) == 0) || (local_28 < 1)) {
    uVar2 = 0;
  }
  return uVar2;
}



/* 40989078 FUN_40989078 */

/* Boundary evidence: original MIPS .pdata 40989078..409890af. Semantic name remains unreviewed. */

void FUN_40989078(int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined1 uVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0x504);
  *(undefined4 *)(iVar2 + 0x7c) = param_2;
  *(undefined4 *)(iVar2 + 0x80) = param_3;
  uVar1 = FUN_40988b88(param_2);
  *(undefined1 *)(iVar2 + 0x65) = uVar1;
  *(undefined1 *)(iVar2 + 0x66) = 0;
  return;
}



/* 409890b0 FUN_409890b0 */

void FUN_409890b0(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x504);
  *(char *)(iVar1 + 0x4c) = (char)param_2;
  if ((*(uint *)(iVar1 + 0x40) & 8) == 8) {
    *(uint *)(iVar1 + 8) =
         (*(uint *)(iVar1 + 8) & 0xfffffc00 ^ param_2 << 6 ^ 0x1b) & 0xfff0ffff ^ param_2 << 0x10;
  }
  return;
}



/* 40989108 FUN_40989108 */

void FUN_40989108(int param_1,uint param_2,int param_3)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x504);
  *(char *)(iVar1 + 0x46) = (char)param_2;
  *(char *)(iVar1 + 0x47) = (char)param_3;
  if ((*(uint *)(iVar1 + 0x40) & 8) != 8) {
    if ((*(uint *)(iVar1 + 0x40) & 4) == 0) {
      param_3 = 2;
      param_2 = 2;
    }
    *(uint *)(iVar1 + 8) = (*(uint *)(iVar1 + 8) & 0xfffffff8 ^ param_2) & 0xffffffc7 ^ param_3 << 3
    ;
  }
  return;
}



/* 409891a8 FUN_409891a8 */

void FUN_409891a8(int param_1,int param_2)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = *(int *)(param_1 + 0x504);
  *(uint *)(iVar3 + 0x40) = *(uint *)(iVar3 + 0x40) & 0xfffff7ff | param_2 << 0xb;
  if (param_2 != 0) {
    iVar2 = 1;
    if ((*(int *)(param_1 + 0x484) != 0) || (bVar1 = true, *(int *)(param_1 + 0x4b0) < 1)) {
      bVar1 = false;
    }
    if (((*(uint *)(*(int *)(param_1 + 0x504) + 0x40) & 0x20) != 0) && (bVar1)) goto LAB_40989208;
  }
  iVar2 = 0;
LAB_40989208:
  *(uint *)(iVar3 + 0x20) = *(uint *)(iVar3 + 0x20) & 0xfffffeff ^ iVar2 << 8;
  return;
}



/* 40989228 FUN_40989228 */

void FUN_40989228(int param_1,int param_2)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = *(int *)(param_1 + 0x504);
  *(uint *)(iVar3 + 0x40) = *(uint *)(iVar3 + 0x40) & 0xfffffbff | param_2 << 10;
  if (param_2 != 0) {
    iVar2 = 1;
    if ((*(int *)(param_1 + 0x484) != 0) || (bVar1 = true, *(int *)(param_1 + 0x4b0) < 1)) {
      bVar1 = false;
    }
    if (((*(uint *)(*(int *)(param_1 + 0x504) + 0x40) & 0x20) != 0) && (bVar1)) goto LAB_40989288;
  }
  iVar2 = 0;
LAB_40989288:
  *(uint *)(iVar3 + 0x20) = *(uint *)(iVar3 + 0x20) & 0xffffff7f ^ iVar2 << 7;
  return;
}



/* 409892a8 FUN_409892a8 */

void FUN_409892a8(int param_1)

{
  bool bVar1;
  uint uVar2;
  int iVar3;
  
  iVar3 = *(int *)(param_1 + 0x504);
  uVar2 = 1;
  if ((*(int *)(param_1 + 0x484) != 0) || (bVar1 = true, *(int *)(param_1 + 0x4b0) < 1)) {
    bVar1 = false;
  }
  if (((*(uint *)(iVar3 + 0x40) & 0x20) == 0) || (!bVar1)) {
    uVar2 = 0;
  }
  *(uint *)(iVar3 + 0x20) =
       ((uVar2 ^ uVar2 << 2) << 3 ^ *(uint *)(iVar3 + 0x20) & 0xffffffd7) & 0xffffffbf ^ uVar2 << 6;
  return;
}



/* 4098932c FUN_4098932c */

/* Boundary evidence: original MIPS .pdata 4098932c..4098944f. Semantic name remains unreviewed. */

void FUN_4098932c(int param_1,undefined4 param_2,int param_3)

{
  bool bVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  
  iVar4 = *(int *)(param_1 + 0x504);
  *(undefined4 *)(iVar4 + 0x60) = param_2;
  *(char *)(iVar4 + 100) = (char)param_3;
  uVar3 = 0;
  if ((*(int *)(param_1 + 0x484) != 0) || (bVar1 = true, *(int *)(param_1 + 0x4b0) < 1)) {
    bVar1 = false;
  }
  if ((((*(uint *)(*(int *)(param_1 + 0x504) + 0x40) & 0x20) == 0) || (!bVar1)) ||
     ((*(uint *)(iVar4 + 0x40) & 0x40) == 0)) {
    param_2 = 0x3f800000;
    param_3 = 0;
  }
  iVar2 = __gts(param_2,0x3f600000);
  if (iVar2 != 0) {
    uVar3 = 8;
  }
  iVar2 = __gts(param_2,0x3f200000);
  if (iVar2 != 0) {
    uVar3 = uVar3 | 4;
  }
  iVar2 = __gts(param_2,0x3ec00000);
  if (iVar2 != 0) {
    uVar3 = uVar3 | 2;
  }
  iVar2 = __gts(param_2,0x3e000000);
  if (iVar2 != 0) {
    uVar3 = uVar3 | 1;
  }
  if (param_3 != 0) {
    uVar3 = uVar3 ^ 0xf;
  }
  *(uint *)(iVar4 + 0x20) = uVar3 << 0xc ^ *(uint *)(iVar4 + 0x20) & 0xffff0fff;
  return;
}



/* 40989450 FUN_40989450 */

void FUN_40989450(int param_1,uint param_2)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  
  iVar2 = *(int *)(param_1 + 0x504);
  bVar1 = *(byte *)(iVar2 + 0x45);
  uVar3 = (uint)*(byte *)(iVar2 + 0x44);
  *(uint *)(iVar2 + 0x40) = *(uint *)(iVar2 + 0x40) & 0xfffffffe | param_2;
  iVar4 = *(int *)(param_1 + 0x504);
  *(byte *)(iVar4 + 0x44) = *(byte *)(iVar2 + 0x44);
  *(byte *)(iVar4 + 0x45) = bVar1;
  if ((*(uint *)(iVar4 + 0x40) & 1) == 0) {
    uVar3 = 7;
  }
  *(uint *)(iVar4 + 0x20) = *(uint *)(iVar4 + 0x20) & 0xfffffff8 ^ uVar3;
  *(uint *)(iVar4 + 0x1c) = (uint)bVar1 << 0x10 ^ *(uint *)(iVar4 + 0x1c) & 0xffff;
  return;
}



/* 409894c0 FUN_409894c0 */

/* Boundary evidence: original MIPS .pdata 409894c0..4098951b. Semantic name remains unreviewed. */

void FUN_409894c0(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0x504);
  *(char *)(iVar2 + 0x59) = (char)param_2;
  iVar1 = FUN_40988e48(param_1);
  if (iVar1 == 0) {
    param_2 = 0;
  }
  *(uint *)(iVar2 + 0x1c) = param_2 << 8 ^ *(uint *)(iVar2 + 0x1c) & 0xffff00ff;
  return;
}



/* 4098951c FUN_4098951c */

/* Boundary evidence: original MIPS .pdata 4098951c..40989573. Semantic name remains unreviewed. */

void FUN_4098951c(int param_1,uint param_2)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0x504);
  *(char *)(iVar2 + 0x52) = (char)param_2;
  iVar1 = FUN_40988e48(param_1);
  if (iVar1 == 0) {
    param_2 = 0;
  }
  *(uint *)(iVar2 + 0x1c) = *(uint *)(iVar2 + 0x1c) & 0xffffff00 ^ param_2;
  return;
}



/* 40989574 FUN_40989574 */

/* Boundary evidence: original MIPS .pdata 40989574..4098961b. Semantic name remains unreviewed. */

void FUN_40989574(int param_1,uint param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0x504);
  *(char *)(iVar2 + 0x5a) = (char)param_2;
  *(char *)(iVar2 + 0x5b) = (char)param_3;
  *(char *)(iVar2 + 0x5c) = (char)param_4;
  iVar1 = FUN_40988e48(param_1);
  if (iVar1 == 0) {
    param_3 = 0;
    param_4 = 0;
  }
  *(uint *)(iVar2 + 0x18) =
       ((param_2 & 0xffffffc7 ^ param_3 << 3) << 3 ^ *(uint *)(iVar2 + 0x18) & 0xfffffe07) &
       0xfffff1ff ^ param_4 << 9;
  return;
}



/* 4098961c FUN_4098961c */

/* Boundary evidence: original MIPS .pdata 4098961c..409896c3. Semantic name remains unreviewed. */

void FUN_4098961c(int param_1,uint param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0x504);
  *(char *)(iVar2 + 0x53) = (char)param_2;
  *(char *)(iVar2 + 0x54) = (char)param_3;
  *(char *)(iVar2 + 0x55) = (char)param_4;
  iVar1 = FUN_40988e48(param_1);
  if (iVar1 == 0) {
    param_3 = 0;
    param_4 = 0;
  }
  *(uint *)(iVar2 + 0x14) =
       ((param_2 & 0xffffffc7 ^ param_3 << 3) << 3 ^ *(uint *)(iVar2 + 0x14) & 0xfffffe07) &
       0xfffff1ff ^ param_4 << 9;
  return;
}



/* 409896c4 FUN_409896c4 */

/* Boundary evidence: original MIPS .pdata 409896c4..40989777. Semantic name remains unreviewed. */

void FUN_409896c4(int param_1,uint param_2,uint param_3,uint param_4)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  
  iVar3 = *(int *)(param_1 + 0x504);
  *(uint *)(iVar3 + 0x88) = param_4;
  *(char *)(iVar3 + 0x56) = (char)param_2;
  *(char *)(iVar3 + 0x57) = (char)param_3;
  *(char *)(iVar3 + 0x58) = (char)param_4;
  iVar1 = FUN_40988e48(param_1);
  if (iVar1 == 0) {
    param_2 = 7;
  }
  uVar2 = (*(uint *)(iVar3 + 0x18) & 0xfffffff8 ^ param_2) & 0xff00ffff ^
          (param_3 & param_4) << 0x10;
  *(uint *)(iVar3 + 0x18) = uVar2;
  *(uint *)(iVar3 + 0x18) = uVar2 & 0xffffff ^ (uint)*(byte *)(iVar3 + 0x51) << 0x18;
  return;
}



/* 40989778 FUN_40989778 */

/* Boundary evidence: original MIPS .pdata 40989778..4098982b. Semantic name remains unreviewed. */

void FUN_40989778(int param_1,uint param_2,uint param_3,uint param_4)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  
  iVar3 = *(int *)(param_1 + 0x504);
  *(uint *)(iVar3 + 0x84) = param_4;
  *(char *)(iVar3 + 0x4f) = (char)param_2;
  *(char *)(iVar3 + 0x50) = (char)param_3;
  *(char *)(iVar3 + 0x51) = (char)param_4;
  iVar1 = FUN_40988e48(param_1);
  if (iVar1 == 0) {
    param_2 = 7;
  }
  uVar2 = (*(uint *)(iVar3 + 0x14) & 0xfffffff8 ^ param_2) & 0xff00ffff ^
          (param_3 & param_4) << 0x10;
  *(uint *)(iVar3 + 0x14) = uVar2;
  *(uint *)(iVar3 + 0x14) = uVar2 & 0xffffff ^ (uint)*(byte *)(iVar3 + 0x51) << 0x18;
  return;
}



/* 4098982c FUN_4098982c */

/* Boundary evidence: original MIPS .pdata 4098982c..40989887. Semantic name remains unreviewed. */

void FUN_4098982c(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0x504);
  *(char *)(iVar2 + 0x4d) = (char)param_2;
  iVar1 = FUN_40988f60(param_1);
  if (iVar1 == 0) {
    param_2 = 7;
  }
  *(uint *)(iVar2 + 0xc) = param_2 << 1 ^ *(uint *)(iVar2 + 0xc) & 0xfffffff1;
  return;
}



/* 40989888 FUN_40989888 */

/* Boundary evidence: original MIPS .pdata 40989888..409898d7. Semantic name remains unreviewed. */

void FUN_40989888(int param_1,uint param_2)

{
  uint uVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0x504);
  *(char *)(iVar2 + 0x4e) = (char)param_2;
  uVar1 = FUN_40988f60(param_1);
  *(uint *)(iVar2 + 0xc) = *(uint *)(iVar2 + 0xc) & 0xfffffffe ^ uVar1 & param_2;
  return;
}



/* 409898d8 FUN_409898d8 */

/* Boundary evidence: original MIPS .pdata 409898d8..4098993b. Semantic name remains unreviewed. */

void FUN_409898d8(int param_1,int param_2)

{
  undefined1 uVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 uVar4;
  
  iVar3 = *(int *)(param_1 + 0x504);
  uVar4 = *(undefined4 *)(iVar3 + 0x80);
  uVar2 = *(undefined4 *)(iVar3 + 0x7c);
  *(uint *)(iVar3 + 0x40) = *(uint *)(iVar3 + 0x40) & 0xffffff7f | param_2 << 7;
  iVar3 = *(int *)(param_1 + 0x504);
  *(undefined4 *)(iVar3 + 0x7c) = uVar2;
  *(undefined4 *)(iVar3 + 0x80) = uVar4;
  uVar1 = FUN_40988b88(uVar2);
  *(undefined1 *)(iVar3 + 0x65) = uVar1;
  *(undefined1 *)(iVar3 + 0x66) = 0;
  return;
}



/* 4098993c FUN_4098993c */

/* Boundary evidence: original MIPS .pdata 4098993c..40989b0f. Semantic name remains unreviewed. */

void FUN_4098993c(int param_1,uint param_2,int param_3,uint param_4,byte param_5)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  
  iVar3 = *(int *)(param_1 + 0x504);
  uVar2 = (uint)param_5;
  *(char *)(iVar3 + 0x48) = (char)param_2;
  *(char *)(iVar3 + 0x49) = (char)param_3;
  *(char *)(iVar3 + 0x4a) = (char)param_4;
  *(byte *)(iVar3 + 0x4b) = param_5;
  if ((*(uint *)(iVar3 + 0x40) & 8) == 8) {
    return;
  }
  if ((*(uint *)(iVar3 + 0x40) & 4) == 0) {
    param_4 = 0xb;
    param_2 = 0xb;
    uVar2 = 3;
    param_3 = 3;
  }
  FUN_40989108(param_1,(uint)*(byte *)(iVar3 + 0x46),(uint)*(byte *)(iVar3 + 0x47));
  if (*(int *)(param_1 + 0x484) == 0) {
    iVar1 = *(int *)(param_1 + 0x4a0);
  }
  else {
    iVar1 = FUN_40971460(*(int *)(param_1 + 0x484),0xd55);
  }
  if (iVar1 != 0) goto LAB_40989a8c;
  if (param_2 == 4) {
LAB_40989a08:
    param_2 = 3;
  }
  else if (param_2 == 0x11) {
    param_2 = 0xb;
  }
  else if (param_2 == 0x19) goto LAB_40989a08;
  if (param_3 == 4) {
LAB_40989a28:
    param_3 = 3;
  }
  else if (param_3 == 0x11) {
    param_3 = 0xb;
  }
  else if (param_3 == 0x19) goto LAB_40989a28;
  if ((param_4 == 4) || (param_4 == 0x11)) {
    param_4 = 0xb;
  }
  else if (param_4 == 0x19) {
    param_4 = 3;
  }
  if ((uVar2 == 4) || (uVar2 == 0x11)) {
    uVar2 = 0xb;
  }
  else if (uVar2 == 0x19) {
    uVar2 = 3;
  }
LAB_40989a8c:
  if (param_4 == 4) {
    param_4 = 0xb;
  }
  *(uint *)(iVar3 + 8) =
       ((param_2 & 0xffffc01f ^ param_3 << 5) << 6 ^ *(uint *)(iVar3 + 8) & 0xfff0003f) & 0xff0fffff
       ^ ((uVar2 & 0xf) << 4 ^ param_4 & 0xf) << 0x10;
  return;
}



/* 40989b10 FUN_40989b10 */

/* Boundary evidence: original MIPS .pdata 40989b10..40989b9b. Semantic name remains unreviewed. */

void FUN_40989b10(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x504);
  *(uint *)(iVar1 + 0x40) = *(uint *)(iVar1 + 0x40) & 0xffffffdf | param_2 << 5;
  FUN_409892a8(param_1);
  FUN_4098932c(param_1,*(undefined4 *)(iVar1 + 0x60),(uint)*(byte *)(iVar1 + 100));
  FUN_409891a8(param_1,*(uint *)(iVar1 + 0x40) >> 0xb & 1);
  FUN_40989228(param_1,*(uint *)(iVar1 + 0x40) >> 10 & 1);
  return;
}



/* 40989b9c FUN_40989b9c */

/* Boundary evidence: original MIPS .pdata 40989b9c..40989bdf. Semantic name remains unreviewed. */

void FUN_40989b9c(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x504);
  *(uint *)(iVar1 + 0x40) = *(uint *)(iVar1 + 0x40) & 0xffffffbf | param_2 << 6;
  FUN_4098932c(param_1,*(undefined4 *)(iVar1 + 0x60),(uint)*(byte *)(iVar1 + 100));
  return;
}



/* 40989be0 FUN_40989be0 */

/* Boundary evidence: original MIPS .pdata 40989be0..40989c97. Semantic name remains unreviewed. */

void FUN_40989be0(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x504);
  *(uint *)(iVar1 + 0x40) = *(uint *)(iVar1 + 0x40) & 0xffffffef | param_2 << 4;
  FUN_40989778(param_1,(uint)*(byte *)(iVar1 + 0x4f),(uint)*(byte *)(iVar1 + 0x50),
               (uint)*(byte *)(iVar1 + 0x51));
  FUN_4098951c(param_1,(uint)*(byte *)(iVar1 + 0x52));
  FUN_4098961c(param_1,(uint)*(byte *)(iVar1 + 0x53),(uint)*(byte *)(iVar1 + 0x54),
               (uint)*(byte *)(iVar1 + 0x55));
  FUN_409896c4(param_1,(uint)*(byte *)(iVar1 + 0x56),(uint)*(byte *)(iVar1 + 0x57),
               (uint)*(byte *)(iVar1 + 0x58));
  FUN_409894c0(param_1,(uint)*(byte *)(iVar1 + 0x59));
  FUN_40989574(param_1,(uint)*(byte *)(iVar1 + 0x5a),(uint)*(byte *)(iVar1 + 0x5b),
               (uint)*(byte *)(iVar1 + 0x5c));
  return;
}



/* 40989c98 FUN_40989c98 */

/* Boundary evidence: original MIPS .pdata 40989c98..40989cf7. Semantic name remains unreviewed. */

void FUN_40989c98(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x504);
  *(uint *)(iVar1 + 0x40) = *(uint *)(iVar1 + 0x40) & 0xfffffffd | param_2 << 1;
  FUN_4098982c(param_1,(uint)*(byte *)(iVar1 + 0x4d));
  FUN_40989888(param_1,(uint)*(byte *)(iVar1 + 0x4e));
  return;
}



/* 40989cf8 FUN_40989cf8 */

/* Boundary evidence: original MIPS .pdata 40989cf8..40989d57. Semantic name remains unreviewed. */

void FUN_40989cf8(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x504);
  *(uint *)(iVar1 + 0x40) = *(uint *)(iVar1 + 0x40) & 0xfffffff7 | param_2 << 3;
  if (param_2 == 0) {
    FUN_4098993c(param_1,(uint)*(byte *)(iVar1 + 0x48),(uint)*(byte *)(iVar1 + 0x49),
                 (uint)*(byte *)(iVar1 + 0x4a),*(byte *)(iVar1 + 0x4b));
  }
  else {
    FUN_409890b0(param_1,(uint)*(byte *)(iVar1 + 0x4c));
  }
  return;
}



/* 40989d58 FUN_40989d58 */

/* Boundary evidence: original MIPS .pdata 40989d58..40989da3. Semantic name remains unreviewed. */

void FUN_40989d58(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x504);
  *(uint *)(iVar1 + 0x40) = *(uint *)(iVar1 + 0x40) & 0xfffffffb | param_2 << 2;
  FUN_4098993c(param_1,(uint)*(byte *)(iVar1 + 0x48),(uint)*(byte *)(iVar1 + 0x49),
               (uint)*(byte *)(iVar1 + 0x4a),*(byte *)(iVar1 + 0x4b));
  return;
}



/* 40989da4 FUN_40989da4 */

/* Boundary evidence: original MIPS .pdata 40989da4..4098acdf. Semantic name remains unreviewed. */

undefined4 FUN_40989da4(undefined4 *param_1,uint param_2,uint param_3)

{
  undefined1 uVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  undefined4 uVar6;
  undefined4 *puVar7;
  byte bVar8;
  int iVar9;
  uint *puVar10;
  
  puVar7 = (undefined4 *)param_1[0x136];
  puVar10 = param_1 + 3;
  bVar8 = (byte)param_3;
  if (param_2 < 0xbf3) {
    if (param_2 == 0xbf2) {
      if ((*(uint *)(param_1[0x141] + 0x40) >> 3 & 1) == param_3) {
        return 0;
      }
      if ((param_1[1] == 1) && (puVar7[0x1968] != 0)) {
        FUN_40980504(param_1);
      }
      FUN_40989cf8((int)param_1,param_3);
      return 0;
    }
    if (param_2 < 0xb72) {
      if (param_2 == 0xb71) {
        if ((*(uint *)(param_1[0x141] + 0x40) >> 1 & 1) == param_3) {
          return 0;
        }
        if ((param_1[1] == 1) && (puVar7[0x1968] != 0)) {
          FUN_40980504(param_1);
        }
        FUN_40989c98((int)param_1,param_3);
        return 0;
      }
      if (param_2 == 0xb10) {
        if ((*(uint *)(param_1[0x141] + 0x40) >> 9 & 1) == param_3) {
          return 0;
        }
        if ((param_1[1] == 1) && (puVar7[0x1968] != 0)) {
          FUN_40980504(param_1);
        }
        iVar9 = param_1[0x141];
        uVar4 = param_3 << 9;
        uVar3 = *(uint *)(iVar9 + 0x40) & 0xfffffdff;
      }
      else {
        if (param_2 != 0xb20) {
          if (param_2 == 0xb44) {
            if ((param_1[1] == 1) && (puVar7[0x1968] != 0)) {
              FUN_40980504(param_1);
            }
            *(byte *)(param_1 + 0xfb) = bVar8;
            return 0;
          }
          if (param_2 != 0xb50) {
            if (param_2 == 0xb57) {
              if ((uint)(param_3 == 1) == (*(uint *)(param_1[0x142] + 0x1c) >> 4 & 1)) {
                return 0;
              }
              if ((param_1[1] == 1) && (puVar7[0x1968] != 0)) {
                FUN_40980504(param_1);
              }
              *(uint *)(param_1[0x142] + 0x1c) =
                   *(uint *)(param_1[0x142] + 0x1c) & 0xffffffef | (uint)(param_3 == 1) << 4;
              if (param_3 != 1) {
                return 0;
              }
              iVar9 = 4;
              do {
                iVar9 = iVar9 + -1;
                puVar7[0x17c5] = *puVar7;
                puVar7[0x17c9] = *puVar7;
                puVar7 = puVar7 + 1;
              } while (iVar9 != 0);
              return 0;
            }
            if (param_2 != 0xb60) {
              return 0x500;
            }
            if (param_3 == (*(uint *)(param_1[0x142] + 0x1c) >> 0xd & 1)) {
              return 0;
            }
            iVar9 = 0;
            if ((param_1[1] == 1) && (puVar7[0x1968] != 0)) {
              FUN_40980504(param_1);
            }
            *(uint *)(param_1[0x142] + 0x1c) =
                 *(uint *)(param_1[0x142] + 0x1c) & 0xffffdfff | (uint)(param_3 == 1) << 0xd;
            if (param_3 != 0) {
              iVar5 = puVar7[0x17c3];
              if (iVar5 == 0x800) {
                iVar9 = 2;
              }
              else if (iVar5 == 0x801) {
                iVar9 = 3;
              }
              else if (iVar5 == 0x2601) {
                iVar9 = 1;
              }
            }
            *(uint *)(param_1[0x142] + 0x20) =
                 *(uint *)(param_1[0x142] + 0x20) & 0xe7ffffff ^ iVar9 << 0x1b;
            return 0;
          }
          if (param_3 == *(byte *)(puVar7 + 0x17c4)) {
            return 0;
          }
          if ((param_1[1] == 1) && (puVar7[0x1968] != 0)) {
            FUN_40980504(param_1);
          }
          *(byte *)(puVar7 + 0x17c4) = bVar8;
          FUN_409854f8((int)param_1);
          if ((param_3 == 0) && (*(char *)(param_1 + 0x1d) == '\0')) {
            *(uint *)(param_1[0x142] + 0x20) =
                 *(uint *)(param_1[0x142] + 0x20) & 0xffe0ffff ^ 0x90000;
          }
          else {
            *(uint *)(param_1[0x142] + 0x20) =
                 *(uint *)(param_1[0x142] + 0x20) & 0xffe0ffff ^ 0xa0000;
          }
          if (*(char *)(puVar7 + 0x17c4) == '\0') {
            *(uint *)(param_1[0x142] + 0x1c) = *(uint *)(param_1[0x142] + 0x1c) & 0xfffff9ff;
            return 0;
          }
          if (*(char *)((int)puVar7 + 0x626a) == '\0') {
            iVar9 = param_1[0x142];
            uVar3 = *(uint *)(iVar9 + 0x1c) & 0xfffffbff | 0x200;
          }
          else {
            if (*(char *)((int)puVar7 + 0x626a) == '\x01') {
              iVar9 = param_1[0x142];
              uVar3 = *(uint *)(iVar9 + 0x1c) & 0xfffffdff | 0x400;
              goto LAB_4098a6a4;
            }
            iVar9 = param_1[0x142];
            uVar3 = *(uint *)(iVar9 + 0x1c) | 0x600;
          }
          *(uint *)(iVar9 + 0x1c) = uVar3;
          return 0;
        }
        if ((*(uint *)(param_1[0x141] + 0x40) >> 8 & 1) == param_3) {
          return 0;
        }
        if ((param_1[1] == 1) && (puVar7[0x1968] != 0)) {
          FUN_40980504(param_1);
        }
        iVar9 = param_1[0x141];
        uVar4 = *(uint *)(iVar9 + 0x40) & 0xfffffeff;
        uVar3 = param_3 << 8;
      }
      *(uint *)(iVar9 + 0x40) = uVar4 | uVar3;
      return 0;
    }
    if (param_2 == 0xb90) {
      if ((*(uint *)(param_1[0x141] + 0x40) >> 4 & 1) == param_3) {
        return 0;
      }
      if ((param_1[1] == 1) && (puVar7[0x1968] != 0)) {
        FUN_40980504(param_1);
      }
      FUN_40989be0((int)param_1,param_3);
      return 0;
    }
    if (param_2 != 0xba1) {
      if (param_2 == 0xbc0) {
        if ((*(uint *)(param_1[0x141] + 0x40) & 1) == param_3) {
          return 0;
        }
        if ((param_1[1] == 1) && (puVar7[0x1968] != 0)) {
          FUN_40980504(param_1);
        }
        FUN_40989450((int)param_1,param_3);
        return 0;
      }
      if (param_2 == 0xbd0) {
        if ((*(uint *)(param_1[0x141] + 0x38) >> 0xd & 1) == param_3) {
          return 0;
        }
        if ((param_1[1] == 1) && (puVar7[0x1968] != 0)) {
          FUN_40980504(param_1);
        }
        *(uint *)(param_1[0x141] + 0x38) =
             *(uint *)(param_1[0x141] + 0x38) & 0xffffdfff ^ param_3 << 0xd;
        return 0;
      }
      if (param_2 != 0xbe2) {
        return 0x500;
      }
      if ((*(uint *)(param_1[0x141] + 0x40) >> 2 & 1) == param_3) {
        return 0;
      }
      if ((param_1[1] == 1) && (puVar7[0x1968] != 0)) {
        FUN_40980504(param_1);
      }
      iVar9 = param_1[0x141];
      *(uint *)(iVar9 + 0x40) = param_3 << 2 | *(uint *)(iVar9 + 0x40) & 0xfffffffb;
      FUN_4098993c((int)param_1,(uint)*(byte *)(iVar9 + 0x48),(uint)*(byte *)(iVar9 + 0x49),
                   (uint)*(byte *)(iVar9 + 0x4a),*(byte *)(iVar9 + 0x4b));
      return 0;
    }
    if (param_3 == *(byte *)(puVar7 + 0x1576)) {
      return 0;
    }
    if ((param_1[1] == 1) && (puVar7[0x1968] != 0)) {
      FUN_40980504(param_1);
    }
    *(byte *)(puVar7 + 0x1576) = bVar8;
    if ((param_3 == 1) ||
       (((*(uint *)(param_1[0x142] + 0x1c) & 8) != 0 && (*(char *)((int)puVar7 + 0x55d9) != '\0'))))
    {
LAB_4098a980:
      iVar9 = param_1[0x142];
      uVar3 = *(uint *)(iVar9 + 0x1c);
LAB_4098ab8c:
      *(uint *)(iVar9 + 0x1c) = uVar3 | 1;
      return 0;
    }
LAB_4098a3ec:
    *(uint *)(param_1[0x142] + 0x1c) = *(uint *)(param_1[0x142] + 0x1c) & 0xfffffffe;
  }
  else {
    if (param_2 < 0x809e) {
      if (param_2 == 0x809d) {
        if ((*(uint *)(param_1[0x141] + 0x40) >> 5 & 1) == param_3) {
          return 0;
        }
        if ((param_1[1] == 1) && (puVar7[0x1968] != 0)) {
          FUN_40980504(param_1);
        }
        FUN_40989b10((int)param_1,param_3);
        return 0;
      }
      if (0x4007 < param_2) {
        if (param_2 == 0x8037) {
          if ((*(uint *)(param_1[0x141] + 0x40) >> 7 & 1) == param_3) {
            return 0;
          }
          if ((param_1[1] == 1) && (puVar7[0x1968] != 0)) {
            FUN_40980504(param_1);
          }
          iVar9 = param_1[0x141];
          uVar2 = *(undefined4 *)(iVar9 + 0x7c);
          uVar6 = *(undefined4 *)(iVar9 + 0x80);
          *(uint *)(iVar9 + 0x40) = param_3 << 7 | *(uint *)(iVar9 + 0x40) & 0xffffff7f;
          iVar9 = param_1[0x141];
          *(undefined4 *)(iVar9 + 0x7c) = uVar2;
          *(undefined4 *)(iVar9 + 0x80) = uVar6;
          iVar9 = param_1[0x141];
          uVar1 = FUN_40988b88(uVar2);
          *(undefined1 *)(iVar9 + 0x65) = uVar1;
          *(undefined1 *)(iVar9 + 0x66) = 0;
          return 0;
        }
        if (param_2 != 0x803a) {
          return 0x500;
        }
        if (param_3 == *(byte *)((int)puVar7 + 0x55d9)) {
          return 0;
        }
        if ((param_1[1] == 1) && (puVar7[0x1968] != 0)) {
          FUN_40980504(param_1);
        }
        *(byte *)((int)puVar7 + 0x55d9) = bVar8;
        if ((*(char *)(puVar7 + 0x1576) == '\x01') ||
           (((*(uint *)(param_1[0x142] + 0x1c) & 8) != 0 && (param_3 != 0)))) goto LAB_4098a980;
        goto LAB_4098a3ec;
      }
      if (param_2 < 0x4000) {
        if (param_2 == 0xc11) {
          if (param_3 == (*(ushort *)((int)param_1 + 0xe) & 1)) {
            return 0;
          }
          if ((param_1[1] == 1) && (puVar7[0x1968] != 0)) {
            FUN_40980504(param_1);
          }
          if (param_3 != 0) {
            *puVar10 = *puVar10 | 0x10000;
            return 0;
          }
          *puVar10 = *puVar10 & 0xfffeffff;
          return 0;
        }
        if (param_2 != 0xde1) {
          if (param_2 < 0x3000) {
            return 0x500;
          }
          if (0x3005 < param_2) {
            return 0x500;
          }
          if (param_2 != 0x3000) {
            return 0x500;
          }
          if (param_3 == (*(uint *)(param_1[0x142] + 0x1c) >> 0xe & 1)) {
            return 0;
          }
          if ((param_1[1] == 1) && (puVar7[0x1968] != 0)) {
            FUN_40980504(param_1);
          }
          *(uint *)(param_1[0x142] + 0x1c) =
               (uint)(param_3 == 1) << 0xe | *(uint *)(param_1[0x142] + 0x1c) & 0xffffbfff;
          *(uint *)(param_1[0x142] + 0x20) =
               *(uint *)(param_1[0x142] + 0x20) & 0xbfffffff ^ param_3 << 0x1e;
          return 0;
        }
        uVar3 = param_1[0xca];
        if (param_3 == (byte)puVar10[(uVar3 + 0x28) * 5]) {
          return 0;
        }
        if ((param_1[1] == 1) && (puVar7[0x1968] != 0)) {
          FUN_40980504(param_1);
        }
        *(byte *)(puVar10 + (uVar3 + 0x28) * 5) = bVar8;
        if (param_3 == 1) {
          if ((*(uint *)(param_1[0x136] + 0x50a8) & 1 << (uVar3 & 0x1f)) == 0) {
            uVar3 = (uVar3 + 8) * 2;
            *(uint *)(param_1[0x142] + 0x1c) =
                 ~(3 << (uVar3 & 0x1f)) & *(uint *)(param_1[0x142] + 0x1c) | 1 << (uVar3 & 0x1f);
            return 0;
          }
          uVar3 = (uVar3 + 8) * 2;
          *(uint *)(param_1[0x142] + 0x1c) =
               ~(3 << (uVar3 & 0x1f)) & *(uint *)(param_1[0x142] + 0x1c) | 2 << (uVar3 & 0x1f);
          return 0;
        }
        iVar9 = param_1[0x142];
        uVar3 = ~(3 << ((uVar3 + 8) * 2 & 0x1f)) & *(uint *)(iVar9 + 0x1c);
LAB_4098a6a4:
        *(uint *)(iVar9 + 0x1c) = uVar3;
        return 0;
      }
      uVar3 = param_2 - 0x4000;
      if (((int)uVar3 < 0) || (7 < (int)uVar3)) {
        return 0x500;
      }
      iVar9 = (int)uVar3 >> 5;
      uVar4 = uVar3 & 0x1f;
      if (param_3 == (puVar10[iVar9] >> uVar4 & 1)) {
        return 0;
      }
      if ((param_1[1] == 1) && (puVar7[0x1968] != 0)) {
        FUN_40980504(param_1);
      }
      if (param_3 == 1) {
        puVar10[iVar9] = 1 << uVar4 | puVar10[iVar9];
        *(char *)((int)puVar7 + 0x626a) = *(char *)((int)puVar7 + 0x626a) + '\x01';
      }
      else {
        puVar10[iVar9] = ~(1 << uVar4) & puVar10[iVar9];
        *(char *)((int)puVar7 + 0x626a) = *(char *)((int)puVar7 + 0x626a) + -1;
      }
      FUN_409854f8((int)param_1);
      if (*(char *)(puVar7 + 0x17c4) != '\0') {
        if (*(char *)((int)puVar7 + 0x626a) == '\0') {
          *(uint *)(param_1[0x142] + 0x1c) = *(uint *)(param_1[0x142] + 0x1c) & 0xfffffbff | 0x200;
        }
        else if (*(char *)((int)puVar7 + 0x626a) == '\x01') {
          *(uint *)(param_1[0x142] + 0x1c) = *(uint *)(param_1[0x142] + 0x1c) & 0xfffffdff | 0x400;
        }
        else {
          *(uint *)(param_1[0x142] + 0x1c) = *(uint *)(param_1[0x142] + 0x1c) | 0x600;
        }
      }
      uVar4 = param_3 << (uVar3 & 0x1f);
      uVar3 = ~(1 << (uVar3 & 0x1f)) & (uint)*(byte *)(puVar7 + 0x189b);
      *(byte *)(puVar7 + 0x189b) = (byte)uVar3 | (byte)uVar4;
      *(uint *)(param_1[0x142] + 0x1c) =
           (uint)(((uint)*(byte *)((int)puVar7 + 0x6269) & (uVar3 | uVar4 & 0xff)) != 0) << 6 |
           *(uint *)(param_1[0x142] + 0x1c) & 0xffffffbf;
      *(uint *)(param_1[0x142] + 0x1c) =
           (uint)((*(byte *)((int)puVar7 + 0x626b) & *(byte *)(puVar7 + 0x189b)) != 0) << 5 |
           *(uint *)(param_1[0x142] + 0x1c) & 0xffffffdf;
      iVar9 = param_1[0x142];
      uVar3 = (uint)((*(byte *)(puVar7 + 0x189a) & *(byte *)(puVar7 + 0x189b)) != 0) << 7 |
              *(uint *)(iVar9 + 0x1c) & 0xffffff7f;
    }
    else {
      if (param_2 == 0x809e) {
        if ((*(uint *)(param_1[0x141] + 0x40) >> 10 & 1) == param_3) {
          return 0;
        }
        if ((param_1[1] == 1) && (puVar7[0x1968] != 0)) {
          FUN_40980504(param_1);
        }
        FUN_40989228((int)param_1,param_3);
        return 0;
      }
      if (param_2 == 0x809f) {
        if ((*(uint *)(param_1[0x141] + 0x40) >> 0xb & 1) == param_3) {
          return 0;
        }
        if ((param_1[1] == 1) && (puVar7[0x1968] != 0)) {
          FUN_40980504(param_1);
        }
        FUN_409891a8((int)param_1,param_3);
        return 0;
      }
      if (param_2 == 0x80a0) {
        if ((*(uint *)(param_1[0x141] + 0x40) >> 6 & 1) == param_3) {
          return 0;
        }
        if ((param_1[1] == 1) && (puVar7[0x1968] != 0)) {
          FUN_40980504(param_1);
        }
        iVar9 = param_1[0x141];
        *(uint *)(iVar9 + 0x40) = *(uint *)(iVar9 + 0x40) & 0xffffffbf | param_3 << 6;
        FUN_4098932c((int)param_1,*(undefined4 *)(iVar9 + 0x60),(uint)*(byte *)(iVar9 + 100));
        return 0;
      }
      if (param_2 != 0x8840) {
        if (param_2 == 0x8861) {
          if ((param_1[1] == 1) && (puVar7[0x1968] != 0)) {
            FUN_40980504(param_1);
          }
          *(byte *)(puVar7 + 0x1960) = bVar8;
          return 0;
        }
        return 0x500;
      }
      if (param_3 == (*(uint *)(param_1[0x142] + 0x1c) >> 3 & 1)) {
        return 0;
      }
      if ((param_1[1] == 1) && (puVar7[0x1968] != 0)) {
        FUN_40980504(param_1);
      }
      *(uint *)(param_1[0x142] + 0x1c) =
           (uint)(param_3 == 1) << 3 | *(uint *)(param_1[0x142] + 0x1c) & 0xfffffff7;
      if ((*(char *)(puVar7 + 0x1576) == '\x01') ||
         (((*(uint *)(param_1[0x142] + 0x1c) & 8) != 0 && (*(char *)((int)puVar7 + 0x55d9) != '\0'))
         )) {
        iVar9 = param_1[0x142];
        uVar3 = *(uint *)(iVar9 + 0x1c);
        goto LAB_4098ab8c;
      }
      iVar9 = param_1[0x142];
      uVar3 = *(uint *)(iVar9 + 0x1c) & 0xfffffffe;
    }
    *(uint *)(iVar9 + 0x1c) = uVar3;
  }
  return 0;
}



/* 4098ace0 FUN_4098ace0 */

/* Boundary evidence: original MIPS .pdata 4098ace0..4098aef7. Semantic name remains unreviewed. */

undefined4 FUN_4098ace0(undefined4 *param_1,int param_2,uint param_3)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  
  if (param_2 == 0x8074) {
    uVar2 = 0;
  }
  else {
    if (param_2 == 0x8075) {
      uVar2 = 1;
      goto LAB_4098ad84;
    }
    if (param_2 == 0x8076) {
      uVar2 = 2;
      if ((param_1[1] == 1) && (*(int *)(param_1[0x136] + 0x65a0) != 0)) {
        FUN_40980504(param_1);
      }
      if ((*(char *)(param_1[0x136] + 0x5f10) == '\0') && (param_3 == 0)) {
        *(uint *)(param_1[0x142] + 0x20) = *(uint *)(param_1[0x142] + 0x20) & 0xffe0ffff ^ 0x90000;
      }
      else {
        *(uint *)(param_1[0x142] + 0x20) = *(uint *)(param_1[0x142] + 0x20) & 0xffe0ffff ^ 0xa0000;
      }
      goto LAB_4098ad84;
    }
    if (param_2 != 0x8078) {
      if (param_2 == 0x86ad) {
        uVar2 = 4;
      }
      else if (param_2 == 0x8844) {
        uVar2 = 5;
      }
      else {
        if (param_2 != 0x8b9c) {
          return 0x500;
        }
        iVar3 = 1;
        uVar2 = 3;
        if (param_3 == 1) {
          *(uint *)(param_1[0x142] + 0x1c) = *(uint *)(param_1[0x142] + 0x1c) | 0x1000;
        }
        else {
          iVar4 = param_1[0x136];
          iVar1 = __nes(*(undefined4 *)(iVar4 + 0x6294),0x3f800000);
          if (((iVar1 == 0) && (iVar1 = __nes(*(undefined4 *)(iVar4 + 0x6298),0), iVar1 == 0)) &&
             (iVar1 = __nes(*(undefined4 *)(iVar4 + 0x629c),0), iVar1 == 0)) {
            iVar3 = 0;
          }
          *(uint *)(param_1[0x142] + 0x1c) =
               iVar3 << 0xc | *(uint *)(param_1[0x142] + 0x1c) & 0xffffefff;
        }
      }
      goto LAB_4098ad84;
    }
    uVar2 = *(byte *)(param_1 + 0xc9) + 6;
  }
  if (0xf < uVar2) {
    return 0x501;
  }
LAB_4098ad84:
  if (param_3 != *(byte *)(param_1 + uVar2 * 0xc + 5)) {
    *(char *)(param_1 + uVar2 * 0xc + 5) = (char)param_3;
  }
  return 0;
}



/* 4098af88 FUN_4098af88 */

/* Boundary evidence: original MIPS .pdata 4098af88..4098afa3. Semantic name remains unreviewed. */

void FUN_4098af88(int param_1)

{
  mali_sys_atomic_inc(param_1 + 0x50);
  return;
}



/* 4098afa4 FUN_4098afa4 */

/* Boundary evidence: original MIPS .pdata 4098afa4..4098afdf. Semantic name remains unreviewed. */

undefined4 FUN_4098afa4(int param_1,uint param_2)

{
  undefined4 uVar1;
  
  if (param_2 < 0x100) {
    uVar1 = *(undefined4 *)((param_2 + 7) * 4 + param_1);
  }
  else {
    uVar1 = __mali_named_list_get_non_flat();
  }
  return uVar1;
}



/* 4098b01c FUN_4098b01c */

/* Boundary evidence: original MIPS .pdata 4098b01c..4098b0d3. Semantic name remains unreviewed. */

undefined4 FUN_4098b01c(int param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  uint in_stack_0000001c;
  
  if (param_2 == 0xde1) {
    if ((in_stack_0000001c < 0x8b90) ||
       ((0x8b99 < in_stack_0000001c && (in_stack_0000001c != 0x8d64)))) {
      uVar1 = 0x501;
    }
    else {
      uVar1 = FUN_4097aaf0(((int *)(param_1 + 0x328))[*(int *)(param_1 + 0x328) * 5 + 2],param_1,
                           0xde1,param_3);
    }
  }
  else {
    uVar1 = 0x500;
  }
  return uVar1;
}



/* 4098b0d4 FUN_4098b0d4 */

/* Boundary evidence: original MIPS .pdata 4098b0d4..4098b13b. Semantic name remains unreviewed. */

undefined4 FUN_4098b0d4(undefined4 *param_1,int param_2,undefined4 param_3)

{
  undefined4 uVar1;
  int iVar2;
  
  if (param_2 == 0xde1) {
    iVar2 = (param_1 + 0xca)[param_1[0xca] * 5 + 2];
    if (*(int *)(iVar2 + 0x34) == 0) {
      uVar1 = 0x505;
    }
    else {
      uVar1 = FUN_4097b20c(iVar2,param_1,0xde1,param_3);
    }
  }
  else {
    uVar1 = 0x500;
  }
  return uVar1;
}



/* 4098b13c FUN_4098b13c */

/* Boundary evidence: original MIPS .pdata 4098b13c..4098b27f. Semantic name remains unreviewed. */

undefined4 FUN_4098b13c(int param_1,int param_2,uint *param_3)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  
  if (param_2 < 0) {
    uVar1 = 0x501;
  }
  else {
    if (param_3 != (uint *)0x0) {
      iVar6 = *(int *)(*(int *)(param_1 + 0x4e8) + 4);
      if (0 < param_2) {
        do {
          uVar4 = *param_3;
          if (uVar4 != 0) {
            if (uVar4 < 0x100) {
              iVar3 = *(int *)((uVar4 + 7) * 4 + iVar6);
            }
            else {
              iVar3 = __mali_named_list_get_non_flat(iVar6,uVar4);
            }
            if (iVar3 != 0) {
              if (*(int *)(iVar3 + 4) != 0) {
                FUN_409834f8(param_1 + 0x328,uVar4,(int *)(param_1 + 0x4dc));
                if (*(int *)(iVar3 + 4) != 0) {
                  *(undefined4 *)(*(int *)(iVar3 + 4) + 0x44) = 1;
                }
                iVar5 = *(int *)(iVar3 + 4);
                iVar2 = mali_sys_atomic_dec_and_return(iVar5 + 0x50);
                if (iVar2 == 0) {
                  FUN_4097b168(iVar5);
                }
                *(undefined4 *)(iVar3 + 4) = 0;
              }
              __mali_named_list_remove(iVar6,uVar4);
              mali_sys_free(iVar3);
            }
          }
          param_3 = param_3 + 1;
          param_2 = param_2 + -1;
        } while (param_2 != 0);
      }
    }
    uVar1 = 0;
  }
  return uVar1;
}



/* 4098b280 FUN_4098b280 */

/* Boundary evidence: original MIPS .pdata 4098b280..4098b363. Semantic name remains unreviewed. */

undefined4
FUN_4098b280(undefined4 *param_1,int param_2,uint param_3,uint param_4,uint param_5,uint param_6,
            int param_7)

{
  undefined4 uVar1;
  
  if (param_2 == 0xde1) {
    if (((((param_5 == 0) || ((param_5 - 1 & param_5) == 0)) &&
         ((param_6 == 0 || ((param_6 - 1 & param_6) == 0)))) && (0x8b8f < param_4)) &&
       (((param_4 < 0x8b9a || (param_4 == 0x8d64)) && (param_7 == 0)))) {
      uVar1 = FUN_4097b4ac((param_1 + 0xca)[param_1[0xca] * 5 + 2],param_1,0xde1,param_3);
    }
    else {
      uVar1 = 0x501;
    }
  }
  else {
    uVar1 = 0x500;
  }
  return uVar1;
}



/* 4098b364 FUN_4098b364 */

/* Boundary evidence: original MIPS .pdata 4098b364..4098b4d7. Semantic name remains unreviewed. */

void FUN_4098b364(undefined4 *param_1,int param_2,uint param_3)

{
  int iVar1;
  int iVar2;
  uint in_stack_00000068;
  uint in_stack_0000006c;
  int in_stack_00000074;
  int in_stack_00000078;
  int in_stack_00000080;
  
  FUN_40993300();
  if (((((in_stack_00000068 == 0) || ((in_stack_00000068 - 1 & in_stack_00000068) == 0)) &&
       ((in_stack_0000006c == 0 || ((in_stack_0000006c - 1 & in_stack_0000006c) == 0)))) &&
      (param_2 == 0xde1)) &&
     ((((iVar2 = (param_1 + 0xca)[param_1[0xca] * 5 + 2], *(char *)(iVar2 + 0x14) == '\0' ||
        (param_3 != 0)) || (in_stack_00000078 != 0x1403)) ||
      ((in_stack_00000074 != 0x1908 && (in_stack_00000074 != 0x190a)))))) {
    FUN_4097a0a0(in_stack_00000080,in_stack_00000068,in_stack_00000074,in_stack_00000078);
    iVar1 = FUN_4097c7d0(iVar2,param_1,0xde1,param_3);
    if ((iVar1 == 0) && ((*(char *)(iVar2 + 0x14) != '\0' && (param_3 == 0)))) {
      FUN_40975a38(iVar2,param_1,0xde1);
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_40993338(0x30);
}



/* 4098b4d8 FUN_4098b4d8 */

/* Boundary evidence: original MIPS .pdata 4098b4d8..4098b58b. Semantic name remains unreviewed. */

void FUN_4098b4d8(undefined4 *param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  
  FUN_40993370();
  if (param_2 == 0xde1) {
    iVar2 = (param_1 + 0xca)[param_1[0xca] * 5 + 2];
    iVar1 = FUN_4097c0b8(iVar2,param_1,0xde1,param_3);
    if (((iVar1 == 0) && (*(char *)(iVar2 + 0x14) != '\0')) && (param_3 == 0)) {
      FUN_4096bbcc(param_1,iVar2,0xde1);
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_40993390(0x28);
}



/* 4098b58c FUN_4098b58c */

/* Boundary evidence: original MIPS .pdata 4098b58c..4098b63f. Semantic name remains unreviewed. */

void FUN_4098b58c(undefined4 *param_1,int param_2,uint param_3)

{
  int iVar1;
  int iVar2;
  
  FUN_40993370();
  if (param_2 == 0xde1) {
    iVar2 = (param_1 + 0xca)[param_1[0xca] * 5 + 2];
    iVar1 = FUN_4097c374(iVar2,param_1,0xde1,param_3);
    if (((iVar1 == 0) && (*(char *)(iVar2 + 0x14) != '\0')) && (param_3 == 0)) {
      FUN_4096bbcc(param_1,iVar2,0xde1);
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_40993390(0x28);
}



/* 4098b640 gles1_bind_tex_image */

/* Boundary evidence: original MIPS .pdata 4098b640..4098b747. Semantic name remains unreviewed.
   gles1_bind_tex_image */

undefined4
gles1_bind_tex_image
          (undefined4 *param_1,int param_2,uint param_3,undefined4 param_4,undefined4 param_5,
          int param_6)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  
                    /* 0x2b640  2  _gles1_bind_tex_image */
  if (param_2 == 0xde1) {
    iVar2 = (param_1 + 0xca)[param_1[0xca] * 5 + 2];
    if ((((((-1 < (int)param_3) && ((int)param_3 < 0xd)) &&
          (uVar3 = (uint)*(ushort *)(param_6 + 0xc), uVar3 < 0x1001)) &&
         ((uVar4 = (uint)*(ushort *)(param_6 + 0xe), uVar4 < 0x1001 &&
          ((int)(uVar3 << (param_3 & 0x1f)) < 0x1001)))) &&
        (((int)(uVar4 << (param_3 & 0x1f)) < 0x1001 && ((uVar3 == 0 || ((uVar3 - 1 & uVar3) == 0))))
        )) && ((uVar4 == 0 || ((uVar4 - 1 & uVar4) == 0)))) {
      if (*(int *)(iVar2 + 0x34) == 0) {
        return 0x505;
      }
      uVar1 = FUN_4097c92c(iVar2,param_1,0xde1,param_3);
      return uVar1;
    }
    uVar1 = 0x501;
  }
  else {
    uVar1 = 0x500;
  }
  return uVar1;
}



/* 4098b748 FUN_4098b748 */

/* Boundary evidence: original MIPS .pdata 4098b748..4098b847. Semantic name remains unreviewed. */

void FUN_4098b748(undefined4 *param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int in_stack_0000005c;
  int in_stack_00000060;
  
  FUN_40993370();
  if ((((param_2 == 0xde1) &&
       ((((iVar2 = (param_1 + 0xca)[param_1[0xca] * 5 + 2], *(char *)(iVar2 + 0x14) == '\0' ||
          (param_3 != 0)) || (in_stack_00000060 != 0x1403)) ||
        ((in_stack_0000005c != 0x1908 && (in_stack_0000005c != 0x190a)))))) &&
      (iVar1 = FUN_4097c628(iVar2,param_1,0xde1,param_3), iVar1 == 0)) &&
     ((*(char *)(iVar2 + 0x14) != '\0' && (param_3 == 0)))) {
    FUN_4096bbcc(param_1,iVar2,0xde1);
  }
                    /* WARNING: Subroutine does not return */
  FUN_40993390(0x30);
}



/* 4098b848 gles1_unbind_tex_image */

/* Boundary evidence: original MIPS .pdata 4098b848..4098b97f. Semantic name remains unreviewed.
   gles1_unbind_tex_image */

void gles1_unbind_tex_image(undefined4 *param_1)

{
  int iVar1;
  int iVar2;
  
                    /* 0x2b848  6  _gles1_unbind_tex_image */
  if ((param_1[1] == 1) && (*(int *)(param_1[0x136] + 0x65a0) != 0)) {
    FUN_40980504(param_1);
  }
  iVar2 = (param_1 + 0xca)[param_1[0xca] * 5 + 2];
  FUN_4097a0a0(8,1,0x1907,0x1401);
  iVar1 = FUN_4097c7d0(iVar2,param_1,0xde1,0);
  if ((iVar1 == 0) && (*(char *)(iVar2 + 0x14) != '\0')) {
    FUN_40975a38(iVar2,param_1,0xde1);
  }
  return;
}



/* 4098b980 FUN_4098b980 */

/* Boundary evidence: original MIPS .pdata 4098b980..4098ba8f. Semantic name remains unreviewed. */

void FUN_4098b980(undefined4 *param_1,int param_2,uint param_3,undefined4 param_4,uint param_5)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  undefined1 auStackX_0 [16];
  
  FUN_40993230();
  iVar3 = 0;
  if (param_2 == 0xde1) {
    piVar4 = param_1 + 0xca;
    if (auStackX_0 != (undefined1 *)0xfffffff0) {
      param_5 = piVar4[*piVar4 * 5 + 4];
      iVar3 = piVar4[*piVar4 * 5 + 2];
    }
    if ((param_5 != param_3) || (*(int *)(iVar3 + 0x44) != 0)) {
      if ((param_1[1] == 1) && (*(int *)(param_1[0x136] + 0x65a0) != 0)) {
        FUN_40980504(param_1);
      }
      piVar1 = (int *)FUN_4097befc((int)param_1,param_3,0);
      if ((piVar1 != (int *)0x0) && (*piVar1 == 0)) {
        iVar2 = *piVar4;
        piVar4[iVar2 * 5 + 4] = param_3;
        piVar4[iVar2 * 5 + 2] = (int)piVar1;
        mali_sys_atomic_inc(piVar1 + 0x14);
        iVar2 = mali_sys_atomic_dec_and_return(iVar3 + 0x50);
        if (iVar2 == 0) {
          FUN_4097b168(iVar3);
        }
      }
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_40993258(0x18);
}



/* 4098ba90 FUN_4098ba90 */

void FUN_4098ba90(int param_1,uint param_2)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  
  **(uint **)(*(int *)(param_1 + 0x4d8) + 0x50a0) = param_2;
  iVar1 = *(int *)(param_1 + 0x4d8);
  if (*(int *)(iVar1 + 0x55d4) == 0x1702) {
    uVar3 = *(uint *)(iVar1 + 0x50a4);
    uVar2 = 1 << (uVar3 & 0x1f);
    if (param_2 != ((*(uint *)(iVar1 + 0x50a8) & uVar2) == 0)) {
      *(uint *)(*(int *)(param_1 + 0x4d8) + 0x50a8) =
           ~uVar2 & *(uint *)(*(int *)(param_1 + 0x4d8) + 0x50a8);
      if (param_2 == 1) {
        uVar2 = 0;
      }
      *(uint *)(*(int *)(param_1 + 0x4d8) + 0x50a8) =
           *(uint *)(*(int *)(param_1 + 0x4d8) + 0x50a8) | uVar2;
      if (*(char *)((uVar3 + 0x28) * 0x14 + param_1 + 0xc) == '\x01') {
        if (param_2 == 1) {
          uVar2 = (uVar3 + 8) * 2;
          *(uint *)(*(int *)(param_1 + 0x508) + 0x1c) =
               ~(3 << (uVar2 & 0x1f)) & *(uint *)(*(int *)(param_1 + 0x508) + 0x1c) |
               1 << (uVar2 & 0x1f);
        }
        else {
          uVar2 = (uVar3 + 8) * 2;
          *(uint *)(*(int *)(param_1 + 0x508) + 0x1c) =
               ~(3 << (uVar2 & 0x1f)) & *(uint *)(*(int *)(param_1 + 0x508) + 0x1c) |
               2 << (uVar2 & 0x1f);
        }
      }
      else {
        *(uint *)(*(int *)(param_1 + 0x508) + 0x1c) =
             ~(3 << ((uVar3 + 8) * 2 & 0x1f)) & *(uint *)(*(int *)(param_1 + 0x508) + 0x1c);
      }
    }
  }
  return;
}



/* 4098bc0c FUN_4098bc0c */

int FUN_4098bc0c(uint param_1)

{
  int iVar1;
  
  iVar1 = 0;
  if ((param_1 & 0xffff0000) == 0) {
    iVar1 = 0x10;
  }
  else {
    param_1 = param_1 >> 0x10;
  }
  if ((param_1 & 0xff00) == 0) {
    iVar1 = iVar1 + 8;
  }
  else {
    param_1 = param_1 >> 8;
  }
  return (uint)(byte)(&DAT_4096203c)[param_1] + iVar1;
}



/* 4098bc58 FUN_4098bc58 */

/* Boundary evidence: original MIPS .pdata 4098bc58..4098bc73. Semantic name remains unreviewed. */

void FUN_4098bc58(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3)

{
  FUN_40969e90(param_1,param_2,param_3);
  return;
}



/* 4098bc74 FUN_4098bc74 */

/* Boundary evidence: original MIPS .pdata 4098bc74..4098bc8f. Semantic name remains unreviewed. */

void FUN_4098bc74(undefined4 param_1,undefined4 param_2)

{
  mali_sys_memcpy(param_1,param_2,0x40);
  return;
}



/* 4098bc90 FUN_4098bc90 */

/* Boundary evidence: original MIPS .pdata 4098bc90..4098bcbf. Semantic name remains unreviewed. */

void FUN_4098bc90(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,undefined4 param_7)

{
  FUN_4096a570(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
  return;
}



/* 4098bcc0 FUN_4098bcc0 */

/* Boundary evidence: original MIPS .pdata 4098bcc0..4098bcef. Semantic name remains unreviewed. */

void FUN_4098bcc0(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,undefined4 param_7)

{
  FUN_4096a714(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
  return;
}



/* 4098bd38 FUN_4098bd38 */

/* Boundary evidence: original MIPS .pdata 4098bd38..4098bdbb. Semantic name remains unreviewed. */

void FUN_4098bd38(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  uVar1 = __fpmul(param_6,param_3);
  uVar2 = __fpmul(param_5,param_2);
  uVar1 = __fpadd(uVar1,uVar2);
  uVar2 = __fpmul(param_4,param_1);
  __fpadd(uVar1,uVar2);
  return;
}



/* 4098bdbc FUN_4098bdbc */

/* Boundary evidence: original MIPS .pdata 4098bdbc..4098be37. Semantic name remains unreviewed. */

undefined4 *
FUN_4098bdbc(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5)

{
  undefined4 uVar1;
  
  uVar1 = __fpmul(param_2,param_5);
  *param_1 = uVar1;
  uVar1 = __fpmul(param_3,param_5);
  param_1[1] = uVar1;
  uVar1 = __fpmul(param_4,param_5);
  param_1[2] = uVar1;
  return param_1;
}



/* 4098be38 FUN_4098be38 */

/* Boundary evidence: original MIPS .pdata 4098be38..4098bf8b. Semantic name remains unreviewed. */

undefined4 FUN_4098be38(int param_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  uint *puVar8;
  
  iVar5 = *(int *)(param_1 + 0x4d8);
  iVar7 = iVar5 + 0x9c;
  iVar1 = *(int *)(iVar5 + 0x55d4);
  if (iVar1 == 0x1700) {
    puVar8 = (uint *)(iVar5 + 0x55ac);
    iVar1 = iVar5 + 0x50ac;
  }
  else {
    if (iVar1 != 0x1701) {
      if (iVar1 != 0x1702) {
        if (iVar1 != 0x8840) {
          return 0;
        }
        return 0x503;
      }
      iVar4 = *(int *)(param_1 + 0x328);
      puVar8 = (uint *)((iVar4 + 0x1546) * 4 + iVar7);
      uVar2 = *puVar8;
      iVar1 = iVar4 * 0x80 + iVar7 + 0x5110;
      iVar7 = (iVar4 + 2) * 0x800 + iVar7;
      goto joined_r0x4098bf7c;
    }
    puVar8 = (uint *)(iVar5 + 0x55b0);
    iVar1 = iVar5 + 0x512c;
    iVar7 = iVar5 + 0x89c;
  }
  uVar2 = *puVar8;
joined_r0x4098bf7c:
  if (uVar2 < 0x20) {
    uVar2 = *puVar8;
    uVar3 = uVar2 + 1;
    uVar6 = **(uint **)(iVar5 + 0x50a0);
    iVar4 = uVar3 * 0x40 + iVar7 + -0x40;
    *puVar8 = uVar3;
    mali_sys_memcpy(iVar4,uVar2 * 0x40 + iVar7 + -0x40,0x40);
    *(int *)(iVar5 + 0x509c) = iVar4;
    *(uint *)(iVar5 + 0x50a0) = *puVar8 * 4 + iVar1 + -4;
    FUN_4098ba90(param_1,uVar6);
    return 0;
  }
  return 0x503;
}



/* 4098bfb8 FUN_4098bfb8 */

/* Boundary evidence: original MIPS .pdata 4098bfb8..4098c02f. Semantic name remains unreviewed. */

void FUN_4098bfb8(uint param_1)

{
  FUN_40993370();
  if (param_1 != 0) {
    if ((int)param_1 < 0) {
      param_1 = -param_1;
    }
    FUN_4098bc0c(param_1);
  }
                    /* WARNING: Subroutine does not return */
  FUN_40993390(0x10);
}



/* 4098c030 FUN_4098c030 */

/* Boundary evidence: original MIPS .pdata 4098c030..4098c057. Semantic name remains unreviewed. */

void FUN_4098c030(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6)

{
  FUN_4098bd38(param_1,param_2,param_3,param_4,param_5,param_6);
  return;
}



/* 4098c058 FUN_4098c058 */

/* Boundary evidence: original MIPS .pdata 4098c058..4098c0bb. Semantic name remains unreviewed. */

void FUN_4098c058(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 in_stack_00000038;
  
  FUN_40993230();
  uVar1 = __fpmul(param_2,in_stack_00000038);
  uVar2 = __fpmul(param_3,in_stack_00000038);
  uVar3 = __fpmul(param_4,in_stack_00000038);
  param_1[2] = uVar3;
  *param_1 = uVar1;
  param_1[1] = uVar2;
                    /* WARNING: Subroutine does not return */
  FUN_40993258(0x10);
}



/* 4098c188 FUN_4098c188 */

/* Boundary evidence: original MIPS .pdata 4098c188..4098c227. Semantic name remains unreviewed. */

void FUN_4098c188(undefined4 *param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  
  if (param_2 == 0x1700) {
    uVar2 = param_1[3] | 0x100000;
  }
  else {
    if (param_2 == 0x1701) {
      iVar1 = param_1[1];
    }
    else {
      if (param_2 != 0x1702) {
        return;
      }
      iVar1 = param_1[1];
    }
    if ((iVar1 == 1) && (*(int *)(param_1[0x136] + 0x65a0) != 0)) {
      FUN_40980504(param_1);
    }
    uVar2 = param_1[3] | 0x200000;
  }
  param_1[3] = uVar2;
  return;
}



/* 4098c228 FUN_4098c228 */

/* Boundary evidence: original MIPS .pdata 4098c228..4098c343. Semantic name remains unreviewed. */

void FUN_4098c228(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 in_stack_00000098;
  undefined4 in_stack_0000009c;
  undefined4 in_stack_000000a0;
  
  FUN_40993300();
  puVar3 = *(undefined4 **)(param_1[0x136] + 0x509c);
  iVar4 = **(int **)(param_1[0x136] + 0x50a0);
  uVar1 = __fpsub(param_3,param_2);
  iVar2 = __eqs(uVar1,0);
  if (iVar2 == 0) {
    uVar1 = __fpsub(in_stack_0000009c,in_stack_000000a0);
    iVar2 = __eqs(uVar1,0);
    if (iVar2 == 0) {
      uVar1 = __fpsub(in_stack_00000098,param_4);
      iVar2 = __eqs(uVar1,0);
      if (iVar2 == 0) {
        FUN_4098c188(param_1,*(int *)(param_1[0x136] + 0x55d4));
        FUN_4096a570((undefined4 *)&stack0x00000020,param_2,param_3,param_4,in_stack_00000098,
                     in_stack_0000009c,in_stack_000000a0);
        if (iVar4 == 1) {
          mali_sys_memcpy(puVar3,&stack0x00000020,0x40);
          FUN_4098ba90((int)param_1,0);
        }
        else {
          FUN_40969e90(puVar3,puVar3,(undefined4 *)&stack0x00000020);
        }
      }
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_40993338(0x60);
}



/* 4098c344 FUN_4098c344 */

/* Boundary evidence: original MIPS .pdata 4098c344..4098c487. Semantic name remains unreviewed. */

void FUN_4098c344(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 in_stack_00000098;
  undefined4 in_stack_0000009c;
  undefined4 in_stack_000000a0;
  
  FUN_40993300();
  puVar3 = *(undefined4 **)(param_1[0x136] + 0x509c);
  iVar4 = **(int **)(param_1[0x136] + 0x50a0);
  iVar1 = __les(in_stack_0000009c,0);
  if ((iVar1 == 0) && (iVar1 = __les(in_stack_000000a0,0), iVar1 == 0)) {
    uVar2 = __fpsub(param_3,param_2);
    iVar1 = __eqs(uVar2,0);
    if (iVar1 == 0) {
      uVar2 = __fpsub(in_stack_0000009c,in_stack_000000a0);
      iVar1 = __eqs(uVar2,0);
      if (iVar1 == 0) {
        uVar2 = __fpsub(in_stack_00000098,param_4);
        iVar1 = __eqs(uVar2,0);
        if (iVar1 == 0) {
          FUN_4098c188(param_1,*(int *)(param_1[0x136] + 0x55d4));
          FUN_4096a714((undefined4 *)&stack0x00000020,param_2,param_3,param_4,in_stack_00000098,
                       in_stack_0000009c,in_stack_000000a0);
          if (iVar4 == 1) {
            mali_sys_memcpy(puVar3,&stack0x00000020,0x40);
            FUN_4098ba90((int)param_1,0);
          }
          else {
            FUN_40969e90(puVar3,puVar3,(undefined4 *)&stack0x00000020);
          }
        }
      }
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_40993338(0x60);
}



/* 4098c488 FUN_4098c488 */

/* Boundary evidence: original MIPS .pdata 4098c488..4098c58b. Semantic name remains unreviewed. */

void FUN_4098c488(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  
  FUN_40993230();
  puVar2 = *(undefined4 **)(param_1[0x136] + 0x509c);
  FUN_4098c188(param_1,*(int *)(param_1[0x136] + 0x55d4));
  uVar1 = __fpmul(*puVar2,param_2);
  *puVar2 = uVar1;
  uVar1 = __fpmul(param_3,puVar2[4]);
  puVar2[4] = uVar1;
  uVar1 = __fpmul(param_4,puVar2[8]);
  puVar2[8] = uVar1;
  uVar1 = __fpmul(param_2,puVar2[1]);
  puVar2[1] = uVar1;
  uVar1 = __fpmul(param_3,puVar2[5]);
  puVar2[5] = uVar1;
  uVar1 = __fpmul(param_4,puVar2[9]);
  puVar2[9] = uVar1;
  uVar1 = __fpmul(param_2,puVar2[2]);
  puVar2[2] = uVar1;
  uVar1 = __fpmul(param_3,puVar2[6]);
  puVar2[6] = uVar1;
  uVar1 = __fpmul(param_4,puVar2[10]);
  puVar2[10] = uVar1;
  uVar1 = __fpmul(param_2,puVar2[3]);
  puVar2[3] = uVar1;
  uVar1 = __fpmul(param_3,puVar2[7]);
  puVar2[7] = uVar1;
  uVar1 = __fpmul(param_4,puVar2[0xb]);
  puVar2[0xb] = uVar1;
  FUN_4098ba90((int)param_1,0);
                    /* WARNING: Subroutine does not return */
  FUN_40993258(0x10);
}



/* 4098c58c FUN_4098c58c */

/* Boundary evidence: original MIPS .pdata 4098c58c..4098c753. Semantic name remains unreviewed. */

void FUN_4098c58c(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  
  puVar3 = *(undefined4 **)(param_1[0x136] + 0x509c);
  FUN_4098c188(param_1,*(int *)(param_1[0x136] + 0x55d4));
  uVar1 = __fpmul(puVar3[4],param_3);
  uVar2 = __fpmul(puVar3[8],param_4);
  uVar1 = __fpadd(uVar1,uVar2);
  uVar2 = __fpmul(*puVar3,param_2);
  uVar1 = __fpadd(uVar1,uVar2);
  uVar1 = __fpadd(uVar1,puVar3[0xc]);
  puVar3[0xc] = uVar1;
  uVar1 = __fpmul(puVar3[1],param_2);
  uVar2 = __fpmul(puVar3[5],param_3);
  uVar1 = __fpadd(uVar1,uVar2);
  uVar2 = __fpmul(puVar3[9],param_4);
  uVar1 = __fpadd(uVar1,uVar2);
  uVar1 = __fpadd(uVar1,puVar3[0xd]);
  puVar3[0xd] = uVar1;
  uVar1 = __fpmul(puVar3[2],param_2);
  uVar2 = __fpmul(puVar3[6],param_3);
  uVar1 = __fpadd(uVar1,uVar2);
  uVar2 = __fpmul(puVar3[10],param_4);
  uVar1 = __fpadd(uVar1,uVar2);
  uVar1 = __fpadd(uVar1,puVar3[0xe]);
  puVar3[0xe] = uVar1;
  uVar1 = __fpmul(puVar3[3],param_2);
  uVar2 = __fpmul(puVar3[7],param_3);
  uVar1 = __fpadd(uVar1,uVar2);
  uVar2 = __fpmul(puVar3[0xb],param_4);
  uVar1 = __fpadd(uVar1,uVar2);
  uVar1 = __fpadd(uVar1,puVar3[0xf]);
  puVar3[0xf] = uVar1;
  FUN_4098ba90((int)param_1,0);
  return;
}



/* 4098c754 FUN_4098c754 */

/* Boundary evidence: original MIPS .pdata 4098c754..4098cb57. Semantic name remains unreviewed. */

void FUN_4098c754(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  undefined4 *puVar12;
  undefined8 uVar13;
  undefined4 uStack00000018;
  undefined4 uStack0000001c;
  undefined4 uStack00000020;
  undefined4 uStack00000024;
  int iStack00000028;
  undefined4 uStack0000002c;
  undefined4 uStack00000030;
  undefined4 uStack00000034;
  undefined4 uStack00000038;
  undefined4 uStack0000003c;
  undefined4 *puStack00000040;
  undefined4 in_stack_00000080;
  
  FUN_40993300();
  iStack00000028 = *(int *)(param_1[0x136] + 0x509c);
  uStack00000018 = param_3;
  uStack0000001c = param_4;
  puStack00000040 = param_1;
  FUN_4098c188(param_1,*(int *)(param_1[0x136] + 0x55d4));
  uVar1 = __fpmul(param_2,0x3c8efa35);
  uStack00000020 = in_stack_00000080;
  uVar2 = FUN_4098bd38(param_3,param_4,in_stack_00000080,param_3,param_4,in_stack_00000080);
  uVar13 = __fptodp(uVar2);
  iVar3 = __ltd((int)uVar13,(int)((ulonglong)uVar13 >> 0x20),0xfff24190,0x3fefffff);
  if (iVar3 == 0) {
    uVar13 = __fptodp(uVar2);
    iVar3 = __gtd((int)uVar13,(int)((ulonglong)uVar13 >> 0x20),0x6df38,0x3ff00000);
    if (iVar3 == 0) goto LAB_4098c8b0;
  }
  uVar2 = mali_sys_sqrt(uVar2);
  uVar13 = __fptodp(uVar2);
  iVar3 = __ltd((int)uVar13,(int)((ulonglong)uVar13 >> 0x20),0xd9d7bdbb,0x3ddb7cdf);
  if (iVar3 != 0) {
    uVar2 = 0x2edbe6ff;
  }
  uVar2 = __fpdiv(0x3f800000,uVar2);
  param_3 = __fpmul(uVar2,param_3);
  uStack00000018 = param_3;
  param_4 = __fpmul(uVar2,param_4);
  uStack0000001c = param_4;
  in_stack_00000080 = __fpmul(uVar2,in_stack_00000080);
  uStack00000020 = in_stack_00000080;
LAB_4098c8b0:
  uVar2 = mali_sys_cos(uVar1);
  uStack00000024 = uVar2;
  uVar1 = mali_sys_sin(uVar1);
  uVar2 = __fpsub(0x3f800000,uVar2);
  uVar4 = __fpmul(uVar1,param_3);
  uVar5 = __fpmul(uVar1,param_4);
  uVar6 = __fpmul(uVar1,in_stack_00000080);
  uVar7 = __fpmul(uVar2,param_4);
  uVar8 = __fpmul(uVar2,in_stack_00000080);
  uVar9 = __fpmul(uVar7,param_3);
  uVar10 = __fpmul(uVar8,param_3);
  uVar11 = __fpmul(uVar8,param_4);
  uVar1 = __fpmul(uVar2,uStack00000018);
  uVar2 = __fpmul(uVar1,uStack00000018);
  uVar1 = uStack00000024;
  uStack00000024 = __fpadd(uVar2,uStack00000024);
  uStack00000018 = __fpadd(uVar9,uVar6);
  uStack0000002c = __fpsub(uVar10,uVar5);
  uStack00000034 = __fpsub(uVar9,uVar6);
  uVar2 = __fpmul(uVar7,uStack0000001c);
  uStack00000030 = __fpadd(uVar2,uVar1);
  uStack0000001c = __fpadd(uVar11,uVar4);
  uStack0000003c = __fpadd(uVar10,uVar5);
  uStack00000038 = __fpsub(uVar11,uVar4);
  uVar2 = __fpmul(uVar8,uStack00000020);
  uStack00000020 = __fpadd(uVar2,uVar1);
  uVar4 = uStack0000002c;
  uVar2 = uStack00000024;
  uVar1 = uStack00000018;
  puVar12 = (undefined4 *)(iStack00000028 + 0x10);
  iVar3 = 4;
  do {
    uVar7 = puVar12[4];
    uVar9 = puVar12[-4];
    uVar8 = *puVar12;
    uVar5 = __fpmul(uVar7,uVar4);
    uVar6 = __fpmul(uVar8,uVar1);
    uVar5 = __fpadd(uVar5,uVar6);
    uVar6 = __fpmul(uVar9,uVar2);
    uVar5 = __fpadd(uVar5,uVar6);
    puVar12[-4] = uVar5;
    uVar5 = __fpmul(uVar7,uStack0000001c);
    uVar6 = __fpmul(uVar8,uStack00000030);
    uVar5 = __fpadd(uVar5,uVar6);
    uVar6 = __fpmul(uVar9,uStack00000034);
    uVar5 = __fpadd(uVar5,uVar6);
    *puVar12 = uVar5;
    uVar5 = __fpmul(uVar7,uStack00000020);
    uVar6 = __fpmul(uVar8,uStack00000038);
    uVar5 = __fpadd(uVar5,uVar6);
    uVar6 = __fpmul(uVar9,uStack0000003c);
    uVar5 = __fpadd(uVar5,uVar6);
    iVar3 = iVar3 + -1;
    puVar12[4] = uVar5;
    puVar12 = puVar12 + 1;
  } while (iVar3 != 0);
  FUN_4098ba90((int)puStack00000040,0);
                    /* WARNING: Subroutine does not return */
  FUN_40993338(0x48);
}



/* 4098cb58 FUN_4098cb58 */

/* Boundary evidence: original MIPS .pdata 4098cb58..4098cc23. Semantic name remains unreviewed. */

void FUN_4098cb58(undefined4 *param_1,uint *param_2)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 local_60 [16];
  
  puVar2 = *(undefined4 **)(param_1[0x136] + 0x509c);
  iVar3 = **(int **)(param_1[0x136] + 0x50a0);
  puVar5 = local_60;
  if (param_2 != (uint *)0x0) {
    FUN_4098c188(param_1,*(int *)(param_1[0x136] + 0x55d4));
    iVar4 = 0x10;
    do {
      uVar1 = FUN_4098bfb8(*param_2);
      iVar4 = iVar4 + -1;
      *puVar5 = uVar1;
      puVar5 = puVar5 + 1;
      param_2 = param_2 + 1;
    } while (iVar4 != 0);
    if (iVar3 == 1) {
      mali_sys_memcpy(puVar2,local_60,0x40);
      FUN_4098ba90((int)param_1,0);
    }
    else {
      FUN_40969e90(puVar2,puVar2,local_60);
    }
  }
  return;
}



/* 4098cc24 FUN_4098cc24 */

/* Boundary evidence: original MIPS .pdata 4098cc24..4098cca3. Semantic name remains unreviewed. */

void FUN_4098cc24(undefined4 *param_1,uint *param_2)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  
  puVar3 = *(undefined4 **)(param_1[0x136] + 0x509c);
  if (param_2 != (uint *)0x0) {
    FUN_4098c188(param_1,*(int *)(param_1[0x136] + 0x55d4));
    iVar2 = 0x10;
    do {
      uVar1 = FUN_4098bfb8(*param_2);
      iVar2 = iVar2 + -1;
      *puVar3 = uVar1;
      puVar3 = puVar3 + 1;
      param_2 = param_2 + 1;
    } while (iVar2 != 0);
    FUN_4098ba90((int)param_1,0);
  }
  return;
}



/* 4098cca4 FUN_4098cca4 */

/* Boundary evidence: original MIPS .pdata 4098cca4..4098cd43. Semantic name remains unreviewed. */

void FUN_4098cca4(undefined4 *param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  int iVar2;
  
  puVar1 = *(undefined4 **)(param_1[0x136] + 0x509c);
  iVar2 = **(int **)(param_1[0x136] + 0x50a0);
  if (param_2 != (undefined4 *)0x0) {
    FUN_4098c188(param_1,*(int *)(param_1[0x136] + 0x55d4));
    if (iVar2 == 1) {
      mali_sys_memcpy(puVar1,param_2,0x40);
      FUN_4098ba90((int)param_1,0);
    }
    else {
      FUN_40969e90(puVar1,puVar1,param_2);
    }
  }
  return;
}



/* 4098cd44 FUN_4098cd44 */

/* Boundary evidence: original MIPS .pdata 4098cd44..4098cd93. Semantic name remains unreviewed. */

void FUN_4098cd44(undefined4 *param_1,int param_2)

{
  undefined4 uVar1;
  
  FUN_40993370();
  uVar1 = *(undefined4 *)(param_1[0x136] + 0x509c);
  if (param_2 != 0) {
    FUN_4098c188(param_1,*(int *)(param_1[0x136] + 0x55d4));
    mali_sys_memcpy(uVar1,param_2,0x40);
    FUN_4098ba90((int)param_1,0);
  }
                    /* WARNING: Subroutine does not return */
  FUN_40993390(0x10);
}



/* 4098cd94 FUN_4098cd94 */

/* Boundary evidence: original MIPS .pdata 4098cd94..4098ce1f. Semantic name remains unreviewed. */

void FUN_4098cd94(undefined4 *param_1)

{
  undefined4 *puVar1;
  
  puVar1 = *(undefined4 **)(param_1[0x136] + 0x509c);
  FUN_4098c188(param_1,*(int *)(param_1[0x136] + 0x55d4));
  *puVar1 = 0x3f800000;
  puVar1[5] = 0x3f800000;
  puVar1[10] = 0x3f800000;
  puVar1[0xf] = 0x3f800000;
  puVar1[1] = 0;
  puVar1[2] = 0;
  puVar1[3] = 0;
  puVar1[4] = 0;
  puVar1[6] = 0;
  puVar1[7] = 0;
  puVar1[8] = 0;
  puVar1[9] = 0;
  puVar1[0xb] = 0;
  puVar1[0xc] = 0;
  puVar1[0xd] = 0;
  puVar1[0xe] = 0;
  FUN_4098ba90((int)param_1,1);
  return;
}



/* 4098ce20 FUN_4098ce20 */

/* Boundary evidence: original MIPS .pdata 4098ce20..4098cf27. Semantic name remains unreviewed. */

undefined4 FUN_4098ce20(undefined4 *param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  uint *puVar5;
  int iVar6;
  
  iVar2 = param_1[0x136];
  iVar6 = iVar2 + 0x9c;
  FUN_4098c188(param_1,*(int *)(iVar2 + 0x55d4));
  iVar1 = *(int *)(iVar2 + 0x55d4);
  if (iVar1 == 0x1700) {
    puVar5 = (uint *)(iVar2 + 0x55ac);
    iVar1 = iVar2 + 0x50ac;
  }
  else if (iVar1 == 0x1701) {
    puVar5 = (uint *)(iVar2 + 0x55b0);
    iVar1 = iVar2 + 0x512c;
    iVar6 = iVar2 + 0x89c;
  }
  else {
    if (iVar1 != 0x1702) {
      if (iVar1 != 0x8840) {
        return 0;
      }
      return 0x504;
    }
    iVar4 = param_1[0xca];
    puVar5 = (uint *)((iVar4 + 0x1546) * 4 + iVar6);
    iVar1 = iVar4 * 0x80 + iVar6 + 0x5110;
    iVar6 = (iVar4 + 2) * 0x800 + iVar6;
  }
  if (puVar5 != (uint *)0x0) {
    if (*puVar5 < 2) {
      return 0x504;
    }
    uVar3 = *puVar5 - 1;
    *puVar5 = uVar3;
    *(uint *)(iVar2 + 0x509c) = uVar3 * 0x40 + iVar6 + -0x40;
    *(uint *)(iVar2 + 0x50a0) = *puVar5 * 4 + iVar1 + -4;
  }
  return 0;
}



/* 4098cf54 FUN_4098cf54 */

/* Boundary evidence: original MIPS .pdata 4098cf54..4098cfef. Semantic name remains unreviewed. */

void FUN_4098cf54(undefined4 *param_1,int param_2)

{
  int iVar1;
  
  FUN_40993370();
  if (param_2 == 0) {
    if (((param_1[0x134] != 1) || (iVar1 = FUN_40978ffc(param_1), iVar1 != 0)) ||
       (iVar1 = FUN_4096b244(param_1), iVar1 != 0)) goto LAB_4098cfe8;
    if (param_1[0x144] != 0) {
      FUN_409748f8(param_1[0x144]);
    }
    mali_frame_builder_write_unlock(param_1[0x13d]);
    param_1[0x134] = 0;
  }
  if (((param_2 == 4) || (param_2 == 5)) || (param_2 == 6)) {
    param_1[0x134] = 1;
  }
LAB_4098cfe8:
                    /* WARNING: Subroutine does not return */
  FUN_40993390(0x10);
}



/* 4098cff0 FUN_4098cff0 */

/* Boundary evidence: original MIPS .pdata 4098cff0..4098d15f. Semantic name remains unreviewed. */

int FUN_4098cff0(undefined4 *param_1,int param_2,undefined4 param_3,int *param_4,int param_5)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  int local_78 [8];
  int local_58;
  uint local_54;
  undefined4 local_50;
  undefined4 local_4c;
  uint local_48;
  uint local_44;
  undefined4 local_40 [8];
  
  local_54 = (uint)*(byte *)(param_1[0x136] + 0x5f10);
  local_58 = 1;
  if ((local_54 == 0) ||
     ((*(char *)(param_1[0x136] + 0x5f10) != '\0' &&
      ((*(uint *)(param_1[0x142] + 0x1c) & 0x10) == 0x10)))) {
    local_50 = 1;
  }
  else {
    local_50 = 0;
  }
  local_4c = 1;
  puVar3 = param_1 + 0xcc;
  iVar2 = 0;
  do {
    if (*(char *)(puVar3 + -1) == '\0') {
      *(undefined4 *)((int)local_78 + iVar2) = 0;
      *(undefined4 *)((int)local_40 + iVar2) = 0;
    }
    else {
      uVar1 = FUN_4096df58((int *)*puVar3);
      *(undefined4 *)((int)local_78 + iVar2) = uVar1;
      *(undefined4 *)((int)local_40 + iVar2) = uVar1;
    }
    iVar2 = iVar2 + 4;
    puVar3 = puVar3 + 5;
  } while (iVar2 < 0x20);
  local_48 = *(uint *)(param_1[0x142] + 0x1c) >> 3 & 1;
  local_44 = local_48;
  iVar2 = FUN_4098119c((char *)(param_1 + 5),param_4,param_5,&local_58);
  if (iVar2 == 0) {
    iVar2 = -3;
  }
  else {
    iVar2 = FUN_40966500((int)param_1,(undefined4 *)param_1[0x142],local_78,param_2);
    if (iVar2 == 0) {
      iVar2 = FUN_4096d724(param_1,param_3,*param_4,param_2);
    }
  }
  return iVar2;
}



/* 4098d160 FUN_4098d160 */

/* Boundary evidence: original MIPS .pdata 4098d160..4098d2d7. Semantic name remains unreviewed. */

int FUN_4098d160(undefined4 *param_1,uint param_2,int param_3,uint param_4)

{
  int iVar1;
  uint uVar2;
  int local_20 [2];
  
  iVar1 = FUN_4098cf54(param_1,param_2);
  if (iVar1 == 0) {
    iVar1 = FUN_40975028(param_2,param_4);
    if (iVar1 != 0) {
      return iVar1;
    }
    if (param_3 < 0) {
      return 0x501;
    }
    uVar2 = FUN_40974e18(param_2,param_4);
    if (uVar2 == 0) {
      return 0;
    }
    local_20[0] = param_3 + uVar2 + -1;
    iVar1 = FUN_4097525c((int)param_1,param_2);
    if ((iVar1 == 0) && (iVar1 = FUN_40978ffc(param_1), iVar1 == 0)) {
      iVar1 = FUN_4098cff0(param_1,param_2,param_3,local_20,0);
      if (iVar1 == 0) {
        iVar1 = FUN_40968d80(param_1,param_2,param_3,(local_20[0] - param_3) + 1);
      }
      if (param_1[0x144] != 0) {
        FUN_409748f8(param_1[0x144]);
      }
      mali_frame_builder_write_unlock(param_1[0x13d]);
    }
  }
  if (((iVar1 != -3) && (-3 < iVar1)) && (iVar1 < 0)) {
    return 0x505;
  }
  return 0;
}



/* 4098d2d8 FUN_4098d2d8 */

/* Boundary evidence: original MIPS .pdata 4098d2d8..4098d487. Semantic name remains unreviewed. */

int FUN_4098d2d8(undefined4 *param_1,uint param_2,uint param_3,uint param_4,undefined4 param_5,
                undefined4 param_6,int param_7)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = FUN_4098cf54(param_1,param_2);
  if (iVar1 == 0) {
    iVar1 = FUN_40975028(param_2,param_3);
    if (iVar1 != 0) {
      return iVar1;
    }
    if ((param_4 != 0x1401) && (param_4 != 0x1403)) {
      return 0x500;
    }
    uVar2 = FUN_40974e18(param_2,param_3);
    if (uVar2 == 0) {
      return 0;
    }
    iVar1 = FUN_409752bc((int)param_1,uVar2,param_4,param_2);
    if ((iVar1 == 0) && (iVar1 = FUN_40978ffc(param_1), iVar1 == 0)) {
      iVar1 = FUN_4098cff0(param_1,param_2,0,&param_7,1);
      if (iVar1 == 0) {
        iVar1 = FUN_40968c58(param_1,param_2,0,param_7);
      }
      if (param_1[0x144] != 0) {
        FUN_409748f8(param_1[0x144]);
      }
      mali_frame_builder_write_unlock(param_1[0x13d]);
    }
  }
  if (((iVar1 != -3) && (-3 < iVar1)) && (iVar1 < 0)) {
    return 0x505;
  }
  return 0;
}



/* 4098d488 FUN_4098d488 */

/* Boundary evidence: original MIPS .pdata 4098d488..4098d61b. Semantic name remains unreviewed. */

void FUN_4098d488(undefined4 *param_1,uint param_2,uint param_3,uint param_4)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  int iStack00000020;
  int iStack00000024;
  
  FUN_409933b0();
  iStack00000020 = 0;
  iStack00000024 = 0;
  iVar1 = FUN_4098cf54(param_1,param_2);
  if ((((iVar1 == 0) && (iVar1 = FUN_40975028(param_2,param_3), iVar1 == 0)) &&
      ((param_4 == 0x1401 || (param_4 == 0x1403)))) &&
     (((uVar2 = FUN_40974e18(param_2,param_3), uVar2 != 0 &&
       (iVar1 = FUN_409752bc((int)param_1,uVar2,param_4,param_2), iVar1 == 0)) &&
      (iVar3 = FUN_40978ffc(param_1), iVar1 = iStack00000024, iVar3 == 0)))) {
    iVar3 = FUN_4098cff0(param_1,param_2,iStack00000024,&stack0x00000020,1);
    if (iVar3 == 0) {
      FUN_40968c58(param_1,param_2,iVar1,iStack00000020);
    }
    if (param_1[0x144] != 0) {
      FUN_409748f8(param_1[0x144]);
    }
    mali_frame_builder_write_unlock(param_1[0x13d]);
  }
                    /* WARNING: Subroutine does not return */
  FUN_409933e0(0x28);
}



/* 4098d61c gles1_get_proc_address */

/* Boundary evidence: original MIPS .pdata 4098d61c..4098d63f. Semantic name remains unreviewed.
   gles1_get_proc_address */

void gles1_get_proc_address(int param_1)

{
                    /* 0x2d61c  5  _gles1_get_proc_address */
  FUN_40977bd4(param_1);
  return;
}



/* 4098d704 FUN_4098d704 */

uint FUN_4098d704(uint param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar2 = param_1 >> 10 & 0x1f;
  uVar3 = param_1 & 0x3ff | 0x400;
  uVar1 = 0xe - (param_1 >> 10 & 0xf);
  if ((((param_1 & 0xffff8000) == 0) && (uVar2 != 0)) && ((uVar2 != 0x1f || (param_1 != 0x400)))) {
    if (uVar2 < 0xf) {
      uVar2 = uVar3 << 5;
      if ((uVar1 & 1) != 0) {
        uVar2 = uVar3 << 4;
      }
      if ((uVar1 & 2) != 0) {
        uVar2 = uVar2 >> 2;
      }
      if ((uVar1 & 4) != 0) {
        uVar2 = uVar2 >> 4;
      }
      if ((uVar1 & 8) != 0) {
        uVar2 = uVar2 >> 8;
      }
      uVar1 = (uVar2 - (uVar2 >> 8)) + 0x80 >> 8;
      if (uVar1 < 0x100) {
        return uVar1;
      }
    }
    uVar1 = 0xff;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}



/* 4098d884 FUN_4098d884 */

/* Boundary evidence: original MIPS .pdata 4098d884..4098d99b. Semantic name remains unreviewed. */

undefined4 FUN_4098d884(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int *piVar4;
  int local_28;
  undefined1 auStack_24 [4];
  undefined1 auStack_20 [4];
  undefined1 auStack_1c [4];
  undefined1 auStack_18 [4];
  undefined1 auStack_14 [4];
  
  iVar3 = *(int *)(param_1 + 0x484);
  if (iVar3 == 0) {
    local_28 = *(int *)(param_1 + 0x4a8);
    goto LAB_4098d958;
  }
  if (iVar3 != -0x48) {
    if (*(int *)(iVar3 + 0x50) == 0x1702) {
      iVar1 = FUN_40979e34(*(int *)(iVar3 + 100));
      piVar4 = *(int **)((iVar1 * 0xd + *(int *)(iVar3 + 0x60)) * 4 +
                        *(int *)(*(int *)(iVar3 + 0x58) + 0x34));
      if (piVar4 != (int *)0x0) {
        iVar3 = *piVar4;
        goto LAB_4098d910;
      }
    }
    else if (*(int *)(iVar3 + 0x50) == 0x8d41) {
      iVar3 = *(int *)(*(int *)(iVar3 + 0x58) + 0x28);
LAB_4098d910:
      if (iVar3 != 0) {
        mali_pixel_format_get_bpc
                  (*(undefined4 *)(iVar3 + 0x14),auStack_14,auStack_18,auStack_1c,auStack_20,
                   auStack_24,&local_28);
        goto LAB_4098d958;
      }
    }
  }
  local_28 = 0;
LAB_4098d958:
  uVar2 = 1;
  if (((*(uint *)(*(int *)(param_1 + 0x504) + 0x40) & 0x10) == 0) || (local_28 < 1)) {
    uVar2 = 0;
  }
  return uVar2;
}



/* 4098d99c FUN_4098d99c */

/* Boundary evidence: original MIPS .pdata 4098d99c..4098dab3. Semantic name remains unreviewed. */

undefined4 FUN_4098d99c(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int *piVar4;
  int local_28;
  undefined1 auStack_24 [4];
  undefined1 auStack_20 [4];
  undefined1 auStack_1c [4];
  undefined1 auStack_18 [4];
  undefined1 auStack_14 [4];
  
  iVar3 = *(int *)(param_1 + 0x484);
  if (iVar3 == 0) {
    local_28 = *(int *)(param_1 + 0x4a4);
    goto LAB_4098da70;
  }
  if (iVar3 != -0x24) {
    if (*(int *)(iVar3 + 0x2c) == 0x1702) {
      iVar1 = FUN_40979e34(*(int *)(iVar3 + 0x40));
      piVar4 = *(int **)((iVar1 * 0xd + *(int *)(iVar3 + 0x3c)) * 4 +
                        *(int *)(*(int *)(iVar3 + 0x34) + 0x34));
      if (piVar4 != (int *)0x0) {
        iVar3 = *piVar4;
        goto LAB_4098da28;
      }
    }
    else if (*(int *)(iVar3 + 0x2c) == 0x8d41) {
      iVar3 = *(int *)(*(int *)(iVar3 + 0x34) + 0x28);
LAB_4098da28:
      if (iVar3 != 0) {
        mali_pixel_format_get_bpc
                  (*(undefined4 *)(iVar3 + 0x14),auStack_14,auStack_18,auStack_1c,auStack_20,
                   &local_28,auStack_24);
        goto LAB_4098da70;
      }
    }
  }
  local_28 = 0;
LAB_4098da70:
  uVar2 = 1;
  if (((*(uint *)(*(int *)(param_1 + 0x504) + 0x40) & 2) == 0) || (local_28 < 1)) {
    uVar2 = 0;
  }
  return uVar2;
}



/* 4098dab4 FUN_4098dab4 */

/* Boundary evidence: original MIPS .pdata 4098dab4..4098db1f. Semantic name remains unreviewed. */

void FUN_4098dab4(int param_1)

{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = *(int *)(param_1 + 0x504);
  uVar1 = mali_sys_floor(0);
  uVar2 = __fptoul(uVar1);
  *(uint *)(iVar4 + 0x10) = *(uint *)(iVar4 + 0x10) & 0xffff0000 ^ uVar2;
  uVar1 = mali_sys_ceil(0x477fff00);
  iVar3 = __fptoul(uVar1);
  *(uint *)(iVar4 + 0x10) = iVar3 << 0x10 ^ *(uint *)(iVar4 + 0x10) & 0xffff;
  return;
}



/* 4098db44 FUN_4098db44 */

void FUN_4098db44(int param_1,uint param_2,int param_3)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x504);
  *(char *)(iVar1 + 0x46) = (char)param_2;
  *(char *)(iVar1 + 0x47) = (char)param_3;
  if ((*(uint *)(iVar1 + 0x40) & 8) != 8) {
    if ((*(uint *)(iVar1 + 0x40) & 4) == 0) {
      param_3 = 2;
      param_2 = 2;
    }
    *(uint *)(iVar1 + 8) = (*(uint *)(iVar1 + 8) & 0xfffffff8 ^ param_2) & 0xffffffc7 ^ param_3 << 3
    ;
  }
  return;
}



/* 4098dbe8 FUN_4098dbe8 */

void FUN_4098dbe8(int param_1)

{
  bool bVar1;
  uint uVar2;
  int iVar3;
  
  iVar3 = *(int *)(param_1 + 0x504);
  uVar2 = 1;
  if ((*(int *)(param_1 + 0x484) != 0) || (bVar1 = true, *(int *)(param_1 + 0x4b0) < 1)) {
    bVar1 = false;
  }
  if (((*(uint *)(iVar3 + 0x40) & 0x20) == 0) || (!bVar1)) {
    uVar2 = 0;
  }
  *(uint *)(iVar3 + 0x20) =
       ((uVar2 ^ uVar2 << 2) << 3 ^ *(uint *)(iVar3 + 0x20) & 0xffffffd7) & 0xffffffbf ^ uVar2 << 6;
  return;
}



/* 4098dc98 FUN_4098dc98 */

/* Boundary evidence: original MIPS .pdata 4098dc98..4098dcf3. Semantic name remains unreviewed. */

void FUN_4098dc98(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = *(int *)(param_1 + 0x504);
  iVar2 = 0xff;
  *(undefined1 *)(iVar3 + 0x59) = 0xff;
  iVar1 = FUN_4098d884(param_1);
  if (iVar1 == 0) {
    iVar2 = 0;
  }
  *(uint *)(iVar3 + 0x1c) = iVar2 << 8 ^ *(uint *)(iVar3 + 0x1c) & 0xffff00ff;
  return;
}



/* 4098dcf4 FUN_4098dcf4 */

/* Boundary evidence: original MIPS .pdata 4098dcf4..4098dd4b. Semantic name remains unreviewed. */

void FUN_4098dcf4(int param_1)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  
  iVar3 = *(int *)(param_1 + 0x504);
  uVar2 = 0xff;
  *(undefined1 *)(iVar3 + 0x52) = 0xff;
  iVar1 = FUN_4098d884(param_1);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  *(uint *)(iVar3 + 0x1c) = *(uint *)(iVar3 + 0x1c) & 0xffffff00 ^ uVar2;
  return;
}



/* 4098dd4c FUN_4098dd4c */

/* Boundary evidence: original MIPS .pdata 4098dd4c..4098dd8f. Semantic name remains unreviewed. */

void FUN_4098dd4c(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x504);
  *(undefined1 *)(iVar1 + 0x5a) = 0;
  *(undefined1 *)(iVar1 + 0x5b) = 0;
  *(undefined1 *)(iVar1 + 0x5c) = 0;
  FUN_4098d884(param_1);
  *(uint *)(iVar1 + 0x18) = *(uint *)(iVar1 + 0x18) & 0xfffff007;
  return;
}



/* 4098dd90 FUN_4098dd90 */

/* Boundary evidence: original MIPS .pdata 4098dd90..4098ddd3. Semantic name remains unreviewed. */

void FUN_4098dd90(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x504);
  *(undefined1 *)(iVar1 + 0x53) = 0;
  *(undefined1 *)(iVar1 + 0x54) = 0;
  *(undefined1 *)(iVar1 + 0x55) = 0;
  FUN_4098d884(param_1);
  *(uint *)(iVar1 + 0x14) = *(uint *)(iVar1 + 0x14) & 0xfffff007;
  return;
}



/* 4098ddd4 FUN_4098ddd4 */

/* Boundary evidence: original MIPS .pdata 4098ddd4..4098de43. Semantic name remains unreviewed. */

void FUN_4098ddd4(int param_1)

{
  uint uVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0x504);
  *(undefined4 *)(iVar2 + 0x88) = 0;
  *(undefined1 *)(iVar2 + 0x56) = 7;
  *(undefined1 *)(iVar2 + 0x57) = 0;
  *(undefined1 *)(iVar2 + 0x58) = 0;
  FUN_4098d884(param_1);
  uVar1 = *(uint *)(iVar2 + 0x18) & 0xff00fff8 ^ 7;
  *(uint *)(iVar2 + 0x18) = uVar1;
  *(uint *)(iVar2 + 0x18) = uVar1 & 0xffffff ^ (uint)*(byte *)(iVar2 + 0x51) << 0x18;
  return;
}



/* 4098de44 FUN_4098de44 */

/* Boundary evidence: original MIPS .pdata 4098de44..4098deb3. Semantic name remains unreviewed. */

void FUN_4098de44(int param_1)

{
  uint uVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0x504);
  *(undefined4 *)(iVar2 + 0x84) = 0;
  *(undefined1 *)(iVar2 + 0x4f) = 7;
  *(undefined1 *)(iVar2 + 0x50) = 0;
  *(undefined1 *)(iVar2 + 0x51) = 0;
  FUN_4098d884(param_1);
  uVar1 = *(uint *)(iVar2 + 0x14) & 0xff00fff8 ^ 7;
  *(uint *)(iVar2 + 0x14) = uVar1;
  *(uint *)(iVar2 + 0x14) = uVar1 & 0xffffff ^ (uint)*(byte *)(iVar2 + 0x51) << 0x18;
  return;
}



/* 4098deb4 FUN_4098deb4 */

/* Boundary evidence: original MIPS .pdata 4098deb4..4098df0f. Semantic name remains unreviewed. */

void FUN_4098deb4(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = *(int *)(param_1 + 0x504);
  iVar2 = 1;
  *(undefined1 *)(iVar3 + 0x4d) = 1;
  iVar1 = FUN_4098d99c(param_1);
  if (iVar1 == 0) {
    iVar2 = 7;
  }
  *(uint *)(iVar3 + 0xc) = iVar2 << 1 ^ *(uint *)(iVar3 + 0xc) & 0xfffffff1;
  return;
}



/* 4098df10 FUN_4098df10 */

/* Boundary evidence: original MIPS .pdata 4098df10..4098df57. Semantic name remains unreviewed. */

void FUN_4098df10(int param_1)

{
  uint uVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0x504);
  *(undefined1 *)(iVar2 + 0x4e) = 1;
  uVar1 = FUN_4098d99c(param_1);
  *(uint *)(iVar2 + 0xc) = *(uint *)(iVar2 + 0xc) & 0xfffffffe ^ uVar1 & 1;
  return;
}



/* 4098df58 FUN_4098df58 */

/* Boundary evidence: original MIPS .pdata 4098df58..4098dff3. Semantic name remains unreviewed. */

void FUN_4098df58(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x504);
  *(undefined1 *)(iVar1 + 0x49) = 3;
  *(undefined1 *)(iVar1 + 0x4b) = 3;
  *(undefined1 *)(iVar1 + 0x48) = 0xb;
  *(undefined1 *)(iVar1 + 0x4a) = 0xb;
  if ((*(uint *)(iVar1 + 0x40) & 8) != 8) {
    FUN_4098db44(param_1,(uint)*(byte *)(iVar1 + 0x46),(uint)*(byte *)(iVar1 + 0x47));
    if (*(int *)(param_1 + 0x484) != 0) {
      FUN_40971460(*(int *)(param_1 + 0x484),0xd55);
    }
    *(uint *)(iVar1 + 8) = *(uint *)(iVar1 + 8) & 0xff00003f ^ 0x3b1ac0;
  }
  return;
}



/* 4098e014 FUN_4098e014 */

/* WARNING: Removing unreachable block (ram,0x4098e054) */
/* WARNING: Removing unreachable block (ram,0x4098e038) */

undefined4 FUN_4098e014(void)

{
  return 0;
}



/* 4098e068 FUN_4098e068 */

/* Boundary evidence: original MIPS .pdata 4098e068..4098e0df. Semantic name remains unreviewed. */

void FUN_4098e068(int param_1)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = FUN_4098e014();
  uVar1 = FUN_4098d704(uVar1);
  *(undefined4 *)(*(int *)(param_1 + 0x504) + 0x78) = 0;
  iVar2 = *(int *)(param_1 + 0x504);
  *(undefined1 *)(iVar2 + 0x44) = 7;
  *(char *)(iVar2 + 0x45) = (char)uVar1;
  *(uint *)(iVar2 + 0x20) = *(uint *)(iVar2 + 0x20) & 0xfffffff8 ^ 7;
  *(uint *)(iVar2 + 0x1c) = (uVar1 & 0xff) << 0x10 ^ *(uint *)(iVar2 + 0x1c) & 0xffff;
  return;
}



/* 4098e0e0 FUN_4098e0e0 */

/* Boundary evidence: original MIPS .pdata 4098e0e0..4098e333. Semantic name remains unreviewed. */

void FUN_4098e0e0(int param_1)

{
  uint uVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  undefined1 uStack00000010;
  
  FUN_40993230();
  iVar4 = *(int *)(param_1 + 0x504);
  mali_sys_memset(iVar4,0,0x8c);
  *(uint *)(*(int *)(param_1 + 0x504) + 0x38) =
       *(uint *)(*(int *)(param_1 + 0x504) + 0x38) & 0xffffdfff ^ 0x2000;
  *(uint *)(iVar4 + 0x40) = *(uint *)(iVar4 + 0x40) | 0x20;
  FUN_4098dbe8(param_1);
  iVar3 = *(int *)(param_1 + 0x504);
  *(undefined4 *)(iVar3 + 0x60) = 0x3f800000;
  *(undefined1 *)(iVar3 + 100) = 0;
  *(uint *)(iVar3 + 0x20) = *(uint *)(iVar3 + 0x20) & 0xffff0fff ^ 0xf000;
  FUN_4098deb4(param_1);
  iVar3 = *(int *)(param_1 + 0x504);
  *(undefined1 *)(iVar3 + 0x4e) = 1;
  uVar1 = FUN_4098d99c(param_1);
  *(uint *)(iVar3 + 0xc) = *(uint *)(iVar3 + 0xc) & 0xfffffffe ^ uVar1 & 1;
  FUN_4098dab4(param_1);
  *(uint *)(*(int *)(param_1 + 0x504) + 8) =
       *(uint *)(*(int *)(param_1 + 0x504) + 8) & 0xfffffff ^ 0xf0000000;
  FUN_4098db44(param_1,2,2);
  uStack00000010 = 3;
  FUN_4098df58(param_1);
  puVar2 = *(undefined4 **)(param_1 + 0x504);
  puVar2[0x1a] = 0;
  puVar2[0x1b] = 0;
  puVar2[0x1c] = 0;
  puVar2[0x1d] = 0;
  *puVar2 = 0;
  puVar2[1] = 0;
  FUN_4098de44(param_1);
  iVar3 = *(int *)(param_1 + 0x504);
  *(undefined1 *)(iVar3 + 0x53) = 0;
  *(undefined1 *)(iVar3 + 0x54) = 0;
  *(undefined1 *)(iVar3 + 0x55) = 0;
  FUN_4098d884(param_1);
  *(uint *)(iVar3 + 0x14) = *(uint *)(iVar3 + 0x14) & 0xfffff007;
  FUN_4098dcf4(param_1);
  FUN_4098ddd4(param_1);
  iVar3 = *(int *)(param_1 + 0x504);
  *(undefined1 *)(iVar3 + 0x5a) = 0;
  *(undefined1 *)(iVar3 + 0x5b) = 0;
  *(undefined1 *)(iVar3 + 0x5c) = 0;
  FUN_4098d884(param_1);
  *(uint *)(iVar3 + 0x18) = *(uint *)(iVar3 + 0x18) & 0xfffff007;
  FUN_4098dc98(param_1);
  uVar1 = FUN_4098e014();
  uVar1 = FUN_4098d704(uVar1);
  *(undefined4 *)(*(int *)(param_1 + 0x504) + 0x78) = 0;
  iVar3 = *(int *)(param_1 + 0x504);
  *(char *)(iVar3 + 0x45) = (char)uVar1;
  *(undefined1 *)(iVar3 + 0x44) = 7;
  *(uint *)(iVar3 + 0x20) = *(uint *)(iVar3 + 0x20) & 0xfffffff8 ^ 7;
  *(uint *)(iVar3 + 0x1c) = (uVar1 & 0xff) << 0x10 ^ *(uint *)(iVar3 + 0x1c) & 0xffff;
  *(uint *)(iVar4 + 8) = *(uint *)(iVar4 + 8) & 0xf3ffffff ^ 0xc000000;
                    /* WARNING: Subroutine does not return */
  *(uint *)(iVar4 + 0xc) = *(uint *)(iVar4 + 0xc) & 0xffffffcf ^ 0x30;
  FUN_40993258(0x18);
}



/* 4098e334 gles1_delete_context */

/* Boundary evidence: original MIPS .pdata 4098e334..4098e433. Semantic name remains unreviewed.
   gles1_delete_context */

void gles1_delete_context(undefined4 *param_1)

{
  int *piVar1;
  undefined4 *puVar2;
  int iVar3;
  
                    /* 0x2e334  4  _gles1_delete_context */
  FUN_40993370();
  if (param_1 != (undefined4 *)0x0) {
    FUN_409806d4(param_1);
    if (param_1[0x13a] != 0) {
      FUN_409834a4((int)(param_1 + 0xca));
      FUN_409792b0(*(int *)(param_1[0x13a] + 8),(int)(param_1 + 5));
      FUN_40977e40(param_1[0x13a],param_1[1]);
      param_1[0x13a] = 0;
      FUN_4097473c((int)(param_1 + 5));
    }
    if (param_1[0x136] != 0) {
      mali_sys_free();
    }
    if (param_1[0x141] != 0) {
      mali_sys_free();
    }
    piVar1 = param_1 + 0x137;
    iVar3 = 2;
    do {
      if (*piVar1 != 0) {
        FUN_4097b168(*piVar1);
        *piVar1 = 0;
      }
      iVar3 = iVar3 + -1;
      piVar1 = piVar1 + 1;
    } while (iVar3 != 0);
    if (param_1[0x142] != 0) {
      FUN_40966080(param_1[0x142]);
    }
    FUN_40969bdc((int)param_1);
    puVar2 = (undefined4 *)param_1[0x140];
    if (puVar2 != (undefined4 *)0x0) {
      FUN_4096d088(puVar2);
      mali_sys_free(puVar2);
    }
    param_1[0x140] = 0;
    mali_sys_free(param_1);
  }
                    /* WARNING: Subroutine does not return */
  FUN_40993390(0x10);
}



/* 4098e434 gles1_create_context */

/* Boundary evidence: original MIPS .pdata 4098e434..4098e633. Semantic name remains unreviewed.
   gles1_create_context */

undefined4 * gles1_create_context(undefined4 param_1,int param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  int iVar2;
  int *piVar3;
  undefined4 *puVar4;
  uint uVar5;
  
                    /* 0x2e434  3  _gles1_create_context */
  puVar1 = (undefined4 *)mali_sys_calloc(1,0x534);
  if (puVar1 == (undefined4 *)0x0) {
    return (undefined4 *)0x0;
  }
  puVar1[0x143] = param_3;
  FUN_40977f10((int)(puVar1 + 0x145));
  *puVar1 = param_1;
  iVar2 = mali_sys_malloc(0x8c);
  puVar1[0x141] = iVar2;
  if (iVar2 != 0) {
    FUN_4098e0e0((int)puVar1);
    iVar2 = 0;
    puVar4 = puVar1 + 0x137;
    do {
      piVar3 = FUN_4097abfc();
      if (piVar3 == (int *)0x0) goto LAB_4098e600;
      *piVar3 = iVar2;
      iVar2 = iVar2 + 1;
      *puVar4 = piVar3;
      puVar4 = puVar4 + 1;
    } while (iVar2 < 2);
    puVar1[1] = 1;
    puVar1[2] = &PTR_LAB_40962a44;
    iVar2 = mali_sys_calloc(1,0x6630);
    puVar1[0x136] = iVar2;
    if (iVar2 != 0) {
      puVar4 = FUN_409656e4(param_1);
      puVar1[0x142] = puVar4;
      if (puVar4 != (undefined4 *)0x0) {
        puVar4[7] = 0;
        FUN_40980ebc((int)puVar1);
        iVar2 = puVar1[0x142];
        uVar5 = *(uint *)(iVar2 + 0x20);
        *(uint *)(iVar2 + 0x20) = uVar5 & 0xbfffffff;
        *(uint *)(iVar2 + 0x20) = uVar5 & 0xbbffffff;
        uVar5 = uVar5 & 0xb81fffff ^ 0x3a00000;
        *(uint *)(iVar2 + 0x20) = uVar5;
        *(uint *)(iVar2 + 0x20) = uVar5 & 0xffe0ffff ^ 0x90000;
        if (param_2 == 0) {
          iVar2 = FUN_40977ea0(puVar1[1]);
          puVar1[0x13a] = iVar2;
          if (iVar2 == 0) goto LAB_4098e600;
        }
        else {
          iVar2 = *(int *)(param_2 + 0x4e8);
          if (puVar1[1] == 2) {
            mali_sys_atomic_inc(iVar2 + 0xc);
          }
          mali_sys_atomic_inc(iVar2);
          puVar1[0x13a] = *(undefined4 *)(param_2 + 0x4e8);
        }
        puVar1[0x13f] = 0;
        iVar2 = FUN_40969c28(puVar1);
        if (iVar2 == 0) {
          puVar4 = FUN_4096d23c();
          puVar1[0x140] = puVar4;
          if (puVar4 != (undefined4 *)0x0) {
            puVar1[0x13d] = 0;
            puVar1[0x13c] = 0;
            puVar1[0x13e] = 0;
            puVar1[0x13b] = 0;
            puVar1[0x144] = 0;
            return puVar1;
          }
        }
      }
    }
  }
LAB_4098e600:
  gles1_delete_context(puVar1);
  return (undefined4 *)0x0;
}



/* 4098e8f0 glPointSizePointerOES */

/* Boundary evidence: original MIPS .pdata 4098e8f0..4098e99b. Semantic name remains unreviewed. */

void glPointSizePointerOES(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  
                    /* 0x2e8f0  129  glPointSizePointerOES */
  if (DAT_40996364 != 0) {
    if (*(int *)(DAT_40996364 + 8) == 0) {
      iVar1 = *(int *)(DAT_40996364 + 0xc);
    }
    else {
      iVar1 = mali_sys_thread_key_get_data(4);
    }
    if ((iVar1 != 0) &&
       (iVar2 = (**(code **)(*(int *)(iVar1 + 8) + 0x298))(iVar1,param_1,param_2,param_3),
       iVar2 != 0)) {
      (**(code **)(*(int *)(iVar1 + 8) + 0x3b8))(iVar1,iVar2);
    }
  }
  return;
}



/* 4098e99c glWeightPointerOES */

/* Boundary evidence: original MIPS .pdata 4098e99c..4098ea57. Semantic name remains unreviewed. */

void glWeightPointerOES(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  
                    /* 0x2e99c  167  glWeightPointerOES */
  if (DAT_40996364 != 0) {
    if (*(int *)(DAT_40996364 + 8) == 0) {
      iVar1 = *(int *)(DAT_40996364 + 0xc);
    }
    else {
      iVar1 = mali_sys_thread_key_get_data(4);
    }
    if (iVar1 != 0) {
      iVar2 = (**(code **)(*(int *)(iVar1 + 8) + 0x294))(iVar1,param_1,param_2,param_3,param_4);
      if (iVar2 != 0) {
        (**(code **)(*(int *)(iVar1 + 8) + 0x3b8))(iVar1,iVar2);
      }
    }
  }
  return;
}



/* 4098ea58 glMatrixIndexPointerOES */

/* Boundary evidence: original MIPS .pdata 4098ea58..4098eb13. Semantic name remains unreviewed. */

void glMatrixIndexPointerOES
               (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  
                    /* 0x2ea58  111  glMatrixIndexPointerOES */
  if (DAT_40996364 != 0) {
    if (*(int *)(DAT_40996364 + 8) == 0) {
      iVar1 = *(int *)(DAT_40996364 + 0xc);
    }
    else {
      iVar1 = mali_sys_thread_key_get_data(4);
    }
    if (iVar1 != 0) {
      iVar2 = (**(code **)(*(int *)(iVar1 + 8) + 0x290))(iVar1,param_1,param_2,param_3,param_4);
      if (iVar2 != 0) {
        (**(code **)(*(int *)(iVar1 + 8) + 0x3b8))(iVar1,iVar2);
      }
    }
  }
  return;
}



/* 4098eb14 glVertexPointer */

/* Boundary evidence: original MIPS .pdata 4098eb14..4098ebcf. Semantic name remains unreviewed. */

void glVertexPointer(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  
                    /* 0x2eb14  165  glVertexPointer */
  if (DAT_40996364 != 0) {
    if (*(int *)(DAT_40996364 + 8) == 0) {
      iVar1 = *(int *)(DAT_40996364 + 0xc);
    }
    else {
      iVar1 = mali_sys_thread_key_get_data(4);
    }
    if (iVar1 != 0) {
      iVar2 = (**(code **)(*(int *)(iVar1 + 8) + 0x284))(iVar1,param_1,param_2,param_3,param_4);
      if (iVar2 != 0) {
        (**(code **)(*(int *)(iVar1 + 8) + 0x3b8))(iVar1,iVar2);
      }
    }
  }
  return;
}



/* 4098ebd0 glTranslatef */

/* Boundary evidence: original MIPS .pdata 4098ebd0..4098ec57. Semantic name remains unreviewed. */

void glTranslatef(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  
                    /* 0x2ebd0  163  glTranslatef */
  if (DAT_40996364 != 0) {
    if (*(int *)(DAT_40996364 + 8) == 0) {
      iVar1 = *(int *)(DAT_40996364 + 0xc);
    }
    else {
      iVar1 = mali_sys_thread_key_get_data(4);
    }
    if (iVar1 != 0) {
      (**(code **)(*(int *)(iVar1 + 8) + 0x27c))(iVar1,param_1,param_2,param_3);
    }
  }
  return;
}



/* 4098ec58 glTexEnvxv */

/* Boundary evidence: original MIPS .pdata 4098ec58..4098ed0b. Semantic name remains unreviewed. */

void glTexEnvxv(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  
                    /* 0x2ec58  154  glTexEnvxv */
  if (DAT_40996364 != 0) {
    if (*(int *)(DAT_40996364 + 8) == 0) {
      iVar1 = *(int *)(DAT_40996364 + 0xc);
    }
    else {
      iVar1 = mali_sys_thread_key_get_data(4);
    }
    if (iVar1 != 0) {
      iVar2 = (**(code **)(*(int *)(iVar1 + 8) + 0x270))(iVar1,param_1,param_2,param_3,1);
      if (iVar2 != 0) {
        (**(code **)(*(int *)(iVar1 + 8) + 0x3b8))(iVar1,iVar2);
      }
    }
  }
  return;
}



/* 4098ed0c glTexEnvx */

/* Boundary evidence: original MIPS .pdata 4098ed0c..4098edb7. Semantic name remains unreviewed. */

void glTexEnvx(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  undefined4 local_res8 [2];
  
                    /* 0x2ed0c  153  glTexEnvx */
  if (DAT_40996364 != 0) {
    local_res8[0] = param_3;
    if (*(int *)(DAT_40996364 + 8) == 0) {
      iVar1 = *(int *)(DAT_40996364 + 0xc);
    }
    else {
      iVar1 = mali_sys_thread_key_get_data(4);
    }
    if (iVar1 != 0) {
      iVar2 = (**(code **)(*(int *)(iVar1 + 8) + 0x26c))(iVar1,param_1,param_2,local_res8,1);
      if (iVar2 != 0) {
        (**(code **)(*(int *)(iVar1 + 8) + 0x3b8))(iVar1,iVar2);
      }
    }
  }
  return;
}



/* 4098edb8 glTexEnviv */

/* Boundary evidence: original MIPS .pdata 4098edb8..4098ee6b. Semantic name remains unreviewed. */

void glTexEnviv(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  
                    /* 0x2edb8  152  glTexEnviv */
  if (DAT_40996364 != 0) {
    if (*(int *)(DAT_40996364 + 8) == 0) {
      iVar1 = *(int *)(DAT_40996364 + 0xc);
    }
    else {
      iVar1 = mali_sys_thread_key_get_data(4);
    }
    if (iVar1 != 0) {
      iVar2 = (**(code **)(*(int *)(iVar1 + 8) + 0x268))(iVar1,param_1,param_2,param_3,3);
      if (iVar2 != 0) {
        (**(code **)(*(int *)(iVar1 + 8) + 0x3b8))(iVar1,iVar2);
      }
    }
  }
  return;
}



/* 4098ee6c glTexEnvi */

/* Boundary evidence: original MIPS .pdata 4098ee6c..4098ef17. Semantic name remains unreviewed. */

void glTexEnvi(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  undefined4 local_res8 [2];
  
                    /* 0x2ee6c  151  glTexEnvi */
  if (DAT_40996364 != 0) {
    local_res8[0] = param_3;
    if (*(int *)(DAT_40996364 + 8) == 0) {
      iVar1 = *(int *)(DAT_40996364 + 0xc);
    }
    else {
      iVar1 = mali_sys_thread_key_get_data(4);
    }
    if (iVar1 != 0) {
      iVar2 = (**(code **)(*(int *)(iVar1 + 8) + 0x264))(iVar1,param_1,param_2,local_res8,3);
      if (iVar2 != 0) {
        (**(code **)(*(int *)(iVar1 + 8) + 0x3b8))(iVar1,iVar2);
      }
    }
  }
  return;
}



/* 4098ef18 glTexEnvfv */

/* Boundary evidence: original MIPS .pdata 4098ef18..4098efc7. Semantic name remains unreviewed. */

void glTexEnvfv(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  
                    /* 0x2ef18  150  glTexEnvfv */
  if (DAT_40996364 != 0) {
    if (*(int *)(DAT_40996364 + 8) == 0) {
      iVar1 = *(int *)(DAT_40996364 + 0xc);
    }
    else {
      iVar1 = mali_sys_thread_key_get_data(4);
    }
    if (iVar1 != 0) {
      iVar2 = (**(code **)(*(int *)(iVar1 + 8) + 0x260))(iVar1,param_1,param_2,param_3,0);
      if (iVar2 != 0) {
        (**(code **)(*(int *)(iVar1 + 8) + 0x3b8))(iVar1,iVar2);
      }
    }
  }
  return;
}



/* 4098efc8 glTexEnvf */

/* Boundary evidence: original MIPS .pdata 4098efc8..4098f06f. Semantic name remains unreviewed. */

void glTexEnvf(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  undefined4 local_res8 [2];
  
                    /* 0x2efc8  149  glTexEnvf */
  if (DAT_40996364 != 0) {
    local_res8[0] = param_3;
    if (*(int *)(DAT_40996364 + 8) == 0) {
      iVar1 = *(int *)(DAT_40996364 + 0xc);
    }
    else {
      iVar1 = mali_sys_thread_key_get_data(4);
    }
    if (iVar1 != 0) {
      iVar2 = (**(code **)(*(int *)(iVar1 + 8) + 0x25c))(iVar1,param_1,param_2,local_res8,0);
      if (iVar2 != 0) {
        (**(code **)(*(int *)(iVar1 + 8) + 0x3b8))(iVar1,iVar2);
      }
    }
  }
  return;
}



/* 4098f070 glTexCoordPointer */

/* Boundary evidence: original MIPS .pdata 4098f070..4098f12b. Semantic name remains unreviewed. */

void glTexCoordPointer(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  
                    /* 0x2f070  148  glTexCoordPointer */
  if (DAT_40996364 != 0) {
    if (*(int *)(DAT_40996364 + 8) == 0) {
      iVar1 = *(int *)(DAT_40996364 + 0xc);
    }
    else {
      iVar1 = mali_sys_thread_key_get_data(4);
    }
    if (iVar1 != 0) {
      iVar2 = (**(code **)(*(int *)(iVar1 + 8) + 600))(iVar1,param_1,param_2,param_3,param_4);
      if (iVar2 != 0) {
        (**(code **)(*(int *)(iVar1 + 8) + 0x3b8))(iVar1,iVar2);
      }
    }
  }
  return;
}



/* 4098f12c glScalef */

/* Boundary evidence: original MIPS .pdata 4098f12c..4098f1b3. Semantic name remains unreviewed. */

void glScalef(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  
                    /* 0x2f12c  141  glScalef */
  if (DAT_40996364 != 0) {
    if (*(int *)(DAT_40996364 + 8) == 0) {
      iVar1 = *(int *)(DAT_40996364 + 0xc);
    }
    else {
      iVar1 = mali_sys_thread_key_get_data(4);
    }
    if (iVar1 != 0) {
      (**(code **)(*(int *)(iVar1 + 8) + 0x24c))(iVar1,param_1,param_2,param_3);
    }
  }
  return;
}



/* 4098f1b4 glRotatef */

/* Boundary evidence: original MIPS .pdata 4098f1b4..4098f24b. Semantic name remains unreviewed. */

void glRotatef(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  
                    /* 0x2f1b4  137  glRotatef */
  if (DAT_40996364 != 0) {
    if (*(int *)(DAT_40996364 + 8) == 0) {
      iVar1 = *(int *)(DAT_40996364 + 0xc);
    }
    else {
      iVar1 = mali_sys_thread_key_get_data(4);
    }
    if (iVar1 != 0) {
      (**(code **)(*(int *)(iVar1 + 8) + 0x240))(iVar1,param_1,param_2,param_3,param_4);
    }
  }
  return;
}



/* 4098f24c glPushMatrix */

/* Boundary evidence: original MIPS .pdata 4098f24c..4098f2cb. Semantic name remains unreviewed. */

void glPushMatrix(void)

{
  int iVar1;
  int iVar2;
  
                    /* 0x2f24c  134  glPushMatrix */
  if (DAT_40996364 != 0) {
    if (*(int *)(DAT_40996364 + 8) == 0) {
      iVar1 = *(int *)(DAT_40996364 + 0xc);
    }
    else {
      iVar1 = mali_sys_thread_key_get_data(4);
    }
    if ((iVar1 != 0) && (iVar2 = (**(code **)(*(int *)(iVar1 + 8) + 0x23c))(iVar1), iVar2 != 0)) {
      (**(code **)(*(int *)(iVar1 + 8) + 0x3b8))(iVar1,iVar2);
    }
  }
  return;
}



/* 4098f2cc glPopMatrix */

/* Boundary evidence: original MIPS .pdata 4098f2cc..4098f34b. Semantic name remains unreviewed. */

void glPopMatrix(void)

{
  int iVar1;
  int iVar2;
  
                    /* 0x2f2cc  133  glPopMatrix */
  if (DAT_40996364 != 0) {
    if (*(int *)(DAT_40996364 + 8) == 0) {
      iVar1 = *(int *)(DAT_40996364 + 0xc);
    }
    else {
      iVar1 = mali_sys_thread_key_get_data(4);
    }
    if ((iVar1 != 0) && (iVar2 = (**(code **)(*(int *)(iVar1 + 8) + 0x238))(iVar1), iVar2 != 0)) {
      (**(code **)(*(int *)(iVar1 + 8) + 0x3b8))(iVar1,iVar2);
    }
  }
  return;
}



/* 4098f34c glOrthof */

/* Boundary evidence: original MIPS .pdata 4098f34c..4098f417. Semantic name remains unreviewed. */

void glOrthof(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
             undefined4 param_5,undefined4 param_6)

{
  int iVar1;
  int iVar2;
  
                    /* 0x2f34c  121  glOrthof */
  if (DAT_40996364 != 0) {
    if (*(int *)(DAT_40996364 + 8) == 0) {
      iVar1 = *(int *)(DAT_40996364 + 0xc);
    }
    else {
      iVar1 = mali_sys_thread_key_get_data(4);
    }
    if (iVar1 != 0) {
      iVar2 = (**(code **)(*(int *)(iVar1 + 8) + 0x214))
                        (iVar1,param_1,param_2,param_3,param_4,param_5,param_6);
      if (iVar2 != 0) {
        (**(code **)(*(int *)(iVar1 + 8) + 0x3b8))(iVar1,iVar2);
      }
    }
  }
  return;
}



/* 4098f418 glNormalPointer */

/* Boundary evidence: original MIPS .pdata 4098f418..4098f4c3. Semantic name remains unreviewed. */

void glNormalPointer(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  
                    /* 0x2f418  120  glNormalPointer */
  if (DAT_40996364 != 0) {
    if (*(int *)(DAT_40996364 + 8) == 0) {
      iVar1 = *(int *)(DAT_40996364 + 0xc);
    }
    else {
      iVar1 = mali_sys_thread_key_get_data(4);
    }
    if ((iVar1 != 0) &&
       (iVar2 = (**(code **)(*(int *)(iVar1 + 8) + 0x210))(iVar1,param_1,param_2,param_3),
       iVar2 != 0)) {
      (**(code **)(*(int *)(iVar1 + 8) + 0x3b8))(iVar1,iVar2);
    }
  }
  return;
}



/* 4098f4c4 glMultMatrixx */

/* Boundary evidence: original MIPS .pdata 4098f4c4..4098f52b. Semantic name remains unreviewed. */

void glMultMatrixx(undefined4 param_1)

{
  int iVar1;
  
                    /* 0x2f4c4  114  glMultMatrixx */
  if (DAT_40996364 != 0) {
    if (*(int *)(DAT_40996364 + 8) == 0) {
      iVar1 = *(int *)(DAT_40996364 + 0xc);
    }
    else {
      iVar1 = mali_sys_thread_key_get_data(4);
    }
    if (iVar1 != 0) {
      (**(code **)(*(int *)(iVar1 + 8) + 0x204))(iVar1,param_1);
    }
  }
  return;
}



/* 4098f52c glMultMatrixf */

/* Boundary evidence: original MIPS .pdata 4098f52c..4098f593. Semantic name remains unreviewed. */

void glMultMatrixf(undefined4 param_1)

{
  int iVar1;
  
                    /* 0x2f52c  113  glMultMatrixf */
  if (DAT_40996364 != 0) {
    if (*(int *)(DAT_40996364 + 8) == 0) {
      iVar1 = *(int *)(DAT_40996364 + 0xc);
    }
    else {
      iVar1 = mali_sys_thread_key_get_data(4);
    }
    if (iVar1 != 0) {
      (**(code **)(*(int *)(iVar1 + 8) + 0x200))(iVar1,param_1);
    }
  }
  return;
}



/* 4098f594 glMatrixMode */

/* Boundary evidence: original MIPS .pdata 4098f594..4098f61f. Semantic name remains unreviewed. */

void glMatrixMode(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  
                    /* 0x2f594  112  glMatrixMode */
  if (DAT_40996364 != 0) {
    if (*(int *)(DAT_40996364 + 8) == 0) {
      iVar1 = *(int *)(DAT_40996364 + 0xc);
    }
    else {
      iVar1 = mali_sys_thread_key_get_data(4);
    }
    if ((iVar1 != 0) &&
       (iVar2 = (**(code **)(*(int *)(iVar1 + 8) + 0x1f0))(iVar1 + 0xc,param_1), iVar2 != 0)) {
      (**(code **)(*(int *)(iVar1 + 8) + 0x3b8))(iVar1,iVar2);
    }
  }
  return;
}



/* 4098f620 glLoadMatrixx */

/* Boundary evidence: original MIPS .pdata 4098f620..4098f687. Semantic name remains unreviewed. */

void glLoadMatrixx(undefined4 param_1)

{
  int iVar1;
  
                    /* 0x2f620  104  glLoadMatrixx */
  if (DAT_40996364 != 0) {
    if (*(int *)(DAT_40996364 + 8) == 0) {
      iVar1 = *(int *)(DAT_40996364 + 0xc);
    }
    else {
      iVar1 = mali_sys_thread_key_get_data(4);
    }
    if (iVar1 != 0) {
      (**(code **)(*(int *)(iVar1 + 8) + 0x1d8))(iVar1,param_1);
    }
  }
  return;
}



/* 4098f688 glLoadMatrixf */

/* Boundary evidence: original MIPS .pdata 4098f688..4098f6ef. Semantic name remains unreviewed. */

void glLoadMatrixf(undefined4 param_1)

{
  int iVar1;
  
                    /* 0x2f688  103  glLoadMatrixf */
  if (DAT_40996364 != 0) {
    if (*(int *)(DAT_40996364 + 8) == 0) {
      iVar1 = *(int *)(DAT_40996364 + 0xc);
    }
    else {
      iVar1 = mali_sys_thread_key_get_data(4);
    }
    if (iVar1 != 0) {
      (**(code **)(*(int *)(iVar1 + 8) + 0x1d4))(iVar1,param_1);
    }
  }
  return;
}



/* 4098f6f0 glLoadIdentity */

/* Boundary evidence: original MIPS .pdata 4098f6f0..4098f74b. Semantic name remains unreviewed. */

void glLoadIdentity(void)

{
  int iVar1;
  
                    /* 0x2f6f0  102  glLoadIdentity */
  if (DAT_40996364 != 0) {
    if (*(int *)(DAT_40996364 + 8) == 0) {
      iVar1 = *(int *)(DAT_40996364 + 0xc);
    }
    else {
      iVar1 = mali_sys_thread_key_get_data(4);
    }
    if (iVar1 != 0) {
      (**(code **)(*(int *)(iVar1 + 8) + 0x1d0))(iVar1);
    }
  }
  return;
}



/* 4098f74c glFrustumf */

/* Boundary evidence: original MIPS .pdata 4098f74c..4098f817. Semantic name remains unreviewed. */

void glFrustumf(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
               undefined4 param_5,undefined4 param_6)

{
  int iVar1;
  int iVar2;
  
                    /* 0x2f74c  64  glFrustumf */
  if (DAT_40996364 != 0) {
    if (*(int *)(DAT_40996364 + 8) == 0) {
      iVar1 = *(int *)(DAT_40996364 + 0xc);
    }
    else {
      iVar1 = mali_sys_thread_key_get_data(4);
    }
    if (iVar1 != 0) {
      iVar2 = (**(code **)(*(int *)(iVar1 + 8) + 0x174))
                        (iVar1,param_1,param_2,param_3,param_4,param_5,param_6);
      if (iVar2 != 0) {
        (**(code **)(*(int *)(iVar1 + 8) + 0x3b8))(iVar1,iVar2);
      }
    }
  }
  return;
}



/* 4098f818 glEnableClientState */

/* Boundary evidence: original MIPS .pdata 4098f818..4098f8a7. Semantic name remains unreviewed. */

void glEnableClientState(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  
                    /* 0x2f818  56  glEnableClientState */
  if (DAT_40996364 != 0) {
    if (*(int *)(DAT_40996364 + 8) == 0) {
      iVar1 = *(int *)(DAT_40996364 + 0xc);
    }
    else {
      iVar1 = mali_sys_thread_key_get_data(4);
    }
    if ((iVar1 != 0) &&
       (iVar2 = (**(code **)(*(int *)(iVar1 + 8) + 0x160))(iVar1,param_1,1), iVar2 != 0)) {
      (**(code **)(*(int *)(iVar1 + 8) + 0x3b8))(iVar1,iVar2);
    }
  }
  return;
}



/* 4098f8a8 glDisableClientState */

/* Boundary evidence: original MIPS .pdata 4098f8a8..4098f937. Semantic name remains unreviewed. */

void glDisableClientState(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  
                    /* 0x2f8a8  50  glDisableClientState */
  if (DAT_40996364 != 0) {
    if (*(int *)(DAT_40996364 + 8) == 0) {
      iVar1 = *(int *)(DAT_40996364 + 0xc);
    }
    else {
      iVar1 = mali_sys_thread_key_get_data(4);
    }
    if ((iVar1 != 0) &&
       (iVar2 = (**(code **)(*(int *)(iVar1 + 8) + 0x15c))(iVar1,param_1,0), iVar2 != 0)) {
      (**(code **)(*(int *)(iVar1 + 8) + 0x3b8))(iVar1,iVar2);
    }
  }
  return;
}



/* 4098f938 glColorPointer */

/* Boundary evidence: original MIPS .pdata 4098f938..4098f9f3. Semantic name remains unreviewed. */

void glColorPointer(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  
                    /* 0x2f938  36  glColorPointer */
  if (DAT_40996364 != 0) {
    if (*(int *)(DAT_40996364 + 8) == 0) {
      iVar1 = *(int *)(DAT_40996364 + 0xc);
    }
    else {
      iVar1 = mali_sys_thread_key_get_data(4);
    }
    if (iVar1 != 0) {
      iVar2 = (**(code **)(*(int *)(iVar1 + 8) + 0x154))(iVar1,param_1,param_2,param_3,param_4);
      if (iVar2 != 0) {
        (**(code **)(*(int *)(iVar1 + 8) + 0x3b8))(iVar1,iVar2);
      }
    }
  }
  return;
}



/* 4098f9f4 glColor4f */

/* Boundary evidence: original MIPS .pdata 4098f9f4..4098faaf. Semantic name remains unreviewed. */

void glColor4f(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  
                    /* 0x2f9f4  32  glColor4f */
  if (DAT_40996364 != 0) {
    if (*(int *)(DAT_40996364 + 8) == 0) {
      iVar1 = *(int *)(DAT_40996364 + 0xc);
    }
    else {
      iVar1 = mali_sys_thread_key_get_data(4);
    }
    if (iVar1 != 0) {
      iVar2 = (**(code **)(*(int *)(iVar1 + 8) + 0x148))(iVar1,param_1,param_2,param_3,param_4);
      if (iVar2 != 0) {
        (**(code **)(*(int *)(iVar1 + 8) + 0x3b8))(iVar1,iVar2);
      }
    }
  }
  return;
}



/* 4098fab0 FUN_4098fab0 */

/* Boundary evidence: original MIPS .pdata 4098fab0..4098facb. Semantic name remains unreviewed. */

void FUN_4098fab0(int param_1)

{
  mali_sys_mutex_unlock(*(undefined4 *)(param_1 + 0x1c));
  return;
}



/* 4098facc FUN_4098facc */

/* Boundary evidence: original MIPS .pdata 4098facc..4098fae7. Semantic name remains unreviewed. */

void FUN_4098facc(int param_1)

{
  mali_sys_mutex_lock(*(undefined4 *)(param_1 + 0x1c));
  return;
}



/* 4098fb34 glClientActiveTexture */

/* Boundary evidence: original MIPS .pdata 4098fb34..4098fbdb. Semantic name remains unreviewed. */

void glClientActiveTexture(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  
                    /* 0x2fb34  29  glClientActiveTexture */
  if (DAT_40996364 != 0) {
    if (*(int *)(DAT_40996364 + 8) == 0) {
      iVar1 = *(int *)(DAT_40996364 + 0xc);
    }
    else {
      iVar1 = mali_sys_thread_key_get_data(4);
    }
    if (iVar1 != 0) {
      mali_sys_mutex_lock(*(undefined4 *)(*(int *)(iVar1 + 0x4e8) + 0x1c));
      iVar2 = (**(code **)(*(int *)(iVar1 + 8) + 0x13c))(iVar1 + 0x14,param_1);
      mali_sys_mutex_unlock(*(undefined4 *)(*(int *)(iVar1 + 0x4e8) + 0x1c));
      if (iVar2 != 0) {
        (**(code **)(*(int *)(iVar1 + 8) + 0x3b8))(iVar1,iVar2);
      }
    }
  }
  return;
}



/* 4098fbdc FUN_4098fbdc */

uint FUN_4098fbdc(uint param_1)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  
  uVar3 = 0;
  if (param_1 == 0) {
    return 0;
  }
  if ((int)param_1 < 0) {
    param_1 = -param_1;
    uVar3 = 0x80000000;
  }
  iVar2 = 0;
  if ((param_1 & 0xffff0000) == 0) {
    iVar2 = 0x10;
    uVar1 = param_1;
  }
  else {
    uVar1 = param_1 >> 0x10;
  }
  if ((uVar1 & 0xff00) == 0) {
    iVar2 = iVar2 + 8;
  }
  else {
    uVar1 = uVar1 >> 8;
  }
  uVar5 = (uint)(byte)(&DAT_4096203c)[uVar1] + iVar2;
  uVar4 = uVar5 - 8;
  uVar1 = ~(0x80000000U >> (uVar5 & 0x1f)) & param_1;
  if ((int)uVar4 < 0) {
    uVar1 = (int)uVar1 >> (-uVar4 & 0x1f);
  }
  else {
    uVar1 = uVar1 << (uVar4 & 0x1f);
  }
  return (0x8e - uVar5) * 0x800000 | uVar1 | uVar3;
}



/* 4098fc88 glTranslatex */

/* Boundary evidence: original MIPS .pdata 4098fc88..4098fd47. Semantic name remains unreviewed. */

void glTranslatex(uint param_1,uint param_2,uint param_3)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  
                    /* 0x2fc88  164  glTranslatex */
  if (DAT_40996364 != 0) {
    if (*(int *)(DAT_40996364 + 8) == 0) {
      iVar1 = *(int *)(DAT_40996364 + 0xc);
    }
    else {
      iVar1 = mali_sys_thread_key_get_data(4);
    }
    if (iVar1 != 0) {
      iVar5 = *(int *)(iVar1 + 8);
      uVar2 = FUN_4098fbdc(param_3);
      uVar3 = FUN_4098fbdc(param_2);
      uVar4 = FUN_4098fbdc(param_1);
      (**(code **)(iVar5 + 0x280))(iVar1,uVar4,uVar3,uVar2);
    }
  }
  return;
}



/* 4098fd48 glScalex */

/* Boundary evidence: original MIPS .pdata 4098fd48..4098fe07. Semantic name remains unreviewed. */

void glScalex(uint param_1,uint param_2,uint param_3)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  
                    /* 0x2fd48  142  glScalex */
  if (DAT_40996364 != 0) {
    if (*(int *)(DAT_40996364 + 8) == 0) {
      iVar1 = *(int *)(DAT_40996364 + 0xc);
    }
    else {
      iVar1 = mali_sys_thread_key_get_data(4);
    }
    if (iVar1 != 0) {
      iVar5 = *(int *)(iVar1 + 8);
      uVar2 = FUN_4098fbdc(param_3);
      uVar3 = FUN_4098fbdc(param_2);
      uVar4 = FUN_4098fbdc(param_1);
      (**(code **)(iVar5 + 0x250))(iVar1,uVar4,uVar3,uVar2);
    }
  }
  return;
}



/* 4098fe08 glRotatex */

/* Boundary evidence: original MIPS .pdata 4098fe08..4098fee3. Semantic name remains unreviewed. */

void glRotatex(uint param_1,uint param_2,uint param_3,uint param_4)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  
                    /* 0x2fe08  138  glRotatex */
  if (DAT_40996364 != 0) {
    if (*(int *)(DAT_40996364 + 8) == 0) {
      iVar1 = *(int *)(DAT_40996364 + 0xc);
    }
    else {
      iVar1 = mali_sys_thread_key_get_data(4);
    }
    if (iVar1 != 0) {
      iVar6 = *(int *)(iVar1 + 8);
      uVar2 = FUN_4098fbdc(param_4);
      uVar3 = FUN_4098fbdc(param_3);
      uVar4 = FUN_4098fbdc(param_2);
      uVar5 = FUN_4098fbdc(param_1);
      (**(code **)(iVar6 + 0x244))(iVar1,uVar5,uVar4,uVar3,uVar2);
    }
  }
  return;
}



/* 4098fee4 glOrthox */

/* Boundary evidence: original MIPS .pdata 4098fee4..4099000b. Semantic name remains unreviewed. */

void glOrthox(uint param_1,uint param_2,uint param_3,uint param_4,uint param_5,uint param_6)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  
                    /* 0x2fee4  122  glOrthox */
  if (DAT_40996364 != 0) {
    if (*(int *)(DAT_40996364 + 8) == 0) {
      iVar1 = *(int *)(DAT_40996364 + 0xc);
    }
    else {
      iVar1 = mali_sys_thread_key_get_data(4);
    }
    if (iVar1 != 0) {
      iVar8 = *(int *)(iVar1 + 8);
      uVar2 = FUN_4098fbdc(param_6);
      uVar3 = FUN_4098fbdc(param_5);
      uVar4 = FUN_4098fbdc(param_4);
      uVar5 = FUN_4098fbdc(param_3);
      uVar6 = FUN_4098fbdc(param_2);
      uVar7 = FUN_4098fbdc(param_1);
      iVar8 = (**(code **)(iVar8 + 0x218))(iVar1,uVar7,uVar6,uVar5,uVar4,uVar3,uVar2);
      if (iVar8 != 0) {
        (**(code **)(*(int *)(iVar1 + 8) + 0x3b8))(iVar1,iVar8);
      }
    }
  }
  return;
}



/* 4099000c glLineWidthx */

/* Boundary evidence: original MIPS .pdata 4099000c..409900a7. Semantic name remains unreviewed. */

void glLineWidthx(uint param_1)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  
                    /* 0x3000c  101  glLineWidthx */
  if (DAT_40996364 != 0) {
    if (*(int *)(DAT_40996364 + 8) == 0) {
      iVar1 = *(int *)(DAT_40996364 + 0xc);
    }
    else {
      iVar1 = mali_sys_thread_key_get_data(4);
    }
    if (iVar1 != 0) {
      iVar3 = *(int *)(iVar1 + 8);
      uVar2 = FUN_4098fbdc(param_1);
      iVar3 = (**(code **)(iVar3 + 0x1cc))(iVar1,uVar2);
      if (iVar3 != 0) {
        (**(code **)(*(int *)(iVar1 + 8) + 0x3b8))(iVar1,iVar3);
      }
    }
  }
  return;
}



/* 409900a8 glFrustumx */

/* Boundary evidence: original MIPS .pdata 409900a8..409901cf. Semantic name remains unreviewed. */

void glFrustumx(uint param_1,uint param_2,uint param_3,uint param_4,uint param_5,uint param_6)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  
                    /* 0x300a8  65  glFrustumx */
  if (DAT_40996364 != 0) {
    if (*(int *)(DAT_40996364 + 8) == 0) {
      iVar1 = *(int *)(DAT_40996364 + 0xc);
    }
    else {
      iVar1 = mali_sys_thread_key_get_data(4);
    }
    if (iVar1 != 0) {
      iVar8 = *(int *)(iVar1 + 8);
      uVar2 = FUN_4098fbdc(param_6);
      uVar3 = FUN_4098fbdc(param_5);
      uVar4 = FUN_4098fbdc(param_4);
      uVar5 = FUN_4098fbdc(param_3);
      uVar6 = FUN_4098fbdc(param_2);
      uVar7 = FUN_4098fbdc(param_1);
      iVar8 = (**(code **)(iVar8 + 0x178))(iVar1,uVar7,uVar6,uVar5,uVar4,uVar3,uVar2);
      if (iVar8 != 0) {
        (**(code **)(*(int *)(iVar1 + 8) + 0x3b8))(iVar1,iVar8);
      }
    }
  }
  return;
}



/* 409901d0 glColor4x */

/* Boundary evidence: original MIPS .pdata 409901d0..409902c7. Semantic name remains unreviewed. */

void glColor4x(uint param_1,uint param_2,uint param_3,uint param_4)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  
                    /* 0x301d0  34  glColor4x */
  if (DAT_40996364 != 0) {
    if (*(int *)(DAT_40996364 + 8) == 0) {
      iVar1 = *(int *)(DAT_40996364 + 0xc);
    }
    else {
      iVar1 = mali_sys_thread_key_get_data(4);
    }
    if (iVar1 != 0) {
      iVar6 = *(int *)(iVar1 + 8);
      uVar2 = FUN_4098fbdc(param_4);
      uVar3 = FUN_4098fbdc(param_3);
      uVar4 = FUN_4098fbdc(param_2);
      uVar5 = FUN_4098fbdc(param_1);
      iVar6 = (**(code **)(iVar6 + 0x150))(iVar1,uVar5,uVar4,uVar3,uVar2);
      if (iVar6 != 0) {
        (**(code **)(*(int *)(iVar1 + 8) + 0x3b8))(iVar1,iVar6);
      }
    }
  }
  return;
}



/* 409902c8 glColor4ub */

/* Boundary evidence: original MIPS .pdata 409902c8..409903df. Semantic name remains unreviewed. */

void glColor4ub(int param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  
                    /* 0x302c8  33  glColor4ub */
  if (DAT_40996364 != 0) {
    if (*(int *)(DAT_40996364 + 8) == 0) {
      iVar1 = *(int *)(DAT_40996364 + 0xc);
    }
    else {
      iVar1 = mali_sys_thread_key_get_data(4);
    }
    if (iVar1 != 0) {
      iVar6 = *(int *)(iVar1 + 8);
      uVar2 = FUN_4098fbdc(param_4 * 0x101);
      uVar3 = FUN_4098fbdc(param_3 * 0x101);
      uVar4 = FUN_4098fbdc(param_2 * 0x101);
      uVar5 = FUN_4098fbdc(param_1 * 0x101);
      iVar6 = (**(code **)(iVar6 + 0x14c))(iVar1,uVar5,uVar4,uVar3,uVar2);
      if (iVar6 != 0) {
        (**(code **)(*(int *)(iVar1 + 8) + 0x3b8))(iVar1,iVar6);
      }
    }
  }
  return;
}



/* 409903e0 glQueryMatrixxOES */

/* Boundary evidence: original MIPS .pdata 409903e0..40990493. Semantic name remains unreviewed. */

undefined4 glQueryMatrixxOES(undefined4 param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
                    /* 0x303e0  135  glQueryMatrixxOES */
  if (DAT_40996364 != 0) {
    if (*(int *)(DAT_40996364 + 8) == 0) {
      puVar1 = *(undefined4 **)(DAT_40996364 + 0xc);
    }
    else {
      puVar1 = (undefined4 *)mali_sys_thread_key_get_data(4);
    }
    if (puVar1 != (undefined4 *)0x0) {
      if ((puVar1[1] == 1) && (*(int *)(puVar1[0x136] + 0x65a0) != 0)) {
        FUN_40980504(puVar1);
      }
      uVar2 = (**(code **)(puVar1[2] + 0x29c))(puVar1,param_1,param_2);
      return uVar2;
    }
  }
  return 0;
}



/* 40990494 glLoadPaletteFromModelViewMatrixOES */

/* Boundary evidence: original MIPS .pdata 40990494..40990523. Semantic name remains unreviewed. */

void glLoadPaletteFromModelViewMatrixOES(void)

{
  undefined4 *puVar1;
  
                    /* 0x30494  105  glLoadPaletteFromModelViewMatrixOES */
  if (DAT_40996364 != 0) {
    if (*(int *)(DAT_40996364 + 8) == 0) {
      puVar1 = *(undefined4 **)(DAT_40996364 + 0xc);
    }
    else {
      puVar1 = (undefined4 *)mali_sys_thread_key_get_data(4);
    }
    if (puVar1 != (undefined4 *)0x0) {
      if ((puVar1[1] == 1) && (*(int *)(puVar1[0x136] + 0x65a0) != 0)) {
        FUN_40980504(puVar1);
      }
      (**(code **)(puVar1[2] + 0x28c))(puVar1[0x136] + 0x9c);
    }
  }
  return;
}



/* 40990524 glCurrentPaletteMatrixOES */

/* Boundary evidence: original MIPS .pdata 40990524..409905db. Semantic name remains unreviewed. */

void glCurrentPaletteMatrixOES(undefined4 param_1)

{
  undefined4 *puVar1;
  int iVar2;
  
                    /* 0x30524  42  glCurrentPaletteMatrixOES */
  if (DAT_40996364 != 0) {
    if (*(int *)(DAT_40996364 + 8) == 0) {
      puVar1 = *(undefined4 **)(DAT_40996364 + 0xc);
    }
    else {
      puVar1 = (undefined4 *)mali_sys_thread_key_get_data(4);
    }
    if (puVar1 != (undefined4 *)0x0) {
      if ((puVar1[1] == 1) && (*(int *)(puVar1[0x136] + 0x65a0) != 0)) {
        FUN_40980504(puVar1);
      }
      iVar2 = (**(code **)(puVar1[2] + 0x288))(puVar1[0x136] + 0x9c,param_1);
      if (iVar2 != 0) {
        (**(code **)(puVar1[2] + 0x3b8))(puVar1,iVar2);
      }
    }
  }
  return;
}



/* 409905dc glTexParameterxv */

/* Boundary evidence: original MIPS .pdata 409905dc..409906d7. Semantic name remains unreviewed. */

void glTexParameterxv(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  int iVar2;
  
                    /* 0x305dc  161  glTexParameterxv */
  if (DAT_40996364 != 0) {
    if (*(int *)(DAT_40996364 + 8) == 0) {
      puVar1 = *(undefined4 **)(DAT_40996364 + 0xc);
    }
    else {
      puVar1 = (undefined4 *)mali_sys_thread_key_get_data(4);
    }
    if (puVar1 != (undefined4 *)0x0) {
      if ((puVar1[1] == 1) && (*(int *)(puVar1[0x136] + 0x65a0) != 0)) {
        FUN_40980504(puVar1);
      }
      mali_sys_mutex_lock(*(undefined4 *)(puVar1[0x13a] + 0x1c));
      iVar2 = (**(code **)(puVar1[2] + 0x278))(puVar1 + 0xca,param_1,param_2,param_3,1);
      mali_sys_mutex_unlock(*(undefined4 *)(puVar1[0x13a] + 0x1c));
      if (iVar2 != 0) {
        (**(code **)(puVar1[2] + 0x3b8))(puVar1,iVar2);
      }
    }
  }
  return;
}



/* 409906d8 glTexParameterx */

/* Boundary evidence: original MIPS .pdata 409906d8..409907cb. Semantic name remains unreviewed. */

void glTexParameterx(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 local_res8 [2];
  
                    /* 0x306d8  160  glTexParameterx */
  if (DAT_40996364 != 0) {
    local_res8[0] = param_3;
    if (*(int *)(DAT_40996364 + 8) == 0) {
      puVar1 = *(undefined4 **)(DAT_40996364 + 0xc);
    }
    else {
      puVar1 = (undefined4 *)mali_sys_thread_key_get_data(4);
    }
    if (puVar1 != (undefined4 *)0x0) {
      if ((puVar1[1] == 1) && (*(int *)(puVar1[0x136] + 0x65a0) != 0)) {
        FUN_40980504(puVar1);
      }
      mali_sys_mutex_lock(*(undefined4 *)(puVar1[0x13a] + 0x1c));
      iVar2 = (**(code **)(puVar1[2] + 0x274))(puVar1 + 0xca,param_1,param_2,local_res8,1);
      mali_sys_mutex_unlock(*(undefined4 *)(puVar1[0x13a] + 0x1c));
      if (iVar2 != 0) {
        (**(code **)(puVar1[2] + 0x3b8))(puVar1,iVar2);
      }
    }
  }
  return;
}



/* 409907cc glShadeModel */

/* Boundary evidence: original MIPS .pdata 409907cc..4099087f. Semantic name remains unreviewed. */

void glShadeModel(undefined4 param_1)

{
  undefined4 *puVar1;
  int iVar2;
  
                    /* 0x307cc  144  glShadeModel */
  if (DAT_40996364 != 0) {
    if (*(int *)(DAT_40996364 + 8) == 0) {
      puVar1 = *(undefined4 **)(DAT_40996364 + 0xc);
    }
    else {
      puVar1 = (undefined4 *)mali_sys_thread_key_get_data(4);
    }
    if (puVar1 != (undefined4 *)0x0) {
      if ((puVar1[1] == 1) && (*(int *)(puVar1[0x136] + 0x65a0) != 0)) {
        FUN_40980504(puVar1);
      }
      iVar2 = (**(code **)(puVar1[2] + 0x254))(puVar1,param_1);
      if (iVar2 != 0) {
        (**(code **)(puVar1[2] + 0x3b8))(puVar1,iVar2);
      }
    }
  }
  return;
}



/* 40990880 glSampleCoveragex */

/* Boundary evidence: original MIPS .pdata 40990880..40990937. Semantic name remains unreviewed. */

void glSampleCoveragex(uint param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  uint uVar2;
  int iVar3;
  
                    /* 0x30880  140  glSampleCoveragex */
  if (DAT_40996364 != 0) {
    if (*(int *)(DAT_40996364 + 8) == 0) {
      puVar1 = *(undefined4 **)(DAT_40996364 + 0xc);
    }
    else {
      puVar1 = (undefined4 *)mali_sys_thread_key_get_data(4);
    }
    if (puVar1 != (undefined4 *)0x0) {
      if ((puVar1[1] == 1) && (*(int *)(puVar1[0x136] + 0x65a0) != 0)) {
        FUN_40980504(puVar1);
      }
      iVar3 = puVar1[2];
      uVar2 = FUN_4098fbdc(param_1);
      (**(code **)(iVar3 + 0x248))(puVar1,uVar2,param_2);
    }
  }
  return;
}



/* 40990938 glPolygonOffsetx */

/* Boundary evidence: original MIPS .pdata 40990938..40990a17. Semantic name remains unreviewed. */

void glPolygonOffsetx(uint param_1,uint param_2)

{
  undefined4 *puVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  
                    /* 0x30938  132  glPolygonOffsetx */
  if (DAT_40996364 != 0) {
    if (*(int *)(DAT_40996364 + 8) == 0) {
      puVar1 = *(undefined4 **)(DAT_40996364 + 0xc);
    }
    else {
      puVar1 = (undefined4 *)mali_sys_thread_key_get_data(4);
    }
    if (puVar1 != (undefined4 *)0x0) {
      if ((puVar1[1] == 1) && (*(int *)(puVar1[0x136] + 0x65a0) != 0)) {
        FUN_40980504(puVar1);
      }
      iVar4 = puVar1[2];
      uVar2 = FUN_4098fbdc(param_2);
      uVar3 = FUN_4098fbdc(param_1);
      iVar4 = (**(code **)(iVar4 + 0x234))(puVar1,uVar3,uVar2);
      if (iVar4 != 0) {
        (**(code **)(puVar1[2] + 0x3b8))(puVar1,iVar4);
      }
    }
  }
  return;
}



/* 40990a18 glPointSizex */

/* Boundary evidence: original MIPS .pdata 40990a18..40990adb. Semantic name remains unreviewed. */

void glPointSizex(uint param_1)

{
  undefined4 *puVar1;
  uint uVar2;
  int iVar3;
  
                    /* 0x30a18  130  glPointSizex */
  if (DAT_40996364 != 0) {
    if (*(int *)(DAT_40996364 + 8) == 0) {
      puVar1 = *(undefined4 **)(DAT_40996364 + 0xc);
    }
    else {
      puVar1 = (undefined4 *)mali_sys_thread_key_get_data(4);
    }
    if (puVar1 != (undefined4 *)0x0) {
      if ((puVar1[1] == 1) && (*(int *)(puVar1[0x136] + 0x65a0) != 0)) {
        FUN_40980504(puVar1);
      }
      iVar3 = puVar1[2];
      uVar2 = FUN_4098fbdc(param_1);
      iVar3 = (**(code **)(iVar3 + 0x230))(puVar1 + 0xfa,uVar2);
      if (iVar3 != 0) {
        (**(code **)(puVar1[2] + 0x3b8))(puVar1,iVar3);
      }
    }
  }
  return;
}



/* 40990adc glPointSize */

/* Boundary evidence: original MIPS .pdata 40990adc..40990b8f. Semantic name remains unreviewed. */

void glPointSize(undefined4 param_1)

{
  undefined4 *puVar1;
  int iVar2;
  
                    /* 0x30adc  128  glPointSize */
  if (DAT_40996364 != 0) {
    if (*(int *)(DAT_40996364 + 8) == 0) {
      puVar1 = *(undefined4 **)(DAT_40996364 + 0xc);
    }
    else {
      puVar1 = (undefined4 *)mali_sys_thread_key_get_data(4);
    }
    if (puVar1 != (undefined4 *)0x0) {
      if ((puVar1[1] == 1) && (*(int *)(puVar1[0x136] + 0x65a0) != 0)) {
        FUN_40980504(puVar1);
      }
      iVar2 = (**(code **)(puVar1[2] + 0x22c))(puVar1 + 0xfa,param_1);
      if (iVar2 != 0) {
        (**(code **)(puVar1[2] + 0x3b8))(puVar1,iVar2);
      }
    }
  }
  return;
}



/* 40990b90 glPointParameterxv */

/* Boundary evidence: original MIPS .pdata 40990b90..40990c57. Semantic name remains unreviewed. */

void glPointParameterxv(undefined4 param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  int iVar2;
  
                    /* 0x30b90  127  glPointParameterxv */
  if (DAT_40996364 != 0) {
    if (*(int *)(DAT_40996364 + 8) == 0) {
      puVar1 = *(undefined4 **)(DAT_40996364 + 0xc);
    }
    else {
      puVar1 = (undefined4 *)mali_sys_thread_key_get_data(4);
    }
    if (puVar1 != (undefined4 *)0x0) {
      if ((puVar1[1] == 1) && (*(int *)(puVar1[0x136] + 0x65a0) != 0)) {
        FUN_40980504(puVar1);
      }
      iVar2 = (**(code **)(puVar1[2] + 0x228))(puVar1,param_1,param_2,1);
      if (iVar2 != 0) {
        (**(code **)(puVar1[2] + 0x3b8))(puVar1,iVar2);
      }
    }
  }
  return;
}



/* 40990c58 glPointParameterx */

/* Boundary evidence: original MIPS .pdata 40990c58..40990d17. Semantic name remains unreviewed. */

void glPointParameterx(undefined4 param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 local_res4 [3];
  
                    /* 0x30c58  126  glPointParameterx */
  if (DAT_40996364 != 0) {
    local_res4[0] = param_2;
    if (*(int *)(DAT_40996364 + 8) == 0) {
      puVar1 = *(undefined4 **)(DAT_40996364 + 0xc);
    }
    else {
      puVar1 = (undefined4 *)mali_sys_thread_key_get_data(4);
    }
    if (puVar1 != (undefined4 *)0x0) {
      if ((puVar1[1] == 1) && (*(int *)(puVar1[0x136] + 0x65a0) != 0)) {
        FUN_40980504(puVar1);
      }
      iVar2 = (**(code **)(puVar1[2] + 0x224))(puVar1,param_1,local_res4,1);
      if (iVar2 != 0) {
        (**(code **)(puVar1[2] + 0x3b8))(puVar1,iVar2);
      }
    }
  }
  return;
}



/* 40990d18 glPointParameterfv */

/* Boundary evidence: original MIPS .pdata 40990d18..40990ddf. Semantic name remains unreviewed. */

void glPointParameterfv(undefined4 param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  int iVar2;
  
                    /* 0x30d18  125  glPointParameterfv */
  if (DAT_40996364 != 0) {
    if (*(int *)(DAT_40996364 + 8) == 0) {
      puVar1 = *(undefined4 **)(DAT_40996364 + 0xc);
    }
    else {
      puVar1 = (undefined4 *)mali_sys_thread_key_get_data(4);
    }
    if (puVar1 != (undefined4 *)0x0) {
      if ((puVar1[1] == 1) && (*(int *)(puVar1[0x136] + 0x65a0) != 0)) {
        FUN_40980504(puVar1);
      }
      iVar2 = (**(code **)(puVar1[2] + 0x220))(puVar1,param_1,param_2,0);
      if (iVar2 != 0) {
        (**(code **)(puVar1[2] + 0x3b8))(puVar1,iVar2);
      }
    }
  }
  return;
}



/* 40990de0 glPointParameterf */

/* Boundary evidence: original MIPS .pdata 40990de0..40990e9f. Semantic name remains unreviewed. */

void glPointParameterf(undefined4 param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 local_res4 [3];
  
                    /* 0x30de0  124  glPointParameterf */
  if (DAT_40996364 != 0) {
    local_res4[0] = param_2;
    if (*(int *)(DAT_40996364 + 8) == 0) {
      puVar1 = *(undefined4 **)(DAT_40996364 + 0xc);
    }
    else {
      puVar1 = (undefined4 *)mali_sys_thread_key_get_data(4);
    }
    if (puVar1 != (undefined4 *)0x0) {
      if ((puVar1[1] == 1) && (*(int *)(puVar1[0x136] + 0x65a0) != 0)) {
        FUN_40980504(puVar1);
      }
      iVar2 = (**(code **)(puVar1[2] + 0x21c))(puVar1,param_1,local_res4,0);
      if (iVar2 != 0) {
        (**(code **)(puVar1[2] + 0x3b8))(puVar1,iVar2);
      }
    }
  }
  return;
}



/* 40990ea0 glNormal3x */

/* Boundary evidence: original MIPS .pdata 40990ea0..40990fa3. Semantic name remains unreviewed. */

void glNormal3x(uint param_1,uint param_2,uint param_3)

{
  undefined4 *puVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  
                    /* 0x30ea0  119  glNormal3x */
  if (DAT_40996364 != 0) {
    if (*(int *)(DAT_40996364 + 8) == 0) {
      puVar1 = *(undefined4 **)(DAT_40996364 + 0xc);
    }
    else {
      puVar1 = (undefined4 *)mali_sys_thread_key_get_data(4);
    }
    if (puVar1 != (undefined4 *)0x0) {
      if ((puVar1[1] == 1) && (*(int *)(puVar1[0x136] + 0x65a0) != 0)) {
        FUN_40980504(puVar1);
      }
      iVar5 = puVar1[2];
      uVar2 = FUN_4098fbdc(param_3);
      uVar3 = FUN_4098fbdc(param_2);
      uVar4 = FUN_4098fbdc(param_1);
      iVar5 = (**(code **)(iVar5 + 0x20c))(puVar1[0x136],uVar4,uVar3,uVar2);
      if (iVar5 != 0) {
        (**(code **)(puVar1[2] + 0x3b8))(puVar1,iVar5);
      }
    }
  }
  return;
}



/* 40990fa4 glNormal3f */

/* Boundary evidence: original MIPS .pdata 40990fa4..40991077. Semantic name remains unreviewed. */

void glNormal3f(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  int iVar2;
  
                    /* 0x30fa4  118  glNormal3f */
  if (DAT_40996364 != 0) {
    if (*(int *)(DAT_40996364 + 8) == 0) {
      puVar1 = *(undefined4 **)(DAT_40996364 + 0xc);
    }
    else {
      puVar1 = (undefined4 *)mali_sys_thread_key_get_data(4);
    }
    if (puVar1 != (undefined4 *)0x0) {
      if ((puVar1[1] == 1) && (*(int *)(puVar1[0x136] + 0x65a0) != 0)) {
        FUN_40980504(puVar1);
      }
      iVar2 = (**(code **)(puVar1[2] + 0x208))(puVar1[0x136],param_1,param_2,param_3);
      if (iVar2 != 0) {
        (**(code **)(puVar1[2] + 0x3b8))(puVar1,iVar2);
      }
    }
  }
  return;
}



/* 40991078 glMultiTexCoord4x */

/* Boundary evidence: original MIPS .pdata 40991078..409911a3. Semantic name remains unreviewed. */

void glMultiTexCoord4x(undefined4 param_1,uint param_2,uint param_3,uint param_4,uint param_5)

{
  undefined4 *puVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  
                    /* 0x31078  117  glMultiTexCoord4x */
  if (DAT_40996364 != 0) {
    if (*(int *)(DAT_40996364 + 8) == 0) {
      puVar1 = *(undefined4 **)(DAT_40996364 + 0xc);
    }
    else {
      puVar1 = (undefined4 *)mali_sys_thread_key_get_data(4);
    }
    if (puVar1 != (undefined4 *)0x0) {
      if ((puVar1[1] == 1) && (*(int *)(puVar1[0x136] + 0x65a0) != 0)) {
        FUN_40980504(puVar1);
      }
      iVar6 = puVar1[2];
      uVar2 = FUN_4098fbdc(param_5);
      uVar3 = FUN_4098fbdc(param_4);
      uVar4 = FUN_4098fbdc(param_3);
      uVar5 = FUN_4098fbdc(param_2);
      iVar6 = (**(code **)(iVar6 + 0x1fc))(puVar1[0x136],param_1,uVar5,uVar4,uVar3,uVar2);
      if (iVar6 != 0) {
        (**(code **)(puVar1[2] + 0x3b8))(puVar1,iVar6);
      }
    }
  }
  return;
}



/* 409911a4 glMultiTexCoord4f */

/* Boundary evidence: original MIPS .pdata 409911a4..4099128f. Semantic name remains unreviewed. */

void glMultiTexCoord4f(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                      undefined4 param_5)

{
  undefined4 *puVar1;
  int iVar2;
  
                    /* 0x311a4  116  glMultiTexCoord4f */
  if (DAT_40996364 != 0) {
    if (*(int *)(DAT_40996364 + 8) == 0) {
      puVar1 = *(undefined4 **)(DAT_40996364 + 0xc);
    }
    else {
      puVar1 = (undefined4 *)mali_sys_thread_key_get_data(4);
    }
    if (puVar1 != (undefined4 *)0x0) {
      if ((puVar1[1] == 1) && (*(int *)(puVar1[0x136] + 0x65a0) != 0)) {
        FUN_40980504(puVar1);
      }
      iVar2 = (**(code **)(puVar1[2] + 0x1f8))
                        (puVar1[0x136],param_1,param_2,param_3,param_4,param_5);
      if (iVar2 != 0) {
        (**(code **)(puVar1[2] + 0x3b8))(puVar1,iVar2);
      }
    }
  }
  return;
}



/* 40991290 glMultiTexCoord4b */

/* Boundary evidence: original MIPS .pdata 40991290..409913cb. Semantic name remains unreviewed. */

void glMultiTexCoord4b(undefined4 param_1,int param_2,int param_3,int param_4,char param_5)

{
  undefined4 *puVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  
                    /* 0x31290  115  glMultiTexCoord4b */
  if (DAT_40996364 != 0) {
    if (*(int *)(DAT_40996364 + 8) == 0) {
      puVar1 = *(undefined4 **)(DAT_40996364 + 0xc);
    }
    else {
      puVar1 = (undefined4 *)mali_sys_thread_key_get_data(4);
    }
    if (puVar1 != (undefined4 *)0x0) {
      if ((puVar1[1] == 1) && (*(int *)(puVar1[0x136] + 0x65a0) != 0)) {
        FUN_40980504(puVar1);
      }
      iVar6 = puVar1[2];
      uVar2 = FUN_4098fbdc(param_5 * 0x204);
      uVar3 = FUN_4098fbdc(param_4 * 0x204);
      uVar4 = FUN_4098fbdc(param_3 * 0x204);
      uVar5 = FUN_4098fbdc(param_2 * 0x204);
      iVar6 = (**(code **)(iVar6 + 500))(puVar1[0x136],param_1,uVar5,uVar4,uVar3,uVar2);
      if (iVar6 != 0) {
        (**(code **)(puVar1[2] + 0x3b8))(puVar1,iVar6);
      }
    }
  }
  return;
}



/* 409913cc glMaterialxv */

/* Boundary evidence: original MIPS .pdata 409913cc..409914ab. Semantic name remains unreviewed. */

void glMaterialxv(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  int iVar2;
  
                    /* 0x313cc  110  glMaterialxv */
  if (DAT_40996364 != 0) {
    if (*(int *)(DAT_40996364 + 8) == 0) {
      puVar1 = *(undefined4 **)(DAT_40996364 + 0xc);
    }
    else {
      puVar1 = (undefined4 *)mali_sys_thread_key_get_data(4);
    }
    if (puVar1 != (undefined4 *)0x0) {
      if ((puVar1[1] == 1) && (*(int *)(puVar1[0x136] + 0x65a0) != 0)) {
        FUN_40980504(puVar1);
      }
      iVar2 = (**(code **)(puVar1[2] + 0x1ec))(puVar1,param_1,param_2,param_3,1);
      if (iVar2 != 0) {
        (**(code **)(puVar1[2] + 0x3b8))(puVar1,iVar2);
      }
    }
  }
  return;
}



/* 409914ac glMaterialx */

/* Boundary evidence: original MIPS .pdata 409914ac..40991583. Semantic name remains unreviewed. */

void glMaterialx(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 local_res8 [2];
  
                    /* 0x314ac  109  glMaterialx */
  if (DAT_40996364 != 0) {
    local_res8[0] = param_3;
    if (*(int *)(DAT_40996364 + 8) == 0) {
      puVar1 = *(undefined4 **)(DAT_40996364 + 0xc);
    }
    else {
      puVar1 = (undefined4 *)mali_sys_thread_key_get_data(4);
    }
    if (puVar1 != (undefined4 *)0x0) {
      if ((puVar1[1] == 1) && (*(int *)(puVar1[0x136] + 0x65a0) != 0)) {
        FUN_40980504(puVar1);
      }
      iVar2 = (**(code **)(puVar1[2] + 0x1e8))(puVar1,param_1,param_2,local_res8,1);
      if (iVar2 != 0) {
        (**(code **)(puVar1[2] + 0x3b8))(puVar1,iVar2);
      }
    }
  }
  return;
}



/* 40991584 glMaterialfv */

/* Boundary evidence: original MIPS .pdata 40991584..4099165b. Semantic name remains unreviewed. */

void glMaterialfv(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  int iVar2;
  
                    /* 0x31584  108  glMaterialfv */
  if (DAT_40996364 != 0) {
    if (*(int *)(DAT_40996364 + 8) == 0) {
      puVar1 = *(undefined4 **)(DAT_40996364 + 0xc);
    }
    else {
      puVar1 = (undefined4 *)mali_sys_thread_key_get_data(4);
    }
    if (puVar1 != (undefined4 *)0x0) {
      if ((puVar1[1] == 1) && (*(int *)(puVar1[0x136] + 0x65a0) != 0)) {
        FUN_40980504(puVar1);
      }
      iVar2 = (**(code **)(puVar1[2] + 0x1e4))(puVar1,param_1,param_2,param_3,0);
      if (iVar2 != 0) {
        (**(code **)(puVar1[2] + 0x3b8))(puVar1,iVar2);
      }
    }
  }
  return;
}



/* 4099165c glMaterialf */

/* Boundary evidence: original MIPS .pdata 4099165c..4099172b. Semantic name remains unreviewed. */

void glMaterialf(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 local_res8 [2];
  
                    /* 0x3165c  107  glMaterialf */
  if (DAT_40996364 != 0) {
    local_res8[0] = param_3;
    if (*(int *)(DAT_40996364 + 8) == 0) {
      puVar1 = *(undefined4 **)(DAT_40996364 + 0xc);
    }
    else {
      puVar1 = (undefined4 *)mali_sys_thread_key_get_data(4);
    }
    if (puVar1 != (undefined4 *)0x0) {
      if ((puVar1[1] == 1) && (*(int *)(puVar1[0x136] + 0x65a0) != 0)) {
        FUN_40980504(puVar1);
      }
      iVar2 = (**(code **)(puVar1[2] + 0x1e0))(puVar1,param_1,param_2,local_res8,0);
      if (iVar2 != 0) {
        (**(code **)(puVar1[2] + 0x3b8))(puVar1,iVar2);
      }
    }
  }
  return;
}



/* 4099172c glLogicOp */

/* Boundary evidence: original MIPS .pdata 4099172c..409917df. Semantic name remains unreviewed. */

void glLogicOp(undefined4 param_1)

{
  undefined4 *puVar1;
  int iVar2;
  
                    /* 0x3172c  106  glLogicOp */
  if (DAT_40996364 != 0) {
    if (*(int *)(DAT_40996364 + 8) == 0) {
      puVar1 = *(undefined4 **)(DAT_40996364 + 0xc);
    }
    else {
      puVar1 = (undefined4 *)mali_sys_thread_key_get_data(4);
    }
    if (puVar1 != (undefined4 *)0x0) {
      if ((puVar1[1] == 1) && (*(int *)(puVar1[0x136] + 0x65a0) != 0)) {
        FUN_40980504(puVar1);
      }
      iVar2 = (**(code **)(puVar1[2] + 0x1dc))(puVar1,param_1);
      if (iVar2 != 0) {
        (**(code **)(puVar1[2] + 0x3b8))(puVar1,iVar2);
      }
    }
  }
  return;
}



/* 409917e0 glLightxv */

/* Boundary evidence: original MIPS .pdata 409917e0..409918bf. Semantic name remains unreviewed. */

void glLightxv(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  int iVar2;
  
                    /* 0x317e0  99  glLightxv */
  if (DAT_40996364 != 0) {
    if (*(int *)(DAT_40996364 + 8) == 0) {
      puVar1 = *(undefined4 **)(DAT_40996364 + 0xc);
    }
    else {
      puVar1 = (undefined4 *)mali_sys_thread_key_get_data(4);
    }
    if (puVar1 != (undefined4 *)0x0) {
      if ((puVar1[1] == 1) && (*(int *)(puVar1[0x136] + 0x65a0) != 0)) {
        FUN_40980504(puVar1);
      }
      iVar2 = (**(code **)(puVar1[2] + 0x1c8))(puVar1,param_1,param_2,param_3,1);
      if (iVar2 != 0) {
        (**(code **)(puVar1[2] + 0x3b8))(puVar1,iVar2);
      }
    }
  }
  return;
}



/* 409918c0 glLightx */

/* Boundary evidence: original MIPS .pdata 409918c0..40991997. Semantic name remains unreviewed. */

void glLightx(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 local_res8 [2];
  
                    /* 0x318c0  98  glLightx */
  if (DAT_40996364 != 0) {
    local_res8[0] = param_3;
    if (*(int *)(DAT_40996364 + 8) == 0) {
      puVar1 = *(undefined4 **)(DAT_40996364 + 0xc);
    }
    else {
      puVar1 = (undefined4 *)mali_sys_thread_key_get_data(4);
    }
    if (puVar1 != (undefined4 *)0x0) {
      if ((puVar1[1] == 1) && (*(int *)(puVar1[0x136] + 0x65a0) != 0)) {
        FUN_40980504(puVar1);
      }
      iVar2 = (**(code **)(puVar1[2] + 0x1c4))(puVar1,param_1,param_2,local_res8,1);
      if (iVar2 != 0) {
        (**(code **)(puVar1[2] + 0x3b8))(puVar1,iVar2);
      }
    }
  }
  return;
}



/* 40991998 glLightModelxv */

/* Boundary evidence: original MIPS .pdata 40991998..40991a5f. Semantic name remains unreviewed. */

void glLightModelxv(undefined4 param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  int iVar2;
  
                    /* 0x31998  95  glLightModelxv */
  if (DAT_40996364 != 0) {
    if (*(int *)(DAT_40996364 + 8) == 0) {
      puVar1 = *(undefined4 **)(DAT_40996364 + 0xc);
    }
    else {
      puVar1 = (undefined4 *)mali_sys_thread_key_get_data(4);
    }
    if (puVar1 != (undefined4 *)0x0) {
      if ((puVar1[1] == 1) && (*(int *)(puVar1[0x136] + 0x65a0) != 0)) {
        FUN_40980504(puVar1);
      }
      iVar2 = (**(code **)(puVar1[2] + 0x1c0))(puVar1,param_1,param_2,1);
      if (iVar2 != 0) {
        (**(code **)(puVar1[2] + 0x3b8))(puVar1,iVar2);
      }
    }
  }
  return;
}



/* 40991a60 glLightModelx */

/* Boundary evidence: original MIPS .pdata 40991a60..40991b1f. Semantic name remains unreviewed. */

void glLightModelx(undefined4 param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 local_res4 [3];
  
                    /* 0x31a60  94  glLightModelx */
  if (DAT_40996364 != 0) {
    local_res4[0] = param_2;
    if (*(int *)(DAT_40996364 + 8) == 0) {
      puVar1 = *(undefined4 **)(DAT_40996364 + 0xc);
    }
    else {
      puVar1 = (undefined4 *)mali_sys_thread_key_get_data(4);
    }
    if (puVar1 != (undefined4 *)0x0) {
      if ((puVar1[1] == 1) && (*(int *)(puVar1[0x136] + 0x65a0) != 0)) {
        FUN_40980504(puVar1);
      }
      iVar2 = (**(code **)(puVar1[2] + 0x1bc))(puVar1,param_1,local_res4,1);
      if (iVar2 != 0) {
        (**(code **)(puVar1[2] + 0x3b8))(puVar1,iVar2);
      }
    }
  }
  return;
}



/* 40991b20 glLightModelfv */

/* Boundary evidence: original MIPS .pdata 40991b20..40991be7. Semantic name remains unreviewed. */

void glLightModelfv(undefined4 param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  int iVar2;
  
                    /* 0x31b20  93  glLightModelfv */
  if (DAT_40996364 != 0) {
    if (*(int *)(DAT_40996364 + 8) == 0) {
      puVar1 = *(undefined4 **)(DAT_40996364 + 0xc);
    }
    else {
      puVar1 = (undefined4 *)mali_sys_thread_key_get_data(4);
    }
    if (puVar1 != (undefined4 *)0x0) {
      if ((puVar1[1] == 1) && (*(int *)(puVar1[0x136] + 0x65a0) != 0)) {
        FUN_40980504(puVar1);
      }
      iVar2 = (**(code **)(puVar1[2] + 0x1b8))(puVar1,param_1,param_2,0);
      if (iVar2 != 0) {
        (**(code **)(puVar1[2] + 0x3b8))(puVar1,iVar2);
      }
    }
  }
  return;
}



/* 40991be8 glLightModelf */

/* Boundary evidence: original MIPS .pdata 40991be8..40991ca7. Semantic name remains unreviewed. */

void glLightModelf(undefined4 param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 local_res4 [3];
  
                    /* 0x31be8  92  glLightModelf */
  if (DAT_40996364 != 0) {
    local_res4[0] = param_2;
    if (*(int *)(DAT_40996364 + 8) == 0) {
      puVar1 = *(undefined4 **)(DAT_40996364 + 0xc);
    }
    else {
      puVar1 = (undefined4 *)mali_sys_thread_key_get_data(4);
    }
    if (puVar1 != (undefined4 *)0x0) {
      if ((puVar1[1] == 1) && (*(int *)(puVar1[0x136] + 0x65a0) != 0)) {
        FUN_40980504(puVar1);
      }
      iVar2 = (**(code **)(puVar1[2] + 0x1b4))(puVar1,param_1,local_res4,0);
      if (iVar2 != 0) {
        (**(code **)(puVar1[2] + 0x3b8))(puVar1,iVar2);
      }
    }
  }
  return;
}



/* 40991ca8 glLightfv */

/* Boundary evidence: original MIPS .pdata 40991ca8..40991d7f. Semantic name remains unreviewed. */

void glLightfv(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  int iVar2;
  
                    /* 0x31ca8  97  glLightfv */
  if (DAT_40996364 != 0) {
    if (*(int *)(DAT_40996364 + 8) == 0) {
      puVar1 = *(undefined4 **)(DAT_40996364 + 0xc);
    }
    else {
      puVar1 = (undefined4 *)mali_sys_thread_key_get_data(4);
    }
    if (puVar1 != (undefined4 *)0x0) {
      if ((puVar1[1] == 1) && (*(int *)(puVar1[0x136] + 0x65a0) != 0)) {
        FUN_40980504(puVar1);
      }
      iVar2 = (**(code **)(puVar1[2] + 0x1b0))(puVar1,param_1,param_2,param_3,0);
      if (iVar2 != 0) {
        (**(code **)(puVar1[2] + 0x3b8))(puVar1,iVar2);
      }
    }
  }
  return;
}



/* 40991d80 glLightf */

/* Boundary evidence: original MIPS .pdata 40991d80..40991e4f. Semantic name remains unreviewed. */

void glLightf(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 local_res8 [2];
  
                    /* 0x31d80  96  glLightf */
  if (DAT_40996364 != 0) {
    local_res8[0] = param_3;
    if (*(int *)(DAT_40996364 + 8) == 0) {
      puVar1 = *(undefined4 **)(DAT_40996364 + 0xc);
    }
    else {
      puVar1 = (undefined4 *)mali_sys_thread_key_get_data(4);
    }
    if (puVar1 != (undefined4 *)0x0) {
      if ((puVar1[1] == 1) && (*(int *)(puVar1[0x136] + 0x65a0) != 0)) {
        FUN_40980504(puVar1);
      }
      iVar2 = (**(code **)(puVar1[2] + 0x1ac))(puVar1,param_1,param_2,local_res8,0);
      if (iVar2 != 0) {
        (**(code **)(puVar1[2] + 0x3b8))(puVar1,iVar2);
      }
    }
  }
  return;
}



/* 40991e50 glGetTexParameterxv */

/* Boundary evidence: original MIPS .pdata 40991e50..40991f4b. Semantic name remains unreviewed. */

void glGetTexParameterxv(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  int iVar2;
  
                    /* 0x31e50  87  glGetTexParameterxv */
  if (DAT_40996364 != 0) {
    if (*(int *)(DAT_40996364 + 8) == 0) {
      puVar1 = *(undefined4 **)(DAT_40996364 + 0xc);
    }
    else {
      puVar1 = (undefined4 *)mali_sys_thread_key_get_data(4);
    }
    if (puVar1 != (undefined4 *)0x0) {
      if ((puVar1[1] == 1) && (*(int *)(puVar1[0x136] + 0x65a0) != 0)) {
        FUN_40980504(puVar1);
      }
      mali_sys_mutex_lock(*(undefined4 *)(puVar1[0x13a] + 0x1c));
      iVar2 = (**(code **)(puVar1[2] + 0x1a8))(puVar1 + 3,param_1,param_2,param_3,1);
      mali_sys_mutex_unlock(*(undefined4 *)(puVar1[0x13a] + 0x1c));
      if (iVar2 != 0) {
        (**(code **)(puVar1[2] + 0x3b8))(puVar1,iVar2);
      }
    }
  }
  return;
}



/* 40991f4c glGetTexEnvxv */

/* Boundary evidence: original MIPS .pdata 40991f4c..4099202b. Semantic name remains unreviewed. */

void glGetTexEnvxv(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  int iVar2;
  
                    /* 0x31f4c  84  glGetTexEnvxv */
  if (DAT_40996364 != 0) {
    if (*(int *)(DAT_40996364 + 8) == 0) {
      puVar1 = *(undefined4 **)(DAT_40996364 + 0xc);
    }
    else {
      puVar1 = (undefined4 *)mali_sys_thread_key_get_data(4);
    }
    if (puVar1 != (undefined4 *)0x0) {
      if ((puVar1[1] == 1) && (*(int *)(puVar1[0x136] + 0x65a0) != 0)) {
        FUN_40980504(puVar1);
      }
      iVar2 = (**(code **)(puVar1[2] + 0x1a4))(puVar1 + 3,param_1,param_2,param_3,1);
      if (iVar2 != 0) {
        (**(code **)(puVar1[2] + 0x3b8))(puVar1,iVar2);
      }
    }
  }
  return;
}



/* 4099202c glGetTexEnviv */

/* Boundary evidence: original MIPS .pdata 4099202c..40992107. Semantic name remains unreviewed. */

void glGetTexEnviv(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  int iVar2;
  
                    /* 0x3202c  83  glGetTexEnviv */
  if (DAT_40996364 != 0) {
    if (*(int *)(DAT_40996364 + 8) == 0) {
      puVar1 = *(undefined4 **)(DAT_40996364 + 0xc);
    }
    else {
      puVar1 = (undefined4 *)mali_sys_thread_key_get_data(4);
    }
    if (puVar1 != (undefined4 *)0x0) {
      if ((puVar1[1] == 1) && (*(int *)(puVar1[0x136] + 0x65a0) != 0)) {
        FUN_40980504(puVar1);
      }
      iVar2 = (**(code **)(puVar1[2] + 0x1a0))(puVar1 + 3,param_1,param_2,param_3,3);
      if (iVar2 != 0) {
        (**(code **)(puVar1[2] + 0x3b8))(puVar1,iVar2);
      }
    }
  }
  return;
}



/* 40992108 glGetTexEnvfv */

/* Boundary evidence: original MIPS .pdata 40992108..409921df. Semantic name remains unreviewed. */

void glGetTexEnvfv(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  int iVar2;
  
                    /* 0x32108  82  glGetTexEnvfv */
  if (DAT_40996364 != 0) {
    if (*(int *)(DAT_40996364 + 8) == 0) {
      puVar1 = *(undefined4 **)(DAT_40996364 + 0xc);
    }
    else {
      puVar1 = (undefined4 *)mali_sys_thread_key_get_data(4);
    }
    if (puVar1 != (undefined4 *)0x0) {
      if ((puVar1[1] == 1) && (*(int *)(puVar1[0x136] + 0x65a0) != 0)) {
        FUN_40980504(puVar1);
      }
      iVar2 = (**(code **)(puVar1[2] + 0x19c))(puVar1 + 3,param_1,param_2,param_3,0);
      if (iVar2 != 0) {
        (**(code **)(puVar1[2] + 0x3b8))(puVar1,iVar2);
      }
    }
  }
  return;
}



/* 409921e0 glGetPointerv */

/* Boundary evidence: original MIPS .pdata 409921e0..409922a3. Semantic name remains unreviewed. */

void glGetPointerv(undefined4 param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  int iVar2;
  
                    /* 0x321e0  80  glGetPointerv */
  if (DAT_40996364 != 0) {
    if (*(int *)(DAT_40996364 + 8) == 0) {
      puVar1 = *(undefined4 **)(DAT_40996364 + 0xc);
    }
    else {
      puVar1 = (undefined4 *)mali_sys_thread_key_get_data(4);
    }
    if (puVar1 != (undefined4 *)0x0) {
      if ((puVar1[1] == 1) && (*(int *)(puVar1[0x136] + 0x65a0) != 0)) {
        FUN_40980504(puVar1);
      }
      iVar2 = (**(code **)(puVar1[2] + 0x198))(puVar1 + 3,param_1,param_2);
      if (iVar2 != 0) {
        (**(code **)(puVar1[2] + 0x3b8))(puVar1,iVar2);
      }
    }
  }
  return;
}



/* 409922a4 glGetMaterialxv */

/* Boundary evidence: original MIPS .pdata 409922a4..40992383. Semantic name remains unreviewed. */

void glGetMaterialxv(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  int iVar2;
  
                    /* 0x322a4  79  glGetMaterialxv */
  if (DAT_40996364 != 0) {
    if (*(int *)(DAT_40996364 + 8) == 0) {
      puVar1 = *(undefined4 **)(DAT_40996364 + 0xc);
    }
    else {
      puVar1 = (undefined4 *)mali_sys_thread_key_get_data(4);
    }
    if (puVar1 != (undefined4 *)0x0) {
      if ((puVar1[1] == 1) && (*(int *)(puVar1[0x136] + 0x65a0) != 0)) {
        FUN_40980504(puVar1);
      }
      iVar2 = (**(code **)(puVar1[2] + 0x194))(puVar1 + 3,param_1,param_2,param_3,1);
      if (iVar2 != 0) {
        (**(code **)(puVar1[2] + 0x3b8))(puVar1,iVar2);
      }
    }
  }
  return;
}



/* 40992384 glGetMaterialfv */

/* Boundary evidence: original MIPS .pdata 40992384..4099245b. Semantic name remains unreviewed. */

void glGetMaterialfv(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  int iVar2;
  
                    /* 0x32384  78  glGetMaterialfv */
  if (DAT_40996364 != 0) {
    if (*(int *)(DAT_40996364 + 8) == 0) {
      puVar1 = *(undefined4 **)(DAT_40996364 + 0xc);
    }
    else {
      puVar1 = (undefined4 *)mali_sys_thread_key_get_data(4);
    }
    if (puVar1 != (undefined4 *)0x0) {
      if ((puVar1[1] == 1) && (*(int *)(puVar1[0x136] + 0x65a0) != 0)) {
        FUN_40980504(puVar1);
      }
      iVar2 = (**(code **)(puVar1[2] + 400))(puVar1 + 3,param_1,param_2,param_3,0);
      if (iVar2 != 0) {
        (**(code **)(puVar1[2] + 0x3b8))(puVar1,iVar2);
      }
    }
  }
  return;
}



/* 4099245c glGetLightxv */

/* Boundary evidence: original MIPS .pdata 4099245c..4099253b. Semantic name remains unreviewed. */

void glGetLightxv(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  int iVar2;
  
                    /* 0x3245c  77  glGetLightxv */
  if (DAT_40996364 != 0) {
    if (*(int *)(DAT_40996364 + 8) == 0) {
      puVar1 = *(undefined4 **)(DAT_40996364 + 0xc);
    }
    else {
      puVar1 = (undefined4 *)mali_sys_thread_key_get_data(4);
    }
    if (puVar1 != (undefined4 *)0x0) {
      if ((puVar1[1] == 1) && (*(int *)(puVar1[0x136] + 0x65a0) != 0)) {
        FUN_40980504(puVar1);
      }
      iVar2 = (**(code **)(puVar1[2] + 0x18c))(puVar1 + 3,param_1,param_2,param_3,1);
      if (iVar2 != 0) {
        (**(code **)(puVar1[2] + 0x3b8))(puVar1,iVar2);
      }
    }
  }
  return;
}



/* 4099253c glGetLightfv */

/* Boundary evidence: original MIPS .pdata 4099253c..40992613. Semantic name remains unreviewed. */

void glGetLightfv(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  int iVar2;
  
                    /* 0x3253c  76  glGetLightfv */
  if (DAT_40996364 != 0) {
    if (*(int *)(DAT_40996364 + 8) == 0) {
      puVar1 = *(undefined4 **)(DAT_40996364 + 0xc);
    }
    else {
      puVar1 = (undefined4 *)mali_sys_thread_key_get_data(4);
    }
    if (puVar1 != (undefined4 *)0x0) {
      if ((puVar1[1] == 1) && (*(int *)(puVar1[0x136] + 0x65a0) != 0)) {
        FUN_40980504(puVar1);
      }
      iVar2 = (**(code **)(puVar1[2] + 0x188))(puVar1 + 3,param_1,param_2,param_3,0);
      if (iVar2 != 0) {
        (**(code **)(puVar1[2] + 0x3b8))(puVar1,iVar2);
      }
    }
  }
  return;
}



/* 40992614 glGetFixedv */

/* Boundary evidence: original MIPS .pdata 40992614..409926db. Semantic name remains unreviewed. */

void glGetFixedv(undefined4 param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  int iVar2;
  
                    /* 0x32614  73  glGetFixedv */
  if (DAT_40996364 != 0) {
    if (*(int *)(DAT_40996364 + 8) == 0) {
      puVar1 = *(undefined4 **)(DAT_40996364 + 0xc);
    }
    else {
      puVar1 = (undefined4 *)mali_sys_thread_key_get_data(4);
    }
    if (puVar1 != (undefined4 *)0x0) {
      if ((puVar1[1] == 1) && (*(int *)(puVar1[0x136] + 0x65a0) != 0)) {
        FUN_40980504(puVar1);
      }
      iVar2 = (**(code **)(puVar1[2] + 0x184))(puVar1,param_1,param_2,1);
      if (iVar2 != 0) {
        (**(code **)(puVar1[2] + 0x3b8))(puVar1,iVar2);
      }
    }
  }
  return;
}



/* 409926dc glGetClipPlanex */

/* Boundary evidence: original MIPS .pdata 409926dc..409927a3. Semantic name remains unreviewed. */

void glGetClipPlanex(undefined4 param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  int iVar2;
  
                    /* 0x326dc  71  glGetClipPlanex */
  if (DAT_40996364 != 0) {
    if (*(int *)(DAT_40996364 + 8) == 0) {
      puVar1 = *(undefined4 **)(DAT_40996364 + 0xc);
    }
    else {
      puVar1 = (undefined4 *)mali_sys_thread_key_get_data(4);
    }
    if (puVar1 != (undefined4 *)0x0) {
      if ((puVar1[1] == 1) && (*(int *)(puVar1[0x136] + 0x65a0) != 0)) {
        FUN_40980504(puVar1);
      }
      iVar2 = (**(code **)(puVar1[2] + 0x180))(puVar1 + 3,param_1,param_2,1);
      if (iVar2 != 0) {
        (**(code **)(puVar1[2] + 0x3b8))(puVar1,iVar2);
      }
    }
  }
  return;
}



/* 409927a4 glGetClipPlanef */

/* Boundary evidence: original MIPS .pdata 409927a4..4099286b. Semantic name remains unreviewed. */

void glGetClipPlanef(undefined4 param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  int iVar2;
  
                    /* 0x327a4  70  glGetClipPlanef */
  if (DAT_40996364 != 0) {
    if (*(int *)(DAT_40996364 + 8) == 0) {
      puVar1 = *(undefined4 **)(DAT_40996364 + 0xc);
    }
    else {
      puVar1 = (undefined4 *)mali_sys_thread_key_get_data(4);
    }
    if (puVar1 != (undefined4 *)0x0) {
      if ((puVar1[1] == 1) && (*(int *)(puVar1[0x136] + 0x65a0) != 0)) {
        FUN_40980504(puVar1);
      }
      iVar2 = (**(code **)(puVar1[2] + 0x17c))(puVar1 + 3,param_1,param_2,0);
      if (iVar2 != 0) {
        (**(code **)(puVar1[2] + 0x3b8))(puVar1,iVar2);
      }
    }
  }
  return;
}



/* 4099286c glFogxv */

/* Boundary evidence: original MIPS .pdata 4099286c..40992933. Semantic name remains unreviewed. */

void glFogxv(undefined4 param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  int iVar2;
  
                    /* 0x3286c  62  glFogxv */
  if (DAT_40996364 != 0) {
    if (*(int *)(DAT_40996364 + 8) == 0) {
      puVar1 = *(undefined4 **)(DAT_40996364 + 0xc);
    }
    else {
      puVar1 = (undefined4 *)mali_sys_thread_key_get_data(4);
    }
    if (puVar1 != (undefined4 *)0x0) {
      if ((puVar1[1] == 1) && (*(int *)(puVar1[0x136] + 0x65a0) != 0)) {
        FUN_40980504(puVar1);
      }
      iVar2 = (**(code **)(puVar1[2] + 0x170))(puVar1,param_1,param_2,1);
      if (iVar2 != 0) {
        (**(code **)(puVar1[2] + 0x3b8))(puVar1,iVar2);
      }
    }
  }
  return;
}



/* 40992934 glFogx */

/* Boundary evidence: original MIPS .pdata 40992934..409929f3. Semantic name remains unreviewed. */

void glFogx(undefined4 param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 local_res4 [3];
  
                    /* 0x32934  61  glFogx */
  if (DAT_40996364 != 0) {
    local_res4[0] = param_2;
    if (*(int *)(DAT_40996364 + 8) == 0) {
      puVar1 = *(undefined4 **)(DAT_40996364 + 0xc);
    }
    else {
      puVar1 = (undefined4 *)mali_sys_thread_key_get_data(4);
    }
    if (puVar1 != (undefined4 *)0x0) {
      if ((puVar1[1] == 1) && (*(int *)(puVar1[0x136] + 0x65a0) != 0)) {
        FUN_40980504(puVar1);
      }
      iVar2 = (**(code **)(puVar1[2] + 0x16c))(puVar1,param_1,local_res4,1);
      if (iVar2 != 0) {
        (**(code **)(puVar1[2] + 0x3b8))(puVar1,iVar2);
      }
    }
  }
  return;
}



/* 409929f4 glFogfv */

/* Boundary evidence: original MIPS .pdata 409929f4..40992abb. Semantic name remains unreviewed. */

void glFogfv(undefined4 param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  int iVar2;
  
                    /* 0x329f4  60  glFogfv */
  if (DAT_40996364 != 0) {
    if (*(int *)(DAT_40996364 + 8) == 0) {
      puVar1 = *(undefined4 **)(DAT_40996364 + 0xc);
    }
    else {
      puVar1 = (undefined4 *)mali_sys_thread_key_get_data(4);
    }
    if (puVar1 != (undefined4 *)0x0) {
      if ((puVar1[1] == 1) && (*(int *)(puVar1[0x136] + 0x65a0) != 0)) {
        FUN_40980504(puVar1);
      }
      iVar2 = (**(code **)(puVar1[2] + 0x168))(puVar1,param_1,param_2,0);
      if (iVar2 != 0) {
        (**(code **)(puVar1[2] + 0x3b8))(puVar1,iVar2);
      }
    }
  }
  return;
}



/* 40992abc glFogf */

/* Boundary evidence: original MIPS .pdata 40992abc..40992b7b. Semantic name remains unreviewed. */

void glFogf(undefined4 param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 local_res4 [3];
  
                    /* 0x32abc  59  glFogf */
  if (DAT_40996364 != 0) {
    local_res4[0] = param_2;
    if (*(int *)(DAT_40996364 + 8) == 0) {
      puVar1 = *(undefined4 **)(DAT_40996364 + 0xc);
    }
    else {
      puVar1 = (undefined4 *)mali_sys_thread_key_get_data(4);
    }
    if (puVar1 != (undefined4 *)0x0) {
      if ((puVar1[1] == 1) && (*(int *)(puVar1[0x136] + 0x65a0) != 0)) {
        FUN_40980504(puVar1);
      }
      iVar2 = (**(code **)(puVar1[2] + 0x164))(puVar1,param_1,local_res4,0);
      if (iVar2 != 0) {
        (**(code **)(puVar1[2] + 0x3b8))(puVar1,iVar2);
      }
    }
  }
  return;
}



/* 40992b7c glDepthRangex */

/* Boundary evidence: original MIPS .pdata 40992b7c..40992c3f. Semantic name remains unreviewed. */

void glDepthRangex(uint param_1,uint param_2)

{
  undefined4 *puVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  
                    /* 0x32b7c  48  glDepthRangex */
  if (DAT_40996364 != 0) {
    if (*(int *)(DAT_40996364 + 8) == 0) {
      puVar1 = *(undefined4 **)(DAT_40996364 + 0xc);
    }
    else {
      puVar1 = (undefined4 *)mali_sys_thread_key_get_data(4);
    }
    if (puVar1 != (undefined4 *)0x0) {
      if ((puVar1[1] == 1) && (*(int *)(puVar1[0x136] + 0x65a0) != 0)) {
        FUN_40980504(puVar1);
      }
      iVar4 = puVar1[2];
      uVar2 = FUN_4098fbdc(param_2);
      uVar3 = FUN_4098fbdc(param_1);
      (**(code **)(iVar4 + 0x158))(puVar1,uVar3,uVar2);
    }
  }
  return;
}



/* 40992c40 glClipPlanex */

/* Boundary evidence: original MIPS .pdata 40992c40..40992d0b. Semantic name remains unreviewed. */

void glClipPlanex(undefined4 param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  int iVar2;
  
                    /* 0x32c40  31  glClipPlanex */
  if (DAT_40996364 != 0) {
    if (*(int *)(DAT_40996364 + 8) == 0) {
      puVar1 = *(undefined4 **)(DAT_40996364 + 0xc);
    }
    else {
      puVar1 = (undefined4 *)mali_sys_thread_key_get_data(4);
    }
    if (puVar1 != (undefined4 *)0x0) {
      if ((puVar1[1] == 1) && (*(int *)(puVar1[0x136] + 0x65a0) != 0)) {
        FUN_40980504(puVar1);
      }
      iVar2 = (**(code **)(puVar1[2] + 0x144))(puVar1[0x136] + 0x9c,param_1,param_2,1);
      if (iVar2 != 0) {
        (**(code **)(puVar1[2] + 0x3b8))(puVar1,iVar2);
      }
    }
  }
  return;
}



/* 40992d0c glClipPlanef */

/* Boundary evidence: original MIPS .pdata 40992d0c..40992dd7. Semantic name remains unreviewed. */

void glClipPlanef(undefined4 param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  int iVar2;
  
                    /* 0x32d0c  30  glClipPlanef */
  if (DAT_40996364 != 0) {
    if (*(int *)(DAT_40996364 + 8) == 0) {
      puVar1 = *(undefined4 **)(DAT_40996364 + 0xc);
    }
    else {
      puVar1 = (undefined4 *)mali_sys_thread_key_get_data(4);
    }
    if (puVar1 != (undefined4 *)0x0) {
      if ((puVar1[1] == 1) && (*(int *)(puVar1[0x136] + 0x65a0) != 0)) {
        FUN_40980504(puVar1);
      }
      iVar2 = (**(code **)(puVar1[2] + 0x140))(puVar1[0x136] + 0x9c,param_1,param_2,0);
      if (iVar2 != 0) {
        (**(code **)(puVar1[2] + 0x3b8))(puVar1,iVar2);
      }
    }
  }
  return;
}



/* 40992dd8 glClearDepthx */

/* Boundary evidence: original MIPS .pdata 40992dd8..40992e7f. Semantic name remains unreviewed. */

void glClearDepthx(uint param_1)

{
  undefined4 *puVar1;
  uint uVar2;
  int iVar3;
  
                    /* 0x32dd8  27  glClearDepthx */
  if (DAT_40996364 != 0) {
    if (*(int *)(DAT_40996364 + 8) == 0) {
      puVar1 = *(undefined4 **)(DAT_40996364 + 0xc);
    }
    else {
      puVar1 = (undefined4 *)mali_sys_thread_key_get_data(4);
    }
    if (puVar1 != (undefined4 *)0x0) {
      if ((puVar1[1] == 1) && (*(int *)(puVar1[0x136] + 0x65a0) != 0)) {
        FUN_40980504(puVar1);
      }
      iVar3 = puVar1[2];
      uVar2 = FUN_4098fbdc(param_1);
      (**(code **)(iVar3 + 0x138))(puVar1 + 0x115,uVar2);
    }
  }
  return;
}



/* 40992e80 glClearColorx */

/* Boundary evidence: original MIPS .pdata 40992e80..40992f83. Semantic name remains unreviewed. */

void glClearColorx(uint param_1,uint param_2,uint param_3,uint param_4)

{
  undefined4 *puVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  
                    /* 0x32e80  25  glClearColorx */
  if (DAT_40996364 != 0) {
    if (*(int *)(DAT_40996364 + 8) == 0) {
      puVar1 = *(undefined4 **)(DAT_40996364 + 0xc);
    }
    else {
      puVar1 = (undefined4 *)mali_sys_thread_key_get_data(4);
    }
    if (puVar1 != (undefined4 *)0x0) {
      if ((puVar1[1] == 1) && (*(int *)(puVar1[0x136] + 0x65a0) != 0)) {
        FUN_40980504(puVar1);
      }
      iVar6 = puVar1[2];
      uVar2 = FUN_4098fbdc(param_4);
      uVar3 = FUN_4098fbdc(param_3);
      uVar4 = FUN_4098fbdc(param_2);
      uVar5 = FUN_4098fbdc(param_1);
      (**(code **)(iVar6 + 0x134))(puVar1 + 0x115,uVar5,uVar4,uVar3,uVar2);
    }
  }
  return;
}



/* 40992f84 glAlphaFuncx */

/* Boundary evidence: original MIPS .pdata 40992f84..40993057. Semantic name remains unreviewed. */

void glAlphaFuncx(undefined4 param_1,uint param_2)

{
  undefined4 *puVar1;
  uint uVar2;
  int iVar3;
  
                    /* 0x32f84  17  glAlphaFuncx */
  if (DAT_40996364 != 0) {
    if (*(int *)(DAT_40996364 + 8) == 0) {
      puVar1 = *(undefined4 **)(DAT_40996364 + 0xc);
    }
    else {
      puVar1 = (undefined4 *)mali_sys_thread_key_get_data(4);
    }
    if (puVar1 != (undefined4 *)0x0) {
      if ((puVar1[1] == 1) && (*(int *)(puVar1[0x136] + 0x65a0) != 0)) {
        FUN_40980504(puVar1);
      }
      iVar3 = puVar1[2];
      uVar2 = FUN_4098fbdc(param_2);
      iVar3 = (**(code **)(iVar3 + 0x130))(puVar1,param_1,uVar2);
      if (iVar3 != 0) {
        (**(code **)(puVar1[2] + 0x3b8))(puVar1,iVar3);
      }
    }
  }
  return;
}



/* 40993058 glAlphaFunc */

/* Boundary evidence: original MIPS .pdata 40993058..4099311b. Semantic name remains unreviewed. */

void glAlphaFunc(undefined4 param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  int iVar2;
  
                    /* 0x33058  16  glAlphaFunc */
  if (DAT_40996364 != 0) {
    if (*(int *)(DAT_40996364 + 8) == 0) {
      puVar1 = *(undefined4 **)(DAT_40996364 + 0xc);
    }
    else {
      puVar1 = (undefined4 *)mali_sys_thread_key_get_data(4);
    }
    if (puVar1 != (undefined4 *)0x0) {
      if ((puVar1[1] == 1) && (*(int *)(puVar1[0x136] + 0x65a0) != 0)) {
        FUN_40980504(puVar1);
      }
      iVar2 = (**(code **)(puVar1[2] + 300))(puVar1,param_1,param_2);
      if (iVar2 != 0) {
        (**(code **)(puVar1[2] + 0x3b8))(puVar1,iVar2);
      }
    }
  }
  return;
}



/* 4099311c FUN_4099311c */

/* Boundary evidence: original MIPS .pdata 4099311c..409931b3. Semantic name remains unreviewed. */

undefined4 FUN_4099311c(int param_1,int param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int *piVar4;
  
  piVar4 = *(int **)(param_1 + 0x500);
  iVar1 = FUN_40974b50(*(undefined4 **)(param_1 + 0x510),param_2 << 4,piVar4);
  if ((iVar1 == 0) ||
     (iVar1 = FUN_40974b50(*(undefined4 **)(param_1 + 0x510),param_2 * param_3,piVar4 + 1),
     iVar1 == 0)) {
    uVar2 = 0xffffffff;
  }
  else {
    iVar3 = piVar4[2];
    uVar2 = 0;
    iVar1 = *(int *)(param_1 + 0x4fc);
    *(int *)(iVar1 + 0x48) = *piVar4;
    *(int *)(iVar1 + 0x44) = iVar3;
  }
  return uVar2;
}



/* 409931b4 FUN_409931b4 */

/* Boundary evidence: original MIPS .pdata 409931b4..4099322f. Semantic name remains unreviewed. */

void FUN_409931b4(undefined4 *param_1,undefined4 param_2)

{
  int iVar1;
  uint uVar2;
  
  FUN_40993370();
  uVar2 = 7;
  if (1 < (int)param_1[299]) {
    uVar2 = 0xf;
  }
  iVar1 = mali_frame_builder_get_supersample_factor(param_2);
  if (iVar1 != 0) {
    uVar2 = uVar2 | 0x10;
  }
  mali_incremental_render(param_2,uVar2);
  iVar1 = FUN_40978694(param_1);
  if (iVar1 == 0) {
    FUN_40974c48((undefined4 *)param_1[0x144]);
  }
                    /* WARNING: Subroutine does not return */
  FUN_40993390(0x10);
}



/* 40993230 FUN_40993230 */

/* Boundary evidence: original MIPS .pdata 40993230..40993257. Semantic name remains unreviewed. */

void FUN_40993230(void)

{
  return;
}



/* 40993258 FUN_40993258 */

/* Boundary evidence: original MIPS .pdata 40993258..4099327f. Semantic name remains unreviewed. */

void FUN_40993258(int param_1)

{
                    /* WARNING: Could not recover jumptable at 0x40993278. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(&stack0x00000014 + param_1))();
  return;
}



/* 40993280 FUN_40993280 */

/* Boundary evidence: original MIPS .pdata 40993280..409932d3. Semantic name remains unreviewed. */

void FUN_40993280(int param_1,undefined4 param_2,uint *param_3)

{
  if ((*param_3 & 1) != 0) {
    param_1 = ((-param_3[2] & param_3[1] + param_1) - (param_3[1] + param_1)) + param_1;
  }
  FUN_40963898(*(uint *)(param_1 + (*param_3 & 0xfffffffc)));
  return;
}



/* 409932d4 FUN_409932d4 */

/* Boundary evidence: original MIPS .pdata 409932d4..409932ff. Semantic name remains unreviewed. */

undefined4 FUN_409932d4(undefined4 param_1,int param_2,undefined4 param_3,int param_4)

{
  FUN_40993280(param_2,param_4,*(uint **)(*(int *)(param_4 + 4) + 0xc));
  return 1;
}



/* 40993300 FUN_40993300 */

/* Boundary evidence: original MIPS .pdata 40993300..40993337. Semantic name remains unreviewed. */

void FUN_40993300(void)

{
  return;
}



/* 40993338 FUN_40993338 */

/* Boundary evidence: original MIPS .pdata 40993338..4099336f. Semantic name remains unreviewed. */

void FUN_40993338(int param_1)

{
                    /* WARNING: Could not recover jumptable at 0x40993368. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(&stack0x00000024 + param_1))();
  return;
}



/* 40993370 FUN_40993370 */

/* Boundary evidence: original MIPS .pdata 40993370..4099338f. Semantic name remains unreviewed. */

void FUN_40993370(void)

{
  return;
}



/* 40993390 FUN_40993390 */

/* Boundary evidence: original MIPS .pdata 40993390..409933af. Semantic name remains unreviewed. */

void FUN_40993390(int param_1)

{
  undefined4 uStackX_c;
  
                    /* WARNING: Could not recover jumptable at 0x409933a8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)((int)&uStackX_c + param_1))();
  return;
}



/* 409933b0 FUN_409933b0 */

/* Boundary evidence: original MIPS .pdata 409933b0..409933df. Semantic name remains unreviewed. */

void FUN_409933b0(void)

{
  return;
}



/* 409933e0 FUN_409933e0 */

/* Boundary evidence: original MIPS .pdata 409933e0..4099340f. Semantic name remains unreviewed. */

void FUN_409933e0(int param_1)

{
                    /* WARNING: Could not recover jumptable at 0x40993408. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(&stack0x0000001c + param_1))();
  return;
}


