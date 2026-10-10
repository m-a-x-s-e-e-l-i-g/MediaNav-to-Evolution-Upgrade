/* Automatic Ghidra pseudocode. Not original source; not runtime-verified. */

/* c09520d8 FUN_c09520d8 */

/* Boundary evidence: original MIPS .pdata c09520d8..c095210b. Semantic name remains unreviewed. */

undefined4 FUN_c09520d8(HMODULE param_1,int param_2)

{
  if (param_2 == 1) {
    DisableThreadLibraryCalls(param_1);
  }
  return 1;
}



/* c095210c WAV_Init */

/* Boundary evidence: original MIPS .pdata c095210c..c0952127. Semantic name remains unreviewed. */

void WAV_Init(undefined4 param_1)

{
                    /* 0x210c  4  WAV_Init */
  FUN_c0958224(param_1);
  return;
}



/* c0952128 WAV_Deinit */

/* Boundary evidence: original MIPS .pdata c0952128..c0952147. Semantic name remains unreviewed. */

void WAV_Deinit(void)

{
                    /* 0x2128  2  WAV_Deinit */
  FUN_c095772c(DAT_c095a13c);
  return;
}



/* c0952148 WAV_Open */

/* Boundary evidence: original MIPS .pdata c0952148..c0952177. Semantic name remains unreviewed. */

undefined4 * WAV_Open(void)

{
  undefined4 *puVar1;
  
                    /* 0x2148  5  WAV_Open */
  puVar1 = operator_new(4);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    *puVar1 = 0;
  }
  return puVar1;
}



/* c0952178 WAV_Close */

/* Boundary evidence: original MIPS .pdata c0952178..c0952197. Semantic name remains unreviewed. */

undefined4 WAV_Close(void *param_1)

{
                    /* 0x2178  1  WAV_Close */
  operator_delete(param_1);
  return 1;
}



/* c0952198 FUN_c0952198 */

/* Boundary evidence: original MIPS .pdata c0952198..c0952767. Semantic name remains unreviewed. */

undefined4 FUN_c0952198(int param_1,int *param_2)

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
  EnterCriticalSection((LPCRITICAL_SECTION)(DAT_c095a13c + 4));
  if (0x400 < uVar8) {
    if (uVar8 == 0x401) {
      if (piVar6 == (int *)0x0) {
        iVar5 = DAT_c095a13c + 0x50;
      }
      else {
        iVar5 = FUN_c0953700((int)piVar6);
      }
      bVar1 = FUN_c095314c(iVar5,(uint)puVar7,uVar9);
      iVar5 = CONCAT31(extraout_var_00,bVar1);
      goto LAB_c09526e8;
    }
    if (uVar8 == 0x402) {
      if (piVar6 == (int *)0x0) {
        iVar5 = FUN_c0957c18(DAT_c095a13c,(int)puVar7);
      }
      else {
        iVar5 = FUN_c095404c((int)piVar6,(int)puVar7);
      }
      goto LAB_c09526e8;
    }
switchD_c095224c_caseD_7:
    iVar5 = 8;
    goto LAB_c09526e8;
  }
  if (uVar8 == 0x400) {
    if (piVar6 == (int *)0x0) {
      iVar5 = 0xb;
    }
    else {
      bVar1 = FUN_c0953808(piVar6,(uint)puVar7);
      iVar5 = CONCAT31(extraout_var,bVar1);
    }
    goto LAB_c09526e8;
  }
  switch(uVar8) {
  case 3:
  case 0x32:
    iVar5 = 1;
    break;
  case 4:
    if (piVar6 == (int *)0x0) {
      piVar6 = (int *)(DAT_c095a13c + 0x50);
    }
    else {
LAB_c09522e4:
      piVar6 = (int *)FUN_c0953700((int)piVar6);
    }
    goto LAB_c0952300;
  case 5:
    piVar3 = (int *)(DAT_c095a13c + 0x50);
    goto LAB_c0952378;
  case 6:
  case 0x35:
    NKDbgPrintfW(L"WIDM_CLOSE/WODM_CLOSE\r\n");
    iVar5 = (**(code **)(*piVar6 + 8))(piVar6);
    if (iVar5 == 0) {
      FUN_c0953994(piVar6);
    }
    if (*(int **)(DAT_c095a13c + 0x54) == (int *)(DAT_c095a13c + 0x54)) {
      FUN_c0957868(DAT_c095a13c);
      NKDbgPrintfW(L"Stop Output DMA\r\n");
    }
    if (*(int **)(DAT_c095a13c + 0x24) == (int *)(DAT_c095a13c + 0x24)) {
      FUN_c09578d8(DAT_c095a13c);
      NKDbgPrintfW(L"Stop Input DMA\r\n");
    }
    break;
  default:
    goto switchD_c095224c_caseD_7;
  case 9:
  case 0x38:
    pcVar4 = *(code **)(*piVar6 + 0x30);
    goto LAB_c0952498;
  case 10:
  case 0x3a:
    pcVar4 = *(code **)(*piVar6 + 0x14);
    goto LAB_c095246c;
  case 0xb:
  case 0x39:
    pcVar4 = *(code **)(*piVar6 + 0x10);
    goto LAB_c095246c;
  case 0xc:
  case 0x3b:
    pcVar4 = *(code **)(*piVar6 + 0x18);
LAB_c095246c:
    iVar5 = (*pcVar4)(piVar6);
    break;
  case 0xd:
  case 0x3c:
    pcVar4 = *(code **)(*piVar6 + 0xc);
    goto LAB_c0952498;
  case 0x10:
    if (piVar6 == (int *)0x0) {
      uVar2 = FUN_c09574dc();
    }
    else {
      uVar2 = FUN_c09537d8((int)piVar6);
    }
    *puVar7 = uVar2;
    iVar5 = 0;
    break;
  case 0x11:
    if (piVar6 == (int *)0x0) {
      iVar5 = FUN_c095748c(puVar7);
    }
    else {
      iVar5 = FUN_c09537e0(piVar6,(int)puVar7);
    }
    break;
  case 0x12:
    iVar5 = FUN_c0953f40((int)piVar6,puVar7);
    break;
  case 0x13:
    pcVar4 = *(code **)(*piVar6 + 0x3c);
LAB_c0952498:
    iVar5 = (*pcVar4)(piVar6,puVar7);
    break;
  case 0x14:
    iVar5 = FUN_c0953bc4(piVar6);
    break;
  case 0x16:
    if (piVar6 == (int *)0x0) {
      piVar6 = (int *)(DAT_c095a13c + 0x50);
    }
    else {
      piVar6 = (int *)FUN_c0953700((int)piVar6);
    }
    pcVar4 = *(code **)(*piVar6 + 8);
    goto LAB_c0952308;
  case 0x17:
    if (piVar6 != (int *)0x0) {
LAB_c0952580:
      iVar5 = FUN_c0954268((int)piVar6,puVar7);
      break;
    }
    piVar6 = (int *)(DAT_c095a13c + 0x50);
    goto LAB_c095259c;
  case 0x18:
    goto joined_r0xc0952604;
  case 0x33:
    if (piVar6 != (int *)0x0) goto LAB_c09522e4;
    piVar6 = (int *)(DAT_c095a13c + 0x20);
LAB_c0952300:
    pcVar4 = *(code **)(*piVar6 + 0xc);
LAB_c0952308:
    iVar5 = (*pcVar4)(piVar6,puVar7,uVar9);
    break;
  case 0x34:
    piVar3 = (int *)(DAT_c095a13c + 0x20);
LAB_c0952378:
    iVar5 = FUN_c0952d70(piVar3,(int)puVar7,uVar9,piVar6);
    break;
  case 0x3d:
    if (piVar6 != (int *)0x0) goto LAB_c0952580;
    piVar6 = (int *)(DAT_c095a13c + 0x20);
LAB_c095259c:
    iVar5 = FUN_c0953090(piVar6,puVar7);
    break;
  case 0x3e:
joined_r0xc0952604:
    if (piVar6 == (int *)0x0) {
      iVar5 = FUN_c0952d68();
    }
    else {
      iVar5 = FUN_c0954284();
    }
  }
LAB_c09526e8:
  LeaveCriticalSection((LPCRITICAL_SECTION)(DAT_c095a13c + 4));
  if (param_2 != (int *)0x0) {
    *param_2 = iVar5;
  }
  return 1;
}



/* c0952768 FUN_c0952768 */

/* Boundary evidence: original MIPS .pdata c0952768..c0952773. Semantic name remains unreviewed. */

undefined4 FUN_c0952768(void)

{
  return 1;
}



/* c0952774 WAV_IOControl */

/* Boundary evidence: original MIPS .pdata c0952774..c09528ab. Semantic name remains unreviewed. */

undefined4
WAV_IOControl(int *param_1,int param_2,int param_3,undefined4 param_4,int *param_5,uint param_6,
             undefined4 *param_7)

{
  int iVar1;
  undefined4 uVar2;
  
                    /* 0x2774  3  WAV_IOControl */
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
      uVar2 = FUN_c0957304(param_3,param_5);
      return uVar2;
    }
    uVar2 = FUN_c0957c44(DAT_c095a13c,param_2,param_3,param_4,param_5,param_6,param_7);
    return uVar2;
  }
  uVar2 = FUN_c0952198(param_3,param_5);
  return uVar2;
}



/* c09528ac FUN_c09528ac */

undefined4 * FUN_c09528ac(undefined4 *param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  puVar2 = param_1 + 1;
  *param_1 = &PTR_FUN_c09510b4;
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



/* c09528f8 FUN_c09528f8 */

undefined4 FUN_c09528f8(int param_1)

{
  return *(undefined4 *)(param_1 + 0xc);
}



/* c0952900 FUN_c0952900 */

undefined4 FUN_c0952900(int param_1)

{
  return *(undefined4 *)(param_1 + 0x10);
}



/* c0952908 FUN_c0952908 */

undefined4 FUN_c0952908(int param_1,int param_2)

{
  return *(undefined4 *)((param_2 + 5) * 4 + param_1);
}



/* c095291c FUN_c095291c */

undefined4 FUN_c095291c(undefined4 param_1,short *param_2)

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



/* c09529d4 FUN_c09529d4 */

/* Boundary evidence: original MIPS .pdata c09529d4..c0952a47. Semantic name remains unreviewed. */

undefined4 FUN_c09529d4(undefined4 param_1,short *param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  if ((*param_2 != 0x3000) && (iVar1 = FUN_c0953844(), iVar1 == 0)) {
    uVar2 = FUN_c095291c(param_1,param_2);
    return uVar2;
  }
  return 1;
}



/* c0952a48 FUN_c0952a48 */

/* Boundary evidence: original MIPS .pdata c0952a48..c0952ae7. Semantic name remains unreviewed. */

undefined4 FUN_c0952a48(int param_1,int *param_2)

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



/* c0952ae8 FUN_c0952ae8 */

/* Boundary evidence: original MIPS .pdata c0952ae8..c0952b47. Semantic name remains unreviewed. */

void FUN_c0952ae8(int param_1,int *param_2)

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



/* c0952b48 FUN_c0952b48 */

/* Boundary evidence: original MIPS .pdata c0952b48..c0952c37. Semantic name remains unreviewed. */

uint FUN_c0952b48(int param_1,uint param_2,undefined4 param_3,int *param_4)

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
    FUN_c0953984((int)piVar3);
    uVar2 = (**(code **)(*piVar3 + 0x1c))(piVar3,param_2,param_3,uVar1,param_4);
    FUN_c0953994(piVar3);
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



/* c0952c38 FUN_c0952c38 */

/* Boundary evidence: original MIPS .pdata c0952c38..c0952c8b. Semantic name remains unreviewed. */

void FUN_c0952c38(int param_1)

{
  int *piVar1;
  
  for (piVar1 = *(int **)(param_1 + 4); piVar1 != (int *)(param_1 + 4); piVar1 = (int *)*piVar1) {
    (**(code **)(piVar1[-1] + 0x34))();
  }
  return;
}



/* c0952c8c FUN_c0952c8c */

/* Boundary evidence: original MIPS .pdata c0952c8c..c0952cab. Semantic name remains unreviewed. */

void FUN_c0952c8c(void)

{
  FUN_c0957f4c(DAT_c095a13c);
  return;
}



/* c0952cac FUN_c0952cac */

/* Boundary evidence: original MIPS .pdata c0952cac..c0952ccb. Semantic name remains unreviewed. */

void FUN_c0952cac(void)

{
  FUN_c09578a4(DAT_c095a13c);
  return;
}



/* c0952ccc FUN_c0952ccc */

/* Boundary evidence: original MIPS .pdata c0952ccc..c0952cff. Semantic name remains unreviewed. */

undefined4 FUN_c0952ccc(undefined4 param_1,void *param_2,size_t param_3)

{
  if (0x54 < param_3) {
    param_3 = 0x54;
  }
  memcpy(param_2,&DAT_c09510d4,param_3);
  return 0;
}



/* c0952d00 FUN_c0952d00 */

/* Boundary evidence: original MIPS .pdata c0952d00..c0952d33. Semantic name remains unreviewed. */

undefined4 FUN_c0952d00(undefined4 param_1,void *param_2,size_t param_3)

{
  if (0x50 < param_3) {
    param_3 = 0x50;
  }
  memcpy(param_2,&DAT_c0951128,param_3);
  return 0;
}



/* c0952d34 FUN_c0952d34 */

/* Boundary evidence: original MIPS .pdata c0952d34..c0952d67. Semantic name remains unreviewed. */

undefined4 FUN_c0952d34(undefined4 param_1,void *param_2,size_t param_3)

{
  if (0x1c < param_3) {
    param_3 = 0x1c;
  }
  memcpy(param_2,&DAT_c0951178,param_3);
  return 0;
}



/* c0952d68 FUN_c0952d68 */

undefined4 FUN_c0952d68(void)

{
  return 8;
}



/* c0952d70 FUN_c0952d70 */

/* Boundary evidence: original MIPS .pdata c0952d70..c0952ef3. Semantic name remains unreviewed. */

int FUN_c0952d70(int *param_1,int param_2,uint param_3,int *param_4)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  wchar_t *pwVar4;
  undefined4 *puVar5;
  
  if ((*(int *)(param_2 + 4) == 0) || (iVar1 = (**(code **)*param_1)(param_1), iVar1 == 0)) {
    iVar1 = 0x20;
  }
  else if ((param_3 & 1) == 0) {
    puVar5 = (undefined4 *)(*(int *)(param_2 + 4) + 4);
    iVar2 = (**(code **)(*param_1 + 0x18))(param_1,*puVar5);
    iVar1 = 4;
    if (iVar2 == 4) {
      pwVar4 = L"OpenStream : Specified resource is already allocated\r\n";
    }
    else {
      iVar2 = (**(code **)(*param_1 + 0x18))(param_1,*puVar5);
      iVar1 = 0x20;
      if (iVar2 != 0x20) {
        piVar3 = (int *)(**(code **)(*param_1 + 0x14))(param_1,param_2);
        if (piVar3 == (int *)0x0) {
          return 7;
        }
        iVar1 = (**(code **)(*piVar3 + 4))(piVar3,param_1,param_2,param_3);
        if (iVar1 != 0) {
          (**(code **)*piVar3)(piVar3,1);
          return iVar1;
        }
        *param_4 = (int)piVar3;
        return 0;
      }
      pwVar4 = L"OpenStream : Attempted to open with an unsupported sample rate\r\n";
    }
    NKDbgPrintfW(pwVar4);
  }
  else {
    iVar1 = 0;
  }
  return iVar1;
}



/* c0952ef4 FUN_c0952ef4 */

/* Boundary evidence: original MIPS .pdata c0952ef4..c0952f47. Semantic name remains unreviewed. */

void FUN_c0952ef4(int param_1)

{
  int *piVar1;
  
  for (piVar1 = *(int **)(param_1 + 4); piVar1 != (int *)(param_1 + 4); piVar1 = (int *)*piVar1) {
    (**(code **)(piVar1[-1] + 0x20))();
  }
  return;
}



/* c0952f48 FUN_c0952f48 */

undefined4 FUN_c0952f48(int param_1)

{
  return *(undefined4 *)(param_1 + 0x28);
}



/* c0952f50 FUN_c0952f50 */

undefined4 FUN_c0952f50(int param_1)

{
  return *(undefined4 *)(param_1 + 0x2c);
}



/* c0952f60 FUN_c0952f60 */

/* Boundary evidence: original MIPS .pdata c0952f60..c095308f. Semantic name remains unreviewed. */

undefined4 FUN_c0952f60(int *param_1,int param_2,undefined4 param_3,uint param_4,uint *param_5)

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



/* c0953090 FUN_c0953090 */

/* Boundary evidence: original MIPS .pdata c0953090..c095312b. Semantic name remains unreviewed. */

undefined4 FUN_c0953090(int *param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = 8;
  iVar1 = memcmp((void *)*param_2,&DAT_c09512c4,0x10);
  if (iVar1 == 0) {
    uVar2 = FUN_c0952f60(param_1,param_2[1],param_2[4],param_2[5],(uint *)param_2[6]);
  }
  return uVar2;
}



/* c095312c FUN_c095312c */

/* Boundary evidence: original MIPS .pdata c095312c..c095314b. Semantic name remains unreviewed. */

undefined4 FUN_c095312c(int param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 0xc) = param_2;
  FUN_c0952c38(param_1);
  return 0;
}



/* c095314c FUN_c095314c */

/* Boundary evidence: original MIPS .pdata c095314c..c095318b. Semantic name remains unreviewed. */

bool FUN_c095314c(int param_1,uint param_2,undefined4 param_3)

{
  if (param_2 < 4) {
    *(undefined4 *)((param_2 + 5) * 4 + param_1) = param_3;
    FUN_c0952c38(param_1);
  }
  return param_2 >= 4;
}



/* c095318c FUN_c095318c */

/* Boundary evidence: original MIPS .pdata c095318c..c09531d7. Semantic name remains unreviewed. */

undefined4 * FUN_c095318c(undefined4 *param_1,uint param_2)

{
  FUN_c09536d8(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}



/* c09531d8 FUN_c09531d8 */

/* Boundary evidence: original MIPS .pdata c09531d8..c0953223. Semantic name remains unreviewed. */

undefined4 * FUN_c09531d8(undefined4 *param_1,uint param_2)

{
  FUN_c09536d8(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}



/* c0953224 FUN_c0953224 */

/* Boundary evidence: original MIPS .pdata c0953224..c095326f. Semantic name remains unreviewed. */

undefined4 * FUN_c0953224(undefined4 *param_1,uint param_2)

{
  FUN_c09536d8(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}



/* c0953270 FUN_c0953270 */

/* Boundary evidence: original MIPS .pdata c0953270..c09532bb. Semantic name remains unreviewed. */

undefined4 * FUN_c0953270(undefined4 *param_1,uint param_2)

{
  FUN_c09536d8(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}



/* c09532bc FUN_c09532bc */

/* Boundary evidence: original MIPS .pdata c09532bc..c0953307. Semantic name remains unreviewed. */

undefined4 * FUN_c09532bc(undefined4 *param_1,uint param_2)

{
  FUN_c09536d8(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}



/* c0953308 FUN_c0953308 */

/* Boundary evidence: original MIPS .pdata c0953308..c0953353. Semantic name remains unreviewed. */

undefined4 * FUN_c0953308(undefined4 *param_1,uint param_2)

{
  FUN_c09536d8(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}



/* c0953354 FUN_c0953354 */

/* Boundary evidence: original MIPS .pdata c0953354..c095339f. Semantic name remains unreviewed. */

undefined4 * FUN_c0953354(undefined4 *param_1,uint param_2)

{
  FUN_c09536d8(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}



/* c09533a0 FUN_c09533a0 */

/* Boundary evidence: original MIPS .pdata c09533a0..c0953417. Semantic name remains unreviewed. */

undefined4 FUN_c09533a0(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_c0957dd8(DAT_c095a13c,param_2);
  if (iVar1 == 1) {
    uVar2 = 4;
  }
  else if (iVar1 == 0) {
    uVar2 = 0x20;
  }
  else {
    *(int *)(param_1 + 0x28) = iVar1;
    uVar2 = __ll_div(0,1,iVar1,0);
    *(undefined4 *)(param_1 + 0x2c) = uVar2;
    FUN_c0952ef4(param_1);
    uVar2 = 0;
  }
  return uVar2;
}



/* c0953418 FUN_c0953418 */

/* Boundary evidence: original MIPS .pdata c0953418..c095348f. Semantic name remains unreviewed. */

undefined4 FUN_c0953418(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_c0957df4(DAT_c095a13c,param_2);
  if (iVar1 == 1) {
    uVar2 = 4;
  }
  else if (iVar1 == 0) {
    uVar2 = 0x20;
  }
  else {
    *(int *)(param_1 + 0x28) = iVar1;
    uVar2 = __ll_div(0,1,iVar1,0);
    *(undefined4 *)(param_1 + 0x2c) = uVar2;
    FUN_c0952ef4(param_1);
    uVar2 = 0;
  }
  return uVar2;
}



/* c0953490 FUN_c0953490 */

/* Boundary evidence: original MIPS .pdata c0953490..c09534df. Semantic name remains unreviewed. */

undefined4 * FUN_c0953490(void)

{
  undefined4 *puVar1;
  
  puVar1 = operator_new(0x94);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    FUN_c09536c4(puVar1);
    *puVar1 = &PTR_FUN_c09512d4;
  }
  return puVar1;
}



/* c09534e0 FUN_c09534e0 */

/* Boundary evidence: original MIPS .pdata c09534e0..c09536c3. Semantic name remains unreviewed. */

undefined4 * FUN_c09534e0(undefined4 param_1,int param_2)

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
    FUN_c09536c4(puVar1);
    ppuVar2 = &PTR_FUN_c0951194;
  }
  else if (*psVar3 == 0x164) {
    puVar1 = operator_new(0x94);
    if (puVar1 == (undefined4 *)0x0) {
      return (undefined4 *)0x0;
    }
    FUN_c09536c4(puVar1);
    ppuVar2 = &PTR_FUN_c0951318;
  }
  else if (psVar3[7] == 8) {
    if (psVar3[1] == 1) {
      puVar1 = operator_new(0x94);
      if (puVar1 == (undefined4 *)0x0) {
        return (undefined4 *)0x0;
      }
      FUN_c09536c4(puVar1);
      ppuVar2 = &PTR_FUN_c095135c;
    }
    else {
      if (psVar3[1] != 2) {
        return (undefined4 *)0x0;
      }
      puVar1 = operator_new(0x94);
      if (puVar1 == (undefined4 *)0x0) {
        return (undefined4 *)0x0;
      }
      FUN_c09536c4(puVar1);
      ppuVar2 = &PTR_FUN_c09513a0;
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
      FUN_c09536c4(puVar1);
      ppuVar2 = &PTR_FUN_c09513e4;
    }
    else {
      if (psVar3[1] != 2) {
        return (undefined4 *)0x0;
      }
      puVar1 = operator_new(0x94);
      if (puVar1 == (undefined4 *)0x0) {
        return (undefined4 *)0x0;
      }
      FUN_c09536c4(puVar1);
      ppuVar2 = &PTR_FUN_c0951428;
    }
  }
  *puVar1 = ppuVar2;
  return puVar1;
}



/* c09536c4 FUN_c09536c4 */

undefined4 * FUN_c09536c4(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_c09515fc;
  return param_1;
}



/* c09536d8 FUN_c09536d8 */

void FUN_c09536d8(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_c09515fc;
  return;
}



/* c09536e8 FUN_c09536e8 */

bool FUN_c09536e8(int param_1)

{
  return *(int *)(param_1 + 0x38) != 0;
}



/* c0953700 FUN_c0953700 */

undefined4 FUN_c0953700(int param_1)

{
  return *(undefined4 *)(param_1 + 0x50);
}



/* c0953708 FUN_c0953708 */

/* Boundary evidence: original MIPS .pdata c0953708..c095373b. Semantic name remains unreviewed. */

void FUN_c0953708(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  (**(code **)(param_1 + 0x1c))
            (*(undefined4 *)(param_1 + 0x18),param_2,*(undefined4 *)(param_1 + 0x20),param_3,param_4
            );
  return;
}



/* c095373c FUN_c095373c */

/* Boundary evidence: original MIPS .pdata c095373c..c095376f. Semantic name remains unreviewed. */

void FUN_c095373c(int param_1,undefined4 param_2)

{
  (**(code **)(param_1 + 0x1c))
            (*(undefined4 *)(param_1 + 0x18),0x3bd,*(undefined4 *)(param_1 + 0x20),param_2,0);
  return;
}



/* c0953770 FUN_c0953770 */

/* Boundary evidence: original MIPS .pdata c0953770..c09537a3. Semantic name remains unreviewed. */

void FUN_c0953770(int param_1)

{
  (**(code **)(param_1 + 0x1c))
            (*(undefined4 *)(param_1 + 0x18),0x3bb,*(undefined4 *)(param_1 + 0x20),0,0);
  return;
}



/* c09537a4 FUN_c09537a4 */

/* Boundary evidence: original MIPS .pdata c09537a4..c09537d7. Semantic name remains unreviewed. */

void FUN_c09537a4(int param_1)

{
  (**(code **)(param_1 + 0x1c))
            (*(undefined4 *)(param_1 + 0x18),0x3bc,*(undefined4 *)(param_1 + 0x20),0,0);
  return;
}



/* c09537d8 FUN_c09537d8 */

undefined4 FUN_c09537d8(int param_1)

{
  return *(undefined4 *)(param_1 + 0x58);
}



/* c09537e0 FUN_c09537e0 */

/* Boundary evidence: original MIPS .pdata c09537e0..c0953807. Semantic name remains unreviewed. */

undefined4 FUN_c09537e0(int *param_1,int param_2)

{
  code *pcVar1;
  
  pcVar1 = *(code **)(*param_1 + 0x34);
  param_1[0x16] = param_2;
  (*pcVar1)();
  return 0;
}



/* c0953808 FUN_c0953808 */

/* Boundary evidence: original MIPS .pdata c0953808..c0953843. Semantic name remains unreviewed. */

bool FUN_c0953808(int *param_1,uint param_2)

{
  code *pcVar1;
  
  if (param_2 < 4) {
    pcVar1 = *(code **)(*param_1 + 0x34);
    param_1[0x17] = param_2;
    (*pcVar1)();
  }
  return param_2 >= 4;
}



/* c0953844 FUN_c0953844 */

undefined4 FUN_c0953844(void)

{
  return 0;
}



/* c095384c FUN_c095384c */

/* Boundary evidence: original MIPS .pdata c095384c..c0953983. Semantic name remains unreviewed. */

int FUN_c095384c(int *param_1,int *param_2,int *param_3,int param_4)

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
  iVar1 = FUN_c0952900((int)param_2);
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



/* c0953984 FUN_c0953984 */

void FUN_c0953984(int param_1)

{
  *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + 1;
  return;
}



/* c0953994 FUN_c0953994 */

/* Boundary evidence: original MIPS .pdata c0953994..c09539ef. Semantic name remains unreviewed. */

int FUN_c0953994(int *param_1)

{
  int iVar1;
  
  iVar1 = param_1[3] + -1;
  param_1[3] = iVar1;
  if (iVar1 == 0) {
    FUN_c0952ae8(param_1[0x14],param_1);
    (**(code **)*param_1)(param_1,1);
  }
  return iVar1;
}



/* c09539f0 FUN_c09539f0 */

/* Boundary evidence: original MIPS .pdata c09539f0..c0953abb. Semantic name remains unreviewed. */

undefined4 FUN_c09539f0(int param_1,int *param_2)

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



/* c0953abc FUN_c0953abc */

/* Boundary evidence: original MIPS .pdata c0953abc..c0953bc3. Semantic name remains unreviewed. */

int FUN_c0953abc(int *param_1)

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



/* c0953bc4 FUN_c0953bc4 */

/* Boundary evidence: original MIPS .pdata c0953bc4..c0953c5f. Semantic name remains unreviewed. */

undefined4 FUN_c0953bc4(int *param_1)

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
  FUN_c0953994(param_1);
  return 0;
}



/* c0953c60 FUN_c0953c60 */

/* Boundary evidence: original MIPS .pdata c0953c60..c0953d73. Semantic name remains unreviewed. */

uint FUN_c0953c60(int param_1,uint param_2,int param_3)

{
  uint uVar1;
  uint uVar2;
  
  if (param_3 == 1) {
    param_2 = param_2 >> 0x10;
  }
  if (*(uint *)(param_1 + 0x5c) < 2) {
    uVar2 = FUN_c09528f8(*(int *)(param_1 + 0x50));
    if (param_3 == 1) {
      uVar2 = uVar2 >> 0x10;
    }
    uVar2 = uVar2 & 0xffff;
  }
  else {
    uVar2 = 0xffff;
  }
  uVar1 = FUN_c0952908(*(int *)(param_1 + 0x50),*(int *)(param_1 + 0x5c));
  if ((((param_2 & 0xffff) != 0) && (uVar2 != 0)) && ((uVar1 & 0xffff) != 0)) {
    uVar2 = (param_2 & 0xffff) * -200 + ((uVar1 & 0xffff) + uVar2) * -0x46 + 0x1547eac >> 0x10;
    if (uVar2 == 0) {
      return 0x10000;
    }
    if (uVar2 < 0xc9) {
      return (uint)*(ushort *)(&DAT_c095146a + uVar2 * 2);
    }
  }
  return 0;
}



/* c0953e4c FUN_c0953e4c */

/* Boundary evidence: original MIPS .pdata c0953e4c..c0953f3f. Semantic name remains unreviewed. */

int FUN_c0953e4c(int *param_1,int *param_2,int *param_3,int param_4)

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
      goto LAB_c0953ee8;
    }
    param_1[0x1b] = 2;
  }
  else {
    if (*psVar1 != 1) {
      param_1[0x1b] = 3;
      param_1[0x1c] = 4;
      goto LAB_c0953ee8;
    }
    param_1[0x1b] = 1;
  }
  param_1[0x1c] = 2;
LAB_c0953ee8:
  piVar2 = param_1 + 0x20;
  do {
    piVar2[-2] = 0;
    *piVar2 = 0;
    iVar3 = iVar3 + -1;
    piVar2 = piVar2 + 1;
  } while (iVar3 != 0);
  iVar3 = FUN_c095384c(param_1,param_2,param_3,param_4);
  if (iVar3 == 0) {
    (**(code **)(*param_1 + 0x3c))(param_1,0x10000);
  }
  return iVar3;
}



/* c0953f40 FUN_c0953f40 */

undefined4 FUN_c0953f40(int param_1,undefined4 *param_2)

{
  *param_2 = *(undefined4 *)(param_1 + 0x74);
  return 0;
}



/* c0953f50 FUN_c0953f50 */

/* Boundary evidence: original MIPS .pdata c0953f50..c0953f93. Semantic name remains unreviewed. */

undefined4 FUN_c0953f50(int param_1)

{
  *(undefined4 *)(param_1 + 0x10) = 1;
  if (*(int *)(param_1 + 0x44) != 0) {
    (**(code **)(**(int **)(param_1 + 0x50) + 0x10))();
  }
  return 0;
}



/* c0953f94 FUN_c0953f94 */

undefined4 FUN_c0953f94(int param_1)

{
  *(undefined4 *)(param_1 + 0x10) = 0;
  return 0;
}



/* c0953fa0 FUN_c0953fa0 */

/* Boundary evidence: original MIPS .pdata c0953fa0..c095404b. Semantic name remains unreviewed. */

undefined4 FUN_c0953fa0(int *param_1)

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
  FUN_c0953994(param_1);
  return 0;
}



/* c095404c FUN_c095404c */

/* Boundary evidence: original MIPS .pdata c095404c..c0954097. Semantic name remains unreviewed. */

undefined4 FUN_c095404c(int param_1,int param_2)

{
  undefined4 uVar1;
  uint uVar2;
  
  uVar2 = (uint)(param_2 != 0);
  if (uVar2 == *(uint *)(param_1 + 0x68)) {
    uVar1 = 0;
  }
  else {
    *(uint *)(param_1 + 0x68) = uVar2;
    uVar1 = FUN_c0957c18(DAT_c095a13c,uVar2);
  }
  return uVar1;
}



/* c0954098 FUN_c0954098 */

/* Boundary evidence: original MIPS .pdata c0954098..c09540fb. Semantic name remains unreviewed. */

undefined4 FUN_c0954098(int param_1,uint param_2)

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



/* c09540fc FUN_c09540fc */

/* Boundary evidence: original MIPS .pdata c09540fc..c095423b. Semantic name remains unreviewed. */

uint FUN_c09540fc(int *param_1,uint param_2,uint param_3,undefined4 param_4,undefined4 param_5)

{
  int iVar1;
  
  if ((param_1[4] != 0) && (param_1[0x11] != 0)) {
    for (; param_2 < param_3;
        param_2 = (**(code **)(*param_1 + 0x40))(param_1,param_2,param_3,param_4,param_5)) {
      if ((uint)param_1[0x12] <= (uint)param_1[0x11]) {
        do {
          iVar1 = FUN_c0953abc(param_1);
          if (iVar1 == 0) {
            return param_2;
          }
        } while ((uint)param_1[0x12] <= (uint)param_1[0x11]);
      }
    }
  }
  return param_2;
}



/* c095423c FUN_c095423c */

/* Boundary evidence: original MIPS .pdata c095423c..c0954247. Semantic name remains unreviewed. */

undefined4 FUN_c095423c(void)

{
  return 1;
}



/* c0954248 FUN_c0954248 */

/* Boundary evidence: original MIPS .pdata c0954248..c0954267. Semantic name remains unreviewed. */

void FUN_c0954248(void *param_1,int param_2)

{
  memset(param_1,0,param_2 - (int)param_1);
  return;
}



/* c0954268 FUN_c0954268 */

/* Boundary evidence: original MIPS .pdata c0954268..c0954283. Semantic name remains unreviewed. */

void FUN_c0954268(int param_1,undefined4 *param_2)

{
  FUN_c0953090(*(int **)(param_1 + 0x50),param_2);
  return;
}



/* c0954284 FUN_c0954284 */

/* Boundary evidence: original MIPS .pdata c0954284..c095429f. Semantic name remains unreviewed. */

void FUN_c0954284(void)

{
  FUN_c0952d68();
  return;
}



/* c09542a0 FUN_c09542a0 */

/* Boundary evidence: original MIPS .pdata c09542a0..c09542e3. Semantic name remains unreviewed. */

undefined4 * FUN_c09542a0(undefined4 *param_1,uint param_2)

{
  *param_1 = &PTR_FUN_c09515fc;
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}



/* c09542e4 FUN_c09542e4 */

/* Boundary evidence: original MIPS .pdata c09542e4..c095433f. Semantic name remains unreviewed. */

void FUN_c09542e4(int param_1)

{
  uint uVar1;
  int iVar2;
  uint *puVar3;
  
  iVar2 = 0;
  puVar3 = (uint *)(param_1 + 0x60);
  do {
    uVar1 = FUN_c0953c60(param_1,*(uint *)(param_1 + 0x58),iVar2);
    iVar2 = iVar2 + 1;
    *puVar3 = uVar1;
    puVar3 = puVar3 + 1;
  } while (iVar2 < 2);
  return;
}



/* c0954340 FUN_c0954340 */

/* Boundary evidence: original MIPS .pdata c0954340..c09543a7. Semantic name remains unreviewed. */

undefined4 FUN_c0954340(int *param_1)

{
  undefined4 uVar1;
  
  if (param_1[0xe] == 0) {
    if (param_1[0x1a] != 0) {
      param_1[0x1a] = 0;
      FUN_c0957c18(DAT_c095a13c,0);
    }
    (**(code **)(*param_1 + 0x2c))(param_1);
    uVar1 = 0;
  }
  else {
    uVar1 = 0x21;
  }
  return uVar1;
}



/* c09543a8 FUN_c09543a8 */

/* Boundary evidence: original MIPS .pdata c09543a8..c09543db. Semantic name remains unreviewed. */

void FUN_c09543a8(int *param_1,int *param_2,int *param_3,int param_4)

{
  FUN_c0953e4c(param_1,param_2,param_3,param_4);
  param_1[0x22] = -param_1[0x23];
  return;
}



/* c09543dc FUN_c09543dc */

/* Boundary evidence: original MIPS .pdata c09543dc..c09543ff. Semantic name remains unreviewed. */

void FUN_c09543dc(int param_1,undefined4 param_2)

{
  FUN_c0953708(param_1,0x3c0,param_2,0);
  return;
}



/* c0954400 FUN_c0954400 */

/* Boundary evidence: original MIPS .pdata c0954400..c0954423. Semantic name remains unreviewed. */

void FUN_c0954400(int param_1)

{
  FUN_c0953708(param_1,0x3be,0,0);
  return;
}



/* c0954424 FUN_c0954424 */

/* Boundary evidence: original MIPS .pdata c0954424..c0954447. Semantic name remains unreviewed. */

void FUN_c0954424(int param_1)

{
  FUN_c0953708(param_1,0x3bf,0,0);
  return;
}



/* c0954448 FUN_c0954448 */

/* Boundary evidence: original MIPS .pdata c0954448..c0954493. Semantic name remains unreviewed. */

undefined4 FUN_c0954448(int *param_1)

{
  FUN_c0953f94((int)param_1);
  if ((param_1[0xf] != 0) && (*(int *)(param_1[0xf] + 8) != 0)) {
    FUN_c0953abc(param_1);
  }
  return 0;
}



/* c0954494 FUN_c0954494 */

/* Boundary evidence: original MIPS .pdata c0954494..c0954687. Semantic name remains unreviewed. */

short * FUN_c0954494(int param_1,short *param_2,short *param_3)

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
  iVar5 = FUN_c0952f48(*(int *)(param_1 + 0x50));
  pcVar13 = *(char **)(param_1 + 0x44);
  pcVar7 = *(char **)(param_1 + 0x48);
  iVar9 = *(int *)(param_1 + 0x60);
  iVar17 = *(int *)(param_1 + 100);
  iVar18 = *(int *)(param_1 + 0x80);
  iVar10 = *(int *)(param_1 + 0x78);
  iVar6 = *(int *)(param_1 + 0x84);
  iVar8 = *(int *)(param_1 + 0x7c);
joined_r0xc09544f8:
  do {
    iVar3 = iVar6;
    if (pcVar7 <= pcVar13) {
LAB_c0954618:
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
      if (param_3 <= param_2) goto LAB_c0954618;
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
        goto joined_r0xc09544f8;
      }
      *pcVar13 = (char)((uint)iVar3 >> 0x18) + -0x80;
      pcVar13[1] = (char)((uint)iVar4 >> 0x18) + -0x80;
    }
    pcVar13 = pcVar13 + 2;
  } while( true );
}



/* c0954688 FUN_c0954688 */

/* Boundary evidence: original MIPS .pdata c0954688..c09546e3. Semantic name remains unreviewed. */

int FUN_c0954688(int *param_1,int *param_2,int *param_3,int param_4)

{
  int iVar1;
  int iVar2;
  
  iVar1 = FUN_c0953e4c(param_1,param_2,param_3,param_4);
  iVar2 = FUN_c0952f48(param_1[0x14]);
  param_1[0x22] = -iVar2;
  if (iVar1 == 0) {
    (**(code **)(*param_1 + 0x10))(param_1);
  }
  return iVar1;
}



/* c09546e4 FUN_c09546e4 */

/* Boundary evidence: original MIPS .pdata c09546e4..c0954733. Semantic name remains unreviewed. */

int FUN_c09546e4(int *param_1)

{
  int iVar1;
  
  iVar1 = FUN_c0953fa0(param_1);
  if (iVar1 == 0) {
    (**(code **)(*param_1 + 0x10))(param_1);
  }
  return iVar1;
}



/* c095473c FUN_c095473c */

/* Boundary evidence: original MIPS .pdata c095473c..c095490b. Semantic name remains unreviewed. */

short * FUN_c095473c(int param_1,short *param_2,short *param_3,short *param_4,int param_5)

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
  iVar3 = FUN_c0952f48(*(int *)(param_1 + 0x50));
  iVar4 = FUN_c0952f50(*(int *)(param_1 + 0x50));
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
      if (pbVar7 <= pbVar10) goto LAB_c09548bc;
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
LAB_c09548bc:
  *(int *)(param_1 + 0x88) = iVar11;
  *(byte **)(param_1 + 0x4c) = pbVar10 + (*(int *)(param_1 + 0x4c) - *(int *)(param_1 + 0x44));
  *(byte **)(param_1 + 0x44) = pbVar10;
  *(int *)(param_1 + 0x78) = iVar6;
  *(int *)(param_1 + 0x80) = iVar13;
  return param_2;
}



/* c095490c FUN_c095490c */

/* Boundary evidence: original MIPS .pdata c095490c..c0954ad7. Semantic name remains unreviewed. */

short * FUN_c095490c(int param_1,short *param_2,short *param_3,short *param_4,int param_5)

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
  iVar3 = FUN_c0952f48(*(int *)(param_1 + 0x50));
  iVar4 = FUN_c0952f50(*(int *)(param_1 + 0x50));
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
      if (psVar7 <= psVar10) goto LAB_c0954a88;
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
LAB_c0954a88:
  *(int *)(param_1 + 0x88) = iVar11;
  *(int *)(param_1 + 0x4c) = (*(int *)(param_1 + 0x4c) - *(int *)(param_1 + 0x44)) + (int)psVar10;
  *(short **)(param_1 + 0x44) = psVar10;
  *(int *)(param_1 + 0x78) = iVar14;
  *(int *)(param_1 + 0x80) = iVar13;
  return param_2;
}



/* c0954ad8 FUN_c0954ad8 */

/* Boundary evidence: original MIPS .pdata c0954ad8..c0954cef. Semantic name remains unreviewed. */

short * FUN_c0954ad8(int param_1,short *param_2,short *param_3,short *param_4,int param_5)

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
  iVar3 = FUN_c0952f48(*(int *)(param_1 + 0x50));
  iVar4 = FUN_c0952f50(*(int *)(param_1 + 0x50));
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
      if (pbVar5 <= pbVar16) goto LAB_c0954c90;
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
LAB_c0954c90:
  *(int *)(param_1 + 0x88) = iVar14;
  *(byte **)(param_1 + 0x4c) = pbVar16 + (*(int *)(param_1 + 0x4c) - *(int *)(param_1 + 0x44));
  *(byte **)(param_1 + 0x44) = pbVar16;
  *(int *)(param_1 + 0x78) = iVar8;
  *(int *)(param_1 + 0x7c) = iVar7;
  *(int *)(param_1 + 0x80) = iVar17;
  *(int *)(param_1 + 0x84) = iVar6;
  return param_2;
}



/* c0954cf0 FUN_c0954cf0 */

/* Boundary evidence: original MIPS .pdata c0954cf0..c0954eff. Semantic name remains unreviewed. */

short * FUN_c0954cf0(int param_1,short *param_2,short *param_3,short *param_4,int param_5)

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
  iVar3 = FUN_c0952f48(*(int *)(param_1 + 0x50));
  iVar4 = FUN_c0952f50(*(int *)(param_1 + 0x50));
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
      if (psVar5 <= psVar16) goto LAB_c0954ea0;
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
LAB_c0954ea0:
  *(int *)(param_1 + 0x88) = iVar14;
  *(int *)(param_1 + 0x4c) = (*(int *)(param_1 + 0x4c) - *(int *)(param_1 + 0x44)) + (int)psVar16;
  *(short **)(param_1 + 0x44) = psVar16;
  *(int *)(param_1 + 0x78) = iVar8;
  *(int *)(param_1 + 0x7c) = iVar7;
  *(int *)(param_1 + 0x80) = iVar17;
  *(int *)(param_1 + 0x84) = iVar6;
  return param_2;
}



/* c0954f00 FUN_c0954f00 */

/* Boundary evidence: original MIPS .pdata c0954f00..c0954f8b. Semantic name remains unreviewed. */

int FUN_c0954f00(int param_1,void *param_2,int param_3,undefined4 param_4,int param_5)

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



/* c0954fa4 FUN_c0954fa4 */

/* Boundary evidence: original MIPS .pdata c0954fa4..c0954feb. Semantic name remains unreviewed. */

void FUN_c0954fa4(int param_1)

{
  int *piVar1;
  
  for (piVar1 = *(int **)(param_1 + 0x66c); piVar1 != (int *)(param_1 + 0x66c);
      piVar1 = (int *)*piVar1) {
    FUN_c09559cc((int)piVar1);
  }
  return;
}



/* c0954fec FUN_c0954fec */

/* Boundary evidence: original MIPS .pdata c0954fec..c095503b. Semantic name remains unreviewed. */

void FUN_c0954fec(int param_1,uint param_2,int param_3)

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
  FUN_c0953c60(param_1,uVar1,param_3);
  return;
}



/* c095503c FUN_c095503c */

/* Boundary evidence: original MIPS .pdata c095503c..c0955107. Semantic name remains unreviewed. */

int FUN_c095503c(int *param_1,int *param_2,int *param_3,int param_4)

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
    iVar6 = FUN_c095384c(param_1,param_2,param_3,param_4);
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



/* c0955108 FUN_c0955108 */

/* Boundary evidence: original MIPS .pdata c0955108..c09551b3. Semantic name remains unreviewed. */

undefined4 FUN_c0955108(int param_1)

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
  uVar3 = FUN_c0952f48(*(int *)(param_1 + 0x50));
  lVar1 = (ulonglong)*(uint *)(param_1 + 0x684) * (ulonglong)uVar3;
  lVar2 = (ulonglong)*(uint *)(param_1 + 0x688) * 1000000;
  uVar4 = __ull_div((int)lVar1,(int)((ulonglong)lVar1 >> 0x20),(int)lVar2,
                    (int)((ulonglong)lVar2 >> 0x20));
  *(undefined4 *)(param_1 + 0x68c) = uVar4;
  return 0;
}



/* c09551b4 FUN_c09551b4 */

/* Boundary evidence: original MIPS .pdata c09551b4..c095522f. Semantic name remains unreviewed. */

int FUN_c09551b4(int param_1,int param_2,int param_3)

{
  int iVar1;
  int *piVar2;
  
  piVar2 = *(int **)(param_1 + 0x66c);
  while( true ) {
    if (piVar2 == (int *)(param_1 + 0x66c)) {
      return 0;
    }
    iVar1 = FUN_c09528f8((int)piVar2);
    if ((iVar1 == param_2) && (iVar1 = FUN_c0955bd8((int)piVar2), iVar1 == param_3)) break;
    piVar2 = (int *)*piVar2;
  }
  return (int)piVar2;
}



/* c0955230 FUN_c0955230 */

/* Boundary evidence: original MIPS .pdata c0955230..c0955287. Semantic name remains unreviewed. */

undefined4 FUN_c0955230(int param_1)

{
  int *piVar1;
  int *piVar2;
  
  piVar1 = (int *)*(int *)(param_1 + 0x66c);
  while (piVar1 != (int *)(param_1 + 0x66c)) {
    piVar2 = (int *)*piVar1;
    FUN_c0955a78((int)piVar1);
    piVar1 = piVar2;
  }
  return 0;
}



/* c0955288 FUN_c0955288 */

/* Boundary evidence: original MIPS .pdata c0955288..c0955357. Semantic name remains unreviewed. */

void FUN_c0955288(int param_1)

{
  longlong lVar1;
  uint uVar2;
  uint *puVar3;
  int iVar4;
  int *piVar5;
  
  uVar2 = FUN_c0952f50(*(int *)(param_1 + 0x50));
  if (DAT_c095a130 != uVar2) {
    iVar4 = 0;
    DAT_c095a130 = uVar2;
    do {
      lVar1 = (ulonglong)*(uint *)((int)&DAT_c09516a0 + iVar4) * (ulonglong)uVar2;
      puVar3 = (uint *)((int)&DAT_c095a100 + iVar4);
      iVar4 = iVar4 + 4;
      *puVar3 = (int)((ulonglong)lVar1 >> 0x20) * 0x10000 | (uint)lVar1 >> 0x10;
    } while (iVar4 < 0x30);
  }
  FUN_c0955108(param_1);
  for (piVar5 = *(int **)(param_1 + 0x66c); piVar5 != (int *)(param_1 + 0x66c);
      piVar5 = (int *)*piVar5) {
    FUN_c0955a28((int)piVar5);
  }
  return;
}



/* c0955358 FUN_c0955358 */

uint FUN_c0955358(undefined4 param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = param_2 / 0xc - 5;
  uVar1 = (&DAT_c095a100)[param_2 % 0xc];
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



/* c09553b0 FUN_c09553b0 */

/* Boundary evidence: original MIPS .pdata c09553b0..c09553df. Semantic name remains unreviewed. */

int FUN_c09553b0(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = FUN_c0952f50(*(int *)(param_1 + 0x50));
  return iVar1 * param_2;
}



/* c09553e0 FUN_c09553e0 */

/* Boundary evidence: original MIPS .pdata c09553e0..c0955427. Semantic name remains unreviewed. */

void FUN_c09553e0(int *param_1,int *param_2)

{
  undefined4 *puVar1;
  
  *(int *)param_2[1] = *param_2;
  *(int *)(*param_2 + 4) = param_2[1];
  puVar1 = (undefined4 *)param_1[0x19e];
  *param_2 = (int)(param_1 + 0x19d);
  param_2[1] = (int)puVar1;
  *puVar1 = param_2;
  param_1[0x19e] = (int)param_2;
  FUN_c0953994(param_1);
  return;
}



/* c0955428 FUN_c0955428 */

/* Boundary evidence: original MIPS .pdata c0955428..c0955483. Semantic name remains unreviewed. */

int FUN_c0955428(int *param_1)

{
  int iVar1;
  
  iVar1 = FUN_c0953fa0(param_1);
  if (iVar1 == 0) {
    FUN_c0955230((int)param_1);
    (**(code **)(*param_1 + 0x10))(param_1);
  }
  return iVar1;
}



/* c0955484 FUN_c0955484 */

/* Boundary evidence: original MIPS .pdata c0955484..c09554cf. Semantic name remains unreviewed. */

int FUN_c0955484(int *param_1)

{
  int iVar1;
  
  iVar1 = FUN_c0954340(param_1);
  if (iVar1 == 0) {
    FUN_c0955230((int)param_1);
  }
  return iVar1;
}



/* c09554d0 FUN_c09554d0 */

/* Boundary evidence: original MIPS .pdata c09554d0..c09555bb. Semantic name remains unreviewed. */

undefined4 FUN_c09554d0(int param_1,int param_2,int param_3,int param_4)

{
  int *piVar1;
  undefined4 *puVar2;
  
  piVar1 = (int *)FUN_c09551b4(param_1,param_2,param_4);
  if (piVar1 == (int *)0x0) {
    piVar1 = *(int **)(param_1 + 0x674);
    if (piVar1 == (int *)(param_1 + 0x674)) {
      piVar1 = *(int **)(param_1 + 0x66c);
    }
    else {
      FUN_c0953984(param_1);
    }
    FUN_c0955c10((int)piVar1,param_1,param_2,param_3,param_4);
  }
  else {
    FUN_c0955be0((int)piVar1,param_3);
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



/* c09555bc FUN_c09555bc */

/* Boundary evidence: original MIPS .pdata c09555bc..c095568f. Semantic name remains unreviewed. */

undefined4 FUN_c09555bc(int param_1,uint param_2)

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
      uVar1 = FUN_c0955230(param_1);
      return uVar1;
    }
    if (uVar5 != 0) {
      uVar1 = FUN_c09554d0(param_1,uVar4,uVar5,param_2 & 0xf);
      return uVar1;
    }
  }
  iVar2 = FUN_c09551b4(param_1,uVar4,param_2 & 0xf);
  if (iVar2 != 0) {
    FUN_c0955a78(iVar2);
  }
  return 0;
}



/* c0955690 FUN_c0955690 */

/* Boundary evidence: original MIPS .pdata c0955690..c0955767. Semantic name remains unreviewed. */

undefined4 FUN_c0955690(int param_1,uint param_2)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  
  uVar3 = param_2 & 0xf0000000;
  if (uVar3 == 0) {
    uVar1 = FUN_c09555bc(param_1,param_2);
  }
  else if (uVar3 == 0x10000000) {
    *(uint *)(param_1 + 0x684) = param_2 & 0xffffff;
    uVar1 = FUN_c0955108(param_1);
  }
  else if ((uVar3 == 0x20000000) || (uVar3 == 0x30000000)) {
    uVar4 = param_2 >> 0x10 & 0x7f;
    if ((uVar3 == 0x20000000) && (uVar4 != 0)) {
      uVar1 = FUN_c09554d0(param_1,param_2 & 0xffff,uVar4,0x10);
    }
    else {
      iVar2 = FUN_c09551b4(param_1,param_2 & 0xffff,0x10);
      if (iVar2 != 0) {
        FUN_c0955a78(iVar2);
      }
      uVar1 = 0;
    }
  }
  else {
    uVar1 = 0x80004001;
  }
  return uVar1;
}



/* c0955768 FUN_c0955768 */

/* Boundary evidence: original MIPS .pdata c0955768..c095587f. Semantic name remains unreviewed. */

int FUN_c0955768(int *param_1)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  
  piVar2 = (int *)param_1[0x11];
  piVar3 = (int *)param_1[0x12];
  while( true ) {
    if (piVar3 <= piVar2) {
      piVar2 = (int *)FUN_c0953abc(param_1);
      if (piVar2 == (int *)0x0) {
        return 0;
      }
      piVar3 = (int *)param_1[0x12];
    }
    iVar1 = *piVar2;
    if ((uint)param_1[0x1a4] < (uint)(param_1[0x1a3] * iVar1)) break;
    FUN_c0955690((int)param_1,piVar2[1]);
    param_1[0x1a4] = 0;
    piVar2 = piVar2 + 2;
  }
  param_1[0x11] = (int)piVar2;
  return param_1[0x1a3] * iVar1 - param_1[0x1a4];
}



/* c0955880 FUN_c0955880 */

/* Boundary evidence: original MIPS .pdata c0955880..c095588b. Semantic name remains unreviewed. */

undefined4 FUN_c0955880(void)

{
  return 1;
}



/* c095588c FUN_c095588c */

/* Boundary evidence: original MIPS .pdata c095588c..c09559cb. Semantic name remains unreviewed. */

short * FUN_c095588c(int *param_1,short *param_2,short *param_3,short *param_4,int param_5)

{
  int *piVar1;
  bool bVar2;
  undefined3 extraout_var;
  int iVar3;
  short *psVar4;
  short *psVar5;
  int *piVar6;
  
  if ((param_1[4] != 0) &&
     ((bVar2 = FUN_c09536e8((int)param_1), CONCAT31(extraout_var,bVar2) != 0 ||
      ((int *)param_1[0x19b] != param_1 + 0x19b)))) {
    if (param_2 < param_3) {
      do {
        iVar3 = FUN_c0955768(param_1);
        if ((iVar3 == 0) || (psVar5 = param_2 + iVar3 * 2, param_3 < param_2 + iVar3 * 2)) {
          psVar5 = param_3;
        }
        param_1[0x1a4] = ((uint)((int)psVar5 - (int)param_2) >> 2) + param_1[0x1a4];
        piVar1 = (int *)param_1[0x19b];
        while (piVar1 != param_1 + 0x19b) {
          piVar6 = (int *)*piVar1;
          psVar4 = FUN_c0955c7c(piVar1,param_2,psVar5,param_4,param_5);
          piVar1 = piVar6;
          if (param_4 < psVar4) {
            param_4 = psVar4;
          }
        }
        param_2 = psVar5;
      } while (psVar5 < param_3);
    }
    FUN_c0954248(param_4,(int)param_3);
    param_2 = param_3;
  }
  return param_2;
}



/* c09559cc FUN_c09559cc */

/* Boundary evidence: original MIPS .pdata c09559cc..c0955a27. Semantic name remains unreviewed. */

void FUN_c09559cc(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  
  iVar2 = 0;
  puVar3 = (undefined4 *)(param_1 + 0x24);
  do {
    uVar1 = FUN_c0954fec(*(int *)(param_1 + 8),*(uint *)(param_1 + 0x20),iVar2);
    iVar2 = iVar2 + 1;
    *puVar3 = uVar1;
    puVar3 = puVar3 + 1;
  } while (iVar2 < 2);
  return;
}



/* c0955a28 FUN_c0955a28 */

/* Boundary evidence: original MIPS .pdata c0955a28..c0955a77. Semantic name remains unreviewed. */

void FUN_c0955a28(int param_1)

{
  uint uVar1;
  
  if (*(int *)(param_1 + 0x14) == 0x10) {
    uVar1 = FUN_c09553b0(*(int *)(param_1 + 8),*(uint *)(param_1 + 0xc));
  }
  else {
    uVar1 = FUN_c0955358(*(int *)(param_1 + 8),*(uint *)(param_1 + 0xc));
  }
  *(uint *)(param_1 + 0x1c) = uVar1;
  return;
}



/* c0955a78 FUN_c0955a78 */

undefined4 FUN_c0955a78(int param_1)

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



/* c0955ac4 FUN_c0955ac4 */

/* Boundary evidence: original MIPS .pdata c0955ac4..c0955bd7. Semantic name remains unreviewed. */

short * FUN_c0955ac4(int param_1,short *param_2,short *param_3,short *param_4,int param_5)

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
    iVar4 = *(short *)(&DAT_c0951744 + uVar2 * 2) * iVar5 >> 0x10;
    iVar3 = *(short *)(&DAT_c0951744 + uVar2 * 2) * iVar6 >> 0x10;
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



/* c0955bd8 FUN_c0955bd8 */

undefined4 FUN_c0955bd8(int param_1)

{
  return *(undefined4 *)(param_1 + 0x14);
}



/* c0955be0 FUN_c0955be0 */

/* Boundary evidence: original MIPS .pdata c0955be0..c0955c0f. Semantic name remains unreviewed. */

void FUN_c0955be0(int param_1,int param_2)

{
  *(int *)(param_1 + 0x10) = param_2;
  *(undefined4 *)(param_1 + 0x2c) = 0xffffffff;
  *(int *)(param_1 + 0x20) = param_2 << 9;
  FUN_c09559cc(param_1);
  return;
}



/* c0955c10 FUN_c0955c10 */

/* Boundary evidence: original MIPS .pdata c0955c10..c0955c7b. Semantic name remains unreviewed. */

undefined4
FUN_c0955c10(int param_1,undefined4 param_2,undefined4 param_3,int param_4,undefined4 param_5)

{
  *(undefined4 *)(param_1 + 8) = param_2;
  *(undefined4 *)(param_1 + 0xc) = param_3;
  *(undefined4 *)(param_1 + 0x14) = param_5;
  *(undefined4 *)(param_1 + 0x18) = 0;
  FUN_c0955a28(param_1);
  *(int *)(param_1 + 0x10) = param_4;
  *(undefined4 *)(param_1 + 0x2c) = 0xffffffff;
  *(int *)(param_1 + 0x20) = param_4 << 9;
  FUN_c09559cc(param_1);
  return 0;
}



/* c0955c7c FUN_c0955c7c */

/* Boundary evidence: original MIPS .pdata c0955c7c..c0955d23. Semantic name remains unreviewed. */

short * FUN_c0955c7c(int *param_1,short *param_2,short *param_3,short *param_4,int param_5)

{
  short *psVar1;
  uint uVar2;
  int iVar3;
  
  uVar2 = param_1[0xb];
  if (uVar2 == 0xffffffff) {
    psVar1 = FUN_c0955ac4((int)param_1,param_2,param_3,param_4,param_5);
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
    psVar1 = FUN_c0955ac4((int)param_1,param_2,param_3,param_4,param_5);
    if (iVar3 == 0) {
      FUN_c09553e0((int *)param_1[2],param_1);
    }
  }
  return psVar1;
}



/* c0955d24 FUN_c0955d24 */

undefined4 * FUN_c0955d24(uint param_1)

{
  ushort *puVar1;
  int iVar2;
  
  iVar2 = 0;
  puVar1 = &DAT_c09519e0;
  do {
    if (*puVar1 == param_1) {
      return &DAT_c09519cc + iVar2 * 9;
    }
    puVar1 = puVar1 + 0x12;
    iVar2 = iVar2 + 1;
  } while ((int)puVar1 < -0x3f6ae5b4);
  return (undefined4 *)0x0;
}



/* c0955d78 FUN_c0955d78 */

void FUN_c0955d78(int param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 4) = param_2;
  return;
}



/* c0955d80 FUN_c0955d80 */

/* Boundary evidence: original MIPS .pdata c0955d80..c0955dcf. Semantic name remains unreviewed. */

void FUN_c0955d80(int *param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  *param_2 = 0xe4;
  param_2[1] = param_1[1];
  uVar1 = (**(code **)(*param_1 + 0x14))();
  param_2[2] = uVar1;
  return;
}



/* c0955dd0 FUN_c0955dd0 */

/* Boundary evidence: original MIPS .pdata c0955dd0..c0955e13. Semantic name remains unreviewed. */

undefined4 * FUN_c0955dd0(undefined4 *param_1,uint param_2)

{
  *param_1 = &PTR_FUN_c0951a38;
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}



/* c0955e14 FUN_c0955e14 */

/* Boundary evidence: original MIPS .pdata c0955e14..c0955e6b. Semantic name remains unreviewed. */

void FUN_c0955e14(int *param_1,undefined4 *param_2)

{
  FUN_c0955d80(param_1,param_2);
  param_2[3] = 0;
  param_2[4] = 0;
  param_2[0x2d] = 0;
  param_2[0x2e] = 0xffff;
  param_2[0x33] = 1;
  return;
}



/* c0955e78 FUN_c0955e78 */

/* Boundary evidence: original MIPS .pdata c0955e78..c0955f3f. Semantic name remains unreviewed. */

undefined4 FUN_c0955e78(int *param_1,int param_2)

{
  uint uVar1;
  undefined4 *puVar2;
  uint uVar3;
  uint uVar4;
  uint *puVar5;
  
  uVar1 = (**(code **)(*param_1 + 0x18))(param_1);
  puVar2 = FUN_c0955d24(uVar1);
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



/* c0955f40 FUN_c0955f40 */

/* Boundary evidence: original MIPS .pdata c0955f40..c095601b. Semantic name remains unreviewed. */

undefined4 FUN_c0955f40(int *param_1,int param_2)

{
  uint uVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  uint uVar4;
  
  uVar1 = (**(code **)(*param_1 + 0x18))(param_1);
  puVar2 = FUN_c0955d24(uVar1);
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



/* c095601c FUN_c095601c */

/* Boundary evidence: original MIPS .pdata c095601c..c095606b. Semantic name remains unreviewed. */

void FUN_c095601c(int *param_1,undefined4 *param_2)

{
  FUN_c0955e14(param_1,param_2);
  wcscpy((wchar_t *)(param_2 + 0xd),L"Master Volume");
  wcscpy((wchar_t *)(param_2 + 5),L"Master Volume");
  return;
}



/* c095606c FUN_c095606c */

/* Boundary evidence: original MIPS .pdata c095606c..c095608b. Semantic name remains unreviewed. */

void FUN_c095606c(undefined4 param_1,undefined4 param_2)

{
  FUN_c0957780(DAT_c095a13c,param_2);
  return;
}



/* c095608c FUN_c095608c */

/* Boundary evidence: original MIPS .pdata c095608c..c09560ab. Semantic name remains unreviewed. */

void FUN_c095608c(void)

{
  FUN_c09577e4(DAT_c095a13c);
  return;
}



/* c09560ac FUN_c09560ac */

/* Boundary evidence: original MIPS .pdata c09560ac..c09560fb. Semantic name remains unreviewed. */

void FUN_c09560ac(int *param_1,undefined4 *param_2)

{
  FUN_c0955e14(param_1,param_2);
  wcscpy((wchar_t *)(param_2 + 0xd),L"Mic Volume");
  wcscpy((wchar_t *)(param_2 + 5),L"Mic Volume");
  return;
}



/* c0956104 FUN_c0956104 */

/* Boundary evidence: original MIPS .pdata c0956104..c0956123. Semantic name remains unreviewed. */

void FUN_c0956104(undefined4 param_1,undefined4 param_2)

{
  FUN_c0957838(DAT_c095a13c,param_2);
  return;
}



/* c0956124 FUN_c0956124 */

/* Boundary evidence: original MIPS .pdata c0956124..c0956143. Semantic name remains unreviewed. */

void FUN_c0956124(void)

{
  FUN_c0957830(DAT_c095a13c);
  return;
}



/* c0956144 FUN_c0956144 */

/* Boundary evidence: original MIPS .pdata c0956144..c0956197. Semantic name remains unreviewed. */

void FUN_c0956144(int *param_1,undefined4 *param_2)

{
  FUN_c0955d80(param_1,param_2);
  param_2[3] = 1;
  param_2[4] = 0;
  param_2[0x2d] = 0;
  param_2[0x2e] = 1;
  param_2[0x33] = 0;
  return;
}



/* c09561a0 FUN_c09561a0 */

/* Boundary evidence: original MIPS .pdata c09561a0..c09561e3. Semantic name remains unreviewed. */

undefined4 FUN_c09561a0(int *param_1,int param_2)

{
  undefined4 uVar1;
  
  uVar1 = (**(code **)(*param_1 + 0x1c))();
  **(undefined4 **)(param_2 + 0x14) = uVar1;
  return 0;
}



/* c09561e4 FUN_c09561e4 */

/* Boundary evidence: original MIPS .pdata c09561e4..c095621b. Semantic name remains unreviewed. */

undefined4 FUN_c09561e4(int *param_1,int param_2)

{
  (**(code **)(*param_1 + 0x20))(param_1,**(undefined4 **)(param_2 + 0x14));
  return 0;
}



/* c095621c FUN_c095621c */

/* Boundary evidence: original MIPS .pdata c095621c..c095626b. Semantic name remains unreviewed. */

void FUN_c095621c(int *param_1,undefined4 *param_2)

{
  FUN_c0956144(param_1,param_2);
  wcscpy((wchar_t *)(param_2 + 0xd),L"Master Mute");
  wcscpy((wchar_t *)(param_2 + 5),L"Master Mute");
  return;
}



/* c0956278 FUN_c0956278 */

/* Boundary evidence: original MIPS .pdata c0956278..c0956297. Semantic name remains unreviewed. */

void FUN_c0956278(void)

{
  FUN_c09577ec(DAT_c095a13c);
  return;
}



/* c0956298 FUN_c0956298 */

/* Boundary evidence: original MIPS .pdata c0956298..c09562b7. Semantic name remains unreviewed. */

void FUN_c0956298(undefined4 param_1,int param_2)

{
  FUN_c09577b0(DAT_c095a13c,param_2);
  return;
}



/* c09562b8 FUN_c09562b8 */

/* Boundary evidence: original MIPS .pdata c09562b8..c0956307. Semantic name remains unreviewed. */

void FUN_c09562b8(int *param_1,undefined4 *param_2)

{
  FUN_c0956144(param_1,param_2);
  wcscpy((wchar_t *)(param_2 + 0xd),L"Mic Mute");
  wcscpy((wchar_t *)(param_2 + 5),L"Mic Mute");
  return;
}



/* c0956308 FUN_c0956308 */

/* Boundary evidence: original MIPS .pdata c0956308..c0956327. Semantic name remains unreviewed. */

void FUN_c0956308(void)

{
  FUN_c09577f4(DAT_c095a13c);
  return;
}



/* c0956328 FUN_c0956328 */

/* Boundary evidence: original MIPS .pdata c0956328..c0956347. Semantic name remains unreviewed. */

void FUN_c0956328(undefined4 param_1,int param_2)

{
  FUN_c09577fc(DAT_c095a13c,param_2);
  return;
}



/* c0956348 FUN_c0956348 */

/* Boundary evidence: original MIPS .pdata c0956348..c09563b3. Semantic name remains unreviewed. */

void FUN_c0956348(int *param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  FUN_c0955d80(param_1,param_2);
  param_2[0x2e] = 1;
  param_2[0x2d] = 0;
  param_2[0x33] = 0;
  uVar1 = (**(code **)(*param_1 + 0x1c))(param_1);
  param_2[4] = uVar1;
  return;
}



/* c09563b4 FUN_c09563b4 */

/* Boundary evidence: original MIPS .pdata c09563b4..c09564f3. Semantic name remains unreviewed. */

undefined4 FUN_c09563b4(int *param_1,int param_2,int param_3)

{
  uint uVar1;
  undefined4 uVar2;
  uint uVar3;
  undefined4 *puVar4;
  
  uVar1 = (**(code **)(*param_1 + 0x1c))(param_1);
  if (*(uint *)(param_2 + 0xc) == uVar1) {
    if (param_3 == 0) {
      if (*(int *)(param_2 + 0x10) != 4) goto LAB_c0956400;
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
      if (*(int *)(param_2 + 0x10) != 0x88) goto LAB_c0956400;
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
LAB_c0956400:
    uVar2 = 0xb;
  }
  return uVar2;
}



/* c09564f4 FUN_c09564f4 */

/* Boundary evidence: original MIPS .pdata c09564f4..c09565cb. Semantic name remains unreviewed. */

undefined4 FUN_c09564f4(int *param_1,int param_2,int param_3)

{
  uint uVar1;
  undefined4 uVar2;
  uint uVar3;
  undefined4 *puVar4;
  
  uVar1 = (**(code **)(*param_1 + 0x1c))(param_1);
  if (*(uint *)(param_2 + 0xc) == uVar1) {
    if (param_3 == 0) {
      if (*(int *)(param_2 + 0x10) != 4) goto LAB_c0956540;
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
LAB_c0956540:
    uVar2 = 0xb;
  }
  return uVar2;
}



/* c09565cc FUN_c09565cc */

/* Boundary evidence: original MIPS .pdata c09565cc..c0956627. Semantic name remains unreviewed. */

void FUN_c09565cc(int *param_1,undefined4 *param_2)

{
  FUN_c0956348(param_1,param_2);
  wcscpy((wchar_t *)(param_2 + 0xd),L"Eq Preset");
  wcscpy((wchar_t *)(param_2 + 5),L"Eq Preset");
  param_2[3] = 3;
  return;
}



/* c0956634 FUN_c0956634 */

/* Boundary evidence: original MIPS .pdata c0956634..c0956687. Semantic name remains unreviewed. */

void FUN_c0956634(undefined4 param_1,int param_2,int param_3)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)(param_3 * 0x88 + param_2);
  *puVar1 = 0;
  puVar1[1] = 0;
  wcscpy((wchar_t *)(puVar1 + 2),(wchar_t *)(&PTR_u_Rock_c095a0e0)[param_3]);
  return;
}



/* c095669c FUN_c095669c */

/* Boundary evidence: original MIPS .pdata c095669c..c09566f7. Semantic name remains unreviewed. */

void FUN_c095669c(int *param_1,undefined4 *param_2)

{
  FUN_c0956348(param_1,param_2);
  wcscpy((wchar_t *)(param_2 + 0xd),L"Input Mux");
  wcscpy((wchar_t *)(param_2 + 5),L"Input Mux");
  param_2[3] = 3;
  return;
}



/* c0956714 FUN_c0956714 */

/* Boundary evidence: original MIPS .pdata c0956714..c09567af. Semantic name remains unreviewed. */

void FUN_c0956714(int *param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  uint uVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  
  puVar4 = (undefined4 *)(param_3 * 0x88 + param_2);
  uVar1 = (**(code **)(*param_1 + 0x18))(param_1);
  *puVar4 = uVar1;
  uVar2 = (**(code **)(*param_1 + 0x18))(param_1);
  puVar3 = FUN_c0955d24(uVar2);
  puVar4[1] = *puVar3;
  wcscpy((wchar_t *)(puVar4 + 2),(wchar_t *)(&PTR_u_Microphone_c095a0ec)[param_3]);
  return;
}



/* c09567c8 FUN_c09567c8 */

/* Boundary evidence: original MIPS .pdata c09567c8..c0956817. Semantic name remains unreviewed. */

void FUN_c09567c8(int *param_1,undefined4 *param_2)

{
  FUN_c0956144(param_1,param_2);
  wcscpy((wchar_t *)(param_2 + 0xd),L"S/PDIF");
  wcscpy((wchar_t *)(param_2 + 5),L"S/PDIF");
  return;
}



/* c0956828 FUN_c0956828 */

/* Boundary evidence: original MIPS .pdata c0956828..c0956863. Semantic name remains unreviewed. */

void FUN_c0956828(undefined4 param_1,int param_2)

{
  undefined4 *puVar1;
  
  puVar1 = DAT_c095a13c;
  if (param_2 != DAT_c095a13c[0x24]) {
    DAT_c095a13c[0x24] = param_2;
    FUN_c095799c(puVar1,L"EnableSpdif",param_2);
  }
  return;
}



/* c0956864 FUN_c0956864 */

/* Boundary evidence: original MIPS .pdata c0956864..c09568b3. Semantic name remains unreviewed. */

void FUN_c0956864(int *param_1,undefined4 *param_2)

{
  FUN_c0956144(param_1,param_2);
  wcscpy((wchar_t *)(param_2 + 0xd),L"WmaPro S/PDIF");
  wcscpy((wchar_t *)(param_2 + 5),L"WmaPro S/PDIF");
  return;
}



/* c09568d8 FUN_c09568d8 */

/* Boundary evidence: original MIPS .pdata c09568d8..c0956907. Semantic name remains unreviewed. */

void FUN_c09568d8(undefined4 param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  
  puVar1 = DAT_c095a13c;
  DAT_c095a13c[0x25] = param_2;
  FUN_c095799c(puVar1,L"EnableSpdifWmaPro",param_2);
  return;
}



/* c0956908 FUN_c0956908 */

/* Boundary evidence: original MIPS .pdata c0956908..c0956a3f. Semantic name remains unreviewed. */

undefined4 * FUN_c0956908(undefined4 *param_1)

{
  uint uVar1;
  undefined4 *puVar2;
  
  *param_1 = &PTR_FUN_c0951cc0;
  param_1[1] = &PTR_FUN_c0951a54;
  param_1[2] = 0xffffffff;
  param_1[3] = &PTR_FUN_c0951ad0;
  param_1[4] = 0xffffffff;
  param_1[5] = &PTR_FUN_c0951c10;
  param_1[6] = 0xffffffff;
  param_1[7] = &PTR_FUN_c0951c5c;
  param_1[8] = 0xffffffff;
  param_1[9] = &PTR_FUN_c0951b44;
  param_1[10] = 0xffffffff;
  param_1[0xb] = 0;
  param_1[0xc] = &PTR_FUN_c0951a94;
  param_1[0xd] = 0xffffffff;
  param_1[0xf] = 0xffffffff;
  param_1[0xe] = &PTR_FUN_c0951b0c;
  puVar2 = param_1 + 0x13;
  param_1[0x11] = 0xffffffff;
  param_1[0x10] = &PTR_FUN_c0951bb0;
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



/* c0956a40 FUN_c0956a40 */

/* Boundary evidence: original MIPS .pdata c0956a40..c0956aa7. Semantic name remains unreviewed. */

undefined4 * FUN_c0956a40(undefined4 *param_1,uint param_2)

{
  *param_1 = &PTR_FUN_c0951cc0;
  param_1[0x10] = &PTR_FUN_c0951a38;
  param_1[0xe] = &PTR_FUN_c0951a38;
  param_1[0xc] = &PTR_FUN_c0951a38;
  param_1[9] = &PTR_FUN_c0951a38;
  param_1[7] = &PTR_FUN_c0951a38;
  param_1[5] = &PTR_FUN_c0951a38;
  param_1[3] = &PTR_FUN_c0951a38;
  param_1[1] = &PTR_FUN_c0951a38;
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}



/* c0956aa8 FUN_c0956aa8 */

/* Boundary evidence: original MIPS .pdata c0956aa8..c0956b17. Semantic name remains unreviewed. */

void FUN_c0956aa8(undefined4 param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  
  for (puVar1 = DAT_c095a134; puVar1 != (undefined4 *)0x0; puVar1 = (undefined4 *)puVar1[2]) {
    if ((code *)puVar1[1] != (code *)0x0) {
      (*(code *)puVar1[1])(*puVar1,param_1,0,param_2,0);
    }
  }
  return;
}



/* c0956b18 FUN_c0956b18 */

/* Boundary evidence: original MIPS .pdata c0956b18..c0956b8b. Semantic name remains unreviewed. */

undefined4 FUN_c0956b18(undefined1 *param_1)

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



/* c0956b8c FUN_c0956b8c */

/* Boundary evidence: original MIPS .pdata c0956b8c..c0956c37. Semantic name remains unreviewed. */

undefined4 FUN_c0956b8c(undefined4 *param_1,undefined4 *param_2,uint param_3)

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
    puVar1[2] = DAT_c095a134;
    DAT_c095a134 = puVar1;
    *param_1 = puVar1;
    uVar2 = 0;
  }
  return uVar2;
}



/* c0956c38 FUN_c0956c38 */

/* Boundary evidence: original MIPS .pdata c0956c38..c0956c9f. Semantic name remains unreviewed. */

undefined4 FUN_c0956c38(HLOCAL param_1)

{
  HLOCAL pvVar1;
  HLOCAL hMem;
  HLOCAL pvVar2;
  
  pvVar1 = (HLOCAL)0x0;
  hMem = DAT_c095a134;
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
    pvVar2 = DAT_c095a134;
  }
  DAT_c095a134 = pvVar2;
  LocalFree(hMem);
  return 0;
}



/* c0956ca0 FUN_c0956ca0 */

/* Boundary evidence: original MIPS .pdata c0956ca0..c0956f87. Semantic name remains unreviewed. */

undefined4 FUN_c0956ca0(int param_1,uint param_2)

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
    puVar3 = (ushort *)(&DAT_c09519c4 + *(uint *)(param_1 + 4) * 2);
  }
  else {
    if (uVar6 != 1) {
      if (uVar6 == 2) {
        uVar2 = *(uint *)(param_1 + 0xc) & 0xffff;
      }
      else if ((uVar6 != 3) && (uVar6 != 4)) {
        return 0xb;
      }
      goto LAB_c0956db4;
    }
    if (1 < *(uint *)(param_1 + 4)) {
      return 0x400;
    }
    puVar1 = FUN_c0955d24((uint)*(ushort *)(&DAT_c09519c4 + *(uint *)(param_1 + 4) * 2));
    if (puVar1 == (undefined4 *)0x0) {
      return 1;
    }
    if ((uint)*(byte *)((int)puVar1 + 0x17) <= *(uint *)(param_1 + 8)) {
      return 0x400;
    }
    puVar3 = (ushort *)(*(uint *)(param_1 + 8) * 2 + puVar1[4]);
  }
  uVar2 = (uint)*puVar3;
LAB_c0956db4:
  if (uVar6 < 3) {
    puVar1 = FUN_c0955d24(uVar2);
    if (puVar1 == (undefined4 *)0x0) {
      return 1;
    }
  }
  else {
    if (uVar6 == 3) {
      iVar5 = 0;
      piVar4 = &DAT_c09519cc;
      while (*piVar4 != *(int *)(param_1 + 0x18)) {
        piVar4 = piVar4 + 9;
        iVar5 = iVar5 + 1;
        if (-0x3f6ae5c9 < (int)piVar4) {
          return 0x400;
        }
      }
    }
    else {
      if (uVar6 != 4) {
        return 0x400;
      }
      iVar5 = 0;
      piVar4 = &DAT_c09519e8;
      while (*piVar4 != *(int *)(param_1 + 200)) {
        piVar4 = piVar4 + 9;
        iVar5 = iVar5 + 1;
        if (-0x3f6ae5ad < (int)piVar4) {
          return 0x400;
        }
      }
    }
    puVar1 = &DAT_c09519cc + iVar5 * 9;
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



/* c0956f88 FUN_c0956f88 */

/* Boundary evidence: original MIPS .pdata c0956f88..c09571c3. Semantic name remains unreviewed. */

undefined4 FUN_c0956f88(int param_1,uint param_2)

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
    puVar2 = FUN_c0955d24(uVar7);
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
        piVar6 = *(int **)(uVar4 + DAT_c095a138);
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
       (piVar6 = *(int **)((*(uint *)(param_1 + 8) + 0x13) * 4 + DAT_c095a138), piVar6 == (int *)0x0
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
          (uVar4 < 0x6c && (piVar6 = *(int **)(uVar4 + DAT_c095a138), piVar6 != (int *)0x0));
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



/* c09571c4 FUN_c09571c4 */

/* Boundary evidence: original MIPS .pdata c09571c4..c0957233. Semantic name remains unreviewed. */

undefined4 FUN_c09571c4(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int *piVar2;
  
  if ((*(uint *)(param_1 + 4) < 8) &&
     (piVar2 = *(int **)((*(uint *)(param_1 + 4) + 0x13) * 4 + DAT_c095a138), piVar2 != (int *)0x0))
  {
    uVar1 = (**(code **)(*piVar2 + 0xc))(piVar2,param_1,param_2);
  }
  else {
    uVar1 = 0x401;
  }
  return uVar1;
}



/* c0957234 FUN_c0957234 */

/* Boundary evidence: original MIPS .pdata c0957234..c09572bb. Semantic name remains unreviewed. */

undefined4 FUN_c0957234(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  uint uVar2;
  int *piVar3;
  
  uVar2 = *(uint *)(param_1 + 4);
  if ((uVar2 < 8) && (piVar3 = *(int **)((uVar2 + 0x13) * 4 + DAT_c095a138), piVar3 != (int *)0x0))
  {
    (**(code **)(*piVar3 + 0x10))(piVar3,param_1,param_2);
    FUN_c0956aa8(0x3d1,*(uint *)(param_1 + 4));
    uVar1 = 0;
  }
  else {
    uVar1 = 0x401;
  }
  return uVar1;
}



/* c09572bc FUN_c09572bc */

/* Boundary evidence: original MIPS .pdata c09572bc..c0957303. Semantic name remains unreviewed. */

undefined4 FUN_c09572bc(void)

{
  undefined4 *puVar1;
  
  puVar1 = operator_new(0x6c);
  if (puVar1 == (undefined4 *)0x0) {
    DAT_c095a138 = (undefined4 *)0x0;
  }
  else {
    DAT_c095a138 = FUN_c0956908(puVar1);
  }
  return 1;
}



/* c0957304 FUN_c0957304 */

/* Boundary evidence: original MIPS .pdata c0957304..c095747f. Semantic name remains unreviewed. */

undefined4 FUN_c0957304(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  switch(*(undefined4 *)(param_1 + 4)) {
  case 1:
    uVar1 = 1;
    break;
  case 2:
    uVar1 = FUN_c0956b18(*(undefined1 **)(param_1 + 0xc));
    break;
  case 3:
    uVar1 = FUN_c0956b8c(*(undefined4 **)(param_1 + 8),*(undefined4 **)(param_1 + 0xc),
                         *(uint *)(param_1 + 0x10));
    break;
  case 4:
    uVar1 = FUN_c0956c38(*(HLOCAL *)(param_1 + 8));
    break;
  case 5:
    uVar1 = FUN_c0956ca0(*(int *)(param_1 + 0xc),*(uint *)(param_1 + 0x10));
    break;
  case 6:
    uVar1 = FUN_c0956f88(*(int *)(param_1 + 0xc),*(uint *)(param_1 + 0x10));
    break;
  case 7:
    uVar1 = FUN_c09571c4(*(int *)(param_1 + 0xc),*(undefined4 *)(param_1 + 0x10));
    break;
  case 8:
    uVar1 = FUN_c0957234(*(int *)(param_1 + 0xc),*(undefined4 *)(param_1 + 0x10));
    break;
  default:
    NKDbgPrintfW(L"[ERROR] \"Unsupported mixer message\"\r\n");
    uVar1 = 8;
  }
  *param_2 = uVar1;
  return 1;
}



/* c0957480 FUN_c0957480 */

/* Boundary evidence: original MIPS .pdata c0957480..c095748b. Semantic name remains unreviewed. */

undefined4 FUN_c0957480(void)

{
  return 1;
}



/* c095748c FUN_c095748c */

/* Boundary evidence: original MIPS .pdata c095748c..c09574db. Semantic name remains unreviewed. */

undefined4 FUN_c095748c(undefined4 param_1)

{
  (**(code **)(*(int *)(DAT_c095a138 + 4) + 0x1c))((int *)(DAT_c095a138 + 4),param_1);
  FUN_c0956aa8(0x3d1,*(undefined4 *)(DAT_c095a138 + 8));
  return 0;
}



/* c09574dc FUN_c09574dc */

/* Boundary evidence: original MIPS .pdata c09574dc..c095750b. Semantic name remains unreviewed. */

void FUN_c09574dc(void)

{
  (**(code **)(*(int *)(DAT_c095a138 + 4) + 0x20))();
  return;
}



/* c095750c FUN_c095750c */

/* Boundary evidence: original MIPS .pdata c095750c..c095754f. Semantic name remains unreviewed. */

undefined4 * FUN_c095750c(undefined4 *param_1,uint param_2)

{
  *param_1 = &PTR_FUN_c0951a38;
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}



/* c0957550 FUN_c0957550 */

/* Boundary evidence: original MIPS .pdata c0957550..c0957593. Semantic name remains unreviewed. */

undefined4 * FUN_c0957550(undefined4 *param_1,uint param_2)

{
  *param_1 = &PTR_FUN_c0951a38;
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}



/* c0957594 FUN_c0957594 */

/* Boundary evidence: original MIPS .pdata c0957594..c09575d7. Semantic name remains unreviewed. */

undefined4 * FUN_c0957594(undefined4 *param_1,uint param_2)

{
  *param_1 = &PTR_FUN_c0951a38;
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}



/* c09575d8 FUN_c09575d8 */

/* Boundary evidence: original MIPS .pdata c09575d8..c095761b. Semantic name remains unreviewed. */

undefined4 * FUN_c09575d8(undefined4 *param_1,uint param_2)

{
  *param_1 = &PTR_FUN_c0951a38;
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}



/* c095761c FUN_c095761c */

/* Boundary evidence: original MIPS .pdata c095761c..c095765f. Semantic name remains unreviewed. */

undefined4 * FUN_c095761c(undefined4 *param_1,uint param_2)

{
  *param_1 = &PTR_FUN_c0951a38;
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}



/* c0957660 FUN_c0957660 */

/* Boundary evidence: original MIPS .pdata c0957660..c09576a3. Semantic name remains unreviewed. */

undefined4 * FUN_c0957660(undefined4 *param_1,uint param_2)

{
  *param_1 = &PTR_FUN_c0951a38;
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}



/* c09576a4 FUN_c09576a4 */

/* Boundary evidence: original MIPS .pdata c09576a4..c09576e7. Semantic name remains unreviewed. */

undefined4 * FUN_c09576a4(undefined4 *param_1,uint param_2)

{
  *param_1 = &PTR_FUN_c0951a38;
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}



/* c09576e8 FUN_c09576e8 */

/* Boundary evidence: original MIPS .pdata c09576e8..c095772b. Semantic name remains unreviewed. */

undefined4 * FUN_c09576e8(undefined4 *param_1,uint param_2)

{
  *param_1 = &PTR_FUN_c0951a38;
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}



/* c095772c FUN_c095772c */

/* Boundary evidence: original MIPS .pdata c095772c..c095777f. Semantic name remains unreviewed. */

bool FUN_c095772c(int param_1)

{
  int iVar1;
  
  if (*(int *)(param_1 + 0xb0) != 0) {
    FreeIntChainHandler();
    *(undefined4 *)(param_1 + 0xb0) = 0;
  }
  iVar1 = FUN_c0958600();
  return iVar1 != 0;
}



/* c0957780 FUN_c0957780 */

/* Boundary evidence: original MIPS .pdata c0957780..c09577af. Semantic name remains unreviewed. */

undefined4 FUN_c0957780(int param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 0x9c) = param_2;
  if (*(int *)(param_1 + 0xa8) != 0) {
    param_2 = 0;
  }
  FUN_c095312c(param_1 + 0x50,param_2);
  return 0;
}



/* c09577b0 FUN_c09577b0 */

/* Boundary evidence: original MIPS .pdata c09577b0..c09577e3. Semantic name remains unreviewed. */

undefined4 FUN_c09577b0(int param_1,int param_2)

{
  undefined4 uVar1;
  
  *(int *)(param_1 + 0xa8) = param_2;
  if (param_2 == 0) {
    uVar1 = *(undefined4 *)(param_1 + 0x9c);
  }
  else {
    uVar1 = 0;
  }
  FUN_c095312c(param_1 + 0x50,uVar1);
  return 0;
}



/* c09577e4 FUN_c09577e4 */

undefined4 FUN_c09577e4(int param_1)

{
  return *(undefined4 *)(param_1 + 0x9c);
}



/* c09577ec FUN_c09577ec */

undefined4 FUN_c09577ec(int param_1)

{
  return *(undefined4 *)(param_1 + 0xa8);
}



/* c09577f4 FUN_c09577f4 */

undefined4 FUN_c09577f4(int param_1)

{
  return *(undefined4 *)(param_1 + 0xa4);
}



/* c09577fc FUN_c09577fc */

/* Boundary evidence: original MIPS .pdata c09577fc..c095782f. Semantic name remains unreviewed. */

undefined4 FUN_c09577fc(int param_1,int param_2)

{
  undefined4 uVar1;
  
  *(int *)(param_1 + 0xa4) = param_2;
  if (param_2 == 0) {
    uVar1 = *(undefined4 *)(param_1 + 0xa0);
  }
  else {
    uVar1 = 0;
  }
  FUN_c095312c(param_1 + 0x20,uVar1);
  return 0;
}



/* c0957830 FUN_c0957830 */

undefined4 FUN_c0957830(int param_1)

{
  return *(undefined4 *)(param_1 + 0xa0);
}



/* c0957838 FUN_c0957838 */

/* Boundary evidence: original MIPS .pdata c0957838..c0957867. Semantic name remains unreviewed. */

undefined4 FUN_c0957838(int param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 0xa0) = param_2;
  if (*(int *)(param_1 + 0xa4) != 0) {
    param_2 = 0;
  }
  FUN_c095312c(param_1 + 0x20,param_2);
  return 0;
}



/* c0957868 FUN_c0957868 */

/* Boundary evidence: original MIPS .pdata c0957868..c09578a3. Semantic name remains unreviewed. */

void FUN_c0957868(int param_1)

{
  if (*(int *)(param_1 + 0x84) != 0) {
    FUN_c09585a0(param_1 + 200,2);
    *(undefined4 *)(param_1 + 0x84) = 0;
  }
  return;
}



/* c09578a4 FUN_c09578a4 */

/* Boundary evidence: original MIPS .pdata c09578a4..c09578d7. Semantic name remains unreviewed. */

undefined4 FUN_c09578a4(int param_1)

{
  if (*(int *)(param_1 + 0x80) == 0) {
    *(undefined4 *)(param_1 + 0x80) = 1;
    FUN_c095852c(param_1 + 200,1);
  }
  return 1;
}



/* c09578d8 FUN_c09578d8 */

/* Boundary evidence: original MIPS .pdata c09578d8..c0957913. Semantic name remains unreviewed. */

void FUN_c09578d8(int param_1)

{
  if (*(int *)(param_1 + 0x80) != 0) {
    FUN_c09585a0(param_1 + 200,1);
    *(undefined4 *)(param_1 + 0x80) = 0;
  }
  return;
}



/* c0957914 FUN_c0957914 */

/* Boundary evidence: original MIPS .pdata c0957914..c095799b. Semantic name remains unreviewed. */

undefined4 FUN_c0957914(undefined4 *param_1,LPCWSTR param_2,undefined4 param_3)

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



/* c095799c FUN_c095799c */

/* Boundary evidence: original MIPS .pdata c095799c..c0957a17. Semantic name remains unreviewed. */

void FUN_c095799c(undefined4 *param_1,LPCWSTR param_2,undefined4 param_3)

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



/* c0957a18 FUN_c0957a18 */

/* Boundary evidence: original MIPS .pdata c0957a18..c0957aa7. Semantic name remains unreviewed. */

int FUN_c0957a18(int param_1)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int local_20;
  undefined1 auStack_1c [12];
  
  uVar1 = FUN_c0958608(param_1 + 200,2);
  local_20 = 0;
  memset(auStack_1c,0,8);
  uVar2 = FUN_c0952b48(param_1 + 0x50,uVar1,uVar1 + 0x100,&local_20);
  iVar3 = uVar2 - uVar1;
  if (iVar3 != 0) {
    FUN_c0958654(param_1 + 200,2,uVar1,iVar3);
  }
  return iVar3;
}



/* c0957aa8 FUN_c0957aa8 */

/* Boundary evidence: original MIPS .pdata c0957aa8..c0957b23. Semantic name remains unreviewed. */

int FUN_c0957aa8(int param_1)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  
  uVar1 = FUN_c0958608(param_1 + 200,1);
  uVar2 = FUN_c0952b48(param_1 + 0x20,uVar1,uVar1 + 0x100,(int *)0x0);
  iVar3 = uVar2 - uVar1;
  if (iVar3 != 0) {
    FUN_c0958654(param_1 + 200,1,uVar1,iVar3);
  }
  return iVar3;
}



/* c0957b24 FUN_c0957b24 */

/* Boundary evidence: original MIPS .pdata c0957b24..c0957bfb. Semantic name remains unreviewed. */

void FUN_c0957b24(int param_1)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = param_1 + 200;
  do {
    InterruptDone(*(undefined4 *)(param_1 + 0xac));
    WaitForSingleObject(*(HANDLE *)(param_1 + 0xb4),0xffffffff);
    EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 4));
    bVar1 = FUN_c09586a4(iVar3);
    if ((((bVar1 & 2) != 0) && (iVar2 = FUN_c0957a18(param_1), iVar2 == 0)) &&
       (*(int *)(param_1 + 0x84) != 0)) {
      FUN_c09585a0(iVar3,2);
      *(undefined4 *)(param_1 + 0x84) = 0;
    }
    if ((((bVar1 & 1) != 0) && (iVar2 = FUN_c0957aa8(param_1), iVar2 == 0)) &&
       (*(int *)(param_1 + 0x80) != 0)) {
      FUN_c09585a0(iVar3,1);
      *(undefined4 *)(param_1 + 0x80) = 0;
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 4));
  } while( true );
}



/* c0957bfc FUN_c0957bfc */

/* Boundary evidence: original MIPS .pdata c0957bfc..c0957c17. Semantic name remains unreviewed. */

void FUN_c0957bfc(int param_1)

{
  FUN_c0957b24(param_1);
  return;
}



/* c0957c18 FUN_c0957c18 */

undefined4 FUN_c0957c18(int param_1,int param_2)

{
  if (param_2 == 0) {
    *(int *)(param_1 + 0x88) = *(int *)(param_1 + 0x88) + -1;
  }
  else {
    *(int *)(param_1 + 0x88) = *(int *)(param_1 + 0x88) + 1;
  }
  return 0;
}



/* c0957c44 FUN_c0957c44 */

/* Boundary evidence: original MIPS .pdata c0957c44..c0957dd7. Semantic name remains unreviewed. */

undefined4
FUN_c0957c44(int param_1,int param_2,undefined4 param_3,undefined4 param_4,int *param_5,uint param_6
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
          FUN_c0958600();
        }
        else {
          FUN_c0958814(param_1 + 200);
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



/* c0957dd8 FUN_c0957dd8 */

/* Boundary evidence: original MIPS .pdata c0957dd8..c0957df3. Semantic name remains unreviewed. */

void FUN_c0957dd8(int param_1,int param_2)

{
  FUN_c0958714(param_1 + 200,param_2);
  return;
}



/* c0957df4 FUN_c0957df4 */

/* Boundary evidence: original MIPS .pdata c0957df4..c0957e0f. Semantic name remains unreviewed. */

void FUN_c0957df4(int param_1,int param_2)

{
  FUN_c0958750(param_1 + 200,param_2);
  return;
}



/* c0957e10 FUN_c0957e10 */

/* Boundary evidence: original MIPS .pdata c0957e10..c0957ed7. Semantic name remains unreviewed. */

undefined4 FUN_c0957e10(undefined4 param_1,LPCWSTR param_2,undefined4 param_3)

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



/* c0957ed8 FUN_c0957ed8 */

/* Boundary evidence: original MIPS .pdata c0957ed8..c0957f4b. Semantic name remains unreviewed. */

int FUN_c0957ed8(int param_1)

{
  FUN_c09528ac((undefined4 *)(param_1 + 0x20));
  *(undefined4 *)(param_1 + 0x20) = &PTR_FUN_c0951d7c;
  FUN_c09528ac((undefined4 *)(param_1 + 0x50));
  *(undefined4 *)(param_1 + 0x50) = &PTR_FUN_c0951d9c;
  *(undefined4 *)(param_1 + 0x90) = 0;
  *(undefined4 *)(param_1 + 0x94) = 0;
  *(undefined4 *)(param_1 + 0x98) = 0;
  InitializeCriticalSection((LPCRITICAL_SECTION)(param_1 + 4));
  *(undefined4 *)(param_1 + 0x18) = 0;
  return param_1;
}



/* c0957f4c FUN_c0957f4c */

/* Boundary evidence: original MIPS .pdata c0957f4c..c0957fbf. Semantic name remains unreviewed. */

undefined4 FUN_c0957f4c(int param_1)

{
  int iVar1;
  int iVar2;
  
  if (*(int *)(param_1 + 0x84) == 0) {
    *(undefined4 *)(param_1 + 0x84) = 1;
    iVar1 = FUN_c0957a18(param_1);
    iVar2 = FUN_c0957a18(param_1);
    if (iVar2 + iVar1 == 0) {
      *(undefined4 *)(param_1 + 0x84) = 0;
    }
    else {
      FUN_c095852c(param_1 + 200,2);
    }
  }
  return 1;
}



/* c0957fc0 FUN_c0957fc0 */

/* Boundary evidence: original MIPS .pdata c0957fc0..c0958073. Semantic name remains unreviewed. */

undefined4 FUN_c0957fc0(undefined4 *param_1)

{
  HANDLE pvVar1;
  undefined4 uVar2;
  
  pvVar1 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
  param_1[0x2d] = pvVar1;
  if (pvVar1 != (HANDLE)0x0) {
    InterruptInitialize(param_1[0x2b],pvVar1,0,0);
    pvVar1 = CreateThread((LPSECURITY_ATTRIBUTES)0x0,0,FUN_c0957bfc,param_1,0,(LPDWORD)0x0);
    param_1[0x2e] = pvVar1;
    if (pvVar1 != (HANDLE)0x0) {
      uVar2 = FUN_c0957914(param_1,L"Priority256",0x96);
      CeSetThreadPriority(param_1[0x2e],uVar2);
      return 1;
    }
  }
  return 0;
}



/* c0958074 FUN_c0958074 */

/* Boundary evidence: original MIPS .pdata c0958074..c0958223. Semantic name remains unreviewed. */

undefined4 FUN_c0958074(undefined4 *param_1,undefined4 param_2)

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
    iVar1 = FUN_c095878c((int)piVar3);
    if ((iVar1 != 0) && (iVar1 = FUN_c0958600(), iVar1 != 0)) {
      iVar1 = FUN_c0957e10(param_1,L"MinDACSampleRate",0);
      *piVar3 = iVar1;
      iVar1 = FUN_c0957e10(param_1,L"MinADCSampleRate",0);
      param_1[0x33] = iVar1;
      if (*piVar3 == 0) {
        *piVar3 = 8000;
      }
      if (iVar1 == 0) {
        param_1[0x33] = 8000;
      }
      (**(code **)(param_1[8] + 0x18))(param_1 + 8,48000);
      (**(code **)(param_1[0x14] + 0x18))(param_1 + 0x14,48000);
      param_1[0x39] = 0x100;
      FUN_c09584ac((int)piVar3);
      FUN_c095842c((int)piVar3,param_1 + 0x2b);
      iVar1 = FUN_c0957fc0(param_1);
      if (iVar1 != 0) {
        iVar1 = FUN_c0957914(param_1,L"EnableSpdif",0);
        if (iVar1 != param_1[0x24]) {
          param_1[0x24] = iVar1;
          FUN_c095799c(param_1,L"EnableSpdif",iVar1);
        }
        uVar2 = FUN_c0957914(param_1,L"EnableSpdifWmaPro",0);
        param_1[0x25] = uVar2;
        FUN_c095799c(param_1,L"EnableSpdifWmaPro",uVar2);
        FUN_c09572bc();
        param_1[6] = 1;
      }
      return param_1[6];
    }
  }
  return 0;
}



/* c0958224 FUN_c0958224 */

/* Boundary evidence: original MIPS .pdata c0958224..c095829f. Semantic name remains unreviewed. */

undefined4 FUN_c0958224(undefined4 param_1)

{
  undefined4 uVar1;
  void *pvVar2;
  
  if (DAT_c095a13c == (undefined4 *)0x0) {
    pvVar2 = operator_new(0xe8);
    if (pvVar2 == (void *)0x0) {
      DAT_c095a13c = (undefined4 *)0x0;
    }
    else {
      DAT_c095a13c = (undefined4 *)FUN_c0957ed8((int)pvVar2);
    }
    if (DAT_c095a13c == (undefined4 *)0x0) {
      uVar1 = 0;
    }
    else {
      uVar1 = FUN_c0958074(DAT_c095a13c,param_1);
    }
  }
  else {
    uVar1 = 1;
  }
  return uVar1;
}



/* c09582a0 FUN_c09582a0 */

/* Boundary evidence: original MIPS .pdata c09582a0..c095842b. Semantic name remains unreviewed. */

undefined4 FUN_c09582a0(int param_1)

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
    WRITE_REGISTER_ULONG(*(int *)(param_1 + 8) + 8,0xf42c60f0);
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



/* c095842c FUN_c095842c */

/* Boundary evidence: original MIPS .pdata c095842c..c09584ab. Semantic name remains unreviewed. */

bool FUN_c095842c(int param_1,int *param_2)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = HalGetDMAHwIntr(*(undefined4 *)(param_1 + 0x18));
  iVar2 = HalGetDMAHwIntr(*(undefined4 *)(param_1 + 0x14));
  iVar2 = InterruptConnect(0,0,iVar2 << 8 | uVar1,0);
  *param_2 = iVar2;
  if (iVar2 == 0) {
    NKDbgPrintfW(L"Can not allocate SYSINTR\r\n");
  }
  return iVar2 != 0;
}



/* c09584ac FUN_c09584ac */

/* Boundary evidence: original MIPS .pdata c09584ac..c095852b. Semantic name remains unreviewed. */

undefined4 FUN_c09584ac(int param_1)

{
  int iVar1;
  
  iVar1 = HalAllocateDMAChannel();
  *(int *)(param_1 + 0x18) = iVar1;
  if (iVar1 != 0) {
    HalInitDmaChannel(iVar1,0x12,*(undefined4 *)(param_1 + 0x1c),1);
    iVar1 = HalAllocateDMAChannel();
    *(int *)(param_1 + 0x14) = iVar1;
    if (iVar1 != 0) {
      HalInitDmaChannel(iVar1,0x13,*(undefined4 *)(param_1 + 0x1c),1);
      return 1;
    }
  }
  return 0;
}



/* c095852c FUN_c095852c */

/* Boundary evidence: original MIPS .pdata c095852c..c095859f. Semantic name remains unreviewed. */

void FUN_c095852c(int param_1,int param_2)

{
  undefined4 uVar1;
  
  if (param_2 == 1) {
    HalSetDMAForReceive(*(undefined4 *)(param_1 + 0x14));
    WRITE_REGISTER_ULONG(*(int *)(param_1 + 8) + 0x10,0x10);
    uVar1 = *(undefined4 *)(param_1 + 0x14);
  }
  else {
    if (param_2 != 2) {
      return;
    }
    WRITE_REGISTER_ULONG(*(int *)(param_1 + 8) + 0x10,1);
    uVar1 = *(undefined4 *)(param_1 + 0x18);
  }
  HalStartDMA(uVar1);
  return;
}



/* c09585a0 FUN_c09585a0 */

/* Boundary evidence: original MIPS .pdata c09585a0..c09585ff. Semantic name remains unreviewed. */

void FUN_c09585a0(int param_1,int param_2)

{
  undefined4 uVar1;
  
  if (param_2 == 1) {
    HalStopDMA(*(undefined4 *)(param_1 + 0x14));
    uVar1 = 0x20;
  }
  else {
    if (param_2 != 2) {
      return;
    }
    HalStopDMA(*(undefined4 *)(param_1 + 0x18));
    uVar1 = 2;
  }
  WRITE_REGISTER_ULONG(*(int *)(param_1 + 8) + 0x10,uVar1);
  return;
}



/* c0958600 FUN_c0958600 */

undefined4 FUN_c0958600(void)

{
  return 1;
}



/* c0958608 FUN_c0958608 */

/* Boundary evidence: original MIPS .pdata c0958608..c0958653. Semantic name remains unreviewed. */

undefined4 FUN_c0958608(int param_1,int param_2)

{
  undefined4 uVar1;
  
  if (param_2 == 1) {
    uVar1 = *(undefined4 *)(param_1 + 0x14);
  }
  else {
    if (param_2 != 2) {
      return 0;
    }
    uVar1 = *(undefined4 *)(param_1 + 0x18);
  }
  uVar1 = HalGetNextDMABuffer(uVar1);
  return uVar1;
}



/* c0958654 FUN_c0958654 */

/* Boundary evidence: original MIPS .pdata c0958654..c09586a3. Semantic name remains unreviewed. */

undefined4 FUN_c0958654(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  
  if (param_2 == 1) {
    uVar1 = *(undefined4 *)(param_1 + 0x14);
  }
  else {
    if (param_2 != 2) {
      return 0;
    }
    uVar1 = *(undefined4 *)(param_1 + 0x18);
  }
  uVar1 = HalActivateDMABuffer(uVar1,param_3,param_4);
  return uVar1;
}



/* c09586a4 FUN_c09586a4 */

/* Boundary evidence: original MIPS .pdata c09586a4..c0958713. Semantic name remains unreviewed. */

byte FUN_c09586a4(int param_1)

{
  int iVar1;
  byte bVar2;
  
  iVar1 = HalCheckForDMAInterrupt(*(undefined4 *)(param_1 + 0x14));
  bVar2 = iVar1 != 0;
  if ((bool)bVar2) {
    HalAckDMAInterrupt(*(undefined4 *)(param_1 + 0x14),iVar1);
  }
  iVar1 = HalCheckForDMAInterrupt(*(undefined4 *)(param_1 + 0x18));
  if (iVar1 != 0) {
    bVar2 = bVar2 | 2;
    HalAckDMAInterrupt(*(undefined4 *)(param_1 + 0x18),iVar1);
  }
  return bVar2;
}



/* c0958714 FUN_c0958714 */

undefined4 FUN_c0958714(undefined4 param_1,int param_2)

{
  undefined4 uVar1;
  
  if (*(int **)(DAT_c095a13c + 0x54) == (int *)(DAT_c095a13c + 0x54)) {
    uVar1 = 8000;
    if (param_2 != 8000) {
      uVar1 = 0;
    }
  }
  else {
    uVar1 = 1;
  }
  return uVar1;
}



/* c0958750 FUN_c0958750 */

undefined4 FUN_c0958750(undefined4 param_1,int param_2)

{
  undefined4 uVar1;
  
  if (*(int **)(DAT_c095a13c + 0x24) == (int *)(DAT_c095a13c + 0x24)) {
    uVar1 = 8000;
    if (param_2 != 8000) {
      uVar1 = 0;
    }
  }
  else {
    uVar1 = 1;
  }
  return uVar1;
}



/* c095878c FUN_c095878c */

/* Boundary evidence: original MIPS .pdata c095878c..c0958813. Semantic name remains unreviewed. */

undefined4 FUN_c095878c(int param_1)

{
  int iVar1;
  
  NKDbgPrintfW(L"Initializing PSC%d for I2S2 operation\r\n",0);
  iVar1 = MmMapIoSpace(0x10a00000,0,0x20,0);
  *(int *)(param_1 + 8) = iVar1;
  if (iVar1 != 0) {
    iVar1 = FUN_c09582a0(param_1);
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



/* c0958814 FUN_c0958814 */

/* Boundary evidence: original MIPS .pdata c0958814..c0958833. Semantic name remains unreviewed. */

undefined4 FUN_c0958814(int param_1)

{
  FUN_c095878c(param_1);
  return 1;
}



/* c0958a14 FUN_c0958a14 */

/* Boundary evidence: original MIPS .pdata c0958a14..c0958b4f. Semantic name remains unreviewed. */

int FUN_c0958a14(HMODULE param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 1;
  if (param_2 == 1) {
    if (DAT_c095a150 != (code *)0x0) {
      iVar2 = (*DAT_c095a150)(param_1,1,param_3);
    }
    iVar1 = 0;
    if (iVar2 == 0) goto LAB_c0958ac4;
    FUN_c0958d6c();
  }
  iVar1 = 0;
  if (iVar2 != 0) {
    iVar1 = FUN_c09520d8(param_1,param_2);
  }
LAB_c0958ac4:
  if (((param_2 == 0) && (FUN_c0958cf4(), iVar1 != 0)) && (DAT_c095a150 != (code *)0x0)) {
    iVar1 = (*DAT_c095a150)(param_1,0,param_3);
  }
  return iVar1;
}



/* c0958b50 FUN_c0958b50 */

/* Boundary evidence: original MIPS .pdata c0958b50..c0958b7b. Semantic name remains unreviewed. */

void FUN_c0958b50(_EXCEPTION_POINTERS *param_1)

{
  _XcptFilter(param_1->ExceptionRecord->ExceptionCode,param_1);
  return;
}



/* c0958b7c entry */

/* Boundary evidence: original MIPS .pdata c0958b7c..c0958bd3. Semantic name remains unreviewed. */

void entry(HMODULE param_1,int param_2,undefined4 param_3)

{
  if (param_2 == 1) {
    FUN_c0958da8();
  }
  FUN_c0958a14(param_1,param_2,param_3);
  return;
}



/* c0958bd4 FUN_c0958bd4 */

/* Boundary evidence: original MIPS .pdata c0958bd4..c0958cf3. Semantic name remains unreviewed. */

void FUN_c0958bd4(UINT param_1,int param_2,int param_3)

{
  LPCRITICAL_SECTION lpCriticalSection;
  undefined4 *_Memory;
  
  DAT_c095a140 = (undefined1)param_3;
  if (param_2 == 0) {
    _Memory = DAT_c095a148;
    if (DAT_c095a148 != (undefined4 *)0x0) {
      while (DAT_c095a144 = DAT_c095a144 + -1, _Memory <= DAT_c095a144) {
        if ((code *)*DAT_c095a144 != (code *)0x0) {
          (*(code *)*DAT_c095a144)();
          _Memory = DAT_c095a148;
        }
      }
      free(_Memory);
      DAT_c095a144 = (undefined4 *)0x0;
      DAT_c095a148 = (undefined4 *)0x0;
    }
    FUN_c0958d18((undefined4 *)&DAT_c0951010,(undefined4 *)&DAT_c0951014);
  }
  FUN_c0958d18((undefined4 *)&DAT_c0951018,(undefined4 *)&DAT_c095101c);
  if (param_3 == 0) {
    TerminateProcess((HANDLE)0x42,param_1);
  }
  else {
    lpCriticalSection = (LPCRITICAL_SECTION)InterlockedExchange((LONG *)&DAT_c095a14c,0);
    if (lpCriticalSection != (LPCRITICAL_SECTION)0x0) {
      DeleteCriticalSection(lpCriticalSection);
      free(lpCriticalSection);
    }
  }
  return;
}



/* c0958cf4 FUN_c0958cf4 */

/* Boundary evidence: original MIPS .pdata c0958cf4..c0958d17. Semantic name remains unreviewed. */

void FUN_c0958cf4(void)

{
  FUN_c0958bd4(0,0,1);
  return;
}



/* c0958d18 FUN_c0958d18 */

/* Boundary evidence: original MIPS .pdata c0958d18..c0958d6b. Semantic name remains unreviewed. */

void FUN_c0958d18(undefined4 *param_1,undefined4 *param_2)

{
  for (; param_1 < param_2; param_1 = param_1 + 1) {
    if ((code *)*param_1 != (code *)0x0) {
      (*(code *)*param_1)();
    }
  }
  return;
}



/* c0958d6c FUN_c0958d6c */

/* Boundary evidence: original MIPS .pdata c0958d6c..c0958da7. Semantic name remains unreviewed. */

void FUN_c0958d6c(void)

{
  FUN_c0958d18((undefined4 *)&DAT_c0951008,(undefined4 *)&DAT_c095100c);
  FUN_c0958d18((undefined4 *)&DAT_c0951000,(undefined4 *)&DAT_c0951004);
  return;
}



/* c0958da8 FUN_c0958da8 */

/* Boundary evidence: original MIPS .pdata c0958da8..c0958e1b. Semantic name remains unreviewed. */

void FUN_c0958da8(void)

{
  uint uVar1;
  
  if ((DAT_c095a0f8 == 0) || (DAT_c095a0f8 == 0xb064)) {
    uVar1 = __security_gen_cookie2();
    DAT_c095a0f8 = uVar1 >> 0x10 ^ uVar1 & 0xffff;
    if (DAT_c095a0f8 == 0) {
      DAT_c095a0f8 = 0xb064;
    }
  }
  DAT_c095a0fc = ~DAT_c095a0f8;
  return;
}


