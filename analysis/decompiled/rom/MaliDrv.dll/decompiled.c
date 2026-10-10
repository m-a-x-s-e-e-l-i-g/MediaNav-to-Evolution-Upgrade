/* Automatic Ghidra pseudocode. Not original source; not runtime-verified. */

/* c0982eb4 FUN_c0982eb4 */

/* Boundary evidence: original MIPS .pdata c0982eb4..c0982fef. Semantic name remains unreviewed. */

int FUN_c0982eb4(HMODULE param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 1;
  if (param_2 == 1) {
    if (DAT_c0996850 != (code *)0x0) {
      iVar2 = (*DAT_c0996850)(param_1,1,param_3);
    }
    iVar1 = 0;
    if (iVar2 == 0) goto LAB_c0982f64;
    FUN_c0983220();
  }
  iVar1 = 0;
  if (iVar2 != 0) {
    iVar1 = FUN_c0991e70(param_1,param_2);
  }
LAB_c0982f64:
  if (((param_2 == 0) && (FUN_c09831a8(), iVar1 != 0)) && (DAT_c0996850 != (code *)0x0)) {
    iVar1 = (*DAT_c0996850)(param_1,0,param_3);
  }
  return iVar1;
}



/* c0982ff0 FUN_c0982ff0 */

/* Boundary evidence: original MIPS .pdata c0982ff0..c098301b. Semantic name remains unreviewed. */

void FUN_c0982ff0(_EXCEPTION_POINTERS *param_1)

{
  _XcptFilter(param_1->ExceptionRecord->ExceptionCode,param_1);
  return;
}



/* c098301c entry */

/* Boundary evidence: original MIPS .pdata c098301c..c0983073. Semantic name remains unreviewed. */

void entry(HMODULE param_1,int param_2,undefined4 param_3)

{
  if (param_2 == 1) {
    FUN_c098325c();
  }
  FUN_c0982eb4(param_1,param_2,param_3);
  return;
}



/* c0983074 FUN_c0983074 */

/* Boundary evidence: original MIPS .pdata c0983074..c09830bb. Semantic name remains unreviewed. */

void FUN_c0983074(uint param_1)

{
  if ((param_1 == DAT_c09960f4) && (param_1 >> 0x10 == 0)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __report_gsfailure();
}



/* c09830bc FUN_c09830bc */

/* Boundary evidence: original MIPS .pdata c09830bc..c09831a7. Semantic name remains unreviewed. */

void FUN_c09830bc(UINT param_1,int param_2,int param_3)

{
  undefined4 *_Memory;
  
  DAT_c099663c = (undefined1)param_3;
  if (param_2 == 0) {
    _Memory = DAT_c099684c;
    if (DAT_c099684c != (undefined4 *)0x0) {
      while (DAT_c0996848 = DAT_c0996848 + -1, _Memory <= DAT_c0996848) {
        if ((code *)*DAT_c0996848 != (code *)0x0) {
          (*(code *)*DAT_c0996848)();
          _Memory = DAT_c099684c;
        }
      }
      free(_Memory);
      DAT_c0996848 = (undefined4 *)0x0;
      DAT_c099684c = (undefined4 *)0x0;
    }
    FUN_c09831cc((undefined4 *)&DAT_c0981010,(undefined4 *)&DAT_c0981014);
  }
  FUN_c09831cc((undefined4 *)&DAT_c0981018,(undefined4 *)&DAT_c098101c);
  if (param_3 == 0) {
    TerminateProcess((HANDLE)0x42,param_1);
  }
  return;
}



/* c09831a8 FUN_c09831a8 */

/* Boundary evidence: original MIPS .pdata c09831a8..c09831cb. Semantic name remains unreviewed. */

void FUN_c09831a8(void)

{
  FUN_c09830bc(0,0,1);
  return;
}



/* c09831cc FUN_c09831cc */

/* Boundary evidence: original MIPS .pdata c09831cc..c098321f. Semantic name remains unreviewed. */

void FUN_c09831cc(undefined4 *param_1,undefined4 *param_2)

{
  for (; param_1 < param_2; param_1 = param_1 + 1) {
    if ((code *)*param_1 != (code *)0x0) {
      (*(code *)*param_1)();
    }
  }
  return;
}



/* c0983220 FUN_c0983220 */

/* Boundary evidence: original MIPS .pdata c0983220..c098325b. Semantic name remains unreviewed. */

void FUN_c0983220(void)

{
  FUN_c09831cc((undefined4 *)&DAT_c0981008,(undefined4 *)&DAT_c098100c);
  FUN_c09831cc((undefined4 *)&DAT_c0981000,(undefined4 *)&DAT_c0981004);
  return;
}



/* c098325c FUN_c098325c */

/* Boundary evidence: original MIPS .pdata c098325c..c09832cf. Semantic name remains unreviewed. */

void FUN_c098325c(void)

{
  uint uVar1;
  
  if ((DAT_c09960f4 == 0) || (DAT_c09960f4 == 0xb064)) {
    uVar1 = __security_gen_cookie2();
    DAT_c09960f4 = uVar1 >> 0x10 ^ uVar1 & 0xffff;
    if (DAT_c09960f4 == 0) {
      DAT_c09960f4 = 0xb064;
    }
  }
  DAT_c09960f8 = ~DAT_c09960f4;
  return;
}



/* c0983350 __malidrv_build_info */

char * __malidrv_build_info(void)

{
                    /* 0x3350  8  __malidrv_build_info */
  return 
  "malidrv:  CONFIG=release USING_ZBT= ONLY_ZBT= USING_OS_MEMORY= API_VERSION=5 REPO_URL=svn://coredev/3rdParty/Mali-r1p1-05rel0/NETLOGIC/MALI/DRIVER REVISION=148 CHANGED_REVISION=142 CHANGED_DATE=2010-06-14 16:29:27 -0500 (Mon, 14 Jun 2010) BUILD_DATE=Wed Jun 16 17:09:20 CDT 2010 BUILD=RELEASE _TGTCPU=MIPSII  _TGTPLAT=DBAU13XX  USING_MMU=1 USING_UMP= USING_MALI200=1 USING_MALI400= USING_MALI400_L2_CACHE= USING_GP2= "
  ;
}



/* c0983378 FUN_c0983378 */

/* Boundary evidence: original MIPS .pdata c0983378..c09833df. Semantic name remains unreviewed. */

void FUN_c0983378(void *param_1)

{
  void *_Memory;
  undefined4 *_Memory_00;
  
  _Memory_00 = *(undefined4 **)((int)param_1 + 0xc);
  free((void *)_Memory_00[1]);
  _Memory = (void *)*_Memory_00;
  CloseHandle(*(HANDLE *)((int)_Memory + 4));
  free(_Memory);
  free(_Memory_00);
  free(param_1);
  return;
}



/* c09833e0 FUN_c09833e0 */

/* Boundary evidence: original MIPS .pdata c09833e0..c09834b3. Semantic name remains unreviewed. */

void FUN_c09833e0(int param_1)

{
  int iVar1;
  int *piVar2;
  undefined4 *puVar3;
  
  puVar3 = *(undefined4 **)(param_1 + 4);
  piVar2 = *(int **)(param_1 + 8);
  iVar1 = FUN_c098be3c((int *)*puVar3);
  if (iVar1 == 0) {
    VirtualFree(*(LPVOID *)(param_1 + 0x14),0,0x8000);
    while (piVar2 != (int *)0x0) {
      iVar1 = *piVar2;
      *piVar2 = puVar3[2];
      puVar3[2] = piVar2;
      piVar2 = (int *)iVar1;
    }
    piVar2 = (int *)*puVar3;
    if ((((-1 < *piVar2) && (*piVar2 < 4)) && (piVar2[2] == 1)) &&
       (iVar1 = __GetUserKData(8), piVar2[3] == iVar1)) {
      piVar2[2] = 0;
      piVar2[3] = 0;
      ReleaseMutex((HANDLE)piVar2[1]);
    }
  }
  return;
}



/* c09834b4 FUN_c09834b4 */

/* Boundary evidence: original MIPS .pdata c09834b4..c09835f7. Semantic name remains unreviewed. */

undefined4 FUN_c09834b4(undefined4 *param_1,undefined4 *param_2)

{
  int iVar1;
  LPVOID pvVar2;
  int *piVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  uint uVar6;
  
  uVar5 = 3;
  iVar1 = FUN_c098be3c((int *)*param_1);
  if (iVar1 == 0) {
    puVar4 = (undefined4 *)param_1[2];
    if (puVar4 == (undefined4 *)0x0) {
      uVar5 = 2;
    }
    else {
      uVar6 = ((int)puVar4 - param_1[1] >> 2) * 0x40000 + param_1[3];
      pvVar2 = FUN_c098b9c0(uVar6,0x40000,"Mali block allocator page tables");
      if (pvVar2 != (LPVOID)0x0) {
        param_2[1] = param_1;
        uVar5 = 0;
        param_2[2] = puVar4;
        param_2[4] = uVar6;
        param_2[3] = 0x40000;
        *param_2 = FUN_c09833e0;
        param_2[5] = pvVar2;
        param_1[2] = *puVar4;
        *puVar4 = 0;
      }
    }
    piVar3 = (int *)*param_1;
    if ((((-1 < *piVar3) && (*piVar3 < 4)) && (piVar3[2] == 1)) &&
       (iVar1 = __GetUserKData(8), piVar3[3] == iVar1)) {
      piVar3[2] = 0;
      piVar3[3] = 0;
      ReleaseMutex((HANDLE)piVar3[1]);
    }
  }
  else {
    uVar5 = 3;
  }
  return uVar5;
}



/* c09835f8 FUN_c09835f8 */

/* Boundary evidence: original MIPS .pdata c09835f8..c09836db. Semantic name remains unreviewed. */

void FUN_c09835f8(undefined4 *param_1,int *param_2)

{
  int iVar1;
  int *piVar2;
  
  piVar2 = (int *)*param_2;
  iVar1 = FUN_c098be3c((int *)*param_1);
  if (iVar1 == 0) {
    FUN_c0983afc((int *)param_2[1],param_2[2],param_2[3],param_2[4],0);
    while (piVar2 != (int *)0x0) {
      iVar1 = *piVar2;
      *piVar2 = param_1[2];
      param_1[2] = piVar2;
      piVar2 = (int *)iVar1;
    }
    piVar2 = (int *)*param_1;
    if ((((-1 < *piVar2) && (*piVar2 < 4)) && (piVar2[2] == 1)) &&
       (iVar1 = __GetUserKData(8), piVar2[3] == iVar1)) {
      piVar2[2] = 0;
      piVar2[3] = 0;
      ReleaseMutex((HANDLE)piVar2[1]);
    }
    free(param_2);
  }
  return;
}



/* c09836dc FUN_c09836dc */

/* Boundary evidence: original MIPS .pdata c09836dc..c09838f7. Semantic name remains unreviewed. */

undefined1
FUN_c09836dc(undefined4 *param_1,int *param_2,int param_3,uint *param_4,undefined4 *param_5)

{
  undefined1 uVar1;
  int iVar2;
  undefined4 *_Memory;
  uint uVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  uint uVar6;
  uint uVar7;
  undefined4 *puVar8;
  
  puVar8 = (undefined4 *)0x0;
  uVar1 = 2;
  uVar7 = *(int *)(param_3 + 8) - *param_4;
  iVar2 = FUN_c098be3c((int *)*param_1);
  if (iVar2 == 0) {
    _Memory = malloc(0x14);
    if (_Memory == (undefined4 *)0x0) {
      FUN_c098bdc8((int *)*param_1);
      uVar1 = 2;
    }
    else {
      _Memory[3] = *param_4;
      _Memory[4] = 0;
      if (uVar7 != 0) {
LAB_c0983790:
        puVar4 = (undefined4 *)param_1[2];
        if (puVar4 != (undefined4 *)0x0) {
          param_1[2] = *puVar4;
          *puVar4 = puVar8;
          uVar3 = *param_4 & 0x3ffff;
          uVar6 = 0x40000 - uVar3;
          if (uVar7 <= uVar6) {
            uVar6 = uVar7;
          }
          iVar2 = FUN_c0983b98(param_2,param_3,*param_4,
                               uVar3 + ((int)puVar4 - param_1[1] >> 2) * 0x40000 + param_1[3],
                               param_1[4],uVar6);
          if (iVar2 == 0) goto code_r0xc0983804;
          uVar1 = 3;
          FUN_c0983afc(param_2,param_3,_Memory[3],_Memory[4],0);
          do {
            puVar5 = (undefined4 *)*puVar4;
            *puVar4 = param_1[2];
            param_1[2] = puVar4;
            puVar4 = puVar5;
            puVar8 = (undefined4 *)0x0;
          } while (puVar5 != (undefined4 *)0x0);
        }
      }
LAB_c0983874:
      FUN_c098bdc8((int *)*param_1);
      if (puVar8 == (undefined4 *)0x0) {
        free(_Memory);
      }
      else {
        uVar1 = uVar7 != 0;
        *_Memory = puVar8;
        _Memory[1] = param_2;
        _Memory[2] = param_3;
        param_5[1] = param_1;
        param_5[2] = _Memory;
        *param_5 = FUN_c09835f8;
      }
    }
  }
  else {
    uVar1 = 3;
  }
  return uVar1;
code_r0xc0983804:
  *param_4 = *param_4 + uVar6;
  uVar7 = uVar7 - uVar6;
  _Memory[4] = uVar6 + _Memory[4];
  puVar8 = puVar4;
  if (uVar7 == 0) goto LAB_c0983874;
  goto LAB_c0983790;
}



/* c09838f8 FUN_c09838f8 */

/* Boundary evidence: original MIPS .pdata c09838f8..c0983a4b. Semantic name remains unreviewed. */

undefined4 * FUN_c09838f8(undefined4 param_1,undefined4 param_2,uint param_3,undefined4 param_4)

{
  undefined4 *_Memory;
  undefined4 *_Memory_00;
  undefined4 *puVar1;
  void *pvVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  
  uVar5 = param_3 >> 0x12;
  if (((param_3 & 0xfffc0000) != 0) && (_Memory = malloc(0x1c), _Memory != (undefined4 *)0x0)) {
    _Memory_00 = malloc(0x18);
    if (_Memory_00 != (undefined4 *)0x0) {
      puVar1 = FUN_c098bcf4(8);
      *_Memory_00 = puVar1;
      if (puVar1 != (undefined4 *)0x0) {
        pvVar2 = malloc(uVar5 << 2);
        _Memory_00[1] = pvVar2;
        if (pvVar2 != (void *)0x0) {
          _Memory_00[2] = 0;
          _Memory_00[5] = uVar5;
          _Memory_00[3] = param_1;
          _Memory_00[4] = param_2;
          if (uVar5 != 0) {
            iVar4 = 0;
            do {
              uVar5 = uVar5 - 1;
              *(undefined4 *)(iVar4 + (int)pvVar2) = _Memory_00[2];
              pvVar2 = (void *)_Memory_00[1];
              iVar3 = iVar4 + (int)pvVar2;
              iVar4 = iVar4 + 4;
              _Memory_00[2] = iVar3;
            } while (uVar5 != 0);
          }
          *_Memory = FUN_c09836dc;
          _Memory[1] = FUN_c09834b4;
          _Memory[2] = FUN_c0983378;
          _Memory[3] = _Memory_00;
          _Memory[4] = param_4;
          return _Memory;
        }
        pvVar2 = (void *)*_Memory_00;
        CloseHandle(*(HANDLE *)((int)pvVar2 + 4));
        free(pvVar2);
      }
      free(_Memory_00);
    }
    free(_Memory);
  }
  return (undefined4 *)0x0;
}



/* c0983a68 FUN_c0983a68 */

/* Boundary evidence: original MIPS .pdata c0983a68..c0983afb. Semantic name remains unreviewed. */

undefined4 FUN_c0983a68(undefined4 param_1,undefined4 param_2,int param_3)

{
  undefined4 uVar1;
  
  while (param_3 != 0) {
    uVar1 = (**(code **)(param_3 + 4))(*(undefined4 *)(param_3 + 0xc),param_2);
    switch(uVar1) {
    case 0:
      return 0;
    case 1:
    case 3:
      return 0xffffffff;
    case 2:
      param_3 = *(int *)(param_3 + 0x18);
    }
  }
  return 0xffffffff;
}



/* c0983afc FUN_c0983afc */

/* Boundary evidence: original MIPS .pdata c0983afc..c0983b97. Semantic name remains unreviewed. */

void FUN_c0983afc(int *param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5)

{
  if ((*(uint *)(param_2 + 0x10) & 1) != 0) {
    (**(code **)(param_1[1] + 0xc))(param_2,param_3,param_4,param_5);
  }
  if (*(code **)(*param_1 + 0xc) != (code *)0x0) {
    (**(code **)(*param_1 + 0xc))(param_2,param_3,param_4,param_5);
  }
  return;
}



/* c0983b98 FUN_c0983b98 */

/* Boundary evidence: original MIPS .pdata c0983b98..c0983cc3. Semantic name remains unreviewed. */

int FUN_c0983b98(int *param_1,int param_2,undefined4 param_3,int param_4,int param_5,
                undefined4 param_6)

{
  int iVar1;
  bool bVar2;
  int local_resc;
  int local_28 [2];
  
  bVar2 = false;
  local_resc = param_4;
  if ((*(uint *)(param_2 + 0x10) & 1) != 0) {
    if (param_4 != -1) {
      local_28[0] = param_4 + param_5;
      iVar1 = (**(code **)(param_1[1] + 8))(param_2,param_3,local_28,param_6);
    }
    else {
      iVar1 = (**(code **)(param_1[1] + 8))(param_2,param_3,&local_resc,param_6);
      local_resc = local_resc - param_5;
    }
    bVar2 = param_4 == -1;
    if (iVar1 != 0) {
      return iVar1;
    }
  }
  iVar1 = (**(code **)(*param_1 + 8))(param_2,param_3,&local_resc,param_6);
  if (iVar1 == 0) {
    iVar1 = 0;
  }
  else if ((*(uint *)(param_2 + 0x10) & 1) != 0) {
    (**(code **)(param_1[1] + 0xc))(param_2,param_3,param_6,bVar2);
  }
  return iVar1;
}



/* c0983cfc FUN_c0983cfc */

/* Boundary evidence: original MIPS .pdata c0983cfc..c0983d17. Semantic name remains unreviewed. */

void FUN_c0983cfc(void *param_1)

{
  free(param_1);
  return;
}



/* c0983d18 FUN_c0983d18 */

/* Boundary evidence: original MIPS .pdata c0983d18..c0983d5f. Semantic name remains unreviewed. */

undefined4 * FUN_c0983d18(void)

{
  undefined4 *puVar1;
  
  puVar1 = malloc(8);
  if (puVar1 == (undefined4 *)0x0) {
    return (undefined4 *)0x0;
  }
  *puVar1 = &PTR_FUN_c0996128;
  puVar1[1] = &PTR_FUN_c0996138;
  return puVar1;
}



/* c0983d8c FUN_c0983d8c */

/* Boundary evidence: original MIPS .pdata c0983d8c..c0983e53. Semantic name remains unreviewed. */

void FUN_c0983d8c(int *param_1,int param_2)

{
  void *_Memory;
  int *piVar1;
  int *piVar2;
  undefined4 *puVar3;
  void *pvVar4;
  
  piVar1 = *(int **)(param_2 + 0x30);
  if (piVar1 != (int *)(param_2 + 0x30)) {
    piVar2 = *(int **)(param_2 + 0x34);
    piVar1[1] = (int)piVar2;
    *piVar2 = (int)piVar1;
  }
  (**(code **)(*param_1 + 4))(param_2);
  for (puVar3 = (undefined4 *)(param_2 + 0x20); puVar3 != (undefined4 *)0x0;
      puVar3 = (undefined4 *)puVar3[3]) {
    (*(code *)*puVar3)(puVar3[1],puVar3[2]);
  }
  _Memory = *(void **)(param_2 + 0x2c);
  while (_Memory != (void *)0x0) {
    pvVar4 = *(void **)((int)_Memory + 0xc);
    free(_Memory);
    _Memory = pvVar4;
  }
  if ((*(uint *)(param_2 + 0x10) & 1) != 0) {
    (**(code **)(param_1[1] + 4))(param_2);
  }
  return;
}



/* c0983e54 FUN_c0983e54 */

/* Boundary evidence: original MIPS .pdata c0983e54..c098402b. Semantic name remains unreviewed. */

undefined4 FUN_c0983e54(int *param_1,int param_2,undefined4 *param_3,int *param_4)

{
  undefined4 *puVar1;
  void *_Memory;
  int iVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  int *piVar5;
  undefined4 *puVar6;
  void *pvVar7;
  undefined4 local_28 [2];
  
  iVar2 = (**(code **)*param_1)(param_2);
  if (iVar2 != 0) {
    return 0xffffffff;
  }
  if (((*(uint *)(param_2 + 0x10) & 1) == 0) ||
     (iVar2 = (**(code **)param_1[1])(param_2), iVar2 == 0)) {
    puVar6 = (undefined4 *)(param_2 + 0x20);
    local_28[0] = 0;
    puVar1 = puVar6;
joined_r0xc0983ecc:
    if (param_3 != (undefined4 *)0x0) goto LAB_c0983ed4;
    goto switchD_c0983f14_caseD_3;
  }
LAB_c0983fcc:
  (**(code **)(*param_1 + 4))(param_2);
  return 0xffffffff;
LAB_c0983ed4:
  uVar3 = (*(code *)*param_3)(param_3[3],param_1,param_2,local_28,puVar1);
  switch(uVar3) {
  case 0:
    goto switchD_c0983f14_caseD_0;
  case 1:
    if (param_3[6] != 0) {
      puVar4 = calloc(1,0x10);
      puVar1[3] = puVar4;
      if (puVar4 != (undefined4 *)0x0) {
        param_3 = (undefined4 *)param_3[6];
        puVar1 = puVar4;
        goto joined_r0xc0983ecc;
      }
    }
  case 3:
switchD_c0983f14_caseD_3:
    for (; puVar6 != (undefined4 *)0x0; puVar6 = (undefined4 *)puVar6[3]) {
      if ((code *)*puVar6 != (code *)0x0) {
        (*(code *)*puVar6)(puVar6[1],puVar6[2]);
      }
    }
    _Memory = *(void **)(param_2 + 0x2c);
    while (_Memory != (void *)0x0) {
      pvVar7 = *(void **)((int)_Memory + 0xc);
      free(_Memory);
      _Memory = pvVar7;
    }
    if ((*(uint *)(param_2 + 0x10) & 1) != 0) {
      (**(code **)(param_1[1] + 4))(param_2);
    }
    break;
  case 2:
    param_3 = (undefined4 *)param_3[6];
  default:
    goto joined_r0xc0983ecc;
  }
  goto LAB_c0983fcc;
switchD_c0983f14_caseD_0:
  if (param_4 != (int *)0x0) {
    iVar2 = *param_4;
    piVar5 = (int *)(param_2 + 0x30);
    *(int **)(iVar2 + 4) = piVar5;
    *piVar5 = iVar2;
    *(int **)(param_2 + 0x34) = param_4;
    *param_4 = (int)piVar5;
  }
  return 0;
}



/* c09841a4 FUN_c09841a4 */

undefined4 FUN_c09841a4(int param_1,uint *param_2)

{
  uint uVar1;
  undefined4 *puVar2;
  uint uVar3;
  undefined4 uVar4;
  
  uVar4 = *(undefined4 *)(param_1 + 0xc);
  if (param_2 != (uint *)0x0) {
    uVar1 = param_2[1];
    puVar2 = (undefined4 *)param_2[3];
    param_2[1] = uVar1 + 8;
    if (puVar2 != (undefined4 *)0x0) {
      uVar3 = *param_2;
      if (uVar3 < 8) {
        return 0xfffffffc;
      }
      *puVar2 = 0;
      puVar2[1] = uVar4;
      param_2[3] = (uint)(puVar2 + 2);
      *param_2 = uVar3 - 8;
    }
    puVar2 = (undefined4 *)param_2[3];
    param_2[1] = uVar1 + 0x10;
    if (puVar2 != (undefined4 *)0x0) {
      uVar3 = *param_2;
      if (uVar3 < 8) {
        return 0xfffffffc;
      }
      *puVar2 = 8;
      puVar2[1] = 4;
      param_2[3] = (uint)(puVar2 + 2);
      *param_2 = uVar3 - 8;
    }
    puVar2 = (undefined4 *)param_2[3];
    param_2[1] = uVar1 + 0x18;
    if (puVar2 != (undefined4 *)0x0) {
      uVar1 = *param_2;
      if (uVar1 < 8) {
        return 0xfffffffc;
      }
      *puVar2 = 8;
      puVar2[1] = 0;
      param_2[3] = (uint)(puVar2 + 2);
      *param_2 = uVar1 - 8;
    }
  }
  return 0;
}



/* c0984280 FUN_c0984280 */

/* Boundary evidence: original MIPS .pdata c0984280..c098430f. Semantic name remains unreviewed. */

undefined4 FUN_c0984280(void *param_1,undefined4 param_2,uint *param_3)

{
  undefined4 *puVar1;
  uint uVar2;
  
  if (param_3 != (uint *)0x0) {
    puVar1 = (undefined4 *)param_3[3];
    param_3[2] = param_3[2] + 0x1004;
    if (puVar1 != (undefined4 *)0x0) {
      uVar2 = *param_3;
      if (uVar2 < 0x1004) {
        return 0xfffffffc;
      }
      *puVar1 = param_2;
      memcpy(puVar1 + 1,param_1,0x1000);
      param_3[3] = (uint)(puVar1 + 0x401);
      *param_3 = uVar2 - 0x1004;
    }
  }
  return 0;
}



/* c0984310 FUN_c0984310 */

/* Boundary evidence: original MIPS .pdata c0984310..c098437f. Semantic name remains unreviewed. */

undefined4 FUN_c0984310(int param_1,int param_2,uint *param_3,int param_4)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  
  uVar2 = *param_3;
  uVar5 = *(int *)(param_1 + 4) + param_2;
  uVar1 = uVar5 + param_4;
  iVar3 = *(int *)(param_1 + 0x18);
  for (; uVar5 < uVar1; uVar5 = uVar5 + 0x1000) {
    uVar4 = uVar2 | 7;
    uVar2 = uVar2 + 0x1000;
    *(uint *)((uVar5 >> 0xc & 0x3ff) * 4 + *(int *)(((uVar5 >> 0x16) + 5) * 4 + iVar3)) = uVar4;
  }
  return 0;
}



/* c0984380 FUN_c0984380 */

/* Boundary evidence: original MIPS .pdata c0984380..c098443f. Semantic name remains unreviewed. */

undefined4 FUN_c0984380(void)

{
  undefined4 *_Memory;
  HANDLE pvVar1;
  
  _Memory = malloc(0x10);
  if (_Memory == (undefined4 *)0x0) {
    _Memory = (undefined4 *)0x0;
  }
  else {
    pvVar1 = CreateMutexW((LPSECURITY_ATTRIBUTES)0x0,0,(LPCWSTR)0x0);
    _Memory[1] = pvVar1;
    if (pvVar1 == (HANDLE)0x0) {
      free(_Memory);
      _Memory = (undefined4 *)0x0;
    }
    else {
      _Memory[2] = 0;
      _Memory[3] = 0;
      *_Memory = 2;
    }
  }
  DAT_c0996740 = _Memory;
  if (_Memory == (undefined4 *)0x0) {
    return 0xffffffff;
  }
  DAT_c0996744 = &DAT_c0996744;
  DAT_c0996748 = &DAT_c0996744;
  DAT_c099674c = &DAT_c099674c;
  DAT_c0996750 = &DAT_c099674c;
  return 0;
}



/* c0984440 FUN_c0984440 */

/* Boundary evidence: original MIPS .pdata c0984440..c09844e3. Semantic name remains unreviewed. */

void FUN_c0984440(undefined4 param_1,undefined4 *param_2)

{
  code *pcVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  
  iVar3 = param_2[1];
  uVar4 = param_2[3];
  uVar5 = param_2[2];
  piVar2 = (int *)*param_2;
  if ((*(uint *)(iVar3 + 0x10) & 1) != 0) {
    (**(code **)(piVar2[1] + 0xc))(iVar3,uVar5,uVar4,0);
  }
  pcVar1 = *(code **)(*piVar2 + 0xc);
  if (pcVar1 != (code *)0x0) {
    (*pcVar1)(iVar3,uVar5,uVar4,0);
  }
  free(param_2);
  return;
}



/* c09844e4 FUN_c09844e4 */

/* Boundary evidence: original MIPS .pdata c09844e4..c09845b3. Semantic name remains unreviewed. */

undefined4
FUN_c09844e4(int *param_1,int *param_2,int param_3,undefined4 *param_4,undefined4 *param_5)

{
  undefined4 *_Memory;
  int iVar1;
  
  _Memory = malloc(0x10);
  if (_Memory != (undefined4 *)0x0) {
    *_Memory = param_2;
    _Memory[1] = param_3;
    _Memory[2] = *param_4;
    _Memory[3] = param_1[1];
    param_5[1] = 0;
    param_5[2] = _Memory;
    param_5[3] = 0;
    *param_5 = FUN_c0984440;
    iVar1 = FUN_c0983b98(param_2,param_3,*param_4,*param_1,0,param_1[1]);
    if (iVar1 == 0) {
      return 0;
    }
    free(_Memory);
  }
  return 3;
}



/* c09845b4 FUN_c09845b4 */

/* Boundary evidence: original MIPS .pdata c09845b4..c09845e7. Semantic name remains unreviewed. */

void FUN_c09845b4(int param_1,int param_2,undefined4 param_3)

{
  if (DAT_c0996798 == 0) {
    *(undefined4 *)(param_2 * 4 + *(int *)(param_1 + 0x10)) = param_3;
  }
  return;
}



/* c09845e8 FUN_c09845e8 */

/* Boundary evidence: original MIPS .pdata c09845e8..c0984627. Semantic name remains unreviewed. */

undefined4 FUN_c09845e8(int param_1,int param_2)

{
  if (DAT_c0996798 != 0) {
    return 0;
  }
  return *(undefined4 *)(param_2 * 4 + *(int *)(param_1 + 0x10));
}



/* c0984628 FUN_c0984628 */

/* Boundary evidence: original MIPS .pdata c0984628..c0984757. Semantic name remains unreviewed. */

undefined4 FUN_c0984628(int param_1,int *param_2,undefined4 param_3,undefined4 param_4)

{
  uint uVar1;
  int local_20 [2];
  
  if (DAT_c0996798 == 0) {
    uVar1 = *(uint *)(*(int *)(param_1 + 0x10) + 0x20);
    if (uVar1 == 0) {
      return 0xffffffff;
    }
    *(undefined4 *)(*(int *)(param_1 + 0x10) + 0x1c) = 0;
    local_20[0] = *(int *)(param_1 + 0x10);
    if ((uVar1 & 1) != 0) {
      FUN_c098b68c("Mali: ",param_2,param_3,param_4);
      FUN_c098b68c("Page fault on %s\n",*(undefined4 *)(param_1 + 4),param_3,param_4);
      local_20[0] = *(int *)(param_1 + 0x20);
      param_4 = 0;
      param_3 = 4;
      param_2 = local_20;
      WriteMsgQueue(*(undefined4 *)(local_20[0] + 4));
    }
    if ((uVar1 & 2) != 0) {
      FUN_c098b68c("Mali: ",param_2,param_3,param_4);
      FUN_c098b68c("Bus read error on %s\n",*(undefined4 *)(param_1 + 4),param_3,param_4);
      if (DAT_c0996798 == 0) {
        *(undefined4 *)(*(int *)(param_1 + 0x10) + 0x18) = 2;
        *(uint *)(*(int *)(param_1 + 0x10) + 0x1c) = *(uint *)(*(int *)(param_1 + 0x10) + 0x1c) | 2;
      }
    }
  }
  return 0;
}



/* c0984758 FUN_c0984758 */

/* Boundary evidence: original MIPS .pdata c0984758..c09847b7. Semantic name remains unreviewed. */

undefined4 FUN_c0984758(int param_1)

{
  LPVOID lpAddress;
  
  lpAddress = FUN_c098b9c0(*(int *)(param_1 + 8) + 0x1000,8,"fpga framework");
  if (lpAddress != (LPVOID)0x0) {
    VirtualFree(lpAddress,0,0x8000);
  }
  return 0;
}



/* c09847b8 FUN_c09847b8 */

/* Boundary evidence: original MIPS .pdata c09847b8..c098482b. Semantic name remains unreviewed. */

undefined4 FUN_c09847b8(int param_1)

{
  undefined4 *puVar1;
  
  *(undefined4 *)(param_1 + 8) = 1;
  puVar1 = calloc(1,0x14);
  if (puVar1 == (undefined4 *)0x0) {
    return 0xfffffffc;
  }
  *puVar1 = 0x80000000;
  puVar1[2] = 0x1e;
  puVar1[1] = 0x3f;
  puVar1[3] = 0;
  *(undefined4 **)(param_1 + 4) = puVar1;
  return 0;
}



/* c098482c FUN_c098482c */

/* Boundary evidence: original MIPS .pdata c098482c..c098485b. Semantic name remains unreviewed. */

undefined4 FUN_c098482c(int param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  int iVar2;
  
  iVar2 = 0;
  do {
    puVar1 = (undefined4 *)(param_1 + iVar2);
    iVar2 = iVar2 + 4;
    *puVar1 = param_2;
  } while (iVar2 < 0x1000);
  return 0;
}



/* c0984958 FUN_c0984958 */

/* Boundary evidence: original MIPS .pdata c0984958..c0984abb. Semantic name remains unreviewed. */

undefined4 FUN_c0984958(int param_1,uint *param_2)

{
  void *pvVar1;
  undefined4 *puVar2;
  uint *puVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  
  pvVar1 = *(void **)(param_1 + 0x10);
  if (pvVar1 != (void *)0x0) {
    if (param_2 != (uint *)0x0) {
      puVar2 = (undefined4 *)param_2[3];
      param_2[2] = param_2[2] + 0x1004;
      if (puVar2 != (undefined4 *)0x0) {
        uVar4 = *param_2;
        if (uVar4 < 0x1004) {
          return 0xfffffffc;
        }
        *puVar2 = *(undefined4 *)(param_1 + 0xc);
        memcpy(puVar2 + 1,pvVar1,0x1000);
        param_2[3] = (uint)(puVar2 + 0x401);
        *param_2 = uVar4 - 0x1004;
      }
    }
    iVar5 = 0;
    puVar2 = (undefined4 *)(param_1 + 0x14);
    do {
      pvVar1 = (void *)*puVar2;
      if ((pvVar1 != (void *)0x0) &&
         (uVar4 = *(uint *)(*(int *)(param_1 + 0x10) + (-0x14 - param_1) + (int)puVar2),
         param_2 != (uint *)0x0)) {
        puVar3 = (uint *)param_2[3];
        param_2[2] = param_2[2] + 0x1004;
        if (puVar3 != (uint *)0x0) {
          uVar6 = *param_2;
          if (uVar6 < 0x1004) {
            return 0xfffffffc;
          }
          *puVar3 = uVar4 & 0xfffffff8;
          memcpy(puVar3 + 1,pvVar1,0x1000);
          param_2[3] = (uint)(puVar3 + 0x401);
          *param_2 = uVar6 - 0x1004;
        }
      }
      iVar5 = iVar5 + 1;
      puVar2 = puVar2 + 1;
    } while (iVar5 < 0x400);
  }
  return 0;
}



/* c0984abc FUN_c0984abc */

/* Boundary evidence: original MIPS .pdata c0984abc..c0984b53. Semantic name remains unreviewed. */

undefined4 FUN_c0984abc(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  
  iVar1 = DAT_c0996798;
  if (DAT_c0996798 == 0) {
    uVar3 = *(uint *)(*(int *)(param_1 + 0x10) + 0x20);
  }
  else {
    uVar3 = 0;
  }
  if (((uVar3 & 1) != 0) && (DAT_c0996798 == 0)) {
    *(undefined4 *)(*(int *)(param_1 + 0x10) + 0x18) = 1;
  }
  if (((uVar3 & 2) != 0) && (iVar1 == 0)) {
    *(undefined4 *)(*(int *)(param_1 + 0x10) + 0x18) = 2;
  }
  uVar2 = 0;
  if ((uVar3 & 3) != 3) {
    uVar2 = 0xffffffff;
  }
  return uVar2;
}



/* c0984b54 FUN_c0984b54 */

/* Boundary evidence: original MIPS .pdata c0984b54..c0984b83. Semantic name remains unreviewed. */

void FUN_c0984b54(int param_1)

{
  if (DAT_c0996798 == 0) {
    *(undefined4 *)(*(int *)(param_1 + 0x10) + 0x14) = 3;
  }
  return;
}



/* c0984b84 FUN_c0984b84 */

/* Boundary evidence: original MIPS .pdata c0984b84..c0984d8f. Semantic name remains unreviewed. */

void FUN_c0984b84(int param_1)

{
  int *piVar1;
  DWORD DVar2;
  int *piVar3;
  uint uVar4;
  void *_Memory;
  int *piVar5;
  int iVar6;
  int iVar7;
  int *piVar8;
  
  _Memory = *(void **)(param_1 + 0xc);
  iVar7 = *(int *)((int)_Memory + 0x18);
  FUN_c0983d8c(DAT_c099683c,(int)_Memory);
  free(_Memory);
  piVar8 = (int *)(iVar7 + 0x2014);
  piVar3 = (int *)*piVar8;
  piVar5 = (int *)*piVar3;
  iVar7 = DAT_c0996798;
  do {
    piVar1 = piVar5;
    if (piVar3 == piVar8) {
      return;
    }
    piVar5 = (int *)piVar3[-6];
    if (((-1 < *piVar5) && (*piVar5 < 4)) &&
       (DVar2 = WaitForSingleObject((HANDLE)piVar5[1],0xffffffff), iVar7 = DAT_c0996798, DVar2 == 0)
       ) {
      if (piVar5[2] == 1) {
        ReleaseMutex((HANDLE)piVar5[1]);
        iVar7 = DAT_c0996798;
      }
      else {
        piVar5[2] = 1;
        iVar7 = __GetUserKData(8);
        piVar5[3] = iVar7;
        iVar7 = DAT_c0996798;
      }
    }
    if (iVar7 == 0) {
      iVar6 = 0;
      *(undefined4 *)(piVar3[-0xc] + 8) = 2;
      do {
        if (iVar7 == 0) {
          uVar4 = *(uint *)(piVar3[-0xc] + 4);
        }
        else {
          uVar4 = 0;
        }
        if ((uVar4 & 4) != 0) break;
        StallExecution(1);
        iVar6 = iVar6 + 1;
        iVar7 = DAT_c0996798;
      } while (iVar6 < 100);
      if (iVar7 == 0) {
        *(undefined4 *)(piVar3[-0xc] + 8) = 4;
        *(undefined4 *)(piVar3[-0xc] + 8) = 3;
      }
    }
    piVar3 = (int *)piVar3[-6];
    if (((-1 < *piVar3) && (*piVar3 < 4)) &&
       ((piVar3[2] == 1 && (iVar6 = __GetUserKData(8), iVar7 = DAT_c0996798, piVar3[3] == iVar6))))
    {
      piVar3[2] = 0;
      piVar3[3] = 0;
      ReleaseMutex((HANDLE)piVar3[1]);
      iVar7 = DAT_c0996798;
    }
    piVar5 = (int *)*piVar1;
    piVar3 = piVar1;
  } while( true );
}



/* c0984d90 FUN_c0984d90 */

/* Boundary evidence: original MIPS .pdata c0984d90..c0984fcf. Semantic name remains unreviewed. */

undefined4 FUN_c0984d90(int *param_1)

{
  int *piVar1;
  int *piVar2;
  int *_Memory;
  int *piVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  
  if ((param_1 == (int *)0x0) || (*param_1 == 0)) {
    return 0xfffffffd;
  }
  if ((DAT_c0996148 < 5) && (piVar7 = *(int **)(DAT_c0996148 * 4 + *param_1), piVar7 != (int *)0x0))
  {
    _Memory = calloc(1,0x38);
    if (_Memory == (int *)0x0) {
      return 0xfffffffc;
    }
    iVar5 = param_1[3];
    iVar6 = param_1[6];
    _Memory[2] = param_1[2];
    piVar3 = _Memory + 0xc;
    _Memory[1] = iVar5;
    _Memory[6] = (int)piVar7;
    _Memory[7] = iVar6;
    _Memory[4] = 1;
    _Memory[5] = *piVar7;
    *piVar3 = (int)piVar3;
    _Memory[0xd] = (int)piVar3;
    FUN_c098be3c((int *)*piVar7);
    iVar5 = FUN_c0983e54(DAT_c099683c,(int)_Memory,DAT_c0996840,piVar7 + 0x807);
    if (iVar5 == 0) {
      piVar3 = (int *)piVar7[0x805];
      piVar2 = (int *)*piVar3;
      while (piVar1 = piVar2, piVar3 != piVar7 + 0x805) {
        FUN_c098be3c((int *)piVar3[-6]);
        iVar5 = DAT_c0996798;
        if (DAT_c0996798 == 0) {
          *(undefined4 *)(piVar3[-0xc] + 8) = 2;
          while( true ) {
            if (iVar5 == 0) {
              uVar4 = *(uint *)(piVar3[-0xc] + 4);
            }
            else {
              uVar4 = 0;
            }
            if ((uVar4 & 4) != 0) break;
            StallExecution(1);
            iVar5 = DAT_c0996798;
          }
          if (iVar5 == 0) {
            *(undefined4 *)(piVar3[-0xc] + 8) = 4;
            *(undefined4 *)(piVar3[-0xc] + 8) = 3;
          }
        }
        FUN_c098bdc8((int *)piVar3[-6]);
        piVar2 = (int *)*piVar1;
        piVar3 = piVar1;
      }
      FUN_c098bdc8((int *)*piVar7);
      param_1[1] = *_Memory;
      param_1[4] = (int)_Memory;
      return 0;
    }
    FUN_c098bdc8((int *)*piVar7);
    free(_Memory);
  }
  return 0xffffffff;
}



/* c0984fd0 FUN_c0984fd0 */

/* Boundary evidence: original MIPS .pdata c0984fd0..c098509f. Semantic name remains unreviewed. */

void FUN_c0984fd0(int param_1)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  
  FUN_c098be3c(*(int **)(param_1 + 0x28));
  piVar3 = *(int **)(param_1 + 0x34);
  piVar4 = (int *)*piVar3;
  do {
    piVar1 = piVar4;
    if (piVar3 == (int *)(param_1 + 0x34)) {
LAB_c0985038:
      piVar3 = *(int **)(param_1 + 0x28);
      if ((((-1 < *piVar3) && (*piVar3 < 4)) && (piVar3[2] == 1)) &&
         (iVar2 = __GetUserKData(8), piVar3[3] == iVar2)) {
        piVar3[2] = 0;
        piVar3[3] = 0;
        ReleaseMutex((HANDLE)piVar3[1]);
      }
      return;
    }
    if ((code *)piVar3[2] == FUN_c098d09c) {
      iVar2 = *piVar3;
      piVar4 = (int *)piVar3[1];
      *(int **)(iVar2 + 4) = piVar4;
      *piVar4 = iVar2;
      free(piVar3);
      goto LAB_c0985038;
    }
    piVar4 = (int *)*piVar1;
    piVar3 = piVar1;
  } while( true );
}



/* c09850a0 FUN_c09850a0 */

/* Boundary evidence: original MIPS .pdata c09850a0..c0985183. Semantic name remains unreviewed. */

void FUN_c09850a0(int param_1,undefined4 param_2)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = DAT_c0996798;
  if (DAT_c0996798 == 0) {
    iVar3 = 0;
    *(undefined4 *)(*(int *)(param_1 + 0x10) + 8) = 2;
    do {
      if (iVar2 == 0) {
        uVar1 = *(uint *)(*(int *)(param_1 + 0x10) + 4);
      }
      else {
        uVar1 = 0;
      }
      if ((uVar1 & 4) != 0) break;
      StallExecution(10);
      iVar3 = iVar3 + 1;
      iVar2 = DAT_c0996798;
    } while (iVar3 < 10);
    if (iVar2 == 0) {
      **(undefined4 **)(param_1 + 0x10) = param_2;
      *(undefined4 *)(*(int *)(param_1 + 0x10) + 8) = 4;
      *(undefined4 *)(*(int *)(param_1 + 0x10) + 8) = 3;
    }
  }
  return;
}



/* c0985184 FUN_c0985184 */

/* Boundary evidence: original MIPS .pdata c0985184..c098525f. Semantic name remains unreviewed. */

void FUN_c0985184(void)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  
  piVar3 = (int *)*DAT_c0996744;
  piVar2 = DAT_c0996744;
  while (piVar1 = piVar3, (int **)piVar2 != &DAT_c0996744) {
    iVar4 = *piVar2;
    piVar3 = (int *)piVar2[1];
    *(int **)(iVar4 + 4) = piVar3;
    *piVar3 = iVar4;
    (*(code *)piVar2[5])(piVar2 + 5);
    free((void *)piVar2[2]);
    free(piVar2);
    piVar3 = (int *)*piVar1;
    piVar2 = piVar1;
  }
  piVar3 = (int *)*DAT_c099674c;
  piVar2 = DAT_c099674c;
  while (piVar1 = piVar3, (int **)piVar2 != &DAT_c099674c) {
    iVar4 = *piVar2;
    piVar3 = (int *)piVar2[1];
    *(int **)(iVar4 + 4) = piVar3;
    *piVar3 = iVar4;
    (*(code *)piVar2[5])(piVar2 + 5);
    free((void *)piVar2[2]);
    free(piVar2);
    piVar3 = (int *)*piVar1;
    piVar2 = piVar1;
  }
  return;
}



/* c0985260 FUN_c0985260 */

/* Boundary evidence: original MIPS .pdata c0985260..c098533f. Semantic name remains unreviewed. */

undefined4 FUN_c0985260(int param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  int *piVar4;
  uint uVar5;
  
  uVar5 = *(uint *)(param_1 + 0x20);
  puVar1 = FUN_c09838f8(*(undefined4 *)(param_1 + 8),*(undefined4 *)(param_1 + 0xc),
                        *(uint *)(param_1 + 0x10),*(undefined4 *)(param_1 + 4));
  if (puVar1 != (undefined4 *)0x0) {
    puVar1[5] = uVar5;
    puVar2 = malloc(0xc);
    if (puVar2 != (undefined4 *)0x0) {
      *puVar2 = *(undefined4 *)(param_1 + 8);
      piVar4 = &DAT_c0996840;
      puVar2[1] = *(undefined4 *)(param_1 + 0x10);
      puVar2[2] = DAT_c0996844;
      iVar3 = DAT_c0996840;
      while ((iVar3 != 0 && (*(uint *)(*piVar4 + 0x14) < uVar5))) {
        piVar4 = (int *)(*piVar4 + 0x18);
        iVar3 = *piVar4;
      }
      DAT_c0996844 = puVar2;
      puVar1[6] = *piVar4;
      *piVar4 = (int)puVar1;
      return 0;
    }
    (*(code *)puVar1[2])(puVar1);
  }
  return 0xffffffff;
}



/* c0985340 FUN_c0985340 */

/* Boundary evidence: original MIPS .pdata c0985340..c09853d7. Semantic name remains unreviewed. */

undefined4 FUN_c0985340(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  int *piVar3;
  uint uVar4;
  
  uVar4 = *(uint *)(param_1 + 0x20);
  puVar1 = FUN_c0993ed4(*(int *)(param_1 + 0x10),*(undefined4 *)(param_1 + 0xc),
                        *(undefined4 *)(param_1 + 4));
  if (puVar1 != (undefined4 *)0x0) {
    piVar3 = &DAT_c0996840;
    puVar1[5] = uVar4;
    iVar2 = DAT_c0996840;
    while ((iVar2 != 0 && (*(uint *)(*piVar3 + 0x14) < uVar4))) {
      piVar3 = (int *)(*piVar3 + 0x18);
      iVar2 = *piVar3;
    }
    puVar1[6] = *piVar3;
    *piVar3 = (int)puVar1;
    return 0;
  }
  return 0xffffffff;
}



/* c09853d8 FUN_c09853d8 */

/* Boundary evidence: original MIPS .pdata c09853d8..c098540f. Semantic name remains unreviewed. */

void FUN_c09853d8(undefined4 param_1,void *param_2)

{
  FUN_c0983d8c(DAT_c099683c,(int)param_2);
  free(param_2);
  return;
}



/* c0985438 FUN_c0985438 */

uint FUN_c0985438(uint *param_1,uint param_2)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = 0;
  if (param_2 != 0) {
    while (iVar2 = 0x1f - LZCOUNT(-~*param_1 & ~*param_1), iVar2 < 0) {
      uVar1 = uVar1 + 0x20;
      prefetch(param_1 + 2,0);
      param_1 = param_1 + 1;
      if (param_2 <= uVar1) {
        return param_2;
      }
    }
    uVar1 = iVar2 + uVar1;
    if (uVar1 < param_2) {
      return uVar1;
    }
  }
  return param_2;
}



/* c09854a0 FUN_c09854a0 */

/* Boundary evidence: original MIPS .pdata c09854a0..c098557f. Semantic name remains unreviewed. */

int FUN_c09854a0(int *param_1)

{
  int iVar1;
  int iVar2;
  uint local_20;
  int local_1c;
  int local_18;
  int local_14;
  
  local_1c = 0;
  local_18 = 0;
  if ((*param_1 != 0) && (local_14 = param_1[2], local_14 != 0)) {
    if (DAT_c0996148 < 5) {
      iVar2 = *(int *)(DAT_c0996148 * 4 + *param_1);
    }
    else {
      iVar2 = 0;
    }
    local_20 = param_1[1];
    param_1[4] = local_14;
    iVar1 = FUN_c09841a4(iVar2,&local_20);
    if (iVar1 == 0) {
      param_1[6] = local_14;
      iVar1 = FUN_c0984958(iVar2,&local_20);
      if (iVar1 == 0) {
        iVar1 = 0;
        param_1[3] = local_1c;
        param_1[5] = local_18;
      }
    }
    return iVar1;
  }
  return -3;
}



/* c0985580 FUN_c0985580 */

/* Boundary evidence: original MIPS .pdata c0985580..c0985637. Semantic name remains unreviewed. */

int FUN_c0985580(int *param_1)

{
  int iVar1;
  int iVar2;
  uint local_20;
  int local_1c;
  int local_18;
  undefined4 local_14;
  
  local_20 = 0;
  local_1c = 0;
  local_18 = 0;
  local_14 = 0;
  if (*param_1 == 0) {
    return -3;
  }
  if (DAT_c0996148 < 5) {
    iVar2 = *(int *)(DAT_c0996148 * 4 + *param_1);
  }
  else {
    iVar2 = 0;
  }
  iVar1 = FUN_c09841a4(iVar2,&local_20);
  if ((iVar1 == 0) && (iVar1 = FUN_c0984958(iVar2,&local_20), iVar1 == 0)) {
    iVar1 = 0;
    param_1[1] = local_18 + local_1c;
  }
  return iVar1;
}



/* c0985638 FUN_c0985638 */

/* Boundary evidence: original MIPS .pdata c0985638..c09856e3. Semantic name remains unreviewed. */

undefined4 FUN_c0985638(int param_1)

{
  int iVar1;
  int *piVar2;
  
  piVar2 = *(int **)(*(int *)(param_1 + 0xc) + 0x14);
  if (piVar2 != (int *)0x0) {
    FUN_c098be3c(piVar2);
  }
  FUN_c0984b84(param_1);
  if ((((piVar2 != (int *)0x0) && (-1 < *piVar2)) && (*piVar2 < 4)) &&
     ((piVar2[2] == 1 && (iVar1 = __GetUserKData(8), piVar2[3] == iVar1)))) {
    piVar2[2] = 0;
    piVar2[3] = 0;
    ReleaseMutex((HANDLE)piVar2[1]);
  }
  return 0;
}



/* c09856e4 FUN_c09856e4 */

/* Boundary evidence: original MIPS .pdata c09856e4..c09858df. Semantic name remains unreviewed. */

void FUN_c09856e4(int param_1)

{
  bool bVar1;
  int ***pppiVar2;
  int *piVar3;
  int ***pppiVar4;
  int iVar5;
  int ****ppppiVar6;
  int ****ppppiVar7;
  undefined4 *puVar8;
  int *piVar9;
  int ***local_18;
  int ***local_14;
  
  puVar8 = *(undefined4 **)(param_1 + 0x2c);
  if (puVar8 != (undefined4 *)0x0) {
    FUN_c098be3c((int *)*puVar8);
  }
  FUN_c098be3c(*(int **)(param_1 + 0x28));
  iVar5 = *(int *)(param_1 + 0x30) + -1;
  *(int *)(param_1 + 0x30) = iVar5;
  if (iVar5 == 0) {
    FUN_c09850a0(param_1,DAT_c0996124);
    piVar9 = (int *)(param_1 + 0x40);
    iVar5 = *piVar9;
    piVar3 = *(int **)(param_1 + 0x44);
    local_14 = (int ***)&local_18;
    *(int **)(iVar5 + 4) = piVar3;
    *piVar3 = iVar5;
    ppppiVar6 = (int ****)(param_1 + 0x34);
    *piVar9 = (int)piVar9;
    *(int **)(param_1 + 0x44) = piVar9;
    *(undefined4 *)(param_1 + 0x2c) = 0;
    ppppiVar7 = (int ****)*ppppiVar6;
    local_18 = (int ***)&local_18;
    if (ppppiVar7 != ppppiVar6) {
      local_14 = *(int ****)(param_1 + 0x38);
      ppppiVar7[1] = (int ***)&local_18;
      *local_14 = (int **)&local_18;
      local_18 = (int ***)ppppiVar7;
    }
    *ppppiVar6 = (int ***)ppppiVar6;
    *(int *****)(param_1 + 0x38) = ppppiVar6;
    piVar9 = *(int **)(param_1 + 0x28);
    if ((((-1 < *piVar9) && (*piVar9 < 4)) && (piVar9[2] == 1)) &&
       (iVar5 = __GetUserKData(8), piVar9[3] == iVar5)) {
      piVar9[2] = 0;
      piVar9[3] = 0;
      ReleaseMutex((HANDLE)piVar9[1]);
    }
    if (puVar8 != (undefined4 *)0x0) {
      FUN_c098bdc8((int *)*puVar8);
    }
    ppppiVar6 = (int ****)local_18;
    ppppiVar7 = (int ****)*local_18;
    if ((int ****)local_18 != &local_18) {
      do {
        (*(code *)ppppiVar6[2])(ppppiVar6[3]);
        pppiVar2 = *ppppiVar6;
        pppiVar4 = ppppiVar6[1];
        pppiVar2[1] = (int **)pppiVar4;
        *pppiVar4 = (int **)pppiVar2;
        free(ppppiVar6);
        bVar1 = ppppiVar7 != &local_18;
        ppppiVar6 = ppppiVar7;
        ppppiVar7 = (int ****)*ppppiVar7;
      } while (bVar1);
    }
  }
  else {
    piVar9 = *(int **)(param_1 + 0x28);
    if (((-1 < *piVar9) && (*piVar9 < 4)) &&
       ((piVar9[2] == 1 && (iVar5 = __GetUserKData(8), piVar9[3] == iVar5)))) {
      piVar9[2] = 0;
      piVar9[3] = 0;
      ReleaseMutex((HANDLE)piVar9[1]);
    }
    if (puVar8 != (undefined4 *)0x0) {
      FUN_c098bdc8((int *)*puVar8);
      return;
    }
  }
  return;
}



/* c09858e0 FUN_c09858e0 */

/* Boundary evidence: original MIPS .pdata c09858e0..c0985aff. Semantic name remains unreviewed. */

undefined4 FUN_c09858e0(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int *piVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 *puVar4;
  int *piVar5;
  int *piVar6;
  int *piVar7;
  undefined4 *puVar8;
  undefined4 uVar9;
  
  uVar9 = 0xffffffff;
  if (DAT_c0996148 < 5) {
    if (param_2 == 0) {
      puVar8 = (undefined4 *)0x0;
    }
    else {
      puVar8 = *(undefined4 **)(DAT_c0996148 * 4 + param_2);
    }
  }
  else {
    puVar8 = (undefined4 *)0x0;
  }
  FUN_c098be3c((int *)*puVar8);
  FUN_c098be3c(*(int **)(param_1 + 0x28));
  if (*(int *)(param_1 + 0x30) == 0) {
    *(undefined4 **)(param_1 + 0x2c) = puVar8;
    *(undefined4 *)(param_1 + 0x30) = 1;
    FUN_c09850a0(param_1,puVar8[3]);
    piVar7 = puVar8 + 0x805;
    iVar3 = *piVar7;
    piVar5 = (int *)(param_1 + 0x40);
    uVar9 = 0;
    *(int **)(iVar3 + 4) = piVar5;
    *piVar5 = iVar3;
    *(int **)(param_1 + 0x44) = piVar7;
    *piVar7 = (int)piVar5;
  }
  else if ((puVar8 == *(undefined4 **)(param_1 + 0x2c)) && ((*(uint *)(param_1 + 0x24) & 1) == 0)) {
    uVar9 = 0;
    *(int *)(param_1 + 0x30) = *(int *)(param_1 + 0x30) + 1;
  }
  else {
    piVar6 = (int *)(param_1 + 0x34);
    piVar5 = *(int **)*piVar6;
    piVar7 = (undefined4 *)*piVar6;
    while (piVar1 = piVar5, piVar7 != piVar6) {
      if ((code *)piVar7[2] == FUN_c098d09c) goto LAB_c0985a30;
      piVar5 = (int *)*piVar1;
      piVar7 = piVar1;
    }
    puVar2 = malloc(0x10);
    if (puVar2 != (undefined4 *)0x0) {
      puVar2[2] = FUN_c098d09c;
      puVar2[3] = param_4;
      puVar4 = *(undefined4 **)(param_1 + 0x38);
      *(undefined4 **)(param_1 + 0x38) = puVar2;
      *puVar2 = piVar6;
      puVar2[1] = puVar4;
      *puVar4 = puVar2;
LAB_c0985a30:
      uVar9 = 0xfffffff8;
    }
  }
  piVar7 = *(int **)(param_1 + 0x28);
  if ((((-1 < *piVar7) && (*piVar7 < 4)) && (piVar7[2] == 1)) &&
     (iVar3 = __GetUserKData(8), piVar7[3] == iVar3)) {
    piVar7[2] = 0;
    piVar7[3] = 0;
    ReleaseMutex((HANDLE)piVar7[1]);
  }
  piVar7 = (int *)*puVar8;
  if (((-1 < *piVar7) && (*piVar7 < 4)) &&
     ((piVar7[2] == 1 && (iVar3 = __GetUserKData(8), piVar7[3] == iVar3)))) {
    piVar7[2] = 0;
    piVar7[3] = 0;
    ReleaseMutex((HANDLE)piVar7[1]);
  }
  return uVar9;
}



/* c0985b00 FUN_c0985b00 */

/* Boundary evidence: original MIPS .pdata c0985b00..c0985db3. Semantic name remains unreviewed. */

void FUN_c0985b00(uint param_1)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  uint *puVar5;
  uint uVar6;
  
  FUN_c098be3c(DAT_c0996740);
  piVar4 = (int *)*DAT_c0996744;
  piVar2 = DAT_c0996744;
  while (piVar1 = piVar4, (int **)piVar2 != &DAT_c0996744) {
    uVar6 = piVar2[9];
    if ((uVar6 <= param_1) && (param_1 <= (piVar2[4] + -1) * 0x1000 + uVar6)) {
      puVar5 = (uint *)((param_1 - uVar6 >> 0x11) * 4 + piVar2[2]);
      *puVar5 = ~(1 << (param_1 - uVar6 >> 0xc & 0x1f)) & *puVar5;
      piVar2[3] = piVar2[3] + -1;
      memset((void *)((piVar2[10] - uVar6) + param_1),0,0x1000);
      if (piVar2[3] == 0) {
        piVar4 = (int *)piVar2[1];
        iVar3 = *piVar2;
        *(int **)(iVar3 + 4) = piVar4;
        *piVar4 = iVar3;
        (*(code *)piVar2[5])(piVar2 + 5);
        free((void *)piVar2[2]);
        free(piVar2);
      }
      if (*DAT_c0996740 < 0) {
        return;
      }
      if (3 < *DAT_c0996740) {
        return;
      }
      iVar3 = DAT_c0996740[2];
      goto joined_r0xc0985cf4;
    }
    piVar4 = (int *)*piVar1;
    piVar2 = piVar1;
  }
  piVar4 = (int *)*DAT_c099674c;
  piVar2 = DAT_c099674c;
  do {
    piVar1 = piVar4;
    if ((int **)piVar2 == &DAT_c099674c) {
      if (((-1 < *DAT_c0996740) && (*DAT_c0996740 < 4)) && (DAT_c0996740[2] == 1)) {
LAB_c0985bf4:
        piVar2 = DAT_c0996740;
        iVar3 = __GetUserKData(8);
        if (piVar2[3] == iVar3) {
          piVar2[2] = 0;
          piVar2[3] = 0;
          ReleaseMutex((HANDLE)piVar2[1]);
        }
      }
      return;
    }
    uVar6 = piVar2[9];
    if ((uVar6 <= param_1) && (param_1 <= (piVar2[4] + -1) * 0x1000 + uVar6)) {
      puVar5 = (uint *)((param_1 - uVar6 >> 0x11) * 4 + piVar2[2]);
      *puVar5 = ~(1 << (param_1 - uVar6 >> 0xc & 0x1f)) & *puVar5;
      piVar2[3] = piVar2[3] + -1;
      memset((void *)((piVar2[10] - uVar6) + param_1),0,0x1000);
      piVar4 = (int *)piVar2[1];
      iVar3 = *piVar2;
      *(int **)(iVar3 + 4) = piVar4;
      *piVar4 = iVar3;
      DAT_c0996744[1] = (int)piVar2;
      *piVar2 = (int)DAT_c0996744;
      piVar2[1] = (int)&DAT_c0996744;
      if (*DAT_c0996740 < 0) {
        DAT_c0996744 = piVar2;
        return;
      }
      if (3 < *DAT_c0996740) {
        DAT_c0996744 = piVar2;
        return;
      }
      iVar3 = DAT_c0996740[2];
      DAT_c0996744 = piVar2;
joined_r0xc0985cf4:
      if (iVar3 != 1) {
        return;
      }
      goto LAB_c0985bf4;
    }
    piVar4 = (int *)*piVar1;
    piVar2 = piVar1;
  } while( true );
}



/* c0985db4 FUN_c0985db4 */

/* Boundary evidence: original MIPS .pdata c0985db4..c098604b. Semantic name remains unreviewed. */

undefined4 FUN_c0985db4(int *param_1,int *param_2)

{
  uint uVar1;
  int *piVar2;
  void *pvVar3;
  undefined4 uVar4;
  int *piVar5;
  int iVar6;
  undefined4 *puVar7;
  int iVar8;
  uint *puVar9;
  
  FUN_c098be3c(DAT_c0996740);
  piVar2 = DAT_c0996744;
  if ((int **)DAT_c0996744 == &DAT_c0996744) {
    piVar2 = calloc(1,0x2c);
    if (piVar2 == (int *)0x0) {
      FUN_c098bdc8(DAT_c0996740);
      *param_1 = -1;
      return 0xfffffffc;
    }
    *piVar2 = (int)piVar2;
    piVar5 = piVar2 + 5;
    piVar2[1] = (int)piVar2;
    iVar6 = FUN_c0983a68(DAT_c099683c,piVar5,DAT_c0996840);
    if (iVar6 == 0) {
      piVar2[4] = (uint)piVar2[8] >> 0xc;
      piVar2[3] = 1;
      pvVar3 = calloc(1,(((uint)piVar2[8] >> 0xc) + 0x1f) * 4);
      piVar2[2] = (int)pvVar3;
      if (pvVar3 != (void *)0x0) {
        iVar6 = piVar2[10];
        iVar8 = 0;
        do {
          puVar7 = (undefined4 *)(iVar6 + iVar8);
          iVar8 = iVar8 + 4;
          *puVar7 = 0;
        } while (iVar8 < 0x1000);
        *(uint *)piVar2[2] = *(uint *)piVar2[2] | 1;
        DAT_c0996744[1] = (int)piVar2;
        *piVar2 = (int)DAT_c0996744;
        piVar2[1] = (int)&DAT_c0996744;
        DAT_c0996744 = piVar2;
        FUN_c098bdc8(DAT_c0996740);
        *param_1 = piVar2[9];
        *param_2 = piVar2[10];
        goto LAB_c0986020;
      }
      (*(code *)*piVar5)(piVar5);
    }
    free(piVar2);
    FUN_c098bdc8(DAT_c0996740);
    *param_1 = -1;
    uVar4 = 0xfffffffc;
    *param_2 = 0;
  }
  else {
    puVar9 = (uint *)DAT_c0996744[2];
    uVar1 = FUN_c0985438(puVar9,DAT_c0996744[4]);
    puVar9 = puVar9 + (uVar1 >> 5);
    *puVar9 = 1 << (uVar1 & 0x1f) | *puVar9;
    iVar6 = piVar2[3];
    piVar2[3] = iVar6 + 1;
    if (piVar2[4] == iVar6 + 1) {
      piVar5 = (int *)piVar2[1];
      iVar6 = *piVar2;
      *(int **)(iVar6 + 4) = piVar5;
      *piVar5 = iVar6;
      DAT_c099674c[1] = (int)piVar2;
      *piVar2 = (int)DAT_c099674c;
      piVar2[1] = (int)&DAT_c099674c;
      DAT_c099674c = piVar2;
    }
    piVar5 = DAT_c0996740;
    if ((((-1 < *DAT_c0996740) && (*DAT_c0996740 < 4)) && (DAT_c0996740[2] == 1)) &&
       (iVar6 = __GetUserKData(8), piVar5[3] == iVar6)) {
      piVar5[2] = 0;
      piVar5[3] = 0;
      ReleaseMutex((HANDLE)piVar5[1]);
    }
    *param_1 = piVar2[9] + uVar1 * 0x1000;
    *param_2 = piVar2[10] + uVar1 * 0x1000;
LAB_c0986020:
    uVar4 = 0;
  }
  return uVar4;
}



/* c098604c FUN_c098604c */

/* Boundary evidence: original MIPS .pdata c098604c..c098611b. Semantic name remains unreviewed. */

undefined4 FUN_c098604c(int *param_1)

{
  int iVar1;
  int iVar2;
  void *local_18 [2];
  
  if (((*param_1 != 0) && (DAT_c0996148 < 5)) &&
     (iVar2 = *(int *)(DAT_c0996148 * 4 + *param_1), iVar2 != 0)) {
    iVar1 = FUN_c098c8c8(*(undefined4 **)(iVar2 + 8),param_1[1],local_18);
    if (iVar1 != 0) {
      return 0xffffffff;
    }
    FUN_c098c7c8(*(undefined4 **)(iVar2 + 8),param_1[1]);
    FUN_c0983d8c(DAT_c099683c,(int)local_18[0]);
    free(local_18[0]);
    return 0;
  }
  return 0xfffffffd;
}



/* c098611c FUN_c098611c */

/* Boundary evidence: original MIPS .pdata c098611c..c098629b. Semantic name remains unreviewed. */

int FUN_c098611c(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 *_Memory;
  uint uVar2;
  int iVar3;
  undefined4 *puVar4;
  int iVar5;
  uint local_48 [2];
  int local_40;
  int local_3c;
  code *local_38;
  undefined4 local_34;
  int *local_2c;
  char *local_28;
  undefined4 local_20;
  
  if (((*param_1 != 0) && (DAT_c0996148 < 5)) &&
     (iVar5 = *(int *)(DAT_c0996148 * 4 + *param_1), iVar5 != 0)) {
    local_2c = &local_40;
    uVar2 = param_1[2];
    local_38 = FUN_c09844e4;
    local_34 = 0;
    local_28 = "External Memory";
    local_20 = 0;
    if ((uVar2 != 0) && ((uVar2 & 0xfff) == 0)) {
      iVar1 = FUN_c0992a10(param_1[1],uVar2,param_3,param_4);
      if (iVar1 != 0) {
        return iVar1;
      }
      local_40 = param_1[1];
      iVar1 = param_1[2];
      local_3c = iVar1;
      _Memory = calloc(1,0x38);
      if (_Memory != (undefined4 *)0x0) {
        iVar3 = param_1[3];
        puVar4 = _Memory + 0xc;
        _Memory[2] = iVar1;
        *_Memory = 0;
        _Memory[1] = iVar3;
        _Memory[6] = iVar5;
        _Memory[7] = 0;
        _Memory[5] = 0;
        *puVar4 = puVar4;
        _Memory[0xd] = puVar4;
        iVar1 = FUN_c098cb14(*(undefined4 **)(iVar5 + 8),_Memory,local_48);
        if (iVar1 != 0) {
          free(_Memory);
          return -1;
        }
        iVar1 = FUN_c0983e54(DAT_c099683c,(int)_Memory,&local_38,(int *)0x0);
        if (iVar1 == 0) {
          param_1[5] = local_48[0];
          return 0;
        }
        FUN_c098c7c8(*(undefined4 **)(iVar5 + 8),local_48[0]);
        free(_Memory);
      }
      return -4;
    }
  }
  return -3;
}



/* c098629c FUN_c098629c */

/* Boundary evidence: original MIPS .pdata c098629c..c0986477. Semantic name remains unreviewed. */

void FUN_c098629c(int param_1)

{
  int iVar1;
  uint uVar2;
  int *piVar3;
  int iVar4;
  
  FUN_c098be3c(*(int **)(param_1 + 0x28));
  piVar3 = *(int **)(param_1 + 0x28);
  *(int *)(param_1 + 0x30) = *(int *)(param_1 + 0x30) + 1;
  if ((((-1 < *piVar3) && (*piVar3 < 4)) && (piVar3[2] == 1)) &&
     (iVar1 = __GetUserKData(8), piVar3[3] == iVar1)) {
    piVar3[2] = 0;
    piVar3[3] = 0;
    ReleaseMutex((HANDLE)piVar3[1]);
  }
  FUN_c0992e04(1,param_1);
  iVar1 = DAT_c0996798;
  if (DAT_c0996798 == 0) {
    iVar4 = 0;
    **(undefined4 **)(param_1 + 0x10) = DAT_c0996118;
    *(undefined4 *)(*(int *)(param_1 + 0x10) + 8) = 4;
    *(undefined4 *)(*(int *)(param_1 + 0x10) + 0x18) = 1;
    *(undefined4 *)(*(int *)(param_1 + 0x10) + 8) = 5;
    do {
      if (iVar1 == 0) {
        uVar2 = *(uint *)(*(int *)(param_1 + 0x10) + 4);
      }
      else {
        uVar2 = 0;
      }
      if ((uVar2 & 0x10) != 0) break;
      StallExecution(10);
      iVar4 = iVar4 + 1;
      iVar1 = DAT_c0996798;
    } while (iVar4 < 100);
  }
  FUN_c0992e04(2,param_1);
  if (DAT_c0996798 == 0) {
    *(undefined4 *)(*(int *)(param_1 + 0x10) + 8) = 6;
    *(undefined4 *)(*(int *)(param_1 + 0x10) + 0x1c) = 3;
    **(undefined4 **)(param_1 + 0x10) = DAT_c0996124;
    *(undefined4 *)(*(int *)(param_1 + 0x10) + 8) = 0;
  }
  FUN_c0992e04(3,param_1);
  FUN_c09856e4(param_1);
  return;
}



/* c0986478 FUN_c0986478 */

/* Boundary evidence: original MIPS .pdata c0986478..c09864f3. Semantic name remains unreviewed. */

void FUN_c0986478(void)

{
  if (DAT_c0996118 != 0xffffffff) {
    FUN_c0985b00(DAT_c0996118);
    DAT_c0996118 = 0xffffffff;
  }
  if (DAT_c099611c != 0xffffffff) {
    FUN_c0985b00(DAT_c099611c);
    DAT_c099611c = 0xffffffff;
  }
  if (DAT_c0996120 != 0xffffffff) {
    FUN_c0985b00(DAT_c0996120);
    DAT_c0996120 = 0xffffffff;
  }
  return;
}



/* c09864f4 FUN_c09864f4 */

/* Boundary evidence: original MIPS .pdata c09864f4..c0986633. Semantic name remains unreviewed. */

int FUN_c09864f4(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  uint *puVar5;
  uint uVar6;
  
  iVar3 = FUN_c0985db4((int *)&DAT_c0996120,&DAT_c0996838);
  if (iVar3 == 0) {
    iVar3 = FUN_c0985db4((int *)&DAT_c099611c,&DAT_c0996834);
    if (iVar3 == 0) {
      iVar3 = FUN_c0985db4(&DAT_c0996118,&DAT_c0996830);
      iVar1 = DAT_c0996838;
      if (iVar3 == 0) {
        iVar3 = 0;
        do {
          puVar4 = (undefined4 *)(iVar1 + iVar3);
          iVar3 = iVar3 + 4;
          *puVar4 = 0;
          iVar2 = DAT_c0996834;
        } while (iVar3 < 0x1000);
        uVar6 = DAT_c0996120 | 7;
        iVar3 = 0;
        do {
          puVar5 = (uint *)(iVar2 + iVar3);
          iVar3 = iVar3 + 4;
          *puVar5 = uVar6;
          iVar1 = DAT_c0996830;
        } while (iVar3 < 0x1000);
        uVar6 = DAT_c099611c | 1;
        iVar3 = 0;
        do {
          puVar5 = (uint *)(iVar1 + iVar3);
          iVar3 = iVar3 + 4;
          *puVar5 = uVar6;
        } while (iVar3 < 0x1000);
        return 0;
      }
      FUN_c0985b00(DAT_c099611c);
      DAT_c099611c = 0xffffffff;
      DAT_c0996834 = 0;
    }
    FUN_c0985b00(DAT_c0996120);
    DAT_c0996120 = 0xffffffff;
    DAT_c0996838 = 0;
  }
  return iVar3;
}



/* c0986634 FUN_c0986634 */

/* Boundary evidence: original MIPS .pdata c0986634..c098667b. Semantic name remains unreviewed. */

void FUN_c0986634(void)

{
  if (DAT_c0996124 != 0xffffffff) {
    FUN_c0985b00(DAT_c0996124);
    DAT_c0996124 = 0xffffffff;
  }
  return;
}



/* c098667c FUN_c098667c */

/* Boundary evidence: original MIPS .pdata c098667c..c09866cf. Semantic name remains unreviewed. */

int FUN_c098667c(void)

{
  int iVar1;
  undefined4 *puVar2;
  int local_10 [2];
  
  iVar1 = FUN_c0985db4(&DAT_c0996124,local_10);
  if (iVar1 == 0) {
    iVar1 = 0;
    do {
      puVar2 = (undefined4 *)(local_10[0] + iVar1);
      iVar1 = iVar1 + 4;
      *puVar2 = 0;
    } while (iVar1 < 0x1000);
    iVar1 = 0;
  }
  return iVar1;
}



/* c09866d0 FUN_c09866d0 */

/* Boundary evidence: original MIPS .pdata c09866d0..c09868df. Semantic name remains unreviewed. */

void FUN_c09866d0(undefined4 param_1,undefined4 *param_2)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  void *pvVar5;
  int iVar6;
  int *piVar7;
  undefined4 *_Memory;
  undefined4 *_Memory_00;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 *local_1c;
  
  if ((param_2 != (undefined4 *)0x0) &&
     (_Memory_00 = (undefined4 *)*param_2, _Memory_00 != (undefined4 *)0x0)) {
    FUN_c098be3c((int *)*_Memory_00);
    piVar7 = _Memory_00 + 0x807;
    piVar3 = (int *)*piVar7;
    if (piVar3 != piVar7) {
      piVar2 = (int *)*piVar3;
      local_28 = param_1;
      while (piVar1 = piVar2, piVar3 != piVar7) {
        local_1c = piVar3 + -0xc;
        local_20 = piVar3[-10];
        local_24 = *local_1c;
        FUN_c0984b84((int)&local_28);
        piVar2 = (int *)*piVar1;
        piVar3 = piVar1;
      }
    }
    if ((undefined4 *)_Memory_00[2] != (undefined4 *)0x0) {
      FUN_c098c9e0((undefined4 *)_Memory_00[2]);
      _Memory = (undefined4 *)_Memory_00[2];
      free((void *)_Memory[3]);
      pvVar5 = (void *)*_Memory;
      CloseHandle(*(HANDLE *)((int)pvVar5 + 4));
      free(pvVar5);
      free(_Memory);
      _Memory_00[2] = 0;
    }
    iVar6 = 0;
    do {
      iVar4 = _Memory_00[4];
      if ((iVar4 != 0) && ((*(uint *)(iVar4 + iVar6) & 1) != 0)) {
        FUN_c0985b00(*(uint *)(iVar4 + iVar6) & 0xfffffff8);
        *(undefined4 *)(_Memory_00[4] + iVar6) = 0;
      }
      iVar6 = iVar6 + 4;
    } while (iVar6 < 0x1000);
    if (_Memory_00[3] != 0xffffffff) {
      FUN_c0985b00(_Memory_00[3]);
      _Memory_00[3] = 0xffffffff;
    }
    piVar3 = (int *)*_Memory_00;
    if ((((-1 < *piVar3) && (*piVar3 < 4)) && (piVar3[2] == 1)) &&
       (iVar6 = __GetUserKData(8), piVar3[3] == iVar6)) {
      piVar3[2] = 0;
      piVar3[3] = 0;
      ReleaseMutex((HANDLE)piVar3[1]);
    }
    pvVar5 = (void *)*_Memory_00;
    CloseHandle(*(HANDLE *)((int)pvVar5 + 4));
    free(pvVar5);
    free(_Memory_00);
    *param_2 = 0;
  }
  return;
}



/* c09868e0 FUN_c09868e0 */

/* Boundary evidence: original MIPS .pdata c09868e0..c0986a23. Semantic name remains unreviewed. */

int FUN_c09868e0(undefined4 param_1,int *param_2)

{
  int iVar1;
  undefined4 *_Memory;
  undefined4 *puVar2;
  int local_20 [2];
  
  if ((param_2 == (int *)0x0) || (*param_2 != 0)) {
    iVar1 = -3;
  }
  else {
    _Memory = calloc(1,0x2024);
    if (_Memory != (undefined4 *)0x0) {
      puVar2 = FUN_c098cccc();
      _Memory[2] = puVar2;
      if (puVar2 != (undefined4 *)0x0) {
        iVar1 = FUN_c0985db4(_Memory + 3,local_20);
        _Memory[4] = local_20[0];
        if (iVar1 != 0) {
          FUN_c098c634((undefined4 *)_Memory[2]);
          free(_Memory);
          return iVar1;
        }
        iVar1 = 0;
        do {
          local_20[0] = _Memory[4];
          puVar2 = (undefined4 *)(local_20[0] + iVar1);
          iVar1 = iVar1 + 4;
          *puVar2 = 0;
        } while (iVar1 < 0x1000);
        puVar2 = _Memory + 0x805;
        *puVar2 = puVar2;
        _Memory[0x806] = puVar2;
        puVar2 = FUN_c098bcf4(0x1a);
        *_Memory = puVar2;
        if (puVar2 == (undefined4 *)0x0) {
          FUN_c0985b00(_Memory[3]);
          FUN_c098c634((undefined4 *)_Memory[2]);
          free(_Memory);
          return -1;
        }
        puVar2 = _Memory + 0x807;
        *puVar2 = puVar2;
        _Memory[0x808] = puVar2;
        *param_2 = (int)_Memory;
        return 0;
      }
      free(_Memory);
    }
    iVar1 = -4;
  }
  return iVar1;
}



/* c0986a24 FUN_c0986a24 */

/* Boundary evidence: original MIPS .pdata c0986a24..c0986bd3. Semantic name remains unreviewed. */

void FUN_c0986a24(void)

{
  undefined4 uVar1;
  int *piVar2;
  int *piVar4;
  int iVar5;
  void *_Memory;
  void *pvVar6;
  int *piVar3;
  
  piVar4 = (int *)*DAT_c0996754;
  piVar2 = DAT_c0996754;
  if ((int **)DAT_c0996754 != &DAT_c0996754) {
    do {
      piVar3 = piVar4;
      if (DAT_c0996798 == 0) {
        *(undefined4 *)(piVar2[-2] + 8) = 6;
      }
      FUN_c098c058((void *)piVar2[2]);
      iVar5 = *piVar2;
      piVar4 = (int *)piVar2[1];
      *(int **)(iVar5 + 4) = piVar4;
      *piVar4 = iVar5;
      VirtualFree((LPVOID)piVar2[-2],0,0x8000);
      free(piVar2 + -6);
      piVar4 = (int *)*piVar3;
      piVar2 = piVar3;
    } while ((int **)piVar3 != &DAT_c0996754);
  }
  if (DAT_c0996124 != 0xffffffff) {
    FUN_c0985b00(DAT_c0996124);
    DAT_c0996124 = 0xffffffff;
  }
  if (DAT_c0996118 != 0xffffffff) {
    FUN_c0985b00(DAT_c0996118);
    DAT_c0996118 = 0xffffffff;
  }
  if (DAT_c099611c != 0xffffffff) {
    FUN_c0985b00(DAT_c099611c);
    DAT_c099611c = 0xffffffff;
  }
  if (DAT_c0996120 != 0xffffffff) {
    FUN_c0985b00(DAT_c0996120);
    DAT_c0996120 = 0xffffffff;
  }
  FUN_c0985184();
  _Memory = DAT_c0996844;
  iVar5 = DAT_c0996840;
  uVar1 = 0;
  if (DAT_c0996844 != (void *)0x0) {
    do {
      pvVar6 = *(void **)((int)_Memory + 8);
      free(_Memory);
      _Memory = pvVar6;
    } while (pvVar6 != (void *)0x0);
    iVar5 = DAT_c0996840;
    uVar1 = 0;
  }
  while (DAT_c0996844 = (void *)uVar1, iVar5 != 0) {
    DAT_c0996840 = *(int *)(iVar5 + 0x18);
    (**(code **)(iVar5 + 8))(iVar5);
    iVar5 = DAT_c0996840;
    uVar1 = DAT_c0996844;
  }
  DAT_c0996840 = iVar5;
  if (DAT_c099683c != (void *)0x0) {
    free(DAT_c099683c);
    DAT_c099683c = (void *)0x0;
  }
  return;
}



/* c0986bd4 FUN_c0986bd4 */

/* Boundary evidence: original MIPS .pdata c0986bd4..c0986d43. Semantic name remains unreviewed. */

void FUN_c0986bd4(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  int *piVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  int iVar11;
  
  uVar9 = *(uint *)(param_1 + 4);
  uVar8 = *(uint *)(param_1 + 8);
  uVar4 = (uVar8 + uVar9) - 1 >> 0x16;
  uVar3 = uVar9 >> 0x16;
  iVar11 = *(int *)(param_1 + 0x18);
  if (uVar3 <= uVar4) {
    piVar7 = (int *)((uVar3 + 5) * 4 + iVar11);
    iVar10 = (uVar4 - uVar3) + 1;
    do {
      uVar3 = uVar8;
      if (0x3fffff < uVar8) {
        uVar3 = 0x400000;
      }
      iVar1 = piVar7[0x400];
      piVar7[0x400] = iVar1 + -1;
      if (iVar1 + -1 == 0) {
        FUN_c0985b00(*(uint *)((int)piVar7 + *(int *)(iVar11 + 0x10) + (-0x14 - iVar11)) &
                     0xfffffc00);
        *piVar7 = 0;
        *(undefined4 *)((int)piVar7 + *(int *)(iVar11 + 0x10) + (-0x14 - iVar11)) = 0;
        uVar4 = uVar9;
      }
      else {
        uVar4 = uVar3 + uVar9;
        uVar6 = uVar4 - 1 >> 0xc & 0x3ff;
        uVar9 = uVar9 >> 0xc & 0x3ff;
        if (uVar9 <= uVar6) {
          iVar1 = uVar9 << 2;
          iVar5 = (uVar6 - uVar9) + 1;
          do {
            iVar5 = iVar5 + -1;
            puVar2 = (undefined4 *)(*piVar7 + iVar1);
            iVar1 = iVar1 + 4;
            *puVar2 = 0;
          } while (iVar5 != 0);
        }
      }
      uVar8 = uVar8 - uVar3;
      piVar7 = piVar7 + 1;
      iVar10 = iVar10 + -1;
      uVar9 = uVar4;
    } while (iVar10 != 0);
  }
  return;
}



/* c0986d44 FUN_c0986d44 */

/* Boundary evidence: original MIPS .pdata c0986d44..c0986eeb. Semantic name remains unreviewed. */

undefined4 FUN_c0986d44(int param_1)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  int local_2c;
  uint local_28 [2];
  
  uVar8 = *(uint *)(param_1 + 4) >> 0x16;
  iVar5 = *(int *)(param_1 + 0x18);
  uVar6 = (*(int *)(param_1 + 8) + *(uint *)(param_1 + 4)) - 1 >> 0x16;
  if (uVar8 <= uVar6) {
    piVar3 = (int *)((uVar8 + 0x405) * 4 + iVar5);
    iVar7 = -0x1014 - iVar5;
    uVar4 = uVar8;
    do {
      if ((*(uint *)((int)piVar3 + *(int *)(iVar5 + 0x10) + iVar7) & 1) == 0) {
        iVar1 = FUN_c0985db4((int *)local_28,&local_2c);
        if (iVar1 != 0) {
          if ((int)uVar6 < (int)uVar4) {
            return 0;
          }
          if ((int)uVar8 <= (int)(uVar4 - 1)) {
            piVar3 = (int *)((uVar4 + 0x404) * 4 + iVar5);
            iVar1 = ((uVar4 - 1) - uVar8) + 1;
            do {
              iVar2 = *piVar3;
              *piVar3 = iVar2 + -1;
              if (iVar2 + -1 == 0) {
                local_28[0] = *(uint *)(iVar5 + 0x10);
                FUN_c0985b00(*(uint *)((int)piVar3 + local_28[0] + iVar7) & 0xfffffc00);
                piVar3[-0x400] = 0;
                *(undefined4 *)((int)piVar3 + *(int *)(iVar5 + 0x10) + iVar7) = 0;
              }
              iVar1 = iVar1 + -1;
              piVar3 = piVar3 + -1;
            } while (iVar1 != 0);
          }
          return 0xfffffffc;
        }
        piVar3[-0x400] = local_2c;
        *(uint *)((int)piVar3 + *(int *)(iVar5 + 0x10) + iVar7) = local_28[0] | 1;
        *piVar3 = *piVar3 + 1;
      }
      else {
        *piVar3 = *piVar3 + 1;
      }
      uVar4 = uVar4 + 1;
      piVar3 = piVar3 + 1;
    } while ((int)uVar4 <= (int)uVar6);
  }
  return 0;
}



/* c0986eec FUN_c0986eec */

/* Boundary evidence: original MIPS .pdata c0986eec..c098721b. Semantic name remains unreviewed. */

void FUN_c0986eec(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  bool bVar1;
  char *pcVar2;
  undefined4 uVar3;
  uint uVar4;
  char *pcVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  
  if (param_1 == 0) {
    FUN_c098b68c("Mali: ERR: %s\n","src/devicedrv/mali/common/mali_kernel_mem_mmu.c",param_3,param_4
                );
    uVar3 = 0x512;
    pcVar2 = "mali_kernel_memory_mmu_interrupt_handler_bottom_half";
    FUN_c098b68c("           %s()%4d\n           ",
                 "mali_kernel_memory_mmu_interrupt_handler_bottom_half",0x512,param_4);
    FUN_c098b68c("MMU IRQ work queue: NULL argument",pcVar2,uVar3,param_4);
    FUN_c098b68c("\n",pcVar2,uVar3,param_4);
  }
  else {
    iVar7 = param_1;
    FUN_c0992e04(0,param_1);
    if (DAT_c0996798 == 0) {
      uVar6 = *(uint *)(*(int *)(param_1 + 0x10) + 0x14);
      uVar8 = *(uint *)(*(int *)(param_1 + 0x10) + 4);
    }
    else {
      uVar6 = 0;
      uVar8 = 0;
    }
    if (((uVar6 & 1) != 0) || ((uVar8 & 2) != 0)) {
      bVar1 = DAT_c0996798 == 0;
      *(undefined4 *)(param_1 + 0x3c) = 1;
      if (bVar1) {
        uVar6 = *(uint *)(*(int *)(param_1 + 0x10) + 0xc);
      }
      else {
        uVar6 = 0;
      }
      FUN_c098b68c("Mali: ",iVar7,param_3,param_4);
      if ((uVar8 & 0x20) == 0) {
        pcVar2 = "read";
      }
      else {
        pcVar2 = "write";
      }
      uVar4 = uVar8 >> 6 & 0x1f;
      uVar8 = uVar6;
      FUN_c098b68c("Page fault detected at 0x%x from bus id %d of type %s on %s\n",uVar6,uVar4,
                   pcVar2);
      if (*(int *)(param_1 + 0x2c) == 0) {
        FUN_c098b68c("Mali: ",uVar8,uVar4,pcVar2);
        FUN_c098b68c("Spurious memory access detected from MMU %s\n",*(undefined4 *)(param_1 + 4),
                     uVar4,pcVar2);
      }
      else {
        FUN_c098b68c("Mali: ",uVar8,uVar4,pcVar2);
        uVar3 = *(undefined4 *)(*(int *)(param_1 + 0x2c) + 0xc);
        FUN_c098b68c("Active page directory at 0x%08lX\n",uVar3,uVar4,pcVar2);
        FUN_c098b68c("Mali: ",uVar3,uVar4,pcVar2);
        uVar8 = uVar6;
        FUN_c098b68c("Info from page table for VA 0x%x:\n",uVar6,uVar4,pcVar2);
        FUN_c098b68c("Mali: ",uVar8,uVar4,pcVar2);
        iVar9 = (uVar6 >> 0x16) * 4;
        iVar7 = *(int *)(*(int *)(param_1 + 0x2c) + 0x10);
        pcVar5 = "present";
        if ((*(uint *)(iVar7 + iVar9) & 1) == 0) {
          pcVar5 = "not present";
        }
        uVar8 = *(uint *)(iVar7 + iVar9) & 0xfffffff8;
        FUN_c098b68c("DTE entry: PTE at 0x%x marked as %s\n",uVar8,pcVar5,pcVar2);
        if ((*(uint *)(*(int *)(*(int *)(param_1 + 0x2c) + 0x10) + iVar9) & 1) == 0) {
          FUN_c098b68c("Mali: ",uVar8,pcVar5,pcVar2);
          FUN_c098b68c("PTE entry: Not present",uVar8,pcVar5,pcVar2);
        }
        else {
          uVar6 = *(uint *)((uVar6 >> 0xc & 0x3ff) * 4 +
                           *(int *)(((uVar6 >> 0x16) + 5) * 4 + *(int *)(param_1 + 0x2c)));
          FUN_c098b68c("Mali: ",uVar8,pcVar5,pcVar2);
          pcVar2 = "";
          if ((uVar6 & 2) != 0) {
            pcVar2 = "readable";
          }
          pcVar5 = "present";
          if ((uVar6 & 1) == 0) {
            pcVar5 = "not present";
          }
          FUN_c098b68c("PTE entry: Page at 0x%x, %s %s %s\n",uVar6 & 0xfffffff8,pcVar5,pcVar2);
        }
      }
      FUN_c098629c(param_1);
      *(undefined4 *)(param_1 + 0x3c) = 0;
    }
    FUN_c0992e04(4,param_1);
  }
  return;
}



/* c098721c FUN_c098721c */

/* Boundary evidence: original MIPS .pdata c098721c..c09872b3. Semantic name remains unreviewed. */

void FUN_c098721c(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  char *pcVar1;
  undefined4 uVar2;
  
  if (*(int *)(param_1 + 0x3c) != 0) {
    FUN_c098b68c("Mali: ERR: %s\n","src/devicedrv/mali/common/mali_kernel_mem_mmu.c",param_3,param_4
                );
    uVar2 = 0x502;
    pcVar1 = "mali_kernel_mmu_force_bus_reset";
    FUN_c098b68c("           %s()%4d\n           ","mali_kernel_mmu_force_bus_reset",0x502,param_4);
    FUN_c098b68c("Stopping the Memory bus not possible. Mali reset could not be performed.",pcVar1,
                 uVar2,param_4);
    FUN_c098b68c("\n",pcVar1,uVar2,param_4);
    return;
  }
  if (DAT_c0996798 == 0) {
    *(undefined4 *)(*(int *)(param_1 + 0x10) + 0x1c) = 0;
  }
  FUN_c098629c(param_1);
  return;
}



/* c09872b4 FUN_c09872b4 */

/* Boundary evidence: original MIPS .pdata c09872b4..c098750b. Semantic name remains unreviewed. */

undefined4 FUN_c09872b4(int param_1)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  LPVOID pvVar4;
  int *piVar5;
  int iVar6;
  undefined4 *puVar7;
  void *pvVar8;
  int *piVar9;
  
  if ((undefined4 **)DAT_c0996754 != &DAT_c0996754) {
    puVar3 = (undefined4 *)*DAT_c0996754;
    puVar1 = DAT_c0996754;
    do {
      puVar7 = puVar3;
      if (*(int *)(param_1 + 0x1c) == puVar1[-6]) goto LAB_c09873e8;
      puVar3 = (undefined4 *)*puVar7;
      puVar1 = puVar7;
    } while ((undefined4 **)puVar7 != &DAT_c0996754);
  }
  puVar1 = calloc(1,0x48);
  if (puVar1 == (undefined4 *)0x0) {
    uVar2 = 0xfffffffc;
  }
  else {
    piVar9 = puVar1 + 6;
    *piVar9 = (int)piVar9;
    puVar1[7] = piVar9;
    *puVar1 = *(undefined4 *)(param_1 + 0x1c);
    puVar1[2] = *(undefined4 *)(param_1 + 0x14);
    puVar3 = puVar1 + 0xd;
    puVar1[9] = *(undefined4 *)(param_1 + 0x18);
    puVar7 = puVar1 + 0x10;
    puVar1[3] = *(undefined4 *)(param_1 + 8);
    puVar1[5] = 0x24;
    puVar1[1] = *(undefined4 *)(param_1 + 4);
    *puVar3 = puVar3;
    puVar1[0xe] = puVar3;
    *puVar7 = puVar7;
    puVar1[0x11] = puVar7;
    puVar1[0xf] = 0;
    puVar3 = FUN_c098bcf4(0x1a);
    puVar1[10] = puVar3;
    if (puVar3 != (undefined4 *)0x0) {
      pvVar4 = FUN_c098b9c0(puVar1[3],puVar1[5],puVar1[1]);
      puVar1[4] = pvVar4;
      iVar6 = DAT_c0996798;
      if (pvVar4 != (LPVOID)0x0) {
        if (DAT_c0996798 == 0) {
          *(undefined4 *)((int)pvVar4 + 8) = 6;
          *(undefined4 *)(puVar1[4] + 0x1c) = 3;
        }
        puVar3 = DAT_c0996758;
        DAT_c0996758 = piVar9;
        *piVar9 = (int)&DAT_c0996754;
        puVar1[7] = puVar3;
        *puVar3 = piVar9;
        if (puVar1[2] == -1) {
          puVar3 = (undefined4 *)0x0;
        }
        else {
          puVar3 = FUN_c098c21c(puVar1[2],FUN_c0984628,FUN_c0986eec,puVar1);
          iVar6 = DAT_c0996798;
        }
        puVar1[8] = puVar3;
        if (puVar3 == (undefined4 *)0x0) {
          piVar5 = (int *)puVar1[7];
          iVar6 = *piVar9;
          *(int **)(iVar6 + 4) = piVar5;
          *piVar5 = iVar6;
          pvVar8 = (void *)puVar1[10];
          CloseHandle(*(HANDLE *)((int)pvVar8 + 4));
          free(pvVar8);
          VirtualFree((LPVOID)puVar1[4],0,0x8000);
          free(puVar1);
          return 0xffffffff;
        }
        if (iVar6 == 0) {
          *(undefined4 *)(puVar1[4] + 8) = 6;
          *(undefined4 *)(puVar1[4] + 0x1c) = 3;
        }
        return 0;
      }
      pvVar8 = (void *)puVar1[10];
      CloseHandle(*(HANDLE *)((int)pvVar8 + 4));
      free(pvVar8);
    }
    free(puVar1);
LAB_c09873e8:
    uVar2 = 0xffffffff;
  }
  return uVar2;
}



/* c098750c FUN_c098750c */

/* Boundary evidence: original MIPS .pdata c098750c..c0987623. Semantic name remains unreviewed. */

int FUN_c098750c(void)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar5;
  int local_18 [2];
  undefined4 *puVar4;
  
  iVar1 = FUN_c0985db4((int *)&DAT_c0996124,local_18);
  if (iVar1 == 0) {
    iVar1 = 0;
    do {
      puVar5 = (undefined4 *)(local_18[0] + iVar1);
      iVar1 = iVar1 + 4;
      *puVar5 = 0;
    } while (iVar1 < 0x1000);
    iVar2 = FUN_c09864f4();
    iVar1 = DAT_c0996798;
    if (iVar2 != 0) {
      if (DAT_c0996124 != 0xffffffff) {
        FUN_c0985b00(DAT_c0996124);
        DAT_c0996124 = 0xffffffff;
      }
      return -1;
    }
    puVar5 = (undefined4 *)*DAT_c0996754;
    puVar3 = DAT_c0996754;
    if ((undefined4 **)DAT_c0996754 != &DAT_c0996754) {
      do {
        puVar4 = puVar5;
        if (iVar1 == 0) {
          *(uint *)puVar3[-2] = DAT_c0996124;
          *(undefined4 *)(puVar3[-2] + 8) = 0;
        }
        puVar5 = (undefined4 *)*puVar4;
        puVar3 = puVar4;
      } while ((undefined4 **)puVar4 != &DAT_c0996754);
    }
    iVar1 = 0;
  }
  return iVar1;
}



/* c0987624 FUN_c0987624 */

/* Boundary evidence: original MIPS .pdata c0987624..c098774f. Semantic name remains unreviewed. */

undefined4 FUN_c0987624(undefined4 param_1)

{
  undefined4 *_Memory;
  HANDLE pvVar1;
  
  DAT_c0996754 = &DAT_c0996754;
  DAT_c0996758 = &DAT_c0996754;
  DAT_c0996148 = param_1;
  _Memory = malloc(0x10);
  if (_Memory == (undefined4 *)0x0) {
    _Memory = (undefined4 *)0x0;
  }
  else {
    pvVar1 = CreateMutexW((LPSECURITY_ATTRIBUTES)0x0,0,(LPCWSTR)0x0);
    _Memory[1] = pvVar1;
    if (pvVar1 == (HANDLE)0x0) {
      free(_Memory);
      _Memory = (undefined4 *)0x0;
    }
    else {
      _Memory[2] = 0;
      _Memory[3] = 0;
      *_Memory = 2;
    }
  }
  DAT_c0996740 = _Memory;
  if (_Memory != (undefined4 *)0x0) {
    DAT_c0996744 = &DAT_c0996744;
    DAT_c0996748 = &DAT_c0996744;
    DAT_c099674c = &DAT_c099674c;
    DAT_c0996750 = &DAT_c099674c;
    DAT_c0996774 = FUN_c09872b4;
    DAT_c0996778 = FUN_c0984758;
    DAT_c0996760 = FUN_c0985260;
    DAT_c0996764 = FUN_c0985340;
    DAT_c099683c = FUN_c0983d18();
    if (DAT_c099683c != (undefined4 *)0x0) {
      return 0;
    }
  }
  return 0xffffffff;
}



/* c0987800 FUN_c0987800 */

/* Boundary evidence: original MIPS .pdata c0987800..c0987873. Semantic name remains unreviewed. */

undefined4 FUN_c0987800(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  uint uVar1;
  undefined4 local_c;
  
  uVar1 = FUN_c098d590(param_1,0x30,param_3,param_4);
  if ((uVar1 & 0x40) == 0) {
    local_c = 0xffffffff;
  }
  else {
    FUN_c098d4d4(param_1,0x28,0x40,param_4);
    SYNC(0);
    local_c = 0;
  }
  return local_c;
}



/* c0987874 FUN_c0987874 */

/* Boundary evidence: original MIPS .pdata c0987874..c09878bb. Semantic name remains unreviewed. */

void FUN_c0987874(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  FUN_c098d4d4(param_1,0x2c,0xe67,param_4);
  FUN_c098d4d4(param_1,0x24,0x40,param_4);
  SYNC(0);
  return;
}



/* c09878bc FUN_c09878bc */

/* Boundary evidence: original MIPS .pdata c09878bc..c09878d7. Semantic name remains unreviewed. */

void FUN_c09878bc(void *param_1)

{
  free(param_1);
  return;
}



/* c09878d8 FUN_c09878d8 */

/* Boundary evidence: original MIPS .pdata c09878d8..c0987a87. Semantic name remains unreviewed. */

void FUN_c09878d8(void *param_1,int param_2)

{
  int iVar1;
  undefined4 *_Dst;
  int iVar2;
  undefined4 local_20 [2];
  
  _Dst = *(undefined4 **)(*(int *)((int)param_1 + 0x8c) + 8);
  iVar2 = *(int *)((int)param_1 + 8);
  memset(_Dst,0,0x40);
  *_Dst = *(undefined4 *)((int)param_1 + 0x2c);
  if (param_2 < 0x100001) {
    if (param_2 != 0x100000) {
      if (param_2 < 0x20001) {
        if (((param_2 != 0x20000) && (param_2 != 1)) && (param_2 != 0x10000)) {
LAB_c0987a80:
          _Dst[1] = 0x800000;
          goto LAB_c0987978;
        }
      }
      else if (param_2 != 0x40000) {
        iVar1 = 0x80000;
        goto LAB_c0987a78;
      }
    }
  }
  else if (param_2 < 0x800001) {
    if (((param_2 != 0x800000) && (param_2 != 0x200000)) && (param_2 != 0x400000)) {
      _Dst[1] = 0x800000;
      goto LAB_c0987978;
    }
  }
  else if (param_2 != 0x1000000) {
    iVar1 = 0x2000000;
LAB_c0987a78:
    if (param_2 != iVar1) goto LAB_c0987a80;
  }
  _Dst[1] = param_2;
LAB_c0987978:
  _Dst[2] = *(undefined4 *)((int)param_1 + 0x70);
  _Dst[3] = *(undefined4 *)((int)param_1 + 0x74);
  _Dst[4] = 0;
  _Dst[5] = 0;
  _Dst[6] = *(undefined4 *)((int)param_1 + 0x88);
  _Dst[9] = *(undefined4 *)((int)param_1 + 0x78);
  _Dst[10] = *(undefined4 *)((int)param_1 + 0x7c);
  _Dst[7] = *(undefined4 *)((int)param_1 + 0x54);
  _Dst[8] = *(undefined4 *)((int)param_1 + 0x58);
  _Dst[0xb] = *(undefined4 *)((int)param_1 + 0x18);
  local_20[0] = *(undefined4 *)((int)param_1 + 0x8c);
  WriteMsgQueue(*(undefined4 *)(*(int *)(iVar2 + 0x20) + 4),local_20,4,0,0);
  *(undefined4 *)((int)param_1 + 0x8c) = 0;
  free(param_1);
  DAT_c099682c = 0;
  return;
}



/* c0987a88 FUN_c0987a88 */

/* Boundary evidence: original MIPS .pdata c0987a88..c0987b0f. Semantic name remains unreviewed. */

undefined4 FUN_c0987a88(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  int iVar2;
  
  if (DAT_c0996798 == 0) {
    iVar2 = FUN_c098d590(param_1,0x30,param_3,param_4);
    if (iVar2 != 0) {
      FUN_c098d4d4(param_1,0x2c,0,param_4);
      return 1;
    }
    uVar1 = 0;
  }
  else {
    uVar1 = 1;
    if (*(int *)(param_1 + 0x10) == 0) {
      return 0;
    }
  }
  return uVar1;
}



/* c0987b10 FUN_c0987b10 */

/* Boundary evidence: original MIPS .pdata c0987b10..c0987bd7. Semantic name remains unreviewed. */

void FUN_c0987b10(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  uint uVar1;
  undefined4 uVar2;
  
  uVar1 = DAT_c099616c;
  if (DAT_c0996798 == 0) {
    if (*(uint *)(param_1 + 0x28) <= DAT_c099616c) {
      FUN_c098b68c("Mali: ERR: %s\n","src/devicedrv/mali/common/mali_rendercore.c",param_3,param_4);
      FUN_c098b68c("           %s()%4d\n           ","mali_core_renderunit_register_write",0x11a,
                   param_4);
      uVar2 = *(undefined4 *)(param_1 + 0x2c);
      FUN_c098b68c("Trying to write to illegal register: 0x%04x in core: %s",uVar1,uVar2,param_4);
      FUN_c098b68c("\n",uVar1,uVar2,param_4);
      return;
    }
    *(undefined4 *)(*(int *)(param_1 + 0x20) + DAT_c099616c) = DAT_c0996170;
  }
  return;
}



/* c0987bd8 FUN_c0987bd8 */

/* Boundary evidence: original MIPS .pdata c0987bd8..c0987bf7. Semantic name remains unreviewed. */

void FUN_c0987bd8(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  FUN_c098d4d4(param_1,0x20,0x200,param_4);
  return;
}



/* c0987bf8 FUN_c0987bf8 */

/* Boundary evidence: original MIPS .pdata c0987bf8..c0987c8f. Semantic name remains unreviewed. */

undefined4 FUN_c0987bf8(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  if ((*(uint *)(param_1 + 0x34) & 0xffff0000) != 0xa070000) {
    FUN_c098b68c("Mali: ERR: %s\n","src/devicedrv/mali/common/mali_kernel_GP2.c",param_3,param_4);
    uVar2 = 0x1bd;
    FUN_c098b68c("           %s()%4d\n           ","maligp_core_version_legal",0x1bd,param_4);
    uVar1 = *(undefined4 *)(param_1 + 0x34);
    FUN_c098b68c("Error: reading this from maligp version register: 0x%x\n",uVar1,uVar2,param_4);
    FUN_c098b68c("\n",uVar1,uVar2,param_4);
    return 0xffffffff;
  }
  return 0;
}



/* c0987c90 FUN_c0987c90 */

/* Boundary evidence: original MIPS .pdata c0987c90..c0987cff. Semantic name remains unreviewed. */

undefined4 FUN_c0987c90(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  int *piVar2;
  
  if (*param_1 == 0) {
    return 0xfffffffd;
  }
  if ((DAT_c0996168 < 5) && (piVar2 = *(int **)(DAT_c0996168 * 4 + *param_1), piVar2 != (int *)0x0))
  {
    uVar1 = FUN_c098e118(piVar2,param_1,param_3,param_4);
    return uVar1;
  }
  return 0xffffffff;
}



/* c0987d00 FUN_c0987d00 */

/* Boundary evidence: original MIPS .pdata c0987d00..c0987d6f. Semantic name remains unreviewed. */

undefined4 FUN_c0987d00(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  
  if (*param_1 == 0) {
    return 0xfffffffd;
  }
  if ((DAT_c0996168 < 5) &&
     (puVar2 = *(undefined4 **)(DAT_c0996168 * 4 + *param_1), puVar2 != (undefined4 *)0x0)) {
    uVar1 = FUN_c098e398(puVar2,param_1 + 1,param_3,param_4);
    return uVar1;
  }
  return 0xffffffff;
}



/* c0987d70 FUN_c0987d70 */

/* Boundary evidence: original MIPS .pdata c0987d70..c0987ddf. Semantic name remains unreviewed. */

undefined4 FUN_c0987d70(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  int *piVar2;
  
  if (*param_1 == 0) {
    return 0xfffffffd;
  }
  if ((DAT_c0996168 < 5) && (piVar2 = *(int **)(DAT_c0996168 * 4 + *param_1), piVar2 != (int *)0x0))
  {
    uVar1 = FUN_c098e6b0(piVar2,param_1,param_3,param_4);
    return uVar1;
  }
  return 0xffffffff;
}



/* c0987de0 FUN_c0987de0 */

/* Boundary evidence: original MIPS .pdata c0987de0..c0987f7b. Semantic name remains unreviewed. */

undefined4 FUN_c0987de0(undefined4 param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  DWORD DVar1;
  char *pcVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  int local_18 [2];
  
  iVar5 = *(int *)(param_2 + 4);
  if (DAT_c099682c == iVar5) {
    DAT_c099682c = 0;
    iVar6 = *(int *)(iVar5 + 0x10);
    if (*(int *)(param_2 + 8) == 0) {
      local_18[0] = *(int *)(iVar5 + 0x40);
      WriteMsgQueue(*(undefined4 *)(local_18[0] + 4),local_18,4,0,0);
    }
    else if (*(int *)(param_2 + 8) == 1) {
      *(undefined4 *)(iVar6 + 0x90) = 0;
      DVar1 = GetTickCount();
      iVar3 = *(int *)(iVar6 + 0x20) + DVar1;
      *(int *)(iVar6 + 0x20) = iVar3;
      FUN_c098aba4(*(MMRESULT **)(iVar5 + 0x18),iVar3);
      FUN_c098d4d4(iVar5,0x28,0x24,param_4);
      FUN_c098d4d4(iVar5,0x2c,*(undefined4 *)(iVar6 + 0x94),param_4);
      FUN_c098d4d4(iVar5,0x10,*(undefined4 *)(param_2 + 0xc),param_4);
      FUN_c098d4d4(iVar5,0x14,*(undefined4 *)(param_2 + 0x10),param_4);
      FUN_c098d4d4(iVar5,0x20,0x10,param_4);
    }
    else {
      FUN_c098b68c("Mali: ERR: %s\n","src/devicedrv/mali/common/mali_kernel_GP2.c",param_3,param_4);
      uVar4 = 0x4c3;
      pcVar2 = "subsystem_maligp_suspend_response";
      FUN_c098b68c("           %s()%4d\n           ","subsystem_maligp_suspend_response",0x4c3,
                   param_4);
      FUN_c098b68c("Wrong Suspend response from userspace\n",pcVar2,uVar4,param_4);
      FUN_c098b68c("\n",pcVar2,uVar4,param_4);
    }
    uVar4 = 0;
  }
  else {
    FUN_c098b68c("Mali: ERR: %s\n","src/devicedrv/mali/common/mali_kernel_GP2.c",param_3,param_4);
    uVar4 = 0x4a0;
    pcVar2 = "subsystem_maligp_suspend_response";
    FUN_c098b68c("           %s()%4d\n           ","subsystem_maligp_suspend_response",0x4a0,param_4
                );
    FUN_c098b68c("Mali GP: Got an illegal cookie from Userspace. Shame on you.\n",pcVar2,uVar4,
                 param_4);
    FUN_c098b68c("\n",pcVar2,uVar4,param_4);
    uVar4 = 0xffffffff;
  }
  return uVar4;
}



/* c0987f7c FUN_c0987f7c */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Boundary evidence: original MIPS .pdata c0987f7c..c098874f. Semantic name remains unreviewed. */

undefined4 FUN_c0987f7c(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  UINT UVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  char *pcVar6;
  int iVar7;
  undefined4 *puVar8;
  uint local_64;
  uint local_5c;
  undefined4 *local_38;
  UINT *local_34;
  UINT *local_30;
  DWORD local_2c;
  undefined4 local_28;
  uint local_20;
  uint local_1c;
  uint local_18;
  uint local_14;
  uint local_10;
  uint local_c;
  
  _DAT_b9800018 = _DAT_b9800018 | 0x200;
  SYNC(0);
  iVar7 = *(int *)(param_1 + 0x10);
  if (DAT_c0996798 == 0) {
    local_64 = FUN_c098d590(param_1,0x24,param_3,param_4);
    local_64 = local_64 & 0xe67;
    local_5c = FUN_c098d590(param_1,0x68,param_3,param_4);
  }
  else {
    local_64 = 3;
    local_5c = 0;
  }
  if (iVar7 == 0) {
    if (local_64 != 0) {
      FUN_c098b68c("Mali: ERR: %s\n","src/devicedrv/mali/common/mali_kernel_GP2.c",param_3,param_4);
      FUN_c098b68c("           %s()%4d\n           ","subsystem_maligp_irq_handler_bottom_half",
                   0x31d,param_4);
      FUN_c098b68c("Interrupt from a core not running a job. IRQ: 0x%04x Status: 0x%04x",local_64,
                   local_5c,param_4);
      FUN_c098b68c("\n",local_64,local_5c,param_4);
    }
    return 0x800000;
  }
  uVar2 = FUN_c098d590(param_1,0x10,param_3,param_4);
  *(undefined4 *)(iVar7 + 0x88) = uVar2;
  iVar3 = FUN_c098d590(param_1,0,param_3,param_4);
  iVar4 = FUN_c098d590(param_1,8,param_3,param_4);
  *(uint *)(iVar7 + 0x70) = *(uint *)(iVar7 + 0x70) | local_64;
  *(uint *)(iVar7 + 0x74) = local_5c;
  if (*(int *)(iVar7 + 0x90) != 0) {
    if ((*(uint *)(iVar7 + 0x50) & 3) != 0) {
      uVar2 = FUN_c098d590(param_1,0x4c,param_3,param_4);
      *(undefined4 *)(iVar7 + 0x78) = uVar2;
      uVar2 = FUN_c098d590(param_1,0x50,param_3,param_4);
      *(undefined4 *)(iVar7 + 0x7c) = uVar2;
    }
    return 0x20000;
  }
  if ((local_5c & 10) == 0) {
    if ((*(int *)(iVar7 + 0x50) != 0) && ((*(uint *)(iVar7 + 0x50) & 3) != 0)) {
      uVar2 = FUN_c098d590(param_1,0x4c,param_3,param_4);
      *(undefined4 *)(iVar7 + 0x78) = uVar2;
      uVar2 = FUN_c098d590(param_1,0x50,param_3,param_4);
      *(undefined4 *)(iVar7 + 0x7c) = uVar2;
    }
    FUN_c098d4d4(param_1,0x28,0xfff,param_4);
    return 0x10000;
  }
  if (*(int *)(param_1 + 0xc) == 2) {
LAB_c0988340:
    local_28 = 0x100000;
  }
  else {
    if (*(int *)(param_1 + 0xc) == 4) {
      if (*(int *)(iVar7 + 0xa0) == 0) {
        local_1c = 1;
      }
      else {
        iVar5 = FUN_c098d590(param_1,0x50,param_3,param_4);
        local_20 = (uint)(iVar5 == *(int *)(iVar7 + 0xa4));
        local_1c = local_20;
      }
      if (local_1c != 0) {
        if ((local_5c & 2) == 0) {
          local_14 = 1;
        }
        else {
          local_18 = (uint)(iVar3 == *(int *)(iVar7 + 0x98));
          local_14 = local_18;
        }
        if (local_14 != 0) {
          if ((local_5c & 8) == 0) {
            local_c = 1;
          }
          else {
            local_10 = (uint)(iVar4 == *(int *)(iVar7 + 0x9c));
            local_c = local_10;
          }
          if (local_c != 0) goto LAB_c0988340;
        }
      }
    }
    if ((local_64 & 4) == 0) {
      if ((*(int *)(param_1 + 0xc) == 4) || ((local_64 & *(uint *)(iVar7 + 0x94) & 0x20) != 0)) {
        if ((int)DAT_c09961b0 < 0x7d1) {
          if ((int)DAT_c09961b0 < 100) {
            DAT_c09961b0 = 100;
          }
        }
        else {
          DAT_c09961b0 = 2000;
        }
        UVar1 = DAT_c09961b0;
        *(undefined4 *)(param_1 + 0xc) = 1;
        *(int *)(iVar7 + 0x98) = iVar3;
        *(int *)(iVar7 + 0x9c) = iVar4;
        if (*(int *)(iVar7 + 0xa0) != 0) {
          uVar2 = FUN_c098d590(param_1,0x50,param_3,param_4);
          *(undefined4 *)(iVar7 + 0xa4) = uVar2;
        }
        FUN_c098ac24(*(MMRESULT **)(param_1 + 0x1c),UVar1);
        *(uint *)(iVar7 + 0x94) = *(uint *)(iVar7 + 0x94) & 0xffffffdf;
        FUN_c098d4d4(param_1,0x28,local_64,param_4);
        FUN_c098d4d4(param_1,0x2c,*(undefined4 *)(iVar7 + 0x94),param_4);
        local_28 = 1;
      }
      else if (((local_5c & 0x1c0) == 0) && ((local_5c & 10) != 0)) {
        FUN_c098d4d4(param_1,0x28,local_64,param_4);
        FUN_c098d4d4(param_1,0x2c,*(undefined4 *)(iVar7 + 0x94),param_4);
        local_28 = 1;
      }
      else if ((local_64 == 0) && ((local_5c & 10) != 0)) {
        FUN_c098d4d4(param_1,0x28,0,param_4);
        FUN_c098d4d4(param_1,0x2c,*(undefined4 *)(iVar7 + 0x94),param_4);
        local_28 = 1;
      }
      else {
        local_28 = 0x800000;
      }
    }
    else {
      iVar3 = *(int *)(iVar7 + 8);
      local_38 = FUN_c098ae0c(0x30020,0xc);
      if (local_38 == (undefined4 *)0x0) {
        FUN_c098b68c("Mali: ERR: %s\n","src/devicedrv/mali/common/mali_kernel_GP2.c",param_3,param_4
                    );
        uVar2 = 0x3bf;
        pcVar6 = "subsystem_maligp_irq_handler_bottom_half";
        FUN_c098b68c("           %s()%4d\n           ","subsystem_maligp_irq_handler_bottom_half",
                     0x3bf,param_4);
        FUN_c098b68c("Mali GP: Could not get notification object\n",pcVar6,uVar2,param_4);
        FUN_c098b68c("\n",pcVar6,uVar2,param_4);
        local_28 = 0x20000;
      }
      else {
        *(undefined4 *)(param_1 + 0xc) = 1;
        *(undefined4 *)(iVar7 + 0x90) = 1;
        puVar8 = (undefined4 *)local_38[2];
        *puVar8 = *(undefined4 *)(iVar7 + 0x2c);
        puVar8[1] = 0;
        puVar8[2] = param_1;
        DAT_c099682c = param_1;
        WriteMsgQueue(*(undefined4 *)(*(int *)(iVar3 + 0x20) + 4),&local_38,4,0,0);
        local_34 = *(UINT **)(param_1 + 0x18);
        timeKillEvent(*local_34);
        local_30 = *(UINT **)(param_1 + 0x1c);
        timeKillEvent(*local_30);
        local_2c = GetTickCount();
        *(DWORD *)(iVar7 + 0x20) = *(int *)(iVar7 + 0x20) - local_2c;
        FUN_c098ac24(*(MMRESULT **)(param_1 + 0x18),1000);
        local_28 = 1;
      }
    }
  }
  return local_28;
}



/* c0988750 FUN_c0988750 */

/* Boundary evidence: original MIPS .pdata c0988750..c0988773. Semantic name remains unreviewed. */

void FUN_c0988750(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  FUN_c098e904((int *)&DAT_c09966cc,param_1,param_3,param_4);
  return;
}



/* c0988774 FUN_c0988774 */

/* Boundary evidence: original MIPS .pdata c0988774..c0988797. Semantic name remains unreviewed. */

undefined4 FUN_c0988774(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  FUN_c098ec5c((int *)&DAT_c09966cc,param_2,param_3,param_4);
  return 0;
}



/* c0988798 FUN_c0988798 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Boundary evidence: original MIPS .pdata c0988798..c0988987. Semantic name remains unreviewed. */

undefined4 FUN_c0988798(int param_1,int param_2)

{
  undefined4 uVar1;
  uint local_18;
  undefined4 local_c;
  
  local_18 = (uint)(*(int *)(param_1 + 0x38) != *(int *)(param_1 + 0x3c));
  if (*(int *)(param_1 + 0x40) != *(int *)(param_1 + 0x44)) {
    local_18 = local_18 | 2;
  }
  if (local_18 == 0) {
    local_c = 0xffffffff;
  }
  else {
    uVar1 = 6;
    FUN_c098ef70(param_2,0,param_1 + 0x38,6);
    if (*(int *)(param_1 + 0x50) != 0) {
      if ((*(uint *)(param_1 + 0x50) & 1) != 0) {
        FUN_c098d4d4(param_2,0x44,*(undefined4 *)(param_1 + 0x54),uVar1);
        FUN_c098d4d4(param_2,0x3c,1,uVar1);
      }
      if ((*(uint *)(param_1 + 0x50) & 2) != 0) {
        FUN_c098d4d4(param_2,0x48,*(undefined4 *)(param_1 + 0x58),uVar1);
        FUN_c098d4d4(param_2,0x40,1,uVar1);
      }
    }
    if ((*(uint *)(param_1 + 0x50) & 2) == 0) {
      *(undefined4 *)(param_1 + 0xa0) = 1;
      FUN_c098d4d4(param_2,0x48,10,uVar1);
      FUN_c098d4d4(param_2,0x40,1,uVar1);
    }
    CacheRangeFlush(0,0,0x24);
    SYNC(0);
    SYNC(0);
    _DAT_b9800018 = _DAT_b9800018 & 0xfdff;
    SYNC(0);
    FUN_c098d4d4(param_2,0x20,local_18,uVar1);
    local_c = 0;
  }
  return local_c;
}



/* c0988988 FUN_c0988988 */

/* Boundary evidence: original MIPS .pdata c0988988..c0988a17. Semantic name remains unreviewed. */

undefined4 FUN_c0988988(int param_1,undefined4 *param_2,int param_3,undefined4 param_4)

{
  int *_Dst;
  undefined4 uVar1;
  undefined4 uVar2;
  
  _Dst = malloc(0x2c);
  if (_Dst == (int *)0x0) {
    uVar1 = 0xffffffff;
  }
  else {
    uVar2 = 0x2c;
    uVar1 = 0;
    memset(_Dst,0,0x2c);
    *param_2 = _Dst;
    *_Dst = (int)&DAT_c09966cc;
    _Dst[8] = param_3;
    _Dst[9] = param_1;
    FUN_c098f1f0(_Dst,uVar1,uVar2,param_4);
    uVar1 = 0;
  }
  return uVar1;
}



/* c0988a18 FUN_c0988a18 */

/* Boundary evidence: original MIPS .pdata c0988a18..c0988a37. Semantic name remains unreviewed. */

void FUN_c0988a18(undefined4 param_1,char *param_2,undefined4 param_3,undefined4 param_4)

{
  FUN_c098f67c((int *)&DAT_c09966cc,param_2,param_3,param_4);
  return;
}



/* c0988a38 FUN_c0988a38 */

/* Boundary evidence: original MIPS .pdata c0988a38..c0988ce3. Semantic name remains unreviewed. */

void FUN_c0988a38(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  
  if (DAT_c0996798 == 0) {
    FUN_c098d4d4(param_1,0x2c,0,param_4);
    uVar4 = 0x200;
    FUN_c098d4d4(param_1,0x20,0x200,param_4);
    iVar5 = 0;
    do {
      uVar1 = FUN_c098d590(param_1,0x68,uVar4,param_4);
      uVar1 = uVar1 & 4;
      if (uVar1 != 0) break;
      StallExecution(10);
      iVar5 = iVar5 + 1;
    } while (iVar5 < 0x14);
    if ((iVar5 == 0x14) && (*(int *)(param_1 + 0x3c) != 0)) {
      FUN_c098721c(*(int *)(param_1 + 0x3c),uVar1,uVar4,param_4);
    }
    else {
      FUN_c098d4d4(param_1,0x34,0xc0ffe000,param_4);
      uVar4 = 0x20;
      FUN_c098d4d4(param_1,0x20,0x20,param_4);
      iVar5 = 0;
      do {
        if (DAT_c0996798 == 0) {
          if (*(uint *)(param_1 + 0x28) < 0x35) {
            FUN_c098b68c("Mali: ERR: %s\n","src/devicedrv/mali/common/mali_rendercore.c",uVar4,
                         param_4);
            FUN_c098b68c("           %s()%4d\n           ","mali_core_renderunit_register_write",
                         0x11a,param_4);
            uVar4 = *(undefined4 *)(param_1 + 0x2c);
            uVar3 = 0x34;
            FUN_c098b68c("Trying to write to illegal register: 0x%04x in core: %s",0x34,uVar4,
                         param_4);
            FUN_c098b68c("\n",uVar3,uVar4,param_4);
          }
          else {
            *(undefined4 *)(*(int *)(param_1 + 0x20) + 0x34) = 0xc01a0000;
          }
        }
        iVar2 = FUN_c098d590(param_1,0x34,uVar4,param_4);
      } while ((iVar2 != -0x3fe60000) && (iVar5 = iVar5 + 1, iVar5 < 0xf));
      if (DAT_c0996798 == 0) {
        if (*(uint *)(param_1 + 0x28) < 0x35) {
          FUN_c098b68c("Mali: ERR: %s\n","src/devicedrv/mali/common/mali_rendercore.c",uVar4,param_4
                      );
          FUN_c098b68c("           %s()%4d\n           ","mali_core_renderunit_register_write",0x11a
                       ,param_4);
          uVar4 = *(undefined4 *)(param_1 + 0x2c);
          uVar3 = 0x34;
          FUN_c098b68c("Trying to write to illegal register: 0x%04x in core: %s",0x34,uVar4,param_4)
          ;
          FUN_c098b68c("\n",uVar3,uVar4,param_4);
          if (DAT_c0996798 != 0) {
            return;
          }
        }
        else {
          *(undefined4 *)(*(int *)(param_1 + 0x20) + 0x34) = 0;
        }
        if (*(uint *)(param_1 + 0x28) < 0x29) {
          FUN_c098b68c("Mali: ERR: %s\n","src/devicedrv/mali/common/mali_rendercore.c",uVar4,param_4
                      );
          FUN_c098b68c("           %s()%4d\n           ","mali_core_renderunit_register_write",0x11a
                       ,param_4);
          uVar3 = *(undefined4 *)(param_1 + 0x2c);
          uVar4 = 0x28;
          FUN_c098b68c("Trying to write to illegal register: 0x%04x in core: %s",0x28,uVar3,param_4)
          ;
          FUN_c098b68c("\n",uVar4,uVar3,param_4);
        }
        else {
          *(undefined4 *)(*(int *)(param_1 + 0x20) + 0x28) = 0xfff;
        }
      }
    }
  }
  return;
}



/* c0988ce4 FUN_c0988ce4 */

/* Boundary evidence: original MIPS .pdata c0988ce4..c0988d1f. Semantic name remains unreviewed. */

void FUN_c0988ce4(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  if (DAT_c0996798 == 0) {
    FUN_c0988a38(param_1,param_2,param_3,param_4);
    FUN_c0987b10(param_1,param_2,param_3,param_4);
  }
  return;
}



/* c0988d20 FUN_c0988d20 */

/* Boundary evidence: original MIPS .pdata c0988d20..c0988d8b. Semantic name remains unreviewed. */

void FUN_c0988d20(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  if (param_2 == 0) {
    if (DAT_c0996798 == 0) {
      FUN_c0988a38(param_1,0,param_3,param_4);
      FUN_c0987b10(param_1,param_2,param_3,param_4);
      return;
    }
  }
  else {
    FUN_c0988a38(param_1,param_2,param_3,param_4);
    FUN_c098d4d4(param_1,0x2c,0,param_4);
  }
  return;
}



/* c0988d8c FUN_c0988d8c */

/* Boundary evidence: original MIPS .pdata c0988d8c..c0988ddf. Semantic name remains unreviewed. */

void FUN_c0988d8c(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int *piVar1;
  
  if (((*param_1 != 0) && (DAT_c0996168 < 5)) &&
     (piVar1 = *(int **)(DAT_c0996168 * 4 + *param_1), piVar1 != (int *)0x0)) {
    FUN_c0990b7c(piVar1,(char *)param_1[1],param_3,param_4);
  }
  return;
}



/* c0988de0 FUN_c0988de0 */

/* Boundary evidence: original MIPS .pdata c0988de0..c09890a3. Semantic name remains unreviewed. */

int FUN_c0988de0(int *param_1,void *param_2,undefined4 param_3,undefined4 param_4)

{
  char *_Memory;
  void *pvVar1;
  undefined4 *puVar2;
  char *pcVar3;
  undefined4 uVar4;
  int *piVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  int local_28 [2];
  
  iVar8 = 0;
  _Memory = calloc(1,0xa8);
  if (_Memory == (char *)0x0) {
    iVar8 = -1;
  }
  else {
    uVar4 = 0x48;
    pvVar1 = memcpy(_Memory + 0x28,param_2,0x48);
    if (pvVar1 == (void *)0x0) {
      FUN_c098b68c("Mali: ERR: %s\n","src/devicedrv/mali/common/mali_kernel_GP2.c",uVar4,param_4);
      uVar4 = 0x421;
      pcVar3 = "subsystem_maligp_get_new_job_from_user";
      FUN_c098b68c("           %s()%4d\n           ","subsystem_maligp_get_new_job_from_user",0x421,
                   param_4);
      FUN_c098b68c("Mali GP: Could not copy data from U/K interface.\n",pcVar3,uVar4,param_4);
      FUN_c098b68c("\n",pcVar3,uVar4,param_4);
      iVar8 = -1;
    }
    else {
      *(int **)(_Memory + 8) = param_1;
      if (*(uint *)(_Memory + 0x30) < 3) {
        *(uint *)(_Memory + 0x10) = *(uint *)(_Memory + 0x30);
      }
      else {
        _Memory[0x10] = '\x02';
        _Memory[0x11] = '\0';
        _Memory[0x12] = '\0';
        _Memory[0x13] = '\0';
      }
      uVar7 = *(uint *)(_Memory + 0x34);
      if (uVar7 == 0) {
        _Memory[0x14] = -0x60;
        _Memory[0x15] = -0x45;
        _Memory[0x16] = '\r';
        _Memory[0x17] = '\0';
      }
      else if (uVar7 < 0x36ee81) {
        if (uVar7 < 200) {
          _Memory[0x14] = -0x38;
          _Memory[0x15] = '\0';
          _Memory[0x16] = '\0';
          _Memory[0x17] = '\0';
        }
        else {
          *(uint *)(_Memory + 0x14) = uVar7;
        }
      }
      else {
        _Memory[0x14] = -0x80;
        _Memory[0x15] = -0x12;
        _Memory[0x16] = '6';
        _Memory[0x17] = '\0';
      }
      *(undefined4 *)(_Memory + 0x88) = *(undefined4 *)(_Memory + 0x48);
      *(undefined4 *)(_Memory + 0x24) = *(undefined4 *)(_Memory + 100);
      _Memory[0x90] = '\0';
      _Memory[0x91] = '\0';
      _Memory[0x92] = '\0';
      _Memory[0x93] = '\0';
      if ((param_1[3] == 0) || (*(uint *)(_Memory + 0x10) < *(uint *)(param_1[3] + 0x10))) {
        _Memory[0x94] = 'g';
        _Memory[0x95] = '\x0e';
        _Memory[0x96] = '\0';
        _Memory[0x97] = '\0';
        puVar2 = FUN_c098ae0c(0x30010,0x40);
        *(undefined4 **)(_Memory + 0x8c) = puVar2;
        if (puVar2 == (undefined4 *)0x0) {
          FUN_c098b68c("Mali: ERR: %s\n","src/devicedrv/mali/common/mali_kernel_GP2.c",uVar4,param_4
                      );
          uVar4 = 0x453;
          pcVar3 = "subsystem_maligp_get_new_job_from_user";
          FUN_c098b68c("           %s()%4d\n           ","subsystem_maligp_get_new_job_from_user",
                       0x453,param_4);
          FUN_c098b68c("Mali GP: Could not get notification_obj.\n",pcVar3,uVar4,param_4);
          FUN_c098b68c("\n",pcVar3,uVar4,param_4);
          iVar8 = -4;
        }
        else {
          piVar5 = local_28;
          *(char **)_Memory = _Memory;
          *(char **)(_Memory + 4) = _Memory;
          iVar8 = FUN_c0990688(param_1,_Memory,piVar5,param_4);
          if (iVar8 < 0) {
            FUN_c098b68c("Mali: ERR: %s\n","src/devicedrv/mali/common/mali_kernel_GP2.c",piVar5,
                         param_4);
            uVar4 = 0x460;
            pcVar3 = "subsystem_maligp_get_new_job_from_user";
            FUN_c098b68c("           %s()%4d\n           ","subsystem_maligp_get_new_job_from_user",
                         0x460,param_4);
            FUN_c098b68c("Mali GP: Internal error\n",pcVar3,uVar4,param_4);
            FUN_c098b68c("\n",pcVar3,uVar4,param_4);
            *(undefined4 *)((int)param_2 + 0x38) = 2;
            iVar6 = *(int *)(_Memory + 0x8c);
            free(*(void **)(iVar6 + 8));
            free((void *)(iVar6 + -8));
          }
          else if (local_28[0] == 0) {
            *(undefined4 *)((int)param_2 + 0x38) = 0;
          }
          else {
            *(undefined4 *)((int)param_2 + 0x34) = *(undefined4 *)(local_28[0] + 0x2c);
            *(undefined4 *)((int)param_2 + 0x38) = 1;
          }
        }
      }
      else {
        *(undefined4 *)((int)param_2 + 0x38) = 2;
      }
    }
    if ((*(int *)((int)param_2 + 0x38) == 2) || (iVar8 != 0)) {
      free(_Memory);
    }
  }
  return iVar8;
}



/* c09890a4 FUN_c09890a4 */

/* Boundary evidence: original MIPS .pdata c09890a4..c098914b. Semantic name remains unreviewed. */

void FUN_c09890a4(undefined4 param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4)

{
  char *pcVar1;
  undefined4 uVar2;
  int *_Memory;
  
  if ((param_2 != (undefined4 *)0x0) && (_Memory = (int *)*param_2, _Memory != (int *)0x0)) {
    FUN_c09908f0(_Memory,param_2,param_3,param_4);
    free(_Memory);
    *param_2 = 0;
    return;
  }
  FUN_c098b68c("Mali: ERR: %s\n","src/devicedrv/mali/common/mali_kernel_GP2.c",param_3,param_4);
  uVar2 = 0x110;
  pcVar1 = "maligp_subsystem_session_end";
  FUN_c098b68c("           %s()%4d\n           ","maligp_subsystem_session_end",0x110,param_4);
  FUN_c098b68c("Input slot==NULL",pcVar1,uVar2,param_4);
  FUN_c098b68c("\n",pcVar1,uVar2,param_4);
  return;
}



/* c098914c FUN_c098914c */

/* Boundary evidence: original MIPS .pdata c098914c..c09893df. Semantic name remains unreviewed. */

int FUN_c098914c(int *param_1,int *param_2,undefined *param_3,int *param_4)

{
  int *_Memory;
  int iVar1;
  char *pcVar2;
  undefined4 uVar3;
  
  if (*param_1 == 4) {
    if (param_1[4] != 0) {
      FUN_c098b68c("Mali: ERR: %s\n","src/devicedrv/mali/common/mali_kernel_GP2.c",param_3,param_4);
      uVar3 = 0x13c;
      pcVar2 = "maligp_renderunit_create";
      FUN_c098b68c("           %s()%4d\n           ","maligp_renderunit_create",0x13c,param_4);
      FUN_c098b68c("Memory size set to MaliGP2 core should be zero.",pcVar2,uVar3,param_4);
      FUN_c098b68c("\n",pcVar2,uVar3,param_4);
      return -1;
    }
    if (param_1[1] == 0) {
      FUN_c098b68c("Mali: ERR: %s\n","src/devicedrv/mali/common/mali_kernel_GP2.c",param_3,param_4);
      uVar3 = 0x142;
      pcVar2 = "maligp_renderunit_create";
      FUN_c098b68c("           %s()%4d\n           ","maligp_renderunit_create",0x142,param_4);
      FUN_c098b68c("A MaliGP2 core needs a unique description field",pcVar2,uVar3,param_4);
      FUN_c098b68c("\n",pcVar2,uVar3,param_4);
      return -1;
    }
    _Memory = malloc(0x44);
    if (_Memory != (int *)0x0) {
      *_Memory = (int)&DAT_c09966cc;
      _Memory[9] = param_1[2];
      _Memory[10] = 0x98;
      _Memory[0xb] = param_1[1];
      _Memory[0xc] = param_1[5];
      _Memory[0xe] = param_1[7];
      _Memory[0xf] = 0;
      iVar1 = FUN_c098ee20((int)_Memory,param_2,param_3,param_4);
      if (iVar1 == 0) {
        iVar1 = FUN_c098d270((int)_Memory,param_2,param_3,param_4);
        if (iVar1 == 0) {
          if (DAT_c0996798 == 0) {
            param_2 = (int *)0x6c;
            iVar1 = FUN_c098d590((int)_Memory,0x6c,param_3,param_4);
            _Memory[0xd] = iVar1;
          }
          else {
            _Memory[0xd] = 0xa070000;
          }
          iVar1 = FUN_c0987bf8((int)_Memory,param_2,param_3,param_4);
          if (iVar1 == 0) {
            if (DAT_c0996798 == 0) {
              FUN_c0988a38((int)_Memory,param_2,param_3,param_4);
              FUN_c0987b10((int)_Memory,param_2,param_3,param_4);
            }
            param_2 = _Memory;
            iVar1 = FUN_c0991724((int *)&DAT_c09966cc,_Memory,param_3,param_4);
            if (iVar1 == 0) {
              return 0;
            }
          }
          FUN_c098d1dc((int)_Memory,param_2,param_3,param_4);
        }
        FUN_c098d388((int)_Memory);
      }
      free(_Memory);
      FUN_c098b68c("Mali: ERR: %s\n","src/devicedrv/mali/common/mali_kernel_GP2.c",param_3,param_4);
      uVar3 = 0x185;
      pcVar2 = "maligp_renderunit_create";
      FUN_c098b68c("           %s()%4d\n           ","maligp_renderunit_create",0x185,param_4);
      FUN_c098b68c("Renderunit NOT created.",pcVar2,uVar3,param_4);
      FUN_c098b68c("\n",pcVar2,uVar3,param_4);
      return iVar1;
    }
  }
  else {
    FUN_c098b68c("Mali: ERR: %s\n","src/devicedrv/mali/common/mali_kernel_GP2.c",param_3,param_4);
    uVar3 = 0x130;
    pcVar2 = "maligp_renderunit_create";
    FUN_c098b68c("           %s()%4d\n           ","maligp_renderunit_create",0x130,param_4);
    FUN_c098b68c("Can not register this resource as a MaliGP2 core.",pcVar2,uVar3,param_4);
    FUN_c098b68c("\n",pcVar2,uVar3,param_4);
  }
  return -1;
}



/* c09893e0 FUN_c09893e0 */

/* Boundary evidence: original MIPS .pdata c09893e0..c09894e3. Semantic name remains unreviewed. */

int FUN_c09893e0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  uVar3 = 0x74;
  uVar2 = 0;
  DAT_c0996168 = param_1;
  memset(&DAT_c09966cc,0,0x74);
  DAT_c0996714 = FUN_c0988798;
  DAT_c0996718 = FUN_c0987a88;
  DAT_c099671c = FUN_c0987f7c;
  DAT_c0996720 = FUN_c0988de0;
  DAT_c0996724 = FUN_c0987de0;
  DAT_c0996728 = FUN_c09878d8;
  DAT_c099672c = FUN_c09878bc;
  DAT_c0996730 = FUN_c0988d20;
  DAT_c099673c = FUN_c0987bd8;
  DAT_c0996734 = FUN_c0987874;
  DAT_c0996738 = FUN_c0987800;
  DAT_c099670c = "MaliGP2";
  DAT_c09966d4 = 2;
  DAT_c0996710 = param_1;
  iVar1 = FUN_c098ed0c(-0x3f669934,uVar2,uVar3,param_4);
  if (iVar1 == 0) {
    iVar1 = 0;
    DAT_c0996770 = FUN_c098914c;
  }
  return iVar1;
}



/* c09894e4 FUN_c09894e4 */

/* Boundary evidence: original MIPS .pdata c09894e4..c098950b. Semantic name remains unreviewed. */

void FUN_c09894e4(char *param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  FUN_c0991b2c((int *)&DAT_c09966cc,param_1,param_2,param_4);
  return;
}



/* c09895bc FUN_c09895bc */

/* Boundary evidence: original MIPS .pdata c09895bc..c098962f. Semantic name remains unreviewed. */

undefined4 FUN_c09895bc(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  uint uVar1;
  undefined4 local_c;
  
  uVar1 = FUN_c098d590(param_1,0x102c,param_3,param_4);
  if ((uVar1 & 8) == 0) {
    local_c = 0xffffffff;
  }
  else {
    FUN_c098d4d4(param_1,0x1024,8,param_4);
    SYNC(0);
    local_c = 0;
  }
  return local_c;
}



/* c0989630 FUN_c0989630 */

/* Boundary evidence: original MIPS .pdata c0989630..c0989677. Semantic name remains unreviewed. */

void FUN_c0989630(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  FUN_c098d4d4(param_1,0x1028,0x11d,param_4);
  FUN_c098d4d4(param_1,0x1020,8,param_4);
  SYNC(0);
  return;
}



/* c0989678 FUN_c0989678 */

/* Boundary evidence: original MIPS .pdata c0989678..c0989693. Semantic name remains unreviewed. */

void FUN_c0989678(void *param_1)

{
  free(param_1);
  return;
}



/* c0989694 FUN_c0989694 */

/* Boundary evidence: original MIPS .pdata c0989694..c098981b. Semantic name remains unreviewed. */

void FUN_c0989694(void *param_1,int param_2)

{
  int iVar1;
  undefined4 *_Dst;
  int iVar2;
  undefined4 local_20 [2];
  
  if (param_1 == (void *)0x0) {
    return;
  }
  if (*(int *)((int)param_1 + 0x14c) == 0) {
    return;
  }
  _Dst = *(undefined4 **)(*(int *)((int)param_1 + 0x14c) + 8);
  iVar2 = *(int *)((int)param_1 + 8);
  memset(_Dst,0,0x3c);
  *_Dst = *(undefined4 *)((int)param_1 + 0x2c);
  if (param_2 < 0x100001) {
    if (param_2 != 0x100000) {
      if (param_2 < 0x20001) {
        if (((param_2 != 0x20000) && (param_2 != 1)) && (param_2 != 0x10000)) {
LAB_c0989814:
          _Dst[1] = 0x800000;
          goto LAB_c0989740;
        }
      }
      else if (param_2 != 0x40000) {
        iVar1 = 0x80000;
        goto LAB_c098980c;
      }
    }
  }
  else if (param_2 < 0x800001) {
    if (((param_2 != 0x800000) && (param_2 != 0x200000)) && (param_2 != 0x400000)) {
      _Dst[1] = 0x800000;
      goto LAB_c0989740;
    }
  }
  else if (param_2 != 0x1000000) {
    iVar1 = 0x2000000;
LAB_c098980c:
    if (param_2 != iVar1) goto LAB_c0989814;
  }
  _Dst[1] = param_2;
LAB_c0989740:
  _Dst[2] = *(undefined4 *)((int)param_1 + 0x138);
  _Dst[6] = *(undefined4 *)((int)param_1 + 0x13c);
  _Dst[7] = *(undefined4 *)((int)param_1 + 0x140);
  _Dst[8] = *(undefined4 *)((int)param_1 + 0x18);
  local_20[0] = *(undefined4 *)((int)param_1 + 0x14c);
  WriteMsgQueue(*(undefined4 *)(*(int *)(iVar2 + 0x20) + 4),local_20,4,0,0);
  *(undefined4 *)((int)param_1 + 0x14c) = 0;
  free(param_1);
  return;
}



/* c098981c FUN_c098981c */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Boundary evidence: original MIPS .pdata c098981c..c09898f3. Semantic name remains unreviewed. */

bool FUN_c098981c(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  bool local_10;
  
  _DAT_b9800018 = _DAT_b9800018 | 0x400;
  SYNC(0);
  if (DAT_c0996798 == 0) {
    iVar1 = FUN_c098d590(param_1,0x102c,param_3,param_4);
    if (iVar1 == 0) {
      local_10 = false;
    }
    else {
      FUN_c098d4d4(param_1,0x1028,0,param_4);
      local_10 = true;
    }
  }
  else {
    local_10 = *(int *)(param_1 + 0x10) != 0;
  }
  return local_10;
}



/* c09898f4 FUN_c09898f4 */

/* Boundary evidence: original MIPS .pdata c09898f4..c0989913. Semantic name remains unreviewed. */

void FUN_c09898f4(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  FUN_c098d4d4(param_1,0x1028,0x11d,param_4);
  return;
}



/* c0989914 FUN_c0989914 */

/* Boundary evidence: original MIPS .pdata c0989914..c0989933. Semantic name remains unreviewed. */

void FUN_c0989914(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  FUN_c098d4d4(param_1,0x100c,1,param_4);
  return;
}



/* c0989934 FUN_c0989934 */

/* Boundary evidence: original MIPS .pdata c0989934..c09899cb. Semantic name remains unreviewed. */

undefined4 FUN_c0989934(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  if ((*(uint *)(param_1 + 0x34) & 0xffff0000) != 0xc8070000) {
    FUN_c098b68c("Mali: ERR: %s\n","src/devicedrv/mali/common/mali_kernel_MALI200.c",param_3,param_4
                );
    uVar2 = 0x19a;
    FUN_c098b68c("           %s()%4d\n           ","mali200_core_version_legal",0x19a,param_4);
    uVar1 = *(undefined4 *)(param_1 + 0x34);
    FUN_c098b68c("Error: reading this from Mali200 version register: 0x%x\n",uVar1,uVar2,param_4);
    FUN_c098b68c("\n",uVar1,uVar2,param_4);
    return 0xffffffff;
  }
  return 0;
}



/* c09899cc FUN_c09899cc */

/* Boundary evidence: original MIPS .pdata c09899cc..c0989a3b. Semantic name remains unreviewed. */

undefined4 FUN_c09899cc(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  
  if (*param_1 == 0) {
    return 0xfffffffd;
  }
  if ((DAT_c0996190 < 5) &&
     (puVar2 = *(undefined4 **)(DAT_c0996190 * 4 + *param_1), puVar2 != (undefined4 *)0x0)) {
    uVar1 = FUN_c098e398(puVar2,param_1 + 1,param_3,param_4);
    return uVar1;
  }
  return 0xffffffff;
}



/* c0989a3c FUN_c0989a3c */

/* Boundary evidence: original MIPS .pdata c0989a3c..c0989aab. Semantic name remains unreviewed. */

undefined4 FUN_c0989a3c(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  int *piVar2;
  
  if (*param_1 == 0) {
    return 0xfffffffd;
  }
  if ((DAT_c0996190 < 5) && (piVar2 = *(int **)(DAT_c0996190 * 4 + *param_1), piVar2 != (int *)0x0))
  {
    uVar1 = FUN_c098e6b0(piVar2,param_1,param_3,param_4);
    return uVar1;
  }
  return 0xffffffff;
}



/* c0989aac FUN_c0989aac */

/* Boundary evidence: original MIPS .pdata c0989aac..c0989d33. Semantic name remains unreviewed. */

undefined4 FUN_c0989aac(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  UINT UVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  
  iVar4 = *(int *)(param_1 + 0x10);
  uVar5 = 1;
  if (DAT_c0996798 == 0) {
    uVar5 = FUN_c098d590(param_1,0x1020,param_3,param_4);
    uVar5 = uVar5 & 0x11d;
    iVar6 = FUN_c098d590(param_1,0x1004,param_3,param_4);
    uVar7 = FUN_c098d590(param_1,0x1008,param_3,param_4);
  }
  else {
    iVar6 = 0;
    uVar7 = 0;
  }
  if (iVar4 == 0) {
    if (uVar5 != 0) {
      FUN_c098b68c("Mali: ERR: %s\n","src/devicedrv/mali/common/mali_kernel_MALI200.c",param_3,
                   param_4);
      FUN_c098b68c("           %s()%4d\n           ","subsystem_mali200_irq_handler_bottom_half",
                   0x2e9,param_4);
      FUN_c098b68c("Interrupt from a core not running a job. IRQ: 0x%04x Status: 0x%04x",uVar5,uVar7
                   ,param_4);
      FUN_c098b68c("\n",uVar5,uVar7,param_4);
    }
    return 0x800000;
  }
  *(uint *)(iVar4 + 0x138) = *(uint *)(iVar4 + 0x138) | uVar5;
  if ((uVar5 & 1) != 0) {
    CacheRangeFlush(0,0,0x24);
    uVar3 = 8;
    FUN_c098d4d4(param_1,0x100c,8,param_4);
    if ((*(uint *)(iVar4 + 0x118) != 0) && ((*(uint *)(iVar4 + 0x118) & 3) != 0)) {
      uVar2 = FUN_c098d590(param_1,0x108c,uVar3,param_4);
      *(undefined4 *)(iVar4 + 0x13c) = uVar2;
      uVar3 = FUN_c098d590(param_1,0x10ac,uVar3,param_4);
      *(undefined4 *)(iVar4 + 0x140) = uVar3;
    }
    return 0x10000;
  }
  if (*(int *)(param_1 + 0xc) == 2) {
LAB_c0989d10:
    uVar3 = 0x100000;
  }
  else {
    if (*(int *)(param_1 + 0xc) == 4) {
      if (iVar6 == *(int *)(iVar4 + 0x144)) goto LAB_c0989d10;
    }
    else if ((*(uint *)(iVar4 + 0x148) & uVar5 & 4) == 0) {
      if ((uVar5 == 0) && ((uVar7 & 1) != 0)) {
        FUN_c098d4d4(param_1,0x1024,0,param_4);
        FUN_c098d4d4(param_1,0x1028,*(undefined4 *)(iVar4 + 0x148),param_4);
        return 1;
      }
      if ((uVar5 & 0x10) != 0) {
        FUN_c098d590(param_1,0x1050,param_3,param_4);
      }
      return 0x800000;
    }
    if ((int)DAT_c09961b0 < 0x7d1) {
      if ((int)DAT_c09961b0 < 100) {
        DAT_c09961b0 = 100;
      }
    }
    else {
      DAT_c09961b0 = 2000;
    }
    UVar1 = DAT_c09961b0;
    *(int *)(iVar4 + 0x144) = iVar6;
    FUN_c098ac24(*(MMRESULT **)(param_1 + 0x1c),UVar1);
    *(uint *)(iVar4 + 0x148) = *(uint *)(iVar4 + 0x148) & 0xfffffffb;
    FUN_c098d4d4(param_1,0x1024,uVar5 & 0xfffffffb,param_4);
    FUN_c098d4d4(param_1,0x1028,*(undefined4 *)(iVar4 + 0x148),param_4);
    uVar3 = 1;
  }
  return uVar3;
}



/* c0989d34 FUN_c0989d34 */

/* Boundary evidence: original MIPS .pdata c0989d34..c0989d57. Semantic name remains unreviewed. */

void FUN_c0989d34(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  FUN_c098e904((int *)&DAT_c0996658,param_1,param_3,param_4);
  return;
}



/* c0989d58 FUN_c0989d58 */

/* Boundary evidence: original MIPS .pdata c0989d58..c0989d7b. Semantic name remains unreviewed. */

undefined4 FUN_c0989d58(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  FUN_c098ec5c((int *)&DAT_c0996658,param_2,param_3,param_4);
  return 0;
}



/* c0989d7c FUN_c0989d7c */

/* Boundary evidence: original MIPS .pdata c0989d7c..c0989daf. Semantic name remains unreviewed. */

void FUN_c0989d7c(void)

{
  CacheRangeFlush(0,0,0x24);
  SYNC(0);
  SYNC(0);
  return;
}



/* c0989db0 FUN_c0989db0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Boundary evidence: original MIPS .pdata c0989db0..c0989f9f. Semantic name remains unreviewed. */

undefined4 FUN_c0989db0(int param_1,int param_2)

{
  undefined4 uVar1;
  undefined4 local_10;
  
  if ((*(int *)(param_1 + 0x38) == 0) || (*(int *)(param_1 + 0x3c) == 0)) {
    local_10 = 0xffffffff;
  }
  else {
    uVar1 = 0x14;
    FUN_c098ef70(param_2,0,param_1 + 0x38,0x14);
    if (*(int *)(param_1 + 0x88) == 0) {
      FUN_c098d4d4(param_2,0x100,0,uVar1);
    }
    else {
      FUN_c098ef70(param_2,0x100,param_1 + 0x88,0xc);
    }
    FUN_c098ef70(param_2,0x200,param_1 + 0xb8,0xc);
    uVar1 = 0xc;
    FUN_c098ef70(param_2,0x300,param_1 + 0xe8,0xc);
    if (*(int *)(param_1 + 0x118) != 0) {
      if ((*(uint *)(param_1 + 0x118) & 1) != 0) {
        FUN_c098d4d4(param_2,0x1080,1,uVar1);
        FUN_c098d4d4(param_2,0x1084,*(undefined4 *)(param_1 + 0x11c),uVar1);
      }
      if ((*(uint *)(param_1 + 0x118) & 2) != 0) {
        FUN_c098d4d4(param_2,0x10a0,1,uVar1);
        FUN_c098d4d4(param_2,0x10a4,*(undefined4 *)(param_1 + 0x120),uVar1);
      }
    }
    _DAT_b9800018 = _DAT_b9800018 & 0xfbff;
    SYNC(0);
    CacheRangeFlush(0,0,0x24);
    SYNC(0);
    SYNC(0);
    FUN_c098d4d4(param_2,0x100c,0x40,uVar1);
    local_10 = 0;
  }
  return local_10;
}



/* c0989fa0 FUN_c0989fa0 */

/* Boundary evidence: original MIPS .pdata c0989fa0..c098a02f. Semantic name remains unreviewed. */

undefined4 FUN_c0989fa0(int param_1,undefined4 *param_2,int param_3,undefined4 param_4)

{
  int *_Dst;
  undefined4 uVar1;
  undefined4 uVar2;
  
  _Dst = malloc(0x2c);
  if (_Dst == (int *)0x0) {
    uVar1 = 0xfffffffc;
  }
  else {
    uVar2 = 0x2c;
    uVar1 = 0;
    memset(_Dst,0,0x2c);
    *param_2 = _Dst;
    *_Dst = (int)&DAT_c0996658;
    _Dst[8] = param_3;
    _Dst[9] = param_1;
    FUN_c098f1f0(_Dst,uVar1,uVar2,param_4);
    uVar1 = 0;
  }
  return uVar1;
}



/* c098a030 FUN_c098a030 */

/* Boundary evidence: original MIPS .pdata c098a030..c098a04f. Semantic name remains unreviewed. */

void FUN_c098a030(undefined4 param_1,char *param_2,undefined4 param_3,undefined4 param_4)

{
  FUN_c098f67c((int *)&DAT_c0996658,param_2,param_3,param_4);
  return;
}



/* c098a050 FUN_c098a050 */

/* Boundary evidence: original MIPS .pdata c098a050..c098a2fb. Semantic name remains unreviewed. */

void FUN_c098a050(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  
  if (DAT_c0996798 == 0) {
    FUN_c098d4d4(param_1,0x1028,0,param_4);
    uVar4 = 1;
    FUN_c098d4d4(param_1,0x100c,1,param_4);
    iVar5 = 0;
    do {
      uVar1 = FUN_c098d590(param_1,0x1008,uVar4,param_4);
      uVar1 = uVar1 & 0x10;
      if (uVar1 != 0) break;
      StallExecution(10);
      iVar5 = iVar5 + 1;
    } while (iVar5 < 0x14);
    if ((iVar5 == 0x14) && (*(int *)(param_1 + 0x3c) != 0)) {
      FUN_c098721c(*(int *)(param_1 + 0x3c),uVar1,uVar4,param_4);
    }
    else {
      FUN_c098d4d4(param_1,0x1044,0xc0ffe000,param_4);
      uVar4 = 0x20;
      FUN_c098d4d4(param_1,0x100c,0x20,param_4);
      iVar5 = 0;
      do {
        if (DAT_c0996798 == 0) {
          if (*(uint *)(param_1 + 0x28) < 0x1045) {
            FUN_c098b68c("Mali: ERR: %s\n","src/devicedrv/mali/common/mali_rendercore.c",uVar4,
                         param_4);
            FUN_c098b68c("           %s()%4d\n           ","mali_core_renderunit_register_write",
                         0x11a,param_4);
            uVar4 = *(undefined4 *)(param_1 + 0x2c);
            uVar3 = 0x1044;
            FUN_c098b68c("Trying to write to illegal register: 0x%04x in core: %s",0x1044,uVar4,
                         param_4);
            FUN_c098b68c("\n",uVar3,uVar4,param_4);
          }
          else {
            *(undefined4 *)(*(int *)(param_1 + 0x20) + 0x1044) = 0xc01a0000;
          }
        }
        iVar2 = FUN_c098d590(param_1,0x1044,uVar4,param_4);
      } while ((iVar2 != -0x3fe60000) && (iVar5 = iVar5 + 1, iVar5 < 0xf));
      if (DAT_c0996798 == 0) {
        if (*(uint *)(param_1 + 0x28) < 0x1045) {
          FUN_c098b68c("Mali: ERR: %s\n","src/devicedrv/mali/common/mali_rendercore.c",uVar4,param_4
                      );
          FUN_c098b68c("           %s()%4d\n           ","mali_core_renderunit_register_write",0x11a
                       ,param_4);
          uVar4 = *(undefined4 *)(param_1 + 0x2c);
          uVar3 = 0x1044;
          FUN_c098b68c("Trying to write to illegal register: 0x%04x in core: %s",0x1044,uVar4,
                       param_4);
          FUN_c098b68c("\n",uVar3,uVar4,param_4);
          if (DAT_c0996798 != 0) {
            return;
          }
        }
        else {
          *(undefined4 *)(*(int *)(param_1 + 0x20) + 0x1044) = 0;
        }
        if (*(uint *)(param_1 + 0x28) < 0x1025) {
          FUN_c098b68c("Mali: ERR: %s\n","src/devicedrv/mali/common/mali_rendercore.c",uVar4,param_4
                      );
          FUN_c098b68c("           %s()%4d\n           ","mali_core_renderunit_register_write",0x11a
                       ,param_4);
          uVar3 = *(undefined4 *)(param_1 + 0x2c);
          uVar4 = 0x1024;
          FUN_c098b68c("Trying to write to illegal register: 0x%04x in core: %s",0x1024,uVar3,
                       param_4);
          FUN_c098b68c("\n",uVar4,uVar3,param_4);
        }
        else {
          *(undefined4 *)(*(int *)(param_1 + 0x20) + 0x1024) = 0x1ff;
        }
      }
    }
  }
  return;
}



/* c098a2fc FUN_c098a2fc */

/* Boundary evidence: original MIPS .pdata c098a2fc..c098a33f. Semantic name remains unreviewed. */

void FUN_c098a2fc(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  if (DAT_c0996798 == 0) {
    FUN_c098a050(param_1,param_2,param_3,param_4);
    FUN_c098d4d4(param_1,0x1028,0x11d,param_4);
  }
  return;
}



/* c098a340 FUN_c098a340 */

/* Boundary evidence: original MIPS .pdata c098a340..c098a39b. Semantic name remains unreviewed. */

void FUN_c098a340(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  
  if (param_2 == 0) {
    if (DAT_c0996798 != 0) {
      return;
    }
    FUN_c098a050(param_1,0,param_3,param_4);
    uVar1 = 0x11d;
  }
  else {
    FUN_c098a050(param_1,param_2,param_3,param_4);
    uVar1 = 0;
  }
  FUN_c098d4d4(param_1,0x1028,uVar1,param_4);
  return;
}



/* c098a39c FUN_c098a39c */

/* Boundary evidence: original MIPS .pdata c098a39c..c098a3ef. Semantic name remains unreviewed. */

void FUN_c098a39c(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int *piVar1;
  
  if (((*param_1 != 0) && (DAT_c0996190 < 5)) &&
     (piVar1 = *(int **)(DAT_c0996190 * 4 + *param_1), piVar1 != (int *)0x0)) {
    FUN_c0990b7c(piVar1,(char *)param_1[1],param_3,param_4);
  }
  return;
}



/* c098a3f0 FUN_c098a3f0 */

/* Boundary evidence: original MIPS .pdata c098a3f0..c098a6a7. Semantic name remains unreviewed. */

int FUN_c098a3f0(int *param_1,void *param_2,undefined4 param_3,undefined4 param_4)

{
  char *_Dst;
  void *pvVar1;
  undefined4 *puVar2;
  int iVar3;
  char *pcVar4;
  undefined4 uVar5;
  int *piVar6;
  uint uVar7;
  int iVar8;
  int local_20 [2];
  
  iVar8 = 0;
  _Dst = malloc(0x150);
  if (_Dst == (char *)0x0) {
    iVar8 = -4;
  }
  else {
    memset(_Dst,0,0x150);
    uVar5 = 0x110;
    pvVar1 = memcpy(_Dst + 0x28,param_2,0x110);
    if (pvVar1 == (void *)0x0) {
      FUN_c098b68c("Mali: ERR: %s\n","src/devicedrv/mali/common/mali_kernel_MALI200.c",uVar5,param_4
                  );
      uVar5 = 0x375;
      pcVar4 = "subsystem_mali200_get_new_job_from_user";
      FUN_c098b68c("           %s()%4d\n           ","subsystem_mali200_get_new_job_from_user",0x375
                   ,param_4);
      FUN_c098b68c("Mali PP: Could not copy data from U/K interface.\n",pcVar4,uVar5,param_4);
      FUN_c098b68c("\n",pcVar4,uVar5,param_4);
      iVar8 = -1;
    }
    else {
      *(int **)(_Dst + 8) = param_1;
      if (*(uint *)(_Dst + 0x30) < 3) {
        *(uint *)(_Dst + 0x10) = *(uint *)(_Dst + 0x30);
      }
      else {
        _Dst[0x10] = '\x02';
        _Dst[0x11] = '\0';
        _Dst[0x12] = '\0';
        _Dst[0x13] = '\0';
      }
      uVar7 = *(uint *)(_Dst + 0x34);
      if (uVar7 == 0) {
        _Dst[0x14] = -0x60;
        _Dst[0x15] = -0x45;
        _Dst[0x16] = '\r';
        _Dst[0x17] = '\0';
      }
      else if (uVar7 < 0x36ee81) {
        if (uVar7 < 200) {
          _Dst[0x14] = -0x38;
          _Dst[0x15] = '\0';
          _Dst[0x16] = '\0';
          _Dst[0x17] = '\0';
        }
        else {
          *(uint *)(_Dst + 0x14) = uVar7;
        }
      }
      else {
        _Dst[0x14] = -0x80;
        _Dst[0x15] = -0x12;
        _Dst[0x16] = '6';
        _Dst[0x17] = '\0';
      }
      *(undefined4 *)(_Dst + 0x24) = *(undefined4 *)(_Dst + 300);
      if ((param_1[3] == 0) || (*(uint *)(_Dst + 0x10) < *(uint *)(param_1[3] + 0x10))) {
        _Dst[0x148] = '\x1d';
        _Dst[0x149] = '\x01';
        _Dst[0x14a] = '\0';
        _Dst[0x14b] = '\0';
        puVar2 = FUN_c098ae0c(0x20010,0x3c);
        *(undefined4 **)(_Dst + 0x14c) = puVar2;
        if (puVar2 == (undefined4 *)0x0) {
          FUN_c098b68c("Mali: ERR: %s\n","src/devicedrv/mali/common/mali_kernel_MALI200.c",uVar5,
                       param_4);
          uVar5 = 0x3af;
          pcVar4 = "subsystem_mali200_get_new_job_from_user";
          FUN_c098b68c("           %s()%4d\n           ","subsystem_mali200_get_new_job_from_user",
                       0x3af,param_4);
          FUN_c098b68c("Mali PP: Could not get notification_obj.\n",pcVar4,uVar5,param_4);
          FUN_c098b68c("\n",pcVar4,uVar5,param_4);
          iVar8 = -4;
        }
        else {
          piVar6 = local_20;
          *(char **)_Dst = _Dst;
          *(char **)(_Dst + 4) = _Dst;
          iVar3 = FUN_c0990688(param_1,_Dst,piVar6,param_4);
          if (iVar3 == 0) {
            if (local_20[0] == 0) {
              *(undefined4 *)((int)param_2 + 0x100) = 0;
            }
            else {
              *(undefined4 *)((int)param_2 + 0xfc) = *(undefined4 *)(local_20[0] + 0x2c);
              *(undefined4 *)((int)param_2 + 0x100) = 1;
            }
          }
          else {
            FUN_c098b68c("Mali: ERR: %s\n","src/devicedrv/mali/common/mali_kernel_MALI200.c",piVar6,
                         param_4);
            uVar5 = 0x3bb;
            pcVar4 = "subsystem_mali200_get_new_job_from_user";
            FUN_c098b68c("           %s()%4d\n           ","subsystem_mali200_get_new_job_from_user"
                         ,0x3bb,param_4);
            FUN_c098b68c("Mali PP: Internal error\n",pcVar4,uVar5,param_4);
            FUN_c098b68c("\n",pcVar4,uVar5,param_4);
            *(undefined4 *)((int)param_2 + 0x100) = 2;
            iVar3 = *(int *)(_Dst + 0x14c);
            free(*(void **)(iVar3 + 8));
            free((void *)(iVar3 + -8));
          }
        }
      }
      else {
        *(undefined4 *)((int)param_2 + 0x100) = 2;
      }
    }
    if ((*(int *)((int)param_2 + 0x100) == 2) || (iVar8 != 0)) {
      free(_Dst);
    }
  }
  return iVar8;
}



/* c098a6a8 FUN_c098a6a8 */

/* Boundary evidence: original MIPS .pdata c098a6a8..c098a74f. Semantic name remains unreviewed. */

void FUN_c098a6a8(undefined4 param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4)

{
  char *pcVar1;
  undefined4 uVar2;
  int *_Memory;
  
  if ((param_2 != (undefined4 *)0x0) && (_Memory = (int *)*param_2, _Memory != (int *)0x0)) {
    FUN_c09908f0(_Memory,param_2,param_3,param_4);
    free(_Memory);
    *param_2 = 0;
    return;
  }
  FUN_c098b68c("Mali: ERR: %s\n","src/devicedrv/mali/common/mali_kernel_MALI200.c",param_3,param_4);
  uVar2 = 0x102;
  pcVar1 = "mali200_subsystem_session_end";
  FUN_c098b68c("           %s()%4d\n           ","mali200_subsystem_session_end",0x102,param_4);
  FUN_c098b68c("Input slot==NULL",pcVar1,uVar2,param_4);
  FUN_c098b68c("\n",pcVar1,uVar2,param_4);
  return;
}



/* c098a750 FUN_c098a750 */

/* Boundary evidence: original MIPS .pdata c098a750..c098a9f7. Semantic name remains unreviewed. */

int FUN_c098a750(int *param_1,int *param_2,undefined *param_3,int *param_4)

{
  int iVar1;
  int *_Memory;
  char *pcVar2;
  undefined4 uVar3;
  
  if (*param_1 == 3) {
    if (param_1[4] == 0) {
      if (param_1[1] == 0) {
        FUN_c098b68c("Mali: ERR: %s\n","src/devicedrv/mali/common/mali_kernel_MALI200.c",param_3,
                     param_4);
        uVar3 = 0x135;
        pcVar2 = "mali200_renderunit_create";
        FUN_c098b68c("           %s()%4d\n           ","mali200_renderunit_create",0x135,param_4);
        FUN_c098b68c("A Mali200 core needs a unique description field",pcVar2,uVar3,param_4);
        FUN_c098b68c("\n",pcVar2,uVar3,param_4);
        iVar1 = -1;
      }
      else {
        _Memory = malloc(0x44);
        if (_Memory == (int *)0x0) {
          iVar1 = -4;
        }
        else {
          *_Memory = (int)&DAT_c0996658;
          _Memory[9] = param_1[2];
          _Memory[10] = 0x10f0;
          _Memory[0xc] = param_1[5];
          _Memory[0xb] = param_1[1];
          _Memory[0xe] = param_1[7];
          _Memory[0xf] = 0;
          iVar1 = FUN_c098ee20((int)_Memory,param_2,param_3,param_4);
          if (iVar1 == 0) {
            iVar1 = FUN_c098d270((int)_Memory,param_2,param_3,param_4);
            if (iVar1 == 0) {
              if (DAT_c0996798 == 0) {
                param_2 = (int *)0x1000;
                iVar1 = FUN_c098d590((int)_Memory,0x1000,param_3,param_4);
                _Memory[0xd] = iVar1;
              }
              else {
                _Memory[0xd] = -0x37f8fffb;
              }
              iVar1 = FUN_c0989934((int)_Memory,param_2,param_3,param_4);
              if (iVar1 == 0) {
                if (DAT_c0996798 == 0) {
                  FUN_c098a050((int)_Memory,param_2,param_3,param_4);
                  param_3 = (undefined *)0x11d;
                  FUN_c098d4d4((int)_Memory,0x1028,0x11d,param_4);
                }
                param_2 = _Memory;
                iVar1 = FUN_c0991724((int *)&DAT_c0996658,_Memory,param_3,param_4);
                if (iVar1 == 0) {
                  return 0;
                }
              }
              FUN_c098d1dc((int)_Memory,param_2,param_3,param_4);
            }
            FUN_c098d388((int)_Memory);
          }
          free(_Memory);
          FUN_c098b68c("Mali: ERR: %s\n","src/devicedrv/mali/common/mali_kernel_MALI200.c",param_3,
                       param_4);
          uVar3 = 0x187;
          pcVar2 = "mali200_renderunit_create";
          FUN_c098b68c("           %s()%4d\n           ","mali200_renderunit_create",0x187,param_4);
          FUN_c098b68c("Renderunit NOT created.",pcVar2,uVar3,param_4);
          FUN_c098b68c("\n",pcVar2,uVar3,param_4);
        }
      }
    }
    else {
      FUN_c098b68c("Mali: ERR: %s\n","src/devicedrv/mali/common/mali_kernel_MALI200.c",param_3,
                   param_4);
      uVar3 = 0x12f;
      pcVar2 = "mali200_renderunit_create";
      FUN_c098b68c("           %s()%4d\n           ","mali200_renderunit_create",0x12f,param_4);
      FUN_c098b68c("Memory size set to Mali200 core should be zero.",pcVar2,uVar3,param_4);
      FUN_c098b68c("\n",pcVar2,uVar3,param_4);
      iVar1 = -1;
    }
  }
  else {
    FUN_c098b68c("Mali: ERR: %s\n","src/devicedrv/mali/common/mali_kernel_MALI200.c",param_3,param_4
                );
    uVar3 = 0x123;
    pcVar2 = "mali200_renderunit_create";
    FUN_c098b68c("           %s()%4d\n           ","mali200_renderunit_create",0x123,param_4);
    FUN_c098b68c("Can not register this resource as a Mali200 core.",pcVar2,uVar3,param_4);
    FUN_c098b68c("\n",pcVar2,uVar3,param_4);
    iVar1 = -1;
  }
  return iVar1;
}



/* c098a9f8 FUN_c098a9f8 */

/* Boundary evidence: original MIPS .pdata c098a9f8..c098aaef. Semantic name remains unreviewed. */

int FUN_c098a9f8(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  uVar3 = 0x74;
  uVar2 = 0;
  DAT_c0996190 = param_1;
  memset(&DAT_c0996658,0,0x74);
  DAT_c09966a0 = FUN_c0989db0;
  DAT_c09966a4 = FUN_c098981c;
  DAT_c09966a8 = FUN_c0989aac;
  DAT_c09966ac = FUN_c098a3f0;
  DAT_c09966b4 = FUN_c0989694;
  DAT_c09966b8 = FUN_c0989678;
  DAT_c09966bc = FUN_c098a340;
  DAT_c09966c8 = FUN_c0989914;
  DAT_c09966c0 = FUN_c0989630;
  DAT_c09966c4 = FUN_c09895bc;
  DAT_c0996698 = "Mali200";
  DAT_c0996660 = 5;
  DAT_c099669c = param_1;
  iVar1 = FUN_c098ed0c(-0x3f6699a8,uVar2,uVar3,param_4);
  if (iVar1 == 0) {
    iVar1 = 0;
    DAT_c099676c = FUN_c098a750;
  }
  return iVar1;
}



/* c098aaf0 FUN_c098aaf0 */

/* Boundary evidence: original MIPS .pdata c098aaf0..c098ab17. Semantic name remains unreviewed. */

void FUN_c098aaf0(char *param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  FUN_c0991b2c((int *)&DAT_c0996658,param_1,param_2,param_4);
  return;
}



/* c098ab18 FUN_c098ab18 */

/* Boundary evidence: original MIPS .pdata c098ab18..c098ab33. Semantic name remains unreviewed. */

void FUN_c098ab18(void *param_1)

{
  free(param_1);
  return;
}



/* c098ab40 FUN_c098ab40 */

/* Boundary evidence: original MIPS .pdata c098ab40..c098ab63. Semantic name remains unreviewed. */

void FUN_c098ab40(UINT *param_1)

{
  timeKillEvent(*param_1);
  return;
}



/* c098ab64 FUN_c098ab64 */

/* Boundary evidence: original MIPS .pdata c098ab64..c098ab83. Semantic name remains unreviewed. */

void FUN_c098ab64(void)

{
  calloc(1,0xc);
  return;
}



/* c098ab84 FUN_c098ab84 */

/* Boundary evidence: original MIPS .pdata c098ab84..c098aba3. Semantic name remains unreviewed. */

void FUN_c098ab84(undefined4 param_1,undefined4 param_2,int param_3)

{
  (**(code **)(param_3 + 4))(*(undefined4 *)(param_3 + 8));
  return;
}



/* c098aba4 FUN_c098aba4 */

/* Boundary evidence: original MIPS .pdata c098aba4..c098ac23. Semantic name remains unreviewed. */

void FUN_c098aba4(MMRESULT *param_1,int param_2)

{
  DWORD DVar1;
  MMRESULT MVar2;
  UINT uDelay;
  
  timeKillEvent(*param_1);
  DVar1 = GetTickCount();
  uDelay = param_2 - DVar1;
  if ((int)uDelay < 0) {
    uDelay = 0;
  }
  MVar2 = timeSetEvent(uDelay,0,FUN_c098ab84,(DWORD_PTR)param_1,0);
  *param_1 = MVar2;
  return;
}



/* c098ac24 FUN_c098ac24 */

/* Boundary evidence: original MIPS .pdata c098ac24..c098ac6f. Semantic name remains unreviewed. */

void FUN_c098ac24(MMRESULT *param_1,UINT param_2)

{
  MMRESULT MVar1;
  
  MVar1 = timeSetEvent(param_2,0,FUN_c098ab84,(DWORD_PTR)param_1,0);
  *param_1 = MVar1;
  return;
}



/* c098ac70 FUN_c098ac70 */

/* Boundary evidence: original MIPS .pdata c098ac70..c098ac8b. Semantic name remains unreviewed. */

void FUN_c098ac70(void)

{
  StallExecution();
  return;
}



/* c098ac8c FUN_c098ac8c */

/* Boundary evidence: original MIPS .pdata c098ac8c..c098acaf. Semantic name remains unreviewed. */

void FUN_c098ac8c(void)

{
  GetTickCount();
  return;
}



/* c098acd8 FUN_c098acd8 */

/* Boundary evidence: original MIPS .pdata c098acd8..c098ad5b. Semantic name remains unreviewed. */

undefined4 FUN_c098acd8(undefined4 *param_1,undefined4 param_2,undefined4 *param_3)

{
  int iVar1;
  DWORD DVar2;
  undefined1 auStack_10 [4];
  undefined1 auStack_c [4];
  
  *param_3 = 0;
  iVar1 = ReadMsgQueue(*param_1,param_3,4,auStack_c,param_2,auStack_10);
  if (iVar1 != 0) {
    return 0;
  }
  DVar2 = GetLastError();
  if (DVar2 == 0x5b4) {
    return 0xfffffffb;
  }
  return 0xffffffff;
}



/* c098ad5c FUN_c098ad5c */

/* Boundary evidence: original MIPS .pdata c098ad5c..c098ad8b. Semantic name remains unreviewed. */

void FUN_c098ad5c(int param_1,undefined4 param_2)

{
  undefined4 local_res4 [3];
  
  local_res4[0] = param_2;
  WriteMsgQueue(*(undefined4 *)(param_1 + 4),local_res4,4,0,0);
  return;
}



/* c098ad8c FUN_c098ad8c */

/* Boundary evidence: original MIPS .pdata c098ad8c..c098addb. Semantic name remains unreviewed. */

void FUN_c098ad8c(int *param_1)

{
  if (param_1[1] != 0) {
    CloseMsgQueue();
  }
  if (*param_1 != 0) {
    CloseMsgQueue();
  }
  free(param_1);
  return;
}



/* c098addc FUN_c098addc */

/* Boundary evidence: original MIPS .pdata c098addc..c098ae0b. Semantic name remains unreviewed. */

void FUN_c098addc(int param_1)

{
  free(*(void **)(param_1 + 8));
  free((void *)(param_1 + -8));
  return;
}



/* c098ae0c FUN_c098ae0c */

/* Boundary evidence: original MIPS .pdata c098ae0c..c098ae87. Semantic name remains unreviewed. */

undefined4 * FUN_c098ae0c(undefined4 param_1,size_t param_2)

{
  void *_Memory;
  void *pvVar1;
  
  _Memory = malloc(0x14);
  if (_Memory != (void *)0x0) {
    pvVar1 = malloc(param_2);
    *(void **)((int)_Memory + 0x10) = pvVar1;
    if (pvVar1 != (void *)0x0) {
      *(void **)((int)_Memory + 4) = _Memory;
      *(void **)_Memory = _Memory;
      *(undefined4 *)((int)_Memory + 8) = param_1;
      *(size_t *)((int)_Memory + 0xc) = param_2;
      return (undefined4 *)((int)_Memory + 8);
    }
    free(_Memory);
  }
  return (undefined4 *)0x0;
}



/* c098ae88 FUN_c098ae88 */

/* Boundary evidence: original MIPS .pdata c098ae88..c098af5f. Semantic name remains unreviewed. */

int * FUN_c098ae88(void)

{
  int *_Memory;
  int iVar1;
  int iVar2;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  
  _Memory = calloc(1,8);
  if (_Memory != (int *)0x0) {
    local_28 = 0x14;
    local_24 = 1;
    local_20 = 0;
    local_1c = 4;
    local_18 = 1;
    iVar1 = CreateMsgQueue(0,&local_28);
    *_Memory = iVar1;
    if (iVar1 != 0) {
      local_18 = 0;
      iVar2 = OpenMsgQueue(0x42,iVar1,&local_28);
      _Memory[1] = iVar2;
      if (iVar2 != 0) {
        return _Memory;
      }
    }
    if (_Memory[1] != 0) {
      CloseMsgQueue();
    }
    if (iVar1 != 0) {
      CloseMsgQueue(iVar1);
    }
    free(_Memory);
  }
  return (int *)0x0;
}



/* c098af60 FUN_c098af60 */

/* Boundary evidence: original MIPS .pdata c098af60..c098af9b. Semantic name remains unreviewed. */

void FUN_c098af60(void)

{
  if (DAT_c099675c != (void *)0x0) {
    free(DAT_c099675c);
    DAT_c099675c = (void *)0x0;
  }
  return;
}



/* c098af9c FUN_c098af9c */

/* Boundary evidence: original MIPS .pdata c098af9c..c098b5df. Semantic name remains unreviewed. */

int FUN_c098af9c(void)

{
  HKEY hKey;
  LSTATUS LVar1;
  int *lpData;
  int *piVar2;
  LPCWSTR lpName;
  DWORD dwIndex;
  int iVar3;
  DWORD local_40;
  HKEY local_3c;
  HKEY local_38;
  DWORD local_34;
  uint local_30;
  int *local_2c;
  
  lpName = (LPCWSTR)0x0;
  iVar3 = -1;
  local_38 = (HKEY)0x0;
  local_3c = (HKEY)0x0;
  hKey = (HKEY)OpenDeviceKey(DAT_c0996854);
  if (((hKey != (HKEY)0x0) && (LVar1 = RegOpenKeyExW(hKey,L"Resources",0,0,&local_38), LVar1 == 0))
     && (LVar1 = RegQueryInfoKeyW(local_38,(LPWSTR)0x0,(LPDWORD)0x0,(LPDWORD)0x0,&local_30,&local_34
                                  ,(LPDWORD)0x0,(LPDWORD)0x0,(LPDWORD)0x0,(LPDWORD)0x0,(LPDWORD)0x0,
                                  (PFILETIME)0x0), LVar1 == 0)) {
    lpData = malloc((local_34 + 0x25) * local_30);
    DAT_c099675c = lpData;
    if (lpData == (int *)0x0) {
      iVar3 = -4;
    }
    else {
      piVar2 = lpData + local_30 * 9;
      local_2c = piVar2;
      lpName = malloc((local_34 + 1) * 2);
      if (lpName == (LPCWSTR)0x0) {
        iVar3 = -4;
      }
      else {
        dwIndex = 0;
        if (local_30 != 0) {
          do {
            local_40 = local_34 + 1;
            LVar1 = RegEnumKeyExW(local_38,dwIndex,lpName,&local_40,(LPDWORD)0x0,(LPWSTR)0x0,
                                  (LPDWORD)0x0,(PFILETIME)0x0);
            if ((LVar1 != 0) || (LVar1 = RegOpenKeyExW(local_38,lpName,0,0,&local_3c), LVar1 != 0))
            {
switchD_c098b548_caseD_3:
              goto LAB_c098b2d4;
            }
            *lpData = 0;
            lpData[1] = 0;
            lpData[2] = 0;
            lpData[3] = 0;
            lpData[4] = 0;
            lpData[5] = 0;
            lpData[6] = 0;
            lpData[7] = 0;
            lpData[8] = 0;
            piVar2 = (int *)((local_34 + 1) * dwIndex + (int)piVar2);
            lpData[1] = (int)piVar2;
            WideCharToMultiByte(0,0,lpName,local_40 + 1,(LPSTR)piVar2,local_40 + 1,(LPCSTR)0x0,
                                (LPBOOL)0x0);
            local_40 = 4;
            LVar1 = RegQueryValueExW(local_3c,L"Type",(LPDWORD)0x0,(LPDWORD)0x0,(LPBYTE)lpData,
                                     &local_40);
            if (LVar1 == 2) goto switchD_c098b548_caseD_3;
            local_40 = 4;
            LVar1 = RegQueryValueExW(local_3c,L"Base",(LPDWORD)0x0,(LPDWORD)0x0,(LPBYTE)(lpData + 2)
                                     ,&local_40);
            if ((LVar1 == 2) && (*lpData != 1)) goto switchD_c098b548_caseD_3;
            local_40 = 4;
            LVar1 = RegQueryValueExW(local_3c,L"Size",(LPDWORD)0x0,(LPDWORD)0x0,(LPBYTE)(lpData + 4)
                                     ,&local_40);
            if (*lpData == 0) {
              if (LVar1 == 2) goto switchD_c098b548_caseD_3;
            }
            else if (LVar1 == 2) {
              lpData[4] = 0;
            }
            local_40 = 4;
            LVar1 = RegQueryValueExW(local_3c,L"Irq",(LPDWORD)0x0,(LPDWORD)0x0,(LPBYTE)(lpData + 5),
                                     &local_40);
            if (LVar1 == 2) {
              lpData[5] = 0;
            }
            local_40 = 4;
            LVar1 = RegQueryValueExW(local_3c,L"Flags",(LPDWORD)0x0,(LPDWORD)0x0,
                                     (LPBYTE)(lpData + 6),&local_40);
            if (*lpData == 0) {
              if (LVar1 == 2) goto switchD_c098b548_caseD_3;
            }
            else if (LVar1 == 2) {
              lpData[6] = 0;
            }
            local_40 = 4;
            LVar1 = RegQueryValueExW(local_3c,L"CPU_Usage_Adjust",(LPDWORD)0x0,(LPDWORD)0x0,
                                     (LPBYTE)(lpData + 3),&local_40);
            if (LVar1 == 2) {
              lpData[3] = 0;
            }
            local_40 = 4;
            LVar1 = RegQueryValueExW(local_3c,L"Allocation_Order",(LPDWORD)0x0,(LPDWORD)0x0,
                                     (LPBYTE)(lpData + 8),&local_40);
            if (LVar1 == 2) {
              lpData[8] = 0;
            }
            local_40 = 4;
            LVar1 = RegQueryValueExW(local_3c,L"MMU_ID",(LPDWORD)0x0,(LPDWORD)0x0,
                                     (LPBYTE)(lpData + 7),&local_40);
            if (LVar1 != 2) {
              switch(*lpData) {
              case 3:
              case 4:
              case 5:
              case 8:
              case 9:
                goto switchD_c098b588_caseD_3;
              default:
                goto switchD_c098b548_caseD_6;
              }
            }
            switch(*lpData) {
            case 3:
            case 4:
            case 5:
            case 8:
            case 9:
              goto switchD_c098b548_caseD_3;
            }
switchD_c098b548_caseD_6:
            lpData[7] = 0;
switchD_c098b588_caseD_3:
            RegCloseKey(local_3c);
            dwIndex = dwIndex + 1;
            lpData = lpData + 9;
            local_3c = (HKEY)0x0;
            piVar2 = local_2c;
          } while (dwIndex < local_30);
        }
        iVar3 = 0;
        DAT_c0996640 = local_30;
      }
    }
  }
LAB_c098b2d4:
  if (local_3c != (HKEY)0x0) {
    RegCloseKey(local_3c);
  }
  if (local_38 != (HKEY)0x0) {
    RegCloseKey(local_38);
  }
  if (hKey != (HKEY)0x0) {
    RegCloseKey(hKey);
  }
  if (lpName != (LPCWSTR)0x0) {
    free(lpName);
  }
  if ((iVar3 != 0) && (DAT_c099675c != (int *)0x0)) {
    free(DAT_c099675c);
    DAT_c099675c = (int *)0x0;
  }
  return iVar3;
}



/* c098b5e0 FUN_c098b5e0 */

/* Boundary evidence: original MIPS .pdata c098b5e0..c098b64b. Semantic name remains unreviewed. */

void FUN_c098b5e0(void)

{
  DWORD DVar1;
  
  CloseMsgQueue(DAT_c0996824);
  DVar1 = WaitForSingleObject(DAT_c0996828,5000);
  if (DVar1 != 0) {
    TerminateThread(DAT_c0996828,0xffffffff);
  }
  CloseHandle(DAT_c099681c);
  CloseMsgQueue(DAT_c0996820);
  return;
}



/* c098b64c FUN_c098b64c */

/* Boundary evidence: original MIPS .pdata c098b64c..c098b68b. Semantic name remains unreviewed. */

undefined4 FUN_c098b64c(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  
  iVar1 = FUN_c09920e8(param_1,param_2,param_3,param_4);
  if (iVar1 != 0) {
    return 0xffffffff;
  }
  CalibrateStallCounter();
  return 0;
}



/* c098b68c FUN_c098b68c */

/* Boundary evidence: original MIPS .pdata c098b68c..c098b727. Semantic name remains unreviewed. */

void FUN_c098b68c(char *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  size_t sVar1;
  char *_Dest;
  size_t _Size;
  undefined4 local_res4;
  undefined4 local_res8;
  undefined4 local_resc;
  
  _Dest = (char *)0x0;
  _Size = 0x80;
  local_res4 = param_2;
  local_res8 = param_3;
  local_resc = param_4;
  while( true ) {
    if (_Dest != (char *)0x0) {
      free(_Dest);
    }
    _Size = _Size << 1;
    _Dest = malloc(_Size);
    if (_Dest == (char *)0x0) break;
    sVar1 = _vsnprintf(_Dest,_Size,param_1,(va_list)&local_res4);
    if ((sVar1 != 0xffffffff) && (sVar1 != _Size)) {
      free(_Dest);
      return;
    }
  }
  return;
}



/* c098b728 FUN_c098b728 */

/* Boundary evidence: original MIPS .pdata c098b728..c098b743. Semantic name remains unreviewed. */

void FUN_c098b728(void *param_1,undefined4 param_2,size_t param_3)

{
  memset(param_1,0,param_3);
  return;
}



/* c098b744 FUN_c098b744 */

/* Boundary evidence: original MIPS .pdata c098b744..c098b75f. Semantic name remains unreviewed. */

void FUN_c098b744(void *param_1,void *param_2,size_t param_3)

{
  memcpy(param_1,param_2,param_3);
  return;
}



/* c098b760 FUN_c098b760 */

/* Boundary evidence: original MIPS .pdata c098b760..c098b77b. Semantic name remains unreviewed. */

void FUN_c098b760(void *param_1)

{
  free(param_1);
  return;
}



/* c098b77c FUN_c098b77c */

/* Boundary evidence: original MIPS .pdata c098b77c..c098b797. Semantic name remains unreviewed. */

void FUN_c098b77c(size_t param_1)

{
  malloc(param_1);
  return;
}



/* c098b798 FUN_c098b798 */

/* Boundary evidence: original MIPS .pdata c098b798..c098b7b3. Semantic name remains unreviewed. */

void FUN_c098b798(undefined4 param_1,size_t param_2)

{
  calloc(1,param_2);
  return;
}



/* c098b7bc FUN_c098b7bc */

/* Boundary evidence: original MIPS .pdata c098b7bc..c098b827. Semantic name remains unreviewed. */

void FUN_c098b7bc(int *param_1,int param_2,uint param_3)

{
  undefined4 uVar1;
  int iVar2;
  
  if (((param_1 != (int *)0x0) && (iVar2 = *param_1, iVar2 != 0)) &&
     (param_3 <= (uint)(param_1[2] - param_2))) {
    uVar1 = GetDirectCallerProcessId();
    (*(code *)&SUB_ffffb3d6)(uVar1,iVar2 + param_2,param_3,0x4000);
  }
  return;
}



/* c098b828 FUN_c098b828 */

/* Boundary evidence: original MIPS .pdata c098b828..c098b877. Semantic name remains unreviewed. */

void FUN_c098b828(int *param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  if ((param_1 != (int *)0x0) && (iVar2 = *param_1, iVar2 != 0)) {
    uVar1 = GetDirectCallerProcessId();
    (*(code *)&SUB_ffffb3d6)(uVar1,iVar2,0,0x8000);
  }
  return;
}



/* c098b878 FUN_c098b878 */

/* Boundary evidence: original MIPS .pdata c098b878..c098b90b. Semantic name remains unreviewed. */

undefined4 FUN_c098b878(int *param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  if (param_1 == (int *)0x0) {
    return 0xfffffffd;
  }
  uVar1 = GetDirectCallerProcessId();
  iVar2 = (*(code *)&SUB_ffffb3da)(uVar1,0,param_1[2],0x2000,4);
  *param_1 = iVar2;
  if (iVar2 == 0) {
    GetLastError();
    return 0xfffffffc;
  }
  return 0;
}



/* c098b950 FUN_c098b950 */

/* Boundary evidence: original MIPS .pdata c098b950..c098b96b. Semantic name remains unreviewed. */

void FUN_c098b950(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  FreePhysMem(param_3);
  return;
}



/* c098b96c FUN_c098b96c */

/* Boundary evidence: original MIPS .pdata c098b96c..c098b9b7. Semantic name remains unreviewed. */

void FUN_c098b96c(undefined4 *param_1)

{
  int iVar1;
  undefined4 local_10 [2];
  
  iVar1 = AllocPhysMem(0x40000,4,0xfff,0,local_10);
  if (iVar1 != 0) {
    *param_1 = local_10[0];
  }
  return;
}



/* c098b9c0 FUN_c098b9c0 */

/* Boundary evidence: original MIPS .pdata c098b9c0..c098baff. Semantic name remains unreviewed. */

LPVOID FUN_c098b9c0(uint param_1,SIZE_T param_2,undefined4 param_3)

{
  LPVOID lpAddress;
  int iVar1;
  undefined4 uVar2;
  SIZE_T SVar3;
  undefined4 uVar4;
  
  uVar4 = 0x204;
  uVar2 = 0x2000;
  lpAddress = VirtualAlloc((LPVOID)0x0,param_2,0x2000,0x204);
  if (lpAddress == (LPVOID)0x0) {
    FUN_c098b68c("Mali: ERR: %s\n","src/devicedrv/mali/windowsce/mali_osk_low_level_mem.c",uVar2,
                 uVar4);
    FUN_c098b68c("           %s()%4d\n           ","_mali_osk_mem_mapioregion",0x2a,uVar4);
    FUN_c098b68c("Could not allocate registers for %S @0x%x(phys), size 0x%x\n",param_3,param_1,
                 param_2);
    FUN_c098b68c("\n",param_3,param_1,param_2);
    lpAddress = (LPVOID)0x0;
  }
  else {
    uVar2 = 0x604;
    SVar3 = param_2;
    iVar1 = VirtualCopy(lpAddress,param_1 >> 8);
    if (iVar1 == 0) {
      FUN_c098b68c("Mali: ERR: %s\n","src/devicedrv/mali/windowsce/mali_osk_low_level_mem.c",SVar3,
                   uVar2);
      FUN_c098b68c("           %s()%4d\n           ","_mali_osk_mem_mapioregion",0x31,uVar2);
      FUN_c098b68c("Could not map registers for %S @0x%x(phys), size 0x%x\n",param_3,param_1,param_2
                  );
      FUN_c098b68c("\n",param_3,param_1,param_2);
      VirtualFree(lpAddress,0,0x8000);
      lpAddress = (LPVOID)0x0;
    }
  }
  return lpAddress;
}



/* c098bb00 FUN_c098bb00 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Boundary evidence: original MIPS .pdata c098bb00..c098bc8b. Semantic name remains unreviewed. */

undefined4 FUN_c098bb00(int *param_1,int param_2,uint *param_3,uint param_4)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  int iVar5;
  int local_28 [2];
  
  if ((param_1 == (int *)0x0) || (*param_1 == 0)) {
    uVar1 = 0xfffffffd;
  }
  else if ((uint)(param_1[2] - param_2) < param_4) {
    uVar1 = 0xffffffff;
  }
  else {
    if (*param_3 == 0xffffffff) {
      iVar5 = *param_1 + param_2;
      uVar1 = GetDirectCallerProcessId();
      iVar2 = (*(code *)&SUB_ffffb3da)(uVar1,iVar5,param_4,0x1000,4);
      if (iVar2 == 0) {
        return 0xfffffffc;
      }
      iVar2 = LockPages(iVar5,param_4,local_28,2);
      if (iVar2 != 0) {
        *param_3 = local_28[0] << (_DAT_00005b08 & 0x1f);
        return 0;
      }
      uVar1 = GetDirectCallerProcessId();
      (*(code *)&SUB_ffffb3d6)(uVar1,iVar5,param_4,0x4000);
    }
    else {
      uVar1 = __GetUserKData(0xc);
      uVar4 = *param_3;
      iVar2 = *param_1;
      uVar3 = GetDirectCallerProcessId();
      iVar2 = (*(code *)&SUB_ffffb3ca)(uVar3,iVar2 + param_2,uVar1,uVar4 >> 8,param_4,0x404);
      if (iVar2 != 0) {
        return 0;
      }
    }
    uVar1 = 0xffffffff;
  }
  return uVar1;
}



/* c098bc8c FUN_c098bc8c */

/* Boundary evidence: original MIPS .pdata c098bc8c..c098bcbb. Semantic name remains unreviewed. */

void FUN_c098bc8c(void)

{
  CacheRangeFlush(0,0,0x24);
  SYNC(0);
  return;
}



/* c098bcbc FUN_c098bcbc */

/* Boundary evidence: original MIPS .pdata c098bcbc..c098bcf3. Semantic name remains unreviewed. */

void FUN_c098bcbc(void *param_1)

{
  CloseHandle(*(HANDLE *)((int)param_1 + 4));
  free(param_1);
  return;
}



/* c098bcf4 FUN_c098bcf4 */

/* Boundary evidence: original MIPS .pdata c098bcf4..c098bdc7. Semantic name remains unreviewed. */

undefined4 * FUN_c098bcf4(uint param_1)

{
  undefined4 *_Memory;
  HANDLE pvVar1;
  undefined4 uVar2;
  
  _Memory = malloc(0x10);
  if (_Memory == (undefined4 *)0x0) {
    return (undefined4 *)0x0;
  }
  pvVar1 = CreateMutexW((LPSECURITY_ATTRIBUTES)0x0,0,(LPCWSTR)0x0);
  _Memory[1] = pvVar1;
  if (pvVar1 == (HANDLE)0x0) {
    free(_Memory);
    return (undefined4 *)0x0;
  }
  _Memory[2] = 0;
  _Memory[3] = 0;
  if ((param_1 & 1) != 0) {
    *_Memory = 0;
    return _Memory;
  }
  if ((param_1 & 2) != 0) {
    if ((param_1 & 4) != 0) {
      uVar2 = 3;
      goto LAB_c098bdac;
    }
    if ((param_1 & 2) != 0) {
      *_Memory = 2;
      return _Memory;
    }
  }
  uVar2 = 1;
LAB_c098bdac:
  *_Memory = uVar2;
  return _Memory;
}



/* c098bdc8 FUN_c098bdc8 */

/* Boundary evidence: original MIPS .pdata c098bdc8..c098be3b. Semantic name remains unreviewed. */

void FUN_c098bdc8(int *param_1)

{
  int iVar1;
  
  if ((((-1 < *param_1) && (*param_1 < 4)) && (param_1[2] == 1)) &&
     (iVar1 = __GetUserKData(8), param_1[3] == iVar1)) {
    param_1[2] = 0;
    param_1[3] = 0;
    ReleaseMutex((HANDLE)param_1[1]);
  }
  return;
}



/* c098be3c FUN_c098be3c */

/* Boundary evidence: original MIPS .pdata c098be3c..c098beeb. Semantic name remains unreviewed. */

undefined4 FUN_c098be3c(int *param_1)

{
  DWORD DVar1;
  BOOL BVar2;
  int iVar3;
  
  if (*param_1 < 0) {
    return 0;
  }
  if (3 < *param_1) {
    return 0;
  }
  DVar1 = WaitForSingleObject((HANDLE)param_1[1],0xffffffff);
  if (DVar1 == 0) {
    if (param_1[2] != 1) {
      param_1[2] = 1;
      iVar3 = __GetUserKData(8);
      param_1[3] = iVar3;
      return 0;
    }
    BVar2 = ReleaseMutex((HANDLE)param_1[1]);
    if (BVar2 != 0) {
      return 0;
    }
  }
  return 0xffffffff;
}



/* c098beec FUN_c098beec */

/* Boundary evidence: original MIPS .pdata c098beec..c098bf1b. Semantic name remains unreviewed. */

void FUN_c098beec(int param_1)

{
  undefined4 local_res0 [4];
  
  local_res0[0] = param_1;
  WriteMsgQueue(*(undefined4 *)(param_1 + 4),local_res0,4,0,0);
  return;
}



/* c098bf1c FUN_c098bf1c */

/* Boundary evidence: original MIPS .pdata c098bf1c..c098bf87. Semantic name remains unreviewed. */

void FUN_c098bf1c(void)

{
  DWORD DVar1;
  
  CloseMsgQueue(DAT_c0996824);
  DVar1 = WaitForSingleObject(DAT_c0996828,5000);
  if (DVar1 != 0) {
    TerminateThread(DAT_c0996828,0xffffffff);
  }
  CloseHandle(DAT_c099681c);
  CloseMsgQueue(DAT_c0996820);
  return;
}



/* c098bf88 FUN_c098bf88 */

/* Boundary evidence: original MIPS .pdata c098bf88..c098bfdf. Semantic name remains unreviewed. */

void FUN_c098bf88(int param_1)

{
  int iVar1;
  
  iVar1 = WriteMsgQueue(*(undefined4 *)(param_1 + 4),&DAT_c0996818,4,0xffffffff,0);
  if (iVar1 != 0) {
    WaitForSingleObject(DAT_c099681c,5000);
  }
  return;
}



/* c098bfe0 FUN_c098bfe0 */

/* Boundary evidence: original MIPS .pdata c098bfe0..c098c057. Semantic name remains unreviewed. */

undefined4 FUN_c098bfe0(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x1c);
  while ((iVar1 == 0 &&
         (WaitForSingleObject(*(HANDLE *)(param_1 + 0x18),0xffffffff), *(int *)(param_1 + 0x1c) == 0
         ))) {
    (**(code **)(param_1 + 0xc))(*(undefined4 *)(param_1 + 8));
    InterruptDone(*(undefined4 *)(param_1 + 0x14));
    iVar1 = *(int *)(param_1 + 0x1c);
  }
  return 1;
}



/* c098c058 FUN_c098c058 */

/* Boundary evidence: original MIPS .pdata c098c058..c098c183. Semantic name remains unreviewed. */

void FUN_c098c058(void *param_1)

{
  DWORD DVar1;
  int iVar2;
  undefined4 *puVar3;
  
  if (DAT_c0996798 == 0) {
    puVar3 = (undefined4 *)((int)param_1 + 0x14);
    *(undefined4 *)((int)param_1 + 0x1c) = 1;
    InterruptDisable(*puVar3);
    EventModify(*(undefined4 *)((int)param_1 + 0x18),3);
    DVar1 = WaitForSingleObject(*(HANDLE *)((int)param_1 + 0x20),5000);
    if (DVar1 != 0) {
      TerminateThread(*(HANDLE *)((int)param_1 + 0x20),0xffffffff);
    }
    CloseHandle(*(HANDLE *)((int)param_1 + 0x20));
    *(undefined4 *)((int)param_1 + 0x20) = 0;
    CloseHandle(*(HANDLE *)((int)param_1 + 0x18));
    *(undefined4 *)((int)param_1 + 0x18) = 0;
    KernelIoControl(0x10100d8,puVar3,4,0,0,0);
    *puVar3 = 0xffffffff;
  }
  iVar2 = WriteMsgQueue(*(undefined4 *)((int)param_1 + 4),&DAT_c0996818,4,0xffffffff,0);
  if (iVar2 != 0) {
    WaitForSingleObject(DAT_c099681c,5000);
  }
  CloseMsgQueue(*(undefined4 *)((int)param_1 + 4));
  free(param_1);
  return;
}



/* c098c184 FUN_c098c184 */

/* Boundary evidence: original MIPS .pdata c098c184..c098c21b. Semantic name remains unreviewed. */

undefined4 FUN_c098c184(void)

{
  int iVar1;
  int local_20;
  undefined1 auStack_1c [4];
  undefined1 auStack_18 [8];
  
  while( true ) {
    iVar1 = ReadMsgQueue(DAT_c0996820,&local_20,4,auStack_18,0xffffffff,auStack_1c);
    if (iVar1 == 0) break;
    if (DAT_c0996818 == local_20) {
      EventModify(DAT_c099681c,3);
    }
    else {
      (**(code **)(local_20 + 0x10))(*(undefined4 *)(local_20 + 8));
    }
  }
  return 1;
}



/* c098c21c FUN_c098c21c */

/* Boundary evidence: original MIPS .pdata c098c21c..c098c40b. Semantic name remains unreviewed. */

undefined4 *
FUN_c098c21c(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 *lpParameter;
  int iVar1;
  HANDLE pvVar2;
  undefined4 uVar3;
  int *piVar4;
  undefined4 local_res0 [4];
  undefined4 local_20 [2];
  
  local_res0[0] = param_1;
  lpParameter = calloc(1,0x24);
  if (lpParameter != (undefined4 *)0x0) {
    lpParameter[4] = param_3;
    lpParameter[2] = param_4;
    piVar4 = lpParameter + 5;
    lpParameter[3] = param_2;
    uVar3 = DAT_c0996820;
    *lpParameter = local_res0[0];
    *piVar4 = -1;
    iVar1 = OpenMsgQueue(0x42,uVar3,&DAT_c0996644);
    lpParameter[1] = iVar1;
    if (iVar1 != 0) {
      if (DAT_c0996798 != 0) {
        return lpParameter;
      }
      iVar1 = KernelIoControl(0x1010098,local_res0,4,piVar4,4,0);
      if (iVar1 != 0) {
        pvVar2 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
        lpParameter[6] = pvVar2;
        if ((pvVar2 != (HANDLE)0x0) && (iVar1 = InterruptInitialize(*piVar4,pvVar2,0,0), iVar1 != 0)
           ) {
          pvVar2 = CreateThread((LPSECURITY_ATTRIBUTES)0x0,0,FUN_c098bfe0,lpParameter,0,(LPDWORD)0x0
                               );
          lpParameter[8] = pvVar2;
          if (pvVar2 != (HANDLE)0x0) {
            iVar1 = FUN_c0991dc8(L"Priority256",(LPBYTE)local_20);
            uVar3 = 0xfb;
            if (iVar1 != 0) {
              uVar3 = local_20[0];
            }
            CeSetThreadPriority(lpParameter[8],uVar3);
            return lpParameter;
          }
          InterruptDisable(*piVar4);
        }
      }
    }
    if ((HANDLE)lpParameter[6] != (HANDLE)0x0) {
      CloseHandle((HANDLE)lpParameter[6]);
      lpParameter[6] = 0;
    }
    if (*piVar4 != -1) {
      KernelIoControl(0x10100d8,piVar4,4,0,0,0);
      *piVar4 = -1;
    }
    if (lpParameter[1] != 0) {
      CloseMsgQueue();
    }
    free(lpParameter);
  }
  return (undefined4 *)0x0;
}



/* c098c40c FUN_c098c40c */

/* Boundary evidence: original MIPS .pdata c098c40c..c098c5c3. Semantic name remains unreviewed. */

undefined4 FUN_c098c40c(void)

{
  int iVar1;
  DWORD DVar2;
  undefined4 local_10 [2];
  
  DAT_c0996644 = 0x14;
  DAT_c0996648 = 1;
  DAT_c099664c = 0;
  DAT_c0996650 = 4;
  DAT_c0996654 = 1;
  DAT_c0996820 = CreateMsgQueue(0,&DAT_c0996644);
  if (DAT_c0996820 != 0) {
    DAT_c0996654 = 0;
    DAT_c0996824 = OpenMsgQueue(0x42,DAT_c0996820,&DAT_c0996644);
    if (DAT_c0996824 == 0) goto LAB_c098c54c;
    DAT_c099681c = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
    if (DAT_c099681c != (HANDLE)0x0) {
      DAT_c0996828 = CreateThread((LPSECURITY_ATTRIBUTES)0x0,0,FUN_c098c184,(LPVOID)0x0,0,
                                  (LPDWORD)0x0);
      if (DAT_c0996828 != (HANDLE)0x0) {
        iVar1 = FUN_c0991dc8(L"Priority256",(LPBYTE)local_10);
        if (iVar1 == 0) {
          local_10[0] = 0xfb;
        }
        CeSetThreadPriority(DAT_c0996828,local_10[0]);
        return 0;
      }
      DAT_c0996828 = (HANDLE)0x0;
    }
  }
  if (DAT_c0996824 != 0) {
    CloseMsgQueue(DAT_c0996824);
  }
LAB_c098c54c:
  if ((DAT_c0996828 != (HANDLE)0x0) && (DVar2 = WaitForSingleObject(DAT_c0996828,5000), DVar2 != 0))
  {
    TerminateThread(DAT_c0996828,0xffffffff);
  }
  if (DAT_c099681c != (HANDLE)0x0) {
    CloseHandle(DAT_c099681c);
  }
  if (DAT_c0996820 != 0) {
    CloseMsgQueue(DAT_c0996820);
  }
  return 0xffffffff;
}



/* c098c5c4 FUN_c098c5c4 */

/* Boundary evidence: original MIPS .pdata c098c5c4..c098c5df. Semantic name remains unreviewed. */

void FUN_c098c5c4(void *param_1)

{
  free(param_1);
  return;
}



/* c098c5e0 FUN_c098c5e0 */

/* Boundary evidence: original MIPS .pdata c098c5e0..c098c633. Semantic name remains unreviewed. */

void FUN_c098c5e0(uint param_1)

{
  int *piVar1;
  uint uVar2;
  
  uVar2 = (param_1 & 0x3fffffff) >> 3;
  piVar1 = calloc(1,(param_1 + 2) * 4 + uVar2);
  if (piVar1 != (int *)0x0) {
    *piVar1 = (int)(piVar1 + 2);
    piVar1[1] = (int)piVar1 + uVar2 + 8;
  }
  return;
}



/* c098c634 FUN_c098c634 */

/* Boundary evidence: original MIPS .pdata c098c634..c098c687. Semantic name remains unreviewed. */

void FUN_c098c634(undefined4 *param_1)

{
  void *_Memory;
  
  free((void *)param_1[3]);
  _Memory = (void *)*param_1;
  CloseHandle(*(HANDLE *)((int)_Memory + 4));
  free(_Memory);
  free(param_1);
  return;
}



/* c098c6e8 FUN_c098c6e8 */

uint FUN_c098c6e8(uint *param_1,uint param_2)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = 0;
  if (param_2 != 0) {
    while (iVar2 = 0x1f - LZCOUNT(-~*param_1 & ~*param_1), iVar2 < 0) {
      uVar1 = uVar1 + 0x20;
      prefetch(param_1 + 2,0);
      param_1 = param_1 + 1;
      if (param_2 <= uVar1) {
        return param_2;
      }
    }
    uVar1 = iVar2 + uVar1;
    if (uVar1 < param_2) {
      return uVar1;
    }
  }
  return param_2;
}



/* c098c7c8 FUN_c098c7c8 */

/* Boundary evidence: original MIPS .pdata c098c7c8..c098c8c7. Semantic name remains unreviewed. */

void FUN_c098c7c8(undefined4 *param_1,uint param_2)

{
  int iVar1;
  uint *puVar2;
  uint uVar3;
  int *piVar4;
  
  FUN_c098be3c((int *)*param_1);
  if ((-1 < (int)param_2) && ((int)param_2 < (int)param_1[2])) {
    iVar1 = (param_2 >> 5) * 4;
    uVar3 = 1 << (param_2 & 0x1f);
    if ((*(uint *)(*(int *)param_1[3] + iVar1) & uVar3) != 0) {
      *(undefined4 *)(((int *)param_1[3])[1] + param_2 * 4) = 0;
      puVar2 = (uint *)(*(int *)param_1[3] + iVar1);
      *puVar2 = ~uVar3 & *puVar2;
    }
  }
  piVar4 = (int *)*param_1;
  if ((((-1 < *piVar4) && (*piVar4 < 4)) && (piVar4[2] == 1)) &&
     (iVar1 = __GetUserKData(8), piVar4[3] == iVar1)) {
    piVar4[2] = 0;
    piVar4[3] = 0;
    ReleaseMutex((HANDLE)piVar4[1]);
  }
  return;
}



/* c098c8c8 FUN_c098c8c8 */

/* Boundary evidence: original MIPS .pdata c098c8c8..c098c9df. Semantic name remains unreviewed. */

undefined4 FUN_c098c8c8(undefined4 *param_1,uint param_2,undefined4 *param_3)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  
  uVar3 = 0xffffffff;
  FUN_c098be3c((int *)*param_1);
  if ((((int)param_2 < 0) || ((int)param_1[2] <= (int)param_2)) ||
     ((1 << (param_2 & 0x1f) & *(uint *)((param_2 >> 5) * 4 + *(int *)param_1[3])) == 0)) {
    *param_3 = 0;
  }
  else {
    uVar3 = 0;
    *param_3 = *(undefined4 *)(((int *)param_1[3])[1] + param_2 * 4);
  }
  piVar2 = (int *)*param_1;
  if (((-1 < *piVar2) && (*piVar2 < 4)) &&
     ((piVar2[2] == 1 && (iVar1 = __GetUserKData(8), piVar2[3] == iVar1)))) {
    piVar2[2] = 0;
    piVar2[3] = 0;
    ReleaseMutex((HANDLE)piVar2[1]);
  }
  return uVar3;
}



/* c098c9e0 FUN_c098c9e0 */

/* Boundary evidence: original MIPS .pdata c098c9e0..c098cb13. Semantic name remains unreviewed. */

void FUN_c098c9e0(undefined4 *param_1)

{
  void *_Memory;
  int *piVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  
  FUN_c098be3c((int *)*param_1);
  uVar2 = 1;
  uVar3 = 2;
  if (1 < (int)param_1[2]) {
    iVar4 = 4;
    do {
      if ((*(uint *)((uVar2 >> 5) * 4 + *(int *)param_1[3]) & uVar3) != 0) {
        _Memory = *(void **)(((int *)param_1[3])[1] + iVar4);
        FUN_c0983d8c(DAT_c099683c,(int)_Memory);
        free(_Memory);
      }
      uVar3 = uVar3 >> 0x1f | uVar3 << 1;
      uVar2 = uVar2 + 1;
      iVar4 = iVar4 + 4;
    } while ((int)uVar2 < (int)param_1[2]);
  }
  piVar1 = (int *)*param_1;
  if ((((-1 < *piVar1) && (*piVar1 < 4)) && (piVar1[2] == 1)) &&
     (iVar4 = __GetUserKData(8), piVar1[3] == iVar4)) {
    piVar1[2] = 0;
    piVar1[3] = 0;
    ReleaseMutex((HANDLE)piVar1[1]);
  }
  return;
}



/* c098cb14 FUN_c098cb14 */

/* Boundary evidence: original MIPS .pdata c098cb14..c098cccb. Semantic name remains unreviewed. */

undefined4 FUN_c098cb14(undefined4 *param_1,undefined4 param_2,uint *param_3)

{
  uint uVar1;
  undefined4 *puVar2;
  int iVar3;
  uint *puVar4;
  uint uVar5;
  uint uVar6;
  undefined4 *_Memory;
  int *piVar7;
  undefined4 uVar8;
  
  uVar8 = 0xffffffff;
  FUN_c098be3c((int *)*param_1);
  uVar5 = param_1[2];
  uVar1 = FUN_c098c6e8(*(uint **)param_1[3],uVar5);
  if (uVar1 == uVar5) {
    if ((int)param_1[1] <= (int)uVar5) goto LAB_c098cc48;
    param_1[2] = uVar5 + 0x20;
    uVar6 = (uVar5 + 0x20 & 0x3fffffff) >> 3;
    puVar2 = calloc(1,(uVar5 + 0x22) * 4 + uVar6);
    if (puVar2 == (undefined4 *)0x0) goto LAB_c098cc48;
    *puVar2 = puVar2 + 2;
    puVar2[1] = (int)puVar2 + uVar6 + 8;
    _Memory = (undefined4 *)param_1[3];
    memcpy(puVar2 + 2,(void *)*_Memory,(param_1[2] & 0x3fffffff) >> 3);
    memcpy((void *)puVar2[1],(void *)_Memory[1],param_1[2] << 2);
    param_1[3] = puVar2;
    free(_Memory);
  }
  iVar3 = *(int *)param_1[3];
  *param_3 = uVar1;
  puVar4 = (uint *)((uVar1 >> 5) * 4 + iVar3);
  *puVar4 = 1 << (uVar1 & 0x1f) | *puVar4;
  uVar8 = 0;
  *(undefined4 *)(*(int *)(param_1[3] + 4) + uVar1 * 4) = param_2;
LAB_c098cc48:
  piVar7 = (int *)*param_1;
  if ((((-1 < *piVar7) && (*piVar7 < 4)) && (piVar7[2] == 1)) &&
     (iVar3 = __GetUserKData(8), piVar7[3] == iVar3)) {
    piVar7[2] = 0;
    piVar7[3] = 0;
    ReleaseMutex((HANDLE)piVar7[1]);
  }
  return uVar8;
}



/* c098cccc FUN_c098cccc */

/* Boundary evidence: original MIPS .pdata c098cccc..c098cd9b. Semantic name remains unreviewed. */

undefined4 * FUN_c098cccc(void)

{
  undefined4 *_Memory;
  int *_Memory_00;
  undefined4 *puVar1;
  
  _Memory = calloc(1,0x10);
  if (_Memory != (undefined4 *)0x0) {
    _Memory_00 = calloc(1,0x110);
    if (_Memory_00 != (int *)0x0) {
      *_Memory_00 = (int)(_Memory_00 + 2);
      _Memory_00[1] = (int)(_Memory_00 + 4);
    }
    _Memory[3] = _Memory_00;
    if (_Memory_00 != (int *)0x0) {
      puVar1 = FUN_c098bcf4(0xe);
      *_Memory = puVar1;
      if (puVar1 != (undefined4 *)0x0) {
        *(uint *)*_Memory_00 = *(uint *)*_Memory_00 | 1;
        _Memory[1] = 0x10000;
        _Memory[2] = 0x40;
        return _Memory;
      }
      free(_Memory_00);
    }
    free(_Memory);
  }
  return (undefined4 *)0x0;
}



/* c098cd9c FUN_c098cd9c */

/* Boundary evidence: original MIPS .pdata c098cd9c..c098cf17. Semantic name remains unreviewed. */

undefined4 FUN_c098cd9c(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  char *pcVar2;
  undefined4 uVar3;
  char *pcVar4;
  int local_28 [2];
  
  if (((param_1 == (int *)0x0) || (*param_1 == 0)) || (*(int *)(*param_1 + 0x4c) == 0)) {
    uVar3 = 0xfffffffd;
  }
  else {
    pcVar4 = "mali_core_irq_handler_upper_half";
    if (param_1[5] != -0x35014542) {
      FUN_c098b68c("Mali: ERR: %s\n","src/devicedrv/mali/common/mali_rendercore.c",param_3,param_4);
      param_3 = 0x5e2;
      pcVar2 = pcVar4;
      FUN_c098b68c("           %s()%4d\n           ","mali_core_irq_handler_upper_half",0x5e2,
                   param_4);
      FUN_c098b68c("Wrong magic number",pcVar2,param_3,param_4);
      FUN_c098b68c("\n",pcVar2,param_3,param_4);
    }
    if (*(int *)(*param_1 + 0xc) != -0x21524111) {
      FUN_c098b68c("Mali: ERR: %s\n","src/devicedrv/mali/common/mali_rendercore.c",param_3,param_4);
      uVar3 = 0x5e3;
      FUN_c098b68c("           %s()%4d\n           ","mali_core_irq_handler_upper_half",0x5e3,
                   param_4);
      FUN_c098b68c("Wrong magic number",pcVar4,uVar3,param_4);
      FUN_c098b68c("\n",pcVar4,uVar3,param_4);
    }
    iVar1 = (**(code **)(*param_1 + 0x4c))(param_1);
    if (iVar1 == 0) {
      if (DAT_c0996798 == 0) {
        return 0xffffffff;
      }
    }
    else {
      local_28[0] = param_1[0x10];
      WriteMsgQueue(*(undefined4 *)(local_28[0] + 4),local_28,4,0,0);
    }
    uVar3 = 0;
  }
  return uVar3;
}



/* c098cfc0 FUN_c098cfc0 */

/* Boundary evidence: original MIPS .pdata c098cfc0..c098d077. Semantic name remains unreviewed. */

void FUN_c098cfc0(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  DWORD DVar1;
  undefined4 uVar2;
  int iVar3;
  
  DVar1 = GetTickCount();
  iVar3 = DVar1 - *(int *)(param_1 + 0x1c);
  if (100000 < iVar3) {
    FUN_c098b68c("Mali: ERR: %s\n","src/devicedrv/mali/common/mali_rendercore.c",param_3,param_4);
    uVar2 = 0x517;
    FUN_c098b68c("           %s()%4d\n           ","mali_core_job_set_run_time",0x517,param_4);
    FUN_c098b68c("Job used too many jiffies: %ld\n",iVar3,uVar2,param_4);
    FUN_c098b68c("\n",iVar3,uVar2,param_4);
    *(undefined4 *)(param_1 + 0x18) = 0;
    return;
  }
  *(int *)(param_1 + 0x18) = iVar3;
  return;
}



/* c098d078 FUN_c098d078 */

/* Boundary evidence: original MIPS .pdata c098d078..c098d09b. Semantic name remains unreviewed. */

void FUN_c098d078(int *param_1)

{
  (**(code **)(*param_1 + 0x70))();
  return;
}



/* c098d09c FUN_c098d09c */

/* Boundary evidence: original MIPS .pdata c098d09c..c098d0b7. Semantic name remains unreviewed. */

void FUN_c098d09c(int param_1,char *param_2,undefined4 param_3,undefined4 param_4)

{
  FUN_c0990294(param_1,param_2,param_3,param_4);
  return;
}



/* c098d0e4 FUN_c098d0e4 */

/* Boundary evidence: original MIPS .pdata c098d0e4..c098d1db. Semantic name remains unreviewed. */

int FUN_c098d0e4(int *param_1,uint param_2,undefined4 param_3,undefined4 param_4)

{
  char *pcVar1;
  undefined4 uVar2;
  int iVar3;
  
  if ((uint)param_1[1] <= param_2) {
    FUN_c098b68c("Mali: ERR: %s\n","src/devicedrv/mali/common/mali_rendercore.c",param_3,param_4);
    uVar2 = 0x1ea;
    FUN_c098b68c("           %s()%4d\n           ","mali_core_renderunit_get_mali_core_nr",0x1ea,
                 param_4);
    FUN_c098b68c("Trying to get illegal mali_core_nr: 0x%x",param_2,uVar2,param_4);
    FUN_c098b68c("\n",param_2,uVar2,param_4);
    return 0;
  }
  iVar3 = *(int *)(param_2 * 4 + *param_1);
  if (*(int *)(iVar3 + 0x14) != -0x35014542) {
    FUN_c098b68c("Mali: ERR: %s\n","src/devicedrv/mali/common/mali_rendercore.c",param_3,param_4);
    uVar2 = 0x1ef;
    pcVar1 = "mali_core_renderunit_get_mali_core_nr";
    FUN_c098b68c("           %s()%4d\n           ","mali_core_renderunit_get_mali_core_nr",0x1ef,
                 param_4);
    FUN_c098b68c("Wrong magic number",pcVar1,uVar2,param_4);
    FUN_c098b68c("\n",pcVar1,uVar2,param_4);
  }
  return iVar3;
}



/* c098d1dc FUN_c098d1dc */

/* Boundary evidence: original MIPS .pdata c098d1dc..c098d26f. Semantic name remains unreviewed. */

void FUN_c098d1dc(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  if (*(LPVOID *)(param_1 + 0x20) == (LPVOID)0x0) {
    FUN_c098b68c("Mali: ERR: %s\n","src/devicedrv/mali/common/mali_rendercore.c",param_3,param_4);
    uVar2 = 0x1d7;
    FUN_c098b68c("           %s()%4d\n           ","mali_core_renderunit_unmap_registers",0x1d7,
                 param_4);
    uVar1 = *(undefined4 *)(param_1 + 0x2c);
    FUN_c098b68c("Trying to unmap register-mapping with NULL from core: %s\n",uVar1,uVar2,param_4);
    FUN_c098b68c("\n",uVar1,uVar2,param_4);
    return;
  }
  VirtualFree(*(LPVOID *)(param_1 + 0x20),0,0x8000);
  *(undefined4 *)(param_1 + 0x20) = 0;
  return;
}



/* c098d270 FUN_c098d270 */

/* Boundary evidence: original MIPS .pdata c098d270..c098d387. Semantic name remains unreviewed. */

undefined4 FUN_c098d270(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  LPVOID pvVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  
  if (((*(uint *)(param_1 + 0x24) != 0) && (*(SIZE_T *)(param_1 + 0x28) != 0)) &&
     (iVar3 = *(int *)(param_1 + 0x2c), param_3 = 0, iVar3 != 0)) {
    pvVar1 = FUN_c098b9c0(*(uint *)(param_1 + 0x24),*(SIZE_T *)(param_1 + 0x28),iVar3);
    *(LPVOID *)(param_1 + 0x20) = pvVar1;
    if (pvVar1 == (LPVOID)0x0) {
      FUN_c098b68c("Mali: ERR: %s\n","src/devicedrv/mali/common/mali_rendercore.c",iVar3,param_4);
      uVar4 = 0x1c0;
      FUN_c098b68c("           %s()%4d\n           ","mali_core_renderunit_map_registers",0x1c0,
                   param_4);
      uVar2 = *(undefined4 *)(param_1 + 0x2c);
      FUN_c098b68c("Could not ioremap registers for %s .\n",uVar2,uVar4,param_4);
      FUN_c098b68c("\n",uVar2,uVar4,param_4);
      return 0xfffffffc;
    }
    return 0;
  }
  FUN_c098b68c("Mali: ERR: %s\n","src/devicedrv/mali/common/mali_rendercore.c",param_3,param_4);
  FUN_c098b68c("           %s()%4d\n           ","mali_core_renderunit_map_registers",0x1ac,param_4)
  ;
  uVar5 = *(undefined4 *)(param_1 + 0x2c);
  uVar4 = *(undefined4 *)(param_1 + 0x28);
  uVar2 = *(undefined4 *)(param_1 + 0x24);
  FUN_c098b68c("Missing fields in the core structure %d %d 0x%x;\n",uVar2,uVar4,uVar5);
  FUN_c098b68c("\n",uVar2,uVar4,uVar5);
  return 0xfffffffd;
}



/* c098d388 FUN_c098d388 */

/* Boundary evidence: original MIPS .pdata c098d388..c098d3d7. Semantic name remains unreviewed. */

void FUN_c098d388(int param_1)

{
  if (*(void **)(param_1 + 0x18) != (void *)0x0) {
    free(*(void **)(param_1 + 0x18));
    *(undefined4 *)(param_1 + 0x18) = 0;
  }
  if (*(void **)(param_1 + 0x1c) != (void *)0x0) {
    free(*(void **)(param_1 + 0x1c));
    *(undefined4 *)(param_1 + 0x1c) = 0;
  }
  return;
}



/* c098d3d8 FUN_c098d3d8 */

/* Boundary evidence: original MIPS .pdata c098d3d8..c098d477. Semantic name remains unreviewed. */

void FUN_c098d3d8(int param_1)

{
  DWORD DVar1;
  int iVar2;
  int local_18 [2];
  
  if (param_1 != 0) {
    if (((DAT_c0996798 == 0) || (iVar2 = *(int *)(param_1 + 0x10), iVar2 == 0)) ||
       (DVar1 = GetTickCount(), -1 < (int)(DVar1 - *(int *)(iVar2 + 0x20)))) {
      *(undefined4 *)(param_1 + 0xc) = 2;
    }
    else {
      *(undefined4 *)(param_1 + 0xc) = 3;
    }
    local_18[0] = *(int *)(param_1 + 0x40);
    WriteMsgQueue(*(undefined4 *)(local_18[0] + 4),local_18,4,0,0);
  }
  return;
}



/* c098d478 FUN_c098d478 */

/* Boundary evidence: original MIPS .pdata c098d478..c098d4d3. Semantic name remains unreviewed. */

void FUN_c098d478(int param_1)

{
  int local_10 [2];
  
  if (((param_1 != 0) && (*(int *)(param_1 + 0xc) != 2)) && (*(int *)(param_1 + 0xc) != 0)) {
    local_10[0] = *(int *)(param_1 + 0x40);
    *(undefined4 *)(param_1 + 0xc) = 4;
    WriteMsgQueue(*(undefined4 *)(local_10[0] + 4),local_10,4,0,0);
  }
  return;
}



/* c098d4d4 FUN_c098d4d4 */

/* Boundary evidence: original MIPS .pdata c098d4d4..c098d58f. Semantic name remains unreviewed. */

void FUN_c098d4d4(int param_1,uint param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  
  if (DAT_c0996798 == 0) {
    if (*(uint *)(param_1 + 0x28) <= param_2) {
      FUN_c098b68c("Mali: ERR: %s\n","src/devicedrv/mali/common/mali_rendercore.c",param_3,param_4);
      FUN_c098b68c("           %s()%4d\n           ","mali_core_renderunit_register_write",0x11a,
                   param_4);
      uVar1 = *(undefined4 *)(param_1 + 0x2c);
      FUN_c098b68c("Trying to write to illegal register: 0x%04x in core: %s",param_2,uVar1,param_4);
      FUN_c098b68c("\n",param_2,uVar1,param_4);
      return;
    }
    *(undefined4 *)(*(int *)(param_1 + 0x20) + param_2) = param_3;
  }
  return;
}



/* c098d590 FUN_c098d590 */

/* Boundary evidence: original MIPS .pdata c098d590..c098d66b. Semantic name remains unreviewed. */

undefined4 FUN_c098d590(int param_1,uint param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  
  if (DAT_c0996798 != 0) {
    return 0;
  }
  if (*(uint *)(param_1 + 0x28) <= param_2) {
    FUN_c098b68c("Mali: ERR: %s\n","src/devicedrv/mali/common/mali_rendercore.c",param_3,param_4);
    FUN_c098b68c("           %s()%4d\n           ","mali_core_renderunit_register_read",0xf2,param_4
                );
    uVar1 = *(undefined4 *)(param_1 + 0x2c);
    FUN_c098b68c("Trying to read from illegal register: 0x%04x in core: %s\n",param_2,uVar1,param_4)
    ;
    FUN_c098b68c("\n",param_2,uVar1,param_4);
    return 0xdeadbeef;
  }
  return *(undefined4 *)(*(int *)(param_1 + 0x20) + param_2);
}



/* c098d66c FUN_c098d66c */

/* Boundary evidence: original MIPS .pdata c098d66c..c098d6c7. Semantic name remains unreviewed. */

void FUN_c098d66c(void)

{
  void *_Memory;
  
  _Memory = DAT_c099679c;
  DAT_c09967e4 = 0;
  DAT_c09967b0 = 0;
  CloseHandle(*(HANDLE *)((int)DAT_c099679c + 4));
  free(_Memory);
  DAT_c099679c = (void *)0x0;
  return;
}



/* c098d6c8 FUN_c098d6c8 */

/* Boundary evidence: original MIPS .pdata c098d6c8..c098d7cf. Semantic name remains unreviewed. */

undefined4 FUN_c098d6c8(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 *_Memory;
  HANDLE pvVar1;
  char *pcVar2;
  undefined4 uVar3;
  
  DAT_c09967a0 = 0;
  _Memory = malloc(0x10);
  if (_Memory == (undefined4 *)0x0) {
    _Memory = (undefined4 *)0x0;
  }
  else {
    param_3 = 0;
    pvVar1 = CreateMutexW((LPSECURITY_ATTRIBUTES)0x0,0,(LPCWSTR)0x0);
    _Memory[1] = pvVar1;
    if (pvVar1 == (HANDLE)0x0) {
      free(_Memory);
      _Memory = (undefined4 *)0x0;
    }
    else {
      _Memory[2] = 0;
      _Memory[3] = 0;
      *_Memory = 2;
    }
  }
  DAT_c099679c = _Memory;
  if (_Memory == (undefined4 *)0x0) {
    FUN_c098b68c("Mali: ERR: %s\n","src/devicedrv/mali/common/mali_rendercore.c",param_3,param_4);
    uVar3 = 0x85;
    pcVar2 = "rendercore_subsystem_startup";
    FUN_c098b68c("           %s()%4d\n           ","rendercore_subsystem_startup",0x85,param_4);
    FUN_c098b68c("Failed: _mali_osk_lock_init\n",pcVar2,uVar3,param_4);
    FUN_c098b68c("\n",pcVar2,uVar3,param_4);
    return 0xffffffff;
  }
  DAT_c09967e4 = "Rendercore Global Subsystem";
  DAT_c09967b0 = 0xdeadbeef;
  return 0;
}



/* c098d834 FUN_c098d834 */

/* Boundary evidence: original MIPS .pdata c098d834..c098da13. Semantic name remains unreviewed. */

void FUN_c098d834(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int *piVar1;
  int iVar2;
  char *pcVar3;
  undefined4 uVar4;
  char *pcVar5;
  
  pcVar5 = "unlock_subsystem";
  if (DAT_c09967a0 == 0) {
    FUN_c098b68c("Mali: ERR: %s\n","src/devicedrv/mali/common/mali_rendercore.c",param_3,param_4);
    param_3 = 0x5a4;
    pcVar3 = pcVar5;
    FUN_c098b68c("           %s()%4d\n           ","unlock_subsystem",0x5a4,param_4);
    FUN_c098b68c("ASSERT MUTEX SHOULD BE GRABBED",pcVar3,param_3,param_4);
    FUN_c098b68c("\n",pcVar3,param_3,param_4);
  }
  if (DAT_c09967b0 != -0x21524111) {
    FUN_c098b68c("Mali: ERR: %s\n","src/devicedrv/mali/common/mali_rendercore.c",param_3,param_4);
    param_3 = 0x5a4;
    pcVar3 = pcVar5;
    FUN_c098b68c("           %s()%4d\n           ","unlock_subsystem",0x5a4,param_4);
    FUN_c098b68c("Wrong magic number",pcVar3,param_3,param_4);
    FUN_c098b68c("\n",pcVar3,param_3,param_4);
  }
  DAT_c09967a0 = 0;
  if (DAT_c09967b0 != -0x21524111) {
    FUN_c098b68c("Mali: ERR: %s\n","src/devicedrv/mali/common/mali_rendercore.c",param_3,param_4);
    param_3 = 0x5a5;
    pcVar3 = pcVar5;
    FUN_c098b68c("           %s()%4d\n           ","unlock_subsystem",0x5a5,param_4);
    FUN_c098b68c("Wrong magic number",pcVar3,param_3,param_4);
    FUN_c098b68c("\n",pcVar3,param_3,param_4);
  }
  piVar1 = DAT_c099679c;
  if ((((-1 < *DAT_c099679c) && (*DAT_c099679c < 4)) && (DAT_c099679c[2] == 1)) &&
     (iVar2 = __GetUserKData(8), piVar1[3] == iVar2)) {
    piVar1[2] = 0;
    piVar1[3] = 0;
    ReleaseMutex((HANDLE)piVar1[1]);
  }
  if (DAT_c09967b0 != -0x21524111) {
    FUN_c098b68c("Mali: ERR: %s\n","src/devicedrv/mali/common/mali_rendercore.c",param_3,param_4);
    uVar4 = 0x5a5;
    FUN_c098b68c("           %s()%4d\n           ","unlock_subsystem",0x5a5,param_4);
    FUN_c098b68c("Wrong magic number",pcVar5,uVar4,param_4);
    FUN_c098b68c("\n",pcVar5,uVar4,param_4);
  }
  return;
}



/* c098da14 FUN_c098da14 */

/* Boundary evidence: original MIPS .pdata c098da14..c098dc0b. Semantic name remains unreviewed. */

void FUN_c098da14(int *param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int *piVar1;
  char *pcVar2;
  IMAGE_DOS_HEADER *pIVar3;
  undefined4 uVar4;
  uint uVar5;
  char *pcVar6;
  
  pcVar6 = "stop_bus_for_all_cores_on_mmu";
  if (DAT_c09967a0 == 0) {
    FUN_c098b68c("Mali: ERR: %s\n","src/devicedrv/mali/common/mali_rendercore.c",param_3,param_4);
    param_3 = 0x554;
    pcVar2 = pcVar6;
    FUN_c098b68c("           %s()%4d\n           ","stop_bus_for_all_cores_on_mmu",0x554,param_4);
    FUN_c098b68c("ASSERT MUTEX SHOULD BE GRABBED",pcVar2,param_3,param_4);
    FUN_c098b68c("\n",pcVar2,param_3,param_4);
  }
  if (param_1[3] != -0x21524111) {
    FUN_c098b68c("Mali: ERR: %s\n","src/devicedrv/mali/common/mali_rendercore.c",param_3,param_4);
    param_3 = 0x554;
    pcVar2 = pcVar6;
    FUN_c098b68c("           %s()%4d\n           ","stop_bus_for_all_cores_on_mmu",0x554,param_4);
    FUN_c098b68c("Wrong magic number",pcVar2,param_3,param_4);
    FUN_c098b68c("\n",pcVar2,param_3,param_4);
  }
  uVar5 = 0;
  if (param_1[1] != 0) {
    do {
      piVar1 = (int *)FUN_c098d0e4(param_1,uVar5,param_3,param_4);
      if (((param_2 == 0) || (piVar1[0xf] == param_2)) && (piVar1[3] != 0)) {
        (**(code **)(*piVar1 + 0x70))(piVar1);
      }
      uVar5 = uVar5 + 1;
    } while (uVar5 < (uint)param_1[1]);
  }
  if (DAT_c09967a0 == 0) {
    FUN_c098b68c("Mali: ERR: %s\n","src/devicedrv/mali/common/mali_rendercore.c",param_3,param_4);
    param_3 = 0x569;
    FUN_c098b68c("           %s()%4d\n           ","stop_bus_for_all_cores_on_mmu",0x569,param_4);
    pIVar3 = &IMAGE_DOS_HEADER_c0980000;
    FUN_c098b68c("ASSERT MUTEX SHOULD BE GRABBED",&IMAGE_DOS_HEADER_c0980000,param_3,param_4);
    FUN_c098b68c("\n",pIVar3,param_3,param_4);
  }
  if (param_1[3] != -0x21524111) {
    FUN_c098b68c("Mali: ERR: %s\n","src/devicedrv/mali/common/mali_rendercore.c",param_3,param_4);
    uVar4 = 0x569;
    FUN_c098b68c("           %s()%4d\n           ","stop_bus_for_all_cores_on_mmu",0x569,param_4);
    FUN_c098b68c("Wrong magic number",pcVar6,uVar4,param_4);
    FUN_c098b68c("\n",pcVar6,uVar4,param_4);
  }
  return;
}



/* c098dc0c FUN_c098dc0c */

/* Boundary evidence: original MIPS .pdata c098dc0c..c098dd87. Semantic name remains unreviewed. */

void FUN_c098dc0c(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int *piVar1;
  DWORD DVar2;
  int iVar3;
  char *pcVar4;
  undefined4 uVar5;
  char *pcVar6;
  
  piVar1 = DAT_c099679c;
  if (((-1 < *DAT_c099679c) && (*DAT_c099679c < 4)) &&
     (DVar2 = WaitForSingleObject((HANDLE)DAT_c099679c[1],0xffffffff), DVar2 == 0)) {
    if (piVar1[2] == 1) {
      ReleaseMutex((HANDLE)piVar1[1]);
    }
    else {
      piVar1[2] = 1;
      iVar3 = __GetUserKData(8);
      piVar1[3] = iVar3;
    }
  }
  pcVar6 = "lock_subsystem";
  if (DAT_c09967b0 != -0x21524111) {
    FUN_c098b68c("Mali: ERR: %s\n","src/devicedrv/mali/common/mali_rendercore.c",param_3,param_4);
    param_3 = 0x549;
    pcVar4 = pcVar6;
    FUN_c098b68c("           %s()%4d\n           ","lock_subsystem",0x549,param_4);
    FUN_c098b68c("Wrong magic number",pcVar4,param_3,param_4);
    FUN_c098b68c("\n",pcVar4,param_3,param_4);
  }
  DAT_c09967a0 = 1;
  if (DAT_c09967b0 != -0x21524111) {
    FUN_c098b68c("Mali: ERR: %s\n","src/devicedrv/mali/common/mali_rendercore.c",param_3,param_4);
    uVar5 = 0x54a;
    FUN_c098b68c("           %s()%4d\n           ","lock_subsystem",0x54a,param_4);
    FUN_c098b68c("Wrong magic number",pcVar6,uVar5,param_4);
    FUN_c098b68c("\n",pcVar6,uVar5,param_4);
  }
  return;
}



/* c098dd88 FUN_c098dd88 */

/* Boundary evidence: original MIPS .pdata c098dd88..c098df13. Semantic name remains unreviewed. */

int FUN_c098dd88(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  char *pcVar1;
  undefined4 uVar2;
  int *piVar3;
  int iVar4;
  char *pcVar5;
  
  pcVar5 = "mali_core_subsystem_get_waiting_session";
  if (*(int *)(param_1 + 0xc) != -0x21524111) {
    FUN_c098b68c("Mali: ERR: %s\n","src/devicedrv/mali/common/mali_rendercore.c",param_3,param_4);
    param_3 = 0x3e6;
    pcVar1 = pcVar5;
    FUN_c098b68c("           %s()%4d\n           ","mali_core_subsystem_get_waiting_session",0x3e6,
                 param_4);
    FUN_c098b68c("Wrong magic number",pcVar1,param_3,param_4);
    FUN_c098b68c("\n",pcVar1,param_3,param_4);
  }
  if (DAT_c09967a0 == 0) {
    FUN_c098b68c("Mali: ERR: %s\n","src/devicedrv/mali/common/mali_rendercore.c",param_3,param_4);
    param_3 = 999;
    pcVar1 = pcVar5;
    FUN_c098b68c("           %s()%4d\n           ","mali_core_subsystem_get_waiting_session",999,
                 param_4);
    FUN_c098b68c("ASSERT MUTEX SHOULD BE GRABBED",pcVar1,param_3,param_4);
    FUN_c098b68c("\n",pcVar1,param_3,param_4);
  }
  if (*(int *)(param_1 + 0xc) != -0x21524111) {
    FUN_c098b68c("Mali: ERR: %s\n","src/devicedrv/mali/common/mali_rendercore.c",param_3,param_4);
    uVar2 = 999;
    FUN_c098b68c("           %s()%4d\n           ","mali_core_subsystem_get_waiting_session",999,
                 param_4);
    FUN_c098b68c("Wrong magic number",pcVar5,uVar2,param_4);
    FUN_c098b68c("\n",pcVar5,uVar2,param_4);
  }
  if (*(int *)(param_1 + 0x30) != 0) {
    iVar4 = 0;
    piVar3 = (int *)(param_1 + 0x18);
    do {
      if ((int *)*piVar3 != piVar3) {
        return *(int *)((iVar4 + 3) * 8 + param_1) + -0x10;
      }
      iVar4 = iVar4 + 1;
      prefetch(piVar3 + 4,0);
      piVar3 = piVar3 + 2;
    } while (iVar4 < 3);
  }
  return 0;
}



/* c098df14 FUN_c098df14 */

/* Boundary evidence: original MIPS .pdata c098df14..c098e117. Semantic name remains unreviewed. */

void FUN_c098df14(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  bool bVar1;
  char *pcVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  int iVar5;
  char *pcVar6;
  
  free((void *)*param_1);
  pcVar6 = "mali_core_subsystem_cleanup_all_renderunits";
  bVar1 = DAT_c09967a0 == 0;
  param_1[1] = 0;
  if (bVar1) {
    FUN_c098b68c("Mali: ERR: %s\n","src/devicedrv/mali/common/mali_rendercore.c",param_3,param_4);
    param_3 = 0x393;
    pcVar2 = pcVar6;
    FUN_c098b68c("           %s()%4d\n           ","mali_core_subsystem_cleanup_all_renderunits",
                 0x393,param_4);
    FUN_c098b68c("ASSERT MUTEX SHOULD BE GRABBED",pcVar2,param_3,param_4);
    FUN_c098b68c("\n",pcVar2,param_3,param_4);
  }
  if (param_1[3] != -0x21524111) {
    FUN_c098b68c("Mali: ERR: %s\n","src/devicedrv/mali/common/mali_rendercore.c",param_3,param_4);
    param_3 = 0x393;
    pcVar2 = pcVar6;
    FUN_c098b68c("           %s()%4d\n           ","mali_core_subsystem_cleanup_all_renderunits",
                 0x393,param_4);
    FUN_c098b68c("Wrong magic number",pcVar2,param_3,param_4);
    FUN_c098b68c("\n",pcVar2,param_3,param_4);
  }
  puVar4 = param_1 + 4;
  if ((undefined4 *)*puVar4 != puVar4) {
    FUN_c098b68c("Mali: ERR: %s\n","src/devicedrv/mali/common/mali_rendercore.c",param_3,param_4);
    param_3 = 0x397;
    pcVar2 = pcVar6;
    FUN_c098b68c("           %s()%4d\n           ","mali_core_subsystem_cleanup_all_renderunits",
                 0x397,param_4);
    FUN_c098b68c("List renderunit_list_idle should be empty.",pcVar2,param_3,param_4);
    FUN_c098b68c("\n",pcVar2,param_3,param_4);
    *puVar4 = puVar4;
    param_1[5] = puVar4;
  }
  puVar4 = param_1 + 6;
  iVar5 = 3;
  do {
    if ((undefined4 *)*puVar4 != puVar4) {
      FUN_c098b68c("Mali: ERR: %s\n","src/devicedrv/mali/common/mali_rendercore.c",param_3,param_4);
      param_3 = 0x39f;
      pcVar2 = pcVar6;
      FUN_c098b68c("           %s()%4d\n           ","mali_core_subsystem_cleanup_all_renderunits",
                   0x39f,param_4);
      FUN_c098b68c("List awaiting_sessions_linkedlist should be empty.",pcVar2,param_3,param_4);
      FUN_c098b68c("\n",pcVar2,param_3,param_4);
      *puVar4 = puVar4;
      puVar4[1] = puVar4;
      param_1[0xc] = 0;
    }
    iVar5 = iVar5 + -1;
    puVar4 = puVar4 + 2;
  } while (iVar5 != 0);
  puVar4 = param_1 + 0xd;
  if ((undefined4 *)*puVar4 != puVar4) {
    FUN_c098b68c("Mali: ERR: %s\n","src/devicedrv/mali/common/mali_rendercore.c",param_3,param_4);
    uVar3 = 0x3a7;
    FUN_c098b68c("           %s()%4d\n           ","mali_core_subsystem_cleanup_all_renderunits",
                 0x3a7,param_4);
    FUN_c098b68c("List all_sessions_linkedlist should be empty.",pcVar6,uVar3,param_4);
    FUN_c098b68c("\n",pcVar6,uVar3,param_4);
    *puVar4 = puVar4;
    param_1[0xe] = puVar4;
  }
  return;
}



/* c098e118 FUN_c098e118 */

/* Boundary evidence: original MIPS .pdata c098e118..c098e397. Semantic name remains unreviewed. */

undefined4 FUN_c098e118(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int *piVar1;
  DWORD DVar2;
  int iVar3;
  char *pcVar4;
  undefined4 uVar5;
  int iVar6;
  undefined4 uVar7;
  char *pcVar8;
  
  piVar1 = DAT_c099679c;
  iVar6 = *param_1;
  uVar7 = 0xffffffff;
  if (iVar6 == 0) {
    uVar7 = 0xffffffff;
  }
  else {
    if (((-1 < *DAT_c099679c) && (*DAT_c099679c < 4)) &&
       (DVar2 = WaitForSingleObject((HANDLE)DAT_c099679c[1],0xffffffff), DVar2 == 0)) {
      if (piVar1[2] == 1) {
        ReleaseMutex((HANDLE)piVar1[1]);
      }
      else {
        piVar1[2] = 1;
        iVar3 = __GetUserKData(8);
        piVar1[3] = iVar3;
      }
    }
    pcVar8 = "mali_core_subsystem_ioctl_suspend_response";
    if (*(int *)(iVar6 + 0xc) != -0x21524111) {
      FUN_c098b68c("Mali: ERR: %s\n","src/devicedrv/mali/common/mali_rendercore.c",param_3,param_4);
      param_3 = 0x37a;
      pcVar4 = pcVar8;
      FUN_c098b68c("           %s()%4d\n           ","mali_core_subsystem_ioctl_suspend_response",
                   0x37a,param_4);
      FUN_c098b68c("Wrong magic number",pcVar4,param_3,param_4);
      FUN_c098b68c("\n",pcVar4,param_3,param_4);
    }
    DAT_c09967a0 = 1;
    if (*(code **)(iVar6 + 0x58) != (code *)0x0) {
      uVar7 = (**(code **)(iVar6 + 0x58))(param_1,param_2);
    }
    DAT_c09967a0 = 0;
    if (*(int *)(iVar6 + 0xc) != -0x21524111) {
      FUN_c098b68c("Mali: ERR: %s\n","src/devicedrv/mali/common/mali_rendercore.c",param_3,param_4);
      param_3 = 0x382;
      pcVar4 = pcVar8;
      FUN_c098b68c("           %s()%4d\n           ","mali_core_subsystem_ioctl_suspend_response",
                   0x382,param_4);
      FUN_c098b68c("Wrong magic number",pcVar4,param_3,param_4);
      FUN_c098b68c("\n",pcVar4,param_3,param_4);
    }
    piVar1 = DAT_c099679c;
    if (((-1 < *DAT_c099679c) && (*DAT_c099679c < 4)) &&
       ((DAT_c099679c[2] == 1 && (iVar3 = __GetUserKData(8), piVar1[3] == iVar3)))) {
      piVar1[2] = 0;
      piVar1[3] = 0;
      ReleaseMutex((HANDLE)piVar1[1]);
    }
    if (*(int *)(iVar6 + 0xc) != -0x21524111) {
      FUN_c098b68c("Mali: ERR: %s\n","src/devicedrv/mali/common/mali_rendercore.c",param_3,param_4);
      uVar5 = 0x382;
      FUN_c098b68c("           %s()%4d\n           ","mali_core_subsystem_ioctl_suspend_response",
                   0x382,param_4);
      FUN_c098b68c("Wrong magic number",pcVar8,uVar5,param_4);
      FUN_c098b68c("\n",pcVar8,uVar5,param_4);
    }
  }
  return uVar7;
}



/* c098e398 FUN_c098e398 */

/* Boundary evidence: original MIPS .pdata c098e398..c098e6af. Semantic name remains unreviewed. */

undefined4
FUN_c098e398(undefined4 *param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4)

{
  int *piVar1;
  DWORD DVar2;
  int iVar3;
  undefined4 uVar4;
  char *pcVar5;
  undefined4 uVar6;
  int *piVar7;
  char *pcVar8;
  
  piVar1 = DAT_c099679c;
  piVar7 = (int *)*param_1;
  if (((-1 < *DAT_c099679c) && (*DAT_c099679c < 4)) &&
     (DVar2 = WaitForSingleObject((HANDLE)DAT_c099679c[1],0xffffffff), DVar2 == 0)) {
    if (piVar1[2] == 1) {
      ReleaseMutex((HANDLE)piVar1[1]);
    }
    else {
      piVar1[2] = 1;
      iVar3 = __GetUserKData(8);
      piVar1[3] = iVar3;
    }
  }
  pcVar8 = "mali_core_subsystem_ioctl_core_version_get";
  if (piVar7[3] != -0x21524111) {
    FUN_c098b68c("Mali: ERR: %s\n","src/devicedrv/mali/common/mali_rendercore.c",param_3,param_4);
    param_3 = 0x327;
    pcVar5 = pcVar8;
    FUN_c098b68c("           %s()%4d\n           ","mali_core_subsystem_ioctl_core_version_get",
                 0x327,param_4);
    FUN_c098b68c("Wrong magic number",pcVar5,param_3,param_4);
    FUN_c098b68c("\n",pcVar5,param_3,param_4);
  }
  DAT_c09967a0 = 1;
  iVar3 = FUN_c098d0e4(piVar7,0,param_3,param_4);
  DAT_c09967a0 = 0;
  if (iVar3 == 0) {
    if (piVar7[3] != -0x21524111) {
      FUN_c098b68c("Mali: ERR: %s\n","src/devicedrv/mali/common/mali_rendercore.c",param_3,param_4);
      param_3 = 0x32d;
      pcVar5 = pcVar8;
      FUN_c098b68c("           %s()%4d\n           ","mali_core_subsystem_ioctl_core_version_get",
                   0x32d,param_4);
      FUN_c098b68c("Wrong magic number",pcVar5,param_3,param_4);
      FUN_c098b68c("\n",pcVar5,param_3,param_4);
    }
    piVar1 = DAT_c099679c;
    if (((-1 < *DAT_c099679c) && (*DAT_c099679c < 4)) &&
       ((DAT_c099679c[2] == 1 && (iVar3 = __GetUserKData(8), piVar1[3] == iVar3)))) {
      piVar1[2] = 0;
      piVar1[3] = 0;
      ReleaseMutex((HANDLE)piVar1[1]);
    }
    if (piVar7[3] != -0x21524111) {
      FUN_c098b68c("Mali: ERR: %s\n","src/devicedrv/mali/common/mali_rendercore.c",param_3,param_4);
      uVar6 = 0x32d;
      FUN_c098b68c("           %s()%4d\n           ","mali_core_subsystem_ioctl_core_version_get",
                   0x32d,param_4);
      FUN_c098b68c("Wrong magic number",pcVar8,uVar6,param_4);
      FUN_c098b68c("\n",pcVar8,uVar6,param_4);
    }
    uVar4 = 0xffffffff;
  }
  else {
    uVar6 = *(undefined4 *)(iVar3 + 0x34);
    if (piVar7[3] != -0x21524111) {
      FUN_c098b68c("Mali: ERR: %s\n","src/devicedrv/mali/common/mali_rendercore.c",param_3,param_4);
      param_3 = 0x332;
      pcVar5 = pcVar8;
      FUN_c098b68c("           %s()%4d\n           ","mali_core_subsystem_ioctl_core_version_get",
                   0x332,param_4);
      FUN_c098b68c("Wrong magic number",pcVar5,param_3,param_4);
      FUN_c098b68c("\n",pcVar5,param_3,param_4);
    }
    piVar1 = DAT_c099679c;
    if (((-1 < *DAT_c099679c) && (*DAT_c099679c < 4)) &&
       ((DAT_c099679c[2] == 1 && (iVar3 = __GetUserKData(8), piVar1[3] == iVar3)))) {
      piVar1[2] = 0;
      piVar1[3] = 0;
      ReleaseMutex((HANDLE)piVar1[1]);
    }
    if (piVar7[3] != -0x21524111) {
      FUN_c098b68c("Mali: ERR: %s\n","src/devicedrv/mali/common/mali_rendercore.c",param_3,param_4);
      uVar4 = 0x332;
      FUN_c098b68c("           %s()%4d\n           ","mali_core_subsystem_ioctl_core_version_get",
                   0x332,param_4);
      FUN_c098b68c("Wrong magic number",pcVar8,uVar4,param_4);
      FUN_c098b68c("\n",pcVar8,uVar4,param_4);
    }
    uVar4 = 0;
    *param_2 = uVar6;
  }
  return uVar4;
}



/* c098e6b0 FUN_c098e6b0 */

/* Boundary evidence: original MIPS .pdata c098e6b0..c098e903. Semantic name remains unreviewed. */

undefined4 FUN_c098e6b0(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int *piVar1;
  undefined4 uVar2;
  DWORD DVar3;
  int iVar4;
  char *pcVar5;
  undefined4 uVar6;
  int iVar7;
  char *pcVar8;
  
  piVar1 = DAT_c099679c;
  iVar7 = *param_1;
  if (iVar7 == 0) {
    uVar2 = 0xffffffff;
  }
  else {
    if (((-1 < *DAT_c099679c) && (*DAT_c099679c < 4)) &&
       (DVar3 = WaitForSingleObject((HANDLE)DAT_c099679c[1],0xffffffff), DVar3 == 0)) {
      if (piVar1[2] == 1) {
        ReleaseMutex((HANDLE)piVar1[1]);
      }
      else {
        piVar1[2] = 1;
        iVar4 = __GetUserKData(8);
        piVar1[3] = iVar4;
      }
    }
    pcVar8 = "mali_core_subsystem_ioctl_start_job";
    if (*(int *)(iVar7 + 0xc) != -0x21524111) {
      FUN_c098b68c("Mali: ERR: %s\n","src/devicedrv/mali/common/mali_rendercore.c",param_3,param_4);
      param_3 = 0x317;
      pcVar5 = pcVar8;
      FUN_c098b68c("           %s()%4d\n           ","mali_core_subsystem_ioctl_start_job",0x317,
                   param_4);
      FUN_c098b68c("Wrong magic number",pcVar5,param_3,param_4);
      FUN_c098b68c("\n",pcVar5,param_3,param_4);
    }
    DAT_c09967a0 = 1;
    uVar2 = (**(code **)(iVar7 + 0x54))(param_1,param_2);
    DAT_c09967a0 = 0;
    if (*(int *)(iVar7 + 0xc) != -0x21524111) {
      FUN_c098b68c("Mali: ERR: %s\n","src/devicedrv/mali/common/mali_rendercore.c",param_3,param_4);
      param_3 = 0x319;
      pcVar5 = pcVar8;
      FUN_c098b68c("           %s()%4d\n           ","mali_core_subsystem_ioctl_start_job",0x319,
                   param_4);
      FUN_c098b68c("Wrong magic number",pcVar5,param_3,param_4);
      FUN_c098b68c("\n",pcVar5,param_3,param_4);
    }
    piVar1 = DAT_c099679c;
    if (((-1 < *DAT_c099679c) && (*DAT_c099679c < 4)) &&
       ((DAT_c099679c[2] == 1 && (iVar4 = __GetUserKData(8), piVar1[3] == iVar4)))) {
      piVar1[2] = 0;
      piVar1[3] = 0;
      ReleaseMutex((HANDLE)piVar1[1]);
    }
    if (*(int *)(iVar7 + 0xc) != -0x21524111) {
      FUN_c098b68c("Mali: ERR: %s\n","src/devicedrv/mali/common/mali_rendercore.c",param_3,param_4);
      uVar6 = 0x319;
      FUN_c098b68c("           %s()%4d\n           ","mali_core_subsystem_ioctl_start_job",0x319,
                   param_4);
      FUN_c098b68c("Wrong magic number",pcVar8,uVar6,param_4);
      FUN_c098b68c("\n",pcVar8,uVar6,param_4);
    }
  }
  return uVar2;
}



/* c098e904 FUN_c098e904 */

/* Boundary evidence: original MIPS .pdata c098e904..c098ec5b. Semantic name remains unreviewed. */

char * FUN_c098e904(int *param_1,int *param_2,undefined4 param_3,undefined4 param_4)

{
  char *pcVar1;
  DWORD DVar2;
  int *piVar3;
  char *pcVar4;
  undefined4 uVar5;
  int iVar6;
  uint uVar7;
  char *pcVar8;
  
  piVar3 = DAT_c099679c;
  if (param_2 == (int *)0x0) {
    pcVar1 = (char *)0xfffffffd;
  }
  else {
    iVar6 = *param_2;
    while (iVar6 != 0) {
      param_2 = (int *)(iVar6 + 0x14);
      iVar6 = *param_2;
    }
    if (((-1 < *DAT_c099679c) && (*DAT_c099679c < 4)) &&
       (DVar2 = WaitForSingleObject((HANDLE)DAT_c099679c[1],0xffffffff), DVar2 == 0)) {
      if (piVar3[2] == 1) {
        ReleaseMutex((HANDLE)piVar3[1]);
      }
      else {
        piVar3[2] = 1;
        iVar6 = __GetUserKData(8);
        piVar3[3] = iVar6;
      }
    }
    pcVar8 = "mali_core_subsystem_system_info_fill";
    if (param_1[3] != -0x21524111) {
      FUN_c098b68c("Mali: ERR: %s\n","src/devicedrv/mali/common/mali_rendercore.c",param_3,param_4);
      param_3 = 0x2a6;
      pcVar1 = pcVar8;
      FUN_c098b68c("           %s()%4d\n           ","mali_core_subsystem_system_info_fill",0x2a6,
                   param_4);
      FUN_c098b68c("Wrong magic number",pcVar1,param_3,param_4);
      FUN_c098b68c("\n",pcVar1,param_3,param_4);
    }
    DAT_c09967a0 = 1;
    uVar7 = 0;
    if (param_1[1] == 0) {
      pcVar1 = "Wrong magic number";
LAB_c098eb4c:
      FUN_c098b68c("Mali: ERR: %s\n","src/devicedrv/mali/common/mali_rendercore.c",param_3,param_4);
      param_3 = 0x2ba;
      FUN_c098b68c("           %s()%4d\n           ","mali_core_subsystem_system_info_fill",0x2ba,
                   param_4);
      pcVar4 = pcVar1;
      FUN_c098b68c("Error: In mali_core_subsystem_system_info_fill %d\n",pcVar1,param_3,param_4);
      FUN_c098b68c("\n",pcVar4,param_3,param_4);
    }
    else {
      do {
        pcVar1 = (char *)0xfffffffc;
        iVar6 = FUN_c098d0e4(param_1,uVar7,param_3,param_4);
        if ((iVar6 == 0) || (piVar3 = calloc(1,0x18), piVar3 == (int *)0x0)) goto LAB_c098eb4c;
        piVar3[1] = *(int *)(iVar6 + 0x34);
        *piVar3 = param_1[2];
        iVar6 = *(int *)(iVar6 + 0x24);
        piVar3[3] = uVar7;
        uVar7 = uVar7 + 1;
        piVar3[2] = iVar6;
        piVar3[5] = 0;
        *param_2 = (int)piVar3;
        param_2 = piVar3 + 5;
      } while (uVar7 < (uint)param_1[1]);
      pcVar1 = (char *)0x0;
    }
    DAT_c09967a0 = 0;
    if (param_1[3] != -0x21524111) {
      FUN_c098b68c("Mali: ERR: %s\n","src/devicedrv/mali/common/mali_rendercore.c",param_3,param_4);
      param_3 = 0x2cb;
      pcVar4 = pcVar8;
      FUN_c098b68c("           %s()%4d\n           ","mali_core_subsystem_system_info_fill",0x2cb,
                   param_4);
      FUN_c098b68c("Wrong magic number",pcVar4,param_3,param_4);
      FUN_c098b68c("\n",pcVar4,param_3,param_4);
    }
    piVar3 = DAT_c099679c;
    if (((-1 < *DAT_c099679c) && (*DAT_c099679c < 4)) &&
       ((DAT_c099679c[2] == 1 && (iVar6 = __GetUserKData(8), piVar3[3] == iVar6)))) {
      piVar3[2] = 0;
      piVar3[3] = 0;
      ReleaseMutex((HANDLE)piVar3[1]);
    }
    if (param_1[3] != -0x21524111) {
      FUN_c098b68c("Mali: ERR: %s\n","src/devicedrv/mali/common/mali_rendercore.c",param_3,param_4);
      uVar5 = 0x2cb;
      FUN_c098b68c("           %s()%4d\n           ","mali_core_subsystem_system_info_fill",0x2cb,
                   param_4);
      FUN_c098b68c("Wrong magic number",pcVar8,uVar5,param_4);
      FUN_c098b68c("\n",pcVar8,uVar5,param_4);
    }
  }
  return pcVar1;
}



/* c098ec5c FUN_c098ec5c */

/* Boundary evidence: original MIPS .pdata c098ec5c..c098ed0b. Semantic name remains unreviewed. */

void FUN_c098ec5c(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int iVar4;
  int *piVar5;
  uint uVar6;
  
  uVar6 = 0;
  if (param_1[1] != 0) {
    do {
      iVar4 = FUN_c098d0e4(param_1,uVar6,param_3,param_4);
      if (iVar4 == 0) {
        return;
      }
      if ((undefined4 **)DAT_c0996754 != &DAT_c0996754) {
        puVar3 = (undefined4 *)*DAT_c0996754;
        puVar2 = DAT_c0996754;
        do {
          puVar1 = puVar3;
          piVar5 = puVar2 + -6;
          if (*(int *)(iVar4 + 0x38) == *piVar5) goto LAB_c098ecdc;
          puVar3 = (undefined4 *)*puVar1;
          puVar2 = puVar1;
        } while ((undefined4 **)puVar1 != &DAT_c0996754);
      }
      piVar5 = (int *)0x0;
LAB_c098ecdc:
      *(int **)(iVar4 + 0x3c) = piVar5;
      uVar6 = uVar6 + 1;
    } while (uVar6 < (uint)param_1[1]);
  }
  return;
}



/* c098ed0c FUN_c098ed0c */

/* Boundary evidence: original MIPS .pdata c098ed0c..c098ee03. Semantic name remains unreviewed. */

undefined4 FUN_c098ed0c(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  char *pcVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  if ((((*(int *)(param_1 + 0x40) != 0) && (*(int *)(param_1 + 0x48) != 0)) &&
      (*(int *)(param_1 + 0x4c) != 0)) &&
     (((*(int *)(param_1 + 0x50) != 0 && (*(int *)(param_1 + 0x54) != 0)) &&
      (*(int *)(param_1 + 0x5c) != 0)))) {
    *(undefined4 *)(param_1 + 0xc) = 0xdeadbeef;
    iVar4 = param_1 + 0x10;
    iVar3 = param_1 + 0x18;
    *(int *)iVar4 = iVar4;
    *(int *)(param_1 + 0x14) = iVar4;
    iVar4 = param_1 + 0x20;
    *(int *)iVar3 = iVar3;
    iVar5 = param_1 + 0x28;
    *(int *)(param_1 + 0x1c) = iVar3;
    iVar3 = param_1 + 0x34;
    *(int *)iVar4 = iVar4;
    *(int *)(param_1 + 0x24) = iVar4;
    *(int *)iVar5 = iVar5;
    *(int *)(param_1 + 0x2c) = iVar5;
    *(int *)iVar3 = iVar3;
    *(int *)(param_1 + 0x38) = iVar3;
    return 0;
  }
  FUN_c098b68c("Mali: ERR: %s\n","src/devicedrv/mali/common/mali_rendercore.c",param_3,param_4);
  uVar2 = 0x203;
  pcVar1 = "mali_core_subsystem_init";
  FUN_c098b68c("           %s()%4d\n           ","mali_core_subsystem_init",0x203,param_4);
  FUN_c098b68c("Missing functions in subsystem.",pcVar1,uVar2,param_4);
  FUN_c098b68c("\n",pcVar1,uVar2,param_4);
  return 0xffffffff;
}



/* c098ee04 FUN_c098ee04 */

/* Boundary evidence: original MIPS .pdata c098ee04..c098ee1f. Semantic name remains unreviewed. */

void FUN_c098ee04(int param_1)

{
  FUN_c098c058(*(void **)(param_1 + 0x40));
  return;
}



/* c098ee20 FUN_c098ee20 */

/* Boundary evidence: original MIPS .pdata c098ee20..c098ef6f. Semantic name remains unreviewed. */

undefined4 FUN_c098ee20(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  void *pvVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  
  iVar4 = param_1 + 4;
  *(int *)iVar4 = iVar4;
  *(int *)(param_1 + 8) = iVar4;
  pvVar1 = calloc(1,0xc);
  *(void **)(param_1 + 0x18) = pvVar1;
  if (pvVar1 == (void *)0x0) {
    FUN_c098b68c("Mali: ERR: %s\n","src/devicedrv/mali/common/mali_rendercore.c",param_3,param_4);
    uVar3 = 0x179;
    FUN_c098b68c("           %s()%4d\n           ","mali_core_renderunit_init",0x179,param_4);
    uVar2 = *(undefined4 *)(param_1 + 0x2c);
    FUN_c098b68c("Core: renderunit_init: Core:%s -- cannot init timer\n",uVar2,uVar3,param_4);
    FUN_c098b68c("\n",uVar2,uVar3,param_4);
    return 0xffffffff;
  }
  *(code **)((int)pvVar1 + 4) = FUN_c098d3d8;
  *(int *)((int)pvVar1 + 8) = param_1;
  pvVar1 = calloc(1,0xc);
  *(void **)(param_1 + 0x1c) = pvVar1;
  if (pvVar1 == (void *)0x0) {
    free(*(void **)(param_1 + 0x18));
    FUN_c098b68c("Mali: ERR: %s\n","src/devicedrv/mali/common/mali_rendercore.c",param_3,param_4);
    uVar3 = 0x183;
    FUN_c098b68c("           %s()%4d\n           ","mali_core_renderunit_init",0x183,param_4);
    uVar2 = *(undefined4 *)(param_1 + 0x2c);
    FUN_c098b68c("Core: renderunit_init: Core:%s -- cannot init hang detection timer\n",uVar2,uVar3,
                 param_4);
    FUN_c098b68c("\n",uVar2,uVar3,param_4);
    return 0xffffffff;
  }
  *(int *)((int)pvVar1 + 8) = param_1;
  *(code **)((int)pvVar1 + 4) = FUN_c098d478;
  *(undefined4 *)(param_1 + 0xc) = 0;
  *(undefined4 *)(param_1 + 0x10) = 0;
  *(undefined4 *)(param_1 + 0x14) = 0xcafebabe;
  *(undefined4 *)(param_1 + 0x3c) = 0;
  return 0;
}



/* c098ef70 FUN_c098ef70 */

/* Boundary evidence: original MIPS .pdata c098ef70..c098f0a3. Semantic name remains unreviewed. */

void FUN_c098ef70(int param_1,uint param_2,int param_3,int param_4)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  if (param_4 != 0) {
    iVar4 = param_3 - param_2;
    iVar3 = DAT_c0996798;
    iVar2 = param_4;
    do {
      if (iVar3 == 0) {
        if (param_2 < *(uint *)(param_1 + 0x28)) {
          *(undefined4 *)(*(int *)(param_1 + 0x20) + param_2) = *(undefined4 *)(iVar4 + param_2);
        }
        else {
          FUN_c098b68c("Mali: ERR: %s\n","src/devicedrv/mali/common/mali_rendercore.c",param_3,
                       param_4);
          FUN_c098b68c("           %s()%4d\n           ","mali_core_renderunit_register_write",0x11a
                       ,param_4);
          param_3 = *(int *)(param_1 + 0x2c);
          uVar1 = param_2;
          FUN_c098b68c("Trying to write to illegal register: 0x%04x in core: %s",param_2,param_3,
                       param_4);
          FUN_c098b68c("\n",uVar1,param_3,param_4);
          iVar3 = DAT_c0996798;
        }
      }
      param_2 = param_2 + 4;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
  }
  return;
}



/* c098f0a4 FUN_c098f0a4 */

/* Boundary evidence: original MIPS .pdata c098f0a4..c098f18f. Semantic name remains unreviewed. */

void FUN_c098f0a4(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  switch(param_1) {
  case 0:
    FUN_c098dc0c(&DAT_c09967a4,param_2,param_3,param_4);
    return;
  case 1:
  case 2:
  case 3:
    break;
  case 4:
    FUN_c098d834(&DAT_c09967a4,param_2,param_3,param_4);
    return;
  default:
    FUN_c098b68c("Mali: ERR: %s\n","src/devicedrv/mali/common/mali_rendercore.c",param_3,param_4);
    FUN_c098b68c("           %s()%4d\n           ","rendercore_subsystem_broadcast_notification",
                 0xdd,param_4);
    FUN_c098b68c("Illegal message: 0x%x, data: 0x%x\n",param_1,param_2,param_4);
    FUN_c098b68c("\n",param_1,param_2,param_4);
  }
  return;
}



/* c098f1f0 FUN_c098f1f0 */

/* Boundary evidence: original MIPS .pdata c098f1f0..c098f4bf. Semantic name remains unreviewed. */

void FUN_c098f1f0(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  DWORD DVar1;
  char *pcVar2;
  char *pcVar3;
  undefined4 uVar4;
  int iVar5;
  int *piVar6;
  int *piVar7;
  int iVar8;
  int *piVar9;
  
  iVar8 = *param_1;
  if (iVar8 == 0) {
    FUN_c098b68c("Mali: ERR: %s\n","src/devicedrv/mali/common/mali_rendercore.c",param_3,param_4);
    uVar4 = 0x494;
    pcVar2 = "mali_core_session_begin";
    FUN_c098b68c("           %s()%4d\n           ","mali_core_session_begin",0x494,param_4);
    FUN_c098b68c("Missing data in struct\n",pcVar2,uVar4,param_4);
  }
  else {
    param_1[10] = -0x4541edcc;
    piVar6 = param_1 + 1;
    *piVar6 = (int)piVar6;
    piVar7 = param_1 + 4;
    param_1[2] = (int)piVar6;
    piVar9 = param_1 + 6;
    param_1[3] = 0;
    piVar6 = DAT_c099679c;
    *piVar7 = (int)piVar7;
    param_1[5] = (int)piVar7;
    *piVar9 = (int)piVar9;
    param_1[7] = (int)piVar9;
    piVar7 = piVar6;
    if (((-1 < *piVar6) && (*piVar6 < 4)) &&
       (DVar1 = WaitForSingleObject((HANDLE)piVar6[1],0xffffffff), piVar7 = DAT_c099679c, DVar1 == 0
       )) {
      if (piVar6[2] == 1) {
        ReleaseMutex((HANDLE)piVar6[1]);
        piVar7 = DAT_c099679c;
      }
      else {
        piVar6[2] = 1;
        iVar5 = __GetUserKData(8);
        piVar6[3] = iVar5;
        piVar7 = DAT_c099679c;
      }
    }
    pcVar2 = "mali_core_session_begin";
    if (*(int *)(iVar8 + 0xc) != -0x21524111) {
      FUN_c098b68c("Mali: ERR: %s\n","src/devicedrv/mali/common/mali_rendercore.c",param_3,param_4);
      param_3 = 0x4a1;
      pcVar3 = pcVar2;
      FUN_c098b68c("           %s()%4d\n           ","mali_core_session_begin",0x4a1,param_4);
      FUN_c098b68c("Wrong magic number",pcVar3,param_3,param_4);
      FUN_c098b68c("\n",pcVar3,param_3,param_4);
      piVar7 = DAT_c099679c;
    }
    piVar6 = (int *)(*param_1 + 0x34);
    iVar5 = *piVar6;
    *(int **)(iVar5 + 4) = piVar9;
    *piVar9 = iVar5;
    param_1[7] = (int)piVar6;
    *piVar6 = (int)piVar9;
    DAT_c09967a0 = 0;
    if (*(int *)(iVar8 + 0xc) != -0x21524111) {
      FUN_c098b68c("Mali: ERR: %s\n","src/devicedrv/mali/common/mali_rendercore.c",param_3,param_4);
      param_3 = 0x4a3;
      pcVar3 = pcVar2;
      FUN_c098b68c("           %s()%4d\n           ","mali_core_session_begin",0x4a3,param_4);
      FUN_c098b68c("Wrong magic number",pcVar3,param_3,param_4);
      FUN_c098b68c("\n",pcVar3,param_3,param_4);
      piVar7 = DAT_c099679c;
    }
    if (((-1 < *piVar7) && (*piVar7 < 4)) &&
       ((piVar7[2] == 1 && (iVar5 = __GetUserKData(8), piVar7[3] == iVar5)))) {
      piVar7[2] = 0;
      piVar7[3] = 0;
      ReleaseMutex((HANDLE)piVar7[1]);
    }
    if (*(int *)(iVar8 + 0xc) == -0x21524111) {
      return;
    }
    FUN_c098b68c("Mali: ERR: %s\n","src/devicedrv/mali/common/mali_rendercore.c",param_3,param_4);
    uVar4 = 0x4a3;
    FUN_c098b68c("           %s()%4d\n           ","mali_core_session_begin",0x4a3,param_4);
    FUN_c098b68c("Wrong magic number",pcVar2,uVar4,param_4);
  }
  FUN_c098b68c("\n",pcVar2,uVar4,param_4);
  return;
}



/* c098f4c0 FUN_c098f4c0 */

/* Boundary evidence: original MIPS .pdata c098f4c0..c098f67b. Semantic name remains unreviewed. */

int FUN_c098f4c0(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  char *pcVar1;
  undefined4 uVar2;
  int *piVar3;
  int iVar4;
  int *piVar5;
  char *pcVar6;
  
  pcVar6 = "mali_core_subsystem_release_session_get_job";
  if (*(int *)(param_1 + 0xc) != -0x21524111) {
    FUN_c098b68c("Mali: ERR: %s\n","src/devicedrv/mali/common/mali_rendercore.c",param_3,param_4);
    param_3 = 0x3fd;
    pcVar1 = pcVar6;
    FUN_c098b68c("           %s()%4d\n           ","mali_core_subsystem_release_session_get_job",
                 0x3fd,param_4);
    FUN_c098b68c("Wrong magic number",pcVar1,param_3,param_4);
    FUN_c098b68c("\n",pcVar1,param_3,param_4);
  }
  if (DAT_c09967a0 == 0) {
    FUN_c098b68c("Mali: ERR: %s\n","src/devicedrv/mali/common/mali_rendercore.c",param_3,param_4);
    param_3 = 0x3fe;
    pcVar1 = pcVar6;
    FUN_c098b68c("           %s()%4d\n           ","mali_core_subsystem_release_session_get_job",
                 0x3fe,param_4);
    FUN_c098b68c("ASSERT MUTEX SHOULD BE GRABBED",pcVar1,param_3,param_4);
    FUN_c098b68c("\n",pcVar1,param_3,param_4);
  }
  if (*(int *)(param_1 + 0xc) != -0x21524111) {
    FUN_c098b68c("Mali: ERR: %s\n","src/devicedrv/mali/common/mali_rendercore.c",param_3,param_4);
    param_3 = 0x3fe;
    pcVar1 = pcVar6;
    FUN_c098b68c("           %s()%4d\n           ","mali_core_subsystem_release_session_get_job",
                 0x3fe,param_4);
    FUN_c098b68c("Wrong magic number",pcVar1,param_3,param_4);
    FUN_c098b68c("\n",pcVar1,param_3,param_4);
  }
  piVar5 = (int *)(param_2 + 0x10);
  iVar4 = *piVar5;
  piVar3 = *(int **)(param_2 + 0x14);
  *(int **)(iVar4 + 4) = piVar3;
  *piVar3 = iVar4;
  *piVar5 = (int)piVar5;
  *(int **)(param_2 + 0x14) = piVar5;
  *(int *)(param_1 + 0x30) = *(int *)(param_1 + 0x30) + -1;
  iVar4 = *(int *)(param_2 + 0xc);
  *(undefined4 *)(param_2 + 0xc) = 0;
  if (*(int *)(iVar4 + 0xc) != 0x123abcd) {
    FUN_c098b68c("Mali: ERR: %s\n","src/devicedrv/mali/common/mali_rendercore.c",param_3,param_4);
    uVar2 = 0x404;
    FUN_c098b68c("           %s()%4d\n           ","mali_core_subsystem_release_session_get_job",
                 0x404,param_4);
    FUN_c098b68c("Wrong magic number",pcVar6,uVar2,param_4);
    FUN_c098b68c("\n",pcVar6,uVar2,param_4);
  }
  return iVar4;
}



/* c098f67c FUN_c098f67c */

/* Boundary evidence: original MIPS .pdata c098f67c..c098fb83. Semantic name remains unreviewed. */

void FUN_c098f67c(int *param_1,char *param_2,undefined4 param_3,undefined4 param_4)

{
  DWORD DVar1;
  int iVar2;
  int iVar3;
  char *pcVar4;
  undefined4 uVar5;
  int *piVar6;
  int *piVar7;
  char *pcVar8;
  uint local_30;
  
  piVar6 = DAT_c099679c;
  if ((-1 < *DAT_c099679c) && (*DAT_c099679c < 4)) {
    param_2 = (char *)0xffffffff;
    DVar1 = WaitForSingleObject((HANDLE)DAT_c099679c[1],0xffffffff);
    if (DVar1 == 0) {
      if (piVar6[2] == 1) {
        ReleaseMutex((HANDLE)piVar6[1]);
      }
      else {
        piVar6[2] = 1;
        iVar2 = __GetUserKData(8);
        piVar6[3] = iVar2;
      }
    }
  }
  pcVar8 = "mali_core_subsystem_cleanup";
  if (param_1[3] != -0x21524111) {
    FUN_c098b68c("Mali: ERR: %s\n","src/devicedrv/mali/common/mali_rendercore.c",param_3,param_4);
    param_3 = 0x2d7;
    param_2 = pcVar8;
    FUN_c098b68c("           %s()%4d\n           ","mali_core_subsystem_cleanup",0x2d7,param_4);
    FUN_c098b68c("Wrong magic number",param_2,param_3,param_4);
    FUN_c098b68c("\n",param_2,param_3,param_4);
  }
  DAT_c09967a0 = 1;
  local_30 = 0;
  if (param_1[1] != 0) {
    do {
      iVar2 = FUN_c098d0e4(param_1,local_30,param_3,param_4);
      if (*(int *)(iVar2 + 0x3c) != 0) {
        FUN_c0984fd0(*(int *)(iVar2 + 0x3c));
      }
      DAT_c09967a0 = 0;
      if (param_1[3] != -0x21524111) {
        FUN_c098b68c("Mali: ERR: %s\n","src/devicedrv/mali/common/mali_rendercore.c",param_3,param_4
                    );
        param_3 = 0x2e5;
        pcVar4 = pcVar8;
        FUN_c098b68c("           %s()%4d\n           ","mali_core_subsystem_cleanup",0x2e5,param_4);
        FUN_c098b68c("Wrong magic number",pcVar4,param_3,param_4);
        FUN_c098b68c("\n",pcVar4,param_3,param_4);
      }
      piVar6 = DAT_c099679c;
      if ((((-1 < *DAT_c099679c) && (*DAT_c099679c < 4)) && (DAT_c099679c[2] == 1)) &&
         (iVar3 = __GetUserKData(8), piVar6[3] == iVar3)) {
        piVar6[2] = 0;
        piVar6[3] = 0;
        ReleaseMutex((HANDLE)piVar6[1]);
      }
      if (param_1[3] != -0x21524111) {
        FUN_c098b68c("Mali: ERR: %s\n","src/devicedrv/mali/common/mali_rendercore.c",param_3,param_4
                    );
        param_3 = 0x2e5;
        pcVar4 = pcVar8;
        FUN_c098b68c("           %s()%4d\n           ","mali_core_subsystem_cleanup",0x2e5,param_4);
        FUN_c098b68c("Wrong magic number",pcVar4,param_3,param_4);
        FUN_c098b68c("\n",pcVar4,param_3,param_4);
      }
      FUN_c098c058(*(void **)(iVar2 + 0x40));
      piVar6 = DAT_c099679c;
      if (((-1 < *DAT_c099679c) && (*DAT_c099679c < 4)) &&
         (DVar1 = WaitForSingleObject((HANDLE)DAT_c099679c[1],0xffffffff), DVar1 == 0)) {
        if (piVar6[2] == 1) {
          ReleaseMutex((HANDLE)piVar6[1]);
        }
        else {
          piVar6[2] = 1;
          iVar3 = __GetUserKData(8);
          piVar6[3] = iVar3;
        }
      }
      if (param_1[3] != -0x21524111) {
        FUN_c098b68c("Mali: ERR: %s\n","src/devicedrv/mali/common/mali_rendercore.c",param_3,param_4
                    );
        param_3 = 0x2f0;
        pcVar4 = pcVar8;
        FUN_c098b68c("           %s()%4d\n           ","mali_core_subsystem_cleanup",0x2f0,param_4);
        FUN_c098b68c("Wrong magic number",pcVar4,param_3,param_4);
        FUN_c098b68c("\n",pcVar4,param_3,param_4);
      }
      DAT_c09967a0 = 1;
      (*(code *)param_1[0x19])(iVar2,1);
      if (*(LPVOID *)(iVar2 + 0x20) == (LPVOID)0x0) {
        FUN_c098b68c("Mali: ERR: %s\n","src/devicedrv/mali/common/mali_rendercore.c",param_3,param_4
                    );
        param_3 = 0x1d7;
        FUN_c098b68c("           %s()%4d\n           ","mali_core_renderunit_unmap_registers",0x1d7,
                     param_4);
        param_2 = *(char **)(iVar2 + 0x2c);
        FUN_c098b68c("Trying to unmap register-mapping with NULL from core: %s\n",param_2,param_3,
                     param_4);
        FUN_c098b68c("\n",param_2,param_3,param_4);
      }
      else {
        param_3 = 0x8000;
        param_2 = (char *)0x0;
        VirtualFree(*(LPVOID *)(iVar2 + 0x20),0,0x8000);
        *(undefined4 *)(iVar2 + 0x20) = 0;
      }
      piVar7 = (int *)(iVar2 + 4);
      iVar3 = *piVar7;
      piVar6 = *(int **)(iVar2 + 8);
      *(int **)(iVar3 + 4) = piVar6;
      *piVar6 = iVar3;
      *piVar7 = (int)piVar7;
      *(int **)(iVar2 + 8) = piVar7;
      if (*(void **)(iVar2 + 0x18) != (void *)0x0) {
        free(*(void **)(iVar2 + 0x18));
        *(undefined4 *)(iVar2 + 0x18) = 0;
      }
      if (*(void **)(iVar2 + 0x1c) != (void *)0x0) {
        free(*(void **)(iVar2 + 0x1c));
        *(undefined4 *)(iVar2 + 0x1c) = 0;
      }
      (*(code *)param_1[0x18])(iVar2);
      local_30 = local_30 + 1;
    } while (local_30 < (uint)param_1[1]);
  }
  FUN_c098df14(param_1,param_2,param_3,param_4);
  DAT_c09967a0 = 0;
  if (param_1[3] != -0x21524111) {
    FUN_c098b68c("Mali: ERR: %s\n","src/devicedrv/mali/common/mali_rendercore.c",param_3,param_4);
    param_3 = 0x2fe;
    pcVar4 = pcVar8;
    FUN_c098b68c("           %s()%4d\n           ","mali_core_subsystem_cleanup",0x2fe,param_4);
    FUN_c098b68c("Wrong magic number",pcVar4,param_3,param_4);
    FUN_c098b68c("\n",pcVar4,param_3,param_4);
  }
  piVar6 = DAT_c099679c;
  if (((-1 < *DAT_c099679c) && (*DAT_c099679c < 4)) &&
     ((DAT_c099679c[2] == 1 && (iVar2 = __GetUserKData(8), piVar6[3] == iVar2)))) {
    piVar6[2] = 0;
    piVar6[3] = 0;
    ReleaseMutex((HANDLE)piVar6[1]);
  }
  if (param_1[3] != -0x21524111) {
    FUN_c098b68c("Mali: ERR: %s\n","src/devicedrv/mali/common/mali_rendercore.c",param_3,param_4);
    uVar5 = 0x2fe;
    FUN_c098b68c("           %s()%4d\n           ","mali_core_subsystem_cleanup",0x2fe,param_4);
    FUN_c098b68c("Wrong magic number",pcVar8,uVar5,param_4);
    FUN_c098b68c("\n",pcVar8,uVar5,param_4);
  }
  return;
}



/* c098fbac FUN_c098fbac */

/* Boundary evidence: original MIPS .pdata c098fbac..c098fdd3. Semantic name remains unreviewed. */

void FUN_c098fbac(int *param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  DWORD DVar1;
  char *pcVar2;
  undefined4 uVar3;
  int iVar4;
  int *piVar5;
  int *piVar6;
  int *piVar7;
  char *pcVar8;
  int iVar9;
  
  iVar4 = *(int *)(param_2 + 8);
  iVar9 = *param_1;
  pcVar8 = "mali_core_subsystem_move_set_working";
  if (param_1[5] != -0x35014542) {
    FUN_c098b68c("Mali: ERR: %s\n","src/devicedrv/mali/common/mali_rendercore.c",param_3,param_4);
    param_3 = 0x3cf;
    pcVar2 = pcVar8;
    FUN_c098b68c("           %s()%4d\n           ","mali_core_subsystem_move_set_working",0x3cf,
                 param_4);
    FUN_c098b68c("Wrong magic number",pcVar2,param_3,param_4);
    FUN_c098b68c("\n",pcVar2,param_3,param_4);
  }
  if (*(int *)(param_2 + 0xc) != 0x123abcd) {
    FUN_c098b68c("Mali: ERR: %s\n","src/devicedrv/mali/common/mali_rendercore.c",param_3,param_4);
    param_3 = 0x3d0;
    pcVar2 = pcVar8;
    FUN_c098b68c("           %s()%4d\n           ","mali_core_subsystem_move_set_working",0x3d0,
                 param_4);
    FUN_c098b68c("Wrong magic number",pcVar2,param_3,param_4);
    FUN_c098b68c("\n",pcVar2,param_3,param_4);
  }
  if (*(int *)(iVar9 + 0xc) != -0x21524111) {
    FUN_c098b68c("Mali: ERR: %s\n","src/devicedrv/mali/common/mali_rendercore.c",param_3,param_4);
    param_3 = 0x3d1;
    pcVar2 = pcVar8;
    FUN_c098b68c("           %s()%4d\n           ","mali_core_subsystem_move_set_working",0x3d1,
                 param_4);
    FUN_c098b68c("Wrong magic number",pcVar2,param_3,param_4);
    FUN_c098b68c("\n",pcVar2,param_3,param_4);
  }
  if (DAT_c09967a0 == 0) {
    FUN_c098b68c("Mali: ERR: %s\n","src/devicedrv/mali/common/mali_rendercore.c",param_3,param_4);
    param_3 = 0x3d3;
    pcVar2 = pcVar8;
    FUN_c098b68c("           %s()%4d\n           ","mali_core_subsystem_move_set_working",0x3d3,
                 param_4);
    FUN_c098b68c("ASSERT MUTEX SHOULD BE GRABBED",pcVar2,param_3,param_4);
    FUN_c098b68c("\n",pcVar2,param_3,param_4);
  }
  if (*(int *)(iVar9 + 0xc) != -0x21524111) {
    FUN_c098b68c("Mali: ERR: %s\n","src/devicedrv/mali/common/mali_rendercore.c",param_3,param_4);
    uVar3 = 0x3d3;
    FUN_c098b68c("           %s()%4d\n           ","mali_core_subsystem_move_set_working",0x3d3,
                 param_4);
    FUN_c098b68c("Wrong magic number",pcVar8,uVar3,param_4);
    FUN_c098b68c("\n",pcVar8,uVar3,param_4);
  }
  param_1[3] = 1;
  param_1[4] = param_2;
  DVar1 = GetTickCount();
  piVar6 = param_1 + 1;
  *(DWORD *)(param_2 + 0x1c) = DVar1;
  piVar7 = (int *)(iVar4 + 4);
  iVar4 = *piVar6;
  piVar5 = (int *)param_1[2];
  *(int **)(iVar4 + 4) = piVar5;
  *piVar5 = iVar4;
  iVar4 = *piVar7;
  *(int **)(iVar4 + 4) = piVar6;
  *piVar6 = iVar4;
  param_1[2] = (int)piVar7;
  *piVar7 = (int)piVar6;
  return;
}



/* c098fdd4 FUN_c098fdd4 */

/* Boundary evidence: original MIPS .pdata c098fdd4..c098ffb7. Semantic name remains unreviewed. */

void FUN_c098fdd4(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  char *pcVar1;
  undefined4 uVar2;
  int *piVar3;
  int *piVar4;
  int *piVar5;
  char *pcVar6;
  int iVar7;
  
  pcVar6 = "mali_core_subsystem_move_core_set_idle";
  iVar7 = *param_1;
  if (DAT_c09967a0 == 0) {
    FUN_c098b68c("Mali: ERR: %s\n","src/devicedrv/mali/common/mali_rendercore.c",param_3,param_4);
    param_3 = 0x3b5;
    pcVar1 = pcVar6;
    FUN_c098b68c("           %s()%4d\n           ","mali_core_subsystem_move_core_set_idle",0x3b5,
                 param_4);
    FUN_c098b68c("ASSERT MUTEX SHOULD BE GRABBED",pcVar1,param_3,param_4);
    FUN_c098b68c("\n",pcVar1,param_3,param_4);
  }
  if (*(int *)(iVar7 + 0xc) != -0x21524111) {
    FUN_c098b68c("Mali: ERR: %s\n","src/devicedrv/mali/common/mali_rendercore.c",param_3,param_4);
    param_3 = 0x3b5;
    pcVar1 = pcVar6;
    FUN_c098b68c("           %s()%4d\n           ","mali_core_subsystem_move_core_set_idle",0x3b5,
                 param_4);
    FUN_c098b68c("Wrong magic number",pcVar1,param_3,param_4);
    FUN_c098b68c("\n",pcVar1,param_3,param_4);
  }
  if (param_1[5] != -0x35014542) {
    FUN_c098b68c("Mali: ERR: %s\n","src/devicedrv/mali/common/mali_rendercore.c",param_3,param_4);
    param_3 = 0x3b6;
    pcVar1 = pcVar6;
    FUN_c098b68c("           %s()%4d\n           ","mali_core_subsystem_move_core_set_idle",0x3b6,
                 param_4);
    FUN_c098b68c("Wrong magic number",pcVar1,param_3,param_4);
    FUN_c098b68c("\n",pcVar1,param_3,param_4);
  }
  if (*(int *)(iVar7 + 0xc) != -0x21524111) {
    FUN_c098b68c("Mali: ERR: %s\n","src/devicedrv/mali/common/mali_rendercore.c",param_3,param_4);
    uVar2 = 0x3b7;
    FUN_c098b68c("           %s()%4d\n           ","mali_core_subsystem_move_core_set_idle",0x3b7,
                 param_4);
    FUN_c098b68c("Wrong magic number",pcVar6,uVar2,param_4);
    FUN_c098b68c("\n",pcVar6,uVar2,param_4);
  }
  timeKillEvent(*(UINT *)param_1[6]);
  timeKillEvent(*(UINT *)param_1[7]);
  piVar4 = param_1 + 1;
  piVar5 = (int *)(iVar7 + 0x10);
  param_1[4] = 0;
  param_1[3] = 0;
  iVar7 = *piVar4;
  piVar3 = (int *)param_1[2];
  *(int **)(iVar7 + 4) = piVar3;
  *piVar3 = iVar7;
  iVar7 = *piVar5;
  *(int **)(iVar7 + 4) = piVar4;
  *piVar4 = iVar7;
  param_1[2] = (int)piVar5;
  *piVar5 = (int)piVar4;
  FUN_c09856e4(param_1[0xf]);
  return;
}



/* c098ffb8 FUN_c098ffb8 */

/* Boundary evidence: original MIPS .pdata c098ffb8..c0990293. Semantic name remains unreviewed. */

void FUN_c098ffb8(int param_1,int *param_2,undefined4 param_3,undefined4 param_4)

{
  DWORD DVar1;
  MMRESULT MVar2;
  char *pcVar3;
  int *piVar4;
  int iVar5;
  MMRESULT *dwUser;
  UINT uDelay;
  char *pcVar6;
  int iVar7;
  
  iVar5 = *(int *)(param_1 + 8);
  iVar7 = *param_2;
  pcVar6 = "mali_core_job_start_on_core";
  if (param_2[5] != -0x35014542) {
    FUN_c098b68c("Mali: ERR: %s\n","src/devicedrv/mali/common/mali_rendercore.c",param_3,param_4);
    param_3 = 0x414;
    pcVar3 = pcVar6;
    FUN_c098b68c("           %s()%4d\n           ","mali_core_job_start_on_core",0x414,param_4);
    FUN_c098b68c("Wrong magic number",pcVar3,param_3,param_4);
    FUN_c098b68c("\n",pcVar3,param_3,param_4);
  }
  if (*(int *)(param_1 + 0xc) != 0x123abcd) {
    FUN_c098b68c("Mali: ERR: %s\n","src/devicedrv/mali/common/mali_rendercore.c",param_3,param_4);
    param_3 = 0x415;
    pcVar3 = pcVar6;
    FUN_c098b68c("           %s()%4d\n           ","mali_core_job_start_on_core",0x415,param_4);
    FUN_c098b68c("Wrong magic number",pcVar3,param_3,param_4);
    FUN_c098b68c("\n",pcVar3,param_3,param_4);
  }
  if (*(int *)(iVar7 + 0xc) != -0x21524111) {
    FUN_c098b68c("Mali: ERR: %s\n","src/devicedrv/mali/common/mali_rendercore.c",param_3,param_4);
    param_3 = 0x416;
    pcVar3 = pcVar6;
    FUN_c098b68c("           %s()%4d\n           ","mali_core_job_start_on_core",0x416,param_4);
    FUN_c098b68c("Wrong magic number",pcVar3,param_3,param_4);
    FUN_c098b68c("\n",pcVar3,param_3,param_4);
  }
  if (*(int *)(iVar5 + 0x28) != -0x4541edcc) {
    FUN_c098b68c("Mali: ERR: %s\n","src/devicedrv/mali/common/mali_rendercore.c",param_3,param_4);
    param_3 = 0x417;
    pcVar3 = pcVar6;
    FUN_c098b68c("           %s()%4d\n           ","mali_core_job_start_on_core",0x417,param_4);
    FUN_c098b68c("Wrong magic number",pcVar3,param_3,param_4);
    FUN_c098b68c("\n",pcVar3,param_3,param_4);
  }
  if (DAT_c09967a0 == 0) {
    FUN_c098b68c("Mali: ERR: %s\n","src/devicedrv/mali/common/mali_rendercore.c",param_3,param_4);
    param_3 = 0x418;
    pcVar3 = pcVar6;
    FUN_c098b68c("           %s()%4d\n           ","mali_core_job_start_on_core",0x418,param_4);
    FUN_c098b68c("ASSERT MUTEX SHOULD BE GRABBED",pcVar3,param_3,param_4);
    FUN_c098b68c("\n",pcVar3,param_3,param_4);
  }
  if (*(int *)(iVar7 + 0xc) != -0x21524111) {
    FUN_c098b68c("Mali: ERR: %s\n","src/devicedrv/mali/common/mali_rendercore.c",param_3,param_4);
    param_3 = 0x418;
    FUN_c098b68c("           %s()%4d\n           ","mali_core_job_start_on_core",0x418,param_4);
    FUN_c098b68c("Wrong magic number",pcVar6,param_3,param_4);
    FUN_c098b68c("\n",pcVar6,param_3,param_4);
  }
  FUN_c098fbac(param_2,param_1,param_3,param_4);
  piVar4 = param_2;
  iVar5 = (**(code **)(iVar7 + 0x48))(param_1);
  if (iVar5 == 0) {
    uDelay = *(int *)(param_1 + 0x14) + 1;
    DVar1 = GetTickCount();
    iVar5 = DAT_c0996798;
    *(DWORD *)(param_1 + 0x20) = DVar1 + uDelay;
    dwUser = (MMRESULT *)param_2[6];
    if (iVar5 == 0) {
      MVar2 = timeSetEvent(uDelay,0,FUN_c098ab84,(DWORD_PTR)dwUser,0);
    }
    else {
      MVar2 = timeSetEvent(1,0,FUN_c098ab84,(DWORD_PTR)dwUser,0);
    }
    *dwUser = MVar2;
  }
  else {
    FUN_c098fdd4(param_2,piVar4,param_3,param_4);
    (**(code **)(iVar7 + 0x5c))(param_1,0x400000);
  }
  return;
}



/* c0990294 FUN_c0990294 */

/* Boundary evidence: original MIPS .pdata c0990294..c0990417. Semantic name remains unreviewed. */

void FUN_c0990294(int param_1,char *param_2,undefined4 param_3,undefined4 param_4)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  code *pcVar5;
  int iVar6;
  int *piVar7;
  char *pcVar8;
  int *piVar9;
  
  pcVar8 = "mali_core_subsystem_schedule";
  if (DAT_c09967a0 == 0) {
    FUN_c098b68c("Mali: ERR: %s\n","src/devicedrv/mali/common/mali_rendercore.c",param_3,param_4);
    param_3 = 0x45f;
    param_2 = pcVar8;
    FUN_c098b68c("           %s()%4d\n           ","mali_core_subsystem_schedule",0x45f,param_4);
    FUN_c098b68c("ASSERT MUTEX SHOULD BE GRABBED",param_2,param_3,param_4);
    FUN_c098b68c("\n",param_2,param_3,param_4);
  }
  if (*(int *)(param_1 + 0xc) != -0x21524111) {
    FUN_c098b68c("Mali: ERR: %s\n","src/devicedrv/mali/common/mali_rendercore.c",param_3,param_4);
    param_3 = 0x45f;
    FUN_c098b68c("           %s()%4d\n           ","mali_core_subsystem_schedule",0x45f,param_4);
    FUN_c098b68c("Wrong magic number",pcVar8,param_3,param_4);
    FUN_c098b68c("\n",pcVar8,param_3,param_4);
    param_2 = pcVar8;
  }
  if ((*(int *)(param_1 + 0x30) != 0) &&
     (iVar3 = FUN_c098dd88(param_1,param_2,param_3,param_4), iVar3 != 0)) {
    piVar9 = (int *)(param_1 + 0x10);
    piVar7 = (int *)*piVar9;
    if (piVar7 != piVar9) {
      piVar2 = (int *)*piVar7;
      do {
        piVar1 = piVar2;
        pcVar5 = FUN_c098d09c;
        iVar6 = param_1;
        iVar4 = FUN_c09858e0(piVar7[0xe],*(int *)(iVar3 + 0x24),FUN_c098d09c,param_1);
        if (iVar4 == 0) {
          iVar3 = FUN_c098f4c0(param_1,iVar3,pcVar5,iVar6);
          FUN_c098ffb8(iVar3,piVar7 + -1,pcVar5,iVar6);
          return;
        }
        piVar2 = (int *)*piVar1;
        piVar7 = piVar1;
      } while (piVar1 != piVar9);
    }
  }
  return;
}



/* c0990418 FUN_c0990418 */

/* Boundary evidence: original MIPS .pdata c0990418..c09905d7. Semantic name remains unreviewed. */

void FUN_c0990418(int param_1,char *param_2,undefined4 param_3,undefined4 param_4)

{
  bool bVar1;
  IMAGE_DOS_HEADER *pIVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  char *pcVar6;
  
  pcVar6 = "continue_job_handling";
  if (DAT_c09967a0 == 0) {
    FUN_c098b68c("Mali: ERR: %s\n","src/devicedrv/mali/common/mali_rendercore.c",param_3,param_4);
    param_3 = 0x593;
    param_2 = pcVar6;
    FUN_c098b68c("           %s()%4d\n           ","continue_job_handling",0x593,param_4);
    FUN_c098b68c("ASSERT MUTEX SHOULD BE GRABBED",param_2,param_3,param_4);
    FUN_c098b68c("\n",param_2,param_3,param_4);
  }
  if (*(int *)(param_1 + 0xc) != -0x21524111) {
    FUN_c098b68c("Mali: ERR: %s\n","src/devicedrv/mali/common/mali_rendercore.c",param_3,param_4);
    param_3 = 0x593;
    param_2 = pcVar6;
    FUN_c098b68c("           %s()%4d\n           ","continue_job_handling",0x593,param_4);
    FUN_c098b68c("Wrong magic number",param_2,param_3,param_4);
    FUN_c098b68c("\n",param_2,param_3,param_4);
  }
  iVar4 = *(int *)(param_1 + 4);
  iVar5 = *(int *)(param_1 + 0x30);
  while (iVar4 != 0) {
    iVar4 = iVar4 + -1;
    bVar1 = iVar5 == 0;
    iVar5 = iVar5 + -1;
    if (bVar1) break;
    FUN_c0990294(param_1,param_2,param_3,param_4);
  }
  if (DAT_c09967a0 == 0) {
    FUN_c098b68c("Mali: ERR: %s\n","src/devicedrv/mali/common/mali_rendercore.c",param_3,param_4);
    param_3 = 0x59e;
    FUN_c098b68c("           %s()%4d\n           ","continue_job_handling",0x59e,param_4);
    pIVar2 = &IMAGE_DOS_HEADER_c0980000;
    FUN_c098b68c("ASSERT MUTEX SHOULD BE GRABBED",&IMAGE_DOS_HEADER_c0980000,param_3,param_4);
    FUN_c098b68c("\n",pIVar2,param_3,param_4);
  }
  if (*(int *)(param_1 + 0xc) != -0x21524111) {
    FUN_c098b68c("Mali: ERR: %s\n","src/devicedrv/mali/common/mali_rendercore.c",param_3,param_4);
    uVar3 = 0x59e;
    FUN_c098b68c("           %s()%4d\n           ","continue_job_handling",0x59e,param_4);
    FUN_c098b68c("Wrong magic number",pcVar6,uVar3,param_4);
    FUN_c098b68c("\n",pcVar6,uVar3,param_4);
  }
  return;
}



/* c09905d8 FUN_c09905d8 */

/* Boundary evidence: original MIPS .pdata c09905d8..c0990687. Semantic name remains unreviewed. */

void FUN_c09905d8(int *param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  char *pcVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar4 = param_1[4];
  iVar5 = *param_1;
  uVar2 = param_3;
  if (iVar4 != 0) {
    FUN_c098cfc0(iVar4,param_2,param_3,param_4);
    param_1[4] = 0;
  }
  pcVar1 = (char *)0x0;
  (**(code **)(iVar5 + 100))(param_1);
  iVar3 = param_1[3];
  if (iVar3 != 0) {
    FUN_c098fdd4(param_1,pcVar1,uVar2,iVar3);
  }
  if (param_2 == 0) {
    FUN_c0990294(iVar5,pcVar1,uVar2,iVar3);
  }
  if (iVar4 != 0) {
    (**(code **)(*param_1 + 0x5c))(iVar4,param_3);
  }
  return;
}



/* c0990688 FUN_c0990688 */

/* Boundary evidence: original MIPS .pdata c0990688..c09908ef. Semantic name remains unreviewed. */

undefined4 FUN_c0990688(int *param_1,char *param_2,int *param_3,undefined4 param_4)

{
  char *pcVar1;
  int *piVar2;
  undefined4 uVar3;
  int iVar4;
  int *piVar5;
  undefined4 *puVar6;
  int iVar7;
  char *pcVar8;
  
  builtin_strncpy(param_2 + 0xc,"ͫ#\x01",4);
  pcVar8 = "mali_core_session_add_job";
  pcVar1 = param_2;
  piVar2 = param_3;
  if (param_1[10] != -0x4541edcc) {
    FUN_c098b68c("Mali: ERR: %s\n","src/devicedrv/mali/common/mali_rendercore.c",param_3,param_4);
    piVar2 = (int *)0x4de;
    pcVar1 = pcVar8;
    FUN_c098b68c("           %s()%4d\n           ","mali_core_session_add_job",0x4de,param_4);
    FUN_c098b68c("Wrong magic number",pcVar1,piVar2,param_4);
    FUN_c098b68c("\n",pcVar1,piVar2,param_4);
  }
  iVar7 = *param_1;
  if (*(int *)(iVar7 + 0xc) != -0x21524111) {
    FUN_c098b68c("Mali: ERR: %s\n","src/devicedrv/mali/common/mali_rendercore.c",piVar2,param_4);
    piVar2 = (int *)0x4e1;
    pcVar1 = pcVar8;
    FUN_c098b68c("           %s()%4d\n           ","mali_core_session_add_job",0x4e1,param_4);
    FUN_c098b68c("Wrong magic number",pcVar1,piVar2,param_4);
    FUN_c098b68c("\n",pcVar1,piVar2,param_4);
  }
  if (DAT_c09967a0 == 0) {
    FUN_c098b68c("Mali: ERR: %s\n","src/devicedrv/mali/common/mali_rendercore.c",piVar2,param_4);
    piVar2 = (int *)0x4e2;
    pcVar1 = pcVar8;
    FUN_c098b68c("           %s()%4d\n           ","mali_core_session_add_job",0x4e2,param_4);
    FUN_c098b68c("ASSERT MUTEX SHOULD BE GRABBED",pcVar1,piVar2,param_4);
    FUN_c098b68c("\n",pcVar1,piVar2,param_4);
  }
  if (*(int *)(iVar7 + 0xc) != -0x21524111) {
    FUN_c098b68c("Mali: ERR: %s\n","src/devicedrv/mali/common/mali_rendercore.c",piVar2,param_4);
    piVar2 = (int *)0x4e2;
    pcVar1 = pcVar8;
    FUN_c098b68c("           %s()%4d\n           ","mali_core_session_add_job",0x4e2,param_4);
    FUN_c098b68c("Wrong magic number",pcVar1,piVar2,param_4);
    FUN_c098b68c("\n",pcVar1,piVar2,param_4);
  }
  iVar4 = param_1[3];
  *param_3 = 0;
  if (iVar4 != 0) {
    if (*(uint *)(iVar4 + 0x10) <= *(uint *)(param_2 + 0x10)) {
      FUN_c098b68c("Mali: ERR: %s\n","src/devicedrv/mali/common/mali_rendercore.c",piVar2,param_4);
      uVar3 = 0x4f7;
      FUN_c098b68c("           %s()%4d\n           ","mali_core_session_add_job",0x4f7,param_4);
      FUN_c098b68c("Illegal internal state.",pcVar8,uVar3,param_4);
      FUN_c098b68c("\n",pcVar8,uVar3,param_4);
      return 0xffffffff;
    }
    piVar5 = (int *)param_1[5];
    iVar4 = param_1[4];
    *(int **)(iVar4 + 4) = piVar5;
    *piVar5 = iVar4;
    *(int *)(iVar7 + 0x30) = *(int *)(iVar7 + 0x30) + -1;
    *param_3 = param_1[3];
  }
  param_1[3] = (int)param_2;
  piVar5 = param_1 + 4;
  iVar4 = (*(int *)(param_2 + 0x10) + 3) * 8 + iVar7;
  puVar6 = *(undefined4 **)(iVar4 + 4);
  *(int **)(iVar4 + 4) = piVar5;
  *piVar5 = iVar4;
  param_1[5] = (int)puVar6;
  *puVar6 = piVar5;
  *(int *)(iVar7 + 0x30) = *(int *)(iVar7 + 0x30) + 1;
  FUN_c0990294(iVar7,pcVar1,piVar2,param_4);
  return 0;
}



/* c09908f0 FUN_c09908f0 */

/* Boundary evidence: original MIPS .pdata c09908f0..c0990b7b. Semantic name remains unreviewed. */

void FUN_c09908f0(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  DWORD DVar1;
  char *pcVar2;
  undefined4 uVar3;
  int *piVar4;
  int *piVar5;
  int iVar6;
  int *piVar7;
  int iVar8;
  char *pcVar9;
  
  piVar4 = DAT_c099679c;
  iVar8 = *param_1;
  if (((-1 < *DAT_c099679c) && (*DAT_c099679c < 4)) &&
     (DVar1 = WaitForSingleObject((HANDLE)DAT_c099679c[1],0xffffffff), DVar1 == 0)) {
    if (piVar4[2] == 1) {
      ReleaseMutex((HANDLE)piVar4[1]);
    }
    else {
      piVar4[2] = 1;
      iVar6 = __GetUserKData(8);
      piVar4[3] = iVar6;
    }
  }
  pcVar9 = "mali_core_session_close";
  if (*(int *)(iVar8 + 0xc) != -0x21524111) {
    FUN_c098b68c("Mali: ERR: %s\n","src/devicedrv/mali/common/mali_rendercore.c",param_3,param_4);
    param_3 = 0x4bb;
    pcVar2 = pcVar9;
    FUN_c098b68c("           %s()%4d\n           ","mali_core_session_close",0x4bb,param_4);
    FUN_c098b68c("Wrong magic number",pcVar2,param_3,param_4);
    FUN_c098b68c("\n",pcVar2,param_3,param_4);
  }
  DAT_c09967a0 = 1;
  piVar4 = DAT_c099679c;
  if (param_1[3] != 0) {
    (**(code **)(iVar8 + 0x5c))(param_1[3],0x1000000);
    piVar5 = param_1 + 4;
    param_1[3] = 0;
    iVar6 = *piVar5;
    piVar4 = (int *)param_1[5];
    *(int **)(iVar6 + 4) = piVar4;
    *piVar4 = iVar6;
    *piVar5 = (int)piVar5;
    param_1[5] = (int)piVar5;
    piVar4 = DAT_c099679c;
    *(int *)(iVar8 + 0x30) = *(int *)(iVar8 + 0x30) + -1;
  }
  piVar5 = param_1 + 1;
  if ((int *)*piVar5 != piVar5) {
    param_3 = 0x1000000;
    FUN_c09905d8((int *)*piVar5 + -1,0,0x1000000,param_4);
    piVar4 = DAT_c099679c;
  }
  piVar7 = param_1 + 6;
  *piVar5 = (int)piVar5;
  param_1[2] = (int)piVar5;
  iVar6 = *piVar7;
  piVar5 = (int *)param_1[7];
  *(int **)(iVar6 + 4) = piVar5;
  *piVar5 = iVar6;
  *piVar7 = (int)piVar7;
  param_1[7] = (int)piVar7;
  DAT_c09967a0 = 0;
  if (*(int *)(iVar8 + 0xc) != -0x21524111) {
    FUN_c098b68c("Mali: ERR: %s\n","src/devicedrv/mali/common/mali_rendercore.c",param_3,param_4);
    uVar3 = 0x4d5;
    pcVar2 = pcVar9;
    FUN_c098b68c("           %s()%4d\n           ","mali_core_session_close",0x4d5,param_4);
    FUN_c098b68c("Wrong magic number",pcVar2,uVar3,param_4);
    FUN_c098b68c("\n",pcVar2,uVar3,param_4);
    piVar4 = DAT_c099679c;
  }
  FUN_c098bdc8(piVar4);
  if (*(int *)(iVar8 + 0xc) != -0x21524111) {
    FUN_c098b68c("Mali: ERR: %s\n","src/devicedrv/mali/common/mali_rendercore.c",
                 *(int *)(iVar8 + 0xc),param_4);
    uVar3 = 0x4d5;
    FUN_c098b68c("           %s()%4d\n           ","mali_core_session_close",0x4d5,param_4);
    FUN_c098b68c("Wrong magic number",pcVar9,uVar3,param_4);
    FUN_c098b68c("\n",pcVar9,uVar3,param_4);
  }
  return;
}



/* c0990b7c FUN_c0990b7c */

/* Boundary evidence: original MIPS .pdata c0990b7c..c0990f43. Semantic name remains unreviewed. */

void FUN_c0990b7c(int *param_1,char *param_2,undefined4 param_3,undefined4 param_4)

{
  int *piVar1;
  DWORD DVar2;
  char *pcVar3;
  undefined4 uVar4;
  int *piVar5;
  int iVar6;
  int *piVar7;
  int iVar8;
  int iVar9;
  char *pcVar10;
  
  piVar5 = DAT_c099679c;
  iVar9 = *param_1;
  pcVar3 = param_2;
  if ((-1 < *DAT_c099679c) && (*DAT_c099679c < 4)) {
    pcVar3 = (char *)0xffffffff;
    DVar2 = WaitForSingleObject((HANDLE)DAT_c099679c[1],0xffffffff);
    if (DVar2 == 0) {
      if (piVar5[2] == 1) {
        ReleaseMutex((HANDLE)piVar5[1]);
      }
      else {
        piVar5[2] = 1;
        iVar6 = __GetUserKData(8);
        piVar5[3] = iVar6;
      }
    }
  }
  pcVar10 = "find_and_abort";
  if (*(int *)(iVar9 + 0xc) != -0x21524111) {
    FUN_c098b68c("Mali: ERR: %s\n","src/devicedrv/mali/common/mali_rendercore.c",param_3,param_4);
    param_3 = 0x34f;
    pcVar3 = pcVar10;
    FUN_c098b68c("           %s()%4d\n           ","find_and_abort",0x34f,param_4);
    FUN_c098b68c("Wrong magic number",pcVar3,param_3,param_4);
    FUN_c098b68c("\n",pcVar3,param_3,param_4);
  }
  DAT_c09967a0 = 1;
  if ((param_1[3] != 0) && (*(char **)(param_1[3] + 0x24) == param_2)) {
    piVar7 = param_1 + 4;
    param_1[3] = 0;
    iVar6 = *piVar7;
    pcVar3 = (char *)0x40000;
    piVar5 = (int *)param_1[5];
    *(int **)(iVar6 + 4) = piVar5;
    *piVar5 = iVar6;
    *piVar7 = (int)piVar7;
    param_1[5] = (int)piVar7;
    *(int *)(iVar9 + 0x30) = *(int *)(iVar9 + 0x30) + -1;
    (**(code **)(iVar9 + 0x5c))();
  }
  piVar5 = (int *)param_1[1];
  piVar7 = (int *)*piVar5;
  do {
    piVar1 = piVar7;
    if (piVar5 == param_1 + 1) {
LAB_c0990e24:
      DAT_c09967a0 = 0;
      if (*(int *)(iVar9 + 0xc) != -0x21524111) {
        FUN_c098b68c("Mali: ERR: %s\n","src/devicedrv/mali/common/mali_rendercore.c",param_3,param_4
                    );
        param_3 = 0x36d;
        pcVar3 = pcVar10;
        FUN_c098b68c("           %s()%4d\n           ","find_and_abort",0x36d,param_4);
        FUN_c098b68c("Wrong magic number",pcVar3,param_3,param_4);
        FUN_c098b68c("\n",pcVar3,param_3,param_4);
      }
      piVar5 = DAT_c099679c;
      if ((((-1 < *DAT_c099679c) && (*DAT_c099679c < 4)) && (DAT_c099679c[2] == 1)) &&
         (iVar6 = __GetUserKData(8), piVar5[3] == iVar6)) {
        piVar5[2] = 0;
        piVar5[3] = 0;
        ReleaseMutex((HANDLE)piVar5[1]);
      }
      if (*(int *)(iVar9 + 0xc) != -0x21524111) {
        FUN_c098b68c("Mali: ERR: %s\n","src/devicedrv/mali/common/mali_rendercore.c",param_3,param_4
                    );
        uVar4 = 0x36d;
        FUN_c098b68c("           %s()%4d\n           ","find_and_abort",0x36d,param_4);
        FUN_c098b68c("Wrong magic number",pcVar10,uVar4,param_4);
        FUN_c098b68c("\n",pcVar10,uVar4,param_4);
      }
      return;
    }
    piVar7 = piVar5 + -1;
    iVar6 = piVar5[3];
    if ((iVar6 != 0) && (*(char **)(iVar6 + 0x24) == param_2)) {
      if (piVar5[2] == 0) {
        FUN_c098b68c("Mali: ERR: %s\n","src/devicedrv/mali/common/mali_rendercore.c",param_3,param_4
                    );
        param_3 = 0x365;
        pcVar3 = pcVar10;
        FUN_c098b68c("           %s()%4d\n           ","find_and_abort",0x365,param_4);
        FUN_c098b68c("Aborting core with running job which is idle. Must be something wery wrong.",
                     pcVar3,param_3,param_4);
        FUN_c098b68c("\n",pcVar3,param_3,param_4);
        goto LAB_c0990e24;
      }
      iVar8 = *piVar7;
      if (iVar6 != 0) {
        FUN_c098cfc0(iVar6,pcVar3,param_3,param_4);
        piVar5[3] = 0;
      }
      (**(code **)(iVar8 + 100))(piVar7,0);
      pcVar3 = (char *)piVar5[2];
      if (pcVar3 != (char *)0x0) {
        FUN_c098fdd4(piVar7,pcVar3,param_3,param_4);
      }
      FUN_c0990294(iVar8,pcVar3,param_3,param_4);
      if (iVar6 != 0) {
        pcVar3 = (char *)0x40000;
        (**(code **)(*piVar7 + 0x5c))(iVar6);
      }
    }
    piVar7 = (int *)*piVar1;
    piVar5 = piVar1;
  } while( true );
}



/* c0990f44 FUN_c0990f44 */

/* Boundary evidence: original MIPS .pdata c0990f44..c0990f5f. Semantic name remains unreviewed. */

void FUN_c0990f44(int *param_1,char *param_2,undefined4 param_3,undefined4 param_4)

{
  FUN_c0990b7c(param_1,param_2,param_3,param_4);
  return;
}



/* c0990f60 FUN_c0990f60 */

/* Boundary evidence: original MIPS .pdata c0990f60..c09914bf. Semantic name remains unreviewed. */

void FUN_c0990f60(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int *piVar1;
  DWORD DVar2;
  int iVar3;
  char *pcVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  
  if (param_1[5] != -0x35014542) {
    FUN_c098b68c("Mali: ERR: %s\n","src/devicedrv/mali/common/mali_rendercore.c",param_3,param_4);
    param_3 = 0x5fb;
    pcVar4 = "mali_core_irq_handler_bottom_half";
    FUN_c098b68c("           %s()%4d\n           ","mali_core_irq_handler_bottom_half",0x5fb,param_4
                );
    FUN_c098b68c("Wrong magic number",pcVar4,param_3,param_4);
    FUN_c098b68c("\n",pcVar4,param_3,param_4);
  }
  iVar6 = *param_1;
  if (*(int *)(iVar6 + 0xc) != -0x21524111) {
    FUN_c098b68c("Mali: ERR: %s\n","src/devicedrv/mali/common/mali_rendercore.c",param_3,param_4);
    param_3 = 0x5fd;
    pcVar4 = "mali_core_irq_handler_bottom_half";
    FUN_c098b68c("           %s()%4d\n           ","mali_core_irq_handler_bottom_half",0x5fd,param_4
                );
    FUN_c098b68c("Wrong magic number",pcVar4,param_3,param_4);
    FUN_c098b68c("\n",pcVar4,param_3,param_4);
  }
  piVar1 = DAT_c099679c;
  if (((-1 < *DAT_c099679c) && (*DAT_c099679c < 4)) &&
     (DVar2 = WaitForSingleObject((HANDLE)DAT_c099679c[1],0xffffffff), DVar2 == 0)) {
    if (piVar1[2] == 1) {
      ReleaseMutex((HANDLE)piVar1[1]);
    }
    else {
      piVar1[2] = 1;
      iVar3 = __GetUserKData(8);
      piVar1[3] = iVar3;
    }
  }
  if (*(int *)(iVar6 + 0xc) != -0x21524111) {
    FUN_c098b68c("Mali: ERR: %s\n","src/devicedrv/mali/common/mali_rendercore.c",param_3,param_4);
    param_3 = 0x5ff;
    pcVar4 = "mali_core_irq_handler_bottom_half";
    FUN_c098b68c("           %s()%4d\n           ","mali_core_irq_handler_bottom_half",0x5ff,param_4
                );
    FUN_c098b68c("Wrong magic number",pcVar4,param_3,param_4);
    FUN_c098b68c("\n",pcVar4,param_3,param_4);
  }
  DAT_c09967a0 = 1;
  if (param_1[3] != 0) {
    param_3 = 0x24;
    uVar5 = 0;
    CacheRangeFlush(0);
    SYNC(0);
    iVar3 = (**(code **)(iVar6 + 0x50))(param_1);
    if (iVar3 == 1) {
      if (param_1[3] == 2) {
        param_3 = 0x80000;
        FUN_c09905d8(param_1,0,0x80000,param_4);
      }
      else if (param_1[3] == 3) {
        param_1[3] = 1;
        FUN_c098ac24((MMRESULT *)param_1[6],1);
      }
    }
    else {
      iVar7 = param_1[4];
      iVar8 = *param_1;
      if (iVar7 != 0) {
        FUN_c098cfc0(iVar7,uVar5,param_3,param_4);
        param_1[4] = 0;
      }
      pcVar4 = (char *)0x0;
      (**(code **)(iVar8 + 100))(param_1);
      if (param_1[3] != 0) {
        FUN_c098fdd4(param_1,pcVar4,param_3,param_4);
      }
      FUN_c0990294(iVar8,pcVar4,param_3,param_4);
      if (iVar7 != 0) {
        (**(code **)(*param_1 + 0x5c))(iVar7,iVar3);
      }
    }
  }
  DAT_c09967a0 = 0;
  if (*(int *)(iVar6 + 0xc) != -0x21524111) {
    FUN_c098b68c("Mali: ERR: %s\n","src/devicedrv/mali/common/mali_rendercore.c",param_3,param_4);
    param_3 = 0x61e;
    pcVar4 = "mali_core_irq_handler_bottom_half";
    FUN_c098b68c("           %s()%4d\n           ","mali_core_irq_handler_bottom_half",0x61e,param_4
                );
    FUN_c098b68c("Wrong magic number",pcVar4,param_3,param_4);
    FUN_c098b68c("\n",pcVar4,param_3,param_4);
  }
  piVar1 = DAT_c099679c;
  if (((-1 < *DAT_c099679c) && (*DAT_c099679c < 4)) &&
     ((DAT_c099679c[2] == 1 && (iVar3 = __GetUserKData(8), piVar1[3] == iVar3)))) {
    piVar1[2] = 0;
    piVar1[3] = 0;
    ReleaseMutex((HANDLE)piVar1[1]);
  }
  if (*(int *)(iVar6 + 0xc) != -0x21524111) {
    FUN_c098b68c("Mali: ERR: %s\n","src/devicedrv/mali/common/mali_rendercore.c",param_3,param_4);
    uVar5 = 0x61e;
    pcVar4 = "mali_core_irq_handler_bottom_half";
    FUN_c098b68c("           %s()%4d\n           ","mali_core_irq_handler_bottom_half",0x61e,param_4
                );
    FUN_c098b68c("Wrong magic number",pcVar4,uVar5,param_4);
    FUN_c098b68c("\n",pcVar4,uVar5,param_4);
  }
  return;
}



/* c09914c0 FUN_c09914c0 */

/* Boundary evidence: original MIPS .pdata c09914c0..c0991723. Semantic name remains unreviewed. */

void FUN_c09914c0(int *param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int *piVar1;
  char *pcVar2;
  uint uVar3;
  IMAGE_DOS_HEADER *pIVar4;
  undefined4 uVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  char *pcVar9;
  
  pcVar9 = "reset_all_cores_on_mmu";
  if (DAT_c09967a0 == 0) {
    FUN_c098b68c("Mali: ERR: %s\n","src/devicedrv/mali/common/mali_rendercore.c",param_3,param_4);
    param_3 = 0x573;
    pcVar2 = pcVar9;
    FUN_c098b68c("           %s()%4d\n           ","reset_all_cores_on_mmu",0x573,param_4);
    FUN_c098b68c("ASSERT MUTEX SHOULD BE GRABBED",pcVar2,param_3,param_4);
    FUN_c098b68c("\n",pcVar2,param_3,param_4);
  }
  if (param_1[3] != -0x21524111) {
    FUN_c098b68c("Mali: ERR: %s\n","src/devicedrv/mali/common/mali_rendercore.c",param_3,param_4);
    param_3 = 0x573;
    pcVar2 = pcVar9;
    FUN_c098b68c("           %s()%4d\n           ","reset_all_cores_on_mmu",0x573,param_4);
    FUN_c098b68c("Wrong magic number",pcVar2,param_3,param_4);
    FUN_c098b68c("\n",pcVar2,param_3,param_4);
  }
  uVar7 = 0;
  if (param_1[1] != 0) {
    do {
      uVar3 = uVar7;
      piVar1 = (int *)FUN_c098d0e4(param_1,uVar7,param_3,param_4);
      if (((param_2 == 0) || (piVar1[0xf] == param_2)) && (piVar1[3] != 0)) {
        iVar6 = piVar1[4];
        iVar8 = *piVar1;
        if (iVar6 != 0) {
          FUN_c098cfc0(iVar6,uVar3,param_3,param_4);
          piVar1[4] = 0;
        }
        (**(code **)(iVar8 + 100))(piVar1,0);
        if (piVar1[3] != 0) {
          FUN_c098fdd4(piVar1,piVar1[3],param_3,param_4);
        }
        if (iVar6 != 0) {
          (**(code **)(*piVar1 + 0x5c))(iVar6,0x200000);
        }
      }
      uVar7 = uVar7 + 1;
    } while (uVar7 < (uint)param_1[1]);
  }
  if (DAT_c09967a0 == 0) {
    FUN_c098b68c("Mali: ERR: %s\n","src/devicedrv/mali/common/mali_rendercore.c",param_3,param_4);
    param_3 = 0x588;
    FUN_c098b68c("           %s()%4d\n           ","reset_all_cores_on_mmu",0x588,param_4);
    pIVar4 = &IMAGE_DOS_HEADER_c0980000;
    FUN_c098b68c("ASSERT MUTEX SHOULD BE GRABBED",&IMAGE_DOS_HEADER_c0980000,param_3,param_4);
    FUN_c098b68c("\n",pIVar4,param_3,param_4);
  }
  if (param_1[3] != -0x21524111) {
    FUN_c098b68c("Mali: ERR: %s\n","src/devicedrv/mali/common/mali_rendercore.c",param_3,param_4);
    uVar5 = 0x588;
    FUN_c098b68c("           %s()%4d\n           ","reset_all_cores_on_mmu",0x588,param_4);
    FUN_c098b68c("Wrong magic number",pcVar9,uVar5,param_4);
    FUN_c098b68c("\n",pcVar9,uVar5,param_4);
  }
  return;
}



/* c0991724 FUN_c0991724 */

/* Boundary evidence: original MIPS .pdata c0991724..c0991b2b. Semantic name remains unreviewed. */

undefined4 FUN_c0991724(int *param_1,int *param_2,undefined *param_3,int *param_4)

{
  undefined4 *puVar1;
  void *_Dst;
  char *pcVar2;
  code *pcVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int *piVar8;
  int *piVar9;
  char *pcVar10;
  undefined4 uVar11;
  
  uVar11 = 0xffffffff;
  if ((((*param_2 == 0) || (param_2[9] == 0)) || (param_2[10] == 0)) || (param_2[0xb] == 0)) {
    FUN_c098b68c("Mali: ERR: %s\n","src/devicedrv/mali/common/mali_rendercore.c",param_3,param_4);
    FUN_c098b68c("           %s()%4d\n           ","mali_core_subsystem_register_renderunit",0x23e,
                 param_4);
    iVar5 = param_2[0xb];
    iVar7 = param_2[10];
    iVar6 = param_2[9];
    FUN_c098b68c("Missing fields in the core structure 0x%x 0x%x 0x%x;\n",iVar6,iVar7,iVar5);
    FUN_c098b68c("\n",iVar6,iVar7,iVar5);
    return 0xfffffffd;
  }
  if (param_2[0xc] == -1) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    pcVar3 = FUN_c0990f60;
    param_4 = param_2;
    puVar1 = FUN_c098c21c(param_2[0xc],FUN_c098cd9c,FUN_c0990f60,param_2);
    param_3 = pcVar3;
  }
  param_2[0x10] = (int)puVar1;
  if (puVar1 == (undefined4 *)0x0) {
    return 0xffffffff;
  }
  FUN_c098be3c(DAT_c099679c);
  pcVar10 = "mali_core_subsystem_register_renderunit";
  if (param_1[3] != -0x21524111) {
    FUN_c098b68c("Mali: ERR: %s\n","src/devicedrv/mali/common/mali_rendercore.c",param_3,param_4);
    param_3 = (code *)0x251;
    pcVar2 = pcVar10;
    FUN_c098b68c("           %s()%4d\n           ","mali_core_subsystem_register_renderunit",0x251,
                 param_4);
    FUN_c098b68c("Wrong magic number",pcVar2,param_3,param_4);
    FUN_c098b68c("\n",pcVar2,param_3,param_4);
  }
  DAT_c09967a0 = 1;
  iVar6 = param_1[1];
  if (iVar6 == 0) {
    _Dst = malloc(4);
    if (_Dst != (void *)0x0) {
LAB_c09918ec:
      *param_1 = (int)_Dst;
      piVar9 = param_1 + 4;
      *(int **)(iVar6 * 4 + (int)_Dst) = param_2;
      iVar7 = *piVar9;
      piVar8 = param_2 + 1;
      *(int **)(iVar7 + 4) = piVar8;
      *piVar8 = iVar7;
      param_2[2] = (int)piVar9;
      *piVar9 = (int)piVar8;
      param_1[1] = iVar6 + 1;
      DAT_c09967a0 = 0;
      if (param_1[3] != -0x21524111) {
        FUN_c098b68c("Mali: ERR: %s\n","src/devicedrv/mali/common/mali_rendercore.c",param_3,param_4
                    );
        param_3 = (code *)0x280;
        pcVar2 = pcVar10;
        FUN_c098b68c("           %s()%4d\n           ","mali_core_subsystem_register_renderunit",
                     0x280,param_4);
        FUN_c098b68c("Wrong magic number",pcVar2,param_3,param_4);
        FUN_c098b68c("\n",pcVar2,param_3,param_4);
      }
      FUN_c098bdc8(DAT_c099679c);
      if (param_1[3] != -0x21524111) {
        FUN_c098b68c("Mali: ERR: %s\n","src/devicedrv/mali/common/mali_rendercore.c",param_3,param_4
                    );
        uVar11 = 0x280;
        FUN_c098b68c("           %s()%4d\n           ","mali_core_subsystem_register_renderunit",
                     0x280,param_4);
        FUN_c098b68c("Wrong magic number",pcVar10,uVar11,param_4);
        FUN_c098b68c("\n",pcVar10,uVar11,param_4);
      }
      return 0;
    }
    FUN_c098b68c("Mali: ERR: %s\n","src/devicedrv/mali/common/mali_rendercore.c",param_3,param_4);
    uVar11 = 0x271;
  }
  else {
    if (*param_1 == 0) {
      FUN_c098b68c("Mali: ERR: %s\n","src/devicedrv/mali/common/mali_rendercore.c",param_3,param_4);
      uVar4 = 0x25d;
      pcVar2 = pcVar10;
      FUN_c098b68c("           %s()%4d\n           ","mali_core_subsystem_register_renderunit",0x25d
                   ,param_4);
      FUN_c098b68c("Internal error",pcVar2,uVar4,param_4);
      FUN_c098b68c("\n",pcVar2,uVar4,param_4);
      goto LAB_c0991a08;
    }
    _Dst = malloc((iVar6 + 1) * 4);
    if (_Dst != (void *)0x0) {
      param_3 = (undefined *)(iVar6 << 2);
      memcpy(_Dst,(void *)*param_1,(size_t)param_3);
      free((void *)*param_1);
      goto LAB_c09918ec;
    }
    FUN_c098b68c("Mali: ERR: %s\n","src/devicedrv/mali/common/mali_rendercore.c",param_3,param_4);
    uVar11 = 0x264;
  }
  pcVar2 = pcVar10;
  FUN_c098b68c("           %s()%4d\n           ","mali_core_subsystem_register_renderunit",uVar11,
               param_4);
  FUN_c098b68c("Out of mem",pcVar2,uVar11,param_4);
  FUN_c098b68c("\n",pcVar2,uVar11,param_4);
  uVar11 = 0xfffffffc;
LAB_c0991a08:
  FUN_c098c058((void *)param_2[0x10]);
  DAT_c09967a0 = 0;
  if (param_1[3] != -0x21524111) {
    FUN_c098b68c("Mali: ERR: %s\n","src/devicedrv/mali/common/mali_rendercore.c",0,param_4);
    uVar4 = 0x285;
    pcVar2 = pcVar10;
    FUN_c098b68c("           %s()%4d\n           ","mali_core_subsystem_register_renderunit",0x285,
                 param_4);
    FUN_c098b68c("Wrong magic number",pcVar2,uVar4,param_4);
    FUN_c098b68c("\n",pcVar2,uVar4,param_4);
  }
  FUN_c098bdc8(DAT_c099679c);
  if (param_1[3] != -0x21524111) {
    FUN_c098b68c("Mali: ERR: %s\n","src/devicedrv/mali/common/mali_rendercore.c",param_1[3],param_4)
    ;
    uVar4 = 0x285;
    FUN_c098b68c("           %s()%4d\n           ","mali_core_subsystem_register_renderunit",0x285,
                 param_4);
    FUN_c098b68c("Wrong magic number",pcVar10,uVar4,param_4);
    FUN_c098b68c("\n",pcVar10,uVar4,param_4);
  }
  return uVar11;
}



/* c0991b2c FUN_c0991b2c */

/* Boundary evidence: original MIPS .pdata c0991b2c..c0991c2b. Semantic name remains unreviewed. */

void FUN_c0991b2c(int *param_1,char *param_2,int param_3,undefined4 param_4)

{
  switch(param_2) {
  case (char *)0x0:
  case (char *)0x4:
    break;
  case (char *)0x1:
    FUN_c098da14(param_1,param_3,param_3,param_4);
    return;
  case (char *)0x2:
    FUN_c09914c0(param_1,param_3,param_3,param_4);
    return;
  case (char *)0x3:
    FUN_c0990418((int)param_1,param_2,param_3,param_4);
    return;
  default:
    FUN_c098b68c("Mali: ERR: %s\n","src/devicedrv/mali/common/mali_rendercore.c",param_3,param_4);
    FUN_c098b68c("           %s()%4d\n           ","mali_core_subsystem_broadcast_notification",
                 0x5be,param_4);
    FUN_c098b68c("Illegal message: 0x%x, data: 0x%x\n",param_2,param_3,param_4);
    FUN_c098b68c("\n",param_2,param_3,param_4);
  }
  return;
}



/* c0991c3c FUN_c0991c3c */

/* Boundary evidence: original MIPS .pdata c0991c3c..c0991cfb. Semantic name remains unreviewed. */

undefined4 FUN_c0991c3c(void)

{
  int iVar1;
  undefined1 auStack_20 [8];
  undefined4 local_18;
  undefined4 local_14;
  
  NKDbgPrintfW(L"+MAL_PowerDown\r\n");
  local_18 = 3;
  local_14 = 0;
  iVar1 = KernelIoControl(0x1032c9f,&local_18,0x10,0,0,auStack_20);
  if (iVar1 == 0) {
    NKDbgPrintfW(L"PowerDown: IOCTL_HAL_VSS OiControl failed for MGP\r\n");
  }
  local_18 = 2;
  local_14 = 0;
  iVar1 = KernelIoControl(0x1032c9f,&local_18,0x10,0,0,auStack_20);
  if (iVar1 == 0) {
    NKDbgPrintfW(L"PowerDown: IOCTL_HAL_VSS OiControl failed for GPU\r\n");
  }
  NKDbgPrintfW(L"-MAL_PowerDown\r\n");
  return 0;
}



/* c0991cfc FUN_c0991cfc */

/* Boundary evidence: original MIPS .pdata c0991cfc..c0991dc7. Semantic name remains unreviewed. */

undefined4 FUN_c0991cfc(void)

{
  int iVar1;
  undefined1 auStack_28 [8];
  undefined4 local_20;
  undefined4 local_1c;
  
  NKDbgPrintfW(L"+MAL_PowerUp\r\n");
  local_20 = 2;
  local_1c = 1;
  iVar1 = KernelIoControl(0x1032c9f,&local_20,0x10,0,0,auStack_28);
  if (iVar1 == 0) {
    NKDbgPrintfW(L"PowerUp: IOCTL_HAL_VSS OiControl failed for GPU\r\n");
  }
  local_20 = 3;
  local_1c = 1;
  iVar1 = KernelIoControl(0x1032c9f,&local_20,0x10,0,0,auStack_28);
  if (iVar1 == 0) {
    NKDbgPrintfW(L"PowerUp: IOCTL_HAL_VSS OiControl failed for MGP\r\n");
  }
  NKDbgPrintfW(L"-MAL_PowerUp\r\n");
  return 0;
}



/* c0991dc8 FUN_c0991dc8 */

/* Boundary evidence: original MIPS .pdata c0991dc8..c0991e6f. Semantic name remains unreviewed. */

undefined4 FUN_c0991dc8(LPCWSTR param_1,LPBYTE param_2)

{
  HKEY hKey;
  undefined4 uVar1;
  LSTATUS LVar2;
  DWORD local_18 [2];
  
  hKey = (HKEY)OpenDeviceKey(DAT_c0996854);
  if (hKey == (HKEY)0x0) {
    uVar1 = 0;
  }
  else {
    local_18[0] = 4;
    LVar2 = RegQueryValueExW(hKey,param_1,(LPDWORD)0x0,(LPDWORD)0x0,param_2,local_18);
    RegCloseKey(hKey);
    uVar1 = 1;
    if (LVar2 == 2) {
      uVar1 = 0;
    }
  }
  return uVar1;
}



/* c0991e70 FUN_c0991e70 */

/* Boundary evidence: original MIPS .pdata c0991e70..c0991ebb. Semantic name remains unreviewed. */

undefined4 FUN_c0991e70(HMODULE param_1,int param_2)

{
  if (param_2 == 1) {
    RegisterDbgZones(param_1,&DAT_c09961b8);
    DisableThreadLibraryCalls(param_1);
  }
  return 1;
}



/* c0991ebc MAL_PowerDown */

void MAL_PowerDown(void)

{
                    /* 0x11ebc  6  MAL_PowerDown */
  return;
}



/* c0991ec4 MAL_PowerUp */

void MAL_PowerUp(void)

{
                    /* 0x11ec4  7  MAL_PowerUp */
  return;
}



/* c0991ecc FUN_c0991ecc */

/* Boundary evidence: original MIPS .pdata c0991ecc..c0991f87. Semantic name remains unreviewed. */

undefined4 FUN_c0991ecc(undefined4 param_1)

{
  switch(param_1) {
  case 0:
    return 0;
  case 0xfffffff9:
    return 0x490;
  case 0xfffffffa:
    return 0x4d5;
  case 0xfffffffb:
    return 0x5b4;
  case 0xfffffffc:
    return 0xe;
  case 0xfffffffd:
    return 0xa0;
  case 0xfffffffe:
    return 1;
  default:
    return 0x54f;
  }
}



/* c0991f88 FUN_c0991f88 */

/* Boundary evidence: original MIPS .pdata c0991f88..c0991ff3. Semantic name remains unreviewed. */

void FUN_c0991f88(void)

{
  DWORD DVar1;
  
  CloseMsgQueue(DAT_c0996824);
  DVar1 = WaitForSingleObject(DAT_c0996828,5000);
  if (DVar1 != 0) {
    TerminateThread(DAT_c0996828,0xffffffff);
  }
  CloseHandle(DAT_c099681c);
  CloseMsgQueue(DAT_c0996820);
  return;
}



/* c0991ff4 FUN_c0991ff4 */

/* Boundary evidence: original MIPS .pdata c0991ff4..c099202b. Semantic name remains unreviewed. */

undefined4 FUN_c0991ff4(LPCWSTR param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 local_10 [2];
  
  iVar1 = FUN_c0991dc8(param_1,(LPBYTE)local_10);
  if (iVar1 != 0) {
    param_2 = local_10[0];
  }
  return param_2;
}



/* c099202c FUN_c099202c */

/* Boundary evidence: original MIPS .pdata c099202c..c099206b. Semantic name remains unreviewed. */

undefined4 FUN_c099202c(void)

{
  int iVar1;
  undefined4 local_10 [2];
  
  iVar1 = FUN_c0991dc8(L"Priority256",(LPBYTE)local_10);
  if (iVar1 == 0) {
    return 0xfb;
  }
  return local_10[0];
}



/* c099206c MAL_Close */

/* Boundary evidence: original MIPS .pdata c099206c..c09920ab. Semantic name remains unreviewed. */

undefined4 MAL_Close(int param_1)

{
  int iVar1;
  undefined4 local_res0 [4];
  
                    /* 0x1206c  1  MAL_Close */
  if ((param_1 != 0) && (local_res0[0] = param_1, iVar1 = FUN_c09928d8(local_res0), iVar1 == 0)) {
    return 1;
  }
  return 0;
}



/* c09920ac MAL_Open */

/* Boundary evidence: original MIPS .pdata c09920ac..c09920e7. Semantic name remains unreviewed. */

undefined4 MAL_Open(void)

{
  int iVar1;
  undefined4 local_10 [2];
  
                    /* 0x120ac  5  MAL_Open */
  local_10[0] = 0;
  iVar1 = FUN_c0992fb0(local_10);
  if (iVar1 != 0) {
    return 0;
  }
  return local_10[0];
}



/* c09920e8 FUN_c09920e8 */

/* Boundary evidence: original MIPS .pdata c09920e8..c0992273. Semantic name remains unreviewed. */

undefined4 FUN_c09920e8(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  MMRESULT MVar2;
  char *pcVar3;
  undefined4 uVar4;
  char *pcVar5;
  uint local_28;
  undefined4 local_24;
  timecaps_tag local_20;
  
  iVar1 = FUN_c0991dc8(L"Benchmark",(LPBYTE)&local_24);
  DAT_c0996798 = 0;
  if (iVar1 != 0) {
    DAT_c0996798 = local_24;
  }
  iVar1 = FUN_c0991dc8(L"HangCheckMs",(LPBYTE)&local_28);
  pcVar5 = "initialize_kernel_device";
  if (iVar1 != 0) {
    MVar2 = timeGetDevCaps(&local_20,8);
    if (MVar2 == 0) {
      if (local_28 < local_20.wPeriodMin) {
        local_28 = local_20.wPeriodMin;
        DAT_c09961b0 = local_28;
      }
      else {
        DAT_c09961b0 = local_28;
        if (local_20.wPeriodMax < local_28) {
          local_28 = local_20.wPeriodMax;
          DAT_c09961b0 = local_28;
        }
      }
    }
    else {
      FUN_c098b68c("Mali: ERR: %s\n","src/devicedrv/mali/windowsce/mali_kernel_windowsce.c",param_3,
                   param_4);
      param_3 = 0x85;
      pcVar3 = pcVar5;
      FUN_c098b68c("           %s()%4d\n           ","initialize_kernel_device",0x85,param_4);
      FUN_c098b68c("timeGetDevCaps() failed. mali_hang_check_interval not clamped to timer limits\n"
                   ,pcVar3,param_3,param_4);
      FUN_c098b68c("\n",pcVar3,param_3,param_4);
      DAT_c09961b0 = local_28;
    }
  }
  CalibrateStallCounter();
  iVar1 = FUN_c098c40c();
  if (iVar1 == 0) {
    uVar4 = 0;
  }
  else {
    FUN_c098b68c("Mali: ERR: %s\n","src/devicedrv/mali/windowsce/mali_kernel_windowsce.c",param_3,
                 param_4);
    uVar4 = 0x8f;
    FUN_c098b68c("           %s()%4d\n           ","initialize_kernel_device",0x8f,param_4);
    FUN_c098b68c("Failed to Initialize IRQ WorkQueue\n",pcVar5,uVar4,param_4);
    FUN_c098b68c("\n",pcVar5,uVar4,param_4);
    uVar4 = 0xffffffff;
  }
  return uVar4;
}



/* c0992274 MAL_Deinit */

/* Boundary evidence: original MIPS .pdata c0992274..c0992327. Semantic name remains unreviewed. */

undefined4 MAL_Deinit(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  DWORD DVar1;
  int iVar2;
  undefined4 uVar3;
  
                    /* 0x12274  2  MAL_Deinit */
  FUN_c0992e7c();
  CloseMsgQueue(DAT_c0996824);
  uVar3 = 5000;
  DVar1 = WaitForSingleObject(DAT_c0996828,5000);
  if (DVar1 != 0) {
    uVar3 = 0xffffffff;
    TerminateThread(DAT_c0996828,0xffffffff);
  }
  CloseHandle(DAT_c099681c);
  CloseMsgQueue(DAT_c0996820);
  iVar2 = FUN_c0991c3c();
  if (iVar2 != 0) {
    FUN_c098b68c("Mali: ",uVar3,param_3,param_4);
    FUN_c098b68c("Failed to powerdown MALI\n",uVar3,param_3,param_4);
    return 0;
  }
  return 1;
}



/* c0992328 MAL_Init */

/* Boundary evidence: original MIPS .pdata c0992328..c09923cb. Semantic name remains unreviewed. */

undefined4 MAL_Init(undefined4 param_1,undefined4 param_2,wchar_t *param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = param_1;
                    /* 0x12328  4  MAL_Init */
  iVar1 = FUN_c0991cfc();
  if (iVar1 != 0) {
    FUN_c098b68c("Mali: ",param_2,param_3,param_4);
    FUN_c098b68c("Failed to initialise MALI\n",param_2,param_3,param_4);
    return 0;
  }
  DAT_c0996854 = param_1;
  iVar1 = FUN_c09937a4(uVar2,param_2,param_3,param_4);
  if (iVar1 != 0) {
    FUN_c098b68c("Mali: ",param_2,param_3,param_4);
    FUN_c098b68c("Failed to initialize driver (error %d)\n",iVar1,param_3,param_4);
    return 0;
  }
  return 4;
}



/* c09923cc MAL_IOControl */

/* Boundary evidence: original MIPS .pdata c09923cc..c09928d7. Semantic name remains unreviewed. */

bool MAL_IOControl(int param_1,uint param_2,uint *param_3,undefined4 param_4,void *param_5,
                  uint param_6,uint *param_7)

{
  int iVar1;
  DWORD dwErrCode;
  
                    /* 0x123cc  3  MAL_IOControl */
  dwErrCode = 0xa0;
  if ((param_1 == 0) || (param_5 == (void *)0x0)) {
switchD_c099259c_caseD_f000204d:
    dwErrCode = 0x57;
  }
  else if (param_2 < 0xf0002069) {
    if (param_2 == 0xf0002068) {
      if (0x17 < param_6) {
        dwErrCode = FUN_c0994e34(param_1,(int)param_5,param_3,param_4);
        goto LAB_c0992880;
      }
    }
    else if (param_2 < 0xf0002049) {
      if (param_2 == 0xf0002048) {
        if (0x23 < param_6) {
          dwErrCode = FUN_c0991ecc(0xffffffff);
          goto LAB_c0992880;
        }
      }
      else if (param_2 < 0xf0002015) {
        if (param_2 == 0xf0002014) {
          if (0xb < param_6) {
            dwErrCode = FUN_c09940e8(param_1,(int)param_5);
            goto LAB_c0992880;
          }
        }
        else if (param_2 == 0xf0002008) {
          if (7 < param_6) {
            dwErrCode = 0;
            *(undefined4 *)((int)param_5 + 4) = DAT_c0996794;
            goto LAB_c09928a8;
          }
        }
        else if (param_2 == 0xf000200c) {
          if (0xf < param_6) {
            dwErrCode = FUN_c0994168(param_1,(int)param_5);
            goto LAB_c0992880;
          }
        }
        else {
          if (param_2 != 0xf0002010) goto switchD_c099259c_caseD_f000204d;
          if (0x47 < param_6) {
            dwErrCode = FUN_c0994004(param_1,param_5);
            goto LAB_c0992880;
          }
        }
      }
      else if (param_2 == 0xf0002040) {
        if (0xb < param_6) {
          dwErrCode = FUN_c0994ab8(param_1,(int)param_5);
          goto LAB_c0992880;
        }
      }
      else {
        if (param_2 != 0xf0002044) goto switchD_c099259c_caseD_f000204d;
        if (3 < param_6) {
          dwErrCode = 0;
          goto LAB_c09928a8;
        }
      }
    }
    else {
      switch(param_2) {
      case 0xf000204c:
        if (7 < param_6) {
          dwErrCode = FUN_c0991ecc(0xffffffff);
          goto LAB_c0992880;
        }
        break;
      default:
        goto switchD_c099259c_caseD_f000204d;
      case 0xf0002050:
        if (0x1b < param_6) {
          dwErrCode = FUN_c0994b10(param_1,(int)param_5);
          goto LAB_c0992880;
        }
        break;
      case 0xf0002054:
        if (0xf < param_6) {
          dwErrCode = FUN_c0994d64(param_1,(int)param_5);
          goto LAB_c0992880;
        }
        break;
      case 0xf0002058:
        if (7 < param_6) {
          dwErrCode = FUN_c0994cf0(param_1,(int)param_5);
          goto LAB_c0992880;
        }
        break;
      case 0xf000205c:
        if (0x1b < param_6) {
          dwErrCode = FUN_c0994bbc(param_1,(int)param_5);
          goto LAB_c0992880;
        }
      }
    }
  }
  else if (param_2 < 0xf000208d) {
    if (param_2 == 0xf000208c) {
      if (7 < param_6) {
        dwErrCode = FUN_c09942b8(param_1,(int)param_5,param_3,param_4);
        goto LAB_c0992880;
      }
    }
    else if (param_2 < 0xf0002081) {
      if (param_2 == 0xf0002080) {
        if (0x10f < param_6) {
          dwErrCode = FUN_c0994364(param_1,param_5,param_3,param_4);
          goto LAB_c0992880;
        }
      }
      else if (param_2 == 0xf000206c) {
        if (7 < param_6) {
          dwErrCode = FUN_c0994dd8(param_1,(int)param_5);
          goto LAB_c0992880;
        }
      }
      else {
        if (param_2 != 0xf0002070) goto switchD_c099259c_caseD_f000204d;
        if (0xf < param_6) {
          iVar1 = FUN_c09947e8((int)param_5,-0xfffdf90,param_3,param_4);
          dwErrCode = FUN_c0991ecc(iVar1);
          goto LAB_c0992880;
        }
      }
    }
    else if (param_2 == 0xf0002084) {
      if (7 < param_6) {
        dwErrCode = FUN_c0994438(param_1,(int)param_5,param_3,param_4);
        goto LAB_c0992880;
      }
    }
    else {
      if (param_2 != 0xf0002088) goto switchD_c099259c_caseD_f000204d;
      if (7 < param_6) {
        dwErrCode = FUN_c0994228(param_1,(int)param_5);
        goto LAB_c0992880;
      }
    }
  }
  else {
    switch(param_2) {
    case 0xf00020c0:
      if (0x47 < param_6) {
        dwErrCode = FUN_c09946ac(param_1,param_5,param_3,param_4);
LAB_c0992880:
        if (dwErrCode == 0) goto LAB_c09928a8;
      }
      break;
    default:
      goto switchD_c099259c_caseD_f000204d;
    case 0xf00020c4:
      if (7 < param_6) {
        dwErrCode = FUN_c0994784(param_1,(int)param_5,param_3,param_4);
        goto LAB_c0992880;
      }
      break;
    case 0xf00020c8:
      if (7 < param_6) {
        dwErrCode = FUN_c099449c(param_1,(int)param_5);
        goto LAB_c0992880;
      }
      break;
    case 0xf00020cc:
      if (7 < param_6) {
        dwErrCode = FUN_c0994600(param_1,(int)param_5,param_3,param_4);
        goto LAB_c0992880;
      }
      break;
    case 0xf00020d0:
      if (0x13 < param_6) {
        dwErrCode = FUN_c099452c(param_1,(int)param_5,param_3,param_4);
        goto LAB_c0992880;
      }
    }
  }
  SetLastError(dwErrCode);
LAB_c09928a8:
  if (param_7 != (uint *)0x0) {
    *param_7 = param_6;
  }
  return dwErrCode == 0;
}



/* c09928d8 FUN_c09928d8 */

/* Boundary evidence: original MIPS .pdata c09928d8..c09929ab. Semantic name remains unreviewed. */

undefined4 FUN_c09928d8(undefined4 *param_1)

{
  undefined4 uVar1;
  undefined **ppuVar2;
  int *_Memory;
  int iVar3;
  void *_Memory_00;
  
  if (param_1 == (undefined4 *)0x0) {
    uVar1 = 0xfffffffd;
  }
  else {
    _Memory_00 = (void *)*param_1;
    iVar3 = (int)_Memory_00 + 0x10;
    ppuVar2 = &PTR_PTR_c0996638;
    do {
      if (*(code **)(*ppuVar2 + 0x14) != (code *)0x0) {
        (**(code **)(*ppuVar2 + 0x14))(_Memory_00,iVar3);
      }
      ppuVar2 = ppuVar2 + -1;
      iVar3 = iVar3 + -4;
    } while (-0x3f6699d9 < (int)ppuVar2);
    _Memory = *(int **)((int)_Memory_00 + 0x14);
    if (_Memory[1] != 0) {
      CloseMsgQueue();
    }
    if (*_Memory != 0) {
      CloseMsgQueue();
    }
    free(_Memory);
    free(_Memory_00);
    *param_1 = 0;
    uVar1 = 0;
  }
  return uVar1;
}



/* c0992a10 FUN_c0992a10 */

/* Boundary evidence: original MIPS .pdata c0992a10..c0992b4b. Semantic name remains unreviewed. */

undefined4 FUN_c0992a10(uint param_1,uint param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  uint uVar2;
  
  if (((((param_1 & 0xfff) == 0) && ((param_2 & 0xfff) == 0)) && (DAT_c0996600 <= param_1)) &&
     (((DAT_c0996600 <= param_1 + param_2 && (param_1 <= DAT_c0996604 + DAT_c0996600)) &&
      (param_1 + param_2 <= DAT_c0996604 + DAT_c0996600)))) {
    uVar1 = 0;
  }
  else {
    uVar2 = param_2;
    FUN_c098b68c("*******************************************************************************\n"
                 ,param_2,param_3,param_4);
    FUN_c098b68c("MALI PHYSICAL RANGE VALIDATION ERROR!\n",uVar2,param_3,param_4);
    FUN_c098b68c("\n",uVar2,param_3,param_4);
    FUN_c098b68c("We failed to validate a Mali-Physical range that the user-side wished to map in\n"
                 ,uVar2,param_3,param_4);
    FUN_c098b68c("\n",uVar2,param_3,param_4);
    FUN_c098b68c("It is likely that the user-side wished to do Direct Rendering, but a suitable\n",
                 uVar2,param_3,param_4);
    FUN_c098b68c("address range validation mechanism has not been correctly setup\n",uVar2,param_3,
                 param_4);
    FUN_c098b68c("\n",uVar2,param_3,param_4);
    FUN_c098b68c("The range supplied was: phys_base=0x%.8X, size=0x%.8X\n",param_1,param_2,param_4);
    FUN_c098b68c("\n",param_1,param_2,param_4);
    FUN_c098b68c("Please refer to the ARM Mali Software Integration Guide for more information.\n",
                 param_1,param_2,param_4);
    FUN_c098b68c("\n",param_1,param_2,param_4);
    FUN_c098b68c("*******************************************************************************\n"
                 ,param_1,param_2,param_4);
    uVar1 = 0xffffffff;
  }
  return uVar1;
}



/* c0992b4c FUN_c0992b4c */

/* Boundary evidence: original MIPS .pdata c0992b4c..c0992bcf. Semantic name remains unreviewed. */

int FUN_c0992b4c(uint *param_1,uint param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = *param_1 - DAT_c0996608;
  if (((uVar2 & 0xfff) == 0) && ((param_2 & 0xfff) == 0)) {
    iVar1 = FUN_c0992a10(uVar2,param_2,param_3,param_4);
    if (iVar1 == 0) {
      *param_1 = uVar2;
      iVar1 = 0;
    }
    return iVar1;
  }
  return -1;
}



/* c0992c80 FUN_c0992c80 */

/* Boundary evidence: original MIPS .pdata c0992c80..c0992d5f. Semantic name remains unreviewed. */

int FUN_c0992c80(int *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  int *local_18 [2];
  
  if (*param_1 == 0) {
    return -3;
  }
  if ((DAT_c09965fc < 5) &&
     (puVar2 = *(undefined4 **)(DAT_c09965fc * 4 + *param_1), puVar2 != (undefined4 *)0x0)) {
    iVar1 = FUN_c098acd8(puVar2,param_1[1],local_18);
    if (iVar1 == -5) {
      param_1[1] = 0x10;
    }
    else {
      if (iVar1 != 0) {
        return iVar1;
      }
      param_1[1] = *local_18[0];
      memcpy(param_1 + 2,(void *)local_18[0][2],local_18[0][1]);
      free((void *)local_18[0][2]);
      free(local_18[0] + -2);
    }
  }
  else {
    param_1[1] = 0x20;
  }
  return 0;
}



/* c0992dc8 FUN_c0992dc8 */

/* Boundary evidence: original MIPS .pdata c0992dc8..c0992e03. Semantic name remains unreviewed. */

void FUN_c0992dc8(void)

{
  if (DAT_c099675c != (void *)0x0) {
    free(DAT_c099675c);
    DAT_c099675c = (void *)0x0;
  }
  return;
}



/* c0992e04 FUN_c0992e04 */

/* Boundary evidence: original MIPS .pdata c0992e04..c0992e7b. Semantic name remains unreviewed. */

void FUN_c0992e04(undefined4 param_1,undefined4 param_2)

{
  undefined **ppuVar1;
  
  ppuVar1 = &PTR_PTR_c0996628;
  do {
    if (*(code **)(*ppuVar1 + 0x18) != (code *)0x0) {
      (**(code **)(*ppuVar1 + 0x18))(param_1,param_2);
    }
    ppuVar1 = ppuVar1 + 1;
  } while ((int)ppuVar1 < -0x3f6699c4);
  return;
}



/* c0992e7c FUN_c0992e7c */

/* Boundary evidence: original MIPS .pdata c0992e7c..c0992f07. Semantic name remains unreviewed. */

void FUN_c0992e7c(void)

{
  void *_Memory;
  undefined **ppuVar1;
  int iVar2;
  
  iVar2 = 4;
  ppuVar1 = &PTR_PTR_c0996638;
  do {
    if (*(code **)(*ppuVar1 + 4) != (code *)0x0) {
      (**(code **)(*ppuVar1 + 4))(iVar2);
    }
    _Memory = DAT_c099678c;
    ppuVar1 = ppuVar1 + -1;
    iVar2 = iVar2 + -1;
  } while (-0x3f6699d9 < (int)ppuVar1);
  if (DAT_c099678c != (void *)0x0) {
    CloseHandle(*(HANDLE *)((int)DAT_c099678c + 4));
    free(_Memory);
  }
  return;
}



/* c0992f08 FUN_c0992f08 */

/* Boundary evidence: original MIPS .pdata c0992f08..c0992faf. Semantic name remains unreviewed. */

int FUN_c0992f08(undefined4 param_1,uint param_2)

{
  int iVar1;
  int *piVar2;
  uint uVar3;
  
  uVar3 = 0;
  piVar2 = DAT_c099675c;
  if (param_2 != 0) {
    do {
      iVar1 = *piVar2;
      if (((iVar1 < 0) || (10 < iVar1)) || ((code *)(&DAT_c0996760)[iVar1] == (code *)0x0)) {
        return -3;
      }
      iVar1 = (*(code *)(&DAT_c0996760)[iVar1])(piVar2);
      if (iVar1 != 0) {
        return iVar1;
      }
      uVar3 = uVar3 + 1;
      piVar2 = piVar2 + 9;
    } while (uVar3 < param_2);
  }
  return 0;
}



/* c0992fb0 FUN_c0992fb0 */

/* Boundary evidence: original MIPS .pdata c0992fb0..c099311f. Semantic name remains unreviewed. */

int FUN_c0992fb0(undefined4 *param_1)

{
  void *_Dst;
  int *piVar1;
  int iVar2;
  int iVar3;
  undefined **ppuVar4;
  
  _Dst = malloc(0x18);
  if (_Dst != (void *)0x0) {
    memset(_Dst,0,0x14);
    piVar1 = FUN_c098ae88();
    *(int **)((int)_Dst + 0x14) = piVar1;
    if (piVar1 != (int *)0x0) {
      ppuVar4 = &PTR_PTR_c0996628;
      iVar3 = 0;
      while ((*(code **)(*ppuVar4 + 0x10) == (code *)0x0 ||
             (iVar2 = (**(code **)(*ppuVar4 + 0x10))
                                (_Dst,(int)_Dst + 0x3f6699d8 + (int)ppuVar4,
                                 *(undefined4 *)((int)_Dst + 0x14)), iVar2 == 0))) {
        ppuVar4 = ppuVar4 + 1;
        iVar3 = iVar3 + 1;
        if (-0x3f6699c5 < (int)ppuVar4) {
          *param_1 = _Dst;
          return 0;
        }
      }
      iVar3 = iVar3 + -1;
      if (-1 < iVar3) {
        ppuVar4 = &PTR_PTR_c0996628 + iVar3;
        do {
          if (*(code **)(*ppuVar4 + 0x14) != (code *)0x0) {
            (**(code **)(*ppuVar4 + 0x14))(_Dst,(int)ppuVar4 + (int)_Dst + 0x3f6699d8);
          }
          iVar3 = iVar3 + -1;
          ppuVar4 = ppuVar4 + -1;
        } while (-1 < iVar3);
      }
      piVar1 = *(int **)((int)_Dst + 0x14);
      if (piVar1[1] != 0) {
        CloseMsgQueue();
      }
      if (*piVar1 != 0) {
        CloseMsgQueue();
      }
      free(piVar1);
      free(_Dst);
      return iVar2;
    }
    free(_Dst);
  }
  return -4;
}



/* c0993120 FUN_c0993120 */

/* Boundary evidence: original MIPS .pdata c0993120..c09932bb. Semantic name remains unreviewed. */

undefined4 FUN_c0993120(int *param_1)

{
  int *piVar1;
  int *piVar2;
  int *_Dst;
  undefined4 uVar3;
  void *pvVar4;
  int iVar5;
  int *_Dst_00;
  int iVar6;
  
  uVar3 = 0xffffffff;
  if ((*param_1 == 0) || (param_1[2] == 0)) {
    uVar3 = 0xfffffffd;
  }
  else {
    FUN_c098be3c(DAT_c099678c);
    piVar2 = DAT_c0996790;
    if (DAT_c0996794 <= (uint)param_1[1]) {
      iVar5 = param_1[3];
      if (iVar5 == 0) {
        iVar5 = param_1[2];
      }
      _Dst_00 = (int *)param_1[2];
      memcpy(_Dst_00,DAT_c0996790,0x10);
      pvVar4 = (void *)*piVar2;
      _Dst = _Dst_00 + 4;
      if (pvVar4 != (void *)0x0) {
        iVar6 = (int)_Dst + (iVar5 - (int)_Dst_00);
        piVar1 = _Dst_00;
        do {
          *piVar1 = iVar6;
          memcpy(_Dst,pvVar4,0x18);
          piVar1 = _Dst + 5;
          pvVar4 = *(void **)((int)pvVar4 + 0x14);
          _Dst = _Dst + 6;
          iVar6 = iVar6 + 0x18;
        } while (pvVar4 != (void *)0x0);
      }
      pvVar4 = (void *)piVar2[1];
      piVar2 = _Dst_00 + 1;
      if (pvVar4 != (void *)0x0) {
        iVar5 = (int)_Dst + (iVar5 - (int)_Dst_00);
        do {
          *piVar2 = iVar5;
          memcpy(_Dst,pvVar4,0x14);
          piVar2 = _Dst + 4;
          pvVar4 = *(void **)((int)pvVar4 + 0x10);
          _Dst = _Dst + 5;
          iVar5 = iVar5 + 0x14;
        } while (pvVar4 != (void *)0x0);
      }
      uVar3 = 0;
    }
    piVar2 = DAT_c099678c;
    if ((((-1 < *DAT_c099678c) && (*DAT_c099678c < 4)) && (DAT_c099678c[2] == 1)) &&
       (iVar5 = __GetUserKData(8), piVar2[3] == iVar5)) {
      piVar2[2] = 0;
      piVar2[3] = 0;
      ReleaseMutex((HANDLE)piVar2[1]);
    }
  }
  return uVar3;
}



/* c09932bc FUN_c09932bc */

/* Boundary evidence: original MIPS .pdata c09932bc..c0993517. Semantic name remains unreviewed. */

int FUN_c09932bc(void)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  DWORD DVar4;
  void *pvVar5;
  code *pcVar6;
  int *piVar7;
  int iVar8;
  uint uVar9;
  
  iVar8 = 0x10;
  piVar2 = malloc(0x10);
  if (piVar2 == (int *)0x0) {
    iVar3 = -4;
  }
  else {
    *(undefined1 *)piVar2 = 0;
    *(undefined1 *)((int)piVar2 + 1) = 0;
    uVar9 = 0;
    *(undefined1 *)((int)piVar2 + 2) = 0;
    *(undefined1 *)((int)piVar2 + 3) = 0;
    *(undefined1 *)(piVar2 + 1) = 0;
    *(undefined1 *)((int)piVar2 + 5) = 0;
    *(undefined1 *)((int)piVar2 + 6) = 0;
    *(undefined1 *)((int)piVar2 + 7) = 0;
    *(undefined1 *)(piVar2 + 2) = 0;
    *(undefined1 *)((int)piVar2 + 9) = 0;
    *(undefined1 *)((int)piVar2 + 10) = 0;
    *(undefined1 *)((int)piVar2 + 0xb) = 0;
    *(undefined1 *)(piVar2 + 3) = 0;
    *(undefined1 *)((int)piVar2 + 0xd) = 0;
    *(undefined1 *)((int)piVar2 + 0xe) = 0;
    *(undefined1 *)((int)piVar2 + 0xf) = 0;
    do {
      pcVar6 = *(code **)(*(int *)((int)&PTR_PTR_c0996628 + uVar9) + 0xc);
      if ((pcVar6 != (code *)0x0) && (iVar3 = (*pcVar6)(piVar2), piVar7 = piVar2, iVar3 != 0))
      goto LAB_c099348c;
      piVar7 = DAT_c099678c;
      uVar9 = uVar9 + 4;
    } while (uVar9 < 0x14);
    for (iVar3 = *piVar2; iVar3 != 0; iVar3 = *(int *)(iVar3 + 0x14)) {
      iVar8 = iVar8 + 0x18;
    }
    for (iVar3 = piVar2[1]; iVar3 != 0; iVar3 = *(int *)(iVar3 + 0x10)) {
      iVar8 = iVar8 + 0x14;
    }
    if (((-1 < *DAT_c099678c) && (*DAT_c099678c < 4)) &&
       (DVar4 = WaitForSingleObject((HANDLE)DAT_c099678c[1],0xffffffff), DVar4 == 0)) {
      if (piVar7[2] == 1) {
        ReleaseMutex((HANDLE)piVar7[1]);
      }
      else {
        piVar7[2] = 1;
        iVar3 = __GetUserKData(8);
        piVar7[3] = iVar3;
      }
    }
    piVar7 = DAT_c0996790;
    piVar1 = DAT_c099678c;
    DAT_c0996790 = piVar2;
    DAT_c0996794 = iVar8;
    if (((-1 < *DAT_c099678c) && (*DAT_c099678c < 4)) &&
       ((DAT_c099678c[2] == 1 && (iVar8 = __GetUserKData(8), piVar1[3] == iVar8)))) {
      piVar1[2] = 0;
      piVar1[3] = 0;
      ReleaseMutex((HANDLE)piVar1[1]);
    }
    iVar3 = 0;
LAB_c099348c:
    if (piVar7 != (int *)0x0) {
      iVar8 = *piVar7;
      while (iVar8 != 0) {
        pvVar5 = (void *)*piVar7;
        *piVar7 = *(int *)((int)pvVar5 + 0x14);
        free(pvVar5);
        iVar8 = *piVar7;
      }
      iVar8 = piVar7[1];
      while (iVar8 != 0) {
        pvVar5 = (void *)piVar7[1];
        piVar7[1] = *(int *)((int)pvVar5 + 0x10);
        free(pvVar5);
        iVar8 = piVar7[1];
      }
      free(piVar7);
    }
  }
  return iVar3;
}



/* c0993518 FUN_c0993518 */

/* Boundary evidence: original MIPS .pdata c0993518..c099357f. Semantic name remains unreviewed. */

void FUN_c0993518(undefined4 param_1)

{
  int iVar1;
  
  DAT_c0996788 = &LAB_c0992bd0;
  DAT_c09965fc = param_1;
  iVar1 = FUN_c098af9c();
  if (iVar1 == 0) {
    FUN_c0992f08(&DAT_c099675c,DAT_c0996640);
  }
  return;
}



/* c0993580 FUN_c0993580 */

/* Boundary evidence: original MIPS .pdata c0993580..c099372f. Semantic name remains unreviewed. */

int FUN_c0993580(void)

{
  undefined4 *puVar1;
  HANDLE pvVar2;
  undefined **ppuVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined **ppuVar7;
  
  iVar5 = -1;
  puVar1 = malloc(0x10);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    pvVar2 = CreateMutexW((LPSECURITY_ATTRIBUTES)0x0,0,(LPCWSTR)0x0);
    puVar1[1] = pvVar2;
    if (pvVar2 == (HANDLE)0x0) {
      free(puVar1);
      puVar1 = (undefined4 *)0x0;
    }
    else {
      puVar1[2] = 0;
      puVar1[3] = 0;
      *puVar1 = 0;
    }
  }
  DAT_c099678c = puVar1;
  if (puVar1 == (undefined4 *)0x0) {
    iVar5 = -1;
  }
  else {
    ppuVar7 = &PTR_PTR_c0996628;
    iVar6 = 0;
    ppuVar3 = ppuVar7;
    do {
      if ((*(code **)*ppuVar3 != (code *)0x0) && (iVar5 = (**(code **)*ppuVar3)(iVar6), iVar5 != 0))
      goto LAB_c09936ac;
      ppuVar3 = ppuVar3 + 1;
      iVar6 = iVar6 + 1;
    } while ((int)ppuVar3 < -0x3f6699c4);
    iVar4 = 0;
    do {
      if ((*(code **)(*ppuVar7 + 8) != (code *)0x0) &&
         (iVar5 = (**(code **)(*ppuVar7 + 8))(iVar4), iVar5 != 0)) goto LAB_c09936ac;
      ppuVar7 = ppuVar7 + 1;
      iVar4 = iVar4 + 1;
    } while ((int)ppuVar7 < -0x3f6699c4);
    iVar4 = FUN_c09932bc();
    if (iVar4 == 0) {
      iVar5 = 0;
    }
    else {
LAB_c09936ac:
      iVar6 = iVar6 + -1;
      if (-1 < iVar6) {
        ppuVar3 = &PTR_PTR_c0996628 + iVar6;
        do {
          if (*(code **)(*ppuVar3 + 4) != (code *)0x0) {
            (**(code **)(*ppuVar3 + 4))(iVar6);
          }
          iVar6 = iVar6 + -1;
          ppuVar3 = ppuVar3 + -1;
        } while (-1 < iVar6);
      }
      puVar1 = DAT_c099678c;
      CloseHandle((HANDLE)DAT_c099678c[1]);
      free(puVar1);
    }
  }
  return iVar5;
}



/* c0993730 FUN_c0993730 */

/* Boundary evidence: original MIPS .pdata c0993730..c09937a3. Semantic name remains unreviewed. */

void FUN_c0993730(void)

{
  DWORD DVar1;
  
  FUN_c0992e7c();
  CloseMsgQueue(DAT_c0996824);
  DVar1 = WaitForSingleObject(DAT_c0996828,5000);
  if (DVar1 != 0) {
    TerminateThread(DAT_c0996828,0xffffffff);
  }
  CloseHandle(DAT_c099681c);
  CloseMsgQueue(DAT_c0996820);
  return;
}



/* c09937a4 FUN_c09937a4 */

/* Boundary evidence: original MIPS .pdata c09937a4..c09938ef. Semantic name remains unreviewed. */

int FUN_c09937a4(undefined4 param_1,undefined4 param_2,wchar_t *param_3,undefined4 param_4)

{
  int iVar1;
  
  iVar1 = FUN_c09920e8(param_1,param_2,param_3,param_4);
  if (iVar1 == 0) {
    CalibrateStallCounter();
    NKDbgPrintfW(&DAT_c098103c);
    NKDbgPrintfW(L"Mali200/GP2. \r\n");
    param_3 = L"17:11:08";
    NKDbgPrintfW(L"                   Compiled: %s, time: %s.\r\n",L"Jun 16 2010");
    NKDbgPrintfW(L"                    Variant: %s\r\n",
                 L"mali200-maligp2-udd-windowsce-gles11-gles20-vg-mmu-r0p4-drawmerge");
    NKDbgPrintfW(L"      MALI_MEMORY_IS_CACHED: %d\r\n",1);
    NKDbgPrintfW(L"                MEMCPY_FAST: %d\r\n",1);
    param_2 = 4;
    NKDbgPrintfW(L"  __PLATFORM_MAX_DR_BUFFERS: %d\r\n");
    NKDbgPrintfW(&DAT_c098103c);
    iVar1 = FUN_c0993580();
    if (iVar1 == 0) {
      FUN_c098b68c("Mali: ",param_2,param_3,param_4);
      FUN_c098b68c("Mali device driver %s loaded\n",&DAT_c0981288,param_3,param_4);
      return 0;
    }
    FUN_c098b68c("Mali: ",param_2,param_3,param_4);
    FUN_c098b68c("Mali subsystems failed\n",param_2,param_3,param_4);
    FUN_c098b5e0();
  }
  else {
    iVar1 = -1;
  }
  FUN_c098b68c("Mali: ",param_2,param_3,param_4);
  FUN_c098b68c("Mali device driver init failed\n",param_2,param_3,param_4);
  return iVar1;
}



/* c09938f0 FUN_c09938f0 */

/* Boundary evidence: original MIPS .pdata c09938f0..c099394f. Semantic name remains unreviewed. */

void FUN_c09938f0(void *param_1)

{
  void *_Memory;
  undefined4 *_Memory_00;
  
  _Memory_00 = *(undefined4 **)((int)param_1 + 0xc);
  _Memory = (void *)*_Memory_00;
  CloseHandle(*(HANDLE *)((int)_Memory + 4));
  free(_Memory);
  free(_Memory_00);
  free(param_1);
  return;
}



/* c0993950 FUN_c0993950 */

/* Boundary evidence: original MIPS .pdata c0993950..c0993a13. Semantic name remains unreviewed. */

void FUN_c0993950(int param_1)

{
  int iVar1;
  uint uVar2;
  undefined4 *puVar3;
  int *piVar4;
  
  puVar3 = *(undefined4 **)(param_1 + 4);
  uVar2 = *(uint *)(param_1 + 8);
  iVar1 = FUN_c098be3c((int *)*puVar3);
  if (iVar1 == 0) {
    puVar3[2] = puVar3[2] - (1 << (uVar2 & 0x1f));
    FreePhysMem(*(undefined4 *)(param_1 + 0x14));
    piVar4 = (int *)*puVar3;
    if ((((-1 < *piVar4) && (*piVar4 < 4)) && (piVar4[2] == 1)) &&
       (iVar1 = __GetUserKData(8), piVar4[3] == iVar1)) {
      piVar4[2] = 0;
      piVar4[3] = 0;
      ReleaseMutex((HANDLE)piVar4[1]);
    }
  }
  return;
}



/* c0993a14 FUN_c0993a14 */

/* Boundary evidence: original MIPS .pdata c0993a14..c0993aff. Semantic name remains unreviewed. */

undefined4 FUN_c0993a14(undefined4 *param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int local_18 [2];
  
  iVar1 = FUN_c098be3c((int *)*param_1);
  if (iVar1 == 0) {
    if (((uint)param_1[1] < param_1[2] + 0x40) ||
       (iVar1 = AllocPhysMem(0x40000,4,0xfff,0,local_18), iVar1 == 0)) {
      FUN_c098bdc8((int *)*param_1);
      uVar2 = 2;
    }
    else {
      *param_2 = FUN_c0993950;
      param_2[2] = 6;
      param_2[1] = param_1;
      param_2[3] = 0x40000;
      iVar3 = param_1[3];
      param_2[5] = iVar1;
      param_2[4] = local_18[0] - iVar3;
      param_1[2] = param_1[2] + 0x40;
      FUN_c098bdc8((int *)*param_1);
      uVar2 = 0;
    }
  }
  else {
    uVar2 = 3;
  }
  return uVar2;
}



/* c0993b00 FUN_c0993b00 */

/* Boundary evidence: original MIPS .pdata c0993b00..c0993beb. Semantic name remains unreviewed. */

void FUN_c0993b00(undefined4 *param_1,int *param_2)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  
  piVar2 = (int *)param_2[2];
  iVar3 = param_2[3];
  iVar1 = FUN_c098be3c((int *)*param_1);
  if (iVar1 == 0) {
    param_1[2] = param_1[2] - *param_2;
    FUN_c0983afc(piVar2,iVar3,param_2[1],*param_2 << 0xc,1);
    piVar2 = (int *)*param_1;
    if ((((-1 < *piVar2) && (*piVar2 < 4)) && (piVar2[2] == 1)) &&
       (iVar1 = __GetUserKData(8), piVar2[3] == iVar1)) {
      piVar2[2] = 0;
      piVar2[3] = 0;
      ReleaseMutex((HANDLE)piVar2[1]);
    }
    free(param_2);
  }
  return;
}



/* c0993bec FUN_c0993bec */

/* Boundary evidence: original MIPS .pdata c0993bec..c0993ed3. Semantic name remains unreviewed. */

undefined1
FUN_c0993bec(undefined4 *param_1,int *param_2,int *param_3,uint *param_4,undefined4 *param_5)

{
  int iVar1;
  uint *_Memory;
  int iVar2;
  uint uVar3;
  int *piVar4;
  uint uVar5;
  uint uVar6;
  undefined1 uVar7;
  undefined4 uVar8;
  int local_34;
  int *local_30;
  
  uVar7 = 2;
  uVar5 = 0;
  uVar3 = param_3[2] - *param_4;
  local_30 = param_2;
  iVar1 = FUN_c098be3c((int *)*param_1);
  if (iVar1 != 0) {
    return 3;
  }
  _Memory = malloc(0x10);
  if (_Memory != (uint *)0x0) {
    _Memory[1] = *param_4;
    *_Memory = uVar3 + 0xfff >> 0xc;
    if (uVar3 != 0) {
      do {
        if ((uint)param_1[1] <= uVar5 + param_1[2]) break;
        uVar8 = 0;
        iVar1 = param_1[3];
        uVar6 = *param_4;
        local_34 = -1;
        if ((param_3[4] & 1U) != 0) {
          uVar8 = 1;
          iVar2 = (**(code **)(local_30[1] + 8))(param_3,uVar6,&local_34,0x1000);
          local_34 = local_34 - iVar1;
          param_2 = local_30;
          if (iVar2 == 0) goto LAB_c0993cfc;
LAB_c0993d98:
          if (iVar2 != -4) {
            if (0 < (int)uVar5) {
              FUN_c0983afc(param_2,(int)param_3,_Memory[1],uVar5 << 0xc,1);
            }
            uVar7 = 3;
            goto LAB_c0993e40;
          }
          break;
        }
LAB_c0993cfc:
        param_2 = local_30;
        iVar2 = (**(code **)(*local_30 + 8))(param_3,uVar6,&local_34,0x1000);
        if (iVar2 != 0) {
          if ((param_3[4] & 1U) != 0) {
            (**(code **)(param_2[1] + 0xc))(param_3,uVar6,0x1000,uVar8);
          }
          goto LAB_c0993d98;
        }
        if (uVar3 < 0x1000) {
          uVar3 = 0;
        }
        else {
          uVar3 = uVar3 - 0x1000;
        }
        uVar5 = uVar5 + 1;
        *param_4 = *param_4 + 0x1000;
      } while (uVar3 != 0);
      if (uVar5 != 0) {
        uVar7 = uVar3 != 0;
        CacheRangeFlush(_Memory[1] + *param_3,uVar5 << 0xc,0x20);
        *_Memory = uVar5;
        _Memory[2] = (uint)param_2;
        _Memory[3] = (uint)param_3;
        param_1[2] = uVar5 + param_1[2];
        param_5[1] = param_1;
        param_5[2] = _Memory;
        *param_5 = FUN_c0993b00;
        goto LAB_c0993e4c;
      }
    }
    uVar7 = 2;
LAB_c0993e40:
    free(_Memory);
  }
LAB_c0993e4c:
  piVar4 = (int *)*param_1;
  if ((((-1 < *piVar4) && (*piVar4 < 4)) && (piVar4[2] == 1)) &&
     (iVar1 = __GetUserKData(8), piVar4[3] == iVar1)) {
    piVar4[2] = 0;
    piVar4[3] = 0;
    ReleaseMutex((HANDLE)piVar4[1]);
  }
  return uVar7;
}



/* c0993ed4 FUN_c0993ed4 */

/* Boundary evidence: original MIPS .pdata c0993ed4..c0994003. Semantic name remains unreviewed. */

undefined4 * FUN_c0993ed4(int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 *_Memory;
  undefined4 *_Memory_00;
  undefined4 *_Memory_01;
  HANDLE pvVar1;
  
  _Memory = malloc(0x1c);
  if (_Memory != (undefined4 *)0x0) {
    _Memory_00 = malloc(0x10);
    if (_Memory_00 != (undefined4 *)0x0) {
      _Memory_00[2] = 0;
      _Memory_00[1] = param_1 + 0xfffU >> 0xc;
      _Memory_00[3] = param_2;
      _Memory_01 = malloc(0x10);
      if (_Memory_01 == (undefined4 *)0x0) {
        _Memory_01 = (undefined4 *)0x0;
      }
      else {
        pvVar1 = CreateMutexW((LPSECURITY_ATTRIBUTES)0x0,0,(LPCWSTR)0x0);
        _Memory_01[1] = pvVar1;
        if (pvVar1 == (HANDLE)0x0) {
          free(_Memory_01);
          _Memory_01 = (undefined4 *)0x0;
        }
        else {
          _Memory_01[2] = 0;
          _Memory_01[3] = 0;
          *_Memory_01 = 1;
        }
      }
      *_Memory_00 = _Memory_01;
      if (_Memory_01 != (undefined4 *)0x0) {
        *_Memory = FUN_c0993bec;
        _Memory[1] = FUN_c0993a14;
        _Memory[2] = FUN_c09938f0;
        _Memory[3] = _Memory_00;
        _Memory[4] = param_3;
        return _Memory;
      }
      free(_Memory_00);
    }
    free(_Memory);
  }
  return (undefined4 *)0x0;
}



/* c0994004 FUN_c0994004 */

/* Boundary evidence: original MIPS .pdata c0994004..c09940bf. Semantic name remains unreviewed. */

undefined4 FUN_c0994004(int param_1,void *param_2)

{
  int iVar1;
  undefined4 uVar2;
  int local_50;
  int local_4c;
  
  if (param_2 == (void *)0x0) {
    return 0xa0;
  }
  local_4c = *(int *)((int)param_2 + 4);
  local_50 = param_1;
  iVar1 = FUN_c0992c80(&local_50);
  if (iVar1 != 0) {
    uVar2 = FUN_c0991ecc(iVar1);
    return uVar2;
  }
  if ((local_4c != 0x10) && (local_4c != 0x20)) {
    local_50 = 0;
    memcpy(param_2,&local_50,0x48);
    return 0;
  }
  *(int *)((int)param_2 + 4) = local_4c;
  return 0;
}



/* c09940e8 FUN_c09940e8 */

/* Boundary evidence: original MIPS .pdata c09940e8..c0994167. Semantic name remains unreviewed. */

undefined4 FUN_c09940e8(int param_1,int param_2)

{
  undefined4 uVar1;
  
  if (param_2 == 0) {
    return 0xa0;
  }
  if (param_1 != 0) {
    if (*(int *)(param_2 + 4) == 0x50005) {
      *(undefined4 *)(param_2 + 4) = 0x50005;
      *(undefined4 *)(param_2 + 8) = 1;
      return 0;
    }
    *(undefined4 *)(param_2 + 4) = 0x50005;
    *(undefined4 *)(param_2 + 8) = 0;
    return 0;
  }
  uVar1 = FUN_c0991ecc(0xfffffffd);
  return uVar1;
}



/* c0994168 FUN_c0994168 */

/* Boundary evidence: original MIPS .pdata c0994168..c0994227. Semantic name remains unreviewed. */

undefined4 FUN_c0994168(int param_1,int param_2)

{
  undefined4 uVar1;
  void *_Src;
  int iVar2;
  void *_Dst;
  int local_28;
  size_t local_24;
  void *local_20;
  void *local_1c;
  
  if (param_2 == 0) {
    uVar1 = 0xa0;
  }
  else {
    local_24 = *(size_t *)(param_2 + 4);
    _Src = malloc(local_24);
    if (_Src == (void *)0x0) {
      uVar1 = 0xe;
    }
    else {
      _Dst = *(void **)(param_2 + 8);
      local_28 = param_1;
      local_20 = _Src;
      local_1c = _Dst;
      iVar2 = FUN_c0993120(&local_28);
      if (iVar2 == 0) {
        memcpy(_Dst,_Src,local_24);
        free(_Src);
        uVar1 = 0;
      }
      else {
        free(_Src);
        uVar1 = FUN_c0991ecc(iVar2);
      }
    }
  }
  return uVar1;
}



/* c0994228 FUN_c0994228 */

/* Boundary evidence: original MIPS .pdata c0994228..c09942b7. Semantic name remains unreviewed. */

undefined4 FUN_c0994228(int param_1,int param_2)

{
  undefined4 uVar1;
  int *piVar2;
  
  if (param_2 == 0) {
    return 0xa0;
  }
  if (param_1 == 0) {
    uVar1 = FUN_c0991ecc(0xfffffffd);
    return uVar1;
  }
  if ((DAT_c0996190 < 5) && (piVar2 = *(int **)(DAT_c0996190 * 4 + param_1), piVar2 != (int *)0x0))
  {
    *(undefined4 *)(param_2 + 4) = *(undefined4 *)(*piVar2 + 4);
    return 0;
  }
  uVar1 = FUN_c0991ecc(0xffffffff);
  return uVar1;
}



/* c09942b8 FUN_c09942b8 */

/* Boundary evidence: original MIPS .pdata c09942b8..c0994363. Semantic name remains unreviewed. */

undefined4 FUN_c09942b8(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  undefined4 local_c;
  
  if (param_2 == 0) {
    return 0xa0;
  }
  if (param_1 == 0) {
    iVar1 = -3;
  }
  else if ((DAT_c0996190 < 5) &&
          (puVar3 = *(undefined4 **)(DAT_c0996190 * 4 + param_1), puVar3 != (undefined4 *)0x0)) {
    iVar1 = FUN_c098e398(puVar3,&local_c,param_3,param_4);
    if (iVar1 == 0) {
      *(undefined4 *)(param_2 + 4) = local_c;
      return 0;
    }
  }
  else {
    iVar1 = -1;
  }
  uVar2 = FUN_c0991ecc(iVar1);
  return uVar2;
}



/* c0994364 FUN_c0994364 */

/* Boundary evidence: original MIPS .pdata c0994364..c0994437. Semantic name remains unreviewed. */

undefined4 FUN_c0994364(int param_1,void *param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  int local_120 [63];
  undefined4 local_24;
  undefined4 local_20;
  
  if (param_2 == (void *)0x0) {
    return 0xa0;
  }
  uVar3 = 0x110;
  memcpy(local_120,param_2,0x110);
  local_120[0] = param_1;
  if (param_1 == 0) {
    iVar1 = -3;
  }
  else if ((DAT_c0996190 < 5) &&
          (piVar2 = *(int **)(DAT_c0996190 * 4 + param_1), piVar2 != (int *)0x0)) {
    iVar1 = FUN_c098e6b0(piVar2,local_120,uVar3,param_4);
    if (iVar1 == 0) {
      *(undefined4 *)((int)param_2 + 0xfc) = local_24;
      *(undefined4 *)((int)param_2 + 0x100) = local_20;
      return 0;
    }
  }
  else {
    iVar1 = -1;
  }
  uVar3 = FUN_c0991ecc(iVar1);
  return uVar3;
}



/* c0994438 FUN_c0994438 */

/* Boundary evidence: original MIPS .pdata c0994438..c099449b. Semantic name remains unreviewed. */

undefined4 FUN_c0994438(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int *piVar1;
  
  if (param_2 == 0) {
    return 0xa0;
  }
  if (((param_1 != 0) && (DAT_c0996190 < 5)) &&
     (piVar1 = *(int **)(DAT_c0996190 * 4 + param_1), piVar1 != (int *)0x0)) {
    FUN_c0990b7c(piVar1,*(char **)(param_2 + 4),param_3,param_4);
  }
  return 0;
}



/* c099449c FUN_c099449c */

/* Boundary evidence: original MIPS .pdata c099449c..c099452b. Semantic name remains unreviewed. */

undefined4 FUN_c099449c(int param_1,int param_2)

{
  undefined4 uVar1;
  int *piVar2;
  
  if (param_2 == 0) {
    return 0xa0;
  }
  if (param_1 == 0) {
    uVar1 = FUN_c0991ecc(0xfffffffd);
    return uVar1;
  }
  if ((DAT_c0996168 < 5) && (piVar2 = *(int **)(DAT_c0996168 * 4 + param_1), piVar2 != (int *)0x0))
  {
    *(undefined4 *)(param_2 + 4) = *(undefined4 *)(*piVar2 + 4);
    return 0;
  }
  uVar1 = FUN_c0991ecc(0xffffffff);
  return uVar1;
}



/* c099452c FUN_c099452c */

/* Boundary evidence: original MIPS .pdata c099452c..c09945ff. Semantic name remains unreviewed. */

undefined4 FUN_c099452c(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  int local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  
  if (param_2 == 0) {
    return 0xa0;
  }
  local_1c = *(undefined4 *)(param_2 + 4);
  local_18 = *(undefined4 *)(param_2 + 8);
  local_14 = *(undefined4 *)(param_2 + 0xc);
  local_10 = *(undefined4 *)(param_2 + 0x10);
  local_20 = param_1;
  if (param_1 == 0) {
    iVar1 = -3;
  }
  else if ((DAT_c0996168 < 5) &&
          (piVar3 = *(int **)(DAT_c0996168 * 4 + param_1), piVar3 != (int *)0x0)) {
    iVar1 = FUN_c098e118(piVar3,&local_20,param_3,param_4);
    if (iVar1 == 0) {
      *(undefined4 *)(param_2 + 4) = local_1c;
      return 0;
    }
  }
  else {
    iVar1 = -1;
  }
  uVar2 = FUN_c0991ecc(iVar1);
  return uVar2;
}



/* c0994600 FUN_c0994600 */

/* Boundary evidence: original MIPS .pdata c0994600..c09946ab. Semantic name remains unreviewed. */

undefined4 FUN_c0994600(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  undefined4 local_c;
  
  if (param_2 == 0) {
    return 0xa0;
  }
  if (param_1 == 0) {
    iVar1 = -3;
  }
  else if ((DAT_c0996168 < 5) &&
          (puVar3 = *(undefined4 **)(DAT_c0996168 * 4 + param_1), puVar3 != (undefined4 *)0x0)) {
    iVar1 = FUN_c098e398(puVar3,&local_c,param_3,param_4);
    if (iVar1 == 0) {
      *(undefined4 *)(param_2 + 4) = local_c;
      return 0;
    }
  }
  else {
    iVar1 = -1;
  }
  uVar2 = FUN_c0991ecc(iVar1);
  return uVar2;
}



/* c09946ac FUN_c09946ac */

/* Boundary evidence: original MIPS .pdata c09946ac..c0994783. Semantic name remains unreviewed. */

undefined4 FUN_c09946ac(int param_1,void *param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  int local_58 [18];
  
  if (param_2 == (void *)0x0) {
    return 0xa0;
  }
  uVar3 = 0x48;
  memcpy(local_58,param_2,0x48);
  local_58[0] = param_1;
  if (param_1 == 0) {
    iVar1 = -3;
  }
  else if ((DAT_c0996168 < 5) &&
          (piVar2 = *(int **)(DAT_c0996168 * 4 + param_1), piVar2 != (int *)0x0)) {
    iVar1 = FUN_c098e6b0(piVar2,local_58,uVar3,param_4);
    if (iVar1 == 0) {
      local_58[0] = 0;
      memcpy(param_2,local_58,0x48);
      return 0;
    }
  }
  else {
    iVar1 = -1;
  }
  uVar3 = FUN_c0991ecc(iVar1);
  return uVar3;
}



/* c0994784 FUN_c0994784 */

/* Boundary evidence: original MIPS .pdata c0994784..c09947e7. Semantic name remains unreviewed. */

undefined4 FUN_c0994784(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int *piVar1;
  
  if (param_2 == 0) {
    return 0xa0;
  }
  if (((param_1 != 0) && (DAT_c0996168 < 5)) &&
     (piVar1 = *(int **)(DAT_c0996168 * 4 + param_1), piVar1 != (int *)0x0)) {
    FUN_c0990b7c(piVar1,*(char **)(param_2 + 4),param_3,param_4);
  }
  return 0;
}



/* c09947e8 FUN_c09947e8 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Boundary evidence: original MIPS .pdata c09947e8..c0994a0f. Semantic name remains unreviewed. */

int FUN_c09947e8(int param_1,int param_2,uint *param_3,undefined4 param_4)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint local_30 [2];
  
  iVar4 = 0;
  uVar5 = local_30[0];
  if (param_1 == 0) {
LAB_c0994948:
    FUN_c098b68c("*******************************************************************************\n"
                 ,param_2,param_3,param_4);
    FUN_c098b68c("MALI PHYSICAL RANGE VALIDATION ERROR!\n",param_2,param_3,param_4);
    FUN_c098b68c("\n",param_2,param_3,param_4);
    FUN_c098b68c("We failed to validate a Mali-Physical range that the user-side wished to map in\n"
                 ,param_2,param_3,param_4);
    FUN_c098b68c("\n",param_2,param_3,param_4);
    FUN_c098b68c("It is likely that the user-side wished to do Direct Rendering, but a suitable\n",
                 param_2,param_3,param_4);
    FUN_c098b68c("address range validation mechanism has not been correctly setup\n",param_2,param_3
                 ,param_4);
    FUN_c098b68c("\n",param_2,param_3,param_4);
    FUN_c098b68c("The range supplied was: phys_base=0x%.8X, size=0x%.8X\n",iVar4,uVar5,param_4);
    FUN_c098b68c("\n",iVar4,uVar5,param_4);
    FUN_c098b68c("Please refer to the ARM Mali Software Integration Guide for more information.\n",
                 iVar4,uVar5,param_4);
    FUN_c098b68c("\n",iVar4,uVar5,param_4);
    FUN_c098b68c("*******************************************************************************\n"
                 ,iVar4,uVar5,param_4);
  }
  else {
    uVar5 = (_DAT_00005b04 - 1U & *(uint *)(param_1 + 4)) + *(int *)(param_1 + 0xc);
    uVar6 = ~(_DAT_00005b04 - 1U) & *(uint *)(param_1 + 4);
    if ((uVar5 == 0) || ((_DAT_00005b04 - 1U & uVar5) != 0)) {
      uVar5 = _DAT_00005b04 + uVar5 & ~(_DAT_00005b04 - 1U);
    }
    LockPages((uVar5 - _DAT_00005b04) + uVar6,_DAT_00005b04,local_30,2);
    uVar2 = uVar5;
    iVar3 = (local_30[0] << (_DAT_00005b08 & 0x1f)) + _DAT_00005b04;
    do {
      uVar2 = uVar2 - _DAT_00005b04;
      param_4 = 2;
      param_3 = local_30;
      param_2 = _DAT_00005b04;
      iVar1 = LockPages(uVar2 + uVar6);
      if ((iVar1 == 0) ||
         (iVar4 = local_30[0] << (_DAT_00005b08 & 0x1f), _DAT_00005b04 + iVar4 != iVar3))
      goto LAB_c0994948;
      iVar3 = iVar4;
    } while (uVar2 != 0);
    uVar2 = iVar4 - DAT_c0996608;
    if (((uVar2 & 0xfff) == 0) && ((uVar5 & 0xfff) == 0)) {
      iVar4 = FUN_c0992a10(uVar2,uVar5,param_3,param_4);
      if (iVar4 != 0) {
        return iVar4;
      }
      *(uint *)(param_1 + 0xc) = uVar5;
      *(uint *)(param_1 + 8) = uVar2;
      *(uint *)(param_1 + 4) = uVar6;
      return 0;
    }
  }
  return -1;
}



/* c0994a10 FUN_c0994a10 */

/* Boundary evidence: original MIPS .pdata c0994a10..c0994a3f. Semantic name remains unreviewed. */

undefined4 FUN_c0994a10(undefined4 param_1,int param_2)

{
  undefined4 uVar1;
  
  if (param_2 == 0) {
    return 0xa0;
  }
  uVar1 = FUN_c0991ecc(0xffffffff);
  return uVar1;
}



/* c0994a40 FUN_c0994a40 */

/* Boundary evidence: original MIPS .pdata c0994a40..c0994a6f. Semantic name remains unreviewed. */

undefined4 FUN_c0994a40(undefined4 param_1,int param_2)

{
  undefined4 uVar1;
  
  if (param_2 == 0) {
    return 0xa0;
  }
  uVar1 = FUN_c0991ecc(0xffffffff);
  return uVar1;
}



/* c0994a70 FUN_c0994a70 */

/* Boundary evidence: original MIPS .pdata c0994a70..c0994ab7. Semantic name remains unreviewed. */

undefined4 FUN_c0994a70(int param_1,int param_2)

{
  undefined4 uVar1;
  
  if (param_2 == 0) {
    return 0xa0;
  }
  if (param_1 == 0) {
    uVar1 = FUN_c0991ecc(0xfffffffd);
    return uVar1;
  }
  return 0;
}



/* c0994ab8 FUN_c0994ab8 */

/* Boundary evidence: original MIPS .pdata c0994ab8..c0994b0f. Semantic name remains unreviewed. */

undefined4 FUN_c0994ab8(int param_1,int param_2)

{
  undefined4 uVar1;
  
  if (param_2 == 0) {
    return 0xa0;
  }
  if (param_1 == 0) {
    uVar1 = FUN_c0991ecc(0xfffffffd);
    return uVar1;
  }
  *(undefined4 *)(param_2 + 4) = 0x40000000;
  *(undefined4 *)(param_2 + 8) = 0x80000000;
  return 0;
}



/* c0994b10 FUN_c0994b10 */

/* Boundary evidence: original MIPS .pdata c0994b10..c0994bbb. Semantic name remains unreviewed. */

undefined4 FUN_c0994b10(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  int local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  
  local_24 = 0;
  local_18 = 0;
  local_14 = 0;
  local_10 = 0;
  if (param_2 == 0) {
    return 0xa0;
  }
  local_20 = *(undefined4 *)(param_2 + 8);
  local_1c = *(undefined4 *)(param_2 + 0xc);
  local_28 = param_1;
  iVar1 = FUN_c0984d90(&local_28);
  if (iVar1 != 0) {
    uVar2 = FUN_c0991ecc(iVar1);
    return uVar2;
  }
  *(undefined4 *)(param_2 + 4) = local_24;
  *(undefined4 *)(param_2 + 0x10) = local_18;
  return 0;
}



/* c0994bbc FUN_c0994bbc */

/* Boundary evidence: original MIPS .pdata c0994bbc..c0994cef. Semantic name remains unreviewed. */

undefined4 FUN_c0994bbc(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  int local_30;
  int local_2c;
  int local_28;
  undefined4 local_24;
  int local_20;
  undefined4 local_1c;
  int local_18;
  
  uVar2 = 0;
  if (param_2 == 0) {
    uVar2 = 0xa0;
  }
  else {
    local_2c = *(int *)(param_2 + 4);
    if (local_2c == 0) {
      uVar2 = 0xe;
    }
    else {
      local_28 = 0;
      iVar1 = CeOpenCallerBuffer(&local_28,*(undefined4 *)(param_2 + 8),local_2c,8,0);
      if (iVar1 < 0) {
        uVar2 = 0x1f;
      }
      else {
        local_30 = param_1;
        iVar1 = FUN_c09854a0(&local_30);
        if (iVar1 == 0) {
          iVar1 = CeCloseCallerBuffer(local_28,*(undefined4 *)(param_2 + 8),
                                      *(undefined4 *)(param_2 + 4),8);
          if (iVar1 < 0) {
            uVar2 = 0x1f;
          }
          else {
            *(int *)(param_2 + 0x10) = (local_20 - local_28 >> 2) * 4 + *(int *)(param_2 + 8);
            *(int *)(param_2 + 0x18) = (local_18 - local_28 >> 2) * 4 + *(int *)(param_2 + 8);
            *(undefined4 *)(param_2 + 0xc) = local_24;
            *(undefined4 *)(param_2 + 0x14) = local_1c;
          }
        }
        else {
          uVar2 = FUN_c0991ecc(iVar1);
        }
      }
      if (local_28 != 0) {
        CeCloseCallerBuffer(local_28,*(undefined4 *)(param_2 + 8),*(undefined4 *)(param_2 + 4),8);
      }
    }
  }
  return uVar2;
}



/* c0994cf0 FUN_c0994cf0 */

/* Boundary evidence: original MIPS .pdata c0994cf0..c0994d63. Semantic name remains unreviewed. */

undefined4 FUN_c0994cf0(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  int local_10;
  undefined4 local_c;
  
  if (param_2 == 0) {
    return 0xa0;
  }
  local_10 = param_1;
  iVar1 = FUN_c0985580(&local_10);
  if (iVar1 != 0) {
    uVar2 = FUN_c0991ecc(iVar1);
    return uVar2;
  }
  *(undefined4 *)(param_2 + 4) = local_c;
  return 0;
}



/* c0994d64 FUN_c0994d64 */

/* Boundary evidence: original MIPS .pdata c0994d64..c0994dd7. Semantic name remains unreviewed. */

undefined4 FUN_c0994d64(undefined4 param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  
  if (param_2 == 0) {
    return 0xa0;
  }
  local_14 = *(undefined4 *)(param_2 + 4);
  local_10 = *(undefined4 *)(param_2 + 8);
  local_c = *(undefined4 *)(param_2 + 0xc);
  local_18 = param_1;
  iVar1 = FUN_c0985638((int)&local_18);
  if (iVar1 != 0) {
    uVar2 = FUN_c0991ecc(iVar1);
    return uVar2;
  }
  return 0;
}



/* c0994dd8 FUN_c0994dd8 */

/* Boundary evidence: original MIPS .pdata c0994dd8..c0994e33. Semantic name remains unreviewed. */

undefined4 FUN_c0994dd8(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  int local_10;
  undefined4 local_c;
  
  if (param_2 == 0) {
    return 0xa0;
  }
  local_c = *(undefined4 *)(param_2 + 4);
  local_10 = param_1;
  iVar1 = FUN_c098604c(&local_10);
  if (iVar1 != 0) {
    uVar2 = FUN_c0991ecc(iVar1);
    return uVar2;
  }
  return 0;
}



/* c0994e34 FUN_c0994e34 */

/* Boundary evidence: original MIPS .pdata c0994e34..c0994ed7. Semantic name remains unreviewed. */

undefined4 FUN_c0994e34(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  int local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  
  if (param_2 == 0) {
    return 0xa0;
  }
  local_1c = *(undefined4 *)(param_2 + 4);
  local_18 = *(undefined4 *)(param_2 + 8);
  local_14 = *(undefined4 *)(param_2 + 0xc);
  local_10 = *(undefined4 *)(param_2 + 0x10);
  local_c = *(undefined4 *)(param_2 + 0x14);
  local_20 = param_1;
  iVar1 = FUN_c098611c(&local_20,param_2,param_3,param_4);
  if (iVar1 != 0) {
    uVar2 = FUN_c0991ecc(iVar1);
    return uVar2;
  }
  *(undefined4 *)(param_2 + 0x14) = local_c;
  return 0;
}


