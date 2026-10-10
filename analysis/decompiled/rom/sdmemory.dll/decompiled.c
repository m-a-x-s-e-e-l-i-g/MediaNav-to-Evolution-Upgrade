/* Automatic Ghidra pseudocode. Not original source; not runtime-verified. */

/* c07212bc FUN_c07212bc */

/* Boundary evidence: original MIPS .pdata c07212bc..c072131f. Semantic name remains unreviewed. */

undefined4 FUN_c07212bc(HMODULE param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = 1;
  if (param_2 == 1) {
    DisableThreadLibraryCalls(param_1);
    iVar1 = FUN_c0723508();
    if (iVar1 == 0) {
      uVar2 = 0;
    }
  }
  else if (param_2 == 0) {
    FUN_c0723548();
  }
  return uVar2;
}



/* c0721320 DSK_Close */

undefined4 DSK_Close(void)

{
                    /* 0x1320  1  DSK_Close */
  return 1;
}



/* c0721328 FUN_c0721328 */

/* Boundary evidence: original MIPS .pdata c0721328..c07213c3. Semantic name remains unreviewed. */

void FUN_c0721328(HLOCAL param_1)

{
  LPCRITICAL_SECTION lpCriticalSection;
  
  FUN_c0722f08((int)param_1);
  lpCriticalSection = (LPCRITICAL_SECTION)((int)param_1 + 0xb0);
  EnterCriticalSection(lpCriticalSection);
  if (*(HLOCAL *)((int)param_1 + 8) != (HLOCAL)0x0) {
    FUN_c0723594(*(HLOCAL *)((int)param_1 + 8));
  }
  if (*(void **)((int)param_1 + 4) != (void *)0x0) {
    FUN_c0723718(*(void **)((int)param_1 + 4));
  }
  LeaveCriticalSection(lpCriticalSection);
  DeleteCriticalSection(lpCriticalSection);
  DeleteCriticalSection((LPCRITICAL_SECTION)((int)param_1 + 0xc4));
  if (*(HLOCAL *)((int)param_1 + 0x104) != (HLOCAL)0x0) {
    LocalFree(*(HLOCAL *)((int)param_1 + 0x104));
    *(undefined4 *)((int)param_1 + 0x104) = 0;
  }
  FUN_c0723594(param_1);
  return;
}



/* c07213c4 DSK_Deinit */

/* Boundary evidence: original MIPS .pdata c07213c4..c07213e3. Semantic name remains unreviewed. */

undefined4 DSK_Deinit(HLOCAL param_1)

{
                    /* 0x13c4  2  DSK_Deinit */
  FUN_c0721328(param_1);
  return 1;
}



/* c07213e4 FUN_c07213e4 */

/* Boundary evidence: original MIPS .pdata c07213e4..c0721423. Semantic name remains unreviewed. */

void FUN_c07213e4(undefined4 param_1,int param_2,int param_3)

{
  if (param_3 == 1) {
    *(undefined4 *)(param_2 + 0xd8) = 1;
    EnterCriticalSection((LPCRITICAL_SECTION)(param_2 + 0xb0));
    LeaveCriticalSection((LPCRITICAL_SECTION)(param_2 + 0xb0));
  }
  return;
}



/* c0721424 DSK_Init */

/* Boundary evidence: original MIPS .pdata c0721424..c072171f. Semantic name remains unreviewed. */

int * DSK_Init(LPCWSTR param_1)

{
  int *piVar1;
  int iVar2;
  HLOCAL pvVar3;
  LSTATUS LVar4;
  int *piVar5;
  DWORD local_88;
  uint local_84;
  HKEY local_80 [2];
  wchar_t awStack_78 [32];
  code *local_38;
  uint local_28;
  
                    /* 0x1424  4  DSK_Init */
  local_28 = DAT_c0726100;
  piVar1 = (int *)FUN_c0723574(0x108);
  if (piVar1 != (int *)0x0) {
    piVar1[0x41] = 0;
    InitializeCriticalSection((LPCRITICAL_SECTION)(piVar1 + 0x31));
    InitializeCriticalSection((LPCRITICAL_SECTION)(piVar1 + 0x2c));
    iVar2 = FUN_c07239ac(param_1,piVar1 + 2);
    *piVar1 = iVar2;
    if (iVar2 != 0) {
      pvVar3 = LocalAlloc(0x40,0x54);
      piVar1[0x41] = (int)pvVar3;
      if (pvVar3 != (HLOCAL)0x0) {
        memset(awStack_78,0,0x50);
        wcscpy(awStack_78,L"Memory Card");
        local_38 = FUN_c07213e4;
        iVar2 = FUN_c07238b8(iVar2,piVar1,awStack_78);
        if ((-1 < iVar2) && (iVar2 = FUN_c0722318(piVar1), iVar2 == 0)) {
          piVar5 = piVar1 + 3;
          *piVar5 = 8;
          LVar4 = RegOpenKeyExW((HKEY)0x80000002,(LPCWSTR)piVar1[2],0,0xf003f,local_80);
          if (LVar4 == 0) {
            local_88 = 4;
            RegQueryValueExW(local_80[0],L"BlockTransferSize",(LPDWORD)0x0,(LPDWORD)0x0,
                             (LPBYTE)piVar5,&local_88);
            piVar1[0x29] = 0;
            local_88 = 4;
            local_84 = 0;
            LVar4 = RegQueryValueExW(local_80[0],L"SingleBlockWrites",(LPDWORD)0x0,(LPDWORD)0x0,
                                     (LPBYTE)&local_84,&local_88);
            if (LVar4 == 0) {
              piVar1[0x29] = 1;
            }
            piVar1[0x37] = 1;
            local_88 = 4;
            local_84 = 0;
            LVar4 = RegQueryValueExW(local_80[0],L"DisablePowerManagement",(LPDWORD)0x0,(LPDWORD)0x0
                                     ,(LPBYTE)&local_84,&local_88);
            if (LVar4 == 0) {
              piVar1[0x37] = 0;
            }
            piVar1[0x3d] = 2000;
            local_88 = 4;
            RegQueryValueExW(local_80[0],L"IdleTimeout",(LPDWORD)0x0,(LPDWORD)0x0,
                             (LPBYTE)(piVar1 + 0x3d),&local_88);
            piVar1[0x3a] = 2;
            local_88 = 4;
            local_84 = 0;
            LVar4 = RegQueryValueExW(local_80[0],L"IdlePowerState",(LPDWORD)0x0,(LPDWORD)0x0,
                                     (LPBYTE)&local_84,&local_88);
            if ((LVar4 == 0) && (local_84 < 5)) {
              piVar1[0x3a] = local_84;
            }
            RegCloseKey(local_80[0]);
          }
          piVar5 = FUN_c07237a0(0x53444d43,2,*piVar5 << 9);
          piVar1[1] = (int)piVar5;
          if (piVar5 != (int *)0x0) {
            FUN_c0722e74(piVar1);
            FUN_c0724c1c(local_28);
            return piVar1;
          }
        }
      }
    }
    FUN_c0721328(piVar1);
  }
  FUN_c0724c1c(local_28);
  return (int *)0x0;
}



/* c0721720 DSK_Open */

undefined4 DSK_Open(undefined4 param_1)

{
                    /* 0x1720  5  DSK_Open */
  return param_1;
}



/* c0721728 DSK_PowerDown */

void DSK_PowerDown(void)

{
                    /* 0x1728  6  DSK_PowerDown
                       0x1728  7  DSK_PowerUp */
  return;
}



/* c0721730 DSK_Read */

undefined4 DSK_Read(void)

{
                    /* 0x1730  8  DSK_Read
                       0x1730  9  DSK_Seek
                       0x1730  10  DSK_Write */
  return 0;
}



/* c0721738 FUN_c0721738 */

/* Boundary evidence: original MIPS .pdata c0721738..c07217e3. Semantic name remains unreviewed. */

undefined4 FUN_c0721738(int param_1,undefined4 *param_2,uint param_3,undefined4 *param_4)

{
  undefined4 uVar1;
  int iVar2;
  char *_Dest;
  
  if (param_3 < 0x1c) {
    *param_2 = 0x1c;
    uVar1 = 0x7a;
  }
  else {
    _Dest = (char *)(param_2 + 4);
    param_2[2] = (int)_Dest - (int)param_2;
    iVar2 = sprintf(_Dest,"%02X",(uint)*(byte *)(param_1 + 0x28));
    param_2[3] = (int)(_Dest + iVar2) - (int)param_2;
    sprintf(_Dest + iVar2,"%08X",*(undefined4 *)(param_1 + 0x38));
    *param_2 = 0x1c;
    param_2[1] = 0;
    *param_4 = 0x1c;
    uVar1 = 0;
  }
  return uVar1;
}



/* c07217e4 FUN_c07217e4 */

/* Boundary evidence: original MIPS .pdata c07217e4..c07218f7. Semantic name remains unreviewed. */

undefined4 FUN_c07217e4(int param_1,int param_2)

{
  LSTATUS LVar1;
  undefined4 uVar2;
  DWORD local_20;
  HKEY local_1c;
  DWORD aDStack_18 [2];
  
  LVar1 = RegOpenKeyExW((HKEY)0x80000002,*(LPCWSTR *)(param_1 + 8),0,0xf003f,&local_1c);
  if (LVar1 == 0) {
    if (local_1c != (HKEY)0x0) {
      local_20 = 0x40;
      LVar1 = RegQueryValueExW(local_1c,L"Profile",(LPDWORD)0x0,aDStack_18,(LPBYTE)(param_2 + 4),
                               &local_20);
      if ((LVar1 != 0) || (0x40 < local_20)) {
        wcscpy((wchar_t *)(param_2 + 4),L"Default");
      }
      RegCloseKey(local_1c);
    }
    uVar2 = 1;
    *(undefined4 *)(param_2 + 0x44) = 1;
    *(undefined4 *)(param_2 + 0x48) = 0xa0000000;
    if (*(int *)(param_1 + 0xa8) == 0) {
      *(undefined4 *)(param_2 + 0x4c) = 1;
    }
    else {
      *(undefined4 *)(param_2 + 0x4c) = 2;
    }
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}



/* c07218f8 DSK_IOControl */

/* Boundary evidence: original MIPS .pdata c07218f8..c072220b. Semantic name remains unreviewed. */

undefined4
DSK_IOControl(undefined4 *param_1,uint param_2,int *param_3,uint param_4,int *param_5,uint param_6,
             int *param_7)

{
  bool bVar1;
  undefined1 auVar2 [4];
  int iVar3;
  DWORD dwErrCode;
  uint uVar4;
  undefined4 **ppuVar5;
  uint *puVar6;
  undefined4 uVar7;
  uint dwErrCode_00;
  undefined4 uVar8;
  uint local_e8 [2];
  undefined4 *local_e0;
  uint local_dc;
  undefined4 local_d8;
  undefined1 auStack_d4 [12];
  undefined4 local_c8;
  undefined1 auStack_c4 [20];
  undefined4 *apuStack_b0 [6];
  undefined4 *apuStack_98 [6];
  undefined1 local_80 [4];
  undefined4 local_7c;
  undefined4 local_78;
  undefined4 local_74;
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  uint local_30;
  
                    /* 0x18f8  3  DSK_IOControl */
  local_30 = DAT_c0726100;
  dwErrCode_00 = 0;
  local_e8[1] = 0;
  local_e8[0] = param_4;
  local_e0 = param_1;
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x2c));
  iVar3 = FUN_c07230bc(param_1,param_2);
  if (iVar3 < 0) {
    LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x2c));
    dwErrCode = FUN_c0723190(iVar3);
    SetLastError(dwErrCode);
    FUN_c0724c1c(local_30);
    return 0;
  }
  if (param_2 < 0x71c4d) {
    if (param_2 == 0x71c4c) {
      if ((param_3 == (int *)0x0) || (local_e8[0] != 0xc)) {
LAB_c0721cb0:
        dwErrCode_00 = 0x57;
      }
    }
    else if (param_2 < 0x71801) {
      if (param_2 == 0x71800) {
        if ((param_3 == (int *)0x0) || (local_e8[0] != 0x50)) goto LAB_c0721cb0;
      }
      else if (param_2 == 1) {
LAB_c0721ad4:
        if ((param_3 == (int *)0x0) || (local_e8[0] != 0x18)) {
          dwErrCode_00 = 0x57;
        }
      }
      else {
        if (1 < param_2) {
          if (param_2 < 4) goto LAB_c0721c34;
          if (param_2 == 6) goto LAB_c0721cc4;
        }
LAB_c0721bc0:
        dwErrCode_00 = 0x57;
      }
    }
    else if (param_2 == 0x71c00) {
      if ((param_5 == (int *)0x0) || (param_6 != 0x18)) {
        dwErrCode_00 = 0x57;
      }
    }
    else {
      if (param_2 == 0x71c04) goto LAB_c0721ad4;
      if (param_2 != 0x71c24) goto LAB_c0721bc0;
      if ((param_5 == (int *)0x0) || (param_6 < 0x10)) goto LAB_c0721cb0;
    }
  }
  else if (param_2 == 0x71f84) {
    if ((param_5 == (int *)0x0) || (param_6 < 4)) goto LAB_c0721cb0;
  }
  else if ((param_2 == 0x75c08) || (param_2 == 0x79c0c)) {
LAB_c0721c34:
    if (((param_3 == (int *)0x0) || (local_e8[0] < 0x1c)) || (0x54 < local_e8[0])) {
      dwErrCode_00 = 0x57;
    }
  }
  else if (param_2 != 0x79c14) {
    if (param_2 == 0x321000) {
      if (param_5 != (int *)0x0) {
        bVar1 = param_6 < 0x30;
LAB_c0721c00:
        if ((!bVar1) && (param_7 != (int *)0x0)) goto LAB_c0721cc4;
      }
    }
    else {
      if (param_2 != 0x321008) goto LAB_c0721bc0;
      if (param_5 != (int *)0x0) {
        bVar1 = param_6 < 4;
        goto LAB_c0721c00;
      }
    }
    dwErrCode_00 = 0x57;
  }
LAB_c0721cc4:
  uVar8 = 1;
  if (dwErrCode_00 != 0) goto LAB_c0722190;
  if (param_2 < 0x71c25) {
    if (param_2 == 0x71c24) {
      dwErrCode_00 = FUN_c0721738((int)param_1,param_5,param_6,param_7);
      local_dc = dwErrCode_00;
    }
    else if (param_2 == 1) {
      local_e8[1] = 0x18;
      memcpy(apuStack_98,param_1 + 4,0x18);
      uVar7 = 0x18;
      ppuVar5 = apuStack_98;
LAB_c0721dc8:
      iVar3 = CeSafeCopyMemory(param_3,ppuVar5,uVar7);
      if (iVar3 == 0) goto LAB_c0722070;
LAB_c0721dd8:
      dwErrCode_00 = 0;
      if (param_7 != (int *)0x0) {
        puVar6 = local_e8 + 1;
        goto LAB_c0721de8;
      }
    }
    else if (param_2 == 2) {
LAB_c0722058:
      iVar3 = CeSafeCopyMemory(param_1[0x41],param_3);
      if (iVar3 == 0) goto LAB_c0722070;
      dwErrCode_00 = FUN_c0722568(param_1,(uint *)param_1[0x41]);
      param_3[3] = dwErrCode_00;
      if ((param_7 != (int *)0x0) && (dwErrCode_00 == 0)) {
        *param_7 = *(int *)(param_1[0x41] + 4) << 9;
      }
    }
    else if (param_2 == 3) {
LAB_c0721fec:
      iVar3 = CeSafeCopyMemory(param_1[0x41],param_3);
      if (iVar3 == 0) goto LAB_c0722070;
      dwErrCode_00 = FUN_c0722864(param_1,(uint *)param_1[0x41]);
      param_3[3] = dwErrCode_00;
      if ((param_7 != (int *)0x0) && (dwErrCode_00 == 0)) {
        *param_7 = *(int *)(param_1[0x41] + 4) << 9;
      }
    }
    else if (param_2 == 6) {
LAB_c0721d94:
      dwErrCode_00 = 0;
    }
    else {
      if (param_2 != 0x71800) {
        if (param_2 == 0x71c00) {
          local_e8[1] = 0x18;
          memcpy(apuStack_b0,param_1 + 4,0x18);
          uVar7 = 0x18;
          ppuVar5 = apuStack_b0;
          param_3 = param_5;
          goto LAB_c0721dc8;
        }
        if (param_2 == 0x71c04) {
          local_c8 = 0;
          memset(auStack_c4,0,0x14);
          iVar3 = CeSafeCopyMemory(&local_c8,param_3,0x18);
          if (iVar3 != 0) {
            memcpy(param_1 + 4,&local_c8,0x18);
            goto LAB_c0721d94;
          }
        }
        goto LAB_c0722070;
      }
      local_80 = (undefined1  [4])0x0;
      memset(&local_7c,0,0x4c);
      local_e8[1] = 0x50;
      iVar3 = FUN_c07217e4((int)param_1,(int)local_80);
      if (iVar3 != 0) {
        uVar7 = 0x50;
        goto LAB_c0721e4c;
      }
      dwErrCode_00 = 0x1f;
    }
  }
  else {
    if (param_2 == 0x71c4c) {
      local_d8 = 0;
      memset(auStack_d4,0,8);
      iVar3 = CeSafeCopyMemory(&local_d8,param_3,0xc);
      if (iVar3 != 0) {
        dwErrCode_00 = FUN_c0722b88((int)param_1,(int)&local_d8);
        goto LAB_c0722184;
      }
    }
    else if (param_2 == 0x71f84) {
      local_e0 = (undefined4 *)0x0;
      NKDbgPrintfW(L"SMC_IOControl: IOCTL_DISK_SLEEP\r\n");
      iVar3 = CeSafeCopyMemory(&local_e0,param_3,4);
      if (iVar3 != 0) {
        uVar4 = FUN_c0722f98(param_1,(int)local_e0);
        local_e8[0] = 0;
        if (-1 < (int)uVar4) {
          local_e8[0] = uVar4;
        }
        puVar6 = local_e8;
        param_7 = param_5;
LAB_c0721de8:
        iVar3 = CeSafeCopyMemory(param_7,puVar6,4);
        if (iVar3 != 0) goto LAB_c0722184;
      }
    }
    else {
      if (param_2 == 0x75c08) goto LAB_c0722058;
      if (param_2 == 0x79c0c) goto LAB_c0721fec;
      if (param_2 == 0x79c14) goto LAB_c0721d94;
      if (param_2 == 0x321000) {
        memset(local_80 + 1,0,0x2f);
        auVar2 = local_80;
        local_e8[1] = 0x30;
        local_80[0] = (byte)(1 << (param_1[0x3a] & 0x1f)) | 1;
        local_7c = 0xffffffff;
        local_78 = 0xffffffff;
        local_74 = 0xffffffff;
        local_70 = 0xffffffff;
        local_6c = 0xffffffff;
        local_68 = 0;
        local_64 = 0;
        local_60 = 0;
        local_5c = 0;
        local_58 = 0;
        local_80[3] = auVar2[3];
        local_80._1_2_ = 0;
        uVar7 = 0x30;
        param_3 = param_5;
LAB_c0721e4c:
        iVar3 = CeSafeCopyMemory(param_3,local_80,uVar7);
        if (iVar3 != 0) goto LAB_c0721dd8;
      }
      else if (param_2 == 0x321008) {
        local_e8[1] = 4;
        iVar3 = CeSafeCopyMemory(&local_e0,param_5,4);
        if (iVar3 != 0) {
          FUN_c0722de8((int)param_1,(int *)&local_e0);
          uVar7 = 4;
          ppuVar5 = &local_e0;
          param_3 = param_5;
          goto LAB_c0721dc8;
        }
      }
    }
LAB_c0722070:
    dwErrCode_00 = 0x57;
  }
LAB_c0722184:
  FUN_c0722bb0((int)param_1);
LAB_c0722190:
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x2c));
  if ((dwErrCode_00 != 0) && (SetLastError(dwErrCode_00), dwErrCode_00 != 0)) {
    uVar8 = 0;
  }
  FUN_c0724c1c(local_30);
  return uVar8;
}



/* c072220c FUN_c072220c */

/* Boundary evidence: original MIPS .pdata c072220c..c0722217. Semantic name remains unreviewed. */

undefined4 FUN_c072220c(void)

{
  return 1;
}



/* c0722218 FUN_c0722218 */

/* Boundary evidence: original MIPS .pdata c0722218..c0722223. Semantic name remains unreviewed. */

undefined4 FUN_c0722218(void)

{
  return 1;
}



/* c0722224 FUN_c0722224 */

/* Boundary evidence: original MIPS .pdata c0722224..c072222f. Semantic name remains unreviewed. */

undefined4 FUN_c0722224(void)

{
  return 1;
}



/* c0722230 FUN_c0722230 */

/* Boundary evidence: original MIPS .pdata c0722230..c0722317. Semantic name remains unreviewed. */

undefined4 FUN_c0722230(undefined4 *param_1,int *param_2,int *param_3)

{
  ushort uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined8 uVar4;
  undefined1 auStack_20 [4];
  uint local_1c;
  
  iVar2 = (*DAT_c07260d4)(*param_1,5,auStack_20,0xc);
  if (((iVar2 < 0) || (local_1c == 0)) || (1000000000 < local_1c)) {
    uVar3 = 0;
  }
  else {
    if (local_1c == 0) {
      trap(0x1c00);
    }
    uVar4 = __ultodp(1000000000 / local_1c);
    uVar4 = __dpdiv(param_1[0x16],param_1[0x17],(int)uVar4,(int)((ulonglong)uVar4 >> 0x20));
    iVar2 = __dptoul((int)uVar4,(int)((ulonglong)uVar4 >> 0x20));
    uVar1 = *(ushort *)(param_1 + 0x18);
    *param_2 = iVar2 + (uint)uVar1;
    uVar3 = 1;
    *param_3 = (uint)*(byte *)(param_1 + 0x21) * (iVar2 + (uint)uVar1);
  }
  return uVar3;
}



/* c0722318 FUN_c0722318 */

/* Boundary evidence: original MIPS .pdata c0722318..c0722567. Semantic name remains unreviewed. */

undefined4 FUN_c0722318(undefined4 *param_1)

{
  byte bVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  int local_40 [2];
  int iStack_38;
  int iStack_34;
  undefined1 auStack_30 [8];
  undefined4 local_28;
  
  iVar2 = (*DAT_c07260d4)(*param_1,1,param_1 + 10,0x28);
  if (iVar2 < 0) {
    return 0x1f;
  }
  iVar2 = (*DAT_c07260d4)(*param_1,2,param_1 + 0x14,0x50);
  if (iVar2 < 0) {
    return 0x1f;
  }
  iVar2 = (*DAT_c07260d4)(*param_1,3,param_1 + 0x28,2);
  if (iVar2 < 0) {
    return 0x1f;
  }
  iVar2 = (*DAT_c07260d4)(*param_1,5,auStack_30,0xc);
  if (iVar2 < 0) {
    return 0x1f;
  }
  param_1[0x2a] = local_28;
  iVar2 = (*DAT_c07260d4)(*param_1,10,local_40,4);
  if (iVar2 < 0) {
    param_1[0x2b] = 0;
  }
  else {
    param_1[0x2b] = (uint)(local_40[0] != 0);
  }
  if ((*(ushort *)(param_1 + 0x1b) & 4) == 0) {
    return 0x4b0;
  }
  if ((*(ushort *)(param_1 + 0x1b) & 0x10) == 0) {
    param_1[0x2a] = 1;
  }
  iVar2 = FUN_c0722230(param_1,&iStack_38,&iStack_34);
  if (iVar2 == 0) {
    return 0x1f;
  }
  iVar2 = (*DAT_c07260ec)(*param_1,3,&iStack_38,8);
  if (iVar2 < 0) {
    return 0x1f;
  }
  param_1[5] = 0x200;
  param_1[9] = 10;
  param_1[6] = 0;
  param_1[7] = 0;
  param_1[8] = 0;
  if (param_1[0x23] == 0) {
    param_1[9] = 0xb;
  }
  else if (param_1[0x23] != 1) {
    return 0x1f;
  }
  bVar1 = *(byte *)(param_1 + 0x14);
  if ((bVar1 == 0) || (param_1[0x2b] == 0)) {
    if ((1 < bVar1) && ((*(short *)((int)param_1 + 0x6e) == 0x400 && (param_1[0x2b] == 0)))) {
      param_1[4] = param_1[0x1d];
      goto LAB_c0722524;
    }
    uVar4 = (uint)param_1[0x1d] >> 9;
  }
  else {
    uVar4 = param_1[0x1d];
  }
  param_1[4] = uVar4;
LAB_c0722524:
  if (*(short *)((int)param_1 + 0x6e) != 0x200) {
    uVar3 = FUN_c07232bc(param_1);
    return uVar3;
  }
  return 0;
}



/* c0722568 FUN_c0722568 */

/* Boundary evidence: original MIPS .pdata c0722568..c0722863. Semantic name remains unreviewed. */

uint FUN_c0722568(undefined4 *param_1,uint *param_2)

{
  int iVar1;
  uint uVar2;
  uint *puVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  int *piVar10;
  int local_40;
  uint local_3c;
  int local_38;
  int local_34;
  int *local_30;
  uint *local_2c;
  
  piVar10 = (int *)0x0;
  local_40 = 0;
  uVar6 = 0;
  uVar5 = 0;
  if (param_2[2] != 0) {
    puVar3 = param_2 + 5;
    do {
      if (*puVar3 == 0) goto LAB_c072264c;
      uVar5 = uVar5 + 1;
      puVar3 = puVar3 + 2;
    } while (uVar5 < param_2[2]);
  }
  uVar5 = *param_2;
  uVar9 = param_2[1];
  if ((uVar5 + uVar9 < uVar5) || ((uint)param_1[4] < uVar5 + uVar9)) {
LAB_c0722814:
    uVar6 = 0x57;
  }
  else {
    if (0x7fffff < uVar9) {
LAB_c072264c:
      uVar6 = 0x57;
      goto LAB_c072282c;
    }
    uVar2 = 0;
    if (param_2[2] != 0) {
      uVar4 = param_2[2];
      puVar3 = param_2 + 6;
      do {
        uVar2 = *puVar3 + uVar2;
        uVar4 = uVar4 - 1;
        puVar3 = puVar3 + 2;
      } while (uVar4 != 0);
    }
    if (uVar2 < uVar9 << 9) {
      uVar6 = 0x1f;
      goto LAB_c072282c;
    }
    piVar10 = FUN_c0723770((int *)param_1[1]);
    uVar2 = param_2[6];
    local_34 = 0;
    local_3c = uVar2;
    iVar1 = CeOpenCallerBuffer(&local_40,param_2[5],uVar2,8,0);
    if (iVar1 < 0) goto LAB_c0722814;
    local_38 = local_40;
    uVar4 = uVar5;
    if (uVar5 < uVar9 + uVar5) {
      do {
        uVar6 = (uVar9 - uVar4) + uVar5;
        uVar7 = param_1[3];
        if (uVar6 <= (uint)param_1[3]) {
          uVar7 = uVar6;
        }
        local_30 = piVar10;
        uVar6 = FUN_c07232f8(param_1,uVar4,uVar7);
        if (uVar6 != 0) break;
        uVar7 = uVar7 << 9;
        if (uVar7 != 0) {
          local_2c = param_2 + (local_34 + 3) * 2;
          do {
            uVar8 = uVar2;
            if (uVar7 <= uVar2) {
              uVar8 = uVar7;
            }
            iVar1 = CeSafeCopyMemory(local_38,local_30,uVar8);
            puVar3 = local_2c;
            if (iVar1 == 0) goto LAB_c0722814;
            local_30 = (int *)(uVar8 + (int)local_30);
            local_38 = uVar8 + local_38;
            uVar2 = local_3c - uVar8;
            uVar7 = uVar7 - uVar8;
            local_3c = uVar2;
            if (uVar2 == 0) {
              if (uVar7 == 0) break;
              CeCloseCallerBuffer(local_40,local_2c[-1],*local_2c,8);
              local_2c = puVar3 + 2;
              uVar2 = *local_2c;
              local_34 = local_34 + 1;
              local_3c = uVar2;
              iVar1 = CeOpenCallerBuffer(&local_40,puVar3[1],uVar2,8,0);
              if (iVar1 < 0) goto LAB_c0722814;
              local_38 = local_40;
            }
          } while (uVar7 != 0);
        }
        uVar4 = param_1[3] + uVar4;
      } while (uVar4 < uVar9 + uVar5);
    }
    CeCloseCallerBuffer(local_40,param_2[local_34 * 2 + 5],param_2[(local_34 + 3) * 2],8);
  }
  if (piVar10 != (int *)0x0) {
    FUN_c072369c(param_1[1],piVar10);
  }
LAB_c072282c:
  param_2[3] = uVar6;
  return uVar6;
}



/* c0722864 FUN_c0722864 */

/* Boundary evidence: original MIPS .pdata c0722864..c0722b87. Semantic name remains unreviewed. */

uint FUN_c0722864(undefined4 *param_1,uint *param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint *puVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  int *piVar11;
  int local_40;
  int local_3c;
  int local_38;
  uint *local_34;
  int *local_30;
  uint local_2c;
  
  piVar11 = (int *)0x0;
  local_40 = 0;
  uVar7 = 0;
  uVar6 = 0;
  if (param_2[2] != 0) {
    puVar4 = param_2 + 5;
    do {
      if (*puVar4 == 0) goto LAB_c0722910;
      uVar6 = uVar6 + 1;
      puVar4 = puVar4 + 2;
    } while (uVar6 < param_2[2]);
  }
  uVar6 = *param_2;
  uVar10 = param_2[1];
  if ((uVar6 + uVar10 < uVar6) || ((uint)param_1[4] < uVar6 + uVar10)) {
LAB_c0722b38:
    uVar7 = 0x57;
  }
  else {
    if (param_1[0x2a] != 0) {
      uVar7 = 0x13;
      goto LAB_c0722b50;
    }
    if (0x7fffff < uVar10) {
LAB_c0722910:
      uVar7 = 0x57;
      goto LAB_c0722b50;
    }
    uVar3 = 0;
    if (param_2[2] != 0) {
      uVar5 = param_2[2];
      puVar4 = param_2 + 6;
      do {
        uVar3 = *puVar4 + uVar3;
        uVar5 = uVar5 - 1;
        puVar4 = puVar4 + 2;
      } while (uVar5 != 0);
    }
    if (uVar3 < uVar10 << 9) {
      uVar7 = 0x1f;
      goto LAB_c0722b50;
    }
    piVar11 = FUN_c0723770((int *)param_1[1]);
    uVar3 = param_2[6];
    iVar8 = 0;
    local_3c = 0;
    iVar1 = CeOpenCallerBuffer(&local_40,param_2[5],uVar3,4,0);
    if (iVar1 < 0) goto LAB_c0722b38;
    local_38 = local_40;
    uVar5 = uVar6;
    if (uVar6 < uVar10 + uVar6) {
      do {
        uVar7 = (uVar10 - uVar5) + uVar6;
        local_2c = param_1[3];
        if (uVar7 <= (uint)param_1[3]) {
          local_2c = uVar7;
        }
        uVar7 = local_2c << 9;
        local_30 = piVar11;
        if (uVar7 != 0) {
          local_34 = param_2 + (iVar8 + 3) * 2;
          do {
            uVar9 = uVar3;
            if (uVar7 <= uVar3) {
              uVar9 = uVar7;
            }
            iVar8 = CeSafeCopyMemory(local_30,local_38,uVar9);
            puVar4 = local_34;
            if (iVar8 == 0) goto LAB_c0722b38;
            local_38 = uVar9 + local_38;
            local_30 = (int *)(uVar9 + (int)local_30);
            uVar7 = uVar7 - uVar9;
            uVar3 = uVar3 - uVar9;
            iVar1 = local_38;
            iVar8 = local_3c;
            if (uVar3 == 0) {
              if (uVar7 == 0) break;
              CeCloseCallerBuffer(local_40,local_34[-1],*local_34,4);
              local_34 = puVar4 + 2;
              uVar3 = *local_34;
              iVar8 = local_3c + 1;
              local_3c = iVar8;
              iVar2 = CeOpenCallerBuffer(&local_40,puVar4[1],uVar3,4,0);
              iVar1 = local_40;
              if (iVar2 < 0) goto LAB_c0722b38;
            }
            local_38 = iVar1;
          } while (uVar7 != 0);
        }
        uVar7 = FUN_c072347c(param_1,uVar5,local_2c);
      } while ((uVar7 == 0) && (uVar5 = param_1[3] + uVar5, uVar5 < uVar10 + uVar6));
    }
    CeCloseCallerBuffer(local_40,param_2[iVar8 * 2 + 5],param_2[(iVar8 + 3) * 2],4);
  }
  if (piVar11 != (int *)0x0) {
    FUN_c072369c(param_1[1],piVar11);
  }
LAB_c0722b50:
  param_2[3] = uVar7;
  return uVar7;
}



/* c0722b88 FUN_c0722b88 */

undefined4 FUN_c0722b88(int param_1,int param_2)

{
  undefined4 uVar1;
  
  uVar1 = 0x32;
  if (*(uint *)(param_1 + 0x10) < (uint)(*(int *)(param_2 + 8) + *(int *)(param_2 + 4))) {
    uVar1 = 0x57;
  }
  return uVar1;
}



/* c0722bb0 FUN_c0722bb0 */

/* Boundary evidence: original MIPS .pdata c0722bb0..c0722bef. Semantic name remains unreviewed. */

void FUN_c0722bb0(int param_1)

{
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xc4));
  *(undefined4 *)(param_1 + 0xf0) = 0;
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xc4));
  return;
}



/* c0722bf0 FUN_c0722bf0 */

/* Boundary evidence: original MIPS .pdata c0722bf0..c0722cef. Semantic name remains unreviewed. */

int FUN_c0722bf0(undefined4 *param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  uint local_28 [2];
  
  uVar4 = 2;
  if (param_2 == 0) {
    uVar2 = 0;
    uVar4 = 0;
  }
  else {
    uVar2 = (uint)*(ushort *)(param_1 + 0x28);
  }
  iVar3 = 3;
  while( true ) {
    iVar1 = (*DAT_c07260c8)(*param_1,7,uVar2 << 0x10,2,uVar4,0,0,0,0,0,0,0);
    if (iVar1 < 0) {
      return iVar1;
    }
    if (param_2 != 0) {
      return iVar1;
    }
    iVar1 = (*DAT_c07260d4)(*param_1,6,local_28,4);
    if (iVar1 < 0) {
      return iVar1;
    }
    if ((local_28[0] & 0x1e00) == 0x600) break;
    iVar3 = iVar3 + -1;
    if (iVar3 == 0) {
      return -0x3ffffffd;
    }
  }
  return iVar1;
}



/* c0722cf0 FUN_c0722cf0 */

/* Boundary evidence: original MIPS .pdata c0722cf0..c0722de7. Semantic name remains unreviewed. */

undefined4 FUN_c0722cf0(undefined4 *param_1)

{
  int iVar1;
  
  WaitForSingleObject((HANDLE)param_1[0x3f],0xffffffff);
  iVar1 = param_1[0x3b];
  while( true ) {
    if (iVar1 != 0) {
      return 0;
    }
    iVar1 = param_1[0x38];
    while (iVar1 != 0) {
      WaitForSingleObject((HANDLE)param_1[0x3f],param_1[0x3d]);
      if (param_1[0x38] != 0) {
        EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x31));
        if (((param_1[0x3c] == 0) && (param_1[0x3e] == 0)) &&
           (iVar1 = FUN_c0722bf0(param_1,0), -1 < iVar1)) {
          param_1[0x3e] = 1;
        }
        LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x31));
      }
      iVar1 = param_1[0x38];
    }
    if (param_1[0x3b] != 0) break;
    WaitForSingleObject((HANDLE)param_1[0x3f],0xffffffff);
    iVar1 = param_1[0x3b];
  }
  return 0;
}



/* c0722de8 FUN_c0722de8 */

/* Boundary evidence: original MIPS .pdata c0722de8..c0722e73. Semantic name remains unreviewed. */

void FUN_c0722de8(int param_1,int *param_2)

{
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xc4));
  if (*param_2 < *(int *)(param_1 + 0xe8)) {
    *param_2 = 0;
    *(undefined4 *)(param_1 + 0xe4) = 0;
    *(undefined4 *)(param_1 + 0xe0) = 0;
  }
  else {
    *param_2 = *(int *)(param_1 + 0xe8);
    *(undefined4 *)(param_1 + 0xe4) = *(undefined4 *)(param_1 + 0xe8);
    *(undefined4 *)(param_1 + 0xe0) = 1;
    EventModify(*(undefined4 *)(param_1 + 0xfc),3);
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xc4));
  return;
}



/* c0722e74 FUN_c0722e74 */

/* Boundary evidence: original MIPS .pdata c0722e74..c0722f07. Semantic name remains unreviewed. */

void FUN_c0722e74(LPVOID param_1)

{
  HANDLE pvVar1;
  DWORD aDStack_10 [2];
  
  if (*(int *)((int)param_1 + 0xdc) != 0) {
    *(undefined4 *)((int)param_1 + 0xe0) = 0;
    *(undefined4 *)((int)param_1 + 0xe4) = 0;
    *(undefined4 *)((int)param_1 + 0xec) = 0;
    *(undefined4 *)((int)param_1 + 0xf0) = 0;
    *(undefined4 *)((int)param_1 + 0xf8) = 0;
    pvVar1 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
    *(HANDLE *)((int)param_1 + 0xfc) = pvVar1;
    if (pvVar1 != (HANDLE)0x0) {
      pvVar1 = CreateThread((LPSECURITY_ATTRIBUTES)0x0,0,FUN_c0722cf0,param_1,0,aDStack_10);
      *(HANDLE *)((int)param_1 + 0x100) = pvVar1;
      if (pvVar1 != (HANDLE)0x0) {
        return;
      }
    }
    *(undefined4 *)((int)param_1 + 0xdc) = 0;
  }
  return;
}



/* c0722f08 FUN_c0722f08 */

/* Boundary evidence: original MIPS .pdata c0722f08..c0722f97. Semantic name remains unreviewed. */

void FUN_c0722f08(int param_1)

{
  *(undefined4 *)(param_1 + 0xec) = 1;
  *(undefined4 *)(param_1 + 0xf0) = 1;
  *(undefined4 *)(param_1 + 0xe0) = 0;
  if (*(int *)(param_1 + 0x100) != 0) {
    EventModify(*(undefined4 *)(param_1 + 0xfc),3);
    WaitForSingleObject(*(HANDLE *)(param_1 + 0x100),0xffffffff);
    CloseHandle(*(HANDLE *)(param_1 + 0x100));
    *(undefined4 *)(param_1 + 0x100) = 0;
  }
  if (*(HANDLE *)(param_1 + 0xfc) != (HANDLE)0x0) {
    CloseHandle(*(HANDLE *)(param_1 + 0xfc));
    *(undefined4 *)(param_1 + 0xfc) = 0;
  }
  return;
}



/* c0722f98 FUN_c0722f98 */

/* Boundary evidence: original MIPS .pdata c0722f98..c07230bb. Semantic name remains unreviewed. */

int FUN_c0722f98(undefined4 *param_1,int param_2)

{
  int iVar1;
  wchar_t *pwVar2;
  int iVar3;
  uint local_28 [2];
  
  iVar3 = 3;
  do {
    iVar1 = (*DAT_c07260c8)(*param_1,7,0,2,0,0,0,0,0,0,0,0);
    if (iVar1 < 0) {
      return iVar1;
    }
    if (param_2 != 0) {
      pwVar2 = L"SDMemory: Card now in Transfer state \r\n";
LAB_c072308c:
      NKDbgPrintfW(pwVar2);
      return iVar1;
    }
    iVar1 = (*DAT_c07260d4)(*param_1,6,local_28,4);
    if (iVar1 < 0) {
      return iVar1;
    }
    if ((local_28[0] & 0x1e00) == 0x600) {
      pwVar2 = L"SDMemory: Card now in Standby\r\n";
      goto LAB_c072308c;
    }
    NKDbgPrintfW(L"SDMemory: Card not in standby! Card Status: 0x%08X\r\n");
    iVar3 = iVar3 + -1;
    if (iVar3 == 0) {
      return -0x3ffffffd;
    }
  } while( true );
}



/* c07230bc FUN_c07230bc */

/* Boundary evidence: original MIPS .pdata c07230bc..c072318f. Semantic name remains unreviewed. */

int FUN_c07230bc(undefined4 *param_1,int param_2)

{
  int iVar1;
  
  iVar1 = 0;
  if (param_1[0x36] == 0) {
    if ((((param_1[0x37] == 0) || (param_2 == 0x321000)) || (param_2 == 0x32100c)) ||
       (param_2 == 0x321008)) {
      iVar1 = 0;
    }
    else {
      EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x31));
      param_1[0x3c] = 1;
      if ((param_1[0x3e] != 0) && (iVar1 = FUN_c0722bf0(param_1,1), -1 < iVar1)) {
        param_1[0x3e] = 0;
      }
      LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x31));
    }
  }
  else {
    iVar1 = -0x3fffffef;
  }
  return iVar1;
}



/* c0723190 FUN_c0723190 */

/* Boundary evidence: original MIPS .pdata c0723190..c0723237. Semantic name remains unreviewed. */

undefined4 FUN_c0723190(int param_1)

{
  undefined4 uVar1;
  
  if (param_1 < 1) {
    if (param_1 == 0) {
      return 0;
    }
    switch(param_1) {
    default:
      goto switchD_c07231d4_caseD_c0000001;
    case -0x3ffffffe:
      uVar1 = 0xaa;
      break;
    case -0x3ffffff8:
      uVar1 = 0x37;
      break;
    case -0x3ffffff6:
      uVar1 = 8;
      break;
    case -0x3ffffff3:
      uVar1 = 0x17;
      break;
    case -0x3ffffff0:
      uVar1 = 0x48f;
      break;
    case -0x3fffffef:
      uVar1 = 0x651;
    }
  }
  else {
switchD_c07231d4_caseD_c0000001:
    uVar1 = 0x1f;
  }
  return uVar1;
}



/* c0723238 FUN_c0723238 */

/* Boundary evidence: original MIPS .pdata c0723238..c07232bb. Semantic name remains unreviewed. */

undefined4 FUN_c0723238(undefined4 *param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = (*DAT_c07260c8)(*param_1);
  if (iVar1 < 0) {
    uVar2 = FUN_c0723190(iVar1);
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}



/* c07232bc FUN_c07232bc */

/* Boundary evidence: original MIPS .pdata c07232bc..c07232f7. Semantic name remains unreviewed. */

void FUN_c07232bc(undefined4 *param_1)

{
  FUN_c0723238(param_1);
  return;
}



/* c07232f8 FUN_c07232f8 */

/* Boundary evidence: original MIPS .pdata c07232f8..c072338f. Semantic name remains unreviewed. */

undefined4 FUN_c07232f8(undefined4 *param_1,uint param_2,int param_3)

{
  undefined4 uVar1;
  
  if ((param_1[0x2b] == 0) && (0x7fffff < param_2)) {
    uVar1 = 0x57;
  }
  else if (param_3 == 1) {
    uVar1 = FUN_c0723238(param_1);
  }
  else {
    uVar1 = FUN_c0723238(param_1);
  }
  return uVar1;
}



/* c0723390 FUN_c0723390 */

/* Boundary evidence: original MIPS .pdata c0723390..c072347b. Semantic name remains unreviewed. */

int FUN_c0723390(undefined4 *param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  
  iVar1 = 0;
  if ((param_1[0x2b] == 0) && (0x7fffff < (uint)(param_2 + param_3))) {
    iVar1 = 0x57;
  }
  else {
    iVar2 = 0;
    if (0 < param_3) {
      do {
        iVar1 = FUN_c0723238(param_1);
        if (iVar1 != 0) {
          return iVar1;
        }
        iVar2 = iVar2 + 1;
        iVar1 = 0;
      } while (iVar2 < param_3);
    }
  }
  return iVar1;
}



/* c072347c FUN_c072347c */

/* Boundary evidence: original MIPS .pdata c072347c..c0723507. Semantic name remains unreviewed. */

int FUN_c072347c(undefined4 *param_1,uint param_2,int param_3)

{
  int iVar1;
  
  if ((param_1[0x29] == 0) && (param_3 != 1)) {
    if ((param_1[0x2b] == 0) && (0x7fffff < param_2)) {
      iVar1 = 0x57;
    }
    else {
      iVar1 = FUN_c0723238(param_1);
    }
  }
  else {
    iVar1 = FUN_c0723390(param_1,param_2,param_3);
  }
  return iVar1;
}



/* c0723508 FUN_c0723508 */

/* Boundary evidence: original MIPS .pdata c0723508..c0723547. Semantic name remains unreviewed. */

undefined4 FUN_c0723508(void)

{
  DSK_PowerDown();
  DAT_c07260c0 = 0x34;
  DAT_c072610c = 1;
  DAT_c0726110 = 1;
  return 1;
}



/* c0723548 FUN_c0723548 */

/* Boundary evidence: original MIPS .pdata c0723548..c0723573. Semantic name remains unreviewed. */

undefined4 FUN_c0723548(void)

{
  DAT_c0726110 = 0;
  DAT_c072610c = 0;
  DSK_PowerDown();
  return 1;
}



/* c0723574 FUN_c0723574 */

/* Boundary evidence: original MIPS .pdata c0723574..c0723593. Semantic name remains unreviewed. */

void FUN_c0723574(SIZE_T param_1)

{
  LocalAlloc(0x40,param_1);
  return;
}



/* c0723594 FUN_c0723594 */

/* Boundary evidence: original MIPS .pdata c0723594..c07235af. Semantic name remains unreviewed. */

void FUN_c0723594(HLOCAL param_1)

{
  LocalFree(param_1);
  return;
}



/* c07235b0 FUN_c07235b0 */

/* Boundary evidence: original MIPS .pdata c07235b0..c0723637. Semantic name remains unreviewed. */

bool FUN_c07235b0(int *param_1,int param_2)

{
  bool bVar1;
  undefined4 *Exchange;
  LONG LVar2;
  
  Exchange = FUN_c0723ba0(param_2,*param_1,param_1 + 2);
  if (Exchange == (undefined4 *)0x0) {
    bVar1 = false;
  }
  else {
    LVar2 = InterlockedCompareExchange(param_1 + 1,(LONG)Exchange,0);
    if (LVar2 != 0) {
      FUN_c0723e14((int)Exchange);
    }
    bVar1 = param_1[1] != 0;
  }
  return bVar1;
}



/* c0723638 FUN_c0723638 */

/* Boundary evidence: original MIPS .pdata c0723638..c072369b. Semantic name remains unreviewed. */

void * FUN_c0723638(void *param_1,uint param_2)

{
  if (*(int *)((int)param_1 + 4) != 0) {
    FUN_c0723e14(*(int *)((int)param_1 + 4));
    *(undefined4 *)((int)param_1 + 4) = 0;
  }
  DeleteCriticalSection((LPCRITICAL_SECTION)((int)param_1 + 8));
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}



/* c072369c FUN_c072369c */

/* Boundary evidence: original MIPS .pdata c072369c..c07236cb. Semantic name remains unreviewed. */

void FUN_c072369c(int param_1,undefined4 *param_2)

{
  if ((param_1 != 0) && (param_2 != (undefined4 *)0x0)) {
    FUN_c0723d20(param_2,*(undefined4 **)(param_1 + 4));
  }
  return;
}



/* c07236cc FUN_c07236cc */

/* Boundary evidence: original MIPS .pdata c07236cc..c0723717. Semantic name remains unreviewed. */

int * FUN_c07236cc(int *param_1)

{
  bool bVar1;
  undefined3 extraout_var;
  int *piVar2;
  
  if ((param_1[1] == 0) &&
     (bVar1 = FUN_c07235b0(param_1,param_1[7]), CONCAT31(extraout_var,bVar1) == 0)) {
    piVar2 = (int *)0x0;
  }
  else {
    piVar2 = FUN_c0723c30((int *)param_1[1]);
  }
  return piVar2;
}



/* c0723718 FUN_c0723718 */

/* Boundary evidence: original MIPS .pdata c0723718..c072376f. Semantic name remains unreviewed. */

void FUN_c0723718(void *param_1)

{
  LONG LVar1;
  
  if (((param_1 != (void *)0x0) && (FUN_c0723638(param_1,1), DAT_c0726110 == 0)) &&
     (LVar1 = InterlockedDecrement((LONG *)&DAT_c0726108), LVar1 == 0)) {
    DAT_c072610c = 0;
    DSK_PowerDown();
  }
  return;
}



/* c0723770 FUN_c0723770 */

/* Boundary evidence: original MIPS .pdata c0723770..c072379f. Semantic name remains unreviewed. */

int * FUN_c0723770(int *param_1)

{
  int *piVar1;
  
  if (param_1 == (int *)0x0) {
    piVar1 = (int *)0x0;
  }
  else {
    piVar1 = FUN_c07236cc(param_1);
  }
  return piVar1;
}



/* c07237a0 FUN_c07237a0 */

/* Boundary evidence: original MIPS .pdata c07237a0..c07238b7. Semantic name remains unreviewed. */

int * FUN_c07237a0(undefined4 param_1,int param_2,int param_3)

{
  LONG LVar1;
  int *piVar2;
  int *piVar3;
  
  if (DAT_c0726110 == 0) {
    LVar1 = InterlockedIncrement((LONG *)&DAT_c0726108);
    if (LVar1 == 1) {
      DSK_PowerDown();
      DAT_c072610c = 1;
      DAT_c07260c0 = 0x34;
    }
    else {
      while (DAT_c072610c == 0) {
        Sleep(1);
      }
    }
  }
  piVar2 = operator_new(0x20);
  if (piVar2 == (int *)0x0) {
    piVar2 = (int *)0x0;
  }
  else {
    piVar2[1] = 0;
    *piVar2 = param_2;
    InitializeCriticalSection((LPCRITICAL_SECTION)(piVar2 + 2));
    piVar2[7] = param_3;
  }
  if (piVar2 != (int *)0x0) {
    piVar3 = FUN_c07236cc(piVar2);
    if (piVar3 == (int *)0x0) {
      FUN_c0723638(piVar2,1);
      piVar2 = (int *)0x0;
    }
    else {
      FUN_c0723d20(piVar3,(undefined4 *)piVar2[1]);
    }
  }
  return piVar2;
}



/* c07238b8 FUN_c07238b8 */

/* WARNING: Removing unreachable block (ram,0xc072395c) */
/* Boundary evidence: original MIPS .pdata c07238b8..c07239ab. Semantic name remains unreviewed. */

void FUN_c07238b8(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  int iVar2;
  DWORD DVar3;
  int local_28 [2];
  
  local_28[0] = 0;
  uVar1 = FUN_c072482c();
  iVar2 = BusIoControl(uVar1,0x2a0530,0,0,&DAT_c07260c0,0x34,local_28,0);
  DVar3 = GetLastError();
  if ((iVar2 == 0) || (local_28[0] != 0x34)) {
    DVar3 = FUN_c07247bc(&DAT_c07260c0);
  }
  if (-1 < (int)DVar3) {
    (*DAT_c07260c4)(param_1,param_2,param_3);
  }
  return;
}



/* c07239ac FUN_c07239ac */

/* Boundary evidence: original MIPS .pdata c07239ac..c0723b4b. Semantic name remains unreviewed. */

int FUN_c07239ac(LPCWSTR param_1,undefined4 *param_2)

{
  void *pvVar1;
  LSTATUS LVar2;
  LPBYTE lpData;
  DWORD local_28;
  HKEY local_24;
  int local_20 [2];
  
  local_20[0] = 0;
  local_24 = (HKEY)0x0;
  lpData = (LPBYTE)0x0;
  pvVar1 = FUN_c0724920(param_1);
  if (pvVar1 != (void *)0x0) {
    LVar2 = RegOpenKeyExW((HKEY)0x80000002,param_1,0,0,&local_24);
    if (LVar2 == 0) {
      LVar2 = RegQueryValueExW(local_24,L"Key",(LPDWORD)0x0,(LPDWORD)0x0,(LPBYTE)0x0,&local_28);
      if (((LVar2 == 0) && (local_28 != 0)) &&
         (lpData = (LPBYTE)FUN_c0723574(local_28), lpData != (LPBYTE)0x0)) {
        LVar2 = RegQueryValueExW(local_24,L"Key",(LPDWORD)0x0,(LPDWORD)0x0,lpData,&local_28);
        if (LVar2 == 0) {
          (lpData + ((local_28 & 0xfffffffe) - 2))[0] = '\0';
          (lpData + ((local_28 & 0xfffffffe) - 2))[1] = '\0';
          local_28 = 4;
          RegQueryValueExW(local_24,L"ClientInfo",(LPDWORD)0x0,(LPDWORD)0x0,(LPBYTE)local_20,
                           &local_28);
        }
      }
    }
  }
  if (local_24 != (HKEY)0x0) {
    RegCloseKey(local_24);
  }
  if (lpData != (LPBYTE)0x0) {
    if ((param_2 == (undefined4 *)0x0) || (local_20[0] == 0)) {
      FUN_c0723594(lpData);
    }
    else {
      *param_2 = lpData;
    }
  }
  return local_20[0];
}



/* c0723b4c FUN_c0723b4c */

/* Boundary evidence: original MIPS .pdata c0723b4c..c0723b67. Semantic name remains unreviewed. */

void FUN_c0723b4c(size_t param_1)

{
  malloc(param_1);
  return;
}



/* c0723b68 FUN_c0723b68 */

/* Boundary evidence: original MIPS .pdata c0723b68..c0723b83. Semantic name remains unreviewed. */

void FUN_c0723b68(void *param_1,size_t param_2)

{
  realloc(param_1,param_2);
  return;
}



/* c0723b84 FUN_c0723b84 */

/* Boundary evidence: original MIPS .pdata c0723b84..c0723b9f. Semantic name remains unreviewed. */

void FUN_c0723b84(void *param_1)

{
  free(param_1);
  return;
}



/* c0723ba0 FUN_c0723ba0 */

/* Boundary evidence: original MIPS .pdata c0723ba0..c0723c2f. Semantic name remains unreviewed. */

undefined4 * FUN_c0723ba0(int param_1,int param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  uint uVar2;
  
  uVar2 = param_1 + 3U & 0xfffffffc;
  puVar1 = (undefined4 *)(*(code *)PTR_FUN_c07260f4)(0x18,DAT_c0726114);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    *puVar1 = 0;
    puVar1[1] = 0;
    puVar1[2] = param_3;
    puVar1[3] = uVar2;
    puVar1[4] = param_2;
    puVar1[5] = uVar2 * param_2 + 8;
  }
  return puVar1;
}



/* c0723c30 FUN_c0723c30 */

/* Boundary evidence: original MIPS .pdata c0723c30..c0723d1f. Semantic name remains unreviewed. */

int * FUN_c0723c30(int *param_1)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  
  if ((LPCRITICAL_SECTION)param_1[2] != (LPCRITICAL_SECTION)0x0) {
    EnterCriticalSection((LPCRITICAL_SECTION)param_1[2]);
  }
  if (*param_1 == 0) {
    piVar2 = (int *)(*(code *)PTR_FUN_c07260f4)(param_1[5],DAT_c0726114);
    if (piVar2 == (int *)0x0) {
      if ((LPCRITICAL_SECTION)param_1[2] != (LPCRITICAL_SECTION)0x0) {
        LeaveCriticalSection((LPCRITICAL_SECTION)param_1[2]);
      }
      return (int *)0x0;
    }
    piVar4 = piVar2 + 2;
    *piVar2 = param_1[1];
    iVar3 = param_1[5];
    param_1[1] = (int)piVar2;
    *param_1 = (int)piVar4;
    for (piVar1 = (int *)(param_1[3] + (int)piVar4); piVar1 < (int *)(iVar3 + (int)piVar2);
        piVar1 = (int *)(param_1[3] + (int)piVar1)) {
      *piVar4 = (int)piVar1;
      piVar4 = piVar1;
    }
    *piVar4 = 0;
  }
  piVar2 = (int *)*param_1;
  *param_1 = *piVar2;
  if ((LPCRITICAL_SECTION)param_1[2] != (LPCRITICAL_SECTION)0x0) {
    LeaveCriticalSection((LPCRITICAL_SECTION)param_1[2]);
  }
  return piVar2;
}



/* c0723d20 FUN_c0723d20 */

/* Boundary evidence: original MIPS .pdata c0723d20..c0723d7b. Semantic name remains unreviewed. */

void FUN_c0723d20(undefined4 *param_1,undefined4 *param_2)

{
  if ((LPCRITICAL_SECTION)param_2[2] != (LPCRITICAL_SECTION)0x0) {
    EnterCriticalSection((LPCRITICAL_SECTION)param_2[2]);
  }
  *param_1 = *param_2;
  *param_2 = param_1;
  if ((LPCRITICAL_SECTION)param_2[2] != (LPCRITICAL_SECTION)0x0) {
    LeaveCriticalSection((LPCRITICAL_SECTION)param_2[2]);
  }
  return;
}



/* c0723d7c FUN_c0723d7c */

/* Boundary evidence: original MIPS .pdata c0723d7c..c0723e13. Semantic name remains unreviewed. */

void FUN_c0723d7c(int param_1)

{
  int *piVar1;
  int iVar2;
  
  if (*(LPCRITICAL_SECTION *)(param_1 + 8) != (LPCRITICAL_SECTION)0x0) {
    EnterCriticalSection(*(LPCRITICAL_SECTION *)(param_1 + 8));
  }
  piVar1 = (int *)*(int *)(param_1 + 4);
  while (piVar1 != (int *)0x0) {
    iVar2 = *piVar1;
    (*(code *)PTR_FUN_c07260f8)(piVar1,DAT_c0726118);
    piVar1 = (int *)iVar2;
  }
  if (*(LPCRITICAL_SECTION *)(param_1 + 8) != (LPCRITICAL_SECTION)0x0) {
    LeaveCriticalSection(*(LPCRITICAL_SECTION *)(param_1 + 8));
  }
  (*(code *)PTR_FUN_c07260f8)(param_1,DAT_c0726118);
  return;
}



/* c0723e14 FUN_c0723e14 */

/* Boundary evidence: original MIPS .pdata c0723e14..c0723e63. Semantic name remains unreviewed. */

void FUN_c0723e14(int param_1)

{
  if (*(LPCRITICAL_SECTION *)(param_1 + 8) != (LPCRITICAL_SECTION)0x0) {
    EnterCriticalSection(*(LPCRITICAL_SECTION *)(param_1 + 8));
  }
  if (*(LPCRITICAL_SECTION *)(param_1 + 8) != (LPCRITICAL_SECTION)0x0) {
    LeaveCriticalSection(*(LPCRITICAL_SECTION *)(param_1 + 8));
  }
  FUN_c0723d7c(param_1);
  return;
}



/* c0723e64 FUN_c0723e64 */

/* Boundary evidence: original MIPS .pdata c0723e64..c0723eb3. Semantic name remains unreviewed. */

void FUN_c0723e64(int param_1)

{
  if (*(int *)(param_1 + 0x34) != 0) {
    CloseBusAccessHandle();
  }
  if (*(HANDLE *)(param_1 + 0x38) != (HANDLE)0x0) {
    CloseHandle(*(HANDLE *)(param_1 + 0x38));
  }
  return;
}



/* c0723eb4 FUN_c0723eb4 */

/* Boundary evidence: original MIPS .pdata c0723eb4..c0723fb3. Semantic name remains unreviewed. */

undefined4 FUN_c0723eb4(int param_1,undefined4 *param_2,uint param_3)

{
  int iVar1;
  
  if (param_1 == 0x2a0500) {
    if (param_2 == (undefined4 *)0x0) {
      return 0;
    }
    if (param_3 < 0x14) {
      return 0;
    }
    if ((code *)*param_2 == (code *)0x0) {
      return 0;
    }
    (*(code *)*param_2)(param_2[1],param_2[2],param_2[3],param_2[4]);
  }
  else if (param_1 == 0x2a0504) {
    if (param_2 == (undefined4 *)0x0) {
      return 0;
    }
    if (param_3 < 0x18) {
      return 0;
    }
    if ((code *)*param_2 == (code *)0x0) {
      return 0;
    }
    iVar1 = 0;
    if (param_2[4] != 0) {
      iVar1 = param_2[4] + (int)param_2;
    }
    (*(code *)*param_2)(param_2[1],param_2[2],param_2[3],iVar1,param_2[5]);
  }
  else {
    if (param_1 != 0x2a0508) {
      return 0;
    }
    if (param_2 == (undefined4 *)0x0) {
      return 0;
    }
    if (param_3 < 0xc) {
      return 0;
    }
    if ((code *)*param_2 == (code *)0x0) {
      return 0;
    }
    (*(code *)*param_2)(param_2[1],param_2[2]);
  }
  return 1;
}



/* c0723fb4 FUN_c0723fb4 */

/* Boundary evidence: original MIPS .pdata c0723fb4..c07240a3. Semantic name remains unreviewed. */

DWORD FUN_c0723fb4(undefined4 param_1,undefined4 param_2,void *param_3)

{
  int iVar1;
  DWORD DVar2;
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 local_68;
  undefined1 auStack_64 [80];
  uint local_14;
  
  iVar1 = DAT_c072611c;
  local_14 = DAT_c0726100;
  if ((DAT_c072611c == 0) || (param_3 == (void *)0x0)) {
    FUN_c0724c1c(DAT_c0726100);
    DVar2 = 0xc0000008;
  }
  else {
    local_68 = *(undefined4 *)(DAT_c072611c + 0x38);
    local_70 = param_1;
    local_6c = param_2;
    memcpy(auStack_64,param_3,0x50);
    SetLastError(0);
    iVar1 = BusIoControl(*(undefined4 *)(iVar1 + 0x34),0x2a0500,&local_70,0x5c,0,0,0,0);
    DVar2 = GetLastError();
    if ((iVar1 == 0) && (-1 < (int)DVar2)) {
      DVar2 = 0xc0000008;
    }
    FUN_c0724c1c(local_14);
  }
  return DVar2;
}



/* c07240a4 FUN_c07240a4 */

/* Boundary evidence: original MIPS .pdata c07240a4..c072418f. Semantic name remains unreviewed. */

DWORD FUN_c07240a4(undefined4 param_1,undefined1 param_2,undefined4 param_3,undefined4 param_4,
                  undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
                  undefined4 param_9,uint param_10,undefined4 param_11,undefined4 param_12)

{
  int iVar1;
  DWORD DVar2;
  undefined4 local_38;
  undefined1 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  uint local_18;
  undefined4 local_14;
  undefined4 local_10;
  
  iVar1 = DAT_c072611c;
  if (DAT_c072611c != 0) {
    local_28 = param_5;
    local_24 = param_7;
    local_20 = param_8;
    local_1c = param_9;
    local_18 = param_10;
    local_14 = param_11;
    local_10 = param_12;
    if ((param_10 & 0x8000) == 0) {
      local_14 = 0;
      local_10 = 0;
    }
    local_38 = param_1;
    local_34 = param_2;
    local_30 = param_3;
    local_2c = param_4;
    SetLastError(0);
    iVar1 = BusIoControl(*(undefined4 *)(iVar1 + 0x34),0x2a0534,&local_38,0x2c,param_6,0x18,0,0);
    DVar2 = GetLastError();
    if (iVar1 != 0) {
      return DVar2;
    }
    if ((int)DVar2 < 0) {
      return DVar2;
    }
  }
  return 0xc0000008;
}



/* c0724190 FUN_c0724190 */

/* Boundary evidence: original MIPS .pdata c0724190..c072423b. Semantic name remains unreviewed. */

DWORD FUN_c0724190(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  DWORD DVar2;
  undefined4 local_res0 [4];
  
  iVar1 = DAT_c072611c;
  DVar2 = 0xc0000007;
  if (DAT_c072611c != 0) {
    local_res0[0] = param_1;
    SetLastError(0);
    iVar1 = BusIoControl(*(undefined4 *)(iVar1 + 0x34),0x2a052c,local_res0,4,param_2,0x18,0,0);
    DVar2 = GetLastError();
    if ((iVar1 == 0) && (-1 < (int)DVar2)) {
      DVar2 = 0xc0000007;
    }
  }
  return DVar2;
}



/* c072423c FUN_c072423c */

/* Boundary evidence: original MIPS .pdata c072423c..c0724343. Semantic name remains unreviewed. */

DWORD FUN_c072423c(undefined4 param_1,undefined1 param_2,undefined4 param_3,undefined4 param_4,
                  undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
                  undefined4 param_9,undefined4 param_10,undefined4 param_11,uint param_12,
                  undefined4 param_13,undefined4 param_14)

{
  int iVar1;
  DWORD DVar2;
  undefined4 local_48;
  undefined1 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  uint local_14;
  undefined4 local_10;
  undefined4 local_c;
  
  iVar1 = DAT_c072611c;
  if (DAT_c072611c != 0) {
    local_38 = param_5;
    local_34 = param_6;
    local_30 = param_7;
    local_2c = param_8;
    local_18 = param_10;
    local_28 = param_9;
    local_20 = 0;
    local_1c = 0;
    local_14 = param_12;
    local_10 = param_13;
    local_c = param_14;
    if ((param_12 & 0x8000) == 0) {
      local_10 = 0;
      local_c = 0;
    }
    local_48 = param_1;
    local_44 = param_2;
    local_40 = param_3;
    local_3c = param_4;
    local_24 = param_1;
    SetLastError(0);
    iVar1 = BusIoControl(*(undefined4 *)(iVar1 + 0x34),0x2a0538,&local_48,0x40,param_11,4,0,0);
    DVar2 = GetLastError();
    if (iVar1 != 0) {
      return DVar2;
    }
    if ((int)DVar2 < 0) {
      return DVar2;
    }
  }
  return 0xc0000008;
}



/* c0724344 FUN_c0724344 */

/* Boundary evidence: original MIPS .pdata c0724344..c07243ab. Semantic name remains unreviewed. */

undefined1 FUN_c0724344(undefined4 param_1)

{
  undefined1 uVar1;
  undefined4 local_res0 [4];
  
  local_res0[0] = param_1;
  if (DAT_c072611c == 0) {
    SetLastError(0x32);
    uVar1 = 0;
  }
  else {
    uVar1 = BusIoControl(*(undefined4 *)(DAT_c072611c + 0x34),0x2a0518,local_res0,4,0,0,0,0);
  }
  return uVar1;
}



/* c07243ac FUN_c07243ac */

/* Boundary evidence: original MIPS .pdata c07243ac..c07243f7. Semantic name remains unreviewed. */

void FUN_c07243ac(undefined4 param_1)

{
  undefined4 local_res0 [4];
  
  if (DAT_c072611c != 0) {
    local_res0[0] = param_1;
    BusIoControl(*(undefined4 *)(DAT_c072611c + 0x34),0x2a050c,local_res0,4,0,0,0,0);
  }
  return;
}



/* c07243f8 FUN_c07243f8 */

/* Boundary evidence: original MIPS .pdata c07243f8..c072449f. Semantic name remains unreviewed. */

DWORD FUN_c07243f8(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  DWORD DVar2;
  undefined4 local_18;
  undefined4 local_14;
  
  iVar1 = DAT_c072611c;
  if (DAT_c072611c != 0) {
    local_18 = param_1;
    local_14 = param_2;
    SetLastError(0);
    iVar1 = BusIoControl(*(undefined4 *)(iVar1 + 0x34),0x2a0510,&local_18,8,param_3,param_4,0,0);
    DVar2 = GetLastError();
    if (iVar1 != 0) {
      return DVar2;
    }
    if ((int)DVar2 < 0) {
      return DVar2;
    }
  }
  return 0xc0000008;
}



/* c07244a0 FUN_c07244a0 */

/* Boundary evidence: original MIPS .pdata c07244a0..c0724553. Semantic name remains unreviewed. */

DWORD FUN_c07244a0(undefined4 param_1,undefined4 param_2,undefined1 param_3,undefined4 param_4,
                  undefined1 param_5,undefined4 param_6,undefined4 param_7)

{
  int iVar1;
  DWORD DVar2;
  undefined4 local_28;
  undefined4 local_24;
  undefined1 local_20;
  undefined4 local_1c;
  undefined1 local_18;
  undefined4 local_14;
  undefined4 local_10;
  
  iVar1 = DAT_c072611c;
  if (DAT_c072611c != 0) {
    local_18 = param_5;
    local_14 = param_6;
    local_10 = param_7;
    local_28 = param_1;
    local_24 = param_2;
    local_20 = param_3;
    local_1c = param_4;
    SetLastError(0);
    iVar1 = BusIoControl(*(undefined4 *)(iVar1 + 0x34),0x2a0514,&local_28,0x1c,0,0,0,0);
    DVar2 = GetLastError();
    if (iVar1 != 0) {
      return DVar2;
    }
    if ((int)DVar2 < 0) {
      return DVar2;
    }
  }
  return 0xc0000008;
}



/* c0724554 FUN_c0724554 */

/* Boundary evidence: original MIPS .pdata c0724554..c072462f. Semantic name remains unreviewed. */

DWORD FUN_c0724554(undefined4 param_1,undefined1 param_2,undefined4 param_3,undefined4 *param_4,
                  undefined4 param_5)

{
  int iVar1;
  DWORD DVar2;
  undefined4 uVar3;
  undefined4 local_28 [2];
  undefined4 local_20;
  undefined1 local_1c;
  undefined4 local_18;
  
  iVar1 = DAT_c072611c;
  if (DAT_c072611c != 0) {
    local_18 = param_5;
    local_20 = param_1;
    local_1c = param_2;
    SetLastError(0);
    local_28[0] = 0;
    if (param_4 == (undefined4 *)0x0) {
      uVar3 = 0;
    }
    else {
      uVar3 = *param_4;
    }
    iVar1 = BusIoControl(*(undefined4 *)(iVar1 + 0x34),0x2a051c,&local_20,0xc,param_3,uVar3,local_28
                         ,0);
    DVar2 = GetLastError();
    if (iVar1 != 0) {
      if (param_4 == (undefined4 *)0x0) {
        return DVar2;
      }
      *param_4 = local_28[0];
      return DVar2;
    }
    if ((int)DVar2 < 0) {
      return DVar2;
    }
  }
  return 0xc0000008;
}



/* c0724630 FUN_c0724630 */

/* Boundary evidence: original MIPS .pdata c0724630..c07246d3. Semantic name remains unreviewed. */

DWORD FUN_c0724630(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  DWORD DVar2;
  undefined4 local_18;
  undefined4 local_14;
  undefined1 auStack_10 [8];
  
  iVar1 = DAT_c072611c;
  if (DAT_c072611c != 0) {
    local_18 = param_1;
    local_14 = param_2;
    memset(auStack_10,0,8);
    SetLastError(0);
    iVar1 = BusIoControl(*(undefined4 *)(iVar1 + 0x34),0x2a0520,&local_18,0x10,0,0,0,0);
    DVar2 = GetLastError();
    if (iVar1 != 0) {
      return DVar2;
    }
    if ((int)DVar2 < 0) {
      return DVar2;
    }
  }
  return 0xc0000008;
}



/* c07246d4 FUN_c07246d4 */

/* Boundary evidence: original MIPS .pdata c07246d4..c072471f. Semantic name remains unreviewed. */

void FUN_c07246d4(undefined4 param_1)

{
  undefined4 local_res0 [4];
  
  if (DAT_c072611c != 0) {
    local_res0[0] = param_1;
    BusIoControl(*(undefined4 *)(DAT_c072611c + 0x34),0x2a0524,local_res0,4,0,0,0,0);
  }
  return;
}



/* c0724720 FUN_c0724720 */

/* Boundary evidence: original MIPS .pdata c0724720..c07247bb. Semantic name remains unreviewed. */

DWORD FUN_c0724720(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  DWORD DVar2;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  
  iVar1 = DAT_c072611c;
  if (DAT_c072611c != 0) {
    local_18 = param_1;
    local_14 = param_2;
    local_10 = param_3;
    local_c = param_4;
    SetLastError(0);
    iVar1 = BusIoControl(*(undefined4 *)(iVar1 + 0x34),0x2a0528,&local_18,0x10,0,0,0,0);
    DVar2 = GetLastError();
    if (iVar1 != 0) {
      return DVar2;
    }
    if ((int)DVar2 < 0) {
      return DVar2;
    }
  }
  return 0xc0000008;
}



/* c07247bc FUN_c07247bc */

/* Boundary evidence: original MIPS .pdata c07247bc..c072482b. Semantic name remains unreviewed. */

undefined4 FUN_c07247bc(uint *param_1)

{
  undefined4 uVar1;
  
  if (((param_1 == (uint *)0x0) || (*param_1 < 0x34)) || (DAT_c072611c == (void *)0x0)) {
    uVar1 = 0xc0000007;
  }
  else {
    memcpy(param_1,DAT_c072611c,0x34);
    *param_1 = 0x34;
    uVar1 = 0;
  }
  return uVar1;
}



/* c072482c FUN_c072482c */

undefined4 FUN_c072482c(void)

{
  undefined4 uVar1;
  
  if (DAT_c072611c == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = *(undefined4 *)(DAT_c072611c + 0x34);
  }
  return uVar1;
}



/* c0724850 FUN_c0724850 */

/* Boundary evidence: original MIPS .pdata c0724850..c072491f. Semantic name remains unreviewed. */

int FUN_c0724850(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  uVar1 = CreateBusAccessHandle(param_2);
  *(undefined4 *)(param_1 + 0x34) = uVar1;
  uVar1 = CeDriverMapCallbackFunction(FUN_c0723eb4);
  *(code **)(param_1 + 4) = FUN_c0723fb4;
  *(code **)(param_1 + 8) = FUN_c07240a4;
  *(code **)(param_1 + 0xc) = FUN_c072423c;
  *(code **)(param_1 + 0x10) = FUN_c07243ac;
  *(code **)(param_1 + 0x14) = FUN_c07243f8;
  *(code **)(param_1 + 0x18) = FUN_c07244a0;
  *(code **)(param_1 + 0x1c) = FUN_c0724344;
  *(code **)(param_1 + 0x20) = FUN_c0724554;
  *(code **)(param_1 + 0x24) = FUN_c0724630;
  *(undefined4 *)(param_1 + 0x38) = uVar1;
  *(code **)(param_1 + 0x28) = FUN_c07246d4;
  *(code **)(param_1 + 0x2c) = FUN_c0724720;
  *(code **)(param_1 + 0x30) = FUN_c0724190;
  return param_1;
}



/* c0724920 FUN_c0724920 */

/* Boundary evidence: original MIPS .pdata c0724920..c07249c3. Semantic name remains unreviewed. */

void * FUN_c0724920(undefined4 param_1)

{
  void *pvVar1;
  void *pvVar2;
  
  pvVar1 = DAT_c072611c;
  if (DAT_c072611c == (void *)0x0) {
    pvVar1 = operator_new(0x3c);
    if (pvVar1 == (void *)0x0) {
      pvVar2 = (void *)0x0;
    }
    else {
      pvVar2 = (void *)FUN_c0724850((int)pvVar1,param_1);
    }
    pvVar1 = DAT_c072611c;
    if ((pvVar2 != (void *)0x0) &&
       ((*(int *)((int)pvVar2 + 0x34) == 0 || (pvVar1 = pvVar2, *(int *)((int)pvVar2 + 0x38) == 0)))
       ) {
      FUN_c0723e64((int)pvVar2);
      operator_delete(pvVar2);
      pvVar1 = DAT_c072611c;
    }
  }
  DAT_c072611c = pvVar1;
  return DAT_c072611c;
}



/* c0724ab4 entry */

/* Boundary evidence: original MIPS .pdata c0724ab4..c0724b27. Semantic name remains unreviewed. */

undefined4 entry(HMODULE param_1,int param_2)

{
  undefined4 uVar1;
  
  if (param_2 == 1) {
    FUN_c0724b28();
    FUN_c0724e78();
  }
  uVar1 = FUN_c07212bc(param_1,param_2);
  if (param_2 == 0) {
    FUN_c0724e00();
  }
  return uVar1;
}



/* c0724b28 FUN_c0724b28 */

/* Boundary evidence: original MIPS .pdata c0724b28..c0724b9b. Semantic name remains unreviewed. */

void FUN_c0724b28(void)

{
  uint uVar1;
  
  if ((DAT_c0726100 == 0) || (DAT_c0726100 == 0xb064)) {
    uVar1 = __security_gen_cookie2();
    DAT_c0726100 = uVar1 >> 0x10 ^ uVar1 & 0xffff;
    if (DAT_c0726100 == 0) {
      DAT_c0726100 = 0xb064;
    }
  }
  DAT_c0726104 = ~DAT_c0726100;
  return;
}



/* c0724b9c FUN_c0724b9c */

/* Boundary evidence: original MIPS .pdata c0724b9c..c0724bef. Semantic name remains unreviewed. */

void FUN_c0724b9c(int param_1,undefined4 param_2,uint *param_3)

{
  if ((*param_3 & 1) != 0) {
    param_1 = ((-param_3[2] & param_3[1] + param_1) - (param_3[1] + param_1)) + param_1;
  }
  FUN_c0724c1c(*(uint *)(param_1 + (*param_3 & 0xfffffffc)));
  return;
}



/* c0724bf0 FUN_c0724bf0 */

/* Boundary evidence: original MIPS .pdata c0724bf0..c0724c1b. Semantic name remains unreviewed. */

undefined4 FUN_c0724bf0(undefined4 param_1,int param_2,undefined4 param_3,int param_4)

{
  FUN_c0724b9c(param_2,param_4,*(uint **)(*(int *)(param_4 + 4) + 0xc));
  return 1;
}



/* c0724c1c FUN_c0724c1c */

/* Boundary evidence: original MIPS .pdata c0724c1c..c0724c63. Semantic name remains unreviewed. */

void FUN_c0724c1c(uint param_1)

{
  if ((param_1 == DAT_c0726100) && (param_1 >> 0x10 == 0)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __report_gsfailure();
}



/* c0724c64 FUN_c0724c64 */

/* Boundary evidence: original MIPS .pdata c0724c64..c0724cdf. Semantic name remains unreviewed. */

void FUN_c0724c64(undefined4 param_1,int param_2,undefined4 param_3,int param_4)

{
  int *piVar1;
  
  piVar1 = *(int **)(*(int *)(param_4 + 4) + 0xc);
  FUN_c0724b9c(param_2,param_4,(uint *)(piVar1 + *piVar1 * 4 + 1));
  __C_specific_handler(param_1,param_2,param_3,param_4);
  return;
}



/* c0724ce0 FUN_c0724ce0 */

/* Boundary evidence: original MIPS .pdata c0724ce0..c0724dff. Semantic name remains unreviewed. */

void FUN_c0724ce0(UINT param_1,int param_2,int param_3)

{
  LPCRITICAL_SECTION lpCriticalSection;
  undefined4 *_Memory;
  
  DAT_c0726120 = (undefined1)param_3;
  if (param_2 == 0) {
    _Memory = DAT_c0726128;
    if (DAT_c0726128 != (undefined4 *)0x0) {
      while (DAT_c0726124 = DAT_c0726124 + -1, _Memory <= DAT_c0726124) {
        if ((code *)*DAT_c0726124 != (code *)0x0) {
          (*(code *)*DAT_c0726124)();
          _Memory = DAT_c0726128;
        }
      }
      free(_Memory);
      DAT_c0726124 = (undefined4 *)0x0;
      DAT_c0726128 = (undefined4 *)0x0;
    }
    FUN_c0724e24((undefined4 *)&DAT_c0721010,(undefined4 *)&DAT_c0721014);
  }
  FUN_c0724e24((undefined4 *)&DAT_c0721018,(undefined4 *)&DAT_c072101c);
  if (param_3 == 0) {
    TerminateProcess((HANDLE)0x42,param_1);
  }
  else {
    lpCriticalSection = (LPCRITICAL_SECTION)InterlockedExchange((LONG *)&DAT_c072612c,0);
    if (lpCriticalSection != (LPCRITICAL_SECTION)0x0) {
      DeleteCriticalSection(lpCriticalSection);
      free(lpCriticalSection);
    }
  }
  return;
}



/* c0724e00 FUN_c0724e00 */

/* Boundary evidence: original MIPS .pdata c0724e00..c0724e23. Semantic name remains unreviewed. */

void FUN_c0724e00(void)

{
  FUN_c0724ce0(0,0,1);
  return;
}



/* c0724e24 FUN_c0724e24 */

/* Boundary evidence: original MIPS .pdata c0724e24..c0724e77. Semantic name remains unreviewed. */

void FUN_c0724e24(undefined4 *param_1,undefined4 *param_2)

{
  for (; param_1 < param_2; param_1 = param_1 + 1) {
    if ((code *)*param_1 != (code *)0x0) {
      (*(code *)*param_1)();
    }
  }
  return;
}



/* c0724e78 FUN_c0724e78 */

/* Boundary evidence: original MIPS .pdata c0724e78..c0724eb3. Semantic name remains unreviewed. */

void FUN_c0724e78(void)

{
  FUN_c0724e24((undefined4 *)&DAT_c0721008,(undefined4 *)&DAT_c072100c);
  FUN_c0724e24((undefined4 *)&DAT_c0721000,(undefined4 *)&DAT_c0721004);
  return;
}


