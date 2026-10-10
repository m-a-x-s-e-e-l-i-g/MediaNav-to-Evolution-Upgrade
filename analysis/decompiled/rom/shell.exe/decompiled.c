/* Automatic Ghidra pseudocode. Not original source; not runtime-verified. */

/* 000175a0 FUN_000175a0 */

/* Boundary evidence: original MIPS .pdata 000175a0..00017633. Semantic name remains unreviewed. */

void FUN_000175a0(undefined4 param_1,undefined4 param_2,wchar_t *param_3)

{
  UINT UVar1;
  
  FUN_000178b0();
  UVar1 = FUN_0001d7b0(param_1,param_2,param_3);
  FUN_000177f0(UVar1);
  FUN_00017810(UVar1);
  return;
}



/* 00017634 FUN_00017634 */

/* Boundary evidence: original MIPS .pdata 00017634..00017673. Semantic name remains unreviewed. */

void FUN_00017634(_EXCEPTION_POINTERS *param_1)

{
  int in_v0;
  
  *(DWORD *)(in_v0 + -0x20) = param_1->ExceptionRecord->ExceptionCode;
  _XcptFilter(*(ulong *)(in_v0 + -0x20),param_1);
  return;
}



/* 00017674 entry */

/* Boundary evidence: original MIPS .pdata 00017674..000176cf. Semantic name remains unreviewed. */

void entry(undefined4 param_1,undefined4 param_2,wchar_t *param_3)

{
  FUN_000178ec();
  FUN_000175a0(param_1,param_2,param_3);
  return;
}



/* 000176d0 FUN_000176d0 */

/* Boundary evidence: original MIPS .pdata 000176d0..000177ef. Semantic name remains unreviewed. */

void FUN_000176d0(UINT param_1,int param_2,int param_3)

{
  LPCRITICAL_SECTION lpCriticalSection;
  undefined4 *_Memory;
  
  DAT_0001f280 = (undefined1)param_3;
  if (param_2 == 0) {
    _Memory = DAT_00020934;
    if (DAT_00020934 != (undefined4 *)0x0) {
      while (DAT_00020930 = DAT_00020930 + -1, _Memory <= DAT_00020930) {
        if ((code *)*DAT_00020930 != (code *)0x0) {
          (*(code *)*DAT_00020930)();
          _Memory = DAT_00020934;
        }
      }
      free(_Memory);
      DAT_00020930 = (undefined4 *)0x0;
      DAT_00020934 = (undefined4 *)0x0;
    }
    FUN_0001785c((undefined4 *)&DAT_00011010,(undefined4 *)&DAT_00011014);
  }
  FUN_0001785c((undefined4 *)&DAT_00011018,(undefined4 *)&DAT_0001101c);
  if (param_3 == 0) {
    TerminateProcess((HANDLE)0x42,param_1);
  }
  else {
    lpCriticalSection = (LPCRITICAL_SECTION)InterlockedExchange((LONG *)&DAT_00020938,0);
    if (lpCriticalSection != (LPCRITICAL_SECTION)0x0) {
      DeleteCriticalSection(lpCriticalSection);
      free(lpCriticalSection);
    }
  }
  return;
}



/* 000177f0 FUN_000177f0 */

/* Boundary evidence: original MIPS .pdata 000177f0..0001780f. Semantic name remains unreviewed. */

void FUN_000177f0(UINT param_1)

{
  FUN_000176d0(param_1,0,0);
  return;
}



/* 00017810 FUN_00017810 */

/* Boundary evidence: original MIPS .pdata 00017810..0001785b. Semantic name remains unreviewed. */

void FUN_00017810(UINT param_1)

{
  DAT_0001f280 = 0;
  FUN_0001785c((undefined4 *)&DAT_00011018,(undefined4 *)&DAT_0001101c);
  TerminateProcess((HANDLE)0x42,param_1);
  return;
}



/* 0001785c FUN_0001785c */

/* Boundary evidence: original MIPS .pdata 0001785c..000178af. Semantic name remains unreviewed. */

void FUN_0001785c(undefined4 *param_1,undefined4 *param_2)

{
  for (; param_1 < param_2; param_1 = param_1 + 1) {
    if ((code *)*param_1 != (code *)0x0) {
      (*(code *)*param_1)();
    }
  }
  return;
}



/* 000178b0 FUN_000178b0 */

/* Boundary evidence: original MIPS .pdata 000178b0..000178eb. Semantic name remains unreviewed. */

void FUN_000178b0(void)

{
  FUN_0001785c((undefined4 *)&DAT_00011008,(undefined4 *)&DAT_0001100c);
  FUN_0001785c((undefined4 *)&DAT_00011000,(undefined4 *)&DAT_00011004);
  return;
}



/* 000178ec FUN_000178ec */

/* Boundary evidence: original MIPS .pdata 000178ec..0001795f. Semantic name remains unreviewed. */

void FUN_000178ec(void)

{
  uint uVar1;
  
  if ((DAT_0001f184 == 0) || (DAT_0001f184 == 0xb064)) {
    uVar1 = __security_gen_cookie2();
    DAT_0001f184 = uVar1 >> 0x10 ^ uVar1 & 0xffff;
    if (DAT_0001f184 == 0) {
      DAT_0001f184 = 0xb064;
    }
  }
  DAT_0001f188 = ~DAT_0001f184;
  return;
}



/* 000179d0 FUN_000179d0 */

undefined4 FUN_000179d0(uint param_1)

{
  undefined4 uVar1;
  uint uVar2;
  
  uVar2 = param_1 & 3;
  if (uVar2 == 0) {
    uVar1 = 0x80000000;
  }
  else if (uVar2 == 1) {
    uVar1 = 0x40000000;
  }
  else if (uVar2 == 2) {
    uVar1 = 0xc0000000;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}



/* 00017a18 FUN_00017a18 */

undefined4 FUN_00017a18(uint param_1)

{
  uint uVar1;
  
  if ((param_1 & 0xffff0000) == 0) {
    uVar1 = param_1 & 0xff00;
    if (uVar1 == 0) {
      return 3;
    }
    if (uVar1 == 0x100) {
      return 4;
    }
    if (uVar1 == 0x200) {
      return 5;
    }
    if (uVar1 != 0x300) {
      if (uVar1 != 0x500) {
        return 0;
      }
      return 1;
    }
  }
  else {
    uVar1 = param_1 & 0x90000;
    if (uVar1 == 0x10000) {
      return 3;
    }
    if (uVar1 != 0x80000) {
      if (uVar1 == 0x90000) {
        return 4;
      }
      return 0;
    }
  }
  return 2;
}



/* 00017ac0 FUN_00017ac0 */

/* Boundary evidence: original MIPS .pdata 00017ac0..00017b6f. Semantic name remains unreviewed. */

HANDLE FUN_00017ac0(wchar_t *param_1,uint param_2)

{
  size_t sVar1;
  DWORD dwCreationDisposition;
  DWORD dwDesiredAccess;
  HANDLE pvVar2;
  wchar_t awStack_428 [520];
  uint local_18;
  
  local_18 = DAT_0001f184;
  wcscpy(awStack_428,L"\\Release\\");
  sVar1 = wcslen(awStack_428);
  wcsncat(awStack_428,param_1,0x207 - sVar1);
  dwCreationDisposition = FUN_00017a18(param_2);
  dwDesiredAccess = FUN_000179d0(param_2);
  pvVar2 = CreateFileW(awStack_428,dwDesiredAccess,3,(LPSECURITY_ATTRIBUTES)0x0,
                       dwCreationDisposition,0,(HANDLE)0x0);
  FUN_0001e3d4(local_18);
  return pvVar2;
}



/* 00017b70 FUN_00017b70 */

/* Boundary evidence: original MIPS .pdata 00017b70..00017bab. Semantic name remains unreviewed. */

DWORD FUN_00017b70(HANDLE param_1,LPVOID param_2,DWORD param_3)

{
  BOOL BVar1;
  DWORD local_10 [2];
  
  BVar1 = ReadFile(param_1,param_2,param_3,local_10,(LPOVERLAPPED)0x0);
  if (BVar1 == 0) {
    local_10[0] = 0;
  }
  return local_10[0];
}



/* 00017bac FUN_00017bac */

/* Boundary evidence: original MIPS .pdata 00017bac..00017be7. Semantic name remains unreviewed. */

DWORD FUN_00017bac(HANDLE param_1,LPCVOID param_2,DWORD param_3)

{
  BOOL BVar1;
  DWORD local_10 [2];
  
  BVar1 = WriteFile(param_1,param_2,param_3,local_10,(LPOVERLAPPED)0x0);
  if (BVar1 == 0) {
    local_10[0] = 0;
  }
  return local_10[0];
}



/* 00017be8 FUN_00017be8 */

/* Boundary evidence: original MIPS .pdata 00017be8..00017c37. Semantic name remains unreviewed. */

void FUN_00017be8(LPCWSTR param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 local_res4;
  undefined4 local_res8;
  undefined4 local_resc;
  WCHAR aWStack_810 [1024];
  uint local_10;
  
  local_10 = DAT_0001f184;
  local_res4 = param_2;
  local_res8 = param_3;
  local_resc = param_4;
  wvsprintfW(aWStack_810,param_1,(va_list)&local_res4);
  FUN_0001e194(aWStack_810);
  FUN_0001e3d4(local_10);
  return;
}



/* 00017c38 FUN_00017c38 */

/* Boundary evidence: original MIPS .pdata 00017c38..00017d4b. Semantic name remains unreviewed. */

undefined4 FUN_00017c38(int param_1)

{
  short sVar1;
  undefined2 *puVar2;
  wchar_t *pwVar3;
  short *psVar4;
  int iVar5;
  short local_218 [260];
  uint local_10;
  
  local_10 = DAT_0001f184;
  if (param_1 == 0) {
LAB_00017d08:
    iVar5 = LoadKernelLibrary(L"CeLog.dll");
    if (iVar5 != 0) {
      FUN_0001e194(
                  L"CeLog is now loaded.\r\n*** You should probably start a flush application like CeLogFlush.exe.\r\n\r\n"
                  );
      FUN_0001e3d4(local_10);
      return 1;
    }
    pwVar3 = L"CeLog could not be loaded.  Make sure CeLog.dll is present.\r\n\r\n";
  }
  else {
    FUN_0001e194(
                L"\r\nCeLog has not been loaded yet, load it now?  (y or n at prompt below)\r\nWindows CE>"
                );
    puVar2 = FUN_0001e0b4(local_218,0x104);
    if (puVar2 == (undefined2 *)0x0) goto LAB_00017c74;
    iVar5 = 0;
    for (psVar4 = local_218; ((sVar1 = *psVar4, sVar1 == 0x20 || (sVar1 == 0xd)) || (sVar1 == 10));
        psVar4 = psVar4 + 1) {
      iVar5 = iVar5 + 1;
    }
    if ((local_218[iVar5] == 0x59) || (local_218[iVar5] == 0x79)) goto LAB_00017d08;
    pwVar3 = L"CeLog is not loaded, command aborted.\r\n\r\n";
  }
  FUN_0001e194(pwVar3);
LAB_00017c74:
  FUN_0001e3d4(local_10);
  return 0;
}



/* 00017d4c FUN_00017d4c */

/* Boundary evidence: original MIPS .pdata 00017d4c..00017e37. Semantic name remains unreviewed. */

int FUN_00017d4c(wchar_t *param_1,wchar_t *param_2)

{
  wchar_t *pwVar1;
  wchar_t *pwVar2;
  int iVar3;
  wchar_t awStack_430 [260];
  wchar_t awStack_228 [260];
  uint local_20;
  
  local_20 = DAT_0001f184;
  pwVar1 = wcsrchr(param_1,L'\\');
  pwVar2 = wcsrchr(param_2,L'\\');
  if (pwVar1 != (wchar_t *)0x0) {
    param_1 = pwVar1 + 1;
  }
  StringCchCopyW(awStack_228,0x104,param_1);
  if (pwVar2 != (wchar_t *)0x0) {
    param_2 = pwVar2 + 1;
  }
  StringCchCopyW(awStack_430,0x104,param_2);
  pwVar1 = wcsrchr(awStack_228,L'.');
  pwVar2 = wcsrchr(awStack_430,L'.');
  if (pwVar1 != (wchar_t *)0x0) {
    *pwVar1 = L'\0';
  }
  if (pwVar2 != (wchar_t *)0x0) {
    *pwVar2 = L'\0';
  }
  iVar3 = _wcsicmp(awStack_228,awStack_430);
  FUN_0001e3d4(local_20);
  return iVar3;
}



/* 00017e38 FUN_00017e38 */

/* Boundary evidence: original MIPS .pdata 00017e38..0001800f. Semantic name remains unreviewed. */

void FUN_00017e38(wchar_t *param_1,wchar_t *param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  HMODULE hLibModule;
  size_t sVar2;
  HLOCAL pvVar3;
  DWORD DVar4;
  wchar_t *_Dest;
  undefined4 uVar5;
  int *piVar6;
  
  for (piVar6 = DAT_0001f710; piVar6 != (int *)0x0; piVar6 = (int *)*piVar6) {
    iVar1 = FUN_00017d4c((wchar_t *)piVar6[2],param_2);
    if (iVar1 == 0) {
      return;
    }
  }
  hLibModule = LoadLibraryW(param_2);
  if (hLibModule == (HMODULE)0x0) {
    DVar4 = GetLastError();
    FUN_00017be8(L"Shell: Error unable to load %s : Error %d\r\n",param_2,DVar4,param_4);
  }
  else {
    iVar1 = GetProcAddressW(hLibModule,L"ParseCommand");
    if (iVar1 == 0) {
      FUN_00017be8(L"Shell: Error unable to find %s in %s\r\n",L"ParseCommand",param_2,param_4);
    }
    else {
      uVar5 = 0x14;
      piVar6 = LocalAlloc(0x40,0x14);
      if (piVar6 == (int *)0x0) {
        FUN_00017be8(L"Unable to allocate extension block\r\n",uVar5,param_3,param_4);
      }
      else {
        sVar2 = wcslen(param_1);
        pvVar3 = LocalAlloc(0,(sVar2 + 1) * 2);
        piVar6[1] = (int)pvVar3;
        sVar2 = wcslen(param_2);
        pvVar3 = LocalAlloc(0,(sVar2 + 1) * 2);
        _Dest = (wchar_t *)piVar6[1];
        piVar6[2] = (int)pvVar3;
        if (_Dest != (wchar_t *)0x0) {
          if (pvVar3 != (HLOCAL)0x0) {
            wcscpy(_Dest,param_1);
            wcscpy((wchar_t *)piVar6[2],param_2);
            piVar6[3] = (int)hLibModule;
            piVar6[4] = iVar1;
            *piVar6 = (int)DAT_0001f710;
            DAT_0001f710 = piVar6;
            return;
          }
          if (_Dest != (wchar_t *)0x0) {
            LocalFree(_Dest);
          }
        }
        if ((HLOCAL)piVar6[2] != (HLOCAL)0x0) {
          LocalFree((HLOCAL)piVar6[2]);
        }
        LocalFree(piVar6);
      }
    }
    FreeLibrary(hLibModule);
  }
  return;
}



/* 00018010 FUN_00018010 */

/* Boundary evidence: original MIPS .pdata 00018010..000181bb. Semantic name remains unreviewed. */

void FUN_00018010(void)

{
  LSTATUS LVar1;
  wchar_t *lpValueName;
  wchar_t *lpData;
  int iVar2;
  wchar_t *pwVar3;
  LPDWORD lpcchValueName;
  DWORD dwIndex;
  HKEY local_30;
  DWORD local_2c;
  SIZE_T local_28;
  SIZE_T local_24;
  DWORD local_20;
  DWORD local_1c;
  
  LVar1 = RegOpenKeyExW((HKEY)0x80000002,L"Software\\Microsoft\\TxtShell\\Extensions",0,0,&local_30)
  ;
  if (LVar1 == 0) {
    LVar1 = RegQueryInfoKeyW(local_30,(LPWSTR)0x0,(LPDWORD)0x0,(LPDWORD)0x0,(LPDWORD)0x0,
                             (LPDWORD)0x0,(LPDWORD)0x0,(LPDWORD)0x0,&local_2c,&local_28,(LPDWORD)0x0
                             ,(PFILETIME)0x0);
    if (LVar1 == 0) {
      lpValueName = LocalAlloc(0,(local_2c + 1) * 2);
      lpData = LocalAlloc(0,local_28);
      local_20 = local_2c + 1;
      lpcchValueName = &local_20;
      dwIndex = 0;
      local_24 = local_28;
      pwVar3 = lpValueName;
      iVar2 = RegEnumValueW(local_30,0,lpValueName,lpcchValueName,(LPDWORD)0x0,&local_1c,
                            (LPBYTE)lpData,&local_24);
      while (iVar2 == 0) {
        if (local_1c == 1) {
          FUN_00017e38(lpValueName,lpData,pwVar3,lpcchValueName);
        }
        local_20 = local_2c + 1;
        dwIndex = dwIndex + 1;
        lpcchValueName = &local_20;
        local_24 = local_28;
        pwVar3 = lpValueName;
        iVar2 = RegEnumValueW(local_30,dwIndex,lpValueName,lpcchValueName,(LPDWORD)0x0,&local_1c,
                              (LPBYTE)lpData,&local_24);
      }
    }
    RegCloseKey(local_30);
  }
  return;
}



/* 000181bc FUN_000181bc */

/* Boundary evidence: original MIPS .pdata 000181bc..00018627. Semantic name remains unreviewed. */

undefined4 FUN_000181bc(undefined4 param_1,undefined4 param_2,undefined *param_3,undefined *param_4)

{
  int *piVar1;
  int *piVar2;
  
  FUN_0001e194(L"\r\nEnter any of the following commands at the prompt:\r\n");
  FUN_0001e194(L"break : Breaks into the debugger\r\n");
  FUN_0001e194(L"s <procname> : Starts new process\r\n");
  FUN_0001e194(L"gi [\"proc\",\"thrd\",\"mod\",\"all\"]* [\"<pattern>\"] : Get Information\r\n");
  FUN_0001e194(L"    proc   -> Lists all processes in the system\r\n");
  FUN_0001e194(L"    thrd   -> Lists all processes with their threads\r\n");
  FUN_0001e194(L"    delta  -> Lists only threads that have changes in CPU times\r\n");
  FUN_0001e194(L"    mod    -> Lists all modules loaded\r\n");
  FUN_0001e194(L"    moduse -> Lists module usage data\r\n");
  FUN_0001e194(L"    system -> Lists processor architecture and OS version\r\n");
  FUN_0001e194(L"    all    -> Lists all of the above\r\n");
  FUN_0001e194(L"mi [\"kernel\",\"full\"] : Memory information\r\n");
  FUN_0001e194(L"    kernel-> Lists kernel memory detail\r\n");
  FUN_0001e194(L"    full  -> Lists full memory maps\r\n");
  FUN_0001e194(
              L"zo [\"p\",\"m\",\"h\"] [index,name,handle] [<zone>,[[\"on\",\"off\"][<zoneindex>]*]*: Zone Ops\r\n"
              );
  FUN_0001e194(
              L"    p/m/h -> Selects whether you operate on a process, module, or hProcess/pModule\r\n"
              );
  FUN_0001e194(L"    index -> Put the index of the proc/module, as printed by the gi command\r\n");
  FUN_0001e194(L"    name  -> Put the name of the proc/module, as printed by the gi command\r\n");
  FUN_0001e194(
              L"    handle-> Put the value of the hProcess/pModule, as printed by the gi command\r\n"
              );
  FUN_0001e194(L"          -> If no args are specified, prints cur setting with the zone names\r\n")
  ;
  FUN_0001e194(L"    zone  -> Must be a number to which this proc/modl zones are to be set \r\n");
  FUN_0001e194(L"             Prefix by 0x if this is specified in hex\r\n");
  FUN_0001e194(L"    on/off-> Specify bits to be turned on/off relative to the current zonemask\r\n"
              );
  FUN_0001e194(L"  eg. zo p 2: Prints zone names for the proc at index 2 in the proc list \r\n");
  FUN_0001e194(
              L"  eg. zo h 8fe773a2: Prints zone names for the proc/module with hProcess/pModule of 8fe773a2\r\n"
              );
  FUN_0001e194(L"  eg. zo m 0 0x100: Sets zone for module at index 0 to 0x100 \r\n");
  FUN_0001e194(L"  eg. zo p 3 on 3 5 off 2: Sets bits 3&5 on, and bit 2 off for the proc[3]\r\n");
  FUN_0001e194(L"win : Dumps the list of windows\r\n");
  FUN_0001e194(L"log <CE zone> [user zone] [process zone] : Change CeLog zone settings\r\n");
  FUN_0001e194(L"prof <on|off> [data_type] [storage_type] : Start or stop kernel profiler\r\n");
  FUN_0001e194(L"memtrack (deprecated; use Application Verifier instead)\r\n");
  FUN_0001e194(L"kp <pid> [<pid2> <pid3> ...]: Kills process(es)\r\n");
  FUN_0001e194(L"dd <process id> <addr> [<#dwords>]: dumps dwords for specified process id\r\n");
  FUN_0001e194(L"df <filename> <process id> <addr> <size>: dumps address of a process to file\r\n");
  FUN_0001e194(L"hd <exe>: dumps the process heap\r\n");
  FUN_0001e194(L"run <filename>: run file in batch mode\r\n");
  FUN_0001e194(L"dis: Discard all discardable memory\r\n");
  FUN_0001e194(L"options: Set options\r\n");
  FUN_0001e194(L"     timestamp     -> Toggle timestamp on all cmds (useful for logs)\r\n");
  FUN_0001e194(L"     priority [N]  -> Change the priority of the shell thread\r\n");
  FUN_0001e194(L"     kernfault     -> Fault even if NOFAULT specified\r\n");
  FUN_0001e194(L"     kernnofault   -> Re-enable default NOFAULT handling\r\n");
  FUN_0001e194(L"suspend: Suspend the device.  Requires GWES.exe and proper OAL support\r\n");
  FUN_0001e194(L"loadext [[-u] DLLName] : Load shell.exe extension dll\r\n");
  FUN_0001e194(L"    -u : unload extension dll\r\n");
  FUN_0001e194(L"    DLLName : name of DLL to load (i.e. shellext.dll)\r\n");
  FUN_0001e194(L"tp <tid> [prio] : Sets/queries thread priority\r\n");
  FUN_0001e194(L"    tid  : can be either a thread id, \'kitlintr\' or \'kitltimer\'\r\n");
  FUN_0001e194(L"    prio : thread priority\r\n");
  FUN_0001e194(L"           -1 or omitted : query current thread priority\r\n");
  FUN_0001e194(L"           0 - 255       : set thread priority\r\n");
  FUN_0001e194(L"\r\n");
  FUN_00018010();
  for (piVar1 = (int *)DAT_0001f710; piVar1 != (int *)0x0; piVar1 = (int *)*piVar1) {
    piVar2 = piVar1;
    FUN_00017be8(L"Extension: %s\r\n",piVar1[2],param_3,param_4);
    param_3 = FUN_00017be8;
    param_4 = FUN_0001e0b4;
    (*(code *)piVar1[4])(&UNK_00011f88,&DAT_00011f84,FUN_00017be8,FUN_0001e0b4,piVar2);
  }
  return 1;
}



/* 00018628 FUN_00018628 */

/* Boundary evidence: original MIPS .pdata 00018628..00018633. Semantic name remains unreviewed. */

undefined4 FUN_00018628(void)

{
  return 1;
}



/* 00018634 FUN_00018634 */

/* Boundary evidence: original MIPS .pdata 00018634..000187ab. Semantic name remains unreviewed. */

int FUN_00018634(int *param_1,undefined4 *param_2)

{
  short sVar1;
  size_t sVar2;
  wchar_t *_Str;
  size_t sVar3;
  int iVar4;
  int iVar5;
  wchar_t *_Str2;
  uint uVar6;
  
  while( true ) {
    sVar1 = *(short *)*param_1;
    if (((sVar1 != 0x20) && (sVar1 != 0xd)) && (sVar1 != 10)) break;
    *param_1 = (int)((short *)*param_1 + 1);
  }
  sVar2 = wcslen((wchar_t *)*param_1);
  iVar5 = sVar2 << 1;
  while( true ) {
    sVar1 = *(short *)(iVar5 + *param_1 + -2);
    if (((sVar1 != 0x20) && (sVar1 != 0xd)) && (sVar1 != 10)) break;
    *(undefined2 *)(iVar5 + *param_1 + -2) = 0;
    sVar2 = sVar2 - 1;
    iVar5 = iVar5 + -2;
  }
  _Str = wcstok((wchar_t *)*param_1,L" ");
  *param_2 = _Str;
  if ((_Str == (wchar_t *)0x0) || (*_Str == L'\0')) {
    iVar5 = -2;
  }
  else {
    sVar3 = wcslen(_Str);
    if (sVar2 == sVar3) {
      *param_1 = 0;
    }
    else {
      sVar2 = wcslen(_Str);
      *param_1 = (sVar2 + 1) * 2 + *param_1;
    }
    iVar5 = 0;
    _Str2 = L"exit";
    uVar6 = 0;
    do {
      iVar4 = wcscmp(_Str,_Str2);
      if (iVar4 == 0) {
        return iVar5;
      }
      uVar6 = uVar6 + 0x48;
      iVar5 = iVar5 + 1;
      _Str2 = _Str2 + 0x24;
    } while (uVar6 < 0x708);
    iVar5 = -1;
  }
  return iVar5;
}



/* 000187ac FUN_000187ac */

/* Boundary evidence: original MIPS .pdata 000187ac..00018a0f. Semantic name remains unreviewed. */

undefined4 FUN_000187ac(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  int local_258;
  undefined4 local_254;
  int local_250;
  int local_24c;
  int local_248;
  _SYSTEMTIME local_240;
  wchar_t awStack_230 [260];
  uint local_28;
  
  local_28 = DAT_0001f184;
  local_258 = param_1;
  iVar1 = FUN_00018634(&local_258,&local_254);
  if (iVar1 == -2) {
    uVar2 = 1;
  }
  else if (iVar1 == -1) {
    local_250 = 0;
    uVar2 = 1;
    piVar3 = DAT_0001f710;
    iVar1 = local_250;
LAB_000188fc:
    for (; local_24c = (int)piVar3, piVar3 != (int *)0x0; piVar3 = (int *)*piVar3) {
      local_248 = (*(code *)piVar3[4])(local_254,local_258,FUN_00017be8,FUN_0001e0b4);
      if (local_248 != 0) {
        if (piVar3 == (int *)0x0) break;
        goto LAB_000189d0;
      }
    }
    if (iVar1 == 0) {
      FUN_00018010();
      local_250 = 1;
      piVar3 = DAT_0001f710;
      iVar1 = local_250;
      goto LAB_000188fc;
    }
    FUN_0001e194(L"Unknown command.\r\n\r\n");
  }
  else {
    if (((-1 < iVar1) && (iVar1 < 0x19)) && (DAT_0001f70c != 0)) {
      GetLocalTime(&local_240);
      StringCbPrintfW(awStack_230,0x208,L"%02d/%02d/%02d %d:%02d:%02d.%03d\r\n",
                      (uint)local_240.wMonth,(uint)local_240.wDay,(uint)local_240.wYear,
                      (uint)local_240.wHour,(uint)local_240.wMinute,(uint)local_240.wSecond,
                      (uint)local_240.wMilliseconds);
      FUN_0001e194(awStack_230);
    }
    uVar2 = (*(code *)(&PTR_LAB_00011394)[iVar1 * 0x12])(local_258);
  }
LAB_000189d0:
  FUN_0001e3d4(local_28);
  return uVar2;
}



/* 00018a10 FUN_00018a10 */

/* Boundary evidence: original MIPS .pdata 00018a10..00018a1b. Semantic name remains unreviewed. */

undefined4 FUN_00018a10(void)

{
  return 1;
}



/* 00018a24 FUN_00018a24 */

/* Boundary evidence: original MIPS .pdata 00018a24..00018c67. Semantic name remains unreviewed. */

BOOL FUN_00018a24(LPWSTR param_1,STRSAFE_LPWSTR param_2,size_t param_3,LPPROCESS_INFORMATION param_4
                 )

{
  HRESULT HVar1;
  size_t sVar2;
  size_t sVar3;
  int iVar4;
  BOOL BVar5;
  LPWSTR lpCommandLine;
  bool bVar6;
  
  bVar6 = false;
  if ((((param_1 == (LPWSTR)0x0) || (param_2 == (STRSAFE_LPWSTR)0x0)) ||
      (param_4 == (LPPROCESS_INFORMATION)0x0)) || (param_3 == 0)) {
    SetLastError(0x57);
    return 0;
  }
  while ((*param_1 != L'\0' && (iVar4 = iswctype(*param_1,8), iVar4 != 0))) {
    param_1 = param_1 + 1;
  }
  lpCommandLine = param_1;
  if (*param_1 == L'\"') {
    param_1 = param_1 + 1;
    for (lpCommandLine = param_1; (*lpCommandLine != L'\0' && (*lpCommandLine != L'\"'));
        lpCommandLine = lpCommandLine + 1) {
    }
    if (*lpCommandLine == L'\0') goto LAB_00018b6c;
LAB_00018b60:
    *lpCommandLine = L'\0';
    lpCommandLine = lpCommandLine + 1;
  }
  else {
    while ((*lpCommandLine != L'\0' && (iVar4 = iswctype(*lpCommandLine,8), iVar4 == 0))) {
      lpCommandLine = lpCommandLine + 1;
    }
    if (*lpCommandLine != L'\0') goto LAB_00018b60;
  }
  bVar6 = true;
LAB_00018b6c:
  HVar1 = StringCchCopyW(param_2,param_3,param_1);
  if (HVar1 != 0) {
    bVar6 = false;
  }
  BVar5 = 0;
  if (bVar6) {
    while ((*lpCommandLine != L'\0' && (iVar4 = iswctype(*lpCommandLine,8), iVar4 != 0))) {
      lpCommandLine = lpCommandLine + 1;
    }
    sVar2 = wcslen(param_2);
    sVar3 = wcslen(L".exe");
    bVar6 = true;
    if (((sVar2 < sVar3) || (iVar4 = _wcsicmp(param_2 + (sVar2 - sVar3),L".exe"), iVar4 != 0)) &&
       (HVar1 = StringCchCatW(param_2,param_3,L".exe"), HVar1 != 0)) {
      bVar6 = false;
      SetLastError(0x57);
    }
    BVar5 = 0;
    if (bVar6) {
      BVar5 = CreateProcessW(param_2,lpCommandLine,(LPSECURITY_ATTRIBUTES)0x0,
                             (LPSECURITY_ATTRIBUTES)0x0,0,0,(LPVOID)0x0,(LPCWSTR)0x0,
                             (LPSTARTUPINFOW)0x0,param_4);
    }
  }
  return BVar5;
}



/* 00018c68 FUN_00018c68 */

/* Boundary evidence: original MIPS .pdata 00018c68..00018e63. Semantic name remains unreviewed. */

undefined4 FUN_00018c68(LPWSTR param_1)

{
  short sVar1;
  DWORD DVar2;
  undefined2 *puVar3;
  BOOL BVar4;
  LPPROCESS_INFORMATION p_Var5;
  short *psVar6;
  int iVar7;
  _PROCESS_INFORMATION local_448;
  short local_438 [260];
  wchar_t awStack_230 [260];
  uint local_28;
  
  local_28 = DAT_0001f184;
  if (param_1 == (LPWSTR)0x0) {
    FUN_0001e194(L"Syntax: s <procname>\r\n\r\n");
  }
  else {
    if ((DAT_0001f2b0 == 0) && (DAT_0001f284 != (HANDLE)0x0)) {
      DVar2 = WaitForSingleObject(DAT_0001f284,0);
      while (DVar2 != 0) {
        FUN_0001e194(L"\r\nGWES has not been started yet, run anyway (y or n)?");
        puVar3 = FUN_0001e0b4(local_438,0x104);
        if (puVar3 == (undefined2 *)0x0) goto LAB_00018e30;
        iVar7 = 0;
        for (psVar6 = local_438;
            ((sVar1 = *psVar6, sVar1 == 0x20 || (sVar1 == 0xd)) || (sVar1 == 10));
            psVar6 = psVar6 + 1) {
          iVar7 = iVar7 + 1;
        }
        sVar1 = local_438[iVar7];
        if ((sVar1 == 0x59) || (sVar1 == 0x79)) {
          DAT_0001f2b0 = 1;
          break;
        }
        if ((sVar1 == 0x4e) || (sVar1 == 0x6e)) goto LAB_00018e30;
        FUN_0001e194(L"Enter Y or N\r\n");
        DVar2 = WaitForSingleObject(DAT_0001f284,0);
      }
    }
    p_Var5 = &local_448;
    BVar4 = FUN_00018a24(param_1,awStack_230,0x104,p_Var5);
    if (BVar4 == 0) {
      DVar2 = GetLastError();
      FUN_00017be8(L"Unable to create process \'%s\' : Error 0x%X\r\n",awStack_230,DVar2,p_Var5);
    }
    else {
      CloseHandle(local_448.hProcess);
      CloseHandle(local_448.hThread);
    }
  }
LAB_00018e30:
  FUN_0001e3d4(local_28);
  return 1;
}



/* 00018e64 FUN_00018e64 */

/* Boundary evidence: original MIPS .pdata 00018e64..00018ecb. Semantic name remains unreviewed. */

void FUN_00018e64(undefined4 param_1,undefined4 *param_2)

{
  StringCbPrintfW((STRSAFE_LPWSTR)&DAT_0001f2e0,DAT_0001f18c,L"%08X: %08X %08X %08X %08X\r\n",
                  param_1,*param_2,param_2[1],param_2[2],param_2[3]);
  FUN_0001e194((wchar_t *)&DAT_0001f2e0);
  return;
}



/* 00018ecc FUN_00018ecc */

/* Boundary evidence: original MIPS .pdata 00018ecc..00019053. Semantic name remains unreviewed. */

undefined4 FUN_00018ecc(HANDLE param_1,DWORD param_2,LPCVOID param_3,uint param_4)

{
  HANDLE hProcess;
  BOOL BVar1;
  wchar_t *pwVar2;
  undefined4 uVar3;
  SIZE_T nSize;
  undefined4 *puVar4;
  DWORD local_428;
  DWORD local_424;
  undefined4 auStack_420 [256];
  
  hProcess = OpenProcess(0x10,0,param_2);
  if (hProcess == (HANDLE)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = 1;
    do {
      while( true ) {
        if ((int)param_4 < 1) goto LAB_00019018;
        nSize = 0x400;
        if (param_4 < 0x401) {
          nSize = param_4;
        }
        BVar1 = ReadProcessMemory(hProcess,param_3,auStack_420,nSize,&local_428);
        if ((BVar1 == 0) || (nSize != local_428)) {
          pwVar2 = L"Unable to read process memory\r\n";
          goto LAB_0001900c;
        }
        param_4 = param_4 - local_428;
        if (param_1 != (HANDLE)0xffffffff) break;
        puVar4 = auStack_420;
        for (; 0 < (int)local_428; local_428 = local_428 - 0x10) {
          FUN_00018e64(param_3,puVar4);
          puVar4 = puVar4 + 4;
          param_3 = (LPCVOID)((int)param_3 + 0x10);
        }
      }
      BVar1 = WriteFile(param_1,auStack_420,local_428,&local_424,(LPOVERLAPPED)0x0);
      if (BVar1 == 0) {
        local_424 = 0;
      }
    } while (local_424 == local_428);
    pwVar2 = L"Error Writing file\r\n";
LAB_0001900c:
    FUN_0001e194(pwVar2);
    uVar3 = 0;
LAB_00019018:
    CloseHandle(hProcess);
  }
  return uVar3;
}



/* 00019054 FUN_00019054 */

/* Boundary evidence: original MIPS .pdata 00019054..00019223. Semantic name remains unreviewed. */

undefined4 FUN_00019054(wchar_t *param_1)

{
  HANDLE hObject;
  int iVar1;
  wchar_t *pwVar2;
  ulong uVar3;
  LPCVOID pvVar4;
  ulong uVar5;
  wchar_t local_430 [260];
  wchar_t awStack_228 [260];
  uint local_20;
  
  local_20 = DAT_0001f184;
  pvVar4 = (LPCVOID)0x0;
  uVar3 = 0;
  uVar5 = 0;
  if (param_1 == (wchar_t *)0x0) {
LAB_00019088:
    pwVar2 = L"Syntax: df <filename> <process id> <addr> <size>\r\n";
  }
  else {
    local_430[0] = L'\0';
    pwVar2 = wcstok(param_1,L" \t");
    if (pwVar2 != (wchar_t *)0x0) {
      StringCbCopyW(local_430,0x208,pwVar2);
      pwVar2 = wcstok((wchar_t *)0x0,L" \t");
      if (pwVar2 != (wchar_t *)0x0) {
        uVar5 = wcstoul(pwVar2,(wchar_t **)0x0,0x10);
        pwVar2 = wcstok((wchar_t *)0x0,L" \t");
        if (pwVar2 != (wchar_t *)0x0) {
          pvVar4 = (LPCVOID)wcstoul(pwVar2,(wchar_t **)0x0,0x10);
          pwVar2 = wcstok((wchar_t *)0x0,L" \t");
          if (pwVar2 != (wchar_t *)0x0) {
            uVar3 = wcstoul(pwVar2,(wchar_t **)0x0,0x10);
            goto LAB_00019138;
          }
        }
      }
      goto LAB_00019088;
    }
LAB_00019138:
    if ((((local_430[0] == L'\0') || (uVar5 == 0)) || (pvVar4 == (LPCVOID)0x0)) || (uVar3 == 0)) {
      pwVar2 = L"Error: invalid parameters.\r\n";
    }
    else {
      hObject = FUN_00017ac0(local_430,0x80001);
      if (hObject != (HANDLE)0xffffffff) {
        iVar1 = FUN_00018ecc(hObject,uVar5,pvVar4,uVar3);
        if (iVar1 == 0) {
          pwVar2 = L"Error reading image physical start from file.\r\n";
        }
        else {
          pwVar2 = L"Write complete.\r\n";
        }
        FUN_0001e194(pwVar2);
        CloseHandle(hObject);
        goto LAB_000191fc;
      }
      StringCbPrintfW(awStack_228,0x208,L"Unable to open input file %s\r\n",local_430);
      pwVar2 = awStack_228;
    }
  }
  FUN_0001e194(pwVar2);
LAB_000191fc:
  FUN_0001e3d4(local_20);
  return 1;
}



/* 00019224 FUN_00019224 */

/* Boundary evidence: original MIPS .pdata 00019224..000192a3. Semantic name remains unreviewed. */

bool FUN_00019224(wchar_t *param_1,wchar_t *param_2)

{
  wchar_t *pwVar1;
  bool bVar2;
  wchar_t awStack_218 [259];
  undefined2 local_12;
  uint local_10;
  
  local_10 = DAT_0001f184;
  if (param_1 == (wchar_t *)0x0) {
    FUN_0001e3d4(DAT_0001f184);
    bVar2 = true;
  }
  else {
    wcsncpy(awStack_218,param_2,0x103);
    local_12 = 0;
    _wcslwr(awStack_218);
    pwVar1 = wcsstr(awStack_218,param_1);
    bVar2 = pwVar1 != (wchar_t *)0x0;
    FUN_0001e3d4(local_10);
  }
  return bVar2;
}



/* 000192a4 FUN_000192a4 */

/* Boundary evidence: original MIPS .pdata 000192a4..000193af. Semantic name remains unreviewed. */

undefined4 FUN_000192a4(wchar_t *param_1,wchar_t *param_2)

{
  size_t sVar1;
  size_t sVar2;
  uint uVar3;
  wchar_t *pwVar4;
  wchar_t local_220 [259];
  undefined2 local_1a;
  uint local_18;
  
  local_18 = DAT_0001f184;
  if ((param_1 != (wchar_t *)0x0) && (param_2 != (wchar_t *)0x0)) {
    sVar1 = wcslen(param_1);
    sVar2 = wcslen(param_2);
    if ((sVar2 < 0x104) && (sVar1 <= sVar2)) {
      wcsncpy(local_220,param_2,0x103);
      local_1a = 0;
      _wcslwr(local_220);
      uVar3 = 0;
      if (sVar1 != 0) {
        pwVar4 = local_220;
        do {
          if (*(wchar_t *)(((int)param_1 - (int)local_220) + (int)pwVar4) != *pwVar4)
          goto LAB_0001938c;
          uVar3 = uVar3 + 1;
          pwVar4 = pwVar4 + 1;
        } while (uVar3 < sVar1);
      }
      if (local_220[sVar1] == L'.') {
        FUN_0001e3d4(local_18);
        return 1;
      }
    }
  }
LAB_0001938c:
  FUN_0001e3d4(local_18);
  return 0;
}



/* 000193b0 FUN_000193b0 */

/* Boundary evidence: original MIPS .pdata 000193b0..00019543. Semantic name remains unreviewed. */

void FUN_000193b0(undefined4 param_1)

{
  undefined4 *hMem;
  int *piVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  HLOCAL pvVar5;
  int *piVar6;
  wchar_t *_Str1;
  undefined4 local_458;
  int local_454;
  int local_448;
  int local_444;
  undefined1 auStack_438 [1040];
  int local_28;
  uint local_24;
  
  local_24 = DAT_0001f184;
  hMem = DAT_0001f6e4;
  while (hMem != (HLOCAL)0x0) {
    pvVar5 = (HLOCAL)*hMem;
    LocalFree(hMem);
    hMem = pvVar5;
  }
  DAT_0001f6e4 = (int *)0x0;
  local_458 = 0x434;
  DAT_0001f704 = 0;
  iVar3 = Module32First(param_1,&local_458);
  do {
    if (iVar3 == 0) {
      FUN_0001e3d4(local_24);
      return;
    }
    piVar4 = LocalAlloc(0x40,0x220);
    piVar2 = DAT_0001f6e4;
    if (piVar4 != (int *)0x0) {
      _Str1 = (wchar_t *)(piVar4 + 6);
      piVar4[1] = local_454;
      piVar4[2] = local_28;
      piVar4[3] = local_448;
      piVar4[4] = local_444;
      piVar4[5] = local_28;
      memcpy(_Str1,auStack_438,0x208);
      piVar6 = DAT_0001f6e4;
      piVar2 = piVar4;
      if (DAT_0001f6e4 != (int *)0x0) {
        iVar3 = wcscmp(_Str1,(wchar_t *)(DAT_0001f6e4 + 6));
        if (iVar3 < 0) {
          *piVar4 = (int)piVar6;
        }
        else {
          do {
            piVar1 = piVar6;
            piVar2 = DAT_0001f6e4;
            if (piVar1 == (int *)0x0) goto LAB_000194f4;
            piVar6 = (int *)*piVar1;
          } while ((piVar6 != (int *)0x0) &&
                  (iVar3 = wcscmp(_Str1,(wchar_t *)(piVar6 + 6)), -1 < iVar3));
          *piVar4 = *piVar1;
          *piVar1 = (int)piVar4;
          piVar2 = DAT_0001f6e4;
        }
      }
    }
LAB_000194f4:
    DAT_0001f6e4 = piVar2;
    DAT_0001f704 = DAT_0001f704 + 1;
    iVar3 = Module32Next(param_1,&local_458);
  } while( true );
}



/* 00019544 FUN_00019544 */

/* Boundary evidence: original MIPS .pdata 00019544..0001a057. Semantic name remains unreviewed. */

undefined4 FUN_00019544(wchar_t *param_1,undefined4 param_2,wchar_t *param_3,LPFILETIME param_4)

{
  bool bVar1;
  bool bVar2;
  _FILETIME _Var3;
  bool bVar4;
  bool bVar5;
  wchar_t *pwVar6;
  int iVar7;
  int iVar8;
  undefined3 extraout_var;
  undefined4 *puVar9;
  int iVar10;
  HANDLE hThread;
  BOOL BVar11;
  size_t sVar12;
  int iVar13;
  undefined3 extraout_var_00;
  DWORD DVar14;
  undefined4 uVar15;
  undefined4 *puVar16;
  uint uVar17;
  uint uVar18;
  undefined4 *hMem;
  undefined4 *puVar19;
  HLOCAL pvVar20;
  wchar_t *_Str;
  int *piVar21;
  undefined8 uVar22;
  undefined8 uVar23;
  undefined8 uVar24;
  undefined8 uVar25;
  _FILETIME _Var26;
  LPCWSTR local_41c;
  _FILETIME local_418;
  _FILETIME local_410;
  wchar_t *local_408;
  int local_404;
  undefined4 *local_400;
  undefined4 local_3f4;
  int local_3f0;
  _FILETIME local_3e8;
  LPFILETIME local_3e0;
  _FILETIME local_3d8;
  int local_3d0;
  undefined4 *local_3cc;
  undefined4 local_3c8 [2];
  DWORD local_3c0;
  int local_3bc;
  int local_3b8;
  int local_3b4;
  int local_3b0;
  undefined4 local_3ac;
  undefined4 local_3a8;
  _union_530 local_3a0 [6];
  undefined4 local_388;
  undefined4 local_378 [2];
  int local_370;
  undefined4 local_358;
  wchar_t awStack_354 [260];
  undefined4 local_14c;
  undefined4 local_148;
  _OSVERSIONINFOW local_140;
  uint local_2c;
  
  local_2c = DAT_0001f184;
  uVar18 = 0xc000000e;
  _Str = (wchar_t *)0x0;
  bVar2 = true;
  bVar1 = true;
  bVar4 = true;
  bVar5 = true;
  local_404 = -1;
  local_408 = (wchar_t *)0x0;
  local_3f0 = 0;
  if (param_1 != (wchar_t *)0x0) {
    bVar2 = false;
    bVar1 = false;
    bVar4 = false;
    bVar5 = false;
    uVar18 = 0;
    puVar16 = (undefined4 *)&DAT_00013a58;
    pwVar6 = wcstok(param_1,L" \t");
    iVar7 = -1;
    if (pwVar6 == (wchar_t *)0x0) goto LAB_000197ec;
    local_41c = L"silent";
    local_408 = L"proc";
    bVar5 = false;
    bVar4 = false;
    bVar1 = false;
    bVar2 = false;
    do {
      iVar7 = wcscmp(pwVar6,local_408);
      if (iVar7 == 0) {
        bVar4 = true;
        uVar17 = 0x40000002;
LAB_000196f8:
        uVar18 = uVar18 | uVar17;
      }
      else {
        iVar7 = wcscmp(pwVar6,L"thrd");
        if (iVar7 == 0) {
LAB_00019694:
          bVar1 = true;
          bVar4 = true;
          uVar17 = 0x40000006;
          goto LAB_000196f8;
        }
        iVar7 = wcscmp(pwVar6,L"mod");
        if (iVar7 == 0) {
          bVar5 = true;
          uVar17 = 0x80000008;
          goto LAB_000196f8;
        }
        iVar7 = wcscmp(pwVar6,L"delta");
        if (iVar7 == 0) {
          local_3f0 = 1;
          goto LAB_00019694;
        }
        iVar7 = wcscmp(pwVar6,L"all");
        if (iVar7 == 0) {
          bVar2 = true;
          bVar1 = true;
          bVar4 = true;
          bVar5 = true;
          uVar17 = 0xc000000e;
          goto LAB_000196f8;
        }
        iVar7 = wcscmp(pwVar6,L"silent");
        if (iVar7 == 0) {
          bVar4 = true;
          bVar5 = true;
          uVar17 = 0xc000000a;
          goto LAB_000196f8;
        }
        if ((*pwVar6 == L'\"') && (_Str == (wchar_t *)0x0)) {
          _Str = pwVar6 + 1;
          sVar12 = wcslen(_Str);
          if ((sVar12 != 0) && (sVar12 = wcslen(_Str), _Str[sVar12 - 1] == L'\"')) {
            sVar12 = wcslen(_Str);
            _Str[sVar12 - 1] = L'\0';
          }
        }
        else {
          iVar7 = wcscmp(pwVar6,L"system");
          if (iVar7 == 0) {
            bVar2 = true;
          }
          else {
            FUN_0001e194(
                        L"Invalid argument.  Must be one of proc, thrd, delta, mod, moduse, system or all.\r\n\r\n"
                        );
          }
        }
      }
      puVar16 = (undefined4 *)&DAT_00013a58;
      pwVar6 = wcstok((wchar_t *)0x0,L" \t");
    } while (pwVar6 != (wchar_t *)0x0);
    iVar7 = local_404;
    local_408 = _Str;
    if (uVar18 == 0) goto LAB_000197ec;
  }
  _Str = local_408;
  puVar16 = (undefined4 *)0x0;
  iVar7 = CreateToolhelp32Snapshot(uVar18);
  local_404 = iVar7;
  if ((uVar18 & 8) != 0) {
    FUN_000193b0(iVar7);
  }
LAB_000197ec:
  hMem = DAT_00020920;
  pwVar6 = L"Unable to obtain process/thread snapshot (%d)!\r\n";
  local_41c = L"Unable to obtain process/thread snapshot (%d)!\r\n";
  if (bVar4) {
    if (iVar7 == -1) {
      puVar16 = (undefined4 *)GetLastError();
      FUN_00017be8(L"Unable to obtain process/thread snapshot (%d)!\r\n",puVar16,param_3,param_4);
    }
    else {
      puVar16 = local_378;
      local_378[0] = 0x234;
      puVar19 = (undefined4 *)0x0;
      local_400 = DAT_00020920;
      DAT_00020920 = (undefined4 *)0x0;
      iVar8 = Process32First(iVar7);
      pwVar6 = local_41c;
      if (iVar8 != 0) {
        DAT_0001f2c8 = (LPFILETIME)0x0;
        StringCbPrintfW((STRSAFE_LPWSTR)&DAT_0001f2e0,DAT_0001f18c,
                        L"PROC: Name            hProcess: CurAKY :dwVMBase:CurZone\r\n");
        FUN_0001e194((wchar_t *)&DAT_0001f2e0);
        if (bVar1) {
          StringCbPrintfW((STRSAFE_LPWSTR)&DAT_0001f2e0,DAT_0001f18c,
                          L"THRD: State :hCurThrd:hCurProc: CurAKY :Cp :Bp :Kernel Time  User Time\r\n"
                         );
          FUN_0001e194((wchar_t *)&DAT_0001f2e0);
        }
        local_3e0 = (LPFILETIME)0x13dc4;
        do {
          param_3 = (wchar_t *)local_3e0;
          bVar4 = FUN_00019224(_Str,awStack_354);
          iVar8 = CONCAT31(extraout_var,bVar4);
          param_4 = DAT_0001f2c8;
          local_3d0 = iVar8;
          StringCbPrintfW((STRSAFE_LPWSTR)&DAT_0001f2e0,DAT_0001f18c,param_3,DAT_0001f2c8,
                          awStack_354,local_370,local_148,local_14c,local_358);
          puVar16 = (undefined4 *)0x21c;
          puVar9 = LocalAlloc(0x40,0x21c);
          if (puVar9 == (undefined4 *)0x0) {
            FUN_0001e194(L"Shell: Error unable allocate PROCDATA structure\r\n");
            break;
          }
          puVar16 = puVar9;
          if (puVar19 != (undefined4 *)0x0) {
            *puVar19 = puVar9;
            puVar16 = DAT_00020920;
          }
          DAT_00020920 = puVar16;
          puVar9[1] = local_370;
          puVar9[3] = local_148;
          param_3 = (wchar_t *)0x208;
          puVar9[2] = local_358;
          local_3cc = puVar9;
          memcpy(puVar9 + 5,awStack_354,0x208);
          DAT_0001f2c8 = (LPFILETIME)((int)&DAT_0001f2c8->dwLowDateTime + 1);
          puVar19 = puVar9;
          if (iVar8 != 0) {
            FUN_0001e194((wchar_t *)&DAT_0001f2e0);
            if (bVar1) {
              local_3c8[0] = 0x24;
              iVar10 = Thread32First(iVar7,local_3c8);
              iVar13 = local_3f0;
              while (iVar10 != 0) {
                _Var26 = local_418;
                _Var3 = local_410;
                if (local_3bc == local_370) {
                  puVar16 = LocalAlloc(0x40,0x1c);
                  if (puVar16 != (undefined4 *)0x0) {
                    puVar16[1] = local_3c0;
                    *puVar16 = puVar9[4];
                    puVar9[4] = puVar16;
                  }
                  piVar21 = (int *)0x0;
                  if (hMem != (undefined4 *)0x0) {
LAB_000199f8:
                    if (hMem[1] != puVar9[1]) goto code_r0x00019a04;
                    for (piVar21 = (int *)hMem[4];
                        (piVar21 != (int *)0x0 && (piVar21[1] != local_3c0));
                        piVar21 = (int *)*piVar21) {
                    }
                  }
LAB_00019a3c:
                  StringCbPrintfW((STRSAFE_LPWSTR)&DAT_0001f2e0,DAT_0001f18c,
                                  L" T    %6.6s %8.8lx %8.8lx %8.8lx %3d %3d",
                                  L"Runing " + local_3b0 * 0x10,local_3c0,local_3a8,local_3ac,
                                  local_3b8 - local_3b4,local_3b8);
                  hThread = OpenThread(0,0,local_3c0);
                  param_4 = &local_410;
                  param_3 = (wchar_t *)&local_3e8;
                  BVar11 = GetThreadTimes(hThread,&local_3d8,(LPFILETIME)param_3,param_4,&local_418)
                  ;
                  CloseHandle(hThread);
                  if (BVar11 == 0) {
                    sVar12 = wcslen((wchar_t *)&DAT_0001f2e0);
                    param_3 = L" No Thread Time\r\n";
                    StringCbPrintfW((STRSAFE_LPWSTR)(&DAT_0001f2e0 + sVar12 * 2),
                                    DAT_0001f18c + sVar12 * -2,L" No Thread Time\r\n");
                  }
                  else {
                    _Var26 = local_418;
                    _Var3 = local_410;
                    local_3e8 = local_3e8;
                    local_3d8 = local_3d8;
                    if (puVar16 != (undefined4 *)0x0) {
                      if ((iVar13 != 0) && (piVar21 != (int *)0x0)) {
                        _Var3 = (_FILETIME)((longlong)local_410 - *(longlong *)((int)piVar21 + 8));
                        _Var26 = (_FILETIME)
                                 ((longlong)local_418 - *(longlong *)((int)piVar21 + 0x10));
                      }
                      *(_FILETIME *)(puVar16 + 2) = local_410;
                      *(_FILETIME *)(puVar16 + 4) = local_418;
                      local_3e8 = local_418;
                      local_3d8 = local_410;
                      if (((iVar13 != 0) && (_Var3 == (_FILETIME)0x0)) &&
                         (hMem = local_400, _Var26 == (_FILETIME)0x0)) goto LAB_00019df8;
                    }
                    local_410.dwHighDateTime = _Var3.dwHighDateTime;
                    local_410.dwLowDateTime = _Var3.dwLowDateTime;
                    local_418 = _Var26;
                    uVar22 = __ll_div(local_410.dwLowDateTime,local_410.dwHighDateTime,10000,0);
                    local_410 = _Var3;
                    uVar15 = (undefined4)((ulonglong)uVar22 >> 0x20);
                    uVar23 = __ll_rem((int)uVar22,uVar15,1000,0);
                    local_3f4 = (undefined4)((ulonglong)uVar23 >> 0x20);
                    uVar22 = __ll_div((int)uVar22,uVar15,1000,0);
                    uVar15 = (undefined4)((ulonglong)uVar22 >> 0x20);
                    uVar24 = __ll_rem((int)uVar22,uVar15,0x3c,0);
                    local_3f4 = (undefined4)((ulonglong)uVar24 >> 0x20);
                    uVar22 = __ll_div((int)uVar22,uVar15,0x3c,0);
                    uVar15 = (undefined4)((ulonglong)uVar22 >> 0x20);
                    uVar25 = __ll_rem((int)uVar22,uVar15,0x3c,0);
                    local_3f4 = (undefined4)((ulonglong)uVar25 >> 0x20);
                    _Var26 = (_FILETIME)__ll_div((int)uVar22,uVar15,0x3c,0);
                    local_410 = _Var26;
                    sVar12 = wcslen((wchar_t *)&DAT_0001f2e0);
                    StringCbPrintfW((STRSAFE_LPWSTR)(&DAT_0001f2e0 + sVar12 * 2),
                                    DAT_0001f18c + sVar12 * -2,L" %2.2d:%2.2d:%2.2d.%3.3d",
                                    _Var26.dwLowDateTime,(int)uVar25,(int)uVar24,(int)uVar23);
                    uVar22 = __ll_div(local_418.dwLowDateTime,local_418.dwHighDateTime,10000,0);
                    uVar15 = (undefined4)((ulonglong)uVar22 >> 0x20);
                    uVar23 = __ll_rem((int)uVar22,uVar15,1000,0);
                    local_3f4 = (undefined4)((ulonglong)uVar23 >> 0x20);
                    uVar22 = __ll_div((int)uVar22,uVar15,1000,0);
                    uVar15 = (undefined4)((ulonglong)uVar22 >> 0x20);
                    uVar24 = __ll_rem((int)uVar22,uVar15,0x3c,0);
                    local_3f4 = (undefined4)((ulonglong)uVar24 >> 0x20);
                    uVar22 = __ll_div((int)uVar22,uVar15,0x3c,0);
                    uVar15 = (undefined4)((ulonglong)uVar22 >> 0x20);
                    uVar25 = __ll_rem((int)uVar22,uVar15,0x3c,0);
                    local_3f4 = (undefined4)((ulonglong)uVar25 >> 0x20);
                    _Var26 = (_FILETIME)__ll_div((int)uVar22,uVar15,0x3c,0);
                    param_4 = (LPFILETIME)_Var26.dwLowDateTime;
                    local_418 = _Var26;
                    sVar12 = wcslen((wchar_t *)&DAT_0001f2e0);
                    param_3 = L" %2.2d:%2.2d:%2.2d.%3.3d\r\n";
                    StringCbPrintfW((STRSAFE_LPWSTR)(&DAT_0001f2e0 + sVar12 * 2),
                                    DAT_0001f18c + sVar12 * -2,L" %2.2d:%2.2d:%2.2d.%3.3d\r\n",
                                    param_4,(int)uVar25,(int)uVar24,(int)uVar23);
                    iVar7 = local_404;
                  }
                  FUN_0001e194((wchar_t *)&DAT_0001f2e0);
                  hMem = local_400;
                  _Var26 = local_418;
                  _Var3 = local_410;
                }
LAB_00019df8:
                local_418 = _Var26;
                local_410 = _Var3;
                iVar10 = Thread32Next(iVar7,local_3c8);
                puVar19 = local_3cc;
                iVar8 = local_3d0;
                _Str = local_408;
              }
            }
          }
          puVar16 = local_378;
          iVar13 = Process32Next(iVar7);
        } while (iVar13 != 0);
        pwVar6 = local_41c;
        if ((bVar5) && (iVar8 != 0)) {
          FUN_0001e194(L"\r\n");
          pwVar6 = local_41c;
        }
      }
      while (local_41c = pwVar6, hMem != (HLOCAL)0x0) {
        puVar19 = (HLOCAL)hMem[4];
        while (puVar19 != (HLOCAL)0x0) {
          pvVar20 = (HLOCAL)*puVar19;
          LocalFree(puVar19);
          puVar19 = pvVar20;
        }
        pvVar20 = (HLOCAL)*hMem;
        LocalFree(hMem);
        hMem = pvVar20;
        pwVar6 = local_41c;
      }
    }
  }
  if (bVar5) {
    if (iVar7 == -1) {
      DVar14 = GetLastError();
      FUN_00017be8(pwVar6,DVar14,param_3,param_4);
    }
    else {
      FUN_00017be8(L" MOD: Name            pModule :dwInUSE :dwVMBase:CurZone\r\n",puVar16,param_3,
                   param_4);
      iVar8 = 0;
      for (piVar21 = (int *)DAT_0001f6e4; piVar21 != (int *)0x0; piVar21 = (int *)*piVar21) {
        bVar5 = FUN_00019224(_Str,(wchar_t *)(piVar21 + 6));
        if (CONCAT31(extraout_var_00,bVar5) != 0) {
          FUN_00017be8(L" M%2.2d: %-15s %8.8lx %8.8lx %8.8lx %8.8lx\r\n",iVar8,piVar21 + 6,
                       piVar21[1]);
        }
        iVar8 = iVar8 + 1;
      }
    }
  }
  if (bVar2) {
    local_140.dwOSVersionInfoSize = 0x114;
    BVar11 = GetVersionExW(&local_140);
    if (BVar11 != 0) {
      GetSystemInfo((LPSYSTEM_INFO)&local_3a0[0].s);
      local_41c = (LPCWSTR)0x0;
      QueryInstructionSet(0,&local_41c);
      StringCbPrintfW((STRSAFE_LPWSTR)&DAT_0001f2e0,DAT_0001f18c,
                      L"Architecture CpuType    OSMajor    OSMinor    InstructionSet\r\n0x%8.8lx   0x%8.8lx 0x%8.8lx 0x%8.8lx 0x%8.8lx\r\n"
                      ,(uint)(ushort)local_3a0[0]._0_2_,local_388,local_140.dwMajorVersion,
                      local_140.dwMinorVersion,local_41c);
      FUN_0001e194((wchar_t *)&DAT_0001f2e0);
    }
  }
  if (iVar7 != -1) {
    CloseToolhelp32Snapshot(iVar7);
  }
  FUN_0001e3d4(local_2c);
  return 1;
code_r0x00019a04:
  hMem = (undefined4 *)*hMem;
  if (hMem == (undefined4 *)0x0) goto LAB_00019a3c;
  goto LAB_000199f8;
}



/* 0001a058 FUN_0001a058 */

/* Boundary evidence: original MIPS .pdata 0001a058..0001a27f. Semantic name remains unreviewed. */

void FUN_0001a058(uint *param_1,uint param_2,int *param_3,uint param_4,int param_5)

{
  int iVar1;
  undefined2 uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  undefined2 *puVar6;
  uint uVar7;
  int iVar8;
  undefined2 local_30 [18];
  uint local_c;
  
  local_c = DAT_0001f184;
  uVar7 = 0;
  if ((((param_2 != 0) && (param_2 < param_4)) || ((0xbfffffff < param_2 && (param_2 < 0xc8000000)))
      ) || ((0x3fffffff < param_2 && (param_2 < 0x60000000)))) {
    uVar7 = 1;
  }
  iVar8 = 0;
  puVar6 = local_30;
  uVar4 = DAT_0001f6fc;
  uVar5 = DAT_0001f6f8;
  do {
    uVar3 = *param_1;
    if (uVar3 == 0) break;
    if (uVar3 < 0x40) {
      *puVar6 = 0x2d;
      param_3[5] = param_3[5] + 1;
      uVar4 = DAT_0001f6fc;
      uVar5 = DAT_0001f6f8;
      if (uVar7 == 0) {
        uVar7 = uVar3 >> 2 & 3;
      }
    }
    else if ((uVar3 & 6) == 6) {
      if (uVar7 == 3) {
        *puVar6 = 0x53;
        param_3[4] = param_3[4] + 1;
        uVar4 = DAT_0001f6fc;
        uVar5 = DAT_0001f6f8;
      }
      else if (((uVar3 & 0x3fffffc0) < uVar5) || (uVar4 <= (uVar3 & 0x3fffffc0))) {
        *puVar6 = 0x50;
      }
      else {
        *puVar6 = 0x57;
        param_3[3] = param_3[3] + 1;
        uVar4 = DAT_0001f6fc;
        uVar5 = DAT_0001f6f8;
      }
    }
    else {
      uVar3 = uVar3 & 0x3fffffc0;
      if (uVar7 == 1) {
        if ((uVar3 < DAT_0001f6f0) || (DAT_0001f6f4 <= uVar3)) {
          *puVar6 = 99;
          param_3[1] = param_3[1] + 1;
          uVar4 = DAT_0001f6fc;
          uVar5 = DAT_0001f6f8;
        }
        else {
          iVar1 = *param_3;
          *puVar6 = 0x43;
          *param_3 = iVar1 + 1;
          uVar4 = DAT_0001f6fc;
          uVar5 = DAT_0001f6f8;
        }
      }
      else {
        if ((uVar3 < DAT_0001f6f0) || (uVar2 = 0x52, DAT_0001f6f4 <= uVar3)) {
          uVar2 = 0x72;
        }
        iVar1 = param_3[2];
        *puVar6 = uVar2;
        param_3[2] = iVar1 + 1;
        uVar4 = DAT_0001f6fc;
        uVar5 = DAT_0001f6f8;
      }
    }
    iVar8 = iVar8 + 1;
    param_1 = param_1 + 1;
    puVar6 = puVar6 + 1;
  } while (iVar8 < 0x10);
  local_30[iVar8] = 0;
  if ((iVar8 != 0) && (param_5 != 0)) {
    FUN_00017be8(L"  %8.8lx: %s\r\n",param_2,local_30,0x3fffffc0);
  }
  FUN_0001e3d4(local_c);
  return;
}



/* 0001a280 FUN_0001a280 */

/* Boundary evidence: original MIPS .pdata 0001a280..0001a30b. Semantic name remains unreviewed. */

void FUN_0001a280(uint *param_1,uint param_2,int *param_3,uint param_4,int param_5)

{
  int iVar1;
  
  iVar1 = 0x40;
  do {
    FUN_0001a058(param_1,param_2,param_3,param_4,param_5);
    param_1 = param_1 + 0x10;
    param_2 = param_2 + 0x10000;
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  return;
}



/* 0001a30c FUN_0001a30c */

/* Boundary evidence: original MIPS .pdata 0001a30c..0001a527. Semantic name remains unreviewed. */

void FUN_0001a30c(int param_1,int param_2)

{
  uint *puVar1;
  uint uVar2;
  uint uVar3;
  char *pcVar4;
  uint *puVar5;
  uint uVar6;
  undefined4 *puVar7;
  int local_250;
  undefined4 local_24c;
  undefined4 local_248;
  int local_244;
  int local_240;
  int local_238;
  uint local_234;
  char local_230 [512];
  uint local_30;
  
  local_30 = DAT_0001f184;
  local_238 = 0;
  memset(&local_234,0,0x204);
  local_250 = 0;
  memset(&local_24c,0,0x14);
  puVar7 = (undefined4 *)(param_1 + 4);
  uVar2 = 4;
  puVar1 = (uint *)KernelLibIoControl(1,0x18,puVar7,4,&local_238,0x208,0);
  if (puVar1 == (uint *)0x0) {
    FUN_00017be8(L"Unable to get memory info for process \'%s\', id = 0x%x.\r\n\r\n",param_1 + 0x14,
                 *puVar7,uVar2);
  }
  else {
    pcVar4 = local_230;
    uVar3 = 0;
    uVar6 = 0x70000000;
    puVar5 = puVar1;
    if (local_238 != 0) {
      uVar3 = 0x70000000;
      FUN_0001e194(L"\r\nMemory usage for Shared Heap:\r\n");
      do {
        if (*pcVar4 != '\0') {
          uVar2 = local_234;
          FUN_0001a280(puVar5,uVar3,&local_250,local_234,param_2);
        }
        uVar3 = uVar3 + 0x400000;
        puVar5 = puVar5 + 0x400;
        pcVar4 = pcVar4 + 1;
      } while (uVar3 < 0x80000000);
      uVar6 = 0xf0000000;
    }
    FUN_00017be8(L"\r\nMemory usage for Process \'%s\' pid %x\r\n",param_1 + 0x14,*puVar7,uVar2);
    for (; uVar3 < uVar6; uVar3 = uVar3 + 0x400000) {
      if (*pcVar4 != '\0') {
        FUN_0001a280(puVar5,uVar3,&local_250,local_234,param_2);
      }
      puVar5 = puVar5 + 0x400;
      pcVar4 = pcVar4 + 1;
    }
    KernelLibIoControl(1,0x19,puVar1,0,0,0,0);
    DAT_0001f2b8 = DAT_0001f2b8 + local_240 + local_244;
    FUN_00017be8(L"Page summary: code=%d(%d) data r/o=%d r/w=%d stack=%d reserved=%d\r\n",local_250,
                 local_24c,local_248);
  }
  FUN_0001e3d4(local_30);
  return;
}



/* 0001a528 FUN_0001a528 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Boundary evidence: original MIPS .pdata 0001a528..0001a633. Semantic name remains unreviewed. */

void FUN_0001a528(void)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined1 auStack_480 [8];
  ushort local_478 [6];
  int local_46c;
  int local_468;
  
  iVar4 = 0;
  iVar5 = 0;
  FUN_0001e194(L"Inx Size   Used    Max Extra  Entries Name\r\n");
  iVar3 = 0;
  do {
    iVar1 = KernelLibIoControl(1,0x1a,0,iVar3,local_478,0x460,auStack_480);
    if (iVar1 != 0) {
      uVar2 = (uint)local_478[0];
      iVar1 = uVar2 * local_46c;
      iVar4 = iVar1 + iVar4;
      iVar5 = (uVar2 * local_468 - iVar1) + iVar5;
      FUN_00017be8(L"%2d: %4d %6ld %6ld %5ld %3d(%3d) %hs\r\n",iVar3,uVar2,iVar1);
    }
    iVar3 = iVar3 + 1;
  } while (iVar3 < 8);
  FUN_00017be8(L"Total Used = %ld  Total Extra = %ld  Waste = %d\r\n",iVar4,iVar5,_DAT_00005b58);
  return;
}



/* 0001a634 FUN_0001a634 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Boundary evidence: original MIPS .pdata 0001a634..0001a83b. Semantic name remains unreviewed. */

undefined4 FUN_0001a634(wchar_t *param_1)

{
  bool bVar1;
  wchar_t *pwVar2;
  int iVar3;
  wchar_t *pwVar4;
  LPFILETIME p_Var5;
  int *piVar6;
  int iVar7;
  wchar_t awStack_30 [6];
  uint local_24;
  
  local_24 = DAT_0001f184;
  bVar1 = false;
  iVar7 = 0;
  if (param_1 != (wchar_t *)0x0) {
    pwVar2 = wcstok(param_1,L" \t");
    while (pwVar2 != (wchar_t *)0x0) {
      iVar3 = wcscmp(pwVar2,L"full");
      if (iVar3 == 0) {
        iVar7 = 1;
      }
      else {
        iVar3 = wcscmp(pwVar2,L"kernel");
        if (iVar3 == 0) {
          bVar1 = true;
        }
      }
      pwVar2 = wcstok((wchar_t *)0x0,L" \t");
    }
  }
  FUN_0001e194(L"\r\nWindows CE Kernel Memory Usage Tool 0.2\r\n");
  FUN_00017be8(L"Page size=%d, %d total pages, %d free pages. %d MinFree pages (%d current bytes, %d MaxUsed bytes)\r\n"
               ,_DAT_00005b04,_DAT_00005b2c,_DAT_00005b10);
  p_Var5 = (LPFILETIME)(_DAT_00005b2c - _DAT_00005b10);
  FUN_00017be8(L"%d pages used by kernel, %d pages held by kernel, %d pages consumed.\r\n",
               _DAT_00005b14,_DAT_00005b44,p_Var5);
  DAT_0001f2b8 = 0;
  if ((((iVar7 == 0) && (!bVar1)) || (FUN_0001a528(), iVar7 != 0)) || (!bVar1)) {
    pwVar4 = L"proc";
    pwVar2 = (wchar_t *)0xa;
    memcpy(awStack_30,L"proc",10);
    FUN_00019544(awStack_30,pwVar4,pwVar2,p_Var5);
    for (piVar6 = (int *)DAT_00020920; piVar6 != (int *)0x0; piVar6 = (int *)*piVar6) {
      FUN_0001a30c((int)piVar6,iVar7);
    }
    FUN_00017be8(L"\r\nTotal R/W data + stack = %ld\r\n",DAT_0001f2b8,pwVar2,p_Var5);
  }
  FUN_0001e3d4(local_24);
  return 1;
}



/* 0001a83c FUN_0001a83c */

int FUN_0001a83c(uint param_1,uint *param_2)

{
  int *piVar1;
  int *piVar2;
  uint uVar3;
  
  if (param_1 != 0) {
    uVar3 = (uint)((param_1 & 3) == 0);
    *param_2 = uVar3;
    piVar1 = DAT_00020920;
    piVar2 = DAT_0001f6e4;
    if (uVar3 == 0) {
      for (; piVar1 != (int *)0x0; piVar1 = (int *)*piVar1) {
        if (param_1 == piVar1[1]) {
          return (int)piVar1;
        }
      }
    }
    else {
      for (; piVar2 != (int *)0x0; piVar2 = (int *)*piVar2) {
        if (param_1 == piVar2[1]) {
          return (int)piVar2;
        }
      }
    }
  }
  return 0;
}



/* 0001a8c0 FUN_0001a8c0 */

/* Boundary evidence: original MIPS .pdata 0001a8c0..0001a95b. Semantic name remains unreviewed. */

int FUN_0001a8c0(wchar_t *param_1,int param_2)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  
  piVar1 = DAT_00020920;
  piVar2 = DAT_0001f6e4;
  if (param_2 == 0) {
    for (; piVar1 != (int *)0x0; piVar1 = (int *)*piVar1) {
      iVar3 = FUN_000192a4(param_1,(wchar_t *)(piVar1 + 5));
      if (iVar3 != 0) {
        return (int)piVar1;
      }
    }
  }
  else {
    for (; piVar2 != (int *)0x0; piVar2 = (int *)*piVar2) {
      iVar3 = FUN_000192a4(param_1,(wchar_t *)(piVar2 + 6));
      if (iVar3 != 0) {
        return (int)piVar2;
      }
    }
  }
  return 0;
}



/* 0001a95c FUN_0001a95c */

void FUN_0001a95c(uint param_1,int param_2)

{
  int *piVar1;
  int *piVar2;
  uint uVar3;
  
  uVar3 = 0;
  piVar1 = DAT_00020920;
  piVar2 = DAT_0001f6e4;
  if (param_2 == 0) {
    for (; (piVar1 != (int *)0x0 && (uVar3 < param_1)); uVar3 = uVar3 + 1) {
      piVar1 = (int *)*piVar1;
    }
  }
  else {
    for (; (piVar2 != (int *)0x0 && (uVar3 < param_1)); uVar3 = uVar3 + 1) {
      piVar2 = (int *)*piVar2;
    }
  }
  return;
}



/* 0001a9c4 FUN_0001a9c4 */

/* Boundary evidence: original MIPS .pdata 0001a9c4..0001aa6f. Semantic name remains unreviewed. */

void FUN_0001a9c4(int param_1,undefined4 param_2)

{
  int *piVar1;
  int *piVar2;
  
  piVar1 = DAT_00020920;
  piVar2 = DAT_0001f6e4;
  if (param_1 == 0) {
    for (; piVar1 != (int *)0x0; piVar1 = (int *)*piVar1) {
      if (piVar1[1] != 0) {
        SetDbgZone(piVar1[1],0,0,param_2,0);
      }
    }
  }
  else {
    for (; piVar2 != (int *)0x0; piVar2 = (int *)*piVar2) {
      if (piVar2[1] != 0) {
        SetDbgZone(0,piVar2[1],0,param_2,0);
      }
    }
  }
  return;
}



/* 0001aa70 FUN_0001aa70 */

/* Boundary evidence: original MIPS .pdata 0001aa70..0001ab27. Semantic name remains unreviewed. */

void FUN_0001aa70(int param_1,wchar_t *param_2,wchar_t *param_3,LPFILETIME param_4)

{
  wchar_t *pwVar1;
  wchar_t *pwVar2;
  wchar_t awStack_20 [6];
  uint local_14;
  
  local_14 = DAT_0001f184;
  pwVar1 = L"proc";
  pwVar2 = (wchar_t *)0xa;
  memcpy(awStack_20,L"proc",10);
  if (param_1 != 0) {
    pwVar2 = L"mod";
    pwVar1 = (wchar_t *)0x5;
    StringCchCopyW(awStack_20,5,L"mod");
  }
  FUN_00019544(awStack_20,pwVar1,pwVar2,param_4);
  wcsncpy(param_2,param_3,0x104);
  param_2[0x103] = L'\0';
  wcstok(param_2,L" \t");
  wcstok((wchar_t *)0x0,L" \t");
  FUN_0001e3d4(local_14);
  return;
}



/* 0001ab28 FUN_0001ab28 */

/* Boundary evidence: original MIPS .pdata 0001ab28..0001b0c3. Semantic name remains unreviewed. */

undefined4 FUN_0001ab28(wchar_t *param_1,undefined4 param_2,undefined4 param_3,LPFILETIME param_4)

{
  wchar_t wVar1;
  bool bVar2;
  wchar_t *pwVar3;
  wchar_t *_Str2;
  int iVar4;
  ulong uVar5;
  int iVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  uint uVar9;
  uint uVar10;
  undefined4 uVar11;
  uint uVar12;
  uint uVar13;
  uint local_688;
  wchar_t *local_684;
  undefined1 auStack_680 [64];
  undefined1 auStack_640 [256];
  undefined1 auStack_540 [256];
  undefined1 auStack_440 [256];
  undefined1 auStack_340 [256];
  uint local_240;
  wchar_t awStack_238 [259];
  undefined2 local_32;
  uint local_30;
  
  local_30 = DAT_0001f184;
  uVar10 = 0;
  bVar2 = false;
  local_688 = 0;
  if (param_1 == (wchar_t *)0x0) goto LAB_0001b08c;
  if ((DAT_0001f704 == 0) || (DAT_0001f2c8 == 0)) {
    wcsncpy(awStack_238,param_1,0x104);
    local_32 = 0;
  }
  pwVar3 = wcstok(param_1,L" \t");
  if ((pwVar3 == (wchar_t *)0x0) || (_Str2 = wcstok((wchar_t *)0x0,L" \t"), _Str2 == (wchar_t *)0x0)
     ) {
LAB_0001b080:
    FUN_0001e194(L"Zone Operation failed! May be an invalid param - type ? for help.\r\n");
  }
  else {
    wVar1 = *pwVar3;
    if ((wVar1 == L'm') || (wVar1 == L'M')) {
      uVar10 = 1;
      local_688 = 1;
      if (DAT_0001f704 == 0) {
        iVar4 = 1;
LAB_0001ac60:
        FUN_0001aa70(iVar4,param_1,awStack_238,param_4);
      }
    }
    else if ((wVar1 == L'p') || (wVar1 == L'P')) {
      uVar10 = 0;
      local_688 = 0;
      if (DAT_0001f2c8 == 0) {
        iVar4 = 0;
        goto LAB_0001ac60;
      }
    }
    else {
      if ((wVar1 != L'h') && (wVar1 != L'H')) goto LAB_0001b080;
      bVar2 = true;
    }
    iVar4 = wcscmp(L"alloff",_Str2);
    if (iVar4 == 0) {
      uVar7 = 0;
    }
    else {
      iVar4 = wcscmp(L"allon",_Str2);
      if (iVar4 != 0) {
        if (bVar2) {
          uVar5 = wcstoul(_Str2,(wchar_t **)0x0,0x10);
          iVar4 = FUN_0001a83c(uVar5,&local_688);
          uVar10 = local_688;
        }
        else {
          iVar4 = _isctype((uint)(ushort)*_Str2,4);
          if (iVar4 == 0) {
            iVar4 = FUN_0001a8c0(_Str2,uVar10);
          }
          else {
            uVar12 = _wtol(_Str2);
            iVar4 = FUN_0001a95c(uVar12,uVar10);
          }
        }
        if (iVar4 != 0) {
          uVar13 = *(uint *)(iVar4 + 4);
          uVar9 = *(uint *)(iVar4 + 8);
          local_688 = uVar13;
          pwVar3 = wcstok((wchar_t *)0x0,L" \t");
          uVar12 = 0xffffffff;
          if (pwVar3 != (wchar_t *)0x0) {
            wVar1 = *pwVar3;
            if (((ushort)wVar1 < 0x30) || (0x39 < (ushort)wVar1)) {
              if ((wVar1 != L'o') && (wVar1 != L'O')) goto LAB_0001b080;
              local_684 = L"on";
              do {
                iVar6 = wcscmp(pwVar3,local_684);
                pwVar3 = wcstok((wchar_t *)0x0,L" \t");
                uVar12 = uVar9;
                uVar13 = local_688;
                if (pwVar3 == (wchar_t *)0x0) break;
                do {
                  if ((*pwVar3 == L'o') || (*pwVar3 == L'O')) break;
                  uVar12 = _wtol(pwVar3);
                  uVar12 = 1 << (uVar12 & 0x1f);
                  if (iVar6 == 0) {
                    uVar9 = uVar12 | uVar9;
                  }
                  else {
                    uVar9 = ~uVar12 & uVar9;
                  }
                  pwVar3 = wcstok((wchar_t *)0x0,L" \t");
                } while (pwVar3 != (wchar_t *)0x0);
                uVar12 = uVar9;
                uVar13 = local_688;
              } while (pwVar3 != (wchar_t *)0x0);
            }
            else {
              uVar12 = _wtol(pwVar3);
            }
          }
          uVar9 = uVar12;
          if (uVar10 == 0) {
            iVar6 = SetDbgZone(uVar13,0,0,uVar12,auStack_680);
          }
          else {
            iVar6 = SetDbgZone(0,uVar13,0,uVar12,auStack_680);
          }
          if (iVar6 != 0) {
            if (uVar12 == 0xffffffff) {
              uVar12 = local_240;
            }
            *(uint *)(iVar4 + 8) = uVar12;
            FUN_00017be8(L"Registered Name:%s   CurZone:%08X\r\n",auStack_680,uVar12,uVar9);
            FUN_0001e194(L"Zone Names - Prefixed with bit number and * if currently on\r\n");
            uVar11 = 0x2a;
            uVar7 = 0x2a;
            if ((uVar12 & 2) == 0) {
              uVar7 = 0x20;
            }
            uVar8 = 0x2a;
            if ((uVar12 & 1) == 0) {
              uVar8 = 0x20;
            }
            FUN_00017be8(L" 0%c%-16s: 1%c%-16s: 2%c%-16s: 3%c%-16s\r\n",uVar8,auStack_640,uVar7);
            uVar7 = 0x2a;
            if ((uVar12 & 0x20) == 0) {
              uVar7 = 0x20;
            }
            uVar8 = 0x2a;
            if ((uVar12 & 0x10) == 0) {
              uVar8 = 0x20;
            }
            FUN_00017be8(L" 4%c%-16s: 5%c%-16s: 6%c%-16s: 7%c%-16s\r\n",uVar8,auStack_540,uVar7);
            uVar7 = 0x2a;
            if ((uVar12 & 0x200) == 0) {
              uVar7 = 0x20;
            }
            uVar8 = 0x2a;
            if ((uVar12 & 0x100) == 0) {
              uVar8 = 0x20;
            }
            FUN_00017be8(L" 8%c%-16s: 9%c%-16s:10%c%-16s:11%c%-16s\r\n",uVar8,auStack_440,uVar7);
            uVar7 = 0x2a;
            if ((uVar12 & 0x2000) == 0) {
              uVar7 = 0x20;
            }
            if ((uVar12 & 0x1000) == 0) {
              uVar11 = 0x20;
            }
            FUN_00017be8(L"12%c%-16s:13%c%-16s:14%c%-16s:15%c%-16s\r\n",uVar11,auStack_340,uVar7);
            goto LAB_0001b08c;
          }
        }
        goto LAB_0001b080;
      }
      uVar7 = 0xffff;
    }
    FUN_0001a9c4(uVar10,uVar7);
  }
LAB_0001b08c:
  FUN_0001e3d4(local_30);
  return 1;
}



/* 0001b0c4 FUN_0001b0c4 */

void FUN_0001b0c4(void)

{
  trap(0x400);
  return;
}



/* 0001b0d0 FUN_0001b0d0 */

/* Boundary evidence: original MIPS .pdata 0001b0d0..0001b0ef. Semantic name remains unreviewed. */

undefined4 FUN_0001b0d0(void)

{
  FUN_0001b0c4();
  return 1;
}



/* 0001b0f0 FUN_0001b0f0 */

/* Boundary evidence: original MIPS .pdata 0001b0f0..0001b1f7. Semantic name remains unreviewed. */

undefined4 FUN_0001b0f0(LPWSTR param_1)

{
  BOOL BVar1;
  DWORD DVar2;
  LPPROCESS_INFORMATION p_Var3;
  _PROCESS_INFORMATION local_230;
  wchar_t awStack_220 [260];
  uint local_18;
  
  local_18 = DAT_0001f184;
  if (param_1 == (LPWSTR)0x0) {
    FUN_0001e194(L"Run process requires an argument\r\n");
  }
  else {
    p_Var3 = &local_230;
    BVar1 = FUN_00018a24(param_1,awStack_220,0x104,p_Var3);
    if (BVar1 == 0) {
      DVar2 = GetLastError();
      FUN_00017be8(L"Unable to create process \'%s\' : Error %d\r\n",awStack_220,DVar2,p_Var3);
    }
    else {
      FUN_0001e194(L"Running ");
      FUN_0001e194(awStack_220);
      do {
        FUN_0001e194(L".");
        DVar2 = WaitForSingleObject(local_230.hProcess,3000);
      } while (DVar2 == 0x102);
      FUN_0001e194(L"done.\r\n");
      CloseHandle(local_230.hProcess);
      CloseHandle(local_230.hThread);
    }
  }
  FUN_0001e3d4(local_18);
  return 1;
}



/* 0001b1f8 FUN_0001b1f8 */

/* Boundary evidence: original MIPS .pdata 0001b1f8..0001b5a7. Semantic name remains unreviewed. */

undefined4 FUN_0001b1f8(wchar_t *param_1)

{
  char cVar1;
  HANDLE hFile;
  DWORD DVar2;
  BOOL BVar3;
  wchar_t *pwVar4;
  DWORD DVar5;
  DWORD DVar6;
  size_t _Size;
  DWORD DVar7;
  DWORD DVar8;
  int iVar9;
  int local_650;
  DWORD local_648;
  DWORD local_644;
  char local_640 [20];
  undefined1 local_62c;
  wchar_t awStack_238 [259];
  undefined2 local_32;
  uint local_30;
  
  local_30 = DAT_0001f184;
  iVar9 = 1;
  _Size = 0;
  local_650 = 1;
  if (param_1 == (wchar_t *)0x0) {
    pwVar4 = L"Syntax: run <filename>\r\n";
  }
  else {
    pwVar4 = wcstok(param_1,L" \t");
    hFile = FUN_00017ac0(pwVar4,0x10000);
    if (hFile != (HANDLE)0xffffffff) {
      DVar2 = GetFileSize(hFile,(LPDWORD)0x0);
      while( true ) {
        DVar8 = 0;
        BVar3 = ReadFile(hFile,local_640 + _Size,0x400 - _Size,&local_644,(LPOVERLAPPED)0x0);
        if (BVar3 == 0) {
          local_644 = 0;
        }
        if (local_644 == 0) break;
        DVar2 = DVar2 - local_644;
        DVar7 = local_644 + _Size;
        DVar5 = 0;
        do {
          if ((int)DVar5 < (int)DVar7) {
            do {
              cVar1 = local_640[DVar5];
              if (((cVar1 == '\0') || (cVar1 == '\r')) || (cVar1 == '\n')) break;
              DVar5 = DVar5 + 1;
            } while ((int)DVar5 < (int)DVar7);
            if (((int)DVar7 <= (int)DVar5) ||
               ((local_640[DVar5] != '\r' && (local_640[DVar5] != '\n')))) goto LAB_0001b398;
LAB_0001b3a0:
            if (DVar5 != DVar8) {
              local_640[DVar5] = '\0';
              MultiByteToWideChar(0,0,local_640 + DVar8,-1,awStack_238,0x104);
              FUN_0001b0f0(awStack_238);
            }
            do {
              DVar6 = DVar5 + 1;
              if (((int)DVar7 <= (int)DVar6) || (cVar1 = local_640[DVar5 + 1], cVar1 == '\0'))
              break;
              DVar5 = DVar6;
            } while ((cVar1 == '\r') || (cVar1 == '\n'));
            local_650 = iVar9 + 1;
            DVar8 = DVar6;
            iVar9 = local_650;
          }
          else {
LAB_0001b398:
            if (DVar2 == 0) goto LAB_0001b3a0;
            DVar6 = DVar5;
            if (DVar8 == 0) {
              local_62c = 0;
              FUN_00017be8(L"Ignoring line %i (\'%S...\'), line is too long (max is %i characters).\r\n"
                           ,iVar9,local_640,0x400);
              DVar6 = 0;
              do {
                BVar3 = ReadFile(hFile,local_640,0x400,&local_648,(LPOVERLAPPED)0x0);
                if (BVar3 == 0) {
                  local_648 = 0;
                }
                DVar2 = DVar2 - local_648;
                for (; (((int)DVar6 < (int)local_648 && (cVar1 = local_640[DVar6], cVar1 != '\0'))
                       && ((cVar1 != '\r' && (cVar1 != '\n')))); DVar6 = DVar6 + 1) {
                }
                DVar7 = local_648;
                DVar8 = DVar6;
                iVar9 = local_650;
              } while ((((DVar6 == local_648) && (local_640[DVar6] != '\r')) &&
                       (local_640[DVar6] != '\n')) && (DVar2 != 0));
            }
          }
          DVar5 = DVar6;
        } while ((int)DVar6 < (int)DVar7);
        if ((int)DVar8 < (int)DVar7) {
          _Size = DVar7 - DVar8;
          memcpy(local_640,local_640 + DVar8,_Size);
          local_640[_Size] = '\0';
        }
        else {
          _Size = 0;
        }
      }
      CloseHandle(hFile);
      goto LAB_0001b570;
    }
    _snwprintf(awStack_238,0x103,L"Unable to open input file %s\r\n",pwVar4);
    local_32 = 0;
    pwVar4 = awStack_238;
  }
  FUN_0001e194(pwVar4);
LAB_0001b570:
  FUN_0001e3d4(local_30);
  return 1;
}



/* 0001b5a8 FUN_0001b5a8 */

/* Boundary evidence: original MIPS .pdata 0001b5a8..0001b5c7. Semantic name remains unreviewed. */

undefined4 FUN_0001b5a8(void)

{
  ForcePageout();
  return 1;
}



/* 0001b5c8 FUN_0001b5c8 */

/* Boundary evidence: original MIPS .pdata 0001b5c8..0001b74b. Semantic name remains unreviewed. */

undefined4 FUN_0001b5c8(undefined4 *param_1,long *param_2)

{
  bool bVar1;
  bool bVar2;
  long lVar3;
  wchar_t wVar4;
  wchar_t *_Str;
  
  _Str = (wchar_t *)*param_1;
  bVar2 = false;
  bVar1 = false;
  if ((_Str != (wchar_t *)0x0) && (*_Str != L'\0')) {
    lVar3 = _wtol(_Str);
    if ((*_Str == L'-') || (*_Str == L'+')) {
      _Str = _Str + 1;
    }
    if ((*_Str == L'0') && (_Str[1] == L'x')) {
      _Str = _Str + 2;
      bVar1 = true;
    }
    wVar4 = *_Str;
    if (wVar4 != L'\0') {
      do {
        if (((((ushort)wVar4 < 0x30) || (0x39 < (ushort)wVar4)) &&
            (((ushort)wVar4 < 0x61 || ((0x66 < (ushort)wVar4 || (!bVar1)))))) &&
           (((ushort)wVar4 < 0x41 || ((0x46 < (ushort)wVar4 || (!bVar1)))))) break;
        _Str = _Str + 1;
        wVar4 = *_Str;
        bVar2 = true;
      } while (wVar4 != L'\0');
      if (bVar2) {
        if (*_Str != L'\0') {
          if (*_Str != L' ') {
            return 0;
          }
          wVar4 = L' ';
          do {
            if (wVar4 != L' ') break;
            _Str = _Str + 1;
            wVar4 = *_Str;
          } while (wVar4 != L'\0');
        }
        *param_1 = _Str;
        *param_2 = lVar3;
        return 1;
      }
    }
  }
  return 0;
}



/* 0001b74c FUN_0001b74c */

/* Boundary evidence: original MIPS .pdata 0001b74c..0001b79b. Semantic name remains unreviewed. */

void FUN_0001b74c(int param_1)

{
  if (0 < param_1) {
    do {
      FUN_0001e194(L"    ");
      param_1 = param_1 + -1;
    } while (param_1 != 0);
  }
  return;
}



/* 0001b79c FUN_0001b79c */

/* Boundary evidence: original MIPS .pdata 0001b79c..0001babf. Semantic name remains unreviewed. */

void FUN_0001b79c(undefined4 param_1,int param_2)

{
  bool bVar1;
  LPCWSTR pWVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  uint uVar6;
  uint uVar7;
  undefined1 local_31c [4];
  LPCWSTR local_318;
  int local_314;
  int local_310;
  undefined4 local_30c;
  int local_308;
  wchar_t awStack_300 [100];
  wchar_t awStack_238 [259];
  undefined2 local_32;
  uint local_30;
  
  local_30 = DAT_0001f184;
  local_314 = param_2;
  FUN_0001b74c(param_2);
  iVar4 = (*DAT_0001f708)(param_1,awStack_300,100);
  if (iVar4 == 0) {
    StringCbPrintfW(awStack_238,0x208,L"<No name>\r\n");
  }
  else {
    _snwprintf(awStack_238,0x103,L"\"%s\"\r\n",awStack_300);
    local_32 = 0;
  }
  FUN_0001e194(awStack_238);
  iVar4 = (*DAT_0001f6e0)(param_1,awStack_300,100);
  if (iVar4 == 0) {
    wcscpy(awStack_300,L"Unknown class");
    FUN_0001e194(awStack_238);
  }
  (*DAT_0001f2c0)(param_1,&local_310);
  (*DAT_0001f2c4)(param_1,local_31c);
  FUN_0001b74c(param_2);
  uVar5 = (*DAT_0002092c)(param_1);
  FUN_00017be8(L"hwnd=%08x Class=%s parent=%08x thread=%08x process=%08x\r\n",param_1,awStack_300,
               uVar5);
  FUN_0001b74c(param_2);
  iVar4 = local_308 - local_310;
  FUN_00017be8(L"x=%d y=%d width=%d height=%d\r\n",local_310,local_30c,iVar4);
  uVar6 = (*DAT_0001f2bc)(param_1,0xfffffff0);
  FUN_0001b74c(param_2);
  FUN_0001e194(L"Style=");
  uVar7 = 0;
  local_318 = L"%s ";
  uVar5 = local_30c;
  do {
    if ((*(uint *)((int)&DAT_0001f194 + uVar7) & uVar6) != 0) {
      uVar6 = ~*(uint *)((int)&DAT_0001f194 + uVar7) & uVar6;
      FUN_00017be8(L"%s ",*(undefined4 *)((int)&PTR_u_WS_CAPTION_0001f198 + uVar7),uVar5,iVar4);
    }
    iVar3 = local_314;
    uVar7 = uVar7 + 8;
  } while (uVar7 < 0x70);
  if (uVar6 != 0) {
    FUN_00017be8(L"%08x ",uVar6,uVar5,iVar4);
  }
  FUN_0001e194(L"\r\n");
  uVar6 = (*DAT_0001f2bc)(param_1,0xffffffec);
  pWVar2 = local_318;
  bVar1 = false;
  uVar7 = 0;
  do {
    if ((*(uint *)((int)&DAT_0001f204 + uVar7) & uVar6) != 0) {
      uVar6 = ~*(uint *)((int)&DAT_0001f204 + uVar7) & uVar6;
      if (!bVar1) {
        FUN_0001b74c(iVar3);
        FUN_0001e194(L"exstyle=");
        bVar1 = true;
      }
      FUN_00017be8(pWVar2,*(undefined4 *)((int)&PTR_u_WS_EX_DLGMODALFRAME_0001f208 + uVar7),uVar5,
                   iVar4);
    }
    uVar7 = uVar7 + 8;
  } while (uVar7 < 0x68);
  if (uVar6 != 0) {
    if (!bVar1) {
      FUN_0001b74c(iVar3);
      FUN_0001e194(L"exstyle=");
      bVar1 = true;
    }
    FUN_00017be8(L"%08x ",uVar6,uVar5,iVar4);
  }
  if (bVar1) {
    FUN_0001e194(L"\r\n");
  }
  FUN_0001e194(L"\r\n");
  FUN_0001e3d4(local_30);
  return;
}



/* 0001bac0 FUN_0001bac0 */

/* Boundary evidence: original MIPS .pdata 0001bac0..0001bb57. Semantic name remains unreviewed. */

void FUN_0001bac0(int param_1,int param_2)

{
  int iVar1;
  
  if (param_1 != 0) {
    FUN_0001b79c(param_1,param_2);
  }
  iVar1 = (*DAT_00020924)(param_1,5);
  if (iVar1 != 0) {
    do {
      FUN_0001bac0(iVar1,param_2 + 1);
      iVar1 = (*DAT_00020924)(iVar1,2);
    } while (iVar1 != 0);
  }
  return;
}



/* 0001bb58 FUN_0001bb58 */

/* Boundary evidence: original MIPS .pdata 0001bb58..0001bf5b. Semantic name remains unreviewed. */

undefined4
FUN_0001bb58(undefined4 param_1,undefined4 param_2,undefined1 *param_3,undefined1 *param_4)

{
  HMODULE hLibModule;
  wchar_t *pwVar1;
  int local_1e8;
  int local_1e4;
  int local_1e0;
  int local_1dc;
  undefined4 local_1d8;
  undefined4 local_1d4;
  undefined4 local_1d0;
  undefined1 auStack_1c0 [200];
  undefined1 auStack_f8 [200];
  uint local_30;
  
  local_30 = DAT_0001f184;
  pwVar1 = L"\r\n\r\n";
  FUN_0001e194(L"\r\n\r\n");
  if (DAT_00020924 == 0) {
    hLibModule = LoadLibraryW(L"COREDLL.DLL");
    if (hLibModule == (HMODULE)0x0) {
      pwVar1 = L"Unable to LoadLibrary(Coredll.dll)\r\n";
      goto LAB_0001bf1c;
    }
    DAT_00020924 = GetProcAddressW(hLibModule,L"GetWindow");
    DAT_0001f2bc = GetProcAddressW(hLibModule,L"GetWindowLongW");
    DAT_0001f708 = (code *)GetProcAddressW(hLibModule,L"GetWindowTextW");
    DAT_0001f6e0 = (code *)GetProcAddressW(hLibModule,L"GetClassNameW");
    DAT_0001f2c0 = GetProcAddressW(hLibModule,L"GetWindowRect");
    DAT_0001f2c4 = GetProcAddressW(hLibModule,L"GetWindowThreadProcessId");
    DAT_0002092c = GetProcAddressW(hLibModule,L"GetParent");
    DAT_00020928 = (code *)GetProcAddressW(hLibModule,L"GetForegroundInfo");
    if (((((DAT_00020924 == 0) || (DAT_0001f2bc == 0)) || (DAT_0001f708 == (code *)0x0)) ||
        ((DAT_0001f6e0 == (code *)0x0 || (DAT_0001f2c0 == 0)))) ||
       ((DAT_0001f2c4 == 0 || ((DAT_0002092c == 0 || (DAT_00020928 == (code *)0x0)))))) {
      DAT_00020924 = 0;
      FUN_0001e194(L"Unable to GetProcAddress of something\r\n");
      FreeLibrary(hLibModule);
      pwVar1 = L"Unable to get function pointers, assuming missing components\r\n\r\n";
      goto LAB_0001bf1c;
    }
    FreeLibrary(hLibModule);
  }
  (*DAT_00020928)(&local_1e8);
  FUN_0001e194(L"\r\nFOREGROUND INFO:\r\n\r\n");
  if (local_1e8 == 0) {
    FUN_0001e194(L"Active:     NULL\r\n\r\n");
  }
  else {
    (*DAT_0001f708)(local_1e8,auStack_f8,100);
    (*DAT_0001f6e0)(local_1e8,auStack_1c0,100);
    param_4 = auStack_1c0;
    param_3 = auStack_f8;
    FUN_00017be8(L"Active:     0x%X,  %s,  %s\r\n",local_1e8,param_3,param_4);
  }
  if (local_1e4 == 0) {
    FUN_0001e194(L"Focus:      NULL\r\n");
  }
  else {
    (*DAT_0001f708)(local_1e4,auStack_f8,100);
    (*DAT_0001f6e0)(local_1e4,auStack_1c0,100);
    param_4 = auStack_1c0;
    param_3 = auStack_f8;
    FUN_00017be8(L"Focus:      0x%X,  %s,  %s\r\n",local_1e4,param_3,param_4);
  }
  if (local_1e0 == 0) {
    FUN_0001e194(L"Menu:       NULL\r\n");
  }
  else {
    (*DAT_0001f708)(local_1e0,auStack_f8,100);
    (*DAT_0001f6e0)(local_1e0,auStack_1c0,100);
    param_4 = auStack_1c0;
    param_3 = auStack_f8;
    FUN_00017be8(L"Menu:       0x%X,  %s,  %s\r\n",local_1e0,param_3,param_4);
  }
  if (local_1dc == 0) {
    FUN_0001e194(L"KeybdDest:  NULL\r\n");
  }
  else {
    (*DAT_0001f708)(local_1dc,auStack_f8,100);
    (*DAT_0001f6e0)(local_1dc,auStack_1c0,100);
    param_4 = auStack_1c0;
    param_3 = auStack_f8;
    FUN_00017be8(L"KeybdDest:  0x%X,  %s,  %s\r\n",local_1dc,param_3,param_4);
  }
  FUN_00017be8(L"IME open:   %i\r\n",local_1d0,param_3,param_4);
  FUN_00017be8(L"IME Conv:   0x%X\r\n",local_1d8,param_3,param_4);
  FUN_00017be8(L"IME Sent:   0x%X\r\n",local_1d4,param_3,param_4);
  FUN_0001e194(L"\r\n\r\n");
  FUN_0001bac0(0,-1);
LAB_0001bf1c:
  FUN_0001e194(pwVar1);
  FUN_0001e3d4(local_30);
  return 1;
}



/* 0001bf5c FUN_0001bf5c */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Boundary evidence: original MIPS .pdata 0001bf5c..0001c123. Semantic name remains unreviewed. */

undefined4 FUN_0001bf5c(int param_1,uint param_2,undefined4 param_3,undefined4 param_4)

{
  HANDLE hObject;
  int iVar1;
  undefined4 uVar2;
  wchar_t *pwVar3;
  
  if (DAT_0001f288 == (HMODULE)0x0) {
    DAT_0001f288 = LoadLibraryW(L"ShellCeLog.dll");
    if (DAT_0001f288 == (HMODULE)0x0) {
      pwVar3 = L"Unable to open ShellCeLog.dll\r\n";
      goto LAB_0001c078;
    }
    DAT_0001f290 = (code *)GetProcAddressW(DAT_0001f288,L"SetCeLogBufSize");
    DAT_0001f28c = (code *)GetProcAddressW(DAT_0001f288,L"FlushOnce");
  }
  if (param_1 < 1) {
    return 0;
  }
  if (param_1 < 3) {
    if (DAT_0001f28c == (code *)0x0) {
      return 0;
    }
    if (param_1 != 1) {
      param_2 = 0;
    }
    uVar2 = (*DAT_0001f28c)(param_2);
    return uVar2;
  }
  if (param_1 == 3) {
    if (DAT_0001f290 == (code *)0x0) {
      return 0;
    }
    iVar1 = (*DAT_0001f290)(param_2);
    if (iVar1 != 0) {
      FUN_00017be8(L"CeLog buffer size set to %ukB in registry.\r\n\r\n",param_2 >> 10,param_3,
                   param_4);
      return 1;
    }
    if ((_DAT_00005b68 & 0x30000000) == 0) {
      return 0;
    }
    pwVar3 = L"CeLog is already running, buffer size could not be changed.\r\n\r\n";
  }
  else {
    if (param_1 != 4) {
      return 0;
    }
    hObject = OpenEventW(0x1f0003,0,L"SYSTEM/CeLogFlush Quit");
    if (hObject != (HANDLE)0x0) {
      EventModify(hObject,3);
      CloseHandle(hObject);
      FUN_0001e194(L"Signalled flush app to exit.\r\n");
      return 1;
    }
    pwVar3 = L"Flush app is not running.\r\n";
  }
LAB_0001c078:
  FUN_0001e194(pwVar3);
  return 0;
}



/* 0001c124 FUN_0001c124 */

/* Boundary evidence: original MIPS .pdata 0001c124..0001c203. Semantic name remains unreviewed. */

void FUN_0001c124(void)

{
  FUN_0001e194(L"Syntax:   log [log_options]  [[CE zone] [user zone] [process mask]]\r\n");
  FUN_0001e194(L"log_options:\r\n");
  FUN_0001e194(L"    -buf <size>            Set size of CeLog data buffer, if CeLog is\r\n");
  FUN_0001e194(L"                           not yet running (hex or decimal)\r\n");
  FUN_0001e194(L"    -clear                 Discard CeLog data buffer contents\r\n");
  FUN_0001e194(L"    -flush [filename.clg]  Flush buffered data to log file\r\n");
  FUN_0001e194(L"                           (default file \\Release\\celog.clg)\r\n");
  FUN_0001e194(L"    -stopflush             Signal flush application to exit\r\n");
  FUN_0001e194(L"Zones:  CeLog zones (hex or decimal).  Omitted zones default to 0xFFFFFFFF.\r\n");
  FUN_0001e194(L"\r\nExamples:\r\n");
  FUN_0001e194(L"    log 0x63 0xFFFFFFFF 0xFFFFFFFF    Get data from zone 0x63\r\n");
  FUN_0001e194(L"    log 0x63                          (same as previous)\r\n");
  FUN_0001e194(L"    log -buf 0x00100000               Set CeLog buffer size to 1MB without\r\n");
  FUN_0001e194(L"                                      changing zones\r\n");
  FUN_0001e194(L"    log -buf 1048576                  (same as previous)\r\n");
  FUN_0001e194(L"    log -buf 1048576 0x63             Set buffer size to 1MB and set zones\r\n");
  FUN_0001e194(
              L"    log -flush \\release\\myfile.clg    Flush CeLog buffer contents to file\r\n\r\n"
              );
  return;
}



/* 0001c204 FUN_0001c204 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Boundary evidence: original MIPS .pdata 0001c204..0001c56f. Semantic name remains unreviewed. */

undefined4 FUN_0001c204(wchar_t *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  wchar_t *pwVar1;
  int iVar2;
  wchar_t *pwVar3;
  undefined4 uVar4;
  undefined4 **ppuVar5;
  undefined4 *puVar6;
  int iVar7;
  long *plVar8;
  wchar_t *local_260 [2];
  long local_258;
  undefined4 **local_254;
  undefined4 *local_250;
  undefined4 local_24c;
  wchar_t *local_248;
  wchar_t local_240 [259];
  undefined2 local_3a;
  int local_38;
  uint local_34;
  uint local_30;
  
  local_30 = DAT_0001f184;
  uVar4 = 0x10;
  memset(&local_258,0xff,0x10);
  iVar7 = 0;
  local_38 = 0;
  local_34 = 0;
  local_240[0] = L'\0';
  if (param_1 == (wchar_t *)0x0) {
    FUN_0001c124();
LAB_0001c460:
    if (local_38 != 0) goto LAB_0001c46c;
LAB_0001c4d8:
    if ((local_34 != 0) || (local_38 != 0)) goto LAB_0001c538;
  }
  else {
    pwVar1 = wcstok(param_1,L" \t");
    local_260[0] = pwVar1;
    if (pwVar1 == (wchar_t *)0x0) goto LAB_0001c460;
    plVar8 = &local_258;
    local_248 = L"-buf";
    do {
      local_260[0] = pwVar1;
      if (*pwVar1 == L'\0') break;
      iVar2 = wcscmp(pwVar1,local_248);
      if (iVar2 == 0) {
        local_260[0] = wcstok((wchar_t *)0x0,L" \t");
        iVar2 = FUN_0001b5c8(local_260,(long *)&local_34);
        if (iVar2 == 0) {
LAB_0001c440:
          FUN_0001c124();
          break;
        }
        FUN_0001bf5c(3,local_34,uVar4,param_4);
      }
      else {
        iVar2 = wcscmp(pwVar1,L"-clear");
        if (iVar2 == 0) {
          if (local_38 == 0) {
            local_38 = 2;
          }
        }
        else {
          pwVar3 = L"-flush";
          iVar2 = wcscmp(pwVar1,L"-flush");
          if (iVar2 == 0) {
            if ((_DAT_00005b68 & 0x30000000) == 0) {
              FUN_00017be8(L"CeLog is not loaded, no data to flush!\r\n\r\n",pwVar3,uVar4,param_4);
              goto LAB_0001c538;
            }
            if (local_38 != 4) {
              local_38 = 1;
            }
            pwVar1 = wcstok((wchar_t *)0x0,L"\"");
            if (pwVar1 == (wchar_t *)0x0) {
              wcscpy(local_240,L"\\release\\celog.clg");
            }
            else {
              uVar4 = 0x104;
              wcsncpy(local_240,pwVar1,0x104);
              local_3a = 0;
            }
          }
          else {
            iVar2 = wcscmp(pwVar1,L"-stopflush");
            if (iVar2 == 0) {
              local_38 = 4;
            }
            else {
              iVar2 = FUN_0001b5c8(local_260,plVar8);
              if (iVar2 == 0) goto LAB_0001c440;
              iVar7 = iVar7 + 1;
              plVar8 = plVar8 + 1;
            }
          }
        }
      }
      pwVar1 = wcstok((wchar_t *)0x0,L" \t");
      local_260[0] = pwVar1;
    } while (pwVar1 != (wchar_t *)0x0);
    if (iVar7 == 0) goto LAB_0001c460;
LAB_0001c46c:
    if ((((_DAT_00005b68 & 0x30000000) == 0) && (iVar2 = FUN_00017c38(1), iVar2 == 0)) ||
       ((local_38 != 0 && (iVar2 = FUN_0001bf5c(local_38,(uint)local_240,uVar4,param_4), iVar2 == 0)
        ))) goto LAB_0001c538;
    if (iVar7 == 0) goto LAB_0001c4d8;
    CeLogSetZones(local_254,local_258,local_250);
    CeLogReSync();
  }
  puVar6 = &local_24c;
  ppuVar5 = &local_250;
  CeLogGetZones(&local_254,&local_258);
  if ((_DAT_00005b68 & 0x30000000) != 0) {
    FUN_00017be8(L"\r\nCurrent CeLog zones:  CE=0x%08X User=0x%08X Process=0x%08X\r\n",local_258,
                 local_254,local_250);
    ppuVar5 = local_254;
    puVar6 = local_250;
  }
  FUN_00017be8(L"Available zones:  0x%08X\r\n\r\n",local_24c,ppuVar5,puVar6);
LAB_0001c538:
  FUN_0001e3d4(local_30);
  return 1;
}



/* 0001c570 FUN_0001c570 */

/* Boundary evidence: original MIPS .pdata 0001c570..0001c593. Semantic name remains unreviewed. */

undefined4 FUN_0001c570(void)

{
  FUN_0001e194(L"memtrack is no longer supported. Use Application Verifier to track memory.\r\n\r\n"
              );
  return 1;
}



/* 0001c594 FUN_0001c594 */

/* Boundary evidence: original MIPS .pdata 0001c594..0001c657. Semantic name remains unreviewed. */

undefined4 FUN_0001c594(wchar_t *param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 local_248 [2];
  undefined4 local_240;
  wchar_t awStack_224 [264];
  uint local_14;
  
  local_14 = DAT_0001f184;
  iVar1 = CreateToolhelp32Snapshot(0x40000002,0);
  uVar3 = 0xffffffff;
  if (iVar1 != -1) {
    local_248[0] = 0x234;
    iVar2 = Process32First(iVar1,local_248);
    while ((uVar3 = 0xffffffff, iVar2 != 0 &&
           (iVar2 = FUN_000192a4(param_1,awStack_224), uVar3 = local_240, iVar2 == 0))) {
      iVar2 = Process32Next(iVar1,local_248);
    }
    CloseToolhelp32Snapshot(iVar1);
  }
  FUN_0001e3d4(local_14);
  return uVar3;
}



/* 0001c658 FUN_0001c658 */

/* Boundary evidence: original MIPS .pdata 0001c658..0001c907. Semantic name remains unreviewed. */

undefined4 FUN_0001c658(wchar_t *param_1)

{
  bool bVar1;
  wchar_t *pwVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  DWORD DVar6;
  int iVar7;
  int iVar8;
  int local_78;
  int local_74;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_50 [3];
  int local_44;
  uint local_40;
  undefined4 local_34;
  undefined4 local_30;
  
  bVar1 = false;
  if ((param_1 == (wchar_t *)0x0) || (pwVar2 = wcstok(param_1,L" \t"), pwVar2 == (wchar_t *)0x0)) {
    pwVar2 = L"Syntax: hd <procname>\r\n\r\n";
  }
  else {
    iVar3 = FUN_0001c594(pwVar2);
    if (iVar3 == -1) {
      pwVar2 = L"Process not found\r\n\r\n";
    }
    else {
      pwVar2 = wcstok((wchar_t *)0x0,L" \t");
      if ((pwVar2 != (wchar_t *)0x0) && (iVar4 = wcscmp(L"freed",pwVar2), iVar4 == 0)) {
        bVar1 = true;
      }
      iVar7 = 0;
      iVar8 = 0;
      local_78 = 0;
      local_74 = 0;
      iVar4 = CreateToolhelp32Snapshot(1,iVar3);
      if (iVar4 != -1) {
        local_60 = 0x10;
        iVar5 = Heap32ListFirst(iVar4,&local_60);
        if (iVar5 == 0) {
          DVar6 = GetLastError();
          if (DVar6 == 0x12) {
            pwVar2 = L"No heap list exists for this process.\r\n\r\n";
          }
          else {
            pwVar2 = L"Heap32ListFirst failed\r\n";
          }
          FUN_0001e194(pwVar2);
        }
        else {
          do {
            local_50[0] = 0x24;
            iVar5 = Heap32First(iVar4,local_50,iVar3,local_58);
            if (iVar5 != 0) {
              iVar7 = 0;
              iVar8 = 0;
              do {
                if ((bVar1) || ((local_40 & 2) == 0)) {
                  FUN_00017be8(L"Process 0x%08x Heap 0x%08x: %5d bytes at 0x%08x %s\r\n",local_34,
                               local_30,local_44);
                  iVar8 = iVar8 + 1;
                  local_50[0] = 0x24;
                  iVar7 = local_44 + iVar7;
                }
                iVar5 = Heap32Next(iVar4,local_50);
              } while (iVar5 != 0);
              FUN_00017be8(L"Process 0x%08x Heap 0x%08x: %5d total bytes in %5d allocations\r\n\r\n"
                           ,local_34,local_30,iVar7);
              iVar7 = iVar7 + local_78;
              iVar8 = iVar8 + local_74;
              local_78 = iVar7;
              local_74 = iVar8;
            }
            local_60 = 0x10;
            iVar5 = Heap32ListNext(iVar4,&local_60);
          } while (iVar5 != 0);
          FUN_00017be8(L"Process 0x%08x: Total %5d bytes in %d allocations\r\n",local_5c,iVar7,iVar8
                      );
        }
        CloseToolhelp32Snapshot(iVar4);
        return 1;
      }
      pwVar2 = L"Heap snapshot failed for Process\r\n\r\n";
    }
  }
  FUN_0001e194(pwVar2);
  return 1;
}



/* 0001c908 FUN_0001c908 */

/* Boundary evidence: original MIPS .pdata 0001c908..0001cbbb. Semantic name remains unreviewed. */

undefined4 FUN_0001c908(wchar_t *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  wchar_t *_Str1;
  int iVar1;
  undefined4 uVar2;
  wchar_t *pwVar3;
  undefined *puVar4;
  wchar_t *local_38;
  wchar_t *local_34;
  wchar_t *local_30;
  
  if ((param_1 == (wchar_t *)0x0) || (*param_1 == L'\0')) {
    FUN_0001e194(L"Options:\r\n");
    if (DAT_0001f70c == 0) {
      puVar4 = &DAT_00015f3c;
    }
    else {
      puVar4 = &DAT_00015f34;
    }
    FUN_00017be8(L"     Timestamp : %s\r\n",puVar4,param_3,param_4);
    FUN_0001e194(L"\r\n");
  }
  else {
    _Str1 = wcstok(param_1,L" \t");
    if (_Str1 != (wchar_t *)0x0) {
      local_30 = L"timestamp";
      do {
        iVar1 = _wcsicmp(_Str1,local_30);
        if (iVar1 == 0) {
          DAT_0001f70c = DAT_0001f70c ^ 1;
          pwVar3 = L"Timestamp : %s\r\n";
          _Str1 = L"On";
          if (DAT_0001f70c == 0) {
            _Str1 = L"Off";
          }
LAB_0001cb1c:
          FUN_00017be8(pwVar3,_Str1,param_3,param_4);
        }
        else {
          iVar1 = _wcsicmp(_Str1,L"priority");
          if (iVar1 == 0) {
            local_34 = wcstok((wchar_t *)0x0,L" \t");
            if (local_34 == (wchar_t *)0x0) {
              uVar2 = __GetUserKData(8);
              local_38 = (wchar_t *)CeGetThreadPriority(uVar2);
              pwVar3 = L"Current priority=%d\r\n";
              _Str1 = local_38;
            }
            else {
              iVar1 = FUN_0001b5c8(&local_34,(long *)&local_38);
              _Str1 = local_38;
              if ((iVar1 == 0) || ((wchar_t *)0xff < local_38)) {
                FUN_0001e194(L"Invalid priority value\r\n");
                goto LAB_0001cb24;
              }
              uVar2 = __GetUserKData(8);
              CeSetThreadPriority(uVar2,_Str1);
              pwVar3 = L"Priority set to %d\r\n";
            }
            goto LAB_0001cb1c;
          }
          iVar1 = _wcsicmp(_Str1,L"kernfault");
          if (iVar1 == 0) {
            param_4 = 1;
            param_3 = 0;
            KernelLibIoControl(1,0xb,0,1,0,0,0);
          }
          else {
            iVar1 = _wcsicmp(_Str1,L"kernnofault");
            if (iVar1 != 0) {
              pwVar3 = L"Unexpected option \'%s\'\r\n";
              goto LAB_0001cb1c;
            }
            param_4 = 0;
            param_3 = 0;
            KernelLibIoControl(1,0xb,0,0,0,0,0);
          }
        }
LAB_0001cb24:
        _Str1 = wcstok((wchar_t *)0x0,L" \t");
      } while (_Str1 != (wchar_t *)0x0);
    }
  }
  return 1;
}



/* 0001cbbc FUN_0001cbbc */

/* Boundary evidence: original MIPS .pdata 0001cbbc..0001cc53. Semantic name remains unreviewed. */

undefined4 FUN_0001cbbc(void)

{
  HMODULE hLibModule;
  code *pcVar1;
  
  hLibModule = LoadLibraryW(L"COREDLL.DLL");
  if (hLibModule == (HMODULE)0x0) {
    FUN_0001e194(L"Unable to LoadLibrary(Coredll.dll)\r\n");
  }
  else {
    pcVar1 = (code *)GetProcAddressW(hLibModule,L"GwesPowerOffSystem");
    if (pcVar1 == (code *)0x0) {
      FUN_0001e194(L"Unable to find GwesPowerOffSystem() api in coredll.dll\r\n");
    }
    else {
      (*pcVar1)();
    }
    FreeLibrary(hLibModule);
  }
  return 1;
}



/* 0001cc54 FUN_0001cc54 */

/* Boundary evidence: original MIPS .pdata 0001cc54..0001cdff. Semantic name remains unreviewed. */

void FUN_0001cc54(void)

{
  FUN_0001e194(L"Syntax: prof <on|off> [data_type] [storage_type] [other_options]\r\n");
  FUN_0001e194(L"data_type, one of: -m or -s or -k\r\n");
  FUN_0001e194(L"    -m: Gather Monte Carlo data (time-based sampling) (DEFAULT)\r\n");
  FUN_0001e194(L"    -s: Gather System Call data (call-based sampling)\r\n");
  FUN_0001e194(L"    -k: Gather Kernel Call data (call-based sampling)\r\n");
  FUN_0001e194(L"storage_type, one of: -b or -u or -l\r\n");
  FUN_0001e194(L"    -b: Buffered (DEFAULT)\r\n");
  FUN_0001e194(L"    -u: Unbuffered\r\n");
  FUN_0001e194(L"    -l: Send data to CeLog, additional options available:\r\n");
  FUN_0001e194(L"other_options:\r\n");
  FUN_0001e194(L"    -i <interval>          Set the sampling interval, in microseconds\r\n");
  FUN_0001e194(L"                           (hex or decimal)\r\n");
  FUN_0001e194(L"The following options are only available when using CeLog (-l):\r\n");
  FUN_0001e194(L"    -buf <size>            Set size of CeLog data buffer, if CeLog is\r\n");
  FUN_0001e194(L"                           not yet running (hex or decimal)\r\n");
  FUN_0001e194(L"    -clear                 (\"prof on\" only) Clear CeLog buffer, then\r\n");
  FUN_0001e194(L"                           start profiler\r\n");
  FUN_0001e194(L"    -flush [filename.clg]  (\"prof off\" only) Stop profiler, then\r\n");
  FUN_0001e194(L"                           flush CeLog buffer to log file\r\n");
  FUN_0001e194(L"                           (default file \\Release\\celog.clg)\r\n");
  FUN_0001e194(L"\r\nExamples:\r\n");
  FUN_0001e194(L"    prof on                   Start profiler, Monte Carlo data,\r\n");
  FUN_0001e194(L"                              buffered mode\r\n");
  FUN_0001e194(L"    prof on -s -u             Start profiler, SysCall data,\r\n");
  FUN_0001e194(L"                              unbuffered mode\r\n");
  FUN_0001e194(L"    prof off                  Stop profiler\r\n\r\n");
  FUN_0001e194(L"    prof on -l                Start profiler, Monte Carlo data, CeLog mode\r\n");
  FUN_0001e194(L"    prof on -l -buf 0x100000  Start profiler, Monte Carlo data, CeLog mode\r\n");
  FUN_0001e194(L"                              with 1MB CeLog buffer\r\n");
  FUN_0001e194(L"    prof on -l -buf 1048576   (same as previous)\r\n");
  FUN_0001e194(L"    prof on -l -clear         Clear CeLog buffer, then start profiler,\r\n");
  FUN_0001e194(L"                              Monte Carlo data in CeLog mode\r\n");
  FUN_0001e194(L"    prof off -flush           Stop profiler and flush CeLog buffer to file\r\n");
  FUN_0001e194(L"\r\n");
  return;
}



/* 0001ce00 FUN_0001ce00 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Boundary evidence: original MIPS .pdata 0001ce00..0001d2cf. Semantic name remains unreviewed. */

undefined4 FUN_0001ce00(wchar_t *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  wchar_t *pwVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  long lVar5;
  long local_250;
  wchar_t *local_24c;
  wchar_t *local_248;
  wchar_t local_240 [259];
  undefined2 local_3a;
  int local_38;
  uint local_34;
  uint local_30;
  
  local_30 = DAT_0001f184;
  lVar5 = 200;
  uVar4 = 4;
  local_250 = 200;
  local_38 = 0;
  local_34 = 0;
  local_240[0] = L'\0';
  if ((param_1 != (wchar_t *)0x0) && (pwVar1 = wcstok(param_1,L" \t"), pwVar1 != (wchar_t *)0x0)) {
    iVar2 = _wcsicmp(pwVar1,L"on");
    if (iVar2 == 0) {
      iVar3 = 1;
    }
    else {
      iVar2 = _wcsicmp(pwVar1,L"off");
      iVar3 = 2;
      if (iVar2 != 0) {
        iVar3 = 0;
      }
    }
    if (iVar3 != 0) {
      if (iVar3 != 1) {
        ProfileStop();
        if (((DAT_0001f294 != 0) &&
            (pwVar1 = wcstok((wchar_t *)0x0,L" \t"), pwVar1 != (wchar_t *)0x0)) &&
           (iVar2 = wcscmp(pwVar1,L"-flush"), iVar2 == 0)) {
          pwVar1 = wcstok((wchar_t *)0x0,L"\"");
          if (pwVar1 == (wchar_t *)0x0) {
            wcscpy(local_240,L"\\release\\celog.clg");
          }
          else {
            param_3 = 0x104;
            wcsncpy(local_240,pwVar1,0x104);
            local_3a = 0;
          }
          local_38 = 1;
        }
        if ((local_38 == 0) ||
           (iVar2 = FUN_0001bf5c(local_38,(uint)local_240,param_3,param_4), iVar2 != 0)) {
          DAT_0001f294 = 0;
        }
        goto LAB_0001d0a0;
      }
      pwVar1 = wcstok((wchar_t *)0x0,L" \t");
      if (pwVar1 != (wchar_t *)0x0) {
        local_248 = L"-m";
LAB_0001cefc:
        iVar2 = wcscmp(pwVar1,local_248);
        if (iVar2 == 0) {
          uVar4 = uVar4 & 0xfffffffc;
        }
        else {
          iVar2 = wcscmp(pwVar1,L"-s");
          if (iVar2 == 0) {
            uVar4 = uVar4 & 0xfffffffd | 1;
          }
          else {
            iVar2 = wcscmp(pwVar1,L"-k");
            if (iVar2 == 0) {
              uVar4 = uVar4 & 0xfffffffe | 2;
            }
            else {
              iVar2 = wcscmp(pwVar1,L"-b");
              if (iVar2 == 0) {
                uVar4 = uVar4 & 0xffffffbf | 4;
LAB_0001d11c:
                lVar5 = 200;
                local_250 = lVar5;
              }
              else {
                iVar2 = wcscmp(pwVar1,L"-u");
                if (iVar2 == 0) {
                  uVar4 = uVar4 & 0xffffffbb;
                  lVar5 = 1000;
                  local_250 = lVar5;
                }
                else {
                  iVar2 = wcscmp(pwVar1,L"-l");
                  if (iVar2 == 0) {
                    uVar4 = uVar4 & 0xfffffffb | 0x40;
                    goto LAB_0001d11c;
                  }
                  iVar2 = wcscmp(pwVar1,L"-i");
                  if (iVar2 == 0) {
                    local_24c = wcstok((wchar_t *)0x0,L" \t");
                    iVar2 = FUN_0001b5c8(&local_24c,&local_250);
                    lVar5 = local_250;
                  }
                  else {
                    iVar2 = wcscmp(pwVar1,L"-buf");
                    if (iVar2 != 0) {
                      iVar2 = wcscmp(pwVar1,L"-clear");
                      if (iVar2 == 0) {
                        local_38 = 2;
                        goto LAB_0001d14c;
                      }
                      iVar2 = wcscmp(pwVar1,L"-stack");
                      if (iVar2 == 0) {
                        uVar4 = uVar4 & 0xfffffffb | 0x840;
                        goto LAB_0001d11c;
                      }
                      iVar2 = wcscmp(pwVar1,L"inproc");
                      if (iVar2 != 0) goto LAB_0001d098;
                      if ((uVar4 & 0x800) != 0) {
                        uVar4 = uVar4 | 0x1000;
                      }
                      goto LAB_0001d14c;
                    }
                    local_24c = wcstok((wchar_t *)0x0,L" \t");
                    iVar2 = FUN_0001b5c8(&local_24c,(long *)&local_34);
                  }
                  if (iVar2 == 0) goto LAB_0001d098;
                }
              }
            }
          }
        }
LAB_0001d14c:
        pwVar1 = wcstok((wchar_t *)0x0,L" \t");
        if (pwVar1 == (wchar_t *)0x0) goto LAB_0001d16c;
        goto LAB_0001cefc;
      }
LAB_0001d16c:
      if ((uVar4 & 0x40) == 0) {
        if (local_34 == 0) {
          if (local_38 == 0) goto LAB_0001d210;
          pwVar1 = L"\"-clear\" option ignored, only used with CeLog\r\n";
        }
        else {
          pwVar1 = L"Buffer size ignored, only used with CeLog\r\n";
        }
        FUN_0001e194(pwVar1);
      }
      else {
        if (local_34 != 0) {
          FUN_0001bf5c(3,local_34,param_3,param_4);
        }
        if ((((_DAT_00005b68 & 0x30000000) == 0) && (iVar2 = FUN_00017c38(1), iVar2 == 0)) ||
           ((local_38 != 0 &&
            (iVar2 = FUN_0001bf5c(local_38,(uint)local_240,param_3,param_4), iVar2 == 0))))
        goto LAB_0001d0a0;
        DAT_0001f294 = 1;
      }
LAB_0001d210:
      ProfileStart(lVar5,uVar4);
      goto LAB_0001d0a0;
    }
  }
LAB_0001d098:
  FUN_0001cc54();
LAB_0001d0a0:
  FUN_0001e3d4(local_30);
  return 1;
}



/* 0001d2d0 FUN_0001d2d0 */

/* Boundary evidence: original MIPS .pdata 0001d2d0..0001d447. Semantic name remains unreviewed. */

undefined4 FUN_0001d2d0(wchar_t *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 *puVar1;
  undefined4 *hMem;
  wchar_t *pwVar2;
  int iVar3;
  
  pwVar2 = wcstok(param_1,L" \t");
  do {
    puVar1 = DAT_0001f710;
    if (pwVar2 == (wchar_t *)0x0) {
      for (; puVar1 != (undefined4 *)0x0; puVar1 = (undefined4 *)*puVar1) {
        FUN_00017be8(L"  DLL=%s, Name=%s\r\n",puVar1[2],puVar1[1],param_4);
      }
      return 1;
    }
    iVar3 = wcscmp(pwVar2,L"-u");
    if (iVar3 == 0) {
      pwVar2 = wcstok((wchar_t *)0x0,L" \t");
      if (pwVar2 != (wchar_t *)0x0) {
        puVar1 = (undefined4 *)0x0;
        for (hMem = DAT_0001f710; hMem != (HLOCAL)0x0; hMem = (undefined4 *)*hMem) {
          iVar3 = _wcsicmp((wchar_t *)hMem[2],pwVar2);
          if (iVar3 == 0) {
            if (puVar1 == (undefined4 *)0x0) {
              DAT_0001f710 = (undefined4 *)*hMem;
            }
            else {
              *puVar1 = *hMem;
            }
            LocalFree((HLOCAL)hMem[2]);
            LocalFree((HLOCAL)hMem[1]);
            FreeLibrary((HMODULE)hMem[3]);
            LocalFree(hMem);
            break;
          }
          puVar1 = hMem;
        }
      }
    }
    else {
      FUN_00017e38(pwVar2,pwVar2,param_3,param_4);
    }
    pwVar2 = wcstok((wchar_t *)0x0,L" \t");
  } while( true );
}



/* 0001d448 FUN_0001d448 */

/* Boundary evidence: original MIPS .pdata 0001d448..0001d66f. Semantic name remains unreviewed. */

undefined4 FUN_0001d448(wchar_t *param_1,undefined4 param_2,DWORD param_3,undefined4 param_4)

{
  wchar_t *pwVar1;
  int iVar2;
  size_t sVar3;
  HANDLE hObject;
  undefined4 uVar4;
  DWORD *pDVar5;
  long lVar6;
  DWORD dwThreadId;
  
  dwThreadId = 0;
  lVar6 = -1;
  pwVar1 = wcstok(param_1,L" \t");
  if (pwVar1 != (wchar_t *)0x0) {
    do {
      iVar2 = wcscmp(pwVar1,L"kitlintr");
      if (iVar2 == 0) {
        pDVar5 = (DWORD *)&DAT_000058cc;
LAB_0001d4d0:
        dwThreadId = *pDVar5;
      }
      else {
        iVar2 = wcscmp(pwVar1,L"kitltimer");
        if (iVar2 == 0) {
          pDVar5 = (DWORD *)&DAT_000058d0;
          goto LAB_0001d4d0;
        }
        if (dwThreadId == 0) {
          dwThreadId = _wtol(pwVar1);
        }
        else {
          lVar6 = _wtol(pwVar1);
          if ((lVar6 == 0) && ((*pwVar1 != L'0' || (sVar3 = wcslen(pwVar1), 1 < sVar3)))) {
            lVar6 = -2;
          }
        }
      }
      pwVar1 = wcstok((wchar_t *)0x0,L" \t");
    } while (pwVar1 != (wchar_t *)0x0);
    if (dwThreadId != 0) {
      if ((lVar6 < -1) || (0xff < lVar6)) {
        pwVar1 = L"Invalid priority for Thread id 0x%8.8lx.\r\n";
      }
      else {
        param_3 = dwThreadId;
        hObject = OpenThread(0x1f03ff,0,dwThreadId);
        if (hObject != (HANDLE)0x0) {
          if (lVar6 < 0) {
            uVar4 = CeGetThreadPriority(hObject);
            FUN_00017be8(L"Thread 0x%08x current priority: %d\r\n",hObject,uVar4,param_4);
          }
          else {
            iVar2 = CeSetThreadPriority(hObject,lVar6);
            if (iVar2 == 0) {
              pwVar1 = L"FAILED";
            }
            else {
              pwVar1 = L"OK";
            }
            FUN_00017be8(L"Thread 0x%08x priority --> %d %s\r\n",hObject,lVar6,pwVar1);
          }
          CloseHandle(hObject);
          return 1;
        }
        pwVar1 = L"Invalid Thread id 0x%8.8lx\r\n";
      }
      FUN_00017be8(pwVar1,dwThreadId,param_3,param_4);
      return 1;
    }
  }
  FUN_00017be8(L"Invalid parameter. ThreadId: 0x%08x, Priority: %d\r\n",0,lVar6,param_4);
  return 1;
}



/* 0001d670 FUN_0001d670 */

/* Boundary evidence: original MIPS .pdata 0001d670..0001d7af. Semantic name remains unreviewed. */

undefined4 FUN_0001d670(LPCWSTR param_1)

{
  HANDLE hFindFile;
  DWORD local_248;
  DWORD local_244;
  DWORD local_240;
  DWORD local_23c;
  DWORD local_238;
  DWORD local_234;
  DWORD local_230;
  DWORD local_22c;
  DWORD local_228;
  uint local_18;
  
  local_18 = DAT_0001f184;
  local_248 = 0;
  memset(&local_244,0,0x22c);
  hFindFile = FindFirstFileW(param_1,(LPWIN32_FIND_DATAW)&local_248);
  if (hFindFile == (HANDLE)0xffffffff) {
    StringCbPrintfW((STRSAFE_LPWSTR)&DAT_0001f2e0,DAT_0001f18c,
                    L"Attributes    FileSize(b)   CreateTime(L) CreateTime(H) AccessTime(L) AccessTime(H) WriteTime(L)  WriteTime(H)\r\n0x%8.8lx    0x%8.8lx    0x%8.8lx    0x%8.8lx    0x%8.8lx    0x%8.8lx    0x%8.8lx    0x%8.8lx\r\n"
                    ,0xffffffff,0,0,0,0,0,0,0);
  }
  else {
    StringCbPrintfW((STRSAFE_LPWSTR)&DAT_0001f2e0,DAT_0001f18c,
                    L"Attributes    FileSize(b)   CreateTime(L) CreateTime(H) AccessTime(L) AccessTime(H) WriteTime(L)  WriteTime(H)\r\n0x%8.8lx    0x%8.8lx    0x%8.8lx    0x%8.8lx    0x%8.8lx    0x%8.8lx    0x%8.8lx    0x%8.8lx\r\n"
                    ,local_248,local_228 - local_22c,local_244,local_240,local_23c,local_238,
                    local_234,local_230);
    FindClose(hFindFile);
  }
  FUN_0001e194((wchar_t *)&DAT_0001f2e0);
  FUN_0001e3d4(local_18);
  return 1;
}



/* 0001d7b0 FUN_0001d7b0 */

/* Boundary evidence: original MIPS .pdata 0001d7b0..0001dc17. Semantic name remains unreviewed. */

undefined4 FUN_0001d7b0(undefined4 param_1,undefined4 param_2,wchar_t *param_3)

{
  bool bVar1;
  int iVar2;
  HANDLE hHandle;
  LSTATUS LVar3;
  undefined2 *puVar4;
  wchar_t _C;
  long lVar5;
  undefined4 uVar6;
  undefined4 local_38;
  HKEY local_34;
  DWORD local_30;
  DWORD local_2c;
  
  lVar5 = 0;
  if (param_3 != (wchar_t *)0x0) {
LAB_0001d80c:
    _C = *param_3;
    if (_C != L'\0') {
      while (iVar2 = iswctype(_C,8), iVar2 != 0) {
        param_3 = param_3 + 1;
        _C = *param_3;
      }
      iVar2 = wcsncmp(param_3,L"-c",2);
      if (iVar2 == 0) {
LAB_0001d86c:
        DAT_0001f2ac = 1;
        param_3 = param_3 + 2;
LAB_0001d8cc:
        if (param_3 != (wchar_t *)0x0) goto LAB_0001d8d4;
      }
      else {
        iVar2 = wcsncmp(param_3,L"-d",2);
        if (iVar2 == 0) {
          DAT_0001f700 = 1;
          goto LAB_0001d86c;
        }
        iVar2 = wcsncmp(param_3,L"-r",2);
        if (iVar2 == 0) {
          param_3 = param_3 + 2;
          while (iVar2 = iswctype(*param_3,8), iVar2 != 0) {
            param_3 = param_3 + 1;
          }
        }
        else {
          iVar2 = iswctype(*param_3,4);
          if (iVar2 != 0) {
            lVar5 = _wtol(param_3);
            while (iVar2 = iswctype(*param_3,4), iVar2 != 0) {
              param_3 = param_3 + 1;
            }
            goto LAB_0001d8cc;
          }
        }
      }
    }
    goto LAB_0001d924;
  }
LAB_0001d938:
  FUN_0001decc();
  if (DAT_0001f2ac == 0) {
    hHandle = OpenEventW(0x1f0003,0,L"ReleaseFSD");
    if (hHandle == (HANDLE)0x0) {
      return 0;
    }
    WaitForSingleObject(hHandle,0xffffffff);
    PPSHRestart();
  }
  DAT_0001f2b4 = VirtualAlloc((LPVOID)0x0,0x2000,0x3000,4);
  if (DAT_0001f2b4 == (LPVOID)0x0) {
    FUN_0001e194(L"\r\n\r\nWindows CE Shell - unable to initialize!\r\n");
  }
  else {
    KernelLibIoControl(1,0x1b,0,0,&DAT_0001f6f0,0x10,0);
    FUN_0001e194(L"\r\n\r\nWelcome to the Windows CE Shell. Type ? for help.\r\n");
    uVar6 = 0x82;
    LVar3 = RegOpenKeyExW((HKEY)0x80000002,L"Software\\Microsoft\\TxtShell",0,0,&local_34);
    if (LVar3 == 0) {
      local_30 = 4;
      local_38 = 0;
      LVar3 = RegQueryValueExW(local_34,L"MainThreadPrio",(LPDWORD)0x0,&local_2c,(LPBYTE)&local_38,
                               &local_30);
      if ((LVar3 == 0) && (local_2c == 4)) {
        uVar6 = local_38;
      }
      RegCloseKey(local_34);
    }
    CeSetThreadPriority(0x41,uVar6);
    FUN_00018010();
    if ((param_3 == (wchar_t *)0x0) || (*param_3 == L'\0')) {
      DAT_0001f284 = OpenEventW(0x1f0003,0,(LPCWSTR)PTR_u_SYSTEM_GweApiSetReady_0001f190);
      DAT_0001f700 = 0;
      bVar1 = true;
      do {
        if (DAT_0001f2ac == 0) {
          PPSHRestart();
        }
        FUN_0001e194(L"Windows CE>");
        puVar4 = FUN_0001e0b4((undefined2 *)&DAT_0001f720,0x900);
        if (puVar4 == (undefined2 *)0x0) {
LAB_0001db88:
          if (!bVar1) goto LAB_0001dbbc;
        }
        else {
          do {
            iVar2 = FUN_000187ac(0x1f720);
            if (iVar2 == 0) {
              bVar1 = false;
              goto LAB_0001db88;
            }
            FUN_0001e194(L"Windows CE>");
            puVar4 = FUN_0001e0b4((undefined2 *)&DAT_0001f720,0x900);
          } while (puVar4 != (undefined2 *)0x0);
        }
        bVar1 = false;
        Sleep(1000);
        FUN_0001decc();
        FUN_0001e194(L"\r\n\r\nWelcome to the Windows CE Shell. Type ? for help.\r\n");
      } while( true );
    }
    FUN_000187ac((int)param_3);
LAB_0001dbbc:
    VirtualFree(DAT_0001f2b4,0,0x8000);
    if (DAT_0001f284 != (HANDLE)0x0) {
      CloseHandle(DAT_0001f284);
    }
  }
  return 1;
LAB_0001d8d4:
  do {
    iVar2 = iswctype(*param_3,8);
    if (iVar2 == 0) break;
    param_3 = param_3 + 1;
  } while (param_3 != (wchar_t *)0x0);
  if (param_3 == (wchar_t *)0x0) {
LAB_0001d924:
    if (lVar5 != 0) {
      SignalStarted(lVar5);
    }
    goto LAB_0001d938;
  }
  goto LAB_0001d80c;
}



/* 0001dc18 FUN_0001dc18 */

/* Boundary evidence: original MIPS .pdata 0001dc18..0001dde7. Semantic name remains unreviewed. */

undefined4 FUN_0001dc18(int param_1,undefined4 param_2,undefined4 param_3,LPFILETIME param_4)

{
  bool bVar1;
  int iVar2;
  HANDLE hProcess;
  BOOL BVar3;
  wchar_t *pwVar4;
  wchar_t *pwVar5;
  uint uVar6;
  int *piVar7;
  uint uVar8;
  uint local_40;
  int local_3c;
  wchar_t awStack_38 [6];
  uint local_2c;
  
  local_2c = DAT_0001f184;
  bVar1 = true;
  local_40 = 0;
  local_3c = param_1;
  if (DAT_0001f2c8 == 0) {
    pwVar4 = L"proc";
    pwVar5 = (wchar_t *)0xa;
    memcpy(awStack_38,L"proc",10);
    FUN_00019544(awStack_38,pwVar4,pwVar5,param_4);
  }
  if (param_1 != 0) {
    do {
      iVar2 = FUN_0001b5c8(&local_3c,(long *)&local_40);
      if (iVar2 == 0) break;
      if (local_40 < DAT_0001f2c8) {
        uVar8 = 0;
        piVar7 = (int *)DAT_00020920;
        if (local_40 != 0) {
          do {
            if (piVar7 == (int *)0x0) goto LAB_0001dd10;
            uVar8 = uVar8 + 1;
            piVar7 = (int *)*piVar7;
          } while (uVar8 < local_40);
        }
        if (piVar7 != (int *)0x0) {
          local_40 = *(DWORD *)((int)piVar7 + 4);
        }
      }
LAB_0001dd10:
      uVar8 = local_40;
      if (local_40 != 0) {
        uVar6 = local_40;
        hProcess = OpenProcess(0x1f0fff,0,local_40);
        FUN_00017be8(L"Attempting to kill process of id %08x ...",uVar8,uVar6,param_4);
        if (hProcess == (HANDLE)0x0) {
          FUN_00017be8(L"Unable to open process %d\r\n\r\n",uVar8,uVar6,param_4);
        }
        else {
          BVar3 = TerminateProcess(hProcess,0);
          pwVar4 = L"Succeeded\r\n\r\n";
          if (BVar3 == 0) {
            pwVar4 = L"Failed\r\n\r\n";
          }
          FUN_0001e194(pwVar4);
          CloseHandle(hProcess);
        }
      }
      bVar1 = false;
    } while (local_3c != 0);
    if (!bVar1) goto LAB_0001ddb0;
  }
  FUN_0001e194(L"Syntax: kp <pid> [<pid2> <pid3> ...]\r\n\r\n");
LAB_0001ddb0:
  FUN_0001e3d4(local_2c);
  return 1;
}



/* 0001dde8 FUN_0001dde8 */

/* Boundary evidence: original MIPS .pdata 0001dde8..0001decb. Semantic name remains unreviewed. */

undefined4 FUN_0001dde8(short *param_1)

{
  int iVar1;
  wchar_t *pwVar2;
  short *local_res0 [4];
  uint local_18;
  uint local_14;
  DWORD local_10 [2];
  
  local_18 = 0x10;
  local_res0[0] = param_1;
  if (((param_1 == (short *)0x0) || (iVar1 = FUN_0001b5c8(local_res0,(long *)local_10), iVar1 == 0))
     || (iVar1 = FUN_0001b5c8(local_res0,(long *)&local_14), iVar1 == 0)) {
    pwVar2 = L"Syntax: dd <process id> <addr> [<#dwords>]\r\n";
  }
  else {
    iVar1 = FUN_0001b5c8(local_res0,(long *)&local_18);
    if ((iVar1 == 0) && (*local_res0[0] != 0)) {
      pwVar2 = L"Syntax: dd <process id> <addr> [<#dwords>]\r\n";
    }
    else {
      if ((local_18 != 0) && (local_18 < 0x100001)) {
        FUN_00018ecc((HANDLE)0xffffffff,local_10[0],(LPCVOID)(local_14 & 0xfffffffc),local_18 << 2);
        return 1;
      }
      pwVar2 = L"dd: Invalid Length\r\n";
    }
  }
  FUN_0001e194(pwVar2);
  return 1;
}



/* 0001decc FUN_0001decc */

/* Boundary evidence: original MIPS .pdata 0001decc..0001e033. Semantic name remains unreviewed. */

undefined4 FUN_0001decc(void)

{
  HMODULE pHVar1;
  
  if (DAT_0001f2ac != 0) {
    pHVar1 = LoadLibraryW(L"COREDLL.DLL");
    if (pHVar1 == (HMODULE)0x0) {
      DAT_0001f2ac = 0;
    }
    else {
      DAT_0001f2a0 = GetProcAddressW(pHVar1,L"fgetws");
      DAT_0001f2a8 = GetProcAddressW(pHVar1,L"fputws");
      DAT_0001f298 = GetProcAddressW(pHVar1,L"OutputDebugStringW");
      DAT_0001f29c = GetProcAddressW(pHVar1,L"_getstdfilex");
      if (((DAT_0001f2a8 == 0) || (DAT_0001f2a0 == 0)) || (DAT_0001f29c == 0)) {
        DAT_0001f2ac = 0;
      }
      if (DAT_0001f2ac != 0) {
        return 1;
      }
    }
  }
  DAT_0001f2a4 = FUN_00017ac0(L"con",0x10002);
  if (DAT_0001f2a4 == (HANDLE)0xffffffff) {
    DAT_0001f2a4 = (HANDLE)0xffffffff;
    do {
      Sleep(2000);
      DAT_0001f2a4 = FUN_00017ac0(L"con",0x10002);
    } while (DAT_0001f2a4 == (HANDLE)0xffffffff);
  }
  return 1;
}



/* 0001e034 FUN_0001e034 */

/* Boundary evidence: original MIPS .pdata 0001e034..0001e0b3. Semantic name remains unreviewed. */

uint FUN_0001e034(void)

{
  DWORD DVar1;
  uint uVar2;
  byte local_18 [8];
  
  uVar2 = 0xffffffff;
  if (DAT_0001f2a4 != (HANDLE)0xffffffff) {
    while (DVar1 = FUN_00017b70(DAT_0001f2a4,local_18,1), DVar1 == 0) {
      Sleep(1000);
    }
    if (DVar1 != 0xffffffff) {
      uVar2 = (uint)local_18[0];
    }
  }
  return uVar2;
}



/* 0001e0b4 FUN_0001e0b4 */

/* Boundary evidence: original MIPS .pdata 0001e0b4..0001e193. Semantic name remains unreviewed. */

undefined2 * FUN_0001e0b4(undefined2 *param_1,int param_2)

{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  undefined2 *puVar4;
  
  iVar3 = 0;
  if (DAT_0001f2ac == 0) {
    puVar4 = param_1;
    if (param_2 + -1 < 1) {
LAB_0001e170:
      param_1 = (undefined2 *)0x0;
    }
    else {
      do {
        uVar2 = FUN_0001e034();
        if (uVar2 == 0xffffffff) goto LAB_0001e170;
        *puVar4 = (short)uVar2;
        if ((uVar2 & 0xffff) == 0xd) break;
        iVar3 = iVar3 + 1;
        puVar4 = puVar4 + 1;
      } while (iVar3 < param_2 + -1);
      param_1[iVar3] = 0;
    }
  }
  else {
    DAT_0001f700 = 0;
    uVar1 = (*DAT_0001f29c)(0);
    param_1 = (undefined2 *)(*DAT_0001f2a0)(param_1,param_2,uVar1);
  }
  return param_1;
}



/* 0001e194 FUN_0001e194 */

/* Boundary evidence: original MIPS .pdata 0001e194..0001e293. Semantic name remains unreviewed. */

DWORD FUN_0001e194(wchar_t *param_1)

{
  undefined4 uVar1;
  DWORD DVar2;
  size_t sVar3;
  char acStack_118 [256];
  uint local_18;
  
  local_18 = DAT_0001f184;
  if (DAT_0001f2ac == 0) {
    DVar2 = 0xffffffff;
    if ((DAT_0001f2a4 != (HANDLE)0xffffffff) &&
       (sVar3 = wcstombs(acStack_118,param_1,0x100), sVar3 != 0xffffffff)) {
      DVar2 = FUN_00017bac(DAT_0001f2a4,acStack_118,sVar3);
    }
  }
  else {
    if ((DAT_0001f700 != 0) && (DAT_0001f298 != (code *)0x0)) {
      (*DAT_0001f298)(param_1);
      FUN_0001e3d4(local_18);
      return 1;
    }
    uVar1 = (*DAT_0001f29c)(1);
    DVar2 = (*DAT_0001f2a8)(param_1,uVar1);
  }
  FUN_0001e3d4(local_18);
  return DVar2;
}



/* 0001e354 FUN_0001e354 */

/* Boundary evidence: original MIPS .pdata 0001e354..0001e3a7. Semantic name remains unreviewed. */

void FUN_0001e354(int param_1,undefined4 param_2,uint *param_3)

{
  if ((*param_3 & 1) != 0) {
    param_1 = ((-param_3[2] & param_3[1] + param_1) - (param_3[1] + param_1)) + param_1;
  }
  FUN_0001e3d4(*(uint *)(param_1 + (*param_3 & 0xfffffffc)));
  return;
}



/* 0001e3a8 FUN_0001e3a8 */

/* Boundary evidence: original MIPS .pdata 0001e3a8..0001e3d3. Semantic name remains unreviewed. */

undefined4 FUN_0001e3a8(undefined4 param_1,int param_2,undefined4 param_3,int param_4)

{
  FUN_0001e354(param_2,param_4,*(uint **)(*(int *)(param_4 + 4) + 0xc));
  return 1;
}



/* 0001e3d4 FUN_0001e3d4 */

/* Boundary evidence: original MIPS .pdata 0001e3d4..0001e41b. Semantic name remains unreviewed. */

void FUN_0001e3d4(uint param_1)

{
  if ((param_1 == DAT_0001f184) && (param_1 >> 0x10 == 0)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __report_gsfailure();
}



/* 0001e41c FUN_0001e41c */

/* Boundary evidence: original MIPS .pdata 0001e41c..0001e497. Semantic name remains unreviewed. */

void FUN_0001e41c(undefined4 param_1,int param_2,undefined4 param_3,int param_4)

{
  int *piVar1;
  
  piVar1 = *(int **)(*(int *)(param_4 + 4) + 0xc);
  FUN_0001e354(param_2,param_4,(uint *)(piVar1 + *piVar1 * 4 + 1));
  __C_specific_handler(param_1,param_2,param_3,param_4);
  return;
}


