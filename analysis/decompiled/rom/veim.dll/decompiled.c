/* Automatic Ghidra pseudocode. Not original source; not runtime-verified. */

/* c06d1260 DllMain */

/* Boundary evidence: original MIPS .pdata c06d1260..c06d129b. Semantic name remains unreviewed. */

undefined4 DllMain(HMODULE param_1,int param_2)

{
                    /* 0x1260  1  DllMain */
  if (param_2 == 1) {
    DAT_c06d5188 = param_1;
    DisableThreadLibraryCalls(param_1);
  }
  return 1;
}



/* c06d129c FUN_c06d129c */

/* Boundary evidence: original MIPS .pdata c06d129c..c06d1383. Semantic name remains unreviewed. */

int FUN_c06d129c(undefined4 param_1,int param_2,int param_3,int param_4,undefined *param_5)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  
  if (param_3 != 0) {
    uVar3 = 0;
    uVar4 = param_3 - 1;
    do {
      iVar2 = (uVar4 - uVar3 >> 1) + uVar3;
      iVar5 = iVar2 * param_4 + param_2;
      iVar1 = (*(code *)param_5)(param_1,iVar5);
      if (iVar1 == 0) {
        return iVar5;
      }
      if (iVar1 < 0) {
        if (iVar2 == 0) {
          return 0;
        }
        uVar4 = iVar2 - 1;
      }
      else {
        uVar3 = iVar2 + 1;
      }
    } while (uVar3 <= uVar4);
  }
  return 0;
}



/* c06d1384 FUN_c06d1384 */

/* Boundary evidence: original MIPS .pdata c06d1384..c06d13b3. Semantic name remains unreviewed. */

void FUN_c06d1384(int param_1)

{
  *(undefined4 *)(param_1 + 4) = 1;
  if (*(code **)(param_1 + 0xac) != (code *)0x0) {
    (**(code **)(param_1 + 0xac))(*(undefined4 *)(param_1 + 0xcc));
  }
  return;
}



/* c06d13b4 FUN_c06d13b4 */

/* Boundary evidence: original MIPS .pdata c06d13b4..c06d154b. Semantic name remains unreviewed. */

int FUN_c06d13b4(undefined4 param_1,uint *param_2,int *param_3,uint param_4,undefined4 param_5,
                undefined4 param_6)

{
  undefined4 *puVar1;
  uint uVar2;
  int local_20;
  int local_1c;
  
  local_1c = 0;
  puVar1 = (undefined4 *)NdisIMGetDeviceContext(param_5);
  if (puVar1 == (undefined4 *)0x0) {
    local_20 = -0x3ffefffa;
  }
  else {
    local_20 = -0x3ffeffe7;
    uVar2 = 0;
    if (param_4 != 0) {
      do {
        if (*param_3 == puVar1[0x32]) {
          *param_2 = uVar2;
          local_20 = 0;
          *puVar1 = param_5;
          NdisOpenConfiguration(&local_20,&local_1c,param_6);
          if (local_20 == 0) {
            NdisMSetAttributesEx(param_5,puVar1,0xfffffff,0x70,0);
            NdisMRegisterAdapterShutdownHandler(param_5,puVar1,FUN_c06d1384);
            local_20 = FUN_c06d3b80((int)puVar1);
            if ((local_20 == 0) && (local_20 = FUN_c06d3894((int)puVar1), local_20 == 0)) {
              local_20 = FUN_c06d3490((int)puVar1);
            }
          }
          break;
        }
        uVar2 = uVar2 + 1;
        param_3 = param_3 + 1;
      } while (uVar2 < param_4);
    }
  }
  if (local_1c != 0) {
    NdisCloseConfiguration();
  }
  if ((local_20 != 0) && (puVar1 != (undefined4 *)0x0)) {
    NdisFreeMemory(puVar1,0xd0,0);
  }
  return local_20;
}



/* c06d154c FUN_c06d154c */

/* Boundary evidence: original MIPS .pdata c06d154c..c06d159b. Semantic name remains unreviewed. */

void FUN_c06d154c(int param_1)

{
  FUN_c06d3538(param_1);
  FUN_c06d38d4(param_1);
  FUN_c06d3e40(param_1);
  NdisFreeMemory(param_1,0,0);
  return;
}



/* c06d15b4 FUN_c06d15b4 */

/* Boundary evidence: original MIPS .pdata c06d15b4..c06d18fb. Semantic name remains unreviewed. */

int FUN_c06d15b4(int param_1,uint param_2,void *param_3,uint param_4,uint *param_5,uint *param_6)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  uint _Size;
  undefined4 uVar4;
  char *_Src;
  uint local_30 [2];
  
  uVar4 = *(undefined4 *)(param_1 + 0xcc);
  _Size = 4;
  _Src = (char *)local_30;
  local_30[0] = param_2;
  iVar1 = FUN_c06d129c(local_30,*(int *)(param_1 + 0xb0),*(int *)(param_1 + 0xb4),0xc,&LAB_c06d15a4)
  ;
  iVar3 = -0x3ffeffe9;
  if (iVar1 != 0) {
    uVar2 = *(uint *)(iVar1 + 4);
    if (param_4 < uVar2) {
      iVar3 = -0x3ffeffec;
      *param_6 = uVar2;
    }
    else {
      *param_5 = uVar2;
      iVar3 = (**(code **)(iVar1 + 8))(uVar4,param_3,param_4,param_5,param_6);
    }
  }
  if (iVar3 != -0x3ffeffe9) {
    return iVar3;
  }
  iVar1 = 0;
  if (param_2 < 0x20102) {
    if (param_2 == 0x20101) {
      local_30[0] = *(uint *)(param_1 + 8);
    }
    else {
      switch(param_2) {
      case 0x10101:
        _Src = (char *)0xc06d50f8;
        _Size = 0x88;
        break;
      case 0x10102:
      case 0x10103:
      case 0x10104:
        local_30[0] = 0;
        _Src = (char *)local_30;
        break;
      case 0x10105:
      case 0x10106:
      case 0x10108:
      case 0x10109:
        local_30[0] = *(uint *)(param_1 + 0xc0);
        break;
      case 0x10107:
        local_30[0] = *(uint *)(param_1 + 0xc4) / 100;
        break;
      case 0x1010a:
      case 0x1010b:
      case 0x1010f:
        local_30[0] = *(uint *)(param_1 + 0xc0);
        break;
      case 0x1010c:
        local_30[0] = 0xffffffff;
        break;
      case 0x1010d:
        _Src = "MS Windows CE Virtual Ethernet Adapter";
        _Size = 0x27;
        break;
      case 0x1010e:
        local_30[0] = *(uint *)(param_1 + 0x10);
        break;
      case 0x10110:
        local_30[0] = CONCAT22(local_30[0]._2_2_,0x100);
        _Src = (char *)local_30;
        _Size = 2;
        break;
      case 0x10111:
        local_30[0] = *(int *)(param_1 + 0xc0) + 0xe;
        break;
      default:
        return -0x3ffeffe9;
      case 0x10113:
        local_30[0] = 0xf;
        break;
      case 0x10114:
        local_30[0] = *(uint *)(param_1 + 0x60);
        break;
      case 0x10115:
        local_30[0] = 1;
        break;
      case 0x10116:
        local_30[0] = 0x10000;
      }
    }
    goto LAB_c06d189c;
  }
  if (param_2 < 0x1010103) {
    if (param_2 != 0x1010102) {
      if (param_2 == 0x20102) {
        local_30[0] = *(uint *)(param_1 + 0xc);
        goto LAB_c06d189c;
      }
      if ((param_2 == 0x20103) || (param_2 - 0x20103 < 3)) goto LAB_c06d1890;
      if (param_2 - 0x20103 != 0xfefffe) {
        return -0x3ffeffe9;
      }
    }
    _Src = (char *)(param_1 + 0x18);
    _Size = 6;
  }
  else {
    if (param_2 == 0x1010103) {
      _Size = 0;
      goto LAB_c06d189c;
    }
    if (((param_2 != 0x1010104) && (param_2 != 0x1020101)) && (2 < param_2 + 0xfefdfeff)) {
      return -0x3ffeffe9;
    }
LAB_c06d1890:
    local_30[0] = 0;
  }
LAB_c06d189c:
  if (param_4 < _Size) {
    *param_6 = _Size;
    iVar1 = -0x3ffeffec;
  }
  else {
    memcpy(param_3,_Src,_Size);
    *param_5 = _Size;
  }
  return iVar1;
}



/* c06d18fc FUN_c06d18fc */

/* Boundary evidence: original MIPS .pdata c06d18fc..c06d1a9b. Semantic name remains unreviewed. */

int FUN_c06d18fc(int param_1,int param_2,uint *param_3,uint param_4,uint *param_5,uint *param_6)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  int local_30 [2];
  
  uVar3 = *(undefined4 *)(param_1 + 0xcc);
  local_30[0] = param_2;
  iVar1 = FUN_c06d129c(local_30,*(int *)(param_1 + 0xb8),*(int *)(param_1 + 0xbc),0xc,&LAB_c06d15a4)
  ;
  iVar4 = -0x3ffeffe9;
  if (iVar1 != 0) {
    uVar2 = *(uint *)(iVar1 + 4);
    if (param_4 < uVar2) {
      iVar4 = -0x3ffeffec;
      *param_6 = uVar2;
    }
    else {
      *param_5 = uVar2;
      iVar4 = (**(code **)(iVar1 + 8))(uVar3,param_3,param_4,param_5,param_6);
    }
  }
  if (iVar4 == -0x3ffeffe9) {
    iVar4 = 0;
    if (param_2 == 0x1010e) {
      uVar2 = 4;
      if (param_4 == 4) {
        if ((*param_3 & 0xf050) != 0) {
          return -0x3fffff45;
        }
        *(uint *)(param_1 + 0x10) = *param_3;
      }
    }
    else if (param_2 == 0x1010f) {
      uVar2 = 4;
      if (param_4 == 4) {
        *(uint *)(param_1 + 0x14) = *param_3;
      }
    }
    else {
      uVar2 = param_4;
      if (param_2 != 0x1010103) {
        return -0x3ffeffe9;
      }
    }
    *param_6 = uVar2;
    *param_5 = uVar2;
    if (param_4 != uVar2) {
      iVar4 = -0x3ffeffec;
      *param_5 = 0;
    }
  }
  return iVar4;
}



/* c06d1a9c FUN_c06d1a9c */

/* Boundary evidence: original MIPS .pdata c06d1a9c..c06d1b03. Semantic name remains unreviewed. */

void FUN_c06d1a9c(int *param_1,int *param_2,int param_3)

{
  for (; param_3 != 0; param_3 = param_3 + -1) {
    FUN_c06d3904(param_1,*param_2);
    param_2 = param_2 + 1;
    param_1[2] = param_1[2] + 1;
  }
  return;
}



/* c06d1b04 FUN_c06d1b04 */

/* Boundary evidence: original MIPS .pdata c06d1b04..c06d1b1f. Semantic name remains unreviewed. */

void FUN_c06d1b04(int param_1,int param_2)

{
  FUN_c06d3ae0(param_1,param_2);
  return;
}



/* c06d1b20 DriverEntry */

/* Boundary evidence: original MIPS .pdata c06d1b20..c06d1c0f. Semantic name remains unreviewed. */

int DriverEntry(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 local_58 [2];
  undefined1 local_50 [20];
  code *local_3c;
  code *local_34;
  code *local_2c;
  undefined1 *local_24;
  code *local_1c;
  code *local_14;
  code *local_10;
  
                    /* 0x1b20  2  DriverEntry */
  NdisInitializeWrapper(local_58,param_1,param_2,0);
  DAT_c06d518c = 0;
  memset(local_50,0,0x48);
  local_3c = FUN_c06d154c;
  local_24 = &LAB_c06d159c;
  local_34 = FUN_c06d13b4;
  local_2c = FUN_c06d15b4;
  local_10 = FUN_c06d1a9c;
  local_1c = FUN_c06d18fc;
  local_50[0] = 4;
  local_14 = FUN_c06d1b04;
  iVar1 = NdisIMRegisterLayeredMiniport(local_58[0],local_50,0x48,&DAT_c06d5190);
  if (iVar1 != 0) {
    NdisTerminateWrapper(local_58[0],0);
  }
  return iVar1;
}



/* c06d1c10 FUN_c06d1c10 */

/* Boundary evidence: original MIPS .pdata c06d1c10..c06d1caf. Semantic name remains unreviewed. */

undefined4 FUN_c06d1c10(undefined4 param_1,undefined4 param_2)

{
  HRESULT HVar1;
  LSTATUS LVar2;
  HKEY local_220 [2];
  wchar_t awStack_218 [260];
  uint local_10;
  
  local_10 = DAT_c06d5180;
  HVar1 = StringCchPrintfW(awStack_218,0x104,L"Comm\\%s\\%s",param_1,param_2);
  if ((-1 < HVar1) &&
     (LVar2 = RegCreateKeyExW((HKEY)0x80000002,awStack_218,0,(LPWSTR)0x0,0,0,
                              (LPSECURITY_ATTRIBUTES)0x0,local_220,(LPDWORD)0x0), LVar2 == 0)) {
    FUN_c06d41e0(local_10);
    return local_220[0];
  }
  FUN_c06d41e0(local_10);
  return 0;
}



/* c06d1cb0 VEMDeviceCreate */

/* Boundary evidence: original MIPS .pdata c06d1cb0..c06d1f13. Semantic name remains unreviewed. */

int VEMDeviceCreate(wchar_t *param_1,void *param_2,undefined4 param_3,undefined4 *param_4)

{
  short sVar1;
  int iVar2;
  size_t sVar3;
  HKEY pHVar4;
  uint uVar5;
  uint _Size;
  void *local_28 [2];
  
                    /* 0x1cb0  5  VEMDeviceCreate */
  local_28[0] = (void *)0x0;
  if (DAT_c06d5190 == 0) {
    iVar2 = 0x10003;
  }
  else {
    sVar3 = wcslen(param_1);
    uVar5 = (sVar3 + 1) * 2;
    _Size = uVar5 & 0xffff;
    iVar2 = NdisAllocateMemoryWithTag(local_28,_Size + 0xd0,0x4d687445);
    if (iVar2 == 0) {
      memset(local_28[0],0,0xd0);
      memcpy((void *)((int)local_28[0] + 0x7c),param_2,0x50);
      *(undefined4 *)((int)local_28[0] + 0xcc) = param_3;
      *(int *)((int)local_28[0] + 0x78) = (int)local_28[0] + 0xd0;
      sVar1 = (short)uVar5;
      *(short *)((int)local_28[0] + 0x74) = sVar1 + -2;
      *(short *)((int)local_28[0] + 0x76) = sVar1;
      memcpy(*(void **)((int)local_28[0] + 0x78),param_1,_Size);
      pHVar4 = (HKEY)FUN_c06d1c10(param_1,L"Parms");
      if (pHVar4 != (HKEY)0x0) {
        SetRegDWORDValue(pHVar4,L"BusType",0);
        SetRegDWORDValue(pHVar4,L"BusNumber",0);
        if ((*(uint *)((int)local_28[0] + 0x80) & 8) == 0) {
          RegDeleteValueW(pHVar4,L"UpperBind");
        }
        else {
          SetRegMultiSZValue(pHVar4,L"UpperBind",&DAT_c06d1108);
        }
        RegCloseKey(pHVar4);
      }
      pHVar4 = (HKEY)FUN_c06d1c10(param_1,L"Parms\\Tcpip");
      if (pHVar4 != (HKEY)0x0) {
        SetRegDWORDValue(pHVar4,L"DontAddDefaultGateway",
                         (*(uint *)((int)local_28[0] + 0x80) & 0x10) != 0);
        if ((*(uint *)((int)local_28[0] + 0x80) & 0x20) == 0) {
          RegDeleteValueW(pHVar4,L"DefaultGatewayMetric");
        }
        else {
          SetRegMultiSZValue(pHVar4,L"DefaultGatewayMetric",&DAT_c06d10a8);
        }
        RegCloseKey(pHVar4);
      }
      iVar2 = NdisIMInitializeDeviceInstanceEx(DAT_c06d5190,(int)local_28[0] + 0x74);
    }
  }
  *param_4 = local_28[0];
  return iVar2;
}



/* c06d1f14 VEMDeviceDestroy */

/* Boundary evidence: original MIPS .pdata c06d1f14..c06d1f73. Semantic name remains unreviewed. */

undefined4 VEMDeviceDestroy(int *param_1)

{
  undefined4 uVar1;
  
                    /* 0x1f14  6  VEMDeviceDestroy */
  uVar1 = 0;
  if (param_1 != (int *)0x0) {
    if (*param_1 == 0) {
      uVar1 = NdisIMCancelInitializeDeviceInstance(DAT_c06d5190,param_1 + 0x1d);
    }
    else {
      uVar1 = NdisIMDeInitializeDeviceInstance(*param_1);
    }
  }
  return uVar1;
}



/* c06d1f74 VEMReceivePacket */

/* Boundary evidence: original MIPS .pdata c06d1f74..c06d1faf. Semantic name remains unreviewed. */

void VEMReceivePacket(int *param_1,int param_2,int param_3)

{
                    /* 0x1f74  13  VEMReceivePacket */
  *(undefined4 *)(param_2 + 0x24) = 2;
  FUN_c06d39f8(param_1,param_2,param_3);
  param_1[3] = param_1[3] + 1;
  return;
}



/* c06d1fb0 VEMGetNDISPacket */

/* Boundary evidence: original MIPS .pdata c06d1fb0..c06d1fe3. Semantic name remains unreviewed. */

undefined4 VEMGetNDISPacket(int param_1)

{
  undefined4 local_10;
  undefined1 auStack_c [4];
  
                    /* 0x1fb0  10  VEMGetNDISPacket */
  local_10 = 0;
  NdisAllocatePacket(auStack_c,&local_10,*(undefined4 *)(param_1 + 0x24));
  return local_10;
}



/* c06d1fe4 VEMFreeNDISPacket */

/* Boundary evidence: original MIPS .pdata c06d1fe4..c06d2007. Semantic name remains unreviewed. */

void VEMFreeNDISPacket(undefined4 param_1,undefined4 param_2)

{
                    /* 0x1fe4  8  VEMFreeNDISPacket */
  NdisFreePacket(param_2);
  return;
}



/* c06d2008 VEMGetNDISBuffer */

/* Boundary evidence: original MIPS .pdata c06d2008..c06d2023. Semantic name remains unreviewed. */

void VEMGetNDISBuffer(int param_1,undefined4 param_2,undefined4 param_3)

{
                    /* 0x2008  9  VEMGetNDISBuffer */
  FUN_c06d2ac4(*(int *)(param_1 + 0x6c),param_2,param_3);
  return;
}



/* c06d2024 VEMFreeNDISBuffer */

/* Boundary evidence: original MIPS .pdata c06d2024..c06d203f. Semantic name remains unreviewed. */

void VEMFreeNDISBuffer(int param_1,undefined4 *param_2)

{
                    /* 0x2024  7  VEMFreeNDISBuffer */
  FUN_c06d2ba4(*(int *)(param_1 + 0x6c),param_2);
  return;
}



/* c06d2040 VEMSendComplete */

/* Boundary evidence: original MIPS .pdata c06d2040..c06d2067. Semantic name remains unreviewed. */

void VEMSendComplete(int *param_1)

{
                    /* 0x2040  14  VEMSendComplete */
  (**(code **)(*param_1 + 0x10c))(*param_1);
  return;
}



/* c06d2068 VEMIndicateStatus */

/* Boundary evidence: original MIPS .pdata c06d2068..c06d208f. Semantic name remains unreviewed. */

void VEMIndicateStatus(int *param_1)

{
                    /* 0x2068  11  VEMIndicateStatus */
  (**(code **)(*param_1 + 0x220))(*param_1);
  return;
}



/* c06d2090 FUN_c06d2090 */

/* Boundary evidence: original MIPS .pdata c06d2090..c06d21c7. Semantic name remains unreviewed. */

LSTATUS FUN_c06d2090(int param_1,LPCWSTR param_2,DWORD param_3,wchar_t *param_4)

{
  wchar_t wVar1;
  HKEY hKey;
  size_t sVar2;
  DWORD cbData;
  int iVar3;
  wchar_t wVar4;
  wchar_t *pwVar5;
  LSTATUS LVar6;
  
  LVar6 = 0;
  hKey = (HKEY)FUN_c06d1c10(*(undefined4 *)(param_1 + 0x78),L"Parms\\Tcpip");
  if (hKey != (HKEY)0x0) {
    if (param_4 == (wchar_t *)0x0) {
      LVar6 = RegDeleteValueW(hKey,param_2);
    }
    else {
      if (param_3 == 1) {
        sVar2 = wcslen(param_4);
        cbData = (sVar2 + 1) * 2;
      }
      else {
        cbData = 4;
        if (param_3 != 4) {
          if (param_3 == 7) {
            iVar3 = 0;
            pwVar5 = param_4;
            wVar1 = L'\0';
            do {
              do {
                wVar4 = wVar1;
                wVar1 = *pwVar5;
                pwVar5 = pwVar5 + 1;
                iVar3 = iVar3 + 1;
              } while (wVar1 != L'\0');
            } while (wVar4 != L'\0');
            cbData = iVar3 * 2;
          }
          else {
            cbData = 0;
          }
        }
      }
      LVar6 = RegSetValueExW(hKey,param_2,0,param_3,(BYTE *)param_4,cbData);
    }
    RegCloseKey(hKey);
  }
  return LVar6;
}



/* c06d21c8 FUN_c06d21c8 */

/* Boundary evidence: original MIPS .pdata c06d21c8..c06d22eb. Semantic name remains unreviewed. */

LSTATUS FUN_c06d21c8(int param_1,LPCWSTR param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  LSTATUS LVar2;
  wchar_t *pwVar3;
  uint uVar4;
  int *piVar5;
  int *piVar6;
  int local_res8;
  undefined4 local_resc;
  wchar_t awStack_230 [260];
  uint local_28;
  
  local_28 = DAT_c06d5180;
  pwVar3 = awStack_230;
  piVar5 = &local_res8;
  local_res8 = param_3;
  local_resc = param_4;
  while( true ) {
    piVar6 = piVar5 + 1;
    if ((uint *)*piVar5 == (uint *)0x0) break;
    uVar4 = *(uint *)*piVar5;
    piVar5 = piVar6;
    if (uVar4 != 0) {
      iVar1 = swprintf(pwVar3,0xc06d113c,(wchar_t *)(uVar4 >> 0x18),uVar4 >> 0x10 & 0xff,
                       uVar4 >> 8 & 0xff,uVar4 & 0xff);
      pwVar3 = pwVar3 + iVar1 + 1;
    }
  }
  if (awStack_230 < pwVar3) {
    *pwVar3 = L'\0';
    pwVar3 = awStack_230;
  }
  else {
    pwVar3 = (wchar_t *)0x0;
  }
  LVar2 = FUN_c06d2090(param_1,param_2,7,pwVar3);
  FUN_c06d41e0(local_28);
  return LVar2;
}



/* c06d22ec VEMSetIPConfig */

/* Boundary evidence: original MIPS .pdata c06d22ec..c06d2493. Semantic name remains unreviewed. */

void VEMSetIPConfig(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                   uint param_5,uint param_6)

{
  int iVar1;
  uint uVar2;
  uint *puVar3;
  undefined4 local_res4;
  undefined4 local_res8;
  undefined4 local_resc;
  wchar_t local_18 [2];
  uint local_14;
  
                    /* 0x22ec  16  VEMSetIPConfig */
  puVar3 = *(uint **)(param_1 + 0x70);
  local_18[0] = L'\0';
  local_18[1] = L'\0';
  *(undefined4 *)(param_1 + 0x90) = param_2;
  *(undefined4 *)(param_1 + 0x94) = param_3;
  *(undefined4 *)(param_1 + 0x98) = param_4;
  *(uint *)(param_1 + 0x9c) = param_5;
  *(uint *)(param_1 + 0xa0) = param_6;
  if ((*(uint *)(param_1 + 0x80) & 4) != 0) {
    local_14 = (uint)((*(uint *)(param_1 + 0x80) & 0x10) != 0);
    local_res4 = param_2;
    local_res8 = param_3;
    local_resc = param_4;
    FUN_c06d2090(param_1,L"EnableDHCP",4,local_18);
    FUN_c06d2090(param_1,L"UseZeroBroadcast",4,local_18);
    FUN_c06d2090(param_1,L"DontAddDefaultGateway",4,(wchar_t *)&local_14);
    FUN_c06d21c8(param_1,L"IpAddress",(int)&local_res4,0);
    FUN_c06d21c8(param_1,L"Subnetmask",(int)&local_res8,0);
    FUN_c06d21c8(param_1,L"DefaultGateway",(int)&local_resc,0);
    FUN_c06d21c8(param_1,L"DNS",(int)&param_5,&param_6);
  }
  if (puVar3 != (uint *)0x0) {
    iVar1 = *(int *)(param_1 + 0x90);
    uVar2 = iVar1 + 1;
    *puVar3 = uVar2;
    if ((uVar2 & 0xff) == 0xff) {
      *puVar3 = iVar1 - 1;
    }
    puVar3[1] = *(uint *)(param_1 + 0x90);
    puVar3[2] = 1;
    puVar3[3] = *(uint *)(param_1 + 0x98);
    puVar3[4] = *(uint *)(param_1 + 0x94);
    puVar3[6] = param_5;
    puVar3[7] = param_6;
    puVar3[10] = 0;
    if ((param_5 != 0) && (puVar3[10] = 1, param_6 != 0)) {
      puVar3[10] = 2;
    }
  }
  return;
}



/* c06d2494 VEMSetWINSConfig */

/* Boundary evidence: original MIPS .pdata c06d2494..c06d2523. Semantic name remains unreviewed. */

void VEMSetWINSConfig(int param_1,int param_2,int param_3)

{
  int iVar1;
  int local_res4;
  int local_res8 [2];
  
                    /* 0x2494  19  VEMSetWINSConfig */
  iVar1 = *(int *)(param_1 + 0x70);
  local_res4 = param_2;
  local_res8[0] = param_3;
  if ((*(uint *)(param_1 + 0x80) & 4) != 0) {
    FUN_c06d21c8(param_1,L"WINS",(int)&local_res4,local_res8);
  }
  if (iVar1 != 0) {
    *(int *)(iVar1 + 0x3c) = local_res4;
    *(int *)(iVar1 + 0x40) = local_res8[0];
    *(undefined4 *)(iVar1 + 0x4c) = 0;
    if ((local_res4 != 0) && (*(undefined4 *)(iVar1 + 0x4c) = 1, local_res8[0] != 0)) {
      *(undefined4 *)(iVar1 + 0x4c) = 2;
    }
  }
  return;
}



/* c06d2524 VEMSetDomain */

/* Boundary evidence: original MIPS .pdata c06d2524..c06d260b. Semantic name remains unreviewed. */

void VEMSetDomain(int param_1,char *param_2)

{
  size_t sVar1;
  char *_Dest;
  wchar_t *pwVar2;
  int iVar3;
  wchar_t local_220 [260];
  uint local_18;
  
                    /* 0x2524  15  VEMSetDomain */
  local_18 = DAT_c06d5180;
  iVar3 = *(int *)(param_1 + 0x70);
  if ((*(uint *)(param_1 + 0x80) & 4) != 0) {
    StringCchPrintfW(local_220,0x104,L"%hs%hs",param_2,&DAT_c06d1214);
    pwVar2 = local_220;
    if (local_220[0] == L'\0') {
      pwVar2 = (wchar_t *)0x0;
    }
    FUN_c06d2090(param_1,L"Domain",1,pwVar2);
  }
  if (iVar3 != 0) {
    LocalFree(*(HLOCAL *)(iVar3 + 0x2c));
    *(undefined4 *)(iVar3 + 0x2c) = 0;
    if (*param_2 != '\0') {
      sVar1 = strlen(param_2);
      _Dest = LocalAlloc(0x40,sVar1 + 1);
      *(char **)(iVar3 + 0x2c) = _Dest;
      if (_Dest != (char *)0x0) {
        strcpy(_Dest,param_2);
      }
    }
  }
  FUN_c06d41e0(local_18);
  return;
}



/* c06d260c VEMAddBindings */

/* Boundary evidence: original MIPS .pdata c06d260c..c06d272f. Semantic name remains unreviewed. */

void VEMAddBindings(int param_1,wchar_t *param_2)

{
  wchar_t wVar1;
  bool bVar2;
  int iVar3;
  size_t sVar4;
  wchar_t *_Str2;
  int local_230;
  undefined1 auStack_22c [4];
  wchar_t local_228 [262];
  uint local_1c;
  
                    /* 0x260c  3  VEMAddBindings */
  local_1c = DAT_c06d5180;
  NdisGetAdapterBindings(&local_230,*(undefined4 *)(param_1 + 0x78),local_228,0x20a,auStack_22c);
  if (local_230 == 0) {
    wVar1 = *param_2;
    while (wVar1 != L'\0') {
      _Str2 = local_228;
      bVar2 = false;
      wVar1 = local_228[0];
      while (wVar1 != L'\0') {
        iVar3 = _wcsicmp(param_2,_Str2);
        if (iVar3 == 0) {
          bVar2 = true;
          break;
        }
        sVar4 = wcslen(_Str2);
        _Str2 = _Str2 + sVar4 + 1;
        wVar1 = *_Str2;
      }
      if (!bVar2) {
        NdisBindProtocolsToAdapter(&local_230,*(undefined4 *)(param_1 + 0x78),param_2);
      }
      sVar4 = wcslen(param_2);
      param_2 = param_2 + sVar4 + 1;
      wVar1 = *param_2;
    }
  }
  FUN_c06d41e0(local_1c);
  return;
}



/* c06d2730 VEMDeleteBindings */

/* Boundary evidence: original MIPS .pdata c06d2730..c06d2853. Semantic name remains unreviewed. */

void VEMDeleteBindings(int param_1,wchar_t *param_2)

{
  wchar_t wVar1;
  bool bVar2;
  int iVar3;
  size_t sVar4;
  wchar_t *_Str2;
  int local_230;
  undefined1 auStack_22c [4];
  wchar_t local_228 [262];
  uint local_1c;
  
                    /* 0x2730  4  VEMDeleteBindings */
  local_1c = DAT_c06d5180;
  NdisGetAdapterBindings(&local_230,*(undefined4 *)(param_1 + 0x78),local_228,0x20a,auStack_22c);
  if (local_230 == 0) {
    wVar1 = *param_2;
    while (wVar1 != L'\0') {
      _Str2 = local_228;
      bVar2 = false;
      wVar1 = local_228[0];
      while (wVar1 != L'\0') {
        iVar3 = _wcsicmp(param_2,_Str2);
        if (iVar3 == 0) {
          bVar2 = true;
          break;
        }
        sVar4 = wcslen(_Str2);
        _Str2 = _Str2 + sVar4 + 1;
        wVar1 = *_Str2;
      }
      if (bVar2) {
        NdisUnbindProtocolsFromAdapter(&local_230,*(undefined4 *)(param_1 + 0x78),param_2);
      }
      sVar4 = wcslen(param_2);
      param_2 = param_2 + sVar4 + 1;
      wVar1 = *param_2;
    }
  }
  FUN_c06d41e0(local_1c);
  return;
}



/* c06d2854 VEMSetMediaState */

/* Boundary evidence: original MIPS .pdata c06d2854..c06d289f. Semantic name remains unreviewed. */

void VEMSetMediaState(int *param_1,int param_2)

{
  undefined4 uVar1;
  
                    /* 0x2854  18  VEMSetMediaState */
  uVar1 = 0x4001000b;
  param_1[0x18] = param_2;
  if (param_2 == 1) {
    uVar1 = 0x4001000c;
  }
  (**(code **)(*param_1 + 0x220))(*param_1,uVar1,0,0);
  return;
}



/* c06d28a0 VEMQueryInformationComplete */

/* Boundary evidence: original MIPS .pdata c06d28a0..c06d28c7. Semantic name remains unreviewed. */

void VEMQueryInformationComplete(int *param_1)

{
                    /* 0x28a0  12  VEMQueryInformationComplete */
  (**(code **)(*param_1 + 0x22c))(*param_1);
  return;
}



/* c06d28c8 VEMSetInformationComplete */

/* Boundary evidence: original MIPS .pdata c06d28c8..c06d28ef. Semantic name remains unreviewed. */

void VEMSetInformationComplete(int *param_1)

{
                    /* 0x28c8  17  VEMSetInformationComplete */
  (**(code **)(*param_1 + 0x230))(*param_1);
  return;
}



/* c06d28f0 ndisBufferGetUpToNBytes */

/* Boundary evidence: original MIPS .pdata c06d28f0..c06d2a0b. Semantic name remains unreviewed. */

void * ndisBufferGetUpToNBytes(int *param_1,uint param_2,uint param_3,void *param_4,uint *param_5)

{
  void *_Src;
  uint _Size;
  void *pvVar1;
  uint uVar2;
  uint uVar3;
  
                    /* 0x28f0  22  ndisBufferGetUpToNBytes */
  pvVar1 = (void *)0x0;
  uVar2 = 0;
  for (; _Src = pvVar1, uVar3 = uVar2, param_1 != (int *)0x0; param_1 = (int *)*param_1) {
    _Size = param_1[2];
    _Src = (void *)param_1[1];
    if (param_2 < _Size) {
      if (param_2 != 0) {
        _Size = _Size - param_2;
        _Src = (void *)((int)_Src + param_2);
      }
      param_2 = 0;
      if ((pvVar1 == (void *)0x0) &&
         ((uVar3 = param_3, param_3 <= _Size || (pvVar1 = param_4, uVar3 = _Size, *param_1 == 0))))
      break;
      if (param_3 < _Size) {
        _Size = param_3;
      }
      memcpy(param_4,_Src,_Size);
      param_4 = (void *)(_Size + (int)param_4);
      param_3 = param_3 - _Size;
      uVar2 = _Size + uVar2;
      _Src = pvVar1;
      uVar3 = uVar2;
      if (param_3 == 0) break;
    }
    else {
      param_2 = param_2 - _Size;
    }
  }
  *param_5 = uVar3;
  return _Src;
}



/* c06d2a0c ndisBufferGetExactlyNBytes */

/* Boundary evidence: original MIPS .pdata c06d2a0c..c06d2a4b. Semantic name remains unreviewed. */

void * ndisBufferGetExactlyNBytes(int *param_1,uint param_2,uint param_3,void *param_4)

{
  void *pvVar1;
  uint local_10 [2];
  
                    /* 0x2a0c  21  ndisBufferGetExactlyNBytes */
  pvVar1 = ndisBufferGetUpToNBytes(param_1,param_2,param_3,param_4,local_10);
  if (local_10[0] != param_3) {
    pvVar1 = (void *)0x0;
  }
  return pvVar1;
}



/* c06d2a4c ndisBufferGetBEUshort */

/* Boundary evidence: original MIPS .pdata c06d2a4c..c06d2ac3. Semantic name remains unreviewed. */

bool ndisBufferGetBEUshort(int *param_1,uint param_2,undefined2 *param_3)

{
  undefined1 *puVar1;
  undefined1 auStack_18 [4];
  uint local_14;
  
                    /* 0x2a4c  20  ndisBufferGetBEUshort */
  puVar1 = ndisBufferGetUpToNBytes(param_1,param_2,2,auStack_18,&local_14);
  if (local_14 != 2) {
    puVar1 = (undefined1 *)0x0;
  }
  if (puVar1 != (undefined1 *)0x0) {
    *param_3 = CONCAT11(*puVar1,puVar1[1]);
  }
  return puVar1 != (undefined1 *)0x0;
}



/* c06d2ac4 FUN_c06d2ac4 */

/* Boundary evidence: original MIPS .pdata c06d2ac4..c06d2ba3. Semantic name remains unreviewed. */

undefined4 * FUN_c06d2ac4(int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 *local_18;
  int local_14;
  
  NdisAcquireSpinLock(param_1);
  local_18 = *(undefined4 **)(param_1 + 0x18);
  if (local_18 == (undefined4 *)0x0) {
    NdisAllocateBuffer(&local_14,&local_18,*(undefined4 *)(param_1 + 0x14),param_2,param_3);
    if (local_14 == 0) {
      *(int *)(param_1 + 0x1c) = *(int *)(param_1 + 0x1c) + 1;
      *(int *)(param_1 + 0x20) = *(int *)(param_1 + 0x20) + 1;
    }
  }
  else {
    *(undefined4 *)(param_1 + 0x18) = *local_18;
    *(int *)(param_1 + 0x20) = *(int *)(param_1 + 0x20) + 1;
    local_18[4] = param_2;
    local_18[1] = param_2;
    local_18[2] = param_3;
    *local_18 = 0;
  }
  NdisReleaseSpinLock(param_1);
  return local_18;
}



/* c06d2ba4 FUN_c06d2ba4 */

/* Boundary evidence: original MIPS .pdata c06d2ba4..c06d2c07. Semantic name remains unreviewed. */

void FUN_c06d2ba4(int param_1,undefined4 *param_2)

{
  NdisAcquireSpinLock(param_1);
  *param_2 = *(undefined4 *)(param_1 + 0x18);
  *(undefined4 **)(param_1 + 0x18) = param_2;
  *(int *)(param_1 + 0x20) = *(int *)(param_1 + 0x20) + -1;
  NdisReleaseSpinLock(param_1);
  return;
}



/* c06d2c08 FUN_c06d2c08 */

/* Boundary evidence: original MIPS .pdata c06d2c08..c06d2c9b. Semantic name remains unreviewed. */

int FUN_c06d2c08(int *param_1)

{
  int iVar1;
  int local_10 [2];
  
  local_10[0] = NdisAllocateMemoryWithTag(param_1,0x2c,0x4c4f4f50);
  if (local_10[0] == 0) {
    iVar1 = *param_1;
    NdisAllocateBufferPool(local_10,iVar1 + 0x14,1);
    if (local_10[0] == 0) {
      NdisAllocateSpinLock(iVar1);
      *(undefined4 *)(iVar1 + 0x18) = 0;
      *(undefined4 *)(iVar1 + 0x1c) = 0;
      *(undefined4 *)(iVar1 + 0x20) = 0;
      *(undefined4 *)(iVar1 + 0x24) = 0;
      *(undefined4 *)(iVar1 + 0x28) = 0;
    }
  }
  return local_10[0];
}



/* c06d2c9c FUN_c06d2c9c */

/* Boundary evidence: original MIPS .pdata c06d2c9c..c06d2d17. Semantic name remains unreviewed. */

void FUN_c06d2c9c(int param_1)

{
  int *piVar1;
  
  piVar1 = *(int **)(param_1 + 0x18);
  while (piVar1 != (int *)0x0) {
    piVar1 = (int *)*piVar1;
    NdisFreeBuffer();
  }
  NdisFreeSpinLock(param_1);
  NdisFreeMemory(param_1,0x2c,0);
  return;
}



/* c06d2d18 FUN_c06d2d18 */

/* Boundary evidence: original MIPS .pdata c06d2d18..c06d2d37. Semantic name remains unreviewed. */

void FUN_c06d2d18(int param_1)

{
  FUN_c06d2ac4(param_1,*(undefined4 *)(param_1 + 0x24),*(undefined4 *)(param_1 + 0x28));
  return;
}



/* c06d2d38 FUN_c06d2d38 */

/* Boundary evidence: original MIPS .pdata c06d2d38..c06d2d8b. Semantic name remains unreviewed. */

void FUN_c06d2d38(int *param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  
  iVar1 = FUN_c06d2c08(param_1);
  if (iVar1 == 0) {
    iVar1 = *param_1;
    *(undefined4 *)(iVar1 + 0x24) = param_2;
    *(undefined4 *)(iVar1 + 0x28) = param_3;
  }
  return;
}



/* c06d2d8c FUN_c06d2d8c */

/* Boundary evidence: original MIPS .pdata c06d2d8c..c06d2e2f. Semantic name remains unreviewed. */

undefined4 * FUN_c06d2d8c(int param_1)

{
  uint uVar1;
  undefined4 *puVar2;
  undefined4 *local_18 [2];
  
  puVar2 = (undefined4 *)0x0;
  NdisAcquireSpinLock(param_1);
  local_18[0] = *(undefined4 **)(param_1 + 0x14);
  if (local_18[0] == (undefined4 *)0x0) {
    uVar1 = *(int *)(param_1 + 0x18) + 4;
    if (3 < uVar1) {
      NdisAllocateMemoryWithTag(local_18,uVar1,0x46465542);
    }
  }
  else {
    *(undefined4 *)(param_1 + 0x14) = *local_18[0];
  }
  NdisReleaseSpinLock(param_1);
  if (local_18[0] != (undefined4 *)0x0) {
    puVar2 = local_18[0] + 1;
  }
  return puVar2;
}



/* c06d2e30 FUN_c06d2e30 */

/* Boundary evidence: original MIPS .pdata c06d2e30..c06d2e87. Semantic name remains unreviewed. */

void FUN_c06d2e30(int param_1,int param_2)

{
  NdisAcquireSpinLock(param_1);
  *(undefined4 *)(param_2 + -4) = *(undefined4 *)(param_1 + 0x14);
  *(undefined4 **)(param_1 + 0x14) = (undefined4 *)(param_2 + -4);
  NdisReleaseSpinLock(param_1);
  return;
}



/* c06d2e88 FUN_c06d2e88 */

/* Boundary evidence: original MIPS .pdata c06d2e88..c06d2f0f. Semantic name remains unreviewed. */

int FUN_c06d2e88(int *param_1,undefined4 param_2)

{
  int iVar1;
  int local_18 [2];
  
  iVar1 = NdisAllocateMemoryWithTag(local_18,0x1c,0x50465542);
  if (iVar1 == 0) {
    NdisAllocateSpinLock(local_18[0]);
    *(undefined4 *)(local_18[0] + 0x18) = param_2;
    *(undefined4 *)(local_18[0] + 0x14) = 0;
  }
  *param_1 = local_18[0];
  return iVar1;
}



/* c06d2f10 FUN_c06d2f10 */

/* Boundary evidence: original MIPS .pdata c06d2f10..c06d2f8b. Semantic name remains unreviewed. */

void FUN_c06d2f10(int param_1)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = (int *)*(int *)(param_1 + 0x14);
  while (piVar1 != (int *)0x0) {
    iVar2 = *piVar1;
    NdisFreeMemory(piVar1,0,0);
    piVar1 = (int *)iVar2;
  }
  NdisFreeSpinLock(param_1);
  NdisFreeMemory(param_1,0,0);
  return;
}



/* c06d2f8c FUN_c06d2f8c */

undefined1 * FUN_c06d2f8c(undefined1 *param_1,undefined4 param_2)

{
  *param_1 = (char)((uint)param_2 >> 0x18);
  param_1[1] = (char)((uint)param_2 >> 0x10);
  param_1[2] = (char)((uint)param_2 >> 8);
  param_1[3] = (char)param_2;
  return param_1 + 4;
}



/* c06d2fbc FUN_c06d2fbc */

uint FUN_c06d2fbc(byte *param_1,uint param_2,uint param_3)

{
  uint uVar1;
  
  if (1 < param_2) {
    uVar1 = param_2 >> 1;
    param_2 = param_2 + uVar1 * -2;
    do {
      param_3 = CONCAT11(*param_1,param_1[1]) + param_3;
      uVar1 = uVar1 - 1;
      param_1 = param_1 + 2;
    } while (uVar1 != 0);
  }
  if (0 < (int)param_2) {
    param_3 = *param_1 + param_3;
  }
  uVar1 = (param_3 >> 0x10) + (param_3 & 0xffff);
  return (uVar1 >> 0x10) + uVar1 & 0xffff;
}



/* c06d3024 FUN_c06d3024 */

/* Boundary evidence: original MIPS .pdata c06d3024..c06d3137. Semantic name remains unreviewed. */

uint FUN_c06d3024(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 byte *param_5,int param_6)

{
  uint uVar1;
  
  uVar1 = param_6 + 0x1cU & 0xffff;
  *param_5 = 0x45;
  param_5[1] = 0;
  param_5[2] = (byte)(uVar1 >> 8);
  param_5[3] = (byte)uVar1;
  param_5[4] = 0;
  param_5[5] = 0;
  param_5[6] = 0;
  param_5[7] = 0;
  param_5[8] = 0x80;
  param_5[9] = 0x11;
  param_5[10] = 0;
  param_5[0xb] = 0;
  FUN_c06d2f8c(param_5 + 0xc,param_1);
  FUN_c06d2f8c(param_5 + 0x10,param_2);
  uVar1 = FUN_c06d2fbc(param_5,0x14,0);
  param_5[10] = (byte)((~uVar1 & 0xffff) >> 8);
  param_5[0xb] = (byte)(~uVar1 & 0xffff);
  param_5[0x14] = (byte)((uint)param_3 >> 8);
  param_5[0x15] = (byte)param_3;
  uVar1 = param_6 + 8U & 0xffff;
  param_5[0x16] = (byte)((uint)param_4 >> 8);
  param_5[0x17] = (byte)param_4;
  param_5[0x18] = (byte)(uVar1 >> 8);
  param_5[0x19] = (byte)uVar1;
  param_5[0x1a] = 0;
  param_5[0x1b] = 0;
  return param_6 + 0x1cU;
}



/* c06d3138 FUN_c06d3138 */

/* Boundary evidence: original MIPS .pdata c06d3138..c06d31bb. Semantic name remains unreviewed. */

void FUN_c06d3138(int param_1,int param_2)

{
  undefined4 *local_10 [2];
  
  if (*(int *)(param_2 + 0x24) == 1) {
    NdisUnchainBufferAtFront(param_2,local_10);
    if (local_10[0] != (undefined4 *)0x0) {
      DHCPServerFreePacket(*(undefined4 *)(param_1 + 0x70),local_10[0][1] + 0x1c);
      FUN_c06d2ba4(*(int *)(param_1 + 0x6c),local_10[0]);
    }
  }
  else {
    (**(code **)(param_1 + 0xa8))(*(undefined4 *)(param_1 + 0xcc),param_2);
  }
  return;
}



/* c06d31bc FUN_c06d31bc */

/* Boundary evidence: original MIPS .pdata c06d31bc..c06d335f. Semantic name remains unreviewed. */

undefined4 FUN_c06d31bc(int param_1,undefined4 param_2,int *param_3,uint param_4,int param_5)

{
  byte *pbVar1;
  void *pvVar2;
  int iVar3;
  uint uVar4;
  undefined4 uVar5;
  uint uVar6;
  undefined1 auStack_250 [8];
  undefined1 auStack_248 [24];
  undefined1 auStack_230 [512];
  uint local_30;
  
  local_30 = DAT_c06d5180;
  uVar5 = 0;
  if ((((*(int *)(param_1 + 0x70) != 0) && (param_5 == 1)) &&
      (pbVar1 = ndisBufferGetExactlyNBytes(param_3,param_4,0x14,auStack_248), pbVar1 != (byte *)0x0)
      ) && (pbVar1[9] == 0x11)) {
    uVar6 = (*pbVar1 & 0xf) * 4 + param_4;
    pvVar2 = ndisBufferGetExactlyNBytes(param_3,uVar6,8,auStack_250);
    if ((pvVar2 != (void *)0x0) && (iVar3 = memcmp(&DAT_c06d1218,pvVar2,4), iVar3 == 0)) {
      uVar4 = CONCAT11(*(undefined1 *)((int)pvVar2 + 4),*(undefined1 *)((int)pvVar2 + 5)) + 0xfff8 &
              0xffff;
      if ((uVar4 < 0x201) &&
         (pvVar2 = ndisBufferGetExactlyNBytes(param_3,uVar6 + 8,uVar4,auStack_230),
         pvVar2 != (void *)0x0)) {
        DHCPServerProcessPacket(*(undefined4 *)(param_1 + 0x70),pvVar2,uVar4);
      }
      goto LAB_c06d3328;
    }
  }
  if (*(code **)(param_1 + 0xa4) == (code *)0x0) {
    uVar5 = 0xc00000bb;
  }
  else {
    uVar5 = (**(code **)(param_1 + 0xa4))
                      (*(undefined4 *)(param_1 + 0xcc),param_2,param_3,param_4,param_5);
  }
LAB_c06d3328:
  FUN_c06d41e0(local_30);
  return uVar5;
}



/* c06d3360 FUN_c06d3360 */

/* Boundary evidence: original MIPS .pdata c06d3360..c06d348f. Semantic name remains unreviewed. */

void FUN_c06d3360(int *param_1,undefined4 param_2,undefined4 param_3,int param_4,int param_5)

{
  uint uVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  int local_18;
  int local_14;
  
  uVar1 = FUN_c06d3024(param_2,param_3,0x43,0x44,(byte *)(param_4 + -0x1c),param_5);
  NdisAllocatePacket(&local_14,&local_18,param_1[9]);
  if (local_14 == 0) {
    piVar2 = FUN_c06d2ac4(param_1[0x1b],(byte *)(param_4 + -0x1c),uVar1);
    if (piVar2 != (int *)0x0) {
      *(undefined4 *)(local_18 + 0x24) = 1;
      iVar3 = *piVar2;
      piVar4 = piVar2;
      while (iVar3 != 0) {
        piVar4 = (int *)*piVar4;
        iVar3 = *piVar4;
      }
      if (*(int *)(local_18 + 8) == 0) {
        *(int **)(local_18 + 8) = piVar2;
      }
      else {
        **(undefined4 **)(local_18 + 0xc) = piVar2;
      }
      *(int **)(local_18 + 0xc) = piVar4;
      *piVar4 = 0;
      *(undefined1 *)(local_18 + 0x1c) = 0;
      local_14 = FUN_c06d39f8(param_1,local_18,1);
      if (local_14 == 0) {
        return;
      }
      FUN_c06d2ba4(param_1[0x1b],piVar2);
    }
    NdisFreePacket(local_18);
  }
  return;
}



/* c06d3490 FUN_c06d3490 */

/* Boundary evidence: original MIPS .pdata c06d3490..c06d3537. Semantic name remains unreviewed. */

int FUN_c06d3490(int param_1)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = FUN_c06d2c08((int *)(param_1 + 0x6c));
  if ((iVar1 == 0) && ((*(uint *)(param_1 + 0x80) & 1) == 0)) {
    piVar2 = (int *)DHCPServerSessionNew(param_1,FUN_c06d3360,0x1c);
    if (piVar2 == (int *)0x0) {
      iVar1 = -0x3fffff66;
    }
    else {
      *(int **)(param_1 + 0x70) = piVar2;
      *piVar2 = *(int *)(param_1 + 0x90) + 1;
      piVar2[1] = *(int *)(param_1 + 0x90);
      piVar2[2] = 1;
      piVar2[3] = *(int *)(param_1 + 0x98);
      piVar2[4] = *(int *)(param_1 + 0x94);
    }
  }
  return iVar1;
}



/* c06d3538 FUN_c06d3538 */

/* Boundary evidence: original MIPS .pdata c06d3538..c06d3567. Semantic name remains unreviewed. */

void FUN_c06d3538(int param_1)

{
  FUN_c06d2c9c(*(int *)(param_1 + 0x6c));
  DHCPServerSessionDelete(*(undefined4 *)(param_1 + 0x70));
  return;
}



/* c06d3568 FUN_c06d3568 */

void FUN_c06d3568(int param_1,undefined4 *param_2,undefined4 *param_3)

{
  undefined1 uVar1;
  
  *param_3 = 0x80100;
  *(undefined1 *)(param_3 + 1) = 6;
  *(undefined1 *)((int)param_3 + 5) = 4;
  *(undefined1 *)((int)param_3 + 6) = 0;
  *(undefined1 *)((int)param_3 + 7) = 2;
  param_3[2] = *param_2;
  uVar1 = *(undefined1 *)((int)param_2 + 5);
  *(undefined1 *)(param_3 + 3) = *(undefined1 *)(param_2 + 1);
  *(undefined1 *)((int)param_3 + 0xd) = uVar1;
  *(undefined4 *)((int)param_3 + 0xe) = *(undefined4 *)(param_1 + 0x18);
  *(undefined4 *)((int)param_3 + 0x12) = *(undefined4 *)(param_1 + 8);
  uVar1 = *(undefined1 *)(param_1 + 0xd);
  *(undefined1 *)((int)param_3 + 0x16) = *(undefined1 *)(param_1 + 0xc);
  *(undefined1 *)((int)param_3 + 0x17) = uVar1;
  param_3[6] = *(undefined4 *)(param_1 + 0xe);
  return;
}



/* c06d3628 FUN_c06d3628 */

/* Boundary evidence: original MIPS .pdata c06d3628..c06d3837. Semantic name remains unreviewed. */

int FUN_c06d3628(int *param_1,int *param_2,uint param_3)

{
  void *_Buf1;
  int iVar1;
  int *piVar2;
  int *piVar3;
  undefined4 *puVar4;
  int local_48;
  int local_44;
  undefined1 auStack_40 [28];
  uint local_24;
  
  local_24 = DAT_c06d5180;
  local_48 = 0;
  local_44 = 0;
  puVar4 = (undefined4 *)0x0;
  piVar3 = (int *)0x0;
  _Buf1 = ndisBufferGetExactlyNBytes(param_2,param_3,0x1c,auStack_40);
  if ((_Buf1 == (void *)0x0) || (iVar1 = memcmp(_Buf1,&DAT_c06d1220,8), iVar1 != 0)) {
LAB_c06d37b8:
    if (local_48 == 0) goto LAB_c06d3808;
LAB_c06d37c4:
    if (puVar4 != (undefined4 *)0x0) {
      FUN_c06d2e30(param_1[0x1a],(int)puVar4);
    }
    if (piVar3 != (int *)0x0) {
      FUN_c06d2ba4(param_1[0x19],piVar3);
    }
  }
  else {
    iVar1 = memcmp((void *)((int)_Buf1 + 0xe),(void *)((int)_Buf1 + 0x18),4);
    if ((iVar1 == 0) || (iVar1 = memcmp((void *)((int)_Buf1 + 0xe),&DAT_c06d1228,4), iVar1 == 0))
    goto LAB_c06d37b8;
    NdisAllocatePacket(&local_48,&local_44,param_1[9]);
    if (local_48 == 0) {
      puVar4 = FUN_c06d2d8c(param_1[0x1a]);
      if ((puVar4 != (undefined4 *)0x0) &&
         (piVar3 = FUN_c06d2ac4(param_1[0x19],puVar4,0x1c), piVar3 != (int *)0x0)) {
        FUN_c06d3568((int)_Buf1,(undefined4 *)((int)param_1 + 0x1e),puVar4);
        iVar1 = *piVar3;
        piVar2 = piVar3;
        while (iVar1 != 0) {
          piVar2 = (int *)*piVar2;
          iVar1 = *piVar2;
        }
        if (*(int *)(local_44 + 8) == 0) {
          *(int **)(local_44 + 8) = piVar3;
        }
        else {
          **(undefined4 **)(local_44 + 0xc) = piVar3;
        }
        *(int **)(local_44 + 0xc) = piVar2;
        *piVar2 = 0;
        *(undefined1 *)(local_44 + 0x1c) = 0;
        FUN_c06d39f8(param_1,local_44,0);
        goto LAB_c06d37b8;
      }
      local_48 = -0x3fffff66;
      goto LAB_c06d37c4;
    }
  }
  if (local_44 != 0) {
    NdisFreePacket();
  }
LAB_c06d3808:
  FUN_c06d41e0(local_24);
  return local_48;
}



/* c06d3838 FUN_c06d3838 */

/* Boundary evidence: original MIPS .pdata c06d3838..c06d3893. Semantic name remains unreviewed. */

void FUN_c06d3838(int param_1,undefined4 param_2)

{
  undefined4 *local_10 [2];
  
  NdisUnchainBufferAtFront(param_2,local_10);
  if (local_10[0] != (undefined4 *)0x0) {
    FUN_c06d2e30(*(int *)(param_1 + 0x68),local_10[0][1]);
    FUN_c06d2ba4(*(int *)(param_1 + 100),local_10[0]);
  }
  return;
}



/* c06d3894 FUN_c06d3894 */

/* Boundary evidence: original MIPS .pdata c06d3894..c06d38d3. Semantic name remains unreviewed. */

void FUN_c06d3894(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_c06d2c08((int *)(param_1 + 100));
  if (iVar1 == 0) {
    FUN_c06d2e88((int *)(param_1 + 0x68),0x1c);
  }
  return;
}



/* c06d38d4 FUN_c06d38d4 */

/* Boundary evidence: original MIPS .pdata c06d38d4..c06d3903. Semantic name remains unreviewed. */

void FUN_c06d38d4(int param_1)

{
  FUN_c06d2c9c(*(int *)(param_1 + 100));
  FUN_c06d2f10(*(int *)(param_1 + 0x68));
  return;
}



/* c06d3904 FUN_c06d3904 */

/* Boundary evidence: original MIPS .pdata c06d3904..c06d39f7. Semantic name remains unreviewed. */

void FUN_c06d3904(int *param_1,int param_2)

{
  bool bVar1;
  undefined3 extraout_var;
  int iVar2;
  int *piVar3;
  short local_20 [4];
  
  piVar3 = *(int **)(param_2 + 8);
  iVar2 = 0;
  bVar1 = ndisBufferGetBEUshort(piVar3,0xc,local_20);
  if (CONCAT31(extraout_var,bVar1) != 0) {
    if (local_20[0] == 0x806) {
      iVar2 = FUN_c06d3628(param_1,piVar3,0xe);
    }
    else {
      if (local_20[0] == 0x800) {
        iVar2 = 1;
      }
      else {
        if (local_20[0] != -0x7923) goto LAB_c06d39c4;
        iVar2 = 2;
      }
      iVar2 = FUN_c06d31bc((int)param_1,param_2,piVar3,0xe,iVar2);
    }
    if (iVar2 == 0x103) {
      return;
    }
  }
LAB_c06d39c4:
  (**(code **)(*param_1 + 0x10c))(*param_1,param_2,iVar2);
  return;
}



/* c06d39f8 FUN_c06d39f8 */

/* Boundary evidence: original MIPS .pdata c06d39f8..c06d3adf. Semantic name remains unreviewed. */

undefined4 FUN_c06d39f8(int *param_1,int param_2,int param_3)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  undefined4 uVar4;
  int local_res4 [3];
  
  *(int *)(param_2 + 0x20) = param_3;
  *(undefined4 *)((uint)*(ushort *)(param_2 + 0x1e) + param_2 + 0x10) = 0xe;
  *(undefined4 *)((uint)*(ushort *)(param_2 + 0x1e) + param_2 + 0x1c) = 0;
  uVar4 = 0;
  local_res4[0] = param_2;
  piVar1 = (int *)FUN_c06d2d18(param_1[param_3 + 0x15]);
  if (piVar1 == (int *)0x0) {
    uVar4 = 0xc000009a;
  }
  else {
    iVar2 = *piVar1;
    piVar3 = piVar1;
    while (iVar2 != 0) {
      piVar3 = (int *)*piVar3;
      iVar2 = *piVar3;
    }
    if (*(int *)(local_res4[0] + 8) == 0) {
      *(int **)(local_res4[0] + 0xc) = piVar3;
    }
    *piVar3 = *(int *)(local_res4[0] + 8);
    *(int **)(local_res4[0] + 8) = piVar1;
    *(undefined1 *)(local_res4[0] + 0x1c) = 0;
    (**(code **)(*param_1 + 0x108))(*param_1,local_res4,1);
  }
  return uVar4;
}



/* c06d3ae0 FUN_c06d3ae0 */

/* Boundary evidence: original MIPS .pdata c06d3ae0..c06d3b7f. Semantic name remains unreviewed. */

void FUN_c06d3ae0(int param_1,int param_2)

{
  int iVar1;
  undefined4 *local_18 [2];
  
  NdisUnchainBufferAtFront(param_2,local_18);
  if (local_18[0] != (undefined4 *)0x0) {
    iVar1 = *(int *)(param_2 + 0x20);
    FUN_c06d2ba4(*(int *)((iVar1 + 0x15) * 4 + param_1),local_18[0]);
    if (iVar1 == 0) {
      FUN_c06d3838(param_1,param_2);
    }
    else {
      FUN_c06d3138(param_1,param_2);
    }
  }
  NdisFreePacket(param_2);
  return;
}



/* c06d3b80 FUN_c06d3b80 */

/* Boundary evidence: original MIPS .pdata c06d3b80..c06d3e3f. Semantic name remains unreviewed. */

void FUN_c06d3b80(int param_1)

{
  char *pcVar1;
  char *pcVar2;
  int local_20 [2];
  
  *(undefined4 *)(param_1 + 0x60) = 1;
  pcVar1 = (char *)(param_1 + 0x18);
  pcVar2 = (char *)(param_1 + 0x1e);
  if ((*(uint *)(param_1 + 0x80) & 0x40) == 0) {
    builtin_strncpy(pcVar1," LOC",4);
    *(undefined1 *)(param_1 + 0x1c) = 0x41;
    *(undefined1 *)(param_1 + 0x1d) = 0x4c;
    builtin_strncpy(pcVar2,"  PE",4);
    *(undefined1 *)(param_1 + 0x22) = 0x45;
    *(undefined1 *)(param_1 + 0x23) = 0x52;
  }
  else {
    *(undefined4 *)pcVar1 = *(undefined4 *)(param_1 + 0x84);
    *(undefined1 *)(param_1 + 0x1d) = *(undefined1 *)(param_1 + 0x89);
    *(undefined1 *)(param_1 + 0x1c) = *(undefined1 *)(param_1 + 0x88);
    *(undefined4 *)pcVar2 = *(undefined4 *)(param_1 + 0x8a);
    *(undefined1 *)(param_1 + 0x22) = *(undefined1 *)(param_1 + 0x8e);
    *(undefined1 *)(param_1 + 0x23) = *(undefined1 *)(param_1 + 0x8f);
  }
  NdisAllocatePacketPoolEx(local_20,param_1 + 0x24,0x14,200,0x10);
  if (local_20[0] == 0) {
    *(undefined4 *)(param_1 + 0x28) = *(undefined4 *)pcVar1;
    *(undefined1 *)(param_1 + 0x2c) = *(undefined1 *)(param_1 + 0x1c);
    *(undefined1 *)(param_1 + 0x2d) = *(undefined1 *)(param_1 + 0x1d);
    *(undefined4 *)(param_1 + 0x2e) = *(undefined4 *)pcVar2;
    *(undefined1 *)(param_1 + 0x32) = *(undefined1 *)(param_1 + 0x22);
    *(undefined1 *)(param_1 + 0x33) = *(undefined1 *)(param_1 + 0x23);
    *(undefined1 *)(param_1 + 0x34) = 8;
    *(undefined1 *)(param_1 + 0x35) = 6;
    *(undefined4 *)(param_1 + 0x36) = *(undefined4 *)pcVar1;
    *(undefined1 *)(param_1 + 0x3a) = *(undefined1 *)(param_1 + 0x1c);
    *(undefined1 *)(param_1 + 0x3b) = *(undefined1 *)(param_1 + 0x1d);
    *(undefined4 *)(param_1 + 0x3c) = *(undefined4 *)pcVar2;
    *(undefined1 *)(param_1 + 0x41) = *(undefined1 *)(param_1 + 0x23);
    *(undefined1 *)(param_1 + 0x40) = *(undefined1 *)(param_1 + 0x22);
    *(undefined1 *)(param_1 + 0x42) = 8;
    *(undefined1 *)(param_1 + 0x43) = 0;
    *(undefined4 *)(param_1 + 0x44) = *(undefined4 *)pcVar1;
    *(undefined1 *)(param_1 + 0x49) = *(undefined1 *)(param_1 + 0x1d);
    *(undefined1 *)(param_1 + 0x48) = *(undefined1 *)(param_1 + 0x1c);
    *(undefined4 *)(param_1 + 0x4a) = *(undefined4 *)pcVar2;
    *(undefined1 *)(param_1 + 0x4e) = *(undefined1 *)(param_1 + 0x22);
    *(undefined1 *)(param_1 + 0x4f) = *(undefined1 *)(param_1 + 0x23);
    *(undefined1 *)(param_1 + 0x50) = 0x86;
    *(undefined1 *)(param_1 + 0x51) = 0xdd;
    local_20[0] = FUN_c06d2d38((int *)(param_1 + 0x54),(undefined4 *)(param_1 + 0x28),0xe);
    if (local_20[0] == 0) {
      local_20[0] = FUN_c06d2d38((int *)(param_1 + 0x58),(undefined4 *)(param_1 + 0x36),0xe);
      if (local_20[0] == 0) {
        FUN_c06d2d38((int *)(param_1 + 0x5c),(undefined4 *)(param_1 + 0x44),0xe);
      }
    }
  }
  return;
}



/* c06d3e40 FUN_c06d3e40 */

/* Boundary evidence: original MIPS .pdata c06d3e40..c06d3e9b. Semantic name remains unreviewed. */

void FUN_c06d3e40(int param_1)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = (int *)(param_1 + 0x54);
  iVar2 = 3;
  do {
    FUN_c06d2c9c(*piVar1);
    iVar2 = iVar2 + -1;
    piVar1 = piVar1 + 1;
  } while (iVar2 != 0);
  NdisFreePacketPool(*(undefined4 *)(param_1 + 0x24));
  return;
}



/* c06d3f2c FUN_c06d3f2c */

/* Boundary evidence: original MIPS .pdata c06d3f2c..c06d4067. Semantic name remains unreviewed. */

int FUN_c06d3f2c(HMODULE param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 1;
  if (param_2 == 1) {
    if (DAT_c06d51a4 != (code *)0x0) {
      iVar2 = (*DAT_c06d51a4)(param_1,1,param_3);
    }
    iVar1 = 0;
    if (iVar2 == 0) goto LAB_c06d3fdc;
    FUN_c06d43c0();
  }
  iVar1 = 0;
  if (iVar2 != 0) {
    iVar1 = DllMain(param_1,param_2);
  }
LAB_c06d3fdc:
  if (((param_2 == 0) && (FUN_c06d4348(), iVar1 != 0)) && (DAT_c06d51a4 != (code *)0x0)) {
    iVar1 = (*DAT_c06d51a4)(param_1,0,param_3);
  }
  return iVar1;
}



/* c06d4068 FUN_c06d4068 */

/* Boundary evidence: original MIPS .pdata c06d4068..c06d4093. Semantic name remains unreviewed. */

void FUN_c06d4068(_EXCEPTION_POINTERS *param_1)

{
  _XcptFilter(param_1->ExceptionRecord->ExceptionCode,param_1);
  return;
}



/* c06d4094 entry */

/* Boundary evidence: original MIPS .pdata c06d4094..c06d40eb. Semantic name remains unreviewed. */

void entry(HMODULE param_1,int param_2,undefined4 param_3)

{
  if (param_2 == 1) {
    FUN_c06d40ec();
  }
  FUN_c06d3f2c(param_1,param_2,param_3);
  return;
}



/* c06d40ec FUN_c06d40ec */

/* Boundary evidence: original MIPS .pdata c06d40ec..c06d415f. Semantic name remains unreviewed. */

void FUN_c06d40ec(void)

{
  uint uVar1;
  
  if ((DAT_c06d5180 == 0) || (DAT_c06d5180 == 0xb064)) {
    uVar1 = __security_gen_cookie2();
    DAT_c06d5180 = uVar1 >> 0x10 ^ uVar1 & 0xffff;
    if (DAT_c06d5180 == 0) {
      DAT_c06d5180 = 0xb064;
    }
  }
  DAT_c06d5184 = ~DAT_c06d5180;
  return;
}



/* c06d4160 FUN_c06d4160 */

/* Boundary evidence: original MIPS .pdata c06d4160..c06d41b3. Semantic name remains unreviewed. */

void FUN_c06d4160(int param_1,undefined4 param_2,uint *param_3)

{
  if ((*param_3 & 1) != 0) {
    param_1 = ((-param_3[2] & param_3[1] + param_1) - (param_3[1] + param_1)) + param_1;
  }
  FUN_c06d41e0(*(uint *)(param_1 + (*param_3 & 0xfffffffc)));
  return;
}



/* c06d41b4 FUN_c06d41b4 */

/* Boundary evidence: original MIPS .pdata c06d41b4..c06d41df. Semantic name remains unreviewed. */

undefined4 FUN_c06d41b4(undefined4 param_1,int param_2,undefined4 param_3,int param_4)

{
  FUN_c06d4160(param_2,param_4,*(uint **)(*(int *)(param_4 + 4) + 0xc));
  return 1;
}



/* c06d41e0 FUN_c06d41e0 */

/* Boundary evidence: original MIPS .pdata c06d41e0..c06d4227. Semantic name remains unreviewed. */

void FUN_c06d41e0(uint param_1)

{
  if ((param_1 == DAT_c06d5180) && (param_1 >> 0x10 == 0)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __report_gsfailure();
}



/* c06d4228 FUN_c06d4228 */

/* Boundary evidence: original MIPS .pdata c06d4228..c06d4347. Semantic name remains unreviewed. */

void FUN_c06d4228(UINT param_1,int param_2,int param_3)

{
  LPCRITICAL_SECTION lpCriticalSection;
  undefined4 *_Memory;
  
  DAT_c06d5194 = (undefined1)param_3;
  if (param_2 == 0) {
    _Memory = DAT_c06d519c;
    if (DAT_c06d519c != (undefined4 *)0x0) {
      while (DAT_c06d5198 = DAT_c06d5198 + -1, _Memory <= DAT_c06d5198) {
        if ((code *)*DAT_c06d5198 != (code *)0x0) {
          (*(code *)*DAT_c06d5198)();
          _Memory = DAT_c06d519c;
        }
      }
      free(_Memory);
      DAT_c06d5198 = (undefined4 *)0x0;
      DAT_c06d519c = (undefined4 *)0x0;
    }
    FUN_c06d436c((undefined4 *)&DAT_c06d1010,(undefined4 *)&DAT_c06d1014);
  }
  FUN_c06d436c((undefined4 *)&DAT_c06d1018,(undefined4 *)&DAT_c06d101c);
  if (param_3 == 0) {
    TerminateProcess((HANDLE)0x42,param_1);
  }
  else {
    lpCriticalSection = (LPCRITICAL_SECTION)InterlockedExchange((LONG *)&DAT_c06d51a0,0);
    if (lpCriticalSection != (LPCRITICAL_SECTION)0x0) {
      DeleteCriticalSection(lpCriticalSection);
      free(lpCriticalSection);
    }
  }
  return;
}



/* c06d4348 FUN_c06d4348 */

/* Boundary evidence: original MIPS .pdata c06d4348..c06d436b. Semantic name remains unreviewed. */

void FUN_c06d4348(void)

{
  FUN_c06d4228(0,0,1);
  return;
}



/* c06d436c FUN_c06d436c */

/* Boundary evidence: original MIPS .pdata c06d436c..c06d43bf. Semantic name remains unreviewed. */

void FUN_c06d436c(undefined4 *param_1,undefined4 *param_2)

{
  for (; param_1 < param_2; param_1 = param_1 + 1) {
    if ((code *)*param_1 != (code *)0x0) {
      (*(code *)*param_1)();
    }
  }
  return;
}



/* c06d43c0 FUN_c06d43c0 */

/* Boundary evidence: original MIPS .pdata c06d43c0..c06d43fb. Semantic name remains unreviewed. */

void FUN_c06d43c0(void)

{
  FUN_c06d436c((undefined4 *)&DAT_c06d1008,(undefined4 *)&DAT_c06d100c);
  FUN_c06d436c((undefined4 *)&DAT_c06d1000,(undefined4 *)&DAT_c06d1004);
  return;
}


