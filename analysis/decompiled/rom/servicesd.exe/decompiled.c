/* Automatic Ghidra pseudocode. Not original source; not runtime-verified. */

/* 00011558 FUN_00011558 */

/* Boundary evidence: original MIPS .pdata 00011558..000115eb. Semantic name remains unreviewed. */

void FUN_00011558(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  UINT UVar1;
  
  FUN_00011868();
  UVar1 = FUN_00012850(param_1,param_2,param_3);
  FUN_000117a8(UVar1);
  FUN_000117c8(UVar1);
  return;
}



/* 000115ec FUN_000115ec */

/* Boundary evidence: original MIPS .pdata 000115ec..0001162b. Semantic name remains unreviewed. */

void FUN_000115ec(_EXCEPTION_POINTERS *param_1)

{
  int in_v0;
  
  *(DWORD *)(in_v0 + -0x20) = param_1->ExceptionRecord->ExceptionCode;
  _XcptFilter(*(ulong *)(in_v0 + -0x20),param_1);
  return;
}



/* 0001162c entry */

/* Boundary evidence: original MIPS .pdata 0001162c..00011687. Semantic name remains unreviewed. */

void entry(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_000118a4();
  FUN_00011558(param_1,param_2,param_3);
  return;
}



/* 00011688 FUN_00011688 */

/* Boundary evidence: original MIPS .pdata 00011688..000117a7. Semantic name remains unreviewed. */

void FUN_00011688(UINT param_1,int param_2,int param_3)

{
  LPCRITICAL_SECTION lpCriticalSection;
  undefined4 *_Memory;
  
  DAT_00019140 = (undefined1)param_3;
  if (param_2 == 0) {
    _Memory = DAT_00019380;
    if (DAT_00019380 != (undefined4 *)0x0) {
      while (DAT_0001937c = DAT_0001937c + -1, _Memory <= DAT_0001937c) {
        if ((code *)*DAT_0001937c != (code *)0x0) {
          (*(code *)*DAT_0001937c)();
          _Memory = DAT_00019380;
        }
      }
      free(_Memory);
      DAT_0001937c = (undefined4 *)0x0;
      DAT_00019380 = (undefined4 *)0x0;
    }
    FUN_00011814((undefined4 *)&DAT_00011014,(undefined4 *)&DAT_00011018);
  }
  FUN_00011814((undefined4 *)&DAT_0001101c,(undefined4 *)&DAT_00011020);
  if (param_3 == 0) {
    TerminateProcess((HANDLE)0x42,param_1);
  }
  else {
    lpCriticalSection = (LPCRITICAL_SECTION)InterlockedExchange(&DAT_00019384,0);
    if (lpCriticalSection != (LPCRITICAL_SECTION)0x0) {
      DeleteCriticalSection(lpCriticalSection);
      free(lpCriticalSection);
    }
  }
  return;
}



/* 000117a8 FUN_000117a8 */

/* Boundary evidence: original MIPS .pdata 000117a8..000117c7. Semantic name remains unreviewed. */

void FUN_000117a8(UINT param_1)

{
  FUN_00011688(param_1,0,0);
  return;
}



/* 000117c8 FUN_000117c8 */

/* Boundary evidence: original MIPS .pdata 000117c8..00011813. Semantic name remains unreviewed. */

void FUN_000117c8(UINT param_1)

{
  DAT_00019140 = 0;
  FUN_00011814((undefined4 *)&DAT_0001101c,(undefined4 *)&DAT_00011020);
  TerminateProcess((HANDLE)0x42,param_1);
  return;
}



/* 00011814 FUN_00011814 */

/* Boundary evidence: original MIPS .pdata 00011814..00011867. Semantic name remains unreviewed. */

void FUN_00011814(undefined4 *param_1,undefined4 *param_2)

{
  for (; param_1 < param_2; param_1 = param_1 + 1) {
    if ((code *)*param_1 != (code *)0x0) {
      (*(code *)*param_1)();
    }
  }
  return;
}



/* 00011868 FUN_00011868 */

/* Boundary evidence: original MIPS .pdata 00011868..000118a3. Semantic name remains unreviewed. */

void FUN_00011868(void)

{
  FUN_00011814((undefined4 *)&DAT_0001100c,(undefined4 *)&DAT_00011010);
  FUN_00011814((undefined4 *)&DAT_00011000,(undefined4 *)&DAT_00011008);
  return;
}



/* 000118a4 FUN_000118a4 */

/* Boundary evidence: original MIPS .pdata 000118a4..00011917. Semantic name remains unreviewed. */

void FUN_000118a4(void)

{
  uint uVar1;
  
  if ((DAT_00019118 == 0) || (DAT_00019118 == 0xb064)) {
    uVar1 = __security_gen_cookie2();
    DAT_00019118 = uVar1 >> 0x10 ^ uVar1 & 0xffff;
    if (DAT_00019118 == 0) {
      DAT_00019118 = 0xb064;
    }
  }
  DAT_0001911c = ~DAT_00019118;
  return;
}



/* 00011918 FUN_00011918 */

/* Boundary evidence: original MIPS .pdata 00011918..00011a23. Semantic name remains unreviewed. */

undefined4 FUN_00011918(undefined4 param_1)

{
  void *_Memory;
  uint uVar1;
  void *pvVar2;
  uint _NewSize;
  undefined4 *puVar3;
  int iVar4;
  
  _Memory = DAT_00019380;
  puVar3 = DAT_0001937c;
  iVar4 = (int)DAT_0001937c - (int)DAT_00019380;
  uVar1 = 0;
  if (iVar4 < 0) {
LAB_0001195c:
    param_1 = 0;
  }
  else {
    if (DAT_00019380 != (void *)0x0) {
      uVar1 = _msize(DAT_00019380);
    }
    pvVar2 = _Memory;
    if (uVar1 < iVar4 + 4U) {
      if (_Memory == (void *)0x0) {
        pvVar2 = malloc(0x10);
LAB_000119d0:
        if (pvVar2 == (void *)0x0) goto LAB_0001195c;
      }
      else {
        _NewSize = uVar1 << 1;
        if (0x200 < uVar1) {
          _NewSize = uVar1 + 0x200;
        }
        if ((_NewSize <= uVar1) || (pvVar2 = realloc(_Memory,_NewSize), pvVar2 == (void *)0x0)) {
          pvVar2 = realloc(_Memory,iVar4 + 4U);
          goto LAB_000119d0;
        }
      }
      puVar3 = (undefined4 *)((iVar4 >> 2) * 4 + (int)pvVar2);
    }
    DAT_0001937c = puVar3 + 1;
    *puVar3 = param_1;
    DAT_00019380 = pvVar2;
  }
  return param_1;
}



/* 00011a24 FUN_00011a24 */

/* Boundary evidence: original MIPS .pdata 00011a24..00011b0f. Semantic name remains unreviewed. */

undefined4 FUN_00011a24(undefined4 param_1)

{
  LPCRITICAL_SECTION lpCriticalSection;
  LONG LVar1;
  undefined4 uVar2;
  
  if (DAT_00019384 == (LPCRITICAL_SECTION)0x0) {
    lpCriticalSection = malloc(0x14);
    if (lpCriticalSection != (LPCRITICAL_SECTION)0x0) {
      InitializeCriticalSection(lpCriticalSection);
      LVar1 = InterlockedCompareExchange((LONG *)&DAT_00019384,(LONG)lpCriticalSection,0);
      if (LVar1 != 0) {
        DeleteCriticalSection(lpCriticalSection);
        free(lpCriticalSection);
      }
    }
    if (DAT_00019384 == (LPCRITICAL_SECTION)0x0) goto LAB_00011ac8;
  }
  EnterCriticalSection(DAT_00019384);
LAB_00011ac8:
  uVar2 = FUN_00011918(param_1);
  FUN_00011b10();
  return uVar2;
}



/* 00011b10 FUN_00011b10 */

/* Boundary evidence: original MIPS .pdata 00011b10..00011b5b. Semantic name remains unreviewed. */

void FUN_00011b10(void)

{
  if (DAT_00019384 != (LPCRITICAL_SECTION)0x0) {
    LeaveCriticalSection(DAT_00019384);
  }
  return;
}



/* 00011b5c FUN_00011b5c */

/* Boundary evidence: original MIPS .pdata 00011b5c..00011b8b. Semantic name remains unreviewed. */

undefined4 FUN_00011b5c(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_00011a24(param_1);
  if (iVar1 == 0) {
    uVar2 = 0xffffffff;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}



/* 00011c6c FUN_00011c6c */

/* Boundary evidence: original MIPS .pdata 00011c6c..00011cbb. Semantic name remains unreviewed. */

void FUN_00011c6c(undefined4 *param_1)

{
  if ((HKEY)*param_1 != (HKEY)0x0) {
    RegCloseKey((HKEY)*param_1);
  }
  if ((HLOCAL)param_1[2] != (HLOCAL)0x0) {
    LocalFree((HLOCAL)param_1[2]);
  }
  return;
}



/* 00011cbc FUN_00011cbc */

/* Boundary evidence: original MIPS .pdata 00011cbc..00011d17. Semantic name remains unreviewed. */

undefined4 FUN_00011cbc(undefined4 *param_1,LPCWSTR param_2,LPBYTE param_3,int param_4)

{
  LSTATUS LVar1;
  DWORD local_resc;
  
  if ((HKEY)*param_1 != (HKEY)0x0) {
    local_resc = param_4 << 1;
    LVar1 = RegQueryValueExW((HKEY)*param_1,param_2,(LPDWORD)0x0,(LPDWORD)0x0,param_3,&local_resc);
    if (LVar1 == 0) {
      return 1;
    }
  }
  return 0;
}



/* 00011d18 FUN_00011d18 */

/* Boundary evidence: original MIPS .pdata 00011d18..00011d6b. Semantic name remains unreviewed. */

undefined4 FUN_00011d18(undefined4 *param_1,LPCWSTR param_2,undefined4 param_3)

{
  undefined4 local_10;
  DWORD local_c;
  
  if ((HKEY)*param_1 != (HKEY)0x0) {
    local_c = 4;
    local_10 = param_3;
    RegQueryValueExW((HKEY)*param_1,param_2,(LPDWORD)0x0,(LPDWORD)0x0,(LPBYTE)&local_10,&local_c);
    param_3 = local_10;
  }
  return param_3;
}



/* 00011d6c FUN_00011d6c */

/* Boundary evidence: original MIPS .pdata 00011d6c..00011dd3. Semantic name remains unreviewed. */

undefined4 FUN_00011d6c(int *param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0x800700b7;
  if (param_1[1] != 0) {
    if (*param_1 != 0) {
      CeFreeAsynchronousBuffer(*param_1,param_1[1],param_1[3],param_1[4]);
    }
    uVar1 = CeCloseCallerBuffer(param_1[1],param_1[2],param_1[3],param_1[4]);
    param_1[1] = 0;
    *param_1 = 0;
    param_1[3] = 0;
  }
  return uVar1;
}



/* 00011dd4 FUN_00011dd4 */

/* Boundary evidence: original MIPS .pdata 00011dd4..00011e2f. Semantic name remains unreviewed. */

LONG FUN_00011dd4(undefined4 *param_1)

{
  LONG LVar1;
  
  LVar1 = InterlockedDecrement(param_1 + 1);
  if ((LVar1 < 1) && (param_1 != (undefined4 *)0x0)) {
    (**(code **)*param_1)(param_1,1);
  }
  return LVar1;
}



/* 00011e30 FUN_00011e30 */

/* Boundary evidence: original MIPS .pdata 00011e30..00011e4b. Semantic name remains unreviewed. */

void FUN_00011e30(int param_1)

{
  FUN_000169d8(param_1);
  return;
}



/* 00011e4c FUN_00011e4c */

/* Boundary evidence: original MIPS .pdata 00011e4c..00011ea3. Semantic name remains unreviewed. */

undefined4 * FUN_00011e4c(undefined4 *param_1,uint param_2)

{
  *param_1 = &PTR_FUN_00011060;
  FUN_00016c10(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}



/* 00011ea4 FUN_00011ea4 */

/* Boundary evidence: original MIPS .pdata 00011ea4..00011f5b. Semantic name remains unreviewed. */

undefined4 FUN_00011ea4(void)

{
  LPCRITICAL_SECTION lpCriticalSection;
  
  FUN_0001565c();
  lpCriticalSection = operator_new(0x14);
  if (lpCriticalSection == (LPCRITICAL_SECTION)0x0) {
    lpCriticalSection = (LPCRITICAL_SECTION)0x0;
  }
  else {
    InitializeCriticalSection(lpCriticalSection);
  }
  DAT_00019148 = lpCriticalSection;
  if ((lpCriticalSection != (LPCRITICAL_SECTION)0x0) &&
     (DAT_00019144 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,1,0,(LPCWSTR)0x0),
     DAT_00019144 != (HANDLE)0x0)) {
    FUN_00014014();
    FUN_00013988();
    FUN_00013464();
    DAT_0001914c = 1;
    return 1;
  }
  return 0;
}



/* 00011f5c FUN_00011f5c */

/* Boundary evidence: original MIPS .pdata 00011f5c..00011fe3. Semantic name remains unreviewed. */

undefined4 * FUN_00011f5c(void *param_1)

{
  undefined4 *puVar1;
  
  if ((*(uint *)((int)param_1 + 4) & 0xfffeffc8) == 0) {
    *(uint *)((int)param_1 + 4) = *(uint *)((int)param_1 + 4) | 2;
    puVar1 = operator_new(0x6ac);
    if (puVar1 != (undefined4 *)0x0) {
      FUN_0001578c(puVar1,param_1,0);
      *puVar1 = &PTR_FUN_00011060;
      *(undefined2 *)(puVar1 + 0x9f) = 0;
      return puVar1;
    }
  }
  return (undefined4 *)0x0;
}



/* 00011fe4 FUN_00011fe4 */

/* Boundary evidence: original MIPS .pdata 00011fe4..000120a7. Semantic name remains unreviewed. */

undefined4 FUN_00011fe4(LPTHREAD_START_ROUTINE param_1,LPVOID param_2)

{
  HANDLE hHandle;
  undefined4 uVar1;
  BOOL BVar2;
  DWORD local_10 [2];
  
  hHandle = CreateThread((LPSECURITY_ATTRIBUTES)0x0,0,param_1,param_2,0,(LPDWORD)0x0);
  if (hHandle == (HANDLE)0x0) {
    uVar1 = 0x425;
  }
  else {
    WaitForSingleObject(hHandle,0xffffffff);
    BVar2 = GetExitCodeThread(hHandle,local_10);
    if (BVar2 == 0) {
      local_10[0] = 0x425;
    }
    if (local_10[0] != 0) {
      SetLastError(local_10[0]);
    }
    CloseHandle(hHandle);
    uVar1 = 1;
    if (local_10[0] != 0) {
      uVar1 = 0;
    }
  }
  return uVar1;
}



/* 000120a8 FUN_000120a8 */

/* Boundary evidence: original MIPS .pdata 000120a8..0001212f. Semantic name remains unreviewed. */

bool FUN_000120a8(int param_1,wchar_t *param_2,uint param_3)

{
  bool bVar1;
  size_t sVar2;
  
  sVar2 = wcslen((wchar_t *)(param_1 + 0x27c));
  bVar1 = sVar2 + 8 < param_3;
  if (bVar1) {
    wcscpy(param_2,(wchar_t *)(param_1 + 0x27c));
    wcscpy(param_2 + sVar2,L"\\Accept");
  }
  return bVar1;
}



/* 00012130 FUN_00012130 */

/* Boundary evidence: original MIPS .pdata 00012130..0001215b. Semantic name remains unreviewed. */

undefined4 FUN_00012130(int *param_1)

{
  (**(code **)(*param_1 + 0x40))();
  return 0;
}



/* 0001215c FUN_0001215c */

/* Boundary evidence: original MIPS .pdata 0001215c..00012287. Semantic name remains unreviewed. */

undefined4 FUN_0001215c(undefined4 *param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  FUN_00015848((int)param_1,(LPCWSTR)(param_1 + 0x126));
  iVar1 = (*(code *)param_1[0x8f])(param_1[0x121],param_1[0x125]);
  param_1[0x9b] = iVar1;
  if (iVar1 == 0) {
    if ((HANDLE)param_1[0x9c] != (HANDLE)0x0) {
      CloseHandle((HANDLE)param_1[0x9c]);
      param_1[0x9c] = 0;
    }
    uVar2 = 0x425;
  }
  else {
    EnterCriticalSection(DAT_00019148);
    FUN_00013404();
    FUN_00013d40();
    if ((param_1[0x121] & 1) != 0) {
      FUN_00015150(param_1,1,1);
    }
    LeaveCriticalSection(DAT_00019148);
    uVar2 = 0;
  }
  return uVar2;
}



/* 00012288 FUN_00012288 */

/* Boundary evidence: original MIPS .pdata 00012288..00012293. Semantic name remains unreviewed. */

undefined4 FUN_00012288(void)

{
  return 1;
}



/* 00012294 FUN_00012294 */

/* Boundary evidence: original MIPS .pdata 00012294..0001230b. Semantic name remains unreviewed. */

undefined4 FUN_00012294(undefined4 *param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_00015a64((int)param_1);
  uVar2 = 0;
  if (iVar1 == 0) {
    uVar2 = 0x425;
  }
  EnterCriticalSection(DAT_00019148);
  if ((param_1[0x121] & 1) != 0) {
    FUN_00014bf4(param_1,1);
  }
  LeaveCriticalSection(DAT_00019148);
  return uVar2;
}



/* 0001230c FUN_0001230c */

/* Boundary evidence: original MIPS .pdata 0001230c..0001232f. Semantic name remains unreviewed. */

void FUN_0001230c(LPVOID param_1)

{
  FUN_00011fe4(FUN_00012130,param_1);
  return;
}



/* 00012330 FUN_00012330 */

/* Boundary evidence: original MIPS .pdata 00012330..00012473. Semantic name remains unreviewed. */

uint FUN_00012330(int *param_1,undefined4 *param_2)

{
  bool bVar1;
  int iVar2;
  undefined3 extraout_var;
  uint uVar3;
  int iVar4;
  
  iVar4 = param_2[2];
  iVar2 = (**(code **)(*param_1 + 0x24))(param_1,param_2[1]);
  if (iVar2 == 0) {
    SetLastError(0x57);
    uVar3 = 0;
  }
  else if (iVar4 == 0x1040fa0) {
    uVar3 = FUN_000153d0(param_1,(int)param_2);
  }
  else if (iVar4 == 0x1040fa4) {
    uVar3 = FUN_00014d28(param_1,(int)param_2);
  }
  else if (iVar4 == 0x1040fa8) {
    bVar1 = FUN_00014e38(param_1);
    uVar3 = CONCAT31(extraout_var,bVar1);
  }
  else {
    uVar3 = FUN_00016608(param_1,param_2);
    if (uVar3 != 0) {
      if (((param_1[0x121] & 1U) != 0) && (iVar4 == 0x1040008)) {
        FUN_00014bf4(param_1,0);
      }
      if (((param_1[0x121] & 1U) != 0) && (iVar4 == 0x1040004)) {
        FUN_00015150(param_1,0,0);
      }
    }
  }
  return uVar3;
}



/* 0001247c FUN_0001247c */

/* Boundary evidence: original MIPS .pdata 0001247c..0001257f. Semantic name remains unreviewed. */

undefined4
FUN_0001247c(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,undefined4 param_6)

{
  undefined4 uVar1;
  undefined1 auStack_24 [4];
  
  InterlockedIncrement(param_1 + 1);
  LeaveCriticalSection(DAT_00019148);
  uVar1 = (*(code *)param_1[0x98])(param_1[0x9b],param_2,param_3,param_4,param_5,param_6,auStack_24)
  ;
  EnterCriticalSection(DAT_00019148);
  FUN_00011dd4(param_1);
  return uVar1;
}



/* 00012580 FUN_00012580 */

/* Boundary evidence: original MIPS .pdata 00012580..0001258b. Semantic name remains unreviewed. */

undefined4 FUN_00012580(void)

{
  return 1;
}



/* 0001258c FUN_0001258c */

/* Boundary evidence: original MIPS .pdata 0001258c..000125cb. Semantic name remains unreviewed. */

bool FUN_0001258c(int param_1)

{
  bool bVar1;
  
  bVar1 = (*(uint *)(param_1 + 0x484) & 1) == 0;
  if (bVar1) {
    SetLastError(0x425);
  }
  return !bVar1;
}



/* 000125cc FUN_000125cc */

/* Boundary evidence: original MIPS .pdata 000125cc..00012633. Semantic name remains unreviewed. */

void * FUN_000125cc(int param_1,int param_2)

{
  void *pvVar1;
  
  pvVar1 = operator_new(0xc);
  if (pvVar1 == (void *)0x0) {
    pvVar1 = (void *)0x0;
  }
  else {
    *(int *)((int)pvVar1 + 4) = param_2;
    *(undefined4 *)((int)pvVar1 + 8) = *(undefined4 *)(param_2 + 8);
    *(void **)(*(int *)(param_2 + 8) + 4) = pvVar1;
    *(void **)(param_2 + 8) = pvVar1;
    *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + 1;
  }
  return pvVar1;
}



/* 00012634 FUN_00012634 */

/* Boundary evidence: original MIPS .pdata 00012634..000126cb. Semantic name remains unreviewed. */

bool FUN_00012634(PHKEY param_1,HKEY param_2,LPCWSTR param_3,REGSAM param_4)

{
  LSTATUS LVar1;
  
  if (*param_1 != (HKEY)0x0) {
    RegCloseKey(*param_1);
    *param_1 = (HKEY)0x0;
  }
  param_1[1] = (HKEY)0x0;
  LVar1 = RegOpenKeyExW(param_2,param_3,0,param_4,param_1);
  return LVar1 == 0;
}



/* 000126cc FUN_000126cc */

/* Boundary evidence: original MIPS .pdata 000126cc..0001279f. Semantic name remains unreviewed. */

int FUN_000126cc(int *param_1,int param_2,int param_3,int param_4,undefined4 param_5,int param_6)

{
  int iVar1;
  int *piVar2;
  
  piVar2 = param_1 + 1;
  iVar1 = -0x7ff8ff49;
  if (*piVar2 == 0) {
    iVar1 = CeOpenCallerBuffer(piVar2,param_2,param_3,param_4,param_5);
    if (-1 < iVar1) {
      *param_1 = 0;
      param_1[2] = param_2;
      param_1[3] = param_3;
      param_1[4] = param_4;
      if ((param_6 != 0) &&
         (iVar1 = CeAllocAsynchronousBuffer(param_1,*piVar2,param_3,param_4), iVar1 < 0)) {
        FUN_00011d6c(param_1);
      }
    }
  }
  return iVar1;
}



/* 000127a0 FUN_000127a0 */

/* Boundary evidence: original MIPS .pdata 000127a0..0001284f. Semantic name remains unreviewed. */

void FUN_000127a0(void)

{
  LPCRITICAL_SECTION p_Var1;
  
  DAT_0001914c = 0;
  if (DAT_00019144 != 0) {
    EventModify(DAT_00019144,3);
  }
  FUN_00013304();
  FUN_00013a08();
  FUN_00015594();
  if (DAT_00019144 != 0) {
    CloseHandle((HANDLE)DAT_00019144);
    DAT_00019144 = 0;
  }
  p_Var1 = DAT_00019148;
  if (DAT_00019148 != (LPCRITICAL_SECTION)0x0) {
    DeleteCriticalSection(DAT_00019148);
    operator_delete(p_Var1);
    DAT_00019148 = (LPCRITICAL_SECTION)0x0;
  }
  FUN_0001565c();
  return;
}



/* 00012850 FUN_00012850 */

/* Boundary evidence: original MIPS .pdata 00012850..000128a7. Semantic name remains unreviewed. */

undefined4 FUN_00012850(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  
  iVar1 = FUN_00011ea4();
  if ((iVar1 != 0) && (iVar1 = FUN_00017de4(param_3), iVar1 != 0)) {
    FUN_00016da8(0xffffffff);
  }
  FUN_00017fac();
  FUN_000127a0();
  return 0xffffffff;
}



/* 000128a8 FUN_000128a8 */

/* Boundary evidence: original MIPS .pdata 000128a8..0001298f. Semantic name remains unreviewed. */

undefined4 FUN_000128a8(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  LPBYTE pBVar3;
  HKEY local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  
  if (*(short *)(param_1 + 0x27c) == 0) {
    local_20 = (HKEY)0x0;
    local_1c = 0;
    local_18 = 0;
    local_14 = 0;
    FUN_00012634(&local_20,(HKEY)0x80000002,(LPCWSTR)(param_2 + 0x10),0x20019);
    if (local_20 != (HKEY)0x0) {
      iVar1 = FUN_00011cbc(&local_20,L"Key",(LPBYTE)(param_1 + 0x27c),0x104);
      if (iVar1 == 0) {
        uVar2 = 0;
      }
      else {
        pBVar3 = (LPBYTE)(param_1 + 0x6a0);
        iVar1 = FUN_00011cbc(&local_20,L"Name",pBVar3,6);
        if (iVar1 == 0) {
          pBVar3[0] = '\0';
          pBVar3[1] = '\0';
        }
        uVar2 = 1;
      }
      FUN_00011c6c(&local_20);
      return uVar2;
    }
    FUN_00011c6c(&local_20);
  }
  return 0;
}



/* 00012990 FUN_00012990 */

/* Boundary evidence: original MIPS .pdata 00012990..000129ab. Semantic name remains unreviewed. */

void FUN_00012990(undefined4 *param_1)

{
  FUN_0001215c(param_1);
  return;
}



/* 000129ac FUN_000129ac */

/* Boundary evidence: original MIPS .pdata 000129ac..000129c7. Semantic name remains unreviewed. */

void FUN_000129ac(undefined4 *param_1)

{
  FUN_00012294(param_1);
  return;
}



/* 000129c8 FUN_000129c8 */

/* Boundary evidence: original MIPS .pdata 000129c8..000129f7. Semantic name remains unreviewed. */

undefined4 FUN_000129c8(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_000169d8(param_1);
  if (iVar1 == 0) {
    uVar2 = 0x54f;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}



/* 000129f8 FUN_000129f8 */

/* Boundary evidence: original MIPS .pdata 000129f8..00012a1b. Semantic name remains unreviewed. */

void FUN_000129f8(LPVOID param_1)

{
  FUN_00011fe4(FUN_000129c8,param_1);
  return;
}



/* 00012a1c FUN_00012a1c */

/* Boundary evidence: original MIPS .pdata 00012a1c..00012ad7. Semantic name remains unreviewed. */

undefined4 FUN_00012a1c(LPVOID param_1,void *param_2)

{
  int iVar1;
  undefined4 uVar2;
  HKEY local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  
  iVar1 = FUN_000128a8((int)param_1,(int)param_2);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    local_20 = (HKEY)0x0;
    local_1c = 0;
    local_18 = 0;
    local_14 = 0;
    FUN_00012634(&local_20,(HKEY)0x80000002,(LPCWSTR)((int)param_1 + 0x27c),0x20019);
    uVar2 = FUN_00011d18(&local_20,L"ServiceContext",0);
    *(undefined4 *)((int)param_1 + 0x484) = uVar2;
    memcpy((void *)((int)param_1 + 0x488),param_2,0x218);
    uVar2 = FUN_00011fe4(FUN_00012990,param_1);
    FUN_00011c6c(&local_20);
  }
  return uVar2;
}



/* 00012ad8 FUN_00012ad8 */

/* Boundary evidence: original MIPS .pdata 00012ad8..00012afb. Semantic name remains unreviewed. */

void FUN_00012ad8(LPVOID param_1)

{
  FUN_00011fe4(FUN_000129ac,param_1);
  return;
}



/* 00012afc FUN_00012afc */

/* Boundary evidence: original MIPS .pdata 00012afc..00012b67. Semantic name remains unreviewed. */

undefined4 * FUN_00012afc(int param_1,undefined4 *param_2,void *param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = *(undefined4 *)((int)param_3 + 4);
  *(undefined4 *)(*(int *)((int)param_3 + 8) + 4) = uVar2;
  *(undefined4 *)(*(int *)((int)param_3 + 4) + 8) = *(undefined4 *)((int)param_3 + 8);
  operator_delete(param_3);
  iVar1 = *(int *)(param_1 + 0xc);
  *param_2 = uVar2;
  *(int *)(param_1 + 0xc) = iVar1 + -1;
  return param_2;
}



/* 00012b68 FUN_00012b68 */

/* Boundary evidence: original MIPS .pdata 00012b68..00012bc7. Semantic name remains unreviewed. */

undefined * FUN_00012b68(void)

{
  if ((DAT_00019164 & 1) == 0) {
    DAT_00019164 = DAT_00019164 | 1;
    InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_00019150);
    FUN_00011b5c(FUN_00018340);
  }
  return &DAT_00019150;
}



/* 00012bc8 FUN_00012bc8 */

/* Boundary evidence: original MIPS .pdata 00012bc8..00012c53. Semantic name remains unreviewed. */

undefined4 * FUN_00012bc8(int param_1,undefined4 *param_2,void *param_3,void *param_4)

{
  void *pvVar1;
  undefined4 auStack_20 [2];
  
  while (param_3 != param_4) {
    pvVar1 = *(void **)((int)param_3 + 4);
    FUN_00012afc(param_1,auStack_20,param_3);
    param_3 = pvVar1;
  }
  *param_2 = param_3;
  return param_2;
}



/* 00012c54 FUN_00012c54 */

/* Boundary evidence: original MIPS .pdata 00012c54..00012cbb. Semantic name remains unreviewed. */

undefined4 * FUN_00012c54(undefined4 *param_1,undefined4 *param_2,int param_3,undefined4 *param_4)

{
  undefined4 *puVar1;
  
  puVar1 = FUN_000125cc((int)param_1,param_3);
  if (puVar1 == (undefined4 *)0x0) {
    *param_2 = *param_1;
  }
  else {
    *puVar1 = *param_4;
    *param_2 = puVar1;
  }
  return param_2;
}



/* 00012cbc FUN_00012cbc */

/* Boundary evidence: original MIPS .pdata 00012cbc..00012d13. Semantic name remains unreviewed. */

bool FUN_00012cbc(int *param_1,undefined4 *param_2)

{
  int *piVar1;
  int iVar2;
  undefined4 auStack_10 [2];
  
  iVar2 = *param_1;
  piVar1 = FUN_00012c54(param_1,auStack_10,iVar2,param_2);
  return iVar2 != *piVar1;
}



/* 00012d14 FUN_00012d14 */

/* Boundary evidence: original MIPS .pdata 00012d14..0001327b. Semantic name remains unreviewed. */

undefined4 FUN_00012d14(int param_1,int param_2,int param_3)

{
  undefined4 *****pppppuVar1;
  int iVar2;
  size_t sVar3;
  int *piVar4;
  DWORD dwErrCode;
  wchar_t *_Dest;
  wchar_t *_Source;
  undefined4 ******ppppppuVar5;
  undefined4 uVar6;
  uint *puVar7;
  wchar_t *pwVar8;
  int iVar9;
  uint uVar10;
  wchar_t *local_a0;
  int local_9c;
  int local_90;
  uint *local_8c;
  undefined4 *****local_88;
  uint local_84;
  undefined4 *****local_80;
  undefined4 *****local_7c;
  undefined4 *****local_78;
  undefined4 local_74;
  int *local_70;
  int *local_6c;
  undefined4 local_64;
  uint *local_58;
  uint *local_54;
  undefined4 local_4c;
  wchar_t *local_40;
  wchar_t *local_3c;
  undefined4 local_34;
  
  local_a0 = (wchar_t *)0x0;
  iVar9 = 0;
  local_9c = 0;
  local_80 = &local_80;
  local_74 = 0;
  local_7c = &local_80;
  local_78 = &local_80;
  if ((param_2 == 0) || (param_3 == 0)) {
    SetLastError(0x57);
  }
  else {
    local_6c = (int *)0x0;
    local_70 = (int *)0x0;
    local_64 = 0;
    FUN_000126cc((int *)&local_70,param_2,4,8,1,0);
    piVar4 = local_70;
    if ((local_70 == (int *)0x0) && (piVar4 = local_6c, local_6c == (int *)0x0)) {
      SetLastError(0x57);
    }
    else {
      local_54 = (uint *)0x0;
      local_58 = (uint *)0x0;
      local_4c = 0;
      FUN_000126cc((int *)&local_58,param_3,4,0xc,1,0);
      puVar7 = local_58;
      if (local_58 == (uint *)0x0) {
        puVar7 = local_54;
      }
      local_8c = puVar7;
      if (puVar7 == (uint *)0x0) {
        SetLastError(0x57);
      }
      else {
        local_3c = (wchar_t *)0x0;
        local_40 = (wchar_t *)0x0;
        local_34 = 0;
        FUN_000126cc((int *)&local_40,param_1,*puVar7,8,1,0);
        pwVar8 = local_40;
        if (local_40 == (wchar_t *)0x0) {
          pwVar8 = local_3c;
        }
        if (((param_1 == 0) || (pwVar8 != (wchar_t *)0x0)) || (*puVar7 == 0)) {
          EnterCriticalSection(DAT_00019378);
          iVar2 = FUN_00016874((int)DAT_00019378);
          if (iVar2 != 0) {
            local_a0 = (wchar_t *)0x0;
            do {
              sVar3 = wcslen((wchar_t *)(iVar2 + 0x2c));
              local_a0 = (wchar_t *)((sVar3 + 1) * 2 + (int)local_a0);
              iVar9 = iVar9 + 1;
              iVar2 = *(int *)(iVar2 + 0x278);
              local_9c = iVar9;
            } while (iVar2 != 0);
          }
          uVar6 = 1;
          local_88 = (undefined4 *****)(local_9c * 0x18);
          uVar10 = (int)local_88 + (int)local_a0;
          *piVar4 = local_9c;
          local_84 = uVar10;
          if (param_1 == 0) {
            dwErrCode = 0x7a;
          }
          else {
            if (uVar10 <= *puVar7) {
              iVar9 = FUN_00016874((int)DAT_00019378);
              iVar2 = (int)local_88 + param_1;
              local_a0 = (wchar_t *)((int)local_88 + (int)pwVar8);
              _Dest = pwVar8;
              for (; local_90 = iVar9, iVar9 != 0; iVar9 = *(int *)(iVar9 + 0x278)) {
                wcscpy(_Dest,(wchar_t *)(iVar9 + 0x6a0));
                _Dest[8] = L'\0';
                _Dest[9] = L'\0';
                _Source = (wchar_t *)(iVar9 + 0x2c);
                wcscpy(local_a0,_Source);
                *(int *)(_Dest + 6) = iVar2;
                sVar3 = wcslen(_Source);
                local_a0 = local_a0 + sVar3 + 1;
                sVar3 = wcslen(_Source);
                iVar2 = (sVar3 + 1) * 2 + iVar2;
                InterlockedIncrement((LONG *)(iVar9 + 4));
                FUN_00012cbc((int *)&local_80,&local_90);
                _Dest = _Dest + 0xc;
              }
              LeaveCriticalSection(DAT_00019378);
              pppppuVar1 = local_80;
              ppppppuVar5 = (undefined4 ******)local_80[1];
              local_88 = local_80;
              EnterCriticalSection(DAT_00019148);
              for (; ppppppuVar5 != (undefined4 ******)pppppuVar1;
                  ppppppuVar5 = (undefined4 ******)ppppppuVar5[1]) {
                iVar9 = FUN_0001247c(*ppppppuVar5,0x1040020,0,0,&local_88,4);
                if (iVar9 == 0) {
                  pwVar8[10] = L'\xffff';
                  pwVar8[0xb] = L'\xffff';
                }
                else {
                  *(undefined4 ******)(pwVar8 + 10) = local_88;
                }
                FUN_00011dd4(*ppppppuVar5);
                pwVar8 = pwVar8 + 0xc;
              }
              LeaveCriticalSection(DAT_00019148);
              dwErrCode = 0;
              goto LAB_00013194;
            }
            dwErrCode = 0xea;
          }
          LeaveCriticalSection(DAT_00019378);
LAB_00013194:
          *puVar7 = uVar10;
          if ((dwErrCode != 0) && (SetLastError(dwErrCode), dwErrCode != 0)) {
            uVar6 = 0;
          }
          FUN_00011d6c((int *)&local_40);
          FUN_00011d6c((int *)&local_58);
          FUN_00011d6c((int *)&local_70);
          FUN_00012bc8((int)&local_80,&local_84,local_80[1],local_80);
          return uVar6;
        }
        SetLastError(0x57);
        FUN_00011d6c((int *)&local_40);
      }
      FUN_00011d6c((int *)&local_58);
    }
    FUN_00011d6c((int *)&local_70);
  }
  FUN_00012bc8((int)&local_80,&local_84,local_80[1],local_80);
  return 0;
}



/* 0001327c FUN_0001327c */

/* Boundary evidence: original MIPS .pdata 0001327c..000132a3. Semantic name remains unreviewed. */

undefined4 FUN_0001327c(undefined4 param_1)

{
  ReportFault(param_1,0);
  return 1;
}



/* 000132a4 FUN_000132a4 */

/* Boundary evidence: original MIPS .pdata 000132a4..00013303. Semantic name remains unreviewed. */

undefined4 FUN_000132a4(int param_1)

{
  undefined4 uVar1;
  int *piVar2;
  
  if ((*(int *)(param_1 + 8) == 0x1040fac) &&
     (piVar2 = *(int **)(param_1 + 0xc), piVar2 != (int *)0x0)) {
    uVar1 = FUN_00012d14(*piVar2,piVar2[1],piVar2[2]);
  }
  else {
    SetLastError(0x57);
    uVar1 = 0;
  }
  return uVar1;
}



/* 00013304 FUN_00013304 */

/* Boundary evidence: original MIPS .pdata 00013304..00013377. Semantic name remains unreviewed. */

void FUN_00013304(void)

{
  if (DAT_00019170 != 0) {
    if (DAT_0001916c != (HANDLE)0x0) {
      WaitForSingleObject(DAT_0001916c,0xffffffff);
      CloseHandle(DAT_0001916c);
      DAT_0001916c = (HANDLE)0x0;
    }
    FreeLibrary(DAT_0001917c);
  }
  return;
}



/* 00013378 FUN_00013378 */

/* Boundary evidence: original MIPS .pdata 00013378..00013403. Semantic name remains unreviewed. */

undefined4 FUN_00013378(void)

{
  int iVar1;
  DWORD DVar2;
  
  iVar1 = (*DAT_00019174)(0,0);
  if (-1 < iVar1) {
    while (DVar2 = WaitForSingleObject(DAT_00019144,DAT_00019178), DVar2 != 0) {
      (*DAT_00019184)();
    }
    (*DAT_00019180)();
  }
  return 0;
}



/* 00013404 FUN_00013404 */

/* Boundary evidence: original MIPS .pdata 00013404..00013463. Semantic name remains unreviewed. */

void FUN_00013404(void)

{
  if ((DAT_00019170 != 0) && (DAT_0001916c == (HANDLE)0x0)) {
    DAT_0001916c = CreateThread((LPSECURITY_ATTRIBUTES)0x0,0,FUN_00013378,(LPVOID)0x0,0,(LPDWORD)0x0
                               );
  }
  return;
}



/* 00013464 FUN_00013464 */

/* Boundary evidence: original MIPS .pdata 00013464..00013597. Semantic name remains unreviewed. */

void FUN_00013464(void)

{
  HKEY local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  
  DAT_0001917c = LoadLibraryW(L"\\windows\\ole32.dll");
  if (DAT_0001917c != (HMODULE)0x0) {
    DAT_00019184 = GetProcAddressW(DAT_0001917c,L"CoFreeUnusedLibraries");
    DAT_00019174 = GetProcAddressW(DAT_0001917c,L"CoInitializeEx");
    DAT_00019180 = GetProcAddressW(DAT_0001917c,L"CoUninitialize");
    local_20 = (HKEY)0x0;
    local_1c = 0;
    local_18 = 0;
    local_14 = 0;
    FUN_00012634(&local_20,(HKEY)0x80000002,L"Services",0x20019);
    DAT_00019178 = FUN_00011d18(&local_20,L"CoFreeUnusedLibrariesThreadPeriod",900000);
    if (DAT_00019178 == 0) {
      DAT_00019178 = 900000;
    }
    if (((DAT_00019184 == 0) || (DAT_00019174 == 0)) || (DAT_00019180 == 0)) {
      FreeLibrary(DAT_0001917c);
      DAT_0001917c = (HMODULE)0x0;
    }
    else {
      DAT_00019170 = 1;
    }
    FUN_00011c6c(&local_20);
  }
  return;
}



/* 00013598 FUN_00013598 */

/* Boundary evidence: original MIPS .pdata 00013598..000137e7. Semantic name remains unreviewed. */

undefined4 * FUN_00013598(undefined4 *param_1)

{
  SOCKET SVar1;
  HANDLE pvVar2;
  int iVar3;
  DWORD DVar4;
  uint uVar5;
  
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0xffffffff;
  param_1[8] = 0;
  memset(param_1 + 3,0,0xc);
  memset(param_1 + 9,0,0x28);
  uVar5 = 0;
  do {
    SVar1 = socket(*(int *)((int)&DAT_000111c4 + uVar5),1,0);
    param_1[param_1[8] + 6] = SVar1;
    if (param_1[param_1[8] + 6] != -1) {
      pvVar2 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
      param_1[param_1[8] * 5 + 0xd] = pvVar2;
      iVar3 = WSAIoctl(param_1[param_1[8] + 6],0x28000017,0,0,0,0,0,param_1 + param_1[8] * 5 + 9,0);
      if ((iVar3 == 0) || (DVar4 = GetLastError(), DVar4 == 0x3e5)) {
        param_1[param_1[8] + 3] = param_1[param_1[8] * 5 + 0xd];
        param_1[8] = param_1[8] + 1;
      }
      else {
        closesocket(param_1[param_1[8] + 6]);
        CloseHandle((HANDLE)param_1[param_1[8] * 5 + 0xd]);
      }
    }
    uVar5 = uVar5 + 4;
  } while (uVar5 < 8);
  param_1[param_1[8] + 3] = DAT_00019144;
  param_1[8] = param_1[8] + 1;
  return param_1;
}



/* 000137e8 FUN_000137e8 */

/* Boundary evidence: original MIPS .pdata 000137e8..000138a3. Semantic name remains unreviewed. */

void FUN_000137e8(undefined4 *param_1)

{
  uint uVar1;
  undefined4 *puVar2;
  SOCKET *pSVar3;
  
  uVar1 = 0;
  if (param_1[8] != 0) {
    puVar2 = param_1 + 3;
    do {
      CloseHandle((HANDLE)*puVar2);
      uVar1 = uVar1 + 1;
      puVar2 = puVar2 + 1;
    } while (uVar1 < (uint)param_1[8]);
  }
  uVar1 = 0;
  if (param_1[8] != 1) {
    pSVar3 = param_1 + 6;
    do {
      closesocket(*pSVar3);
      uVar1 = uVar1 + 1;
      pSVar3 = pSVar3 + 1;
    } while (uVar1 < param_1[8] - 1);
  }
  if ((void *)*param_1 != (void *)0x0) {
    operator_delete((void *)*param_1);
  }
  return;
}



/* 000138a4 FUN_000138a4 */

/* Boundary evidence: original MIPS .pdata 000138a4..00013987. Semantic name remains unreviewed. */

undefined4 FUN_000138a4(undefined4 *param_1)

{
  int iVar1;
  HLOCAL pvVar2;
  SIZE_T local_18 [2];
  
  local_18[0] = param_1[1];
  iVar1 = (*DAT_00019190)(0,0,0,*param_1,local_18);
  if (iVar1 == 0x6f) {
    if ((HLOCAL)*param_1 != (HLOCAL)0x0) {
      LocalFree((HLOCAL)*param_1);
      *param_1 = 0;
      param_1[1] = 0;
    }
    pvVar2 = LocalAlloc(0,local_18[0]);
    *param_1 = pvVar2;
    if (pvVar2 == (HLOCAL)0x0) goto LAB_00013920;
    param_1[1] = local_18[0];
    iVar1 = (*DAT_00019190)(0,0,0,pvVar2,local_18);
  }
  if (iVar1 == 0) {
    return 1;
  }
LAB_00013920:
  Sleep(10000);
  return 0;
}



/* 00013988 FUN_00013988 */

/* Boundary evidence: original MIPS .pdata 00013988..00013a07. Semantic name remains unreviewed. */

void FUN_00013988(void)

{
  DAT_00019188 = LoadLibraryW(L"\\windows\\iphlpapi.dll");
  if (DAT_00019188 != (HMODULE)0x0) {
    DAT_00019190 = GetProcAddressW(DAT_00019188,L"GetAdaptersAddresses");
    if (DAT_00019190 == 0) {
      FreeLibrary(DAT_00019188);
      DAT_00019188 = (HMODULE)0x0;
    }
    else {
      DAT_00019194 = 1;
    }
  }
  return;
}



/* 00013a08 FUN_00013a08 */

/* Boundary evidence: original MIPS .pdata 00013a08..00013a83. Semantic name remains unreviewed. */

void FUN_00013a08(void)

{
  if (DAT_00019194 != 0) {
    if (DAT_0001918c != (HANDLE)0x0) {
      WaitForSingleObject(DAT_0001918c,0xffffffff);
      CloseHandle(DAT_0001918c);
      DAT_0001918c = (HANDLE)0x0;
    }
    FreeLibrary(DAT_00019188);
    DAT_00019188 = (HMODULE)0x0;
  }
  return;
}



/* 00013a84 FUN_00013a84 */

/* Boundary evidence: original MIPS .pdata 00013a84..00013b9f. Semantic name remains unreviewed. */

void FUN_00013a84(undefined4 *param_1)

{
  undefined4 **ppuVar1;
  int iVar2;
  undefined4 ***pppuVar3;
  int local_30 [2];
  undefined4 **local_28;
  undefined4 **local_24;
  undefined4 **local_20;
  undefined4 local_1c;
  
  local_28 = &local_28;
  local_24 = &local_28;
  local_20 = &local_28;
  local_1c = 0;
  EnterCriticalSection(DAT_00019378);
  for (iVar2 = FUN_00016874((int)DAT_00019378); local_30[0] = iVar2, iVar2 != 0;
      iVar2 = *(int *)(iVar2 + 0x278)) {
    InterlockedIncrement((LONG *)(iVar2 + 4));
    FUN_00012cbc((int *)&local_28,local_30);
  }
  LeaveCriticalSection(DAT_00019378);
  ppuVar1 = local_28;
  pppuVar3 = (undefined4 ***)local_28[1];
  EnterCriticalSection(DAT_00019148);
  for (; pppuVar3 != (undefined4 ***)ppuVar1; pppuVar3 = (undefined4 ***)pppuVar3[1]) {
    FUN_0001247c(*pppuVar3,0x1040040,*param_1,param_1[1],0,0);
    FUN_00011dd4(*pppuVar3);
  }
  LeaveCriticalSection(DAT_00019148);
  FUN_00012bc8((int)&local_28,local_30,local_28[1],local_28);
  return;
}



/* 00013ba0 FUN_00013ba0 */

/* Boundary evidence: original MIPS .pdata 00013ba0..00013d0f. Semantic name remains unreviewed. */

void FUN_00013ba0(undefined4 *param_1)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = WaitForMultipleObjects(param_1[8],(HANDLE *)(param_1 + 3),0,param_1[2]);
  do {
    if (DAT_0001914c == 0) {
      return;
    }
    if (uVar1 == 0xffffffff) {
LAB_00013c18:
      Sleep(10000);
    }
    else if (uVar1 == 0x102) {
      param_1[2] = 0xffffffff;
      iVar2 = FUN_000138a4(param_1);
      if (iVar2 != 0) {
        FUN_00013a84(param_1);
      }
    }
    else {
      if ((uint)param_1[8] <= uVar1) goto LAB_00013c18;
      WSAIoctl(param_1[uVar1 + 6],0x28000017,0,0,0,0,0,param_1 + uVar1 * 5 + 9,0);
      param_1[2] = 5000;
    }
    uVar1 = WaitForMultipleObjects(param_1[8],(HANDLE *)(param_1 + 3),0,param_1[2]);
  } while( true );
}



/* 00013d10 FUN_00013d10 */

/* Boundary evidence: original MIPS .pdata 00013d10..00013d3f. Semantic name remains unreviewed. */

undefined4 FUN_00013d10(void)

{
  undefined4 auStack_58 [20];
  
  FUN_00013598(auStack_58);
  FUN_00013ba0(auStack_58);
  FUN_000137e8(auStack_58);
  return 0;
}



/* 00013d40 FUN_00013d40 */

/* Boundary evidence: original MIPS .pdata 00013d40..00013d9f. Semantic name remains unreviewed. */

void FUN_00013d40(void)

{
  if ((DAT_00019194 != 0) && (DAT_0001918c == (HANDLE)0x0)) {
    DAT_0001918c = CreateThread((LPSECURITY_ATTRIBUTES)0x0,0,FUN_00013d10,(LPVOID)0x0,0,(LPDWORD)0x0
                               );
  }
  return;
}



/* 00013da0 FUN_00013da0 */

/* Boundary evidence: original MIPS .pdata 00013da0..00013e07. Semantic name remains unreviewed. */

undefined4 FUN_00013da0(undefined4 *param_1,LPWSTR param_2,DWORD param_3)

{
  LSTATUS LVar1;
  DWORD dwIndex;
  DWORD local_res8 [2];
  
  if ((HKEY)*param_1 != (HKEY)0x0) {
    dwIndex = param_1[1];
    param_1[1] = dwIndex + 1;
    local_res8[0] = param_3;
    LVar1 = RegEnumKeyExW((HKEY)*param_1,dwIndex,param_2,local_res8,(LPDWORD)0x0,(LPWSTR)0x0,
                          (LPDWORD)0x0,(PFILETIME)0x0);
    if (LVar1 == 0) {
      return 1;
    }
  }
  return 0;
}



/* 00013e08 FUN_00013e08 */

/* Boundary evidence: original MIPS .pdata 00013e08..00013e67. Semantic name remains unreviewed. */

undefined4 FUN_00013e08(int *param_1,int param_2,void *param_3,size_t param_4,int param_5)

{
  int iVar1;
  undefined4 uVar2;
  
  if ((((param_2 == *param_1) && (param_4 == param_1[0x22])) && (param_5 == param_1[0x23])) &&
     (iVar1 = memcmp(param_1 + 2,param_3,param_4), iVar1 == 0)) {
    uVar2 = 1;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}



/* 00013e68 FUN_00013e68 */

/* Boundary evidence: original MIPS .pdata 00013e68..00013eef. Semantic name remains unreviewed. */

void FUN_00013e68(undefined4 *param_1,undefined4 param_2,undefined4 param_3)

{
  if (DAT_000191a0 != 0) {
    closesocket(DAT_000191a8);
    DAT_000191a0 = 0;
  }
  FUN_0001247c(param_1,0x1040030,param_2,param_3,0,0);
  return;
}



/* 00013ef0 FUN_00013ef0 */

/* Boundary evidence: original MIPS .pdata 00013ef0..00013f4b. Semantic name remains unreviewed. */

void FUN_00013ef0(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 400);
  while (iVar1 != 0) {
    iVar1 = *(int *)(param_1 + 400) + -1;
    *(int *)(param_1 + 400) = iVar1;
    operator_delete(*(void **)(iVar1 * 4 + param_1));
    iVar1 = *(int *)(param_1 + 400);
  }
  DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x194));
  return;
}



/* 00013f4c FUN_00013f4c */

/* Boundary evidence: original MIPS .pdata 00013f4c..00013fab. Semantic name remains unreviewed. */

void * FUN_00013f4c(void *param_1,uint param_2)

{
  closesocket(*(SOCKET *)((int)param_1 + 4));
  DAT_000191a4 = DAT_000191a4 + -1;
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}



/* 00013fac FUN_00013fac */

/* Boundary evidence: original MIPS .pdata 00013fac..00014013. Semantic name remains unreviewed. */

void * FUN_00013fac(int param_1,int param_2)

{
  void *pvVar1;
  
  pvVar1 = operator_new(0x10);
  if (pvVar1 == (void *)0x0) {
    pvVar1 = (void *)0x0;
  }
  else {
    *(int *)((int)pvVar1 + 8) = param_2;
    *(undefined4 *)((int)pvVar1 + 0xc) = *(undefined4 *)(param_2 + 0xc);
    *(void **)(*(int *)(param_2 + 0xc) + 8) = pvVar1;
    *(void **)(param_2 + 0xc) = pvVar1;
    *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + 1;
  }
  return pvVar1;
}



/* 00014014 FUN_00014014 */

/* Boundary evidence: original MIPS .pdata 00014014..000140ab. Semantic name remains unreviewed. */

void FUN_00014014(void)

{
  int iVar1;
  WSADATA WStack_1a0;
  uint local_10;
  
  local_10 = DAT_00019118;
  iVar1 = WSAStartup(0x202,&WStack_1a0);
  if (iVar1 == 0) {
    DAT_0001919c = operator_new(0x10);
    if (DAT_0001919c == (int *)0x0) {
      DAT_0001919c = (int *)0x0;
    }
    else {
      *DAT_0001919c = (int)(DAT_0001919c + -1);
      DAT_0001919c[3] = 0;
      DAT_0001919c[1] = (int)(DAT_0001919c + -1);
      *(undefined4 *)(*DAT_0001919c + 0xc) = *(undefined4 *)(*DAT_0001919c + 8);
    }
    if (DAT_0001919c != (int *)0x0) {
      DAT_00019198 = 1;
    }
  }
  FUN_000180fc(local_10);
  return;
}



/* 000140ac FUN_000140ac */

/* Boundary evidence: original MIPS .pdata 000140ac..0001415b. Semantic name remains unreviewed. */

void * FUN_000140ac(int param_1,uint param_2)

{
  int iVar1;
  LPCRITICAL_SECTION lpCriticalSection;
  void *pvVar2;
  
  lpCriticalSection = (LPCRITICAL_SECTION)(param_1 + 0x194);
  EnterCriticalSection(lpCriticalSection);
  if (*(int *)(param_1 + 0x1a8) == -1) {
    *(uint *)(param_1 + 0x1a8) = param_2;
  }
  if (*(int *)(param_1 + 400) == 0) {
    if (lpCriticalSection != (LPCRITICAL_SECTION)0x0) {
      LeaveCriticalSection(lpCriticalSection);
      lpCriticalSection = (LPCRITICAL_SECTION)0x0;
    }
    pvVar2 = operator_new(param_2);
  }
  else {
    iVar1 = *(int *)(param_1 + 400) + -1;
    *(int *)(param_1 + 400) = iVar1;
    pvVar2 = *(void **)(iVar1 * 4 + param_1);
  }
  if (lpCriticalSection != (LPCRITICAL_SECTION)0x0) {
    LeaveCriticalSection(lpCriticalSection);
  }
  return pvVar2;
}



/* 0001415c FUN_0001415c */

/* Boundary evidence: original MIPS .pdata 0001415c..000141f3. Semantic name remains unreviewed. */

void FUN_0001415c(int param_1,void *param_2)

{
  LPCRITICAL_SECTION lpCriticalSection;
  
  lpCriticalSection = (LPCRITICAL_SECTION)(param_1 + 0x194);
  EnterCriticalSection(lpCriticalSection);
  if (*(uint *)(param_1 + 400) < 100) {
    *(void **)(*(uint *)(param_1 + 400) * 4 + param_1) = param_2;
    *(int *)(param_1 + 400) = *(int *)(param_1 + 400) + 1;
  }
  else {
    if (lpCriticalSection != (LPCRITICAL_SECTION)0x0) {
      LeaveCriticalSection(lpCriticalSection);
      lpCriticalSection = (LPCRITICAL_SECTION)0x0;
    }
    operator_delete(param_2);
  }
  if (lpCriticalSection != (LPCRITICAL_SECTION)0x0) {
    LeaveCriticalSection(lpCriticalSection);
  }
  return;
}



/* 000141f4 FUN_000141f4 */

/* Boundary evidence: original MIPS .pdata 000141f4..00014273. Semantic name remains unreviewed. */

void FUN_000141f4(void)

{
  LONG LVar1;
  LPCRITICAL_SECTION lpCriticalSection;
  
  LVar1 = InterlockedDecrement((LONG *)&DAT_00019360);
  if (LVar1 == 0) {
    lpCriticalSection = (LPCRITICAL_SECTION)FUN_00012b68();
    EnterCriticalSection(lpCriticalSection);
    if (DAT_0001935c != 0) {
      FUN_00013ef0(DAT_0001935c);
      DAT_0001935c = 0;
    }
    if (lpCriticalSection != (LPCRITICAL_SECTION)0x0) {
      LeaveCriticalSection(lpCriticalSection);
    }
  }
  return;
}



/* 00014274 FUN_00014274 */

/* Boundary evidence: original MIPS .pdata 00014274..0001430b. Semantic name remains unreviewed. */

void FUN_00014274(void)

{
  LPCRITICAL_SECTION lpCriticalSection;
  
  lpCriticalSection = (LPCRITICAL_SECTION)FUN_00012b68();
  EnterCriticalSection(lpCriticalSection);
  if (DAT_0001935c == (undefined *)0x0) {
    DAT_00019340 = 0;
    InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_00019344);
    DAT_00019358 = 0xffffffff;
    DAT_0001935c = &DAT_000191b0;
  }
  if (lpCriticalSection != (LPCRITICAL_SECTION)0x0) {
    LeaveCriticalSection(lpCriticalSection);
  }
  return;
}



/* 0001430c FUN_0001430c */

/* Boundary evidence: original MIPS .pdata 0001430c..000144db. Semantic name remains unreviewed. */

void FUN_0001430c(SOCKET *param_1)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  SOCKET *pSVar4;
  int iVar5;
  
  *param_1 = 0;
  EnterCriticalSection(DAT_00019148);
  if (DAT_000191a0 == 0) {
    DAT_000191a8 = socket(2,1,0);
    if (DAT_000191a8 == 0xffffffff) {
      DAT_000191a8 = socket(0x17,1,0);
    }
    DAT_000191a0 = 1;
  }
  if (DAT_000191a8 != 0xffffffff) {
    uVar1 = *param_1;
    uVar2 = 0;
    pSVar4 = param_1;
    if (uVar1 != 0) {
      do {
        if (pSVar4[1] == DAT_000191a8) break;
        uVar2 = uVar2 + 1;
        pSVar4 = pSVar4 + 1;
      } while (uVar2 < *param_1);
    }
    if ((uVar2 == uVar1) && (uVar1 < 0x40)) {
      param_1[uVar2 + 1] = DAT_000191a8;
      *param_1 = *param_1 + 1;
    }
  }
  iVar5 = *DAT_0001919c;
  iVar3 = *(int *)(iVar5 + 8);
  do {
    if (iVar3 == iVar5) {
      LeaveCriticalSection(DAT_00019148);
      return;
    }
    uVar1 = *param_1;
    uVar2 = 0;
    if (uVar1 != 0) {
      pSVar4 = param_1;
      do {
        pSVar4 = pSVar4 + 1;
        if (*pSVar4 == *(SOCKET *)(*(int *)(iVar3 + 4) + 4)) break;
        uVar2 = uVar2 + 1;
      } while (uVar2 < *param_1);
    }
    if ((uVar2 == uVar1) && (uVar1 < 0x40)) {
      param_1[uVar2 + 1] = *(SOCKET *)(*(int *)(iVar3 + 4) + 4);
      *param_1 = *param_1 + 1;
    }
    iVar3 = *(int *)(iVar3 + 8);
  } while( true );
}



/* 000144dc FUN_000144dc */

/* Boundary evidence: original MIPS .pdata 000144dc..00014637. Semantic name remains unreviewed. */

void FUN_000144dc(SOCKET *param_1,uint param_2)

{
  int iVar1;
  uint uVar2;
  int local_30;
  SOCKET local_2c;
  
  uVar2 = 0;
  if (param_2 != 0) {
    do {
      param_1 = param_1 + 1;
      EnterCriticalSection(DAT_00019148);
      if (DAT_000191a0 == 0) {
        LeaveCriticalSection(DAT_00019148);
        return;
      }
      for (iVar1 = *(int *)(*DAT_0001919c + 8); iVar1 != *DAT_0001919c; iVar1 = *(int *)(iVar1 + 8))
      {
        if (*param_1 == *(SOCKET *)(*(int *)(iVar1 + 4) + 4)) {
          local_30 = 0;
          local_2c = accept(*param_1,(sockaddr *)0x0,&local_30);
          if (local_2c != 0xffffffff) {
            FUN_0001247c((undefined4 *)**(undefined4 **)(iVar1 + 4),0x1040034,&local_2c,4,0,0);
          }
          break;
        }
      }
      if (DAT_000191a8 == -1) {
        DAT_000191a0 = 0;
      }
      LeaveCriticalSection(DAT_00019148);
      uVar2 = uVar2 + 1;
    } while (uVar2 < param_2);
  }
  return;
}



/* 00014638 FUN_00014638 */

/* Boundary evidence: original MIPS .pdata 00014638..00014757. Semantic name remains unreviewed. */

undefined4 FUN_00014638(void)

{
  uint uVar1;
  fd_set fStack_128;
  
  FUN_0001430c(&fStack_128.fd_count);
  uVar1 = select(0,&fStack_128,(fd_set *)0x0,(fd_set *)0x0,(timeval *)0x0);
  while (DAT_0001914c != 0) {
    if ((uVar1 == 0) || (uVar1 == 0xffffffff)) {
      EnterCriticalSection(DAT_00019148);
      if (DAT_000191a0 == 0) {
        LeaveCriticalSection(DAT_00019148);
      }
      else {
        LeaveCriticalSection(DAT_00019148);
        Sleep(10000);
      }
    }
    else {
      FUN_000144dc(&fStack_128.fd_count,uVar1);
    }
    FUN_0001430c(&fStack_128.fd_count);
    uVar1 = select(0,&fStack_128,(fd_set *)0x0,(fd_set *)0x0,(timeval *)0x0);
  }
  return 0;
}



/* 00014758 FUN_00014758 */

/* Boundary evidence: original MIPS .pdata 00014758..000147c7. Semantic name remains unreviewed. */

undefined4 FUN_00014758(undefined4 *param_1)

{
  LONG LVar1;
  undefined4 uVar2;
  void *pvVar3;
  
  if (((LONG *)*param_1 == (LONG *)0x0) ||
     (LVar1 = InterlockedDecrement((LONG *)*param_1), LVar1 != 0)) {
    uVar2 = 0;
  }
  else {
    pvVar3 = (void *)*param_1;
    FUN_00014274();
    FUN_0001415c(DAT_0001935c,pvVar3);
    uVar2 = 1;
  }
  *param_1 = 0;
  return uVar2;
}



/* 000147c8 FUN_000147c8 */

/* Boundary evidence: original MIPS .pdata 000147c8..0001484b. Semantic name remains unreviewed. */

undefined4 * FUN_000147c8(undefined4 *param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 *puVar2;
  
  iVar1 = FUN_00014758(param_1);
  if ((iVar1 != 0) && ((void *)param_1[1] != (void *)0x0)) {
    FUN_00013f4c((void *)param_1[1],1);
  }
  param_1[1] = *param_2;
  FUN_00014274();
  puVar2 = FUN_000140ac(DAT_0001935c,4);
  *param_1 = puVar2;
  if (puVar2 != (undefined4 *)0x0) {
    *puVar2 = 1;
  }
  return param_1;
}



/* 0001484c FUN_0001484c */

/* Boundary evidence: original MIPS .pdata 0001484c..00014897. Semantic name remains unreviewed. */

void FUN_0001484c(undefined4 *param_1)

{
  int iVar1;
  
  iVar1 = FUN_00014758(param_1);
  if ((iVar1 != 0) && ((void *)param_1[1] != (void *)0x0)) {
    FUN_00013f4c((void *)param_1[1],1);
  }
  FUN_000141f4();
  return;
}



/* 00014898 FUN_00014898 */

/* Boundary evidence: original MIPS .pdata 00014898..00014907. Semantic name remains unreviewed. */

undefined4 * FUN_00014898(undefined4 *param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  
  InterlockedIncrement((LONG *)&DAT_00019360);
  FUN_00014274();
  *param_1 = 0;
  param_1[1] = param_2;
  FUN_00014274();
  puVar1 = FUN_000140ac(DAT_0001935c,4);
  *param_1 = puVar1;
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = 1;
  }
  return param_1;
}



/* 00014908 FUN_00014908 */

/* Boundary evidence: original MIPS .pdata 00014908..0001496b. Semantic name remains unreviewed. */

undefined4 * FUN_00014908(undefined4 *param_1,undefined4 *param_2)

{
  LONG *lpAddend;
  
  InterlockedIncrement((LONG *)&DAT_00019360);
  FUN_00014274();
  *param_1 = 0;
  param_1[1] = param_2[1];
  lpAddend = (LONG *)*param_2;
  *param_1 = lpAddend;
  if (lpAddend != (LONG *)0x0) {
    InterlockedIncrement(lpAddend);
  }
  return param_1;
}



/* 0001496c FUN_0001496c */

/* Boundary evidence: original MIPS .pdata 0001496c..000149eb. Semantic name remains unreviewed. */

undefined4 * FUN_0001496c(int param_1,undefined4 *param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = param_3[2];
  *(undefined4 *)(param_3[3] + 8) = uVar2;
  *(undefined4 *)(param_3[2] + 0xc) = param_3[3];
  FUN_0001484c(param_3);
  operator_delete(param_3);
  iVar1 = *(int *)(param_1 + 0xc);
  *param_2 = uVar2;
  *(int *)(param_1 + 0xc) = iVar1 + -1;
  return param_2;
}



/* 000149ec FUN_000149ec */

/* Boundary evidence: original MIPS .pdata 000149ec..00014a77. Semantic name remains unreviewed. */

undefined4 * FUN_000149ec(int param_1,undefined4 *param_2,undefined4 *param_3,undefined4 *param_4)

{
  undefined4 *puVar1;
  undefined4 auStack_20 [2];
  
  while (param_3 != param_4) {
    puVar1 = (undefined4 *)param_3[2];
    FUN_0001496c(param_1,auStack_20,param_3);
    param_3 = puVar1;
  }
  *param_2 = param_3;
  return param_2;
}



/* 00014a78 FUN_00014a78 */

/* Boundary evidence: original MIPS .pdata 00014a78..00014aef. Semantic name remains unreviewed. */

undefined4 * FUN_00014a78(undefined4 *param_1,undefined4 *param_2,int param_3,undefined4 *param_4)

{
  undefined4 *puVar1;
  
  puVar1 = FUN_00013fac((int)param_1,param_3);
  if (puVar1 == (undefined4 *)0x0) {
    *param_2 = *param_1;
  }
  else {
    FUN_00014908(puVar1,param_4);
    *param_2 = puVar1;
  }
  return param_2;
}



/* 00014af0 FUN_00014af0 */

/* Boundary evidence: original MIPS .pdata 00014af0..00014bf3. Semantic name remains unreviewed. */

undefined4 FUN_00014af0(undefined4 *param_1,void *param_2,size_t param_3,int param_4)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 auStack_30 [2];
  
  puVar1 = DAT_0001919c;
  puVar4 = (undefined4 *)*DAT_0001919c;
  puVar3 = (undefined4 *)puVar4[2];
  while( true ) {
    if (puVar3 == puVar4) {
      SetLastError(0x425);
      return 0;
    }
    iVar2 = FUN_00013e08((int *)puVar3[1],(int)param_1,param_2,param_3,param_4);
    if (iVar2 != 0) break;
    puVar3 = (undefined4 *)puVar3[2];
  }
  FUN_0001496c((int)puVar1,auStack_30,puVar3);
  FUN_00013e68(param_1,param_2,param_3);
  return 1;
}



/* 00014bf4 FUN_00014bf4 */

/* Boundary evidence: original MIPS .pdata 00014bf4..00014d27. Semantic name remains unreviewed. */

bool FUN_00014bf4(undefined4 *param_1,int param_2)

{
  DWORD dwErrCode;
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  bool bVar4;
  undefined4 *puVar5;
  undefined4 auStack_28 [2];
  
  if (param_2 == 0) {
    EnterCriticalSection(DAT_00019148);
  }
  bVar4 = false;
  if (DAT_00019198 == 0) {
    dwErrCode = 0x15;
  }
  else {
    bVar4 = false;
    puVar5 = (undefined4 *)*DAT_0001919c;
    puVar1 = DAT_0001919c;
    puVar3 = (undefined4 *)puVar5[2];
    while (puVar3 != puVar5) {
      if (*(undefined4 **)puVar3[1] == param_1) {
        puVar2 = (undefined4 *)puVar3[2];
        FUN_0001496c((int)puVar1,auStack_28,puVar3);
        bVar4 = true;
        puVar1 = DAT_0001919c;
        puVar3 = puVar2;
      }
      else {
        puVar3 = (undefined4 *)puVar3[2];
      }
    }
    if (bVar4) {
      FUN_00013e68(param_1,0,0);
    }
    dwErrCode = 0x425;
  }
  SetLastError(dwErrCode);
  if (param_2 == 0) {
    LeaveCriticalSection(DAT_00019148);
  }
  return bVar4;
}



/* 00014d28 FUN_00014d28 */

/* Boundary evidence: original MIPS .pdata 00014d28..00014e37. Semantic name remains unreviewed. */

undefined4 FUN_00014d28(undefined4 *param_1,int param_2)

{
  bool bVar1;
  undefined3 extraout_var;
  int iVar2;
  undefined4 uVar3;
  void *pvVar4;
  int local_38;
  size_t local_34;
  int local_30;
  void *local_28;
  void *local_24;
  undefined4 local_1c;
  
  bVar1 = FUN_0001258c((int)param_1);
  if (CONCAT31(extraout_var,bVar1) != 0) {
    iVar2 = CeSafeCopyMemory(&local_38,*(undefined4 *)(param_2 + 0xc),0xc);
    if (iVar2 != 0) {
      local_24 = (void *)0x0;
      local_28 = (void *)0x0;
      local_1c = 0;
      FUN_000126cc((int *)&local_28,local_38,local_34,4,1,0);
      pvVar4 = local_28;
      if ((local_28 == (void *)0x0) && (pvVar4 = local_24, local_24 == (void *)0x0)) {
        SetLastError(0x57);
        uVar3 = 0;
      }
      else {
        EnterCriticalSection(DAT_00019148);
        uVar3 = FUN_00014af0(param_1,pvVar4,local_34,local_30);
        LeaveCriticalSection(DAT_00019148);
      }
      FUN_00011d6c((int *)&local_28);
      return uVar3;
    }
    SetLastError(0x57);
  }
  return 0;
}



/* 00014e38 FUN_00014e38 */

/* Boundary evidence: original MIPS .pdata 00014e38..00014e7b. Semantic name remains unreviewed. */

bool FUN_00014e38(undefined4 *param_1)

{
  bool bVar1;
  undefined3 extraout_var;
  
  bVar1 = FUN_0001258c((int)param_1);
  if (CONCAT31(extraout_var,bVar1) == 0) {
    bVar1 = false;
  }
  else {
    bVar1 = FUN_00014bf4(param_1,0);
  }
  return bVar1;
}



/* 00014e7c FUN_00014e7c */

/* Boundary evidence: original MIPS .pdata 00014e7c..00014ed3. Semantic name remains unreviewed. */

bool FUN_00014e7c(int *param_1,undefined4 *param_2)

{
  int *piVar1;
  int iVar2;
  undefined4 auStack_10 [2];
  
  iVar2 = *param_1;
  piVar1 = FUN_00014a78(param_1,auStack_10,iVar2,param_2);
  return iVar2 != *piVar1;
}



/* 00014ed4 FUN_00014ed4 */

/* Boundary evidence: original MIPS .pdata 00014ed4..0001514f. Semantic name remains unreviewed. */

undefined4 FUN_00014ed4(undefined4 *param_1,sockaddr *param_2,size_t param_3,int param_4)

{
  bool bVar1;
  int iVar2;
  undefined3 extraout_var;
  SOCKET s;
  DWORD dwErrCode;
  undefined4 uVar3;
  undefined4 *local_38 [2];
  undefined4 uStack_30;
  int local_2c;
  
  s = 0xffffffff;
  FUN_00014898(&uStack_30,0);
  if (DAT_000191a4 < 0x3f) {
    uVar3 = 1;
    s = socket((int)param_2->sa_family,1,param_4);
    if (((s == 0xffffffff) || (iVar2 = bind(s,param_2,param_3), iVar2 != 0)) ||
       (iVar2 = listen(s,0x7fffffff), iVar2 != 0)) {
      dwErrCode = WSAGetLastError();
LAB_000150d0:
      if (dwErrCode == 0) goto LAB_00015114;
      goto LAB_000150d8;
    }
    local_38[0] = operator_new(0x90);
    if (local_38[0] == (undefined4 *)0x0) {
      local_38[0] = (undefined4 *)0x0;
    }
    else {
      *local_38[0] = param_1;
      local_38[0][1] = s;
      local_38[0][0x22] = param_3;
      local_38[0][0x23] = param_4;
      memcpy(local_38[0] + 2,param_2,param_3);
      DAT_000191a4 = DAT_000191a4 + 1;
    }
    FUN_000147c8(&uStack_30,local_38);
    if (local_2c != 0) {
      iVar2 = FUN_0001247c(param_1,0x104002c,param_2,param_3,0,0);
      if (iVar2 != 1) goto LAB_00014f40;
      if (DAT_000191ac == (HANDLE)0x0) {
        DAT_000191ac = CreateThread((LPSECURITY_ATTRIBUTES)0x0,0,FUN_00014638,(LPVOID)0x0,0,
                                    (LPDWORD)0x0);
        if (DAT_000191ac != (HANDLE)0x0) goto LAB_0001509c;
      }
      else {
LAB_0001509c:
        bVar1 = FUN_00014e7c(DAT_0001919c,&uStack_30);
        if (CONCAT31(extraout_var,bVar1) != 0) {
          dwErrCode = 0;
          if (DAT_000191a0 == 0) goto LAB_00015114;
          closesocket(DAT_000191a8);
          DAT_000191a0 = 0;
          goto LAB_000150d0;
        }
      }
      dwErrCode = 0xe;
      goto LAB_000150d8;
    }
    dwErrCode = 0xe;
LAB_000150e4:
    if (s != 0xffffffff) {
      closesocket(s);
    }
  }
  else {
LAB_00014f40:
    dwErrCode = 0x425;
LAB_000150d8:
    if (local_2c == 0) goto LAB_000150e4;
  }
  SetLastError(dwErrCode);
  uVar3 = 0;
LAB_00015114:
  FUN_0001484c(&uStack_30);
  return uVar3;
}



/* 00015150 FUN_00015150 */

/* Boundary evidence: original MIPS .pdata 00015150..000153cf. Semantic name remains unreviewed. */

void FUN_00015150(undefined4 *param_1,int param_2,int param_3)

{
  bool bVar1;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  int iVar2;
  LSTATUS LVar3;
  DWORD DVar4;
  DWORD local_4e8 [2];
  HKEY local_4e0;
  undefined4 local_4dc;
  undefined4 local_4d8;
  undefined4 local_4d4;
  HKEY local_4d0;
  undefined4 local_4cc;
  undefined4 local_4c8;
  undefined4 local_4c4;
  sockaddr local_4c0 [8];
  WCHAR aWStack_440 [260];
  wchar_t awStack_238 [260];
  uint local_30;
  
  local_30 = DAT_00019118;
  if (param_2 == 0) {
    EnterCriticalSection(DAT_00019148);
  }
  local_4d0 = (HKEY)0x0;
  local_4cc = 0;
  local_4c8 = 0;
  local_4c4 = 0;
  if ((((DAT_00019198 != 0) &&
       (bVar1 = FUN_000120a8((int)param_1,awStack_238,0x104), CONCAT31(extraout_var,bVar1) != 0)) &&
      (bVar1 = FUN_00012634(&local_4d0,(HKEY)0x80000002,awStack_238,0x20019),
      CONCAT31(extraout_var_00,bVar1) != 0)) &&
     (iVar2 = FUN_0001247c(param_1,0x104002c,0,0,0,0), iVar2 != 0)) {
    iVar2 = FUN_00013da0(&local_4d0,aWStack_440,0x104);
    while (iVar2 != 0) {
      local_4e0 = (HKEY)0x0;
      local_4dc = 0;
      local_4d8 = 0;
      local_4d4 = 0;
      FUN_00012634(&local_4e0,local_4d0,aWStack_440,0x20019);
      local_4e8[0] = 0x80;
      if (local_4e0 != (HKEY)0x0) {
        LVar3 = RegQueryValueExW(local_4e0,L"SockAddr",(LPDWORD)0x0,(LPDWORD)0x0,(LPBYTE)local_4c0,
                                 local_4e8);
        DVar4 = local_4e8[0];
        if (LVar3 != 0) {
          DVar4 = 0;
        }
        if (((DVar4 != 0) && (0xf < DVar4)) && ((local_4c0[0].sa_family != 2 || (DVar4 == 0x10)))) {
          if (local_4c0[0].sa_family == 0x17) {
            if (DVar4 == 0x1c) {
LAB_00015310:
              iVar2 = FUN_00011d18(&local_4e0,L"Protocol",0);
              FUN_00014ed4(param_1,local_4c0,DVar4,iVar2);
            }
          }
          else if (local_4c0[0].sa_family == 2) goto LAB_00015310;
        }
      }
      FUN_00011c6c(&local_4e0);
      iVar2 = FUN_00013da0(&local_4d0,aWStack_440,0x104);
    }
    if (param_3 != 0) {
      FUN_0001247c(param_1,0x1040038,0,0,0,0);
    }
  }
  if (param_2 == 0) {
    LeaveCriticalSection(DAT_00019148);
  }
  FUN_00011c6c(&local_4d0);
  FUN_000180fc(local_30);
  return;
}



/* 000153d0 FUN_000153d0 */

/* Boundary evidence: original MIPS .pdata 000153d0..0001553b. Semantic name remains unreviewed. */

undefined4 FUN_000153d0(undefined4 *param_1,int param_2)

{
  u_short uVar1;
  bool bVar2;
  undefined3 extraout_var;
  int iVar3;
  undefined4 uVar4;
  sockaddr *psVar5;
  int local_38;
  uint local_34;
  int local_30;
  sockaddr *local_28;
  sockaddr *local_24;
  undefined4 local_1c;
  
  bVar2 = FUN_0001258c((int)param_1);
  if (CONCAT31(extraout_var,bVar2) != 0) {
    iVar3 = CeSafeCopyMemory(&local_38,*(undefined4 *)(param_2 + 0xc),0xc);
    if (iVar3 == 0) {
      SetLastError(0x57);
    }
    else {
      local_24 = (sockaddr *)0x0;
      local_28 = (sockaddr *)0x0;
      local_1c = 0;
      FUN_000126cc((int *)&local_28,local_38,local_34,4,1,0);
      psVar5 = local_28;
      if ((((local_28 != (sockaddr *)0x0) || (psVar5 = local_24, local_24 != (sockaddr *)0x0)) &&
          (0xf < local_34)) && ((uVar1 = psVar5->sa_family, uVar1 != 2 || (local_34 == 0x10)))) {
        if (uVar1 == 0x17) {
          if (local_34 == 0x1c) {
LAB_000154c8:
            EnterCriticalSection(DAT_00019148);
            uVar4 = FUN_00014ed4(param_1,psVar5,local_34,local_30);
            LeaveCriticalSection(DAT_00019148);
            FUN_00011d6c((int *)&local_28);
            return uVar4;
          }
        }
        else if (uVar1 == 2) goto LAB_000154c8;
      }
      SetLastError(0x57);
      FUN_00011d6c((int *)&local_28);
    }
  }
  return 0;
}



/* 0001553c FUN_0001553c */

/* Boundary evidence: original MIPS .pdata 0001553c..00015593. Semantic name remains unreviewed. */

undefined4 * FUN_0001553c(undefined4 *param_1,uint param_2)

{
  undefined4 auStack_18 [2];
  
  FUN_000149ec((int)param_1,auStack_18,(undefined4 *)((undefined4 *)*param_1)[2],
               (undefined4 *)*param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}



/* 00015594 FUN_00015594 */

/* Boundary evidence: original MIPS .pdata 00015594..0001565b. Semantic name remains unreviewed. */

void FUN_00015594(void)

{
  if (DAT_00019198 != 0) {
    EnterCriticalSection(DAT_00019148);
    if (DAT_000191a0 != 0) {
      closesocket(DAT_000191a8);
      DAT_000191a0 = 0;
    }
    LeaveCriticalSection(DAT_00019148);
    if (DAT_000191ac != (HANDLE)0x0) {
      WaitForSingleObject(DAT_000191ac,0xffffffff);
      CloseHandle(DAT_000191ac);
      DAT_000191ac = (HANDLE)0x0;
    }
    if (DAT_0001919c != (undefined4 *)0x0) {
      FUN_0001553c(DAT_0001919c,1);
    }
    WSACleanup();
  }
  return;
}



/* 0001565c FUN_0001565c */

void FUN_0001565c(void)

{
  return;
}



/* 00015664 FUN_00015664 */

/* Boundary evidence: original MIPS .pdata 00015664..0001567f. Semantic name remains unreviewed. */

void FUN_00015664(size_t param_1)

{
  malloc(param_1);
  return;
}



/* 00015680 FUN_00015680 */

/* Boundary evidence: original MIPS .pdata 00015680..0001569b. Semantic name remains unreviewed. */

void FUN_00015680(void *param_1,size_t param_2)

{
  realloc(param_1,param_2);
  return;
}



/* 0001569c FUN_0001569c */

/* Boundary evidence: original MIPS .pdata 0001569c..000156b7. Semantic name remains unreviewed. */

void FUN_0001569c(void *param_1)

{
  free(param_1);
  return;
}



/* 000156b8 FUN_000156b8 */

/* Boundary evidence: original MIPS .pdata 000156b8..00015717. Semantic name remains unreviewed. */

PHKEY FUN_000156b8(PHKEY param_1,HKEY param_2,LPCWSTR param_3)

{
  LSTATUS LVar1;
  
  *param_1 = (HKEY)0x0;
  if (param_3 != (LPCWSTR)0x0) {
    LVar1 = RegOpenKeyExW(param_2,param_3,0,0,param_1);
    if (LVar1 != 0) {
      *param_1 = (HKEY)0x0;
    }
  }
  return param_1;
}



/* 00015718 FUN_00015718 */

/* Boundary evidence: original MIPS .pdata 00015718..0001575b. Semantic name remains unreviewed. */

undefined4 * FUN_00015718(undefined4 *param_1,uint param_2)

{
  *param_1 = &PTR_FUN_0001124c;
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}



/* 0001575c FUN_0001575c */

/* Boundary evidence: original MIPS .pdata 0001575c..0001578b. Semantic name remains unreviewed. */

void FUN_0001575c(int param_1)

{
  if (*(HMODULE *)(param_1 + 0x238) != (HMODULE)0x0) {
    FreeLibrary(*(HMODULE *)(param_1 + 0x238));
  }
  return;
}



/* 0001578c FUN_0001578c */

/* Boundary evidence: original MIPS .pdata 0001578c..00015847. Semantic name remains unreviewed. */

undefined4 * FUN_0001578c(undefined4 *param_1,void *param_2,undefined4 param_3)

{
  *param_1 = &PTR_FUN_0001124c;
  param_1[1] = 0;
  InitializeCriticalSection((LPCRITICAL_SECTION)(param_1 + 2));
  *param_1 = &PTR_FUN_00011250;
  memcpy(param_1 + 7,param_2,0x218);
  param_1[0x9e] = param_3;
  param_1[0x8d] = 0;
  param_1[0x8e] = 0;
  param_1[0x8f] = 0;
  param_1[0x90] = 0;
  param_1[0x91] = 0;
  param_1[0x92] = 0;
  param_1[0x93] = 0;
  param_1[0x94] = 0;
  param_1[0x95] = 0;
  param_1[0x96] = 0;
  param_1[0x97] = 0;
  param_1[0x98] = 0;
  param_1[0x99] = 0;
  param_1[0x9a] = 0;
  param_1[0x9b] = 0;
  param_1[0x9c] = 0;
  param_1[0x9d] = 0xffffffff;
  return param_1;
}



/* 00015848 FUN_00015848 */

/* Boundary evidence: original MIPS .pdata 00015848..000158fb. Semantic name remains unreviewed. */

void FUN_00015848(int param_1,LPCWSTR param_2)

{
  LSTATUS LVar1;
  HKEY local_20;
  DWORD local_1c;
  DWORD local_18;
  undefined4 local_14;
  
  FUN_000156b8(&local_20,(HKEY)0x80000002,param_2);
  if (local_20 != (HKEY)0x0) {
    local_1c = 4;
    LVar1 = RegQueryValueExW(local_20,L"ReflectorHandle",(LPDWORD)0x0,&local_18,(LPBYTE)&local_14,
                             &local_1c);
    if ((LVar1 == 0) && (local_18 == 4)) {
      *(undefined4 *)(param_1 + 0x270) = local_14;
    }
    if (local_20 != (HKEY)0x0) {
      RegCloseKey(local_20);
    }
  }
  return;
}



/* 000158fc FUN_000158fc */

/* Boundary evidence: original MIPS .pdata 000158fc..00015a57. Semantic name remains unreviewed. */

bool FUN_000158fc(int param_1,undefined4 *param_2)

{
  int iVar1;
  bool bVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  
  bVar2 = false;
  if ((*(int *)(param_1 + 0x23c) != 0) && (*(int *)(param_1 + 0x26c) == 0)) {
    if ((param_2[2] == 0) && (*(int *)(param_1 + 0x270) == 0)) {
      FUN_00015848(param_1,(LPCWSTR)(param_2 + 4));
    }
    puVar3 = (undefined4 *)param_2[2];
    if (puVar3 == (undefined4 *)0x0) {
      puVar3 = param_2 + 4;
    }
    iVar1 = __GetUserKData(0);
    uVar4 = *(undefined4 *)(iVar1 + -0x1c);
    iVar1 = __GetUserKData(0);
    *(undefined4 *)(iVar1 + -0x1c) = *param_2;
    iVar1 = (**(code **)(param_1 + 0x23c))(puVar3,param_2[3]);
    *(int *)(param_1 + 0x26c) = iVar1;
    bVar2 = iVar1 != 0;
    iVar1 = __GetUserKData(0);
    *(undefined4 *)(iVar1 + -0x1c) = uVar4;
    if ((!bVar2) && (*(HANDLE *)(param_1 + 0x270) != (HANDLE)0x0)) {
      CloseHandle(*(HANDLE *)(param_1 + 0x270));
      *(undefined4 *)(param_1 + 0x270) = 0;
    }
  }
  return bVar2;
}



/* 00015a58 FUN_00015a58 */

/* Boundary evidence: original MIPS .pdata 00015a58..00015a63. Semantic name remains unreviewed. */

undefined4 FUN_00015a58(void)

{
  return 1;
}



/* 00015a64 FUN_00015a64 */

/* Boundary evidence: original MIPS .pdata 00015a64..00015b73. Semantic name remains unreviewed. */

undefined4 FUN_00015a64(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 8));
  iVar2 = *(int *)(param_1 + 0x26c);
  *(undefined4 *)(param_1 + 0x26c) = 0;
  while (*(int *)(param_1 + 0x234) != 0) {
    uVar1 = **(undefined4 **)(param_1 + 0x234);
    operator_delete(*(undefined4 **)(param_1 + 0x234));
    *(undefined4 *)(param_1 + 0x234) = uVar1;
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 8));
  if ((iVar2 != 0) && (*(code **)(param_1 + 0x244) != (code *)0x0)) {
    (**(code **)(param_1 + 0x244))(iVar2);
    if (*(HANDLE *)(param_1 + 0x270) != (HANDLE)0x0) {
      CloseHandle(*(HANDLE *)(param_1 + 0x270));
      *(undefined4 *)(param_1 + 0x270) = 0;
    }
  }
  return 1;
}



/* 00015b74 FUN_00015b74 */

/* Boundary evidence: original MIPS .pdata 00015b74..00015b7f. Semantic name remains unreviewed. */

undefined4 FUN_00015b74(void)

{
  return 1;
}



/* 00015b80 FUN_00015b80 */

/* Boundary evidence: original MIPS .pdata 00015b80..00015c17. Semantic name remains unreviewed. */

undefined4 FUN_00015b80(int *param_1)

{
  undefined4 uVar1;
  
  uVar1 = 1;
  if ((code *)param_1[0x90] == (code *)0x0) {
    uVar1 = (**(code **)(*param_1 + 0xc))();
  }
  else if (param_1[0x9b] != 0) {
    (*(code *)param_1[0x90])(param_1[0x9b]);
  }
  return uVar1;
}



/* 00015c18 FUN_00015c18 */

/* Boundary evidence: original MIPS .pdata 00015c18..00015c23. Semantic name remains unreviewed. */

undefined4 FUN_00015c18(void)

{
  return 1;
}



/* 00015c24 FUN_00015c24 */

/* Boundary evidence: original MIPS .pdata 00015c24..00015c9f. Semantic name remains unreviewed. */

undefined4 FUN_00015c24(int param_1)

{
  if ((*(int *)(param_1 + 0x26c) != 0) && (*(code **)(param_1 + 0x268) != (code *)0x0)) {
    (**(code **)(param_1 + 0x268))(*(int *)(param_1 + 0x26c));
  }
  return 1;
}



/* 00015ca0 FUN_00015ca0 */

/* Boundary evidence: original MIPS .pdata 00015ca0..00015cab. Semantic name remains unreviewed. */

undefined4 FUN_00015ca0(void)

{
  return 1;
}



/* 00015cac FUN_00015cac */

/* Boundary evidence: original MIPS .pdata 00015cac..00015d27. Semantic name remains unreviewed. */

undefined4 FUN_00015cac(int param_1)

{
  if ((*(int *)(param_1 + 0x26c) != 0) && (*(code **)(param_1 + 0x264) != (code *)0x0)) {
    (**(code **)(param_1 + 0x264))(*(int *)(param_1 + 0x26c));
  }
  return 1;
}



/* 00015d28 FUN_00015d28 */

/* Boundary evidence: original MIPS .pdata 00015d28..00015d33. Semantic name remains unreviewed. */

undefined4 FUN_00015d28(void)

{
  return 1;
}



/* 00015d34 FUN_00015d34 */

/* Boundary evidence: original MIPS .pdata 00015d34..00015eb3. Semantic name remains unreviewed. */

undefined4 * FUN_00015d34(int param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  DWORD dwErrCode;
  undefined4 uVar4;
  
  if (*(int *)(param_1 + 0x248) == 0) {
    dwErrCode = 1;
  }
  else {
    puVar1 = operator_new(8);
    if (puVar1 != (undefined4 *)0x0) {
      iVar2 = __GetUserKData(0);
      uVar4 = *(undefined4 *)(iVar2 + -0x1c);
      iVar2 = __GetUserKData(0);
      *(undefined4 *)(iVar2 + -0x1c) = *param_2;
      iVar2 = (**(code **)(param_1 + 0x248))(*(undefined4 *)(param_1 + 0x26c),param_2[2],param_2[3])
      ;
      iVar3 = __GetUserKData(0);
      *(undefined4 *)(iVar3 + -0x1c) = uVar4;
      if (iVar2 != 0) {
        EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 8));
        puVar1[1] = iVar2;
        *puVar1 = *(undefined4 *)(param_1 + 0x234);
        *(undefined4 **)(param_1 + 0x234) = puVar1;
        LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 8));
        return puVar1;
      }
      operator_delete(puVar1);
      return (undefined4 *)0x0;
    }
    dwErrCode = 0xe;
  }
  SetLastError(dwErrCode);
  return (undefined4 *)0x0;
}



/* 00015eb4 FUN_00015eb4 */

/* Boundary evidence: original MIPS .pdata 00015eb4..00015ebf. Semantic name remains unreviewed. */

undefined4 FUN_00015eb4(void)

{
  return 1;
}



/* 00015ec0 FUN_00015ec0 */

/* Boundary evidence: original MIPS .pdata 00015ec0..00015ff3. Semantic name remains unreviewed. */

undefined4 FUN_00015ec0(int param_1,int *param_2)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  undefined4 uVar4;
  int iVar5;
  
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 8));
  piVar2 = *(int **)(param_1 + 0x234);
  piVar3 = (int *)0x0;
  if (*(int **)(param_1 + 0x234) != (int *)0x0) {
    do {
      piVar1 = piVar2;
      piVar2 = piVar1;
      if (piVar1 == param_2) break;
      piVar2 = (int *)*piVar1;
      piVar3 = piVar1;
    } while (piVar2 != (int *)0x0);
    if (piVar2 != (int *)0x0) {
      iVar5 = piVar2[1];
      if (piVar3 == (int *)0x0) {
        *(int *)(param_1 + 0x234) = *piVar2;
      }
      else {
        *piVar3 = *piVar2;
      }
      operator_delete(piVar2);
      goto LAB_00015f60;
    }
  }
  iVar5 = 0;
LAB_00015f60:
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 8));
  uVar4 = 1;
  SetLastError(0x1f);
  if ((iVar5 != 0) && (*(code **)(param_1 + 0x250) != (code *)0x0)) {
    uVar4 = (**(code **)(param_1 + 0x250))(iVar5);
  }
  return uVar4;
}



/* 00015ff4 FUN_00015ff4 */

/* Boundary evidence: original MIPS .pdata 00015ff4..00015fff. Semantic name remains unreviewed. */

undefined4 FUN_00015ff4(void)

{
  return 1;
}



/* 00016000 FUN_00016000 */

/* Boundary evidence: original MIPS .pdata 00016000..00016073. Semantic name remains unreviewed. */

bool FUN_00016000(int param_1,int param_2)

{
  int *piVar1;
  
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 8));
  for (piVar1 = *(int **)(param_1 + 0x234); (piVar1 != (int *)0x0 && (piVar1 != (int *)param_2));
      piVar1 = (int *)*piVar1) {
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 8));
  return piVar1 != (int *)0x0;
}



/* 00016074 FUN_00016074 */

/* Boundary evidence: original MIPS .pdata 00016074..000160f7. Semantic name remains unreviewed. */

undefined4 FUN_00016074(int param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 8));
  piVar1 = *(int **)(param_1 + 0x234);
  do {
    if (piVar1 == (int *)0x0) {
LAB_000160d0:
      LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 8));
      return uVar2;
    }
    if (piVar1 == (int *)param_2) {
      uVar2 = piVar1[1];
      goto LAB_000160d0;
    }
    piVar1 = (int *)*piVar1;
  } while( true );
}



/* 000160f8 FUN_000160f8 */

/* Boundary evidence: original MIPS .pdata 000160f8..00016253. Semantic name remains unreviewed. */

undefined4 FUN_000160f8(int param_1,int *param_2)

{
  int *piVar1;
  undefined4 uVar2;
  LPCRITICAL_SECTION lpCriticalSection;
  int iVar3;
  
  uVar2 = 0;
  lpCriticalSection = (LPCRITICAL_SECTION)(param_1 + 8);
  EnterCriticalSection(lpCriticalSection);
  piVar1 = *(int **)(param_1 + 0x234);
  if (piVar1 != (int *)0x0) {
    do {
      if (piVar1 == param_2) break;
      piVar1 = (int *)*piVar1;
    } while (piVar1 != (int *)0x0);
    if ((piVar1 != (int *)0x0) && (iVar3 = piVar1[1], iVar3 != 0)) {
      if (*(int *)(param_1 + 0x24c) == 0) {
        piVar1[1] = 0;
        if (*(int *)(param_1 + 0x250) == 0) goto LAB_000161c0;
        LeaveCriticalSection(lpCriticalSection);
        uVar2 = (**(code **)(param_1 + 0x250))(iVar3);
      }
      else {
        LeaveCriticalSection(lpCriticalSection);
        uVar2 = (**(code **)(param_1 + 0x24c))(iVar3);
      }
      EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 8));
    }
  }
LAB_000161c0:
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 8));
  return uVar2;
}



/* 00016254 FUN_00016254 */

/* Boundary evidence: original MIPS .pdata 00016254..0001625f. Semantic name remains unreviewed. */

undefined4 FUN_00016254(void)

{
  return 1;
}



/* 00016260 FUN_00016260 */

/* Boundary evidence: original MIPS .pdata 00016260..0001626b. Semantic name remains unreviewed. */

undefined4 FUN_00016260(void)

{
  return 1;
}



/* 0001626c FUN_0001626c */

/* Boundary evidence: original MIPS .pdata 0001626c..00016393. Semantic name remains unreviewed. */

int FUN_0001626c(int *param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 uVar4;
  
  iVar3 = 0;
  iVar1 = (**(code **)(*param_1 + 0x28))(param_1,param_2[1]);
  if ((iVar1 != 0) && (param_1[0x95] != 0)) {
    iVar3 = __GetUserKData(0);
    uVar4 = *(undefined4 *)(iVar3 + -0x1c);
    iVar3 = __GetUserKData(0);
    *(undefined4 *)(iVar3 + -0x1c) = *param_2;
    uVar2 = (*(code *)param_1[0x95])(iVar1,param_2[2],param_2[3]);
    param_2[4] = uVar2;
    iVar3 = 1;
    iVar1 = __GetUserKData(0);
    *(undefined4 *)(iVar1 + -0x1c) = uVar4;
  }
  if (iVar3 == 0) {
    param_2[4] = 0xffffffff;
  }
  return iVar3;
}



/* 00016394 FUN_00016394 */

/* Boundary evidence: original MIPS .pdata 00016394..0001639f. Semantic name remains unreviewed. */

undefined4 FUN_00016394(void)

{
  return 1;
}



/* 000163a0 FUN_000163a0 */

/* Boundary evidence: original MIPS .pdata 000163a0..000164c7. Semantic name remains unreviewed. */

int FUN_000163a0(int *param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 uVar4;
  
  iVar3 = 0;
  iVar1 = (**(code **)(*param_1 + 0x28))(param_1,param_2[1]);
  if ((iVar1 != 0) && (param_1[0x96] != 0)) {
    iVar3 = __GetUserKData(0);
    uVar4 = *(undefined4 *)(iVar3 + -0x1c);
    iVar3 = __GetUserKData(0);
    *(undefined4 *)(iVar3 + -0x1c) = *param_2;
    uVar2 = (*(code *)param_1[0x96])(iVar1,param_2[2],param_2[3]);
    param_2[4] = uVar2;
    iVar3 = 1;
    iVar1 = __GetUserKData(0);
    *(undefined4 *)(iVar1 + -0x1c) = uVar4;
  }
  if (iVar3 == 0) {
    param_2[4] = 0xffffffff;
  }
  return iVar3;
}



/* 000164c8 FUN_000164c8 */

/* Boundary evidence: original MIPS .pdata 000164c8..000164d3. Semantic name remains unreviewed. */

undefined4 FUN_000164c8(void)

{
  return 1;
}



/* 000164d4 FUN_000164d4 */

/* Boundary evidence: original MIPS .pdata 000164d4..000165fb. Semantic name remains unreviewed. */

int FUN_000164d4(int *param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 uVar4;
  
  iVar3 = 0;
  iVar1 = (**(code **)(*param_1 + 0x28))(param_1,param_2[1]);
  if ((iVar1 != 0) && (param_1[0x97] != 0)) {
    iVar3 = __GetUserKData(0);
    uVar4 = *(undefined4 *)(iVar3 + -0x1c);
    iVar3 = __GetUserKData(0);
    *(undefined4 *)(iVar3 + -0x1c) = *param_2;
    uVar2 = (*(code *)param_1[0x97])(iVar1,param_2[2],param_2[3]);
    param_2[4] = uVar2;
    iVar3 = 1;
    iVar1 = __GetUserKData(0);
    *(undefined4 *)(iVar1 + -0x1c) = uVar4;
  }
  if (iVar3 == 0) {
    param_2[4] = 0xffffffff;
  }
  return iVar3;
}



/* 000165fc FUN_000165fc */

/* Boundary evidence: original MIPS .pdata 000165fc..00016607. Semantic name remains unreviewed. */

undefined4 FUN_000165fc(void)

{
  return 1;
}



/* 00016608 FUN_00016608 */

/* Boundary evidence: original MIPS .pdata 00016608..0001673b. Semantic name remains unreviewed. */

undefined4 FUN_00016608(int *param_1,undefined4 *param_2)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  
  uVar4 = 0;
  iVar1 = (**(code **)(*param_1 + 0x28))(param_1,param_2[1]);
  if ((iVar1 != 0) && (param_1[0x98] != 0)) {
    iVar2 = __GetUserKData(0);
    uVar5 = *(undefined4 *)(iVar2 + -0x1c);
    iVar2 = __GetUserKData(0);
    *(undefined4 *)(iVar2 + -0x1c) = *param_2;
    puVar3 = param_2 + 8;
    if (param_2[7] == 0) {
      puVar3 = (undefined4 *)0x0;
    }
    uVar4 = (*(code *)param_1[0x98])
                      (iVar1,param_2[2],param_2[3],param_2[4],param_2[5],param_2[6],puVar3);
    iVar1 = __GetUserKData(0);
    *(undefined4 *)(iVar1 + -0x1c) = uVar5;
  }
  return uVar4;
}



/* 0001673c FUN_0001673c */

/* Boundary evidence: original MIPS .pdata 0001673c..00016747. Semantic name remains unreviewed. */

undefined4 FUN_0001673c(void)

{
  return 1;
}



/* 00016748 FUN_00016748 */

/* Boundary evidence: original MIPS .pdata 00016748..000167db. Semantic name remains unreviewed. */

undefined4 FUN_00016748(undefined4 param_1,short *param_2,wchar_t *param_3,undefined4 param_4)

{
  undefined4 uVar1;
  undefined4 local_50;
  short local_4c;
  undefined2 local_4a;
  wchar_t awStack_48 [28];
  uint local_10;
  
  local_10 = DAT_00019118;
  if ((param_2 != (short *)0x0) && (*param_2 != 0)) {
    local_50 = *(undefined4 *)param_2;
    local_4c = param_2[2];
    local_4a = 0x5f;
    wcscpy(awStack_48,param_3);
    param_3 = (wchar_t *)&local_50;
  }
  uVar1 = GetProcAddressW(param_4,param_3);
  FUN_000180fc(local_10);
  return uVar1;
}



/* 000167dc FUN_000167dc */

/* Boundary evidence: original MIPS .pdata 000167dc..00016873. Semantic name remains unreviewed. */

int * FUN_000167dc(LPCRITICAL_SECTION param_1,undefined4 param_2)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  
  EnterCriticalSection(param_1);
  piVar2 = (int *)param_1->SpinCount;
  do {
    piVar3 = (int *)0x0;
    if (piVar2 == (int *)0x0) {
LAB_0001684c:
      LeaveCriticalSection(param_1);
      return piVar3;
    }
    iVar1 = (**(code **)(*piVar2 + 0x24))(piVar2,param_2);
    if (iVar1 != 0) {
      InterlockedIncrement(piVar2 + 1);
      piVar3 = piVar2;
      goto LAB_0001684c;
    }
    piVar2 = (int *)piVar2[0x9e];
  } while( true );
}



/* 00016874 FUN_00016874 */

undefined4 FUN_00016874(int param_1)

{
  return *(undefined4 *)(param_1 + 0x14);
}



/* 0001687c FUN_0001687c */

/* Boundary evidence: original MIPS .pdata 0001687c..0001692b. Semantic name remains unreviewed. */

ULONG_PTR FUN_0001687c(LPCRITICAL_SECTION param_1,ULONG_PTR param_2,int param_3)

{
  ULONG_PTR UVar1;
  ULONG_PTR UVar2;
  ULONG_PTR *pUVar3;
  
  if (param_2 == 0) {
    param_2 = 0;
  }
  else {
    EnterCriticalSection(param_1);
    if ((param_3 == 0) && (UVar2 = param_1->SpinCount, UVar2 != 0)) {
      pUVar3 = (ULONG_PTR *)(UVar2 + 0x278);
      UVar1 = *pUVar3;
      while (UVar1 != 0) {
        UVar2 = *pUVar3;
        pUVar3 = (ULONG_PTR *)(UVar2 + 0x278);
        UVar1 = *pUVar3;
      }
      *(ULONG_PTR *)(UVar2 + 0x278) = param_2;
    }
    else {
      *(ULONG_PTR *)(param_2 + 0x278) = param_1->SpinCount;
      param_1->SpinCount = param_2;
    }
    InterlockedIncrement((LONG *)(param_2 + 4));
    LeaveCriticalSection(param_1);
  }
  return param_2;
}



/* 0001692c FUN_0001692c */

/* Boundary evidence: original MIPS .pdata 0001692c..000169d7. Semantic name remains unreviewed. */

undefined4 * FUN_0001692c(LPCRITICAL_SECTION param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  
  EnterCriticalSection(param_1);
  puVar3 = (undefined4 *)param_1->SpinCount;
  puVar4 = (undefined4 *)0x0;
  if (puVar3 != (undefined4 *)0x0) {
    if (puVar3 == param_2) {
      param_1->SpinCount = param_2[0x9e];
LAB_000169a8:
      FUN_00011dd4(param_2);
      puVar4 = param_2;
    }
    else {
      iVar2 = puVar3[0x9e];
      while (iVar2 != 0) {
        puVar1 = (undefined4 *)puVar3[0x9e];
        if (puVar1 == param_2) {
          puVar3[0x9e] = param_2[0x9e];
          goto LAB_000169a8;
        }
        puVar3 = puVar1;
        iVar2 = puVar1[0x9e];
      }
    }
  }
  LeaveCriticalSection(param_1);
  return puVar4;
}



/* 000169d8 FUN_000169d8 */

/* Boundary evidence: original MIPS .pdata 000169d8..00016c0f. Semantic name remains unreviewed. */

undefined4 FUN_000169d8(int param_1)

{
  HMODULE pHVar1;
  undefined4 uVar2;
  short *psVar3;
  
  if (*(int *)(param_1 + 0x238) == 0) {
    if ((*(uint *)(param_1 + 0x20) & 2) == 0) {
      pHVar1 = (HMODULE)LoadDriver();
    }
    else {
      pHVar1 = LoadLibraryW((LPCWSTR)(param_1 + 0x2c));
    }
    *(HMODULE *)(param_1 + 0x238) = pHVar1;
    if (pHVar1 != (HMODULE)0x0) {
      psVar3 = (short *)(param_1 + 0x24);
      uVar2 = FUN_00016748(param_1,psVar3,L"Init",pHVar1);
      *(undefined4 *)(param_1 + 0x23c) = uVar2;
      uVar2 = FUN_00016748(param_1,psVar3,L"PreDeinit",*(undefined4 *)(param_1 + 0x238));
      *(undefined4 *)(param_1 + 0x240) = uVar2;
      uVar2 = FUN_00016748(param_1,psVar3,L"Deinit",*(undefined4 *)(param_1 + 0x238));
      *(undefined4 *)(param_1 + 0x244) = uVar2;
      uVar2 = FUN_00016748(param_1,psVar3,L"Open",*(undefined4 *)(param_1 + 0x238));
      *(undefined4 *)(param_1 + 0x248) = uVar2;
      uVar2 = FUN_00016748(param_1,psVar3,L"PreClose",*(undefined4 *)(param_1 + 0x238));
      *(undefined4 *)(param_1 + 0x24c) = uVar2;
      uVar2 = FUN_00016748(param_1,psVar3,L"Close",*(undefined4 *)(param_1 + 0x238));
      *(undefined4 *)(param_1 + 0x250) = uVar2;
      uVar2 = FUN_00016748(param_1,psVar3,L"Read",*(undefined4 *)(param_1 + 0x238));
      *(undefined4 *)(param_1 + 0x254) = uVar2;
      uVar2 = FUN_00016748(param_1,psVar3,L"Write",*(undefined4 *)(param_1 + 0x238));
      *(undefined4 *)(param_1 + 600) = uVar2;
      uVar2 = FUN_00016748(param_1,psVar3,L"Seek",*(undefined4 *)(param_1 + 0x238));
      *(undefined4 *)(param_1 + 0x25c) = uVar2;
      uVar2 = FUN_00016748(param_1,psVar3,L"IOControl",*(undefined4 *)(param_1 + 0x238));
      *(undefined4 *)(param_1 + 0x260) = uVar2;
      uVar2 = FUN_00016748(param_1,psVar3,L"PowerUp",*(undefined4 *)(param_1 + 0x238));
      *(undefined4 *)(param_1 + 0x264) = uVar2;
      uVar2 = FUN_00016748(param_1,psVar3,L"PowerDown",*(undefined4 *)(param_1 + 0x238));
      *(undefined4 *)(param_1 + 0x268) = uVar2;
      if (((((*(int *)(param_1 + 0x23c) != 0) && (*(int *)(param_1 + 0x244) != 0)) &&
           ((*(int *)(param_1 + 0x248) == 0 || (*(int *)(param_1 + 0x250) != 0)))) &&
          ((((*(int *)(param_1 + 0x254) != 0 || (*(int *)(param_1 + 600) != 0)) ||
            (*(int *)(param_1 + 0x25c) != 0)) || (*(int *)(param_1 + 0x260) != 0)))) &&
         ((*(int *)(param_1 + 0x24c) == 0 || (*(int *)(param_1 + 0x240) != 0)))) {
        return 1;
      }
    }
  }
  return 0;
}



/* 00016c10 FUN_00016c10 */

/* Boundary evidence: original MIPS .pdata 00016c10..00016cc7. Semantic name remains unreviewed. */

void FUN_00016c10(undefined4 *param_1)

{
  undefined4 uVar1;
  LPCRITICAL_SECTION lpCriticalSection;
  
  lpCriticalSection = (LPCRITICAL_SECTION)(param_1 + 2);
  *param_1 = &PTR_FUN_00011250;
  EnterCriticalSection(lpCriticalSection);
  if (param_1[0x8e] != 0) {
    FUN_00015a64((int)param_1);
    if ((HMODULE)param_1[0x8e] != (HMODULE)0x0) {
      FreeLibrary((HMODULE)param_1[0x8e]);
    }
  }
  while (param_1[0x8d] != 0) {
    uVar1 = *(undefined4 *)param_1[0x8d];
    operator_delete((undefined4 *)param_1[0x8d]);
    param_1[0x8d] = uVar1;
  }
  LeaveCriticalSection(lpCriticalSection);
  DeleteCriticalSection(lpCriticalSection);
  *param_1 = &PTR_FUN_0001124c;
  return;
}



/* 00016cc8 FUN_00016cc8 */

/* Boundary evidence: original MIPS .pdata 00016cc8..00016cff. Semantic name remains unreviewed. */

bool FUN_00016cc8(LPCRITICAL_SECTION param_1,ULONG_PTR param_2)

{
  ULONG_PTR UVar1;
  
  UVar1 = FUN_0001687c(param_1,param_2,1);
  return UVar1 != 0;
}



/* 00016d00 FUN_00016d00 */

/* Boundary evidence: original MIPS .pdata 00016d00..00016d2f. Semantic name remains unreviewed. */

bool FUN_00016d00(LPCRITICAL_SECTION param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  
  puVar1 = FUN_0001692c(param_1,param_2);
  return puVar1 != (undefined4 *)0x0;
}



/* 00016d30 FUN_00016d30 */

/* Boundary evidence: original MIPS .pdata 00016d30..00016d7b. Semantic name remains unreviewed. */

undefined4 * FUN_00016d30(undefined4 *param_1,uint param_2)

{
  FUN_00016c10(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}



/* 00016d7c FUN_00016d7c */

/* Boundary evidence: original MIPS .pdata 00016d7c..00016da7. Semantic name remains unreviewed. */

undefined4 FUN_00016d7c(undefined4 *param_1)

{
  if (param_1 != (undefined4 *)0x0) {
    param_1[0x9d] = 0xffffffff;
    FUN_00011dd4(param_1);
  }
  return 1;
}



/* 00016da8 FUN_00016da8 */

/* Boundary evidence: original MIPS .pdata 00016da8..00016dd7. Semantic name remains unreviewed. */

void FUN_00016da8(DWORD param_1)

{
  WaitForSingleObject(DAT_00019374,param_1);
  return;
}



/* 00016dd8 FUN_00016dd8 */

/* Boundary evidence: original MIPS .pdata 00016dd8..00016e87. Semantic name remains unreviewed. */

int * FUN_00016dd8(void *param_1)

{
  bool bVar1;
  int *piVar2;
  int iVar3;
  undefined3 extraout_var;
  
  if (DAT_00019378 != (LPCRITICAL_SECTION)0x0) {
    piVar2 = FUN_00011f5c(param_1);
    if (piVar2 == (int *)0x0) {
      return (int *)0x0;
    }
    iVar3 = (**(code **)(*piVar2 + 4))(piVar2);
    if (iVar3 == 0) {
      (**(code **)*piVar2)(piVar2,1);
      piVar2 = (int *)0x0;
    }
    if (piVar2 == (int *)0x0) {
      return (int *)0x0;
    }
    bVar1 = FUN_00016cc8(DAT_00019378,(ULONG_PTR)piVar2);
    if (CONCAT31(extraout_var,bVar1) != 0) {
      return piVar2;
    }
    (**(code **)*piVar2)(piVar2,1);
  }
  return (int *)0x0;
}



/* 00016e88 FUN_00016e88 */

/* Boundary evidence: original MIPS .pdata 00016e88..00016eff. Semantic name remains unreviewed. */

undefined4 FUN_00016e88(undefined4 param_1)

{
  int *piVar1;
  undefined4 uVar2;
  
  uVar2 = 1;
  if ((DAT_00019378 != (LPCRITICAL_SECTION)0x0) &&
     (piVar1 = FUN_000167dc(DAT_00019378,param_1), piVar1 != (int *)0x0)) {
    uVar2 = (**(code **)(*piVar1 + 0x20))(piVar1,param_1);
    FUN_00011dd4(piVar1);
  }
  return uVar2;
}



/* 00016f00 FUN_00016f00 */

/* Boundary evidence: original MIPS .pdata 00016f00..00016f77. Semantic name remains unreviewed. */

undefined4 FUN_00016f00(undefined4 param_1)

{
  int *piVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  if ((DAT_00019378 != (LPCRITICAL_SECTION)0x0) &&
     (piVar1 = FUN_000167dc(DAT_00019378,param_1), piVar1 != (int *)0x0)) {
    uVar2 = (**(code **)(*piVar1 + 0x2c))(piVar1,param_1);
    FUN_00011dd4(piVar1);
  }
  return uVar2;
}



/* 00016f78 FUN_00016f78 */

/* Boundary evidence: original MIPS .pdata 00016f78..00016fef. Semantic name remains unreviewed. */

undefined4 FUN_00016f78(int param_1)

{
  int *piVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  if ((DAT_00019378 != (LPCRITICAL_SECTION)0x0) &&
     (piVar1 = FUN_000167dc(DAT_00019378,*(undefined4 *)(param_1 + 4)), piVar1 != (int *)0x0)) {
    uVar2 = (**(code **)(*piVar1 + 0x30))(piVar1,param_1);
    FUN_00011dd4(piVar1);
  }
  return uVar2;
}



/* 00016ff0 FUN_00016ff0 */

/* Boundary evidence: original MIPS .pdata 00016ff0..00017067. Semantic name remains unreviewed. */

undefined4 FUN_00016ff0(int param_1)

{
  int *piVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  if ((DAT_00019378 != (LPCRITICAL_SECTION)0x0) &&
     (piVar1 = FUN_000167dc(DAT_00019378,*(undefined4 *)(param_1 + 4)), piVar1 != (int *)0x0)) {
    uVar2 = (**(code **)(*piVar1 + 0x34))(piVar1,param_1);
    FUN_00011dd4(piVar1);
  }
  return uVar2;
}



/* 00017068 FUN_00017068 */

/* Boundary evidence: original MIPS .pdata 00017068..000170df. Semantic name remains unreviewed. */

undefined4 FUN_00017068(int param_1)

{
  int *piVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  if ((DAT_00019378 != (LPCRITICAL_SECTION)0x0) &&
     (piVar1 = FUN_000167dc(DAT_00019378,*(undefined4 *)(param_1 + 4)), piVar1 != (int *)0x0)) {
    uVar2 = (**(code **)(*piVar1 + 0x38))(piVar1,param_1);
    FUN_00011dd4(piVar1);
  }
  return uVar2;
}



/* 000170e0 FUN_000170e0 */

/* Boundary evidence: original MIPS .pdata 000170e0..00017157. Semantic name remains unreviewed. */

undefined4 FUN_000170e0(int param_1)

{
  int *piVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  if ((DAT_00019378 != (LPCRITICAL_SECTION)0x0) &&
     (piVar1 = FUN_000167dc(DAT_00019378,*(undefined4 *)(param_1 + 4)), piVar1 != (int *)0x0)) {
    uVar2 = (**(code **)(*piVar1 + 0x3c))(piVar1,param_1);
    FUN_00011dd4(piVar1);
  }
  return uVar2;
}



/* 00017158 FUN_00017158 */

/* Boundary evidence: original MIPS .pdata 00017158..000174d3. Semantic name remains unreviewed. */

int FUN_00017158(int *param_1,uint param_2,undefined4 *param_3,uint param_4,int *param_5,
                uint param_6,undefined4 *param_7)

{
  bool bVar1;
  DWORD dwErrCode;
  int iVar2;
  undefined3 extraout_var;
  DWORD DVar3;
  code *pcVar4;
  int iVar5;
  
  dwErrCode = GetLastError();
  SetLastError(0x57);
  if (param_1 == (int *)0x0) {
    return 0;
  }
  if (param_2 < 0x109001d) {
    if (param_2 == 0x109001c) {
      if (param_3 == (undefined4 *)0x0) {
        return 0;
      }
      if (param_4 < 4) {
        return 0;
      }
      pcVar4 = *(code **)(*param_1 + 0x20);
LAB_00017468:
      param_3 = (undefined4 *)*param_3;
      goto LAB_0001746c;
    }
    if (param_2 == 0x1090004) {
      if (param_3 == (undefined4 *)0x0) {
        return 0;
      }
      if (param_4 < 0x218) {
        return 0;
      }
      pcVar4 = *(code **)(*param_1 + 8);
      goto LAB_0001746c;
    }
    if (param_2 == 0x1090008) {
      pcVar4 = *(code **)(*param_1 + 0xc);
    }
    else if (param_2 == 0x109000c) {
      pcVar4 = *(code **)(*param_1 + 0x10);
    }
    else if (param_2 == 0x1090010) {
      pcVar4 = *(code **)(*param_1 + 0x14);
    }
    else {
      if (param_2 != 0x1090014) {
        if (param_2 != 0x1090018) {
          return 0;
        }
        if (param_3 == (undefined4 *)0x0) {
          return 0;
        }
        if (param_4 < 0x10) {
          return 0;
        }
        if (param_5 == (int *)0x0) {
          return 0;
        }
        if (param_6 < 4) {
          return 0;
        }
        iVar2 = (**(code **)(*param_1 + 0x1c))(param_1,param_3);
        if (iVar2 == 0) {
          return 0;
        }
        iVar5 = 1;
        *param_5 = iVar2;
        if (param_7 != (undefined4 *)0x0) {
          *param_7 = 4;
        }
        goto LAB_00017480;
      }
      pcVar4 = *(code **)(*param_1 + 0x18);
    }
    iVar5 = (*pcVar4)(param_1);
  }
  else {
    if (param_2 == 0x1090020) {
      if (param_3 == (undefined4 *)0x0) {
        return 0;
      }
      if (param_4 < 4) {
        return 0;
      }
      pcVar4 = *(code **)(*param_1 + 0x2c);
      goto LAB_00017468;
    }
    if (param_2 == 0x1090024) {
      if (param_3 == (undefined4 *)0x0) {
        return 0;
      }
      if (param_4 < 0x14) {
        return 0;
      }
      pcVar4 = *(code **)(*param_1 + 0x30);
    }
    else if (param_2 == 0x1090028) {
      if (param_3 == (undefined4 *)0x0) {
        return 0;
      }
      if (param_4 < 0x14) {
        return 0;
      }
      pcVar4 = *(code **)(*param_1 + 0x34);
    }
    else if (param_2 == 0x109002c) {
      if (param_3 == (undefined4 *)0x0) {
        return 0;
      }
      if (param_4 < 0x14) {
        return 0;
      }
      pcVar4 = *(code **)(*param_1 + 0x38);
    }
    else {
      if (param_2 != 0x1090030) {
        if (param_2 != 0x1090404) {
          return 0;
        }
        if ((HANDLE)param_1[0x9d] != (HANDLE)0xffffffff) {
          CloseHandle((HANDLE)param_1[0x9d]);
          param_1[0x9d] = -1;
        }
        if (DAT_00019378 == (LPCRITICAL_SECTION)0x0) {
          iVar5 = 0;
        }
        else {
          bVar1 = FUN_00016d00(DAT_00019378,param_1);
          iVar5 = CONCAT31(extraout_var,bVar1);
        }
        goto LAB_00017478;
      }
      if (param_3 == (undefined4 *)0x0) {
        return 0;
      }
      if (param_4 < 0x24) {
        return 0;
      }
      pcVar4 = *(code **)(*param_1 + 0x3c);
    }
LAB_0001746c:
    iVar5 = (*pcVar4)(param_1,param_3);
  }
LAB_00017478:
  if (iVar5 == 0) {
    return 0;
  }
LAB_00017480:
  DVar3 = GetLastError();
  if (DVar3 == 0x57) {
    SetLastError(dwErrCode);
  }
  return iVar5;
}



/* 000174d4 FUN_000174d4 */

/* Boundary evidence: original MIPS .pdata 000174d4..00017547. Semantic name remains unreviewed. */

void FUN_000174d4(LPCRITICAL_SECTION param_1)

{
  undefined4 *puVar1;
  ULONG_PTR UVar2;
  
  EnterCriticalSection(param_1);
  while (param_1->SpinCount != 0) {
    puVar1 = (undefined4 *)param_1->SpinCount;
    UVar2 = puVar1[0x9e];
    if (puVar1 != (undefined4 *)0x0) {
      (**(code **)*puVar1)(puVar1,1);
    }
    param_1->SpinCount = UVar2;
  }
  LeaveCriticalSection(param_1);
  DeleteCriticalSection(param_1);
  return;
}



/* 00017548 FUN_00017548 */

/* Boundary evidence: original MIPS .pdata 00017548..000175d7. Semantic name remains unreviewed. */

ULONG_PTR FUN_00017548(LPCRITICAL_SECTION param_1,ULONG_PTR param_2)

{
  ULONG_PTR UVar1;
  ULONG_PTR UVar2;
  
  if (param_2 == 0) {
    UVar2 = 0;
  }
  else {
    EnterCriticalSection(param_1);
    for (UVar1 = param_1->SpinCount; UVar2 = 0, UVar1 != 0; UVar1 = *(ULONG_PTR *)(UVar1 + 0x278)) {
      if (UVar1 == param_2) {
        UVar2 = UVar1;
        if (UVar1 != 0) {
          InterlockedIncrement((LONG *)(UVar1 + 4));
        }
        break;
      }
    }
    LeaveCriticalSection(param_1);
  }
  return UVar2;
}



/* 000175d8 FUN_000175d8 */

/* Boundary evidence: original MIPS .pdata 000175d8..0001764f. Semantic name remains unreviewed. */

undefined4 FUN_000175d8(int param_1)

{
  int *piVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  if ((DAT_00019378 != (LPCRITICAL_SECTION)0x0) &&
     (piVar1 = (int *)FUN_00017548(DAT_00019378,*(ULONG_PTR *)(param_1 + 4)), piVar1 != (int *)0x0))
  {
    uVar2 = (**(code **)(*piVar1 + 8))(piVar1,param_1);
    FUN_00011dd4(piVar1);
  }
  return uVar2;
}



/* 00017650 FUN_00017650 */

/* Boundary evidence: original MIPS .pdata 00017650..000176bb. Semantic name remains unreviewed. */

undefined4 FUN_00017650(ULONG_PTR param_1)

{
  int *piVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  if ((DAT_00019378 != (LPCRITICAL_SECTION)0x0) &&
     (piVar1 = (int *)FUN_00017548(DAT_00019378,param_1), piVar1 != (int *)0x0)) {
    uVar2 = (**(code **)(*piVar1 + 0xc))(piVar1);
    FUN_00011dd4(piVar1);
  }
  return uVar2;
}



/* 000176bc FUN_000176bc */

/* Boundary evidence: original MIPS .pdata 000176bc..00017727. Semantic name remains unreviewed. */

undefined4 FUN_000176bc(ULONG_PTR param_1)

{
  int *piVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  if ((DAT_00019378 != (LPCRITICAL_SECTION)0x0) &&
     (piVar1 = (int *)FUN_00017548(DAT_00019378,param_1), piVar1 != (int *)0x0)) {
    uVar2 = (**(code **)(*piVar1 + 0x10))(piVar1);
    FUN_00011dd4(piVar1);
  }
  return uVar2;
}



/* 00017728 FUN_00017728 */

/* Boundary evidence: original MIPS .pdata 00017728..00017793. Semantic name remains unreviewed. */

undefined4 FUN_00017728(ULONG_PTR param_1)

{
  int *piVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  if ((DAT_00019378 != (LPCRITICAL_SECTION)0x0) &&
     (piVar1 = (int *)FUN_00017548(DAT_00019378,param_1), piVar1 != (int *)0x0)) {
    uVar2 = (**(code **)(*piVar1 + 0x14))(piVar1);
    FUN_00011dd4(piVar1);
  }
  return uVar2;
}



/* 00017794 FUN_00017794 */

/* Boundary evidence: original MIPS .pdata 00017794..000177ff. Semantic name remains unreviewed. */

undefined4 FUN_00017794(ULONG_PTR param_1)

{
  int *piVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  if ((DAT_00019378 != (LPCRITICAL_SECTION)0x0) &&
     (piVar1 = (int *)FUN_00017548(DAT_00019378,param_1), piVar1 != (int *)0x0)) {
    uVar2 = (**(code **)(*piVar1 + 0x18))(piVar1);
    FUN_00011dd4(piVar1);
  }
  return uVar2;
}



/* 00017800 FUN_00017800 */

/* Boundary evidence: original MIPS .pdata 00017800..00017877. Semantic name remains unreviewed. */

undefined4 FUN_00017800(int param_1)

{
  int *piVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  if ((DAT_00019378 != (LPCRITICAL_SECTION)0x0) &&
     (piVar1 = (int *)FUN_00017548(DAT_00019378,*(ULONG_PTR *)(param_1 + 4)), piVar1 != (int *)0x0))
  {
    uVar2 = (**(code **)(*piVar1 + 0x1c))(piVar1,param_1);
    FUN_00011dd4(piVar1);
  }
  return uVar2;
}



/* 00017878 FUN_00017878 */

/* Boundary evidence: original MIPS .pdata 00017878..00017de3. Semantic name remains unreviewed. */

int FUN_00017878(undefined4 param_1,undefined4 param_2,uint param_3,ULONG_PTR *param_4,uint param_5,
                int *param_6,uint param_7,undefined4 *param_8)

{
  bool bVar1;
  DWORD dwErrCode;
  int iVar2;
  int *piVar3;
  undefined4 *puVar4;
  undefined3 extraout_var;
  DWORD DVar5;
  int iVar6;
  
  iVar6 = 0;
  dwErrCode = GetLastError();
  SetLastError(0x57);
  if (0x1090024 < param_3) {
    if (param_3 < 0x1090401) {
      if (param_3 == 0x1090400) {
        if (param_4 == (ULONG_PTR *)0x0) {
          return 0;
        }
        if (param_5 < 0x218) {
          return 0;
        }
        if (param_6 == (int *)0x0) {
          return 0;
        }
        if (param_7 < 8) {
          return 0;
        }
        piVar3 = FUN_00016dd8(param_4);
        if (piVar3 == (int *)0x0) {
          return 0;
        }
        *param_6 = (int)piVar3;
        iVar6 = CreateAPIHandle(DAT_0001912c,piVar3);
        if ((iVar6 != 0) && (iVar6 != -1)) {
          piVar3[0x9d] = iVar6;
          InterlockedIncrement(piVar3 + 1);
        }
        param_6[1] = iVar6;
        if (param_8 != (undefined4 *)0x0) {
          *param_8 = 8;
        }
LAB_00017c9c:
        iVar6 = 1;
        goto LAB_00017d94;
      }
      if (param_3 == 0x1090028) {
        if (param_4 == (ULONG_PTR *)0x0) {
          return 0;
        }
        if (param_5 < 0x14) {
          return 0;
        }
        iVar6 = FUN_00016ff0((int)param_4);
      }
      else if (param_3 == 0x109002c) {
        if (param_4 == (ULONG_PTR *)0x0) {
          return 0;
        }
        if (param_5 < 0x14) {
          return 0;
        }
        iVar6 = FUN_00017068((int)param_4);
      }
      else if (param_3 == 0x1090030) {
        if (param_4 == (ULONG_PTR *)0x0) {
          return 0;
        }
        if (param_5 < 0x24) {
          return 0;
        }
        iVar6 = FUN_000170e0((int)param_4);
      }
      else {
        if (param_3 != 0x1090034) {
          return 0;
        }
        if (param_4 == (ULONG_PTR *)0x0) {
          return 0;
        }
        if (param_5 < 0x24) {
          return 0;
        }
        iVar6 = FUN_000132a4((int)param_4);
      }
    }
    else {
      if (param_3 != 0x1090404) {
        if (param_3 == 0x1090800) {
          if (DAT_00019374 == 0) {
            return 0;
          }
          EventModify(DAT_00019374,3);
          return 0;
        }
        if (param_3 != 0x1090804) {
          return 0;
        }
        goto LAB_00017c9c;
      }
      if (param_4 == (ULONG_PTR *)0x0) {
        return 0;
      }
      if (param_5 < 4) {
        return 0;
      }
      if ((DAT_00019378 != (LPCRITICAL_SECTION)0x0) &&
         (puVar4 = (undefined4 *)FUN_00017548(DAT_00019378,*param_4), puVar4 != (undefined4 *)0x0))
      {
        if ((HANDLE)puVar4[0x9d] != (HANDLE)0xffffffff) {
          CloseHandle((HANDLE)puVar4[0x9d]);
          puVar4[0x9d] = 0xffffffff;
        }
        FUN_00011dd4(puVar4);
      }
      if (DAT_00019378 == (LPCRITICAL_SECTION)0x0) {
        iVar6 = 0;
      }
      else {
        bVar1 = FUN_00016d00(DAT_00019378,(undefined4 *)*param_4);
        iVar6 = CONCAT31(extraout_var,bVar1);
      }
    }
    goto LAB_00017d8c;
  }
  if (param_3 == 0x1090024) {
    if (param_4 == (ULONG_PTR *)0x0) {
      return 0;
    }
    if (param_5 < 0x14) {
      return 0;
    }
    iVar6 = FUN_00016f78((int)param_4);
    goto LAB_00017d8c;
  }
  switch(param_3) {
  case 0x1090004:
    if (param_4 == (ULONG_PTR *)0x0) {
      return 0;
    }
    if (param_5 < 0x218) {
      return 0;
    }
    iVar6 = FUN_000175d8((int)param_4);
    break;
  default:
    goto switchD_00017924_caseD_1090005;
  case 0x1090008:
    if (param_4 == (ULONG_PTR *)0x0) {
      return 0;
    }
    if (param_5 < 4) {
      return 0;
    }
    iVar6 = FUN_00017650(*param_4);
    break;
  case 0x109000c:
    if (param_4 == (ULONG_PTR *)0x0) {
      return 0;
    }
    if (param_5 < 4) {
      return 0;
    }
    iVar6 = FUN_000176bc(*param_4);
    break;
  case 0x1090010:
    if (param_4 == (ULONG_PTR *)0x0) {
      return 0;
    }
    if (param_5 < 4) {
      return 0;
    }
    iVar6 = FUN_00017728(*param_4);
    break;
  case 0x1090014:
    if (param_4 == (ULONG_PTR *)0x0) {
      return 0;
    }
    if (param_5 < 4) {
      return 0;
    }
    iVar6 = FUN_00017794(*param_4);
    break;
  case 0x1090018:
    if (param_4 == (ULONG_PTR *)0x0) {
      return 0;
    }
    if (param_5 < 0x10) {
      return 0;
    }
    if (param_6 == (int *)0x0) {
      return 0;
    }
    if (param_7 < 4) {
      return 0;
    }
    iVar2 = FUN_00017800((int)param_4);
    if (iVar2 == 0) {
      return 0;
    }
    iVar6 = 1;
    *param_6 = iVar2;
    if (param_8 != (undefined4 *)0x0) {
      *param_8 = 4;
    }
    goto LAB_00017d94;
  case 0x109001c:
    if (param_4 == (ULONG_PTR *)0x0) {
      return 0;
    }
    if (param_5 < 4) {
      return 0;
    }
    iVar6 = FUN_00016e88(*param_4);
    break;
  case 0x1090020:
    if (param_4 == (ULONG_PTR *)0x0) {
      return 0;
    }
    if (param_5 < 4) {
      return 0;
    }
    iVar6 = FUN_00016f00(*param_4);
  }
LAB_00017d8c:
  if (iVar6 != 0) {
LAB_00017d94:
    DVar5 = GetLastError();
    if (DVar5 == 0x57) {
      SetLastError(dwErrCode);
    }
  }
switchD_00017924_caseD_1090005:
  return iVar6;
}



/* 00017de4 FUN_00017de4 */

/* Boundary evidence: original MIPS .pdata 00017de4..00017fab. Semantic name remains unreviewed. */

undefined4 FUN_00017de4(undefined4 param_1)

{
  LPCRITICAL_SECTION lpCriticalSection;
  undefined4 uVar1;
  int iVar2;
  
  lpCriticalSection = operator_new(0x18);
  if (lpCriticalSection == (LPCRITICAL_SECTION)0x0) {
    DAT_00019378 = (LPCRITICAL_SECTION)0x0;
  }
  else {
    InitializeCriticalSection(lpCriticalSection);
    lpCriticalSection->SpinCount = 0;
    DAT_00019378 = lpCriticalSection;
  }
  DAT_0001912c = CreateAPISet(&DAT_00011528,0xc,&PTR_FUN_00011370,&DAT_000113a0);
  iVar2 = 0;
  if (DAT_0001912c != -1) {
    iVar2 = RegisterAPISet(DAT_0001912c,0x80000007);
  }
  DAT_0001936c = CreateAPISet(&DAT_00011520,0x18,&PTR_LAB_00011400,&DAT_00011460);
  RegisterAPISet(DAT_0001936c,0x80000010);
  DAT_00019130 = RegisterAFSName(param_1);
  if ((DAT_0001936c != 0) && (DAT_00019130 != -1)) {
    DAT_00019370 = RegisterAFSEx(DAT_00019130,DAT_0001936c,0,4,0x101);
  }
  uVar1 = 1;
  if (DAT_00019370 != 0) {
    DAT_00019374 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,1,0,(LPCWSTR)0x0);
  }
  if ((((DAT_00019378 == (LPCRITICAL_SECTION)0x0) || (DAT_00019370 == 0)) ||
      (DAT_00019374 == (HANDLE)0x0)) || ((DAT_0001912c == -1 || (iVar2 == 0)))) {
    uVar1 = 0;
  }
  return uVar1;
}



/* 00017fac FUN_00017fac */

/* Boundary evidence: original MIPS .pdata 00017fac..0001807b. Semantic name remains unreviewed. */

void FUN_00017fac(void)

{
  LPCRITICAL_SECTION p_Var1;
  
  if (DAT_0001912c != -1) {
    CloseHandle((HANDLE)DAT_0001912c);
  }
  if (DAT_00019130 != -1) {
    DeregisterAFS();
    DeregisterAFSName(DAT_00019130);
  }
  if (DAT_0001936c != 0) {
    CloseHandle((HANDLE)DAT_0001936c);
  }
  if (DAT_00019374 != 0) {
    CloseHandle((HANDLE)DAT_00019374);
  }
  p_Var1 = DAT_00019378;
  if (DAT_00019378 != (LPCRITICAL_SECTION)0x0) {
    FUN_000174d4(DAT_00019378);
    operator_delete(p_Var1);
    DAT_00019378 = (LPCRITICAL_SECTION)0x0;
  }
  return;
}



/* 0001807c FUN_0001807c */

/* Boundary evidence: original MIPS .pdata 0001807c..000180cf. Semantic name remains unreviewed. */

void FUN_0001807c(int param_1,undefined4 param_2,uint *param_3)

{
  if ((*param_3 & 1) != 0) {
    param_1 = ((-param_3[2] & param_3[1] + param_1) - (param_3[1] + param_1)) + param_1;
  }
  FUN_000180fc(*(uint *)(param_1 + (*param_3 & 0xfffffffc)));
  return;
}



/* 000180d0 FUN_000180d0 */

/* Boundary evidence: original MIPS .pdata 000180d0..000180fb. Semantic name remains unreviewed. */

undefined4 FUN_000180d0(undefined4 param_1,int param_2,undefined4 param_3,int param_4)

{
  FUN_0001807c(param_2,param_4,*(uint **)(*(int *)(param_4 + 4) + 0xc));
  return 1;
}



/* 000180fc FUN_000180fc */

/* Boundary evidence: original MIPS .pdata 000180fc..00018143. Semantic name remains unreviewed. */

void FUN_000180fc(uint param_1)

{
  if ((param_1 == DAT_00019118) && (param_1 >> 0x10 == 0)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __report_gsfailure();
}



/* 00018324 FUN_00018324 */

/* Boundary evidence: original MIPS .pdata 00018324..0001833f. Semantic name remains unreviewed. */

void FUN_00018324(void)

{
  FUN_00012b68();
  return;
}



/* 00018340 FUN_00018340 */

/* Boundary evidence: original MIPS .pdata 00018340..0001835f. Semantic name remains unreviewed. */

void FUN_00018340(void)

{
  DeleteCriticalSection((LPCRITICAL_SECTION)&DAT_00019150);
  return;
}


