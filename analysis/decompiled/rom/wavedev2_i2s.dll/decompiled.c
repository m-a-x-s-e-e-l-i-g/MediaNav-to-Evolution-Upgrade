/* Automatic Ghidra pseudocode. Not original source; not runtime-verified. */

/* c0942078 FUN_c0942078 */

/* Boundary evidence: original MIPS .pdata c0942078..c09420ab. Semantic name remains unreviewed. */

undefined4 FUN_c0942078(HMODULE param_1,int param_2)

{
  if (param_2 == 1) {
    DisableThreadLibraryCalls(param_1);
  }
  return 1;
}



/* c09420ac WAV_Init */

/* Boundary evidence: original MIPS .pdata c09420ac..c09420c7. Semantic name remains unreviewed. */

void WAV_Init(undefined4 param_1)

{
                    /* 0x20ac  4  WAV_Init */
  FUN_c0948128(param_1);
  return;
}



/* c09420c8 WAV_Deinit */

/* Boundary evidence: original MIPS .pdata c09420c8..c09420e7. Semantic name remains unreviewed. */

void WAV_Deinit(void)

{
                    /* 0x20c8  2  WAV_Deinit */
  FUN_c0947630(DAT_c094a140);
  return;
}



/* c09420e8 WAV_Open */

/* Boundary evidence: original MIPS .pdata c09420e8..c0942117. Semantic name remains unreviewed. */

undefined4 * WAV_Open(void)

{
  undefined4 *puVar1;
  
                    /* 0x20e8  5  WAV_Open */
  puVar1 = operator_new(4);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    *puVar1 = 0;
  }
  return puVar1;
}



/* c0942118 WAV_Close */

/* Boundary evidence: original MIPS .pdata c0942118..c0942137. Semantic name remains unreviewed. */

undefined4 WAV_Close(void *param_1)

{
                    /* 0x2118  1  WAV_Close */
  operator_delete(param_1);
  return 1;
}



/* c0942138 FUN_c0942138 */

/* Boundary evidence: original MIPS .pdata c0942138..c0942707. Semantic name remains unreviewed. */

undefined4 FUN_c0942138(int param_1,int *param_2)

{
  bool bVar1;
  undefined4 uVar2;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  int *piVar3;
  code *pcVar4;
  int iVar5;
  int *piVar6;
  undefined4 *puVar7;
  uint uVar8;
  uint uVar9;
  
  SetLastError(0);
  uVar8 = *(uint *)(param_1 + 4);
  puVar7 = *(undefined4 **)(param_1 + 0xc);
  uVar9 = *(uint *)(param_1 + 0x10);
  piVar6 = *(int **)(param_1 + 8);
  EnterCriticalSection((LPCRITICAL_SECTION)(DAT_c094a140 + 4));
  if (0x400 < uVar8) {
    if (uVar8 == 0x401) {
      if (piVar6 == (int *)0x0) {
        iVar5 = DAT_c094a140 + 0x50;
      }
      else {
        iVar5 = FUN_c09435f4((int)piVar6);
      }
      bVar1 = FUN_c0943080(iVar5,(uint)puVar7,uVar9);
      iVar5 = CONCAT31(extraout_var_00,bVar1);
      goto LAB_c0942688;
    }
    if (uVar8 == 0x402) {
      if (piVar6 == (int *)0x0) {
        iVar5 = FUN_c0947b1c(DAT_c094a140,(int)puVar7);
      }
      else {
        iVar5 = FUN_c0943f40((int)piVar6,(int)puVar7);
      }
      goto LAB_c0942688;
    }
switchD_c09421ec_caseD_7:
    iVar5 = 8;
    goto LAB_c0942688;
  }
  if (uVar8 == 0x400) {
    if (piVar6 == (int *)0x0) {
      iVar5 = 0xb;
    }
    else {
      bVar1 = FUN_c09436fc(piVar6,(uint)puVar7);
      iVar5 = CONCAT31(extraout_var,bVar1);
    }
    goto LAB_c0942688;
  }
  switch(uVar8) {
  case 3:
  case 0x32:
    iVar5 = 1;
    break;
  case 4:
    if (piVar6 == (int *)0x0) {
      piVar6 = (int *)(DAT_c094a140 + 0x50);
    }
    else {
LAB_c0942284:
      piVar6 = (int *)FUN_c09435f4((int)piVar6);
    }
    goto LAB_c09422a0;
  case 5:
    piVar3 = (int *)(DAT_c094a140 + 0x50);
    goto LAB_c0942318;
  case 6:
  case 0x35:
    NKDbgPrintfW(L"WIDM_CLOSE/WODM_CLOSE\r\n");
    iVar5 = (**(code **)(*piVar6 + 8))(piVar6);
    if (iVar5 == 0) {
      FUN_c0943888(piVar6);
    }
    if (*(int **)(DAT_c094a140 + 0x54) == (int *)(DAT_c094a140 + 0x54)) {
      FUN_c094776c(DAT_c094a140);
      NKDbgPrintfW(L"Stop Output DMA\r\n");
    }
    if (*(int **)(DAT_c094a140 + 0x24) == (int *)(DAT_c094a140 + 0x24)) {
      FUN_c09477dc(DAT_c094a140);
      NKDbgPrintfW(L"Stop Input DMA\r\n");
    }
    break;
  default:
    goto switchD_c09421ec_caseD_7;
  case 9:
  case 0x38:
    pcVar4 = *(code **)(*piVar6 + 0x30);
    goto LAB_c0942438;
  case 10:
  case 0x3a:
    pcVar4 = *(code **)(*piVar6 + 0x14);
    goto LAB_c094240c;
  case 0xb:
  case 0x39:
    pcVar4 = *(code **)(*piVar6 + 0x10);
    goto LAB_c094240c;
  case 0xc:
  case 0x3b:
    pcVar4 = *(code **)(*piVar6 + 0x18);
LAB_c094240c:
    iVar5 = (*pcVar4)(piVar6);
    break;
  case 0xd:
  case 0x3c:
    pcVar4 = *(code **)(*piVar6 + 0xc);
    goto LAB_c0942438;
  case 0x10:
    if (piVar6 == (int *)0x0) {
      uVar2 = FUN_c09473e0();
    }
    else {
      uVar2 = FUN_c09436cc((int)piVar6);
    }
    *puVar7 = uVar2;
    iVar5 = 0;
    break;
  case 0x11:
    if (piVar6 == (int *)0x0) {
      iVar5 = FUN_c0947390(puVar7);
    }
    else {
      iVar5 = FUN_c09436d4(piVar6,(int)puVar7);
    }
    break;
  case 0x12:
    iVar5 = FUN_c0943e34((int)piVar6,puVar7);
    break;
  case 0x13:
    pcVar4 = *(code **)(*piVar6 + 0x3c);
LAB_c0942438:
    iVar5 = (*pcVar4)(piVar6,puVar7);
    break;
  case 0x14:
    iVar5 = FUN_c0943ab8(piVar6);
    break;
  case 0x16:
    if (piVar6 == (int *)0x0) {
      piVar6 = (int *)(DAT_c094a140 + 0x50);
    }
    else {
      piVar6 = (int *)FUN_c09435f4((int)piVar6);
    }
    pcVar4 = *(code **)(*piVar6 + 8);
    goto LAB_c09422a8;
  case 0x17:
    if (piVar6 != (int *)0x0) {
LAB_c0942520:
      iVar5 = FUN_c094415c((int)piVar6,puVar7);
      break;
    }
    piVar6 = (int *)(DAT_c094a140 + 0x50);
    goto LAB_c094253c;
  case 0x18:
    goto joined_r0xc09425a4;
  case 0x33:
    if (piVar6 != (int *)0x0) goto LAB_c0942284;
    piVar6 = (int *)(DAT_c094a140 + 0x20);
LAB_c09422a0:
    pcVar4 = *(code **)(*piVar6 + 0xc);
LAB_c09422a8:
    iVar5 = (*pcVar4)(piVar6,puVar7,uVar9);
    break;
  case 0x34:
    piVar3 = (int *)(DAT_c094a140 + 0x20);
LAB_c0942318:
    iVar5 = FUN_c0942d00(piVar3,(int)puVar7,uVar9,piVar6);
    break;
  case 0x3d:
    if (piVar6 != (int *)0x0) goto LAB_c0942520;
    piVar6 = (int *)(DAT_c094a140 + 0x20);
LAB_c094253c:
    iVar5 = FUN_c0942fc4(piVar6,puVar7);
    break;
  case 0x3e:
joined_r0xc09425a4:
    if (piVar6 == (int *)0x0) {
      iVar5 = FUN_c0945ccc();
    }
    else {
      iVar5 = FUN_c0944178();
    }
  }
LAB_c0942688:
  LeaveCriticalSection((LPCRITICAL_SECTION)(DAT_c094a140 + 4));
  if (param_2 != (int *)0x0) {
    *param_2 = iVar5;
  }
  return 1;
}



/* c0942708 FUN_c0942708 */

/* Boundary evidence: original MIPS .pdata c0942708..c0942713. Semantic name remains unreviewed. */

undefined4 FUN_c0942708(void)

{
  return 1;
}



/* c0942714 WAV_IOControl */

/* Boundary evidence: original MIPS .pdata c0942714..c094284b. Semantic name remains unreviewed. */

undefined4
WAV_IOControl(int *param_1,int param_2,int param_3,undefined4 param_4,int *param_5,uint param_6,
             undefined4 *param_7)

{
  int iVar1;
  undefined4 uVar2;
  
                    /* 0x2714  3  WAV_IOControl */
  if (*param_1 != 2) {
    iVar1 = CeGetCallerTrust();
    *param_1 = iVar1;
    if (iVar1 != 2) {
      SetLastError(5);
      return 0;
    }
  }
  if (param_2 != 0x1d000c) {
    if ((((param_2 != 0x321000) && (param_2 != 0x321004)) && (param_2 != 0x321008)) &&
       (param_2 != 0x32100c)) {
      if (param_2 != -0x7fffff00) {
        return 0;
      }
      uVar2 = FUN_c0947208(param_3,param_5);
      return uVar2;
    }
    uVar2 = FUN_c0947b48(DAT_c094a140,param_2,param_3,param_4,param_5,param_6,param_7);
    return uVar2;
  }
  uVar2 = FUN_c0942138(param_3,param_5);
  return uVar2;
}



/* c094284c FUN_c094284c */

undefined4 * FUN_c094284c(undefined4 *param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  puVar2 = param_1 + 1;
  *param_1 = &PTR_FUN_c09410b4;
  puVar1 = param_1 + 5;
  param_1[2] = puVar2;
  *puVar2 = puVar2;
  param_1[3] = 0xffffffff;
  param_1[4] = 0xffffffff;
  param_1[9] = 0;
  do {
    *puVar1 = 0xffffffff;
    puVar1 = puVar1 + 1;
  } while (puVar1 != param_1 + 9);
  return param_1;
}



/* c0942898 FUN_c0942898 */

undefined4 FUN_c0942898(int param_1)

{
  return *(undefined4 *)(param_1 + 0x10);
}



/* c09428a0 FUN_c09428a0 */

undefined4 FUN_c09428a0(int param_1,int param_2)

{
  return *(undefined4 *)((param_2 + 5) * 4 + param_1);
}



/* c09428b4 FUN_c09428b4 */

undefined4 FUN_c09428b4(undefined4 param_1,short *param_2)

{
  undefined4 uVar1;
  
  uVar1 = 1;
  if ((((*param_2 != 1) || (param_2[1] == 0)) || (2 < (ushort)param_2[1])) ||
     (((param_2[7] != 8 && (param_2[7] != 0x10)) ||
      ((*(uint *)(param_2 + 2) < 100 || (0x2ee00 < *(uint *)(param_2 + 2))))))) {
    uVar1 = 0;
  }
  return uVar1;
}



/* c094296c FUN_c094296c */

/* Boundary evidence: original MIPS .pdata c094296c..c09429df. Semantic name remains unreviewed. */

undefined4 FUN_c094296c(undefined4 param_1,short *param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  if ((*param_2 != 0x3000) && (iVar1 = FUN_c0943738(), iVar1 == 0)) {
    uVar2 = FUN_c09428b4(param_1,param_2);
    return uVar2;
  }
  return 1;
}



/* c09429e0 FUN_c09429e0 */

/* Boundary evidence: original MIPS .pdata c09429e0..c0942a7f. Semantic name remains unreviewed. */

undefined4 FUN_c09429e0(int param_1,int *param_2)

{
  int iVar1;
  int *piVar2;
  undefined4 *puVar3;
  int *piVar4;
  
  iVar1 = (**(code **)(*param_2 + 0x38))(param_2);
  if (iVar1 == 0) {
    puVar3 = *(undefined4 **)(param_1 + 8);
    piVar2 = param_2 + 1;
    *piVar2 = param_1 + 4;
    param_2[2] = (int)puVar3;
    *puVar3 = piVar2;
    *(int **)(param_1 + 8) = piVar2;
  }
  else {
    if (*(int *)(param_1 + 0x24) != 0) {
      return 4;
    }
    piVar4 = (int *)(param_1 + 4);
    *(undefined4 *)(param_1 + 0x24) = 1;
    iVar1 = *piVar4;
    piVar2 = param_2 + 1;
    *piVar2 = iVar1;
    param_2[2] = (int)piVar4;
    *(int **)(iVar1 + 4) = piVar2;
    *piVar4 = (int)piVar2;
  }
  return 0;
}



/* c0942a80 FUN_c0942a80 */

/* Boundary evidence: original MIPS .pdata c0942a80..c0942adf. Semantic name remains unreviewed. */

void FUN_c0942a80(int param_1,int *param_2)

{
  int iVar1;
  
  iVar1 = (**(code **)(*param_2 + 0x38))(param_2);
  if (iVar1 != 0) {
    *(undefined4 *)(param_1 + 0x24) = 0;
  }
  *(int *)param_2[2] = param_2[1];
  *(int *)(param_2[1] + 4) = param_2[2];
  return;
}



/* c0942ae0 FUN_c0942ae0 */

/* Boundary evidence: original MIPS .pdata c0942ae0..c0942bcf. Semantic name remains unreviewed. */

uint FUN_c0942ae0(int param_1,uint param_2,undefined4 param_3,int *param_4)

{
  uint uVar1;
  uint uVar2;
  int *piVar3;
  int iVar4;
  int *piVar5;
  
  piVar5 = *(int **)(param_1 + 4);
  iVar4 = 0;
  uVar1 = param_2;
  while (piVar5 != (int *)(param_1 + 4)) {
    piVar3 = piVar5 + -1;
    piVar5 = (int *)*piVar5;
    FUN_c0943878((int)piVar3);
    uVar2 = (**(code **)(*piVar3 + 0x1c))(piVar3,param_2,param_3,uVar1,param_4);
    FUN_c0943888(piVar3);
    if (param_2 < uVar2) {
      iVar4 = iVar4 + 1;
    }
    if (uVar1 < uVar2) {
      uVar1 = uVar2;
    }
  }
  if (param_4 != (int *)0x0) {
    *param_4 = iVar4;
  }
  return uVar1;
}



/* c0942bd0 FUN_c0942bd0 */

/* Boundary evidence: original MIPS .pdata c0942bd0..c0942c23. Semantic name remains unreviewed. */

void FUN_c0942bd0(int param_1)

{
  int *piVar1;
  
  for (piVar1 = *(int **)(param_1 + 4); piVar1 != (int *)(param_1 + 4); piVar1 = (int *)*piVar1) {
    (**(code **)(piVar1[-1] + 0x34))();
  }
  return;
}



/* c0942c24 FUN_c0942c24 */

/* Boundary evidence: original MIPS .pdata c0942c24..c0942c43. Semantic name remains unreviewed. */

void FUN_c0942c24(void)

{
  FUN_c0947e50(DAT_c094a140);
  return;
}



/* c0942c44 FUN_c0942c44 */

/* Boundary evidence: original MIPS .pdata c0942c44..c0942c63. Semantic name remains unreviewed. */

void FUN_c0942c44(void)

{
  FUN_c09477a8(DAT_c094a140);
  return;
}



/* c0942c64 FUN_c0942c64 */

/* Boundary evidence: original MIPS .pdata c0942c64..c0942c97. Semantic name remains unreviewed. */

undefined4 FUN_c0942c64(undefined4 param_1,void *param_2,size_t param_3)

{
  if (0x54 < param_3) {
    param_3 = 0x54;
  }
  memcpy(param_2,&DAT_c09410d4,param_3);
  return 0;
}



/* c0942c98 FUN_c0942c98 */

/* Boundary evidence: original MIPS .pdata c0942c98..c0942ccb. Semantic name remains unreviewed. */

undefined4 FUN_c0942c98(undefined4 param_1,void *param_2,size_t param_3)

{
  if (0x50 < param_3) {
    param_3 = 0x50;
  }
  memcpy(param_2,&DAT_c0941128,param_3);
  return 0;
}



/* c0942ccc FUN_c0942ccc */

/* Boundary evidence: original MIPS .pdata c0942ccc..c0942cff. Semantic name remains unreviewed. */

undefined4 FUN_c0942ccc(undefined4 param_1,void *param_2,size_t param_3)

{
  if (0x1c < param_3) {
    param_3 = 0x1c;
  }
  memcpy(param_2,&DAT_c0941178,param_3);
  return 0;
}



/* c0942d00 FUN_c0942d00 */

/* Boundary evidence: original MIPS .pdata c0942d00..c0942e27. Semantic name remains unreviewed. */

int FUN_c0942d00(int *param_1,int param_2,uint param_3,int *param_4)

{
  int iVar1;
  int *piVar2;
  
  if ((*(int *)(param_2 + 4) == 0) || (iVar1 = (**(code **)*param_1)(param_1), iVar1 == 0)) {
    iVar1 = 0x20;
  }
  else if ((param_3 & 1) == 0) {
    (**(code **)(*param_1 + 0x18))(param_1,*(undefined4 *)(*(int *)(param_2 + 4) + 4));
    piVar2 = (int *)(**(code **)(*param_1 + 0x14))(param_1,param_2);
    if (piVar2 == (int *)0x0) {
      iVar1 = 7;
    }
    else {
      iVar1 = (**(code **)(*piVar2 + 4))(piVar2,param_1,param_2,param_3);
      if (iVar1 == 0) {
        *param_4 = (int)piVar2;
      }
      else {
        (**(code **)*piVar2)(piVar2,1);
      }
    }
  }
  else {
    iVar1 = 0;
  }
  return iVar1;
}



/* c0942e28 FUN_c0942e28 */

/* Boundary evidence: original MIPS .pdata c0942e28..c0942e7b. Semantic name remains unreviewed. */

void FUN_c0942e28(int param_1)

{
  int *piVar1;
  
  for (piVar1 = *(int **)(param_1 + 4); piVar1 != (int *)(param_1 + 4); piVar1 = (int *)*piVar1) {
    (**(code **)(piVar1[-1] + 0x20))();
  }
  return;
}



/* c0942e7c FUN_c0942e7c */

undefined4 FUN_c0942e7c(int param_1)

{
  return *(undefined4 *)(param_1 + 0x28);
}



/* c0942e84 FUN_c0942e84 */

undefined4 FUN_c0942e84(int param_1)

{
  return *(undefined4 *)(param_1 + 0x2c);
}



/* c0942e94 FUN_c0942e94 */

/* Boundary evidence: original MIPS .pdata c0942e94..c0942fc3. Semantic name remains unreviewed. */

undefined4 FUN_c0942e94(int *param_1,int param_2,undefined4 param_3,uint param_4,uint *param_5)

{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  undefined1 local_28;
  undefined1 local_27;
  undefined1 local_26;
  undefined1 local_25;
  int local_24;
  int local_20;
  undefined1 local_1c;
  undefined1 local_1b;
  undefined1 local_1a;
  undefined1 local_19;
  undefined1 local_18;
  undefined1 local_17;
  
  if (param_2 == 0) {
    local_28 = 1;
    local_1a = 0x10;
    local_27 = 0;
    local_19 = 0;
    uVar2 = (**(code **)(*param_1 + 0x1c))(param_1);
    local_24 = param_1[10];
    uVar2 = uVar2 & 0xffff;
    local_26 = (undefined1)uVar2;
    local_20 = uVar2 * local_24;
    local_25 = (undefined1)(uVar2 >> 8);
    iVar3 = uVar2 * CONCAT11(local_19,local_1a);
    if (iVar3 < 0) {
      iVar3 = iVar3 + 7;
    }
    uVar2 = iVar3 >> 3 & 0xffff;
    local_1c = (undefined1)uVar2;
    local_18 = 0;
    local_1b = (undefined1)(uVar2 >> 8);
    local_17 = 0;
    if (0x12 < param_4) {
      param_4 = 0x12;
    }
    iVar3 = CeSafeCopyMemory(param_3,&local_28,param_4);
    if (iVar3 == 0) {
      uVar1 = 0xb;
    }
    else {
      uVar1 = 0;
      *param_5 = param_4;
    }
  }
  else {
    uVar1 = 1;
  }
  return uVar1;
}



/* c0942fc4 FUN_c0942fc4 */

/* Boundary evidence: original MIPS .pdata c0942fc4..c094305f. Semantic name remains unreviewed. */

undefined4 FUN_c0942fc4(int *param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = 8;
  iVar1 = memcmp((void *)*param_2,&DAT_c09411d0,0x10);
  if (iVar1 == 0) {
    uVar2 = FUN_c0942e94(param_1,param_2[1],param_2[4],param_2[5],(uint *)param_2[6]);
  }
  return uVar2;
}



/* c0943060 FUN_c0943060 */

/* Boundary evidence: original MIPS .pdata c0943060..c094307f. Semantic name remains unreviewed. */

undefined4 FUN_c0943060(int param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 0xc) = param_2;
  FUN_c0942bd0(param_1);
  return 0;
}



/* c0943080 FUN_c0943080 */

/* Boundary evidence: original MIPS .pdata c0943080..c09430bf. Semantic name remains unreviewed. */

bool FUN_c0943080(int param_1,uint param_2,undefined4 param_3)

{
  if (param_2 < 4) {
    *(undefined4 *)((param_2 + 5) * 4 + param_1) = param_3;
    FUN_c0942bd0(param_1);
  }
  return param_2 >= 4;
}



/* c09430c0 FUN_c09430c0 */

/* Boundary evidence: original MIPS .pdata c09430c0..c094310b. Semantic name remains unreviewed. */

undefined4 * FUN_c09430c0(undefined4 *param_1,uint param_2)

{
  FUN_c09435cc(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}



/* c094310c FUN_c094310c */

/* Boundary evidence: original MIPS .pdata c094310c..c0943157. Semantic name remains unreviewed. */

undefined4 * FUN_c094310c(undefined4 *param_1,uint param_2)

{
  FUN_c09435cc(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}



/* c0943158 FUN_c0943158 */

/* Boundary evidence: original MIPS .pdata c0943158..c09431a3. Semantic name remains unreviewed. */

undefined4 * FUN_c0943158(undefined4 *param_1,uint param_2)

{
  FUN_c09435cc(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}



/* c09431a4 FUN_c09431a4 */

/* Boundary evidence: original MIPS .pdata c09431a4..c09431ef. Semantic name remains unreviewed. */

undefined4 * FUN_c09431a4(undefined4 *param_1,uint param_2)

{
  FUN_c09435cc(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}



/* c09431f0 FUN_c09431f0 */

/* Boundary evidence: original MIPS .pdata c09431f0..c094323b. Semantic name remains unreviewed. */

undefined4 * FUN_c09431f0(undefined4 *param_1,uint param_2)

{
  FUN_c09435cc(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}



/* c094323c FUN_c094323c */

/* Boundary evidence: original MIPS .pdata c094323c..c0943287. Semantic name remains unreviewed. */

undefined4 * FUN_c094323c(undefined4 *param_1,uint param_2)

{
  FUN_c09435cc(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}



/* c0943288 FUN_c0943288 */

/* Boundary evidence: original MIPS .pdata c0943288..c09432d3. Semantic name remains unreviewed. */

undefined4 * FUN_c0943288(undefined4 *param_1,uint param_2)

{
  FUN_c09435cc(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}



/* c09432d4 FUN_c09432d4 */

/* Boundary evidence: original MIPS .pdata c09432d4..c094332b. Semantic name remains unreviewed. */

void FUN_c09432d4(int param_1,uint param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_c0947cdc(DAT_c094a140,param_2);
  if (iVar1 != 0) {
    *(int *)(param_1 + 0x28) = iVar1;
    uVar2 = __ll_div(0,1,iVar1,0);
    *(undefined4 *)(param_1 + 0x2c) = uVar2;
    FUN_c0942e28(param_1);
  }
  return;
}



/* c094332c FUN_c094332c */

/* Boundary evidence: original MIPS .pdata c094332c..c0943383. Semantic name remains unreviewed. */

void FUN_c094332c(int param_1,uint param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_c0947cf8(DAT_c094a140,param_2);
  if (iVar1 != 0) {
    *(int *)(param_1 + 0x28) = iVar1;
    uVar2 = __ll_div(0,1,iVar1,0);
    *(undefined4 *)(param_1 + 0x2c) = uVar2;
    FUN_c0942e28(param_1);
  }
  return;
}



/* c0943384 FUN_c0943384 */

/* Boundary evidence: original MIPS .pdata c0943384..c09433d3. Semantic name remains unreviewed. */

undefined4 * FUN_c0943384(void)

{
  undefined4 *puVar1;
  
  puVar1 = operator_new(0x94);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    FUN_c09435b8(puVar1);
    *puVar1 = &PTR_FUN_c09411e0;
  }
  return puVar1;
}



/* c09433d4 FUN_c09433d4 */

/* Boundary evidence: original MIPS .pdata c09433d4..c09435b7. Semantic name remains unreviewed. */

undefined4 * FUN_c09433d4(undefined4 param_1,int param_2)

{
  undefined4 *puVar1;
  undefined **ppuVar2;
  short *psVar3;
  
  psVar3 = *(short **)(param_2 + 4);
  if (*psVar3 == 0x3000) {
    puVar1 = operator_new(0x694);
    if (puVar1 == (undefined4 *)0x0) {
      return (undefined4 *)0x0;
    }
    FUN_c09435b8(puVar1);
    ppuVar2 = &PTR_FUN_c0941194;
  }
  else if (*psVar3 == 0x164) {
    puVar1 = operator_new(0x94);
    if (puVar1 == (undefined4 *)0x0) {
      return (undefined4 *)0x0;
    }
    FUN_c09435b8(puVar1);
    ppuVar2 = &PTR_FUN_c0941224;
  }
  else if (psVar3[7] == 8) {
    if (psVar3[1] == 1) {
      puVar1 = operator_new(0x94);
      if (puVar1 == (undefined4 *)0x0) {
        return (undefined4 *)0x0;
      }
      FUN_c09435b8(puVar1);
      ppuVar2 = &PTR_FUN_c0941268;
    }
    else {
      if (psVar3[1] != 2) {
        return (undefined4 *)0x0;
      }
      puVar1 = operator_new(0x94);
      if (puVar1 == (undefined4 *)0x0) {
        return (undefined4 *)0x0;
      }
      FUN_c09435b8(puVar1);
      ppuVar2 = &PTR_FUN_c09412ac;
    }
  }
  else {
    if (psVar3[7] != 0x10) {
      return (undefined4 *)0x0;
    }
    if (psVar3[1] == 1) {
      puVar1 = operator_new(0x94);
      if (puVar1 == (undefined4 *)0x0) {
        return (undefined4 *)0x0;
      }
      FUN_c09435b8(puVar1);
      ppuVar2 = &PTR_FUN_c09412f0;
    }
    else {
      if (psVar3[1] != 2) {
        return (undefined4 *)0x0;
      }
      puVar1 = operator_new(0x94);
      if (puVar1 == (undefined4 *)0x0) {
        return (undefined4 *)0x0;
      }
      FUN_c09435b8(puVar1);
      ppuVar2 = &PTR_FUN_c0941334;
    }
  }
  *puVar1 = ppuVar2;
  return puVar1;
}



/* c09435b8 FUN_c09435b8 */

undefined4 * FUN_c09435b8(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_c0941508;
  return param_1;
}



/* c09435cc FUN_c09435cc */

void FUN_c09435cc(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_c0941508;
  return;
}



/* c09435dc FUN_c09435dc */

bool FUN_c09435dc(int param_1)

{
  return *(int *)(param_1 + 0x38) != 0;
}



/* c09435f4 FUN_c09435f4 */

undefined4 FUN_c09435f4(int param_1)

{
  return *(undefined4 *)(param_1 + 0x50);
}



/* c09435fc FUN_c09435fc */

/* Boundary evidence: original MIPS .pdata c09435fc..c094362f. Semantic name remains unreviewed. */

void FUN_c09435fc(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  (**(code **)(param_1 + 0x1c))
            (*(undefined4 *)(param_1 + 0x18),param_2,*(undefined4 *)(param_1 + 0x20),param_3,param_4
            );
  return;
}



/* c0943630 FUN_c0943630 */

/* Boundary evidence: original MIPS .pdata c0943630..c0943663. Semantic name remains unreviewed. */

void FUN_c0943630(int param_1,undefined4 param_2)

{
  (**(code **)(param_1 + 0x1c))
            (*(undefined4 *)(param_1 + 0x18),0x3bd,*(undefined4 *)(param_1 + 0x20),param_2,0);
  return;
}



/* c0943664 FUN_c0943664 */

/* Boundary evidence: original MIPS .pdata c0943664..c0943697. Semantic name remains unreviewed. */

void FUN_c0943664(int param_1)

{
  (**(code **)(param_1 + 0x1c))
            (*(undefined4 *)(param_1 + 0x18),0x3bb,*(undefined4 *)(param_1 + 0x20),0,0);
  return;
}



/* c0943698 FUN_c0943698 */

/* Boundary evidence: original MIPS .pdata c0943698..c09436cb. Semantic name remains unreviewed. */

void FUN_c0943698(int param_1)

{
  (**(code **)(param_1 + 0x1c))
            (*(undefined4 *)(param_1 + 0x18),0x3bc,*(undefined4 *)(param_1 + 0x20),0,0);
  return;
}



/* c09436cc FUN_c09436cc */

undefined4 FUN_c09436cc(int param_1)

{
  return *(undefined4 *)(param_1 + 0x58);
}



/* c09436d4 FUN_c09436d4 */

/* Boundary evidence: original MIPS .pdata c09436d4..c09436fb. Semantic name remains unreviewed. */

undefined4 FUN_c09436d4(int *param_1,int param_2)

{
  code *pcVar1;
  
  pcVar1 = *(code **)(*param_1 + 0x34);
  param_1[0x16] = param_2;
  (*pcVar1)();
  return 0;
}



/* c09436fc FUN_c09436fc */

/* Boundary evidence: original MIPS .pdata c09436fc..c0943737. Semantic name remains unreviewed. */

bool FUN_c09436fc(int *param_1,uint param_2)

{
  code *pcVar1;
  
  if (param_2 < 4) {
    pcVar1 = *(code **)(*param_1 + 0x34);
    param_1[0x17] = param_2;
    (*pcVar1)();
  }
  return param_2 >= 4;
}



/* c0943738 FUN_c0943738 */

undefined4 FUN_c0943738(void)

{
  return 0;
}



/* c0943740 FUN_c0943740 */

/* Boundary evidence: original MIPS .pdata c0943740..c0943877. Semantic name remains unreviewed. */

int FUN_c0943740(int *param_1,int *param_2,int *param_3,int param_4)

{
  int iVar1;
  short *_Src;
  size_t _Size;
  code *pcVar2;
  
  param_1[3] = 1;
  param_1[0x14] = (int)param_2;
  param_1[7] = param_3[2];
  param_1[8] = param_3[3];
  param_1[6] = *param_3;
  param_1[5] = param_4;
  param_1[4] = 0;
  param_1[0x1a] = 0;
  _Src = (short *)param_3[1];
  if (*_Src == 1) {
    *(undefined1 *)(param_1 + 0xd) = 0;
    _Size = 0x10;
    *(undefined1 *)((int)param_1 + 0x35) = 0;
  }
  else {
    _Size = 0x12;
  }
  memcpy(param_1 + 9,_Src,_Size);
  param_1[0xe] = 0;
  param_1[0x10] = 0;
  param_1[0xf] = 0;
  param_1[0x11] = 0;
  param_1[0x12] = 0;
  param_1[0x13] = 0;
  param_1[0x15] = 0;
  param_1[0x17] = 0;
  iVar1 = FUN_c0942898((int)param_2);
  pcVar2 = *(code **)(*param_1 + 0x34);
  param_1[0x16] = iVar1;
  (*pcVar2)(param_1);
  (**(code **)(*param_1 + 0x20))(param_1);
  iVar1 = (**(code **)(*param_2 + 4))(param_2,param_1);
  if (iVar1 == 0) {
    (**(code **)(*param_1 + 0x28))(param_1);
  }
  return iVar1;
}



/* c0943878 FUN_c0943878 */

void FUN_c0943878(int param_1)

{
  *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + 1;
  return;
}



/* c0943888 FUN_c0943888 */

/* Boundary evidence: original MIPS .pdata c0943888..c09438e3. Semantic name remains unreviewed. */

int FUN_c0943888(int *param_1)

{
  int iVar1;
  
  iVar1 = param_1[3] + -1;
  param_1[3] = iVar1;
  if (iVar1 == 0) {
    FUN_c0942a80(param_1[0x14],param_1);
    (**(code **)*param_1)(param_1,1);
  }
  return iVar1;
}



/* c09438e4 FUN_c09438e4 */

/* Boundary evidence: original MIPS .pdata c09438e4..c09439af. Semantic name remains unreviewed. */

undefined4 FUN_c09438e4(int param_1,int *param_2)

{
  undefined4 uVar1;
  
  if ((param_2[4] & 2U) == 0) {
    uVar1 = 0x22;
  }
  else {
    param_2[6] = 0;
    param_2[4] = param_2[4] & 0xfffffffeU | 0x10;
    param_2[2] = 0;
    if (*(int *)(param_1 + 0x38) == 0) {
      *(int **)(param_1 + 0x38) = param_2;
    }
    else {
      *(int **)(*(int *)(param_1 + 0x40) + 0x18) = param_2;
    }
    *(int **)(param_1 + 0x40) = param_2;
    if (*(int *)(param_1 + 0x3c) == 0) {
      *(int **)(param_1 + 0x3c) = param_2;
      *(int *)(param_1 + 0x44) = *param_2;
      *(int *)(param_1 + 0x48) = param_2[1] + *param_2;
      if ((param_2[4] & 4U) != 0) {
        *(int *)(param_1 + 0x54) = param_2[5];
      }
    }
    if (*(int *)(param_1 + 0x10) != 0) {
      (**(code **)(**(int **)(param_1 + 0x50) + 0x10))();
    }
    uVar1 = 0;
  }
  return uVar1;
}



/* c09439b0 FUN_c09439b0 */

/* Boundary evidence: original MIPS .pdata c09439b0..c0943ab7. Semantic name remains unreviewed. */

int FUN_c09439b0(int *param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int *piVar4;
  
  iVar1 = param_1[0xf];
  if (iVar1 == 0) {
    iVar1 = 0;
  }
  else {
    uVar3 = param_1[0x15];
    if (uVar3 < 2) {
      piVar4 = *(int **)(iVar1 + 0x18);
      param_1[0xe] = (int)piVar4;
      if (piVar4 == (int *)0x0) {
        param_1[0x10] = 0;
      }
      else if ((piVar4[4] & 4U) != 0) {
        param_1[0x15] = piVar4[5];
      }
    }
    else {
      if ((*(uint *)(iVar1 + 0x10) & 8) == 0) {
        piVar4 = *(int **)(iVar1 + 0x18);
      }
      else {
        if (uVar3 != 0xffffffff) {
          param_1[0x15] = uVar3 - 1;
        }
        piVar4 = (int *)param_1[0xe];
      }
      iVar1 = 0;
    }
    param_1[0xf] = (int)piVar4;
    if (piVar4 == (int *)0x0) {
      param_1[0x11] = 0;
      param_1[0x12] = 0;
    }
    else {
      iVar2 = *piVar4;
      param_1[0x11] = iVar2;
      param_1[0x12] = piVar4[1] + iVar2;
    }
    if (iVar1 != 0) {
      *(uint *)(iVar1 + 0x10) = *(uint *)(iVar1 + 0x10) & 0xffffffef | 1;
      (**(code **)(*param_1 + 0x24))(param_1);
    }
    iVar1 = param_1[0x11];
  }
  return iVar1;
}



/* c0943ab8 FUN_c0943ab8 */

/* Boundary evidence: original MIPS .pdata c0943ab8..c0943b53. Semantic name remains unreviewed. */

undefined4 FUN_c0943ab8(int *param_1)

{
  int iVar1;
  int iVar2;
  
  param_1[3] = param_1[3] + 1;
  if ((param_1[0x15] != 0) && (param_1[0x15] = 0, param_1[0xe] != param_1[0xf])) {
    do {
      iVar1 = param_1[0xe];
      iVar2 = *(int *)(iVar1 + 0x18);
      param_1[0xe] = iVar2;
      if (iVar2 == 0) {
        param_1[0x10] = 0;
      }
      *(uint *)(iVar1 + 0x10) = *(uint *)(iVar1 + 0x10) & 0xffffffef | 1;
      (**(code **)(*param_1 + 0x24))(param_1);
    } while (param_1[0xe] != param_1[0xf]);
  }
  FUN_c0943888(param_1);
  return 0;
}



/* c0943b54 FUN_c0943b54 */

/* Boundary evidence: original MIPS .pdata c0943b54..c0943c67. Semantic name remains unreviewed. */

uint FUN_c0943b54(int param_1,uint param_2,int param_3)

{
  uint uVar1;
  uint uVar2;
  
  if (param_3 == 1) {
    param_2 = param_2 >> 0x10;
  }
  if (*(uint *)(param_1 + 0x5c) < 2) {
    uVar2 = FUN_c0945acc(*(int *)(param_1 + 0x50));
    if (param_3 == 1) {
      uVar2 = uVar2 >> 0x10;
    }
    uVar2 = uVar2 & 0xffff;
  }
  else {
    uVar2 = 0xffff;
  }
  uVar1 = FUN_c09428a0(*(int *)(param_1 + 0x50),*(int *)(param_1 + 0x5c));
  if ((((param_2 & 0xffff) != 0) && (uVar2 != 0)) && ((uVar1 & 0xffff) != 0)) {
    uVar2 = (param_2 & 0xffff) * -200 + ((uVar1 & 0xffff) + uVar2) * -0x46 + 0x1547eac >> 0x10;
    if (uVar2 == 0) {
      return 0x10000;
    }
    if (uVar2 < 0xc9) {
      return (uint)*(ushort *)(&DAT_c0941376 + uVar2 * 2);
    }
  }
  return 0;
}



/* c0943d40 FUN_c0943d40 */

/* Boundary evidence: original MIPS .pdata c0943d40..c0943e33. Semantic name remains unreviewed. */

int FUN_c0943d40(int *param_1,int *param_2,int *param_3,int param_4)

{
  short *psVar1;
  int *piVar2;
  int iVar3;
  
  psVar1 = (short *)(param_3[1] + 2);
  iVar3 = 2;
  if (*(short *)(param_3[1] + 0xe) == 8) {
    if (*psVar1 == 1) {
      param_1[0x1b] = 0;
      param_1[0x1c] = 1;
      goto LAB_c0943ddc;
    }
    param_1[0x1b] = 2;
  }
  else {
    if (*psVar1 != 1) {
      param_1[0x1b] = 3;
      param_1[0x1c] = 4;
      goto LAB_c0943ddc;
    }
    param_1[0x1b] = 1;
  }
  param_1[0x1c] = 2;
LAB_c0943ddc:
  piVar2 = param_1 + 0x20;
  do {
    piVar2[-2] = 0;
    *piVar2 = 0;
    iVar3 = iVar3 + -1;
    piVar2 = piVar2 + 1;
  } while (iVar3 != 0);
  iVar3 = FUN_c0943740(param_1,param_2,param_3,param_4);
  if (iVar3 == 0) {
    (**(code **)(*param_1 + 0x3c))(param_1,0x10000);
  }
  return iVar3;
}



/* c0943e34 FUN_c0943e34 */

undefined4 FUN_c0943e34(int param_1,undefined4 *param_2)

{
  *param_2 = *(undefined4 *)(param_1 + 0x74);
  return 0;
}



/* c0943e44 FUN_c0943e44 */

/* Boundary evidence: original MIPS .pdata c0943e44..c0943e87. Semantic name remains unreviewed. */

undefined4 FUN_c0943e44(int param_1)

{
  *(undefined4 *)(param_1 + 0x10) = 1;
  if (*(int *)(param_1 + 0x44) != 0) {
    (**(code **)(**(int **)(param_1 + 0x50) + 0x10))();
  }
  return 0;
}



/* c0943e88 FUN_c0943e88 */

undefined4 FUN_c0943e88(int param_1)

{
  *(undefined4 *)(param_1 + 0x10) = 0;
  return 0;
}



/* c0943e94 FUN_c0943e94 */

/* Boundary evidence: original MIPS .pdata c0943e94..c0943f3f. Semantic name remains unreviewed. */

undefined4 FUN_c0943e94(int *param_1)

{
  int iVar1;
  int iVar2;
  code *pcVar3;
  
  pcVar3 = *(code **)(*param_1 + 0x14);
  param_1[3] = param_1[3] + 1;
  (*pcVar3)(param_1);
  iVar1 = param_1[0xe];
  param_1[0xf] = 0;
  param_1[0x11] = 0;
  param_1[0x12] = 0;
  param_1[0x13] = 0;
  param_1[0x15] = 0;
  while (iVar1 != 0) {
    iVar1 = param_1[0xe];
    iVar2 = *(int *)(iVar1 + 0x18);
    param_1[0xe] = iVar2;
    if (iVar2 == 0) {
      param_1[0x10] = 0;
    }
    *(uint *)(iVar1 + 0x10) = *(uint *)(iVar1 + 0x10) & 0xffffffef | 1;
    (**(code **)(*param_1 + 0x24))(param_1);
    iVar1 = param_1[0xe];
  }
  FUN_c0943888(param_1);
  return 0;
}



/* c0943f40 FUN_c0943f40 */

/* Boundary evidence: original MIPS .pdata c0943f40..c0943f8b. Semantic name remains unreviewed. */

undefined4 FUN_c0943f40(int param_1,int param_2)

{
  undefined4 uVar1;
  uint uVar2;
  
  uVar2 = (uint)(param_2 != 0);
  if (uVar2 == *(uint *)(param_1 + 0x68)) {
    uVar1 = 0;
  }
  else {
    *(uint *)(param_1 + 0x68) = uVar2;
    uVar1 = FUN_c0947b1c(DAT_c094a140,uVar2);
  }
  return uVar1;
}



/* c0943f8c FUN_c0943f8c */

/* Boundary evidence: original MIPS .pdata c0943f8c..c0943fef. Semantic name remains unreviewed. */

undefined4 FUN_c0943f8c(int param_1,uint param_2)

{
  longlong lVar1;
  undefined4 uVar2;
  uint uVar3;
  
  lVar1 = (ulonglong)*(uint *)(param_1 + 0x28) * (ulonglong)param_2;
  *(uint *)(param_1 + 0x74) = param_2;
  uVar3 = (int)((ulonglong)lVar1 >> 0x20) << 0x10 | (uint)lVar1 >> 0x10;
  *(uint *)(param_1 + 0x8c) = uVar3;
  uVar2 = __ll_div(0,1,uVar3,0);
  *(undefined4 *)(param_1 + 0x90) = uVar2;
  return 0;
}



/* c0943ff0 FUN_c0943ff0 */

/* Boundary evidence: original MIPS .pdata c0943ff0..c094412f. Semantic name remains unreviewed. */

uint FUN_c0943ff0(int *param_1,uint param_2,uint param_3,undefined4 param_4,undefined4 param_5)

{
  int iVar1;
  
  if ((param_1[4] != 0) && (param_1[0x11] != 0)) {
    for (; param_2 < param_3;
        param_2 = (**(code **)(*param_1 + 0x40))(param_1,param_2,param_3,param_4,param_5)) {
      if ((uint)param_1[0x12] <= (uint)param_1[0x11]) {
        do {
          iVar1 = FUN_c09439b0(param_1);
          if (iVar1 == 0) {
            return param_2;
          }
        } while ((uint)param_1[0x12] <= (uint)param_1[0x11]);
      }
    }
  }
  return param_2;
}



/* c0944130 FUN_c0944130 */

/* Boundary evidence: original MIPS .pdata c0944130..c094413b. Semantic name remains unreviewed. */

undefined4 FUN_c0944130(void)

{
  return 1;
}



/* c094413c FUN_c094413c */

/* Boundary evidence: original MIPS .pdata c094413c..c094415b. Semantic name remains unreviewed. */

void FUN_c094413c(void *param_1,int param_2)

{
  memset(param_1,0,param_2 - (int)param_1);
  return;
}



/* c094415c FUN_c094415c */

/* Boundary evidence: original MIPS .pdata c094415c..c0944177. Semantic name remains unreviewed. */

void FUN_c094415c(int param_1,undefined4 *param_2)

{
  FUN_c0942fc4(*(int **)(param_1 + 0x50),param_2);
  return;
}



/* c0944178 FUN_c0944178 */

/* Boundary evidence: original MIPS .pdata c0944178..c0944193. Semantic name remains unreviewed. */

void FUN_c0944178(void)

{
  FUN_c0945ccc();
  return;
}



/* c0944194 FUN_c0944194 */

/* Boundary evidence: original MIPS .pdata c0944194..c09441d7. Semantic name remains unreviewed. */

undefined4 * FUN_c0944194(undefined4 *param_1,uint param_2)

{
  *param_1 = &PTR_FUN_c0941508;
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}



/* c09441d8 FUN_c09441d8 */

/* Boundary evidence: original MIPS .pdata c09441d8..c0944233. Semantic name remains unreviewed. */

void FUN_c09441d8(int param_1)

{
  uint uVar1;
  int iVar2;
  uint *puVar3;
  
  iVar2 = 0;
  puVar3 = (uint *)(param_1 + 0x60);
  do {
    uVar1 = FUN_c0943b54(param_1,*(uint *)(param_1 + 0x58),iVar2);
    iVar2 = iVar2 + 1;
    *puVar3 = uVar1;
    puVar3 = puVar3 + 1;
  } while (iVar2 < 2);
  return;
}



/* c0944234 FUN_c0944234 */

/* Boundary evidence: original MIPS .pdata c0944234..c094429b. Semantic name remains unreviewed. */

undefined4 FUN_c0944234(int *param_1)

{
  undefined4 uVar1;
  
  if (param_1[0xe] == 0) {
    if (param_1[0x1a] != 0) {
      param_1[0x1a] = 0;
      FUN_c0947b1c(DAT_c094a140,0);
    }
    (**(code **)(*param_1 + 0x2c))(param_1);
    uVar1 = 0;
  }
  else {
    uVar1 = 0x21;
  }
  return uVar1;
}



/* c094429c FUN_c094429c */

/* Boundary evidence: original MIPS .pdata c094429c..c09442cf. Semantic name remains unreviewed. */

void FUN_c094429c(int *param_1,int *param_2,int *param_3,int param_4)

{
  FUN_c0943d40(param_1,param_2,param_3,param_4);
  param_1[0x22] = -param_1[0x23];
  return;
}



/* c09442d0 FUN_c09442d0 */

/* Boundary evidence: original MIPS .pdata c09442d0..c09442f3. Semantic name remains unreviewed. */

void FUN_c09442d0(int param_1,undefined4 param_2)

{
  FUN_c09435fc(param_1,0x3c0,param_2,0);
  return;
}



/* c09442f4 FUN_c09442f4 */

/* Boundary evidence: original MIPS .pdata c09442f4..c0944317. Semantic name remains unreviewed. */

void FUN_c09442f4(int param_1)

{
  FUN_c09435fc(param_1,0x3be,0,0);
  return;
}



/* c0944318 FUN_c0944318 */

/* Boundary evidence: original MIPS .pdata c0944318..c094433b. Semantic name remains unreviewed. */

void FUN_c0944318(int param_1)

{
  FUN_c09435fc(param_1,0x3bf,0,0);
  return;
}



/* c094433c FUN_c094433c */

/* Boundary evidence: original MIPS .pdata c094433c..c0944387. Semantic name remains unreviewed. */

undefined4 FUN_c094433c(int *param_1)

{
  FUN_c0943e88((int)param_1);
  if ((param_1[0xf] != 0) && (*(int *)(param_1[0xf] + 8) != 0)) {
    FUN_c09439b0(param_1);
  }
  return 0;
}



/* c0944388 FUN_c0944388 */

/* Boundary evidence: original MIPS .pdata c0944388..c094457b. Semantic name remains unreviewed. */

short * FUN_c0944388(int param_1,short *param_2,short *param_3)

{
  short *psVar1;
  short sVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  char *pcVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  uint uVar12;
  char *pcVar13;
  int iVar14;
  int iVar15;
  int iVar16;
  int iVar17;
  int iVar18;
  
  iVar14 = *(int *)(param_1 + 0x88);
  iVar15 = *(int *)(param_1 + 0x8c);
  iVar16 = *(int *)(param_1 + 0x90);
  iVar5 = FUN_c0942e7c(*(int *)(param_1 + 0x50));
  pcVar13 = *(char **)(param_1 + 0x44);
  pcVar7 = *(char **)(param_1 + 0x48);
  iVar9 = *(int *)(param_1 + 0x60);
  iVar17 = *(int *)(param_1 + 100);
  iVar18 = *(int *)(param_1 + 0x80);
  iVar10 = *(int *)(param_1 + 0x78);
  iVar6 = *(int *)(param_1 + 0x84);
  iVar8 = *(int *)(param_1 + 0x7c);
joined_r0xc09443ec:
  do {
    iVar3 = iVar6;
    if (pcVar7 <= pcVar13) {
LAB_c094450c:
      *(char **)(*(int *)(param_1 + 0x3c) + 8) =
           pcVar13 + (*(int *)(*(int *)(param_1 + 0x3c) + 8) - *(int *)(param_1 + 0x44));
      *(int *)(param_1 + 0x88) = iVar14;
      *(char **)(param_1 + 0x4c) = pcVar13 + (*(int *)(param_1 + 0x4c) - *(int *)(param_1 + 0x44));
      *(char **)(param_1 + 0x44) = pcVar13;
      *(int *)(param_1 + 0x78) = iVar10;
      *(int *)(param_1 + 0x80) = iVar18;
      *(int *)(param_1 + 0x7c) = iVar8;
      *(int *)(param_1 + 0x84) = iVar6;
      return param_2;
    }
    for (; iVar6 = iVar3, iVar14 < 0; iVar14 = iVar15 + iVar14) {
      if (param_3 <= param_2) goto LAB_c094450c;
      sVar2 = *param_2;
      psVar1 = param_2 + 1;
      param_2 = param_2 + 2;
      iVar3 = (int)*psVar1;
      iVar8 = iVar6;
      iVar10 = iVar18;
      iVar18 = (int)sVar2;
    }
    uVar12 = iVar16 * iVar14;
    iVar14 = iVar14 - iVar5;
    uVar12 = uVar12 >> 0x11;
    iVar3 = (((int)((iVar10 - iVar18) * uVar12) >> 0xf) + iVar18) * iVar9;
    iVar11 = *(int *)(param_1 + 0x6c);
    iVar4 = (((int)((iVar8 - iVar6) * uVar12) >> 0xf) + iVar6) * iVar17;
    if (iVar11 == 1) {
      *(short *)pcVar13 = (short)((iVar4 >> 0x10) + (iVar3 >> 0x10) >> 1);
    }
    else {
      if (iVar11 != 2) {
        if (iVar11 == 3) {
          *(short *)pcVar13 = (short)((uint)iVar3 >> 0x10);
          *(short *)(pcVar13 + 2) = (short)((uint)iVar4 >> 0x10);
          pcVar13 = pcVar13 + 4;
        }
        else {
          *pcVar13 = (char)((iVar4 >> 0x10) + (iVar3 >> 0x10) >> 9) + -0x80;
          pcVar13 = pcVar13 + 1;
        }
        goto joined_r0xc09443ec;
      }
      *pcVar13 = (char)((uint)iVar3 >> 0x18) + -0x80;
      pcVar13[1] = (char)((uint)iVar4 >> 0x18) + -0x80;
    }
    pcVar13 = pcVar13 + 2;
  } while( true );
}



/* c094457c FUN_c094457c */

/* Boundary evidence: original MIPS .pdata c094457c..c09445d7. Semantic name remains unreviewed. */

int FUN_c094457c(int *param_1,int *param_2,int *param_3,int param_4)

{
  int iVar1;
  int iVar2;
  
  iVar1 = FUN_c0943d40(param_1,param_2,param_3,param_4);
  iVar2 = FUN_c0942e7c(param_1[0x14]);
  param_1[0x22] = -iVar2;
  if (iVar1 == 0) {
    (**(code **)(*param_1 + 0x10))(param_1);
  }
  return iVar1;
}



/* c09445d8 FUN_c09445d8 */

/* Boundary evidence: original MIPS .pdata c09445d8..c0944627. Semantic name remains unreviewed. */

int FUN_c09445d8(int *param_1)

{
  int iVar1;
  
  iVar1 = FUN_c0943e94(param_1);
  if (iVar1 == 0) {
    (**(code **)(*param_1 + 0x10))(param_1);
  }
  return iVar1;
}



/* c0944630 FUN_c0944630 */

/* Boundary evidence: original MIPS .pdata c0944630..c09447ff. Semantic name remains unreviewed. */

short * FUN_c0944630(int param_1,short *param_2,short *param_3,short *param_4,int param_5)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  byte *pbVar7;
  int iVar8;
  int iVar9;
  byte *pbVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  
  iVar11 = *(int *)(param_1 + 0x88);
  iVar12 = *(int *)(param_1 + 0x8c);
  iVar3 = FUN_c0942e7c(*(int *)(param_1 + 0x50));
  iVar4 = FUN_c0942e84(*(int *)(param_1 + 0x50));
  iVar13 = *(int *)(param_1 + 0x80);
  iVar6 = *(int *)(param_1 + 0x78);
  pbVar10 = *(byte **)(param_1 + 0x44);
  pbVar7 = *(byte **)(param_1 + 0x48);
  if (*(int *)(param_5 + 4) == 0) {
    iVar14 = *(int *)(param_1 + 0x60);
    iVar5 = *(int *)(param_1 + 100);
  }
  else {
    iVar14 = 0;
    iVar5 = 0;
  }
  for (; param_2 < param_3; param_2 = param_2 + 2) {
    for (; iVar11 < 0; iVar11 = iVar3 + iVar11) {
      if (pbVar7 <= pbVar10) goto LAB_c09447b0;
      bVar1 = *pbVar10;
      pbVar10 = pbVar10 + 1;
      iVar6 = iVar13;
      iVar13 = (bVar1 - 0x80) * 0x100;
    }
    uVar2 = iVar4 * iVar11;
    iVar11 = iVar11 - iVar12;
    iVar8 = ((int)((iVar6 - iVar13) * (uVar2 >> 0x11)) >> 0xf) + iVar13;
    iVar9 = iVar8 * iVar14 >> 0x10;
    iVar8 = iVar8 * iVar5 >> 0x10;
    if (param_2 < param_4) {
      iVar9 = *param_2 + iVar9;
      iVar8 = param_2[1] + iVar8;
      if (iVar9 < 0x8000) {
        if (iVar9 < -0x8000) {
          iVar9 = -0x8000;
        }
      }
      else {
        iVar9 = 0x7fff;
      }
      if (iVar8 < 0x8000) {
        if (iVar8 < -0x8000) {
          iVar8 = -0x8000;
        }
      }
      else {
        iVar8 = 0x7fff;
      }
    }
    *param_2 = (short)iVar9;
    param_2[1] = (short)iVar8;
  }
LAB_c09447b0:
  *(int *)(param_1 + 0x88) = iVar11;
  *(byte **)(param_1 + 0x4c) = pbVar10 + (*(int *)(param_1 + 0x4c) - *(int *)(param_1 + 0x44));
  *(byte **)(param_1 + 0x44) = pbVar10;
  *(int *)(param_1 + 0x78) = iVar6;
  *(int *)(param_1 + 0x80) = iVar13;
  return param_2;
}



/* c0944800 FUN_c0944800 */

/* Boundary evidence: original MIPS .pdata c0944800..c09449cb. Semantic name remains unreviewed. */

short * FUN_c0944800(int param_1,short *param_2,short *param_3,short *param_4,int param_5)

{
  short sVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  short *psVar7;
  int iVar8;
  int iVar9;
  short *psVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  
  iVar11 = *(int *)(param_1 + 0x88);
  iVar12 = *(int *)(param_1 + 0x8c);
  iVar3 = FUN_c0942e7c(*(int *)(param_1 + 0x50));
  iVar4 = FUN_c0942e84(*(int *)(param_1 + 0x50));
  iVar13 = *(int *)(param_1 + 0x80);
  iVar14 = *(int *)(param_1 + 0x78);
  psVar10 = *(short **)(param_1 + 0x44);
  psVar7 = *(short **)(param_1 + 0x48);
  if (*(int *)(param_5 + 4) == 0) {
    iVar5 = *(int *)(param_1 + 0x60);
    iVar6 = *(int *)(param_1 + 100);
  }
  else {
    iVar5 = 0;
    iVar6 = 0;
  }
  for (; iVar8 = iVar13, param_2 < param_3; param_2 = param_2 + 2) {
    for (; iVar13 = iVar8, iVar11 < 0; iVar11 = iVar3 + iVar11) {
      if (psVar7 <= psVar10) goto LAB_c094497c;
      sVar1 = *psVar10;
      psVar10 = psVar10 + 1;
      iVar8 = (int)sVar1;
      iVar14 = iVar13;
    }
    uVar2 = iVar4 * iVar11;
    iVar11 = iVar11 - iVar12;
    iVar8 = ((int)((iVar14 - iVar13) * (uVar2 >> 0x11)) >> 0xf) + iVar13;
    iVar9 = iVar8 * iVar5 >> 0x10;
    iVar8 = iVar8 * iVar6 >> 0x10;
    if (param_2 < param_4) {
      iVar9 = *param_2 + iVar9;
      iVar8 = param_2[1] + iVar8;
      if (iVar9 < 0x8000) {
        if (iVar9 < -0x8000) {
          iVar9 = -0x8000;
        }
      }
      else {
        iVar9 = 0x7fff;
      }
      if (iVar8 < 0x8000) {
        if (iVar8 < -0x8000) {
          iVar8 = -0x8000;
        }
      }
      else {
        iVar8 = 0x7fff;
      }
    }
    *param_2 = (short)iVar9;
    param_2[1] = (short)iVar8;
  }
LAB_c094497c:
  *(int *)(param_1 + 0x88) = iVar11;
  *(int *)(param_1 + 0x4c) = (*(int *)(param_1 + 0x4c) - *(int *)(param_1 + 0x44)) + (int)psVar10;
  *(short **)(param_1 + 0x44) = psVar10;
  *(int *)(param_1 + 0x78) = iVar14;
  *(int *)(param_1 + 0x80) = iVar13;
  return param_2;
}



/* c09449cc FUN_c09449cc */

/* Boundary evidence: original MIPS .pdata c09449cc..c0944be3. Semantic name remains unreviewed. */

short * FUN_c09449cc(int param_1,short *param_2,short *param_3,short *param_4,int param_5)

{
  byte *pbVar1;
  byte bVar2;
  int iVar3;
  int iVar4;
  byte *pbVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  uint uVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  byte *pbVar16;
  int iVar17;
  
  iVar14 = *(int *)(param_1 + 0x88);
  iVar15 = *(int *)(param_1 + 0x8c);
  iVar3 = FUN_c0942e7c(*(int *)(param_1 + 0x50));
  iVar4 = FUN_c0942e84(*(int *)(param_1 + 0x50));
  iVar17 = *(int *)(param_1 + 0x80);
  iVar6 = *(int *)(param_1 + 0x84);
  iVar8 = *(int *)(param_1 + 0x78);
  iVar7 = *(int *)(param_1 + 0x7c);
  pbVar16 = *(byte **)(param_1 + 0x44);
  pbVar5 = *(byte **)(param_1 + 0x48);
  if (*(int *)(param_5 + 4) == 0) {
    iVar10 = *(int *)(param_1 + 0x60);
    iVar9 = *(int *)(param_1 + 100);
  }
  else {
    iVar10 = 0;
    iVar9 = 0;
  }
  for (; iVar12 = iVar6, param_2 < param_3; param_2 = param_2 + 2) {
    for (; iVar6 = iVar12, iVar14 < 0; iVar14 = iVar3 + iVar14) {
      if (pbVar5 <= pbVar16) goto LAB_c0944b84;
      bVar2 = *pbVar16;
      pbVar1 = pbVar16 + 1;
      pbVar16 = pbVar16 + 2;
      iVar12 = (*pbVar1 - 0x80) * 0x100;
      iVar7 = iVar6;
      iVar8 = iVar17;
      iVar17 = (bVar2 - 0x80) * 0x100;
    }
    uVar11 = iVar4 * iVar14;
    iVar14 = iVar14 - iVar15;
    uVar11 = uVar11 >> 0x11;
    iVar13 = (((int)((iVar8 - iVar17) * uVar11) >> 0xf) + iVar17) * iVar10 >> 0x10;
    iVar12 = (((int)((iVar7 - iVar6) * uVar11) >> 0xf) + iVar6) * iVar9 >> 0x10;
    if (param_2 < param_4) {
      iVar13 = *param_2 + iVar13;
      iVar12 = param_2[1] + iVar12;
      if (iVar13 < 0x8000) {
        if (iVar13 < -0x8000) {
          iVar13 = -0x8000;
        }
      }
      else {
        iVar13 = 0x7fff;
      }
      if (iVar12 < 0x8000) {
        if (iVar12 < -0x8000) {
          iVar12 = -0x8000;
        }
      }
      else {
        iVar12 = 0x7fff;
      }
    }
    *param_2 = (short)iVar13;
    param_2[1] = (short)iVar12;
  }
LAB_c0944b84:
  *(int *)(param_1 + 0x88) = iVar14;
  *(byte **)(param_1 + 0x4c) = pbVar16 + (*(int *)(param_1 + 0x4c) - *(int *)(param_1 + 0x44));
  *(byte **)(param_1 + 0x44) = pbVar16;
  *(int *)(param_1 + 0x78) = iVar8;
  *(int *)(param_1 + 0x7c) = iVar7;
  *(int *)(param_1 + 0x80) = iVar17;
  *(int *)(param_1 + 0x84) = iVar6;
  return param_2;
}



/* c0944be4 FUN_c0944be4 */

/* Boundary evidence: original MIPS .pdata c0944be4..c0944df3. Semantic name remains unreviewed. */

short * FUN_c0944be4(int param_1,short *param_2,short *param_3,short *param_4,int param_5)

{
  short *psVar1;
  short sVar2;
  int iVar3;
  int iVar4;
  short *psVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  uint uVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  short *psVar16;
  int iVar17;
  
  iVar14 = *(int *)(param_1 + 0x88);
  iVar15 = *(int *)(param_1 + 0x8c);
  iVar3 = FUN_c0942e7c(*(int *)(param_1 + 0x50));
  iVar4 = FUN_c0942e84(*(int *)(param_1 + 0x50));
  iVar17 = *(int *)(param_1 + 0x80);
  iVar6 = *(int *)(param_1 + 0x84);
  iVar8 = *(int *)(param_1 + 0x78);
  iVar7 = *(int *)(param_1 + 0x7c);
  psVar16 = *(short **)(param_1 + 0x44);
  psVar5 = *(short **)(param_1 + 0x48);
  if (*(int *)(param_5 + 4) == 0) {
    iVar10 = *(int *)(param_1 + 0x60);
    iVar9 = *(int *)(param_1 + 100);
  }
  else {
    iVar10 = 0;
    iVar9 = 0;
  }
  for (; iVar12 = iVar6, param_2 < param_3; param_2 = param_2 + 2) {
    for (; iVar6 = iVar12, iVar14 < 0; iVar14 = iVar3 + iVar14) {
      if (psVar5 <= psVar16) goto LAB_c0944d94;
      sVar2 = *psVar16;
      psVar1 = psVar16 + 1;
      psVar16 = psVar16 + 2;
      iVar12 = (int)*psVar1;
      iVar7 = iVar6;
      iVar8 = iVar17;
      iVar17 = (int)sVar2;
    }
    uVar11 = iVar4 * iVar14;
    iVar14 = iVar14 - iVar15;
    uVar11 = uVar11 >> 0x11;
    iVar13 = (((int)((iVar8 - iVar17) * uVar11) >> 0xf) + iVar17) * iVar10 >> 0x10;
    iVar12 = (((int)((iVar7 - iVar6) * uVar11) >> 0xf) + iVar6) * iVar9 >> 0x10;
    if (param_2 < param_4) {
      iVar13 = *param_2 + iVar13;
      iVar12 = param_2[1] + iVar12;
      if (iVar13 < 0x8000) {
        if (iVar13 < -0x8000) {
          iVar13 = -0x8000;
        }
      }
      else {
        iVar13 = 0x7fff;
      }
      if (iVar12 < 0x8000) {
        if (iVar12 < -0x8000) {
          iVar12 = -0x8000;
        }
      }
      else {
        iVar12 = 0x7fff;
      }
    }
    *param_2 = (short)iVar13;
    param_2[1] = (short)iVar12;
  }
LAB_c0944d94:
  *(int *)(param_1 + 0x88) = iVar14;
  *(int *)(param_1 + 0x4c) = (*(int *)(param_1 + 0x4c) - *(int *)(param_1 + 0x44)) + (int)psVar16;
  *(short **)(param_1 + 0x44) = psVar16;
  *(int *)(param_1 + 0x78) = iVar8;
  *(int *)(param_1 + 0x7c) = iVar7;
  *(int *)(param_1 + 0x80) = iVar17;
  *(int *)(param_1 + 0x84) = iVar6;
  return param_2;
}



/* c0944df4 FUN_c0944df4 */

/* Boundary evidence: original MIPS .pdata c0944df4..c0944e7f. Semantic name remains unreviewed. */

int FUN_c0944df4(int param_1,void *param_2,int param_3,undefined4 param_4,int param_5)

{
  uint _Size;
  
  _Size = *(int *)(param_1 + 0x48) - (int)*(void **)(param_1 + 0x44);
  if ((uint)(param_3 - (int)param_2) <= _Size) {
    _Size = param_3 - (int)param_2;
  }
  memcpy(param_2,*(void **)(param_1 + 0x44),_Size);
  *(uint *)(param_1 + 0x4c) = *(int *)(param_1 + 0x4c) + _Size;
  *(uint *)(param_1 + 0x44) = *(int *)(param_1 + 0x44) + _Size;
  *(undefined4 *)(param_5 + 8) = 1;
  *(undefined4 *)(param_5 + 4) = 1;
  return _Size + (int)param_2;
}



/* c0944e98 FUN_c0944e98 */

/* Boundary evidence: original MIPS .pdata c0944e98..c0944edf. Semantic name remains unreviewed. */

void FUN_c0944e98(int param_1)

{
  int *piVar1;
  
  for (piVar1 = *(int **)(param_1 + 0x66c); piVar1 != (int *)(param_1 + 0x66c);
      piVar1 = (int *)*piVar1) {
    FUN_c09458c0((int)piVar1);
  }
  return;
}



/* c0944ee0 FUN_c0944ee0 */

/* Boundary evidence: original MIPS .pdata c0944ee0..c0944f2f. Semantic name remains unreviewed. */

void FUN_c0944ee0(int param_1,uint param_2,int param_3)

{
  uint uVar1;
  
  uVar1 = *(uint *)(param_1 + 0x58);
  if (param_3 == 1) {
    uVar1 = uVar1 >> 0x10;
  }
  uVar1 = (uVar1 & 0xffff) * (param_2 & 0xffff) + 0xffff >> 0x10;
  if (param_3 == 1) {
    uVar1 = uVar1 << 0x10;
  }
  FUN_c0943b54(param_1,uVar1,param_3);
  return;
}



/* c0944f30 FUN_c0944f30 */

/* Boundary evidence: original MIPS .pdata c0944f30..c0944ffb. Semantic name remains unreviewed. */

int FUN_c0944f30(int *param_1,int *param_2,int *param_3,int param_4)

{
  int *piVar1;
  undefined4 *puVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  int iVar6;
  
  iVar6 = param_3[1];
  if (*(short *)(iVar6 + 0x10) == 10) {
    piVar5 = param_1 + 0x19b;
    param_1[0x1a1] = *(int *)(iVar6 + 0x14);
    iVar6 = *(int *)(iVar6 + 0x18);
    piVar4 = param_1 + 0x19d;
    param_1[0x19c] = (int)piVar5;
    *piVar5 = (int)piVar5;
    piVar5 = param_1 + 0x1c;
    iVar3 = 0x20;
    param_1[0x1a2] = iVar6;
    param_1[0x1a4] = 0;
    param_1[0x19e] = (int)piVar4;
    *piVar4 = (int)piVar4;
    do {
      puVar2 = (undefined4 *)param_1[0x19e];
      piVar1 = piVar5 + -1;
      *piVar5 = (int)puVar2;
      *piVar1 = (int)piVar4;
      *puVar2 = piVar1;
      piVar5 = piVar5 + 0xc;
      iVar3 = iVar3 + -1;
      param_1[0x19e] = (int)piVar1;
    } while (iVar3 != 0);
    iVar6 = FUN_c0943740(param_1,param_2,param_3,param_4);
    if (iVar6 == 0) {
      (**(code **)(*param_1 + 0x10))(param_1);
      iVar6 = 0;
    }
  }
  else {
    iVar6 = 0x20;
  }
  return iVar6;
}



/* c0944ffc FUN_c0944ffc */

/* Boundary evidence: original MIPS .pdata c0944ffc..c09450a7. Semantic name remains unreviewed. */

undefined4 FUN_c0944ffc(int param_1)

{
  longlong lVar1;
  longlong lVar2;
  uint uVar3;
  undefined4 uVar4;
  
  if (*(int *)(param_1 + 0x684) == 0) {
    *(undefined4 *)(param_1 + 0x684) = 500000;
  }
  if (*(int *)(param_1 + 0x688) == 0) {
    *(undefined4 *)(param_1 + 0x688) = 0x60;
  }
  uVar3 = FUN_c0942e7c(*(int *)(param_1 + 0x50));
  lVar1 = (ulonglong)*(uint *)(param_1 + 0x684) * (ulonglong)uVar3;
  lVar2 = (ulonglong)*(uint *)(param_1 + 0x688) * 1000000;
  uVar4 = __ull_div((int)lVar1,(int)((ulonglong)lVar1 >> 0x20),(int)lVar2,
                    (int)((ulonglong)lVar2 >> 0x20));
  *(undefined4 *)(param_1 + 0x68c) = uVar4;
  return 0;
}



/* c09450a8 FUN_c09450a8 */

/* Boundary evidence: original MIPS .pdata c09450a8..c0945123. Semantic name remains unreviewed. */

int FUN_c09450a8(int param_1,int param_2,int param_3)

{
  int iVar1;
  int *piVar2;
  
  piVar2 = *(int **)(param_1 + 0x66c);
  while( true ) {
    if (piVar2 == (int *)(param_1 + 0x66c)) {
      return 0;
    }
    iVar1 = FUN_c0945acc((int)piVar2);
    if ((iVar1 == param_2) && (iVar1 = FUN_c0945ad4((int)piVar2), iVar1 == param_3)) break;
    piVar2 = (int *)*piVar2;
  }
  return (int)piVar2;
}



/* c0945124 FUN_c0945124 */

/* Boundary evidence: original MIPS .pdata c0945124..c094517b. Semantic name remains unreviewed. */

undefined4 FUN_c0945124(int param_1)

{
  int *piVar1;
  int *piVar2;
  
  piVar1 = (int *)*(int *)(param_1 + 0x66c);
  while (piVar1 != (int *)(param_1 + 0x66c)) {
    piVar2 = (int *)*piVar1;
    FUN_c094596c((int)piVar1);
    piVar1 = piVar2;
  }
  return 0;
}



/* c094517c FUN_c094517c */

/* Boundary evidence: original MIPS .pdata c094517c..c094524b. Semantic name remains unreviewed. */

void FUN_c094517c(int param_1)

{
  longlong lVar1;
  uint uVar2;
  uint *puVar3;
  int iVar4;
  int *piVar5;
  
  uVar2 = FUN_c0942e84(*(int *)(param_1 + 0x50));
  if (DAT_c094a134 != uVar2) {
    iVar4 = 0;
    DAT_c094a134 = uVar2;
    do {
      lVar1 = (ulonglong)*(uint *)((int)&DAT_c09415ac + iVar4) * (ulonglong)uVar2;
      puVar3 = (uint *)((int)&DAT_c094a104 + iVar4);
      iVar4 = iVar4 + 4;
      *puVar3 = (int)((ulonglong)lVar1 >> 0x20) * 0x10000 | (uint)lVar1 >> 0x10;
    } while (iVar4 < 0x30);
  }
  FUN_c0944ffc(param_1);
  for (piVar5 = *(int **)(param_1 + 0x66c); piVar5 != (int *)(param_1 + 0x66c);
      piVar5 = (int *)*piVar5) {
    FUN_c094591c((int)piVar5);
  }
  return;
}



/* c094524c FUN_c094524c */

uint FUN_c094524c(undefined4 param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = param_2 / 0xc - 5;
  uVar1 = (&DAT_c094a104)[param_2 % 0xc];
  if ((int)uVar2 < 1) {
    if ((int)uVar2 < 0) {
      uVar1 = uVar1 >> (-uVar2 & 0x1f);
    }
  }
  else {
    uVar1 = uVar1 << (uVar2 & 0x1f);
  }
  return uVar1;
}



/* c09452a4 FUN_c09452a4 */

/* Boundary evidence: original MIPS .pdata c09452a4..c09452d3. Semantic name remains unreviewed. */

int FUN_c09452a4(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = FUN_c0942e84(*(int *)(param_1 + 0x50));
  return iVar1 * param_2;
}



/* c09452d4 FUN_c09452d4 */

/* Boundary evidence: original MIPS .pdata c09452d4..c094531b. Semantic name remains unreviewed. */

void FUN_c09452d4(int *param_1,int *param_2)

{
  undefined4 *puVar1;
  
  *(int *)param_2[1] = *param_2;
  *(int *)(*param_2 + 4) = param_2[1];
  puVar1 = (undefined4 *)param_1[0x19e];
  *param_2 = (int)(param_1 + 0x19d);
  param_2[1] = (int)puVar1;
  *puVar1 = param_2;
  param_1[0x19e] = (int)param_2;
  FUN_c0943888(param_1);
  return;
}



/* c094531c FUN_c094531c */

/* Boundary evidence: original MIPS .pdata c094531c..c0945377. Semantic name remains unreviewed. */

int FUN_c094531c(int *param_1)

{
  int iVar1;
  
  iVar1 = FUN_c0943e94(param_1);
  if (iVar1 == 0) {
    FUN_c0945124((int)param_1);
    (**(code **)(*param_1 + 0x10))(param_1);
  }
  return iVar1;
}



/* c0945378 FUN_c0945378 */

/* Boundary evidence: original MIPS .pdata c0945378..c09453c3. Semantic name remains unreviewed. */

int FUN_c0945378(int *param_1)

{
  int iVar1;
  
  iVar1 = FUN_c0944234(param_1);
  if (iVar1 == 0) {
    FUN_c0945124((int)param_1);
  }
  return iVar1;
}



/* c09453c4 FUN_c09453c4 */

/* Boundary evidence: original MIPS .pdata c09453c4..c09454af. Semantic name remains unreviewed. */

undefined4 FUN_c09453c4(int param_1,int param_2,int param_3,int param_4)

{
  int *piVar1;
  undefined4 *puVar2;
  
  piVar1 = (int *)FUN_c09450a8(param_1,param_2,param_4);
  if (piVar1 == (int *)0x0) {
    piVar1 = *(int **)(param_1 + 0x674);
    if (piVar1 == (int *)(param_1 + 0x674)) {
      piVar1 = *(int **)(param_1 + 0x66c);
    }
    else {
      FUN_c0943878(param_1);
    }
    FUN_c0945b0c((int)piVar1,param_1,param_2,param_3,param_4);
  }
  else {
    FUN_c0945adc((int)piVar1,param_3);
  }
  *(int *)piVar1[1] = *piVar1;
  *(int *)(*piVar1 + 4) = piVar1[1];
  puVar2 = *(undefined4 **)(param_1 + 0x670);
  *piVar1 = param_1 + 0x66c;
  piVar1[1] = (int)puVar2;
  *puVar2 = piVar1;
  *(int **)(param_1 + 0x670) = piVar1;
  return 0;
}



/* c09454b0 FUN_c09454b0 */

/* Boundary evidence: original MIPS .pdata c09454b0..c0945583. Semantic name remains unreviewed. */

undefined4 FUN_c09454b0(int param_1,uint param_2)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  
  if ((param_2 & 0x80) == 0) {
    param_2 = (uint)*(byte *)(param_1 + 0x680) | param_2 << 8;
  }
  else {
    *(char *)(param_1 + 0x680) = (char)param_2;
  }
  uVar4 = param_2 >> 8 & 0x7f;
  uVar3 = param_2 & 0xf0;
  uVar5 = param_2 >> 0x10 & 0x7f;
  if (uVar3 != 0x80) {
    if (uVar3 != 0x90) {
      if (uVar3 != 0xb0) {
        return 0x80004001;
      }
      if (uVar4 != 0x7b) {
        return 0x80004001;
      }
      uVar1 = FUN_c0945124(param_1);
      return uVar1;
    }
    if (uVar5 != 0) {
      uVar1 = FUN_c09453c4(param_1,uVar4,uVar5,param_2 & 0xf);
      return uVar1;
    }
  }
  iVar2 = FUN_c09450a8(param_1,uVar4,param_2 & 0xf);
  if (iVar2 != 0) {
    FUN_c094596c(iVar2);
  }
  return 0;
}



/* c0945584 FUN_c0945584 */

/* Boundary evidence: original MIPS .pdata c0945584..c094565b. Semantic name remains unreviewed. */

undefined4 FUN_c0945584(int param_1,uint param_2)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  
  uVar3 = param_2 & 0xf0000000;
  if (uVar3 == 0) {
    uVar1 = FUN_c09454b0(param_1,param_2);
  }
  else if (uVar3 == 0x10000000) {
    *(uint *)(param_1 + 0x684) = param_2 & 0xffffff;
    uVar1 = FUN_c0944ffc(param_1);
  }
  else if ((uVar3 == 0x20000000) || (uVar3 == 0x30000000)) {
    uVar4 = param_2 >> 0x10 & 0x7f;
    if ((uVar3 == 0x20000000) && (uVar4 != 0)) {
      uVar1 = FUN_c09453c4(param_1,param_2 & 0xffff,uVar4,0x10);
    }
    else {
      iVar2 = FUN_c09450a8(param_1,param_2 & 0xffff,0x10);
      if (iVar2 != 0) {
        FUN_c094596c(iVar2);
      }
      uVar1 = 0;
    }
  }
  else {
    uVar1 = 0x80004001;
  }
  return uVar1;
}



/* c094565c FUN_c094565c */

/* Boundary evidence: original MIPS .pdata c094565c..c0945773. Semantic name remains unreviewed. */

int FUN_c094565c(int *param_1)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  
  piVar2 = (int *)param_1[0x11];
  piVar3 = (int *)param_1[0x12];
  while( true ) {
    if (piVar3 <= piVar2) {
      piVar2 = (int *)FUN_c09439b0(param_1);
      if (piVar2 == (int *)0x0) {
        return 0;
      }
      piVar3 = (int *)param_1[0x12];
    }
    iVar1 = *piVar2;
    if ((uint)param_1[0x1a4] < (uint)(param_1[0x1a3] * iVar1)) break;
    FUN_c0945584((int)param_1,piVar2[1]);
    param_1[0x1a4] = 0;
    piVar2 = piVar2 + 2;
  }
  param_1[0x11] = (int)piVar2;
  return param_1[0x1a3] * iVar1 - param_1[0x1a4];
}



/* c0945774 FUN_c0945774 */

/* Boundary evidence: original MIPS .pdata c0945774..c094577f. Semantic name remains unreviewed. */

undefined4 FUN_c0945774(void)

{
  return 1;
}



/* c0945780 FUN_c0945780 */

/* Boundary evidence: original MIPS .pdata c0945780..c09458bf. Semantic name remains unreviewed. */

short * FUN_c0945780(int *param_1,short *param_2,short *param_3,short *param_4,int param_5)

{
  int *piVar1;
  bool bVar2;
  undefined3 extraout_var;
  int iVar3;
  short *psVar4;
  short *psVar5;
  int *piVar6;
  
  if ((param_1[4] != 0) &&
     ((bVar2 = FUN_c09435dc((int)param_1), CONCAT31(extraout_var,bVar2) != 0 ||
      ((int *)param_1[0x19b] != param_1 + 0x19b)))) {
    if (param_2 < param_3) {
      do {
        iVar3 = FUN_c094565c(param_1);
        if ((iVar3 == 0) || (psVar5 = param_2 + iVar3 * 2, param_3 < param_2 + iVar3 * 2)) {
          psVar5 = param_3;
        }
        param_1[0x1a4] = ((uint)((int)psVar5 - (int)param_2) >> 2) + param_1[0x1a4];
        piVar1 = (int *)param_1[0x19b];
        while (piVar1 != param_1 + 0x19b) {
          piVar6 = (int *)*piVar1;
          psVar4 = FUN_c0945b78(piVar1,param_2,psVar5,param_4,param_5);
          piVar1 = piVar6;
          if (param_4 < psVar4) {
            param_4 = psVar4;
          }
        }
        param_2 = psVar5;
      } while (psVar5 < param_3);
    }
    FUN_c094413c(param_4,(int)param_3);
    param_2 = param_3;
  }
  return param_2;
}



/* c09458c0 FUN_c09458c0 */

/* Boundary evidence: original MIPS .pdata c09458c0..c094591b. Semantic name remains unreviewed. */

void FUN_c09458c0(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  
  iVar2 = 0;
  puVar3 = (undefined4 *)(param_1 + 0x24);
  do {
    uVar1 = FUN_c0944ee0(*(int *)(param_1 + 8),*(uint *)(param_1 + 0x20),iVar2);
    iVar2 = iVar2 + 1;
    *puVar3 = uVar1;
    puVar3 = puVar3 + 1;
  } while (iVar2 < 2);
  return;
}



/* c094591c FUN_c094591c */

/* Boundary evidence: original MIPS .pdata c094591c..c094596b. Semantic name remains unreviewed. */

void FUN_c094591c(int param_1)

{
  uint uVar1;
  
  if (*(int *)(param_1 + 0x14) == 0x10) {
    uVar1 = FUN_c09452a4(*(int *)(param_1 + 8),*(uint *)(param_1 + 0xc));
  }
  else {
    uVar1 = FUN_c094524c(*(int *)(param_1 + 8),*(uint *)(param_1 + 0xc));
  }
  *(uint *)(param_1 + 0x1c) = uVar1;
  return;
}



/* c094596c FUN_c094596c */

undefined4 FUN_c094596c(int param_1)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = *(uint *)(param_1 + 0x1c);
  if (uVar1 == 0) {
    iVar2 = 0;
  }
  else {
    if (uVar1 == 0) {
      trap(0x1c00);
    }
    iVar2 = (-*(int *)(param_1 + 0x18) & 0x7fffffffU) / uVar1 + 1;
  }
  *(int *)(param_1 + 0x2c) = iVar2 << 2;
  return 0;
}



/* c09459b8 FUN_c09459b8 */

/* Boundary evidence: original MIPS .pdata c09459b8..c0945acb. Semantic name remains unreviewed. */

short * FUN_c09459b8(int param_1,short *param_2,short *param_3,short *param_4,int param_5)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  
  uVar7 = *(uint *)(param_1 + 0x18);
  iVar1 = *(int *)(param_1 + 0x1c);
  if (*(int *)(param_5 + 4) == 0) {
    iVar5 = *(int *)(param_1 + 0x24);
    iVar6 = *(int *)(param_1 + 0x28);
  }
  else {
    iVar5 = 0;
    iVar6 = 0;
  }
  for (; param_2 < param_3; param_2 = param_2 + 2) {
    uVar2 = uVar7 >> 0x18;
    uVar7 = iVar1 + uVar7;
    iVar4 = *(short *)(&DAT_c0941650 + uVar2 * 2) * iVar5 >> 0x10;
    iVar3 = *(short *)(&DAT_c0941650 + uVar2 * 2) * iVar6 >> 0x10;
    if (param_2 < param_4) {
      iVar4 = *param_2 + iVar4;
      iVar3 = param_2[1] + iVar3;
      if (iVar4 < 0x8000) {
        if (iVar4 < -0x8000) {
          iVar4 = -0x8000;
        }
      }
      else {
        iVar4 = 0x7fff;
      }
      if (iVar3 < 0x8000) {
        if (iVar3 < -0x8000) {
          iVar3 = -0x8000;
        }
      }
      else {
        iVar3 = 0x7fff;
      }
    }
    *param_2 = (short)iVar4;
    param_2[1] = (short)iVar3;
  }
  *(uint *)(param_1 + 0x18) = uVar7;
  return param_2;
}



/* c0945acc FUN_c0945acc */

undefined4 FUN_c0945acc(int param_1)

{
  return *(undefined4 *)(param_1 + 0xc);
}



/* c0945ad4 FUN_c0945ad4 */

undefined4 FUN_c0945ad4(int param_1)

{
  return *(undefined4 *)(param_1 + 0x14);
}



/* c0945adc FUN_c0945adc */

/* Boundary evidence: original MIPS .pdata c0945adc..c0945b0b. Semantic name remains unreviewed. */

void FUN_c0945adc(int param_1,int param_2)

{
  *(int *)(param_1 + 0x10) = param_2;
  *(undefined4 *)(param_1 + 0x2c) = 0xffffffff;
  *(int *)(param_1 + 0x20) = param_2 << 9;
  FUN_c09458c0(param_1);
  return;
}



/* c0945b0c FUN_c0945b0c */

/* Boundary evidence: original MIPS .pdata c0945b0c..c0945b77. Semantic name remains unreviewed. */

undefined4
FUN_c0945b0c(int param_1,undefined4 param_2,undefined4 param_3,int param_4,undefined4 param_5)

{
  *(undefined4 *)(param_1 + 8) = param_2;
  *(undefined4 *)(param_1 + 0xc) = param_3;
  *(undefined4 *)(param_1 + 0x14) = param_5;
  *(undefined4 *)(param_1 + 0x18) = 0;
  FUN_c094591c(param_1);
  *(int *)(param_1 + 0x10) = param_4;
  *(undefined4 *)(param_1 + 0x2c) = 0xffffffff;
  *(int *)(param_1 + 0x20) = param_4 << 9;
  FUN_c09458c0(param_1);
  return 0;
}



/* c0945b78 FUN_c0945b78 */

/* Boundary evidence: original MIPS .pdata c0945b78..c0945c1f. Semantic name remains unreviewed. */

short * FUN_c0945b78(int *param_1,short *param_2,short *param_3,short *param_4,int param_5)

{
  short *psVar1;
  uint uVar2;
  int iVar3;
  
  uVar2 = param_1[0xb];
  if (uVar2 == 0xffffffff) {
    psVar1 = FUN_c09459b8((int)param_1,param_2,param_3,param_4,param_5);
  }
  else {
    if ((uint)((int)param_3 - (int)param_2) < uVar2) {
      iVar3 = uVar2 - ((int)param_3 - (int)param_2);
    }
    else {
      param_3 = (short *)(uVar2 + (int)param_2);
      iVar3 = 0;
    }
    param_1[0xb] = iVar3;
    psVar1 = FUN_c09459b8((int)param_1,param_2,param_3,param_4,param_5);
    if (iVar3 == 0) {
      FUN_c09452d4((int *)param_1[2],param_1);
    }
  }
  return psVar1;
}



/* c0945c20 FUN_c0945c20 */

undefined4 * FUN_c0945c20(uint param_1)

{
  ushort *puVar1;
  int iVar2;
  
  iVar2 = 0;
  puVar1 = &DAT_c09418ec;
  do {
    if (*puVar1 == param_1) {
      return &DAT_c09418d8 + iVar2 * 9;
    }
    puVar1 = puVar1 + 0x12;
    iVar2 = iVar2 + 1;
  } while ((int)puVar1 < -0x3f6be6a8);
  return (undefined4 *)0x0;
}



/* c0945c74 FUN_c0945c74 */

void FUN_c0945c74(int param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 4) = param_2;
  return;
}



/* c0945c7c FUN_c0945c7c */

/* Boundary evidence: original MIPS .pdata c0945c7c..c0945ccb. Semantic name remains unreviewed. */

void FUN_c0945c7c(int *param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  *param_2 = 0xe4;
  param_2[1] = param_1[1];
  uVar1 = (**(code **)(*param_1 + 0x14))();
  param_2[2] = uVar1;
  return;
}



/* c0945ccc FUN_c0945ccc */

undefined4 FUN_c0945ccc(void)

{
  return 8;
}



/* c0945cd4 FUN_c0945cd4 */

/* Boundary evidence: original MIPS .pdata c0945cd4..c0945d17. Semantic name remains unreviewed. */

undefined4 * FUN_c0945cd4(undefined4 *param_1,uint param_2)

{
  *param_1 = &PTR_FUN_c0941944;
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}



/* c0945d18 FUN_c0945d18 */

/* Boundary evidence: original MIPS .pdata c0945d18..c0945d6f. Semantic name remains unreviewed. */

void FUN_c0945d18(int *param_1,undefined4 *param_2)

{
  FUN_c0945c7c(param_1,param_2);
  param_2[3] = 0;
  param_2[4] = 0;
  param_2[0x2d] = 0;
  param_2[0x2e] = 0xffff;
  param_2[0x33] = 1;
  return;
}



/* c0945d7c FUN_c0945d7c */

/* Boundary evidence: original MIPS .pdata c0945d7c..c0945e43. Semantic name remains unreviewed. */

undefined4 FUN_c0945d7c(int *param_1,int param_2)

{
  uint uVar1;
  undefined4 *puVar2;
  uint uVar3;
  uint uVar4;
  uint *puVar5;
  
  uVar1 = (**(code **)(*param_1 + 0x18))(param_1);
  puVar2 = FUN_c0945c20(uVar1);
  uVar3 = (**(code **)(*param_1 + 0x20))(param_1);
  puVar5 = *(uint **)(param_2 + 0x14);
  uVar4 = uVar3 & 0xffff;
  uVar1 = uVar4;
  if (*(char *)((int)puVar2 + 0x16) == '\x02') {
    uVar1 = uVar3 >> 0x10;
  }
  if (*(int *)(param_2 + 8) == 1) {
    *puVar5 = uVar1 + uVar4 >> 1;
  }
  else {
    *puVar5 = uVar4;
    puVar5[1] = uVar1;
  }
  return 0;
}



/* c0945e44 FUN_c0945e44 */

/* Boundary evidence: original MIPS .pdata c0945e44..c0945f1f. Semantic name remains unreviewed. */

undefined4 FUN_c0945e44(int *param_1,int param_2)

{
  uint uVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  uint uVar4;
  
  uVar1 = (**(code **)(*param_1 + 0x18))(param_1);
  puVar2 = FUN_c0945c20(uVar1);
  uVar4 = **(uint **)(param_2 + 0x14);
  uVar1 = uVar4;
  if (*(int *)(param_2 + 8) == 2) {
    uVar1 = (*(uint **)(param_2 + 0x14))[1];
  }
  if ((uVar4 < 0x10000) && (uVar1 < 0x10000)) {
    if (*(char *)((int)puVar2 + 0x16) == '\x01') {
      uVar4 = uVar1 + uVar4 >> 1;
    }
    else {
      uVar4 = uVar1 << 0x10 | uVar4;
    }
    (**(code **)(*param_1 + 0x1c))(param_1,uVar4);
    uVar3 = 0;
  }
  else {
    uVar3 = 0xb;
  }
  return uVar3;
}



/* c0945f20 FUN_c0945f20 */

/* Boundary evidence: original MIPS .pdata c0945f20..c0945f6f. Semantic name remains unreviewed. */

void FUN_c0945f20(int *param_1,undefined4 *param_2)

{
  FUN_c0945d18(param_1,param_2);
  wcscpy((wchar_t *)(param_2 + 0xd),L"Master Volume");
  wcscpy((wchar_t *)(param_2 + 5),L"Master Volume");
  return;
}



/* c0945f70 FUN_c0945f70 */

/* Boundary evidence: original MIPS .pdata c0945f70..c0945f8f. Semantic name remains unreviewed. */

void FUN_c0945f70(undefined4 param_1,undefined4 param_2)

{
  FUN_c0947684(DAT_c094a140,param_2);
  return;
}



/* c0945f90 FUN_c0945f90 */

/* Boundary evidence: original MIPS .pdata c0945f90..c0945faf. Semantic name remains unreviewed. */

void FUN_c0945f90(void)

{
  FUN_c09476e8(DAT_c094a140);
  return;
}



/* c0945fb0 FUN_c0945fb0 */

/* Boundary evidence: original MIPS .pdata c0945fb0..c0945fff. Semantic name remains unreviewed. */

void FUN_c0945fb0(int *param_1,undefined4 *param_2)

{
  FUN_c0945d18(param_1,param_2);
  wcscpy((wchar_t *)(param_2 + 0xd),L"Mic Volume");
  wcscpy((wchar_t *)(param_2 + 5),L"Mic Volume");
  return;
}



/* c0946008 FUN_c0946008 */

/* Boundary evidence: original MIPS .pdata c0946008..c0946027. Semantic name remains unreviewed. */

void FUN_c0946008(undefined4 param_1,undefined4 param_2)

{
  FUN_c094773c(DAT_c094a140,param_2);
  return;
}



/* c0946028 FUN_c0946028 */

/* Boundary evidence: original MIPS .pdata c0946028..c0946047. Semantic name remains unreviewed. */

void FUN_c0946028(void)

{
  FUN_c0947734(DAT_c094a140);
  return;
}



/* c0946048 FUN_c0946048 */

/* Boundary evidence: original MIPS .pdata c0946048..c094609b. Semantic name remains unreviewed. */

void FUN_c0946048(int *param_1,undefined4 *param_2)

{
  FUN_c0945c7c(param_1,param_2);
  param_2[3] = 1;
  param_2[4] = 0;
  param_2[0x2d] = 0;
  param_2[0x2e] = 1;
  param_2[0x33] = 0;
  return;
}



/* c09460a4 FUN_c09460a4 */

/* Boundary evidence: original MIPS .pdata c09460a4..c09460e7. Semantic name remains unreviewed. */

undefined4 FUN_c09460a4(int *param_1,int param_2)

{
  undefined4 uVar1;
  
  uVar1 = (**(code **)(*param_1 + 0x1c))();
  **(undefined4 **)(param_2 + 0x14) = uVar1;
  return 0;
}



/* c09460e8 FUN_c09460e8 */

/* Boundary evidence: original MIPS .pdata c09460e8..c094611f. Semantic name remains unreviewed. */

undefined4 FUN_c09460e8(int *param_1,int param_2)

{
  (**(code **)(*param_1 + 0x20))(param_1,**(undefined4 **)(param_2 + 0x14));
  return 0;
}



/* c0946120 FUN_c0946120 */

/* Boundary evidence: original MIPS .pdata c0946120..c094616f. Semantic name remains unreviewed. */

void FUN_c0946120(int *param_1,undefined4 *param_2)

{
  FUN_c0946048(param_1,param_2);
  wcscpy((wchar_t *)(param_2 + 0xd),L"Master Mute");
  wcscpy((wchar_t *)(param_2 + 5),L"Master Mute");
  return;
}



/* c0946184 FUN_c0946184 */

/* Boundary evidence: original MIPS .pdata c0946184..c09461a3. Semantic name remains unreviewed. */

void FUN_c0946184(void)

{
  FUN_c09476f0(DAT_c094a140);
  return;
}



/* c09461a4 FUN_c09461a4 */

/* Boundary evidence: original MIPS .pdata c09461a4..c09461c3. Semantic name remains unreviewed. */

void FUN_c09461a4(undefined4 param_1,int param_2)

{
  FUN_c09476b4(DAT_c094a140,param_2);
  return;
}



/* c09461c4 FUN_c09461c4 */

/* Boundary evidence: original MIPS .pdata c09461c4..c0946213. Semantic name remains unreviewed. */

void FUN_c09461c4(int *param_1,undefined4 *param_2)

{
  FUN_c0946048(param_1,param_2);
  wcscpy((wchar_t *)(param_2 + 0xd),L"Mic Mute");
  wcscpy((wchar_t *)(param_2 + 5),L"Mic Mute");
  return;
}



/* c0946214 FUN_c0946214 */

/* Boundary evidence: original MIPS .pdata c0946214..c0946233. Semantic name remains unreviewed. */

void FUN_c0946214(void)

{
  FUN_c09476f8(DAT_c094a140);
  return;
}



/* c0946234 FUN_c0946234 */

/* Boundary evidence: original MIPS .pdata c0946234..c0946253. Semantic name remains unreviewed. */

void FUN_c0946234(undefined4 param_1,int param_2)

{
  FUN_c0947700(DAT_c094a140,param_2);
  return;
}



/* c0946254 FUN_c0946254 */

/* Boundary evidence: original MIPS .pdata c0946254..c09462bf. Semantic name remains unreviewed. */

void FUN_c0946254(int *param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  FUN_c0945c7c(param_1,param_2);
  param_2[0x2e] = 1;
  param_2[0x2d] = 0;
  param_2[0x33] = 0;
  uVar1 = (**(code **)(*param_1 + 0x1c))(param_1);
  param_2[4] = uVar1;
  return;
}



/* c09462c0 FUN_c09462c0 */

/* Boundary evidence: original MIPS .pdata c09462c0..c09463ff. Semantic name remains unreviewed. */

undefined4 FUN_c09462c0(int *param_1,int param_2,int param_3)

{
  uint uVar1;
  undefined4 uVar2;
  uint uVar3;
  undefined4 *puVar4;
  
  uVar1 = (**(code **)(*param_1 + 0x1c))(param_1);
  if (*(uint *)(param_2 + 0xc) == uVar1) {
    if (param_3 == 0) {
      if (*(int *)(param_2 + 0x10) != 4) goto LAB_c094630c;
      uVar3 = 0;
      puVar4 = *(undefined4 **)(param_2 + 0x14);
      if (uVar1 != 0) {
        do {
          uVar2 = (**(code **)(*param_1 + 0x24))(param_1,uVar3);
          uVar3 = uVar3 + 1;
          *puVar4 = uVar2;
          puVar4 = puVar4 + 1;
        } while (uVar3 < uVar1);
      }
    }
    else if (param_3 == 1) {
      if (*(int *)(param_2 + 0x10) != 0x88) goto LAB_c094630c;
      uVar2 = *(undefined4 *)(param_2 + 0x14);
      uVar3 = 0;
      if (uVar1 != 0) {
        do {
          (**(code **)(*param_1 + 0x20))(param_1,uVar2,uVar3);
          uVar3 = uVar3 + 1;
        } while (uVar3 < uVar1);
      }
    }
    uVar2 = 0;
  }
  else {
LAB_c094630c:
    uVar2 = 0xb;
  }
  return uVar2;
}



/* c0946400 FUN_c0946400 */

/* Boundary evidence: original MIPS .pdata c0946400..c09464d7. Semantic name remains unreviewed. */

undefined4 FUN_c0946400(int *param_1,int param_2,int param_3)

{
  uint uVar1;
  undefined4 uVar2;
  uint uVar3;
  undefined4 *puVar4;
  
  uVar1 = (**(code **)(*param_1 + 0x1c))(param_1);
  if (*(uint *)(param_2 + 0xc) == uVar1) {
    if (param_3 == 0) {
      if (*(int *)(param_2 + 0x10) != 4) goto LAB_c094644c;
      puVar4 = *(undefined4 **)(param_2 + 0x14);
      uVar3 = 0;
      if (uVar1 != 0) {
        do {
          (**(code **)(*param_1 + 0x28))(param_1,uVar3,*puVar4);
          uVar3 = uVar3 + 1;
          puVar4 = puVar4 + 1;
        } while (uVar3 < uVar1);
      }
    }
    uVar2 = 0;
  }
  else {
LAB_c094644c:
    uVar2 = 0xb;
  }
  return uVar2;
}



/* c09464d8 FUN_c09464d8 */

/* Boundary evidence: original MIPS .pdata c09464d8..c0946533. Semantic name remains unreviewed. */

void FUN_c09464d8(int *param_1,undefined4 *param_2)

{
  FUN_c0946254(param_1,param_2);
  wcscpy((wchar_t *)(param_2 + 0xd),L"Eq Preset");
  wcscpy((wchar_t *)(param_2 + 5),L"Eq Preset");
  param_2[3] = 3;
  return;
}



/* c0946540 FUN_c0946540 */

/* Boundary evidence: original MIPS .pdata c0946540..c0946593. Semantic name remains unreviewed. */

void FUN_c0946540(undefined4 param_1,int param_2,int param_3)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)(param_3 * 0x88 + param_2);
  *puVar1 = 0;
  puVar1[1] = 0;
  wcscpy((wchar_t *)(puVar1 + 2),(wchar_t *)(&PTR_u_Rock_c094a0e4)[param_3]);
  return;
}



/* c0946594 FUN_c0946594 */

/* Boundary evidence: original MIPS .pdata c0946594..c09465ef. Semantic name remains unreviewed. */

void FUN_c0946594(int *param_1,undefined4 *param_2)

{
  FUN_c0946254(param_1,param_2);
  wcscpy((wchar_t *)(param_2 + 0xd),L"Input Mux");
  wcscpy((wchar_t *)(param_2 + 5),L"Input Mux");
  param_2[3] = 3;
  return;
}



/* c094660c FUN_c094660c */

/* Boundary evidence: original MIPS .pdata c094660c..c09466a7. Semantic name remains unreviewed. */

void FUN_c094660c(int *param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  uint uVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  
  puVar4 = (undefined4 *)(param_3 * 0x88 + param_2);
  uVar1 = (**(code **)(*param_1 + 0x18))(param_1);
  *puVar4 = uVar1;
  uVar2 = (**(code **)(*param_1 + 0x18))(param_1);
  puVar3 = FUN_c0945c20(uVar2);
  puVar4[1] = *puVar3;
  wcscpy((wchar_t *)(puVar4 + 2),(wchar_t *)(&PTR_u_Microphone_c094a0f0)[param_3]);
  return;
}



/* c09466d4 FUN_c09466d4 */

/* Boundary evidence: original MIPS .pdata c09466d4..c0946723. Semantic name remains unreviewed. */

void FUN_c09466d4(int *param_1,undefined4 *param_2)

{
  FUN_c0946048(param_1,param_2);
  wcscpy((wchar_t *)(param_2 + 0xd),L"S/PDIF");
  wcscpy((wchar_t *)(param_2 + 5),L"S/PDIF");
  return;
}



/* c0946740 FUN_c0946740 */

/* Boundary evidence: original MIPS .pdata c0946740..c094677b. Semantic name remains unreviewed. */

void FUN_c0946740(undefined4 param_1,int param_2)

{
  undefined4 *puVar1;
  
  puVar1 = DAT_c094a140;
  if (param_2 != DAT_c094a140[0x24]) {
    DAT_c094a140[0x24] = param_2;
    FUN_c09478a0(puVar1,L"EnableSpdif",param_2);
  }
  return;
}



/* c094677c FUN_c094677c */

/* Boundary evidence: original MIPS .pdata c094677c..c09467cb. Semantic name remains unreviewed. */

void FUN_c094677c(int *param_1,undefined4 *param_2)

{
  FUN_c0946048(param_1,param_2);
  wcscpy((wchar_t *)(param_2 + 0xd),L"WmaPro S/PDIF");
  wcscpy((wchar_t *)(param_2 + 5),L"WmaPro S/PDIF");
  return;
}



/* c09467dc FUN_c09467dc */

/* Boundary evidence: original MIPS .pdata c09467dc..c094680b. Semantic name remains unreviewed. */

void FUN_c09467dc(undefined4 param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  
  puVar1 = DAT_c094a140;
  DAT_c094a140[0x25] = param_2;
  FUN_c09478a0(puVar1,L"EnableSpdifWmaPro",param_2);
  return;
}



/* c094680c FUN_c094680c */

/* Boundary evidence: original MIPS .pdata c094680c..c0946943. Semantic name remains unreviewed. */

undefined4 * FUN_c094680c(undefined4 *param_1)

{
  uint uVar1;
  undefined4 *puVar2;
  
  *param_1 = &PTR_FUN_c0941bcc;
  param_1[1] = &PTR_FUN_c0941960;
  param_1[2] = 0xffffffff;
  param_1[3] = &PTR_FUN_c09419dc;
  param_1[4] = 0xffffffff;
  param_1[5] = &PTR_FUN_c0941b1c;
  param_1[6] = 0xffffffff;
  param_1[7] = &PTR_FUN_c0941b68;
  param_1[8] = 0xffffffff;
  param_1[9] = &PTR_FUN_c0941a50;
  param_1[10] = 0xffffffff;
  param_1[0xb] = 0;
  param_1[0xc] = &PTR_FUN_c09419a0;
  param_1[0xd] = 0xffffffff;
  param_1[0xf] = 0xffffffff;
  param_1[0xe] = &PTR_FUN_c0941a18;
  puVar2 = param_1 + 0x13;
  param_1[0x11] = 0xffffffff;
  param_1[0x10] = &PTR_FUN_c0941abc;
  uVar1 = 0;
  *puVar2 = param_1 + 1;
  param_1[0x14] = param_1 + 3;
  param_1[0x15] = param_1 + 5;
  param_1[0x16] = param_1 + 7;
  param_1[0x17] = param_1 + 9;
  param_1[0x18] = param_1 + 0xc;
  param_1[0x19] = param_1 + 0xe;
  param_1[0x1a] = param_1 + 0x10;
  do {
    (**(code **)(*(int *)*puVar2 + 4))((int *)*puVar2,uVar1);
    uVar1 = uVar1 + 1;
    puVar2 = puVar2 + 1;
  } while (uVar1 < 8);
  return param_1;
}



/* c0946944 FUN_c0946944 */

/* Boundary evidence: original MIPS .pdata c0946944..c09469ab. Semantic name remains unreviewed. */

undefined4 * FUN_c0946944(undefined4 *param_1,uint param_2)

{
  *param_1 = &PTR_FUN_c0941bcc;
  param_1[0x10] = &PTR_FUN_c0941944;
  param_1[0xe] = &PTR_FUN_c0941944;
  param_1[0xc] = &PTR_FUN_c0941944;
  param_1[9] = &PTR_FUN_c0941944;
  param_1[7] = &PTR_FUN_c0941944;
  param_1[5] = &PTR_FUN_c0941944;
  param_1[3] = &PTR_FUN_c0941944;
  param_1[1] = &PTR_FUN_c0941944;
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}



/* c09469ac FUN_c09469ac */

/* Boundary evidence: original MIPS .pdata c09469ac..c0946a1b. Semantic name remains unreviewed. */

void FUN_c09469ac(undefined4 param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  
  for (puVar1 = DAT_c094a138; puVar1 != (undefined4 *)0x0; puVar1 = (undefined4 *)puVar1[2]) {
    if ((code *)puVar1[1] != (code *)0x0) {
      (*(code *)puVar1[1])(*puVar1,param_1,0,param_2,0);
    }
  }
  return;
}



/* c0946a1c FUN_c0946a1c */

/* Boundary evidence: original MIPS .pdata c0946a1c..c0946a8f. Semantic name remains unreviewed. */

undefined4 FUN_c0946a1c(undefined1 *param_1)

{
  *param_1 = 1;
  param_1[2] = 0x11;
  param_1[1] = 0;
  param_1[3] = 0;
  wcscpy((wchar_t *)(param_1 + 8),L"Audio Mixer");
  *(undefined4 *)(param_1 + 4) = 0x100;
  *(undefined4 *)(param_1 + 0x4c) = 2;
  *(undefined4 *)(param_1 + 0x48) = 0;
  return 0;
}



/* c0946a90 FUN_c0946a90 */

/* Boundary evidence: original MIPS .pdata c0946a90..c0946b3b. Semantic name remains unreviewed. */

undefined4 FUN_c0946a90(undefined4 *param_1,undefined4 *param_2,uint param_3)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  puVar1 = LocalAlloc(0,0xc);
  if (puVar1 == (undefined4 *)0x0) {
    NKDbgPrintfW(L"[ERROR] \"wdev_MXDM_OPEN: out of memory\"\r\n");
    uVar2 = 7;
  }
  else {
    *puVar1 = *param_2;
    if ((param_3 & 0x30000) == 0) {
      puVar1[1] = 0;
    }
    else {
      puVar1[1] = param_2[2];
    }
    puVar1[2] = DAT_c094a138;
    DAT_c094a138 = puVar1;
    *param_1 = puVar1;
    uVar2 = 0;
  }
  return uVar2;
}



/* c0946b3c FUN_c0946b3c */

/* Boundary evidence: original MIPS .pdata c0946b3c..c0946ba3. Semantic name remains unreviewed. */

undefined4 FUN_c0946b3c(HLOCAL param_1)

{
  HLOCAL pvVar1;
  HLOCAL hMem;
  HLOCAL pvVar2;
  
  pvVar1 = (HLOCAL)0x0;
  hMem = DAT_c094a138;
  while( true ) {
    if (hMem == (HLOCAL)0x0) {
      return 0;
    }
    if (hMem == param_1) break;
    pvVar1 = hMem;
    hMem = *(HLOCAL *)((int)hMem + 8);
  }
  pvVar2 = *(HLOCAL *)((int)hMem + 8);
  if (pvVar1 != (HLOCAL)0x0) {
    *(HLOCAL *)((int)pvVar1 + 8) = *(HLOCAL *)((int)hMem + 8);
    pvVar2 = DAT_c094a138;
  }
  DAT_c094a138 = pvVar2;
  LocalFree(hMem);
  return 0;
}



/* c0946ba4 FUN_c0946ba4 */

/* Boundary evidence: original MIPS .pdata c0946ba4..c0946e8b. Semantic name remains unreviewed. */

undefined4 FUN_c0946ba4(int param_1,uint param_2)

{
  undefined4 *puVar1;
  uint uVar2;
  ushort *puVar3;
  int *piVar4;
  int iVar5;
  uint uVar6;
  
  uVar2 = 0xff;
  uVar6 = param_2 & 0xf;
  if (uVar6 == 0) {
    if (1 < *(uint *)(param_1 + 4)) {
      return 0x400;
    }
    puVar3 = (ushort *)(&DAT_c09418d0 + *(uint *)(param_1 + 4) * 2);
  }
  else {
    if (uVar6 != 1) {
      if (uVar6 == 2) {
        uVar2 = *(uint *)(param_1 + 0xc) & 0xffff;
      }
      else if ((uVar6 != 3) && (uVar6 != 4)) {
        return 0xb;
      }
      goto LAB_c0946cb8;
    }
    if (1 < *(uint *)(param_1 + 4)) {
      return 0x400;
    }
    puVar1 = FUN_c0945c20((uint)*(ushort *)(&DAT_c09418d0 + *(uint *)(param_1 + 4) * 2));
    if (puVar1 == (undefined4 *)0x0) {
      return 1;
    }
    if ((uint)*(byte *)((int)puVar1 + 0x17) <= *(uint *)(param_1 + 8)) {
      return 0x400;
    }
    puVar3 = (ushort *)(*(uint *)(param_1 + 8) * 2 + puVar1[4]);
  }
  uVar2 = (uint)*puVar3;
LAB_c0946cb8:
  if (uVar6 < 3) {
    puVar1 = FUN_c0945c20(uVar2);
    if (puVar1 == (undefined4 *)0x0) {
      return 1;
    }
  }
  else {
    if (uVar6 == 3) {
      iVar5 = 0;
      piVar4 = &DAT_c09418d8;
      while (*piVar4 != *(int *)(param_1 + 0x18)) {
        piVar4 = piVar4 + 9;
        iVar5 = iVar5 + 1;
        if (-0x3f6be6bd < (int)piVar4) {
          return 0x400;
        }
      }
    }
    else {
      if (uVar6 != 4) {
        return 0x400;
      }
      iVar5 = 0;
      piVar4 = &DAT_c09418f4;
      while (*piVar4 != *(int *)(param_1 + 200)) {
        piVar4 = piVar4 + 9;
        iVar5 = iVar5 + 1;
        if (-0x3f6be6a1 < (int)piVar4) {
          return 0x400;
        }
      }
    }
    puVar1 = &DAT_c09418d8 + iVar5 * 9;
    if (puVar1 == (undefined4 *)0x0) {
      return 0x400;
    }
  }
  *(uint *)(param_1 + 0x1c) = (uint)*(byte *)((int)puVar1 + 0x16);
  *(uint *)(param_1 + 0x20) = (uint)*(byte *)((int)puVar1 + 0x17);
  *(uint *)(param_1 + 0x24) = (uint)*(byte *)(puVar1 + 6);
  *(undefined4 *)(param_1 + 0x18) = *puVar1;
  *(uint *)(param_1 + 0xc) = (uint)*(ushort *)(puVar1 + 5);
  *(uint *)(param_1 + 4) = (uint)*(byte *)(puVar1 + 8);
  *(uint *)(param_1 + 8) = (uint)*(byte *)((int)puVar1 + 0x21);
  *(undefined4 *)(param_1 + 0x10) = puVar1[3];
  *(undefined4 *)(param_1 + 0xcc) = 0;
  *(undefined4 *)(param_1 + 200) = puVar1[7];
  *(undefined1 *)(param_1 + 0xd2) = 0x11;
  *(undefined4 *)(param_1 + 0xd4) = 0x100;
  *(undefined1 *)(param_1 + 0xd0) = 1;
  *(undefined1 *)(param_1 + 0xd1) = 0;
  *(undefined1 *)(param_1 + 0xd3) = 0;
  wcscpy((wchar_t *)(param_1 + 0x48),(wchar_t *)puVar1[2]);
  wcscpy((wchar_t *)(param_1 + 0x28),(wchar_t *)puVar1[1]);
  wcscpy((wchar_t *)(param_1 + 0xd8),L"Audio Mixer");
  return 0;
}



/* c0946e8c FUN_c0946e8c */

/* Boundary evidence: original MIPS .pdata c0946e8c..c09470c7. Semantic name remains unreviewed. */

undefined4 FUN_c0946e8c(int param_1,uint param_2)

{
  int iVar1;
  undefined4 *puVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int *piVar6;
  uint uVar7;
  int iVar8;
  
  iVar8 = *(int *)(param_1 + 0x14);
  uVar5 = *(uint *)(param_1 + 0xc);
  uVar4 = param_2 & 0xf;
  uVar7 = *(uint *)(param_1 + 4) & 0xffff;
  if (uVar4 == 0) {
    puVar2 = FUN_c0945c20(uVar7);
    if (puVar2 == (undefined4 *)0x0) {
      return 0x400;
    }
    if (*(byte *)(puVar2 + 6) != uVar5) {
      return 0xb;
    }
    if (uVar5 != 0) {
      uVar4 = 0x4c;
      do {
        if (0x6b < uVar4) {
          return 0xb;
        }
        piVar6 = *(int **)(uVar4 + DAT_c094a13c);
        if (piVar6 == (int *)0x0) {
          return 0xb;
        }
        uVar3 = (**(code **)(*piVar6 + 0x18))(piVar6);
        if (uVar3 == uVar7) {
          (**(code **)(*piVar6 + 8))(piVar6,iVar8);
          iVar8 = iVar8 + 0xe4;
          uVar5 = uVar5 - 1;
        }
        uVar4 = uVar4 + 4;
      } while (uVar5 != 0);
    }
  }
  else if (uVar4 == 1) {
    if (uVar5 == 0) {
      return 0xb;
    }
    if ((7 < *(uint *)(param_1 + 8)) ||
       (piVar6 = *(int **)((*(uint *)(param_1 + 8) + 0x13) * 4 + DAT_c094a13c), piVar6 == (int *)0x0
       )) {
      return 0x401;
    }
    (**(code **)(*piVar6 + 8))(piVar6,iVar8);
    uVar4 = (**(code **)(*piVar6 + 0x18))(piVar6);
    *(uint *)(param_1 + 4) = uVar4;
  }
  else if (uVar4 == 2) {
    if (uVar5 != 0) {
      for (uVar4 = 0x4c;
          (uVar4 < 0x6c && (piVar6 = *(int **)(uVar4 + DAT_c094a13c), piVar6 != (int *)0x0));
          uVar4 = uVar4 + 4) {
        uVar5 = (**(code **)(*piVar6 + 0x18))(piVar6);
        if ((uVar5 == uVar7) &&
           (iVar1 = (**(code **)(*piVar6 + 0x14))(piVar6), iVar1 == *(int *)(param_1 + 8))) {
          (**(code **)(*piVar6 + 8))(piVar6,iVar8);
          return 0;
        }
      }
    }
    return 0xb;
  }
  return 0;
}



/* c09470c8 FUN_c09470c8 */

/* Boundary evidence: original MIPS .pdata c09470c8..c0947137. Semantic name remains unreviewed. */

undefined4 FUN_c09470c8(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int *piVar2;
  
  if ((*(uint *)(param_1 + 4) < 8) &&
     (piVar2 = *(int **)((*(uint *)(param_1 + 4) + 0x13) * 4 + DAT_c094a13c), piVar2 != (int *)0x0))
  {
    uVar1 = (**(code **)(*piVar2 + 0xc))(piVar2,param_1,param_2);
  }
  else {
    uVar1 = 0x401;
  }
  return uVar1;
}



/* c0947138 FUN_c0947138 */

/* Boundary evidence: original MIPS .pdata c0947138..c09471bf. Semantic name remains unreviewed. */

undefined4 FUN_c0947138(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  uint uVar2;
  int *piVar3;
  
  uVar2 = *(uint *)(param_1 + 4);
  if ((uVar2 < 8) && (piVar3 = *(int **)((uVar2 + 0x13) * 4 + DAT_c094a13c), piVar3 != (int *)0x0))
  {
    (**(code **)(*piVar3 + 0x10))(piVar3,param_1,param_2);
    FUN_c09469ac(0x3d1,*(uint *)(param_1 + 4));
    uVar1 = 0;
  }
  else {
    uVar1 = 0x401;
  }
  return uVar1;
}



/* c09471c0 FUN_c09471c0 */

/* Boundary evidence: original MIPS .pdata c09471c0..c0947207. Semantic name remains unreviewed. */

undefined4 FUN_c09471c0(void)

{
  undefined4 *puVar1;
  
  puVar1 = operator_new(0x6c);
  if (puVar1 == (undefined4 *)0x0) {
    DAT_c094a13c = (undefined4 *)0x0;
  }
  else {
    DAT_c094a13c = FUN_c094680c(puVar1);
  }
  return 1;
}



/* c0947208 FUN_c0947208 */

/* Boundary evidence: original MIPS .pdata c0947208..c0947383. Semantic name remains unreviewed. */

undefined4 FUN_c0947208(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  switch(*(undefined4 *)(param_1 + 4)) {
  case 1:
    uVar1 = 1;
    break;
  case 2:
    uVar1 = FUN_c0946a1c(*(undefined1 **)(param_1 + 0xc));
    break;
  case 3:
    uVar1 = FUN_c0946a90(*(undefined4 **)(param_1 + 8),*(undefined4 **)(param_1 + 0xc),
                         *(uint *)(param_1 + 0x10));
    break;
  case 4:
    uVar1 = FUN_c0946b3c(*(HLOCAL *)(param_1 + 8));
    break;
  case 5:
    uVar1 = FUN_c0946ba4(*(int *)(param_1 + 0xc),*(uint *)(param_1 + 0x10));
    break;
  case 6:
    uVar1 = FUN_c0946e8c(*(int *)(param_1 + 0xc),*(uint *)(param_1 + 0x10));
    break;
  case 7:
    uVar1 = FUN_c09470c8(*(int *)(param_1 + 0xc),*(undefined4 *)(param_1 + 0x10));
    break;
  case 8:
    uVar1 = FUN_c0947138(*(int *)(param_1 + 0xc),*(undefined4 *)(param_1 + 0x10));
    break;
  default:
    NKDbgPrintfW(L"[ERROR] \"Unsupported mixer message\"\r\n");
    uVar1 = 8;
  }
  *param_2 = uVar1;
  return 1;
}



/* c0947384 FUN_c0947384 */

/* Boundary evidence: original MIPS .pdata c0947384..c094738f. Semantic name remains unreviewed. */

undefined4 FUN_c0947384(void)

{
  return 1;
}



/* c0947390 FUN_c0947390 */

/* Boundary evidence: original MIPS .pdata c0947390..c09473df. Semantic name remains unreviewed. */

undefined4 FUN_c0947390(undefined4 param_1)

{
  (**(code **)(*(int *)(DAT_c094a13c + 4) + 0x1c))((int *)(DAT_c094a13c + 4),param_1);
  FUN_c09469ac(0x3d1,*(undefined4 *)(DAT_c094a13c + 8));
  return 0;
}



/* c09473e0 FUN_c09473e0 */

/* Boundary evidence: original MIPS .pdata c09473e0..c094740f. Semantic name remains unreviewed. */

void FUN_c09473e0(void)

{
  (**(code **)(*(int *)(DAT_c094a13c + 4) + 0x20))();
  return;
}



/* c0947410 FUN_c0947410 */

/* Boundary evidence: original MIPS .pdata c0947410..c0947453. Semantic name remains unreviewed. */

undefined4 * FUN_c0947410(undefined4 *param_1,uint param_2)

{
  *param_1 = &PTR_FUN_c0941944;
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}



/* c0947454 FUN_c0947454 */

/* Boundary evidence: original MIPS .pdata c0947454..c0947497. Semantic name remains unreviewed. */

undefined4 * FUN_c0947454(undefined4 *param_1,uint param_2)

{
  *param_1 = &PTR_FUN_c0941944;
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}



/* c0947498 FUN_c0947498 */

/* Boundary evidence: original MIPS .pdata c0947498..c09474db. Semantic name remains unreviewed. */

undefined4 * FUN_c0947498(undefined4 *param_1,uint param_2)

{
  *param_1 = &PTR_FUN_c0941944;
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}



/* c09474dc FUN_c09474dc */

/* Boundary evidence: original MIPS .pdata c09474dc..c094751f. Semantic name remains unreviewed. */

undefined4 * FUN_c09474dc(undefined4 *param_1,uint param_2)

{
  *param_1 = &PTR_FUN_c0941944;
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}



/* c0947520 FUN_c0947520 */

/* Boundary evidence: original MIPS .pdata c0947520..c0947563. Semantic name remains unreviewed. */

undefined4 * FUN_c0947520(undefined4 *param_1,uint param_2)

{
  *param_1 = &PTR_FUN_c0941944;
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}



/* c0947564 FUN_c0947564 */

/* Boundary evidence: original MIPS .pdata c0947564..c09475a7. Semantic name remains unreviewed. */

undefined4 * FUN_c0947564(undefined4 *param_1,uint param_2)

{
  *param_1 = &PTR_FUN_c0941944;
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}



/* c09475a8 FUN_c09475a8 */

/* Boundary evidence: original MIPS .pdata c09475a8..c09475eb. Semantic name remains unreviewed. */

undefined4 * FUN_c09475a8(undefined4 *param_1,uint param_2)

{
  *param_1 = &PTR_FUN_c0941944;
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}



/* c09475ec FUN_c09475ec */

/* Boundary evidence: original MIPS .pdata c09475ec..c094762f. Semantic name remains unreviewed. */

undefined4 * FUN_c09475ec(undefined4 *param_1,uint param_2)

{
  *param_1 = &PTR_FUN_c0941944;
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}



/* c0947630 FUN_c0947630 */

/* Boundary evidence: original MIPS .pdata c0947630..c0947683. Semantic name remains unreviewed. */

bool FUN_c0947630(int param_1)

{
  int iVar1;
  
  if (*(int *)(param_1 + 0xb0) != 0) {
    FreeIntChainHandler();
    *(undefined4 *)(param_1 + 0xb0) = 0;
  }
  iVar1 = FUN_c09481a4();
  return iVar1 != 0;
}



/* c0947684 FUN_c0947684 */

/* Boundary evidence: original MIPS .pdata c0947684..c09476b3. Semantic name remains unreviewed. */

undefined4 FUN_c0947684(int param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 0x9c) = param_2;
  if (*(int *)(param_1 + 0xa8) != 0) {
    param_2 = 0;
  }
  FUN_c0943060(param_1 + 0x50,param_2);
  return 0;
}



/* c09476b4 FUN_c09476b4 */

/* Boundary evidence: original MIPS .pdata c09476b4..c09476e7. Semantic name remains unreviewed. */

undefined4 FUN_c09476b4(int param_1,int param_2)

{
  undefined4 uVar1;
  
  *(int *)(param_1 + 0xa8) = param_2;
  if (param_2 == 0) {
    uVar1 = *(undefined4 *)(param_1 + 0x9c);
  }
  else {
    uVar1 = 0;
  }
  FUN_c0943060(param_1 + 0x50,uVar1);
  return 0;
}



/* c09476e8 FUN_c09476e8 */

undefined4 FUN_c09476e8(int param_1)

{
  return *(undefined4 *)(param_1 + 0x9c);
}



/* c09476f0 FUN_c09476f0 */

undefined4 FUN_c09476f0(int param_1)

{
  return *(undefined4 *)(param_1 + 0xa8);
}



/* c09476f8 FUN_c09476f8 */

undefined4 FUN_c09476f8(int param_1)

{
  return *(undefined4 *)(param_1 + 0xa4);
}



/* c0947700 FUN_c0947700 */

/* Boundary evidence: original MIPS .pdata c0947700..c0947733. Semantic name remains unreviewed. */

undefined4 FUN_c0947700(int param_1,int param_2)

{
  undefined4 uVar1;
  
  *(int *)(param_1 + 0xa4) = param_2;
  if (param_2 == 0) {
    uVar1 = *(undefined4 *)(param_1 + 0xa0);
  }
  else {
    uVar1 = 0;
  }
  FUN_c0943060(param_1 + 0x20,uVar1);
  return 0;
}



/* c0947734 FUN_c0947734 */

undefined4 FUN_c0947734(int param_1)

{
  return *(undefined4 *)(param_1 + 0xa0);
}



/* c094773c FUN_c094773c */

/* Boundary evidence: original MIPS .pdata c094773c..c094776b. Semantic name remains unreviewed. */

undefined4 FUN_c094773c(int param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 0xa0) = param_2;
  if (*(int *)(param_1 + 0xa4) != 0) {
    param_2 = 0;
  }
  FUN_c0943060(param_1 + 0x20,param_2);
  return 0;
}



/* c094776c FUN_c094776c */

/* Boundary evidence: original MIPS .pdata c094776c..c09477a7. Semantic name remains unreviewed. */

void FUN_c094776c(int param_1)

{
  if (*(int *)(param_1 + 0x84) != 0) {
    FUN_c09484c4(param_1 + 200,2);
    *(undefined4 *)(param_1 + 0x84) = 0;
  }
  return;
}



/* c09477a8 FUN_c09477a8 */

/* Boundary evidence: original MIPS .pdata c09477a8..c09477db. Semantic name remains unreviewed. */

undefined4 FUN_c09477a8(int param_1)

{
  if (*(int *)(param_1 + 0x80) == 0) {
    *(undefined4 *)(param_1 + 0x80) = 1;
    FUN_c0948440(param_1 + 200,1);
  }
  return 1;
}



/* c09477dc FUN_c09477dc */

/* Boundary evidence: original MIPS .pdata c09477dc..c0947817. Semantic name remains unreviewed. */

void FUN_c09477dc(int param_1)

{
  if (*(int *)(param_1 + 0x80) != 0) {
    FUN_c09484c4(param_1 + 200,1);
    *(undefined4 *)(param_1 + 0x80) = 0;
  }
  return;
}



/* c0947818 FUN_c0947818 */

/* Boundary evidence: original MIPS .pdata c0947818..c094789f. Semantic name remains unreviewed. */

undefined4 FUN_c0947818(undefined4 *param_1,LPCWSTR param_2,undefined4 param_3)

{
  HKEY hKey;
  undefined4 local_res8 [2];
  DWORD local_18 [2];
  
  local_res8[0] = param_3;
  hKey = (HKEY)OpenDeviceKey(*param_1);
  if (hKey != (HKEY)0x0) {
    local_18[0] = 4;
    RegQueryValueExW(hKey,param_2,(LPDWORD)0x0,(LPDWORD)0x0,(LPBYTE)local_res8,local_18);
    RegCloseKey(hKey);
  }
  return local_res8[0];
}



/* c09478a0 FUN_c09478a0 */

/* Boundary evidence: original MIPS .pdata c09478a0..c094791b. Semantic name remains unreviewed. */

void FUN_c09478a0(undefined4 *param_1,LPCWSTR param_2,undefined4 param_3)

{
  HKEY hKey;
  undefined4 local_res8 [2];
  
  local_res8[0] = param_3;
  hKey = (HKEY)OpenDeviceKey(*param_1);
  if (hKey != (HKEY)0x0) {
    RegSetValueExW(hKey,param_2,0,4,(BYTE *)local_res8,4);
    RegCloseKey(hKey);
  }
  return;
}



/* c094791c FUN_c094791c */

/* Boundary evidence: original MIPS .pdata c094791c..c09479ab. Semantic name remains unreviewed. */

int FUN_c094791c(int param_1)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int local_20;
  undefined1 auStack_1c [12];
  
  uVar1 = FUN_c0948554(param_1 + 200,2);
  local_20 = 0;
  memset(auStack_1c,0,8);
  uVar2 = FUN_c0942ae0(param_1 + 0x50,uVar1,uVar1 + 0x1000,&local_20);
  iVar3 = uVar2 - uVar1;
  if (iVar3 != 0) {
    FUN_c09485a0(param_1 + 200,2,uVar1,iVar3);
  }
  return iVar3;
}



/* c09479ac FUN_c09479ac */

/* Boundary evidence: original MIPS .pdata c09479ac..c0947a27. Semantic name remains unreviewed. */

int FUN_c09479ac(int param_1)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  
  uVar1 = FUN_c0948554(param_1 + 200,1);
  uVar2 = FUN_c0942ae0(param_1 + 0x20,uVar1,uVar1 + 0x1000,(int *)0x0);
  iVar3 = uVar2 - uVar1;
  if (iVar3 != 0) {
    FUN_c09485a0(param_1 + 200,1,uVar1,iVar3);
  }
  return iVar3;
}



/* c0947a28 FUN_c0947a28 */

/* Boundary evidence: original MIPS .pdata c0947a28..c0947aff. Semantic name remains unreviewed. */

void FUN_c0947a28(int param_1)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = param_1 + 200;
  do {
    InterruptDone(*(undefined4 *)(param_1 + 0xac));
    WaitForSingleObject(*(HANDLE *)(param_1 + 0xb4),0xffffffff);
    EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 4));
    bVar1 = FUN_c09485f0(iVar3);
    if ((((bVar1 & 2) != 0) && (iVar2 = FUN_c094791c(param_1), iVar2 == 0)) &&
       (*(int *)(param_1 + 0x84) != 0)) {
      FUN_c09484c4(iVar3,2);
      *(undefined4 *)(param_1 + 0x84) = 0;
    }
    if ((((bVar1 & 1) != 0) && (iVar2 = FUN_c09479ac(param_1), iVar2 == 0)) &&
       (*(int *)(param_1 + 0x80) != 0)) {
      FUN_c09484c4(iVar3,1);
      *(undefined4 *)(param_1 + 0x80) = 0;
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 4));
  } while( true );
}



/* c0947b00 FUN_c0947b00 */

/* Boundary evidence: original MIPS .pdata c0947b00..c0947b1b. Semantic name remains unreviewed. */

void FUN_c0947b00(int param_1)

{
  FUN_c0947a28(param_1);
  return;
}



/* c0947b1c FUN_c0947b1c */

undefined4 FUN_c0947b1c(int param_1,int param_2)

{
  if (param_2 == 0) {
    *(int *)(param_1 + 0x88) = *(int *)(param_1 + 0x88) + -1;
  }
  else {
    *(int *)(param_1 + 0x88) = *(int *)(param_1 + 0x88) + 1;
  }
  return 0;
}



/* c0947b48 FUN_c0947b48 */

/* Boundary evidence: original MIPS .pdata c0947b48..c0947cdb. Semantic name remains unreviewed. */

undefined4
FUN_c0947b48(int param_1,int param_2,undefined4 param_3,undefined4 param_4,int *param_5,uint param_6
            ,undefined4 *param_7)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (param_2 == 0x321000) {
    if (param_5 == (int *)0x0) {
      return 0;
    }
    if (param_6 < 0x30) {
      return 0;
    }
    if (param_7 == (undefined4 *)0x0) {
      return 0;
    }
    memset(param_5,0,0x30);
    *(undefined1 *)param_5 = 0x11;
    *param_7 = 0x30;
  }
  else {
    if (param_2 == 0x321008) {
      NKDbgPrintfW(L"+WAVE: IOCTL_POWER_SET = %d.\r\n",*param_5);
      if (((3 < param_6) && (-1 < *param_5)) && (*param_5 < 5)) {
        EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 4));
        if (*param_5 == 4) {
          FUN_c09481a4();
        }
        else {
          FUN_c09489cc(param_1 + 200);
        }
        *(int *)(param_1 + 0x8c) = *param_5;
        LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 4));
        uVar1 = 1;
      }
      NKDbgPrintfW(L"-WAVE: IOCTL_POWER_SET = %d.\r\n",*param_5);
      return uVar1;
    }
    if (param_2 != 0x32100c) {
      return 0;
    }
    if (param_5 == (int *)0x0) {
      return 0;
    }
    if (param_6 < 4) {
      return 0;
    }
    if (param_7 == (undefined4 *)0x0) {
      return 0;
    }
    if (*param_5 < 0) {
      return 0;
    }
    if (4 < *param_5) {
      return 0;
    }
    *param_7 = 4;
  }
  return 1;
}



/* c0947cdc FUN_c0947cdc */

/* Boundary evidence: original MIPS .pdata c0947cdc..c0947cf7. Semantic name remains unreviewed. */

void FUN_c0947cdc(int param_1,uint param_2)

{
  FUN_c09489ec((uint *)(param_1 + 200),param_2);
  return;
}



/* c0947cf8 FUN_c0947cf8 */

/* Boundary evidence: original MIPS .pdata c0947cf8..c0947d13. Semantic name remains unreviewed. */

void FUN_c0947cf8(int param_1,uint param_2)

{
  FUN_c0948894(param_1 + 200,param_2);
  return;
}



/* c0947d14 FUN_c0947d14 */

/* Boundary evidence: original MIPS .pdata c0947d14..c0947ddb. Semantic name remains unreviewed. */

undefined4 FUN_c0947d14(undefined4 param_1,LPCWSTR param_2,undefined4 param_3)

{
  LSTATUS LVar1;
  undefined4 local_res8 [2];
  HKEY local_20;
  DWORD local_1c;
  DWORD aDStack_18 [2];
  
  local_1c = 4;
  local_res8[0] = param_3;
  LVar1 = RegOpenKeyExW((HKEY)0x80000002,L"Audio\\SoftwareMixer",0,0x20019,&local_20);
  if (LVar1 == 0) {
    RegQueryValueExW(local_20,param_2,(LPDWORD)0x0,aDStack_18,(LPBYTE)local_res8,&local_1c);
    RegCloseKey(local_20);
  }
  else {
    NKDbgPrintfW(L"WAVEDEV2: Failed to open registry key HKLM\\%s.\r\n",L"Audio\\SoftwareMixer");
  }
  return local_res8[0];
}



/* c0947ddc FUN_c0947ddc */

/* Boundary evidence: original MIPS .pdata c0947ddc..c0947e4f. Semantic name remains unreviewed. */

int FUN_c0947ddc(int param_1)

{
  FUN_c094284c((undefined4 *)(param_1 + 0x20));
  *(undefined4 *)(param_1 + 0x20) = &PTR_FUN_c0941c88;
  FUN_c094284c((undefined4 *)(param_1 + 0x50));
  *(undefined4 *)(param_1 + 0x50) = &PTR_FUN_c0941ca8;
  *(undefined4 *)(param_1 + 0x90) = 0;
  *(undefined4 *)(param_1 + 0x94) = 0;
  *(undefined4 *)(param_1 + 0x98) = 0;
  InitializeCriticalSection((LPCRITICAL_SECTION)(param_1 + 4));
  *(undefined4 *)(param_1 + 0x18) = 0;
  return param_1;
}



/* c0947e50 FUN_c0947e50 */

/* Boundary evidence: original MIPS .pdata c0947e50..c0947ec3. Semantic name remains unreviewed. */

undefined4 FUN_c0947e50(int param_1)

{
  int iVar1;
  int iVar2;
  
  if (*(int *)(param_1 + 0x84) == 0) {
    *(undefined4 *)(param_1 + 0x84) = 1;
    iVar1 = FUN_c094791c(param_1);
    iVar2 = FUN_c094791c(param_1);
    if (iVar2 + iVar1 == 0) {
      *(undefined4 *)(param_1 + 0x84) = 0;
    }
    else {
      FUN_c0948440(param_1 + 200,2);
    }
  }
  return 1;
}



/* c0947ec4 FUN_c0947ec4 */

/* Boundary evidence: original MIPS .pdata c0947ec4..c0947f77. Semantic name remains unreviewed. */

undefined4 FUN_c0947ec4(undefined4 *param_1)

{
  HANDLE pvVar1;
  undefined4 uVar2;
  
  pvVar1 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
  param_1[0x2d] = pvVar1;
  if (pvVar1 != (HANDLE)0x0) {
    InterruptInitialize(param_1[0x2b],pvVar1,0,0);
    pvVar1 = CreateThread((LPSECURITY_ATTRIBUTES)0x0,0,FUN_c0947b00,param_1,0,(LPDWORD)0x0);
    param_1[0x2e] = pvVar1;
    if (pvVar1 != (HANDLE)0x0) {
      uVar2 = FUN_c0947818(param_1,L"Priority256",0x96);
      CeSetThreadPriority(param_1[0x2e],uVar2);
      return 1;
    }
  }
  return 0;
}



/* c0947f78 FUN_c0947f78 */

/* Boundary evidence: original MIPS .pdata c0947f78..c0948127. Semantic name remains unreviewed. */

undefined4 FUN_c0947f78(undefined4 *param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  
  if (param_1[6] == 0) {
    *param_1 = param_2;
    param_1[0x27] = 0xffffffff;
    param_1[0x28] = 0xffffffff;
    piVar3 = param_1 + 0x32;
    param_1[7] = 0;
    param_1[0x20] = 0;
    param_1[0x21] = 0;
    param_1[0x22] = 0;
    param_1[0x29] = 0;
    param_1[0x2a] = 0;
    param_1[0x2f] = 0;
    param_1[0x30] = 5;
    iVar1 = FUN_c0948940((int)piVar3);
    if ((iVar1 != 0) && (iVar1 = FUN_c09481a4(), iVar1 != 0)) {
      iVar1 = FUN_c0947d14(param_1,L"MinDACSampleRate",0);
      *piVar3 = iVar1;
      iVar1 = FUN_c0947d14(param_1,L"MinADCSampleRate",0);
      param_1[0x33] = iVar1;
      if (*piVar3 == 0) {
        *piVar3 = 8000;
      }
      if (iVar1 == 0) {
        param_1[0x33] = 8000;
      }
      (**(code **)(param_1[8] + 0x18))(param_1 + 8,48000);
      (**(code **)(param_1[0x14] + 0x18))(param_1 + 0x14,48000);
      param_1[0x3a] = 0x1000;
      FUN_c09483c0((int)piVar3);
      FUN_c0948340((int)piVar3,param_1 + 0x2b);
      iVar1 = FUN_c0947ec4(param_1);
      if (iVar1 != 0) {
        iVar1 = FUN_c0947818(param_1,L"EnableSpdif",0);
        if (iVar1 != param_1[0x24]) {
          param_1[0x24] = iVar1;
          FUN_c09478a0(param_1,L"EnableSpdif",iVar1);
        }
        uVar2 = FUN_c0947818(param_1,L"EnableSpdifWmaPro",0);
        param_1[0x25] = uVar2;
        FUN_c09478a0(param_1,L"EnableSpdifWmaPro",uVar2);
        FUN_c09471c0();
        param_1[6] = 1;
      }
      return param_1[6];
    }
  }
  return 0;
}



/* c0948128 FUN_c0948128 */

/* Boundary evidence: original MIPS .pdata c0948128..c09481a3. Semantic name remains unreviewed. */

undefined4 FUN_c0948128(undefined4 param_1)

{
  undefined4 uVar1;
  void *pvVar2;
  
  if (DAT_c094a140 == (undefined4 *)0x0) {
    pvVar2 = operator_new(0xec);
    if (pvVar2 == (void *)0x0) {
      DAT_c094a140 = (undefined4 *)0x0;
    }
    else {
      DAT_c094a140 = (undefined4 *)FUN_c0947ddc((int)pvVar2);
    }
    if (DAT_c094a140 == (undefined4 *)0x0) {
      uVar1 = 0;
    }
    else {
      uVar1 = FUN_c0947f78(DAT_c094a140,param_1);
    }
  }
  else {
    uVar1 = 1;
  }
  return uVar1;
}



/* c09481a4 FUN_c09481a4 */

undefined4 FUN_c09481a4(void)

{
  return 1;
}



/* c09481ac FUN_c09481ac */

/* Boundary evidence: original MIPS .pdata c09481ac..c094833f. Semantic name remains unreviewed. */

undefined4 FUN_c09481ac(int param_1)

{
  int iVar1;
  uint uVar2;
  wchar_t *pwVar3;
  
  iVar1 = MmMapIoSpace(0x10900000,0,0x114,0);
  if (iVar1 == 0) {
    NKDbgPrintfW(L"Can not map System Control registers!\r\n");
  }
  else {
    *(uint *)(iVar1 + 0x20) = *(uint *)(iVar1 + 0x20) & 0xc63fffff;
    *(uint *)(iVar1 + 0x20) = *(uint *)(iVar1 + 0x20) | 0x46300000;
    *(uint *)(iVar1 + 0x28) = *(uint *)(iVar1 + 0x28) & 0xff0fffff;
    *(uint *)(iVar1 + 0x28) = *(uint *)(iVar1 + 0x28) | 0x1000000;
    MmUnmapIoSpace(iVar1,0x114);
  }
  WRITE_REGISTER_ULONG(*(undefined4 *)(param_1 + 8),3);
  WRITE_REGISTER_ULONG(*(int *)(param_1 + 8) + 4,3);
  iVar1 = 1000;
  do {
    uVar2 = READ_REGISTER_ULONG(*(int *)(param_1 + 8) + 0x14);
    if ((uVar2 & 1) != 0) break;
    OALStallExecution(1000);
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  if (iVar1 == 0) {
    pwVar3 = L"Failed waiting for SR\r\n";
  }
  else {
    WRITE_REGISTER_ULONG(*(int *)(param_1 + 8) + 0xc,0xffffffff);
    *(undefined4 *)(param_1 + 0xc) = 48000;
    WRITE_REGISTER_ULONG(*(int *)(param_1 + 8) + 8,0xf41d34f0);
    iVar1 = 0x32;
    do {
      uVar2 = READ_REGISTER_ULONG(*(int *)(param_1 + 8) + 0x14);
      if ((uVar2 & 2) != 0) break;
      OALStallExecution(1000);
      iVar1 = iVar1 + -1;
    } while (iVar1 != 0);
    if (iVar1 != 0) {
      return 1;
    }
    pwVar3 = L"Failed waiting for DR\r\n";
  }
  NKDbgPrintfW(pwVar3);
  return 0;
}



/* c0948340 FUN_c0948340 */

/* Boundary evidence: original MIPS .pdata c0948340..c09483bf. Semantic name remains unreviewed. */

bool FUN_c0948340(int param_1,int *param_2)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = HalGetDMAHwIntr(*(undefined4 *)(param_1 + 0x1c));
  iVar2 = HalGetDMAHwIntr(*(undefined4 *)(param_1 + 0x18));
  iVar2 = InterruptConnect(0,0,iVar2 << 8 | uVar1,0);
  *param_2 = iVar2;
  if (iVar2 == 0) {
    NKDbgPrintfW(L"Can not allocate SYSINTR\r\n");
  }
  return iVar2 != 0;
}



/* c09483c0 FUN_c09483c0 */

/* Boundary evidence: original MIPS .pdata c09483c0..c094843f. Semantic name remains unreviewed. */

undefined4 FUN_c09483c0(int param_1)

{
  int iVar1;
  
  iVar1 = HalAllocateDMAChannel();
  *(int *)(param_1 + 0x1c) = iVar1;
  if (iVar1 != 0) {
    HalInitDmaChannel(iVar1,0xc,*(undefined4 *)(param_1 + 0x20),1);
    iVar1 = HalAllocateDMAChannel();
    *(int *)(param_1 + 0x18) = iVar1;
    if (iVar1 != 0) {
      HalInitDmaChannel(iVar1,0xd,*(undefined4 *)(param_1 + 0x20),1);
      return 1;
    }
  }
  return 0;
}



/* c0948440 FUN_c0948440 */

/* Boundary evidence: original MIPS .pdata c0948440..c09484c3. Semantic name remains unreviewed. */

void FUN_c0948440(int param_1,int param_2)

{
  undefined4 uVar1;
  
  if (param_2 == 1) {
    HalSetDMAForReceive(*(undefined4 *)(param_1 + 0x18));
    WRITE_REGISTER_ULONG(*(int *)(param_1 + 8) + 0x10,0x10);
    uVar1 = *(undefined4 *)(param_1 + 0x18);
  }
  else {
    if (param_2 != 2) {
      return;
    }
    WRITE_REGISTER_ULONG(*(int *)(param_1 + 8) + 0x10,1);
    Sleep(1);
    uVar1 = *(undefined4 *)(param_1 + 0x1c);
  }
  HalStartDMA(uVar1);
  return;
}



/* c09484c4 FUN_c09484c4 */

/* Boundary evidence: original MIPS .pdata c09484c4..c0948553. Semantic name remains unreviewed. */

void FUN_c09484c4(int param_1,int param_2)

{
  undefined4 uVar1;
  
  if (param_2 == 1) {
    HalStopDMA(*(undefined4 *)(param_1 + 0x18));
    WRITE_REGISTER_ULONG(*(int *)(param_1 + 8) + 0x10,0x20);
    uVar1 = 0x40;
  }
  else {
    if (param_2 != 2) {
      return;
    }
    HalStopDMA(*(undefined4 *)(param_1 + 0x1c));
    Sleep(1);
    WRITE_REGISTER_ULONG(*(int *)(param_1 + 8) + 0x10,2);
    uVar1 = 4;
  }
  WRITE_REGISTER_ULONG(*(int *)(param_1 + 8) + 0x10,uVar1);
  return;
}



/* c0948554 FUN_c0948554 */

/* Boundary evidence: original MIPS .pdata c0948554..c094859f. Semantic name remains unreviewed. */

undefined4 FUN_c0948554(int param_1,int param_2)

{
  undefined4 uVar1;
  
  if (param_2 == 1) {
    uVar1 = *(undefined4 *)(param_1 + 0x18);
  }
  else {
    if (param_2 != 2) {
      return 0;
    }
    uVar1 = *(undefined4 *)(param_1 + 0x1c);
  }
  uVar1 = HalGetNextDMABuffer(uVar1);
  return uVar1;
}



/* c09485a0 FUN_c09485a0 */

/* Boundary evidence: original MIPS .pdata c09485a0..c09485ef. Semantic name remains unreviewed. */

undefined4 FUN_c09485a0(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  
  if (param_2 == 1) {
    uVar1 = *(undefined4 *)(param_1 + 0x18);
  }
  else {
    if (param_2 != 2) {
      return 0;
    }
    uVar1 = *(undefined4 *)(param_1 + 0x1c);
  }
  uVar1 = HalActivateDMABuffer(uVar1,param_3,param_4);
  return uVar1;
}



/* c09485f0 FUN_c09485f0 */

/* Boundary evidence: original MIPS .pdata c09485f0..c094865f. Semantic name remains unreviewed. */

byte FUN_c09485f0(int param_1)

{
  int iVar1;
  byte bVar2;
  
  iVar1 = HalCheckForDMAInterrupt(*(undefined4 *)(param_1 + 0x18));
  bVar2 = iVar1 != 0;
  if ((bool)bVar2) {
    HalAckDMAInterrupt(*(undefined4 *)(param_1 + 0x18),iVar1);
  }
  iVar1 = HalCheckForDMAInterrupt(*(undefined4 *)(param_1 + 0x1c));
  if (iVar1 != 0) {
    bVar2 = bVar2 | 2;
    HalAckDMAInterrupt(*(undefined4 *)(param_1 + 0x1c),iVar1);
  }
  return bVar2;
}



/* c0948660 FUN_c0948660 */

/* Boundary evidence: original MIPS .pdata c0948660..c0948893. Semantic name remains unreviewed. */

uint FUN_c0948660(int param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  undefined4 uVar3;
  
  if (*(uint *)(param_1 + 0xc) == param_2) {
    return param_2;
  }
  uVar1 = READ_REGISTER_ULONG(*(int *)(param_1 + 8) + 8);
  WRITE_REGISTER_ULONG(*(int *)(param_1 + 8) + 8,uVar1 & 0xfbffffff);
  do {
    uVar2 = READ_REGISTER_ULONG(*(int *)(param_1 + 8) + 0x14);
  } while ((uVar2 & 2) != 0);
  WRITE_REGISTER_ULONG(*(int *)(param_1 + 8) + 4,0);
  do {
    uVar2 = READ_REGISTER_ULONG(*(int *)(param_1 + 8) + 0x14);
  } while ((uVar2 & 1) != 0);
  if (((param_2 == 0x2b11) || (param_2 == 0x5622)) || (uVar3 = 3, param_2 == 0xac44)) {
    uVar3 = 0x13;
  }
  WRITE_REGISTER_ULONG(*(undefined4 *)(param_1 + 8),uVar3);
  if (0x5622 < param_2) {
    if (param_2 == 24000) {
      uVar2 = 0x1d4000;
      goto LAB_c0948808;
    }
    if (param_2 == 32000) {
      uVar2 = 0x2c0000;
    }
    else {
      if (param_2 == 0xac44) {
        uVar2 = 0x1f2000;
        goto LAB_c0948808;
      }
      if (param_2 != 48000) {
LAB_c09487d8:
        param_2 = 48000;
      }
      uVar2 = 0x1d0000;
    }
    uVar2 = uVar2 | 0x2000;
    goto LAB_c0948808;
  }
  if (param_2 == 0x5622) {
    uVar2 = 0x1f0000;
LAB_c0948774:
    uVar2 = uVar2 | 0x4000;
  }
  else {
    if (param_2 == 8000) {
      uVar2 = 0x2c0000;
    }
    else {
      if (param_2 == 0x2b11) {
        uVar2 = 0x1f6000;
        goto LAB_c0948808;
      }
      if (param_2 != 12000) {
        if (param_2 != 16000) goto LAB_c09487d8;
        uVar2 = 0x2c0000;
        goto LAB_c0948774;
      }
      uVar2 = 0x1d0000;
    }
    uVar2 = uVar2 | 0x6000;
  }
LAB_c0948808:
  uVar2 = uVar1 & 0xfb009fff | uVar2;
  WRITE_REGISTER_ULONG(*(int *)(param_1 + 8) + 4,3);
  do {
    uVar1 = READ_REGISTER_ULONG(*(int *)(param_1 + 8) + 0x14);
  } while ((uVar1 & 1) == 0);
  WRITE_REGISTER_ULONG(*(int *)(param_1 + 8) + 8,uVar2);
  WRITE_REGISTER_ULONG(*(int *)(param_1 + 8) + 8,uVar2 | 0x4000000);
  do {
    uVar1 = READ_REGISTER_ULONG(*(int *)(param_1 + 8) + 0x14);
  } while ((uVar1 & 2) == 0);
  *(uint *)(param_1 + 0xc) = param_2;
  return param_2;
}



/* c0948894 FUN_c0948894 */

/* Boundary evidence: original MIPS .pdata c0948894..c094893f. Semantic name remains unreviewed. */

uint FUN_c0948894(int param_1,uint param_2)

{
  uint uVar1;
  
  if (*(int **)(DAT_c094a140 + 0x24) == (int *)(DAT_c094a140 + 0x24)) {
    if (*(int **)(DAT_c094a140 + 0x54) == (int *)(DAT_c094a140 + 0x54)) {
      if (param_2 < *(uint *)(param_1 + 4)) {
        param_2 = *(uint *)(param_1 + 4);
      }
      NKDbgPrintfW(L"SetADCSampleRate : %d ***********\r\n",param_2);
      uVar1 = FUN_c0948660(param_1,param_2);
      return uVar1;
    }
    if (*(uint *)(param_1 + 0xc) == param_2) {
      return param_2;
    }
  }
  return 0;
}



/* c0948940 FUN_c0948940 */

/* Boundary evidence: original MIPS .pdata c0948940..c09489cb. Semantic name remains unreviewed. */

undefined4 FUN_c0948940(int param_1)

{
  int iVar1;
  
  NKDbgPrintfW(L"Initializing PSC%d for I2S operation\r\n",2);
  iVar1 = MmMapIoSpace(0x10a02000,0,0x20,0);
  *(int *)(param_1 + 8) = iVar1;
  if (iVar1 != 0) {
    iVar1 = FUN_c09481ac(param_1);
    if (iVar1 != 0) {
      return 1;
    }
    NKDbgPrintfW(L"I2S: Failed to initialize registers\r\n");
  }
  if (*(int *)(param_1 + 8) != 0) {
    MmUnmapIoSpace(*(int *)(param_1 + 8),0x20);
  }
  return 0;
}



/* c09489cc FUN_c09489cc */

/* Boundary evidence: original MIPS .pdata c09489cc..c09489eb. Semantic name remains unreviewed. */

undefined4 FUN_c09489cc(int param_1)

{
  FUN_c0948940(param_1);
  return 1;
}



/* c09489ec FUN_c09489ec */

/* Boundary evidence: original MIPS .pdata c09489ec..c0948a97. Semantic name remains unreviewed. */

uint FUN_c09489ec(uint *param_1,uint param_2)

{
  uint uVar1;
  
  if (*(int **)(DAT_c094a140 + 0x54) == (int *)(DAT_c094a140 + 0x54)) {
    if (*(int **)(DAT_c094a140 + 0x24) == (int *)(DAT_c094a140 + 0x24)) {
      if (param_2 < *param_1) {
        param_2 = *param_1;
      }
      NKDbgPrintfW(L"SetDACSampleRate : %d -------------\r\n",param_2);
      uVar1 = FUN_c0948660((int)param_1,param_2);
      return uVar1;
    }
    if (param_1[3] == param_2) {
      return param_2;
    }
  }
  return 0;
}



/* c0948c78 FUN_c0948c78 */

/* Boundary evidence: original MIPS .pdata c0948c78..c0948db3. Semantic name remains unreviewed. */

int FUN_c0948c78(HMODULE param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 1;
  if (param_2 == 1) {
    if (DAT_c094a154 != (code *)0x0) {
      iVar2 = (*DAT_c094a154)(param_1,1,param_3);
    }
    iVar1 = 0;
    if (iVar2 == 0) goto LAB_c0948d28;
    FUN_c0948fd0();
  }
  iVar1 = 0;
  if (iVar2 != 0) {
    iVar1 = FUN_c0942078(param_1,param_2);
  }
LAB_c0948d28:
  if (((param_2 == 0) && (FUN_c0948f58(), iVar1 != 0)) && (DAT_c094a154 != (code *)0x0)) {
    iVar1 = (*DAT_c094a154)(param_1,0,param_3);
  }
  return iVar1;
}



/* c0948db4 FUN_c0948db4 */

/* Boundary evidence: original MIPS .pdata c0948db4..c0948ddf. Semantic name remains unreviewed. */

void FUN_c0948db4(_EXCEPTION_POINTERS *param_1)

{
  _XcptFilter(param_1->ExceptionRecord->ExceptionCode,param_1);
  return;
}



/* c0948de0 entry */

/* Boundary evidence: original MIPS .pdata c0948de0..c0948e37. Semantic name remains unreviewed. */

void entry(HMODULE param_1,int param_2,undefined4 param_3)

{
  if (param_2 == 1) {
    FUN_c094900c();
  }
  FUN_c0948c78(param_1,param_2,param_3);
  return;
}



/* c0948e38 FUN_c0948e38 */

/* Boundary evidence: original MIPS .pdata c0948e38..c0948f57. Semantic name remains unreviewed. */

void FUN_c0948e38(UINT param_1,int param_2,int param_3)

{
  LPCRITICAL_SECTION lpCriticalSection;
  undefined4 *_Memory;
  
  DAT_c094a144 = (undefined1)param_3;
  if (param_2 == 0) {
    _Memory = DAT_c094a14c;
    if (DAT_c094a14c != (undefined4 *)0x0) {
      while (DAT_c094a148 = DAT_c094a148 + -1, _Memory <= DAT_c094a148) {
        if ((code *)*DAT_c094a148 != (code *)0x0) {
          (*(code *)*DAT_c094a148)();
          _Memory = DAT_c094a14c;
        }
      }
      free(_Memory);
      DAT_c094a148 = (undefined4 *)0x0;
      DAT_c094a14c = (undefined4 *)0x0;
    }
    FUN_c0948f7c((undefined4 *)&DAT_c0941010,(undefined4 *)&DAT_c0941014);
  }
  FUN_c0948f7c((undefined4 *)&DAT_c0941018,(undefined4 *)&DAT_c094101c);
  if (param_3 == 0) {
    TerminateProcess((HANDLE)0x42,param_1);
  }
  else {
    lpCriticalSection = (LPCRITICAL_SECTION)InterlockedExchange((LONG *)&DAT_c094a150,0);
    if (lpCriticalSection != (LPCRITICAL_SECTION)0x0) {
      DeleteCriticalSection(lpCriticalSection);
      free(lpCriticalSection);
    }
  }
  return;
}



/* c0948f58 FUN_c0948f58 */

/* Boundary evidence: original MIPS .pdata c0948f58..c0948f7b. Semantic name remains unreviewed. */

void FUN_c0948f58(void)

{
  FUN_c0948e38(0,0,1);
  return;
}



/* c0948f7c FUN_c0948f7c */

/* Boundary evidence: original MIPS .pdata c0948f7c..c0948fcf. Semantic name remains unreviewed. */

void FUN_c0948f7c(undefined4 *param_1,undefined4 *param_2)

{
  for (; param_1 < param_2; param_1 = param_1 + 1) {
    if ((code *)*param_1 != (code *)0x0) {
      (*(code *)*param_1)();
    }
  }
  return;
}



/* c0948fd0 FUN_c0948fd0 */

/* Boundary evidence: original MIPS .pdata c0948fd0..c094900b. Semantic name remains unreviewed. */

void FUN_c0948fd0(void)

{
  FUN_c0948f7c((undefined4 *)&DAT_c0941008,(undefined4 *)&DAT_c094100c);
  FUN_c0948f7c((undefined4 *)&DAT_c0941000,(undefined4 *)&DAT_c0941004);
  return;
}



/* c094900c FUN_c094900c */

/* Boundary evidence: original MIPS .pdata c094900c..c094907f. Semantic name remains unreviewed. */

void FUN_c094900c(void)

{
  uint uVar1;
  
  if ((DAT_c094a0fc == 0) || (DAT_c094a0fc == 0xb064)) {
    uVar1 = __security_gen_cookie2();
    DAT_c094a0fc = uVar1 >> 0x10 ^ uVar1 & 0xffff;
    if (DAT_c094a0fc == 0) {
      DAT_c094a0fc = 0xb064;
    }
  }
  DAT_c094a100 = ~DAT_c094a0fc;
  return;
}


