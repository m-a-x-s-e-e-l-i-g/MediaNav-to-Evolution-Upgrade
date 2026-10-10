/* Automatic Ghidra pseudocode. Not original source; not runtime-verified. */

/* 40a7112c FUN_40a7112c */

/* Boundary evidence: original MIPS .pdata 40a7112c..40a71157. Semantic name remains unreviewed. */

undefined4 FUN_40a7112c(HMODULE param_1,int param_2)

{
  if (param_2 == 1) {
    DisableThreadLibraryCalls(param_1);
  }
  return 1;
}



/* 40a71158 FUN_40a71158 */

/* Boundary evidence: original MIPS .pdata 40a71158..40a71293. Semantic name remains unreviewed. */

int FUN_40a71158(HMODULE param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 1;
  if (param_2 == 1) {
    if (DAT_40a7409c != (code *)0x0) {
      iVar2 = (*DAT_40a7409c)(param_1,1,param_3);
    }
    iVar1 = 0;
    if (iVar2 == 0) goto LAB_40a71208;
    FUN_40a714c4();
  }
  iVar1 = 0;
  if (iVar2 != 0) {
    iVar1 = FUN_40a7112c(param_1,param_2);
  }
LAB_40a71208:
  if (((param_2 == 0) && (FUN_40a7144c(), iVar1 != 0)) && (DAT_40a7409c != (code *)0x0)) {
    iVar1 = (*DAT_40a7409c)(param_1,0,param_3);
  }
  return iVar1;
}



/* 40a71294 FUN_40a71294 */

/* Boundary evidence: original MIPS .pdata 40a71294..40a712bf. Semantic name remains unreviewed. */

void FUN_40a71294(_EXCEPTION_POINTERS *param_1)

{
  _XcptFilter(param_1->ExceptionRecord->ExceptionCode,param_1);
  return;
}



/* 40a712c0 entry */

/* Boundary evidence: original MIPS .pdata 40a712c0..40a71317. Semantic name remains unreviewed. */

void entry(HMODULE param_1,int param_2,undefined4 param_3)

{
  if (param_2 == 1) {
    FUN_40a71500();
  }
  FUN_40a71158(param_1,param_2,param_3);
  return;
}



/* 40a71318 FUN_40a71318 */

/* Boundary evidence: original MIPS .pdata 40a71318..40a7135f. Semantic name remains unreviewed. */

void FUN_40a71318(uint param_1)

{
  if ((param_1 == DAT_40a74088) && (param_1 >> 0x10 == 0)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __report_gsfailure();
}



/* 40a71360 FUN_40a71360 */

/* Boundary evidence: original MIPS .pdata 40a71360..40a7144b. Semantic name remains unreviewed. */

void FUN_40a71360(UINT param_1,int param_2,int param_3)

{
  undefined4 *_Memory;
  
  DAT_40a74090 = (undefined1)param_3;
  if (param_2 == 0) {
    _Memory = DAT_40a74098;
    if (DAT_40a74098 != (undefined4 *)0x0) {
      while (DAT_40a74094 = DAT_40a74094 + -1, _Memory <= DAT_40a74094) {
        if ((code *)*DAT_40a74094 != (code *)0x0) {
          (*(code *)*DAT_40a74094)();
          _Memory = DAT_40a74098;
        }
      }
      free(_Memory);
      DAT_40a74094 = (undefined4 *)0x0;
      DAT_40a74098 = (undefined4 *)0x0;
    }
    FUN_40a71470((undefined4 *)&DAT_40a71010,(undefined4 *)&DAT_40a71014);
  }
  FUN_40a71470((undefined4 *)&DAT_40a71018,(undefined4 *)&DAT_40a7101c);
  if (param_3 == 0) {
    TerminateProcess((HANDLE)0x42,param_1);
  }
  return;
}



/* 40a7144c FUN_40a7144c */

/* Boundary evidence: original MIPS .pdata 40a7144c..40a7146f. Semantic name remains unreviewed. */

void FUN_40a7144c(void)

{
  FUN_40a71360(0,0,1);
  return;
}



/* 40a71470 FUN_40a71470 */

/* Boundary evidence: original MIPS .pdata 40a71470..40a714c3. Semantic name remains unreviewed. */

void FUN_40a71470(undefined4 *param_1,undefined4 *param_2)

{
  for (; param_1 < param_2; param_1 = param_1 + 1) {
    if ((code *)*param_1 != (code *)0x0) {
      (*(code *)*param_1)();
    }
  }
  return;
}



/* 40a714c4 FUN_40a714c4 */

/* Boundary evidence: original MIPS .pdata 40a714c4..40a714ff. Semantic name remains unreviewed. */

void FUN_40a714c4(void)

{
  FUN_40a71470((undefined4 *)&DAT_40a71008,(undefined4 *)&DAT_40a7100c);
  FUN_40a71470((undefined4 *)&DAT_40a71000,(undefined4 *)&DAT_40a71004);
  return;
}



/* 40a71500 FUN_40a71500 */

/* Boundary evidence: original MIPS .pdata 40a71500..40a71573. Semantic name remains unreviewed. */

void FUN_40a71500(void)

{
  uint uVar1;
  
  if ((DAT_40a74088 == 0) || (DAT_40a74088 == 0xb064)) {
    uVar1 = __security_gen_cookie2();
    DAT_40a74088 = uVar1 >> 0x10 ^ uVar1 & 0xffff;
    if (DAT_40a74088 == 0) {
      DAT_40a74088 = 0xb064;
    }
  }
  DAT_40a7408c = ~DAT_40a74088;
  return;
}



/* 40a715e4 __vgu_build_info */

char * __vgu_build_info(void)

{
                    /* 0x15e4  1  __vgu_build_info */
  return "vgu:  ";
}



/* 40a715f0 FUN_40a715f0 */

/* Boundary evidence: original MIPS .pdata 40a715f0..40a717bb. Semantic name remains unreviewed. */

void FUN_40a715f0(undefined4 *param_1,undefined4 *param_2,int param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  int iVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  undefined4 uVar13;
  undefined4 *puVar14;
  int iVar15;
  undefined4 uVar16;
  undefined4 uVar17;
  
  uVar4 = param_2[7];
  puVar14 = (undefined4 *)(param_3 + 8);
  iVar15 = 3;
  uVar5 = param_2[4];
  uVar6 = param_2[1];
  uVar7 = param_2[8];
  uVar8 = param_2[5];
  uVar9 = param_2[2];
  uVar3 = *param_2;
  iVar10 = (int)param_1 - param_3;
  uVar16 = param_2[6];
  uVar17 = param_2[3];
  do {
    uVar11 = puVar14[-2];
    uVar12 = puVar14[-1];
    uVar13 = *puVar14;
    uVar1 = __fpmul(uVar3,uVar11);
    uVar2 = __fpmul(uVar17,uVar12);
    uVar1 = __fpadd(uVar1,uVar2);
    uVar2 = __fpmul(uVar16,uVar13);
    uVar1 = __fpadd(uVar1,uVar2);
    *param_1 = uVar1;
    uVar1 = __fpmul(uVar6,uVar11);
    uVar2 = __fpmul(uVar5,uVar12);
    uVar1 = __fpadd(uVar1,uVar2);
    uVar2 = __fpmul(uVar4,uVar13);
    uVar1 = __fpadd(uVar1,uVar2);
    param_1[1] = uVar1;
    uVar1 = __fpmul(uVar9,uVar11);
    uVar2 = __fpmul(uVar8,uVar12);
    uVar1 = __fpadd(uVar1,uVar2);
    uVar2 = __fpmul(uVar7,uVar13);
    uVar1 = __fpadd(uVar1,uVar2);
    iVar15 = iVar15 + -1;
    param_1 = param_1 + 3;
    *(undefined4 *)(iVar10 + (int)puVar14) = uVar1;
    puVar14 = puVar14 + 3;
  } while (iVar15 != 0);
  return;
}



/* 40a717bc FUN_40a717bc */

/* Boundary evidence: original MIPS .pdata 40a717bc..40a71ad3. Semantic name remains unreviewed. */

undefined4 FUN_40a717bc(undefined4 *param_1,undefined4 *param_2)

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
  
  uVar8 = param_2[8];
  uVar9 = param_2[4];
  uVar5 = param_2[7];
  uVar7 = param_2[5];
  uVar1 = __fpmul(uVar9,uVar8);
  uVar2 = __fpmul(uVar7,uVar5);
  uVar1 = __fpsub(uVar1,uVar2);
  uVar6 = param_2[2];
  uVar4 = param_2[1];
  uVar2 = __fpmul(uVar6,uVar5);
  uVar5 = __fpmul(uVar4,uVar8);
  uVar2 = __fpsub(uVar2,uVar5);
  uVar5 = __fpmul(uVar4,uVar7);
  uVar4 = __fpmul(uVar6,uVar9);
  uVar5 = __fpsub(uVar5,uVar4);
  uVar4 = __fpmul(param_2[6],uVar5);
  uVar6 = __fpmul(param_2[3],uVar2);
  uVar4 = __fpadd(uVar4,uVar6);
  uVar6 = __fpmul(*param_2,uVar1);
  uVar4 = __fpadd(uVar4,uVar6);
  iVar3 = __lts(uVar4,0x2b8cbccc);
  if ((iVar3 == 0) || (iVar3 = __gts(uVar4,0xab8cbccc), iVar3 == 0)) {
    uVar4 = __fpdiv(0x3f800000,uVar4);
    uVar1 = __fpmul(uVar4,uVar1);
    *param_1 = uVar1;
    uVar1 = __fpmul(uVar4,uVar2);
    param_1[1] = uVar1;
    uVar1 = __fpmul(uVar4,uVar5);
    param_1[2] = uVar1;
    uVar1 = __fpmul(param_2[6],param_2[5]);
    uVar2 = __fpmul(param_2[3],param_2[8]);
    uVar1 = __fpsub(uVar1,uVar2);
    uVar1 = __fpmul(uVar1,uVar4);
    param_1[3] = uVar1;
    uVar1 = __fpmul(*param_2,param_2[8]);
    uVar2 = __fpmul(param_2[6],param_2[2]);
    uVar1 = __fpsub(uVar1,uVar2);
    uVar1 = __fpmul(uVar1,uVar4);
    param_1[4] = uVar1;
    uVar1 = __fpmul(param_2[3],param_2[2]);
    uVar2 = __fpmul(*param_2,param_2[5]);
    uVar1 = __fpsub(uVar1,uVar2);
    uVar1 = __fpmul(uVar1,uVar4);
    param_1[5] = uVar1;
    uVar1 = __fpmul(param_2[7],param_2[3]);
    uVar2 = __fpmul(param_2[6],param_2[4]);
    uVar1 = __fpsub(uVar1,uVar2);
    uVar1 = __fpmul(uVar1,uVar4);
    param_1[6] = uVar1;
    uVar1 = __fpmul(param_2[6],param_2[1]);
    uVar2 = __fpmul(param_2[7],*param_2);
    uVar1 = __fpsub(uVar1,uVar2);
    uVar1 = __fpmul(uVar1,uVar4);
    param_1[7] = uVar1;
    uVar1 = __fpmul(param_2[4],*param_2);
    uVar2 = __fpmul(param_2[3],param_2[1]);
    uVar1 = __fpsub(uVar1,uVar2);
    uVar1 = __fpmul(uVar1,uVar4);
    param_1[8] = uVar1;
    uVar1 = 1;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}



/* 40a71aec vguComputeWarpSquareToQuad */

/* Boundary evidence: original MIPS .pdata 40a71aec..40a71e9b. Semantic name remains unreviewed. */

undefined4
vguComputeWarpSquareToQuad
          (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
          undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
          undefined4 *param_9)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  int iVar7;
  undefined4 uVar8;
  
                    /* 0x1aec  5  vguComputeWarpSquareToQuad */
  if ((param_9 == (undefined4 *)0x0) || (((uint)param_9 & 3) != 0)) {
    uVar1 = 0xf001;
  }
  else {
    uVar1 = __fpsub(param_3,param_7);
    uVar2 = __fpsub(param_4,param_8);
    uVar3 = __fpsub(param_5,param_7);
    uVar4 = __fpsub(param_6,param_8);
    uVar5 = __fpmul(uVar4,uVar1);
    uVar6 = __fpmul(uVar3,uVar2);
    uVar5 = __fpsub(uVar5,uVar6);
    iVar7 = __lts(uVar5,0x2b8cbccc);
    if ((iVar7 == 0) || (iVar7 = __gts(uVar5,0xab8cbccc), iVar7 == 0)) {
      uVar6 = __fpsub(param_1,param_3);
      uVar6 = __fpadd(uVar6,param_7);
      uVar6 = __fpsub(uVar6,param_5);
      uVar8 = __fpsub(param_2,param_4);
      uVar8 = __fpadd(uVar8,param_8);
      uVar8 = __fpsub(uVar8,param_6);
      iVar7 = __lts(uVar6,0x2b8cbccc);
      if ((iVar7 == 0) ||
         (((iVar7 = __gts(uVar6,0xab8cbccc), iVar7 == 0 ||
           (iVar7 = __lts(uVar8,0x2b8cbccc), iVar7 == 0)) ||
          (iVar7 = __gts(uVar8,0xab8cbccc), iVar7 == 0)))) {
        uVar5 = __fpdiv(0x3f800000,uVar5);
        uVar4 = __fpmul(uVar6,uVar4);
        uVar3 = __fpmul(uVar8,uVar3);
        uVar3 = __fpsub(uVar4,uVar3);
        uVar3 = __fpmul(uVar3,uVar5);
        uVar1 = __fpmul(uVar8,uVar1);
        uVar2 = __fpmul(uVar6,uVar2);
        uVar1 = __fpsub(uVar1,uVar2);
        uVar1 = __fpmul(uVar1,uVar5);
        uVar2 = __fpmul(uVar3,param_3);
        uVar4 = __fpsub(param_3,param_1);
        uVar2 = __fpadd(uVar2,uVar4);
        *param_9 = uVar2;
        uVar2 = __fpmul(uVar3,param_4);
        uVar4 = __fpsub(param_4,param_2);
        uVar2 = __fpadd(uVar2,uVar4);
        param_9[2] = uVar3;
        param_9[1] = uVar2;
        uVar2 = __fpmul(uVar1,param_5);
        uVar3 = __fpsub(param_5,param_1);
        uVar2 = __fpadd(uVar2,uVar3);
        param_9[3] = uVar2;
        uVar2 = __fpmul(uVar1,param_6);
        uVar3 = __fpsub(param_6,param_2);
        uVar2 = __fpadd(uVar2,uVar3);
        param_9[5] = uVar1;
      }
      else {
        uVar1 = __fpsub(param_3,param_1);
        *param_9 = uVar1;
        uVar1 = __fpsub(param_4,param_2);
        param_9[1] = uVar1;
        param_9[2] = 0;
        uVar1 = __fpsub(param_7,param_3);
        param_9[3] = uVar1;
        uVar2 = __fpsub(param_8,param_4);
        param_9[5] = 0;
      }
      param_9[4] = uVar2;
      uVar1 = 0;
      param_9[8] = 0x3f800000;
      param_9[7] = param_2;
      param_9[6] = param_1;
    }
    else {
      uVar1 = 0xf004;
    }
  }
  return uVar1;
}



/* 40a71e9c vguComputeWarpQuadToSquare */

/* Boundary evidence: original MIPS .pdata 40a71e9c..40a71f53. Semantic name remains unreviewed. */

int vguComputeWarpQuadToSquare
              (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
              undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
              undefined4 *param_9)

{
  int iVar1;
  undefined4 auStack_30 [10];
  
                    /* 0x1e9c  4  vguComputeWarpQuadToSquare */
  if ((param_9 == (undefined4 *)0x0) || (((uint)param_9 & 3) != 0)) {
    iVar1 = 0xf001;
  }
  else {
    iVar1 = vguComputeWarpSquareToQuad
                      (param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,auStack_30);
    if (iVar1 == 0) {
      iVar1 = FUN_40a717bc(param_9,auStack_30);
      if (iVar1 == 0) {
        mali_sys_memcpy(param_9,auStack_30,0x24);
        return 0xf004;
      }
      return 0;
    }
  }
  return iVar1;
}



/* 40a71f54 vguComputeWarpQuadToQuad */

/* Boundary evidence: original MIPS .pdata 40a71f54..40a72057. Semantic name remains unreviewed. */

int vguComputeWarpQuadToQuad
              (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
              undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
              undefined4 param_9,undefined4 param_10,undefined4 param_11,undefined4 param_12,
              undefined4 param_13,undefined4 param_14,undefined4 param_15,undefined4 param_16,
              undefined4 *param_17)

{
  int iVar1;
  undefined4 auStack_68 [10];
  undefined4 auStack_40 [10];
  
                    /* 0x1f54  3  vguComputeWarpQuadToQuad */
  if ((param_17 == (undefined4 *)0x0) || (((uint)param_17 & 3) != 0)) {
    iVar1 = 0xf001;
  }
  else {
    iVar1 = vguComputeWarpQuadToSquare
                      (param_9,param_10,param_11,param_12,param_13,param_14,param_15,param_16,
                       auStack_68);
    if (iVar1 == 0) {
      iVar1 = vguComputeWarpSquareToQuad
                        (param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,auStack_40)
      ;
      if (iVar1 == 0) {
        FUN_40a715f0(param_17,auStack_40,(int)auStack_68);
        iVar1 = 0;
      }
    }
  }
  return iVar1;
}



/* 40a72058 FUN_40a72058 */

/* Boundary evidence: original MIPS .pdata 40a72058..40a72363. Semantic name remains unreviewed. */

undefined4
FUN_40a72058(undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4,
            undefined4 *param_5)

{
  undefined1 uVar1;
  undefined2 uVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  undefined4 *puVar7;
  undefined4 uVar8;
  undefined1 *puVar9;
  undefined4 *puVar10;
  
  uVar3 = vgGetParameterf(param_1,0x1603);
  iVar4 = vgGetParameteri(param_1,0x1601);
  uVar5 = vgGetParameterf(param_1,0x1602);
  iVar6 = vgGetError();
  if (iVar6 == 0x1000) {
    return 0xf000;
  }
  iVar6 = __eqs(0,uVar5);
  if (iVar6 != 0) {
    return 0xf001;
  }
  if (iVar4 == 0) {
    puVar7 = (undefined4 *)mali_sys_malloc(param_4);
    if (puVar7 == (undefined4 *)0x0) {
      return 0xf002;
    }
    iVar4 = 0;
    if (0 < param_4) {
      uVar5 = __fpdiv(0x3f800000,uVar5);
      do {
        uVar8 = __fpsub(*param_5,uVar3);
        uVar8 = __fpmul(uVar8,uVar5);
        uVar8 = __fpadd(uVar8,0x3f000000);
        uVar8 = mali_sys_floor(uVar8);
        uVar1 = __fptoli(uVar8);
        puVar9 = (undefined1 *)(iVar4 + (int)puVar7);
        iVar4 = iVar4 + 1;
        *puVar9 = uVar1;
        param_5 = param_5 + 1;
      } while (iVar4 < param_4);
    }
  }
  else if (iVar4 == 1) {
    puVar7 = (undefined4 *)mali_sys_malloc(param_4 << 1);
    if (puVar7 == (undefined4 *)0x0) {
      return 0xf002;
    }
    if (0 < param_4) {
      uVar5 = __fpdiv(0x3f800000,uVar5);
      puVar10 = puVar7;
      do {
        uVar8 = __fpsub(*param_5,uVar3);
        uVar8 = __fpmul(uVar8,uVar5);
        uVar8 = __fpadd(uVar8,0x3f000000);
        uVar8 = mali_sys_floor(uVar8);
        uVar2 = __fptoli(uVar8);
        param_4 = param_4 + -1;
        *(undefined2 *)puVar10 = uVar2;
        puVar10 = (undefined4 *)((int)puVar10 + 2);
        param_5 = param_5 + 1;
      } while (param_4 != 0);
    }
  }
  else {
    if (iVar4 != 2) {
      vgAppendPathData(param_1,param_2,param_3,param_5);
      goto LAB_40a7230c;
    }
    puVar7 = (undefined4 *)mali_sys_malloc(param_4 << 2);
    if (puVar7 == (undefined4 *)0x0) {
      return 0xf002;
    }
    if (0 < param_4) {
      uVar5 = __fpdiv(0x3f800000,uVar5);
      puVar10 = puVar7;
      do {
        uVar8 = __fpsub(*(undefined4 *)(((int)param_5 - (int)puVar7) + (int)puVar10),uVar3);
        uVar8 = __fpmul(uVar8,uVar5);
        uVar8 = __fpadd(uVar8,0x3f000000);
        uVar8 = mali_sys_floor(uVar8);
        uVar8 = __fptoli(uVar8);
        param_4 = param_4 + -1;
        *puVar10 = uVar8;
        puVar10 = puVar10 + 1;
      } while (param_4 != 0);
    }
  }
  vgAppendPathData(param_1,param_2,param_3,puVar7);
  mali_sys_free(puVar7);
LAB_40a7230c:
  iVar4 = vgGetError();
  if (iVar4 == 0x1000) {
    return 0xf000;
  }
  if (iVar4 != 0x1003) {
    return 0;
  }
  return 0xf003;
}



/* 40a7237c vguArc */

/* Boundary evidence: original MIPS .pdata 40a7237c..40a72a87. Semantic name remains unreviewed. */

undefined4
vguArc(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
      undefined4 param_5,undefined4 param_6,undefined4 param_7,int param_8)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  undefined1 *puVar4;
  undefined4 *puVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined1 *puVar10;
  undefined1 uVar11;
  undefined4 *puVar12;
  int iVar13;
  undefined8 uVar14;
  int local_50;
  int local_44;
  undefined4 local_3c;
  
                    /* 0x237c  2  vguArc */
  iVar1 = __les(param_4,0);
  if (((iVar1 != 0) || (iVar1 = __les(param_5,0), iVar1 != 0)) ||
     ((param_8 != 0xf100 && ((param_8 != 0xf101 && (param_8 != 0xf102)))))) {
    return 0xf001;
  }
  iVar1 = 2;
  local_44 = 2;
  if (param_8 == 0xf102) {
    iVar13 = 3;
    iVar1 = 4;
  }
  else {
    iVar13 = 2;
  }
  uVar2 = mali_sys_fabs(param_7);
  uVar2 = __fpmul(uVar2,0x3bb60b61);
  uVar2 = mali_sys_ceil(uVar2);
  uVar2 = __fpadd(uVar2,0x3f800000);
  iVar3 = __fptoli(uVar2);
  puVar4 = (undefined1 *)mali_sys_malloc(iVar3 + iVar13);
  if (puVar4 == (undefined1 *)0x0) {
    return 0xf002;
  }
  puVar5 = (undefined4 *)mali_sys_malloc((iVar3 * 5 + iVar1) * 4);
  if (puVar5 == (undefined4 *)0x0) {
    mali_sys_free(puVar4);
    return 0xf002;
  }
  iVar13 = 2;
  *puVar4 = 2;
  local_50 = 1;
  uVar14 = __fptodp(param_6);
  uVar14 = __dpmul((int)uVar14,(int)((ulonglong)uVar14 >> 0x20),0xa2529d39,0x3f91df46);
  uVar2 = __dptofp((int)uVar14,(int)((ulonglong)uVar14 >> 0x20));
  uVar6 = mali_sys_cos(uVar2);
  uVar6 = __fpmul(uVar6,param_4);
  uVar6 = __fpmul(uVar6,0x3f000000);
  uVar6 = __fpadd(uVar6,param_2);
  *puVar5 = uVar6;
  uVar2 = mali_sys_sin(uVar2);
  uVar2 = __fpmul(uVar2,param_5);
  uVar2 = __fpmul(uVar2,0x3f000000);
  uVar2 = __fpadd(uVar2,param_3);
  puVar5[1] = uVar2;
  uVar2 = __fpadd(param_6,param_7);
  iVar1 = __gts(param_7,0);
  if (iVar1 == 0) {
    local_3c = __fpsub(param_6,0x43340000);
    iVar1 = __gts(local_3c,uVar2);
    if (iVar1 != 0) {
      uVar6 = __fpmul(param_4,0x3f000000);
      uVar7 = __fpmul(param_5,0x3f000000);
      puVar12 = puVar5 + 2;
      do {
        puVar10 = puVar4 + local_50;
        local_50 = local_50 + 1;
        *puVar10 = 0x14;
        *puVar12 = uVar6;
        puVar12[1] = uVar7;
        puVar12[2] = 0;
        uVar14 = __fptodp(local_3c);
        uVar14 = __dpmul((int)uVar14,(int)((ulonglong)uVar14 >> 0x20),0xa2529d39,0x3f91df46);
        uVar8 = __dptofp((int)uVar14,(int)((ulonglong)uVar14 >> 0x20));
        uVar9 = mali_sys_cos(uVar8);
        uVar9 = __fpmul(uVar9,param_4);
        uVar9 = __fpmul(uVar9,0x3f000000);
        uVar9 = __fpadd(uVar9,param_2);
        puVar12[3] = uVar9;
        uVar8 = mali_sys_sin(uVar8);
        uVar8 = __fpmul(uVar8,param_5);
        uVar8 = __fpmul(uVar8,0x3f000000);
        uVar8 = __fpadd(uVar8,param_3);
        puVar12[4] = uVar8;
        iVar13 = iVar13 + 5;
        puVar12 = puVar12 + 5;
        local_3c = __fpsub(local_3c,0x43340000);
        iVar1 = __gts(local_3c,uVar2);
        local_44 = iVar13;
      } while (iVar1 != 0);
    }
    uVar11 = 0x14;
  }
  else {
    local_3c = __fpadd();
    iVar1 = __lts(local_3c,uVar2);
    if (iVar1 != 0) {
      uVar6 = __fpmul(param_4,0x3f000000);
      uVar7 = __fpmul(param_5,0x3f000000);
      puVar12 = puVar5 + 2;
      do {
        puVar10 = puVar4 + local_50;
        local_50 = local_50 + 1;
        *puVar10 = 0x12;
        *puVar12 = uVar6;
        puVar12[1] = uVar7;
        puVar12[2] = 0;
        uVar14 = __fptodp(local_3c);
        uVar14 = __dpmul((int)uVar14,(int)((ulonglong)uVar14 >> 0x20),0xa2529d39,0x3f91df46);
        uVar8 = __dptofp((int)uVar14,(int)((ulonglong)uVar14 >> 0x20));
        uVar9 = mali_sys_cos(uVar8);
        uVar9 = __fpmul(uVar9,param_4);
        uVar9 = __fpmul(uVar9,0x3f000000);
        uVar9 = __fpadd(uVar9,param_2);
        puVar12[3] = uVar9;
        uVar8 = mali_sys_sin(uVar8);
        uVar8 = __fpmul(uVar8,param_5);
        uVar8 = __fpmul(uVar8,0x3f000000);
        uVar8 = __fpadd(uVar8,param_3);
        puVar12[4] = uVar8;
        iVar13 = iVar13 + 5;
        puVar12 = puVar12 + 5;
        local_3c = __fpadd(local_3c,0x43340000);
        iVar1 = __lts(local_3c,uVar2);
        local_44 = iVar13;
      } while (iVar1 != 0);
    }
    uVar11 = 0x12;
  }
  iVar13 = local_50 + 1;
  puVar4[local_50] = uVar11;
  uVar6 = __fpmul(param_4,0x3f000000);
  puVar5[local_44] = uVar6;
  uVar6 = __fpmul(param_5,0x3f000000);
  puVar5[local_44 + 1] = uVar6;
  puVar5[local_44 + 2] = 0;
  uVar14 = __fptodp(uVar2);
  uVar14 = __dpmul((int)uVar14,(int)((ulonglong)uVar14 >> 0x20),0xa2529d39,0x3f91df46);
  uVar2 = __dptofp((int)uVar14,(int)((ulonglong)uVar14 >> 0x20));
  uVar6 = mali_sys_cos(uVar2);
  uVar6 = __fpmul(uVar6,param_4);
  uVar6 = __fpmul(uVar6,0x3f000000);
  uVar6 = __fpadd(uVar6,param_2);
  puVar5[local_44 + 3] = uVar6;
  uVar2 = mali_sys_sin(uVar2);
  uVar2 = __fpmul(uVar2,param_5);
  uVar2 = __fpmul(uVar2,0x3f000000);
  uVar2 = __fpadd(uVar2,param_3);
  puVar5[local_44 + 4] = uVar2;
  iVar1 = local_44 + 5;
  if (param_8 == 0xf102) {
    puVar4[iVar13] = 4;
    puVar5[iVar1] = param_2;
    iVar13 = local_50 + 2;
    puVar5[local_44 + 6] = param_3;
    iVar1 = local_44 + 7;
  }
  else if (param_8 != 0xf101) goto LAB_40a72a24;
  puVar10 = puVar4 + iVar13;
  iVar13 = iVar13 + 1;
  *puVar10 = 0;
LAB_40a72a24:
  uVar2 = FUN_40a72058(param_1,iVar13,puVar4,iVar1,puVar5);
  mali_sys_free(puVar4);
  mali_sys_free(puVar5);
  return uVar2;
}



/* 40a72a88 vguEllipse */

/* Boundary evidence: original MIPS .pdata 40a72a88..40a72bb3. Semantic name remains unreviewed. */

undefined4
vguEllipse(undefined4 param_1,undefined4 param_2,undefined4 param_3,uint param_4,undefined4 param_5)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 local_58;
  undefined1 local_57;
  undefined1 local_56;
  undefined1 local_55;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  uint local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  uint local_28;
  undefined4 local_24;
  
                    /* 0x2a88  6  vguEllipse */
  local_55 = 0;
  local_57 = 0x13;
  local_56 = 0x13;
  local_58 = 2;
  iVar1 = __les(param_4,0);
  if ((iVar1 == 0) && (iVar1 = __les(param_5,0), iVar1 == 0)) {
    uVar2 = __fpmul(param_4,0x3f000000);
    local_50 = __fpadd(uVar2,param_2);
    local_4c = param_3;
    local_48 = uVar2;
    local_44 = __fpmul(param_5,0x3f000000);
    local_3c = param_4 ^ 0x80000000;
    local_40 = 0;
    local_38 = 0;
    local_2c = 0;
    local_24 = 0;
    local_34 = uVar2;
    local_30 = local_44;
    local_28 = param_4;
    uVar2 = FUN_40a72058(param_1,4,&local_58,0xc,&local_50);
    return uVar2;
  }
  return 0xf001;
}



/* 40a72bb4 vguRoundRect */

/* Boundary evidence: original MIPS .pdata 40a72bb4..40a72e1b. Semantic name remains unreviewed. */

undefined4
vguRoundRect(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,undefined4 param_6,undefined4 param_7)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  undefined4 uVar4;
  uint uVar5;
  undefined4 local_a0;
  undefined4 local_9c;
  uint local_98;
  undefined4 local_94;
  undefined4 local_90;
  undefined4 local_8c;
  undefined4 local_88;
  undefined4 local_84;
  uint local_80;
  undefined4 local_7c;
  undefined4 local_78;
  undefined4 local_74;
  undefined4 local_70;
  undefined4 local_6c;
  uint local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  uint local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined1 local_38;
  undefined1 local_37;
  undefined1 local_36;
  undefined1 local_35;
  undefined1 local_34;
  undefined1 local_33;
  undefined1 local_32;
  undefined1 local_31;
  undefined1 local_30;
  undefined1 local_2f;
  uint local_2c;
  
                    /* 0x2bb4  10  vguRoundRect */
  local_2c = DAT_40a74088;
  local_38 = 2;
  local_37 = 7;
  local_36 = 0x13;
  local_35 = 9;
  local_34 = 0x13;
  local_33 = 7;
  local_32 = 0x13;
  local_31 = 9;
  local_30 = 0x13;
  local_2f = 0;
  iVar1 = __les(param_4,0);
  if ((iVar1 == 0) && (iVar1 = __les(param_5,0), iVar1 == 0)) {
    iVar1 = __lts(param_6,0);
    if (iVar1 == 0) {
      iVar1 = __gts(param_6,param_4);
      if (iVar1 != 0) {
        param_6 = param_4;
      }
    }
    else {
      param_6 = 0;
    }
    iVar1 = __lts(param_7,0);
    if (iVar1 == 0) {
      iVar1 = __gts(param_7,param_5);
      if (iVar1 != 0) {
        param_7 = param_5;
      }
    }
    else {
      param_7 = 0;
    }
    uVar2 = __fpmul(param_6,0x3f000000);
    local_a0 = __fpadd(uVar2,param_2);
    local_9c = param_3;
    uVar3 = __fpsub(param_4,param_6);
    local_98 = uVar3;
    local_94 = uVar2;
    uVar4 = __fpmul(param_7,0x3f000000);
    local_8c = 0;
    local_90 = uVar4;
    local_88 = uVar2;
    local_84 = uVar4;
    uVar5 = __fpsub(param_5,param_7);
    local_74 = 0;
    local_80 = uVar5;
    local_7c = uVar2;
    local_78 = uVar4;
    local_70 = __fpmul(param_6,0xbf000000);
    local_68 = uVar3 ^ 0x80000000;
    local_5c = 0;
    local_6c = uVar4;
    local_64 = uVar2;
    local_60 = uVar4;
    local_58 = local_70;
    local_54 = __fpmul(param_7,0xbf000000);
    local_50 = uVar5 ^ 0x80000000;
    local_44 = 0;
    local_4c = uVar2;
    local_48 = uVar4;
    local_40 = uVar2;
    local_3c = local_54;
    uVar2 = FUN_40a72058(param_1,10,&local_38,0x1a,&local_a0);
    FUN_40a71318(local_2c);
    return uVar2;
  }
  FUN_40a71318(local_2c);
  return 0xf001;
}



/* 40a72e1c vguRect */

/* Boundary evidence: original MIPS .pdata 40a72e1c..40a72f17. Semantic name remains unreviewed. */

undefined4
vguRect(undefined4 param_1,undefined4 param_2,undefined4 param_3,uint param_4,undefined4 param_5)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 local_38;
  undefined4 local_34;
  uint local_30;
  undefined4 local_2c;
  uint local_28;
  undefined1 local_24;
  undefined1 local_23;
  undefined1 local_22;
  undefined1 local_21;
  undefined1 local_20;
  uint local_1c;
  
                    /* 0x2e1c  9  vguRect */
  local_1c = DAT_40a74088;
  local_24 = 2;
  local_23 = 7;
  local_22 = 9;
  local_21 = 7;
  local_20 = 0;
  iVar1 = __les(param_4,0);
  if ((iVar1 == 0) && (iVar1 = __les(param_5,0), iVar1 == 0)) {
    local_28 = param_4 ^ 0x80000000;
    local_2c = param_5;
    local_38 = param_2;
    local_34 = param_3;
    local_30 = param_4;
    uVar2 = FUN_40a72058(param_1,5,&local_24,5,&local_38);
    FUN_40a71318(local_1c);
    return uVar2;
  }
  FUN_40a71318(local_1c);
  return 0xf001;
}



/* 40a72f18 vguPolygon */

/* Boundary evidence: original MIPS .pdata 40a72f18..40a7303b. Semantic name remains unreviewed. */

undefined4 vguPolygon(undefined4 param_1,undefined4 *param_2,int param_3,int param_4)

{
  undefined1 *puVar1;
  undefined4 uVar2;
  undefined1 *puVar3;
  undefined1 *puVar4;
  int iVar5;
  int iVar6;
  
                    /* 0x2f18  8  vguPolygon */
  if (((param_2 == (undefined4 *)0x0) || (param_3 < 1)) || (((uint)param_2 & 3) != 0)) {
    uVar2 = 0xf001;
  }
  else {
    iVar6 = param_3 << 1;
    puVar1 = (undefined1 *)mali_sys_malloc((uint)(param_4 == 1) + param_3);
    if (puVar1 == (undefined1 *)0x0) {
      uVar2 = 0xf002;
    }
    else {
      *puVar1 = 2;
      iVar5 = 1;
      if (1 < param_3) {
        puVar4 = puVar1 + 1;
        iVar5 = param_3;
        if (param_3 + -1 != 0) {
          puVar3 = puVar4 + param_3 + -1;
          do {
            *puVar4 = 4;
            puVar4 = puVar4 + 1;
          } while (puVar4 != puVar3);
        }
      }
      if (param_4 == 1) {
        param_3 = param_3 + 1;
        puVar1[iVar5] = 0;
      }
      uVar2 = FUN_40a72058(param_1,param_3,puVar1,iVar6,param_2);
      mali_sys_free(puVar1);
    }
  }
  return uVar2;
}



/* 40a7303c vguLine */

/* Boundary evidence: original MIPS .pdata 40a7303c..40a7308b. Semantic name remains unreviewed. */

void vguLine(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5)

{
  undefined1 local_20;
  undefined1 local_1f;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  
                    /* 0x303c  7  vguLine */
  local_20 = 2;
  local_1f = 4;
  local_c = param_5;
  local_18 = param_2;
  local_14 = param_3;
  local_10 = param_4;
  FUN_40a72058(param_1,2,&local_20,4,&local_18);
  return;
}



/* 40a7308c FUN_40a7308c */

/* Boundary evidence: original MIPS .pdata 40a7308c..40a730df. Semantic name remains unreviewed. */

void FUN_40a7308c(int param_1,undefined4 param_2,uint *param_3)

{
  if ((*param_3 & 1) != 0) {
    param_1 = ((-param_3[2] & param_3[1] + param_1) - (param_3[1] + param_1)) + param_1;
  }
  FUN_40a71318(*(uint *)(param_1 + (*param_3 & 0xfffffffc)));
  return;
}



/* 40a730e0 FUN_40a730e0 */

/* Boundary evidence: original MIPS .pdata 40a730e0..40a7310b. Semantic name remains unreviewed. */

undefined4 FUN_40a730e0(undefined4 param_1,int param_2,undefined4 param_3,int param_4)

{
  FUN_40a7308c(param_2,param_4,*(uint **)(*(int *)(param_4 + 4) + 0xc));
  return 1;
}


