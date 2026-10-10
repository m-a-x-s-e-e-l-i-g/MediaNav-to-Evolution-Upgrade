/* Automatic Ghidra pseudocode. Not original source; not runtime-verified. */

/* c05f1640 FUN_c05f1640 */

/* Boundary evidence: original MIPS .pdata c05f1640..c05f16af. Semantic name remains unreviewed. */

int FUN_c05f1640(int param_1)

{
  int iVar1;
  undefined1 auStack_10 [8];
  
  iVar1 = 0;
  if ((*(uint *)(param_1 + 0x20) & 0x80) == 0) {
    *(uint *)(param_1 + 0x20) = *(uint *)(param_1 + 0x20) | 0x80;
    iVar1 = (**(code **)(*(int *)(param_1 + 0xc) + 0x24))
                      (*(undefined4 *)(param_1 + 0x14),0,0,auStack_10);
    if (iVar1 == 0) {
      *(uint *)(param_1 + 0x20) = *(uint *)(param_1 + 0x20) & 0xffffff7f;
    }
  }
  return iVar1;
}



/* c05f16b0 FUN_c05f16b0 */

/* Boundary evidence: original MIPS .pdata c05f16b0..c05f182b. Semantic name remains unreviewed. */

undefined4 FUN_c05f16b0(int param_1)

{
  HMODULE hLibModule;
  code *pcVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 local_848;
  undefined4 local_844;
  int local_840 [2];
  undefined1 local_838;
  undefined1 local_837;
  undefined1 local_836;
  undefined1 local_835;
  undefined1 local_834;
  undefined1 local_833;
  undefined1 local_832;
  undefined1 local_831;
  undefined1 local_830;
  undefined1 local_82f;
  undefined1 local_82e;
  undefined4 local_82c;
  undefined1 local_828;
  undefined1 local_827;
  int local_820;
  int local_81c;
  uint local_20;
  
  local_20 = DAT_c05f9108;
  hLibModule = LoadLibraryW(L"tcpstk.dll");
  if (hLibModule == (HMODULE)0x0) {
    FUN_c05f7e0c(local_20);
    uVar3 = 0;
  }
  else {
    uVar3 = 0;
    pcVar1 = (code *)GetProcAddressW(hLibModule,L"VXDEchoRequest");
    if (pcVar1 != (code *)0x0) {
      local_840[1] = 1000;
      local_838 = 0x14;
      local_836 = 5;
      local_837 = 0;
      local_835 = 0;
      local_82c = 0x50434844;
      local_828 = 0x43;
      local_827 = 0;
      local_830 = 0;
      local_834 = 0;
      local_833 = 1;
      local_832 = 0;
      local_831 = 0;
      local_82f = 0;
      local_82e = 0;
      local_848 = 0x1c;
      local_844 = 0x800;
      local_840[0] = param_1;
      iVar2 = (*pcVar1)(local_840,&local_848,&local_820,&local_844);
      if (((iVar2 == 0) && (local_81c == 0)) && (local_820 == param_1)) {
        uVar3 = 1;
      }
    }
    FreeLibrary(hLibModule);
    FUN_c05f7e0c(local_20);
  }
  return uVar3;
}



/* c05f182c FUN_c05f182c */

/* Boundary evidence: original MIPS .pdata c05f182c..c05f18b3. Semantic name remains unreviewed. */

int FUN_c05f182c(int param_1)

{
  bool bVar1;
  undefined3 extraout_var;
  int iVar2;
  
  if (((*(int *)(param_1 + 0x5c) != 0) && (*(int *)(param_1 + 100) != 0)) &&
     (bVar1 = FUN_c05f45b8(param_1), CONCAT31(extraout_var,bVar1) != 0)) {
    iVar2 = FUN_c05f4360(param_1);
    if (iVar2 != 0) {
      return iVar2;
    }
    iVar2 = FUN_c05f16b0(*(int *)(param_1 + 100));
    if (iVar2 != 0) {
      FUN_c05f497c((LPVOID)0xb);
      return 0;
    }
    FUN_c05f3af4(param_1,0);
  }
  return 1;
}



/* c05f18b4 FUN_c05f18b4 */

/* Boundary evidence: original MIPS .pdata c05f18b4..c05f1b07. Semantic name remains unreviewed. */

void FUN_c05f18b4(undefined4 param_1,int *param_2)

{
  undefined4 *puVar1;
  int iVar2;
  DWORD DVar3;
  int iVar4;
  int local_ec8 [2];
  undefined1 auStack_ec0 [3736];
  uint local_28;
  
  local_28 = DAT_c05f9108;
  puVar1 = FUN_c05f2d04(param_2,(wchar_t *)0x0);
  if (puVar1 == (undefined4 *)0x0) goto LAB_c05f1a3c;
  iVar2 = FUN_c05f1640((int)param_2);
  if ((iVar2 != 0) && (DVar3 = FUN_c05f4008((int)param_2,0), DVar3 == 0)) {
    iVar2 = param_2[0x17];
    param_2[0x17] = 0;
    FUN_c05f6604((int)param_2,auStack_ec0,1,1,(byte *)(param_2 + 0x3c),local_ec8);
    param_2[0x17] = iVar2;
    if ((param_2[8] & 0x1000U) == 0) {
      iVar4 = FUN_c05f7648(param_2,(int)auStack_ec0,local_ec8[0],2,0x101);
    }
    else {
      param_2[8] = param_2[8] & 0xffffefff;
      iVar4 = FUN_c05f7648(param_2,(int)auStack_ec0,local_ec8[0],2,0x104);
    }
    if (iVar4 != 8) {
      if ((iVar4 != 0) || ((param_2[0x18] & param_2[0x17]) != param_2[0x54])) {
LAB_c05f1a6c:
        FUN_c05f3e44((int)param_2);
        FUN_c05f4244((int)param_2);
        if (iVar4 == 0) {
          FUN_c05f37e8((int)param_2);
          param_2[0x17] = iVar2;
          FUN_c05f3af4((int)param_2,0);
          param_2[8] = param_2[8] & 0xffffffef;
          FUN_c05f543c(param_2[3],(wchar_t *)(param_2 + 0x5a),param_2[4],param_2[5],param_2 + 0xb,
                       param_2[0xf]);
        }
        else {
          CTEStartTimer(param_2 + 0x35,param_2[0x57] * 1000,FUN_c05f18b4,param_2);
        }
        goto LAB_c05f1a2c;
      }
      param_2[0x17] = iVar2;
      FUN_c05f6604((int)param_2,auStack_ec0,3,4,(byte *)(param_2 + 0x3c),local_ec8);
      iVar4 = FUN_c05f7648(param_2,(int)auStack_ec0,local_ec8[0],5,0x104);
      if (iVar4 != 8) {
        if (iVar4 != 0) {
          iVar4 = 0;
          goto LAB_c05f1a6c;
        }
        FUN_c05f37e8((int)param_2);
      }
    }
    FUN_c05f3e44((int)param_2);
    FUN_c05f4244((int)param_2);
  }
LAB_c05f1a2c:
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_2 + 0x2b));
  FUN_c05f4ab4(param_2);
LAB_c05f1a3c:
  FUN_c05f7e0c(local_28);
  return;
}



/* c05f1b08 ARPResult */

/* Boundary evidence: original MIPS .pdata c05f1b08..c05f1b9b. Semantic name remains unreviewed. */

void ARPResult(int param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  
                    /* 0x1b08  1  ARPResult */
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c05f9160);
  puVar1 = DAT_c05f9180;
  if ((undefined4 **)DAT_c05f9180 != &DAT_c05f9180) {
    do {
      if (puVar1[0x17] == param_1) {
        puVar1[0x59] = param_2;
        if (puVar1[0x58] != 0) {
          EventModify(puVar1[0x58],3);
        }
        break;
      }
      puVar1 = (undefined4 *)*puVar1;
    } while ((undefined4 **)puVar1 != &DAT_c05f9180);
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c05f9160);
  return;
}



/* c05f1b9c FUN_c05f1b9c */

/* Boundary evidence: original MIPS .pdata c05f1b9c..c05f1ca3. Semantic name remains unreviewed. */

uint FUN_c05f1b9c(byte *param_1,int param_2,uint *param_3,uint param_4,uint param_5)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  byte *pbVar5;
  int iVar6;
  uint uVar7;
  
  if (*param_3 == 0) {
    uVar1 = CeGetRandomSeed();
    *param_3 = uVar1;
  }
  iVar4 = 5;
  uVar1 = ~param_4;
  do {
    uVar3 = *param_3 * 0x41c64e6d + 0x3039;
    uVar2 = uVar3 * 0x41c64e6d + 0x3039;
    *param_3 = uVar2;
    uVar3 = (uVar2 >> 0x10) + (uVar3 & 0xffff0000);
    uVar2 = uVar3;
    pbVar5 = param_1;
    for (iVar6 = param_2; iVar6 != 0; iVar6 = iVar6 + -1) {
      uVar7 = uVar3 & 3;
      uVar3 = uVar7 + 1;
      uVar2 = ((uint)*pbVar5 << (uVar7 << 3)) + uVar2;
      pbVar5 = pbVar5 + 1;
    }
    uVar2 = uVar1 & uVar2;
    if ((uVar2 != 0) && (uVar2 != uVar1)) goto LAB_c05f1c7c;
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  uVar2 = uVar1 & 5;
LAB_c05f1c7c:
  return uVar2 | param_5;
}



/* c05f1ca4 FUN_c05f1ca4 */

/* Boundary evidence: original MIPS .pdata c05f1ca4..c05f1fa3. Semantic name remains unreviewed. */

int FUN_c05f1ca4(int param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  uint local_30;
  undefined4 local_2c;
  
  *(uint *)(param_1 + 0x20) = *(uint *)(param_1 + 0x20) & 0xffffffef;
  if ((*(ushort *)(param_1 + 0x18) & 0x80) == 0) {
    iVar1 = FUN_c05f182c(param_1);
    if (iVar1 == 0) {
      return 0;
    }
  }
  else {
    *(ushort *)(param_1 + 0x18) = *(ushort *)(param_1 + 0x18) & 0xff7f;
  }
  local_30 = *(uint *)(param_1 + 0x158);
  local_2c = *(undefined4 *)(param_1 + 0x5c);
  uVar5 = *(uint *)(param_1 + 0x154);
  uVar6 = *(uint *)(param_1 + 0x150);
  iVar7 = *(int *)(param_1 + 0x3c);
  iVar4 = 0x1f;
  iVar1 = FUN_c05f1640(param_1);
  if (iVar1 != 0) {
    uVar3 = *(uint *)(param_1 + 0x14c);
    if (uVar3 == 0) {
      uVar3 = FUN_c05f1b9c((byte *)(param_1 + 0x2c),iVar7,&local_30,uVar5,uVar6);
    }
    iVar1 = 0x14;
    iVar8 = 2;
    do {
      if ((*(uint *)(param_1 + 0x20) & 8) != 0) goto LAB_c05f1f60;
      if (((uVar3 & 0xffffff) != 0xfffea9) && ((uVar3 & 0xffffff) != 0xfea9)) {
        *(undefined4 *)(param_1 + 0x164) = 0;
        *(uint *)(param_1 + 0x5c) = uVar3;
        EventModify(*(undefined4 *)(param_1 + 0x160),2);
        iVar2 = (**(code **)(*(int *)(param_1 + 0xc) + 0x28))
                          (*(undefined2 *)(param_1 + 0x14),0,*(undefined4 *)(param_1 + 0x5c),uVar5,0
                          );
        if (iVar2 == 0x2bf7) {
          WaitForSingleObject(*(HANDLE *)(param_1 + 0x160),5000);
          iVar2 = 0;
        }
        if (iVar2 == 0) {
          if (*(int *)(param_1 + 0x164) == 0) {
            if ((*(uint *)(param_1 + 0x20) & 0x1000) != 0) {
              iVar8 = 10;
            }
            *(uint *)(param_1 + 0x158) = local_30;
            *(uint *)(param_1 + 0x20) = *(uint *)(param_1 + 0x20) | 0x810;
            *(uint *)(param_1 + 0x14c) = uVar3;
            *(uint *)(param_1 + 0x60) = uVar5;
            (*DAT_c05f91a0)(param_1 + 0x168,*(undefined4 *)(param_1 + 0x10),
                            *(undefined4 *)(param_1 + 0x14),0,*(undefined4 *)(param_1 + 0x5c),uVar5,
                            0,param_1 + 0x68,0,param_1 + 0x7c);
            iVar4 = 0;
            CTEStartTimer(param_1 + 0xd4,iVar8 * 1000,FUN_c05f18b4,param_1);
            if (iVar1 != 0) goto LAB_c05f1f68;
            break;
          }
          (**(code **)(*(int *)(param_1 + 0xc) + 0x28))(*(undefined2 *)(param_1 + 0x14),0,0,0,0);
          (**(code **)(*(int *)(param_1 + 0xc) + 0x24))
                    (*(undefined4 *)(param_1 + 0x14),0,0,&local_30);
        }
        else {
          iVar1 = 1;
        }
      }
      uVar3 = FUN_c05f1b9c((byte *)(param_1 + 0x2c),iVar7,&local_30,uVar5,uVar6);
      iVar1 = iVar1 + -1;
    } while (iVar1 != 0);
    (**(code **)(*(int *)(param_1 + 0xc) + 0x28))(*(undefined2 *)(param_1 + 0x14),0,0,0,0);
    if (iVar4 == 0) goto LAB_c05f1f68;
  }
LAB_c05f1f60:
  *(undefined4 *)(param_1 + 0x5c) = local_2c;
LAB_c05f1f68:
  FUN_c05f4244(param_1);
  return iVar4;
}



/* c05f1fa4 FUN_c05f1fa4 */

/* Boundary evidence: original MIPS .pdata c05f1fa4..c05f1fff. Semantic name remains unreviewed. */

int FUN_c05f1fa4(wchar_t *param_1)

{
  int iVar1;
  int *piVar2;
  
  piVar2 = (int *)DAT_c05f9194;
  while ((piVar2 != (int *)0x0 &&
         (iVar1 = wcsncmp(param_1,(wchar_t *)(piVar2 + 1),0x10), iVar1 != 0))) {
    piVar2 = (int *)*piVar2;
  }
  return (int)piVar2;
}



/* c05f2000 DhcpRegister */

/* Boundary evidence: original MIPS .pdata c05f2000..c05f20cf. Semantic name remains unreviewed. */

undefined4 *
DhcpRegister(wchar_t *param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4)

{
  undefined4 *puVar1;
  
                    /* 0x2000  3  DhcpRegister */
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c05f91c0);
  puVar1 = (undefined4 *)FUN_c05f1fa4(param_1);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = LocalAlloc(0x40,0x2c);
    if (puVar1 == (undefined4 *)0x0) goto LAB_c05f20a0;
    *puVar1 = DAT_c05f9194;
    DAT_c05f9194 = puVar1;
    wcsncpy((wchar_t *)(puVar1 + 1),param_1,0x10);
  }
  puVar1[9] = param_2;
  puVar1[10] = param_3;
  *param_4 = FUN_c05f56a0;
LAB_c05f20a0:
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c05f91c0);
  return puVar1;
}



/* c05f20d0 DllEntry */

/* Boundary evidence: original MIPS .pdata c05f20d0..c05f212b. Semantic name remains unreviewed. */

undefined4 DllEntry(HMODULE param_1,int param_2)

{
                    /* 0x20d0  4  DllEntry */
  if (param_2 == 1) {
    InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_c05f91c0);
    CTEInitEvent(&DAT_c05f9140,FUN_c05f6268);
    DisableThreadLibraryCalls(param_1);
  }
  return 1;
}



/* c05f212c FUN_c05f212c */

/* Boundary evidence: original MIPS .pdata c05f212c..c05f22eb. Semantic name remains unreviewed. */

void FUN_c05f212c(void)

{
  HLOCAL hMem;
  HLOCAL hMem_00;
  HLOCAL hMem_01;
  HANDLE hObject;
  uint uVar1;
  
  hMem = LocalAlloc(0x40,0x68);
  hMem_00 = LocalAlloc(0x40,0x28);
  hMem_01 = LocalAlloc(0x40,0x114);
  hObject = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
  if (hMem != (HLOCAL)0x0) {
    while ((hMem_00 != (HLOCAL)0x0 && (hMem_01 != (HLOCAL)0x0))) {
      *(undefined4 *)((int)hMem_00 + 8) = 0x114;
      *(undefined4 *)((int)hMem_00 + 0x10) = 0x12802c;
      *(undefined4 *)((int)hMem_00 + 0xc) = 4;
      *(HLOCAL *)((int)hMem + 8) = hMem_01;
      *(HLOCAL *)((int)hMem + 0x60) = hMem_00;
      *(HANDLE *)((int)hMem + 0x28) = hObject;
      (*DAT_c05f9190)(hMem,hMem_00);
      WaitForSingleObject(hObject,0xffffffff);
      uVar1 = (uint)(*(ushort *)((int)hMem_01 + 0xc) >> 1);
      if (uVar1 < 0x80) {
        *(undefined2 *)(uVar1 * 2 + *(int *)((int)hMem_01 + 0x10)) = 0;
      }
      else {
        *(undefined2 *)(*(int *)((int)hMem_01 + 0x10) + 0xfe) = 0;
      }
      if (*(int *)((int)hMem_01 + 8) == 0x2b10) {
        FUN_c05f5660((uint)*(ushort *)((int)hMem_01 + 4),*(wchar_t **)((int)hMem_01 + 0x10));
      }
      else if (*(int *)((int)hMem_01 + 8) == 0x2b11) {
        FUN_c05f5680((uint)*(ushort *)((int)hMem_01 + 4),*(wchar_t **)((int)hMem_01 + 0x10));
      }
    }
    LocalFree(hMem);
  }
  if (hMem_00 != (HLOCAL)0x0) {
    LocalFree(hMem_00);
  }
  if (hMem_01 != (HLOCAL)0x0) {
    LocalFree(hMem_01);
  }
  if (hObject != (HANDLE)0x0) {
    CloseHandle(hObject);
  }
  return;
}



/* c05f22ec FUN_c05f22ec */

/* Boundary evidence: original MIPS .pdata c05f22ec..c05f2383. Semantic name remains unreviewed. */

undefined4 FUN_c05f22ec(void)

{
  HMODULE pHVar1;
  HANDLE hObject;
  undefined4 uVar2;
  
  uVar2 = 0;
  pHVar1 = LoadLibraryW(L"tcpstk.dll");
  if (pHVar1 != (HMODULE)0x0) {
    DAT_c05f9190 = GetProcAddressW(pHVar1,L"IPDispatchDeviceControl");
    if (DAT_c05f9190 != 0) {
      hObject = CreateThread((LPSECURITY_ATTRIBUTES)0x0,0,FUN_c05f212c,(LPVOID)0x0,0,(LPDWORD)0x0);
      if (hObject != (HANDLE)0x0) {
        uVar2 = 1;
        CloseHandle(hObject);
      }
    }
  }
  return uVar2;
}



/* c05f2384 Dhcp */

/* Boundary evidence: original MIPS .pdata c05f2384..c05f2503. Semantic name remains unreviewed. */

undefined4
Dhcp(undefined4 param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,
    undefined4 param_6,undefined4 *param_7)

{
  HMODULE hLibModule;
  LSTATUS LVar1;
  undefined4 uVar2;
  undefined8 uVar3;
  HKEY local_20 [2];
  uint local_18;
  uint local_14;
  
                    /* 0x2384  2  Dhcp */
  uVar2 = 1;
  if (param_2 == 1) {
    DAT_c05f9198 = param_5;
    DAT_c05f91a8 = param_3;
    *param_7 = 0x19;
    InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_c05f9160);
    DAT_c05f9184 = &DAT_c05f9180;
    DAT_c05f9180 = &DAT_c05f9180;
    DAT_c05f9194 = 0;
    GetCurrentFT(&local_18);
    uVar3 = CeGetRandomSeed();
    DAT_c05f9174 = (uint)((ulonglong)uVar3 >> 0x20) ^ (uint)uVar3 ^
                   (local_18 & 0xf800 | local_14 & 0x788);
    hLibModule = LoadLibraryW(L"afd.dll");
    if (hLibModule != (HMODULE)0x0) {
      DAT_c05f91a0 = GetProcAddressW(hLibModule,L"AfdAddInterface");
      FreeLibrary(hLibModule);
    }
    FUN_c05f22ec();
    LVar1 = RegOpenKeyExW((HKEY)0x80000002,L"Comm\\Tcpip\\Parms",0,0,local_20);
    if (LVar1 == 0) {
      GetRegDWORDValue(local_20[0],L"DhcpGlobalInitDelayInterval",&DAT_c05f91a4);
      GetRegDWORDValue(local_20[0],L"ReUseDhcpInfoWhileAPRoaming",&DAT_c05f919c);
      RegCloseKey(local_20[0]);
    }
  }
  else if (param_2 != 2) {
    uVar2 = 0;
  }
  return uVar2;
}



/* c05f2504 FUN_c05f2504 */

/* Boundary evidence: original MIPS .pdata c05f2504..c05f25bf. Semantic name remains unreviewed. */

undefined4 FUN_c05f2504(undefined4 param_1,undefined4 param_2)

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



/* c05f25c0 FUN_c05f25c0 */

/* Boundary evidence: original MIPS .pdata c05f25c0..c05f26af. Semantic name remains unreviewed. */

undefined4
FUN_c05f25c0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
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



/* c05f26b0 FUN_c05f26b0 */

/* Boundary evidence: original MIPS .pdata c05f26b0..c05f271b. Semantic name remains unreviewed. */

undefined4 FUN_c05f26b0(undefined4 param_1)

{
  int iVar1;
  undefined4 local_18 [2];
  undefined4 local_10;
  undefined4 local_c;
  
  local_18[0] = 0;
  local_10 = 0;
  local_c = param_1;
  iVar1 = FUN_c05f2504(0x51,60000);
  if (iVar1 == 0) {
    FUN_c05f25c0(L"netui.dll",L"GetNetStringSizeExt",&local_10,8,&local_10,8,local_18);
  }
  return local_10;
}



/* c05f271c FUN_c05f271c */

/* Boundary evidence: original MIPS .pdata c05f271c..c05f2837. Semantic name remains unreviewed. */

undefined4 FUN_c05f271c(undefined4 param_1,void *param_2,uint param_3)

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
      iVar1 = FUN_c05f2504(0x51,60000);
      if ((iVar1 == 0) &&
         (iVar1 = FUN_c05f25c0(L"netui.dll",L"GetNetStringExt",hMem,uBytes,hMem,uBytes,local_20),
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



/* c05f2838 FUN_c05f2838 */

/* Boundary evidence: original MIPS .pdata c05f2838..c05f29ef. Semantic name remains unreviewed. */

undefined4 FUN_c05f2838(undefined4 param_1,undefined4 param_2,undefined4 param_3,va_list param_4)

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
  iVar1 = FUN_c05f2504(0x51,60000);
  if (iVar1 != 0) {
    return 0;
  }
  iVar1 = FUN_c05f26b0(param_3);
  if (iVar1 == 0) {
    uVar4 = 0;
    goto LAB_c05f29a4;
  }
  lpSource = LocalAlloc(0x40,(iVar1 + 1U) * 2);
  if (lpSource == (HLOCAL)0x0) {
LAB_c05f28c4:
    uVar4 = 0;
  }
  else {
    DVar2 = FUN_c05f271c(param_3,lpSource,iVar1 + 1U);
    DVar2 = FormatMessageW(0x500,lpSource,0,0,(LPWSTR)&local_28,DVar2,&local_resc);
    if (DVar2 == 0) goto LAB_c05f28c4;
    sVar3 = wcslen(local_28);
    sVar3 = (sVar3 + 1) * 2;
    uBytes = sVar3 + 0x10;
    hMem = LocalAlloc(0x40,uBytes);
    if (hMem == (undefined4 *)0x0) goto LAB_c05f28c4;
    *hMem = 0;
    hMem[1] = param_1;
    hMem[2] = param_2;
    memcpy(hMem + 3,local_28,sVar3);
    iVar1 = FUN_c05f25c0(L"netui.dll",L"NetMsgBoxExt",hMem,uBytes,hMem,uBytes,&local_24);
    uVar4 = 0;
    if (iVar1 != 0) {
      uVar4 = *hMem;
    }
  }
  if (lpSource != (HLOCAL)0x0) {
    LocalFree(lpSource);
  }
LAB_c05f29a4:
  if (local_28 != (wchar_t *)0x0) {
    LocalFree(local_28);
  }
  if (hMem != (undefined4 *)0x0) {
    LocalFree(hMem);
  }
  return uVar4;
}



/* c05f29f0 FUN_c05f29f0 */

/* Boundary evidence: original MIPS .pdata c05f29f0..c05f2a13. Semantic name remains unreviewed. */

void FUN_c05f29f0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 local_resc;
  
  local_resc = param_4;
  FUN_c05f2838(param_1,param_2,param_3,(va_list)&local_resc);
  return;
}



/* c05f2a14 FUN_c05f2a14 */

void FUN_c05f2a14(uint *param_1,uint param_2,uint *param_3)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  
  uVar2 = 0x80000000;
  uVar5 = *param_1;
  uVar4 = param_1[1];
  uVar1 = 0;
  uVar3 = 0x80000000;
  param_3[1] = 0;
  do {
    uVar1 = uVar1 * 2 + (uint)((uVar4 & uVar3) != 0);
    if (param_2 <= uVar1) {
      uVar1 = uVar1 - param_2;
      param_3[1] = param_3[1] | uVar3;
    }
    uVar3 = uVar3 >> 1;
  } while (uVar3 != 0);
  *param_3 = 0;
  do {
    uVar1 = uVar1 * 2 + (uint)((uVar5 & uVar2) != 0);
    if (param_2 <= uVar1) {
      uVar1 = uVar1 - param_2;
      *param_3 = *param_3 | uVar2;
    }
    uVar2 = uVar2 >> 1;
  } while (uVar2 != 0);
  return;
}



/* c05f2ab8 FUN_c05f2ab8 */

uint FUN_c05f2ab8(int param_1)

{
  uint uVar1;
  
  uVar1 = DAT_c05f9174;
  if (DAT_c05f917c == 0) {
    DAT_c05f917c = 1;
    uVar1 = DAT_c05f9174 ^ *(uint *)(param_1 + 2);
  }
  DAT_c05f9174 = uVar1 + 1;
  if (uVar1 == 0) {
    DAT_c05f9174 = 2;
    uVar1 = 1;
  }
  return uVar1;
}



/* c05f2b0c FUN_c05f2b0c */

/* Boundary evidence: original MIPS .pdata c05f2b0c..c05f2c47. Semantic name remains unreviewed. */

undefined4 * FUN_c05f2b0c(undefined4 param_1,wchar_t *param_2)

{
  size_t sVar1;
  undefined4 *hMem;
  HANDLE pvVar2;
  undefined4 *puVar3;
  
  sVar1 = wcslen(param_2);
  hMem = LocalAlloc(0x40,(sVar1 + 0xb5) * 2);
  if (hMem != (undefined4 *)0x0) {
    hMem[7] = 1;
    pvVar2 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,1,0,(LPCWSTR)0x0);
    hMem[0x58] = pvVar2;
    if (pvVar2 == (HANDLE)0x0) {
      LocalFree(hMem);
      hMem = (undefined4 *)0x0;
    }
    else {
      InitializeCriticalSection((LPCRITICAL_SECTION)(hMem + 0x2b));
      *(undefined2 *)(hMem + 6) = 0x40;
      hMem[0x1e] = 0xffffffff;
      hMem[0x57] = 300;
      hMem[0x55] = 0xffff;
      hMem[0x54] = 0xfea9;
      wcscpy((wchar_t *)(hMem + 0x5a),param_2);
      puVar3 = hMem + 9;
      hMem[3] = param_1;
      hMem[10] = puVar3;
      *puVar3 = puVar3;
      EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c05f9160);
      *hMem = &DAT_c05f9180;
      hMem[1] = DAT_c05f9184;
      *DAT_c05f9184 = hMem;
      DAT_c05f9184 = hMem;
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c05f9160);
      EnterCriticalSection((LPCRITICAL_SECTION)(hMem + 0x2b));
    }
  }
  return hMem;
}



/* c05f2c48 FUN_c05f2c48 */

/* Boundary evidence: original MIPS .pdata c05f2c48..c05f2ce7. Semantic name remains unreviewed. */

void FUN_c05f2c48(int *param_1)

{
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c05f9160);
  *(int *)param_1[1] = *param_1;
  *(int *)(*param_1 + 4) = param_1[1];
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c05f9160);
  DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x2b));
  if ((HLOCAL)param_1[0x44] != (HLOCAL)0x0) {
    LocalFree((HLOCAL)param_1[0x44]);
    param_1[0x44] = 0;
  }
  if ((HANDLE)param_1[0x58] != (HANDLE)0x0) {
    CloseHandle((HANDLE)param_1[0x58]);
    param_1[0x58] = 0;
  }
  LocalFree(param_1);
  return;
}



/* c05f2ce8 FUN_c05f2ce8 */

/* Boundary evidence: original MIPS .pdata c05f2ce8..c05f2d03. Semantic name remains unreviewed. */

void FUN_c05f2ce8(int param_1)

{
  InterlockedIncrement((LONG *)(param_1 + 0x1c));
  return;
}



/* c05f2d04 FUN_c05f2d04 */

/* Boundary evidence: original MIPS .pdata c05f2d04..c05f2de3. Semantic name remains unreviewed. */

undefined4 * FUN_c05f2d04(undefined4 *param_1,wchar_t *param_2)

{
  int iVar1;
  undefined4 *puVar2;
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c05f9160);
  puVar2 = DAT_c05f9180;
  do {
    if ((undefined4 **)puVar2 == &DAT_c05f9180) {
      puVar2 = (undefined4 *)0x0;
LAB_c05f2d98:
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c05f9160);
      if (puVar2 != (undefined4 *)0x0) {
        EnterCriticalSection((LPCRITICAL_SECTION)(puVar2 + 0x2b));
      }
      return puVar2;
    }
    if (((puVar2[8] & 0x8000) == 0) &&
       (((param_1 != (undefined4 *)0x0 && (puVar2 == param_1)) ||
        ((param_2 != (wchar_t *)0x0 &&
         (iVar1 = wcscmp((wchar_t *)(puVar2 + 0x5a),param_2), iVar1 == 0)))))) {
      InterlockedIncrement(puVar2 + 7);
      goto LAB_c05f2d98;
    }
    puVar2 = (undefined4 *)*puVar2;
  } while( true );
}



/* c05f2de4 FUN_c05f2de4 */

undefined4 FUN_c05f2de4(ushort *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  iVar2 = 0;
  if (*param_1 != 0) {
    do {
      if (3 < iVar2) break;
      uVar3 = (uint)*param_1;
      iVar1 = 0;
      if (uVar3 != 0) {
        do {
          if (uVar3 == 0x2e) break;
          if (uVar3 < 0x30) {
            return 0;
          }
          if (0x39 < uVar3) {
            return 0;
          }
          param_1 = param_1 + 1;
          iVar1 = iVar1 * 10 + uVar3;
          uVar3 = (uint)*param_1;
          iVar1 = iVar1 + -0x30;
        } while (uVar3 != 0);
        if (0xff < iVar1) {
          return 0;
        }
      }
      *(char *)(iVar2 + param_2) = (char)iVar1;
      if (*param_1 == 0x2e) {
        param_1 = param_1 + 1;
      }
      iVar2 = iVar2 + 1;
    } while (*param_1 != 0);
    if (iVar2 == 4) {
      return 1;
    }
  }
  return 0;
}



/* c05f2e9c FUN_c05f2e9c */

/* Boundary evidence: original MIPS .pdata c05f2e9c..c05f2fff. Semantic name remains unreviewed. */

short * FUN_c05f2e9c(uint param_1,short *param_2,uint param_3)

{
  uint uVar1;
  short *psVar2;
  short *psVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  uint local_res0 [4];
  short local_30 [18];
  uint local_c;
  
  local_c = DAT_c05f9108;
  if (param_3 < 0x10) {
    FUN_c05f7e0c(DAT_c05f9108);
    param_2 = (short *)0x0;
  }
  else {
    local_res0[0] =
         (param_1 & 0xff0000 | param_1 >> 0x10) >> 8 | (param_1 & 0xff00 | param_1 << 0x10) << 8;
    iVar6 = 0;
    iVar4 = 0;
    do {
      if (0xf < iVar4) break;
      uVar1 = (uint)*(byte *)((int)local_res0 + iVar6);
      psVar2 = local_30 + iVar4;
      do {
        iVar5 = iVar4;
        uVar7 = uVar1 % 10;
        iVar4 = iVar5 + 1;
        uVar1 = uVar1 / 10;
        *psVar2 = (short)uVar7 + 0x30;
        *(byte *)((int)local_res0 + iVar6) = (byte)uVar1;
        psVar2 = psVar2 + 1;
        if (uVar1 == 0) break;
      } while (iVar4 < 0x10);
      iVar6 = iVar6 + 1;
      local_30[iVar4] = 0x2e;
      iVar4 = iVar5 + 2;
    } while (iVar6 < 4);
    iVar4 = iVar4 + -1;
    psVar3 = local_30 + iVar4;
    *psVar3 = 0;
    iVar6 = 0;
    psVar2 = param_2;
    do {
      if (iVar4 == 0) break;
      psVar3 = psVar3 + -1;
      iVar6 = iVar6 + 1;
      *psVar2 = *psVar3;
      iVar4 = iVar4 + -1;
      psVar2 = psVar2 + 1;
    } while (iVar6 < 0x11);
    param_2[iVar6] = 0;
    FUN_c05f7e0c(local_c);
  }
  return param_2;
}



/* c05f3000 FUN_c05f3000 */

void FUN_c05f3000(int param_1,byte *param_2)

{
  byte bVar1;
  byte *pbVar2;
  byte *pbVar3;
  byte *pbVar4;
  
  pbVar3 = param_2 + param_1;
  while (pbVar2 = param_2, pbVar4 = param_2, param_2 < pbVar3) {
    for (; pbVar2 < pbVar3; pbVar2 = pbVar2 + 1) {
      if (*pbVar4 < *pbVar2) {
        pbVar4 = pbVar2;
      }
    }
    pbVar3 = pbVar3 + -1;
    if (pbVar4 < pbVar3) {
      bVar1 = *pbVar4;
      *pbVar4 = *pbVar3;
      *pbVar3 = bVar1;
    }
  }
  return;
}



/* c05f3078 FUN_c05f3078 */

undefined4 FUN_c05f3078(ushort *param_1,int param_2,undefined1 *param_3)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = 0;
  if (param_2 != 0) {
    do {
      uVar1 = (uint)*param_1;
      param_2 = param_2 + -1;
      if (uVar1 == 0) break;
      if (uVar1 < 0x30) {
        return 0;
      }
      if (0x39 < uVar1) {
        return 0;
      }
      param_1 = param_1 + 1;
      uVar2 = (uVar2 * 10 + uVar1) - 0x30;
    } while (param_2 != 0);
    if (0xff < uVar2) {
      return 0;
    }
  }
  *param_3 = (char)uVar2;
  return 1;
}



/* c05f30e8 FUN_c05f30e8 */

/* Boundary evidence: original MIPS .pdata c05f30e8..c05f32e7. Semantic name remains unreviewed. */

undefined4 FUN_c05f30e8(HKEY param_1,int param_2)

{
  LSTATUS LVar1;
  int iVar2;
  size_t _Size;
  DWORD dwIndex;
  uint uVar3;
  byte *pbVar4;
  DWORD local_e10;
  HKEY local_e0c;
  size_t local_e08 [2];
  WCHAR aWStack_e00 [4];
  undefined1 auStack_df8 [40];
  byte local_dd0;
  byte abStack_dcf [3499];
  uint local_24;
  
  local_24 = DAT_c05f9108;
  pbVar4 = abStack_dcf;
  *(ushort *)(param_2 + 0x18) = *(ushort *)(param_2 + 0x18) & 0xfff9;
  LVar1 = RegOpenKeyExW(param_1,L"DhcpOptions",0,0,&local_e0c);
  if (LVar1 == 0) {
    local_e10 = 8;
    LVar1 = RegQueryValueExW(local_e0c,(LPCWSTR)0x0,(LPDWORD)0x0,(LPDWORD)0x0,(LPBYTE)0x0,&local_e10
                            );
    if ((LVar1 == 0) && (local_e10 != 0)) {
      *(ushort *)(param_2 + 0x18) = *(ushort *)(param_2 + 0x18) | 2;
      dwIndex = 0;
      do {
        uVar3 = dwIndex + 1;
        local_e10 = 4;
        LVar1 = RegEnumValueW(local_e0c,dwIndex,aWStack_e00,&local_e10,(LPDWORD)0x0,(LPDWORD)0x0,
                              (LPBYTE)0x0,(LPDWORD)0x0);
        if (LVar1 != 0) break;
        iVar2 = FUN_c05f3078((ushort *)aWStack_e00,4,pbVar4);
        if (iVar2 != 0) {
          pbVar4 = pbVar4 + 1;
        }
        dwIndex = uVar3;
      } while (uVar3 < 0x1f);
      local_dd0 = (byte)(pbVar4 + (0xff - (int)&local_dd0));
      FUN_c05f3000((uint)(pbVar4 + (0xff - (int)&local_dd0)) & 0xff,abStack_dcf);
      _Size = local_dd0 + 1;
      if (0x20 < _Size) {
        _Size = 0x20;
      }
      memcpy((void *)(param_2 + 0xf0),&local_dd0,_Size);
    }
    RegCloseKey(local_e0c);
  }
  local_e08[0] = 0x21;
  iVar2 = GetRegBinaryValue(param_1,L"PrevReqOptions",auStack_df8,local_e08);
  if ((iVar2 != 0) &&
     (iVar2 = memcmp(auStack_df8,(void *)(param_2 + 0xf0),local_e08[0]), iVar2 != 0)) {
    *(ushort *)(param_2 + 0x18) = *(ushort *)(param_2 + 0x18) | 4;
  }
  FUN_c05f7e0c(local_24);
  return 0;
}



/* c05f32e8 FUN_c05f32e8 */

/* Boundary evidence: original MIPS .pdata c05f32e8..c05f34cf. Semantic name remains unreviewed. */

undefined4 FUN_c05f32e8(HKEY param_1,int param_2,int param_3)

{
  LSTATUS LVar1;
  byte *pbVar2;
  HLOCAL _Dst;
  size_t _Size;
  uint uVar3;
  undefined4 uVar4;
  DWORD dwIndex;
  DWORD local_df0;
  HKEY local_dec;
  DWORD local_de8;
  DWORD local_de4;
  WCHAR aWStack_de0 [4];
  byte local_dd8 [3500];
  uint local_2c;
  
  local_2c = DAT_c05f9108;
  uVar4 = 0;
  uVar3 = 0xd76;
  if (*(int *)(param_2 + 0x110) != 0) {
    uVar3 = 0xd76 - *(int *)(param_2 + 0x114);
  }
  LVar1 = RegOpenKeyExW(param_1,L"DhcpSendOptions",0,0,&local_dec);
  if (LVar1 != 0) goto LAB_c05f3498;
  _Size = 0;
  dwIndex = 0;
  if (uVar3 != 0) {
    do {
      local_de8 = 4;
      local_df0 = uVar3 - _Size;
      LVar1 = RegEnumValueW(local_dec,dwIndex,aWStack_de0,&local_de8,(LPDWORD)0x0,&local_de4,
                            local_dd8 + _Size,&local_df0);
      if ((LVar1 != 0) || (local_de4 != 3)) break;
      if ((param_3 != 1) ||
         (pbVar2 = FUN_c05f65ac(param_2,(uint)local_dd8[0]), pbVar2 == (byte *)0x0)) {
        _Size = local_df0 + _Size;
      }
      dwIndex = dwIndex + 1;
    } while (_Size < uVar3);
    if (_Size != 0) {
      if (*(int *)(param_2 + 0x110) == 0) {
        _Dst = LocalAlloc(0x40,0xd76);
        if (_Dst == (HLOCAL)0x0) goto LAB_c05f3488;
        memcpy(_Dst,local_dd8,_Size);
        *(HLOCAL *)(param_2 + 0x110) = _Dst;
        *(size_t *)(param_2 + 0x114) = _Size;
        *(ushort *)(param_2 + 0x18) = *(ushort *)(param_2 + 0x18) | 0x20;
      }
      else {
        memcpy((void *)(*(int *)(param_2 + 0x110) + *(int *)(param_2 + 0x114)),local_dd8,_Size);
        *(size_t *)(param_2 + 0x114) = _Size + *(int *)(param_2 + 0x114);
      }
      uVar4 = 1;
    }
  }
LAB_c05f3488:
  RegCloseKey(local_dec);
LAB_c05f3498:
  FUN_c05f7e0c(local_2c);
  return uVar4;
}



/* c05f34d0 FUN_c05f34d0 */

/* Boundary evidence: original MIPS .pdata c05f34d0..c05f358f. Semantic name remains unreviewed. */

undefined4 FUN_c05f34d0(undefined4 param_1,undefined4 param_2,undefined4 *param_3,int param_4)

{
  int iVar1;
  undefined4 uVar2;
  size_t sVar3;
  wchar_t *_Str;
  wchar_t local_118 [128];
  uint local_18;
  
  local_18 = DAT_c05f9108;
  _Str = local_118;
  local_118[0] = L'\0';
  iVar1 = GetRegMultiSZValue(param_1,param_2,local_118,0x100);
  if (iVar1 == 0) {
    FUN_c05f7e0c(local_18);
    uVar2 = 0;
  }
  else {
    for (; param_4 != 0; param_4 = param_4 + -1) {
      if (*_Str == L'\0') {
        *param_3 = 0;
      }
      else {
        FUN_c05f2de4((ushort *)_Str,(int)param_3);
        sVar3 = wcslen(_Str);
        _Str = _Str + sVar3 + 1;
      }
      param_3 = param_3 + 1;
    }
    FUN_c05f7e0c(local_18);
    uVar2 = 1;
  }
  return uVar2;
}



/* c05f3590 FUN_c05f3590 */

/* Boundary evidence: original MIPS .pdata c05f3590..c05f36bf. Semantic name remains unreviewed. */

undefined4 FUN_c05f3590(undefined4 param_1,undefined4 param_2,uint *param_3,uint param_4)

{
  short *psVar1;
  size_t sVar2;
  uint uVar3;
  undefined4 uVar4;
  uint uVar5;
  wchar_t local_130 [128];
  uint local_30;
  
  local_30 = DAT_c05f9108;
  uVar4 = 0;
  local_130[1] = 0;
  local_130[0] = L'\0';
  uVar3 = 0;
  uVar5 = 0;
  if (param_4 != 0) {
    do {
      if (*param_3 == 0) break;
      psVar1 = FUN_c05f2e9c(*param_3,local_130 + uVar3,0x80 - uVar3);
      if (psVar1 != (short *)0x0) {
        sVar2 = wcslen(local_130 + uVar3);
        uVar3 = sVar2 + uVar3 + 1;
        if (0x7f < uVar3) {
          local_130[0x7e] = 0;
          local_130[0x7f] = 0;
          break;
        }
        local_130[uVar3] = L'\0';
      }
      uVar5 = uVar5 + 1;
      param_3 = param_3 + 1;
    } while (uVar5 < param_4);
    if (uVar3 != 0) {
      uVar4 = SetRegMultiSZValue(param_1,param_2,local_130);
    }
  }
  FUN_c05f7e0c(local_30);
  return uVar4;
}



/* c05f36c0 FUN_c05f36c0 */

/* Boundary evidence: original MIPS .pdata c05f36c0..c05f3743. Semantic name remains unreviewed. */

bool FUN_c05f36c0(undefined4 param_1,undefined4 param_2,int param_3,ushort param_4,int param_5)

{
  ushort uVar1;
  uint local_18 [2];
  
  local_18[0] = (uint)(param_5 == 1);
  GetRegDWORDValue(param_1,param_2,local_18);
  if (local_18[0] == 0) {
    uVar1 = *(ushort *)(param_3 + 0x18) & ~param_4;
  }
  else {
    uVar1 = *(ushort *)(param_3 + 0x18) | param_4;
  }
  *(ushort *)(param_3 + 0x18) = uVar1;
  return local_18[0] != 0;
}



/* c05f3744 FUN_c05f3744 */

/* Boundary evidence: original MIPS .pdata c05f3744..c05f37e7. Semantic name remains unreviewed. */

undefined4 FUN_c05f3744(int param_1)

{
  HRESULT HVar1;
  LSTATUS LVar2;
  wchar_t *lpSubKey;
  HKEY local_118 [2];
  wchar_t awStack_110 [128];
  uint local_10;
  
  local_10 = DAT_c05f9108;
  if (param_1 == 0) {
    lpSubKey = L"Comm\\TcpIp\\Parms";
  }
  else {
    HVar1 = StringCchPrintfW(awStack_110,0x80,L"Comm\\%s\\Parms\\TcpIp",param_1 + 0x168);
    if (HVar1 != 0) goto LAB_c05f3784;
    lpSubKey = awStack_110;
  }
  LVar2 = RegOpenKeyExW((HKEY)0x80000002,lpSubKey,0,0,local_118);
  if (LVar2 == 0) {
    FUN_c05f7e0c(local_10);
    return local_118[0];
  }
LAB_c05f3784:
  FUN_c05f7e0c(local_10);
  return 0;
}



/* c05f37e8 FUN_c05f37e8 */

/* Boundary evidence: original MIPS .pdata c05f37e8..c05f3af3. Semantic name remains unreviewed. */

undefined4 FUN_c05f37e8(int param_1)

{
  HKEY pHVar1;
  int iVar2;
  wchar_t *pwVar3;
  undefined4 uVar4;
  size_t sVar5;
  size_t _MaxCount;
  wchar_t awStack_120 [128];
  uint local_20;
  
  local_20 = DAT_c05f9108;
  _MaxCount = 0;
  pHVar1 = (HKEY)FUN_c05f3744(param_1);
  if (pHVar1 != (HKEY)0x0) {
    iVar2 = FUN_c05f3590(pHVar1,L"DhcpIPAddress",(uint *)(param_1 + 0x5c),1);
    if (iVar2 != 0) {
      FUN_c05f3590(pHVar1,L"DhcpSubnetMask",(uint *)(param_1 + 0x60),1);
      FUN_c05f3590(pHVar1,L"DhcpServer",(uint *)(param_1 + 0x78),1);
      FUN_c05f3590(pHVar1,L"DhcpDefaultGateway",(uint *)(param_1 + 100),1);
      FUN_c05f3590(pHVar1,L"DhcpDNS",(uint *)(param_1 + 0x68),4);
      FUN_c05f3590(pHVar1,L"DhcpWINS",(uint *)(param_1 + 0x7c),4);
      SetRegDWORDValue(pHVar1,L"LeaseObtainedLow",*(undefined4 *)(param_1 + 0x8c));
      SetRegDWORDValue(pHVar1,L"LeaseObtainedHigh",*(undefined4 *)(param_1 + 0x90));
      SetRegDWORDValue(pHVar1,L"Lease",*(undefined4 *)(param_1 + 0x9c));
      SetRegDWORDValue(pHVar1,&DAT_c05f1390,*(undefined4 *)(param_1 + 0x94));
      SetRegDWORDValue(pHVar1,&DAT_c05f1388,*(undefined4 *)(param_1 + 0x98));
      SetRegBinaryValue(pHVar1,L"PrevReqOptions",(byte *)(param_1 + 0xf0),
                        *(byte *)(param_1 + 0xf0) + 1);
    }
    if ((*(ushort *)(param_1 + 0x18) & 0x40) == 0) {
      uVar4 = 0;
      pwVar3 = L"AutoCfg";
    }
    else {
      SetRegDWORDValue(pHVar1,L"AutoSeed",*(undefined4 *)(param_1 + 0x158));
      FUN_c05f3590(pHVar1,L"AutoIP",(uint *)(param_1 + 0x14c),1);
      FUN_c05f3590(pHVar1,L"AutoSubnet",(uint *)(param_1 + 0x150),1);
      FUN_c05f3590(pHVar1,L"AutoMask",(uint *)(param_1 + 0x154),1);
      uVar4 = *(undefined4 *)(param_1 + 0x15c);
      pwVar3 = L"AutoInterval";
    }
    SetRegDWORDValue(pHVar1,pwVar3,uVar4);
    sVar5 = (size_t)*(char *)(param_1 + 0x118);
    if (sVar5 == 0) {
      RegDeleteValueW(pHVar1,L"Domain");
    }
    else {
      _MaxCount = 0x7f;
      if ((int)sVar5 < 0x80) {
        _MaxCount = sVar5;
      }
      sVar5 = mbstowcs(awStack_120,(char *)(param_1 + 0x119),_MaxCount);
      if (sVar5 != 0xffffffff) {
        awStack_120[_MaxCount] = L'\0';
        SetRegSZValue(pHVar1,L"Domain",awStack_120);
      }
    }
    RegCloseKey(pHVar1);
    if ((_MaxCount != 0) && (pHVar1 = (HKEY)FUN_c05f3744(0), pHVar1 != (HKEY)0x0)) {
      sVar5 = mbstowcs(awStack_120,(char *)(param_1 + 0x119),_MaxCount);
      if (sVar5 != 0xffffffff) {
        awStack_120[_MaxCount] = L'\0';
        SetRegSZValue(pHVar1,L"DNSDomain",awStack_120);
      }
      RegCloseKey(pHVar1);
    }
  }
  FUN_c05f7e0c(local_20);
  return 0;
}



/* c05f3af4 FUN_c05f3af4 */

/* Boundary evidence: original MIPS .pdata c05f3af4..c05f3c13. Semantic name remains unreviewed. */

void FUN_c05f3af4(int param_1,int param_2)

{
  HKEY hKey;
  
  *(undefined4 *)(param_1 + 0x164) = 0x3b;
  EventModify(*(undefined4 *)(param_1 + 0x160),3);
  (**(code **)(*(int *)(param_1 + 0xc) + 0x28))(*(undefined2 *)(param_1 + 0x14),0,0,0,0);
  if ((*(uint *)(param_1 + 0x20) & 0x800) != 0) {
    *(uint *)(param_1 + 0x20) = *(uint *)(param_1 + 0x20) & 0xfffff7ff;
    (*DAT_c05f91a0)(param_1 + 0x168,*(undefined4 *)(param_1 + 0x10),*(undefined4 *)(param_1 + 0x14),
                    1,*(undefined4 *)(param_1 + 0x5c),*(undefined4 *)(param_1 + 0x60),0,0,0,0);
  }
  if (param_2 != 0) {
    *(undefined4 *)(param_1 + 0x60) = 0;
    *(undefined4 *)(param_1 + 0x5c) = 0;
    hKey = (HKEY)FUN_c05f3744(param_1);
    if (hKey != (HKEY)0x0) {
      RegDeleteValueW(hKey,L"DhcpIPAddress");
      RegDeleteValueW(hKey,L"DhcpSubnetMask");
      RegCloseKey(hKey);
    }
  }
  return;
}



/* c05f3c14 FUN_c05f3c14 */

/* Boundary evidence: original MIPS .pdata c05f3c14..c05f3cfb. Semantic name remains unreviewed. */

undefined4 FUN_c05f3c14(int param_1,uint param_2)

{
  int *hMem;
  undefined4 uVar1;
  int *piVar2;
  
  uVar1 = 0;
  piVar2 = *(int **)(param_1 + 0x24);
joined_r0xc05f3c38:
  do {
    hMem = piVar2;
    if (hMem == (int *)(param_1 + 0x24)) {
      return uVar1;
    }
    piVar2 = (int *)*hMem;
    if (param_2 == 2) goto LAB_c05f3cb8;
    if (param_2 < 4) {
      return 0;
    }
    if (5 < param_2) {
      if (param_2 != 6) {
        return 0;
      }
      break;
    }
  } while (((uint)hMem[2] < 4) || (5 < (uint)hMem[2]));
LAB_c05f3cd0:
  *(int **)hMem[1] = piVar2;
  *(int *)(*hMem + 4) = hMem[1];
  LocalFree(hMem);
  uVar1 = 1;
  goto joined_r0xc05f3c38;
LAB_c05f3cb8:
  if ((hMem[2] != 1) && (hMem[2] != 3)) goto joined_r0xc05f3c38;
  goto LAB_c05f3cd0;
}



/* c05f3cfc FUN_c05f3cfc */

/* Boundary evidence: original MIPS .pdata c05f3cfc..c05f3e43. Semantic name remains unreviewed. */

undefined4
FUN_c05f3cfc(int param_1,uint param_2,int param_3,int param_4,int param_5,void *param_6,
            size_t param_7)

{
  int *piVar1;
  undefined4 uVar2;
  
  piVar1 = LocalAlloc(0x40,0x30);
  if (piVar1 == (int *)0x0) {
    uVar2 = 0;
  }
  else {
    piVar1[3] = param_1;
    piVar1[2] = param_2;
    piVar1[4] = param_3;
    piVar1[5] = param_4;
    piVar1[6] = param_5;
    if (0x10 < param_7) {
      param_7 = 0x10;
    }
    piVar1[0xb] = param_7;
    memcpy(piVar1 + 7,param_6,param_7);
    FUN_c05f3c14(param_1,param_2);
    *piVar1 = param_1 + 0x24;
    piVar1[1] = *(int *)(param_1 + 0x28);
    **(undefined4 **)(param_1 + 0x28) = piVar1;
    *(int **)(param_1 + 0x28) = piVar1;
    if (param_2 == 4) {
      *(uint *)(param_1 + 0x20) = *(uint *)(param_1 + 0x20) & 0xfffffeff;
    }
    else if (param_2 == 5) {
      *(uint *)(param_1 + 0x20) = *(uint *)(param_1 + 0x20) | 0x100;
    }
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c05f9160);
    uVar2 = 1;
    if (DAT_c05f9124 == 0) {
      DAT_c05f9124 = 1;
      CTEScheduleEvent(&DAT_c05f9140,0);
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c05f9160);
  }
  return uVar2;
}



/* c05f3e44 FUN_c05f3e44 */

/* Boundary evidence: original MIPS .pdata c05f3e44..c05f3e7f. Semantic name remains unreviewed. */

void FUN_c05f3e44(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 8);
  if (iVar1 != 0) {
    *(undefined4 *)(param_1 + 8) = 0;
    (*(code *)*DAT_c05f9198)(iVar1);
  }
  return;
}



/* c05f3e80 FUN_c05f3e80 */

/* Boundary evidence: original MIPS .pdata c05f3e80..c05f4007. Semantic name remains unreviewed. */

void FUN_c05f3e80(int param_1,uint param_2,undefined4 param_3,undefined4 param_4)

{
  LONG LVar1;
  FILETIME local_30;
  uint local_28;
  int local_24;
  FILETIME local_20;
  
  local_30 = (FILETIME)((ulonglong)param_2 * 10000000 + *(longlong *)(param_1 + 0x8c));
  InterlockedIncrement((LONG *)(param_1 + 0x1c));
  GetCurrentFT(&local_20);
  LVar1 = CompareFileTime(&local_20,&local_30);
  if (LVar1 < 0) {
    local_28 = -local_20.dwLowDateTime + local_30.dwLowDateTime;
    local_24 = ((local_30.dwHighDateTime - local_20.dwHighDateTime) -
               (uint)(local_20.dwLowDateTime != 0)) + (uint)(local_28 < -local_20.dwLowDateTime);
    if ((local_24 == 0) && (local_28 < 600000000)) {
      *(uint *)(param_1 + 0x20) = *(uint *)(param_1 + 0x20) | 0x20;
      CTEStartFTimer(param_1 + 0xc0,local_30.dwLowDateTime,local_30.dwHighDateTime,param_4,param_1);
    }
    else {
      FUN_c05f2a14(&local_28,2,&local_28);
      *(uint *)(param_1 + 0x20) = *(uint *)(param_1 + 0x20) | 0x20;
      CTEStartFTimer(param_1 + 0xc0,local_28 + local_20.dwLowDateTime,
                     local_24 + local_20.dwHighDateTime +
                     (uint)(local_28 + local_20.dwLowDateTime < local_28),param_3,param_1);
    }
  }
  else {
    *(uint *)(param_1 + 0x20) = *(uint *)(param_1 + 0x20) | 0x20;
    CTEStartFTimer(param_1 + 0xc0,local_30.dwLowDateTime,local_30.dwHighDateTime,param_4,param_1);
  }
  return;
}



/* c05f4008 FUN_c05f4008 */

/* Boundary evidence: original MIPS .pdata c05f4008..c05f41d3. Semantic name remains unreviewed. */

DWORD FUN_c05f4008(int param_1,undefined4 param_2)

{
  int iVar1;
  DWORD DVar2;
  undefined4 local_38 [2];
  undefined2 local_30;
  undefined2 local_2e;
  undefined4 local_2c;
  uint local_20;
  
  local_20 = DAT_c05f9108;
  local_38[0] = 1;
  if (*(int *)(param_1 + 8) != 0) {
    *(undefined4 *)(param_1 + 8) = 0;
    (*(code *)*DAT_c05f9198)();
  }
  memset(&local_30,0,0x10);
  local_2e = 0x4400;
  local_30 = 2;
  local_2c = param_2;
  iVar1 = (**(code **)(DAT_c05f91a8 + 8))(0x80000002,2,0x11,0,0);
  if (iVar1 == 0) {
    DVar2 = GetLastError();
LAB_c05f4188:
    if (DVar2 == 0) goto LAB_c05f41a8;
  }
  else {
    DVar2 = (*(code *)DAT_c05f9198[0xd])(iVar1,0xffff,4,local_38,4);
    if (DVar2 == 0) {
      DVar2 = (*(code *)DAT_c05f9198[0xd])(iVar1,0xffff,0x20,local_38,4);
      if (DVar2 == 0) {
        local_38[0] = 0x4d2;
        DVar2 = (*(code *)DAT_c05f9198[0xd])(iVar1,0xffff,0x8000,local_38,4);
        if ((DVar2 == 0) && (DVar2 = (*(code *)DAT_c05f9198[3])(iVar1,&local_30,0x10), DVar2 == 0))
        {
          *(int *)(param_1 + 8) = iVar1;
          goto LAB_c05f4188;
        }
      }
    }
  }
  if (iVar1 != 0) {
    (*(code *)*DAT_c05f9198)(iVar1);
  }
LAB_c05f41a8:
  FUN_c05f7e0c(local_20);
  return DVar2;
}



/* c05f41d4 FUN_c05f41d4 */

/* Boundary evidence: original MIPS .pdata c05f41d4..c05f4243. Semantic name remains unreviewed. */

int FUN_c05f41d4(int param_1)

{
  int iVar1;
  
  iVar1 = 0;
  if ((*(uint *)(param_1 + 0x20) & 0x80) == 0) {
    *(uint *)(param_1 + 0x20) = *(uint *)(param_1 + 0x20) | 0x80;
    iVar1 = (**(code **)(*(int *)(param_1 + 0xc) + 0x24))(*(undefined4 *)(param_1 + 0x14),0,0,0);
    if (iVar1 == 0) {
      *(uint *)(param_1 + 0x20) = *(uint *)(param_1 + 0x20) & 0xffffff7f;
    }
  }
  return iVar1;
}



/* c05f4244 FUN_c05f4244 */

/* Boundary evidence: original MIPS .pdata c05f4244..c05f4297. Semantic name remains unreviewed. */

undefined4 FUN_c05f4244(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if ((*(uint *)(param_1 + 0x20) & 0x80) != 0) {
    *(uint *)(param_1 + 0x20) = *(uint *)(param_1 + 0x20) & 0xffffff7f;
    uVar1 = (**(code **)(*(int *)(param_1 + 0xc) + 0x24))(0x1ffff,0,0,0);
  }
  return uVar1;
}



/* c05f4298 FUN_c05f4298 */

/* Boundary evidence: original MIPS .pdata c05f4298..c05f435f. Semantic name remains unreviewed. */

undefined4 FUN_c05f4298(int param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  if ((param_2 != (undefined4 *)0x0) &&
     (*param_2 = *(undefined4 *)(param_1 + 0x5c), *(char *)(param_1 + 0x58) == '\0')) {
    uVar2 = 6;
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c05f9160);
    puVar1 = DAT_c05f9180;
    if ((undefined4 **)DAT_c05f9180 != &DAT_c05f9180) {
      do {
        if (((*(char *)(puVar1 + 0x16) == '\x01') && (puVar1[0x17] != 0)) && (puVar1[0x25] != 0)) {
          uVar2 = 0;
          *param_2 = puVar1[0x17];
          break;
        }
        puVar1 = (undefined4 *)*puVar1;
      } while ((undefined4 **)puVar1 != &DAT_c05f9180);
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c05f9160);
  }
  return uVar2;
}



/* c05f4360 FUN_c05f4360 */

/* Boundary evidence: original MIPS .pdata c05f4360..c05f454b. Semantic name remains unreviewed. */

undefined4 FUN_c05f4360(int param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  
  iVar3 = 0;
  iVar4 = 0;
  iVar2 = 4;
  piVar1 = (int *)(param_1 + 0x68);
  do {
    if (*piVar1 != 0) {
      iVar3 = iVar3 + 1;
    }
    if (piVar1[5] != 0) {
      iVar4 = iVar4 + 1;
    }
    iVar2 = iVar2 + -1;
    piVar1 = piVar1 + 1;
  } while (iVar2 != 0);
  *(uint *)(param_1 + 0x20) = *(uint *)(param_1 + 0x20) | 0x800;
  iVar2 = (*DAT_c05f91a0)(param_1 + 0x168,*(undefined4 *)(param_1 + 0x10),
                          *(undefined4 *)(param_1 + 0x14),0,*(undefined4 *)(param_1 + 0x5c),
                          *(undefined4 *)(param_1 + 0x60),iVar3,(int *)(param_1 + 0x68),iVar4,
                          param_1 + 0x7c);
  if (iVar2 == 0) {
    *(uint *)(param_1 + 0x20) = *(uint *)(param_1 + 0x20) & 0xfffff7ff;
    iVar2 = 0x2b2a;
  }
  else {
    *(undefined4 *)(param_1 + 0x164) = 0;
    EventModify(*(undefined4 *)(param_1 + 0x160),2);
    iVar2 = (**(code **)(*(int *)(param_1 + 0xc) + 0x28))
                      (*(undefined2 *)(param_1 + 0x14),0,*(undefined4 *)(param_1 + 0x5c),
                       *(undefined4 *)(param_1 + 0x60),*(undefined4 *)(param_1 + 100));
  }
  if (iVar2 == 0x2bf7) {
    LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xac));
    WaitForSingleObject(*(HANDLE *)(param_1 + 0x160),5000);
    EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0xac));
    if (*(int *)(param_1 + 0x164) == 0) {
      return 0;
    }
    uVar5 = 5;
  }
  else {
    if (iVar2 == 0) {
      return 0;
    }
    uVar5 = 5;
    if (iVar2 != 0x2b15) {
      uVar5 = 1;
    }
  }
  if ((*(uint *)(param_1 + 0x20) & 0x800) != 0) {
    *(uint *)(param_1 + 0x20) = *(uint *)(param_1 + 0x20) & 0xfffff7ff;
    (*DAT_c05f91a0)(param_1 + 0x168,*(undefined4 *)(param_1 + 0x10),*(undefined4 *)(param_1 + 0x14),
                    1,*(undefined4 *)(param_1 + 0x5c),*(undefined4 *)(param_1 + 0x60),0,0,0,0);
  }
  return uVar5;
}



/* c05f454c FUN_c05f454c */

/* Boundary evidence: original MIPS .pdata c05f454c..c05f45b7. Semantic name remains unreviewed. */

void FUN_c05f454c(int param_1,undefined1 *param_2)

{
  int local_18 [2];
  
  FUN_c05f6604(param_1,param_2,4,5,(byte *)0x0,local_18);
  FUN_c05f7488(param_1,param_2,local_18[0],0xffffffff);
  FUN_c05f3af4(param_1,1);
  return;
}



/* c05f45b8 FUN_c05f45b8 */

/* Boundary evidence: original MIPS .pdata c05f45b8..c05f462b. Semantic name remains unreviewed. */

bool FUN_c05f45b8(int param_1)

{
  LONG LVar1;
  FILETIME local_18;
  FILETIME FStack_10;
  
  local_18 = (FILETIME)
             ((ulonglong)*(uint *)(param_1 + 0x98) * 10000000 + *(longlong *)(param_1 + 0x8c));
  GetCurrentFT(&FStack_10);
  LVar1 = CompareFileTime(&local_18,&FStack_10);
  return -1 < LVar1;
}



/* c05f462c FUN_c05f462c */

/* Boundary evidence: original MIPS .pdata c05f462c..c05f4673. Semantic name remains unreviewed. */

void FUN_c05f462c(int param_1)

{
  if (*(int *)(param_1 + 0x5c) != 0) {
    *(undefined4 *)(param_1 + 0x5c) = 0;
    (**(code **)(*(int *)(param_1 + 0xc) + 0x28))(*(undefined2 *)(param_1 + 0x14),0,0,0,0);
  }
  return;
}



/* c05f4674 FUN_c05f4674 */

/* Boundary evidence: original MIPS .pdata c05f4674..c05f473f. Semantic name remains unreviewed. */

void FUN_c05f4674(int param_1,void *param_2,uint param_3)

{
  void *_Src;
  uint _Size;
  size_t _Size_00;
  
  if (param_2 != (void *)0x0) {
    _Src = param_2;
    _Size = param_3;
    if (param_3 == 0x10) {
      _Src = (void *)((int)param_2 + 6);
      _Size = 6;
    }
    if (_Src != (void *)0x0) {
      if (0x10 < _Size) {
        _Size = 0x10;
      }
      *(uint *)(param_1 + 0x3c) = _Size;
      memcpy((void *)(param_1 + 0x2c),_Src,_Size);
      *(undefined4 *)(param_1 + 0x40) = 1;
      _Size_00 = 0x10;
      if (param_3 < 0x11) {
        _Size_00 = param_3;
      }
      *(size_t *)(param_1 + 0x54) = _Size_00;
      memcpy((void *)(param_1 + 0x44),param_2,_Size_00);
      *(bool *)(param_1 + 0x58) = param_3 == 6;
    }
  }
  return;
}



/* c05f4740 FUN_c05f4740 */

/* Boundary evidence: original MIPS .pdata c05f4740..c05f4807. Semantic name remains unreviewed. */

void FUN_c05f4740(int param_1)

{
  int iVar1;
  DWORD DVar2;
  int iVar3;
  int local_eb0;
  undefined4 local_eac;
  undefined1 auStack_ea8 [3736];
  uint local_10;
  
  local_10 = DAT_c05f9108;
  iVar3 = *(int *)(param_1 + 0xc);
  iVar1 = FUN_c05f4298(iVar3,&local_eac);
  if ((iVar1 == 0) && (DVar2 = FUN_c05f4008(iVar3,local_eac), DVar2 == 0)) {
    FUN_c05f6604(iVar3,auStack_ea8,7,1,(byte *)0x0,&local_eb0);
    FUN_c05f7488(iVar3,auStack_ea8,local_eb0,*(undefined4 *)(iVar3 + 0x78));
    FUN_c05f3af4(iVar3,1);
    FUN_c05f4244(iVar3);
    if (*(int *)(iVar3 + 8) != 0) {
      *(undefined4 *)(iVar3 + 8) = 0;
      (*(code *)*DAT_c05f9198)();
    }
  }
  FUN_c05f7e0c(local_10);
  return;
}



/* c05f4808 FUN_c05f4808 */

/* Boundary evidence: original MIPS .pdata c05f4808..c05f48db. Semantic name remains unreviewed. */

void FUN_c05f4808(int param_1)

{
  HKEY hKey;
  uint uVar1;
  uint uVar2;
  int iVar3;
  
  iVar3 = *(int *)(param_1 + 0xc);
  uVar1 = *(uint *)(iVar3 + 0x20);
  uVar2 = uVar1 & 0xfffffeff;
  *(uint *)(iVar3 + 0x20) = uVar2;
  if ((uVar1 & 0x200) == 0) {
    *(uint *)(iVar3 + 0x20) = uVar2 | 0x200;
    FUN_c05f3af4(iVar3,0);
    FUN_c05f4244(iVar3);
    if (*(int *)(iVar3 + 8) != 0) {
      *(undefined4 *)(iVar3 + 8) = 0;
      (*(code *)*DAT_c05f9198)();
    }
    if (((*(uint *)(iVar3 + 0x20) & 0x2000) != 0) &&
       (hKey = (HKEY)FUN_c05f3744(iVar3), hKey != (HKEY)0x0)) {
      *(undefined4 *)(iVar3 + 100) = 0;
      RegDeleteValueW(hKey,L"DhcpDefaultGateway");
      RegCloseKey(hKey);
    }
  }
  return;
}



/* c05f48dc FUN_c05f48dc */

/* Boundary evidence: original MIPS .pdata c05f48dc..c05f497b. Semantic name remains unreviewed. */

undefined4 FUN_c05f48dc(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  if (param_1 == 9) {
    FUN_c05f29f0(0,0xb,9,param_4);
    DAT_c05f918c = 0;
  }
  else if (param_1 == 10) {
    FUN_c05f29f0(0,0xb,10,param_4);
    DAT_c05f9188 = 0;
  }
  else {
    if (param_1 != 0xb) {
      return 1;
    }
    FUN_c05f29f0(0,1,0xb,param_4);
    DAT_c05f9178 = 0;
  }
  return 0;
}



/* c05f497c FUN_c05f497c */

/* Boundary evidence: original MIPS .pdata c05f497c..c05f4ab3. Semantic name remains unreviewed. */

void FUN_c05f497c(LPVOID param_1)

{
  HANDLE hObject;
  
  if (param_1 == (LPVOID)0x9) {
    if (DAT_c05f918c != 0) {
      return;
    }
    DAT_c05f918c = 1;
  }
  else if (param_1 == (LPVOID)0xa) {
    if (DAT_c05f9188 != 0) {
      return;
    }
    DAT_c05f9188 = 1;
  }
  else {
    if (param_1 != (LPVOID)0xb) {
      return;
    }
    if (DAT_c05f9178 != 0) {
      return;
    }
    DAT_c05f9178 = 1;
  }
  hObject = CreateThread((LPSECURITY_ATTRIBUTES)0x0,0,FUN_c05f48dc,param_1,0,(LPDWORD)0x0);
  if (hObject == (HANDLE)0x0) {
    if (param_1 == (LPVOID)0x9) {
      DAT_c05f918c = 0;
    }
    else if (param_1 == (LPVOID)0xa) {
      DAT_c05f9188 = 0;
    }
    else if (param_1 == (LPVOID)0xb) {
      DAT_c05f9178 = 0;
    }
  }
  else {
    CloseHandle(hObject);
  }
  return;
}



/* c05f4ab4 FUN_c05f4ab4 */

/* Boundary evidence: original MIPS .pdata c05f4ab4..c05f4b1f. Semantic name remains unreviewed. */

LONG FUN_c05f4ab4(int *param_1)

{
  LONG LVar1;
  
  LVar1 = InterlockedDecrement(param_1 + 7);
  if (LVar1 == 0) {
    if (param_1[2] != 0) {
      param_1[2] = 0;
      (*(code *)*DAT_c05f9198)();
    }
    FUN_c05f2c48(param_1);
  }
  return LVar1;
}



/* c05f4b20 FUN_c05f4b20 */

/* Boundary evidence: original MIPS .pdata c05f4b20..c05f4b77. Semantic name remains unreviewed. */

void FUN_c05f4b20(int *param_1)

{
  CTEStopTimer(param_1 + 0x35);
  if ((param_1[8] & 0x20U) != 0) {
    param_1[8] = param_1[8] & 0xffffffdf;
    CTEStopFTimer(param_1 + 0x30);
    FUN_c05f4ab4(param_1);
  }
  return;
}



/* c05f4b78 FUN_c05f4b78 */

/* Boundary evidence: original MIPS .pdata c05f4b78..c05f4c03. Semantic name remains unreviewed. */

void FUN_c05f4b78(HKEY param_1,int param_2)

{
  HKEY hKey;
  
  if (*(HLOCAL *)(param_2 + 0x110) != (HLOCAL)0x0) {
    LocalFree(*(HLOCAL *)(param_2 + 0x110));
    *(undefined4 *)(param_2 + 0x110) = 0;
    *(undefined4 *)(param_2 + 0x114) = 0;
  }
  FUN_c05f32e8(param_1,param_2,0);
  hKey = (HKEY)FUN_c05f3744(0);
  if (hKey != (HKEY)0x0) {
    FUN_c05f32e8(hKey,param_2,1);
    RegCloseKey(hKey);
  }
  return;
}



/* c05f4c04 FUN_c05f4c04 */

/* Boundary evidence: original MIPS .pdata c05f4c04..c05f4fdf. Semantic name remains unreviewed. */

undefined4 FUN_c05f4c04(int param_1)

{
  undefined4 uVar1;
  bool bVar2;
  HKEY hKey;
  int iVar3;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  size_t _Size;
  int *piVar4;
  int local_30 [2];
  
  *(undefined4 *)(param_1 + 0xa4) = 2;
  uVar1 = DAT_c05f91a4;
  *(undefined4 *)(param_1 + 0xa0) = 2;
  *(undefined4 *)(param_1 + 0xa8) = uVar1;
  _Size = DAT_c05f90fc + 1;
  if (9 < _Size) {
    _Size = 9;
  }
  if (0x20 < _Size) {
    _Size = 0x20;
  }
  memcpy((void *)(param_1 + 0xf0),&DAT_c05f90fc,_Size);
  hKey = (HKEY)FUN_c05f3744(param_1);
  if (hKey != (HKEY)0x0) {
    iVar3 = GetRegDWORDValue(hKey,L"EnableDHCP",local_30);
    if ((iVar3 != 0) && (local_30[0] != 0)) {
      *(ushort *)(param_1 + 0x18) = *(ushort *)(param_1 + 0x18) | 1;
    }
    piVar4 = (int *)(param_1 + 0x5c);
    iVar3 = FUN_c05f34d0(hKey,L"DhcpIPAddress",piVar4,1);
    if ((iVar3 != 0) && (*piVar4 != 0)) {
      iVar3 = FUN_c05f34d0(hKey,L"DhcpSubnetMask",(int *)(param_1 + 0x60),1);
      if ((iVar3 != 0) && (*(int *)(param_1 + 0x60) != 0)) {
        FUN_c05f34d0(hKey,L"DhcpServer",(undefined4 *)(param_1 + 0x78),1);
        FUN_c05f34d0(hKey,L"DhcpDefaultGateway",(undefined4 *)(param_1 + 100),1);
        FUN_c05f34d0(hKey,L"DhcpDNS",(undefined4 *)(param_1 + 0x68),4);
        FUN_c05f34d0(hKey,L"DhcpWINS",(undefined4 *)(param_1 + 0x7c),4);
        GetRegDWORDValue(hKey,L"LeaseObtainedLow",param_1 + 0x8c);
        GetRegDWORDValue(hKey,L"LeaseObtainedHigh",param_1 + 0x90);
        GetRegDWORDValue(hKey,L"Lease",param_1 + 0x9c);
        GetRegDWORDValue(hKey,&DAT_c05f1390,param_1 + 0x94);
        GetRegDWORDValue(hKey,&DAT_c05f1388,param_1 + 0x98);
      }
    }
    GetRegDWORDValue(hKey,L"DhcpMaxRetry",(undefined4 *)(param_1 + 0xa4));
    GetRegDWORDValue(hKey,L"DhcpInitDelayInterval",(undefined4 *)(param_1 + 0xa8));
    GetRegDWORDValue(hKey,L"DhcpRetryDialogue",(undefined4 *)(param_1 + 0xa0));
    FUN_c05f36c0(hKey,L"DhcpNoMacCompare",param_1,0x10,0);
    FUN_c05f36c0(hKey,L"DhcpConstantRate",param_1,0x100,0);
    FUN_c05f36c0(hKey,L"DhcpDirectRenewal",param_1,0x200,0);
    FUN_c05f30e8(hKey,param_1);
    FUN_c05f4b78(hKey,param_1);
    bVar2 = FUN_c05f36c0(hKey,L"AutoCfg",param_1,0x40,1);
    if (CONCAT31(extraout_var,bVar2) != 0) {
      GetRegDWORDValue(hKey,L"AutoSeed",param_1 + 0x158);
      FUN_c05f34d0(hKey,L"AutoIP",(int *)(param_1 + 0x14c),1);
      FUN_c05f34d0(hKey,L"AutoSubnet",(undefined4 *)(param_1 + 0x150),1);
      FUN_c05f34d0(hKey,L"AutoMask",(undefined4 *)(param_1 + 0x154),1);
      GetRegDWORDValue(hKey,L"AutoInterval",param_1 + 0x15c);
      if (*(int *)(param_1 + 0x14c) == *piVar4) {
        *(uint *)(param_1 + 0x20) = *(uint *)(param_1 + 0x20) | 0x10;
      }
      bVar2 = FUN_c05f36c0(hKey,L"DhcpEnableImmediateAutoIP",param_1,0x80,0);
      if (CONCAT31(extraout_var_00,bVar2) != 0) {
        *(uint *)(param_1 + 0x20) = *(uint *)(param_1 + 0x20) | 0x1000;
      }
      RegDeleteValueW(hKey,L"DhcpEnableImmediateAutoIP");
    }
    RegCloseKey(hKey);
  }
  return 0;
}



/* c05f4fe0 FUN_c05f4fe0 */

/* Boundary evidence: original MIPS .pdata c05f4fe0..c05f505b. Semantic name remains unreviewed. */

undefined4 FUN_c05f4fe0(wchar_t *param_1,uint param_2)

{
  int *piVar1;
  undefined4 uVar2;
  
  piVar1 = FUN_c05f2d04((undefined4 *)0x0,param_1);
  if (piVar1 == (int *)0x0) {
    uVar2 = 6;
  }
  else {
    FUN_c05f3cfc((int)piVar1,param_2,0,0,0,(void *)0x0,0);
    LeaveCriticalSection((LPCRITICAL_SECTION)(piVar1 + 0x2b));
    FUN_c05f4ab4(piVar1);
    uVar2 = 0;
  }
  return uVar2;
}



/* c05f505c FUN_c05f505c */

/* Boundary evidence: original MIPS .pdata c05f505c..c05f510f. Semantic name remains unreviewed. */

void FUN_c05f505c(int *param_1)

{
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x2b));
  param_1[8] = param_1[8] & 0xffffffdfU | 4;
  FUN_c05f3af4((int)param_1,1);
  FUN_c05f4244((int)param_1);
  if (param_1[2] != 0) {
    param_1[2] = 0;
    (*(code *)*DAT_c05f9198)();
  }
  FUN_c05f3cfc((int)param_1,1,0,0,0,(void *)0x0,0);
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x2b));
  FUN_c05f4ab4(param_1);
  return;
}



/* c05f5110 FUN_c05f5110 */

/* Boundary evidence: original MIPS .pdata c05f5110..c05f53a7. Semantic name remains unreviewed. */

void FUN_c05f5110(int *param_1)

{
  bool bVar1;
  int iVar2;
  DWORD DVar3;
  int iVar4;
  code *pcVar5;
  uint uVar6;
  uint uVar7;
  int local_ed0;
  undefined4 local_ecc;
  int local_ec8;
  int local_ec4;
  undefined1 auStack_ec0 [3736];
  uint local_28;
  
  local_28 = DAT_c05f9108;
  bVar1 = false;
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x2b));
  uVar6 = param_1[8];
  uVar7 = uVar6 & 0xffffffdf;
  param_1[8] = uVar7;
  if ((uVar6 & 1) == 0) {
    param_1[8] = uVar7 | 1;
  }
  else {
    param_1[8] = uVar7 | 2;
  }
  iVar2 = FUN_c05f4298((int)param_1,&local_ecc);
  if ((iVar2 == 0) && (DVar3 = FUN_c05f4008((int)param_1,local_ecc), DVar3 == 0)) {
    FUN_c05f6604((int)param_1,auStack_ec0,3,9,(byte *)(param_1 + 0x3c),&local_ed0);
    iVar2 = FUN_c05f41d4((int)param_1);
    GetCurrentFT(&local_ec8);
    if (iVar2 == 0) {
      iVar4 = 4;
    }
    else {
      iVar4 = FUN_c05f7648(param_1,(int)auStack_ec0,local_ed0,5,1);
      if (iVar4 == 8) goto LAB_c05f536c;
    }
    if (iVar4 == 0) {
      param_1[8] = param_1[8] & 0xfffffffc;
      param_1[0x23] = local_ec8;
      param_1[0x24] = local_ec4;
      FUN_c05f37e8((int)param_1);
      FUN_c05f57a8((int)param_1);
    }
    else {
      if (iVar4 == 3) {
        FUN_c05f3af4((int)param_1,1);
        FUN_c05f4244((int)param_1);
        param_1[8] = param_1[8] & 0xfffffffc;
        if (param_1[2] != 0) {
          param_1[2] = 0;
          (*(code *)*DAT_c05f9198)();
        }
        FUN_c05f497c((LPVOID)0xa);
        FUN_c05f3cfc((int)param_1,1,0,0,0,(void *)0x0,0);
        goto LAB_c05f536c;
      }
      bVar1 = true;
    }
    if (iVar2 != 0) {
      FUN_c05f4244((int)param_1);
    }
    if (param_1[2] != 0) {
      param_1[2] = 0;
      (*(code *)*DAT_c05f9198)();
    }
  }
  else {
    bVar1 = true;
  }
  if (bVar1) {
    if ((param_1[8] & 2U) == 0) {
      pcVar5 = FUN_c05f5110;
      uVar6 = param_1[0x26];
    }
    else {
      uVar6 = param_1[0x27];
      pcVar5 = FUN_c05f505c;
    }
    FUN_c05f3e80((int)param_1,uVar6,FUN_c05f5110,pcVar5);
  }
LAB_c05f536c:
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x2b));
  FUN_c05f4ab4(param_1);
  FUN_c05f7e0c(local_28);
  return;
}



/* c05f53a8 FUN_c05f53a8 */

/* Boundary evidence: original MIPS .pdata c05f53a8..c05f543b. Semantic name remains unreviewed. */

undefined4 FUN_c05f53a8(wchar_t *param_1)

{
  int *piVar1;
  undefined4 uVar2;
  
  piVar1 = FUN_c05f2d04((undefined4 *)0x0,param_1);
  if (piVar1 == (int *)0x0) {
    uVar2 = 6;
  }
  else {
    if ((piVar1[8] & 0x8000U) == 0) {
      piVar1[8] = piVar1[8] | 0x8000;
    }
    FUN_c05f3af4((int)piVar1,1);
    FUN_c05f3cfc((int)piVar1,6,0,0,0,(void *)0x0,0);
    LeaveCriticalSection((LPCRITICAL_SECTION)(piVar1 + 0x2b));
    FUN_c05f4ab4(piVar1);
    uVar2 = 0;
  }
  return uVar2;
}



/* c05f543c FUN_c05f543c */

/* Boundary evidence: original MIPS .pdata c05f543c..c05f54e3. Semantic name remains unreviewed. */

undefined4
FUN_c05f543c(int param_1,wchar_t *param_2,int param_3,int param_4,void *param_5,size_t param_6)

{
  int *piVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  piVar1 = FUN_c05f2d04((undefined4 *)0x0,param_2);
  if (piVar1 == (int *)0x0) {
    uVar2 = 6;
  }
  else {
    FUN_c05f3cfc((int)piVar1,3,param_1,param_3,param_4,param_5,param_6);
    LeaveCriticalSection((LPCRITICAL_SECTION)(piVar1 + 0x2b));
    FUN_c05f4ab4(piVar1);
  }
  return uVar2;
}



/* c05f54e4 FUN_c05f54e4 */

/* Boundary evidence: original MIPS .pdata c05f54e4..c05f5597. Semantic name remains unreviewed. */

undefined4
FUN_c05f54e4(undefined4 param_1,wchar_t *param_2,int param_3,int param_4,void *param_5,uint param_6)

{
  int *piVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  piVar1 = FUN_c05f2b0c(param_1,param_2);
  if (piVar1 == (int *)0x0) {
    uVar2 = 2;
  }
  else {
    InterlockedIncrement(piVar1 + 7);
    piVar1[8] = piVar1[8] | 0x2400;
    piVar1[4] = param_3;
    piVar1[5] = param_4;
    FUN_c05f4674((int)piVar1,param_5,param_6);
    if ((char)piVar1[0x16] == '\0') {
      *(ushort *)(piVar1 + 6) = *(ushort *)(piVar1 + 6) | 1;
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)(piVar1 + 0x2b));
    FUN_c05f4ab4(piVar1);
  }
  return uVar2;
}



/* c05f5598 FUN_c05f5598 */

/* Boundary evidence: original MIPS .pdata c05f5598..c05f565f. Semantic name remains unreviewed. */

undefined4
FUN_c05f5598(undefined4 param_1,wchar_t *param_2,int param_3,int param_4,void *param_5,uint param_6)

{
  int *piVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  piVar1 = FUN_c05f2b0c(param_1,param_2);
  if (piVar1 == (int *)0x0) {
    uVar2 = 2;
  }
  else {
    InterlockedIncrement(piVar1 + 7);
    piVar1[4] = param_3;
    piVar1[5] = param_4;
    FUN_c05f4674((int)piVar1,param_5,param_6);
    if ((char)piVar1[0x16] == '\0') {
      *(ushort *)(piVar1 + 6) = *(ushort *)(piVar1 + 6) | 1;
    }
    FUN_c05f3cfc((int)piVar1,1,0,0,0,(void *)0x0,0);
    LeaveCriticalSection((LPCRITICAL_SECTION)(piVar1 + 0x2b));
    FUN_c05f4ab4(piVar1);
  }
  return uVar2;
}



/* c05f5660 FUN_c05f5660 */

/* Boundary evidence: original MIPS .pdata c05f5660..c05f567f. Semantic name remains unreviewed. */

void FUN_c05f5660(undefined4 param_1,wchar_t *param_2)

{
  FUN_c05f4fe0(param_2,4);
  return;
}



/* c05f5680 FUN_c05f5680 */

/* Boundary evidence: original MIPS .pdata c05f5680..c05f569f. Semantic name remains unreviewed. */

void FUN_c05f5680(undefined4 param_1,wchar_t *param_2)

{
  FUN_c05f4fe0(param_2,5);
  return;
}



/* c05f56a0 FUN_c05f56a0 */

/* Boundary evidence: original MIPS .pdata c05f56a0..c05f57a7. Semantic name remains unreviewed. */

undefined4
FUN_c05f56a0(int param_1,int param_2,wchar_t *param_3,int param_4,int param_5,void *param_6,
            uint param_7)

{
  undefined4 uVar1;
  
  if (param_1 == 2) {
    uVar1 = FUN_c05f53a8(param_3);
  }
  else if (param_1 == 0x1001) {
    uVar1 = FUN_c05f5598(param_2,param_3,param_4,param_5,param_6,param_7);
  }
  else if (param_1 == 0x1002) {
    uVar1 = FUN_c05f4fe0(param_3,2);
  }
  else if (param_1 == 0x1003) {
    uVar1 = FUN_c05f543c(param_2,param_3,param_4,param_5,param_6,param_7);
  }
  else if (param_1 == 0x1004) {
    uVar1 = FUN_c05f54e4(param_2,param_3,param_4,param_5,param_6,param_7);
  }
  else {
    uVar1 = 1;
  }
  return uVar1;
}



/* c05f57a8 FUN_c05f57a8 */

/* Boundary evidence: original MIPS .pdata c05f57a8..c05f5837. Semantic name remains unreviewed. */

void FUN_c05f57a8(int param_1)

{
  longlong lVar1;
  
  lVar1 = (ulonglong)*(uint *)(param_1 + 0x94) * 10000000 + *(longlong *)(param_1 + 0x8c);
  InterlockedIncrement((LONG *)(param_1 + 0x1c));
  *(uint *)(param_1 + 0x20) = *(uint *)(param_1 + 0x20) | 0x20;
  CTEStartFTimer(param_1 + 0xc0,(int)lVar1,(int)((ulonglong)lVar1 >> 0x20),FUN_c05f5110,param_1);
  return;
}



/* c05f5838 FUN_c05f5838 */

/* Boundary evidence: original MIPS .pdata c05f5838..c05f5c8b. Semantic name remains unreviewed. */

int FUN_c05f5838(int *param_1)

{
  bool bVar1;
  bool bVar2;
  bool bVar3;
  DWORD DVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  int local_ed8 [2];
  int local_ed0;
  int local_ecc;
  undefined1 auStack_ec8 [3736];
  uint local_30;
  
  local_30 = DAT_c05f9108;
  iVar6 = 0;
  bVar3 = false;
  uVar7 = 0;
  param_1[8] = param_1[8] & 0xfffffff0;
  FUN_c05f4c04((int)param_1);
  if ((*(ushort *)(param_1 + 6) & 1) != 0) {
    if ((param_1[8] & 0x10U) != 0) {
      FUN_c05f4b20(param_1);
      param_1[8] = param_1[8] & 0xffffffef;
      FUN_c05f462c((int)param_1);
    }
    bVar1 = (*(ushort *)(param_1 + 6) & 0xc0) == 0xc0;
    if ((param_1[0x17] == 0) || ((*(ushort *)(param_1 + 6) & 4) != 0)) {
      bVar2 = true;
      FUN_c05f462c((int)param_1);
      *(ushort *)(param_1 + 6) = *(ushort *)(param_1 + 6) & 0xfffb;
    }
    else {
      bVar2 = false;
    }
    while (uVar7 <= (uint)param_1[0x29]) {
      if (!bVar1) {
        if (param_1[0x2a] != 0) {
          DVar4 = GetTickCount();
          if (param_1[0x2a] == 0) {
            trap(0x1c00);
          }
          Sleep(DVar4 % (uint)param_1[0x2a]);
        }
        iVar6 = FUN_c05f41d4((int)param_1);
        if (iVar6 == 0) {
          iVar6 = 4;
          if ((param_1[0x29] != -1) || ((param_1[8] & 0x8000U) == 0)) goto LAB_c05f5c10;
        }
        else {
          GetCurrentFT(&local_ed0);
          if ((param_1[0x17] == 0) || ((*(ushort *)(param_1 + 6) & 4) != 0)) {
            bVar2 = true;
            FUN_c05f6604((int)param_1,auStack_ec8,1,1,(byte *)(param_1 + 0x3c),local_ed8);
            iVar6 = FUN_c05f7648(param_1,(int)auStack_ec8,local_ed8[0],2,0x104);
            if (iVar6 == 0) {
              uVar5 = 6;
              goto LAB_c05f5a30;
            }
          }
          else {
            uVar5 = 5;
LAB_c05f5a30:
            bVar2 = false;
            FUN_c05f6604((int)param_1,auStack_ec8,3,uVar5,(byte *)(param_1 + 0x3c),local_ed8);
            iVar6 = FUN_c05f7648(param_1,(int)auStack_ec8,local_ed8[0],5,0x104);
          }
          if (iVar6 != 8) {
            FUN_c05f4244((int)param_1);
            if ((((uVar7 == param_1[0x29]) && ((*(ushort *)(param_1 + 6) & 0x40) != 0)) && (bVar2))
               && ((param_1[8] & 8U) == 0)) goto LAB_c05f5abc;
            goto LAB_c05f5ac8;
          }
        }
        break;
      }
      bVar1 = false;
LAB_c05f5abc:
      iVar6 = FUN_c05f1ca4((int)param_1);
LAB_c05f5ac8:
      if (iVar6 == 0) {
        param_1[0x23] = local_ed0;
        param_1[0x24] = local_ecc;
        FUN_c05f37e8((int)param_1);
        bVar3 = true;
        if (((param_1[8] & 0x10U) == 0) && ((param_1[8] & 8U) != 0)) {
          iVar6 = FUN_c05f4360((int)param_1);
          if (iVar6 == 0) {
            FUN_c05f57a8((int)param_1);
          }
          else {
            if (iVar6 == 5) {
              FUN_c05f41d4((int)param_1);
              FUN_c05f454c((int)param_1,auStack_ec8);
              FUN_c05f4244((int)param_1);
            }
LAB_c05f5b38:
            bVar3 = false;
LAB_c05f5c18:
            if (iVar6 != 4) goto LAB_c05f5c20;
          }
        }
      }
      else if (iVar6 == 3) {
        param_1[0x18] = 0;
        FUN_c05f462c((int)param_1);
        bVar2 = true;
LAB_c05f5c10:
        if (!bVar3) goto LAB_c05f5c18;
      }
      else {
        if (bVar2) {
          FUN_c05f462c((int)param_1);
          if (iVar6 == 7) {
            bVar3 = true;
          }
          goto LAB_c05f5c10;
        }
        iVar6 = FUN_c05f182c((int)param_1);
        if (iVar6 == 0) {
          FUN_c05f57a8((int)param_1);
          bVar3 = true;
          goto LAB_c05f5c44;
        }
        if (iVar6 != 5) {
          FUN_c05f462c((int)param_1);
          goto LAB_c05f5b38;
        }
        FUN_c05f41d4((int)param_1);
        FUN_c05f454c((int)param_1,auStack_ec8);
        FUN_c05f4244((int)param_1);
        bVar3 = false;
LAB_c05f5c20:
        if ((uVar7 == param_1[0x28]) && ((param_1[8] & 0x100U) == 0)) {
          FUN_c05f497c((LPVOID)0x9);
        }
      }
LAB_c05f5c44:
      uVar7 = uVar7 + 1;
      if (bVar3) break;
    }
  }
  FUN_c05f7e0c(local_30);
  return iVar6;
}



/* c05f5c8c FUN_c05f5c8c */

/* Boundary evidence: original MIPS .pdata c05f5c8c..c05f5d93. Semantic name remains unreviewed. */

void FUN_c05f5c8c(int param_1)

{
  DWORD DVar1;
  int iVar2;
  int *piVar3;
  int local_18 [2];
  
  piVar3 = *(int **)(param_1 + 0xc);
  if (piVar3[2] == 0) {
    DVar1 = FUN_c05f4008((int)piVar3,0);
  }
  else {
    DVar1 = 0;
  }
  if (DVar1 == 0) {
    if (piVar3[4] == 0) {
      local_18[0] = piVar3[0x15];
      (**(code **)(piVar3[3] + 0x24))(piVar3[5],piVar3 + 4,piVar3 + 0x11,local_18);
    }
    iVar2 = FUN_c05f5838(piVar3);
    if (iVar2 != 8) {
      if (piVar3[2] != 0) {
        piVar3[2] = 0;
        (*(code *)*DAT_c05f9198)();
      }
      if (((piVar3[8] & 0x8000U) == 0) && (iVar2 != 0)) {
        FUN_c05f4b20(piVar3);
      }
    }
  }
  else {
    FUN_c05f4b20(piVar3);
    if ((piVar3[8] & 0x100U) == 0) {
      FUN_c05f497c((LPVOID)0x9);
    }
  }
  return;
}



/* c05f5d94 FUN_c05f5d94 */

/* Boundary evidence: original MIPS .pdata c05f5d94..c05f602b. Semantic name remains unreviewed. */

void FUN_c05f5d94(int param_1)

{
  bool bVar1;
  int iVar2;
  DWORD DVar3;
  uint uVar4;
  int iVar5;
  int *piVar6;
  int local_ec0;
  int local_ebc;
  int local_eb8 [2];
  undefined1 auStack_eb0 [3736];
  uint local_18;
  
  local_18 = DAT_c05f9108;
  piVar6 = *(int **)(param_1 + 0xc);
  uVar4 = piVar6[8];
  if ((uVar4 & 0x600) == 0) {
    bVar1 = (uVar4 & 0x200) != 0;
    if (bVar1) {
      piVar6[8] = uVar4 & 0xfffffdff;
    }
    if ((piVar6[8] & 4U) != 0) goto LAB_c05f600c;
    if ((piVar6[8] & 0x10U) == 0) {
      if ((!bVar1) && (DAT_c05f919c != 0)) {
        Sleep(200);
        iVar5 = 0;
        do {
          iVar2 = FUN_c05f16b0(piVar6[0x19]);
          if (iVar2 != 0) goto LAB_c05f600c;
          Sleep(1000);
          iVar5 = iVar5 + 1;
        } while (iVar5 < 3);
      }
      if (piVar6[2] == 0) {
        DVar3 = FUN_c05f4008((int)piVar6,0);
      }
      else {
        DVar3 = 0;
      }
      if (DVar3 == 0) {
        FUN_c05f6604((int)piVar6,auStack_eb0,3,1,(byte *)(piVar6 + 0x3c),local_eb8);
        iVar5 = FUN_c05f41d4((int)piVar6);
        GetCurrentFT(&local_ec0);
        if (iVar5 == 0) {
          iVar5 = 4;
        }
        else {
          iVar5 = FUN_c05f7648(piVar6,(int)auStack_eb0,local_eb8[0],5,0x103);
        }
        if (iVar5 != 8) {
          FUN_c05f4244((int)piVar6);
          if (iVar5 == 0) {
            if (((piVar6[8] & 0x800U) == 0) && (iVar5 = FUN_c05f4360((int)piVar6), iVar5 != 0)) {
              FUN_c05f41d4((int)piVar6);
              FUN_c05f454c((int)piVar6,auStack_eb0);
              FUN_c05f4244((int)piVar6);
            }
            else {
              FUN_c05f4b20(piVar6);
              piVar6[0x23] = local_ec0;
              piVar6[0x24] = local_ebc;
              FUN_c05f37e8((int)piVar6);
              FUN_c05f57a8((int)piVar6);
            }
          }
          else if (iVar5 == 3) {
            FUN_c05f4b20(piVar6);
            FUN_c05f3af4((int)piVar6,1);
            FUN_c05f4244((int)piVar6);
            FUN_c05f3cfc((int)piVar6,1,0,0,0,(void *)0x0,0);
          }
        }
      }
      if (piVar6[2] != 0) {
        piVar6[2] = 0;
        (*(code *)*DAT_c05f9198)();
      }
      goto LAB_c05f600c;
    }
  }
  else {
    piVar6[8] = uVar4 & 0xfffff9ff;
  }
  FUN_c05f5c8c(param_1);
LAB_c05f600c:
  FUN_c05f7e0c(local_18);
  return;
}



/* c05f602c FUN_c05f602c */

/* Boundary evidence: original MIPS .pdata c05f602c..c05f6267. Semantic name remains unreviewed. */

void FUN_c05f602c(int param_1)

{
  bool bVar1;
  int iVar2;
  DWORD DVar3;
  uint uVar4;
  int *piVar5;
  int local_ec8;
  int local_ec4;
  int local_ec0;
  int local_ebc;
  undefined1 auStack_eb8 [3736];
  uint local_20;
  
  local_20 = DAT_c05f9108;
  piVar5 = *(int **)(param_1 + 0xc);
  uVar4 = piVar5[8];
  bVar1 = false;
  if (((uVar4 & 0x600) != 0) || ((uVar4 & 4) != 0)) goto LAB_c05f6240;
  if ((uVar4 & 0x10) == 0) {
    if (piVar5[2] == 0) {
      iVar2 = FUN_c05f4298((int)piVar5,&local_ec4);
      if (iVar2 != 0) goto LAB_c05f6240;
      iVar2 = local_ec4;
      if (local_ec4 == piVar5[0x53]) {
        iVar2 = 0;
      }
      DVar3 = FUN_c05f4008((int)piVar5,iVar2);
      if (DVar3 != 0) goto LAB_c05f6240;
      bVar1 = true;
      if (iVar2 == 0) goto LAB_c05f6084;
    }
    FUN_c05f6604((int)piVar5,auStack_eb8,3,9,(byte *)(piVar5 + 0x3c),&local_ec8);
    GetCurrentFT(&local_ec0);
    iVar2 = FUN_c05f7648(piVar5,(int)auStack_eb8,local_ec8,5,3);
    if (iVar2 == 0) {
      FUN_c05f4b20(piVar5);
      piVar5[0x23] = local_ec0;
      piVar5[0x24] = local_ebc;
      FUN_c05f37e8((int)piVar5);
      FUN_c05f57a8((int)piVar5);
    }
    else if (iVar2 == 1) {
      FUN_c05f3af4((int)piVar5,0);
      FUN_c05f3cfc((int)piVar5,1,0,0,0,(void *)0x0,0);
    }
    else if (iVar2 == 3) {
      FUN_c05f4b20(piVar5);
      FUN_c05f3af4((int)piVar5,1);
      FUN_c05f4244((int)piVar5);
      if (piVar5[2] != 0) {
        piVar5[2] = 0;
        (*(code *)*DAT_c05f9198)();
      }
      FUN_c05f497c((LPVOID)0xa);
      FUN_c05f3cfc((int)piVar5,1,0,0,0,(void *)0x0,0);
    }
    if ((bVar1) && (piVar5[2] != 0)) {
      piVar5[2] = 0;
      (*(code *)*DAT_c05f9198)();
    }
  }
  else {
LAB_c05f6084:
    FUN_c05f3af4((int)piVar5,1);
    FUN_c05f5c8c(param_1);
  }
LAB_c05f6240:
  FUN_c05f7e0c(local_20);
  return;
}



/* c05f6268 FUN_c05f6268 */

/* Boundary evidence: original MIPS .pdata c05f6268..c05f643b. Semantic name remains unreviewed. */

void FUN_c05f6268(void)

{
  int *hMem;
  int iVar1;
  int *piVar2;
  int *piVar3;
  int *piVar4;
  
  do {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c05f9160);
    for (piVar3 = DAT_c05f9180; (int **)piVar3 != &DAT_c05f9180; piVar3 = (int *)*piVar3) {
      if ((int *)piVar3[9] != piVar3 + 9) {
        InterlockedIncrement(piVar3 + 7);
        goto LAB_c05f62e0;
      }
    }
    DAT_c05f9124 = 0;
    piVar3 = (int *)0x0;
LAB_c05f62e0:
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c05f9160);
    if (piVar3 == (int *)0x0) {
      return;
    }
    EnterCriticalSection((LPCRITICAL_SECTION)(piVar3 + 0x2b));
    piVar4 = piVar3 + 9;
    while (hMem = (int *)*piVar4, hMem != piVar4) {
      *(int **)(*hMem + 4) = piVar4;
      *piVar4 = *hMem;
      iVar1 = hMem[2];
      if (iVar1 == 1) {
        FUN_c05f5c8c((int)hMem);
      }
      else if (iVar1 == 2) {
        FUN_c05f4740((int)hMem);
      }
      else if (iVar1 == 3) {
        FUN_c05f602c((int)hMem);
      }
      else if (iVar1 == 4) {
        FUN_c05f5d94((int)hMem);
      }
      else if (iVar1 == 5) {
        FUN_c05f4808((int)hMem);
      }
      else if (iVar1 == 6) {
        piVar2 = (int *)hMem[3];
        FUN_c05f4244((int)piVar2);
        FUN_c05f4b20(piVar2);
        FUN_c05f4ab4(piVar2);
      }
      LocalFree(hMem);
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)(piVar3 + 0x2b));
    FUN_c05f4ab4(piVar3);
  } while( true );
}



/* c05f643c FUN_c05f643c */

/* Boundary evidence: original MIPS .pdata c05f643c..c05f65ab. Semantic name remains unreviewed. */

undefined4 FUN_c05f643c(LPSTR param_1)

{
  LSTATUS LVar1;
  int iVar2;
  undefined4 uVar3;
  HKEY local_70;
  DWORD local_6c;
  wchar_t awStack_68 [20];
  wchar_t awStack_40 [18];
  uint local_1c;
  
  local_1c = DAT_c05f9108;
  uVar3 = 0;
  LVar1 = RegOpenKeyExW((HKEY)0x80000002,L"Ident",0,0,&local_70);
  if (LVar1 == 0) {
    memset(awStack_40,0,0x22);
    local_6c = 0x22;
    RegQueryValueExW(local_70,L"OrigName",(LPDWORD)0x0,(LPDWORD)0x0,(LPBYTE)awStack_40,&local_6c);
    memset(awStack_68,0,0x22);
    local_6c = 0x22;
    LVar1 = RegQueryValueExW(local_70,L"Name",(LPDWORD)0x0,(LPDWORD)0x0,(LPBYTE)awStack_68,&local_6c
                            );
    if ((LVar1 == 0) && (iVar2 = _wcsicmp(awStack_68,awStack_40), iVar2 != 0)) {
      WideCharToMultiByte(0,0,awStack_68,0x10,param_1,0x10,(LPCSTR)0x0,(LPBOOL)0x0);
      uVar3 = 1;
    }
    RegCloseKey(local_70);
  }
  FUN_c05f7e0c(local_1c);
  return uVar3;
}



/* c05f65ac FUN_c05f65ac */

byte * FUN_c05f65ac(int param_1,uint param_2)

{
  byte *pbVar1;
  byte *pbVar2;
  
  pbVar1 = *(byte **)(param_1 + 0x110);
  if (pbVar1 != (byte *)0x0) {
    pbVar2 = pbVar1 + *(int *)(param_1 + 0x114);
    for (; pbVar1 < pbVar2; pbVar1 = pbVar1 + 1 + pbVar1[1] + 1) {
      if (param_2 == *pbVar1) {
        return pbVar1;
      }
    }
  }
  return (byte *)0x0;
}



/* c05f6604 FUN_c05f6604 */

/* Boundary evidence: original MIPS .pdata c05f6604..c05f6a97. Semantic name remains unreviewed. */

void FUN_c05f6604(int param_1,undefined1 *param_2,int param_3,uint param_4,byte *param_5,
                 int *param_6)

{
  uint uVar1;
  byte *pbVar2;
  int iVar3;
  size_t _Size;
  undefined1 *puVar4;
  undefined4 *puVar5;
  undefined1 *puVar6;
  undefined1 *puVar7;
  char local_40 [20];
  uint local_2c;
  
  local_2c = DAT_c05f9108;
  puVar7 = param_2 + 0xe98;
  if ((param_4 & 1) != 0) {
    memset(param_2,0,0xe98);
    *param_2 = 1;
    param_2[1] = (char)*(undefined4 *)(param_1 + 0x40);
    param_2[2] = (char)*(undefined4 *)(param_1 + 0x3c);
    param_2[3] = 0;
    uVar1 = FUN_c05f2ab8(param_1 + 0x2c);
    *(uint *)(param_2 + 4) =
         (uVar1 & 0xff0000 | uVar1 >> 0x10) >> 8 | (uVar1 << 0x10 | uVar1 & 0xff00) << 8;
    *(undefined4 *)(param_2 + 0x18) = 0;
    *(undefined4 *)(param_2 + 0x14) = 0;
    *(undefined4 *)(param_2 + 0x10) = 0;
    *(undefined4 *)(param_2 + 0xc) = 0;
    *(undefined2 *)(param_2 + 10) = 0;
    *(undefined2 *)(param_2 + 8) = 0;
    if ((*(char *)(param_1 + 0x58) == '\0') && ((param_4 & 8) == 0)) {
      *(undefined2 *)(param_2 + 10) = 0x80;
    }
    _Size = *(uint *)(param_1 + 0x3c);
    if (0x10 < _Size) {
      _Size = 0x10;
    }
    memcpy(param_2 + 0x1c,(void *)(param_1 + 0x2c),_Size);
    *(undefined4 *)(param_2 + 0xec) = 0x63538263;
  }
  if ((param_4 & 4) == 0) {
    *(undefined4 *)(param_2 + 0xc) = *(undefined4 *)(param_1 + 0x5c);
  }
  param_2[0xf0] = 0x35;
  param_2[0xf1] = 1;
  param_2[0xf2] = (char)param_3;
  puVar6 = param_2 + 0xf3;
  if (param_3 == 1) {
LAB_c05f68a8:
    if ((*(int *)(param_1 + 0x5c) != 0) && ((param_4 & 4) != 0)) {
      *puVar6 = 0x32;
      puVar5 = (undefined4 *)(puVar6 + 2);
      puVar6[1] = 4;
      puVar6 = puVar6 + 6;
      *puVar5 = *(undefined4 *)(param_1 + 0x5c);
    }
  }
  else {
    if (param_3 == 3) {
      if ((param_4 & 2) != 0) {
        *puVar6 = 0x36;
        param_2[0xf4] = 4;
        puVar6 = param_2 + 0xf9;
        *(undefined4 *)(param_2 + 0xf5) = *(undefined4 *)(param_1 + 0x78);
      }
      goto LAB_c05f68a8;
    }
    if (param_3 == 4) {
      *puVar6 = 0x32;
      param_2[0xf4] = 4;
      puVar6 = param_2 + 0xf9;
      *(undefined4 *)(param_2 + 0xf5) = *(undefined4 *)(param_1 + 0x5c);
LAB_c05f67c8:
      pbVar2 = FUN_c05f65ac(param_1,0x3d);
      if (pbVar2 == (byte *)0x0) {
        *puVar6 = 0x3d;
        puVar6[1] = (char)*(undefined4 *)(param_1 + 0x54) + '\x01';
        puVar6[2] = *(undefined1 *)(param_1 + 0x58);
        memcpy(puVar6 + 3,(void *)(param_1 + 0x44),*(size_t *)(param_1 + 0x54));
        puVar4 = puVar6 + 3 + *(int *)(param_1 + 0x54);
      }
      else {
        memcpy(puVar6,pbVar2,pbVar2[1] + 2);
        puVar4 = puVar6 + pbVar2[1] + 2;
      }
      *puVar4 = 0x36;
      puVar4[1] = 4;
      *(undefined4 *)(puVar4 + 2) = *(undefined4 *)(param_1 + 0x78);
      puVar6 = puVar4 + 7;
      puVar4[6] = 0xff;
      goto LAB_c05f6a34;
    }
    if (param_3 == 7) goto LAB_c05f67c8;
    if (param_3 != 8) goto LAB_c05f6a34;
  }
  pbVar2 = FUN_c05f65ac(param_1,0x3d);
  if (pbVar2 == (byte *)0x0) {
    *puVar6 = 0x3d;
    puVar6[1] = (char)*(undefined4 *)(param_1 + 0x54) + '\x01';
    puVar6[2] = *(undefined1 *)(param_1 + 0x58);
    memcpy(puVar6 + 3,(void *)(param_1 + 0x44),*(size_t *)(param_1 + 0x54));
    puVar6 = puVar6 + 3 + *(int *)(param_1 + 0x54);
  }
  pbVar2 = FUN_c05f65ac(param_1,0xc);
  if ((pbVar2 == (byte *)0x0) && (iVar3 = FUN_c05f643c(local_40), iVar3 != 0)) {
    local_40[0x10] = 0;
    *puVar6 = 0xc;
    puVar6 = puVar6 + 1;
    for (iVar3 = 0; (local_40[0] != '\0' && (iVar3 < 0x11)); iVar3 = iVar3 + 1) {
      puVar6[iVar3 + 1] = local_40[iVar3];
      local_40[0] = local_40[iVar3 + 1];
    }
    *puVar6 = (char)iVar3;
    puVar6 = puVar6 + iVar3 + 1;
  }
  if (((param_5 != (byte *)0x0) && (*param_5 != 0)) &&
     ((int)(uint)*param_5 <= (int)puVar7 - (int)puVar6)) {
    *puVar6 = 0x37;
    memcpy(puVar6 + 1,param_5,*param_5 + 1);
    puVar6 = puVar6 + 1 + *param_5 + 1;
  }
  if (*(void **)(param_1 + 0x110) != (void *)0x0) {
    memcpy(puVar6,*(void **)(param_1 + 0x110),*(size_t *)(param_1 + 0x114));
    puVar6 = puVar6 + *(int *)(param_1 + 0x114);
  }
  *puVar6 = 0xff;
  puVar6 = puVar6 + 1;
LAB_c05f6a34:
  if (puVar6 < puVar7) {
    memset(puVar6,0,(int)puVar7 - (int)puVar6);
  }
  if (param_6 != (int *)0x0) {
    *param_6 = (int)puVar6 - (int)param_2;
  }
  FUN_c05f7e0c(local_2c);
  return;
}



/* c05f6a98 FUN_c05f6a98 */

void FUN_c05f6a98(uint param_1,short *param_2)

{
  if (99 < param_1) {
    param_2 = param_2 + 1;
  }
  if (9 < param_1) {
    param_2 = param_2 + 1;
  }
  param_2[1] = 0;
  do {
    *param_2 = (short)((int)param_1 % 10) + 0x30;
    param_1 = (int)param_1 / 10 & 0xff;
    param_2 = param_2 + -1;
  } while (param_1 != 0);
  return;
}



/* c05f6afc FUN_c05f6afc */

/* Boundary evidence: original MIPS .pdata c05f6afc..c05f7487. Semantic name remains unreviewed. */

int FUN_c05f6afc(int param_1,char *param_2,uint param_3,byte *param_4,int param_5)

{
  byte bVar1;
  int iVar2;
  LSTATUS LVar3;
  undefined4 uVar4;
  uint *_Dst;
  void *_Dst_00;
  undefined4 uVar5;
  byte *_Src;
  uint uVar6;
  undefined4 uVar7;
  size_t _Size;
  undefined4 uVar8;
  uint uVar9;
  byte bVar10;
  uint uVar11;
  uint uVar12;
  int iVar13;
  byte *pbVar14;
  byte *pbVar15;
  uint uVar16;
  uint uVar17;
  int iVar18;
  int iVar19;
  undefined4 uVar20;
  undefined4 uVar21;
  int iVar22;
  byte local_198;
  int local_194;
  HKEY local_190;
  uint local_18c;
  uint local_188;
  DWORD local_184;
  uint local_180;
  int local_17c;
  byte *local_178;
  int local_174;
  int local_170;
  int local_16c;
  uint local_168;
  int local_164;
  uint local_160;
  uint local_158;
  undefined4 local_154;
  undefined4 local_150;
  undefined4 local_14c;
  uint local_148;
  undefined4 local_144;
  undefined4 local_140;
  undefined4 local_13c;
  uint local_138;
  uint local_134;
  wchar_t awStack_130 [128];
  uint local_30;
  
  local_30 = DAT_c05f9108;
  iVar13 = 1;
  local_194 = 1;
  bVar10 = 0;
  local_180 = 0x63538263;
  local_198 = 0;
  iVar22 = 0;
  local_16c = 0;
  iVar19 = 0;
  local_190 = (HKEY)0x0;
  local_164 = 0;
  local_170 = 0;
  local_174 = 0;
  local_17c = 0;
  local_184 = 0;
  local_178 = param_4;
  local_160 = param_3;
  if ((((0xef < param_3) && (*param_2 == '\x02')) &&
      (*(uint *)(param_1 + 0x40) == (uint)(byte)param_2[1])) &&
     (((bVar10 = local_198, param_5 == *(int *)(param_2 + 4) &&
       (iVar2 = memcmp(&local_180,param_2 + 0xec,4), iVar2 == 0)) &&
      (((*(ushort *)(param_1 + 0x18) & 0x10) != 0 ||
       (((uint)(byte)param_2[2] == *(uint *)(param_1 + 0x3c) &&
        (iVar2 = memcmp((void *)(param_1 + 0x2c),param_2 + 0x1c,(uint)(byte)param_2[2]), iVar2 == 0)
        ))))))) {
    iVar2 = 0;
    iVar18 = 0;
    uVar16 = 0;
    do {
      pbVar15 = (byte *)(param_2 + 0xec);
      iVar13 = local_194;
      if (iVar2 == 0) {
        pbVar14 = (byte *)(param_2 + 0xf0);
        pbVar15 = (byte *)(param_2 + local_160);
      }
      else if (iVar2 == 1) {
        pbVar14 = (byte *)(param_2 + 0x6c);
      }
      else {
        bVar10 = local_198;
        if (iVar2 != 2) goto LAB_c05f6e34;
        pbVar14 = (byte *)(param_2 + 0x2c);
        pbVar15 = (byte *)(param_2 + 0x6c);
      }
      iVar18 = iVar2 + iVar18;
      uVar9 = local_138;
joined_r0xc05f6c94:
      while( true ) {
        bVar10 = local_198;
        if (pbVar15 <= pbVar14) {
          iVar13 = 1;
          goto LAB_c05f6e34;
        }
        bVar1 = *pbVar14;
        uVar6 = 4;
        local_138 = uVar9;
        if (0x34 < bVar1) break;
        if (bVar1 == 0x34) {
          if ((pbVar14 + 2 < pbVar15) && (pbVar14[1] == 1)) {
            if ((uVar16 == 0) && (uVar9 = (uint)pbVar14[2], uVar9 < 4)) {
              uVar16 = uVar9;
            }
            goto LAB_c05f6f10;
          }
          goto LAB_c05f6e34;
        }
        if (bVar1 != 0) {
          if (bVar1 == 1) {
            _Dst = &local_138;
            iVar19 = iVar19 + 1;
          }
          else if (bVar1 == 3) {
            local_184 = local_184 + 1;
            _Dst = &local_180;
          }
          else if (bVar1 == 6) {
            memset(&local_148,0,0x10);
            uVar6 = (uint)pbVar14[1];
            if (0x10 < uVar6) {
              uVar6 = 0x10;
            }
            local_164 = local_164 + 1;
            _Dst = &local_148;
          }
          else if (bVar1 == 0x2c) {
            memset(&local_158,0,0x10);
            uVar6 = (uint)pbVar14[1];
            if (0x10 < uVar6) {
              uVar6 = 0x10;
            }
            local_190 = (HKEY)((int)&local_190->unused + 1);
            _Dst = &local_158;
          }
          else {
            if (bVar1 != 0x33) goto LAB_c05f6f10;
            local_17c = local_17c + 1;
            _Dst = &local_18c;
          }
          goto LAB_c05f6eb0;
        }
        pbVar14 = pbVar14 + 1;
      }
      if (bVar1 == 0x35) {
        local_198 = pbVar14[2];
        if ((*local_178 != 0) && (local_198 != *local_178)) {
          local_194 = 0;
          goto LAB_c05f73f0;
        }
        goto LAB_c05f6f10;
      }
      if (bVar1 == 0x36) {
        _Dst = &local_188;
        iVar22 = iVar22 + 1;
LAB_c05f6eb0:
        if (pbVar15 < pbVar14 + uVar6) goto LAB_c05f6e34;
        memcpy(_Dst,pbVar14 + 2,uVar6);
LAB_c05f6f10:
        pbVar14 = pbVar14 + pbVar14[1] + 2;
        uVar9 = local_138;
        goto joined_r0xc05f6c94;
      }
      if (bVar1 == 0x3a) {
        local_174 = local_174 + 1;
        _Dst = &local_134;
        goto LAB_c05f6eb0;
      }
      if (bVar1 == 0x3b) {
        local_170 = local_170 + 1;
        _Dst = &local_168;
        goto LAB_c05f6eb0;
      }
      if (bVar1 == 0xfb) {
        if (pbVar14[1] != 1) goto LAB_c05f6e34;
        goto LAB_c05f6f10;
      }
      if (bVar1 != 0xff) goto LAB_c05f6f10;
      if ((uVar16 & 1) == 0) {
        if (uVar16 != 0) {
          iVar2 = iVar2 + 2;
        }
      }
      else {
        iVar2 = iVar2 + 1;
      }
    } while (iVar18 < (int)uVar16);
    if ((((iVar19 == 0) || (uVar9 != 0)) &&
        ((((local_17c != 0 && (local_18c != 0)) || (local_198 != 5)) &&
         ((iVar22 == 0 || (local_188 != 0)))))) &&
       (((*local_178 != 5 || (*(int *)(param_1 + 0x5c) == 0)) ||
        ((*(int *)(param_1 + 0x5c) == *(int *)(param_2 + 0x10) &&
         ((*(uint *)(param_1 + 0x60) == 0 || (*(uint *)(param_1 + 0x60) == uVar9)))))))) {
      if (local_198 == 5) {
        wcscpy(awStack_130,L"Comm\\");
        wcscat(awStack_130,(wchar_t *)(param_1 + 0x168));
        wcscat(awStack_130,L"\\Parms\\TcpIp\\DhcpOptions");
        LVar3 = RegOpenKeyExW((HKEY)0x80000002,awStack_130,0,0,&local_190);
        if (LVar3 == 0) {
          local_16c = 1;
        }
      }
      iVar19 = 0;
      iVar22 = 0;
      uVar17 = 0;
      uVar16 = local_148;
      uVar4 = local_144;
      uVar6 = local_158;
      uVar5 = local_154;
      uVar7 = local_150;
      uVar8 = local_14c;
      uVar11 = local_180;
      uVar12 = local_168;
      uVar20 = local_13c;
      uVar21 = local_140;
LAB_c05f7080:
      if (iVar19 == 0) {
        pbVar15 = (byte *)(param_2 + 0xf0);
        pbVar14 = (byte *)(param_2 + local_160);
      }
      else if (iVar19 == 1) {
        pbVar14 = (byte *)(param_2 + 0xec);
        pbVar15 = (byte *)(param_2 + 0x6c);
      }
      else {
        if (iVar19 != 2) goto LAB_c05f73d8;
        pbVar15 = (byte *)(param_2 + 0x2c);
        pbVar14 = (byte *)(param_2 + 0x6c);
      }
      iVar22 = iVar19 + iVar22;
joined_r0xc05f70c8:
      do {
        if (pbVar14 <= pbVar15) goto LAB_c05f7238;
        bVar10 = *pbVar15;
        if (bVar10 < 0x34) {
          if (bVar10 == 0x33) {
            *(uint *)(param_1 + 0x9c) =
                 (local_18c & 0xff0000 | local_18c >> 0x10) >> 8 |
                 (local_18c << 0x10 | local_18c & 0xff00) << 8;
          }
          else {
            if (bVar10 == 0) {
              pbVar15 = pbVar15 + 1;
              goto joined_r0xc05f70c8;
            }
            if (bVar10 == 1) {
              *(uint *)(param_1 + 0x60) = uVar9;
            }
            else if (bVar10 == 3) {
              *(uint *)(param_1 + 100) = uVar11;
            }
            else if (bVar10 == 6) {
              *(uint *)(param_1 + 0x68) = uVar16;
              *(undefined4 *)(param_1 + 0x6c) = uVar4;
              *(undefined4 *)(param_1 + 0x70) = uVar21;
              *(undefined4 *)(param_1 + 0x74) = uVar20;
            }
            else if (bVar10 == 0xf) {
              _Src = pbVar15 + 1;
              if (*_Src < 0x34) {
                _Size = *_Src + 1;
                _Dst_00 = (void *)(param_1 + 0x118);
              }
              else {
                *(undefined1 *)(param_1 + 0x118) = 0x33;
                _Dst_00 = (void *)(param_1 + 0x119);
                _Src = pbVar15 + 2;
                _Size = 0x33;
              }
              memcpy(_Dst_00,_Src,_Size);
            }
            else if (bVar10 == 0x2c) {
              *(uint *)(param_1 + 0x7c) = uVar6;
              *(undefined4 *)(param_1 + 0x80) = uVar5;
              *(undefined4 *)(param_1 + 0x84) = uVar7;
              *(undefined4 *)(param_1 + 0x88) = uVar8;
            }
          }
        }
        else if (bVar10 == 0x34) {
          if ((uVar17 == 0) && (pbVar15[2] < 4)) {
            uVar17 = (uint)pbVar15[2];
          }
        }
        else if (bVar10 == 0x36) {
          *(uint *)(param_1 + 0x78) = local_188;
        }
        else if (bVar10 == 0x3a) {
          *(uint *)(param_1 + 0x94) =
               (local_134 & 0xff0000 | local_134 >> 0x10) >> 8 |
               (local_134 << 0x10 | local_134 & 0xff00) << 8;
        }
        else if (bVar10 == 0x3b) {
          *(uint *)(param_1 + 0x98) =
               (uVar12 & 0xff0000 | uVar12 >> 0x10) >> 8 | (uVar12 << 0x10 | uVar12 & 0xff00) << 8;
        }
        else if (bVar10 == 0xfb) {
          if (pbVar15[2] == 0) {
            *(ushort *)(param_1 + 0x18) = *(ushort *)(param_1 + 0x18) & 0xffbf;
          }
          else {
            *(ushort *)(param_1 + 0x18) = *(ushort *)(param_1 + 0x18) | 0x40;
          }
        }
        else if (bVar10 == 0xff) {
          local_194 = 0;
          goto LAB_c05f7238;
        }
        if (local_16c != 0) {
          FUN_c05f6a98((uint)*pbVar15,awStack_130);
          local_184 = 0;
          LVar3 = RegQueryValueExW(local_190,awStack_130,(LPDWORD)0x0,(LPDWORD)0x0,(LPBYTE)0x0,
                                   &local_184);
          if ((LVar3 == 0) && (local_184 != 0)) {
            SetRegBinaryValue(local_190,awStack_130,pbVar15,pbVar15[1] + 2);
          }
        }
        pbVar15 = pbVar15 + pbVar15[1] + 2;
        uVar16 = local_148;
        uVar4 = local_144;
        uVar6 = local_158;
        uVar5 = local_154;
        uVar7 = local_150;
        uVar8 = local_14c;
        uVar11 = local_180;
        uVar12 = local_168;
        uVar20 = local_13c;
        uVar21 = local_140;
      } while( true );
    }
  }
LAB_c05f6e34:
  if (local_178 != (byte *)0x0) {
    *local_178 = bVar10;
  }
  FUN_c05f7e0c(local_30);
  return iVar13;
LAB_c05f7238:
  if ((uVar17 & 1) == 0) {
    if (uVar17 != 0) {
      iVar19 = iVar19 + 2;
    }
  }
  else {
    iVar19 = iVar19 + 1;
  }
  if ((int)uVar17 <= iVar22) goto LAB_c05f73d8;
  goto LAB_c05f7080;
LAB_c05f73d8:
  if (local_194 == 0) {
LAB_c05f73f0:
    if (((local_198 == 2) || (local_198 == 5)) && (local_17c != 0)) {
      if (local_174 == 0) {
        *(int *)(param_1 + 0x94) = *(int *)(param_1 + 0x9c) >> 1;
      }
      if (local_170 == 0) {
        *(int *)(param_1 + 0x98) = *(int *)(param_1 + 0x9c) * 7 >> 3;
      }
      *(undefined4 *)(param_1 + 0x5c) = *(undefined4 *)(param_2 + 0x10);
    }
  }
  iVar13 = local_194;
  bVar10 = local_198;
  if (local_16c != 0) {
    RegCloseKey(local_190);
  }
  goto LAB_c05f6e34;
}



/* c05f7488 FUN_c05f7488 */

/* Boundary evidence: original MIPS .pdata c05f7488..c05f75bb. Semantic name remains unreviewed. */

undefined4 FUN_c05f7488(int param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  LPCRITICAL_SECTION lpCriticalSection;
  undefined4 uVar1;
  int iVar2;
  int local_40;
  undefined4 local_3c;
  undefined1 auStack_38 [8];
  undefined2 local_30;
  undefined2 local_2e;
  undefined4 local_2c;
  uint local_20;
  
  local_20 = DAT_c05f9108;
  if (param_3 < 300) {
    param_3 = 300;
  }
  memset(&local_30,0,0x10);
  lpCriticalSection = (LPCRITICAL_SECTION)(param_1 + 0xac);
  local_30 = 2;
  local_2e = 0x4300;
  local_40 = param_3;
  local_3c = param_2;
  local_2c = param_4;
  EnterCriticalSection(lpCriticalSection);
  if ((*(uint *)(param_1 + 0x20) & 0x8100) == 0) {
    iVar2 = *(int *)(param_1 + 8);
    if (iVar2 == 0) {
      LeaveCriticalSection(lpCriticalSection);
      uVar1 = 6;
    }
    else {
      LeaveCriticalSection(lpCriticalSection);
      uVar1 = (**(code **)(DAT_c05f9198 + 0x20))
                        (iVar2,&local_40,1,auStack_38,0,&local_30,0x10,0,0,0);
    }
  }
  else {
    LeaveCriticalSection(lpCriticalSection);
    uVar1 = 8;
  }
  FUN_c05f7e0c(local_20);
  return uVar1;
}



/* c05f75bc FUN_c05f75bc */

/* Boundary evidence: original MIPS .pdata c05f75bc..c05f7647. Semantic name remains unreviewed. */

int FUN_c05f75bc(int param_1,int param_2)

{
  DWORD DVar1;
  int iVar2;
  
  if (param_1 != 0) {
    iVar2 = 500;
    if (3999 < param_2) {
      iVar2 = 1000;
    }
    DVar1 = GetTickCount();
    if (iVar2 == 0) {
      trap(0x1c00);
    }
    DVar1 = DVar1 % (uint)(iVar2 << 1) - iVar2;
    if ((int)DVar1 < 1) {
      param_2 = DVar1 + param_2;
    }
    else {
      Sleep(DVar1);
    }
  }
  return param_2;
}



/* c05f7648 FUN_c05f7648 */

/* Boundary evidence: original MIPS .pdata c05f7648..c05f7ae3. Semantic name remains unreviewed. */

int FUN_c05f7648(int *param_1,int param_2,int param_3,int param_4,uint param_5)

{
  bool bVar1;
  DWORD DVar2;
  DWORD DVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  LPCRITICAL_SECTION lpCriticalSection;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  byte local_f17 [3];
  int local_f14;
  DWORD local_f10;
  int local_f0c;
  uint local_f08;
  int local_f04;
  uint local_f00;
  DWORD local_efc;
  undefined4 local_ef8;
  int local_ef4;
  int local_ef0;
  int local_eec;
  undefined4 local_ee8;
  char *local_ee4;
  undefined4 local_ee0;
  int local_edc;
  undefined4 local_ed8;
  char acStack_ec8 [3736];
  uint local_30;
  
  local_30 = DAT_c05f9108;
  uVar4 = param_1[8];
  bVar1 = true;
  local_f0c = param_2;
  local_ef4 = param_3;
  if ((uVar4 & 0x200) == 0) {
    local_f04 = param_1[2];
    if ((((param_4 == 5) && ((uVar4 & 0x800) != 0)) && ((*(ushort *)(param_1 + 6) & 0x200) != 0)) ||
       (iVar8 = -1, (param_5 & 0x100) == 0)) {
      iVar8 = param_1[0x1e];
    }
    local_f08 = param_5 & 0xff;
    iVar7 = 0;
    iVar9 = 1000;
    if ((*(ushort *)(param_1 + 6) & 0x100) == 0) {
      iVar10 = 2;
      iVar6 = 1;
      if ((*(ushort *)(param_1 + 6) & 0x40) == 0) {
        iVar9 = 4000;
      }
    }
    else {
      iVar10 = 1;
      iVar6 = 0;
    }
    param_1[8] = uVar4 & 0xfffffff7;
    local_f14 = iVar6;
    FUN_c05f2ce8((int)param_1);
    lpCriticalSection = (LPCRITICAL_SECTION)(param_1 + 0x2b);
    LeaveCriticalSection(lpCriticalSection);
    local_efc = GetTickCount();
    uVar4 = local_f00;
    do {
      DVar2 = GetTickCount();
      local_f10 = DVar2;
      if (bVar1) {
        uVar4 = FUN_c05f75bc(iVar6,iVar9);
        DVar2 = local_f10;
        iVar9 = iVar9 * iVar10;
        *(short *)(local_f0c + 8) = (short)((local_f10 - local_efc) / 1000);
        iVar5 = FUN_c05f7488((int)param_1,local_f0c,local_ef4,iVar8);
        if (iVar5 != 0) break;
      }
      if (((iVar7 != 1) && (iVar7 + 1U == local_f08)) && (8000 < (int)uVar4)) {
        uVar4 = 8000;
      }
      if ((int)uVar4 < 0) {
        uVar4 = 0;
      }
      if (62000 < (int)uVar4) {
        uVar4 = 62000;
      }
      local_ef0 = (int)uVar4 / 1000;
      local_ee0 = 0;
      local_ed8 = 0x29;
      local_eec = ((int)uVar4 % 1000) * 1000;
      local_edc = local_f04;
      iVar5 = (**(code **)(DAT_c05f91a8 + 0x28))(1,&local_ee0,0,0,0,0,&local_ef0,0);
      if (iVar5 != 0) break;
      if (local_edc != 0) {
        local_ee4 = acStack_ec8;
        local_ee8 = 0xe98;
        local_ef8 = 0;
        EnterCriticalSection(lpCriticalSection);
        iVar5 = local_f04;
        if ((param_1[8] & 0x8100U) == 0) {
          if (local_f04 == param_1[2]) {
            LeaveCriticalSection(lpCriticalSection);
            iVar5 = (**(code **)(DAT_c05f9198 + 0x1c))
                              (iVar5,&local_ee8,1,&local_f00,0,&local_ef8,0,0,0,0,0);
          }
          else {
            LeaveCriticalSection(lpCriticalSection);
            iVar5 = 0x2736;
          }
          if (iVar5 != 0) break;
          local_f17[0] = (byte)param_4;
          EnterCriticalSection(lpCriticalSection);
          if ((param_1[8] & 0x8100U) == 0) {
            param_1[8] = param_1[8] | 8;
            iVar5 = FUN_c05f6afc((int)param_1,acStack_ec8,local_f00,local_f17,
                                 *(int *)(local_f0c + 4));
            LeaveCriticalSection(lpCriticalSection);
            if (iVar5 == 0) {
              if (local_f17[0] == (byte)param_4) break;
              if (local_f17[0] == 6) {
                iVar5 = 3;
                break;
              }
            }
            DVar3 = GetTickCount();
            uVar4 = (uVar4 + DVar2) - DVar3;
            goto LAB_c05f7a3c;
          }
        }
        LeaveCriticalSection(lpCriticalSection);
        iVar5 = 8;
        break;
      }
      iVar5 = 1;
      uVar4 = 0;
LAB_c05f7a3c:
      bVar1 = (int)uVar4 < 1;
      if (bVar1) {
        iVar7 = iVar7 + 1;
      }
      iVar6 = local_f14;
    } while (iVar7 < (int)local_f08);
    EnterCriticalSection(lpCriticalSection);
    if ((param_1[8] & 0x8100U) != 0) {
      iVar5 = 8;
    }
    FUN_c05f4ab4(param_1);
    FUN_c05f7e0c(local_30);
  }
  else {
    FUN_c05f7e0c(DAT_c05f9108);
    iVar5 = 7;
  }
  return iVar5;
}



/* c05f7ca4 entry */

/* Boundary evidence: original MIPS .pdata c05f7ca4..c05f7d17. Semantic name remains unreviewed. */

undefined4 entry(HMODULE param_1,int param_2)

{
  undefined4 uVar1;
  
  if (param_2 == 1) {
    FUN_c05f7d18();
    FUN_c05f7fec();
  }
  uVar1 = DllEntry(param_1,param_2);
  if (param_2 == 0) {
    FUN_c05f7f74();
  }
  return uVar1;
}



/* c05f7d18 FUN_c05f7d18 */

/* Boundary evidence: original MIPS .pdata c05f7d18..c05f7d8b. Semantic name remains unreviewed. */

void FUN_c05f7d18(void)

{
  uint uVar1;
  
  if ((DAT_c05f9108 == 0) || (DAT_c05f9108 == 0xb064)) {
    uVar1 = __security_gen_cookie2();
    DAT_c05f9108 = uVar1 >> 0x10 ^ uVar1 & 0xffff;
    if (DAT_c05f9108 == 0) {
      DAT_c05f9108 = 0xb064;
    }
  }
  DAT_c05f910c = ~DAT_c05f9108;
  return;
}



/* c05f7d8c FUN_c05f7d8c */

/* Boundary evidence: original MIPS .pdata c05f7d8c..c05f7ddf. Semantic name remains unreviewed. */

void FUN_c05f7d8c(int param_1,undefined4 param_2,uint *param_3)

{
  if ((*param_3 & 1) != 0) {
    param_1 = ((-param_3[2] & param_3[1] + param_1) - (param_3[1] + param_1)) + param_1;
  }
  FUN_c05f7e0c(*(uint *)(param_1 + (*param_3 & 0xfffffffc)));
  return;
}



/* c05f7de0 FUN_c05f7de0 */

/* Boundary evidence: original MIPS .pdata c05f7de0..c05f7e0b. Semantic name remains unreviewed. */

undefined4 FUN_c05f7de0(undefined4 param_1,int param_2,undefined4 param_3,int param_4)

{
  FUN_c05f7d8c(param_2,param_4,*(uint **)(*(int *)(param_4 + 4) + 0xc));
  return 1;
}



/* c05f7e0c FUN_c05f7e0c */

/* Boundary evidence: original MIPS .pdata c05f7e0c..c05f7e53. Semantic name remains unreviewed. */

void FUN_c05f7e0c(uint param_1)

{
  if ((param_1 == DAT_c05f9108) && (param_1 >> 0x10 == 0)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __report_gsfailure();
}



/* c05f7e54 FUN_c05f7e54 */

/* Boundary evidence: original MIPS .pdata c05f7e54..c05f7f73. Semantic name remains unreviewed. */

void FUN_c05f7e54(UINT param_1,int param_2,int param_3)

{
  LPCRITICAL_SECTION lpCriticalSection;
  undefined4 *_Memory;
  
  DAT_c05f9120 = (undefined1)param_3;
  if (param_2 == 0) {
    _Memory = DAT_c05f91d8;
    if (DAT_c05f91d8 != (undefined4 *)0x0) {
      while (DAT_c05f91d4 = DAT_c05f91d4 + -1, _Memory <= DAT_c05f91d4) {
        if ((code *)*DAT_c05f91d4 != (code *)0x0) {
          (*(code *)*DAT_c05f91d4)();
          _Memory = DAT_c05f91d8;
        }
      }
      free(_Memory);
      DAT_c05f91d4 = (undefined4 *)0x0;
      DAT_c05f91d8 = (undefined4 *)0x0;
    }
    FUN_c05f7f98((undefined4 *)&DAT_c05f1010,(undefined4 *)&DAT_c05f1014);
  }
  FUN_c05f7f98((undefined4 *)&DAT_c05f1018,(undefined4 *)&DAT_c05f101c);
  if (param_3 == 0) {
    TerminateProcess((HANDLE)0x42,param_1);
  }
  else {
    lpCriticalSection = (LPCRITICAL_SECTION)InterlockedExchange((LONG *)&DAT_c05f91dc,0);
    if (lpCriticalSection != (LPCRITICAL_SECTION)0x0) {
      DeleteCriticalSection(lpCriticalSection);
      free(lpCriticalSection);
    }
  }
  return;
}



/* c05f7f74 FUN_c05f7f74 */

/* Boundary evidence: original MIPS .pdata c05f7f74..c05f7f97. Semantic name remains unreviewed. */

void FUN_c05f7f74(void)

{
  FUN_c05f7e54(0,0,1);
  return;
}



/* c05f7f98 FUN_c05f7f98 */

/* Boundary evidence: original MIPS .pdata c05f7f98..c05f7feb. Semantic name remains unreviewed. */

void FUN_c05f7f98(undefined4 *param_1,undefined4 *param_2)

{
  for (; param_1 < param_2; param_1 = param_1 + 1) {
    if ((code *)*param_1 != (code *)0x0) {
      (*(code *)*param_1)();
    }
  }
  return;
}



/* c05f7fec FUN_c05f7fec */

/* Boundary evidence: original MIPS .pdata c05f7fec..c05f8027. Semantic name remains unreviewed. */

void FUN_c05f7fec(void)

{
  FUN_c05f7f98((undefined4 *)&DAT_c05f1008,(undefined4 *)&DAT_c05f100c);
  FUN_c05f7f98((undefined4 *)&DAT_c05f1000,(undefined4 *)&DAT_c05f1004);
  return;
}


