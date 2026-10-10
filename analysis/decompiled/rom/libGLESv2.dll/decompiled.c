/* Automatic Ghidra pseudocode. Not original source; not runtime-verified. */

/* 409b2720 FUN_409b2720 */

/* Boundary evidence: original MIPS .pdata 409b2720..409b274b. Semantic name remains unreviewed. */

undefined4 FUN_409b2720(HMODULE param_1,int param_2)

{
  if (param_2 == 1) {
    DisableThreadLibraryCalls(param_1);
  }
  return 1;
}



/* 409b274c FUN_409b274c */

/* Boundary evidence: original MIPS .pdata 409b274c..409b2887. Semantic name remains unreviewed. */

int FUN_409b274c(HMODULE param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 1;
  if (param_2 == 1) {
    if (DAT_409dd398 != (code *)0x0) {
      iVar2 = (*DAT_409dd398)(param_1,1,param_3);
    }
    iVar1 = 0;
    if (iVar2 == 0) goto LAB_409b27fc;
    FUN_409b2ab8();
  }
  iVar1 = 0;
  if (iVar2 != 0) {
    iVar1 = FUN_409b2720(param_1,param_2);
  }
LAB_409b27fc:
  if (((param_2 == 0) && (FUN_409b2a40(), iVar1 != 0)) && (DAT_409dd398 != (code *)0x0)) {
    iVar1 = (*DAT_409dd398)(param_1,0,param_3);
  }
  return iVar1;
}



/* 409b2888 FUN_409b2888 */

/* Boundary evidence: original MIPS .pdata 409b2888..409b28b3. Semantic name remains unreviewed. */

void FUN_409b2888(_EXCEPTION_POINTERS *param_1)

{
  _XcptFilter(param_1->ExceptionRecord->ExceptionCode,param_1);
  return;
}



/* 409b28b4 entry */

/* Boundary evidence: original MIPS .pdata 409b28b4..409b290b. Semantic name remains unreviewed. */

void entry(HMODULE param_1,int param_2,undefined4 param_3)

{
  if (param_2 == 1) {
    FUN_409b2af4();
  }
  FUN_409b274c(param_1,param_2,param_3);
  return;
}



/* 409b290c FUN_409b290c */

/* Boundary evidence: original MIPS .pdata 409b290c..409b2953. Semantic name remains unreviewed. */

void FUN_409b290c(uint param_1)

{
  if ((param_1 == DAT_409dd288) && (param_1 >> 0x10 == 0)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __report_gsfailure();
}



/* 409b2954 FUN_409b2954 */

/* Boundary evidence: original MIPS .pdata 409b2954..409b2a3f. Semantic name remains unreviewed. */

void FUN_409b2954(UINT param_1,int param_2,int param_3)

{
  undefined4 *_Memory;
  
  DAT_409dd388 = (undefined1)param_3;
  if (param_2 == 0) {
    _Memory = DAT_409dd394;
    if (DAT_409dd394 != (undefined4 *)0x0) {
      while (DAT_409dd390 = DAT_409dd390 + -1, _Memory <= DAT_409dd390) {
        if ((code *)*DAT_409dd390 != (code *)0x0) {
          (*(code *)*DAT_409dd390)();
          _Memory = DAT_409dd394;
        }
      }
      free(_Memory);
      DAT_409dd390 = (undefined4 *)0x0;
      DAT_409dd394 = (undefined4 *)0x0;
    }
    FUN_409b2a64((undefined4 *)&DAT_409b1010,(undefined4 *)&DAT_409b1014);
  }
  FUN_409b2a64((undefined4 *)&DAT_409b1018,(undefined4 *)&DAT_409b101c);
  if (param_3 == 0) {
    TerminateProcess((HANDLE)0x42,param_1);
  }
  return;
}



/* 409b2a40 FUN_409b2a40 */

/* Boundary evidence: original MIPS .pdata 409b2a40..409b2a63. Semantic name remains unreviewed. */

void FUN_409b2a40(void)

{
  FUN_409b2954(0,0,1);
  return;
}



/* 409b2a64 FUN_409b2a64 */

/* Boundary evidence: original MIPS .pdata 409b2a64..409b2ab7. Semantic name remains unreviewed. */

void FUN_409b2a64(undefined4 *param_1,undefined4 *param_2)

{
  for (; param_1 < param_2; param_1 = param_1 + 1) {
    if ((code *)*param_1 != (code *)0x0) {
      (*(code *)*param_1)();
    }
  }
  return;
}



/* 409b2ab8 FUN_409b2ab8 */

/* Boundary evidence: original MIPS .pdata 409b2ab8..409b2af3. Semantic name remains unreviewed. */

void FUN_409b2ab8(void)

{
  FUN_409b2a64((undefined4 *)&DAT_409b1008,(undefined4 *)&DAT_409b100c);
  FUN_409b2a64((undefined4 *)&DAT_409b1000,(undefined4 *)&DAT_409b1004);
  return;
}



/* 409b2af4 FUN_409b2af4 */

/* Boundary evidence: original MIPS .pdata 409b2af4..409b2b67. Semantic name remains unreviewed. */

void FUN_409b2af4(void)

{
  uint uVar1;
  
  if ((DAT_409dd288 == 0) || (DAT_409dd288 == 0xb064)) {
    uVar1 = __security_gen_cookie2();
    DAT_409dd288 = uVar1 >> 0x10 ^ uVar1 & 0xffff;
    if (DAT_409dd288 == 0) {
      DAT_409dd288 = 0xb064;
    }
  }
  DAT_409dd28c = ~DAT_409dd288;
  return;
}



/* 409b2bd8 FUN_409b2bd8 */

void FUN_409b2bd8(int param_1,int param_2,int param_3)

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



/* 409b2c5c FUN_409b2c5c */

/* Boundary evidence: original MIPS .pdata 409b2c5c..409b2c8f. Semantic name remains unreviewed. */

undefined4 FUN_409b2c5c(undefined4 *param_1)

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



/* 409b2c90 FUN_409b2c90 */

/* Boundary evidence: original MIPS .pdata 409b2c90..409b2d8b. Semantic name remains unreviewed. */

undefined4 FUN_409b2c90(int param_1,int param_2,int param_3)

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



/* 409b2d8c FUN_409b2d8c */

/* Boundary evidence: original MIPS .pdata 409b2d8c..409b2e1f. Semantic name remains unreviewed. */

void FUN_409b2d8c(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  FUN_409da7c8();
  iVar2 = *(int *)(param_1 + 0x80);
  mali_sys_memcpy(param_2 + 0x80,*(int *)(iVar2 + 0x178) + 200,0x80);
  iVar1 = *(int *)(iVar2 + 0x50);
  *(int *)((iVar1 + 0x10) * 8 + param_2) =
       *(int *)(param_1 + 0x20) * 0x10 + *(int *)(param_1 + 0x88);
  *(undefined4 *)(iVar1 * 8 + param_2 + 0x84) = 0x8020;
  iVar1 = FUN_409b2c90(param_1,param_2,*(int *)(iVar2 + 0x4c));
  if (iVar1 == 0) {
    FUN_409b2bd8(param_1,param_2,iVar2);
  }
                    /* WARNING: Subroutine does not return */
  FUN_409da7e8(0x10);
}



/* 409b2e20 FUN_409b2e20 */

/* Boundary evidence: original MIPS .pdata 409b2e20..409b2e4f. Semantic name remains unreviewed. */

void FUN_409b2e20(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  uVar1 = mali_frame_builder_get_gp_job(*(undefined4 *)(param_1 + 0x7c));
  mali_gp_job_add_plbu_cmd(uVar1);
  return;
}



/* 409b2e50 FUN_409b2e50 */

/* Boundary evidence: original MIPS .pdata 409b2e50..409b2e7f. Semantic name remains unreviewed. */

void FUN_409b2e50(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  uVar1 = mali_frame_builder_get_gp_job(*(undefined4 *)(param_1 + 0x7c));
  mali_gp_job_add_plbu_cmd(uVar1);
  return;
}



/* 409b2e80 FUN_409b2e80 */

void FUN_409b2e80(int param_1,undefined4 *param_2,undefined4 *param_3)

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
LAB_409b2ef4:
      *param_3 = 1;
      return;
    }
  }
  else if (iVar2 == 0x405) {
    if (*(int *)(param_1 + 0x54) != 0x901) goto LAB_409b2ef4;
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



/* 409b2efc FUN_409b2efc */

/* Boundary evidence: original MIPS .pdata 409b2efc..409b2f9f. Semantic name remains unreviewed. */

void FUN_409b2efc(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  int iStack00000010;
  
  FUN_409da688();
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
  FUN_409da6b0(0x18);
}



/* 409b2fa8 FUN_409b2fa8 */

/* Boundary evidence: original MIPS .pdata 409b2fa8..409b2fc3. Semantic name remains unreviewed. */

void FUN_409b2fa8(undefined4 param_1,undefined4 param_2)

{
  mali_sys_memcpy(param_1,param_2,1);
  return;
}



/* 409b2fc4 FUN_409b2fc4 */

/* Boundary evidence: original MIPS .pdata 409b2fc4..409b2fdf. Semantic name remains unreviewed. */

void FUN_409b2fc4(undefined4 param_1,undefined4 param_2)

{
  mali_sys_memcpy(param_1,param_2,1);
  return;
}



/* 409b302c FUN_409b302c */

/* Boundary evidence: original MIPS .pdata 409b302c..409b3047. Semantic name remains unreviewed. */

void FUN_409b302c(void)

{
  mali_sys_atomic_inc();
  return;
}



/* 409b3050 FUN_409b3050 */

/* Boundary evidence: original MIPS .pdata 409b3050..409b3087. Semantic name remains unreviewed. */

int FUN_409b3050(int *param_1,int param_2)

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



/* 409b3088 FUN_409b3088 */

/* Boundary evidence: original MIPS .pdata 409b3088..409b3117. Semantic name remains unreviewed. */

uint FUN_409b3088(int param_1)

{
  uint uVar1;
  int local_18;
  uint local_14;
  
  local_14 = 0;
  local_18 = 0;
  if ((*(int *)(param_1 + 8) != 1) || (uVar1 = 0x400, *(int *)(param_1 + 0xc) == 0x1401)) {
    uVar1 = 0;
  }
  FUN_409b2e80(param_1,&local_14,&local_18);
  return (((local_18 << 1 | local_14) << 5 | *(uint *)(param_1 + 0x6c)) << 4 |
         *(uint *)(param_1 + 0x58)) << 8 | uVar1;
}



/* 409b3118 FUN_409b3118 */

/* Boundary evidence: original MIPS .pdata 409b3118..409b314f. Semantic name remains unreviewed. */

void FUN_409b3118(int param_1)

{
  if ((*(uint *)(param_1 + 0xc) & 0x4000000) != 0) {
    __fpmul(*(undefined4 *)(*(int *)(param_1 + 0x4fc) + 0x70),0x40000000);
  }
  return;
}



/* 409b3150 FUN_409b3150 */

/* Boundary evidence: original MIPS .pdata 409b3150..409b324f. Semantic name remains unreviewed. */

void FUN_409b3150(int param_1,undefined4 param_2,int param_3,int *param_4)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  int iVar6;
  
  FUN_409da7c8();
  uVar5 = *(uint *)(param_1 + 0xc);
  iVar6 = *param_4;
  iVar3 = *(int *)(param_1 + 0x4fc);
  if ((uVar5 & 0x20000000) == 0) {
    if ((uVar5 & 0x10000000) == 0) goto LAB_409b3240;
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
      if ((uVar5 & 0x40000000) == 0) goto LAB_409b3240;
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
LAB_409b3240:
  *param_4 = iVar6;
                    /* WARNING: Subroutine does not return */
  FUN_409da7e8(0x10);
}



/* 409b3250 FUN_409b3250 */

/* Boundary evidence: original MIPS .pdata 409b3250..409b33a7. Semantic name remains unreviewed. */

void FUN_409b3250(int param_1,undefined4 param_2,int param_3,int *param_4)

{
  uint uVar1;
  uint *puVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  
  FUN_409da688();
  iVar7 = *(int *)(param_1 + 0x4fc);
  iVar5 = *param_4;
  uVar1 = FUN_409b3088(iVar7);
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
    if (((uVar1 & 0x400000) != 0) && (iVar7 = FUN_409b2efc(iVar7), iVar7 != 0)) goto LAB_409b33a0;
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
LAB_409b33a0:
                    /* WARNING: Subroutine does not return */
  FUN_409da6b0(0x10);
}



/* 409b33a8 FUN_409b33a8 */

/* Boundary evidence: original MIPS .pdata 409b33a8..409b3477. Semantic name remains unreviewed. */

void FUN_409b33a8(int param_1,undefined4 param_2,int param_3,int *param_4)

{
  int iVar1;
  undefined4 *puVar2;
  int *piVar3;
  
  FUN_409da7c8();
  puVar2 = *(undefined4 **)(*(int *)(param_1 + 0x90) + 0x30c);
  if (puVar2 == (undefined4 *)0x0) {
    iVar1 = FUN_409c1540(*(undefined4 **)(param_1 + 0x74),param_3,param_4);
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
  FUN_409da7e8(0x10);
}



/* 409b3478 FUN_409b3478 */

/* Boundary evidence: original MIPS .pdata 409b3478..409b34e3. Semantic name remains unreviewed. */

void FUN_409b3478(int param_1,undefined4 param_2,int *param_3)

{
  uint uVar1;
  
  uVar1 = 0;
  if (*(int *)(param_1 + 0xc) == 0x1401) {
    uVar1 = *(int *)(param_1 + 0x18) + 3U & 0xfffffffc;
  }
  else if (*(int *)(param_1 + 0xc) == 0x1403) {
    uVar1 = *(int *)(param_1 + 0x18) * 2 + 3U & 0xfffffffc;
  }
  FUN_409b33a8(param_1,param_2,uVar1,param_3);
  return;
}



/* 409b34e4 FUN_409b34e4 */

/* Boundary evidence: original MIPS .pdata 409b34e4..409b35e7. Semantic name remains unreviewed. */

void FUN_409b34e4(int param_1,undefined4 param_2,int param_3,int *param_4,int param_5)

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
  
  FUN_409da688();
  iVar8 = *param_4;
  puVar7 = *(uint **)(param_1 + 0x4fc);
  uVar9 = *(uint *)(param_1 + 0xc) >> 0x1e & 1;
  if (uVar9 != 0) {
    iVar1 = FUN_409b3478((int)puVar7,param_2,&param_5);
    if (iVar1 != 0) goto LAB_409b35e0;
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
LAB_409b35e0:
                    /* WARNING: Subroutine does not return */
  FUN_409da6b0(0x18);
}



/* 409b35e8 FUN_409b35e8 */

/* Boundary evidence: original MIPS .pdata 409b35e8..409b36eb. Semantic name remains unreviewed. */

void FUN_409b35e8(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  uint *puVar5;
  
  FUN_409da808();
  iVar3 = *(int *)(param_1 + 0x4fc);
  uVar1 = mali_frame_builder_get_gp_job(*(undefined4 *)(iVar3 + 0x7c));
  puVar5 = (uint *)(param_1 + 0xc);
  mali_sys_memcpy(&stack0x00000018,puVar5,1);
  piVar4 = (int *)(iVar3 + 0x158);
  iVar3 = iVar3 + 0xd8;
  *piVar4 = 0;
  iVar2 = FUN_409b3250(param_1,uVar1,iVar3,piVar4);
  if (((iVar2 != 0) ||
      ((((*puVar5 & 0x8000000) == 0 &&
        (iVar2 = FUN_409b3150(param_1,uVar1,iVar3,piVar4), iVar2 != 0)) ||
       (iVar2 = FUN_409b34e4(param_1,uVar1,iVar3,piVar4,0x10), iVar2 != 0)))) ||
     (iVar2 = mali_gp_job_add_plbu_cmds(uVar1,iVar3,*piVar4), iVar2 != 0)) {
    mali_sys_memcpy(puVar5,&stack0x00000018,1);
  }
                    /* WARNING: Subroutine does not return */
  FUN_409da838(0x20);
}



/* 409b36ec FUN_409b36ec */

/* Boundary evidence: original MIPS .pdata 409b36ec..409b376b. Semantic name remains unreviewed. */

void FUN_409b36ec(int param_1,undefined4 *param_2,int param_3,int param_4,int param_5)

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



/* 409b376c FUN_409b376c */

/* Boundary evidence: original MIPS .pdata 409b376c..409b38eb. Semantic name remains unreviewed. */

void FUN_409b376c(int param_1,uint param_2,uint param_3,uint param_4)

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



/* 409b38ec FUN_409b38ec */

/* Boundary evidence: original MIPS .pdata 409b38ec..409b3917. Semantic name remains unreviewed. */

void FUN_409b38ec(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  uVar1 = mali_frame_builder_get_gp_job(*(undefined4 *)(param_1 + 0x7c));
  mali_gp_job_add_vs_cmd(uVar1);
  return;
}



/* 409b3918 FUN_409b3918 */

/* Boundary evidence: original MIPS .pdata 409b3918..409b3977. Semantic name remains unreviewed. */

void FUN_409b3918(int param_1,undefined4 param_2)

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



/* 409b3988 FUN_409b3988 */

/* Boundary evidence: original MIPS .pdata 409b3988..409b3ab7. Semantic name remains unreviewed. */

undefined4 FUN_409b3988(int param_1,int *param_2,uint *param_3)

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
    FUN_409b5114(param_1,(undefined4 *)(*(int *)(iVar1 + 0x140) * 4 + iVar6));
    iVar1 = *(int *)(iVar3 + 0x80);
    FUN_409b36ec(iVar6,(undefined4 *)(param_1 + 0x414),*(int *)(iVar1 + 0x150),
                 *(int *)(iVar1 + 0x154),*(int *)(iVar1 + 0x158));
    if (iVar7 != -1) {
      puVar2 = (undefined4 *)(iVar7 * 4 + iVar6);
      *puVar2 = *(undefined4 *)(iVar3 + 100);
      puVar2[1] = *(undefined4 *)(iVar3 + 0x68);
      *(undefined4 *)((iVar7 + 2) * 4 + iVar6) = *(undefined4 *)(iVar3 + 0x60);
    }
    iVar1 = FUN_409c1540(*(undefined4 **)(iVar3 + 0x74),uVar4 << 2,param_2);
    if (iVar1 == 0) {
      return 0xffffffff;
    }
    mali_sys_memcpy(iVar1,iVar6,iVar5 << 2);
  }
  *param_3 = uVar4;
  return 0;
}



/* 409b3ab8 FUN_409b3ab8 */

/* Boundary evidence: original MIPS .pdata 409b3ab8..409b3b43. Semantic name remains unreviewed. */

void FUN_409b3ab8(int param_1,int *param_2)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int iVar3;
  
  FUN_409da7c8();
  uVar1 = mali_frame_builder_get_gp_job(*(undefined4 *)(param_1 + 0x7c));
  puVar2 = (undefined4 *)FUN_409c1540(*(undefined4 **)(param_1 + 0x74),0x100,param_2);
  if (((puVar2 != (undefined4 *)0x0) && (iVar3 = FUN_409b4864(param_1,puVar2), iVar3 == 0)) &&
     (iVar3 = FUN_409b2d8c(param_1,(int)puVar2), iVar3 == 0)) {
    iVar3 = *(int *)(*(int *)(param_1 + 0x80) + 0x178);
    mali_gp_job_add_vs_cmds(uVar1,iVar3 + 0x10,*(undefined4 *)(iVar3 + 8));
  }
                    /* WARNING: Subroutine does not return */
  FUN_409da7e8(0x10);
}



/* 409b3b44 FUN_409b3b44 */

/* Boundary evidence: original MIPS .pdata 409b3b44..409b3b9f. Semantic name remains unreviewed. */

void FUN_409b3b44(int param_1)

{
  int iVar1;
  int iVar2;
  uint local_18;
  uint local_14;
  uint local_10 [2];
  
  iVar2 = *(int *)(param_1 + 0x4fc);
  iVar1 = FUN_409b3988(param_1,(int *)&local_14,&local_18);
  if ((iVar1 == 0) && (iVar1 = FUN_409b3ab8(iVar2,(int *)local_10), iVar1 == 0)) {
    FUN_409b376c(iVar2,local_10[0],local_14,local_18);
  }
  return;
}



/* 409b3bf4 FUN_409b3bf4 */

/* Boundary evidence: original MIPS .pdata 409b3bf4..409b3c27. Semantic name remains unreviewed. */

undefined4 FUN_409b3bf4(undefined4 *param_1)

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



/* 409b3c28 FUN_409b3c28 */

/* Boundary evidence: original MIPS .pdata 409b3c28..409b3e97. Semantic name remains unreviewed. */

void FUN_409b3c28(undefined4 *param_1,undefined4 param_2,undefined4 param_3)

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
  
  FUN_409da808();
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
  FUN_409da838(0x28);
}



/* 409b3e98 FUN_409b3e98 */

/* Boundary evidence: original MIPS .pdata 409b3e98..409b406b. Semantic name remains unreviewed. */

void FUN_409b3e98(int param_1,undefined4 param_2)

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



/* 409b40ac FUN_409b40ac */

/* Boundary evidence: original MIPS .pdata 409b40ac..409b42c7. Semantic name remains unreviewed. */

void FUN_409b40ac(undefined4 *param_1)

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
  
  FUN_409da808();
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
  FUN_409b4e8c((int)param_1,iVar4,uVar6,0);
  if (((*(int *)(iVar4 + 0x28) < *(int *)(iVar4 + 0x30)) &&
      (*(int *)(iVar4 + 0x24) < *(int *)(iVar4 + 0x2c))) &&
     (iVar1 = FUN_409b3918(iVar4,iVar1), iVar1 == 0)) {
    uVar7 = mali_frame_builder_get_gp_job(*(undefined4 *)(iVar4 + 0x7c));
    iVar1 = mali_gp_job_add_plbu_cmd(uVar7);
    if (iVar1 == 0) {
      uVar7 = mali_frame_builder_get_gp_job(uVar6);
      iVar1 = FUN_409b3c28(param_1,uVar7,&stack0x00000010);
      if (iVar1 == 0) {
        uVar7 = mali_frame_builder_get_gp_job(uVar6);
        iVar1 = FUN_409b3e98((int)param_1,uVar7);
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
  FUN_409da838(0x38);
}



/* 409b42c8 FUN_409b42c8 */

uint FUN_409b42c8(int param_1,int param_2,int param_3,uint param_4)

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



/* 409b43bc FUN_409b43bc */

/* Boundary evidence: original MIPS .pdata 409b43bc..409b43d7. Semantic name remains unreviewed. */

void FUN_409b43bc(void)

{
  mali_sys_atomic_inc();
  return;
}



/* 409b43d8 FUN_409b43d8 */

/* Boundary evidence: original MIPS .pdata 409b43d8..409b440b. Semantic name remains unreviewed. */

undefined4 FUN_409b43d8(undefined4 *param_1)

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



/* 409b440c FUN_409b440c */

/* Boundary evidence: original MIPS .pdata 409b440c..409b4493. Semantic name remains unreviewed. */

void FUN_409b440c(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  
  FUN_409da7c8();
  piVar3 = (int *)((param_3 + 0x25) * 4 + param_1);
  if (*piVar3 != 0) {
    *(int *)(param_1 + 0xd4) = *(int *)(param_1 + 0xd4) + -1;
  }
  *piVar3 = 0;
  iVar2 = param_3 * 0x30 + param_2;
  if ((*(int *)(iVar2 + 0x18) == 0) &&
     (iVar1 = FUN_409c33ec(*(uint *)(iVar2 + 0xc)),
     *(int *)(iVar2 + 8) != iVar1 * *(int *)(iVar2 + 4))) {
    *(int *)(param_1 + 0xd4) = *(int *)(param_1 + 0xd4) + 1;
    *piVar3 = 1;
  }
                    /* WARNING: Subroutine does not return */
  FUN_409da7e8(0x10);
}



/* 409b4494 FUN_409b4494 */

/* Boundary evidence: original MIPS .pdata 409b4494..409b4587. Semantic name remains unreviewed. */

void FUN_409b4494(int param_1,int param_2,int param_3,int param_4,undefined4 param_5,
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
  
  FUN_409da758();
  iVar1 = FUN_409c33ec(in_stack_00000058);
  iVar1 = iVar1 * param_4;
  iVar4 = *(int *)(param_1 + 0x14);
  iVar5 = *in_stack_0000005c;
  iVar2 = FUN_409c1540(*(undefined4 **)(param_1 + 0x74),iVar1 * iVar4,&param_7);
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
  FUN_409da790(0x20);
}



/* 409b4588 FUN_409b4588 */

/* Boundary evidence: original MIPS .pdata 409b4588..409b45db. Semantic name remains unreviewed. */

void FUN_409b4588(int param_1,int param_2,undefined4 param_3,int *param_4)

{
  int iVar1;
  
  FUN_409da7c8();
  iVar1 = FUN_409c1540(*(undefined4 **)(param_1 + 0x74),param_2,param_4);
  if (iVar1 != 0) {
    mali_sys_memcpy(iVar1,param_3,param_2);
  }
                    /* WARNING: Subroutine does not return */
  FUN_409da7e8(0x10);
}



/* 409b45dc FUN_409b45dc */

/* Boundary evidence: original MIPS .pdata 409b45dc..409b4863. Semantic name remains unreviewed. */

void FUN_409b45dc(int param_1,int param_2,int param_3,uint *param_4)

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
  
  FUN_409da758();
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
        iVar1 = FUN_409c33ec(*(uint *)(iVar5 + 0xc));
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
LAB_409b46f0:
          uVar11 = *puVar19;
          if ((uVar9 < uVar11) || (puVar19[1] + uVar11 <= uVar9)) {
            if ((uVar11 < uVar9) || (uVar9 + *(int *)(iVar5 + 8) <= uVar11)) goto LAB_409b4734;
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
LAB_409b4800:
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
        uVar20 = FUN_409b4588(param_1,puVar13[-1],puVar13[-2],(int *)(puVar13 + 1));
        *puVar13 = uVar20;
        if (uVar20 == 0) break;
        iVar16 = iVar16 + 1;
        puVar13 = puVar13 + 4;
      } while (iVar16 < iVar17);
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_409da790(0x60);
LAB_409b4734:
  iVar10 = iVar10 + 1;
  prefetch(puVar19 + 8,0);
  puVar19 = puVar19 + 4;
  if (iVar15 <= iVar10) goto LAB_409b4800;
  goto LAB_409b46f0;
}



/* 409b4864 FUN_409b4864 */

/* Boundary evidence: original MIPS .pdata 409b4864..409b4bbf. Semantic name remains unreviewed. */

void FUN_409b4864(int param_1,undefined4 *param_2)

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
  
  FUN_409da758();
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
  FUN_409b45dc(param_1,*(int *)(param_1 + 0x90),iStack00000048,(uint *)&stack0x000000d0);
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
        iVar11 = FUN_409b4588(param_1,0x10,pcVar9 + 0x20,&stack0x00000024);
        if (iVar11 == 0) break;
        iVar11 = 0;
        uVar2 = 3;
LAB_409b4b40:
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
            iVar8 = FUN_409c33ec(in_stack_00000030);
            iVar8 = FUN_409b4588(param_1,iVar8 * in_stack_0000002c + (iStack00000048 + -1) * uVar2,
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
LAB_409b4ad0:
          if (((uVar2 & 0xfff00000) == 0) ||
             (iVar8 = FUN_409b4494(param_1,iVar8,iVar10,in_stack_0000002c,in_stack_00000030,
                                   &stack0x00000038,(int)&stack0x00000024),
             iVar11 = in_stack_00000028, uVar2 = in_stack_00000038, iVar8 == 0)) {
            uVar2 = FUN_409b42c8(in_stack_0000002c,in_stack_00000030,(uint)bVar1,uVar2);
            pcVar12 = in_stack_00000034;
            goto LAB_409b4b40;
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
          goto LAB_409b4ad0;
        }
      }
      uVar13 = uVar13 + 1;
      iVar4 = iVar4 + 8;
    } while (uVar13 < *(uint *)(*(int *)(param_1 + 0x80) + 0x2c));
  }
                    /* WARNING: Subroutine does not return */
  FUN_409da790(0x1d0);
}



/* 409b4bd4 FUN_409b4bd4 */

/* Boundary evidence: original MIPS .pdata 409b4bd4..409b4cdf. Semantic name remains unreviewed. */

void FUN_409b4bd4(int param_1,int param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  
  FUN_409da688();
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
  FUN_409da6b0(0x10);
}



/* 409b4d6c FUN_409b4d6c */

/* Boundary evidence: original MIPS .pdata 409b4d6c..409b4d87. Semantic name remains unreviewed. */

void FUN_409b4d6c(void)

{
  mali_sys_atomic_inc();
  return;
}



/* 409b4d88 FUN_409b4d88 */

/* Boundary evidence: original MIPS .pdata 409b4d88..409b4e8b. Semantic name remains unreviewed. */

void FUN_409b4d88(int param_1,int param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  
  FUN_409da688();
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
  FUN_409da6b0(0x10);
}



/* 409b4e8c FUN_409b4e8c */

/* Boundary evidence: original MIPS .pdata 409b4e8c..409b5113. Semantic name remains unreviewed. */

void FUN_409b4e8c(int param_1,int param_2,undefined4 param_3,uint param_4)

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
  
  FUN_409da688();
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
  FUN_409da6b0(0x10);
}



/* 409b5114 FUN_409b5114 */

/* Boundary evidence: original MIPS .pdata 409b5114..409b5317. Semantic name remains unreviewed. */

void FUN_409b5114(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  uint uVar6;
  uint *puVar7;
  
  FUN_409da758();
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
  FUN_409da790(0x10);
}



/* 409b5318 FUN_409b5318 */

/* Boundary evidence: original MIPS .pdata 409b5318..409b5393. Semantic name remains unreviewed. */

int FUN_409b5318(int param_1)

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



/* 409b5394 FUN_409b5394 */

/* Boundary evidence: original MIPS .pdata 409b5394..409b548f. Semantic name remains unreviewed. */

void FUN_409b5394(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  
  puVar4 = *(undefined4 **)(param_1 + 0x4fc);
  uVar5 = *(undefined4 *)(param_1 + 0x4f4);
  iVar3 = *(int *)(param_1 + 0x500);
  FUN_409b4e8c(param_1,(int)puVar4,uVar5,*(uint *)(param_1 + 0xc) >> 0x1b & 1);
  iVar1 = mali_frame_builder_get_supersample_factor(uVar5);
  FUN_409b4bd4(param_1,(int)puVar4,uVar5,iVar1);
  puVar4[0x24] = param_1 + 0x14;
  *puVar4 = *(undefined4 *)(iVar3 + 0xc);
  if ((*(uint *)(param_1 + 0xc) & 0x8000000) == 0) {
    iVar1 = mali_frame_builder_get_supersample_factor(uVar5);
    FUN_409b4d88(param_1,(int)puVar4,iVar1);
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



/* 409b5490 FUN_409b5490 */

/* Boundary evidence: original MIPS .pdata 409b5490..409b5573. Semantic name remains unreviewed. */

void FUN_409b5490(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  FUN_409da7c8();
  iVar3 = *(int *)(param_1 + 0x4fc);
  if (((*(int *)(iVar3 + 0x28) < *(int *)(iVar3 + 0x30)) &&
      (*(int *)(iVar3 + 0x24) < *(int *)(iVar3 + 0x2c))) &&
     (iVar1 = FUN_409b3918(iVar3,param_2), iVar1 == 0)) {
    uVar2 = mali_frame_builder_get_gp_job(*(undefined4 *)(iVar3 + 0x7c));
    iVar1 = mali_gp_job_add_plbu_cmd(uVar2);
    if (((iVar1 == 0) && (iVar1 = FUN_409b3b44(param_1), iVar1 == 0)) &&
       (iVar1 = FUN_409b35e8(param_1), iVar1 == 0)) {
      uVar2 = mali_frame_builder_get_gp_job(*(undefined4 *)(iVar3 + 0x7c));
      iVar1 = mali_gp_job_add_vs_cmd(uVar2);
      if (iVar1 == 0) {
        uVar2 = mali_frame_builder_get_gp_job(*(undefined4 *)(iVar3 + 0x7c));
        mali_gp_job_add_plbu_cmd(uVar2);
      }
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_409da7e8(0x10);
}



/* 409b5574 FUN_409b5574 */

/* Boundary evidence: original MIPS .pdata 409b5574..409b587f. Semantic name remains unreviewed. */

void FUN_409b5574(int param_1,uint param_2,int param_3,uint param_4)

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
  
  FUN_409da758();
  iVar5 = *(int *)(param_1 + 0x4fc);
  iVar7 = 0;
  iVar6 = 0;
  iVar8 = 0;
  *(undefined4 *)(iVar5 + 0x80) = *(undefined4 *)(param_1 + 0x4d4);
  if (param_2 == 0) goto LAB_409b5608;
  if (param_2 == 1) {
    iVar6 = 2;
    goto LAB_409b560c;
  }
  if (param_2 == 2) {
    *(undefined4 *)(iVar5 + 4) = 3;
LAB_409b578c:
    iVar7 = 1;
LAB_409b5608:
    iVar6 = 1;
  }
  else {
    if (param_2 == 3) goto LAB_409b578c;
    if (param_2 != 4) {
      if (param_2 == 5) {
        iVar7 = 2;
      }
      else {
        if (param_2 != 6) goto LAB_409b560c;
        iVar7 = 2;
        iVar8 = 1;
      }
      goto LAB_409b5608;
    }
    iVar6 = 3;
  }
LAB_409b560c:
  uVar3 = param_2;
  iStack00000010 = param_3;
  iStack00000014 = param_3;
  uStack00000018 = param_4;
  iVar1 = FUN_409b5318(param_1);
  if (iVar1 == 0) {
    FUN_409b5394(param_1);
    *(undefined4 *)(iVar5 + 0x80) = *(undefined4 *)(param_1 + 0x4d4);
    if (((*(int *)(iVar5 + 0x28) < *(int *)(iVar5 + 0x30)) &&
        (*(int *)(iVar5 + 0x24) < *(int *)(iVar5 + 0x2c))) &&
       (iVar1 = FUN_409b3918(iVar5,uVar3), iVar1 == 0)) {
      uVar2 = mali_frame_builder_get_gp_job(*(undefined4 *)(iVar5 + 0x7c));
      iVar1 = mali_gp_job_add_plbu_cmd(uVar2);
      if (iVar1 == 0) {
        for (; (uint)(iVar6 + iVar7) <= param_4; param_4 = (iVar7 - uVar3) + param_4) {
          uVar3 = 0x10000;
          if (param_4 < 0x10001) {
            uVar3 = param_4;
          }
          uVar3 = FUN_409c1808(param_2,uVar3);
          iVar1 = FUN_409b8784(param_1,uVar3);
          if (iVar1 != 0) goto LAB_409b5878;
          puVar4 = *(undefined4 **)(param_1 + 0x500);
          *(undefined4 *)(iVar5 + 0x88) = *puVar4;
          *(undefined4 *)(iVar5 + 0x84) = puVar4[1];
          if (iVar8 != 0) {
            *(int *)(iVar5 + 0x14) = iVar8;
            *(int *)(iVar5 + 0x1c) = iStack00000014;
            *(undefined4 *)(iVar5 + 0x20) = 0;
            iVar1 = FUN_409b3b44(param_1);
            if (iVar1 != 0) goto LAB_409b5878;
          }
          *(uint *)(iVar5 + 0x14) = uVar3 - iVar8;
          *(int *)(iVar5 + 0x1c) = iVar8 + iStack00000010;
          *(int *)(iVar5 + 0x20) = iVar8;
          iVar1 = FUN_409b3b44(param_1);
          if (iVar1 != 0) goto LAB_409b5878;
          *(int *)(iVar5 + 0x1c) = iStack00000010;
          *(uint *)(iVar5 + 0x18) = uVar3;
          iVar1 = FUN_409b35e8(param_1);
          if (iVar1 != 0) goto LAB_409b5878;
          iStack00000010 = (uVar3 - iVar7) + iStack00000010;
        }
        if (param_2 == 2) {
          iVar7 = FUN_409b8784(param_1,2);
          iVar6 = iStack00000014;
          if (iVar7 != 0) goto LAB_409b5878;
          puVar4 = *(undefined4 **)(param_1 + 0x500);
          *(undefined4 *)(iVar5 + 0x88) = *puVar4;
          *(undefined4 *)(iVar5 + 0x84) = puVar4[1];
          *(undefined4 *)(iVar5 + 0x14) = 1;
          *(uint *)(iVar5 + 0x1c) = uStack00000018 + iStack00000014 + -1;
          *(undefined4 *)(iVar5 + 0x20) = 0;
          iVar7 = FUN_409b3b44(param_1);
          if (iVar7 != 0) goto LAB_409b5878;
          *(undefined4 *)(iVar5 + 0x14) = 1;
          *(int *)(iVar5 + 0x1c) = iVar6;
          *(undefined4 *)(iVar5 + 0x20) = 1;
          iVar6 = FUN_409b3b44(param_1);
          if (iVar6 != 0) goto LAB_409b5878;
          *(undefined4 *)(iVar5 + 0x18) = 2;
          *(undefined4 *)(iVar5 + 0x1c) = 0;
          iVar6 = FUN_409b35e8(param_1);
          if (iVar6 != 0) goto LAB_409b5878;
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
LAB_409b5878:
                    /* WARNING: Subroutine does not return */
  FUN_409da790(0x20);
}



/* 409b5880 FUN_409b5880 */

/* Boundary evidence: original MIPS .pdata 409b5880..409b59a7. Semantic name remains unreviewed. */

void FUN_409b5880(undefined4 *param_1,undefined4 param_2,int param_3,int param_4)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 in_stack_00000030;
  undefined4 in_stack_00000034;
  undefined4 in_stack_00000038;
  
  FUN_409da7c8();
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
  iVar1 = FUN_409b8784((int)param_1,iVar1);
  if (iVar1 == 0) {
    puVar3 = (undefined4 *)param_1[0x140];
    *(undefined4 *)(iVar4 + 0x88) = *puVar3;
    *(undefined4 *)(iVar4 + 0x84) = puVar3[1];
    iVar1 = FUN_409b5318((int)param_1);
    if ((((iVar1 == 0) &&
         (FUN_409b5394((int)param_1), *(int *)(iVar4 + 0x28) < *(int *)(iVar4 + 0x30))) &&
        (*(int *)(iVar4 + 0x24) < *(int *)(iVar4 + 0x2c))) &&
       ((iVar1 = FUN_409b3b44((int)param_1), iVar1 != 0 ||
        (iVar1 = FUN_409b35e8((int)param_1), iVar1 != 0)))) {
      mali_frame_builder_reset(param_1[0x13d]);
      iVar1 = FUN_409c508c(param_1);
      if (iVar1 == 0) {
        FUN_409c1638((undefined4 *)param_1[0x144]);
      }
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_409da7e8(0x10);
}



/* 409b59a8 FUN_409b59a8 */

/* Boundary evidence: original MIPS .pdata 409b59a8..409b5aab. Semantic name remains unreviewed. */

void FUN_409b59a8(undefined4 *param_1,uint param_2,int param_3,uint param_4)

{
  int iVar1;
  uint uVar2;
  undefined4 *puVar3;
  int iVar4;
  
  FUN_409da688();
  iVar4 = param_1[0x13f];
  *(undefined4 *)(iVar4 + 0x74) = param_1[0x144];
  *(uint *)(iVar4 + 4) = param_2;
  *(undefined4 *)(iVar4 + 8) = 0;
  *(undefined4 *)(iVar4 + 0xc) = 0;
  *(undefined4 *)(iVar4 + 0x10) = 0;
  if (param_4 < 0x10001) {
    uVar2 = param_4;
    iVar1 = FUN_409b8784((int)param_1,param_4);
    if (iVar1 != 0) goto LAB_409b5aa0;
    puVar3 = (undefined4 *)param_1[0x140];
    *(undefined4 *)(iVar4 + 0x88) = *puVar3;
    *(undefined4 *)(iVar4 + 0x84) = puVar3[1];
    *(uint *)(iVar4 + 0x14) = param_4;
    *(int *)(iVar4 + 0x1c) = param_3;
    *(uint *)(iVar4 + 0x18) = param_4;
    *(undefined4 *)(iVar4 + 0x20) = 0;
    *(undefined4 *)(iVar4 + 0x80) = param_1[0x135];
    iVar4 = FUN_409b5318((int)param_1);
    if (iVar4 != 0) goto LAB_409b5aa0;
    FUN_409b5394((int)param_1);
    iVar4 = FUN_409b5490((int)param_1,uVar2);
  }
  else {
    iVar4 = FUN_409b5574((int)param_1,param_2,param_3,param_4);
  }
  if (iVar4 != 0) {
    mali_frame_builder_reset(param_1[0x13d]);
    iVar4 = FUN_409c508c(param_1);
    if (iVar4 == 0) {
      FUN_409c1638((undefined4 *)param_1[0x144]);
    }
  }
LAB_409b5aa0:
                    /* WARNING: Subroutine does not return */
  FUN_409da6b0(0x10);
}



/* 409b5ad4 FUN_409b5ad4 */

/* Boundary evidence: original MIPS .pdata 409b5ad4..409b5cef. Semantic name remains unreviewed. */

void FUN_409b5ad4(int *param_1,uint param_2,uint param_3,uint param_4)

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
  
  FUN_409da758();
  uVar1 = DAT_409dd288;
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
  FUN_409b290c(uVar1);
                    /* WARNING: Subroutine does not return */
  FUN_409da790(0x228);
}



/* 409b5cf0 FUN_409b5cf0 */

/* Boundary evidence: original MIPS .pdata 409b5cf0..409b5d23. Semantic name remains unreviewed. */

void FUN_409b5cf0(undefined4 *param_1)

{
  mali_mem_ref_deref(*param_1);
  *param_1 = 0;
  mali_sys_free(param_1);
  return;
}



/* 409b5d24 FUN_409b5d24 */

/* Boundary evidence: original MIPS .pdata 409b5d24..409b5daf. Semantic name remains unreviewed. */

void FUN_409b5d24(undefined4 param_1,undefined4 param_2,int param_3,int *param_4)

{
  int iVar1;
  int *piVar2;
  
  FUN_409da7c8();
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
  FUN_409da7e8(0x10);
}



/* 409b5db0 FUN_409b5db0 */

/* Boundary evidence: original MIPS .pdata 409b5db0..409b5dcb. Semantic name remains unreviewed. */

void FUN_409b5db0(void)

{
  mali_sys_atomic_get();
  return;
}



/* 409b5dcc FUN_409b5dcc */

/* Boundary evidence: original MIPS .pdata 409b5dcc..409b5ef3. Semantic name remains unreviewed. */

int * FUN_409b5dcc(undefined4 param_1,int *param_2,int param_3,undefined4 param_4,int param_5,
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



/* 409b5ef4 FUN_409b5ef4 */

/* Boundary evidence: original MIPS .pdata 409b5ef4..409b5f0f. Semantic name remains unreviewed. */

void FUN_409b5ef4(void)

{
  mali_sys_free();
  return;
}



/* 409b5f10 FUN_409b5f10 */

/* Boundary evidence: original MIPS .pdata 409b5f10..409b5f2f. Semantic name remains unreviewed. */

void FUN_409b5f10(undefined4 param_1,int param_2)

{
  mali_gp_job_add_vs_cmds(param_1,param_2 + 0x10,*(undefined4 *)(param_2 + 8));
  return;
}



/* 409b5f30 FUN_409b5f30 */

/* Boundary evidence: original MIPS .pdata 409b5f30..409b5f53. Semantic name remains unreviewed. */

void FUN_409b5f30(int param_1,int param_2)

{
  mali_sys_memcpy(param_1 + 0x80,param_2 + 200,0x80);
  return;
}



/* 409b5f54 FUN_409b5f54 */

void FUN_409b5f54(int param_1,int param_2)

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



/* 409b5fe4 FUN_409b5fe4 */

/* Boundary evidence: original MIPS .pdata 409b5fe4..409b6017. Semantic name remains unreviewed. */

undefined4 FUN_409b5fe4(undefined4 *param_1)

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



/* 409b6018 FUN_409b6018 */

/* Boundary evidence: original MIPS .pdata 409b6018..409b6183. Semantic name remains unreviewed. */

int * FUN_409b6018(int param_1)

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
    FUN_409b5f54(param_1,(int)(piVar1 + 0x12));
  }
  return piVar1;
}



/* 409b619c FUN_409b619c */

/* Boundary evidence: original MIPS .pdata 409b619c..409b61e7. Semantic name remains unreviewed. */

void FUN_409b619c(int param_1)

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



/* 409b61e8 FUN_409b61e8 */

/* Boundary evidence: original MIPS .pdata 409b61e8..409b625f. Semantic name remains unreviewed. */

undefined4 FUN_409b61e8(undefined4 *param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  if (param_1[0x13f] != 0) {
    FUN_409b619c((int)param_1);
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



/* 409b6260 FUN_409b6260 */

/* Boundary evidence: original MIPS .pdata 409b6260..409b6297. Semantic name remains unreviewed. */

void FUN_409b6260(int param_1)

{
  if (*(int *)(param_1 + 0xbc) != 0) {
    mali_mem_ref_deref();
    *(undefined4 *)(param_1 + 0x68) = 0;
  }
  return;
}



/* 409b62a0 FUN_409b62a0 */

/* Boundary evidence: original MIPS .pdata 409b62a0..409b62bb. Semantic name remains unreviewed. */

void FUN_409b62a0(void)

{
  mali_sys_atomic_inc();
  return;
}



/* 409b62e8 FUN_409b62e8 */

/* Boundary evidence: original MIPS .pdata 409b62e8..409b631b. Semantic name remains unreviewed. */

undefined4 FUN_409b62e8(undefined4 *param_1)

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



/* 409b631c FUN_409b631c */

/* Boundary evidence: original MIPS .pdata 409b631c..409b639f. Semantic name remains unreviewed. */

void FUN_409b631c(int param_1,uint *param_2,uint param_3)

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



/* 409b63a0 FUN_409b63a0 */

void FUN_409b63a0(int param_1)

{
  *(undefined4 *)(param_1 + 0x10) = 0xffff0000;
  *(undefined2 *)(param_1 + 0x3a) = 0;
  *(uint *)(param_1 + 0x20) = *(uint *)(param_1 + 0x20) & 0xffff0ff8 ^ 0xf007;
  *(uint *)(param_1 + 8) = *(uint *)(param_1 + 8) & 0xf3000000 ^ 0xc321892;
  *(uint *)(param_1 + 0xc) = *(uint *)(param_1 + 0xc) & 0xffffffc1 ^ 0x30;
  *(uint *)(param_1 + 0x34) = *(uint *)(param_1 + 0x34) & 0xf0003d40 ^ 0x200;
  return;
}



/* 409b6414 FUN_409b6414 */

/* Boundary evidence: original MIPS .pdata 409b6414..409b645f. Semantic name remains unreviewed. */

undefined4 FUN_409b6414(int param_1)

{
  mali_sys_memset(param_1 + 0x7c,0,0x40);
  FUN_409b63a0(param_1 + 0x7c);
  *(undefined4 *)(param_1 + 0xbc) = 0;
  return 0;
}



/* 409b6460 FUN_409b6460 */

/* Boundary evidence: original MIPS .pdata 409b6460..409b6567. Semantic name remains unreviewed. */

void FUN_409b6460(undefined4 *param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  uint uStack00000010;
  undefined4 uStack00000014;
  undefined4 uStack00000018;
  undefined4 uStack0000001c;
  undefined4 uStack00000020;
  
  FUN_409da7c8();
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
    if (iVar1 == 0) goto LAB_409b6560;
    mali_mem_write(*(undefined4 *)(iVar1 + 4),0,&stack0x00000010,0x14);
  }
  iVar1 = mali_frame_builder_add_callback(uVar3,mali_mem_ref_deref,*(undefined4 *)(iVar2 + 0xbc));
  if (iVar1 == 0) {
    FUN_409b631c(iVar2 + 0x7c,*(uint **)(*(int *)(iVar2 + 0xbc) + 4),uStack00000010 & 0x1f);
    mali_sys_atomic_inc(*(undefined4 *)(iVar2 + 0xbc));
    iVar1 = FUN_409da470((int)param_1,3,0);
    if ((iVar1 == 0) && (iVar1 = FUN_409b8540((int)param_1,iVar2 + 0x7c), iVar1 == 0)) {
      *(undefined4 *)(iVar2 + 0xc) = 0;
      FUN_409b40ac(param_1);
    }
  }
LAB_409b6560:
                    /* WARNING: Subroutine does not return */
  FUN_409da7e8(0x28);
}



/* 409b6568 FUN_409b6568 */

/* Boundary evidence: original MIPS .pdata 409b6568..409b6583. Semantic name remains unreviewed. */

void FUN_409b6568(void)

{
  mali_sys_free();
  return;
}



/* 409b65b0 FUN_409b65b0 */

/* Boundary evidence: original MIPS .pdata 409b65b0..409b65e3. Semantic name remains unreviewed. */

undefined4 FUN_409b65b0(undefined4 *param_1)

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



/* 409b65e4 FUN_409b65e4 */

uint FUN_409b65e4(uint param_1)

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



/* 409b66d8 FUN_409b66d8 */

/* Boundary evidence: original MIPS .pdata 409b66d8..409b690f. Semantic name remains unreviewed. */

void FUN_409b66d8(int param_1,undefined4 param_2,uint param_3)

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
    goto LAB_409b67c0;
  case 6:
    uVar3 = 0xffe30000;
    uVar1 = param_3 << 0x12;
    uVar2 = 0x1c0000;
    goto LAB_409b67bc;
  case 7:
    uVar3 = 0xff1f0000;
    uVar1 = param_3 << 0x15;
    uVar2 = 0xe00000;
    goto LAB_409b67bc;
  case 8:
    uVar3 = 0xf8ff0000;
    uVar1 = param_3 << 0x18;
    uVar2 = 0x7000000;
    goto LAB_409b67bc;
  case 9:
    uVar3 = 0xc7ff0000;
    uVar1 = param_3 << 0x1b;
    uVar2 = 0x38000000;
LAB_409b67bc:
    uVar3 = uVar3 | 0xffff;
LAB_409b67c0:
    *(uint *)(param_1 + 0x28) = *(uint *)(param_1 + 0x28) & uVar3 ^ uVar1;
    *(uint *)(param_1 + 0x68) = *(uint *)(param_1 + 0x68) & uVar3 ^ uVar2;
    return;
  case 10:
    *(uint *)(param_1 + 0x28) = param_3 << 0x1e ^ *(uint *)(param_1 + 0x28) & 0x3fffffff;
    *(uint *)(param_1 + 0x68) = *(uint *)(param_1 + 0x68) & 0x3fffffff ^ 0xc0000000;
    *(uint *)(param_1 + 0x3c) = (int)param_3 >> 2 ^ *(uint *)(param_1 + 0x3c) & 0xfffffffe;
    uVar1 = *(uint *)(param_1 + 0x7c) & 0xfffffffe ^ 1;
    goto LAB_409b674c;
  case 0xb:
    *(uint *)(param_1 + 0x3c) = *(uint *)(param_1 + 0x3c) & 0xfffffff1 ^ param_3 << 1;
    uVar1 = *(uint *)(param_1 + 0x7c) & 0xfffffff1 ^ 0xe;
LAB_409b674c:
    *(uint *)(param_1 + 0x7c) = uVar1;
  default:
    goto switchD_409b6704_default;
  }
  *(uint *)(param_1 + 0x68) = uVar1;
switchD_409b6704_default:
  return;
}



/* 409b6910 FUN_409b6910 */

/* Boundary evidence: original MIPS .pdata 409b6910..409b69c7. Semantic name remains unreviewed. */

void FUN_409b6910(int param_1,int param_2)

{
  bool bVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  FUN_409da688();
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
      FUN_409b66d8(param_1,iVar6,uVar2);
      iVar6 = iVar6 + 1;
      iVar4 = iVar4 + 0xc;
    } while (iVar6 < iVar5);
  }
  *(uint *)(param_1 + 0x34) =
       *(uint *)(param_1 + 0x34) & 0xffffffe0 ^ *(uint *)(param_2 + 0x24) >> 3;
                    /* WARNING: Subroutine does not return */
  *(uint *)(param_1 + 0x74) = *(uint *)(param_1 + 0x74) & 0xffffffe0 ^ 0x1f;
  FUN_409da6b0(0x10);
}



/* 409b69c8 FUN_409b69c8 */

/* Boundary evidence: original MIPS .pdata 409b69c8..409b6d77. Semantic name remains unreviewed. */

int FUN_409b69c8(int param_1)

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
    FUN_409b6910(iVar1,param_1);
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
      uVar2 = FUN_409b65e4((uVar2 >> 0x10 | uVar2) + 1);
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



/* 409b6d78 FUN_409b6d78 */

/* Boundary evidence: original MIPS .pdata 409b6d78..409b6da7. Semantic name remains unreviewed. */

int FUN_409b6d78(void)

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



/* 409b6da8 FUN_409b6da8 */

/* Boundary evidence: original MIPS .pdata 409b6da8..409b6dc3. Semantic name remains unreviewed. */

void FUN_409b6da8(int param_1)

{
  mali_sys_atomic_inc(param_1 + 4);
  return;
}



/* 409b6de8 FUN_409b6de8 */

/* Boundary evidence: original MIPS .pdata 409b6de8..409b7093. Semantic name remains unreviewed. */

void FUN_409b6de8(undefined4 *param_1,int param_2,int param_3)

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
  
  FUN_409da758();
  iVar6 = 0;
  puStack00000038 = param_1;
  puVar1 = (uint *)FUN_409c7034(param_2,param_3,0);
  if (((((puVar1 == (uint *)0x0) || (uVar4 = puVar1[1], uVar4 == 0)) ||
       (uVar3 = *puVar1, uVar3 == 0)) ||
      ((puVar1[4] == 0x1403 && ((puVar1[3] == 0x1908 || (puVar1[3] == 0x190a)))))) ||
     ((puVar1[3] == 0x8d64 || (((uVar3 - 1 & uVar3) != 0 || ((uVar4 - 1 & uVar4) != 0))))))
  goto LAB_409b7088;
  iVar2 = FUN_409c682c(param_3);
  piVar7 = *(int **)(iVar2 * 0x34 + *(int *)(param_2 + 0x34));
  uVar9 = *(undefined4 *)(*piVar7 + 0x2c);
  __m200_texel_format_get_bpp(*(undefined4 *)(*piVar7 + 0x18));
  puVar5 = *(undefined4 **)*piVar7;
  mali_sys_atomic_inc(puVar5 + 1);
  iVar2 = mali_mem_ptr_map_area(*puVar5,*(undefined4 *)(*piVar7 + 4),uVar9,0);
  if (iVar2 == 0) {
LAB_409b6f1c:
    mali_shared_mem_ref_owner_deref(puVar5);
  }
  else {
    if (*(int *)(*piVar7 + 0x20) != 0) {
      iVar6 = mali_sys_malloc(uVar9);
      if (iVar6 == 0) {
        mali_mem_ptr_unmap_area(**(undefined4 **)*piVar7);
        goto LAB_409b6f1c;
      }
      iVar8 = *(int *)(*piVar7 + 0x20);
      if (iVar8 != 0) {
        FUN_409bacdc(*puVar1,puVar1[1],iVar8);
      }
      iVar2 = m200_texture_swizzle(iVar6,0,iVar2,iVar8);
      mali_mem_ptr_unmap_area(*puVar5);
      mali_shared_mem_ref_owner_deref(puVar5);
      puVar5 = (undefined4 *)0x0;
      if (iVar2 != 0) {
        mali_sys_free(iVar6);
        goto LAB_409b7088;
      }
    }
    FUN_409c2428(param_2,puStack00000038,param_3);
    if (iVar6 != 0) {
      mali_sys_free(iVar6);
    }
    if (puVar5 != (undefined4 *)0x0) {
      mali_mem_ptr_unmap_area(*puVar5);
      mali_shared_mem_ref_owner_deref(puVar5);
    }
  }
LAB_409b7088:
                    /* WARNING: Subroutine does not return */
  FUN_409da790(0x40);
}



/* 409b7094 FUN_409b7094 */

/* Boundary evidence: original MIPS .pdata 409b7094..409b7183. Semantic name remains unreviewed. */

undefined4 FUN_409b7094(undefined4 param_1)

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



/* 409b7184 FUN_409b7184 */

undefined4 FUN_409b7184(uint param_1)

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



/* 409b72bc FUN_409b72bc */

/* Boundary evidence: original MIPS .pdata 409b72bc..409b733f. Semantic name remains unreviewed. */

undefined4 FUN_409b72bc(undefined4 param_1)

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



/* 409b7340 FUN_409b7340 */

undefined4 FUN_409b7340(uint param_1)

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



/* 409b73ec FUN_409b73ec */

undefined4 FUN_409b73ec(int param_1)

{
  undefined4 uVar1;
  
  if (param_1 == 0) {
    uVar1 = 0x800a;
  }
  else if (param_1 == 1) {
    uVar1 = 0x800b;
  }
  else if (param_1 == 2) {
    uVar1 = 0x8006;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}



/* 409b7474 FUN_409b7474 */

/* Boundary evidence: original MIPS .pdata 409b7474..409b74ff. Semantic name remains unreviewed. */

undefined4 FUN_409b7474(undefined4 param_1)

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



/* 409b7500 FUN_409b7500 */

/* Boundary evidence: original MIPS .pdata 409b7500..409b7583. Semantic name remains unreviewed. */

undefined4 FUN_409b7500(undefined4 param_1)

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



/* 409b7584 FUN_409b7584 */

/* Boundary evidence: original MIPS .pdata 409b7584..409b75bb. Semantic name remains unreviewed. */

void FUN_409b7584(int param_1)

{
  if (*(int *)(param_1 + 0x68) != 0) {
    mali_mem_ref_deref();
    *(undefined4 *)(param_1 + 0x68) = 0;
  }
  return;
}



/* 409b75c4 FUN_409b75c4 */

/* Boundary evidence: original MIPS .pdata 409b75c4..409b75df. Semantic name remains unreviewed. */

void FUN_409b75c4(void)

{
  mali_sys_atomic_inc();
  return;
}



/* 409b760c FUN_409b760c */

/* Boundary evidence: original MIPS .pdata 409b760c..409b763f. Semantic name remains unreviewed. */

undefined4 FUN_409b760c(undefined4 *param_1)

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



/* 409b7640 FUN_409b7640 */

/* Boundary evidence: original MIPS .pdata 409b7640..409b7727. Semantic name remains unreviewed. */

void FUN_409b7640(uint *param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  
  FUN_409da808();
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
  FUN_409da838(0x10);
}



/* 409b7728 FUN_409b7728 */

void FUN_409b7728(int param_1,uint param_2,int param_3)

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



/* 409b78ec FUN_409b78ec */

/* Boundary evidence: original MIPS .pdata 409b78ec..409b796f. Semantic name remains unreviewed. */

void FUN_409b78ec(int param_1,uint *param_2)

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



/* 409b79e0 FUN_409b79e0 */

/* Boundary evidence: original MIPS .pdata 409b79e0..409b7a8f. Semantic name remains unreviewed. */

undefined4 FUN_409b79e0(int param_1)

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



/* 409b7a90 FUN_409b7a90 */

/* Boundary evidence: original MIPS .pdata 409b7a90..409b7be3. Semantic name remains unreviewed. */

void FUN_409b7a90(undefined4 *param_1,uint param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  
  FUN_409da688();
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
    if (iVar1 == 0) goto LAB_409b7bdc;
    FUN_409b7640((uint *)(iVar3 + 0x28),param_1 + 0x118);
    mali_mem_write(*(undefined4 *)(*(int *)(iVar3 + 0x68) + 4),0,&DAT_409b10a0,0x14);
    *(undefined4 *)(iVar3 + 0x6c) = param_1[0x118];
    *(undefined4 *)(iVar3 + 0x70) = param_1[0x119];
    *(undefined4 *)(iVar3 + 0x74) = param_1[0x11a];
    *(undefined4 *)(iVar3 + 0x78) = param_1[0x11b];
  }
  iVar1 = mali_frame_builder_add_callback(uVar4,mali_mem_ref_deref,*(undefined4 *)(iVar3 + 0x68));
  if (iVar1 == 0) {
    iVar2 = iVar3 + 0x28;
    FUN_409b78ec(iVar2,*(uint **)(*(int *)(iVar3 + 0x68) + 4));
    mali_sys_atomic_inc(*(undefined4 *)(iVar3 + 0x68));
    FUN_409b7728(iVar2,param_2,(int)param_1);
    iVar1 = FUN_409da470((int)param_1,3,0);
    if ((iVar1 == 0) && (iVar1 = FUN_409b8540((int)param_1,iVar2), iVar1 == 0)) {
      *(undefined4 *)(iVar3 + 0xc) = 0;
      FUN_409b40ac(param_1);
    }
  }
LAB_409b7bdc:
                    /* WARNING: Subroutine does not return */
  FUN_409da6b0(0x10);
}



/* 409b7be4 FUN_409b7be4 */

/* Boundary evidence: original MIPS .pdata 409b7be4..409b7bff. Semantic name remains unreviewed. */

void FUN_409b7be4(void)

{
  mali_sys_atomic_inc();
  return;
}



/* 409b7c00 FUN_409b7c00 */

/* Boundary evidence: original MIPS .pdata 409b7c00..409b7c47. Semantic name remains unreviewed. */

undefined4 FUN_409b7c00(undefined4 param_1,int param_2)

{
  mali_sys_atomic_inc(*(undefined4 *)(param_2 + 0x74));
  mali_frame_builder_update_fragment_stack
            (param_1,*(undefined4 *)(param_2 + 0xa8),*(undefined4 *)(param_2 + 0xa4));
  return 0;
}



/* 409b7d24 FUN_409b7d24 */

void FUN_409b7d24(int param_1,int param_2)

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



/* 409b7d98 FUN_409b7d98 */

undefined4 FUN_409b7d98(int param_1,int param_2)

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



/* 409b7e58 FUN_409b7e58 */

/* Boundary evidence: original MIPS .pdata 409b7e58..409b7f0f. Semantic name remains unreviewed. */

void FUN_409b7e58(int param_1,int param_2)

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
    iVar1 = FUN_409b7d98(param_2,iVar1 + 0x7c);
  }
  else {
    iVar1 = 0;
  }
  *(uint *)(param_2 + 0x34) = (iVar1 << 0xc ^ uVar3) & 0xffffedff;
  return;
}



/* 409b7f10 FUN_409b7f10 */

void FUN_409b7f10(int param_1,int param_2,int param_3)

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



/* 409b801c FUN_409b801c */

/* Boundary evidence: original MIPS .pdata 409b801c..409b8163. Semantic name remains unreviewed. */

void FUN_409b801c(int param_1,int param_2,int param_3,int param_4)

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
  FUN_409b7d24(param_1,*(uint *)(param_1 + 0xc) >> 0x1b & 1);
  FUN_409b7f10(param_1,*(uint *)(param_1 + 0xc) >> 0x1d & 1,*(uint *)(param_1 + 0xc) >> 0x1c & 1);
  if (*(int *)(param_1 + 0x490) == 0) {
    if (*(int *)(param_1 + 1000) != 0x901) goto LAB_409b80f8;
  }
  else if (*(int *)(param_1 + 1000) == 0x901) goto LAB_409b80f8;
  iVar1 = 0;
LAB_409b80f8:
  *(uint *)(param_3 + 0x38) = *(uint *)(param_3 + 0x38) & 0xffffefff ^ iVar1 << 0xc;
  *(uint *)(param_3 + 0x30) = *(uint *)(param_3 + 0x30) & 0xf ^ *(uint *)(param_2 + 0x14);
  *(uint *)(param_3 + 0x2c) = *(uint *)(param_3 + 0x2c) & 0xf ^ *(uint *)(param_2 + 0x20);
  FUN_409b7e58(param_1,param_3);
  return;
}



/* 409b8164 FUN_409b8164 */

/* Boundary evidence: original MIPS .pdata 409b8164..409b81b7. Semantic name remains unreviewed. */

void FUN_409b8164(undefined4 *param_1)

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



/* 409b822c FUN_409b822c */

/* Boundary evidence: original MIPS .pdata 409b822c..409b825b. Semantic name remains unreviewed. */

void FUN_409b822c(undefined4 *param_1)

{
  FUN_409b8164(param_1);
  mali_sys_free(param_1);
  return;
}



/* 409b825c FUN_409b825c */

/* Boundary evidence: original MIPS .pdata 409b825c..409b82b3. Semantic name remains unreviewed. */

void FUN_409b825c(undefined4 *param_1)

{
  int iVar1;
  
  mali_sys_memset(param_1,0,0xc0);
  *param_1 = 0;
  param_1[1] = 0;
  param_1[5] = 0;
  param_1[8] = 0;
  iVar1 = FUN_409b6414((int)param_1);
  if (iVar1 == 0) {
    FUN_409b79e0((int)param_1);
  }
  return;
}



/* 409b8318 FUN_409b8318 */

/* Boundary evidence: original MIPS .pdata 409b8318..409b836f. Semantic name remains unreviewed. */

undefined4 * FUN_409b8318(void)

{
  undefined4 *puVar1;
  int iVar2;
  
  puVar1 = (undefined4 *)mali_sys_malloc(0xc0);
  if (puVar1 != (undefined4 *)0x0) {
    iVar2 = FUN_409b825c(puVar1);
    if (iVar2 == 0) {
      return puVar1;
    }
    FUN_409b8164(puVar1);
    mali_sys_free(puVar1);
  }
  return (undefined4 *)0x0;
}



/* 409b8370 FUN_409b8370 */

void FUN_409b8370(int param_1)

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



/* 409b8414 FUN_409b8414 */

uint FUN_409b8414(uint param_1)

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



/* 409b84c0 FUN_409b84c0 */

/* Boundary evidence: original MIPS .pdata 409b84c0..409b853f. Semantic name remains unreviewed. */

void FUN_409b84c0(int param_1,int param_2,int param_3,uint param_4)

{
  int iVar1;
  uint uVar2;
  uint *puVar3;
  
  if (-1 < param_3) {
    puVar3 = (uint *)(*(int *)(param_1 + 0xac) + param_3 * 4);
    iVar1 = __nes(*puVar3,param_4);
    if (iVar1 != 0) {
      *puVar3 = param_4;
      uVar2 = FUN_409b8414(param_4);
      *(short *)(*(int *)(param_2 + 0x17c) + param_3 * 2) = (short)uVar2;
    }
  }
  return;
}



/* 409b8540 FUN_409b8540 */

/* Boundary evidence: original MIPS .pdata 409b8540..409b85cb. Semantic name remains unreviewed. */

undefined4 FUN_409b8540(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 *puVar4;
  int *piVar5;
  
  puVar4 = *(undefined4 **)(param_1 + 0x500);
  piVar5 = puVar4 + 2;
  iVar1 = FUN_409c1540(*(undefined4 **)(param_1 + 0x510),0x40,piVar5);
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



/* 409b85cc FUN_409b85cc */

/* Boundary evidence: original MIPS .pdata 409b85cc..409b8783. Semantic name remains unreviewed. */

void FUN_409b85cc(int param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  undefined4 uVar4;
  int iVar5;
  
  FUN_409da758();
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
    FUN_409b84c0(param_3,param_2,iVar5,uVar2);
    FUN_409b84c0(param_3,param_2,*(int *)(param_2 + 0x168) + 1,uVar2);
    FUN_409b84c0(param_3,param_2,*(int *)(param_2 + 0x168) + 2,0x3f800000);
  }
  iVar5 = *(int *)(param_2 + 0x14c);
  if (iVar5 != -1) {
    if (*(int *)(param_1 + 0x490) == 0) {
      FUN_409b84c0(param_3,param_2,iVar5,0x3f800000);
      FUN_409b84c0(param_3,param_2,iVar5 + 1,0xbf800000);
      FUN_409b84c0(param_3,param_2,iVar5 + 2,0);
      uVar2 = 0x3f800000;
    }
    else {
      FUN_409b84c0(param_3,param_2,iVar5,0x3f800000);
      FUN_409b84c0(param_3,param_2,iVar5 + 1,0x3f800000);
      FUN_409b84c0(param_3,param_2,iVar5 + 2,0);
      uVar2 = 0;
    }
    FUN_409b84c0(param_3,param_2,iVar5 + 3,uVar2);
  }
  if (*(int *)(param_2 + 0x148) != -1) {
    if (*(int *)(param_1 + 0x490) != 0) {
      uVar4 = 0xffffffff;
    }
    if ((*(uint *)(param_1 + 0xc) & 0x4000000) != 0) {
      uVar3 = 0x40000000;
    }
    FUN_409b84c0(param_3,param_2,*(int *)(param_2 + 0x148),uVar3);
    uVar4 = __litofp(uVar4);
    uVar3 = __fpmul(uVar4,uVar3);
    FUN_409b84c0(param_3,param_2,*(int *)(param_2 + 0x148) + 1,uVar3);
  }
                    /* WARNING: Subroutine does not return */
  FUN_409da790(0x10);
}



/* 409b8784 FUN_409b8784 */

/* Boundary evidence: original MIPS .pdata 409b8784..409b87ff. Semantic name remains unreviewed. */

void FUN_409b8784(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  FUN_409da7c8();
  iVar2 = *(int *)(param_1 + 0x4d4);
  iVar3 = *(int *)(param_1 + 0x500);
  iVar1 = FUN_409da470(param_1,param_2,*(int *)(iVar2 + 0x24));
  if (iVar1 == 0) {
    iVar1 = *(int *)(param_1 + 0x504);
    if ((*(uint *)(iVar2 + 0x24) & 0xfffffff8) == 0) {
      *(uint *)(iVar1 + 0x3c) = *(uint *)(iVar1 + 0x3c) & 0xf;
    }
    else {
      *(uint *)(iVar1 + 0x3c) = *(uint *)(iVar1 + 0x3c) & 0xf ^ *(uint *)(iVar3 + 4);
    }
    FUN_409b8540(param_1,*(undefined4 *)(param_1 + 0x504));
  }
                    /* WARNING: Subroutine does not return */
  FUN_409da7e8(0x10);
}



/* 409b8800 FUN_409b8800 */

/* Boundary evidence: original MIPS .pdata 409b8800..409b89af. Semantic name remains unreviewed. */

void FUN_409b8800(undefined4 *param_1,undefined4 param_2,undefined4 param_3,int param_4)

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
  
  FUN_409da808();
  uVar7 = param_1[0x13d];
  iVar6 = param_1[0x135];
  iVar8 = param_1[0x140];
  puVar9 = (uint *)param_1[0x141];
  iVar1 = mali_frame_builder_incremental_rendering_requested(uVar7);
  if ((iVar1 != 1) || (iVar1 = FUN_409da508(param_1,uVar7), iVar1 == 0)) {
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
    iVar1 = FUN_409b940c(param_1,iVar8,uVar7,(int)(param_1 + 3));
    if (iVar1 == 0) {
      if (*(int *)(iVar6 + 0x16c) != 0) {
        FUN_409b84c0(iVar6,iVar6,*(int *)(iVar6 + 0x15c),param_1[0x105]);
        FUN_409b84c0(iVar6,iVar6,*(int *)(iVar6 + 0x160),param_1[0x106]);
        uVar2 = __fpsub(param_1[0x106],param_1[0x105]);
        FUN_409b84c0(iVar6,iVar6,*(int *)(iVar6 + 0x164),uVar2);
      }
      if (*(int *)(iVar6 + 0x170) != 0) {
        FUN_409b85cc((int)param_1,iVar6,iVar6);
      }
      iVar1 = FUN_409b8a68((undefined4 *)param_1[0x144],iVar8,uVar7,iVar6);
      if (iVar1 == 0) {
        *(undefined4 *)(iVar6 + 0xb4) = 0;
        iVar1 = mali_frame_builder_add_callback
                          (uVar7,mali_mem_ref_deref,*(undefined4 *)(iVar6 + 0x74));
        if (iVar1 == 0) {
          mali_sys_atomic_inc(*(undefined4 *)(iVar6 + 0x74));
          mali_frame_builder_update_fragment_stack
                    (uVar7,*(undefined4 *)(iVar6 + 0xa8),*(undefined4 *)(iVar6 + 0xa4));
          *(undefined4 *)(iVar8 + 0xc) = param_2;
          FUN_409b801c((int)param_1,iVar8,(int)puVar9,param_4);
          FUN_409b8370((int)param_1);
        }
      }
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_409da838(0x18);
}



/* 409b89b8 FUN_409b89b8 */

uint FUN_409b89b8(uint param_1)

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



/* 409b8a68 FUN_409b8a68 */

/* Boundary evidence: original MIPS .pdata 409b8a68..409b8b67. Semantic name remains unreviewed. */

undefined4 FUN_409b8a68(undefined4 *param_1,int param_2,undefined4 param_3,int param_4)

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
    iVar1 = FUN_409c1540(param_1,uVar4 << 3,local_28);
    piVar2 = (int *)FUN_409c1540(param_1,4,(int *)(param_2 + 0x20));
    if ((iVar1 == 0) || (piVar2 == (int *)0x0)) {
      return 0xffffffff;
    }
    *piVar2 = local_28[0];
    mali_sys_memcpy(iVar1,*(undefined4 *)(param_4 + 0x17c),iVar5 << 1);
    uVar3 = FUN_409b89b8((uVar3 >> 0x10 | uVar3) + 1);
    *(uint *)(param_2 + 0x24) = uVar3;
  }
  return 0;
}



/* 409b8b68 FUN_409b8b68 */

/* Boundary evidence: original MIPS .pdata 409b8b68..409b8c47. Semantic name remains unreviewed. */

int FUN_409b8b68(int param_1,int param_2,undefined4 param_3,undefined4 param_4,int param_5)

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



/* 409b8c5c FUN_409b8c5c */

/* Boundary evidence: original MIPS .pdata 409b8c5c..409b8ccb. Semantic name remains unreviewed. */

int FUN_409b8c5c(int param_1)

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



/* 409b8ccc FUN_409b8ccc */

/* Boundary evidence: original MIPS .pdata 409b8ccc..409b8d07. Semantic name remains unreviewed. */

undefined4 * FUN_409b8ccc(void)

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



/* 409b8d08 FUN_409b8d08 */

/* Boundary evidence: original MIPS .pdata 409b8d08..409b8d57. Semantic name remains unreviewed. */

void FUN_409b8d08(int *param_1)

{
  if (*param_1 != 0) {
    FUN_409b8c5c(*param_1);
    *param_1 = 0;
  }
  if (param_1[1] != 0) {
    FUN_409b8c5c(param_1[1]);
    param_1[1] = 0;
  }
  return;
}



/* 409b8d58 FUN_409b8d58 */

/* Boundary evidence: original MIPS .pdata 409b8d58..409b8d87. Semantic name remains unreviewed. */

void FUN_409b8d58(int *param_1)

{
  FUN_409b8d08(param_1);
  mali_sys_free(param_1);
  return;
}



/* 409b8d88 FUN_409b8d88 */

/* Boundary evidence: original MIPS .pdata 409b8d88..409b8e03. Semantic name remains unreviewed. */

void FUN_409b8d88(undefined4 param_1,undefined4 *param_2)

{
  int *piVar1;
  int iVar2;
  
  FUN_409da7c8();
  piVar1 = (int *)mali_sys_malloc(0x10);
  if (piVar1 != (int *)0x0) {
    piVar1[3] = 0;
    *piVar1 = 0;
    piVar1[1] = 0;
    piVar1[2] = 0;
    iVar2 = mali_surface_alloc_surface(*param_2,1,param_1);
    *piVar1 = iVar2;
    if (iVar2 == 0) {
      FUN_409b8d08(piVar1);
      mali_sys_free(piVar1);
    }
    else {
      piVar1[3] = param_2[3];
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_409da7e8(0x10);
}



/* 409b8e04 FUN_409b8e04 */

undefined4 FUN_409b8e04(int param_1,int param_2,int param_3)

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



/* 409b8e84 FUN_409b8e84 */

/* Boundary evidence: original MIPS .pdata 409b8e84..409b8ed7. Semantic name remains unreviewed. */

void FUN_409b8e84(uint *param_1)

{
  mali_sys_memset(param_1,0,0x40);
  *param_1 = *param_1 | 0x3f;
  param_1[1] = param_1[1] & 0xfffff7ff | 0x400;
  return;
}



/* 409b8ed8 FUN_409b8ed8 */

/* Boundary evidence: original MIPS .pdata 409b8ed8..409b8ef3. Semantic name remains unreviewed. */

void FUN_409b8ed8(int param_1)

{
  mali_sys_atomic_inc(param_1 + 0x188);
  return;
}



/* 409b8ef4 FUN_409b8ef4 */

/* Boundary evidence: original MIPS .pdata 409b8ef4..409b8f23. Semantic name remains unreviewed. */

void FUN_409b8ef4(int param_1)

{
  mali_sys_atomic_inc(param_1 + 4);
  mali_sys_atomic_inc(param_1 + 8);
  return;
}



/* 409b8f24 FUN_409b8f24 */

/* Boundary evidence: original MIPS .pdata 409b8f24..409b8f3f. Semantic name remains unreviewed. */

void FUN_409b8f24(void)

{
  mali_sys_atomic_inc();
  return;
}



/* 409b8f40 FUN_409b8f40 */

/* Boundary evidence: original MIPS .pdata 409b8f40..409b8f73. Semantic name remains unreviewed. */

undefined4 FUN_409b8f40(undefined4 *param_1)

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



/* 409b8f74 FUN_409b8f74 */

/* Boundary evidence: original MIPS .pdata 409b8f74..409b9033. Semantic name remains unreviewed. */

void FUN_409b8f74(uint *param_1,uint param_2)

{
  FUN_409b8e84(param_1);
  param_1[3] = param_1[3] & 0xe0010008 | 0x10008;
  param_1[1] = param_1[1] & 0xf000047f | 0x400;
  param_1[2] = param_1[2] & 0x3ff9ff | 0x400000;
  param_1[6] = param_1[6] & 0x3fff9fff | (param_2 >> 6) << 0x1e;
  param_1[7] = param_1[7] & 0xff000000 | param_2 >> 8;
  return;
}



/* 409b9034 FUN_409b9034 */

/* Boundary evidence: original MIPS .pdata 409b9034..409b907b. Semantic name remains unreviewed. */

undefined4 FUN_409b9034(int *param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  if ((((int *)param_1[7] == (int *)0x0) || (*(int *)param_1[7] == 0)) ||
     (iVar1 = FUN_409c6dd8(param_1), iVar1 == 0)) {
    uVar2 = 0;
  }
  else {
    uVar2 = 1;
  }
  return uVar2;
}



/* 409b907c FUN_409b907c */

/* Boundary evidence: original MIPS .pdata 409b907c..409b9227. Semantic name remains unreviewed. */

int FUN_409b907c(undefined4 *param_1,undefined4 param_2,int *param_3,undefined4 *param_4)

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
  iVar1 = FUN_409b9034(param_3);
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
    FUN_409b8f74(auStack_58,uVar3);
    mali_mem_write(*(undefined4 *)(*(int *)(param_3[0xd] + 0x178) + 4),0,auStack_58,0x40);
  }
  else if (*(int *)(param_3[0xd] + 0x184) == 1) {
    uVar2 = mali_mem_ref_alloc_mem(*param_1,0x40,0x40,1);
    *(undefined4 *)(param_3[0xd] + 0x178) = uVar2;
    if (*(int *)(param_3[0xd] + 0x178) == 0) {
      return -1;
    }
    iVar1 = FUN_409b9e68(*param_1,param_3);
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



/* 409b9228 FUN_409b9228 */

/* Boundary evidence: original MIPS .pdata 409b9228..409b940b. Semantic name remains unreviewed. */

void FUN_409b9228(undefined4 *param_1,undefined4 param_2,int param_3,int param_4,uint param_5)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint *puVar4;
  int *piVar5;
  int *in_stack_00000090;
  
  FUN_409da758();
  if (in_stack_00000090 == (int *)0x0) {
    iVar1 = FUN_409c1540((undefined4 *)param_1[0x144],0x40,(int *)&param_5);
    uVar3 = param_5;
    if (iVar1 == 0) goto LAB_409b9404;
    FUN_409b8f74((uint *)&stack0x00000018,param_5);
    mali_sys_memcpy(iVar1,&stack0x00000018,0x40);
  }
  else {
    iVar1 = mali_frame_builder_add_callback(param_2,FUN_409bbf28,in_stack_00000090[0xd]);
    if (iVar1 != 0) goto LAB_409b9404;
    mali_sys_atomic_inc(in_stack_00000090[0xd] + 0x188);
    iVar1 = 0;
    if (0 < in_stack_00000090[0x15]) {
      piVar5 = in_stack_00000090 + 0x16;
      do {
        iVar2 = mali_frame_builder_add_callback(param_2,&LAB_409b2600,*(undefined4 *)*piVar5);
        if (iVar2 != 0) goto LAB_409b9404;
        iVar2 = *(int *)*piVar5;
        mali_sys_atomic_inc(iVar2 + 4);
        mali_sys_atomic_inc(iVar2 + 8);
        iVar1 = iVar1 + 1;
        piVar5 = piVar5 + 1;
      } while (iVar1 < in_stack_00000090[0x15]);
    }
    if ((in_stack_00000090[0xe] != 0) || (*(int *)(in_stack_00000090[0xd] + 0x184) != 0)) {
      iVar1 = FUN_409b907c(param_1,in_stack_00000090[0xd] + 0x138,in_stack_00000090,&param_5);
      if (iVar1 != 0) goto LAB_409b9404;
      in_stack_00000090[0xe] = 0;
    }
    if (*(int *)(in_stack_00000090[0xd] + 0x178) == 0) {
      iVar1 = FUN_409c1540((undefined4 *)param_1[0x144],0x40,(int *)&param_5);
      if (iVar1 == 0) goto LAB_409b9404;
      mali_sys_memcpy(iVar1,in_stack_00000090[0xd] + 0x138,0x40);
      uVar3 = param_5;
    }
    else {
      iVar1 = mali_frame_builder_add_callback(param_2,mali_mem_ref_deref);
      if (iVar1 != 0) goto LAB_409b9404;
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
LAB_409b9404:
                    /* WARNING: Subroutine does not return */
  FUN_409da790(0x58);
}



/* 409b940c FUN_409b940c */

/* Boundary evidence: original MIPS .pdata 409b940c..409b94ef. Semantic name remains unreviewed. */

void FUN_409b940c(undefined4 *param_1,int param_2,undefined4 param_3,int param_4)

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
  
  FUN_409da758();
  iVar4 = *(int *)(in_stack_00000058 + 0x10);
  uStack00000018 = param_3;
  if (iVar4 == 0) {
    *(undefined4 *)(param_2 + 0x14) = 0;
    *(undefined4 *)(param_2 + 0x1c) = 0;
  }
  else {
    iVar1 = FUN_409c1540((undefined4 *)param_1[0x144],iVar4,&stack0x0000001c);
    if (iVar1 == 0) goto LAB_409b94e8;
    iVar6 = 0;
    if (0 < iVar4) {
      iVar7 = 0;
      pcVar5 = (char *)(param_4 + 800);
      do {
        if (*pcVar5 != '\0') {
          uVar2 = FUN_409b8e04(param_4,in_stack_00000058,iVar6);
          iVar3 = FUN_409b9228(param_1,uStack00000018,iVar1,
                               *(int *)(*(int *)(in_stack_00000058 + 0xc) + iVar7 + 4),uVar2);
          if (iVar3 != 0) goto LAB_409b94e8;
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
LAB_409b94e8:
                    /* WARNING: Subroutine does not return */
  FUN_409da790(0x20);
}



/* 409b9574 FUN_409b9574 */

/* Boundary evidence: original MIPS .pdata 409b9574..409b958f. Semantic name remains unreviewed. */

void FUN_409b9574(int param_1)

{
  mali_sys_atomic_inc(param_1 + 4);
  return;
}



/* 409b9590 FUN_409b9590 */

/* Boundary evidence: original MIPS .pdata 409b9590..409b95bf. Semantic name remains unreviewed. */

int FUN_409b9590(void)

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



/* 409b95c0 FUN_409b95c0 */

/* Boundary evidence: original MIPS .pdata 409b95c0..409b95f7. Semantic name remains unreviewed. */

int FUN_409b95c0(int *param_1,int param_2)

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



/* 409b95f8 FUN_409b95f8 */

uint FUN_409b95f8(uint param_1)

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



/* 409b96a8 FUN_409b96a8 */

/* Boundary evidence: original MIPS .pdata 409b96a8..409b9813. Semantic name remains unreviewed. */

void FUN_409b96a8(int param_1)

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
      uVar1 = FUN_409b95f8(((uVar1 >> 0x10 | uVar1) >> 1) + 1);
      *(uint *)(iVar3 + 0x13c) = uVar1 << 0x18 | *(uint *)(iVar3 + 0x13c) & 0xf00fffff;
    }
  }
  return;
}



/* 409b9814 FUN_409b9814 */

/* Boundary evidence: original MIPS .pdata 409b9814..409b9a37. Semantic name remains unreviewed. */

void FUN_409b9814(undefined4 *param_1,undefined4 param_2,int *param_3,int param_4)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int iStack0000002c;
  int in_stack_00000068;
  undefined4 in_stack_0000006c;
  int in_stack_00000070;
  
  FUN_409da758();
  uVar3 = *(undefined4 *)(*param_3 + 4);
  mali_surface_access_lock();
  iVar1 = FUN_409b8b68(param_4,in_stack_00000068,in_stack_0000006c,*(undefined4 *)(*param_3 + 0x18),
                       *(int *)(*param_3 + 0x20));
  iStack0000002c = mali_mem_ptr_map_area(**(undefined4 **)*param_3,uVar3,iVar1,1);
  if (iStack0000002c == 0) {
    mali_surface_access_unlock(*param_3);
  }
  else {
    iVar1 = FUN_409b8b68(param_4,in_stack_00000068,in_stack_0000006c,
                         *(undefined4 *)(*param_3 + 0x18),in_stack_00000070);
    iVar1 = mali_mem_ptr_map_area(*param_1,param_2,iVar1,1);
    if (iVar1 == 0) {
      mali_mem_ptr_unmap_area(**(undefined4 **)*param_3);
    }
    else {
      iVar4 = *param_3;
      iVar2 = *(int *)(iVar4 + 0x20);
      if (iVar2 != 0) {
        FUN_409bacdc(param_4,in_stack_00000068,iVar2);
      }
      __m200_texel_format_get_bpp(*(undefined4 *)(iVar4 + 0x18));
      if (in_stack_00000070 != 0) {
        FUN_409bacdc(param_4,in_stack_00000068,in_stack_00000070);
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
  FUN_409da790(0x30);
}



/* 409b9a38 FUN_409b9a38 */

/* Boundary evidence: original MIPS .pdata 409b9a38..409b9e67. Semantic name remains unreviewed. */

void FUN_409b9a38(int param_1,int param_2)

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
      FUN_409b96a8(param_1);
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



/* 409b9e68 FUN_409b9e68 */

/* Boundary evidence: original MIPS .pdata 409b9e68..409ba243. Semantic name remains unreviewed. */

void FUN_409b9e68(undefined4 param_1,int *param_2)

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
  
  FUN_409da758();
  puVar12 = (undefined4 *)0x0;
  uStack0000003c = param_1;
  iVar1 = FUN_409c6dd8(param_2);
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
      uVar4 = FUN_409b95f8(((uVar5 >> 0x10 | uVar5) >> 1) + 1);
      iVar1 = uVar4 + 1;
    }
    else {
      iVar1 = 1;
    }
    if (((int *)param_2[7] == (int *)0x0) || (*(int *)param_2[7] == 0)) {
      *(undefined4 *)(param_2[0xd] + 0x184) = 0;
      goto LAB_409ba238;
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
       puVar12 == (undefined4 *)0x0)) goto LAB_409ba238;
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
              goto LAB_409ba238;
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
              iVar3 = FUN_409b9814(puVar2,iStack00000020,*(int **)(iVar7 + param_2[0xd]),*piVar6);
              if (iVar3 != 0) {
                mali_shared_mem_ref_owner_deref(puVar2);
                if (puVar12 != (undefined4 *)0x0) {
                  mali_shared_mem_ref_owner_deref(puVar12);
                }
                goto LAB_409ba238;
              }
              iStack00000020 = iVar10 + iStack00000020;
              iStack00000030 = iStack00000030 + 1;
              iVar7 = iVar7 + 0x34;
            } while (iStack00000030 < iVar15);
          }
          FUN_409b9a38((int)param_2,iVar13);
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
LAB_409ba238:
                    /* WARNING: Subroutine does not return */
  FUN_409da790(0x48);
}



/* 409ba244 FUN_409ba244 */

/* Boundary evidence: original MIPS .pdata 409ba244..409ba303. Semantic name remains unreviewed. */

void FUN_409ba244(int *param_1,int param_2)

{
  undefined4 uVar1;
  int *piVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  undefined4 *puVar6;
  int iVar7;
  
  FUN_409da808();
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
  FUN_409da838(0x10);
}



/* 409ba304 FUN_409ba304 */

/* Boundary evidence: original MIPS .pdata 409ba304..409ba393. Semantic name remains unreviewed. */

undefined4 FUN_409ba304(int param_1)

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



/* 409ba3b0 FUN_409ba3b0 */

/* Boundary evidence: original MIPS .pdata 409ba3b0..409ba44f. Semantic name remains unreviewed. */

int FUN_409ba3b0(int *param_1)

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
        iVar2 = FUN_409b8b68((uint)*(ushort *)(iVar2 + 0xc),(uint)*(ushort *)(iVar2 + 0xe),piVar1[3]
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



/* 409ba450 FUN_409ba450 */

/* Boundary evidence: original MIPS .pdata 409ba450..409ba543. Semantic name remains unreviewed. */

void FUN_409ba450(int param_1,undefined1 *param_2,uint param_3,uint param_4,int param_5,int param_6)

{
  undefined1 uVar1;
  undefined1 uVar2;
  undefined1 uVar3;
  int iVar4;
  undefined1 *puVar5;
  
  uVar1 = (&DAT_409b1278)[(int)param_3 >> 8 & 0xf];
  uVar2 = (&DAT_409b1278)[(int)param_3 >> 4 & 0xf];
  uVar3 = (&DAT_409b1278)[param_3 & 0xf];
  if (0 < param_5) {
    do {
      puVar5 = (undefined1 *)
               ((uint)(uint3)(CONCAT21(CONCAT11((&DAT_409b1288)[(int)param_4 >> 8 & 0xf],
                                                (&DAT_409b1288)[(int)param_4 >> 4 & 0xf]),
                                       (&DAT_409b1288)[param_4 & 0xf]) ^
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



/* 409ba544 FUN_409ba544 */

/* Boundary evidence: original MIPS .pdata 409ba544..409ba627. Semantic name remains unreviewed. */

void FUN_409ba544(int param_1,int param_2,undefined1 *param_3,int param_4)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined1 *puVar5;
  int in_stack_00000020;
  int in_stack_00000024;
  int in_stack_00000028;
  
  FUN_409da7c8();
  iVar2 = param_2 + 0xf;
  if (iVar2 < 0) {
    iVar2 = param_2 + 0x1e;
  }
  iVar3 = param_4;
  if (param_4 < 0) {
    iVar3 = param_4 + 0xf;
  }
  bVar1 = (&DAT_409b1278)[param_4 % 0x10];
  if (0 < in_stack_00000024) {
    do {
      iVar4 = in_stack_00000020;
      if (in_stack_00000020 < 0) {
        iVar4 = in_stack_00000020 + 0xf;
      }
      puVar5 = (undefined1 *)
               ((uint)((&DAT_409b1288)[in_stack_00000020 % 0x10] ^ bVar1) * in_stack_00000028 +
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
  FUN_409da7e8(0);
}



/* 409ba664 FUN_409ba664 */

/* Boundary evidence: original MIPS .pdata 409ba664..409ba6b7. Semantic name remains unreviewed. */

void FUN_409ba664(uint *param_1)

{
  mali_sys_memset(param_1,0,0x40);
  *param_1 = *param_1 | 0x3f;
  param_1[1] = param_1[1] & 0xfffff7ff | 0x400;
  return;
}



/* 409ba6b8 FUN_409ba6b8 */

/* Boundary evidence: original MIPS .pdata 409ba6b8..409ba727. Semantic name remains unreviewed. */

int FUN_409ba6b8(int param_1)

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



/* 409ba728 FUN_409ba728 */

/* Boundary evidence: original MIPS .pdata 409ba728..409ba743. Semantic name remains unreviewed. */

void FUN_409ba728(int param_1)

{
  mali_sys_atomic_inc(param_1 + 0x34);
  return;
}



/* 409ba770 FUN_409ba770 */

/* Boundary evidence: original MIPS .pdata 409ba770..409ba78b. Semantic name remains unreviewed. */

void FUN_409ba770(int param_1)

{
  mali_sys_atomic_get(param_1 + 8);
  return;
}



/* 409ba7c0 FUN_409ba7c0 */

/* Boundary evidence: original MIPS .pdata 409ba7c0..409ba7ef. Semantic name remains unreviewed. */

int FUN_409ba7c0(void)

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



/* 409ba7f0 FUN_409ba7f0 */

/* Boundary evidence: original MIPS .pdata 409ba7f0..409ba827. Semantic name remains unreviewed. */

int FUN_409ba7f0(int *param_1,int param_2)

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



/* 409ba828 FUN_409ba828 */

/* Boundary evidence: original MIPS .pdata 409ba828..409ba8db. Semantic name remains unreviewed. */

void FUN_409ba828(int param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  int *piVar2;
  undefined4 in_stack_00000030;
  int *in_stack_00000034;
  
  FUN_409da7c8();
  piVar2 = *(int **)((param_2 * 0xd + param_3) * 4 + param_1);
  iVar1 = piVar2[1];
  *in_stack_00000034 = iVar1;
  if (iVar1 != 0) {
    FUN_409ba6b8(iVar1);
    piVar2[1] = 0;
  }
  mali_sys_atomic_inc(*piVar2 + 0x34);
  piVar2[1] = *piVar2;
  mali_sys_atomic_inc(*piVar2 + 0x34);
  iVar1 = mali_image_create_from_surface(*piVar2,in_stack_00000030);
  *(int *)(param_4 + 0x20) = iVar1;
  if (iVar1 == 0) {
    FUN_409ba6b8(*piVar2);
    FUN_409ba6b8(*piVar2);
    piVar2[1] = 0;
  }
  else {
    iVar1 = *(int *)(iVar1 + 0x10);
    *(undefined4 *)(iVar1 + 0x28) = *(undefined4 *)(param_1 + 0x180);
    *(undefined4 *)(iVar1 + 0x24) = *(undefined4 *)(param_1 + 0x17c);
  }
                    /* WARNING: Subroutine does not return */
  FUN_409da7e8(0x10);
}



/* 409ba8dc FUN_409ba8dc */

/* Boundary evidence: original MIPS .pdata 409ba8dc..409ba8f7. Semantic name remains unreviewed. */

void FUN_409ba8dc(undefined4 param_1,undefined4 *param_2,undefined4 *param_3)

{
  FUN_409bbf60(param_1,param_2,param_3);
  return;
}



/* 409ba8f8 FUN_409ba8f8 */

/* Boundary evidence: original MIPS .pdata 409ba8f8..409ba943. Semantic name remains unreviewed. */

undefined4 FUN_409ba8f8(int param_1,int param_2,int param_3)

{
  int iVar1;
  
  iVar1 = FUN_409c682c(param_2);
  return *(undefined4 *)((iVar1 * 0xd + param_3) * 4 + param_1);
}



/* 409ba944 FUN_409ba944 */

/* Boundary evidence: original MIPS .pdata 409ba944..409ba9a3. Semantic name remains unreviewed. */

undefined4 FUN_409ba944(int param_1,int param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  
  iVar1 = FUN_409c682c(param_2);
  piVar3 = (int *)((iVar1 * 0xd + param_3) * 4 + param_1);
  FUN_409ba6b8(*(int *)(*piVar3 + 4));
  iVar1 = *piVar3;
  uVar2 = *(undefined4 *)(iVar1 + 4);
  *(undefined4 *)(iVar1 + 4) = 0;
  return uVar2;
}



/* 409ba9a4 FUN_409ba9a4 */

/* Boundary evidence: original MIPS .pdata 409ba9a4..409baa23. Semantic name remains unreviewed. */

undefined4 FUN_409ba9a4(int param_1,int param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  
  iVar1 = FUN_409c682c(param_2);
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



/* 409baa24 FUN_409baa24 */

/* Boundary evidence: original MIPS .pdata 409baa24..409baa83. Semantic name remains unreviewed. */

undefined4 FUN_409baa24(int param_1,int param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_409c682c(param_2);
  iVar1 = *(int *)((iVar1 * 0xd + param_3) * 4 + param_1);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = *(undefined4 *)(iVar1 + 8);
  }
  return uVar2;
}



/* 409baa84 FUN_409baa84 */

/* Boundary evidence: original MIPS .pdata 409baa84..409baae7. Semantic name remains unreviewed. */

undefined4 FUN_409baa84(int param_1,int param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_409c682c(param_2);
  iVar1 = *(int *)((iVar1 * 0xd + param_3) * 4 + param_1);
  if ((iVar1 == 0) || (uVar2 = 1, *(int *)(iVar1 + 4) == 0)) {
    uVar2 = 0;
  }
  return uVar2;
}



/* 409baae8 FUN_409baae8 */

/* Boundary evidence: original MIPS .pdata 409baae8..409bacdb. Semantic name remains unreviewed. */

void FUN_409baae8(undefined4 param_1,int param_2,int param_3,int param_4)

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
  
  FUN_409da758();
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
              FUN_409ba450(iVar1,in_stack_00000078,iVar4 + in_stack_00000064,in_stack_00000060,
                           in_stack_00000068,iVar2);
              iVar4 = iVar4 + 1;
              in_stack_00000078 = in_stack_00000078 + in_stack_0000007c;
              piVar3 = piStack00000024;
            } while (iVar4 < in_stack_0000006c);
          }
        }
        else if ((iVar4 == 3) && (iVar2 = 0, 0 < in_stack_0000006c)) {
          do {
            FUN_409ba544(iVar1,(uint)*(ushort *)(*piVar3 + 0xc),puStack00000020,
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
  FUN_409da790(0x28);
}



/* 409bacdc FUN_409bacdc */

uint FUN_409bacdc(int param_1,int param_2,int param_3)

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



/* 409bad54 FUN_409bad54 */

/* Boundary evidence: original MIPS .pdata 409bad54..409bada7. Semantic name remains unreviewed. */

void FUN_409bad54(int param_1,int param_2,int param_3)

{
  int iVar1;
  
  iVar1 = FUN_409c682c(param_2);
  mali_surface_write_unlock(**(undefined4 **)((iVar1 * 0xd + param_3) * 4 + param_1));
  return;
}



/* 409bada8 FUN_409bada8 */

/* Boundary evidence: original MIPS .pdata 409bada8..409badff. Semantic name remains unreviewed. */

void FUN_409bada8(int param_1,int param_2,int param_3)

{
  int iVar1;
  
  iVar1 = FUN_409c682c(param_2);
  mali_surface_write_lock(**(undefined4 **)((iVar1 * 0xd + param_3) * 4 + param_1),0);
  return;
}



/* 409bae00 FUN_409bae00 */

/* Boundary evidence: original MIPS .pdata 409bae00..409bae67. Semantic name remains unreviewed. */

void FUN_409bae00(undefined4 *param_1)

{
  undefined4 *puVar1;
  
  puVar1 = param_1;
  do {
    *puVar1 = 0;
    puVar1 = puVar1 + 1;
  } while (puVar1 != param_1 + 0x4e);
  FUN_409ba664(param_1 + 0x4e);
  param_1[0x61] = 1;
  param_1[0x5f] = 0;
  param_1[0x60] = 0;
  mali_sys_atomic_initialize(param_1 + 0x62,1);
  param_1[0x5e] = 0;
  param_1[99] = 0;
  return;
}



/* 409bae68 FUN_409bae68 */

/* Boundary evidence: original MIPS .pdata 409bae68..409bb0b7. Semantic name remains unreviewed. */

void FUN_409bae68(int param_1,int param_2,int param_3,int param_4)

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
  
  FUN_409da758();
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
  FUN_409da790(0);
}



/* 409bb0b8 FUN_409bb0b8 */

/* Boundary evidence: original MIPS .pdata 409bb0b8..409bb37f. Semantic name remains unreviewed. */

void FUN_409bb0b8(int param_1,int param_2)

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



/* 409bb380 FUN_409bb380 */

/* Boundary evidence: original MIPS .pdata 409bb380..409bb40b. Semantic name remains unreviewed. */

void FUN_409bb380(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int *piVar1;
  int iVar2;
  
  FUN_409da688();
  piVar1 = (int *)mali_sys_malloc(0x10);
  if (piVar1 != (int *)0x0) {
    piVar1[3] = 0;
    *piVar1 = 0;
    piVar1[1] = 0;
    piVar1[2] = 0;
    iVar2 = mali_surface_alloc(param_2,param_3,0,param_4);
    *piVar1 = iVar2;
    if (iVar2 == 0) {
      FUN_409b8d08(piVar1);
      mali_sys_free(piVar1);
    }
    else {
      piVar1[3] = 0;
      *(undefined4 *)(iVar2 + 4) = 0;
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_409da6b0(0x18);
}



/* 409bb40c FUN_409bb40c */

/* Boundary evidence: original MIPS .pdata 409bb40c..409bb45f. Semantic name remains unreviewed. */

void FUN_409bb40c(int param_1,int param_2,int param_3)

{
  int *piVar1;
  undefined4 *puVar2;
  
  FUN_409da7c8();
  puVar2 = (undefined4 *)((param_2 * 0xd + param_3) * 4 + param_1);
  piVar1 = (int *)*puVar2;
  if (piVar1 != (int *)0x0) {
    FUN_409b8d08(piVar1);
    mali_sys_free(piVar1);
    *puVar2 = 0;
  }
                    /* WARNING: Subroutine does not return */
  *(undefined4 *)(param_1 + 0x184) = 1;
  FUN_409da7e8(0x10);
}



/* 409bb460 FUN_409bb460 */

/* Boundary evidence: original MIPS .pdata 409bb460..409bb4a3. Semantic name remains unreviewed. */

undefined4 * FUN_409bb460(void)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)mali_sys_malloc(400);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    FUN_409bae00(puVar1);
  }
  return puVar1;
}



/* 409bb4a4 FUN_409bb4a4 */

/* Boundary evidence: original MIPS .pdata 409bb4a4..409bb517. Semantic name remains unreviewed. */

void FUN_409bb4a4(undefined4 *param_1)

{
  undefined4 *puVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  
  FUN_409da688();
  iVar2 = 6;
  puVar1 = param_1;
  do {
    iVar4 = 0xd;
    do {
      piVar3 = (int *)*puVar1;
      if (piVar3 != (int *)0x0) {
        FUN_409b8d08(piVar3);
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
  FUN_409da6b0(0x10);
}



/* 409bb518 FUN_409bb518 */

/* Boundary evidence: original MIPS .pdata 409bb518..409bb663. Semantic name remains unreviewed. */

undefined4 FUN_409bb518(int param_1,int param_2,int param_3,int param_4,int param_5)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  
  iVar1 = FUN_409c682c(param_2);
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
    FUN_409bb40c(param_1,iVar1,param_3);
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



/* 409bb664 FUN_409bb664 */

/* Boundary evidence: original MIPS .pdata 409bb664..409bbc5f. Semantic name remains unreviewed. */

void FUN_409bb664(undefined4 param_1,int param_2,int param_3,int param_4)

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
  
  FUN_409da758();
  iVar10 = 0;
  uStack00000028 = param_1;
  iStack00000030 = param_2;
  iStack00000040 = param_3;
  if (in_stack_000000a0 == 0x8d64) {
    iStack0000003c = param_4;
    if (param_4 < 0) goto LAB_409bbc48;
  }
  else {
    if (0 < param_4) goto LAB_409bbc48;
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
      goto LAB_409bb9e0;
    }
    if (uVar3 != 0x1d4) goto LAB_409bbc48;
    iVar9 = 4;
    iStack0000002c = 2;
LAB_409bb720:
    iVar10 = 0;
    in_stack_00000050 = 0xffffffff;
    in_stack_00000054 = 0x20;
    in_stack_00000058 = 2;
    in_stack_0000005c = 3;
    in_stack_00000060 = 0;
    in_stack_00000064 = 0;
    goto switchD_409bba20_default;
  }
  iVar13 = 0x10;
  iStack0000002c = 2;
LAB_409bb9e0:
  iVar9 = 1;
  if (0x8d64 < in_stack_000000a0) goto switchD_409bba20_default;
  if (in_stack_000000a0 == 0x8d64) goto LAB_409bb720;
  switch(in_stack_000000a0) {
  case 0x8b90:
  case 0x8b95:
    FUN_409bc0e0(&stack0x00000050,0x1401,0x1907);
    iVar10 = iVar13 * 3;
    goto LAB_409bba58;
  case 0x8b91:
  case 0x8b96:
    FUN_409bc0e0(&stack0x00000050,0x1401,0x1908);
    iVar10 = iVar13 << 2;
    goto LAB_409bba58;
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
    goto switchD_409bba20_default;
  }
  FUN_409bc0e0(&stack0x00000050,iVar10,iVar12);
  iVar10 = iVar13 << 1;
LAB_409bba58:
  in_stack_0000005c = 0;
  in_stack_00000058 = 0;
switchD_409bba20_default:
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
      piVar2 = (int *)FUN_409bb380(uStack00000028,uVar3 & 0xffff,uVar6 & 0xffff,&stack0x00000050);
      if (piVar2 == (int *)0x0) goto LAB_409bbc48;
      piVar2[3] = 1;
      piVar14 = (int *)((iStack00000040 * 0xd + iVar12) * 4 + param_2);
      piVar8 = (int *)*piVar14;
      if (piVar8 != (int *)0x0) {
        FUN_409b8d08(piVar8);
        mali_sys_free(piVar8);
        *piVar14 = 0;
      }
      *piVar14 = (int)piVar2;
      mali_surface_access_lock(*piVar2);
      iVar13 = mali_mem_ptr_map_area(**(undefined4 **)*piVar2,0,((undefined4 *)*piVar2)[0xb],0x40);
      if (iVar13 == 0) {
        mali_surface_access_unlock(*piVar2);
        goto LAB_409bbc48;
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
            FUN_409bacdc((iVar4 / iVar9) * iVar9,(iVar7 / iVar9) * iVar9,in_stack_0000005c);
          }
          __m200_texel_format_get_bpp(in_stack_00000054);
          __m200_texel_format_get_bpp(in_stack_00000054);
          iStack00000034 = m200_texture_swizzle(iVar13,in_stack_0000005c,in_stack_000000b0,0);
          iVar10 = *(int *)(*piVar2 + 0x2c) + iVar10;
        }
        else {
          FUN_409bae68(in_stack_000000b0,iVar10,in_stack_000000a0,uVar3);
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
      if (iStack00000034 != 0) goto LAB_409bbc48;
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
LAB_409bbc48:
                    /* WARNING: Subroutine does not return */
  FUN_409da790(0x68);
}



/* 409bbc60 FUN_409bbc60 */

/* Boundary evidence: original MIPS .pdata 409bbc60..409bbdd7. Semantic name remains unreviewed. */

void FUN_409bbc60(undefined4 param_1,int param_2,int param_3,int param_4)

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
  
  FUN_409da758();
  FUN_409bc0e0((undefined4 *)&stack0x00000028,in_stack_00000084,in_stack_00000080);
  if ((0 < (int)in_stack_00000078) && (0 < (int)in_stack_0000007c)) {
    piVar1 = (int *)FUN_409bb380(param_1,in_stack_00000078 & 0xffff,in_stack_0000007c & 0xffff,
                                 &stack0x00000028);
    if (piVar1 == (int *)0x0) goto LAB_409bbdcc;
    piVar1[3] = 1;
    FUN_409bb40c(param_2,param_3,param_4);
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
        FUN_409b8d08(piVar1);
        mali_sys_free(piVar1);
        *piVar5 = 0;
        goto LAB_409bbdcc;
      }
    }
  }
  *(undefined4 *)(param_2 + 0x184) = 1;
  if (param_4 == 0) {
    *(undefined4 *)(param_2 + 0x180) = in_stack_0000003c;
    *(undefined4 *)(param_2 + 0x17c) = in_stack_00000038;
  }
LAB_409bbdcc:
                    /* WARNING: Subroutine does not return */
  FUN_409da790(0x40);
}



/* 409bbdd8 FUN_409bbdd8 */

/* Boundary evidence: original MIPS .pdata 409bbdd8..409bbe1b. Semantic name remains unreviewed. */

void FUN_409bbdd8(undefined4 *param_1)

{
  if (param_1[99] != 0) {
    mali_cmu_dec_cow_memory_usage();
  }
  FUN_409bb4a4(param_1);
  mali_sys_free(param_1);
  return;
}



/* 409bbe1c FUN_409bbe1c */

/* Boundary evidence: original MIPS .pdata 409bbe1c..409bbf27. Semantic name remains unreviewed. */

int * FUN_409bbe1c(undefined4 param_1,undefined4 *param_2)

{
  int *piVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  int iVar5;
  int iVar6;
  
  piVar1 = FUN_409bb460();
  if (piVar1 == (int *)0x0) {
LAB_409bbe5c:
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
          iVar2 = FUN_409b8d88(param_1,(undefined4 *)*puVar4);
          *(int *)(((int)piVar1 - (int)param_2) + (int)puVar4) = iVar2;
          if (iVar2 == 0) {
            FUN_409bbdd8(piVar1);
            goto LAB_409bbe5c;
          }
        }
        iVar6 = iVar6 + 1;
        puVar4 = puVar4 + 1;
      } while (iVar6 < 0xd);
      iVar5 = iVar5 + 1;
      puVar3 = puVar3 + 0xd;
    } while (iVar5 < 6);
    FUN_409bb0b8((int)piVar1,(int)param_2);
    iVar5 = FUN_409ba3b0(piVar1);
    piVar1[99] = iVar5;
    mali_cmu_inc_cow_memory_usage(iVar5);
    piVar1[0x60] = param_2[0x60];
    piVar1[0x5f] = param_2[0x5f];
  }
  return piVar1;
}



/* 409bbf28 FUN_409bbf28 */

/* Boundary evidence: original MIPS .pdata 409bbf28..409bbf5f. Semantic name remains unreviewed. */

void FUN_409bbf28(undefined4 *param_1)

{
  int iVar1;
  
  iVar1 = mali_sys_atomic_dec_and_return(param_1 + 0x62);
  if (iVar1 == 0) {
    FUN_409bbdd8(param_1);
  }
  return;
}



/* 409bbf60 FUN_409bbf60 */

/* Boundary evidence: original MIPS .pdata 409bbf60..409bc047. Semantic name remains unreviewed. */

void FUN_409bbf60(undefined4 param_1,undefined4 *param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  switch(param_1) {
  case 9:
    uVar1 = 0x1909;
    *param_2 = 0x1401;
    goto LAB_409bc038;
  case 10:
    uVar2 = 0x1906;
    break;
  case 0xb:
    uVar2 = 0x1401;
    uVar1 = 0x1906;
    goto LAB_409bbfe4;
  default:
    goto switchD_409bbf90_caseD_c;
  case 0xe:
    uVar2 = 0x8363;
    goto LAB_409bc030;
  case 0xf:
    uVar1 = 0x8034;
    uVar2 = 0x1908;
    goto LAB_409bbfd0;
  case 0x10:
    uVar2 = 0x8033;
    goto LAB_409bc008;
  case 0x11:
    uVar2 = 0x1401;
    uVar1 = 0x190a;
    goto LAB_409bc034;
  case 0x15:
    uVar2 = 0x1907;
    break;
  case 0x16:
    uVar2 = 0x1401;
LAB_409bc008:
    uVar1 = 0x1908;
LAB_409bbfe4:
    *param_2 = uVar2;
    *param_3 = uVar1;
    return;
  case 0x17:
    uVar2 = 0x1401;
LAB_409bc030:
    uVar1 = 0x1907;
LAB_409bc034:
    *param_2 = uVar2;
LAB_409bc038:
    *param_3 = uVar1;
    goto switchD_409bbf90_caseD_c;
  }
  uVar1 = 0x1401;
LAB_409bbfd0:
  *param_2 = uVar1;
  *param_3 = uVar2;
switchD_409bbf90_caseD_c:
  return;
}



/* 409bc074 FUN_409bc074 */

/* Boundary evidence: original MIPS .pdata 409bc074..409bc0df. Semantic name remains unreviewed. */

void FUN_409bc074(undefined4 *param_1)

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



/* 409bc0e0 FUN_409bc0e0 */

/* Boundary evidence: original MIPS .pdata 409bc0e0..409bc1a7. Semantic name remains unreviewed. */

void FUN_409bc0e0(undefined4 *param_1,int param_2,int param_3)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  
  iVar3 = 0;
  uVar1 = 0;
  while ((*(int *)((int)&DAT_409dd290 + uVar1) != param_2 ||
         (*(int *)((int)&DAT_409dd294 + uVar1) != param_3))) {
    uVar1 = uVar1 + 0x18;
    iVar3 = iVar3 + 1;
    if (0xef < uVar1) {
      FUN_409bc074(param_1);
      return;
    }
  }
  iVar3 = iVar3 * 0x18;
  uVar5 = *(undefined4 *)(iVar3 + 0x409dd2a4);
  uVar4 = *(undefined4 *)(iVar3 + 0x409dd2a0);
  uVar2 = *(undefined4 *)(iVar3 + 0x409dd29c);
  *param_1 = *(undefined4 *)(iVar3 + 0x409dd298);
  param_1[1] = uVar2;
  param_1[2] = 2;
  param_1[3] = 3;
  param_1[4] = uVar4;
  param_1[5] = uVar5;
  return;
}



/* 409bc1b0 FUN_409bc1b0 */

/* Boundary evidence: original MIPS .pdata 409bc1b0..409bc28f. Semantic name remains unreviewed. */

void FUN_409bc1b0(undefined4 param_1)

{
  undefined4 *puVar1;
  int iVar2;
  
  FUN_409da7c8();
  puVar1 = (undefined4 *)mali_sys_malloc(0x88);
  if (puVar1 != (undefined4 *)0x0) {
    mali_sys_memset(puVar1,0,0x88);
    mali_sys_atomic_initialize(puVar1 + 0x20,1);
    puVar1[2] = 0;
    puVar1[3] = 0;
    puVar1[5] = 1;
    puVar1[8] = 0;
    *puVar1 = 0;
    puVar1[1] = 0;
    puVar1[0xb] = 0;
    puVar1[0xc] = 0;
    puVar1[0xe] = 1;
    puVar1[0x11] = 0;
    puVar1[9] = 1;
    puVar1[10] = 1;
    puVar1[0x14] = 0;
    puVar1[0x15] = 0;
    puVar1[0x17] = 1;
    puVar1[0x1a] = 0;
    puVar1[0x12] = 2;
    puVar1[0x13] = 2;
    puVar1[0x1f] = 1;
    iVar2 = mali_frame_builder_alloc(param_1,0,1,0);
    puVar1[0x1b] = iVar2;
    puVar1[0x1c] = 0;
    if (iVar2 == 0) {
      mali_sys_free(puVar1);
    }
    else {
      puVar1[0x21] = 0;
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_409da7e8(0x18);
}



/* 409bc2e8 FUN_409bc2e8 */

/* Boundary evidence: original MIPS .pdata 409bc2e8..409bc303. Semantic name remains unreviewed. */

void FUN_409bc2e8(int param_1)

{
  mali_sys_atomic_inc(param_1 + 0x80);
  return;
}



/* 409bc3f0 FUN_409bc3f0 */

/* Boundary evidence: original MIPS .pdata 409bc3f0..409bc40b. Semantic name remains unreviewed. */

void FUN_409bc3f0(int param_1)

{
  mali_sys_atomic_inc(param_1 + 0x2c);
  return;
}



/* 409bc40c FUN_409bc40c */

/* Boundary evidence: original MIPS .pdata 409bc40c..409bc47b. Semantic name remains unreviewed. */

int FUN_409bc40c(int param_1)

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



/* 409bc47c FUN_409bc47c */

/* Boundary evidence: original MIPS .pdata 409bc47c..409bc497. Semantic name remains unreviewed. */

void FUN_409bc47c(int param_1)

{
  mali_sys_atomic_inc(param_1 + 0x34);
  return;
}



/* 409bc498 FUN_409bc498 */

/* Boundary evidence: original MIPS .pdata 409bc498..409bc4b3. Semantic name remains unreviewed. */

void FUN_409bc498(int param_1)

{
  mali_sys_atomic_inc(param_1 + 0x50);
  return;
}



/* 409bc4b4 FUN_409bc4b4 */

/* Boundary evidence: original MIPS .pdata 409bc4b4..409bc4ef. Semantic name remains unreviewed. */

undefined4 FUN_409bc4b4(int param_1,uint param_2)

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



/* 409bc4f0 FUN_409bc4f0 */

/* Boundary evidence: original MIPS .pdata 409bc4f0..409bc577. Semantic name remains unreviewed. */

void FUN_409bc4f0(int param_1,undefined4 *param_2,undefined4 *param_3,undefined4 *param_4)

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



/* 409bc578 FUN_409bc578 */

/* Boundary evidence: original MIPS .pdata 409bc578..409bc5d7. Semantic name remains unreviewed. */

void FUN_409bc578(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  FUN_409da7c8();
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
  FUN_409da7e8(0x10);
}



/* 409bc6f0 FUN_409bc6f0 */

undefined4 FUN_409bc6f0(int param_1,int param_2)

{
  uint uVar1;
  
  if (param_2 == 0x8ce0) {
    uVar1 = 0;
    do {
      if (param_1 == *(int *)((int)&DAT_409b1298 + uVar1)) {
        return 0x8cd5;
      }
      uVar1 = uVar1 + 4;
    } while (uVar1 < 0xc);
  }
  else if (param_2 == 0x8d00) {
    uVar1 = 0;
    do {
      if (param_1 == *(int *)((int)&DAT_409b12a4 + uVar1)) {
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
      if (param_1 == *(int *)((int)&DAT_409b12ac + uVar1)) {
        return 0x8cd5;
      }
      uVar1 = uVar1 + 4;
    } while (uVar1 < 4);
  }
  return 0x8cd6;
}



/* 409bc7c4 FUN_409bc7c4 */

/* Boundary evidence: original MIPS .pdata 409bc7c4..409bc95f. Semantic name remains unreviewed. */

undefined4 FUN_409bc7c4(int param_1,int param_2)

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
      iVar1 = FUN_409c682c(*(int *)(param_1 + 0x1c));
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



/* 409bc988 FUN_409bc988 */

void FUN_409bc988(int param_1,uint param_2,int param_3)

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



/* 409bc9ec FUN_409bc9ec */

/* Boundary evidence: original MIPS .pdata 409bc9ec..409bcab3. Semantic name remains unreviewed. */

void FUN_409bc9ec(int param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint local_18;
  uint local_14;
  uint local_10 [2];
  
  FUN_409bc4f0(*(int *)(param_1 + 0x484),&local_18,&local_14,local_10);
  uVar2 = 1;
  if ((((*(char *)(param_1 + 0x454) != '\0') || (*(char *)(param_1 + 0x455) != '\0')) ||
      (*(char *)(param_1 + 0x456) != '\0')) || (uVar1 = 0, *(char *)(param_1 + 0x457) != '\0')) {
    uVar1 = 1;
  }
  if ((*(char *)(param_1 + 0x458) == '\0') ||
     (uVar3 = 1, (*(uint *)(*(int *)(param_1 + 0x504) + 0x40) & 2) == 0)) {
    uVar3 = 0;
  }
  if ((*(int *)(param_1 + 0x45c) == 0) ||
     ((*(uint *)(*(int *)(param_1 + 0x504) + 0x40) & 0x10) == 0)) {
    uVar2 = 0;
  }
  FUN_409bc578(*(int *)(param_1 + 0x484),uVar1 | local_18,uVar3 | local_14,uVar2 | local_10[0]);
  return;
}



/* 409bcab4 FUN_409bcab4 */

/* Boundary evidence: original MIPS .pdata 409bcab4..409bcc7b. Semantic name remains unreviewed. */

int FUN_409bcab4(int param_1,undefined4 *param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int local_20 [2];
  
  uVar3 = 0;
  local_20[0] = 0;
  if (param_2[5] == 0) {
LAB_409bcc5c:
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
        FUN_409bc40c(iVar1);
      }
      mali_render_attachment_free(param_2[8]);
      param_2[8] = 0;
      mali_frame_builder_set_attachment(*(undefined4 *)(param_1 + 0x6c),param_2[1],0);
    }
    if (param_2[2] == 0x1702) {
      iVar1 = FUN_409c7034(param_2[4],param_2[7],param_2[6]);
      if (iVar1 != 0) {
        iVar1 = FUN_409c682c(param_2[7]);
        local_20[0] = **(int **)((iVar1 * 0xd + param_2[6]) * 4 + *(int *)(param_2[4] + 0x34));
        goto LAB_409bcbd8;
      }
    }
    else if ((param_2[2] != 0x8d41) || (local_20[0] = *(int *)(param_2[4] + 0x28), local_20[0] != 0)
            ) {
LAB_409bcbd8:
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
      goto LAB_409bcc5c;
    }
    iVar1 = -2;
  }
  return iVar1;
}



/* 409bcc7c FUN_409bcc7c */

/* Boundary evidence: original MIPS .pdata 409bcc7c..409bcdcb. Semantic name remains unreviewed. */

void FUN_409bcc7c(int param_1,int *param_2,int *param_3,int param_4)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  FUN_409da808();
  iVar5 = 0;
  iVar3 = 0;
  if (*(int *)(param_1 + 8) == 0x1702) {
    iVar4 = *(int *)(param_1 + 0x10);
    if ((*(int **)(iVar4 + 0x1c) != (int *)0x0) && (**(int **)(iVar4 + 0x1c) != 0)) {
      iVar1 = FUN_409c682c(*(int *)(param_1 + 0x1c));
      piVar2 = *(int **)(*(int *)((iVar1 + 7) * 4 + iVar4) + *(int *)(param_1 + 0x18) * 4);
      iVar5 = *piVar2;
      iVar3 = piVar2[1];
      if ((param_4 != 0x8ce0) ||
         (*(int *)(**(int **)((iVar1 * 0xd + *(int *)(param_1 + 0x18)) * 4 + *(int *)(iVar4 + 0x34))
                  + 0x14) == -1)) goto LAB_409bcdc0;
    }
  }
  else if (*(int *)(param_1 + 8) == 0x8d41) {
    FUN_409bc6f0(**(int **)(param_1 + 0x10),param_4);
    iVar5 = *(int *)(*(int *)(param_1 + 0x10) + 4);
    iVar3 = *(int *)(*(int *)(param_1 + 0x10) + 8);
  }
  if (*param_2 == -1) {
    *param_2 = iVar5;
  }
  if (*param_3 == -1) {
    *param_3 = iVar3;
  }
LAB_409bcdc0:
                    /* WARNING: Subroutine does not return */
  FUN_409da838(0x10);
}



/* 409bce10 FUN_409bce10 */

/* Boundary evidence: original MIPS .pdata 409bce10..409bcf27. Semantic name remains unreviewed. */

undefined4 FUN_409bce10(int param_1)

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
    goto LAB_409bcee4;
  }
  if (iVar3 != -0x48) {
    if (*(int *)(iVar3 + 0x50) == 0x1702) {
      iVar1 = FUN_409c682c(*(int *)(iVar3 + 100));
      piVar4 = *(int **)((iVar1 * 0xd + *(int *)(iVar3 + 0x60)) * 4 +
                        *(int *)(*(int *)(iVar3 + 0x58) + 0x34));
      if (piVar4 != (int *)0x0) {
        iVar3 = *piVar4;
        goto LAB_409bce9c;
      }
    }
    else if (*(int *)(iVar3 + 0x50) == 0x8d41) {
      iVar3 = *(int *)(*(int *)(iVar3 + 0x58) + 0x28);
LAB_409bce9c:
      if (iVar3 != 0) {
        mali_pixel_format_get_bpc
                  (*(undefined4 *)(iVar3 + 0x14),auStack_14,auStack_18,auStack_1c,auStack_20,
                   auStack_24,&local_28);
        goto LAB_409bcee4;
      }
    }
  }
  local_28 = 0;
LAB_409bcee4:
  uVar2 = 1;
  if (((*(uint *)(*(int *)(param_1 + 0x504) + 0x40) & 0x10) == 0) || (local_28 < 1)) {
    uVar2 = 0;
  }
  return uVar2;
}



/* 409bcf28 FUN_409bcf28 */

/* Boundary evidence: original MIPS .pdata 409bcf28..409bd03f. Semantic name remains unreviewed. */

undefined4 FUN_409bcf28(int param_1)

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
    goto LAB_409bcffc;
  }
  if (iVar3 != -0x24) {
    if (*(int *)(iVar3 + 0x2c) == 0x1702) {
      iVar1 = FUN_409c682c(*(int *)(iVar3 + 0x40));
      piVar4 = *(int **)((iVar1 * 0xd + *(int *)(iVar3 + 0x3c)) * 4 +
                        *(int *)(*(int *)(iVar3 + 0x34) + 0x34));
      if (piVar4 != (int *)0x0) {
        iVar3 = *piVar4;
        goto LAB_409bcfb4;
      }
    }
    else if (*(int *)(iVar3 + 0x2c) == 0x8d41) {
      iVar3 = *(int *)(*(int *)(iVar3 + 0x34) + 0x28);
LAB_409bcfb4:
      if (iVar3 != 0) {
        mali_pixel_format_get_bpc
                  (*(undefined4 *)(iVar3 + 0x14),auStack_14,auStack_18,auStack_1c,auStack_20,
                   &local_28,auStack_24);
        goto LAB_409bcffc;
      }
    }
  }
  local_28 = 0;
LAB_409bcffc:
  uVar2 = 1;
  if (((*(uint *)(*(int *)(param_1 + 0x504) + 0x40) & 2) == 0) || (local_28 < 1)) {
    uVar2 = 0;
  }
  return uVar2;
}



/* 409bd040 FUN_409bd040 */

/* Boundary evidence: original MIPS .pdata 409bd040..409bd213. Semantic name remains unreviewed. */

void FUN_409bd040(int param_1,uint param_2,int param_3,uint param_4,byte param_5)

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
  FUN_409bc988(param_1,(uint)*(byte *)(iVar3 + 0x46),(uint)*(byte *)(iVar3 + 0x47));
  if (*(int *)(param_1 + 0x484) == 0) {
    iVar1 = *(int *)(param_1 + 0x4a0);
  }
  else {
    iVar1 = FUN_409bc7c4(*(int *)(param_1 + 0x484),0xd55);
  }
  if (iVar1 != 0) goto LAB_409bd190;
  if (param_2 == 4) {
LAB_409bd10c:
    param_2 = 3;
  }
  else if (param_2 == 0x11) {
    param_2 = 0xb;
  }
  else if (param_2 == 0x19) goto LAB_409bd10c;
  if (param_3 == 4) {
LAB_409bd12c:
    param_3 = 3;
  }
  else if (param_3 == 0x11) {
    param_3 = 0xb;
  }
  else if (param_3 == 0x19) goto LAB_409bd12c;
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
LAB_409bd190:
  if (param_4 == 4) {
    param_4 = 0xb;
  }
  *(uint *)(iVar3 + 8) =
       ((param_2 & 0xffffc01f ^ param_3 << 5) << 6 ^ *(uint *)(iVar3 + 8) & 0xfff0003f) & 0xff0fffff
       ^ ((uVar2 & 0xf) << 4 ^ param_4 & 0xf) << 0x10;
  return;
}



/* 409bd214 FUN_409bd214 */

/* Boundary evidence: original MIPS .pdata 409bd214..409bd277. Semantic name remains unreviewed. */

int FUN_409bd214(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_409bcab4(param_1,(undefined4 *)param_1);
  if (((iVar1 == 0) && (iVar1 = FUN_409bcab4(param_1,(undefined4 *)(param_1 + 0x24)), iVar1 == 0))
     && (iVar1 = FUN_409bcab4(param_1,(undefined4 *)(param_1 + 0x48)), iVar1 == 0)) {
    *(undefined4 *)(param_1 + 0x7c) = 0;
    iVar1 = 0;
  }
  return iVar1;
}



/* 409bd278 FUN_409bd278 */

/* Boundary evidence: original MIPS .pdata 409bd278..409bd333. Semantic name remains unreviewed. */

void FUN_409bd278(int param_1)

{
  int iVar1;
  int iStack00000010;
  int iStack00000014;
  
  FUN_409da7c8();
  iStack00000014 = -1;
  iStack00000010 = -1;
  if ((((*(int *)(param_1 + 8) == 0) ||
       (iVar1 = FUN_409bcc7c(param_1,&stack0x00000014,&stack0x00000010,0x8ce0), iVar1 == 0x8cd5)) &&
      ((*(int *)(param_1 + 0x2c) == 0 ||
       (iVar1 = FUN_409bcc7c(param_1 + 0x24,&stack0x00000014,&stack0x00000010,0x8d00),
       iVar1 == 0x8cd5)))) && (*(int *)(param_1 + 0x50) != 0)) {
    FUN_409bcc7c(param_1 + 0x48,&stack0x00000014,&stack0x00000010,0x8d20);
  }
                    /* WARNING: Subroutine does not return */
  FUN_409da7e8(0x18);
}



/* 409bd334 FUN_409bd334 */

void FUN_409bd334(int param_1,int param_2)

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
    if (((*(uint *)(*(int *)(param_1 + 0x504) + 0x40) & 0x20) != 0) && (bVar1)) goto LAB_409bd394;
  }
  iVar2 = 0;
LAB_409bd394:
  *(uint *)(iVar3 + 0x20) = *(uint *)(iVar3 + 0x20) & 0xfffffeff ^ iVar2 << 8;
  return;
}



/* 409bd3b4 FUN_409bd3b4 */

void FUN_409bd3b4(int param_1,int param_2)

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
    if (((*(uint *)(*(int *)(param_1 + 0x504) + 0x40) & 0x20) != 0) && (bVar1)) goto LAB_409bd414;
  }
  iVar2 = 0;
LAB_409bd414:
  *(uint *)(iVar3 + 0x20) = *(uint *)(iVar3 + 0x20) & 0xffffff7f ^ iVar2 << 7;
  return;
}



/* 409bd434 FUN_409bd434 */

void FUN_409bd434(int param_1)

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



/* 409bd4b8 FUN_409bd4b8 */

/* Boundary evidence: original MIPS .pdata 409bd4b8..409bd5db. Semantic name remains unreviewed. */

void FUN_409bd4b8(int param_1,undefined4 param_2,int param_3)

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



/* 409bd5dc FUN_409bd5dc */

/* Boundary evidence: original MIPS .pdata 409bd5dc..409bd637. Semantic name remains unreviewed. */

void FUN_409bd5dc(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0x504);
  *(char *)(iVar2 + 0x59) = (char)param_2;
  iVar1 = FUN_409bce10(param_1);
  if (iVar1 == 0) {
    param_2 = 0;
  }
  *(uint *)(iVar2 + 0x1c) = param_2 << 8 ^ *(uint *)(iVar2 + 0x1c) & 0xffff00ff;
  return;
}



/* 409bd638 FUN_409bd638 */

/* Boundary evidence: original MIPS .pdata 409bd638..409bd68f. Semantic name remains unreviewed. */

void FUN_409bd638(int param_1,uint param_2)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0x504);
  *(char *)(iVar2 + 0x52) = (char)param_2;
  iVar1 = FUN_409bce10(param_1);
  if (iVar1 == 0) {
    param_2 = 0;
  }
  *(uint *)(iVar2 + 0x1c) = *(uint *)(iVar2 + 0x1c) & 0xffffff00 ^ param_2;
  return;
}



/* 409bd690 FUN_409bd690 */

/* Boundary evidence: original MIPS .pdata 409bd690..409bd737. Semantic name remains unreviewed. */

void FUN_409bd690(int param_1,uint param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0x504);
  *(char *)(iVar2 + 0x5a) = (char)param_2;
  *(char *)(iVar2 + 0x5b) = (char)param_3;
  *(char *)(iVar2 + 0x5c) = (char)param_4;
  iVar1 = FUN_409bce10(param_1);
  if (iVar1 == 0) {
    param_3 = 0;
    param_4 = 0;
  }
  *(uint *)(iVar2 + 0x18) =
       ((param_2 & 0xffffffc7 ^ param_3 << 3) << 3 ^ *(uint *)(iVar2 + 0x18) & 0xfffffe07) &
       0xfffff1ff ^ param_4 << 9;
  return;
}



/* 409bd738 FUN_409bd738 */

/* Boundary evidence: original MIPS .pdata 409bd738..409bd7df. Semantic name remains unreviewed. */

void FUN_409bd738(int param_1,uint param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0x504);
  *(char *)(iVar2 + 0x53) = (char)param_2;
  *(char *)(iVar2 + 0x54) = (char)param_3;
  *(char *)(iVar2 + 0x55) = (char)param_4;
  iVar1 = FUN_409bce10(param_1);
  if (iVar1 == 0) {
    param_3 = 0;
    param_4 = 0;
  }
  *(uint *)(iVar2 + 0x14) =
       ((param_2 & 0xffffffc7 ^ param_3 << 3) << 3 ^ *(uint *)(iVar2 + 0x14) & 0xfffffe07) &
       0xfffff1ff ^ param_4 << 9;
  return;
}



/* 409bd7e0 FUN_409bd7e0 */

/* Boundary evidence: original MIPS .pdata 409bd7e0..409bd893. Semantic name remains unreviewed. */

void FUN_409bd7e0(int param_1,uint param_2,uint param_3,uint param_4)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  
  iVar3 = *(int *)(param_1 + 0x504);
  *(uint *)(iVar3 + 0x88) = param_4;
  *(char *)(iVar3 + 0x56) = (char)param_2;
  *(char *)(iVar3 + 0x57) = (char)param_3;
  *(char *)(iVar3 + 0x58) = (char)param_4;
  iVar1 = FUN_409bce10(param_1);
  if (iVar1 == 0) {
    param_2 = 7;
  }
  uVar2 = (*(uint *)(iVar3 + 0x18) & 0xfffffff8 ^ param_2) & 0xff00ffff ^
          (param_3 & param_4) << 0x10;
  *(uint *)(iVar3 + 0x18) = uVar2;
  *(uint *)(iVar3 + 0x18) = uVar2 & 0xffffff ^ (uint)*(byte *)(iVar3 + 0x51) << 0x18;
  return;
}



/* 409bd894 FUN_409bd894 */

/* Boundary evidence: original MIPS .pdata 409bd894..409bd947. Semantic name remains unreviewed. */

void FUN_409bd894(int param_1,uint param_2,uint param_3,uint param_4)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  
  iVar3 = *(int *)(param_1 + 0x504);
  *(uint *)(iVar3 + 0x84) = param_4;
  *(char *)(iVar3 + 0x4f) = (char)param_2;
  *(char *)(iVar3 + 0x50) = (char)param_3;
  *(char *)(iVar3 + 0x51) = (char)param_4;
  iVar1 = FUN_409bce10(param_1);
  if (iVar1 == 0) {
    param_2 = 7;
  }
  uVar2 = (*(uint *)(iVar3 + 0x14) & 0xfffffff8 ^ param_2) & 0xff00ffff ^
          (param_3 & param_4) << 0x10;
  *(uint *)(iVar3 + 0x14) = uVar2;
  *(uint *)(iVar3 + 0x14) = uVar2 & 0xffffff ^ (uint)*(byte *)(iVar3 + 0x51) << 0x18;
  return;
}



/* 409bd948 FUN_409bd948 */

/* Boundary evidence: original MIPS .pdata 409bd948..409bd9a3. Semantic name remains unreviewed. */

void FUN_409bd948(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0x504);
  *(char *)(iVar2 + 0x4d) = (char)param_2;
  iVar1 = FUN_409bcf28(param_1);
  if (iVar1 == 0) {
    param_2 = 7;
  }
  *(uint *)(iVar2 + 0xc) = param_2 << 1 ^ *(uint *)(iVar2 + 0xc) & 0xfffffff1;
  return;
}



/* 409bd9a4 FUN_409bd9a4 */

/* Boundary evidence: original MIPS .pdata 409bd9a4..409bd9f3. Semantic name remains unreviewed. */

void FUN_409bd9a4(int param_1,uint param_2)

{
  uint uVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0x504);
  *(char *)(iVar2 + 0x4e) = (char)param_2;
  uVar1 = FUN_409bcf28(param_1);
  *(uint *)(iVar2 + 0xc) = *(uint *)(iVar2 + 0xc) & 0xfffffffe ^ uVar1 & param_2;
  return;
}



/* 409bd9f4 FUN_409bd9f4 */

/* Boundary evidence: original MIPS .pdata 409bd9f4..409bda3f. Semantic name remains unreviewed. */

void FUN_409bd9f4(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x504);
  *(uint *)(iVar1 + 0x40) = *(uint *)(iVar1 + 0x40) & 0xfffffffb | param_2 << 2;
  FUN_409bd040(param_1,(uint)*(byte *)(iVar1 + 0x48),(uint)*(byte *)(iVar1 + 0x49),
               (uint)*(byte *)(iVar1 + 0x4a),*(byte *)(iVar1 + 0x4b));
  return;
}



/* 409bda40 FUN_409bda40 */

/* Boundary evidence: original MIPS .pdata 409bda40..409bdafb. Semantic name remains unreviewed. */

void FUN_409bda40(undefined4 *param_1,int param_2)

{
  int iVar1;
  
  FUN_409da7c8();
  if (*(int *)(param_2 + 0x68) != 0 ||
      (*(int *)(param_2 + 0x44) != 0 || *(int *)(param_2 + 0x20) != 0)) {
    iVar1 = mali_frame_builder_flush(*(undefined4 *)(param_2 + 0x6c),0,0);
    if (iVar1 == 0) {
      mali_frame_builder_wait(*(undefined4 *)(param_2 + 0x6c));
      FUN_409c4b20((int)param_1);
    }
    else {
      mali_frame_builder_reset(param_1[0x13d]);
      iVar1 = FUN_409c508c(param_1);
      if (iVar1 == 0) {
        FUN_409c1638((undefined4 *)param_1[0x144]);
      }
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_409da7e8(0x10);
}



/* 409bdafc FUN_409bdafc */

/* Boundary evidence: original MIPS .pdata 409bdafc..409bdb57. Semantic name remains unreviewed. */

undefined4 FUN_409bdafc(int *param_1,int param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  
  if (param_2 == 0x8d40) {
    if (param_1[1] == 0) {
      *param_3 = 0x8cd5;
    }
    else {
      uVar1 = FUN_409bd278(*param_1);
      *param_3 = uVar1;
    }
    uVar1 = 0;
  }
  else {
    *param_3 = 0;
    uVar1 = 0x500;
  }
  return uVar1;
}



/* 409bdb58 FUN_409bdb58 */

/* Boundary evidence: original MIPS .pdata 409bdb58..409bdbe3. Semantic name remains unreviewed. */

void FUN_409bdb58(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x504);
  *(uint *)(iVar1 + 0x40) = *(uint *)(iVar1 + 0x40) & 0xffffffdf | param_2 << 5;
  FUN_409bd434(param_1);
  FUN_409bd4b8(param_1,*(undefined4 *)(iVar1 + 0x60),(uint)*(byte *)(iVar1 + 100));
  FUN_409bd334(param_1,*(uint *)(iVar1 + 0x40) >> 0xb & 1);
  FUN_409bd3b4(param_1,*(uint *)(iVar1 + 0x40) >> 10 & 1);
  return;
}



/* 409bdbe4 FUN_409bdbe4 */

/* Boundary evidence: original MIPS .pdata 409bdbe4..409bdc9b. Semantic name remains unreviewed. */

void FUN_409bdbe4(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x504);
  *(uint *)(iVar1 + 0x40) = *(uint *)(iVar1 + 0x40) & 0xffffffef | param_2 << 4;
  FUN_409bd894(param_1,(uint)*(byte *)(iVar1 + 0x4f),(uint)*(byte *)(iVar1 + 0x50),
               (uint)*(byte *)(iVar1 + 0x51));
  FUN_409bd638(param_1,(uint)*(byte *)(iVar1 + 0x52));
  FUN_409bd738(param_1,(uint)*(byte *)(iVar1 + 0x53),(uint)*(byte *)(iVar1 + 0x54),
               (uint)*(byte *)(iVar1 + 0x55));
  FUN_409bd7e0(param_1,(uint)*(byte *)(iVar1 + 0x56),(uint)*(byte *)(iVar1 + 0x57),
               (uint)*(byte *)(iVar1 + 0x58));
  FUN_409bd5dc(param_1,(uint)*(byte *)(iVar1 + 0x59));
  FUN_409bd690(param_1,(uint)*(byte *)(iVar1 + 0x5a),(uint)*(byte *)(iVar1 + 0x5b),
               (uint)*(byte *)(iVar1 + 0x5c));
  return;
}



/* 409bdc9c FUN_409bdc9c */

/* Boundary evidence: original MIPS .pdata 409bdc9c..409bdcfb. Semantic name remains unreviewed. */

void FUN_409bdc9c(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x504);
  *(uint *)(iVar1 + 0x40) = *(uint *)(iVar1 + 0x40) & 0xfffffffd | param_2 << 1;
  FUN_409bd948(param_1,(uint)*(byte *)(iVar1 + 0x4d));
  FUN_409bd9a4(param_1,(uint)*(byte *)(iVar1 + 0x4e));
  return;
}



/* 409bdcfc FUN_409bdcfc */

/* Boundary evidence: original MIPS .pdata 409bdcfc..409bddab. Semantic name remains unreviewed. */

void FUN_409bdcfc(int param_1)

{
  int iVar1;
  
  FUN_409bdc9c(param_1,*(uint *)(*(int *)(param_1 + 0x504) + 0x40) >> 1 & 1);
  FUN_409bdbe4(param_1,*(uint *)(*(int *)(param_1 + 0x504) + 0x40) >> 4 & 1);
  iVar1 = *(int *)(param_1 + 0x504);
  *(uint *)(iVar1 + 0x40) =
       *(uint *)(iVar1 + 0x40) & 0xfffffffb | (*(uint *)(iVar1 + 0x40) >> 2 & 1) << 2;
  FUN_409bd040(param_1,(uint)*(byte *)(iVar1 + 0x48),(uint)*(byte *)(iVar1 + 0x49),
               (uint)*(byte *)(iVar1 + 0x4a),*(byte *)(iVar1 + 0x4b));
  FUN_409bdb58(param_1,*(uint *)(*(int *)(param_1 + 0x504) + 0x40) >> 5 & 1);
  return;
}



/* 409bddac FUN_409bddac */

/* Boundary evidence: original MIPS .pdata 409bddac..409bde6f. Semantic name remains unreviewed. */

undefined4 FUN_409bddac(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0x484);
  if (*(int *)(iVar2 + 0x7c) == 1) {
    iVar1 = FUN_409bd278(iVar2);
    if (iVar1 != 0x8cd5) {
      return 0x506;
    }
    iVar1 = mali_frame_builder_flush(*(undefined4 *)(iVar2 + 0x6c),0,0);
    if ((iVar1 == 0) && (iVar1 = FUN_409bd214(iVar2), iVar1 == 0)) {
      FUN_409bdcfc(param_1);
      *(uint *)(param_1 + 0xc) = *(uint *)(param_1 + 0xc) | 0x2000000;
    }
    else if ((iVar1 != -3) && ((-3 < iVar1 && (iVar1 < 0)))) {
      return 0x505;
    }
  }
  return 0;
}



/* 409bde70 FUN_409bde70 */

/* Boundary evidence: original MIPS .pdata 409bde70..409bdf33. Semantic name remains unreviewed. */

void FUN_409bde70(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  FUN_409da7c8();
  if (*(int *)(param_1 + 8) == 0x1702) {
    iVar1 = FUN_409c7034(*(int *)(param_1 + 0x10),*(int *)(param_1 + 0x1c),*(int *)(param_1 + 0x18))
    ;
    FUN_409bec20(*(undefined4 *)(iVar1 + 0x14),param_2,param_1);
    iVar2 = *(int *)(param_1 + 0x10);
    iVar1 = mali_sys_atomic_dec_and_return(iVar2 + 0x50);
    if (iVar1 == 0) {
      FUN_409c7b60(iVar2);
    }
  }
  else {
    if (*(int *)(param_1 + 8) != 0x8d41) goto LAB_409bdf14;
    FUN_409bec20(*(undefined4 *)(*(int *)(param_1 + 0x10) + 0x30),param_2,param_1);
    iVar2 = *(int *)(param_1 + 0x10);
    iVar1 = mali_sys_atomic_dec_and_return(iVar2 + 0x2c);
    if (iVar1 == 0) {
      FUN_409bf59c(iVar2);
    }
  }
  *(undefined4 *)(param_1 + 0x10) = 0;
LAB_409bdf14:
  *(undefined4 *)(param_1 + 8) = 0;
  *(undefined4 *)(param_1 + 0xc) = 0;
  *(undefined4 *)(param_1 + 0x18) = 0;
  *(undefined4 *)(param_1 + 0x14) = 1;
                    /* WARNING: Subroutine does not return */
  *(undefined4 *)(param_2 + 0x7c) = 1;
  FUN_409da7e8(0x10);
}



/* 409bdf34 FUN_409bdf34 */

/* Boundary evidence: original MIPS .pdata 409bdf34..409be1eb. Semantic name remains unreviewed. */

void FUN_409bdf34(undefined4 *param_1,int *param_2)

{
  bool bVar1;
  undefined4 *puVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  int *piVar6;
  int in_stack_00000060;
  int in_stack_00000064;
  int in_stack_00000068;
  int in_stack_0000006c;
  uint in_stack_00000070;
  int in_stack_00000074;
  
  FUN_409da758();
  uVar4 = 0;
  do {
    if (in_stack_0000006c == *(int *)((int)&DAT_409b12b0 + uVar4)) {
      bVar1 = true;
      goto LAB_409bdf84;
    }
    uVar4 = uVar4 + 4;
  } while (uVar4 < 0x18);
  bVar1 = false;
LAB_409bdf84:
  if ((((in_stack_0000006c == 0xde1) || (bVar1)) && (in_stack_00000064 == 0x8d40)) &&
     ((in_stack_00000074 == 0 && (iVar3 = *param_2, iVar3 != 0)))) {
    if (in_stack_00000068 == 0x8d00) {
      iVar5 = iVar3 + 0x24;
    }
    else if (in_stack_00000068 == 0x8d20) {
      iVar5 = iVar3 + 0x48;
    }
    else {
      iVar5 = iVar3;
      if (in_stack_00000068 != 0x8ce0) goto LAB_409be1e4;
    }
    if (iVar5 != 0) {
      if (in_stack_00000070 == 0) {
        FUN_409bde70(iVar5,iVar3);
        *(undefined4 *)(*param_2 + 0x7c) = 1;
        *(undefined4 *)(iVar5 + 0x14) = 1;
      }
      else {
        if (in_stack_00000070 < 0x100) {
          iVar3 = *(int *)((in_stack_00000070 + 7) * 4 + in_stack_00000060);
        }
        else {
          iVar3 = __mali_named_list_get_non_flat(in_stack_00000060,in_stack_00000070);
        }
        if (((((iVar3 != 0) && (piVar6 = *(int **)(iVar3 + 4), piVar6 != (int *)0x0)) &&
             ((*(int *)(iVar5 + 8) != 0x1702 || (*(int **)(iVar5 + 0x10) != piVar6)))) &&
            ((*piVar6 != 0 || (!bVar1)))) && ((*piVar6 != 1 || (bVar1)))) {
          FUN_409bde70(iVar5,*param_2);
          *(undefined4 *)(*param_2 + 0x7c) = 1;
          *(undefined4 *)(iVar5 + 0x14) = 1;
          puVar2 = (undefined4 *)FUN_409c7034((int)piVar6,in_stack_0000006c,0);
          if (puVar2 == (undefined4 *)0x0) {
            iVar3 = FUN_409c85c0((int)piVar6,param_1,in_stack_0000006c,0);
            if ((iVar3 != 0) ||
               (puVar2 = (undefined4 *)FUN_409c7034((int)piVar6,in_stack_0000006c,0),
               puVar2 == (undefined4 *)0x0)) goto LAB_409be1e4;
            *puVar2 = 0;
            puVar2[1] = 0;
          }
          if (puVar2[5] == 0) {
            iVar3 = __mali_linked_list_alloc();
            puVar2[5] = iVar3;
            if (iVar3 == 0) goto LAB_409be1e4;
          }
          iVar3 = FUN_409becc4(puVar2[5],*param_2,iVar5);
          if (iVar3 == 0) {
            *(uint *)(iVar5 + 0xc) = in_stack_00000070;
            *(undefined4 *)(iVar5 + 8) = 0x1702;
            *(int **)(iVar5 + 0x10) = piVar6;
            *(undefined4 *)(iVar5 + 0x18) = 0;
            *(int *)(iVar5 + 0x1c) = in_stack_0000006c;
            mali_sys_atomic_inc(piVar6 + 0x14);
          }
        }
      }
    }
  }
LAB_409be1e4:
                    /* WARNING: Subroutine does not return */
  FUN_409da790(0x28);
}



/* 409be1ec FUN_409be1ec */

/* Boundary evidence: original MIPS .pdata 409be1ec..409be36b. Semantic name remains unreviewed. */

void FUN_409be1ec(int *param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int in_stack_00000038;
  int in_stack_0000003c;
  int in_stack_00000040;
  uint in_stack_00000044;
  
  FUN_409da688();
  iVar3 = 0;
  if ((in_stack_00000038 == 0x8d40) &&
     (((in_stack_00000044 == 0 || (in_stack_00000040 == 0x8d41)) && (iVar2 = *param_1, iVar2 != 0)))
     ) {
    if (in_stack_0000003c == 0x8d00) {
      iVar2 = iVar2 + 0x24;
    }
    else if (in_stack_0000003c == 0x8d20) {
      iVar2 = iVar2 + 0x48;
    }
    else if (in_stack_0000003c != 0x8ce0) goto LAB_409be364;
    if (iVar2 != 0) {
      if (in_stack_00000044 != 0) {
        if (in_stack_00000044 < 0x100) {
          iVar3 = *(int *)((in_stack_00000044 + 7) * 4 + param_3);
        }
        else {
          iVar3 = __mali_named_list_get_non_flat(param_3,in_stack_00000044);
        }
        if ((iVar3 == 0) || (iVar3 = *(int *)(iVar3 + 4), iVar3 == 0)) goto LAB_409be364;
      }
      if (((*(int *)(iVar2 + 8) != 0x8d41) || (*(int *)(iVar2 + 0x10) != iVar3)) &&
         ((in_stack_00000044 == 0 ||
          (iVar1 = FUN_409becc4(*(undefined4 *)(iVar3 + 0x30),*param_1,iVar2), iVar1 == 0)))) {
        FUN_409bde70(iVar2,*param_1);
        *(undefined4 *)(*param_1 + 0x7c) = 1;
        *(undefined4 *)(iVar2 + 0x14) = 1;
        if (in_stack_00000044 != 0) {
          *(undefined4 *)(iVar2 + 8) = 0x8d41;
          *(uint *)(iVar2 + 0xc) = in_stack_00000044;
          *(int *)(iVar2 + 0x10) = iVar3;
          mali_sys_atomic_inc(iVar3 + 0x2c);
        }
      }
    }
  }
LAB_409be364:
                    /* WARNING: Subroutine does not return */
  FUN_409da6b0(0x10);
}



/* 409be36c FUN_409be36c */

/* Boundary evidence: original MIPS .pdata 409be36c..409be52f. Semantic name remains unreviewed. */

void FUN_409be36c(int param_1)

{
  int iVar1;
  int iVar2;
  
  FUN_409da7c8();
  FUN_409bde70(param_1,param_1);
  iVar1 = mali_frame_builder_get_attachment(*(undefined4 *)(param_1 + 0x6c),0);
  mali_frame_builder_set_attachment(*(undefined4 *)(param_1 + 0x6c),0,0);
  if ((iVar1 != 0) && (iVar2 = mali_render_attachment_get_target(iVar1,0,0), iVar2 != 0)) {
    if (*(int *)(param_1 + 0x6c) == *(int *)(iVar2 + 8)) {
      mali_surface_access_lock(iVar2);
      *(undefined4 *)(iVar2 + 8) = 0;
      mali_surface_access_unlock(iVar2);
    }
    FUN_409bc40c(iVar2);
    mali_render_attachment_free(iVar1);
  }
  FUN_409bde70(param_1 + 0x24,param_1);
  iVar1 = mali_frame_builder_get_attachment(*(undefined4 *)(param_1 + 0x6c),1);
  if ((iVar1 != 0) && (iVar2 = mali_render_attachment_get_target(iVar1,0,0), iVar2 != 0)) {
    if (*(int *)(param_1 + 0x6c) == *(int *)(iVar2 + 8)) {
      mali_surface_access_lock(iVar2);
      *(undefined4 *)(iVar2 + 8) = 0;
      mali_surface_access_unlock(iVar2);
    }
    FUN_409bc40c(iVar2);
    mali_render_attachment_free(iVar1);
  }
  mali_frame_builder_set_attachment(*(undefined4 *)(param_1 + 0x6c),1,0);
  FUN_409bde70(param_1 + 0x48,param_1);
  iVar1 = mali_frame_builder_get_attachment(*(undefined4 *)(param_1 + 0x6c),2);
  if ((iVar1 != 0) && (iVar2 = mali_render_attachment_get_target(iVar1,0,0), iVar2 != 0)) {
    if (*(int *)(param_1 + 0x6c) == *(int *)(iVar2 + 8)) {
      mali_surface_access_lock(iVar2);
      *(undefined4 *)(iVar2 + 8) = 0;
      mali_surface_access_unlock(iVar2);
    }
    FUN_409bc40c(iVar2);
    mali_render_attachment_free(iVar1);
  }
  mali_frame_builder_set_attachment(*(undefined4 *)(param_1 + 0x6c),2,0);
  if (*(int *)(param_1 + 0x70) == 0) {
    mali_frame_builder_free(*(undefined4 *)(param_1 + 0x6c));
  }
  *(undefined4 *)(param_1 + 0x6c) = 0;
  mali_sys_free(param_1);
                    /* WARNING: Subroutine does not return */
  FUN_409da7e8(0x10);
}



/* 409be530 FUN_409be530 */

/* Boundary evidence: original MIPS .pdata 409be530..409be5a7. Semantic name remains unreviewed. */

void FUN_409be530(int param_1,int param_2)

{
  if (param_1 != 0) {
    if (*(int *)(param_1 + 0x10) == param_2) {
      FUN_409bde70(param_1,param_1);
    }
    if (*(int *)(param_1 + 0x34) == param_2) {
      FUN_409bde70(param_1 + 0x24,param_1);
    }
    if (*(int *)(param_1 + 0x58) == param_2) {
      FUN_409bde70(param_1 + 0x48,param_1);
    }
  }
  return;
}



/* 409be5a8 FUN_409be5a8 */

/* Boundary evidence: original MIPS .pdata 409be5a8..409be61f. Semantic name remains unreviewed. */

void FUN_409be5a8(int param_1,int param_2)

{
  if (param_1 != 0) {
    if (*(int *)(param_1 + 0x10) == param_2) {
      FUN_409bde70(param_1,param_1);
    }
    if (*(int *)(param_1 + 0x34) == param_2) {
      FUN_409bde70(param_1 + 0x24,param_1);
    }
    if (*(int *)(param_1 + 0x58) == param_2) {
      FUN_409bde70(param_1 + 0x48,param_1);
    }
  }
  return;
}



/* 409be620 FUN_409be620 */

/* Boundary evidence: original MIPS .pdata 409be620..409be657. Semantic name remains unreviewed. */

void FUN_409be620(int param_1)

{
  int iVar1;
  
  iVar1 = mali_sys_atomic_dec_and_return(param_1 + 0x80);
  if (iVar1 == 0) {
    FUN_409be36c(param_1);
  }
  return;
}



/* 409be658 FUN_409be658 */

/* Boundary evidence: original MIPS .pdata 409be658..409be6cf. Semantic name remains unreviewed. */

void FUN_409be658(int param_1)

{
  int iVar1;
  int iVar2;
  
  if (*(int *)(param_1 + 4) != 0) {
    mali_frame_builder_flush(*(undefined4 *)(*(int *)(param_1 + 4) + 0x6c),0,0);
    mali_frame_builder_wait(*(undefined4 *)(*(int *)(param_1 + 4) + 0x6c));
    iVar2 = *(int *)(param_1 + 4);
    iVar1 = mali_sys_atomic_dec_and_return(iVar2 + 0x80);
    if (iVar1 == 0) {
      FUN_409be36c(iVar2);
    }
    *(undefined4 *)(param_1 + 4) = 0;
  }
  mali_sys_free(param_1);
  return;
}



/* 409be6d0 FUN_409be6d0 */

/* Boundary evidence: original MIPS .pdata 409be6d0..409be787. Semantic name remains unreviewed. */

void FUN_409be6d0(int *param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  FUN_409da688();
  if (*param_1 != 0) {
    iVar1 = mali_frame_builder_flush(*(undefined4 *)(*param_1 + 0x6c),0,0);
    mali_frame_builder_wait(*(undefined4 *)(*param_1 + 0x6c));
    iVar3 = *param_1;
    iVar2 = mali_sys_atomic_dec_and_return(iVar3 + 0x80);
    if (iVar2 == 0) {
      FUN_409be36c(iVar3);
    }
    if (iVar1 != 0) {
      mali_frame_builder_reset(*(undefined4 *)(*param_1 + 0x6c));
    }
  }
  *param_1 = param_2;
  param_1[1] = param_3;
  if (param_3 == 0) {
    param_1[2] = param_1[0xe];
    param_1[3] = param_1[0xf];
  }
  else {
    param_1[2] = 0;
    param_1[3] = 0;
  }
  if (param_2 != 0) {
    mali_sys_atomic_inc(param_2 + 0x80);
  }
                    /* WARNING: Subroutine does not return */
  FUN_409da6b0(0x10);
}



/* 409be788 FUN_409be788 */

/* WARNING: Type propagation algorithm not settling */
/* Boundary evidence: original MIPS .pdata 409be788..409bea03. Semantic name remains unreviewed. */

undefined4 FUN_409be788(undefined4 *param_1,int param_2,int *param_3,int param_4,uint param_5)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  
  uVar5 = *param_1;
  if (param_4 != 0x8d40) {
    return 0x500;
  }
  if (param_3[1] != param_5) {
    if (param_5 == 0) {
      iVar3 = 0;
      if (*param_3 != 0) {
        iVar3 = FUN_409bda40(param_1,*param_3);
      }
      iVar1 = FUN_409be6d0(param_3,0,0);
      param_1[0x13e] = param_1[0x13b];
      param_1[0x13d] = param_1[0x13c];
      FUN_409c5d00((int)param_1);
      iVar2 = FUN_409c508c(param_1);
      if (((iVar2 == 0) && (iVar2 = iVar3, iVar3 == 0)) && (iVar2 = iVar1, iVar1 == 0)) {
        return 0;
      }
    }
    else {
      if (param_5 < 0x100) {
        puVar4 = *(undefined4 **)((param_5 + 7) * 4 + param_2);
      }
      else {
        puVar4 = (undefined4 *)__mali_named_list_get_non_flat(param_2,param_5);
      }
      if (puVar4 == (undefined4 *)0x0) {
        puVar4 = (undefined4 *)mali_sys_malloc(8);
        if (puVar4 == (undefined4 *)0x0) {
          return 0x505;
        }
        *puVar4 = 3;
        puVar4[1] = 0;
        puVar4[1] = 0;
        iVar2 = __mali_named_list_insert(param_2,param_5,puVar4);
        if (iVar2 != 0) {
          mali_sys_free(puVar4);
          return 0x505;
        }
      }
      if (puVar4[1] == 0) {
        iVar2 = FUN_409bc1b0(uVar5);
        puVar4[1] = iVar2;
        if (iVar2 == 0) {
          return 0x505;
        }
      }
      if (((*param_3 == 0) || (iVar2 = FUN_409bda40(param_1,*param_3), iVar2 == 0)) &&
         (iVar2 = FUN_409be6d0(param_3,puVar4[1],param_5), iVar2 == 0)) {
        param_1[0x13d] = *(undefined4 *)(puVar4[1] + 0x6c);
        FUN_409c5d00((int)param_1);
        iVar2 = FUN_409c508c(param_1);
        param_1[0x13e] = *(undefined4 *)(puVar4[1] + 0x6c);
      }
    }
    if (((iVar2 != -3) && (-3 < iVar2)) && (iVar2 < 0)) {
      return 0x505;
    }
  }
  return 0;
}



/* 409bea04 FUN_409bea04 */

/* Boundary evidence: original MIPS .pdata 409bea04..409bec1f. Semantic name remains unreviewed. */

void FUN_409bea04(undefined4 *param_1,int param_2,uint *param_3)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  uint *puVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  
  FUN_409da758();
  iVar7 = 0;
  iVar6 = 0;
  iVar3 = 0;
  if ((-1 < param_2) && (param_3 != (uint *)0x0)) {
    puVar4 = param_3;
    iVar5 = param_2;
    if (0 < param_2) {
      do {
        uVar2 = *puVar4;
        if (uVar2 != 0) {
          if (uVar2 < 0x100) {
            iVar1 = *(int *)((uVar2 + 7) * 4 + *(int *)(param_1[0x13a] + 0x10));
          }
          else {
            iVar1 = __mali_named_list_get_non_flat();
          }
          if (((iVar1 != 0) && (*(int *)(iVar1 + 4) != 0)) &&
             (iVar1 = mali_frame_builder_flush(*(undefined4 *)(*(int *)(iVar1 + 4) + 0x6c),0,0),
             iVar3 == 0)) {
            iVar3 = iVar1;
          }
        }
        iVar5 = iVar5 + -1;
        puVar4 = puVar4 + 1;
      } while (iVar5 != 0);
    }
    if (0 < param_2) {
      do {
        uVar2 = *param_3;
        if (uVar2 != 0) {
          if (uVar2 < 0x100) {
            iVar3 = *(int *)((uVar2 + 7) * 4 + *(int *)(param_1[0x13a] + 0x10));
          }
          else {
            iVar3 = __mali_named_list_get_non_flat(*(int *)(param_1[0x13a] + 0x10),uVar2);
          }
          if (iVar3 != 0) {
            if (*(int *)(iVar3 + 4) != 0) {
              if (param_1[0x121] == *(int *)(iVar3 + 4)) {
                iVar5 = FUN_409be6d0(param_1 + 0x121,0,0);
                if (iVar7 == 0) {
                  iVar7 = iVar5;
                }
                param_1[0x13e] = param_1[0x13b];
                param_1[0x13d] = param_1[0x13c];
                FUN_409c5d00((int)param_1);
                iVar5 = FUN_409c508c(param_1);
                if (iVar6 == 0) {
                  iVar6 = iVar5;
                }
              }
              mali_frame_builder_wait(*(undefined4 *)(*(int *)(iVar3 + 4) + 0x6c));
              FUN_409c4b20((int)param_1);
              iVar1 = *(int *)(iVar3 + 4);
              iVar5 = mali_sys_atomic_dec_and_return(iVar1 + 0x80);
              if (iVar5 == 0) {
                FUN_409be36c(iVar1);
              }
              *(undefined4 *)(iVar3 + 4) = 0;
            }
            __mali_named_list_remove(*(undefined4 *)(param_1[0x13a] + 0x10),uVar2);
            mali_sys_free(iVar3);
          }
        }
        param_3 = param_3 + 1;
        param_2 = param_2 + -1;
      } while (param_2 != 0);
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_409da790(0x10);
}



/* 409bec20 FUN_409bec20 */

/* Boundary evidence: original MIPS .pdata 409bec20..409becc3. Semantic name remains unreviewed. */

void FUN_409bec20(undefined4 param_1,int param_2,int param_3)

{
  int iVar1;
  
  iVar1 = __mali_linked_list_get_first_entry(param_1);
  while( true ) {
    if (iVar1 == 0) {
      return;
    }
    if ((**(int **)(iVar1 + 8) == param_2) && ((*(int **)(iVar1 + 8))[1] == param_3)) break;
    iVar1 = __mali_linked_list_get_next_entry(iVar1);
  }
  *(undefined4 *)(param_2 + 0x7c) = 1;
  *(undefined4 *)(param_3 + 0x14) = 1;
  mali_sys_free();
  __mali_linked_list_remove_entry(param_1,iVar1);
  return;
}



/* 409becc4 FUN_409becc4 */

/* Boundary evidence: original MIPS .pdata 409becc4..409bed4b. Semantic name remains unreviewed. */

int FUN_409becc4(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  int iVar2;
  
  puVar1 = (undefined4 *)mali_sys_malloc(8);
  if (puVar1 == (undefined4 *)0x0) {
    iVar2 = -1;
  }
  else {
    *puVar1 = param_2;
    puVar1[1] = param_3;
    iVar2 = __mali_linked_list_insert_data(param_1,puVar1);
    if (iVar2 != 0) {
      mali_sys_free(puVar1);
    }
  }
  return iVar2;
}



/* 409bed4c FUN_409bed4c */

/* Boundary evidence: original MIPS .pdata 409bed4c..409bed9f. Semantic name remains unreviewed. */

void FUN_409bed4c(void)

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



/* 409beda0 FUN_409beda0 */

/* Boundary evidence: original MIPS .pdata 409beda0..409bedbb. Semantic name remains unreviewed. */

void FUN_409beda0(void)

{
  __mali_linked_list_free();
  return;
}



/* 409bedbc FUN_409bedbc */

/* Boundary evidence: original MIPS .pdata 409bedbc..409bedd7. Semantic name remains unreviewed. */

void FUN_409bedbc(void)

{
  __mali_linked_list_alloc();
  return;
}



/* 409bedd8 FUN_409bedd8 */

/* Boundary evidence: original MIPS .pdata 409bedd8..409bef2b. Semantic name remains unreviewed. */

undefined4
FUN_409bedd8(undefined4 *param_1,undefined4 param_2,int param_3,undefined4 param_4,
            undefined4 *param_5)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  
  if (param_3 != 0x8d41) {
LAB_409bef20:
    return 0x500;
  }
  puVar2 = (undefined4 *)*param_1;
  if (puVar2 == (undefined4 *)0x0) {
    return 0x502;
  }
  switch(param_4) {
  case 0x8d42:
    if (param_5 == (undefined4 *)0x0) {
      return 0;
    }
    *param_5 = puVar2[1];
    return 0;
  case 0x8d43:
    if (param_5 == (undefined4 *)0x0) {
      return 0;
    }
    uVar1 = puVar2[2];
    break;
  case 0x8d44:
    if (param_5 == (undefined4 *)0x0) {
      return 0;
    }
    uVar1 = *puVar2;
    goto LAB_409bee9c;
  default:
    goto LAB_409bef20;
  case 0x8d50:
    if (param_5 == (undefined4 *)0x0) {
      return 0;
    }
    uVar1 = puVar2[3];
    break;
  case 0x8d51:
    if (param_5 == (undefined4 *)0x0) {
      return 0;
    }
    uVar1 = puVar2[5];
    goto LAB_409bee9c;
  case 0x8d52:
    if (param_5 == (undefined4 *)0x0) {
      return 0;
    }
    uVar1 = puVar2[4];
    break;
  case 0x8d53:
    if (param_5 == (undefined4 *)0x0) {
      return 0;
    }
    uVar1 = puVar2[6];
    goto LAB_409bee9c;
  case 0x8d54:
    if (param_5 == (undefined4 *)0x0) {
      return 0;
    }
    uVar1 = puVar2[7];
    break;
  case 0x8d55:
    if (param_5 == (undefined4 *)0x0) {
      return 0;
    }
    uVar1 = puVar2[8];
LAB_409bee9c:
    *param_5 = uVar1;
    return 0;
  }
  *param_5 = uVar1;
  return 0;
}



/* 409bef2c FUN_409bef2c */

void FUN_409bef2c(int *param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5)

{
  *(int *)*param_1 = param_2;
  *(undefined4 *)(*param_1 + 4) = param_3;
  *(undefined4 *)(*param_1 + 8) = param_4;
  *(undefined4 *)(*param_1 + 0x24) = param_5;
  if (param_2 == 0x8056) {
    *(undefined4 *)(*param_1 + 0xc) = 4;
    *(undefined4 *)(*param_1 + 0x14) = 4;
    *(undefined4 *)(*param_1 + 0x10) = 4;
    *(undefined4 *)(*param_1 + 0x18) = 4;
LAB_409bf008:
    if (param_2 != 0x81a5) {
      if (param_2 == 0x81a6) {
        *(undefined4 *)(*param_1 + 0x1c) = 0x18;
        goto LAB_409bf054;
      }
      goto LAB_409bf020;
    }
    *(undefined4 *)(*param_1 + 0x1c) = 0x18;
  }
  else {
    if (param_2 == 0x8057) {
      *(undefined4 *)(*param_1 + 0xc) = 5;
      *(undefined4 *)(*param_1 + 0x14) = 5;
      *(undefined4 *)(*param_1 + 0x10) = 5;
      *(undefined4 *)(*param_1 + 0x18) = 1;
    }
    else {
      if (param_2 != 0x8d62) {
        *(undefined4 *)(*param_1 + 0xc) = 0;
        *(undefined4 *)(*param_1 + 0x14) = 0;
        *(undefined4 *)(*param_1 + 0x10) = 0;
        *(undefined4 *)(*param_1 + 0x18) = 0;
        goto LAB_409bf008;
      }
      *(undefined4 *)(*param_1 + 0xc) = 5;
      *(undefined4 *)(*param_1 + 0x14) = 6;
      *(undefined4 *)(*param_1 + 0x10) = 5;
      *(undefined4 *)(*param_1 + 0x18) = 0;
    }
LAB_409bf020:
    *(undefined4 *)(*param_1 + 0x1c) = 0;
  }
  if (param_2 == 0x8d48) {
    *(undefined4 *)(*param_1 + 0x20) = 8;
    return;
  }
LAB_409bf054:
  *(undefined4 *)(*param_1 + 0x20) = 0;
  return;
}



/* 409bf074 FUN_409bf074 */

undefined4 FUN_409bf074(uint param_1)

{
  if (param_1 < 0x81a6) {
    if (param_1 != 0x81a5) {
      if ((param_1 != 0x1907) && (param_1 != 0x8051)) {
        if (param_1 == 0x8056) {
          return 2;
        }
        if (param_1 == 0x8057) {
          return 1;
        }
        if (param_1 != 0x8058) {
          return 0x10;
        }
      }
      return 3;
    }
  }
  else if (((param_1 != 0x81a6) && (param_1 != 0x8d47)) && (param_1 != 0x8d48)) {
    if (param_1 != 0x8d62) {
      return 0x10;
    }
    return 0;
  }
  return 0xf;
}



/* 409bf130 FUN_409bf130 */

undefined4 FUN_409bf130(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  if (param_1 == 0xe) {
    uVar1 = 0x8d62;
LAB_409bf1a8:
    *param_2 = uVar1;
  }
  else {
    if (param_1 == 0xf) {
      uVar1 = 0x8057;
    }
    else {
      if (param_1 == 0x10) {
        uVar1 = 0x8056;
        goto LAB_409bf1a8;
      }
      if (param_1 != 0x15) {
        if (param_1 == 0x16) {
          uVar1 = 0x8058;
          goto LAB_409bf1a8;
        }
        if (param_1 != 0x17) {
          return 0xfffffffe;
        }
      }
      uVar1 = 0x8051;
    }
    *param_2 = uVar1;
  }
  return 0;
}



/* 409bf1c4 FUN_409bf1c4 */

/* Boundary evidence: original MIPS .pdata 409bf1c4..409bf1df. Semantic name remains unreviewed. */

void FUN_409bf1c4(int param_1)

{
  mali_sys_atomic_inc(param_1 + 0x2c);
  return;
}



/* 409bf1e0 FUN_409bf1e0 */

/* Boundary evidence: original MIPS .pdata 409bf1e0..409bf24f. Semantic name remains unreviewed. */

int FUN_409bf1e0(int param_1)

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



/* 409bf250 FUN_409bf250 */

/* Boundary evidence: original MIPS .pdata 409bf250..409bf26b. Semantic name remains unreviewed. */

void FUN_409bf250(int param_1)

{
  mali_sys_atomic_inc(param_1 + 0x34);
  return;
}



/* 409bf290 FUN_409bf290 */

/* Boundary evidence: original MIPS .pdata 409bf290..409bf2cb. Semantic name remains unreviewed. */

undefined4 FUN_409bf290(int param_1,uint param_2)

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



/* 409bf2cc gles_setup_egl_image_from_renderbuffer */

/* Boundary evidence: original MIPS .pdata 409bf2cc..409bf3b3. Semantic name remains unreviewed.
   gles_setup_egl_image_from_renderbuffer */

undefined4 gles_setup_egl_image_from_renderbuffer(undefined4 *param_1,uint param_2,int param_3)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  
                    /* 0xf2cc  13  _gles_setup_egl_image_from_renderbuffer */
  if (param_2 == 0) {
    uVar1 = 4;
  }
  else {
    if (param_2 < 0x100) {
      iVar2 = *(int *)((param_2 + 7) * 4 + *(int *)(param_1[0x13a] + 0x14));
    }
    else {
      iVar2 = __mali_named_list_get_non_flat();
    }
    if ((iVar2 == 0) || (iVar2 = *(int *)(iVar2 + 4), iVar2 == 0)) {
      uVar1 = 3;
    }
    else if (*(int *)(iVar2 + 0x24) == 1) {
      uVar1 = 5;
    }
    else if (*(int *)(iVar2 + 0x28) == 0) {
      uVar1 = 2;
    }
    else {
      iVar3 = mali_image_create_from_surface(*(int *)(iVar2 + 0x28),*param_1);
      *(int *)(param_3 + 0x20) = iVar3;
      if (iVar3 == 0) {
        uVar1 = 6;
      }
      else {
        mali_sys_atomic_inc(*(int *)(iVar3 + 0x10) + 0x34);
        *(undefined4 *)(iVar2 + 0x24) = 1;
        uVar1 = 0;
      }
    }
  }
  return uVar1;
}



/* 409bf3b4 FUN_409bf3b4 */

/* Boundary evidence: original MIPS .pdata 409bf3b4..409bf4eb. Semantic name remains unreviewed. */

void FUN_409bf3b4(int param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  int iStack00000018;
  
  FUN_409da688();
  iStack00000018 = 0x8d62;
  if (param_2 == 0x8d41) {
    piVar4 = (int *)(param_1 + 0x47c);
    iVar1 = (**(code **)(param_1 + 0x50c))(param_3);
    if ((((((iVar1 != 0) && (*(int *)(iVar1 + 0x20) != 0)) &&
          (piVar3 = *(int **)(*(int *)(iVar1 + 0x20) + 0x10), piVar3 != (int *)0x0)) &&
         ((*piVar3 != 0 && (piVar3[5] != -1)))) &&
        ((iVar2 = FUN_409bf130(piVar3[6],&stack0x00000018), iVar1 = iStack00000018, iVar2 == 0 &&
         ((iStack00000018 != 0x8d62 || (piVar3[10] != 1)))))) &&
       ((*(ushort *)(piVar3 + 3) < 0x1001 &&
        ((*(ushort *)((int)piVar3 + 0xe) < 0x1001 && (*piVar4 != 0)))))) {
      iVar2 = *(int *)(*piVar4 + 0x28);
      if (iVar2 != 0) {
        FUN_409bf1e0(iVar2);
        *(undefined4 *)(*piVar4 + 0x28) = 0;
      }
      *(int **)(*piVar4 + 0x28) = piVar3;
      mali_sys_atomic_inc(piVar3 + 0xd);
      FUN_409bef2c(piVar4,iVar1,(uint)*(ushort *)(piVar3 + 3),(uint)*(ushort *)((int)piVar3 + 0xe),1
                  );
      FUN_409bed4c();
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_409da6b0(0x20);
}



/* 409bf4ec FUN_409bf4ec */

/* Boundary evidence: original MIPS .pdata 409bf4ec..409bf59b. Semantic name remains unreviewed. */

undefined4 FUN_409bf4ec(int param_1,int param_2,int param_3,int param_4)

{
  int *piVar1;
  uint uVar2;
  int local_18 [6];
  
  local_18[0] = 0x8d62;
  local_18[1] = 0x8056;
  local_18[2] = 0x8057;
  local_18[3] = 0x81a5;
  local_18[4] = 0x8d48;
  local_18[5] = 0x81a6;
  if (param_1 == 0x8d41) {
    uVar2 = 0;
    piVar1 = local_18;
    do {
      if (param_2 == *piVar1) {
        if (((-1 < param_3) && (-1 < param_4)) && (param_3 < 0x1001)) {
          if (0x1000 < param_4) {
            return 0x501;
          }
          return 0;
        }
        return 0x501;
      }
      uVar2 = uVar2 + 1;
      prefetch(piVar1 + 2,0);
      piVar1 = piVar1 + 1;
    } while (uVar2 < 6);
  }
  return 0x500;
}



/* 409bf59c FUN_409bf59c */

/* Boundary evidence: original MIPS .pdata 409bf59c..409bf5f7. Semantic name remains unreviewed. */

void FUN_409bf59c(int param_1)

{
  if (param_1 != 0) {
    if (*(int *)(param_1 + 0x30) != 0) {
      __mali_linked_list_free();
    }
    *(undefined4 *)(param_1 + 0x30) = 0;
    if (*(int *)(param_1 + 0x28) != 0) {
      FUN_409bf1e0(*(int *)(param_1 + 0x28));
      *(undefined4 *)(param_1 + 0x28) = 0;
    }
    mali_sys_free(param_1);
  }
  return;
}



/* 409bf5f8 FUN_409bf5f8 */

/* Boundary evidence: original MIPS .pdata 409bf5f8..409bf663. Semantic name remains unreviewed. */

void FUN_409bf5f8(undefined4 *param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  uVar1 = mali_pixel_layout_to_texel_layout(2);
  uVar2 = mali_pixel_to_texel_format(param_2);
  *param_1 = param_2;
  param_1[2] = 2;
  param_1[3] = uVar1;
  param_1[1] = uVar2;
  param_1[4] = 0;
  param_1[5] = 0;
  return;
}



/* 409bf664 FUN_409bf664 */

/* Boundary evidence: original MIPS .pdata 409bf664..409bf74b. Semantic name remains unreviewed. */

void FUN_409bf664(void)

{
  int iVar1;
  undefined4 uVar2;
  int *in_a3;
  int in_stack_0000005c;
  uint in_stack_00000060;
  uint in_stack_00000064;
  uint in_stack_00000068;
  
  FUN_409da688();
  if ((*in_a3 != 0) &&
     (iVar1 = FUN_409bf4ec(in_stack_0000005c,in_stack_00000060,in_stack_00000064,in_stack_00000068),
     iVar1 == 0)) {
    uVar2 = FUN_409bf074(in_stack_00000060);
    FUN_409bf5f8((undefined4 *)&stack0x00000018,uVar2);
    iVar1 = mali_surface_alloc(in_stack_00000064 & 0xffff,in_stack_00000068 & 0xffff,0,
                               &stack0x00000018);
    if (iVar1 != 0) {
      if (*(int *)(*in_a3 + 0x28) != 0) {
        FUN_409bf1e0(*(int *)(*in_a3 + 0x28));
      }
      *(int *)(*in_a3 + 0x28) = iVar1;
      FUN_409bef2c(in_a3,in_stack_00000060,in_stack_00000064,in_stack_00000068,0);
      FUN_409bed4c();
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_409da6b0(0x30);
}



/* 409bf74c FUN_409bf74c */

/* Boundary evidence: original MIPS .pdata 409bf74c..409bf783. Semantic name remains unreviewed. */

void FUN_409bf74c(int param_1)

{
  int iVar1;
  
  iVar1 = mali_sys_atomic_dec_and_return(param_1 + 0x2c);
  if (iVar1 == 0) {
    FUN_409bf59c(param_1);
  }
  return;
}



/* 409bf784 FUN_409bf784 */

/* Boundary evidence: original MIPS .pdata 409bf784..409bf7db. Semantic name remains unreviewed. */

void FUN_409bf784(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 4);
  if (iVar2 != 0) {
    iVar1 = mali_sys_atomic_dec_and_return(iVar2 + 0x2c);
    if (iVar1 == 0) {
      FUN_409bf59c(iVar2);
    }
    *(undefined4 *)(param_1 + 4) = 0;
  }
  mali_sys_free(param_1);
  return;
}



/* 409bf7dc FUN_409bf7dc */

/* Boundary evidence: original MIPS .pdata 409bf7dc..409bf877. Semantic name remains unreviewed. */

undefined4 * FUN_409bf7dc(void)

{
  undefined4 *puVar1;
  int iVar2;
  
  puVar1 = (undefined4 *)mali_sys_malloc(0x34);
  if (puVar1 != (undefined4 *)0x0) {
    mali_sys_memset(puVar1,0,0x34);
    mali_sys_atomic_initialize(puVar1 + 0xb,1);
    *puVar1 = 0x1908;
    puVar1[1] = 0;
    puVar1[2] = 0;
    puVar1[10] = 0;
    puVar1[9] = 0;
    iVar2 = __mali_linked_list_alloc();
    puVar1[0xc] = iVar2;
    if (iVar2 != 0) {
      return puVar1;
    }
    iVar2 = mali_sys_atomic_dec_and_return(puVar1 + 0xb);
    if (iVar2 == 0) {
      FUN_409bf59c((int)puVar1);
    }
  }
  return (undefined4 *)0x0;
}



/* 409bf878 FUN_409bf878 */

/* Boundary evidence: original MIPS .pdata 409bf878..409bf8eb. Semantic name remains unreviewed. */

void FUN_409bf878(int *param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *param_1;
  if ((iVar2 != 0) && (iVar1 = mali_sys_atomic_dec_and_return(iVar2 + 0x2c), iVar1 == 0)) {
    FUN_409bf59c(iVar2);
  }
  *param_1 = param_2;
  param_1[1] = param_3;
  if (param_2 != 0) {
    mali_sys_atomic_inc(param_2 + 0x2c);
  }
  return;
}



/* 409bf8ec FUN_409bf8ec */

/* Boundary evidence: original MIPS .pdata 409bf8ec..409bfa03. Semantic name remains unreviewed. */

undefined4 FUN_409bf8ec(int param_1,int *param_2,int param_3,uint param_4)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  
  if (param_3 != 0x8d41) {
    return 0x500;
  }
  if (param_4 == 0) {
    param_4 = 0;
    iVar2 = 0;
  }
  else {
    if (param_4 < 0x100) {
      puVar3 = *(undefined4 **)((param_4 + 7) * 4 + param_1);
    }
    else {
      puVar3 = (undefined4 *)__mali_named_list_get_non_flat(param_1,param_4);
    }
    if (puVar3 == (undefined4 *)0x0) {
      puVar3 = (undefined4 *)mali_sys_malloc(8);
      if (puVar3 == (undefined4 *)0x0) {
        return 0x505;
      }
      *puVar3 = 2;
      puVar3[1] = 0;
      puVar3[1] = 0;
      iVar2 = __mali_named_list_insert(param_1,param_4,puVar3);
      if (iVar2 != 0) {
        mali_sys_free(puVar3);
        return 0x505;
      }
    }
    if (puVar3[1] == 0) {
      puVar1 = FUN_409bf7dc();
      puVar3[1] = puVar1;
      if (puVar1 == (undefined4 *)0x0) {
        return 0x505;
      }
    }
    iVar2 = puVar3[1];
  }
  FUN_409bf878(param_2,iVar2,param_4);
  return 0;
}



/* 409bfa04 FUN_409bfa04 */

/* Boundary evidence: original MIPS .pdata 409bfa04..409bfb53. Semantic name remains unreviewed. */

undefined4
FUN_409bfa04(int param_1,undefined4 param_2,int *param_3,int *param_4,int param_5,uint *param_6)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  
  if (param_5 < 0) {
    uVar1 = 0x501;
  }
  else {
    if ((param_6 != (uint *)0x0) && (0 < param_5)) {
      do {
        uVar4 = *param_6;
        if (uVar4 != 0) {
          if (uVar4 < 0x100) {
            iVar3 = *(int *)((uVar4 + 7) * 4 + param_1);
          }
          else {
            iVar3 = __mali_named_list_get_non_flat(param_1,uVar4);
          }
          if (iVar3 != 0) {
            if (*(int *)(iVar3 + 4) != 0) {
              if (*param_3 == *(int *)(iVar3 + 4)) {
                FUN_409bf878(param_3,0,0);
              }
              if (*param_4 != 0) {
                FUN_409be5a8(*param_4,*(int *)(iVar3 + 4));
              }
              iVar5 = *(int *)(iVar3 + 4);
              iVar2 = mali_sys_atomic_dec_and_return(iVar5 + 0x2c);
              if (iVar2 == 0) {
                FUN_409bf59c(iVar5);
              }
              *(undefined4 *)(iVar3 + 4) = 0;
            }
            __mali_named_list_remove(param_1,uVar4);
            mali_sys_free(iVar3);
          }
        }
        param_6 = param_6 + 1;
        param_5 = param_5 + -1;
      } while (param_5 != 0);
    }
    uVar1 = 0;
  }
  return uVar1;
}



/* 409bfbcc FUN_409bfbcc */

/* Boundary evidence: original MIPS .pdata 409bfbcc..409bfcef. Semantic name remains unreviewed. */

void FUN_409bfbcc(int param_1,undefined4 param_2,int param_3)

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



/* 409bfcf0 FUN_409bfcf0 */

/* Boundary evidence: original MIPS .pdata 409bfcf0..409bfd7f. Semantic name remains unreviewed. */

void FUN_409bfcf0(int param_1,undefined4 param_2,int param_3)

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
  FUN_409bfbcc(param_1,uVar2,(uint)(param_3 != 0));
  return;
}



/* 409bfd80 FUN_409bfd80 */

/* Boundary evidence: original MIPS .pdata 409bfd80..409bfe0f. Semantic name remains unreviewed. */

void FUN_409bfd80(int param_1)

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



/* 409bfe10 FUN_409bfe10 */

/* Boundary evidence: original MIPS .pdata 409bfe10..409bfeef. Semantic name remains unreviewed. */

int FUN_409bfe10(void)

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



/* 409bfef0 FUN_409bfef0 */

/* Boundary evidence: original MIPS .pdata 409bfef0..409bff27. Semantic name remains unreviewed. */

void FUN_409bfef0(int param_1)

{
  int iVar1;
  
  iVar1 = mali_sys_atomic_dec_and_return(param_1 + 0x180);
  if (iVar1 == 0) {
    FUN_409bfd80(param_1);
  }
  return;
}



/* 409bff74 FUN_409bff74 */

/* Boundary evidence: original MIPS .pdata 409bff74..409c0053. Semantic name remains unreviewed. */

int FUN_409bff74(int *param_1,uint param_2)

{
  int iVar1;
  
  if (*param_1 != 0) {
    iVar1 = FUN_409bc7c4(*param_1,param_2);
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



/* 409c005c FUN_409c005c */

/* Boundary evidence: original MIPS .pdata 409c005c..409c00b3. Semantic name remains unreviewed. */

void FUN_409c005c(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  FUN_409da7c8();
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
  FUN_409da7e8(0x10);
}



/* 409c00b4 FUN_409c00b4 */

/* Boundary evidence: original MIPS .pdata 409c00b4..409c01bb. Semantic name remains unreviewed. */

void FUN_409c00b4(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 in_stack_00000038;
  
  FUN_409da688();
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
  FUN_409da6b0(0x10);
}



/* 409c01f8 FUN_409c01f8 */

/* Boundary evidence: original MIPS .pdata 409c01f8..409c030f. Semantic name remains unreviewed. */

undefined4 FUN_409c01f8(int param_1)

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
    goto LAB_409c02cc;
  }
  if (iVar3 != -0x48) {
    if (*(int *)(iVar3 + 0x50) == 0x1702) {
      iVar1 = FUN_409c682c(*(int *)(iVar3 + 100));
      piVar4 = *(int **)((iVar1 * 0xd + *(int *)(iVar3 + 0x60)) * 4 +
                        *(int *)(*(int *)(iVar3 + 0x58) + 0x34));
      if (piVar4 != (int *)0x0) {
        iVar3 = *piVar4;
        goto LAB_409c0284;
      }
    }
    else if (*(int *)(iVar3 + 0x50) == 0x8d41) {
      iVar3 = *(int *)(*(int *)(iVar3 + 0x58) + 0x28);
LAB_409c0284:
      if (iVar3 != 0) {
        mali_pixel_format_get_bpc
                  (*(undefined4 *)(iVar3 + 0x14),auStack_14,auStack_18,auStack_1c,auStack_20,
                   auStack_24,&local_28);
        goto LAB_409c02cc;
      }
    }
  }
  local_28 = 0;
LAB_409c02cc:
  uVar2 = 1;
  if (((*(uint *)(*(int *)(param_1 + 0x504) + 0x40) & 0x10) == 0) || (local_28 < 1)) {
    uVar2 = 0;
  }
  return uVar2;
}



/* 409c0310 FUN_409c0310 */

/* Boundary evidence: original MIPS .pdata 409c0310..409c0427. Semantic name remains unreviewed. */

undefined4 FUN_409c0310(int param_1)

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
    goto LAB_409c03e4;
  }
  if (iVar3 != -0x24) {
    if (*(int *)(iVar3 + 0x2c) == 0x1702) {
      iVar1 = FUN_409c682c(*(int *)(iVar3 + 0x40));
      piVar4 = *(int **)((iVar1 * 0xd + *(int *)(iVar3 + 0x3c)) * 4 +
                        *(int *)(*(int *)(iVar3 + 0x34) + 0x34));
      if (piVar4 != (int *)0x0) {
        iVar3 = *piVar4;
        goto LAB_409c039c;
      }
    }
    else if (*(int *)(iVar3 + 0x2c) == 0x8d41) {
      iVar3 = *(int *)(*(int *)(iVar3 + 0x34) + 0x28);
LAB_409c039c:
      if (iVar3 != 0) {
        mali_pixel_format_get_bpc
                  (*(undefined4 *)(iVar3 + 0x14),auStack_14,auStack_18,auStack_1c,auStack_20,
                   &local_28,auStack_24);
        goto LAB_409c03e4;
      }
    }
  }
  local_28 = 0;
LAB_409c03e4:
  uVar2 = 1;
  if (((*(uint *)(*(int *)(param_1 + 0x504) + 0x40) & 2) == 0) || (local_28 < 1)) {
    uVar2 = 0;
  }
  return uVar2;
}



/* 409c047c FUN_409c047c */

void FUN_409c047c(int param_1,int param_2,int param_3,int param_4,char param_5)

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



/* 409c0514 FUN_409c0514 */

/* Boundary evidence: original MIPS .pdata 409c0514..409c056f. Semantic name remains unreviewed. */

void FUN_409c0514(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0x504);
  *(char *)(iVar2 + 0x59) = (char)param_2;
  iVar1 = FUN_409c01f8(param_1);
  if (iVar1 == 0) {
    param_2 = 0;
  }
  *(uint *)(iVar2 + 0x1c) = param_2 << 8 ^ *(uint *)(iVar2 + 0x1c) & 0xffff00ff;
  return;
}



/* 409c0570 FUN_409c0570 */

/* Boundary evidence: original MIPS .pdata 409c0570..409c05c7. Semantic name remains unreviewed. */

void FUN_409c0570(int param_1,uint param_2)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0x504);
  *(char *)(iVar2 + 0x52) = (char)param_2;
  iVar1 = FUN_409c01f8(param_1);
  if (iVar1 == 0) {
    param_2 = 0;
  }
  *(uint *)(iVar2 + 0x1c) = *(uint *)(iVar2 + 0x1c) & 0xffffff00 ^ param_2;
  return;
}



/* 409c05c8 FUN_409c05c8 */

/* Boundary evidence: original MIPS .pdata 409c05c8..409c0617. Semantic name remains unreviewed. */

void FUN_409c05c8(int param_1,uint param_2)

{
  uint uVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0x504);
  *(char *)(iVar2 + 0x4e) = (char)param_2;
  uVar1 = FUN_409c0310(param_1);
  *(uint *)(iVar2 + 0xc) = *(uint *)(iVar2 + 0xc) & 0xfffffffe ^ uVar1 & param_2;
  return;
}



/* 409c0618 FUN_409c0618 */

/* Boundary evidence: original MIPS .pdata 409c0618..409c06bf. Semantic name remains unreviewed. */

void FUN_409c0618(int param_1,int param_2,uint param_3,undefined4 param_4,int param_5,
                 undefined4 param_6,undefined4 param_7)

{
  int *piVar1;
  uint uVar2;
  
  FUN_409da688();
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
        FUN_409c0570(param_1,uVar2);
      }
      if ((param_2 == 0x405) || (param_2 == 0x408)) {
        *(uint *)(param_1 + 0x478) = uVar2;
        FUN_409c0514(param_1,uVar2);
      }
      break;
    }
    uVar2 = uVar2 + 1;
    prefetch(piVar1 + 2,0);
    piVar1 = piVar1 + 1;
  } while (uVar2 < 3);
                    /* WARNING: Subroutine does not return */
  FUN_409da6b0(0x20);
}



/* 409c06c0 FUN_409c06c0 */

/* Boundary evidence: original MIPS .pdata 409c06c0..409c06ef. Semantic name remains unreviewed. */

void FUN_409c06c0(int param_1,int param_2)

{
  *(bool *)(param_1 + 0x458) = param_2 != 0;
  FUN_409c05c8(param_1,(uint)(param_2 != 0));
  return;
}



/* 409c06f0 FUN_409c06f0 */

/* Boundary evidence: original MIPS .pdata 409c06f0..409c076f. Semantic name remains unreviewed. */

void FUN_409c06f0(int param_1)

{
  undefined4 uVar1;
  int in_stack_00000010;
  undefined4 in_stack_00000014;
  undefined4 in_stack_00000018;
  
  FUN_409da7c8();
  uVar1 = 1;
  in_stack_00000010 = CONCAT31(in_stack_00000010._1_3_,1);
  FUN_409c047c(param_1,1,1,1,'\x01');
  *(undefined1 *)(param_1 + 0x458) = 1;
  FUN_409c05c8(param_1,1);
  FUN_409c0618(param_1,0x408,0xff,uVar1,in_stack_00000010,in_stack_00000014,in_stack_00000018);
  FUN_409c00b4(param_1 + 0x454,0,0,0);
  FUN_409c005c(param_1 + 0x454,0x3f800000);
  *(undefined4 *)(param_1 + 0x474) = 0;
                    /* WARNING: Subroutine does not return */
  FUN_409da7e8(0x18);
}



/* 409c0780 FUN_409c0780 */

/* Boundary evidence: original MIPS .pdata 409c0780..409c081f. Semantic name remains unreviewed. */

undefined1 FUN_409c0780(undefined4 param_1)

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



/* 409c0820 FUN_409c0820 */

/* Boundary evidence: original MIPS .pdata 409c0820..409c0857. Semantic name remains unreviewed. */

void FUN_409c0820(int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined1 uVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0x504);
  *(undefined4 *)(iVar2 + 0x7c) = param_2;
  *(undefined4 *)(iVar2 + 0x80) = param_3;
  uVar1 = FUN_409c0780(param_2);
  *(undefined1 *)(iVar2 + 0x65) = uVar1;
  *(undefined1 *)(iVar2 + 0x66) = 0;
  return;
}



/* 409c0858 FUN_409c0858 */

/* Boundary evidence: original MIPS .pdata 409c0858..409c0893. Semantic name remains unreviewed. */

undefined4 FUN_409c0858(int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined1 uVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0x504);
  *(undefined4 *)(iVar2 + 0x7c) = param_2;
  *(undefined4 *)(iVar2 + 0x80) = param_3;
  uVar1 = FUN_409c0780(param_2);
  *(undefined1 *)(iVar2 + 0x65) = uVar1;
  *(undefined1 *)(iVar2 + 0x66) = 0;
  return 0;
}



/* 409c0984 FUN_409c0984 */

/* Boundary evidence: original MIPS .pdata 409c0984..409c0a9b. Semantic name remains unreviewed. */

undefined4 FUN_409c0984(int param_1)

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
    goto LAB_409c0a58;
  }
  if (iVar3 != -0x48) {
    if (*(int *)(iVar3 + 0x50) == 0x1702) {
      iVar1 = FUN_409c682c(*(int *)(iVar3 + 100));
      piVar4 = *(int **)((iVar1 * 0xd + *(int *)(iVar3 + 0x60)) * 4 +
                        *(int *)(*(int *)(iVar3 + 0x58) + 0x34));
      if (piVar4 != (int *)0x0) {
        iVar3 = *piVar4;
        goto LAB_409c0a10;
      }
    }
    else if (*(int *)(iVar3 + 0x50) == 0x8d41) {
      iVar3 = *(int *)(*(int *)(iVar3 + 0x58) + 0x28);
LAB_409c0a10:
      if (iVar3 != 0) {
        mali_pixel_format_get_bpc
                  (*(undefined4 *)(iVar3 + 0x14),auStack_14,auStack_18,auStack_1c,auStack_20,
                   auStack_24,&local_28);
        goto LAB_409c0a58;
      }
    }
  }
  local_28 = 0;
LAB_409c0a58:
  uVar2 = 1;
  if (((*(uint *)(*(int *)(param_1 + 0x504) + 0x40) & 0x10) == 0) || (local_28 < 1)) {
    uVar2 = 0;
  }
  return uVar2;
}



/* 409c0a9c FUN_409c0a9c */

/* Boundary evidence: original MIPS .pdata 409c0a9c..409c0bb3. Semantic name remains unreviewed. */

undefined4 FUN_409c0a9c(int param_1)

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
    goto LAB_409c0b70;
  }
  if (iVar3 != -0x24) {
    if (*(int *)(iVar3 + 0x2c) == 0x1702) {
      iVar1 = FUN_409c682c(*(int *)(iVar3 + 0x40));
      piVar4 = *(int **)((iVar1 * 0xd + *(int *)(iVar3 + 0x3c)) * 4 +
                        *(int *)(*(int *)(iVar3 + 0x34) + 0x34));
      if (piVar4 != (int *)0x0) {
        iVar3 = *piVar4;
        goto LAB_409c0b28;
      }
    }
    else if (*(int *)(iVar3 + 0x2c) == 0x8d41) {
      iVar3 = *(int *)(*(int *)(iVar3 + 0x34) + 0x28);
LAB_409c0b28:
      if (iVar3 != 0) {
        mali_pixel_format_get_bpc
                  (*(undefined4 *)(iVar3 + 0x14),auStack_14,auStack_18,auStack_1c,auStack_20,
                   &local_28,auStack_24);
        goto LAB_409c0b70;
      }
    }
  }
  local_28 = 0;
LAB_409c0b70:
  uVar2 = 1;
  if (((*(uint *)(*(int *)(param_1 + 0x504) + 0x40) & 2) == 0) || (local_28 < 1)) {
    uVar2 = 0;
  }
  return uVar2;
}



/* 409c0bb4 FUN_409c0bb4 */

/* Boundary evidence: original MIPS .pdata 409c0bb4..409c0c67. Semantic name remains unreviewed. */

void FUN_409c0bb4(int param_1,uint param_2,uint param_3,uint param_4)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  
  iVar3 = *(int *)(param_1 + 0x504);
  *(uint *)(iVar3 + 0x88) = param_4;
  *(char *)(iVar3 + 0x56) = (char)param_2;
  *(char *)(iVar3 + 0x57) = (char)param_3;
  *(char *)(iVar3 + 0x58) = (char)param_4;
  iVar1 = FUN_409c0984(param_1);
  if (iVar1 == 0) {
    param_2 = 7;
  }
  uVar2 = (*(uint *)(iVar3 + 0x18) & 0xfffffff8 ^ param_2) & 0xff00ffff ^
          (param_3 & param_4) << 0x10;
  *(uint *)(iVar3 + 0x18) = uVar2;
  *(uint *)(iVar3 + 0x18) = uVar2 & 0xffffff ^ (uint)*(byte *)(iVar3 + 0x51) << 0x18;
  return;
}



/* 409c0c68 FUN_409c0c68 */

/* Boundary evidence: original MIPS .pdata 409c0c68..409c0d1b. Semantic name remains unreviewed. */

void FUN_409c0c68(int param_1,uint param_2,uint param_3,uint param_4)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  
  iVar3 = *(int *)(param_1 + 0x504);
  *(uint *)(iVar3 + 0x84) = param_4;
  *(char *)(iVar3 + 0x4f) = (char)param_2;
  *(char *)(iVar3 + 0x50) = (char)param_3;
  *(char *)(iVar3 + 0x51) = (char)param_4;
  iVar1 = FUN_409c0984(param_1);
  if (iVar1 == 0) {
    param_2 = 7;
  }
  uVar2 = (*(uint *)(iVar3 + 0x14) & 0xfffffff8 ^ param_2) & 0xff00ffff ^
          (param_3 & param_4) << 0x10;
  *(uint *)(iVar3 + 0x14) = uVar2;
  *(uint *)(iVar3 + 0x14) = uVar2 & 0xffffff ^ (uint)*(byte *)(iVar3 + 0x51) << 0x18;
  return;
}



/* 409c0d1c FUN_409c0d1c */

/* Boundary evidence: original MIPS .pdata 409c0d1c..409c0d77. Semantic name remains unreviewed. */

void FUN_409c0d1c(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0x504);
  *(char *)(iVar2 + 0x4d) = (char)param_2;
  iVar1 = FUN_409c0a9c(param_1);
  if (iVar1 == 0) {
    param_2 = 7;
  }
  *(uint *)(iVar2 + 0xc) = param_2 << 1 ^ *(uint *)(iVar2 + 0xc) & 0xfffffff1;
  return;
}



/* 409c0d78 FUN_409c0d78 */

/* Boundary evidence: original MIPS .pdata 409c0d78..409c0de3. Semantic name remains unreviewed. */

undefined4 FUN_409c0d78(int param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = 0;
  do {
    if (param_2 == *(int *)((int)&DAT_409b148c + uVar2)) {
      iVar1 = FUN_409b7500(param_2);
      FUN_409c0d1c(param_1,iVar1);
      return 0;
    }
    uVar2 = uVar2 + 4;
  } while (uVar2 < 0x20);
  return 0x500;
}



/* 409c0de4 FUN_409c0de4 */

/* Boundary evidence: original MIPS .pdata 409c0de4..409c0f1b. Semantic name remains unreviewed. */

undefined4 FUN_409c0de4(int param_1,int param_2,int param_3,uint param_4,uint param_5)

{
  uint uVar1;
  
  uVar1 = 0;
  while (param_3 != *(int *)((int)&DAT_409b148c + uVar1)) {
    uVar1 = uVar1 + 4;
    if (0x1f < uVar1) {
      return 0x500;
    }
  }
  uVar1 = 0;
  do {
    if (param_2 == *(int *)((int)&DAT_409b14b0 + uVar1)) {
      uVar1 = FUN_409b7500(param_3);
      if ((int)param_4 < 0) {
        param_4 = 0;
      }
      else if (0xff < (int)param_4) {
        param_4 = 0xff;
      }
      if ((param_2 == 0x404) || (param_2 == 0x408)) {
        FUN_409c0c68(param_1,uVar1,param_4 & 0xff,param_5);
      }
      if ((param_2 == 0x405) || (param_2 == 0x408)) {
        FUN_409c0bb4(param_1,uVar1,param_4 & 0xff,param_5);
      }
      return 0;
    }
    uVar1 = uVar1 + 4;
  } while (uVar1 < 0xc);
  return 0x500;
}



/* 409c0f60 FUN_409c0f60 */

/* Boundary evidence: original MIPS .pdata 409c0f60..409c0f7b. Semantic name remains unreviewed. */

void FUN_409c0f60(int param_1)

{
  mali_sys_atomic_inc(param_1 + 0x14);
  return;
}



/* 409c0f7c FUN_409c0f7c */

/* Boundary evidence: original MIPS .pdata 409c0f7c..409c0feb. Semantic name remains unreviewed. */

void FUN_409c0f7c(int param_1,int param_2,undefined4 param_3,int param_4)

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
    FUN_409c5ec4(puVar1);
  }
  return;
}



/* 409c0fec FUN_409c0fec */

/* Boundary evidence: original MIPS .pdata 409c0fec..409c106f. Semantic name remains unreviewed. */

void FUN_409c0fec(int param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  
  FUN_409da7c8();
  if (param_2 == *(int *)(param_1 + 0x300)) {
    FUN_409c5ec4(*(undefined4 **)(param_1 + 0x308));
    *(undefined4 *)(param_1 + 0x300) = 0;
    *(undefined4 *)(param_1 + 0x308) = 0;
  }
  if (param_2 == *(int *)(param_1 + 0x304)) {
    FUN_409c5ec4(*(undefined4 **)(param_1 + 0x30c));
    *(undefined4 *)(param_1 + 0x304) = 0;
    *(undefined4 *)(param_1 + 0x30c) = 0;
  }
  piVar1 = (int *)(param_1 + 0x18);
  iVar2 = 0x10;
  do {
    if (param_2 == *piVar1) {
      FUN_409c5ec4((undefined4 *)piVar1[1]);
      *piVar1 = 0;
      piVar1[1] = 0;
    }
    iVar2 = iVar2 + -1;
    piVar1 = piVar1 + 0xc;
  } while (iVar2 != 0);
                    /* WARNING: Subroutine does not return */
  FUN_409da7e8(0x10);
}



/* 409c1070 FUN_409c1070 */

/* Boundary evidence: original MIPS .pdata 409c1070..409c112b. Semantic name remains unreviewed. */

void FUN_409c1070(int param_1,int param_2,int param_3,uint param_4)

{
  int iVar1;
  undefined1 in_stack_00000040;
  int in_stack_00000044;
  undefined4 in_stack_00000048;
  
  FUN_409da808();
  if (in_stack_00000044 == 0) {
    iVar1 = FUN_409c33ec(param_4);
    in_stack_00000044 = iVar1 * param_3;
  }
  iVar1 = param_2 * 0x30 + param_1 + 0x14;
  if (*(int *)(param_1 + 0x314) != *(int *)(iVar1 + 0x18)) {
    if (*(int *)(param_1 + 0x31c) != 0) {
      mali_sys_atomic_inc(*(int *)(param_1 + 0x31c) + 0x14);
    }
    if (*(undefined4 **)(iVar1 + 0x1c) != (undefined4 *)0x0) {
      FUN_409c5ec4(*(undefined4 **)(iVar1 + 0x1c));
    }
    *(undefined4 *)(iVar1 + 0x18) = *(undefined4 *)(param_1 + 0x314);
    *(undefined4 *)(iVar1 + 0x1c) = *(undefined4 *)(param_1 + 0x31c);
  }
  *(int *)(iVar1 + 4) = param_3;
  *(uint *)(iVar1 + 0xc) = param_4;
  *(undefined1 *)(iVar1 + 0x10) = in_stack_00000040;
  *(int *)(iVar1 + 8) = in_stack_00000044;
  *(undefined4 *)(iVar1 + 0x14) = in_stack_00000048;
  FUN_409b440c(*(int *)(param_1 + 0x4fc),param_1 + 0x14,param_2);
                    /* WARNING: Subroutine does not return */
  FUN_409da838(0x10);
}



/* 409c112c FUN_409c112c */

/* Boundary evidence: original MIPS .pdata 409c112c..409c11a3. Semantic name remains unreviewed. */

void FUN_409c112c(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  
  FUN_409da7c8();
  puVar1 = (undefined4 *)(param_1 + 0x18);
  iVar2 = 0x10;
  do {
    if ((undefined4 *)puVar1[1] != (undefined4 *)0x0) {
      FUN_409c5ec4((undefined4 *)puVar1[1]);
    }
    *puVar1 = 0;
    iVar2 = iVar2 + -1;
    puVar1[1] = 0;
    puVar1 = puVar1 + 0xc;
  } while (iVar2 != 0);
  *(undefined4 *)(param_1 + 0x300) = 0;
  *(undefined4 *)(param_1 + 0x304) = 0;
  if (*(undefined4 **)(param_1 + 0x308) != (undefined4 *)0x0) {
    FUN_409c5ec4(*(undefined4 **)(param_1 + 0x308));
  }
  *(undefined4 *)(param_1 + 0x308) = 0;
  if (*(undefined4 **)(param_1 + 0x30c) != (undefined4 *)0x0) {
    FUN_409c5ec4(*(undefined4 **)(param_1 + 0x30c));
  }
  *(undefined4 *)(param_1 + 0x30c) = 0;
                    /* WARNING: Subroutine does not return */
  FUN_409da7e8(0x10);
}



/* 409c11f8 FUN_409c11f8 */

/* Boundary evidence: original MIPS .pdata 409c11f8..409c1223. Semantic name remains unreviewed. */

void FUN_409c11f8(undefined4 param_1,undefined4 *param_2)

{
  mali_mem_ptr_unmap_area(*param_2);
  param_2[2] = 0;
  return;
}



/* 409c1224 FUN_409c1224 */

/* Boundary evidence: original MIPS .pdata 409c1224..409c127f. Semantic name remains unreviewed. */

bool FUN_409c1224(undefined4 param_1,undefined4 *param_2)

{
  int iVar1;
  
  iVar1 = mali_mem_ptr_map_area(*param_2,param_2[4],param_2[3] - param_2[4],0x40,0x10002);
  if (iVar1 != 0) {
    param_2[2] = iVar1;
  }
  return iVar1 != 0;
}



/* 409c1280 FUN_409c1280 */

/* Boundary evidence: original MIPS .pdata 409c1280..409c12b3. Semantic name remains unreviewed. */

undefined4 * FUN_409c1280(void)

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



/* 409c12b4 FUN_409c12b4 */

/* Boundary evidence: original MIPS .pdata 409c12b4..409c12e7. Semantic name remains unreviewed. */

undefined4 FUN_409c12b4(undefined4 *param_1)

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



/* 409c12e8 FUN_409c12e8 */

/* Boundary evidence: original MIPS .pdata 409c12e8..409c13af. Semantic name remains unreviewed. */

void FUN_409c12e8(int param_1)

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



/* 409c13b0 FUN_409c13b0 */

/* Boundary evidence: original MIPS .pdata 409c13b0..409c146b. Semantic name remains unreviewed. */

void FUN_409c13b0(int param_1)

{
  uint *puVar1;
  int iVar2;
  uint *puVar3;
  uint uVar4;
  
  if (*(int *)(param_1 + 4) != 0) {
    iVar2 = *(int *)(param_1 + 0xc);
    while (0 < iVar2) {
      FUN_409c12e8(param_1);
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



/* 409c146c FUN_409c146c */

/* Boundary evidence: original MIPS .pdata 409c146c..409c153f. Semantic name remains unreviewed. */

void FUN_409c146c(undefined4 *param_1,int param_2)

{
  undefined4 *puVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  
  FUN_409da7c8();
  if (*(int *)param_1[1] == 0x80) {
    puVar1 = (undefined4 *)mali_sys_malloc(0xa08);
    if (puVar1 == (undefined4 *)0x0) goto LAB_409c1534;
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
LAB_409c1534:
                    /* WARNING: Subroutine does not return */
  FUN_409da7e8(0x10);
}



/* 409c1540 FUN_409c1540 */

/* Boundary evidence: original MIPS .pdata 409c1540..409c1637. Semantic name remains unreviewed. */

undefined4 FUN_409c1540(undefined4 *param_1,int param_2,int *param_3)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  uint uVar3;
  
  puVar2 = (undefined4 *)param_1[2];
  uVar3 = param_2 + 0x3fU & 0xffffffc0;
  if ((uint)(puVar2[3] - puVar2[4]) < uVar3) {
    if (((uint)(puVar2[3] - puVar2[4]) < 0x1001) && (uVar3 < 0x10001)) {
      puVar2 = (undefined4 *)FUN_409c146c(param_1,0x10000);
      if (puVar2 == (undefined4 *)0x0) {
        return 0;
      }
      param_1[2] = puVar2;
    }
    else {
      puVar2 = (undefined4 *)FUN_409c146c(param_1,uVar3);
      if (puVar2 == (undefined4 *)0x0) {
        return 0;
      }
    }
    FUN_409c1224(param_1,puVar2);
  }
  uVar1 = puVar2[2];
  *param_3 = puVar2[1] + puVar2[4];
  puVar2[4] = puVar2[4] + uVar3;
  puVar2[2] = puVar2[2] + uVar3;
  return uVar1;
}



/* 409c1638 FUN_409c1638 */

/* Boundary evidence: original MIPS .pdata 409c1638..409c16d7. Semantic name remains unreviewed. */

undefined4 FUN_409c1638(undefined4 *param_1)

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
      iVar2 = FUN_409c146c(param_1,0x10000);
      if (iVar2 == 0) {
        return 0xffffffff;
      }
      param_1[2] = iVar2;
    }
    bVar1 = FUN_409c1224(param_1,(undefined4 *)param_1[2]);
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



/* 409c16d8 FUN_409c16d8 */

/* Boundary evidence: original MIPS .pdata 409c16d8..409c175b. Semantic name remains unreviewed. */

undefined4 FUN_409c16d8(undefined4 *param_1,undefined4 param_2)

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
    iVar2 = FUN_409c146c(param_1,0x10000);
    param_1[2] = iVar2;
    if (iVar2 != 0) {
      return 0;
    }
    FUN_409c13b0((int)param_1);
  }
  return 0xffffffff;
}



/* 409c175c FUN_409c175c */

void FUN_409c175c(uint *param_1,uint *param_2,int param_3,int param_4,ushort *param_5)

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



/* 409c1808 FUN_409c1808 */

uint FUN_409c1808(uint param_1,uint param_2)

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



/* 409c1924 FUN_409c1924 */

/* Boundary evidence: original MIPS .pdata 409c1924..409c1a17. Semantic name remains unreviewed. */

void FUN_409c1924(int param_1,undefined4 param_2)

{
  FUN_409da7c8();
  if ((((*(ushort *)(param_1 + 0xe) & 1) != 0) && (*(int *)(param_1 + 0x3dc) != 0)) &&
     (*(int *)(param_1 + 0x3e0) != 0)) {
    mali_frame_builder_get_frame_height(param_2);
    mali_frame_builder_get_frame_width(param_2);
  }
                    /* WARNING: Subroutine does not return */
  FUN_409da7e8(0x10);
}



/* 409c1a18 FUN_409c1a18 */

/* Boundary evidence: original MIPS .pdata 409c1a18..409c1a93. Semantic name remains unreviewed. */

undefined4 FUN_409c1a18(int param_1,int param_2)

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



/* 409c1a94 FUN_409c1a94 */

uint FUN_409c1a94(int param_1,uint param_2,int param_3)

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



/* 409c1af4 FUN_409c1af4 */

/* Boundary evidence: original MIPS .pdata 409c1af4..409c1bc7. Semantic name remains unreviewed. */

void FUN_409c1af4(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  FUN_409da808();
  if (((param_2 == 5) || (param_2 == 4)) || (iVar1 = 0, param_2 == 6)) {
    iVar1 = 1;
  }
  if (((param_2 == 1) || (param_2 == 3)) || (iVar2 = 0, param_2 == 2)) {
    iVar2 = 1;
  }
  iVar3 = param_1 + 0xc;
  FUN_409c1a94(iVar3,0x1b,iVar1);
  FUN_409c1a94(iVar3,0x1c,iVar2);
  FUN_409c1a94(iVar3,0x1d,(uint)(param_2 == 0));
  FUN_409c1a94(iVar3,0x1e,param_3);
  iVar1 = mali_frame_builder_get_supersample_factor(*(undefined4 *)(param_1 + 0x4f4));
  FUN_409c1a94(iVar3,0x1a,(uint)(iVar1 == 2));
                    /* WARNING: Subroutine does not return */
  FUN_409da838(0x10);
}



/* 409c1bc8 FUN_409c1bc8 */

/* Boundary evidence: original MIPS .pdata 409c1bc8..409c1c03. Semantic name remains unreviewed. */

int FUN_409c1bc8(int param_1,int param_2,int param_3)

{
  int iVar1;
  
  iVar1 = FUN_409c1a18(param_1,param_3);
  if ((iVar1 == 0) && (iVar1 = 0x501, -1 < param_2)) {
    iVar1 = 0;
  }
  return iVar1;
}



/* 409c1c04 FUN_409c1c04 */

/* Boundary evidence: original MIPS .pdata 409c1c04..409c1c4b. Semantic name remains unreviewed. */

int FUN_409c1c04(int param_1,int param_2,int param_3)

{
  int iVar1;
  
  iVar1 = FUN_409c1a18(param_1,param_2);
  if ((iVar1 == 0) && ((param_3 == 0x1401 || (iVar1 = 0x500, param_3 == 0x1403)))) {
    iVar1 = 0;
  }
  return iVar1;
}



/* 409c1c4c FUN_409c1c4c */

/* Boundary evidence: original MIPS .pdata 409c1c4c..409c1cab. Semantic name remains unreviewed. */

undefined4 FUN_409c1c4c(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_409c1924(param_1,*(undefined4 *)(param_1 + 0x4f4));
  if (iVar1 == 1) {
    uVar2 = 0xfffffffd;
  }
  else {
    FUN_409c1af4(param_1,param_2,0);
    uVar2 = 0;
  }
  return uVar2;
}



/* 409c1cac FUN_409c1cac */

/* Boundary evidence: original MIPS .pdata 409c1cac..409c1dcf. Semantic name remains unreviewed. */

void FUN_409c1cac(int param_1,uint param_2,uint param_3,int param_4)

{
  int iVar1;
  int *piVar2;
  undefined4 *puVar3;
  ushort *in_stack_00000040;
  uint *in_stack_00000044;
  uint *in_stack_00000048;
  
  FUN_409da688();
  iVar1 = FUN_409c1924(param_1,*(undefined4 *)(param_1 + 0x4f4));
  if (iVar1 != 1) {
    FUN_409c1af4(param_1,param_4,1);
    puVar3 = *(undefined4 **)(param_1 + 800);
    if (puVar3 == (undefined4 *)0x0) {
      if ((in_stack_00000040 != (ushort *)0x0) && (in_stack_00000044 != (uint *)0x0)) {
        FUN_409c175c(in_stack_00000048,in_stack_00000044,param_2,param_3,in_stack_00000040);
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
          FUN_409b5ad4(piVar2,(uint)in_stack_00000040,param_2,param_3);
        }
      }
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_409da6b0(0x18);
}



/* 409c1dd0 FUN_409c1dd0 */

/* Boundary evidence: original MIPS .pdata 409c1dd0..409c1dff. Semantic name remains unreviewed. */

void FUN_409c1dd0(undefined4 *param_1,undefined4 param_2)

{
  int in_stack_00000014;
  int in_stack_00000018;
  
  FUN_409b5880(param_1,param_2,in_stack_00000014,in_stack_00000018);
  return;
}



/* 409c1e00 FUN_409c1e00 */

/* Boundary evidence: original MIPS .pdata 409c1e00..409c1e1b. Semantic name remains unreviewed. */

void FUN_409c1e00(undefined4 *param_1,uint param_2,int param_3,uint param_4)

{
  FUN_409b59a8(param_1,param_2,param_3,param_4);
  return;
}



/* 409c1e1c FUN_409c1e1c */

/* Boundary evidence: original MIPS .pdata 409c1e1c..409c1ffb. Semantic name remains unreviewed. */

void FUN_409c1e1c(int param_1,undefined4 param_2,undefined1 *param_3,int param_4,int param_5,
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



/* 409c1ffc FUN_409c1ffc */

/* WARNING: Removing unreachable block (ram,0x409c20e8) */
/* Boundary evidence: original MIPS .pdata 409c1ffc..409c22c7. Semantic name remains unreviewed. */

void FUN_409c1ffc(int param_1,int param_2,int param_3,int param_4)

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
  
  FUN_409da758();
  uVar1 = DAT_409dd288;
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
          FUN_409c1e1c((int)&stack0x00000240,0x200,&stack0x00000040,iVar4,iStack00000028,iVar8,
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
  FUN_409b290c(uVar1);
                    /* WARNING: Subroutine does not return */
  FUN_409da790(0x648);
}



/* 409c22c8 FUN_409c22c8 */

undefined4 FUN_409c22c8(int param_1,int param_2)

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



/* 409c23ac FUN_409c23ac */

uint FUN_409c23ac(uint param_1)

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



/* 409c2428 FUN_409c2428 */

/* Boundary evidence: original MIPS .pdata 409c2428..409c26ff. Semantic name remains unreviewed. */

void FUN_409c2428(int param_1,undefined4 *param_2,int param_3)

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
  
  FUN_409da758();
  iStack00000040 = 0;
  iStack00000044 = 0;
  iStack00000030 = param_3;
  puStack00000034 = param_2;
  iStack00000038 = param_1;
  uStack0000002c = FUN_409c22c8(in_stack_0000008c,in_stack_00000090);
  uVar2 = in_stack_00000080;
  if ((int)in_stack_00000080 <= (int)in_stack_00000084) {
    uVar2 = in_stack_00000084;
  }
  if ((((1 < (int)uVar2) && (in_stack_00000094 != 0)) &&
      (iVar1 = FUN_409c3314(in_stack_0000008c,in_stack_00000090), iVar1 != 0)) &&
     (uVar2 = FUN_409c23ac(uVar2), -1 < (int)uVar2)) {
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
            FUN_409c1ffc(in_stack_00000094,in_stack_00000080,in_stack_00000084,in_stack_00000098);
            iVar3 = FUN_409c85c0(iStack00000038,puStack00000034,iStack00000030,uVar7);
            if (iVar3 != 0) {
              mali_sys_free(iVar6);
              mali_sys_free(iVar4);
              goto LAB_409c26f4;
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
        goto LAB_409c26f4;
      }
      mali_sys_free(iVar6);
    }
    if (iVar4 != 0) {
      mali_sys_free(iVar4);
    }
  }
LAB_409c26f4:
                    /* WARNING: Subroutine does not return */
  FUN_409da790(0x48);
}



/* 409c2700 FUN_409c2700 */

/* Boundary evidence: original MIPS .pdata 409c2700..409c271b. Semantic name remains unreviewed. */

void FUN_409c2700(void)

{
  mali_sys_free();
  return;
}



/* 409c271c FUN_409c271c */

/* Boundary evidence: original MIPS .pdata 409c271c..409c275b. Semantic name remains unreviewed. */

undefined4 * FUN_409c271c(undefined4 param_1)

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



/* 409c275c FUN_409c275c */

/* Boundary evidence: original MIPS .pdata 409c275c..409c2797. Semantic name remains unreviewed. */

undefined4 FUN_409c275c(int param_1,uint param_2)

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



/* 409c2798 FUN_409c2798 */

/* Boundary evidence: original MIPS .pdata 409c2798..409c27f7. Semantic name remains unreviewed. */

undefined4 FUN_409c2798(int param_1,uint param_2)

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



/* 409c27f8 FUN_409c27f8 */

/* Boundary evidence: original MIPS .pdata 409c27f8..409c2843. Semantic name remains unreviewed. */

void FUN_409c27f8(undefined4 param_1,int param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  
  FUN_409da7c8();
  if (0 < param_2) {
    do {
      uVar1 = __mali_named_list_remove(param_1,*param_3);
      mali_sys_free(uVar1);
      param_3 = param_3 + 1;
      param_2 = param_2 + -1;
    } while (param_2 != 0);
  }
                    /* WARNING: Subroutine does not return */
  FUN_409da7e8(0x10);
}



/* 409c2844 FUN_409c2844 */

/* Boundary evidence: original MIPS .pdata 409c2844..409c2943. Semantic name remains unreviewed. */

undefined4 FUN_409c2844(undefined4 param_1,int param_2,int *param_3,undefined4 param_4)

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
LAB_409c2930:
          FUN_409c27f8(param_1,iVar4,param_3);
          return 0x505;
        }
        *puVar2 = param_4;
        puVar2[1] = 0;
        iVar3 = __mali_named_list_insert(param_1,iVar1,puVar2);
        if (iVar3 != 0) {
          mali_sys_free(puVar2);
          goto LAB_409c2930;
        }
        iVar4 = iVar4 + 1;
        *piVar5 = iVar1;
        piVar5 = piVar5 + 1;
      } while (iVar4 < param_2);
    }
  }
  return 0;
}



/* 409c2984 FUN_409c2984 */

/* Boundary evidence: original MIPS .pdata 409c2984..409c29db. Semantic name remains unreviewed. */

void FUN_409c2984(int *param_1,int param_2,int param_3,int param_4,int param_5)

{
  if (param_1[1] == 0) {
    param_1[0x11] = param_4;
    param_1[0x10] = param_3;
    param_1[0x12] = param_5;
  }
  else if (param_2 == 2) {
    FUN_409bc578(*param_1,param_3,param_4,param_5);
  }
  return;
}



/* 409c29dc FUN_409c29dc */

/* Boundary evidence: original MIPS .pdata 409c29dc..409c2a3f. Semantic name remains unreviewed. */

void FUN_409c29dc(int *param_1,int param_2,int *param_3,int *param_4,int *param_5)

{
  if (param_1[1] == 0) {
    *param_3 = param_1[0x10];
    *param_4 = param_1[0x11];
    *param_5 = param_1[0x12];
  }
  else if (param_2 == 2) {
    FUN_409bc4f0(*param_1,param_3,param_4,param_5);
  }
  return;
}



/* 409c2a40 FUN_409c2a40 */

/* Boundary evidence: original MIPS .pdata 409c2a40..409c30af. Semantic name remains unreviewed. */

void FUN_409c2a40(undefined4 *param_1,uint param_2)

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
  
  FUN_409da758();
  uStack00000018 = 0;
  uStack0000001c = 0;
  uStack00000020 = 0;
  if (((param_1[1] == 2) && (param_1[0x122] != 0)) &&
     (iVar1 = FUN_409bddac((int)param_1), iVar1 != 0)) goto LAB_409c30a8;
  iVar1 = 0;
  if ((param_2 & 0xffffbaff) != 0) {
    iVar1 = 0x501;
  }
  if (iVar1 != 0) goto LAB_409c30a8;
  uVar10 = param_1[0x13d];
  iVar1 = FUN_409c59f4(param_1);
  if (iVar1 != 0) goto LAB_409c30a8;
  piVar11 = param_1 + 0x121;
  FUN_409c29dc(piVar11,param_1[1],(int *)&stack0x00000018,(int *)&stack0x0000001c,
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
  iVar2 = FUN_409c1924((int)param_1,param_1[0x13d]);
  if (iVar2 == 1) {
    if (param_1[0x144] != 0) {
      FUN_409c12e8(param_1[0x144]);
    }
    mali_frame_builder_write_unlock(param_1[0x13d]);
    goto LAB_409c30a8;
  }
  if (((*(ushort *)((int)param_1 + 0xe) & 1) != 0) &&
     ((((param_1[0xf5] != 0 || (param_1[0xf6] != 0)) ||
       (iVar2 = mali_frame_builder_get_frame_width(uVar10), param_1[0xf7] != iVar2)) ||
      (iVar2 = mali_frame_builder_get_frame_height(uVar10), param_1[0xf8] != iVar2)))) {
    FUN_409c2984(piVar11,param_1[1],(param_2 & 0x4000) != 0 | uStack00000018,
                 (param_2 & 0x100) != 0 | uStack0000001c,(param_2 & 0x400) != 0 | uStack00000020);
    FUN_409b7a90(param_1,param_2);
    if (param_1[0x144] != 0) {
      FUN_409c12e8(param_1[0x144]);
    }
    mali_frame_builder_write_unlock(param_1[0x13d]);
    goto LAB_409c30a8;
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
      iVar2 = FUN_409bc7c4(*piVar11,0xd55);
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
LAB_409c2f68:
    iVar1 = 1;
LAB_409c2f74:
    if ((uVar12 == 0) || (iVar2 = 1, iVar8 != 0)) {
      iVar2 = 0;
    }
    if ((uVar5 == 0) || (iVar8 = 1, in_stack_00000024 != 0)) {
      iVar8 = 0;
    }
    FUN_409c2984(piVar11,param_1[1],iVar1,iVar2,iVar8);
    iVar1 = FUN_409b7a90(param_1,param_2);
    if (param_1[0x144] != 0) {
      FUN_409c12e8(param_1[0x144]);
    }
    mali_frame_builder_write_unlock(param_1[0x13d]);
  }
  else {
    if (((iVar8 == 0) && (uVar12 != 0)) || ((in_stack_00000024 == 0 && (uVar5 != 0)))) {
      if ((uStack00000018 != 0) && (iVar1 == 0)) goto LAB_409c2f68;
      iVar1 = 0;
      goto LAB_409c2f74;
    }
    FUN_409c2984(piVar11,param_1[1],0,0,0);
    if (param_1[0x144] != 0) {
      FUN_409c12e8(param_1[0x144]);
    }
    mali_frame_builder_write_unlock(param_1[0x13d]);
    mali_frame_builder_reset(param_1[0x13d]);
    iVar1 = FUN_409c508c(param_1);
    if (iVar1 != 0) goto LAB_409c30a8;
    iVar1 = FUN_409c1638((undefined4 *)param_1[0x144]);
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
LAB_409c30a8:
                    /* WARNING: Subroutine does not return */
  FUN_409da790(0x48);
}



/* 409c30ec gles_finish */

/* Boundary evidence: original MIPS .pdata 409c30ec..409c3213. Semantic name remains unreviewed.
   gles_finish */

void gles_finish(undefined4 *param_1)

{
  int iVar1;
  int iVar2;
  
                    /* 0x130ec  7  _gles_finish */
  FUN_409da7c8();
  if (*(code **)(param_1[2] + 0x3b4) != (code *)0x0) {
    (**(code **)(param_1[2] + 0x3b4))(param_1);
  }
  if ((((param_1[1] != 2) || (param_1[0x122] == 0)) ||
      (iVar1 = FUN_409bddac((int)param_1), iVar1 == 0)) &&
     ((iVar1 = param_1[0x13e], iVar1 != 0 && ((param_1[0x122] != 0 || (param_1[0x12e] != 0)))))) {
    iVar2 = mali_frame_builder_flush(iVar1,0,0);
    if (iVar2 == 0) {
      mali_frame_builder_wait(iVar1);
      FUN_409c4b20((int)param_1);
    }
    else {
      mali_frame_builder_reset(param_1[0x13d]);
      iVar1 = FUN_409c508c(param_1);
      if (iVar1 == 0) {
        FUN_409c1638((undefined4 *)param_1[0x144]);
      }
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_409da7e8(0x10);
}



/* 409c3214 gles_flush */

/* Boundary evidence: original MIPS .pdata 409c3214..409c3313. Semantic name remains unreviewed.
   gles_flush */

int gles_flush(undefined4 *param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
                    /* 0x13214  8  _gles_flush */
  uVar3 = 0;
  if (*(code **)(param_1[2] + 0x3b4) != (code *)0x0) {
    (**(code **)(param_1[2] + 0x3b4))(param_1);
  }
  if ((param_1[1] == 2) && (param_1[0x122] != 0)) {
    iVar1 = FUN_409bddac((int)param_1);
    if (iVar1 != 0) {
      return iVar1;
    }
    uVar3 = param_1[0x121];
  }
  iVar1 = mali_frame_builder_flush(param_1[0x13d],0,uVar3);
  if (iVar1 != 0) {
    mali_frame_builder_reset(param_1[0x13d]);
    iVar2 = FUN_409c508c(param_1);
    if ((iVar2 == 0) && (iVar2 = FUN_409c1638((undefined4 *)param_1[0x144]), iVar2 == 0)) {
      iVar2 = iVar1;
    }
    if (((iVar2 != -3) && (-3 < iVar2)) && (iVar2 < 0)) {
      return 0x505;
    }
  }
  return 0;
}



/* 409c3314 FUN_409c3314 */

undefined4 FUN_409c3314(int param_1,int param_2)

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



/* 409c33ec FUN_409c33ec */

undefined4 FUN_409c33ec(uint param_1)

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



/* 409c34a8 FUN_409c34a8 */

/* Boundary evidence: original MIPS .pdata 409c34a8..409c354b. Semantic name remains unreviewed. */

void FUN_409c34a8(int param_1,int param_2,undefined1 *param_3,int param_4)

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
  
  FUN_409da758();
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
  FUN_409da790(0x28);
}



/* 409c354c FUN_409c354c */

/* Boundary evidence: original MIPS .pdata 409c354c..409c35fb. Semantic name remains unreviewed. */

void FUN_409c354c(int param_1,int param_2,undefined1 *param_3,int param_4)

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
  
  FUN_409da758();
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
  FUN_409da790(0x28);
}



/* 409c35fc FUN_409c35fc */

/* Boundary evidence: original MIPS .pdata 409c35fc..409c369f. Semantic name remains unreviewed. */

void FUN_409c35fc(int param_1,int param_2,undefined1 *param_3,int param_4)

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
  
  FUN_409da758();
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
  FUN_409da790(0x28);
}



/* 409c36a0 FUN_409c36a0 */

/* Boundary evidence: original MIPS .pdata 409c36a0..409c375b. Semantic name remains unreviewed. */

void FUN_409c36a0(int param_1,int param_2,undefined1 *param_3,int param_4)

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
  
  FUN_409da758();
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
  FUN_409da790(0x28);
}



/* 409c375c FUN_409c375c */

/* Boundary evidence: original MIPS .pdata 409c375c..409c3823. Semantic name remains unreviewed. */

void FUN_409c375c(int param_1,int param_2,undefined1 *param_3,int param_4)

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
  
  FUN_409da758();
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
  FUN_409da790(0x28);
}



/* 409c3824 FUN_409c3824 */

/* Boundary evidence: original MIPS .pdata 409c3824..409c392b. Semantic name remains unreviewed. */

void FUN_409c3824(int param_1,int param_2,byte *param_3,int param_4)

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
  
  FUN_409da758();
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
  FUN_409da790(0x28);
}



/* 409c392c FUN_409c392c */

/* Boundary evidence: original MIPS .pdata 409c392c..409c3a33. Semantic name remains unreviewed. */

void FUN_409c392c(int param_1,int param_2,byte *param_3,int param_4)

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
  
  FUN_409da758();
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
  FUN_409da790(0x28);
}



/* 409c3a34 FUN_409c3a34 */

/* Boundary evidence: original MIPS .pdata 409c3a34..409c3b23. Semantic name remains unreviewed. */

void FUN_409c3a34(int param_1,int param_2,byte *param_3,int param_4)

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
  
  FUN_409da758();
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
  FUN_409da790(0x28);
}



/* 409c3dc4 FUN_409c3dc4 */

/* Boundary evidence: original MIPS .pdata 409c3dc4..409c3e1b. Semantic name remains unreviewed. */

undefined4 FUN_409c3dc4(int *param_1)

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



/* 409c3e1c FUN_409c3e1c */

/* Boundary evidence: original MIPS .pdata 409c3e1c..409c3ebb. Semantic name remains unreviewed. */

void FUN_409c3e1c(undefined4 *param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  FUN_409da7c8();
  uVar2 = param_1[0x13e];
  iVar1 = mali_frame_builder_flush(uVar2,0,0);
  if (iVar1 == 0) {
    mali_frame_builder_wait(uVar2);
    FUN_409c4b20((int)param_1);
  }
  else {
    mali_frame_builder_reset(param_1[0x13d]);
    iVar1 = FUN_409c508c(param_1);
    if (iVar1 == 0) {
      FUN_409c1638((undefined4 *)param_1[0x144]);
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_409da7e8(0x10);
}



/* 409c3ebc FUN_409c3ebc */

/* Boundary evidence: original MIPS .pdata 409c3ebc..409c4507. Semantic name remains unreviewed. */

void FUN_409c3ebc(undefined4 *param_1,int param_2,int param_3,int param_4)

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
  
  FUN_409da758();
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
        (iVar2 = FUN_409bddac((int)param_1), iVar2 != 0)) ||
       ((iVar2 = FUN_409c3e1c(param_1), iVar2 != 0 ||
        (iVar2 = mali_frame_builder_get_attachment(param_1[0x13e],0), iVar2 == 0)))) ||
      (iVar3 = mali_render_attachment_get_target(iVar2,0,0), iVar3 == 0)))) goto LAB_409c44fc;
  uVar5 = (uint)*(ushort *)(iVar3 + 0xc);
  uVar7 = (uint)*(ushort *)(iVar3 + 0xe);
  iVar9 = *(int *)(iVar3 + 0x14);
  if ((uVar5 == 0) || (uVar7 == 0)) goto LAB_409c44fc;
  mali_surface_access_lock(iVar3);
  iVar4 = mali_surface_map(iVar3,1);
  if (iVar4 == 0) {
LAB_409c4154:
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
        goto LAB_409c4154;
      }
      iStack00000028 = 4;
    }
    iVar2 = iVar4;
    if ((puStack00000038[1] == 2) && (puStack00000038[0x122] != 0)) {
      iVar2 = mali_sys_malloc(*(undefined4 *)(iVar3 + 0x2c));
      if (iVar2 == 0) {
        mali_surface_unmap(iVar3);
        goto LAB_409c4154;
      }
      uVar6 = FUN_409c3dc4((int *)(iVar3 + 0x14));
      uVar6 = (uVar6 >> 3) * (uint)*(ushort *)(iVar3 + 0xc);
      mali_pixel_to_texel_format(iVar9);
      iVar9 = m200_texture_swizzle(iVar2,0,iVar4,*(undefined4 *)(iVar3 + 0x20));
      iStack0000002c = iVar2;
      if (iVar9 != 0) {
        mali_surface_unmap(iVar3);
        mali_surface_access_unlock(iVar3);
        goto LAB_409c44fc;
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
          FUN_409c34a8(iVar2,uVar6,in_stack_00000094,iVar4);
        }
        else if (in_stack_0000008c == 0x1907) {
          FUN_409c36a0(iVar2,uVar6,in_stack_00000094,iVar4);
        }
        else if (in_stack_0000008c == 0x1908) {
          FUN_409c375c(iVar2,uVar6,in_stack_00000094,iVar4);
        }
        else if (in_stack_0000008c == 0x1909) {
          FUN_409c35fc(iVar2,uVar6,in_stack_00000094,iVar4);
        }
        else if (in_stack_0000008c == 0x190a) {
          FUN_409c354c(iVar2,uVar6,in_stack_00000094,iVar4);
        }
      }
      else if (in_stack_00000090 == 0x8033) {
        FUN_409c392c(iVar2,uVar6,in_stack_00000094,iVar4);
      }
      else if (in_stack_00000090 == 0x8034) {
        FUN_409c3824(iVar2,uVar6,in_stack_00000094,iVar4);
      }
      else if (in_stack_00000090 == 0x8363) {
        FUN_409c3a34(iVar2,uVar6,in_stack_00000094,iVar4);
      }
    }
    if ((puVar1[1] == 2) && (iStack0000002c != 0)) {
      mali_sys_free(iStack0000002c);
    }
    mali_surface_unmap(iVar3);
    mali_surface_access_unlock(iVar3);
  }
LAB_409c44fc:
                    /* WARNING: Subroutine does not return */
  FUN_409da790(0x50);
}



/* 409c4508 FUN_409c4508 */

/* Boundary evidence: original MIPS .pdata 409c4508..409c45c3. Semantic name remains unreviewed. */

undefined4
FUN_409c4508(undefined4 *param_1,int param_2,int param_3,int param_4,int param_5,int param_6,
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
    uVar1 = FUN_409c3ebc(param_1,param_2,param_3,param_4);
    return uVar1;
  }
  return 0x500;
}



/* 409c45c4 FUN_409c45c4 */

/* Boundary evidence: original MIPS .pdata 409c45c4..409c465b. Semantic name remains unreviewed. */

undefined4 FUN_409c45c4(int param_1)

{
  int iVar1;
  undefined **ppuVar2;
  int iVar3;
  
  if (param_1 != 0) {
    iVar3 = 1;
    ppuVar2 = &PTR_s_glEGLImageTargetRenderbufferStor_409b1bab_1_409b17e8;
    do {
      iVar1 = mali_sys_strcmp(*ppuVar2,param_1);
      if (iVar1 == 0) {
        return *(undefined4 *)(&UNK_409b17e4 + iVar3 * 8);
      }
      ppuVar2 = ppuVar2 + 2;
      iVar3 = iVar3 + 1;
    } while ((int)ppuVar2 < 0x409b17f0);
  }
  return 0;
}



/* 409c465c FUN_409c465c */

/* Boundary evidence: original MIPS .pdata 409c465c..409c4693. Semantic name remains unreviewed. */

void FUN_409c465c(int param_1,int param_2)

{
  if (param_2 == 2) {
    mali_sys_atomic_inc(param_1 + 0xc);
  }
  mali_sys_atomic_inc(param_1);
  return;
}



/* 409c4694 FUN_409c4694 */

/* Boundary evidence: original MIPS .pdata 409c4694..409c474b. Semantic name remains unreviewed. */

undefined4 FUN_409c4694(int param_1,int param_2)

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



/* 409c474c FUN_409c474c */

/* Boundary evidence: original MIPS .pdata 409c474c..409c4767. Semantic name remains unreviewed. */

void FUN_409c474c(int param_1)

{
  mali_sys_mutex_unlock(*(undefined4 *)(param_1 + 0x1c));
  return;
}



/* 409c4768 FUN_409c4768 */

/* Boundary evidence: original MIPS .pdata 409c4768..409c4783. Semantic name remains unreviewed. */

void FUN_409c4768(int param_1)

{
  mali_sys_mutex_lock(*(undefined4 *)(param_1 + 0x1c));
  return;
}



/* 409c4784 FUN_409c4784 */

/* Boundary evidence: original MIPS .pdata 409c4784..409c482f. Semantic name remains unreviewed. */

void FUN_409c4784(int param_1)

{
  if (*(int *)(param_1 + 4) != 0) {
    __mali_named_list_free(*(int *)(param_1 + 4),FUN_409c8a50);
  }
  *(undefined4 *)(param_1 + 4) = 0;
  if (*(int *)(param_1 + 8) != 0) {
    __mali_named_list_free(*(int *)(param_1 + 8),FUN_409c61b0);
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



/* 409c4830 FUN_409c4830 */

/* Boundary evidence: original MIPS .pdata 409c4830..409c489f. Semantic name remains unreviewed. */

int FUN_409c4830(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = mali_sys_malloc(0x20);
  if (iVar1 != 0) {
    mali_sys_memset(iVar1,0,0x20);
    iVar2 = FUN_409c4694(iVar1,param_1);
    if (iVar2 == 0) {
      return iVar1;
    }
    FUN_409c4784(iVar1);
  }
  return 0;
}



/* 409c48a0 FUN_409c48a0 */

/* Boundary evidence: original MIPS .pdata 409c48a0..409c4907. Semantic name remains unreviewed. */

void FUN_409c48a0(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  
  if ((param_2 == 2) && (iVar1 = mali_sys_atomic_dec_and_return(param_1 + 0xc), iVar1 == 0)) {
    mali_sys_mutex_lock(*(undefined4 *)(param_1 + 0x1c));
    FUN_409cc5d0(param_1,param_2,param_3,param_4);
    mali_sys_mutex_unlock(*(undefined4 *)(param_1 + 0x1c));
  }
  iVar1 = mali_sys_atomic_dec_and_return(param_1);
  if (iVar1 == 0) {
    FUN_409c4784(param_1);
  }
  return;
}



/* 409c4908 FUN_409c4908 */

/* Boundary evidence: original MIPS .pdata 409c4908..409c4963. Semantic name remains unreviewed. */

void FUN_409c4908(int param_1)

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



/* 409c4964 gles_shutdown */

/* Boundary evidence: original MIPS .pdata 409c4964..409c499b. Semantic name remains unreviewed.
   gles_shutdown */

void gles_shutdown(int *param_1)

{
                    /* 0x14964  15  _gles_shutdown */
  if (*param_1 != 0) {
    mali_sys_mutex_destroy();
    *param_1 = 0;
  }
  return;
}



/* 409c499c gles_initialize */

/* Boundary evidence: original MIPS .pdata 409c499c..409c49f7. Semantic name remains unreviewed.
   gles_initialize */

undefined4 gles_initialize(int *param_1)

{
  int iVar1;
  
                    /* 0x1499c  9  _gles_initialize */
  DAT_409dd38c = param_1;
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



/* 409c49f8 gles_make_current */

/* Boundary evidence: original MIPS .pdata 409c49f8..409c4acb. Semantic name remains unreviewed.
   gles_make_current */

int gles_make_current(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  
                    /* 0x149f8  10  _gles_make_current */
  puVar1 = DAT_409dd38c;
  iVar2 = mali_sys_thread_key_get_data(4);
  iVar3 = mali_sys_thread_key_set_data(4,param_1);
  if (iVar3 == 0) {
    mali_sys_mutex_lock(*DAT_409dd38c);
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
    mali_sys_mutex_unlock(*DAT_409dd38c);
    iVar3 = 0;
  }
  return iVar3;
}



/* 409c4acc FUN_409c4acc */

/* Boundary evidence: original MIPS .pdata 409c4acc..409c4b17. Semantic name remains unreviewed. */

undefined4 FUN_409c4acc(void)

{
  undefined4 uVar1;
  
  if (DAT_409dd38c == 0) {
    uVar1 = 0;
  }
  else if (*(int *)(DAT_409dd38c + 8) == 0) {
    uVar1 = *(undefined4 *)(DAT_409dd38c + 0xc);
  }
  else {
    uVar1 = mali_sys_thread_key_get_data(4);
  }
  return uVar1;
}



/* 409c4b20 FUN_409c4b20 */

/* Boundary evidence: original MIPS .pdata 409c4b20..409c4bcb. Semantic name remains unreviewed. */

void FUN_409c4b20(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 in_stack_00000010;
  
  FUN_409da7c8();
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
  FUN_409da7e8(0x18);
}



/* 409c4cdc gles_set_read_frame_builder */

/* Boundary evidence: original MIPS .pdata 409c4cdc..409c4d47. Semantic name remains unreviewed.
   gles_set_read_frame_builder */

void gles_set_read_frame_builder(int param_1,undefined4 param_2,int param_3)

{
                    /* 0x14cdc  12  _gles_set_read_frame_builder */
  FUN_409da7c8();
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
  FUN_409da7e8(0x10);
}



/* 409c4d48 FUN_409c4d48 */

/* Boundary evidence: original MIPS .pdata 409c4d48..409c4d83. Semantic name remains unreviewed. */

void FUN_409c4d48(int param_1)

{
  if (*(int *)(param_1 + 0x510) != 0) {
    FUN_409c12e8(*(int *)(param_1 + 0x510));
  }
  mali_frame_builder_write_unlock(*(undefined4 *)(param_1 + 0x4f4));
  return;
}



/* 409c4d84 FUN_409c4d84 */

/* Boundary evidence: original MIPS .pdata 409c4d84..409c4db3. Semantic name remains unreviewed. */

void FUN_409c4d84(int param_1)

{
  FUN_409c13b0(param_1);
  mali_sys_free(param_1);
  return;
}



/* 409c4df8 FUN_409c4df8 */

/* Boundary evidence: original MIPS .pdata 409c4df8..409c4f0f. Semantic name remains unreviewed. */

undefined4 FUN_409c4df8(int param_1)

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
    goto LAB_409c4ecc;
  }
  if (iVar3 != -0x48) {
    if (*(int *)(iVar3 + 0x50) == 0x1702) {
      iVar1 = FUN_409c682c(*(int *)(iVar3 + 100));
      piVar4 = *(int **)((iVar1 * 0xd + *(int *)(iVar3 + 0x60)) * 4 +
                        *(int *)(*(int *)(iVar3 + 0x58) + 0x34));
      if (piVar4 != (int *)0x0) {
        iVar3 = *piVar4;
        goto LAB_409c4e84;
      }
    }
    else if (*(int *)(iVar3 + 0x50) == 0x8d41) {
      iVar3 = *(int *)(*(int *)(iVar3 + 0x58) + 0x28);
LAB_409c4e84:
      if (iVar3 != 0) {
        mali_pixel_format_get_bpc
                  (*(undefined4 *)(iVar3 + 0x14),auStack_14,auStack_18,auStack_1c,auStack_20,
                   auStack_24,&local_28);
        goto LAB_409c4ecc;
      }
    }
  }
  local_28 = 0;
LAB_409c4ecc:
  uVar2 = 1;
  if (((*(uint *)(*(int *)(param_1 + 0x504) + 0x40) & 0x10) == 0) || (local_28 < 1)) {
    uVar2 = 0;
  }
  return uVar2;
}



/* 409c4f10 FUN_409c4f10 */

/* Boundary evidence: original MIPS .pdata 409c4f10..409c5027. Semantic name remains unreviewed. */

undefined4 FUN_409c4f10(int param_1)

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
    goto LAB_409c4fe4;
  }
  if (iVar3 != -0x24) {
    if (*(int *)(iVar3 + 0x2c) == 0x1702) {
      iVar1 = FUN_409c682c(*(int *)(iVar3 + 0x40));
      piVar4 = *(int **)((iVar1 * 0xd + *(int *)(iVar3 + 0x3c)) * 4 +
                        *(int *)(*(int *)(iVar3 + 0x34) + 0x34));
      if (piVar4 != (int *)0x0) {
        iVar3 = *piVar4;
        goto LAB_409c4f9c;
      }
    }
    else if (*(int *)(iVar3 + 0x2c) == 0x8d41) {
      iVar3 = *(int *)(*(int *)(iVar3 + 0x34) + 0x28);
LAB_409c4f9c:
      if (iVar3 != 0) {
        mali_pixel_format_get_bpc
                  (*(undefined4 *)(iVar3 + 0x14),auStack_14,auStack_18,auStack_1c,auStack_20,
                   &local_28,auStack_24);
        goto LAB_409c4fe4;
      }
    }
  }
  local_28 = 0;
LAB_409c4fe4:
  uVar2 = 1;
  if (((*(uint *)(*(int *)(param_1 + 0x504) + 0x40) & 2) == 0) || (local_28 < 1)) {
    uVar2 = 0;
  }
  return uVar2;
}



/* 409c5028 FUN_409c5028 */

void FUN_409c5028(int param_1,uint param_2,int param_3)

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



/* 409c508c FUN_409c508c */

/* Boundary evidence: original MIPS .pdata 409c508c..409c515f. Semantic name remains unreviewed. */

int FUN_409c508c(undefined4 *param_1)

{
  undefined4 *puVar1;
  uint uVar2;
  int iVar3;
  
  mali_frame_builder_wait(param_1[0x13d]);
  param_1[0x144] = 0;
  param_1[0x134] = 0;
  FUN_409c4b20((int)param_1);
  uVar2 = param_1[3];
  param_1[3] = uVar2 | 0x800000;
  param_1[3] = uVar2 | 0x1800000;
  puVar1 = (undefined4 *)mali_sys_malloc(0x10);
  param_1[0x144] = puVar1;
  if (puVar1 == (undefined4 *)0x0) {
    iVar3 = -1;
  }
  else {
    iVar3 = FUN_409c16d8(puVar1,*param_1);
    if (((iVar3 != 0) ||
        (iVar3 = mali_frame_builder_add_callback(param_1[0x13d],FUN_409c4d84,param_1[0x144]),
        iVar3 != 0)) && (param_1[0x144] != 0)) {
      FUN_409c13b0(param_1[0x144]);
      mali_sys_free(param_1[0x144]);
      param_1[0x144] = 0;
    }
  }
  return iVar3;
}



/* 409c5160 FUN_409c5160 */

void FUN_409c5160(int param_1,int param_2)

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
    if (((*(uint *)(*(int *)(param_1 + 0x504) + 0x40) & 0x20) != 0) && (bVar1)) goto LAB_409c51c0;
  }
  iVar2 = 0;
LAB_409c51c0:
  *(uint *)(iVar3 + 0x20) = *(uint *)(iVar3 + 0x20) & 0xfffffeff ^ iVar2 << 8;
  return;
}



/* 409c51e0 FUN_409c51e0 */

void FUN_409c51e0(int param_1,int param_2)

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
    if (((*(uint *)(*(int *)(param_1 + 0x504) + 0x40) & 0x20) != 0) && (bVar1)) goto LAB_409c5240;
  }
  iVar2 = 0;
LAB_409c5240:
  *(uint *)(iVar3 + 0x20) = *(uint *)(iVar3 + 0x20) & 0xffffff7f ^ iVar2 << 7;
  return;
}



/* 409c5260 FUN_409c5260 */

void FUN_409c5260(int param_1)

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



/* 409c52e4 FUN_409c52e4 */

/* Boundary evidence: original MIPS .pdata 409c52e4..409c5407. Semantic name remains unreviewed. */

void FUN_409c52e4(int param_1,undefined4 param_2,int param_3)

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



/* 409c5408 FUN_409c5408 */

/* Boundary evidence: original MIPS .pdata 409c5408..409c5463. Semantic name remains unreviewed. */

void FUN_409c5408(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0x504);
  *(char *)(iVar2 + 0x59) = (char)param_2;
  iVar1 = FUN_409c4df8(param_1);
  if (iVar1 == 0) {
    param_2 = 0;
  }
  *(uint *)(iVar2 + 0x1c) = param_2 << 8 ^ *(uint *)(iVar2 + 0x1c) & 0xffff00ff;
  return;
}



/* 409c5464 FUN_409c5464 */

/* Boundary evidence: original MIPS .pdata 409c5464..409c54bb. Semantic name remains unreviewed. */

void FUN_409c5464(int param_1,uint param_2)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0x504);
  *(char *)(iVar2 + 0x52) = (char)param_2;
  iVar1 = FUN_409c4df8(param_1);
  if (iVar1 == 0) {
    param_2 = 0;
  }
  *(uint *)(iVar2 + 0x1c) = *(uint *)(iVar2 + 0x1c) & 0xffffff00 ^ param_2;
  return;
}



/* 409c54bc FUN_409c54bc */

/* Boundary evidence: original MIPS .pdata 409c54bc..409c5563. Semantic name remains unreviewed. */

void FUN_409c54bc(int param_1,uint param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0x504);
  *(char *)(iVar2 + 0x5a) = (char)param_2;
  *(char *)(iVar2 + 0x5b) = (char)param_3;
  *(char *)(iVar2 + 0x5c) = (char)param_4;
  iVar1 = FUN_409c4df8(param_1);
  if (iVar1 == 0) {
    param_3 = 0;
    param_4 = 0;
  }
  *(uint *)(iVar2 + 0x18) =
       ((param_2 & 0xffffffc7 ^ param_3 << 3) << 3 ^ *(uint *)(iVar2 + 0x18) & 0xfffffe07) &
       0xfffff1ff ^ param_4 << 9;
  return;
}



/* 409c5564 FUN_409c5564 */

/* Boundary evidence: original MIPS .pdata 409c5564..409c560b. Semantic name remains unreviewed. */

void FUN_409c5564(int param_1,uint param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0x504);
  *(char *)(iVar2 + 0x53) = (char)param_2;
  *(char *)(iVar2 + 0x54) = (char)param_3;
  *(char *)(iVar2 + 0x55) = (char)param_4;
  iVar1 = FUN_409c4df8(param_1);
  if (iVar1 == 0) {
    param_3 = 0;
    param_4 = 0;
  }
  *(uint *)(iVar2 + 0x14) =
       ((param_2 & 0xffffffc7 ^ param_3 << 3) << 3 ^ *(uint *)(iVar2 + 0x14) & 0xfffffe07) &
       0xfffff1ff ^ param_4 << 9;
  return;
}



/* 409c560c FUN_409c560c */

/* Boundary evidence: original MIPS .pdata 409c560c..409c56bf. Semantic name remains unreviewed. */

void FUN_409c560c(int param_1,uint param_2,uint param_3,uint param_4)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  
  iVar3 = *(int *)(param_1 + 0x504);
  *(uint *)(iVar3 + 0x88) = param_4;
  *(char *)(iVar3 + 0x56) = (char)param_2;
  *(char *)(iVar3 + 0x57) = (char)param_3;
  *(char *)(iVar3 + 0x58) = (char)param_4;
  iVar1 = FUN_409c4df8(param_1);
  if (iVar1 == 0) {
    param_2 = 7;
  }
  uVar2 = (*(uint *)(iVar3 + 0x18) & 0xfffffff8 ^ param_2) & 0xff00ffff ^
          (param_3 & param_4) << 0x10;
  *(uint *)(iVar3 + 0x18) = uVar2;
  *(uint *)(iVar3 + 0x18) = uVar2 & 0xffffff ^ (uint)*(byte *)(iVar3 + 0x51) << 0x18;
  return;
}



/* 409c56c0 FUN_409c56c0 */

/* Boundary evidence: original MIPS .pdata 409c56c0..409c5773. Semantic name remains unreviewed. */

void FUN_409c56c0(int param_1,uint param_2,uint param_3,uint param_4)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  
  iVar3 = *(int *)(param_1 + 0x504);
  *(uint *)(iVar3 + 0x84) = param_4;
  *(char *)(iVar3 + 0x4f) = (char)param_2;
  *(char *)(iVar3 + 0x50) = (char)param_3;
  *(char *)(iVar3 + 0x51) = (char)param_4;
  iVar1 = FUN_409c4df8(param_1);
  if (iVar1 == 0) {
    param_2 = 7;
  }
  uVar2 = (*(uint *)(iVar3 + 0x14) & 0xfffffff8 ^ param_2) & 0xff00ffff ^
          (param_3 & param_4) << 0x10;
  *(uint *)(iVar3 + 0x14) = uVar2;
  *(uint *)(iVar3 + 0x14) = uVar2 & 0xffffff ^ (uint)*(byte *)(iVar3 + 0x51) << 0x18;
  return;
}



/* 409c5774 FUN_409c5774 */

/* Boundary evidence: original MIPS .pdata 409c5774..409c57cf. Semantic name remains unreviewed. */

void FUN_409c5774(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0x504);
  *(char *)(iVar2 + 0x4d) = (char)param_2;
  iVar1 = FUN_409c4f10(param_1);
  if (iVar1 == 0) {
    param_2 = 7;
  }
  *(uint *)(iVar2 + 0xc) = param_2 << 1 ^ *(uint *)(iVar2 + 0xc) & 0xfffffff1;
  return;
}



/* 409c57d0 FUN_409c57d0 */

/* Boundary evidence: original MIPS .pdata 409c57d0..409c581f. Semantic name remains unreviewed. */

void FUN_409c57d0(int param_1,uint param_2)

{
  uint uVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0x504);
  *(char *)(iVar2 + 0x4e) = (char)param_2;
  uVar1 = FUN_409c4f10(param_1);
  *(uint *)(iVar2 + 0xc) = *(uint *)(iVar2 + 0xc) & 0xfffffffe ^ uVar1 & param_2;
  return;
}



/* 409c5820 FUN_409c5820 */

/* Boundary evidence: original MIPS .pdata 409c5820..409c59f3. Semantic name remains unreviewed. */

void FUN_409c5820(int param_1,uint param_2,int param_3,uint param_4,byte param_5)

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
  FUN_409c5028(param_1,(uint)*(byte *)(iVar3 + 0x46),(uint)*(byte *)(iVar3 + 0x47));
  if (*(int *)(param_1 + 0x484) == 0) {
    iVar1 = *(int *)(param_1 + 0x4a0);
  }
  else {
    iVar1 = FUN_409bc7c4(*(int *)(param_1 + 0x484),0xd55);
  }
  if (iVar1 != 0) goto LAB_409c5970;
  if (param_2 == 4) {
LAB_409c58ec:
    param_2 = 3;
  }
  else if (param_2 == 0x11) {
    param_2 = 0xb;
  }
  else if (param_2 == 0x19) goto LAB_409c58ec;
  if (param_3 == 4) {
LAB_409c590c:
    param_3 = 3;
  }
  else if (param_3 == 0x11) {
    param_3 = 0xb;
  }
  else if (param_3 == 0x19) goto LAB_409c590c;
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
LAB_409c5970:
  if (param_4 == 4) {
    param_4 = 0xb;
  }
  *(uint *)(iVar3 + 8) =
       ((param_2 & 0xffffc01f ^ param_3 << 5) << 6 ^ *(uint *)(iVar3 + 8) & 0xfff0003f) & 0xff0fffff
       ^ ((uVar2 & 0xf) << 4 ^ param_4 & 0xf) << 0x10;
  return;
}



/* 409c59f4 FUN_409c59f4 */

/* Boundary evidence: original MIPS .pdata 409c59f4..409c5a77. Semantic name remains unreviewed. */

int FUN_409c59f4(undefined4 *param_1)

{
  int iVar1;
  
  if (((param_1[0x144] != 0) || (iVar1 = FUN_409c508c(param_1), iVar1 == 0)) &&
     (iVar1 = mali_frame_builder_write_lock(param_1[0x13d]), iVar1 == 0)) {
    iVar1 = FUN_409c1638((undefined4 *)param_1[0x144]);
    if (iVar1 == 0) {
      iVar1 = 0;
    }
    else {
      mali_frame_builder_write_unlock(param_1[0x13d]);
    }
  }
  return iVar1;
}



/* 409c5a78 FUN_409c5a78 */

/* Boundary evidence: original MIPS .pdata 409c5a78..409c5ab7. Semantic name remains unreviewed. */

void FUN_409c5a78(undefined4 *param_1)

{
  int iVar1;
  
  mali_frame_builder_reset(param_1[0x13d]);
  iVar1 = FUN_409c508c(param_1);
  if (iVar1 == 0) {
    FUN_409c1638((undefined4 *)param_1[0x144]);
  }
  return;
}



/* 409c5ab8 FUN_409c5ab8 */

/* Boundary evidence: original MIPS .pdata 409c5ab8..409c5b43. Semantic name remains unreviewed. */

void FUN_409c5ab8(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x504);
  *(uint *)(iVar1 + 0x40) = *(uint *)(iVar1 + 0x40) & 0xffffffdf | param_2 << 5;
  FUN_409c5260(param_1);
  FUN_409c52e4(param_1,*(undefined4 *)(iVar1 + 0x60),(uint)*(byte *)(iVar1 + 100));
  FUN_409c5160(param_1,*(uint *)(iVar1 + 0x40) >> 0xb & 1);
  FUN_409c51e0(param_1,*(uint *)(iVar1 + 0x40) >> 10 & 1);
  return;
}



/* 409c5b44 FUN_409c5b44 */

/* Boundary evidence: original MIPS .pdata 409c5b44..409c5bfb. Semantic name remains unreviewed. */

void FUN_409c5b44(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x504);
  *(uint *)(iVar1 + 0x40) = *(uint *)(iVar1 + 0x40) & 0xffffffef | param_2 << 4;
  FUN_409c56c0(param_1,(uint)*(byte *)(iVar1 + 0x4f),(uint)*(byte *)(iVar1 + 0x50),
               (uint)*(byte *)(iVar1 + 0x51));
  FUN_409c5464(param_1,(uint)*(byte *)(iVar1 + 0x52));
  FUN_409c5564(param_1,(uint)*(byte *)(iVar1 + 0x53),(uint)*(byte *)(iVar1 + 0x54),
               (uint)*(byte *)(iVar1 + 0x55));
  FUN_409c560c(param_1,(uint)*(byte *)(iVar1 + 0x56),(uint)*(byte *)(iVar1 + 0x57),
               (uint)*(byte *)(iVar1 + 0x58));
  FUN_409c5408(param_1,(uint)*(byte *)(iVar1 + 0x59));
  FUN_409c54bc(param_1,(uint)*(byte *)(iVar1 + 0x5a),(uint)*(byte *)(iVar1 + 0x5b),
               (uint)*(byte *)(iVar1 + 0x5c));
  return;
}



/* 409c5bfc FUN_409c5bfc */

/* Boundary evidence: original MIPS .pdata 409c5bfc..409c5c5b. Semantic name remains unreviewed. */

void FUN_409c5bfc(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x504);
  *(uint *)(iVar1 + 0x40) = *(uint *)(iVar1 + 0x40) & 0xfffffffd | param_2 << 1;
  FUN_409c5774(param_1,(uint)*(byte *)(iVar1 + 0x4d));
  FUN_409c57d0(param_1,(uint)*(byte *)(iVar1 + 0x4e));
  return;
}



/* 409c5c5c FUN_409c5c5c */

/* Boundary evidence: original MIPS .pdata 409c5c5c..409c5ca7. Semantic name remains unreviewed. */

void FUN_409c5c5c(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x504);
  *(uint *)(iVar1 + 0x40) = *(uint *)(iVar1 + 0x40) & 0xfffffffb | param_2 << 2;
  FUN_409c5820(param_1,(uint)*(byte *)(iVar1 + 0x48),(uint)*(byte *)(iVar1 + 0x49),
               (uint)*(byte *)(iVar1 + 0x4a),*(byte *)(iVar1 + 0x4b));
  return;
}



/* 409c5ca8 FUN_409c5ca8 */

/* Boundary evidence: original MIPS .pdata 409c5ca8..409c5cff. Semantic name remains unreviewed. */

void FUN_409c5ca8(int param_1,int param_2)

{
  undefined4 *puVar1;
  
  if ((param_1 != 0) && (FUN_409c6468(param_1,param_2,0x8893,0), *(int *)(param_2 + 0x300) != 0)) {
    puVar1 = *(undefined4 **)(param_2 + 0x308);
    *(undefined4 *)(param_2 + 0x308) = 0;
    *(undefined4 *)(param_2 + 0x300) = 0;
    if (puVar1 != (undefined4 *)0x0) {
      FUN_409c5ec4(puVar1);
    }
  }
  return;
}



/* 409c5d00 FUN_409c5d00 */

/* Boundary evidence: original MIPS .pdata 409c5d00..409c5daf. Semantic name remains unreviewed. */

void FUN_409c5d00(int param_1)

{
  int iVar1;
  
  FUN_409c5bfc(param_1,*(uint *)(*(int *)(param_1 + 0x504) + 0x40) >> 1 & 1);
  FUN_409c5b44(param_1,*(uint *)(*(int *)(param_1 + 0x504) + 0x40) >> 4 & 1);
  iVar1 = *(int *)(param_1 + 0x504);
  *(uint *)(iVar1 + 0x40) =
       *(uint *)(iVar1 + 0x40) & 0xfffffffb | (*(uint *)(iVar1 + 0x40) >> 2 & 1) << 2;
  FUN_409c5820(param_1,(uint)*(byte *)(iVar1 + 0x48),(uint)*(byte *)(iVar1 + 0x49),
               (uint)*(byte *)(iVar1 + 0x4a),*(byte *)(iVar1 + 0x4b));
  FUN_409c5ab8(param_1,*(uint *)(*(int *)(param_1 + 0x504) + 0x40) >> 5 & 1);
  return;
}



/* 409c5db0 FUN_409c5db0 */

/* Boundary evidence: original MIPS .pdata 409c5db0..409c5de3. Semantic name remains unreviewed. */

void FUN_409c5db0(undefined4 *param_1,undefined4 param_2)

{
  param_1[0x13d] = param_2;
  FUN_409c5d00((int)param_1);
  FUN_409c508c(param_1);
  return;
}



/* 409c5de4 gles_set_draw_frame_builder */

/* Boundary evidence: original MIPS .pdata 409c5de4..409c5ec3. Semantic name remains unreviewed.
   gles_set_draw_frame_builder */

int gles_set_draw_frame_builder
              (undefined4 *param_1,undefined4 param_2,int param_3,undefined4 param_4,
              undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
              undefined4 param_9,undefined4 param_10,undefined4 param_11)

{
  int iVar1;
  
                    /* 0x15de4  11  _gles_set_draw_frame_builder */
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
    FUN_409c5d00((int)param_1);
  }
  iVar1 = FUN_409c508c(param_1);
  if (iVar1 == 0) {
    mali_frame_builder_set_subpixel_bits(param_2,5);
    iVar1 = 0;
  }
  else {
    param_1[4] = 0x505;
  }
  return iVar1;
}



/* 409c5ec4 FUN_409c5ec4 */

/* Boundary evidence: original MIPS .pdata 409c5ec4..409c5f27. Semantic name remains unreviewed. */

void FUN_409c5ec4(undefined4 *param_1)

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



/* 409c5f28 FUN_409c5f28 */

/* Boundary evidence: original MIPS .pdata 409c5f28..409c5f63. Semantic name remains unreviewed. */

void FUN_409c5f28(undefined4 *param_1)

{
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0x88e4;
  param_1[3] = 0x88b9;
  param_1[4] = 0;
  mali_sys_atomic_initialize(param_1 + 5,1);
  return;
}



/* 409c5f74 FUN_409c5f74 */

/* Boundary evidence: original MIPS .pdata 409c5f74..409c5faf. Semantic name remains unreviewed. */

undefined4 FUN_409c5f74(int param_1,uint param_2)

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



/* 409c5fb0 FUN_409c5fb0 */

/* Boundary evidence: original MIPS .pdata 409c5fb0..409c608f. Semantic name remains unreviewed. */

undefined4
FUN_409c5fb0(undefined4 param_1,int param_2,int param_3,int param_4,int param_5,int param_6)

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
      piVar1 = FUN_409b5dcc(param_1,(int *)*puVar4,puVar4[1],param_3,param_4,param_5,param_6);
      if (piVar1 == (int *)0x0) {
        return 0x505;
      }
      *puVar4 = piVar1;
    }
    uVar2 = 0;
  }
  return uVar2;
}



/* 409c6090 FUN_409c6090 */

/* Boundary evidence: original MIPS .pdata 409c6090..409c61af. Semantic name remains unreviewed. */

void FUN_409c6090(undefined4 param_1,int param_2,int param_3,int param_4)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  undefined4 *puVar4;
  int in_stack_00000038;
  int in_stack_0000003c;
  int in_stack_00000040;
  
  FUN_409da688();
  if ((-1 < in_stack_00000038) && ((param_4 == 0x8892 || (param_4 == 0x8893)))) {
    if (in_stack_00000040 == 0x88e0) {
      if (param_3 != 2) goto LAB_409c60f0;
    }
    else if ((in_stack_00000040 != 0x88e4) && (in_stack_00000040 != 0x88e8)) goto LAB_409c60f0;
    if (param_4 == 0x8892) {
      piVar3 = *(int **)(param_2 + 0x308);
      iVar2 = *(int *)(param_2 + 0x300);
    }
    else {
      if (param_4 != 0x8893) goto LAB_409c60f0;
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
        iVar2 = FUN_409b5d24(param_1,in_stack_00000038,in_stack_0000003c,piVar1);
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
LAB_409c60f0:
                    /* WARNING: Subroutine does not return */
  FUN_409da6b0(0x10);
}



/* 409c61b0 FUN_409c61b0 */

/* Boundary evidence: original MIPS .pdata 409c61b0..409c61f7. Semantic name remains unreviewed. */

void FUN_409c61b0(int param_1)

{
  if (param_1 != 0) {
    if (*(undefined4 **)(param_1 + 4) != (undefined4 *)0x0) {
      FUN_409c5ec4(*(undefined4 **)(param_1 + 4));
      *(undefined4 *)(param_1 + 4) = 0;
    }
    mali_sys_free(param_1);
  }
  return;
}



/* 409c61f8 FUN_409c61f8 */

/* Boundary evidence: original MIPS .pdata 409c61f8..409c62fb. Semantic name remains unreviewed. */

undefined4 FUN_409c61f8(int param_1,int param_2,int param_3,uint *param_4)

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
              FUN_409c0fec(param_2,uVar1);
              FUN_409c5ec4(*(undefined4 **)(iVar2 + 4));
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



/* 409c62fc FUN_409c62fc */

/* Boundary evidence: original MIPS .pdata 409c62fc..409c635f. Semantic name remains unreviewed. */

undefined4 * FUN_409c62fc(void)

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



/* 409c6360 FUN_409c6360 */

/* Boundary evidence: original MIPS .pdata 409c6360..409c6467. Semantic name remains unreviewed. */

undefined4 * FUN_409c6360(int param_1,uint param_2)

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
    puVar2 = FUN_409c62fc();
    if (puVar2 != (undefined4 *)0x0) {
      if (iVar3 != 0) {
        *(undefined4 **)(iVar3 + 4) = puVar2;
        return puVar2;
      }
      puVar1 = (undefined4 *)mali_sys_malloc(8);
      if (puVar1 == (undefined4 *)0x0) {
        FUN_409c5ec4(puVar2);
      }
      else {
        *puVar1 = 4;
        puVar1[1] = 0;
        puVar1[1] = puVar2;
        iVar3 = __mali_named_list_insert(param_1,param_2,puVar1);
        if (iVar3 == 0) {
          return puVar2;
        }
        FUN_409c5ec4(puVar2);
        puVar1[1] = 0;
        mali_sys_free(puVar1);
      }
    }
    puVar2 = (undefined4 *)0x0;
  }
  return puVar2;
}



/* 409c6468 FUN_409c6468 */

/* Boundary evidence: original MIPS .pdata 409c6468..409c64fb. Semantic name remains unreviewed. */

void FUN_409c6468(int param_1,int param_2,int param_3,uint param_4)

{
  undefined4 *puVar1;
  uint uVar2;
  
  FUN_409da7c8();
  if (param_3 == 0x8892) {
    uVar2 = *(uint *)(param_2 + 0x300);
  }
  else {
    if (param_3 != 0x8893) goto LAB_409c64f4;
    uVar2 = *(uint *)(param_2 + 0x304);
  }
  if (uVar2 != param_4) {
    if (param_4 == 0) {
      puVar1 = (undefined4 *)0x0;
      param_4 = 0;
    }
    else {
      puVar1 = FUN_409c6360(param_1,param_4);
      if (puVar1 == (undefined4 *)0x0) goto LAB_409c64f4;
    }
    FUN_409c0f7c(param_2,param_3,param_4,(int)puVar1);
  }
LAB_409c64f4:
                    /* WARNING: Subroutine does not return */
  FUN_409da7e8(0x18);
}



/* 409c64fc FUN_409c64fc */

undefined4 FUN_409c64fc(int param_1)

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



/* 409c65b4 FUN_409c65b4 */

int FUN_409c65b4(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  if (((param_2 == 0x8363) || (param_2 == 0x8033)) || (param_2 == 0x8034)) {
    return 2;
  }
  if ((param_2 == 0x1401) && (iVar2 = 1, param_1 != 0x1906)) {
    if (param_1 == 0x1907) {
      iVar1 = 3;
      goto LAB_409c6668;
    }
    if (param_1 != 0x1908) {
      if (param_1 != 0x1909) {
        if (param_1 != 0x190a) {
          return 1;
        }
        iVar1 = 2;
        goto LAB_409c6668;
      }
      goto LAB_409c6638;
    }
  }
  else {
LAB_409c6638:
    iVar2 = 1;
    iVar1 = 1;
    if (param_2 != 0x1403) goto LAB_409c6668;
    iVar1 = 2;
    iVar2 = 2;
    if (param_1 != 0x1908) {
      if (param_1 != 0x190a) {
        return 1;
      }
      goto LAB_409c6668;
    }
  }
  iVar1 = 4;
LAB_409c6668:
  return iVar2 * iVar1;
}



/* 409c667c FUN_409c667c */

undefined4 FUN_409c667c(uint param_1,uint param_2,int param_3)

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
      goto LAB_409c6794;
    }
  }
  iVar1 = 0x1401;
LAB_409c6794:
  if (param_3 == iVar1) {
    return 0;
  }
  return 0x502;
}



/* 409c67c0 FUN_409c67c0 */

/* Boundary evidence: original MIPS .pdata 409c67c0..409c682b. Semantic name remains unreviewed. */

int FUN_409c67c0(int param_1,int param_2)

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



/* 409c682c FUN_409c682c */

undefined4 FUN_409c682c(int param_1)

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



/* 409c68b4 FUN_409c68b4 */

/* Boundary evidence: original MIPS .pdata 409c68b4..409c690b. Semantic name remains unreviewed. */

void FUN_409c68b4(int param_1,int param_2)

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



/* 409c690c FUN_409c690c */

/* Boundary evidence: original MIPS .pdata 409c690c..409c69ab. Semantic name remains unreviewed. */

void FUN_409c690c(undefined4 *param_1)

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



/* 409c69ac FUN_409c69ac */

undefined4 FUN_409c69ac(int *param_1)

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
LAB_409c6a8c:
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
      goto LAB_409c6a8c;
      if (((iVar6 == 1) && (iVar5 == 1)) && (iVar4 == 1)) {
        return 1;
      }
      uVar7 = uVar7 + 1;
      param_1 = param_1 + 1;
    } while ((int)uVar7 < 0xd);
  }
  return uVar1;
}



/* 409c6a98 FUN_409c6a98 */

/* Boundary evidence: original MIPS .pdata 409c6a98..409c6b23. Semantic name remains unreviewed. */

int FUN_409c6a98(int param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  
  if (param_4 == 0x1401) {
    iVar1 = FUN_409c3314(param_3,0x1401);
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
    iVar1 = FUN_409c3314(param_3,param_4);
    iVar1 = iVar1 * param_2;
  }
  return iVar1;
}



/* 409c6ba8 FUN_409c6ba8 */

void FUN_409c6ba8(int *param_1)

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



/* 409c6c38 FUN_409c6c38 */

/* Boundary evidence: original MIPS .pdata 409c6c38..409c6c53. Semantic name remains unreviewed. */

void FUN_409c6c38(int param_1)

{
  mali_sys_atomic_inc(param_1 + 0x188);
  return;
}



/* 409c6c90 FUN_409c6c90 */

/* Boundary evidence: original MIPS .pdata 409c6c90..409c6cc7. Semantic name remains unreviewed. */

int FUN_409c6c90(int *param_1,int param_2)

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



/* 409c6cc8 FUN_409c6cc8 */

/* Boundary evidence: original MIPS .pdata 409c6cc8..409c6d03. Semantic name remains unreviewed. */

undefined4 FUN_409c6cc8(int param_1,uint param_2)

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



/* 409c6d04 FUN_409c6d04 */

uint FUN_409c6d04(uint param_1)

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



/* 409c6dd8 FUN_409c6dd8 */

/* Boundary evidence: original MIPS .pdata 409c6dd8..409c6f97. Semantic name remains unreviewed. */

void FUN_409c6dd8(int *param_1)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  uint *puVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  int *piVar8;
  
  FUN_409da688();
  iVar6 = 1;
  iVar7 = 1;
  if (param_1[0xf] == 0) goto LAB_409c6ec8;
  param_1[0xf] = 0;
  if ((param_1[3] == 0x2600) || (param_1[3] == 0x2601)) {
    if (*param_1 == 0) {
      if (((int *)param_1[7] == (int *)0x0) ||
         (puVar4 = *(uint **)param_1[7], puVar4 == (uint *)0x0)) goto LAB_409c6ea4;
      uVar5 = *puVar4;
      if ((((uVar5 != 0) && ((uVar5 - 1 & uVar5) != 0)) ||
          ((uVar5 = puVar4[1], uVar5 != 0 && ((uVar5 - 1 & uVar5) != 0)))) &&
         ((param_1[1] != 0x812f || (param_1[2] != 0x812f)))) {
LAB_409c6e98:
        param_1[0x10] = 0;
        goto LAB_409c6ec8;
      }
    }
    else {
      if (*param_1 != 1) goto LAB_409c6ed4;
      iVar6 = FUN_409c64fc((int)param_1);
    }
  }
  else {
LAB_409c6ed4:
    if (param_1[0x12] == 1) {
      iVar6 = param_1[0x13];
    }
    else {
      if (*param_1 != 0) {
        if (*param_1 == 1) {
          iVar7 = 6;
          iVar1 = FUN_409c64fc((int)param_1);
          if (iVar1 != 0) goto LAB_409c6f10;
        }
LAB_409c6ea4:
        param_1[0x10] = 0;
        goto LAB_409c6ec8;
      }
LAB_409c6f10:
      iVar1 = 0;
      if (iVar7 != 0) {
        piVar8 = param_1 + 7;
        do {
          piVar3 = (int *)*piVar8;
          if ((piVar3 == (int *)0x0) || (puVar4 = (uint *)*piVar3, puVar4 == (uint *)0x0))
          goto LAB_409c6e98;
          uVar5 = *puVar4;
          if ((((uVar5 != 0) && ((uVar5 - 1 & uVar5) != 0)) ||
              ((uVar5 = puVar4[1], uVar5 != 0 && ((uVar5 - 1 & uVar5) != 0)))) ||
             (iVar2 = FUN_409c69ac(piVar3), iVar2 == 0)) goto LAB_409c6ea4;
          iVar1 = iVar1 + 1;
          piVar8 = piVar8 + 1;
        } while (iVar1 < iVar7);
      }
    }
  }
  param_1[0x10] = iVar6;
LAB_409c6ec8:
                    /* WARNING: Subroutine does not return */
  FUN_409da6b0(0x10);
}



/* 409c6f98 FUN_409c6f98 */

/* Boundary evidence: original MIPS .pdata 409c6f98..409c6fdf. Semantic name remains unreviewed. */

undefined4 FUN_409c6f98(int param_1,int param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = FUN_409ba9a4(param_1,param_2,param_3);
  if ((iVar1 == 0) && (uVar2 = mali_sys_atomic_get(param_1 + 0x188), uVar2 < 2)) {
    return 0;
  }
  return 1;
}



/* 409c6fe0 FUN_409c6fe0 */

/* Boundary evidence: original MIPS .pdata 409c6fe0..409c7033. Semantic name remains unreviewed. */

void FUN_409c6fe0(int param_1,int param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  
  FUN_409da7c8();
  iVar1 = FUN_409c682c(param_2);
  iVar1 = FUN_409c67c0(param_1,iVar1);
  if (iVar1 != 0) {
    *(undefined4 *)(param_3 * 4 + iVar1) = param_4;
  }
                    /* WARNING: Subroutine does not return */
  FUN_409da7e8(0x10);
}



/* 409c7034 FUN_409c7034 */

/* Boundary evidence: original MIPS .pdata 409c7034..409c708f. Semantic name remains unreviewed. */

undefined4 FUN_409c7034(int param_1,int param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_409c682c(param_2);
  iVar1 = FUN_409c67c0(param_1,iVar1);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = *(undefined4 *)(param_3 * 4 + iVar1);
  }
  return uVar2;
}



/* 409c7090 FUN_409c7090 */

/* Boundary evidence: original MIPS .pdata 409c7090..409c71fb. Semantic name remains unreviewed. */

void FUN_409c7090(int param_1)

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
      uVar1 = FUN_409c6d04(((uVar1 >> 0x10 | uVar1) >> 1) + 1);
      *(uint *)(iVar3 + 0x13c) = uVar1 << 0x18 | *(uint *)(iVar3 + 0x13c) & 0xf00fffff;
    }
  }
  return;
}



/* 409c71fc gles_setup_egl_image_from_texture */

/* Boundary evidence: original MIPS .pdata 409c71fc..409c74e7. Semantic name remains unreviewed.
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
  
                    /* 0x171fc  14  _gles_setup_egl_image_from_texture */
  FUN_409da758();
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
       (iVar2 = FUN_409baa84(piVar5[0xd],iVar6,param_4), iVar2 == 0)) {
      if (iVar6 == 0xde1) {
        iVar6 = FUN_409c682c(0xde1);
        if ((piVar5[iVar6 + 7] != 0) && (*(int *)(param_4 * 4 + piVar5[iVar6 + 7]) != 0)) {
          bVar1 = true;
        }
        if (*piVar5 != 0) goto LAB_409c7390;
      }
      else {
        if ((iVar6 != 0x8515) && (5 < iVar6 - 0x8515U)) goto LAB_409c7390;
        iVar6 = FUN_409c682c(iVar6);
        if ((piVar5[iVar6 + 7] != 0) && (*(int *)(param_4 * 4 + piVar5[iVar6 + 7]) != 0)) {
          bVar1 = true;
        }
        if (*piVar5 != 1) goto LAB_409c7390;
      }
      iVar2 = FUN_409c6dd8(piVar5);
      if (((iVar2 == 1) && (bVar1)) && (param_4 < 10)) {
        iVar6 = FUN_409ba828(piVar5[0xd],iVar6,param_4,in_stack_00000058);
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
LAB_409c7390:
                    /* WARNING: Subroutine does not return */
  FUN_409da790(0x20);
}



/* 409c74e8 FUN_409c74e8 */

/* Boundary evidence: original MIPS .pdata 409c74e8..409c7553. Semantic name remains unreviewed. */

undefined4 FUN_409c74e8(int param_1,undefined4 param_2,int param_3,int param_4)

{
  int iVar1;
  int in_stack_00000020;
  
  iVar1 = FUN_409c7034(param_1,param_3,0);
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



/* 409c7554 FUN_409c7554 */

/* Boundary evidence: original MIPS .pdata 409c7554..409c75f3. Semantic name remains unreviewed. */

int FUN_409c7554(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  
  iVar1 = FUN_409c7034(param_1,param_2,param_3);
  if (iVar1 == 0) {
    iVar1 = mali_sys_malloc(0x18);
    if (iVar1 != 0) {
      *(undefined4 *)(iVar1 + 0x14) = 0;
      iVar2 = FUN_409c6fe0(param_1,param_2,param_3,iVar1);
      if (iVar2 == 0) {
        return iVar1;
      }
      mali_sys_free(iVar1);
    }
    iVar1 = 0;
  }
  return iVar1;
}



/* 409c75f4 FUN_409c75f4 */

/* Boundary evidence: original MIPS .pdata 409c75f4..409c764b. Semantic name remains unreviewed. */

undefined4 * FUN_409c75f4(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  puVar1 = (undefined4 *)mali_sys_malloc(400);
  if (puVar1 != (undefined4 *)0x0) {
    FUN_409c690c(puVar1);
    puVar2 = FUN_409bb460();
    puVar1[0xd] = puVar2;
    if (puVar2 != (undefined4 *)0x0) {
      return puVar1;
    }
    mali_sys_free(puVar1);
  }
  return (undefined4 *)0x0;
}



/* 409c764c FUN_409c764c */

/* Boundary evidence: original MIPS .pdata 409c764c..409c7a7b. Semantic name remains unreviewed. */

void FUN_409c764c(int param_1,int param_2)

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
      FUN_409c7090(param_1);
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



/* 409c7a7c FUN_409c7a7c */

/* Boundary evidence: original MIPS .pdata 409c7a7c..409c7b3b. Semantic name remains unreviewed. */

void FUN_409c7a7c(int *param_1,undefined4 *param_2,int param_3,int param_4)

{
  int iVar1;
  uint uVar2;
  
  FUN_409da688();
  iVar1 = FUN_409baa24((int)param_1,param_3,param_4);
  if ((iVar1 == 0) && (iVar1 = FUN_409baa84((int)param_1,param_3,param_4), iVar1 == 0)) {
    uVar2 = mali_sys_atomic_get(param_1 + 0x62);
    if (1 < uVar2) {
      iVar1 = FUN_409ba3b0(param_1);
      iVar1 = mali_cmu_is_cow_space_available(iVar1);
      if ((iVar1 == 0) && (iVar1 = FUN_409da508(param_2,param_2[0x13d]), iVar1 == 0)) {
        mali_sys_atomic_get(param_1 + 0x62);
      }
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_409da6b0(0x10);
}



/* 409c7b3c FUN_409c7b3c */

/* Boundary evidence: original MIPS .pdata 409c7b3c..409c7b5f. Semantic name remains unreviewed. */

void FUN_409c7b3c(undefined4 *param_1,undefined4 param_2)

{
  FUN_409bbe1c(param_2,param_1);
  return;
}



/* 409c7b60 FUN_409c7b60 */

/* Boundary evidence: original MIPS .pdata 409c7b60..409c7c03. Semantic name remains unreviewed. */

void FUN_409c7b60(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  
  FUN_409da688();
  if (param_1 != 0) {
    puVar2 = *(undefined4 **)(param_1 + 0x34);
    if ((puVar2 != (undefined4 *)0x0) &&
       (iVar1 = mali_sys_atomic_dec_and_return(puVar2 + 0x62), iVar1 == 0)) {
      FUN_409bbdd8(puVar2);
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
            FUN_409c68b4(iVar5,*piVar3);
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
  FUN_409da6b0(0x10);
}



/* 409c7c04 FUN_409c7c04 */

/* Boundary evidence: original MIPS .pdata 409c7c04..409c7ea3. Semantic name remains unreviewed. */

void FUN_409c7c04(int param_1,undefined4 *param_2,int param_3,undefined4 param_4)

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
  
  FUN_409da758();
  iVar1 = (*(code *)param_2[0x143])(param_4);
  if (((iVar1 != 0) && (*(int *)(iVar1 + 0x20) != 0)) &&
     (iVar7 = *(int *)(*(int *)(iVar1 + 0x20) + 0x10), iVar7 != 0)) {
    iVar6 = *(int *)(iVar7 + 0x18);
    iVar2 = FUN_409ba304(iVar6);
    if ((iVar2 == 1) && ((iVar6 != 0xe || (*(int *)(iVar7 + 0x28) != 1)))) {
      *(undefined4 *)(param_1 + 0x3c) = 1;
      iVar2 = FUN_409c7a7c(*(int **)(param_1 + 0x34),param_2,param_3,0);
      if (iVar2 == 0) {
        piVar3 = *(int **)(param_1 + 0x34);
        mali_sys_atomic_inc(piVar3 + 0x62);
      }
      else {
        piVar3 = FUN_409bbe1c(*param_2,*(undefined4 **)(param_1 + 0x34));
        if (piVar3 == (int *)0x0) goto LAB_409c7e98;
      }
      puVar4 = (uint *)mali_sys_malloc(0x18);
      if (puVar4 == (uint *)0x0) {
        iVar1 = mali_sys_atomic_dec_and_return(piVar3 + 0x62);
        if (iVar1 == 0) {
          FUN_409bbdd8(piVar3);
        }
      }
      else {
        *puVar4 = (uint)*(ushort *)(iVar7 + 0xc);
        puVar4[1] = (uint)*(ushort *)(iVar7 + 0xe);
        puVar4[2] = 1;
        puVar4[5] = 0;
        FUN_409bbf60(*(undefined4 *)(iVar7 + 0x18),puVar4 + 4,puVar4 + 3);
        iVar2 = FUN_409c682c(param_3);
        iVar6 = 0;
        do {
          FUN_409bb40c((int)piVar3,iVar2,iVar6);
          iVar5 = *(int *)((iVar2 + 7) * 4 + param_1);
          if (iVar5 != 0) {
            FUN_409c68b4(iVar6,iVar5);
          }
          iVar6 = iVar6 + 1;
        } while (iVar6 < 0xd);
        puVar8 = (undefined4 *)((iVar2 + 7) * 4 + param_1);
        puVar9 = (undefined4 *)*puVar8;
        iVar2 = FUN_409c6fe0(param_1,param_3,0,puVar4);
        if (iVar2 == 0) {
          iVar1 = FUN_409bb518((int)piVar3,param_3,0,iVar7,*(int *)(iVar1 + 0x10));
          if (iVar1 == 0) {
            puVar8 = *(undefined4 **)(param_1 + 0x34);
            iVar1 = mali_sys_atomic_dec_and_return(puVar8 + 0x62);
            if (iVar1 == 0) {
              FUN_409bbdd8(puVar8);
            }
            *(int **)(param_1 + 0x34) = piVar3;
            FUN_409c764c(param_1,0);
            *(undefined4 *)(param_1 + 0x38) = 1;
            *(undefined4 *)(param_1 + 0x48) = 0;
            *(int *)((*(int *)(param_1 + 0x54) + 0x16) * 4 + param_1) = iVar7;
            *(int *)(param_1 + 0x54) = *(int *)(param_1 + 0x54) + 1;
          }
          else {
            iVar1 = mali_sys_atomic_dec_and_return(piVar3 + 0x62);
            if (iVar1 == 0) {
              FUN_409bbdd8(piVar3);
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
            FUN_409bbdd8(piVar3);
          }
          mali_sys_free(puVar4);
        }
      }
    }
  }
LAB_409c7e98:
                    /* WARNING: Subroutine does not return */
  FUN_409da790(0x18);
}



/* 409c7ea4 FUN_409c7ea4 */

/* Boundary evidence: original MIPS .pdata 409c7ea4..409c8307. Semantic name remains unreviewed. */

void FUN_409c7ea4(int param_1,undefined4 *param_2,int param_3,uint param_4)

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
  
  FUN_409da758();
  iStack00000028 = param_3;
  puStack00000030 = param_2;
  if ((-1 < in_stack_00000074) && (-1 < in_stack_00000078)) {
    if (in_stack_00000070 == 0x8d64) {
      if ((((int)param_4 < 0) || (0xc < (int)param_4)) ||
         ((0x1000 < in_stack_00000074 ||
          ((0x1000 < in_stack_00000078 || (0x1000 < in_stack_00000074 << (param_4 & 0x1f)))))))
      goto LAB_409c7f3c;
      iVar1 = in_stack_00000078 << (param_4 & 0x1f);
    }
    else if (((0 < (int)param_4) || (0xc < (int)-param_4)) ||
            (iVar1 = in_stack_00000078, 0x1000 < in_stack_00000074)) goto LAB_409c7f3c;
    if (iVar1 < 0x1001) {
      *(undefined4 *)(param_1 + 0x3c) = 1;
      if (*(int **)(param_1 + 0x34) != (int *)0x0) {
        uVar5 = param_4;
        if ((int)param_4 < 0) {
          uVar5 = 0;
        }
        iVar1 = FUN_409c7a7c(*(int **)(param_1 + 0x34),param_2,param_3,uVar5);
        if (iVar1 != 0) {
          piVar2 = FUN_409bbe1c(*param_2,*(undefined4 **)(param_1 + 0x34));
          if (piVar2 == (int *)0x0) goto LAB_409c7f3c;
          puVar8 = *(undefined4 **)(param_1 + 0x34);
          iVar1 = mali_sys_atomic_dec_and_return(puVar8 + 0x62);
          if (iVar1 == 0) {
            FUN_409bbdd8(puVar8);
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
            iVar3 = FUN_409baa84(iVar9,param_3,iVar1);
            if ((iVar3 != 0) && (iVar3 = FUN_409ba944(iVar9,param_3,iVar1), iVar3 != 0)) {
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
          iVar3 = FUN_409c682c(iStack00000028);
          iVar3 = *(int *)((iVar3 + 7) * 4 + param_1);
          if (iVar3 != 0) {
            iVar9 = *(int *)(param_4 * 4 + iVar3);
          }
          piVar2 = (int *)FUN_409c7554(param_1,iVar1,param_4);
          if (piVar2 == (int *)0x0) goto LAB_409c7f3c;
        }
        iVar7 = FUN_409c682c(iStack00000028);
        iVar4 = FUN_409bb664(*puStack00000030,*(int *)(param_1 + 0x34),iVar7,param_4);
        iVar1 = iStack00000028;
        if (iVar4 == 0) {
          if (in_stack_00000070 == 0x8d64) {
            *piVar2 = in_stack_00000074;
            piVar2[1] = in_stack_00000078;
            piVar2[2] = 1;
            piVar2[4] = 0;
            piVar2[3] = 0x8d64;
            *(undefined4 *)(param_1 + 0x38) = 1;
            FUN_409c764c(param_1,param_4);
            iVar1 = iStack00000028;
            uVar5 = param_4;
LAB_409c82d0:
            iVar1 = FUN_409c7034(param_1,iVar1,uVar5);
            if ((iVar1 != 0) && (*(int *)(iVar1 + 0x14) != 0)) {
              FUN_409bed4c();
            }
            FUN_409c764c(param_1,param_4);
          }
          else {
            iVar3 = 0;
            while( true ) {
              uVar6 = 1;
              if (0 < (int)uVar5) {
                uVar6 = uVar5;
              }
              if ((int)uVar6 < iVar3) goto LAB_409c82d0;
              piVar2 = (int *)FUN_409c7554(param_1,iVar1,iVar3);
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
              FUN_409c764c(param_1,iVar3);
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
LAB_409c7f3c:
                    /* WARNING: Subroutine does not return */
  FUN_409da790(0x38);
}



/* 409c8308 FUN_409c8308 */

/* WARNING: Type propagation algorithm not settling */
/* Boundary evidence: original MIPS .pdata 409c8308..409c85bf. Semantic name remains unreviewed. */

int FUN_409c8308(int param_1,undefined4 *param_2,int param_3,int param_4)

{
  bool bVar1;
  int iVar2;
  uint uVar3;
  int *piVar4;
  int iVar5;
  int *piVar6;
  
  piVar6 = *(int **)(param_1 + 0x34);
  bVar1 = false;
  iVar2 = FUN_409bada8((int)piVar6,param_3,param_4);
  if (iVar2 != 0) goto joined_r0x409c8478;
  iVar5 = *(int *)(param_1 + 0x34);
  iVar2 = FUN_409ba9a4(iVar5,param_3,param_4);
  if ((iVar2 == 0) && (uVar3 = mali_sys_atomic_get(iVar5 + 0x188), uVar3 < 2)) {
LAB_409c84a4:
    FUN_409bad54((int)piVar6,param_3,param_4);
    iVar2 = FUN_409c682c(param_3);
    iVar2 = FUN_409baae8(*param_2,*(int *)(param_1 + 0x34),iVar2,param_4);
    if (iVar2 == 0) {
      iVar2 = FUN_409c7034(param_1,param_3,param_4);
      if (*(int *)(iVar2 + 0x14) != 0) {
        FUN_409bed4c();
      }
      FUN_409c764c(param_1,param_4);
      *(undefined4 *)(param_1 + 0x38) = 1;
      if (!bVar1) {
        return 0;
      }
      iVar2 = mali_sys_atomic_dec_and_return(piVar6 + 0x62);
      if (iVar2 != 0) {
        return 0;
      }
      FUN_409bbdd8(piVar6);
      return 0;
    }
    if (!bVar1) goto joined_r0x409c8478;
    iVar5 = mali_sys_atomic_dec_and_return(piVar6 + 0x62);
  }
  else {
    piVar4 = FUN_409bbe1c(*param_2,*(undefined4 **)(param_1 + 0x34));
    if (piVar4 == (int *)0x0) {
      FUN_409bad54((int)piVar6,param_3,param_4);
      return 0x505;
    }
    iVar2 = FUN_409baa84(*(int *)(param_1 + 0x34),param_3,param_4);
    if (iVar2 == 0) {
LAB_409c849c:
      *(int **)(param_1 + 0x34) = piVar4;
      bVar1 = true;
      goto LAB_409c84a4;
    }
    FUN_409bad54((int)piVar6,param_3,param_4);
    iVar2 = FUN_409ba244(*(int **)(param_1 + 0x34),(int)piVar4);
    if (iVar2 != 0) {
      iVar5 = mali_sys_atomic_dec_and_return(piVar4 + 0x62);
      if (iVar5 == 0) {
        FUN_409bbdd8(piVar4);
        return iVar2;
      }
      return iVar2;
    }
    iVar2 = FUN_409bada8((int)piVar6,param_3,param_4);
    if (iVar2 == 0) goto LAB_409c849c;
    iVar5 = mali_sys_atomic_dec_and_return(piVar4 + 0x62);
    piVar6 = piVar4;
  }
  if (iVar5 == 0) {
    FUN_409bbdd8(piVar6);
  }
joined_r0x409c8478:
  if (((iVar2 != -3) && (-3 < iVar2)) && (iVar2 < 0)) {
    return 0x505;
  }
  return 0;
}



/* 409c85c0 FUN_409c85c0 */

/* Boundary evidence: original MIPS .pdata 409c85c0..409c88f3. Semantic name remains unreviewed. */

void FUN_409c85c0(int param_1,undefined4 *param_2,int param_3,int param_4)

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
  
  FUN_409da758();
  *(undefined4 *)(param_1 + 0x3c) = 1;
  puStack0000002c = param_2;
  iVar1 = FUN_409c7a7c(*(int **)(param_1 + 0x34),param_2,param_3,param_4);
  if (iVar1 == 0) {
    piVar2 = *(int **)(param_1 + 0x34);
    mali_sys_atomic_inc(piVar2 + 0x62);
  }
  else {
    piVar2 = FUN_409bbe1c(*param_2,*(undefined4 **)(param_1 + 0x34));
    if (piVar2 == (int *)0x0) goto LAB_409c88ec;
  }
  iVar5 = *(int *)(param_1 + 0x34);
  iVar1 = FUN_409baa84(iVar5,param_3,param_4);
  if ((iVar1 != 0) && (iVar1 = FUN_409ba944(iVar5,param_3,param_4), iVar1 != 0)) {
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
    iVar1 = FUN_409c682c(param_3);
    FUN_409bb40c((int)piVar2,iVar1,param_4);
    puVar6 = (undefined4 *)FUN_409c7034(param_1,param_3,param_4);
    if (puVar6 != (undefined4 *)0x0) {
      *puVar6 = 0;
      puVar6[1] = 0;
    }
  }
  else {
    iVar4 = 0;
    iVar1 = FUN_409c682c(param_3);
    piVar7 = (int *)((iVar1 + 7) * 4 + param_1);
    iVar5 = *piVar7;
    if (iVar5 != 0) {
      iVar4 = *(int *)(param_4 * 4 + iVar5);
    }
    piVar3 = (int *)FUN_409c7554(param_1,param_3,param_4);
    if (piVar3 == (int *)0x0) {
      iVar1 = mali_sys_atomic_dec_and_return(piVar2 + 0x62);
      if (iVar1 == 0) {
        FUN_409bbdd8(piVar2);
      }
      goto LAB_409c88ec;
    }
    iVar1 = FUN_409bbc60(*puStack0000002c,(int)piVar2,iVar1,param_4);
    if (iVar1 != 0) {
      iVar1 = mali_sys_atomic_dec_and_return(piVar2 + 0x62);
      if (iVar1 == 0) {
        FUN_409bbdd8(piVar2);
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
      goto LAB_409c88ec;
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
    FUN_409bbdd8(puVar6);
  }
  *(int **)(param_1 + 0x34) = piVar2;
  FUN_409c764c(param_1,param_4);
  iVar1 = mali_sys_atomic_dec_and_return(piVar2 + 0x62);
  if (iVar1 == 0) {
    FUN_409bbdd8(piVar2);
  }
  *(undefined4 *)(param_1 + 0x48) = 0;
  *(undefined4 *)(param_1 + 0x38) = 1;
  iVar1 = FUN_409c7034(param_1,param_3,param_4);
  if ((iVar1 != 0) && (*(int *)(iVar1 + 0x14) != 0)) {
    FUN_409bed4c();
  }
LAB_409c88ec:
                    /* WARNING: Subroutine does not return */
  FUN_409da790(0x30);
}



/* 409c88f4 FUN_409c88f4 */

/* Boundary evidence: original MIPS .pdata 409c88f4..409c8a17. Semantic name remains unreviewed. */

void FUN_409c88f4(int param_1,uint param_2,int param_3)

{
  int *piVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  
  FUN_409da688();
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
  if ((iVar3 == 0) && (piVar1 = FUN_409c75f4(), piVar1 != (int *)0x0)) {
    *piVar1 = param_3;
    FUN_409c6ba8(piVar1);
    if (iVar4 == 0) {
      puVar2 = (undefined4 *)mali_sys_malloc(8);
      if (puVar2 == (undefined4 *)0x0) {
        FUN_409c7b60((int)piVar1);
      }
      else {
        *puVar2 = 1;
        puVar2[1] = 0;
        puVar2[1] = piVar1;
        iVar4 = __mali_named_list_insert
                          (*(undefined4 *)(*(int *)(param_1 + 0x4e8) + 4),param_2,puVar2);
        if (iVar4 != 0) {
          FUN_409c7b60((int)piVar1);
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
  FUN_409da6b0(0x10);
}



/* 409c8a18 FUN_409c8a18 */

/* Boundary evidence: original MIPS .pdata 409c8a18..409c8a4f. Semantic name remains unreviewed. */

void FUN_409c8a18(int param_1)

{
  int iVar1;
  
  iVar1 = mali_sys_atomic_dec_and_return(param_1 + 0x50);
  if (iVar1 == 0) {
    FUN_409c7b60(param_1);
  }
  return;
}



/* 409c8a50 FUN_409c8a50 */

/* Boundary evidence: original MIPS .pdata 409c8a50..409c8aaf. Semantic name remains unreviewed. */

void FUN_409c8a50(int param_1)

{
  int iVar1;
  int iVar2;
  
  if (param_1 != 0) {
    iVar2 = *(int *)(param_1 + 4);
    if (iVar2 != 0) {
      iVar1 = mali_sys_atomic_dec_and_return(iVar2 + 0x50);
      if (iVar1 == 0) {
        FUN_409c7b60(iVar2);
      }
      *(undefined4 *)(param_1 + 4) = 0;
    }
    mali_sys_free(param_1);
  }
  return;
}



/* 409c8ab0 FUN_409c8ab0 */

/* Boundary evidence: original MIPS .pdata 409c8ab0..409c8d6b. Semantic name remains unreviewed. */

void FUN_409c8ab0(int param_1,undefined4 *param_2,int param_3,int param_4)

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
  
  FUN_409da758();
  iStack00000038 = param_3;
  iStack0000003c = param_1;
  if (((((param_4 < 0) || (0xc < param_4)) || (in_stack_00000078 < 0)) ||
      (((in_stack_0000007c < 0 || (in_stack_00000080 < 0)) ||
       ((in_stack_00000084 < 0 || ((in_stack_00000088 < 0 || (in_stack_0000008c < 0)))))))) ||
     ((0x1000 < in_stack_00000088 ||
      ((((0x1000 < in_stack_0000008c ||
         (piVar1 = (int *)FUN_409c7034(param_1,param_3,param_4), piVar1 == (int *)0x0)) ||
        (*piVar1 < in_stack_00000078 + in_stack_00000088)) ||
       (piVar1[1] < in_stack_0000007c + in_stack_0000008c)))))) goto LAB_409c8d60;
  iVar3 = piVar1[3];
  if (iVar3 == 0x1906) {
LAB_409c8be0:
    if (param_2[0x121] == 0) {
      iVar3 = param_2[0x128];
    }
    else {
      iVar3 = FUN_409bc7c4(param_2[0x121],0xd55);
    }
    if (iVar3 == 0) {
      if (param_2[0x121] != 0) {
        FUN_409bc7c4(param_2[0x121],0xd52);
      }
      if (param_2[0x121] != 0) {
        FUN_409bc7c4(param_2[0x121],0xd53);
      }
      if (param_2[0x121] != 0) {
        FUN_409bc7c4(param_2[0x121],0xd54);
      }
      goto LAB_409c8d60;
    }
  }
  else if (iVar3 != 0x1907) {
    if (iVar3 != 0x1908) {
      if (iVar3 == 0x1909) goto LAB_409c8c88;
      if (iVar3 != 0x190a) goto LAB_409c8d60;
    }
    if (piVar1[4] == 0x1403) goto LAB_409c8d60;
    goto LAB_409c8be0;
  }
LAB_409c8c88:
  if (*(int *)(param_1 + 0x34) != 0) {
    iVar3 = FUN_409c65b4(piVar1[3],piVar1[4]);
    iVar3 = mali_sys_malloc(iVar3 * in_stack_00000088 * in_stack_0000008c);
    if (iVar3 != 0) {
      iVar2 = FUN_409c3ebc(param_2,in_stack_00000080,in_stack_00000084,in_stack_00000088);
      if (iVar2 == 0) {
        FUN_409c8308(iStack0000003c,param_2,iStack00000038,param_4);
      }
      mali_sys_free(iVar3);
    }
  }
LAB_409c8d60:
                    /* WARNING: Subroutine does not return */
  FUN_409da790(0x40);
}



/* 409c8d6c FUN_409c8d6c */

/* Boundary evidence: original MIPS .pdata 409c8d6c..409c901f. Semantic name remains unreviewed. */

void FUN_409c8d6c(int param_1,undefined4 *param_2,int param_3,uint param_4)

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
  
  FUN_409da758();
  if (((((((((int)param_4 < 0) || (0xc < (int)param_4)) || (in_stack_0000006c < 0)) ||
         ((in_stack_00000070 < 0 || ((int)in_stack_00000074 < 0)))) ||
        (((int)in_stack_00000078 < 0 ||
         ((0x1000 < (int)in_stack_00000074 || (0x1000 < (int)in_stack_00000078)))))) ||
       (0x1000 < (int)(in_stack_00000074 << (param_4 & 0x1f)))) ||
      (((0x1000 < (int)(in_stack_00000078 << (param_4 & 0x1f)) ||
        ((in_stack_00000074 != 0 && ((in_stack_00000074 - 1 & in_stack_00000074) != 0)))) ||
       ((in_stack_00000078 != 0 && ((in_stack_00000078 - 1 & in_stack_00000078) != 0)))))) ||
     (in_stack_0000007c != 0)) goto LAB_409c9014;
  if (in_stack_00000068 == 0x1906) {
LAB_409c8e84:
    if (param_2[0x121] == 0) {
      iVar1 = param_2[0x128];
    }
    else {
      iVar1 = FUN_409bc7c4(param_2[0x121],0xd55);
    }
    if (iVar1 == 0) {
      if (param_2[0x121] != 0) {
        FUN_409bd278(param_2[0x121]);
      }
      goto LAB_409c9014;
    }
  }
  else if (in_stack_00000068 != 0x1907) {
    if (in_stack_00000068 != 0x1908) {
      if (in_stack_00000068 == 0x1909) goto LAB_409c8edc;
      if (in_stack_00000068 != 0x190a) goto LAB_409c9014;
    }
    goto LAB_409c8e84;
  }
LAB_409c8edc:
  if (*(int *)(param_1 + 0x34) != 0) {
    iVar1 = FUN_409c65b4(in_stack_00000068,0x1401);
    iVar1 = mali_sys_malloc(iVar1 * in_stack_00000074 * in_stack_00000078);
    if (iVar1 != 0) {
      iVar2 = FUN_409c3ebc(param_2,in_stack_0000006c,in_stack_00000070,in_stack_00000074);
      if (iVar2 == 0) {
        iVar2 = FUN_409c85c0(param_1,param_2,param_3,param_4);
        mali_sys_free(iVar1);
        if ((iVar2 == 0) &&
           (puVar3 = (uint *)FUN_409c7554(param_1,param_3,param_4), puVar3 != (uint *)0x0)) {
          *puVar3 = in_stack_00000074;
          puVar3[1] = in_stack_00000078;
          puVar3[2] = 1;
          iVar1 = FUN_409c7034(param_1,param_3,param_4);
          if ((iVar1 != 0) && (*(int *)(iVar1 + 0x14) != 0)) {
            FUN_409bed4c();
          }
        }
      }
      else {
        mali_sys_free(iVar1);
      }
    }
  }
LAB_409c9014:
                    /* WARNING: Subroutine does not return */
  FUN_409da790(0x30);
}



/* 409c9020 FUN_409c9020 */

/* Boundary evidence: original MIPS .pdata 409c9020..409c91c7. Semantic name remains unreviewed. */

void FUN_409c9020(int param_1,undefined4 *param_2,int param_3,int param_4)

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
  
  FUN_409da758();
  iStack00000030 = param_3;
  puStack00000034 = param_2;
  if (((((((-1 < param_4) && (param_4 < 0xd)) && (-1 < in_stack_00000070)) &&
        ((-1 < in_stack_00000074 && (-1 < in_stack_00000078)))) &&
       (((-1 < in_stack_0000007c &&
         ((*(int *)(param_1 + 0x1c) != 0 &&
          (piVar2 = *(int **)(param_4 * 4 + *(int *)(param_1 + 0x1c)), piVar2 != (int *)0x0)))) &&
        (iVar1 = FUN_409c667c(in_stack_00000080,piVar2[3],in_stack_00000084), iVar1 == 0)))) &&
      ((((in_stack_00000080 == piVar2[3] && (in_stack_00000084 == piVar2[4])) &&
        (iVar1 = *piVar2, in_stack_00000070 <= iVar1)) &&
       (((iVar3 = piVar2[1], in_stack_00000074 <= iVar3 && (in_stack_00000078 <= iVar1)) &&
        ((in_stack_0000007c <= iVar3 &&
         ((in_stack_00000070 + in_stack_00000078 <= iVar1 &&
          (in_stack_00000074 + in_stack_0000007c <= iVar3)))))))))) &&
     ((*(int *)(param_1 + 0x34) != 0 && ((in_stack_00000078 != 0 && (in_stack_0000007c != 0)))))) {
    FUN_409c6a98(in_stack_0000008c,in_stack_00000078,in_stack_00000080,in_stack_00000084);
    FUN_409c8308(param_1,puStack00000034,iStack00000030,param_4);
  }
                    /* WARNING: Subroutine does not return */
  FUN_409da790(0x38);
}



/* 409c91c8 FUN_409c91c8 */

/* Boundary evidence: original MIPS .pdata 409c91c8..409c9323. Semantic name remains unreviewed. */

void FUN_409c91c8(int param_1,undefined4 *param_2,int param_3,uint param_4)

{
  int iVar1;
  uint uVar2;
  uint in_stack_00000058;
  int in_stack_0000005c;
  int in_stack_00000060;
  int in_stack_00000064;
  uint in_stack_00000068;
  int in_stack_0000006c;
  
  FUN_409da808();
  iVar1 = FUN_409c667c(in_stack_00000068,in_stack_00000058,in_stack_0000006c);
  if ((((iVar1 != 0) || ((int)param_4 < 0)) || (0xc < (int)param_4)) ||
     ((in_stack_00000064 != 0 || (in_stack_00000068 != in_stack_00000058)))) goto LAB_409c931c;
  if (in_stack_0000006c == 0x8363) {
    uVar2 = 0x1907;
LAB_409c9248:
    if (in_stack_00000068 != uVar2) goto LAB_409c931c;
  }
  else if ((in_stack_0000006c == 0x8033) || (in_stack_0000006c == 0x8034)) {
    uVar2 = 0x1908;
    goto LAB_409c9248;
  }
  if (((((-1 < in_stack_0000005c) && (-1 < in_stack_00000060)) && (in_stack_0000005c < 0x1001)) &&
      ((in_stack_00000060 < 0x1001 && (in_stack_0000005c << (param_4 & 0x1f) < 0x1001)))) &&
     ((in_stack_00000060 << (param_4 & 0x1f) < 0x1001 && (*(int *)(param_1 + 0x34) != 0)))) {
    FUN_409c85c0(param_1,param_2,param_3,param_4);
  }
LAB_409c931c:
                    /* WARNING: Subroutine does not return */
  FUN_409da838(0x28);
}



/* 409c9324 FUN_409c9324 */

/* Boundary evidence: original MIPS .pdata 409c9324..409c95c3. Semantic name remains unreviewed. */

void FUN_409c9324(int param_1,undefined4 *param_2,int param_3,int param_4)

{
  int iVar1;
  int *piVar2;
  uint *puVar3;
  int iVar4;
  int iVar5;
  undefined4 *puVar6;
  int in_stack_0000005c;
  int in_stack_00000060;
  
  FUN_409da758();
  if (in_stack_00000060 != 0) {
    iVar5 = *(int *)(in_stack_00000060 + 0x18);
    iVar1 = FUN_409ba304(iVar5);
    if ((iVar1 == 1) && ((iVar5 != 0xe || (*(int *)(in_stack_00000060 + 0x28) != 1)))) {
      *(undefined4 *)(param_1 + 0x3c) = 1;
      iVar1 = FUN_409c7a7c(*(int **)(param_1 + 0x34),param_2,param_3,param_4);
      if (iVar1 == 0) {
        piVar2 = *(int **)(param_1 + 0x34);
        mali_sys_atomic_inc(piVar2 + 0x62);
      }
      else {
        piVar2 = FUN_409bbe1c(*param_2,*(undefined4 **)(param_1 + 0x34));
        if (piVar2 == (int *)0x0) goto LAB_409c95b8;
      }
      puVar3 = (uint *)mali_sys_malloc(0x18);
      if (puVar3 == (uint *)0x0) {
        iVar1 = mali_sys_atomic_dec_and_return(piVar2 + 0x62);
        if (iVar1 == 0) {
          FUN_409bbdd8(piVar2);
        }
      }
      else {
        *puVar3 = (uint)*(ushort *)(in_stack_00000060 + 0xc);
        puVar3[1] = (uint)*(ushort *)(in_stack_00000060 + 0xe);
        puVar3[2] = 1;
        puVar3[5] = 0;
        FUN_409bbf60(*(undefined4 *)(in_stack_00000060 + 0x18),puVar3 + 4,puVar3 + 3);
        iVar1 = FUN_409c682c(param_3);
        iVar5 = 0;
        do {
          FUN_409bb40c((int)piVar2,iVar1,iVar5);
          iVar4 = *(int *)((iVar1 + 7) * 4 + param_1);
          if (iVar4 != 0) {
            FUN_409c68b4(iVar5,iVar4);
          }
          iVar5 = iVar5 + 1;
        } while (iVar5 < 0xd);
        iVar5 = FUN_409bb518((int)piVar2,param_3,param_4,in_stack_00000060,0);
        if (iVar5 == 0) {
          iVar5 = FUN_409c6fe0(param_1,param_3,param_4,puVar3);
          if (iVar5 == 0) {
            puVar6 = *(undefined4 **)(param_1 + 0x34);
            iVar1 = mali_sys_atomic_dec_and_return(puVar6 + 0x62);
            if (iVar1 == 0) {
              FUN_409bbdd8(puVar6);
            }
            *(int **)(param_1 + 0x34) = piVar2;
            FUN_409c764c(param_1,param_4);
            *(undefined4 *)(param_1 + 0x48) = 0;
            *(undefined4 *)(param_1 + 0x38) = 1;
            if ((((in_stack_0000005c != 1) || (*(char *)(param_1 + 0x14) == '\0')) || (param_4 != 0)
                ) || (iVar1 = FUN_409b6de8(param_2,param_1,param_3), iVar1 == 0)) {
              *(int *)((*(int *)(param_1 + 0x54) + 0x16) * 4 + param_1) = in_stack_00000060;
              *(int *)(param_1 + 0x54) = *(int *)(param_1 + 0x54) + 1;
            }
            goto LAB_409c95b8;
          }
          FUN_409bb40c((int)piVar2,iVar1,param_4);
          iVar1 = *(int *)((iVar1 + 7) * 4 + param_1);
          if (iVar1 != 0) {
            FUN_409c68b4(param_4,iVar1);
          }
        }
        iVar1 = mali_sys_atomic_dec_and_return(piVar2 + 0x62);
        if (iVar1 == 0) {
          FUN_409bbdd8(piVar2);
        }
        mali_sys_free(puVar3);
      }
    }
  }
LAB_409c95b8:
                    /* WARNING: Subroutine does not return */
  FUN_409da790(0x20);
}



/* 409c95c4 glViewport */

/* Boundary evidence: original MIPS .pdata 409c95c4..409c9697. Semantic name remains unreviewed. */

void glViewport(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  code *pcVar3;
  
                    /* 0x195c4  159  glViewport */
  if (DAT_409dd38c != 0) {
    if (*(int *)(DAT_409dd38c + 8) == 0) {
      iVar1 = *(int *)(DAT_409dd38c + 0xc);
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



/* 409c9698 glStencilOp */

/* Boundary evidence: original MIPS .pdata 409c9698..409c975f. Semantic name remains unreviewed. */

void glStencilOp(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  code *pcVar3;
  
                    /* 0x19698  121  glStencilOp */
  if (DAT_409dd38c != 0) {
    if (*(int *)(DAT_409dd38c + 8) == 0) {
      iVar1 = *(int *)(DAT_409dd38c + 0xc);
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



/* 409c9760 glStencilMask */

/* Boundary evidence: original MIPS .pdata 409c9760..409c9807. Semantic name remains unreviewed. */

void glStencilMask(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  code *pcVar3;
  
                    /* 0x19760  119  glStencilMask */
  if (DAT_409dd38c != 0) {
    if (*(int *)(DAT_409dd38c + 8) == 0) {
      iVar1 = *(int *)(DAT_409dd38c + 0xc);
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



/* 409c9808 glStencilFunc */

/* Boundary evidence: original MIPS .pdata 409c9808..409c98cf. Semantic name remains unreviewed. */

void glStencilFunc(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  code *pcVar3;
  
                    /* 0x19808  117  glStencilFunc */
  if (DAT_409dd38c != 0) {
    if (*(int *)(DAT_409dd38c + 8) == 0) {
      iVar1 = *(int *)(DAT_409dd38c + 0xc);
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



/* 409c98d0 glScissor */

/* Boundary evidence: original MIPS .pdata 409c98d0..409c99a3. Semantic name remains unreviewed. */

void glScissor(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  code *pcVar3;
  
                    /* 0x198d0  114  glScissor */
  if (DAT_409dd38c != 0) {
    if (*(int *)(DAT_409dd38c + 8) == 0) {
      iVar1 = *(int *)(DAT_409dd38c + 0xc);
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



/* 409c99a4 glSampleCoverage */

/* Boundary evidence: original MIPS .pdata 409c99a4..409c9a3b. Semantic name remains unreviewed. */

void glSampleCoverage(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  code *pcVar2;
  
                    /* 0x199a4  113  glSampleCoverage */
  if (DAT_409dd38c != 0) {
    if (*(int *)(DAT_409dd38c + 8) == 0) {
      iVar1 = *(int *)(DAT_409dd38c + 0xc);
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



/* 409c9a3c glPolygonOffset */

/* Boundary evidence: original MIPS .pdata 409c9a3c..409c9aef. Semantic name remains unreviewed. */

void glPolygonOffset(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  code *pcVar3;
  
                    /* 0x19a3c  109  glPolygonOffset */
  if (DAT_409dd38c != 0) {
    if (*(int *)(DAT_409dd38c + 8) == 0) {
      iVar1 = *(int *)(DAT_409dd38c + 0xc);
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



/* 409c9af0 glPixelStorei */

/* Boundary evidence: original MIPS .pdata 409c9af0..409c9ba3. Semantic name remains unreviewed. */

void glPixelStorei(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  code *pcVar3;
  
                    /* 0x19af0  108  glPixelStorei */
  if (DAT_409dd38c != 0) {
    if (*(int *)(DAT_409dd38c + 8) == 0) {
      iVar1 = *(int *)(DAT_409dd38c + 0xc);
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



/* 409c9ba4 glLineWidth */

/* Boundary evidence: original MIPS .pdata 409c9ba4..409c9c2f. Semantic name remains unreviewed. */

void glLineWidth(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  
                    /* 0x19ba4  106  glLineWidth */
  if (DAT_409dd38c != 0) {
    if (*(int *)(DAT_409dd38c + 8) == 0) {
      iVar1 = *(int *)(DAT_409dd38c + 0xc);
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



/* 409c9c30 glIsEnabled */

/* Boundary evidence: original MIPS .pdata 409c9c30..409c9cf3. Semantic name remains unreviewed. */

undefined1 glIsEnabled(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  code *pcVar3;
  undefined1 local_18 [8];
  
                    /* 0x19c30  100  glIsEnabled */
  if (DAT_409dd38c != 0) {
    if (*(int *)(DAT_409dd38c + 8) == 0) {
      iVar1 = *(int *)(DAT_409dd38c + 0xc);
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



/* 409c9cf4 glHint */

/* Boundary evidence: original MIPS .pdata 409c9cf4..409c9da7. Semantic name remains unreviewed. */

void glHint(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  code *pcVar3;
  
                    /* 0x19cf4  98  glHint */
  if (DAT_409dd38c != 0) {
    if (*(int *)(DAT_409dd38c + 8) == 0) {
      iVar1 = *(int *)(DAT_409dd38c + 0xc);
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



/* 409c9da8 glGetString */

/* Boundary evidence: original MIPS .pdata 409c9da8..409c9e6b. Semantic name remains unreviewed. */

undefined4 glGetString(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  code *pcVar3;
  undefined4 local_18 [2];
  
                    /* 0x19da8  89  glGetString */
  if (DAT_409dd38c != 0) {
    if (*(int *)(DAT_409dd38c + 8) == 0) {
      iVar1 = *(int *)(DAT_409dd38c + 0xc);
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



/* 409c9e6c glGetError */

/* Boundary evidence: original MIPS .pdata 409c9e6c..409c9efb. Semantic name remains unreviewed. */

undefined4 glGetError(void)

{
  int iVar1;
  undefined4 uVar2;
  code *pcVar3;
  
                    /* 0x19e6c  78  glGetError */
  if (DAT_409dd38c != 0) {
    if (*(int *)(DAT_409dd38c + 8) == 0) {
      iVar1 = *(int *)(DAT_409dd38c + 0xc);
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



/* 409c9efc glFrontFace */

/* Boundary evidence: original MIPS .pdata 409c9efc..409c9f9f. Semantic name remains unreviewed. */

void glFrontFace(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  code *pcVar3;
  
                    /* 0x19efc  66  glFrontFace */
  if (DAT_409dd38c != 0) {
    if (*(int *)(DAT_409dd38c + 8) == 0) {
      iVar1 = *(int *)(DAT_409dd38c + 0xc);
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



/* 409c9fa0 glEnable */

/* Boundary evidence: original MIPS .pdata 409c9fa0..409ca02f. Semantic name remains unreviewed. */

void glEnable(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  
                    /* 0x19fa0  60  glEnable */
  if (DAT_409dd38c != 0) {
    if (*(int *)(DAT_409dd38c + 8) == 0) {
      iVar1 = *(int *)(DAT_409dd38c + 0xc);
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



/* 409ca030 glDisable */

/* Boundary evidence: original MIPS .pdata 409ca030..409ca0d7. Semantic name remains unreviewed. */

void glDisable(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  code *pcVar3;
  
                    /* 0x1a030  54  glDisable */
  if (DAT_409dd38c != 0) {
    if (*(int *)(DAT_409dd38c + 8) == 0) {
      iVar1 = *(int *)(DAT_409dd38c + 0xc);
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



/* 409ca0d8 glDepthRangef */

/* Boundary evidence: original MIPS .pdata 409ca0d8..409ca16f. Semantic name remains unreviewed. */

void glDepthRangef(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  code *pcVar2;
  
                    /* 0x1a0d8  52  glDepthRangef */
  if (DAT_409dd38c != 0) {
    if (*(int *)(DAT_409dd38c + 8) == 0) {
      iVar1 = *(int *)(DAT_409dd38c + 0xc);
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



/* 409ca170 glDepthMask */

/* Boundary evidence: original MIPS .pdata 409ca170..409ca1f7. Semantic name remains unreviewed. */

void glDepthMask(undefined4 param_1)

{
  int iVar1;
  code *pcVar2;
  
                    /* 0x1a170  51  glDepthMask */
  if (DAT_409dd38c != 0) {
    if (*(int *)(DAT_409dd38c + 8) == 0) {
      iVar1 = *(int *)(DAT_409dd38c + 0xc);
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



/* 409ca1f8 glDepthFunc */

/* Boundary evidence: original MIPS .pdata 409ca1f8..409ca29b. Semantic name remains unreviewed. */

void glDepthFunc(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  code *pcVar3;
  
                    /* 0x1a1f8  50  glDepthFunc */
  if (DAT_409dd38c != 0) {
    if (*(int *)(DAT_409dd38c + 8) == 0) {
      iVar1 = *(int *)(DAT_409dd38c + 0xc);
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



/* 409ca29c glCullFace */

/* Boundary evidence: original MIPS .pdata 409ca29c..409ca33f. Semantic name remains unreviewed. */

void glCullFace(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  code *pcVar3;
  
                    /* 0x1a29c  43  glCullFace */
  if (DAT_409dd38c != 0) {
    if (*(int *)(DAT_409dd38c + 8) == 0) {
      iVar1 = *(int *)(DAT_409dd38c + 0xc);
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



/* 409ca340 glColorMask */

/* Boundary evidence: original MIPS .pdata 409ca340..409ca3f7. Semantic name remains unreviewed. */

void glColorMask(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined1 param_4)

{
  int iVar1;
  code *pcVar2;
  
                    /* 0x1a340  35  glColorMask */
  if (DAT_409dd38c != 0) {
    if (*(int *)(DAT_409dd38c + 8) == 0) {
      iVar1 = *(int *)(DAT_409dd38c + 0xc);
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



/* 409ca3f8 glClearStencil */

/* Boundary evidence: original MIPS .pdata 409ca3f8..409ca47f. Semantic name remains unreviewed. */

void glClearStencil(undefined4 param_1)

{
  int iVar1;
  code *pcVar2;
  
                    /* 0x1a3f8  34  glClearStencil */
  if (DAT_409dd38c != 0) {
    if (*(int *)(DAT_409dd38c + 8) == 0) {
      iVar1 = *(int *)(DAT_409dd38c + 0xc);
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



/* 409ca480 glClearDepthf */

/* Boundary evidence: original MIPS .pdata 409ca480..409ca507. Semantic name remains unreviewed. */

void glClearDepthf(undefined4 param_1)

{
  int iVar1;
  code *pcVar2;
  
                    /* 0x1a480  33  glClearDepthf */
  if (DAT_409dd38c != 0) {
    if (*(int *)(DAT_409dd38c + 8) == 0) {
      iVar1 = *(int *)(DAT_409dd38c + 0xc);
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



/* 409ca508 glClearColor */

/* Boundary evidence: original MIPS .pdata 409ca508..409ca5bf. Semantic name remains unreviewed. */

void glClearColor(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  code *pcVar2;
  
                    /* 0x1a508  32  glClearColor */
  if (DAT_409dd38c != 0) {
    if (*(int *)(DAT_409dd38c + 8) == 0) {
      iVar1 = *(int *)(DAT_409dd38c + 0xc);
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



/* 409ca5c0 glBlendFunc */

/* Boundary evidence: original MIPS .pdata 409ca5c0..409ca67b. Semantic name remains unreviewed. */

void glBlendFunc(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  code *pcVar3;
  
                    /* 0x1a5c0  26  glBlendFunc */
  if (DAT_409dd38c != 0) {
    if (*(int *)(DAT_409dd38c + 8) == 0) {
      iVar1 = *(int *)(DAT_409dd38c + 0xc);
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



/* 409ca67c FUN_409ca67c */

/* Boundary evidence: original MIPS .pdata 409ca67c..409ca697. Semantic name remains unreviewed. */

void FUN_409ca67c(int param_1)

{
  mali_sys_mutex_unlock(*(undefined4 *)(param_1 + 0x1c));
  return;
}



/* 409ca698 FUN_409ca698 */

/* Boundary evidence: original MIPS .pdata 409ca698..409ca6b3. Semantic name remains unreviewed. */

void FUN_409ca698(int param_1)

{
  mali_sys_mutex_lock(*(undefined4 *)(param_1 + 0x1c));
  return;
}



/* 409ca6b4 glEGLImageTargetRenderbufferStorageOES */

/* Boundary evidence: original MIPS .pdata 409ca6b4..409ca783. Semantic name remains unreviewed. */

void glEGLImageTargetRenderbufferStorageOES(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  code *pcVar3;
  
                    /* 0x1a6b4  58  glEGLImageTargetRenderbufferStorageOES */
  if (DAT_409dd38c != 0) {
    if (*(int *)(DAT_409dd38c + 8) == 0) {
      iVar1 = *(int *)(DAT_409dd38c + 0xc);
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



/* 409ca784 glEGLImageTargetTexture2DOES */

/* Boundary evidence: original MIPS .pdata 409ca784..409ca853. Semantic name remains unreviewed. */

void glEGLImageTargetTexture2DOES(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  code *pcVar3;
  
                    /* 0x1a784  59  glEGLImageTargetTexture2DOES */
  if (DAT_409dd38c != 0) {
    if (*(int *)(DAT_409dd38c + 8) == 0) {
      iVar1 = *(int *)(DAT_409dd38c + 0xc);
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



/* 409ca854 glTexSubImage2D */

/* Boundary evidence: original MIPS .pdata 409ca854..409ca973. Semantic name remains unreviewed. */

void glTexSubImage2D(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                    undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
                    undefined4 param_9)

{
  int iVar1;
  int iVar2;
  code *pcVar3;
  
                    /* 0x1a854  128  glTexSubImage2D */
  if (DAT_409dd38c != 0) {
    if (*(int *)(DAT_409dd38c + 8) == 0) {
      iVar1 = *(int *)(DAT_409dd38c + 0xc);
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



/* 409ca974 glTexParameteriv */

/* Boundary evidence: original MIPS .pdata 409ca974..409caa5b. Semantic name remains unreviewed. */

void glTexParameteriv(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  code *pcVar3;
  
                    /* 0x1a974  127  glTexParameteriv */
  if (DAT_409dd38c != 0) {
    if (*(int *)(DAT_409dd38c + 8) == 0) {
      iVar1 = *(int *)(DAT_409dd38c + 0xc);
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



/* 409caa5c glTexParameteri */

/* Boundary evidence: original MIPS .pdata 409caa5c..409cab3b. Semantic name remains unreviewed. */

void glTexParameteri(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  code *pcVar3;
  undefined4 local_res8 [2];
  
                    /* 0x1aa5c  126  glTexParameteri */
  if (DAT_409dd38c != 0) {
    local_res8[0] = param_3;
    if (*(int *)(DAT_409dd38c + 8) == 0) {
      iVar1 = *(int *)(DAT_409dd38c + 0xc);
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



/* 409cab3c glTexParameterfv */

/* Boundary evidence: original MIPS .pdata 409cab3c..409cac1f. Semantic name remains unreviewed. */

void glTexParameterfv(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  code *pcVar3;
  
                    /* 0x1ab3c  125  glTexParameterfv */
  if (DAT_409dd38c != 0) {
    if (*(int *)(DAT_409dd38c + 8) == 0) {
      iVar1 = *(int *)(DAT_409dd38c + 0xc);
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



/* 409cac20 glTexParameterf */

/* Boundary evidence: original MIPS .pdata 409cac20..409cacfb. Semantic name remains unreviewed. */

void glTexParameterf(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  code *pcVar3;
  undefined4 local_res8 [2];
  
                    /* 0x1ac20  124  glTexParameterf */
  if (DAT_409dd38c != 0) {
    local_res8[0] = param_3;
    if (*(int *)(DAT_409dd38c + 8) == 0) {
      iVar1 = *(int *)(DAT_409dd38c + 0xc);
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



/* 409cacfc glTexImage2D */

/* Boundary evidence: original MIPS .pdata 409cacfc..409cae1b. Semantic name remains unreviewed. */

void glTexImage2D(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
                 undefined4 param_9)

{
  int iVar1;
  int iVar2;
  code *pcVar3;
  
                    /* 0x1acfc  123  glTexImage2D */
  if (DAT_409dd38c != 0) {
    if (*(int *)(DAT_409dd38c + 8) == 0) {
      iVar1 = *(int *)(DAT_409dd38c + 0xc);
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



/* 409cae1c glReadPixels */

/* Boundary evidence: original MIPS .pdata 409cae1c..409caf23. Semantic name remains unreviewed. */

void glReadPixels(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,undefined4 param_7)

{
  int iVar1;
  int iVar2;
  code *pcVar3;
  
                    /* 0x1ae1c  110  glReadPixels */
  if (DAT_409dd38c != 0) {
    if (*(int *)(DAT_409dd38c + 8) == 0) {
      iVar1 = *(int *)(DAT_409dd38c + 0xc);
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



/* 409caf24 glIsTexture */

/* Boundary evidence: original MIPS .pdata 409caf24..409cafe7. Semantic name remains unreviewed. */

undefined4 glIsTexture(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  code *pcVar3;
  
                    /* 0x1af24  105  glIsTexture */
  if (DAT_409dd38c != 0) {
    if (*(int *)(DAT_409dd38c + 8) == 0) {
      iVar1 = *(int *)(DAT_409dd38c + 0xc);
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



/* 409cafe8 glIsBuffer */

/* Boundary evidence: original MIPS .pdata 409cafe8..409cb0ab. Semantic name remains unreviewed. */

undefined4 glIsBuffer(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  code *pcVar3;
  
                    /* 0x1afe8  99  glIsBuffer */
  if (DAT_409dd38c != 0) {
    if (*(int *)(DAT_409dd38c + 8) == 0) {
      iVar1 = *(int *)(DAT_409dd38c + 0xc);
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



/* 409cb0ac glGetTexParameteriv */

/* Boundary evidence: original MIPS .pdata 409cb0ac..409cb193. Semantic name remains unreviewed. */

void glGetTexParameteriv(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  code *pcVar3;
  
                    /* 0x1b0ac  91  glGetTexParameteriv */
  if (DAT_409dd38c != 0) {
    if (*(int *)(DAT_409dd38c + 8) == 0) {
      iVar1 = *(int *)(DAT_409dd38c + 0xc);
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



/* 409cb194 glGetTexParameterfv */

/* Boundary evidence: original MIPS .pdata 409cb194..409cb277. Semantic name remains unreviewed. */

void glGetTexParameterfv(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  code *pcVar3;
  
                    /* 0x1b194  90  glGetTexParameterfv */
  if (DAT_409dd38c != 0) {
    if (*(int *)(DAT_409dd38c + 8) == 0) {
      iVar1 = *(int *)(DAT_409dd38c + 0xc);
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



/* 409cb278 glGetIntegerv */

/* Boundary evidence: original MIPS .pdata 409cb278..409cb34b. Semantic name remains unreviewed. */

void glGetIntegerv(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  code *pcVar3;
  
                    /* 0x1b278  81  glGetIntegerv */
  if (DAT_409dd38c != 0) {
    if (*(int *)(DAT_409dd38c + 8) == 0) {
      iVar1 = *(int *)(DAT_409dd38c + 0xc);
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



/* 409cb34c glGetFloatv */

/* Boundary evidence: original MIPS .pdata 409cb34c..409cb41f. Semantic name remains unreviewed. */

void glGetFloatv(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  code *pcVar3;
  
                    /* 0x1b34c  79  glGetFloatv */
  if (DAT_409dd38c != 0) {
    if (*(int *)(DAT_409dd38c + 8) == 0) {
      iVar1 = *(int *)(DAT_409dd38c + 0xc);
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



/* 409cb420 glGetBufferParameteriv */

/* Boundary evidence: original MIPS .pdata 409cb420..409cb4ff. Semantic name remains unreviewed. */

void glGetBufferParameteriv(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  code *pcVar3;
  
                    /* 0x1b420  77  glGetBufferParameteriv */
  if (DAT_409dd38c != 0) {
    if (*(int *)(DAT_409dd38c + 8) == 0) {
      iVar1 = *(int *)(DAT_409dd38c + 0xc);
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



/* 409cb500 glGetBooleanv */

/* Boundary evidence: original MIPS .pdata 409cb500..409cb5d3. Semantic name remains unreviewed. */

void glGetBooleanv(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  code *pcVar3;
  
                    /* 0x1b500  76  glGetBooleanv */
  if (DAT_409dd38c != 0) {
    if (*(int *)(DAT_409dd38c + 8) == 0) {
      iVar1 = *(int *)(DAT_409dd38c + 0xc);
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



/* 409cb5d4 glGenTextures */

/* Boundary evidence: original MIPS .pdata 409cb5d4..409cb6ab. Semantic name remains unreviewed. */

void glGenTextures(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  code *pcVar3;
  
                    /* 0x1b5d4  70  glGenTextures */
  if (DAT_409dd38c != 0) {
    if (*(int *)(DAT_409dd38c + 8) == 0) {
      iVar1 = *(int *)(DAT_409dd38c + 0xc);
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



/* 409cb6ac glGenBuffers */

/* Boundary evidence: original MIPS .pdata 409cb6ac..409cb783. Semantic name remains unreviewed. */

void glGenBuffers(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  code *pcVar3;
  
                    /* 0x1b6ac  67  glGenBuffers */
  if (DAT_409dd38c != 0) {
    if (*(int *)(DAT_409dd38c + 8) == 0) {
      iVar1 = *(int *)(DAT_409dd38c + 0xc);
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



/* 409cb784 glFlush */

/* Boundary evidence: original MIPS .pdata 409cb784..409cb83f. Semantic name remains unreviewed. */

void glFlush(void)

{
  int iVar1;
  int iVar2;
  code *pcVar3;
  
                    /* 0x1b784  63  glFlush */
  if (DAT_409dd38c != 0) {
    if (*(int *)(DAT_409dd38c + 8) == 0) {
      iVar1 = *(int *)(DAT_409dd38c + 0xc);
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



/* 409cb840 glFinish */

/* Boundary evidence: original MIPS .pdata 409cb840..409cb8fb. Semantic name remains unreviewed. */

void glFinish(void)

{
  int iVar1;
  int iVar2;
  code *pcVar3;
  
                    /* 0x1b840  62  glFinish */
  if (DAT_409dd38c != 0) {
    if (*(int *)(DAT_409dd38c + 8) == 0) {
      iVar1 = *(int *)(DAT_409dd38c + 0xc);
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



/* 409cb8fc glDrawElements */

/* Boundary evidence: original MIPS .pdata 409cb8fc..409cb9cf. Semantic name remains unreviewed. */

void glDrawElements(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  
                    /* 0x1b8fc  57  glDrawElements */
  if (DAT_409dd38c != 0) {
    if (*(int *)(DAT_409dd38c + 8) == 0) {
      iVar1 = *(int *)(DAT_409dd38c + 0xc);
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



/* 409cb9d0 glDrawArrays */

/* Boundary evidence: original MIPS .pdata 409cb9d0..409cba93. Semantic name remains unreviewed. */

void glDrawArrays(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  
                    /* 0x1b9d0  56  glDrawArrays */
  if (DAT_409dd38c != 0) {
    if (*(int *)(DAT_409dd38c + 8) == 0) {
      iVar1 = *(int *)(DAT_409dd38c + 0xc);
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



/* 409cba94 glDeleteTextures */

/* Boundary evidence: original MIPS .pdata 409cba94..409cbb63. Semantic name remains unreviewed. */

void glDeleteTextures(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  code *pcVar3;
  
                    /* 0x1ba94  49  glDeleteTextures */
  if (DAT_409dd38c != 0) {
    if (*(int *)(DAT_409dd38c + 8) == 0) {
      iVar1 = *(int *)(DAT_409dd38c + 0xc);
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



/* 409cbb64 glDeleteBuffers */

/* Boundary evidence: original MIPS .pdata 409cbb64..409cbc3b. Semantic name remains unreviewed. */

void glDeleteBuffers(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  code *pcVar3;
  
                    /* 0x1bb64  44  glDeleteBuffers */
  if (DAT_409dd38c != 0) {
    if (*(int *)(DAT_409dd38c + 8) == 0) {
      iVar1 = *(int *)(DAT_409dd38c + 0xc);
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



/* 409cbc3c glCopyTexSubImage2D */

/* Boundary evidence: original MIPS .pdata 409cbc3c..409cbd4b. Semantic name remains unreviewed. */

void glCopyTexSubImage2D(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4
                        ,undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8
                        )

{
  int iVar1;
  int iVar2;
  code *pcVar3;
  
                    /* 0x1bc3c  40  glCopyTexSubImage2D */
  if (DAT_409dd38c != 0) {
    if (*(int *)(DAT_409dd38c + 8) == 0) {
      iVar1 = *(int *)(DAT_409dd38c + 0xc);
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



/* 409cbd4c glCopyTexImage2D */

/* Boundary evidence: original MIPS .pdata 409cbd4c..409cbe5b. Semantic name remains unreviewed. */

void glCopyTexImage2D(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                     undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8)

{
  int iVar1;
  int iVar2;
  code *pcVar3;
  
                    /* 0x1bd4c  39  glCopyTexImage2D */
  if (DAT_409dd38c != 0) {
    if (*(int *)(DAT_409dd38c + 8) == 0) {
      iVar1 = *(int *)(DAT_409dd38c + 0xc);
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



/* 409cbe5c glCompressedTexSubImage2D */

/* Boundary evidence: original MIPS .pdata 409cbe5c..409cbf73. Semantic name remains unreviewed. */

void glCompressedTexSubImage2D
               (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
               undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
               undefined4 param_9)

{
  int iVar1;
  int iVar2;
  code *pcVar3;
  
                    /* 0x1be5c  38  glCompressedTexSubImage2D */
  if (DAT_409dd38c != 0) {
    if (*(int *)(DAT_409dd38c + 8) == 0) {
      iVar1 = *(int *)(DAT_409dd38c + 0xc);
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



/* 409cbf74 glCompressedTexImage2D */

/* Boundary evidence: original MIPS .pdata 409cbf74..409cc083. Semantic name remains unreviewed. */

void glCompressedTexImage2D
               (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
               undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8)

{
  int iVar1;
  int iVar2;
  code *pcVar3;
  
                    /* 0x1bf74  37  glCompressedTexImage2D */
  if (DAT_409dd38c != 0) {
    if (*(int *)(DAT_409dd38c + 8) == 0) {
      iVar1 = *(int *)(DAT_409dd38c + 0xc);
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



/* 409cc084 glClear */

/* Boundary evidence: original MIPS .pdata 409cc084..409cc143. Semantic name remains unreviewed. */

void glClear(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  code *pcVar3;
  
                    /* 0x1c084  31  glClear */
  if (DAT_409dd38c != 0) {
    if (*(int *)(DAT_409dd38c + 8) == 0) {
      iVar1 = *(int *)(DAT_409dd38c + 0xc);
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



/* 409cc144 glBufferSubData */

/* Boundary evidence: original MIPS .pdata 409cc144..409cc237. Semantic name remains unreviewed. */

void glBufferSubData(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 *puVar1;
  int iVar2;
  
                    /* 0x1c144  29  glBufferSubData */
  if (DAT_409dd38c != 0) {
    if (*(int *)(DAT_409dd38c + 8) == 0) {
      puVar1 = *(undefined4 **)(DAT_409dd38c + 0xc);
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



/* 409cc238 glBufferData */

/* Boundary evidence: original MIPS .pdata 409cc238..409cc32f. Semantic name remains unreviewed. */

void glBufferData(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 *puVar1;
  int iVar2;
  
                    /* 0x1c238  28  glBufferData */
  if (DAT_409dd38c != 0) {
    if (*(int *)(DAT_409dd38c + 8) == 0) {
      puVar1 = *(undefined4 **)(DAT_409dd38c + 0xc);
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



/* 409cc330 glBindTexture */

/* Boundary evidence: original MIPS .pdata 409cc330..409cc3e7. Semantic name remains unreviewed. */

void glBindTexture(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  
                    /* 0x1c330  22  glBindTexture */
  if (DAT_409dd38c != 0) {
    if (*(int *)(DAT_409dd38c + 8) == 0) {
      iVar1 = *(int *)(DAT_409dd38c + 0xc);
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



/* 409cc3e8 glBindBuffer */

/* Boundary evidence: original MIPS .pdata 409cc3e8..409cc4bf. Semantic name remains unreviewed. */

void glBindBuffer(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  code *pcVar3;
  
                    /* 0x1c3e8  19  glBindBuffer */
  if (DAT_409dd38c != 0) {
    if (*(int *)(DAT_409dd38c + 8) == 0) {
      iVar1 = *(int *)(DAT_409dd38c + 0xc);
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



/* 409cc4c0 glActiveTexture */

/* Boundary evidence: original MIPS .pdata 409cc4c0..409cc57f. Semantic name remains unreviewed. */

void glActiveTexture(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  code *pcVar3;
  
                    /* 0x1c4c0  16  glActiveTexture */
  if (DAT_409dd38c != 0) {
    if (*(int *)(DAT_409dd38c + 8) == 0) {
      iVar1 = *(int *)(DAT_409dd38c + 0xc);
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



/* 409cc580 FUN_409cc580 */

/* Boundary evidence: original MIPS .pdata 409cc580..409cc5cf. Semantic name remains unreviewed. */

void FUN_409cc580(undefined4 param_1,undefined *param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5)

{
  int iVar1;
  
  FUN_409da7c8();
  param_5 = 0;
  while (iVar1 = __mali_named_list_iterate_begin(param_1,&param_5), iVar1 != 0) {
    __mali_named_list_remove(param_1,param_5);
    (*(code *)param_2)(iVar1);
  }
                    /* WARNING: Subroutine does not return */
  FUN_409da7e8(0x18);
}



/* 409cc5d0 FUN_409cc5d0 */

/* Boundary evidence: original MIPS .pdata 409cc5d0..409cc61f. Semantic name remains unreviewed. */

void FUN_409cc5d0(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 unaff_s0;
  
  FUN_409cc580(*(undefined4 *)(param_1 + 0x10),FUN_409be658,param_3,param_4,unaff_s0);
  FUN_409cc580(*(undefined4 *)(param_1 + 0x14),FUN_409bf784,param_3,param_4,unaff_s0);
  FUN_409cc580(*(undefined4 *)(param_1 + 0x18),FUN_409d381c,param_3,param_4,unaff_s0);
  return;
}



/* 409cc620 __gles20_build_info */

char * __gles20_build_info(void)

{
                    /* 0x1c620  1  __gles20_build_info */
  return "gles20:  ";
}



/* 409cc66c FUN_409cc66c */

/* Boundary evidence: original MIPS .pdata 409cc66c..409cc6cb. Semantic name remains unreviewed. */

undefined4 FUN_409cc66c(undefined4 *param_1,int param_2)

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



/* 409cc700 FUN_409cc700 */

/* Boundary evidence: original MIPS .pdata 409cc700..409cc71b. Semantic name remains unreviewed. */

void FUN_409cc700(int param_1)

{
  mali_sys_atomic_inc(param_1 + 0x50);
  return;
}



/* 409cc71c FUN_409cc71c */

uint FUN_409cc71c(uint param_1)

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



/* 409cc7cc FUN_409cc7cc */

void FUN_409cc7cc(int *param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *param_1;
  if (param_2 == 0xde1) {
    iVar2 = 0;
  }
  else if (param_2 == 0x8513) {
    iVar2 = 1;
  }
  else {
    iVar2 = -1;
  }
  param_1[iVar1 * 5 + iVar2 + 4] = param_3;
  param_1[iVar1 * 5 + iVar2 + 2] = param_4;
  return;
}



/* 409cc82c FUN_409cc82c */

void FUN_409cc82c(int *param_1,int param_2,int *param_3,int *param_4)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *param_1;
  if (param_2 == 0xde1) {
    iVar2 = 0;
  }
  else if (param_2 == 0x8513) {
    iVar2 = 1;
  }
  else {
    iVar2 = -1;
  }
  if (param_3 != (int *)0x0) {
    *param_3 = param_1[iVar1 * 5 + iVar2 + 4];
  }
  if (param_4 != (int *)0x0) {
    *param_4 = param_1[iVar1 * 5 + iVar2 + 2];
  }
  return;
}



/* 409cc8a8 FUN_409cc8a8 */

/* Boundary evidence: original MIPS .pdata 409cc8a8..409cc93f. Semantic name remains unreviewed. */

void FUN_409cc8a8(undefined4 *param_1,int *param_2)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  int iVar6;
  
  *param_1 = 0;
  piVar2 = param_1 + 2;
  iVar3 = 8;
  do {
    iVar6 = 2;
    piVar4 = piVar2;
    piVar5 = param_2;
    do {
      iVar1 = *piVar5;
      *(undefined1 *)(piVar2 + -1) = 1;
      *piVar4 = iVar1;
      piVar4[2] = 0;
      mali_sys_atomic_inc(iVar1 + 0x50);
      piVar5 = piVar5 + 1;
      iVar6 = iVar6 + -1;
      piVar4 = piVar4 + 1;
    } while (iVar6 != 0);
    iVar3 = iVar3 + -1;
    piVar2 = piVar2 + 5;
  } while (iVar3 != 0);
  return;
}



/* 409cc940 FUN_409cc940 */

void FUN_409cc940(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 8);
  if (iVar1 != 0x2901) {
    if (iVar1 == 0x812f) {
      iVar1 = 1;
      goto LAB_409cc97c;
    }
    if (iVar1 == 0x8370) {
      iVar1 = 4;
      goto LAB_409cc97c;
    }
  }
  iVar1 = 0;
LAB_409cc97c:
  *(uint *)(*(int *)(param_1 + 0x34) + 0x140) =
       *(uint *)(*(int *)(param_1 + 0x34) + 0x140) & 0xfff8ffff | iVar1 << 0x10;
  return;
}



/* 409cc9a0 FUN_409cc9a0 */

void FUN_409cc9a0(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 4);
  if (iVar1 != 0x2901) {
    if (iVar1 == 0x812f) {
      iVar1 = 1;
      goto LAB_409cc9dc;
    }
    if (iVar1 == 0x8370) {
      iVar1 = 4;
      goto LAB_409cc9dc;
    }
  }
  iVar1 = 0;
LAB_409cc9dc:
  *(uint *)(*(int *)(param_1 + 0x34) + 0x140) =
       *(uint *)(*(int *)(param_1 + 0x34) + 0x140) & 0xffff1fff | iVar1 << 0xd;
  return;
}



/* 409cca00 FUN_409cca00 */

/* Boundary evidence: original MIPS .pdata 409cca00..409ccb6b. Semantic name remains unreviewed. */

void FUN_409cca00(int param_1)

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
      uVar1 = FUN_409cc71c(((uVar1 >> 0x10 | uVar1) >> 1) + 1);
      *(uint *)(iVar3 + 0x13c) = uVar1 << 0x18 | *(uint *)(iVar3 + 0x13c) & 0xf00fffff;
    }
  }
  return;
}



/* 409ccb6c FUN_409ccb6c */

/* Boundary evidence: original MIPS .pdata 409ccb6c..409ccbd7. Semantic name remains unreviewed. */

undefined4 FUN_409ccb6c(uint param_1,int *param_2,int *param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_409d3fa4(param_1);
  if (iVar1 == -1) {
    uVar2 = 0x500;
  }
  else {
    uVar2 = 0;
    *param_3 = param_2[*param_2 * 5 + iVar1 + 2];
  }
  return uVar2;
}



/* 409ccbd8 FUN_409ccbd8 */

/* Boundary evidence: original MIPS .pdata 409ccbd8..409ccc23. Semantic name remains unreviewed. */

void FUN_409ccbd8(int param_1)

{
  *(uint *)(*(int *)(param_1 + 0x34) + 0x140) =
       *(uint *)(*(int *)(param_1 + 0x34) + 0x140) & 0xffffefff |
       (uint)(*(int *)(param_1 + 0x10) == 0x2600) << 0xc;
  FUN_409cca00(param_1);
  return;
}



/* 409ccc24 FUN_409ccc24 */

/* Boundary evidence: original MIPS .pdata 409ccc24..409ccd03. Semantic name remains unreviewed. */

void FUN_409ccc24(int param_1)

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
  FUN_409cca00(param_1);
  return;
}



/* 409ccd04 FUN_409ccd04 */

/* Boundary evidence: original MIPS .pdata 409ccd04..409ccf87. Semantic name remains unreviewed. */

undefined4 FUN_409ccd04(int *param_1,int param_2,int param_3,undefined4 *param_4,int param_5)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  uint uVar5;
  int local_50 [6];
  int local_38 [6];
  
  local_50[2] = 0x812f;
  local_50[3] = 0x2901;
  local_50[4] = 0x8370;
  local_38[0] = 0x2600;
  local_38[1] = 0x2601;
  local_38[2] = 0x2700;
  local_38[3] = 0x2701;
  local_38[4] = 0x2703;
  local_38[5] = 0x2702;
  local_50[0] = 0x2600;
  local_50[1] = 0x2601;
  iVar1 = FUN_409cc66c(param_4,param_5);
  if (param_2 == 0xde1) {
    iVar2 = 0;
  }
  else {
    if (param_2 != 0x8513) {
      return 0x500;
    }
    iVar2 = 1;
  }
  iVar2 = param_1[*param_1 * 5 + iVar2 + 2];
  if (param_3 == 0x2800) {
    if (*(int *)(iVar2 + 0x10) == iVar1) {
      return 0;
    }
    uVar5 = 0;
    piVar3 = local_50;
    do {
      if (iVar1 == *piVar3) {
        *(int *)(iVar2 + 0x10) = iVar1;
        FUN_409ccbd8(iVar2);
        goto LAB_409ccf5c;
      }
      uVar5 = uVar5 + 1;
      prefetch(piVar3 + 2,0);
      piVar3 = piVar3 + 1;
    } while (uVar5 < 2);
  }
  else if (param_3 == 0x2801) {
    iVar4 = *(int *)(iVar2 + 0xc);
    if (iVar4 == iVar1) {
      return 0;
    }
    uVar5 = 0;
    piVar3 = local_38;
    do {
      if (iVar1 == *piVar3) {
        if ((((iVar4 == 0x2600) || (iVar4 == 0x2601)) && (iVar1 != 0x2600)) && (iVar1 != 0x2601)) {
          *(undefined4 *)(*(int *)(iVar2 + 0x34) + 0x184) = 1;
        }
        *(int *)(iVar2 + 0xc) = iVar1;
        FUN_409ccc24(iVar2);
        *(undefined4 *)(iVar2 + 0x3c) = 1;
        goto LAB_409ccf5c;
      }
      uVar5 = uVar5 + 1;
      prefetch(piVar3 + 2,0);
      piVar3 = piVar3 + 1;
    } while (uVar5 < 6);
  }
  else if (param_3 == 0x2802) {
    if (*(int *)(iVar2 + 4) == iVar1) {
      return 0;
    }
    uVar5 = 0;
    piVar3 = local_50 + 2;
    do {
      if (iVar1 == *piVar3) {
        *(int *)(iVar2 + 4) = iVar1;
        FUN_409cc9a0(iVar2);
        goto LAB_409ccf5c;
      }
      uVar5 = uVar5 + 1;
      prefetch(piVar3 + 2,0);
      piVar3 = piVar3 + 1;
    } while (uVar5 < 3);
  }
  else if (param_3 == 0x2803) {
    if (*(int *)(iVar2 + 8) == iVar1) {
      return 0;
    }
    uVar5 = 0;
    piVar3 = local_50 + 2;
    do {
      if (iVar1 == *piVar3) {
        *(int *)(iVar2 + 8) = iVar1;
        FUN_409cc940(iVar2);
LAB_409ccf5c:
        *(undefined4 *)(iVar2 + 0x38) = 1;
        return 0;
      }
      uVar5 = uVar5 + 1;
      prefetch(piVar3 + 2,0);
      piVar3 = piVar3 + 1;
    } while (uVar5 < 3);
  }
  return 0x500;
}



/* 409ccf88 FUN_409ccf88 */

/* Boundary evidence: original MIPS .pdata 409ccf88..409ccfe7. Semantic name remains unreviewed. */

void FUN_409ccf88(int param_1)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  
  FUN_409da688();
  piVar2 = (int *)(param_1 + 8);
  iVar3 = 8;
  do {
    iVar5 = 2;
    piVar4 = piVar2;
    do {
      iVar6 = *piVar4;
      *piVar4 = 0;
      piVar4[2] = 0;
      iVar1 = mali_sys_atomic_dec_and_return(iVar6 + 0x50);
      if (iVar1 == 0) {
        FUN_409c7b60(iVar6);
      }
      iVar5 = iVar5 + -1;
      piVar4 = piVar4 + 1;
    } while (iVar5 != 0);
    iVar3 = iVar3 + -1;
    piVar2 = piVar2 + 5;
  } while (iVar3 != 0);
                    /* WARNING: Subroutine does not return */
  FUN_409da6b0(0x10);
}



/* 409ccfe8 FUN_409ccfe8 */

/* Boundary evidence: original MIPS .pdata 409ccfe8..409cd0b3. Semantic name remains unreviewed. */

void FUN_409ccfe8(int param_1,int param_2,int *param_3)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  int iVar7;
  
  piVar2 = (int *)(param_1 + 8);
  iVar4 = 8;
  do {
    iVar5 = 2;
    piVar3 = piVar2;
    piVar6 = param_3;
    do {
      if (piVar3[2] == param_2) {
        iVar7 = *piVar3;
        *piVar3 = *piVar6;
        piVar3[2] = 0;
        mali_sys_atomic_inc(*piVar6 + 0x50);
        iVar1 = mali_sys_atomic_dec_and_return(iVar7 + 0x50);
        if (iVar1 == 0) {
          FUN_409c7b60(iVar7);
        }
      }
      piVar3 = piVar3 + 1;
      iVar5 = iVar5 + -1;
      piVar6 = piVar6 + 1;
    } while (iVar5 != 0);
    iVar4 = iVar4 + -1;
    piVar2 = piVar2 + 5;
  } while (iVar4 != 0);
  return;
}



/* 409cd374 FUN_409cd374 */

/* Boundary evidence: original MIPS .pdata 409cd374..409cd41b. Semantic name remains unreviewed. */

void FUN_409cd374(int param_1,int param_2,int param_3,int param_4)

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



/* 409cd41c FUN_409cd41c */

/* Boundary evidence: original MIPS .pdata 409cd41c..409cd4c7. Semantic name remains unreviewed. */

void FUN_409cd41c(int param_1,int param_2,int param_3,int param_4)

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



/* 409cd4c8 FUN_409cd4c8 */

void FUN_409cd4c8(int param_1,int param_2,int param_3,int param_4)

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



/* 409cd724 FUN_409cd724 */

/* Boundary evidence: original MIPS .pdata 409cd724..409cd793. Semantic name remains unreviewed. */

undefined4 FUN_409cd724(undefined4 param_1)

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



/* 409cd794 FUN_409cd794 */

/* Boundary evidence: original MIPS .pdata 409cd794..409cd7b7. Semantic name remains unreviewed. */

void FUN_409cd794(undefined4 param_1)

{
  undefined4 uVar1;
  
  uVar1 = __fpmul(param_1,0x47800000);
  __fptoli(uVar1);
  return;
}



/* 409cd7b8 FUN_409cd7b8 */

/* Boundary evidence: original MIPS .pdata 409cd7b8..409cd873. Semantic name remains unreviewed. */

undefined4 FUN_409cd7b8(int param_1,int param_2,int param_3,int param_4,int param_5)

{
  undefined4 uVar1;
  int iVar2;
  
  if (param_2 == 0xde1) {
    iVar2 = 0;
LAB_409cd7ec:
    iVar2 = *(int *)((*(int *)(param_1 + 0x31c) * 5 + iVar2 + 0xc9) * 4 + param_1);
    if (param_3 == 0x2800) {
      iVar2 = *(int *)(iVar2 + 0x10);
    }
    else if (param_3 == 0x2801) {
      iVar2 = *(int *)(iVar2 + 0xc);
    }
    else if (param_3 == 0x2802) {
      iVar2 = *(int *)(iVar2 + 4);
    }
    else {
      if (param_3 != 0x2803) goto LAB_409cd7d8;
      iVar2 = *(int *)(iVar2 + 8);
    }
    FUN_409cd374(param_4,0,iVar2,param_5);
    uVar1 = 0;
  }
  else {
    if (param_2 == 0x8513) {
      iVar2 = 1;
      goto LAB_409cd7ec;
    }
LAB_409cd7d8:
    uVar1 = 0x500;
  }
  return uVar1;
}



/* 409cd874 FUN_409cd874 */

/* Boundary evidence: original MIPS .pdata 409cd874..409cd97b. Semantic name remains unreviewed. */

void FUN_409cd874(int param_1,int param_2,undefined4 param_3,int param_4)

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
      uVar2 = FUN_409cd724(param_3);
      goto LAB_409cd944;
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
LAB_409cd944:
  *(undefined4 *)(param_2 * 4 + param_1) = uVar2;
  return;
}



/* 409cda08 FUN_409cda08 */

/* Boundary evidence: original MIPS .pdata 409cda08..409cdba7. Semantic name remains unreviewed. */

void FUN_409cda08(int param_1,uint param_2,int param_3,int param_4)

{
  byte bVar1;
  int iVar2;
  int in_stack_00000030;
  
  FUN_409da7c8();
  if (0xf < param_2) goto LAB_409cdba0;
  if (param_3 == 0x8622) {
    bVar1 = *(byte *)(param_2 * 0x30 + param_1);
LAB_409cdb8c:
    FUN_409cd4c8(in_stack_00000030,0,(uint)bVar1,param_4);
  }
  else {
    if (param_3 == 0x8623) {
      iVar2 = *(int *)(param_2 * 0x30 + param_1 + 4);
    }
    else if (param_3 == 0x8624) {
      iVar2 = *(int *)(param_2 * 0x30 + param_1 + 8);
    }
    else {
      if (param_3 == 0x8625) {
        FUN_409cd374(in_stack_00000030,0,*(int *)(param_2 * 0x30 + param_1 + 0xc),param_4);
        goto LAB_409cdba0;
      }
      if (param_3 == 0x8626) {
        iVar2 = param_2 * 0x30 + param_1;
        FUN_409cd874(in_stack_00000030,0,*(undefined4 *)(iVar2 + 0x20),param_4);
        FUN_409cd874(in_stack_00000030,1,*(undefined4 *)(iVar2 + 0x24),param_4);
        FUN_409cd874(in_stack_00000030,2,*(undefined4 *)(iVar2 + 0x28),param_4);
        FUN_409cd874(in_stack_00000030,3,*(undefined4 *)(iVar2 + 0x2c),param_4);
        goto LAB_409cdba0;
      }
      if (param_3 == 0x886a) {
        bVar1 = *(byte *)(param_2 * 0x30 + param_1 + 0x10);
        goto LAB_409cdb8c;
      }
      if (param_3 != 0x889f) goto LAB_409cdba0;
      iVar2 = *(int *)(param_2 * 0x30 + param_1 + 0x18);
    }
    FUN_409cd41c(in_stack_00000030,0,iVar2,param_4);
  }
LAB_409cdba0:
                    /* WARNING: Subroutine does not return */
  FUN_409da7e8(0x10);
}



/* 409cdcd8 FUN_409cdcd8 */

/* Boundary evidence: original MIPS .pdata 409cdcd8..409ce61f. Semantic name remains unreviewed. */

undefined4 FUN_409cdcd8(int param_1,uint param_2,int param_3,int param_4)

{
  byte bVar1;
  undefined4 uVar2;
  uint uVar3;
  int *piVar4;
  int iVar5;
  undefined4 *puVar6;
  
  piVar4 = *(int **)(param_1 + 0x4d8);
  iVar5 = (*(int *)(param_1 + 0x328) + 0x28) * 0x14 + param_1 + 0xc;
  if (0x80ca < param_2) {
    if (param_2 < 0x8895) {
      if (param_2 == 0x8894) {
        uVar3 = *(uint *)(param_1 + 0x314);
      }
      else if (param_2 < 0x86a3) {
        if (param_2 == 0x86a2) {
LAB_409ce594:
          uVar3 = 1;
        }
        else {
          if (param_2 < 0x84e1) {
            if (param_2 == 0x84e0) {
              iVar5 = *(int *)(param_1 + 0x328) + 0x84c0;
              goto LAB_409cddf4;
            }
            if (param_2 != 0x80cb) {
              if (param_2 == 0x8192) {
                iVar5 = *piVar4;
                goto LAB_409cddf4;
              }
              if ((param_2 != 0x846d) && (param_2 != 0x846e)) {
                return 0x500;
              }
              FUN_409cd874(param_3,0,0x3e800000,param_4);
              uVar2 = 0x42c80000;
              goto LAB_409cddd0;
            }
            uVar3 = (uint)*(byte *)(*(int *)(param_1 + 0x504) + 0x4a);
            goto LAB_409ce268;
          }
          if (param_2 == 0x84e8) {
LAB_409ce080:
            uVar3 = 0x1000;
          }
          else {
            if (param_2 != 0x8514) {
              if (param_2 != 0x851c) {
                return 0x500;
              }
              goto LAB_409ce394;
            }
            uVar3 = *(uint *)(iVar5 + 0x10);
          }
        }
      }
      else {
        if (param_2 < 0x8804) {
          if (param_2 == 0x8803) {
            uVar3 = (uint)*(byte *)(*(int *)(param_1 + 0x504) + 0x5c);
          }
          else {
            if (param_2 == 0x86a3) {
              iVar5 = 0x8d64;
              goto LAB_409cddf4;
            }
            if (param_2 == 0x8800) {
              uVar3 = (uint)*(byte *)(*(int *)(param_1 + 0x504) + 0x56);
              goto LAB_409cde78;
            }
            if (param_2 == 0x8801) {
              uVar3 = (uint)*(byte *)(*(int *)(param_1 + 0x504) + 0x5a);
            }
            else {
              if (param_2 != 0x8802) {
                return 0x500;
              }
              uVar3 = (uint)*(byte *)(*(int *)(param_1 + 0x504) + 0x5b);
            }
          }
LAB_409cdef0:
          iVar5 = FUN_409b72bc(uVar3);
          goto LAB_409cddf4;
        }
        if (param_2 == 0x883d) {
          bVar1 = *(byte *)(*(int *)(param_1 + 0x504) + 0x47);
LAB_409ce224:
          iVar5 = FUN_409b73ec((uint)bVar1);
          goto LAB_409cddf4;
        }
        if (param_2 == 0x8869) {
          uVar3 = 0x10;
        }
        else {
          if (param_2 != 0x8872) {
            return 0x500;
          }
LAB_409ce44c:
          uVar3 = 8;
        }
      }
    }
    else if (param_2 < 0x8ca5) {
      if (param_2 == 0x8ca4) {
        uVar3 = *(uint *)(*(int *)(param_1 + 0x504) + 0x88);
      }
      else if (param_2 < 0x8b8e) {
        if (param_2 == 0x8b8d) {
          uVar3 = piVar4[3];
        }
        else if (param_2 == 0x8895) {
          uVar3 = *(uint *)(param_1 + 0x318);
        }
        else {
          if (param_2 != 0x8b4c) {
            if (param_2 != 0x8b4d) {
              if (param_2 != 0x8b8b) {
                return 0x500;
              }
              iVar5 = piVar4[1];
              goto LAB_409cddf4;
            }
            goto LAB_409ce44c;
          }
          uVar3 = 0;
        }
      }
      else {
        if (param_2 == 0x8b9a) {
          iVar5 = 0x1401;
          goto LAB_409cddf4;
        }
        if (param_2 == 0x8b9b) {
          iVar5 = 0x1908;
          goto LAB_409cddf4;
        }
        if (param_2 != 0x8ca3) {
          return 0x500;
        }
        uVar3 = (uint)*(byte *)(*(int *)(param_1 + 0x504) + 0x57);
      }
    }
    else if (param_2 < 0x8dfb) {
      if (param_2 == 0x8dfa) {
        uVar3 = 1;
        goto LAB_409ce28c;
      }
      if (param_2 == 0x8ca6) {
        uVar3 = *(uint *)(param_1 + 0x488);
      }
      else {
        if (param_2 != 0x8ca7) {
          if (param_2 == 0x8df8) {
            iVar5 = 0x8f60;
            goto LAB_409cddf4;
          }
          if (param_2 != 0x8df9) {
            return 0x500;
          }
          goto LAB_409ce594;
        }
        uVar3 = *(uint *)(param_1 + 0x480);
      }
    }
    else if (param_2 == 0x8dfb) {
      uVar3 = 0x80;
    }
    else if (param_2 == 0x8dfc) {
      uVar3 = 0xc;
    }
    else {
      if (param_2 != 0x8dfd) {
        return 0x500;
      }
LAB_409ce394:
      uVar3 = 0x400;
    }
    goto LAB_409ce5f0;
  }
  if (param_2 != 0x80ca) {
    if (param_2 < 0xc23) {
      if (param_2 == 0xc22) {
        if (param_4 == 3) {
          param_4 = 2;
        }
        iVar5 = 0;
        puVar6 = (undefined4 *)(param_1 + 0x460);
        do {
          FUN_409cd874(param_3,iVar5,*puVar6,param_4);
          iVar5 = iVar5 + 1;
          puVar6 = puVar6 + 1;
        } while (iVar5 < 4);
        return 0;
      }
      if (param_2 < 0xb93) {
        if (param_2 != 0xb92) {
          if (param_2 < 0xb73) {
            if (param_2 == 0xb72) {
              uVar3 = (uint)*(byte *)(param_1 + 0x458);
              goto LAB_409ce28c;
            }
            if (param_2 != 0xb21) {
              if (param_2 == 0xb45) {
                iVar5 = *(int *)(param_1 + 0x3f0);
                goto LAB_409cddf4;
              }
              if (param_2 == 0xb46) {
                iVar5 = *(int *)(param_1 + 1000);
                goto LAB_409cddf4;
              }
              if (param_2 != 0xb70) {
                return 0x500;
              }
              if (param_4 == 3) {
                param_4 = 2;
              }
              FUN_409cd874(param_3,0,*(undefined4 *)(param_1 + 0x414),param_4);
              uVar2 = *(undefined4 *)(param_1 + 0x418);
LAB_409cddd0:
              iVar5 = 1;
              goto LAB_409cddd4;
            }
            uVar2 = *(undefined4 *)(param_1 + 0x400);
          }
          else {
            if (param_2 != 0xb73) {
              if (param_2 != 0xb74) {
                if (param_2 != 0xb91) {
                  return 0x500;
                }
                uVar3 = *(uint *)(param_1 + 0x474);
                goto LAB_409ce5f0;
              }
              uVar3 = (uint)*(byte *)(*(int *)(param_1 + 0x504) + 0x4d);
              goto LAB_409cde78;
            }
            if (param_4 == 3) {
              param_4 = 2;
            }
            uVar2 = *(undefined4 *)(param_1 + 0x470);
          }
LAB_409cde10:
          iVar5 = 0;
LAB_409cddd4:
          FUN_409cd874(param_3,iVar5,uVar2,param_4);
          return 0;
        }
        uVar3 = (uint)*(byte *)(*(int *)(param_1 + 0x504) + 0x4f);
LAB_409cde78:
        iVar5 = FUN_409b7474(uVar3);
        goto LAB_409cddf4;
      }
      if (param_2 < 0xb98) {
        if (param_2 == 0xb97) {
          uVar3 = (uint)*(byte *)(*(int *)(param_1 + 0x504) + 0x50);
        }
        else {
          if (param_2 != 0xb93) {
            if (param_2 == 0xb94) {
              uVar3 = (uint)*(byte *)(*(int *)(param_1 + 0x504) + 0x53);
            }
            else if (param_2 == 0xb95) {
              uVar3 = (uint)*(byte *)(*(int *)(param_1 + 0x504) + 0x54);
            }
            else {
              if (param_2 != 0xb96) {
                return 0x500;
              }
              uVar3 = (uint)*(byte *)(*(int *)(param_1 + 0x504) + 0x55);
            }
            goto LAB_409cdef0;
          }
          uVar3 = *(uint *)(*(int *)(param_1 + 0x504) + 0x84);
        }
      }
      else {
        if (param_2 != 0xb98) {
          if (param_2 == 0xba2) {
            FUN_409cd41c(param_3,0,*(int *)(param_1 + 0x404),param_4);
            FUN_409cd41c(param_3,1,*(int *)(param_1 + 0x408),param_4);
            FUN_409cd41c(param_3,2,*(int *)(param_1 + 0x40c),param_4);
            uVar3 = *(uint *)(param_1 + 0x410);
          }
          else {
            if (param_2 != 0xc10) {
              return 0x500;
            }
            FUN_409cd41c(param_3,0,*(int *)(param_1 + 0x3d4),param_4);
            FUN_409cd41c(param_3,1,*(int *)(param_1 + 0x3d8),param_4);
            FUN_409cd41c(param_3,2,*(int *)(param_1 + 0x3dc),param_4);
            uVar3 = *(uint *)(param_1 + 0x3e0);
          }
          iVar5 = 3;
          goto LAB_409ce5f4;
        }
        uVar3 = (uint)*(byte *)(*(int *)(param_1 + 0x504) + 0x52);
      }
    }
    else {
      if (0x8005 < param_2) {
        if (param_2 < 0x80ab) {
          if (param_2 == 0x80aa) {
            uVar2 = *(undefined4 *)(*(int *)(param_1 + 0x504) + 0x60);
          }
          else {
            if (param_2 == 0x8009) {
              bVar1 = *(byte *)(*(int *)(param_1 + 0x504) + 0x46);
              goto LAB_409ce224;
            }
            if (param_2 != 0x8038) {
              if (param_2 != 0x8069) {
                if ((param_2 != 0x80a8) && (1 < param_2 - 0x80a8)) {
                  return 0x500;
                }
                goto LAB_409ce1f8;
              }
              uVar3 = *(uint *)(iVar5 + 0xc);
              goto LAB_409ce5f0;
            }
            uVar2 = *(undefined4 *)(*(int *)(param_1 + 0x504) + 0x7c);
          }
          goto LAB_409cde10;
        }
        if (param_2 == 0x80ab) {
          uVar3 = (uint)*(byte *)(*(int *)(param_1 + 0x504) + 100);
LAB_409ce28c:
          FUN_409cd4c8(param_3,0,uVar3,param_4);
          return 0;
        }
        if (param_2 == 0x80c8) {
          uVar3 = (uint)*(byte *)(*(int *)(param_1 + 0x504) + 0x49);
        }
        else {
          if (param_2 != 0x80c9) {
            return 0x500;
          }
          uVar3 = (uint)*(byte *)(*(int *)(param_1 + 0x504) + 0x48);
        }
        goto LAB_409ce268;
      }
      if (param_2 == 0x8005) {
        if (param_4 == 3) {
          param_4 = 2;
        }
        FUN_409cd874(param_3,0,*(undefined4 *)(*(int *)(param_1 + 0x504) + 0x68),param_4);
        FUN_409cd874(param_3,1,*(undefined4 *)(*(int *)(param_1 + 0x504) + 0x6c),param_4);
        FUN_409cd874(param_3,2,*(undefined4 *)(*(int *)(param_1 + 0x504) + 0x70),param_4);
        uVar2 = *(undefined4 *)(*(int *)(param_1 + 0x504) + 0x74);
        iVar5 = 3;
        goto LAB_409cddd4;
      }
      if (param_2 < 0xd3b) {
        if (param_2 == 0xd3a) {
          FUN_409cd41c(param_3,0,0x1000,param_4);
          uVar3 = 0x1000;
          iVar5 = 1;
          goto LAB_409ce5f4;
        }
        if (param_2 == 0xc23) {
          iVar5 = 0;
          do {
            FUN_409cd4c8(param_3,iVar5,(uint)*(byte *)(param_1 + 0x454 + iVar5),param_4);
            iVar5 = iVar5 + 1;
          } while (iVar5 < 4);
          return 0;
        }
        if (param_2 == 0xcf5) {
          uVar3 = *(uint *)(param_1 + 0x3d0);
        }
        else {
          if (param_2 != 0xd05) {
            if (param_2 != 0xd33) {
              return 0x500;
            }
            goto LAB_409ce080;
          }
          uVar3 = *(uint *)(param_1 + 0x3cc);
        }
      }
      else if (param_2 == 0xd50) {
        uVar3 = 4;
      }
      else {
        if (param_2 < 0xd52) {
          return 0x500;
        }
        if (0xd57 < param_2) {
          if (param_2 != 0x2a00) {
            return 0x500;
          }
          uVar2 = *(undefined4 *)(*(int *)(param_1 + 0x504) + 0x80);
          goto LAB_409cde10;
        }
LAB_409ce1f8:
        uVar3 = FUN_409bff74((int *)(param_1 + 0x484),param_2);
      }
    }
LAB_409ce5f0:
    iVar5 = 0;
LAB_409ce5f4:
    FUN_409cd41c(param_3,iVar5,uVar3,param_4);
    return 0;
  }
  uVar3 = (uint)*(byte *)(*(int *)(param_1 + 0x504) + 0x4b);
LAB_409ce268:
  iVar5 = FUN_409b7094(uVar3);
LAB_409cddf4:
  FUN_409cd374(param_3,0,iVar5,param_4);
  return 0;
}



/* 409ce644 FUN_409ce644 */

/* Boundary evidence: original MIPS .pdata 409ce644..409ce693. Semantic name remains unreviewed. */

undefined4 FUN_409ce644(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = __les(param_2,0);
  if (iVar1 == 0) {
    *(undefined4 *)(param_1 + 0x400) = param_2;
    uVar2 = 0;
  }
  else {
    uVar2 = 0x501;
  }
  return uVar2;
}



/* 409ce7fc FUN_409ce7fc */

/* Boundary evidence: original MIPS .pdata 409ce7fc..409ce883. Semantic name remains unreviewed. */

void FUN_409ce7fc(int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  
  FUN_409da7c8();
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
  FUN_409da7e8(0x10);
}



/* 409ce884 FUN_409ce884 */

/* Boundary evidence: original MIPS .pdata 409ce884..409ce983. Semantic name remains unreviewed. */

void FUN_409ce884(int param_1,undefined4 param_2,undefined4 param_3)

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
  FUN_409ce7fc(param_1,*(undefined4 *)(param_1 + 0x41c),*(undefined4 *)(param_1 + 0x420));
  uVar2 = *(uint *)(param_1 + 0xc);
  *(uint *)(param_1 + 0xc) = uVar2 | 0x40000;
  *(uint *)(param_1 + 0xc) = uVar2 | 0x840000;
  return;
}



/* 409ce984 FUN_409ce984 */

/* Boundary evidence: original MIPS .pdata 409ce984..409ce9d3. Semantic name remains unreviewed. */

void FUN_409ce984(int param_1)

{
  uint uVar1;
  
  *(undefined4 *)(param_1 + 0x404) = 0;
  *(undefined4 *)(param_1 + 0x408) = 0;
  *(undefined4 *)(param_1 + 0x40c) = 0;
  *(undefined4 *)(param_1 + 0x410) = 0;
  uVar1 = *(uint *)(param_1 + 0xc);
  *(uint *)(param_1 + 0xc) = uVar1 | 0x40000;
  *(uint *)(param_1 + 0xc) = uVar1 | 0xc0000;
  FUN_409ce884(param_1,0,0x3f800000);
  return;
}



/* 409ceb44 FUN_409ceb44 */

/* Boundary evidence: original MIPS .pdata 409ceb44..409cebe3. Semantic name remains unreviewed. */

undefined4
FUN_409ceb44(int param_1,uint param_2,int param_3,uint param_4,undefined4 param_5,int param_6)

{
  undefined4 uVar1;
  
  if ((((param_2 < 0x10) && (param_3 < 5)) && (0 < param_3)) && (-1 < param_6)) {
    if ((param_4 < 0x1400) || (((0x1403 < param_4 && (param_4 != 0x1406)) && (param_4 != 0x140c))))
    {
      uVar1 = 0x500;
    }
    else {
      FUN_409c1070(param_1,param_2,param_3,param_4);
      uVar1 = 0;
    }
  }
  else {
    uVar1 = 0x501;
  }
  return uVar1;
}



/* 409cebe4 FUN_409cebe4 */

void FUN_409cebe4(int param_1)

{
  undefined4 *puVar1;
  undefined1 *puVar2;
  int iVar3;
  
  puVar2 = (undefined1 *)(param_1 + 0x10);
  iVar3 = 0x10;
  do {
    *(undefined4 *)(puVar2 + -0xc) = 4;
    puVar1 = (undefined4 *)(puVar2 + 0x10);
    *(undefined4 *)(puVar2 + -4) = 0x1406;
    *(undefined4 *)(puVar2 + -8) = 0;
    *(undefined4 *)(puVar2 + 4) = 0;
    puVar2[-0x10] = 0;
    *puVar2 = 0;
    *(undefined4 *)(puVar2 + 8) = 0;
    *(undefined4 *)(puVar2 + 0xc) = 0;
    do {
      *puVar1 = 0;
      puVar1 = puVar1 + 1;
    } while (puVar1 != (undefined4 *)(puVar2 + 0x1c));
    iVar3 = iVar3 + -1;
    *(undefined4 *)(puVar2 + 0x1c) = 0x3f800000;
    puVar2 = puVar2 + 0x30;
  } while (iVar3 != 0);
  *(undefined4 *)(param_1 + 0x300) = 0;
  *(undefined4 *)(param_1 + 0x304) = 0;
  *(undefined4 *)(param_1 + 0x308) = 0;
  *(undefined4 *)(param_1 + 0x30c) = 0;
  return;
}



/* 409cec60 FUN_409cec60 */

/* Boundary evidence: original MIPS .pdata 409cec60..409cec7b. Semantic name remains unreviewed. */

void FUN_409cec60(int param_1)

{
  FUN_409c112c(param_1 + 0x14);
  return;
}



/* 409cec7c FUN_409cec7c */

/* Boundary evidence: original MIPS .pdata 409cec7c..409cedbf. Semantic name remains unreviewed. */

void FUN_409cec7c(int param_1)

{
  uint uVar1;
  undefined4 *puVar2;
  uint *puVar3;
  
  puVar3 = (uint *)(param_1 + 0xc);
  *puVar3 = 0;
  FUN_409cc8a8((undefined4 *)(param_1 + 0x328),(int *)(param_1 + 0x4dc));
  *(undefined4 *)(param_1 + 0x10) = 0;
  FUN_409cebe4(param_1 + 0x14);
  FUN_409ce984(param_1);
  *(undefined4 *)(param_1 + 0x3f0) = 0x405;
  *(undefined1 *)(param_1 + 0x3ec) = 0;
  *(undefined4 *)(param_1 + 1000) = 0x901;
  *(undefined4 *)(param_1 + 0x3f4) = 0x3f800000;
  *(undefined4 *)(param_1 + 0x3f8) = 0x3e800000;
  *(undefined4 *)(param_1 + 0x3fc) = 0x42c80000;
  *(undefined4 *)(param_1 + 0x400) = 0x3f800000;
  FUN_409c06f0(param_1);
  *(undefined4 *)(*(int *)(param_1 + 0x4d8) + 8) = 0;
  puVar2 = *(undefined4 **)(param_1 + 0x4d8);
  *puVar2 = 0x1100;
  puVar2[1] = 0x1100;
  *(undefined4 *)(param_1 + 0x3d4) = 0;
  *(undefined4 *)(param_1 + 0x3d8) = 0;
  *(undefined4 *)(param_1 + 0x3dc) = 0;
  *(undefined4 *)(param_1 + 0x3e0) = 0;
  *(undefined4 *)(param_1 + 0x3e4) = 0x80000000;
  uVar1 = *puVar3;
  *puVar3 = uVar1 & 0xfffeffff;
  *puVar3 = uVar1 & 0xfffeffff | 0x20000;
  *(undefined4 *)(*(int *)(param_1 + 0x4d8) + 0xc) = 0;
  *(undefined4 *)(param_1 + 0x3cc) = 4;
  *(undefined4 *)(param_1 + 0x3d0) = 4;
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
  *(undefined4 *)(param_1 + 0x47c) = 0;
  *(undefined4 *)(param_1 + 0x480) = 0;
  *(undefined4 *)(param_1 + 0x4d4) = 0;
  return;
}



/* 409cee74 FUN_409cee74 */

/* Boundary evidence: original MIPS .pdata 409cee74..409cef8b. Semantic name remains unreviewed. */

undefined4 FUN_409cee74(int param_1)

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
    goto LAB_409cef48;
  }
  if (iVar3 != -0x48) {
    if (*(int *)(iVar3 + 0x50) == 0x1702) {
      iVar1 = FUN_409c682c(*(int *)(iVar3 + 100));
      piVar4 = *(int **)((iVar1 * 0xd + *(int *)(iVar3 + 0x60)) * 4 +
                        *(int *)(*(int *)(iVar3 + 0x58) + 0x34));
      if (piVar4 != (int *)0x0) {
        iVar3 = *piVar4;
        goto LAB_409cef00;
      }
    }
    else if (*(int *)(iVar3 + 0x50) == 0x8d41) {
      iVar3 = *(int *)(*(int *)(iVar3 + 0x58) + 0x28);
LAB_409cef00:
      if (iVar3 != 0) {
        mali_pixel_format_get_bpc
                  (*(undefined4 *)(iVar3 + 0x14),auStack_14,auStack_18,auStack_1c,auStack_20,
                   auStack_24,&local_28);
        goto LAB_409cef48;
      }
    }
  }
  local_28 = 0;
LAB_409cef48:
  uVar2 = 1;
  if (((*(uint *)(*(int *)(param_1 + 0x504) + 0x40) & 0x10) == 0) || (local_28 < 1)) {
    uVar2 = 0;
  }
  return uVar2;
}



/* 409cef8c FUN_409cef8c */

void FUN_409cef8c(int param_1,uint param_2,int param_3)

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



/* 409cf018 FUN_409cf018 */

/* Boundary evidence: original MIPS .pdata 409cf018..409cf0f7. Semantic name remains unreviewed. */

undefined4 FUN_409cf018(int param_1,int param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = 0;
  while (param_2 != *(int *)((int)&DAT_409b17c8 + uVar2)) {
    uVar2 = uVar2 + 4;
    if (0xb < uVar2) {
      return 0x500;
    }
  }
  uVar2 = 0;
  do {
    if (param_3 == *(int *)((int)&DAT_409b17c8 + uVar2)) {
      iVar1 = 1;
      if (param_2 == 0x8006) {
        uVar2 = 2;
      }
      else if ((param_2 == 0x800a) || (param_2 != 0x800b)) {
        uVar2 = 0;
      }
      else {
        uVar2 = 1;
      }
      if (param_3 == 0x8006) {
        iVar1 = 2;
      }
      else if ((param_3 == 0x800a) || (param_3 != 0x800b)) {
        iVar1 = 0;
      }
      FUN_409cef8c(param_1,uVar2,iVar1);
      return 0;
    }
    uVar2 = uVar2 + 4;
  } while (uVar2 < 0xc);
  return 0x500;
}



/* 409cf0f8 FUN_409cf0f8 */

/* Boundary evidence: original MIPS .pdata 409cf0f8..409cf19f. Semantic name remains unreviewed. */

void FUN_409cf0f8(int param_1,uint param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0x504);
  *(char *)(iVar2 + 0x5a) = (char)param_2;
  *(char *)(iVar2 + 0x5b) = (char)param_3;
  *(char *)(iVar2 + 0x5c) = (char)param_4;
  iVar1 = FUN_409cee74(param_1);
  if (iVar1 == 0) {
    param_3 = 0;
    param_4 = 0;
  }
  *(uint *)(iVar2 + 0x18) =
       ((param_2 & 0xffffffc7 ^ param_3 << 3) << 3 ^ *(uint *)(iVar2 + 0x18) & 0xfffffe07) &
       0xfffff1ff ^ param_4 << 9;
  return;
}



/* 409cf1a0 FUN_409cf1a0 */

/* Boundary evidence: original MIPS .pdata 409cf1a0..409cf247. Semantic name remains unreviewed. */

void FUN_409cf1a0(int param_1,uint param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0x504);
  *(char *)(iVar2 + 0x53) = (char)param_2;
  *(char *)(iVar2 + 0x54) = (char)param_3;
  *(char *)(iVar2 + 0x55) = (char)param_4;
  iVar1 = FUN_409cee74(param_1);
  if (iVar1 == 0) {
    param_3 = 0;
    param_4 = 0;
  }
  *(uint *)(iVar2 + 0x14) =
       ((param_2 & 0xffffffc7 ^ param_3 << 3) << 3 ^ *(uint *)(iVar2 + 0x14) & 0xfffffe07) &
       0xfffff1ff ^ param_4 << 9;
  return;
}



/* 409cf248 FUN_409cf248 */

/* Boundary evidence: original MIPS .pdata 409cf248..409cf41b. Semantic name remains unreviewed. */

void FUN_409cf248(int param_1,uint param_2,int param_3,uint param_4,byte param_5)

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
  FUN_409cef8c(param_1,(uint)*(byte *)(iVar3 + 0x46),(uint)*(byte *)(iVar3 + 0x47));
  if (*(int *)(param_1 + 0x484) == 0) {
    iVar1 = *(int *)(param_1 + 0x4a0);
  }
  else {
    iVar1 = FUN_409bc7c4(*(int *)(param_1 + 0x484),0xd55);
  }
  if (iVar1 != 0) goto LAB_409cf398;
  if (param_2 == 4) {
LAB_409cf314:
    param_2 = 3;
  }
  else if (param_2 == 0x11) {
    param_2 = 0xb;
  }
  else if (param_2 == 0x19) goto LAB_409cf314;
  if (param_3 == 4) {
LAB_409cf334:
    param_3 = 3;
  }
  else if (param_3 == 0x11) {
    param_3 = 0xb;
  }
  else if (param_3 == 0x19) goto LAB_409cf334;
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
LAB_409cf398:
  if (param_4 == 4) {
    param_4 = 0xb;
  }
  *(uint *)(iVar3 + 8) =
       ((param_2 & 0xffffc01f ^ param_3 << 5) << 6 ^ *(uint *)(iVar3 + 8) & 0xfff0003f) & 0xff0fffff
       ^ ((uVar2 & 0xf) << 4 ^ param_4 & 0xf) << 0x10;
  return;
}



/* 409cf41c FUN_409cf41c */

/* Boundary evidence: original MIPS .pdata 409cf41c..409cf5a3. Semantic name remains unreviewed. */

void FUN_409cf41c(int param_1,uint param_2,uint param_3,uint param_4)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint *puVar7;
  uint in_stack_00000040;
  
  FUN_409da808();
  puVar7 = *(uint **)(param_1 + 0x504);
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
  puVar7[0x1a] = param_2;
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
  puVar7[0x1b] = param_3;
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
  puVar7[0x1c] = param_4;
  iVar1 = __lts(in_stack_00000040,0);
  if (iVar1 == 0) {
    iVar1 = __gts(in_stack_00000040,0x3f800000);
    uVar6 = 0x3f800000;
    if (iVar1 == 0) {
      uVar6 = in_stack_00000040;
    }
  }
  else {
    uVar6 = 0;
  }
  puVar7[0x1d] = uVar6;
  uVar2 = __fpmul(param_2,0x437f0000);
  uVar3 = __fptoul(uVar2);
  uVar2 = __fpmul(param_3,0x437f0000);
  uVar4 = __fptoul(uVar2);
  uVar2 = __fpmul(param_4,0x437f0000);
  uVar5 = __fptoul(uVar2);
  uVar2 = __fpmul(uVar6,0x437f0000);
  uVar6 = __fptoul(uVar2);
  *puVar7 = (uVar4 & 0xff) << 0x10 ^ uVar5 & 0xff;
  puVar7[1] = (uVar6 & 0xff) << 0x10 ^ uVar3 & 0xff;
                    /* WARNING: Subroutine does not return */
  FUN_409da838(0x10);
}



/* 409cf5a4 FUN_409cf5a4 */

/* Boundary evidence: original MIPS .pdata 409cf5a4..409cf5c7. Semantic name remains unreviewed. */

undefined4 FUN_409cf5a4(int param_1,uint param_2,uint param_3,uint param_4)

{
  FUN_409cf41c(param_1,param_2,param_3,param_4);
  return 0;
}



/* 409cf5c8 FUN_409cf5c8 */

/* Boundary evidence: original MIPS .pdata 409cf5c8..409cf727. Semantic name remains unreviewed. */

undefined4 FUN_409cf5c8(int param_1,uint param_2,uint param_3,uint param_4,uint param_5)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  
  uVar4 = 0;
  do {
    if (param_2 == *(uint *)((int)&DAT_409b1754 + uVar4)) {
      uVar4 = 0;
      do {
        if (param_3 == *(uint *)((int)&DAT_409b1790 + uVar4)) {
          uVar4 = 0;
          do {
            if (param_4 == *(uint *)((int)&DAT_409b1754 + uVar4)) {
              uVar4 = 0;
              do {
                if (param_5 == *(uint *)((int)&DAT_409b1790 + uVar4)) {
                  uVar1 = FUN_409b7184(param_5);
                  uVar4 = FUN_409b7184(param_4);
                  iVar2 = FUN_409b7184(param_3);
                  uVar3 = FUN_409b7184(param_2);
                  FUN_409cf248(param_1,uVar3,iVar2,uVar4,(byte)uVar1);
                  return 0;
                }
                uVar4 = uVar4 + 4;
              } while (uVar4 < 0x38);
              return 0x500;
            }
            uVar4 = uVar4 + 4;
          } while (uVar4 < 0x3c);
          return 0x500;
        }
        uVar4 = uVar4 + 4;
      } while (uVar4 < 0x38);
      return 0x500;
    }
    uVar4 = uVar4 + 4;
  } while (uVar4 < 0x3c);
  return 0x500;
}



/* 409cf728 FUN_409cf728 */

/* Boundary evidence: original MIPS .pdata 409cf728..409cf8af. Semantic name remains unreviewed. */

undefined4 FUN_409cf728(int param_1,int param_2,uint param_3,uint param_4,uint param_5)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  uVar3 = 0;
  do {
    if (param_3 == *(uint *)((int)&DAT_409b1728 + uVar3)) {
      uVar3 = 0;
      do {
        if (param_4 == *(uint *)((int)&DAT_409b1728 + uVar3)) {
          uVar3 = 0;
          do {
            if (param_5 == *(uint *)((int)&DAT_409b1728 + uVar3)) {
              uVar3 = 0;
              do {
                if (param_2 == *(int *)((int)&DAT_409b1748 + uVar3)) {
                  uVar3 = FUN_409b7340(param_3);
                  iVar1 = FUN_409b7340(param_4);
                  iVar2 = FUN_409b7340(param_5);
                  if ((param_2 == 0x404) || (param_2 == 0x408)) {
                    FUN_409cf1a0(param_1,uVar3,iVar1,iVar2);
                  }
                  if ((param_2 == 0x405) || (param_2 == 0x408)) {
                    FUN_409cf0f8(param_1,uVar3,iVar1,iVar2);
                  }
                  return 0;
                }
                uVar3 = uVar3 + 4;
              } while (uVar3 < 0xc);
              return 0x500;
            }
            uVar3 = uVar3 + 4;
          } while (uVar3 < 0x20);
          return 0x500;
        }
        uVar3 = uVar3 + 4;
      } while (uVar3 < 0x20);
      return 0x500;
    }
    uVar3 = uVar3 + 4;
  } while (uVar3 < 0x20);
  return 0x500;
}



/* 409cfa50 FUN_409cfa50 */

/* Boundary evidence: original MIPS .pdata 409cfa50..409cfaef. Semantic name remains unreviewed. */

undefined1 FUN_409cfa50(undefined4 param_1)

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



/* 409cfb58 FUN_409cfb58 */

/* Boundary evidence: original MIPS .pdata 409cfb58..409cfc6f. Semantic name remains unreviewed. */

undefined4 FUN_409cfb58(int param_1)

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
    goto LAB_409cfc2c;
  }
  if (iVar3 != -0x48) {
    if (*(int *)(iVar3 + 0x50) == 0x1702) {
      iVar1 = FUN_409c682c(*(int *)(iVar3 + 100));
      piVar4 = *(int **)((iVar1 * 0xd + *(int *)(iVar3 + 0x60)) * 4 +
                        *(int *)(*(int *)(iVar3 + 0x58) + 0x34));
      if (piVar4 != (int *)0x0) {
        iVar3 = *piVar4;
        goto LAB_409cfbe4;
      }
    }
    else if (*(int *)(iVar3 + 0x50) == 0x8d41) {
      iVar3 = *(int *)(*(int *)(iVar3 + 0x58) + 0x28);
LAB_409cfbe4:
      if (iVar3 != 0) {
        mali_pixel_format_get_bpc
                  (*(undefined4 *)(iVar3 + 0x14),auStack_14,auStack_18,auStack_1c,auStack_20,
                   auStack_24,&local_28);
        goto LAB_409cfc2c;
      }
    }
  }
  local_28 = 0;
LAB_409cfc2c:
  uVar2 = 1;
  if (((*(uint *)(*(int *)(param_1 + 0x504) + 0x40) & 0x10) == 0) || (local_28 < 1)) {
    uVar2 = 0;
  }
  return uVar2;
}



/* 409cfc70 FUN_409cfc70 */

/* Boundary evidence: original MIPS .pdata 409cfc70..409cfd87. Semantic name remains unreviewed. */

undefined4 FUN_409cfc70(int param_1)

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
    goto LAB_409cfd44;
  }
  if (iVar3 != -0x24) {
    if (*(int *)(iVar3 + 0x2c) == 0x1702) {
      iVar1 = FUN_409c682c(*(int *)(iVar3 + 0x40));
      piVar4 = *(int **)((iVar1 * 0xd + *(int *)(iVar3 + 0x3c)) * 4 +
                        *(int *)(*(int *)(iVar3 + 0x34) + 0x34));
      if (piVar4 != (int *)0x0) {
        iVar3 = *piVar4;
        goto LAB_409cfcfc;
      }
    }
    else if (*(int *)(iVar3 + 0x2c) == 0x8d41) {
      iVar3 = *(int *)(*(int *)(iVar3 + 0x34) + 0x28);
LAB_409cfcfc:
      if (iVar3 != 0) {
        mali_pixel_format_get_bpc
                  (*(undefined4 *)(iVar3 + 0x14),auStack_14,auStack_18,auStack_1c,auStack_20,
                   &local_28,auStack_24);
        goto LAB_409cfd44;
      }
    }
  }
  local_28 = 0;
LAB_409cfd44:
  uVar2 = 1;
  if (((*(uint *)(*(int *)(param_1 + 0x504) + 0x40) & 2) == 0) || (local_28 < 1)) {
    uVar2 = 0;
  }
  return uVar2;
}



/* 409cfd88 FUN_409cfd88 */

/* Boundary evidence: original MIPS .pdata 409cfd88..409cfdbf. Semantic name remains unreviewed. */

void FUN_409cfd88(int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined1 uVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0x504);
  *(undefined4 *)(iVar2 + 0x7c) = param_2;
  *(undefined4 *)(iVar2 + 0x80) = param_3;
  uVar1 = FUN_409cfa50(param_2);
  *(undefined1 *)(iVar2 + 0x65) = uVar1;
  *(undefined1 *)(iVar2 + 0x66) = 0;
  return;
}



/* 409cfdc0 FUN_409cfdc0 */

void FUN_409cfdc0(int param_1,uint param_2,int param_3)

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



/* 409cfe60 FUN_409cfe60 */

void FUN_409cfe60(int param_1,int param_2)

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
    if (((*(uint *)(*(int *)(param_1 + 0x504) + 0x40) & 0x20) != 0) && (bVar1)) goto LAB_409cfec0;
  }
  iVar2 = 0;
LAB_409cfec0:
  *(uint *)(iVar3 + 0x20) = *(uint *)(iVar3 + 0x20) & 0xffffff7f ^ iVar2 << 7;
  return;
}



/* 409cfee0 FUN_409cfee0 */

/* Boundary evidence: original MIPS .pdata 409cfee0..409d0003. Semantic name remains unreviewed. */

void FUN_409cfee0(int param_1,undefined4 param_2,int param_3)

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



/* 409d0004 FUN_409d0004 */

/* Boundary evidence: original MIPS .pdata 409d0004..409d005f. Semantic name remains unreviewed. */

void FUN_409d0004(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0x504);
  *(char *)(iVar2 + 0x59) = (char)param_2;
  iVar1 = FUN_409cfb58(param_1);
  if (iVar1 == 0) {
    param_2 = 0;
  }
  *(uint *)(iVar2 + 0x1c) = param_2 << 8 ^ *(uint *)(iVar2 + 0x1c) & 0xffff00ff;
  return;
}



/* 409d0060 FUN_409d0060 */

/* Boundary evidence: original MIPS .pdata 409d0060..409d00b7. Semantic name remains unreviewed. */

void FUN_409d0060(int param_1,uint param_2)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0x504);
  *(char *)(iVar2 + 0x52) = (char)param_2;
  iVar1 = FUN_409cfb58(param_1);
  if (iVar1 == 0) {
    param_2 = 0;
  }
  *(uint *)(iVar2 + 0x1c) = *(uint *)(iVar2 + 0x1c) & 0xffffff00 ^ param_2;
  return;
}



/* 409d00b8 FUN_409d00b8 */

/* Boundary evidence: original MIPS .pdata 409d00b8..409d015f. Semantic name remains unreviewed. */

void FUN_409d00b8(int param_1,uint param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0x504);
  *(char *)(iVar2 + 0x5a) = (char)param_2;
  *(char *)(iVar2 + 0x5b) = (char)param_3;
  *(char *)(iVar2 + 0x5c) = (char)param_4;
  iVar1 = FUN_409cfb58(param_1);
  if (iVar1 == 0) {
    param_3 = 0;
    param_4 = 0;
  }
  *(uint *)(iVar2 + 0x18) =
       ((param_2 & 0xffffffc7 ^ param_3 << 3) << 3 ^ *(uint *)(iVar2 + 0x18) & 0xfffffe07) &
       0xfffff1ff ^ param_4 << 9;
  return;
}



/* 409d0160 FUN_409d0160 */

/* Boundary evidence: original MIPS .pdata 409d0160..409d0207. Semantic name remains unreviewed. */

void FUN_409d0160(int param_1,uint param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0x504);
  *(char *)(iVar2 + 0x53) = (char)param_2;
  *(char *)(iVar2 + 0x54) = (char)param_3;
  *(char *)(iVar2 + 0x55) = (char)param_4;
  iVar1 = FUN_409cfb58(param_1);
  if (iVar1 == 0) {
    param_3 = 0;
    param_4 = 0;
  }
  *(uint *)(iVar2 + 0x14) =
       ((param_2 & 0xffffffc7 ^ param_3 << 3) << 3 ^ *(uint *)(iVar2 + 0x14) & 0xfffffe07) &
       0xfffff1ff ^ param_4 << 9;
  return;
}



/* 409d0208 FUN_409d0208 */

/* Boundary evidence: original MIPS .pdata 409d0208..409d02bb. Semantic name remains unreviewed. */

void FUN_409d0208(int param_1,uint param_2,uint param_3,uint param_4)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  
  iVar3 = *(int *)(param_1 + 0x504);
  *(uint *)(iVar3 + 0x88) = param_4;
  *(char *)(iVar3 + 0x56) = (char)param_2;
  *(char *)(iVar3 + 0x57) = (char)param_3;
  *(char *)(iVar3 + 0x58) = (char)param_4;
  iVar1 = FUN_409cfb58(param_1);
  if (iVar1 == 0) {
    param_2 = 7;
  }
  uVar2 = (*(uint *)(iVar3 + 0x18) & 0xfffffff8 ^ param_2) & 0xff00ffff ^
          (param_3 & param_4) << 0x10;
  *(uint *)(iVar3 + 0x18) = uVar2;
  *(uint *)(iVar3 + 0x18) = uVar2 & 0xffffff ^ (uint)*(byte *)(iVar3 + 0x51) << 0x18;
  return;
}



/* 409d02bc FUN_409d02bc */

/* Boundary evidence: original MIPS .pdata 409d02bc..409d036f. Semantic name remains unreviewed. */

void FUN_409d02bc(int param_1,uint param_2,uint param_3,uint param_4)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  
  iVar3 = *(int *)(param_1 + 0x504);
  *(uint *)(iVar3 + 0x84) = param_4;
  *(char *)(iVar3 + 0x4f) = (char)param_2;
  *(char *)(iVar3 + 0x50) = (char)param_3;
  *(char *)(iVar3 + 0x51) = (char)param_4;
  iVar1 = FUN_409cfb58(param_1);
  if (iVar1 == 0) {
    param_2 = 7;
  }
  uVar2 = (*(uint *)(iVar3 + 0x14) & 0xfffffff8 ^ param_2) & 0xff00ffff ^
          (param_3 & param_4) << 0x10;
  *(uint *)(iVar3 + 0x14) = uVar2;
  *(uint *)(iVar3 + 0x14) = uVar2 & 0xffffff ^ (uint)*(byte *)(iVar3 + 0x51) << 0x18;
  return;
}



/* 409d0370 FUN_409d0370 */

/* Boundary evidence: original MIPS .pdata 409d0370..409d03cb. Semantic name remains unreviewed. */

void FUN_409d0370(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0x504);
  *(char *)(iVar2 + 0x4d) = (char)param_2;
  iVar1 = FUN_409cfc70(param_1);
  if (iVar1 == 0) {
    param_2 = 7;
  }
  *(uint *)(iVar2 + 0xc) = param_2 << 1 ^ *(uint *)(iVar2 + 0xc) & 0xfffffff1;
  return;
}



/* 409d03cc FUN_409d03cc */

/* Boundary evidence: original MIPS .pdata 409d03cc..409d041b. Semantic name remains unreviewed. */

void FUN_409d03cc(int param_1,uint param_2)

{
  uint uVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0x504);
  *(char *)(iVar2 + 0x4e) = (char)param_2;
  uVar1 = FUN_409cfc70(param_1);
  *(uint *)(iVar2 + 0xc) = *(uint *)(iVar2 + 0xc) & 0xfffffffe ^ uVar1 & param_2;
  return;
}



/* 409d041c FUN_409d041c */

/* Boundary evidence: original MIPS .pdata 409d041c..409d047f. Semantic name remains unreviewed. */

void FUN_409d041c(int param_1,int param_2)

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
  uVar1 = FUN_409cfa50(uVar2);
  *(undefined1 *)(iVar3 + 0x65) = uVar1;
  *(undefined1 *)(iVar3 + 0x66) = 0;
  return;
}



/* 409d0480 FUN_409d0480 */

/* Boundary evidence: original MIPS .pdata 409d0480..409d0653. Semantic name remains unreviewed. */

void FUN_409d0480(int param_1,uint param_2,int param_3,uint param_4,byte param_5)

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
  FUN_409cfdc0(param_1,(uint)*(byte *)(iVar3 + 0x46),(uint)*(byte *)(iVar3 + 0x47));
  if (*(int *)(param_1 + 0x484) == 0) {
    iVar1 = *(int *)(param_1 + 0x4a0);
  }
  else {
    iVar1 = FUN_409bc7c4(*(int *)(param_1 + 0x484),0xd55);
  }
  if (iVar1 != 0) goto LAB_409d05d0;
  if (param_2 == 4) {
LAB_409d054c:
    param_2 = 3;
  }
  else if (param_2 == 0x11) {
    param_2 = 0xb;
  }
  else if (param_2 == 0x19) goto LAB_409d054c;
  if (param_3 == 4) {
LAB_409d056c:
    param_3 = 3;
  }
  else if (param_3 == 0x11) {
    param_3 = 0xb;
  }
  else if (param_3 == 0x19) goto LAB_409d056c;
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
LAB_409d05d0:
  if (param_4 == 4) {
    param_4 = 0xb;
  }
  *(uint *)(iVar3 + 8) =
       ((param_2 & 0xffffc01f ^ param_3 << 5) << 6 ^ *(uint *)(iVar3 + 8) & 0xfff0003f) & 0xff0fffff
       ^ ((uVar2 & 0xf) << 4 ^ param_4 & 0xf) << 0x10;
  return;
}



/* 409d0654 FUN_409d0654 */

/* Boundary evidence: original MIPS .pdata 409d0654..409d0697. Semantic name remains unreviewed. */

void FUN_409d0654(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x504);
  *(uint *)(iVar1 + 0x40) = *(uint *)(iVar1 + 0x40) & 0xffffffbf | param_2 << 6;
  FUN_409cfee0(param_1,*(undefined4 *)(iVar1 + 0x60),(uint)*(byte *)(iVar1 + 100));
  return;
}



/* 409d0698 FUN_409d0698 */

/* Boundary evidence: original MIPS .pdata 409d0698..409d074f. Semantic name remains unreviewed. */

void FUN_409d0698(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x504);
  *(uint *)(iVar1 + 0x40) = *(uint *)(iVar1 + 0x40) & 0xffffffef | param_2 << 4;
  FUN_409d02bc(param_1,(uint)*(byte *)(iVar1 + 0x4f),(uint)*(byte *)(iVar1 + 0x50),
               (uint)*(byte *)(iVar1 + 0x51));
  FUN_409d0060(param_1,(uint)*(byte *)(iVar1 + 0x52));
  FUN_409d0160(param_1,(uint)*(byte *)(iVar1 + 0x53),(uint)*(byte *)(iVar1 + 0x54),
               (uint)*(byte *)(iVar1 + 0x55));
  FUN_409d0208(param_1,(uint)*(byte *)(iVar1 + 0x56),(uint)*(byte *)(iVar1 + 0x57),
               (uint)*(byte *)(iVar1 + 0x58));
  FUN_409d0004(param_1,(uint)*(byte *)(iVar1 + 0x59));
  FUN_409d00b8(param_1,(uint)*(byte *)(iVar1 + 0x5a),(uint)*(byte *)(iVar1 + 0x5b),
               (uint)*(byte *)(iVar1 + 0x5c));
  return;
}



/* 409d0750 FUN_409d0750 */

/* Boundary evidence: original MIPS .pdata 409d0750..409d07af. Semantic name remains unreviewed. */

void FUN_409d0750(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x504);
  *(uint *)(iVar1 + 0x40) = *(uint *)(iVar1 + 0x40) & 0xfffffffd | param_2 << 1;
  FUN_409d0370(param_1,(uint)*(byte *)(iVar1 + 0x4d));
  FUN_409d03cc(param_1,(uint)*(byte *)(iVar1 + 0x4e));
  return;
}



/* 409d07b0 FUN_409d07b0 */

/* Boundary evidence: original MIPS .pdata 409d07b0..409d07fb. Semantic name remains unreviewed. */

void FUN_409d07b0(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x504);
  *(uint *)(iVar1 + 0x40) = *(uint *)(iVar1 + 0x40) & 0xfffffffb | param_2 << 2;
  FUN_409d0480(param_1,(uint)*(byte *)(iVar1 + 0x48),(uint)*(byte *)(iVar1 + 0x49),
               (uint)*(byte *)(iVar1 + 0x4a),*(byte *)(iVar1 + 0x4b));
  return;
}



/* 409d07fc FUN_409d07fc */

/* Boundary evidence: original MIPS .pdata 409d07fc..409d0a17. Semantic name remains unreviewed. */

undefined4 FUN_409d07fc(int param_1,uint param_2,int param_3)

{
  undefined1 uVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 uVar4;
  
  if ((param_3 != 1) && (param_3 != 0)) {
    param_3 = 1;
  }
  if (param_2 < 0xbe3) {
    if (param_2 == 0xbe2) {
      iVar3 = *(int *)(param_1 + 0x504);
      *(uint *)(iVar3 + 0x40) = param_3 << 2 | *(uint *)(iVar3 + 0x40) & 0xfffffffb;
      FUN_409d0480(param_1,(uint)*(byte *)(iVar3 + 0x48),(uint)*(byte *)(iVar3 + 0x49),
                   (uint)*(byte *)(iVar3 + 0x4a),*(byte *)(iVar3 + 0x4b));
    }
    else if (param_2 == 0xb44) {
      *(char *)(param_1 + 0x3ec) = (char)param_3;
    }
    else if (param_2 == 0xb71) {
      FUN_409d0750(param_1,param_3);
    }
    else if (param_2 == 0xb90) {
      FUN_409d0698(param_1,param_3);
    }
    else {
      if (param_2 != 0xbd0) {
        return 0x500;
      }
      *(uint *)(*(int *)(param_1 + 0x504) + 0x38) =
           param_3 << 0xd ^ *(uint *)(*(int *)(param_1 + 0x504) + 0x38) & 0xffffdfff;
    }
  }
  else if (param_2 == 0xc11) {
    if (param_3 == 0) {
      *(uint *)(param_1 + 0xc) = *(uint *)(param_1 + 0xc) & 0xfffeffff;
    }
    else {
      *(uint *)(param_1 + 0xc) = *(uint *)(param_1 + 0xc) | 0x10000;
    }
  }
  else if (param_2 == 0x8037) {
    iVar3 = *(int *)(param_1 + 0x504);
    uVar2 = *(undefined4 *)(iVar3 + 0x7c);
    uVar4 = *(undefined4 *)(iVar3 + 0x80);
    *(uint *)(iVar3 + 0x40) = param_3 << 7 | *(uint *)(iVar3 + 0x40) & 0xffffff7f;
    iVar3 = *(int *)(param_1 + 0x504);
    *(undefined4 *)(iVar3 + 0x7c) = uVar2;
    *(undefined4 *)(iVar3 + 0x80) = uVar4;
    uVar1 = FUN_409cfa50(uVar2);
    *(undefined1 *)(iVar3 + 0x65) = uVar1;
    *(undefined1 *)(iVar3 + 0x66) = 0;
  }
  else if (param_2 == 0x809e) {
    FUN_409cfe60(param_1,param_3);
  }
  else {
    if (param_2 != 0x80a0) {
      return 0x500;
    }
    iVar3 = *(int *)(param_1 + 0x504);
    *(uint *)(iVar3 + 0x40) = param_3 << 6 | *(uint *)(iVar3 + 0x40) & 0xffffffbf;
    FUN_409cfee0(param_1,*(undefined4 *)(iVar3 + 0x60),(uint)*(byte *)(iVar3 + 100));
  }
  return 0;
}



/* 409d0a18 FUN_409d0a18 */

/* Boundary evidence: original MIPS .pdata 409d0a18..409d0a33. Semantic name remains unreviewed. */

void FUN_409d0a18(int param_1)

{
  mali_sys_atomic_dec_and_return(param_1 + 0x18);
  return;
}



/* 409d0a3c FUN_409d0a3c */

/* Boundary evidence: original MIPS .pdata 409d0a3c..409d0a93. Semantic name remains unreviewed. */

void FUN_409d0a3c(int param_1)

{
  __mali_shader_binary_state_reset(param_1 + 0x1c);
  if (*(int *)(param_1 + 8) != 0) {
    mali_sys_free();
  }
  if (*(int *)(param_1 + 0x14) != 0) {
    mali_sys_free();
  }
  mali_sys_free(param_1);
  return;
}



/* 409d0a94 FUN_409d0a94 */

/* Boundary evidence: original MIPS .pdata 409d0a94..409d0b07. Semantic name remains unreviewed. */

undefined4 * FUN_409d0a94(undefined4 param_1)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)mali_sys_malloc(0x78);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    *puVar1 = param_1;
    *(undefined1 *)(puVar1 + 1) = 0;
    puVar1[3] = 0;
    puVar1[2] = 0;
    puVar1[4] = 0;
    puVar1[5] = 0;
    mali_sys_atomic_initialize(puVar1 + 6,0);
    __mali_shader_binary_state_init(puVar1 + 7);
  }
  return puVar1;
}



/* 409d0b08 FUN_409d0b08 */

/* Boundary evidence: original MIPS .pdata 409d0b08..409d0b43. Semantic name remains unreviewed. */

undefined4 FUN_409d0b08(int param_1,uint param_2)

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



/* 409d0b44 FUN_409d0b44 */

/* Boundary evidence: original MIPS .pdata 409d0b44..409d0c17. Semantic name remains unreviewed. */

undefined4 FUN_409d0b44(int param_1,uint param_2)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  
  if (param_2 != 0) {
    if (param_2 < 0x100) {
      piVar2 = *(int **)((param_2 + 7) * 4 + param_1);
    }
    else {
      piVar2 = (int *)__mali_named_list_get_non_flat(param_1,param_2);
    }
    if (piVar2 == (int *)0x0) {
      return 0x501;
    }
    if (*piVar2 != 0) {
      return 0x502;
    }
    iVar3 = piVar2[1];
    iVar1 = mali_sys_atomic_get(iVar3 + 0x18);
    if (iVar1 == 0) {
      FUN_409d0a3c(iVar3);
      mali_sys_free(piVar2);
      __mali_named_list_remove(param_1,param_2);
    }
    else {
      *(undefined1 *)(iVar3 + 4) = 1;
    }
  }
  return 0;
}



/* 409d0c18 FUN_409d0c18 */

/* Boundary evidence: original MIPS .pdata 409d0c18..409d0cdb. Semantic name remains unreviewed. */

void FUN_409d0c18(undefined4 param_1,int param_2,int *param_3)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  
  FUN_409da688();
  if (((param_2 == 0x8b31) || (param_2 == 0x8b30)) &&
     (puVar1 = FUN_409d0a94(param_2), puVar1 != (undefined4 *)0x0)) {
    puVar2 = (undefined4 *)mali_sys_malloc(8);
    if (puVar2 != (undefined4 *)0x0) {
      puVar2[1] = puVar1;
      *puVar2 = 0;
      iVar3 = __mali_named_list_get_unused_name(param_1);
      if ((iVar3 != 0) && (iVar4 = __mali_named_list_insert(param_1,iVar3,puVar2), iVar4 == 0)) {
        *param_3 = iVar3;
        goto LAB_409d0cd4;
      }
      mali_sys_free(puVar2);
    }
    FUN_409d0a3c((int)puVar1);
  }
LAB_409d0cd4:
                    /* WARNING: Subroutine does not return */
  FUN_409da6b0(0x10);
}



/* 409d0cdc FUN_409d0cdc */

/* Boundary evidence: original MIPS .pdata 409d0cdc..409d0e33. Semantic name remains unreviewed. */

void FUN_409d0cdc(int param_1,int param_2,uint *param_3,int param_4,int param_5)

{
  int *piVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint *puVar6;
  int in_stack_00000050;
  undefined4 in_stack_00000054;
  
  FUN_409da758();
  iVar4 = 0;
  iVar3 = 0;
  iVar5 = param_2;
  puVar6 = param_3;
  if (0 < param_2) {
    do {
      param_5 = 0x500;
      piVar1 = (int *)FUN_409d30d0(param_1,*puVar6,&param_5);
      if ((piVar1 != (int *)0x0) && (param_5 == 0)) {
        if (*piVar1 == 0x8b31) {
          iVar4 = iVar4 + 1;
        }
        else {
          iVar3 = iVar3 + 1;
        }
        __mali_shader_binary_state_reset(piVar1 + 7);
      }
      iVar5 = iVar5 + -1;
      puVar6 = puVar6 + 1;
    } while (iVar5 != 0);
  }
  if ((((param_4 == 0x8f60) && (iVar4 < 2)) && (iVar3 < 2)) && (iVar5 = 0, 0 < param_2)) {
    do {
      param_5 = 0x500;
      puVar2 = (undefined4 *)FUN_409d30d0(param_1,*param_3,&param_5);
      if (((puVar2 == (undefined4 *)0x0) || (param_5 != 0)) ||
         ((in_stack_00000050 != 0 &&
          ((iVar3 = __mali_binary_shader_load
                              (puVar2 + 7,*puVar2,in_stack_00000050,in_stack_00000054), iVar3 == -2
           || (iVar3 == -1)))))) break;
      iVar5 = iVar5 + 1;
      param_3 = param_3 + 1;
    } while (iVar5 < param_2);
  }
                    /* WARNING: Subroutine does not return */
  FUN_409da790(0x18);
}



/* 409d0e34 FUN_409d0e34 */

/* Boundary evidence: original MIPS .pdata 409d0e34..409d0f27. Semantic name remains unreviewed. */

undefined4 FUN_409d0e34(int param_1,uint param_2,int param_3,uint *param_4)

{
  uint *puVar1;
  uint uVar2;
  int local_18 [2];
  
  if (param_2 == 0) {
    return 0x501;
  }
  puVar1 = (uint *)FUN_409d30d0(param_1,param_2,local_18);
  if (local_18[0] == 0x501) {
    return 0x501;
  }
  if (local_18[0] != 0) {
    return 0x502;
  }
  if (param_4 != (uint *)0x0) {
    if (param_3 == 0x8b4f) {
      uVar2 = *puVar1;
    }
    else {
      if (param_3 == 0x8b80) {
        *param_4 = (uint)(byte)puVar1[1];
        return 0;
      }
      if (param_3 != 0x8b81) {
        if (param_3 == 0x8b84) {
          bs_get_log_length(puVar1 + 8,param_4);
          return 0;
        }
        if (param_3 == 0x8b88) {
          *param_4 = puVar1[3];
          return 0;
        }
        return 0x500;
      }
      uVar2 = puVar1[7];
    }
    *param_4 = uVar2;
    return 0;
  }
  return 0;
}



/* 409d0f28 FUN_409d0f28 */

/* Boundary evidence: original MIPS .pdata 409d0f28..409d0fa3. Semantic name remains unreviewed. */

undefined4 FUN_409d0f28(int param_1,uint param_2,int param_3,undefined4 param_4,undefined4 param_5)

{
  undefined4 uVar1;
  int iVar2;
  int local_18 [2];
  
  if (param_3 < 0) {
    uVar1 = 0x501;
  }
  else {
    iVar2 = FUN_409d30d0(param_1,param_2,local_18);
    uVar1 = 0x501;
    if (local_18[0] != 0x501) {
      if (local_18[0] == 0) {
        bs_get_log(iVar2 + 0x20,param_3,param_4,param_5);
        uVar1 = 0;
      }
      else {
        uVar1 = 0x502;
      }
    }
  }
  return uVar1;
}



/* 409d0fa4 FUN_409d0fa4 */

/* Boundary evidence: original MIPS .pdata 409d0fa4..409d102f. Semantic name remains unreviewed. */

undefined4 FUN_409d0fa4(int param_1,uint param_2)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 uVar3;
  int local_18 [2];
  
  uVar3 = 0x501;
  local_18[0] = 0x501;
  puVar1 = (undefined4 *)FUN_409d30d0(param_1,param_2,local_18);
  if (local_18[0] != 0x501) {
    if (local_18[0] == 0) {
      __mali_shader_binary_state_reset(puVar1 + 7);
      iVar2 = __mali_compile_essl_shader(puVar1 + 7,*puVar1,puVar1[2],puVar1[5],puVar1[4]);
      uVar3 = 0x505;
      if (iVar2 != -1) {
        uVar3 = 0;
      }
    }
    else {
      uVar3 = 0x502;
    }
  }
  return uVar3;
}



/* 409d1030 FUN_409d1030 */

/* Boundary evidence: original MIPS .pdata 409d1030..409d1127. Semantic name remains unreviewed. */

undefined4 FUN_409d1030(int param_1,uint param_2,uint param_3,int *param_4,undefined1 *param_5)

{
  int iVar1;
  int local_20 [2];
  
  local_20[0] = 0x501;
  if (param_2 != 0) {
    if ((int)param_3 < 0) {
      return 0x501;
    }
    iVar1 = FUN_409d30d0(param_1,param_2,local_20);
    if (local_20[0] == 0x501) {
      return 0x501;
    }
    if (local_20[0] == 0) {
      if (((*(int *)(iVar1 + 8) == 0) || (param_3 == 0)) || (param_5 == (undefined1 *)0x0)) {
        if (param_4 != (int *)0x0) {
          *param_4 = 0;
        }
        if ((0 < (int)param_3) && (param_5 != (undefined1 *)0x0)) {
          *param_5 = 0;
        }
      }
      else {
        mali_sys_strncpy(param_5,*(int *)(iVar1 + 8),param_3);
        param_5[param_3 - 1] = 0;
        if (param_4 != (int *)0x0) {
          if (param_3 < *(uint *)(iVar1 + 0xc)) {
            *param_4 = param_3 - 1;
          }
          else {
            *param_4 = *(uint *)(iVar1 + 0xc) - 1;
          }
        }
      }
      return 0;
    }
  }
  return 0x502;
}



/* 409d1128 FUN_409d1128 */

/* Boundary evidence: original MIPS .pdata 409d1128..409d12b7. Semantic name remains unreviewed. */

void FUN_409d1128(int param_1,uint param_2,int param_3,int param_4,int param_5,int param_6)

{
  int iVar1;
  int *piVar2;
  undefined1 *puVar3;
  undefined1 *puVar4;
  int *piVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int *in_stack_00000050;
  
  FUN_409da758();
  param_5 = 0x501;
  iVar6 = 0;
  if ((((-1 < param_3) &&
       (iVar1 = FUN_409d30d0(param_1,param_2,&param_5), param_6 = iVar1, param_5 != 0x501)) &&
      (param_5 == 0)) && (piVar2 = (int *)mali_sys_malloc(param_3 << 2), piVar2 != (int *)0x0)) {
    if (0 < param_3) {
      piVar5 = in_stack_00000050;
      iVar7 = param_3;
      do {
        if ((in_stack_00000050 == (int *)0x0) || (iVar1 = *piVar5, iVar1 < 0)) {
          iVar1 = mali_sys_strlen(*(undefined4 *)((param_4 - (int)in_stack_00000050) + (int)piVar5))
          ;
          *(int *)(((int)piVar2 - (int)in_stack_00000050) + (int)piVar5) = iVar1;
        }
        else {
          *(int *)(((int)piVar2 - (int)in_stack_00000050) + (int)piVar5) = iVar1;
        }
        iVar6 = iVar1 + iVar6;
        iVar7 = iVar7 + -1;
        piVar5 = piVar5 + 1;
        iVar1 = param_6;
      } while (iVar7 != 0);
    }
    puVar3 = (undefined1 *)mali_sys_malloc(iVar6 + 1);
    if (puVar3 == (undefined1 *)0x0) {
      mali_sys_free(piVar2);
    }
    else {
      iVar7 = 0;
      *puVar3 = 0;
      if (0 < param_3) {
        puVar4 = puVar3;
        piVar5 = piVar2;
        iVar8 = param_3;
        do {
          mali_sys_strncpy(puVar4,*(undefined4 *)((param_4 - (int)piVar2) + (int)piVar5),*piVar5);
          iVar7 = *piVar5 + iVar7;
          puVar4 = puVar3 + iVar7;
          piVar5 = piVar5 + 1;
          iVar8 = iVar8 + -1;
          *puVar4 = 0;
        } while (iVar8 != 0);
      }
      if (*(int *)(iVar1 + 8) != 0) {
        mali_sys_free();
      }
      if (*(int *)(iVar1 + 0x14) != 0) {
        mali_sys_free();
      }
      *(int **)(iVar1 + 0x14) = piVar2;
      *(int *)(iVar1 + 0xc) = iVar6 + 1;
      *(int *)(iVar1 + 0x10) = param_3;
      *(undefined1 **)(iVar1 + 8) = puVar3;
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_409da790(0x18);
}



/* 409d12b8 FUN_409d12b8 */

/* Boundary evidence: original MIPS .pdata 409d12b8..409d12e7. Semantic name remains unreviewed. */

bool FUN_409d12b8(int param_1,uint param_2)

{
  int local_10 [2];
  
  FUN_409d30d0(param_1,param_2,local_10);
  return local_10[0] == 0;
}



/* 409d12e8 FUN_409d12e8 */

/* Boundary evidence: original MIPS .pdata 409d12e8..409d1413. Semantic name remains unreviewed. */

void FUN_409d12e8(int *param_1,int *param_2,undefined4 *param_3)

{
  int *piVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 auStackX_0 [4];
  int local_40 [16];
  
  piVar1 = local_40;
  do {
    *piVar1 = 0xffffffff;
    piVar1 = piVar1 + 1;
  } while (piVar1 != auStackX_0);
  piVar1 = param_2;
  do {
    *piVar1 = -1;
    piVar1 = piVar1 + 1;
  } while (piVar1 != param_2 + 0x10);
  puVar2 = param_3;
  do {
    *puVar2 = 0xffffffff;
    puVar2 = puVar2 + 1;
  } while (puVar2 != param_3 + 0x10);
  iVar3 = 0;
  piVar1 = param_1;
  do {
    if (-1 < *piVar1) {
      local_40[*piVar1] = iVar3;
    }
    iVar3 = iVar3 + 1;
    prefetch(piVar1 + 2,0);
    piVar1 = piVar1 + 1;
  } while (iVar3 < 0x10);
  iVar4 = 0x10;
  iVar5 = 0;
  iVar3 = 0x10;
  piVar1 = param_2;
  do {
    if (-1 < *(int *)(((int)local_40 - (int)param_2) + (int)piVar1)) {
      *piVar1 = iVar5;
      iVar5 = iVar5 + 1;
    }
    iVar3 = iVar3 + -1;
    piVar1 = piVar1 + 1;
  } while (iVar3 != 0);
  iVar3 = 0;
  piVar1 = param_2;
  do {
    if (-1 < *piVar1) {
      param_3[*piVar1] = iVar3;
    }
    iVar3 = iVar3 + 1;
    prefetch(piVar1 + 2,0);
    piVar1 = piVar1 + 1;
  } while (iVar3 < 0x10);
  do {
    if (-1 < *param_1) {
      *param_1 = param_2[*param_1];
    }
    param_1 = param_1 + 1;
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  return;
}



/* 409d1414 FUN_409d1414 */

int FUN_409d1414(int param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  
  iVar1 = -1;
  iVar5 = 0;
  iVar4 = -1;
  iVar3 = 0;
  uVar6 = *(int *)(param_1 + 0x34) + 3U >> 2;
  iVar2 = 0;
  do {
    if (*param_2 < 0) {
      iVar3 = iVar3 + 1;
    }
    else {
      if (((int)uVar6 <= iVar3) && ((iVar1 == -1 || (iVar3 < iVar5)))) {
        iVar1 = iVar4 + 1;
        iVar5 = iVar3;
      }
      iVar3 = 0;
      iVar4 = iVar2;
    }
    iVar2 = iVar2 + 1;
    param_2 = param_2 + 1;
  } while (iVar2 < 0x10);
  if (((int)uVar6 <= iVar3) && ((iVar1 == -1 || (iVar3 < iVar5)))) {
    iVar1 = iVar4 + 1;
  }
  return iVar1;
}



/* 409d14bc FUN_409d14bc */

/* Boundary evidence: original MIPS .pdata 409d14bc..409d14eb. Semantic name remains unreviewed. */

void FUN_409d14bc(undefined4 *param_1)

{
  mali_sys_free(*param_1);
  mali_sys_free(param_1);
  return;
}



/* 409d1518 FUN_409d1518 */

/* Boundary evidence: original MIPS .pdata 409d1518..409d17af. Semantic name remains unreviewed. */

void FUN_409d1518(int param_1,undefined4 *param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  uint uVar6;
  int *piVar7;
  int iVar8;
  uint uVar9;
  undefined4 *puVar10;
  undefined4 *puVar11;
  
  FUN_409da758();
  puVar11 = (undefined4 *)&stack0x00000010;
  do {
    *puVar11 = 0xffffffff;
    puVar11 = puVar11 + 1;
  } while (puVar11 != (undefined4 *)&stack0x00000050);
  puVar11 = param_2;
  do {
    *puVar11 = 0xffffffff;
    puVar11 = puVar11 + 1;
  } while (puVar11 != param_2 + 0x10);
  iVar1 = __mali_linked_list_get_first_entry(param_1 + 0x14);
LAB_409d1670:
  if (iVar1 != 0) {
    piVar4 = *(int **)(*(int *)(param_1 + 0x20) + 0x18);
    puVar11 = *(undefined4 **)(iVar1 + 8);
    uVar9 = 0;
    if (piVar4[1] != 0) {
      iVar5 = 0;
      do {
        puVar10 = *(undefined4 **)(iVar5 + *piVar4);
        iVar8 = mali_sys_strcmp(*puVar10,*puVar11);
        piVar4 = *(int **)(*(int *)(param_1 + 0x20) + 0x18);
        if (iVar8 == 0) {
          iVar5 = *(int *)(*(int *)(*piVar4 + uVar9 * 4) + 0x3c);
          if (iVar5 < 0) {
            iVar5 = iVar5 + 3;
          }
          iVar5 = iVar5 >> 2;
          if ((-1 < iVar5) && (uVar9 = 0, (puVar10[0xd] + 3 & 0xfffffffc) != 0)) {
            piVar4 = param_2 + iVar5;
            goto LAB_409d1618;
          }
          break;
        }
        uVar9 = uVar9 + 1;
        iVar5 = iVar5 + 4;
      } while (uVar9 < (uint)piVar4[1]);
    }
    goto LAB_409d1668;
  }
  piVar4 = *(int **)(*(int *)(param_1 + 0x20) + 0x18);
  uVar9 = 0;
  if (piVar4[1] != 0) {
    iVar1 = 0;
    do {
      iVar8 = *(int *)(iVar1 + *piVar4);
      iVar5 = *(int *)(iVar8 + 0x3c);
      if (iVar5 < 0) {
        iVar5 = iVar5 + 3;
      }
      iVar5 = iVar5 >> 2;
      piVar4 = param_2 + iVar5;
      if (*piVar4 < 0) {
        iVar2 = FUN_409d1414(iVar8,(int *)&stack0x00000010);
        if (iVar2 == -1) {
          bs_set_error(*(int *)(param_1 + 0x20) + 4,"L0004",
                       "Not enough attribute locations available");
LAB_409d1770:
          bs_is_error_log_set_to_out_of_memory(*(int *)(param_1 + 0x20) + 4);
          break;
        }
        uVar6 = 0;
        if ((*(int *)(iVar8 + 0x34) + 3U & 0xfffffffc) != 0) {
          piVar7 = (int *)(&stack0x00000010 + iVar2 * 4);
          iVar2 = iVar2 - iVar5;
          do {
            *piVar4 = iVar2 + iVar5;
            uVar6 = uVar6 + 1;
            iVar3 = *(int *)(iVar8 + 0x34);
            *piVar7 = iVar5;
            iVar5 = iVar5 + 1;
            piVar4 = piVar4 + 1;
            piVar7 = piVar7 + 1;
          } while (uVar6 < iVar3 + 3U >> 2);
        }
      }
      uVar9 = uVar9 + 1;
      piVar4 = *(int **)(*(int *)(param_1 + 0x20) + 0x18);
      iVar1 = iVar1 + 4;
    } while (uVar9 < (uint)piVar4[1]);
  }
                    /* WARNING: Subroutine does not return */
  FUN_409da790(0x50);
  while( true ) {
    iVar2 = uVar9 + iVar2;
    *piVar4 = iVar2;
    iVar8 = puVar10[0xd];
    *(uint *)(&stack0x00000010 + iVar2 * 4) = uVar9 + iVar5;
    uVar9 = uVar9 + 1;
    piVar4 = piVar4 + 1;
    if (iVar8 + 3U >> 2 <= uVar9) break;
LAB_409d1618:
    iVar2 = puVar11[1];
    iVar8 = uVar9 + iVar2;
    if (0xf < iVar8) {
      bs_set_program_link_error_attribute_bound_outsize_of_legal_range
                (*(undefined4 *)(param_1 + 0x20),*puVar10,iVar8,0xf);
      goto LAB_409d1770;
    }
  }
LAB_409d1668:
  iVar1 = __mali_linked_list_get_next_entry(iVar1);
  goto LAB_409d1670;
}



/* 409d17b0 FUN_409d17b0 */

/* Boundary evidence: original MIPS .pdata 409d17b0..409d17db. Semantic name remains unreviewed. */

void FUN_409d17b0(int param_1)

{
  if (param_1 + 0x14 != 0) {
    __mali_linked_list_empty(param_1 + 0x14,FUN_409d14bc);
  }
  return;
}



/* 409d17dc FUN_409d17dc */

/* Boundary evidence: original MIPS .pdata 409d17dc..409d1847. Semantic name remains unreviewed. */

int FUN_409d17dc(int param_1)

{
  int iVar1;
  int aiStack_48 [16];
  
  iVar1 = FUN_409d1518(param_1,aiStack_48);
  if (iVar1 == 0) {
    FUN_409d12e8(aiStack_48,(int *)(*(int *)(param_1 + 0x20) + 0xb8),
                 (undefined4 *)(*(int *)(param_1 + 0x20) + 0xf8));
    iVar1 = mali_gp2_link_attribs(*(undefined4 *)(param_1 + 0x20),aiStack_48,1);
    if (iVar1 == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = -1;
    }
  }
  return iVar1;
}



/* 409d1848 FUN_409d1848 */

/* Boundary evidence: original MIPS .pdata 409d1848..409d1907. Semantic name remains unreviewed. */

void FUN_409d1848(int param_1,uint param_2,undefined4 param_3,undefined4 *param_4,undefined4 param_5
                 ,undefined4 param_6,int param_7,int param_8)

{
  int iVar1;
  int iVar2;
  
  FUN_409da7c8();
  if (param_4 != (undefined4 *)0x0) {
    *param_4 = 0xffffffff;
  }
  iVar1 = FUN_409d30d0(param_1,param_2,&param_7);
  if ((((param_7 != 0x501) && (param_7 == 1)) && (**(int **)(iVar1 + 0x20) == 1)) &&
     ((param_4 != (undefined4 *)0x0 &&
      (iVar2 = bs_symbol_lookup((*(int **)(iVar1 + 0x20))[6],param_3,&param_8,0), iVar2 != 0)))) {
    iVar2 = param_8;
    if (param_8 < 0) {
      iVar2 = param_8 + 3;
    }
    *param_4 = *(undefined4 *)(((iVar2 >> 2) + 0x3e) * 4 + *(int *)(iVar1 + 0x20));
  }
                    /* WARNING: Subroutine does not return */
  FUN_409da7e8(0x20);
}



/* 409d1908 FUN_409d1908 */

/* Boundary evidence: original MIPS .pdata 409d1908..409d1a6f. Semantic name remains unreviewed. */

undefined4
FUN_409d1908(int param_1,uint param_2,uint param_3,int param_4,undefined4 *param_5,
            undefined4 *param_6,undefined4 *param_7,int param_8)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  int local_30 [2];
  
  if ((param_4 < 0) || (0xf < param_3)) {
    uVar4 = 0x501;
  }
  else {
    iVar1 = FUN_409d30d0(param_1,param_2,local_30);
    uVar4 = 0x501;
    if (local_30[0] != 0x501) {
      if (local_30[0] == 1) {
        iVar3 = *(int *)(*(int *)(iVar1 + 0x20) + 0x18);
        if ((iVar3 != 0) &&
           (uVar2 = bs_symbol_count_actives(iVar3,&PTR_DAT_409dd380,2), param_3 < uVar2)) {
          uVar4 = 0;
          iVar1 = bs_symbol_get_nth_active
                            (*(undefined4 *)(*(int *)(iVar1 + 0x20) + 0x18),param_3,param_8,param_4,
                             &PTR_DAT_409dd380,2);
          if (param_8 != 0) {
            uVar4 = mali_sys_strlen(param_8);
          }
          if (param_5 != (undefined4 *)0x0) {
            *param_5 = uVar4;
          }
          if ((param_6 != (undefined4 *)0x0) &&
             (*param_6 = *(undefined4 *)(iVar1 + 0x30), *(int *)(iVar1 + 0x30) == 0)) {
            *param_6 = 1;
          }
          if (param_7 != (undefined4 *)0x0) {
            uVar4 = FUN_409d1ca0(*(int *)(iVar1 + 4),*(int *)(iVar1 + 0x1c));
            *param_7 = uVar4;
          }
          uVar4 = 0;
        }
      }
      else {
        uVar4 = 0x502;
      }
    }
  }
  return uVar4;
}



/* 409d1a70 FUN_409d1a70 */

/* Boundary evidence: original MIPS .pdata 409d1a70..409d1c4b. Semantic name remains unreviewed. */

undefined4 FUN_409d1a70(int param_1,uint param_2,uint param_3,undefined4 param_4)

{
  uint uVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  undefined4 *puVar6;
  int local_28 [2];
  
  if (0xf < param_3) {
    return 0x501;
  }
  uVar1 = mali_sys_strlen(param_4);
  if ((uVar1 < 3) || (iVar2 = mali_sys_memcmp(param_4,&DAT_409b1be4,3), iVar2 != 0)) {
    iVar2 = FUN_409d30d0(param_1,param_2,local_28);
    if (local_28[0] == 0x501) {
      return 0x501;
    }
    if (local_28[0] == 1) {
      piVar3 = (int *)mali_sys_malloc(8);
      if (piVar3 != (int *)0x0) {
        iVar4 = mali_sys_strlen(param_4);
        iVar5 = mali_sys_malloc(iVar4 + 1);
        if (iVar5 != 0) {
          mali_sys_memcpy(iVar5,param_4,iVar4);
          *(undefined1 *)(iVar5 + iVar4) = 0;
          piVar3[1] = param_3;
          *piVar3 = iVar5;
          for (iVar4 = __mali_linked_list_get_first_entry(iVar2 + 0x14); iVar4 != 0;
              iVar4 = __mali_linked_list_get_next_entry(iVar4)) {
            puVar6 = *(undefined4 **)(iVar4 + 8);
            iVar5 = mali_sys_strcmp(*puVar6,param_4);
            if (iVar5 == 0) {
              mali_sys_free(*puVar6);
              mali_sys_free(puVar6);
              *(int **)(iVar4 + 8) = piVar3;
              return 0;
            }
          }
          iVar2 = __mali_linked_list_insert_data(iVar2 + 0x14,piVar3);
          if (iVar2 != 0) {
            mali_sys_free(*piVar3);
            mali_sys_free(piVar3);
            if (((iVar2 != -3) && (-3 < iVar2)) && (iVar2 < 0)) {
              return 0x505;
            }
          }
          return 0;
        }
        mali_sys_free(piVar3);
      }
      return 0x505;
    }
  }
  return 0x502;
}



/* 409d1c4c FUN_409d1c4c */

/* Boundary evidence: original MIPS .pdata 409d1c4c..409d1c9f. Semantic name remains unreviewed. */

undefined4 FUN_409d1c4c(int param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  
  if (param_3 == 0) {
    uVar1 = *(undefined4 *)(param_2 * 4 + param_1);
  }
  else if (param_3 == 3) {
    uVar1 = __litofp(*(undefined4 *)(param_2 * 4 + param_1));
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}



/* 409d1ca0 FUN_409d1ca0 */

undefined4 FUN_409d1ca0(int param_1,int param_2)

{
  if (param_1 == 1) {
    if (param_2 == 1) {
      return 0x1406;
    }
    if (param_2 == 2) {
      return 0x8b50;
    }
    if (param_2 == 3) {
      return 0x8b51;
    }
    if (param_2 == 4) {
      return 0x8b52;
    }
  }
  else if (param_1 == 2) {
    if (param_2 == 1) {
      return 0x1404;
    }
    if (param_2 == 2) {
      return 0x8b53;
    }
    if (param_2 == 3) {
      return 0x8b54;
    }
    if (param_2 == 4) {
      return 0x8b55;
    }
  }
  else if (param_1 == 3) {
    if (param_2 == 1) {
      return 0x8b56;
    }
    if (param_2 == 2) {
      return 0x8b57;
    }
    if (param_2 == 3) {
      return 0x8b58;
    }
    if (param_2 == 4) {
      return 0x8b59;
    }
  }
  else if (param_1 == 4) {
    if (param_2 == 2) {
      return 0x8b5a;
    }
    if (param_2 == 3) {
      return 0x8b5b;
    }
    if (param_2 == 4) {
      return 0x8b5c;
    }
  }
  else if (param_1 == 5) {
    if (param_2 == 2) {
      return 0x8b5e;
    }
  }
  else if (param_1 == 6) {
    return 0x8b60;
  }
  return 0x500;
}



/* 409d1e14 FUN_409d1e14 */

/* Boundary evidence: original MIPS .pdata 409d1e14..409d208b. Semantic name remains unreviewed. */

void FUN_409d1e14(int param_1)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  int *piVar5;
  undefined4 uStack00000010;
  
  FUN_409da758();
  iVar2 = *(int *)(param_1 + 0x20);
  uStack00000010 = 0;
  iVar1 = bs_symbol_lookup(*(undefined4 *)(iVar2 + 0x14),"gl_mali_ViewportTransform",
                           (undefined4 *)(iVar2 + 0x140),0);
  if ((((iVar1 == 0) || (*(int *)(iVar1 + 4) != 1)) || (*(int *)(iVar1 + 0x1c) != 4)) ||
     (*(int *)(iVar1 + 0x30) != 2)) {
    *(undefined4 *)(iVar2 + 0x140) = 0xffffffff;
  }
  uStack00000010 = 0;
  iVar1 = bs_symbol_lookup(*(undefined4 *)(iVar2 + 0x14),"gl_mali_PointSizeParameters",
                           (undefined4 *)(iVar2 + 0x144),0);
  if (((iVar1 == 0) || (*(int *)(iVar1 + 4) != 1)) ||
     ((*(int *)(iVar1 + 0x1c) != 4 || (*(int *)(iVar1 + 0x30) != 0)))) {
    *(undefined4 *)(iVar2 + 0x144) = 0xffffffff;
  }
  piVar4 = (int *)(iVar2 + 0x14c);
  uStack00000010 = 0;
  iVar1 = bs_symbol_lookup(*(undefined4 *)(iVar2 + 0x14),"gl_mali_PointCoordScaleBias",0,piVar4);
  if (((iVar1 == 0) || (*(int *)(iVar1 + 4) != 1)) ||
     ((*(int *)(iVar1 + 0x1c) != 4 || (*(int *)(iVar1 + 0x30) != 0)))) {
    *piVar4 = -1;
  }
  piVar3 = (int *)(iVar2 + 0x148);
  uStack00000010 = 0;
  iVar1 = bs_symbol_lookup(*(undefined4 *)(iVar2 + 0x14),"gl_mali_DerivativeScale",0,piVar3);
  if ((((iVar1 == 0) || (*(int *)(iVar1 + 4) != 1)) || (*(int *)(iVar1 + 0x1c) != 2)) ||
     (*(int *)(iVar1 + 0x30) != 0)) {
    *piVar3 = -1;
  }
  uStack00000010 = 0;
  bs_symbol_lookup(*(undefined4 *)(iVar2 + 0x14),"gl_DepthRange.near",iVar2 + 0x150,
                   (int *)(iVar2 + 0x15c));
  uStack00000010 = 0;
  bs_symbol_lookup(*(undefined4 *)(iVar2 + 0x14),"gl_DepthRange.far",iVar2 + 0x154,
                   (int *)(iVar2 + 0x160));
  uStack00000010 = 0;
  bs_symbol_lookup(*(undefined4 *)(iVar2 + 0x14),"gl_DepthRange.diff",iVar2 + 0x158,
                   (int *)(iVar2 + 0x164));
  piVar5 = (int *)(iVar2 + 0x168);
  uStack00000010 = 0;
  iVar1 = bs_symbol_lookup(*(undefined4 *)(iVar2 + 0x14),"gl_mali_FragCoordScale",0,piVar5);
  if (((iVar1 == 0) || (*(int *)(iVar1 + 4) != 1)) ||
     ((*(int *)(iVar1 + 0x1c) != 3 || (*(int *)(iVar1 + 0x30) != 0)))) {
    *piVar5 = -1;
  }
  if (((*(int *)(iVar2 + 0x15c) == -1) && (*(int *)(iVar2 + 0x160) == -1)) &&
     (*(int *)(iVar2 + 0x164) == -1)) {
    *(undefined4 *)(iVar2 + 0x16c) = 0;
  }
  else {
    *(undefined4 *)(iVar2 + 0x16c) = 1;
  }
  if (((*piVar4 == -1) && (*piVar3 == -1)) && (*piVar5 == -1)) {
    *(undefined4 *)(iVar2 + 0x170) = 0;
  }
  else {
    *(undefined4 *)(iVar2 + 0x170) = 1;
  }
                    /* WARNING: Subroutine does not return */
  FUN_409da790(0x18);
}



/* 409d208c FUN_409d208c */

/* Boundary evidence: original MIPS .pdata 409d208c..409d212f. Semantic name remains unreviewed. */

void FUN_409d208c(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  
  FUN_409da7c8();
  iVar4 = *(int *)(param_1 + 0x20);
  iVar1 = bs_symbol_count_locations(*(undefined4 *)(iVar4 + 0x14));
  *(int *)(iVar4 + 0x13c) = iVar1;
  if (iVar1 != 0) {
    iVar1 = mali_sys_malloc(iVar1 << 4);
    *(int *)(iVar4 + 0x138) = iVar1;
    if (iVar1 == 0) {
      *(undefined4 *)(iVar4 + 0x13c) = 0;
      goto LAB_409d2128;
    }
  }
  uVar5 = 0;
  if (*(int *)(iVar4 + 0x13c) != 0) {
    iVar1 = 0;
    do {
      iVar3 = *(int *)(iVar4 + 0x138) + iVar1;
      uVar2 = bs_symbol_get_nth_location(*(undefined4 *)(iVar4 + 0x14),uVar5,iVar3 + 4,iVar3 + 8);
      *(undefined4 *)(*(int *)(iVar4 + 0x138) + iVar1) = uVar2;
      uVar5 = uVar5 + 1;
      iVar1 = iVar1 + 0x10;
    } while (uVar5 < *(uint *)(iVar4 + 0x13c));
  }
LAB_409d2128:
                    /* WARNING: Subroutine does not return */
  FUN_409da7e8(0x20);
}



/* 409d2130 FUN_409d2130 */

/* Boundary evidence: original MIPS .pdata 409d2130..409d2193. Semantic name remains unreviewed. */

undefined4 FUN_409d2130(int param_1)

{
  int iVar1;
  int iVar2;
  
  if (0 < *(int *)(param_1 + 0xb0)) {
    iVar2 = *(int *)(param_1 + 0xb0) << 1;
    iVar1 = mali_sys_malloc(iVar2);
    *(int *)(param_1 + 0x17c) = iVar1;
    if (iVar1 == 0) {
      return 0xffffffff;
    }
    mali_sys_memset(iVar1,0,iVar2);
  }
  return 0;
}



/* 409d220c FUN_409d220c */

/* Boundary evidence: original MIPS .pdata 409d220c..409d23bb. Semantic name remains unreviewed. */

void FUN_409d220c(int param_1,uint param_2,uint param_3,undefined4 *param_4,int param_5)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  int iVar7;
  int *piVar8;
  int iVar9;
  undefined4 *puVar10;
  undefined4 *puVar11;
  undefined4 *puVar12;
  int in_stack_00000050;
  
  FUN_409da758();
  iVar1 = FUN_409d30d0(param_1,param_2,&param_5);
  if ((((param_5 != 0x501) && (param_5 == 1)) && (piVar6 = *(int **)(iVar1 + 0x20), *piVar6 == 1))
     && ((-1 < (int)param_3 && (param_3 < (uint)piVar6[0x4f])))) {
    piVar8 = (int *)(piVar6[0x4e] + param_3 * 0x10);
    if (piVar8[3] == -1) {
      iVar3 = piVar8[1];
      iVar1 = *piVar8;
      if (iVar3 == -1) {
        iVar5 = piVar6[0x2b];
        iVar7 = *(int *)(iVar1 + 0x24);
        iVar3 = piVar8[2];
      }
      else {
        iVar5 = piVar6[0x1a];
        iVar7 = *(int *)(iVar1 + 0x20);
      }
      iVar9 = *(int *)(iVar1 + 0x1c);
      iVar4 = 1;
      if (*(int *)(iVar1 + 4) == 4) {
        iVar4 = iVar9;
      }
      if (iVar4 != 0) {
        param_5 = iVar7 << 2;
        puVar11 = (undefined4 *)(iVar3 * 4 + iVar5);
        iVar1 = iVar9;
        puVar12 = puVar11;
        puVar10 = param_4;
        do {
          for (; iVar1 != 0; iVar1 = iVar1 + -1) {
            if (in_stack_00000050 == 0) {
              *param_4 = *puVar11;
            }
            if (in_stack_00000050 == 3) {
              uVar2 = __fptoli(*puVar11);
              *param_4 = uVar2;
            }
            puVar11 = puVar11 + 1;
            param_4 = param_4 + 1;
          }
          param_4 = puVar10 + iVar9;
          iVar4 = iVar4 + -1;
          puVar11 = (undefined4 *)(param_5 + (int)puVar12);
          iVar1 = iVar9;
          puVar12 = puVar11;
          puVar10 = param_4;
        } while (iVar4 != 0);
      }
    }
    else {
      if (in_stack_00000050 == 0) {
        uVar2 = __ultofp(*(undefined4 *)(piVar8[3] * 0x10 + piVar6[3] + 0xc));
        *param_4 = uVar2;
      }
      if (in_stack_00000050 == 3) {
        *param_4 = *(undefined4 *)(piVar8[3] * 0x10 + *(int *)(*(int *)(iVar1 + 0x20) + 0xc) + 0xc);
      }
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_409da790(0x18);
}



/* 409d23bc FUN_409d23bc */

/* Boundary evidence: original MIPS .pdata 409d23bc..409d24df. Semantic name remains unreviewed. */

undefined4 FUN_409d23bc(int param_1,uint param_2,undefined4 param_3,uint *param_4)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int *piVar4;
  uint uVar5;
  uint uVar6;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  
  uVar6 = 0;
  if (param_4 != (uint *)0x0) {
    *param_4 = 0xffffffff;
  }
  iVar1 = FUN_409d30d0(param_1,param_2,&local_28);
  uVar2 = 0x501;
  if (local_28 != 0x501) {
    if ((local_28 == 1) && (**(int **)(iVar1 + 0x20) == 1)) {
      iVar3 = bs_symbol_lookup((*(int **)(iVar1 + 0x20))[5],param_3,&local_1c,&local_20,&local_24);
      if (iVar3 != 0) {
        uVar5 = *(uint *)(*(int *)(iVar1 + 0x20) + 0x13c);
        if (uVar5 != 0) {
          piVar4 = *(int **)(*(int *)(iVar1 + 0x20) + 0x138);
          do {
            if ((((*piVar4 == iVar3) && (piVar4[1] == local_1c)) && (piVar4[2] == local_20)) &&
               (piVar4[3] == local_24)) break;
            uVar6 = uVar6 + 1;
            prefetch(piVar4 + 8,0);
            piVar4 = piVar4 + 4;
          } while (uVar6 < uVar5);
        }
        if (param_4 != (uint *)0x0) {
          *param_4 = uVar6;
        }
      }
      uVar2 = 0;
    }
    else {
      uVar2 = 0x502;
    }
  }
  return uVar2;
}



/* 409d24e0 FUN_409d24e0 */

/* Boundary evidence: original MIPS .pdata 409d24e0..409d2673. Semantic name remains unreviewed. */

void FUN_409d24e0(int param_1,uint param_2,uint param_3,int param_4,undefined4 param_5,
                 undefined4 param_6,int param_7)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  undefined1 *puVar5;
  int iVar6;
  int *in_stack_00000050;
  undefined4 *in_stack_00000054;
  undefined4 *in_stack_00000058;
  int in_stack_0000005c;
  
  FUN_409da808();
  if (((-1 < param_4) && (iVar1 = FUN_409d30d0(param_1,param_2,&param_7), param_7 != 0x501)) &&
     (param_7 == 1)) {
    iVar6 = *(int *)(iVar1 + 0x20);
    iVar1 = *(int *)(iVar6 + 0x14);
    if ((iVar1 != 0) &&
       (uVar2 = bs_symbol_count_actives(iVar1,&PTR_DAT_409dd380,2), param_3 < uVar2)) {
      iVar6 = bs_symbol_get_nth_active
                        (*(undefined4 *)(iVar6 + 0x14),param_3,in_stack_0000005c,param_4);
      iVar1 = 0;
      if ((in_stack_0000005c != 0) &&
         ((iVar3 = mali_sys_strlen(in_stack_0000005c), iVar1 = iVar3, *(int *)(iVar6 + 0x30) != 0 &&
          (0 < param_4)))) {
        if (iVar3 < param_4) {
          iVar1 = iVar3 + 1;
          *(undefined1 *)(iVar3 + in_stack_0000005c) = 0x5b;
          if (iVar1 < param_4) {
            puVar5 = (undefined1 *)(iVar1 + in_stack_0000005c);
            iVar1 = iVar3 + 2;
            *puVar5 = 0x30;
            if (iVar1 < param_4) {
              puVar5 = (undefined1 *)(iVar1 + in_stack_0000005c);
              iVar1 = iVar3 + 3;
              *puVar5 = 0x5d;
              if (iVar1 < param_4) {
                *(undefined1 *)(iVar1 + in_stack_0000005c) = 0;
              }
            }
          }
        }
        *(undefined1 *)(param_4 + in_stack_0000005c + -1) = 0;
      }
      if ((in_stack_00000054 != (undefined4 *)0x0) &&
         (*in_stack_00000054 = *(undefined4 *)(iVar6 + 0x30), *(int *)(iVar6 + 0x30) == 0)) {
        *in_stack_00000054 = 1;
      }
      if (in_stack_00000058 != (undefined4 *)0x0) {
        uVar4 = FUN_409d1ca0(*(int *)(iVar6 + 4),*(int *)(iVar6 + 0x1c));
        *in_stack_00000058 = uVar4;
      }
      if (in_stack_00000050 != (int *)0x0) {
        *in_stack_00000050 = iVar1;
      }
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_409da838(0x20);
}



/* 409d2674 FUN_409d2674 */

uint FUN_409d2674(uint param_1)

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



/* 409d2720 FUN_409d2720 */

/* Boundary evidence: original MIPS .pdata 409d2720..409d286f. Semantic name remains unreviewed. */

void FUN_409d2720(int param_1,uint param_2,undefined4 param_3)

{
  uint uVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  uint *puVar5;
  int iVar6;
  int iVar7;
  
  FUN_409da808();
  if ((((param_2 != 0xffffffff) && (param_1 != 0)) && (-1 < (int)param_2)) &&
     (param_2 < *(uint *)(param_1 + 0x13c))) {
    iVar4 = *(int *)(param_1 + 0x68);
    piVar3 = (int *)(*(int *)(param_1 + 0x138) + param_2 * 0x10);
    iVar6 = *(int *)(param_1 + 0xac);
    iVar2 = *(int *)(*piVar3 + 4);
    iVar7 = *(int *)(param_1 + 0x17c);
    if (((iVar2 == 5) || (iVar2 == 6)) || (iVar2 == 7)) {
      *(undefined4 *)(piVar3[3] * 0x10 + *(int *)(param_1 + 0xc) + 0xc) = param_3;
    }
    else if (((iVar2 == 2) || (iVar2 == 3)) && (*(int *)(*piVar3 + 0x1c) == 1)) {
      uVar1 = __litofp(param_3);
      if (-1 < piVar3[1]) {
        puVar5 = (uint *)(piVar3[1] * 4 + iVar4);
        iVar2 = __nes(uVar1,*puVar5);
        if (iVar2 != 0) {
          *puVar5 = uVar1;
          *(undefined4 *)(param_1 + 0x70) = 1;
        }
      }
      if (-1 < piVar3[2]) {
        puVar5 = (uint *)(piVar3[2] * 4 + iVar6);
        iVar2 = __nes(uVar1,*puVar5);
        if (iVar2 != 0) {
          *puVar5 = uVar1;
          uVar1 = FUN_409d2674(uVar1);
          *(short *)(piVar3[2] * 2 + iVar7) = (short)uVar1;
          *(undefined4 *)(param_1 + 0xb4) = 1;
        }
      }
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_409da838(0x10);
}



/* 409d2870 FUN_409d2870 */

/* Boundary evidence: original MIPS .pdata 409d2870..409d2947. Semantic name remains unreviewed. */

void FUN_409d2870(uint *param_1,int param_2,uint *param_3,undefined2 *param_4)

{
  int iVar1;
  uint *puVar2;
  uint *puVar3;
  uint uVar4;
  undefined2 *puVar5;
  int iVar6;
  uint *puStack00000010;
  int iStack00000014;
  int in_stack_00000058;
  int in_stack_0000005c;
  
  FUN_409da758();
  iStack00000014 = in_stack_0000005c;
  puStack00000010 = param_3;
  if (0 < in_stack_0000005c) {
    do {
      puVar2 = puStack00000010;
      puVar3 = param_1;
      puVar5 = param_4;
      iVar6 = in_stack_00000058;
      if (0 < in_stack_00000058) {
        do {
          uVar4 = *puVar2;
          puVar2 = puVar2 + 1;
          iVar1 = __nes(*puVar3,uVar4);
          if ((iVar1 != 0) && (*puVar3 = uVar4, param_4 != (undefined2 *)0x0)) {
            uVar4 = FUN_409d2674(uVar4);
            *puVar5 = (short)uVar4;
          }
          iVar6 = iVar6 + -1;
          puVar3 = puVar3 + 1;
          puVar5 = puVar5 + 1;
        } while (iVar6 != 0);
      }
      puStack00000010 = puVar2;
      param_1 = param_1 + param_2;
      if (param_4 != (undefined2 *)0x0) {
        param_4 = param_4 + param_2;
      }
      iStack00000014 = iStack00000014 + -1;
    } while (iStack00000014 != 0);
  }
                    /* WARNING: Subroutine does not return */
  FUN_409da790(0x20);
}



/* 409d2948 FUN_409d2948 */

/* Boundary evidence: original MIPS .pdata 409d2948..409d2a77. Semantic name remains unreviewed. */

void FUN_409d2948(uint *param_1,int param_2,int param_3,undefined2 *param_4)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  undefined2 *puVar4;
  int iVar5;
  int iVar6;
  int iStack00000010;
  uint *puStack00000014;
  int iStack00000018;
  int iStack0000001c;
  int iStack00000020;
  int in_stack_00000060;
  int in_stack_00000064;
  int in_stack_00000068;
  int in_stack_0000006c;
  
  FUN_409da758();
  iStack00000010 = 0;
  iStack00000018 = in_stack_00000064;
  puStack00000014 = param_1;
  iStack0000001c = param_2;
  iStack00000020 = param_3;
  if (0 < in_stack_00000064) {
    iVar3 = param_2 << 2;
    do {
      iVar1 = iStack00000020;
      puStack00000014 = param_1;
      puVar4 = param_4;
      iVar5 = iStack00000010;
      iVar6 = in_stack_00000060;
      if (0 < in_stack_00000060) {
        do {
          uVar2 = FUN_409d1c4c(iVar1,iVar5,in_stack_00000068);
          iVar5 = iVar5 + 1;
          if ((in_stack_0000006c != 0) && (iVar3 = __nes(uVar2,0), iVar3 != 0)) {
            uVar2 = 0x3f800000;
          }
          iVar3 = __nes(*param_1,uVar2);
          if ((iVar3 != 0) && (*param_1 = uVar2, param_4 != (undefined2 *)0x0)) {
            uVar2 = FUN_409d2674(uVar2);
            *puVar4 = (short)uVar2;
          }
          param_1 = param_1 + 1;
          iVar6 = iVar6 + -1;
          iVar3 = param_2 << 2;
          puVar4 = puVar4 + 1;
        } while (iVar6 != 0);
      }
      iStack00000010 = iVar5;
      param_1 = (uint *)(iVar3 + (int)puStack00000014);
      if (param_4 != (undefined2 *)0x0) {
        param_4 = param_4 + iStack0000001c;
      }
      iStack00000018 = iStack00000018 + -1;
      iVar3 = iStack0000001c << 2;
      puStack00000014 = param_1;
    } while (iStack00000018 != 0);
  }
                    /* WARNING: Subroutine does not return */
  FUN_409da790(0x28);
}



/* 409d2a78 FUN_409d2a78 */

/* Boundary evidence: original MIPS .pdata 409d2a78..409d2acf. Semantic name remains unreviewed. */

void FUN_409d2a78(int param_1)

{
  uint uVar1;
  int iVar2;
  undefined2 *puVar3;
  uint *puVar4;
  
  FUN_409da7c8();
  iVar2 = *(int *)(param_1 + 0xb0);
  if (0 < iVar2) {
    puVar4 = *(uint **)(param_1 + 0xac);
    puVar3 = *(undefined2 **)(param_1 + 0x17c);
    if (0 < iVar2) {
      do {
        uVar1 = FUN_409d2674(*puVar4);
        puVar4 = puVar4 + 1;
        iVar2 = iVar2 + -1;
        *puVar3 = (short)uVar1;
        puVar3 = puVar3 + 1;
      } while (iVar2 != 0);
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_409da7e8(0x10);
}



/* 409d2ad0 FUN_409d2ad0 */

/* Boundary evidence: original MIPS .pdata 409d2ad0..409d2e3b. Semantic name remains unreviewed. */

void FUN_409d2ad0(int param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  uint *puVar8;
  undefined2 *puVar9;
  int iStack00000020;
  uint *puStack00000024;
  int in_stack_00000078;
  uint in_stack_0000007c;
  uint *in_stack_00000080;
  
  FUN_409da758();
  iStack00000020 = in_stack_00000078;
  if ((((-1 < in_stack_00000078) && (in_stack_0000007c != 0xffffffff)) && (param_1 != 0)) &&
     ((-1 < (int)in_stack_0000007c && (in_stack_0000007c < *(uint *)(param_1 + 0x13c))))) {
    iVar6 = *(int *)(param_1 + 0xac);
    piVar7 = (int *)(*(int *)(param_1 + 0x138) + in_stack_0000007c * 0x10);
    iVar5 = *piVar7;
    iVar2 = *(int *)(iVar5 + 0x30);
    if (iVar2 == 0) {
      if (in_stack_00000078 != 1) goto LAB_409d2e34;
      iVar2 = 1;
    }
    if (iVar2 <= in_stack_00000078) {
      in_stack_00000078 = iVar2;
    }
    iVar2 = *(int *)(iVar5 + 4);
    iStack00000020 = in_stack_00000078;
    if (((iVar2 == 5) || (iVar2 == 6)) || (iVar2 == 7)) {
      if ((((param_2 == 3) && (param_3 == 1)) && (param_4 == 1)) &&
         (iVar2 = 0, 0 < in_stack_00000078)) {
        do {
          iVar5 = piVar7[3] + iVar2;
          iVar2 = iVar2 + 1;
          prefetch(in_stack_00000080 + 2,0);
          *(uint *)(iVar5 * 0x10 + *(int *)(param_1 + 0xc) + 0xc) = *in_stack_00000080;
          in_stack_00000080 = in_stack_00000080 + 1;
        } while (iVar2 < in_stack_00000078);
      }
    }
    else if ((((param_2 == 3) || (iVar2 != 2)) && ((param_2 == 0 || ((iVar2 != 1 && (iVar2 != 4)))))
             ) && (param_3 == *(int *)(iVar5 + 0x1c))) {
      iVar3 = 1;
      if (iVar2 == 4) {
        iVar3 = param_3;
      }
      if (param_4 == iVar3) {
        puStack00000024 = in_stack_00000080;
        if (-1 < piVar7[1]) {
          iVar3 = *(int *)(iVar5 + 0x20);
          iVar4 = *(int *)(iVar5 + 0x28);
          puVar8 = (uint *)(piVar7[1] * 4 + *(int *)(param_1 + 0x68));
          if (0 < in_stack_00000078) {
            do {
              if ((iVar2 == 3) || (param_2 != 0)) {
                iVar1 = FUN_409d2948(puVar8,iVar3,(int)in_stack_00000080,(undefined2 *)0x0);
              }
              else {
                iVar1 = FUN_409d2870(puVar8,iVar3,in_stack_00000080,(undefined2 *)0x0);
              }
              if (iVar1 == 1) {
                *(undefined4 *)(param_1 + 0x70) = 1;
              }
              puVar8 = puVar8 + iVar4;
              in_stack_00000078 = in_stack_00000078 + -1;
              in_stack_00000080 = in_stack_00000080 + param_3 * param_4;
            } while (in_stack_00000078 != 0);
          }
        }
        iVar3 = piVar7[2];
        if (-1 < iVar3) {
          iVar4 = *(int *)(iVar5 + 0x24);
          iVar5 = *(int *)(iVar5 + 0x2c);
          puVar8 = (uint *)(iVar3 * 4 + iVar6);
          puVar9 = (undefined2 *)(iVar3 * 2 + *(int *)(param_1 + 0x17c));
          if (0 < iStack00000020) {
            iVar6 = iStack00000020;
            do {
              if ((iVar2 == 3) || (param_2 != 0)) {
                iVar3 = FUN_409d2948(puVar8,iVar4,(int)puStack00000024,puVar9);
              }
              else {
                iVar3 = FUN_409d2870(puVar8,iVar4,puStack00000024,puVar9);
              }
              if (iVar3 == 1) {
                *(undefined4 *)(param_1 + 0xb4) = 1;
              }
              puVar8 = puVar8 + iVar5;
              puVar9 = puVar9 + iVar5;
              puStack00000024 = puStack00000024 + param_3 * param_4;
              iVar6 = iVar6 + -1;
            } while (iVar6 != 0);
          }
        }
      }
    }
  }
LAB_409d2e34:
                    /* WARNING: Subroutine does not return */
  FUN_409da790(0x40);
}



/* 409d2e78 FUN_409d2e78 */

/* Boundary evidence: original MIPS .pdata 409d2e78..409d2f2f. Semantic name remains unreviewed. */

void FUN_409d2e78(undefined4 param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  undefined4 uVar2;
  
  FUN_409da688();
  if (param_4 != 0) {
    for (iVar1 = __mali_linked_list_get_first_entry(param_2 + 8);
        (iVar1 != 0 && (*(int *)(iVar1 + 8) != param_4));
        iVar1 = __mali_linked_list_get_next_entry(iVar1)) {
    }
    __mali_linked_list_remove_entry(param_2 + 8,iVar1);
    *(int *)(param_2 + 4) = *(int *)(param_2 + 4) + -1;
    mali_sys_atomic_dec_and_return(param_3 + 0x18);
    if ((*(char *)(param_3 + 4) == '\x01') &&
       (iVar1 = mali_sys_atomic_get(param_3 + 0x18), iVar1 == 0)) {
      FUN_409d0a3c(param_3);
      uVar2 = __mali_named_list_remove(param_1,param_4);
      mali_sys_free(uVar2);
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_409da6b0(0x10);
}



/* 409d2f38 FUN_409d2f38 */

/* Boundary evidence: original MIPS .pdata 409d2f38..409d2fc7. Semantic name remains unreviewed. */

void FUN_409d2f38(void)

{
  int iVar1;
  int iVar2;
  
  FUN_409da7c8();
  iVar1 = mali_sys_malloc(0x28);
  if (iVar1 != 0) {
    mali_sys_memset(iVar1,0,0x28);
    iVar2 = __mali_linked_list_init(iVar1 + 0x14);
    if (iVar2 == 0) {
      iVar2 = __mali_linked_list_init(iVar1 + 8);
      if (iVar2 == 0) {
        iVar2 = FUN_409bfe10();
        *(int *)(iVar1 + 0x20) = iVar2;
        if (iVar2 != 0) goto LAB_409d2fbc;
        __mali_linked_list_deinit(iVar1 + 8);
      }
      __mali_linked_list_deinit(iVar1 + 0x14);
    }
    mali_sys_free(iVar1);
  }
LAB_409d2fbc:
                    /* WARNING: Subroutine does not return */
  FUN_409da7e8(0x10);
}



/* 409d2fc8 FUN_409d2fc8 */

/* Boundary evidence: original MIPS .pdata 409d2fc8..409d302f. Semantic name remains unreviewed. */

undefined4 FUN_409d2fc8(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = __mali_linked_list_get_first_entry(param_1 + 8);
  while( true ) {
    if (iVar1 == 0) {
      return 0;
    }
    if (*(int *)(iVar1 + 8) == param_2) break;
    iVar1 = __mali_linked_list_get_next_entry(iVar1);
  }
  return 1;
}



/* 409d305c FUN_409d305c */

/* Boundary evidence: original MIPS .pdata 409d305c..409d3077. Semantic name remains unreviewed. */

void FUN_409d305c(int param_1)

{
  mali_sys_atomic_inc(param_1 + 0x180);
  return;
}



/* 409d3078 FUN_409d3078 */

/* Boundary evidence: original MIPS .pdata 409d3078..409d3093. Semantic name remains unreviewed. */

void FUN_409d3078(int param_1)

{
  mali_sys_atomic_inc(param_1 + 0x18);
  return;
}



/* 409d3094 FUN_409d3094 */

/* Boundary evidence: original MIPS .pdata 409d3094..409d30cf. Semantic name remains unreviewed. */

undefined4 FUN_409d3094(int param_1,uint param_2)

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



/* 409d30d0 FUN_409d30d0 */

/* Boundary evidence: original MIPS .pdata 409d30d0..409d3147. Semantic name remains unreviewed. */

undefined4 FUN_409d30d0(int param_1,uint param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  if (param_2 < 0x100) {
    puVar1 = *(undefined4 **)((param_2 + 7) * 4 + param_1);
  }
  else {
    puVar1 = (undefined4 *)__mali_named_list_get_non_flat();
  }
  if (puVar1 == (undefined4 *)0x0) {
    if (param_3 != (undefined4 *)0x0) {
      *param_3 = 0x501;
    }
    uVar2 = 0;
  }
  else {
    if (param_3 != (undefined4 *)0x0) {
      *param_3 = *puVar1;
    }
    uVar2 = puVar1[1];
  }
  return uVar2;
}



/* 409d3148 FUN_409d3148 */

/* Boundary evidence: original MIPS .pdata 409d3148..409d31bf. Semantic name remains unreviewed. */

void FUN_409d3148(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0x20);
  iVar1 = mali_sys_atomic_dec_and_return(iVar2 + 0x180);
  if (iVar1 == 0) {
    FUN_409bfd80(iVar2);
  }
  iVar1 = param_1 + 0x14;
  if (iVar1 != 0) {
    __mali_linked_list_empty(iVar1,FUN_409d14bc);
  }
  __mali_linked_list_deinit(iVar1);
  __mali_linked_list_deinit(param_1 + 8);
  mali_sys_free(param_1);
  return;
}



/* 409d31c0 FUN_409d31c0 */

/* Boundary evidence: original MIPS .pdata 409d31c0..409d3277. Semantic name remains unreviewed. */

void FUN_409d31c0(int param_1,uint param_2,int param_3,int *param_4,int param_5)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *in_stack_00000040;
  
  FUN_409da688();
  iVar2 = 0;
  if (((-1 < param_3) && (iVar1 = FUN_409d30d0(param_1,param_2,&param_5), param_5 != 0x501)) &&
     (param_5 == 1)) {
    iVar1 = __mali_linked_list_get_first_entry(iVar1 + 8);
    puVar3 = in_stack_00000040;
    for (; (iVar1 != 0 && (iVar2 < param_3)); iVar2 = iVar2 + 1) {
      if (in_stack_00000040 != (undefined4 *)0x0) {
        *puVar3 = *(undefined4 *)(iVar1 + 8);
      }
      puVar3 = puVar3 + 1;
      iVar1 = __mali_linked_list_get_next_entry(iVar1);
    }
    if (param_4 != (int *)0x0) {
      *param_4 = iVar2;
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_409da6b0(0x18);
}



/* 409d3278 FUN_409d3278 */

/* Boundary evidence: original MIPS .pdata 409d3278..409d33e7. Semantic name remains unreviewed. */

undefined4 FUN_409d3278(int param_1,uint param_2,undefined4 param_3,uint *param_4)

{
  byte *pbVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  int local_18 [2];
  
  if (param_2 == 0) {
    return 0x501;
  }
  pbVar1 = (byte *)FUN_409d30d0(param_1,param_2,local_18);
  if (local_18[0] == 0x501) {
    return 0x501;
  }
  if (local_18[0] != 1) {
    return 0x502;
  }
  if (param_4 == (uint *)0x0) {
    return 0;
  }
  switch(param_3) {
  case 0x8b80:
    *param_4 = (uint)*pbVar1;
    break;
  default:
    return 0x500;
  case 0x8b82:
    *param_4 = **(uint **)(pbVar1 + 0x20);
    break;
  case 0x8b83:
    *param_4 = (uint)pbVar1[1];
    break;
  case 0x8b84:
    bs_get_log_length(*(int *)(pbVar1 + 0x20) + 4,param_4);
    break;
  case 0x8b85:
    *param_4 = *(uint *)(pbVar1 + 4);
    break;
  case 0x8b86:
    uVar4 = *(undefined4 *)(*(int *)(pbVar1 + 0x20) + 0x14);
    goto LAB_409d3374;
  case 0x8b87:
    uVar4 = *(undefined4 *)(*(int *)(pbVar1 + 0x20) + 0x14);
    goto LAB_409d338c;
  case 0x8b89:
    uVar4 = *(undefined4 *)(*(int *)(pbVar1 + 0x20) + 0x18);
LAB_409d3374:
    uVar2 = bs_symbol_count_actives(uVar4,&PTR_DAT_409dd380,2);
    *param_4 = uVar2;
    break;
  case 0x8b8a:
    uVar4 = *(undefined4 *)(*(int *)(pbVar1 + 0x20) + 0x18);
LAB_409d338c:
    iVar3 = bs_symbol_longest_location_name_length(uVar4);
    *param_4 = iVar3 + 1;
  }
  return 0;
}



/* 409d33e8 FUN_409d33e8 */

/* Boundary evidence: original MIPS .pdata 409d33e8..409d346b. Semantic name remains unreviewed. */

undefined4 FUN_409d33e8(int param_1,uint param_2,int param_3,undefined4 param_4,undefined4 param_5)

{
  undefined4 uVar1;
  int iVar2;
  int local_18 [2];
  
  if (param_3 < 0) {
    uVar1 = 0x501;
  }
  else {
    iVar2 = FUN_409d30d0(param_1,param_2,local_18);
    uVar1 = 0x501;
    if (local_18[0] != 0x501) {
      if (local_18[0] == 1) {
        bs_get_log(*(int *)(iVar2 + 0x20) + 4,param_3,param_4,param_5);
        uVar1 = 0;
      }
      else {
        uVar1 = 0x502;
      }
    }
  }
  return uVar1;
}



/* 409d346c FUN_409d346c */

/* Boundary evidence: original MIPS .pdata 409d346c..409d35ef. Semantic name remains unreviewed. */

undefined4 FUN_409d346c(int param_1,uint param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  int *piVar4;
  int *piVar5;
  uint uVar6;
  uint uVar7;
  undefined4 *puVar8;
  int *piVar9;
  uint uVar10;
  int local_10 [2];
  
  iVar1 = FUN_409d30d0(param_1,param_2,local_10);
  uVar2 = 0x501;
  if (local_10[0] != 0x501) {
    if (local_10[0] == 1) {
      piVar4 = *(int **)(iVar1 + 0x20);
      *(undefined1 *)(iVar1 + 1) = 0;
      if (*piVar4 == 0) {
        bs_set_error(piVar4 + 1,"Validate: ","Program is not successfully linked");
LAB_409d34d4:
        iVar1 = bs_is_error_log_set_to_out_of_memory(*(int *)(iVar1 + 0x20) + 4);
        if (iVar1 != 0) {
          return 0x505;
        }
      }
      else {
        uVar7 = piVar4[4];
        uVar6 = 0;
        if (uVar7 != 0) {
          piVar5 = (int *)(piVar4[3] + 0xc);
          do {
            if (7 < *piVar5) {
              bs_set_program_validate_error_sampler_out_of_range
                        (piVar4,**(undefined4 **)(uVar6 * 0x10 + piVar4[3]),*piVar5,8);
              goto LAB_409d34d4;
            }
            uVar6 = uVar6 + 1;
            prefetch(piVar5 + 8,0);
            piVar5 = piVar5 + 4;
          } while (uVar6 < uVar7);
        }
        uVar6 = 0;
        if (uVar7 != 0) {
          piVar5 = (int *)piVar4[3];
          do {
            uVar10 = 0;
            puVar3 = (undefined4 *)*piVar5;
            piVar9 = (int *)piVar4[3];
            do {
              if (((uVar6 != uVar10) && (piVar5[3] == piVar9[3])) &&
                 ((puVar8 = (undefined4 *)*piVar9, puVar3[1] != puVar8[1] ||
                  (puVar3[7] != puVar8[7])))) {
                bs_set_program_validate_error_sampler_of_different_types_share_unit
                          (piVar4,*puVar3,*puVar8);
                goto LAB_409d34d4;
              }
              uVar10 = uVar10 + 1;
              prefetch(piVar9 + 0xb,0);
              piVar9 = piVar9 + 4;
            } while (uVar10 < uVar7);
            uVar6 = uVar6 + 1;
            piVar5 = piVar5 + 4;
          } while (uVar6 < uVar7);
        }
        *(undefined1 *)(iVar1 + 1) = 1;
      }
      uVar2 = 0;
    }
    else {
      uVar2 = 0x502;
    }
  }
  return uVar2;
}



/* 409d35f0 FUN_409d35f0 */

/* Boundary evidence: original MIPS .pdata 409d35f0..409d3697. Semantic name remains unreviewed. */

void FUN_409d35f0(int param_1,undefined4 param_2,uint param_3,uint param_4,int param_5,int param_6)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  FUN_409da688();
  iVar1 = FUN_409d30d0(param_1,param_3,&param_5);
  iVar2 = FUN_409d30d0(param_1,param_4,&param_6);
  if ((((param_5 != 0x501) && (param_5 == 1)) && (param_6 != 0x501)) &&
     ((param_6 == 0 && (iVar3 = FUN_409d2fc8(iVar1,param_4), iVar3 == 1)))) {
    FUN_409d2e78(param_1,iVar1,iVar2,param_4);
  }
                    /* WARNING: Subroutine does not return */
  FUN_409da6b0(0x18);
}



/* 409d3698 FUN_409d3698 */

/* Boundary evidence: original MIPS .pdata 409d3698..409d37e7. Semantic name remains unreviewed. */

undefined4 FUN_409d3698(int param_1,uint param_2,uint param_3)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  int local_28;
  int local_24;
  
  iVar1 = FUN_409d30d0(param_1,param_2,&local_28);
  piVar2 = (int *)FUN_409d30d0(param_1,param_3,&local_24);
  if (local_28 == 0x501) {
    return 0x501;
  }
  if (local_28 == 1) {
    if (local_24 == 0x501) {
      return 0x501;
    }
    if (local_24 == 0) {
      iVar5 = iVar1 + 8;
      for (iVar3 = __mali_linked_list_get_first_entry(iVar5); iVar3 != 0;
          iVar3 = __mali_linked_list_get_next_entry(iVar3)) {
        if (*(uint *)(iVar3 + 8) == param_3) {
          return 0x502;
        }
      }
      iVar3 = __mali_linked_list_get_first_entry(iVar5);
      while( true ) {
        if (iVar3 == 0) {
          iVar3 = __mali_linked_list_insert_data(iVar5,param_3);
          if (iVar3 != 0) {
            return 0x505;
          }
          mali_sys_atomic_inc(piVar2 + 6);
          *(int *)(iVar1 + 4) = *(int *)(iVar1 + 4) + 1;
          return 0;
        }
        piVar4 = (int *)FUN_409d30d0(param_1,*(uint *)(iVar3 + 8),&local_24);
        if (*piVar4 == *piVar2) break;
        iVar3 = __mali_linked_list_get_next_entry(iVar3);
      }
    }
  }
  return 0x502;
}



/* 409d37e8 FUN_409d37e8 */

/* Boundary evidence: original MIPS .pdata 409d37e8..409d381b. Semantic name remains unreviewed. */

bool FUN_409d37e8(int param_1,uint param_2)

{
  int local_10 [2];
  
  FUN_409d30d0(param_1,param_2,local_10);
  return local_10[0] == 1;
}



/* 409d381c FUN_409d381c */

/* Boundary evidence: original MIPS .pdata 409d381c..409d388f. Semantic name remains unreviewed. */

void FUN_409d381c(int *param_1)

{
  int iVar1;
  
  if (*param_1 == 0) {
    iVar1 = param_1[1];
    mali_sys_atomic_set(iVar1 + 0x18,0);
    FUN_409d0a3c(iVar1);
  }
  else if (*param_1 == 1) {
    iVar1 = param_1[1];
    *(undefined4 *)(iVar1 + 4) = 0;
    FUN_409d3148(iVar1);
  }
  mali_sys_free(param_1);
  return;
}



/* 409d3890 FUN_409d3890 */

/* Boundary evidence: original MIPS .pdata 409d3890..409d39af. Semantic name remains unreviewed. */

undefined4 FUN_409d3890(int param_1,uint param_2)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  undefined1 *puVar4;
  
  if (param_2 != 0) {
    if (param_2 < 0x100) {
      piVar3 = *(int **)((param_2 + 7) * 4 + param_1);
    }
    else {
      piVar3 = (int *)__mali_named_list_get_non_flat(param_1,param_2);
    }
    if (piVar3 == (int *)0x0) {
      return 0x501;
    }
    if (*piVar3 != 1) {
      return 0x502;
    }
    puVar4 = (undefined1 *)piVar3[1];
    if (*(int *)(puVar4 + 0x24) == 0) {
      while (iVar2 = __mali_linked_list_get_first_entry(puVar4 + 8), iVar2 != 0) {
        iVar1 = FUN_409d30d0(param_1,*(uint *)(iVar2 + 8),(undefined4 *)0x0);
        FUN_409d2e78(param_1,(int)puVar4,iVar1,*(int *)(iVar2 + 8));
      }
      mali_sys_free(piVar3);
      FUN_409d3148((int)puVar4);
      __mali_named_list_remove(param_1,param_2);
    }
    else {
      *puVar4 = 1;
    }
  }
  return 0;
}



/* 409d39b0 FUN_409d39b0 */

/* Boundary evidence: original MIPS .pdata 409d39b0..409d3a5b. Semantic name remains unreviewed. */

void FUN_409d39b0(undefined4 param_1,int *param_2)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  
  FUN_409da688();
  *param_2 = 0;
  iVar1 = FUN_409d2f38();
  if (iVar1 != 0) {
    puVar2 = (undefined4 *)mali_sys_malloc(8);
    if (puVar2 != (undefined4 *)0x0) {
      *puVar2 = 1;
      puVar2[1] = iVar1;
      iVar3 = __mali_named_list_get_unused_name(param_1);
      if ((iVar3 != 0) && (iVar4 = __mali_named_list_insert(param_1,iVar3,puVar2), iVar4 == 0)) {
        *param_2 = iVar3;
        goto LAB_409d3a54;
      }
      mali_sys_free(puVar2);
    }
    FUN_409d3148(iVar1);
  }
LAB_409d3a54:
                    /* WARNING: Subroutine does not return */
  FUN_409da6b0(0x10);
}



/* 409d3a5c FUN_409d3a5c */

/* Boundary evidence: original MIPS .pdata 409d3a5c..409d3bdb. Semantic name remains unreviewed. */

undefined4 FUN_409d3a5c(int param_1,int param_2,uint param_3)

{
  int iVar1;
  undefined4 uVar2;
  char *pcVar3;
  uint uVar4;
  int *piVar5;
  int iVar6;
  int iVar7;
  
  iVar7 = *(int *)(param_1 + 0x4cc);
  uVar4 = *(uint *)(iVar7 + 0xc);
  iVar6 = *(int *)(param_1 + 0x4c8);
  if (param_3 == 0) {
    piVar5 = (int *)0x0;
LAB_409d3b24:
    if ((iVar6 != 0) && (iVar1 = mali_sys_atomic_dec_and_return(iVar6 + 0x180), iVar1 == 0)) {
      FUN_409bfd80(iVar6);
    }
    *(uint *)(iVar7 + 0xc) = param_3;
    *(int **)(param_1 + 0x4c8) = piVar5;
    if (uVar4 != 0) {
      if (uVar4 < 0x100) {
        iVar6 = *(int *)((uVar4 + 7) * 4 + param_2);
      }
      else {
        iVar6 = __mali_named_list_get_non_flat(param_2,uVar4);
      }
      pcVar3 = *(char **)(iVar6 + 4);
      iVar6 = *(int *)(pcVar3 + 0x24);
      *(int *)(pcVar3 + 0x24) = iVar6 + -1;
      if ((*pcVar3 == '\x01') && (iVar6 + -1 == 0)) {
        FUN_409d3890(param_2,uVar4);
      }
    }
    uVar2 = 0;
  }
  else {
    if (param_3 < 0x100) {
      piVar5 = *(int **)((param_3 + 7) * 4 + param_2);
    }
    else {
      piVar5 = (int *)__mali_named_list_get_non_flat(param_2,param_3);
    }
    if (piVar5 == (int *)0x0) {
      return 0x501;
    }
    if (*piVar5 == 1) {
      iVar1 = piVar5[1];
      piVar5 = *(int **)(iVar1 + 0x20);
      if (*piVar5 == 1) {
        *(int *)(iVar1 + 0x24) = *(int *)(iVar1 + 0x24) + 1;
        mali_sys_atomic_inc(piVar5 + 0x60);
        goto LAB_409d3b24;
      }
    }
    uVar2 = 0x502;
  }
  return uVar2;
}



/* 409d3bdc FUN_409d3bdc */

/* Boundary evidence: original MIPS .pdata 409d3bdc..409d3e77. Semantic name remains unreviewed. */

void FUN_409d3bdc(undefined4 *param_1,int param_2,uint param_3,undefined4 param_4,int param_5)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  int *piVar6;
  char *pcVar7;
  char *pcVar8;
  int iVar9;
  undefined4 uVar10;
  
  FUN_409da758();
  uVar10 = *param_1;
  iVar1 = FUN_409d30d0(param_2,param_3,&param_5);
  if (((param_5 == 0x501) || (param_5 != 1)) ||
     (puVar2 = (undefined4 *)FUN_409bfe10(), puVar2 == (undefined4 *)0x0)) goto LAB_409d3e70;
  iVar9 = *(int *)(iVar1 + 0x20);
  iVar3 = mali_sys_atomic_dec_and_return(iVar9 + 0x180);
  if (iVar3 == 0) {
    FUN_409bfd80(iVar9);
  }
  *(undefined4 **)(iVar1 + 0x20) = puVar2;
  if (*(int *)(iVar1 + 4) == 0) {
    pcVar8 = "A program cannot be linked unless there are any shaders attached to it";
    pcVar7 = "L0100";
  }
  else if (*(int *)(iVar1 + 4) == 2) {
    piVar4 = (int *)FUN_409d30d0(param_2,*(uint *)(*(int *)(iVar1 + 8) + 8),(undefined4 *)0x0);
    if (*piVar4 == 0x8b30) {
      piVar5 = (int *)FUN_409d30d0(param_2,*(uint *)(**(int **)(iVar1 + 8) + 8),(undefined4 *)0x0);
      piVar6 = piVar4;
      piVar4 = piVar5;
    }
    else {
      piVar6 = (int *)FUN_409d30d0(param_2,*(uint *)(**(int **)(iVar1 + 8) + 8),(undefined4 *)0x0);
    }
    if ((*piVar4 == 0x8b31) && (*piVar6 == 0x8b30)) {
      if ((piVar4[7] == 1) && (piVar6[7] == 1)) {
        iVar3 = __mali_link_binary_shaders(uVar10,puVar2);
        if (iVar3 == 0) {
          iVar3 = FUN_409d17dc(iVar1);
          if (iVar3 == 0) {
            FUN_409d1e14(iVar1);
            iVar1 = FUN_409d208c(iVar1);
            if (iVar1 == 0) {
              iVar1 = FUN_409b69c8((int)puVar2);
              puVar2[0x5d] = iVar1;
              if (iVar1 != 0) {
                piVar4 = FUN_409b6018((int)puVar2);
                puVar2[0x5e] = piVar4;
                if (piVar4 != (int *)0x0) {
                  if ((*(uint *)(param_1[0x136] + 0xc) == param_3) &&
                     (iVar1 = FUN_409d3a5c((int)(param_1 + 3),param_2,param_3), iVar1 != 0))
                  goto LAB_409d3e70;
                  iVar1 = FUN_409d2130((int)puVar2);
                  if (iVar1 == 0) {
                    FUN_409d2a78((int)puVar2);
                    goto LAB_409d3e70;
                  }
                }
              }
            }
            *puVar2 = 0;
          }
          else {
            *puVar2 = 0;
          }
        }
        goto LAB_409d3e70;
      }
      pcVar8 = "All attached shaders must be compiled prior to linking";
      pcVar7 = "L0101";
    }
    else {
      pcVar8 = "A linked program must contain exactly one of each type of shader";
      pcVar7 = "L0100";
    }
  }
  else {
    pcVar8 = "GLSL allows exactly two attached shaders (one of each type) per program";
    pcVar7 = "L0100";
  }
  bs_set_error(puVar2 + 1,pcVar7,pcVar8);
  bs_is_error_log_set_to_out_of_memory(puVar2 + 1);
LAB_409d3e70:
                    /* WARNING: Subroutine does not return */
  FUN_409da790(0x18);
}



/* 409d3f28 FUN_409d3f28 */

/* Boundary evidence: original MIPS .pdata 409d3f28..409d3f43. Semantic name remains unreviewed. */

void FUN_409d3f28(int param_1)

{
  mali_sys_atomic_inc(param_1 + 0x50);
  return;
}



/* 409d3f44 FUN_409d3f44 */

/* Boundary evidence: original MIPS .pdata 409d3f44..409d3f7f. Semantic name remains unreviewed. */

undefined4 FUN_409d3f44(int param_1,uint param_2)

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



/* 409d3fa4 FUN_409d3fa4 */

undefined4 FUN_409d3fa4(uint param_1)

{
  if (param_1 != 0x8513) {
    if ((0x8514 < param_1) && (param_1 < 0x851b)) {
      return 1;
    }
    if (param_1 == 0xde1) {
      return 0;
    }
  }
  return 0xffffffff;
}



/* 409d3ff0 FUN_409d3ff0 */

/* Boundary evidence: original MIPS .pdata 409d3ff0..409d40ab. Semantic name remains unreviewed. */

int FUN_409d3ff0(int param_1,uint param_2,int param_3)

{
  int iVar1;
  int in_stack_0000001c;
  int local_20 [2];
  
  local_20[0] = 0;
  iVar1 = FUN_409ccb6c(param_2,(int *)(param_1 + 0x328),local_20);
  if (iVar1 == 0) {
    if (in_stack_0000001c == 0x8d64) {
      iVar1 = FUN_409c74e8(local_20[0],param_1,param_2,param_3);
    }
    else {
      iVar1 = 0x501;
    }
  }
  return iVar1;
}



/* 409d40ac FUN_409d40ac */

/* Boundary evidence: original MIPS .pdata 409d40ac..409d4123. Semantic name remains unreviewed. */

undefined4 FUN_409d40ac(undefined4 *param_1,int param_2,undefined4 param_3)

{
  undefined4 uVar1;
  int local_18 [2];
  
  local_18[0] = 0;
  if (param_2 == 0xde1) {
    FUN_409ccb6c(0xde1,param_1 + 0xca,local_18);
    if (*(int *)(local_18[0] + 0x34) == 0) {
      uVar1 = 0x505;
    }
    else {
      uVar1 = FUN_409c7c04(local_18[0],param_1,0xde1,param_3);
    }
  }
  else {
    uVar1 = 0x500;
  }
  return uVar1;
}



/* 409d4124 FUN_409d4124 */

/* Boundary evidence: original MIPS .pdata 409d4124..409d41db. Semantic name remains unreviewed. */

int FUN_409d4124(undefined4 *param_1,uint param_2,uint param_3,int param_4,undefined4 param_5,
                undefined4 param_6,int param_7)

{
  int iVar1;
  int local_20 [2];
  
  local_20[0] = 0;
  iVar1 = FUN_409ccb6c(param_2,param_1 + 0xca,local_20);
  if (iVar1 == 0) {
    if ((param_4 == 0x8d64) && (param_7 == 0)) {
      iVar1 = FUN_409c7ea4(local_20[0],param_1,param_2,param_3);
    }
    else {
      iVar1 = 0x501;
    }
  }
  return iVar1;
}



/* 409d41dc FUN_409d41dc */

/* Boundary evidence: original MIPS .pdata 409d41dc..409d42f7. Semantic name remains unreviewed. */

undefined4 FUN_409d41dc(int param_1,int param_2,uint param_3)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int local_28;
  uint local_24;
  
  local_28 = 0;
  if (param_2 == 0xde1) {
    iVar3 = 0;
  }
  else {
    if (param_2 != 0x8513) {
      return 0x500;
    }
    iVar3 = 1;
  }
  FUN_409cc82c((int *)(param_1 + 0x328),param_2,(int *)&local_24,&local_28);
  iVar1 = local_28;
  if ((local_24 != param_3) || (*(int *)(local_28 + 0x44) != 0)) {
    piVar2 = (int *)FUN_409c88f4(param_1,param_3,iVar3);
    if (piVar2 == (int *)0x0) {
      return 0x505;
    }
    if (*piVar2 != iVar3) {
      return 0x502;
    }
    FUN_409cc7cc((int *)(param_1 + 0x328),param_2,param_3,(int)piVar2);
    mali_sys_atomic_inc(piVar2 + 0x14);
    iVar3 = mali_sys_atomic_dec_and_return(iVar1 + 0x50);
    if (iVar3 == 0) {
      FUN_409c7b60(iVar1);
    }
  }
  return 0;
}



/* 409d42f8 FUN_409d42f8 */

/* Boundary evidence: original MIPS .pdata 409d42f8..409d4397. Semantic name remains unreviewed. */

void FUN_409d42f8(undefined4 *param_1,uint param_2,int param_3)

{
  int iVar1;
  int local_20 [2];
  
  local_20[0] = 0;
  iVar1 = FUN_409ccb6c(param_2,param_1 + 0xca,local_20);
  if (iVar1 == 0) {
    FUN_409c8ab0(local_20[0],param_1,param_2,param_3);
  }
  return;
}



/* 409d4398 FUN_409d4398 */

/* Boundary evidence: original MIPS .pdata 409d4398..409d4437. Semantic name remains unreviewed. */

void FUN_409d4398(undefined4 *param_1,uint param_2,uint param_3)

{
  int iVar1;
  int local_20 [2];
  
  local_20[0] = 0;
  iVar1 = FUN_409ccb6c(param_2,param_1 + 0xca,local_20);
  if (iVar1 == 0) {
    FUN_409c8d6c(local_20[0],param_1,param_2,param_3);
  }
  return;
}



/* 409d4438 FUN_409d4438 */

/* Boundary evidence: original MIPS .pdata 409d4438..409d44e7. Semantic name remains unreviewed. */

void FUN_409d4438(undefined4 *param_1,uint param_2,int param_3)

{
  int iVar1;
  int local_20 [2];
  
  local_20[0] = 0;
  iVar1 = FUN_409ccb6c(param_2,param_1 + 0xca,local_20);
  if (iVar1 == 0) {
    FUN_409c9020(local_20[0],param_1,param_2,param_3);
  }
  return;
}



/* 409d44e8 FUN_409d44e8 */

/* Boundary evidence: original MIPS .pdata 409d44e8..409d4603. Semantic name remains unreviewed. */

int FUN_409d44e8(undefined4 *param_1,uint param_2,uint param_3,undefined4 param_4,uint param_5,
                uint param_6,undefined4 param_7,int param_8,int param_9,undefined4 param_10,
                int param_11)

{
  int iVar1;
  int local_30 [2];
  
  local_30[0] = 0;
  if (((int)param_3 < 1) ||
     (((param_5 == 0 || ((param_5 - 1 & param_5) == 0)) &&
      ((param_6 == 0 || ((param_6 - 1 & param_6) == 0)))))) {
    iVar1 = FUN_409ccb6c(param_2,param_1 + 0xca,local_30);
    if (iVar1 == 0) {
      FUN_409c6a98(param_11,param_5,param_8,param_9);
      iVar1 = FUN_409c91c8(local_30[0],param_1,param_2,param_3);
    }
  }
  else {
    iVar1 = 0x501;
  }
  return iVar1;
}



/* 409d4604 FUN_409d4604 */

/* Boundary evidence: original MIPS .pdata 409d4604..409d476f. Semantic name remains unreviewed. */

undefined4 FUN_409d4604(int param_1,int param_2,uint *param_3)

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
                FUN_409ccfe8(param_1 + 0x328,uVar4,(int *)(param_1 + 0x4dc));
                if ((*(int *)(param_1 + 0x488) != 0) &&
                   (*(int *)(*(int *)(param_1 + 0x4e8) + 0x10) != 0)) {
                  FUN_409be530(*(int *)(param_1 + 0x484),*(int *)(iVar3 + 4));
                }
                if (*(int *)(iVar3 + 4) != 0) {
                  *(undefined4 *)(*(int *)(iVar3 + 4) + 0x44) = 1;
                }
                iVar5 = *(int *)(iVar3 + 4);
                iVar2 = mali_sys_atomic_dec_and_return(iVar5 + 0x50);
                if (iVar2 == 0) {
                  FUN_409c7b60(iVar5);
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



/* 409d4770 gles2_unbind_tex_image */

/* Boundary evidence: original MIPS .pdata 409d4770..409d482b. Semantic name remains unreviewed.
   gles2_unbind_tex_image */

void gles2_unbind_tex_image(undefined4 *param_1)

{
  int iVar1;
  int local_1c;
  
                    /* 0x24770  6  _gles2_unbind_tex_image */
  local_1c = 0;
  iVar1 = FUN_409ccb6c(0xde1,param_1 + 0xca,&local_1c);
  if (iVar1 == 0) {
    FUN_409c6a98(8,1,0x1907,0x1401);
    FUN_409c91c8(local_1c,param_1,0xde1,0);
  }
  return;
}



/* 409d482c gles2_bind_tex_image */

/* Boundary evidence: original MIPS .pdata 409d482c..409d4967. Semantic name remains unreviewed.
   gles2_bind_tex_image */

int gles2_bind_tex_image
              (undefined4 *param_1,uint param_2,uint param_3,undefined4 param_4,undefined4 param_5,
              int param_6)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int local_20 [2];
  
                    /* 0x2482c  2  _gles2_bind_tex_image */
  local_20[0] = 0;
  iVar1 = FUN_409ccb6c(param_2,param_1 + 0xca,local_20);
  if (iVar1 == 0) {
    if ((((((-1 < (int)param_3) && ((int)param_3 < 0xd)) &&
          (uVar2 = (uint)*(ushort *)(param_6 + 0xc), uVar2 < 0x1001)) &&
         ((uVar3 = (uint)*(ushort *)(param_6 + 0xe), uVar3 < 0x1001 &&
          ((int)(uVar2 << (param_3 & 0x1f)) < 0x1001)))) &&
        ((int)(uVar3 << (param_3 & 0x1f)) < 0x1001)) &&
       (((int)param_3 < 1 ||
        (((uVar2 == 0 || ((uVar2 - 1 & uVar2) == 0)) && ((uVar3 == 0 || ((uVar3 - 1 & uVar3) == 0)))
         ))))) {
      if (*(int *)(local_20[0] + 0x34) == 0) {
        return 0x505;
      }
      iVar1 = FUN_409c9324(local_20[0],param_1,param_2,param_3);
      return iVar1;
    }
    iVar1 = 0x501;
  }
  return iVar1;
}



/* 409d4968 FUN_409d4968 */

/* Boundary evidence: original MIPS .pdata 409d4968..409d4a6b. Semantic name remains unreviewed. */

undefined4 FUN_409d4968(int param_1,int *param_2,int param_3)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  int *piVar6;
  int iVar7;
  
  iVar7 = 0;
  piVar6 = (int *)(param_1 + 0x1c);
  do {
    if ((char)piVar6[-2] == '\x01') {
      if (piVar6[4] == 0) {
        if (piVar6[3] == 0) {
          return 0xfffffffe;
        }
      }
      else {
        iVar2 = FUN_409c33ec(piVar6[1]);
        uVar1 = piVar6[-1] * iVar2;
        iVar2 = *piVar6;
        uVar4 = piVar6[3];
        uVar5 = *(uint *)(piVar6[5] + 4);
        if (uVar5 < iVar2 * *param_2 + uVar1 + uVar4) {
          if (param_3 != 0) {
            return 0xfffffffe;
          }
          iVar3 = -(uint)(uVar5 - uVar1 < uVar4) - (uint)(uVar5 < uVar1);
          if (iVar3 < 0) {
            return 0xfffffffe;
          }
          iVar2 = __ll_div((uVar5 - uVar1) - uVar4,iVar3,iVar2,iVar2 >> 0x1f);
          *param_2 = iVar2;
        }
      }
    }
    iVar7 = iVar7 + 1;
    piVar6 = piVar6 + 0xc;
    if (0xf < iVar7) {
      return 0;
    }
  } while( true );
}



/* 409d4a98 FUN_409d4a98 */

/* Boundary evidence: original MIPS .pdata 409d4a98..409d4b6b. Semantic name remains unreviewed. */

int FUN_409d4a98(undefined4 *param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  
  if (param_1[0x122] == 0) {
    piVar2 = param_1 + 0x134;
  }
  else {
    piVar2 = (int *)(param_1[0x121] + 0x84);
  }
  if (param_2 == 0) {
    if (*piVar2 != 1) {
      return 0;
    }
    iVar1 = FUN_409c59f4(param_1);
    if (iVar1 != 0) {
      return iVar1;
    }
    iVar1 = FUN_409b6460(param_1);
    if (iVar1 != 0) {
      return iVar1;
    }
    if (param_1[0x144] != 0) {
      FUN_409c12e8(param_1[0x144]);
    }
    mali_frame_builder_write_unlock(param_1[0x13d]);
    *piVar2 = 0;
  }
  if (((param_2 == 4) || (param_2 == 5)) || (param_2 == 6)) {
    *piVar2 = 1;
  }
  return 0;
}



/* 409d4b6c FUN_409d4b6c */

/* Boundary evidence: original MIPS .pdata 409d4b6c..409d4dbb. Semantic name remains unreviewed. */

int FUN_409d4b6c(undefined4 *param_1,uint param_2,uint param_3,uint param_4)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int local_30;
  int local_2c;
  
  local_30 = 0;
  local_2c = 0;
  iVar4 = param_1[0x136];
  iVar2 = FUN_409c1a18(param_2,param_3);
  if (iVar2 != 0) {
    return iVar2;
  }
  if ((param_4 != 0x1401) && (param_4 != 0x1403)) {
    return 0x500;
  }
  uVar3 = FUN_409c1808(param_2,param_3);
  if ((uVar3 != 0) && (*(int *)(iVar4 + 0xc) != 0)) {
    if ((param_1[0x122] != 0) && (iVar2 = FUN_409bddac((int)param_1), iVar2 != 0)) {
      return iVar2;
    }
    iVar2 = FUN_409d4a98(param_1,param_2);
    if ((iVar2 == 0) && (iVar2 = FUN_409c59f4(param_1), iVar2 == 0)) {
      iVar2 = FUN_409c1cac((int)param_1,uVar3,param_4,param_2);
      if (iVar2 == 0) {
        iVar2 = FUN_409d4968((int)param_1,&local_30,1);
        iVar1 = local_2c;
        iVar4 = local_30;
        if (iVar2 != 0) {
          if (param_1[0x144] != 0) {
            FUN_409c12e8(param_1[0x144]);
          }
          mali_frame_builder_write_unlock(param_1[0x13d]);
          return 0;
        }
        iVar2 = FUN_409b8800(param_1,local_2c,local_30,param_2);
        if (iVar2 == 0) {
          if (param_1[0x122] != 0) {
            FUN_409bc9ec((int)param_1);
          }
          iVar2 = FUN_409b5880(param_1,param_2,iVar1,iVar4);
        }
      }
      if (param_1[0x144] != 0) {
        FUN_409c12e8(param_1[0x144]);
      }
      mali_frame_builder_write_unlock(param_1[0x13d]);
    }
    if (((iVar2 != -3) && (-3 < iVar2)) && (iVar2 < 0)) {
      return 0x505;
    }
  }
  return 0;
}



/* 409d4dbc FUN_409d4dbc */

/* Boundary evidence: original MIPS .pdata 409d4dbc..409d4f97. Semantic name remains unreviewed. */

int FUN_409d4dbc(undefined4 *param_1,uint param_2,int param_3,uint param_4)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int local_28 [2];
  
  iVar4 = param_1[0x136];
  iVar1 = FUN_409c1a18(param_2,param_4);
  if (iVar1 == 0) {
    if (param_3 < 0) {
      iVar1 = 0x501;
    }
    else {
      uVar2 = FUN_409c1808(param_2,param_4);
      if (((uVar2 != 0) && (local_28[0] = param_3 + uVar2 + -1, *(int *)(iVar4 + 0xc) != 0)) &&
         (iVar4 = FUN_409d4968((int)param_1,local_28,0), iVar1 = local_28[0], iVar4 == 0)) {
        iVar4 = local_28[0] - param_3;
        if ((param_1[0x122] != 0) && (iVar3 = FUN_409bddac((int)param_1), iVar3 != 0)) {
          return iVar3;
        }
        iVar3 = FUN_409d4a98(param_1,param_2);
        if ((iVar3 == 0) && (iVar3 = FUN_409c59f4(param_1), iVar3 == 0)) {
          iVar3 = FUN_409c1c4c((int)param_1,param_2);
          if ((iVar3 == 0) && (iVar3 = FUN_409b8800(param_1,param_3,iVar1,param_2), iVar3 == 0)) {
            if (param_1[0x122] != 0) {
              FUN_409bc9ec((int)param_1);
            }
            iVar3 = FUN_409b59a8(param_1,param_2,param_3,iVar4 + 1);
          }
          if (param_1[0x144] != 0) {
            FUN_409c12e8(param_1[0x144]);
          }
          mali_frame_builder_write_unlock(param_1[0x13d]);
        }
        if (((iVar3 != -3) && (-3 < iVar3)) && (iVar3 < 0)) {
          return 0x505;
        }
      }
      iVar1 = 0;
    }
  }
  return iVar1;
}



/* 409d4f98 gles2_get_proc_address */

/* Boundary evidence: original MIPS .pdata 409d4f98..409d4fbb. Semantic name remains unreviewed.
   gles2_get_proc_address */

void gles2_get_proc_address(int param_1)

{
                    /* 0x24f98  5  _gles2_get_proc_address */
  FUN_409c45c4(param_1);
  return;
}



/* 409d5080 FUN_409d5080 */

uint FUN_409d5080(uint param_1)

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



/* 409d5200 FUN_409d5200 */

/* Boundary evidence: original MIPS .pdata 409d5200..409d5317. Semantic name remains unreviewed. */

undefined4 FUN_409d5200(int param_1)

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
    goto LAB_409d52d4;
  }
  if (iVar3 != -0x48) {
    if (*(int *)(iVar3 + 0x50) == 0x1702) {
      iVar1 = FUN_409c682c(*(int *)(iVar3 + 100));
      piVar4 = *(int **)((iVar1 * 0xd + *(int *)(iVar3 + 0x60)) * 4 +
                        *(int *)(*(int *)(iVar3 + 0x58) + 0x34));
      if (piVar4 != (int *)0x0) {
        iVar3 = *piVar4;
        goto LAB_409d528c;
      }
    }
    else if (*(int *)(iVar3 + 0x50) == 0x8d41) {
      iVar3 = *(int *)(*(int *)(iVar3 + 0x58) + 0x28);
LAB_409d528c:
      if (iVar3 != 0) {
        mali_pixel_format_get_bpc
                  (*(undefined4 *)(iVar3 + 0x14),auStack_14,auStack_18,auStack_1c,auStack_20,
                   auStack_24,&local_28);
        goto LAB_409d52d4;
      }
    }
  }
  local_28 = 0;
LAB_409d52d4:
  uVar2 = 1;
  if (((*(uint *)(*(int *)(param_1 + 0x504) + 0x40) & 0x10) == 0) || (local_28 < 1)) {
    uVar2 = 0;
  }
  return uVar2;
}



/* 409d5318 FUN_409d5318 */

/* Boundary evidence: original MIPS .pdata 409d5318..409d542f. Semantic name remains unreviewed. */

undefined4 FUN_409d5318(int param_1)

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
    goto LAB_409d53ec;
  }
  if (iVar3 != -0x24) {
    if (*(int *)(iVar3 + 0x2c) == 0x1702) {
      iVar1 = FUN_409c682c(*(int *)(iVar3 + 0x40));
      piVar4 = *(int **)((iVar1 * 0xd + *(int *)(iVar3 + 0x3c)) * 4 +
                        *(int *)(*(int *)(iVar3 + 0x34) + 0x34));
      if (piVar4 != (int *)0x0) {
        iVar3 = *piVar4;
        goto LAB_409d53a4;
      }
    }
    else if (*(int *)(iVar3 + 0x2c) == 0x8d41) {
      iVar3 = *(int *)(*(int *)(iVar3 + 0x34) + 0x28);
LAB_409d53a4:
      if (iVar3 != 0) {
        mali_pixel_format_get_bpc
                  (*(undefined4 *)(iVar3 + 0x14),auStack_14,auStack_18,auStack_1c,auStack_20,
                   &local_28,auStack_24);
        goto LAB_409d53ec;
      }
    }
  }
  local_28 = 0;
LAB_409d53ec:
  uVar2 = 1;
  if (((*(uint *)(*(int *)(param_1 + 0x504) + 0x40) & 2) == 0) || (local_28 < 1)) {
    uVar2 = 0;
  }
  return uVar2;
}



/* 409d5430 FUN_409d5430 */

/* Boundary evidence: original MIPS .pdata 409d5430..409d549b. Semantic name remains unreviewed. */

void FUN_409d5430(int param_1)

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



/* 409d54c0 FUN_409d54c0 */

void FUN_409d54c0(int param_1,uint param_2,int param_3)

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



/* 409d5564 FUN_409d5564 */

void FUN_409d5564(int param_1)

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



/* 409d5614 FUN_409d5614 */

/* Boundary evidence: original MIPS .pdata 409d5614..409d566f. Semantic name remains unreviewed. */

void FUN_409d5614(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = *(int *)(param_1 + 0x504);
  iVar2 = 0xff;
  *(undefined1 *)(iVar3 + 0x59) = 0xff;
  iVar1 = FUN_409d5200(param_1);
  if (iVar1 == 0) {
    iVar2 = 0;
  }
  *(uint *)(iVar3 + 0x1c) = iVar2 << 8 ^ *(uint *)(iVar3 + 0x1c) & 0xffff00ff;
  return;
}



/* 409d5670 FUN_409d5670 */

/* Boundary evidence: original MIPS .pdata 409d5670..409d56c7. Semantic name remains unreviewed. */

void FUN_409d5670(int param_1)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  
  iVar3 = *(int *)(param_1 + 0x504);
  uVar2 = 0xff;
  *(undefined1 *)(iVar3 + 0x52) = 0xff;
  iVar1 = FUN_409d5200(param_1);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  *(uint *)(iVar3 + 0x1c) = *(uint *)(iVar3 + 0x1c) & 0xffffff00 ^ uVar2;
  return;
}



/* 409d56c8 FUN_409d56c8 */

/* Boundary evidence: original MIPS .pdata 409d56c8..409d570b. Semantic name remains unreviewed. */

void FUN_409d56c8(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x504);
  *(undefined1 *)(iVar1 + 0x5a) = 0;
  *(undefined1 *)(iVar1 + 0x5b) = 0;
  *(undefined1 *)(iVar1 + 0x5c) = 0;
  FUN_409d5200(param_1);
  *(uint *)(iVar1 + 0x18) = *(uint *)(iVar1 + 0x18) & 0xfffff007;
  return;
}



/* 409d570c FUN_409d570c */

/* Boundary evidence: original MIPS .pdata 409d570c..409d574f. Semantic name remains unreviewed. */

void FUN_409d570c(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x504);
  *(undefined1 *)(iVar1 + 0x53) = 0;
  *(undefined1 *)(iVar1 + 0x54) = 0;
  *(undefined1 *)(iVar1 + 0x55) = 0;
  FUN_409d5200(param_1);
  *(uint *)(iVar1 + 0x14) = *(uint *)(iVar1 + 0x14) & 0xfffff007;
  return;
}



/* 409d5750 FUN_409d5750 */

/* Boundary evidence: original MIPS .pdata 409d5750..409d57bf. Semantic name remains unreviewed. */

void FUN_409d5750(int param_1)

{
  uint uVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0x504);
  *(undefined4 *)(iVar2 + 0x88) = 0;
  *(undefined1 *)(iVar2 + 0x56) = 7;
  *(undefined1 *)(iVar2 + 0x57) = 0;
  *(undefined1 *)(iVar2 + 0x58) = 0;
  FUN_409d5200(param_1);
  uVar1 = *(uint *)(iVar2 + 0x18) & 0xff00fff8 ^ 7;
  *(uint *)(iVar2 + 0x18) = uVar1;
  *(uint *)(iVar2 + 0x18) = uVar1 & 0xffffff ^ (uint)*(byte *)(iVar2 + 0x51) << 0x18;
  return;
}



/* 409d57c0 FUN_409d57c0 */

/* Boundary evidence: original MIPS .pdata 409d57c0..409d582f. Semantic name remains unreviewed. */

void FUN_409d57c0(int param_1)

{
  uint uVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0x504);
  *(undefined4 *)(iVar2 + 0x84) = 0;
  *(undefined1 *)(iVar2 + 0x4f) = 7;
  *(undefined1 *)(iVar2 + 0x50) = 0;
  *(undefined1 *)(iVar2 + 0x51) = 0;
  FUN_409d5200(param_1);
  uVar1 = *(uint *)(iVar2 + 0x14) & 0xff00fff8 ^ 7;
  *(uint *)(iVar2 + 0x14) = uVar1;
  *(uint *)(iVar2 + 0x14) = uVar1 & 0xffffff ^ (uint)*(byte *)(iVar2 + 0x51) << 0x18;
  return;
}



/* 409d5830 FUN_409d5830 */

/* Boundary evidence: original MIPS .pdata 409d5830..409d588b. Semantic name remains unreviewed. */

void FUN_409d5830(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = *(int *)(param_1 + 0x504);
  iVar2 = 1;
  *(undefined1 *)(iVar3 + 0x4d) = 1;
  iVar1 = FUN_409d5318(param_1);
  if (iVar1 == 0) {
    iVar2 = 7;
  }
  *(uint *)(iVar3 + 0xc) = iVar2 << 1 ^ *(uint *)(iVar3 + 0xc) & 0xfffffff1;
  return;
}



/* 409d588c FUN_409d588c */

/* Boundary evidence: original MIPS .pdata 409d588c..409d58d3. Semantic name remains unreviewed. */

void FUN_409d588c(int param_1)

{
  uint uVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0x504);
  *(undefined1 *)(iVar2 + 0x4e) = 1;
  uVar1 = FUN_409d5318(param_1);
  *(uint *)(iVar2 + 0xc) = *(uint *)(iVar2 + 0xc) & 0xfffffffe ^ uVar1 & 1;
  return;
}



/* 409d58d4 FUN_409d58d4 */

/* Boundary evidence: original MIPS .pdata 409d58d4..409d596f. Semantic name remains unreviewed. */

void FUN_409d58d4(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x504);
  *(undefined1 *)(iVar1 + 0x49) = 3;
  *(undefined1 *)(iVar1 + 0x4b) = 3;
  *(undefined1 *)(iVar1 + 0x48) = 0xb;
  *(undefined1 *)(iVar1 + 0x4a) = 0xb;
  if ((*(uint *)(iVar1 + 0x40) & 8) != 8) {
    FUN_409d54c0(param_1,(uint)*(byte *)(iVar1 + 0x46),(uint)*(byte *)(iVar1 + 0x47));
    if (*(int *)(param_1 + 0x484) != 0) {
      FUN_409bc7c4(*(int *)(param_1 + 0x484),0xd55);
    }
    *(uint *)(iVar1 + 8) = *(uint *)(iVar1 + 8) & 0xff00003f ^ 0x3b1ac0;
  }
  return;
}



/* 409d5990 FUN_409d5990 */

/* WARNING: Removing unreachable block (ram,0x409d59d0) */
/* WARNING: Removing unreachable block (ram,0x409d59b4) */

undefined4 FUN_409d5990(void)

{
  return 0;
}



/* 409d59e4 FUN_409d59e4 */

/* Boundary evidence: original MIPS .pdata 409d59e4..409d5a5b. Semantic name remains unreviewed. */

void FUN_409d59e4(int param_1)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = FUN_409d5990();
  uVar1 = FUN_409d5080(uVar1);
  *(undefined4 *)(*(int *)(param_1 + 0x504) + 0x78) = 0;
  iVar2 = *(int *)(param_1 + 0x504);
  *(undefined1 *)(iVar2 + 0x44) = 7;
  *(char *)(iVar2 + 0x45) = (char)uVar1;
  *(uint *)(iVar2 + 0x20) = *(uint *)(iVar2 + 0x20) & 0xfffffff8 ^ 7;
  *(uint *)(iVar2 + 0x1c) = (uVar1 & 0xff) << 0x10 ^ *(uint *)(iVar2 + 0x1c) & 0xffff;
  return;
}



/* 409d5a5c FUN_409d5a5c */

/* Boundary evidence: original MIPS .pdata 409d5a5c..409d5caf. Semantic name remains unreviewed. */

void FUN_409d5a5c(int param_1)

{
  uint uVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  undefined1 uStack00000010;
  
  FUN_409da688();
  iVar4 = *(int *)(param_1 + 0x504);
  mali_sys_memset(iVar4,0,0x8c);
  *(uint *)(*(int *)(param_1 + 0x504) + 0x38) =
       *(uint *)(*(int *)(param_1 + 0x504) + 0x38) & 0xffffdfff ^ 0x2000;
  *(uint *)(iVar4 + 0x40) = *(uint *)(iVar4 + 0x40) | 0x20;
  FUN_409d5564(param_1);
  iVar3 = *(int *)(param_1 + 0x504);
  *(undefined4 *)(iVar3 + 0x60) = 0x3f800000;
  *(undefined1 *)(iVar3 + 100) = 0;
  *(uint *)(iVar3 + 0x20) = *(uint *)(iVar3 + 0x20) & 0xffff0fff ^ 0xf000;
  FUN_409d5830(param_1);
  iVar3 = *(int *)(param_1 + 0x504);
  *(undefined1 *)(iVar3 + 0x4e) = 1;
  uVar1 = FUN_409d5318(param_1);
  *(uint *)(iVar3 + 0xc) = *(uint *)(iVar3 + 0xc) & 0xfffffffe ^ uVar1 & 1;
  FUN_409d5430(param_1);
  *(uint *)(*(int *)(param_1 + 0x504) + 8) =
       *(uint *)(*(int *)(param_1 + 0x504) + 8) & 0xfffffff ^ 0xf0000000;
  FUN_409d54c0(param_1,2,2);
  uStack00000010 = 3;
  FUN_409d58d4(param_1);
  puVar2 = *(undefined4 **)(param_1 + 0x504);
  puVar2[0x1a] = 0;
  puVar2[0x1b] = 0;
  puVar2[0x1c] = 0;
  puVar2[0x1d] = 0;
  *puVar2 = 0;
  puVar2[1] = 0;
  FUN_409d57c0(param_1);
  iVar3 = *(int *)(param_1 + 0x504);
  *(undefined1 *)(iVar3 + 0x53) = 0;
  *(undefined1 *)(iVar3 + 0x54) = 0;
  *(undefined1 *)(iVar3 + 0x55) = 0;
  FUN_409d5200(param_1);
  *(uint *)(iVar3 + 0x14) = *(uint *)(iVar3 + 0x14) & 0xfffff007;
  FUN_409d5670(param_1);
  FUN_409d5750(param_1);
  iVar3 = *(int *)(param_1 + 0x504);
  *(undefined1 *)(iVar3 + 0x5a) = 0;
  *(undefined1 *)(iVar3 + 0x5b) = 0;
  *(undefined1 *)(iVar3 + 0x5c) = 0;
  FUN_409d5200(param_1);
  *(uint *)(iVar3 + 0x18) = *(uint *)(iVar3 + 0x18) & 0xfffff007;
  FUN_409d5614(param_1);
  uVar1 = FUN_409d5990();
  uVar1 = FUN_409d5080(uVar1);
  *(undefined4 *)(*(int *)(param_1 + 0x504) + 0x78) = 0;
  iVar3 = *(int *)(param_1 + 0x504);
  *(char *)(iVar3 + 0x45) = (char)uVar1;
  *(undefined1 *)(iVar3 + 0x44) = 7;
  *(uint *)(iVar3 + 0x20) = *(uint *)(iVar3 + 0x20) & 0xfffffff8 ^ 7;
  *(uint *)(iVar3 + 0x1c) = (uVar1 & 0xff) << 0x10 ^ *(uint *)(iVar3 + 0x1c) & 0xffff;
  *(uint *)(iVar4 + 8) = *(uint *)(iVar4 + 8) & 0xf3ffffff ^ 0xc000000;
                    /* WARNING: Subroutine does not return */
  *(uint *)(iVar4 + 0xc) = *(uint *)(iVar4 + 0xc) & 0xffffffcf ^ 0x30;
  FUN_409da6b0(0x18);
}



/* 409d5cb0 gles2_delete_context */

/* Boundary evidence: original MIPS .pdata 409d5cb0..409d5e37. Semantic name remains unreviewed.
   gles2_delete_context */

void gles2_delete_context(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  undefined4 *puVar4;
  
                    /* 0x25cb0  4  _gles2_delete_context */
  FUN_409da7c8();
  if (param_1 != 0) {
    if (*(int *)(param_1 + 0x4e8) != 0) {
      FUN_409ccf88(param_1 + 0x328);
      FUN_409c5ca8(*(int *)(*(int *)(param_1 + 0x4e8) + 8),param_1 + 0x14);
      if (*(int *)(*(int *)(param_1 + 0x4e8) + 0x10) != 0) {
        param_3 = 0;
        FUN_409be6d0((int *)(param_1 + 0x484),0,0);
      }
      if (*(int *)(*(int *)(param_1 + 0x4e8) + 0x14) != 0) {
        param_3 = 0;
        FUN_409bf878((int *)(param_1 + 0x47c),0,0);
      }
      iVar1 = *(int *)(*(int *)(param_1 + 0x4e8) + 0x18);
      if (iVar1 != 0) {
        param_3 = 0;
        FUN_409d3a5c(param_1 + 0xc,iVar1,0);
      }
      FUN_409c48a0(*(int *)(param_1 + 0x4e8),*(int *)(param_1 + 4),param_3,param_4);
      *(undefined4 *)(param_1 + 0x4e8) = 0;
      FUN_409c112c(param_1 + 0x14);
    }
    if (*(int *)(param_1 + 0x4d8) != 0) {
      mali_sys_free();
    }
    if (*(int *)(param_1 + 0x504) != 0) {
      mali_sys_free();
    }
    piVar2 = (int *)(param_1 + 0x4dc);
    iVar1 = 2;
    do {
      if (*piVar2 != 0) {
        FUN_409c7b60(*piVar2);
        *piVar2 = 0;
      }
      iVar1 = iVar1 + -1;
      piVar2 = piVar2 + 1;
    } while (iVar1 != 0);
    if (*(int *)(param_1 + 0x4e4) != 0) {
      mali_frame_builder_flush(*(undefined4 *)(*(int *)(param_1 + 0x4e4) + 0x6c),0,0);
      mali_frame_builder_wait(*(undefined4 *)(*(int *)(param_1 + 0x4e4) + 0x6c));
      iVar3 = *(int *)(param_1 + 0x4e4);
      iVar1 = mali_sys_atomic_dec_and_return(iVar3 + 0x80);
      if (iVar1 == 0) {
        FUN_409be36c(iVar3);
      }
      *(undefined4 *)(param_1 + 0x4e4) = 0;
    }
    FUN_409b619c(param_1);
    puVar4 = *(undefined4 **)(param_1 + 0x500);
    if (puVar4 != (undefined4 *)0x0) {
      FUN_409b8164(puVar4);
      mali_sys_free(puVar4);
    }
    *(undefined4 *)(param_1 + 0x500) = 0;
    mali_sys_free(param_1);
  }
                    /* WARNING: Subroutine does not return */
  FUN_409da7e8(0x10);
}



/* 409d5e38 gles2_create_context */

/* Boundary evidence: original MIPS .pdata 409d5e38..409d5fb3. Semantic name remains unreviewed.
   gles2_create_context */

undefined4 *
gles2_create_context(undefined4 param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 *puVar1;
  int *piVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  int iVar6;
  
  uVar5 = param_3;
                    /* 0x25e38  3  _gles2_create_context */
  puVar1 = (undefined4 *)mali_sys_calloc(1,0x534);
  if (puVar1 == (undefined4 *)0x0) {
    return (undefined4 *)0x0;
  }
  uVar4 = 0x20;
  puVar1[0x143] = param_3;
  FUN_409c4908((int)(puVar1 + 0x145));
  *puVar1 = param_1;
  puVar3 = puVar1 + 0x137;
  iVar6 = 0;
  do {
    piVar2 = FUN_409c75f4();
    if (piVar2 == (int *)0x0) goto LAB_409d5f88;
    *piVar2 = iVar6;
    iVar6 = iVar6 + 1;
    *puVar3 = piVar2;
    puVar3 = puVar3 + 1;
  } while (iVar6 < 2);
  puVar1[1] = 2;
  puVar1[2] = &PTR_LAB_409b17f0;
  iVar6 = mali_sys_malloc(0x8c);
  puVar1[0x141] = iVar6;
  if (iVar6 != 0) {
    FUN_409d5a5c((int)puVar1);
    uVar4 = 0x10;
    iVar6 = mali_sys_calloc(1);
    puVar1[0x136] = iVar6;
    if (iVar6 != 0) {
      FUN_409cec7c((int)puVar1);
      if (param_2 == 0) {
        iVar6 = FUN_409c4830(puVar1[1]);
        puVar1[0x13a] = iVar6;
        if (iVar6 == 0) goto LAB_409d5f88;
      }
      else {
        iVar6 = *(int *)(param_2 + 0x4e8);
        if (puVar1[1] == 2) {
          mali_sys_atomic_inc(iVar6 + 0xc);
        }
        mali_sys_atomic_inc(iVar6);
        puVar1[0x13a] = *(undefined4 *)(param_2 + 0x4e8);
      }
      puVar1[0x13f] = 0;
      iVar6 = FUN_409b61e8(puVar1);
      if (iVar6 == 0) {
        puVar3 = FUN_409b8318();
        puVar1[0x140] = puVar3;
        if (puVar3 != (undefined4 *)0x0) {
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
LAB_409d5f88:
  gles2_delete_context((int)puVar1,uVar4,uVar5,param_4);
  return (undefined4 *)0x0;
}



/* 409d62b0 glVertexAttribPointer */

/* Boundary evidence: original MIPS .pdata 409d62b0..409d637b. Semantic name remains unreviewed. */

void glVertexAttribPointer
               (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined1 param_4,
               undefined4 param_5,undefined4 param_6)

{
  int iVar1;
  int iVar2;
  
                    /* 0x262b0  158  glVertexAttribPointer */
  if (DAT_409dd38c != 0) {
    if (*(int *)(DAT_409dd38c + 8) == 0) {
      iVar1 = *(int *)(DAT_409dd38c + 0xc);
    }
    else {
      iVar1 = mali_sys_thread_key_get_data(4);
    }
    if (iVar1 != 0) {
      iVar2 = (**(code **)(*(int *)(iVar1 + 8) + 0x3b0))
                        (iVar1,param_1,param_2,param_3,param_4,param_5,param_6);
      if (iVar2 != 0) {
        (**(code **)(*(int *)(iVar1 + 8) + 0x3b8))(iVar1,iVar2);
      }
    }
  }
  return;
}



/* 409d637c glVertexAttrib4fv */

/* Boundary evidence: original MIPS .pdata 409d637c..409d641b. Semantic name remains unreviewed. */

void glVertexAttrib4fv(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  
                    /* 0x2637c  157  glVertexAttrib4fv */
  if (DAT_409dd38c != 0) {
    if (*(int *)(DAT_409dd38c + 8) == 0) {
      iVar1 = *(int *)(DAT_409dd38c + 0xc);
    }
    else {
      iVar1 = mali_sys_thread_key_get_data(4);
    }
    if ((iVar1 != 0) &&
       (iVar2 = (**(code **)(*(int *)(iVar1 + 8) + 0x3ac))(iVar1 + 0x14,param_1,4,param_2),
       iVar2 != 0)) {
      (**(code **)(*(int *)(iVar1 + 8) + 0x3b8))(iVar1,iVar2);
    }
  }
  return;
}



/* 409d641c glVertexAttrib4f */

/* Boundary evidence: original MIPS .pdata 409d641c..409d64eb. Semantic name remains unreviewed. */

void glVertexAttrib4f(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                     undefined4 param_5)

{
  int iVar1;
  int iVar2;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  
                    /* 0x2641c  156  glVertexAttrib4f */
  if (DAT_409dd38c == 0) {
    iVar2 = 0;
  }
  else if (*(int *)(DAT_409dd38c + 8) == 0) {
    iVar2 = *(int *)(DAT_409dd38c + 0xc);
  }
  else {
    iVar2 = mali_sys_thread_key_get_data(4);
  }
  local_1c = param_5;
  if ((iVar2 != 0) &&
     (local_28 = param_2, local_24 = param_3, local_20 = param_4,
     iVar1 = (**(code **)(*(int *)(iVar2 + 8) + 0x3a8))(iVar2 + 0x14,param_1,4,&local_28),
     iVar1 != 0)) {
    (**(code **)(*(int *)(iVar2 + 8) + 0x3b8))(iVar2,iVar1);
  }
  return;
}



/* 409d64ec glVertexAttrib3fv */

/* Boundary evidence: original MIPS .pdata 409d64ec..409d658b. Semantic name remains unreviewed. */

void glVertexAttrib3fv(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  
                    /* 0x264ec  155  glVertexAttrib3fv */
  if (DAT_409dd38c != 0) {
    if (*(int *)(DAT_409dd38c + 8) == 0) {
      iVar1 = *(int *)(DAT_409dd38c + 0xc);
    }
    else {
      iVar1 = mali_sys_thread_key_get_data(4);
    }
    if ((iVar1 != 0) &&
       (iVar2 = (**(code **)(*(int *)(iVar1 + 8) + 0x3a4))(iVar1 + 0x14,param_1,3,param_2),
       iVar2 != 0)) {
      (**(code **)(*(int *)(iVar1 + 8) + 0x3b8))(iVar1,iVar2);
    }
  }
  return;
}



/* 409d658c glVertexAttrib3f */

/* Boundary evidence: original MIPS .pdata 409d658c..409d6653. Semantic name remains unreviewed. */

void glVertexAttrib3f(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  
                    /* 0x2658c  154  glVertexAttrib3f */
  if (DAT_409dd38c == 0) {
    iVar2 = 0;
  }
  else if (*(int *)(DAT_409dd38c + 8) == 0) {
    iVar2 = *(int *)(DAT_409dd38c + 0xc);
  }
  else {
    iVar2 = mali_sys_thread_key_get_data(4);
  }
  if ((iVar2 != 0) &&
     (local_28 = param_2, local_24 = param_3, local_20 = param_4,
     iVar1 = (**(code **)(*(int *)(iVar2 + 8) + 0x3a0))(iVar2 + 0x14,param_1,3,&local_28),
     iVar1 != 0)) {
    (**(code **)(*(int *)(iVar2 + 8) + 0x3b8))(iVar2,iVar1);
  }
  return;
}



/* 409d6654 glVertexAttrib2fv */

/* Boundary evidence: original MIPS .pdata 409d6654..409d66f3. Semantic name remains unreviewed. */

void glVertexAttrib2fv(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  
                    /* 0x26654  153  glVertexAttrib2fv */
  if (DAT_409dd38c != 0) {
    if (*(int *)(DAT_409dd38c + 8) == 0) {
      iVar1 = *(int *)(DAT_409dd38c + 0xc);
    }
    else {
      iVar1 = mali_sys_thread_key_get_data(4);
    }
    if ((iVar1 != 0) &&
       (iVar2 = (**(code **)(*(int *)(iVar1 + 8) + 0x39c))(iVar1 + 0x14,param_1,2,param_2),
       iVar2 != 0)) {
      (**(code **)(*(int *)(iVar1 + 8) + 0x3b8))(iVar1,iVar2);
    }
  }
  return;
}



/* 409d66f4 glVertexAttrib2f */

/* Boundary evidence: original MIPS .pdata 409d66f4..409d67ab. Semantic name remains unreviewed. */

void glVertexAttrib2f(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  undefined4 local_20;
  undefined4 local_1c;
  
                    /* 0x266f4  152  glVertexAttrib2f */
  if (DAT_409dd38c == 0) {
    iVar2 = 0;
  }
  else if (*(int *)(DAT_409dd38c + 8) == 0) {
    iVar2 = *(int *)(DAT_409dd38c + 0xc);
  }
  else {
    iVar2 = mali_sys_thread_key_get_data(4);
  }
  if ((iVar2 != 0) &&
     (local_20 = param_2, local_1c = param_3,
     iVar1 = (**(code **)(*(int *)(iVar2 + 8) + 0x398))(iVar2 + 0x14,param_1,2,&local_20),
     iVar1 != 0)) {
    (**(code **)(*(int *)(iVar2 + 8) + 0x3b8))(iVar2,iVar1);
  }
  return;
}



/* 409d67ac glVertexAttrib1fv */

/* Boundary evidence: original MIPS .pdata 409d67ac..409d684b. Semantic name remains unreviewed. */

void glVertexAttrib1fv(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  
                    /* 0x267ac  151  glVertexAttrib1fv */
  if (DAT_409dd38c != 0) {
    if (*(int *)(DAT_409dd38c + 8) == 0) {
      iVar1 = *(int *)(DAT_409dd38c + 0xc);
    }
    else {
      iVar1 = mali_sys_thread_key_get_data(4);
    }
    if ((iVar1 != 0) &&
       (iVar2 = (**(code **)(*(int *)(iVar1 + 8) + 0x394))(iVar1 + 0x14,param_1,1,param_2),
       iVar2 != 0)) {
      (**(code **)(*(int *)(iVar1 + 8) + 0x3b8))(iVar1,iVar2);
    }
  }
  return;
}



/* 409d684c glVertexAttrib1f */

/* Boundary evidence: original MIPS .pdata 409d684c..409d68e3. Semantic name remains unreviewed. */

void glVertexAttrib1f(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  undefined4 local_res4 [3];
  
                    /* 0x2684c  150  glVertexAttrib1f */
  if (DAT_409dd38c != 0) {
    local_res4[0] = param_2;
    if (*(int *)(DAT_409dd38c + 8) == 0) {
      iVar1 = *(int *)(DAT_409dd38c + 0xc);
    }
    else {
      iVar1 = mali_sys_thread_key_get_data(4);
    }
    if ((iVar1 != 0) &&
       (iVar2 = (**(code **)(*(int *)(iVar1 + 8) + 0x390))(iVar1 + 0x14,param_1,1,local_res4),
       iVar2 != 0)) {
      (**(code **)(*(int *)(iVar1 + 8) + 0x3b8))(iVar1,iVar2);
    }
  }
  return;
}



/* 409d68e4 glStencilOpSeparate */

/* Boundary evidence: original MIPS .pdata 409d68e4..409d699f. Semantic name remains unreviewed. */

void glStencilOpSeparate(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4
                        )

{
  int iVar1;
  int iVar2;
  
                    /* 0x268e4  122  glStencilOpSeparate */
  if (DAT_409dd38c != 0) {
    if (*(int *)(DAT_409dd38c + 8) == 0) {
      iVar1 = *(int *)(DAT_409dd38c + 0xc);
    }
    else {
      iVar1 = mali_sys_thread_key_get_data(4);
    }
    if (iVar1 != 0) {
      iVar2 = (**(code **)(*(int *)(iVar1 + 8) + 0x338))(iVar1,param_1,param_2,param_3,param_4);
      if (iVar2 != 0) {
        (**(code **)(*(int *)(iVar1 + 8) + 0x3b8))(iVar1,iVar2);
      }
    }
  }
  return;
}



/* 409d69a0 glStencilMaskSeparate */

/* Boundary evidence: original MIPS .pdata 409d69a0..409d6a3b. Semantic name remains unreviewed. */

void glStencilMaskSeparate(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  
                    /* 0x269a0  120  glStencilMaskSeparate */
  if (DAT_409dd38c != 0) {
    if (*(int *)(DAT_409dd38c + 8) == 0) {
      iVar1 = *(int *)(DAT_409dd38c + 0xc);
    }
    else {
      iVar1 = mali_sys_thread_key_get_data(4);
    }
    if ((iVar1 != 0) &&
       (iVar2 = (**(code **)(*(int *)(iVar1 + 8) + 0x334))(iVar1,param_1,param_2), iVar2 != 0)) {
      (**(code **)(*(int *)(iVar1 + 8) + 0x3b8))(iVar1,iVar2);
    }
  }
  return;
}



/* 409d6a3c glStencilFuncSeparate */

/* Boundary evidence: original MIPS .pdata 409d6a3c..409d6af7. Semantic name remains unreviewed. */

void glStencilFuncSeparate
               (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  
                    /* 0x26a3c  118  glStencilFuncSeparate */
  if (DAT_409dd38c != 0) {
    if (*(int *)(DAT_409dd38c + 8) == 0) {
      iVar1 = *(int *)(DAT_409dd38c + 0xc);
    }
    else {
      iVar1 = mali_sys_thread_key_get_data(4);
    }
    if (iVar1 != 0) {
      iVar2 = (**(code **)(*(int *)(iVar1 + 8) + 0x330))(iVar1,param_1,param_2,param_3,param_4);
      if (iVar2 != 0) {
        (**(code **)(*(int *)(iVar1 + 8) + 0x3b8))(iVar1,iVar2);
      }
    }
  }
  return;
}



/* 409d6af8 glGetVertexAttribPointerv */

/* Boundary evidence: original MIPS .pdata 409d6af8..409d6ba3. Semantic name remains unreviewed. */

void glGetVertexAttribPointerv(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  
                    /* 0x26af8  95  glGetVertexAttribPointerv */
  if (DAT_409dd38c != 0) {
    if (*(int *)(DAT_409dd38c + 8) == 0) {
      iVar1 = *(int *)(DAT_409dd38c + 0xc);
    }
    else {
      iVar1 = mali_sys_thread_key_get_data(4);
    }
    if ((iVar1 != 0) &&
       (iVar2 = (**(code **)(*(int *)(iVar1 + 8) + 0x314))(iVar1 + 0x14,param_1,param_2,param_3),
       iVar2 != 0)) {
      (**(code **)(*(int *)(iVar1 + 8) + 0x3b8))(iVar1,iVar2);
    }
  }
  return;
}



/* 409d6ba4 glGetShaderPrecisionFormat */

/* Boundary evidence: original MIPS .pdata 409d6ba4..409d6c5b. Semantic name remains unreviewed. */

void glGetShaderPrecisionFormat
               (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  
                    /* 0x26ba4  86  glGetShaderPrecisionFormat */
  if (DAT_409dd38c != 0) {
    if (*(int *)(DAT_409dd38c + 8) == 0) {
      iVar1 = *(int *)(DAT_409dd38c + 0xc);
    }
    else {
      iVar1 = mali_sys_thread_key_get_data(4);
    }
    if ((iVar1 != 0) &&
       (iVar2 = (**(code **)(*(int *)(iVar1 + 8) + 0x2f8))(param_1,param_2,param_3,param_4),
       iVar2 != 0)) {
      (**(code **)(*(int *)(iVar1 + 8) + 0x3b8))(iVar1,iVar2);
    }
  }
  return;
}



/* 409d6c5c glEnableVertexAttribArray */

/* Boundary evidence: original MIPS .pdata 409d6c5c..409d6ce7. Semantic name remains unreviewed. */

void glEnableVertexAttribArray(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  
                    /* 0x26c5c  61  glEnableVertexAttribArray */
  if (DAT_409dd38c != 0) {
    if (*(int *)(DAT_409dd38c + 8) == 0) {
      iVar1 = *(int *)(DAT_409dd38c + 0xc);
    }
    else {
      iVar1 = mali_sys_thread_key_get_data(4);
    }
    if ((iVar1 != 0) &&
       (iVar2 = (**(code **)(*(int *)(iVar1 + 8) + 0x2d4))(iVar1 + 0x14,param_1), iVar2 != 0)) {
      (**(code **)(*(int *)(iVar1 + 8) + 0x3b8))(iVar1,iVar2);
    }
  }
  return;
}



/* 409d6ce8 glDisableVertexAttribArray */

/* Boundary evidence: original MIPS .pdata 409d6ce8..409d6d73. Semantic name remains unreviewed. */

void glDisableVertexAttribArray(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  
                    /* 0x26ce8  55  glDisableVertexAttribArray */
  if (DAT_409dd38c != 0) {
    if (*(int *)(DAT_409dd38c + 8) == 0) {
      iVar1 = *(int *)(DAT_409dd38c + 0xc);
    }
    else {
      iVar1 = mali_sys_thread_key_get_data(4);
    }
    if ((iVar1 != 0) &&
       (iVar2 = (**(code **)(*(int *)(iVar1 + 8) + 0x2d0))(iVar1 + 0x14,param_1), iVar2 != 0)) {
      (**(code **)(*(int *)(iVar1 + 8) + 0x3b8))(iVar1,iVar2);
    }
  }
  return;
}



/* 409d6d74 glBlendFuncSeparate */

/* Boundary evidence: original MIPS .pdata 409d6d74..409d6e2f. Semantic name remains unreviewed. */

void glBlendFuncSeparate(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4
                        )

{
  int iVar1;
  int iVar2;
  
                    /* 0x26d74  27  glBlendFuncSeparate */
  if (DAT_409dd38c != 0) {
    if (*(int *)(DAT_409dd38c + 8) == 0) {
      iVar1 = *(int *)(DAT_409dd38c + 0xc);
    }
    else {
      iVar1 = mali_sys_thread_key_get_data(4);
    }
    if (iVar1 != 0) {
      iVar2 = (**(code **)(*(int *)(iVar1 + 8) + 0x2b4))(iVar1,param_1,param_2,param_3,param_4);
      if (iVar2 != 0) {
        (**(code **)(*(int *)(iVar1 + 8) + 0x3b8))(iVar1,iVar2);
      }
    }
  }
  return;
}



/* 409d6e30 glBlendEquationSeparate */

/* Boundary evidence: original MIPS .pdata 409d6e30..409d6ecb. Semantic name remains unreviewed. */

void glBlendEquationSeparate(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  
                    /* 0x26e30  25  glBlendEquationSeparate */
  if (DAT_409dd38c != 0) {
    if (*(int *)(DAT_409dd38c + 8) == 0) {
      iVar1 = *(int *)(DAT_409dd38c + 0xc);
    }
    else {
      iVar1 = mali_sys_thread_key_get_data(4);
    }
    if ((iVar1 != 0) &&
       (iVar2 = (**(code **)(*(int *)(iVar1 + 8) + 0x2b0))(iVar1,param_1,param_2), iVar2 != 0)) {
      (**(code **)(*(int *)(iVar1 + 8) + 0x3b8))(iVar1,iVar2);
    }
  }
  return;
}



/* 409d6ecc glBlendEquation */

/* Boundary evidence: original MIPS .pdata 409d6ecc..409d6f5b. Semantic name remains unreviewed. */

void glBlendEquation(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  
                    /* 0x26ecc  24  glBlendEquation */
  if (DAT_409dd38c != 0) {
    if (*(int *)(DAT_409dd38c + 8) == 0) {
      iVar1 = *(int *)(DAT_409dd38c + 0xc);
    }
    else {
      iVar1 = mali_sys_thread_key_get_data(4);
    }
    if ((iVar1 != 0) &&
       (iVar2 = (**(code **)(*(int *)(iVar1 + 8) + 0x2ac))(iVar1,param_1,param_1), iVar2 != 0)) {
      (**(code **)(*(int *)(iVar1 + 8) + 0x3b8))(iVar1,iVar2);
    }
  }
  return;
}



/* 409d6f5c glBlendColor */

/* Boundary evidence: original MIPS .pdata 409d6f5c..409d7017. Semantic name remains unreviewed. */

void glBlendColor(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  
                    /* 0x26f5c  23  glBlendColor */
  if (DAT_409dd38c != 0) {
    if (*(int *)(DAT_409dd38c + 8) == 0) {
      iVar1 = *(int *)(DAT_409dd38c + 0xc);
    }
    else {
      iVar1 = mali_sys_thread_key_get_data(4);
    }
    if (iVar1 != 0) {
      iVar2 = (**(code **)(*(int *)(iVar1 + 8) + 0x2a8))(iVar1,param_1,param_2,param_3,param_4);
      if (iVar2 != 0) {
        (**(code **)(*(int *)(iVar1 + 8) + 0x3b8))(iVar1,iVar2);
      }
    }
  }
  return;
}



/* 409d7018 FUN_409d7018 */

/* Boundary evidence: original MIPS .pdata 409d7018..409d7033. Semantic name remains unreviewed. */

void FUN_409d7018(int param_1)

{
  mali_sys_mutex_unlock(*(undefined4 *)(param_1 + 0x1c));
  return;
}



/* 409d7034 FUN_409d7034 */

/* Boundary evidence: original MIPS .pdata 409d7034..409d704f. Semantic name remains unreviewed. */

void FUN_409d7034(int param_1)

{
  mali_sys_mutex_lock(*(undefined4 *)(param_1 + 0x1c));
  return;
}



/* 409d7050 glGenerateMipmap */

/* Boundary evidence: original MIPS .pdata 409d7050..409d7103. Semantic name remains unreviewed. */

void glGenerateMipmap(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  
                    /* 0x27050  71  glGenerateMipmap */
  if (DAT_409dd38c != 0) {
    if (*(int *)(DAT_409dd38c + 8) == 0) {
      iVar1 = *(int *)(DAT_409dd38c + 0xc);
    }
    else {
      iVar1 = mali_sys_thread_key_get_data(4);
    }
    if (iVar1 != 0) {
      mali_sys_mutex_lock(*(undefined4 *)(*(int *)(iVar1 + 0x4e8) + 0x1c));
      iVar2 = (**(code **)(*(int *)(iVar1 + 8) + 0x120))
                        (iVar1,iVar1 + 0x328,*(undefined4 *)(*(int *)(iVar1 + 0x4e8) + 4),param_1);
      mali_sys_mutex_unlock(*(undefined4 *)(*(int *)(iVar1 + 0x4e8) + 0x1c));
      if (iVar2 != 0) {
        (**(code **)(*(int *)(iVar1 + 8) + 0x3b8))(iVar1,iVar2);
      }
    }
  }
  return;
}



/* 409d7104 glGetFramebufferAttachmentParameteriv */

/* Boundary evidence: original MIPS .pdata 409d7104..409d71e3. Semantic name remains unreviewed. */

void glGetFramebufferAttachmentParameteriv
               (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  
                    /* 0x27104  80  glGetFramebufferAttachmentParameteriv */
  if (DAT_409dd38c != 0) {
    if (*(int *)(DAT_409dd38c + 8) == 0) {
      iVar1 = *(int *)(DAT_409dd38c + 0xc);
    }
    else {
      iVar1 = mali_sys_thread_key_get_data(4);
    }
    if (iVar1 != 0) {
      mali_sys_mutex_lock(*(undefined4 *)(*(int *)(iVar1 + 0x4e8) + 0x1c));
      iVar2 = (**(code **)(*(int *)(iVar1 + 8) + 0x11c))
                        (iVar1 + 0x484,*(undefined4 *)(*(int *)(iVar1 + 0x4e8) + 0x10),param_1,
                         param_2,param_3,param_4);
      mali_sys_mutex_unlock(*(undefined4 *)(*(int *)(iVar1 + 0x4e8) + 0x1c));
      if (iVar2 != 0) {
        (**(code **)(*(int *)(iVar1 + 8) + 0x3b8))(iVar1,iVar2);
      }
    }
  }
  return;
}



/* 409d71e4 glFramebufferRenderbuffer */

/* Boundary evidence: original MIPS .pdata 409d71e4..409d72cb. Semantic name remains unreviewed. */

void glFramebufferRenderbuffer
               (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  
                    /* 0x271e4  64  glFramebufferRenderbuffer */
  if (DAT_409dd38c != 0) {
    if (*(int *)(DAT_409dd38c + 8) == 0) {
      iVar1 = *(int *)(DAT_409dd38c + 0xc);
    }
    else {
      iVar1 = mali_sys_thread_key_get_data(4);
    }
    if (iVar1 != 0) {
      mali_sys_mutex_lock(*(undefined4 *)(*(int *)(iVar1 + 0x4e8) + 0x1c));
      iVar2 = *(int *)(iVar1 + 0x4e8);
      iVar2 = (**(code **)(*(int *)(iVar1 + 8) + 0x118))
                        (iVar1 + 0x484,*(undefined4 *)(iVar2 + 0x10),*(undefined4 *)(iVar2 + 0x14),
                         *(undefined4 *)(iVar2 + 4),param_1,param_2,param_3,param_4);
      mali_sys_mutex_unlock(*(undefined4 *)(*(int *)(iVar1 + 0x4e8) + 0x1c));
      if (iVar2 != 0) {
        (**(code **)(*(int *)(iVar1 + 8) + 0x3b8))(iVar1,iVar2);
      }
    }
  }
  return;
}



/* 409d72cc glFramebufferTexture2D */

/* Boundary evidence: original MIPS .pdata 409d72cc..409d73c3. Semantic name remains unreviewed. */

void glFramebufferTexture2D
               (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
               undefined4 param_5)

{
  int iVar1;
  int iVar2;
  
                    /* 0x272cc  65  glFramebufferTexture2D */
  if (DAT_409dd38c != 0) {
    if (*(int *)(DAT_409dd38c + 8) == 0) {
      iVar1 = *(int *)(DAT_409dd38c + 0xc);
    }
    else {
      iVar1 = mali_sys_thread_key_get_data(4);
    }
    if (iVar1 != 0) {
      mali_sys_mutex_lock(*(undefined4 *)(*(int *)(iVar1 + 0x4e8) + 0x1c));
      iVar2 = *(int *)(iVar1 + 0x4e8);
      iVar2 = (**(code **)(*(int *)(iVar1 + 8) + 0x114))
                        (iVar1,iVar1 + 0x484,*(undefined4 *)(iVar2 + 0x10),
                         *(undefined4 *)(iVar2 + 0x14),*(undefined4 *)(iVar2 + 4),param_1,param_2,
                         param_3,param_4,param_5);
      mali_sys_mutex_unlock(*(undefined4 *)(*(int *)(iVar1 + 0x4e8) + 0x1c));
      if (iVar2 != 0) {
        (**(code **)(*(int *)(iVar1 + 8) + 0x3b8))(iVar1,iVar2);
      }
    }
  }
  return;
}



/* 409d73c4 glCheckFramebufferStatus */

/* Boundary evidence: original MIPS .pdata 409d73c4..409d7493. Semantic name remains unreviewed. */

undefined4 glCheckFramebufferStatus(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  undefined4 local_18 [2];
  
                    /* 0x273c4  30  glCheckFramebufferStatus */
  local_18[0] = 0x501;
  if (DAT_409dd38c != 0) {
    if (*(int *)(DAT_409dd38c + 8) == 0) {
      iVar1 = *(int *)(DAT_409dd38c + 0xc);
    }
    else {
      iVar1 = mali_sys_thread_key_get_data(4);
    }
    if (iVar1 != 0) {
      mali_sys_mutex_lock(*(undefined4 *)(*(int *)(iVar1 + 0x4e8) + 0x1c));
      iVar2 = (**(code **)(*(int *)(iVar1 + 8) + 0x110))(iVar1 + 0x484,param_1,local_18);
      mali_sys_mutex_unlock(*(undefined4 *)(*(int *)(iVar1 + 0x4e8) + 0x1c));
      if (iVar2 != 0) {
        (**(code **)(*(int *)(iVar1 + 8) + 0x3b8))(iVar1,iVar2);
      }
      return local_18[0];
    }
  }
  return 0x502;
}



/* 409d7494 glGenFramebuffers */

/* Boundary evidence: original MIPS .pdata 409d7494..409d7553. Semantic name remains unreviewed. */

void glGenFramebuffers(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  
                    /* 0x27494  68  glGenFramebuffers */
  if (DAT_409dd38c != 0) {
    if (*(int *)(DAT_409dd38c + 8) == 0) {
      iVar1 = *(int *)(DAT_409dd38c + 0xc);
    }
    else {
      iVar1 = mali_sys_thread_key_get_data(4);
    }
    if (iVar1 != 0) {
      mali_sys_mutex_lock(*(undefined4 *)(*(int *)(iVar1 + 0x4e8) + 0x1c));
      iVar2 = (**(code **)(*(int *)(iVar1 + 8) + 0x10c))
                        (*(undefined4 *)(*(int *)(iVar1 + 0x4e8) + 0x10),param_1,param_2,3);
      mali_sys_mutex_unlock(*(undefined4 *)(*(int *)(iVar1 + 0x4e8) + 0x1c));
      if (iVar2 != 0) {
        (**(code **)(*(int *)(iVar1 + 8) + 0x3b8))(iVar1,iVar2);
      }
    }
  }
  return;
}



/* 409d7554 glDeleteFramebuffers */

/* Boundary evidence: original MIPS .pdata 409d7554..409d760b. Semantic name remains unreviewed. */

void glDeleteFramebuffers(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  
                    /* 0x27554  45  glDeleteFramebuffers */
  if (DAT_409dd38c != 0) {
    if (*(int *)(DAT_409dd38c + 8) == 0) {
      iVar1 = *(int *)(DAT_409dd38c + 0xc);
    }
    else {
      iVar1 = mali_sys_thread_key_get_data(4);
    }
    if (iVar1 != 0) {
      mali_sys_mutex_lock(*(undefined4 *)(*(int *)(iVar1 + 0x4e8) + 0x1c));
      iVar2 = (**(code **)(*(int *)(iVar1 + 8) + 0x108))(iVar1,param_1,param_2);
      mali_sys_mutex_unlock(*(undefined4 *)(*(int *)(iVar1 + 0x4e8) + 0x1c));
      if (iVar2 != 0) {
        (**(code **)(*(int *)(iVar1 + 8) + 0x3b8))(iVar1,iVar2);
      }
    }
  }
  return;
}



/* 409d760c glBindFramebuffer */

/* Boundary evidence: original MIPS .pdata 409d760c..409d76cf. Semantic name remains unreviewed. */

void glBindFramebuffer(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  
                    /* 0x2760c  20  glBindFramebuffer */
  if (DAT_409dd38c != 0) {
    if (*(int *)(DAT_409dd38c + 8) == 0) {
      iVar1 = *(int *)(DAT_409dd38c + 0xc);
    }
    else {
      iVar1 = mali_sys_thread_key_get_data(4);
    }
    if (iVar1 != 0) {
      mali_sys_mutex_lock(*(undefined4 *)(*(int *)(iVar1 + 0x4e8) + 0x1c));
      iVar2 = (**(code **)(*(int *)(iVar1 + 8) + 0x104))
                        (iVar1,*(undefined4 *)(*(int *)(iVar1 + 0x4e8) + 0x10),iVar1 + 0x484,param_1
                         ,param_2);
      mali_sys_mutex_unlock(*(undefined4 *)(*(int *)(iVar1 + 0x4e8) + 0x1c));
      if (iVar2 != 0) {
        (**(code **)(*(int *)(iVar1 + 8) + 0x3b8))(iVar1,iVar2);
      }
    }
  }
  return;
}



/* 409d76d0 glIsFramebuffer */

/* Boundary evidence: original MIPS .pdata 409d76d0..409d777b. Semantic name remains unreviewed. */

undefined4 glIsFramebuffer(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  
                    /* 0x276d0  101  glIsFramebuffer */
  if (DAT_409dd38c != 0) {
    if (*(int *)(DAT_409dd38c + 8) == 0) {
      iVar1 = *(int *)(DAT_409dd38c + 0xc);
    }
    else {
      iVar1 = mali_sys_thread_key_get_data(4);
    }
    if (iVar1 != 0) {
      mali_sys_mutex_lock(*(undefined4 *)(*(int *)(iVar1 + 0x4e8) + 0x1c));
      uVar2 = (**(code **)(*(int *)(iVar1 + 8) + 0x100))
                        (*(undefined4 *)(*(int *)(iVar1 + 0x4e8) + 0x10),param_1);
      mali_sys_mutex_unlock(*(undefined4 *)(*(int *)(iVar1 + 0x4e8) + 0x1c));
      return uVar2;
    }
  }
  return 0;
}



/* 409d777c glGetRenderbufferParameteriv */

/* Boundary evidence: original MIPS .pdata 409d777c..409d784b. Semantic name remains unreviewed. */

void glGetRenderbufferParameteriv(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  
                    /* 0x2777c  84  glGetRenderbufferParameteriv */
  if (DAT_409dd38c != 0) {
    if (*(int *)(DAT_409dd38c + 8) == 0) {
      iVar1 = *(int *)(DAT_409dd38c + 0xc);
    }
    else {
      iVar1 = mali_sys_thread_key_get_data(4);
    }
    if (iVar1 != 0) {
      mali_sys_mutex_lock(*(undefined4 *)(*(int *)(iVar1 + 0x4e8) + 0x1c));
      iVar2 = (**(code **)(*(int *)(iVar1 + 8) + 0xfc))
                        (iVar1 + 0x47c,*(undefined4 *)(*(int *)(iVar1 + 0x4e8) + 0x14),param_1,
                         param_2,param_3);
      mali_sys_mutex_unlock(*(undefined4 *)(*(int *)(iVar1 + 0x4e8) + 0x1c));
      if (iVar2 != 0) {
        (**(code **)(*(int *)(iVar1 + 8) + 0x3b8))(iVar1,iVar2);
      }
    }
  }
  return;
}



/* 409d784c glRenderbufferStorage */

/* Boundary evidence: original MIPS .pdata 409d784c..409d793b. Semantic name remains unreviewed. */

void glRenderbufferStorage
               (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 *puVar1;
  int iVar2;
  
                    /* 0x2784c  112  glRenderbufferStorage */
  if (DAT_409dd38c != 0) {
    if (*(int *)(DAT_409dd38c + 8) == 0) {
      puVar1 = *(undefined4 **)(DAT_409dd38c + 0xc);
    }
    else {
      puVar1 = (undefined4 *)mali_sys_thread_key_get_data(4);
    }
    if (puVar1 != (undefined4 *)0x0) {
      mali_sys_mutex_lock(*(undefined4 *)(puVar1[0x13a] + 0x1c));
      iVar2 = (**(code **)(puVar1[2] + 0xf8))
                        (*puVar1,*(undefined4 *)(puVar1[0x13a] + 0x14),
                         *(undefined4 *)(puVar1[0x13a] + 0x10),puVar1 + 0x11f,puVar1 + 0x121,param_1
                         ,param_2,param_3,param_4);
      mali_sys_mutex_unlock(*(undefined4 *)(puVar1[0x13a] + 0x1c));
      if (iVar2 != 0) {
        (**(code **)(puVar1[2] + 0x3b8))(puVar1,iVar2);
      }
    }
  }
  return;
}



/* 409d793c glGenRenderbuffers */

/* Boundary evidence: original MIPS .pdata 409d793c..409d79fb. Semantic name remains unreviewed. */

void glGenRenderbuffers(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  
                    /* 0x2793c  69  glGenRenderbuffers */
  if (DAT_409dd38c != 0) {
    if (*(int *)(DAT_409dd38c + 8) == 0) {
      iVar1 = *(int *)(DAT_409dd38c + 0xc);
    }
    else {
      iVar1 = mali_sys_thread_key_get_data(4);
    }
    if (iVar1 != 0) {
      mali_sys_mutex_lock(*(undefined4 *)(*(int *)(iVar1 + 0x4e8) + 0x1c));
      iVar2 = (**(code **)(*(int *)(iVar1 + 8) + 0xf4))
                        (*(undefined4 *)(*(int *)(iVar1 + 0x4e8) + 0x14),param_1,param_2,2);
      mali_sys_mutex_unlock(*(undefined4 *)(*(int *)(iVar1 + 0x4e8) + 0x1c));
      if (iVar2 != 0) {
        (**(code **)(*(int *)(iVar1 + 8) + 0x3b8))(iVar1,iVar2);
      }
    }
  }
  return;
}



/* 409d79fc glDeleteRenderbuffers */

/* Boundary evidence: original MIPS .pdata 409d79fc..409d7ac3. Semantic name remains unreviewed. */

void glDeleteRenderbuffers(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  
                    /* 0x279fc  47  glDeleteRenderbuffers */
  if (DAT_409dd38c != 0) {
    if (*(int *)(DAT_409dd38c + 8) == 0) {
      iVar1 = *(int *)(DAT_409dd38c + 0xc);
    }
    else {
      iVar1 = mali_sys_thread_key_get_data(4);
    }
    if (iVar1 != 0) {
      mali_sys_mutex_lock(*(undefined4 *)(*(int *)(iVar1 + 0x4e8) + 0x1c));
      iVar2 = (**(code **)(*(int *)(iVar1 + 8) + 0xf0))
                        (*(undefined4 *)(*(int *)(iVar1 + 0x4e8) + 0x14),
                         *(undefined4 *)(*(int *)(iVar1 + 0x4e8) + 0x10),iVar1 + 0x47c,iVar1 + 0x484
                         ,param_1,param_2);
      mali_sys_mutex_unlock(*(undefined4 *)(*(int *)(iVar1 + 0x4e8) + 0x1c));
      if (iVar2 != 0) {
        (**(code **)(*(int *)(iVar1 + 8) + 0x3b8))(iVar1,iVar2);
      }
    }
  }
  return;
}



/* 409d7ac4 glBindRenderbuffer */

/* Boundary evidence: original MIPS .pdata 409d7ac4..409d7b83. Semantic name remains unreviewed. */

void glBindRenderbuffer(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  
                    /* 0x27ac4  21  glBindRenderbuffer */
  if (DAT_409dd38c != 0) {
    if (*(int *)(DAT_409dd38c + 8) == 0) {
      iVar1 = *(int *)(DAT_409dd38c + 0xc);
    }
    else {
      iVar1 = mali_sys_thread_key_get_data(4);
    }
    if (iVar1 != 0) {
      mali_sys_mutex_lock(*(undefined4 *)(*(int *)(iVar1 + 0x4e8) + 0x1c));
      iVar2 = (**(code **)(*(int *)(iVar1 + 8) + 0xec))
                        (*(undefined4 *)(*(int *)(iVar1 + 0x4e8) + 0x14),iVar1 + 0x47c,param_1,
                         param_2);
      mali_sys_mutex_unlock(*(undefined4 *)(*(int *)(iVar1 + 0x4e8) + 0x1c));
      if (iVar2 != 0) {
        (**(code **)(*(int *)(iVar1 + 8) + 0x3b8))(iVar1,iVar2);
      }
    }
  }
  return;
}



/* 409d7b84 glIsRenderbuffer */

/* Boundary evidence: original MIPS .pdata 409d7b84..409d7c2f. Semantic name remains unreviewed. */

undefined4 glIsRenderbuffer(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  
                    /* 0x27b84  103  glIsRenderbuffer */
  if (DAT_409dd38c != 0) {
    if (*(int *)(DAT_409dd38c + 8) == 0) {
      iVar1 = *(int *)(DAT_409dd38c + 0xc);
    }
    else {
      iVar1 = mali_sys_thread_key_get_data(4);
    }
    if (iVar1 != 0) {
      mali_sys_mutex_lock(*(undefined4 *)(*(int *)(iVar1 + 0x4e8) + 0x1c));
      uVar2 = (**(code **)(*(int *)(iVar1 + 8) + 0xe8))
                        (*(undefined4 *)(*(int *)(iVar1 + 0x4e8) + 0x14),param_1);
      mali_sys_mutex_unlock(*(undefined4 *)(*(int *)(iVar1 + 0x4e8) + 0x1c));
      return uVar2;
    }
  }
  return 0;
}



/* 409d7c30 glValidateProgram */

/* Boundary evidence: original MIPS .pdata 409d7c30..409d7cdb. Semantic name remains unreviewed. */

void glValidateProgram(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  
                    /* 0x27c30  149  glValidateProgram */
  if (DAT_409dd38c != 0) {
    if (*(int *)(DAT_409dd38c + 8) == 0) {
      iVar1 = *(int *)(DAT_409dd38c + 0xc);
    }
    else {
      iVar1 = mali_sys_thread_key_get_data(4);
    }
    if (iVar1 != 0) {
      mali_sys_mutex_lock(*(undefined4 *)(*(int *)(iVar1 + 0x4e8) + 0x1c));
      iVar2 = (**(code **)(*(int *)(iVar1 + 8) + 0x38c))
                        (*(undefined4 *)(*(int *)(iVar1 + 0x4e8) + 0x18),param_1);
      mali_sys_mutex_unlock(*(undefined4 *)(*(int *)(iVar1 + 0x4e8) + 0x1c));
      if (iVar2 != 0) {
        (**(code **)(*(int *)(iVar1 + 8) + 0x3b8))(iVar1,iVar2);
      }
    }
  }
  return;
}



/* 409d7cdc glUseProgram */

/* Boundary evidence: original MIPS .pdata 409d7cdc..409d7d8b. Semantic name remains unreviewed. */

void glUseProgram(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  
                    /* 0x27cdc  148  glUseProgram */
  if (DAT_409dd38c != 0) {
    if (*(int *)(DAT_409dd38c + 8) == 0) {
      iVar1 = *(int *)(DAT_409dd38c + 0xc);
    }
    else {
      iVar1 = mali_sys_thread_key_get_data(4);
    }
    if (iVar1 != 0) {
      mali_sys_mutex_lock(*(undefined4 *)(*(int *)(iVar1 + 0x4e8) + 0x1c));
      iVar2 = (**(code **)(*(int *)(iVar1 + 8) + 0x388))
                        (iVar1 + 0xc,*(undefined4 *)(*(int *)(iVar1 + 0x4e8) + 0x18),param_1);
      mali_sys_mutex_unlock(*(undefined4 *)(*(int *)(iVar1 + 0x4e8) + 0x1c));
      if (iVar2 != 0) {
        (**(code **)(*(int *)(iVar1 + 8) + 0x3b8))(iVar1,iVar2);
      }
    }
  }
  return;
}



/* 409d7d8c glUniformMatrix4fv */

/* Boundary evidence: original MIPS .pdata 409d7d8c..409d7e7f. Semantic name remains unreviewed. */

void glUniformMatrix4fv(undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  
                    /* 0x27d8c  147  glUniformMatrix4fv */
  iVar2 = 0x501;
  if (DAT_409dd38c != 0) {
    if (*(int *)(DAT_409dd38c + 8) == 0) {
      iVar1 = *(int *)(DAT_409dd38c + 0xc);
    }
    else {
      iVar1 = mali_sys_thread_key_get_data(4);
    }
    if (iVar1 != 0) {
      if (param_3 == 0) {
        mali_sys_mutex_lock(*(undefined4 *)(*(int *)(iVar1 + 0x4e8) + 0x1c));
        iVar2 = (**(code **)(*(int *)(iVar1 + 8) + 900))
                          (*(undefined4 *)(iVar1 + 0x4d4),0,4,4,param_2,param_1,param_4);
        mali_sys_mutex_unlock(*(undefined4 *)(*(int *)(iVar1 + 0x4e8) + 0x1c));
        if (iVar2 == 0) {
          return;
        }
      }
      (**(code **)(*(int *)(iVar1 + 8) + 0x3b8))(iVar1,iVar2);
    }
  }
  return;
}



/* 409d7e80 glUniformMatrix3fv */

/* Boundary evidence: original MIPS .pdata 409d7e80..409d7f73. Semantic name remains unreviewed. */

void glUniformMatrix3fv(undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  
                    /* 0x27e80  146  glUniformMatrix3fv */
  iVar2 = 0x501;
  if (DAT_409dd38c != 0) {
    if (*(int *)(DAT_409dd38c + 8) == 0) {
      iVar1 = *(int *)(DAT_409dd38c + 0xc);
    }
    else {
      iVar1 = mali_sys_thread_key_get_data(4);
    }
    if (iVar1 != 0) {
      if (param_3 == 0) {
        mali_sys_mutex_lock(*(undefined4 *)(*(int *)(iVar1 + 0x4e8) + 0x1c));
        iVar2 = (**(code **)(*(int *)(iVar1 + 8) + 0x380))
                          (*(undefined4 *)(iVar1 + 0x4d4),0,3,3,param_2,param_1,param_4);
        mali_sys_mutex_unlock(*(undefined4 *)(*(int *)(iVar1 + 0x4e8) + 0x1c));
        if (iVar2 == 0) {
          return;
        }
      }
      (**(code **)(*(int *)(iVar1 + 8) + 0x3b8))(iVar1,iVar2);
    }
  }
  return;
}



/* 409d7f74 glUniformMatrix2fv */

/* Boundary evidence: original MIPS .pdata 409d7f74..409d8067. Semantic name remains unreviewed. */

void glUniformMatrix2fv(undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  
                    /* 0x27f74  145  glUniformMatrix2fv */
  iVar2 = 0x501;
  if (DAT_409dd38c != 0) {
    if (*(int *)(DAT_409dd38c + 8) == 0) {
      iVar1 = *(int *)(DAT_409dd38c + 0xc);
    }
    else {
      iVar1 = mali_sys_thread_key_get_data(4);
    }
    if (iVar1 != 0) {
      if (param_3 == 0) {
        mali_sys_mutex_lock(*(undefined4 *)(*(int *)(iVar1 + 0x4e8) + 0x1c));
        iVar2 = (**(code **)(*(int *)(iVar1 + 8) + 0x37c))
                          (*(undefined4 *)(iVar1 + 0x4d4),0,2,2,param_2,param_1,param_4);
        mali_sys_mutex_unlock(*(undefined4 *)(*(int *)(iVar1 + 0x4e8) + 0x1c));
        if (iVar2 == 0) {
          return;
        }
      }
      (**(code **)(*(int *)(iVar1 + 8) + 0x3b8))(iVar1,iVar2);
    }
  }
  return;
}



/* 409d8068 glUniform4iv */

/* Boundary evidence: original MIPS .pdata 409d8068..409d813b. Semantic name remains unreviewed. */

void glUniform4iv(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  
                    /* 0x28068  144  glUniform4iv */
  if (DAT_409dd38c != 0) {
    if (*(int *)(DAT_409dd38c + 8) == 0) {
      iVar1 = *(int *)(DAT_409dd38c + 0xc);
    }
    else {
      iVar1 = mali_sys_thread_key_get_data(4);
    }
    if (iVar1 != 0) {
      mali_sys_mutex_lock(*(undefined4 *)(*(int *)(iVar1 + 0x4e8) + 0x1c));
      iVar2 = (**(code **)(*(int *)(iVar1 + 8) + 0x378))
                        (*(undefined4 *)(iVar1 + 0x4d4),3,4,1,param_2,param_1,param_3);
      mali_sys_mutex_unlock(*(undefined4 *)(*(int *)(iVar1 + 0x4e8) + 0x1c));
      if (iVar2 != 0) {
        (**(code **)(*(int *)(iVar1 + 8) + 0x3b8))(iVar1,iVar2);
      }
    }
  }
  return;
}



/* 409d813c glUniform4i */

/* Boundary evidence: original MIPS .pdata 409d813c..409d823b. Semantic name remains unreviewed. */

void glUniform4i(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                undefined4 param_5)

{
  int iVar1;
  int iVar2;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  
                    /* 0x2813c  143  glUniform4i */
  if (DAT_409dd38c == 0) {
    iVar2 = 0;
  }
  else if (*(int *)(DAT_409dd38c + 8) == 0) {
    iVar2 = *(int *)(DAT_409dd38c + 0xc);
  }
  else {
    iVar2 = mali_sys_thread_key_get_data(4);
  }
  local_1c = param_5;
  if (iVar2 != 0) {
    local_28 = param_2;
    local_24 = param_3;
    local_20 = param_4;
    mali_sys_mutex_lock(*(undefined4 *)(*(int *)(iVar2 + 0x4e8) + 0x1c));
    iVar1 = (**(code **)(*(int *)(iVar2 + 8) + 0x374))
                      (*(undefined4 *)(iVar2 + 0x4d4),3,4,1,1,param_1,&local_28);
    mali_sys_mutex_unlock(*(undefined4 *)(*(int *)(iVar2 + 0x4e8) + 0x1c));
    if (iVar1 != 0) {
      (**(code **)(*(int *)(iVar2 + 8) + 0x3b8))(iVar2,iVar1);
    }
  }
  return;
}



/* 409d823c glUniform4fv */

/* Boundary evidence: original MIPS .pdata 409d823c..409d830f. Semantic name remains unreviewed. */

void glUniform4fv(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  
                    /* 0x2823c  142  glUniform4fv */
  if (DAT_409dd38c != 0) {
    if (*(int *)(DAT_409dd38c + 8) == 0) {
      iVar1 = *(int *)(DAT_409dd38c + 0xc);
    }
    else {
      iVar1 = mali_sys_thread_key_get_data(4);
    }
    if (iVar1 != 0) {
      mali_sys_mutex_lock(*(undefined4 *)(*(int *)(iVar1 + 0x4e8) + 0x1c));
      iVar2 = (**(code **)(*(int *)(iVar1 + 8) + 0x370))
                        (*(undefined4 *)(iVar1 + 0x4d4),0,4,1,param_2,param_1,param_3);
      mali_sys_mutex_unlock(*(undefined4 *)(*(int *)(iVar1 + 0x4e8) + 0x1c));
      if (iVar2 != 0) {
        (**(code **)(*(int *)(iVar1 + 8) + 0x3b8))(iVar1,iVar2);
      }
    }
  }
  return;
}



/* 409d8310 glUniform4f */

/* Boundary evidence: original MIPS .pdata 409d8310..409d840f. Semantic name remains unreviewed. */

void glUniform4f(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                undefined4 param_5)

{
  int iVar1;
  int iVar2;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  
                    /* 0x28310  141  glUniform4f */
  if (DAT_409dd38c == 0) {
    iVar2 = 0;
  }
  else if (*(int *)(DAT_409dd38c + 8) == 0) {
    iVar2 = *(int *)(DAT_409dd38c + 0xc);
  }
  else {
    iVar2 = mali_sys_thread_key_get_data(4);
  }
  local_1c = param_5;
  if (iVar2 != 0) {
    local_28 = param_2;
    local_24 = param_3;
    local_20 = param_4;
    mali_sys_mutex_lock(*(undefined4 *)(*(int *)(iVar2 + 0x4e8) + 0x1c));
    iVar1 = (**(code **)(*(int *)(iVar2 + 8) + 0x36c))
                      (*(undefined4 *)(iVar2 + 0x4d4),0,4,1,1,param_1,&local_28);
    mali_sys_mutex_unlock(*(undefined4 *)(*(int *)(iVar2 + 0x4e8) + 0x1c));
    if (iVar1 != 0) {
      (**(code **)(*(int *)(iVar2 + 8) + 0x3b8))(iVar2,iVar1);
    }
  }
  return;
}



/* 409d8410 glUniform3iv */

/* Boundary evidence: original MIPS .pdata 409d8410..409d84e3. Semantic name remains unreviewed. */

void glUniform3iv(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  
                    /* 0x28410  140  glUniform3iv */
  if (DAT_409dd38c != 0) {
    if (*(int *)(DAT_409dd38c + 8) == 0) {
      iVar1 = *(int *)(DAT_409dd38c + 0xc);
    }
    else {
      iVar1 = mali_sys_thread_key_get_data(4);
    }
    if (iVar1 != 0) {
      mali_sys_mutex_lock(*(undefined4 *)(*(int *)(iVar1 + 0x4e8) + 0x1c));
      iVar2 = (**(code **)(*(int *)(iVar1 + 8) + 0x368))
                        (*(undefined4 *)(iVar1 + 0x4d4),3,3,1,param_2,param_1,param_3);
      mali_sys_mutex_unlock(*(undefined4 *)(*(int *)(iVar1 + 0x4e8) + 0x1c));
      if (iVar2 != 0) {
        (**(code **)(*(int *)(iVar1 + 8) + 0x3b8))(iVar1,iVar2);
      }
    }
  }
  return;
}



/* 409d84e4 glUniform3i */

/* Boundary evidence: original MIPS .pdata 409d84e4..409d85db. Semantic name remains unreviewed. */

void glUniform3i(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  
                    /* 0x284e4  139  glUniform3i */
  if (DAT_409dd38c == 0) {
    iVar2 = 0;
  }
  else if (*(int *)(DAT_409dd38c + 8) == 0) {
    iVar2 = *(int *)(DAT_409dd38c + 0xc);
  }
  else {
    iVar2 = mali_sys_thread_key_get_data(4);
  }
  if (iVar2 != 0) {
    local_28 = param_2;
    local_24 = param_3;
    local_20 = param_4;
    mali_sys_mutex_lock(*(undefined4 *)(*(int *)(iVar2 + 0x4e8) + 0x1c));
    iVar1 = (**(code **)(*(int *)(iVar2 + 8) + 0x364))
                      (*(undefined4 *)(iVar2 + 0x4d4),3,3,1,1,param_1,&local_28);
    mali_sys_mutex_unlock(*(undefined4 *)(*(int *)(iVar2 + 0x4e8) + 0x1c));
    if (iVar1 != 0) {
      (**(code **)(*(int *)(iVar2 + 8) + 0x3b8))(iVar2,iVar1);
    }
  }
  return;
}



/* 409d85dc glUniform3fv */

/* Boundary evidence: original MIPS .pdata 409d85dc..409d86af. Semantic name remains unreviewed. */

void glUniform3fv(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  
                    /* 0x285dc  138  glUniform3fv */
  if (DAT_409dd38c != 0) {
    if (*(int *)(DAT_409dd38c + 8) == 0) {
      iVar1 = *(int *)(DAT_409dd38c + 0xc);
    }
    else {
      iVar1 = mali_sys_thread_key_get_data(4);
    }
    if (iVar1 != 0) {
      mali_sys_mutex_lock(*(undefined4 *)(*(int *)(iVar1 + 0x4e8) + 0x1c));
      iVar2 = (**(code **)(*(int *)(iVar1 + 8) + 0x360))
                        (*(undefined4 *)(iVar1 + 0x4d4),0,3,1,param_2,param_1,param_3);
      mali_sys_mutex_unlock(*(undefined4 *)(*(int *)(iVar1 + 0x4e8) + 0x1c));
      if (iVar2 != 0) {
        (**(code **)(*(int *)(iVar1 + 8) + 0x3b8))(iVar1,iVar2);
      }
    }
  }
  return;
}



/* 409d86b0 glUniform3f */

/* Boundary evidence: original MIPS .pdata 409d86b0..409d87a7. Semantic name remains unreviewed. */

void glUniform3f(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  
                    /* 0x286b0  137  glUniform3f */
  if (DAT_409dd38c == 0) {
    iVar2 = 0;
  }
  else if (*(int *)(DAT_409dd38c + 8) == 0) {
    iVar2 = *(int *)(DAT_409dd38c + 0xc);
  }
  else {
    iVar2 = mali_sys_thread_key_get_data(4);
  }
  if (iVar2 != 0) {
    local_28 = param_2;
    local_24 = param_3;
    local_20 = param_4;
    mali_sys_mutex_lock(*(undefined4 *)(*(int *)(iVar2 + 0x4e8) + 0x1c));
    iVar1 = (**(code **)(*(int *)(iVar2 + 8) + 0x35c))
                      (*(undefined4 *)(iVar2 + 0x4d4),0,3,1,1,param_1,&local_28);
    mali_sys_mutex_unlock(*(undefined4 *)(*(int *)(iVar2 + 0x4e8) + 0x1c));
    if (iVar1 != 0) {
      (**(code **)(*(int *)(iVar2 + 8) + 0x3b8))(iVar2,iVar1);
    }
  }
  return;
}



/* 409d87a8 glUniform2iv */

/* Boundary evidence: original MIPS .pdata 409d87a8..409d887b. Semantic name remains unreviewed. */

void glUniform2iv(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  
                    /* 0x287a8  136  glUniform2iv */
  if (DAT_409dd38c != 0) {
    if (*(int *)(DAT_409dd38c + 8) == 0) {
      iVar1 = *(int *)(DAT_409dd38c + 0xc);
    }
    else {
      iVar1 = mali_sys_thread_key_get_data(4);
    }
    if (iVar1 != 0) {
      mali_sys_mutex_lock(*(undefined4 *)(*(int *)(iVar1 + 0x4e8) + 0x1c));
      iVar2 = (**(code **)(*(int *)(iVar1 + 8) + 0x358))
                        (*(undefined4 *)(iVar1 + 0x4d4),3,2,1,param_2,param_1,param_3);
      mali_sys_mutex_unlock(*(undefined4 *)(*(int *)(iVar1 + 0x4e8) + 0x1c));
      if (iVar2 != 0) {
        (**(code **)(*(int *)(iVar1 + 8) + 0x3b8))(iVar1,iVar2);
      }
    }
  }
  return;
}



/* 409d887c glUniform2i */

/* Boundary evidence: original MIPS .pdata 409d887c..409d8963. Semantic name remains unreviewed. */

void glUniform2i(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  undefined4 local_20;
  undefined4 local_1c;
  
                    /* 0x2887c  135  glUniform2i */
  if (DAT_409dd38c == 0) {
    iVar2 = 0;
  }
  else if (*(int *)(DAT_409dd38c + 8) == 0) {
    iVar2 = *(int *)(DAT_409dd38c + 0xc);
  }
  else {
    iVar2 = mali_sys_thread_key_get_data(4);
  }
  if (iVar2 != 0) {
    local_20 = param_2;
    local_1c = param_3;
    mali_sys_mutex_lock(*(undefined4 *)(*(int *)(iVar2 + 0x4e8) + 0x1c));
    iVar1 = (**(code **)(*(int *)(iVar2 + 8) + 0x354))
                      (*(undefined4 *)(iVar2 + 0x4d4),3,2,1,1,param_1,&local_20);
    mali_sys_mutex_unlock(*(undefined4 *)(*(int *)(iVar2 + 0x4e8) + 0x1c));
    if (iVar1 != 0) {
      (**(code **)(*(int *)(iVar2 + 8) + 0x3b8))(iVar2,iVar1);
    }
  }
  return;
}



/* 409d8964 glUniform2fv */

/* Boundary evidence: original MIPS .pdata 409d8964..409d8a37. Semantic name remains unreviewed. */

void glUniform2fv(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  
                    /* 0x28964  134  glUniform2fv */
  if (DAT_409dd38c != 0) {
    if (*(int *)(DAT_409dd38c + 8) == 0) {
      iVar1 = *(int *)(DAT_409dd38c + 0xc);
    }
    else {
      iVar1 = mali_sys_thread_key_get_data(4);
    }
    if (iVar1 != 0) {
      mali_sys_mutex_lock(*(undefined4 *)(*(int *)(iVar1 + 0x4e8) + 0x1c));
      iVar2 = (**(code **)(*(int *)(iVar1 + 8) + 0x350))
                        (*(undefined4 *)(iVar1 + 0x4d4),0,2,1,param_2,param_1,param_3);
      mali_sys_mutex_unlock(*(undefined4 *)(*(int *)(iVar1 + 0x4e8) + 0x1c));
      if (iVar2 != 0) {
        (**(code **)(*(int *)(iVar1 + 8) + 0x3b8))(iVar1,iVar2);
      }
    }
  }
  return;
}



/* 409d8a38 glUniform2f */

/* Boundary evidence: original MIPS .pdata 409d8a38..409d8b1f. Semantic name remains unreviewed. */

void glUniform2f(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  undefined4 local_20;
  undefined4 local_1c;
  
                    /* 0x28a38  133  glUniform2f */
  if (DAT_409dd38c == 0) {
    iVar2 = 0;
  }
  else if (*(int *)(DAT_409dd38c + 8) == 0) {
    iVar2 = *(int *)(DAT_409dd38c + 0xc);
  }
  else {
    iVar2 = mali_sys_thread_key_get_data(4);
  }
  if (iVar2 != 0) {
    local_20 = param_2;
    local_1c = param_3;
    mali_sys_mutex_lock(*(undefined4 *)(*(int *)(iVar2 + 0x4e8) + 0x1c));
    iVar1 = (**(code **)(*(int *)(iVar2 + 8) + 0x34c))
                      (*(undefined4 *)(iVar2 + 0x4d4),0,2,1,1,param_1,&local_20);
    mali_sys_mutex_unlock(*(undefined4 *)(*(int *)(iVar2 + 0x4e8) + 0x1c));
    if (iVar1 != 0) {
      (**(code **)(*(int *)(iVar2 + 8) + 0x3b8))(iVar2,iVar1);
    }
  }
  return;
}



/* 409d8b20 glUniform1iv */

/* Boundary evidence: original MIPS .pdata 409d8b20..409d8bf3. Semantic name remains unreviewed. */

void glUniform1iv(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  
                    /* 0x28b20  132  glUniform1iv */
  if (DAT_409dd38c != 0) {
    if (*(int *)(DAT_409dd38c + 8) == 0) {
      iVar1 = *(int *)(DAT_409dd38c + 0xc);
    }
    else {
      iVar1 = mali_sys_thread_key_get_data(4);
    }
    if (iVar1 != 0) {
      mali_sys_mutex_lock(*(undefined4 *)(*(int *)(iVar1 + 0x4e8) + 0x1c));
      iVar2 = (**(code **)(*(int *)(iVar1 + 8) + 0x348))
                        (*(undefined4 *)(iVar1 + 0x4d4),3,1,1,param_2,param_1,param_3);
      mali_sys_mutex_unlock(*(undefined4 *)(*(int *)(iVar1 + 0x4e8) + 0x1c));
      if (iVar2 != 0) {
        (**(code **)(*(int *)(iVar1 + 8) + 0x3b8))(iVar1,iVar2);
      }
    }
  }
  return;
}



/* 409d8bf4 glUniform1i */

/* Boundary evidence: original MIPS .pdata 409d8bf4..409d8cab. Semantic name remains unreviewed. */

void glUniform1i(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  
                    /* 0x28bf4  131  glUniform1i */
  if (DAT_409dd38c != 0) {
    if (*(int *)(DAT_409dd38c + 8) == 0) {
      iVar1 = *(int *)(DAT_409dd38c + 0xc);
    }
    else {
      iVar1 = mali_sys_thread_key_get_data(4);
    }
    if (iVar1 != 0) {
      mali_sys_mutex_lock(*(undefined4 *)(*(int *)(iVar1 + 0x4e8) + 0x1c));
      iVar2 = (**(code **)(*(int *)(iVar1 + 8) + 0x344))
                        (*(undefined4 *)(iVar1 + 0x4d4),param_1,param_2);
      mali_sys_mutex_unlock(*(undefined4 *)(*(int *)(iVar1 + 0x4e8) + 0x1c));
      if (iVar2 != 0) {
        (**(code **)(*(int *)(iVar1 + 8) + 0x3b8))(iVar1,iVar2);
      }
    }
  }
  return;
}



/* 409d8cac glUniform1fv */

/* Boundary evidence: original MIPS .pdata 409d8cac..409d8d7f. Semantic name remains unreviewed. */

void glUniform1fv(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  
                    /* 0x28cac  130  glUniform1fv */
  if (DAT_409dd38c != 0) {
    if (*(int *)(DAT_409dd38c + 8) == 0) {
      iVar1 = *(int *)(DAT_409dd38c + 0xc);
    }
    else {
      iVar1 = mali_sys_thread_key_get_data(4);
    }
    if (iVar1 != 0) {
      mali_sys_mutex_lock(*(undefined4 *)(*(int *)(iVar1 + 0x4e8) + 0x1c));
      iVar2 = (**(code **)(*(int *)(iVar1 + 8) + 0x340))
                        (*(undefined4 *)(iVar1 + 0x4d4),0,1,1,param_2,param_1,param_3);
      mali_sys_mutex_unlock(*(undefined4 *)(*(int *)(iVar1 + 0x4e8) + 0x1c));
      if (iVar2 != 0) {
        (**(code **)(*(int *)(iVar1 + 8) + 0x3b8))(iVar1,iVar2);
      }
    }
  }
  return;
}



/* 409d8d80 glUniform1f */

/* Boundary evidence: original MIPS .pdata 409d8d80..409d8e47. Semantic name remains unreviewed. */

void glUniform1f(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  undefined4 local_res4 [3];
  
                    /* 0x28d80  129  glUniform1f */
  if (DAT_409dd38c != 0) {
    local_res4[0] = param_2;
    if (*(int *)(DAT_409dd38c + 8) == 0) {
      iVar1 = *(int *)(DAT_409dd38c + 0xc);
    }
    else {
      iVar1 = mali_sys_thread_key_get_data(4);
    }
    if (iVar1 != 0) {
      mali_sys_mutex_lock(*(undefined4 *)(*(int *)(iVar1 + 0x4e8) + 0x1c));
      iVar2 = (**(code **)(*(int *)(iVar1 + 8) + 0x33c))
                        (*(undefined4 *)(iVar1 + 0x4d4),0,1,1,1,param_1,local_res4);
      mali_sys_mutex_unlock(*(undefined4 *)(*(int *)(iVar1 + 0x4e8) + 0x1c));
      if (iVar2 != 0) {
        (**(code **)(*(int *)(iVar1 + 8) + 0x3b8))(iVar1,iVar2);
      }
    }
  }
  return;
}



/* 409d8e48 glShaderSource */

/* Boundary evidence: original MIPS .pdata 409d8e48..409d8f23. Semantic name remains unreviewed. */

void glShaderSource(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  
                    /* 0x28e48  116  glShaderSource */
  if (DAT_409dd38c != 0) {
    if (*(int *)(DAT_409dd38c + 8) == 0) {
      iVar1 = *(int *)(DAT_409dd38c + 0xc);
    }
    else {
      iVar1 = mali_sys_thread_key_get_data(4);
    }
    if (iVar1 != 0) {
      mali_sys_mutex_lock(*(undefined4 *)(*(int *)(iVar1 + 0x4e8) + 0x1c));
      iVar2 = (**(code **)(*(int *)(iVar1 + 8) + 0x32c))
                        (*(undefined4 *)(*(int *)(iVar1 + 0x4e8) + 0x18),param_1,param_2,param_3,
                         param_4);
      mali_sys_mutex_unlock(*(undefined4 *)(*(int *)(iVar1 + 0x4e8) + 0x1c));
      if (iVar2 != 0) {
        (**(code **)(*(int *)(iVar1 + 8) + 0x3b8))(iVar1,iVar2);
      }
    }
  }
  return;
}



/* 409d8f24 glShaderBinary */

/* Boundary evidence: original MIPS .pdata 409d8f24..409d9007. Semantic name remains unreviewed. */

void glShaderBinary(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                   undefined4 param_5)

{
  int iVar1;
  int iVar2;
  
                    /* 0x28f24  115  glShaderBinary */
  if (DAT_409dd38c != 0) {
    if (*(int *)(DAT_409dd38c + 8) == 0) {
      iVar1 = *(int *)(DAT_409dd38c + 0xc);
    }
    else {
      iVar1 = mali_sys_thread_key_get_data(4);
    }
    if (iVar1 != 0) {
      mali_sys_mutex_lock(*(undefined4 *)(*(int *)(iVar1 + 0x4e8) + 0x1c));
      iVar2 = (**(code **)(*(int *)(iVar1 + 8) + 0x328))
                        (*(undefined4 *)(*(int *)(iVar1 + 0x4e8) + 0x18),param_1,param_2,param_3,
                         param_4,param_5);
      mali_sys_mutex_unlock(*(undefined4 *)(*(int *)(iVar1 + 0x4e8) + 0x1c));
      if (iVar2 != 0) {
        (**(code **)(*(int *)(iVar1 + 8) + 0x3b8))(iVar1,iVar2);
      }
    }
  }
  return;
}



/* 409d9008 glReleaseShaderCompiler */

/* Boundary evidence: original MIPS .pdata 409d9008..409d90ab. Semantic name remains unreviewed. */

void glReleaseShaderCompiler(void)

{
  int iVar1;
  int iVar2;
  
                    /* 0x29008  111  glReleaseShaderCompiler */
  if (DAT_409dd38c != 0) {
    if (*(int *)(DAT_409dd38c + 8) == 0) {
      iVar1 = *(int *)(DAT_409dd38c + 0xc);
    }
    else {
      iVar1 = mali_sys_thread_key_get_data(4);
    }
    if (iVar1 != 0) {
      mali_sys_mutex_lock(*(undefined4 *)(*(int *)(iVar1 + 0x4e8) + 0x1c));
      iVar2 = (**(code **)(*(int *)(iVar1 + 8) + 0x324))();
      mali_sys_mutex_unlock(*(undefined4 *)(*(int *)(iVar1 + 0x4e8) + 0x1c));
      if (iVar2 != 0) {
        (**(code **)(*(int *)(iVar1 + 8) + 0x3b8))(iVar1,iVar2);
      }
    }
  }
  return;
}



/* 409d90ac glLinkProgram */

/* Boundary evidence: original MIPS .pdata 409d90ac..409d915b. Semantic name remains unreviewed. */

void glLinkProgram(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  
                    /* 0x290ac  107  glLinkProgram */
  if (DAT_409dd38c != 0) {
    if (*(int *)(DAT_409dd38c + 8) == 0) {
      iVar1 = *(int *)(DAT_409dd38c + 0xc);
    }
    else {
      iVar1 = mali_sys_thread_key_get_data(4);
    }
    if (iVar1 != 0) {
      mali_sys_mutex_lock(*(undefined4 *)(*(int *)(iVar1 + 0x4e8) + 0x1c));
      iVar2 = (**(code **)(*(int *)(iVar1 + 8) + 800))
                        (iVar1,*(undefined4 *)(*(int *)(iVar1 + 0x4e8) + 0x18),param_1);
      mali_sys_mutex_unlock(*(undefined4 *)(*(int *)(iVar1 + 0x4e8) + 0x1c));
      if (iVar2 != 0) {
        (**(code **)(*(int *)(iVar1 + 8) + 0x3b8))(iVar1,iVar2);
      }
    }
  }
  return;
}



/* 409d915c glIsShader */

/* Boundary evidence: original MIPS .pdata 409d915c..409d9207. Semantic name remains unreviewed. */

undefined4 glIsShader(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  
                    /* 0x2915c  104  glIsShader */
  if (DAT_409dd38c != 0) {
    if (*(int *)(DAT_409dd38c + 8) == 0) {
      iVar1 = *(int *)(DAT_409dd38c + 0xc);
    }
    else {
      iVar1 = mali_sys_thread_key_get_data(4);
    }
    if (iVar1 != 0) {
      mali_sys_mutex_lock(*(undefined4 *)(*(int *)(iVar1 + 0x4e8) + 0x1c));
      uVar2 = (**(code **)(*(int *)(iVar1 + 8) + 0x31c))
                        (*(undefined4 *)(*(int *)(iVar1 + 0x4e8) + 0x18),param_1);
      mali_sys_mutex_unlock(*(undefined4 *)(*(int *)(iVar1 + 0x4e8) + 0x1c));
      return uVar2;
    }
  }
  return 0;
}



/* 409d9208 glIsProgram */

/* Boundary evidence: original MIPS .pdata 409d9208..409d92b3. Semantic name remains unreviewed. */

undefined4 glIsProgram(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  
                    /* 0x29208  102  glIsProgram */
  if (DAT_409dd38c != 0) {
    if (*(int *)(DAT_409dd38c + 8) == 0) {
      iVar1 = *(int *)(DAT_409dd38c + 0xc);
    }
    else {
      iVar1 = mali_sys_thread_key_get_data(4);
    }
    if (iVar1 != 0) {
      mali_sys_mutex_lock(*(undefined4 *)(*(int *)(iVar1 + 0x4e8) + 0x1c));
      uVar2 = (**(code **)(*(int *)(iVar1 + 8) + 0x318))
                        (*(undefined4 *)(*(int *)(iVar1 + 0x4e8) + 0x18),param_1);
      mali_sys_mutex_unlock(*(undefined4 *)(*(int *)(iVar1 + 0x4e8) + 0x1c));
      return uVar2;
    }
  }
  return 0;
}



/* 409d92b4 glGetVertexAttribiv */

/* Boundary evidence: original MIPS .pdata 409d92b4..409d937f. Semantic name remains unreviewed. */

void glGetVertexAttribiv(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  
                    /* 0x292b4  97  glGetVertexAttribiv */
  if (DAT_409dd38c != 0) {
    if (*(int *)(DAT_409dd38c + 8) == 0) {
      iVar1 = *(int *)(DAT_409dd38c + 0xc);
    }
    else {
      iVar1 = mali_sys_thread_key_get_data(4);
    }
    if (iVar1 != 0) {
      mali_sys_mutex_lock(*(undefined4 *)(*(int *)(iVar1 + 0x4e8) + 0x1c));
      iVar2 = (**(code **)(*(int *)(iVar1 + 8) + 0x310))(iVar1 + 0x14,param_1,param_2,3,param_3);
      mali_sys_mutex_unlock(*(undefined4 *)(*(int *)(iVar1 + 0x4e8) + 0x1c));
      if (iVar2 != 0) {
        (**(code **)(*(int *)(iVar1 + 8) + 0x3b8))(iVar1,iVar2);
      }
    }
  }
  return;
}



/* 409d9380 glGetVertexAttribfv */

/* Boundary evidence: original MIPS .pdata 409d9380..409d944b. Semantic name remains unreviewed. */

void glGetVertexAttribfv(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  
                    /* 0x29380  96  glGetVertexAttribfv */
  if (DAT_409dd38c != 0) {
    if (*(int *)(DAT_409dd38c + 8) == 0) {
      iVar1 = *(int *)(DAT_409dd38c + 0xc);
    }
    else {
      iVar1 = mali_sys_thread_key_get_data(4);
    }
    if (iVar1 != 0) {
      mali_sys_mutex_lock(*(undefined4 *)(*(int *)(iVar1 + 0x4e8) + 0x1c));
      iVar2 = (**(code **)(*(int *)(iVar1 + 8) + 0x30c))(iVar1 + 0x14,param_1,param_2,0,param_3);
      mali_sys_mutex_unlock(*(undefined4 *)(*(int *)(iVar1 + 0x4e8) + 0x1c));
      if (iVar2 != 0) {
        (**(code **)(*(int *)(iVar1 + 8) + 0x3b8))(iVar1,iVar2);
      }
    }
  }
  return;
}



/* 409d944c glGetUniformLocation */

/* Boundary evidence: original MIPS .pdata 409d944c..409d951f. Semantic name remains unreviewed. */

undefined4 glGetUniformLocation(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  undefined4 local_18 [2];
  
                    /* 0x2944c  92  glGetUniformLocation */
  local_18[0] = 0xffffffff;
  if (DAT_409dd38c != 0) {
    if (*(int *)(DAT_409dd38c + 8) == 0) {
      iVar1 = *(int *)(DAT_409dd38c + 0xc);
    }
    else {
      iVar1 = mali_sys_thread_key_get_data(4);
    }
    if (iVar1 != 0) {
      mali_sys_mutex_lock(*(undefined4 *)(*(int *)(iVar1 + 0x4e8) + 0x1c));
      iVar2 = (**(code **)(*(int *)(iVar1 + 8) + 0x308))
                        (*(undefined4 *)(*(int *)(iVar1 + 0x4e8) + 0x18),param_1,param_2,local_18);
      mali_sys_mutex_unlock(*(undefined4 *)(*(int *)(iVar1 + 0x4e8) + 0x1c));
      if (iVar2 == 0) {
        return local_18[0];
      }
      (**(code **)(*(int *)(iVar1 + 8) + 0x3b8))(iVar1,iVar2);
      return local_18[0];
    }
  }
  return 0;
}



/* 409d9520 glGetUniformiv */

/* Boundary evidence: original MIPS .pdata 409d9520..409d95f3. Semantic name remains unreviewed. */

void glGetUniformiv(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  
                    /* 0x29520  94  glGetUniformiv */
  if (DAT_409dd38c != 0) {
    if (*(int *)(DAT_409dd38c + 8) == 0) {
      iVar1 = *(int *)(DAT_409dd38c + 0xc);
    }
    else {
      iVar1 = mali_sys_thread_key_get_data(4);
    }
    if (iVar1 != 0) {
      mali_sys_mutex_lock(*(undefined4 *)(*(int *)(iVar1 + 0x4e8) + 0x1c));
      iVar2 = (**(code **)(*(int *)(iVar1 + 8) + 0x304))
                        (*(undefined4 *)(*(int *)(iVar1 + 0x4e8) + 0x18),param_1,param_2,param_3,3);
      mali_sys_mutex_unlock(*(undefined4 *)(*(int *)(iVar1 + 0x4e8) + 0x1c));
      if (iVar2 != 0) {
        (**(code **)(*(int *)(iVar1 + 8) + 0x3b8))(iVar1,iVar2);
      }
    }
  }
  return;
}



/* 409d95f4 glGetUniformfv */

/* Boundary evidence: original MIPS .pdata 409d95f4..409d96c3. Semantic name remains unreviewed. */

void glGetUniformfv(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  
                    /* 0x295f4  93  glGetUniformfv */
  if (DAT_409dd38c != 0) {
    if (*(int *)(DAT_409dd38c + 8) == 0) {
      iVar1 = *(int *)(DAT_409dd38c + 0xc);
    }
    else {
      iVar1 = mali_sys_thread_key_get_data(4);
    }
    if (iVar1 != 0) {
      mali_sys_mutex_lock(*(undefined4 *)(*(int *)(iVar1 + 0x4e8) + 0x1c));
      iVar2 = (**(code **)(*(int *)(iVar1 + 8) + 0x300))
                        (*(undefined4 *)(*(int *)(iVar1 + 0x4e8) + 0x18),param_1,param_2,param_3,0);
      mali_sys_mutex_unlock(*(undefined4 *)(*(int *)(iVar1 + 0x4e8) + 0x1c));
      if (iVar2 != 0) {
        (**(code **)(*(int *)(iVar1 + 8) + 0x3b8))(iVar1,iVar2);
      }
    }
  }
  return;
}



/* 409d96c4 glGetShaderSource */

/* Boundary evidence: original MIPS .pdata 409d96c4..409d979f. Semantic name remains unreviewed. */

void glGetShaderSource(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  
                    /* 0x296c4  87  glGetShaderSource */
  if (DAT_409dd38c != 0) {
    if (*(int *)(DAT_409dd38c + 8) == 0) {
      iVar1 = *(int *)(DAT_409dd38c + 0xc);
    }
    else {
      iVar1 = mali_sys_thread_key_get_data(4);
    }
    if (iVar1 != 0) {
      mali_sys_mutex_lock(*(undefined4 *)(*(int *)(iVar1 + 0x4e8) + 0x1c));
      iVar2 = (**(code **)(*(int *)(iVar1 + 8) + 0x2fc))
                        (*(undefined4 *)(*(int *)(iVar1 + 0x4e8) + 0x18),param_1,param_2,param_3,
                         param_4);
      mali_sys_mutex_unlock(*(undefined4 *)(*(int *)(iVar1 + 0x4e8) + 0x1c));
      if (iVar2 != 0) {
        (**(code **)(*(int *)(iVar1 + 8) + 0x3b8))(iVar1,iVar2);
      }
    }
  }
  return;
}



/* 409d97a0 glGetShaderiv */

/* Boundary evidence: original MIPS .pdata 409d97a0..409d986b. Semantic name remains unreviewed. */

void glGetShaderiv(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  
                    /* 0x297a0  88  glGetShaderiv */
  if (DAT_409dd38c != 0) {
    if (*(int *)(DAT_409dd38c + 8) == 0) {
      iVar1 = *(int *)(DAT_409dd38c + 0xc);
    }
    else {
      iVar1 = mali_sys_thread_key_get_data(4);
    }
    if (iVar1 != 0) {
      mali_sys_mutex_lock(*(undefined4 *)(*(int *)(iVar1 + 0x4e8) + 0x1c));
      iVar2 = (**(code **)(*(int *)(iVar1 + 8) + 0x2f4))
                        (*(undefined4 *)(*(int *)(iVar1 + 0x4e8) + 0x18),param_1,param_2,param_3);
      mali_sys_mutex_unlock(*(undefined4 *)(*(int *)(iVar1 + 0x4e8) + 0x1c));
      if (iVar2 != 0) {
        (**(code **)(*(int *)(iVar1 + 8) + 0x3b8))(iVar1,iVar2);
      }
    }
  }
  return;
}



/* 409d986c glGetShaderInfoLog */

/* Boundary evidence: original MIPS .pdata 409d986c..409d9947. Semantic name remains unreviewed. */

void glGetShaderInfoLog(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  
                    /* 0x2986c  85  glGetShaderInfoLog */
  if (DAT_409dd38c != 0) {
    if (*(int *)(DAT_409dd38c + 8) == 0) {
      iVar1 = *(int *)(DAT_409dd38c + 0xc);
    }
    else {
      iVar1 = mali_sys_thread_key_get_data(4);
    }
    if (iVar1 != 0) {
      mali_sys_mutex_lock(*(undefined4 *)(*(int *)(iVar1 + 0x4e8) + 0x1c));
      iVar2 = (**(code **)(*(int *)(iVar1 + 8) + 0x2f0))
                        (*(undefined4 *)(*(int *)(iVar1 + 0x4e8) + 0x18),param_1,param_2,param_3,
                         param_4);
      mali_sys_mutex_unlock(*(undefined4 *)(*(int *)(iVar1 + 0x4e8) + 0x1c));
      if (iVar2 != 0) {
        (**(code **)(*(int *)(iVar1 + 8) + 0x3b8))(iVar1,iVar2);
      }
    }
  }
  return;
}



/* 409d9948 glGetProgramiv */

/* Boundary evidence: original MIPS .pdata 409d9948..409d9a13. Semantic name remains unreviewed. */

void glGetProgramiv(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  
                    /* 0x29948  83  glGetProgramiv */
  if (DAT_409dd38c != 0) {
    if (*(int *)(DAT_409dd38c + 8) == 0) {
      iVar1 = *(int *)(DAT_409dd38c + 0xc);
    }
    else {
      iVar1 = mali_sys_thread_key_get_data(4);
    }
    if (iVar1 != 0) {
      mali_sys_mutex_lock(*(undefined4 *)(*(int *)(iVar1 + 0x4e8) + 0x1c));
      iVar2 = (**(code **)(*(int *)(iVar1 + 8) + 0x2ec))
                        (*(undefined4 *)(*(int *)(iVar1 + 0x4e8) + 0x18),param_1,param_2,param_3);
      mali_sys_mutex_unlock(*(undefined4 *)(*(int *)(iVar1 + 0x4e8) + 0x1c));
      if (iVar2 != 0) {
        (**(code **)(*(int *)(iVar1 + 8) + 0x3b8))(iVar1,iVar2);
      }
    }
  }
  return;
}



/* 409d9a14 glGetProgramInfoLog */

/* Boundary evidence: original MIPS .pdata 409d9a14..409d9aef. Semantic name remains unreviewed. */

void glGetProgramInfoLog(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4
                        )

{
  int iVar1;
  int iVar2;
  
                    /* 0x29a14  82  glGetProgramInfoLog */
  if (DAT_409dd38c != 0) {
    if (*(int *)(DAT_409dd38c + 8) == 0) {
      iVar1 = *(int *)(DAT_409dd38c + 0xc);
    }
    else {
      iVar1 = mali_sys_thread_key_get_data(4);
    }
    if (iVar1 != 0) {
      mali_sys_mutex_lock(*(undefined4 *)(*(int *)(iVar1 + 0x4e8) + 0x1c));
      iVar2 = (**(code **)(*(int *)(iVar1 + 8) + 0x2e8))
                        (*(undefined4 *)(*(int *)(iVar1 + 0x4e8) + 0x18),param_1,param_2,param_3,
                         param_4);
      mali_sys_mutex_unlock(*(undefined4 *)(*(int *)(iVar1 + 0x4e8) + 0x1c));
      if (iVar2 != 0) {
        (**(code **)(*(int *)(iVar1 + 8) + 0x3b8))(iVar1,iVar2);
      }
    }
  }
  return;
}



/* 409d9af0 glGetAttribLocation */

/* Boundary evidence: original MIPS .pdata 409d9af0..409d9bc3. Semantic name remains unreviewed. */

undefined4 glGetAttribLocation(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  undefined4 local_18 [2];
  
                    /* 0x29af0  75  glGetAttribLocation */
  local_18[0] = 0xffffffff;
  if (DAT_409dd38c != 0) {
    if (*(int *)(DAT_409dd38c + 8) == 0) {
      iVar1 = *(int *)(DAT_409dd38c + 0xc);
    }
    else {
      iVar1 = mali_sys_thread_key_get_data(4);
    }
    if (iVar1 != 0) {
      mali_sys_mutex_lock(*(undefined4 *)(*(int *)(iVar1 + 0x4e8) + 0x1c));
      iVar2 = (**(code **)(*(int *)(iVar1 + 8) + 0x2e4))
                        (*(undefined4 *)(*(int *)(iVar1 + 0x4e8) + 0x18),param_1,param_2,local_18);
      mali_sys_mutex_unlock(*(undefined4 *)(*(int *)(iVar1 + 0x4e8) + 0x1c));
      if (iVar2 == 0) {
        return local_18[0];
      }
      (**(code **)(*(int *)(iVar1 + 8) + 0x3b8))(iVar1,iVar2);
      return local_18[0];
    }
  }
  return 0;
}



/* 409d9bc4 glGetAttachedShaders */

/* Boundary evidence: original MIPS .pdata 409d9bc4..409d9c9f. Semantic name remains unreviewed. */

void glGetAttachedShaders
               (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  
                    /* 0x29bc4  74  glGetAttachedShaders */
  if (DAT_409dd38c != 0) {
    if (*(int *)(DAT_409dd38c + 8) == 0) {
      iVar1 = *(int *)(DAT_409dd38c + 0xc);
    }
    else {
      iVar1 = mali_sys_thread_key_get_data(4);
    }
    if (iVar1 != 0) {
      mali_sys_mutex_lock(*(undefined4 *)(*(int *)(iVar1 + 0x4e8) + 0x1c));
      iVar2 = (**(code **)(*(int *)(iVar1 + 8) + 0x2e0))
                        (*(undefined4 *)(*(int *)(iVar1 + 0x4e8) + 0x18),param_1,param_2,param_3,
                         param_4);
      mali_sys_mutex_unlock(*(undefined4 *)(*(int *)(iVar1 + 0x4e8) + 0x1c));
      if (iVar2 != 0) {
        (**(code **)(*(int *)(iVar1 + 8) + 0x3b8))(iVar1,iVar2);
      }
    }
  }
  return;
}



/* 409d9ca0 glGetActiveUniform */

/* Boundary evidence: original MIPS .pdata 409d9ca0..409d9d93. Semantic name remains unreviewed. */

void glGetActiveUniform(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                       undefined4 param_5,undefined4 param_6,undefined4 param_7)

{
  int iVar1;
  int iVar2;
  
                    /* 0x29ca0  73  glGetActiveUniform */
  if (DAT_409dd38c != 0) {
    if (*(int *)(DAT_409dd38c + 8) == 0) {
      iVar1 = *(int *)(DAT_409dd38c + 0xc);
    }
    else {
      iVar1 = mali_sys_thread_key_get_data(4);
    }
    if (iVar1 != 0) {
      mali_sys_mutex_lock(*(undefined4 *)(*(int *)(iVar1 + 0x4e8) + 0x1c));
      iVar2 = (**(code **)(*(int *)(iVar1 + 8) + 0x2dc))
                        (*(undefined4 *)(*(int *)(iVar1 + 0x4e8) + 0x18),param_1,param_2,param_3,
                         param_4,param_5,param_6,param_7);
      mali_sys_mutex_unlock(*(undefined4 *)(*(int *)(iVar1 + 0x4e8) + 0x1c));
      if (iVar2 != 0) {
        (**(code **)(*(int *)(iVar1 + 8) + 0x3b8))(iVar1,iVar2);
      }
    }
  }
  return;
}



/* 409d9d94 glGetActiveAttrib */

/* Boundary evidence: original MIPS .pdata 409d9d94..409d9e87. Semantic name remains unreviewed. */

void glGetActiveAttrib(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                      undefined4 param_5,undefined4 param_6,undefined4 param_7)

{
  int iVar1;
  int iVar2;
  
                    /* 0x29d94  72  glGetActiveAttrib */
  if (DAT_409dd38c != 0) {
    if (*(int *)(DAT_409dd38c + 8) == 0) {
      iVar1 = *(int *)(DAT_409dd38c + 0xc);
    }
    else {
      iVar1 = mali_sys_thread_key_get_data(4);
    }
    if (iVar1 != 0) {
      mali_sys_mutex_lock(*(undefined4 *)(*(int *)(iVar1 + 0x4e8) + 0x1c));
      iVar2 = (**(code **)(*(int *)(iVar1 + 8) + 0x2d8))
                        (*(undefined4 *)(*(int *)(iVar1 + 0x4e8) + 0x18),param_1,param_2,param_3,
                         param_4,param_5,param_6,param_7);
      mali_sys_mutex_unlock(*(undefined4 *)(*(int *)(iVar1 + 0x4e8) + 0x1c));
      if (iVar2 != 0) {
        (**(code **)(*(int *)(iVar1 + 8) + 0x3b8))(iVar1,iVar2);
      }
    }
  }
  return;
}



/* 409d9e88 glDetachShader */

/* Boundary evidence: original MIPS .pdata 409d9e88..409d9f4b. Semantic name remains unreviewed. */

void glDetachShader(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  
                    /* 0x29e88  53  glDetachShader */
  if (DAT_409dd38c != 0) {
    if (*(int *)(DAT_409dd38c + 8) == 0) {
      iVar1 = *(int *)(DAT_409dd38c + 0xc);
    }
    else {
      iVar1 = mali_sys_thread_key_get_data(4);
    }
    if (iVar1 != 0) {
      mali_sys_mutex_lock(*(undefined4 *)(*(int *)(iVar1 + 0x4e8) + 0x1c));
      iVar2 = (**(code **)(*(int *)(iVar1 + 8) + 0x2cc))
                        (*(undefined4 *)(*(int *)(iVar1 + 0x4e8) + 0x18),
                         *(int *)(iVar1 + 0x4d8) + 0xc,param_1,param_2);
      mali_sys_mutex_unlock(*(undefined4 *)(*(int *)(iVar1 + 0x4e8) + 0x1c));
      if (iVar2 != 0) {
        (**(code **)(*(int *)(iVar1 + 8) + 0x3b8))(iVar1,iVar2);
      }
    }
  }
  return;
}



/* 409d9f4c glDeleteShader */

/* Boundary evidence: original MIPS .pdata 409d9f4c..409d9ff7. Semantic name remains unreviewed. */

void glDeleteShader(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  
                    /* 0x29f4c  48  glDeleteShader */
  if (DAT_409dd38c != 0) {
    if (*(int *)(DAT_409dd38c + 8) == 0) {
      iVar1 = *(int *)(DAT_409dd38c + 0xc);
    }
    else {
      iVar1 = mali_sys_thread_key_get_data(4);
    }
    if (iVar1 != 0) {
      mali_sys_mutex_lock(*(undefined4 *)(*(int *)(iVar1 + 0x4e8) + 0x1c));
      iVar2 = (**(code **)(*(int *)(iVar1 + 8) + 0x2c8))
                        (*(undefined4 *)(*(int *)(iVar1 + 0x4e8) + 0x18),param_1);
      mali_sys_mutex_unlock(*(undefined4 *)(*(int *)(iVar1 + 0x4e8) + 0x1c));
      if (iVar2 != 0) {
        (**(code **)(*(int *)(iVar1 + 8) + 0x3b8))(iVar1,iVar2);
      }
    }
  }
  return;
}



/* 409d9ff8 glDeleteProgram */

/* Boundary evidence: original MIPS .pdata 409d9ff8..409da0a3. Semantic name remains unreviewed. */

void glDeleteProgram(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  
                    /* 0x29ff8  46  glDeleteProgram */
  if (DAT_409dd38c != 0) {
    if (*(int *)(DAT_409dd38c + 8) == 0) {
      iVar1 = *(int *)(DAT_409dd38c + 0xc);
    }
    else {
      iVar1 = mali_sys_thread_key_get_data(4);
    }
    if (iVar1 != 0) {
      mali_sys_mutex_lock(*(undefined4 *)(*(int *)(iVar1 + 0x4e8) + 0x1c));
      iVar2 = (**(code **)(*(int *)(iVar1 + 8) + 0x2c4))
                        (*(undefined4 *)(*(int *)(iVar1 + 0x4e8) + 0x18),param_1);
      mali_sys_mutex_unlock(*(undefined4 *)(*(int *)(iVar1 + 0x4e8) + 0x1c));
      if (iVar2 != 0) {
        (**(code **)(*(int *)(iVar1 + 8) + 0x3b8))(iVar1,iVar2);
      }
    }
  }
  return;
}



/* 409da0a4 glCreateShader */

/* Boundary evidence: original MIPS .pdata 409da0a4..409da173. Semantic name remains unreviewed. */

undefined4 glCreateShader(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  undefined4 local_18 [2];
  
                    /* 0x2a0a4  42  glCreateShader */
  local_18[0] = 0;
  if (DAT_409dd38c != 0) {
    if (*(int *)(DAT_409dd38c + 8) == 0) {
      iVar1 = *(int *)(DAT_409dd38c + 0xc);
    }
    else {
      iVar1 = mali_sys_thread_key_get_data(4);
    }
    if (iVar1 != 0) {
      mali_sys_mutex_lock(*(undefined4 *)(*(int *)(iVar1 + 0x4e8) + 0x1c));
      iVar2 = (**(code **)(*(int *)(iVar1 + 8) + 0x2c0))
                        (*(undefined4 *)(*(int *)(iVar1 + 0x4e8) + 0x18),param_1,local_18);
      mali_sys_mutex_unlock(*(undefined4 *)(*(int *)(iVar1 + 0x4e8) + 0x1c));
      if (iVar2 != 0) {
        (**(code **)(*(int *)(iVar1 + 8) + 0x3b8))(iVar1,iVar2);
      }
      return local_18[0];
    }
  }
  return 0;
}



/* 409da174 glCreateProgram */

/* Boundary evidence: original MIPS .pdata 409da174..409da23b. Semantic name remains unreviewed. */

undefined4 glCreateProgram(void)

{
  int iVar1;
  int iVar2;
  undefined4 local_18 [2];
  
                    /* 0x2a174  41  glCreateProgram */
  local_18[0] = 0;
  if (DAT_409dd38c != 0) {
    if (*(int *)(DAT_409dd38c + 8) == 0) {
      iVar1 = *(int *)(DAT_409dd38c + 0xc);
    }
    else {
      iVar1 = mali_sys_thread_key_get_data(4);
    }
    if (iVar1 != 0) {
      mali_sys_mutex_lock(*(undefined4 *)(*(int *)(iVar1 + 0x4e8) + 0x1c));
      iVar2 = (**(code **)(*(int *)(iVar1 + 8) + 700))
                        (*(undefined4 *)(*(int *)(iVar1 + 0x4e8) + 0x18),local_18);
      mali_sys_mutex_unlock(*(undefined4 *)(*(int *)(iVar1 + 0x4e8) + 0x1c));
      if (iVar2 != 0) {
        (**(code **)(*(int *)(iVar1 + 8) + 0x3b8))(iVar1,iVar2);
      }
      return local_18[0];
    }
  }
  return 0;
}



/* 409da23c glCompileShader */

/* Boundary evidence: original MIPS .pdata 409da23c..409da2e7. Semantic name remains unreviewed. */

void glCompileShader(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  
                    /* 0x2a23c  36  glCompileShader */
  if (DAT_409dd38c != 0) {
    if (*(int *)(DAT_409dd38c + 8) == 0) {
      iVar1 = *(int *)(DAT_409dd38c + 0xc);
    }
    else {
      iVar1 = mali_sys_thread_key_get_data(4);
    }
    if (iVar1 != 0) {
      mali_sys_mutex_lock(*(undefined4 *)(*(int *)(iVar1 + 0x4e8) + 0x1c));
      iVar2 = (**(code **)(*(int *)(iVar1 + 8) + 0x2b8))
                        (*(undefined4 *)(*(int *)(iVar1 + 0x4e8) + 0x18),param_1);
      mali_sys_mutex_unlock(*(undefined4 *)(*(int *)(iVar1 + 0x4e8) + 0x1c));
      if (iVar2 != 0) {
        (**(code **)(*(int *)(iVar1 + 8) + 0x3b8))(iVar1,iVar2);
      }
    }
  }
  return;
}



/* 409da2e8 glBindAttribLocation */

/* Boundary evidence: original MIPS .pdata 409da2e8..409da3b3. Semantic name remains unreviewed. */

void glBindAttribLocation(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  
                    /* 0x2a2e8  18  glBindAttribLocation */
  if (DAT_409dd38c != 0) {
    if (*(int *)(DAT_409dd38c + 8) == 0) {
      iVar1 = *(int *)(DAT_409dd38c + 0xc);
    }
    else {
      iVar1 = mali_sys_thread_key_get_data(4);
    }
    if (iVar1 != 0) {
      mali_sys_mutex_lock(*(undefined4 *)(*(int *)(iVar1 + 0x4e8) + 0x1c));
      iVar2 = (**(code **)(*(int *)(iVar1 + 8) + 0x2a4))
                        (*(undefined4 *)(*(int *)(iVar1 + 0x4e8) + 0x18),param_1,param_2,param_3);
      mali_sys_mutex_unlock(*(undefined4 *)(*(int *)(iVar1 + 0x4e8) + 0x1c));
      if (iVar2 != 0) {
        (**(code **)(*(int *)(iVar1 + 8) + 0x3b8))(iVar1,iVar2);
      }
    }
  }
  return;
}



/* 409da3b4 glAttachShader */

/* Boundary evidence: original MIPS .pdata 409da3b4..409da46f. Semantic name remains unreviewed. */

void glAttachShader(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  
                    /* 0x2a3b4  17  glAttachShader */
  if (DAT_409dd38c != 0) {
    if (*(int *)(DAT_409dd38c + 8) == 0) {
      iVar1 = *(int *)(DAT_409dd38c + 0xc);
    }
    else {
      iVar1 = mali_sys_thread_key_get_data(4);
    }
    if (iVar1 != 0) {
      mali_sys_mutex_lock(*(undefined4 *)(*(int *)(iVar1 + 0x4e8) + 0x1c));
      iVar2 = (**(code **)(*(int *)(iVar1 + 8) + 0x2a0))
                        (*(undefined4 *)(*(int *)(iVar1 + 0x4e8) + 0x18),param_1,param_2);
      mali_sys_mutex_unlock(*(undefined4 *)(*(int *)(iVar1 + 0x4e8) + 0x1c));
      if (iVar2 != 0) {
        (**(code **)(*(int *)(iVar1 + 8) + 0x3b8))(iVar1,iVar2);
      }
    }
  }
  return;
}



/* 409da470 FUN_409da470 */

/* Boundary evidence: original MIPS .pdata 409da470..409da507. Semantic name remains unreviewed. */

undefined4 FUN_409da470(int param_1,int param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int *piVar4;
  
  piVar4 = *(int **)(param_1 + 0x500);
  iVar1 = FUN_409c1540(*(undefined4 **)(param_1 + 0x510),param_2 << 4,piVar4);
  if ((iVar1 == 0) ||
     (iVar1 = FUN_409c1540(*(undefined4 **)(param_1 + 0x510),param_2 * param_3,piVar4 + 1),
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



/* 409da508 FUN_409da508 */

/* Boundary evidence: original MIPS .pdata 409da508..409da583. Semantic name remains unreviewed. */

void FUN_409da508(undefined4 *param_1,undefined4 param_2)

{
  int iVar1;
  uint uVar2;
  
  FUN_409da7c8();
  uVar2 = 7;
  if (1 < (int)param_1[299]) {
    uVar2 = 0xf;
  }
  iVar1 = mali_frame_builder_get_supersample_factor(param_2);
  if (iVar1 != 0) {
    uVar2 = uVar2 | 0x10;
  }
  mali_incremental_render(param_2,uVar2);
  iVar1 = FUN_409c508c(param_1);
  if (iVar1 == 0) {
    FUN_409c1638((undefined4 *)param_1[0x144]);
  }
                    /* WARNING: Subroutine does not return */
  FUN_409da7e8(0x10);
}



/* 409da584 FUN_409da584 */

/* Boundary evidence: original MIPS .pdata 409da584..409da687. Semantic name remains unreviewed. */

void FUN_409da584(undefined4 *param_1,int *param_2,undefined4 param_3,int param_4,int param_5,
                 undefined4 param_6,int param_7,undefined4 param_8,undefined4 param_9,
                 undefined4 param_10,undefined4 param_11,undefined4 param_12)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  
  FUN_409da688();
  param_5 = 0;
  if ((param_4 == 0xde1) || (param_4 == 0x8513)) {
    FUN_409cc82c(param_2,param_4,(int *)0x0,&param_5);
    iVar1 = param_5;
    if (param_4 == 0xde1) {
      FUN_409b6de8(param_1,param_5,0xde1);
    }
    else if (param_4 == 0x8513) {
      param_7 = 0x8515;
      param_8 = 0x8516;
      param_9 = 0x8517;
      param_10 = 0x8518;
      param_11 = 0x8519;
      param_12 = 0x851a;
      iVar2 = FUN_409c64fc(param_5);
      if (iVar2 != 0) {
        iVar2 = 0;
        piVar4 = &param_7;
        do {
          iVar3 = FUN_409b6de8(param_1,iVar1,*piVar4);
          if (iVar3 != 0) break;
          iVar2 = iVar2 + 1;
          piVar4 = piVar4 + 1;
        } while (iVar2 < 6);
      }
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_409da6b0(0x30);
}



/* 409da688 FUN_409da688 */

/* Boundary evidence: original MIPS .pdata 409da688..409da6af. Semantic name remains unreviewed. */

void FUN_409da688(void)

{
  return;
}



/* 409da6b0 FUN_409da6b0 */

/* Boundary evidence: original MIPS .pdata 409da6b0..409da6d7. Semantic name remains unreviewed. */

void FUN_409da6b0(int param_1)

{
                    /* WARNING: Could not recover jumptable at 0x409da6d0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(&stack0x00000014 + param_1))();
  return;
}



/* 409da6d8 FUN_409da6d8 */

/* Boundary evidence: original MIPS .pdata 409da6d8..409da72b. Semantic name remains unreviewed. */

void FUN_409da6d8(int param_1,undefined4 param_2,uint *param_3)

{
  if ((*param_3 & 1) != 0) {
    param_1 = ((-param_3[2] & param_3[1] + param_1) - (param_3[1] + param_1)) + param_1;
  }
  FUN_409b290c(*(uint *)(param_1 + (*param_3 & 0xfffffffc)));
  return;
}



/* 409da72c FUN_409da72c */

/* Boundary evidence: original MIPS .pdata 409da72c..409da757. Semantic name remains unreviewed. */

undefined4 FUN_409da72c(undefined4 param_1,int param_2,undefined4 param_3,int param_4)

{
  FUN_409da6d8(param_2,param_4,*(uint **)(*(int *)(param_4 + 4) + 0xc));
  return 1;
}



/* 409da758 FUN_409da758 */

/* Boundary evidence: original MIPS .pdata 409da758..409da78f. Semantic name remains unreviewed. */

void FUN_409da758(void)

{
  return;
}



/* 409da790 FUN_409da790 */

/* Boundary evidence: original MIPS .pdata 409da790..409da7c7. Semantic name remains unreviewed. */

void FUN_409da790(int param_1)

{
                    /* WARNING: Could not recover jumptable at 0x409da7c0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(&stack0x00000024 + param_1))();
  return;
}



/* 409da7c8 FUN_409da7c8 */

/* Boundary evidence: original MIPS .pdata 409da7c8..409da7e7. Semantic name remains unreviewed. */

void FUN_409da7c8(void)

{
  return;
}



/* 409da7e8 FUN_409da7e8 */

/* Boundary evidence: original MIPS .pdata 409da7e8..409da807. Semantic name remains unreviewed. */

void FUN_409da7e8(int param_1)

{
  undefined4 uStackX_c;
  
                    /* WARNING: Could not recover jumptable at 0x409da800. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)((int)&uStackX_c + param_1))();
  return;
}



/* 409da808 FUN_409da808 */

/* Boundary evidence: original MIPS .pdata 409da808..409da837. Semantic name remains unreviewed. */

void FUN_409da808(void)

{
  return;
}



/* 409da838 FUN_409da838 */

/* Boundary evidence: original MIPS .pdata 409da838..409da867. Semantic name remains unreviewed. */

void FUN_409da838(int param_1)

{
                    /* WARNING: Could not recover jumptable at 0x409da860. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(&stack0x0000001c + param_1))();
  return;
}


