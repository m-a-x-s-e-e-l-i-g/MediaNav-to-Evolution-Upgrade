/* Automatic Ghidra pseudocode. Not original source; not runtime-verified. */

/* 40121620 SetCeLogBufSize */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Boundary evidence: original MIPS .pdata 40121620..40121713. Semantic name remains unreviewed. */

undefined4 SetCeLogBufSize(uint param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  LSTATUS LVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  uint local_res0 [4];
  HKEY local_10 [2];
  
                    /* 0x1620  5  SetCeLogBufSize */
  local_res0[0] = param_1;
  if ((_DAT_00005b68 & 0x30000000) == 0) {
    LVar1 = RegCreateKeyExW((HKEY)0x80000002,L"System\\CeLog",0,(LPWSTR)0x0,0,0,
                            (LPSECURITY_ATTRIBUTES)0x0,local_10,(LPDWORD)0x0);
    if (LVar1 == 0) {
      uVar3 = 4;
      uVar2 = 0;
      LVar1 = RegSetValueExW(local_10[0],L"BufferSize",0,4,(BYTE *)local_res0,4);
      RegCloseKey(local_10[0]);
      FUN_40122090(L"CeLog buffer size set to %ukB in registry.\r\n",local_res0[0] >> 10,uVar2,uVar3
                  );
      if (LVar1 == 0) {
        return 1;
      }
    }
  }
  else {
    FUN_40122090(L"WARNING: CeLog is already running, buffer size could not be changed.\r\n",param_2
                 ,param_3,param_4);
  }
  return 0;
}



/* 40121714 DeinitFlush */

/* Boundary evidence: original MIPS .pdata 40121714..4012175b. Semantic name remains unreviewed. */

void DeinitFlush(undefined4 *param_1)

{
                    /* 0x1714  1  DeinitFlush */
  if (param_1 != (undefined4 *)0x0) {
    FUN_40121a54((int)(param_1 + 8),0,1);
    FUN_40121adc(param_1);
    LocalFree(param_1);
  }
  return;
}



/* 4012175c InitFlush */

/* Boundary evidence: original MIPS .pdata 4012175c..40121877. Semantic name remains unreviewed. */

undefined4 * InitFlush(short *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 local_20 [2];
  
                    /* 0x175c  4  InitFlush */
  local_20[0] = 0;
  puVar2 = LocalAlloc(0x40,0x34);
  if (puVar2 != (undefined4 *)0x0) {
    puVar2[0xc] = 0xffffffff;
    iVar3 = FUN_40122574(puVar2,(int *)0x0);
    uVar1 = DAT_401242bc;
    if (iVar3 != 0) {
      if ((param_1 == (short *)0x0) || (*param_1 == 0)) {
        DAT_401242bc = 2;
        param_1 = (short *)0x0;
      }
      else {
        DAT_401242bc = 3;
      }
      puVar4 = puVar2 + 8;
      FUN_40122860(puVar4);
      DAT_401242bc = uVar1;
      if (((code *)*puVar4 == (code *)0x0) || (iVar3 = (*(code *)*puVar4)(param_1), iVar3 != 0)) {
        iVar3 = FUN_401219ec((int)puVar4,param_1,local_20);
        if (iVar3 != 0) {
          return puVar2;
        }
      }
      else {
        FUN_40122090(L"%s: Transport initialization failed\r\n",L"Shell Flush",param_3,param_4);
      }
    }
  }
  DeinitFlush(puVar2);
  return (undefined4 *)0x0;
}



/* 40121878 Flush */

/* Boundary evidence: original MIPS .pdata 40121878..401218e3. Semantic name remains unreviewed. */

undefined4 Flush(int *param_1,int param_2)

{
  undefined4 uVar1;
  
                    /* 0x1878  2  Flush */
  if (param_1 == (int *)0x0) {
    uVar1 = 0;
  }
  else {
    uVar1 = 1;
    FUN_40121b54(param_1,(int)(param_1 + 8),1,(undefined4 *)0x0);
    if (param_2 != 0) {
      *(undefined4 *)(*param_1 + 0xc) = 1;
    }
  }
  return uVar1;
}



/* 401218e4 FlushOnce */

/* Boundary evidence: original MIPS .pdata 401218e4..40121983. Semantic name remains unreviewed. */

undefined4 FlushOnce(short *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int *piVar1;
  undefined4 uVar2;
  
                    /* 0x18e4  3  FlushOnce */
  piVar1 = InitFlush(param_1,param_2,param_3,param_4);
  if (piVar1 == (int *)0x0) {
    uVar2 = 0;
  }
  else {
    Flush(piVar1,0);
    DeinitFlush(piVar1);
    CeLogReSync();
    if (param_1 == (short *)0x0) {
      FUN_40122090(L"%s: CeLog data cleared\r\n",L"Shell Flush",param_3,param_4);
    }
    else {
      FUN_40122090(L"%s: CeLog data successfully written to %s\r\n",L"Shell Flush",param_1,param_4);
    }
    uVar2 = 1;
  }
  return uVar2;
}



/* 40121984 FUN_40121984 */

/* Boundary evidence: original MIPS .pdata 40121984..401219eb. Semantic name remains unreviewed. */

int FUN_40121984(HMODULE param_1,int param_2)

{
  int iVar1;
  
  iVar1 = 1;
  if ((param_2 == 1) &&
     (DisableThreadLibraryCalls(param_1), iVar1 = DAT_401242e4, DAT_401242e4 == 0)) {
    FUN_4012210c();
    DAT_401242e4 = 1;
    iVar1 = DAT_401242e4;
  }
  return iVar1;
}



/* 401219ec FUN_401219ec */

/* Boundary evidence: original MIPS .pdata 401219ec..40121a53. Semantic name remains unreviewed. */

undefined4 FUN_401219ec(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  
  if ((*(int *)(param_1 + 0x10) == -1) && (*(code **)(param_1 + 4) != (code *)0x0)) {
    iVar1 = (**(code **)(param_1 + 4))(param_2,param_3);
    *(int *)(param_1 + 0x10) = iVar1;
    if (iVar1 == -1) {
      return 0;
    }
  }
  return 1;
}



/* 40121a54 FUN_40121a54 */

/* Boundary evidence: original MIPS .pdata 40121a54..40121adb. Semantic name remains unreviewed. */

void FUN_40121a54(int param_1,int param_2,int param_3)

{
  if (((*(code **)(param_1 + 0xc) != (code *)0x0) && (*(int *)(param_1 + 0x10) != -1)) &&
     (((param_3 != 0 || ((DAT_401242c0 & 2) != 0)) || (((DAT_401242c0 & 1) == 0 && (param_2 == 0))))
     )) {
    (**(code **)(param_1 + 0xc))();
    *(undefined4 *)(param_1 + 0x10) = 0xffffffff;
  }
  return;
}



/* 40121adc FUN_40121adc */

/* Boundary evidence: original MIPS .pdata 40121adc..40121b53. Semantic name remains unreviewed. */

void FUN_40121adc(undefined4 *param_1)

{
  if ((LPCVOID)*param_1 != (LPCVOID)0x0) {
    UnmapViewOfFile((LPCVOID)*param_1);
    *param_1 = 0;
  }
  if ((HANDLE)param_1[6] != (HANDLE)0x0) {
    CloseHandle((HANDLE)param_1[6]);
    param_1[6] = 0;
  }
  if ((HANDLE)param_1[7] != (HANDLE)0x0) {
    CloseHandle((HANDLE)param_1[7]);
    param_1[7] = 0;
  }
  return;
}



/* 40121b54 FUN_40121b54 */

/* Boundary evidence: original MIPS .pdata 40121b54..40121d0f. Semantic name remains unreviewed. */

void FUN_40121b54(int *param_1,int param_2,int param_3,undefined4 *param_4)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  undefined4 local_30;
  int local_2c;
  
  uVar3 = param_1[2];
  uVar2 = *(int *)(*param_1 + 0x20) + param_1[1];
  param_1[3] = uVar2;
  if (uVar2 < uVar3) {
    uVar3 = param_1[4] - uVar3;
    uVar2 = uVar2 - param_1[1];
  }
  else {
    uVar3 = uVar2 - uVar3;
    uVar2 = 0;
  }
  for (; uVar3 != 0; uVar3 = uVar3 - uVar4) {
    uVar4 = uVar3;
    if (0x1ffff < uVar3) {
      uVar4 = 0x20000;
    }
    if (*(code **)(param_2 + 8) != (code *)0x0) {
      (**(code **)(param_2 + 8))(*(undefined4 *)(param_2 + 0x10),param_1[2],uVar4);
    }
    iVar1 = param_1[2];
    param_1[2] = iVar1 + uVar4;
    *(uint *)(*param_1 + 0x24) = (iVar1 + uVar4) - param_1[1];
  }
  if (uVar2 != 0) {
    param_1[2] = param_1[1];
    *(undefined4 *)(*param_1 + 0x24) = 0;
    do {
      uVar3 = uVar2;
      if (0x1ffff < uVar2) {
        uVar3 = 0x20000;
      }
      if (*(code **)(param_2 + 8) != (code *)0x0) {
        (**(code **)(param_2 + 8))(*(undefined4 *)(param_2 + 0x10),param_1[2],uVar3);
      }
      iVar1 = param_1[2];
      param_1[2] = iVar1 + uVar3;
      uVar2 = uVar2 - uVar3;
      *(uint *)(*param_1 + 0x24) = (iVar1 + uVar3) - param_1[1];
    } while (uVar2 != 0);
  }
  if (param_3 != 0) {
    local_2c = *(int *)(*param_1 + 0x14);
    local_30 = 0x960004;
    iVar1 = param_1[5];
    param_1[5] = local_2c;
    local_2c = local_2c - iVar1;
    if (*(code **)(param_2 + 8) != (code *)0x0) {
      (**(code **)(param_2 + 8))(*(undefined4 *)(param_2 + 0x10),&local_30,8);
    }
    if ((param_4 != (undefined4 *)0x0) && (local_2c != 0)) {
      *param_4 = 1;
    }
  }
  return;
}



/* 40121d10 FUN_40121d10 */

/* Boundary evidence: original MIPS .pdata 40121d10..40121d4f. Semantic name remains unreviewed. */

bool FUN_40121d10(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = U_ropen(param_1,0x80002);
  if (iVar1 != -1) {
    U_rclose(iVar1);
  }
  return iVar1 != -1;
}



/* 40121d50 FUN_40121d50 */

/* Boundary evidence: original MIPS .pdata 40121d50..40121de7. Semantic name remains unreviewed. */

int FUN_40121d50(undefined4 param_1,undefined4 *param_2)

{
  int iVar1;
  
  iVar1 = U_ropen(param_1,0x10002);
  if (iVar1 == -1) {
    iVar1 = U_ropen(param_1,0x90002);
    if (iVar1 == -1) {
      return -1;
    }
    *param_2 = 1;
  }
  U_rlseek(iVar1,0,2);
  return iVar1;
}



/* 40121de8 FUN_40121de8 */

/* Boundary evidence: original MIPS .pdata 40121de8..40121e07. Semantic name remains unreviewed. */

undefined4 FUN_40121de8(void)

{
  U_rclose();
  return 1;
}



/* 40121e08 FUN_40121e08 */

/* Boundary evidence: original MIPS .pdata 40121e08..40121e27. Semantic name remains unreviewed. */

undefined4 FUN_40121e08(void)

{
  U_rwrite();
  return 1;
}



/* 40121e28 FUN_40121e28 */

/* Boundary evidence: original MIPS .pdata 40121e28..40122013. Semantic name remains unreviewed. */

HANDLE FUN_40121e28(STRSAFE_LPCWSTR param_1,uint *param_2)

{
  DWORD DVar1;
  HANDLE hFile;
  HRESULT HVar2;
  HANDLE hFile_00;
  uint uVar3;
  wchar_t awStack_238 [260];
  uint local_30;
  
  local_30 = DAT_401242dc;
  DVar1 = GetFileAttributesW(param_1);
  hFile_00 = (HANDLE)0xffffffff;
  uVar3 = (uint)(DVar1 == 0xffffffff);
  hFile = CreateFileW(param_1,0x40000000,1,(LPSECURITY_ATTRIBUTES)0x0,4,0x10000080,(HANDLE)0x0);
  if (hFile == (HANDLE)0xffffffff) {
LAB_40121ed4:
    FUN_40122c90(local_30);
  }
  else {
    DVar1 = GetFileSize(hFile,(LPDWORD)0x0);
    if ((((DAT_401242d4 != 0) && (DAT_401242d4 < DVar1)) &&
        (HVar2 = StringCchCopyW(awStack_238,0x104,param_1), -1 < HVar2)) &&
       (HVar2 = StringCchCatW(awStack_238,0x104,L".old"), -1 < HVar2)) {
      CloseHandle(hFile);
      DeleteFileW(awStack_238);
      MoveFileW(param_1,awStack_238);
      hFile = CreateFileW(param_1,0x40000000,1,(LPSECURITY_ATTRIBUTES)0x0,4,0x10000080,(HANDLE)0x0);
      if (hFile == (HANDLE)0xffffffff) goto LAB_40121ed4;
      uVar3 = 1;
    }
    hFile_00 = hFile;
    *param_2 = uVar3;
    SetFilePointer(hFile_00,0,(PLONG)0x0,2);
    FUN_40122c90(local_30);
  }
  return hFile_00;
}



/* 40122014 FUN_40122014 */

/* Boundary evidence: original MIPS .pdata 40122014..4012203b. Semantic name remains unreviewed. */

undefined4 FUN_40122014(HANDLE param_1)

{
  CloseHandle(param_1);
  return 1;
}



/* 4012203c FUN_4012203c */

/* Boundary evidence: original MIPS .pdata 4012203c..4012208f. Semantic name remains unreviewed. */

undefined4 FUN_4012203c(HANDLE param_1,LPCVOID param_2,DWORD param_3)

{
  BOOL BVar1;
  undefined4 uVar2;
  DWORD local_10 [2];
  
  local_10[0] = 0;
  BVar1 = WriteFile(param_1,param_2,param_3,local_10,(LPOVERLAPPED)0x0);
  if ((BVar1 == 0) || (uVar2 = 1, local_10[0] != param_3)) {
    uVar2 = 0;
  }
  return uVar2;
}



/* 40122090 FUN_40122090 */

/* Boundary evidence: original MIPS .pdata 40122090..4012210b. Semantic name remains unreviewed. */

void FUN_40122090(STRSAFE_LPCWSTR param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  HRESULT HVar1;
  undefined4 local_res4;
  undefined4 local_res8;
  undefined4 local_resc;
  wchar_t awStack_218 [260];
  uint local_10;
  
  local_10 = DAT_401242dc;
  local_res4 = param_2;
  local_res8 = param_3;
  local_resc = param_4;
  HVar1 = StringCchVPrintfW(awStack_218,0x104,param_1,(va_list)&local_res4);
  if ((-1 < HVar1) && (DAT_401242ec != (code *)0x0)) {
    (*DAT_401242ec)(0,awStack_218,L"Shell Flush",0x40);
  }
  FUN_40122c90(local_10);
  return;
}



/* 4012210c FUN_4012210c */

/* Boundary evidence: original MIPS .pdata 4012210c..40122573. Semantic name remains unreviewed. */

undefined4 FUN_4012210c(void)

{
  LSTATUS LVar1;
  int iVar2;
  undefined4 uVar3;
  size_t _Count;
  DWORD local_238;
  DWORD local_234;
  uint local_230;
  HKEY local_22c;
  wchar_t awStack_228 [260];
  uint local_20;
  
  local_20 = DAT_401242dc;
  LVar1 = RegOpenKeyExW((HKEY)0x80000002,L"System\\CeLog",0,0,&local_22c);
  if (LVar1 == 0) {
    local_238 = 4;
    LVar1 = RegQueryValueExW(local_22c,L"FlushTimeout",(LPDWORD)0x0,&local_234,(LPBYTE)&local_230,
                             &local_238);
    if (((LVar1 == 0) && (local_238 == 4)) && (local_234 == 4)) {
      DAT_401240a8 = local_230;
    }
    local_238 = 4;
    LVar1 = RegQueryValueExW(local_22c,L"SavedFlushes",(LPDWORD)0x0,&local_234,(LPBYTE)&local_230,
                             &local_238);
    if (((LVar1 == 0) && (local_238 == 4)) && (local_234 == 4)) {
      DAT_401240ac = local_230;
    }
    local_238 = 4;
    LVar1 = RegQueryValueExW(local_22c,L"ThreadPriority",(LPDWORD)0x0,&local_234,(LPBYTE)&local_230,
                             &local_238);
    if (((LVar1 == 0) && (local_238 == 4)) && ((local_234 == 4 && (local_230 < 0x100)))) {
      DAT_401240b0 = local_230;
    }
    local_238 = 0x208;
    LVar1 = RegQueryValueExW(local_22c,L"Transport",(LPDWORD)0x0,&local_234,(LPBYTE)awStack_228,
                             &local_238);
    uVar3 = 1;
    if ((LVar1 == 0) && (local_234 == 1)) {
      iVar2 = _wcsicmp(awStack_228,L"RAM");
      if (iVar2 == 0) {
        DAT_401242bc = 2;
      }
      else {
        iVar2 = _wcsicmp(awStack_228,L"LocalFile");
        if (iVar2 == 0) {
          DAT_401242bc = 3;
        }
        else {
          DAT_401242bc = 1;
        }
      }
    }
    local_238 = 0x208;
    LVar1 = RegQueryValueExW(local_22c,L"FileName",(LPDWORD)0x0,&local_234,(LPBYTE)awStack_228,
                             &local_238);
    if ((LVar1 == 0) && (local_234 == 1)) {
      _Count = local_238 >> 1;
      if (0x103 < _Count) {
        _Count = 0x103;
      }
      wcsncpy(u__Release_celog_clg_401240b4,awStack_228,_Count);
      u__Release_celog_clg_401240b4[_Count] = L'\0';
    }
    local_238 = 4;
    LVar1 = RegQueryValueExW(local_22c,L"FileFlags",(LPDWORD)0x0,&local_234,(LPBYTE)&local_230,
                             &local_238);
    if (((LVar1 == 0) && (local_238 == 4)) && (local_234 == 4)) {
      DAT_401242c0 = local_230;
    }
    local_238 = 4;
    LVar1 = RegQueryValueExW(local_22c,L"ZoneCE",(LPDWORD)0x0,&local_234,(LPBYTE)&local_230,
                             &local_238);
    if (((LVar1 == 0) && (local_238 == 4)) && (local_234 == 4)) {
      DAT_401242c8 = 1;
      DAT_401242c4 = local_230;
    }
    local_238 = 4;
    LVar1 = RegQueryValueExW(local_22c,L"UseUI",(LPDWORD)0x0,&local_234,(LPBYTE)&local_230,
                             &local_238);
    if (((LVar1 == 0) && (local_238 == 4)) && (local_234 == 4)) {
      if (local_230 == 0) {
        DAT_401242cc = 0;
      }
      else {
        DAT_401242cc = 1;
      }
    }
    local_238 = 4;
    LVar1 = RegQueryValueExW(local_22c,L"FileSize",(LPDWORD)0x0,&local_234,(LPBYTE)&local_230,
                             &local_238);
    if ((((LVar1 == 0) && (local_238 == 4)) && (local_234 == 4)) &&
       (DAT_401242d4 = local_230, local_230 != 0)) {
      DAT_401242c0 = DAT_401242c0 & 0xfffffffe | 2;
    }
    RegCloseKey(local_22c);
    FUN_40122c90(local_20);
  }
  else {
    FUN_40122c90(local_20);
    uVar3 = 0;
  }
  return uVar3;
}



/* 40122574 FUN_40122574 */

/* Boundary evidence: original MIPS .pdata 40122574..40122797. Semantic name remains unreviewed. */

undefined4 FUN_40122574(undefined4 *param_1,int *param_2)

{
  HANDLE pvVar1;
  DWORD DVar2;
  int iVar3;
  int *piVar4;
  wchar_t *pwVar5;
  undefined4 uVar6;
  wchar_t *pwVar7;
  int iVar8;
  
  pwVar7 = L"CeLog Flush Instance";
  uVar6 = 0;
  *param_1 = 0;
  param_1[6] = 0;
  param_1[7] = 0;
  pvVar1 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,L"CeLog Flush Instance");
  param_1[7] = pvVar1;
  if (pvVar1 == (HANDLE)0x0) {
    DVar2 = GetLastError();
    FUN_40122090(L"%s: Error, unable to create named event (%u)\r\n",L"Shell Flush",DVar2,pwVar7);
    return 0;
  }
  DVar2 = GetLastError();
  if (DVar2 == 0xb7) {
    pwVar5 = L"%s: Another CeLog flushing tool is already running, aborting to avoid conflict.\r\n";
  }
  else {
    pwVar7 = (wchar_t *)0x0;
    uVar6 = 4;
    pvVar1 = CreateFileMappingW((HANDLE)0xffffffff,(LPSECURITY_ATTRIBUTES)0x0,4,0,0,
                                L"SYSTEM/CeLog Data");
    param_1[6] = pvVar1;
    if (pvVar1 == (HANDLE)0x0) {
      if (param_2 == (int *)0x0) goto LAB_40122770;
      iVar3 = LoadKernelLibrary(L"CeLog.dll");
      *param_2 = iVar3;
      if (iVar3 == 0) {
        pwVar5 = L"%s: Failed to load CeLog DLL\r\n";
      }
      else {
        pwVar7 = (wchar_t *)0x0;
        uVar6 = 4;
        pvVar1 = CreateFileMappingW((HANDLE)0xffffffff,(LPSECURITY_ATTRIBUTES)0x0,4,0,0,
                                    L"SYSTEM/CeLog Data");
        param_1[6] = pvVar1;
        if (pvVar1 != (HANDLE)0x0) goto LAB_401226c8;
        pwVar5 = L"%s: CeLog map not found\r\n";
      }
    }
    else {
LAB_401226c8:
      pwVar7 = (wchar_t *)0x0;
      uVar6 = 0;
      piVar4 = MapViewOfFile((HANDLE)param_1[6],0xf001f,0,0,0);
      *param_1 = piVar4;
      if (piVar4 == (int *)0x0) {
        pwVar5 = L"%s: Unable to open CeLog map\r\n";
      }
      else {
        if (((piVar4[2] == 0) && (piVar4[1] == 0)) && (piVar4[6] == 2)) {
          iVar3 = piVar4[7] + (int)piVar4;
          param_1[1] = iVar3;
          param_1[2] = piVar4[9] + iVar3;
          iVar8 = *piVar4;
          param_1[5] = 0;
          param_1[4] = iVar8 + iVar3;
          return 1;
        }
        pwVar5 = L"%s: Unknown CeLog map format\r\n";
      }
    }
  }
  FUN_40122090(pwVar5,L"Shell Flush",uVar6,pwVar7);
LAB_40122770:
  FUN_40121adc(param_1);
  return 0;
}



/* 40122798 FUN_40122798 */

/* Boundary evidence: original MIPS .pdata 40122798..4012285f. Semantic name remains unreviewed. */

bool FUN_40122798(LPCWSTR param_1)

{
  HANDLE hObject;
  undefined4 uVar1;
  
  uVar1 = 0;
  hObject = CreateFileW(param_1,0x40000000,1,(LPSECURITY_ATTRIBUTES)0x0,2,0x80,(HANDLE)0x0);
  if (hObject != (HANDLE)0xffffffff) {
    CloseHandle(hObject);
    DeleteFileW(param_1);
    FUN_40122090(L"%s: Using file %s\r\n",L"Shell Flush",param_1,uVar1);
  }
  else {
    FUN_40122090(L"%s: Unable to open file %s\r\n",L"Shell Flush",param_1,uVar1);
  }
  return hObject != (HANDLE)0xffffffff;
}



/* 40122860 FUN_40122860 */

/* Boundary evidence: original MIPS .pdata 40122860..4012290b. Semantic name remains unreviewed. */

void FUN_40122860(undefined4 *param_1)

{
  code *pcVar1;
  
  if (DAT_401242bc == 2) {
    memset(param_1,0,0x14);
  }
  else {
    if (DAT_401242bc == 3) {
      *param_1 = FUN_40122798;
      pcVar1 = FUN_4012203c;
      param_1[1] = FUN_40121e28;
      param_1[3] = FUN_40122014;
    }
    else {
      *param_1 = FUN_40121d10;
      pcVar1 = FUN_40121e08;
      param_1[1] = FUN_40121d50;
      param_1[3] = FUN_40121de8;
    }
    param_1[2] = pcVar1;
  }
  return;
}



/* 401229dc FUN_401229dc */

/* Boundary evidence: original MIPS .pdata 401229dc..40122b17. Semantic name remains unreviewed. */

int FUN_401229dc(HMODULE param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 1;
  if (param_2 == 1) {
    if (DAT_401242fc != (code *)0x0) {
      iVar2 = (*DAT_401242fc)(param_1,1,param_3);
    }
    iVar1 = 0;
    if (iVar2 == 0) goto LAB_40122a8c;
    FUN_40122e70();
  }
  iVar1 = 0;
  if (iVar2 != 0) {
    iVar1 = FUN_40121984(param_1,param_2);
  }
LAB_40122a8c:
  if (((param_2 == 0) && (FUN_40122df8(), iVar1 != 0)) && (DAT_401242fc != (code *)0x0)) {
    iVar1 = (*DAT_401242fc)(param_1,0,param_3);
  }
  return iVar1;
}



/* 40122b18 FUN_40122b18 */

/* Boundary evidence: original MIPS .pdata 40122b18..40122b43. Semantic name remains unreviewed. */

void FUN_40122b18(_EXCEPTION_POINTERS *param_1)

{
  _XcptFilter(param_1->ExceptionRecord->ExceptionCode,param_1);
  return;
}



/* 40122b44 entry */

/* Boundary evidence: original MIPS .pdata 40122b44..40122b9b. Semantic name remains unreviewed. */

void entry(HMODULE param_1,int param_2,undefined4 param_3)

{
  if (param_2 == 1) {
    FUN_40122b9c();
  }
  FUN_401229dc(param_1,param_2,param_3);
  return;
}



/* 40122b9c FUN_40122b9c */

/* Boundary evidence: original MIPS .pdata 40122b9c..40122c0f. Semantic name remains unreviewed. */

void FUN_40122b9c(void)

{
  uint uVar1;
  
  if ((DAT_401242dc == 0) || (DAT_401242dc == 0xb064)) {
    uVar1 = __security_gen_cookie2();
    DAT_401242dc = uVar1 >> 0x10 ^ uVar1 & 0xffff;
    if (DAT_401242dc == 0) {
      DAT_401242dc = 0xb064;
    }
  }
  DAT_401242e0 = ~DAT_401242dc;
  return;
}



/* 40122c10 FUN_40122c10 */

/* Boundary evidence: original MIPS .pdata 40122c10..40122c63. Semantic name remains unreviewed. */

void FUN_40122c10(int param_1,undefined4 param_2,uint *param_3)

{
  if ((*param_3 & 1) != 0) {
    param_1 = ((-param_3[2] & param_3[1] + param_1) - (param_3[1] + param_1)) + param_1;
  }
  FUN_40122c90(*(uint *)(param_1 + (*param_3 & 0xfffffffc)));
  return;
}



/* 40122c64 FUN_40122c64 */

/* Boundary evidence: original MIPS .pdata 40122c64..40122c8f. Semantic name remains unreviewed. */

undefined4 FUN_40122c64(undefined4 param_1,int param_2,undefined4 param_3,int param_4)

{
  FUN_40122c10(param_2,param_4,*(uint **)(*(int *)(param_4 + 4) + 0xc));
  return 1;
}



/* 40122c90 FUN_40122c90 */

/* Boundary evidence: original MIPS .pdata 40122c90..40122cd7. Semantic name remains unreviewed. */

void FUN_40122c90(uint param_1)

{
  if ((param_1 == DAT_401242dc) && (param_1 >> 0x10 == 0)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __report_gsfailure();
}



/* 40122cd8 FUN_40122cd8 */

/* Boundary evidence: original MIPS .pdata 40122cd8..40122df7. Semantic name remains unreviewed. */

void FUN_40122cd8(UINT param_1,int param_2,int param_3)

{
  LPCRITICAL_SECTION lpCriticalSection;
  undefined4 *_Memory;
  
  DAT_401242e8 = (undefined1)param_3;
  if (param_2 == 0) {
    _Memory = DAT_401242f4;
    if (DAT_401242f4 != (undefined4 *)0x0) {
      while (DAT_401242f0 = DAT_401242f0 + -1, _Memory <= DAT_401242f0) {
        if ((code *)*DAT_401242f0 != (code *)0x0) {
          (*(code *)*DAT_401242f0)();
          _Memory = DAT_401242f4;
        }
      }
      free(_Memory);
      DAT_401242f0 = (undefined4 *)0x0;
      DAT_401242f4 = (undefined4 *)0x0;
    }
    FUN_40122e1c((undefined4 *)&DAT_40121010,(undefined4 *)&DAT_40121014);
  }
  FUN_40122e1c((undefined4 *)&DAT_40121018,(undefined4 *)&DAT_4012101c);
  if (param_3 == 0) {
    TerminateProcess((HANDLE)0x42,param_1);
  }
  else {
    lpCriticalSection = (LPCRITICAL_SECTION)InterlockedExchange((LONG *)&DAT_401242f8,0);
    if (lpCriticalSection != (LPCRITICAL_SECTION)0x0) {
      DeleteCriticalSection(lpCriticalSection);
      free(lpCriticalSection);
    }
  }
  return;
}



/* 40122df8 FUN_40122df8 */

/* Boundary evidence: original MIPS .pdata 40122df8..40122e1b. Semantic name remains unreviewed. */

void FUN_40122df8(void)

{
  FUN_40122cd8(0,0,1);
  return;
}



/* 40122e1c FUN_40122e1c */

/* Boundary evidence: original MIPS .pdata 40122e1c..40122e6f. Semantic name remains unreviewed. */

void FUN_40122e1c(undefined4 *param_1,undefined4 *param_2)

{
  for (; param_1 < param_2; param_1 = param_1 + 1) {
    if ((code *)*param_1 != (code *)0x0) {
      (*(code *)*param_1)();
    }
  }
  return;
}



/* 40122e70 FUN_40122e70 */

/* Boundary evidence: original MIPS .pdata 40122e70..40122eab. Semantic name remains unreviewed. */

void FUN_40122e70(void)

{
  FUN_40122e1c((undefined4 *)&DAT_40121008,(undefined4 *)&DAT_4012100c);
  FUN_40122e1c((undefined4 *)&DAT_40121000,(undefined4 *)&DAT_40121004);
  return;
}


