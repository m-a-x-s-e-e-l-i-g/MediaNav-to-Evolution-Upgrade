/* Automatic Ghidra pseudocode. Not original source; not runtime-verified. */

/* c03e10c0 FUN_c03e10c0 */

/* Boundary evidence: original MIPS .pdata c03e10c0..c03e11df. Semantic name remains unreviewed. */

undefined4 FUN_c03e10c0(int param_1)

{
  BOOL BVar1;
  int *lpInBuffer;
  DWORD aDStack_28 [2];
  
  lpInBuffer = (int *)(param_1 + 0x28);
  BVar1 = DeviceIoControl(*(HANDLE *)(param_1 + 0x18),0x71c00,lpInBuffer,0x18,lpInBuffer,0x18,
                          aDStack_28,(LPOVERLAPPED)0x0);
  if ((((BVar1 != 0) ||
       (BVar1 = DeviceIoControl(*(HANDLE *)(param_1 + 0x18),1,lpInBuffer,0x18,lpInBuffer,0x18,
                                aDStack_28,(LPOVERLAPPED)0x0), BVar1 != 0)) &&
      (*(int *)(param_1 + 0x2c) != 0)) && (*lpInBuffer != 0)) {
    if (*(int *)(param_1 + 0x34) == 0) {
      *(undefined4 *)(param_1 + 0x34) = 1;
    }
    if (*(int *)(param_1 + 0x30) == 0) {
      *(undefined4 *)(param_1 + 0x30) = 1;
    }
    if (*(int *)(param_1 + 0x38) == 0) {
      *(int *)(param_1 + 0x38) = *lpInBuffer;
    }
    return 0;
  }
  return 0x1f;
}



/* c03e11e0 PD_OpenStore */

/* Boundary evidence: original MIPS .pdata c03e11e0..c03e142b. Semantic name remains unreviewed. */

int PD_OpenStore(undefined4 param_1,undefined4 *param_2)

{
  HLOCAL hMem;
  undefined4 uVar1;
  int iVar2;
  DWORD DVar3;
  wchar_t *pwVar4;
  char *local_30;
  int local_2c;
  wchar_t local_28 [4];
  uint local_20 [2];
  
                    /* 0x11e0  15  PD_OpenStore */
  local_30 = (char *)0x0;
  *param_2 = 0;
  hMem = LocalAlloc(0x40,0x60);
  if (hMem == (HLOCAL)0x0) {
    return 0xe;
  }
  *(undefined4 *)((int)hMem + 0x18) = param_1;
  uVar1 = FSDMGR_DeviceHandleToHDSK(param_1);
  iVar2 = FUN_c03e10c0((int)hMem);
  if (iVar2 != 0) {
    LocalFree(hMem);
    return iVar2;
  }
  FSDMGR_GetRegistryValue(uVar1,L"PrimaryPart",&local_2c);
  if (local_2c != 0) {
    *(uint *)((int)hMem + 0x24) = *(uint *)((int)hMem + 0x24) | 1;
  }
  FSDMGR_GetRegistryValue(uVar1,L"AlignCylinder",&local_2c);
  if (local_2c != 0) {
    *(uint *)((int)hMem + 0x24) = *(uint *)((int)hMem + 0x24) | 2;
  }
  pwVar4 = L"SkipSector1";
  FSDMGR_GetRegistryValue(uVar1,L"SkipSector1",&local_2c);
  if (local_2c != 0) {
    *(uint *)((int)hMem + 0x24) = *(uint *)((int)hMem + 0x24) | 4;
  }
  *(undefined4 *)((int)hMem + 0x40) = 0;
  *(undefined4 *)((int)hMem + 0x44) = 0;
  *(undefined4 *)((int)hMem + 0x1c) = 0;
  iVar2 = FUN_c03e3088((int)hMem,pwVar4,0,0,1,0,(int *)&local_30);
  if (iVar2 == 0) {
    iVar2 = 0;
    if ((*(uint *)((int)hMem + 0x3c) & 4) != 0) goto LAB_c03e13f8;
LAB_c03e1328:
    iVar2 = 0x1e;
  }
  else {
    pwVar4 = local_28;
    local_28[0] = L'\0';
    local_28[1] = L'\0';
    local_20[0] = 0;
    local_20[1] = 0;
    DVar3 = FUN_c03e3ebc((int)hMem,(int *)pwVar4,(int)local_30,0,local_20,0);
    if (DVar3 == 0) {
      *(undefined4 *)((int)hMem + 0x1c) = 1;
      FUN_c03e42c4((int)hMem,pwVar4);
    }
    else {
      if ((*(short *)(local_30 + 0x1fe) == -0x55ab) &&
         ((*local_30 == -0x15 || (*local_30 == -0x17)))) {
        iVar2 = 0x453;
        goto LAB_c03e13f8;
      }
      if (DVar3 != 0xd) goto LAB_c03e1328;
      iVar2 = 0;
      if ((((*(uint *)((int)hMem + 0x24) & 1) == 0) || (*(short *)(local_30 + 0x1fe) != -0x55ab)) ||
         ((*local_30 != -0x15 && (*local_30 != -0x17)))) goto LAB_c03e13f8;
      *(undefined4 *)((int)hMem + 0x1c) = 1;
    }
    iVar2 = 0;
  }
LAB_c03e13f8:
  if (local_30 != (char *)0x0) {
    LocalFree(local_30);
  }
  *param_2 = hMem;
  return iVar2;
}



/* c03e142c PD_GetStoreInfo */

/* Boundary evidence: original MIPS .pdata c03e142c..c03e14f7. Semantic name remains unreviewed. */

undefined4 PD_GetStoreInfo(int *param_1,int *param_2)

{
  undefined4 uVar1;
  int iVar2;
  
                    /* 0x142c  12  PD_GetStoreInfo */
  if (*param_2 == 0x40) {
    memset(param_2,0,0x40);
    *param_2 = 0x40;
    param_2[10] = *param_1;
    param_2[0xb] = param_1[1];
    param_2[0xc] = param_1[2];
    param_2[0xd] = param_1[3];
    param_2[4] = param_1[0xb];
    param_2[2] = param_1[10];
    param_2[3] = 0;
    iVar2 = FUN_c03e4590((int)param_1,(uint *)(param_2 + 6),(uint *)(param_2 + 8));
    if (iVar2 == 0) {
      uVar1 = 0x1f;
    }
    else {
      if (param_1[7] == 0) {
        param_2[0xe] = param_2[0xe] | 4;
      }
      uVar1 = 0;
    }
  }
  else {
    uVar1 = 0x57;
  }
  return uVar1;
}



/* c03e14f8 PD_CloseStore */

/* Boundary evidence: original MIPS .pdata c03e14f8..c03e1527. Semantic name remains unreviewed. */

void PD_CloseStore(HLOCAL param_1)

{
                    /* 0x14f8  2  PD_CloseStore */
  FUN_c03e2d9c((int)param_1);
  LocalFree(param_1);
  return;
}



/* c03e1528 PD_FormatStore */

/* Boundary evidence: original MIPS .pdata c03e1528..c03e178b. Semantic name remains unreviewed. */

DWORD PD_FormatStore(uint param_1)

{
  BOOL BVar1;
  DWORD DVar2;
  DWORD DVar3;
  undefined1 *hMem;
  undefined1 *puVar4;
  uint uVar5;
  uint uVar6;
  undefined1 *uBytes;
  uint *lpInBuffer;
  DWORD aDStack_20 [2];
  
                    /* 0x1528  10  PD_FormatStore */
  lpInBuffer = (uint *)(param_1 + 0x28);
  BVar1 = DeviceIoControl(*(HANDLE *)(param_1 + 0x18),0x79c14,lpInBuffer,0x18,(LPVOID)0x0,0,
                          aDStack_20,(LPOVERLAPPED)0x0);
  if ((BVar1 == 0) &&
     (BVar1 = DeviceIoControl(*(HANDLE *)(param_1 + 0x18),6,lpInBuffer,0x18,(LPVOID)0x0,0,aDStack_20
                              ,(LPOVERLAPPED)0x0), BVar1 == 0)) {
    DVar2 = GetLastError();
    DVar3 = DVar2;
  }
  else {
    DVar3 = FUN_c03e10c0(param_1);
    if (DVar3 != 0) {
      return DVar3;
    }
    if (0x1fffffff < *(uint *)(param_1 + 0x2c)) {
      return 0x10db;
    }
    uBytes = (undefined1 *)(*(uint *)(param_1 + 0x2c) << 3);
    puVar4 = uBytes;
    hMem = LocalAlloc(0x40,(SIZE_T)uBytes);
    if (hMem == (undefined1 *)0x0) {
      return 0xe;
    }
    if ((*(uint *)(param_1 + 0x24) & 1) != 0) {
      puVar4 = (undefined1 *)0x0;
      *(undefined2 *)(hMem + 0x1fe) = 0xaa55;
      *hMem = 0xe9;
      hMem[1] = 0xfd;
      hMem[2] = 0xff;
      memset(hMem + 0x1be,0,0x40);
    }
    if (*(uint *)(param_1 + 0x2c) == 0) {
      trap(0x1c00);
    }
    DVar3 = FUN_c03e2fb8(param_1,puVar4,0,0,(uint)uBytes / *(uint *)(param_1 + 0x2c),0,hMem);
    LocalFree(hMem);
    if (DVar3 == 0) {
      return 0x1d;
    }
    if (*(int *)(param_1 + 0x1c) != 0) {
      FUN_c03e2d9c(param_1);
    }
    *(undefined4 *)(param_1 + 0x14) = 0;
    if ((*(uint *)(param_1 + 0x24) & 1) == 0) {
      *(undefined4 *)(param_1 + 0x54) = 0;
      if (*(uint *)(param_1 + 0x34) < 2) {
        *(undefined4 *)(param_1 + 0x50) = 1;
      }
      else {
        *(uint *)(param_1 + 0x50) = *(int *)(param_1 + 0x38) * *(uint *)(param_1 + 0x34);
      }
      uVar6 = *lpInBuffer;
      uVar5 = *(uint *)(param_1 + 0x50);
      *(uint *)(param_1 + 0x58) = uVar6 - 1;
      *(undefined4 *)(param_1 + 0x5c) = 0;
      DVar3 = FUN_c03e534c(param_1,puVar4,uVar5,*(int *)(param_1 + 0x54),uVar6 - uVar5,
                           -(uint)(uVar6 < uVar5) - *(int *)(param_1 + 0x54),5,1);
      if (DVar3 == 0) {
        return 0x1d;
      }
    }
    *(undefined4 *)(param_1 + 0x1c) = 1;
    DVar2 = 0;
  }
  if (DVar3 == 0) {
    DVar2 = 0x1f;
  }
  return DVar2;
}



/* c03e178c PD_IsStoreFormatted */

undefined4 PD_IsStoreFormatted(int param_1)

{
  undefined4 uVar1;
  
                    /* 0x178c  13  PD_IsStoreFormatted */
  uVar1 = 0;
  if (*(int *)(param_1 + 0x1c) == 0) {
    uVar1 = 0xb;
  }
  return uVar1;
}



/* c03e17a4 PD_CreatePartition */

/* Boundary evidence: original MIPS .pdata c03e17a4..c03e1b7b. Semantic name remains unreviewed. */

undefined4
PD_CreatePartition(uint param_1,wchar_t *param_2,char param_3,undefined4 param_4,uint param_5,
                  int param_6,int param_7)

{
  undefined4 uVar1;
  size_t sVar2;
  int iVar3;
  wchar_t *_Dest;
  int *piVar4;
  wchar_t *pwVar5;
  int iVar6;
  uint uVar7;
  wchar_t *pwVar8;
  uint uVar9;
  int iVar10;
  int iVar11;
  int local_48 [2];
  int local_40;
  int local_3c;
  uint local_38;
  int local_34;
  uint local_30;
  int local_2c;
  
                    /* 0x17a4  3  PD_CreatePartition */
  local_38 = 0;
  local_34 = 0;
  if (*(int *)(param_1 + 0x1c) == 0) {
    uVar1 = 0xb;
  }
  else {
    sVar2 = wcslen(param_2);
    if (sVar2 == 0) {
      uVar1 = 0x7b;
    }
    else if (((param_5 == 0 && param_6 == 0) || (param_6 != 0)) ||
            (*(uint *)(param_1 + 0x28) < param_5)) {
      uVar1 = 0x70;
    }
    else {
      piVar4 = local_48;
      FUN_c03e3e20(param_1,piVar4,(undefined4 *)0x0,param_2);
      if (local_48[0] == 0) {
        if ((*(int *)(param_1 + 0x14) != 0x18) &&
           (iVar3 = FUN_c03e31fc(param_1,piVar4,param_5,0,param_3,local_48,&local_38,&local_30,
                                 (ulonglong *)&local_40), iVar3 != 0)) {
          _Dest = LocalAlloc(0x40,0x80);
          if (_Dest == (wchar_t *)0x0) {
            return 0xe;
          }
          uVar9 = 0;
          iVar3 = 0;
          iVar10 = 0;
          iVar11 = 0;
          if (local_48[0] == 0) {
            iVar6 = *(int *)(param_1 + 0x40);
            if (iVar6 != 0) {
              uVar9 = *(uint *)(iVar6 + 0x68);
              iVar3 = *(int *)(iVar6 + 0x6c);
            }
          }
          else {
            iVar10 = *(int *)(local_48[0] + 0x68);
            iVar6 = *(int *)(local_48[0] + 0x70);
            iVar11 = *(int *)(local_48[0] + 0x6c);
            if (iVar6 != 0) {
              uVar9 = *(uint *)(iVar6 + 0x68);
              iVar3 = *(int *)(iVar6 + 0x6c);
            }
          }
          wcscpy(_Dest,param_2);
          *(uint *)(_Dest + 0x20) = local_38;
          *(int *)(_Dest + 0x22) = local_34;
          if (local_30 == 0 && local_2c == 0) {
            *(int *)(_Dest + 0x24) = local_40;
            *(int *)(_Dest + 0x26) = local_3c;
          }
          else {
            uVar7 = (local_30 - local_38) + local_40;
            *(uint *)(_Dest + 0x24) = uVar7;
            *(uint *)(_Dest + 0x26) =
                 ((local_2c - local_34) - (uint)(local_30 < local_38)) + local_3c +
                 (uint)(uVar7 < local_30 - local_38);
          }
          _Dest[0x38] = L'\0';
          _Dest[0x39] = L'\0';
          *(uint *)(_Dest + 0x3a) = param_1;
          *(uint *)(_Dest + 0x34) = local_30;
          *(int *)(_Dest + 0x36) = local_2c;
          pwVar5 = _Dest;
          iVar6 = FUN_c03e3c14(param_1,(int)_Dest);
          if (iVar6 != 0) {
            if (local_48[0] == 0) {
              if (*(int *)(param_1 + 0x40) != 0) {
                *(int *)(_Dest + 0x38) = *(int *)(param_1 + 0x40);
              }
              *(wchar_t **)(param_1 + 0x40) = _Dest;
            }
            else {
              if (*(int *)(local_48[0] + 0x70) != 0) {
                *(int *)(_Dest + 0x38) = *(int *)(local_48[0] + 0x70);
              }
              *(wchar_t **)(local_48[0] + 0x70) = _Dest;
            }
            pwVar8 = _Dest + 0x3c;
            *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + 1;
            if (param_7 == 0) {
              *(char *)pwVar8 = param_3;
            }
            else {
              FUN_c03e2e00(param_1,pwVar5,*(uint *)(_Dest + 0x24),*(undefined4 *)(_Dest + 0x26),
                           (undefined1 *)pwVar8);
            }
            if (local_30 == 0 && local_2c == 0) {
              iVar3 = FUN_c03e534c(param_1,(undefined1 *)pwVar5,local_38,local_34,local_40,local_3c,
                                   (char)*pwVar8,0);
            }
            else {
              iVar3 = FUN_c03e4acc(param_1,pwVar5,iVar10,iVar11,uVar9,iVar3,local_30,local_2c,
                                   local_40,local_3c,(char)*pwVar8);
            }
            if (iVar3 != 0) {
              if (*(int *)(_Dest + 0x38) != 0) {
                for (iVar3 = *(int *)(param_1 + 0x44); iVar3 != 0; iVar3 = *(int *)(iVar3 + 8)) {
                  if (*(int *)(iVar3 + 4) == *(int *)(_Dest + 0x38)) {
                    *(wchar_t **)(iVar3 + 4) = _Dest;
                  }
                }
              }
              return 0;
            }
            if (local_48[0] == 0) {
              *(undefined4 *)(param_1 + 0x40) = 0;
            }
            else {
              *(undefined4 *)(local_48[0] + 0x70) = *(undefined4 *)(_Dest + 0x38);
            }
            *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + -1;
          }
          LocalFree(_Dest);
        }
        uVar1 = 0x451;
      }
      else {
        uVar1 = 0xb7;
      }
    }
  }
  return uVar1;
}



/* c03e1b7c PD_OpenPartition */

/* Boundary evidence: original MIPS .pdata c03e1b7c..c03e1bd3. Semantic name remains unreviewed. */

undefined4 PD_OpenPartition(int param_1,wchar_t *param_2,int *param_3)

{
  undefined4 uVar1;
  int local_10 [2];
  
                    /* 0x1b7c  14  PD_OpenPartition */
  if (param_1 == 0) {
    uVar1 = 0x57;
  }
  else {
    FUN_c03e3e20(param_1,local_10,(undefined4 *)0x0,param_2);
    if (local_10[0] == 0) {
      uVar1 = 0x490;
    }
    else {
      *param_3 = local_10[0];
      uVar1 = 0;
    }
  }
  return uVar1;
}



/* c03e1bd4 FUN_c03e1bd4 */

/* Boundary evidence: original MIPS .pdata c03e1bd4..c03e1d4f. Semantic name remains unreviewed. */

DWORD FUN_c03e1bd4(int param_1,uint *param_2,DWORD param_3,LPVOID param_4,DWORD param_5,
                  LPDWORD param_6)

{
  BOOL BVar1;
  uint uVar2;
  uint uVar3;
  DWORD DVar4;
  
  uVar3 = *param_2;
  uVar2 = *(uint *)(param_1 + 0x48);
  DVar4 = 0;
  if ((*(uint *)(param_1 + 0x4c) != 0) || (uVar3 < uVar2)) {
    if ((*(uint *)(param_1 + 0x4c) != (uint)(uVar2 < uVar3)) || (param_2[1] <= uVar2 - uVar3)) {
      *param_2 = *(int *)(param_1 + 0x40) + uVar3;
      BVar1 = DeviceIoControl(*(HANDLE *)(*(int *)(param_1 + 0x74) + 0x18),0x75c08,param_2,param_3,
                              param_4,param_5,param_6,(LPOVERLAPPED)0x0);
      if (((BVar1 == 0) &&
          (BVar1 = DeviceIoControl(*(HANDLE *)(*(int *)(param_1 + 0x74) + 0x18),2,param_2,param_3,
                                   param_4,param_5,param_6,(LPOVERLAPPED)0x0), BVar1 == 0)) &&
         (DVar4 = GetLastError(), DVar4 == 0)) {
        DVar4 = 0x1f;
      }
      *param_2 = *param_2 - *(int *)(param_1 + 0x40);
      return DVar4;
    }
  }
  return 9;
}



/* c03e1d50 FUN_c03e1d50 */

/* Boundary evidence: original MIPS .pdata c03e1d50..c03e1ee3. Semantic name remains unreviewed. */

DWORD FUN_c03e1d50(int param_1,uint *param_2,DWORD param_3,LPVOID param_4,DWORD param_5,
                  LPDWORD param_6)

{
  BOOL BVar1;
  uint uVar2;
  uint uVar3;
  DWORD DVar4;
  
  uVar3 = *param_2;
  uVar2 = *(uint *)(param_1 + 0x48);
  DVar4 = 0;
  if ((*(uint *)(param_1 + 0x4c) != 0) || (uVar3 < uVar2)) {
    if ((*(uint *)(param_1 + 0x4c) != (uint)(uVar2 < uVar3)) || (param_2[1] <= uVar2 - uVar3)) {
      if ((*(uint *)(param_1 + 0x60) & 2) != 0) {
        return 5;
      }
      *param_2 = *(int *)(param_1 + 0x40) + uVar3;
      BVar1 = DeviceIoControl(*(HANDLE *)(*(int *)(param_1 + 0x74) + 0x18),0x79c0c,param_2,param_3,
                              param_4,param_5,param_6,(LPOVERLAPPED)0x0);
      if (((BVar1 == 0) &&
          (BVar1 = DeviceIoControl(*(HANDLE *)(*(int *)(param_1 + 0x74) + 0x18),3,param_2,param_3,
                                   param_4,param_5,param_6,(LPOVERLAPPED)0x0), BVar1 == 0)) &&
         (DVar4 = GetLastError(), DVar4 == 0)) {
        DVar4 = 0x1f;
      }
      *param_2 = *param_2 - *(int *)(param_1 + 0x40);
      return DVar4;
    }
  }
  return 9;
}



/* c03e1ee4 FUN_c03e1ee4 */

/* Boundary evidence: original MIPS .pdata c03e1ee4..c03e200f. Semantic name remains unreviewed. */

DWORD FUN_c03e1ee4(int param_1,int *param_2,LPDWORD param_3)

{
  BOOL BVar1;
  uint uVar2;
  DWORD DVar3;
  
  DVar3 = 0;
  if (*param_2 == 0xc) {
    uVar2 = param_2[1];
    if (((*(int *)(param_1 + 0x4c) == 0) && (*(uint *)(param_1 + 0x48) <= uVar2)) ||
       ((*(int *)(param_1 + 0x4c) == 0 && (*(uint *)(param_1 + 0x48) < param_2[2] + uVar2)))) {
      DVar3 = 9;
    }
    else if ((*(uint *)(param_1 + 0x60) & 2) == 0) {
      param_2[1] = *(int *)(param_1 + 0x40) + uVar2;
      BVar1 = DeviceIoControl(*(HANDLE *)(*(int *)(param_1 + 0x74) + 0x18),0x71c4c,param_2,0xc,
                              (LPVOID)0x0,0,param_3,(LPOVERLAPPED)0x0);
      if ((BVar1 == 0) && (DVar3 = GetLastError(), DVar3 == 0)) {
        DVar3 = 0x1f;
      }
      param_2[1] = param_2[1] - *(int *)(param_1 + 0x40);
    }
    else {
      DVar3 = 5;
    }
  }
  else {
    DVar3 = 0x57;
  }
  return DVar3;
}



/* c03e2010 FUN_c03e2010 */

/* Boundary evidence: original MIPS .pdata c03e2010..c03e20bf. Semantic name remains unreviewed. */

DWORD FUN_c03e2010(DWORD param_1,int param_2)

{
  BOOL BVar1;
  DWORD DVar2;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  
  local_18 = 0xc;
  local_14 = *(undefined4 *)(param_2 + 0x40);
  local_10 = *(undefined4 *)(param_2 + 0x48);
  DVar2 = 0;
  if ((*(uint *)(param_2 + 0x60) & 2) == 0) {
    BVar1 = DeviceIoControl(*(HANDLE *)(*(int *)(param_2 + 0x74) + 0x18),param_1,&local_18,0xc,
                            (LPVOID)0x0,0,(LPDWORD)0x0,(LPOVERLAPPED)0x0);
    if ((BVar1 == 0) && (DVar2 = GetLastError(), DVar2 == 0)) {
      DVar2 = 0x1f;
    }
  }
  else {
    DVar2 = 5;
  }
  return DVar2;
}



/* c03e20c0 FUN_c03e20c0 */

/* Boundary evidence: original MIPS .pdata c03e20c0..c03e21c7. Semantic name remains unreviewed. */

DWORD FUN_c03e20c0(int param_1,int *param_2,uint param_3,LPVOID param_4,DWORD param_5,
                  LPDWORD param_6)

{
  BOOL BVar1;
  int *piVar2;
  uint uVar3;
  uint uVar4;
  DWORD DVar5;
  
  DVar5 = 0;
  uVar4 = param_3 >> 2;
  piVar2 = param_2;
  for (uVar3 = uVar4; uVar3 != 0; uVar3 = uVar3 - 1) {
    *piVar2 = *(int *)(param_1 + 0x40) + *piVar2;
    piVar2 = piVar2 + 1;
  }
  BVar1 = DeviceIoControl(*(HANDLE *)(*(int *)(param_1 + 0x74) + 0x18),0x71c50,param_2,param_3,
                          param_4,param_5,param_6,(LPOVERLAPPED)0x0);
  if ((BVar1 == 0) && (DVar5 = GetLastError(), DVar5 == 0)) {
    DVar5 = 0x1f;
  }
  for (; uVar4 != 0; uVar4 = uVar4 - 1) {
    *param_2 = *param_2 - *(int *)(param_1 + 0x40);
    param_2 = param_2 + 1;
  }
  return DVar5;
}



/* c03e21c8 FUN_c03e21c8 */

/* Boundary evidence: original MIPS .pdata c03e21c8..c03e2287. Semantic name remains unreviewed. */

DWORD FUN_c03e21c8(int param_1,LPVOID param_2,LPVOID param_3,DWORD param_4,LPDWORD param_5)

{
  BOOL BVar1;
  uint uVar2;
  int *piVar3;
  DWORD DVar4;
  
  DVar4 = 0;
  piVar3 = (int *)((int)param_2 + 0x228);
  for (uVar2 = *(uint *)((int)param_2 + 0x224) >> 3; uVar2 != 0; uVar2 = uVar2 - 1) {
    *piVar3 = *(int *)(param_1 + 0x40) + *piVar3;
    piVar3 = piVar3 + 2;
  }
  BVar1 = DeviceIoControl(*(HANDLE *)(*(int *)(param_1 + 0x74) + 0x18),0x71c58,param_2,
                          *(int *)((int)param_2 + 0x224) + 0x228,param_3,param_4,param_5,
                          (LPOVERLAPPED)0x0);
  if ((BVar1 == 0) && (DVar4 = GetLastError(), DVar4 == 0)) {
    DVar4 = 0x1f;
  }
  return DVar4;
}



/* c03e2288 PD_DeviceIoControl */

/* Boundary evidence: original MIPS .pdata c03e2288..c03e25c7. Semantic name remains unreviewed. */

DWORD PD_DeviceIoControl(int param_1,DWORD param_2,uint *param_3,uint param_4,uint *param_5,
                        DWORD param_6,LPDWORD param_7)

{
  DWORD DVar1;
  int iVar2;
  BOOL BVar3;
  uint uVar4;
  uint *puVar5;
  
                    /* 0x2288  5  PD_DeviceIoControl */
  if ((param_2 == 0x75c08) || (param_2 == 2)) {
    DVar1 = FUN_c03e1bd4(param_1,param_3,param_4,param_5,param_6,param_7);
    return DVar1;
  }
  if ((param_2 == 0x79c0c) || (param_2 == 3)) {
    DVar1 = FUN_c03e1d50(param_1,param_3,param_4,param_5,param_6,param_7);
    return DVar1;
  }
  if (param_2 == 0x71c4c) {
    if (param_4 == 0xc) {
      DVar1 = FUN_c03e1ee4(param_1,(int *)param_3,param_7);
      return DVar1;
    }
  }
  else {
    if ((param_2 == 0x71c64) || (param_2 == 0x71c80)) {
      DVar1 = FUN_c03e2010(param_2,param_1);
      return DVar1;
    }
    if (param_2 == 0x71c58) {
      if (0x227 < param_4) {
        DVar1 = FUN_c03e21c8(param_1,param_3,param_5,param_6,param_7);
        return DVar1;
      }
    }
    else if ((param_2 == 0x71c00) || (param_2 == 1)) {
      puVar5 = (uint *)0x0;
      if (((param_3 == (uint *)0x0) || (puVar5 = param_3, param_4 == 0x18)) &&
         (((param_5 == (uint *)0x0 || (puVar5 = param_5, param_6 == 0x18)) &&
          (puVar5 != (uint *)0x0)))) {
        BVar3 = DeviceIoControl(*(HANDLE *)(*(int *)(param_1 + 0x74) + 0x18),param_2,param_3,param_4
                                ,param_5,param_6,param_7,(LPOVERLAPPED)0x0);
        if (BVar3 != 0) {
          uVar4 = puVar5[5];
          *puVar5 = *(uint *)(param_1 + 0x48);
          puVar5[2] = 1;
          puVar5[3] = 1;
          puVar5[4] = 1;
          puVar5[5] = uVar4 & 0xfffffffe;
          if (*(int *)(*(int *)(param_1 + 0x74) + 0x1c) != 0) {
            puVar5[5] = uVar4 & 0xfffffffa;
          }
          if (param_7 != (LPDWORD)0x0) {
            *param_7 = 0x18;
          }
          return 0;
        }
        goto LAB_c03e2444;
      }
    }
    else {
      if (param_2 != 0x71c50) {
        iVar2 = ForwardDeviceIoControl
                          (*(undefined4 *)(*(int *)(param_1 + 0x74) + 0x18),param_2,param_3,param_4,
                           param_5,param_6,param_7,0);
        if (iVar2 != 0) {
          return 0;
        }
LAB_c03e2444:
        DVar1 = GetLastError();
        if (DVar1 != 0) {
          return DVar1;
        }
        return 0x1f;
      }
      if (((param_6 != 0) && (param_4 == param_6)) &&
         ((param_3 != (uint *)0x0 && (param_5 != (uint *)0x0)))) {
        DVar1 = FUN_c03e20c0(param_1,(int *)param_3,param_4,param_5,param_6,param_7);
        return DVar1;
      }
    }
  }
  return 0x57;
}



/* c03e25c8 PD_ClosePartition */

void PD_ClosePartition(void)

{
                    /* 0x25c8  1  PD_ClosePartition */
  return;
}



/* c03e25d0 PD_DeletePartition */

/* Boundary evidence: original MIPS .pdata c03e25d0..c03e270f. Semantic name remains unreviewed. */

undefined4 PD_DeletePartition(uint param_1,wchar_t *param_2)

{
  int iVar1;
  DWORD dwErrCode;
  undefined4 uVar2;
  HLOCAL local_10;
  int local_c;
  
                    /* 0x25d0  4  PD_DeletePartition */
  FUN_c03e3e20(param_1,&local_10,&local_c,param_2);
  if (local_10 == (HLOCAL)0x0) {
    uVar2 = 0x490;
    dwErrCode = 0x490;
  }
  else {
    if ((*(uint *)((int)local_10 + 0x60) & 2) == 0) {
      if (*(int *)((int)local_10 + 0x68) == 0 && *(int *)((int)local_10 + 0x6c) == 0) {
        iVar1 = FUN_c03e51b0(param_1,(int)local_10);
      }
      else {
        iVar1 = FUN_c03e4e8c(param_1,(int)local_10,local_c);
      }
      if (iVar1 == 0) {
        return 0x1f;
      }
      FUN_c03e3bac(param_1,(int)local_10);
      if (local_c == 0) {
        *(undefined4 *)(param_1 + 0x40) = *(undefined4 *)((int)local_10 + 0x70);
      }
      else {
        *(undefined4 *)(local_c + 0x70) = *(undefined4 *)((int)local_10 + 0x70);
      }
      iVar1 = *(int *)(param_1 + 0x44);
      *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + -1;
      for (; iVar1 != 0; iVar1 = *(int *)(iVar1 + 8)) {
        if (*(HLOCAL *)(iVar1 + 4) == local_10) {
          *(undefined4 *)(iVar1 + 4) = *(undefined4 *)((int)local_10 + 0x70);
        }
      }
      LocalFree(local_10);
      return 0;
    }
    uVar2 = 5;
    dwErrCode = 5;
  }
  SetLastError(dwErrCode);
  return uVar2;
}



/* c03e2710 PD_RenamePartition */

/* Boundary evidence: original MIPS .pdata c03e2710..c03e27bf. Semantic name remains unreviewed. */

undefined4 PD_RenamePartition(int param_1,wchar_t *param_2,wchar_t *param_3)

{
  undefined4 uVar1;
  wchar_t *local_18 [2];
  
                    /* 0x2710  16  PD_RenamePartition */
  if (param_1 == 0) {
    uVar1 = 0x57;
  }
  else {
    FUN_c03e3e20(param_1,local_18,(undefined4 *)0x0,param_3);
    if (local_18[0] == (wchar_t *)0x0) {
      FUN_c03e3e20(param_1,local_18,(undefined4 *)0x0,param_2);
      if (local_18[0] == (wchar_t *)0x0) {
        uVar1 = 0x490;
      }
      else {
        memset(local_18[0],0,0x40);
        wcscpy(local_18[0],param_3);
        uVar1 = 0;
      }
    }
    else {
      uVar1 = 0xb7;
    }
  }
  return uVar1;
}



/* c03e27c0 PD_SetPartitionAttrs */

/* Boundary evidence: original MIPS .pdata c03e27c0..c03e2817. Semantic name remains unreviewed. */

undefined4 PD_SetPartitionAttrs(int param_1,wchar_t *param_2,undefined4 param_3)

{
  undefined4 uVar1;
  int local_10 [2];
  
                    /* 0x27c0  17  PD_SetPartitionAttrs */
  if (param_1 == 0) {
    uVar1 = 0x57;
  }
  else {
    FUN_c03e3e20(param_1,local_10,(undefined4 *)0x0,param_2);
    if (local_10[0] == 0) {
      uVar1 = 0x490;
    }
    else {
      *(undefined4 *)(local_10[0] + 0x60) = param_3;
      uVar1 = 0;
    }
  }
  return uVar1;
}



/* c03e2818 PD_SetPartitionSize */

/* Boundary evidence: original MIPS .pdata c03e2818..c03e2947. Semantic name remains unreviewed. */

undefined4 PD_SetPartitionSize(uint param_1,wchar_t *param_2,uint param_3,int param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  int local_28 [2];
  
                    /* 0x2818  18  PD_SetPartitionSize */
  if ((*(uint *)(param_1 + 0x24) & 2) == 0) {
    iVar3 = *(int *)(param_1 + 0x38);
  }
  else {
    iVar3 = *(int *)(param_1 + 0x38) * *(int *)(param_1 + 0x34);
  }
  FUN_c03e3e20(param_1,local_28,(undefined4 *)0x0,param_2);
  iVar1 = local_28[0];
  if ((local_28[0] == 0) || (*(int *)(local_28[0] + 0x68) != 0 || *(int *)(local_28[0] + 0x6c) != 0)
     ) {
    uVar4 = 0x490;
  }
  else {
    if ((iVar3 != 0) &&
       (uVar5 = *(uint *)(local_28[0] + 0x40) + param_3,
       iVar2 = __ull_rem(uVar5,*(int *)(local_28[0] + 0x44) + param_4 +
                               (uint)(uVar5 < *(uint *)(local_28[0] + 0x40)),iVar3,0), iVar2 != 0))
    {
      param_3 = (iVar3 - iVar2) + param_3;
      param_4 = param_4 + (uint)(param_3 < (uint)(iVar3 - iVar2));
    }
    uVar6 = *(undefined4 *)(iVar1 + 0x48);
    uVar7 = *(undefined4 *)(iVar1 + 0x4c);
    *(uint *)(iVar1 + 0x48) = param_3;
    *(int *)(iVar1 + 0x4c) = param_4;
    iVar3 = FUN_c03e5020(param_1,local_28[0]);
    if (iVar3 == 0) {
      uVar4 = 0x1f;
      *(undefined4 *)(local_28[0] + 0x48) = uVar6;
      *(undefined4 *)(local_28[0] + 0x4c) = uVar7;
    }
    else {
      uVar4 = 0;
    }
  }
  return uVar4;
}



/* c03e2948 PD_FormatPartition */

/* Boundary evidence: original MIPS .pdata c03e2948..c03e2b3f. Semantic name remains unreviewed. */

undefined4 PD_FormatPartition(uint param_1,wchar_t *param_2,uint param_3,int param_4)

{
  int iVar1;
  undefined1 *puVar2;
  byte local_28 [4];
  undefined1 *local_24;
  HLOCAL local_20 [2];
  
                    /* 0x2948  9  PD_FormatPartition */
  local_28[0] = 0xff;
  local_20[0] = (HLOCAL)0x0;
  if (param_1 == 0) {
    return 0x57;
  }
  FUN_c03e3e20(param_1,&local_24,(undefined4 *)0x0,param_2);
  if (local_24 == (undefined1 *)0x0) {
    return 0x490;
  }
  if ((*(uint *)(local_24 + 0x60) & 2) != 0) {
    SetLastError(5);
    return 5;
  }
  iVar1 = FUN_c03e3c14(param_1,(int)local_24);
  if (iVar1 != 0) {
    local_28[0] = (byte)param_3;
    if ((param_4 != 0) && (param_3 != (byte)local_24[0x78])) {
      FUN_c03e2e00(param_1,local_24,*(uint *)(local_24 + 0x48),*(undefined4 *)(local_24 + 0x4c),
                   local_28);
      param_3 = (uint)local_28[0];
    }
    if (param_3 == 0xff) {
      return 0;
    }
    if (param_3 == (byte)local_24[0x78]) {
      return 0;
    }
    if (*(int *)(local_24 + 0x68) == 0 && *(int *)(local_24 + 0x6c) == 0) {
      puVar2 = local_24;
      iVar1 = FUN_c03e51b0(param_1,(int)local_24);
      if (iVar1 == 0) {
        return 0x1f;
      }
      iVar1 = FUN_c03e534c(param_1,puVar2,*(uint *)(local_24 + 0x40),*(int *)(local_24 + 0x44),
                           *(int *)(local_24 + 0x48),*(undefined4 *)(local_24 + 0x4c),local_28[0],0)
      ;
    }
    else {
      local_20[0] = (HLOCAL)0x0;
      puVar2 = local_24;
      iVar1 = FUN_c03e3088(param_1,local_24,*(undefined4 *)(local_24 + 0x68),
                           *(undefined4 *)(local_24 + 0x6c),1,0,(int *)local_20);
      if (iVar1 == 0) {
        return 0x1f;
      }
      *(byte *)((int)local_20[0] + 0x1c2) = local_28[0];
      iVar1 = FUN_c03e2fb8(param_1,puVar2,*(undefined4 *)(local_24 + 0x68),
                           *(undefined4 *)(local_24 + 0x6c),1,0,local_20[0]);
      LocalFree(local_20[0]);
    }
    if (iVar1 == 0) {
      return 0x1f;
    }
    local_24[0x78] = local_28[0];
  }
  return 0;
}



/* c03e2b40 PD_GetPartitionInfo */

/* Boundary evidence: original MIPS .pdata c03e2b40..c03e2bf3. Semantic name remains unreviewed. */

undefined4 PD_GetPartitionInfo(int param_1,wchar_t *param_2,int param_3)

{
  undefined4 uVar1;
  int local_18 [2];
  
                    /* 0x2b40  11  PD_GetPartitionInfo */
  if (param_1 == 0) {
    uVar1 = 0x57;
  }
  else {
    FUN_c03e3e20(param_1,local_18,(undefined4 *)0x0,param_2);
    if (local_18[0] == 0) {
      uVar1 = 0x490;
    }
    else {
      wcscpy((wchar_t *)(param_3 + 4),param_2);
      *(undefined4 *)(param_3 + 0x48) = *(undefined4 *)(local_18[0] + 0x48);
      uVar1 = 0;
      *(undefined4 *)(param_3 + 0x4c) = *(undefined4 *)(local_18[0] + 0x4c);
      *(undefined4 *)(param_3 + 0x50) = *(undefined4 *)(local_18[0] + 0x50);
      *(undefined4 *)(param_3 + 0x54) = *(undefined4 *)(local_18[0] + 0x54);
      *(undefined4 *)(param_3 + 0x58) = *(undefined4 *)(local_18[0] + 0x58);
      *(undefined4 *)(param_3 + 0x5c) = *(undefined4 *)(local_18[0] + 0x5c);
      *(undefined4 *)(param_3 + 0x60) = *(undefined4 *)(local_18[0] + 0x60);
      *(undefined1 *)(param_3 + 100) = *(undefined1 *)(local_18[0] + 0x78);
    }
  }
  return uVar1;
}



/* c03e2bf4 PD_FindPartitionStart */

/* Boundary evidence: original MIPS .pdata c03e2bf4..c03e2c93. Semantic name remains unreviewed. */

undefined4 PD_FindPartitionStart(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  int *piVar2;
  int iVar3;
  
                    /* 0x2bf4  8  PD_FindPartitionStart */
  if (*(int *)(param_1 + 0x1c) == 0) {
    uVar1 = 0xb;
  }
  else {
    piVar2 = LocalAlloc(0x40,0xc);
    if (piVar2 == (int *)0x0) {
      uVar1 = 0xe;
    }
    else {
      *piVar2 = param_1;
      iVar3 = *(int *)(param_1 + 0x40);
      if (iVar3 != 0) {
        if (iVar3 == *(int *)(param_1 + 0x48)) {
          iVar3 = *(int *)(*(int *)(param_1 + 0x48) + 0x70);
        }
        piVar2[1] = iVar3;
      }
      for (iVar3 = *(int *)(param_1 + 0x44); iVar3 != 0; iVar3 = *(int *)(iVar3 + 8)) {
      }
      *(int **)(param_1 + 0x44) = piVar2;
      *param_2 = piVar2;
      uVar1 = 0;
    }
  }
  return uVar1;
}



/* c03e2c94 PD_FindPartitionNext */

/* Boundary evidence: original MIPS .pdata c03e2c94..c03e2d0b. Semantic name remains unreviewed. */

int PD_FindPartitionNext(int *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
                    /* 0x2c94  7  PD_FindPartitionNext */
  if ((wchar_t *)param_1[1] == (wchar_t *)0x0) {
    iVar1 = 0x103;
  }
  else {
    iVar1 = PD_GetPartitionInfo(*param_1,(wchar_t *)param_1[1],param_2);
    if (iVar1 == 0) {
      iVar2 = *(int *)(param_1[1] + 0x70);
      if ((iVar2 == 0) || (iVar2 != *(int *)(*param_1 + 0x48))) {
        param_1[1] = iVar2;
      }
      else {
        param_1[1] = *(int *)(*(int *)(*param_1 + 0x48) + 0x70);
      }
    }
  }
  return iVar1;
}



/* c03e2d0c PD_FindPartitionClose */

/* Boundary evidence: original MIPS .pdata c03e2d0c..c03e2d67. Semantic name remains unreviewed. */

void PD_FindPartitionClose(int *param_1)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  
                    /* 0x2d0c  6  PD_FindPartitionClose */
  piVar1 = *(int **)(*param_1 + 0x44);
  piVar3 = (int *)0x0;
  if (piVar1 != (int *)0x0) {
    do {
      piVar2 = piVar1;
      if (piVar2 == param_1) break;
      piVar1 = (int *)piVar2[2];
      piVar3 = piVar2;
    } while ((int *)piVar2[2] != (int *)0x0);
    if (piVar3 == (int *)0x0) {
      *(undefined4 *)(*param_1 + 0x44) = 0;
    }
    else {
      piVar3[2] = param_1[2];
    }
    LocalFree(param_1);
  }
  return;
}



/* c03e2d68 FUN_c03e2d68 */

/* Boundary evidence: original MIPS .pdata c03e2d68..c03e2d9b. Semantic name remains unreviewed. */

undefined4 FUN_c03e2d68(HMODULE param_1,int param_2)

{
  if (param_2 == 1) {
    DisableThreadLibraryCalls(param_1);
  }
  return 1;
}



/* c03e2d9c FUN_c03e2d9c */

/* Boundary evidence: original MIPS .pdata c03e2d9c..c03e2dff. Semantic name remains unreviewed. */

void FUN_c03e2d9c(int param_1)

{
  HLOCAL hMem;
  HLOCAL pvVar1;
  
  hMem = *(HLOCAL *)(param_1 + 0x40);
  while (hMem != (HLOCAL)0x0) {
    pvVar1 = *(HLOCAL *)((int)hMem + 0x70);
    LocalFree(hMem);
    hMem = pvVar1;
  }
  *(undefined4 *)(param_1 + 0x40) = 0;
  *(undefined4 *)(param_1 + 0x48) = 0;
  *(undefined4 *)(param_1 + 0x50) = 0;
  *(undefined4 *)(param_1 + 0x54) = 0;
  *(undefined4 *)(param_1 + 0x58) = 0;
  *(undefined4 *)(param_1 + 0x5c) = 0;
  *(undefined4 *)(param_1 + 0x14) = 0;
  return;
}



/* c03e2e00 FUN_c03e2e00 */

/* Boundary evidence: original MIPS .pdata c03e2e00..c03e2fb7. Semantic name remains unreviewed. */

void FUN_c03e2e00(int param_1,undefined4 param_2,uint param_3,undefined4 param_4,undefined1 *param_5
                 )

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  
  uVar7 = *(uint *)(param_1 + 0x2c);
  uVar5 = 1;
  iVar1 = 1;
  if (uVar7 == 0) {
    trap(0x1c00);
  }
LAB_c03e2e40:
  do {
    iVar6 = 4;
    uVar2 = 0;
    uVar3 = 0;
    do {
      while( true ) {
        uVar8 = (((param_3 - uVar2) - uVar3) - iVar1) / uVar5;
        if (uVar5 == 0) {
          trap(0x1c00);
        }
        if (0x8000 / uVar7 < uVar5) {
          param_3 = (0x8000 / uVar7) * 0xffffff6;
          goto LAB_c03e2e40;
        }
        if (uVar8 < 0xff6) {
          iVar4 = 0xc;
          goto LAB_c03e2ecc;
        }
        if (uVar8 < 0xfff6) {
          iVar4 = 0x10;
          goto LAB_c03e2ecc;
        }
        if (uVar7 == 0) {
          trap(0x1c00);
        }
        if (0x1000 / uVar7 <= uVar5) break;
        uVar5 = uVar5 << 1;
      }
      iVar4 = 0x20;
      iVar1 = 2;
LAB_c03e2ecc:
      uVar8 = ((((uVar8 + 2) * iVar4 + 7 >> 3) + uVar7) - 1) / uVar7;
      if (uVar7 == 0) {
        trap(0x1c00);
      }
      if (iVar4 == 0x20) {
        uVar2 = 0;
      }
      else {
        uVar2 = (uVar7 + 0x1fff) / uVar7;
        if (uVar7 == 0) {
          trap(0x1c00);
        }
      }
    } while ((uVar8 != uVar3) && (iVar6 = iVar6 + -1, uVar3 = uVar8, iVar6 != 0));
    if (iVar6 != 0) {
      if (iVar4 == 0xc) {
        *param_5 = 1;
      }
      else if (iVar4 == 0x20) {
        *param_5 = 0xb;
      }
      else if (param_3 < 0x10000) {
        *param_5 = 4;
      }
      else {
        *param_5 = 6;
      }
      return;
    }
    param_3 = param_3 - uVar5;
  } while( true );
}



/* c03e2fb8 FUN_c03e2fb8 */

/* Boundary evidence: original MIPS .pdata c03e2fb8..c03e3087. Semantic name remains unreviewed. */

void FUN_c03e2fb8(uint param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,int param_5,
                 undefined4 param_6,undefined4 param_7)

{
  uint uVar1;
  uint uVar2;
  BOOL BVar3;
  undefined4 *puVar4;
  DWORD aDStack_38 [2];
  undefined4 local_30;
  int local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  int local_18;
  
  local_18 = *(int *)(param_1 + 0x2c) * param_5;
  local_28 = 1;
  puVar4 = (undefined4 *)(param_1 + 0x18);
  uVar1 = param_1 + 0x1b & 3;
  local_2c = param_5;
  local_1c = param_7;
  uVar2 = (uint)puVar4 & 3;
  local_24 = 0;
  local_20 = 0;
  local_30 = param_3;
  BVar3 = DeviceIoControl((HANDLE)((*(int *)((param_1 + 0x1b) - uVar1) << (3 - uVar1) * 8 |
                                   param_1 & 0xffffffffU >> (uVar1 + 1) * 8) & -1 << (4 - uVar2) * 8
                                  | *(uint *)((int)puVar4 - uVar2) >> uVar2 * 8),0x79c0c,&local_30,
                          0x1c,(LPVOID)0x0,0,aDStack_38,(LPOVERLAPPED)0x0);
  if (BVar3 == 0) {
    DeviceIoControl((HANDLE)*puVar4,3,&local_30,0x1c,(LPVOID)0x0,0,aDStack_38,(LPOVERLAPPED)0x0);
  }
  return;
}



/* c03e3088 FUN_c03e3088 */

/* Boundary evidence: original MIPS .pdata c03e3088..c03e31fb. Semantic name remains unreviewed. */

int FUN_c03e3088(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,uint param_5,
                undefined4 param_6,int *param_7)

{
  SIZE_T uBytes;
  BOOL BVar1;
  HLOCAL hMem;
  DWORD aDStack_48 [2];
  undefined4 local_40;
  uint local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  HLOCAL local_2c;
  SIZE_T local_28;
  
  if (param_5 == 0) {
    trap(0x1c00);
  }
  if (*(uint *)(param_1 + 0x2c) <= 0xffffffff / param_5) {
    uBytes = *(uint *)(param_1 + 0x2c) * param_5;
    hMem = (HLOCAL)*param_7;
    if ((hMem != (HLOCAL)0x0) || (hMem = LocalAlloc(0x40,uBytes), hMem != (HLOCAL)0x0)) {
      local_38 = 1;
      local_3c = param_5;
      local_34 = 0;
      local_30 = 0;
      local_40 = param_3;
      local_2c = hMem;
      local_28 = uBytes;
      BVar1 = DeviceIoControl(*(HANDLE *)(param_1 + 0x18),0x75c08,&local_40,0x1c,(LPVOID)0x0,0,
                              aDStack_48,(LPOVERLAPPED)0x0);
      if (BVar1 == 0) {
        BVar1 = DeviceIoControl(*(HANDLE *)(param_1 + 0x18),2,&local_40,0x1c,(LPVOID)0x0,0,
                                aDStack_48,(LPOVERLAPPED)0x0);
      }
      if (*param_7 != 0) {
        return BVar1;
      }
      if (BVar1 != 0) {
        *param_7 = (int)hMem;
        return BVar1;
      }
      LocalFree(hMem);
      return 0;
    }
  }
  return 0;
}



/* c03e31fc FUN_c03e31fc */

/* WARNING: Removing unreachable block (ram,0xc03e37a0) */
/* WARNING: Removing unreachable block (ram,0xc03e36d4) */
/* WARNING: Removing unreachable block (ram,0xc03e3630) */
/* WARNING: Removing unreachable block (ram,0xc03e3994) */
/* Boundary evidence: original MIPS .pdata c03e31fc..c03e3af7. Semantic name remains unreviewed. */

undefined4
FUN_c03e31fc(int param_1,HLOCAL param_2,uint param_3,int param_4,char param_5,int *param_6,
            uint *param_7,uint *param_8,ulonglong *param_9)

{
  bool bVar1;
  bool bVar2;
  ulonglong uVar3;
  ulonglong uVar4;
  ulonglong uVar5;
  uint uVar6;
  uint uVar7;
  int *piVar8;
  uint uVar9;
  int iVar10;
  int iVar11;
  uint uVar12;
  uint uVar13;
  undefined4 uVar14;
  HLOCAL pvVar15;
  undefined4 uVar16;
  uint uVar17;
  int iVar18;
  int iVar19;
  longlong lVar20;
  longlong lVar21;
  HLOCAL local_38;
  HLOCAL local_34;
  HLOCAL local_30;
  
  bVar2 = false;
  if ((*(uint *)(param_1 + 0x24) & 2) == 0) {
    uVar7 = *(uint *)(param_1 + 0x38);
  }
  else {
    uVar7 = *(int *)(param_1 + 0x34) * *(int *)(param_1 + 0x38);
  }
  iVar18 = *(int *)(param_1 + 0x40);
  uVar12 = *(uint *)(param_1 + 0x50);
  uVar13 = *(uint *)(param_1 + 0x54);
  *(uint *)param_9 = param_3;
  *(int *)((int)param_9 + 4) = param_4;
  *param_7 = 0;
  param_7[1] = 0;
  iVar19 = 0;
  if (((1 < *(uint *)(param_1 + 0x34)) && (param_4 == 0)) && (param_3 < *(uint *)(param_1 + 0x38)))
  {
    *(uint *)param_9 = *(uint *)(param_1 + 0x38);
    *(undefined4 *)((int)param_9 + 4) = 0;
  }
  uVar14 = 1;
  local_34 = *(HLOCAL *)((int)param_9 + 4);
  bVar1 = *(uint *)(param_1 + 0x34) < 2;
  uVar6 = (uint)*param_9;
  if (bVar1) {
    uVar3 = CONCAT44((int)local_34 + (uint)(uVar6 + 1 < uVar6),uVar6 + 1);
  }
  else {
    uVar17 = *(uint *)(param_1 + 0x38) + uVar6;
    pvVar15 = (HLOCAL)((int)local_34 + (uint)(uVar17 < *(uint *)(param_1 + 0x38)));
    uVar3 = CONCAT44(pvVar15,uVar17);
    local_30 = (HLOCAL)0x0;
    param_2 = pvVar15;
    lVar20 = __ull_rem(uVar17,pvVar15,uVar7,0);
    if (lVar20 != 0) {
      lVar20 = __ull_div(uVar17,pvVar15,uVar7,0);
      uVar3 = (lVar20 + 1) * CONCAT44(local_30,uVar7);
      param_2 = pvVar15;
    }
  }
  pvVar15 = local_34;
  iVar11 = *(int *)(param_1 + 0x40);
  if (iVar11 == 0) {
    local_38 = (HLOCAL)0x1;
    bVar2 = true;
    if ((*(uint *)(param_1 + 0x24) & 1) != 0) {
      local_38 = (HLOCAL)0x0;
      if (bVar1) {
        uVar12 = 1;
      }
      else {
        if ((param_5 == ' ') || (param_5 == '&')) {
          uVar12 = 2;
          if ((*(uint *)(param_1 + 0x24) & 4) == 0) {
            uVar12 = 1;
          }
          uVar13 = uVar6 + uVar12;
          param_2 = (HLOCAL)((int)local_34 + (uint)(uVar13 < uVar6));
          local_34 = (HLOCAL)0x0;
          local_30 = param_2;
          lVar20 = __ull_rem(uVar13,param_2,uVar7,0);
          if (lVar20 != 0) {
            param_2 = local_30;
            lVar20 = __ull_div(uVar13,local_30,uVar7,0);
            lVar20 = (lVar20 + 1) * CONCAT44(local_34,uVar7);
            uVar13 = (uint)lVar20;
            uVar6 = uVar13 - uVar12;
            pvVar15 = (HLOCAL)((int)((ulonglong)lVar20 >> 0x20) - (uint)(uVar13 < uVar12));
          }
        }
        else {
          param_2 = local_34;
          lVar20 = __ull_rem(uVar6,local_34,uVar7,0);
          uVar12 = uVar7;
          if (lVar20 != 0) {
            lVar21 = __ull_div(uVar6,pvVar15,uVar7,0);
            lVar20 = (lVar21 + 1U & 0xffffffff) * (ulonglong)uVar7;
            uVar6 = (uint)lVar20;
            param_2 = pvVar15;
            pvVar15 = (HLOCAL)((int)(lVar21 + 1U >> 0x20) * uVar7 + (int)((ulonglong)lVar20 >> 0x20)
                              );
          }
        }
        iVar11 = *(int *)(param_1 + 0x40);
        local_34 = pvVar15;
      }
      uVar13 = 0;
      uVar17 = *(uint *)(param_1 + 0x28) - uVar12;
      pvVar15 = (HLOCAL)-(uint)(*(uint *)(param_1 + 0x28) < uVar12);
      uVar3 = CONCAT44(local_34,uVar6);
      if ((pvVar15 <= local_34) &&
         ((local_34 != pvVar15 || (uVar3 = CONCAT44(local_34,uVar6), uVar17 < uVar6)))) {
        uVar3 = CONCAT44(pvVar15,uVar17);
      }
    }
  }
  else {
    local_38 = local_30;
  }
  if ((((*(uint *)(param_1 + 0x24) & 4) != 0) && (uVar12 == 1)) && (uVar13 == 0)) {
    uVar12 = 2;
    uVar13 = 0;
  }
  if ((!bVar2) && (uVar12 != 0 || uVar13 != 0)) {
    while (iVar10 = iVar18, iVar10 != 0) {
      uVar6 = *(uint *)(iVar10 + 0x68);
      if (uVar6 == 0 && *(int *)(iVar10 + 0x6c) == 0) {
        if ((iVar19 != 0) && (*(int *)(iVar19 + 0x68) != 0 || *(int *)(iVar19 + 0x6c) != 0)) break;
      }
      else {
        if (uVar3 <= CONCAT44((*(int *)(iVar10 + 0x6c) - uVar13) - (uint)(uVar6 < uVar12),
                              uVar6 - uVar12)) {
          bVar2 = true;
          local_38 = (HLOCAL)0x1;
          goto LAB_c03e3678;
        }
        uVar12 = *(uint *)(iVar10 + 0x48) + *(int *)(iVar10 + 0x40);
        uVar13 = *(int *)(iVar10 + 0x4c) + *(int *)(iVar10 + 0x44) +
                 (uint)(uVar12 < *(uint *)(iVar10 + 0x48));
      }
      iVar19 = iVar10;
      iVar18 = *(int *)(iVar10 + 0x70);
    }
    if ((uVar12 == *(uint *)(param_1 + 0x50)) && (uVar13 == *(uint *)(param_1 + 0x54))) {
      uVar6 = *(uint *)(param_1 + 0x58) - uVar12;
      uVar17 = uVar6 + 1;
      if (uVar3 <= CONCAT44(((*(int *)(param_1 + 0x5c) - uVar13) -
                            (uint)(*(uint *)(param_1 + 0x58) < uVar12)) + (uint)(uVar17 < uVar6),
                            uVar17)) {
        local_38 = (HLOCAL)0x1;
        bVar2 = true;
        if ((*(uint *)(iVar11 + 0x44) < uVar13) ||
           ((*(uint *)(iVar11 + 0x44) == uVar13 && (*(uint *)(iVar11 + 0x40) <= uVar12)))) {
          while (iVar19 = iVar11, iVar11 = *(int *)(iVar19 + 0x70), iVar11 != 0) {
            if ((uVar13 < *(uint *)(iVar11 + 0x44)) ||
               ((*(uint *)(iVar11 + 0x44) == uVar13 && (uVar12 < *(uint *)(iVar11 + 0x40))))) break;
          }
        }
        else {
          iVar19 = 0;
        }
      }
    }
    else {
      uVar6 = *(uint *)(param_1 + 0x58) - uVar12;
      uVar17 = uVar6 + 1;
      if (uVar3 <= CONCAT44(((*(int *)(param_1 + 0x5c) - uVar13) -
                            (uint)(*(uint *)(param_1 + 0x58) < uVar12)) + (uint)(uVar17 < uVar6),
                            uVar17)) {
        bVar2 = true;
        local_38 = (HLOCAL)0x1;
      }
    }
  }
LAB_c03e3678:
  local_34 = (HLOCAL)0x0;
  if (bVar2) {
LAB_c03e3a40:
    *param_9 = uVar3;
    *param_6 = iVar19;
    if (local_38 == (HLOCAL)0x0) {
      *param_8 = 0;
      param_8[1] = 0;
      *param_7 = uVar12;
      param_7[1] = uVar13;
    }
    else {
      *param_8 = uVar12;
      param_8[1] = uVar13;
      if (*(uint *)(param_1 + 0x34) < 2) {
        *param_7 = uVar12 + 1;
        param_7[1] = uVar13 + (uVar12 + 1 < uVar12);
      }
      else {
        uVar7 = *(uint *)(param_1 + 0x38);
        uVar12 = uVar7 + uVar12;
        *param_7 = uVar12;
        param_7[1] = uVar13 + (uVar12 < uVar7);
      }
    }
  }
  else {
    iVar18 = FUN_c03e3088(param_1,param_2,0,0,1,0,(int *)&local_34);
    pvVar15 = local_34;
    if (iVar18 != 0) {
      if (*(int *)((int)local_34 + 0x1fa) == 0) {
        uVar5 = *param_9;
        bVar2 = *(uint *)(param_1 + 0x34) < 2;
        uVar16 = *(undefined4 *)((int)param_9 + 4);
        uVar3 = *param_9;
        uVar4 = *param_9;
        if (!bVar2) {
          local_30 = (HLOCAL)0x0;
          lVar20 = __ull_rem((int)uVar5,uVar16,uVar7,0);
          uVar4 = uVar3;
          if (lVar20 != 0) {
            lVar20 = __ull_div((int)uVar5,uVar16,uVar7,0);
            uVar4 = (lVar20 + 1) * CONCAT44(local_30,uVar7);
          }
        }
        uVar6 = 0;
        uVar7 = 0;
        uVar3 = uVar4;
        if (1 < *(byte *)((int)pvVar15 + 0x1c1)) {
          uVar13 = 0;
          if (bVar2) {
            uVar6 = *(int *)((int)pvVar15 + 0x1c6) - 1;
            uVar7 = 0;
            uVar12 = 1;
          }
          else {
            uVar12 = *(uint *)(param_1 + 0x38);
            uVar7 = *(byte *)((int)pvVar15 + 0x1bf) * uVar12;
            uVar17 = *(int *)((int)pvVar15 + 0x1c6) - uVar12;
            uVar6 = uVar17 - uVar7;
            uVar7 = -(uint)(uVar17 < uVar7);
          }
          uVar17 = (int)(uVar4 >> 0x20) - (uint)((uint)uVar4 < uVar12);
          uVar9 = (uint)uVar4 - uVar12;
          uVar3 = CONCAT44(uVar17,uVar9);
          if ((uVar7 <= uVar17) &&
             ((uVar7 != uVar17 || (uVar3 = CONCAT44(uVar17,uVar9), uVar6 < uVar9)))) {
            uVar6 = 0;
            uVar7 = 0;
            uVar3 = uVar4;
          }
        }
        iVar18 = 0;
        piVar8 = (int *)((int)pvVar15 + 0x1c6);
        do {
          iVar11 = piVar8[1];
          if (iVar11 == 0) break;
          if (uVar6 == 0 && uVar7 == 0) {
            iVar10 = *piVar8;
            if (piVar8[5] == 0) {
              uVar6 = (*(int *)(param_1 + 0x28) - iVar11) - iVar10;
            }
            else {
              uVar6 = (piVar8[4] - iVar11) - iVar10;
            }
            uVar7 = 0;
            uVar12 = iVar11 + iVar10;
            uVar13 = 0;
          }
          if (uVar3 <= CONCAT44(uVar7,uVar6)) {
            bVar2 = true;
            local_38 = (HLOCAL)0x0;
            iVar18 = *(int *)(param_1 + 0x40);
            iVar19 = 0;
            goto joined_r0xc03e39fc;
          }
          iVar18 = iVar18 + 1;
          uVar6 = 0;
          uVar7 = 0;
          piVar8 = piVar8 + 4;
        } while (iVar18 < 4);
      }
      bVar2 = false;
LAB_c03e39bc:
      if (local_34 != (HLOCAL)0x0) {
        LocalFree(local_34);
      }
      if (bVar2) goto LAB_c03e3a40;
      SetLastError(0x70);
    }
    uVar14 = 0;
  }
  return uVar14;
joined_r0xc03e39fc:
  iVar11 = iVar18;
  if (iVar11 == 0) goto LAB_c03e39bc;
  if ((uVar13 < *(uint *)(iVar11 + 0x44)) ||
     ((*(uint *)(iVar11 + 0x44) == uVar13 && (uVar12 < *(uint *)(iVar11 + 0x40)))))
  goto LAB_c03e39bc;
  iVar18 = *(int *)(iVar11 + 0x70);
  iVar19 = iVar11;
  goto joined_r0xc03e39fc;
}



/* c03e3af8 FUN_c03e3af8 */

undefined4
FUN_c03e3af8(int param_1,undefined4 param_2,uint param_3,undefined4 param_4,undefined1 *param_5,
            char *param_6,byte *param_7)

{
  uint uVar1;
  char cVar2;
  undefined4 uVar3;
  uint uVar4;
  uint uVar5;
  
  if (*(uint *)(param_1 + 0x28) < param_3) {
    uVar3 = 0;
  }
  else {
    uVar4 = *(uint *)(param_1 + 0x38);
    uVar1 = *(int *)(param_1 + 0x34) * uVar4;
    uVar5 = param_3 / uVar1;
    if (uVar1 == 0) {
      trap(0x1c00);
    }
    if (uVar4 == 0) {
      trap(0x1c00);
    }
    cVar2 = (char)((param_3 - uVar5 * uVar1) / uVar4);
    uVar3 = 1;
    *param_6 = cVar2;
    *param_5 = (char)uVar5;
    *param_7 = ((byte)(uVar5 >> 2) ^
               (((char)param_3 - (char)uVar4 * cVar2) - (char)(uVar5 * uVar1)) + 1U) & 0x3f ^
               (byte)(uVar5 >> 2);
  }
  return uVar3;
}



/* c03e3bac FUN_c03e3bac */

/* Boundary evidence: original MIPS .pdata c03e3bac..c03e3c13. Semantic name remains unreviewed. */

void FUN_c03e3bac(int param_1,int param_2)

{
  DWORD aDStack_20 [2];
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  
  local_18 = 0xc;
  local_14 = *(undefined4 *)(param_2 + 0x40);
  local_10 = *(undefined4 *)(param_2 + 0x48);
  DeviceIoControl(*(HANDLE *)(param_1 + 0x18),0x71c4c,&local_18,0xc,(LPVOID)0x0,0,aDStack_20,
                  (LPOVERLAPPED)0x0);
  return;
}



/* c03e3c14 FUN_c03e3c14 */

/* Boundary evidence: original MIPS .pdata c03e3c14..c03e3e1f. Semantic name remains unreviewed. */

undefined4 FUN_c03e3c14(int param_1,int param_2)

{
  HLOCAL _Dst;
  BOOL BVar1;
  uint uVar2;
  undefined4 uVar3;
  uint uBytes;
  int iVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  DWORD aDStack_50 [2];
  int local_48;
  uint local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  HLOCAL local_34;
  uint local_30;
  
  uVar3 = 0;
  FUN_c03e3bac(param_1,param_2);
  uBytes = *(uint *)(param_1 + 0x2c);
  _Dst = LocalAlloc(0,uBytes);
  if (_Dst != (HLOCAL)0x0) {
    uVar2 = *(uint *)(param_1 + 0x2c);
    iVar6 = *(int *)(param_2 + 0x40);
    uVar7 = (uVar2 + 0xfff) / uVar2;
    if (uVar2 == 0) {
      trap(0x1c00);
    }
    uVar2 = *(uint *)(param_2 + 0x48) - 1;
    if ((*(int *)(param_2 + 0x4c) + -1 + (uint)(uVar2 < *(uint *)(param_2 + 0x48)) == 0) &&
       (uVar2 < uVar7)) {
      uVar7 = uVar2;
    }
    iVar4 = 0;
    memset(_Dst,0,uBytes);
    uVar3 = 1;
    if (uVar7 != 0) {
      do {
        local_44 = uBytes / *(uint *)(param_1 + 0x2c);
        if (*(uint *)(param_1 + 0x2c) == 0) {
          trap(0x1c00);
        }
        local_40 = 1;
        local_3c = 0;
        local_38 = 0;
        local_48 = iVar6;
        local_34 = _Dst;
        local_30 = uBytes;
        BVar1 = DeviceIoControl(*(HANDLE *)(param_1 + 0x18),0x79c0c,&local_48,0x1c,(LPVOID)0x0,0,
                                aDStack_50,(LPOVERLAPPED)0x0);
        if (BVar1 == 0) {
          BVar1 = DeviceIoControl(*(HANDLE *)(param_1 + 0x18),3,&local_48,0x1c,(LPVOID)0x0,0,
                                  aDStack_50,(LPOVERLAPPED)0x0);
          uVar3 = 0;
          if (BVar1 == 0) break;
        }
        uVar3 = 1;
        uVar2 = uBytes / *(uint *)(param_1 + 0x2c);
        if (*(uint *)(param_1 + 0x2c) == 0) {
          trap(0x1c00);
        }
        uVar5 = uVar7 - uVar2;
        iVar6 = uVar2 + iVar6;
        iVar4 = iVar4 - (uint)(uVar7 < uVar2);
        uVar7 = uVar5;
      } while (uVar5 != 0 || iVar4 != 0);
    }
    LocalFree(_Dst);
  }
  return uVar3;
}



/* c03e3e20 FUN_c03e3e20 */

/* Boundary evidence: original MIPS .pdata c03e3e20..c03e3ebb. Semantic name remains unreviewed. */

void FUN_c03e3e20(int param_1,undefined4 *param_2,undefined4 *param_3,wchar_t *param_4)

{
  wchar_t *_Str2;
  int iVar1;
  wchar_t *pwVar2;
  wchar_t *pwVar3;
  
  pwVar2 = *(wchar_t **)(param_1 + 0x40);
  *param_2 = 0;
  pwVar3 = (wchar_t *)0x0;
  if (param_3 != (undefined4 *)0x0) {
    *param_3 = 0;
  }
  while( true ) {
    _Str2 = pwVar2;
    if (_Str2 == (wchar_t *)0x0) {
      return;
    }
    iVar1 = _wcsicmp(param_4,_Str2);
    if (iVar1 == 0) break;
    pwVar2 = *(wchar_t **)(_Str2 + 0x38);
    pwVar3 = _Str2;
  }
  *param_2 = _Str2;
  if (param_3 == (undefined4 *)0x0) {
    return;
  }
  *param_3 = pwVar3;
  return;
}



/* c03e3ebc FUN_c03e3ebc */

/* Boundary evidence: original MIPS .pdata c03e3ebc..c03e42c3. Semantic name remains unreviewed. */

DWORD FUN_c03e3ebc(int param_1,int *param_2,int param_3,int param_4,uint *param_5,int param_6)

{
  HLOCAL pvVar1;
  DWORD DVar2;
  int *piVar3;
  uint *puVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  byte *pbVar8;
  byte *pbVar9;
  byte *pbVar10;
  int iVar11;
  int local_34;
  HLOCAL local_30 [2];
  
  if (param_6 < 0x19) {
    iVar11 = 2;
    if (param_4 == 0) {
      iVar11 = 4;
    }
    if (*(short *)(param_3 + 0x1fe) == -0x55ab) {
      iVar7 = 0;
      pbVar10 = (byte *)(param_3 + 0x1be);
      if (iVar11 != 0) {
        puVar4 = (uint *)(param_3 + 0x1c6);
        uVar5 = 0;
        do {
          uVar6 = uVar5;
          if (puVar4[1] != 0) {
            uVar6 = *puVar4;
            if (uVar6 == 0) break;
            if (uVar6 < uVar5) {
              return 0xd;
            }
            if (*(uint *)(param_1 + 0x28) <= uVar6) {
              return 0xd;
            }
          }
          iVar7 = iVar7 + 1;
          puVar4 = puVar4 + 4;
          uVar5 = uVar6;
        } while (iVar7 < iVar11);
        if (uVar5 != 0) {
          local_34 = 0;
          piVar3 = param_2;
          do {
            pbVar9 = pbVar10 + 4;
            pbVar8 = pbVar10 + 0xc;
            if (*(int *)pbVar8 != 0) {
              puVar4 = (uint *)(pbVar10 + 8);
              uVar5 = *puVar4;
              if (*(uint *)(param_1 + 0x28) < *(int *)pbVar8 + uVar5) {
                *(uint *)pbVar8 = *(uint *)(param_1 + 0x28) - uVar5;
              }
              if ((((param_4 != 0) && (local_34 == 1)) && (*pbVar9 != 5)) && (*pbVar9 != 0xf)) {
                return 0;
              }
              if ((*pbVar9 == 5) || (*pbVar9 == 0xf)) {
                uVar6 = uVar5 + *(int *)(param_1 + 0x50);
                local_30[0] = (HLOCAL)0x0;
                iVar7 = FUN_c03e3088(param_1,piVar3,uVar6,
                                     *(int *)(param_1 + 0x54) + (uint)(uVar6 < uVar5),1,0,
                                     (int *)local_30);
                pvVar1 = local_30[0];
                if (iVar7 == 0) {
                  DVar2 = GetLastError();
                  return DVar2;
                }
                if (param_4 == 0) {
                  if (*(int *)(param_1 + 0x50) != 0 || *(int *)(param_1 + 0x54) != 0) {
                    LocalFree(local_30[0]);
                    return 0xd;
                  }
                  *(uint *)(param_1 + 0x50) = *puVar4;
                  *(undefined4 *)(param_1 + 0x54) = 0;
                  uVar5 = *puVar4;
                  iVar7 = *(int *)pbVar8;
                  *(undefined4 *)(param_1 + 0x5c) = 0;
                  *(uint *)(param_1 + 0x58) = uVar5 + iVar7 + -1;
                  *param_5 = *puVar4;
                  param_5[1] = 0;
                }
                else {
                  uVar6 = *puVar4;
                  iVar7 = *(int *)(param_1 + 0x54);
                  uVar5 = uVar6 + *(int *)(param_1 + 0x50);
                  *param_5 = uVar5;
                  param_5[1] = iVar7 + (uint)(uVar5 < uVar6);
                }
                piVar3 = param_2;
                DVar2 = FUN_c03e3ebc(param_1,param_2,(int)local_30[0],1,param_5,param_6 + 1);
                LocalFree(pvVar1);
                if (DVar2 != 0) {
                  return DVar2;
                }
                if (param_4 == 0) {
                  *param_5 = 0;
                  param_5[1] = 0;
                }
              }
              else {
                piVar3 = (int *)0x80;
                pvVar1 = LocalAlloc(0x40,0x80);
                if (pvVar1 == (HLOCAL)0x0) {
                  return 8;
                }
                uVar5 = *puVar4 + *param_5;
                *(uint *)((int)pvVar1 + 0x44) = param_5[1] + (uint)(uVar5 < *puVar4);
                *(uint *)((int)pvVar1 + 0x40) = uVar5;
                *(undefined4 *)((int)pvVar1 + 0x48) = *(undefined4 *)pbVar8;
                *(undefined4 *)((int)pvVar1 + 0x4c) = 0;
                *(byte *)((int)pvVar1 + 0x78) = *pbVar9;
                if ((*pbVar10 & 0x80) != 0) {
                  *(uint *)((int)pvVar1 + 0x60) = *(uint *)((int)pvVar1 + 0x60) | 8;
                }
                if ((*pbVar10 & 2) != 0) {
                  *(uint *)((int)pvVar1 + 0x60) = *(uint *)((int)pvVar1 + 0x60) | 2;
                }
                *(uint *)((int)pvVar1 + 0x68) = *param_5;
                *(uint *)((int)pvVar1 + 0x6c) = param_5[1];
                if (*(int *)(param_1 + 0x40) == 0) {
                  *(HLOCAL *)(param_1 + 0x40) = pvVar1;
                }
                else {
                  *(HLOCAL *)(*param_2 + 0x70) = pvVar1;
                }
                *(int *)((int)pvVar1 + 0x74) = param_1;
                *param_2 = (int)pvVar1;
                if (*pbVar9 == 0x18) {
                  *(HLOCAL *)(param_1 + 0x48) = pvVar1;
                }
                else {
                  *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + 1;
                }
              }
            }
            local_34 = local_34 + 1;
            pbVar10 = pbVar10 + 0x10;
            if (iVar11 <= local_34) {
              return 0;
            }
          } while( true );
        }
      }
    }
    else if (param_4 != 0) {
      return 0;
    }
  }
  return 0xd;
}



/* c03e42c4 FUN_c03e42c4 */

/* Boundary evidence: original MIPS .pdata c03e42c4..c03e458f. Semantic name remains unreviewed. */

void FUN_c03e42c4(int param_1,wchar_t *param_2)

{
  char cVar1;
  char cVar2;
  char *hMem;
  int iVar3;
  size_t sVar4;
  char *_Src;
  wchar_t *_Dest;
  uint cbMultiByte;
  LPWSTR lpWideCharStr;
  int _Value;
  char *local_88;
  int local_84;
  CHAR local_80 [16];
  wchar_t awStack_70 [4];
  wchar_t local_68;
  wchar_t awStack_66 [27];
  uint local_30;
  
  lpWideCharStr = *(LPWSTR *)(param_1 + 0x40);
  _Value = 0;
  local_30 = DAT_c03e6074;
joined_r0xc03e4304:
  do {
    if (lpWideCharStr == (LPWSTR)0x0) {
LAB_c03e4558:
      FUN_c03e58a8(local_30);
      return;
    }
    cVar1 = (char)lpWideCharStr[0x3c];
    if ((cVar1 != '\x18') && (*lpWideCharStr == L'\0')) {
      if (((cVar1 == '\x01') || (((cVar1 == '\x04' || (cVar1 == '\x06')) || (cVar1 == '\v')))) ||
         ((cVar1 == '\f' || (cVar1 == '\x0e')))) {
        local_88 = (char *)0x0;
        iVar3 = FUN_c03e3088(*(int *)(lpWideCharStr + 0x3a),param_2,
                             *(undefined4 *)(lpWideCharStr + 0x20),
                             *(undefined4 *)(lpWideCharStr + 0x22),1,0,(int *)&local_88);
        hMem = local_88;
        if (iVar3 == 0) goto LAB_c03e4558;
        if ((*(short *)(local_88 + 0x1fe) == -0x55ab) &&
           (((cVar2 = *local_88, cVar2 == -0x70 || (cVar2 == -0x15)) || (cVar2 == -0x17)))) {
          if ((((cVar1 == '\x01') || (cVar1 == '\x04')) || (cVar1 == '\x06')) ||
             (_Src = local_88 + 0x47, cVar1 == '\x0e')) {
            _Src = local_88 + 0x2b;
          }
          memcpy(local_80,_Src,0xb);
          iVar3 = memcmp(local_80,"NO NAME",7);
          if (iVar3 != 0) {
            cbMultiByte = 0;
            do {
              if ((local_80[cbMultiByte] == '\0') || (local_80[cbMultiByte] == ' ')) break;
              cbMultiByte = cbMultiByte + 1;
            } while (cbMultiByte < 0xb);
            if (cbMultiByte != 0) {
              param_2 = (wchar_t *)0x1;
              MultiByteToWideChar(0,1,local_80,cbMultiByte,lpWideCharStr,0x20);
              lpWideCharStr = *(LPWSTR *)(lpWideCharStr + 0x38);
              LocalFree(hMem);
              goto joined_r0xc03e4304;
            }
          }
        }
        LocalFree(hMem);
      }
      do {
        memset(awStack_70,0,0x40);
        wcscpy(awStack_70,L"Part");
        _Dest = &local_68;
        if (_Value < 10) {
          local_68 = L'0';
          _Dest = awStack_66;
        }
        _itow(_Value,_Dest,10);
        _Value = _Value + 1;
        FUN_c03e3e20(param_1,&local_84,(undefined4 *)0x0,awStack_70);
      } while (local_84 != 0);
      sVar4 = wcslen(awStack_70);
      param_2 = awStack_70;
      memcpy(lpWideCharStr,param_2,sVar4 << 1);
    }
    lpWideCharStr = *(LPWSTR *)(lpWideCharStr + 0x38);
  } while( true );
}



/* c03e4590 FUN_c03e4590 */

/* Boundary evidence: original MIPS .pdata c03e4590..c03e4acb. Semantic name remains unreviewed. */

undefined4 FUN_c03e4590(int param_1,uint *param_2,uint *param_3)

{
  uint *puVar1;
  int *piVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  HLOCAL pvVar6;
  uint uVar7;
  uint uVar8;
  int *piVar9;
  int iVar10;
  undefined4 uVar11;
  HLOCAL pvVar12;
  uint uVar13;
  HLOCAL local_20;
  uint local_1c;
  
  *param_3 = 0;
  param_3[1] = 0;
  *param_2 = 0;
  param_2[1] = 0;
  uVar7 = *(uint *)(param_1 + 0x50);
  uVar13 = *(uint *)(param_1 + 0x54);
  if (uVar7 != 0 || uVar13 != 0) {
    iVar10 = *(int *)(param_1 + 0x40);
    if (iVar10 != 0) {
      do {
        if (*(int *)(iVar10 + 0x68) != 0 || *(int *)(iVar10 + 0x6c) != 0) break;
        iVar10 = *(int *)(iVar10 + 0x70);
      } while (iVar10 != 0);
      if (iVar10 != 0) {
        do {
          uVar3 = *(uint *)(iVar10 + 0x68);
          if (uVar3 == 0 && *(int *)(iVar10 + 0x6c) == 0) break;
          pvVar12 = (HLOCAL)(uVar3 - uVar7);
          uVar8 = *param_2 + (int)pvVar12;
          local_1c = (*(int *)(iVar10 + 0x6c) - uVar13) - (uint)(uVar3 < uVar7);
          param_2[1] = param_2[1] + local_1c + (uint)(uVar8 < *param_2);
          *param_2 = uVar8;
          local_20 = pvVar12;
          if (pvVar12 != (HLOCAL)0x0 || local_1c != 0) {
            if (*(uint *)(param_1 + 0x34) < 2) {
              local_20 = (HLOCAL)((int)pvVar12 - 1);
              local_1c = (local_1c - 1) + (uint)(local_20 < pvVar12);
            }
            else {
              local_20 = (HLOCAL)((int)pvVar12 - (int)*(HLOCAL *)(param_1 + 0x38));
              local_1c = local_1c - (pvVar12 < *(HLOCAL *)(param_1 + 0x38));
            }
          }
          if ((param_3[1] <= local_1c) &&
             ((local_1c != param_3[1] || ((HLOCAL)*param_3 < local_20)))) {
            *param_3 = (uint)local_20;
            param_3[1] = local_1c;
          }
          puVar1 = (uint *)(iVar10 + 0x48);
          piVar9 = (int *)(iVar10 + 0x4c);
          piVar2 = (int *)(iVar10 + 0x44);
          uVar7 = *puVar1 + *(int *)(iVar10 + 0x40);
          iVar10 = *(int *)(iVar10 + 0x70);
          uVar13 = *piVar9 + *piVar2 + (uint)(uVar7 < *puVar1);
        } while (iVar10 != 0);
        uVar8 = *(uint *)(param_1 + 0x5c);
        uVar3 = *(uint *)(param_1 + 0x58);
        if ((uVar13 <= uVar8) && ((uVar8 != uVar13 || (uVar7 < uVar3)))) {
          local_20 = (HLOCAL)((int)(uVar3 - uVar7) + 1);
          uVar5 = *param_2;
          local_1c = ((uVar8 - uVar13) - (uint)(uVar3 < uVar7)) +
                     (uint)(local_20 < (HLOCAL)(uVar3 - uVar7));
          uVar7 = uVar5 + (int)local_20;
          *param_2 = uVar7;
          param_2[1] = param_2[1] + local_1c + (uint)(uVar7 < uVar5);
        }
        pvVar12 = local_20;
        if (local_20 != (HLOCAL)0x0 || local_1c != 0) {
          if ((*(uint *)(param_1 + 0x34) < 2) ||
             ((pvVar6 = *(HLOCAL *)(param_1 + 0x38), local_1c == 0 && (local_20 < pvVar6)))) {
            pvVar12 = (HLOCAL)((int)local_20 - 1);
            local_1c = (local_1c - 1) + (uint)(pvVar12 < local_20);
          }
          else {
            pvVar12 = (HLOCAL)((int)local_20 - (int)pvVar6);
            local_1c = local_1c - (local_20 < pvVar6);
          }
        }
        if ((param_3[1] <= local_1c) && ((local_1c != param_3[1] || ((HLOCAL)*param_3 < pvVar12))))
        {
          *param_3 = (uint)pvVar12;
          param_3[1] = local_1c;
        }
        goto LAB_c03e4858;
      }
    }
    uVar3 = *(uint *)(param_1 + 0x58) - uVar7;
    uVar8 = uVar3 + 1;
    uVar7 = ((*(int *)(param_1 + 0x5c) - uVar13) - (uint)(*(uint *)(param_1 + 0x58) < uVar7)) +
            (uint)(uVar8 < uVar3);
    *param_2 = uVar8;
    param_2[1] = uVar7;
    if (*(uint *)(param_1 + 0x34) < 2) {
      uVar13 = *param_2 - 1;
      uVar7 = (param_2[1] - 1) + (uint)(uVar13 < *param_2);
      *param_3 = uVar13;
    }
    else {
      uVar13 = *(uint *)(param_1 + 0x38);
      *param_3 = uVar8 - uVar13;
      uVar7 = uVar7 - (uVar8 < uVar13);
    }
    param_3[1] = uVar7;
  }
LAB_c03e4858:
  uVar11 = 1;
  local_20 = (HLOCAL)0x0;
  iVar10 = FUN_c03e3088(param_1,param_2,0,0,1,0,(int *)&local_20);
  if (iVar10 == 0) {
    uVar11 = 0;
  }
  else {
    if (*(int *)((int)local_20 + 0x1fa) == 0) {
      if (1 < *(byte *)((int)local_20 + 0x1c1)) {
        if (*(uint *)(param_1 + 0x34) < 2) {
          uVar13 = *(int *)((int)local_20 + 0x1c6) - 1;
          uVar7 = 0;
        }
        else {
          uVar7 = (uint)*(byte *)((int)local_20 + 0x1bf) * *(int *)(param_1 + 0x38);
          uVar3 = *(int *)((int)local_20 + 0x1c6) - *(int *)(param_1 + 0x38);
          uVar13 = uVar3 - uVar7;
          uVar7 = -(uint)(uVar3 < uVar7);
        }
        uVar3 = *param_2;
        uVar8 = uVar3 + uVar13;
        *param_2 = uVar8;
        param_2[1] = param_2[1] + uVar7 + (uint)(uVar8 < uVar3);
        if ((param_3[1] <= uVar7) && ((uVar7 != param_3[1] || (*param_3 < uVar13)))) {
          *param_3 = uVar13;
          param_3[1] = uVar7;
        }
      }
      iVar10 = 0;
      piVar9 = (int *)((int)local_20 + 0x1c6);
      do {
        iVar4 = piVar9[1];
        if (iVar4 == 0) {
          if ((((*(uint *)(param_1 + 0x24) & 1) != 0) && (iVar10 == 0)) &&
             (*(int *)(param_1 + 0x1c) != 0)) {
            if (*(uint *)(param_1 + 0x34) < 2) {
              *param_2 = *(int *)(param_1 + 0x28) - 1;
            }
            else {
              *param_2 = *(int *)(param_1 + 0x28) - *(int *)(param_1 + 0x38);
            }
            param_2[1] = 0;
            *param_3 = *param_2;
            param_3[1] = param_2[1];
          }
          break;
        }
        if (piVar9[5] == 0) {
          if ((uint)(iVar4 + *piVar9) < *(uint *)(param_1 + 0x28)) {
            uVar7 = (*(uint *)(param_1 + 0x28) - iVar4) - *piVar9;
          }
          else {
            uVar7 = 0;
          }
        }
        else {
          uVar7 = (piVar9[4] - iVar4) - *piVar9;
        }
        uVar13 = *param_2;
        uVar3 = uVar13 + uVar7;
        *param_2 = uVar3;
        param_2[1] = param_2[1] + (uint)(uVar3 < uVar13);
        if ((param_3[1] == 0) && (*param_3 < uVar7)) {
          *param_3 = uVar7;
          param_3[1] = 0;
        }
        iVar10 = iVar10 + 1;
        piVar9 = piVar9 + 4;
      } while (iVar10 < 4);
    }
    LocalFree(local_20);
  }
  return uVar11;
}



/* c03e4acc FUN_c03e4acc */

/* Boundary evidence: original MIPS .pdata c03e4acc..c03e4e8b. Semantic name remains unreviewed. */

undefined4
FUN_c03e4acc(uint param_1,undefined4 param_2,int param_3,int param_4,uint param_5,int param_6,
            uint param_7,int param_8,int param_9,int param_10,undefined1 param_11)

{
  bool bVar1;
  HLOCAL pvVar2;
  int iVar3;
  SIZE_T uBytes;
  int *piVar4;
  uint uVar5;
  uint uVar6;
  HLOCAL local_38;
  int local_34;
  int local_30;
  uint local_2c;
  
  if (*(uint *)(param_1 + 0x34) < 2) {
    uVar6 = param_7 + 1;
    bVar1 = uVar6 < param_7;
  }
  else {
    uVar6 = *(uint *)(param_1 + 0x38) + param_7;
    bVar1 = uVar6 < *(uint *)(param_1 + 0x38);
  }
  uBytes = *(SIZE_T *)(param_1 + 0x2c);
  local_34 = param_3;
  pvVar2 = LocalAlloc(0x40,uBytes);
  if (pvVar2 != (HLOCAL)0x0) {
    *(undefined2 *)((int)pvVar2 + 0x1fe) = 0xaa55;
    FUN_c03e3af8(param_1,uBytes,uVar6,param_8 + (uint)bVar1,(undefined1 *)((int)pvVar2 + 0x1c1),
                 (char *)((int)pvVar2 + 0x1bf),(byte *)((int)pvVar2 + 0x1c0));
    uVar6 = param_7 + param_9;
    local_2c = uVar6 - 1;
    local_30 = param_8 + param_10 + (uint)(uVar6 < param_7) + -1 + (uint)(local_2c < uVar6);
    FUN_c03e3af8(param_1,uBytes,local_2c,local_30,(undefined1 *)((int)pvVar2 + 0x1c5),
                 (char *)((int)pvVar2 + 0x1c3),(byte *)((int)pvVar2 + 0x1c4));
    *(undefined1 *)((int)pvVar2 + 0x1c2) = param_11;
    piVar4 = (int *)((int)pvVar2 + 0x1c6);
    if (*(uint *)(param_1 + 0x34) < 2) {
      *piVar4 = 1;
    }
    else {
      *piVar4 = *(int *)(param_1 + 0x38);
    }
    *(int *)((int)pvVar2 + 0x1ca) = param_9 - *piVar4;
    if (param_5 != 0 || param_6 != 0) {
      local_38 = (HLOCAL)0x0;
      iVar3 = FUN_c03e3088(param_1,uBytes,param_5,param_6,1,0,(int *)&local_38);
      if (iVar3 == 0) {
        LocalFree(pvVar2);
        return 0;
      }
      *(uint *)((int)pvVar2 + 0x1d6) = param_5 - *(int *)(param_1 + 0x50);
      *(uint *)((int)pvVar2 + 0x1da) = *(int *)((int)pvVar2 + 0x1ca) + *(int *)((int)pvVar2 + 0x1c6)
      ;
      FUN_c03e3af8(param_1,uBytes,param_5,param_6,(undefined1 *)((int)pvVar2 + 0x1d1),
                   (char *)((int)pvVar2 + 0x1cf),(byte *)((int)pvVar2 + 0x1d0));
      uVar6 = *(uint *)((int)pvVar2 + 0x1da);
      uVar5 = uVar6 + param_5;
      FUN_c03e3af8(param_1,uBytes,uVar5 - 1,
                   param_6 + (uint)(uVar5 < uVar6) + -1 + (uint)(uVar5 - 1 < uVar5),
                   (undefined1 *)((int)pvVar2 + 0x1d5),(char *)((int)pvVar2 + 0x1d3),
                   (byte *)((int)pvVar2 + 0x1d4));
      *(undefined1 *)((int)pvVar2 + 0x1d2) = 5;
      LocalFree(local_38);
      param_3 = local_34;
    }
    iVar3 = FUN_c03e2fb8(param_1,uBytes,param_7,param_8,1,0,pvVar2);
    LocalFree(pvVar2);
    if (iVar3 != 0) {
      if (param_3 == 0 && param_4 == 0) {
        return 1;
      }
      local_38 = (HLOCAL)0x0;
      iVar3 = FUN_c03e3088(param_1,uBytes,param_3,param_4,1,0,(int *)&local_38);
      pvVar2 = local_38;
      if (iVar3 != 0) {
        FUN_c03e3af8(param_1,uBytes,param_7,param_8,(undefined1 *)((int)local_38 + 0x1d1),
                     (char *)((int)local_38 + 0x1cf),(byte *)((int)local_38 + 0x1d0));
        iVar3 = (int)pvVar2 + 0x1d4;
        FUN_c03e3af8(param_1,iVar3,local_2c,local_30,(undefined1 *)((int)pvVar2 + 0x1d5),
                     (char *)((int)pvVar2 + 0x1d3),(byte *)iVar3);
        *(undefined1 *)((int)pvVar2 + 0x1d2) = 5;
        *(uint *)((int)pvVar2 + 0x1d6) = param_7 - *(int *)(param_1 + 0x50);
        *(int *)((int)pvVar2 + 0x1da) = param_9;
        iVar3 = FUN_c03e2fb8(param_1,iVar3,local_34,param_4,1,0,pvVar2);
        LocalFree(pvVar2);
        if (iVar3 != 0) {
          return 1;
        }
      }
    }
  }
  return 0;
}



/* c03e4e8c FUN_c03e4e8c */

/* Boundary evidence: original MIPS .pdata c03e4e8c..c03e501f. Semantic name remains unreviewed. */

undefined4 FUN_c03e4e8c(uint param_1,int param_2,int param_3)

{
  HLOCAL hMem;
  int iVar1;
  int iVar2;
  void *_Src;
  undefined4 uVar3;
  HLOCAL _Dst;
  HLOCAL local_28;
  HLOCAL local_24;
  
  local_28 = (HLOCAL)0x0;
  iVar2 = param_2;
  iVar1 = FUN_c03e3088(param_1,param_2,*(undefined4 *)(param_2 + 0x68),
                       *(undefined4 *)(param_2 + 0x6c),1,0,(int *)&local_28);
  _Dst = local_28;
  if (iVar1 == 0) {
LAB_c03e4ee8:
    LocalFree(local_28);
    return 0;
  }
  if (param_3 != 0) {
    if (*(int *)(param_3 + 0x68) != 0 || *(int *)(param_3 + 0x6c) != 0) {
      local_24 = (HLOCAL)0x0;
      iVar2 = FUN_c03e3088(param_1,iVar2,*(int *)(param_3 + 0x68),*(int *)(param_3 + 0x6c),1,0,
                           (int *)&local_24);
      hMem = local_24;
      _Dst = local_28;
      if (iVar2 == 0) goto LAB_c03e4ee8;
      _Src = (void *)((int)local_28 + 0x1ce);
      memcpy((void *)((int)local_24 + 0x1ce),_Src,0x10);
      iVar2 = FUN_c03e2fb8(param_1,_Src,*(undefined4 *)(param_3 + 0x68),
                           *(undefined4 *)(param_3 + 0x6c),1,0,hMem);
      LocalFree(hMem);
      if (iVar2 == 0) {
        uVar3 = 0;
      }
      else {
        uVar3 = 0;
        memset(_Dst,0,*(size_t *)(param_1 + 0x2c));
        uVar3 = FUN_c03e2fb8(param_1,uVar3,*(undefined4 *)(param_2 + 0x68),
                             *(undefined4 *)(param_2 + 0x6c),1,0,_Dst);
      }
      goto LAB_c03e4ff0;
    }
  }
  uVar3 = 0;
  memset((void *)((int)local_28 + 0x1be),0,0x10);
  uVar3 = FUN_c03e2fb8(param_1,uVar3,*(undefined4 *)(param_2 + 0x68),*(undefined4 *)(param_2 + 0x6c)
                       ,1,0,_Dst);
LAB_c03e4ff0:
  LocalFree(_Dst);
  return uVar3;
}



/* c03e5020 FUN_c03e5020 */

/* Boundary evidence: original MIPS .pdata c03e5020..c03e51af. Semantic name remains unreviewed. */

undefined4 FUN_c03e5020(uint param_1,int param_2)

{
  uint uVar1;
  uint *puVar2;
  HLOCAL hMem;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  HLOCAL local_20 [2];
  
  local_20[0] = (HLOCAL)0x0;
  iVar5 = param_2;
  iVar3 = FUN_c03e3088(param_1,param_2,0,0,1,0,(int *)local_20);
  hMem = local_20[0];
  if (iVar3 != 0) {
    iVar3 = 0;
    iVar7 = (int)local_20[0] + 0x1be;
    do {
      if ((*(uint *)(iVar7 + 8) == *(uint *)(param_2 + 0x40)) && (*(int *)(param_2 + 0x44) == 0))
      break;
      iVar3 = iVar3 + 1;
      iVar7 = iVar7 + 0x10;
    } while (iVar3 < 4);
    if (iVar3 < 4) {
      FUN_c03e3af8(param_1,iVar5,*(uint *)(param_2 + 0x40),0,(undefined1 *)(iVar7 + 3),
                   (char *)(iVar7 + 1),(byte *)(iVar7 + 2));
      *(undefined1 *)(iVar7 + 4) = *(undefined1 *)(param_2 + 0x78);
      *(int *)(iVar7 + 8) = *(int *)(param_2 + 0x40);
      uVar6 = *(uint *)(param_2 + 0x48);
      iVar3 = *(int *)(iVar7 + 8);
      uVar1 = iVar7 + 0xfU & 3;
      puVar2 = (uint *)((iVar7 + 0xfU) - uVar1);
      *puVar2 = *puVar2 & -1 << (uVar1 + 1) * 8 | uVar6 >> (3 - uVar1) * 8;
      uVar1 = iVar7 + 0xcU & 3;
      puVar2 = (uint *)((iVar7 + 0xcU) - uVar1);
      *puVar2 = *puVar2 & 0xffffffffU >> (4 - uVar1) * 8 | uVar6 << uVar1 * 8;
      FUN_c03e3af8(param_1,iVar5,(uVar6 + iVar3) - 1,0,(undefined1 *)(iVar7 + 7),(char *)(iVar7 + 5)
                   ,(byte *)(iVar7 + 6));
      uVar4 = FUN_c03e2fb8(param_1,iVar5,0,0,1,0,hMem);
      LocalFree(hMem);
      return uVar4;
    }
    LocalFree(local_20[0]);
    SetLastError(0x1f);
  }
  return 0;
}



/* c03e51b0 FUN_c03e51b0 */

/* Boundary evidence: original MIPS .pdata c03e51b0..c03e534b. Semantic name remains unreviewed. */

undefined4 FUN_c03e51b0(uint param_1,int param_2)

{
  HLOCAL hMem;
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  void *_Dst;
  void *_Src;
  HLOCAL local_28 [2];
  
  local_28[0] = (HLOCAL)0x0;
  iVar5 = -1;
  iVar1 = FUN_c03e3088(param_1,param_2,0,0,1,0,(int *)local_28);
  hMem = local_28[0];
  if (iVar1 != 0) {
    iVar4 = 0;
    iVar1 = 3;
    piVar3 = (int *)((int)local_28[0] + 0x1c6);
    do {
      if ((*piVar3 == *(int *)(param_2 + 0x40)) && (*(int *)(param_2 + 0x44) == 0)) {
        iVar5 = iVar4;
      }
      if (piVar3[1] == 0) {
        iVar1 = iVar4 + -1;
        break;
      }
      iVar4 = iVar4 + 1;
      piVar3 = piVar3 + 4;
    } while (iVar4 < 4);
    if ((iVar5 != -1) && (iVar1 != -1)) {
      _Dst = (void *)((int)local_28[0] + iVar5 * 0x10 + 0x1be);
      _Src = (void *)((int)local_28[0] + iVar5 * 0x10 + 0x1ce);
      if (iVar5 < iVar1) {
        iVar1 = iVar1 - iVar5;
        do {
          memcpy(_Dst,_Src,0x10);
          _Dst = (void *)((int)_Dst + 0x10);
          iVar1 = iVar1 + -1;
          _Src = (void *)((int)_Src + 0x10);
        } while (iVar1 != 0);
      }
      uVar2 = 0;
      memset(_Dst,0,0x10);
      uVar2 = FUN_c03e2fb8(param_1,uVar2,0,0,1,0,hMem);
      LocalFree(hMem);
      return uVar2;
    }
    LocalFree(local_28[0]);
    SetLastError(0x1f);
  }
  return 0;
}



/* c03e534c FUN_c03e534c */

/* Boundary evidence: original MIPS .pdata c03e534c..c03e55a3. Semantic name remains unreviewed. */

int FUN_c03e534c(uint param_1,undefined1 *param_2,uint param_3,int param_4,int param_5,
                undefined4 param_6,undefined1 param_7,int param_8)

{
  int iVar1;
  undefined1 *hMem;
  uint *puVar2;
  int iVar3;
  undefined1 *_Dst;
  undefined1 *_Src;
  undefined1 *local_30 [2];
  
  local_30[0] = (undefined1 *)0x0;
  if (param_8 == 0) {
    iVar1 = FUN_c03e3088(param_1,param_2,0,0,1,0,(int *)local_30);
    hMem = local_30[0];
    iVar3 = 0;
    if (iVar1 != 0) {
      iVar1 = 0;
      puVar2 = (uint *)(local_30[0] + 0x1c6);
      do {
        if (puVar2[1] == 0) {
          if (iVar3 != -1) {
            if (iVar1 != iVar3) {
              _Dst = local_30[0] + iVar3 * 0x10 + 0x1be;
              if (iVar1 < iVar3) {
                iVar1 = iVar3 - iVar1;
                _Src = local_30[0] + iVar3 * 0x10 + 0x1ae;
                iVar3 = iVar3 - iVar1;
                do {
                  param_2 = _Src;
                  memcpy(_Dst,_Src,0x10);
                  _Dst = _Dst + -0x10;
                  iVar1 = iVar1 + -1;
                  _Src = _Src + -0x10;
                } while (iVar1 != 0);
              }
            }
            goto LAB_c03e54cc;
          }
          break;
        }
        if ((param_4 != 0) || (*puVar2 < param_3)) {
          iVar1 = iVar3 + 1;
        }
        iVar3 = iVar3 + 1;
        puVar2 = puVar2 + 4;
      } while (iVar3 < 4);
      LocalFree(local_30[0]);
      SetLastError(0x70);
      iVar3 = 0;
    }
  }
  else {
    param_2 = *(undefined1 **)(param_1 + 0x2c);
    hMem = LocalAlloc(0x40,(SIZE_T)param_2);
    iVar3 = 0;
    if (hMem != (undefined1 *)0x0) {
      *(undefined2 *)(hMem + 0x1fe) = 0xaa55;
      *hMem = 0xe9;
      hMem[1] = 0xfd;
      hMem[2] = 0xff;
LAB_c03e54cc:
      FUN_c03e3af8(param_1,param_2,param_3,param_4,hMem + iVar3 * 0x10 + 0x1c1,
                   hMem + iVar3 * 0x10 + 0x1bf,hMem + iVar3 * 0x10 + 0x1c0);
      *(int *)(hMem + iVar3 * 0x10 + 0x1ca) = param_5;
      hMem[iVar3 * 0x10 + 0x1c2] = param_7;
      *(uint *)(hMem + iVar3 * 0x10 + 0x1c6) = param_3;
      FUN_c03e3af8(param_1,param_2,(param_5 + param_3) - 1,0,hMem + iVar3 * 0x10 + 0x1c5,
                   hMem + iVar3 * 0x10 + 0x1c3,hMem + iVar3 * 0x10 + 0x1c4);
      iVar3 = FUN_c03e2fb8(param_1,param_2,0,0,1,0,hMem);
      LocalFree(hMem);
    }
  }
  return iVar3;
}



/* c03e55f4 FUN_c03e55f4 */

/* Boundary evidence: original MIPS .pdata c03e55f4..c03e572f. Semantic name remains unreviewed. */

int FUN_c03e55f4(HMODULE param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 1;
  if (param_2 == 1) {
    if (DAT_c03e608c != (code *)0x0) {
      iVar2 = (*DAT_c03e608c)(param_1,1,param_3);
    }
    iVar1 = 0;
    if (iVar2 == 0) goto LAB_c03e56a4;
    FUN_c03e5a88();
  }
  iVar1 = 0;
  if (iVar2 != 0) {
    iVar1 = FUN_c03e2d68(param_1,param_2);
  }
LAB_c03e56a4:
  if (((param_2 == 0) && (FUN_c03e5a10(), iVar1 != 0)) && (DAT_c03e608c != (code *)0x0)) {
    iVar1 = (*DAT_c03e608c)(param_1,0,param_3);
  }
  return iVar1;
}



/* c03e5730 FUN_c03e5730 */

/* Boundary evidence: original MIPS .pdata c03e5730..c03e575b. Semantic name remains unreviewed. */

void FUN_c03e5730(_EXCEPTION_POINTERS *param_1)

{
  _XcptFilter(param_1->ExceptionRecord->ExceptionCode,param_1);
  return;
}



/* c03e575c entry */

/* Boundary evidence: original MIPS .pdata c03e575c..c03e57b3. Semantic name remains unreviewed. */

void entry(HMODULE param_1,int param_2,undefined4 param_3)

{
  if (param_2 == 1) {
    FUN_c03e57b4();
  }
  FUN_c03e55f4(param_1,param_2,param_3);
  return;
}



/* c03e57b4 FUN_c03e57b4 */

/* Boundary evidence: original MIPS .pdata c03e57b4..c03e5827. Semantic name remains unreviewed. */

void FUN_c03e57b4(void)

{
  uint uVar1;
  
  if ((DAT_c03e6074 == 0) || (DAT_c03e6074 == 0xb064)) {
    uVar1 = __security_gen_cookie2();
    DAT_c03e6074 = uVar1 >> 0x10 ^ uVar1 & 0xffff;
    if (DAT_c03e6074 == 0) {
      DAT_c03e6074 = 0xb064;
    }
  }
  DAT_c03e6078 = ~DAT_c03e6074;
  return;
}



/* c03e5828 FUN_c03e5828 */

/* Boundary evidence: original MIPS .pdata c03e5828..c03e587b. Semantic name remains unreviewed. */

void FUN_c03e5828(int param_1,undefined4 param_2,uint *param_3)

{
  if ((*param_3 & 1) != 0) {
    param_1 = ((-param_3[2] & param_3[1] + param_1) - (param_3[1] + param_1)) + param_1;
  }
  FUN_c03e58a8(*(uint *)(param_1 + (*param_3 & 0xfffffffc)));
  return;
}



/* c03e587c FUN_c03e587c */

/* Boundary evidence: original MIPS .pdata c03e587c..c03e58a7. Semantic name remains unreviewed. */

undefined4 FUN_c03e587c(undefined4 param_1,int param_2,undefined4 param_3,int param_4)

{
  FUN_c03e5828(param_2,param_4,*(uint **)(*(int *)(param_4 + 4) + 0xc));
  return 1;
}



/* c03e58a8 FUN_c03e58a8 */

/* Boundary evidence: original MIPS .pdata c03e58a8..c03e58ef. Semantic name remains unreviewed. */

void FUN_c03e58a8(uint param_1)

{
  if ((param_1 == DAT_c03e6074) && (param_1 >> 0x10 == 0)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __report_gsfailure();
}



/* c03e58f0 FUN_c03e58f0 */

/* Boundary evidence: original MIPS .pdata c03e58f0..c03e5a0f. Semantic name remains unreviewed. */

void FUN_c03e58f0(UINT param_1,int param_2,int param_3)

{
  LPCRITICAL_SECTION lpCriticalSection;
  undefined4 *_Memory;
  
  DAT_c03e607c = (undefined1)param_3;
  if (param_2 == 0) {
    _Memory = DAT_c03e6084;
    if (DAT_c03e6084 != (undefined4 *)0x0) {
      while (DAT_c03e6080 = DAT_c03e6080 + -1, _Memory <= DAT_c03e6080) {
        if ((code *)*DAT_c03e6080 != (code *)0x0) {
          (*(code *)*DAT_c03e6080)();
          _Memory = DAT_c03e6084;
        }
      }
      free(_Memory);
      DAT_c03e6080 = (undefined4 *)0x0;
      DAT_c03e6084 = (undefined4 *)0x0;
    }
    FUN_c03e5a34((undefined4 *)&DAT_c03e1010,(undefined4 *)&DAT_c03e1014);
  }
  FUN_c03e5a34((undefined4 *)&DAT_c03e1018,(undefined4 *)&DAT_c03e101c);
  if (param_3 == 0) {
    TerminateProcess((HANDLE)0x42,param_1);
  }
  else {
    lpCriticalSection = (LPCRITICAL_SECTION)InterlockedExchange((LONG *)&DAT_c03e6088,0);
    if (lpCriticalSection != (LPCRITICAL_SECTION)0x0) {
      DeleteCriticalSection(lpCriticalSection);
      free(lpCriticalSection);
    }
  }
  return;
}



/* c03e5a10 FUN_c03e5a10 */

/* Boundary evidence: original MIPS .pdata c03e5a10..c03e5a33. Semantic name remains unreviewed. */

void FUN_c03e5a10(void)

{
  FUN_c03e58f0(0,0,1);
  return;
}



/* c03e5a34 FUN_c03e5a34 */

/* Boundary evidence: original MIPS .pdata c03e5a34..c03e5a87. Semantic name remains unreviewed. */

void FUN_c03e5a34(undefined4 *param_1,undefined4 *param_2)

{
  for (; param_1 < param_2; param_1 = param_1 + 1) {
    if ((code *)*param_1 != (code *)0x0) {
      (*(code *)*param_1)();
    }
  }
  return;
}



/* c03e5a88 FUN_c03e5a88 */

/* Boundary evidence: original MIPS .pdata c03e5a88..c03e5ac3. Semantic name remains unreviewed. */

void FUN_c03e5a88(void)

{
  FUN_c03e5a34((undefined4 *)&DAT_c03e1008,(undefined4 *)&DAT_c03e100c);
  FUN_c03e5a34((undefined4 *)&DAT_c03e1000,(undefined4 *)&DAT_c03e1004);
  return;
}


