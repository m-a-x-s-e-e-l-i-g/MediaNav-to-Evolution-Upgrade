/* Automatic Ghidra pseudocode. Not original source; not runtime-verified. */

/* 4032107c FUN_4032107c */

/* Boundary evidence: original MIPS .pdata 4032107c..40321203. Semantic name remains unreviewed. */

void FUN_4032107c(char *param_1,void *param_2,size_t param_3,int param_4,undefined4 param_5,
                 byte *param_6)

{
  size_t sVar1;
  byte *pbVar2;
  int iVar3;
  int iVar4;
  byte abStack_60 [40];
  undefined1 auStack_38 [20];
  uint local_24;
  
  local_24 = DAT_4032307c;
  if ((0 < (int)param_3) && ((int)param_3 < 0x21)) {
    memcpy(abStack_60,param_2,param_3);
    abStack_60[param_3] = (byte)((uint)param_5 >> 0x18);
    abStack_60[param_3 + 1] = (byte)((uint)param_5 >> 0x10);
    abStack_60[param_3 + 2] = (byte)((uint)param_5 >> 8);
    abStack_60[param_3 + 3] = (byte)param_5;
    sVar1 = strlen(param_1);
    FUN_4032212c(abStack_60,param_3 + 4,param_1,sVar1,auStack_38,0x14);
    memcpy(param_6,auStack_38,0x14);
    if (1 < param_4) {
      iVar4 = param_4 + -1;
      do {
        sVar1 = strlen(param_1);
        FUN_4032212c(auStack_38,0x14,param_1,sVar1,abStack_60,0x24);
        memcpy(auStack_38,abStack_60,0x14);
        iVar3 = 0x14;
        pbVar2 = param_6;
        do {
          *pbVar2 = pbVar2[(int)(abStack_60 + -(int)param_6)] ^ *pbVar2;
          iVar3 = iVar3 + -1;
          pbVar2 = pbVar2 + 1;
        } while (iVar3 != 0);
        iVar4 = iVar4 + -1;
      } while (iVar4 != 0);
    }
  }
  FUN_40322590(local_24);
  return;
}



/* 40321204 FUN_40321204 */

/* Boundary evidence: original MIPS .pdata 40321204..40321277. Semantic name remains unreviewed. */

undefined4 FUN_40321204(SIZE_T *param_1,SIZE_T *param_2)

{
  HLOCAL _Dst;
  
  if (*param_2 == 0) {
    param_1[1] = 0;
    *param_1 = 0;
  }
  else {
    _Dst = LocalAlloc(0x40,*param_2);
    param_1[1] = (SIZE_T)_Dst;
    if (_Dst == (HLOCAL)0x0) {
      return 0;
    }
    memcpy(_Dst,(void *)param_2[1],*param_2);
    *param_1 = *param_2;
  }
  return 1;
}



/* 40321278 FUN_40321278 */

/* Boundary evidence: original MIPS .pdata 40321278..403213c7. Semantic name remains unreviewed. */

undefined4 FUN_40321278(uint *param_1,uint *param_2,uint *param_3)

{
  undefined4 uVar1;
  HLOCAL pvVar2;
  uint *puVar3;
  uint uVar4;
  uint *puVar5;
  uint *puVar6;
  
  if (*param_1 == *param_2) {
    uVar4 = 0;
    if (*param_2 != 0) {
      puVar6 = param_1 + 0x2e;
      puVar5 = param_2 + 0x28;
      do {
        if (*puVar5 != 0) {
          pvVar2 = LocalAlloc(0x40,*puVar5);
          puVar3 = (uint *)(((int)param_1 - (int)param_2) + (int)puVar5);
          puVar3[1] = (uint)pvVar2;
          if (pvVar2 == (HLOCAL)0x0) {
            *param_1 = uVar4;
            uVar1 = 0;
            goto LAB_4032135c;
          }
          *puVar3 = *puVar5;
          memcpy(pvVar2,(void *)puVar5[1],*puVar5);
        }
        if (puVar5[5] != 0) {
          pvVar2 = LocalAlloc(0x40,puVar5[5]);
          *puVar6 = (uint)pvVar2;
          if (pvVar2 == (HLOCAL)0x0) {
            if (param_2[uVar4 * 0x31 + 0x28] != 0) {
              LocalFree((HLOCAL)param_1[uVar4 * 0x31 + 0x29]);
            }
            *param_3 = uVar4;
            *param_1 = uVar4;
            goto LAB_403212b8;
          }
          puVar6[-1] = puVar5[5];
          memcpy(pvVar2,(void *)puVar5[6],puVar5[5]);
        }
        uVar4 = uVar4 + 1;
        puVar6 = puVar6 + 0x31;
        puVar5 = puVar5 + 0x31;
      } while (uVar4 < *param_2);
    }
    uVar1 = 1;
LAB_4032135c:
    *param_3 = uVar4;
  }
  else {
    *param_3 = 0;
LAB_403212b8:
    uVar1 = 0;
  }
  return uVar1;
}



/* 403213c8 FUN_403213c8 */

/* Boundary evidence: original MIPS .pdata 403213c8..40321443. Semantic name remains unreviewed. */

void FUN_403213c8(uint *param_1,uint param_2)

{
  uint *puVar1;
  
  if ((param_2 <= *param_1) && (param_2 != 0)) {
    puVar1 = param_1 + 0x28;
    do {
      if (*puVar1 != 0) {
        LocalFree((HLOCAL)puVar1[1]);
      }
      if (puVar1[5] != 0) {
        LocalFree((HLOCAL)puVar1[6]);
      }
      param_2 = param_2 - 1;
      puVar1 = puVar1 + 0x31;
    } while (param_2 != 0);
  }
  return;
}



/* 40321444 FUN_40321444 */

/* Boundary evidence: original MIPS .pdata 40321444..4032158f. Semantic name remains unreviewed. */

DWORD FUN_40321444(DWORD param_1,LPVOID param_2,DWORD param_3,LPDWORD param_4,int param_5)

{
  HANDLE hDevice;
  int iVar1;
  DWORD DVar2;
  
  DVar2 = 0;
  if (param_4 != (LPDWORD)0x0) {
    *param_4 = 0;
  }
  hDevice = CreateFileW(L"ZCF1:",0xc0000000,0,(LPSECURITY_ATTRIBUTES)0x0,3,0x40000080,
                        (HANDLE)0xffffffff);
  if (hDevice == (HANDLE)0xffffffff) {
    DVar2 = 2;
  }
  else {
    if (param_5 == 1) {
      iVar1 = DeviceIoControl(hDevice,param_1,param_2,param_3,(LPVOID)0x0,0,(LPDWORD)0x0,
                              (LPOVERLAPPED)0x0);
    }
    else {
      iVar1 = DeviceIoControl(hDevice,param_1,(LPVOID)0x0,0,param_2,param_3,param_4,
                              (LPOVERLAPPED)0x0);
    }
    if (iVar1 == 0) {
      DVar2 = GetLastError();
    }
    CloseHandle(hDevice);
  }
  return DVar2;
}



/* 40321590 WZCPassword2Key */

/* Boundary evidence: original MIPS .pdata 40321590..40321647. Semantic name remains unreviewed. */

void WZCPassword2Key(int param_1,char *param_2)

{
  byte abStack_40 [20];
  byte abStack_2c [20];
  uint local_18;
  
                    /* 0x1590  5  WZCPassword2Key */
  local_18 = DAT_4032307c;
  if (*(uint *)(param_1 + 0x10) < 0x21) {
    FUN_4032107c(param_2,(void *)(param_1 + 0x14),*(uint *)(param_1 + 0x10),0x1000,1,abStack_40);
    FUN_4032107c(param_2,(void *)(param_1 + 0x14),*(size_t *)(param_1 + 0x10),0x1000,2,abStack_2c);
    *(undefined4 *)(param_1 + 0x70) = 0x20;
    memcpy((void *)(param_1 + 0x74),abStack_40,0x20);
  }
  FUN_40322590(local_18);
  return;
}



/* 40321648 WZCEnumInterfaces */

/* Boundary evidence: original MIPS .pdata 40321648..4032175f. Semantic name remains unreviewed. */

DWORD WZCEnumInterfaces(undefined4 param_1,undefined4 *param_2)

{
  DWORD DVar1;
  SIZE_T local_30 [2];
  undefined4 local_28;
  SIZE_T local_24;
  HLOCAL local_20;
  
                    /* 0x1648  4  WZCEnumInterfaces */
  local_24 = 0;
  local_20 = (HLOCAL)0x0;
  DVar1 = FUN_40321444(0x120c00,&local_28,0xc,local_30,0x80);
  do {
    if (DVar1 == 0) {
      DVar1 = 0;
LAB_40321700:
      if (DVar1 == 0) {
        *param_2 = local_28;
        param_2[1] = local_20;
      }
      else {
LAB_4032171c:
        *param_2 = 0;
        param_2[1] = 0;
      }
      return DVar1;
    }
    if (local_30[0] == 0) {
      if (local_20 != (HLOCAL)0x0) {
        LocalFree(local_20);
      }
      goto LAB_40321700;
    }
    if (local_20 != (HLOCAL)0x0) {
      LocalFree(local_20);
    }
    local_20 = LocalAlloc(0x40,local_30[0]);
    if (local_20 == (HLOCAL)0x0) {
      DVar1 = 0xe;
      goto LAB_4032171c;
    }
    local_24 = local_30[0];
    DVar1 = FUN_40321444(0x120c00,&local_28,0xc,local_30,0x80);
  } while( true );
}



/* 40321760 FUN_40321760 */

/* Boundary evidence: original MIPS .pdata 40321760..40321ba7. Semantic name remains unreviewed. */

DWORD FUN_40321760(undefined4 param_1,undefined4 param_2,undefined4 *param_3,undefined4 *param_4,
                  int param_5)

{
  HLOCAL pvVar1;
  DWORD DVar2;
  size_t sVar3;
  wchar_t *_Dest;
  int iVar4;
  SIZE_T *pSVar5;
  uint uVar6;
  uint uVar7;
  SIZE_T local_50;
  uint local_4c;
  uint local_48;
  undefined4 *local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  SIZE_T local_34;
  HLOCAL local_30;
  
  uVar6 = 0;
  uVar7 = 0;
  local_4c = 0;
  local_48 = 0;
  local_44 = param_4;
  memset(&local_40,0,0x14);
  local_3c = *param_4;
  local_38 = *param_3;
  local_34 = 0;
  local_30 = (HLOCAL)0x0;
  local_40 = param_2;
  DVar2 = FUN_40321444(0x120c38,&local_40,0x14,&local_50,0x80);
  while (DVar2 != 0) {
    if (local_50 == 0) {
      if (local_30 != (HLOCAL)0x0) {
        LocalFree(local_30);
        local_30 = (HLOCAL)0x0;
      }
      goto LAB_40321874;
    }
    if (local_30 != (HLOCAL)0x0) {
      LocalFree(local_30);
      local_30 = (HLOCAL)0x0;
    }
    local_30 = LocalAlloc(0x40,local_50);
    if (local_30 == (HLOCAL)0x0) {
      DVar2 = 0xe;
      goto LAB_40321b38;
    }
    local_34 = local_50;
    DVar2 = FUN_40321444(0x120c38,&local_40,0x14,&local_50,0x80);
  }
  DVar2 = 0;
LAB_40321874:
  pvVar1 = local_30;
  if (DVar2 == 0) {
    if (local_30 == (HLOCAL)0x0) goto LAB_40321b50;
    param_3[2] = *(undefined4 *)((int)local_30 + 8);
    param_3[3] = *(undefined4 *)((int)local_30 + 0xc);
    param_3[4] = *(undefined4 *)((int)local_30 + 0x10);
    param_3[5] = *(undefined4 *)((int)local_30 + 0x14);
    param_3[6] = *(undefined4 *)((int)local_30 + 0x18);
    param_3[7] = *(undefined4 *)((int)local_30 + 0x1c);
    param_3[8] = *(undefined4 *)((int)local_30 + 0x20);
    param_3[9] = *(undefined4 *)((int)local_30 + 0x24);
    DVar2 = 0xe;
    if (*(wchar_t **)((int)local_30 + 4) == (wchar_t *)0x0) {
      _Dest = (wchar_t *)0x0;
    }
    else {
      sVar3 = wcslen(*(wchar_t **)((int)local_30 + 4));
      _Dest = LocalAlloc(0x40,(sVar3 + 1) * 2);
    }
    param_3[1] = _Dest;
    if (_Dest != (wchar_t *)0x0) {
      wcscpy(_Dest,*(wchar_t **)((int)pvVar1 + 4));
    }
    pSVar5 = param_3 + 10;
    iVar4 = FUN_40321204(pSVar5,(SIZE_T *)((int)pvVar1 + 0x28));
    if ((iVar4 != 0) &&
       (iVar4 = FUN_40321204(param_3 + 0xc,(SIZE_T *)((int)pvVar1 + 0x30)), iVar4 != 0)) {
      iVar4 = FUN_40321204(param_3 + 0xe,(SIZE_T *)((int)pvVar1 + 0x38));
      if (iVar4 != 0) {
        iVar4 = FUN_40321204(param_3 + 0x10,(SIZE_T *)((int)pvVar1 + 0x40));
        if ((iVar4 != 0) &&
           (iVar4 = FUN_40321204(param_3 + 0x12,(SIZE_T *)((int)pvVar1 + 0x48)), iVar4 != 0)) {
          if (param_5 != 0) {
            param_3[0x16] = *(undefined4 *)((int)pvVar1 + 0x58);
            iVar4 = FUN_40321204(param_3 + 0x17,(SIZE_T *)((int)pvVar1 + 0x5c));
            if ((iVar4 == 0) ||
               (iVar4 = FUN_40321204(param_3 + 0x19,(SIZE_T *)((int)pvVar1 + 100)), iVar4 == 0))
            goto LAB_40321a2c;
            param_3[0x1b] = *(undefined4 *)((int)pvVar1 + 0x6c);
          }
          if (((*(SIZE_T *)((int)pvVar1 + 0x38) == 0) ||
              (iVar4 = FUN_40321278((uint *)param_3[0xf],*(uint **)((int)pvVar1 + 0x3c),&local_4c),
              uVar6 = local_4c, iVar4 != 0)) &&
             ((*(SIZE_T *)((int)pvVar1 + 0x40) == 0 ||
              (iVar4 = FUN_40321278((uint *)param_3[0x11],*(uint **)((int)pvVar1 + 0x44),&local_48),
              uVar7 = local_48, iVar4 != 0)))) {
            DVar2 = 0;
            *local_44 = local_3c;
            goto LAB_40321b38;
          }
        }
      }
    }
LAB_40321a2c:
    if ((HLOCAL)param_3[1] != (HLOCAL)0x0) {
      LocalFree((HLOCAL)param_3[1]);
    }
    if (uVar6 != 0) {
      FUN_403213c8((uint *)param_3[0xf],uVar6);
    }
    if (uVar7 != 0) {
      FUN_403213c8((uint *)param_3[0x11],uVar7);
    }
    if (*pSVar5 != 0) {
      LocalFree((HLOCAL)param_3[0xb]);
      param_3[0xb] = 0;
      *pSVar5 = 0;
    }
    if (param_3[0xc] != 0) {
      LocalFree((HLOCAL)param_3[0xd]);
      param_3[0xd] = 0;
      param_3[0xc] = 0;
    }
    if (param_3[0xe] != 0) {
      LocalFree((HLOCAL)param_3[0xf]);
      param_3[0xf] = 0;
      param_3[0xe] = 0;
    }
    if (param_3[0x10] != 0) {
      LocalFree((HLOCAL)param_3[0x11]);
      param_3[0x11] = 0;
      param_3[0x10] = 0;
    }
    if (param_3[0x12] != 0) {
      LocalFree((HLOCAL)param_3[0x13]);
      param_3[0x13] = 0;
      param_3[0x12] = 0;
    }
    if (param_5 != 0) {
      if (param_3[0x17] != 0) {
        LocalFree((HLOCAL)param_3[0x18]);
        param_3[0x18] = 0;
        param_3[0x17] = 0;
      }
      if (param_3[0x19] != 0) {
        LocalFree((HLOCAL)param_3[0x1a]);
        param_3[0x1a] = 0;
        param_3[0x19] = 0;
      }
    }
  }
LAB_40321b38:
  if (local_30 != (HLOCAL)0x0) {
    LocalFree(local_30);
  }
  if (DVar2 != 0) {
    param_3[0x14] = 0;
    return DVar2;
  }
LAB_40321b50:
  param_3[0x14] = 1;
  return 0;
}



/* 40321ba8 WZCQueryInterface */

/* Boundary evidence: original MIPS .pdata 40321ba8..40321bc3. Semantic name remains unreviewed. */

void WZCQueryInterface(undefined4 param_1,undefined4 param_2,undefined4 *param_3,undefined4 *param_4
                      )

{
                    /* 0x1ba8  7  WZCQueryInterface */
  FUN_40321760(param_1,param_2,param_3,param_4,0);
  return;
}



/* 40321bc4 WZCQueryInterfaceEx */

/* Boundary evidence: original MIPS .pdata 40321bc4..40321be3. Semantic name remains unreviewed. */

void WZCQueryInterfaceEx(undefined4 param_1,undefined4 param_2,undefined4 *param_3,
                        undefined4 *param_4)

{
                    /* 0x1bc4  8  WZCQueryInterfaceEx */
  FUN_40321760(param_1,param_2,param_3,param_4,1);
  return;
}



/* 40321be4 FUN_40321be4 */

/* Boundary evidence: original MIPS .pdata 40321be4..40321d2f. Semantic name remains unreviewed. */

void FUN_40321be4(int param_1,int param_2)

{
  if (*(int *)(param_1 + 0x50) != 0) {
    if (*(HLOCAL *)(param_1 + 4) != (HLOCAL)0x0) {
      LocalFree(*(HLOCAL *)(param_1 + 4));
      *(undefined4 *)(param_1 + 4) = 0;
    }
    if (*(int *)(param_1 + 0x38) != 0) {
      FUN_403213c8(*(uint **)(param_1 + 0x3c),**(uint **)(param_1 + 0x3c));
    }
    if (*(int *)(param_1 + 0x40) != 0) {
      FUN_403213c8(*(uint **)(param_1 + 0x44),**(uint **)(param_1 + 0x44));
    }
    if (*(int *)(param_1 + 0x28) != 0) {
      LocalFree(*(HLOCAL *)(param_1 + 0x2c));
      *(undefined4 *)(param_1 + 0x2c) = 0;
      *(undefined4 *)(param_1 + 0x28) = 0;
    }
    if (*(int *)(param_1 + 0x30) != 0) {
      LocalFree(*(HLOCAL *)(param_1 + 0x34));
      *(undefined4 *)(param_1 + 0x34) = 0;
      *(undefined4 *)(param_1 + 0x30) = 0;
    }
    if (*(int *)(param_1 + 0x38) != 0) {
      LocalFree(*(HLOCAL *)(param_1 + 0x3c));
      *(undefined4 *)(param_1 + 0x3c) = 0;
      *(undefined4 *)(param_1 + 0x38) = 0;
    }
    if (*(int *)(param_1 + 0x40) != 0) {
      LocalFree(*(HLOCAL *)(param_1 + 0x44));
      *(undefined4 *)(param_1 + 0x44) = 0;
      *(undefined4 *)(param_1 + 0x40) = 0;
    }
    if (*(int *)(param_1 + 0x48) != 0) {
      LocalFree(*(HLOCAL *)(param_1 + 0x4c));
      *(undefined4 *)(param_1 + 0x4c) = 0;
      *(undefined4 *)(param_1 + 0x48) = 0;
    }
    if (param_2 != 0) {
      if (*(int *)(param_1 + 0x5c) != 0) {
        LocalFree(*(HLOCAL *)(param_1 + 0x60));
        *(undefined4 *)(param_1 + 0x60) = 0;
        *(undefined4 *)(param_1 + 0x5c) = 0;
      }
      if (*(int *)(param_1 + 100) != 0) {
        LocalFree(*(HLOCAL *)(param_1 + 0x68));
        *(undefined4 *)(param_1 + 0x68) = 0;
        *(undefined4 *)(param_1 + 100) = 0;
      }
    }
    *(undefined4 *)(param_1 + 0x50) = 0;
  }
  return;
}



/* 40321d30 WZCDeleteIntfObj */

/* Boundary evidence: original MIPS .pdata 40321d30..40321d4b. Semantic name remains unreviewed. */

void WZCDeleteIntfObj(int param_1)

{
                    /* 0x1d30  1  WZCDeleteIntfObj */
  FUN_40321be4(param_1,0);
  return;
}



/* 40321d4c WZCDeleteIntfObjEx */

/* Boundary evidence: original MIPS .pdata 40321d4c..40321d67. Semantic name remains unreviewed. */

void WZCDeleteIntfObjEx(int param_1)

{
                    /* 0x1d4c  2  WZCDeleteIntfObjEx */
  FUN_40321be4(param_1,1);
  return;
}



/* 40321d68 FUN_40321d68 */

/* Boundary evidence: original MIPS .pdata 40321d68..40321deb. Semantic name remains unreviewed. */

void FUN_40321d68(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4,
                 int param_5)

{
  DWORD DVar1;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  
  if (param_4 == (undefined4 *)0x0) {
    local_14 = 0;
  }
  else {
    local_14 = *param_4;
  }
  if (param_5 == 0) {
    DVar1 = 0x120c08;
  }
  else {
    DVar1 = 0x120c3c;
  }
  local_18 = param_2;
  local_10 = param_3;
  DVar1 = FUN_40321444(DVar1,&local_18,0xc,(LPDWORD)0x0,1);
  if ((DVar1 == 0) && (param_4 != (undefined4 *)0x0)) {
    *param_4 = local_14;
  }
  return;
}



/* 40321dec WZCSetInterface */

/* Boundary evidence: original MIPS .pdata 40321dec..40321e07. Semantic name remains unreviewed. */

void WZCSetInterface(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4)

{
                    /* 0x1dec  12  WZCSetInterface */
  FUN_40321d68(param_1,param_2,param_3,param_4,0);
  return;
}



/* 40321e08 WZCSetInterfaceEx */

/* Boundary evidence: original MIPS .pdata 40321e08..40321e27. Semantic name remains unreviewed. */

void WZCSetInterfaceEx(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4)

{
                    /* 0x1e08  13  WZCSetInterfaceEx */
  FUN_40321d68(param_1,param_2,param_3,param_4,1);
  return;
}



/* 40321e28 WZCRefreshInterface */

/* Boundary evidence: original MIPS .pdata 40321e28..40321e87. Semantic name remains unreviewed. */

void WZCRefreshInterface(undefined4 param_1,undefined4 param_2,undefined4 param_3,
                        undefined4 *param_4)

{
  DWORD DVar1;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  
                    /* 0x1e28  9  WZCRefreshInterface */
  local_14 = *param_4;
  local_18 = param_2;
  local_10 = param_3;
  DVar1 = FUN_40321444(0x120c0c,&local_18,0xc,(LPDWORD)0x0,1);
  if (DVar1 == 0) {
    *param_4 = local_14;
  }
  return;
}



/* 40321e88 WZCRefreshInterfaceEx */

/* Boundary evidence: original MIPS .pdata 40321e88..40321ea3. Semantic name remains unreviewed. */

void WZCRefreshInterfaceEx
               (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4)

{
                    /* 0x1e88  10  WZCRefreshInterfaceEx */
  WZCRefreshInterface(param_1,param_2,param_3,param_4);
  return;
}



/* 40321ea4 WZCEnumEapExtensions */

/* Boundary evidence: original MIPS .pdata 40321ea4..4032204b. Semantic name remains unreviewed. */

DWORD WZCEnumEapExtensions(uint *param_1,undefined4 *param_2)

{
  DWORD DVar1;
  int *_Dst;
  int *piVar2;
  uint uVar3;
  int *piVar4;
  int iVar5;
  SIZE_T local_38 [2];
  int local_30 [4];
  int *local_20;
  
                    /* 0x1ea4  3  WZCEnumEapExtensions */
  if ((param_1 == (uint *)0x0) || (param_2 == (undefined4 *)0x0)) {
    DVar1 = 0x57;
  }
  else {
    local_30[3] = 0;
    local_20 = (int *)0x0;
    DVar1 = FUN_40321444(0x120c10,local_30 + 2,0xc,local_38,0x80);
    while (DVar1 != 0) {
      if (local_38[0] == 0) {
        LocalFree(local_20);
        goto LAB_40321f60;
      }
      LocalFree(local_20);
      local_20 = LocalAlloc(0x40,local_38[0]);
      if (local_20 == (int *)0x0) {
        DVar1 = 0xe;
        goto LAB_40321fc8;
      }
      local_30[3] = local_38[0];
      DVar1 = FUN_40321444(0x120c10,local_30 + 2,0xc,local_38,0x80);
    }
    DVar1 = 0;
LAB_40321f60:
    if ((DVar1 == 0) && (local_20 != (int *)0x0)) {
      local_30[0] = 0x1a;
      piVar4 = local_30;
      local_30[1] = 4;
      iVar5 = 2;
      piVar2 = local_20;
      do {
        uVar3 = 0;
        if (local_30[2] != 0) {
          _Dst = piVar2;
          do {
            if (*_Dst == *piVar4) {
              local_30[2] = local_30[2] - 1;
              memmove(_Dst,_Dst + 0x312,(local_30[2] - uVar3) * 0xc48);
              piVar2 = local_20;
              break;
            }
            uVar3 = uVar3 + 1;
            _Dst = _Dst + 0x312;
          } while (uVar3 < (uint)local_30[2]);
        }
        iVar5 = iVar5 + -1;
        piVar4 = piVar4 + 1;
      } while (iVar5 != 0);
      *param_1 = local_30[2];
      *param_2 = piVar2;
    }
    else {
LAB_40321fc8:
      *param_1 = 0;
      *param_2 = 0;
    }
  }
  return DVar1;
}



/* 4032204c WZCQueryContext */

/* Boundary evidence: original MIPS .pdata 4032204c..40322083. Semantic name remains unreviewed. */

void WZCQueryContext(undefined4 param_1,undefined4 param_2,LPVOID param_3)

{
  DWORD local_10 [2];
  
                    /* 0x204c  6  WZCQueryContext */
  local_10[0] = 0;
  FUN_40321444(0x120c28,param_3,0x14,local_10,0x80);
  return;
}



/* 40322084 WZCSetContext */

/* Boundary evidence: original MIPS .pdata 40322084..403220b7. Semantic name remains unreviewed. */

void WZCSetContext(undefined4 param_1,undefined4 param_2,LPVOID param_3)

{
                    /* 0x2084  11  WZCSetContext */
  FUN_40321444(0x120c2c,param_3,0x14,(LPDWORD)0x0,1);
  return;
}



/* 403220b8 WzcPortIndication */

/* Boundary evidence: original MIPS .pdata 403220b8..403220f7. Semantic name remains unreviewed. */

DWORD WzcPortIndication(undefined4 param_1,LPVOID param_2)

{
  DWORD DVar1;
  
                    /* 0x20b8  14  WzcPortIndication */
  if (param_2 == (LPVOID)0x0) {
    DVar1 = 0x57;
  }
  else {
    DVar1 = FUN_40321444(0x120c34,param_2,0x1c,(LPDWORD)0x0,1);
  }
  return DVar1;
}



/* 403220f8 FUN_403220f8 */

/* Boundary evidence: original MIPS .pdata 403220f8..4032212b. Semantic name remains unreviewed. */

undefined4 FUN_403220f8(HMODULE param_1,int param_2)

{
  if (param_2 == 1) {
    DisableThreadLibraryCalls(param_1);
  }
  return 1;
}



/* 4032212c FUN_4032212c */

/* Boundary evidence: original MIPS .pdata 4032212c..40322357. Semantic name remains unreviewed. */

void FUN_4032212c(undefined4 param_1,undefined4 param_2,void *param_3,uint param_4,
                 undefined1 *param_5,uint param_6)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint *puVar5;
  undefined1 *puVar6;
  undefined1 *_Src;
  int iVar7;
  uint local_180 [16];
  uint local_140 [16];
  undefined1 local_100 [96];
  undefined1 auStack_a0 [96];
  undefined1 auStack_40 [20];
  uint local_2c;
  
  local_2c = DAT_4032307c;
  _Src = auStack_40;
  if (0x13 < param_6) {
    _Src = param_5;
  }
  if (0x40 < param_4) {
    A_SHAInit(auStack_a0);
    A_SHAUpdate(auStack_a0,param_3,param_4);
    A_SHAFinal(auStack_a0,param_3);
    param_4 = 0x14;
  }
  iVar7 = 0x40;
  memset(local_140,0,0x40);
  memset(local_180,0,0x40);
  memcpy(local_140,param_3,param_4);
  memcpy(local_180,param_3,param_4);
  uVar1 = 0;
  do {
    uVar4 = *(uint *)((int)local_180 + uVar1 + 4);
    *(uint *)((int)local_140 + uVar1 + 4) = *(uint *)((int)local_140 + uVar1 + 4) ^ 0x36363636;
    *(uint *)((int)local_140 + uVar1) = *(uint *)((int)local_140 + uVar1) ^ 0x36363636;
    uVar2 = uVar1 + 8;
    *(uint *)((int)local_180 + uVar1 + 4) = uVar4 ^ 0x5c5c5c5c;
    *(uint *)((int)local_180 + uVar1) = *(uint *)((int)local_180 + uVar1) ^ 0x5c5c5c5c;
    uVar1 = uVar2;
  } while (uVar2 < 0x40);
  A_SHAInit(local_100);
  A_SHAUpdate(local_100,local_140,0x40);
  A_SHAUpdate(local_100,param_1,param_2);
  A_SHAFinal(local_100,_Src);
  A_SHAInit(local_100);
  A_SHAUpdate(local_100,local_180,0x40);
  A_SHAUpdate(local_100,_Src,0x14);
  A_SHAFinal(local_100,_Src);
  iVar3 = 0x40;
  puVar5 = local_140;
  do {
    *(undefined1 *)puVar5 = 0;
    iVar3 = iVar3 + -1;
    puVar5 = (uint *)((int)puVar5 + 1);
  } while (iVar3 != 0);
  puVar5 = local_180;
  do {
    *(undefined1 *)puVar5 = 0;
    iVar7 = iVar7 + -1;
    puVar5 = (uint *)((int)puVar5 + 1);
  } while (iVar7 != 0);
  iVar7 = 0x5c;
  puVar6 = local_100;
  do {
    *puVar6 = 0;
    iVar7 = iVar7 + -1;
    puVar6 = puVar6 + 1;
  } while (iVar7 != 0);
  if (_Src != param_5) {
    memcpy(param_5,_Src,param_6);
  }
  FUN_40322590(local_2c);
  return;
}



/* 40322358 FUN_40322358 */

/* Boundary evidence: original MIPS .pdata 40322358..403223b7. Semantic name remains unreviewed. */

undefined * FUN_40322358(void)

{
  if ((DAT_40323098 & 1) == 0) {
    DAT_40323098 = DAT_40323098 | 1;
    InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_40323084);
    FUN_4032281c(FUN_40322b5c);
  }
  return &DAT_40323084;
}



/* 40322428 entry */

/* Boundary evidence: original MIPS .pdata 40322428..4032249b. Semantic name remains unreviewed. */

undefined4 entry(HMODULE param_1,int param_2)

{
  undefined4 uVar1;
  
  if (param_2 == 1) {
    FUN_4032249c();
    FUN_403229e4();
  }
  uVar1 = FUN_403220f8(param_1,param_2);
  if (param_2 == 0) {
    FUN_4032296c();
  }
  return uVar1;
}



/* 4032249c FUN_4032249c */

/* Boundary evidence: original MIPS .pdata 4032249c..4032250f. Semantic name remains unreviewed. */

void FUN_4032249c(void)

{
  uint uVar1;
  
  if ((DAT_4032307c == 0) || (DAT_4032307c == 0xb064)) {
    uVar1 = __security_gen_cookie2();
    DAT_4032307c = uVar1 >> 0x10 ^ uVar1 & 0xffff;
    if (DAT_4032307c == 0) {
      DAT_4032307c = 0xb064;
    }
  }
  DAT_40323080 = ~DAT_4032307c;
  return;
}



/* 40322510 FUN_40322510 */

/* Boundary evidence: original MIPS .pdata 40322510..40322563. Semantic name remains unreviewed. */

void FUN_40322510(int param_1,undefined4 param_2,uint *param_3)

{
  if ((*param_3 & 1) != 0) {
    param_1 = ((-param_3[2] & param_3[1] + param_1) - (param_3[1] + param_1)) + param_1;
  }
  FUN_40322590(*(uint *)(param_1 + (*param_3 & 0xfffffffc)));
  return;
}



/* 40322564 FUN_40322564 */

/* Boundary evidence: original MIPS .pdata 40322564..4032258f. Semantic name remains unreviewed. */

undefined4 FUN_40322564(undefined4 param_1,int param_2,undefined4 param_3,int param_4)

{
  FUN_40322510(param_2,param_4,*(uint **)(*(int *)(param_4 + 4) + 0xc));
  return 1;
}



/* 40322590 FUN_40322590 */

/* Boundary evidence: original MIPS .pdata 40322590..403225d7. Semantic name remains unreviewed. */

void FUN_40322590(uint param_1)

{
  if ((param_1 == DAT_4032307c) && (param_1 >> 0x10 == 0)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __report_gsfailure();
}



/* 403225d8 FUN_403225d8 */

/* Boundary evidence: original MIPS .pdata 403225d8..403226e3. Semantic name remains unreviewed. */

undefined4 FUN_403225d8(undefined4 param_1)

{
  void *_Memory;
  uint uVar1;
  void *pvVar2;
  uint _NewSize;
  undefined4 *puVar3;
  int iVar4;
  
  _Memory = DAT_403230a4;
  puVar3 = DAT_403230a0;
  iVar4 = (int)DAT_403230a0 - (int)DAT_403230a4;
  uVar1 = 0;
  if (iVar4 < 0) {
LAB_4032261c:
    param_1 = 0;
  }
  else {
    if (DAT_403230a4 != (void *)0x0) {
      uVar1 = _msize(DAT_403230a4);
    }
    pvVar2 = _Memory;
    if (uVar1 < iVar4 + 4U) {
      if (_Memory == (void *)0x0) {
        pvVar2 = malloc(0x10);
LAB_40322690:
        if (pvVar2 == (void *)0x0) goto LAB_4032261c;
      }
      else {
        _NewSize = uVar1 << 1;
        if (0x200 < uVar1) {
          _NewSize = uVar1 + 0x200;
        }
        if ((_NewSize <= uVar1) || (pvVar2 = realloc(_Memory,_NewSize), pvVar2 == (void *)0x0)) {
          pvVar2 = realloc(_Memory,iVar4 + 4U);
          goto LAB_40322690;
        }
      }
      puVar3 = (undefined4 *)((iVar4 >> 2) * 4 + (int)pvVar2);
    }
    DAT_403230a0 = puVar3 + 1;
    *puVar3 = param_1;
    DAT_403230a4 = pvVar2;
  }
  return param_1;
}



/* 403226e4 FUN_403226e4 */

/* Boundary evidence: original MIPS .pdata 403226e4..403227cf. Semantic name remains unreviewed. */

undefined4 FUN_403226e4(undefined4 param_1)

{
  LPCRITICAL_SECTION lpCriticalSection;
  LONG LVar1;
  undefined4 uVar2;
  
  if (DAT_403230a8 == (LPCRITICAL_SECTION)0x0) {
    lpCriticalSection = malloc(0x14);
    if (lpCriticalSection != (LPCRITICAL_SECTION)0x0) {
      InitializeCriticalSection(lpCriticalSection);
      LVar1 = InterlockedCompareExchange((LONG *)&DAT_403230a8,(LONG)lpCriticalSection,0);
      if (LVar1 != 0) {
        DeleteCriticalSection(lpCriticalSection);
        free(lpCriticalSection);
      }
    }
    if (DAT_403230a8 == (LPCRITICAL_SECTION)0x0) goto LAB_40322788;
  }
  EnterCriticalSection(DAT_403230a8);
LAB_40322788:
  uVar2 = FUN_403225d8(param_1);
  FUN_403227d0();
  return uVar2;
}



/* 403227d0 FUN_403227d0 */

/* Boundary evidence: original MIPS .pdata 403227d0..4032281b. Semantic name remains unreviewed. */

void FUN_403227d0(void)

{
  if (DAT_403230a8 != (LPCRITICAL_SECTION)0x0) {
    LeaveCriticalSection(DAT_403230a8);
  }
  return;
}



/* 4032281c FUN_4032281c */

/* Boundary evidence: original MIPS .pdata 4032281c..4032284b. Semantic name remains unreviewed. */

undefined4 FUN_4032281c(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_403226e4(param_1);
  if (iVar1 == 0) {
    uVar2 = 0xffffffff;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}



/* 4032284c FUN_4032284c */

/* Boundary evidence: original MIPS .pdata 4032284c..4032296b. Semantic name remains unreviewed. */

void FUN_4032284c(UINT param_1,int param_2,int param_3)

{
  LPCRITICAL_SECTION lpCriticalSection;
  undefined4 *_Memory;
  
  DAT_4032309d = (undefined1)param_3;
  if (param_2 == 0) {
    _Memory = DAT_403230a4;
    if (DAT_403230a4 != (undefined4 *)0x0) {
      while (DAT_403230a0 = DAT_403230a0 + -1, _Memory <= DAT_403230a0) {
        if ((code *)*DAT_403230a0 != (code *)0x0) {
          (*(code *)*DAT_403230a0)();
          _Memory = DAT_403230a4;
        }
      }
      free(_Memory);
      DAT_403230a0 = (undefined4 *)0x0;
      DAT_403230a4 = (undefined4 *)0x0;
    }
    FUN_40322990((undefined4 *)&DAT_40321014,(undefined4 *)&DAT_40321018);
  }
  FUN_40322990((undefined4 *)&DAT_4032101c,(undefined4 *)&DAT_40321020);
  if (param_3 == 0) {
    TerminateProcess((HANDLE)0x42,param_1);
  }
  else {
    lpCriticalSection = (LPCRITICAL_SECTION)InterlockedExchange(&DAT_403230a8,0);
    if (lpCriticalSection != (LPCRITICAL_SECTION)0x0) {
      DeleteCriticalSection(lpCriticalSection);
      free(lpCriticalSection);
    }
  }
  return;
}



/* 4032296c FUN_4032296c */

/* Boundary evidence: original MIPS .pdata 4032296c..4032298f. Semantic name remains unreviewed. */

void FUN_4032296c(void)

{
  FUN_4032284c(0,0,1);
  return;
}



/* 40322990 FUN_40322990 */

/* Boundary evidence: original MIPS .pdata 40322990..403229e3. Semantic name remains unreviewed. */

void FUN_40322990(undefined4 *param_1,undefined4 *param_2)

{
  for (; param_1 < param_2; param_1 = param_1 + 1) {
    if ((code *)*param_1 != (code *)0x0) {
      (*(code *)*param_1)();
    }
  }
  return;
}



/* 403229e4 FUN_403229e4 */

/* Boundary evidence: original MIPS .pdata 403229e4..40322a1f. Semantic name remains unreviewed. */

void FUN_403229e4(void)

{
  FUN_40322990((undefined4 *)&DAT_4032100c,(undefined4 *)&DAT_40321010);
  FUN_40322990((undefined4 *)&DAT_40321000,(undefined4 *)&DAT_40321008);
  return;
}



/* 40322b40 FUN_40322b40 */

/* Boundary evidence: original MIPS .pdata 40322b40..40322b5b. Semantic name remains unreviewed. */

void FUN_40322b40(void)

{
  FUN_40322358();
  return;
}



/* 40322b5c FUN_40322b5c */

/* Boundary evidence: original MIPS .pdata 40322b5c..40322b7b. Semantic name remains unreviewed. */

void FUN_40322b5c(void)

{
  DeleteCriticalSection((LPCRITICAL_SECTION)&DAT_40323084);
  return;
}


