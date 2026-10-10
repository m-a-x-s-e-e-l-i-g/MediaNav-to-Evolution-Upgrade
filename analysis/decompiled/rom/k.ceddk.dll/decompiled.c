/* Automatic Ghidra pseudocode. Not original source; not runtime-verified. */

/* c0421f5c GetCPUCoreSpeed */

/* Boundary evidence: original MIPS .pdata c0421f5c..c0421f9b. Semantic name remains unreviewed. */

undefined4 GetCPUCoreSpeed(void)

{
  undefined4 local_10;
  undefined1 auStack_c [4];
  
                    /* 0x1f5c  58  GetCPUCoreSpeed */
  KernelIoControl(0x1032c93,0,0,&local_10,4,auStack_c);
  return local_10;
}



/* c0421f9c GetPBUSSpeed */

/* Boundary evidence: original MIPS .pdata c0421f9c..c0421fdb. Semantic name remains unreviewed. */

undefined4 GetPBUSSpeed(void)

{
  undefined4 local_10;
  undefined1 auStack_c [4];
  
                    /* 0x1f9c  59  GetPBUSSpeed */
  KernelIoControl(0x1032c97,0,0,&local_10,4,auStack_c);
  return local_10;
}



/* c0421fdc entry */

/* Boundary evidence: original MIPS .pdata c0421fdc..c042201f. Semantic name remains unreviewed. */

undefined4 entry(HMODULE param_1,int param_2)

{
  if (param_2 == 1) {
    DisableThreadLibraryCalls(param_1);
    CalibrateStallCounter();
    CalibrateStallCounter();
  }
  return 1;
}



/* c0422020 OALStallExecution */

/* Boundary evidence: original MIPS .pdata c0422020..c04220a7. Semantic name remains unreviewed. */

void OALStallExecution(int param_1)

{
  uint uVar1;
  uint uVar2;
  
                    /* 0x2020  96  OALStallExecution */
  uVar1 = FUN_c04221ac();
  uVar2 = FUN_c04220d0();
  uVar2 = (uVar2 / 1000000 + 1) * param_1 + uVar1;
  while (uVar2 < uVar1) {
    uVar1 = FUN_c04221ac();
  }
  do {
    uVar1 = FUN_c04221ac();
  } while (uVar1 < uVar2);
  return;
}



/* c04220a8 StallExecution */

/* Boundary evidence: original MIPS .pdata c04220a8..c04220cf. Semantic name remains unreviewed. */

void StallExecution(int param_1)

{
                    /* 0x20a8  22  StallExecution */
  OALStallExecution(param_1 * 10);
  return;
}



/* c04220d0 FUN_c04220d0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_c04220d0(void)

{
  return (_DAT_b0900060 & 0x7f) * 12000000;
}



/* c04221ac FUN_c04221ac */

undefined4 FUN_c04221ac(void)

{
  return Count;
}



/* c0422360 MmMapIoSpace */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Boundary evidence: original MIPS .pdata c0422360..c0422443. Semantic name remains unreviewed. */

LPVOID MmMapIoSpace(uint param_1,int param_2,int param_3,int param_4)

{
  LPVOID lpAddress;
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  uint dwSize;
  
                    /* 0x2360  8  MmMapIoSpace */
  uVar4 = ~(_DAT_00005b04 - 1U) & param_1;
  iVar3 = param_1 - uVar4;
  dwSize = (_DAT_00005b04 + iVar3 + param_3) - 1U & ~(_DAT_00005b04 - 1U);
  lpAddress = VirtualAlloc((LPVOID)0x0,dwSize,0x2000,1);
  if (lpAddress != (LPVOID)0x0) {
    uVar2 = 0x404;
    if (param_4 == 0) {
      uVar2 = 0x604;
    }
    iVar1 = VirtualCopy(lpAddress,param_2 << 0x18 | uVar4 >> 8,dwSize,uVar2);
    if (iVar1 == 0) {
      VirtualFree(lpAddress,0,0x8000);
      lpAddress = (LPVOID)0x0;
    }
    else {
      lpAddress = (LPVOID)(iVar3 + (int)lpAddress);
    }
  }
  return lpAddress;
}



/* c0422444 MmUnmapIoSpace */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Boundary evidence: original MIPS .pdata c0422444..c0422477. Semantic name remains unreviewed. */

void MmUnmapIoSpace(uint param_1)

{
                    /* 0x2444  9  MmUnmapIoSpace */
  VirtualFree((LPVOID)(~(_DAT_00005b04 - 1U) & param_1),0,0x8000);
  return;
}



/* c0422478 TransBusAddrToVirtual */

/* Boundary evidence: original MIPS .pdata c0422478..c04224db. Semantic name remains unreviewed. */

undefined4
TransBusAddrToVirtual
          (int param_1,undefined4 param_2,undefined4 param_3,int param_4,int param_5,
          undefined4 *param_6,undefined4 *param_7)

{
  int iVar1;
  LPVOID pvVar2;
  undefined4 uVar3;
  uint local_10;
  int local_c;
  
                    /* 0x2478  24  TransBusAddrToVirtual */
  uVar3 = 0;
  iVar1 = HalTranslateBusAddress(param_1,param_2,param_3,param_4,param_6,&local_10);
  if (iVar1 != 0) {
    pvVar2 = MmMapIoSpace(local_10,local_c,param_5,0);
    *param_7 = pvVar2;
    if (pvVar2 != (LPVOID)0x0) {
      uVar3 = 1;
    }
  }
  return uVar3;
}



/* c04224dc HalAddWiredTLB */

/* Boundary evidence: original MIPS .pdata c04224dc..c042252b. Semantic name remains unreviewed. */

undefined4
HalAddWiredTLB(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 local_20;
  undefined1 auStack_1c [4];
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  
                    /* 0x24dc  62  HalAddWiredTLB */
  local_18 = param_1;
  local_14 = param_2;
  local_10 = param_3;
  local_c = param_4;
  KernelIoControl(0x1032c9b,&local_18,0x10,&local_20,4,auStack_1c);
  return local_20;
}



/* c042252c HalCreateBlockMapping */

/* Boundary evidence: original MIPS .pdata c042252c..c042282f. Semantic name remains unreviewed. */

uint HalCreateBlockMapping(uint param_1,int param_2,int param_3,uint param_4)

{
  LPVOID pvVar1;
  int iVar2;
  HANDLE hProcess;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  undefined4 uVar7;
  uint uVar8;
  
                    /* 0x252c  67  HalCreateBlockMapping */
  NKDbgPrintfW(L"HalCreateBlockMapping(%08X%08X,%08X,%d)\r\n",param_2,param_1,param_3,param_4);
  if (param_3 != 0) {
    uVar5 = (param_1 + param_3) - 1;
    if (((uVar5 ^ param_1) & 0xfffff000) != 0) {
      iVar2 = 0;
      while( true ) {
        if (iVar2 == 0) {
          uVar7 = 0;
          uVar4 = 0x1000;
        }
        else if (iVar2 == 1) {
          uVar7 = 0x6000;
          uVar4 = 0x4000;
        }
        else if (iVar2 == 2) {
          uVar7 = 0x1e000;
          uVar4 = 0x10000;
        }
        else if (iVar2 == 3) {
          uVar7 = 0x7e000;
          uVar4 = 0x40000;
        }
        else if (iVar2 == 4) {
          uVar7 = 0x1fe000;
          uVar4 = 0x100000;
        }
        else if (iVar2 == 5) {
          uVar7 = 0x7fe000;
          uVar4 = 0x400000;
        }
        else {
          if (iVar2 != 6) {
            return 0;
          }
          uVar7 = 0x1ffe000;
          uVar4 = 0x1000000;
        }
        uVar3 = ~(uVar4 * 2 - 1);
        if ((uVar3 & param_1) == (uVar3 & uVar5)) break;
        iVar2 = iVar2 + 1;
        if (7 < iVar2) {
          return 0;
        }
      }
      uVar8 = param_2 << 0x1a | param_1 >> 6 & 0xffffffc0;
      uVar3 = uVar4 * 2;
      uVar5 = uVar3;
      if (uVar3 < 0x200000) {
        uVar5 = 0x200000;
      }
      hProcess = (HANDLE)GetDirectCallerProcessId();
      pvVar1 = VirtualAllocEx(hProcess,(LPVOID)0x0,uVar5 << 1,0x2000,4);
      if (pvVar1 != (LPVOID)0x0) {
        uVar5 = (int)pvVar1 + (uVar3 - 1) & ~(uVar3 - 1);
        if (param_4 == 0) {
          param_4 = 2;
        }
        if (param_4 == 1) {
          param_4 = 3;
        }
        uVar3 = (param_4 & 7) << 3;
        uVar6 = uVar3 | uVar8 | 7;
        uVar4 = uVar3 | (uVar4 >> 6) + uVar8 | 7;
        NKDbgPrintfW(L" HalCreateBlockMapping(): VA=%08X, PA0=%08X, PA1=%08X, PM=%08X\r\n",uVar5,
                     uVar6,uVar4,uVar7);
        HalAddWiredTLB(uVar5,uVar6,uVar4,uVar7);
        return uVar5;
      }
      NKDbgPrintfW(L"HalCreateBlockMapping() VirtualAlloc(%d bytes) failed\r\n",uVar5 << 1);
      return 0;
    }
    pvVar1 = VirtualAlloc((LPVOID)0x0,0x200000,0x2000,1);
    if (pvVar1 == (LPVOID)0x0) {
      return 0;
    }
    iVar2 = VirtualCopy(pvVar1,param_2 << 0x18 | param_1 >> 8 & 0xfffffff0,0x1000,0x604);
    if (iVar2 == 1) {
      return (param_1 & 0xfff) + (int)pvVar1;
    }
    VirtualFree(pvVar1,0,0x8000);
  }
  return 0;
}



/* c0422830 TransBusAddrToStatic */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Boundary evidence: original MIPS .pdata c0422830..c042298b. Semantic name remains unreviewed. */

undefined4
TransBusAddrToStatic
          (int param_1,undefined4 param_2,undefined4 param_3,int param_4,int param_5,
          undefined4 *param_6,uint *param_7)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  uint local_20;
  int local_1c;
  
                    /* 0x2830  23  TransBusAddrToStatic */
  uVar3 = 0;
  iVar1 = HalTranslateBusAddress(param_1,param_2,param_3,param_4,param_6,&local_20);
  if (iVar1 != 0) {
    if (local_1c == 0) {
      iVar1 = (_DAT_00005b04 - 1U & local_20) + param_5;
      NKDbgPrintfW(L"\r\nTransBusAddrToStatic  BA=%x%08x ",param_4,param_3);
      uVar2 = (int)~(_DAT_00005b04 - 1U) >> 8 & (local_1c << 0x18 | local_20 >> 8);
      NKDbgPrintfW(L"TA=%x%08x ");
      NKDbgPrintfW(L"CreateStaticMapping(%x, %x) = ",uVar2,iVar1);
      uVar2 = CreateStaticMapping(uVar2,iVar1);
      *param_7 = uVar2;
      *param_7 = (_DAT_00005b04 - 1U & local_20) + uVar2;
      NKDbgPrintfW(L" %x\r\n");
    }
    else {
      uVar2 = HalCreateBlockMapping(local_20,local_1c,param_5,0);
      *param_7 = uVar2;
    }
    if (*param_7 != 0) {
      uVar3 = 1;
    }
  }
  return uVar3;
}



/* c042298c MmCreateMdl */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Boundary evidence: original MIPS .pdata c042298c..c0422b17. Semantic name remains unreviewed. */

undefined4 * MmCreateMdl(undefined4 *param_1,uint param_2,int param_3)

{
  bool bVar1;
  DWORD DVar2;
  int iVar3;
  int *piVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  
                    /* 0x298c  94  MmCreateMdl */
  uVar6 = ~(_DAT_00005b04 - 1U) & param_2;
  iVar7 = (param_2 - uVar6) + param_3;
  iVar3 = 0xc;
  if (_DAT_00005b04 != 0x1000) {
    iVar3 = 10;
  }
  uVar5 = ((_DAT_00005b04 - 1U & uVar6) + _DAT_00005b04 + iVar7) - 1 >> iVar3;
  if (param_1 == (undefined4 *)0x0) {
    param_1 = LocalAlloc(0x40,(uVar5 + 6) * 4);
    if (param_1 == (undefined4 *)0x0) {
      return (undefined4 *)0x0;
    }
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  *param_1 = 0;
  *(undefined2 *)(param_1 + 3) = 0;
  param_1[1] = param_2;
  param_1[2] = param_3;
  param_1[5] = param_2 - uVar6;
  if (!bVar1) {
    *(undefined2 *)(param_1 + 3) = 8;
  }
  piVar4 = param_1 + 6;
  iVar3 = LockPages(uVar6,iVar7,piVar4,4);
  if (iVar3 == 0) {
    DVar2 = GetLastError();
    NKDbgPrintfW(L"MmCreateMdl: Failed to lock pages (Error Code %d)\r\n",DVar2);
    if (bVar1) {
      LocalFree(param_1);
    }
    return (undefined4 *)0x0;
  }
  for (; uVar5 != 0; uVar5 = uVar5 - 1) {
    *piVar4 = *piVar4 << (_DAT_00005b08 & 0x1f);
    piVar4 = piVar4 + 1;
  }
  return param_1;
}



/* c0422b18 MmFreeMdl */

/* Boundary evidence: original MIPS .pdata c0422b18..c0422b87. Semantic name remains unreviewed. */

void MmFreeMdl(undefined4 *param_1)

{
                    /* 0x2b18  95  MmFreeMdl */
  if (param_1 != (undefined4 *)0x0) {
    UnlockPages(param_1[1] - param_1[5],param_1[5] + param_1[2]);
    if ((*(ushort *)(param_1 + 3) & 8) == 0) {
      LocalFree(param_1);
    }
    else {
      *param_1 = 0;
      *(undefined2 *)(param_1 + 3) = 0;
      param_1[1] = 0;
      param_1[5] = 0;
      param_1[2] = 0;
    }
  }
  return;
}



/* c0422b88 READ_PORT_UCHAR */

undefined1 READ_PORT_UCHAR(undefined1 *param_1)

{
                    /* 0x2b88  13  READ_PORT_UCHAR
                       0x2b88  19  READ_REGISTER_UCHAR */
  return *param_1;
}



/* c0422b90 WRITE_PORT_UCHAR */

void WRITE_PORT_UCHAR(undefined1 *param_1,undefined1 param_2)

{
                    /* 0x2b90  28  WRITE_PORT_UCHAR
                       0x2b90  34  WRITE_REGISTER_UCHAR */
  SYNC(0);
  *param_1 = param_2;
  SYNC(0);
  return;
}



/* c0422bb4 READ_PORT_USHORT */

undefined2 READ_PORT_USHORT(undefined2 *param_1)

{
                    /* 0x2bb4  15  READ_PORT_USHORT
                       0x2bb4  21  READ_REGISTER_USHORT */
  return *param_1;
}



/* c0422bbc READ_PORT_ULONG */

undefined4 READ_PORT_ULONG(undefined4 *param_1)

{
                    /* 0x2bbc  14  READ_PORT_ULONG
                       0x2bbc  20  READ_REGISTER_ULONG */
  return *param_1;
}



/* c0422bc4 WRITE_PORT_USHORT */

void WRITE_PORT_USHORT(undefined2 *param_1,undefined2 param_2)

{
                    /* 0x2bc4  30  WRITE_PORT_USHORT
                       0x2bc4  36  WRITE_REGISTER_USHORT */
  SYNC(0);
  *param_1 = param_2;
  SYNC(0);
  return;
}



/* c0422be8 WRITE_PORT_ULONG */

void WRITE_PORT_ULONG(undefined4 *param_1,undefined4 param_2)

{
                    /* 0x2be8  29  WRITE_PORT_ULONG
                       0x2be8  35  WRITE_REGISTER_ULONG */
  SYNC(0);
  *param_1 = param_2;
  SYNC(0);
  return;
}



/* c0422c0c READ_PORT_BUFFER_UCHAR */

void READ_PORT_BUFFER_UCHAR(undefined1 *param_1,undefined1 *param_2,int param_3)

{
                    /* 0x2c0c  10  READ_PORT_BUFFER_UCHAR
                       0x2c0c  16  READ_REGISTER_BUFFER_UCHAR */
  for (; param_3 != 0; param_3 = param_3 + -1) {
    *param_2 = *param_1;
    param_2 = param_2 + 1;
  }
  return;
}



/* c0422c30 READ_PORT_BUFFER_USHORT */

void READ_PORT_BUFFER_USHORT(undefined2 *param_1,undefined2 *param_2,int param_3)

{
                    /* 0x2c30  12  READ_PORT_BUFFER_USHORT
                       0x2c30  18  READ_REGISTER_BUFFER_USHORT */
  for (; param_3 != 0; param_3 = param_3 + -1) {
    *param_2 = *param_1;
    param_2 = param_2 + 1;
  }
  return;
}



/* c0422c54 READ_PORT_BUFFER_ULONG */

void READ_PORT_BUFFER_ULONG(undefined4 *param_1,undefined4 *param_2,int param_3)

{
                    /* 0x2c54  11  READ_PORT_BUFFER_ULONG
                       0x2c54  17  READ_REGISTER_BUFFER_ULONG */
  for (; param_3 != 0; param_3 = param_3 + -1) {
    *param_2 = *param_1;
    param_2 = param_2 + 1;
  }
  return;
}



/* c0422c78 WRITE_PORT_BUFFER_UCHAR */

void WRITE_PORT_BUFFER_UCHAR(undefined1 *param_1,undefined1 *param_2,int param_3)

{
  undefined1 *local_res4;
  int local_res8;
  
                    /* 0x2c78  25  WRITE_PORT_BUFFER_UCHAR
                       0x2c78  31  WRITE_REGISTER_BUFFER_UCHAR */
  local_res4 = param_2;
  local_res8 = param_3;
  while (local_res8 != 0) {
    SYNC(0);
    *param_1 = *local_res4;
    local_res4 = local_res4 + 1;
    local_res8 = local_res8 + -1;
  }
  SYNC(0);
  return;
}



/* c0422cd0 WRITE_PORT_BUFFER_USHORT */

void WRITE_PORT_BUFFER_USHORT(undefined2 *param_1,undefined2 *param_2,int param_3)

{
  undefined2 *local_res4;
  int local_res8;
  
                    /* 0x2cd0  27  WRITE_PORT_BUFFER_USHORT
                       0x2cd0  33  WRITE_REGISTER_BUFFER_USHORT */
  local_res4 = param_2;
  local_res8 = param_3;
  while (local_res8 != 0) {
    SYNC(0);
    *param_1 = *local_res4;
    local_res4 = local_res4 + 1;
    local_res8 = local_res8 + -1;
  }
  SYNC(0);
  return;
}



/* c0422d28 WRITE_PORT_BUFFER_ULONG */

void WRITE_PORT_BUFFER_ULONG(undefined4 *param_1,undefined4 *param_2,int param_3)

{
  undefined4 *local_res4;
  int local_res8;
  
                    /* 0x2d28  26  WRITE_PORT_BUFFER_ULONG
                       0x2d28  32  WRITE_REGISTER_BUFFER_ULONG */
  local_res4 = param_2;
  local_res8 = param_3;
  while (local_res8 != 0) {
    SYNC(0);
    *param_1 = *local_res4;
    local_res4 = local_res4 + 1;
    local_res8 = local_res8 + -1;
  }
  SYNC(0);
  return;
}



/* c0422d80 InterruptConfigure */

/* Boundary evidence: original MIPS .pdata c0422d80..c04230a7. Semantic name remains unreviewed. */

int * InterruptConfigure(undefined4 param_1,uint param_2,int *param_3)

{
  HKEY hKey;
  int *hMem;
  LSTATUS LVar1;
  HKEY pHVar2;
  int iVar3;
  code *pcVar4;
  int *piVar5;
  DWORD local_140 [2];
  undefined4 local_138;
  uint local_134;
  int local_130;
  undefined1 auStack_12c [128];
  undefined1 auStack_ac [128];
  uint local_2c;
  
                    /* 0x2d80  82  InterruptConfigure */
  local_2c = DAT_c0428134;
  hKey = (HKEY)OpenDeviceKey(param_1);
  NKDbgPrintfW(L"InterruptConfigure: %s %d %d\r\n",param_1,param_2,*param_3);
  if (hKey != (HKEY)0x0) {
    hMem = LocalAlloc(0x40,0x28);
    pcVar4 = RegCloseKey_exref;
    if (hMem != (int *)0x0) {
      piVar5 = hMem + 4;
      local_140[0] = 4;
      LVar1 = RegQueryValueExW(hKey,L"PortAddr",(LPDWORD)0x0,(LPDWORD)0x0,(LPBYTE)piVar5,local_140);
      if (LVar1 != 0) {
        *piVar5 = 0;
      }
      local_140[0] = 4;
      LVar1 = RegQueryValueExW(hKey,L"PortSize",(LPDWORD)0x0,(LPDWORD)0x0,(LPBYTE)(hMem + 5),
                               local_140);
      if (LVar1 != 0) {
        hMem[5] = 4;
      }
      hMem[1] = (uint)(*piVar5 != 0);
      piVar5 = hMem + 7;
      hMem[2] = 0;
      local_140[0] = 4;
      LVar1 = RegQueryValueExW(hKey,L"MaskAddr",(LPDWORD)0x0,(LPDWORD)0x0,(LPBYTE)piVar5,local_140);
      if (LVar1 != 0) {
        *piVar5 = 0;
      }
      hMem[3] = (uint)(*piVar5 != 0);
      local_140[0] = 4;
      LVar1 = RegQueryValueExW(hKey,L"Mask",(LPDWORD)0x0,(LPDWORD)0x0,(LPBYTE)(hMem + 6),local_140);
      if (LVar1 != 0) {
        hMem[6] = -1;
      }
      local_138 = 0x10c;
      pHVar2 = (HKEY)DDKReg_GetIsrInfo(hKey,&local_138);
      RegCloseKey(hKey);
      if (pHVar2 == (HKEY)0x0) {
        if (param_2 != 0xffffffff) {
          local_134 = param_2;
        }
        if (*param_3 != 0) {
          local_130 = *param_3;
        }
        if (local_130 == 0) {
          local_130 = InterruptConnect(0,0,local_134);
          hMem[8] = 1;
        }
        else {
          hMem[8] = 0;
        }
        if (local_130 != 0) {
          *hMem = local_130;
          iVar3 = LoadIntChainHandler(auStack_12c,auStack_ac,local_134 & 0xff);
          hMem[9] = iVar3;
          if (iVar3 != 0) {
            iVar3 = KernelLibIoControl(iVar3,0x100,hMem,0x20,0,0,0);
            if (iVar3 != 0) {
              *param_3 = *hMem;
              FUN_c0426ba8(local_2c);
              return hMem;
            }
            FreeIntChainHandler(hMem[9]);
          }
        }
        LocalFree(hMem);
        goto LAB_c0422dec;
      }
      LocalFree(hMem);
      hKey = pHVar2;
      pcVar4 = SetLastError_exref;
    }
    (*pcVar4)(hKey);
  }
LAB_c0422dec:
  FUN_c0426ba8(local_2c);
  return (int *)0x0;
}



/* c04230a8 InterruptUnconfigure */

/* Boundary evidence: original MIPS .pdata c04230a8..c04230eb. Semantic name remains unreviewed. */

void InterruptUnconfigure(undefined4 *param_1)

{
                    /* 0x30a8  93  InterruptUnconfigure */
  FreeIntChainHandler(param_1[9]);
  if (param_1[8] != 0) {
    InterruptDisconnect(*param_1);
  }
  LocalFree(param_1);
  return;
}



/* c04230ec InterruptConnect */

/* Boundary evidence: original MIPS .pdata c04230ec..c042312f. Semantic name remains unreviewed. */

undefined4 InterruptConnect(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 local_res8 [2];
  undefined4 local_10;
  undefined1 auStack_c [4];
  
                    /* 0x30ec  87  InterruptConnect */
  local_res8[0] = param_3;
  KernelIoControl(0x1010098,local_res8,4,&local_10,4,auStack_c);
  return local_10;
}



/* c0423130 InterruptDisconnect */

/* Boundary evidence: original MIPS .pdata c0423130..c0423167. Semantic name remains unreviewed. */

void InterruptDisconnect(undefined4 param_1)

{
  undefined4 local_res0 [4];
  
  local_res0[0] = param_1;
                    /* 0x3130  89  InterruptDisconnect */
  KernelIoControl(0x10100d8,local_res0,4,0,0,0);
  return;
}



/* c0423168 InterruptConnectTimer */

/* Boundary evidence: original MIPS .pdata c0423168..c04231a7. Semantic name remains unreviewed. */

undefined4 InterruptConnectTimer(void)

{
  undefined4 local_10;
  undefined1 auStack_c [4];
  
                    /* 0x3168  88  InterruptConnectTimer */
  KernelIoControl(0x101200b,0,0,&local_10,4,auStack_c);
  return local_10;
}



/* c04231a8 InterruptDisconnectTimer */

/* Boundary evidence: original MIPS .pdata c04231a8..c04231df. Semantic name remains unreviewed. */

void InterruptDisconnectTimer(undefined4 param_1)

{
  undefined4 local_res0 [4];
  
  local_res0[0] = param_1;
                    /* 0x31a8  90  InterruptDisconnectTimer */
  KernelIoControl(0x101200f,local_res0,4,0,0,0);
  return;
}



/* c04231e0 InterruptStartTimer */

/* Boundary evidence: original MIPS .pdata c04231e0..c0423227. Semantic name remains unreviewed. */

undefined1 InterruptStartTimer(undefined4 param_1,undefined4 param_2)

{
  undefined1 local_18 [4];
  undefined1 auStack_14 [4];
  undefined4 local_10;
  undefined4 local_c;
  
                    /* 0x31e0  91  InterruptStartTimer */
  local_10 = param_1;
  local_c = param_2;
  KernelIoControl(0x1012013,&local_10,8,local_18,1,auStack_14);
  return local_18[0];
}



/* c0423228 InterruptStopTimer */

/* Boundary evidence: original MIPS .pdata c0423228..c042326b. Semantic name remains unreviewed. */

undefined1 InterruptStopTimer(undefined4 param_1)

{
  undefined4 local_res0 [4];
  undefined1 local_10 [4];
  undefined1 auStack_c [4];
  
                    /* 0x3228  92  InterruptStopTimer */
  local_res0[0] = param_1;
  KernelIoControl(0x1012017,local_res0,4,local_10,1,auStack_c);
  return local_10[0];
}



/* c042326c FUN_c042326c */

/* Boundary evidence: original MIPS .pdata c042326c..c04235d7. Semantic name remains unreviewed. */

void FUN_c042326c(void)

{
  undefined **ppuVar1;
  
  ppuVar1 = &PTR_u___DMA_CHANNEL_MUTEX_0___c04280f4;
  do {
    ppuVar1 = ppuVar1 + 1;
  } while ((int)ppuVar1 < -0x3fbd7ecc);
  DAT_c04281bc = 1;
  DAT_c04281d8 = L"AC97 TX";
  DAT_c04281c0 = 8;
  DAT_c04281c8 = 0;
  DAT_c04281cc = 0xe0000000;
  DAT_c04281d4 = 0;
  DAT_c04281dc = 1;
  DAT_c04281f8 = L"AC97 RX";
  DAT_c04281e0 = 8;
  DAT_c04281e8 = 0xe0000000;
  DAT_c04281ec = 0;
  DAT_c04281f4 = 1;
  DAT_c04281c4 = 0x3f051800;
  DAT_c04281d0 = 0x10a0101c;
  DAT_c04281e4 = 0x23f51800;
  DAT_c04281f0 = 0x10a0101c;
  DAT_c04282bc = 1;
  DAT_c04282d8 = L"I2S TX";
  DAT_c04282c0 = 8;
  DAT_c04282c8 = 0;
  DAT_c04282cc = 0xe0000000;
  DAT_c04282d4 = 0;
  DAT_c04282dc = 1;
  DAT_c04282f8 = L"I2S RX";
  DAT_c04282e0 = 8;
  DAT_c04282e8 = 0xe0000000;
  DAT_c04282ec = 0;
  DAT_c04282f4 = 1;
  DAT_c04282c4 = 0x3f251800;
  DAT_c04282d0 = 0x10a0201c;
  DAT_c04282e4 = 0x27f51800;
  DAT_c04282f0 = 0x10a0201c;
  DAT_c042837c = 1;
  DAT_c0428398 = L"I2S2 TX";
  DAT_c0428380 = 8;
  DAT_c0428388 = 0;
  DAT_c042838c = 0xe0000000;
  DAT_c0428394 = 0;
  DAT_c042839c = 1;
  DAT_c04283b8 = L"I2S2 RX";
  DAT_c04283a0 = 8;
  DAT_c04283a8 = 0xe0000000;
  DAT_c04283ac = 0;
  DAT_c04283b4 = 1;
  DAT_c0428384 = 0x3ee51800;
  DAT_c0428390 = 0x10a0001c;
  DAT_c04283a4 = 0x1ff51800;
  DAT_c04283b0 = 0x10a0001c;
  DAT_c04282fc = 1;
  DAT_c0428318 = L"SDIO0 TX";
  DAT_c0428300 = 8;
  DAT_c0428304 = 0x3e8a1800;
  DAT_c0428308 = 0xc0000000;
  DAT_c042830c = 0xe0000000;
  DAT_c0428310 = 0x10600000;
  DAT_c0428314 = 0;
  DAT_c042831c = 1;
  DAT_c0428338 = L"SDIO0 RX";
  DAT_c0428320 = 8;
  DAT_c0428324 = 0x13fa1800;
  DAT_c0428328 = 0xe0000000;
  DAT_c042832c = 0xc0000000;
  DAT_c0428330 = 0x10600004;
  DAT_c0428334 = 1;
  DAT_c04283bc = 1;
  DAT_c04283d8 = L"IDE TX";
  DAT_c04283c0 = 0x28;
  DAT_c04283c4 = 0x3fda1800;
  DAT_c04283c8 = 0xc0000000;
  DAT_c04283cc = 0xf0000000;
  DAT_c04283d0 = 0x18800000;
  DAT_c04283d4 = 0;
  DAT_c04283dc = 1;
  DAT_c04283f8 = L"IDE RX";
  DAT_c04283e0 = 0x28;
  DAT_c04283e4 = 0x3bfa1800;
  DAT_c04283e8 = 0xf0000000;
  DAT_c04283ec = 0xc0000000;
  DAT_c04283f0 = 0x18800000;
  DAT_c04283f4 = 1;
  DAT_c042841c = 1;
  DAT_c0428438 = L"NAND TX";
  DAT_c0428420 = 8;
  DAT_c0428424 = 0x3f7a1800;
  DAT_c0428428 = 0xc0000000;
  DAT_c042842c = 0xf0000000;
  DAT_c0428430 = 0x20000020;
  DAT_c0428434 = 0;
  DAT_c042843c = 1;
  DAT_c0428458 = L"NAND RX";
  DAT_c0428440 = 8;
  DAT_c0428444 = 0x2ffa1800;
  DAT_c0428448 = 0xf0000000;
  DAT_c042844c = 0xc0000000;
  DAT_c0428450 = 0x20000000;
  DAT_c0428454 = 1;
  DAT_c042813c = 1;
  DAT_c0428158 = L"UART0 TX";
  DAT_c0428140 = 8;
  DAT_c0428144 = 0x3e001800;
  DAT_c0428148 = 0x80000000;
  DAT_c042814c = 0xa0000000;
  DAT_c0428150 = 0x10100004;
  DAT_c0428154 = 0;
  DAT_c042815c = 1;
  DAT_c0428178 = L"UART0 RX";
  DAT_c0428160 = 8;
  DAT_c0428164 = 0x3f01800;
  DAT_c0428168 = 0x20000000;
  DAT_c042816c = 0;
  DAT_c0428170 = 0x10100000;
  DAT_c0428174 = 1;
  DAT_c042845c = MmMapIoSpace(0x14002000,0,0x1010,0);
  *(undefined4 *)((int)DAT_c042845c + 0x1000) = 7;
  return;
}



/* c04235d8 HalAllocateDMAChannel */

/* Boundary evidence: original MIPS .pdata c04235d8..c0423723. Semantic name remains unreviewed. */

HLOCAL HalAllocateDMAChannel(void)

{
  HLOCAL hMem;
  HANDLE pvVar1;
  DWORD DVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined **ppuVar5;
  
                    /* 0x35d8  63  HalAllocateDMAChannel */
  FUN_c042326c();
  hMem = LocalAlloc(0x40,0x88);
  if (hMem != (HLOCAL)0x0) {
    ppuVar5 = &PTR_u___DMA_CHANNEL_MUTEX_0___c04280f4;
    iVar4 = 0;
    do {
      pvVar1 = CreateMutexW((LPSECURITY_ATTRIBUTES)0x0,0,(LPCWSTR)*ppuVar5);
      *(HANDLE *)((int)hMem + 0x14) = pvVar1;
      if (pvVar1 == (HANDLE)0x0) goto LAB_c04236b0;
      DVar2 = GetLastError();
      if (DVar2 != 0xb7) {
        *(int *)((int)hMem + 0xc) = iVar4;
        break;
      }
      CloseHandle(*(HANDLE *)((int)hMem + 0x14));
      ppuVar5 = ppuVar5 + 1;
      iVar4 = iVar4 + 1;
    } while ((int)ppuVar5 < -0x3fbd7ecc);
    if (iVar4 != 0x10) {
      WaitForSingleObject(*(HANDLE *)((int)hMem + 0x14),0xffffffff);
      puVar3 = (undefined4 *)((*(int *)((int)hMem + 0xc) + -0x4bffe0) * 0x100);
      *(undefined4 **)((int)hMem + 0x24) = puVar3;
      WRITE_PORT_ULONG(puVar3,0);
      return hMem;
    }
    NKDbgPrintfW(L"No DDMA Channels available\r\n");
LAB_c04236b0:
    LocalFree(hMem);
  }
  return (HLOCAL)0x0;
}



/* c0423724 HalAllocateCommonBuffer */

/* Boundary evidence: original MIPS .pdata c0423724..c0423777. Semantic name remains unreviewed. */

void HalAllocateCommonBuffer(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  undefined4 local_10;
  undefined4 local_c;
  
                    /* 0x3724  2  HalAllocateCommonBuffer */
  local_10 = 0;
  local_c = 0;
  AllocPhysMem(param_2,0x204,0x20,0,&local_10);
  *param_3 = local_10;
  param_3[1] = local_c;
  return;
}



/* c0423778 HalFreeDMAChannel */

/* Boundary evidence: original MIPS .pdata c0423778..c0423817. Semantic name remains unreviewed. */

void HalFreeDMAChannel(HLOCAL param_1)

{
  DWORD DVar1;
  
                    /* 0x3778  69  HalFreeDMAChannel */
  if ((param_1 != (HLOCAL)0x0) &&
     (DVar1 = WaitForSingleObject(*(HANDLE *)((int)param_1 + 0x14),0), DVar1 == 0)) {
    WRITE_PORT_ULONG(*(undefined4 **)((int)param_1 + 0x24),0);
    if (*(int *)((int)param_1 + 0x28) != 0) {
      FreePhysMem();
    }
    if (*(int *)((int)param_1 + 0x2c) != 0) {
      FreePhysMem();
    }
    ReleaseMutex(*(HANDLE *)((int)param_1 + 0x14));
    CloseHandle(*(HANDLE *)((int)param_1 + 0x14));
    LocalFree(param_1);
  }
  return;
}



/* c0423818 HalFreeCommonBuffer */

/* Boundary evidence: original MIPS .pdata c0423818..c0423833. Semantic name remains unreviewed. */

void HalFreeCommonBuffer(void)

{
  undefined4 in_stack_00000010;
  
                    /* 0x3818  3  HalFreeCommonBuffer */
  FreePhysMem(in_stack_00000010);
  return;
}



/* c0423834 FUN_c0423834 */

/* Boundary evidence: original MIPS .pdata c0423834..c04238f7. Semantic name remains unreviewed. */

void FUN_c0423834(undefined4 *param_1)

{
  NKDbgPrintfW(L"Descriptor @ 0x%08X\r\n",param_1);
  NKDbgPrintfW(L"cmd0    %08X\r\n",*param_1);
  NKDbgPrintfW(L"cmd1    %08X\r\n",param_1[1]);
  NKDbgPrintfW(L"source0 %08X\r\n",param_1[2]);
  NKDbgPrintfW(L"source1 %08X\r\n",param_1[3]);
  NKDbgPrintfW(L"dest0   %08X\r\n",param_1[4]);
  NKDbgPrintfW(L"dest1   %08X\r\n",param_1[5]);
  NKDbgPrintfW(L"stat    %08X\r\n",param_1[6]);
  NKDbgPrintfW(L"nxt_ptr %08X (%08X)\r\n",param_1[7],param_1[7] << 5);
  NKDbgPrintfW(L"================\r\n");
  return;
}



/* c04238f8 FUN_c04238f8 */

/* Boundary evidence: original MIPS .pdata c04238f8..c0423993. Semantic name remains unreviewed. */

void FUN_c04238f8(undefined4 *param_1)

{
  NKDbgPrintfW(L"DDMA Channel @ 0x%08X\r\n",param_1);
  NKDbgPrintfW(L"cfg      %08X\r\n",*param_1);
  NKDbgPrintfW(L"des_ptr  %08X\r\n",param_1[1]);
  NKDbgPrintfW(L"stat_ptr %08X\r\n",param_1[2]);
  NKDbgPrintfW(L"irq      %08X\r\n",param_1[4]);
  NKDbgPrintfW(L"stat     %08X\r\n",param_1[5]);
  NKDbgPrintfW(L"bytecnt  %08X\r\n",param_1[6]);
  NKDbgPrintfW(L"=================\r\n");
  return;
}



/* c0423994 FUN_c0423994 */

/* Boundary evidence: original MIPS .pdata c0423994..c0423a2b. Semantic name remains unreviewed. */

void FUN_c0423994(int param_1)

{
  NKDbgPrintfW(L"--------> DMA CHANNEL %d <----------\r\n",*(undefined4 *)(param_1 + 0xc));
  NKDbgPrintfW(L"DESCRIPTOR A %08X (phys=%08X)\r\n",*(undefined4 *)(param_1 + 0x40),
               *(undefined4 *)(param_1 + 0x48));
  NKDbgPrintfW(L"DESCRIPTOR B %08X (phys=%08X)\r\n",*(undefined4 *)(param_1 + 0x44),
               *(undefined4 *)(param_1 + 0x50));
  NKDbgPrintfW(L"Buffer A     %08X (phys=%08X)\r\n",*(undefined4 *)(param_1 + 0x28),
               *(undefined4 *)(param_1 + 0x30));
  NKDbgPrintfW(L"buffer B     %08X (phys=%08X)\r\n",*(undefined4 *)(param_1 + 0x2c),
               *(undefined4 *)(param_1 + 0x38));
  FUN_c04238f8(*(undefined4 **)(param_1 + 0x24));
  FUN_c0423834(*(undefined4 **)(param_1 + 0x40));
  FUN_c0423834(*(undefined4 **)(param_1 + 0x44));
  return;
}



/* c0423a2c HalInitDmaChannel */

/* Boundary evidence: original MIPS .pdata c0423a2c..c0423c97. Semantic name remains unreviewed. */

undefined4 HalInitDmaChannel(int param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  wchar_t *pwVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  uint uVar5;
  int *piVar6;
  uint *puVar7;
  
                    /* 0x3a2c  73  HalInitDmaChannel */
  if (param_2 < 0x19) {
    if ((&DAT_c042813c)[param_2 * 8] != 0) {
      *(undefined4 **)(param_1 + 0x18) = &DAT_c042813c + param_2 * 8;
      *(int *)(param_1 + 0x10) = param_3;
      uVar4 = (&DAT_c0428158)[param_2 * 8];
      piVar6 = (int *)(param_1 + 0x30);
      *(int *)(param_1 + 0x20) = param_2;
      *(undefined4 *)(param_1 + 0x60) = uVar4;
      *piVar6 = 0;
      *(undefined4 *)(param_1 + 0x34) = 0;
      *(undefined4 *)(param_1 + 0x38) = 0;
      *(undefined4 *)(param_1 + 0x3c) = 0;
      iVar1 = AllocPhysMem(param_3 << 1,0x204,0x20,0,piVar6);
      puVar7 = (uint *)(param_1 + 0x48);
      *(int *)(param_1 + 0x28) = iVar1;
      *(int *)(param_1 + 0x2c) = iVar1 + param_3;
      *(int *)(param_1 + 0x38) = *piVar6 + param_3;
      *puVar7 = 0;
      *(undefined4 *)(param_1 + 0x4c) = 0;
      *(undefined4 *)(param_1 + 0x50) = 0;
      *(undefined4 *)(param_1 + 0x54) = 0;
      iVar1 = AllocPhysMem(0x80,0x204,0x20,0,puVar7);
      *(int *)(param_1 + 0x40) = iVar1;
      *(int *)(param_1 + 0x44) = iVar1 + 0x40;
      *(uint *)(param_1 + 0x50) = *puVar7 + 0x40;
      uVar5 = (&DAT_c0428144)[param_2 * 8];
      if (param_4 != 0) {
        *(undefined4 *)(param_1 + 0x1c) = 1;
        uVar5 = uVar5 | 0x100;
      }
      if ((&DAT_c0428154)[param_2 * 8] == 0) {
        WRITE_PORT_ULONG((undefined4 *)(iVar1 + 0x10),(&DAT_c0428150)[param_2 * 8]);
        WRITE_PORT_ULONG((undefined4 *)(*(int *)(param_1 + 0x44) + 0x10),
                         (&DAT_c0428150)[param_2 * 8]);
        WRITE_PORT_ULONG((undefined4 *)(*(int *)(param_1 + 0x40) + 8),*piVar6);
        puVar3 = (undefined4 *)(*(int *)(param_1 + 0x44) + 8);
      }
      else {
        WRITE_PORT_ULONG((undefined4 *)(iVar1 + 8),(&DAT_c0428150)[param_2 * 8]);
        WRITE_PORT_ULONG((undefined4 *)(*(int *)(param_1 + 0x44) + 8),(&DAT_c0428150)[param_2 * 8]);
        WRITE_PORT_ULONG((undefined4 *)(*(int *)(param_1 + 0x40) + 0x10),*piVar6);
        puVar3 = (undefined4 *)(*(int *)(param_1 + 0x44) + 0x10);
      }
      WRITE_PORT_ULONG(puVar3,*(undefined4 *)(param_1 + 0x38));
      WRITE_PORT_ULONG((undefined4 *)(*(int *)(param_1 + 0x40) + 0xc),(&DAT_c0428148)[param_2 * 8]);
      WRITE_PORT_ULONG((undefined4 *)(*(int *)(param_1 + 0x44) + 0xc),(&DAT_c0428148)[param_2 * 8]);
      WRITE_PORT_ULONG((undefined4 *)(*(int *)(param_1 + 0x40) + 0x14),(&DAT_c042814c)[param_2 * 8])
      ;
      WRITE_PORT_ULONG((undefined4 *)(*(int *)(param_1 + 0x44) + 0x14),(&DAT_c042814c)[param_2 * 8])
      ;
      WRITE_PORT_ULONG(*(undefined4 **)(param_1 + 0x40),uVar5 | 4);
      WRITE_PORT_ULONG(*(undefined4 **)(param_1 + 0x44),uVar5 | 4);
      WRITE_PORT_ULONG((undefined4 *)(*(int *)(param_1 + 0x40) + 0x1c),
                       *(uint *)(param_1 + 0x50) >> 5);
      WRITE_PORT_ULONG((undefined4 *)(*(int *)(param_1 + 0x44) + 0x1c),*puVar7 >> 5);
      WRITE_PORT_ULONG(*(undefined4 **)(param_1 + 0x24),(&DAT_c0428140)[param_2 * 8]);
      WRITE_PORT_ULONG((undefined4 *)(*(int *)(param_1 + 0x24) + 4),*puVar7);
      *(uint *)(param_1 + 0x84) = *puVar7;
      return 1;
    }
    pwVar2 = L"HalInitDmaChannel: Device %d does not have valid configuration\r\n";
  }
  else {
    pwVar2 = L"HalInitDmaChannel: Device %d is out of range\r\n";
  }
  NKDbgPrintfW(pwVar2);
  return 0;
}



/* c0423c98 HalGetNextDMABuffer */

/* Boundary evidence: original MIPS .pdata c0423c98..c0423e67. Semantic name remains unreviewed. */

undefined4 HalGetNextDMABuffer(int param_1)

{
  int iVar1;
  uint uVar2;
  wchar_t *pwVar3;
  
                    /* 0x3c98  72  HalGetNextDMABuffer */
  pwVar3 = *(wchar_t **)(param_1 + 0x60);
  if ((((pwVar3 == L"UART0 TX") || (pwVar3 == L"UART0 RX")) || (pwVar3 == L"SPI TX")) ||
     (pwVar3 == L"SPI RX")) {
    iVar1 = READ_PORT_ULONG((undefined4 *)(*(int *)(param_1 + 0x24) + 4));
  }
  else {
    iVar1 = *(int *)(param_1 + 0x84);
  }
  if (iVar1 == *(int *)(param_1 + 0x48)) {
    uVar2 = READ_PORT_ULONG((undefined4 *)(*(int *)(param_1 + 0x24) + 0x14));
    if ((uVar2 & 1) == 0) {
      if ((*(int *)(*(int *)(param_1 + 0x18) + 0x18) != 0) &&
         (uVar2 = READ_PORT_ULONG(*(undefined4 **)(param_1 + 0x44)), (uVar2 & 0x80000000) == 0))
      goto LAB_c0423e24;
      if (*(int *)(*(int *)(param_1 + 0x18) + 0x18) != 0) goto LAB_c0423e4c;
      uVar2 = READ_PORT_ULONG(*(undefined4 **)(param_1 + 0x40));
    }
    else {
      uVar2 = READ_PORT_ULONG(*(undefined4 **)(param_1 + 0x40));
    }
    if ((uVar2 & 0x80000000) != 0) {
LAB_c0423e24:
      *(undefined4 *)(param_1 + 0x5c) = 0;
      return *(undefined4 *)(param_1 + 0x2c);
    }
  }
  else if (iVar1 == *(int *)(param_1 + 0x50)) {
    uVar2 = READ_PORT_ULONG((undefined4 *)(*(int *)(param_1 + 0x24) + 0x14));
    if ((uVar2 & 1) == 0) {
      if ((*(int *)(*(int *)(param_1 + 0x18) + 0x18) != 0) &&
         (uVar2 = READ_PORT_ULONG(*(undefined4 **)(param_1 + 0x40)), (uVar2 & 0x80000000) == 0))
      goto LAB_c0423e4c;
      if (*(int *)(*(int *)(param_1 + 0x18) + 0x18) != 0) goto LAB_c0423e24;
      uVar2 = READ_PORT_ULONG(*(undefined4 **)(param_1 + 0x44));
    }
    else {
      uVar2 = READ_PORT_ULONG(*(undefined4 **)(param_1 + 0x44));
    }
    if ((uVar2 & 0x80000000) == 0) goto LAB_c0423e24;
  }
  else {
    NKDbgPrintfW(L"HalGetNextDMABuffer(%s): Unknown descriptor in use 0x%08X\r\n",
                 *(undefined4 *)(param_1 + 0x60),iVar1);
    FUN_c0423994(param_1);
  }
LAB_c0423e4c:
  *(undefined4 *)(param_1 + 0x58) = 0;
  return *(undefined4 *)(param_1 + 0x28);
}



/* c0423e68 HalActivateDMABuffer */

/* Boundary evidence: original MIPS .pdata c0423e68..c0423f23. Semantic name remains unreviewed. */

undefined4 HalActivateDMABuffer(int param_1,int param_2,undefined4 param_3)

{
  uint uVar1;
  undefined4 *puVar2;
  
                    /* 0x3e68  61  HalActivateDMABuffer */
  if (param_2 == *(int *)(param_1 + 0x28)) {
    puVar2 = *(undefined4 **)(param_1 + 0x40);
    *(undefined4 *)(param_1 + 0x58) = 1;
  }
  else {
    if (param_2 != *(int *)(param_1 + 0x2c)) {
      NKDbgPrintfW(L"HalActivateDMABuffer(%s) Invalid buffer address 0x%X\r\n",
                   *(undefined4 *)(param_1 + 0x60),param_2);
      return 0;
    }
    puVar2 = *(undefined4 **)(param_1 + 0x44);
    *(undefined4 *)(param_1 + 0x5c) = 1;
  }
  WRITE_PORT_ULONG(puVar2 + 1,param_3);
  uVar1 = READ_PORT_ULONG(puVar2);
  WRITE_PORT_ULONG(puVar2,uVar1 | 0x80000000);
  WRITE_PORT_ULONG((undefined4 *)(*(int *)(param_1 + 0x24) + 0xc),1);
  return 1;
}



/* c0423f24 HalStartDMA */

/* Boundary evidence: original MIPS .pdata c0423f24..c0423f83. Semantic name remains unreviewed. */

undefined4 HalStartDMA(int param_1)

{
  uint uVar1;
  
                    /* 0x3f24  77  HalStartDMA */
  WRITE_PORT_ULONG((undefined4 *)(*(int *)(param_1 + 0x24) + 0x10),0);
  uVar1 = READ_PORT_ULONG(*(undefined4 **)(param_1 + 0x24));
  WRITE_PORT_ULONG(*(undefined4 **)(param_1 + 0x24),uVar1 | 1);
  CacheSync(4);
  WRITE_PORT_ULONG((undefined4 *)(*(int *)(param_1 + 0x24) + 0xc),1);
  return 1;
}



/* c0423f84 HalStopDMA */

/* Boundary evidence: original MIPS .pdata c0423f84..c0424057. Semantic name remains unreviewed. */

undefined4 HalStopDMA(int param_1)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  
                    /* 0x3f84  79  HalStopDMA */
  uVar1 = READ_PORT_ULONG(*(undefined4 **)(param_1 + 0x24));
  WRITE_PORT_ULONG(*(undefined4 **)(param_1 + 0x24),uVar1 & 0xfffffffe);
  do {
    iVar2 = READ_PORT_ULONG((undefined4 *)(*(int *)(param_1 + 0x24) + 0x14));
  } while (iVar2 == 0);
  uVar1 = READ_PORT_ULONG(*(undefined4 **)(param_1 + 0x40));
  WRITE_PORT_ULONG(*(undefined4 **)(param_1 + 0x40),uVar1 & 0x7fffffff);
  *(undefined4 *)(param_1 + 0x58) = 0;
  uVar1 = READ_PORT_ULONG(*(undefined4 **)(param_1 + 0x44));
  WRITE_PORT_ULONG(*(undefined4 **)(param_1 + 0x44),uVar1 & 0x7fffffff);
  *(undefined4 *)(param_1 + 0x5c) = 0;
  WRITE_PORT_ULONG((undefined4 *)(*(int *)(param_1 + 0x24) + 0x14),6);
  WRITE_PORT_ULONG((undefined4 *)(*(int *)(param_1 + 0x24) + 0x10),0);
  uVar3 = READ_PORT_ULONG((undefined4 *)(*(int *)(param_1 + 0x24) + 4));
  *(undefined4 *)(param_1 + 0x84) = uVar3;
  return 1;
}



/* c0424058 HalCheckForDMAInterrupt */

/* Boundary evidence: original MIPS .pdata c0424058..c04240fb. Semantic name remains unreviewed. */

uint HalCheckForDMAInterrupt(int param_1)

{
  uint uVar1;
  uint uVar2;
  
                    /* 0x4058  64  HalCheckForDMAInterrupt */
  uVar2 = 0;
  uVar1 = READ_PORT_ULONG((undefined4 *)(*(int *)(param_1 + 0x24) + 0x14));
  if ((uVar1 & 1) == 0) {
    if ((*(int *)(param_1 + 0x58) == 1) &&
       (uVar1 = READ_PORT_ULONG(*(undefined4 **)(param_1 + 0x40)), (uVar1 & 0x80000000) == 0)) {
      uVar2 = 1;
    }
    if ((*(int *)(param_1 + 0x5c) == 1) &&
       (uVar1 = READ_PORT_ULONG(*(undefined4 **)(param_1 + 0x44)), (uVar1 & 0x80000000) == 0)) {
      uVar2 = uVar2 | 2;
    }
  }
  return uVar2;
}



/* c04240fc HalAckDMAInterrupt */

undefined4 HalAckDMAInterrupt(int param_1,int param_2)

{
  undefined4 uVar1;
  
                    /* 0x40fc  60  HalAckDMAInterrupt */
  if (param_2 == 1) {
    *(undefined4 *)(param_1 + 0x58) = 2;
  }
  else {
    if (param_2 == 2) {
      uVar1 = *(undefined4 *)(param_1 + 0x48);
      *(undefined4 *)(param_1 + 0x5c) = 2;
      goto LAB_c0424140;
    }
    if (*(int *)(param_1 + 0x84) != *(int *)(param_1 + 0x48)) {
      *(int *)(param_1 + 0x84) = *(int *)(param_1 + 0x48);
      return 1;
    }
  }
  uVar1 = *(undefined4 *)(param_1 + 0x50);
LAB_c0424140:
  *(undefined4 *)(param_1 + 0x84) = uVar1;
  return 1;
}



/* c0424154 HalSetDMAForReceive */

/* Boundary evidence: original MIPS .pdata c0424154..c0424197. Semantic name remains unreviewed. */

undefined4 HalSetDMAForReceive(int param_1)

{
                    /* 0x4154  75  HalSetDMAForReceive */
  HalActivateDMABuffer(param_1,*(int *)(param_1 + 0x28),*(undefined4 *)(param_1 + 0x10));
  HalActivateDMABuffer(param_1,*(int *)(param_1 + 0x2c),*(undefined4 *)(param_1 + 0x10));
  return 1;
}



/* c0424198 HalGetDMAHwIntr */

uint HalGetDMAHwIntr(int param_1)

{
                    /* 0x4198  71  HalGetDMAHwIntr */
  return *(int *)(param_1 + 0xc) + 0xa0U & 0xff;
}



/* c04241a8 HalGetDMABufferRxSize */

/* Boundary evidence: original MIPS .pdata c04241a8..c04242c3. Semantic name remains unreviewed. */

int HalGetDMABufferRxSize(int param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  
                    /* 0x41a8  70  HalGetDMABufferRxSize */
  if (param_2 == *(int *)(param_1 + 0x28)) {
    uVar1 = READ_PORT_ULONG(*(undefined4 **)(param_1 + 0x40));
    uVar3 = *(undefined4 *)(param_1 + 0x50);
  }
  else {
    if (param_2 != *(int *)(param_1 + 0x2c)) {
      NKDbgPrintfW(L"HalGetDMABufferRxSize(%s): Invalid buffer 0x%08X\r\n",
                   *(undefined4 *)(param_1 + 0x60),param_2);
      return 0;
    }
    uVar1 = READ_PORT_ULONG(*(undefined4 **)(param_1 + 0x44));
    uVar3 = *(undefined4 *)(param_1 + 0x48);
  }
  if ((uVar1 & 0x80000000) == 0) {
    iVar2 = *(int *)(param_1 + 0x10);
  }
  else {
    uVar1 = READ_PORT_ULONG(*(undefined4 **)(param_1 + 0x24));
    WRITE_PORT_ULONG(*(undefined4 **)(param_1 + 0x24),uVar1 & 0xfffffffe);
    do {
      iVar2 = READ_PORT_ULONG((undefined4 *)(*(int *)(param_1 + 0x24) + 0x14));
    } while (iVar2 == 0);
    iVar2 = READ_PORT_ULONG((undefined4 *)(*(int *)(param_1 + 0x24) + 0x18));
    iVar2 = *(int *)(param_1 + 0x10) - iVar2;
    WRITE_PORT_ULONG((undefined4 *)(*(int *)(param_1 + 0x24) + 0x14),6);
    WRITE_PORT_ULONG((undefined4 *)(*(int *)(param_1 + 0x24) + 4),uVar3);
    HalStartDMA(param_1);
  }
  return iVar2;
}



/* c04242c4 HalWaitForDMA */

/* Boundary evidence: original MIPS .pdata c04242c4..c0424337. Semantic name remains unreviewed. */

void HalWaitForDMA(int param_1)

{
  uint uVar1;
  
  do {
    uVar1 = READ_PORT_ULONG(*(undefined4 **)(param_1 + 0x40));
    if ((uVar1 & 0x80000000) == 0) {
      uVar1 = READ_PORT_ULONG(*(undefined4 **)(param_1 + 0x44));
      if ((uVar1 & 0x80000000) == 0) {
        return;
      }
    }
    Sleep(0);
  } while( true );
}



/* c0424338 HalDMAIsUnderflowed */

/* Boundary evidence: original MIPS .pdata c0424338..c042438f. Semantic name remains unreviewed. */

undefined4 HalDMAIsUnderflowed(int param_1)

{
  uint uVar1;
  
                    /* 0x4338  68  HalDMAIsUnderflowed */
  uVar1 = READ_PORT_ULONG(*(undefined4 **)(param_1 + 0x40));
  if (((uVar1 & 0x80000000) == 0) &&
     (uVar1 = READ_PORT_ULONG(*(undefined4 **)(param_1 + 0x44)), (uVar1 & 0x80000000) == 0)) {
    return 1;
  }
  return 0;
}



/* c0424390 HalReconfigureDMA */

/* Boundary evidence: original MIPS .pdata c0424390..c0424563. Semantic name remains unreviewed. */

undefined4 HalReconfigureDMA(int param_1,int param_2)

{
  undefined4 uVar1;
  wchar_t *pwVar2;
  undefined4 *puVar3;
  uint uVar4;
  
                    /* 0x4390  74  HalReconfigureDMA */
  if (*(int *)(param_1 + 0x20) == param_2) {
LAB_c0424548:
    uVar1 = 1;
  }
  else {
    if (param_2 < 0x19) {
      if ((&DAT_c042813c)[param_2 * 8] != 0) {
        HalStopDMA(param_1);
        *(undefined4 *)(param_1 + 0x60) = (&DAT_c0428158)[param_2 * 8];
        *(int *)(param_1 + 0x20) = param_2;
        *(undefined4 **)(param_1 + 0x18) = &DAT_c042813c + param_2 * 8;
        uVar4 = (&DAT_c0428144)[param_2 * 8];
        if (*(int *)(param_1 + 0x1c) != 0) {
          uVar4 = uVar4 | 0x100;
        }
        if ((&DAT_c0428154)[param_2 * 8] == 0) {
          WRITE_PORT_ULONG((undefined4 *)(*(int *)(param_1 + 0x40) + 0x10),
                           (&DAT_c0428150)[param_2 * 8]);
          WRITE_PORT_ULONG((undefined4 *)(*(int *)(param_1 + 0x44) + 0x10),
                           (&DAT_c0428150)[param_2 * 8]);
          WRITE_PORT_ULONG((undefined4 *)(*(int *)(param_1 + 0x40) + 8),
                           *(undefined4 *)(param_1 + 0x30));
          puVar3 = (undefined4 *)(*(int *)(param_1 + 0x44) + 8);
        }
        else {
          WRITE_PORT_ULONG((undefined4 *)(*(int *)(param_1 + 0x40) + 8),(&DAT_c0428150)[param_2 * 8]
                          );
          WRITE_PORT_ULONG((undefined4 *)(*(int *)(param_1 + 0x44) + 8),(&DAT_c0428150)[param_2 * 8]
                          );
          WRITE_PORT_ULONG((undefined4 *)(*(int *)(param_1 + 0x40) + 0x10),
                           *(undefined4 *)(param_1 + 0x30));
          puVar3 = (undefined4 *)(*(int *)(param_1 + 0x44) + 0x10);
        }
        WRITE_PORT_ULONG(puVar3,*(undefined4 *)(param_1 + 0x38));
        WRITE_PORT_ULONG((undefined4 *)(*(int *)(param_1 + 0x40) + 0xc),(&DAT_c0428148)[param_2 * 8]
                        );
        WRITE_PORT_ULONG((undefined4 *)(*(int *)(param_1 + 0x44) + 0xc),(&DAT_c0428148)[param_2 * 8]
                        );
        WRITE_PORT_ULONG((undefined4 *)(*(int *)(param_1 + 0x40) + 0x14),
                         (&DAT_c042814c)[param_2 * 8]);
        WRITE_PORT_ULONG((undefined4 *)(*(int *)(param_1 + 0x44) + 0x14),
                         (&DAT_c042814c)[param_2 * 8]);
        WRITE_PORT_ULONG(*(undefined4 **)(param_1 + 0x40),uVar4 | 4);
        WRITE_PORT_ULONG(*(undefined4 **)(param_1 + 0x44),uVar4 | 4);
        WRITE_PORT_ULONG((undefined4 *)(*(int *)(param_1 + 0x40) + 0x1c),
                         *(uint *)(param_1 + 0x50) >> 5);
        WRITE_PORT_ULONG((undefined4 *)(*(int *)(param_1 + 0x44) + 0x1c),
                         *(uint *)(param_1 + 0x48) >> 5);
        WRITE_PORT_ULONG(*(undefined4 **)(param_1 + 0x24),(&DAT_c0428140)[param_2 * 8]);
        WRITE_PORT_ULONG((undefined4 *)(*(int *)(param_1 + 0x24) + 4),
                         *(undefined4 *)(param_1 + 0x48));
        goto LAB_c0424548;
      }
      pwVar2 = L"HalReconfigureDMA: Device %d does not have valid configuration\r\n";
    }
    else {
      pwVar2 = L"HalReconfigureDMA: Device %d is out of range\r\n";
    }
    NKDbgPrintfW(pwVar2,param_2);
    uVar1 = 0;
  }
  return uVar1;
}



/* c0424564 HalSetupMdlDMA */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Boundary evidence: original MIPS .pdata c0424564..c04248c7. Semantic name remains unreviewed. */

undefined4 HalSetupMdlDMA(int param_1,int *param_2,int param_3)

{
  int *piVar1;
  undefined4 uVar2;
  void *_Dst;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int *piVar6;
  uint uVar7;
  uint uVar8;
  uint *puVar9;
  uint uVar10;
  uint *puVar11;
  int iVar12;
  uint uVar13;
  
                    /* 0x4564  76  HalSetupMdlDMA */
  iVar12 = 0;
  for (piVar6 = param_2; piVar6 != (int *)0x0; piVar6 = (int *)*piVar6) {
    iVar5 = 0xc;
    if (_DAT_00005b04 != 0x1000) {
      iVar5 = 10;
    }
    iVar12 = (((_DAT_00005b04 - 1 & piVar6[1]) + piVar6[2] + _DAT_00005b04) - 1 >> iVar5) + iVar12;
  }
  uVar8 = iVar12 + 1;
  if (*(uint *)(param_1 + 0x70) < uVar8) {
    if (*(int *)(param_1 + 100) != 0) {
      FreePhysMem();
    }
    *(uint *)(param_1 + 0x70) = uVar8;
    uVar2 = AllocPhysMem(uVar8 * 0x20,0x204,0x20,0,param_1 + 0x68);
    *(undefined4 *)(param_1 + 100) = uVar2;
  }
  puVar9 = *(uint **)(param_1 + 100);
  uVar8 = *(uint *)(param_1 + 0x68);
  if ((param_2[1] & 0x1fU) == 0) {
    do {
      iVar12 = 0xc;
      if (_DAT_00005b04 != 0x1000) {
        iVar12 = 10;
      }
      uVar13 = param_2[2];
      uVar3 = ((_DAT_00005b04 - 1 & param_2[1]) + uVar13 + _DAT_00005b04) - 1 >> iVar12;
      uVar7 = 0;
      uVar10 = uVar8;
      if (uVar3 != 0) {
        do {
          if (param_3 == 0) {
            puVar9[2] = param_2[uVar7 + 6];
            puVar9[4] = *(uint *)(*(int *)(param_1 + 0x18) + 0x14);
            if (uVar7 == 0) {
              puVar9[2] = param_2[5] + puVar9[2];
            }
          }
          else {
            puVar9[2] = *(uint *)(*(int *)(param_1 + 0x18) + 0x14);
            puVar9[4] = param_2[uVar7 + 6];
            if (uVar7 == 0) {
              puVar9[4] = param_2[5] + puVar9[4];
            }
          }
          puVar9[3] = *(uint *)(*(int *)(param_1 + 0x18) + 0xc);
          puVar9[5] = *(uint *)(*(int *)(param_1 + 0x18) + 0x10);
          *puVar9 = *(uint *)(*(int *)(param_1 + 0x18) + 8) | 0x80000004;
          uVar4 = _DAT_00005b04;
          if (uVar7 == 0) {
            uVar4 = _DAT_00005b04 - param_2[5];
          }
          if (uVar13 < uVar4) {
            uVar4 = uVar13;
          }
          puVar9[1] = uVar4;
          uVar7 = uVar7 + 1;
          puVar9[7] = uVar10 + 0x20 >> 5;
          uVar13 = uVar13 - uVar4;
          uVar8 = uVar8 + 0x20;
          puVar9 = puVar9 + 8;
          uVar10 = uVar10 + 0x20;
        } while (uVar7 < uVar3);
      }
      param_2 = (int *)*param_2;
    } while (param_2 != (int *)0x0);
  }
  else {
    uVar10 = 0;
    piVar6 = param_2;
    do {
      piVar1 = piVar6 + 2;
      piVar6 = (int *)*piVar6;
      uVar10 = *piVar1 + uVar10;
    } while (piVar6 != (int *)0x0);
    puVar11 = (uint *)(param_1 + 0x78);
    *(uint *)(param_1 + 0x80) = uVar10;
    _Dst = (void *)AllocPhysMem(uVar10,0x204,0x20,0,puVar11);
    *(void **)(param_1 + 0x74) = _Dst;
    if (_Dst == (void *)0x0) {
      return 0;
    }
    if (param_3 == 0) {
      do {
        memcpy(_Dst,(void *)param_2[1],param_2[2]);
        piVar6 = param_2 + 2;
        param_2 = (int *)*param_2;
        _Dst = (void *)((int)_Dst + *piVar6);
      } while (param_2 != (int *)0x0);
      puVar9[2] = *puVar11;
      puVar9[4] = *(uint *)(*(int *)(param_1 + 0x18) + 0x14);
    }
    else {
      puVar9[2] = *(uint *)(*(int *)(param_1 + 0x18) + 0x14);
      puVar9[4] = *puVar11;
    }
    puVar9[3] = *(uint *)(*(int *)(param_1 + 0x18) + 0xc);
    puVar9[5] = *(uint *)(*(int *)(param_1 + 0x18) + 0x10);
    *puVar9 = *(uint *)(*(int *)(param_1 + 0x18) + 8) | 0x80000004;
    puVar9[1] = uVar10;
    puVar9[7] = uVar8 + 0x20 >> 5;
    puVar9 = puVar9 + 8;
  }
  *puVar9 = *puVar9 & 0x7fffffff;
  puVar9[-8] = puVar9[-8] | 0x100;
  *(undefined4 *)(*(int *)(param_1 + 0x24) + 4) = *(undefined4 *)(param_1 + 0x68);
  return 1;
}



/* c04248c8 HalStartMdlDMA */

/* Boundary evidence: original MIPS .pdata c04248c8..c042490f. Semantic name remains unreviewed. */

undefined4 HalStartMdlDMA(int param_1)

{
                    /* 0x48c8  78  HalStartMdlDMA */
  **(uint **)(param_1 + 0x24) = **(uint **)(param_1 + 0x24) | 1;
  CacheSync(4);
  *(undefined4 *)(*(int *)(param_1 + 0x24) + 0xc) = 1;
  return 1;
}



/* c0424910 HalCompleteMdlDMA */

/* Boundary evidence: original MIPS .pdata c0424910..c0424993. Semantic name remains unreviewed. */

undefined4 HalCompleteMdlDMA(int param_1,int *param_2)

{
  void *_Src;
  
                    /* 0x4910  66  HalCompleteMdlDMA */
  _Src = *(void **)(param_1 + 0x74);
  if (_Src != (void *)0x0) {
    if (*(int *)(*(int *)(param_1 + 0x18) + 0x18) != 0) {
      for (; param_2 != (int *)0x0; param_2 = (int *)*param_2) {
        memcpy((void *)param_2[1],_Src,param_2[2]);
        _Src = (void *)((int)_Src + param_2[2]);
      }
    }
    FreePhysMem(*(undefined4 *)(param_1 + 0x74));
    *(undefined4 *)(param_1 + 0x74) = 0;
  }
  return 1;
}



/* c0424994 HalStopMdlDMA */

/* Boundary evidence: original MIPS .pdata c0424994..c0424ae7. Semantic name remains unreviewed. */

undefined4 HalStopMdlDMA(int param_1,int *param_2)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
                    /* 0x4994  80  HalStopMdlDMA */
  uVar1 = READ_PORT_ULONG(*(undefined4 **)(param_1 + 0x24));
  WRITE_PORT_ULONG(*(undefined4 **)(param_1 + 0x24),uVar1 & 0xfffffffe);
  do {
    iVar2 = READ_PORT_ULONG((undefined4 *)(*(int *)(param_1 + 0x24) + 0x14));
  } while (iVar2 == 0);
  WRITE_PORT_ULONG((undefined4 *)(*(int *)(param_1 + 0x24) + 0x14),6);
  if (param_2 != (int *)0x0) {
    *param_2 = 0;
    uVar1 = 0;
    if (*(int *)(param_1 + 0x70) != 1) {
      iVar2 = 0;
      do {
        uVar3 = READ_PORT_ULONG((undefined4 *)(*(int *)(param_1 + 100) + iVar2 + 4));
        *param_2 = (uVar3 & 0x3fffff) + *param_2;
        uVar3 = READ_PORT_ULONG((undefined4 *)(*(int *)(param_1 + 100) + iVar2));
        if ((uVar3 & 0x80000000) != 0) {
          iVar2 = READ_PORT_ULONG((undefined4 *)(*(int *)(param_1 + 0x24) + 0x18));
          *param_2 = *param_2 - iVar2;
          break;
        }
        WRITE_PORT_ULONG((undefined4 *)(*(int *)(param_1 + 100) + iVar2),uVar3 & 0x7fffffff);
        uVar1 = uVar1 + 1;
        iVar2 = iVar2 + 0x20;
      } while (uVar1 < *(int *)(param_1 + 0x70) - 1U);
    }
  }
  WRITE_PORT_ULONG((undefined4 *)(*(int *)(param_1 + 0x24) + 0x10),0);
  return 1;
}



/* c0424ae8 HalCheckForMdlDMAInterrupt */

/* Boundary evidence: original MIPS .pdata c0424ae8..c0424b17. Semantic name remains unreviewed. */

bool HalCheckForMdlDMAInterrupt(int param_1)

{
  uint uVar1;
  
                    /* 0x4ae8  65  HalCheckForMdlDMAInterrupt */
  uVar1 = READ_PORT_ULONG((undefined4 *)(*(int *)(param_1 + 0x24) + 0x14));
  return (uVar1 & 1) == 0;
}



/* c0424b18 HalTranslateBusAddress */

/* Boundary evidence: original MIPS .pdata c0424b18..c0424ba7. Semantic name remains unreviewed. */

undefined4
HalTranslateBusAddress
          (int param_1,undefined4 param_2,undefined4 param_3,int param_4,undefined4 *param_5,
          undefined4 *param_6)

{
                    /* 0x4b18  6  HalTranslateBusAddress */
  if (param_1 == 0) {
    *param_5 = 0;
    *param_6 = param_3;
    param_6[1] = param_4;
  }
  else {
    if (param_1 != 8) {
      return 0;
    }
    NKDbgPrintfW(L"HalTranslateBusAddress::PCMCIA %X\r\n",param_2,param_3,param_4 + 0xf);
    *param_5 = 0;
    *param_6 = param_3;
    param_6[1] = param_4 + 0xf;
  }
  return 1;
}



/* c0424ba8 HalGetBusDataByOffset */

undefined4 HalGetBusDataByOffset(void)

{
                    /* 0x4ba8  4  HalGetBusDataByOffset
                       0x4ba8  5  HalSetBusDataByOffset */
  return 0;
}



/* c0424bb0 HalTranslateSystemAddress */

bool HalTranslateSystemAddress
               (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
               undefined4 *param_5)

{
                    /* 0x4bb0  7  HalTranslateSystemAddress */
  if (param_5 != (undefined4 *)0x0) {
    *param_5 = param_3;
    param_5[1] = param_4;
  }
  return param_5 != (undefined4 *)0x0;
}



/* c0424bd8 CalibrateStallCounter */

void CalibrateStallCounter(void)

{
                    /* 0x4bd8  1  CalibrateStallCounter */
  return;
}



/* c0424be0 CreateBusAccessHandle */

/* Boundary evidence: original MIPS .pdata c0424be0..c0424c27. Semantic name remains unreviewed. */

int * CreateBusAccessHandle(LPCWSTR param_1)

{
  int *piVar1;
  
                    /* 0x4be0  37  CreateBusAccessHandle */
  piVar1 = operator_new(0x14);
  if (piVar1 == (int *)0x0) {
    piVar1 = (int *)0x0;
  }
  else {
    piVar1 = FUN_c04254f0(piVar1,param_1);
  }
  return piVar1;
}



/* c0424c28 SetDevicePowerState */

/* Boundary evidence: original MIPS .pdata c0424c28..c0424c67. Semantic name remains unreviewed. */

BOOL SetDevicePowerState(int param_1,undefined4 param_2,undefined4 param_3)

{
  BOOL BVar1;
  
                    /* 0x4c28  39  SetDevicePowerState */
  if (param_1 == 0) {
    SetLastError(6);
    BVar1 = 0;
  }
  else {
    BVar1 = FUN_c0425760(param_1,param_2,param_3);
  }
  return BVar1;
}



/* c0424c68 GetDevicePowerState */

/* Boundary evidence: original MIPS .pdata c0424c68..c0424ca7. Semantic name remains unreviewed. */

BOOL GetDevicePowerState(HANDLE hDevice,BOOL *pfOn)

{
  BOOL BVar1;
  undefined4 in_a2;
  
                    /* 0x4c68  40  GetDevicePowerState */
  if (hDevice == (HANDLE)0x0) {
    SetLastError(6);
    BVar1 = 0;
  }
  else {
    BVar1 = FUN_c0425804((int)hDevice,pfOn,in_a2);
  }
  return BVar1;
}



/* c0424ca8 TranslateBusAddr */

/* Boundary evidence: original MIPS .pdata c0424ca8..c0424d03. Semantic name remains unreviewed. */

undefined4
TranslateBusAddr(int param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,
                int param_6,undefined4 *param_7,undefined4 *param_8)

{
  undefined4 uVar1;
  
                    /* 0x4ca8  41  TranslateBusAddr */
  if (param_1 == 0) {
    SetLastError(6);
    uVar1 = 0;
  }
  else {
    uVar1 = FUN_c04258c8(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8);
  }
  return uVar1;
}



/* c0424d04 TranslateSystemAddr */

/* Boundary evidence: original MIPS .pdata c0424d04..c0424d57. Semantic name remains unreviewed. */

bool TranslateSystemAddr(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                        undefined4 param_5,undefined4 param_6,undefined4 *param_7)

{
  bool bVar1;
  
                    /* 0x4d04  42  TranslateSystemAddr */
  if (param_1 == 0) {
    SetLastError(6);
    bVar1 = false;
  }
  else {
    bVar1 = FUN_c0425a20(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
  }
  return bVar1;
}



/* c0424d58 SetDeviceConfigurationData */

/* Boundary evidence: original MIPS .pdata c0424d58..c0424dab. Semantic name remains unreviewed. */

int SetDeviceConfigurationData
              (int param_1,int param_2,undefined4 param_3,undefined4 param_4,int param_5,
              uint param_6,undefined4 param_7)

{
  int iVar1;
  
                    /* 0x4d58  43  SetDeviceConfigurationData */
  if (param_1 == 0) {
    SetLastError(6);
    iVar1 = 0;
  }
  else {
    iVar1 = FUN_c0425b4c(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
  }
  return iVar1;
}



/* c0424dac GetDeviceConfigurationData */

/* Boundary evidence: original MIPS .pdata c0424dac..c0424dff. Semantic name remains unreviewed. */

uint GetDeviceConfigurationData
               (int param_1,int param_2,undefined4 param_3,undefined4 param_4,int param_5,
               uint param_6,undefined4 param_7)

{
  uint uVar1;
  
                    /* 0x4dac  44  GetDeviceConfigurationData */
  if (param_1 == 0) {
    SetLastError(6);
    uVar1 = 0;
  }
  else {
    uVar1 = FUN_c0425cb8(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
  }
  return uVar1;
}



/* c0424e00 GetParentDeviceInfo */

/* Boundary evidence: original MIPS .pdata c0424e00..c0424e3f. Semantic name remains unreviewed. */

undefined4 GetParentDeviceInfo(int *param_1,uint *param_2)

{
  undefined4 uVar1;
  
                    /* 0x4e00  45  GetParentDeviceInfo */
  if (param_1 == (int *)0x0) {
    SetLastError(6);
    uVar1 = 0;
  }
  else {
    uVar1 = FUN_c0425e38(param_1,param_2);
  }
  return uVar1;
}



/* c0424e40 GetChildDeviceRemoveState */

/* Boundary evidence: original MIPS .pdata c0424e40..c0424e7f. Semantic name remains unreviewed. */

BOOL GetChildDeviceRemoveState(int param_1,LPVOID param_2)

{
  BOOL BVar1;
  
                    /* 0x4e40  46  GetChildDeviceRemoveState */
  if (param_1 == 0) {
    SetLastError(6);
    BVar1 = 0;
  }
  else {
    BVar1 = FUN_c0425ed8(param_1,param_2);
  }
  return BVar1;
}



/* c0424e80 GetBusNamePrefix */

/* Boundary evidence: original MIPS .pdata c0424e80..c0424ebf. Semantic name remains unreviewed. */

BOOL GetBusNamePrefix(int param_1,LPVOID param_2,int param_3)

{
  BOOL BVar1;
  
                    /* 0x4e80  47  GetBusNamePrefix */
  if (param_1 == 0) {
    SetLastError(6);
    BVar1 = 0;
  }
  else {
    BVar1 = FUN_c0425f64(param_1,param_2,param_3);
  }
  return BVar1;
}



/* c0424ec0 BusTransBusAddrToVirtual */

/* Boundary evidence: original MIPS .pdata c0424ec0..c0424f53. Semantic name remains unreviewed. */

undefined4
BusTransBusAddrToVirtual
          (int param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,
          int param_6,int param_7,int *param_8,uint *param_9)

{
  int iVar1;
  undefined4 uVar2;
  LPVOID pvVar3;
  uint local_10;
  int local_c;
  
                    /* 0x4ec0  48  BusTransBusAddrToVirtual */
  iVar1 = TranslateBusAddr(param_1,param_2,param_3,param_4,param_5,param_6,param_8,&local_10);
  if (iVar1 == 0) {
LAB_c0424ef8:
    uVar2 = 0;
  }
  else {
    if (*param_8 == 0) {
      pvVar3 = MmMapIoSpace(local_10,local_c,param_7,0);
      *param_9 = (uint)pvVar3;
      if (pvVar3 == (LPVOID)0x0) goto LAB_c0424ef8;
    }
    else {
      *param_9 = local_10;
    }
    uVar2 = 1;
  }
  return uVar2;
}



/* c0424f54 BusTransBusAddrToStatic */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Boundary evidence: original MIPS .pdata c0424f54..c0425023. Semantic name remains unreviewed. */

undefined4
BusTransBusAddrToStatic
          (int param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,
          int param_6,int param_7,int *param_8,uint *param_9)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  uint local_10;
  uint local_c;
  
                    /* 0x4f54  49  BusTransBusAddrToStatic */
  iVar1 = TranslateBusAddr(param_1,param_2,param_3,param_4,param_5,param_6,param_8,&local_10);
  if (iVar1 == 0) {
LAB_c0424f8c:
    uVar2 = 0;
  }
  else {
    if (*param_8 == 0) {
      uVar3 = CreateStaticMapping(((int)~(_DAT_00005b04 - 1U) >> 0x1f & local_c) << 0x18 |
                                  (~(_DAT_00005b04 - 1U) & local_10) >> 8,
                                  (_DAT_00005b04 - 1U & local_10) + param_7);
      *param_9 = uVar3;
      if (uVar3 == 0) goto LAB_c0424f8c;
      *param_9 = (_DAT_00005b04 - 1U & local_10) + uVar3;
    }
    else {
      *param_9 = local_10;
    }
    uVar2 = 1;
  }
  return uVar2;
}



/* c0425024 BusIoControl */

/* Boundary evidence: original MIPS .pdata c0425024..c042507f. Semantic name remains unreviewed. */

BOOL BusIoControl(int param_1,DWORD param_2,LPVOID param_3,DWORD param_4,LPVOID param_5,
                 DWORD param_6,LPDWORD param_7,LPOVERLAPPED param_8)

{
  BOOL BVar1;
  
                    /* 0x5024  50  BusIoControl */
  if (param_1 == 0) {
    SetLastError(6);
    BVar1 = 0;
  }
  else {
    BVar1 = FUN_c0425ff0(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8);
  }
  return BVar1;
}



/* c0425080 BusChildIoControl */

/* Boundary evidence: original MIPS .pdata c0425080..c04250bf. Semantic name remains unreviewed. */

BOOL BusChildIoControl(int param_1,DWORD param_2,LPVOID param_3,DWORD param_4)

{
  BOOL BVar1;
  
                    /* 0x5080  57  BusChildIoControl */
  if (param_1 == 0) {
    SetLastError(6);
    BVar1 = 0;
  }
  else {
    BVar1 = FUN_c0426060(param_1,param_2,param_3,param_4);
  }
  return BVar1;
}



/* c04250c0 CloseBusAccessHandle */

/* Boundary evidence: original MIPS .pdata c04250c0..c04250f7. Semantic name remains unreviewed. */

void CloseBusAccessHandle(void *param_1)

{
                    /* 0x50c0  38  CloseBusAccessHandle */
  if (param_1 != (void *)0x0) {
    FUN_c04256fc((int)param_1);
    operator_delete(param_1);
  }
  return;
}



/* c0425100 FUN_c0425100 */

/* Boundary evidence: original MIPS .pdata c0425100..c0425237. Semantic name remains unreviewed. */

undefined4
FUN_c0425100(undefined *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  uVar3 = 0;
  iVar1 = __GetUserKData(0xc);
  iVar2 = GetDirectCallerProcessId();
  if (iVar1 == iVar2) {
    if (param_1 == (undefined *)0x0) {
      SetLastError(0x57);
    }
    else {
      uVar3 = (*(code *)param_1)(param_2,param_3,param_4,param_5,param_6,param_7,param_8);
    }
  }
  else {
    uVar3 = 0;
  }
  return uVar3;
}



/* c0425238 FUN_c0425238 */

/* Boundary evidence: original MIPS .pdata c0425238..c0425243. Semantic name remains unreviewed. */

undefined4 FUN_c0425238(void)

{
  return 1;
}



/* c0425244 CeDriverMapCallbackFunction */

/* Boundary evidence: original MIPS .pdata c0425244..c042532b. Semantic name remains unreviewed. */

undefined4 CeDriverMapCallbackFunction(int param_1)

{
  HANDLE hObject;
  int iVar1;
  undefined4 uVar2;
  
                    /* 0x5244  85  CeDriverMapCallbackFunction */
  if (((DAT_c0428464 == 0) &&
      (hObject = (HANDLE)CreateAPISet(&DAT_c0421f08,0xc,&PTR_LAB_c0421e78,&DAT_c0421ea8),
      hObject != (HANDLE)0xffffffff)) &&
     ((iVar1 = RegisterAPISet(hObject,0x80000007), iVar1 == 0 ||
      (hObject = (HANDLE)InterlockedExchange(&DAT_c0428464,(LONG)hObject), hObject != (HANDLE)0x0)))
     ) {
    CloseHandle(hObject);
  }
  if ((param_1 == 0) || (DAT_c0428464 == 0)) {
    uVar2 = 0;
  }
  else {
    uVar2 = CreateAPIHandle(DAT_c0428464,param_1);
  }
  return uVar2;
}



/* c042532c CeDriverPerformCallback */

/* Boundary evidence: original MIPS .pdata c042532c..c042536b. Semantic name remains unreviewed. */

void CeDriverPerformCallback
               (HANDLE param_1,DWORD param_2,LPVOID param_3,DWORD param_4,LPVOID param_5,
               DWORD param_6,LPDWORD param_7,LPOVERLAPPED param_8)

{
                    /* 0x532c  86  CeDriverPerformCallback */
  DeviceIoControl(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8);
  return;
}



/* c042536c CeDriverGetDirectCaller */

/* WARNING: Removing unreachable block (ram,0xc0425384) */
/* WARNING: Removing unreachable block (ram,0xc0425398) */
/* Boundary evidence: original MIPS .pdata c042536c..c04253bb. Semantic name remains unreviewed. */

undefined4 CeDriverGetDirectCaller(void)

{
  undefined4 uVar1;
  
                    /* 0x536c  83  CeDriverGetDirectCaller */
  uVar1 = GetDirectCallerProcessId();
  return uVar1;
}



/* c04253bc CeDriverDuplicateCallerHandle */

/* WARNING: Removing unreachable block (ram,0xc0425434) */
/* Boundary evidence: original MIPS .pdata c04253bc..c042548f. Semantic name remains unreviewed. */

HANDLE CeDriverDuplicateCallerHandle(HANDLE param_1,DWORD param_2,BOOL param_3,DWORD param_4)

{
  HANDLE hSourceProcessHandle;
  BOOL BVar1;
  HANDLE local_30 [6];
  
                    /* 0x53bc  84  CeDriverDuplicateCallerHandle */
  local_30[0] = (HANDLE)0x0;
  hSourceProcessHandle = (HANDLE)GetDirectCallerProcessId();
  BVar1 = DuplicateHandle(hSourceProcessHandle,param_1,(HANDLE)0x42,local_30,param_2,param_3,param_4
                         );
  if (BVar1 == 0) {
    local_30[0] = (HANDLE)0x0;
  }
  return local_30[0];
}



/* c0425490 FUN_c0425490 */

/* Boundary evidence: original MIPS .pdata c0425490..c04254ef. Semantic name remains unreviewed. */

PHKEY FUN_c0425490(PHKEY param_1,HKEY param_2,LPCWSTR param_3)

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



/* c04254f0 FUN_c04254f0 */

/* Boundary evidence: original MIPS .pdata c04254f0..c04256fb. Semantic name remains unreviewed. */

int * FUN_c04254f0(int *param_1,LPCWSTR param_2)

{
  LSTATUS LVar1;
  int iVar2;
  size_t sVar3;
  wchar_t *_Dest;
  HANDLE pvVar4;
  uint uVar5;
  uint uVar6;
  HKEY local_c98;
  DWORD local_c94;
  int local_c90;
  DWORD local_c8c;
  int local_c88 [2];
  undefined4 local_c80 [2];
  int local_c78;
  wchar_t awStack_858 [260];
  undefined4 local_650 [266];
  WCHAR aWStack_228 [260];
  uint local_20;
  
  local_20 = DAT_c0428134;
  uVar6 = 0xffffffff;
  *param_1 = 0;
  param_1[1] = -1;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = -1;
  FUN_c0425490(&local_c98,(HKEY)0x80000002,param_2);
  local_c90 = 0;
  if (local_c98 != (HKEY)0x0) {
    local_c94 = 4;
    LVar1 = RegQueryValueExW(local_c98,L"Hnd",(LPDWORD)0x0,&local_c8c,(LPBYTE)&local_c90,&local_c94)
    ;
    if ((LVar1 != 0) || (local_c8c != 4)) {
      local_c90 = 0;
    }
    local_c94 = 4;
    LVar1 = RegQueryValueExW(local_c98,L"ReflectorHandle",(LPDWORD)0x0,&local_c8c,(LPBYTE)local_c88,
                             &local_c94);
    iVar2 = local_c90;
    if ((LVar1 == 0) && (local_c8c == 4)) {
      param_1[4] = local_c88[0];
    }
    if (local_c90 != 0) {
      memset(local_c80,0,0x630);
      local_c80[0] = 0x630;
      iVar2 = GetDeviceInformationByDeviceHandle(iVar2,local_c80);
      if (iVar2 != 0) {
        *param_1 = local_c78;
        sVar3 = wcslen(awStack_858);
        uVar5 = sVar3 + 1;
        param_1[3] = uVar5;
        if (uVar5 < 0x80000000) {
          uVar6 = uVar5 * 2;
        }
        _Dest = operator_new(uVar6);
        param_1[2] = (int)_Dest;
        if (_Dest != (wchar_t *)0x0) {
          wcscpy(_Dest,awStack_858);
        }
      }
    }
  }
  local_650[0] = 0x630;
  if ((*param_1 != 0) &&
     (iVar2 = GetDeviceInformationByDeviceHandle(*param_1,local_650), iVar2 != 0)) {
    pvVar4 = CreateFileW(aWStack_228,0xc0000000,3,(LPSECURITY_ATTRIBUTES)0x0,3,0,(HANDLE)0x0);
    param_1[1] = (int)pvVar4;
  }
  if (local_c98 != (HKEY)0x0) {
    RegCloseKey(local_c98);
  }
  FUN_c0426ba8(local_20);
  return param_1;
}



/* c04256fc FUN_c04256fc */

/* Boundary evidence: original MIPS .pdata c04256fc..c042575f. Semantic name remains unreviewed. */

void FUN_c04256fc(int param_1)

{
  if (*(HANDLE *)(param_1 + 4) != (HANDLE)0xffffffff) {
    CloseHandle(*(HANDLE *)(param_1 + 4));
    *(undefined4 *)(param_1 + 4) = 0xffffffff;
  }
  if (*(void **)(param_1 + 8) != (void *)0x0) {
    operator_delete(*(void **)(param_1 + 8));
  }
  return;
}



/* c0425760 FUN_c0425760 */

/* Boundary evidence: original MIPS .pdata c0425760..c0425803. Semantic name remains unreviewed. */

BOOL FUN_c0425760(int param_1,undefined4 param_2,undefined4 param_3)

{
  BOOL BVar1;
  DWORD local_18 [2];
  undefined4 local_10;
  undefined4 local_c;
  
  BVar1 = 0;
  if ((*(HANDLE *)(param_1 + 4) == (HANDLE)0xffffffff) || (*(LPVOID *)(param_1 + 8) == (LPVOID)0x0))
  {
    SetLastError(6);
  }
  else {
    local_18[0] = 0;
    local_10 = param_2;
    local_c = param_3;
    BVar1 = DeviceIoControl(*(HANDLE *)(param_1 + 4),0x2a0010,*(LPVOID *)(param_1 + 8),
                            *(int *)(param_1 + 0xc) << 1,&local_10,8,local_18,(LPOVERLAPPED)0x0);
  }
  return BVar1;
}



/* c0425804 FUN_c0425804 */

/* Boundary evidence: original MIPS .pdata c0425804..c04258c7. Semantic name remains unreviewed. */

BOOL FUN_c0425804(int param_1,undefined4 *param_2,undefined4 param_3)

{
  BOOL BVar1;
  DWORD local_20 [2];
  undefined4 local_18;
  undefined4 local_14;
  
  BVar1 = 0;
  if (((*(HANDLE *)(param_1 + 4) == (HANDLE)0xffffffff) || (*(LPVOID *)(param_1 + 8) == (LPVOID)0x0)
      ) || (param_2 == (undefined4 *)0x0)) {
    SetLastError(6);
  }
  else {
    local_20[0] = 0;
    local_14 = param_3;
    BVar1 = DeviceIoControl(*(HANDLE *)(param_1 + 4),0x2a000c,*(LPVOID *)(param_1 + 8),
                            *(int *)(param_1 + 0xc) << 1,&local_18,8,local_20,(LPOVERLAPPED)0x0);
    if (BVar1 != 0) {
      *param_2 = local_18;
    }
  }
  return BVar1;
}



/* c04258c8 FUN_c04258c8 */

/* Boundary evidence: original MIPS .pdata c04258c8..c0425a1f. Semantic name remains unreviewed. */

undefined4
FUN_c04258c8(int param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,
            int param_6,undefined4 *param_7,undefined4 *param_8)

{
  BOOL BVar1;
  undefined4 uVar2;
  DWORD local_48 [2];
  int local_40;
  undefined4 local_3c;
  undefined4 local_38;
  int local_34;
  undefined4 local_30;
  undefined4 local_28;
  undefined4 local_24;
  
  if ((((*(HANDLE *)(param_1 + 4) == (HANDLE)0xffffffff) ||
       (*(LPVOID *)(param_1 + 8) == (LPVOID)0x0)) || (param_8 == (undefined4 *)0x0)) ||
     (param_7 == (undefined4 *)0x0)) {
    uVar2 = HalTranslateBusAddress(param_2,param_3,param_5,param_6,param_7,param_8);
  }
  else {
    local_30 = *param_7;
    local_28 = *param_8;
    local_24 = param_8[1];
    local_38 = param_5;
    local_34 = param_6;
    local_48[0] = 0;
    local_40 = param_2;
    local_3c = param_3;
    BVar1 = DeviceIoControl(*(HANDLE *)(param_1 + 4),0x2a0004,*(LPVOID *)(param_1 + 8),
                            *(int *)(param_1 + 0xc) << 1,&local_40,0x20,local_48,(LPOVERLAPPED)0x0);
    if (BVar1 == 0) {
      uVar2 = HalTranslateBusAddress(param_2,param_3,param_5,param_6,param_7,param_8);
    }
    else {
      *param_8 = local_28;
      param_8[1] = local_24;
      uVar2 = 1;
      *param_7 = local_30;
    }
  }
  return uVar2;
}



/* c0425a20 FUN_c0425a20 */

/* Boundary evidence: original MIPS .pdata c0425a20..c0425b4b. Semantic name remains unreviewed. */

bool FUN_c0425a20(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,undefined4 *param_7)

{
  bool bVar1;
  BOOL BVar2;
  DWORD local_38 [2];
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  
  if (((*(HANDLE *)(param_1 + 4) == (HANDLE)0xffffffff) || (*(LPVOID *)(param_1 + 8) == (LPVOID)0x0)
      ) || (param_7 == (undefined4 *)0x0)) {
    bVar1 = HalTranslateSystemAddress(param_2,param_3,param_5,param_6,param_7);
  }
  else {
    local_20 = *param_7;
    local_1c = param_7[1];
    local_28 = param_5;
    local_24 = param_6;
    local_38[0] = 0;
    local_30 = param_2;
    local_2c = param_3;
    BVar2 = DeviceIoControl(*(HANDLE *)(param_1 + 4),0x2a0008,*(LPVOID *)(param_1 + 8),
                            *(int *)(param_1 + 0xc) << 1,&local_30,0x18,local_38,(LPOVERLAPPED)0x0);
    if (BVar2 == 0) {
      bVar1 = HalTranslateSystemAddress(param_2,param_3,param_5,param_6,param_7);
    }
    else {
      bVar1 = true;
      *param_7 = local_20;
      param_7[1] = local_1c;
    }
  }
  return bVar1;
}



/* c0425b4c FUN_c0425b4c */

/* Boundary evidence: original MIPS .pdata c0425b4c..c0425cb7. Semantic name remains unreviewed. */

int FUN_c0425b4c(int param_1,int param_2,undefined4 param_3,undefined4 param_4,int param_5,
                uint param_6,undefined4 param_7)

{
  int *lpOutBuffer;
  BOOL BVar1;
  DWORD dwErrCode;
  int iVar2;
  DWORD local_20 [2];
  
  if (((*(int *)(param_1 + 4) == -1) || (*(int *)(param_1 + 8) == 0)) || (0xffffffee < param_6)) {
    if (param_2 == 0) {
      iVar2 = HalGetBusDataByOffset();
      return iVar2;
    }
    dwErrCode = 6;
  }
  else {
    lpOutBuffer = malloc(param_6 + 0x10);
    if (lpOutBuffer != (int *)0x0) {
      *lpOutBuffer = param_2;
      lpOutBuffer[1] = param_5;
      lpOutBuffer[2] = param_6;
      CeSafeCopyMemory(lpOutBuffer + 3,param_7,param_6);
      local_20[0] = 0;
      BVar1 = DeviceIoControl(*(HANDLE *)(param_1 + 4),0x2a0018,*(LPVOID *)(param_1 + 8),
                              *(int *)(param_1 + 0xc) << 1,lpOutBuffer,param_6 + 0x10,local_20,
                              (LPOVERLAPPED)0x0);
      if (BVar1 == 0) {
        iVar2 = 0;
      }
      else {
        iVar2 = lpOutBuffer[2];
      }
      free(lpOutBuffer);
      return iVar2;
    }
    dwErrCode = 0xe;
  }
  SetLastError(dwErrCode);
  return 0;
}



/* c0425cb8 FUN_c0425cb8 */

/* Boundary evidence: original MIPS .pdata c0425cb8..c0425e37. Semantic name remains unreviewed. */

uint FUN_c0425cb8(int param_1,int param_2,undefined4 param_3,undefined4 param_4,int param_5,
                 uint param_6,undefined4 param_7)

{
  int *lpOutBuffer;
  BOOL BVar1;
  DWORD dwErrCode;
  uint uVar2;
  DWORD local_20 [2];
  
  if (((*(int *)(param_1 + 4) == -1) || (*(int *)(param_1 + 8) == 0)) || (0xffffffee < param_6)) {
    if (param_2 == 0) {
      uVar2 = HalGetBusDataByOffset();
      return uVar2;
    }
    dwErrCode = 6;
  }
  else {
    lpOutBuffer = malloc(param_6 + 0x10);
    if (lpOutBuffer != (int *)0x0) {
      lpOutBuffer[1] = param_5;
      *lpOutBuffer = param_2;
      lpOutBuffer[2] = param_6;
      local_20[0] = 0;
      BVar1 = DeviceIoControl(*(HANDLE *)(param_1 + 4),0x2a0014,*(LPVOID *)(param_1 + 8),
                              *(int *)(param_1 + 0xc) << 1,lpOutBuffer,param_6 + 0x10,local_20,
                              (LPOVERLAPPED)0x0);
      if (BVar1 == 0) {
        uVar2 = 0;
      }
      else {
        uVar2 = lpOutBuffer[2];
        if (uVar2 < param_6) {
          param_6 = uVar2;
        }
        CeSafeCopyMemory(param_7,lpOutBuffer + 3,param_6);
      }
      free(lpOutBuffer);
      return uVar2;
    }
    dwErrCode = 0xe;
  }
  SetLastError(dwErrCode);
  return 0;
}



/* c0425e38 FUN_c0425e38 */

/* Boundary evidence: original MIPS .pdata c0425e38..c0425ed7. Semantic name remains unreviewed. */

undefined4 FUN_c0425e38(int *param_1,uint *param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 local_640 [396];
  uint local_10;
  
  local_10 = DAT_c0428134;
  local_640[0] = 0x630;
  if ((*param_1 == 0) ||
     (iVar1 = GetDeviceInformationByDeviceHandle(*param_1,local_640), iVar1 == 0)) {
    SetLastError(6);
    FUN_c0426ba8(local_10);
    uVar2 = 0;
  }
  else {
    if ((param_2 != (uint *)0x0) && (0x62f < *param_2)) {
      memcpy(param_2,local_640,0x630);
    }
    FUN_c0426ba8(local_10);
    uVar2 = 1;
  }
  return uVar2;
}



/* c0425ed8 FUN_c0425ed8 */

/* Boundary evidence: original MIPS .pdata c0425ed8..c0425f63. Semantic name remains unreviewed. */

BOOL FUN_c0425ed8(int param_1,LPVOID param_2)

{
  BOOL BVar1;
  DWORD local_10 [2];
  
  if ((*(HANDLE *)(param_1 + 4) == (HANDLE)0xffffffff) || (*(LPVOID *)(param_1 + 8) == (LPVOID)0x0))
  {
    SetLastError(6);
    BVar1 = 0;
  }
  else {
    local_10[0] = 0;
    BVar1 = DeviceIoControl(*(HANDLE *)(param_1 + 4),0x2a0080,*(LPVOID *)(param_1 + 8),
                            *(int *)(param_1 + 0xc) << 1,param_2,4,local_10,(LPOVERLAPPED)0x0);
  }
  return BVar1;
}



/* c0425f64 FUN_c0425f64 */

/* Boundary evidence: original MIPS .pdata c0425f64..c0425fef. Semantic name remains unreviewed. */

BOOL FUN_c0425f64(int param_1,LPVOID param_2,int param_3)

{
  BOOL BVar1;
  DWORD local_10 [2];
  
  if ((*(HANDLE *)(param_1 + 4) == (HANDLE)0xffffffff) || (*(LPVOID *)(param_1 + 8) == (LPVOID)0x0))
  {
    SetLastError(6);
    BVar1 = 0;
  }
  else {
    local_10[0] = 0;
    BVar1 = DeviceIoControl(*(HANDLE *)(param_1 + 4),0x2a0084,*(LPVOID *)(param_1 + 8),
                            *(int *)(param_1 + 0xc) << 1,param_2,param_3 << 1,local_10,
                            (LPOVERLAPPED)0x0);
  }
  return BVar1;
}



/* c0425ff0 FUN_c0425ff0 */

/* Boundary evidence: original MIPS .pdata c0425ff0..c042605f. Semantic name remains unreviewed. */

BOOL FUN_c0425ff0(int param_1,DWORD param_2,LPVOID param_3,DWORD param_4,LPVOID param_5,
                 DWORD param_6,LPDWORD param_7,LPOVERLAPPED param_8)

{
  BOOL BVar1;
  
  if (*(HANDLE *)(param_1 + 4) == (HANDLE)0xffffffff) {
    SetLastError(6);
    BVar1 = 0;
  }
  else {
    BVar1 = DeviceIoControl(*(HANDLE *)(param_1 + 4),param_2,param_3,param_4,param_5,param_6,param_7
                            ,param_8);
  }
  return BVar1;
}



/* c0426060 FUN_c0426060 */

/* Boundary evidence: original MIPS .pdata c0426060..c04260cf. Semantic name remains unreviewed. */

BOOL FUN_c0426060(int param_1,DWORD param_2,LPVOID param_3,DWORD param_4)

{
  BOOL BVar1;
  
  if (*(HANDLE *)(param_1 + 4) == (HANDLE)0xffffffff) {
    SetLastError(6);
    BVar1 = 0;
  }
  else {
    BVar1 = DeviceIoControl(*(HANDLE *)(param_1 + 4),param_2,*(LPVOID *)(param_1 + 8),
                            *(int *)(param_1 + 0xc) << 1,param_3,param_4,(LPDWORD)0x0,
                            (LPOVERLAPPED)0x0);
  }
  return BVar1;
}



/* c04260d0 FUN_c04260d0 */

/* Boundary evidence: original MIPS .pdata c04260d0..c04262eb. Semantic name remains unreviewed. */

undefined4
FUN_c04260d0(undefined4 *param_1,undefined *param_2,undefined4 param_3,undefined1 param_4,
            undefined4 param_5)

{
  HANDLE pvVar1;
  undefined4 uVar2;
  DWORD dwErrCode;
  HANDLE hObject;
  undefined4 *puVar3;
  
  if (param_2 == (undefined *)0x0) {
    dwErrCode = 0x57;
  }
  else {
    InitializeCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xb));
    pvVar1 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
    param_1[9] = pvVar1;
    pvVar1 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,1,1,(LPCWSTR)0x0);
    param_1[10] = pvVar1;
    hObject = (HANDLE)param_1[9];
    if (hObject != (HANDLE)0x0) {
      if (pvVar1 != (HANDLE)0x0) {
        puVar3 = param_1;
        do {
          *puVar3 = 0;
          puVar3 = puVar3 + 1;
        } while (puVar3 != param_1 + 5);
        param_1[0x11] = param_3;
        uVar2 = (*(code *)param_2)(param_3,0xffffffff);
        param_1[5] = uVar2;
        param_1[6] = 0xffffffff;
        *(undefined1 *)(param_1 + 7) = 0;
        *(undefined1 *)((int)param_1 + 0x1d) = param_4;
        param_1[8] = param_5;
        param_1[0x10] = param_2;
        return 1;
      }
      if (hObject != (HANDLE)0x0) {
        CloseHandle(hObject);
      }
    }
    if ((HANDLE)param_1[10] != (HANDLE)0x0) {
      CloseHandle((HANDLE)param_1[10]);
    }
    DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xb));
    dwErrCode = 0xe;
  }
  SetLastError(dwErrCode);
  return 0;
}



/* c04262ec FUN_c04262ec */

/* Boundary evidence: original MIPS .pdata c04262ec..c04262f7. Semantic name remains unreviewed. */

undefined4 FUN_c04262ec(void)

{
  return 1;
}



/* c04262f8 FUN_c04262f8 */

/* Boundary evidence: original MIPS .pdata c04262f8..c0426343. Semantic name remains unreviewed. */

void FUN_c04262f8(int param_1)

{
  CloseHandle(*(HANDLE *)(param_1 + 0x24));
  CloseHandle(*(HANDLE *)(param_1 + 0x28));
  DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x2c));
  return;
}



/* c0426344 FUN_c0426344 */

/* Boundary evidence: original MIPS .pdata c0426344..c042644b. Semantic name remains unreviewed. */

undefined4 FUN_c0426344(int param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  LPCRITICAL_SECTION lpCriticalSection;
  
  lpCriticalSection = (LPCRITICAL_SECTION)(param_1 + 0x2c);
  EnterCriticalSection(lpCriticalSection);
  if ((*(int *)(param_1 + 0x18) != -1) && (*(char *)(param_1 + 0x1c) != '\0')) {
    LeaveCriticalSection(lpCriticalSection);
    WaitForSingleObject(*(HANDLE *)(param_1 + 0x28),0xffffffff);
    EnterCriticalSection(lpCriticalSection);
  }
  uVar3 = 1;
  if (((*(char *)(param_1 + 0x1d) == '\0') || (*(int *)(param_1 + 0x18) == -1)) ||
     (*(int *)(param_1 + 0x18) <= param_2)) {
    if (param_2 < *(int *)(param_1 + 0x14)) {
      iVar1 = (**(code **)(param_1 + 0x40))(*(undefined4 *)(param_1 + 0x44),param_2);
      *(int *)(param_1 + 0x14) = iVar1;
      if (param_2 < iVar1) goto LAB_c0426404;
    }
    piVar2 = (int *)(param_2 * 4 + param_1);
    *piVar2 = *piVar2 + 1;
  }
  else {
LAB_c0426404:
    uVar3 = 0;
  }
  LeaveCriticalSection(lpCriticalSection);
  return uVar3;
}



/* c042644c FUN_c042644c */

/* Boundary evidence: original MIPS .pdata c042644c..c0426527. Semantic name remains unreviewed. */

void FUN_c042644c(int *param_1,int param_2)

{
  bool bVar1;
  int *piVar2;
  uint uVar3;
  
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xb));
  param_1[param_2] = param_1[param_2] + -1;
  if ((param_1[6] != -1) && ((char)param_1[7] == '\0')) {
    bVar1 = true;
    uVar3 = 0;
    piVar2 = param_1;
    if (param_1[6] != 0) {
      do {
        if (*piVar2 != 0) {
          bVar1 = false;
          break;
        }
        uVar3 = uVar3 + 1;
        piVar2 = piVar2 + 1;
      } while (uVar3 < (uint)param_1[6]);
    }
    if (bVar1) {
      EventModify(param_1[10],2);
      *(undefined1 *)(param_1 + 7) = 1;
      EventModify(param_1[9],3);
    }
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xb));
  return;
}



/* c0426528 FUN_c0426528 */

/* Boundary evidence: original MIPS .pdata c0426528..c042667f. Semantic name remains unreviewed. */

bool FUN_c0426528(int *param_1,uint param_2,undefined *param_3)

{
  bool bVar1;
  int iVar2;
  int *piVar3;
  uint uVar4;
  LPCRITICAL_SECTION lpCriticalSection;
  
  lpCriticalSection = (LPCRITICAL_SECTION)(param_1 + 0xb);
  EnterCriticalSection(lpCriticalSection);
  bVar1 = false;
  uVar4 = 0;
  piVar3 = param_1;
  if (param_2 != 0) {
    do {
      if (*piVar3 != 0) {
        bVar1 = true;
        break;
      }
      uVar4 = uVar4 + 1;
      piVar3 = piVar3 + 1;
    } while (uVar4 < param_2);
  }
  if (bVar1) {
    param_1[6] = param_2;
    LeaveCriticalSection(lpCriticalSection);
    WaitForSingleObject((HANDLE)param_1[9],param_1[8]);
    EnterCriticalSection(lpCriticalSection);
    *(undefined1 *)(param_1 + 7) = 0;
    EventModify(param_1[10],3);
  }
  bVar1 = false;
  if ((param_3 != (undefined *)0x0) && (uVar4 = 0, piVar3 = param_1, param_2 != 0)) {
    do {
      if (*piVar3 != 0) {
        bVar1 = true;
        break;
      }
      uVar4 = uVar4 + 1;
      piVar3 = piVar3 + 1;
    } while (uVar4 < param_2);
  }
  if (bVar1) {
    (*(code *)param_3)(param_1[0x11],param_2);
  }
  param_1[6] = -1;
  iVar2 = (*(code *)param_1[0x10])(param_1[0x11],param_2);
  param_1[5] = iVar2;
  LeaveCriticalSection(lpCriticalSection);
  return param_1[5] == param_2;
}



/* c0426680 DDKPwr_Initialize */

/* Boundary evidence: original MIPS .pdata c0426680..c042672f. Semantic name remains unreviewed. */

undefined4 * DDKPwr_Initialize(undefined *param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  undefined4 *puVar1;
  int iVar2;
  
                    /* 0x6680  51  DDKPwr_Initialize */
  puVar1 = operator_new(0x48);
  if (puVar1 == (undefined4 *)0x0) {
    SetLastError(0xe);
  }
  else {
    iVar2 = FUN_c04260d0(puVar1,param_1,param_2,param_3 != 0,param_4);
    if (iVar2 != 0) {
      return puVar1;
    }
    operator_delete(puVar1);
  }
  return (undefined4 *)0xffffffff;
}



/* c0426730 DDKPwr_Deinitialize */

/* Boundary evidence: original MIPS .pdata c0426730..c0426793. Semantic name remains unreviewed. */

void DDKPwr_Deinitialize(void *param_1)

{
  DWORD dwErrCode;
  
                    /* 0x6730  52  DDKPwr_Deinitialize */
  if ((param_1 == (void *)0x0) || (param_1 == (void *)0xffffffff)) {
    dwErrCode = 0x57;
  }
  else {
    FUN_c04262f8((int)param_1);
    operator_delete(param_1);
    dwErrCode = 0;
  }
  SetLastError(dwErrCode);
  return;
}



/* c0426794 DDKPwr_RequestLevel */

/* Boundary evidence: original MIPS .pdata c0426794..c0426807. Semantic name remains unreviewed. */

int DDKPwr_RequestLevel(int param_1,int param_2)

{
  int iVar1;
  DWORD dwErrCode;
  
                    /* 0x6794  53  DDKPwr_RequestLevel */
  if ((param_1 == 0) || (param_1 == -1)) {
    dwErrCode = 0x57;
  }
  else {
    iVar1 = FUN_c0426344(param_1,param_2);
    if (iVar1 != 0) {
      return param_2 + 1000;
    }
    dwErrCode = 0xa7;
  }
  SetLastError(dwErrCode);
  return -1;
}



/* c0426808 DDKPwr_ReleaseLevel */

/* Boundary evidence: original MIPS .pdata c0426808..c0426867. Semantic name remains unreviewed. */

void DDKPwr_ReleaseLevel(int *param_1,int param_2)

{
  DWORD dwErrCode;
  
                    /* 0x6808  54  DDKPwr_ReleaseLevel */
  if ((((param_1 == (int *)0x0) || (param_1 == (int *)0xffffffff)) || (param_2 == 0)) ||
     (param_2 == -1)) {
    dwErrCode = 0x57;
  }
  else {
    FUN_c042644c(param_1,param_2 + -1000);
    dwErrCode = 0;
  }
  SetLastError(dwErrCode);
  return;
}



/* c0426868 DDKPwr_GetDeviceLevel */

/* Boundary evidence: original MIPS .pdata c0426868..c04268b3. Semantic name remains unreviewed. */

undefined4 DDKPwr_GetDeviceLevel(int param_1)

{
  undefined4 uVar1;
  
                    /* 0x6868  55  DDKPwr_GetDeviceLevel */
  uVar1 = 0xffffffff;
  if ((param_1 == 0) || (param_1 == -1)) {
    SetLastError(0x57);
  }
  else {
    uVar1 = *(undefined4 *)(param_1 + 0x14);
  }
  return uVar1;
}



/* c04268b4 DDKPwr_SetDeviceLevel */

/* Boundary evidence: original MIPS .pdata c04268b4..c0426917. Semantic name remains unreviewed. */

undefined4 DDKPwr_SetDeviceLevel(int *param_1,uint param_2,undefined *param_3)

{
  bool bVar1;
  undefined3 extraout_var;
  DWORD dwErrCode;
  
                    /* 0x68b4  56  DDKPwr_SetDeviceLevel */
  if ((param_1 == (int *)0x0) || (param_1 == (int *)0xffffffff)) {
    dwErrCode = 0x57;
  }
  else {
    bVar1 = FUN_c0426528(param_1,param_2,param_3);
    if (CONCAT31(extraout_var,bVar1) != 0) {
      return 1;
    }
    dwErrCode = 0xa7;
  }
  SetLastError(dwErrCode);
  return 0;
}



/* c0426b28 FUN_c0426b28 */

/* Boundary evidence: original MIPS .pdata c0426b28..c0426b7b. Semantic name remains unreviewed. */

void FUN_c0426b28(int param_1,undefined4 param_2,uint *param_3)

{
  if ((*param_3 & 1) != 0) {
    param_1 = ((-param_3[2] & param_3[1] + param_1) - (param_3[1] + param_1)) + param_1;
  }
  FUN_c0426ba8(*(uint *)(param_1 + (*param_3 & 0xfffffffc)));
  return;
}



/* c0426b7c FUN_c0426b7c */

/* Boundary evidence: original MIPS .pdata c0426b7c..c0426ba7. Semantic name remains unreviewed. */

undefined4 FUN_c0426b7c(undefined4 param_1,int param_2,undefined4 param_3,int param_4)

{
  FUN_c0426b28(param_2,param_4,*(uint **)(*(int *)(param_4 + 4) + 0xc));
  return 1;
}



/* c0426ba8 FUN_c0426ba8 */

/* Boundary evidence: original MIPS .pdata c0426ba8..c0426bef. Semantic name remains unreviewed. */

void FUN_c0426ba8(uint param_1)

{
  if ((param_1 == DAT_c0428134) && (param_1 >> 0x10 == 0)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __report_gsfailure();
}


