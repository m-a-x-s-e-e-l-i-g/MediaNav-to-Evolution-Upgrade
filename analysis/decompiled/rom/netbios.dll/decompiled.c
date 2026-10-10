/* Automatic Ghidra pseudocode. Not original source; not runtime-verified. */

/* c06b123c FUN_c06b123c */

/* Boundary evidence: original MIPS .pdata c06b123c..c06b12f7. Semantic name remains unreviewed. */

undefined4 FUN_c06b123c(undefined4 param_1,undefined4 param_2)

{
  HMODULE hLibModule;
  code *pcVar1;
  undefined4 uVar2;
  DWORD dwErrCode;
  
  hLibModule = LoadLibraryW(L"k.coredll.dll");
  if (hLibModule == (HMODULE)0x0) {
    dwErrCode = 3;
  }
  else {
    pcVar1 = (code *)GetProcAddressW(hLibModule,L"WaitForAPIReady");
    if (pcVar1 != (code *)0x0) {
      uVar2 = (*pcVar1)(param_1,param_2);
      FreeLibrary(hLibModule);
      return uVar2;
    }
    dwErrCode = 2;
  }
  SetLastError(dwErrCode);
  return 0xffffffff;
}



/* c06b12f8 FUN_c06b12f8 */

/* Boundary evidence: original MIPS .pdata c06b12f8..c06b13e7. Semantic name remains unreviewed. */

undefined4
FUN_c06b12f8(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,undefined4 param_6,undefined4 param_7)

{
  HMODULE hLibModule;
  code *pcVar1;
  undefined4 uVar2;
  DWORD dwErrCode;
  
  hLibModule = LoadLibraryW(L"k.coredll.dll");
  if (hLibModule == (HMODULE)0x0) {
    dwErrCode = 3;
  }
  else {
    pcVar1 = (code *)GetProcAddressW(hLibModule,L"CeCallUserProc");
    if (pcVar1 != (code *)0x0) {
      uVar2 = (*pcVar1)(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
      FreeLibrary(hLibModule);
      return uVar2;
    }
    dwErrCode = 2;
  }
  SetLastError(dwErrCode);
  return 0;
}



/* c06b13e8 FUN_c06b13e8 */

/* Boundary evidence: original MIPS .pdata c06b13e8..c06b1453. Semantic name remains unreviewed. */

undefined4 FUN_c06b13e8(undefined4 param_1)

{
  int iVar1;
  undefined4 local_18 [2];
  undefined4 local_10;
  undefined4 local_c;
  
  local_18[0] = 0;
  local_10 = 0;
  local_c = param_1;
  iVar1 = FUN_c06b123c(0x51,60000);
  if (iVar1 == 0) {
    FUN_c06b12f8(L"netui.dll",L"GetNetStringSizeExt",&local_10,8,&local_10,8,local_18);
  }
  return local_10;
}



/* c06b1454 FUN_c06b1454 */

/* Boundary evidence: original MIPS .pdata c06b1454..c06b156f. Semantic name remains unreviewed. */

undefined4 FUN_c06b1454(undefined4 param_1,void *param_2,uint param_3)

{
  undefined4 *hMem;
  int iVar1;
  uint uBytes;
  undefined4 uVar2;
  undefined4 local_20 [2];
  
  local_20[0] = 0;
  if (((int)((ulonglong)param_3 * 2 >> 0x20) == 0) &&
     (uBytes = (int)((ulonglong)param_3 * 2) + 0x10, 0xf < uBytes)) {
    hMem = LocalAlloc(0x40,uBytes);
    if (hMem != (undefined4 *)0x0) {
      *hMem = 0;
      hMem[1] = param_1;
      hMem[2] = param_3;
      iVar1 = FUN_c06b123c(0x51,60000);
      if ((iVar1 == 0) &&
         (iVar1 = FUN_c06b12f8(L"netui.dll",L"GetNetStringExt",hMem,uBytes,hMem,uBytes,local_20),
         iVar1 != 0)) {
        memcpy(param_2,hMem + 3,hMem[2] << 1);
      }
      uVar2 = *hMem;
      LocalFree(hMem);
      return uVar2;
    }
  }
  else {
    SetLastError(0x57);
  }
  return 0;
}



/* c06b1570 FUN_c06b1570 */

/* Boundary evidence: original MIPS .pdata c06b1570..c06b1727. Semantic name remains unreviewed. */

undefined4 FUN_c06b1570(undefined4 param_1,undefined4 param_2,undefined4 param_3,va_list param_4)

{
  int iVar1;
  HLOCAL lpSource;
  DWORD DVar2;
  size_t sVar3;
  undefined4 uVar4;
  SIZE_T uBytes;
  undefined4 *hMem;
  va_list local_resc;
  wchar_t *local_28;
  undefined4 local_24;
  
  local_24 = 0;
  local_28 = (wchar_t *)0x0;
  hMem = (undefined4 *)0x0;
  local_resc = param_4;
  iVar1 = FUN_c06b123c(0x51,60000);
  if (iVar1 != 0) {
    return 0;
  }
  iVar1 = FUN_c06b13e8(param_3);
  if (iVar1 == 0) {
    uVar4 = 0;
    goto LAB_c06b16dc;
  }
  lpSource = LocalAlloc(0x40,(iVar1 + 1U) * 2);
  if (lpSource == (HLOCAL)0x0) {
LAB_c06b15fc:
    uVar4 = 0;
  }
  else {
    DVar2 = FUN_c06b1454(param_3,lpSource,iVar1 + 1U);
    DVar2 = FormatMessageW(0x500,lpSource,0,0,(LPWSTR)&local_28,DVar2,&local_resc);
    if (DVar2 == 0) goto LAB_c06b15fc;
    sVar3 = wcslen(local_28);
    sVar3 = (sVar3 + 1) * 2;
    uBytes = sVar3 + 0x10;
    hMem = LocalAlloc(0x40,uBytes);
    if (hMem == (undefined4 *)0x0) goto LAB_c06b15fc;
    *hMem = 0;
    hMem[1] = param_1;
    hMem[2] = param_2;
    memcpy(hMem + 3,local_28,sVar3);
    iVar1 = FUN_c06b12f8(L"netui.dll",L"NetMsgBoxExt",hMem,uBytes,hMem,uBytes,&local_24);
    uVar4 = 0;
    if (iVar1 != 0) {
      uVar4 = *hMem;
    }
  }
  if (lpSource != (HLOCAL)0x0) {
    LocalFree(lpSource);
  }
LAB_c06b16dc:
  if (local_28 != (wchar_t *)0x0) {
    LocalFree(local_28);
  }
  if (hMem != (undefined4 *)0x0) {
    LocalFree(hMem);
  }
  return uVar4;
}



/* c06b1728 FUN_c06b1728 */

/* Boundary evidence: original MIPS .pdata c06b1728..c06b174b. Semantic name remains unreviewed. */

void FUN_c06b1728(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 local_resc;
  
  local_resc = param_4;
  FUN_c06b1570(param_1,param_2,param_3,(va_list)&local_resc);
  return;
}



/* c06b174c FUN_c06b174c */

/* Boundary evidence: original MIPS .pdata c06b174c..c06b194b. Semantic name remains unreviewed. */

undefined4 FUN_c06b174c(LPSTR param_1)

{
  char cVar1;
  LSTATUS LVar2;
  int iVar3;
  uint uVar4;
  undefined4 uVar5;
  DWORD local_70;
  HKEY local_6c;
  wchar_t awStack_68 [20];
  wchar_t awStack_40 [18];
  uint local_1c;
  
  local_1c = DAT_c06bc0f4;
  uVar5 = 0;
  LVar2 = RegOpenKeyExW((HKEY)0x80000002,L"Ident",0,0,&local_6c);
  if (LVar2 == 0) {
    memset(awStack_40,0,0x22);
    local_70 = 0x22;
    RegQueryValueExW(local_6c,L"OrigName",(LPDWORD)0x0,(LPDWORD)0x0,(LPBYTE)awStack_40,&local_70);
    memset(awStack_68,0,0x22);
    local_70 = 0x22;
    LVar2 = RegQueryValueExW(local_6c,L"Name",(LPDWORD)0x0,(LPDWORD)0x0,(LPBYTE)awStack_68,&local_70
                            );
    if ((LVar2 == 0) && (iVar3 = _wcsicmp(awStack_68,awStack_40), iVar3 != 0)) {
      WideCharToMultiByte(0,0,awStack_68,0x10,param_1,0x10,(LPCSTR)0x0,(LPBOOL)0x0);
      local_70 = (local_70 >> 1) - 1;
      uVar4 = 0;
      if (local_70 != 0) {
        do {
          cVar1 = param_1[uVar4];
          if (('`' < cVar1) && (cVar1 < '{')) {
            param_1[uVar4] = cVar1 + -0x20;
          }
          uVar4 = uVar4 + 1;
        } while (uVar4 < local_70);
      }
      for (; local_70 < 0xf; local_70 = local_70 + 1) {
        param_1[local_70] = ' ';
      }
      uVar5 = 1;
      FUN_c06b3b20(&DAT_c06bc660,(int)param_1);
    }
    RegCloseKey(local_6c);
  }
  FUN_c06bac58(local_1c);
  return uVar5;
}



/* c06b194c FUN_c06b194c */

char FUN_c06b194c(void)

{
  bool bVar1;
  int *piVar2;
  char cVar3;
  char cVar4;
  
  bVar1 = true;
  cVar4 = '\0';
  cVar3 = DAT_c06bc0bc;
  do {
    if (!bVar1) break;
    if (cVar3 == -1) {
      cVar3 = '\0';
      DAT_c06bc0bc = '\0';
    }
    if (cVar3 == '\0') {
      cVar3 = '\x01';
      DAT_c06bc0bc = '\x01';
    }
    bVar1 = false;
    for (piVar2 = (int *)DAT_c06bc684; piVar2 != (int *)0x0; piVar2 = (int *)*piVar2) {
      if (*(char *)(piVar2 + 0xe) == cVar3) {
        DAT_c06bc0bc = cVar3 + '\x01';
        bVar1 = true;
        cVar3 = DAT_c06bc0bc;
        break;
      }
    }
    cVar4 = cVar4 + '\x01';
  } while (cVar4 != -1);
  if (cVar4 != -1) {
    DAT_c06bc0bc = cVar3 + '\x01';
    cVar4 = cVar3;
  }
  return cVar4;
}



/* c06b1a00 FUN_c06b1a00 */

/* Boundary evidence: original MIPS .pdata c06b1a00..c06b1a6f. Semantic name remains unreviewed. */

int * FUN_c06b1a00(uint param_1)

{
  int iVar1;
  int *piVar2;
  
  piVar2 = &DAT_c06bc684;
  iVar1 = DAT_c06bc684;
  while( true ) {
    if (iVar1 == 0) {
      return piVar2;
    }
    EnterCriticalSection((LPCRITICAL_SECTION)(iVar1 + 0x1c));
    if (*(byte *)(*piVar2 + 0x38) == param_1) break;
    LeaveCriticalSection((LPCRITICAL_SECTION)(*piVar2 + 0x1c));
    piVar2 = (int *)*piVar2;
    iVar1 = *piVar2;
  }
  return piVar2;
}



/* c06b1a70 FUN_c06b1a70 */

/* Boundary evidence: original MIPS .pdata c06b1a70..c06b1aff. Semantic name remains unreviewed. */

int FUN_c06b1a70(int param_1)

{
  int *piVar1;
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c06bc620);
  for (piVar1 = (int *)DAT_c06bc684; piVar1 != (int *)0x0; piVar1 = (int *)*piVar1) {
    EnterCriticalSection((LPCRITICAL_SECTION)(piVar1 + 7));
    if (piVar1[0xc] == param_1) break;
    LeaveCriticalSection((LPCRITICAL_SECTION)(piVar1 + 7));
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c06bc620);
  return (int)piVar1;
}



/* c06b1b00 FUN_c06b1b00 */

/* Boundary evidence: original MIPS .pdata c06b1b00..c06b1b83. Semantic name remains unreviewed. */

int FUN_c06b1b00(uint param_1)

{
  int *piVar1;
  int iVar2;
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c06bc620);
  piVar1 = FUN_c06b1a00(param_1);
  iVar2 = *piVar1;
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c06bc620);
  if (iVar2 != 0) {
    if ((*(byte *)(iVar2 + 0x39) & 1) == 0) {
      *(short *)(iVar2 + 0x36) = *(short *)(iVar2 + 0x36) + 1;
    }
    else {
      LeaveCriticalSection((LPCRITICAL_SECTION)(iVar2 + 0x1c));
      iVar2 = 0;
    }
  }
  return iVar2;
}



/* c06b1b84 FUN_c06b1b84 */

/* Boundary evidence: original MIPS .pdata c06b1b84..c06b1de3. Semantic name remains unreviewed. */

void FUN_c06b1b84(int param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  LPCRITICAL_SECTION lpCriticalSection;
  undefined4 *puVar3;
  
  puVar1 = *(undefined4 **)(param_1 + 0x14);
  while (puVar1 != (undefined4 *)0x0) {
    puVar3 = (undefined4 *)*puVar1;
    LocalFree(puVar1);
    puVar1 = puVar3;
  }
  *(undefined4 *)(param_1 + 0x14) = 0;
  puVar1 = *(undefined4 **)(param_1 + 0x10);
  while (puVar1 != (undefined4 *)0x0) {
    EnterCriticalSection((LPCRITICAL_SECTION)(puVar1 + 0x17));
    puVar1[0x11] = puVar1[0x11] | 0x80000;
    EventModify(puVar1[0x14],3);
    while (puVar3 = (undefined4 *)puVar1[0x15], puVar3 != (undefined4 *)0x0) {
      EnterCriticalSection((LPCRITICAL_SECTION)(puVar3 + 0x10));
      puVar3[6] = puVar3[6] | 8;
      puVar1[0x15] = *puVar3;
      *puVar3 = 0;
      EventModify(puVar3[3],3);
      EventModify(puVar3[4],3);
      LeaveCriticalSection((LPCRITICAL_SECTION)(puVar3 + 0x10));
      FUN_c06b475c(puVar3);
    }
    puVar3 = puVar1 + 0x16;
    while (puVar2 = puVar3, puVar3 = (undefined4 *)*puVar2, puVar3 != (undefined4 *)0x0) {
      if (*(char *)(puVar3[9] + 0x30) == *(char *)(param_1 + 0x38)) {
        *puVar2 = *puVar3;
        puVar3[2] = 0x14;
        EventModify(puVar3[1],3);
        puVar3 = puVar2;
      }
    }
    puVar3 = (undefined4 *)*puVar1;
    LeaveCriticalSection((LPCRITICAL_SECTION)(puVar1 + 0x17));
    FUN_c06b50f0(puVar1);
    puVar1 = puVar3;
  }
  *(undefined4 *)(param_1 + 0x10) = 0;
  while (puVar1 = *(undefined4 **)(param_1 + 0x18), puVar1 != (undefined4 *)0x0) {
    *(undefined4 *)(param_1 + 0x18) = *puVar1;
    *puVar1 = 0;
    puVar1[2] = 0x14;
    EventModify(puVar1[1],3);
  }
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c06bc5a0);
  puVar1 = &DAT_c06bc580;
  for (puVar3 = DAT_c06bc580; puVar3 != (undefined4 *)0x0; puVar3 = (undefined4 *)*puVar3) {
    lpCriticalSection = (LPCRITICAL_SECTION)(puVar3 + 0x10);
    EnterCriticalSection(lpCriticalSection);
    if (*(char *)(puVar3 + 0x15) == *(char *)(param_1 + 0x38)) {
      puVar3[6] = puVar3[6] | 8;
      *puVar1 = *puVar3;
      *puVar3 = 0;
      if (puVar3[2] != 0) {
        puVar3[2] = 0;
        (*(code *)*DAT_c06bc5dc)();
      }
      EventModify(puVar3[4],3);
      EventModify(puVar3[3],3);
      LeaveCriticalSection(lpCriticalSection);
      FUN_c06b475c(puVar3);
      puVar3 = puVar1;
    }
    else {
      LeaveCriticalSection(lpCriticalSection);
    }
    puVar1 = puVar3;
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c06bc5a0);
  return;
}



/* c06b1de4 FUN_c06b1de4 */

/* Boundary evidence: original MIPS .pdata c06b1de4..c06b1eb7. Semantic name remains unreviewed. */

void FUN_c06b1de4(int *param_1)

{
  byte bVar1;
  int *piVar2;
  LPCRITICAL_SECTION lpCriticalSection;
  short sVar3;
  int *piVar4;
  LPCRITICAL_SECTION lpCriticalSection_00;
  
  sVar3 = *(short *)((int)param_1 + 0x36) + -1;
  bVar1 = *(byte *)(param_1 + 0xe);
  *(short *)((int)param_1 + 0x36) = sVar3;
  if (sVar3 != 0) {
    LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 7));
    return;
  }
  lpCriticalSection_00 = (LPCRITICAL_SECTION)(param_1 + 7);
  LeaveCriticalSection(lpCriticalSection_00);
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c06bc620);
  piVar2 = FUN_c06b1a00((uint)bVar1);
  piVar4 = (int *)*piVar2;
  if (param_1 == piVar4) {
    *piVar2 = *param_1;
    *param_1 = 0;
    lpCriticalSection = lpCriticalSection_00;
  }
  else {
    if (piVar4 == (int *)0x0) goto LAB_c06b1e74;
    lpCriticalSection = (LPCRITICAL_SECTION)(piVar4 + 7);
  }
  LeaveCriticalSection(lpCriticalSection);
LAB_c06b1e74:
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c06bc620);
  DeleteCriticalSection(lpCriticalSection_00);
  LocalFree(param_1);
  return;
}



/* c06b1eb8 FUN_c06b1eb8 */

void FUN_c06b1eb8(int param_1)

{
  int iVar1;
  
  iVar1 = param_1;
  if (DAT_c06bc6bc != 0) {
    *DAT_c06bc6b8 = param_1;
    iVar1 = DAT_c06bc6bc;
  }
  DAT_c06bc6bc = iVar1;
  DAT_c06bc6b8 = (int *)param_1;
  return;
}



/* c06b1ee0 FUN_c06b1ee0 */

/* Boundary evidence: original MIPS .pdata c06b1ee0..c06b2117. Semantic name remains unreviewed. */

void FUN_c06b1ee0(void)

{
  undefined4 *hMem;
  int iVar1;
  undefined4 in_a3;
  int *piVar2;
  undefined4 *puVar3;
  int *piVar4;
  undefined4 local_70 [2];
  undefined2 local_68;
  undefined1 auStack_50 [16];
  undefined1 local_40;
  CHAR aCStack_38 [16];
  uint local_28;
  
  local_28 = DAT_c06bc0f4;
  iVar1 = FUN_c06b174c(aCStack_38);
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c06bc6a0);
  while( true ) {
    hMem = DAT_c06bc6bc;
    if (DAT_c06bc6bc == (HLOCAL)0x0) break;
    puVar3 = DAT_c06bc6bc;
    DAT_c06bc6bc = (HLOCAL)*DAT_c06bc6bc;
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c06bc6a0);
    if (iVar1 != 0) {
      memcpy(auStack_50,aCStack_38,0x10);
      local_70[0] = 0;
      local_40 = *(undefined1 *)(hMem + 3);
      local_68 = 7;
      FUN_c06b5b68((int)local_70);
    }
    if ((code *)hMem[2] != (code *)0x0) {
      (*(code *)hMem[2])(*(undefined1 *)(hMem + 3),hMem[1],0,in_a3,puVar3);
    }
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c06bc640);
    piVar2 = DAT_c06bc634;
    piVar4 = DAT_c06bc634;
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c06bc640);
    while (piVar2 != (int *)0x0) {
      if ((HLOCAL)piVar2[2] == (HLOCAL)0x0) {
        if (hMem[2] == 0) {
          (*(code *)piVar2[1])(*(undefined1 *)(hMem + 3),hMem[1],0,in_a3,puVar3,piVar4);
        }
      }
      else if ((HLOCAL)piVar2[2] == hMem) {
        piVar2[2] = 0;
      }
      piVar2 = (int *)*piVar2;
      piVar4 = piVar2;
    }
    LocalFree(hMem);
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c06bc6a0);
  }
  DAT_c06bc6b4 = 0;
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c06bc6a0);
  FUN_c06bac58(local_28);
  return;
}



/* c06b2118 FUN_c06b2118 */

/* Boundary evidence: original MIPS .pdata c06b2118..c06b2123. Semantic name remains unreviewed. */

undefined4 FUN_c06b2118(void)

{
  return 1;
}



/* c06b2124 FUN_c06b2124 */

/* Boundary evidence: original MIPS .pdata c06b2124..c06b212f. Semantic name remains unreviewed. */

undefined4 FUN_c06b2124(void)

{
  return 1;
}



/* c06b2130 FUN_c06b2130 */

/* Boundary evidence: original MIPS .pdata c06b2130..c06b23b3. Semantic name remains unreviewed. */

undefined4 FUN_c06b2130(void *param_1,size_t param_2,undefined4 param_3,undefined4 param_4)

{
  char cVar1;
  int iVar2;
  int iVar3;
  char *pcVar4;
  char *pcVar5;
  undefined4 uVar6;
  int iVar7;
  int iVar8;
  int *piVar9;
  int iVar10;
  undefined4 local_98 [2];
  undefined2 local_90;
  undefined1 auStack_78 [16];
  char local_68;
  char local_60 [15];
  char local_51 [25];
  CHAR aCStack_38 [16];
  uint local_28;
  
  local_28 = DAT_c06bc0f4;
  if ((int)param_2 < 1) {
    FUN_c06bac58(DAT_c06bc0f4);
    uVar6 = 2;
  }
  else {
    iVar10 = 0;
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c06bc620);
    piVar9 = (int *)DAT_c06bc684;
    for (iVar8 = 0; (piVar9 != (int *)0x0 && (iVar8 < 0x14)); iVar8 = iVar8 + 1) {
      EnterCriticalSection((LPCRITICAL_SECTION)(piVar9 + 7));
      local_51[iVar8 + 1] = *(char *)(piVar9 + 0xe);
      LeaveCriticalSection((LPCRITICAL_SECTION)(piVar9 + 7));
      piVar9 = (int *)*piVar9;
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c06bc620);
    if (param_1 != (void *)0x0) {
      if (0x10 < (int)param_2) {
        param_2 = 0x10;
      }
      memcpy(local_60,param_1,param_2);
      iVar3 = 0;
      if (0 < (int)param_2) {
        do {
          cVar1 = local_60[iVar3];
          if (('`' < cVar1) && (cVar1 < '{')) {
            local_60[iVar3] = cVar1 + -0x20;
          }
          iVar3 = iVar3 + 1;
        } while (iVar3 < (int)param_2);
      }
      if ((int)param_2 < 0xf) {
        pcVar5 = local_60 + param_2;
        iVar3 = 0xf - param_2;
        if (iVar3 != 0) {
          pcVar4 = pcVar5 + iVar3;
          do {
            *pcVar5 = ' ';
            pcVar5 = pcVar5 + 1;
          } while (pcVar5 != pcVar4);
        }
        param_2 = iVar3 + param_2;
      }
      if ((int)param_2 < 0x10) {
        local_51[0] = '\0';
      }
    }
    iVar3 = FUN_c06b174c(aCStack_38);
    iVar7 = 0;
    if (0 < iVar8) {
      do {
        if (param_1 != (void *)0x0) {
          memcpy(auStack_78,local_60,0x10);
          local_68 = local_51[iVar7 + 1];
          local_98[0] = 0;
          local_90 = 10;
          FUN_c06b5dac((int)local_98);
        }
        if (iVar3 != 0) {
          memcpy(auStack_78,aCStack_38,0x10);
          local_68 = local_51[iVar7 + 1];
          local_98[0] = 0;
          local_90 = 7;
          iVar2 = FUN_c06b5b68((int)local_98);
          if (iVar2 == 0) {
            iVar10 = iVar10 + 1;
          }
        }
        iVar7 = iVar7 + 1;
      } while (iVar7 < iVar8);
    }
    if ((iVar8 == 0) || (iVar10 != 0)) {
      uVar6 = 0;
    }
    else {
      FUN_c06b1728(0,0xb,5,param_4);
      uVar6 = 2;
    }
    FUN_c06bac58(local_28);
  }
  return uVar6;
}



/* c06b23b4 FUN_c06b23b4 */

/* Boundary evidence: original MIPS .pdata c06b23b4..c06b243f. Semantic name remains unreviewed. */

uint FUN_c06b23b4(uint param_1)

{
  int *piVar1;
  uint uVar2;
  
  uVar2 = 0xffffffff;
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c06bc620);
  piVar1 = (int *)DAT_c06bc684;
  do {
    if (piVar1 == (int *)0x0) {
LAB_c06b241c:
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c06bc620);
      return uVar2;
    }
    if (*(ushort *)(piVar1 + 0xd) == param_1) {
      uVar2 = (uint)*(byte *)(piVar1 + 0xe);
      goto LAB_c06b241c;
    }
    piVar1 = (int *)*piVar1;
  } while( true );
}



/* c06b2440 FUN_c06b2440 */

/* Boundary evidence: original MIPS .pdata c06b2440..c06b24af. Semantic name remains unreviewed. */

void FUN_c06b2440(void)

{
  HANDLE hObject;
  DWORD aDStack_10 [2];
  
  if (DAT_c06bc6b4 == 0) {
    hObject = CreateThread((LPSECURITY_ATTRIBUTES)0x0,0,FUN_c06b1ee0,(LPVOID)0x0,0,aDStack_10);
    if (hObject != (HANDLE)0x0) {
      CloseHandle(hObject);
      DAT_c06bc6b4 = 1;
    }
  }
  return;
}



/* c06b24b0 FUN_c06b24b0 */

/* Boundary evidence: original MIPS .pdata c06b24b0..c06b25cf. Semantic name remains unreviewed. */

void FUN_c06b24b0(int param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int *piVar3;
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c06bc620);
  piVar3 = DAT_c06bc684;
  do {
    if (piVar3 == (int *)0x0) {
LAB_c06b2500:
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c06bc620);
      return;
    }
    if (piVar3[0xc] == param_1) {
      if ((*(byte *)((int)piVar3 + 0x39) & 1) == 0) {
        EnterCriticalSection((LPCRITICAL_SECTION)(piVar3 + 7));
        LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c06bc620);
        *(byte *)((int)piVar3 + 0x39) = *(byte *)((int)piVar3 + 0x39) | 1;
        puVar2 = LocalAlloc(0x40,0x10);
        if (puVar2 != (HLOCAL)0x0) {
          puVar2[1] = *(byte *)((int)piVar3 + 0x39) & 2;
          *(char *)(puVar2 + 3) = (char)piVar3[0xe];
          EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c06bc6a0);
          puVar1 = puVar2;
          if (DAT_c06bc6bc != (undefined4 *)0x0) {
            *DAT_c06bc6b8 = puVar2;
            puVar1 = DAT_c06bc6bc;
          }
          DAT_c06bc6bc = puVar1;
          DAT_c06bc6b8 = puVar2;
          FUN_c06b2440();
          LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c06bc6a0);
        }
        FUN_c06b1b84((int)piVar3);
        FUN_c06b1de4(piVar3);
        return;
      }
      goto LAB_c06b2500;
    }
    piVar3 = (int *)*piVar3;
  } while( true );
}



/* c06b25d0 LanaUp */

/* Boundary evidence: original MIPS .pdata c06b25d0..c06b282b. Semantic name remains unreviewed. */

void LanaUp(uint param_1,undefined2 param_2,uint param_3,uint param_4,uint param_5,
           undefined4 *param_6)

{
  undefined4 *puVar1;
  char cVar2;
  int *hMem;
  undefined4 *puVar3;
  LPCRITICAL_SECTION lpCriticalSection;
  undefined4 uVar4;
  
                    /* 0x25d0  1  LanaUp */
  uVar4 = 1;
  if ((param_5 & 1) == 0) {
    hMem = LocalAlloc(0x40,0x40);
    if (hMem != (int *)0x0) {
      lpCriticalSection = (LPCRITICAL_SECTION)(hMem + 7);
      InitializeCriticalSection(lpCriticalSection);
      *(undefined1 *)((int)hMem + 0x39) = 0;
      if ((param_5 & 0x10) != 0) {
        *(undefined1 *)((int)hMem + 0x39) = 2;
        uVar4 = 3;
      }
      *(undefined2 *)(hMem + 0xd) = param_2;
      hMem[2] = param_4;
      hMem[1] = param_3;
      hMem[3] = ~param_4 | param_3;
      hMem[0xc] = param_1 & 0xffffff;
      *(undefined2 *)((int)hMem + 0x36) = 1;
      if (param_6 != (undefined4 *)0x0) {
        *(undefined4 *)((int)hMem + 0x3a) = *param_6;
        *(undefined2 *)((int)hMem + 0x3e) = *(undefined2 *)(param_6 + 1);
      }
      EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c06bc620);
      if (param_3 == 0x100007f) {
        *(undefined1 *)(hMem + 0xe) = 0;
      }
      else {
        cVar2 = FUN_c06b194c();
        *(char *)(hMem + 0xe) = cVar2;
      }
      if ((char)hMem[0xe] == -1) {
        LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c06bc620);
        DeleteCriticalSection(lpCriticalSection);
        LocalFree(hMem);
      }
      else {
        if ((DAT_c06bc684 == (int *)0x0) && (DAT_c06bc57c == 0)) {
          DAT_c06bc57c = 1;
          CTEStartTimer(&DAT_c06bc560,60000,FUN_c06b4e64,0);
        }
        *hMem = (int)DAT_c06bc684;
        DAT_c06bc684 = hMem;
        EnterCriticalSection(lpCriticalSection);
        LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c06bc620);
        puVar3 = LocalAlloc(0x40,0x10);
        if (puVar3 != (HLOCAL)0x0) {
          puVar3[1] = uVar4;
          *(char *)(puVar3 + 3) = (char)hMem[0xe];
          EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c06bc6a0);
          puVar1 = puVar3;
          if (DAT_c06bc6bc != (undefined4 *)0x0) {
            *DAT_c06bc6b8 = puVar3;
            puVar1 = DAT_c06bc6bc;
          }
          DAT_c06bc6bc = puVar1;
          DAT_c06bc6b8 = puVar3;
          LeaveCriticalSection(lpCriticalSection);
          FUN_c06b2440();
          LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c06bc6a0);
        }
      }
    }
  }
  else {
    FUN_c06b24b0(param_1 & 0xffffff);
  }
  return;
}



/* c06b282c FUN_c06b282c */

/* Boundary evidence: original MIPS .pdata c06b282c..c06b2893. Semantic name remains unreviewed. */

undefined4 FUN_c06b282c(int *param_1)

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



/* c06b2894 NBT_Deinit */

undefined4 NBT_Deinit(void)

{
                    /* 0x2894  3  NBT_Deinit */
  return 1;
}



/* c06b289c NBT_Init */

/* Boundary evidence: original MIPS .pdata c06b289c..c06b2997. Semantic name remains unreviewed. */

undefined4 NBT_Init(void)

{
  LSTATUS LVar1;
  DWORD local_28 [3];
  HKEY local_1c;
  undefined4 auStack_18 [2];
  uint local_10;
  
                    /* 0x289c  5  NBT_Init */
  local_10 = DAT_c06bc0f4;
  LVar1 = RegOpenKeyExW((HKEY)0x80000002,L"Comm\\NetBIOS",0,0x20019,&local_1c);
  if (LVar1 == 0) {
    local_28[1] = 4;
    LVar1 = RegQueryValueExW(local_1c,L"EnableLoopBack",(LPDWORD)0x0,local_28,(LPBYTE)(local_28 + 2)
                             ,local_28 + 1);
    if (((LVar1 == 0) && (local_28[0] == 4)) && (local_28[2] != 0)) {
      memset(auStack_18,0,6);
      LanaUp(0,0,0x100007f,0xffffffff,0x10,auStack_18);
    }
  }
  FUN_c06bac58(local_10);
  return 1;
}



/* c06b2998 NBT_PowerDown */

void NBT_PowerDown(void)

{
                    /* 0x2998  7  NBT_PowerDown
                       0x2998  8  NBT_PowerUp */
  return;
}



/* c06b29a0 NBT_Open */

undefined4 NBT_Open(void)

{
                    /* 0x29a0  6  NBT_Open */
  return 0xabcdef01;
}



/* c06b29ac NBT_Close */

undefined4 NBT_Close(void)

{
                    /* 0x29ac  2  NBT_Close
                       0x29ac  9  NBT_Read
                       0x29ac  10  NBT_Seek
                       0x29ac  11  NBT_Write */
  return 0;
}



/* c06b29b4 FUN_c06b29b4 */

/* Boundary evidence: original MIPS .pdata c06b29b4..c06b2a87. Semantic name remains unreviewed. */

int FUN_c06b29b4(int *param_1,int param_2,int param_3,int param_4,undefined4 param_5,int param_6)

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
        FUN_c06b282c(param_1);
      }
    }
  }
  return iVar1;
}



/* c06b2a88 NBT_IOControl */

/* Boundary evidence: original MIPS .pdata c06b2a88..c06b2c27. Semantic name remains unreviewed. */

UCHAR NBT_IOControl(undefined4 param_1,int param_2,int param_3,int param_4)

{
  UCHAR UVar1;
  int iVar2;
  int local_68 [3];
  undefined4 local_5c;
  int local_50 [3];
  undefined4 local_44;
  int local_38 [3];
  undefined4 local_2c;
  
                    /* 0x2a88  4  NBT_IOControl */
  local_38[1] = 0;
  UVar1 = '\0';
  local_38[0] = 0;
  local_2c = 0;
  local_50[1] = 0;
  local_50[0] = 0;
  local_44 = 0;
  local_68[1] = 0;
  local_68[0] = 0;
  local_5c = 0;
  if ((param_2 == 0x1000) && (param_4 == 0x18)) {
    if ((((*(int *)(param_3 + 4) == 0) ||
         (iVar2 = FUN_c06b29b4(local_38,*(int *)(param_3 + 4),0x34,0xc,1,0), -1 < iVar2)) &&
        ((*(int *)(param_3 + 0xc) == 0 ||
         (iVar2 = FUN_c06b29b4(local_50,*(int *)(param_3 + 0xc),*(int *)(param_3 + 8),0xc,1,0),
         -1 < iVar2)))) &&
       ((*(int *)(param_3 + 0x14) == 0 ||
        (iVar2 = FUN_c06b29b4(local_68,*(int *)(param_3 + 0x14),*(int *)(param_3 + 0x10),0xc,1,0),
        -1 < iVar2)))) {
      UVar1 = Netbios((PNCB)0x0);
    }
    else {
      SetLastError(0x57);
    }
  }
  FUN_c06b282c(local_68);
  FUN_c06b282c(local_50);
  FUN_c06b282c(local_38);
  return UVar1;
}



/* c06b2c28 FUN_c06b2c28 */

/* Boundary evidence: original MIPS .pdata c06b2c28..c06b2d8f. Semantic name remains unreviewed. */

void FUN_c06b2c28(void)

{
  bool bVar1;
  LSTATUS LVar2;
  int iVar3;
  DWORD dwIndex;
  undefined4 local_250;
  HKEY local_24c;
  DWORD local_248 [4];
  WCHAR aWStack_238 [260];
  uint local_30;
  
  local_30 = DAT_c06bc0f4;
  bVar1 = false;
  local_250 = 0;
  LVar2 = RegOpenKeyExW((HKEY)0x80000002,L"Comm\\NetBIOS",0,0x20019,&local_24c);
  if (LVar2 == 0) {
    dwIndex = 0;
    while( true ) {
      local_248[0] = 4;
      local_248[1] = 0x104;
      LVar2 = RegEnumValueW(local_24c,dwIndex,aWStack_238,local_248 + 1,(LPDWORD)0x0,local_248 + 2,
                            (LPBYTE)&local_250,local_248);
      if (LVar2 != 0) break;
      iVar3 = lstrcmpiW(aWStack_238,L"SessionConnectAttempts");
      if (iVar3 == 0) {
        bVar1 = true;
        DAT_c06bc604 = local_250;
        goto LAB_c06b2d3c;
      }
      dwIndex = dwIndex + 1;
    }
    if (LVar2 == 0x103) {
      bVar1 = false;
    }
LAB_c06b2d3c:
    RegCloseKey(local_24c);
    if (bVar1) goto LAB_c06b2d5c;
  }
  DAT_c06bc604 = 3;
LAB_c06b2d5c:
  FUN_c06bac58(local_30);
  return;
}



/* c06b2d90 FUN_c06b2d90 */

/* Boundary evidence: original MIPS .pdata c06b2d90..c06b3193. Semantic name remains unreviewed. */

bool FUN_c06b2d90(void)

{
  bool bVar1;
  int iVar2;
  LSTATUS LVar3;
  HMODULE pHVar4;
  HANDLE hObject;
  undefined4 local_150;
  HKEY local_14c;
  DWORD aDStack_148 [2];
  undefined2 local_140;
  undefined2 local_13e;
  undefined4 local_13c;
  wchar_t awStack_130 [128];
  uint local_30;
  
  local_30 = DAT_c06bc0f4;
  hObject = (HANDLE)0x0;
  local_150 = 1;
  InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_c06bc5e0);
  InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_c06bc5a0);
  InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_c06bc5c0);
  InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_c06bc120);
  InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_c06bc620);
  InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_c06bc140);
  InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_c06bc6a0);
  InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_c06bc640);
  CTEInitTimer(&DAT_c06bc560);
  memset(&local_140,0,0x10);
  local_140 = 2;
  local_13e = 0x8900;
  local_13c = 0;
  DAT_c06bc5f4 = (**(code **)(DAT_c06bc600 + 8))(0x80000002,2,0,0,0);
  if (DAT_c06bc5f4 == 0) {
    bVar1 = false;
  }
  else {
    iVar2 = (*(code *)DAT_c06bc5dc[3])(DAT_c06bc5f4,&local_140,0x10);
    bVar1 = iVar2 != -1;
  }
  iVar2 = (*(code *)DAT_c06bc5dc[0xd])(DAT_c06bc5f4,0xffff,0x8001,&local_150,4);
  if (iVar2 != 0) {
    bVar1 = false;
  }
  DAT_c06bc5d8 = (**(code **)(DAT_c06bc600 + 8))(0x80000002,2,0,0,0);
  if (DAT_c06bc5d8 == 0) {
    bVar1 = false;
  }
  else {
    iVar2 = (*(code *)DAT_c06bc5dc[0xd])(DAT_c06bc5d8,0xffff,0x8001,&local_150,4);
    if (iVar2 != 0) {
      bVar1 = false;
    }
    memset(&local_140,0,0x10);
    local_13e = 0x8a00;
    local_140 = 2;
    local_13c = 0;
    iVar2 = (*(code *)DAT_c06bc5dc[3])(DAT_c06bc5d8,&local_140,0x10);
    if (iVar2 == -1) {
      bVar1 = false;
    }
    else {
      DAT_c06bc54c = (HLOCAL)FUN_c06b3ae4();
      if (DAT_c06bc54c == (HLOCAL)0x0) {
        bVar1 = false;
      }
      else {
        hObject = CreateThread((LPSECURITY_ATTRIBUTES)0x0,0,FUN_c06b76a0,(LPVOID)0x0,0,aDStack_148);
        if (hObject == (HANDLE)0x0) {
          bVar1 = false;
        }
        if (bVar1) {
          wcscpy(awStack_130,L"Comm\\");
          wcscat(awStack_130,L"Netbios");
          LVar3 = RegOpenKeyExW((HKEY)0x80000002,awStack_130,0,0,&local_14c);
          if (LVar3 == 0) {
            GetRegDWORDValue(local_14c,L"LocalNamesOnly",&DAT_c06bc5f8);
            RegCloseKey(local_14c);
          }
          pHVar4 = LoadLibraryW(L"Autoras.dll");
          if (pHVar4 != (HMODULE)0x0) {
            DAT_c06bc104 = GetProcAddressW(pHVar4,L"Autoras_Dial");
          }
          goto LAB_c06b303c;
        }
      }
    }
  }
  if (DAT_c06bc5f4 != 0) {
    (*(code *)*DAT_c06bc5dc)(DAT_c06bc5f4);
  }
  if (DAT_c06bc5fc != 0) {
    (*(code *)*DAT_c06bc5dc)(DAT_c06bc5fc);
  }
  if (DAT_c06bc5d8 != 0) {
    (*(code *)*DAT_c06bc5dc)();
  }
  if (DAT_c06bc54c != (HLOCAL)0x0) {
    FUN_c06b3b04(DAT_c06bc54c);
  }
LAB_c06b303c:
  if (hObject != (HANDLE)0x0) {
    CloseHandle(hObject);
  }
  FUN_c06bac58(local_30);
  return bVar1;
}



/* c06b3194 FUN_c06b3194 */

/* Boundary evidence: original MIPS .pdata c06b3194..c06b3203. Semantic name remains unreviewed. */

undefined4 FUN_c06b3194(int param_1,int param_2)

{
  code *pcVar1;
  
  if (param_2 == 0) {
    if (DAT_c06bc5f4 == 0) {
      return 1;
    }
    pcVar1 = (code *)*DAT_c06bc5dc;
    param_1 = DAT_c06bc5f4;
  }
  else {
    if (param_2 != 1) {
      return 1;
    }
    FUN_c06b2c28();
    pcVar1 = DisableThreadLibraryCalls_exref;
  }
  (*pcVar1)(param_1);
  return 1;
}



/* c06b3204 FUN_c06b3204 */

/* Boundary evidence: original MIPS .pdata c06b3204..c06b3277. Semantic name remains unreviewed. */

undefined4 FUN_c06b3204(int param_1,uint param_2)

{
  undefined4 uVar1;
  
  if (7 < param_2) {
    if (param_2 < 0xc) {
      uVar1 = FUN_c06b8398(param_1);
      return uVar1;
    }
    if ((param_2 != 0x12) && ((param_2 == 0x20 || (param_2 == 0x22)))) {
      uVar1 = FUN_c06b7a74(param_1,param_2);
      return uVar1;
    }
  }
  return 2;
}



/* c06b3278 Netbios */

/* Boundary evidence: original MIPS .pdata c06b3278..c06b37bf. Semantic name remains unreviewed. */

UCHAR Netbios(PNCB pncb)

{
  undefined4 *puVar1;
  HLOCAL pvVar2;
  uint uVar3;
  undefined2 uVar4;
  uint in_a1;
  DWORD *in_a2;
  size_t in_a3;
  uint uVar5;
  int iVar6;
  DWORD dwErrCode;
  UCHAR UVar7;
  int *piVar8;
  uint *in_stack_00000010;
  size_t in_stack_00000014;
  undefined4 *in_stack_00000018;
  uint *local_28 [2];
  
                    /* 0x3278  12  Netbios */
  local_28[0] = (uint *)0x0;
  UVar7 = '\x01';
  if (0x32 < in_a1) {
    if (in_a1 == 0x50) {
      *(undefined2 *)(in_a2 + 2) = 0x50;
      dwErrCode = FUN_c06b843c((int)in_a2,in_a3,(int *)in_stack_00000010);
    }
    else {
      if (in_a1 != 0x51) goto switchD_c06b32e8_caseD_2;
      uVar3 = FUN_c06b23b4(*in_stack_00000010);
      *in_stack_00000010 = uVar3;
      if (uVar3 == 0xffffffff) {
        dwErrCode = 2;
      }
      else {
        dwErrCode = 0;
      }
    }
    goto LAB_c06b375c;
  }
  if (in_a1 == 0x32) {
    *(undefined2 *)(in_a2 + 2) = 0x32;
    dwErrCode = FUN_c06b3204((int)in_a2,in_a3);
    goto LAB_c06b375c;
  }
  uVar4 = (undefined2)in_a1;
  switch(in_a1) {
  case 1:
    DAT_c06bc5dc = in_stack_00000010;
    DAT_c06bc600 = in_a2;
    *in_stack_00000018 = 0x18;
    FUN_c06b2d90();
    return '\x01';
  default:
switchD_c06b32e8_caseD_2:
    dwErrCode = 0x15;
    break;
  case 3:
    dwErrCode = FUN_c06b3924((int)in_a2,(short)pncb,in_a3,in_stack_00000014);
    if (dwErrCode == 0) {
      return '\x01';
    }
    goto LAB_c06b3788;
  case 4:
    puVar1 = LocalAlloc(0x40,0xc);
    if (puVar1 != (undefined4 *)0x0) {
      puVar1[1] = in_a2;
      if (in_a2 == (DWORD *)0x0) {
        return '\x01';
      }
      EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c06bc620);
      EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c06bc6a0);
      EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c06bc640);
      if (DAT_c06bc6bc != 0) {
        puVar1[2] = DAT_c06bc6b8;
      }
      *puVar1 = DAT_c06bc634;
      DAT_c06bc634 = puVar1;
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c06bc640);
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c06bc6a0);
      for (piVar8 = (int *)DAT_c06bc684; piVar8 != (int *)0x0; piVar8 = (int *)*piVar8) {
        EnterCriticalSection((LPCRITICAL_SECTION)(piVar8 + 7));
        if ((*(byte *)((int)piVar8 + 0x39) & 1) == 0) {
          pvVar2 = LocalAlloc(0x40,0x10);
          *(DWORD **)((int)pvVar2 + 8) = in_a2;
          *(undefined1 *)((int)pvVar2 + 0xc) = *(undefined1 *)(piVar8 + 0xe);
          *(uint *)((int)pvVar2 + 4) = *(byte *)((int)piVar8 + 0x39) & 2 | 1;
          EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c06bc6a0);
          FUN_c06b1eb8((int)pvVar2);
          LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c06bc6a0);
        }
        LeaveCriticalSection((LPCRITICAL_SECTION)(piVar8 + 7));
      }
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c06bc620);
      EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c06bc6a0);
      FUN_c06b2440();
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c06bc6a0);
      return '\x01';
    }
    goto LAB_c06b3790;
  case 5:
    dwErrCode = FUN_c06b2130(in_stack_00000010,in_a3,in_a2,in_a3);
    break;
  case 8:
  case 9:
  case 0xb:
    *(undefined2 *)(in_a2 + 2) = uVar4;
    dwErrCode = FUN_c06b5b68((int)in_a2);
    break;
  case 10:
    *(undefined2 *)(in_a2 + 2) = uVar4;
    dwErrCode = FUN_c06b5dac((int)in_a2);
    break;
  case 0x10:
    if (in_a3 < 8) {
      dwErrCode = 0x57;
    }
    else {
      *(undefined2 *)(in_a2 + 2) = uVar4;
      dwErrCode = FUN_c06b617c((int)in_a2,(int *)local_28,(uint *)0x0);
      if (dwErrCode == 0) {
        uVar3 = *local_28[0];
        if ((uVar3 & 0x80000000) != 0) {
          uVar3 = uVar3 & 0x7fffffff;
        }
        if ((int)(in_a3 >> 2) < (int)uVar3) {
          uVar3 = in_a3 >> 2;
        }
        *in_stack_00000010 = uVar3;
        if (0 < (int)uVar3) {
          iVar6 = (int)local_28[0] - (int)in_stack_00000010;
          uVar5 = uVar3;
          do {
            in_stack_00000010 = in_stack_00000010 + 1;
            uVar5 = uVar5 - 1;
            *in_stack_00000010 = *(uint *)(iVar6 + (int)in_stack_00000010);
          } while (uVar5 != 0);
        }
        if (uVar3 == 0) {
          dwErrCode = 2;
        }
      }
      if (local_28[0] != (uint *)0x0) {
        LocalFree(local_28[0]);
      }
    }
    break;
  case 0x11:
    *(undefined2 *)(in_a2 + 2) = uVar4;
    dwErrCode = FUN_c06b8600((int)in_a2);
    break;
  case 0x12:
    *(undefined2 *)(in_a2 + 2) = uVar4;
    dwErrCode = FUN_c06b8cb8((int)in_a2);
    break;
  case 0x13:
    *(undefined2 *)(in_a2 + 2) = uVar4;
    dwErrCode = FUN_c06b9e7c((int)in_a2,(int)in_stack_00000010,in_a3);
    break;
  case 0x14:
    *(undefined2 *)(in_a2 + 2) = uVar4;
    dwErrCode = FUN_c06b9fa4((int)in_a2,(int)in_stack_00000010,in_a3);
    break;
  case 0x15:
    *(undefined2 *)(in_a2 + 2) = uVar4;
    dwErrCode = FUN_c06b97c0((int)in_a2,in_stack_00000010,in_a3,in_stack_00000018,in_stack_00000014)
    ;
    break;
  case 0x19:
    *(undefined2 *)(in_a2 + 2) = uVar4;
    dwErrCode = FUN_c06b8c24((int)in_a2);
    break;
  case 0x1a:
    *(undefined2 *)(in_a2 + 2) = uVar4;
    dwErrCode = FUN_c06b4c90((int)in_a2);
    break;
  case 0x20:
    *(undefined2 *)(in_a2 + 2) = uVar4;
    dwErrCode = FUN_c06b77d8((int)in_a2,in_stack_00000010,in_a3);
    break;
  case 0x21:
    *(undefined2 *)(in_a2 + 2) = uVar4;
    dwErrCode = FUN_c06b916c((int)in_a2,in_stack_00000010,in_a3);
    break;
  case 0x22:
    *(undefined2 *)(in_a2 + 2) = uVar4;
    dwErrCode = FUN_c06b792c((int)in_a2,(int)in_stack_00000010,in_a3);
    break;
  case 0x23:
    *(undefined2 *)(in_a2 + 2) = uVar4;
    dwErrCode = FUN_c06b9488((int)in_a2,in_stack_00000010,in_a3);
  }
LAB_c06b375c:
  if (in_a2 != (DWORD *)0x0) {
    *in_a2 = dwErrCode;
  }
  if ((dwErrCode != 0) && (dwErrCode != 0xe)) {
LAB_c06b3788:
    SetLastError(dwErrCode);
LAB_c06b3790:
    UVar7 = '\0';
  }
  return UVar7;
}



/* c06b37c0 FUN_c06b37c0 */

/* Boundary evidence: original MIPS .pdata c06b37c0..c06b380f. Semantic name remains unreviewed. */

short FUN_c06b37c0(void)

{
  short sVar1;
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c06bc5e0);
  sVar1 = DAT_c06bc5d4;
  DAT_c06bc5d4 = DAT_c06bc5d4 + 1;
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c06bc5e0);
  return sVar1;
}



/* c06b3810 FUN_c06b3810 */

/* Boundary evidence: original MIPS .pdata c06b3810..c06b3923. Semantic name remains unreviewed. */

void FUN_c06b3810(undefined4 param_1,int param_2,uint *param_3,uint *param_4)

{
  uint uVar1;
  int *piVar2;
  
  if (param_3 != (uint *)0x0) {
    *param_3 = 0;
  }
  if (param_4 != (uint *)0x0) {
    *param_4 = 0;
  }
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c06bc5c0);
  piVar2 = (int *)DAT_c06bc100;
  do {
    if (piVar2 == (int *)0x0) {
LAB_c06b3900:
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c06bc5c0);
      return;
    }
    if (param_2 == piVar2[1]) {
      if ((param_3 == (uint *)0x0) || (*param_3 != 0)) {
        if (param_4 != (uint *)0x0) {
          uVar1 = piVar2[2];
          *param_4 = (uVar1 & 0xff0000 | uVar1 >> 0x10) >> 8 | (uVar1 << 0x10 | uVar1 & 0xff00) << 8
          ;
        }
        goto LAB_c06b3900;
      }
      uVar1 = piVar2[2];
      *param_3 = (uVar1 & 0xff0000 | uVar1 >> 0x10) >> 8 | (uVar1 << 0x10 | uVar1 & 0xff00) << 8;
    }
    piVar2 = (int *)*piVar2;
  } while( true );
}



/* c06b3924 FUN_c06b3924 */

/* Boundary evidence: original MIPS .pdata c06b3924..c06b3ae3. Semantic name remains unreviewed. */

int FUN_c06b3924(int param_1,undefined2 param_2,int param_3,int param_4)

{
  bool bVar1;
  undefined4 *hMem;
  int *piVar2;
  int iVar3;
  undefined4 *puVar4;
  int *piVar5;
  
  iVar3 = 2;
  if (param_4 == 0) {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c06bc5c0);
    piVar5 = &DAT_c06bc100;
    for (piVar2 = (int *)DAT_c06bc100; piVar2 != (int *)0x0; piVar2 = (int *)*piVar2) {
      if ((param_3 == piVar2[2]) && (param_1 == piVar2[1])) {
        *(undefined2 *)(piVar2 + 3) = param_2;
        iVar3 = 0;
        break;
      }
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c06bc5c0);
    bVar1 = iVar3 != 0;
    iVar3 = 0;
    if (bVar1) {
      puVar4 = LocalAlloc(0x40,0x10);
      if (puVar4 == (undefined4 *)0x0) {
        iVar3 = 3;
      }
      else {
        puVar4[2] = param_3;
        puVar4[1] = param_1;
        *(undefined2 *)(puVar4 + 3) = param_2;
        *puVar4 = 0;
        EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c06bc5c0);
        iVar3 = DAT_c06bc100;
        while (iVar3 != 0) {
          piVar5 = (int *)*piVar5;
          iVar3 = *piVar5;
        }
        *piVar5 = (int)puVar4;
        LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c06bc5c0);
        iVar3 = 0;
      }
    }
  }
  else {
    puVar4 = &DAT_c06bc100;
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c06bc5c0);
    while (hMem = (undefined4 *)*puVar4, hMem != (undefined4 *)0x0) {
      if (param_3 == 0) {
        if (param_1 != hMem[1]) goto LAB_c06b39b8;
        *puVar4 = *hMem;
        LocalFree(hMem);
      }
      else {
        if ((param_3 == hMem[2]) && (param_1 == hMem[1])) {
          *puVar4 = *hMem;
          LocalFree(hMem);
          iVar3 = 0;
          break;
        }
LAB_c06b39b8:
        puVar4 = (undefined4 *)*puVar4;
      }
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c06bc5c0);
  }
  return iVar3;
}



/* c06b3ae4 FUN_c06b3ae4 */

/* Boundary evidence: original MIPS .pdata c06b3ae4..c06b3b03. Semantic name remains unreviewed. */

void FUN_c06b3ae4(void)

{
  LocalAlloc(0x40,0x250);
  return;
}



/* c06b3b04 FUN_c06b3b04 */

/* Boundary evidence: original MIPS .pdata c06b3b04..c06b3b1f. Semantic name remains unreviewed. */

void FUN_c06b3b04(HLOCAL param_1)

{
  LocalFree(param_1);
  return;
}



/* c06b3b20 FUN_c06b3b20 */

int FUN_c06b3b20(undefined1 *param_1,int param_2)

{
  byte bVar1;
  int iVar2;
  char *pcVar3;
  int iVar4;
  
  *param_1 = 0x20;
  pcVar3 = param_1 + 1;
  iVar2 = 0;
  do {
    iVar4 = iVar2;
    bVar1 = *(byte *)(iVar4 + param_2);
    *pcVar3 = (bVar1 >> 4) + 0x41;
    pcVar3[1] = (bVar1 & 0xf) + 0x41;
    pcVar3 = pcVar3 + 2;
    iVar2 = iVar4 + 1;
  } while (iVar4 + 1 < 0x10);
  *pcVar3 = '\0';
  return (iVar4 + 2) * 2;
}



/* c06b3b78 FUN_c06b3b78 */

/* WARNING: Removing unreachable block (ram,0xc06b3b8c) */

int FUN_c06b3b78(byte *param_1,int param_2)

{
  byte bVar1;
  char *pcVar2;
  int iVar3;
  byte *pbVar4;
  
  bVar1 = *param_1;
  pbVar4 = param_1 + 1;
  iVar3 = 0;
  if ((int)(uint)bVar1 >> 1 != 0) {
    do {
      pcVar2 = (char *)(iVar3 + param_2);
      iVar3 = iVar3 + 1;
      *pcVar2 = *pbVar4 * '\x10' + pbVar4[1] + -0x51;
      pbVar4 = pbVar4 + 2;
    } while (iVar3 < (int)(uint)bVar1 >> 1);
  }
  *(undefined1 *)(iVar3 + param_2) = 0x2e;
  return iVar3 + 1;
}



/* c06b3bdc FUN_c06b3bdc */

/* Boundary evidence: original MIPS .pdata c06b3bdc..c06b4223. Semantic name remains unreviewed. */

void FUN_c06b3bdc(uint *param_1,int param_2,char *param_3,uint param_4,uint param_5,
                 undefined4 *param_6,int param_7)

{
  undefined1 *puVar1;
  byte bVar2;
  int iVar3;
  byte *pbVar4;
  ushort uVar5;
  undefined4 uVar6;
  ushort uVar7;
  uint uVar8;
  uint *_Dst;
  int *piVar9;
  uint *puVar10;
  byte bVar11;
  size_t sVar12;
  byte *pbVar13;
  byte *pbVar14;
  byte bStackX_d;
  byte bStack_6f;
  undefined4 local_68;
  undefined1 local_64 [4];
  ushort local_60;
  undefined1 local_5e;
  undefined1 local_5d;
  undefined1 auStack_5c [4];
  undefined4 local_58;
  undefined2 local_54;
  
  bStackX_d = (byte)(param_4 >> 8);
  uVar7 = 0;
  if ((param_4 & 1) != 0) {
    param_4 = param_4 & 0xfffe;
    bStackX_d = (byte)(param_4 >> 8);
    uVar7 = 0x1000;
  }
  _Dst = param_1 + 7;
  uVar5 = 0;
  bVar11 = (byte)param_4;
  if (param_2 < 0x401) {
    if (param_2 == 0x400) {
      *(undefined2 *)((int)param_1 + 0x12) = 0x85;
      *(undefined2 *)((int)param_1 + 0x16) = 0x100;
      if (param_3 == (char *)0x0) {
        iVar3 = (byte)*_Dst + 2;
      }
      else {
        iVar3 = FUN_c06b3b20((undefined1 *)_Dst,(int)param_3);
      }
      local_68 = 0x1002000;
      local_64 = (undefined1  [4])0x0;
      uVar8 = param_7 * 6 & 0xffff;
      local_60 = (ushort)(uVar8 << 8) | (ushort)(uVar8 >> 8);
      memcpy((byte *)(iVar3 + (int)_Dst),&local_68,10);
      _Dst = (uint *)((byte *)(iVar3 + (int)_Dst) + 10);
      if (0 < param_7) {
        do {
          *(byte *)_Dst = bVar11;
          *(byte *)((int)_Dst + 1) = bStackX_d;
          uVar6 = *param_6;
          pbVar4 = (byte *)((int)_Dst + 2);
          param_7 = param_7 + -1;
          _Dst = (uint *)((int)_Dst + 6);
          param_6 = param_6 + 1;
          *(undefined4 *)pbVar4 = uVar6;
        } while (param_7 != 0);
      }
      goto LAB_c06b41e8;
    }
    if (param_2 == 1) goto LAB_c06b3eec;
    if (param_2 == 2) {
LAB_c06b3dd0:
      if (uVar5 == 0) {
        uVar5 = uVar7 | 0x28;
        goto LAB_c06b3ee0;
      }
      goto LAB_c06b3ef8;
    }
    if (param_2 == 4) {
      uVar5 = uVar7 | 0x48;
      goto LAB_c06b3dd0;
    }
    if (param_2 == 0x10) {
      *(undefined2 *)((int)param_1 + 0x12) = 0x86ad;
      *(undefined2 *)((int)param_1 + 0x16) = 0x100;
      sVar12 = (int)*param_3 + 2;
      if ((int)sVar12 < 0x31) {
        memcpy(_Dst,param_3,sVar12);
        puVar1 = local_64 + 3;
        uVar8 = (uint)puVar1 & 3;
        *(uint *)(puVar1 + -uVar8) =
             *(uint *)(puVar1 + -uVar8) & -1 << (uVar8 + 1) * 8 | 0U >> (3 - uVar8) * 8;
        puVar1 = auStack_5c + 3;
        uVar8 = (uint)puVar1 & 3;
        *(uint *)(puVar1 + -uVar8) =
             *(uint *)(puVar1 + -uVar8) & -1 << (uVar8 + 1) * 8 | param_5 >> (3 - uVar8) * 8;
        local_68 = 0x1002000;
        local_64 = (undefined1  [4])0x0;
        local_60 = 0x600;
        local_5e = 0x40;
        local_5d = 0;
        auStack_5c = (undefined1  [4])param_5;
        memcpy((byte *)(sVar12 + (int)_Dst),&local_68,0x10);
        _Dst = (uint *)((byte *)(sVar12 + (int)_Dst) + 0x10);
      }
      goto LAB_c06b41e8;
    }
    if (param_2 != 0x40) {
      if (param_2 == 0x200) {
        *(ushort *)((int)param_1 + 0x12) = uVar7 | 1;
        *(undefined2 *)(param_1 + 5) = 0x100;
        iVar3 = FUN_c06b3b20((undefined1 *)_Dst,(int)param_3);
        pbVar4 = (byte *)(iVar3 + (int)_Dst);
        pbVar4[0] = 0;
        pbVar4[1] = 0x20;
        pbVar4[2] = 0;
        pbVar4[3] = 1;
        _Dst = (uint *)(pbVar4 + 4);
      }
      goto LAB_c06b41e8;
    }
    *(ushort *)((int)param_1 + 0x12) = uVar7 | 0x30;
    *(undefined2 *)((int)param_1 + 0x1a) = 0x100;
    *(undefined2 *)(param_1 + 5) = 0x100;
    iVar3 = FUN_c06b3b20((undefined1 *)_Dst,(int)param_3);
    pbVar4 = (byte *)(iVar3 + (int)_Dst);
    pbVar4[0] = 0;
    pbVar4[1] = 0x20;
    pbVar4[2] = 0;
    pbVar4[3] = 1;
    local_64 = (undefined1  [4])0x0;
  }
  else {
    if (param_2 == 0x800) {
      *(undefined2 *)((int)param_1 + 0x12) = 0x385;
      if (param_3 == (char *)0x0) {
        iVar3 = (byte)*_Dst + 2;
      }
      else {
        iVar3 = FUN_c06b3b20((undefined1 *)_Dst,(int)param_3);
      }
      local_68 = 0x1000a00;
      local_64 = (undefined1  [4])0x0;
      local_60 = 0;
      memcpy((byte *)(iVar3 + (int)_Dst),&local_68,10);
      _Dst = (uint *)((byte *)(iVar3 + (int)_Dst) + 10);
      goto LAB_c06b41e8;
    }
    if (param_2 == 0x2000) {
      *(undefined2 *)((int)param_1 + 0x12) = 0xbc;
      *(undefined2 *)((int)param_1 + 0x16) = 0x100;
      goto LAB_c06b41e8;
    }
    if (param_2 == 0x4000) {
      *(ushort *)((int)param_1 + 0x12) = uVar7;
      *(undefined2 *)(param_1 + 5) = 0x100;
      goto LAB_c06b41e8;
    }
    if (param_2 == 0x8000) {
      *(undefined2 *)((int)param_1 + 0x12) = 0x84;
      *(undefined2 *)((int)param_1 + 0x16) = 0x100;
      bVar2 = (byte)*_Dst;
      local_68 = 0x1002100;
      local_64 = (undefined1  [4])0x0;
      local_60 = 0;
      memcpy((byte *)((int)_Dst + bVar2 + 2),&local_68,10);
      pbVar13 = (byte *)((int)_Dst + bVar2 + 0xc);
      *pbVar13 = 0;
      pbVar4 = (byte *)((int)_Dst + bVar2 + 0xd);
      memset(&local_58,0,0x2e);
      if (param_4 == 0) {
        pbVar14 = pbVar4 + (-0x10 - (int)param_1);
        piVar9 = *(int **)(param_3 + 0x10);
        if (piVar9 != (int *)0x0) {
          iVar3 = 0x240 - (int)pbVar14;
          do {
            if ((iVar3 == 0) || (iVar3 < 0x12)) break;
            EnterCriticalSection((LPCRITICAL_SECTION)(piVar9 + 0x17));
            if ((piVar9[0x11] & 0x200000U) == 0) {
              memcpy(pbVar4,piVar9 + 1,0x10);
              pbVar4[0x10] = (byte)piVar9[0x11];
              pbVar4[0x11] = *(byte *)((int)piVar9 + 0x45);
              pbVar4 = pbVar4 + 0x12;
              pbVar14 = pbVar14 + 0x12;
              *pbVar13 = *pbVar13 + 1;
              iVar3 = iVar3 + -0x12;
            }
            LeaveCriticalSection((LPCRITICAL_SECTION)(piVar9 + 0x17));
            piVar9 = (int *)*piVar9;
          } while (piVar9 != (int *)0x0);
        }
        sVar12 = 0x240 - (int)pbVar14;
        local_58 = *(undefined4 *)(param_3 + 0x3a);
        local_54 = *(undefined2 *)(param_3 + 0x3e);
        if ((int)sVar12 < 0x2e) {
          memcpy(pbVar4,&local_58,sVar12);
          *(ushort *)((int)param_1 + 0x12) = *(ushort *)((int)param_1 + 0x12) | 2;
          puVar10 = (uint *)(pbVar4 + sVar12);
        }
        else {
          memcpy(pbVar4,&local_58,0x2e);
          puVar10 = (uint *)(pbVar4 + 0x2e);
        }
        bStack_6f = (byte)((uint)((int)puVar10 - (int)pbVar13) >> 8);
        *(byte *)((int)_Dst + bVar2 + 10) = bStack_6f;
        *(byte *)((int)_Dst + bVar2 + 0xb) = (byte)((int)puVar10 - (int)pbVar13);
        _Dst = puVar10;
      }
      else {
        *pbVar13 = 1;
        *(byte *)((int)_Dst + bVar2 + 0xb) = 0x41;
        memcpy(pbVar4,param_3,0x10);
        *(byte *)((int)_Dst + bVar2 + 0x1d) = bVar11;
        *(byte *)((int)_Dst + bVar2 + 0x1e) = bStackX_d;
        local_58 = *(undefined4 *)(param_5 + 0x3a);
        local_54 = *(undefined2 *)(param_5 + 0x3e);
        memcpy((byte *)((int)_Dst + bVar2 + 0x1f),&local_58,0x2e);
        _Dst = (uint *)((int)_Dst + bVar2 + 0x4d);
      }
      goto LAB_c06b41e8;
    }
    if (param_2 != 0x10000) goto LAB_c06b41e8;
LAB_c06b3ee0:
    if (uVar5 == 0) {
      uVar5 = uVar7 | 0x79;
LAB_c06b3eec:
      if (uVar5 == 0) {
        uVar5 = uVar7 | 0x29;
      }
    }
LAB_c06b3ef8:
    *(ushort *)((int)param_1 + 0x12) = uVar5;
    *(undefined2 *)((int)param_1 + 0x1a) = 0x100;
    *(undefined2 *)(param_1 + 5) = 0x100;
    iVar3 = FUN_c06b3b20((undefined1 *)_Dst,(int)param_3);
    pbVar4 = (byte *)(iVar3 + (int)_Dst);
    pbVar4[0] = 0;
    pbVar4[1] = 0x20;
    pbVar4[2] = 0;
    pbVar4[3] = 1;
    local_64 = (undefined1  [4])0xe0930400;
  }
  local_60 = 0x600;
  local_68 = 0x1002000;
  pbVar4[4] = 0xc0;
  pbVar4[5] = 0xc;
  memcpy(pbVar4 + 6,&local_68,10);
  pbVar4[0x10] = bVar11;
  pbVar4[0x11] = bStackX_d;
  *(uint *)(pbVar4 + 0x12) = param_5;
  _Dst = (uint *)(pbVar4 + 0x16);
LAB_c06b41e8:
  *param_1 = param_5;
  param_1[3] = (int)_Dst - (int)(param_1 + 4);
  return;
}



/* c06b4224 FUN_c06b4224 */

/* Boundary evidence: original MIPS .pdata c06b4224..c06b42b7. Semantic name remains unreviewed. */

uint * FUN_c06b4224(int param_1,char *param_2,uint param_3,uint param_4)

{
  short sVar1;
  uint *puVar2;
  
  puVar2 = LocalAlloc(0x40,0x250);
  if (puVar2 != (uint *)0x0) {
    sVar1 = FUN_c06b37c0();
    *(short *)(puVar2 + 4) = sVar1;
    FUN_c06b3bdc(puVar2,param_1,param_2,param_3,param_4,(undefined4 *)0x0,0);
  }
  return puVar2;
}



/* c06b42b8 FUN_c06b42b8 */

/* Boundary evidence: original MIPS .pdata c06b42b8..c06b435b. Semantic name remains unreviewed. */

undefined4 FUN_c06b42b8(int param_1)

{
  undefined4 uVar1;
  undefined4 local_30;
  int local_2c;
  undefined1 auStack_28 [8];
  undefined2 local_20;
  undefined2 local_1e;
  undefined4 local_1c;
  uint local_10;
  
  local_10 = DAT_c06bc0f4;
  local_20 = 2;
  local_1c = *(undefined4 *)(param_1 + 4);
  local_1e = *(undefined2 *)(param_1 + 10);
  local_30 = *(undefined4 *)(param_1 + 0xc);
  local_2c = param_1 + 0x10;
  uVar1 = (**(code **)(DAT_c06bc5dc + 0x20))
                    (DAT_c06bc5f4,&local_30,1,auStack_28,0,&local_20,0x10,0,0,0);
  FUN_c06bac58(local_10);
  return uVar1;
}



/* c06b435c FUN_c06b435c */

/* Boundary evidence: original MIPS .pdata c06b435c..c06b43d3. Semantic name remains unreviewed. */

void FUN_c06b435c(int param_1,DWORD param_2)

{
  *(uint *)(param_1 + 0x10) = *(uint *)(param_1 + 0x10) | 8;
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x38));
  WaitForSingleObject(*(HANDLE *)(param_1 + 0x30),param_2);
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x38));
  *(uint *)(param_1 + 0x10) = *(uint *)(param_1 + 0x10) & 0xfffffff7;
  return;
}



/* c06b43d4 FUN_c06b43d4 */

/* Boundary evidence: original MIPS .pdata c06b43d4..c06b4617. Semantic name remains unreviewed. */

int FUN_c06b43d4(int param_1,int param_2,uint param_3,uint param_4)

{
  int iVar1;
  DWORD DVar2;
  uint uVar3;
  LPCRITICAL_SECTION lpCriticalSection;
  DWORD DVar4;
  int iVar5;
  uint local_40;
  int local_3c;
  uint local_38;
  uint local_34;
  uint local_30;
  
  uVar3 = 0;
  local_3c = 0;
  local_40 = 0;
  local_30 = 0;
  local_38 = 0;
  DVar4 = 0;
  iVar5 = 1;
  local_34 = param_3;
  if ((param_4 & 1) == 0) {
    if ((param_4 & 2) != 0) {
      DVar4 = 5000;
      iVar5 = 4;
      FUN_c06b3810((uint)*(ushort *)(param_2 + 10),*(int *)(param_2 + 0xc),&local_38,&local_40);
      local_30 = local_38;
      uVar3 = local_40;
      if ((local_40 == 0) && (uVar3 = local_38, local_38 == 0)) {
        return 2;
      }
      *(undefined2 *)(param_1 + 10) = 0x8900;
      goto LAB_c06b4454;
    }
  }
  else {
    DVar4 = 0xfa;
    iVar5 = 3;
  }
  *(undefined2 *)(param_1 + 10) = 0x8900;
  local_3c = 0;
LAB_c06b4454:
  if ((param_4 & 8) != 0) {
    DVar4 = 0;
    iVar5 = 1;
  }
  *(uint *)(param_2 + 0x14) = local_34;
  lpCriticalSection = (LPCRITICAL_SECTION)(param_2 + 0x38);
  local_38 = local_30;
  do {
    if ((param_4 & 2) != 0) {
      if ((local_3c / 3 & 1U) == 0) {
        *(uint *)(param_1 + 4) = local_30;
      }
      else {
        *(uint *)(param_1 + 4) = uVar3;
      }
    }
    local_3c = local_3c + 1;
    LeaveCriticalSection(lpCriticalSection);
    iVar1 = FUN_c06b42b8(param_1);
    if (iVar1 != 0) {
      EnterCriticalSection(lpCriticalSection);
      return iVar1;
    }
    if (((param_4 & 2) != 0) && ((param_4 & 8) == 0)) {
      Sleep(1000);
    }
    EnterCriticalSection(lpCriticalSection);
    if (((local_34 & 0x2000) == 0) || ((*(uint *)(param_2 + 0x18) & 0x2000) == 0)) {
      if ((DVar4 != 0) && (DVar2 = DVar4, (*(uint *)(param_2 + 0x10) & 1) == 0)) goto LAB_c06b459c;
    }
    else {
      DVar2 = *(int *)(param_2 + 0x1c) * 1000;
LAB_c06b459c:
      FUN_c06b435c(param_2,DVar2);
    }
    if ((((*(uint *)(param_2 + 0x10) & 2) != 0) || ((*(uint *)(param_2 + 0x10) & 1) != 0)) ||
       (iVar5 <= local_3c)) {
      *(undefined4 *)(param_2 + 0x14) = 0;
      return 0;
    }
  } while( true );
}



/* c06b4618 FUN_c06b4618 */

/* Boundary evidence: original MIPS .pdata c06b4618..c06b467b. Semantic name remains unreviewed. */

short FUN_c06b4618(void)

{
  bool bVar1;
  short sVar2;
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c06bc5e0);
  bVar1 = DAT_c06bc5b4 == 0;
  sVar2 = DAT_c06bc5b4;
  DAT_c06bc5b4 = DAT_c06bc5b4 + 1;
  if (bVar1) {
    DAT_c06bc5b4 = 2;
    sVar2 = 1;
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c06bc5e0);
  return sVar2;
}



/* c06b467c FUN_c06b467c */

/* Boundary evidence: original MIPS .pdata c06b467c..c06b475b. Semantic name remains unreviewed. */

HLOCAL FUN_c06b467c(void)

{
  short sVar1;
  HLOCAL hMem;
  HANDLE pvVar2;
  undefined2 extraout_var;
  HANDLE hObject;
  
  hMem = LocalAlloc(0x40,0x58);
  if (hMem != (HLOCAL)0x0) {
    pvVar2 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
    *(HANDLE *)((int)hMem + 0xc) = pvVar2;
    pvVar2 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,1,(LPCWSTR)0x0);
    hObject = *(HANDLE *)((int)hMem + 0xc);
    *(HANDLE *)((int)hMem + 0x10) = pvVar2;
    if ((hObject == (HANDLE)0x0) || (pvVar2 == (HANDLE)0x0)) {
      if (hObject != (HANDLE)0x0) {
        CloseHandle(hObject);
      }
      if (*(HANDLE *)((int)hMem + 0x10) != (HANDLE)0x0) {
        CloseHandle(*(HANDLE *)((int)hMem + 0x10));
      }
      LocalFree(hMem);
      hMem = (HLOCAL)0x0;
    }
    if (hMem != (HLOCAL)0x0) {
      InitializeCriticalSection((LPCRITICAL_SECTION)((int)hMem + 0x40));
      sVar1 = FUN_c06b4618();
      *(uint *)((int)hMem + 4) = CONCAT22(extraout_var,sVar1);
    }
  }
  return hMem;
}



/* c06b475c FUN_c06b475c */

/* Boundary evidence: original MIPS .pdata c06b475c..c06b47d3. Semantic name remains unreviewed. */

void FUN_c06b475c(HLOCAL param_1)

{
  int iVar1;
  
  for (iVar1 = *(int *)((int)param_1 + 0x14); iVar1 != 0; iVar1 = iVar1 + -1) {
    EventModify(*(undefined4 *)((int)param_1 + 0x10),3);
  }
  CloseHandle(*(HANDLE *)((int)param_1 + 0xc));
  CloseHandle(*(HANDLE *)((int)param_1 + 0x10));
  DeleteCriticalSection((LPCRITICAL_SECTION)((int)param_1 + 0x40));
  LocalFree(param_1);
  return;
}



/* c06b47d4 FUN_c06b47d4 */

/* Boundary evidence: original MIPS .pdata c06b47d4..c06b491f. Semantic name remains unreviewed. */

int FUN_c06b47d4(void *param_1,undefined4 *param_2,int param_3,int *param_4,char param_5)

{
  int iVar1;
  uint uVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  
  iVar4 = 0;
  iVar5 = 0;
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c06bc5a0);
  piVar3 = (int *)DAT_c06bc580;
  while ((piVar3 != (int *)0x0 && (iVar4 < param_3))) {
    EnterCriticalSection((LPCRITICAL_SECTION)(piVar3 + 0x10));
    if ((param_5 == *(char *)(piVar3 + 0x15)) &&
       (iVar1 = memcmp(param_1,piVar3 + 8,0x10), iVar1 == 0)) {
      uVar2 = piVar3[6];
      iVar4 = iVar4 + 1;
      if ((uVar2 & 1) == 0) {
        piVar3[6] = uVar2 | 2;
        *param_2 = 0;
        param_2[1] = piVar3[2];
        iVar5 = iVar5 + 1;
        param_2[3] = piVar3[1];
        param_2[2] = 0x29;
        param_2 = param_2 + 6;
      }
      else {
        piVar3[6] = uVar2 | 4;
      }
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)(piVar3 + 0x10));
    piVar3 = (int *)*piVar3;
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c06bc5a0);
  *param_4 = iVar5;
  return iVar4;
}



/* c06b4920 FUN_c06b4920 */

/* Boundary evidence: original MIPS .pdata c06b4920..c06b49f7. Semantic name remains unreviewed. */

int FUN_c06b4920(void *param_1,uint param_2)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  
  iVar3 = 0;
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c06bc5a0);
  for (piVar2 = (int *)DAT_c06bc580; piVar2 != (int *)0x0; piVar2 = (int *)*piVar2) {
    EnterCriticalSection((LPCRITICAL_SECTION)(piVar2 + 0x10));
    if ((param_2 == *(byte *)(piVar2 + 0x15)) &&
       (iVar1 = memcmp(param_1,piVar2 + 8,0x10), iVar1 == 0)) {
      iVar3 = iVar3 + 1;
      piVar2[6] = piVar2[6] & 0xfffffff9;
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)(piVar2 + 0x10));
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c06bc5a0);
  return iVar3;
}



/* c06b49f8 FUN_c06b49f8 */

/* Boundary evidence: original MIPS .pdata c06b49f8..c06b4aef. Semantic name remains unreviewed. */

void FUN_c06b49f8(void *param_1,uint param_2)

{
  int iVar1;
  int *piVar2;
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c06bc5a0);
  piVar2 = (int *)DAT_c06bc580;
  do {
    if (piVar2 == (int *)0x0) {
LAB_c06b4ac8:
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c06bc5a0);
      return;
    }
    EnterCriticalSection((LPCRITICAL_SECTION)(piVar2 + 0x10));
    if (((param_2 == *(byte *)(piVar2 + 0x15)) &&
        (iVar1 = memcmp(param_1,piVar2 + 8,0x10), iVar1 == 0)) && ((piVar2[6] & 2U) != 0)) {
      if (piVar2[2] != 0) {
        (**(code **)(DAT_c06bc5dc + 0x38))(piVar2[2],0,0);
      }
      LeaveCriticalSection((LPCRITICAL_SECTION)(piVar2 + 0x10));
      goto LAB_c06b4ac8;
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)(piVar2 + 0x10));
    piVar2 = (int *)*piVar2;
  } while( true );
}



/* c06b4af0 FUN_c06b4af0 */

/* Boundary evidence: original MIPS .pdata c06b4af0..c06b4b5f. Semantic name remains unreviewed. */

int * FUN_c06b4af0(int param_1)

{
  int iVar1;
  int *piVar2;
  
  piVar2 = &DAT_c06bc580;
  iVar1 = DAT_c06bc580;
  while( true ) {
    if (iVar1 == 0) {
      return piVar2;
    }
    EnterCriticalSection((LPCRITICAL_SECTION)(iVar1 + 0x40));
    if (param_1 == *(int *)(*piVar2 + 4)) break;
    LeaveCriticalSection((LPCRITICAL_SECTION)(*piVar2 + 0x40));
    piVar2 = (int *)*piVar2;
    iVar1 = *piVar2;
  }
  return piVar2;
}



/* c06b4b60 FUN_c06b4b60 */

/* Boundary evidence: original MIPS .pdata c06b4b60..c06b4bdb. Semantic name remains unreviewed. */

int FUN_c06b4b60(int param_1,uint param_2)

{
  int *piVar1;
  int iVar2;
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c06bc5a0);
  piVar1 = FUN_c06b4af0(param_1);
  iVar2 = *piVar1;
  if ((iVar2 != 0) && (param_2 != *(byte *)(iVar2 + 0x54))) {
    LeaveCriticalSection((LPCRITICAL_SECTION)(iVar2 + 0x40));
    iVar2 = 0;
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c06bc5a0);
  return iVar2;
}



/* c06b4bdc FUN_c06b4bdc */

/* Boundary evidence: original MIPS .pdata c06b4bdc..c06b4c2b. Semantic name remains unreviewed. */

void FUN_c06b4bdc(undefined4 *param_1)

{
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c06bc5a0);
  *param_1 = DAT_c06bc580;
  DAT_c06bc580 = param_1;
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c06bc5a0);
  return;
}



/* c06b4c2c FUN_c06b4c2c */

/* Boundary evidence: original MIPS .pdata c06b4c2c..c06b4c8f. Semantic name remains unreviewed. */

int * FUN_c06b4c2c(int param_1)

{
  int *piVar1;
  int *piVar2;
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c06bc5a0);
  piVar1 = FUN_c06b4af0(param_1);
  piVar2 = (int *)*piVar1;
  if (piVar2 != (int *)0x0) {
    *piVar1 = *piVar2;
    *piVar2 = 0;
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c06bc5a0);
  return piVar2;
}



/* c06b4c90 FUN_c06b4c90 */

/* Boundary evidence: original MIPS .pdata c06b4c90..c06b4e63. Semantic name remains unreviewed. */

undefined4 FUN_c06b4c90(int param_1)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  undefined4 uVar4;
  LPCRITICAL_SECTION lpCriticalSection;
  
  uVar4 = 0;
  piVar1 = (int *)FUN_c06b1b00((uint)*(byte *)(param_1 + 0x30));
  if (piVar1 == (int *)0x0) {
    uVar4 = 0x14;
  }
  else {
    iVar2 = FUN_c06b538c((int)piVar1,(byte *)(param_1 + 0x20),0,1);
    if (iVar2 == 0) {
      FUN_c06b1de4(piVar1);
      uVar4 = 4;
    }
    else {
      FUN_c06b1de4(piVar1);
      if ((*(uint *)(iVar2 + 0x44) & 0x20000) != 0) {
        *(uint *)(iVar2 + 0x44) = *(uint *)(iVar2 + 0x44) | 0x40000;
        EventModify(*(undefined4 *)(iVar2 + 0x50),3);
      }
      LeaveCriticalSection((LPCRITICAL_SECTION)(iVar2 + 0x5c));
      EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c06bc5a0);
      piVar1 = &DAT_c06bc580;
      iVar2 = DAT_c06bc580;
      while (iVar2 != 0) {
        piVar3 = (int *)*piVar1;
        lpCriticalSection = (LPCRITICAL_SECTION)(piVar3 + 0x10);
        EnterCriticalSection(lpCriticalSection);
        if (((char)piVar3[0x15] == *(char *)(param_1 + 0x30)) &&
           (iVar2 = memcmp((byte *)(param_1 + 0x20),piVar3 + 8,0x10), iVar2 == 0)) {
          *piVar1 = *piVar3;
          *piVar3 = 0;
          if (piVar3[2] != 0) {
            uVar4 = (*(code *)*DAT_c06bc5dc)();
          }
          EventModify(piVar3[4],3);
          EventModify(piVar3[3],3);
          LeaveCriticalSection(lpCriticalSection);
          FUN_c06b475c(piVar3);
          if (*piVar1 == 0) break;
        }
        else {
          LeaveCriticalSection(lpCriticalSection);
        }
        piVar1 = (int *)*piVar1;
        iVar2 = *piVar1;
      }
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c06bc5a0);
    }
  }
  return uVar4;
}



/* c06b4e64 FUN_c06b4e64 */

/* Boundary evidence: original MIPS .pdata c06b4e64..c06b5077. Semantic name remains unreviewed. */

void FUN_c06b4e64(void)

{
  short sVar1;
  uint *puVar2;
  int *hMem;
  int iVar3;
  int *piVar4;
  int *piVar5;
  int iVar6;
  uint local_30 [2];
  
  iVar6 = 0;
  puVar2 = (uint *)FUN_c06b3ae4();
  if (puVar2 != (uint *)0x0) {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c06bc620);
    DAT_c06bc57c = 0;
    piVar5 = DAT_c06bc684;
    if (DAT_c06bc684 != (int *)0x0) {
      do {
        EnterCriticalSection((LPCRITICAL_SECTION)(piVar5 + 7));
        if ((*(byte *)((int)piVar5 + 0x39) & 1) == 0) {
          local_30[0] = 0;
          piVar4 = piVar5 + 5;
          while (hMem = (int *)*piVar4, hMem != (int *)0x0) {
            iVar3 = hMem[0x12];
            hMem[0x12] = iVar3 + -0x3c;
            if (iVar3 + -0x3c < 1) {
              *piVar4 = *hMem;
              LocalFree(hMem);
            }
            else {
              piVar4 = (int *)*piVar4;
            }
          }
          FUN_c06b3810((uint)*(ushort *)(piVar5 + 0xd),piVar5[0xc],local_30,(uint *)0x0);
          if (local_30[0] != 0) {
            for (piVar4 = (int *)piVar5[4]; piVar4 != (int *)0x0; piVar4 = (int *)*piVar4) {
              EnterCriticalSection((LPCRITICAL_SECTION)(piVar4 + 0x17));
              if (((piVar4[0x11] & 0x200000U) == 0) && (iVar3 = piVar4[0x12], iVar3 != 0)) {
                if (iVar3 < 0x3d) {
                  FUN_c06b3bdc(puVar2,4,(char *)(piVar4 + 1),0x60,piVar5[1],(undefined4 *)0x0,0);
                  sVar1 = FUN_c06b37c0();
                  *(short *)(piVar4 + 0x13) = sVar1;
                  *(short *)(puVar2 + 4) = sVar1;
                  *(undefined2 *)((int)puVar2 + 10) = 0x8900;
                  puVar2[1] = local_30[0];
                  FUN_c06b42b8((int)puVar2);
                }
                else {
                  piVar4[0x12] = iVar3 + -0x3c;
                }
              }
              LeaveCriticalSection((LPCRITICAL_SECTION)(piVar4 + 0x17));
            }
          }
        }
        LeaveCriticalSection((LPCRITICAL_SECTION)(piVar5 + 7));
        piVar5 = (int *)*piVar5;
        iVar6 = iVar6 + 1;
      } while (piVar5 != (int *)0x0);
      if (iVar6 != 0) {
        DAT_c06bc57c = 1;
        CTEStartTimer(&DAT_c06bc560,60000,FUN_c06b4e64,0);
      }
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c06bc620);
    FUN_c06b3b04(puVar2);
  }
  return;
}



/* c06b5078 FUN_c06b5078 */

/* Boundary evidence: original MIPS .pdata c06b5078..c06b50ef. Semantic name remains unreviewed. */

HLOCAL FUN_c06b5078(void)

{
  HLOCAL hMem;
  HANDLE pvVar1;
  
  hMem = LocalAlloc(0x40,0x70);
  if (hMem != (HLOCAL)0x0) {
    pvVar1 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,1,0,(LPCWSTR)0x0);
    *(HANDLE *)((int)hMem + 0x50) = pvVar1;
    if (pvVar1 == (HANDLE)0x0) {
      LocalFree(hMem);
      hMem = (HLOCAL)0x0;
    }
    else {
      InitializeCriticalSection((LPCRITICAL_SECTION)((int)hMem + 0x5c));
    }
  }
  return hMem;
}



/* c06b50f0 FUN_c06b50f0 */

/* Boundary evidence: original MIPS .pdata c06b50f0..c06b515f. Semantic name remains unreviewed. */

void FUN_c06b50f0(HLOCAL param_1)

{
  int iVar1;
  
  iVar1 = *(int *)((int)param_1 + 0x54);
  while (iVar1 != 0) {
    EventModify(*(undefined4 *)(*(int *)((int)param_1 + 0x54) + 0xc),3);
    iVar1 = **(int **)((int)param_1 + 0x54);
    *(int *)((int)param_1 + 0x54) = iVar1;
  }
  CloseHandle(*(HANDLE *)((int)param_1 + 0x50));
  DeleteCriticalSection((LPCRITICAL_SECTION)((int)param_1 + 0x5c));
  LocalFree(param_1);
  return;
}



/* c06b5160 FUN_c06b5160 */

/* Boundary evidence: original MIPS .pdata c06b5160..c06b528b. Semantic name remains unreviewed. */

undefined4 FUN_c06b5160(int param_1,byte *param_2,undefined4 param_3,undefined4 param_4,int param_5)

{
  undefined4 *puVar1;
  uint _Size;
  undefined4 uVar2;
  undefined4 *_Dst;
  undefined1 auStack_38 [20];
  uint local_24;
  
  local_24 = DAT_c06bc0f4;
  uVar2 = 0;
  puVar1 = FUN_c06b5078();
  if (puVar1 == (undefined4 *)0x0) {
LAB_c06b5214:
    uVar2 = 3;
  }
  else {
    _Dst = puVar1 + 5;
    memset(_Dst,0,0x30);
    if (param_5 == 1) {
      memcpy(puVar1 + 1,param_2,0x10);
      FUN_c06b3b20((undefined1 *)_Dst,(int)param_2);
    }
    else {
      _Size = ((int)(char)*param_2 & 0xffffU) + 2;
      if (0x30 < _Size) goto LAB_c06b5214;
      memcpy(_Dst,param_2,_Size);
      FUN_c06b3b78(param_2,(int)auStack_38);
      memcpy(puVar1 + 1,auStack_38,0x10);
    }
    puVar1[0x11] = param_3;
    puVar1[0x12] = param_4;
    *puVar1 = *(undefined4 *)(param_1 + 0x10);
    *(undefined4 **)(param_1 + 0x10) = puVar1;
  }
  FUN_c06bac58(local_24);
  return uVar2;
}



/* c06b528c FUN_c06b528c */

/* Boundary evidence: original MIPS .pdata c06b528c..c06b538b. Semantic name remains unreviewed. */

int * FUN_c06b528c(int param_1,byte *param_2,int param_3)

{
  uint uVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  
  piVar3 = (int *)(param_1 + 0x10);
  if (param_3 == 1) {
    for (; *piVar3 != 0; piVar3 = (int *)*piVar3) {
      EnterCriticalSection((LPCRITICAL_SECTION)(*piVar3 + 0x5c));
      iVar4 = *piVar3;
      iVar2 = memcmp((void *)(iVar4 + 4),param_2,0x10);
      if (iVar2 == 0) goto LAB_c06b5360;
      LeaveCriticalSection((LPCRITICAL_SECTION)(iVar4 + 0x5c));
    }
  }
  else {
    uVar1 = (uint)*param_2;
    if (0x2f < uVar1) {
      uVar1 = 0x2f;
    }
    iVar2 = *piVar3;
    if (iVar2 != 0) {
      do {
        EnterCriticalSection((LPCRITICAL_SECTION)(iVar2 + 0x5c));
        iVar4 = *piVar3;
        iVar2 = memcmp((void *)(iVar4 + 0x14),param_2,uVar1 + 1);
        if (iVar2 == 0) {
LAB_c06b5360:
          LeaveCriticalSection((LPCRITICAL_SECTION)(*piVar3 + 0x5c));
          return piVar3;
        }
        LeaveCriticalSection((LPCRITICAL_SECTION)(iVar4 + 0x5c));
        piVar3 = (int *)*piVar3;
        iVar2 = *piVar3;
      } while (iVar2 != 0);
    }
  }
  return piVar3;
}



/* c06b538c FUN_c06b538c */

/* Boundary evidence: original MIPS .pdata c06b538c..c06b53cb. Semantic name remains unreviewed. */

int FUN_c06b538c(int param_1,byte *param_2,undefined4 param_3,int param_4)

{
  int *piVar1;
  
  piVar1 = FUN_c06b528c(param_1,param_2,param_4);
  if (*piVar1 != 0) {
    EnterCriticalSection((LPCRITICAL_SECTION)(*piVar1 + 0x5c));
  }
  return *piVar1;
}



/* c06b53cc FUN_c06b53cc */

/* Boundary evidence: original MIPS .pdata c06b53cc..c06b543f. Semantic name remains unreviewed. */

bool FUN_c06b53cc(int param_1,byte *param_2,undefined4 param_3,int param_4)

{
  int *piVar1;
  int *piVar2;
  
  piVar1 = FUN_c06b528c(param_1,param_2,param_4);
  piVar2 = (int *)*piVar1;
  if (piVar2 != (int *)0x0) {
    EnterCriticalSection((LPCRITICAL_SECTION)(piVar2 + 0x17));
    *piVar1 = *piVar2;
    LeaveCriticalSection((LPCRITICAL_SECTION)(piVar2 + 0x17));
    FUN_c06b50f0(piVar2);
  }
  return piVar2 != (int *)0x0;
}



/* c06b5440 FUN_c06b5440 */

/* Boundary evidence: original MIPS .pdata c06b5440..c06b5547. Semantic name remains unreviewed. */

undefined4
FUN_c06b5440(int param_1,byte *param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,
            int param_6)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  uint uVar3;
  
  uVar2 = 0;
  puVar1 = LocalAlloc(0x40,0x50);
  if (puVar1 == (undefined4 *)0x0) {
    uVar2 = 3;
  }
  else {
    if (param_6 == 1) {
      memcpy(puVar1 + 1,param_2,0x10);
      FUN_c06b3b20((undefined1 *)(puVar1 + 5),(int)param_2);
    }
    else {
      uVar3 = (int)(char)*param_2 & 0xffff;
      FUN_c06b3b78(param_2,(int)(puVar1 + 1));
      if (0x2f < uVar3) {
        uVar3 = 0x2f;
      }
      memcpy(puVar1 + 5,param_2,uVar3 + 1);
    }
    puVar1[0x11] = param_3;
    puVar1[0x12] = param_5;
    puVar1[0x13] = param_4;
    *puVar1 = *(undefined4 *)(param_1 + 0x14);
    *(undefined4 **)(param_1 + 0x14) = puVar1;
  }
  return uVar2;
}



/* c06b5548 FUN_c06b5548 */

/* Boundary evidence: original MIPS .pdata c06b5548..c06b55ff. Semantic name remains unreviewed. */

int * FUN_c06b5548(int param_1,byte *param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  int *piVar3;
  int *piVar4;
  
  piVar3 = *(int **)(param_1 + 0x14);
  if (param_3 == 1) {
    while ((piVar3 != (int *)0x0 && (iVar1 = memcmp(piVar3 + 1,param_2,0x10), iVar1 != 0))) {
      piVar3 = (int *)*piVar3;
    }
  }
  else {
    uVar2 = (uint)*param_2;
    if (0x2f < uVar2) {
      uVar2 = 0x2f;
    }
    if (piVar3 != (int *)0x0) {
      piVar4 = piVar3;
      do {
        iVar1 = memcmp(piVar4 + 5,param_2,uVar2 + 1);
        if (iVar1 == 0) {
          return piVar4;
        }
        piVar4 = (int *)*piVar4;
        piVar3 = (int *)0x0;
      } while (piVar4 != (int *)0x0);
    }
  }
  return piVar3;
}



/* c06b5600 FUN_c06b5600 */

/* Boundary evidence: original MIPS .pdata c06b5600..c06b56df. Semantic name remains unreviewed. */

undefined4 FUN_c06b5600(int param_1,byte *param_2,int param_3)

{
  byte bVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  int *piVar5;
  undefined4 uVar6;
  
  piVar3 = (int *)(param_1 + 0x14);
  piVar4 = (int *)*piVar3;
  uVar6 = 2;
  if (param_3 == 1) {
    while ((piVar4 != (int *)0x0 && (iVar2 = memcmp(piVar4 + 1,param_2,0x10), iVar2 != 0))) {
      piVar3 = piVar4;
      piVar4 = (int *)*piVar4;
    }
  }
  else {
    bVar1 = *param_2;
    if (piVar4 != (int *)0x0) {
      do {
        iVar2 = memcmp(piVar4 + 5,param_2,bVar1 + 2);
        if (iVar2 == 0) break;
        piVar5 = (int *)*piVar4;
        piVar3 = piVar4;
        piVar4 = piVar5;
      } while (piVar5 != (int *)0x0);
    }
  }
  piVar4 = (int *)*piVar3;
  if (piVar4 != (int *)0x0) {
    *piVar3 = *piVar4;
    LocalFree(piVar4);
    uVar6 = 0;
  }
  return uVar6;
}



/* c06b56e0 FUN_c06b56e0 */

/* Boundary evidence: original MIPS .pdata c06b56e0..c06b589f. Semantic name remains unreviewed. */

int FUN_c06b56e0(int param_1,char *param_2,uint param_3,uint param_4)

{
  uint *puVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  
  uVar4 = 0x60;
  if ((param_3 & 0x80) != 0) {
    uVar4 = 0xe0;
  }
  iVar2 = 0x10000;
  if ((param_3 & 1) == 0) {
    iVar2 = 1;
  }
  puVar1 = FUN_c06b4224(iVar2,param_2,uVar4,param_4);
  if (puVar1 == (uint *)0x0) {
    return 3;
  }
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x38));
  *(short *)(param_1 + 8) = (short)puVar1[4];
  iVar2 = FUN_c06b43d4((int)puVar1,param_1,0x2038,2);
  if (iVar2 != 0) goto LAB_c06b5858;
  if ((*(uint *)(param_1 + 0x10) & 2) == 0) {
    if (((*(uint *)(param_1 + 0x10) & 1) != 0) &&
       (uVar3 = *(uint *)(param_1 + 0x18), (uVar3 & 0x10) == 0)) {
      if ((uVar3 & 8) != 0) {
        iVar2 = 0;
        goto LAB_c06b5858;
      }
      if ((uVar3 & 0x20) == 0) goto LAB_c06b5858;
      memset((void *)((int)puVar1 + 0x12),0,10);
      puVar1[1] = *(uint *)(param_1 + 0x24);
      FUN_c06b3bdc(puVar1,0x200,param_2,uVar4,param_4,(undefined4 *)0x0,0);
      FUN_c06b43d4((int)puVar1,param_1,0xc00,4);
      if ((*(uint *)(param_1 + 0x10) & 2) != 0) goto LAB_c06b5828;
      if ((*(uint *)(param_1 + 0x10) & 1) == 0) {
        trap(0x400);
        goto LAB_c06b5858;
      }
      if ((*(uint *)(param_1 + 0x18) & 0x400) == 0) goto LAB_c06b5858;
    }
    iVar2 = 2;
  }
  else {
LAB_c06b5828:
    iVar2 = 1;
  }
LAB_c06b5858:
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x38));
  FUN_c06b3b04(puVar1);
  return iVar2;
}



/* c06b58a0 FUN_c06b58a0 */

/* Boundary evidence: original MIPS .pdata c06b58a0..c06b59bb. Semantic name remains unreviewed. */

int FUN_c06b58a0(int param_1,char *param_2,uint param_3,uint param_4,uint param_5)

{
  uint *puVar1;
  int iVar2;
  uint uVar3;
  
  uVar3 = 0x61;
  if ((param_3 & 0x80) != 0) {
    uVar3 = 0xe1;
  }
  puVar1 = FUN_c06b4224(1,param_2,uVar3,param_4);
  if (puVar1 == (uint *)0x0) {
    iVar2 = 3;
  }
  else {
    EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x38));
    *(short *)(param_1 + 8) = (short)puVar1[4];
    puVar1[1] = param_5;
    iVar2 = FUN_c06b43d4((int)puVar1,param_1,0x10,1);
    if (iVar2 == 0) {
      if ((*(uint *)(param_1 + 0x10) & 2) == 0) {
        if ((*(uint *)(param_1 + 0x10) & 1) == 0) {
          *(ushort *)((int)puVar1 + 0x12) = *(ushort *)((int)puVar1 + 0x12) & 0xfffe;
          iVar2 = FUN_c06b43d4((int)puVar1,param_1,0,9);
        }
        else if ((*(uint *)(param_1 + 0x18) & 0x10) != 0) {
          iVar2 = 2;
        }
      }
      else {
        iVar2 = 1;
      }
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x38));
    FUN_c06b3b04(puVar1);
  }
  return iVar2;
}



/* c06b59bc FUN_c06b59bc */

/* Boundary evidence: original MIPS .pdata c06b59bc..c06b5ab7. Semantic name remains unreviewed. */

int FUN_c06b59bc(int param_1,char *param_2,int param_3,uint param_4)

{
  uint *puVar1;
  int iVar2;
  uint uVar3;
  
  uVar3 = 0x60;
  if (param_3 != 0) {
    uVar3 = 0xe0;
  }
  puVar1 = FUN_c06b4224(0x40,param_2,uVar3,param_4);
  if (puVar1 == (uint *)0x0) {
    iVar2 = 3;
  }
  else {
    EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x38));
    *(short *)(param_1 + 8) = (short)puVar1[4];
    iVar2 = FUN_c06b43d4((int)puVar1,param_1,0x2180,2);
    if (iVar2 == 0) {
      if ((*(uint *)(param_1 + 0x10) & 2) == 0) {
        if (((*(uint *)(param_1 + 0x10) & 1) == 0) || ((*(uint *)(param_1 + 0x18) & 0x100) != 0)) {
          iVar2 = 2;
        }
        else if ((*(uint *)(param_1 + 0x18) & 0x80) != 0) {
          iVar2 = 0;
        }
      }
      else {
        iVar2 = 1;
      }
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x38));
    FUN_c06b3b04(puVar1);
  }
  return iVar2;
}



/* c06b5ab8 FUN_c06b5ab8 */

/* Boundary evidence: original MIPS .pdata c06b5ab8..c06b5b67. Semantic name remains unreviewed. */

undefined4 FUN_c06b5ab8(int param_1,char *param_2,int param_3,uint param_4,uint param_5)

{
  uint *puVar1;
  uint uVar2;
  undefined4 uVar3;
  
  uVar3 = 0;
  uVar2 = 0x61;
  if (param_3 != 0) {
    uVar2 = 0xe1;
  }
  puVar1 = FUN_c06b4224(0x40,param_2,uVar2,param_4);
  if (puVar1 == (uint *)0x0) {
    uVar3 = 3;
  }
  else {
    EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x38));
    *(short *)(param_1 + 8) = (short)puVar1[4];
    puVar1[1] = param_5;
    FUN_c06b43d4((int)puVar1,param_1,0,9);
    LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x38));
    FUN_c06b3b04(puVar1);
  }
  return uVar3;
}



/* c06b5b68 FUN_c06b5b68 */

/* Boundary evidence: original MIPS .pdata c06b5b68..c06b5dab. Semantic name remains unreviewed. */

int FUN_c06b5b68(int param_1)

{
  short sVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  byte *pbVar9;
  uint uVar10;
  
  iVar6 = 0;
  uVar8 = 100;
  piVar2 = (int *)FUN_c06b1b00((uint)*(byte *)(param_1 + 0x30));
  if (piVar2 == (int *)0x0) {
    iVar6 = 0x14;
  }
  else {
    sVar1 = *(short *)(param_1 + 8);
    if (sVar1 == 7) {
      uVar8 = 0x100064;
    }
    uVar7 = (uint)(sVar1 == 7);
    if (sVar1 == 9) {
      uVar8 = uVar8 | 0x80;
      uVar7 = 0x80;
    }
    pbVar9 = (byte *)(param_1 + 0x20);
    iVar3 = FUN_c06b538c((int)piVar2,pbVar9,uVar8,1);
    if (iVar3 == 0) {
      if ((DAT_c06bc5f8 == 0) && (*(short *)(param_1 + 8) != 0xb)) {
        piVar4 = FUN_c06b8240(param_1);
        if (piVar4 == (int *)0x0) {
          iVar6 = 3;
        }
        else {
          uVar5 = piVar2[3];
          uVar10 = piVar2[1];
          piVar4[3] = piVar2[0xc];
          *(short *)((int)piVar4 + 10) = (short)piVar2[0xd];
          LeaveCriticalSection((LPCRITICAL_SECTION)(piVar2 + 7));
          iVar3 = FUN_c06b56e0((int)piVar4,(char *)pbVar9,uVar7,uVar10);
          iVar6 = 0;
          if (iVar3 != 0) {
            iVar6 = FUN_c06b58a0((int)piVar4,(char *)pbVar9,uVar7,uVar10,uVar5);
          }
          EnterCriticalSection((LPCRITICAL_SECTION)(piVar2 + 7));
          if ((*(byte *)((int)piVar2 + 0x39) & 1) == 0) {
            if (((iVar6 == 0) && (FUN_c06b5160((int)piVar2,pbVar9,uVar8,piVar4[8],1), sVar1 != 9))
               && ((uVar7 & 1) != 0)) {
              *(byte *)((int)piVar2 + 0x39) = *(byte *)((int)piVar2 + 0x39) | 4;
            }
          }
          else {
            iVar6 = 0x14;
          }
          FUN_c06b82f0(piVar4);
        }
      }
      else {
        FUN_c06b5160((int)piVar2,pbVar9,uVar8 | 0x200000,0,1);
      }
    }
    else {
      LeaveCriticalSection((LPCRITICAL_SECTION)(iVar3 + 0x5c));
      iVar6 = 5;
    }
    FUN_c06b1de4(piVar2);
  }
  return iVar6;
}



/* c06b5dac FUN_c06b5dac */

/* Boundary evidence: original MIPS .pdata c06b5dac..c06b5f47. Semantic name remains unreviewed. */

int FUN_c06b5dac(int param_1)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  uint uVar5;
  int iVar6;
  byte *pbVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  
  iVar6 = 0;
  piVar2 = (int *)FUN_c06b1b00((uint)*(byte *)(param_1 + 0x30));
  if (piVar2 == (int *)0x0) {
    iVar6 = 0x14;
  }
  else {
    pbVar7 = (byte *)(param_1 + 0x20);
    iVar3 = FUN_c06b538c((int)piVar2,pbVar7,0,1);
    if (iVar3 == 0) {
      iVar6 = 4;
    }
    else {
      uVar9 = piVar2[1];
      uVar8 = *(uint *)(iVar3 + 0x44) & 0x80;
      uVar5 = piVar2[3];
      iVar1 = piVar2[0xd];
      iVar10 = piVar2[0xc];
      LeaveCriticalSection((LPCRITICAL_SECTION)(piVar2 + 7));
      LeaveCriticalSection((LPCRITICAL_SECTION)(iVar3 + 0x5c));
      piVar4 = FUN_c06b8240(param_1);
      if (piVar4 == (int *)0x0) {
        iVar6 = 3;
      }
      else {
        *(short *)((int)piVar4 + 10) = (short)iVar1;
        piVar4[3] = iVar10;
        if (((*(uint *)(iVar3 + 0x44) & 0x200000) == 0) &&
           (iVar3 = FUN_c06b59bc((int)piVar4,(char *)pbVar7,uVar8,uVar9), iVar6 = 0, iVar3 != 0)) {
          iVar6 = FUN_c06b5ab8((int)piVar4,(char *)pbVar7,uVar8,uVar9,uVar5);
        }
        EnterCriticalSection((LPCRITICAL_SECTION)(piVar2 + 7));
        if (iVar6 == 0) {
          FUN_c06b53cc((int)piVar2,pbVar7,0,1);
        }
        FUN_c06b82f0(piVar4);
      }
    }
    FUN_c06b1de4(piVar2);
  }
  return iVar6;
}



/* c06b5f48 FUN_c06b5f48 */

/* Boundary evidence: original MIPS .pdata c06b5f48..c06b6087. Semantic name remains unreviewed. */

int FUN_c06b5f48(int param_1,char *param_2,int param_3,uint param_4)

{
  bool bVar1;
  uint *puVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  
  uVar5 = 0x60;
  iVar6 = 0;
  if (param_3 != 0) {
    uVar5 = 0xe0;
  }
  do {
    puVar2 = FUN_c06b4224(0x200,param_2,uVar5,param_4);
    if (puVar2 == (uint *)0x0) {
      return 3;
    }
    EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x38));
    *(short *)(param_1 + 8) = (short)puVar2[4];
    iVar3 = FUN_c06b43d4((int)puVar2,param_1,0x3c00,2);
    if (iVar3 != 0) break;
    if ((*(uint *)(param_1 + 0x10) & 2) != 0) {
      iVar3 = 1;
      break;
    }
    if (((*(uint *)(param_1 + 0x10) & 1) == 0) ||
       (uVar4 = *(uint *)(param_1 + 0x18), (uVar4 & 0x800) != 0)) {
      iVar3 = 2;
      break;
    }
    if ((uVar4 & 0x400) != 0) {
      iVar3 = 0;
      break;
    }
    if ((uVar4 & 0x1000) == 0) break;
    FUN_c06b3b04(puVar2);
    bVar1 = iVar6 < 5;
    param_4 = *(uint *)(param_1 + 0x24);
    iVar6 = iVar6 + 1;
  } while (bVar1);
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x38));
  FUN_c06b3b04(puVar2);
  return iVar3;
}



/* c06b6088 FUN_c06b6088 */

/* Boundary evidence: original MIPS .pdata c06b6088..c06b617b. Semantic name remains unreviewed. */

undefined4 FUN_c06b6088(int param_1,char *param_2,int param_3,uint param_4,uint param_5)

{
  uint *puVar1;
  uint uVar2;
  undefined4 uVar3;
  
  uVar2 = 0x61;
  if (param_3 != 0) {
    uVar2 = 0xe1;
  }
  puVar1 = FUN_c06b4224(0x200,param_2,uVar2,param_4);
  if (puVar1 == (uint *)0x0) {
    uVar3 = 3;
  }
  else {
    EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x38));
    *(undefined4 *)(param_1 + 0x18) = 0;
    *(uint *)(param_1 + 0x10) = *(uint *)(param_1 + 0x10) & 0xfffffffe;
    *(short *)(param_1 + 8) = (short)puVar1[4];
    uVar3 = 1;
    puVar1[1] = param_5;
    FUN_c06b43d4((int)puVar1,param_1,0x400,1);
    if (((*(uint *)(param_1 + 0x10) & 2) == 0) &&
       (((*(uint *)(param_1 + 0x10) & 1) == 0 ||
        (uVar3 = 0, (*(uint *)(param_1 + 0x18) & 0x400) == 0)))) {
      uVar3 = 2;
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x38));
    FUN_c06b3b04(puVar1);
  }
  return uVar3;
}



/* c06b617c FUN_c06b617c */

/* Boundary evidence: original MIPS .pdata c06b617c..c06b63eb. Semantic name remains unreviewed. */

int FUN_c06b617c(int param_1,int *param_2,uint *param_3)

{
  int *piVar1;
  int *piVar2;
  undefined4 *puVar3;
  uint *puVar4;
  int iVar5;
  int iVar6;
  byte *pbVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  
  uVar8 = 0;
  piVar1 = (int *)FUN_c06b1b00((uint)*(byte *)(param_1 + 0x30));
  if (piVar1 == (int *)0x0) {
    return 0x14;
  }
  uVar10 = piVar1[3];
  uVar9 = piVar1[1];
  if (param_3 != (uint *)0x0) {
    *param_3 = uVar9;
  }
  pbVar7 = (byte *)(param_1 + 0x20);
  if (*(short *)(param_1 + 8) != 0x10) {
    pbVar7 = (byte *)(param_1 + 0x10);
  }
  piVar2 = FUN_c06b5548((int)piVar1,pbVar7,1);
  if (piVar2 == (int *)0x0) {
    iVar6 = FUN_c06b538c((int)piVar1,pbVar7,100,1);
    if (iVar6 != 0) {
      if ((*(uint *)(iVar6 + 0x44) & 0x80) != 0) {
        uVar8 = 0x80000000;
      }
      LeaveCriticalSection((LPCRITICAL_SECTION)(iVar6 + 0x5c));
      puVar4 = LocalAlloc(0x40,8);
      *param_2 = (int)puVar4;
      if (puVar4 == (uint *)0x0) goto LAB_c06b6238;
      *puVar4 = uVar8 | 1;
      *(undefined4 *)(*param_2 + 4) = 0x100007f;
      goto LAB_c06b6230;
    }
    piVar2 = FUN_c06b8240(param_1);
    if (piVar2 == (int *)0x0) {
      LeaveCriticalSection((LPCRITICAL_SECTION)(piVar1 + 7));
      iVar6 = 3;
LAB_c06b638c:
      if (iVar6 != 0) goto LAB_c06b63a4;
    }
    else {
      piVar2[3] = piVar1[0xc];
      *(short *)((int)piVar2 + 10) = (short)piVar1[0xd];
      LeaveCriticalSection((LPCRITICAL_SECTION)(piVar1 + 7));
      iVar5 = FUN_c06b5f48((int)piVar2,(char *)pbVar7,0,uVar9);
      iVar6 = 0;
      if ((iVar5 == 0) ||
         (iVar6 = FUN_c06b6088((int)piVar2,(char *)pbVar7,0,uVar9,uVar10), iVar6 == 0)) {
        *param_2 = piVar2[10];
        FUN_c06b5440((int)piVar1,pbVar7,0,*(undefined4 *)(piVar2[10] + 4),600,1);
      }
      FUN_c06b82f0(piVar2);
      EnterCriticalSection((LPCRITICAL_SECTION)(piVar1 + 7));
      if (iVar6 != 0) {
        if (DAT_c06bc104 != (code *)0x0) {
          (*DAT_c06bc104)();
        }
        goto LAB_c06b638c;
      }
    }
  }
  else {
    iVar6 = piVar2[0x13];
    puVar3 = LocalAlloc(0x40,8);
    *param_2 = (int)puVar3;
    if (puVar3 == (undefined4 *)0x0) {
LAB_c06b6238:
      iVar6 = 3;
      goto LAB_c06b63a4;
    }
    *puVar3 = 1;
    *(int *)(*param_2 + 4) = iVar6;
LAB_c06b6230:
    iVar6 = 0;
  }
  if (*param_2 == 0) {
    iVar6 = 2;
  }
LAB_c06b63a4:
  FUN_c06b1de4(piVar1);
  return iVar6;
}



/* c06b63ec FUN_c06b63ec */

/* Boundary evidence: original MIPS .pdata c06b63ec..c06b6577. Semantic name remains unreviewed. */

undefined4
FUN_c06b63ec(int param_1,uint param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,
            undefined4 param_6)

{
  uint uVar1;
  int *piVar2;
  LPCRITICAL_SECTION lpCriticalSection;
  undefined4 uVar3;
  
  uVar3 = 0;
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c06bc120);
  piVar2 = (int *)DAT_c06bc134;
  do {
    if (piVar2 == (int *)0x0) {
LAB_c06b64e4:
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c06bc120);
      return uVar3;
    }
    lpCriticalSection = (LPCRITICAL_SECTION)(piVar2 + 0xe);
    EnterCriticalSection(lpCriticalSection);
    if (*(short *)(piVar2 + 2) == *(short *)(param_1 + 0x10)) {
      if ((piVar2[5] & param_2) != 0) {
        piVar2[6] = param_2 | piVar2[6];
        uVar3 = 1;
        if ((*(ushort *)(param_1 + 0x12) & 0xf00) == 0) {
          if (param_2 == 8) {
            piVar2[8] = param_5;
          }
          else {
            if (param_2 != 0x400) {
              if ((param_2 == 0x20) || (param_2 == 0x1000)) {
                piVar2[9] = param_6;
              }
              goto LAB_c06b6560;
            }
            if ((HLOCAL)piVar2[10] != (HLOCAL)0x0) {
              LocalFree((HLOCAL)piVar2[10]);
            }
            piVar2[10] = param_6;
          }
        }
        else {
          piVar2[0xb] = *(ushort *)(param_1 + 0x12) & 0xf00;
LAB_c06b6560:
          if (param_2 == 0x2000) {
            piVar2[7] = param_5;
            goto LAB_c06b64dc;
          }
        }
        uVar1 = piVar2[4];
        piVar2[4] = uVar1 | 1;
        if ((uVar1 & 8) != 0) {
          EventModify(piVar2[0xc],3);
        }
      }
LAB_c06b64dc:
      LeaveCriticalSection((LPCRITICAL_SECTION)(piVar2 + 0xe));
      goto LAB_c06b64e4;
    }
    piVar2 = (int *)*piVar2;
    LeaveCriticalSection(lpCriticalSection);
  } while( true );
}



/* c06b6578 FUN_c06b6578 */

/* Boundary evidence: original MIPS .pdata c06b6578..c06b65d3. Semantic name remains unreviewed. */

void FUN_c06b6578(int param_1,int param_2,undefined4 param_3,byte *param_4,undefined4 param_5)

{
  int iVar1;
  
  iVar1 = FUN_c06b538c(param_1,param_4,0,2);
  if (iVar1 != 0) {
    if (*(short *)(iVar1 + 0x4c) == *(short *)(param_2 + 0x10)) {
      *(undefined4 *)(iVar1 + 0x48) = param_5;
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)(iVar1 + 0x5c));
  }
  return;
}



/* c06b65d4 FUN_c06b65d4 */

/* Boundary evidence: original MIPS .pdata c06b65d4..c06b6b77. Semantic name remains unreviewed. */

bool FUN_c06b65d4(int param_1,int param_2,uint param_3,uint param_4,ushort param_5,ushort param_6,
                 ushort param_7,void *param_8,void *param_9,uint param_10,undefined4 *param_11,
                 uint *param_12,uint *param_13)

{
  bool bVar1;
  short sVar2;
  bool bVar3;
  uint *puVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  ushort uVar8;
  uint uVar9;
  uint _Size;
  ushort *_Src;
  uint uVar10;
  short local_60;
  void *local_58;
  undefined4 local_38;
  uint local_34;
  ushort local_30;
  
  local_60 = 0;
  bVar3 = true;
  local_58 = param_8;
  if (((((*(ushort *)(param_1 + 2) & 0xe007) == param_3) && (*(ushort *)(param_1 + 4) == param_4))
      && (*(ushort *)(param_1 + 6) == param_5)) &&
     ((*(ushort *)(param_1 + 8) == param_6 && (*(ushort *)(param_1 + 10) == param_7)))) {
    uVar10 = 0xc;
    if (param_4 != 0) {
      uVar10 = (uint)*(byte *)(param_1 + 0xc);
      if (param_2 < (int)(uVar10 + 0x12)) {
        return false;
      }
      local_38 = *(uint *)(uVar10 + param_1 + 0xe);
      if (((local_38 & 0xffff) == (param_10 & 0xffff)) &&
         (local_38._2_2_ = (short)(local_38 >> 0x10), local_38._2_2_ == 0x100)) {
        if ((param_10 == 0x2000) || (param_10 == 0x2100)) {
          if (0x30 < uVar10 + 2) {
            return false;
          }
          memcpy(param_8,(byte *)(param_1 + 0xc),uVar10 + 2);
          local_58 = param_9;
        }
      }
      else {
        bVar3 = false;
      }
      uVar10 = uVar10 + 0x12;
    }
    uVar8 = param_5 << 8 | param_5 >> 8;
    bVar1 = true;
    iVar5 = 2;
    sVar2 = (short)param_10;
    if (bVar3) {
      do {
        if ((ushort)((param_7 << 8 | param_7 >> 8) + (param_6 << 8 | param_6 >> 8) + uVar8) == 0) {
          return bVar1;
        }
        if (iVar5 == 0) {
          return bVar1;
        }
        _Src = (ushort *)(uVar10 + param_1);
        if ((*_Src & 0xc0) == 0) {
          uVar9 = (uint)(byte)*_Src;
        }
        else {
          memcpy(local_58,param_8,0x30);
          uVar9 = 0;
        }
        if (param_2 < (int)(uVar9 + uVar10 + 0xc)) {
          return false;
        }
        iVar6 = uVar9 + uVar10 + param_1;
        memcpy(&local_38,(void *)(iVar6 + 2),10);
        uVar7 = (local_34 & 0xff0000 | local_34 >> 0x10) >> 8 |
                (local_34 << 0x10 | local_34 & 0xff00) << 8;
        _Size = (local_30 & 0xff) << 8 | (uint)(local_30 >> 8);
        local_30 = (ushort)_Size;
        local_34 = uVar7;
        if (((short)local_38 == sVar2) && (local_38._2_2_ == 0x100)) {
          if (sVar2 == 0x2000) {
            if (uVar9 != 0) {
              if (0x30 < uVar9 + 2) {
                return false;
              }
              memcpy(local_58,_Src,uVar9 + 2);
            }
            local_58 = param_9;
          }
          else if (sVar2 == 0x200) {
            if (param_2 < (int)(_Size + uVar9 + uVar10 + 0xc)) {
              return false;
            }
            if (0x30 < uVar9 + 2) {
              return false;
            }
            if (0x30 < _Size) {
              return false;
            }
            memcpy(local_58,_Src,uVar9 + 2);
            memcpy(param_9,(void *)(iVar6 + 0xc),_Size);
            local_58 = param_9;
            local_60 = 0x100;
          }
        }
        else {
          bVar1 = false;
        }
        *param_12 = uVar7;
        uVar10 = uVar9 + uVar10 + 0xc & 0xffff;
        if (sVar2 == 0x2000) {
          if (param_2 < (int)(uVar10 + _Size)) {
            return false;
          }
          if (((*(ushort *)(param_1 + 2) & 0x78) == 0) && (5 < _Size)) {
            uVar9 = _Size / 6;
            *param_13 = *(byte *)(uVar10 + param_1) & 0x80;
            puVar4 = LocalAlloc(0x40,(uVar9 + 1) * 4);
            *param_11 = puVar4;
            if (*param_13 == 0) {
              *puVar4 = uVar9;
            }
            else {
              *puVar4 = 0;
            }
            uVar7 = 0;
            if (uVar9 != 0) {
              do {
                puVar4 = puVar4 + 1;
                iVar6 = uVar7 * 6;
                uVar7 = uVar7 + 1 & 0xffff;
                *puVar4 = *(uint *)(iVar6 + uVar10 + param_1 + 2);
              } while (uVar7 < uVar9);
            }
          }
          else if (_Size == 6) {
            *param_13 = *(byte *)(uVar10 + param_1) & 0x80;
            *param_11 = *(undefined4 *)((byte *)(uVar10 + param_1) + 2);
          }
          else if (_Size != 2) {
            bVar1 = false;
          }
        }
        else if (sVar2 == 0x100) {
          bVar1 = _Size == 4;
          if (param_2 < (int)(uVar10 + 6)) {
            return false;
          }
          *param_11 = *(undefined4 *)(uVar10 + param_1 + 2);
        }
        uVar10 = _Size + uVar10 & 0xffff;
        uVar8 = uVar8 - 1;
        iVar5 = iVar5 + -1;
        sVar2 = local_60;
      } while (bVar1);
    }
  }
  return false;
}



/* c06b6b78 FUN_c06b6b78 */

/* Boundary evidence: original MIPS .pdata c06b6b78..c06b6c47. Semantic name remains unreviewed. */

void FUN_c06b6b78(uint *param_1,char *param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  
  iVar1 = FUN_c06b1a70(param_3);
  if (iVar1 != 0) {
    uVar2 = *(uint *)(iVar1 + 4);
    LeaveCriticalSection((LPCRITICAL_SECTION)(iVar1 + 0x1c));
    uVar3 = *param_1;
    if ((uVar2 != uVar3) && (iVar1 = memcmp(&DAT_c06bc660,param_2,0x22), iVar1 == 0)) {
      param_1[1] = uVar3;
      *(short *)((int)param_1 + 10) = (short)param_1[2];
      *param_1 = uVar2;
      *(undefined2 *)((int)param_1 + 0x12) = 0;
      *(undefined2 *)(param_1 + 5) = 0;
      *(undefined2 *)((int)param_1 + 0x16) = 0x100;
      *(undefined2 *)(param_1 + 6) = 0;
      *(undefined2 *)((int)param_1 + 0x1a) = 0;
      FUN_c06b3bdc(param_1,0x10,param_2,0,uVar2,(undefined4 *)0x0,0);
      FUN_c06b42b8((int)param_1);
    }
  }
  return;
}



/* c06b6c48 FUN_c06b6c48 */

/* WARNING: Type propagation algorithm not settling */
/* Boundary evidence: original MIPS .pdata c06b6c48..c06b769f. Semantic name remains unreviewed. */

void FUN_c06b6c48(void)

{
  ushort uVar1;
  uint *puVar2;
  bool bVar3;
  undefined3 extraout_var;
  char *pcVar4;
  undefined3 extraout_var_00;
  undefined3 extraout_var_01;
  undefined3 extraout_var_02;
  undefined3 extraout_var_03;
  undefined3 extraout_var_04;
  undefined3 extraout_var_05;
  undefined3 extraout_var_06;
  undefined3 extraout_var_07;
  undefined3 extraout_var_08;
  undefined3 extraout_var_09;
  int iVar5;
  int iVar6;
  undefined3 extraout_var_10;
  LPCRITICAL_SECTION p_Var7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint *puVar11;
  uint uVar12;
  int *piVar13;
  int *piVar14;
  int iVar15;
  int iVar16;
  uint local_e0;
  uint local_dc;
  uint auStack_d8 [4];
  undefined4 local_c8;
  uint *local_c4;
  undefined1 auStack_c0 [2];
  undefined2 local_be;
  uint local_bc;
  uint local_b8;
  byte abStack_b0 [48];
  int local_80 [16];
  char acStack_40 [16];
  uint local_30;
  
  local_30 = DAT_c06bc0f4;
  auStack_d8[2] = 0x10;
  DAT_c06bc54c[3] = 0x250;
  DAT_c06bc54c[1] = 0;
  *DAT_c06bc54c = 0;
  local_c8 = 0x240;
  local_c4 = DAT_c06bc54c + 4;
  auStack_d8[1] = 0;
  iVar15 = 1;
  (**(code **)(DAT_c06bc5dc + 0x1c))
            (DAT_c06bc5f4,&local_c8,1,DAT_c06bc54c + 3,0,auStack_d8 + 1,auStack_c0,auStack_d8 + 2,0,
             0,0);
  *DAT_c06bc54c = local_bc;
  *(undefined2 *)(DAT_c06bc54c + 2) = local_be;
  puVar2 = DAT_c06bc54c;
  uVar8 = DAT_c06bc54c[3];
  uVar12 = local_b8 & 0xffffff;
  puVar11 = DAT_c06bc54c + 4;
  if ((int)uVar8 < 0xc) goto LAB_c06b766c;
  uVar1 = *(ushort *)((int)DAT_c06bc54c + 0x12);
  uVar9 = (uint)uVar1;
  uVar10 = uVar9 & 0x78;
  if ((uVar1 & 0x78) != 0) {
    if (uVar10 == 0x28) {
      if ((uVar1 & 0x80) == 0) {
        bVar3 = FUN_c06b65d4((int)puVar11,uVar8,0,0x100,0,0,0x100,abStack_b0,local_80,0x2000,
                             &local_e0,&local_dc,auStack_d8);
        if (((CONCAT31(extraout_var_03,bVar3) == 0) && ((uVar1 & 0x1000) != 0)) &&
           (bVar3 = FUN_c06b65d4((int)puVar11,DAT_c06bc54c[3],1,0x100,0,0,0x100,abStack_b0,local_80,
                                 0x2000,&local_e0,&local_dc,auStack_d8),
           CONCAT31(extraout_var_04,bVar3) != 0)) {
          FUN_c06b6b78(DAT_c06bc54c,(char *)abStack_b0,uVar12);
        }
        goto LAB_c06b766c;
      }
      bVar3 = FUN_c06b65d4((int)puVar11,uVar8,0x8005,0,0x100,0,0,abStack_b0,local_80,0x2000,
                           &local_e0,&local_dc,auStack_d8);
      if (CONCAT31(extraout_var_01,bVar3) == 0) {
        bVar3 = FUN_c06b65d4((int)puVar11,DAT_c06bc54c[3],1,0,0x100,0,0,abStack_b0,local_80,0x2000,
                             &local_dc,&local_e0,auStack_d8);
        if (CONCAT31(extraout_var_02,bVar3) != 0) {
          FUN_c06b63ec((int)DAT_c06bc54c,0x20,abStack_b0,local_80,local_dc,local_e0);
        }
        goto LAB_c06b766c;
      }
      uVar8 = 8;
      pcVar4 = (char *)FUN_c06b1a70(uVar12);
      if (pcVar4 == (char *)0x0) goto LAB_c06b766c;
      if (((*(ushort *)((int)puVar2 + 0x12) & 0xf00) != 0) &&
         (uVar8 = 0x10, (*(ushort *)((int)puVar2 + 0x12) & 0xf00) == 0x700)) {
        uVar8 = 0x10;
        iVar15 = FUN_c06b538c((int)pcVar4,abStack_b0,0,2);
        if (iVar15 != 0) {
          *(uint *)(iVar15 + 0x44) = *(uint *)(iVar15 + 0x44) | 8;
          LeaveCriticalSection((LPCRITICAL_SECTION)(iVar15 + 0x5c));
        }
      }
      iVar15 = FUN_c06b63ec((int)DAT_c06bc54c,uVar8,abStack_b0,local_80,local_dc,local_e0);
      if (iVar15 == 0) {
        FUN_c06b6578((int)pcVar4,(int)DAT_c06bc54c,uVar8,abStack_b0,local_dc);
      }
    }
    else {
      if (uVar10 != 0x30) {
        if (((uVar10 == 0x38) && ((uVar1 & 0x80) != 0)) && ((uVar1 & 0xf00) == 0)) {
          FUN_c06b65d4((int)puVar11,uVar8,4,0,0x100,0,0,abStack_b0,local_80,0x2000,&local_e0,
                       &local_dc,auStack_d8);
        }
        goto LAB_c06b766c;
      }
      if ((uVar1 & 0x80) != 0) {
        uVar12 = 0x100;
        if ((uVar1 & 0xf00) == 0) {
          uVar12 = 0x80;
        }
        FUN_c06b65d4((int)puVar11,uVar8,4,0,0x100,0,0,abStack_b0,local_80,0x2000,&local_e0,&local_dc
                     ,auStack_d8);
        FUN_c06b63ec((int)DAT_c06bc54c,uVar12,abStack_b0,local_80,local_dc,local_e0);
        goto LAB_c06b766c;
      }
      bVar3 = FUN_c06b65d4((int)puVar11,uVar8,0,0x100,0,0,0x100,abStack_b0,local_80,0x2000,&local_e0
                           ,&local_dc,auStack_d8);
      if ((CONCAT31(extraout_var,bVar3) == 0) ||
         (pcVar4 = (char *)FUN_c06b1a70(uVar12), pcVar4 == (char *)0x0)) goto LAB_c06b766c;
      bVar3 = FUN_c06b53cc((int)pcVar4,abStack_b0,0,2);
      if (CONCAT31(extraout_var_00,bVar3) == 0) {
        FUN_c06b5600((int)pcVar4,abStack_b0,2);
      }
    }
    goto LAB_c06b7660;
  }
  if ((uVar1 & 0x80) != 0) {
    if ((uVar1 & 0xf00) == 0) {
      bVar3 = FUN_c06b65d4((int)puVar11,uVar8,uVar9 & 0x8002 | 5,0,0x100,0,0,abStack_b0,local_80,
                           0x2000,&local_e0,&local_dc,auStack_d8);
      if (CONCAT31(extraout_var_06,bVar3) == 0) {
        bVar3 = FUN_c06b65d4((int)puVar11,DAT_c06bc54c[3],1,0,0,0x100,0x100,abStack_b0,local_80,
                             0x200,&local_e0,&local_dc,auStack_d8);
        if (CONCAT31(extraout_var_07,bVar3) == 0) {
          bVar3 = FUN_c06b65d4((int)puVar11,DAT_c06bc54c[3],4,0,0x100,0,0,abStack_b0,local_80,0x2100
                               ,&local_e0,&local_dc,auStack_d8);
          if (CONCAT31(extraout_var_08,bVar3) == 0) goto LAB_c06b766c;
          uVar8 = 0x8000;
        }
        else {
          uVar8 = 0x1000;
        }
      }
      else {
        uVar8 = 0x400;
      }
    }
    else {
      bVar3 = FUN_c06b65d4((int)puVar11,uVar8,uVar9 & 0x8000 | 5,0,0,0,0,abStack_b0,local_80,0xa00,
                           (undefined4 *)0x0,&local_dc,auStack_d8);
      if (CONCAT31(extraout_var_05,bVar3) == 0) goto LAB_c06b766c;
      uVar8 = 0x800;
    }
    FUN_c06b63ec((int)DAT_c06bc54c,uVar8,abStack_b0,local_80,local_dc,local_e0);
    goto LAB_c06b766c;
  }
  DAT_c06bc54c[1] = *DAT_c06bc54c;
  *(short *)((int)DAT_c06bc54c + 10) = (short)DAT_c06bc54c[2];
  bVar3 = FUN_c06b65d4((int)puVar11,DAT_c06bc54c[3],1,0x100,0,0,0,abStack_b0,local_80,0x2000,
                       &local_e0,(uint *)0x0,(uint *)0x0);
  if (CONCAT31(extraout_var_09,bVar3) == 0) {
    bVar3 = FUN_c06b65d4((int)puVar11,DAT_c06bc54c[3],0,0x100,0,0,0,abStack_b0,local_80,0x2100,
                         &local_e0,(uint *)0x0,auStack_d8);
    if ((CONCAT31(extraout_var_10,bVar3) == 0) ||
       (pcVar4 = (char *)FUN_c06b1a70(uVar12), pcVar4 == (char *)0x0)) goto LAB_c06b766c;
    uVar8 = *(uint *)(pcVar4 + 4);
    iVar15 = memcmp(abStack_b0,s_CKAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA_c06bc0c0,0x22);
    if (iVar15 == 0) {
      *(undefined2 *)(puVar2 + 5) = 0;
      FUN_c06b3bdc(DAT_c06bc54c,0x8000,pcVar4,0,uVar8,(undefined4 *)0x0,0);
      p_Var7 = (LPCRITICAL_SECTION)(pcVar4 + 0x1c);
LAB_c06b7640:
      LeaveCriticalSection(p_Var7);
      goto LAB_c06b7648;
    }
    iVar15 = FUN_c06b538c((int)pcVar4,abStack_b0,0,2);
    if (iVar15 != 0) {
      if ((*(uint *)(iVar15 + 0x44) & 0x200000) == 0) {
        *(undefined2 *)(puVar2 + 5) = 0;
        FUN_c06b3bdc(DAT_c06bc54c,0x8000,(char *)(iVar15 + 4),(uint)*(ushort *)(iVar15 + 0x44),
                     (uint)pcVar4,(undefined4 *)0x0,0);
        *DAT_c06bc54c = uVar8;
        LeaveCriticalSection((LPCRITICAL_SECTION)(pcVar4 + 0x1c));
        p_Var7 = (LPCRITICAL_SECTION)(iVar15 + 0x5c);
        goto LAB_c06b7640;
      }
      LeaveCriticalSection((LPCRITICAL_SECTION)(iVar15 + 0x5c));
    }
LAB_c06b7660:
    p_Var7 = (LPCRITICAL_SECTION)(pcVar4 + 0x1c);
  }
  else {
    iVar5 = FUN_c06b1a70(uVar12);
    if (iVar5 == 0) goto LAB_c06b766c;
    iVar6 = FUN_c06b538c(iVar5,abStack_b0,0,2);
    if (iVar6 != 0) {
      if ((*(uint *)(iVar6 + 0x44) & 0x200000) == 0) {
        iVar16 = *(int *)(iVar5 + 4);
        LeaveCriticalSection((LPCRITICAL_SECTION)(iVar5 + 0x1c));
        uVar8 = *(uint *)(iVar6 + 0x44);
        memcpy(acStack_40,(void *)(iVar6 + 4),0x10);
        LeaveCriticalSection((LPCRITICAL_SECTION)(iVar6 + 0x5c));
        if ((uVar8 & 0x100000) != 0) {
          iVar15 = 0;
          EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c06bc620);
          if (DAT_c06bc684 != (int *)0x0) {
            piVar14 = local_80;
            piVar13 = DAT_c06bc684;
            do {
              if (0xf < iVar15) break;
              EnterCriticalSection((LPCRITICAL_SECTION)(piVar13 + 7));
              *piVar14 = piVar13[1];
              iVar15 = iVar15 + 1;
              piVar14 = piVar14 + 1;
              LeaveCriticalSection((LPCRITICAL_SECTION)(piVar13 + 7));
              piVar13 = (int *)*piVar13;
            } while (piVar13 != (int *)0x0);
          }
          LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c06bc620);
          iVar16 = local_80[0];
        }
        local_80[0] = iVar16;
        *(undefined2 *)(puVar2 + 5) = 0;
        *(undefined2 *)((int)puVar2 + 0x16) = 0x100;
        FUN_c06b3bdc(DAT_c06bc54c,0x400,acStack_40,0,0,local_80,iVar15);
        goto LAB_c06b7648;
      }
      LeaveCriticalSection((LPCRITICAL_SECTION)(iVar6 + 0x5c));
    }
    p_Var7 = (LPCRITICAL_SECTION)(iVar5 + 0x1c);
    if ((uVar1 & 0x1000) == 0) {
      uVar8 = *(uint *)(iVar5 + 4);
      LeaveCriticalSection(p_Var7);
      *(undefined2 *)(puVar2 + 5) = 0;
      FUN_c06b3bdc(DAT_c06bc54c,0x800,(char *)0x0,0,uVar8,(undefined4 *)0x0,0);
LAB_c06b7648:
      FUN_c06b42b8((int)DAT_c06bc54c);
      goto LAB_c06b766c;
    }
  }
  LeaveCriticalSection(p_Var7);
LAB_c06b766c:
  FUN_c06bac58(local_30);
  return;
}



/* c06b76a0 FUN_c06b76a0 */

/* Boundary evidence: original MIPS .pdata c06b76a0..c06b776f. Semantic name remains unreviewed. */

void FUN_c06b76a0(void)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 local_48;
  int local_44;
  int local_2c;
  
  do {
    while( true ) {
      puVar1 = &local_48;
      iVar2 = 2;
      do {
        *puVar1 = 0;
        puVar1[2] = 0x29;
        iVar2 = iVar2 + -1;
        puVar1 = puVar1 + 6;
      } while (iVar2 != 0);
      local_44 = DAT_c06bc5f4;
      local_2c = DAT_c06bc5d8;
      iVar2 = (**(code **)(DAT_c06bc600 + 0x28))(2,&local_48,0,0,0,0,0,0);
      if (iVar2 != 0) break;
      if (local_44 != 0) {
        FUN_c06b6c48();
      }
      if (local_2c != 0) {
        FUN_c06b7e74();
      }
    }
    GetLastError();
  } while( true );
}



/* c06b7770 FUN_c06b7770 */

/* Boundary evidence: original MIPS .pdata c06b7770..c06b77d7. Semantic name remains unreviewed. */

HLOCAL FUN_c06b7770(void)

{
  HLOCAL hMem;
  HANDLE pvVar1;
  
  hMem = LocalAlloc(0x40,0x28);
  if (hMem != (HLOCAL)0x0) {
    pvVar1 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
    *(HANDLE *)((int)hMem + 4) = pvVar1;
    if (pvVar1 == (HANDLE)0x0) {
      LocalFree(hMem);
      hMem = (HLOCAL)0x0;
    }
  }
  return hMem;
}



/* c06b77d8 FUN_c06b77d8 */

/* Boundary evidence: original MIPS .pdata c06b77d8..c06b792b. Semantic name remains unreviewed. */

int FUN_c06b77d8(int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 *hMem;
  int *piVar1;
  int iVar2;
  undefined1 auStack_58 [48];
  uint local_28;
  
  local_28 = DAT_c06bc0f4;
  hMem = FUN_c06b7770();
  if (hMem == (undefined4 *)0x0) {
    iVar2 = 3;
  }
  else {
    piVar1 = (int *)FUN_c06b1b00((uint)*(byte *)(param_1 + 0x30));
    if (piVar1 == (int *)0x0) {
      iVar2 = 0x14;
    }
    else {
      iVar2 = FUN_c06b538c((int)piVar1,(byte *)(param_1 + 0x20),0,1);
      if (iVar2 == 0) {
        FUN_c06b1de4(piVar1);
        iVar2 = 4;
      }
      else {
        FUN_c06b1de4(piVar1);
        hMem[4] = param_2;
        hMem[5] = param_3;
        hMem[6] = auStack_58;
        hMem[9] = param_1;
        *(undefined1 *)(hMem + 8) = *(undefined1 *)(param_1 + 0x30);
        *hMem = *(undefined4 *)(iVar2 + 0x58);
        *(undefined4 **)(iVar2 + 0x58) = hMem;
        LeaveCriticalSection((LPCRITICAL_SECTION)(iVar2 + 0x5c));
        WaitForSingleObject((HANDLE)hMem[1],0xffffffff);
        iVar2 = hMem[2];
        if (iVar2 == 0) {
          FUN_c06b3b78((byte *)(param_1 + 0x10),(int)auStack_58);
        }
        *(undefined4 *)(param_1 + 4) = hMem[7];
      }
    }
    CloseHandle((HANDLE)hMem[1]);
    LocalFree(hMem);
  }
  FUN_c06bac58(local_28);
  return iVar2;
}



/* c06b792c FUN_c06b792c */

/* Boundary evidence: original MIPS .pdata c06b792c..c06b7a73. Semantic name remains unreviewed. */

int FUN_c06b792c(int param_1,int param_2,int param_3)

{
  int *hMem;
  int *piVar1;
  int iVar2;
  undefined1 auStack_58 [48];
  uint local_28;
  
  local_28 = DAT_c06bc0f4;
  hMem = FUN_c06b7770();
  if (hMem == (int *)0x0) {
    iVar2 = 3;
  }
  else {
    piVar1 = (int *)FUN_c06b1b00((uint)*(byte *)(param_1 + 0x30));
    if (piVar1 == (int *)0x0) {
      iVar2 = 0x14;
    }
    else {
      iVar2 = FUN_c06b538c((int)piVar1,(byte *)(param_1 + 0x20),0,1);
      if (iVar2 == 0) {
        FUN_c06b1de4(piVar1);
        iVar2 = 4;
      }
      else {
        hMem[4] = param_2;
        hMem[5] = param_3;
        hMem[6] = (int)auStack_58;
        hMem[9] = param_1;
        *hMem = piVar1[6];
        piVar1[6] = (int)hMem;
        FUN_c06b1de4(piVar1);
        LeaveCriticalSection((LPCRITICAL_SECTION)(iVar2 + 0x5c));
        WaitForSingleObject((HANDLE)hMem[1],0xffffffff);
        iVar2 = hMem[2];
        if (iVar2 == 0) {
          FUN_c06b3b78((byte *)(param_1 + 0x10),(int)auStack_58);
        }
        *(int *)(param_1 + 4) = hMem[7];
      }
    }
    CloseHandle((HANDLE)hMem[1]);
    LocalFree(hMem);
  }
  FUN_c06bac58(local_28);
  return iVar2;
}



/* c06b7a74 FUN_c06b7a74 */

/* Boundary evidence: original MIPS .pdata c06b7a74..c06b7bcb. Semantic name remains unreviewed. */

undefined4 FUN_c06b7a74(int param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  int *piVar5;
  undefined4 uVar6;
  
  uVar6 = 2;
  piVar1 = (int *)FUN_c06b1b00((uint)*(byte *)(param_1 + 0x30));
  if (piVar1 == (int *)0x0) {
    uVar6 = 0x14;
  }
  else {
    iVar2 = FUN_c06b538c((int)piVar1,(byte *)(param_1 + 0x20),0,1);
    if (iVar2 == 0) {
      FUN_c06b1de4(piVar1);
      uVar6 = 4;
    }
    else {
      if (param_2 == 0x20) {
        FUN_c06b1de4(piVar1);
        piVar3 = (int *)(iVar2 + 0x58);
      }
      else {
        LeaveCriticalSection((LPCRITICAL_SECTION)(iVar2 + 0x5c));
        piVar3 = piVar1 + 6;
      }
      piVar4 = (int *)*piVar3;
      if (piVar4 != (int *)0x0) {
        piVar5 = piVar4;
        do {
          if ((char)piVar5[8] == (char)piVar1[0xe]) {
            piVar5[2] = 1;
            piVar5[7] = 0;
            *piVar3 = *piVar5;
            *piVar5 = 0;
            EventModify(piVar5[1],3);
            piVar4 = piVar5;
            break;
          }
          piVar4 = (int *)*piVar5;
          piVar3 = piVar5;
          piVar5 = piVar4;
        } while (piVar4 != (int *)0x0);
      }
      if (param_2 == 0x20) {
        LeaveCriticalSection((LPCRITICAL_SECTION)(iVar2 + 0x5c));
      }
      else {
        FUN_c06b1de4(piVar1);
      }
      if (piVar4 != (int *)0x0) {
        uVar6 = 0;
      }
    }
  }
  return uVar6;
}



/* c06b7bcc FUN_c06b7bcc */

/* Boundary evidence: original MIPS .pdata c06b7bcc..c06b7c7b. Semantic name remains unreviewed. */

void FUN_c06b7bcc(int param_1,int param_2,char *param_3)

{
  size_t _Size;
  size_t sVar1;
  
  sVar1 = *(size_t *)(param_1 + 0x14);
  memcpy(*(void **)(param_1 + 0x18),param_3,(int)*param_3);
  *(undefined4 *)(param_1 + 0x1c) = 0;
  for (; param_2 != 0; param_2 = *(int *)(param_2 + 4)) {
    _Size = *(size_t *)(param_2 + 0xc);
    if ((int)sVar1 < (int)*(size_t *)(param_2 + 0xc)) {
      *(undefined4 *)(param_1 + 8) = 0xe;
      _Size = sVar1;
    }
    if (0 < (int)_Size) {
      memcpy(*(void **)(param_1 + 0x10),(void *)(param_2 + 0x62),_Size);
      *(size_t *)(param_1 + 0x1c) = *(int *)(param_1 + 0x1c) + _Size;
      sVar1 = sVar1 - _Size;
    }
  }
  return;
}



/* c06b7c7c FUN_c06b7c7c */

/* Boundary evidence: original MIPS .pdata c06b7c7c..c06b7d6f. Semantic name remains unreviewed. */

int FUN_c06b7c7c(int param_1)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  
  iVar3 = 0;
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c06bc140);
  piVar2 = &DAT_c06bc548;
  if (DAT_c06bc548 != 0) {
    piVar1 = &DAT_c06bc548;
    do {
      piVar2 = (int *)*piVar1;
      if (((piVar2[5] == *(int *)(param_1 + 0x14)) &&
          ((short)piVar2[6] == *(short *)(param_1 + 0x18))) &&
         (*(short *)((int)piVar2 + 0x12) == *(short *)(param_1 + 0x12))) {
        if ((*(byte *)((int)piVar2 + 0x11) & 2) == 0) {
          *(int *)(param_1 + 4) = *piVar1;
          iVar3 = param_1;
        }
        else {
          iVar3 = *piVar1;
          *(int *)(iVar3 + 4) = param_1;
        }
        *piVar1 = *(int *)*piVar1;
        piVar2 = piVar1;
        if (iVar3 != 0) goto LAB_c06b7d4c;
        break;
      }
      piVar1 = piVar2;
    } while (*piVar2 != 0);
  }
  *(undefined4 *)(param_1 + 8) = 1;
  *piVar2 = param_1;
LAB_c06b7d4c:
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c06bc140);
  return iVar3;
}



/* c06b7d70 FUN_c06b7d70 */

undefined4 FUN_c06b7d70(byte *param_1,int param_2)

{
  byte bVar1;
  uint uVar2;
  
  if ((9 < param_2) && (bVar1 = *param_1, 0xf < bVar1)) {
    if (bVar1 < 0x13) {
      if (((((0x51 < param_2) &&
            (uVar2 = (*(ushort *)(param_1 + 10) & 0xff) << 8 |
                     (uint)(*(ushort *)(param_1 + 10) >> 8), 0x43 < uVar2)) &&
           ((int)uVar2 <= param_2 + -0xe)) &&
          ((((int)(char)param_1[0xe] & 0xc0U) == 0 && ((int)(char)param_1[0xe] == 0x20)))) &&
         ((((int)(char)param_1[0x30] & 0xc0U) == 0 && ((int)(char)param_1[0x30] == 0x20)))) {
        return 1;
      }
    }
    else if (bVar1 == 0x13) {
      if (10 < param_2) {
        return 1;
      }
    }
    else if (((0x13 < bVar1) && (bVar1 < 0x17)) && ((0x2b < param_2 && (param_1[10] == 0x20)))) {
      return 1;
    }
  }
  return 0;
}



/* c06b7e74 FUN_c06b7e74 */

/* Boundary evidence: original MIPS .pdata c06b7e74..c06b823f. Semantic name remains unreviewed. */

void FUN_c06b7e74(void)

{
  int iVar1;
  HLOCAL _Dst;
  undefined4 *hMem;
  int *piVar2;
  int iVar3;
  int *piVar4;
  undefined4 *puVar5;
  SIZE_T uBytes;
  int local_48;
  undefined4 local_44;
  undefined4 local_40 [2];
  undefined4 local_38;
  undefined1 *local_34;
  undefined1 auStack_30 [4];
  undefined4 local_2c;
  uint local_28;
  uint local_20;
  
  local_20 = DAT_c06bc0f4;
  local_34 = &DAT_c06bc170;
  local_44 = 0x10;
  local_38 = 0x3d8;
  local_40[0] = 0;
  iVar1 = (**(code **)(DAT_c06bc5dc + 0x1c))
                    (DAT_c06bc5d8,&local_38,1,&local_48,0,local_40,auStack_30,&local_44,0,0,0);
  if (((iVar1 != 0) || (local_48 < 10)) ||
     (iVar1 = FUN_c06b7d70(&DAT_c06bc170,local_48), iVar1 == 0)) goto LAB_c06b8218;
  if (DAT_c06bc170 < 0x13) {
    DAT_c06bc16c = (DAT_c06bc17a & 0xff) << 8 | (uint)(DAT_c06bc17a >> 8);
    if (((DAT_c06bc171 & 2) != 0) && ((DAT_c06bc171 & 1) == 0)) goto LAB_c06b7fe4;
    uBytes = ((DAT_c06bc17a & 0xff) << 8 | (uint)(DAT_c06bc17a >> 8)) + 0x1e;
    _Dst = LocalAlloc(0x40,uBytes);
    if (_Dst == (HLOCAL)0x0) goto LAB_c06b8218;
    memcpy(_Dst,&DAT_c06bc160,uBytes);
    *(uint *)((int)_Dst + 0xc) = DAT_c06bc16c;
    hMem = (undefined4 *)FUN_c06b7c7c((int)_Dst);
  }
  else {
LAB_c06b7fe4:
    hMem = (undefined4 *)&DAT_c06bc160;
  }
  if (hMem != (undefined4 *)0x0) {
    piVar4 = (int *)0x0;
    if (0xf < DAT_c06bc170) {
      if (DAT_c06bc170 < 0x12) {
        iVar1 = FUN_c06b1a70(local_28 & 0xffffff);
        if (iVar1 != 0) {
          iVar3 = FUN_c06b538c(iVar1,&DAT_c06bc1a0,0,2);
          if (iVar3 != 0) {
            while (*(int *)(iVar3 + 0x58) != 0) {
              piVar2 = *(int **)(iVar3 + 0x58);
              *(int *)(iVar3 + 0x58) = *piVar2;
              *piVar2 = (int)piVar4;
              piVar4 = piVar2;
            }
            LeaveCriticalSection((LPCRITICAL_SECTION)(iVar3 + 0x5c));
            hMem[3] = hMem[3] + -0x44;
            while (piVar4 != (int *)0x0) {
              FUN_c06b7bcc((int)piVar4,(int)hMem,&DAT_c06bc17e);
              puVar5 = piVar4 + 1;
              piVar4 = (int *)*piVar4;
              EventModify(*puVar5,3);
            }
            piVar4 = FUN_c06b5548(iVar1,&DAT_c06bc17e,2);
            if (piVar4 == (int *)0x0) {
              FUN_c06b5440(iVar1,&DAT_c06bc17e,0,local_2c,600,2);
            }
            else if (piVar4[0x12] < 600) {
              piVar4[0x12] = 600;
            }
          }
          LeaveCriticalSection((LPCRITICAL_SECTION)(iVar1 + 0x1c));
        }
      }
      else if ((DAT_c06bc170 == 0x12) && (iVar1 = FUN_c06b1a70(local_28 & 0xffffff), iVar1 != 0)) {
        while (*(int *)(iVar1 + 0x18) != 0) {
          piVar2 = *(int **)(iVar1 + 0x18);
          *(int *)(iVar1 + 0x18) = *piVar2;
          *piVar2 = (int)piVar4;
          piVar4 = piVar2;
        }
        piVar2 = FUN_c06b5548(iVar1,&DAT_c06bc17e,2);
        if (piVar2 == (int *)0x0) {
          FUN_c06b5440(iVar1,&DAT_c06bc17e,0,local_2c,600,2);
        }
        else if (piVar2[0x12] < 600) {
          piVar2[0x12] = 600;
        }
        LeaveCriticalSection((LPCRITICAL_SECTION)(iVar1 + 0x1c));
        hMem[3] = hMem[3] + -0x44;
        while (piVar4 != (int *)0x0) {
          FUN_c06b7bcc((int)piVar4,(int)hMem,&DAT_c06bc17e);
          piVar2 = piVar4 + 1;
          piVar4 = (int *)*piVar4;
          EventModify(*piVar2,3);
        }
      }
    }
    while ((hMem != (undefined4 *)&DAT_c06bc160 && (hMem != (undefined4 *)0x0))) {
      puVar5 = (undefined4 *)*hMem;
      LocalFree(hMem);
      hMem = puVar5;
    }
  }
LAB_c06b8218:
  FUN_c06bac58(local_20);
  return;
}



/* c06b8240 FUN_c06b8240 */

/* Boundary evidence: original MIPS .pdata c06b8240..c06b82ef. Semantic name remains unreviewed. */

undefined4 * FUN_c06b8240(undefined4 param_1)

{
  undefined4 *hMem;
  HANDLE pvVar1;
  
  hMem = LocalAlloc(0x40,0x4c);
  if (hMem != (undefined4 *)0x0) {
    pvVar1 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
    hMem[0xc] = pvVar1;
    if (pvVar1 == (HANDLE)0x0) {
      LocalFree(hMem);
      hMem = (undefined4 *)0x0;
    }
    else {
      InitializeCriticalSection((LPCRITICAL_SECTION)(hMem + 0xe));
      hMem[1] = param_1;
      EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c06bc120);
      *hMem = DAT_c06bc134;
      DAT_c06bc134 = hMem;
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c06bc120);
    }
  }
  return hMem;
}



/* c06b82f0 FUN_c06b82f0 */

/* Boundary evidence: original MIPS .pdata c06b82f0..c06b8397. Semantic name remains unreviewed. */

void FUN_c06b82f0(int *param_1)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c06bc120);
  piVar1 = &DAT_c06bc134;
  iVar3 = DAT_c06bc134;
  do {
    if (iVar3 == 0) {
LAB_c06b8358:
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c06bc120);
      CloseHandle((HANDLE)param_1[0xc]);
      DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xe));
      LocalFree(param_1);
      return;
    }
    piVar2 = (int *)*piVar1;
    if (piVar2 == param_1) {
      *piVar1 = *param_1;
      goto LAB_c06b8358;
    }
    iVar3 = *piVar2;
    piVar1 = piVar2;
  } while( true );
}



/* c06b8398 FUN_c06b8398 */

/* Boundary evidence: original MIPS .pdata c06b8398..c06b843b. Semantic name remains unreviewed. */

undefined4 FUN_c06b8398(int param_1)

{
  undefined4 uVar1;
  int *piVar2;
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c06bc120);
  piVar2 = (int *)DAT_c06bc134;
  do {
    if (piVar2 == (int *)0x0) {
LAB_c06b8410:
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c06bc120);
      uVar1 = 0;
      if (piVar2 == (int *)0x0) {
        uVar1 = 2;
      }
      return uVar1;
    }
    if (piVar2[1] == param_1) {
      EnterCriticalSection((LPCRITICAL_SECTION)(piVar2 + 0xe));
      piVar2[4] = piVar2[4] | 2;
      LeaveCriticalSection((LPCRITICAL_SECTION)(piVar2 + 0xe));
      goto LAB_c06b8410;
    }
    piVar2 = (int *)*piVar2;
  } while( true );
}



/* c06b843c FUN_c06b843c */

/* Boundary evidence: original MIPS .pdata c06b843c..c06b84a7. Semantic name remains unreviewed. */

undefined4 FUN_c06b843c(int param_1,int param_2,int *param_3)

{
  int *piVar1;
  undefined4 uVar2;
  
  uVar2 = 2;
  if ((param_2 == 0xc) &&
     (piVar1 = (int *)FUN_c06b1b00((uint)*(byte *)(param_1 + 0x30)), piVar1 != (int *)0x0)) {
    param_3[2] = piVar1[3];
    *param_3 = piVar1[1];
    param_3[1] = piVar1[2];
    FUN_c06b1de4(piVar1);
    uVar2 = 0;
  }
  return uVar2;
}



/* c06b84a8 FUN_c06b84a8 */

/* Boundary evidence: original MIPS .pdata c06b84a8..c06b85ff. Semantic name remains unreviewed. */

undefined4 FUN_c06b84a8(void)

{
  int iVar1;
  HANDLE hObject;
  undefined4 uVar2;
  DWORD aDStack_38 [2];
  undefined2 local_30;
  undefined2 local_2e;
  undefined4 local_2c;
  uint local_20;
  
  local_20 = DAT_c06bc0f4;
  uVar2 = 0;
  if (DAT_c06bc108 != 0) goto LAB_c06b85d4;
  DAT_c06bc108 = 1;
  memset(&local_30,0,0x10);
  local_2e = 0x8b00;
  local_30 = 2;
  local_2c = 0;
  DAT_c06bc5fc = (**(code **)(DAT_c06bc600 + 8))(0x80000002,1,0,0,0);
  if ((DAT_c06bc5fc != 0) &&
     (iVar1 = (**(code **)(DAT_c06bc5dc + 0xc))(DAT_c06bc5fc,&local_30,0x10), iVar1 != -1)) {
    iVar1 = (**(code **)(DAT_c06bc5dc + 0x18))(DAT_c06bc5fc,3);
    if (iVar1 == -1) {
      uVar2 = 0;
      goto LAB_c06b85d4;
    }
    hObject = CreateThread((LPSECURITY_ATTRIBUTES)0x0,0,FUN_c06ba5b4,(LPVOID)0x0,0,aDStack_38);
    if (hObject != (HANDLE)0x0) {
      CloseHandle(hObject);
      goto LAB_c06b85d4;
    }
  }
  uVar2 = 2;
LAB_c06b85d4:
  FUN_c06bac58(local_20);
  return uVar2;
}



/* c06b8600 FUN_c06b8600 */

/* Boundary evidence: original MIPS .pdata c06b8600..c06b8793. Semantic name remains unreviewed. */

int FUN_c06b8600(int param_1)

{
  ushort uVar1;
  int iVar2;
  undefined4 *puVar3;
  int *piVar4;
  int iVar5;
  
  iVar2 = FUN_c06b84a8();
  if (iVar2 == 0) {
    puVar3 = FUN_c06b467c();
    if (puVar3 == (undefined4 *)0x0) {
      iVar2 = 3;
    }
    else {
      *(undefined1 *)(puVar3 + 0x15) = *(undefined1 *)(param_1 + 0x30);
      uVar1 = *(ushort *)(puVar3 + 1);
      puVar3[8] = *(undefined4 *)(param_1 + 0x20);
      puVar3[9] = *(undefined4 *)(param_1 + 0x24);
      puVar3[10] = *(undefined4 *)(param_1 + 0x28);
      puVar3[0xb] = *(undefined4 *)(param_1 + 0x2c);
      puVar3[0xc] = *(undefined4 *)(param_1 + 0x10);
      puVar3[0xd] = *(undefined4 *)(param_1 + 0x14);
      puVar3[0xe] = *(undefined4 *)(param_1 + 0x18);
      puVar3[0xf] = *(undefined4 *)(param_1 + 0x1c);
      piVar4 = (int *)FUN_c06b1b00((uint)*(byte *)(param_1 + 0x30));
      if (piVar4 == (int *)0x0) {
        FUN_c06b475c(puVar3);
        iVar2 = 0x14;
      }
      else {
        iVar2 = FUN_c06b538c((int)piVar4,(byte *)(param_1 + 0x20),0,1);
        if (iVar2 == 0) {
          FUN_c06b1de4(piVar4);
          FUN_c06b475c(puVar3);
          iVar2 = 4;
        }
        else {
          *puVar3 = *(undefined4 *)(iVar2 + 0x54);
          *(undefined4 **)(iVar2 + 0x54) = puVar3;
          FUN_c06b1de4(piVar4);
          LeaveCriticalSection((LPCRITICAL_SECTION)(iVar2 + 0x5c));
          WaitForSingleObject((HANDLE)puVar3[3],0xffffffff);
          iVar5 = FUN_c06b4b60((uint)uVar1,(uint)*(byte *)(param_1 + 0x30));
          if (iVar5 == 0) {
            iVar2 = 2;
          }
          else {
            if (*(int *)(iVar5 + 0x18) == 8) {
              iVar2 = 0x14;
            }
            else {
              iVar2 = 0;
              *(undefined4 *)(param_1 + 0xc) = *(undefined4 *)(iVar5 + 4);
            }
            LeaveCriticalSection((LPCRITICAL_SECTION)(iVar5 + 0x40));
          }
        }
      }
    }
  }
  return iVar2;
}



/* c06b8794 FUN_c06b8794 */

/* Boundary evidence: original MIPS .pdata c06b8794..c06b8a23. Semantic name remains unreviewed. */

int FUN_c06b8794(undefined4 param_1,char *param_2,undefined4 param_3,undefined4 *param_4,
                uint *param_5,void *param_6,void *param_7,int *param_8,undefined2 *param_9)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  int *_Src;
  
  iVar2 = FUN_c06b9a14(0,param_1,(int)param_2,4,(int *)0x0);
  if (iVar2 == 0) {
    cVar1 = *param_2;
    _Src = (int *)(param_2 + 4);
    if (cVar1 == '\0') {
      *param_4 = 0x10;
      uVar3 = (*(ushort *)(param_2 + 2) & 0xff) << 8 | (uint)(*(ushort *)(param_2 + 2) >> 8);
      *param_5 = uVar3;
      if ((param_2[1] & 1U) != 0) {
        *param_5 = uVar3 | 0x10000;
      }
    }
    else if (cVar1 == -0x7f) {
      *param_4 = 1;
      *param_5 = (*(ushort *)(param_2 + 2) & 0xff) << 8 | (uint)(*(ushort *)(param_2 + 2) >> 8);
      iVar2 = FUN_c06b9a14(0,param_1,(int)_Src,0x44,(int *)0x0);
      if (iVar2 == 0) {
        if (param_6 != (void *)0x0) {
          memcpy(param_6,_Src,0x22);
        }
        if (param_7 != (void *)0x0) {
          memcpy(param_7,param_2 + 0x26,0x22);
        }
      }
    }
    else if (cVar1 == -0x7e) {
      *param_4 = 2;
    }
    else if (cVar1 == -0x7d) {
      *param_4 = 4;
      *param_5 = (*(ushort *)(param_2 + 2) & 0xff) << 8 | (uint)(*(ushort *)(param_2 + 2) >> 8);
      iVar2 = FUN_c06b9a14(0,param_1,(int)_Src,1,(int *)0x0);
      if (iVar2 == 0) {
        *param_8 = (int)(char)*_Src;
      }
    }
    else if (cVar1 == -0x7c) {
      *param_4 = 8;
      *param_5 = (*(ushort *)(param_2 + 2) & 0xff) << 8 | (uint)(*(ushort *)(param_2 + 2) >> 8);
      iVar2 = FUN_c06b9a14(0,param_1,(int)_Src,6,(int *)0x0);
      if (iVar2 == 0) {
        *param_8 = *_Src;
        *param_9 = *(undefined2 *)(param_2 + 8);
      }
    }
    else if (cVar1 == -0x7b) {
      *param_4 = 0x20;
      *param_5 = (*(ushort *)(param_2 + 2) & 0xff) << 8 | (uint)(*(ushort *)(param_2 + 2) >> 8);
    }
    else {
      iVar2 = 2;
    }
  }
  return iVar2;
}



/* c06b8a24 FUN_c06b8a24 */

/* Boundary evidence: original MIPS .pdata c06b8a24..c06b8c23. Semantic name remains unreviewed. */

int FUN_c06b8a24(undefined4 param_1,byte *param_2,undefined1 *param_3,uint *param_4,int *param_5,
                undefined2 *param_6,byte param_7)

{
  char *hMem;
  int *piVar1;
  int *piVar2;
  uint uVar3;
  int iVar4;
  undefined4 local_38;
  uint uStack_34;
  undefined4 local_30;
  char *local_2c;
  
  local_38 = 0x48;
  hMem = LocalAlloc(0,0x48);
  if (hMem == (char *)0x0) {
    iVar4 = 3;
  }
  else {
    FUN_c06ba908(hMem,&local_38,1,(int)param_2,param_3,0);
    local_30 = local_38;
    local_2c = hMem;
    iVar4 = (**(code **)(DAT_c06bc5dc + 0x20))(param_1,&local_30,1,&uStack_34,0,0,0,0,0,0);
    if (iVar4 == 0) {
      do {
        iVar4 = FUN_c06b8794(param_1,hMem,local_38,param_4,&uStack_34,(void *)0x0,(void *)0x0,
                             param_5,param_6);
        if (iVar4 != 0) goto LAB_c06b8bec;
        uVar3 = *param_4;
      } while (uVar3 == 0x20);
      if (((uVar3 & 0x11) == 0) && ((uVar3 & 2) != 0)) {
        piVar1 = (int *)FUN_c06b1b00((uint)param_7);
        if (piVar1 == (int *)0x0) {
          iVar4 = 0x14;
        }
        else {
          piVar2 = FUN_c06b5548((int)piVar1,param_2,2);
          if (piVar2 == (int *)0x0) {
            FUN_c06b5440((int)piVar1,param_2,0,*param_5,600,1);
          }
          else if ((piVar2[0x13] == *param_5) && (piVar2[0x12] < 600)) {
            piVar2[0x12] = 600;
          }
          FUN_c06b1de4(piVar1);
        }
      }
    }
LAB_c06b8bec:
    LocalFree(hMem);
  }
  return iVar4;
}



/* c06b8c24 FUN_c06b8c24 */

/* Boundary evidence: original MIPS .pdata c06b8c24..c06b8cb7. Semantic name remains unreviewed. */

undefined4 FUN_c06b8c24(int param_1)

{
  int *piVar1;
  undefined4 uVar2;
  
  piVar1 = FUN_c06b4c2c((uint)*(ushort *)(param_1 + 0xc));
  if (piVar1 == (int *)0x0) {
    uVar2 = 10;
  }
  else {
    if (piVar1[2] != 0) {
      piVar1[2] = 0;
      (*(code *)*DAT_c06bc5dc)();
    }
    EventModify(piVar1[4],3);
    EventModify(piVar1[3],3);
    LeaveCriticalSection((LPCRITICAL_SECTION)(piVar1 + 0x10));
    FUN_c06b475c(piVar1);
    uVar2 = 0;
  }
  return uVar2;
}



/* c06b8cb8 FUN_c06b8cb8 */

/* Boundary evidence: original MIPS .pdata c06b8cb8..c06b90cf. Semantic name remains unreviewed. */

DWORD FUN_c06b8cb8(int param_1)

{
  bool bVar1;
  bool bVar2;
  DWORD DVar3;
  undefined4 *puVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int *local_50;
  undefined2 local_4c [2];
  int local_48;
  uint local_44;
  undefined2 local_40;
  undefined2 local_3e;
  int local_3c;
  uint local_30;
  
  local_30 = DAT_c06bc0f4;
  local_50 = (int *)0x0;
  iVar6 = 0;
  DVar3 = FUN_c06b617c(param_1,(int *)&local_50,(uint *)0x0);
  if (DVar3 == 0) {
    iVar8 = *local_50;
    iVar7 = 0;
    bVar1 = false;
    bVar2 = false;
    iVar9 = 0;
    if (0 < DAT_c06bc604) {
      do {
        if (iVar8 <= iVar7) {
          iVar7 = 0;
        }
        if (bVar2) {
          if (local_50 != (int *)0x0) {
            LocalFree(local_50);
            local_50 = (int *)0x0;
          }
          DVar3 = FUN_c06b617c(param_1,(int *)&local_50,(uint *)0x0);
          if (DVar3 != 0) goto LAB_c06b8fec;
          bVar2 = false;
          iVar8 = *local_50;
          iVar7 = 0;
        }
        iVar5 = local_50[iVar7 + 1];
        local_4c[0] = 0x8b00;
        local_48 = iVar5;
        memset(&local_40,0,0x10);
        local_40 = 2;
        local_3e = 0x8b00;
        local_3c = iVar5;
        if ((iVar6 == 0) &&
           (iVar6 = (**(code **)(DAT_c06bc600 + 8))(0x80000002,1,0,0,0), iVar6 == 0)) {
          DVar3 = GetLastError();
          goto LAB_c06b8fec;
        }
        DVar3 = (*(code *)DAT_c06bc5dc[4])(iVar6,&local_40,0x10);
        if (DVar3 == 0x274d) {
          if (bVar1) {
LAB_c06b8e3c:
            bVar1 = false;
          }
          else {
LAB_c06b8e44:
            Sleep(1000);
          }
        }
        else if (DVar3 == 0x274c) {
          if (bVar1) goto LAB_c06b8e3c;
          if (iVar8 == 1) {
            bVar2 = true;
          }
        }
        else {
          if (DVar3 != 0) goto LAB_c06b8e44;
          DVar3 = FUN_c06b8a24(iVar6,(byte *)(param_1 + 0x10),(undefined1 *)(param_1 + 0x20),
                               &local_44,&local_48,local_4c,*(byte *)(param_1 + 0x30));
          if (local_44 == 2) {
            DVar3 = 0;
            goto LAB_c06b8fec;
          }
          if (local_44 == 4) {
            if (((local_48 != 0x80) && (local_48 != 0x81)) && (local_48 == 0x82)) {
              bVar1 = false;
              if (iVar8 == 1) {
                bVar2 = true;
              }
              else {
                (*(code *)*DAT_c06bc5dc)(iVar6);
                iVar6 = 0;
              }
            }
            DVar3 = 2;
          }
          else if (local_44 == 8) {
            (*(code *)*DAT_c06bc5dc)(iVar6);
            bVar1 = true;
            iVar6 = 0;
            DVar3 = 2;
            goto LAB_c06b8e84;
          }
          (*(code *)*DAT_c06bc5dc)(iVar6);
          iVar6 = 0;
        }
LAB_c06b8e84:
        iVar9 = iVar9 + 1;
        iVar7 = iVar7 + 1;
      } while (iVar9 < DAT_c06bc604);
      if ((DVar3 != 0) && (iVar6 != 0)) {
        (*(code *)*DAT_c06bc5dc)(iVar6);
        iVar6 = 0;
      }
    }
  }
LAB_c06b8fec:
  if (local_50 != (int *)0x0) {
    LocalFree(local_50);
  }
  if (DVar3 == 0) {
    puVar4 = FUN_c06b467c();
    if (puVar4 == (undefined4 *)0x0) {
      DVar3 = 3;
    }
    else {
      puVar4[2] = iVar6;
      *(undefined1 *)(puVar4 + 0x15) = *(undefined1 *)(param_1 + 0x30);
      puVar4[8] = *(undefined4 *)(param_1 + 0x20);
      puVar4[9] = *(undefined4 *)(param_1 + 0x24);
      puVar4[10] = *(undefined4 *)(param_1 + 0x28);
      puVar4[0xb] = *(undefined4 *)(param_1 + 0x2c);
      puVar4[0xc] = *(undefined4 *)(param_1 + 0x10);
      puVar4[0xd] = *(undefined4 *)(param_1 + 0x14);
      puVar4[0xe] = *(undefined4 *)(param_1 + 0x18);
      puVar4[0xf] = *(undefined4 *)(param_1 + 0x1c);
      *(undefined4 *)(param_1 + 0xc) = puVar4[1];
      FUN_c06b4bdc(puVar4);
      FUN_c06b9da8((byte *)(param_1 + 0x20),(uint)*(byte *)(puVar4 + 0x15));
    }
  }
  FUN_c06bac58(local_30);
  return DVar3;
}



/* c06b90d0 FUN_c06b90d0 */

/* Boundary evidence: original MIPS .pdata c06b90d0..c06b916b. Semantic name remains unreviewed. */

void FUN_c06b90d0(undefined1 *param_1,int param_2,int param_3,int param_4,int param_5,
                 undefined4 param_6,undefined1 param_7)

{
  param_1[1] = 10;
  *param_1 = (char)param_2;
  *(ushort *)(param_1 + 2) = (ushort)(param_3 << 8) | (ushort)((uint)param_3 >> 8);
  *(undefined4 *)(param_1 + 4) = param_6;
  *(undefined2 *)(param_1 + 8) = 0x8a00;
  if (0xf < param_2) {
    if (param_2 < 0x13) {
      *(undefined2 *)(param_1 + 0xc) = 0;
      FUN_c06b3b20(param_1 + 0xe,param_4);
      FUN_c06b3b20(param_1 + 0x30,param_5);
    }
    else if (param_2 == 0x13) {
      param_1[0xb] = param_7;
    }
  }
  return;
}



/* c06b916c FUN_c06b916c */

/* Boundary evidence: original MIPS .pdata c06b916c..c06b9487. Semantic name remains unreviewed. */

int FUN_c06b916c(int param_1,void *param_2,size_t param_3)

{
  bool bVar1;
  uint uVar2;
  int iVar3;
  undefined1 *hMem;
  undefined2 extraout_var;
  uint uVar4;
  uint uVar5;
  int iVar6;
  size_t _Size;
  int iVar7;
  int local_68;
  uint *local_64;
  ushort local_60;
  undefined2 local_5e;
  void *local_5c;
  int local_58;
  undefined1 *local_54;
  uint local_50;
  uint local_4c;
  int local_48;
  int local_44;
  undefined2 local_40;
  undefined2 local_3e;
  undefined4 local_3c;
  uint local_30;
  
  local_30 = DAT_c06bc0f4;
  local_5c = param_2;
  iVar3 = FUN_c06b617c(param_1,(int *)&local_64,&local_50);
  if (iVar3 == 0) {
    uVar5 = *local_64;
    bVar1 = (uVar5 & 0x80000000) != 0;
    iVar6 = 1;
    if (bVar1) {
      uVar5 = uVar5 & 0x7fffffff;
    }
    hMem = LocalAlloc(0x40,1000);
    if (hMem == (undefined1 *)0x0) {
      iVar3 = 3;
    }
    else {
      local_60 = FUN_c06b4618();
      uVar4 = CONCAT22(extraout_var,local_60);
      iVar3 = 0;
      if (0 < (int)uVar5) {
        local_48 = param_1 + 0x10;
        local_44 = param_1 + 0x20;
        local_4c = (uint)(0x240 < (int)(param_3 + 0x6e));
        iVar7 = 4;
        while( true ) {
          uVar2 = local_4c;
          FUN_c06b90d0(hMem,bVar1 + 0x10,uVar4,local_44,local_48,local_50,0);
          _Size = 0x1d2;
          if (uVar2 == 0) {
            _Size = param_3;
          }
          uVar4 = _Size + 0x44 & 0xffff;
          local_5e = (undefined2)(_Size + 0x44);
          *(ushort *)(hMem + 10) = (ushort)(uVar4 << 8) | (ushort)(uVar4 >> 8);
          memcpy(hMem + 0x52,local_5c,_Size);
          local_40 = 2;
          local_3e = 0x8a00;
          local_3c = *(undefined4 *)(iVar7 + (int)local_64);
          local_58 = _Size + 0x52;
          local_54 = hMem;
          iVar3 = (**(code **)(DAT_c06bc5dc + 0x20))
                            (DAT_c06bc5d8,&local_58,1,&local_68,0,&local_40,0x10,0,0,0);
          if (iVar3 != 0) goto LAB_c06b9430;
          if (local_68 < (int)(_Size + 0x52)) break;
          if ((int)_Size < (int)param_3) {
            uVar4 = param_3 - _Size & 0xffff;
            *(undefined2 *)(hMem + 0xc) = local_5e;
            hMem[1] = 9;
            *(ushort *)(hMem + 10) = (ushort)(uVar4 << 8) | (ushort)(uVar4 >> 8);
            memcpy(hMem + 0xe,(void *)((int)local_5c + _Size),param_3 - _Size);
            local_58 = param_3 - _Size;
            local_54 = hMem;
            iVar3 = (**(code **)(DAT_c06bc5dc + 0x20))
                              (DAT_c06bc5d8,&local_58,1,&local_68,0,&local_40,0x10,0,0,0);
            if (iVar3 != 0) goto LAB_c06b9430;
            if (local_68 < (int)(param_3 - _Size)) break;
          }
          iVar6 = iVar6 + 1;
          iVar7 = iVar7 + 4;
          if ((int)uVar5 < iVar6) goto LAB_c06b9430;
          uVar4 = (uint)local_60;
        }
        iVar3 = 2;
      }
LAB_c06b9430:
      LocalFree(hMem);
    }
    LocalFree(local_64);
  }
  else {
    iVar3 = 4;
  }
  FUN_c06bac58(local_30);
  return iVar3;
}



/* c06b9488 FUN_c06b9488 */

/* Boundary evidence: original MIPS .pdata c06b9488..c06b970b. Semantic name remains unreviewed. */

int FUN_c06b9488(int param_1,void *param_2,size_t param_3)

{
  short sVar1;
  undefined1 *hMem;
  int *piVar2;
  undefined2 extraout_var;
  int iVar3;
  size_t _Size;
  int iVar4;
  uint uVar5;
  int local_50 [2];
  uint local_48;
  undefined1 *local_44;
  undefined2 local_40;
  undefined2 local_3e;
  int local_3c;
  uint local_30;
  
  local_30 = DAT_c06bc0f4;
  hMem = LocalAlloc(0x40,1000);
  if (hMem == (undefined1 *)0x0) {
    iVar3 = 3;
  }
  else {
    piVar2 = (int *)FUN_c06b1b00((uint)*(byte *)(param_1 + 0x30));
    if (piVar2 == (int *)0x0) {
      LocalFree(hMem);
      iVar3 = 0x14;
    }
    else {
      iVar3 = piVar2[1];
      iVar4 = piVar2[3];
      FUN_c06b1de4(piVar2);
      sVar1 = FUN_c06b4618();
      FUN_c06b90d0(hMem,0x12,CONCAT22(extraout_var,sVar1),param_1 + 0x20,-0x3f943f1c,iVar3,0);
      _Size = 0x1d2;
      if ((int)(param_3 + 0x6e) < 0x241) {
        _Size = param_3;
      }
      uVar5 = _Size + 0x44 & 0xffff;
      *(ushort *)(hMem + 10) = (ushort)(uVar5 << 8) | (ushort)(uVar5 >> 8);
      memcpy(hMem + 0x52,param_2,_Size);
      local_3e = 0x8a00;
      local_40 = 2;
      local_48 = _Size + 0x52;
      local_44 = hMem;
      local_3c = iVar4;
      iVar3 = (**(code **)(DAT_c06bc5dc + 0x20))
                        (DAT_c06bc5d8,&local_48,1,local_50,0,&local_40,0x10,0,0,0);
      if ((local_50[0] < (int)(_Size + 0x52)) && (iVar3 == 0)) {
        iVar3 = 2;
      }
      if (((int)_Size < (int)param_3) && (iVar3 == 0)) {
        uVar5 = param_3 - _Size;
        hMem[1] = 9;
        *(short *)(hMem + 0xc) = (short)(_Size + 0x44);
        *(ushort *)(hMem + 10) = (ushort)((uVar5 & 0xffff) << 8) | (ushort)((uVar5 & 0xffff) >> 8);
        memcpy(hMem + 0xe,(void *)((int)param_2 + _Size),uVar5);
        local_48 = uVar5;
        local_44 = hMem;
        iVar3 = (**(code **)(DAT_c06bc5dc + 0x20))
                          (DAT_c06bc5d8,&local_48,1,local_50,0,&local_40,0x10,0,0,0);
        if ((iVar3 == 0) && (local_50[0] < (int)uVar5)) {
          iVar3 = 2;
        }
      }
      LocalFree(hMem);
    }
  }
  FUN_c06bac58(local_30);
  return iVar3;
}



/* c06b970c FUN_c06b970c */

/* Boundary evidence: original MIPS .pdata c06b970c..c06b97bf. Semantic name remains unreviewed. */

undefined4 FUN_c06b970c(int param_1,undefined1 *param_2,int param_3)

{
  undefined4 uVar1;
  undefined4 local_20 [2];
  int local_18;
  undefined1 *local_14;
  
  if (*(int *)(param_1 + 8) == 0) {
    uVar1 = 0xb;
  }
  else {
    FUN_c06ba908(param_2,local_20,0x10,0,(undefined1 *)0x0,(ushort)param_3);
    local_18 = param_3 + 4;
    local_20[0] = 4;
    local_14 = param_2;
    uVar1 = (**(code **)(DAT_c06bc5dc + 0x20))
                      (*(undefined4 *)(param_1 + 8),&local_18,1,local_20,0,0,0,0,0,0);
  }
  return uVar1;
}



/* c06b97c0 FUN_c06b97c0 */

/* Boundary evidence: original MIPS .pdata c06b97c0..c06b9a07. Semantic name remains unreviewed. */

undefined4 FUN_c06b97c0(int param_1,void *param_2,uint param_3,void *param_4,size_t param_5)

{
  undefined1 *hMem;
  SIZE_T uBytes;
  SIZE_T SVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  
  iVar2 = -0x7ff8fdea;
  uVar5 = param_3 + param_5;
  SVar1 = 0xffffffff;
  iVar3 = iVar2;
  if (param_3 <= uVar5) {
    iVar3 = 0;
    SVar1 = uVar5;
  }
  if (iVar3 < 0) {
    return 3;
  }
  uBytes = 0xffffffff;
  if (SVar1 <= SVar1 + 4) {
    iVar2 = 0;
    uBytes = SVar1 + 4;
  }
  if (iVar2 < 0) {
    return 3;
  }
  hMem = LocalAlloc(0x40,uBytes);
  if (hMem == (undefined1 *)0x0) {
    return 3;
  }
  iVar3 = FUN_c06b4b60((uint)*(ushort *)(param_1 + 0xc),(uint)*(byte *)(param_1 + 0x30));
  if (iVar3 != 0) {
    *(int *)(iVar3 + 0x14) = *(int *)(iVar3 + 0x14) + 1;
    LeaveCriticalSection((LPCRITICAL_SECTION)(iVar3 + 0x40));
    WaitForSingleObject(*(HANDLE *)(iVar3 + 0x10),0xffffffff);
    iVar3 = FUN_c06b4b60((uint)*(ushort *)(param_1 + 0xc),(uint)*(byte *)(param_1 + 0x30));
    if (iVar3 != 0) {
      *(int *)(iVar3 + 0x14) = *(int *)(iVar3 + 0x14) + -1;
      if (*(int *)(iVar3 + 0x18) == 8) {
        uVar4 = 0x14;
      }
      else {
        memcpy(hMem + 4,param_2,param_3);
        if ((param_5 != 0) && (param_4 != (void *)0x0)) {
          memcpy(hMem + param_3 + 4,param_4,param_5);
        }
        uVar4 = FUN_c06b970c(iVar3,hMem,uVar5);
        EventModify(*(undefined4 *)(iVar3 + 0x10),3);
      }
      LeaveCriticalSection((LPCRITICAL_SECTION)(iVar3 + 0x40));
      goto LAB_c06b99b4;
    }
  }
  uVar4 = 10;
LAB_c06b99b4:
  LocalFree(hMem);
  return uVar4;
}



/* c06b9a08 FUN_c06b9a08 */

/* Boundary evidence: original MIPS .pdata c06b9a08..c06b9a13. Semantic name remains unreviewed. */

undefined4 FUN_c06b9a08(void)

{
  return 1;
}



/* c06b9a14 FUN_c06b9a14 */

/* Boundary evidence: original MIPS .pdata c06b9a14..c06b9b83. Semantic name remains unreviewed. */

int FUN_c06b9a14(int param_1,undefined4 param_2,int param_3,int param_4,int *param_5)

{
  ushort uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  undefined4 local_38;
  int local_34;
  int local_30;
  int local_2c;
  
  if (param_1 == 0) {
    uVar1 = (ushort)local_38;
  }
  else {
    local_38._0_1_ = *(byte *)(param_1 + 0x54);
    uVar1 = *(ushort *)(param_1 + 4);
  }
  uVar5 = (uint)(byte)local_38;
  iVar4 = 0;
  do {
    if ((param_1 != 0) && (*(int *)(param_1 + 8) == 0)) {
      iVar2 = 0xb;
      break;
    }
    local_30 = param_4 - iVar4;
    local_38 = 0;
    local_2c = param_3;
    if (param_1 != 0) {
      LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x40));
    }
    iVar2 = (**(code **)(DAT_c06bc5dc + 0x1c))(param_2,&local_30,1,&local_34,0,&local_38,0,0,0,0,0);
    if ((param_1 != 0) && (iVar3 = FUN_c06b4b60((uint)uVar1,uVar5), param_1 != iVar3)) {
      iVar2 = 10;
      break;
    }
    if (iVar2 != 0) break;
    if (local_34 == 0) {
      iVar2 = 0x274a;
      break;
    }
    iVar4 = local_34 + iVar4;
    param_3 = local_34 + param_3;
  } while (iVar4 < param_4);
  if (param_5 != (int *)0x0) {
    *param_5 = iVar4;
  }
  return iVar2;
}



/* c06b9b84 FUN_c06b9b84 */

/* Boundary evidence: original MIPS .pdata c06b9b84..c06b9da7. Semantic name remains unreviewed. */

int FUN_c06b9b84(int param_1,int param_2,uint param_3,uint *param_4)

{
  bool bVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  byte local_70;
  byte local_6f;
  undefined2 local_6e;
  undefined1 auStack_6c [68];
  uint local_28;
  
  local_28 = DAT_c06bc0f4;
  uVar4 = *(undefined4 *)(param_1 + 8);
  bVar1 = true;
  do {
    uVar3 = *(uint *)(param_1 + 0x1c);
    if (uVar3 == 0) {
      iVar2 = FUN_c06b9a14(param_1,uVar4,(int)&local_70,4,(int *)0x0);
      if (iVar2 == 0) {
        if (local_70 == 0) {
          uVar3 = (local_6e & 0xff) << 8 | (uint)local_6e._1_1_;
          *param_4 = uVar3;
          if ((local_6f & 1) != 0) {
            *param_4 = uVar3 | 0x10000;
          }
          uVar3 = *param_4;
          if ((int)param_3 < (int)uVar3) {
            *(uint *)(param_1 + 0x1c) = uVar3 - param_3;
            uVar3 = param_3;
          }
          goto LAB_c06b9d60;
        }
        if (0x80 < local_70) {
          if (local_70 < 0x85) {
            uVar3 = (local_6e & 0xff) << 8 | (uint)local_6e._1_1_;
            *param_4 = uVar3;
            if (uVar3 != 0) {
              iVar2 = FUN_c06b9a14(param_1,uVar4,(int)auStack_6c,uVar3,(int *)0x0);
            }
            *param_4 = 0;
            goto LAB_c06b9d80;
          }
          if (local_70 == 0x85) {
            *param_4 = (local_6e & 0xff) << 8 | (uint)local_6e._1_1_;
            iVar2 = 0x10;
            goto LAB_c06b9c80;
          }
        }
      }
      else {
        bVar1 = false;
      }
    }
    else {
      if ((int)uVar3 < (int)param_3) {
        param_3 = uVar3;
      }
      *param_4 = uVar3;
      *(uint *)(param_1 + 0x1c) = *(int *)(param_1 + 0x1c) - param_3;
      uVar3 = param_3;
LAB_c06b9d60:
      iVar2 = FUN_c06b9a14(param_1,uVar4,param_2,uVar3,(int *)0x0);
      bVar1 = false;
      param_3 = uVar3;
LAB_c06b9d80:
      if (iVar2 == 10) goto LAB_c06b9c80;
    }
    if (!bVar1) {
LAB_c06b9c80:
      FUN_c06bac58(local_28);
      return iVar2;
    }
  } while( true );
}



/* c06b9da8 FUN_c06b9da8 */

/* Boundary evidence: original MIPS .pdata c06b9da8..c06b9e7b. Semantic name remains unreviewed. */

void FUN_c06b9da8(byte *param_1,uint param_2)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = (int *)FUN_c06b1b00(param_2);
  if (piVar1 != (int *)0x0) {
    iVar2 = FUN_c06b538c((int)piVar1,param_1,0,1);
    if (iVar2 == 0) {
      FUN_c06b1de4(piVar1);
    }
    else {
      FUN_c06b1de4(piVar1);
      if ((*(uint *)(iVar2 + 0x44) & 0x10000) != 0) {
        if ((*(uint *)(iVar2 + 0x44) & 0x20000) == 0) {
          FUN_c06b49f8(param_1,param_2);
        }
        else {
          EventModify(*(undefined4 *)(iVar2 + 0x50),3);
        }
      }
      LeaveCriticalSection((LPCRITICAL_SECTION)(iVar2 + 0x5c));
    }
  }
  return;
}



/* c06b9e7c FUN_c06b9e7c */

/* Boundary evidence: original MIPS .pdata c06b9e7c..c06b9fa3. Semantic name remains unreviewed. */

int FUN_c06b9e7c(int param_1,int param_2,uint param_3)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  uint local_20 [2];
  
  iVar1 = FUN_c06b4b60((uint)*(ushort *)(param_1 + 0xc),(uint)*(byte *)(param_1 + 0x30));
  if (iVar1 == 0) {
    return 10;
  }
  uVar2 = *(uint *)(iVar1 + 0x18);
  if ((uVar2 & 1) != 0) {
    iVar3 = 0xd;
    goto LAB_c06b9f70;
  }
  *(uint *)(iVar1 + 0x18) = uVar2 | 1;
  if ((uVar2 & 2) != 0) {
    FUN_c06b9da8((byte *)(iVar1 + 0x20),(uint)*(byte *)(param_1 + 0x30));
    *(uint *)(iVar1 + 0x18) = *(uint *)(iVar1 + 0x18) & 0xfffffffd;
  }
  iVar3 = FUN_c06b9b84(iVar1,param_2,param_3,local_20);
  if (iVar3 == 0) {
    if ((int)local_20[0] <= (int)param_3) {
      *(uint *)(param_1 + 4) = local_20[0];
      goto LAB_c06b9f40;
    }
    iVar3 = 0xe;
    *(uint *)(param_1 + 4) = param_3;
  }
  else {
LAB_c06b9f40:
    if (iVar3 == 10) {
      return 10;
    }
  }
  uVar2 = *(uint *)(iVar1 + 0x18);
  *(uint *)(iVar1 + 0x18) = uVar2 & 0xfffffffe;
  if ((uVar2 & 4) != 0) {
    FUN_c06b9da8((byte *)(iVar1 + 0x20),(uint)*(byte *)(param_1 + 0x30));
  }
LAB_c06b9f70:
  LeaveCriticalSection((LPCRITICAL_SECTION)(iVar1 + 0x40));
  return iVar3;
}



/* c06b9fa4 FUN_c06b9fa4 */

/* Boundary evidence: original MIPS .pdata c06b9fa4..c06ba43b. Semantic name remains unreviewed. */

int FUN_c06b9fa4(int param_1,int param_2,uint param_3)

{
  bool bVar1;
  bool bVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  LPCRITICAL_SECTION lpCriticalSection;
  int *piVar9;
  byte *pbVar10;
  int local_1a0;
  int local_19c;
  uint local_198 [2];
  undefined4 uStack_190;
  int local_18c [2];
  undefined4 local_184 [87];
  
  iVar8 = 2;
  bVar1 = true;
  bVar2 = true;
  local_19c = param_2;
  memset(&uStack_190,0,0x168);
  *(undefined4 *)(param_1 + 0xc) = 0;
  piVar3 = (int *)FUN_c06b1b00((uint)*(byte *)(param_1 + 0x30));
  if (piVar3 == (int *)0x0) {
    return 0x14;
  }
  pbVar10 = (byte *)(param_1 + 0x20);
  iVar4 = FUN_c06b538c((int)piVar3,pbVar10,0,1);
  if (iVar4 == 0) {
    iVar8 = 4;
  }
  else {
    if ((*(uint *)(iVar4 + 0x44) & 0x10000) == 0) {
      *(uint *)(iVar4 + 0x44) = *(uint *)(iVar4 + 0x44) | 0x10000;
      do {
        if (!bVar2) {
          EnterCriticalSection((LPCRITICAL_SECTION)(piVar3 + 7));
          if ((*(byte *)((int)piVar3 + 0x39) & 1) != 0) {
            LeaveCriticalSection((LPCRITICAL_SECTION)(piVar3 + 7));
            iVar8 = 0x14;
            break;
          }
          iVar4 = FUN_c06b538c((int)piVar3,pbVar10,0,1);
          if (iVar4 == 0) {
            LeaveCriticalSection((LPCRITICAL_SECTION)(piVar3 + 7));
            iVar8 = 4;
            break;
          }
        }
        lpCriticalSection = (LPCRITICAL_SECTION)(piVar3 + 7);
        LeaveCriticalSection(lpCriticalSection);
        if ((*(uint *)(iVar4 + 0x44) & 0x40000) != 0) {
          iVar8 = 1;
          LeaveCriticalSection((LPCRITICAL_SECTION)(iVar4 + 0x5c));
          break;
        }
        iVar5 = FUN_c06b47d4(pbVar10,&uStack_190,0xf,&local_1a0,*(char *)(param_1 + 0x30));
        if ((iVar5 == 0) || (local_1a0 == 0)) {
          *(uint *)(iVar4 + 0x44) = *(uint *)(iVar4 + 0x44) | 0x20000;
          EventModify(*(undefined4 *)(iVar4 + 0x50),2);
          LeaveCriticalSection((LPCRITICAL_SECTION)(iVar4 + 0x5c));
          WaitForSingleObject(*(HANDLE *)(iVar4 + 0x50),0xffffffff);
          EnterCriticalSection(lpCriticalSection);
          if ((*(byte *)((int)piVar3 + 0x39) & 1) == 0) {
            iVar4 = FUN_c06b538c((int)piVar3,pbVar10,0,1);
            if (iVar4 != 0) {
              LeaveCriticalSection(lpCriticalSection);
              uVar7 = *(uint *)(iVar4 + 0x44);
              if (uVar7 == 0x80000) {
                iVar8 = 0x14;
LAB_c06ba354:
                bVar1 = false;
              }
              else {
                *(uint *)(iVar4 + 0x44) = uVar7 & 0xfffdffff;
                if ((uVar7 & 0x40000) != 0) goto LAB_c06ba354;
              }
              LeaveCriticalSection((LPCRITICAL_SECTION)(iVar4 + 0x5c));
              goto LAB_c06ba360;
            }
            LeaveCriticalSection(lpCriticalSection);
            iVar8 = 4;
          }
          else {
            LeaveCriticalSection(lpCriticalSection);
            iVar8 = 0x14;
          }
LAB_c06ba30c:
          bVar1 = false;
        }
        else {
          LeaveCriticalSection((LPCRITICAL_SECTION)(iVar4 + 0x5c));
          iVar8 = (**(code **)(DAT_c06bc600 + 0x28))(local_1a0,&uStack_190,0,0,0,0,0,0);
          if (iVar8 != 0) goto LAB_c06ba30c;
          iVar5 = 0;
          bVar1 = false;
          piVar9 = local_18c;
          do {
            if (*piVar9 != 0) {
              bVar1 = true;
              iVar6 = FUN_c06b4b60((uint)*(ushort *)(piVar9 + 2),(uint)*(byte *)(param_1 + 0x30));
              if (iVar6 != 0) {
                if ((*(uint *)(iVar6 + 0x18) & 1) == 0) {
                  *(uint *)(iVar6 + 0x18) = *(uint *)(iVar6 + 0x18) | 1;
                  iVar8 = FUN_c06b9b84(iVar6,local_19c,param_3,local_198);
                  if (iVar8 == 0) {
                    if ((int)param_3 < (int)local_198[0]) {
                      iVar8 = 0xe;
                      *(uint *)(param_1 + 4) = param_3;
                    }
                    else {
                      *(uint *)(param_1 + 4) = local_198[0];
                    }
                  }
                  else {
                    if (iVar8 == 10) goto LAB_c06ba268;
                    if (iVar8 == 0x10) {
                      bVar1 = false;
                      *(uint *)(iVar6 + 0x18) = *(uint *)(iVar6 + 0x18) & 0xfffffffe;
                      goto LAB_c06ba1e8;
                    }
                  }
                  *(uint *)(iVar6 + 0x18) = *(uint *)(iVar6 + 0x18) & 0xfffffffe;
                  *(undefined4 *)(param_1 + 0xc) = local_184[iVar5 * 6];
                  LeaveCriticalSection((LPCRITICAL_SECTION)(iVar6 + 0x40));
                  break;
                }
LAB_c06ba1e8:
                LeaveCriticalSection((LPCRITICAL_SECTION)(iVar6 + 0x40));
              }
            }
            iVar5 = iVar5 + 1;
            piVar9 = piVar9 + 6;
          } while (iVar5 < 0xf);
          if (bVar1) {
            bVar1 = false;
          }
          else {
LAB_c06ba268:
            bVar1 = true;
          }
        }
LAB_c06ba360:
        bVar2 = false;
        FUN_c06b4920(pbVar10,(uint)*(byte *)(param_1 + 0x30));
      } while (bVar1);
      EnterCriticalSection((LPCRITICAL_SECTION)(piVar3 + 7));
      if ((iVar8 == 0x14) || (iVar4 = FUN_c06b538c((int)piVar3,pbVar10,0,1), iVar4 == 0))
      goto LAB_c06ba3f4;
      *(uint *)(iVar4 + 0x44) = *(uint *)(iVar4 + 0x44) & 0xfffaffff;
    }
    else {
      iVar8 = 0xf;
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)(iVar4 + 0x5c));
  }
LAB_c06ba3f4:
  FUN_c06b1de4(piVar3);
  return iVar8;
}



/* c06ba43c FUN_c06ba43c */

/* Boundary evidence: original MIPS .pdata c06ba43c..c06ba4ef. Semantic name remains unreviewed. */

int FUN_c06ba43c(int param_1)

{
  int *piVar1;
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c06bc620);
  piVar1 = (int *)DAT_c06bc684;
  do {
    if (piVar1 == (int *)0x0) {
LAB_c06ba4cc:
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c06bc620);
      return (int)piVar1;
    }
    if (((param_1 == 0x100007f) && ((*(byte *)((int)piVar1 + 0x39) & 1) == 0)) ||
       ((piVar1[1] == param_1 && ((*(byte *)((int)piVar1 + 0x39) & 1) == 0)))) {
      EnterCriticalSection((LPCRITICAL_SECTION)(piVar1 + 7));
      goto LAB_c06ba4cc;
    }
    piVar1 = (int *)*piVar1;
  } while( true );
}



/* c06ba4f0 FUN_c06ba4f0 */

/* Boundary evidence: original MIPS .pdata c06ba4f0..c06ba5b3. Semantic name remains unreviewed. */

void FUN_c06ba4f0(undefined4 param_1,int param_2,int param_3,int param_4)

{
  undefined1 *puVar1;
  undefined1 local_78 [8];
  int local_70;
  undefined1 *local_6c;
  undefined1 auStack_68 [8];
  undefined1 auStack_60 [72];
  uint local_18;
  
  local_18 = DAT_c06bc0f4;
  puVar1 = local_78;
  local_78[0] = (undefined1)param_4;
  if (param_4 == 0) {
    puVar1 = (undefined1 *)0x0;
  }
  FUN_c06ba908(auStack_60,0,param_2,0,puVar1,(ushort)(param_4 != 0));
  local_6c = auStack_60;
  local_70 = param_3 + 4;
  (**(code **)(DAT_c06bc5dc + 0x20))(param_1,&local_70,1,auStack_68,0,0,0,0,0,0);
  FUN_c06bac58(local_18);
  return;
}



/* c06ba5b4 FUN_c06ba5b4 */

/* WARNING: Type propagation algorithm not settling */
/* Boundary evidence: original MIPS .pdata c06ba5b4..c06ba907. Semantic name remains unreviewed. */

void FUN_c06ba5b4(void)

{
  byte bVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  int *piVar7;
  int local_120 [3];
  int local_114;
  undefined2 auStack_110 [4];
  undefined1 auStack_108 [16];
  undefined1 local_f8;
  uint uStack_f4;
  undefined1 auStack_f0 [4];
  int local_ec;
  byte abStack_e0 [48];
  undefined1 auStack_b0 [16];
  byte abStack_a0 [48];
  char acStack_70 [72];
  
  do {
    local_120[1] = 0x10;
    bVar2 = false;
    iVar3 = (*(code *)DAT_c06bc5dc[2])(DAT_c06bc5fc,local_120,auStack_b0,0x10,local_120 + 1,0,0);
    if (iVar3 == 0) {
      iVar3 = FUN_c06b8794(local_120[0],acStack_70,0x48,&local_114,&uStack_f4,abStack_a0,abStack_e0,
                           local_120 + 2,auStack_110);
      if ((iVar3 == 0) && (local_114 == 1)) {
        local_120[1] = 0x10;
        iVar3 = (*(code *)DAT_c06bc5dc[10])(local_120[0],auStack_f0,0x10,local_120 + 1);
        if (iVar3 == 0) {
          iVar3 = FUN_c06ba43c(local_ec);
          if (iVar3 != 0) {
            iVar4 = FUN_c06b538c(iVar3,abStack_a0,0,2);
            if (iVar4 != 0) {
              piVar6 = (int *)(iVar4 + 0x54);
              if (*piVar6 == 0) {
                LeaveCriticalSection((LPCRITICAL_SECTION)(iVar3 + 0x1c));
                iVar3 = 0x80;
LAB_c06ba79c:
                FUN_c06ba4f0(local_120[0],4,1,iVar3);
              }
              else {
                FUN_c06b3b78(abStack_e0,(int)auStack_108);
                local_f8 = 0;
                if (*piVar6 != 0) {
                  while( true ) {
                    piVar7 = (int *)*piVar6;
                    iVar5 = memcmp(piVar7 + 0xc,&DAT_c06bc0e4,0x10);
                    if (iVar5 != 0) break;
                    iVar5 = memcmp(piVar7 + 0xc,auStack_108,0x10);
                    if ((iVar5 != 0) || (piVar6 = piVar7, *piVar7 == 0)) goto LAB_c06ba784;
                  }
                  memcpy((void *)(*piVar6 + 0x30),auStack_108,0x10);
                }
LAB_c06ba784:
                piVar7 = (int *)*piVar6;
                if (piVar7 == (int *)0x0) {
                  LeaveCriticalSection((LPCRITICAL_SECTION)(iVar3 + 0x1c));
                  iVar3 = 0x81;
                  goto LAB_c06ba79c;
                }
                *piVar6 = *piVar7;
                *piVar7 = 0;
                piVar7[2] = local_120[0];
                piVar6 = FUN_c06b5548(iVar3,abStack_e0,2);
                if (piVar6 == (int *)0x0) {
                  FUN_c06b5440(iVar3,abStack_e0,0,local_120[2],600,2);
                }
                else if ((piVar6[0x13] == local_120[2]) && (piVar6[0x12] < 600)) {
                  piVar6[0x12] = 600;
                }
                LeaveCriticalSection((LPCRITICAL_SECTION)(iVar3 + 0x1c));
                bVar1 = *(byte *)(piVar7 + 0x15);
                FUN_c06b4bdc(piVar7);
                EventModify(piVar7[3],3);
                FUN_c06ba4f0(local_120[0],2,0,0);
                if ((*(uint *)(iVar4 + 0x44) & 0x10000) != 0) {
                  if ((*(uint *)(iVar4 + 0x44) & 0x20000) == 0) {
                    FUN_c06b49f8(auStack_108,(uint)bVar1);
                  }
                  else {
                    EventModify(*(undefined4 *)(iVar4 + 0x50),3);
                  }
                }
                bVar2 = true;
              }
              LeaveCriticalSection((LPCRITICAL_SECTION)(iVar4 + 0x5c));
              goto LAB_c06ba8e8;
            }
            LeaveCriticalSection((LPCRITICAL_SECTION)(iVar3 + 0x1c));
          }
          FUN_c06ba4f0(local_120[0],4,1,0x82);
        }
      }
    }
    else {
      Sleep(30000);
    }
LAB_c06ba8e8:
    if (!bVar2) {
      (*(code *)*DAT_c06bc5dc)(local_120[0]);
    }
  } while( true );
}



/* c06ba908 FUN_c06ba908 */

/* Boundary evidence: original MIPS .pdata c06ba908..c06ba9ef. Semantic name remains unreviewed. */

void FUN_c06ba908(undefined1 *param_1,undefined4 param_2,int param_3,int param_4,undefined1 *param_5
                 ,ushort param_6)

{
  param_1[1] = 0;
  if (param_3 == 1) {
    *param_1 = 0x81;
    *(undefined2 *)(param_1 + 2) = 0x4400;
    FUN_c06b3b20(param_1 + 4,param_4);
    FUN_c06b3b20(param_1 + 0x26,(int)param_5);
    return;
  }
  if (param_3 == 2) {
    *param_1 = 0x82;
  }
  else {
    if (param_3 == 4) {
      *param_1 = 0x83;
      *(undefined2 *)(param_1 + 2) = 0x100;
      param_1[4] = *param_5;
      return;
    }
    if (param_3 == 0x10) {
      *param_1 = 0;
      *(ushort *)(param_1 + 2) = param_6 << 8 | param_6 >> 8;
      return;
    }
    if (param_3 != 0x20) {
      return;
    }
    *param_1 = 0x85;
  }
  *(undefined2 *)(param_1 + 2) = 0;
  return;
}



/* c06baaf0 entry */

/* Boundary evidence: original MIPS .pdata c06baaf0..c06bab63. Semantic name remains unreviewed. */

undefined4 entry(int param_1,int param_2)

{
  undefined4 uVar1;
  
  if (param_2 == 1) {
    FUN_c06bab64();
    FUN_c06baeb4();
  }
  uVar1 = FUN_c06b3194(param_1,param_2);
  if (param_2 == 0) {
    FUN_c06bae3c();
  }
  return uVar1;
}



/* c06bab64 FUN_c06bab64 */

/* Boundary evidence: original MIPS .pdata c06bab64..c06babd7. Semantic name remains unreviewed. */

void FUN_c06bab64(void)

{
  uint uVar1;
  
  if ((DAT_c06bc0f4 == 0) || (DAT_c06bc0f4 == 0xb064)) {
    uVar1 = __security_gen_cookie2();
    DAT_c06bc0f4 = uVar1 >> 0x10 ^ uVar1 & 0xffff;
    if (DAT_c06bc0f4 == 0) {
      DAT_c06bc0f4 = 0xb064;
    }
  }
  DAT_c06bc0f8 = ~DAT_c06bc0f4;
  return;
}



/* c06babd8 FUN_c06babd8 */

/* Boundary evidence: original MIPS .pdata c06babd8..c06bac2b. Semantic name remains unreviewed. */

void FUN_c06babd8(int param_1,undefined4 param_2,uint *param_3)

{
  if ((*param_3 & 1) != 0) {
    param_1 = ((-param_3[2] & param_3[1] + param_1) - (param_3[1] + param_1)) + param_1;
  }
  FUN_c06bac58(*(uint *)(param_1 + (*param_3 & 0xfffffffc)));
  return;
}



/* c06bac2c FUN_c06bac2c */

/* Boundary evidence: original MIPS .pdata c06bac2c..c06bac57. Semantic name remains unreviewed. */

undefined4 FUN_c06bac2c(undefined4 param_1,int param_2,undefined4 param_3,int param_4)

{
  FUN_c06babd8(param_2,param_4,*(uint **)(*(int *)(param_4 + 4) + 0xc));
  return 1;
}



/* c06bac58 FUN_c06bac58 */

/* Boundary evidence: original MIPS .pdata c06bac58..c06bac9f. Semantic name remains unreviewed. */

void FUN_c06bac58(uint param_1)

{
  if ((param_1 == DAT_c06bc0f4) && (param_1 >> 0x10 == 0)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __report_gsfailure();
}



/* c06baca0 FUN_c06baca0 */

/* Boundary evidence: original MIPS .pdata c06baca0..c06bad1b. Semantic name remains unreviewed. */

void FUN_c06baca0(undefined4 param_1,int param_2,undefined4 param_3,int param_4)

{
  int *piVar1;
  
  piVar1 = *(int **)(*(int *)(param_4 + 4) + 0xc);
  FUN_c06babd8(param_2,param_4,(uint *)(piVar1 + *piVar1 * 4 + 1));
  __C_specific_handler(param_1,param_2,param_3,param_4);
  return;
}



/* c06bad1c FUN_c06bad1c */

/* Boundary evidence: original MIPS .pdata c06bad1c..c06bae3b. Semantic name remains unreviewed. */

void FUN_c06bad1c(UINT param_1,int param_2,int param_3)

{
  LPCRITICAL_SECTION lpCriticalSection;
  undefined4 *_Memory;
  
  DAT_c06bc10c = (undefined1)param_3;
  if (param_2 == 0) {
    _Memory = DAT_c06bc6c4;
    if (DAT_c06bc6c4 != (undefined4 *)0x0) {
      while (DAT_c06bc6c0 = DAT_c06bc6c0 + -1, _Memory <= DAT_c06bc6c0) {
        if ((code *)*DAT_c06bc6c0 != (code *)0x0) {
          (*(code *)*DAT_c06bc6c0)();
          _Memory = DAT_c06bc6c4;
        }
      }
      free(_Memory);
      DAT_c06bc6c0 = (undefined4 *)0x0;
      DAT_c06bc6c4 = (undefined4 *)0x0;
    }
    FUN_c06bae60((undefined4 *)&DAT_c06b1010,(undefined4 *)&DAT_c06b1014);
  }
  FUN_c06bae60((undefined4 *)&DAT_c06b1018,(undefined4 *)&DAT_c06b101c);
  if (param_3 == 0) {
    TerminateProcess((HANDLE)0x42,param_1);
  }
  else {
    lpCriticalSection = (LPCRITICAL_SECTION)InterlockedExchange((LONG *)&DAT_c06bc6c8,0);
    if (lpCriticalSection != (LPCRITICAL_SECTION)0x0) {
      DeleteCriticalSection(lpCriticalSection);
      free(lpCriticalSection);
    }
  }
  return;
}



/* c06bae3c FUN_c06bae3c */

/* Boundary evidence: original MIPS .pdata c06bae3c..c06bae5f. Semantic name remains unreviewed. */

void FUN_c06bae3c(void)

{
  FUN_c06bad1c(0,0,1);
  return;
}



/* c06bae60 FUN_c06bae60 */

/* Boundary evidence: original MIPS .pdata c06bae60..c06baeb3. Semantic name remains unreviewed. */

void FUN_c06bae60(undefined4 *param_1,undefined4 *param_2)

{
  for (; param_1 < param_2; param_1 = param_1 + 1) {
    if ((code *)*param_1 != (code *)0x0) {
      (*(code *)*param_1)();
    }
  }
  return;
}



/* c06baeb4 FUN_c06baeb4 */

/* Boundary evidence: original MIPS .pdata c06baeb4..c06baeef. Semantic name remains unreviewed. */

void FUN_c06baeb4(void)

{
  FUN_c06bae60((undefined4 *)&DAT_c06b1008,(undefined4 *)&DAT_c06b100c);
  FUN_c06bae60((undefined4 *)&DAT_c06b1000,(undefined4 *)&DAT_c06b1004);
  return;
}


