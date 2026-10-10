/* Automatic Ghidra pseudocode. Not original source; not runtime-verified. */

/* c082202c DllMain */

/* Boundary evidence: original MIPS .pdata c082202c..c08220cf. Semantic name remains unreviewed. */

undefined4 DllMain(HMODULE param_1,int param_2)

{
  undefined4 uVar1;
  
                    /* 0x202c  8  DllMain */
  NKDbgPrintfW(L"USBware::DllMain: Started hModule 0x%08X, dwReason %lu\r\n",param_1,param_2);
  if (param_2 == 0) {
    uVar1 = __GetUserKData(0xc);
    NKDbgPrintfW(L"USBware::DllMain: Detach called - Current Process: 0x%08X, ID: 0x%08X\r\n",0x42,
                 uVar1);
  }
  else if (param_2 == 1) {
    uVar1 = __GetUserKData(0xc);
    NKDbgPrintfW(L"USBware::DllMain: Attach called - Current Process: 0x%08X, ID: 0x%08X\r\n",0x42,
                 uVar1);
    DisableThreadLibraryCalls(param_1);
  }
  return 1;
}



/* c08220d0 UDD_Init */

/* Boundary evidence: original MIPS .pdata c08220d0..c08221eb. Semantic name remains unreviewed. */

int UDD_Init(int param_1)

{
  LSTATUS LVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  wchar_t *pwVar4;
  wchar_t *pwVar5;
  HKEY local_20;
  DWORD local_1c;
  int local_18 [2];
  
                    /* 0x20d0  4  UDD_Init */
  NKDbgPrintfW(L"USBware::UDD_Init: Starting pContext 0x%08X\r\n",param_1);
  pwVar4 = L"Drivers\\BuiltIn\\UDD";
  uVar3 = 0;
  uVar2 = 0;
  LVar1 = RegOpenKeyExW((HKEY)0x80000002,L"Drivers\\BuiltIn\\UDD",0,0,&local_20);
  if (LVar1 == 0) {
    local_1c = 4;
    pwVar5 = L"EnableStack";
    uVar3 = 0;
    uVar2 = 0;
    pwVar4 = pwVar5;
    LVar1 = RegQueryValueExW(local_20,L"EnableStack",(LPDWORD)0x0,(LPDWORD)0x0,(LPBYTE)local_18,
                             &local_1c);
    if (LVar1 == 0) {
      if (local_18[0] == 0) {
        NKDbgPrintfW(L"UDD_Init:Registry Indicates that Device should NOT continue Init. Exiting.\r\n"
                     ,L"EnableStack");
        return 0;
      }
    }
    else {
      NKDbgPrintfW(L"UDD_Init:RegQueryValueEx(%s) failed\r\n");
      pwVar4 = pwVar5;
    }
    RegCloseKey(local_20);
  }
  else {
    NKDbgPrintfW(L"UDD_Init:RegOpenKeyEx(%s) failed\r\n");
  }
  FUN_c0822974(param_1,pwVar4,uVar2,uVar3);
  return param_1;
}



/* c08221ec UDD_Deinit */

/* Boundary evidence: original MIPS .pdata c08221ec..c0822227. Semantic name remains unreviewed. */

undefined4 UDD_Deinit(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  
  uVar1 = param_1;
                    /* 0x21ec  2  UDD_Deinit */
  NKDbgPrintfW(L"USBware::UDD_Deinit: Started pContext 0x%08X\r\n");
  FUN_c0822a04(param_1,uVar1,param_3,param_4);
  return param_1;
}



/* c0822228 UDD_Open */

/* Boundary evidence: original MIPS .pdata c0822228..c082225b. Semantic name remains unreviewed. */

undefined4 UDD_Open(undefined4 param_1)

{
                    /* 0x2228  5  UDD_Open */
  NKDbgPrintfW(L"USBware::UDD_Open: Started pContext 0x%08X\r\n",param_1);
  return param_1;
}



/* c082225c UDD_Close */

/* Boundary evidence: original MIPS .pdata c082225c..c082228f. Semantic name remains unreviewed. */

undefined4 UDD_Close(undefined4 param_1)

{
                    /* 0x225c  1  UDD_Close */
  NKDbgPrintfW(L"USBware::UDD_Close: Started pContext 0x%08X\r\n",param_1);
  return param_1;
}



/* c0822290 UDD_PowerUp */

/* Boundary evidence: original MIPS .pdata c0822290..c08222c3. Semantic name remains unreviewed. */

undefined4 UDD_PowerUp(undefined4 param_1)

{
                    /* 0x2290  7  UDD_PowerUp */
  NKDbgPrintfW(L"USBware::UDD_PowerUp: Started pContext 0x%08X\r\n",param_1);
  return param_1;
}



/* c08222c4 UDD_PowerDown */

/* Boundary evidence: original MIPS .pdata c08222c4..c08222f7. Semantic name remains unreviewed. */

undefined4 UDD_PowerDown(undefined4 param_1)

{
                    /* 0x22c4  6  UDD_PowerDown */
  NKDbgPrintfW(L"USBware::UDD_PowerDown: Started pContext 0x%08X\r\n",param_1);
  return param_1;
}



/* c08222f8 UDD_IOControl */

/* Boundary evidence: original MIPS .pdata c08222f8..c082231f. Semantic name remains unreviewed. */

undefined4 UDD_IOControl(undefined4 param_1)

{
                    /* 0x22f8  3  UDD_IOControl */
  NKDbgPrintfW(L"USBware::UDD_IOControl: Started pContext 0x%08X\r\n",param_1);
  return 1;
}



/* c0822320 FUN_c0822320 */

/* Boundary evidence: original MIPS .pdata c0822320..c08223e3. Semantic name remains unreviewed. */

undefined4 FUN_c0822320(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  
  if (param_1 == 0x1004) {
    *(undefined4 *)(param_3 + 0xc) = 1;
    *(undefined4 *)(param_3 + 0x14) = 4;
    iVar1 = param_2 + 4;
    iVar2 = param_2 + 8;
  }
  else if (param_1 == 0x1005) {
    *(undefined4 *)(param_3 + 0xc) = 1;
    *(undefined4 *)(param_3 + 0x14) = 4;
    iVar1 = param_2 + 0xc;
    iVar2 = param_2 + 0x10;
  }
  else {
    if (((param_1 != 0x100a) && (param_1 != 0x2012)) && (param_1 != 0x4005)) {
      NKDbgPrintfW(L"get_interrupt_data: unknown controller type %lx\n",param_1);
      return 1;
    }
    *(undefined4 *)(param_3 + 0xc) = 1;
    *(undefined4 *)(param_3 + 0x14) = 4;
    iVar1 = param_2 + 0x14;
    iVar2 = param_2 + 0x18;
  }
  *(int *)(param_3 + 0x10) = iVar1;
  *(int *)(param_3 + 0x1c) = iVar2;
  return 0;
}



/* c08223e4 FUN_c08223e4 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Boundary evidence: original MIPS .pdata c08223e4..c08224cf. Semantic name remains unreviewed. */

void FUN_c08223e4(void)

{
  _DAT_b4021000 = _DAT_b4021000 & 0xfffffffa;
  Sleep(0x19);
  _DAT_b4021000 = _DAT_b4021000 | 1;
  _DAT_b4021004 = _DAT_b4021004 | 7;
  Sleep(0x19);
  _DAT_b4021020 = 0x10004;
  Sleep(2);
  _DAT_b4021020 = 4;
  _DAT_b402101c = _DAT_b402101c | 0x10000;
  _DAT_b40210c8 = _DAT_b40210c8 | 8;
  _DAT_b402102c = _DAT_b402102c & 0xfffffffc;
  return;
}



/* c08224d0 FUN_c08224d0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Boundary evidence: original MIPS .pdata c08224d0..c082258b. Semantic name remains unreviewed. */

void FUN_c08224d0(void)

{
  _DAT_b4021000 = _DAT_b4021000 & 0xfffffffe;
  _DAT_b4021020 = 0x10004;
  Sleep(2);
  _DAT_b4021020 = 4;
  _DAT_b4021004 = _DAT_b4021004 | 8;
  _DAT_b402101c = _DAT_b402101c | 0x10003;
  _DAT_b4021000 = _DAT_b4021000 | 1;
  Sleep(0x19);
  return;
}



/* c082258c FUN_c082258c */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Boundary evidence: original MIPS .pdata c082258c..c082266f. Semantic name remains unreviewed. */

void FUN_c082258c(void)

{
  _DAT_b4021004 = _DAT_b4021004 & 0xfffffffa;
  Sleep(0x19);
  _DAT_b402101c = _DAT_b402101c & 0xfff1fffc;
  if ((_DAT_b40210c4 & 0x10) != 0) {
    _DAT_b40210c4 = _DAT_b40210c4 | 0x10;
  }
  return;
}



/* c0822670 FUN_c0822670 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Boundary evidence: original MIPS .pdata c0822670..c082273b. Semantic name remains unreviewed. */

void FUN_c0822670(void)

{
  _DAT_b4021004 = _DAT_b4021004 & 0xfffffff7;
  _DAT_b402101c = _DAT_b402101c & 0xfffefffc;
  _DAT_b40210c8 = _DAT_b40210c8 & 0xfffffff7;
  if ((_DAT_b40210c4 & 0x10) != 0) {
    _DAT_b40210c4 = _DAT_b40210c4 | 0x10;
  }
  _DAT_b4021000 = _DAT_b4021000 & 0xfffffffe;
  Sleep(0x19);
  return;
}



/* c082273c FUN_c082273c */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Boundary evidence: original MIPS .pdata c082273c..c082289b. Semantic name remains unreviewed. */

undefined4 FUN_c082273c(uint param_1)

{
  undefined4 uVar1;
  
  NKDbgPrintfW(L"bsp_pre_init: h/w init type %lx\n",param_1);
  if (param_1 < 0x1004) {
LAB_c0822870:
    NKDbgPrintfW(L"bsp_pre_init: Unknown controller type %lx\n",param_1);
    uVar1 = 0;
  }
  else {
    uVar1 = 1;
    if (param_1 < 0x1006) {
      if (DAT_c0839260 != 0) {
        return 1;
      }
      _DAT_b4021000 = _DAT_b4021000 | 2;
      _DAT_b4021004 = _DAT_b4021004 | 7;
      _DAT_b402101c = _DAT_b402101c | 0xe0000;
      _DAT_b402102c = _DAT_b402102c & 0xfffffffd;
      _DAT_b4021034 = 1;
      _DAT_b40210c8 = _DAT_b40210c8 | 7;
      DAT_c0839260 = 1;
      return 1;
    }
    if (param_1 == 0x100a) {
      if (DAT_c0839264 != 0) {
        return 1;
      }
      FUN_c08223e4();
    }
    else {
      if (param_1 != 0x2012) goto LAB_c0822870;
      if (DAT_c0839264 != 0) {
        return 1;
      }
      FUN_c08224d0();
    }
    DAT_c0839264 = DAT_c0839264 + 1;
  }
  return uVar1;
}



/* c082289c FUN_c082289c */

/* Boundary evidence: original MIPS .pdata c082289c..c0822973. Semantic name remains unreviewed. */

void FUN_c082289c(uint param_1)

{
  NKDbgPrintfW(L"bsp_pre_uninit: h/w init type %ld\n",param_1);
  if (0x1003 < param_1) {
    if (param_1 < 0x1006) {
      DAT_c0839260 = DAT_c0839260 + -1;
      if (DAT_c0839260 != 0) {
        return;
      }
      FUN_c082258c();
      return;
    }
    if (param_1 == 0x100a) {
      if (DAT_c0839264 != 0) {
        return;
      }
      DAT_c0839264 = 1;
      return;
    }
    if (param_1 == 0x2012) {
      DAT_c0839264 = DAT_c0839264 + -1;
      if (DAT_c0839264 != 0) {
        return;
      }
      FUN_c0822670();
      return;
    }
  }
  NKDbgPrintfW(L"bsp_pre_init: Unknown controller type %ld\n",param_1);
  return;
}



/* c0822974 FUN_c0822974 */

/* Boundary evidence: original MIPS .pdata c0822974..c0822a03. Semantic name remains unreviewed. */

undefined4 FUN_c0822974(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int local_18;
  undefined4 local_10;
  
  if (param_1 == 0) {
    FUN_c0824430("wince_usbware_entry: Os context is NULL\n",param_2,param_3,param_4);
    local_18 = 10;
  }
  else {
    DAT_c0839280 = param_1;
    local_18 = FUN_c0822a38((int *)0x0,param_2,param_3,param_4);
  }
  if (local_18 == 0) {
    local_10 = 0;
  }
  else {
    local_10 = 0xffffffff;
  }
  return local_10;
}



/* c0822a04 FUN_c0822a04 */

/* Boundary evidence: original MIPS .pdata c0822a04..c0822a37. Semantic name remains unreviewed. */

void FUN_c0822a04(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  char *pcVar1;
  
  pcVar1 = "wince_usbware_exit: Entered\n";
  FUN_c0824430("wince_usbware_exit: Entered\n",param_2,param_3,param_4);
  FUN_c0822d78(pcVar1,param_2,param_3,param_4);
  return;
}



/* c0822a38 FUN_c0822a38 */

/* Boundary evidence: original MIPS .pdata c0822a38..c0822b57. Semantic name remains unreviewed. */

int FUN_c0822a38(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  char *pcVar1;
  int *local_res0;
  int local_10;
  int local_c;
  
  local_c = FUN_c08245b8(param_1,param_2,param_3,param_4);
  if (local_c == 0) {
    local_res0 = param_1;
    if (param_1 == (int *)0x0) {
      local_res0 = (int *)FUN_c082604c();
    }
    local_10 = FUN_c0822b58((int)local_res0,param_2,param_3,param_4);
    if (local_10 == 0) {
      local_10 = FUN_c0825818(local_res0,param_2,param_3,param_4);
      if (local_10 == 0) {
        return 0;
      }
      pcVar1 = FUN_c0825074(local_10);
      FUN_c0824430("%s: Error starting the usb stack %s\n","j_stack_init",pcVar1,param_4);
    }
    else {
      FUN_c0824430("%s: Error customizing uw_args\n","j_stack_init",param_3,param_4);
    }
    FUN_c0824688();
    local_c = local_10;
  }
  else {
    FUN_c0824430("%s: Error initializing memory\n","j_stack_init",param_3,param_4);
  }
  return local_c;
}



/* c0822b58 FUN_c0822b58 */

/* Boundary evidence: original MIPS .pdata c0822b58..c0822d77. Semantic name remains unreviewed. */

int FUN_c0822b58(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int local_20;
  undefined2 local_1c [2];
  undefined2 local_18 [2];
  int local_14;
  undefined2 local_10 [2];
  int local_c;
  
  if ((param_1 == 0) || (*(char *)(param_1 + 4) == '\0')) {
    FUN_c0824430("%s: Broken uw_args\n","customize_args",param_3,param_4);
    local_c = 10;
  }
  else {
    local_20 = FUN_c08234fc(L"vendor",(LPBYTE)local_18,param_3,param_4);
    if (local_20 == 0) {
      local_20 = FUN_c08234fc(L"product",(LPBYTE)local_10,param_3,param_4);
      if (local_20 == 0) {
        local_20 = FUN_c08234fc(L"release",(LPBYTE)local_1c,param_3,param_4);
        if (local_20 == 0) {
          for (local_14 = 0; local_14 < (int)(uint)*(byte *)(param_1 + 4); local_14 = local_14 + 1)
          {
            *(undefined2 *)(*(int *)(*(int *)(param_1 + 8) + local_14 * 0x18 + 0xc) + 6) =
                 local_18[0];
            *(undefined2 *)(*(int *)(*(int *)(param_1 + 8) + local_14 * 0x18 + 0xc) + 8) =
                 local_10[0];
            *(undefined2 *)(*(int *)(*(int *)(param_1 + 8) + local_14 * 0x18 + 0xc) + 10) =
                 local_1c[0];
          }
          return 0;
        }
        FUN_c0824430("%s: Error opening registry value=%s\n","customize_args","release",param_4);
      }
      else {
        FUN_c0824430("%s: Error opening registry value=%s\n","customize_args","product",param_4);
      }
    }
    else {
      FUN_c0824430("%s: Error opening registry value=%s\n","customize_args","vendor",param_4);
    }
    local_c = local_20;
  }
  return local_c;
}



/* c0822d78 FUN_c0822d78 */

/* Boundary evidence: original MIPS .pdata c0822d78..c0822d9f. Semantic name remains unreviewed. */

void FUN_c0822d78(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  FUN_c0825b24(param_1,param_2,param_3,param_4);
  FUN_c0824688();
  return;
}



/* c0822da0 FUN_c0822da0 */

/* Boundary evidence: original MIPS .pdata c0822da0..c0822def. Semantic name remains unreviewed. */

undefined4 FUN_c0822da0(void)

{
  undefined4 uVar1;
  
  uVar1 = FUN_c0826768();
  return uVar1;
}



/* c0822df0 FUN_c0822df0 */

/* Boundary evidence: original MIPS .pdata c0822df0..c0822e17. Semantic name remains unreviewed. */

void FUN_c0822df0(void)

{
  FUN_c082683c();
  DAT_c0839268 = 0;
  return;
}



/* c0822e18 FUN_c0822e18 */

/* Boundary evidence: original MIPS .pdata c0822e18..c0823117. Semantic name remains unreviewed. */

int FUN_c0822e18(int *param_1,int param_2,int param_3,int param_4,int param_5)

{
  HANDLE pvVar1;
  int iVar2;
  int local_1c;
  
  if ((param_1 == (int *)0x0) || (*param_1 != 1)) {
    local_1c = 10;
  }
  else {
    KernelIoControl(0x1010098,param_1 + 3,4,param_1 + 4,4,0,0);
    if (param_1[4] == 0) {
      local_1c = 10;
    }
    else {
      local_1c = FUN_c082327c((int)param_1);
      if (local_1c == 0) {
        pvVar1 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
        param_1[6] = (int)pvVar1;
        if (param_1[6] != 0) {
          pvVar1 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
          param_1[7] = (int)pvVar1;
          if ((param_1[7] != 0) &&
             (iVar2 = InterruptInitialize(param_1[4],param_1[7],0,0), iVar2 != 0)) {
            InterruptDone(param_1[4]);
            param_1[10] = param_2;
            param_1[0xb] = param_3;
            param_1[0xc] = param_4;
            param_1[0xd] = param_5;
            pvVar1 = CreateThread((LPSECURITY_ATTRIBUTES)0x0,0,FUN_c0823118,param_1,0,(LPDWORD)0x0);
            param_1[8] = (int)pvVar1;
            if (param_1[8] != 0) {
              CeSetThreadPriority(param_1[8],5);
              FUN_c08243f8(param_1[6]);
              return 0;
            }
          }
        }
        local_1c = 10;
        if (param_1[5] != 0) {
          FreeIntChainHandler(param_1[5]);
        }
        if (param_1[7] != 0) {
          CloseHandle((HANDLE)param_1[7]);
        }
        if (param_1[6] != 0) {
          CloseHandle((HANDLE)param_1[6]);
        }
      }
    }
  }
  return local_1c;
}



/* c0823118 FUN_c0823118 */

/* Boundary evidence: original MIPS .pdata c0823118..c082327b. Semantic name remains unreviewed. */

undefined4 FUN_c0823118(int param_1)

{
  int iVar1;
  HANDLE hHandle;
  HANDLE hHandle_00;
  undefined4 uVar2;
  
  hHandle = *(HANDLE *)(param_1 + 0x18);
  hHandle_00 = *(HANDLE *)(param_1 + 0x1c);
  uVar2 = *(undefined4 *)(param_1 + 0x10);
  WaitForSingleObject(hHandle,0xffffffff);
  *(undefined4 *)(param_1 + 0x24) = 1;
  while ((*(int *)(param_1 + 0x24) != 0 &&
         (WaitForSingleObject(hHandle_00,0xffffffff), *(int *)(param_1 + 0x24) != 0))) {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c083926c);
    iVar1 = (**(code **)(param_1 + 0x28))(*(undefined4 *)(param_1 + 0x2c));
    if ((iVar1 == 1) && (*(int *)(param_1 + 0x30) != 0)) {
      FUN_c0827790();
      (**(code **)(param_1 + 0x30))(*(undefined4 *)(param_1 + 0x34));
      FUN_c08277b8();
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c083926c);
    InterruptDone(uVar2);
  }
  FUN_c08243f8(hHandle);
  return 0;
}



/* c082327c FUN_c082327c */

/* Boundary evidence: original MIPS .pdata c082327c..c08233ab. Semantic name remains unreviewed. */

undefined4 FUN_c082327c(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_18;
  
  iVar2 = *(int *)(param_1 + 0x3c);
  uVar1 = LoadIntChainHandler(L"giisr.dll",L"ISRHandler",*(uint *)(param_1 + 0xc) & 0xff);
  *(undefined4 *)(param_1 + 0x14) = uVar1;
  if (*(int *)(param_1 + 0x14) == 0) {
    local_18 = 10;
  }
  else {
    iVar2 = CreateStaticMapping(*(undefined4 *)(iVar2 + 8),*(undefined4 *)(iVar2 + 0x10));
    local_38 = *(undefined4 *)(param_1 + 0x10);
    local_34 = 1;
    local_30 = 0;
    iVar2 = FUN_c0822320(*(int *)(param_1 + 8),iVar2,(int)&local_38);
    if (iVar2 == 0) {
      iVar2 = KernelLibIoControl(*(undefined4 *)(param_1 + 0x14),0x100,&local_38,0x20,0,0,0);
      if (iVar2 == 0) {
        local_18 = 10;
      }
      else {
        local_18 = 0;
      }
    }
    else {
      local_18 = 0xb;
    }
  }
  return local_18;
}



/* c08233ac FUN_c08233ac */

/* Boundary evidence: original MIPS .pdata c08233ac..c08234fb. Semantic name remains unreviewed. */

undefined4 FUN_c08233ac(int *param_1)

{
  undefined4 local_14;
  
  if ((param_1 == (int *)0x0) || (*param_1 != 1)) {
    local_14 = 10;
  }
  else {
    if (param_1[5] != 0) {
      FreeIntChainHandler(param_1[5]);
    }
    param_1[9] = 0;
    InterruptDisable(param_1[4]);
    FUN_c08277b8();
    FUN_c08243f8(param_1[7]);
    WaitForSingleObject((HANDLE)param_1[6],0xffffffff);
    FUN_c0827790();
    KernelIoControl(0x10100d8,param_1 + 4,4,0,0,0);
    CloseHandle((HANDLE)param_1[8]);
    CloseHandle((HANDLE)param_1[7]);
    CloseHandle((HANDLE)param_1[6]);
    local_14 = 0;
  }
  return local_14;
}



/* c08234fc FUN_c08234fc */

/* Boundary evidence: original MIPS .pdata c08234fc..c0823643. Semantic name remains unreviewed. */

int FUN_c08234fc(LPCWSTR param_1,LPBYTE param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  int local_228;
  HKEY local_224;
  LSTATUS local_220;
  WCHAR aWStack_218 [256];
  uint local_18;
  int local_14;
  
  local_18 = DAT_c0839254;
  local_224 = (HKEY)0x0;
  local_228 = FUN_c08236e8((LPBYTE)aWStack_218,0x100,param_3,param_4);
  if (local_228 == 0) {
    uVar2 = 0;
    local_220 = RegOpenKeyExW((HKEY)0x80000002,aWStack_218,0,0,&local_224);
    if (local_220 == 0) {
      iVar1 = FUN_c0823644(local_224,param_1,param_2);
      if (iVar1 != 0) {
        FUN_c0824430("%s: Can not read registry\n","get_device_reg_uint32",param_2,uVar2);
        local_228 = 9;
      }
      RegCloseKey(local_224);
      FUN_c0838c24(local_18);
      local_14 = local_228;
    }
    else {
      FUN_c0824430("%s: RegOpenKeyEx returned %d.\n","get_device_reg_uint32",local_220,uVar2);
      FUN_c0838c24(local_18);
      local_14 = 9;
    }
  }
  else {
    FUN_c0838c24(local_18);
    local_14 = local_228;
  }
  return local_14;
}



/* c0823644 FUN_c0823644 */

/* Boundary evidence: original MIPS .pdata c0823644..c08236e7. Semantic name remains unreviewed. */

undefined4 FUN_c0823644(HKEY param_1,LPCWSTR param_2,LPBYTE param_3)

{
  undefined4 uVar1;
  DWORD local_20;
  LSTATUS local_1c;
  undefined4 local_10;
  
  local_20 = 4;
  uVar1 = 0;
  local_1c = RegQueryValueExW(param_1,param_2,(LPDWORD)0x0,(LPDWORD)0x0,param_3,&local_20);
  if (local_1c == 0) {
    local_10 = 0;
  }
  else {
    FUN_c0824430("%s: RegQueryValueEx returned %d.\n","registry_read_uint32",local_1c,uVar1);
    local_10 = 9;
  }
  return local_10;
}



/* c08236e8 FUN_c08236e8 */

/* Boundary evidence: original MIPS .pdata c08236e8..c0823843. Semantic name remains unreviewed. */

undefined4 FUN_c08236e8(LPBYTE param_1,DWORD param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  LPDWORD lpType;
  undefined4 local_30;
  HKEY local_2c;
  DWORD local_28;
  LSTATUS local_24;
  DWORD DStack_20;
  undefined4 local_1c;
  
  local_2c = (HKEY)0x0;
  local_30 = 0;
  if (DAT_c0839280 == (LPCWSTR)0x0) {
    FUN_c0824430("%s: Error: OS context is NULL\n","get_device_reg_path",param_3,param_4);
    local_1c = 9;
  }
  else {
    uVar1 = 0;
    local_24 = RegOpenKeyExW((HKEY)0x80000002,DAT_c0839280,0,0,&local_2c);
    if (local_24 == 0) {
      lpType = &DStack_20;
      local_28 = param_2;
      local_24 = RegQueryValueExW(local_2c,L"Key",(LPDWORD)0x0,lpType,param_1,&local_28);
      if (local_24 != 0) {
        FUN_c0824430("%s: RegQueryValueEx returned %d.\n","get_device_reg_path",local_24,lpType);
        local_30 = 9;
      }
      RegCloseKey(local_2c);
      local_1c = local_30;
    }
    else {
      FUN_c0824430("%s: RegOpenKeyEx returned %d.\n","get_device_reg_path",local_24,uVar1);
      local_1c = 9;
    }
  }
  return local_1c;
}



/* c0823844 FUN_c0823844 */

/* Boundary evidence: original MIPS .pdata c0823844..c0823aaf. Semantic name remains unreviewed. */

int FUN_c0823844(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int local_238;
  uint local_234;
  HKEY local_230;
  DWORD local_22c;
  int local_228;
  uint local_224;
  WCHAR aWStack_220 [256];
  LSTATUS local_20;
  uint local_1c;
  
  local_1c = DAT_c0839254;
  local_230 = (HKEY)0x0;
  InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_c083926c);
  local_238 = FUN_c08236e8((LPBYTE)aWStack_220,0x100,param_3,param_4);
  if (local_238 == 0) {
    local_20 = RegOpenKeyExW((HKEY)0x80000002,aWStack_220,0,0,&local_230);
    if (local_20 == 0) {
      local_22c = 4;
      local_20 = RegQueryValueExW(local_230,L"ControllersCount",(LPDWORD)0x0,(LPDWORD)0x0,
                                  (LPBYTE)&local_224,&local_22c);
      if (local_20 == 0) {
        RegCloseKey(local_230);
        local_230 = (HKEY)0x0;
        for (local_234 = 0; local_234 < local_224; local_234 = local_234 + 1) {
          local_238 = FUN_c0823ab0(aWStack_220,local_234);
          if (local_238 != 0) goto LAB_c0823a60;
        }
        local_228 = DAT_c0839284;
        while( true ) {
          if (local_228 == 0) {
            FUN_c0838c24(local_1c);
            return 0;
          }
          iVar1 = FUN_c082273c(*(uint *)(local_228 + 4));
          if (iVar1 == 0) break;
          local_238 = FUN_c0825ec0(local_228,*(int *)(local_228 + 4),(undefined4 *)(local_228 + 0xc)
                                  );
          if (local_238 != 0) goto LAB_c0823a60;
          local_228 = *(int *)(local_228 + 0x10);
        }
        local_238 = 10;
      }
      else {
        local_238 = 9;
      }
    }
    else {
      local_238 = 9;
    }
  }
LAB_c0823a60:
  if (local_230 != (HKEY)0x0) {
    RegCloseKey(local_230);
  }
  FUN_c0823f14();
  FUN_c0838c24(local_1c);
  return local_238;
}



/* c0823ab0 FUN_c0823ab0 */

/* Boundary evidence: original MIPS .pdata c0823ab0..c0823e8f. Semantic name remains unreviewed. */

int FUN_c0823ab0(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 *local_258;
  int local_254;
  HKEY local_250;
  undefined1 *local_24c;
  undefined4 local_248 [2];
  wchar_t awStack_240 [260];
  undefined4 local_38;
  undefined4 local_34;
  undefined4 *local_30;
  undefined4 local_2c;
  undefined4 local_28;
  LSTATUS local_24;
  int local_20;
  int local_1c;
  uint local_18;
  
  local_18 = DAT_c0839254;
  local_250 = (HKEY)0x0;
  local_38 = 0;
  local_34 = 0;
  local_258 = (undefined4 *)0x0;
  local_30 = (undefined4 *)0x0;
  local_24c = (LPVOID)0x0;
  swprintf_s(awStack_240,0x104,L"%s\\Controller%d",param_1,param_2);
  local_24 = RegOpenKeyExW((HKEY)0x80000002,awStack_240,0,0,&local_250);
  if (local_24 == 0) {
    local_254 = FUN_c0823644(local_250,L"Type",(LPBYTE)&local_1c);
    if (local_254 == 0) {
      iVar1 = FUN_c0823e90(local_1c);
      if (iVar1 == 0) {
        FUN_c0838c24(local_18);
        return 0;
      }
      local_254 = FUN_c0823644(local_250,L"BaseAddress",(LPBYTE)&local_28);
      if (((local_254 == 0) &&
          (local_254 = FUN_c0823644(local_250,L"MemLength",(LPBYTE)&local_2c), local_254 == 0)) &&
         (local_254 = FUN_c0823644(local_250,L"IRQ",(LPBYTE)local_248), local_254 == 0)) {
        RegCloseKey(local_250);
        local_250 = (HKEY)0x0;
        local_38 = local_28;
        local_20 = MmMapIoSpace(local_28,local_34,local_2c,0);
        if (local_20 == 0) {
          local_254 = 7;
        }
        else {
          local_258 = FUN_c08246fc(0x40);
          if (local_258 == (undefined4 *)0x0) {
            local_254 = 7;
          }
          else {
            *local_258 = 2;
            local_258[2] = local_28;
            local_258[3] = local_20;
            local_258[4] = local_2c;
            local_258[1] = 0;
            local_30 = FUN_c08246fc(0x40);
            if (local_30 == (undefined4 *)0x0) {
              local_254 = 7;
            }
            else {
              *local_30 = 1;
              local_30[2] = local_1c;
              local_30[3] = local_248[0];
              local_30[1] = 0;
              local_30[0xf] = local_258;
              local_24c = FUN_c08246fc(0x14);
              if (local_24c != (undefined1 *)0x0) {
                *local_24c = (char)param_2;
                *(int *)(local_24c + 4) = local_1c;
                *(undefined4 **)(local_24c + 8) = local_30;
                *(undefined1 **)(local_24c + 0x10) = DAT_c0839284;
                DAT_c0839284 = local_24c;
                FUN_c0838c24(local_18);
                return 0;
              }
              local_254 = 7;
              local_24c = (LPVOID)0x0;
            }
          }
        }
      }
    }
  }
  else {
    local_254 = 9;
  }
  if (local_24c != (LPVOID)0x0) {
    FUN_c0824790(local_24c);
  }
  if (local_30 != (undefined4 *)0x0) {
    FUN_c0824790(local_30);
  }
  if (local_258 != (undefined4 *)0x0) {
    FUN_c0824790(local_258);
  }
  if (local_250 != (HKEY)0x0) {
    RegCloseKey(local_250);
  }
  FUN_c0838c24(local_18);
  return local_254;
}



/* c0823e90 FUN_c0823e90 */

/* Boundary evidence: original MIPS .pdata c0823e90..c0823f13. Semantic name remains unreviewed. */

undefined4 FUN_c0823e90(int param_1)

{
  uint local_8;
  
  local_8 = 0;
  while( true ) {
    if (1 < local_8) {
      return 0;
    }
    if (*(int *)(&DAT_c08390d0 + local_8 * 4) == param_1) break;
    local_8 = local_8 + 1;
  }
  return 1;
}



/* c0823f14 FUN_c0823f14 */

/* Boundary evidence: original MIPS .pdata c0823f14..c0823fef. Semantic name remains unreviewed. */

void FUN_c0823f14(void)

{
  LPVOID pvVar1;
  LPVOID local_20;
  LPVOID local_1c;
  
  local_20 = DAT_c0839284;
  while (local_20 != (LPVOID)0x0) {
    if (*(int *)((int)local_20 + 0xc) != 0) {
      FUN_c0826004(*(int **)((int)local_20 + 0xc));
      FUN_c082289c(*(uint *)((int)local_20 + 4));
    }
    local_1c = *(LPVOID *)((int)local_20 + 8);
    while (local_1c != (LPVOID)0x0) {
      pvVar1 = *(LPVOID *)((int)local_1c + 0x3c);
      FUN_c0824790(local_1c);
      local_1c = pvVar1;
    }
    pvVar1 = *(LPVOID *)((int)local_20 + 0x10);
    FUN_c0824790(local_20);
    local_20 = pvVar1;
  }
  DeleteCriticalSection((LPCRITICAL_SECTION)&DAT_c083926c);
  return;
}



/* c0823ff0 FUN_c0823ff0 */

/* Boundary evidence: original MIPS .pdata c0823ff0..c08240af. Semantic name remains unreviewed. */

void FUN_c0823ff0(void)

{
  int local_10;
  int *local_c;
  
  if (DAT_c0839284 != 0) {
    for (local_10 = DAT_c0839284; local_10 != 0; local_10 = *(int *)(local_10 + 0x10)) {
      for (local_c = *(int **)(local_10 + 8); local_c != (int *)0x0; local_c = (int *)local_c[0xf])
      {
        if (*local_c == 1) {
          InterruptMask(local_c[4],1);
        }
      }
    }
  }
  return;
}



/* c08240b0 FUN_c08240b0 */

/* Boundary evidence: original MIPS .pdata c08240b0..c082416f. Semantic name remains unreviewed. */

void FUN_c08240b0(void)

{
  int local_10;
  int *local_c;
  
  if (DAT_c0839284 != 0) {
    for (local_10 = DAT_c0839284; local_10 != 0; local_10 = *(int *)(local_10 + 0x10)) {
      for (local_c = *(int **)(local_10 + 8); local_c != (int *)0x0; local_c = (int *)local_c[0xf])
      {
        if (*local_c == 1) {
          InterruptMask(local_c[4],0);
        }
      }
    }
  }
  return;
}



/* c0824170 FUN_c0824170 */

/* Boundary evidence: original MIPS .pdata c0824170..c082424b. Semantic name remains unreviewed. */

int * FUN_c0824170(int param_1,int param_2,int param_3)

{
  int *local_c;
  int *local_8;
  
  if (param_1 == 0) {
    local_8 = (int *)0x0;
  }
  else {
    for (local_c = *(int **)(param_1 + 8);
        (local_c != (int *)0x0 && ((*local_c != param_2 || (local_c[1] != param_3))));
        local_c = (int *)local_c[0xf]) {
    }
    if (local_c == (int *)0x0) {
      local_8 = (int *)0x0;
    }
    else {
      local_c[0xe] = 1;
      local_8 = local_c;
    }
  }
  return local_8;
}



/* c082424c FUN_c082424c */

/* Boundary evidence: original MIPS .pdata c082424c..c08242b3. Semantic name remains unreviewed. */

void FUN_c082424c(undefined4 param_1,int *param_2)

{
  if ((param_2 != (int *)0x0) && ((*param_2 != 1 || (param_2[9] == 0)))) {
    param_2[0xe] = 0;
  }
  return;
}



/* c08242b4 FUN_c08242b4 */

/* Boundary evidence: original MIPS .pdata c08242b4..c08242e7. Semantic name remains unreviewed. */

undefined1 FUN_c08242b4(int param_1,int param_2)

{
  return *(undefined1 *)(*(int *)(param_1 + 0xc) + param_2);
}



/* c08242e8 FUN_c08242e8 */

/* Boundary evidence: original MIPS .pdata c08242e8..c082431b. Semantic name remains unreviewed. */

undefined2 FUN_c08242e8(int param_1,int param_2)

{
  return *(undefined2 *)(*(int *)(param_1 + 0xc) + param_2);
}



/* c082431c FUN_c082431c */

/* Boundary evidence: original MIPS .pdata c082431c..c082434f. Semantic name remains unreviewed. */

undefined4 FUN_c082431c(int param_1,int param_2)

{
  return *(undefined4 *)(*(int *)(param_1 + 0xc) + param_2);
}



/* c08243a8 FUN_c08243a8 */

void FUN_c08243a8(int param_1,int param_2,undefined4 param_3)

{
  *(undefined4 *)(*(int *)(param_1 + 0xc) + param_2) = param_3;
  return;
}



/* c08243d4 FUN_c08243d4 */

/* Boundary evidence: original MIPS .pdata c08243d4..c08243f7. Semantic name remains unreviewed. */

undefined4 FUN_c08243d4(void)

{
  return 0;
}



/* c08243f8 FUN_c08243f8 */

/* Boundary evidence: original MIPS .pdata c08243f8..c082442f. Semantic name remains unreviewed. */

undefined4 FUN_c08243f8(undefined4 param_1)

{
  undefined4 uVar1;
  
  uVar1 = EventModify(param_1,3);
  return uVar1;
}



/* c0824430 FUN_c0824430 */

/* Boundary evidence: original MIPS .pdata c0824430..c08244d7. Semantic name remains unreviewed. */

int FUN_c0824430(char *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 local_res4;
  undefined4 local_res8;
  undefined4 local_resc;
  char acStack_298 [128];
  short asStack_218 [256];
  uint local_18;
  
  local_18 = DAT_c0839254;
  local_res4 = param_2;
  local_res8 = param_3;
  local_resc = param_4;
  iVar1 = _vsnprintf_s(acStack_298,0x80,0xffffffff,param_1,(va_list)&local_res4);
  FUN_c08244d8(acStack_298,asStack_218);
  NKDbgPrintfW(&DAT_c0821a30,asStack_218);
  FUN_c0838c24(local_18);
  return iVar1;
}



/* c08244d8 FUN_c08244d8 */

/* Boundary evidence: original MIPS .pdata c08244d8..c08245b7. Semantic name remains unreviewed. */

void FUN_c08244d8(char *param_1,short *param_2)

{
  bool bVar1;
  char *local_res0;
  short *local_res4;
  
  bVar1 = false;
  local_res4 = param_2;
  for (local_res0 = param_1; *local_res0 != '\0'; local_res0 = local_res0 + 1) {
    if ((*local_res0 != '\n') || (bVar1)) {
      bVar1 = *local_res0 == '\r';
    }
    else {
      *local_res4 = 0xd;
      local_res4 = local_res4 + 1;
    }
    *local_res4 = (short)*local_res0;
    local_res4 = local_res4 + 1;
  }
  *local_res4 = 0;
  return;
}



/* c08245b8 FUN_c08245b8 */

/* Boundary evidence: original MIPS .pdata c08245b8..c0824687. Semantic name remains unreviewed. */

undefined4 FUN_c08245b8(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  uint *puVar2;
  uint local_10;
  undefined4 local_c;
  
  puVar2 = &local_10;
  iVar1 = FUN_c08234fc(L"MaxHeapSize",(LPBYTE)puVar2,param_3,param_4);
  if (iVar1 == 0) {
    if (local_10 < 0x20000) {
      FUN_c0824430("os_mem_init: Incorrect max_heap_size value\n",puVar2,param_3,param_4);
      local_c = 10;
    }
    else {
      DAT_c0839288 = HeapCreate(1,0x20000,local_10);
      if (DAT_c0839288 == (HANDLE)0x0) {
        local_c = 7;
      }
      else {
        local_c = 0;
      }
    }
  }
  else {
    FUN_c0824430("os_mem_init: MaxHeapSize parameter not found in regestry\n",puVar2,param_3,param_4
                );
    local_c = 10;
  }
  return local_c;
}



/* c0824688 FUN_c0824688 */

/* Boundary evidence: original MIPS .pdata c0824688..c08246fb. Semantic name remains unreviewed. */

undefined4 FUN_c0824688(void)

{
  BOOL BVar1;
  undefined4 local_10;
  
  if (DAT_c0839288 == (HANDLE)0x0) {
    local_10 = 0;
  }
  else {
    BVar1 = HeapDestroy(DAT_c0839288);
    if (BVar1 == 0) {
      local_10 = 10;
    }
    else {
      DAT_c0839288 = (HANDLE)0x0;
      local_10 = 0;
    }
  }
  return local_10;
}



/* c08246fc FUN_c08246fc */

/* WARNING: Removing unreachable block (ram,0xc0824754) */
/* Boundary evidence: original MIPS .pdata c08246fc..c082478f. Semantic name remains unreviewed. */

LPVOID FUN_c08246fc(SIZE_T param_1)

{
  LPVOID pvVar1;
  
  pvVar1 = HeapAlloc(DAT_c0839288,8,param_1);
  return pvVar1;
}



/* c0824790 FUN_c0824790 */

/* Boundary evidence: original MIPS .pdata c0824790..c08247c3. Semantic name remains unreviewed. */

void FUN_c0824790(LPVOID param_1)

{
  HeapFree(DAT_c0839288,1,param_1);
  return;
}



/* c08247c4 FUN_c08247c4 */

/* Boundary evidence: original MIPS .pdata c08247c4..c0824873. Semantic name remains unreviewed. */

undefined4
FUN_c08247c4(undefined4 param_1,int *param_2,undefined4 *param_3,undefined4 param_4,int *param_5)

{
  int iVar1;
  undefined4 local_18 [2];
  undefined4 local_10;
  
  *param_5 = 0;
  *param_3 = 0;
  *param_2 = 0;
  iVar1 = AllocPhysMem(param_1,0x204,0x20,0,local_18);
  *param_2 = iVar1;
  if (*param_2 == 0) {
    local_10 = 7;
  }
  else {
    *param_3 = local_18[0];
    *param_5 = *param_2;
    local_10 = 0;
  }
  return local_10;
}



/* c0824874 FUN_c0824874 */

/* Boundary evidence: original MIPS .pdata c0824874..c082489b. Semantic name remains unreviewed. */

void FUN_c0824874(undefined4 param_1)

{
  FreePhysMem(param_1);
  return;
}



/* c08248ac FUN_c08248ac */

void FUN_c08248ac(void)

{
  return;
}



/* c08248bc FUN_c08248bc */

/* Boundary evidence: original MIPS .pdata c08248bc..c08248f3. Semantic name remains unreviewed. */

uint FUN_c08248bc(void)

{
  uint local_18;
  uint local_14;
  
  FUN_c08266d8(&local_18);
  return local_18 ^ local_14;
}



/* c08248f4 FUN_c08248f4 */

/* Boundary evidence: original MIPS .pdata c08248f4..c0824927. Semantic name remains unreviewed. */

ushort FUN_c08248f4(ushort param_1)

{
  return param_1 >> 8 | param_1 << 8;
}



/* c0824928 FUN_c0824928 */

/* Boundary evidence: original MIPS .pdata c0824928..c082497b. Semantic name remains unreviewed. */

uint FUN_c0824928(uint param_1)

{
  return param_1 >> 0x18 | param_1 >> 8 & 0xff00 | (param_1 & 0xff00) << 8 | param_1 << 0x18;
}



/* c082497c FUN_c082497c */

/* Boundary evidence: original MIPS .pdata c082497c..c08249fb. Semantic name remains unreviewed. */

LPVOID FUN_c082497c(char *param_1)

{
  size_t sVar1;
  undefined4 local_10;
  
  sVar1 = FUN_c0827c28(param_1);
  local_10 = FUN_c08246fc(sVar1 + 1);
  if (local_10 == (LPVOID)0x0) {
    local_10 = (LPVOID)0x0;
  }
  else {
    FUN_c0827ba0(local_10,param_1,sVar1 + 1);
  }
  return local_10;
}



/* c08249fc FUN_c08249fc */

/* Boundary evidence: original MIPS .pdata c08249fc..c0824b13. Semantic name remains unreviewed. */

char * FUN_c08249fc(char *param_1,char *param_2)

{
  char *local_res0;
  char *local_10;
  char *local_c;
  
  local_res0 = param_1;
  do {
    if (*local_res0 == '\0') {
      return (char *)0x0;
    }
    local_10 = local_res0;
    local_c = param_2;
    if (*local_res0 == *param_2) {
      do {
        local_c = local_c + 1;
        local_10 = local_10 + 1;
        if ((*local_10 == '\0') || (*local_c == '\0')) break;
      } while (*local_10 == *local_c);
      if (*local_c == '\0') {
        return local_res0;
      }
      if (*local_10 == '\0') {
        return (char *)0x0;
      }
    }
    local_res0 = local_res0 + 1;
  } while( true );
}



/* c0824b14 FUN_c0824b14 */

/* Boundary evidence: original MIPS .pdata c0824b14..c0824d1b. Semantic name remains unreviewed. */

int FUN_c0824b14(int param_1,byte param_2,uint param_3,int param_4,uint param_5)

{
  bool bVar1;
  uint uVar2;
  uint local_res8;
  int local_resc;
  int local_40;
  undefined1 auStack_39 [33];
  uint local_18;
  uint local_14;
  int local_10;
  
  local_14 = DAT_c0839254;
  local_40 = 0;
  local_18 = 0;
  if (param_2 < 2) {
    FUN_c0838c24(DAT_c0839254);
    local_10 = 0;
  }
  else {
    while (local_res8 = param_3, param_5 != 0) {
      uVar2 = param_5 % (uint)param_2;
      if (param_2 == 0) {
        trap(0x1c00);
      }
      param_5 = param_5 / param_2;
      if (param_2 == 0) {
        trap(0x1c00);
      }
      if ((byte)uVar2 < 10) {
        auStack_39[local_18 + 1] = (char)((uVar2 + 0x30) * 0x1000000 >> 0x18);
      }
      else {
        auStack_39[local_18 + 1] = (char)((uVar2 + 0x37) * 0x1000000 >> 0x18);
      }
      local_18 = local_18 + 1;
    }
    while (bVar1 = local_18 < local_res8, local_res8 = local_res8 - 1, local_resc = param_4, bVar1)
    {
      *(undefined1 *)(param_1 + local_40) = 0x30;
      local_40 = local_40 + 1;
    }
    while ((local_18 != 0 && (local_resc != 0))) {
      *(undefined1 *)(param_1 + local_40) = auStack_39[local_18];
      local_40 = local_40 + 1;
      local_18 = local_18 - 1;
      local_resc = local_resc + -1;
    }
    *(undefined1 *)(param_1 + local_40) = 0;
    FUN_c0838c24(local_14);
    local_10 = param_1;
  }
  return local_10;
}



/* c0824d1c FUN_c0824d1c */

/* Boundary evidence: original MIPS .pdata c0824d1c..c0824def. Semantic name remains unreviewed. */

uint FUN_c0824d1c(char *param_1,char *param_2,uint param_3)

{
  char cVar1;
  size_t sVar2;
  char *local_res0;
  char *local_res4;
  uint local_10;
  
  local_10 = 0;
  local_res0 = param_1;
  local_res4 = param_2;
  while( true ) {
    if (param_3 <= local_10) {
      if (param_3 != 0) {
        local_res0[-1] = '\0';
      }
      sVar2 = FUN_c0827c28(local_res4);
      return param_3 + sVar2;
    }
    *local_res0 = *local_res4;
    cVar1 = *local_res0;
    local_res0 = local_res0 + 1;
    local_res4 = local_res4 + 1;
    if (cVar1 == '\0') break;
    local_10 = local_10 + 1;
  }
  return local_10;
}



/* c0824df0 FUN_c0824df0 */

/* Boundary evidence: original MIPS .pdata c0824df0..c0824eff. Semantic name remains unreviewed. */

int FUN_c0824df0(char *param_1,byte param_2,undefined4 *param_3)

{
  int local_18;
  char *local_14;
  uint local_10;
  int local_c;
  
  local_18 = 0;
  local_10 = FUN_c0824f00(*param_1,(uint)param_2);
  local_14 = param_1;
  while ((*local_14 != '\0' && (local_10 != 0xffffffff))) {
    local_18 = local_18 * (uint)param_2 + local_10;
    local_14 = local_14 + 1;
    local_10 = FUN_c0824f00(*local_14,(uint)param_2);
  }
  if (param_3 != (undefined4 *)0x0) {
    *param_3 = local_14;
  }
  if (local_14 == param_1) {
    local_c = -1;
  }
  else {
    local_c = local_18;
  }
  return local_c;
}



/* c0824f00 FUN_c0824f00 */

/* Boundary evidence: original MIPS .pdata c0824f00..c0824ff3. Semantic name remains unreviewed. */

uint FUN_c0824f00(char param_1,uint param_2)

{
  undefined4 local_8;
  undefined4 local_4;
  
  local_8 = 0xffffffff;
  if ((param_1 < '0') || ('9' < param_1)) {
    if ((param_1 < 'A') || ('F' < param_1)) {
      if (('`' < param_1) && (param_1 < 'g')) {
        local_8 = (int)param_1 - 0x57;
      }
    }
    else {
      local_8 = (int)param_1 - 0x37;
    }
  }
  else {
    local_8 = (int)param_1 - 0x30;
  }
  if (local_8 < param_2) {
    local_4 = local_8;
  }
  else {
    local_4 = 0xffffffff;
  }
  return local_4;
}



/* c0824ff4 FUN_c0824ff4 */

/* Boundary evidence: original MIPS .pdata c0824ff4..c0825073. Semantic name remains unreviewed. */

undefined4 FUN_c0824ff4(char param_1)

{
  undefined4 local_8;
  
  if ((((param_1 == ' ') || (param_1 == '\t')) || (param_1 == '\r')) || (param_1 == '\n')) {
    local_8 = 1;
  }
  else {
    local_8 = 0;
  }
  return local_8;
}



/* c0825074 FUN_c0825074 */

/* Boundary evidence: original MIPS .pdata c0825074..c0825483. Semantic name remains unreviewed. */

char * FUN_c0825074(undefined4 param_1)

{
  char *local_10;
  
  switch(param_1) {
  case 0:
    local_10 = "NORMAL COMPLETION";
    break;
  case 1:
    local_10 = "OPERATION NOT STARTED";
    break;
  case 2:
    local_10 = "OPERATION IN PROGRESS";
    break;
  case 3:
    local_10 = "OPERATION NOT PERMITTED";
    break;
  case 4:
    local_10 = "NO SUCH ENTRY";
    break;
  case 5:
    local_10 = "INPUT/OUTPUT ERROR";
    break;
  case 6:
    local_10 = "DEVICE NOT CONFIGURED";
    break;
  case 7:
    local_10 = "FAILED ALLOCATING MEMORY";
    break;
  case 8:
    local_10 = "RESOURCE IS BUSY";
    break;
  case 9:
    local_10 = "NO SUCH DEVICE";
    break;
  case 10:
    local_10 = "INVALID ARGUMENT";
    break;
  case 0xb:
    local_10 = "OPERATION NOT SUPPORTED";
    break;
  case 0xc:
    local_10 = "OPERATION TIMED OUT";
    break;
  case 0xd:
    local_10 = "DEVICE IS SUSPENDED";
    break;
  case 0xe:
    local_10 = "GENERAL-PURPOSE ERROR";
    break;
  case 0xf:
    local_10 = "LOGICAL TEST FAILURE";
    break;
  case 0x10:
    local_10 = "INCORRECT STATE";
    break;
  case 0x11:
    local_10 = "PIPE IS STALLED";
    break;
  case 0x12:
    local_10 = "INVALID PARAMETER";
    break;
  case 0x13:
    local_10 = "OPERATION ABORTED";
    break;
  case 0x14:
    local_10 = "SHORT TRANSFER";
    break;
  case 0x15:
    local_10 = "WOULD BLOCK";
    break;
  case 0x16:
    local_10 = "ALREADY";
    break;
  case 0x17:
    local_10 = "EVALUATION TIME EXPIRED";
    break;
  default:
    local_10 = "INVALID RESULT_T VALUE";
    break;
  case 0x29:
    local_10 = "DEST ADDR REQUIRED";
    break;
  case 0x2a:
    local_10 = "CAN\'T ASSIGN REQUESTED ADDRESS";
    break;
  case 0x2b:
    local_10 = "MESSAGE TOO LONG";
    break;
  case 0x2c:
    local_10 = "NET DOWN";
    break;
  case 0x2d:
    local_10 = "NET UNREACHABLE";
    break;
  case 0x2e:
    local_10 = "NET RESET";
    break;
  case 0x2f:
    local_10 = "CONNECTION ABORTED";
    break;
  case 0x30:
    local_10 = "CONNECTION RESET";
    break;
  case 0x31:
    local_10 = "ALREADY CONNECTED";
    break;
  case 0x32:
    local_10 = "NOT CONNECTED";
    break;
  case 0x33:
    local_10 = "CONNECTION REFUSED";
    break;
  case 0x34:
    local_10 = "HOST DOWN";
    break;
  case 0x35:
    local_10 = "HOST UNREACHABLE";
    break;
  case 0x36:
    local_10 = "NO LINK";
    break;
  case 0x37:
    local_10 = "PROTOCOL";
    break;
  case 0x38:
    local_10 = "NO PROTOCOL OPTION";
    break;
  case 0x39:
    local_10 = "OPERATION INTERRUPTED";
  }
  return local_10;
}



/* c0825484 FUN_c0825484 */

/* Boundary evidence: original MIPS .pdata c0825484..c08255c3. Semantic name remains unreviewed. */

void FUN_c0825484(int param_1,int param_2,uint param_3)

{
  uint uVar1;
  undefined2 local_18;
  undefined4 local_14;
  undefined4 local_c;
  
  local_18 = 0;
  for (local_14 = 0; local_14 < param_3; local_14 = local_14 + *(int *)(param_2 + uVar1 * 0xc + 8))
  {
    if (param_3 - local_14 < *(uint *)(param_2 + (uint)local_18 * 0xc + 8)) {
      local_c = param_3 - local_14;
    }
    else {
      local_c = *(size_t *)(param_2 + (uint)local_18 * 0xc + 8);
    }
    FUN_c0827ba0(*(void **)(param_2 + (uint)local_18 * 0xc),(void *)(param_1 + local_14),local_c);
    uVar1 = (uint)local_18;
    local_18 = local_18 + 1;
  }
  return;
}



/* c08255c4 FUN_c08255c4 */

/* Boundary evidence: original MIPS .pdata c08255c4..c0825703. Semantic name remains unreviewed. */

void FUN_c08255c4(int param_1,int param_2,uint param_3)

{
  uint uVar1;
  undefined2 local_14;
  undefined4 local_10;
  undefined4 local_c;
  
  local_14 = 0;
  for (local_10 = 0; local_10 < param_3; local_10 = local_10 + *(int *)(param_1 + uVar1 * 0xc + 8))
  {
    if (param_3 - local_10 < *(uint *)(param_1 + (uint)local_14 * 0xc + 8)) {
      local_c = param_3 - local_10;
    }
    else {
      local_c = *(size_t *)(param_1 + (uint)local_14 * 0xc + 8);
    }
    FUN_c0827ba0((void *)(param_2 + local_10),*(void **)(param_1 + (uint)local_14 * 0xc),local_c);
    uVar1 = (uint)local_14;
    local_14 = local_14 + 1;
  }
  return;
}



/* c0825704 FUN_c0825704 */

/* Boundary evidence: original MIPS .pdata c0825704..c082577b. Semantic name remains unreviewed. */

int FUN_c0825704(int param_1,int *param_2)

{
  int *local_8;
  
  for (local_8 = param_2; (*local_8 != -1 && (*local_8 != param_1)); local_8 = local_8 + 2) {
  }
  return local_8[1];
}



/* c082577c FUN_c082577c */

/* Boundary evidence: original MIPS .pdata c082577c..c0825817. Semantic name remains unreviewed. */

int FUN_c082577c(uint param_1)

{
  return (uint)(byte)(&DAT_c0821ab8)[param_1 & 0xff] +
         (uint)(byte)(&DAT_c0821ab8)[param_1 >> 8 & 0xff] +
         (uint)(byte)(&DAT_c0821ab8)[param_1 >> 0x10 & 0xff] +
         (uint)(byte)(&DAT_c0821ab8)[param_1 >> 0x18];
}



/* c0825818 FUN_c0825818 */

/* Boundary evidence: original MIPS .pdata c0825818..c0825b23. Semantic name remains unreviewed. */

int FUN_c0825818(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  bool bVar1;
  bool bVar2;
  bool bVar3;
  int iVar4;
  int *piVar5;
  int local_1c;
  byte local_18;
  
  bVar3 = false;
  bVar1 = false;
  bVar2 = false;
  local_18 = 0;
  if (param_1 == (int *)0x0) {
    return 10;
  }
  DAT_c083928c = *param_1;
  piVar5 = param_1;
  iVar4 = FUN_c0827d88();
  if (iVar4 != 0) {
    return iVar4;
  }
  local_1c = FUN_c08280ac();
  if ((local_1c == 0) && (local_1c = FUN_c0828328(), local_1c == 0)) {
    bVar3 = true;
    if ((DAT_c083928c == 2) || ((DAT_c083928c == 3 || (DAT_c083928c == 4)))) {
      piVar5 = param_1;
      local_1c = FUN_c0828e8c((int)param_1);
      if (local_1c != 0) goto LAB_c0825a68;
      bVar2 = true;
      DAT_c0839290 = *(byte *)(param_1 + 1);
    }
    local_1c = FUN_c0823844(piVar5,param_2,param_3,param_4);
    if (local_1c == 0) {
      bVar1 = true;
      if ((DAT_c083928c == 2) || (DAT_c083928c == 3)) {
        for (local_18 = 0; local_18 < DAT_c0839290; local_18 = local_18 + 1) {
          if ((*(int *)(param_1[2] + (uint)local_18 * 0x18 + 4) != 0) &&
             (local_1c = FUN_c0828ef4(local_18), local_1c != 0)) goto LAB_c0825a68;
        }
      }
      FUN_c08277b8();
      return 0;
    }
  }
LAB_c0825a68:
  for (; local_18 != 0; local_18 = local_18 - 1) {
    if (*(int *)(param_1[2] + (uint)local_18 * 0x18 + 4) != 0) {
      FUN_c0828f28(local_18,param_2,param_3,param_4);
    }
  }
  if (bVar1) {
    FUN_c0823f14();
  }
  if (bVar2) {
    FUN_c0828ed4();
  }
  if (bVar3) {
    FUN_c08283d4();
  }
  FUN_c0827fbc();
  FUN_c0827eec();
  return local_1c;
}



/* c0825b24 FUN_c0825b24 */

/* Boundary evidence: original MIPS .pdata c0825b24..c0825c4b. Semantic name remains unreviewed. */

void FUN_c0825b24(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined1 local_10;
  
  FUN_c0827790();
  DAT_c0839294 = 1;
  if (((DAT_c083928c == 2) || (DAT_c083928c == 3)) || (DAT_c083928c == 4)) {
    for (local_10 = 0; local_10 < DAT_c0839290; local_10 = local_10 + 1) {
      FUN_c0828f28(local_10,param_2,param_3,param_4);
    }
  }
  FUN_c0823f14();
  if (((DAT_c083928c == 2) || (DAT_c083928c == 3)) || (DAT_c083928c == 4)) {
    FUN_c0828ed4();
  }
  FUN_c08283d4();
  FUN_c0827fbc();
  FUN_c0827eec();
  FUN_c0828f94();
  DAT_c0839294 = 0;
  return;
}



/* c0825c4c FUN_c0825c4c */

/* Boundary evidence: original MIPS .pdata c0825c4c..c0825c7f. Semantic name remains unreviewed. */

undefined4 FUN_c0825c4c(int param_1)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)FUN_c0829cc0(param_1);
  return *puVar1;
}



/* c0825c80 FUN_c0825c80 */

/* WARNING: Type propagation algorithm not settling */
/* Boundary evidence: original MIPS .pdata c0825c80..c0825ebf. Semantic name remains unreviewed. */

int FUN_c0825c80(undefined4 param_1,int param_2,undefined4 *param_3,undefined4 param_4)

{
  undefined4 *puVar1;
  int *piVar2;
  uint uVar3;
  int local_20;
  
  puVar1 = FUN_c08246fc(0xc);
  if (puVar1 == (undefined4 *)0x0) {
    return 7;
  }
  *puVar1 = param_1;
  puVar1[1] = param_2;
  puVar1[2] = param_4;
  piVar2 = FUN_c082a200(0,0,puVar1,0);
  if (piVar2 == (int *)0x0) {
    local_20 = 7;
    goto LAB_c0825e80;
  }
  local_20 = 10;
  uVar3 = param_2 >> 0xc;
  if (DAT_c083928c == 1) {
    if ((uVar3 & 0xf) != 1) goto joined_r0xc0825d98;
  }
  else if (((DAT_c083928c == 2) || ((DAT_c083928c == 3 && ((uVar3 & 0xf) != 1)))) &&
          ((uVar3 & 0xf) != 2)) {
joined_r0xc0825d98:
    if ((uVar3 & 0xf) != 3) goto LAB_c0825e80;
  }
  local_20 = FUN_c0829f60(piVar2);
  if (local_20 == 0) {
    *param_3 = piVar2;
    return 0;
  }
LAB_c0825e80:
  if (piVar2 != (int *)0x0) {
    FUN_c082a088(piVar2);
  }
  FUN_c0824790(puVar1);
  return local_20;
}



/* c0825ec0 FUN_c0825ec0 */

/* Boundary evidence: original MIPS .pdata c0825ec0..c0825f1b. Semantic name remains unreviewed. */

int FUN_c0825ec0(undefined4 param_1,int param_2,undefined4 *param_3)

{
  int iVar1;
  
  FUN_c08276dc();
  iVar1 = FUN_c0825c80(param_1,param_2,param_3,0);
  FUN_c0827704();
  return iVar1;
}



/* c0825f1c FUN_c0825f1c */

/* Boundary evidence: original MIPS .pdata c0825f1c..c0825f63. Semantic name remains unreviewed. */

undefined4 FUN_c0825f1c(int *param_1)

{
  undefined4 uVar1;
  
  FUN_c08276dc();
  uVar1 = FUN_c0828b7c(param_1);
  FUN_c0827704();
  return uVar1;
}



/* c0825f64 FUN_c0825f64 */

/* Boundary evidence: original MIPS .pdata c0825f64..c0825fab. Semantic name remains unreviewed. */

undefined4 FUN_c0825f64(int *param_1)

{
  undefined4 uVar1;
  
  FUN_c08276dc();
  uVar1 = FUN_c0828bf0(param_1);
  FUN_c0827704();
  return uVar1;
}



/* c0825fac FUN_c0825fac */

/* Boundary evidence: original MIPS .pdata c0825fac..c0826003. Semantic name remains unreviewed. */

undefined4 FUN_c0825fac(int *param_1)

{
  LPVOID pvVar1;
  
  pvVar1 = (LPVOID)FUN_c0829cc0((int)param_1);
  FUN_c082a088(param_1);
  FUN_c0824790(pvVar1);
  return 0;
}



/* c0826004 FUN_c0826004 */

/* Boundary evidence: original MIPS .pdata c0826004..c082604b. Semantic name remains unreviewed. */

undefined4 FUN_c0826004(int *param_1)

{
  undefined4 uVar1;
  
  FUN_c08276dc();
  uVar1 = FUN_c0825fac(param_1);
  FUN_c0827704();
  return uVar1;
}



/* c082604c FUN_c082604c */

/* Boundary evidence: original MIPS .pdata c082604c..c082608b. Semantic name remains unreviewed. */

undefined * FUN_c082604c(void)

{
  DAT_c08390f8 = FUN_c082608c();
  return &DAT_c0839124;
}



/* c082608c FUN_c082608c */

/* Boundary evidence: original MIPS .pdata c082608c..c08260bb. Semantic name remains unreviewed. */

undefined2 FUN_c082608c(void)

{
  return 0x20;
}



/* c08260bc FUN_c08260bc */

/* Boundary evidence: original MIPS .pdata c08260bc..c08261e3. Semantic name remains unreviewed. */

undefined4
FUN_c08260bc(undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4,
            undefined4 *param_5)

{
  undefined4 *lpParameter;
  HANDLE pvVar1;
  int iVar2;
  undefined4 local_14;
  
  if (param_5 != (undefined4 *)0x0) {
    *param_5 = 0;
  }
  lpParameter = FUN_c08246fc(8);
  if (lpParameter == (undefined4 *)0x0) {
    local_14 = 7;
  }
  else {
    *lpParameter = param_1;
    lpParameter[1] = param_2;
    pvVar1 = CreateThread((LPSECURITY_ATTRIBUTES)0x0,0,FUN_c08261e4,lpParameter,0,(LPDWORD)0x0);
    if (pvVar1 == (HANDLE)0x0) {
      FUN_c0824790(lpParameter);
      local_14 = 10;
    }
    else {
      if (param_5 != (undefined4 *)0x0) {
        *param_5 = pvVar1;
      }
      iVar2 = FUN_c0826274(param_3);
      CeSetThreadPriority(pvVar1,iVar2);
      local_14 = 0;
    }
  }
  return local_14;
}



/* c08261e4 FUN_c08261e4 */

/* Boundary evidence: original MIPS .pdata c08261e4..c0826273. Semantic name remains unreviewed. */

undefined4 FUN_c08261e4(int *param_1)

{
  undefined4 local_c;
  
  if ((param_1 == (int *)0x0) || (*param_1 == 0)) {
    local_c = 0;
  }
  else {
    FUN_c0827790();
    (*(code *)*param_1)(param_1[1]);
    FUN_c08277b8();
    FUN_c0824790(param_1);
    local_c = 1;
  }
  return local_c;
}



/* c0826274 FUN_c0826274 */

/* Boundary evidence: original MIPS .pdata c0826274..c082629f. Semantic name remains unreviewed. */

int FUN_c0826274(int param_1)

{
  return DAT_c08392a0 + param_1;
}



/* c08262a0 FUN_c08262a0 */

/* Boundary evidence: original MIPS .pdata c08262a0..c08262cb. Semantic name remains unreviewed. */

undefined4 FUN_c08262a0(void)

{
  undefined4 uVar1;
  
  uVar1 = FUN_c0826844();
  return uVar1;
}



/* c08262cc FUN_c08262cc */

/* Boundary evidence: original MIPS .pdata c08262cc..c0826347. Semantic name remains unreviewed. */

undefined4 FUN_c08262cc(undefined4 *param_1)

{
  HANDLE pvVar1;
  undefined4 local_c;
  
  *param_1 = 0;
  pvVar1 = CreateSemaphoreW((LPSECURITY_ATTRIBUTES)0x0,1,1,(LPCWSTR)0x0);
  if (pvVar1 == (HANDLE)0x0) {
    local_c = 10;
  }
  else {
    *param_1 = pvVar1;
    local_c = 0;
  }
  return local_c;
}



/* c0826348 FUN_c0826348 */

/* Boundary evidence: original MIPS .pdata c0826348..c082638b. Semantic name remains unreviewed. */

void FUN_c0826348(HANDLE param_1)

{
  if (param_1 != (HANDLE)0x0) {
    CloseHandle(param_1);
  }
  return;
}



/* c082638c FUN_c082638c */

/* Boundary evidence: original MIPS .pdata c082638c..c08263db. Semantic name remains unreviewed. */

void FUN_c082638c(HANDLE param_1)

{
  if (param_1 != (HANDLE)0x0) {
    WaitForSingleObject(param_1,0xffffffff);
  }
  return;
}



/* c08263dc FUN_c08263dc */

/* Boundary evidence: original MIPS .pdata c08263dc..c082641b. Semantic name remains unreviewed. */

void FUN_c08263dc(HANDLE param_1)

{
  ReleaseSemaphore(param_1,1,(LPLONG)0x0);
  return;
}



/* c0826428 FUN_c0826428 */

/* Boundary evidence: original MIPS .pdata c0826428..c082644f. Semantic name remains unreviewed. */

void FUN_c0826428(undefined4 param_1)

{
  OALStallExecution(param_1);
  return;
}



/* c0826450 FUN_c0826450 */

/* Boundary evidence: original MIPS .pdata c0826450..c082648f. Semantic name remains unreviewed. */

void FUN_c0826450(DWORD param_1)

{
  FUN_c08277b8();
  Sleep(param_1);
  FUN_c0827790();
  return;
}



/* c0826490 FUN_c0826490 */

/* Boundary evidence: original MIPS .pdata c0826490..c082650b. Semantic name remains unreviewed. */

undefined4 FUN_c0826490(undefined4 *param_1)

{
  HANDLE pvVar1;
  undefined4 local_c;
  
  *param_1 = 0;
  pvVar1 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
  if (pvVar1 == (HANDLE)0x0) {
    local_c = 10;
  }
  else {
    *param_1 = pvVar1;
    local_c = 0;
  }
  return local_c;
}



/* c082650c FUN_c082650c */

/* Boundary evidence: original MIPS .pdata c082650c..c082653b. Semantic name remains unreviewed. */

void FUN_c082650c(HANDLE param_1)

{
  CloseHandle(param_1);
  return;
}



/* c082653c FUN_c082653c */

/* Boundary evidence: original MIPS .pdata c082653c..c08265ff. Semantic name remains unreviewed. */

undefined4 FUN_c082653c(HANDLE param_1,DWORD param_2)

{
  DWORD DVar1;
  undefined4 local_14;
  undefined4 local_10;
  
  local_10 = param_2;
  if (param_2 == 0) {
    local_10 = 0xffffffff;
  }
  DVar1 = WaitForSingleObject(param_1,local_10);
  if (DVar1 == 0) {
    local_14 = 0;
  }
  else if (DVar1 == 0x102) {
    local_14 = 0xc;
  }
  else {
    local_14 = 10;
  }
  return local_14;
}



/* c0826600 FUN_c0826600 */

/* Boundary evidence: original MIPS .pdata c0826600..c082664f. Semantic name remains unreviewed. */

undefined4 FUN_c0826600(HANDLE param_1,DWORD param_2)

{
  undefined4 uVar1;
  
  FUN_c08277b8();
  uVar1 = FUN_c082653c(param_1,param_2);
  FUN_c0827790();
  return uVar1;
}



/* c0826650 FUN_c0826650 */

/* Boundary evidence: original MIPS .pdata c0826650..c082668b. Semantic name remains unreviewed. */

undefined4 FUN_c0826650(HANDLE param_1,DWORD param_2)

{
  undefined4 uVar1;
  
  uVar1 = FUN_c082653c(param_1,param_2);
  return uVar1;
}



/* c082668c FUN_c082668c */

/* Boundary evidence: original MIPS .pdata c082668c..c08266d7. Semantic name remains unreviewed. */

undefined4 FUN_c082668c(undefined4 param_1)

{
  int iVar1;
  undefined4 local_10;
  
  iVar1 = FUN_c08243f8(param_1);
  if (iVar1 == 0) {
    local_10 = 10;
  }
  else {
    local_10 = 0;
  }
  return local_10;
}



/* c08266d8 FUN_c08266d8 */

/* Boundary evidence: original MIPS .pdata c08266d8..c0826747. Semantic name remains unreviewed. */

void FUN_c08266d8(uint *param_1)

{
  DWORD DVar1;
  
  DVar1 = GetTickCount();
  *param_1 = DVar1 / 1000;
  param_1[1] = (DVar1 % 1000) * 1000;
  return;
}



/* c0826748 FUN_c0826748 */

/* Boundary evidence: original MIPS .pdata c0826748..c0826767. Semantic name remains unreviewed. */

undefined4 FUN_c0826748(void)

{
  return DAT_c08392a8;
}



/* c0826768 FUN_c0826768 */

/* Boundary evidence: original MIPS .pdata c0826768..c082683b. Semantic name remains unreviewed. */

undefined4 FUN_c0826768(void)

{
  BOOL BVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined8 uVar5;
  undefined4 local_10;
  
  BVar1 = QueryPerformanceFrequency((LARGE_INTEGER *)&DAT_c08392a8);
  if ((BVar1 == 0) || (DAT_c08392a8 == 0 && DAT_c08392ac == 0)) {
    local_10 = 10;
  }
  else {
    uVar4 = 0;
    uVar3 = 1000000;
    uVar5 = __ll_div(DAT_c08392a8,DAT_c08392ac);
    DAT_c083929c = (undefined4)((ulonglong)uVar5 >> 0x20);
    DAT_c0839298 = (undefined4)uVar5;
    iVar2 = FUN_c08234fc(L"TaskPriority",(LPBYTE)&DAT_c08392a0,uVar3,uVar4);
    if (iVar2 != 0) {
      DAT_c08392a0 = 100;
    }
    local_10 = 0;
  }
  return local_10;
}



/* c082683c FUN_c082683c */

void FUN_c082683c(void)

{
  return;
}



/* c0826844 FUN_c0826844 */

/* Boundary evidence: original MIPS .pdata c0826844..c0826873. Semantic name remains unreviewed. */

undefined4 FUN_c0826844(void)

{
  undefined4 uVar1;
  
  uVar1 = __GetUserKData(8);
  return uVar1;
}



/* c0826874 FUN_c0826874 */

/* Boundary evidence: original MIPS .pdata c0826874..c0826947. Semantic name remains unreviewed. */

int FUN_c0826874(int *param_1,undefined4 param_2)

{
  LPVOID pvVar1;
  undefined4 local_c;
  
  if (param_1 == (int *)0x0) {
    local_c = 10;
  }
  else {
    pvVar1 = FUN_c08246fc(0x28);
    *param_1 = (int)pvVar1;
    if (*param_1 == 0) {
      local_c = 7;
    }
    else {
      local_c = FUN_c0826490((undefined4 *)(*param_1 + 0x24));
      if (local_c == 0) {
        *(undefined4 *)(*param_1 + 0xc) = param_2;
        local_c = 0;
      }
      else {
        FUN_c0824790((LPVOID)*param_1);
      }
    }
  }
  return local_c;
}



/* c0826948 FUN_c0826948 */

/* Boundary evidence: original MIPS .pdata c0826948..c0826a1b. Semantic name remains unreviewed. */

void FUN_c0826948(LPVOID param_1)

{
  int iVar1;
  
  if (param_1 != (LPVOID)0x0) {
    if ((((*(char *)((int)param_1 + 0x18) == '\x01') || (*(char *)((int)param_1 + 0x18) == '\x03'))
        || (*(char *)((int)param_1 + 0x18) == '\x04')) &&
       (iVar1 = FUN_c08262a0(), *(int *)((int)param_1 + 0x1c) == iVar1)) {
      *(undefined4 *)((int)param_1 + 0x20) = 1;
    }
    else {
      FUN_c0826c08((int)param_1);
      FUN_c082650c(*(HANDLE *)((int)param_1 + 0x24));
      FUN_c0824790(param_1);
    }
  }
  return;
}



/* c0826a1c FUN_c0826a1c */

/* Boundary evidence: original MIPS .pdata c0826a1c..c0826b6f. Semantic name remains unreviewed. */

undefined4 FUN_c0826a1c(int *param_1,int param_2,int param_3,int param_4)

{
  uint local_20;
  int local_1c;
  undefined4 local_18;
  uint local_c;
  
  if (param_1 == (int *)0x0) {
    local_18 = 10;
  }
  else {
    FUN_c08266d8(&local_20);
    FUN_c0827914();
    local_c = (uint)*(byte *)(param_1 + 6);
    switch(local_c) {
    case 0:
      *(undefined1 *)(param_1 + 6) = 2;
      break;
    case 1:
      *(undefined1 *)(param_1 + 6) = 3;
      break;
    case 2:
      FUN_c0826b70((int)param_1);
      break;
    case 3:
      FUN_c0826b70((int)param_1);
      break;
    case 4:
      FUN_c0827940();
      return 0x10;
    }
    FUN_c0826d84(param_1,local_20,local_1c,param_2,param_3,param_4);
    FUN_c0827940();
    FUN_c0826f1c(param_1[3]);
    local_18 = 0;
  }
  return local_18;
}



/* c0826b70 FUN_c0826b70 */

/* Boundary evidence: original MIPS .pdata c0826b70..c0826c07. Semantic name remains unreviewed. */

void FUN_c0826b70(int param_1)

{
  int *local_8;
  
  for (local_8 = (int *)(&DAT_c08392b8 + *(int *)(param_1 + 0xc) * 0x34);
      (*local_8 != 0 && (*local_8 != param_1)); local_8 = (int *)*local_8) {
  }
  *local_8 = *(int *)*local_8;
  *(undefined4 *)(param_1 + 0x10) = 0;
  return;
}



/* c0826c08 FUN_c0826c08 */

/* Boundary evidence: original MIPS .pdata c0826c08..c0826d13. Semantic name remains unreviewed. */

void FUN_c0826c08(int param_1)

{
  uint auStack_18 [2];
  uint local_10;
  
  if (param_1 != 0) {
    FUN_c08266d8(auStack_18);
    FUN_c0827914();
    local_10 = (uint)*(byte *)(param_1 + 0x18);
    switch(local_10) {
    case 0:
      FUN_c0827940();
      break;
    case 1:
      *(undefined1 *)(param_1 + 0x18) = 4;
      FUN_c0827940();
      FUN_c0826d14(param_1);
      break;
    case 2:
      FUN_c0826b70(param_1);
      *(undefined1 *)(param_1 + 0x18) = 0;
      FUN_c0827940();
      break;
    case 3:
      FUN_c0826b70(param_1);
      *(undefined1 *)(param_1 + 0x18) = 4;
      FUN_c0827940();
      FUN_c0826d14(param_1);
    }
  }
  return;
}



/* c0826d14 FUN_c0826d14 */

/* Boundary evidence: original MIPS .pdata c0826d14..c0826d83. Semantic name remains unreviewed. */

void FUN_c0826d14(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_c08262a0();
  if (*(int *)(param_1 + 0x1c) != iVar1) {
    while (*(char *)(param_1 + 0x18) != '\0') {
      FUN_c0826600(*(HANDLE *)(param_1 + 0x24),0);
    }
  }
  return;
}



/* c0826d84 FUN_c0826d84 */

/* Boundary evidence: original MIPS .pdata c0826d84..c0826f1b. Semantic name remains unreviewed. */

void FUN_c0826d84(int *param_1,int param_2,int param_3,int param_4,int param_5,int param_6)

{
  bool bVar1;
  int local_res4;
  int local_res8;
  int local_resc;
  int *local_10;
  
  param_1[4] = param_5;
  param_1[5] = param_6;
  local_res8 = param_3 + param_4 * 1000;
  local_res4 = param_2 + local_res8 / 1000000;
  local_res8 = local_res8 % 1000000;
  local_resc = param_4;
  FUN_c0827ba0(param_1 + 1,&local_res4,8);
  for (local_10 = (int *)(&DAT_c08392b8 + param_1[3] * 0x34); *local_10 != 0;
      local_10 = (int *)*local_10) {
    if ((*(int *)(*local_10 + 4) < param_1[1]) ||
       ((param_1[1] == *(int *)(*local_10 + 4) && (*(int *)(*local_10 + 8) <= param_1[2])))) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (!bVar1) break;
  }
  *param_1 = *local_10;
  *local_10 = (int)param_1;
  return;
}



/* c0826f1c FUN_c0826f1c */

/* Boundary evidence: original MIPS .pdata c0826f1c..c0826f9b. Semantic name remains unreviewed. */

void FUN_c0826f1c(int param_1)

{
  if (*(int *)(&DAT_c08392b8 + param_1 * 0x34) != 0) {
    FUN_c082668c(*(undefined4 *)(&DAT_c08392b4 + param_1 * 0x34));
  }
  return;
}



/* c0826f9c FUN_c0826f9c */

/* Boundary evidence: original MIPS .pdata c0826f9c..c0827073. Semantic name remains unreviewed. */

int FUN_c0826f9c(void)

{
  int local_18;
  int local_14;
  int local_10;
  
  local_18 = 0;
  local_14 = 0;
  while ((local_14 < 3 && (local_18 == 0))) {
    local_18 = FUN_c0827074(local_14);
    local_14 = local_14 + 1;
  }
  if (local_18 == 0) {
    local_10 = 0;
  }
  else {
    while (local_14 = local_14 + -1, -1 < local_14) {
      FUN_c0827584(local_14);
    }
    local_10 = local_18;
  }
  return local_10;
}



/* c0827074 FUN_c0827074 */

/* Boundary evidence: original MIPS .pdata c0827074..c08271af. Semantic name remains unreviewed. */

int FUN_c0827074(int param_1)

{
  int iVar1;
  int local_18;
  
  iVar1 = param_1 * 0x34;
  FUN_c0827be4(&DAT_c08392b4 + iVar1,0,0x34);
  local_18 = FUN_c0826490((undefined4 *)(&DAT_c08392b4 + iVar1));
  if (local_18 == 0) {
    (&DAT_c08392e4)[iVar1] = (&DAT_c08392e4)[iVar1] | 1;
    (&DAT_c08392e4)[iVar1] = (&DAT_c08392e4)[iVar1] | 4;
    local_18 = FUN_c08260bc(FUN_c08271b0,param_1,param_1,(&PTR_s_uw_Controller_c0839134)[param_1],
                            (undefined4 *)(iVar1 + -0x3f7c6d20));
    if (local_18 == 0) {
      (&DAT_c08392e4)[iVar1] = (&DAT_c08392e4)[iVar1] | 2;
      return 0;
    }
  }
  FUN_c0827584(param_1);
  return local_18;
}



/* c08271b0 FUN_c08271b0 */

/* Boundary evidence: original MIPS .pdata c08271b0..c0827583. Semantic name remains unreviewed. */

void FUN_c08271b0(int param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  uint local_30;
  int local_2c;
  undefined4 *local_28;
  LPVOID local_24;
  DWORD local_20;
  code *local_1c;
  DWORD local_18;
  uint local_14;
  uint local_10;
  
  local_28 = (undefined4 *)(&DAT_c08392b4 + param_1 * 0x34);
  if (param_1 == 2) {
    FUN_c08276dc();
  }
  while ((*(byte *)(local_28 + 0xc) & 4) != 0) {
    FUN_c08266d8(&local_30);
    FUN_c0827914();
    local_24 = (LPVOID)local_28[1];
    if (local_24 == (LPVOID)0x0) {
      local_20 = 0;
    }
    else {
      local_20 = (*(int *)((int)local_24 + 4) - local_30) * 1000 +
                 (*(int *)((int)local_24 + 8) - local_2c) / 1000;
      if (*(int *)((int)local_24 + 0xc) != 0) {
        local_18 = local_20;
        if ((int)local_20 < 2) {
          local_18 = 2;
        }
        local_20 = local_18;
      }
    }
    FUN_c0827940();
    if ((0 < (int)local_20) || (local_24 == (LPVOID)0x0)) {
      if (param_1 == 2) {
        FUN_c0827704();
      }
      FUN_c0826600((HANDLE)*local_28,local_20);
      if (param_1 == 2) {
        FUN_c08276dc();
      }
    }
    *(byte *)(local_28 + 0xc) = *(byte *)(local_28 + 0xc) & 0xef;
    FUN_c0827914();
    local_24 = (LPVOID)local_28[1];
    if (local_24 == (LPVOID)0x0) {
      FUN_c0827940();
    }
    else {
      FUN_c08266d8(&local_30);
      local_14 = (uint)((int)((*(int *)((int)local_24 + 4) - local_30) * 1000 +
                             (*(int *)((int)local_24 + 8) - local_2c) / 1000) < 1);
      if (local_14 == 0) {
        FUN_c0827940();
      }
      else {
        local_1c = *(code **)((int)local_24 + 0x10);
        uVar2 = *(undefined4 *)((int)local_24 + 0x14);
        FUN_c0826b70((int)local_24);
        *(undefined1 *)((int)local_24 + 0x18) = 1;
        uVar1 = FUN_c08262a0();
        *(undefined4 *)((int)local_24 + 0x1c) = uVar1;
        FUN_c0827940();
        (*local_1c)(uVar2);
        if (*(int *)((int)local_24 + 0x20) == 0) {
          FUN_c0827914();
          local_10 = (uint)*(byte *)((int)local_24 + 0x18);
          if (local_10 == 1) {
            *(undefined1 *)((int)local_24 + 0x18) = 0;
          }
          else if (local_10 == 3) {
            *(undefined1 *)((int)local_24 + 0x18) = 2;
          }
          else if (local_10 == 4) {
            *(undefined1 *)((int)local_24 + 0x18) = 0;
            FUN_c082668c(*(undefined4 *)((int)local_24 + 0x24));
          }
          FUN_c0827940();
        }
        else {
          if (*(char *)((int)local_24 + 0x18) == '\x03') {
            FUN_c0826b70((int)local_24);
          }
          FUN_c082650c(*(HANDLE *)((int)local_24 + 0x24));
          FUN_c0824790(local_24);
        }
      }
    }
  }
  if (param_1 == 2) {
    FUN_c0827704();
  }
  *(byte *)(local_28 + 0xc) = *(byte *)(local_28 + 0xc) | 8;
  return;
}



/* c0827584 FUN_c0827584 */

/* Boundary evidence: original MIPS .pdata c0827584..c0827687. Semantic name remains unreviewed. */

void FUN_c0827584(int param_1)

{
  int iVar1;
  
  iVar1 = param_1 * 0x34;
  if (((&DAT_c08392e4)[iVar1] & 2) != 0) {
    if (*(int *)(&DAT_c08392b8 + iVar1) != 0) {
      *(undefined4 *)(&DAT_c08392b8 + iVar1) = 0;
    }
    (&DAT_c08392e4)[iVar1] = (&DAT_c08392e4)[iVar1] & 0xfb;
    FUN_c082668c(*(undefined4 *)(&DAT_c08392b4 + iVar1));
    while (((&DAT_c08392e4)[iVar1] & 8) == 0) {
      FUN_c0826450(0x37);
    }
  }
  if (((&DAT_c08392e4)[iVar1] & 1) != 0) {
    (&DAT_c08392e4)[iVar1] = (&DAT_c08392e4)[iVar1] & 0xfe;
    FUN_c082650c(*(HANDLE *)(&DAT_c08392b4 + iVar1));
  }
  return;
}



/* c0827688 FUN_c0827688 */

/* Boundary evidence: original MIPS .pdata c0827688..c08276db. Semantic name remains unreviewed. */

void FUN_c0827688(void)

{
  undefined4 local_10;
  
  for (local_10 = 0; local_10 < 3; local_10 = local_10 + 1) {
    FUN_c0827584(local_10);
  }
  return;
}



/* c08276dc FUN_c08276dc */

/* Boundary evidence: original MIPS .pdata c08276dc..c0827703. Semantic name remains unreviewed. */

void FUN_c08276dc(void)

{
  FUN_c08277e0(DAT_c0839350);
  return;
}



/* c0827704 FUN_c0827704 */

/* Boundary evidence: original MIPS .pdata c0827704..c082772b. Semantic name remains unreviewed. */

void FUN_c0827704(void)

{
  FUN_c0827818(DAT_c0839350);
  return;
}



/* c082772c FUN_c082772c */

/* Boundary evidence: original MIPS .pdata c082772c..c082775f. Semantic name remains unreviewed. */

undefined4 FUN_c082772c(void)

{
  undefined4 uVar1;
  
  uVar1 = FUN_c08262cc(&DAT_c0839354);
  return uVar1;
}



/* c0827760 FUN_c0827760 */

/* Boundary evidence: original MIPS .pdata c0827760..c082778f. Semantic name remains unreviewed. */

void FUN_c0827760(void)

{
  FUN_c0826348(DAT_c0839354);
  DAT_c0839354 = (HANDLE)0x0;
  return;
}



/* c0827790 FUN_c0827790 */

/* Boundary evidence: original MIPS .pdata c0827790..c08277b7. Semantic name remains unreviewed. */

void FUN_c0827790(void)

{
  FUN_c082638c(DAT_c0839354);
  return;
}



/* c08277b8 FUN_c08277b8 */

/* Boundary evidence: original MIPS .pdata c08277b8..c08277df. Semantic name remains unreviewed. */

void FUN_c08277b8(void)

{
  FUN_c08263dc(DAT_c0839354);
  return;
}



/* c08277e0 FUN_c08277e0 */

/* Boundary evidence: original MIPS .pdata c08277e0..c0827817. Semantic name remains unreviewed. */

void FUN_c08277e0(HANDLE param_1)

{
  FUN_c08277b8();
  FUN_c082638c(param_1);
  FUN_c0827790();
  return;
}



/* c0827818 FUN_c0827818 */

/* Boundary evidence: original MIPS .pdata c0827818..c082783f. Semantic name remains unreviewed. */

void FUN_c0827818(HANDLE param_1)

{
  FUN_c08263dc(param_1);
  return;
}



/* c0827840 FUN_c0827840 */

/* Boundary evidence: original MIPS .pdata c0827840..c08278d3. Semantic name remains unreviewed. */

int FUN_c0827840(void)

{
  int local_10;
  
  DAT_c0839130 = 4;
  FUN_c0827be4(&DAT_c08392b0,0,4);
  local_10 = FUN_c0826f9c();
  if ((local_10 == 0) && (local_10 = FUN_c08262cc(&DAT_c0839350), local_10 != 0)) {
    FUN_c0827688();
  }
  return local_10;
}



/* c08278d4 FUN_c08278d4 */

/* Boundary evidence: original MIPS .pdata c08278d4..c0827913. Semantic name remains unreviewed. */

void FUN_c08278d4(void)

{
  FUN_c0827688();
  FUN_c0826348(DAT_c0839350);
  DAT_c0839350 = (HANDLE)0x0;
  DAT_c08392b0 = 0;
  return;
}



/* c0827914 FUN_c0827914 */

/* Boundary evidence: original MIPS .pdata c0827914..c082793f. Semantic name remains unreviewed. */

void FUN_c0827914(void)

{
  FUN_c0823ff0();
  DAT_c08392b0 = 1;
  return;
}



/* c0827940 FUN_c0827940 */

/* Boundary evidence: original MIPS .pdata c0827940..c0827967. Semantic name remains unreviewed. */

void FUN_c0827940(void)

{
  DAT_c08392b0 = 0;
  FUN_c08240b0();
  return;
}



/* c0827968 FUN_c0827968 */

/* Boundary evidence: original MIPS .pdata c0827968..c0827987. Semantic name remains unreviewed. */

undefined4 FUN_c0827968(void)

{
  return DAT_c08392b0;
}



/* c0827988 FUN_c0827988 */

/* Boundary evidence: original MIPS .pdata c0827988..c0827a47. Semantic name remains unreviewed. */

int FUN_c0827988(undefined4 *param_1)

{
  LPVOID pvVar1;
  int local_18;
  
  FUN_c0827790();
  pvVar1 = FUN_c08246fc(0xc);
  if (pvVar1 == (LPVOID)0x0) {
    local_18 = 7;
  }
  else {
    local_18 = FUN_c08262cc((undefined4 *)((int)pvVar1 + 8));
    if (local_18 == 0) {
      *param_1 = pvVar1;
    }
  }
  if ((local_18 != 0) && (pvVar1 != (LPVOID)0x0)) {
    FUN_c0824790(pvVar1);
  }
  FUN_c08277b8();
  return local_18;
}



/* c0827a48 FUN_c0827a48 */

/* Boundary evidence: original MIPS .pdata c0827a48..c0827a8f. Semantic name remains unreviewed. */

void FUN_c0827a48(LPVOID param_1)

{
  FUN_c0827790();
  FUN_c0826348(*(HANDLE *)((int)param_1 + 8));
  FUN_c0824790(param_1);
  FUN_c08277b8();
  return;
}



/* c0827a90 FUN_c0827a90 */

/* Boundary evidence: original MIPS .pdata c0827a90..c0827b0b. Semantic name remains unreviewed. */

void FUN_c0827a90(int *param_1)

{
  int iVar1;
  
  iVar1 = FUN_c08262a0();
  if ((param_1[1] == 0) || (*param_1 != iVar1)) {
    FUN_c082638c((HANDLE)param_1[2]);
  }
  *param_1 = iVar1;
  param_1[1] = param_1[1] + 1;
  return;
}



/* c0827b0c FUN_c0827b0c */

/* Boundary evidence: original MIPS .pdata c0827b0c..c0827b5b. Semantic name remains unreviewed. */

void FUN_c0827b0c(int param_1)

{
  *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + -1;
  if (*(int *)(param_1 + 4) == 0) {
    FUN_c08263dc(*(HANDLE *)(param_1 + 8));
  }
  return;
}



/* c0827b5c FUN_c0827b5c */

/* Boundary evidence: original MIPS .pdata c0827b5c..c0827b9f. Semantic name remains unreviewed. */

int FUN_c0827b5c(void *param_1,void *param_2,size_t param_3)

{
  int iVar1;
  
  iVar1 = memcmp(param_1,param_2,param_3);
  return iVar1;
}



/* c0827ba0 FUN_c0827ba0 */

/* Boundary evidence: original MIPS .pdata c0827ba0..c0827be3. Semantic name remains unreviewed. */

void * FUN_c0827ba0(void *param_1,void *param_2,size_t param_3)

{
  void *pvVar1;
  
  pvVar1 = memcpy(param_1,param_2,param_3);
  return pvVar1;
}



/* c0827be4 FUN_c0827be4 */

/* Boundary evidence: original MIPS .pdata c0827be4..c0827c27. Semantic name remains unreviewed. */

void * FUN_c0827be4(void *param_1,int param_2,size_t param_3)

{
  void *pvVar1;
  
  pvVar1 = memset(param_1,param_2,param_3);
  return pvVar1;
}



/* c0827c28 FUN_c0827c28 */

/* Boundary evidence: original MIPS .pdata c0827c28..c0827c5b. Semantic name remains unreviewed. */

size_t FUN_c0827c28(char *param_1)

{
  size_t sVar1;
  
  sVar1 = strlen(param_1);
  return sVar1;
}



/* c0827c5c FUN_c0827c5c */

/* Boundary evidence: original MIPS .pdata c0827c5c..c0827c97. Semantic name remains unreviewed. */

int FUN_c0827c5c(char *param_1,char *param_2)

{
  int iVar1;
  
  iVar1 = strcmp(param_1,param_2);
  return iVar1;
}



/* c0827c98 FUN_c0827c98 */

/* Boundary evidence: original MIPS .pdata c0827c98..c0827cdb. Semantic name remains unreviewed. */

int FUN_c0827c98(char *param_1,char *param_2,size_t param_3)

{
  int iVar1;
  
  iVar1 = strncmp(param_1,param_2,param_3);
  return iVar1;
}



/* c0827cdc FUN_c0827cdc */

/* Boundary evidence: original MIPS .pdata c0827cdc..c0827d87. Semantic name remains unreviewed. */

uint FUN_c0827cdc(char *param_1,size_t param_2,char *param_3,undefined4 param_4)

{
  undefined4 local_resc;
  uint local_18;
  uint local_10;
  
  if (param_2 == 0) {
    local_10 = 0xffffffff;
  }
  else {
    local_resc = param_4;
    local_18 = _vsnprintf_s(param_1,param_2,0xffffffff,param_3,(va_list)&local_resc);
    if (param_2 < local_18) {
      local_18 = param_2 - local_18;
    }
    local_10 = local_18;
  }
  return local_10;
}



/* c0827d88 FUN_c0827d88 */

/* Boundary evidence: original MIPS .pdata c0827d88..c0827eeb. Semantic name remains unreviewed. */

int FUN_c0827d88(void)

{
  int local_10;
  
  local_10 = FUN_c0829bac();
  if (local_10 == 0) {
    DAT_c0839358 = DAT_c0839358 | 1;
    local_10 = FUN_c082772c();
    if (local_10 == 0) {
      FUN_c0827790();
      DAT_c0839358 = DAT_c0839358 | 2;
      local_10 = FUN_c0822da0();
      if (local_10 == 0) {
        DAT_c0839358 = DAT_c0839358 | 4;
        local_10 = FUN_c0827840();
        if (local_10 == 0) {
          DAT_c0839358 = DAT_c0839358 | 8;
          local_10 = FUN_c08282cc();
          if (local_10 == 0) {
            DAT_c0839358 = DAT_c0839358 | 0x10;
            return 0;
          }
        }
      }
    }
  }
  FUN_c0827eec();
  return local_10;
}



/* c0827eec FUN_c0827eec */

/* Boundary evidence: original MIPS .pdata c0827eec..c0827fbb. Semantic name remains unreviewed. */

void FUN_c0827eec(void)

{
  if ((DAT_c0839358 & 0x10) != 0) {
    FUN_c0828320();
  }
  if ((DAT_c0839358 & 8) != 0) {
    FUN_c08278d4();
  }
  if ((DAT_c0839358 & 1) != 0) {
    FUN_c0829ae4();
  }
  if ((DAT_c0839358 & 4) != 0) {
    FUN_c0822df0();
  }
  if ((DAT_c0839358 & 2) != 0) {
    FUN_c08277b8();
    FUN_c0827760();
  }
  if ((DAT_c0839358 & 1) != 0) {
    FUN_c0829bd0();
  }
  DAT_c0839358 = 0;
  return;
}



/* c0827fbc FUN_c0827fbc */

/* Boundary evidence: original MIPS .pdata c0827fbc..c08280ab. Semantic name remains unreviewed. */

void FUN_c0827fbc(void)

{
  int iVar1;
  int local_10;
  
  for (local_10 = 0; (&PTR_FUN_c0839144)[local_10 * 3] != (undefined *)0x0; local_10 = local_10 + 1)
  {
  }
  while (iVar1 = local_10 + -1, local_10 != 0) {
    if (*(int *)(&DAT_c083914c + iVar1 * 0xc) != 0) {
      (*(code *)(&PTR_LAB_c0839148)[iVar1 * 3])();
    }
    *(undefined4 *)(&DAT_c083914c + iVar1 * 0xc) = 0;
    local_10 = iVar1;
  }
  return;
}



/* c08280ac FUN_c08280ac */

/* Boundary evidence: original MIPS .pdata c08280ac..c0828193. Semantic name remains unreviewed. */

int FUN_c08280ac(void)

{
  int iVar1;
  int local_14;
  
  local_14 = 0;
  while( true ) {
    if ((&PTR_FUN_c0839144)[local_14 * 3] == (undefined *)0x0) {
      return 0;
    }
    iVar1 = (*(code *)(&PTR_FUN_c0839144)[local_14 * 3])();
    if (iVar1 != 0) break;
    *(undefined4 *)(&DAT_c083914c + local_14 * 0xc) = 1;
    local_14 = local_14 + 1;
  }
  FUN_c0827fbc();
  return iVar1;
}



/* c0828194 FUN_c0828194 */

void FUN_c0828194(int param_1)

{
  *(undefined4 *)(param_1 + 8) = 0;
  *(int **)(param_1 + 0xc) = DAT_c0839368;
  *DAT_c0839368 = param_1;
  DAT_c0839368 = (int *)(param_1 + 8);
  return;
}



/* c08281e4 FUN_c08281e4 */

/* Boundary evidence: original MIPS .pdata c08281e4..c08282cb. Semantic name remains unreviewed. */

undefined4 FUN_c08281e4(int param_1)

{
  bool bVar1;
  int iVar2;
  undefined4 local_c;
  undefined4 local_4;
  
  bVar1 = false;
  local_c = DAT_c0839364;
  iVar2 = local_c;
  while (local_c = iVar2, local_c != 0) {
    iVar2 = *(int *)(local_c + 8);
    if (local_c == param_1) {
      if (*(int *)(local_c + 8) == 0) {
        DAT_c0839368 = *(undefined4 *)(local_c + 0xc);
      }
      else {
        *(undefined4 *)(*(int *)(local_c + 8) + 0xc) = *(undefined4 *)(local_c + 0xc);
      }
      **(undefined4 **)(local_c + 0xc) = *(undefined4 *)(local_c + 8);
      bVar1 = true;
    }
  }
  if (bVar1) {
    local_4 = 0;
  }
  else {
    local_4 = 10;
  }
  return local_4;
}



/* c08282cc FUN_c08282cc */

/* Boundary evidence: original MIPS .pdata c08282cc..c082831f. Semantic name remains unreviewed. */

undefined4 FUN_c08282cc(void)

{
  DAT_c083935c = 0;
  DAT_c0839360 = &DAT_c083935c;
  DAT_c0839364 = 0;
  DAT_c0839368 = &DAT_c0839364;
  return 0;
}



/* c0828320 FUN_c0828320 */

void FUN_c0828320(void)

{
  return;
}



/* c0828328 FUN_c0828328 */

/* Boundary evidence: original MIPS .pdata c0828328..c08283d3. Semantic name remains unreviewed. */

int FUN_c0828328(void)

{
  int iVar1;
  int local_14;
  
  local_14 = 0;
  while( true ) {
    if ((&PTR_FUN_c083915c)[local_14] == (undefined *)0x0) {
      return 0;
    }
    iVar1 = (*(code *)(&PTR_FUN_c083915c)[local_14])();
    if (iVar1 != 0) break;
    local_14 = local_14 + 1;
  }
  FUN_c08283d4();
  return iVar1;
}



/* c08283d4 FUN_c08283d4 */

/* Boundary evidence: original MIPS .pdata c08283d4..c082843f. Semantic name remains unreviewed. */

void FUN_c08283d4(void)

{
  int *piVar1;
  
  while (piVar1 = DAT_c083935c, DAT_c083935c != (int *)0x0) {
    if (*(int *)(*DAT_c083935c + 0x20) != 0) {
      (**(code **)(*DAT_c083935c + 0x20))();
    }
    FUN_c08284f8(piVar1);
  }
  return;
}



/* c0828440 FUN_c0828440 */

/* Boundary evidence: original MIPS .pdata c0828440..c08284f7. Semantic name remains unreviewed. */

void FUN_c0828440(void)

{
  int iVar1;
  int *piVar2;
  int *local_c;
  
  local_c = DAT_c0839364;
  do {
    if (local_c == (int *)0x0) {
      return;
    }
    iVar1 = FUN_c0829c24((int)local_c);
    if (iVar1 == 0) {
LAB_c08284d4:
      FUN_c08287ac(local_c);
    }
    else {
      piVar2 = (int *)FUN_c0829e94((int)local_c);
      iVar1 = FUN_c0828af0(piVar2,2,local_c);
      if ((iVar1 == 0) || (iVar1 == 0x16)) goto LAB_c08284d4;
    }
    local_c = (int *)local_c[2];
  } while( true );
}



/* c08284f8 FUN_c08284f8 */

/* Boundary evidence: original MIPS .pdata c08284f8..c08285b7. Semantic name remains unreviewed. */

void FUN_c08284f8(LPVOID param_1)

{
  if (*(int *)((int)param_1 + 0x10) == 0) {
    DAT_c0839360 = *(undefined4 *)((int)param_1 + 0x14);
  }
  else {
    *(undefined4 *)(*(int *)((int)param_1 + 0x10) + 0x14) = *(undefined4 *)((int)param_1 + 0x14);
  }
  **(undefined4 **)((int)param_1 + 0x14) = *(undefined4 *)((int)param_1 + 0x10);
  if (*(char *)((int)param_1 + 0xc) != '\0') {
    while (*(int **)((int)param_1 + 0x18) != (int *)0x0) {
      FUN_c082a04c(*(int **)((int)param_1 + 0x18));
    }
  }
  FUN_c0824790(param_1);
  return;
}



/* c08285b8 FUN_c08285b8 */

/* Boundary evidence: original MIPS .pdata c08285b8..c08286fb. Semantic name remains unreviewed. */

undefined4
FUN_c08285b8(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined2 param_4,
            undefined4 *param_5)

{
  undefined4 *puVar1;
  undefined4 local_c;
  
  if (param_5 != (undefined4 *)0x0) {
    *param_5 = 0;
  }
  puVar1 = FUN_c08246fc(0x20);
  if (puVar1 == (undefined4 *)0x0) {
    local_c = 7;
  }
  else {
    puVar1[1] = param_1;
    *puVar1 = param_2;
    puVar1[2] = param_3;
    *(undefined1 *)(puVar1 + 3) = 0;
    *(undefined2 *)((int)puVar1 + 0xe) = param_4;
    *(undefined1 *)((int)puVar1 + 0xd) = 0;
    puVar1[6] = 0;
    puVar1[7] = puVar1 + 6;
    puVar1[4] = 0;
    puVar1[5] = DAT_c0839360;
    *DAT_c0839360 = puVar1;
    DAT_c0839360 = puVar1 + 4;
    if (param_5 != (undefined4 *)0x0) {
      *param_5 = puVar1;
    }
    if (DAT_c0839364 != 0) {
      FUN_c0828440();
    }
    local_c = 0;
  }
  return local_c;
}



/* c08286fc FUN_c08286fc */

/* Boundary evidence: original MIPS .pdata c08286fc..c08287ab. Semantic name remains unreviewed. */

void FUN_c08286fc(int *param_1)

{
  if (*param_1 != 0) {
    if (*(int *)(*(int *)*param_1 + 8) != 0) {
      (**(code **)(*(int *)*param_1 + 8))(param_1);
    }
    if (*param_1 != 0) {
      FUN_c0828d98(param_1);
    }
    if (param_1[5] != 0) {
      FUN_c0824790((LPVOID)param_1[5]);
      param_1[5] = 0;
    }
  }
  return;
}



/* c08287ac FUN_c08287ac */

/* Boundary evidence: original MIPS .pdata c08287ac..c0828a7f. Semantic name remains unreviewed. */

int FUN_c08287ac(int *param_1)

{
  byte bVar1;
  int iVar2;
  LPVOID pvVar3;
  int iVar4;
  int local_30;
  int *local_2c;
  int *local_28;
  int local_20;
  
  local_28 = (int *)0x0;
  local_20 = 0;
  iVar2 = FUN_c0829c24((int)param_1);
  for (local_2c = DAT_c083935c; local_2c != (int *)0x0; local_2c = (int *)local_2c[4]) {
    if (local_2c[1] == iVar2) {
      if (*(short *)((int)local_2c + 0xe) != 0) {
        pvVar3 = FUN_c08246fc((uint)*(ushort *)((int)local_2c + 0xe));
        param_1[5] = (int)pvVar3;
        if (param_1[5] == 0) goto LAB_c08287e4;
      }
      iVar4 = (**(code **)*local_2c)(param_1);
      if (*(short *)((int)local_2c + 0xe) != 0) {
        FUN_c0824790((LPVOID)param_1[5]);
      }
      param_1[5] = 0;
      if (local_20 < iVar4) {
        local_28 = local_2c;
        local_20 = iVar4;
      }
    }
LAB_c08287e4:
  }
  if (local_28 == (int *)0x0) {
    local_30 = 4;
  }
  else {
    if (*(short *)((int)local_28 + 0xe) != 0) {
      pvVar3 = FUN_c08246fc((uint)*(ushort *)((int)local_28 + 0xe));
      param_1[5] = (int)pvVar3;
      if (param_1[5] == 0) {
        local_30 = 7;
        goto LAB_c0828a04;
      }
    }
    bVar1 = *(byte *)((int)local_28 + 0xd);
    *(char *)((int)local_28 + 0xd) = *(char *)((int)local_28 + 0xd) + '\x01';
    FUN_c0829db0((int)param_1,(char *)local_28[2],(uint)bVar1);
    local_30 = (**(code **)(*local_28 + 4))(param_1);
    if (local_30 == 0) {
      if ((*param_1 != 0) || (local_30 = FUN_c0828c64(param_1,(int)local_28,0,0), local_30 == 0)) {
        return 0;
      }
      FUN_c082a04c(param_1);
    }
  }
LAB_c0828a04:
  if (param_1[5] != 0) {
    FUN_c0824790((LPVOID)param_1[5]);
    param_1[5] = 0;
  }
  iVar2 = DAT_c083936c;
  DAT_c083936c = DAT_c083936c + 1;
  FUN_c0829db0((int)param_1,"unknown",iVar2);
  return local_30;
}



/* c0828a80 FUN_c0828a80 */

/* Boundary evidence: original MIPS .pdata c0828a80..c0828aef. Semantic name remains unreviewed. */

int FUN_c0828a80(int *param_1)

{
  undefined4 local_c;
  
  if (param_1 == (int *)0x0) {
    local_c = 10;
  }
  else {
    local_c = FUN_c08287ac(param_1);
    if (local_c == 0) {
      local_c = 0;
    }
  }
  return local_c;
}



/* c0828af0 FUN_c0828af0 */

/* Boundary evidence: original MIPS .pdata c0828af0..c0828b7b. Semantic name remains unreviewed. */

undefined4 FUN_c0828af0(int *param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 local_10;
  
  if ((*param_1 == 0) || (*(int *)(*(int *)*param_1 + 0x14) == 0)) {
    local_10 = 10;
  }
  else {
    local_10 = (**(code **)(*(int *)*param_1 + 0x14))(param_1,param_2,param_3);
  }
  return local_10;
}



/* c0828b7c FUN_c0828b7c */

/* Boundary evidence: original MIPS .pdata c0828b7c..c0828bef. Semantic name remains unreviewed. */

undefined4 FUN_c0828b7c(int *param_1)

{
  undefined4 local_10;
  
  local_10 = 0;
  if ((*param_1 != 0) && (*(int *)(*(int *)*param_1 + 0xc) != 0)) {
    local_10 = (**(code **)(*(int *)*param_1 + 0xc))(param_1);
  }
  return local_10;
}



/* c0828bf0 FUN_c0828bf0 */

/* Boundary evidence: original MIPS .pdata c0828bf0..c0828c63. Semantic name remains unreviewed. */

undefined4 FUN_c0828bf0(int *param_1)

{
  undefined4 local_10;
  
  local_10 = 0;
  if ((*param_1 != 0) && (*(int *)(*(int *)*param_1 + 0x10) != 0)) {
    local_10 = (**(code **)(*(int *)*param_1 + 0x10))(param_1);
  }
  return local_10;
}



/* c0828c64 FUN_c0828c64 */

/* Boundary evidence: original MIPS .pdata c0828c64..c0828d97. Semantic name remains unreviewed. */

int FUN_c0828c64(int *param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int *piVar1;
  int local_10;
  
  piVar1 = (int *)FUN_c082a324((int)param_1);
  if (((piVar1 == (int *)0x0) || (*(int *)(*piVar1 + 0x18) == 0)) ||
     (local_10 = (**(code **)(*piVar1 + 0x18))(param_1,param_3,param_4), local_10 == 0)) {
    *param_1 = param_2;
    *(char *)(*param_1 + 0xc) = *(char *)(*param_1 + 0xc) + '\x01';
    FUN_c08281e4((int)param_1);
    param_1[2] = 0;
    param_1[3] = *(int *)(*param_1 + 0x1c);
    **(undefined4 **)(*param_1 + 0x1c) = param_1;
    *(int **)(*param_1 + 0x1c) = param_1 + 2;
    local_10 = 0;
  }
  return local_10;
}



/* c0828d98 FUN_c0828d98 */

/* Boundary evidence: original MIPS .pdata c0828d98..c0828e8b. Semantic name remains unreviewed. */

void FUN_c0828d98(int *param_1)

{
  int *piVar1;
  
  piVar1 = (int *)FUN_c082a324((int)param_1);
  if ((piVar1 != (int *)0x0) && (*(int *)(*piVar1 + 0x1c) != 0)) {
    (**(code **)(*piVar1 + 0x1c))(param_1);
  }
  if (param_1[2] == 0) {
    *(int *)(*param_1 + 0x1c) = param_1[3];
  }
  else {
    *(int *)(param_1[2] + 0xc) = param_1[3];
  }
  *(int *)param_1[3] = param_1[2];
  *(char *)(*param_1 + 0xc) = *(char *)(*param_1 + 0xc) + -1;
  *param_1 = 0;
  FUN_c0828194((int)param_1);
  return;
}



/* c0828e8c FUN_c0828e8c */

/* Boundary evidence: original MIPS .pdata c0828e8c..c0828ed3. Semantic name remains unreviewed. */

undefined4 FUN_c0828e8c(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = FUN_c0832630(*(int *)(param_1 + 8),*(byte *)(param_1 + 4));
  return uVar1;
}



/* c0828ed4 FUN_c0828ed4 */

/* Boundary evidence: original MIPS .pdata c0828ed4..c0828ef3. Semantic name remains unreviewed. */

void FUN_c0828ed4(void)

{
  FUN_c08329dc();
  return;
}



/* c0828ef4 FUN_c0828ef4 */

/* Boundary evidence: original MIPS .pdata c0828ef4..c0828f27. Semantic name remains unreviewed. */

int FUN_c0828ef4(char param_1)

{
  int iVar1;
  
  iVar1 = FUN_c0832ac8(param_1);
  return iVar1;
}



/* c0828f28 FUN_c0828f28 */

/* Boundary evidence: original MIPS .pdata c0828f28..c0828f4f. Semantic name remains unreviewed. */

void FUN_c0828f28(char param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  FUN_c0832cb0(param_1,param_2,param_3,param_4);
  return;
}



/* c0828f50 FUN_c0828f50 */

/* Boundary evidence: original MIPS .pdata c0828f50..c0828f93. Semantic name remains unreviewed. */

undefined4 FUN_c0828f50(char *param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  
  uVar1 = FUN_c0832dac(param_1,param_2,param_3);
  return uVar1;
}



/* c0828f94 FUN_c0828f94 */

void FUN_c0828f94(void)

{
  return;
}



/* c0828f9c FUN_c0828f9c */

/* Boundary evidence: original MIPS .pdata c0828f9c..c0828fcb. Semantic name remains unreviewed. */

int FUN_c0828f9c(int param_1,int param_2)

{
  return *(int *)(param_1 + 4) + param_2;
}



/* c0828fcc FUN_c0828fcc */

/* Boundary evidence: original MIPS .pdata c0828fcc..c0828ffb. Semantic name remains unreviewed. */

int FUN_c0828fcc(int *param_1,int param_2)

{
  return *param_1 + param_2;
}



/* c0828ffc FUN_c0828ffc */

/* Boundary evidence: original MIPS .pdata c0828ffc..c082901b. Semantic name remains unreviewed. */

undefined4 FUN_c0828ffc(undefined4 param_1)

{
  return param_1;
}



/* c082901c FUN_c082901c */

/* Boundary evidence: original MIPS .pdata c082901c..c08292db. Semantic name remains unreviewed. */

int FUN_c082901c(uint param_1,ushort param_2,int *param_3,int *param_4,ushort param_5,
                undefined4 *param_6)

{
  ushort uVar1;
  int *piVar2;
  uint uVar3;
  LPVOID pvVar4;
  int iVar5;
  void *pvVar6;
  int *local_1c;
  int local_18;
  uint local_14;
  uint local_10;
  
  local_1c = (int *)0x0;
  if (param_1 == 0) {
    pvVar4 = FUN_c08246fc(0x20);
    if (pvVar4 == (LPVOID)0x0) {
      local_18 = 7;
    }
    else {
      *(byte *)((int)pvVar4 + 0x12) = *(byte *)((int)pvVar4 + 0x12) | 8;
      *param_6 = pvVar4;
      local_18 = 0;
    }
  }
  else {
    local_14 = param_1;
    if (param_1 < 0x20) {
      local_14 = 0x20;
    }
    uVar3 = local_14;
    if (param_2 < 4) {
      local_10 = 4;
    }
    else {
      local_10 = (uint)param_2;
    }
    uVar1 = (ushort)local_10;
    local_18 = FUN_c08298e0(local_14,uVar1,param_5,(int *)&local_1c);
    if ((local_18 == 0) &&
       (((local_1c != (int *)0x0 || ((param_5 & 2) == 0)) ||
        (local_18 = FUN_c08298e0(uVar3,uVar1,param_5 & 0xfffd,(int *)&local_1c), local_18 == 0)))) {
      if (local_1c == (int *)0x0) {
        iVar5 = FUN_c08292dc(uVar3,uVar1,param_5);
        piVar2 = DAT_c0839370;
        if (iVar5 != 0) {
          return iVar5;
        }
        local_1c = DAT_c0839370;
        if (DAT_c0839370[6] != 0) {
          *(int *)(DAT_c0839370[6] + 0x1c) = DAT_c0839370[7];
        }
        *(int *)piVar2[7] = piVar2[6];
      }
      if (param_6 != (undefined4 *)0x0) {
        *param_6 = local_1c;
      }
      if (param_3 != (int *)0x0) {
        iVar5 = FUN_c0828fcc(local_1c,0);
        *param_3 = iVar5;
      }
      if (param_4 != (int *)0x0) {
        iVar5 = FUN_c0828f9c((int)local_1c,0);
        *param_4 = iVar5;
      }
      if ((param_5 & 1) != 0) {
        pvVar6 = (void *)FUN_c0828fcc(local_1c,0);
        FUN_c0827be4(pvVar6,0,uVar3);
      }
      local_18 = 0;
    }
  }
  return local_18;
}



/* c08292dc FUN_c08292dc */

/* Boundary evidence: original MIPS .pdata c08292dc..c082931f. Semantic name remains unreviewed. */

int FUN_c08292dc(uint param_1,ushort param_2,ushort param_3)

{
  int iVar1;
  
  iVar1 = FUN_c0829320(param_1,param_2,param_3);
  return iVar1;
}



/* c0829320 FUN_c0829320 */

/* Boundary evidence: original MIPS .pdata c0829320..c082959b. Semantic name remains unreviewed. */

int FUN_c0829320(uint param_1,ushort param_2,ushort param_3)

{
  uint local_40;
  int local_3c;
  uint local_38;
  int local_34;
  int local_30;
  int local_2c;
  uint local_28;
  int local_24;
  int local_20;
  int local_1c;
  uint local_c;
  
  local_24 = 0;
  local_28 = 0;
  local_40 = 0;
  local_20 = 0;
  if (((param_3 & 4) == 0) || (param_1 < 0x1001)) {
    local_c = param_1;
    if (param_1 < 0x20) {
      local_c = 0x20;
    }
    local_2c = local_c + (param_2 - 1);
    if ((param_3 & 4) != 0) {
      local_2c = local_2c * 2;
    }
    local_3c = FUN_c0829784(local_2c,&local_34,&local_40,param_3,&local_24,&local_20);
    local_1c = local_3c;
    if (local_3c == 0) {
      local_30 = local_34;
      local_38 = local_40;
      if (((param_3 & 4) != 0) && (0x1000 < (local_40 & 0xfff) + param_1 + param_2 + -1)) {
        local_28 = 0x1000 - (local_40 & 0xfff);
      }
      if (param_2 == 0) {
        trap(0x1c00);
      }
      if ((local_40 + local_28) % (uint)param_2 != 0) {
        if (param_2 == 0) {
          trap(0x1c00);
        }
        local_28 = (local_28 + param_2) - (local_40 + local_28) % (uint)param_2;
      }
      FUN_c08297fc(local_28,local_24,local_34,local_40);
      FUN_c08297fc((local_2c - param_1) - local_28,local_24,local_30 + local_28 + param_1,
                   local_38 + local_28 + param_1);
      local_1c = FUN_c082959c(param_1,local_24,local_30 + local_28,local_38 + local_28,local_20);
    }
  }
  else {
    local_1c = 10;
  }
  return local_1c;
}



/* c082959c FUN_c082959c */

/* Boundary evidence: original MIPS .pdata c082959c..c0829727. Semantic name remains unreviewed. */

undefined4 FUN_c082959c(int param_1,int param_2,undefined4 param_3,uint param_4,int param_5)

{
  undefined4 *puVar1;
  ushort local_18;
  undefined4 local_c;
  
  puVar1 = FUN_c08246fc(0x20);
  if (puVar1 == (undefined4 *)0x0) {
    local_c = 7;
  }
  else {
    *puVar1 = param_3;
    puVar1[1] = param_4;
    puVar1[2] = 0;
    puVar1[3] = param_1;
    for (local_18 = 1; ((param_4 & local_18) == 0 && (local_18 < 0x1001)); local_18 = local_18 << 1)
    {
    }
    *(ushort *)(puVar1 + 4) = local_18;
    if (param_2 != 0) {
      *(byte *)((int)puVar1 + 0x12) = *(byte *)((int)puVar1 + 0x12) | 1;
    }
    if (param_4 >> 0xc == param_4 + param_1 >> 0xc) {
      *(byte *)((int)puVar1 + 0x12) = *(byte *)((int)puVar1 + 0x12) | 2;
    }
    if (param_5 != 0) {
      *(byte *)((int)puVar1 + 0x12) = *(byte *)((int)puVar1 + 0x12) | 4;
      puVar1[5] = param_5;
    }
    FUN_c0829728((int)puVar1);
    local_c = 0;
  }
  return local_c;
}



/* c0829728 FUN_c0829728 */

void FUN_c0829728(int param_1)

{
  *(int *)(param_1 + 0x18) = DAT_c0839370;
  if (DAT_c0839370 != 0) {
    *(int *)(DAT_c0839370 + 0x1c) = param_1 + 0x18;
  }
  DAT_c0839370 = param_1;
  *(int **)(param_1 + 0x1c) = &DAT_c0839370;
  return;
}



/* c0829784 FUN_c0829784 */

/* Boundary evidence: original MIPS .pdata c0829784..c08297fb. Semantic name remains unreviewed. */

int FUN_c0829784(undefined4 param_1,int *param_2,undefined4 *param_3,ushort param_4,
                undefined4 *param_5,int *param_6)

{
  int iVar1;
  
  iVar1 = FUN_c08247c4(param_1,param_2,param_3,(uint)param_4,param_6);
  if (iVar1 == 0) {
    *param_5 = 0;
  }
  return iVar1;
}



/* c08297fc FUN_c08297fc */

/* Boundary evidence: original MIPS .pdata c08297fc..c08298df. Semantic name remains unreviewed. */

void FUN_c08297fc(uint param_1,int param_2,int param_3,uint param_4)

{
  uint local_18;
  
  local_18 = 0;
  if (0x1f < param_1) {
    if ((param_4 & 3) != 0) {
      local_18 = 4 - (param_4 & 3);
    }
    if ((local_18 < param_1) && (0x1f < param_1 - local_18)) {
      FUN_c082959c(param_1 - local_18,param_2,param_3 + local_18,param_4 + local_18,0);
    }
  }
  return;
}



/* c08298e0 FUN_c08298e0 */

/* Boundary evidence: original MIPS .pdata c08298e0..c0829a8b. Semantic name remains unreviewed. */

undefined4 FUN_c08298e0(uint param_1,ushort param_2,ushort param_3,int *param_4)

{
  int local_8;
  
  *param_4 = 0;
  if (param_1 != 0) {
    for (local_8 = DAT_c0839370; local_8 != 0; local_8 = *(int *)(local_8 + 0x18)) {
      if (((((param_3 & 2) == 0) || ((*(byte *)(local_8 + 0x12) & 1) != 0)) &&
          (((param_3 & 2) != 0 || ((*(byte *)(local_8 + 0x12) & 1) == 0)))) &&
         (((((param_3 & 4) == 0 || ((*(byte *)(local_8 + 0x12) & 2) != 0)) &&
           (param_2 <= *(ushort *)(local_8 + 0x10))) &&
          ((param_1 <= *(uint *)(local_8 + 0xc) && (*(uint *)(local_8 + 0xc) < param_1 << 1)))))) {
        if (*(int *)(local_8 + 0x18) != 0) {
          *(undefined4 *)(*(int *)(local_8 + 0x18) + 0x1c) = *(undefined4 *)(local_8 + 0x1c);
        }
        **(undefined4 **)(local_8 + 0x1c) = *(undefined4 *)(local_8 + 0x18);
        *param_4 = local_8;
        return 0;
      }
    }
  }
  return 0;
}



/* c0829a8c FUN_c0829a8c */

/* Boundary evidence: original MIPS .pdata c0829a8c..c0829ae3. Semantic name remains unreviewed. */

void FUN_c0829a8c(LPVOID param_1)

{
  if ((*(byte *)((int)param_1 + 0x12) & 8) == 0) {
    FUN_c0829728((int)param_1);
  }
  else {
    FUN_c0824790(param_1);
  }
  return;
}



/* c0829ae4 FUN_c0829ae4 */

/* Boundary evidence: original MIPS .pdata c0829ae4..c0829bab. Semantic name remains unreviewed. */

void FUN_c0829ae4(void)

{
  LPVOID pvVar1;
  
  while (pvVar1 = DAT_c0839370, DAT_c0839370 != (LPVOID)0x0) {
    if (*(int *)((int)DAT_c0839370 + 0x18) != 0) {
      *(undefined4 *)(*(int *)((int)DAT_c0839370 + 0x18) + 0x1c) =
           *(undefined4 *)((int)DAT_c0839370 + 0x1c);
    }
    **(undefined4 **)((int)pvVar1 + 0x1c) = *(undefined4 *)((int)pvVar1 + 0x18);
    if ((*(byte *)((int)pvVar1 + 0x12) & 4) == 0) {
      FUN_c0824790(pvVar1);
    }
    else {
      FUN_c0824874(*(undefined4 *)((int)pvVar1 + 0x14));
      FUN_c0824790(pvVar1);
    }
  }
  return;
}



/* c0829bac FUN_c0829bac */

/* Boundary evidence: original MIPS .pdata c0829bac..c0829bcf. Semantic name remains unreviewed. */

undefined4 FUN_c0829bac(void)

{
  return 0;
}



/* c0829bd0 FUN_c0829bd0 */

void FUN_c0829bd0(void)

{
  return;
}



/* c0829bd8 FUN_c0829bd8 */

/* Boundary evidence: original MIPS .pdata c0829bd8..c0829bfb. Semantic name remains unreviewed. */

undefined4 FUN_c0829bd8(int param_1)

{
  return *(undefined4 *)(param_1 + 0x34);
}



/* c0829bfc FUN_c0829bfc */

/* Boundary evidence: original MIPS .pdata c0829bfc..c0829c23. Semantic name remains unreviewed. */

undefined4 FUN_c0829bfc(undefined4 param_1,int param_2)

{
  return *(undefined4 *)(param_2 + 0x3c);
}



/* c0829c24 FUN_c0829c24 */

/* Boundary evidence: original MIPS .pdata c0829c24..c0829c63. Semantic name remains unreviewed. */

undefined4 FUN_c0829c24(int param_1)

{
  undefined4 local_8;
  
  if (param_1 == 0) {
    local_8 = 0xffffffff;
  }
  else {
    local_8 = *(undefined4 *)(param_1 + 0x18);
  }
  return local_8;
}



/* c0829c80 FUN_c0829c80 */

/* Boundary evidence: original MIPS .pdata c0829c80..c0829cbf. Semantic name remains unreviewed. */

undefined4 FUN_c0829c80(int param_1)

{
  undefined4 local_8;
  
  if (param_1 == 0) {
    local_8 = 0;
  }
  else {
    local_8 = *(undefined4 *)(param_1 + 0x1c);
  }
  return local_8;
}



/* c0829cc0 FUN_c0829cc0 */

/* Boundary evidence: original MIPS .pdata c0829cc0..c0829cff. Semantic name remains unreviewed. */

undefined4 FUN_c0829cc0(int param_1)

{
  undefined4 local_8;
  
  if (param_1 == 0) {
    local_8 = 0;
  }
  else {
    local_8 = *(undefined4 *)(param_1 + 0x24);
  }
  return local_8;
}



/* c0829d00 FUN_c0829d00 */

/* Boundary evidence: original MIPS .pdata c0829d00..c0829d23. Semantic name remains unreviewed. */

undefined4 FUN_c0829d00(int param_1)

{
  return *(undefined4 *)(param_1 + 0x20);
}



/* c0829d40 FUN_c0829d40 */

/* Boundary evidence: original MIPS .pdata c0829d40..c0829daf. Semantic name remains unreviewed. */

undefined * FUN_c0829d40(int param_1)

{
  undefined *local_8;
  undefined *local_4;
  
  if (param_1 == 0) {
    local_8 = &DAT_c0821f5c;
  }
  else {
    if (*(int *)(param_1 + 0x2c) == 0) {
      local_4 = &DAT_c0821f5c;
    }
    else {
      local_4 = *(undefined **)(param_1 + 0x2c);
    }
    local_8 = local_4;
  }
  return local_8;
}



/* c0829db0 FUN_c0829db0 */

/* Boundary evidence: original MIPS .pdata c0829db0..c0829e93. Semantic name remains unreviewed. */

void FUN_c0829db0(int param_1,char *param_2,undefined4 param_3)

{
  size_t sVar1;
  LPVOID pvVar2;
  
  if (*(int *)(param_1 + 0x2c) != 0) {
    FUN_c0824790(*(LPVOID *)(param_1 + 0x2c));
  }
  if (param_2 == (char *)0x0) {
    *(undefined4 *)(param_1 + 0x2c) = 0;
    *(undefined4 *)(param_1 + 0x28) = param_3;
  }
  else {
    sVar1 = FUN_c0827c28(param_2);
    pvVar2 = FUN_c08246fc(sVar1 + 10);
    *(LPVOID *)(param_1 + 0x2c) = pvVar2;
    if (*(int *)(param_1 + 0x2c) != 0) {
      *(undefined4 *)(param_1 + 0x28) = param_3;
      FUN_c0827cdc(*(char **)(param_1 + 0x2c),sVar1 + 10,"%s%ld",param_2);
    }
  }
  return;
}



/* c0829e94 FUN_c0829e94 */

/* Boundary evidence: original MIPS .pdata c0829e94..c0829eb7. Semantic name remains unreviewed. */

undefined4 FUN_c0829e94(int param_1)

{
  return *(undefined4 *)(param_1 + 0x10);
}



/* c0829eb8 FUN_c0829eb8 */

/* Boundary evidence: original MIPS .pdata c0829eb8..c0829ef7. Semantic name remains unreviewed. */

undefined4 FUN_c0829eb8(int param_1)

{
  undefined4 local_8;
  
  if (param_1 == 0) {
    local_8 = 0;
  }
  else {
    local_8 = *(undefined4 *)(param_1 + 0x14);
  }
  return local_8;
}



/* c0829ef8 FUN_c0829ef8 */

/* Boundary evidence: original MIPS .pdata c0829ef8..c0829f1b. Semantic name remains unreviewed. */

undefined4 FUN_c0829ef8(int param_1)

{
  return *(undefined4 *)(param_1 + 0x28);
}



/* c0829f1c FUN_c0829f1c */

/* Boundary evidence: original MIPS .pdata c0829f1c..c0829f5f. Semantic name remains unreviewed. */

bool FUN_c0829f1c(int *param_1)

{
  return *param_1 != 0;
}



/* c0829f60 FUN_c0829f60 */

/* Boundary evidence: original MIPS .pdata c0829f60..c0829f97. Semantic name remains unreviewed. */

int FUN_c0829f60(int *param_1)

{
  int iVar1;
  
  iVar1 = FUN_c0828a80(param_1);
  return iVar1;
}



/* c0829f98 FUN_c0829f98 */

/* Boundary evidence: original MIPS .pdata c0829f98..c0829fff. Semantic name remains unreviewed. */

void FUN_c0829f98(int param_1,char *param_2)

{
  LPVOID pvVar1;
  
  if (param_2 != (char *)0x0) {
    if (*(int *)(param_1 + 0x30) != 0) {
      FUN_c0824790(*(LPVOID *)(param_1 + 0x30));
    }
    pvVar1 = FUN_c082497c(param_2);
    *(LPVOID *)(param_1 + 0x30) = pvVar1;
  }
  return;
}



/* c082a000 FUN_c082a000 */

/* Boundary evidence: original MIPS .pdata c082a000..c082a04b. Semantic name remains unreviewed. */

undefined * FUN_c082a000(int param_1)

{
  undefined *local_4;
  
  if (param_1 == 0) {
    local_4 = &DAT_c0821f5c;
  }
  else {
    local_4 = *(undefined **)(param_1 + 0x30);
  }
  return local_4;
}



/* c082a04c FUN_c082a04c */

/* Boundary evidence: original MIPS .pdata c082a04c..c082a087. Semantic name remains unreviewed. */

undefined4 FUN_c082a04c(int *param_1)

{
  FUN_c08286fc(param_1);
  FUN_c0828440();
  return 0;
}



/* c082a088 FUN_c082a088 */

/* Boundary evidence: original MIPS .pdata c082a088..c082a1ff. Semantic name remains unreviewed. */

void FUN_c082a088(int *param_1)

{
  bool bVar1;
  undefined3 extraout_var;
  int iVar2;
  int *piVar3;
  int *local_14;
  
  if (param_1 != (int *)0x0) {
    bVar1 = FUN_c0829f1c(param_1);
    if (CONCAT31(extraout_var,bVar1) != 0) {
      FUN_c08286fc(param_1);
    }
    iVar2 = FUN_c0829e94((int)param_1);
    if (iVar2 != 0) {
      piVar3 = *(int **)(iVar2 + 0x34);
      while (local_14 = piVar3, local_14 != (int *)0x0) {
        piVar3 = (int *)local_14[0xf];
        if (local_14 == param_1) {
          if (local_14[0xf] == 0) {
            *(int *)(iVar2 + 0x38) = local_14[0x10];
          }
          else {
            *(int *)(local_14[0xf] + 0x40) = local_14[0x10];
          }
          *(int *)local_14[0x10] = local_14[0xf];
        }
      }
    }
    FUN_c08281e4((int)param_1);
    if (param_1[0xb] != 0) {
      FUN_c0824790((LPVOID)param_1[0xb]);
    }
    if (param_1[0xc] != 0) {
      FUN_c0824790((LPVOID)param_1[0xc]);
    }
    FUN_c0824790(param_1);
  }
  return;
}



/* c082a200 FUN_c082a200 */

/* Boundary evidence: original MIPS .pdata c082a200..c082a307. Semantic name remains unreviewed. */

LPVOID FUN_c082a200(undefined4 param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 local_c;
  
  local_c = FUN_c08246fc(0x44);
  if (local_c == (LPVOID)0x0) {
    local_c = (LPVOID)0x0;
  }
  else {
    *(int *)((int)local_c + 0x10) = param_2;
    *(undefined4 *)((int)local_c + 0x18) = param_1;
    *(undefined4 *)((int)local_c + 4) = param_4;
    FUN_c082a308((int)local_c,param_3);
    *(undefined4 *)((int)local_c + 0x34) = 0;
    *(int *)((int)local_c + 0x38) = (int)local_c + 0x34;
    if (param_2 != 0) {
      *(undefined4 *)((int)local_c + 0x3c) = 0;
      *(undefined4 *)((int)local_c + 0x40) = *(undefined4 *)(param_2 + 0x38);
      **(undefined4 **)(param_2 + 0x38) = local_c;
      *(int *)(param_2 + 0x38) = (int)local_c + 0x3c;
    }
    FUN_c0828194((int)local_c);
  }
  return local_c;
}



/* c082a308 FUN_c082a308 */

void FUN_c082a308(int param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 0x24) = param_2;
  return;
}



/* c082a324 FUN_c082a324 */

/* Boundary evidence: original MIPS .pdata c082a324..c082a363. Semantic name remains unreviewed. */

undefined4 FUN_c082a324(int param_1)

{
  undefined4 local_8;
  
  if (param_1 == 0) {
    local_8 = 0;
  }
  else {
    local_8 = *(undefined4 *)(param_1 + 4);
  }
  return local_8;
}



/* c082a364 FUN_c082a364 */

/* Boundary evidence: original MIPS .pdata c082a364..c082a3df. Semantic name remains unreviewed. */

void FUN_c082a364(int param_1)

{
  int iVar1;
  
  FUN_c082638c(*(HANDLE *)(param_1 + 0x1c));
  iVar1 = *(int *)(param_1 + 0x14);
  FUN_c08263dc(*(HANDLE *)(param_1 + 0x1c));
  if (iVar1 != 0) {
    (**(code **)(param_1 + 0xc))(*(undefined4 *)(param_1 + 4),1);
  }
  return;
}



/* c082a3e0 FUN_c082a3e0 */

/* Boundary evidence: original MIPS .pdata c082a3e0..c082a41b. Semantic name remains unreviewed. */

void FUN_c082a3e0(int param_1)

{
  (**(code **)(param_1 + 0xc))(*(undefined4 *)(param_1 + 4),0);
  return;
}



/* c082a41c FUN_c082a41c */

/* Boundary evidence: original MIPS .pdata c082a41c..c082a45f. Semantic name remains unreviewed. */

void FUN_c082a41c(int param_1,undefined4 param_2)

{
  (**(code **)(param_1 + 8))(*(undefined4 *)(param_1 + 4),param_2);
  return;
}



/* c082a460 FUN_c082a460 */

/* Boundary evidence: original MIPS .pdata c082a460..c082a5b3. Semantic name remains unreviewed. */

void FUN_c082a460(undefined4 *param_1,void *param_2,uint *param_3)

{
  int iVar1;
  LPVOID local_1c;
  undefined4 *local_18;
  int *local_14;
  
  local_1c = (LPVOID)0x0;
  if ((param_3 != (uint *)0x0) && (*param_3 != 0)) {
    local_18 = param_1;
    FUN_c0827790();
    iVar1 = FUN_c082901c(*param_3,0,(int *)0x0,(int *)0x0,0,&local_1c);
    FUN_c08277b8();
    if (iVar1 == 0) {
      local_14 = (int *)FUN_c0828ffc(local_1c);
      FUN_c0827ba0((void *)*local_14,param_2,*param_3);
      FUN_c0827790();
      iVar1 = FUN_c08331f8((int *)*local_18,local_14,*param_3,(int)local_1c);
      FUN_c08277b8();
      if (iVar1 == 0) {
        return;
      }
    }
    if (local_1c != (LPVOID)0x0) {
      FUN_c0827790();
      FUN_c0829a8c(local_1c);
      FUN_c08277b8();
    }
    *param_3 = 0;
  }
  return;
}



/* c082a5b4 FUN_c082a5b4 */

/* Boundary evidence: original MIPS .pdata c082a5b4..c082a82f. Semantic name remains unreviewed. */

undefined4 FUN_c082a5b4(undefined4 *param_1,void *param_2,uint *param_3)

{
  void *local_res4;
  uint *local_1c;
  size_t local_18;
  uint local_10;
  
  local_10 = *param_3;
  *param_3 = 0;
  FUN_c082638c((HANDLE)param_1[7]);
  local_1c = (uint *)param_1[5];
  FUN_c08263dc((HANDLE)param_1[7]);
  local_res4 = param_2;
  if (local_1c != (uint *)0x0) {
    while (local_1c != (uint *)0x0) {
      if (local_10 < *local_1c) {
        local_18 = local_10;
      }
      else {
        local_18 = *local_1c;
      }
      FUN_c0827ba0(local_res4,(void *)local_1c[1],local_18);
      *param_3 = *param_3 + local_18;
      if (local_18 != *local_1c) {
        local_1c[1] = local_1c[1] + local_18;
        *local_1c = *local_1c - local_18;
        FUN_c0827790();
        FUN_c082a830((int)(param_1 + 0x45),FUN_c082a364,param_1,0);
        FUN_c08277b8();
        return 0;
      }
      FUN_c082638c((HANDLE)param_1[7]);
      if (local_1c[4] == 0) {
        param_1[6] = local_1c[5];
      }
      else {
        *(uint *)(local_1c[4] + 0x14) = local_1c[5];
      }
      *(uint *)local_1c[5] = local_1c[4];
      FUN_c08263dc((HANDLE)param_1[7]);
      FUN_c0827790();
      FUN_c08334b0((int *)*param_1,(int *)local_1c[3],param_1[4],(int)local_1c);
      FUN_c08277b8();
      local_10 = local_10 - local_18;
      local_res4 = (void *)((int)local_res4 + local_18);
      FUN_c082638c((HANDLE)param_1[7]);
      local_1c = (uint *)param_1[5];
      FUN_c08263dc((HANDLE)param_1[7]);
    }
  }
  return 0;
}



/* c082a830 FUN_c082a830 */

/* Boundary evidence: original MIPS .pdata c082a830..c082a91f. Semantic name remains unreviewed. */

undefined4 FUN_c082a830(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 *puVar1;
  undefined4 local_c;
  
  puVar1 = FUN_c08246fc(0x14);
  if (puVar1 == (undefined4 *)0x0) {
    local_c = 7;
  }
  else {
    *puVar1 = param_2;
    puVar1[1] = param_3;
    puVar1[2] = param_4;
    FUN_c082638c(*(HANDLE *)(param_1 + 0xc));
    puVar1[3] = 0;
    puVar1[4] = *(undefined4 *)(param_1 + 4);
    **(undefined4 **)(param_1 + 4) = puVar1;
    *(undefined4 **)(param_1 + 4) = puVar1 + 3;
    FUN_c08263dc(*(HANDLE *)(param_1 + 0xc));
    FUN_c082668c(*(undefined4 *)(param_1 + 8));
    local_c = 0;
  }
  return local_c;
}



/* c082a920 FUN_c082a920 */

/* Boundary evidence: original MIPS .pdata c082a920..c082a94b. Semantic name remains unreviewed. */

void FUN_c082a920(int param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 0x20) = param_2;
  return;
}



/* c082a94c FUN_c082a94c */

/* Boundary evidence: original MIPS .pdata c082a94c..c082a967. Semantic name remains unreviewed. */

undefined4 FUN_c082a94c(void)

{
  return 0;
}



/* c082a970 FUN_c082a970 */

/* Boundary evidence: original MIPS .pdata c082a970..c082ab4b. Semantic name remains unreviewed. */

int FUN_c082a970(undefined4 param_1,undefined4 *param_2,ushort *param_3,undefined4 *param_4)

{
  undefined4 *puVar1;
  int local_18;
  
  FUN_c08277b8();
  local_18 = FUN_c082ab4c();
  FUN_c0827790();
  if (local_18 == 0) {
    puVar1 = FUN_c08246fc(0x128);
    if (puVar1 == (undefined4 *)0x0) {
      local_18 = 7;
    }
    else {
      *param_4 = puVar1;
      *puVar1 = param_1;
      param_3[8] = 0x3f;
      param_3[2] = 100;
      param_3[3] = 0;
      *param_3 = *param_3 | 0x1f;
      *param_2 = FUN_c082ac58;
      param_2[1] = FUN_c082b368;
      param_2[2] = FUN_c082b470;
      param_2[5] = FUN_c082b4b0;
      param_2[6] = &LAB_c082b4d8;
      param_2[7] = FUN_c082b628;
      param_2[8] = FUN_c082b4ec;
      param_2[9] = FUN_c082b548;
      param_2[10] = FUN_c082b570;
      param_2[0xb] = FUN_c082b598;
      param_2[0xc] = FUN_c082b5bc;
      param_2[0xd] = FUN_c082b5e0;
      param_2[0xe] = FUN_c082b70c;
      param_2[0xf] = FUN_c082b604;
      param_2[0x10] = 0;
      param_2[0x11] = 0;
      param_2[0x12] = 0;
      param_2[0x13] = 0;
    }
  }
  return local_18;
}



/* c082ab4c FUN_c082ab4c */

/* Boundary evidence: original MIPS .pdata c082ab4c..c082ac57. Semantic name remains unreviewed. */

undefined4 FUN_c082ab4c(void)

{
  undefined4 local_10;
  
  if (DAT_c0839374 == 0) {
    DAT_c0839374 = LoadDriver(L"JACMDEV.DLL");
    if (DAT_c0839374 == 0) {
      local_10 = 10;
    }
    else {
      DAT_c0839378 = GetProcAddressW(DAT_c0839374,L"register_usb_stack");
      if (DAT_c0839378 == 0) {
        local_10 = 10;
      }
      else {
        DAT_c083937c = GetProcAddressW(DAT_c0839374,L"unregister_usb_stack");
        if (DAT_c083937c == 0) {
          local_10 = 10;
        }
        else {
          local_10 = 0;
        }
      }
    }
  }
  else {
    local_10 = 0;
  }
  return local_10;
}



/* c082ac58 FUN_c082ac58 */

/* Boundary evidence: original MIPS .pdata c082ac58..c082adc3. Semantic name remains unreviewed. */

int FUN_c082ac58(int *param_1)

{
  ushort uVar1;
  int iVar2;
  int local_18;
  int local_10;
  
  if ((DAT_c0839378 == (code *)0x0) || (DAT_c083937c == (code *)0x0)) {
    local_10 = 10;
  }
  else {
    FUN_c08277b8();
    iVar2 = (*DAT_c0839378)(param_1,&PTR_FUN_c0839174,param_1 + 2);
    param_1[1] = iVar2;
    FUN_c0827790();
    if (param_1[1] == 0) {
      local_10 = 10;
    }
    else {
      local_18 = FUN_c082adc4(param_1 + 0x45);
      if (local_18 == 0) {
        uVar1 = FUN_c083385c(*param_1);
        param_1[4] = (uint)uVar1;
        local_18 = FUN_c082b0fc(param_1);
        if (local_18 == 0) {
          return 0;
        }
        FUN_c082b07c((int)(param_1 + 0x45));
      }
      FUN_c08277b8();
      (*DAT_c083937c)(param_1[1]);
      FUN_c0827790();
      local_10 = local_18;
    }
  }
  return local_10;
}



/* c082adc4 FUN_c082adc4 */

/* Boundary evidence: original MIPS .pdata c082adc4..c082aedf. Semantic name remains unreviewed. */

int FUN_c082adc4(undefined4 *param_1)

{
  int local_18;
  undefined4 uStack_14;
  int local_10;
  
  local_10 = FUN_c0826490(param_1 + 2);
  if (local_10 == 0) {
    *param_1 = 0;
    param_1[1] = param_1;
    local_18 = FUN_c08260bc(FUN_c082aee0,param_1,0x34,"TASK_MANAGER_RUN",&uStack_14);
    if ((local_18 == 0) && (local_18 = FUN_c08262cc(param_1 + 3), local_18 == 0)) {
      param_1[4] = 0;
      local_10 = 0;
    }
    else {
      if (param_1[3] != 0) {
        FUN_c0826348((HANDLE)param_1[3]);
      }
      FUN_c082650c((HANDLE)param_1[2]);
      local_10 = local_18;
    }
  }
  return local_10;
}



/* c082aee0 FUN_c082aee0 */

/* Boundary evidence: original MIPS .pdata c082aee0..c082b07b. Semantic name remains unreviewed. */

void FUN_c082aee0(int *param_1)

{
  undefined4 *local_c;
  
  FUN_c08277b8();
  FUN_c082638c((HANDLE)param_1[3]);
  while (param_1[4] == 0) {
    if (*param_1 == 0) {
      FUN_c08263dc((HANDLE)param_1[3]);
      FUN_c0826650((HANDLE)param_1[2],0);
      FUN_c082638c((HANDLE)param_1[3]);
    }
    local_c = (undefined4 *)*param_1;
    while (local_c != (undefined4 *)0x0) {
      if (*(int *)(*param_1 + 0xc) == 0) {
        param_1[1] = *(int *)(*param_1 + 0x10);
      }
      else {
        *(undefined4 *)(*(int *)(*param_1 + 0xc) + 0x10) = *(undefined4 *)(*param_1 + 0x10);
      }
      **(undefined4 **)(*param_1 + 0x10) = *(undefined4 *)(*param_1 + 0xc);
      FUN_c08263dc((HANDLE)param_1[3]);
      (*(code *)*local_c)(local_c[1],local_c[2]);
      FUN_c082638c((HANDLE)param_1[3]);
      FUN_c0824790(local_c);
      local_c = (undefined4 *)*param_1;
    }
  }
  param_1[4] = 2;
  FUN_c08263dc((HANDLE)param_1[3]);
  FUN_c0827790();
  return;
}



/* c082b07c FUN_c082b07c */

/* Boundary evidence: original MIPS .pdata c082b07c..c082b0fb. Semantic name remains unreviewed. */

void FUN_c082b07c(int param_1)

{
  *(undefined4 *)(param_1 + 0x10) = 1;
  FUN_c082668c(*(undefined4 *)(param_1 + 8));
  while (*(int *)(param_1 + 0x10) != 2) {
    FUN_c0826450(100);
  }
  FUN_c082650c(*(HANDLE *)(param_1 + 8));
  FUN_c0826348(*(HANDLE *)(param_1 + 0xc));
  return;
}



/* c082b0fc FUN_c082b0fc */

/* Boundary evidence: original MIPS .pdata c082b0fc..c082b29b. Semantic name remains unreviewed. */

int FUN_c082b0fc(undefined4 *param_1)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int local_20;
  int local_18;
  int local_c;
  
  param_1[5] = 0;
  param_1[6] = param_1 + 5;
  local_20 = FUN_c08262cc(param_1 + 7);
  if (local_20 == 0) {
    for (local_18 = 0; local_18 < 10; local_18 = local_18 + 1) {
      puVar2 = param_1 + local_18 * 6 + 9;
      local_20 = FUN_c082901c(param_1[4],0,(int *)0x0,(int *)0x0,0,puVar2 + 2);
      if (local_20 != 0) goto LAB_c082b244;
      uVar1 = FUN_c0828ffc(puVar2[2]);
      puVar2[3] = uVar1;
      local_20 = FUN_c08334b0((int *)*param_1,(int *)puVar2[3],param_1[4],(int)puVar2);
      if (local_20 != 0) goto LAB_c082b244;
    }
    local_c = 0;
  }
  else {
LAB_c082b244:
    if (param_1[7] != 0) {
      FUN_c0826348((HANDLE)param_1[7]);
    }
    FUN_c08337f4((int *)*param_1);
    FUN_c082b29c((int)param_1);
    local_c = local_20;
  }
  return local_c;
}



/* c082b29c FUN_c082b29c */

/* Boundary evidence: original MIPS .pdata c082b29c..c082b367. Semantic name remains unreviewed. */

void FUN_c082b29c(int param_1)

{
  undefined4 local_10;
  
  local_10 = 0;
  while ((local_10 < 10 && (*(int *)(param_1 + local_10 * 0x18 + 0x2c) != 0))) {
    FUN_c0829a8c(*(LPVOID *)(param_1 + local_10 * 0x18 + 0x2c));
    *(undefined4 *)(param_1 + local_10 * 0x18 + 0x2c) = 0;
    local_10 = local_10 + 1;
  }
  FUN_c0826348(*(HANDLE *)(param_1 + 0x1c));
  return;
}



/* c082b368 FUN_c082b368 */

/* Boundary evidence: original MIPS .pdata c082b368..c082b46f. Semantic name remains unreviewed. */

undefined4 FUN_c082b368(undefined4 *param_1)

{
  uint local_18;
  
  local_18 = 0;
  FUN_c08337f4((int *)*param_1);
  FUN_c083378c((int *)*param_1);
  FUN_c082b29c((int)param_1);
  FUN_c082a830((int)(param_1 + 0x45),FUN_c082a41c,param_1,0);
  while( true ) {
    if (param_1[8] == 0) {
      FUN_c082b07c((int)(param_1 + 0x45));
      FUN_c08277b8();
      (*DAT_c083937c)(param_1[1]);
      FUN_c0827790();
      return 0;
    }
    if (9999 < local_18) break;
    FUN_c0826450(5);
    local_18 = local_18 + 5;
  }
  return 0xc;
}



/* c082b470 FUN_c082b470 */

/* Boundary evidence: original MIPS .pdata c082b470..c082b4af. Semantic name remains unreviewed. */

undefined4 FUN_c082b470(LPVOID param_1)

{
  if (param_1 != (LPVOID)0x0) {
    FUN_c0824790(param_1);
  }
  return 0;
}



/* c082b4b0 FUN_c082b4b0 */

/* Boundary evidence: original MIPS .pdata c082b4b0..c082b4d7. Semantic name remains unreviewed. */

undefined4 FUN_c082b4b0(void)

{
  return 0;
}



/* c082b4ec FUN_c082b4ec */

/* Boundary evidence: original MIPS .pdata c082b4ec..c082b547. Semantic name remains unreviewed. */

void FUN_c082b4ec(undefined4 param_1,undefined4 param_2,int param_3,LPVOID param_4)

{
  FUN_c0829a8c(param_4);
  FUN_c082a830(param_3 + 0x114,FUN_c082a3e0,param_3,0);
  return;
}



/* c082b548 FUN_c082b548 */

/* Boundary evidence: original MIPS .pdata c082b548..c082b56f. Semantic name remains unreviewed. */

undefined4 FUN_c082b548(void)

{
  return 0;
}



/* c082b570 FUN_c082b570 */

/* Boundary evidence: original MIPS .pdata c082b570..c082b597. Semantic name remains unreviewed. */

undefined4 FUN_c082b570(void)

{
  return 0;
}



/* c082b598 FUN_c082b598 */

/* Boundary evidence: original MIPS .pdata c082b598..c082b5bb. Semantic name remains unreviewed. */

undefined4 FUN_c082b598(void)

{
  return 0;
}



/* c082b5bc FUN_c082b5bc */

/* Boundary evidence: original MIPS .pdata c082b5bc..c082b5df. Semantic name remains unreviewed. */

undefined4 FUN_c082b5bc(void)

{
  return 0;
}



/* c082b5e0 FUN_c082b5e0 */

/* Boundary evidence: original MIPS .pdata c082b5e0..c082b603. Semantic name remains unreviewed. */

undefined4 FUN_c082b5e0(void)

{
  return 0;
}



/* c082b604 FUN_c082b604 */

/* Boundary evidence: original MIPS .pdata c082b604..c082b627. Semantic name remains unreviewed. */

undefined4 FUN_c082b604(void)

{
  return 0;
}



/* c082b628 FUN_c082b628 */

/* Boundary evidence: original MIPS .pdata c082b628..c082b70b. Semantic name remains unreviewed. */

void FUN_c082b628(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,int param_5,
                 undefined4 *param_6)

{
  if (param_1 == 0) {
    *param_6 = param_3;
    param_6[1] = *(undefined4 *)param_6[3];
    FUN_c082638c(*(HANDLE *)(param_5 + 0x1c));
    param_6[4] = 0;
    param_6[5] = *(undefined4 *)(param_5 + 0x18);
    **(undefined4 **)(param_5 + 0x18) = param_6;
    *(undefined4 **)(param_5 + 0x18) = param_6 + 4;
    FUN_c08263dc(*(HANDLE *)(param_5 + 0x1c));
    FUN_c082a830(param_5 + 0x114,FUN_c082a364,param_5,0);
  }
  return;
}



/* c082b70c FUN_c082b70c */

/* Boundary evidence: original MIPS .pdata c082b70c..c082b79b. Semantic name remains unreviewed. */

undefined4 FUN_c082b70c(ushort param_1,int param_2)

{
  undefined4 uVar1;
  uint local_14;
  
  local_14 = 0;
  if ((param_1 & 1) != 0) {
    local_14 = 0xa0;
  }
  if ((param_1 & 2) != 0) {
    local_14 = local_14 | 0x10;
  }
  uVar1 = FUN_c082a830(param_2 + 0x114,FUN_c082a41c,param_2,local_14);
  return uVar1;
}



/* c082b79c FUN_c082b79c */

/* Boundary evidence: original MIPS .pdata c082b79c..c082b96b. Semantic name remains unreviewed. */

int FUN_c082b79c(int *param_1,void *param_2,undefined4 param_3,undefined4 param_4)

{
  int local_20;
  
  local_20 = 0xb;
  *(char *)(param_1 + 0x14) = (char)param_3;
  switch(*(undefined1 *)((int)param_2 + 1)) {
  case 0:
    local_20 = FUN_c0833bc8(param_1,(int)param_2);
    break;
  case 1:
    local_20 = FUN_c0833dd8(param_1,(int)param_2);
    break;
  case 2:
    local_20 = FUN_c082b96c(param_1,param_2);
    break;
  case 3:
    local_20 = FUN_c082bb80(param_1,(int)param_2,param_3,param_4);
    break;
  case 4:
    local_20 = FUN_c082bd5c(param_1,(int)param_2);
    break;
  case 0x20:
    local_20 = FUN_c082be44(param_1,(int)param_2);
    break;
  case 0x21:
    local_20 = FUN_c082c0bc(param_1,(int)param_2);
    break;
  case 0x22:
    local_20 = FUN_c082c2e8(param_1,(int)param_2);
    break;
  case 0x23:
    local_20 = FUN_c082c3bc(param_1,(int)param_2);
  }
  return local_20;
}



/* c082b96c FUN_c082b96c */

/* Boundary evidence: original MIPS .pdata c082b96c..c082ba8f. Semantic name remains unreviewed. */

int FUN_c082b96c(int *param_1,void *param_2)

{
  LPVOID pvVar1;
  int local_20;
  
  local_20 = 10;
  if ((((*(ushort *)(param_1 + 0x36) & 1) != 0) && (*(short *)((int)param_2 + 6) == 2)) &&
     (param_1[0x27] != 0)) {
    FUN_c0827ba0(param_1 + 0x12,param_2,8);
    pvVar1 = FUN_c0833880(param_1,2);
    if (pvVar1 == (LPVOID)0x0) {
      local_20 = 7;
    }
    else {
      *(code **)((int)pvVar1 + 0x10) = FUN_c082ba90;
      *(int **)((int)pvVar1 + 0x14) = param_1;
      local_20 = FUN_c0830fc4(*param_1,0,(int)pvVar1);
    }
  }
  return local_20;
}



/* c082ba90 FUN_c082ba90 */

/* Boundary evidence: original MIPS .pdata c082ba90..c082bb7f. Semantic name remains unreviewed. */

void FUN_c082ba90(int param_1)

{
  int iVar1;
  int *piVar2;
  undefined2 local_14 [2];
  int *local_10;
  
  piVar2 = *(int **)(param_1 + 0x14);
  local_10 = piVar2 + 0x1e;
  iVar1 = FUN_c083314c(param_1,1);
  if (iVar1 == 0) {
    local_14[0] = *(undefined2 *)**(undefined4 **)(param_1 + 8);
    iVar1 = (*(code *)local_10[9])(*(undefined2 *)((int)piVar2 + 0x4a),local_14,piVar2[1]);
    if ((iVar1 == 0) && (iVar1 = FUN_c0833b3c(piVar2), iVar1 == 0)) {
      return;
    }
  }
  FUN_c083106c(*piVar2,(char)piVar2[0x14]);
  return;
}



/* c082bb80 FUN_c082bb80 */

/* Boundary evidence: original MIPS .pdata c082bb80..c082bce7. Semantic name remains unreviewed. */

int FUN_c082bb80(int *param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  undefined1 *puVar1;
  int iVar2;
  undefined1 local_1c [4];
  int *local_18;
  int *local_14;
  
  local_18 = param_1 + 0x32;
  local_14 = param_1 + 0x1e;
  iVar2 = 10;
  if (((((*(ushort *)(param_1 + 0x36) & 1) != 0) && (*(short *)(param_2 + 6) == 2)) &&
      (param_1[0x28] != 0)) &&
     (iVar2 = (*(code *)param_1[0x28])
                        (*(undefined2 *)(param_2 + 2),local_1c,param_1[1],param_4,10,0), iVar2 == 0)
     ) {
    puVar1 = FUN_c0833a44(param_1,local_1c,2,(uint)*(ushort *)(param_2 + 6));
    if (puVar1 == (undefined1 *)0x0) {
      iVar2 = 7;
    }
    else {
      *(code **)(puVar1 + 0x10) = FUN_c082bce8;
      *(int **)(puVar1 + 0x14) = param_1;
      iVar2 = FUN_c0830ba8(*param_1,0,(int)puVar1);
    }
  }
  return iVar2;
}



/* c082bce8 FUN_c082bce8 */

/* Boundary evidence: original MIPS .pdata c082bce8..c082bd5b. Semantic name remains unreviewed. */

void FUN_c082bce8(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0x14);
  if (*(int *)(iVar2 + 0xb8) != 0) {
    uVar1 = FUN_c083314c(param_1,1);
    (**(code **)(iVar2 + 0xb8))(uVar1,*(undefined4 *)(iVar2 + 4));
  }
  return;
}



/* c082bd5c FUN_c082bd5c */

/* Boundary evidence: original MIPS .pdata c082bd5c..c082be43. Semantic name remains unreviewed. */

int FUN_c082bd5c(int *param_1,int param_2)

{
  int local_20;
  
  local_20 = 10;
  if (((((*(ushort *)(param_1 + 0x36) & 1) != 0) && (*(short *)(param_2 + 6) == 0)) &&
      (param_1[0x29] != 0)) &&
     (local_20 = (*(code *)param_1[0x29])(*(undefined2 *)(param_2 + 2),param_1[1]), local_20 == 0))
  {
    local_20 = FUN_c0833b3c(param_1);
  }
  return local_20;
}



/* c082be44 FUN_c082be44 */

/* Boundary evidence: original MIPS .pdata c082be44..c082bf4f. Semantic name remains unreviewed. */

int FUN_c082be44(int *param_1,int param_2)

{
  LPVOID pvVar1;
  int local_20;
  
  local_20 = 10;
  if ((((*(ushort *)(param_1 + 0x36) & 2) != 0) && (*(short *)(param_2 + 6) == 7)) &&
     (param_1[0x2a] != 0)) {
    pvVar1 = FUN_c0833880(param_1,7);
    if (pvVar1 == (LPVOID)0x0) {
      local_20 = 7;
    }
    else {
      *(code **)((int)pvVar1 + 0x10) = FUN_c082bf50;
      *(int **)((int)pvVar1 + 0x14) = param_1;
      local_20 = FUN_c0830fc4(*param_1,0,(int)pvVar1);
    }
  }
  return local_20;
}



/* c082bf50 FUN_c082bf50 */

/* Boundary evidence: original MIPS .pdata c082bf50..c082c0bb. Semantic name remains unreviewed. */

void FUN_c082bf50(int param_1)

{
  int iVar1;
  undefined4 local_24;
  int *local_20;
  undefined1 auStack_1c [4];
  undefined1 local_18;
  undefined1 local_17;
  undefined1 local_16;
  undefined4 *local_14;
  int *local_10;
  uint local_c;
  
  local_c = DAT_c0839254;
  local_20 = *(int **)(param_1 + 0x14);
  local_10 = local_20 + 0x1e;
  iVar1 = FUN_c083314c(param_1,1);
  if (iVar1 == 0) {
    local_14 = (undefined4 *)**(undefined4 **)(param_1 + 8);
    local_24 = *local_14;
    FUN_c0827ba0(auStack_1c,&local_24,4);
    local_18 = *(undefined1 *)(local_14 + 1);
    local_17 = *(undefined1 *)((int)local_14 + 5);
    local_16 = *(undefined1 *)((int)local_14 + 6);
    iVar1 = (*(code *)local_10[0xc])(auStack_1c,local_20[1]);
    if ((iVar1 == 0) && (iVar1 = FUN_c0833b3c(local_20), iVar1 == 0)) goto LAB_c082c0a0;
  }
  FUN_c083106c(*local_20,(char)local_20[0x14]);
LAB_c082c0a0:
  FUN_c0838c24(local_c);
  return;
}



/* c082c0bc FUN_c082c0bc */

/* Boundary evidence: original MIPS .pdata c082c0bc..c082c273. Semantic name remains unreviewed. */

int FUN_c082c0bc(int *param_1,int param_2)

{
  undefined1 *puVar1;
  int local_30;
  undefined1 local_28 [4];
  undefined1 local_24;
  undefined1 local_23;
  undefined1 local_22;
  undefined1 local_21;
  int *local_1c;
  int *local_18;
  uint local_14;
  
  local_14 = DAT_c0839254;
  local_1c = param_1 + 0x32;
  local_18 = param_1 + 0x1e;
  local_30 = 10;
  if (((((*(ushort *)(param_1 + 0x36) & 2) != 0) && (*(short *)(param_2 + 6) == 7)) &&
      (param_1[0x2b] != 0)) &&
     (local_30 = (*(code *)param_1[0x2b])(&local_24,param_1[1]), local_30 == 0)) {
    FUN_c0827ba0(local_28,&local_24,4);
    local_24 = local_28[0];
    local_23 = local_28[1];
    local_22 = local_28[2];
    local_21 = local_28[3];
    puVar1 = FUN_c0833a44(param_1,&local_24,7,(uint)*(ushort *)(param_2 + 6));
    if (puVar1 == (undefined1 *)0x0) {
      local_30 = 7;
    }
    else {
      *(code **)(puVar1 + 0x10) = FUN_c082c274;
      *(int **)(puVar1 + 0x14) = param_1;
      local_30 = FUN_c0830ba8(*param_1,0,(int)puVar1);
    }
  }
  FUN_c0838c24(local_14);
  return local_30;
}



/* c082c274 FUN_c082c274 */

/* Boundary evidence: original MIPS .pdata c082c274..c082c2e7. Semantic name remains unreviewed. */

void FUN_c082c274(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0x14);
  if (*(int *)(iVar2 + 0xbc) != 0) {
    uVar1 = FUN_c083314c(param_1,1);
    (**(code **)(iVar2 + 0xbc))(uVar1,*(undefined4 *)(iVar2 + 4));
  }
  return;
}



/* c082c2e8 FUN_c082c2e8 */

/* Boundary evidence: original MIPS .pdata c082c2e8..c082c3bb. Semantic name remains unreviewed. */

int FUN_c082c2e8(int *param_1,int param_2)

{
  int local_20;
  
  local_20 = 10;
  if ((((*(ushort *)(param_1 + 0x36) & 2) != 0) && (param_1[0x2c] != 0)) &&
     (local_20 = (*(code *)param_1[0x2c])(*(undefined2 *)(param_2 + 2),param_1[1]), local_20 == 0))
  {
    local_20 = FUN_c0833b3c(param_1);
  }
  return local_20;
}



/* c082c3bc FUN_c082c3bc */

/* Boundary evidence: original MIPS .pdata c082c3bc..c082c48f. Semantic name remains unreviewed. */

int FUN_c082c3bc(int *param_1,int param_2)

{
  int local_20;
  
  local_20 = 10;
  if ((((*(ushort *)(param_1 + 0x36) & 4) != 0) && (param_1[0x2d] != 0)) &&
     (local_20 = (*(code *)param_1[0x2d])(*(undefined2 *)(param_2 + 2),param_1[1]), local_20 == 0))
  {
    local_20 = FUN_c0833b3c(param_1);
  }
  return local_20;
}



/* c082c490 FUN_c082c490 */

/* Boundary evidence: original MIPS .pdata c082c490..c082c5ab. Semantic name remains unreviewed. */

int FUN_c082c490(int *param_1,undefined2 param_2)

{
  undefined1 *puVar1;
  undefined2 local_res4 [6];
  int local_28;
  
  if (param_1[0xd] == 0) {
    local_28 = 6;
  }
  else if ((*(ushort *)(param_1 + 0x36) & 2) == 0) {
    local_28 = 0xb;
  }
  else {
    local_res4[0] = param_2;
    puVar1 = FUN_c0834084(param_1,0x20,0,(short)param_1[0xe],2,local_res4);
    if (puVar1 == (undefined1 *)0x0) {
      local_28 = 7;
    }
    else {
      *(code **)(puVar1 + 0x10) = FUN_c082c5ac;
      *(int **)(puVar1 + 0x14) = param_1;
      local_28 = FUN_c0830ba8(*param_1,param_1[0xd],(int)puVar1);
    }
  }
  return local_28;
}



/* c082c5ac FUN_c082c5ac */

/* Boundary evidence: original MIPS .pdata c082c5ac..c082c62b. Semantic name remains unreviewed. */

void FUN_c082c5ac(LPVOID param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  iVar2 = *(int *)((int)param_1 + 0x14);
  if (*(int *)(iVar2 + 0xc4) != 0) {
    uVar1 = FUN_c083314c((int)param_1,1);
    (**(code **)(iVar2 + 0xc4))(uVar1,*(undefined4 *)(iVar2 + 4));
  }
  FUN_c083175c(param_1);
  return;
}



/* c082c62c FUN_c082c62c */

/* Boundary evidence: original MIPS .pdata c082c62c..c082c663. Semantic name remains unreviewed. */

undefined4 FUN_c082c62c(int param_1,undefined2 param_2)

{
  *(undefined2 *)(param_1 + 0xd0) = param_2;
  return 0;
}



/* c082c664 FUN_c082c664 */

/* Boundary evidence: original MIPS .pdata c082c664..c082c79b. Semantic name remains unreviewed. */

int FUN_c082c664(int *param_1,int param_2)

{
  undefined1 *puVar1;
  int local_28;
  
  if (param_1[0xd] == 0) {
    local_28 = 6;
  }
  else if ((*(ushort *)(param_1 + 0x36) & 8) == 0) {
    local_28 = 0xb;
  }
  else {
    puVar1 = FUN_c0834084(param_1,0,(ushort)(param_2 != 0),(short)param_1[0xe],0,(void *)0x0);
    if (puVar1 == (undefined1 *)0x0) {
      local_28 = 7;
    }
    else {
      *(code **)(puVar1 + 0x10) = FUN_c082c79c;
      *(int **)(puVar1 + 0x14) = param_1;
      local_28 = FUN_c0830ba8(*param_1,param_1[0xd],(int)puVar1);
    }
  }
  return local_28;
}



/* c082c79c FUN_c082c79c */

/* Boundary evidence: original MIPS .pdata c082c79c..c082c81b. Semantic name remains unreviewed. */

void FUN_c082c79c(LPVOID param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  iVar2 = *(int *)((int)param_1 + 0x14);
  if (*(int *)(iVar2 + 0xc0) != 0) {
    uVar1 = FUN_c083314c((int)param_1,1);
    (**(code **)(iVar2 + 0xc0))(uVar1,*(undefined4 *)(iVar2 + 4));
  }
  FUN_c083175c(param_1);
  return;
}



/* c082c81c FUN_c082c81c */

/* Boundary evidence: original MIPS .pdata c082c81c..c082ca1b. Semantic name remains unreviewed. */

int FUN_c082c81c(int param_1)

{
  int local_38;
  code *local_30;
  undefined1 local_2c;
  undefined1 local_2b;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  code *local_1c;
  uint local_18;
  int *local_14;
  
  local_14 = (int *)0x0;
  local_14 = FUN_c08246fc(0xdc);
  if (local_14 == (int *)0x0) {
    local_38 = 7;
  }
  else {
    *local_14 = param_1;
    local_38 = FUN_c082a970(local_14,local_14 + 0x1e,(ushort *)(local_14 + 0x32),local_14 + 1);
    if (local_38 == 0) {
      FUN_c0827be4(&local_30,0,0x1c);
      local_30 = FUN_c082b79c;
      local_24 = 1;
      local_20 = 0;
      if ((*(ushort *)(local_14 + 0x32) & 0x10) == 0) {
        local_28 = 1;
      }
      if ((*(ushort *)(local_14 + 0x32) & 2) == 0) {
        local_2c = 2;
        if ((*(ushort *)(local_14 + 0x32) & 8) == 0) {
          local_2b = 1;
        }
        else {
          local_2b = 0xff;
        }
      }
      if ((*(ushort *)(local_14 + 0x32) & 4) == 0) {
        local_1c = FUN_c082ca1c;
      }
      local_18 = (uint)((*(ushort *)(local_14 + 0x32) & 1) != 0);
      local_38 = FUN_c08344b8(local_14,&local_30);
      if ((local_38 == 0) && (local_38 = FUN_c08356f8(local_14), local_38 == 0)) {
        return 0;
      }
    }
  }
  if (local_14 != (int *)0x0) {
    FUN_c0834468((int)local_14);
    FUN_c0824790(local_14);
  }
  return local_38;
}



/* c082ca1c FUN_c082ca1c */

/* Boundary evidence: original MIPS .pdata c082ca1c..c082cbeb. Semantic name remains unreviewed. */

undefined4 FUN_c082ca1c(int *param_1,undefined1 *param_2,int param_3)

{
  ushort uVar1;
  char cVar2;
  char local_2c;
  
  uVar1 = *(ushort *)(param_1 + 0x36);
  if (param_2 != (undefined1 *)0x0) {
    cVar2 = FUN_c0831540(*param_1);
    local_2c = cVar2;
    if (param_3 == 0) {
      local_2c = cVar2 + '\x01';
    }
    *param_2 = 5;
    param_2[1] = 0x24;
    param_2[2] = 0;
    param_2[3] = 0x10;
    param_2[4] = 1;
    param_2[5] = 4;
    param_2[6] = 0x24;
    param_2[7] = 2;
    param_2[8] = (byte)uVar1 & 0xf;
    param_2[9] = 5;
    param_2[10] = 0x24;
    param_2[0xb] = 1;
    param_2[0xc] = (char)((uVar1 & 0x30) >> 4);
    param_2[0xd] = local_2c;
    param_2[0xe] = 5;
    param_2[0xf] = 0x24;
    param_2[0x10] = 6;
    param_2[0x11] = cVar2;
    param_2[0x12] = local_2c;
  }
  return 0x13;
}



/* c082cbec FUN_c082cbec */

/* Boundary evidence: original MIPS .pdata c082cbec..c082cc5b. Semantic name remains unreviewed. */

undefined4 FUN_c082cbec(int param_1,ushort param_2)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = FUN_c0829eb8(param_1);
  uVar2 = FUN_c082431c(*(int *)(iVar1 + 8),0x800);
  FUN_c08243a8(*(int *)(iVar1 + 8),0x800,uVar2 | (uint)param_2 << 4);
  return 0;
}



/* c082cc5c FUN_c082cc5c */

/* Boundary evidence: original MIPS .pdata c082cc5c..c082cd37. Semantic name remains unreviewed. */

undefined4 FUN_c082cc5c(int param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  undefined4 local_10;
  
  iVar1 = FUN_c0829eb8(param_1);
  FUN_c0825c4c(param_1);
  iVar2 = FUN_c08243d4();
  if (iVar2 == 0) {
    uVar3 = FUN_c082431c(*(int *)(iVar1 + 8),0x804);
    FUN_c08243a8(*(int *)(iVar1 + 8),0x804,uVar3 | 1);
    FUN_c0826450(10);
    uVar3 = FUN_c082431c(*(int *)(iVar1 + 8),0x804);
    FUN_c08243a8(*(int *)(iVar1 + 8),0x804,uVar3 & 0xfffffffe);
    local_10 = 0;
  }
  else {
    local_10 = 3;
  }
  return local_10;
}



/* c082cd38 FUN_c082cd38 */

/* Boundary evidence: original MIPS .pdata c082cd38..c082cda7. Semantic name remains unreviewed. */

undefined4 FUN_c082cd38(int param_1)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = FUN_c0829eb8(param_1);
  uVar2 = FUN_c082431c(*(int *)(iVar1 + 8),0x804);
  FUN_c08243a8(*(int *)(iVar1 + 8),0x804,uVar2 | 2);
  FUN_c0826450(2);
  return 0;
}



/* c082cda8 FUN_c082cda8 */

/* Boundary evidence: original MIPS .pdata c082cda8..c082ce13. Semantic name remains unreviewed. */

undefined4 FUN_c082cda8(int param_1)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = FUN_c0829eb8(param_1);
  uVar2 = FUN_c082431c(*(int *)(iVar1 + 8),0x804);
  FUN_c08243a8(*(int *)(iVar1 + 8),0x804,uVar2 & 0xfffffffd);
  return 0;
}



/* c082ce14 FUN_c082ce14 */

/* Boundary evidence: original MIPS .pdata c082ce14..c082cfcb. Semantic name remains unreviewed. */

undefined4 FUN_c082ce14(int param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  int *piVar3;
  uint uVar4;
  uint uVar5;
  
  iVar1 = FUN_c0829eb8(param_1);
  piVar3 = (int *)(iVar1 + 0x30 + *(uint *)(param_2 + 0x20) * 0x2c);
  uVar4 = *(uint *)(param_2 + 0x20) >> 1;
  *(char *)(piVar3 + 1) = (char)*(undefined4 *)(param_2 + 4);
  piVar3[7] = param_2;
  *(undefined2 *)(piVar3 + 3) = *(undefined2 *)(param_2 + 0x24);
  *(undefined4 *)(piVar3[7] + 0x28) = 1;
  piVar3[2] = 1;
  uVar5 = (uint)*(ushort *)(param_2 + 0x24) | (uint)*(byte *)(piVar3 + 1) << 0x12;
  if (*piVar3 == 0) {
    uVar2 = FUN_c082431c(*(int *)(iVar1 + 8),0x818);
    FUN_c08243a8(*(int *)(iVar1 + 8),0x818,uVar2 | 1 << (uVar4 + 0x10 & 0x1f));
    FUN_c08243a8(*(int *)(iVar1 + 8),uVar4 * 0x20 + 0xb00,uVar5 | 0x18008000);
  }
  else {
    FUN_c08243a8(*(int *)(iVar1 + 8),uVar4 * 0x20 + 0x900,uVar5 | uVar4 << 0x16 | 0x18008000);
  }
  return 0;
}



/* c082cfcc FUN_c082cfcc */

/* Boundary evidence: original MIPS .pdata c082cfcc..c082d183. Semantic name remains unreviewed. */

undefined4 FUN_c082cfcc(int param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  int *piVar3;
  uint uVar4;
  undefined4 local_10;
  uint local_c;
  
  iVar1 = FUN_c0829eb8(param_1);
  piVar3 = (int *)(iVar1 + 0x30 + *(uint *)(param_2 + 0x20) * 0x2c);
  if (piVar3[2] == 0) {
    local_10 = 8;
  }
  else if ((*(int *)(param_2 + 0x28) == 1) || (*(int *)(param_2 + 0x28) == 3)) {
    uVar4 = *(uint *)(param_2 + 0x20) >> 1;
    uVar2 = uVar4;
    if (*piVar3 != 0) {
      uVar2 = uVar4 + 0x10;
    }
    local_c = 1 << (uVar2 & 0x1f);
    uVar2 = FUN_c082431c(*(int *)(iVar1 + 8),0x818);
    FUN_c08243a8(*(int *)(iVar1 + 8),0x818,uVar2 & ~local_c);
    if (*piVar3 == 0) {
      FUN_c08243a8(*(int *)(iVar1 + 8),uVar4 * 0x20 + 0xb00,0);
    }
    else {
      FUN_c08243a8(*(int *)(iVar1 + 8),uVar4 * 0x20 + 0x900,0);
    }
    *(undefined4 *)(param_2 + 0x28) = 2;
    piVar3[2] = 0;
    local_10 = 0;
  }
  else {
    local_10 = 0x10;
  }
  return local_10;
}



/* c082d184 FUN_c082d184 */

/* Boundary evidence: original MIPS .pdata c082d184..c082d25f. Semantic name remains unreviewed. */

undefined4 FUN_c082d184(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  uint local_20;
  uint local_10;
  
  iVar1 = FUN_c0829eb8(param_1);
  if (param_2 == 0) {
    local_10 = (uint)(*(int *)(iVar1 + 0x44) == 0);
    local_20 = local_10;
  }
  else {
    local_20 = *(uint *)(param_2 + 0x20);
  }
  iVar2 = iVar1 + 0x30 + local_20 * 0x2c;
  if ((iVar2 != 0) && (*(int *)(iVar2 + 0x14) != 0)) {
    FUN_c082d260(iVar1,local_20);
  }
  return 0;
}



/* c082d260 FUN_c082d260 */

/* Boundary evidence: original MIPS .pdata c082d260..c082d43b. Semantic name remains unreviewed. */

void FUN_c082d260(int param_1,uint param_2)

{
  bool bVar1;
  uint uVar2;
  int *piVar3;
  int iVar4;
  uint uVar5;
  int local_10;
  
  piVar3 = (int *)(param_1 + 0x30 + param_2 * 0x2c);
  iVar4 = piVar3[5];
  uVar5 = param_2 >> 1;
  if (*piVar3 == 0) {
    local_10 = 1000;
    uVar2 = FUN_c082431c(*(int *)(param_1 + 8),0x804);
    FUN_c08243a8(*(int *)(param_1 + 8),0x804,uVar2 | 0x200);
    do {
      uVar2 = FUN_c082431c(*(int *)(param_1 + 8),0x14);
      if ((uVar2 & 0x80) != 0) break;
      bVar1 = local_10 != 0;
      local_10 = local_10 + -1;
    } while (bVar1);
    uVar2 = FUN_c082431c(*(int *)(param_1 + 8),uVar5 * 0x20 + 0xb00);
    FUN_c08243a8(*(int *)(param_1 + 8),uVar5 * 0x20 + 0xb00,uVar2 | 0x48000000);
  }
  else {
    uVar2 = FUN_c082431c(*(int *)(param_1 + 8),uVar5 * 0x20 + 0x900);
    if ((uVar2 & 0x80000000) == 0) {
      FUN_c082d43c(param_1,uVar5);
    }
    else {
      FUN_c08243a8(*(int *)(param_1 + 8),uVar5 * 0x20 + 0x900,uVar2 | 0x48000000);
    }
  }
  if (iVar4 != 0) {
    *(undefined4 *)(iVar4 + 0x18) = 2;
    piVar3[5] = 0;
    FUN_c08309c0(*(int *)(param_1 + 4),iVar4);
  }
  return;
}



/* c082d43c FUN_c082d43c */

/* Boundary evidence: original MIPS .pdata c082d43c..c082d4af. Semantic name remains unreviewed. */

void FUN_c082d43c(int param_1,int param_2)

{
  uint uVar1;
  
  FUN_c08243a8(*(int *)(param_1 + 8),0x10,param_2 << 6 | 0x20);
  do {
    uVar1 = FUN_c082431c(*(int *)(param_1 + 8),0x10);
  } while ((uVar1 & 0x20) != 0);
  return;
}



/* c082d4b0 FUN_c082d4b0 */

/* Boundary evidence: original MIPS .pdata c082d4b0..c082d61f. Semantic name remains unreviewed. */

undefined4 FUN_c082d4b0(int param_1,int param_2,int param_3)

{
  int iVar1;
  int *piVar2;
  uint local_28;
  int local_20;
  uint local_10;
  
  iVar1 = FUN_c0829eb8(param_1);
  if (param_2 == 0) {
    local_10 = 0;
  }
  else {
    local_10 = *(uint *)(param_2 + 0x20);
  }
  piVar2 = (int *)(iVar1 + 0x30 + local_10 * 0x2c);
  if (*piVar2 == 0) {
    local_20 = (local_10 >> 1) * 0x20 + 0xb00;
  }
  else {
    local_20 = (local_10 >> 1) * 0x20 + 0x900;
  }
  local_28 = FUN_c082431c(*(int *)(iVar1 + 8),local_20);
  if (param_2 != 0) {
    piVar2[6] = param_3;
  }
  if (param_3 == 0) {
    local_28 = local_28 & 0xffdfffff | 0x10000000;
  }
  else {
    local_28 = local_28 | 0x200000;
  }
  FUN_c08243a8(*(int *)(iVar1 + 8),local_20,local_28);
  return 0;
}



/* c082d620 FUN_c082d620 */

/* Boundary evidence: original MIPS .pdata c082d620..c082d6b7. Semantic name remains unreviewed. */

undefined4 FUN_c082d620(int param_1,int param_2)

{
  int iVar1;
  undefined4 local_c;
  
  iVar1 = FUN_c0829eb8(param_1);
  iVar1 = iVar1 + 0x30 + *(int *)(param_2 + 0x20) * 0x2c;
  if (*(int *)(iVar1 + 8) == 0) {
    *(undefined2 *)(iVar1 + 0xe) = 0;
    *(undefined2 *)(iVar1 + 0x10) = 0;
    local_c = 0;
  }
  else {
    local_c = 8;
  }
  return local_c;
}



/* c082d6b8 FUN_c082d6b8 */

/* Boundary evidence: original MIPS .pdata c082d6b8..c082d93f. Semantic name remains unreviewed. */

undefined4 FUN_c082d6b8(int param_1,int param_2,char param_3,char param_4)

{
  bool bVar1;
  byte bVar2;
  int iVar3;
  uint uVar4;
  uint local_2c;
  int local_28;
  undefined4 local_1c;
  uint local_14;
  uint local_10;
  
  iVar3 = FUN_c0829eb8(param_1);
  bVar1 = *(char *)(param_2 + 8) != '\0';
  local_28 = 0;
  if (bVar1) {
    local_14 = 3;
  }
  else {
    local_14 = 2;
  }
  local_2c = local_14;
  if (bVar1) {
    bVar2 = *(byte *)(iVar3 + 0x5b1);
  }
  else {
    bVar2 = *(byte *)(iVar3 + 0x5b0);
  }
  local_10 = (uint)bVar2;
  local_14 = local_14 + (local_10 - 1) * 2;
  while (((int)local_2c < (int)local_14 &&
         ((local_28 = iVar3 + 0x30 + local_2c * 0x2c, *(int *)(local_28 + 0x20) == 0 ||
          (((*(short *)(local_28 + 0xe) != 0 &&
            ((*(ushort *)(local_28 + 0xe) != (ushort)(byte)(param_3 + 1U) ||
             (*(ushort *)(local_28 + 0x10) == (ushort)(byte)(param_4 + 1U))))) ||
           (*(ushort *)(local_28 + 0xc) < *(ushort *)(param_2 + 2)))))))) {
    local_2c = local_2c + 2;
  }
  if (local_2c == local_14) {
    local_1c = 10;
  }
  else {
    *(ushort *)(local_28 + 0xe) = (ushort)(byte)(param_3 + 1U);
    *(ushort *)(local_28 + 0x10) = (ushort)(byte)(param_4 + 1U);
    uVar4 = local_2c;
    if ((int)local_2c < 0) {
      uVar4 = local_2c + 1;
    }
    *(char *)(param_2 + 0xb) = (char)((int)uVar4 >> 1);
    if ((local_2c & 1) == 0) {
      bVar2 = 0x80;
    }
    else {
      bVar2 = 0;
    }
    *(byte *)(param_2 + 0xb) = *(byte *)(param_2 + 0xb) | bVar2;
    *(uint *)(param_2 + 0x20) = local_2c;
    local_1c = 0;
  }
  return local_1c;
}



/* c082d940 FUN_c082d940 */

/* Boundary evidence: original MIPS .pdata c082d940..c082da8f. Semantic name remains unreviewed. */

undefined4 FUN_c082d940(int param_1,int param_2,int param_3)

{
  int iVar1;
  uint local_20;
  uint local_10;
  
  iVar1 = FUN_c0829eb8(param_1);
  if (param_2 == 0) {
    local_10 = (uint)(*(char *)(param_3 + 1) == '\x01');
    local_20 = local_10;
  }
  else {
    local_20 = *(uint *)(param_2 + 0x20);
  }
  *(int *)(iVar1 + local_20 * 0x2c + 0x44) = param_3;
  if (*(char *)(iVar1 + local_20 * 0x2c + 0x34) == '\x01') {
    FUN_c082da90(iVar1,local_20);
  }
  else if (*(char *)(param_3 + 1) == '\0') {
    FUN_c082db34(iVar1,local_20);
  }
  else {
    FUN_c082dddc(iVar1,local_20);
  }
  return 0;
}



/* c082da90 FUN_c082da90 */

/* Boundary evidence: original MIPS .pdata c082da90..c082db33. Semantic name remains unreviewed. */

void FUN_c082da90(int param_1,int param_2)

{
  uint uVar1;
  
  *(undefined4 *)(param_1 + param_2 * 0x2c + 0x54) = 1;
  *(undefined4 *)(param_1 + param_2 * 0x2c + 0x58) = 0;
  *(uint *)(param_1 + 0x5b8) = *(uint *)(param_1 + 0x5b8) | 0x8000;
  uVar1 = FUN_c082431c(*(int *)(param_1 + 8),0x18);
  FUN_c08243a8(*(int *)(param_1 + 8),0x18,uVar1 | 0x8000);
  return;
}



/* c082db34 FUN_c082db34 */

/* Boundary evidence: original MIPS .pdata c082db34..c082dd0f. Semantic name remains unreviewed. */

void FUN_c082db34(int param_1,uint param_2)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  undefined4 local_1c;
  undefined4 local_10;
  
  iVar3 = *(int *)(param_1 + param_2 * 0x2c + 0x44);
  uVar4 = param_2 >> 1;
  iVar1 = FUN_c082dd10(param_1,param_2);
  local_1c = *(uint *)(iVar3 + 0x1c);
  if (uVar4 == 0) {
    if ((uint)(*(int *)(iVar3 + 0x1c) - *(int *)(iVar3 + 0x20)) < 0x40) {
      local_10 = *(int *)(iVar3 + 0x1c) - *(int *)(iVar3 + 0x20);
    }
    else {
      local_10 = 0x40;
    }
    local_1c = local_10;
  }
  FUN_c08243a8(*(int *)(param_1 + 8),uVar4 * 0x20 + 0x914,
               *(int *)(*(int *)(iVar3 + 4) + 4) + *(int *)(iVar3 + 0x20));
  FUN_c08243a8(*(int *)(param_1 + 8),uVar4 * 0x20 + 0x910,local_1c | iVar1 << 0x13);
  uVar2 = FUN_c082431c(*(int *)(param_1 + 8),uVar4 * 0x20 + 0x900);
  FUN_c08243a8(*(int *)(param_1 + 8),uVar4 * 0x20 + 0x900,uVar2 | 0x84000000);
  uVar2 = FUN_c082431c(*(int *)(param_1 + 8),0x81c);
  FUN_c08243a8(*(int *)(param_1 + 8),0x81c,uVar2 | 1 << (uVar4 & 0x1f));
  uVar4 = FUN_c082431c(*(int *)(param_1 + 8),0x18);
  FUN_c08243a8(*(int *)(param_1 + 8),0x18,uVar4 | 0x40000);
  return;
}



/* c082dd10 FUN_c082dd10 */

/* Boundary evidence: original MIPS .pdata c082dd10..c082dddb. Semantic name remains unreviewed. */

int FUN_c082dd10(int param_1,uint param_2)

{
  int iVar1;
  uint uVar2;
  undefined4 local_14;
  
  iVar1 = *(int *)(param_1 + param_2 * 0x2c + 0x44);
  local_14 = 1;
  if ((param_2 >> 1 != 0) &&
     (uVar2 = (uint)*(ushort *)(*(int *)(param_1 + param_2 * 0x2c + 0x4c) + 0x24),
     *(int *)(iVar1 + 0x1c) != 0)) {
    if (uVar2 == 0) {
      trap(0x1c00);
    }
    local_14 = (*(int *)(iVar1 + 0x1c) - 1U) / uVar2 + 1;
  }
  return local_14;
}



/* c082dddc FUN_c082dddc */

/* Boundary evidence: original MIPS .pdata c082dddc..c082dfbb. Semantic name remains unreviewed. */

void FUN_c082dddc(int param_1,uint param_2)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  undefined4 local_1c;
  undefined4 local_10;
  
  iVar3 = *(int *)(param_1 + param_2 * 0x2c + 0x44);
  uVar4 = param_2 >> 1;
  iVar1 = FUN_c082dd10(param_1,param_2);
  local_1c = *(uint *)(iVar3 + 0x1c);
  if (uVar4 == 0) {
    if ((uint)(*(int *)(iVar3 + 0x1c) - *(int *)(iVar3 + 0x20)) < 0x40) {
      local_10 = *(int *)(iVar3 + 0x1c) - *(int *)(iVar3 + 0x20);
    }
    else {
      local_10 = 0x40;
    }
    local_1c = local_10;
  }
  FUN_c08243a8(*(int *)(param_1 + 8),uVar4 * 0x20 + 0xb14,
               *(int *)(*(int *)(iVar3 + 4) + 4) + *(int *)(iVar3 + 0x20));
  FUN_c08243a8(*(int *)(param_1 + 8),uVar4 * 0x20 + 0xb10,local_1c | iVar1 << 0x13);
  uVar2 = FUN_c082431c(*(int *)(param_1 + 8),uVar4 * 0x20 + 0xb00);
  FUN_c08243a8(*(int *)(param_1 + 8),uVar4 * 0x20 + 0xb00,uVar2 | 0x84000000);
  uVar2 = FUN_c082431c(*(int *)(param_1 + 8),0x81c);
  FUN_c08243a8(*(int *)(param_1 + 8),0x81c,uVar2 | 1 << (uVar4 + 0x10 & 0x1f));
  uVar4 = FUN_c082431c(*(int *)(param_1 + 8),0x18);
  FUN_c08243a8(*(int *)(param_1 + 8),0x18,uVar4 | 0x80000);
  return;
}



/* c082dfbc FUN_c082dfbc */

/* Boundary evidence: original MIPS .pdata c082dfbc..c082e063. Semantic name remains unreviewed. */

undefined4 FUN_c082dfbc(int param_1,undefined1 *param_2,byte param_3)

{
  int iVar1;
  uint local_c;
  
  iVar1 = FUN_c0829eb8(param_1);
  local_c = (uint)((int)(uint)param_3 >> 7 == 0);
  *param_2 = (char)*(undefined4 *)(iVar1 + ((param_3 & 0xf) * 2 + local_c) * 0x2c + 0x48);
  return 0;
}



/* c082e064 FUN_c082e064 */

/* Boundary evidence: original MIPS .pdata c082e064..c082e087. Semantic name remains unreviewed. */

undefined4 FUN_c082e064(void)

{
  return 0;
}



/* c082e088 FUN_c082e088 */

/* Boundary evidence: original MIPS .pdata c082e088..c082e163. Semantic name remains unreviewed. */

undefined4 FUN_c082e088(int param_1,short param_2,ushort param_3,byte param_4)

{
  int *piVar1;
  undefined4 local_20;
  uint local_10;
  
  piVar1 = (int *)FUN_c0829eb8(param_1);
  local_20 = 0xb;
  if (param_2 == 0) {
    local_10 = (uint)((param_3 & 0x80) == 0);
    local_20 = FUN_c082d4b0(*piVar1,piVar1[(local_10 + (param_3 & 0x7f) * 2) * 0xb + 0x13],
                            (uint)param_4);
  }
  return local_20;
}



/* c082e164 FUN_c082e164 */

/* Boundary evidence: original MIPS .pdata c082e164..c082e183. Semantic name remains unreviewed. */

undefined1 FUN_c082e164(void)

{
  return 0x40;
}



/* c082e184 FUN_c082e184 */

/* Boundary evidence: original MIPS .pdata c082e184..c082e1a3. Semantic name remains unreviewed. */

undefined1 FUN_c082e184(void)

{
  return 2;
}



/* c082e1a4 FUN_c082e1a4 */

/* Boundary evidence: original MIPS .pdata c082e1a4..c082e34b. Semantic name remains unreviewed. */

int FUN_c082e1a4(int param_1)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  
  iVar1 = FUN_c0829eb8(param_1);
  uVar2 = FUN_c082431c(*(int *)(iVar1 + 8),8);
  FUN_c08243a8(*(int *)(iVar1 + 8),8,uVar2 | 0xa1);
  uVar2 = FUN_c082431c(*(int *)(iVar1 + 8),0xc);
  FUN_c08243a8(*(int *)(iVar1 + 8),0xc,uVar2 & 0xffffebff | 0x2408);
  FUN_c08243a8(*(int *)(iVar1 + 8),0x14,0xffffffff);
  iVar3 = FUN_c0835aa4(*(int **)(iVar1 + 0xc),-0x3f7d1cb4,iVar1,FUN_c082e8cc,iVar1,
                       (undefined4 *)(iVar1 + 0x10));
  if (iVar3 == 0) {
    *(undefined4 *)(iVar1 + 0x14) = 0;
    *(undefined4 *)(iVar1 + 0x5b8) = 0x800c3800;
    FUN_c08243a8(*(int *)(iVar1 + 8),0x18,*(undefined4 *)(iVar1 + 0x5b8));
    *(undefined4 *)(iVar1 + 0x5c0) = 0xffffffff;
    FUN_c08243a8(*(int *)(iVar1 + 8),0x81c,*(undefined4 *)(iVar1 + 0x5c0));
  }
  return iVar3;
}



/* c082e34c FUN_c082e34c */

/* Boundary evidence: original MIPS .pdata c082e34c..c082e637. Semantic name remains unreviewed. */

undefined4 FUN_c082e34c(int param_1)

{
  uint uVar1;
  uint local_20;
  undefined4 local_18;
  
  uVar1 = FUN_c082431c(*(int *)(param_1 + 8),0x14);
  *(uint *)(param_1 + 0x5b4) = *(uint *)(param_1 + 0x5b4) | *(uint *)(param_1 + 0x5b8) & uVar1;
  uVar1 = FUN_c082431c(*(int *)(param_1 + 8),0x818);
  *(uint *)(param_1 + 0x5bc) = *(uint *)(param_1 + 0x5bc) | uVar1;
  if (*(int *)(param_1 + 0x5b4) == 0) {
    local_18 = 0;
  }
  else {
    if ((*(uint *)(param_1 + 0x5b4) & 0x8000) != 0) {
      for (local_20 = 1; (int)local_20 < (int)(uint)*(byte *)(param_1 + 0x5b0);
          local_20 = local_20 + 1) {
        if (*(int *)(param_1 + local_20 * 0x58 + 0x54) == 0) {
          if (*(int *)(param_1 + local_20 * 0x58 + 0x58) != 0) {
            FUN_c082f990(param_1,local_20);
          }
        }
        else {
          FUN_c082fb60(param_1,local_20);
        }
      }
      *(uint *)(param_1 + 0x5b4) = *(uint *)(param_1 + 0x5b4) & 0xffff7fff;
      FUN_c08243a8(*(int *)(param_1 + 8),0x14,0x8000);
    }
    if ((*(uint *)(param_1 + 0x5b4) & 0x40000) != 0) {
      for (local_20 = 1; (int)local_20 < (int)(uint)*(byte *)(param_1 + 0x5b0);
          local_20 = local_20 + 1) {
        if ((*(char *)(param_1 + local_20 * 0x58 + 0x34) == '\x01') &&
           ((*(uint *)(param_1 + 0x5bc) & 1 << (local_20 & 0x1f)) != 0)) {
          FUN_c082e638(param_1,local_20);
        }
      }
    }
    uVar1 = FUN_c082431c(*(int *)(param_1 + 8),0x18);
    FUN_c08243a8(*(int *)(param_1 + 8),0x18,uVar1 & ~*(uint *)(param_1 + 0x5b4));
    FUN_c08243a8(*(int *)(param_1 + 8),0x81c,
                 *(uint *)(param_1 + 0x5c0) & ~*(uint *)(param_1 + 0x5bc));
    local_18 = 1;
  }
  return local_18;
}



/* c082e638 FUN_c082e638 */

/* Boundary evidence: original MIPS .pdata c082e638..c082e8cb. Semantic name remains unreviewed. */

void FUN_c082e638(int param_1,uint param_2)

{
  uint uVar1;
  int iVar2;
  undefined4 local_c;
  
  uVar1 = FUN_c082431c(*(int *)(param_1 + 8),param_2 * 0x20 + 0x908);
  iVar2 = *(int *)(param_1 + param_2 * 0x58 + 0x44);
  if ((uVar1 & 1) == 0) {
    if ((uVar1 & 2) != 0) {
      FUN_c082d43c(param_1,param_2);
      *(undefined4 *)(param_1 + param_2 * 0x58 + 0x58) = 0;
      *(uint *)(param_1 + 0x5bc) = *(uint *)(param_1 + 0x5bc) & ~(1 << (param_2 & 0x1f));
      FUN_c08243a8(*(int *)(param_1 + 8),param_2 * 0x20 + 0x908,2);
    }
  }
  else {
    FUN_c08243a8(*(int *)(param_1 + 8),param_2 * 0x20 + 0x908,1);
    uVar1 = FUN_c082431c(*(int *)(param_1 + 8),param_2 * 0x20 + 0x910);
    if ((uint)(*(int *)(iVar2 + 0x1c) - *(int *)(iVar2 + 0x20)) <
        (uint)*(ushort *)(*(int *)(param_1 + param_2 * 0x58 + 0x4c) + 0x24)) {
      local_c = *(int *)(iVar2 + 0x1c) - *(int *)(iVar2 + 0x20);
    }
    else {
      local_c = (uint)*(ushort *)(*(int *)(param_1 + param_2 * 0x58 + 0x4c) + 0x24);
    }
    *(uint *)(iVar2 + 0x20) = *(int *)(iVar2 + 0x20) + (local_c - (uVar1 & 0x7ffff));
    if ((*(uint *)(iVar2 + 0x20) < *(uint *)(iVar2 + 0x1c)) && ((uVar1 & 0x7ffff) == 0)) {
      *(uint *)(param_1 + 0x5bc) = *(uint *)(param_1 + 0x5bc) & ~(1 << (param_2 & 0x1f));
      FUN_c082fb60(param_1,param_2);
    }
    else {
      *(undefined4 *)(param_1 + param_2 * 0x58 + 0x58) = 0;
    }
  }
  return;
}



/* c082e8cc FUN_c082e8cc */

/* Boundary evidence: original MIPS .pdata c082e8cc..c082ebff. Semantic name remains unreviewed. */

void FUN_c082e8cc(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  uint uVar1;
  uint uVar2;
  uint local_18;
  uint local_14;
  
  local_14 = 0;
  FUN_c0827914();
  uVar1 = param_1[0x16d] & param_1[0x16e];
  uVar2 = param_1[0x16f];
  param_1[0x16f] = 0;
  param_1[0x16d] = 0;
  FUN_c0827940();
  if (uVar1 != 0) {
    if ((uVar1 & 0x800) != 0) {
      FUN_c0830798((int)param_1);
      local_14 = 0x800;
    }
    if ((uVar1 & 0x80000000) != 0) {
      FUN_c08307e8((int)param_1);
      local_14 = local_14 | 0x80000000;
    }
    if ((uVar1 & 0x1000) != 0) {
      FUN_c08307e8((int)param_1);
      FUN_c082ec00((int)param_1,param_2,param_3,param_4);
      local_14 = local_14 | 0x1000;
    }
    if ((uVar1 & 0x2000) != 0) {
      FUN_c082ee94((int)param_1);
      local_14 = local_14 | 0x2000;
    }
    if ((uVar1 & 0x80000) != 0) {
      if ((uVar2 & 0x10000) != 0) {
        FUN_c082f580(param_1,param_2,param_3,param_4);
      }
      for (local_18 = 1; (int)local_18 < (int)(uint)*(byte *)((int)param_1 + 0x5b1);
          local_18 = local_18 + 1) {
        if ((uVar2 & 1 << (local_18 + 0x10 & 0x1f)) != 0) {
          FUN_c082f800((int)param_1,local_18);
        }
      }
      local_14 = local_14 | 0x80000;
    }
    if ((uVar1 & 0x40000) != 0) {
      if ((uVar2 & 1) != 0) {
        FUN_c082ef04((int)param_1);
      }
      for (local_18 = 1; (int)local_18 < (int)(uint)*(byte *)(param_1 + 0x16c);
          local_18 = local_18 + 1) {
        if ((uVar2 & 1 << (local_18 & 0x1f)) != 0) {
          if ((char)param_1[local_18 * 0x16 + 0xd] == '\x01') {
            FUN_c082f3a8((int)param_1,local_18);
          }
          else {
            FUN_c082f41c((int)param_1,local_18);
          }
        }
      }
      local_14 = local_14 | 0x40000;
    }
    FUN_c08243a8(param_1[2],0x14,local_14);
    uVar1 = FUN_c082431c(param_1[2],0x18);
    FUN_c08243a8(param_1[2],0x18,uVar1 | param_1[0x16e] & local_14);
  }
  return;
}



/* c082ec00 FUN_c082ec00 */

/* Boundary evidence: original MIPS .pdata c082ec00..c082ed9f. Semantic name remains unreviewed. */

void FUN_c082ec00(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  uint uVar1;
  undefined1 local_10;
  
  FUN_c0831ba0(*(int *)(param_1 + 4),param_2,param_3,param_4);
  *(undefined4 *)(param_1 + 0x48) = 0;
  *(undefined4 *)(param_1 + 0x74) = 0;
  *(undefined4 *)(param_1 + 0x5c0) = 0xffffffff;
  FUN_c08243a8(*(int *)(param_1 + 8),0x81c,*(undefined4 *)(param_1 + 0x5c0));
  FUN_c08243a8(*(int *)(param_1 + 8),0x814,0xb);
  FUN_c08243a8(*(int *)(param_1 + 8),0x810,3);
  uVar1 = FUN_c082431c(*(int *)(param_1 + 8),0x800);
  FUN_c08243a8(*(int *)(param_1 + 8),0x800,uVar1 & 0xfffff80f);
  FUN_c08243a8(*(int *)(param_1 + 8),0x24,0x200);
  FUN_c08243a8(*(int *)(param_1 + 8),0x28,0x1000200);
  for (local_10 = 1; local_10 < *(byte *)(param_1 + 0x5b0); local_10 = local_10 + 1) {
    FUN_c08243a8(*(int *)(param_1 + 8),(local_10 - 1) * 4 + 0x104,
                 (uint)local_10 * 0x100 + 0x200 | 0x1000000);
  }
  FUN_c082d43c(param_1,0x10);
  FUN_c082eda0(param_1);
  FUN_c082ee08(param_1);
  return;
}



/* c082eda0 FUN_c082eda0 */

/* Boundary evidence: original MIPS .pdata c082eda0..c082ee07. Semantic name remains unreviewed. */

void FUN_c082eda0(int param_1)

{
  uint uVar1;
  
  FUN_c08243a8(*(int *)(param_1 + 8),0x10,0x10);
  do {
    uVar1 = FUN_c082431c(*(int *)(param_1 + 8),0x10);
  } while ((uVar1 & 0x10) != 0);
  return;
}



/* c082ee08 FUN_c082ee08 */

/* Boundary evidence: original MIPS .pdata c082ee08..c082ee93. Semantic name remains unreviewed. */

void FUN_c082ee08(int param_1)

{
  uint uVar1;
  
  FUN_c08243a8(*(int *)(param_1 + 8),0xb10,0x60080018);
  FUN_c08243a8(*(int *)(param_1 + 8),0xb14,*(undefined4 *)(param_1 + 0x1c));
  uVar1 = FUN_c082431c(*(int *)(param_1 + 8),0xb00);
  FUN_c08243a8(*(int *)(param_1 + 8),0xb00,uVar1 | 0x84000000);
  return;
}



/* c082ee94 FUN_c082ee94 */

/* Boundary evidence: original MIPS .pdata c082ee94..c082ef03. Semantic name remains unreviewed. */

void FUN_c082ee94(int param_1)

{
  uint uVar1;
  
  uVar1 = FUN_c082431c(*(int *)(param_1 + 8),0x808);
  if ((uVar1 & 2) == 0) {
    *(undefined4 *)(param_1 + 0x28) = 3;
  }
  else {
    *(undefined4 *)(param_1 + 0x28) = 2;
  }
  return;
}



/* c082ef04 FUN_c082ef04 */

/* Boundary evidence: original MIPS .pdata c082ef04..c082f127. Semantic name remains unreviewed. */

void FUN_c082ef04(int param_1)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int local_10;
  
  uVar1 = FUN_c082431c(*(int *)(param_1 + 8),0x908);
  iVar3 = *(int *)(param_1 + 0x44);
  if (iVar3 != 0) {
    if ((uVar1 & 1) != 0) {
      if (*(int *)(iVar3 + 0x1c) == 0) {
        FUN_c08243a8(*(int *)(param_1 + 8),0x908,1);
        FUN_c082ee08(param_1);
        FUN_c082f128(param_1,0);
        return;
      }
      FUN_c08243a8(*(int *)(param_1 + 8),0x908,1);
      uVar2 = FUN_c082431c(*(int *)(param_1 + 8),0x910);
      if ((uint)(*(int *)(iVar3 + 0x1c) - *(int *)(iVar3 + 0x20)) < 0x40) {
        local_10 = *(int *)(iVar3 + 0x1c) - *(int *)(iVar3 + 0x20);
      }
      else {
        local_10 = 0x40;
      }
      *(uint *)(iVar3 + 0x20) = *(int *)(iVar3 + 0x20) + (local_10 - (uVar2 & 0x7ffff));
      if ((*(uint *)(iVar3 + 0x20) < *(uint *)(iVar3 + 0x1c)) && ((uVar2 & 0x7ffff) == 0)) {
        FUN_c082db34(param_1,0);
      }
      else {
        FUN_c08243a8(*(int *)(param_1 + 8),0xb10,0x80000);
        uVar2 = FUN_c082431c(*(int *)(param_1 + 8),0xb00);
        FUN_c08243a8(*(int *)(param_1 + 8),0xb00,uVar2 | 0x84000000);
        FUN_c082f128(param_1,0);
      }
    }
    if ((uVar1 & 8) != 0) {
      FUN_c08243a8(*(int *)(param_1 + 8),0x908,8);
    }
  }
  return;
}



/* c082f128 FUN_c082f128 */

/* Boundary evidence: original MIPS .pdata c082f128..c082f3a7. Semantic name remains unreviewed. */

void FUN_c082f128(int param_1,uint param_2)

{
  uint uVar1;
  int *piVar2;
  char *pcVar3;
  uint uVar4;
  
  piVar2 = (int *)(param_1 + 0x30 + param_2 * 0x2c);
  pcVar3 = (char *)piVar2[5];
  if ((*(int *)(pcVar3 + 0x1c) != 0) && (*pcVar3 != '\0')) {
    if (*(ushort *)(piVar2 + 3) == 0) {
      trap(0x1c00);
    }
    if (*(uint *)(pcVar3 + 0x20) % (uint)*(ushort *)(piVar2 + 3) == 0) {
      uVar4 = param_2 >> 1;
      if (*piVar2 == 0) {
        if (*(int *)(pcVar3 + 0x20) == *(int *)(pcVar3 + 0x1c)) {
          FUN_c08243a8(*(int *)(param_1 + 8),uVar4 * 0x20 + 0xb10,0x80000);
          uVar1 = FUN_c082431c(*(int *)(param_1 + 8),uVar4 * 0x20 + 0xb00);
          FUN_c08243a8(*(int *)(param_1 + 8),uVar4 * 0x20 + 0xb00,uVar1 | 0x84000000);
          uVar1 = FUN_c082431c(*(int *)(param_1 + 8),0x81c);
          FUN_c08243a8(*(int *)(param_1 + 8),0x81c,uVar1 | 1 << (uVar4 + 0x10 & 0x1f));
        }
      }
      else {
        FUN_c08243a8(*(int *)(param_1 + 8),uVar4 * 0x20 + 0x910,0x80000);
        uVar1 = FUN_c082431c(*(int *)(param_1 + 8),uVar4 * 0x20 + 0x900);
        FUN_c08243a8(*(int *)(param_1 + 8),uVar4 * 0x20 + 0x900,uVar1 | 0x84000000);
        uVar1 = FUN_c082431c(*(int *)(param_1 + 8),0x81c);
        FUN_c08243a8(*(int *)(param_1 + 8),0x81c,uVar1 | 1 << (uVar4 & 0x1f));
      }
      *pcVar3 = '\0';
      return;
    }
  }
  *(undefined4 *)(param_1 + param_2 * 0x2c + 0x44) = 0;
  if (*(int *)(pcVar3 + 0x18) != 2) {
    pcVar3[0x18] = '\x05';
    pcVar3[0x19] = '\0';
    pcVar3[0x1a] = '\0';
    pcVar3[0x1b] = '\0';
  }
  FUN_c08309c0(*(int *)(param_1 + 4),(int)pcVar3);
  return;
}



/* c082f3a8 FUN_c082f3a8 */

/* Boundary evidence: original MIPS .pdata c082f3a8..c082f41b. Semantic name remains unreviewed. */

void FUN_c082f3a8(int param_1,int param_2)

{
  if (*(int *)(param_1 + param_2 * 0x58 + 0x44) != 0) {
    FUN_c082f128(param_1,param_2 * 2);
  }
  return;
}



/* c082f41c FUN_c082f41c */

/* Boundary evidence: original MIPS .pdata c082f41c..c082f57f. Semantic name remains unreviewed. */

void FUN_c082f41c(int param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  
  uVar1 = FUN_c082431c(*(int *)(param_1 + 8),param_2 * 0x20 + 0x908);
  iVar3 = *(int *)(param_1 + param_2 * 0x58 + 0x44);
  if ((uVar1 & 1) != 0) {
    FUN_c08243a8(*(int *)(param_1 + 8),param_2 * 0x20 + 0x908,1);
    uVar2 = FUN_c082431c(*(int *)(param_1 + 8),param_2 * 0x20 + 0x910);
    *(uint *)(iVar3 + 0x20) = *(int *)(iVar3 + 0x1c) - (uVar2 & 0x7ffff);
    FUN_c082f128(param_1,param_2 * 2);
  }
  if ((uVar1 & 8) != 0) {
    FUN_c08243a8(*(int *)(param_1 + 8),param_2 * 0x20 + 0x908,8);
  }
  if ((uVar1 & 2) != 0) {
    FUN_c082d43c(param_1,param_2);
    FUN_c08243a8(*(int *)(param_1 + 8),param_2 * 0x20 + 0x908,2);
  }
  return;
}



/* c082f580 FUN_c082f580 */

/* Boundary evidence: original MIPS .pdata c082f580..c082f737. Semantic name remains unreviewed. */

void FUN_c082f580(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  int local_10;
  
  uVar2 = 0xb08;
  uVar1 = FUN_c082431c(param_1[2],0xb08);
  iVar3 = param_1[0x1c];
  if ((uVar1 & 8) != 0) {
    FUN_c082f738(param_1,uVar2,param_3,param_4);
  }
  if ((uVar1 & 1) != 0) {
    FUN_c08243a8(param_1[2],0xb08,1);
    if (iVar3 == 0) {
      FUN_c082ee08((int)param_1);
    }
    else {
      uVar1 = FUN_c082431c(param_1[2],0xb10);
      if ((uint)(*(int *)(iVar3 + 0x1c) - *(int *)(iVar3 + 0x20)) < 0x40) {
        local_10 = *(int *)(iVar3 + 0x1c) - *(int *)(iVar3 + 0x20);
      }
      else {
        local_10 = 0x40;
      }
      *(uint *)(iVar3 + 0x20) = *(int *)(iVar3 + 0x20) + (local_10 - (uVar1 & 0x7ffff));
      if ((*(uint *)(iVar3 + 0x20) < *(uint *)(iVar3 + 0x1c)) && ((uVar1 & 0x7ffff) == 0)) {
        FUN_c082dddc((int)param_1,1);
      }
      else {
        FUN_c082f128((int)param_1,1);
      }
    }
  }
  uVar1 = FUN_c082431c(param_1[2],0x81c);
  FUN_c08243a8(param_1[2],0x81c,uVar1 | 0x10000);
  return;
}



/* c082f738 FUN_c082f738 */

/* Boundary evidence: original MIPS .pdata c082f738..c082f7ff. Semantic name remains unreviewed. */

void FUN_c082f738(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  byte abStack_18 [8];
  uint local_10;
  
  local_10 = DAT_c0839254;
  FUN_c08248ac();
  FUN_c0827ba0(abStack_18,(void *)param_1[6],8);
  FUN_c08243a8(param_1[2],0xb08,8);
  iVar1 = FUN_c08317b8(param_1[1],abStack_18,param_1[10],param_4);
  if (iVar1 != 0) {
    FUN_c082d4b0(*param_1,0,1);
    FUN_c082ee08((int)param_1);
  }
  FUN_c0838c24(local_10);
  return;
}



/* c082f800 FUN_c082f800 */

/* Boundary evidence: original MIPS .pdata c082f800..c082f98f. Semantic name remains unreviewed. */

void FUN_c082f800(int param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  
  uVar3 = param_2 * 2 + 1;
  uVar1 = FUN_c082431c(*(int *)(param_1 + 8),param_2 * 0x20 + 0xb08);
  iVar4 = *(int *)(param_1 + uVar3 * 0x2c + 0x44);
  if ((uVar1 & 1) != 0) {
    FUN_c08243a8(*(int *)(param_1 + 8),param_2 * 0x20 + 0xb08,1);
    uVar2 = FUN_c082431c(*(int *)(param_1 + 8),param_2 * 0x20 + 0xb10);
    *(uint *)(iVar4 + 0x20) = *(int *)(iVar4 + 0x1c) - (uVar2 & 0x7ffff);
    FUN_c082f128(param_1,uVar3);
  }
  if ((uVar1 & 2) != 0) {
    uVar1 = FUN_c082431c(*(int *)(param_1 + 8),0x804);
    FUN_c08243a8(*(int *)(param_1 + 8),0x804,uVar1 | 0x400);
    FUN_c08243a8(*(int *)(param_1 + 8),param_2 * 0x20 + 0xb08,2);
  }
  uVar1 = FUN_c082431c(*(int *)(param_1 + 8),0x81c);
  FUN_c08243a8(*(int *)(param_1 + 8),0x81c,uVar1 | 1 << (param_2 + 0x10U & 0x1f));
  return;
}



/* c082f990 FUN_c082f990 */

/* Boundary evidence: original MIPS .pdata c082f990..c082fb5f. Semantic name remains unreviewed. */

void FUN_c082f990(int param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  uint local_c;
  
  uVar1 = FUN_c082431c(*(int *)(param_1 + 8),param_2 * 0x20 + 0x908);
  iVar2 = 1 << (*(byte *)(*(int *)(param_1 + param_2 * 0x58 + 0x4c) + 0xd) - 1 & 0x1f);
  if (((uVar1 & 1) == 0) && (iVar2 != 1)) {
    if ((uint)(iVar2 << 1) < *(uint *)(param_1 + param_2 * 0x58 + 0x58)) {
      local_c = FUN_c082431c(*(int *)(param_1 + 8),param_2 * 0x20 + 0x900);
      if ((local_c & 0x10000) == 0) {
        local_c = local_c | 0x20000000;
      }
      else {
        local_c = local_c | 0x10000000;
      }
      FUN_c08243a8(*(int *)(param_1 + 8),param_2 * 0x20 + 0x900,local_c);
      *(undefined4 *)(param_1 + param_2 * 0x58 + 0x58) = 1;
    }
    else {
      *(int *)(param_1 + param_2 * 0x58 + 0x58) = *(int *)(param_1 + param_2 * 0x58 + 0x58) + 1;
    }
  }
  return;
}



/* c082fb60 FUN_c082fb60 */

/* Boundary evidence: original MIPS .pdata c082fb60..c082fe1f. Semantic name remains unreviewed. */

void FUN_c082fb60(int param_1,uint param_2)

{
  uint uVar1;
  int iVar2;
  undefined4 local_20;
  undefined4 local_c;
  
  iVar2 = *(int *)(param_1 + param_2 * 0x58 + 0x44);
  uVar1 = FUN_c082431c(*(int *)(param_1 + 8),0x808);
  if (iVar2 != 0) {
    *(undefined4 *)(param_1 + param_2 * 0x58 + 0x54) = 0;
    *(undefined4 *)(param_1 + param_2 * 0x58 + 0x58) = 1;
    if ((*(char *)(*(int *)(param_1 + param_2 * 0x58 + 0x4c) + 0xd) == '\x01') ||
       (*(int *)(iVar2 + 0x20) == 0)) {
      if ((uVar1 >> 8 & 1) == 0) {
        local_20 = 0x20000000;
      }
      else {
        local_20 = 0x10000000;
      }
    }
    else {
      local_20 = 0;
    }
    if ((uint)(*(int *)(iVar2 + 0x1c) - *(int *)(iVar2 + 0x20)) <
        (uint)*(ushort *)(*(int *)(param_1 + param_2 * 0x58 + 0x4c) + 0x24)) {
      local_c = *(int *)(iVar2 + 0x1c) - *(int *)(iVar2 + 0x20);
    }
    else {
      local_c = (uint)*(ushort *)(*(int *)(param_1 + param_2 * 0x58 + 0x4c) + 0x24);
    }
    FUN_c08243a8(*(int *)(param_1 + 8),param_2 * 0x20 + 0x914,
                 *(int *)(*(int *)(iVar2 + 4) + 4) + *(int *)(iVar2 + 0x20));
    FUN_c08243a8(*(int *)(param_1 + 8),param_2 * 0x20 + 0x910,local_c | 0x80000);
    uVar1 = FUN_c082431c(*(int *)(param_1 + 8),param_2 * 0x20 + 0x900);
    FUN_c08243a8(*(int *)(param_1 + 8),param_2 * 0x20 + 0x900,uVar1 | 0x84000000 | local_20);
    uVar1 = FUN_c082431c(*(int *)(param_1 + 8),0x81c);
    FUN_c08243a8(*(int *)(param_1 + 8),0x81c,uVar1 | 1 << (param_2 & 0x1f));
  }
  return;
}



/* c082fe20 FUN_c082fe20 */

/* Boundary evidence: original MIPS .pdata c082fe20..c082ff33. Semantic name remains unreviewed. */

void FUN_c082fe20(int param_1)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = FUN_c0829eb8(param_1);
  uVar2 = FUN_c082431c(*(int *)(iVar1 + 8),8);
  FUN_c08243a8(*(int *)(iVar1 + 8),8,uVar2 & 0xffffff5e);
  uVar2 = FUN_c082431c(*(int *)(iVar1 + 8),0xc);
  FUN_c08243a8(*(int *)(iVar1 + 8),0xc,uVar2 & 0xffffdbff);
  uVar2 = FUN_c082431c(*(int *)(iVar1 + 8),0x18);
  FUN_c08243a8(*(int *)(iVar1 + 8),0x18,uVar2 & ~*(uint *)(iVar1 + 0x5b8));
  FUN_c08243a8(*(int *)(iVar1 + 8),0x818,0);
  if (*(int *)(iVar1 + 0x10) != 0) {
    FUN_c0835a50(*(int **)(iVar1 + 0xc),*(LPVOID *)(iVar1 + 0x10));
    *(undefined4 *)(iVar1 + 0x10) = 0;
  }
  return;
}



/* c082ff34 FUN_c082ff34 */

/* Boundary evidence: original MIPS .pdata c082ff34..c082ff9b. Semantic name remains unreviewed. */

undefined4 FUN_c082ff34(int param_1)

{
  int iVar1;
  undefined4 local_c;
  
  iVar1 = FUN_c0829cc0(param_1);
  if ((iVar1 == 0) || (*(int *)(iVar1 + 4) != 0x2012)) {
    local_c = 0;
  }
  else {
    local_c = 0xd;
  }
  return local_c;
}



/* c082ff9c FUN_c082ff9c */

/* Boundary evidence: original MIPS .pdata c082ff9c..c0830093. Semantic name remains unreviewed. */

undefined4 FUN_c082ff9c(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  
  if ((param_1 != 0) && (iVar1 = FUN_c0829eb8(param_1), iVar1 != 0)) {
    FUN_c0832358(*(int *)(iVar1 + 4),param_2,param_3,param_4);
    if (*(int *)(iVar1 + 0x24) != 0) {
      FUN_c0829a8c(*(LPVOID *)(iVar1 + 0x24));
    }
    uVar2 = FUN_c0825c4c(param_1);
    if (*(int *)(iVar1 + 8) != 0) {
      FUN_c082424c(uVar2,*(int **)(iVar1 + 8));
    }
    if (*(int *)(iVar1 + 0xc) != 0) {
      FUN_c082424c(uVar2,*(int **)(iVar1 + 0xc));
    }
  }
  return 0;
}



/* c0830094 FUN_c0830094 */

/* Boundary evidence: original MIPS .pdata c0830094..c08301cb. Semantic name remains unreviewed. */

int FUN_c0830094(int param_1)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  undefined **ppuVar4;
  int *piVar5;
  int local_28;
  
  piVar1 = (int *)FUN_c0829eb8(param_1);
  iVar2 = FUN_c0825c4c(param_1);
  *piVar1 = param_1;
  piVar1[10] = 3;
  piVar3 = FUN_c0824170(iVar2,2,0);
  piVar1[2] = (int)piVar3;
  piVar3 = FUN_c0824170(iVar2,1,0);
  piVar1[3] = (int)piVar3;
  piVar5 = piVar1 + 7;
  piVar3 = piVar1 + 6;
  ppuVar4 = (undefined **)0x4;
  local_28 = FUN_c082901c(8,4,piVar3,piVar5,1,piVar1 + 9);
  if (local_28 == 0) {
    FUN_c08301cc((int)piVar1);
    piVar3 = piVar1 + 1;
    ppuVar4 = &PTR_FUN_c0839180;
    local_28 = FUN_c0831bfc(param_1,-0x3f7c6e80,piVar3);
  }
  else {
    piVar1[9] = 0;
  }
  if (local_28 != 0) {
    FUN_c082ff9c(param_1,ppuVar4,piVar3,piVar5);
  }
  return local_28;
}



/* c08301cc FUN_c08301cc */

/* Boundary evidence: original MIPS .pdata c08301cc..c08304fb. Semantic name remains unreviewed. */

void FUN_c08301cc(int param_1)

{
  undefined1 local_10;
  
  FUN_c08304fc(param_1);
  for (local_10 = 0; local_10 < 0x20; local_10 = local_10 + 2) {
    *(undefined4 *)(param_1 + 0x30 + (uint)local_10 * 0x2c) = 1;
    *(undefined1 *)(param_1 + (uint)local_10 * 0x2c + 0x34) = 0;
    *(undefined2 *)(param_1 + (uint)local_10 * 0x2c + 0x3e) = 0;
    *(undefined2 *)(param_1 + (uint)local_10 * 0x2c + 0x3c) = 0x400;
    *(undefined4 *)(param_1 + (uint)local_10 * 0x2c + 0x44) = 0;
    *(undefined4 *)(param_1 + (uint)local_10 * 0x2c + 0x48) = 0;
    *(undefined4 *)(param_1 + (uint)local_10 * 0x2c + 0x54) = 0;
    *(undefined4 *)(param_1 + (uint)local_10 * 0x2c + 0x58) = 0;
    *(undefined4 *)(param_1 + 0x30 + (local_10 + 1) * 0x2c) = 0;
    *(undefined1 *)(param_1 + (local_10 + 1) * 0x2c + 0x34) = 0;
    *(undefined2 *)(param_1 + (local_10 + 1) * 0x2c + 0x3e) = 0;
    *(undefined2 *)(param_1 + (local_10 + 1) * 0x2c + 0x3c) = 0x400;
    *(undefined4 *)(param_1 + (local_10 + 1) * 0x2c + 0x44) = 0;
    *(undefined4 *)(param_1 + (local_10 + 1) * 0x2c + 0x48) = 0;
    *(undefined4 *)(param_1 + (local_10 + 1) * 0x2c + 0x54) = 0;
    *(undefined4 *)(param_1 + (local_10 + 1) * 0x2c + 0x58) = 0;
  }
  *(undefined1 *)(param_1 + 0x34) = 0;
  *(undefined4 *)(param_1 + 0x4c) = 0;
  *(undefined2 *)(param_1 + 0x3c) = 0x40;
  *(undefined4 *)(param_1 + 0x38) = 1;
  *(undefined4 *)(param_1 + 0x50) = 1;
  *(undefined4 *)(param_1 + 0x54) = 0;
  *(undefined4 *)(param_1 + 0x58) = 0;
  *(undefined1 *)(param_1 + 0x60) = 0;
  *(undefined4 *)(param_1 + 0x78) = 0;
  *(undefined4 *)(param_1 + 100) = 1;
  *(undefined2 *)(param_1 + 0x68) = 0x40;
  *(undefined4 *)(param_1 + 0x7c) = 1;
  *(undefined4 *)(param_1 + 0x80) = 0;
  *(undefined4 *)(param_1 + 0x84) = 0;
  return;
}



/* c08304fc FUN_c08304fc */

/* Boundary evidence: original MIPS .pdata c08304fc..c0830797. Semantic name remains unreviewed. */

void FUN_c08304fc(int param_1)

{
  uint uVar1;
  uint uVar2;
  undefined4 uVar3;
  uint uVar4;
  byte local_17;
  
  uVar1 = FUN_c082431c(*(int *)(param_1 + 8),0x44);
  uVar2 = FUN_c082431c(*(int *)(param_1 + 8),0x48);
  uVar3 = FUN_c082431c(*(int *)(param_1 + 8),0x50);
  for (local_17 = 0; local_17 < (byte)(((char)((uVar2 & 0x3c00) >> 10) + '\x01') * '\x02');
      local_17 = local_17 + 2) {
    uVar4 = uVar1 >> (local_17 & 0x1f) & 3;
    if (uVar4 == 0) {
      *(undefined4 *)(param_1 + (uint)local_17 * 0x2c + 0x50) = 1;
      *(char *)(param_1 + 0x5b0) = *(char *)(param_1 + 0x5b0) + '\x01';
      *(undefined4 *)(param_1 + (local_17 + 1) * 0x2c + 0x50) = 1;
      *(char *)(param_1 + 0x5b1) = *(char *)(param_1 + 0x5b1) + '\x01';
    }
    else if (uVar4 == 1) {
      *(undefined4 *)(param_1 + (uint)local_17 * 0x2c + 0x50) = 1;
      *(char *)(param_1 + 0x5b0) = *(char *)(param_1 + 0x5b0) + '\x01';
      *(undefined4 *)(param_1 + (local_17 + 1) * 0x2c + 0x50) = 0;
    }
    else if (uVar4 == 2) {
      *(undefined4 *)(param_1 + (uint)local_17 * 0x2c + 0x50) = 0;
      *(undefined4 *)(param_1 + (local_17 + 1) * 0x2c + 0x50) = 1;
      *(char *)(param_1 + 0x5b1) = *(char *)(param_1 + 0x5b1) + '\x01';
    }
  }
  uVar1 = FUN_c082431c(*(int *)(param_1 + 8),0x50);
  if ((uVar1 & 0x2000000) != 0) {
    *(byte *)(param_1 + 0x5b0) = (((byte)((uint)uVar3 >> 0x18) & 0x3c) >> 2) + 1;
  }
  return;
}



/* c0830798 FUN_c0830798 */

/* Boundary evidence: original MIPS .pdata c0830798..c08307e7. Semantic name remains unreviewed. */

void FUN_c0830798(int param_1)

{
  if (*(int *)(param_1 + 0x14) == 0) {
    FUN_c08319b0(*(int *)(param_1 + 4));
    *(undefined4 *)(param_1 + 0x14) = 1;
  }
  return;
}



/* c08307e8 FUN_c08307e8 */

/* Boundary evidence: original MIPS .pdata c08307e8..c0830833. Semantic name remains unreviewed. */

void FUN_c08307e8(int param_1)

{
  if (*(int *)(param_1 + 0x14) != 0) {
    FUN_c0831aac(*(int *)(param_1 + 4));
    *(undefined4 *)(param_1 + 0x14) = 0;
  }
  return;
}



/* c0830834 FUN_c0830834 */

/* Boundary evidence: original MIPS .pdata c0830834..c0830853. Semantic name remains unreviewed. */

undefined4 FUN_c0830834(void)

{
  return 0;
}



/* c0830854 FUN_c0830854 */

/* Boundary evidence: original MIPS .pdata c0830854..c0830873. Semantic name remains unreviewed. */

undefined4 FUN_c0830854(void)

{
  return 0;
}



/* c0830874 FUN_c0830874 */

/* Boundary evidence: original MIPS .pdata c0830874..c08308e7. Semantic name remains unreviewed. */

undefined4 FUN_c0830874(int param_1)

{
  int iVar1;
  undefined4 local_18;
  
  local_18 = 0;
  if ((param_1 != 0) && (iVar1 = FUN_c0829eb8(param_1), iVar1 != 0)) {
    local_18 = 10;
  }
  return local_18;
}



/* c08308e8 FUN_c08308e8 */

/* Boundary evidence: original MIPS .pdata c08308e8..c0830987. Semantic name remains unreviewed. */

undefined4 FUN_c08308e8(void)

{
  undefined4 uVar1;
  
  uVar1 = FUN_c08285b8(0,&PTR_FUN_c08391d8,"syn_hsfc",0x5c4,&DAT_c0839380);
  return uVar1;
}



/* c0830988 FUN_c0830988 */

/* Boundary evidence: original MIPS .pdata c0830988..c08309bf. Semantic name remains unreviewed. */

void FUN_c0830988(void)

{
  FUN_c08284f8(DAT_c0839380);
  return;
}



/* c08309c0 FUN_c08309c0 */

/* Boundary evidence: original MIPS .pdata c08309c0..c0830b13. Semantic name remains unreviewed. */

void FUN_c08309c0(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = *(int *)(param_2 + 0x34);
  *(undefined4 *)(param_2 + 0x34) = 0;
  if (((*(char *)(param_2 + 1) == '\x01') && (*(int *)(param_2 + 0x20) != 0)) &&
     (*(int *)(param_2 + 4) != *(int *)(param_2 + 8))) {
    if (**(int **)(param_2 + 8) == 0) {
      FUN_c0825484(**(int **)(param_2 + 4),*(int *)(*(int *)(param_2 + 8) + 8),
                   *(uint *)(param_2 + 0x20));
    }
    else {
      FUN_c0827ba0((void *)**(undefined4 **)(param_2 + 8),(void *)**(undefined4 **)(param_2 + 4),
                   *(size_t *)(param_2 + 0x20));
    }
  }
  if ((iVar1 != 0) &&
     (*(undefined4 *)(iVar1 + 0x2c) = *(undefined4 *)(*(int *)(iVar1 + 0x2c) + 0x2c),
     *(int *)(iVar1 + 0x2c) == 0)) {
    *(int *)(iVar1 + 0x30) = iVar1 + 0x2c;
  }
  FUN_c0830b14(param_1,iVar1);
  if (*(int *)(param_2 + 0x10) != 0) {
    (**(code **)(param_2 + 0x10))(param_2);
  }
  return;
}



/* c0830b14 FUN_c0830b14 */

/* Boundary evidence: original MIPS .pdata c0830b14..c0830ba7. Semantic name remains unreviewed. */

void FUN_c0830b14(int param_1,int param_2)

{
  if (((param_2 != 0) && (*(int *)(param_2 + 0x28) != 4)) && (*(int *)(param_2 + 0x2c) != 0)) {
    (**(code **)(*(int *)(param_1 + 0x24) + 0x30))
              (*(undefined4 *)(param_1 + 0x20),param_2,*(int *)(param_2 + 0x2c));
  }
  return;
}



/* c0830ba8 FUN_c0830ba8 */

/* Boundary evidence: original MIPS .pdata c0830ba8..c0830bf3. Semantic name remains unreviewed. */

int FUN_c0830ba8(int param_1,int param_2,int param_3)

{
  int iVar1;
  
  *(undefined1 *)(param_3 + 1) = 0;
  iVar1 = FUN_c0830bf4(param_1,param_2,param_3);
  return iVar1;
}



/* c0830bf4 FUN_c0830bf4 */

/* Boundary evidence: original MIPS .pdata c0830bf4..c0830e1f. Semantic name remains unreviewed. */

int FUN_c0830bf4(int param_1,int param_2,int param_3)

{
  bool bVar1;
  int local_18;
  
  bVar1 = false;
  local_18 = FUN_c0830e20(param_1,param_2,param_3);
  if (local_18 == 0) {
    if (((*(int *)(param_3 + 0x1c) != 0) && (*(int *)(param_3 + 4) != *(int *)(param_3 + 8))) &&
       (*(char *)(param_3 + 1) == '\0')) {
      if (**(int **)(param_3 + 8) == 0) {
        FUN_c08255c4(*(int *)(*(int *)(param_3 + 8) + 8),**(int **)(param_3 + 4),
                     *(uint *)(param_3 + 0x1c));
      }
      else {
        FUN_c0827ba0((void *)**(undefined4 **)(param_3 + 4),(void *)**(undefined4 **)(param_3 + 8),
                     *(size_t *)(param_3 + 0x1c));
      }
    }
    *(undefined4 *)(param_3 + 0x18) = 1;
    *(undefined4 *)(param_3 + 0x20) = 0;
    *(int *)(param_3 + 0x34) = param_2;
    if ((*(int *)(*(int *)(param_1 + 0x24) + 0x2c) == 0) ||
       (local_18 = (**(code **)(*(int *)(param_1 + 0x24) + 0x2c))
                             (*(undefined4 *)(param_1 + 0x20),param_2,param_3), local_18 == 0)) {
      if (param_2 != 0) {
        bVar1 = *(int *)(param_2 + 0x2c) == 0;
        *(undefined4 *)(param_3 + 0x2c) = 0;
        **(int **)(param_2 + 0x30) = param_3;
        *(int *)(param_2 + 0x30) = param_3 + 0x2c;
      }
      if ((*(int *)(param_1 + 200) == 0) && ((param_2 == 0 || (bVar1)))) {
        (**(code **)(*(int *)(param_1 + 0x24) + 0x30))
                  (*(undefined4 *)(param_1 + 0x20),param_2,param_3);
      }
    }
  }
  return local_18;
}



/* c0830e20 FUN_c0830e20 */

/* Boundary evidence: original MIPS .pdata c0830e20..c0830f77. Semantic name remains unreviewed. */

undefined4 FUN_c0830e20(int param_1,int param_2,int param_3)

{
  undefined4 local_10;
  
  if (((*(int *)(param_1 + 0xc) == 5) || (*(int *)(param_1 + 0xc) == 6)) ||
     (*(int *)(param_1 + 8) == 0)) {
    if ((param_2 == 0) && (*(char *)(param_1 + 0x3c) != *(char *)(param_3 + 3))) {
      local_10 = 3;
    }
    else if ((param_2 == 0) || (*(int *)(param_2 + 0x28) != 4)) {
      if (*(int *)(param_3 + 0x18) != 0) {
        return 8;
      }
      if ((*(int *)(param_3 + 0x1c) == 0) ||
         ((*(int *)(param_3 + 4) != 0 && (*(int *)(param_3 + 8) != 0)))) {
        local_10 = FUN_c0830f78(param_1);
      }
      else {
        local_10 = 10;
      }
    }
    else {
      local_10 = 0x10;
    }
  }
  else {
    local_10 = 0x10;
  }
  return local_10;
}



/* c0830f78 FUN_c0830f78 */

/* Boundary evidence: original MIPS .pdata c0830f78..c0830fc3. Semantic name remains unreviewed. */

undefined4 FUN_c0830f78(int param_1)

{
  undefined4 local_8;
  
  local_8 = 0;
  if (*(int *)(param_1 + 0xc) == 6) {
    local_8 = 0xd;
  }
  return local_8;
}



/* c0830fc4 FUN_c0830fc4 */

/* Boundary evidence: original MIPS .pdata c0830fc4..c0831013. Semantic name remains unreviewed. */

int FUN_c0830fc4(int param_1,int param_2,int param_3)

{
  int iVar1;
  
  *(undefined1 *)(param_3 + 1) = 1;
  iVar1 = FUN_c0830bf4(param_1,param_2,param_3);
  return iVar1;
}



/* c0831014 FUN_c0831014 */

/* Boundary evidence: original MIPS .pdata c0831014..c083106b. Semantic name remains unreviewed. */

void FUN_c0831014(int param_1,undefined4 param_2,undefined1 param_3)

{
  (**(code **)(*(int *)(param_1 + 0x24) + 0x28))(*(undefined4 *)(param_1 + 0x20),param_2,param_3);
  return;
}



/* c083106c FUN_c083106c */

/* Boundary evidence: original MIPS .pdata c083106c..c08310c7. Semantic name remains unreviewed. */

void FUN_c083106c(int param_1,char param_2)

{
  if (param_2 == *(char *)(param_1 + 0x3c)) {
    FUN_c0831014(param_1,0,1);
  }
  return;
}



/* c08310c8 FUN_c08310c8 */

/* Boundary evidence: original MIPS .pdata c08310c8..c0831197. Semantic name remains unreviewed. */

void FUN_c08310c8(int param_1,int param_2)

{
  int iVar1;
  undefined4 local_14;
  
  local_14 = 0;
  if (param_2 != 0) {
    local_14 = *(undefined4 *)(param_2 + 0x28);
    *(undefined4 *)(param_2 + 0x28) = 4;
  }
  (**(code **)(*(int *)(param_1 + 0x24) + 0x24))(*(undefined4 *)(param_1 + 0x20),param_2);
  if (param_2 != 0) {
    while (*(int *)(param_2 + 0x2c) != 0) {
      iVar1 = *(int *)(param_2 + 0x2c);
      *(undefined4 *)(iVar1 + 0x18) = 2;
      FUN_c08309c0(param_1,iVar1);
    }
    *(undefined4 *)(param_2 + 0x28) = local_14;
  }
  return;
}



/* c0831198 FUN_c0831198 */

/* Boundary evidence: original MIPS .pdata c0831198..c083153f. Semantic name remains unreviewed. */

int FUN_c0831198(int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int local_2c;
  int *local_28;
  int local_20;
  uint local_1c;
  int local_10;
  
  if ((*(int *)(param_1 + 0xc) == 2) || (*(int *)(param_1 + 0xc) == 3)) {
    puVar1 = FUN_c08246fc(0x14);
    if (puVar1 == (undefined4 *)0x0) {
      local_10 = 7;
    }
    else {
      puVar1[2] = param_2;
      puVar1[4] = param_3;
      *puVar1 = 0;
      puVar1[1] = 1;
      uVar2 = (**(code **)puVar1[2])(puVar1[4]);
      puVar1[3] = uVar2;
      if (puVar1[3] == 0) {
        FUN_c0824790(puVar1);
        local_10 = 10;
      }
      else {
        for (local_2c = 0; local_2c < (int)(uint)*(byte *)(puVar1[3] + 8); local_2c = local_2c + 1)
        {
          for (local_1c = 0;
              (int)local_1c < (int)(uint)*(byte *)(*(int *)(puVar1[3] + 0xc) + local_2c * 0x18 + 8);
              local_1c = local_1c + 1) {
            for (local_20 = 0;
                local_20 <
                (int)(uint)*(byte *)(*(int *)(*(int *)(puVar1[3] + 0xc) + local_2c * 0x18 + 4) +
                                    local_1c * 0x10); local_20 = local_20 + 1) {
              iVar4 = *(int *)(*(int *)(*(int *)(puVar1[3] + 0xc) + local_2c * 0x18 + 4) +
                               local_1c * 0x10 + 4) + local_20 * 0x34;
              iVar3 = (**(code **)(*(int *)(param_1 + 0x24) + 0x34))
                                (*(undefined4 *)(param_1 + 0x20),iVar4,
                                 (uint)*(byte *)(param_1 + 0x34) + local_2c & 0xff,local_1c & 0xff);
              if (iVar3 != 0) {
                return iVar3;
              }
              *(undefined4 *)(iVar4 + 0x2c) = 0;
              *(int *)(iVar4 + 0x30) = iVar4 + 0x2c;
            }
          }
        }
        *(char *)(param_1 + 0x34) = *(char *)(param_1 + 0x34) + *(char *)(puVar1[3] + 8);
        if (*(int *)puVar1[3] < (int)(uint)*(byte *)(param_1 + 0x18)) {
          *(char *)(param_1 + 0x18) = (char)*(undefined4 *)puVar1[3];
        }
        if (*(int *)(puVar1[3] + 0x10) != 0) {
          *(undefined4 *)(param_1 + 0x1c) = 1;
        }
        for (local_28 = (int *)(param_1 + 0x2c); *local_28 != 0; local_28 = (int *)*local_28) {
        }
        *local_28 = (int)puVar1;
        local_10 = 0;
      }
    }
  }
  else {
    local_10 = 0x10;
  }
  return local_10;
}



/* c0831540 FUN_c0831540 */

/* Boundary evidence: original MIPS .pdata c0831540..c083156b. Semantic name remains unreviewed. */

undefined1 FUN_c0831540(int param_1)

{
  return *(undefined1 *)(param_1 + 0x34);
}



/* c083156c FUN_c083156c */

/* Boundary evidence: original MIPS .pdata c083156c..c083175b. Semantic name remains unreviewed. */

LPVOID FUN_c083156c(int param_1,uint param_2,int *param_3)

{
  int iVar1;
  undefined4 uVar2;
  byte local_28;
  LPVOID local_18;
  int *local_c;
  
  local_28 = 0;
  if (param_3 != (int *)0x0) {
    local_28 = *param_3 != 0;
    if (param_3[1] != 0) {
      local_28 = local_28 | 2;
    }
    if (param_3[2] != 0) {
      local_28 = local_28 | 4;
    }
  }
  local_18 = FUN_c08246fc(0x40);
  if (local_18 == (LPVOID)0x0) {
    local_18 = (LPVOID)0x0;
  }
  else {
    *(uint *)((int)local_18 + 0xc) = param_2;
    if ((local_28 & *(byte *)(param_1 + 0x28)) == 0) {
      iVar1 = FUN_c082901c(param_2,0,(int *)0x0,(int *)0x0,2,(undefined4 *)((int)local_18 + 0x24));
      if (iVar1 == 0) {
        local_c = param_3;
        if (param_3 == (int *)0x0) {
          local_c = (int *)FUN_c0828ffc(*(undefined4 *)((int)local_18 + 0x24));
        }
        *(int **)((int)local_18 + 8) = local_c;
        uVar2 = FUN_c0828ffc(*(undefined4 *)((int)local_18 + 0x24));
        *(undefined4 *)((int)local_18 + 4) = uVar2;
      }
      else {
        if (local_18 != (LPVOID)0x0) {
          FUN_c0824790(local_18);
        }
        local_18 = (LPVOID)0x0;
      }
    }
    else {
      *(int **)((int)local_18 + 8) = param_3;
      *(int **)((int)local_18 + 4) = param_3;
    }
  }
  return local_18;
}



/* c083175c FUN_c083175c */

/* Boundary evidence: original MIPS .pdata c083175c..c08317b7. Semantic name remains unreviewed. */

void FUN_c083175c(LPVOID param_1)

{
  if (param_1 != (LPVOID)0x0) {
    if (*(int *)((int)param_1 + 0x24) != 0) {
      FUN_c0829a8c(*(LPVOID *)((int)param_1 + 0x24));
    }
    FUN_c0824790(param_1);
  }
  return;
}



/* c08317b8 FUN_c08317b8 */

/* Boundary evidence: original MIPS .pdata c08317b8..c083189f. Semantic name remains unreviewed. */

int FUN_c08317b8(int param_1,byte *param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 local_c;
  
  *(char *)(param_1 + 0x3c) = *(char *)(param_1 + 0x3c) + '\x01';
  if (*(int *)(param_1 + 0xc) == 5) {
    if ((*(int *)(param_1 + 8) == 0) || (*(int *)(param_1 + 8) == 1)) {
      if (param_2 == (byte *)0x0) {
        local_c = 10;
      }
      else {
        *(undefined4 *)(param_1 + 0x14) = param_3;
        local_c = FUN_c08364f8(param_1,param_2,*(byte *)(param_1 + 0x3c),param_4);
      }
    }
    else {
      local_c = 0x10;
    }
  }
  else {
    local_c = 0x10;
  }
  return local_c;
}



/* c08318a0 FUN_c08318a0 */

/* Boundary evidence: original MIPS .pdata c08318a0..c0831937. Semantic name remains unreviewed. */

undefined4 FUN_c08318a0(char param_1)

{
  undefined4 *puVar1;
  undefined4 local_c;
  
  puVar1 = FUN_c0831938(param_1);
  if (*(int *)(puVar1[9] + 8) == 0) {
    local_c = 0xb;
  }
  else if (puVar1[0x31] == 0) {
    local_c = 10;
  }
  else {
    local_c = (**(code **)(puVar1[9] + 8))(puVar1[8]);
  }
  return local_c;
}



/* c0831938 FUN_c0831938 */

/* Boundary evidence: original MIPS .pdata c0831938..c08319af. Semantic name remains unreviewed. */

undefined4 * FUN_c0831938(char param_1)

{
  undefined4 *local_8;
  
  for (local_8 = DAT_c0839388;
      (local_8 != (undefined4 *)0x0 && (*(char *)(local_8 + 0x3e) != param_1));
      local_8 = (undefined4 *)*local_8) {
  }
  return local_8;
}



/* c08319b0 FUN_c08319b0 */

/* Boundary evidence: original MIPS .pdata c08319b0..c0831aab. Semantic name remains unreviewed. */

undefined4 FUN_c08319b0(int param_1)

{
  undefined4 *local_14;
  
  *(undefined4 *)(param_1 + 0xc) = 6;
  (**(code **)(*(int *)(param_1 + 0x24) + 0x24))(*(undefined4 *)(param_1 + 0x20),0);
  *(undefined4 *)(*(int *)(param_1 + 0x38) + 0x18) = 0;
  for (local_14 = *(undefined4 **)(param_1 + 0x2c); local_14 != (undefined4 *)0x0;
      local_14 = (undefined4 *)*local_14) {
    if ((local_14[2] != 0) && (*(int *)(local_14[2] + 0xc) != 0)) {
      (**(code **)(local_14[2] + 0xc))(local_14[4]);
    }
  }
  FUN_c0825c4c(*(int *)(param_1 + 0x20));
  FUN_c08243d4();
  return 0;
}



/* c0831aac FUN_c0831aac */

/* Boundary evidence: original MIPS .pdata c0831aac..c0831b9f. Semantic name remains unreviewed. */

undefined4 FUN_c0831aac(int param_1)

{
  undefined4 *local_10;
  
  FUN_c0825c4c(*(int *)(param_1 + 0x20));
  FUN_c08243d4();
  *(undefined4 *)(param_1 + 0xc) = 5;
  for (local_10 = *(undefined4 **)(param_1 + 0x2c); local_10 != (undefined4 *)0x0;
      local_10 = (undefined4 *)*local_10) {
    if (((local_10[1] == 0) && (local_10[2] != 0)) && (*(int *)(local_10[2] + 0x10) != 0)) {
      (**(code **)(local_10[2] + 0x10))(local_10[4]);
    }
  }
  FUN_c08243d4();
  return 0;
}



/* c0831ba0 FUN_c0831ba0 */

/* Boundary evidence: original MIPS .pdata c0831ba0..c0831bfb. Semantic name remains unreviewed. */

void FUN_c0831ba0(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  *(undefined4 *)(param_1 + 0xc4) = 0;
  FUN_c08310c8(param_1,0);
  FUN_c0835e04(param_1,0,param_3,param_4);
  *(undefined4 *)(param_1 + 0xc) = 5;
  return;
}



/* c0831bfc FUN_c0831bfc */

/* Boundary evidence: original MIPS .pdata c0831bfc..c0831df7. Semantic name remains unreviewed. */

int FUN_c0831bfc(undefined4 param_1,int param_2,undefined4 *param_3)

{
  undefined1 uVar1;
  LPVOID pvVar2;
  int local_18;
  undefined4 *local_14;
  int local_10;
  
  if (DAT_c0839384 == 1) {
    for (local_14 = DAT_c0839388; (local_14 != (undefined4 *)0x0 && (local_14[9] != 0));
        local_14 = (undefined4 *)*local_14) {
    }
    if (local_14 == (undefined4 *)0x0) {
      local_18 = 10;
    }
    else {
      if (param_3 != (undefined4 *)0x0) {
        *param_3 = local_14;
      }
      local_18 = FUN_c0826874(local_14 + 0x33,0);
      if (local_18 == 0) {
        local_14[3] = 2;
        local_14[2] = 1;
        *(undefined1 *)(local_14 + 6) = 3;
        local_14[9] = param_2;
        local_14[8] = param_1;
        local_14[7] = 0;
        uVar1 = (**(code **)(param_2 + 0x50))(local_14[8]);
        *(undefined1 *)(local_14 + 10) = uVar1;
        if (*(char *)(local_14 + 10) == '\0') {
          local_18 = 10;
        }
        else {
          pvVar2 = FUN_c083156c((int)local_14,0x100,(int *)0x0);
          local_14[0xe] = pvVar2;
          if (local_14[0xe] == 0) {
            local_18 = 7;
          }
          else {
            local_18 = FUN_c0831df8((int)local_14);
            if (local_18 == 0) {
              return 0;
            }
          }
        }
      }
    }
    local_10 = local_18;
  }
  else {
    local_10 = 0x10;
  }
  return local_10;
}



/* c0831df8 FUN_c0831df8 */

/* Boundary evidence: original MIPS .pdata c0831df8..c0831ec7. Semantic name remains unreviewed. */

int FUN_c0831df8(int param_1)

{
  int iVar1;
  uint local_14;
  
  local_14 = 0;
  while( true ) {
    if (*(byte *)(param_1 + 0x108) <= local_14) {
      *(undefined4 *)(param_1 + 0xc) = 3;
      iVar1 = FUN_c0832058(param_1);
      return iVar1;
    }
    iVar1 = FUN_c0831ec8(param_1,(int *)(*(int *)(param_1 + 0x10c) + local_14 * 0xc));
    if (iVar1 != 0) break;
    local_14 = local_14 + 1;
  }
  return iVar1;
}



/* c0831ec8 FUN_c0831ec8 */

/* Boundary evidence: original MIPS .pdata c0831ec8..c0832057. Semantic name remains unreviewed. */

int FUN_c0831ec8(undefined4 param_1,int *param_2)

{
  int local_20;
  code *local_1c;
  int local_18;
  int local_14;
  
  local_20 = 0;
  if (*param_2 == 0xf) {
    local_1c = (code *)param_2[2];
    if (local_1c == (code *)0x0) {
      return 10;
    }
  }
  else {
    for (local_14 = 0;
        (*(int *)(&DAT_c0839164 + local_14 * 8) != 0 &&
        (*(int *)(&DAT_c0839164 + local_14 * 8) != *param_2)); local_14 = local_14 + 1) {
    }
    if (*(int *)(&DAT_c0839164 + local_14 * 8) == 0) {
      return 4;
    }
    local_1c = (code *)(&PTR_FUN_c0839168)[local_14 * 2];
  }
  local_18 = 0;
  while ((local_18 < (int)(uint)*(byte *)(param_2 + 1) &&
         (local_20 = (*local_1c)(param_1), local_20 == 0))) {
    local_18 = local_18 + 1;
  }
  return local_20;
}



/* c0832058 FUN_c0832058 */

/* Boundary evidence: original MIPS .pdata c0832058..c0832357. Semantic name remains unreviewed. */

undefined4 FUN_c0832058(int param_1)

{
  LPVOID pvVar1;
  byte local_18;
  undefined4 *local_14;
  byte local_10;
  undefined4 local_c;
  
  if (*(int *)(param_1 + 0xc) == 3) {
    pvVar1 = FUN_c08246fc((uint)*(byte *)(param_1 + 0x34) * 0x14);
    *(LPVOID *)(param_1 + 0x30) = pvVar1;
    if (*(int *)(param_1 + 0x30) == 0) {
      local_c = 7;
    }
    else {
      local_18 = 0;
      local_10 = 0;
      local_14 = *(undefined4 **)(param_1 + 0x2c);
      for (; (local_14 != (undefined4 *)0x0 && (local_18 < *(byte *)(param_1 + 0x34)));
          local_18 = local_18 + 1) {
        if (*(byte *)(local_14[3] + 8) <= local_10) {
          local_14 = (undefined4 *)*local_14;
          local_10 = 0;
        }
        *(byte *)(*(int *)(param_1 + 0x30) + (uint)local_18 * 0x14 + 5) = local_10;
        *(undefined4 **)(*(int *)(param_1 + 0x30) + (uint)local_18 * 0x14 + 8) = local_14;
        *(byte *)(*(int *)(param_1 + 0x30) + (uint)local_18 * 0x14 + 4) = local_18;
        *(undefined4 *)(*(int *)(param_1 + 0x30) + (uint)local_18 * 0x14 + 0x10) =
             *(undefined4 *)(*(int *)(local_14[3] + 0xc) + (uint)local_10 * 0x18 + 4);
        *(uint *)(*(int *)(param_1 + 0x30) + (uint)local_18 * 0x14 + 0xc) =
             *(int *)(local_14[3] + 0xc) + (uint)local_10 * 0x18;
        *(undefined4 *)(*(int *)(param_1 + 0x30) + (uint)local_18 * 0x14) =
             *(undefined4 *)(*(int *)(local_14[3] + 0xc) + (uint)local_10 * 0x18);
        *(byte *)(*(int *)(local_14[3] + 0xc) + (uint)local_10 * 0x18 + 0x12) = local_18;
        *(undefined1 *)(*(int *)(local_14[3] + 0xc) + (uint)local_10 * 0x18 + 9) = 0;
        local_10 = local_10 + 1;
      }
      *(undefined4 *)(param_1 + 0xc) = 4;
      local_c = 0;
    }
  }
  else {
    local_c = 0x10;
  }
  return local_c;
}



/* c0832358 FUN_c0832358 */

/* Boundary evidence: original MIPS .pdata c0832358..c08323f7. Semantic name remains unreviewed. */

void FUN_c0832358(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  if (param_1 != 0) {
    FUN_c0835e04(param_1,0,param_3,param_4);
    FUN_c08323f8(param_1);
    if (*(int *)(param_1 + 0xcc) != 0) {
      FUN_c0826948(*(LPVOID *)(param_1 + 0xcc));
    }
    if (*(int *)(param_1 + 0x38) != 0) {
      FUN_c083175c(*(LPVOID *)(param_1 + 0x38));
    }
    *(undefined4 *)(param_1 + 0x24) = 0;
  }
  return;
}



/* c08323f8 FUN_c08323f8 */

/* Boundary evidence: original MIPS .pdata c08323f8..c083262f. Semantic name remains unreviewed. */

void FUN_c08323f8(int param_1)

{
  undefined4 *puVar1;
  int local_20;
  int local_18;
  int local_14;
  undefined4 *local_10;
  
  local_10 = *(undefined4 **)(param_1 + 0x2c);
  while (local_10 != (undefined4 *)0x0) {
    for (local_20 = 0; local_20 < (int)(uint)*(byte *)(local_10[3] + 8); local_20 = local_20 + 1) {
      for (local_14 = 0;
          local_14 < (int)(uint)*(byte *)(*(int *)(local_10[3] + 0xc) + local_20 * 0x18 + 8);
          local_14 = local_14 + 1) {
        for (local_18 = 0;
            local_18 <
            (int)(uint)*(byte *)(*(int *)(*(int *)(local_10[3] + 0xc) + local_20 * 0x18 + 4) +
                                local_14 * 0x10); local_18 = local_18 + 1) {
          (**(code **)(*(int *)(param_1 + 0x24) + 0x38))
                    (*(undefined4 *)(param_1 + 0x20),
                     *(int *)(*(int *)(*(int *)(local_10[3] + 0xc) + local_20 * 0x18 + 4) +
                              local_14 * 0x10 + 4) + local_18 * 0x34);
        }
      }
    }
    if (local_10[2] != 0) {
      (**(code **)(local_10[2] + 0x14))(local_10[4]);
    }
    puVar1 = (undefined4 *)*local_10;
    FUN_c0824790(local_10);
    local_10 = puVar1;
  }
  if (*(int *)(param_1 + 0x30) != 0) {
    FUN_c0824790(*(LPVOID *)(param_1 + 0x30));
  }
  *(undefined1 *)(param_1 + 0x34) = 0;
  *(undefined4 *)(param_1 + 0x2c) = 0;
  *(undefined4 *)(param_1 + 0xc) = 2;
  return;
}



/* c0832630 FUN_c0832630 */

/* Boundary evidence: original MIPS .pdata c0832630..c08328eb. Semantic name remains unreviewed. */

undefined4 FUN_c0832630(int param_1,byte param_2)

{
  int iVar1;
  undefined4 *puVar2;
  LPVOID pvVar3;
  int local_18;
  undefined4 local_c;
  
  iVar1 = FUN_c08328ec(param_1,param_2);
  if (iVar1 == 0) {
    DAT_c0839388 = 0;
    DAT_c083938c = &DAT_c0839388;
    for (local_18 = 0; local_18 < (int)(uint)param_2; local_18 = local_18 + 1) {
      puVar2 = FUN_c08246fc(0x110);
      if (puVar2 == (undefined4 *)0x0) {
LAB_c08328c8:
        FUN_c08329dc();
        return 7;
      }
      *puVar2 = 0;
      puVar2[1] = DAT_c083938c;
      *DAT_c083938c = puVar2;
      DAT_c083938c = puVar2;
      *(undefined1 *)(puVar2 + 0x3e) = *(undefined1 *)(param_1 + local_18 * 0x18);
      pvVar3 = FUN_c08246fc(0x1c);
      puVar2[0x41] = pvVar3;
      if (puVar2[0x41] == 0) goto LAB_c08328c8;
      FUN_c0827ba0((void *)puVar2[0x41],*(void **)(param_1 + local_18 * 0x18 + 0xc),0x1c);
      pvVar3 = FUN_c08246fc((uint)*(byte *)(param_1 + local_18 * 0x18 + 0x10) * 0xc);
      puVar2[0x43] = pvVar3;
      if (puVar2[0x43] == 0) goto LAB_c08328c8;
      FUN_c0827ba0((void *)puVar2[0x43],*(void **)(param_1 + local_18 * 0x18 + 0x14),
                   (uint)*(byte *)(param_1 + local_18 * 0x18 + 0x10) * 0xc);
      *(undefined1 *)(puVar2 + 0x42) = *(undefined1 *)(param_1 + local_18 * 0x18 + 0x10);
      puVar2[0x40] = *(undefined4 *)(param_1 + local_18 * 0x18 + 8);
    }
    DAT_c0839384 = 1;
    local_c = 0;
  }
  else {
    local_c = 10;
  }
  return local_c;
}



/* c08328ec FUN_c08328ec */

/* Boundary evidence: original MIPS .pdata c08328ec..c08329db. Semantic name remains unreviewed. */

undefined4 FUN_c08328ec(int param_1,byte param_2)

{
  int local_10;
  int local_c;
  
  local_10 = 0;
  do {
    local_c = local_10;
    if ((int)(uint)param_2 <= local_10) {
      return 0;
    }
    while (local_c = local_c + 1, local_c < (int)(uint)param_2) {
      if (*(char *)(param_1 + local_c * 0x18) == *(char *)(param_1 + local_10 * 0x18)) {
        return 1;
      }
    }
    local_10 = local_10 + 1;
  } while( true );
}



/* c08329dc FUN_c08329dc */

/* Boundary evidence: original MIPS .pdata c08329dc..c0832ac7. Semantic name remains unreviewed. */

void FUN_c08329dc(void)

{
  int *piVar1;
  
  while (piVar1 = DAT_c0839388, DAT_c0839388 != (int *)0x0) {
    if (*DAT_c0839388 == 0) {
      DAT_c083938c = DAT_c0839388[1];
    }
    else {
      *(int *)(*DAT_c0839388 + 4) = DAT_c0839388[1];
    }
    *(int *)piVar1[1] = *piVar1;
    if (piVar1[0x43] != 0) {
      FUN_c0824790((LPVOID)piVar1[0x43]);
    }
    if (piVar1[0x41] != 0) {
      FUN_c0824790((LPVOID)piVar1[0x41]);
    }
    FUN_c0824790(piVar1);
  }
  DAT_c0839384 = 0;
  return;
}



/* c0832ac8 FUN_c0832ac8 */

/* Boundary evidence: original MIPS .pdata c0832ac8..c0832b07. Semantic name remains unreviewed. */

int FUN_c0832ac8(char param_1)

{
  undefined4 *puVar1;
  int iVar2;
  
  puVar1 = FUN_c0831938(param_1);
  iVar2 = FUN_c0832b08((int)puVar1);
  return iVar2;
}



/* c0832b08 FUN_c0832b08 */

/* Boundary evidence: original MIPS .pdata c0832b08..c0832c7b. Semantic name remains unreviewed. */

int FUN_c0832b08(int param_1)

{
  int iVar1;
  int local_14;
  
  if (param_1 == 0) {
    local_14 = 10;
  }
  else if (*(int *)(param_1 + 0xc) == 4) {
    if ((*(int *)(param_1 + 0x1c) != 0) && (*(char *)(*(int *)(param_1 + 0x104) + 0xc) == '\0')) {
      iVar1 = *(int *)(param_1 + 0x104);
      *(undefined1 *)(iVar1 + 0xc) = 0xef;
      *(undefined1 *)(iVar1 + 0xd) = 2;
      *(undefined1 *)(iVar1 + 0xe) = 1;
    }
    FUN_c083888c(param_1);
    *(undefined4 *)(param_1 + 0xc) = 5;
    local_14 = (*(code *)**(undefined4 **)(param_1 + 0x24))
                         (*(undefined4 *)(param_1 + 0x20),*(undefined4 *)(param_1 + 0x100));
    if (local_14 == 0) {
      local_14 = 0;
    }
  }
  else {
    iVar1 = *(int *)(param_1 + 0xc);
    if (((iVar1 == 2) || (iVar1 == 3)) || (iVar1 != 5)) {
      local_14 = 0x10;
    }
    else {
      local_14 = 0;
    }
  }
  return local_14;
}



/* c0832c7c FUN_c0832c7c */

/* Boundary evidence: original MIPS .pdata c0832c7c..c0832caf. Semantic name remains unreviewed. */

int FUN_c0832c7c(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_c0832b08(param_1);
  return iVar1;
}



/* c0832cb0 FUN_c0832cb0 */

/* Boundary evidence: original MIPS .pdata c0832cb0..c0832ce3. Semantic name remains unreviewed. */

void FUN_c0832cb0(char param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 *puVar1;
  
  puVar1 = FUN_c0831938(param_1);
  FUN_c0832ce4((int)puVar1,param_2,param_3,param_4);
  return;
}



/* c0832ce4 FUN_c0832ce4 */

/* Boundary evidence: original MIPS .pdata c0832ce4..c0832d83. Semantic name remains unreviewed. */

void FUN_c0832ce4(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  if ((param_1 != 0) && ((*(int *)(param_1 + 0xc) == 5 || (*(int *)(param_1 + 0xc) == 6)))) {
    FUN_c0835e04(param_1,0,param_3,param_4);
    (**(code **)(*(int *)(param_1 + 0x24) + 4))(*(undefined4 *)(param_1 + 0x20));
    *(undefined4 *)(param_1 + 0xc) = 4;
  }
  return;
}



/* c0832d84 FUN_c0832d84 */

/* Boundary evidence: original MIPS .pdata c0832d84..c0832dab. Semantic name remains unreviewed. */

void FUN_c0832d84(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  FUN_c0832ce4(param_1,param_2,param_3,param_4);
  return;
}



/* c0832dac FUN_c0832dac */

/* Boundary evidence: original MIPS .pdata c0832dac..c0832fbf. Semantic name remains unreviewed. */

undefined4 FUN_c0832dac(char *param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  LPVOID pvVar2;
  undefined4 local_18;
  
  puVar1 = FUN_c0831938(*param_1);
  local_18 = 0;
  if (puVar1 == (undefined4 *)0x0) {
    local_18 = 10;
  }
  else if (puVar1[0x3d] == 0) {
    pvVar2 = FUN_c08246fc((uint)(byte)param_1[0x10] * 0xc);
    puVar1[0x3b] = pvVar2;
    if (puVar1[0x3b] == 0) {
      local_18 = 7;
    }
    else {
      pvVar2 = FUN_c08246fc(0x1c);
      puVar1[0x39] = pvVar2;
      if (puVar1[0x39] == 0) {
        local_18 = 7;
        FUN_c0824790((LPVOID)puVar1[0x3b]);
      }
      else {
        puVar1[0x3c] = puVar1[3];
        puVar1[0x3d] = 1;
        if (*(int *)(puVar1[9] + 0x18) != 0) {
          (**(code **)(puVar1[9] + 0x18))(puVar1[8]);
        }
        *(char *)(puVar1 + 0x36) = *param_1;
        FUN_c0827ba0((void *)puVar1[0x3b],*(void **)(param_1 + 0x14),(uint)(byte)param_1[0x10] * 0xc
                    );
        *(char *)(puVar1 + 0x3a) = param_1[0x10];
        FUN_c0827ba0((void *)puVar1[0x39],*(void **)(param_1 + 0xc),0x1c);
        puVar1[0x34] = param_2;
        puVar1[0x35] = param_3;
        FUN_c0826a1c((int *)puVar1[0x33],0,-0x3f7cd040,(int)puVar1);
      }
    }
  }
  else {
    local_18 = 10;
  }
  return local_18;
}



/* c0832fc0 FUN_c0832fc0 */

/* Boundary evidence: original MIPS .pdata c0832fc0..c0833127. Semantic name remains unreviewed. */

void FUN_c0832fc0(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  
  FUN_c0824790(*(LPVOID *)(param_1 + 0x10c));
  *(undefined4 *)(param_1 + 0x10c) = *(undefined4 *)(param_1 + 0xec);
  *(undefined1 *)(param_1 + 0x108) = *(undefined1 *)(param_1 + 0xe8);
  FUN_c0835e04(param_1,0,param_3,param_4);
  FUN_c08323f8(param_1);
  iVar1 = FUN_c0831df8(param_1);
  if (iVar1 == 0) {
    FUN_c0824790(*(LPVOID *)(param_1 + 0x104));
    *(undefined4 *)(param_1 + 0x104) = *(undefined4 *)(param_1 + 0xe4);
    *(undefined4 *)(param_1 + 0xc) = *(undefined4 *)(param_1 + 0xf0);
    if (*(int *)(param_1 + 0xc) == 5) {
      FUN_c083888c(param_1);
    }
    if (*(int *)(*(int *)(param_1 + 0x24) + 0x10) != 0) {
      (**(code **)(*(int *)(param_1 + 0x24) + 0x10))(*(undefined4 *)(param_1 + 0x20));
    }
  }
  *(undefined4 *)(param_1 + 0xf4) = 0;
  if (*(int *)(param_1 + 0xd0) != 0) {
    (**(code **)(param_1 + 0xd0))(*(undefined4 *)(param_1 + 0xd4),iVar1);
  }
  return;
}



/* c0833128 FUN_c0833128 */

/* Boundary evidence: original MIPS .pdata c0833128..c083314b. Semantic name remains unreviewed. */

undefined1 FUN_c0833128(int param_1)

{
  return *(undefined1 *)(param_1 + 0xf8);
}



/* c083314c FUN_c083314c */

/* Boundary evidence: original MIPS .pdata c083314c..c08331f7. Semantic name remains unreviewed. */

undefined4 FUN_c083314c(int param_1,int param_2)

{
  undefined4 local_8;
  
  if (*(int *)(param_1 + 0x18) == 2) {
    local_8 = 1;
  }
  else if (*(int *)(param_1 + 0x18) == 5) {
    if ((param_2 == 0) || (*(int *)(param_1 + 0x20) == *(int *)(param_1 + 0x1c))) {
      local_8 = 0;
    }
    else {
      local_8 = 0xffffffff;
    }
  }
  else {
    local_8 = 0xffffffff;
  }
  return local_8;
}



/* c08331f8 FUN_c08331f8 */

/* Boundary evidence: original MIPS .pdata c08331f8..c0833413. Semantic name remains unreviewed. */

int FUN_c08331f8(int *param_1,int *param_2,uint param_3,int param_4)

{
  undefined4 *puVar1;
  int local_1c;
  undefined1 *local_14;
  
  local_14 = (undefined1 *)0x0;
  puVar1 = FUN_c08246fc(8);
  if (puVar1 == (undefined4 *)0x0) {
    local_1c = 7;
  }
  else if (((short)param_1[0x34] == 0) || (param_3 <= *(ushort *)(param_1 + 0x34))) {
    if (param_1[9] == 0) {
      local_1c = 0x10;
    }
    else {
      local_14 = FUN_c083156c(*param_1,param_3,param_2);
      if (local_14 == (undefined1 *)0x0) {
        local_1c = 7;
      }
      else {
        if ((param_1[0x35] == 0) &&
           (((short)param_1[0x34] == 0 || (*(ushort *)(param_1 + 0x34) <= param_3)))) {
          *local_14 = 0;
        }
        else {
          *local_14 = 1;
        }
        *puVar1 = param_1;
        puVar1[1] = param_4;
        *(code **)(local_14 + 0x10) = FUN_c0833414;
        *(undefined4 **)(local_14 + 0x14) = puVar1;
        *(uint *)(local_14 + 0x1c) = param_3;
        local_1c = FUN_c0830ba8(*param_1,param_1[9],(int)local_14);
        if (local_1c == 0) {
          return 0;
        }
      }
    }
  }
  else {
    local_1c = 10;
  }
  if (puVar1 != (undefined4 *)0x0) {
    FUN_c0824790(puVar1);
  }
  if (local_14 != (undefined1 *)0x0) {
    FUN_c083175c(local_14);
  }
  return local_1c;
}



/* c0833414 FUN_c0833414 */

/* Boundary evidence: original MIPS .pdata c0833414..c08334af. Semantic name remains unreviewed. */

void FUN_c0833414(LPVOID param_1)

{
  undefined4 uVar1;
  int *piVar2;
  int iVar3;
  
  piVar2 = *(int **)((int)param_1 + 0x14);
  iVar3 = *piVar2;
  if (*(int *)(iVar3 + 0x98) != 0) {
    uVar1 = FUN_c083314c((int)param_1,1);
    (**(code **)(iVar3 + 0x98))
              (uVar1,*(undefined4 *)((int)param_1 + 8),*(undefined4 *)(iVar3 + 4),piVar2[1]);
  }
  FUN_c0824790(piVar2);
  FUN_c083175c(param_1);
  return;
}



/* c08334b0 FUN_c08334b0 */

/* Boundary evidence: original MIPS .pdata c08334b0..c0833673. Semantic name remains unreviewed. */

int FUN_c08334b0(int *param_1,int *param_2,uint param_3,int param_4)

{
  undefined4 *puVar1;
  int local_1c;
  LPVOID local_14;
  
  local_14 = (LPVOID)0x0;
  puVar1 = FUN_c08246fc(8);
  if (puVar1 == (undefined4 *)0x0) {
    local_1c = 7;
  }
  else if (((short)param_1[0x34] == 0) || (param_3 <= *(ushort *)(param_1 + 0x34))) {
    if (param_1[0xb] == 0) {
      local_1c = 0x10;
    }
    else {
      local_14 = FUN_c083156c(*param_1,param_3,param_2);
      if (local_14 == (LPVOID)0x0) {
        local_1c = 7;
      }
      else {
        *puVar1 = param_1;
        puVar1[1] = param_4;
        *(code **)((int)local_14 + 0x10) = FUN_c0833674;
        *(undefined4 **)((int)local_14 + 0x14) = puVar1;
        *(uint *)((int)local_14 + 0x1c) = param_3;
        local_1c = FUN_c0830fc4(*param_1,param_1[0xb],(int)local_14);
        if (local_1c == 0) {
          return 0;
        }
      }
    }
  }
  else {
    local_1c = 10;
  }
  if (puVar1 != (undefined4 *)0x0) {
    FUN_c0824790(puVar1);
  }
  if (local_14 != (LPVOID)0x0) {
    FUN_c083175c(local_14);
  }
  return local_1c;
}



/* c0833674 FUN_c0833674 */

/* Boundary evidence: original MIPS .pdata c0833674..c083378b. Semantic name remains unreviewed. */

void FUN_c0833674(LPVOID param_1)

{
  undefined4 uVar1;
  int *piVar2;
  int iVar3;
  undefined4 local_10;
  
  piVar2 = *(int **)((int)param_1 + 0x14);
  iVar3 = *piVar2;
  if (*(int *)(iVar3 + 0x94) == 0) goto LAB_c0833764;
  uVar1 = FUN_c083314c((int)param_1,0);
  if (*(uint *)((int)param_1 + 0x20) < *(uint *)((int)param_1 + 0x1c)) {
LAB_c0833714:
    local_10 = 1;
  }
  else {
    if (*(ushort *)(iVar3 + 0x46) == 0) {
      trap(0x1c00);
    }
    if (*(uint *)((int)param_1 + 0x1c) % (uint)*(ushort *)(iVar3 + 0x46) != 0) goto LAB_c0833714;
    local_10 = 0;
  }
  (**(code **)(iVar3 + 0x94))
            (uVar1,*(undefined4 *)((int)param_1 + 8),*(undefined4 *)((int)param_1 + 0x20),local_10,
             *(undefined4 *)(iVar3 + 4),piVar2[1]);
LAB_c0833764:
  FUN_c0824790(piVar2);
  FUN_c083175c(param_1);
  return;
}



/* c083378c FUN_c083378c */

/* Boundary evidence: original MIPS .pdata c083378c..c08337f3. Semantic name remains unreviewed. */

undefined4 FUN_c083378c(int *param_1)

{
  undefined4 local_c;
  
  if (param_1[9] == 0) {
    local_c = 6;
  }
  else {
    FUN_c08310c8(*param_1,param_1[9]);
    local_c = 0;
  }
  return local_c;
}



/* c08337f4 FUN_c08337f4 */

/* Boundary evidence: original MIPS .pdata c08337f4..c083385b. Semantic name remains unreviewed. */

undefined4 FUN_c08337f4(int *param_1)

{
  undefined4 local_c;
  
  if (param_1[0xb] == 0) {
    local_c = 6;
  }
  else {
    FUN_c08310c8(*param_1,param_1[0xb]);
    local_c = 0;
  }
  return local_c;
}



/* c083385c FUN_c083385c */

/* Boundary evidence: original MIPS .pdata c083385c..c083387f. Semantic name remains unreviewed. */

undefined2 FUN_c083385c(int param_1)

{
  return *(undefined2 *)(param_1 + 0x46);
}



/* c0833880 FUN_c0833880 */

/* Boundary evidence: original MIPS .pdata c0833880..c0833903. Semantic name remains unreviewed. */

LPVOID FUN_c0833880(int *param_1,uint param_2)

{
  LPVOID local_c;
  
  if (param_1 == (int *)0x0) {
    local_c = (LPVOID)0x0;
  }
  else {
    local_c = FUN_c0833904(param_1,param_1 + 0xf,(int *)0x0,param_2);
    if (local_c != (LPVOID)0x0) {
      *(char *)((int)local_c + 3) = (char)param_1[0x14];
    }
  }
  return local_c;
}



/* c0833904 FUN_c0833904 */

/* Boundary evidence: original MIPS .pdata c0833904..c0833a43. Semantic name remains unreviewed. */

LPVOID FUN_c0833904(int *param_1,undefined4 *param_2,int *param_3,uint param_4)

{
  LPVOID pvVar1;
  undefined4 local_18;
  undefined4 local_10;
  undefined4 local_c;
  
  pvVar1 = (LPVOID)*param_2;
  if ((pvVar1 == (LPVOID)0x0) || (*(int *)((int)pvVar1 + 0x18) != 1)) {
    if ((pvVar1 == (LPVOID)0x0) ||
       (*(undefined4 *)((int)pvVar1 + 0x18) = 0, local_18 = pvVar1,
       *(uint *)((int)pvVar1 + 0xc) < param_4)) {
      local_c = param_4;
      if (param_4 == 0) {
        local_c = 10;
      }
      local_18 = FUN_c083156c(*param_1,local_c,param_3);
      if (local_18 == (LPVOID)0x0) goto LAB_c0833a28;
      if (pvVar1 != (LPVOID)0x0) {
        FUN_c083175c(pvVar1);
      }
      *param_2 = local_18;
    }
    *(uint *)((int)local_18 + 0x1c) = param_4;
    local_10 = local_18;
  }
  else {
LAB_c0833a28:
    local_10 = (LPVOID)0x0;
  }
  return local_10;
}



/* c0833a44 FUN_c0833a44 */

/* Boundary evidence: original MIPS .pdata c0833a44..c0833b3b. Semantic name remains unreviewed. */

undefined1 * FUN_c0833a44(int *param_1,void *param_2,uint param_3,uint param_4)

{
  undefined1 *local_10;
  
  local_10 = (undefined1 *)0x0;
  if ((param_1 != (int *)0x0) &&
     (local_10 = FUN_c0833904(param_1,param_1 + 0x10,(int *)0x0,param_3),
     local_10 != (undefined1 *)0x0)) {
    if ((param_2 != (void *)0x0) && (param_3 != 0)) {
      FUN_c0827ba0((void *)**(undefined4 **)(param_1[0x10] + 8),param_2,param_3);
    }
    if (param_3 < param_4) {
      *local_10 = 1;
    }
    else {
      *local_10 = 0;
    }
  }
  local_10[3] = (char)param_1[0x14];
  return local_10;
}



/* c0833b3c FUN_c0833b3c */

/* Boundary evidence: original MIPS .pdata c0833b3c..c0833bc7. Semantic name remains unreviewed. */

int FUN_c0833b3c(int *param_1)

{
  undefined1 *puVar1;
  int local_18;
  
  puVar1 = FUN_c0833a44(param_1,(void *)0x0,0,0);
  if (puVar1 == (undefined1 *)0x0) {
    local_18 = 7;
  }
  else {
    *(undefined4 *)(puVar1 + 0x10) = 0;
    *(undefined4 *)(puVar1 + 0x14) = 0;
    local_18 = FUN_c0830ba8(*param_1,0,(int)puVar1);
  }
  return local_18;
}



/* c0833bc8 FUN_c0833bc8 */

/* Boundary evidence: original MIPS .pdata c0833bc8..c0833cf3. Semantic name remains unreviewed. */

int FUN_c0833bc8(int *param_1,int param_2)

{
  LPVOID pvVar1;
  int iVar2;
  int local_20;
  
  local_20 = 10;
  if (((uint)*(ushort *)(param_2 + 6) <= (uint)param_1[0x33]) && (param_1[0x23] != 0)) {
    if (param_1[0x15] != 0) {
      FUN_c08341bc(param_1);
    }
    pvVar1 = FUN_c0833880(param_1,(uint)*(ushort *)(param_2 + 6));
    if (pvVar1 != (LPVOID)0x0) {
      *(code **)((int)pvVar1 + 0x10) = FUN_c0833cf4;
      *(int **)((int)pvVar1 + 0x14) = param_1;
      iVar2 = FUN_c0830fc4(*param_1,0,(int)pvVar1);
      return iVar2;
    }
    local_20 = 7;
  }
  return local_20;
}



/* c0833cf4 FUN_c0833cf4 */

/* Boundary evidence: original MIPS .pdata c0833cf4..c0833dd7. Semantic name remains unreviewed. */

void FUN_c0833cf4(int param_1)

{
  int iVar1;
  int *piVar2;
  
  piVar2 = *(int **)(param_1 + 0x14);
  iVar1 = FUN_c083314c(param_1,1);
  if (((iVar1 != 0) ||
      (iVar1 = (*(code *)piVar2[0x23])
                         (*(undefined4 *)(param_1 + 8),*(uint *)(param_1 + 0x20) & 0xffff,piVar2[1])
      , iVar1 != 0)) || (iVar1 = FUN_c0833b3c(piVar2), iVar1 != 0)) {
    FUN_c083106c(*piVar2,(char)piVar2[0x14]);
  }
  return;
}



/* c0833dd8 FUN_c0833dd8 */

/* Boundary evidence: original MIPS .pdata c0833dd8..c0833f67. Semantic name remains unreviewed. */

int FUN_c0833dd8(int *param_1,int param_2)

{
  undefined1 *puVar1;
  uint uVar2;
  int local_28;
  int local_1c;
  uint local_10;
  
  local_1c = param_1[0x18];
  uVar2 = (uint)*(ushort *)(param_2 + 6);
  if (param_1[0x15] == 0) {
    local_1c = 0;
  }
  local_10 = uVar2;
  if ((uint)(param_1[0x19] - param_1[0x1a]) < uVar2) {
    local_10 = param_1[0x19] - param_1[0x1a];
  }
  puVar1 = FUN_c0833a44(param_1,(void *)(local_1c + param_1[0x1a]),local_10,uVar2);
  if (puVar1 == (undefined1 *)0x0) {
    local_28 = 7;
  }
  else {
    if (local_1c == 0) {
      param_1[0x17] = 1;
      puVar1[2] = 1;
    }
    *(code **)(puVar1 + 0x10) = FUN_c0833f68;
    *(int **)(puVar1 + 0x14) = param_1;
    local_28 = FUN_c0830ba8(*param_1,0,(int)puVar1);
    if (local_28 == 0) {
      return 0;
    }
  }
  FUN_c083518c((int)param_1,1,0xffffffff);
  param_1[0x17] = 0;
  return local_28;
}



/* c0833f68 FUN_c0833f68 */

/* Boundary evidence: original MIPS .pdata c0833f68..c0834083. Semantic name remains unreviewed. */

void FUN_c0833f68(int param_1)

{
  int iVar1;
  int local_c;
  
  iVar1 = *(int *)(param_1 + 0x14);
  if (*(int *)(iVar1 + 0x5c) == 0) {
    *(int *)(iVar1 + 0x68) = *(int *)(iVar1 + 0x68) + *(int *)(param_1 + 0x20);
    local_c = FUN_c083314c(param_1,1);
    if (local_c == 0) {
      if (*(int *)(iVar1 + 0x54) == 1) {
        if (*(uint *)(iVar1 + 0x68) < *(uint *)(iVar1 + 100)) {
          return;
        }
      }
      else {
        local_c = -1;
      }
    }
    FUN_c083518c(iVar1,1,local_c);
  }
  else {
    if (*(int *)(iVar1 + 100) == 0) {
      *(undefined4 *)(iVar1 + 0x54) = 0;
    }
    else {
      *(undefined4 *)(iVar1 + 0x54) = 1;
    }
    *(undefined4 *)(iVar1 + 0x5c) = 0;
  }
  return;
}



/* c0834084 FUN_c0834084 */

/* Boundary evidence: original MIPS .pdata c0834084..c08341bb. Semantic name remains unreviewed. */

undefined1 *
FUN_c0834084(int *param_1,undefined1 param_2,undefined2 param_3,undefined2 param_4,ushort param_5,
            void *param_6)

{
  undefined1 *puVar1;
  undefined1 *local_10;
  
  if (param_1 == (int *)0x0) {
    local_10 = (undefined1 *)0x0;
  }
  else {
    local_10 = FUN_c083156c(*param_1,param_5 + 8,(int *)0x0);
    if (local_10 == (undefined1 *)0x0) {
      local_10 = (undefined1 *)0x0;
    }
    else {
      *local_10 = 0;
      *(uint *)(local_10 + 0x1c) = param_5 + 8;
      puVar1 = (undefined1 *)**(undefined4 **)(local_10 + 8);
      *puVar1 = 0xa1;
      puVar1[1] = param_2;
      *(undefined2 *)(puVar1 + 2) = param_3;
      *(undefined2 *)(puVar1 + 4) = param_4;
      *(ushort *)(puVar1 + 6) = param_5;
      if ((param_5 != 0) && (param_6 != (void *)0x0)) {
        FUN_c0827ba0(puVar1 + 8,param_6,(uint)param_5);
      }
    }
  }
  return local_10;
}



/* c08341bc FUN_c08341bc */

/* Boundary evidence: original MIPS .pdata c08341bc..c08342d7. Semantic name remains unreviewed. */

int FUN_c08341bc(int *param_1)

{
  undefined1 *puVar1;
  int local_20;
  
  local_20 = 0;
  if (param_1[0xd] == 0) {
    local_20 = 6;
  }
  else if (param_1[0x16] == 0) {
    puVar1 = FUN_c0834084(param_1,1,0,(short)param_1[0xe],0,(void *)0x0);
    if (puVar1 == (undefined1 *)0x0) {
      local_20 = 7;
    }
    else {
      *(code **)(puVar1 + 0x10) = FUN_c08342d8;
      *(int **)(puVar1 + 0x14) = param_1;
      local_20 = FUN_c0830ba8(*param_1,param_1[0xd],(int)puVar1);
      if (local_20 == 0) {
        param_1[0x16] = 1;
      }
      else {
        FUN_c083175c(puVar1);
      }
    }
  }
  return local_20;
}



/* c08342d8 FUN_c08342d8 */

/* Boundary evidence: original MIPS .pdata c08342d8..c0834313. Semantic name remains unreviewed. */

void FUN_c08342d8(LPVOID param_1)

{
  *(undefined4 *)(*(int *)((int)param_1 + 0x14) + 0x58) = 0;
  FUN_c083175c(param_1);
  return;
}



/* c0834314 FUN_c0834314 */

/* Boundary evidence: original MIPS .pdata c0834314..c0834467. Semantic name remains unreviewed. */

int FUN_c0834314(int *param_1,void *param_2,size_t param_3)

{
  LPVOID pvVar1;
  int local_18;
  
  if ((param_1[0x19] != 0) && (param_1[0x15] != 0)) {
    FUN_c08341bc(param_1);
    return 8;
  }
  if (param_1[0x18] == 0) {
    pvVar1 = FUN_c08246fc(param_1[0x33]);
    param_1[0x18] = (int)pvVar1;
    if (param_1[0x18] == 0) {
      local_18 = 7;
      goto LAB_c0834438;
    }
  }
  FUN_c0827ba0((void *)param_1[0x18],param_2,param_3);
  param_1[0x19] = param_3;
  param_1[0x1a] = 0;
  param_1[0x15] = 1;
  local_18 = FUN_c08341bc(param_1);
  if (local_18 == 0) {
    return 0;
  }
LAB_c0834438:
  FUN_c083518c((int)param_1,0,0);
  return local_18;
}



/* c0834468 FUN_c0834468 */

/* Boundary evidence: original MIPS .pdata c0834468..c08344b7. Semantic name remains unreviewed. */

void FUN_c0834468(int param_1)

{
  if ((param_1 != 0) && (*(int *)(param_1 + 0x20) != 0)) {
    FUN_c0824790(*(LPVOID *)(param_1 + 0x20));
    *(undefined4 *)(param_1 + 0x20) = 0;
  }
  return;
}



/* c08344b8 FUN_c08344b8 */

/* Boundary evidence: original MIPS .pdata c08344b8..c083454f. Semantic name remains unreviewed. */

undefined4 FUN_c08344b8(int *param_1,undefined4 *param_2)

{
  undefined4 local_10;
  undefined4 local_c;
  
  if ((param_1 == (int *)0x0) || (param_1[8] != 0)) {
    local_c = 10;
  }
  else {
    if (param_2[6] == 0) {
      local_10 = FUN_c0834acc(param_1,param_2);
    }
    else {
      local_10 = FUN_c0834550((int)param_1,param_2);
    }
    local_c = local_10;
  }
  return local_c;
}



/* c0834550 FUN_c0834550 */

/* Boundary evidence: original MIPS .pdata c0834550..c0834a83. Semantic name remains unreviewed. */

undefined4 FUN_c0834550(int param_1,undefined4 *param_2)

{
  undefined2 uVar1;
  undefined4 *puVar2;
  char *pcVar3;
  char *pcVar4;
  undefined4 local_48;
  int local_44;
  char local_3c;
  char *local_38;
  SIZE_T local_20;
  int local_10;
  
  local_44 = 0;
  if (param_2[4] == 0) {
    local_10 = 1;
  }
  else {
    local_10 = 2;
  }
  local_48 = 7;
  local_20 = local_10 * 0x10 + 0x2c;
  if (param_2[5] != 0) {
    local_44 = (*(code *)param_2[5])(param_1,0,1);
    local_20 = local_20 + local_44;
  }
  if (param_2[2] != 0) {
    local_20 = local_20 + 0x34;
  }
  if (param_2[3] != 0) {
    local_20 = local_20 + 0x68;
  }
  puVar2 = FUN_c08246fc(local_20);
  if (puVar2 != (undefined4 *)0x0) {
    pcVar3 = (char *)(puVar2 + 5);
    local_3c = param_2[2] != 0;
    if ((bool)local_3c) {
      pcVar3[0] = '@';
      pcVar3[1] = '\0';
      *(undefined2 *)((int)puVar2 + 0x16) = 0x40;
      puVar2[6] = 3;
      *(undefined1 *)(puVar2 + 7) = 0;
      *(undefined1 *)((int)puVar2 + 0x1d) = 0;
      *(undefined1 *)((int)puVar2 + 0x1e) = 0;
      *(undefined1 *)((int)puVar2 + 0x1f) = 0;
      *(undefined1 *)(puVar2 + 8) = 0;
      *(undefined1 *)((int)puVar2 + 0x21) = 5;
      *(undefined1 *)((int)puVar2 + 0x22) = 1;
    }
    local_38 = pcVar3;
    if (param_2[3] != 0) {
      pcVar4 = pcVar3 + (uint)(byte)local_3c * 0x34;
      local_38 = pcVar4 + 0x68;
      uVar1 = FUN_c0834a84(3);
      *(undefined2 *)pcVar4 = uVar1;
      uVar1 = FUN_c0834a84(2);
      *(undefined2 *)(pcVar4 + 2) = uVar1;
      pcVar4[4] = '\x02';
      pcVar4[5] = '\0';
      pcVar4[6] = '\0';
      pcVar4[7] = '\0';
      pcVar4[8] = '\0';
      pcVar4[9] = '\0';
      pcVar4[10] = '\0';
      pcVar4[0xb] = '\0';
      pcVar4[0xc] = '\0';
      pcVar4[0xd] = ' ';
      pcVar4[0xe] = '\x01';
      uVar1 = FUN_c0834a84(3);
      *(undefined2 *)(pcVar4 + 0x34) = uVar1;
      uVar1 = FUN_c0834a84(2);
      *(undefined2 *)(pcVar4 + 0x36) = uVar1;
      pcVar4[0x38] = '\x02';
      pcVar4[0x39] = '\0';
      pcVar4[0x3a] = '\0';
      pcVar4[0x3b] = '\0';
      pcVar4[0x3c] = '\x01';
      pcVar4[0x3d] = '\0';
      pcVar4[0x3e] = '\0';
      pcVar4[0x3f] = '\0';
      pcVar4[0x40] = '\0';
      pcVar4[0x41] = ' ';
      pcVar4[0x42] = '\x01';
      local_3c = local_3c + '\x02';
    }
    pcVar4 = local_38 + local_10 * 0x10;
    if (param_2[4] == 0) {
      *local_38 = local_3c;
      *(char **)(local_38 + 4) = pcVar3;
    }
    else {
      if (param_2[2] == 0) {
        *local_38 = '\0';
        local_38[4] = '\0';
        local_38[5] = '\0';
        local_38[6] = '\0';
        local_38[7] = '\0';
      }
      else {
        *local_38 = '\x01';
        *(char **)(local_38 + 4) = pcVar3;
      }
      local_38[0x10] = local_3c;
      *(char **)(local_38 + 0x14) = pcVar3;
    }
    *(undefined4 *)pcVar4 = *param_2;
    *(char **)(pcVar4 + 4) = local_38;
    pcVar4[8] = (char)local_10;
    pcVar4[9] = '\0';
    pcVar4[0xc] = '\0';
    pcVar4[0xd] = '\0';
    pcVar4[0xe] = '\0';
    pcVar4[0xf] = '\0';
    pcVar4[0x10] = '\0';
    pcVar4[0x11] = '\0';
    pcVar4[0x12] = '\0';
    if (*(char *)(param_2 + 1) == '\0') {
      pcVar4[0x13] = -1;
      pcVar4[0x14] = -1;
      pcVar4[0x15] = -1;
    }
    else {
      pcVar4[0x13] = '\x02';
      pcVar4[0x14] = *(char *)(param_2 + 1);
      pcVar4[0x15] = *(char *)((int)param_2 + 5);
    }
    if (param_2[5] != 0) {
      (*(code *)param_2[5])(param_1,pcVar4 + 0x18,1);
      *(char **)(pcVar4 + 0xc) = pcVar4 + 0x18;
      *(short *)(pcVar4 + 0x10) = (short)local_44;
    }
    *puVar2 = 3;
    *(undefined1 *)(puVar2 + 2) = 1;
    puVar2[3] = pcVar4;
    puVar2[4] = 0;
    *(undefined4 **)(param_1 + 0x20) = puVar2;
    local_48 = 0;
  }
  return local_48;
}



/* c0834a84 FUN_c0834a84 */

/* Boundary evidence: original MIPS .pdata c0834a84..c0834acb. Semantic name remains unreviewed. */

undefined2 FUN_c0834a84(int param_1)

{
  undefined2 local_8;
  
  if (param_1 == 3) {
    local_8 = 0x200;
  }
  else {
    local_8 = 0x40;
  }
  return local_8;
}



/* c0834acc FUN_c0834acc */

/* WARNING: Removing unreachable block (ram,0xc0835164) */
/* Boundary evidence: original MIPS .pdata c0834acc..c083518b. Semantic name remains unreviewed. */

undefined4 FUN_c0834acc(int *param_1,undefined4 *param_2)

{
  undefined1 uVar1;
  undefined2 uVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  int local_50;
  undefined4 *local_44;
  undefined4 *local_40;
  SIZE_T local_38;
  undefined4 *local_34;
  undefined4 *local_24;
  undefined4 local_20;
  int local_1c;
  undefined4 *local_18;
  undefined4 *local_10;
  
  local_24 = (undefined4 *)0x0;
  local_44 = (undefined4 *)0x0;
  local_50 = 0;
  if (param_2[4] == 0) {
    local_1c = 1;
  }
  else {
    local_1c = 2;
  }
  local_38 = 0x3c;
  if (param_2[5] != 0) {
    local_50 = (*(code *)param_2[5])(param_1,0,0);
    local_38 = local_50 + 0x3c;
  }
  if (param_2[2] != 0) {
    local_38 = local_38 + 0x34;
  }
  if (param_2[3] != 0) {
    local_38 = local_38 + local_1c * 0x10 + 0x88;
  }
  puVar3 = FUN_c08246fc(local_38);
  if (puVar3 == (undefined4 *)0x0) {
    local_20 = 7;
  }
  else {
    puVar4 = puVar3 + 5;
    local_40 = puVar4;
    if (param_2[3] != 0) {
      local_40 = puVar3 + 7;
      *(undefined1 *)puVar4 = 8;
      *(undefined1 *)((int)puVar3 + 0x15) = 0xb;
      uVar1 = FUN_c0831540(*param_1);
      *(undefined1 *)((int)puVar3 + 0x16) = uVar1;
      *(undefined1 *)((int)puVar3 + 0x17) = 2;
      *(undefined1 *)(puVar3 + 6) = 2;
      *(undefined1 *)((int)puVar3 + 0x19) = 0;
      *(undefined1 *)((int)puVar3 + 0x1a) = 0;
      *(undefined1 *)((int)puVar3 + 0x1b) = 0;
      local_44 = puVar4;
    }
    if (param_2[2] == 0) {
      local_34 = local_40;
      *(undefined1 *)local_40 = 0;
      local_40[1] = 0;
      local_40 = local_40 + 4;
    }
    else {
      local_34 = local_40 + 0xd;
      *(undefined2 *)local_40 = 0x40;
      *(undefined2 *)((int)local_40 + 2) = 0x40;
      local_40[1] = 3;
      *(undefined1 *)(local_40 + 2) = 0;
      *(undefined1 *)((int)local_40 + 9) = 0;
      *(undefined1 *)((int)local_40 + 10) = 0;
      *(undefined1 *)((int)local_40 + 0xb) = 0;
      *(undefined1 *)(local_40 + 3) = 0;
      *(undefined1 *)((int)local_40 + 0xd) = 5;
      *(undefined1 *)((int)local_40 + 0xe) = 0;
      *(undefined1 *)local_34 = 1;
      local_40[0xe] = local_40;
      local_40 = local_40 + 0x11;
    }
    if (param_2[3] != 0) {
      local_24 = local_40 + 0x1a;
      uVar2 = FUN_c0834a84(3);
      *(undefined2 *)local_40 = uVar2;
      uVar2 = FUN_c0834a84(2);
      *(undefined2 *)((int)local_40 + 2) = uVar2;
      local_40[1] = 2;
      *(undefined1 *)(local_40 + 2) = 0;
      *(undefined1 *)((int)local_40 + 9) = 0;
      *(undefined1 *)((int)local_40 + 10) = 0;
      *(undefined1 *)((int)local_40 + 0xb) = 0;
      *(undefined1 *)(local_40 + 3) = 0;
      *(undefined1 *)((int)local_40 + 0xd) = 0x20;
      *(undefined1 *)((int)local_40 + 0xe) = 1;
      uVar2 = FUN_c0834a84(3);
      *(undefined2 *)(local_40 + 0xd) = uVar2;
      uVar2 = FUN_c0834a84(2);
      *(undefined2 *)((int)local_40 + 0x36) = uVar2;
      local_40[0xe] = 2;
      *(undefined1 *)(local_40 + 0xf) = 1;
      *(undefined1 *)((int)local_40 + 0x3d) = 0;
      *(undefined1 *)((int)local_40 + 0x3e) = 0;
      *(undefined1 *)((int)local_40 + 0x3f) = 0;
      *(undefined1 *)(local_40 + 0x10) = 0;
      *(undefined1 *)((int)local_40 + 0x41) = 0x20;
      *(undefined1 *)((int)local_40 + 0x42) = 1;
      if (param_2[4] == 0) {
        *(undefined1 *)local_24 = 2;
        local_40[0x1b] = local_40;
        local_40 = local_24 + local_1c * 4;
      }
      else {
        *(undefined1 *)local_24 = 0;
        local_40[0x1b] = 0;
        *(undefined1 *)(local_40 + 0x1e) = 2;
        local_40[0x1f] = local_40;
        local_40 = local_24 + local_1c * 4;
      }
    }
    if (param_2[3] == 0) {
      local_18 = local_40 + 6;
    }
    else {
      local_18 = local_40 + 0xc;
    }
    *local_40 = *param_2;
    local_40[1] = local_34;
    *(undefined1 *)(local_40 + 2) = 1;
    *(undefined1 *)((int)local_40 + 9) = 0;
    local_40[3] = 0;
    *(undefined2 *)(local_40 + 4) = 0;
    *(undefined1 *)((int)local_40 + 0x12) = 0;
    if (*(char *)(param_2 + 1) == '\0') {
      *(undefined1 *)((int)local_40 + 0x13) = 0xff;
      *(undefined1 *)(local_40 + 5) = 0xff;
      *(undefined1 *)((int)local_40 + 0x15) = 0xff;
    }
    else {
      *(undefined1 *)((int)local_40 + 0x13) = 2;
      *(undefined1 *)(local_40 + 5) = *(undefined1 *)(param_2 + 1);
      *(undefined1 *)((int)local_40 + 0x15) = *(undefined1 *)((int)param_2 + 5);
    }
    if (param_2[3] != 0) {
      local_40[6] = *param_2;
      local_40[7] = local_24;
      *(char *)(local_40 + 8) = (char)local_1c;
      *(undefined1 *)((int)local_40 + 0x21) = 0;
      local_40[9] = 0;
      *(undefined2 *)(local_40 + 10) = 0;
      *(undefined1 *)((int)local_40 + 0x2a) = 0;
      *(undefined1 *)((int)local_40 + 0x2b) = 10;
      *(undefined1 *)(local_40 + 0xb) = 0;
      *(undefined1 *)((int)local_40 + 0x2d) = 0;
    }
    if (param_2[5] != 0) {
      (*(code *)param_2[5])(param_1,local_18,0);
      local_40[3] = local_18;
      *(short *)(local_40 + 4) = (short)local_50;
    }
    *puVar3 = 3;
    if (param_2[3] == 0) {
      uVar1 = 1;
    }
    else {
      uVar1 = 2;
    }
    *(undefined1 *)(puVar3 + 2) = uVar1;
    puVar3[3] = local_40;
    if (param_2[3] == 0) {
      local_10 = (undefined4 *)0x0;
    }
    else {
      local_10 = local_44;
    }
    puVar3[4] = local_10;
    param_1[8] = (int)puVar3;
    local_20 = 0;
  }
  return local_20;
}



/* c083518c FUN_c083518c */

/* Boundary evidence: original MIPS .pdata c083518c..c0835223. Semantic name remains unreviewed. */

void FUN_c083518c(int param_1,int param_2,undefined4 param_3)

{
  undefined4 uVar1;
  undefined4 local_res4;
  
  local_res4 = param_2;
  if (*(int *)(param_1 + 0x54) == 0) {
    local_res4 = 0;
  }
  *(undefined4 *)(param_1 + 0x54) = 0;
  *(undefined4 *)(param_1 + 100) = 0;
  uVar1 = *(undefined4 *)(param_1 + 0x68);
  *(undefined4 *)(param_1 + 0x68) = 0;
  if ((local_res4 != 0) && (*(int *)(param_1 + 0x90) != 0)) {
    (**(code **)(param_1 + 0x90))(param_3,uVar1,*(undefined4 *)(param_1 + 4));
  }
  return;
}



/* c0835224 FUN_c0835224 */

/* Boundary evidence: original MIPS .pdata c0835224..c08354f7. Semantic name remains unreviewed. */

undefined4 FUN_c0835224(int param_1)

{
  bool bVar1;
  byte bVar2;
  undefined2 uVar3;
  int iVar4;
  bool local_1c;
  bool local_1b;
  undefined4 local_10;
  
  if ((param_1 == 0) || (*(int *)(param_1 + 0x20) == 0)) {
    local_10 = 10;
  }
  else {
    bVar1 = (*(ushort *)(param_1 + 200) & 1) != 0;
    local_1b = !bVar1;
    local_1c = bVar1;
    if (*(char *)(*(int *)(param_1 + 0x20) + 8) != '\0') {
      bVar2 = *(byte *)(*(int *)(*(int *)(param_1 + 0x20) + 0xc) + 9);
      iVar4 = *(int *)(*(int *)(param_1 + 0x20) + 0xc);
      *(ushort *)(param_1 + 0x38) = (ushort)*(byte *)(iVar4 + 0x12);
      if (((bVar1) && (*(int *)(*(int *)(iVar4 + 4) + (uint)bVar2 * 0x10 + 4) != 0)) &&
         (*(int *)(*(int *)(*(int *)(iVar4 + 4) + (uint)bVar2 * 0x10 + 4) + 4) != 3)) {
        *(undefined4 *)(param_1 + 0x34) = 0;
        local_1c = false;
      }
      else {
        *(undefined4 *)(param_1 + 0x34) =
             *(undefined4 *)(*(int *)(iVar4 + 4) + (uint)bVar2 * 0x10 + 4);
      }
    }
    if ((1 < *(byte *)(*(int *)(param_1 + 0x20) + 8)) || (bVar1)) {
      bVar2 = *(byte *)(*(int *)(*(int *)(param_1 + 0x20) + 0xc) + (uint)local_1b * 0x18 + 9);
      iVar4 = *(int *)(*(int *)(param_1 + 0x20) + 0xc) + (uint)local_1b * 0x18;
      if (*(char *)(*(int *)(iVar4 + 4) + (uint)bVar2 * 0x10) != '\0') {
        *(ushort *)(param_1 + 0x28) = (ushort)*(byte *)(iVar4 + 0x12);
        *(uint *)(param_1 + 0x24) =
             *(int *)(*(int *)(iVar4 + 4) + (uint)bVar2 * 0x10 + 4) + (uint)local_1c * 0x34;
      }
      if (1 < *(byte *)(*(int *)(iVar4 + 4) + (uint)bVar2 * 0x10)) {
        *(ushort *)(param_1 + 0x30) = (ushort)*(byte *)(iVar4 + 0x12);
        *(uint *)(param_1 + 0x2c) =
             *(int *)(*(int *)(iVar4 + 4) + (uint)bVar2 * 0x10 + 4) + (local_1c + 1) * 0x34;
      }
    }
    uVar3 = FUN_c0834a84(*(int *)(*(int *)(param_1 + 0x20) + 4));
    *(undefined2 *)(param_1 + 0x46) = uVar3;
    local_10 = 0;
  }
  return local_10;
}



/* c08354f8 FUN_c08354f8 */

/* Boundary evidence: original MIPS .pdata c08354f8..c083556b. Semantic name remains unreviewed. */

void FUN_c08354f8(int *param_1)

{
  FUN_c083518c((int)param_1,1,1);
  FUN_c083556c(param_1);
  param_1[0xd] = 0;
  *(undefined2 *)(param_1 + 0xe) = 0;
  param_1[9] = 0;
  *(undefined2 *)(param_1 + 10) = 0;
  param_1[0xb] = 0;
  *(undefined2 *)(param_1 + 0xc) = 0;
  *(undefined2 *)((int)param_1 + 0x46) = 0;
  return;
}



/* c083556c FUN_c083556c */

/* Boundary evidence: original MIPS .pdata c083556c..c08355ff. Semantic name remains unreviewed. */

void FUN_c083556c(int *param_1)

{
  if (param_1[0xd] != 0) {
    FUN_c08310c8(*param_1,param_1[0xd]);
  }
  if (param_1[9] != 0) {
    FUN_c08310c8(*param_1,param_1[9]);
  }
  if (param_1[0xb] != 0) {
    FUN_c08310c8(*param_1,param_1[0xb]);
  }
  return;
}



/* c0835600 FUN_c0835600 */

/* Boundary evidence: original MIPS .pdata c0835600..c08356f7. Semantic name remains unreviewed. */

undefined4 FUN_c0835600(LPVOID param_1)

{
  if (param_1 != (LPVOID)0x0) {
    if ((param_1 != (LPVOID)0x0) && (*(int *)((int)param_1 + 0x80) != 0)) {
      (**(code **)((int)param_1 + 0x80))(*(undefined4 *)((int)param_1 + 4));
    }
    if (*(int *)((int)param_1 + 0x3c) != 0) {
      FUN_c083175c(*(LPVOID *)((int)param_1 + 0x3c));
    }
    if (*(int *)((int)param_1 + 0x40) != 0) {
      FUN_c083175c(*(LPVOID *)((int)param_1 + 0x40));
    }
    if (*(int *)((int)param_1 + 0x60) != 0) {
      FUN_c0824790(*(LPVOID *)((int)param_1 + 0x60));
    }
    FUN_c0834468((int)param_1);
    FUN_c0824790(param_1);
  }
  return 0;
}



/* c08356f8 FUN_c08356f8 */

/* Boundary evidence: original MIPS .pdata c08356f8..c08357ff. Semantic name remains unreviewed. */

int FUN_c08356f8(int *param_1)

{
  int iVar1;
  
  if (param_1[2] == 0) {
    param_1[2] = (int)FUN_c0835800;
  }
  if (param_1[3] == 0) {
    param_1[3] = (int)FUN_c083582c;
  }
  if (param_1[4] == 0) {
    param_1[4] = (int)FUN_c08358ec;
  }
  if (param_1[5] == 0) {
    param_1[5] = (int)FUN_c0835970;
  }
  if (param_1[6] == 0) {
    param_1[6] = (int)FUN_c08359f0;
  }
  if (param_1[7] == 0) {
    param_1[7] = (int)FUN_c0835600;
  }
  iVar1 = FUN_c0831198(*param_1,param_1 + 2,param_1);
  return iVar1;
}



/* c0835800 FUN_c0835800 */

/* Boundary evidence: original MIPS .pdata c0835800..c083582b. Semantic name remains unreviewed. */

undefined4 FUN_c0835800(int param_1)

{
  return *(undefined4 *)(param_1 + 0x20);
}



/* c083582c FUN_c083582c */

/* Boundary evidence: original MIPS .pdata c083582c..c08358eb. Semantic name remains unreviewed. */

int FUN_c083582c(int param_1)

{
  int local_18;
  int local_10;
  
  if (param_1 == 0) {
    local_10 = 10;
  }
  else {
    local_18 = FUN_c0835224(param_1);
    local_10 = local_18;
    if (local_18 == 0) {
      if ((*(int *)(param_1 + 0x78) != 0) &&
         (local_18 = (**(code **)(param_1 + 0x78))(*(undefined4 *)(param_1 + 4)), local_18 == 0)) {
        *(undefined1 *)(param_1 + 0x44) = 1;
      }
      local_10 = local_18;
    }
  }
  return local_10;
}



/* c08358ec FUN_c08358ec */

/* Boundary evidence: original MIPS .pdata c08358ec..c083596f. Semantic name remains unreviewed. */

void FUN_c08358ec(int *param_1)

{
  if (param_1 != (int *)0x0) {
    if ((param_1[0x1f] != 0) && ((char)param_1[0x11] != '\0')) {
      *(undefined1 *)(param_1 + 0x11) = 0;
      (*(code *)param_1[0x1f])(param_1[1]);
    }
    FUN_c08354f8(param_1);
  }
  return;
}



/* c0835970 FUN_c0835970 */

/* Boundary evidence: original MIPS .pdata c0835970..c08359ef. Semantic name remains unreviewed. */

undefined4 FUN_c0835970(int *param_1)

{
  undefined4 local_18;
  
  local_18 = 0;
  if (param_1[0x21] != 0) {
    local_18 = (*(code *)param_1[0x21])(param_1[1]);
  }
  FUN_c083518c((int)param_1,1,1);
  FUN_c083556c(param_1);
  return local_18;
}



/* c08359f0 FUN_c08359f0 */

/* Boundary evidence: original MIPS .pdata c08359f0..c0835a4f. Semantic name remains unreviewed. */

undefined4 FUN_c08359f0(int param_1)

{
  undefined4 local_18;
  
  local_18 = 0;
  if (*(int *)(param_1 + 0x88) != 0) {
    local_18 = (**(code **)(param_1 + 0x88))(*(undefined4 *)(param_1 + 4));
  }
  return local_18;
}



/* c0835a50 FUN_c0835a50 */

/* Boundary evidence: original MIPS .pdata c0835a50..c0835aa3. Semantic name remains unreviewed. */

void FUN_c0835a50(int *param_1,LPVOID param_2)

{
  FUN_c08233ac(param_1);
  FUN_c0826948(*(LPVOID *)((int)param_2 + 8));
  FUN_c0824790(param_2);
  return;
}



/* c0835aa4 FUN_c0835aa4 */

/* Boundary evidence: original MIPS .pdata c0835aa4..c0835bef. Semantic name remains unreviewed. */

int FUN_c0835aa4(int *param_1,int param_2,int param_3,undefined4 param_4,undefined4 param_5,
                undefined4 *param_6)

{
  undefined4 *puVar1;
  int local_18;
  
  puVar1 = FUN_c08246fc(0xc);
  if (puVar1 == (undefined4 *)0x0) {
    local_18 = 7;
  }
  else {
    local_18 = FUN_c0826874(puVar1 + 2,0);
    if (local_18 == 0) {
      *puVar1 = param_4;
      puVar1[1] = param_5;
      local_18 = FUN_c0822e18(param_1,param_2,param_3,-0x3f7ca410,(int)puVar1);
      if (local_18 == 0) {
        *param_6 = puVar1;
        return 0;
      }
    }
  }
  if ((puVar1 != (undefined4 *)0x0) && (puVar1[2] != 0)) {
    FUN_c0826948((LPVOID)puVar1[2]);
  }
  if (puVar1 != (undefined4 *)0x0) {
    FUN_c0824790(puVar1);
  }
  *param_6 = 0;
  return local_18;
}



/* c0835bf0 FUN_c0835bf0 */

/* Boundary evidence: original MIPS .pdata c0835bf0..c0835c4f. Semantic name remains unreviewed. */

void FUN_c0835bf0(int *param_1)

{
  if (*param_1 != 0) {
    FUN_c0826a1c((int *)param_1[2],0,*param_1,param_1[1]);
  }
  return;
}



/* c0835c50 FUN_c0835c50 */

/* Boundary evidence: original MIPS .pdata c0835c50..c0835c7b. Semantic name remains unreviewed. */

void FUN_c0835c50(int param_1,undefined1 param_2)

{
  *(undefined1 *)(param_1 + 0xc0) = param_2;
  return;
}



/* c0835c7c FUN_c0835c7c */

/* Boundary evidence: original MIPS .pdata c0835c7c..c0835d5f. Semantic name remains unreviewed. */

char FUN_c0835c7c(int param_1,int param_2)

{
  undefined1 local_10;
  undefined1 local_8;
  
  if (param_2 == 0) {
    local_8 = '\0';
  }
  else {
    local_10 = 0;
    while ((local_10 < 0x20 && (*(int *)(param_1 + 0x40 + (uint)local_10 * 4) != 0))) {
      local_10 = local_10 + 1;
    }
    if (local_10 == 0x20) {
      local_8 = '\0';
    }
    else {
      *(int *)(param_1 + 0x40 + (uint)local_10 * 4) = param_2;
      local_8 = local_10 + 1;
    }
  }
  return local_8;
}



/* c0835d60 FUN_c0835d60 */

/* Boundary evidence: original MIPS .pdata c0835d60..c0835dbf. Semantic name remains unreviewed. */

void FUN_c0835d60(int param_1,byte param_2)

{
  if ((param_2 != 0) && (param_2 < 0x21)) {
    *(undefined4 *)(param_1 + 0x40 + (param_2 - 1) * 4) = 0;
  }
  return;
}



/* c0835dc0 FUN_c0835dc0 */

/* Boundary evidence: original MIPS .pdata c0835dc0..c0835e03. Semantic name remains unreviewed. */

void FUN_c0835dc0(int param_1,byte param_2,undefined4 param_3)

{
  *(undefined4 *)(param_1 + 0x40 + (param_2 - 1) * 4) = param_3;
  return;
}



/* c0835e04 FUN_c0835e04 */

/* Boundary evidence: original MIPS .pdata c0835e04..c083618b. Semantic name remains unreviewed. */

int FUN_c0835e04(int param_1,byte param_2,undefined4 param_3,undefined4 param_4)

{
  int local_14;
  undefined4 *local_10;
  int local_c;
  
  if (param_2 < 2) {
    local_c = (**(code **)(*(int *)(param_1 + 0x24) + 0x48))
                        (*(undefined4 *)(param_1 + 0x20),param_2,param_3,param_4,0);
    if (local_c == 0) {
      if (*(char *)(param_1 + 0x10) != '\0') {
        *(undefined4 *)(param_1 + 8) = 1;
        for (local_10 = *(undefined4 **)(param_1 + 0x2c); local_10 != (undefined4 *)0x0;
            local_10 = (undefined4 *)*local_10) {
          if (local_10[1] == 0) {
            (**(code **)(local_10[2] + 8))(local_10[4]);
          }
          local_10[1] = 1;
        }
        FUN_c083618c(param_1);
      }
      if (param_2 == 0) {
        if (*(char *)(param_1 + 0x10) != '\0') {
          *(undefined1 *)(param_1 + 0x10) = 0;
          FUN_c0825c4c(*(int *)(param_1 + 0x20));
          FUN_c08243d4();
        }
        local_c = 0;
      }
      else {
        for (local_14 = 0; local_14 < (int)(uint)*(byte *)(param_1 + 0x34); local_14 = local_14 + 1)
        {
          *(undefined4 *)(*(int *)(param_1 + 0x30) + local_14 * 0x14 + 0x10) =
               *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x30) + local_14 * 0x14 + 0xc) + 4);
          *(undefined1 *)(*(int *)(*(int *)(param_1 + 0x30) + local_14 * 0x14 + 0xc) + 9) = 0;
        }
        local_c = FUN_c08362fc(param_1);
        if (local_c == 0) {
          for (local_10 = *(undefined4 **)(param_1 + 0x2c); local_10 != (undefined4 *)0x0;
              local_10 = (undefined4 *)*local_10) {
            *(undefined4 *)(local_10[3] + 4) = *(undefined4 *)(param_1 + 0x14);
            local_c = (**(code **)(local_10[2] + 4))(local_10[4]);
            if (local_c != 0) goto LAB_c08360f0;
            local_10[1] = 0;
          }
          *(undefined4 *)(param_1 + 8) = 0;
          *(byte *)(param_1 + 0x10) = param_2;
          FUN_c0825c4c(*(int *)(param_1 + 0x20));
          FUN_c08243d4();
          local_c = 0;
        }
        else {
LAB_c08360f0:
          FUN_c083618c(param_1);
          for (local_10 = *(undefined4 **)(param_1 + 0x2c); local_10 != (undefined4 *)0x0;
              local_10 = (undefined4 *)*local_10) {
            if (local_10[1] == 0) {
              (**(code **)(local_10[2] + 8))(local_10[4]);
            }
            local_10[1] = 1;
          }
          *(undefined1 *)(param_1 + 0x10) = 0;
        }
      }
    }
  }
  else {
    local_c = 10;
  }
  return local_c;
}



/* c083618c FUN_c083618c */

/* Boundary evidence: original MIPS .pdata c083618c..c083620f. Semantic name remains unreviewed. */

void FUN_c083618c(int param_1)

{
  undefined4 local_10;
  
  for (local_10 = 0; local_10 < (int)(uint)*(byte *)(param_1 + 0x34); local_10 = local_10 + 1) {
    FUN_c0836210(param_1,*(byte **)(*(int *)(param_1 + 0x30) + local_10 * 0x14 + 0x10));
  }
  return;
}



/* c0836210 FUN_c0836210 */

/* Boundary evidence: original MIPS .pdata c0836210..c08362fb. Semantic name remains unreviewed. */

void FUN_c0836210(int param_1,byte *param_2)

{
  int local_10;
  
  for (local_10 = 0; local_10 < (int)(uint)*param_2; local_10 = local_10 + 1) {
    if ((*(int *)(*(int *)(param_2 + 4) + local_10 * 0x34 + 0x28) == 1) ||
       (*(int *)(*(int *)(param_2 + 4) + local_10 * 0x34 + 0x28) == 3)) {
      (**(code **)(*(int *)(param_1 + 0x24) + 0x20))
                (*(undefined4 *)(param_1 + 0x20),*(int *)(param_2 + 4) + local_10 * 0x34);
    }
  }
  return;
}



/* c08362fc FUN_c08362fc */

/* Boundary evidence: original MIPS .pdata c08362fc..c08363ab. Semantic name remains unreviewed. */

int FUN_c08362fc(int param_1)

{
  int iVar1;
  int local_14;
  
  local_14 = 0;
  while( true ) {
    if ((int)(uint)*(byte *)(param_1 + 0x34) <= local_14) {
      return 0;
    }
    iVar1 = FUN_c08363ac(param_1,*(byte **)(*(int *)(param_1 + 0x30) + local_14 * 0x14 + 0x10));
    if (iVar1 != 0) break;
    local_14 = local_14 + 1;
  }
  return iVar1;
}



/* c08363ac FUN_c08363ac */

/* Boundary evidence: original MIPS .pdata c08363ac..c08364f7. Semantic name remains unreviewed. */

int FUN_c08363ac(int param_1,byte *param_2)

{
  int iVar1;
  int local_14;
  undefined2 local_c;
  
  local_14 = 0;
  while( true ) {
    if ((int)(uint)*param_2 <= local_14) {
      return 0;
    }
    if (*(int *)(param_1 + 0x14) == 3) {
      local_c = *(undefined2 *)(*(int *)(param_2 + 4) + local_14 * 0x34);
    }
    else {
      local_c = *(undefined2 *)(*(int *)(param_2 + 4) + local_14 * 0x34 + 2);
    }
    *(undefined2 *)(*(int *)(param_2 + 4) + local_14 * 0x34 + 0x24) = local_c;
    iVar1 = (**(code **)(*(int *)(param_1 + 0x24) + 0x1c))
                      (*(undefined4 *)(param_1 + 0x20),*(int *)(param_2 + 4) + local_14 * 0x34);
    if (iVar1 != 0) break;
    local_14 = local_14 + 1;
  }
  return iVar1;
}



/* c08364f8 FUN_c08364f8 */

/* Boundary evidence: original MIPS .pdata c08364f8..c08368ff. Semantic name remains unreviewed. */

int FUN_c08364f8(int param_1,byte *param_2,byte param_3,undefined4 param_4)

{
  byte bVar1;
  bool bVar2;
  int iVar3;
  byte bVar4;
  int local_24;
  int local_20;
  byte local_1a;
  int local_10;
  
  bVar2 = false;
  local_1a = *(byte *)(param_1 + 0x34);
  bVar4 = *param_2 & 0x60;
  bVar1 = *param_2;
  if (bVar4 == 0) {
    iVar3 = FUN_c0836900(param_1,param_2,(uint)param_3,param_4);
    if (iVar3 != 0xb) {
      return iVar3;
    }
  }
  else if ((bVar4 == 0x40) && (param_2[1] == *(byte *)(param_1 + 0xc0))) {
    local_1a = (byte)*(undefined2 *)(param_2 + 2);
  }
  if ((bVar1 & 3) == 1) {
    local_1a = (byte)*(undefined2 *)(param_2 + 4);
  }
  else if ((bVar1 & 3) == 2) {
    local_20 = 0;
    while ((local_20 < (int)(uint)*(byte *)(param_1 + 0x34) && (!bVar2))) {
      local_10 = 0;
      while (((*(int *)(*(int *)(param_1 + 0x30) + local_20 * 0x14 + 0x10) != 0 &&
              (local_10 < (int)(uint)**(byte **)(*(int *)(param_1 + 0x30) + local_20 * 0x14 + 0x10))
              ) && (!bVar2))) {
        if (*(byte *)(*(int *)(*(int *)(*(int *)(param_1 + 0x30) + local_20 * 0x14 + 0x10) + 4) +
                      local_10 * 0x34 + 0xb) ==
            ((byte)*(undefined2 *)(param_2 + 4) & 0xf | (byte)*(undefined2 *)(param_2 + 4) & 0x80))
        {
          local_1a = (byte)local_20;
          bVar2 = true;
        }
        local_10 = local_10 + 1;
      }
      local_20 = local_20 + 1;
    }
  }
  if (local_1a < *(byte *)(param_1 + 0x34)) {
    local_24 = (**(code **)(*(int *)(param_1 + 0x30) + (uint)local_1a * 0x14))
                         (*(undefined4 *)
                           (*(int *)(*(int *)(param_1 + 0x30) + (uint)local_1a * 0x14 + 8) + 0x10),
                          param_2,param_3);
  }
  else if (bVar4 == 0x40) {
    for (local_20 = 0; local_20 < (int)(uint)*(byte *)(param_1 + 0x34); local_20 = local_20 + 1) {
      iVar3 = (**(code **)(*(int *)(param_1 + 0x30) + local_20 * 0x14))
                        (*(undefined4 *)
                          (*(int *)(*(int *)(param_1 + 0x30) + local_20 * 0x14 + 8) + 0x10),param_2,
                         param_3);
      if (iVar3 != 0xb) {
        return iVar3;
      }
    }
    local_24 = 10;
  }
  else {
    local_24 = 10;
  }
  return local_24;
}



/* c0836900 FUN_c0836900 */

/* Boundary evidence: original MIPS .pdata c0836900..c0836c93. Semantic name remains unreviewed. */

int FUN_c0836900(int param_1,byte *param_2,undefined4 param_3,undefined4 param_4)

{
  ushort uVar1;
  ushort uVar2;
  ushort uVar3;
  char cVar4;
  undefined1 *puVar5;
  int local_2c;
  
  cVar4 = (char)param_3;
  uVar1 = *(ushort *)(param_2 + 2);
  uVar2 = *(ushort *)(param_2 + 4);
  uVar3 = *(ushort *)(param_2 + 6);
  puVar5 = (undefined1 *)**(undefined4 **)(*(int *)(param_1 + 0x38) + 8);
  switch(param_2[1]) {
  case 0:
    local_2c = FUN_c083715c(param_1,*param_2,(byte)uVar2,uVar3,cVar4);
    break;
  case 1:
  case 3:
    local_2c = FUN_c08372e8(param_1,uVar1,uVar2,param_2[1] == 3,cVar4,*param_2 & 3);
    break;
  default:
    local_2c = 0xb;
    break;
  case 5:
    local_2c = (**(code **)(*(int *)(param_1 + 0x24) + 0x40))(*(undefined4 *)(param_1 + 0x20),uVar1)
    ;
    if (local_2c == 0) {
      local_2c = FUN_c0836c94(param_1,0,1,cVar4);
    }
    break;
  case 6:
    local_2c = FUN_c08374ac(param_1,uVar1,uVar2,uVar3,cVar4);
    break;
  case 7:
    local_2c = 0xb;
    break;
  case 8:
    *puVar5 = *(undefined1 *)(param_1 + 0x10);
    local_2c = FUN_c0836c94(param_1,1,(uint)uVar3,cVar4);
    break;
  case 9:
    local_2c = FUN_c0835e04(param_1,(byte)uVar1,param_3,param_4);
    if (local_2c == 0) {
      local_2c = FUN_c0836c94(param_1,0,1,cVar4);
    }
    break;
  case 10:
    if (((*(int *)(param_1 + 8) == 0) && (uVar3 == 1)) && (uVar2 < *(byte *)(param_1 + 0x34))) {
      *puVar5 = *(undefined1 *)(*(int *)(*(int *)(param_1 + 0x30) + (uint)uVar2 * 0x14 + 0xc) + 9);
      local_2c = FUN_c0836c94(param_1,1,1,cVar4);
    }
    else {
      local_2c = 10;
    }
    break;
  case 0xb:
    local_2c = FUN_c0836ea4(param_1,(byte)uVar2,(byte)uVar1);
    if (local_2c == 0) {
      local_2c = FUN_c0836c94(param_1,0,1,cVar4);
    }
    break;
  case 0xc:
    local_2c = 0xb;
  }
  return local_2c;
}



/* c0836c94 FUN_c0836c94 */

/* Boundary evidence: original MIPS .pdata c0836c94..c0836e2f. Semantic name remains unreviewed. */

int FUN_c0836c94(int param_1,uint param_2,uint param_3,char param_4)

{
  int local_10;
  uint local_c;
  
  if (*(int *)(param_1 + 0x38) == 0) {
    local_10 = 10;
  }
  else if (*(int *)(*(int *)(param_1 + 0x38) + 0x18) == 0) {
    if (*(char *)(param_1 + 0x3c) == param_4) {
      if (param_2 < param_3) {
        **(undefined1 **)(param_1 + 0x38) = 1;
      }
      else {
        **(undefined1 **)(param_1 + 0x38) = 0;
      }
      *(char *)(*(int *)(param_1 + 0x38) + 3) = param_4;
      *(int *)(*(int *)(param_1 + 0x38) + 0x14) = param_1;
      *(code **)(*(int *)(param_1 + 0x38) + 0x10) = FUN_c0836e30;
      local_c = param_2;
      if (param_3 < param_2) {
        local_c = param_3;
      }
      *(uint *)(*(int *)(param_1 + 0x38) + 0x1c) = local_c;
      if (param_3 == 0) {
        local_10 = FUN_c0830fc4(param_1,0,*(int *)(param_1 + 0x38));
      }
      else {
        local_10 = FUN_c0830ba8(param_1,0,*(int *)(param_1 + 0x38));
      }
    }
    else {
      local_10 = 0;
    }
  }
  else {
    local_10 = 8;
  }
  return local_10;
}



/* c0836e30 FUN_c0836e30 */

/* Boundary evidence: original MIPS .pdata c0836e30..c0836ea3. Semantic name remains unreviewed. */

void FUN_c0836e30(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = *(int *)(param_1 + 0x14);
  if (*(int *)(*(int *)(iVar1 + 0x38) + 0x28) != 0) {
    uVar2 = *(undefined4 *)(*(int *)(iVar1 + 0x38) + 0x28);
    FUN_c083175c(*(LPVOID *)(iVar1 + 0x38));
    *(undefined4 *)(iVar1 + 0x38) = uVar2;
  }
  *(undefined4 *)(*(int *)(iVar1 + 0x38) + 0x18) = 0;
  return;
}



/* c0836ea4 FUN_c0836ea4 */

/* Boundary evidence: original MIPS .pdata c0836ea4..c083715b. Semantic name remains unreviewed. */

int FUN_c0836ea4(int param_1,byte param_2,byte param_3)

{
  int iVar1;
  int local_18;
  int local_10;
  
  if (param_2 < *(byte *)(param_1 + 0x34)) {
    if (param_3 < *(byte *)(*(int *)(*(int *)(param_1 + 0x30) + (uint)param_2 * 0x14 + 0xc) + 8)) {
      if (*(char *)(param_1 + 0x10) == '\0') {
        local_10 = 10;
      }
      else {
        iVar1 = *(int *)(*(int *)(param_1 + 0x30) + (uint)param_2 * 0x14 + 8);
        if (*(int *)(iVar1 + 4) == 0) {
          (**(code **)(*(int *)(iVar1 + 8) + 8))(*(undefined4 *)(iVar1 + 0x10));
        }
        *(undefined4 *)(iVar1 + 4) = 1;
        FUN_c0836210(param_1,*(byte **)(*(int *)(param_1 + 0x30) + (uint)param_2 * 0x14 + 0x10));
        *(uint *)(*(int *)(param_1 + 0x30) + (uint)param_2 * 0x14 + 0x10) =
             *(int *)(*(int *)(*(int *)(param_1 + 0x30) + (uint)param_2 * 0x14 + 0xc) + 4) +
             (uint)param_3 * 0x10;
        *(byte *)(*(int *)(*(int *)(param_1 + 0x30) + (uint)param_2 * 0x14 + 0xc) + 9) = param_3;
        local_18 = FUN_c08363ac(param_1,*(byte **)(*(int *)(param_1 + 0x30) + (uint)param_2 * 0x14 +
                                                  0x10));
        if (local_18 == 0) {
          *(undefined4 *)(*(int *)(iVar1 + 0xc) + 4) = *(undefined4 *)(param_1 + 0x14);
          local_18 = (**(code **)(*(int *)(iVar1 + 8) + 4))(*(undefined4 *)(iVar1 + 0x10));
          if (local_18 == 0) {
            *(undefined4 *)(iVar1 + 4) = 0;
            return 0;
          }
        }
        FUN_c0836210(param_1,*(byte **)(*(int *)(param_1 + 0x30) + (uint)param_2 * 0x14 + 0x10));
        local_10 = local_18;
      }
    }
    else {
      local_10 = 10;
    }
  }
  else {
    local_10 = 10;
  }
  return local_10;
}



/* c083715c FUN_c083715c */

/* Boundary evidence: original MIPS .pdata c083715c..c08372e7. Semantic name remains unreviewed. */

int FUN_c083715c(int param_1,byte param_2,undefined1 param_3,ushort param_4,char param_5)

{
  int iVar1;
  byte local_18;
  undefined1 auStack_17 [7];
  uint local_10;
  
  local_18 = 0;
  memset(auStack_17,0,1);
  local_10 = param_2 & 3;
  if ((param_2 & 3) == 0) {
    if ((**(uint **)(param_1 + 0x104) & 1) != 0) {
      local_18 = local_18 | 1;
    }
    if (*(int *)(param_1 + 0xc4) != 0) {
      local_18 = local_18 | 2;
    }
  }
  else if (local_10 != 1) {
    if (local_10 != 2) {
      return 10;
    }
    iVar1 = (**(code **)(*(int *)(param_1 + 0x24) + 0x3c))
                      (*(undefined4 *)(param_1 + 0x20),&local_18,param_3);
    if (iVar1 != 0) {
      return iVar1;
    }
  }
  FUN_c0827ba0((void *)**(undefined4 **)(*(int *)(param_1 + 0x38) + 8),&local_18,2);
  iVar1 = FUN_c0836c94(param_1,0x12,(uint)param_4,param_5);
  return iVar1;
}



/* c08372e8 FUN_c08372e8 */

/* Boundary evidence: original MIPS .pdata c08372e8..c0837413. Semantic name remains unreviewed. */

int FUN_c08372e8(int param_1,ushort param_2,undefined2 param_3,char param_4,char param_5,
                char param_6)

{
  int local_10;
  
  local_10 = FUN_c0837414(param_2,param_6);
  if (local_10 == 0) {
    if (param_2 == 1) {
      if ((**(uint **)(param_1 + 0x104) >> 1 & 1) == 0) {
        return 0xb;
      }
      if (param_4 == '\0') {
        *(undefined4 *)(param_1 + 0xc4) = 0;
      }
      else {
        *(undefined4 *)(param_1 + 0xc4) = 1;
      }
    }
    else {
      local_10 = (**(code **)(*(int *)(param_1 + 0x24) + 0x44))
                           (*(undefined4 *)(param_1 + 0x20),param_2,param_3,param_4);
    }
    if (local_10 == 0) {
      local_10 = FUN_c0836c94(param_1,0,1,param_5);
    }
  }
  return local_10;
}



/* c0837414 FUN_c0837414 */

/* Boundary evidence: original MIPS .pdata c0837414..c08374ab. Semantic name remains unreviewed. */

undefined4 FUN_c0837414(ushort param_1,char param_2)

{
  undefined4 local_10;
  
  local_10 = 0;
  if (param_1 == 0) {
    if (param_2 != '\x02') {
      local_10 = 10;
    }
  }
  else if (((param_1 != 0) && (param_1 < 3)) && (param_2 != '\0')) {
    local_10 = 10;
  }
  return local_10;
}



/* c08374ac FUN_c08374ac */

/* Boundary evidence: original MIPS .pdata c08374ac..c0837663. Semantic name remains unreviewed. */

int FUN_c08374ac(int param_1,undefined2 param_2,ushort param_3,ushort param_4,char param_5)

{
  int local_1c;
  
  switch((char)((ushort)param_2 >> 8)) {
  case '\x01':
    local_1c = FUN_c0837664(param_1,param_4,param_5);
    break;
  case '\x02':
    local_1c = FUN_c08377c0(param_1,(byte)param_2,(byte)*(undefined4 *)(param_1 + 0x14),param_4,
                            param_5);
    break;
  case '\x03':
    local_1c = FUN_c08383b8(param_1,(byte)param_2,(uint)param_3,param_4,param_5);
    break;
  default:
    local_1c = 0xb;
    break;
  case '\x06':
    if (*(int *)(param_1 + 0x100) == 0) {
      local_1c = FUN_c08386dc(param_1,param_4,param_5);
    }
    else {
      local_1c = 10;
    }
    break;
  case '\a':
    if (*(int *)(param_1 + 0x100) == 0) {
      local_1c = FUN_c08387c0(param_1,param_4,param_5);
    }
    else {
      local_1c = 10;
    }
  }
  return local_1c;
}



/* c0837664 FUN_c0837664 */

/* Boundary evidence: original MIPS .pdata c0837664..c08377bf. Semantic name remains unreviewed. */

int FUN_c0837664(int param_1,ushort param_2,char param_3)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x104);
  DAT_c0839223 = *(undefined1 *)(param_1 + 0xc1);
  DAT_c0839222 = *(undefined1 *)(param_1 + 0xc2);
  DAT_c0839224 = *(undefined1 *)(param_1 + 0xc3);
  DAT_c083921c = *(undefined2 *)(iVar1 + 6);
  DAT_c083921e = *(undefined2 *)(iVar1 + 8);
  DAT_c0839220 = *(undefined2 *)(iVar1 + 10);
  DAT_c0839218 = *(undefined1 *)(iVar1 + 0xc);
  DAT_c0839219 = *(undefined1 *)(iVar1 + 0xd);
  DAT_c083921a = *(undefined1 *)(iVar1 + 0xe);
  DAT_c083921b = (**(code **)(*(int *)(param_1 + 0x24) + 0x4c))(*(undefined4 *)(param_1 + 0x20));
  FUN_c0827ba0((void *)**(undefined4 **)(*(int *)(param_1 + 0x38) + 8),&DAT_c0839214,0x12);
  iVar1 = FUN_c0836c94(param_1,0x12,(uint)param_2,param_3);
  return iVar1;
}



/* c08377c0 FUN_c08377c0 */

/* Boundary evidence: original MIPS .pdata c08377c0..c0838133. Semantic name remains unreviewed. */

int FUN_c08377c0(int param_1,char param_2,byte param_3,ushort param_4,char param_5)

{
  ushort uVar1;
  ushort uVar2;
  LPVOID pvVar3;
  uint *puVar4;
  undefined4 uVar5;
  void *pvVar6;
  int iVar7;
  byte *pbVar8;
  ushort *puVar9;
  int local_44;
  byte local_40;
  uint local_38;
  int local_2c;
  byte local_28;
  undefined4 *local_20;
  int local_18;
  
  puVar4 = *(uint **)(param_1 + 0x104);
  uVar2 = FUN_c0838134(param_1);
  if (param_2 == '\0') {
    if (0x100 < uVar2) {
      uVar5 = *(undefined4 *)(param_1 + 0x38);
      pvVar3 = FUN_c083156c(param_1,(uint)uVar2,(int *)0x0);
      *(LPVOID *)(param_1 + 0x38) = pvVar3;
      if (*(int *)(param_1 + 0x38) == 0) {
        *(undefined4 *)(param_1 + 0x38) = uVar5;
        return 7;
      }
      *(undefined4 *)(*(int *)(param_1 + 0x38) + 0x28) = uVar5;
    }
    pvVar6 = (void *)**(undefined4 **)(*(int *)(param_1 + 0x38) + 8);
    DAT_c0839238 = *(undefined1 *)(param_1 + 0x34);
    DAT_c0839239 = 1;
    if ((*puVar4 & 1) != 0) {
      DAT_c083923b = DAT_c083923b | 0x40;
    }
    if ((*puVar4 >> 1 & 1) != 0) {
      DAT_c083923b = DAT_c083923b | 0x20;
    }
    DAT_c083923c = (undefined1)puVar4[1];
    local_38 = 9;
    local_40 = 0;
    local_2c = 0;
    local_20 = *(undefined4 **)(param_1 + 0x2c);
    for (; local_40 < *(byte *)(param_1 + 0x34); local_40 = local_40 + 1) {
      if ((int)(*(byte *)(local_20[3] + 8) - 1) < local_2c) {
        local_20 = (undefined4 *)*local_20;
        local_2c = 0;
      }
      iVar7 = *(int *)(*(int *)(param_1 + 0x30) + (uint)local_40 * 0x14 + 0xc);
      if ((local_2c == 0) && (*(int *)(local_20[3] + 0x10) != 0)) {
        if ((int)(uint)uVar2 < (int)(local_38 + 8)) {
          return 7;
        }
        FUN_c0827ba0((void *)((int)pvVar6 + local_38),*(void **)(local_20[3] + 0x10),8);
        local_38 = local_38 + 8;
      }
      for (local_28 = 0; local_28 < *(byte *)(iVar7 + 8); local_28 = local_28 + 1) {
        pbVar8 = (byte *)(*(int *)(iVar7 + 4) + (uint)local_28 * 0x10);
        DAT_c0839242 = local_40;
        DAT_c0839243 = local_28;
        DAT_c0839244 = *pbVar8;
        DAT_c0839245 = *(undefined1 *)(iVar7 + 0x13);
        DAT_c0839246 = *(undefined1 *)(iVar7 + 0x14);
        DAT_c0839247 = *(undefined1 *)(iVar7 + 0x15);
        DAT_c0839248 = *(undefined1 *)(iVar7 + 0x16);
        if ((int)(uint)uVar2 < (int)(local_38 + 9)) {
          return 7;
        }
        FUN_c0827ba0((void *)((int)pvVar6 + local_38),&DAT_c0839240,9);
        local_38 = local_38 + 9;
        if ((local_28 == 0) && (*(short *)(iVar7 + 0x10) != 0)) {
          if ((int)(uint)uVar2 < (int)(local_38 + *(ushort *)(iVar7 + 0x10))) {
            return 7;
          }
          FUN_c0827ba0((void *)((int)pvVar6 + local_38),*(void **)(iVar7 + 0xc),
                       (uint)*(ushort *)(iVar7 + 0x10));
          local_38 = local_38 + *(ushort *)(iVar7 + 0x10);
        }
        if (*(short *)(pbVar8 + 0xc) != 0) {
          if ((int)(uint)uVar2 < (int)(local_38 + *(ushort *)(pbVar8 + 0xc))) {
            return 7;
          }
          FUN_c0827ba0((void *)((int)pvVar6 + local_38),*(void **)(pbVar8 + 8),
                       (uint)*(ushort *)(pbVar8 + 0xc));
          local_38 = local_38 + *(ushort *)(pbVar8 + 0xc);
        }
        for (local_44 = 0; local_44 < (int)(uint)*pbVar8; local_44 = local_44 + 1) {
          puVar9 = (ushort *)(*(int *)(pbVar8 + 4) + local_44 * 0x34);
          if ((char)puVar9[4] == '\0') {
            DAT_c083924e = 0x80;
          }
          else {
            DAT_c083924e = 0;
          }
          DAT_c083924e = DAT_c083924e | *(byte *)((int)puVar9 + 0xb);
          DAT_c083924f = (byte)*(undefined4 *)(puVar9 + 2);
          DAT_c0839252 = *(undefined1 *)((int)puVar9 + 0xd);
          if (*(int *)(puVar9 + 2) == 1) {
            DAT_c083924f = DAT_c083924f | *(char *)((int)puVar9 + 9) << 2 | (char)puVar9[5] << 4;
          }
          if (param_3 == 3) {
            uVar1 = *puVar9;
          }
          else {
            uVar1 = puVar9[1];
          }
          if (uVar1 < *(ushort *)(*(int *)(puVar9 + 2) * 6 + -0x3f7c6e04 + (param_3 - 1) * 2)) {
            if (param_3 == 3) {
              DAT_c0839250 = *puVar9;
            }
            else {
              DAT_c0839250 = puVar9[1];
            }
          }
          else {
            DAT_c0839250 = *(ushort *)(*(int *)(puVar9 + 2) * 6 + -0x3f7c6e04 + (param_3 - 1) * 2);
          }
          if ((param_3 == 3) &&
             (((*(int *)(puVar9 + 2) == 1 || (*(int *)(puVar9 + 2) == 3)) &&
              (DAT_c0839250 = DAT_c0839250 | (ushort)(byte)puVar9[6] << 0xb,
              (char)puVar9[0xc] != '\0')))) {
            DAT_c0839252 = (undefined1)puVar9[0xc];
          }
          DAT_c083924c = 7;
          if ((int)(uint)uVar2 < (int)(local_38 + 7)) {
            DAT_c083924c = 7;
            return 7;
          }
          FUN_c0827ba0((void *)((int)pvVar6 + local_38),&DAT_c083924c,7);
          local_38 = local_38 + DAT_c083924c;
          if (puVar9[8] != 0) {
            if ((int)(uint)uVar2 < (int)(local_38 + puVar9[8])) {
              return 7;
            }
            FUN_c0827ba0((void *)((int)pvVar6 + local_38),*(void **)(puVar9 + 10),(uint)puVar9[8]);
            local_38 = local_38 + puVar9[8];
          }
        }
      }
      local_2c = local_2c + 1;
    }
    DAT_c0839236 = (undefined2)local_38;
    FUN_c0827ba0(pvVar6,&DAT_c0839234,9);
    local_18 = FUN_c0836c94(param_1,local_38,(uint)param_4,param_5);
  }
  else {
    local_18 = 10;
  }
  return local_18;
}



/* c0838134 FUN_c0838134 */

/* Boundary evidence: original MIPS .pdata c0838134..c08383b7. Semantic name remains unreviewed. */

short FUN_c0838134(int param_1)

{
  int iVar1;
  byte *pbVar2;
  int iVar3;
  int local_28;
  byte local_24;
  short local_18;
  int local_10;
  byte local_c;
  undefined4 *local_8;
  
  local_18 = 9;
  local_24 = 0;
  local_10 = 0;
  local_8 = *(undefined4 **)(param_1 + 0x2c);
  for (; local_24 < *(byte *)(param_1 + 0x34); local_24 = local_24 + 1) {
    if ((int)(*(byte *)(local_8[3] + 8) - 1) < local_10) {
      local_8 = (undefined4 *)*local_8;
      local_10 = 0;
    }
    iVar1 = *(int *)(*(int *)(param_1 + 0x30) + (uint)local_24 * 0x14 + 0xc);
    if ((local_10 == 0) && (*(int *)(local_8[3] + 0x10) != 0)) {
      local_18 = local_18 + 8;
    }
    for (local_c = 0; local_c < *(byte *)(iVar1 + 8); local_c = local_c + 1) {
      pbVar2 = (byte *)(*(int *)(iVar1 + 4) + (uint)local_c * 0x10);
      local_18 = local_18 + 9;
      if ((local_c == 0) && (*(short *)(iVar1 + 0x10) != 0)) {
        local_18 = local_18 + *(short *)(iVar1 + 0x10);
      }
      if (*(short *)(pbVar2 + 0xc) != 0) {
        local_18 = local_18 + *(short *)(pbVar2 + 0xc);
      }
      for (local_28 = 0; local_28 < (int)(uint)*pbVar2; local_28 = local_28 + 1) {
        iVar3 = *(int *)(pbVar2 + 4) + local_28 * 0x34;
        local_18 = local_18 + 7;
        if (*(short *)(iVar3 + 0x10) != 0) {
          local_18 = local_18 + *(short *)(iVar3 + 0x10);
        }
      }
    }
    local_10 = local_10 + 1;
  }
  return local_18;
}



/* c08383b8 FUN_c08383b8 */

/* Boundary evidence: original MIPS .pdata c08383b8..c083854b. Semantic name remains unreviewed. */

int FUN_c08383b8(int param_1,byte param_2,undefined4 param_3,ushort param_4,char param_5)

{
  char *pcVar1;
  undefined1 *puVar2;
  int local_10;
  
  puVar2 = (undefined1 *)**(undefined4 **)(*(int *)(param_1 + 0x38) + 8);
  if (param_2 == 0) {
    *puVar2 = 4;
    puVar2[1] = 3;
    puVar2[2] = 9;
    puVar2[3] = 4;
    local_10 = FUN_c0836c94(param_1,4,(uint)param_4,param_5);
  }
  else if ((param_2 == 0xee) && (*(char *)(param_1 + 0xc0) != '\0')) {
    *puVar2 = 0x12;
    puVar2[1] = 3;
    FUN_c0827ba0(puVar2 + 2,L"MSFT100",0xe);
    puVar2[0x10] = *(undefined1 *)(param_1 + 0xc0);
    puVar2[0x11] = 0;
    local_10 = FUN_c0836c94(param_1,0x12,(uint)param_4,param_5);
  }
  else {
    pcVar1 = (char *)FUN_c083854c(param_1,param_2);
    if (pcVar1 == (char *)0x0) {
      local_10 = 10;
    }
    else {
      local_10 = FUN_c08385b4(param_1,pcVar1,param_4,param_5);
    }
  }
  return local_10;
}



/* c083854c FUN_c083854c */

/* Boundary evidence: original MIPS .pdata c083854c..c08385b3. Semantic name remains unreviewed. */

undefined4 FUN_c083854c(int param_1,byte param_2)

{
  undefined4 local_8;
  
  if ((param_2 == 0) || (0x20 < param_2)) {
    local_8 = 0;
  }
  else {
    local_8 = *(undefined4 *)(param_1 + 0x40 + (param_2 - 1) * 4);
  }
  return local_8;
}



/* c08385b4 FUN_c08385b4 */

/* Boundary evidence: original MIPS .pdata c08385b4..c08386db. Semantic name remains unreviewed. */

int FUN_c08385b4(int param_1,char *param_2,ushort param_3,char param_4)

{
  byte *pbVar1;
  size_t local_18;
  int local_10;
  
  if (param_2 == (char *)0x0) {
    local_10 = 10;
  }
  else {
    pbVar1 = (byte *)**(undefined4 **)(*(int *)(param_1 + 0x38) + 8);
    local_18 = FUN_c0827c28(param_2);
    *pbVar1 = ((char)local_18 + '\x01') * '\x02';
    pbVar1[1] = 3;
    FUN_c0827be4(pbVar1 + 2,0,local_18 << 1);
    for (; local_18 != 0; local_18 = local_18 - 1) {
      pbVar1[local_18 * 2] = param_2[local_18 - 1];
    }
    local_10 = FUN_c0836c94(param_1,(uint)*pbVar1,(uint)param_3,param_4);
  }
  return local_10;
}



/* c08386dc FUN_c08386dc */

/* Boundary evidence: original MIPS .pdata c08386dc..c08387bf. Semantic name remains unreviewed. */

int FUN_c08386dc(int param_1,ushort param_2,char param_3)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x104);
  DAT_c083922c = *(undefined1 *)(iVar1 + 0xc);
  DAT_c083922d = *(undefined1 *)(iVar1 + 0xd);
  DAT_c083922e = *(undefined1 *)(iVar1 + 0xe);
  DAT_c083922f = (**(code **)(*(int *)(param_1 + 0x24) + 0x4c))(*(undefined4 *)(param_1 + 0x20));
  FUN_c0827ba0((void *)**(undefined4 **)(*(int *)(param_1 + 0x38) + 8),&DAT_c0839228,10);
  iVar1 = FUN_c0836c94(param_1,10,(uint)param_2,param_3);
  return iVar1;
}



/* c08387c0 FUN_c08387c0 */

/* Boundary evidence: original MIPS .pdata c08387c0..c083888b. Semantic name remains unreviewed. */

int FUN_c08387c0(int param_1,ushort param_2,char param_3)

{
  undefined4 local_14;
  undefined1 local_c;
  
  if (*(char *)(param_1 + 0x18) == '\x03') {
    DAT_c0839235 = 7;
    if (*(int *)(param_1 + 0x14) == 3) {
      local_c = 2;
    }
    else {
      local_c = 3;
    }
    local_14 = FUN_c08377c0(param_1,'\0',local_c,param_2,param_3);
    DAT_c0839235 = 2;
  }
  else {
    local_14 = 10;
  }
  return local_14;
}



/* c083888c FUN_c083888c */

/* Boundary evidence: original MIPS .pdata c083888c..c08389f3. Semantic name remains unreviewed. */

void FUN_c083888c(int param_1)

{
  char cVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0x104);
  if (*(char *)(param_1 + 0xc1) == '\0') {
    cVar1 = FUN_c0835c7c(param_1,*(int *)(iVar2 + 0x10));
    *(char *)(param_1 + 0xc1) = cVar1;
  }
  else {
    FUN_c0835dc0(param_1,*(byte *)(param_1 + 0xc1),*(undefined4 *)(iVar2 + 0x10));
  }
  if (*(char *)(param_1 + 0xc2) == '\0') {
    cVar1 = FUN_c0835c7c(param_1,*(int *)(iVar2 + 0x14));
    *(char *)(param_1 + 0xc2) = cVar1;
  }
  else {
    FUN_c0835dc0(param_1,*(byte *)(param_1 + 0xc2),*(undefined4 *)(iVar2 + 0x14));
  }
  if (*(int *)(iVar2 + 0x18) == 0) {
    if (*(char *)(param_1 + 0xc3) != '\0') {
      FUN_c0835d60(param_1,*(byte *)(param_1 + 0xc3));
      *(undefined1 *)(param_1 + 0xc3) = 0;
    }
  }
  else if (*(char *)(param_1 + 0xc3) == '\0') {
    cVar1 = FUN_c0835c7c(param_1,*(int *)(iVar2 + 0x18));
    *(char *)(param_1 + 0xc3) = cVar1;
  }
  else {
    FUN_c0835dc0(param_1,*(byte *)(param_1 + 0xc3),*(undefined4 *)(iVar2 + 0x18));
  }
  return;
}



/* c0838ba4 FUN_c0838ba4 */

/* Boundary evidence: original MIPS .pdata c0838ba4..c0838bf7. Semantic name remains unreviewed. */

void FUN_c0838ba4(int param_1,undefined4 param_2,uint *param_3)

{
  if ((*param_3 & 1) != 0) {
    param_1 = ((-param_3[2] & param_3[1] + param_1) - (param_3[1] + param_1)) + param_1;
  }
  FUN_c0838c24(*(uint *)(param_1 + (*param_3 & 0xfffffffc)));
  return;
}



/* c0838bf8 FUN_c0838bf8 */

/* Boundary evidence: original MIPS .pdata c0838bf8..c0838c23. Semantic name remains unreviewed. */

undefined4 FUN_c0838bf8(undefined4 param_1,int param_2,undefined4 param_3,int param_4)

{
  FUN_c0838ba4(param_2,param_4,*(uint **)(*(int *)(param_4 + 4) + 0xc));
  return 1;
}



/* c0838c24 FUN_c0838c24 */

/* Boundary evidence: original MIPS .pdata c0838c24..c0838c6b. Semantic name remains unreviewed. */

void FUN_c0838c24(uint param_1)

{
  if ((param_1 == DAT_c0839254) && (param_1 >> 0x10 == 0)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __report_gsfailure();
}


