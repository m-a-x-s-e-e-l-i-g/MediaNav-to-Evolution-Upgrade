/* Automatic Ghidra pseudocode. Not original source; not runtime-verified. */

/* 404022e8 FUN_404022e8 */

/* Boundary evidence: original MIPS .pdata 404022e8..40402343. Semantic name remains unreviewed. */

undefined4 * FUN_404022e8(undefined4 *param_1)

{
  int iVar1;
  int iVar2;
  LPVOID pvVar3;
  
  iVar1 = __GetUserKData(0xc);
  iVar2 = GetOwnerProcess();
  if (iVar1 == iVar2) {
    pvVar3 = TlsGetValue(DAT_40430490);
    *param_1 = pvVar3;
  }
  else {
    *param_1 = 0;
  }
  return param_1;
}



/* 40402344 FUN_40402344 */

/* Boundary evidence: original MIPS .pdata 40402344..404023cf. Semantic name remains unreviewed. */

int * FUN_40402344(int *param_1,undefined4 *param_2)

{
  int iVar1;
  int iVar2;
  LPVOID pvVar3;
  undefined4 uVar4;
  
  iVar1 = __GetUserKData(0xc);
  iVar2 = GetOwnerProcess();
  if (iVar1 == iVar2) {
    pvVar3 = TlsGetValue(DAT_40430490);
    *param_1 = (int)pvVar3;
    if (pvVar3 == (LPVOID)0x0) {
      uVar4 = FUN_40406910(param_1);
      *param_2 = uVar4;
    }
    else {
      *param_2 = 0;
    }
  }
  else {
    *param_1 = 0;
    *param_2 = 0x80004006;
  }
  return param_1;
}



/* 404023d0 CoSetState */

/* Boundary evidence: original MIPS .pdata 404023d0..404024f3. Semantic name remains unreviewed. */

undefined4 CoSetState(int *param_1)

{
  HMODULE pHVar1;
  int iVar2;
  undefined4 uVar3;
  int *piVar4;
  HMODULE hLibModule;
  int local_18;
  int local_14;
  
                    /* 0x23d0  10  CoSetState */
  FUN_40402344(&local_14,&local_18);
  if (local_18 < 0) {
    uVar3 = 1;
  }
  else {
    if (param_1 != (int *)0x0) {
      (**(code **)(*param_1 + 4))(param_1);
      EnterCriticalSection((LPCRITICAL_SECTION)&DAT_40430414);
      DAT_4043043c = DAT_4043043c + 1;
      if (DAT_4043043c == 1) {
        DAT_40430440 = LoadLibraryW(L"oleaut32.dll");
      }
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_40430414);
    }
    piVar4 = *(int **)(local_14 + 0x10);
    *(int **)(local_14 + 0x10) = param_1;
    if (piVar4 != (int *)0x0) {
      (**(code **)(*piVar4 + 8))();
      EnterCriticalSection((LPCRITICAL_SECTION)&DAT_40430414);
      pHVar1 = DAT_40430440;
      DAT_4043043c = DAT_4043043c + -1;
      hLibModule = (HMODULE)0x0;
      if (DAT_4043043c == 0) {
        DAT_40430440 = (HMODULE)0x0;
        hLibModule = pHVar1;
      }
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_40430414);
      if ((hLibModule != (HMODULE)0x0) && (iVar2 = IsProcessDying(), iVar2 == 0)) {
        FreeLibrary(hLibModule);
      }
    }
    uVar3 = 0;
  }
  return uVar3;
}



/* 404024f4 FUN_404024f4 */

/* Boundary evidence: original MIPS .pdata 404024f4..40402607. Semantic name remains unreviewed. */

undefined4 FUN_404024f4(undefined4 param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  
  FUN_40408fec(param_1,param_2);
  if (param_2 == 0) {
    if ((DAT_40430444 != 0) && (param_3 == 0)) {
      FUN_40408b48();
      FUN_40406c40();
    }
    FUN_40406a18(param_1,0,param_3);
    DeleteCriticalSection((LPCRITICAL_SECTION)&DAT_40430400);
    DeleteCriticalSection((LPCRITICAL_SECTION)&DAT_40430414);
    DeleteCriticalSection((LPCRITICAL_SECTION)&DAT_404303ec);
    DeleteCriticalSection((LPCRITICAL_SECTION)&DAT_40430428);
    uVar1 = 1;
  }
  else {
    if (param_2 == 1) {
      InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_40430400);
      InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_40430414);
      InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_404303ec);
      InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_40430428);
      DAT_4043044c = param_1;
    }
    uVar1 = FUN_40406a18(param_1,param_2,param_3);
  }
  return uVar1;
}



/* 40402608 CoInitializeEx */

/* Boundary evidence: original MIPS .pdata 40402608..404026cf. Semantic name remains unreviewed. */

HRESULT CoInitializeEx(LPVOID pvReserved,DWORD dwCoInit)

{
  HRESULT HVar1;
  int iVar2;
  int local_10;
  int local_c;
  
                    /* 0x2608  8  CoInitializeEx */
  if ((dwCoInit == 0) && (pvReserved == (LPVOID)0x0)) {
    FUN_40402344(&local_10,&local_c);
    if (local_c < 0) {
      HVar1 = -0x7fffbffa;
    }
    else {
      HVar1 = 1;
      iVar2 = *(int *)(local_10 + 8) + 1;
      *(int *)(local_10 + 8) = iVar2;
      if (iVar2 == 1) {
        EnterCriticalSection((LPCRITICAL_SECTION)&DAT_40430400);
        DAT_40430444 = DAT_40430444 + 1;
        *(uint *)(local_10 + 4) = *(uint *)(local_10 + 4) | 0x140;
        DAT_40430448 = DAT_40430448 + 1;
        LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_40430400);
        HVar1 = 0;
      }
    }
  }
  else {
    HVar1 = -0x7ff8ffa9;
  }
  return HVar1;
}



/* 404026d0 FUN_404026d0 */

/* Boundary evidence: original MIPS .pdata 404026d0..404027bf. Semantic name remains unreviewed. */

void FUN_404026d0(int *param_1,int param_2)

{
  uint uVar1;
  
  uVar1 = *(uint *)(*param_1 + 4);
  if ((uVar1 & 0x20) == 0) {
    *(uint *)(*param_1 + 4) = uVar1 | 0x20;
    if (param_2 == 0) {
      EnterCriticalSection((LPCRITICAL_SECTION)&DAT_40430400);
    }
    if (DAT_40430448 == 1) {
      FUN_40408b68();
    }
    DAT_40430448 = DAT_40430448 + -1;
    if ((param_2 == 0) && (DAT_40430444 == 1)) {
      FUN_40408b48();
      FUN_40406c40();
    }
    DAT_40430444 = DAT_40430444 + -1;
    if (param_2 == 0) {
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_40430400);
    }
    CoSetState((int *)0x0);
    *(undefined4 *)(*param_1 + 4) = 1;
    *(undefined4 *)(*param_1 + 8) = 0;
  }
  return;
}



/* 404027c0 FUN_404027c0 */

/* Boundary evidence: original MIPS .pdata 404027c0..404029ff. Semantic name remains unreviewed. */

undefined4 FUN_404027c0(void)

{
  DWORD DVar1;
  LSTATUS LVar2;
  wchar_t *pwVar3;
  LPCWSTR lpValueName;
  int iVar4;
  undefined4 uVar5;
  HKEY local_b0;
  DWORD local_ac;
  int local_a8;
  DWORD local_a4;
  int local_a0 [2];
  WCHAR aWStack_98 [60];
  uint local_20;
  
  local_20 = DAT_404303e4;
  FUN_40402344(local_a0,&local_b0);
  if (((int)local_b0 < 0) || ((DAT_40430448 == 0 && (*(int *)(local_a0[0] + 8) == 0)))) {
    uVar5 = 0;
    if (DAT_40430450 == 0) {
      DVar1 = GetProcessVersion(0);
      if (DVar1 < 0x40000) {
        DAT_40430454 = 1;
      }
      else {
        LVar2 = RegOpenKeyExW((HKEY)0x80000002,L"Software\\Microsoft\\OLE\\LegacyApps",0,0x20019,
                              &local_b0);
        if (LVar2 == 0) {
          DVar1 = GetModuleFileNameW((HMODULE)0x0,aWStack_98,0x3c);
          if (DVar1 != 0) {
            pwVar3 = wcsrchr(aWStack_98,L'\\');
            lpValueName = aWStack_98;
            if (pwVar3 != (wchar_t *)0x0) {
              lpValueName = pwVar3 + 1;
            }
            local_a4 = 4;
            LVar2 = RegQueryValueExW(local_b0,lpValueName,(LPDWORD)0x0,&local_ac,
                                     (LPBYTE)&DAT_40430454,&local_a4);
            if (((LVar2 != 0) || (local_ac != 4)) || (local_a4 != 4)) {
              DAT_40430454 = 0;
            }
          }
          RegCloseKey(local_b0);
        }
      }
      DAT_40430450 = 1;
    }
    if (((DAT_40430454 != 0) && (FUN_40402344(&local_a8,&local_ac), -1 < (int)local_ac)) &&
       (iVar4 = *(int *)(local_a8 + 8) + 1, *(int *)(local_a8 + 8) = iVar4, iVar4 == 1)) {
      EnterCriticalSection((LPCRITICAL_SECTION)&DAT_40430400);
      DAT_40430444 = DAT_40430444 + 1;
      *(uint *)(local_a8 + 4) = *(uint *)(local_a8 + 4) | 0x140;
      DAT_40430448 = DAT_40430448 + 1;
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_40430400);
      uVar5 = 1;
    }
  }
  else {
    uVar5 = 1;
  }
  FUN_4042f4c4(local_20);
  return uVar5;
}



/* 40402a00 CoUninitialize */

/* Boundary evidence: original MIPS .pdata 40402a00..40402a6b. Semantic name remains unreviewed. */

void CoUninitialize(void)

{
  int local_10 [2];
  
                    /* 0x2a00  15  CoUninitialize */
  FUN_404022e8(local_10);
  if ((local_10[0] != 0) && (*(int *)(local_10[0] + 8) != 0)) {
    if (*(int *)(local_10[0] + 8) == 1) {
      FUN_404026d0(local_10,0);
    }
    else {
      *(int *)(local_10[0] + 8) = *(int *)(local_10[0] + 8) + -1;
    }
  }
  return;
}



/* 40402a6c FUN_40402a6c */

/* Boundary evidence: original MIPS .pdata 40402a6c..40402b4f. Semantic name remains unreviewed. */

int FUN_40402a6c(HKEY param_1,LPCWSTR param_2,LPBYTE param_3,LPDWORD param_4)

{
  int iVar1;
  HKEY local_18 [2];
  
  local_18[0] = (HKEY)0x0;
  if (param_2 == (LPCWSTR)0x0) {
    iVar1 = RegQueryValueExW(param_1,(LPCWSTR)0x0,(LPDWORD)0x0,(LPDWORD)0x0,param_3,param_4);
  }
  else {
    iVar1 = RegOpenKeyExW(param_1,param_2,0,1,local_18);
    if (iVar1 == 0) {
      iVar1 = RegQueryValueExW(local_18[0],(LPCWSTR)0x0,(LPDWORD)0x0,(LPDWORD)0x0,param_3,param_4);
      RegCloseKey(local_18[0]);
    }
  }
  if (iVar1 == 0x57) {
    iVar1 = 2;
  }
  return iVar1;
}



/* 40402b50 FUN_40402b50 */

/* Boundary evidence: original MIPS .pdata 40402b50..40402bbb. Semantic name remains unreviewed. */

HLOCAL FUN_40402b50(wchar_t *param_1)

{
  size_t sVar1;
  HLOCAL _Dst;
  SIZE_T uBytes;
  
  sVar1 = wcslen(param_1);
  uBytes = (sVar1 + 1) * 2;
  _Dst = LocalAlloc(0,uBytes);
  if (_Dst != (HLOCAL)0x0) {
    memcpy(_Dst,param_1,uBytes);
  }
  return _Dst;
}



/* 40402bbc StringFromGUID2 */

/* Boundary evidence: original MIPS .pdata 40402bbc..40402c5f. Semantic name remains unreviewed. */

int StringFromGUID2(GUID *rguid,LPOLESTR lpsz,int cchMax)

{
  BOOL BVar1;
  int iVar2;
  
                    /* 0x2bbc  37  StringFromGUID2 */
  iVar2 = 0;
  if ((((rguid != (GUID *)0x0) && (BVar1 = IsBadReadPtr(rguid,0x10), BVar1 == 0)) &&
      (BVar1 = IsBadWritePtr(lpsz,cchMax), BVar1 == 0)) && (0x26 < cchMax)) {
    iVar2 = FUN_404090c8((int)rguid,lpsz,cchMax);
  }
  return iVar2;
}



/* 40402c60 FUN_40402c60 */

undefined4 FUN_40402c60(int *param_1,int *param_2,int param_3,uint param_4)

{
  ushort uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  
  *param_2 = 0;
  iVar4 = 0;
  if (0 < param_3) {
    do {
      uVar2 = (uint)*(ushort *)*param_1;
      if ((uVar2 < 0x30) || (0x39 < uVar2)) {
        if ((uVar2 < 0x41) || (0x46 < uVar2)) {
          if ((uVar2 < 0x61) || (0x66 < uVar2)) {
            return 0;
          }
          iVar3 = *param_2 * 0x10 + uVar2 + -0x57;
        }
        else {
          iVar3 = *param_2 * 0x10 + uVar2 + -0x37;
        }
      }
      else {
        iVar3 = *param_2 * 0x10 + uVar2 + -0x30;
      }
      *param_2 = iVar3;
      iVar4 = iVar4 + 1;
      *param_1 = *param_1 + 2;
    } while (iVar4 < param_3);
  }
  if ((param_4 != 0) &&
     (uVar1 = *(ushort *)*param_1, *param_1 = (int)((ushort *)*param_1 + 1), uVar1 != param_4)) {
    return 0;
  }
  return 1;
}



/* 40402d4c FUN_40402d4c */

/* Boundary evidence: original MIPS .pdata 40402d4c..40402eff. Semantic name remains unreviewed. */

undefined4 FUN_40402d4c(int param_1,int *param_2)

{
  int iVar1;
  int local_res0 [4];
  undefined1 local_10 [8];
  
  local_res0[0] = param_1;
  iVar1 = FUN_40402c60(local_res0,param_2,8,0x2d);
  if ((iVar1 != 0) && (iVar1 = FUN_40402c60(local_res0,(int *)local_10,4,0x2d), iVar1 != 0)) {
    *(short *)(param_2 + 1) = (short)local_10._0_4_;
    iVar1 = FUN_40402c60(local_res0,(int *)local_10,4,0x2d);
    if (iVar1 != 0) {
      *(short *)((int)param_2 + 6) = (short)local_10._0_4_;
      iVar1 = FUN_40402c60(local_res0,(int *)local_10,2,0);
      if (iVar1 != 0) {
        *(undefined1 *)(param_2 + 2) = local_10[0];
        iVar1 = FUN_40402c60(local_res0,(int *)local_10,2,0x2d);
        if (iVar1 != 0) {
          *(undefined1 *)((int)param_2 + 9) = local_10[0];
          iVar1 = FUN_40402c60(local_res0,(int *)local_10,2,0);
          if (iVar1 != 0) {
            *(undefined1 *)((int)param_2 + 10) = local_10[0];
            iVar1 = FUN_40402c60(local_res0,(int *)local_10,2,0);
            if (iVar1 != 0) {
              *(undefined1 *)((int)param_2 + 0xb) = local_10[0];
              iVar1 = FUN_40402c60(local_res0,(int *)local_10,2,0);
              if (iVar1 != 0) {
                *(undefined1 *)(param_2 + 3) = local_10[0];
                iVar1 = FUN_40402c60(local_res0,(int *)local_10,2,0);
                if (iVar1 != 0) {
                  *(undefined1 *)((int)param_2 + 0xd) = local_10[0];
                  iVar1 = FUN_40402c60(local_res0,(int *)local_10,2,0);
                  if (iVar1 != 0) {
                    *(undefined1 *)((int)param_2 + 0xe) = local_10[0];
                    iVar1 = FUN_40402c60(local_res0,(int *)local_10,2,0);
                    if (iVar1 != 0) {
                      *(undefined1 *)((int)param_2 + 0xf) = local_10[0];
                      return 1;
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  return 0;
}



/* 40402f00 FUN_40402f00 */

/* Boundary evidence: original MIPS .pdata 40402f00..40402f63. Semantic name remains unreviewed. */

undefined4 FUN_40402f00(short *param_1,int *param_2)

{
  int iVar1;
  
  if ((((*param_1 == 0x7b) && (iVar1 = FUN_40402d4c((int)(param_1 + 1),param_2), iVar1 == 1)) &&
      (param_1[0x25] == 0x7d)) && (param_1[0x26] == 0)) {
    return 1;
  }
  return 0;
}



/* 40402f64 FUN_40402f64 */

/* Boundary evidence: original MIPS .pdata 40402f64..40402fc7. Semantic name remains unreviewed. */

undefined4 FUN_40402f64(GUID *param_1,undefined4 *param_2)

{
  HLOCAL pvVar1;
  undefined4 uVar2;
  OLECHAR aOStack_60 [40];
  uint local_10;
  
  local_10 = DAT_404303e4;
  StringFromGUID2(param_1,aOStack_60,0x27);
  pvVar1 = FUN_40402b50(aOStack_60);
  *param_2 = pvVar1;
  if (pvVar1 == (HLOCAL)0x0) {
    uVar2 = 0x8007000e;
  }
  else {
    uVar2 = 0;
  }
  FUN_4042f4c4(local_10);
  return uVar2;
}



/* 40402fc8 FUN_40402fc8 */

/* WARNING: Type propagation algorithm not settling */
/* Boundary evidence: original MIPS .pdata 40402fc8..40403077. Semantic name remains unreviewed. */

int FUN_40402fc8(GUID *param_1,wchar_t *param_2,LPBYTE param_3,DWORD param_4)

{
  int iVar1;
  DWORD local_220 [2];
  wchar_t awStack_218 [5];
  wchar_t awStack_20e [251];
  uint local_18;
  
  local_18 = DAT_404303e4;
  local_220[0] = param_4;
  wcscpy(awStack_218,u_CLSID__40430158);
  iVar1 = StringFromGUID2(param_1,awStack_20e + 1,0xfa);
  awStack_20e[iVar1] = L'\\';
  wcscpy(awStack_20e + iVar1 + 1,param_2);
  iVar1 = FUN_40402a6c((HKEY)0x80000000,awStack_218,param_3,local_220);
  FUN_4042f4c4(local_18);
  return iVar1;
}



/* 40403078 StringFromCLSID */

/* Boundary evidence: original MIPS .pdata 40403078..404030fb. Semantic name remains unreviewed. */

HRESULT StringFromCLSID(IID *rclsid,LPOLESTR *lplpsz)

{
  BOOL BVar1;
  HRESULT HVar2;
  
                    /* 0x3078  36  StringFromCLSID
                       0x3078  38  StringFromIID */
  if (((rclsid == (IID *)0x0) || (BVar1 = IsBadReadPtr(rclsid,0x10), BVar1 != 0)) ||
     (BVar1 = IsBadWritePtr(lplpsz,4), BVar1 != 0)) {
    HVar2 = -0x7ff8ffa9;
  }
  else {
    HVar2 = FUN_40402f64(rclsid,lplpsz);
  }
  return HVar2;
}



/* 404030fc FUN_404030fc */

/* Boundary evidence: original MIPS .pdata 404030fc..4040318b. Semantic name remains unreviewed. */

int FUN_404030fc(wchar_t *param_1,LPCLSID param_2)

{
  int iVar1;
  
  if (param_1 == (wchar_t *)0x0) {
    param_2->Data1 = 0;
    param_2->Data2 = 0;
    param_2->Data3 = 0;
    param_2->Data4[0] = '\0';
    param_2->Data4[1] = '\0';
    param_2->Data4[2] = '\0';
    param_2->Data4[3] = '\0';
    param_2->Data4[4] = '\0';
    param_2->Data4[5] = '\0';
    param_2->Data4[6] = '\0';
    param_2->Data4[7] = '\0';
LAB_40403134:
    iVar1 = 0;
  }
  else {
    if (*param_1 != L'\0') {
      if (*param_1 != L'{') {
        iVar1 = FUN_4040318c(param_1,param_2,0);
        return iVar1;
      }
      iVar1 = FUN_40402f00(param_1,(int *)param_2);
      if (iVar1 != 0) goto LAB_40403134;
    }
    iVar1 = -0x7ffbfe0d;
  }
  return iVar1;
}



/* 4040318c FUN_4040318c */

/* Boundary evidence: original MIPS .pdata 4040318c..4040328b. Semantic name remains unreviewed. */

int FUN_4040318c(wchar_t *param_1,LPCLSID param_2,int param_3)

{
  size_t sVar1;
  int iVar2;
  DWORD local_220 [2];
  wchar_t awStack_218 [256];
  uint local_18;
  
  local_18 = DAT_404303e4;
  local_220[0] = 0x200;
  if ((param_1 == (wchar_t *)0x0) || (sVar1 = wcslen(param_1), 0xf9 < sVar1)) {
    FUN_4042f4c4(local_18);
    iVar2 = -0x7ff8ffa9;
  }
  else if (*param_1 == L'\0') {
    FUN_4042f4c4(local_18);
    iVar2 = -0x7ffbfe0d;
  }
  else {
    wcscpy(awStack_218,param_1);
    wcscat(awStack_218,L"\\Clsid");
    iVar2 = FUN_40402a6c((HKEY)0x80000000,awStack_218,(LPBYTE)awStack_218,local_220);
    if (iVar2 == 0) {
      iVar2 = FUN_404030fc(awStack_218,param_2);
    }
    else {
      iVar2 = FUN_404094a4(param_1,param_2,param_3);
    }
    FUN_4042f4c4(local_18);
  }
  return iVar2;
}



/* 4040328c FUN_4040328c */

/* Boundary evidence: original MIPS .pdata 4040328c..4040334f. Semantic name remains unreviewed. */

undefined4 FUN_4040328c(GUID *param_1,undefined4 *param_2)

{
  int iVar1;
  HLOCAL pvVar2;
  undefined4 uVar3;
  wchar_t awStack_210 [256];
  uint local_10;
  
  local_10 = DAT_404303e4;
  *param_2 = 0;
  iVar1 = FUN_40402fc8(param_1,u_ProgID_40430148,(LPBYTE)awStack_210,0x200);
  if (iVar1 == 0) {
    pvVar2 = FUN_40402b50(awStack_210);
    *param_2 = pvVar2;
    if (pvVar2 == (HLOCAL)0x0) {
      uVar3 = 0x8007000e;
    }
    else {
      uVar3 = 0;
    }
    FUN_4042f4c4(local_10);
  }
  else if (((iVar1 == 2) || (iVar1 == 0x57)) || (iVar1 == 0x3f2)) {
    FUN_4042f4c4(local_10);
    uVar3 = 0x80040154;
  }
  else {
    FUN_4042f4c4(local_10);
    uVar3 = 0x80040150;
  }
  return uVar3;
}



/* 40403350 CLSIDFromString */

/* Boundary evidence: original MIPS .pdata 40403350..404033d3. Semantic name remains unreviewed. */

HRESULT CLSIDFromString(LPCOLESTR lpsz,LPCLSID pclsid)

{
  BOOL BVar1;
  int iVar2;
  
                    /* 0x3350  2  CLSIDFromString */
  if (((lpsz == (LPCOLESTR)0x0) || (BVar1 = IsBadReadPtr(lpsz,1), BVar1 == 0)) &&
     (BVar1 = IsBadWritePtr(pclsid,0x10), BVar1 == 0)) {
    iVar2 = FUN_404030fc(lpsz,pclsid);
  }
  else {
    iVar2 = -0x7ff8ffa9;
  }
  return iVar2;
}



/* 404033d4 FUN_404033d4 */

/* Boundary evidence: original MIPS .pdata 404033d4..404034a7. Semantic name remains unreviewed. */

int FUN_404033d4(wchar_t *param_1,LPCLSID param_2,int param_3)

{
  BOOL BVar1;
  int iVar2;
  
  if (((param_1 == (wchar_t *)0x0) || (BVar1 = IsBadReadPtr(param_1,1), BVar1 != 0)) ||
     (BVar1 = IsBadWritePtr(param_2,0x10), BVar1 != 0)) {
    iVar2 = -0x7ff8ffa9;
  }
  else if (*param_1 == L'\0') {
    param_2->Data1 = 0;
    param_2->Data2 = 0;
    param_2->Data3 = 0;
    param_2->Data4[0] = '\0';
    param_2->Data4[1] = '\0';
    param_2->Data4[2] = '\0';
    param_2->Data4[3] = '\0';
    iVar2 = -0x7ffbfe0d;
    param_2->Data4[4] = '\0';
    param_2->Data4[5] = '\0';
    param_2->Data4[6] = '\0';
    param_2->Data4[7] = '\0';
  }
  else {
    iVar2 = FUN_4040318c(param_1,param_2,param_3);
  }
  return iVar2;
}



/* 404034a8 ProgIDFromCLSID */

/* Boundary evidence: original MIPS .pdata 404034a8..4040352b. Semantic name remains unreviewed. */

HRESULT ProgIDFromCLSID(IID *clsid,LPOLESTR *lplpszProgID)

{
  BOOL BVar1;
  HRESULT HVar2;
  
                    /* 0x34a8  28  ProgIDFromCLSID */
  if (((clsid == (IID *)0x0) || (BVar1 = IsBadReadPtr(clsid,0x10), BVar1 != 0)) ||
     (BVar1 = IsBadWritePtr(lplpszProgID,4), BVar1 != 0)) {
    HVar2 = -0x7ff8ffa9;
  }
  else {
    HVar2 = FUN_4040328c(clsid,lplpszProgID);
  }
  return HVar2;
}



/* 4040352c CLSIDFromProgID */

/* Boundary evidence: original MIPS .pdata 4040352c..40403547. Semantic name remains unreviewed. */

HRESULT CLSIDFromProgID(LPCOLESTR lpszProgID,LPCLSID lpclsid)

{
  int iVar1;
  
                    /* 0x352c  1  CLSIDFromProgID */
  iVar1 = FUN_404033d4(lpszProgID,lpclsid,0);
  return iVar1;
}



/* 40403548 CoCreateInstance */

/* Boundary evidence: original MIPS .pdata 40403548..4040364b. Semantic name remains unreviewed. */

HRESULT CoCreateInstance(IID *rclsid,LPUNKNOWN pUnkOuter,DWORD dwClsContext,IID *riid,LPVOID *ppv)

{
  BOOL BVar1;
  int iVar2;
  IID *local_28;
  LPVOID local_24;
  
                    /* 0x3548  3  CoCreateInstance */
  if ((((rclsid != (IID *)0x0) && (BVar1 = IsBadReadPtr(rclsid,0x10), BVar1 == 0)) &&
      ((pUnkOuter == (LPUNKNOWN)0x0 || (iVar2 = FUN_40409b68(), iVar2 != 0)))) &&
     (((riid != (IID *)0x0 && (BVar1 = IsBadReadPtr(riid,0x10), BVar1 == 0)) &&
      (BVar1 = IsBadWritePtr(ppv,4), BVar1 == 0)))) {
    local_24 = (LPVOID)0x0;
    local_28 = riid;
    iVar2 = FUN_4040993c((int *)rclsid,pUnkOuter,dwClsContext,0,1,&local_28);
    *ppv = local_24;
    return iVar2;
  }
  return -0x7ff8ffa9;
}



/* 4040364c CoLoadLibrary */

/* Boundary evidence: original MIPS .pdata 4040364c..40403667. Semantic name remains unreviewed. */

HINSTANCE CoLoadLibrary(LPOLESTR lpszLibName,BOOL bAutoFree)

{
  HMODULE pHVar1;
  
                    /* 0x364c  9  CoLoadLibrary */
  pHVar1 = LoadLibraryW(lpszLibName);
  return pHVar1;
}



/* 40403668 CoFreeLibrary */

/* Boundary evidence: original MIPS .pdata 40403668..4040368b. Semantic name remains unreviewed. */

void CoFreeLibrary(HINSTANCE hInst)

{
                    /* 0x3668  4  CoFreeLibrary */
  FreeLibrary(hInst);
  return;
}



/* 4040368c CoFreeUnusedLibraries */

/* Boundary evidence: original MIPS .pdata 4040368c..404036bf. Semantic name remains unreviewed. */

void CoFreeUnusedLibraries(void)

{
  int local_10;
  int iStack_c;
  
                    /* 0x368c  5  CoFreeUnusedLibraries */
  FUN_40402344(&iStack_c,&local_10);
  if (-1 < local_10) {
    FUN_40408b88(0xffffffff);
  }
  return;
}



/* 404036c0 CoFreeUnusedLibrariesEx */

/* Boundary evidence: original MIPS .pdata 404036c0..404036ff. Semantic name remains unreviewed. */

void CoFreeUnusedLibrariesEx(DWORD dwUnloadDelay,DWORD dwReserved)

{
  int local_10;
  int iStack_c;
  
                    /* 0x36c0  6  CoFreeUnusedLibrariesEx */
  FUN_40402344(&iStack_c,&local_10);
  if (-1 < local_10) {
    FUN_40408b88(dwUnloadDelay);
  }
  return;
}



/* 40403700 CoGetClassObject */

/* Boundary evidence: original MIPS .pdata 40403700..4040381f. Semantic name remains unreviewed. */

HRESULT CoGetClassObject(IID *rclsid,DWORD dwClsContext,LPVOID pvReserved,IID *riid,LPVOID *ppv)

{
  int iVar1;
  BOOL BVar2;
  DWORD DVar3;
  
                    /* 0x3700  7  CoGetClassObject */
  DVar3 = 0x80070057;
  if (ppv != (LPVOID *)0x0) {
    *ppv = (LPVOID)0x0;
  }
  iVar1 = FUN_404027c0();
  if (iVar1 == 0) {
    DVar3 = 0x800401f0;
  }
  else if ((((rclsid == (IID *)0x0) || (BVar2 = IsBadReadPtr(rclsid,0x10), BVar2 == 0)) &&
           ((riid == (IID *)0x0 || (BVar2 = IsBadReadPtr(riid,0x10), BVar2 == 0)))) &&
          ((BVar2 = IsBadWritePtr(ppv,4), BVar2 == 0 && ((dwClsContext & 0xffffffe8) == 0)))) {
    *ppv = (LPVOID)0x0;
    DVar3 = FUN_40409834((int *)rclsid,dwClsContext,(int)pvReserved,(undefined *)riid,(int *)ppv);
  }
  return DVar3;
}



/* 40403820 FUN_40403820 */

/* Boundary evidence: original MIPS .pdata 40403820..40403873. Semantic name remains unreviewed. */

int FUN_40403820(int *param_1,undefined *param_2,undefined4 param_3,undefined4 param_4,uint param_5,
                undefined4 param_6,DWORD *param_7)

{
  int iVar1;
  
  iVar1 = 0;
  if ((param_5 & 1) != 0) {
    iVar1 = FUN_40408e70((uint *)&DAT_40430458,param_1,param_2,0,0,param_5 & 1,param_6,param_7);
  }
  return iVar1;
}



/* 40403874 CoTaskMemAlloc */

/* Boundary evidence: original MIPS .pdata 40403874..40403893. Semantic name remains unreviewed. */

LPVOID CoTaskMemAlloc(SIZE_T cb)

{
  HLOCAL pvVar1;
  
                    /* 0x3874  11  CoTaskMemAlloc */
  pvVar1 = LocalAlloc(0,cb);
  return pvVar1;
}



/* 40403894 CoTaskMemFree */

/* Boundary evidence: original MIPS .pdata 40403894..404038af. Semantic name remains unreviewed. */

void CoTaskMemFree(LPVOID pv)

{
                    /* 0x3894  12  CoTaskMemFree */
  LocalFree(pv);
  return;
}



/* 404038b0 CoTaskMemRealloc */

/* Boundary evidence: original MIPS .pdata 404038b0..404038e3. Semantic name remains unreviewed. */

LPVOID CoTaskMemRealloc(LPVOID pv,SIZE_T cb)

{
  HLOCAL pvVar1;
  
                    /* 0x38b0  13  CoTaskMemRealloc */
  if (pv == (LPVOID)0x0) {
    pvVar1 = LocalAlloc(0,cb);
  }
  else {
    pvVar1 = LocalReAlloc(pv,cb,2);
  }
  return pvVar1;
}



/* 404038e4 CoTaskMemSize */

/* Boundary evidence: original MIPS .pdata 404038e4..404038ff. Semantic name remains unreviewed. */

void CoTaskMemSize(HLOCAL param_1)

{
                    /* 0x38e4  14  CoTaskMemSize */
  LocalSize(param_1);
  return;
}



/* 40403900 CreateBindCtx */

/* Boundary evidence: original MIPS .pdata 40403900..4040397b. Semantic name remains unreviewed. */

HRESULT CreateBindCtx(DWORD reserved,LPBC *ppbc)

{
  BOOL BVar1;
  HRESULT HVar2;
  LPBC pIVar3;
  
                    /* 0x3900  16  CreateBindCtx */
  BVar1 = IsBadWritePtr(ppbc,4);
  if ((BVar1 == 0) && (reserved == 0)) {
    pIVar3 = (LPBC)FUN_4040a4dc();
    *ppbc = pIVar3;
    if (pIVar3 == (LPBC)0x0) {
      HVar2 = -0x7ff8fff2;
    }
    else {
      HVar2 = 0;
    }
  }
  else {
    HVar2 = -0x7ff8ffa9;
  }
  return HVar2;
}



/* 4040397c FUN_4040397c */

undefined4 FUN_4040397c(int *param_1,int *param_2)

{
  undefined4 uVar1;
  
  if ((((*param_1 != *param_2) || (param_1[1] != param_2[1])) || (param_1[2] != param_2[2])) ||
     (uVar1 = 1, param_1[3] != param_2[3])) {
    uVar1 = 0;
  }
  return uVar1;
}



/* 404039c8 FUN_404039c8 */

/* Boundary evidence: original MIPS .pdata 404039c8..40403a4f. Semantic name remains unreviewed. */

void FUN_404039c8(undefined4 *param_1)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  
  piVar2 = (int *)param_1[2];
  *param_1 = &PTR_FUN_404010bc;
  if (piVar2 != (int *)0x0) {
    iVar3 = 0;
    if (0 < (int)param_1[3]) {
      do {
        piVar1 = (int *)*piVar2;
        *piVar2 = 0;
        if (piVar1 != (int *)0x0) {
          (**(code **)(*piVar1 + 8))();
        }
        iVar3 = iVar3 + 1;
        piVar2 = piVar2 + 1;
      } while (iVar3 < (int)param_1[3]);
    }
    CoTaskMemFree((LPVOID)param_1[2]);
  }
  return;
}



/* 40403a50 FUN_40403a50 */

/* Boundary evidence: original MIPS .pdata 40403a50..40403b13. Semantic name remains unreviewed. */

undefined4 FUN_40403a50(int *param_1,int *param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  
  uVar1 = 0x80004002;
  if (((((*param_2 == 0) && (param_2[1] == 0)) && (param_2[2] == 0xc0)) &&
      (param_2[3] == 0x46000000)) ||
     (((*param_2 == 0x111 && (param_2[1] == 0)) &&
      ((param_2[2] == 0xc0 && (param_2[3] == 0x46000000)))))) {
    *param_3 = param_1;
    (**(code **)(*param_1 + 4))();
    uVar1 = 0;
  }
  else {
    *param_3 = 0;
  }
  return uVar1;
}



/* 40403b14 FUN_40403b14 */

/* Boundary evidence: original MIPS .pdata 40403b14..40403b3f. Semantic name remains unreviewed. */

LONG FUN_40403b14(int param_1)

{
  InterlockedIncrement((LONG *)(param_1 + 4));
  return *(LONG *)(param_1 + 4);
}



/* 40403b40 FUN_40403b40 */

/* Boundary evidence: original MIPS .pdata 40403b40..40403c67. Semantic name remains unreviewed. */

undefined4 FUN_40403b40(int param_1,int *param_2,int *param_3)

{
  LPVOID pvVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  
  if (param_3 != (int *)0x0) {
    *param_3 = 0;
  }
  iVar4 = *(int *)(param_1 + 0xc);
  iVar5 = -1;
  iVar2 = 0;
  piVar3 = *(int **)(param_1 + 8);
  if (0 < iVar4) {
    do {
      if ((*piVar3 == 0) && (iVar5 == -1)) {
        iVar5 = iVar2;
      }
      iVar2 = iVar2 + 1;
      piVar3 = piVar3 + 1;
    } while (iVar2 < iVar4);
    if (iVar5 != -1) goto LAB_40403c08;
  }
  pvVar1 = CoTaskMemRealloc(*(int **)(param_1 + 8),(iVar4 + 5) * 4);
  if (pvVar1 == (LPVOID)0x0) {
    return 0x8007000e;
  }
  memset((void *)(*(int *)(param_1 + 0xc) * 4 + (int)pvVar1),0,0x14);
  iVar5 = *(int *)(param_1 + 0xc);
  *(LPVOID *)(param_1 + 8) = pvVar1;
  *(int *)(param_1 + 0xc) = iVar5 + 5;
LAB_40403c08:
  (**(code **)(*param_2 + 4))(param_2);
  *(int **)(iVar5 * 4 + *(int *)(param_1 + 8)) = param_2;
  if (param_3 != (int *)0x0) {
    *param_3 = iVar5 + 1;
  }
  return 0;
}



/* 40403c68 FUN_40403c68 */

/* Boundary evidence: original MIPS .pdata 40403c68..40403cdf. Semantic name remains unreviewed. */

undefined4 FUN_40403c68(int param_1,int param_2)

{
  int *piVar1;
  int *piVar2;
  
  if ((0 < param_2) && (param_2 + -1 < *(int *)(param_1 + 0xc))) {
    piVar2 = (int *)((param_2 + -1) * 4 + *(int *)(param_1 + 8));
    piVar1 = (int *)*piVar2;
    if (piVar1 != (int *)0x0) {
      *piVar2 = 0;
      (**(code **)(*piVar1 + 8))();
      return 0;
    }
  }
  return 0x80040004;
}



/* 40403cf0 FUN_40403cf0 */

/* Boundary evidence: original MIPS .pdata 40403cf0..40403d5b. Semantic name remains unreviewed. */

undefined4 FUN_40403cf0(int param_1,undefined4 param_2)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  
  iVar3 = *(int *)(param_1 + 0xc);
  piVar2 = *(int **)(param_1 + 8);
  if (0 < iVar3) {
    do {
      piVar1 = (int *)*piVar2;
      if (piVar1 != (int *)0x0) {
        (**(code **)(*piVar1 + 0x14))(piVar1,param_2);
      }
      iVar3 = iVar3 + -1;
      piVar2 = piVar2 + 1;
    } while (iVar3 != 0);
  }
  return 0;
}



/* 40403d5c FUN_40403d5c */

/* Boundary evidence: original MIPS .pdata 40403d5c..40403dbb. Semantic name remains unreviewed. */

undefined4 FUN_40403d5c(int param_1)

{
  int *piVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0xc);
  piVar1 = *(int **)(param_1 + 8);
  if (0 < iVar2) {
    do {
      if ((int *)*piVar1 != (int *)0x0) {
        (**(code **)(*(int *)*piVar1 + 0x18))();
      }
      iVar2 = iVar2 + -1;
      piVar1 = piVar1 + 1;
    } while (iVar2 != 0);
  }
  return 0;
}



/* 40403dbc FUN_40403dbc */

/* Boundary evidence: original MIPS .pdata 40403dbc..40403e1b. Semantic name remains unreviewed. */

undefined4 FUN_40403dbc(int param_1)

{
  int *piVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0xc);
  piVar1 = *(int **)(param_1 + 8);
  if (0 < iVar2) {
    do {
      if ((int *)*piVar1 != (int *)0x0) {
        (**(code **)(*(int *)*piVar1 + 0x1c))();
      }
      iVar2 = iVar2 + -1;
      piVar1 = piVar1 + 1;
    } while (iVar2 != 0);
  }
  return 0;
}



/* 40403e1c FUN_40403e1c */

/* Boundary evidence: original MIPS .pdata 40403e1c..40403e7b. Semantic name remains unreviewed. */

LONG FUN_40403e1c(undefined4 *param_1)

{
  LONG LVar1;
  
  LVar1 = InterlockedDecrement(param_1 + 1);
  if (LVar1 == 0) {
    if (param_1 != (undefined4 *)0x0) {
      FUN_404039c8(param_1);
      operator_delete(param_1);
    }
    LVar1 = 0;
  }
  else {
    LVar1 = param_1[1];
  }
  return LVar1;
}



/* 40403e7c FUN_40403e7c */

/* Boundary evidence: original MIPS .pdata 40403e7c..40403ebf. Semantic name remains unreviewed. */

undefined4 * FUN_40403e7c(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_404010bc;
  param_1[3] = 0;
  param_1[2] = 0;
  param_1[1] = 0;
  InterlockedIncrement(param_1 + 1);
  return param_1;
}



/* 40403ec0 CreateOleAdviseHolder */

/* Boundary evidence: original MIPS .pdata 40403ec0..40403f1b. Semantic name remains unreviewed. */

HRESULT CreateOleAdviseHolder(LPOLEADVISEHOLDER *ppOAHolder)

{
  undefined4 *puVar1;
  LPOLEADVISEHOLDER pIVar2;
  HRESULT HVar3;
  
                    /* 0x3ec0  17  CreateOleAdviseHolder */
  puVar1 = operator_new(0x10);
  if (puVar1 == (undefined4 *)0x0) {
    pIVar2 = (LPOLEADVISEHOLDER)0x0;
  }
  else {
    pIVar2 = (LPOLEADVISEHOLDER)FUN_40403e7c(puVar1);
  }
  *ppOAHolder = pIVar2;
  if (pIVar2 == (LPOLEADVISEHOLDER)0x0) {
    HVar3 = -0x7ff8fff2;
  }
  else {
    HVar3 = 0;
  }
  return HVar3;
}



/* 40403f1c FUN_40403f1c */

/* Boundary evidence: original MIPS .pdata 40403f1c..4040403f. Semantic name remains unreviewed. */

undefined4 FUN_40403f1c(int *param_1,int *param_2,int *param_3)

{
  BOOL BVar1;
  undefined4 uVar2;
  
  BVar1 = IsBadWritePtr(param_3,4);
  if (BVar1 == 0) {
    *param_3 = 0;
    if ((param_1[5] == 0) ||
       (((((*param_2 != 0xc || (param_2[1] != 0)) || (param_2[2] != 0xc0)) ||
         (param_2[3] != 0x46000000)) &&
        (((*param_2 != 0 || (param_2[1] != 0)) ||
         ((param_2[2] != 0xc0 || (param_2[3] != 0x46000000)))))))) {
      *param_3 = 0;
      uVar2 = 0x80004002;
    }
    else {
      (**(code **)(*param_1 + 4))(param_1);
      uVar2 = 0;
      *param_3 = (int)param_1;
    }
  }
  else {
    uVar2 = 0x80070057;
  }
  return uVar2;
}



/* 40404040 FUN_40404040 */

/* Boundary evidence: original MIPS .pdata 40404040..4040405b. Semantic name remains unreviewed. */

void FUN_40404040(int param_1)

{
  InterlockedIncrement((LONG *)(param_1 + 8));
  return;
}



/* 4040405c FUN_4040405c */

/* Boundary evidence: original MIPS .pdata 4040405c..4040419f. Semantic name remains unreviewed. */

undefined4 FUN_4040405c(int param_1,void *param_2,size_t param_3,size_t *param_4)

{
  BOOL BVar1;
  uint uVar2;
  uint uVar3;
  undefined4 uVar4;
  
  BVar1 = IsBadWritePtr(param_2,1);
  if (BVar1 != 0) {
    return 0x80070057;
  }
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x18));
  if (param_4 != (size_t *)0x0) {
    BVar1 = IsBadWritePtr(param_4,4);
    if (BVar1 != 0) {
      uVar4 = 0x80070057;
      goto LAB_40404170;
    }
    *param_4 = 0;
  }
  uVar2 = *(uint *)(param_1 + 0xc);
  uVar3 = **(uint **)(param_1 + 0x14);
  if (uVar3 < uVar2 + param_3) {
    if (uVar2 <= uVar3) {
      param_3 = uVar3 - uVar2;
      goto LAB_40404124;
    }
    param_3 = 0;
  }
  else {
LAB_40404124:
    if (param_3 != 0) {
      uVar3 = (*(uint **)(param_1 + 0x14))[3];
      if (uVar3 == 0) {
        uVar4 = 0x8003001e;
        goto LAB_40404170;
      }
      memcpy(param_2,(void *)(uVar2 + uVar3),param_3);
      *(size_t *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + param_3;
    }
  }
  if (param_4 != (size_t *)0x0) {
    *param_4 = param_3;
  }
  uVar4 = 0;
LAB_40404170:
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x18));
  return uVar4;
}



/* 404041a0 FUN_404041a0 */

/* Boundary evidence: original MIPS .pdata 404041a0..404042d3. Semantic name remains unreviewed. */

int FUN_404041a0(int *param_1,void *param_2,size_t param_3,size_t *param_4)

{
  BOOL BVar1;
  int iVar2;
  
  iVar2 = 0;
  if ((param_2 != (void *)0x0) && (BVar1 = IsBadReadPtr(param_2,1), BVar1 != 0)) {
    return -0x7ff8ffa9;
  }
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 6));
  if (param_4 != (size_t *)0x0) {
    *param_4 = 0;
  }
  if ((param_1[3] + param_3 <= *(uint *)param_1[5]) ||
     (iVar2 = (**(code **)(*param_1 + 0x18))(param_1), iVar2 == 0)) {
    if (param_3 != 0) {
      if (*(int *)(param_1[5] + 0xc) == 0) {
        iVar2 = -0x7ffcffe3;
        goto LAB_404042a4;
      }
      memmove((void *)(param_1[3] + *(int *)(param_1[5] + 0xc)),param_2,param_3);
      param_1[3] = param_1[3] + param_3;
    }
    if (param_4 != (size_t *)0x0) {
      *param_4 = param_3;
    }
  }
LAB_404042a4:
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 6));
  return iVar2;
}



/* 404042d4 FUN_404042d4 */

/* Boundary evidence: original MIPS .pdata 404042d4..40404423. Semantic name remains unreviewed. */

undefined4
FUN_404042d4(int param_1,undefined4 param_2,int param_3,undefined4 param_4,int param_5,
            undefined4 *param_6)

{
  BOOL BVar1;
  int iVar2;
  undefined4 uVar3;
  
  uVar3 = 0;
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x18));
  if (param_6 != (undefined4 *)0x0) {
    BVar1 = IsBadWritePtr(param_6,4);
    if (BVar1 != 0) {
      uVar3 = 0x80070057;
      goto LAB_404043f8;
    }
    param_6[1] = 0;
    *param_6 = *(undefined4 *)(param_1 + 0xc);
  }
  if (param_5 == 0) {
    if (param_3 < 0) goto LAB_404043dc;
    *(int *)(param_1 + 0xc) = param_3;
  }
  else {
    if (param_5 == 1) {
      if ((param_3 < 0) && (*(uint *)(param_1 + 0xc) < (uint)-param_3)) goto LAB_404043dc;
      iVar2 = *(int *)(param_1 + 0xc);
    }
    else {
      if ((param_5 != 2) || ((param_3 < 0 && (**(uint **)(param_1 + 0x14) < (uint)-param_3)))) {
LAB_404043dc:
        uVar3 = 0x80030019;
        goto LAB_404043e4;
      }
      iVar2 = **(int **)(param_1 + 0x14);
    }
    *(int *)(param_1 + 0xc) = iVar2 + param_3;
  }
LAB_404043e4:
  if (param_6 != (undefined4 *)0x0) {
    param_6[1] = 0;
    *param_6 = *(undefined4 *)(param_1 + 0xc);
  }
LAB_404043f8:
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x18));
  return uVar3;
}



/* 40404424 FUN_40404424 */

/* Boundary evidence: original MIPS .pdata 40404424..404044c7. Semantic name remains unreviewed. */

undefined4 FUN_40404424(int param_1,undefined4 param_2,uint param_3)

{
  HLOCAL pvVar1;
  uint uBytes;
  undefined4 uVar2;
  
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x18));
  if (**(uint **)(param_1 + 0x14) != param_3) {
    uBytes = param_3;
    if (param_3 < 2) {
      uBytes = 1;
    }
    pvVar1 = LocalReAlloc((HLOCAL)(*(uint **)(param_1 + 0x14))[3],uBytes,2);
    if (pvVar1 == (HLOCAL)0x0) {
      uVar2 = 0x8007000e;
      goto LAB_404044a4;
    }
    *(HLOCAL *)(*(int *)(param_1 + 0x14) + 0xc) = pvVar1;
    **(uint **)(param_1 + 0x14) = param_3;
  }
  uVar2 = 0;
LAB_404044a4:
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x18));
  return uVar2;
}



/* 404044c8 FUN_404044c8 */

/* Boundary evidence: original MIPS .pdata 404044c8..40404637. Semantic name remains unreviewed. */

undefined4
FUN_404044c8(int param_1,int *param_2,int param_3,int param_4,int *param_5,undefined4 *param_6)

{
  BOOL BVar1;
  int iVar2;
  uint *puVar3;
  undefined4 uVar4;
  undefined4 local_28 [2];
  
  local_28[0] = 0;
  uVar4 = 0;
  if ((param_2 != (int *)0x0) && (BVar1 = IsBadReadPtr(param_2,4), BVar1 != 0)) {
    return 0x80070057;
  }
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x18));
  if ((param_3 == -1) && (param_4 == -1)) {
    puVar3 = *(uint **)(param_1 + 0x14);
    iVar2 = *(int *)(param_1 + 0xc);
    param_3 = *puVar3 - iVar2;
  }
  else {
    puVar3 = *(uint **)(param_1 + 0x14);
    iVar2 = *(int *)(param_1 + 0xc);
    if (param_4 == 0) {
      if (*puVar3 < (uint)(iVar2 + param_3)) {
        param_3 = *puVar3 - iVar2;
      }
    }
    else {
      param_3 = *puVar3 - iVar2;
    }
  }
  if (param_3 != 0) {
    if (puVar3[3] == 0) {
      uVar4 = 0x80030008;
      goto LAB_40404608;
    }
    uVar4 = (**(code **)(*param_2 + 0x10))(param_2,iVar2 + puVar3[3],param_3,local_28);
  }
  *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + param_3;
  if (param_5 != (int *)0x0) {
    param_5[1] = 0;
    *param_5 = param_3;
  }
  if (param_6 != (undefined4 *)0x0) {
    param_6[1] = 0;
    *param_6 = local_28[0];
  }
LAB_40404608:
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x18));
  return uVar4;
}



/* 40404638 FUN_40404638 */

/* Boundary evidence: original MIPS .pdata 40404638..404046b3. Semantic name remains unreviewed. */

undefined4 FUN_40404638(int param_1,void *param_2)

{
  BOOL BVar1;
  undefined4 uVar2;
  
  BVar1 = IsBadWritePtr(param_2,0x48);
  if (BVar1 == 0) {
    memset(param_2,0,0x48);
    *(undefined4 *)((int)param_2 + 4) = 2;
    uVar2 = 0;
    *(undefined4 *)((int)param_2 + 8) = **(undefined4 **)(param_1 + 0x14);
  }
  else {
    uVar2 = 0x80070057;
  }
  return uVar2;
}



/* 404046b4 FUN_404046b4 */

/* Boundary evidence: original MIPS .pdata 404046b4..4040471f. Semantic name remains unreviewed. */

void FUN_404046b4(int *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *param_1;
  if ((iVar2 != 0) && (iVar1 = *(int *)(iVar2 + 4) + -1, *(int *)(iVar2 + 4) = iVar1, iVar1 == 0)) {
    if (*(int *)(iVar2 + 0x10) != 0) {
      LocalFree(*(HLOCAL *)(iVar2 + 0xc));
    }
    if (param_2 == 0) {
      LocalFree((HLOCAL)*param_1);
    }
  }
  *param_1 = 0;
  return;
}



/* 40404720 GetHGlobalFromStream */

/* Boundary evidence: original MIPS .pdata 40404720..404047eb. Semantic name remains unreviewed. */

HRESULT GetHGlobalFromStream(LPSTREAM pstm,HGLOBAL *phglobal)

{
  int iVar1;
  BOOL BVar2;
  
                    /* 0x4720  20  GetHGlobalFromStream */
  iVar1 = FUN_40409b68();
  if ((iVar1 != 0) &&
     ((phglobal == (HGLOBAL *)0x0 || (BVar2 = IsBadReadPtr(phglobal,4), BVar2 == 0)))) {
    BVar2 = IsBadReadPtr(pstm + 1,4);
    if ((BVar2 == 0) && (pstm[1].lpVtbl == (IStreamVtbl *)0x4d525453)) {
      if (pstm[5].lpVtbl == (IStreamVtbl *)0x0) {
        return -0x7ff8fff2;
      }
      *phglobal = (pstm[5].lpVtbl)->Read;
      return 0;
    }
  }
  return -0x7ff8ffa9;
}



/* 404047ec FUN_404047ec */

/* Boundary evidence: original MIPS .pdata 404047ec..4040485b. Semantic name remains unreviewed. */

LONG FUN_404047ec(undefined4 *param_1)

{
  LONG LVar1;
  
  LVar1 = InterlockedDecrement(param_1 + 2);
  if ((LVar1 == 0) && (FUN_404046b4(param_1 + 4,0), param_1 != (undefined4 *)0x0)) {
    *param_1 = &PTR_FUN_404010e0;
    DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 6));
    LocalFree(param_1);
  }
  return LVar1;
}



/* 4040485c FUN_4040485c */

/* Boundary evidence: original MIPS .pdata 4040485c..404048a3. Semantic name remains unreviewed. */

undefined4 * FUN_4040485c(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_404010e0;
  InitializeCriticalSection((LPCRITICAL_SECTION)(param_1 + 6));
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[3] = 0;
  param_1[2] = 0;
  return param_1;
}



/* 404048a4 FUN_404048a4 */

/* Boundary evidence: original MIPS .pdata 404048a4..40404923. Semantic name remains unreviewed. */

undefined4 * FUN_404048a4(int param_1)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)0x0;
  if (param_1 != 0) {
    puVar1 = LocalAlloc(0,0x2c);
    if (puVar1 == (undefined4 *)0x0) {
      puVar1 = (undefined4 *)0x0;
    }
    else {
      puVar1 = FUN_4040485c(puVar1);
    }
    if (puVar1 != (undefined4 *)0x0) {
      puVar1[4] = param_1;
      puVar1[5] = param_1;
      *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + 1;
      puVar1[2] = 1;
      puVar1[1] = 0x4d525453;
    }
  }
  return puVar1;
}



/* 40404924 CreateStreamOnHGlobal */

/* Boundary evidence: original MIPS .pdata 40404924..40404a1f. Semantic name remains unreviewed. */

HRESULT CreateStreamOnHGlobal(HGLOBAL hGlobal,BOOL fDeleteOnRelease,LPSTREAM *ppstm)

{
  BOOL BVar1;
  SIZE_T *hMem;
  LPSTREAM pIVar2;
  SIZE_T SVar3;
  
                    /* 0x4924  18  CreateStreamOnHGlobal */
  if ((ppstm != (LPSTREAM *)0x0) && (BVar1 = IsBadReadPtr(ppstm,4), BVar1 != 0)) {
    return -0x7ff8ffa9;
  }
  *ppstm = (LPSTREAM)0x0;
  if (hGlobal == (HGLOBAL)0x0) {
    hGlobal = LocalAlloc(2,0);
    if (hGlobal == (HLOCAL)0x0) {
      return -0x7ff8fff2;
    }
    SVar3 = 0;
  }
  else {
    SVar3 = LocalSize(hGlobal);
  }
  hMem = LocalAlloc(2,0x14);
  if (hMem != (SIZE_T *)0x0) {
    hMem[1] = 0;
    *hMem = SVar3;
    hMem[4] = fDeleteOnRelease;
    hMem[3] = (SIZE_T)hGlobal;
    pIVar2 = (LPSTREAM)FUN_404048a4((int)hMem);
    if (pIVar2 != (LPSTREAM)0x0) {
      *ppstm = pIVar2;
      return 0;
    }
    LocalFree(hMem);
  }
  return -0x7ff8fff2;
}



/* 40404a20 FUN_40404a20 */

/* Boundary evidence: original MIPS .pdata 40404a20..40404a9b. Semantic name remains unreviewed. */

undefined4 FUN_40404a20(int param_1,undefined4 *param_2)

{
  BOOL BVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  
  BVar1 = IsBadWritePtr(param_2,4);
  if (BVar1 == 0) {
    puVar3 = FUN_404048a4(*(int *)(param_1 + 0x10));
    *param_2 = puVar3;
    if (puVar3 == (undefined4 *)0x0) {
      uVar2 = 0x8007000e;
    }
    else {
      puVar3[3] = *(undefined4 *)(param_1 + 0xc);
      uVar2 = 0;
    }
  }
  else {
    uVar2 = 0x80070057;
  }
  return uVar2;
}



/* 40404a9c FUN_40404a9c */

/* Boundary evidence: original MIPS .pdata 40404a9c..40404b33. Semantic name remains unreviewed. */

wchar_t * FUN_40404a9c(wchar_t *param_1)

{
  wchar_t wVar1;
  size_t sVar2;
  wchar_t *pwVar3;
  
  if (param_1 != (wchar_t *)0x0) {
    sVar2 = wcslen(param_1);
    pwVar3 = param_1 + (sVar2 - 1);
    wVar1 = *pwVar3;
    while ((((wVar1 != L'.' && (wVar1 != L'\\')) && (wVar1 != L'/')) && (param_1 < pwVar3))) {
      pwVar3 = pwVar3 + -1;
      wVar1 = *pwVar3;
    }
    if (*pwVar3 == L'.') {
      return pwVar3;
    }
  }
  return (wchar_t *)0x0;
}



/* 40404b34 FUN_40404b34 */

/* Boundary evidence: original MIPS .pdata 40404b34..40404d43. Semantic name remains unreviewed. */

int FUN_40404b34(wchar_t *param_1,LPCLSID param_2,ulong *param_3)

{
  BOOL BVar1;
  HANDLE hObject;
  uint uVar2;
  wchar_t *pwVar3;
  int iVar4;
  ulong uVar5;
  int iVar6;
  
  if (((param_1 == (wchar_t *)0x0) || (BVar1 = IsBadReadPtr(param_1,2), BVar1 == 0)) &&
     (BVar1 = IsBadWritePtr(param_2,0x10), BVar1 == 0)) {
    if ((param_1 == (wchar_t *)0x0) ||
       (hObject = CreateFileW(param_1,0x80000000,3,(LPSECURITY_ATTRIBUTES)0x0,3,0,(HANDLE)0x0),
       hObject == (HANDLE)0xffffffff)) {
      iVar6 = -0x7ffbfe16;
    }
    else {
      uVar2 = FUN_404055ec(hObject,param_2);
      if ((uVar2 != 0) ||
         (((iVar6 = 0, param_2->Data1 == 0 &&
           (iVar4._0_2_ = param_2->Data2, iVar4._2_2_ = param_2->Data3, iVar4 == 0)) &&
          ((*(int *)param_2->Data4 == 0 && (*(int *)(param_2->Data4 + 4) == 0)))))) {
        if ((((*param_3 == 0) && (param_3[1] == 0)) && (param_3[2] == 0)) && (param_3[3] == 0)) {
          iVar6 = 0;
          pwVar3 = FUN_40404a9c(param_1);
          if ((pwVar3 == (wchar_t *)0x0) || (iVar4 = FUN_40406aac(pwVar3,param_2), iVar4 != 0)) {
            iVar6 = -0x7ffbfe1a;
          }
        }
        else {
          iVar6 = 0;
          param_2->Data1 = *param_3;
          uVar5 = param_3[1];
          param_2->Data2 = (short)uVar5;
          param_2->Data3 = (short)(uVar5 >> 0x10);
          *(ulong *)param_2->Data4 = param_3[2];
          *(ulong *)(param_2->Data4 + 4) = param_3[3];
        }
      }
      CloseHandle(hObject);
      if (iVar6 == 0) {
        return 0;
      }
    }
    param_2->Data1 = 0;
    param_2->Data2 = 0;
    param_2->Data3 = 0;
    param_2->Data4[0] = '\0';
    param_2->Data4[1] = '\0';
    param_2->Data4[2] = '\0';
    param_2->Data4[3] = '\0';
    param_2->Data4[4] = '\0';
    param_2->Data4[5] = '\0';
    param_2->Data4[6] = '\0';
    param_2->Data4[7] = '\0';
  }
  else {
    iVar6 = -0x7ff8ffa9;
  }
  return iVar6;
}



/* 40404d44 GetClassFile */

/* Boundary evidence: original MIPS .pdata 40404d44..40404d63. Semantic name remains unreviewed. */

HRESULT GetClassFile(LPCOLESTR szFilename,CLSID *pclsid)

{
  int iVar1;
  
                    /* 0x4d44  19  GetClassFile */
  iVar1 = FUN_40404b34(szFilename,pclsid,&DAT_404021a4);
  return iVar1;
}



/* 40404d64 FUN_40404d64 */

/* Boundary evidence: original MIPS .pdata 40404d64..40404f3f. Semantic name remains unreviewed. */

HRESULT FUN_40404d64(ulong param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                    IID *param_5,int param_6,LPSTORAGE param_7,short param_8,LPVOID *param_9)

{
  HRESULT HVar1;
  code *pcVar2;
  int *local_38 [2];
  IID local_30;
  uint local_20;
  
  local_20 = DAT_404303e4;
  *param_9 = (LPVOID)0x0;
  local_30.Data1 = param_1;
  local_30._4_4_ = param_2;
  local_30.Data4._0_4_ = param_3;
  local_30.Data4._4_4_ = param_4;
  HVar1 = CoCreateInstance(&local_30,(LPUNKNOWN)0x0,3,param_5,param_9);
  if (HVar1 != 0) goto LAB_40404ef0;
  if (param_8 != 1) {
    HVar1 = (*(code *)**(undefined4 **)*param_9)(*param_9,&UNK_40402214,local_38);
    if (HVar1 != 0) goto LAB_40404ef0;
    if (param_8 == 2) {
      HVar1 = WriteClassStg(param_7,&local_30);
      if (-1 < HVar1) {
        pcVar2 = *(code **)(*local_38[0] + 0x14);
        goto LAB_40404e50;
      }
    }
    else {
      pcVar2 = *(code **)(*local_38[0] + 0x18);
LAB_40404e50:
      HVar1 = (*pcVar2)(local_38[0],param_7);
    }
    (**(code **)(*local_38[0] + 8))();
    if (HVar1 < 0) goto LAB_40404ef0;
  }
  if (param_6 != 0) {
    local_38[0] = (int *)0x0;
    HVar1 = (*(code *)**(undefined4 **)*param_9)(*param_9,&UNK_40402204,local_38);
    if (HVar1 == 0) {
      HVar1 = (**(code **)(*local_38[0] + 0xc))(local_38[0],param_6);
      (**(code **)(*local_38[0] + 8))();
      if (-1 < HVar1) goto LAB_40404ee0;
    }
LAB_40404ef0:
    if (*param_9 != (int *)0x0) {
      (**(code **)(*(int *)*param_9 + 8))();
      *param_9 = (LPVOID)0x0;
    }
    FUN_4042f4c4(local_20);
    return HVar1;
  }
LAB_40404ee0:
  FUN_4042f4c4(local_20);
  return 0;
}



/* 40404f40 OleCreate */

/* Boundary evidence: original MIPS .pdata 40404f40..40405007. Semantic name remains unreviewed. */

HRESULT OleCreate(IID *rclsid,IID *riid,DWORD renderopt,LPFORMATETC pFormatEtc,
                 LPOLECLIENTSITE pClientSite,LPSTORAGE pStg,LPVOID *ppvObj)

{
  HRESULT HVar1;
  undefined4 uVar2;
  
                    /* 0x4f40  21  OleCreate */
  uVar2._0_2_ = rclsid->Data2;
  uVar2._2_2_ = rclsid->Data3;
  HVar1 = FUN_40404d64(rclsid->Data1,uVar2,*(undefined4 *)rclsid->Data4,
                       *(undefined4 *)(rclsid->Data4 + 4),riid,(int)pClientSite,pStg,2,ppvObj);
  if (((HVar1 != 0) ||
      (((renderopt != 0 && (renderopt != 3)) && (HVar1 = OleRun(*ppvObj), HVar1 != 0)))) &&
     (*ppvObj != (int *)0x0)) {
    (**(code **)(*(int *)*ppvObj + 8))();
    *ppvObj = (LPVOID)0x0;
  }
  return HVar1;
}



/* 40405008 ReadClassStg */

/* Boundary evidence: original MIPS .pdata 40405008..404050c3. Semantic name remains unreviewed. */

HRESULT ReadClassStg(LPSTORAGE pStg,CLSID *pclsid)

{
  HRESULT HVar1;
  STATSTG SStack_60;
  uint local_18;
  
                    /* 0x5008  29  ReadClassStg */
  local_18 = DAT_404303e4;
  HVar1 = (*pStg->lpVtbl->Stat)(pStg,&SStack_60,1);
  if (HVar1 < 0) {
    pclsid->Data1 = 0;
    pclsid->Data2 = 0;
    pclsid->Data3 = 0;
    pclsid->Data4[0] = '\0';
    pclsid->Data4[1] = '\0';
    pclsid->Data4[2] = '\0';
    pclsid->Data4[3] = '\0';
    pclsid->Data4[4] = '\0';
    pclsid->Data4[5] = '\0';
    pclsid->Data4[6] = '\0';
    pclsid->Data4[7] = '\0';
    FUN_4042f4c4(local_18);
  }
  else {
    pclsid->Data1 = SStack_60.clsid.Data1;
    pclsid->Data2 = SStack_60.clsid.Data2;
    pclsid->Data3 = SStack_60.clsid.Data3;
    *(undefined4 *)pclsid->Data4 = SStack_60.clsid.Data4._0_4_;
    *(undefined4 *)(pclsid->Data4 + 4) = SStack_60.clsid.Data4._4_4_;
    FUN_4042f4c4(local_18);
    HVar1 = 0;
  }
  return HVar1;
}



/* 404050c4 WriteClassStg */

/* Boundary evidence: original MIPS .pdata 404050c4..404050e7. Semantic name remains unreviewed. */

HRESULT WriteClassStg(LPSTORAGE pStg,IID *rclsid)

{
  HRESULT HVar1;
  
                    /* 0x50c4  39  WriteClassStg */
  HVar1 = (*pStg->lpVtbl->SetClass)(pStg,rclsid);
  return HVar1;
}



/* 404050e8 ReadClassStm */

/* Boundary evidence: original MIPS .pdata 404050e8..40405177. Semantic name remains unreviewed. */

HRESULT ReadClassStm(LPSTREAM pStm,CLSID *pclsid)

{
  HRESULT HVar1;
  ULONG local_18 [2];
  
                    /* 0x50e8  30  ReadClassStm */
  HVar1 = (*pStm->lpVtbl->Read)(pStm,pclsid,0x10,local_18);
  if ((HVar1 != 0) || (local_18[0] != 0x10)) {
    if (-1 < HVar1) {
      HVar1 = -0x7ffcffe2;
    }
    pclsid->Data1 = 0;
    pclsid->Data2 = 0;
    pclsid->Data3 = 0;
    pclsid->Data4[0] = '\0';
    pclsid->Data4[1] = '\0';
    pclsid->Data4[2] = '\0';
    pclsid->Data4[3] = '\0';
    pclsid->Data4[4] = '\0';
    pclsid->Data4[5] = '\0';
    pclsid->Data4[6] = '\0';
    pclsid->Data4[7] = '\0';
  }
  return HVar1;
}



/* 40405178 WriteClassStm */

/* Boundary evidence: original MIPS .pdata 40405178..4040519f. Semantic name remains unreviewed. */

HRESULT WriteClassStm(LPSTREAM pStm,IID *rclsid)

{
  HRESULT HVar1;
  
                    /* 0x5178  40  WriteClassStm */
  HVar1 = (*pStm->lpVtbl->Write)(pStm,rclsid,0x10,(ULONG *)0x0);
  return HVar1;
}



/* 404051a0 ReleaseStgMedium */

/* Boundary evidence: original MIPS .pdata 404051a0..404052d3. Semantic name remains unreviewed. */

void ReleaseStgMedium(LPSTGMEDIUM param_1)

{
  bool bVar1;
  IUnknown *This;
  DWORD DVar2;
  
                    /* 0x51a0  31  ReleaseStgMedium */
  if (param_1 != (LPSTGMEDIUM)0x0) {
    bVar1 = param_1->pUnkForRelease == (IUnknown *)0x0;
    DVar2 = param_1->tymed;
    if (DVar2 == 1) {
      if (((param_1->u).hMetaFilePict != (HLOCAL)0x0) && (bVar1)) {
        LocalFree((param_1->u).hMetaFilePict);
      }
    }
    else if (DVar2 == 2) {
      if ((param_1->u).lpszFileName != (LPCWSTR)0x0) {
        if (bVar1) {
          DeleteFileW((param_1->u).lpszFileName);
        }
        CoTaskMemFree((param_1->u).hMetaFilePict);
        (param_1->u).hBitmap = (HBITMAP)0x0;
      }
    }
    else if ((DVar2 == 4) || (DVar2 == 8)) {
      if ((param_1->u).hBitmap != (HBITMAP)0x0) {
        (**(code **)(((param_1->u).hBitmap)->unused + 8))();
      }
    }
    else if (((DVar2 == 0x10) && ((param_1->u).hMetaFilePict != (HGDIOBJ)0x0)) && (bVar1)) {
      DeleteObject((param_1->u).hMetaFilePict);
    }
    This = param_1->pUnkForRelease;
    if (This != (IUnknown *)0x0) {
      (*This->lpVtbl->Release)(This);
      param_1->pUnkForRelease = (IUnknown *)0x0;
    }
    param_1->tymed = 0;
  }
  return;
}



/* 404052d4 OleIsRunning */

/* Boundary evidence: original MIPS .pdata 404052d4..40405343. Semantic name remains unreviewed. */

BOOL OleIsRunning(LPOLEOBJECT pObject)

{
  HRESULT HVar1;
  BOOL BVar2;
  int *local_10 [2];
  
                    /* 0x52d4  23  OleIsRunning */
  HVar1 = (*pObject->lpVtbl->QueryInterface)(pObject,(IID *)&UNK_40402224,local_10);
  if (HVar1 == 0) {
    BVar2 = (**(code **)(*local_10[0] + 0x14))();
    (**(code **)(*local_10[0] + 8))();
  }
  else {
    BVar2 = 1;
  }
  return BVar2;
}



/* 40405344 OleRun */

/* Boundary evidence: original MIPS .pdata 40405344..404053b3. Semantic name remains unreviewed. */

HRESULT OleRun(LPUNKNOWN pUnknown)

{
  HRESULT HVar1;
  int *local_10 [2];
  
                    /* 0x5344  24  OleRun */
  HVar1 = (*pUnknown->lpVtbl->QueryInterface)(pUnknown,(IID *)&UNK_40402224,local_10);
  if (HVar1 == 0) {
    HVar1 = (**(code **)(*local_10[0] + 0x10))(local_10[0],0);
    (**(code **)(*local_10[0] + 8))();
  }
  else {
    HVar1 = 0;
  }
  return HVar1;
}



/* 404053b4 OleSetContainedObject */

/* Boundary evidence: original MIPS .pdata 404053b4..40405427. Semantic name remains unreviewed. */

HRESULT OleSetContainedObject(LPUNKNOWN pUnknown,BOOL fContained)

{
  HRESULT HVar1;
  int *local_10 [2];
  
                    /* 0x53b4  26  OleSetContainedObject */
  HVar1 = (*pUnknown->lpVtbl->QueryInterface)(pUnknown,(IID *)&UNK_40402224,local_10);
  if (HVar1 == 0) {
    HVar1 = (**(code **)(*local_10[0] + 0x1c))(local_10[0],fContained);
    (**(code **)(*local_10[0] + 8))();
  }
  else {
    HVar1 = 0;
  }
  return HVar1;
}



/* 40405428 OleDraw */

/* Boundary evidence: original MIPS .pdata 40405428..404054db. Semantic name remains unreviewed. */

HRESULT OleDraw(LPUNKNOWN pUnknown,DWORD dwAspect,HDC hdcDraw,LPCRECT lprcBounds)

{
  HRESULT HVar1;
  int *local_18 [2];
  
                    /* 0x5428  22  OleDraw */
  HVar1 = (*pUnknown->lpVtbl->QueryInterface)(pUnknown,(IID *)&UNK_40402234,local_18);
  if (HVar1 == 0) {
    HVar1 = (**(code **)(*local_18[0] + 0xc))
                      (local_18[0],dwAspect,0xffffffff,0,0,0,hdcDraw,lprcBounds,0,0,0);
    (**(code **)(*local_18[0] + 8))();
  }
  else {
    HVar1 = -0x7ffbff93;
  }
  return HVar1;
}



/* 404054dc OleSave */

/* Boundary evidence: original MIPS .pdata 404054dc..404055af. Semantic name remains unreviewed. */

HRESULT OleSave(LPPERSISTSTORAGE pPS,LPSTORAGE pStg,BOOL fSameAsLoad)

{
  HRESULT HVar1;
  CLSID CStack_30;
  uint local_20;
  
                    /* 0x54dc  25  OleSave */
  local_20 = DAT_404303e4;
  HVar1 = (*pPS->lpVtbl->GetClassID)(pPS,&CStack_30);
  if (((HVar1 == 0) && (HVar1 = (*pStg->lpVtbl->SetClass)(pStg,&CStack_30), HVar1 == 0)) &&
     (HVar1 = (*pPS->lpVtbl->Save)(pPS,pStg,fSameAsLoad), HVar1 == 0)) {
    HVar1 = (*pStg->lpVtbl->Commit)(pStg,0);
  }
  FUN_4042f4c4(local_20);
  return HVar1;
}



/* 404055b0 FUN_404055b0 */

/* Boundary evidence: original MIPS .pdata 404055b0..404055e3. Semantic name remains unreviewed. */

void * FUN_404055b0(int param_1,void *param_2)

{
  memcpy(param_2,(void *)(param_1 + 0x50),0x10);
  return param_2;
}



/* 404055e4 FUN_404055e4 */

undefined4 FUN_404055e4(int param_1)

{
  return *(undefined4 *)(param_1 + 0x30);
}



/* 404055ec FUN_404055ec */

/* Boundary evidence: original MIPS .pdata 404055ec..4040585f. Semantic name remains unreviewed. */

uint FUN_404055ec(HANDLE param_1,void *param_2)

{
  DWORD DVar1;
  BOOL BVar2;
  uint uVar3;
  undefined4 *puVar4;
  int *piVar5;
  DWORD local_230;
  int *local_22c;
  uint local_228;
  uint local_224;
  undefined1 auStack_220 [80];
  undefined1 auStack_1d0 [436];
  uint local_1c;
  
  local_1c = DAT_404303e4;
  DVar1 = SetFilePointer(param_1,0,(PLONG)0x0,0);
  if (DVar1 == 0) {
    BVar2 = ReadFile(param_1,auStack_220,0x200,&local_230,(LPOVERLAPPED)0x0);
    if (BVar2 != 0) {
      if (local_230 == 0x200) {
        uVar3 = FUN_4040c940(auStack_220);
        if (-1 < (int)uVar3) {
          FUN_4040a704();
          uVar3 = (*(code *)PTR_FUN_40430320)(&local_22c);
          if (-1 < (int)uVar3) {
            puVar4 = (undefined4 *)FUN_4040a638(0x4c);
            if (puVar4 == (undefined4 *)0x0) {
              piVar5 = (int *)0x0;
            }
            else {
              piVar5 = FUN_4040c6e4(puVar4,local_22c);
            }
            if (piVar5 == (int *)0x0) {
              uVar3 = 0x80030008;
            }
            else {
              uVar3 = FUN_4040a864();
              if ((-1 < (int)uVar3) &&
                 (uVar3 = FUN_4040c3b8(piVar5,0x40,1,(int *)&local_224), -1 < (int)uVar3)) {
                uVar3 = FUN_4040ba60(piVar5,0x40,(int *)&local_228);
                if (-1 < (int)uVar3) {
                  uVar3 = (**(code **)(*piVar5 + 0xc))(piVar5);
                  if (-1 < (int)uVar3) {
                    if (local_230 == 0x80) {
                      uVar3 = 0;
                    }
                    else {
                      uVar3 = 0x8003001e;
                    }
                    memcpy(param_2,auStack_1d0,0x10);
                  }
                  FUN_4040baa4(piVar5,0x40,local_228);
                }
                FUN_4040c3fc(piVar5,0x40,local_224);
              }
              (**(code **)(*piVar5 + 8))(piVar5);
            }
            (**(code **)(*local_22c + 8))();
          }
        }
      }
      else {
        uVar3 = 0x800300fb;
      }
      goto LAB_40405838;
    }
  }
  DVar1 = GetLastError();
  uVar3 = FUN_4040cfd8(DVar1);
LAB_40405838:
  FUN_4042f4c4(local_1c);
  return uVar3;
}



/* 40405860 FUN_40405860 */

/* Boundary evidence: original MIPS .pdata 40405860..404058cb. Semantic name remains unreviewed. */

void FUN_40405860(LPVOID param_1)

{
  int iVar1;
  
  iVar1 = *(int *)((int)param_1 + 0x1c) + -1;
  *(int *)((int)param_1 + 0x1c) = iVar1;
  if (iVar1 == 0) {
    FUN_4040b85c((int)param_1);
    FUN_4040a65c(param_1);
  }
  else {
    iVar1 = __GetUserKData(8);
    if (DAT_40430480 == iVar1) {
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_4043047c);
    }
  }
  return;
}



/* 404058cc FUN_404058cc */

/* Boundary evidence: original MIPS .pdata 404058cc..404059c3. Semantic name remains unreviewed. */

undefined4 FUN_404058cc(undefined4 *param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int iVar3;
  wchar_t awStack_60 [32];
  uint local_20;
  
  local_20 = DAT_404303e4;
  puVar1 = (undefined4 *)FUN_4040a638(0x18);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    uVar2 = param_1[8];
    *puVar1 = 0;
    puVar1[1] = 1;
    puVar1[4] = uVar2;
    puVar1[2] = param_2;
    puVar1[3] = param_3;
    uVar2 = FUN_4040b7a8();
    puVar1[5] = uVar2;
  }
  if (puVar1 == (undefined4 *)0x0) {
    uVar2 = 0x80030008;
  }
  else {
    iVar3 = (int)puVar1 - DAT_404304bc;
    param_1[6] = iVar3;
    StringCchPrintfW(awStack_60,0x20,L"OleDfRoot%08lX",*(undefined4 *)(iVar3 + DAT_404304bc + 0x14))
    ;
    uVar2 = 0;
    FUN_4040d47c((int *)(param_1[6] + DAT_404304bc),param_1);
  }
  FUN_4042f4c4(local_20);
  return uVar2;
}



/* 404059c4 FUN_404059c4 */

/* Boundary evidence: original MIPS .pdata 404059c4..40405c87. Semantic name remains unreviewed. */

uint FUN_404059c4(undefined4 param_1,int *param_2,uint param_3,uint param_4,undefined4 *param_5,
                 undefined4 *param_6)

{
  undefined4 *puVar1;
  int *piVar2;
  uint uVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  int iVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  uint uVar9;
  int local_30;
  uint local_2c;
  
  puVar1 = (undefined4 *)FUN_4040a638(0x90);
  if (puVar1 == (undefined4 *)0x0) {
    piVar2 = (int *)0x0;
  }
  else {
    piVar2 = FUN_40410458(puVar1,param_1);
  }
  if (piVar2 == (int *)0x0) {
    uVar9 = 0x80030008;
  }
  else {
    uVar3 = FUN_404104d8((int)piVar2,param_2,param_4,param_3,param_5,&local_30,&local_2c);
    uVar9 = uVar3;
    if (-1 < (int)uVar3) {
      puVar1 = (undefined4 *)FUN_4040a638(0x28);
      if (puVar1 == (undefined4 *)0x0) {
        puVar1 = (undefined4 *)0x0;
      }
      else {
        uVar8 = *(undefined4 *)(local_30 + 0x14);
        uVar7 = *(undefined4 *)(local_30 + 0x10);
        uVar5 = *(undefined4 *)(local_30 + 0xc);
        puVar1[8] = param_1;
        puVar1[2] = uVar5;
        puVar1[3] = uVar7;
        puVar1[4] = uVar8;
        puVar1[5] = local_2c;
        puVar1[7] = 1;
        puVar1[6] = 0;
      }
      if (puVar1 == (undefined4 *)0x0) {
        uVar9 = 0x80030008;
      }
      else {
        uVar9 = FUN_404058cc(puVar1,(uint)(local_2c != 0),param_3);
        if (-1 < (int)uVar9) {
          puVar4 = (undefined4 *)FUN_4040a638(0x20);
          if (puVar4 == (undefined4 *)0x0) {
            puVar4 = (undefined4 *)0x0;
          }
          else {
            puVar4 = FUN_40410e20(puVar4,(int)piVar2,local_30,puVar1,1);
          }
          *param_6 = puVar4;
          if (puVar4 != (undefined4 *)0x0) {
            return uVar3;
          }
          uVar9 = 0x80030008;
        }
        (**(code **)(**(int **)(local_30 + 0x14) + 4))();
        (**(code **)(**(int **)(local_30 + 0xc) + 4))();
        (**(code **)(**(int **)(local_30 + 0x10) + 4))();
        if (local_2c != 0) {
          if (puVar1[6] == 0) {
            iVar6 = 0;
          }
          else {
            iVar6 = puVar1[6] + DAT_404304bc;
          }
          if (iVar6 == 0) {
            FUN_4040c3fc(*(int **)(local_30 + 0x14),param_3,local_2c);
          }
        }
        FUN_40405860(puVar1);
        local_2c = 0;
      }
      (**(code **)(**(int **)(local_30 + 0x10) + 8))();
      (**(code **)(**(int **)(local_30 + 0xc) + 8))();
      if (local_2c != 0) {
        FUN_4040c3fc(*(int **)(local_30 + 0x14),param_3,local_2c);
      }
      *(undefined4 *)(local_30 + 0x10) = 0;
      *(undefined4 *)(local_30 + 0xc) = 0;
    }
    FUN_4040fa14((int)piVar2,param_2);
    FUN_4040e010(piVar2);
  }
  return uVar9;
}



/* 40405c88 FUN_40405c88 */

/* Boundary evidence: original MIPS .pdata 40405c88..40405e77. Semantic name remains unreviewed. */

uint FUN_40405c88(wchar_t *param_1,uint param_2,uint param_3,undefined4 *param_4,undefined4 *param_5
                 )

{
  bool bVar1;
  uint uVar2;
  undefined4 *puVar3;
  int *piVar4;
  int *local_28 [2];
  
  uVar2 = (*(code *)PTR_FUN_40430320)(local_28);
  if ((int)uVar2 < 0) {
    return uVar2;
  }
  puVar3 = (undefined4 *)FUN_4040a638(0x4c);
  if (puVar3 == (undefined4 *)0x0) {
    piVar4 = (int *)0x0;
  }
  else {
    piVar4 = FUN_4040c6e4(puVar3,local_28[0]);
  }
  if (piVar4 == (int *)0x0) {
    uVar2 = 0x80030008;
    goto LAB_40405e38;
  }
  uVar2 = FUN_4040c740((int)piVar4,param_3 & 0xfffffffc,param_2);
  if (-1 < (int)uVar2) {
    bVar1 = true;
    uVar2 = FUN_4040ac8c((int)piVar4,param_1,1);
    if (((int)uVar2 < 0) || (((param_3 & 4) == 0 && (param_1 != (wchar_t *)0x0)))) {
      bVar1 = false;
    }
    if (uVar2 == 0x80030050) {
      if ((param_3 & 3) == 0) goto LAB_40405e28;
      *(uint *)(piVar4[4] + DAT_404304bc + 0x218) = param_3 & 0xfffffff8;
      uVar2 = FUN_4040ac8c((int)piVar4,param_1,1);
    }
    if (-1 < (int)uVar2) {
      uVar2 = FUN_404059c4(local_28[0],piVar4,param_2,param_3,param_4,param_5);
      if (-1 < (int)uVar2) goto LAB_40405e38;
      if ((bVar1) || (((param_3 & 4) != 0 && ((param_2 & 2) == 0)))) {
        FUN_4040b190((int)piVar4);
      }
    }
  }
LAB_40405e28:
  (**(code **)(*piVar4 + 8))(piVar4);
LAB_40405e38:
  (**(code **)(*local_28[0] + 8))();
  return uVar2;
}



/* 40405e78 FUN_40405e78 */

/* Boundary evidence: original MIPS .pdata 40405e78..40406063. Semantic name remains unreviewed. */

uint FUN_40405e78(wchar_t *param_1,undefined4 param_2,uint param_3,int param_4,undefined4 *param_5)

{
  BOOL BVar1;
  uint uVar2;
  uint uVar3;
  int *piVar4;
  uint uVar5;
  int *local_28 [2];
  
  local_28[0] = (int *)0x0;
  if ((param_5 == (undefined4 *)0x0) || (BVar1 = IsBadReadPtr(param_5,4), BVar1 != 0)) {
    uVar3 = 0x80030009;
  }
  else {
    *param_5 = 0;
    uVar5 = 2;
    if ((param_1 == (wchar_t *)0x0) || (BVar1 = IsBadReadPtr(param_1,2), BVar1 == 0)) {
      if (param_4 == 0) {
        if ((param_3 & 0x8000000) == 0) {
          uVar3 = FUN_4040cc70(param_3);
          if (-1 < (int)uVar3) {
            if (((param_3 & 3) == 0) || ((param_3 & 0x4020000) == 0x4020000)) {
              uVar3 = 0x800300ff;
              piVar4 = (int *)0x0;
            }
            else {
              uVar3 = FUN_4040caa8(param_3);
              if ((param_3 & 0x30000) == 0x30000) {
                uVar3 = uVar3 | 4;
              }
              FUN_4040a704();
              if ((param_3 & 0x1000) == 0) {
                uVar5 = 0;
              }
              uVar2 = 0x10;
              if ((param_3 & 0x4000000) == 0) {
                uVar2 = 0;
              }
              uVar3 = FUN_40405c88(param_1,uVar3,uVar2 | (param_3 & 0x20000) != 0 | uVar5 | 4,
                                   (undefined4 *)0x0,local_28);
              piVar4 = local_28[0];
              if (-1 < (int)uVar3) {
                *param_5 = local_28[0];
                return uVar3;
              }
            }
            if (piVar4 != (int *)0x0) {
              (**(code **)(*piVar4 + 8))(piVar4);
            }
          }
        }
        else {
          uVar3 = 0x800300ff;
        }
      }
      else {
        uVar3 = 0x80030057;
      }
    }
    else {
      uVar3 = 0x800300fc;
    }
  }
  return uVar3;
}



/* 40406064 StgCreateDocfile */

/* Boundary evidence: original MIPS .pdata 40406064..4040608b. Semantic name remains unreviewed. */

HRESULT StgCreateDocfile(WCHAR *pwcsName,DWORD grfMode,DWORD reserved,IStorage **ppstgOpen)

{
  uint uVar1;
  
                    /* 0x6064  32  StgCreateDocfile */
  uVar1 = FUN_40405e78(pwcsName,0,grfMode,reserved,ppstgOpen);
  return uVar1;
}



/* 4040608c StgCreateDocfileOnILockBytes */

/* Boundary evidence: original MIPS .pdata 4040608c..404062a3. Semantic name remains unreviewed. */

HRESULT StgCreateDocfileOnILockBytes
                  (ILockBytes *plkbyt,DWORD grfMode,DWORD reserved,IStorage **ppstgOpen)

{
  BOOL BVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  IStorage *This;
  IStorage *local_28;
  int *local_24;
  
                    /* 0x608c  33  StgCreateDocfileOnILockBytes */
  local_28 = (IStorage *)0x0;
  if ((ppstgOpen != (IStorage **)0x0) && (BVar1 = IsBadReadPtr(ppstgOpen,4), BVar1 == 0)) {
    *ppstgOpen = (IStorage *)0x0;
    iVar2 = FUN_40409b68();
    if (iVar2 != 0) {
      if (reserved != 0) {
        return -0x7ffcffa9;
      }
      if ((grfMode & 0x21000) == 0) {
        return -0x7ffcffb0;
      }
      iVar2 = FUN_4040cc70(grfMode);
      if (iVar2 < 0) {
        return iVar2;
      }
      if ((grfMode & 0x4000000) != 0) {
        return -0x7ffcffff;
      }
      uVar3 = FUN_4040caa8(grfMode);
      if ((grfMode & 0x30000) == 0x30000) {
        uVar3 = uVar3 | 4;
      }
      FUN_4040a704();
      iVar2 = (*(code *)PTR_FUN_40430320)(&local_24);
      if (iVar2 < 0) {
        return iVar2;
      }
      uVar4 = 2;
      if ((grfMode & 0x1000) == 0) {
        uVar4 = 0;
      }
      uVar3 = FUN_404059c4(local_24,(int *)plkbyt,uVar3,(grfMode & 0x20000) != 0 | uVar4 | 4,
                           (undefined4 *)0x0,&local_28);
      (**(code **)(*local_24 + 8))();
      if ((int)uVar3 < 0) {
        This = local_28;
        if (((grfMode & 0x1000) != 0) && ((grfMode & 0x10000) == 0)) {
          (*plkbyt->lpVtbl->SetSize)(plkbyt,(ULARGE_INTEGER)0x0);
          This = local_28;
        }
      }
      else {
        *ppstgOpen = local_28;
        (*plkbyt->lpVtbl->AddRef)(plkbyt);
        This = (IStorage *)0x0;
      }
      if (This == (IStorage *)0x0) {
        return uVar3;
      }
      (*This->lpVtbl->Release)(This);
      return uVar3;
    }
  }
  return -0x7ffcfff7;
}



/* 404062a4 FUN_404062a4 */

/* Boundary evidence: original MIPS .pdata 404062a4..4040650f. Semantic name remains unreviewed. */

uint FUN_404062a4(wchar_t *param_1,undefined4 param_2,int *param_3,uint param_4,undefined4 *param_5,
                 int param_6,int *param_7)

{
  BOOL BVar1;
  int iVar2;
  int *piVar3;
  uint uVar4;
  int *local_280 [2];
  wchar_t *local_278 [18];
  wchar_t awStack_230 [259];
  undefined2 local_2a;
  uint local_28;
  
  local_28 = DAT_404303e4;
  local_280[0] = (int *)0x0;
  if ((param_7 == (int *)0x0) || (BVar1 = IsBadReadPtr(param_7,4), BVar1 != 0)) {
LAB_404064d4:
    uVar4 = 0x80030009;
  }
  else {
    *param_7 = 0;
    if (param_3 == (int *)0x0) {
      BVar1 = IsBadReadPtr(param_1,2);
      if (BVar1 != 0) {
        uVar4 = 0x800300fc;
        goto LAB_404064dc;
      }
      wcsncpy(awStack_230,param_1,0x104);
      local_2a = 0;
    }
    else {
      iVar2 = FUN_40409b68();
      if (iVar2 == 0) goto LAB_404064d4;
      uVar4 = (**(code **)(*param_3 + 0x44))(param_3,local_278,0);
      if ((int)uVar4 < 0) goto LAB_404064dc;
      wcscpy(awStack_230,local_278[0]);
      CoTaskMemFree(local_278[0]);
    }
    uVar4 = FUN_4040cc70(param_4);
    if (-1 < (int)uVar4) {
      if ((param_4 & 0x21000) == 0) {
        if (param_5 != (undefined4 *)0x0) {
          if ((param_4 & 3) != 2) {
            uVar4 = 0x80030005;
            goto LAB_404064dc;
          }
          uVar4 = FUN_4040ce80(param_5);
          if ((int)uVar4 < 0) goto LAB_404064dc;
        }
        if (param_6 == 0) {
          if ((param_4 & 0x4000000) == 0) {
            if ((param_3 == (int *)0x0) ||
               (uVar4 = (**(code **)(*param_3 + 8))(param_3), -1 < (int)uVar4)) {
              FUN_4040a704();
              uVar4 = FUN_4040caa8(param_4);
              uVar4 = FUN_40405c88(awStack_230,uVar4,0,param_5,local_280);
              piVar3 = local_280[0];
              if (-1 < (int)uVar4) {
                *param_7 = (int)local_280[0];
                piVar3 = (int *)0x0;
              }
              if (piVar3 != (int *)0x0) {
                (**(code **)(*piVar3 + 8))();
              }
            }
          }
          else {
            uVar4 = 0x80030001;
          }
        }
        else {
          uVar4 = 0x80030057;
        }
      }
      else {
        uVar4 = 0x800300ff;
      }
    }
  }
LAB_404064dc:
  FUN_4042f4c4(local_28);
  return uVar4;
}



/* 40406510 FUN_40406510 */

/* Boundary evidence: original MIPS .pdata 40406510..4040673f. Semantic name remains unreviewed. */

uint FUN_40406510(int *param_1,int *param_2,uint param_3,undefined4 *param_4,int param_5,
                 undefined4 *param_6)

{
  BOOL BVar1;
  int iVar2;
  uint uVar3;
  int *piVar4;
  int *local_28;
  int *local_24;
  
  local_28 = (int *)0x0;
  if ((param_6 != (undefined4 *)0x0) && (BVar1 = IsBadReadPtr(param_6,4), BVar1 == 0)) {
    *param_6 = 0;
    iVar2 = FUN_40409b68();
    if ((iVar2 != 0) && ((param_2 == (int *)0x0 || (iVar2 = FUN_40409b68(), iVar2 != 0)))) {
      uVar3 = FUN_4040cc70(param_3);
      if ((int)uVar3 < 0) {
        return uVar3;
      }
      if ((param_3 & 0x21000) != 0) {
        return 0x800300ff;
      }
      if ((param_3 & 0x4000000) != 0) {
        return 0x80030001;
      }
      if (param_4 != (undefined4 *)0x0) {
        if ((param_3 & 3) != 2) {
          return 0x80030005;
        }
        uVar3 = FUN_4040ce80(param_4);
        if ((int)uVar3 < 0) {
          return uVar3;
        }
      }
      if (param_5 != 0) {
        return 0x80030057;
      }
      if ((param_2 != (int *)0x0) && (uVar3 = (**(code **)(*param_2 + 8))(param_2), (int)uVar3 < 0))
      {
        return uVar3;
      }
      FUN_4040a704();
      uVar3 = (*(code *)PTR_FUN_40430320)(&local_24);
      if ((int)uVar3 < 0) {
        return uVar3;
      }
      uVar3 = FUN_4040caa8(param_3);
      uVar3 = FUN_404059c4(local_24,param_1,uVar3,0,param_4,&local_28);
      (**(code **)(*local_24 + 8))();
      piVar4 = local_28;
      if (-1 < (int)uVar3) {
        *param_6 = local_28;
        (**(code **)(*param_1 + 4))(param_1);
        piVar4 = (int *)0x0;
      }
      if (piVar4 == (int *)0x0) {
        return uVar3;
      }
      (**(code **)(*piVar4 + 8))(piVar4);
      return uVar3;
    }
  }
  return 0x80030009;
}



/* 40406740 FUN_40406740 */

/* Boundary evidence: original MIPS .pdata 40406740..4040679b. Semantic name remains unreviewed. */

uint FUN_40406740(wchar_t *param_1,undefined4 param_2,int *param_3,uint param_4,undefined4 *param_5,
                 int param_6,int *param_7)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = DAT_404303e4;
  uVar2 = FUN_404062a4(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
  FUN_4042f4c4(uVar1);
  return uVar2;
}



/* 4040679c StgOpenStorage */

/* Boundary evidence: original MIPS .pdata 4040679c..40406813. Semantic name remains unreviewed. */

HRESULT StgOpenStorage(WCHAR *pwcsName,IStorage *pstgPriority,DWORD grfMode,SNB snbExclude,
                      DWORD reserved,IStorage **ppstgOpen)

{
  uint uVar1;
  
                    /* 0x679c  34  StgOpenStorage */
  uVar1 = FUN_40406740(pwcsName,0,(int *)pstgPriority,grfMode,snbExclude,reserved,(int *)ppstgOpen);
  return uVar1;
}



/* 40406814 FUN_40406814 */

/* Boundary evidence: original MIPS .pdata 40406814..4040681f. Semantic name remains unreviewed. */

undefined4 FUN_40406814(void)

{
  return 1;
}



/* 40406820 StgOpenStorageOnILockBytes */

/* Boundary evidence: original MIPS .pdata 40406820..40406873. Semantic name remains unreviewed. */

HRESULT StgOpenStorageOnILockBytes
                  (ILockBytes *plkbyt,IStorage *pstgPriority,DWORD grfMode,SNB snbExclude,
                  DWORD reserved,IStorage **ppstgOpen)

{
  uint uVar1;
  uint uVar2;
  
                    /* 0x6820  35  StgOpenStorageOnILockBytes */
  uVar1 = DAT_404303e4;
  uVar2 = FUN_40406510((int *)plkbyt,(int *)pstgPriority,grfMode,snbExclude,reserved,ppstgOpen);
  FUN_4042f4c4(uVar1);
  return uVar2;
}



/* 40406874 FUN_40406874 */

/* Boundary evidence: original MIPS .pdata 40406874..4040690f. Semantic name remains unreviewed. */

undefined4 FUN_40406874(void *param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = memcmp(param_1,&DAT_40401148,8);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    iVar1 = memcmp(param_1,&DAT_40401140,8);
    if (iVar1 == 0) {
      uVar2 = 1;
    }
    else {
      iVar1 = memcmp(param_1,&DAT_40401138,8);
      if (iVar1 == 0) {
        uVar2 = 0x80030104;
      }
      else {
        uVar2 = 0x800300fb;
      }
    }
  }
  return uVar2;
}



/* 40406910 FUN_40406910 */

/* Boundary evidence: original MIPS .pdata 40406910..40406993. Semantic name remains unreviewed. */

undefined4 FUN_40406910(int *param_1)

{
  HLOCAL _Dst;
  BOOL BVar1;
  
  _Dst = LocalAlloc(0,0x14);
  *param_1 = (int)_Dst;
  if (_Dst != (HLOCAL)0x0) {
    memset(_Dst,0,0x14);
    *(undefined4 *)(*param_1 + 4) = 1;
    BVar1 = TlsSetValue(DAT_40430490,(LPVOID)*param_1);
    if (BVar1 != 0) {
      return 0;
    }
    LocalFree((HLOCAL)*param_1);
    *param_1 = 0;
  }
  return 0x8007000e;
}



/* 40406994 FUN_40406994 */

/* Boundary evidence: original MIPS .pdata 40406994..40406a17. Semantic name remains unreviewed. */

void FUN_40406994(void)

{
  LPVOID hMem;
  int iVar1;
  
  hMem = TlsGetValue(DAT_40430490);
  if (hMem != (LPVOID)0x0) {
    *(uint *)((int)hMem + 4) = *(uint *)((int)hMem + 4) | 4;
    CoSetState((int *)0x0);
    iVar1 = *(int *)((int)hMem + 8);
    while (iVar1 != 0) {
      CoUninitialize();
      iVar1 = *(int *)((int)hMem + 8);
    }
    TlsSetValue(DAT_40430490,(LPVOID)0x0);
    LocalFree(hMem);
  }
  return;
}



/* 40406a18 FUN_40406a18 */

/* Boundary evidence: original MIPS .pdata 40406a18..40406aab. Semantic name remains unreviewed. */

undefined4 FUN_40406a18(undefined4 param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  
  uVar1 = 1;
  if (param_2 == 0) {
    if (param_3 == 0) {
      FUN_40406994();
      TlsCall(1,DAT_40430490);
    }
  }
  else if (param_2 == 1) {
    DAT_40430490 = TlsCall(0,0);
    if (DAT_40430490 == -1) {
      uVar1 = 0;
    }
  }
  else if (param_2 == 3) {
    FUN_40406994();
  }
  return uVar1;
}



/* 40406aac FUN_40406aac */

/* Boundary evidence: original MIPS .pdata 40406aac..40406b67. Semantic name remains unreviewed. */

int FUN_40406aac(wchar_t *param_1,LPCLSID param_2)

{
  undefined4 *puVar1;
  int iVar2;
  
  if (DAT_40430494 == (int *)0x0) {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_40430428);
    if (DAT_40430494 == (int *)0x0) {
      puVar1 = LocalAlloc(0,0x20);
      if (puVar1 == (undefined4 *)0x0) {
        DAT_40430494 = (int *)0x0;
      }
      else {
        DAT_40430494 = FUN_404144a0(puVar1);
      }
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_40430428);
    if (DAT_40430494 == (int *)0x0) {
      return -0x7ff8fff2;
    }
  }
  iVar2 = FUN_4041436c(DAT_40430494,param_1,param_2);
  return iVar2;
}



/* 40406b68 FUN_40406b68 */

/* Boundary evidence: original MIPS .pdata 40406b68..40406c3f. Semantic name remains unreviewed. */

int FUN_40406b68(LPCWSTR param_1,LPCLSID param_2)

{
  LSTATUS LVar1;
  int iVar2;
  HKEY local_228;
  DWORD local_224;
  DWORD aDStack_220 [2];
  wchar_t awStack_218 [256];
  uint local_18;
  
  local_18 = DAT_404303e4;
  iVar2 = -0x7ffbfeac;
  LVar1 = RegOpenKeyExW((HKEY)0x80000000,param_1,0,0x20019,&local_228);
  if (LVar1 == 0) {
    local_224 = 0x200;
    LVar1 = RegQueryValueExW(local_228,(LPCWSTR)0x0,(LPDWORD)0x0,aDStack_220,(LPBYTE)awStack_218,
                             &local_224);
    if (LVar1 == 0) {
      iVar2 = FUN_4040318c(awStack_218,param_2,0);
    }
    RegCloseKey(local_228);
  }
  FUN_4042f4c4(local_18);
  return iVar2;
}



/* 40406c40 FUN_40406c40 */

/* Boundary evidence: original MIPS .pdata 40406c40..40406c8b. Semantic name remains unreviewed. */

void FUN_40406c40(void)

{
  int *hMem;
  
  hMem = DAT_40430494;
  if (DAT_40430494 != (int *)0x0) {
    FUN_40414224(DAT_40430494);
    LocalFree(hMem);
    DAT_40430494 = (int *)0x0;
  }
  return;
}



/* 40406c8c FUN_40406c8c */

undefined4 * FUN_40406c8c(undefined4 *param_1)

{
  *param_1 = 0;
  param_1[1] = 0xffffffff;
  param_1[2] = 0xffffffff;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = 0xffffffff;
  param_1[6] = 0xffffffff;
  param_1[7] = 0;
  param_1[8] = 0;
  return param_1;
}



/* 40406cc0 FUN_40406cc0 */

/* Boundary evidence: original MIPS .pdata 40406cc0..40406da3. Semantic name remains unreviewed. */

DWORD FUN_40406cc0(undefined4 param_1,LPCWSTR param_2,int *param_3,undefined4 *param_4,
                  undefined4 *param_5)

{
  HMODULE pHVar1;
  DWORD DVar2;
  int iVar3;
  undefined4 uVar4;
  
  pHVar1 = LoadLibraryW(param_2);
  *param_5 = pHVar1;
  if (pHVar1 == (HMODULE)0x0) {
    DVar2 = GetLastError();
    if ((int)DVar2 < 1) {
      DVar2 = GetLastError();
    }
    else {
      DVar2 = GetLastError();
      DVar2 = DVar2 & 0xffff | 0x80070000;
    }
  }
  else {
    if (param_3 != (int *)0x0) {
      iVar3 = GetProcAddressW(pHVar1,L"DllGetClassObject");
      *param_3 = iVar3;
      if (iVar3 == 0) {
        return 0x800401f9;
      }
    }
    if (param_4 != (undefined4 *)0x0) {
      uVar4 = GetProcAddressW(*param_5,L"DllCanUnloadNow");
      *param_4 = uVar4;
    }
    DVar2 = 0;
  }
  return DVar2;
}



/* 40406da4 FUN_40406da4 */

/* Boundary evidence: original MIPS .pdata 40406da4..40406f73. Semantic name remains unreviewed. */

undefined4
FUN_40406da4(int param_1,int param_2,int param_3,int param_4,undefined4 param_5,undefined4 *param_6)

{
  LPVOID pvVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = param_2 * 0x44;
  *(undefined4 *)(iVar3 + *(int *)(param_1 + 0xc) + 4) = 0x53534c43;
  *(undefined4 *)(iVar3 + *(int *)(param_1 + 0xc) + 0x38) = 0;
  iVar4 = iVar3 + *(int *)(param_1 + 0xc);
  *(undefined4 *)(iVar4 + 8) = *param_6;
  *(undefined4 *)(iVar4 + 0xc) = param_6[1];
  *(undefined4 *)(iVar4 + 0x10) = param_6[2];
  *(undefined4 *)(iVar4 + 0x14) = param_6[3];
  *(undefined4 *)(iVar3 + *(int *)(param_1 + 0xc) + 0x18) = 0;
  *(undefined4 *)(iVar3 + *(int *)(param_1 + 0xc) + 0x1c) = 1;
  *(undefined4 *)(iVar3 + *(int *)(param_1 + 0xc) + 0x20) = 1;
  pvVar1 = TlsGetValue(DAT_40430490);
  if ((*(uint *)((int)pvVar1 + 4) & 0x80) == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = __GetUserKData(8);
  }
  *(undefined4 *)(iVar3 + *(int *)(param_1 + 0xc) + 0x28) = uVar2;
  *(undefined4 *)(iVar3 + *(int *)(param_1 + 0xc) + 0x24) = 0;
  *(undefined4 *)(iVar3 + *(int *)(param_1 + 0xc) + 0x2c) = 0;
  iVar4 = iVar3 + *(int *)(param_1 + 0xc);
  *(uint *)(iVar4 + 0x30) = *(uint *)(iVar4 + 0x30) & 0xfffffffe;
  iVar4 = iVar3 + *(int *)(param_1 + 0xc);
  *(uint *)(iVar4 + 0x30) = *(uint *)(iVar4 + 0x30) & 0xfffffffd;
  iVar4 = iVar3 + *(int *)(param_1 + 0xc);
  *(uint *)(iVar4 + 0x30) = *(uint *)(iVar4 + 0x30) & 0xfffffffb;
  *(int *)(iVar3 + *(int *)(param_1 + 0xc) + 0x3c) = param_3;
  *(int *)(iVar3 + *(int *)(param_1 + 0xc) + 0x34) = param_4;
  *(undefined4 *)(iVar3 + *(int *)(param_1 + 0xc) + 0x40) = param_5;
  if ((param_4 == 1) || (param_4 == 3)) {
    iVar3 = param_3 * 0x3c + *(int *)(param_1 + 0x1c);
    *(uint *)(iVar3 + 0x18) = *(uint *)(iVar3 + 0x18) | 0x10;
  }
  return 0;
}



/* 40406f74 FUN_40406f74 */

/* Boundary evidence: original MIPS .pdata 40406f74..4040707b. Semantic name remains unreviewed. */

undefined4 FUN_40406f74(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar1 = param_2 * 0x44;
  uVar3 = 0;
  if ((*(uint *)(*(int *)(param_1 + 0xc) + iVar1 + 0x30) & 4) == 0) {
    *(undefined4 *)(*(int *)(param_1 + 0xc) + iVar1 + 0x1c) = 0;
    iVar2 = *(int *)(param_1 + 0xc) + iVar1;
    *(uint *)(iVar2 + 0x30) = *(uint *)(iVar2 + 0x30) | 4;
    if (*(int *)(*(int *)(param_1 + 0xc) + iVar1 + 0x18) != 0) {
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_404303ec);
      if (*(int *)(*(int *)(param_1 + 0xc) + iVar1 + 0x18) != 0) {
        iVar2 = FUN_40409b68();
        if (iVar2 == 0) {
          uVar3 = 0x800401ff;
        }
        else {
          (**(code **)(**(int **)(*(int *)(param_1 + 0xc) + iVar1 + 0x18) + 8))();
          uVar3 = 0;
        }
      }
      EnterCriticalSection((LPCRITICAL_SECTION)&DAT_404303ec);
    }
  }
  else {
    uVar3 = 0;
  }
  return uVar3;
}



/* 4040707c FUN_4040707c */

void FUN_4040707c(int param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  
  iVar1 = param_2 * 0x3c;
  *(undefined4 *)(*(int *)(param_1 + 0x1c) + iVar1) = param_3;
  *(undefined4 *)(*(int *)(param_1 + 0x1c) + iVar1 + 4) = 0;
  *(undefined4 *)(*(int *)(param_1 + 0x1c) + iVar1 + 0x18) = 0;
  *(undefined4 *)(*(int *)(param_1 + 0x1c) + iVar1 + 0x1c) = 0xffffffff;
  *(undefined4 *)(*(int *)(param_1 + 0x1c) + iVar1 + 0x24) = 0x10;
  *(undefined4 *)(*(int *)(param_1 + 0x1c) + iVar1 + 0x28) = 0;
  *(undefined4 *)(*(int *)(param_1 + 0x1c) + iVar1 + 0x2c) = 0xffffffff;
  *(undefined4 *)(*(int *)(param_1 + 0x1c) + iVar1 + 0x38) = 0;
  return;
}



/* 404070f8 FUN_404070f8 */

/* Boundary evidence: original MIPS .pdata 404070f8..404071ab. Semantic name remains unreviewed. */

undefined4 FUN_404070f8(int param_1,int param_2)

{
  int iVar1;
  void *pvVar2;
  undefined4 uVar3;
  int *piVar4;
  int iVar5;
  uint uVar6;
  
  pvVar2 = operator_new(0x100);
  iVar1 = param_2 * 0x3c;
  *(void **)(*(int *)(param_1 + 0x1c) + iVar1 + 0x30) = pvVar2;
  if (*(int *)(*(int *)(param_1 + 0x1c) + iVar1 + 0x30) == 0) {
    uVar3 = 0;
  }
  else {
    uVar6 = 0;
    do {
      if (uVar6 == 0xf) {
        iVar5 = -1;
      }
      else {
        iVar5 = uVar6 + 1;
      }
      piVar4 = (int *)(*(int *)(*(int *)(param_1 + 0x1c) + iVar1 + 0x30) + uVar6 * 0x10);
      uVar6 = uVar6 + 1;
      *piVar4 = iVar5;
      piVar4[1] = 0;
    } while (uVar6 < 0x10);
    uVar3 = 1;
  }
  return uVar3;
}



/* 404071ac FUN_404071ac */

/* Boundary evidence: original MIPS .pdata 404071ac..4040736b. Semantic name remains unreviewed. */

int FUN_404071ac(int param_1,int param_2)

{
  int iVar1;
  void *_Dst;
  uint *puVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  
  iVar1 = param_2 * 0x3c;
  iVar3 = iVar1 + *(int *)(param_1 + 0x1c);
  if (*(int *)(iVar3 + 0x28) == -1) {
    uVar4 = *(int *)(iVar3 + 0x24) + 0x10;
    uVar5 = uVar4 * 0x10;
    if (0xfffffff < uVar4) {
      uVar5 = 0xffffffff;
    }
    _Dst = operator_new(uVar5);
    if (_Dst == (void *)0x0) {
      return -1;
    }
    iVar3 = iVar1 + *(int *)(param_1 + 0x1c);
    memcpy(_Dst,*(void **)(iVar3 + 0x30),*(int *)(iVar3 + 0x24) << 4);
    operator_delete(*(void **)(iVar1 + *(int *)(param_1 + 0x1c) + 0x30));
    *(void **)(iVar1 + *(int *)(param_1 + 0x1c) + 0x30) = _Dst;
    iVar7 = iVar1 + *(int *)(param_1 + 0x1c);
    iVar3 = *(int *)(iVar7 + 0x24);
    uVar5 = *(uint *)(iVar1 + *(int *)(param_1 + 0x1c) + 0x24);
    if (uVar5 < iVar3 + 0x10U) {
      iVar6 = uVar5 << 4;
      do {
        uVar4 = 0xffffffff;
        if (uVar5 != iVar3 + 0xfU) {
          uVar4 = uVar5 + 1;
        }
        puVar2 = (uint *)(*(int *)(iVar7 + 0x30) + iVar6);
        *puVar2 = uVar4;
        puVar2[1] = 0;
        iVar7 = iVar1 + *(int *)(param_1 + 0x1c);
        iVar3 = *(int *)(iVar7 + 0x24);
        uVar5 = uVar5 + 1;
        iVar6 = iVar6 + 0x10;
      } while (uVar5 < iVar3 + 0x10U);
    }
    iVar3 = iVar1 + *(int *)(param_1 + 0x1c);
    *(undefined4 *)(iVar3 + 0x28) = *(undefined4 *)(iVar3 + 0x24);
    iVar3 = iVar1 + *(int *)(param_1 + 0x1c);
    *(int *)(iVar3 + 0x24) = *(int *)(iVar3 + 0x24) + 0x10;
  }
  iVar3 = iVar1 + *(int *)(param_1 + 0x1c);
  iVar6 = *(int *)(iVar3 + 0x28);
  iVar7 = iVar6 * 0x10;
  *(undefined4 *)(*(int *)(iVar3 + 0x30) + iVar7 + 4) = 0x53545041;
  iVar3 = iVar1 + *(int *)(param_1 + 0x1c);
  *(undefined4 *)(iVar3 + 0x28) = *(undefined4 *)(*(int *)(iVar3 + 0x30) + iVar7);
  iVar3 = iVar1 + *(int *)(param_1 + 0x1c);
  *(undefined4 *)(*(int *)(iVar3 + 0x30) + iVar7) = *(undefined4 *)(iVar3 + 0x2c);
  *(int *)(iVar1 + *(int *)(param_1 + 0x1c) + 0x2c) = iVar6;
  return iVar6;
}



/* 4040736c FUN_4040736c */

void FUN_4040736c(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  
  iVar1 = param_2 * 0x3c;
  iVar2 = iVar1 + *(int *)(param_1 + 0x1c);
  iVar3 = *(int *)(iVar2 + 0x2c);
  if (iVar3 == param_3) {
    iVar3 = iVar1 + *(int *)(param_1 + 0x1c);
    *(undefined4 *)(iVar3 + 0x2c) = *(undefined4 *)(*(int *)(iVar3 + 0x30) + param_3 * 0x10);
  }
  else {
    do {
      iVar4 = iVar3;
      iVar3 = *(int *)(iVar4 * 0x10 + *(int *)(iVar2 + 0x30));
    } while (iVar3 != param_3);
    iVar3 = *(int *)(iVar1 + *(int *)(param_1 + 0x1c) + 0x30);
    *(undefined4 *)(iVar4 * 0x10 + iVar3) = *(undefined4 *)(iVar3 + param_3 * 0x10);
  }
  iVar3 = iVar1 + *(int *)(param_1 + 0x1c);
  *(undefined4 *)(*(int *)(iVar3 + 0x30) + param_3 * 0x10) = *(undefined4 *)(iVar3 + 0x28);
  *(int *)(iVar1 + *(int *)(param_1 + 0x1c) + 0x28) = param_3;
  puVar5 = (undefined4 *)(*(int *)(iVar1 + *(int *)(param_1 + 0x1c) + 0x30) + param_3 * 0x10);
  *puVar5 = *puVar5;
  puVar5[1] = 0;
  return;
}



/* 40407434 FUN_40407434 */

undefined4 FUN_40407434(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  
  iVar2 = param_2 * 0x3c + *(int *)(param_1 + 0x1c);
  iVar1 = *(int *)(iVar2 + 0x2c);
  if (iVar1 != -1) {
    do {
      piVar3 = (int *)(iVar1 * 0x10 + *(int *)(iVar2 + 0x30));
      if (piVar3[2] == param_3) {
        return 1;
      }
      iVar1 = *piVar3;
    } while (iVar1 != -1);
  }
  return 0;
}



/* 40407494 FUN_40407494 */

/* Boundary evidence: original MIPS .pdata 40407494..40407627. Semantic name remains unreviewed. */

DWORD FUN_40407494(int param_1,int param_2)

{
  int iVar1;
  LPVOID pvVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  DWORD DVar6;
  LPCWSTR pWVar7;
  int local_30;
  undefined4 local_2c;
  undefined4 local_28 [2];
  
  pvVar2 = TlsGetValue(DAT_40430490);
  if ((*(uint *)((int)pvVar2 + 4) & 0x80) == 0) {
    iVar3 = 0;
  }
  else {
    iVar3 = __GetUserKData(8);
  }
  iVar4 = FUN_40407434(param_1,param_2,iVar3);
  if (iVar4 == 0) {
    iVar4 = FUN_404071ac(param_1,param_2);
    if (iVar4 == -1) {
      DVar6 = 0x8007000e;
    }
    else {
      iVar1 = param_2 * 0x3c;
      iVar5 = *(int *)(iVar1 + *(int *)(param_1 + 0x1c) + 0x30) + iVar4 * 0x10;
      *(undefined4 *)(iVar5 + 4) = 0x53545041;
      *(int *)(iVar5 + 8) = iVar3;
      pWVar7 = *(LPCWSTR *)(iVar1 + *(int *)(param_1 + 0x1c) + 8);
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_404303ec);
      DVar6 = FUN_40406cc0(param_1,pWVar7,&local_30,&local_2c,local_28);
      EnterCriticalSection((LPCRITICAL_SECTION)&DAT_404303ec);
      *(int *)(iVar1 + *(int *)(param_1 + 0x1c) + 0x10) = local_30;
      *(undefined4 *)(iVar1 + *(int *)(param_1 + 0x1c) + 0x14) = local_2c;
      *(undefined4 *)(*(int *)(iVar1 + *(int *)(param_1 + 0x1c) + 0x30) + iVar4 * 0x10 + 0xc) =
           local_28[0];
      if ((int)DVar6 < 0) {
        FUN_4040736c(param_1,param_2,iVar4);
      }
    }
  }
  else {
    DVar6 = 0;
  }
  return DVar6;
}



/* 40407628 FUN_40407628 */

/* Boundary evidence: original MIPS .pdata 40407628..40407707. Semantic name remains unreviewed. */

undefined4
FUN_40407628(int param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,
            undefined4 *param_6)

{
  DWORD DVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  code *pcVar5;
  undefined4 local_20 [2];
  
  local_20[0] = 0;
  DVar1 = FUN_40407494(param_1,param_2);
  if ((int)DVar1 < 0) {
    local_20[0] = 0;
  }
  else {
    iVar3 = param_2 * 0x3c;
    iVar4 = *(int *)(param_1 + 0x1c) + iVar3;
    pcVar5 = *(code **)(iVar4 + 0x10);
    *(int *)(iVar4 + 0x20) = *(int *)(iVar4 + 0x20) + 1;
    *(undefined4 *)(*(int *)(param_1 + 0x1c) + iVar3 + 0x38) = 0;
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_404303ec);
    uVar2 = (*pcVar5)(param_4,param_5,local_20);
    *param_6 = uVar2;
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_404303ec);
    iVar3 = *(int *)(param_1 + 0x1c) + iVar3;
    *(int *)(iVar3 + 0x20) = *(int *)(iVar3 + 0x20) + -1;
  }
  return local_20[0];
}



/* 40407708 FUN_40407708 */

/* Boundary evidence: original MIPS .pdata 40407708..4040789f. Semantic name remains unreviewed. */

int FUN_40407708(int param_1,int param_2,uint param_3)

{
  int iVar1;
  DWORD DVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  code *pcVar6;
  
  iVar1 = param_2 * 0x3c;
  iVar3 = *(int *)(param_1 + 0x1c) + iVar1;
  if (*(int *)(iVar3 + 0x20) != 0) {
    return 1;
  }
  if (*(int *)(iVar3 + 0x14) == 0) {
    return 1;
  }
  iVar3 = *(int *)(param_1 + 0x1c) + iVar1;
  pcVar6 = *(code **)(iVar3 + 0x14);
  *(int *)(iVar3 + 0x20) = *(int *)(iVar3 + 0x20) + 1;
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_404303ec);
  iVar3 = (*pcVar6)();
  if (((iVar3 == 0) && ((*(uint *)(*(int *)(param_1 + 0x1c) + iVar1 + 0x18) & 0x10) != 0)) &&
     (param_3 != 0)) {
    DVar2 = GetTickCount();
    if (param_3 == 0xffffffff) {
      param_3 = 600000;
    }
    uVar4 = *(uint *)(*(int *)(param_1 + 0x1c) + iVar1 + 0x38);
    if (uVar4 == 0) {
      *(uint *)(*(int *)(param_1 + 0x1c) + iVar1 + 0x38) = param_3 + DVar2;
      if (*(uint *)(*(int *)(param_1 + 0x1c) + iVar1 + 0x38) < param_3) {
        *(uint *)(*(int *)(param_1 + 0x1c) + iVar1 + 0x38) = param_3;
      }
    }
    else if ((uVar4 <= DVar2) && (uVar4 <= param_3 + DVar2)) goto LAB_40407848;
    iVar3 = 1;
  }
LAB_40407848:
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_404303ec);
  iVar5 = *(int *)(param_1 + 0x1c) + iVar1;
  *(int *)(iVar5 + 0x20) = *(int *)(iVar5 + 0x20) + -1;
  if (*(int *)(*(int *)(param_1 + 0x1c) + iVar1 + 0x20) != 0) {
    return 1;
  }
  return iVar3;
}



/* 404078a0 FUN_404078a0 */

/* Boundary evidence: original MIPS .pdata 404078a0..40407967. Semantic name remains unreviewed. */

void FUN_404078a0(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = param_2 * 0x3c;
  *(undefined4 *)(*(int *)(param_1 + 0x1c) + iVar1 + 4) = 0;
  if (*(int *)(*(int *)(param_1 + 0x1c) + iVar1 + 0x34) != 0) {
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_404303ec);
    FreeLibrary(*(HMODULE *)(*(int *)(param_1 + 0x1c) + iVar1 + 0x34));
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_404303ec);
  }
  LocalFree(*(HLOCAL *)(*(int *)(param_1 + 0x1c) + iVar1 + 8));
  *(undefined4 *)(*(int *)(param_1 + 0x1c) + iVar1 + 8) = 0;
  operator_delete(*(void **)(*(int *)(param_1 + 0x1c) + iVar1 + 0x30));
  *(undefined4 *)(*(int *)(param_1 + 0x1c) + iVar1 + 0x30) = 0;
  return;
}



/* 40407968 FUN_40407968 */

int FUN_40407968(int param_1,int *param_2,uint param_3,int param_4)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = *(int *)(param_1 + 4);
  if (iVar1 != -1) {
    do {
      piVar2 = (int *)(iVar1 * 0x44 + *(int *)(param_1 + 0xc));
      if ((((*param_2 == piVar2[2]) && (param_2[1] == piVar2[3])) && (param_2[2] == piVar2[4])) &&
         ((((param_2[3] == piVar2[5] && ((piVar2[7] & param_3) != 0)) &&
           (((param_3 & 1) == 0 || ((piVar2[8] & 8U) == 0)))) && (piVar2[10] == param_4)))) {
        return iVar1;
      }
      iVar1 = *piVar2;
    } while (iVar1 != -1);
  }
  return -1;
}



/* 40407a20 FUN_40407a20 */

/* Boundary evidence: original MIPS .pdata 40407a20..40407b6b. Semantic name remains unreviewed. */

uint FUN_40407a20(uint *param_1)

{
  HLOCAL _Dst;
  int iVar1;
  uint *puVar2;
  uint uVar3;
  int iVar4;
  
  if (param_1[2] == 0xffffffff) {
    _Dst = LocalAlloc(0,(*param_1 + 8) * 0x44);
    if (_Dst == (HLOCAL)0x0) {
      return 0xffffffff;
    }
    memcpy(_Dst,(void *)param_1[3],*param_1 * 0x44);
    LocalFree((HLOCAL)param_1[3]);
    uVar3 = *param_1;
    param_1[3] = (uint)_Dst;
    if (uVar3 < uVar3 + 8) {
      iVar4 = uVar3 * 0x44;
      do {
        iVar1 = -1;
        if (uVar3 != *param_1 + 7) {
          iVar1 = uVar3 + 1;
        }
        *(int *)(param_1[3] + iVar4) = iVar1;
        *(undefined4 *)(param_1[3] + iVar4 + 4) = 0;
        *(undefined4 *)(param_1[3] + iVar4 + 0x40) = 0xffffffff;
        uVar3 = uVar3 + 1;
        iVar4 = iVar4 + 0x44;
      } while (uVar3 < *param_1 + 8);
    }
    param_1[2] = *param_1;
    *param_1 = *param_1 + 8;
  }
  uVar3 = param_1[2];
  *(undefined4 *)(param_1[3] + uVar3 * 0x44 + 4) = 0x53534c43;
  puVar2 = (uint *)(param_1[3] + uVar3 * 0x44);
  param_1[2] = *puVar2;
  *puVar2 = param_1[1];
  param_1[1] = uVar3;
  return uVar3;
}



/* 40407b6c FUN_40407b6c */

/* Boundary evidence: original MIPS .pdata 40407b6c..40407cb3. Semantic name remains unreviewed. */

int FUN_40407b6c(int param_1)

{
  HLOCAL _Dst;
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  uint uVar4;
  int iVar5;
  
  if (*(int *)(param_1 + 0x18) == -1) {
    _Dst = LocalAlloc(0,(*(int *)(param_1 + 0x10) + 8) * 0x3c);
    if (_Dst == (HLOCAL)0x0) {
      return -1;
    }
    memcpy(_Dst,*(void **)(param_1 + 0x1c),*(int *)(param_1 + 0x10) * 0x3c);
    LocalFree(*(HLOCAL *)(param_1 + 0x1c));
    *(HLOCAL *)(param_1 + 0x1c) = _Dst;
    uVar4 = *(uint *)(param_1 + 0x10);
    if (uVar4 < uVar4 + 8) {
      do {
        iVar2 = -1;
        if (uVar4 != *(int *)(param_1 + 0x10) + 7U) {
          iVar2 = uVar4 + 1;
        }
        FUN_4040707c(param_1,uVar4,iVar2);
        uVar4 = uVar4 + 1;
      } while (uVar4 < *(int *)(param_1 + 0x10) + 8U);
    }
    *(int *)(param_1 + 0x18) = *(int *)(param_1 + 0x10);
    *(int *)(param_1 + 0x10) = *(int *)(param_1 + 0x10) + 8;
  }
  iVar5 = *(int *)(param_1 + 0x18);
  *(undefined4 *)(*(int *)(param_1 + 0x1c) + iVar5 * 0x3c + 4) = 0x534c4c44;
  iVar1 = FUN_404070f8(param_1,iVar5);
  iVar2 = -1;
  if (iVar1 != 0) {
    puVar3 = (undefined4 *)(*(int *)(param_1 + 0x1c) + iVar5 * 0x3c);
    *(undefined4 *)(param_1 + 0x18) = *puVar3;
    *puVar3 = *(undefined4 *)(param_1 + 0x14);
    *(int *)(param_1 + 0x14) = iVar5;
    iVar2 = iVar5;
  }
  return iVar2;
}



/* 40407cb4 FUN_40407cb4 */

/* Boundary evidence: original MIPS .pdata 40407cb4..40407e4b. Semantic name remains unreviewed. */

void FUN_40407cb4(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  int local_8;
  
  iVar1 = param_2 * 0x44;
  if (*(int *)(*(int *)(param_1 + 0xc) + iVar1 + 4) == 0x53534c43) {
    iVar4 = *(int *)(param_1 + 0x14);
    while (iVar4 != -1) {
      piVar6 = (int *)(iVar4 * 0x3c + *(int *)(param_1 + 0x1c));
      for (iVar4 = piVar6[7]; iVar2 = iVar4, iVar2 != -1;
          iVar4 = *(int *)(iVar4 + *(int *)(param_1 + 0xc) + 0x40)) {
        iVar4 = iVar2 * 0x44;
        if (iVar2 == param_2) {
          if (iVar2 == piVar6[7]) {
            piVar6[7] = *(int *)(iVar4 + *(int *)(param_1 + 0xc) + 0x40);
          }
          else {
            *(undefined4 *)(local_8 * 0x44 + *(int *)(param_1 + 0xc) + 0x40) =
                 *(undefined4 *)(iVar4 + *(int *)(param_1 + 0xc) + 0x40);
          }
          goto LAB_40407da0;
        }
        local_8 = iVar2;
      }
      iVar4 = *piVar6;
    }
LAB_40407da0:
    iVar4 = *(int *)(param_1 + 4);
    if (iVar4 == param_2) {
      *(undefined4 *)(param_1 + 4) = *(undefined4 *)(*(int *)(param_1 + 0xc) + iVar1);
    }
    else {
      iVar2 = iVar4 * 0x44;
      iVar5 = *(int *)(param_1 + 0xc);
      iVar3 = *(int *)(iVar2 + iVar5);
      while (iVar3 != param_2) {
        iVar4 = *(int *)(iVar2 + iVar5);
        iVar2 = iVar4 * 0x44;
        iVar3 = *(int *)(iVar5 + iVar2);
      }
      *(undefined4 *)(iVar4 * 0x44 + iVar5) = *(undefined4 *)(iVar5 + iVar1);
    }
    *(undefined4 *)(*(int *)(param_1 + 0xc) + iVar1) = *(undefined4 *)(param_1 + 8);
    *(int *)(param_1 + 8) = param_2;
    *(undefined4 *)(*(int *)(param_1 + 0xc) + iVar1 + 4) = 0;
    *(undefined4 *)(*(int *)(param_1 + 0xc) + iVar1 + 0x40) = 0xffffffff;
  }
  return;
}



/* 40407e4c FUN_40407e4c */

/* Boundary evidence: original MIPS .pdata 40407e4c..40407f5f. Semantic name remains unreviewed. */

void FUN_40407e4c(int param_1,int param_2)

{
  int iVar1;
  void *pvVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar4 = *(int *)(param_1 + 0x14);
  if (iVar4 == param_2) {
    *(undefined4 *)(param_1 + 0x14) = *(undefined4 *)(*(int *)(param_1 + 0x1c) + param_2 * 0x3c);
  }
  else {
    iVar1 = iVar4 * 0x3c;
    iVar5 = *(int *)(param_1 + 0x1c);
    iVar3 = *(int *)(iVar1 + iVar5);
    while (iVar3 != param_2) {
      iVar4 = *(int *)(iVar1 + iVar5);
      iVar1 = iVar4 * 0x3c;
      iVar3 = *(int *)(iVar5 + iVar1);
    }
    *(undefined4 *)(iVar4 * 0x3c + iVar5) = *(undefined4 *)(iVar5 + param_2 * 0x3c);
  }
  iVar4 = param_2 * 0x3c;
  *(undefined4 *)(*(int *)(param_1 + 0x1c) + iVar4) = *(undefined4 *)(param_1 + 0x18);
  *(int *)(param_1 + 0x18) = param_2;
  pvVar2 = *(void **)(*(int *)(param_1 + 0x1c) + iVar4 + 0x30);
  if (pvVar2 != (void *)0x0) {
    operator_delete(pvVar2);
  }
  FUN_4040707c(param_1,param_2,*(undefined4 *)(*(int *)(param_1 + 0x1c) + iVar4));
  return;
}



/* 40407f60 FUN_40407f60 */

uint FUN_40407f60(undefined4 param_1,ushort *param_2)

{
  ushort uVar1;
  uint uVar2;
  int iVar3;
  
  uVar2 = 0;
  iVar3 = 0;
  uVar1 = *param_2;
  while (uVar1 != 0) {
    iVar3 = iVar3 + 1;
    uVar2 = uVar2 * 3 ^ (uint)uVar1;
    uVar1 = param_2[iVar3];
  }
  return uVar2;
}



/* 40407fa8 FUN_40407fa8 */

/* Boundary evidence: original MIPS .pdata 40407fa8..4040815b. Semantic name remains unreviewed. */

undefined4
FUN_40407fa8(int param_1,int param_2,wchar_t *param_3,undefined4 param_4,undefined4 param_5,
            undefined4 param_6)

{
  int iVar1;
  size_t sVar2;
  HLOCAL pvVar3;
  uint uVar4;
  int iVar5;
  LPVOID pvVar6;
  undefined4 uVar7;
  int iVar8;
  SIZE_T uBytes;
  
  sVar2 = wcslen(param_3);
  uBytes = (sVar2 + 1) * 2;
  pvVar3 = LocalAlloc(0,uBytes);
  iVar1 = param_2 * 0x3c;
  *(HLOCAL *)(*(int *)(param_1 + 0x1c) + iVar1 + 8) = pvVar3;
  if (*(int *)(*(int *)(param_1 + 0x1c) + iVar1 + 8) != 0) {
    memcpy(*(void **)(*(int *)(param_1 + 0x1c) + iVar1 + 8),param_3,uBytes);
    CharUpperW(*(LPWSTR *)(*(int *)(param_1 + 0x1c) + iVar1 + 8));
    *(undefined4 *)(*(int *)(param_1 + 0x1c) + iVar1 + 0x20) = 0;
    uVar4 = FUN_40407f60(param_1,*(ushort **)(*(int *)(param_1 + 0x1c) + iVar1 + 8));
    *(uint *)(*(int *)(param_1 + 0x1c) + iVar1 + 0xc) = uVar4;
    *(undefined4 *)(*(int *)(param_1 + 0x1c) + iVar1 + 0x34) = param_6;
    iVar5 = FUN_404071ac(param_1,param_2);
    if (iVar5 != -1) {
      pvVar6 = TlsGetValue(DAT_40430490);
      if ((*(uint *)((int)pvVar6 + 4) & 0x80) == 0) {
        uVar7 = 0;
      }
      else {
        uVar7 = __GetUserKData(8);
      }
      iVar8 = *(int *)(*(int *)(param_1 + 0x1c) + iVar1 + 0x30) + iVar5 * 0x10;
      *(undefined4 *)(iVar8 + 4) = 0x53545041;
      *(undefined4 *)(iVar8 + 8) = uVar7;
      *(undefined4 *)(*(int *)(param_1 + 0x1c) + iVar1 + 0x10) = param_4;
      *(undefined4 *)(*(int *)(param_1 + 0x1c) + iVar1 + 0x14) = param_5;
      *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x1c) + iVar1 + 0x30) + iVar5 * 0x10 + 0xc) = 0;
      return 0;
    }
  }
  return 0x8007000e;
}



/* 4040815c FUN_4040815c */

/* Boundary evidence: original MIPS .pdata 4040815c..4040829b. Semantic name remains unreviewed. */

bool FUN_4040815c(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  
  iVar1 = param_2 * 0x3c;
  iVar6 = *(int *)(*(int *)(param_1 + 0x1c) + iVar1 + 0x2c);
  while (iVar2 = iVar6, iVar2 != -1) {
    iVar6 = *(int *)(*(int *)(param_1 + 0x1c) + iVar1 + 0x1c);
    while (iVar3 = iVar6, iVar3 != -1) {
      iVar4 = *(int *)(param_1 + 0xc) + iVar3 * 0x44;
      iVar6 = *(int *)(iVar4 + 0x40);
      if (*(int *)(iVar4 + 0x28) == param_3) {
        FUN_40406f74(param_1,iVar3);
        iVar6 = *(int *)(*(int *)(param_1 + 0xc) + iVar3 * 0x44 + 0x40);
        FUN_40407cb4(param_1,iVar3);
      }
    }
    piVar5 = (int *)(*(int *)(*(int *)(param_1 + 0x1c) + iVar1 + 0x30) + iVar2 * 0x10);
    iVar6 = *piVar5;
    if (piVar5[2] == param_3) {
      FUN_4040736c(param_1,param_2,iVar2);
    }
  }
  return *(int *)(*(int *)(param_1 + 0x1c) + iVar1 + 0x2c) != -1;
}



/* 4040829c FUN_4040829c */

/* Boundary evidence: original MIPS .pdata 4040829c..40408607. Semantic name remains unreviewed. */

undefined4
FUN_4040829c(int param_1,int *param_2,undefined *param_3,int param_4,int param_5,int param_6,
            undefined4 *param_7)

{
  LPVOID pvVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  undefined4 *puVar7;
  undefined4 local_28 [2];
  
  local_28[0] = 0;
  *param_7 = 0;
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_404303ec);
  if (param_5 == 0) {
    pvVar1 = TlsGetValue(DAT_40430490);
    if ((*(uint *)((int)pvVar1 + 4) & 0x80) == 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = __GetUserKData(8);
    }
    iVar2 = FUN_40407968(param_1,param_2,3,iVar2);
    if ((iVar2 != -1) &&
       ((param_4 == 0 || (*(int *)(iVar2 * 0x44 + *(int *)(param_1 + 0xc) + 0x38) == 0)))) {
      iVar4 = iVar2 * 0x44;
      iVar6 = iVar4 + *(int *)(param_1 + 0xc);
      if (*(int *)(iVar6 + 0x3c) == -1) {
        if (*(int *)(iVar6 + 0x20) == 0) {
          *(undefined4 *)(iVar6 + 0x1c) = 0;
        }
        iVar6 = iVar4 + *(int *)(param_1 + 0xc);
        puVar7 = *(undefined4 **)(iVar6 + 0x18);
        *(int *)(iVar6 + 0x2c) = *(int *)(iVar6 + 0x2c) + 1;
        LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_404303ec);
        if (param_6 != 0) {
          param_3 = &DAT_40402244;
        }
        uVar3 = (**(code **)*puVar7)(puVar7,param_3,param_7);
        EnterCriticalSection((LPCRITICAL_SECTION)&DAT_404303ec);
        iVar6 = iVar4 + *(int *)(param_1 + 0xc);
        *(int *)(iVar6 + 0x2c) = *(int *)(iVar6 + 0x2c) + -1;
        if (((*(uint *)(iVar4 + *(int *)(param_1 + 0xc) + 0x30) & 1) != 0) &&
           (*(int *)(iVar4 + *(int *)(param_1 + 0xc) + 0x2c) == 0)) {
          FUN_40406f74(param_1,iVar2);
          FUN_40407cb4(param_1,iVar2);
        }
      }
      else {
        iVar4 = iVar4 + *(int *)(param_1 + 0xc);
        uVar3 = FUN_40407628(param_1,*(int *)(iVar4 + 0x3c),*(undefined4 *)(iVar4 + 0x34),param_2,
                             param_3,local_28);
        *param_7 = uVar3;
        uVar3 = local_28[0];
      }
      goto LAB_404085d4;
    }
  }
  else {
    pvVar1 = TlsGetValue(DAT_40430490);
    if ((*(uint *)((int)pvVar1 + 4) & 0x80) == 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = __GetUserKData(8);
    }
    iVar2 = FUN_40407968(param_1,param_2,4,iVar2);
    if (iVar2 != -1) {
      iVar4 = iVar2 * 0x44;
      iVar6 = iVar4 + *(int *)(param_1 + 0xc);
      uVar5 = *(uint *)(iVar6 + 0x20);
      if ((uVar5 & 4) == 0) {
        if (uVar5 == 0) {
          *(undefined4 *)(iVar6 + 0x1c) = 0;
        }
        iVar6 = iVar4 + *(int *)(param_1 + 0xc);
        puVar7 = *(undefined4 **)(iVar6 + 0x18);
        *(int *)(iVar6 + 0x2c) = *(int *)(iVar6 + 0x2c) + 1;
        LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_404303ec);
        if (param_6 != 0) {
          param_3 = &DAT_40402244;
        }
        uVar3 = (**(code **)*puVar7)(puVar7,param_3,param_7);
        EnterCriticalSection((LPCRITICAL_SECTION)&DAT_404303ec);
        iVar6 = iVar4 + *(int *)(param_1 + 0xc);
        *(int *)(iVar6 + 0x2c) = *(int *)(iVar6 + 0x2c) + -1;
        if (((*(uint *)(iVar4 + *(int *)(param_1 + 0xc) + 0x30) & 1) != 0) &&
           (*(int *)(iVar4 + *(int *)(param_1 + 0xc) + 0x2c) == 0)) {
          FUN_40406f74(param_1,iVar2);
          FUN_40407cb4(param_1,iVar2);
          uVar3 = 0x800401fd;
        }
        goto LAB_404085d4;
      }
    }
  }
  uVar3 = 0;
LAB_404085d4:
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_404303ec);
  return uVar3;
}



/* 40408608 FUN_40408608 */

/* Boundary evidence: original MIPS .pdata 40408608..4040875f. Semantic name remains unreviewed. */

void FUN_40408608(int param_1,uint param_2)

{
  int iVar1;
  bool bVar2;
  LPVOID pvVar3;
  int iVar4;
  int iVar5;
  undefined3 extraout_var;
  int iVar6;
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_404303ec);
  pvVar3 = TlsGetValue(DAT_40430490);
  if ((*(uint *)((int)pvVar3 + 4) & 0x80) == 0) {
    iVar4 = 0;
  }
  else {
    iVar4 = __GetUserKData(8);
  }
  if (*(int *)(param_1 + 0x1c) != 0) {
    iVar6 = *(int *)(param_1 + 0x14);
    while (iVar1 = iVar6, iVar1 != -1) {
      iVar6 = *(int *)(*(int *)(param_1 + 0x1c) + iVar1 * 0x3c);
      iVar5 = FUN_40407434(param_1,iVar1,iVar4);
      if ((iVar5 != 0) && (iVar5 = FUN_40407708(param_1,iVar1,param_2), iVar5 == 0)) {
        bVar2 = FUN_4040815c(param_1,iVar1,iVar4);
        iVar6 = *(int *)(*(int *)(param_1 + 0x1c) + iVar1 * 0x3c);
        if (CONCAT31(extraout_var,bVar2) == 0) {
          FUN_404078a0(param_1,iVar1);
          FUN_40407e4c(param_1,iVar1);
        }
      }
    }
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_404303ec);
  return;
}



/* 40408760 FUN_40408760 */

/* Boundary evidence: original MIPS .pdata 40408760..404088b7. Semantic name remains unreviewed. */

void FUN_40408760(int param_1)

{
  int iVar1;
  bool bVar2;
  LPVOID pvVar3;
  int iVar4;
  int iVar5;
  undefined3 extraout_var;
  int iVar6;
  
  pvVar3 = TlsGetValue(DAT_40430490);
  if ((*(uint *)((int)pvVar3 + 4) & 0x80) == 0) {
    iVar4 = 0;
  }
  else {
    iVar4 = __GetUserKData(8);
  }
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_404303ec);
  if (*(int *)(param_1 + 0x1c) != 0) {
    iVar6 = *(int *)(param_1 + 0x14);
    while (iVar1 = iVar6, iVar1 != -1) {
      iVar6 = *(int *)(*(int *)(param_1 + 0x1c) + iVar1 * 0x3c);
      iVar5 = FUN_40407434(param_1,iVar1,iVar4);
      if (iVar5 != 0) {
        iVar5 = FUN_40407708(param_1,iVar1,0xffffffff);
        bVar2 = FUN_4040815c(param_1,iVar1,iVar4);
        iVar6 = *(int *)(*(int *)(param_1 + 0x1c) + iVar1 * 0x3c);
        if ((CONCAT31(extraout_var,bVar2) == 0) && (iVar5 == 0)) {
          FUN_404078a0(param_1,iVar1);
          FUN_40407e4c(param_1,iVar1);
        }
      }
    }
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_404303ec);
  return;
}



/* 404088b8 FUN_404088b8 */

/* Boundary evidence: original MIPS .pdata 404088b8..404089bb. Semantic name remains unreviewed. */

void FUN_404088b8(undefined4 *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_404303ec);
  if (param_1[7] != 0) {
    iVar1 = param_1[5];
    while (iVar1 != -1) {
      while( true ) {
        iVar2 = param_1[5];
        iVar3 = iVar2 * 0x3c + param_1[7];
        iVar1 = *(int *)(iVar3 + 0x2c);
        if (iVar1 == -1) break;
        FUN_4040815c((int)param_1,iVar2,*(int *)(*(int *)(iVar3 + 0x30) + iVar1 * 0x10 + 8));
      }
      FUN_404078a0((int)param_1,iVar2);
      FUN_40407e4c((int)param_1,param_1[5]);
      iVar1 = param_1[5];
    }
    LocalFree((HLOCAL)param_1[7]);
    param_1[7] = 0;
  }
  param_1[4] = 0;
  param_1[5] = 0xffffffff;
  param_1[6] = 0xffffffff;
  if ((HLOCAL)param_1[3] != (HLOCAL)0x0) {
    LocalFree((HLOCAL)param_1[3]);
    param_1[3] = 0;
  }
  *param_1 = 0;
  param_1[1] = 0xffffffff;
  param_1[2] = 0xffffffff;
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_404303ec);
  return;
}



/* 404089bc FUN_404089bc */

/* Boundary evidence: original MIPS .pdata 404089bc..40408b47. Semantic name remains unreviewed. */

int FUN_404089bc(int param_1,wchar_t *param_2)

{
  bool bVar1;
  size_t sVar2;
  wchar_t *_Dest;
  uint uVar3;
  int iVar4;
  int iVar5;
  wchar_t awStack_238 [260];
  uint local_30;
  
  local_30 = DAT_404303e4;
  _Dest = awStack_238;
  sVar2 = wcslen(param_2);
  bVar1 = false;
  if (0x103 < sVar2) {
    _Dest = LocalAlloc(0,(sVar2 + 1) * 2);
    if (_Dest == (wchar_t *)0x0) {
      FUN_4042f4c4(local_30);
      return -1;
    }
    bVar1 = true;
  }
  wcscpy(_Dest,param_2);
  CharUpperW(_Dest);
  uVar3 = FUN_40407f60(param_1,(ushort *)_Dest);
  iVar5 = *(int *)(param_1 + 0x14);
  while( true ) {
    if (iVar5 == -1) {
      if (bVar1) {
        LocalFree(_Dest);
      }
      FUN_4042f4c4(local_30);
      return -1;
    }
    iVar4 = *(int *)(param_1 + 0x1c) + iVar5 * 0x3c;
    if (((*(uint *)(iVar4 + 0xc) == uVar3) && (*(int *)(iVar4 + 4) == 0x534c4c44)) &&
       (iVar4 = lstrcmpW(*(LPCWSTR *)(iVar4 + 8),_Dest), iVar4 == 0)) break;
    iVar5 = *(int *)(*(int *)(param_1 + 0x1c) + iVar5 * 0x3c);
  }
  if (bVar1) {
    LocalFree(_Dest);
  }
  FUN_4042f4c4(local_30);
  return iVar5;
}



/* 40408b48 FUN_40408b48 */

/* Boundary evidence: original MIPS .pdata 40408b48..40408b67. Semantic name remains unreviewed. */

void FUN_40408b48(void)

{
  FUN_404088b8((undefined4 *)&DAT_40430458);
  return;
}



/* 40408b68 FUN_40408b68 */

/* Boundary evidence: original MIPS .pdata 40408b68..40408b87. Semantic name remains unreviewed. */

void FUN_40408b68(void)

{
  FUN_40408760(0x40430458);
  return;
}



/* 40408b88 FUN_40408b88 */

/* Boundary evidence: original MIPS .pdata 40408b88..40408baf. Semantic name remains unreviewed. */

undefined4 FUN_40408b88(uint param_1)

{
  FUN_40408608(0x40430458,param_1);
  return 0;
}



/* 40408bb0 FUN_40408bb0 */

/* Boundary evidence: original MIPS .pdata 40408bb0..40408e6f. Semantic name remains unreviewed. */

undefined4
FUN_40408bb0(uint *param_1,int *param_2,undefined4 param_3,int param_4,wchar_t *param_5,
            undefined4 param_6,DWORD *param_7)

{
  int iVar1;
  DWORD DVar2;
  undefined4 uVar3;
  LPVOID pvVar4;
  int iVar5;
  uint uVar6;
  HMODULE local_38;
  undefined4 local_34;
  int local_30 [2];
  
  *param_7 = 0x80004005;
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_404303ec);
  if (param_5 != (wchar_t *)0x0) {
    iVar1 = FUN_404089bc((int)param_1,param_5);
    if (iVar1 == -1) {
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_404303ec);
      DVar2 = FUN_40406cc0(param_1,param_5,local_30,&local_34,&local_38);
      *param_7 = DVar2;
      EnterCriticalSection((LPCRITICAL_SECTION)&DAT_404303ec);
      if ((int)*param_7 < 0) goto LAB_40408c78;
      iVar1 = FUN_404089bc((int)param_1,param_5);
      if (iVar1 == -1) {
        iVar1 = FUN_40407b6c((int)param_1);
        if (iVar1 == -1) {
          *param_7 = 0x8007000e;
LAB_40408c78:
          LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_404303ec);
          return 0;
        }
        DVar2 = FUN_40407fa8((int)param_1,iVar1,param_5,local_30[0],local_34,local_38);
        *param_7 = DVar2;
        if ((int)DVar2 < 0) {
          FUN_40407e4c((int)param_1,iVar1);
          goto LAB_40408c78;
        }
        *(undefined4 *)(iVar1 * 0x3c + param_1[7] + 0x1c) = 0xffffffff;
        DVar2 = FUN_40407494((int)param_1,iVar1);
        if ((int)DVar2 < 0) goto LAB_40408c78;
      }
      else {
        DVar2 = FUN_40407494((int)param_1,iVar1);
        if ((int)DVar2 < 0) goto LAB_40408c78;
        LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_404303ec);
        FreeLibrary(local_38);
        EnterCriticalSection((LPCRITICAL_SECTION)&DAT_404303ec);
      }
    }
    uVar3 = FUN_40407628((int)param_1,iVar1,param_4,param_2,param_3,param_7);
    if (-1 < (int)*param_7) {
      pvVar4 = TlsGetValue(DAT_40430490);
      if ((*(uint *)((int)pvVar4 + 4) & 0x80) == 0) {
        iVar5 = 0;
      }
      else {
        iVar5 = __GetUserKData(8);
      }
      iVar5 = FUN_40407968((int)param_1,param_2,1,iVar5);
      if (iVar5 != -1) goto LAB_40408e34;
      uVar6 = FUN_40407a20(param_1);
      if (uVar6 != 0xffffffff) {
        FUN_40406da4((int)param_1,uVar6,iVar1,param_4,
                     *(undefined4 *)(iVar1 * 0x3c + param_1[7] + 0x1c),param_2);
        *(uint *)(iVar1 * 0x3c + param_1[7] + 0x1c) = uVar6;
        goto LAB_40408e34;
      }
    }
  }
  uVar3 = 0;
LAB_40408e34:
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_404303ec);
  return uVar3;
}



/* 40408e70 FUN_40408e70 */

/* Boundary evidence: original MIPS .pdata 40408e70..40408feb. Semantic name remains unreviewed. */

int FUN_40408e70(uint *param_1,int *param_2,undefined *param_3,int param_4,int param_5,uint param_6,
                undefined4 param_7,DWORD *param_8)

{
  DWORD DVar1;
  LSTATUS LVar2;
  int iVar3;
  int local_2e0;
  int local_2dc [3];
  WCHAR aWStack_2d0 [6];
  undefined2 auStack_2c4 [38];
  undefined2 local_278;
  undefined1 auStack_276 [70];
  wchar_t awStack_230 [260];
  uint local_28;
  
  local_28 = DAT_404303e4;
  local_2e0 = 0;
  *param_8 = 0;
  DVar1 = FUN_4040829c((int)param_1,param_2,param_3,param_4,param_5,0,&local_2e0);
  *param_8 = DVar1;
  iVar3 = local_2e0;
  if (local_2e0 == 0) {
    memcpy(aWStack_2d0,L"CLSID\\",0xe);
    FUN_404090c8((int)param_2,auStack_2c4,0x27);
    local_278 = 0x5c;
    *param_8 = 0x80040154;
    iVar3 = local_2e0;
    if ((local_2e0 == 0) && ((param_6 & 1) != 0)) {
      local_2dc[1] = 0x104;
      *param_8 = 0x80040154;
      memcpy(auStack_276,L"InprocServer32",0x1e);
      LVar2 = FUN_40414690((HKEY)0x80000000,aWStack_2d0,(wint_t *)awStack_230,
                           (LPDWORD)(local_2dc + 1),local_2dc);
      iVar3 = local_2e0;
      if ((LVar2 == 0) && ((local_2dc[0] == 3 || (local_2dc[0] == 1)))) {
        iVar3 = FUN_40408bb0(param_1,param_2,param_3,local_2dc[0],awStack_230,1,param_8);
      }
    }
  }
  FUN_4042f4c4(local_28);
  return iVar3;
}



/* 40408fec FUN_40408fec */

/* Boundary evidence: original MIPS .pdata 40408fec..40409033. Semantic name remains unreviewed. */

undefined4 FUN_40408fec(undefined4 param_1,int param_2)

{
  if (param_2 == 0) {
    DeleteCriticalSection((LPCRITICAL_SECTION)&DAT_4043047c);
  }
  else if (param_2 == 1) {
    InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_4043047c);
  }
  return 1;
}



/* 40409034 FUN_40409034 */

undefined4 FUN_40409034(int param_1,wchar_t *param_2)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = 0;
  do {
    uVar1 = (uint)(byte)(&DAT_404011c4)[uVar2];
    if (uVar1 == 0x2d) {
      *param_2 = L'-';
      param_2 = param_2 + 1;
    }
    else {
      *param_2 = L"0123456789ABCDEF"[*(byte *)(uVar1 + param_1) >> 4];
      param_2[1] = L"0123456789ABCDEF"
                   [*(byte *)((uint)(byte)(&DAT_404011c4)[uVar2] + param_1) & 0xf];
      param_2 = param_2 + 2;
    }
    uVar2 = uVar2 + 1;
  } while (uVar2 < 0x14);
  *param_2 = L'\0';
  return 0;
}



/* 404090c8 FUN_404090c8 */

/* Boundary evidence: original MIPS .pdata 404090c8..4040911b. Semantic name remains unreviewed. */

undefined4 FUN_404090c8(int param_1,undefined2 *param_2,int param_3)

{
  undefined4 uVar1;
  
  if (param_3 < 0x27) {
    uVar1 = 0;
  }
  else {
    *param_2 = 0x7b;
    FUN_40409034(param_1,param_2 + 1);
    param_2[0x25] = 0x7d;
    param_2[0x26] = 0;
    uVar1 = 0x27;
  }
  return uVar1;
}



/* 4040911c FUN_4040911c */

/* Boundary evidence: original MIPS .pdata 4040911c..40409207. Semantic name remains unreviewed. */

LSTATUS FUN_4040911c(HKEY param_1,LPCWSTR param_2,DWORD param_3,BYTE *param_4,DWORD param_5)

{
  LSTATUS LVar1;
  HKEY local_18 [2];
  
  local_18[0] = (HKEY)0x0;
  if (param_2 == (LPCWSTR)0x0) {
    LVar1 = RegSetValueExW(param_1,(LPCWSTR)0x0,0,param_3,param_4,param_5);
  }
  else {
    LVar1 = RegCreateKeyExW(param_1,param_2,0,(LPWSTR)0x0,0,0x20006,(LPSECURITY_ATTRIBUTES)0x0,
                            local_18,(LPDWORD)0x0);
    if (LVar1 == 0) {
      LVar1 = RegSetValueExW(local_18[0],(LPCWSTR)0x0,0,param_3,param_4,(param_5 + 1) * 2);
      RegCloseKey(local_18[0]);
    }
  }
  return LVar1;
}



/* 40409208 FUN_40409208 */

/* Boundary evidence: original MIPS .pdata 40409208..404094a3. Semantic name remains unreviewed. */

undefined4 FUN_40409208(wchar_t *param_1,wchar_t *param_2)

{
  LSTATUS LVar1;
  size_t sVar2;
  int iVar3;
  HKEY local_438;
  DWORD local_434;
  undefined4 local_430;
  wchar_t awStack_428 [256];
  BYTE aBStack_228 [512];
  uint local_28;
  
  local_28 = DAT_404303e4;
  local_434 = 0x100;
  local_438 = (HKEY)0x0;
  LVar1 = RegOpenKeyExW((HKEY)0x80000000,param_1,0,0x2001f,&local_438);
  if ((LVar1 != 0x57) && (LVar1 == 0)) {
    local_430 = 0;
    LVar1 = RegQueryValueExW(local_438,(LPCWSTR)0x0,(LPDWORD)0x0,(LPDWORD)0x0,aBStack_228,&local_434
                            );
    if ((LVar1 != 0x57) && (LVar1 == 0)) {
      sVar2 = wcslen(param_2);
      LVar1 = FUN_4040911c(local_438,L"Clsid",1,(BYTE *)param_2,sVar2);
      if (LVar1 == 0) {
        iVar3 = lstrcmpW(param_2,L"{00030003-0000-0000-C000-000000000046}");
        if (iVar3 == 0) {
          FUN_4040911c(local_438,L"PackageOnFileDrop",1,(BYTE *)0x0,0);
        }
        LVar1 = RegCloseKey(local_438);
        if (LVar1 == 0) {
          local_438 = (HKEY)0x0;
          StringCchPrintfW(awStack_428,0x100,L"CLSID\\%ws",param_2);
          LVar1 = FUN_4040911c((HKEY)0x80000000,awStack_428,1,aBStack_228,local_434);
          if (((LVar1 == 0) &&
              (LVar1 = RegOpenKeyExW((HKEY)0x80000000,awStack_428,0,0x2001f,&local_438),
              LVar1 != 0x57)) && (LVar1 == 0)) {
            sVar2 = wcslen(param_1);
            LVar1 = FUN_4040911c(local_438,L"Ole1Class",1,(BYTE *)param_1,sVar2);
            if (LVar1 == 0) {
              sVar2 = wcslen(param_1);
              LVar1 = FUN_4040911c(local_438,L"ProgID",1,(BYTE *)param_1,sVar2);
              if ((LVar1 == 0) && (LVar1 = RegCloseKey(local_438), LVar1 == 0)) {
                FUN_4042f4c4(local_28);
                return 0;
              }
            }
          }
        }
      }
    }
  }
  if (local_438 != (HKEY)0x0) {
    RegCloseKey(local_438);
  }
  FUN_4042f4c4(local_28);
  return 0x80040151;
}



/* 404094a4 FUN_404094a4 */

/* Boundary evidence: original MIPS .pdata 404094a4..40409743. Semantic name remains unreviewed. */

int FUN_404094a4(LPCWSTR param_1,LPCLSID param_2,int param_3)

{
  WCHAR WVar1;
  int iVar2;
  LSTATUS LVar3;
  undefined *puVar4;
  ulong uVar5;
  ulong *puVar6;
  uint uVar7;
  WCHAR *pWVar8;
  undefined **ppuVar9;
  HKEY local_d0;
  HKEY local_cc;
  OLECHAR aOStack_c8 [80];
  uint local_28;
  
  local_28 = DAT_404303e4;
  param_2->Data1 = 0;
  param_2->Data2 = 0;
  param_2->Data3 = 0;
  param_2->Data4[0] = '\0';
  param_2->Data4[1] = '\0';
  param_2->Data4[2] = '\0';
  param_2->Data4[3] = '\0';
  ppuVar9 = &PTR_u_ExcelWorksheet_40430168;
  param_2->Data4[4] = '\0';
  param_2->Data4[5] = '\0';
  param_2->Data4[6] = '\0';
  param_2->Data4[7] = '\0';
  puVar4 = PTR_u_ExcelWorksheet_40430168;
  while (puVar4 != (undefined *)0x0) {
    iVar2 = lstrcmpiW(param_1,(LPCWSTR)*ppuVar9);
    if (iVar2 == 0) {
      puVar6 = (ulong *)ppuVar9[1];
      param_2->Data1 = *puVar6;
      uVar5 = puVar6[1];
      param_2->Data2 = (short)uVar5;
      param_2->Data3 = (short)(uVar5 >> 0x10);
      *(ulong *)param_2->Data4 = puVar6[2];
      *(ulong *)(param_2->Data4 + 4) = puVar6[3];
      StringFromGUID2((GUID *)ppuVar9[1],aOStack_c8,0x50);
      break;
    }
    ppuVar9 = ppuVar9 + 2;
    puVar4 = *ppuVar9;
  }
  if ((((param_2->Data1 == 0) &&
       (iVar2._0_2_ = param_2->Data2, iVar2._2_2_ = param_2->Data3, iVar2 == 0)) &&
      (*(int *)param_2->Data4 == 0)) && (*(int *)(param_2->Data4 + 4) == 0)) {
    if (param_3 == 0) {
      iVar2 = 0;
      local_d0 = (HKEY)0x0;
      local_cc = (HKEY)0x0;
      LVar3 = RegOpenKeyExW((HKEY)0x80000000,param_1,0,0x2001f,&local_d0);
      if (((LVar3 == 0x57) || (LVar3 != 0)) ||
         ((LVar3 = RegOpenKeyExW(local_d0,L"protocol\\StdFileEditing",0,0x2001f,&local_cc),
          LVar3 == 0x57 || (LVar3 != 0)))) {
        iVar2 = -0x7ffbfe0d;
      }
      if (local_d0 != (HKEY)0x0) {
        RegCloseKey(local_d0);
      }
      if (local_cc != (HKEY)0x0) {
        RegCloseKey(local_cc);
      }
      if (iVar2 != 0) goto LAB_40409710;
    }
    uVar7 = 0;
    WVar1 = *param_1;
    pWVar8 = param_1;
    while ((ushort)WVar1 != 0) {
      pWVar8 = pWVar8 + 1;
      uVar7 = uVar7 * 0x101 + (uint)(ushort)WVar1 & 0xffff;
      WVar1 = *pWVar8;
    }
    StringCchPrintfW(aOStack_c8,0x50,L"{0004%02X%02X-0000-0000-C000-000000000046}",uVar7 & 0xff,
                     uVar7 >> 8);
    CLSIDFromString(aOStack_c8,param_2);
  }
  iVar2 = FUN_40409208(param_1,aOStack_c8);
  if (param_3 != 0) {
    iVar2 = 0;
  }
LAB_40409710:
  FUN_4042f4c4(local_28);
  return iVar2;
}



/* 40409744 FUN_40409744 */

/* Boundary evidence: original MIPS .pdata 40409744..40409833. Semantic name remains unreviewed. */

int FUN_40409744(int param_1,uint param_2,int param_3)

{
  uint uVar1;
  int *piVar2;
  uint uVar3;
  
  if (param_1 < 0) {
    if (param_2 != 0) {
      piVar2 = (int *)(param_3 + 8);
      do {
        if ((int *)piVar2[-1] != (int *)0x0) {
          (**(code **)(*(int *)piVar2[-1] + 8))();
        }
        param_2 = param_2 - 1;
        piVar2[-1] = 0;
        *piVar2 = param_1;
        piVar2 = piVar2 + 3;
      } while (param_2 != 0);
    }
  }
  else {
    uVar1 = 0;
    if (param_2 != 0) {
      piVar2 = (int *)(param_3 + 8);
      uVar3 = param_2;
      do {
        if (*piVar2 < 0) {
          piVar2[-1] = 0;
        }
        else {
          uVar1 = uVar1 + 1;
        }
        uVar3 = uVar3 - 1;
        piVar2 = piVar2 + 3;
      } while (uVar3 != 0);
      if (uVar1 != 0) {
        if (param_2 <= uVar1) {
          return param_1;
        }
        return 0x80012;
      }
    }
    if (param_2 == 1) {
      param_1 = *(int *)(param_3 + 8);
    }
    else {
      param_1 = -0x7fffbffe;
    }
  }
  return param_1;
}



/* 40409834 FUN_40409834 */

/* Boundary evidence: original MIPS .pdata 40409834..4040993b. Semantic name remains unreviewed. */

DWORD FUN_40409834(int *param_1,uint param_2,int param_3,undefined *param_4,int *param_5)

{
  LPVOID pvVar1;
  int iVar2;
  DWORD DVar3;
  DWORD local_38 [2];
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  uint local_20;
  
  local_20 = DAT_404303e4;
  local_38[0] = 0;
  pvVar1 = TlsGetValue(DAT_40430490);
  if (param_3 == 0) {
    local_30 = *param_1;
    local_2c = param_1[1];
    local_28 = param_1[2];
    local_24 = param_1[3];
    iVar2 = FUN_40403820(&local_30,param_4,0,0,param_2,
                         (uint)((*(uint *)((int)pvVar1 + 4) & 0x80) == 0),local_38);
    *param_5 = iVar2;
    DVar3 = local_38[0];
    if ((iVar2 == 0) && (-1 < (int)local_38[0])) {
      DVar3 = 0x8007000e;
    }
    FUN_4042f4c4(local_20);
  }
  else {
    FUN_4042f4c4(local_20);
    DVar3 = 0x80070057;
  }
  return DVar3;
}



/* 4040993c FUN_4040993c */

/* Boundary evidence: original MIPS .pdata 4040993c..40409b67. Semantic name remains unreviewed. */

int FUN_4040993c(int *param_1,undefined4 param_2,uint param_3,int param_4,uint param_5,
                undefined4 *param_6)

{
  int iVar1;
  LPVOID pvVar2;
  int *piVar3;
  undefined4 uVar4;
  uint uVar5;
  undefined4 *puVar6;
  uint uVar7;
  DWORD local_38;
  int *local_34;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  uint local_20;
  
  local_20 = DAT_404303e4;
  iVar1 = FUN_404027c0();
  if (iVar1 == 0) {
    FUN_4042f4c4(local_20);
    iVar1 = -0x7ffbfe10;
  }
  else {
    pvVar2 = TlsGetValue(DAT_40430490);
    uVar5 = *(uint *)((int)pvVar2 + 4);
    if (param_4 == 0) {
      if ((((param_3 & 0xffffffe0) == 0) && (param_5 != 0)) && (param_6 != (undefined4 *)0x0)) {
        uVar7 = 0;
        if (param_5 != 0) {
          puVar6 = param_6 + 2;
          do {
            if ((puVar6[-1] != 0) || (puVar6[-2] == 0)) goto LAB_40409b34;
            uVar7 = uVar7 + 1;
            *puVar6 = 0x80004002;
            puVar6 = puVar6 + 3;
          } while (uVar7 < param_5);
        }
        local_30 = *param_1;
        local_2c = param_1[1];
        local_28 = param_1[2];
        local_24 = param_1[3];
        piVar3 = (int *)FUN_40403820(&local_30,&DAT_40402244,0,0,param_3,(uint)((uVar5 & 0x80) == 0)
                                     ,&local_38);
        if (piVar3 != (int *)0x0) {
          local_38 = (**(code **)(*piVar3 + 0xc))(piVar3,param_2,*param_6,&local_34);
          (**(code **)(*piVar3 + 8))(piVar3);
          if (-1 < (int)local_38) {
            if (param_5 != 0) {
              puVar6 = param_6 + 2;
              uVar5 = param_5;
              do {
                uVar4 = (**(code **)*local_34)(local_34,puVar6[-2],puVar6 + -1);
                uVar5 = uVar5 - 1;
                *puVar6 = uVar4;
                puVar6 = puVar6 + 3;
              } while (uVar5 != 0);
            }
            (**(code **)(*local_34 + 8))();
          }
        }
        iVar1 = FUN_40409744(local_38,param_5,(int)param_6);
      }
      else {
LAB_40409b34:
        iVar1 = -0x7ff8ffa9;
      }
      FUN_4042f4c4(local_20);
    }
    else {
      FUN_4042f4c4(local_20);
      iVar1 = -0x7ff8ffa9;
    }
  }
  return iVar1;
}



/* 40409b68 FUN_40409b68 */

/* Boundary evidence: original MIPS .pdata 40409b68..40409bc7. Semantic name remains unreviewed. */

undefined4 FUN_40409b68(void)

{
  return 1;
}



/* 40409bc8 FUN_40409bc8 */

/* Boundary evidence: original MIPS .pdata 40409bc8..40409bd3. Semantic name remains unreviewed. */

undefined4 FUN_40409bc8(void)

{
  return 1;
}



/* 40409bd4 FUN_40409bd4 */

/* Boundary evidence: original MIPS .pdata 40409bd4..40409c27. Semantic name remains unreviewed. */

void FUN_40409bd4(size_t *param_1,wchar_t *param_2,void *param_3)

{
  size_t sVar1;
  
  sVar1 = wcslen(param_2);
  FUN_40414fd0(param_1,(byte *)param_2,sVar1 << 1,param_3);
  return;
}



/* 40409c28 FUN_40409c28 */

/* Boundary evidence: original MIPS .pdata 40409c28..40409cff. Semantic name remains unreviewed. */

void FUN_40409c28(int *param_1,int *param_2,undefined4 *param_3)

{
  int iVar1;
  
  *param_3 = 0;
  iVar1 = FUN_4040397c(param_2,&DAT_404021c4);
  if ((iVar1 != 0) || (iVar1 = FUN_4040397c(param_2,(int *)&DAT_40402254), iVar1 != 0)) {
    (**(code **)(*param_1 + 4))(param_1);
    *param_3 = param_1;
  }
  return;
}



/* 40409d00 FUN_40409d00 */

/* Boundary evidence: original MIPS .pdata 40409d00..40409d0b. Semantic name remains unreviewed. */

undefined4 FUN_40409d00(void)

{
  return 1;
}



/* 40409d0c FUN_40409d0c */

/* Boundary evidence: original MIPS .pdata 40409d0c..40409d37. Semantic name remains unreviewed. */

LONG FUN_40409d0c(int param_1)

{
  InterlockedIncrement((LONG *)(param_1 + 4));
  return *(LONG *)(param_1 + 4);
}



/* 40409d38 FUN_40409d38 */

/* Boundary evidence: original MIPS .pdata 40409d38..40409deb. Semantic name remains unreviewed. */

undefined4 FUN_40409d38(int param_1,int *param_2)

{
  int iVar1;
  undefined4 *puVar2;
  
  if (param_2 != (int *)0x0) {
    iVar1 = FUN_40409b68();
    if (iVar1 == 0) {
      return 0x80070057;
    }
    puVar2 = LocalAlloc(0,8);
    if (puVar2 == (undefined4 *)0x0) {
      puVar2 = (undefined4 *)0x0;
    }
    else {
      *puVar2 = param_2;
      puVar2[1] = 0;
    }
    if (puVar2 == (undefined4 *)0x0) {
      return 0x8007000e;
    }
    (**(code **)(*param_2 + 4))(param_2);
    puVar2[1] = *(undefined4 *)(param_1 + 0x28);
    *(undefined4 **)(param_1 + 0x28) = puVar2;
  }
  return 0;
}



/* 40409dec FUN_40409dec */

/* Boundary evidence: original MIPS .pdata 40409dec..40409e47. Semantic name remains unreviewed. */

int * FUN_40409dec(int *param_1,uint param_2)

{
  if ((int *)*param_1 != (int *)0x0) {
    (**(code **)(*(int *)*param_1 + 8))();
  }
  if ((param_2 & 1) != 0) {
    LocalFree(param_1);
  }
  return param_1;
}



/* 40409e48 FUN_40409e48 */

/* Boundary evidence: original MIPS .pdata 40409e48..40409e8b. Semantic name remains unreviewed. */

undefined4 FUN_40409e48(int param_1)

{
  int *piVar1;
  int *piVar2;
  
  piVar1 = *(int **)(param_1 + 0x28);
  *(undefined4 *)(param_1 + 0x28) = 0;
  while (piVar1 != (int *)0x0) {
    piVar2 = (int *)piVar1[1];
    FUN_40409dec(piVar1,1);
    piVar1 = piVar2;
  }
  return 0;
}



/* 40409e8c FUN_40409e8c */

/* Boundary evidence: original MIPS .pdata 40409e8c..40409f07. Semantic name remains unreviewed. */

void FUN_40409e8c(int param_1,uint *param_2)

{
  if (*param_2 < 0x21) {
    memcpy((void *)(param_1 + 8),param_2,*param_2);
  }
  return;
}



/* 40409f08 FUN_40409f08 */

/* Boundary evidence: original MIPS .pdata 40409f08..40409f13. Semantic name remains unreviewed. */

undefined4 FUN_40409f08(void)

{
  return 1;
}



/* 40409f14 FUN_40409f14 */

/* Boundary evidence: original MIPS .pdata 40409f14..40409fb7. Semantic name remains unreviewed. */

void FUN_40409f14(int param_1,uint *param_2)

{
  uint *_Src;
  uint _Size;
  uint uVar1;
  uint local_30 [8];
  
  uVar1 = *param_2;
  _Src = (uint *)(param_1 + 8);
  _Size = *_Src;
  if (uVar1 < *_Src) {
    memcpy(local_30,_Src,0x20);
    _Src = local_30;
    _Size = uVar1;
    local_30[0] = uVar1;
  }
  memcpy(param_2,_Src,_Size);
  return;
}



/* 40409fb8 FUN_40409fb8 */

/* Boundary evidence: original MIPS .pdata 40409fb8..40409fc3. Semantic name remains unreviewed. */

undefined4 FUN_40409fb8(void)

{
  return 1;
}



/* 40409fc4 FUN_40409fc4 */

/* Boundary evidence: original MIPS .pdata 40409fc4..4040a10f. Semantic name remains unreviewed. */

undefined4 FUN_40409fc4(int param_1,wchar_t *param_2,int *param_3)

{
  BOOL BVar1;
  int iVar2;
  undefined4 *puVar3;
  size_t sVar4;
  size_t *psVar5;
  int *local_20 [2];
  
  if (((param_2 != (wchar_t *)0x0) && (BVar1 = IsBadReadPtr(param_2,2), BVar1 != 0)) ||
     (iVar2 = FUN_40409b68(), iVar2 == 0)) {
    return 0x80070057;
  }
  if (*(size_t **)(param_1 + 0x2c) == (size_t *)0x0) {
    puVar3 = LocalAlloc(0,0x28);
    if (puVar3 == (undefined4 *)0x0) {
      puVar3 = (undefined4 *)0x0;
    }
    else {
      FUN_40414840(puVar3,4,0,10,0,0x11);
    }
    *(undefined4 **)(param_1 + 0x2c) = puVar3;
    if (puVar3 == (undefined4 *)0x0) {
      return 0x8007000e;
    }
  }
  else {
    iVar2 = FUN_40409bd4(*(size_t **)(param_1 + 0x2c),param_2,local_20);
    if (iVar2 != 0) {
      (**(code **)(*local_20[0] + 8))();
    }
  }
  psVar5 = *(size_t **)(param_1 + 0x2c);
  local_20[0] = param_3;
  sVar4 = wcslen(param_2);
  iVar2 = FUN_40415018(psVar5,(byte *)param_2,sVar4 << 1,local_20);
  if (iVar2 == 0) {
    return 0x8007000e;
  }
  (**(code **)(*param_3 + 4))(param_3);
  return 0;
}



/* 4040a110 FUN_4040a110 */

/* Boundary evidence: original MIPS .pdata 4040a110..4040a1df. Semantic name remains unreviewed. */

undefined4 FUN_4040a110(int param_1,wchar_t *param_2,undefined4 *param_3)

{
  BOOL BVar1;
  undefined4 uVar2;
  int iVar3;
  int *local_18 [2];
  
  BVar1 = IsBadWritePtr(param_3,4);
  if ((BVar1 == 0) &&
     ((*param_3 = 0, param_2 == (wchar_t *)0x0 || (BVar1 = IsBadReadPtr(param_2,2), BVar1 == 0)))) {
    local_18[0] = (int *)*param_3;
    if ((*(size_t **)(param_1 + 0x2c) == (size_t *)0x0) ||
       (iVar3 = FUN_40409bd4(*(size_t **)(param_1 + 0x2c),param_2,local_18), iVar3 == 0)) {
      uVar2 = 0x80004005;
    }
    else {
      *param_3 = local_18[0];
      (**(code **)(*local_18[0] + 4))();
      uVar2 = 0;
    }
  }
  else {
    uVar2 = 0x80070057;
  }
  return uVar2;
}



/* 4040a1e0 FUN_4040a1e0 */

/* Boundary evidence: original MIPS .pdata 4040a1e0..4040a233. Semantic name remains unreviewed. */

undefined4 FUN_4040a1e0(undefined4 param_1,undefined4 *param_2)

{
  BOOL BVar1;
  undefined4 uVar2;
  
  BVar1 = IsBadWritePtr(param_2,4);
  if (BVar1 == 0) {
    *param_2 = 0;
    uVar2 = 0x80004001;
  }
  else {
    uVar2 = 0x80070057;
  }
  return uVar2;
}



/* 4040a234 FUN_4040a234 */

/* Boundary evidence: original MIPS .pdata 4040a234..4040a2f7. Semantic name remains unreviewed. */

undefined4 FUN_4040a234(int param_1,wchar_t *param_2)

{
  BOOL BVar1;
  undefined4 uVar2;
  int iVar3;
  size_t sVar4;
  int *local_18 [2];
  
  if ((param_2 == (wchar_t *)0x0) || (BVar1 = IsBadReadPtr(param_2,2), BVar1 == 0)) {
    if ((*(size_t **)(param_1 + 0x2c) != (size_t *)0x0) &&
       (iVar3 = FUN_40409bd4(*(size_t **)(param_1 + 0x2c),param_2,local_18), iVar3 != 0)) {
      iVar3 = *(int *)(param_1 + 0x2c);
      sVar4 = wcslen(param_2);
      iVar3 = FUN_40414c14(iVar3,(byte *)param_2,sVar4 << 1);
      if (iVar3 != 0) {
        (**(code **)(*local_18[0] + 8))();
        return 0;
      }
    }
    uVar2 = 0x80004005;
  }
  else {
    uVar2 = 0x80070057;
  }
  return uVar2;
}



/* 4040a2f8 FUN_4040a2f8 */

/* Boundary evidence: original MIPS .pdata 4040a2f8..4040a3a3. Semantic name remains unreviewed. */

undefined4 FUN_4040a2f8(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  int *piVar4;
  int *piVar5;
  
  iVar1 = FUN_40409b68();
  if (iVar1 == 0) {
    uVar2 = 0x80070057;
  }
  else {
    piVar4 = *(int **)(param_1 + 0x28);
    piVar5 = (int *)0x0;
    if (*(int **)(param_1 + 0x28) != (int *)0x0) {
      do {
        piVar3 = piVar4;
        piVar4 = piVar3;
        if (*piVar3 == param_2) break;
        piVar4 = (int *)piVar3[1];
        piVar5 = piVar3;
      } while (piVar4 != (int *)0x0);
      if (piVar4 != (int *)0x0) {
        if (piVar5 == (int *)0x0) {
          *(int *)(param_1 + 0x28) = piVar4[1];
        }
        else {
          piVar5[1] = piVar4[1];
        }
        FUN_40409dec(piVar4,1);
        return 0;
      }
    }
    uVar2 = 0x800401e9;
  }
  return uVar2;
}



/* 4040a3a4 FUN_4040a3a4 */

/* Boundary evidence: original MIPS .pdata 4040a3a4..4040a41b. Semantic name remains unreviewed. */

undefined4 * FUN_4040a3a4(undefined4 *param_1)

{
  LCID LVar1;
  
  *param_1 = &PTR_FUN_4040180c;
  param_1[1] = 1;
  param_1[7] = 0x15;
  param_1[10] = 0;
  param_1[2] = 0x20;
  param_1[3] = 0;
  param_1[4] = 2;
  param_1[5] = 0;
  param_1[6] = 0;
  LVar1 = GetUserDefaultLCID();
  param_1[8] = LVar1;
  param_1[9] = 0;
  param_1[0xb] = 0;
  return param_1;
}



/* 4040a41c FUN_4040a41c */

/* Boundary evidence: original MIPS .pdata 4040a41c..4040a4db. Semantic name remains unreviewed. */

void FUN_4040a41c(undefined4 *param_1)

{
  HLOCAL hMem;
  int local_18;
  int *local_14;
  int aiStack_10 [2];
  
  *param_1 = &PTR_FUN_4040180c;
  FUN_40409e48((int)param_1);
  if (param_1[0xb] != 0) {
    if (*(int *)(param_1[0xb] + 0x18) == 0) {
      local_18 = 0;
    }
    else {
      local_18 = -1;
      do {
        FUN_40414940((size_t *)param_1[0xb],&local_18,aiStack_10,(size_t *)0x0,&local_14);
        if (local_14 != (int *)0x0) {
          (**(code **)(*local_14 + 8))();
        }
      } while (local_18 != 0);
    }
    hMem = (HLOCAL)param_1[0xb];
    if (hMem != (HLOCAL)0x0) {
      FUN_40414d68((int)hMem);
      LocalFree(hMem);
    }
  }
  return;
}



/* 4040a4dc FUN_4040a4dc */

/* Boundary evidence: original MIPS .pdata 4040a4dc..4040a517. Semantic name remains unreviewed. */

undefined4 * FUN_4040a4dc(void)

{
  undefined4 *puVar1;
  
  puVar1 = LocalAlloc(0,0x30);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    puVar1 = FUN_4040a3a4(puVar1);
  }
  return puVar1;
}



/* 4040a518 FUN_4040a518 */

/* Boundary evidence: original MIPS .pdata 4040a518..4040a56f. Semantic name remains unreviewed. */

int FUN_4040a518(undefined4 *param_1)

{
  LONG LVar1;
  int iVar2;
  
  iVar2 = param_1[1] + -1;
  LVar1 = InterlockedDecrement(param_1 + 1);
  if (LVar1 == 0) {
    FUN_4040a41c(param_1);
    LocalFree(param_1);
    iVar2 = 0;
  }
  return iVar2;
}



/* 4040a570 FUN_4040a570 */

/* Boundary evidence: original MIPS .pdata 4040a570..4040a5cb. Semantic name remains unreviewed. */

void FUN_4040a570(int param_1,int param_2,int param_3,undefined *param_4)

{
  while (param_3 = param_3 + -1, -1 < param_3) {
    (*(code *)param_4)(param_1);
    param_1 = param_1 + param_2;
  }
  return;
}



/* 4040a5cc FUN_4040a5cc */

/* Boundary evidence: original MIPS .pdata 4040a5cc..4040a637. Semantic name remains unreviewed. */

void FUN_4040a5cc(int param_1,int param_2,int param_3,undefined *param_4)

{
  int iVar1;
  
  iVar1 = param_2 * param_3 + param_1;
  while (param_3 = param_3 + -1, -1 < param_3) {
    iVar1 = iVar1 - param_2;
    (*(code *)param_4)(iVar1);
  }
  return;
}



/* 4040a638 FUN_4040a638 */

/* Boundary evidence: original MIPS .pdata 4040a638..4040a65b. Semantic name remains unreviewed. */

void FUN_4040a638(SIZE_T param_1)

{
  FUN_40415118(&PTR_PTR_40430324,param_1);
  return;
}



/* 4040a65c FUN_4040a65c */

/* Boundary evidence: original MIPS .pdata 4040a65c..4040a687. Semantic name remains unreviewed. */

void FUN_4040a65c(LPVOID param_1)

{
  if (param_1 != (LPVOID)0x0) {
    FUN_40415154(&PTR_PTR_40430324,param_1);
  }
  return;
}



/* 4040a688 FUN_4040a688 */

/* Boundary evidence: original MIPS .pdata 4040a688..4040a6af. Semantic name remains unreviewed. */

void FUN_4040a688(undefined4 param_1,LPVOID param_2)

{
  if (param_2 != (LPVOID)0x0) {
    FUN_40415170(&PTR_PTR_40430324,param_2);
  }
  return;
}



/* 4040a6c4 FUN_4040a6c4 */

/* Boundary evidence: original MIPS .pdata 4040a6c4..4040a703. Semantic name remains unreviewed. */

int FUN_4040a6c4(void)

{
  int iVar1;
  undefined1 auStack_10 [8];
  
  if ((DAT_4043049c != 0) || (iVar1 = (*(code *)PTR_FUN_40430320)(auStack_10), -1 < iVar1)) {
    iVar1 = 0;
  }
  return iVar1;
}



/* 4040a704 FUN_4040a704 */

/* Boundary evidence: original MIPS .pdata 4040a704..4040a737. Semantic name remains unreviewed. */

void FUN_4040a704(void)

{
  undefined1 auStack_10 [8];
  
  if (DAT_4043049c == 0) {
    (*(code *)PTR_FUN_40430320)(auStack_10);
  }
  return;
}



/* 4040a738 FUN_4040a738 */

/* Boundary evidence: original MIPS .pdata 4040a738..4040a863. Semantic name remains unreviewed. */

DWORD FUN_4040a738(undefined4 *param_1)

{
  HANDLE hHandle;
  DWORD DVar1;
  
  DVar1 = 0;
  if (DAT_4043049c == 0) {
    hHandle = CreateMutexW((LPSECURITY_ATTRIBUTES)0x0,0,L"OleDfSharedMemoryMutex");
    if (hHandle == (HANDLE)0x0) {
      DVar1 = GetLastError();
      if ((int)DVar1 < 1) {
        DVar1 = GetLastError();
      }
      else {
        DVar1 = GetLastError();
        DVar1 = DVar1 & 0xffff | 0x80070000;
      }
    }
    else {
      WaitForSingleObject(hHandle,0xffffffff);
      *param_1 = &PTR_PTR_40430324;
      DAT_404304bc = 0;
      PTR_FUN_40430320 = &LAB_4040a6b0;
      DAT_4043049c = 1;
      DVar1 = 0;
      ReleaseMutex(hHandle);
      CloseHandle(hHandle);
    }
  }
  else {
    *param_1 = &PTR_PTR_40430324;
  }
  return DVar1;
}



/* 4040a864 FUN_4040a864 */

undefined4 FUN_4040a864(void)

{
  return 0x80004005;
}



/* 4040a870 FUN_4040a870 */

/* Boundary evidence: original MIPS .pdata 4040a870..4040a93f. Semantic name remains unreviewed. */

uint FUN_4040a870(int param_1,undefined4 param_2,int param_3,LONG param_4,LPVOID param_5,
                 DWORD param_6,LPDWORD param_7)

{
  DWORD DVar1;
  BOOL BVar2;
  uint uVar3;
  LONG local_18 [2];
  
  *param_7 = 0;
  local_18[0] = param_4;
  if (*(int *)(param_1 + 0x48) != param_3) {
    DVar1 = SetFilePointer(*(HANDLE *)(param_1 + 0x14),param_3,local_18,0);
    if (DVar1 == 0xffffffff) goto LAB_4040a8f8;
    *(int *)(param_1 + 0x48) = param_3;
  }
  BVar2 = ReadFile(*(HANDLE *)(param_1 + 0x14),param_5,param_6,param_7,(LPOVERLAPPED)0x0);
  if (BVar2 != 0) {
    *(DWORD *)(param_1 + 0x48) = *param_7 + param_3;
    return 0;
  }
LAB_4040a8f8:
  DVar1 = GetLastError();
  uVar3 = FUN_4040cfd8(DVar1);
  return uVar3;
}



/* 4040a940 FUN_4040a940 */

/* Boundary evidence: original MIPS .pdata 4040a940..4040aa0f. Semantic name remains unreviewed. */

uint FUN_4040a940(int param_1,undefined4 param_2,int param_3,LONG param_4,LPCVOID param_5,
                 DWORD param_6,LPDWORD param_7)

{
  DWORD DVar1;
  BOOL BVar2;
  uint uVar3;
  LONG local_18 [2];
  
  *param_7 = 0;
  local_18[0] = param_4;
  if (*(int *)(param_1 + 0x48) != param_3) {
    DVar1 = SetFilePointer(*(HANDLE *)(param_1 + 0x14),param_3,local_18,0);
    if (DVar1 == 0xffffffff) goto LAB_4040a9c8;
    *(int *)(param_1 + 0x48) = param_3;
  }
  BVar2 = WriteFile(*(HANDLE *)(param_1 + 0x14),param_5,param_6,param_7,(LPOVERLAPPED)0x0);
  if (BVar2 != 0) {
    *(DWORD *)(param_1 + 0x48) = *param_7 + param_3;
    return 0;
  }
LAB_4040a9c8:
  DVar1 = GetLastError();
  uVar3 = FUN_4040cfd8(DVar1);
  return uVar3;
}



/* 4040aa10 OleSetMenuDescriptor */

HRESULT OleSetMenuDescriptor
                  (HOLEMENU holemenu,HWND hwndFrame,HWND hwndActiveObject,LPOLEINPLACEFRAME lpFrame,
                  LPOLEINPLACEACTIVEOBJECT lpActiveObj)

{
                    /* 0xaa10  27  OleSetMenuDescriptor */
  return 0;
}



/* 4040aa18 FUN_4040aa18 */

/* Boundary evidence: original MIPS .pdata 4040aa18..4040aa67. Semantic name remains unreviewed. */

uint FUN_4040aa18(int param_1)

{
  BOOL BVar1;
  DWORD DVar2;
  uint uVar3;
  
  BVar1 = FlushFileBuffers(*(HANDLE *)(param_1 + 0x10));
  if (BVar1 == 0) {
    DVar2 = GetLastError();
    uVar3 = FUN_4040cfd8(DVar2);
  }
  else {
    uVar3 = 0;
  }
  return uVar3;
}



/* 4040aa68 FUN_4040aa68 */

/* Boundary evidence: original MIPS .pdata 4040aa68..4040ab0b. Semantic name remains unreviewed. */

uint FUN_4040aa68(int param_1,undefined4 param_2,int param_3,LONG param_4)

{
  DWORD DVar1;
  BOOL BVar2;
  uint uVar3;
  LONG local_18 [2];
  
  local_18[0] = param_4;
  if (*(int *)(param_1 + 0x48) != param_3) {
    DVar1 = SetFilePointer(*(HANDLE *)(param_1 + 0x14),param_3,local_18,0);
    if (DVar1 == 0xffffffff) goto LAB_4040aad4;
    *(int *)(param_1 + 0x48) = param_3;
  }
  BVar2 = SetEndOfFile(*(HANDLE *)(param_1 + 0x14));
  if (BVar2 != 0) {
    return 0;
  }
LAB_4040aad4:
  DVar1 = GetLastError();
  uVar3 = FUN_4040cfd8(DVar1);
  return uVar3;
}



/* 4040ab18 FUN_4040ab18 */

/* Boundary evidence: original MIPS .pdata 4040ab18..4040ab87. Semantic name remains unreviewed. */

uint FUN_4040ab18(int param_1,DWORD *param_2)

{
  DWORD DVar1;
  uint uVar2;
  
  uVar2 = 0;
  DVar1 = GetFileSize(*(HANDLE *)(param_1 + 0x10),param_2 + 1);
  *param_2 = DVar1;
  if (DVar1 == 0xffffffff) {
    DVar1 = GetLastError();
    uVar2 = FUN_4040cfd8(DVar1);
  }
  return uVar2;
}



/* 4040ab88 FUN_4040ab88 */

/* Boundary evidence: original MIPS .pdata 4040ab88..4040ac1b. Semantic name remains unreviewed. */

uint FUN_4040ab88(int param_1,int param_2,DWORD param_3,DWORD param_4)

{
  BOOL BVar1;
  DWORD DVar2;
  FILETIME *lpLastAccessTime;
  FILETIME *lpLastWriteTime;
  FILETIME *lpCreationTime;
  uint uVar3;
  FILETIME local_res8;
  
  uVar3 = 0;
  lpCreationTime = (FILETIME *)0x0;
  lpLastAccessTime = (FILETIME *)0x0;
  lpLastWriteTime = (FILETIME *)0x0;
  if (param_2 == 0) {
    lpCreationTime = &local_res8;
  }
  else if (param_2 == 1) {
    lpLastWriteTime = &local_res8;
  }
  else {
    lpLastAccessTime = &local_res8;
  }
  local_res8.dwLowDateTime = param_3;
  local_res8.dwHighDateTime = param_4;
  BVar1 = SetFileTime(*(HANDLE *)(param_1 + 0x14),lpCreationTime,lpLastAccessTime,lpLastWriteTime);
  if (BVar1 == 0) {
    DVar2 = GetLastError();
    uVar3 = FUN_4040cfd8(DVar2);
  }
  return uVar3;
}



/* 4040ac1c FUN_4040ac1c */

/* Boundary evidence: original MIPS .pdata 4040ac1c..4040ac8b. Semantic name remains unreviewed. */

uint FUN_4040ac1c(int param_1,DWORD param_2,DWORD param_3,DWORD param_4)

{
  BOOL BVar1;
  DWORD DVar2;
  uint uVar3;
  FILETIME local_res4;
  DWORD local_resc;
  
  uVar3 = 0;
  local_res4.dwLowDateTime = param_2;
  local_res4.dwHighDateTime = param_3;
  local_resc = param_4;
  BVar1 = SetFileTime(*(HANDLE *)(param_1 + 0x14),(FILETIME *)&stack0x00000014,&local_res4,
                      (FILETIME *)&local_resc);
  if (BVar1 == 0) {
    DVar2 = GetLastError();
    uVar3 = FUN_4040cfd8(DVar2);
  }
  return uVar3;
}



/* 4040ac8c FUN_4040ac8c */

/* Boundary evidence: original MIPS .pdata 4040ac8c..4040b087. Semantic name remains unreviewed. */

uint FUN_4040ac8c(int param_1,wchar_t *param_2,int param_3)

{
  size_t sVar1;
  HANDLE pvVar2;
  wchar_t *pwVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  DWORD dwCreationDisposition;
  int iVar7;
  DWORD dwDesiredAccess;
  DWORD DVar8;
  DWORD local_240;
  WCHAR aWStack_238 [262];
  uint local_2c;
  
  local_2c = DAT_404303e4;
  *(undefined4 *)(param_1 + 0x48) = 0xffffffff;
  iVar7 = DAT_404304bc;
  if (*(int *)(param_1 + 0x14) == -1) {
    iVar5 = *(int *)(param_1 + 0x10) + DAT_404304bc;
    pwVar3 = (wchar_t *)(iVar5 + 8);
    if (*pwVar3 == L'\0') {
      uVar6 = *(uint *)(iVar5 + 0x218);
      if (param_2 == (wchar_t *)0x0) {
        local_240 = GetTickCount();
        wsprintfW(aWStack_238,L"Docfile%d",local_240);
        iVar7 = DAT_404304bc;
        goto LAB_4040ad8c;
      }
      sVar1 = wcslen(param_2);
      if (sVar1 < 0x105) {
        wcscpy(aWStack_238,param_2);
        goto LAB_4040ad8c;
      }
      uVar6 = 0x800300fc;
    }
    else {
      wcscpy(aWStack_238,pwVar3);
      uVar6 = 0;
LAB_4040ad8c:
      DVar8 = 1;
      if ((uVar6 & 0x20) == 0) {
        if ((uVar6 & 4) == 0) {
          dwCreationDisposition = 5;
          if ((uVar6 & 2) == 0) {
            dwCreationDisposition = 3;
          }
        }
        else if ((uVar6 & 2) == 0) {
          dwCreationDisposition = 1;
        }
        else {
          dwCreationDisposition = 2;
        }
      }
      else {
        dwCreationDisposition = 4;
      }
      uVar4 = *(uint *)(*(int *)(param_1 + 0x10) + iVar7 + 0x214);
      uVar6 = uVar4 & 0x80;
      dwDesiredAccess = 0x80000000;
      if (uVar6 != 0) {
        dwDesiredAccess = 0xc0000000;
      }
      if (((uVar4 & 0x200) == 0) || (uVar6 != 0)) {
        DVar8 = 3;
      }
      if (((param_3 == 0) || (uVar6 != 0)) || ((uVar4 & 0x100) == 0)) {
LAB_4040aeb4:
        pvVar2 = CreateFileW(aWStack_238,dwDesiredAccess,DVar8,(LPSECURITY_ATTRIBUTES)0x0,
                             dwCreationDisposition,0x80,(HANDLE)0x0);
        *(HANDLE *)(param_1 + 0x14) = pvVar2;
        if (pvVar2 == (HANDLE)0xffffffff) {
          uVar6 = GetLastError();
          if ((uVar6 != 0xb7) && (uVar6 != 0x50)) goto LAB_4040ae84;
          if ((*(short *)(*(int *)(param_1 + 0x10) + DAT_404304bc + 8) != 0) ||
             (param_2 != (wchar_t *)0x0)) goto LAB_4040b008;
          iVar7 = local_240 + 1;
          StringCchPrintfW(aWStack_238,0x105,L"Docfile%d",iVar7);
          pvVar2 = CreateFileW(aWStack_238,dwDesiredAccess,DVar8,(LPSECURITY_ATTRIBUTES)0x0,
                               dwCreationDisposition,0x10000080,(HANDLE)0x0);
          *(HANDLE *)(param_1 + 0x14) = pvVar2;
          while (pvVar2 == (HANDLE)0xffffffff) {
            uVar6 = GetLastError();
            if ((uVar6 != 0xb7) && (uVar6 != 0x50)) goto LAB_4040b010;
            iVar7 = iVar7 + 1;
            StringCchPrintfW(aWStack_238,0x105,L"Docfile%d",iVar7);
            pvVar2 = CreateFileW(aWStack_238,dwDesiredAccess,DVar8,(LPSECURITY_ATTRIBUTES)0x0,
                                 dwCreationDisposition,0x10000080,(HANDLE)0x0);
            *(HANDLE *)(param_1 + 0x14) = pvVar2;
          }
        }
        pwVar3 = (wchar_t *)(*(int *)(param_1 + 0x10) + DAT_404304bc + 8);
        if (*pwVar3 == L'\0') {
          wcscpy(pwVar3,aWStack_238);
        }
        goto LAB_4040b048;
      }
      pvVar2 = CreateFileW(aWStack_238,0x80000000,0,(LPSECURITY_ATTRIBUTES)0x0,dwCreationDisposition
                           ,0x10000080,(HANDLE)0x0);
      *(HANDLE *)(param_1 + 0x14) = pvVar2;
      if (pvVar2 != (HANDLE)0xffffffff) {
        CloseHandle(pvVar2);
        goto LAB_4040aeb4;
      }
      DVar8 = GetLastError();
      if (DVar8 == 0xb7) {
LAB_4040b008:
        uVar6 = 0x80030050;
      }
      else {
        uVar6 = GetLastError();
LAB_4040ae84:
        uVar6 = FUN_4040cfd8(uVar6);
      }
    }
LAB_4040b010:
    FUN_4042f4c4(local_2c);
  }
  else {
LAB_4040b048:
    FUN_4042f4c4(local_2c);
    uVar6 = 0;
  }
  return uVar6;
}



/* 4040b088 FUN_4040b088 */

/* Boundary evidence: original MIPS .pdata 4040b088..4040b18f. Semantic name remains unreviewed. */

uint FUN_4040b088(int param_1,undefined4 *param_2,uint param_3)

{
  DWORD DVar1;
  BOOL BVar2;
  uint uVar3;
  
  DVar1 = GetFileSize(*(HANDLE *)(param_1 + 0x14),param_2 + 3);
  param_2[2] = DVar1;
  if ((DVar1 == 0xffffffff) ||
     (BVar2 = GetFileTime(*(HANDLE *)(param_1 + 0x14),(LPFILETIME)(param_2 + 6),
                          (LPFILETIME)(param_2 + 8),(LPFILETIME)(param_2 + 4)), BVar2 == 0)) {
    DVar1 = GetLastError();
    uVar3 = FUN_4040cfd8(DVar1);
  }
  else {
    (**(code **)(*(int *)(param_1 + 4) + 0x18))((int *)(param_1 + 4),param_2 + 0xb);
    param_2[1] = 3;
    uVar3 = FUN_4040cba8(*(uint *)(*(int *)(param_1 + 0x10) + DAT_404304bc + 0x214));
    param_2[10] = uVar3;
    *param_2 = 0;
    if (((param_3 & 1) != 0) || (uVar3 = FUN_4040c54c(param_1,param_2), -1 < (int)uVar3)) {
      uVar3 = 0;
    }
  }
  return uVar3;
}



/* 4040b190 FUN_4040b190 */

/* Boundary evidence: original MIPS .pdata 4040b190..4040b21b. Semantic name remains unreviewed. */

void FUN_4040b190(int param_1)

{
  if (*(HANDLE *)(param_1 + 0x14) != (HANDLE)0xffffffff) {
    CloseHandle(*(HANDLE *)(param_1 + 0x14));
  }
  *(undefined4 *)(param_1 + 0x14) = 0xffffffff;
  if (*(HANDLE *)(param_1 + 0x18) != (HANDLE)0xffffffff) {
    CloseHandle(*(HANDLE *)(param_1 + 0x18));
  }
  *(undefined4 *)(param_1 + 0x18) = 0xffffffff;
  DeleteFileW((LPCWSTR)(*(int *)(param_1 + 0x10) + DAT_404304bc + 8));
  return;
}



/* 4040b21c FUN_4040b21c */

/* Boundary evidence: original MIPS .pdata 4040b21c..4040b33b. Semantic name remains unreviewed. */

void FUN_4040b21c(undefined4 *param_1)

{
  LPVOID pvVar1;
  int iVar2;
  
  *param_1 = &PTR_LAB_404018c8;
  param_1[1] = &PTR_LAB_404018a8;
  param_1[7] = 0x74536c46;
  if ((HANDLE)param_1[5] != (HANDLE)0xffffffff) {
    CloseHandle((HANDLE)param_1[5]);
  }
  if ((HANDLE)param_1[6] != (HANDLE)0xffffffff) {
    CloseHandle((HANDLE)param_1[6]);
    param_1[6] = 0xffffffff;
  }
  if (param_1[4] != 0) {
    FUN_4040d430((int *)(param_1[4] + DAT_404304bc),(int)(param_1 + 2));
    iVar2 = param_1[4] + DAT_404304bc;
    if (((*(LPCWSTR)(iVar2 + 8) != L'\0') && (*(int *)(iVar2 + 4) == 1)) &&
       ((*(uint *)(iVar2 + 0x218) & 0x10) != 0)) {
      DeleteFileW((LPCWSTR)(iVar2 + 8));
    }
    pvVar1 = (LPVOID)(param_1[4] + DAT_404304bc);
    iVar2 = *(int *)((int)pvVar1 + 4) + -1;
    *(int *)((int)pvVar1 + 4) = iVar2;
    if (iVar2 == 0) {
      FUN_4040a65c(pvVar1);
    }
  }
  return;
}



/* 4040b378 FUN_4040b378 */

/* Boundary evidence: original MIPS .pdata 4040b378..4040b72b. Semantic name remains unreviewed. */

uint FUN_4040b378(int param_1,wchar_t *param_2,undefined4 param_3,DWORD param_4,LPVOID param_5)

{
  size_t sVar1;
  DWORD DVar2;
  BOOL BVar3;
  uint uVar4;
  int iVar5;
  wchar_t *_Source;
  int *piVar6;
  HANDLE hFile;
  uint uVar7;
  DWORD local_448;
  DWORD local_444;
  wchar_t awStack_440 [260];
  wchar_t awStack_238 [260];
  uint local_30;
  
  local_30 = DAT_404303e4;
  if (*(int *)(DAT_404304bc + *(int *)(param_1 + 0xc) + 4) == 1) {
    DVar2 = SetFilePointer(*(HANDLE *)(param_1 + 0x10),0,(PLONG)0x0,0);
    if (DVar2 == 0xffffffff) {
      DVar2 = GetLastError();
      uVar4 = FUN_4040cfd8(DVar2);
    }
    else {
      *(undefined4 *)(param_1 + 0x44) = 0;
      iVar5 = DAT_404304bc + *(int *)(param_1 + 0xc);
      _Source = (wchar_t *)(iVar5 + 8);
      wcscpy(awStack_440,_Source);
      uVar7 = *(uint *)(iVar5 + 0x218);
      hFile = *(HANDLE *)(param_1 + 0x10);
      *_Source = L'\0';
      *(undefined4 *)(param_1 + 0x10) = 0xffffffff;
      *(uint *)(DAT_404304bc + *(int *)(param_1 + 0xc) + 0x218) = uVar7 & 0xffffffcc | 4;
      if (*(HANDLE *)(param_1 + 0x14) != (HANDLE)0xffffffff) {
        CloseHandle(*(HANDLE *)(param_1 + 0x14));
        *(undefined4 *)(param_1 + 0x14) = 0xffffffff;
      }
      sVar1 = wcslen(param_2);
      if (sVar1 < 0x104) {
        wcscpy(awStack_238,param_2);
        piVar6 = (int *)(param_1 + -4);
        uVar4 = FUN_4040ac8c((int)piVar6,awStack_238,1);
        if (-1 < (int)uVar4) {
          uVar4 = (**(code **)(*piVar6 + 0x18))(piVar6);
          if (-1 < (int)uVar4) {
            DVar2 = SetFilePointer(*(HANDLE *)(param_1 + 0x10),0,(PLONG)0x0,0);
            if (DVar2 != 0xffffffff) {
              *(undefined4 *)(param_1 + 0x44) = 0;
              iVar5 = ReadFile(hFile,param_5,param_4,&local_448,(LPOVERLAPPED)0x0);
              while (iVar5 != 0) {
                if (local_448 == 0) {
                  CloseHandle(hFile);
                  if ((uVar7 & 0x10) != 0) {
                    DeleteFileW(awStack_440);
                  }
                  DVar2 = SetFilePointer(*(HANDLE *)(param_1 + 0x10),0,(PLONG)0x0,1);
                  *(DWORD *)(param_1 + 0x44) = DVar2;
                  FUN_4042f4c4(local_30);
                  return 0;
                }
                BVar3 = WriteFile(*(HANDLE *)(param_1 + 0x10),param_5,local_448,&local_444,
                                  (LPOVERLAPPED)0x0);
                if (BVar3 == 0) break;
                if (local_444 != local_448) {
                  uVar4 = 0x8003001d;
                  goto LAB_4040b6f4;
                }
                iVar5 = ReadFile(hFile,param_5,param_4,&local_448,(LPOVERLAPPED)0x0);
              }
            }
            DVar2 = GetLastError();
            uVar4 = FUN_4040cfd8(DVar2);
          }
LAB_4040b6f4:
          CloseHandle(*(HANDLE *)(param_1 + 0x10));
          DeleteFileW((LPCWSTR)(DAT_404304bc + *(int *)(param_1 + 0xc) + 8));
        }
      }
      else {
        uVar4 = 0x800300fc;
      }
      wcscpy((wchar_t *)(DAT_404304bc + *(int *)(param_1 + 0xc) + 8),awStack_440);
      *(HANDLE *)(param_1 + 0x10) = hFile;
      *(uint *)(DAT_404304bc + *(int *)(param_1 + 0xc) + 0x218) = uVar7;
    }
  }
  else {
    uVar4 = 0x80030108;
  }
  DVar2 = SetFilePointer(*(HANDLE *)(param_1 + 0x10),0,(PLONG)0x0,1);
  *(DWORD *)(param_1 + 0x44) = DVar2;
  FUN_4042f4c4(local_30);
  return uVar4;
}



/* 4040b72c FUN_4040b72c */

/* Boundary evidence: original MIPS .pdata 4040b72c..4040b7a7. Semantic name remains unreviewed. */

void FUN_4040b72c(int *param_1,int *param_2)

{
  int iVar1;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  
  iVar1 = (**(code **)(*param_2 + 8))(param_2,&local_10,&local_18,&local_20);
  if (-1 < iVar1) {
    (**(code **)(*param_1 + 0xc))(param_1,local_10,local_c,local_18,local_14,local_20,local_1c);
  }
  return;
}



/* 4040b7a8 FUN_4040b7a8 */

/* Boundary evidence: original MIPS .pdata 4040b7a8..4040b7c3. Semantic name remains unreviewed. */

void FUN_4040b7a8(void)

{
  FUN_404151a8();
  return;
}



/* 4040b7c4 FUN_4040b7c4 */

/* Boundary evidence: original MIPS .pdata 4040b7c4..4040b85b. Semantic name remains unreviewed. */

void FUN_4040b7c4(int param_1)

{
  if ((*(uint *)(param_1 + 0x14) != 0) && (*(int *)(param_1 + 0x18) != 0)) {
    FUN_4040c3fc(*(int **)(param_1 + 0x10),*(uint *)(*(int *)(param_1 + 0x18) + DAT_404304bc + 0xc),
                 *(uint *)(param_1 + 0x14));
  }
  (**(code **)(**(int **)(param_1 + 8) + 8))();
  (**(code **)(**(int **)(param_1 + 0xc) + 8))();
  (**(code **)(**(int **)(param_1 + 0x10) + 8))();
  *(undefined4 *)(param_1 + 8) = 0;
  *(undefined4 *)(param_1 + 0xc) = 0;
  *(undefined4 *)(param_1 + 0x10) = 0;
  return;
}



/* 4040b85c FUN_4040b85c */

/* Boundary evidence: original MIPS .pdata 4040b85c..4040b8db. Semantic name remains unreviewed. */

void FUN_4040b85c(int param_1)

{
  LPVOID pvVar1;
  int iVar2;
  
  if (*(int *)(param_1 + 8) != 0) {
    FUN_4040b7c4(param_1);
  }
  if (*(int *)(param_1 + 0x18) != 0) {
    FUN_4040d430((int *)(*(int *)(param_1 + 0x18) + DAT_404304bc),param_1);
    pvVar1 = (LPVOID)(DAT_404304bc + *(int *)(param_1 + 0x18));
    iVar2 = *(int *)((int)pvVar1 + 4) + -1;
    *(int *)((int)pvVar1 + 4) = iVar2;
    if (iVar2 == 0) {
      FUN_4040a65c(pvVar1);
    }
  }
  return;
}



/* 4040b8dc FUN_4040b8dc */

/* Boundary evidence: original MIPS .pdata 4040b8dc..4040ba5f. Semantic name remains unreviewed. */

int FUN_4040b8dc(int *param_1,uint param_2,uint param_3,int *param_4)

{
  int iVar1;
  uint uVar2;
  
  *param_4 = 0;
  if ((param_2 & 0x40) == 0) {
    iVar1 = (**(code **)(*param_1 + 0x1c))(param_1,param_2,param_3 & 0xffffff80,0,0x11,0,4);
    if (iVar1 < 0) {
      return iVar1;
    }
    *param_4 = 0xffff;
  }
  else {
    iVar1 = (**(code **)(*param_1 + 0x1c))();
    if (iVar1 < 0) {
      return iVar1;
    }
    uVar2 = 0;
    do {
      iVar1 = (**(code **)(*param_1 + 0x1c))(param_1);
      if (-1 < iVar1) {
        *param_4 = uVar2 + 1;
        break;
      }
      uVar2 = uVar2 + 1 & 0xffff;
    } while (uVar2 < 0x10);
    (**(code **)(*param_1 + 0x20))(param_1);
    if (uVar2 == 0x10) {
      return -0x7ffcfffc;
    }
  }
  return 0;
}



/* 4040ba60 FUN_4040ba60 */

/* Boundary evidence: original MIPS .pdata 4040ba60..4040baa3. Semantic name remains unreviewed. */

int FUN_4040ba60(int *param_1,uint param_2,int *param_3)

{
  int iVar1;
  
  iVar1 = FUN_4040b8dc(param_1,param_2,0x7fffffff,param_3);
  if (iVar1 < 0) {
    *param_3 = 0;
  }
  else {
    iVar1 = 0;
  }
  return iVar1;
}



/* 4040baa4 FUN_4040baa4 */

/* Boundary evidence: original MIPS .pdata 4040baa4..4040bb2f. Semantic name remains unreviewed. */

void FUN_4040baa4(int *param_1,uint param_2,uint param_3)

{
  if ((param_3 & 0xffff) != 0) {
    if ((param_2 & 0x40) == 0) {
      (**(code **)(*param_1 + 0x20))(param_1,param_2,0x7fffff80,0,0x11,0,4);
    }
    else {
      (**(code **)(*param_1 + 0x20))(param_1,param_2,(param_3 & 0xffff) - 0x80 & 0x7fffffff,0,1,0,4)
      ;
    }
  }
  return;
}



/* 4040bb30 FUN_4040bb30 */

/* Boundary evidence: original MIPS .pdata 4040bb30..4040c23b. Semantic name remains unreviewed. */

int FUN_4040bb30(int *param_1,uint param_2,int param_3,uint param_4,int *param_5)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  int *local_34;
  uint local_30;
  
  *param_5 = 0;
  iVar1 = (**(code **)(*param_1 + 0x1c))(param_1,param_2,param_4 & 0xffffff92,0,1,0,4);
  iVar3 = -0x94;
  if (iVar1 < 0) {
    return iVar1;
  }
  if (param_3 == 0) {
LAB_4040be28:
    if (((((param_2 & 0x80) == 0) && ((param_2 & 0x40) != 0)) && ((param_2 & 0x200) != 0)) &&
       (((param_2 & 0x100) == 0 &&
        (iVar1 = (**(code **)*param_1)(param_1,&DAT_40402264,&local_34), -1 < iVar1)))) {
      (**(code **)(*local_34 + 8))();
      (**(code **)(*param_1 + 0x20))(param_1);
      *param_5 = 0;
    }
    else {
      uVar2 = 0;
      do {
        local_34 = (int *)(iVar3 + 0x27U & param_4);
        iVar1 = (**(code **)(*param_1 + 0x1c))(param_1);
        if (-1 < iVar1) {
          local_30 = iVar3 + 0x3bU & param_4;
          iVar1 = (**(code **)(*param_1 + 0x1c))(param_1);
          if (-1 < iVar1) {
            iVar1 = (**(code **)(*param_1 + 0x1c))(param_1);
            if (-1 < iVar1) {
              iVar1 = (**(code **)(*param_1 + 0x1c))(param_1);
              if (-1 < iVar1) {
                if (((param_2 & 0x40000) == 0) ||
                   (iVar1 = (**(code **)(*param_1 + 0x1c))(param_1), -1 < iVar1)) break;
                (**(code **)(*param_1 + 0x20))(param_1);
              }
              (**(code **)(*param_1 + 0x20))(param_1);
            }
            (**(code **)(*param_1 + 0x20))(param_1);
          }
          (**(code **)(*param_1 + 0x20))(param_1);
        }
        uVar2 = uVar2 + 1;
        iVar3 = iVar3 + 1;
      } while (uVar2 < 0x14);
      if (0x13 < uVar2) {
        iVar1 = -0x7ffcfffc;
        goto LAB_4040c0c8;
      }
      if ((param_2 & 0x40) == 0) {
        (**(code **)(*param_1 + 0x20))(param_1);
      }
      if ((param_2 & 0x80) == 0) {
        (**(code **)(*param_1 + 0x20))(param_1);
      }
      if ((param_2 & 0x100) == 0) {
        (**(code **)(*param_1 + 0x20))(param_1);
      }
      if (((param_2 & 0x200) == 0) && ((param_2 & 0x40000) == 0)) {
        (**(code **)(*param_1 + 0x20))(param_1);
      }
      (**(code **)(*param_1 + 0x20))(param_1);
      *param_5 = uVar2 + 1;
    }
    iVar1 = 0;
  }
  else {
    if ((param_2 & 0x100) != 0) {
      iVar1 = (**(code **)(*param_1 + 0x1c))(param_1);
      if (-1 < iVar1) {
        (**(code **)(*param_1 + 0x20))(param_1);
        goto LAB_4040bc3c;
      }
      goto LAB_4040c0c8;
    }
LAB_4040bc3c:
    if ((param_2 & 0x200) != 0) {
      iVar1 = (**(code **)(*param_1 + 0x1c))(param_1);
      if (iVar1 < 0) goto LAB_4040c0c8;
      (**(code **)(*param_1 + 0x20))(param_1);
    }
    if ((param_2 & 0x40) != 0) {
      iVar1 = (**(code **)(*param_1 + 0x1c))(param_1);
      if (iVar1 < 0) goto LAB_4040c0c8;
      (**(code **)(*param_1 + 0x20))(param_1);
    }
    if ((param_2 & 0x80) == 0) goto LAB_4040be28;
    iVar1 = (**(code **)(*param_1 + 0x1c))(param_1);
    if (((param_2 & 0x40000) == 0) || (iVar1 != -0x7ffcffdf)) {
      if (-1 < iVar1) {
        (**(code **)(*param_1 + 0x20))(param_1);
        goto LAB_4040be28;
      }
    }
    else {
      iVar1 = (**(code **)(*param_1 + 0x1c))(param_1);
      if (iVar1 == -0x7ffcffdf) goto LAB_4040be28;
      if (-1 < iVar1) {
        (**(code **)(*param_1 + 0x20))(param_1);
        iVar1 = -0x7ffcffdf;
      }
    }
LAB_4040c0c8:
    (**(code **)(*param_1 + 0x20))(param_1);
  }
  return iVar1;
}



/* 4040c23c FUN_4040c23c */

/* Boundary evidence: original MIPS .pdata 4040c23c..4040c3b7. Semantic name remains unreviewed. */

void FUN_4040c23c(int *param_1,uint param_2,int param_3,uint param_4)

{
  if ((param_2 & 0x40) != 0) {
    (**(code **)(*param_1 + 0x20))(param_1,param_2,param_3 - 0x6eU & param_4,0,1,0,4);
  }
  if ((param_2 & 0x80) != 0) {
    (**(code **)(*param_1 + 0x20))(param_1);
  }
  if ((param_2 & 0x100) != 0) {
    (**(code **)(*param_1 + 0x20))(param_1);
  }
  if (((param_2 & 0x200) != 0) || ((param_2 & 0x40000) != 0)) {
    (**(code **)(*param_1 + 0x20))(param_1);
  }
  if ((param_2 & 0x40000) != 0) {
    (**(code **)(*param_1 + 0x20))(param_1);
  }
  return;
}



/* 4040c3b8 FUN_4040c3b8 */

/* Boundary evidence: original MIPS .pdata 4040c3b8..4040c3fb. Semantic name remains unreviewed. */

int FUN_4040c3b8(int *param_1,uint param_2,int param_3,int *param_4)

{
  int iVar1;
  
  iVar1 = FUN_4040bb30(param_1,param_2,param_3,0x7fffffff,param_4);
  if (iVar1 < 0) {
    *param_4 = 0;
  }
  else {
    iVar1 = 0;
  }
  return iVar1;
}



/* 4040c3fc FUN_4040c3fc */

/* Boundary evidence: original MIPS .pdata 4040c3fc..4040c427. Semantic name remains unreviewed. */

void FUN_4040c3fc(int *param_1,uint param_2,uint param_3)

{
  if (param_3 != 0) {
    FUN_4040c23c(param_1,param_2,param_3 & 0xffff,0x7fffffff);
  }
  return;
}



/* 4040c428 FUN_4040c428 */

/* Boundary evidence: original MIPS .pdata 4040c428..4040c4db. Semantic name remains unreviewed. */

void FUN_4040c428(int *param_1,uint param_2,int *param_3)

{
  int iVar1;
  uint dwMilliseconds;
  
  dwMilliseconds = 100;
  while( true ) {
    iVar1 = FUN_4040b8dc(param_1,param_2,0x7fffffff,param_3);
    if (iVar1 < 0) {
      *param_3 = 0;
    }
    else {
      iVar1 = 0;
    }
    if ((iVar1 != -0x7ffcffdf) || (99999 < dwMilliseconds)) break;
    Sleep(dwMilliseconds);
    dwMilliseconds = dwMilliseconds << 1;
  }
  return;
}



/* 4040c4ec FUN_4040c4ec */

/* Boundary evidence: original MIPS .pdata 4040c4ec..4040c53b. Semantic name remains unreviewed. */

int FUN_4040c4ec(undefined4 *param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = param_1[8];
  iVar2 = iVar1 + -1;
  param_1[8] = iVar2;
  if (iVar2 == 0) {
    FUN_4040b21c(param_1);
    FUN_4040a65c(param_1);
  }
  return iVar1 + -1;
}



/* 4040c54c FUN_4040c54c */

/* Boundary evidence: original MIPS .pdata 4040c54c..4040c5db. Semantic name remains unreviewed. */

undefined4 FUN_4040c54c(int param_1,undefined4 *param_2)

{
  size_t sVar1;
  wchar_t *_Dest;
  undefined4 uVar2;
  
  sVar1 = wcslen((wchar_t *)(DAT_404304bc + *(int *)(param_1 + 0x10) + 8));
  _Dest = CoTaskMemAlloc((sVar1 + 1) * 2);
  *param_2 = _Dest;
  if (_Dest == (wchar_t *)0x0) {
    uVar2 = 0x80030008;
  }
  else {
    uVar2 = 0;
    wcscpy(_Dest,(wchar_t *)(DAT_404304bc + *(int *)(param_1 + 0x10) + 8));
  }
  return uVar2;
}



/* 4040c6e4 FUN_4040c6e4 */

undefined4 * FUN_4040c6e4(undefined4 *param_1,undefined4 param_2)

{
  param_1[1] = &PTR_LAB_404018f0;
  *param_1 = &PTR_LAB_404018c8;
  param_1[1] = &PTR_LAB_404018a8;
  param_1[0x10] = param_2;
  param_1[8] = 1;
  param_1[5] = 0xffffffff;
  param_1[6] = 0xffffffff;
  param_1[4] = 0;
  *(undefined2 *)(param_1 + 0x11) = 0;
  param_1[7] = 0x54534c46;
  param_1[0x12] = 0xffffffff;
  return param_1;
}



/* 4040c740 FUN_4040c740 */

/* Boundary evidence: original MIPS .pdata 4040c740..4040c7f7. Semantic name remains unreviewed. */

undefined4 FUN_4040c740(int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 uVar4;
  
  uVar4 = 0;
  puVar1 = (undefined4 *)FUN_4040a638(0x220);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    uVar2 = *(undefined4 *)(param_1 + 0x40);
    *puVar1 = 0;
    puVar1[1] = 1;
    puVar1[0x87] = uVar2;
    *(undefined2 *)(puVar1 + 2) = 0;
    puVar1[0x85] = param_3;
    puVar1[0x86] = param_2;
  }
  if (puVar1 == (undefined4 *)0x0) {
    uVar4 = 0x80030008;
  }
  else {
    iVar3 = (int)puVar1 - DAT_404304bc;
    *(int *)(param_1 + 0x10) = iVar3;
    FUN_4040d47c((int *)(iVar3 + DAT_404304bc),(undefined4 *)(param_1 + 8));
  }
  return uVar4;
}



/* 4040c7f8 FUN_4040c7f8 */

undefined4 * FUN_4040c7f8(undefined4 *param_1,uint param_2)

{
  undefined4 *puVar1;
  
  *(undefined2 *)(param_1 + 8) = 6;
  param_1[0xe] = 0x1000;
  *(short *)((int)param_1 + 0x1e) = (short)param_2;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  *(undefined2 *)(param_1 + 6) = 0x3e;
  *(undefined2 *)((int)param_1 + 0x1a) = 3;
  *(undefined2 *)(param_1 + 7) = 0xfffe;
  puVar1 = param_1 + 0x13;
  do {
    *puVar1 = 0xffffffff;
    puVar1 = puVar1 + 1;
  } while (puVar1 != param_1 + 0x80);
  param_1[0x12] = 0;
  param_1[0x11] = 0xfffffffe;
  param_1[0xb] = 1;
  param_1[0x13] = 0;
  param_1[0xc] = 1;
  param_1[0x10] = 0;
  param_1[0xf] = 0xfffffffe;
  param_1[0xd] = 0;
  *(undefined2 *)((int)param_1 + 0x22) = 0;
  param_1[9] = 0;
  param_1[10] = (uint)(9 < param_2);
  *param_1 = 0xe011cfd0;
  param_1[1] = 0xe11ab1a1;
  return param_1;
}



/* 4040c8d4 FUN_4040c8d4 */

/* Boundary evidence: original MIPS .pdata 4040c8d4..4040c907. Semantic name remains unreviewed. */

undefined4 * FUN_4040c8d4(undefined4 *param_1,uint param_2)

{
  FUN_4040c7f8(param_1,param_2);
  param_1[0x80] = 1;
  return param_1;
}



/* 4040c908 FUN_4040c908 */

undefined4 FUN_4040c908(int param_1)

{
  return *(undefined4 *)(param_1 + 0x28);
}



/* 4040c910 FUN_4040c910 */

undefined4 FUN_4040c910(int param_1)

{
  return *(undefined4 *)(param_1 + 0x2c);
}



/* 4040c918 FUN_4040c918 */

undefined4 FUN_4040c918(int param_1)

{
  return *(undefined4 *)(param_1 + 0x40);
}



/* 4040c920 FUN_4040c920 */

undefined4 FUN_4040c920(int param_1)

{
  return *(undefined4 *)(param_1 + 0x48);
}



/* 4040c928 FUN_4040c928 */

undefined2 FUN_4040c928(int param_1)

{
  return *(undefined2 *)(param_1 + 0x20);
}



/* 4040c930 FUN_4040c930 */

undefined4 FUN_4040c930(int param_1)

{
  return *(undefined4 *)(param_1 + 0x38);
}



/* 4040c938 FUN_4040c938 */

undefined2 FUN_4040c938(int param_1)

{
  return *(undefined2 *)(param_1 + 0x1a);
}



/* 4040c940 FUN_4040c940 */

/* Boundary evidence: original MIPS .pdata 4040c940..4040caa7. Semantic name remains unreviewed. */

int FUN_4040c940(void *param_1)

{
  undefined2 uVar1;
  int iVar2;
  undefined2 extraout_var;
  undefined2 extraout_var_00;
  undefined2 extraout_var_01;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  
  iVar2 = FUN_40406874(param_1);
  if (iVar2 == 0) {
    uVar1 = FUN_404155d8((int)param_1);
    iVar2 = CONCAT22(extraout_var,uVar1);
    uVar1 = FUN_4040c938((int)param_1);
    if (CONCAT22(extraout_var_00,uVar1) < 4) {
      if (((((iVar2 == 9) || (iVar2 == 0xc)) &&
           (uVar1 = FUN_4040c928((int)param_1), CONCAT22(extraout_var_01,uVar1) == 6)) &&
          ((iVar2 != 0xc || (iVar3 = FUN_4040c930((int)param_1), iVar3 == 0x1000)))) &&
         ((iVar2 != 9 || (iVar3 = FUN_4040c908((int)param_1), iVar3 == 0)))) {
        uVar6 = (0xfffffffaU >> (iVar2 - 2U & 0x1f)) + 1;
        uVar4 = FUN_4040c910((int)param_1);
        if ((uVar4 <= uVar6) && (uVar4 = FUN_4040c918((int)param_1), uVar4 <= uVar6)) {
          uVar4 = FUN_4040c920((int)param_1);
          uVar5 = (1 << (iVar2 - 2U & 0x1f)) - 1;
          if (uVar5 == 0) {
            trap(0x1c00);
          }
          if (uVar4 <= uVar6 / uVar5 + 1) {
            return 0;
          }
        }
      }
      iVar2 = -0x7ffcfef7;
    }
    else {
      iVar2 = -0x7ffcfefb;
    }
  }
  return iVar2;
}



/* 4040caa8 FUN_4040caa8 */

uint FUN_4040caa8(uint param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = 0;
  if (((((param_1 & 0x10000) != 0) && (uVar1 = 2, (param_1 & 0x40000) == 0)) &&
      ((param_1 & 0x70) != 0x20)) && ((param_1 & 0x70) != 0x10)) {
    uVar1 = 6;
  }
  uVar2 = param_1 & 3;
  if (uVar2 == 0) {
    uVar1 = uVar1 | 0x40;
  }
  else if (uVar2 == 1) {
    uVar1 = uVar1 | 0x80;
  }
  else if (uVar2 == 2) {
    uVar1 = uVar1 | 0xc0;
  }
  uVar2 = param_1 & 0x70;
  if (uVar2 == 0x10) {
    uVar1 = uVar1 | 0x300;
  }
  else if (uVar2 == 0x20) {
    uVar1 = uVar1 | 0x200;
  }
  else if (uVar2 == 0x30) {
    uVar1 = uVar1 | 0x100;
  }
  if ((param_1 & 0x40000) != 0) {
    uVar1 = uVar1 | 0x400;
  }
  if ((param_1 & 0x200000) != 0) {
    uVar1 = uVar1 & 0xfffffffb | 0x40000;
  }
  if ((param_1 & 0x100000) != 0) {
    uVar1 = uVar1 | 0x4000;
  }
  return uVar1;
}



/* 4040cba8 FUN_4040cba8 */

/* Boundary evidence: original MIPS .pdata 4040cba8..4040cc6f. Semantic name remains unreviewed. */

uint FUN_4040cba8(uint param_1)

{
  uint uVar1;
  uint uVar2;
  undefined4 local_8;
  
  if ((param_1 & 0x40) == 0) {
    uVar2 = 1;
    if ((param_1 & 0x80) == 0) {
      uVar2 = local_8;
    }
  }
  else if ((param_1 & 0x80) == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = 2;
  }
  if ((param_1 & 0x100) == 0) {
    uVar1 = uVar2 | 0x20;
    if ((param_1 & 0x200) == 0) {
      uVar1 = uVar2 | 0x40;
    }
  }
  else if ((param_1 & 0x200) == 0) {
    uVar1 = uVar2 | 0x30;
  }
  else {
    uVar1 = uVar2 | 0x10;
  }
  if ((param_1 & 2) != 0) {
    uVar1 = uVar1 | 0x10000;
  }
  if ((param_1 & 0x400) != 0) {
    uVar1 = uVar1 | 0x40000;
  }
  if ((param_1 & 0x4000) != 0) {
    uVar1 = uVar1 | 0x100000;
  }
  if ((param_1 & 0x40000) != 0) {
    uVar1 = uVar1 | 0x200000;
  }
  return uVar1;
}



/* 4040cc70 FUN_4040cc70 */

undefined4 FUN_4040cc70(uint param_1)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar3 = param_1 & 3;
  uVar1 = 0;
  if ((((((2 < uVar3) || (uVar2 = param_1 & 0x70, 0x40 < uVar2)) || ((param_1 & 0xfbc8ef8c) != 0))
       || (((((param_1 & 0x40000) != 0 &&
             (((uVar3 == 1 || (uVar3 == 2)) || ((param_1 & 0x10000) != 0)))) ||
            ((param_1 & 0x21000) == 0x21000)) ||
           ((((param_1 & 0x50000) == 0 && (uVar2 != 0x10)) && ((uVar3 != 0 || (uVar2 != 0x20))))))))
      || (((param_1 & 0x100000) != 0 && ((uVar3 == 0 || ((param_1 & 0x10000) == 0)))))) ||
     (((param_1 & 0x200000) != 0 &&
      (((((uVar2 == 0x10 || (uVar2 == 0x20)) || ((param_1 & 0x10000) == 0)) ||
        (((param_1 & 0x100000) != 0 || ((param_1 & 0x1000) != 0)))) || ((param_1 & 0x20000) != 0))))
     )) {
    uVar1 = 0x800300ff;
  }
  return uVar1;
}



/* 4040cd9c FUN_4040cd9c */

/* Boundary evidence: original MIPS .pdata 4040cd9c..4040ce73. Semantic name remains unreviewed. */

void FUN_4040cd9c(ushort *param_1)

{
  uint uVar1;
  ushort *puVar2;
  
  puVar2 = param_1;
  while( true ) {
    if (param_1 + 0x20 < puVar2) {
      return;
    }
    uVar1 = (uint)*puVar2;
    if (uVar1 == 0) break;
    if ((uVar1 < 0x80) &&
       ((1 << uVar1 % 0x20 & *(uint *)(&DAT_40401918 + (uint)(*puVar2 >> 5) * 4)) != 0)) {
      return;
    }
    puVar2 = puVar2 + 1;
  }
  return;
}



/* 4040ce74 FUN_4040ce74 */

/* Boundary evidence: original MIPS .pdata 4040ce74..4040ce7f. Semantic name remains unreviewed. */

undefined4 FUN_4040ce74(void)

{
  return 1;
}



/* 4040ce80 FUN_4040ce80 */

/* Boundary evidence: original MIPS .pdata 4040ce80..4040cf0f. Semantic name remains unreviewed. */

undefined4 FUN_4040ce80(undefined4 *param_1)

{
  BOOL BVar1;
  
  while( true ) {
    if ((param_1 == (undefined4 *)0x0) || (BVar1 = IsBadReadPtr(param_1,4), BVar1 != 0)) {
      return 0x80030009;
    }
    if ((void *)*param_1 == (void *)0x0) {
      return 0;
    }
    BVar1 = IsBadReadPtr((void *)*param_1,2);
    if (BVar1 != 0) break;
    param_1 = param_1 + 1;
  }
  return 0x800300fc;
}



/* 4040cf10 FUN_4040cf10 */

/* Boundary evidence: original MIPS .pdata 4040cf10..4040cfd7. Semantic name remains unreviewed. */

int FUN_4040cf10(ushort *param_1,ushort *param_2,int param_3)

{
  int iVar1;
  LPWSTR pWVar2;
  LPWSTR pWVar3;
  
  if (param_3 == 0) {
    iVar1 = 0;
  }
  else {
    for (; (param_3 = param_3 + -1, param_3 != 0 &&
           (pWVar3 = (LPWSTR)(uint)*param_1, pWVar3 != (LPWSTR)0x0)); param_1 = param_1 + 1) {
      if (pWVar3 != (LPWSTR)(uint)*param_2) {
        pWVar2 = CharUpperW((LPWSTR)(uint)*param_2);
        pWVar3 = CharUpperW(pWVar3);
        if (pWVar3 != pWVar2) break;
      }
      param_2 = param_2 + 1;
    }
    pWVar3 = CharUpperW((LPWSTR)(uint)*param_1);
    pWVar2 = CharUpperW((LPWSTR)(uint)*param_2);
    iVar1 = (int)pWVar3 - (int)pWVar2;
  }
  return iVar1;
}



/* 4040cfd8 FUN_4040cfd8 */

/* Boundary evidence: original MIPS .pdata 4040cfd8..4040d1eb. Semantic name remains unreviewed. */

uint FUN_4040cfd8(uint param_1)

{
  uint uVar1;
  
  if (param_1 < 0x28) {
    if (param_1 != 0x27) {
      switch(param_1) {
      case 1:
        return 0x80030001;
      case 2:
        return 0x80030002;
      case 3:
        return 0x80030003;
      case 4:
        return 0x80030004;
      case 5:
        goto LAB_4040d1dc;
      case 6:
        return 0x80030006;
      default:
switchD_4040d020_caseD_7:
        if (0 < (int)param_1) {
          return param_1 & 0xffff | 0x80070000;
        }
        return param_1;
      case 8:
        return 0x80030008;
      case 0x12:
        return 0x80030012;
      case 0x13:
        return 0x80030013;
      case 0x19:
        return 0x80030019;
      case 0x1d:
        return 0x8003001d;
      case 0x1e:
        return 0x8003001e;
      case 0x20:
        return 0x80030020;
      case 0x21:
        return 0x80030021;
      }
    }
LAB_4040d150:
    uVar1 = 0x80030070;
  }
  else {
    if (param_1 < 0x7c) {
      if (param_1 != 0x7b) {
        if (param_1 == 0x41) {
LAB_4040d1dc:
          return 0x80030005;
        }
        if (param_1 == 0x50) {
          return 0x80030050;
        }
        if (param_1 == 0x57) {
          return 0x80030057;
        }
        if (param_1 != 0x70) goto switchD_4040d020_caseD_7;
        goto LAB_4040d150;
      }
    }
    else if (param_1 != 0xa1) {
      if (param_1 == 0xb7) {
        return 0x80030050;
      }
      if (param_1 != 0xce) {
        if (param_1 == 0x3ec) {
          return 0x800300ff;
        }
        goto switchD_4040d020_caseD_7;
      }
    }
    uVar1 = 0x800300fc;
  }
  return uVar1;
}



/* 4040d1ec FUN_4040d1ec */

undefined2 FUN_4040d1ec(int param_1)

{
  return *(undefined2 *)(param_1 + 0x40);
}



/* 4040d1f4 FUN_4040d1f4 */

undefined4 FUN_4040d1f4(undefined4 param_1)

{
  return param_1;
}



/* 4040d1fc FUN_4040d1fc */

/* Boundary evidence: original MIPS .pdata 4040d1fc..4040d217. Semantic name remains unreviewed. */

void FUN_4040d1fc(SIZE_T param_1)

{
  CoTaskMemAlloc(param_1);
  return;
}



/* 4040d218 FUN_4040d218 */

/* Boundary evidence: original MIPS .pdata 4040d218..4040d233. Semantic name remains unreviewed. */

void FUN_4040d218(LPVOID param_1)

{
  CoTaskMemFree(param_1);
  return;
}



/* 4040d234 FUN_4040d234 */

/* Boundary evidence: original MIPS .pdata 4040d234..4040d397. Semantic name remains unreviewed. */

int FUN_4040d234(int *param_1,int *param_2)

{
  LPVOID pv;
  int iVar1;
  int iVar2;
  int local_28;
  undefined4 local_24;
  int local_20 [2];
  
  pv = CoTaskMemAlloc(0x2000);
  if (pv == (LPVOID)0x0) {
    iVar1 = -0x7ffcfff8;
  }
  else {
    (**(code **)(*param_1 + 0x20))(param_1,&local_24);
    iVar1 = (**(code **)(*param_2 + 0x1c))(param_2,local_24);
    if (-1 < iVar1) {
      iVar2 = 0;
      iVar1 = (**(code **)(*param_1 + 0x14))(param_1,0,pv,0x2000,&local_28);
      while( true ) {
        if (((iVar1 < 0) || (local_28 == 0)) ||
           (iVar1 = (**(code **)(*param_2 + 0x18))(param_2,iVar2,pv,local_28,local_20), iVar1 < 0))
        goto LAB_4040d36c;
        if (local_28 != local_20[0]) break;
        iVar2 = local_20[0] + iVar2;
        iVar1 = (**(code **)(*param_1 + 0x14))(param_1,iVar2,pv,0x2000,&local_28);
      }
      iVar1 = -0x7ffcffe3;
    }
  }
LAB_4040d36c:
  CoTaskMemFree(pv);
  return iVar1;
}



/* 4040d398 FUN_4040d398 */

/* Boundary evidence: original MIPS .pdata 4040d398..4040d42f. Semantic name remains unreviewed. */

undefined4 FUN_4040d398(ushort *param_1,undefined4 *param_2)

{
  size_t sVar1;
  int iVar2;
  wchar_t *_Str;
  
  while( true ) {
    _Str = (wchar_t *)*param_2;
    if (_Str == (wchar_t *)0x0) {
      return 1;
    }
    sVar1 = wcslen(_Str);
    if (((sVar1 + 1) * 2 == (uint)param_1[0x20]) &&
       (iVar2 = FUN_4040cf10(param_1,(ushort *)_Str,(uint)(param_1[0x20] >> 1)), iVar2 == 0)) break;
    param_2 = param_2 + 1;
  }
  return 0;
}



/* 4040d430 FUN_4040d430 */

void FUN_4040d430(int *param_1,int param_2)

{
  int iVar1;
  
  iVar1 = *param_1;
  while( true ) {
    if (iVar1 == 0) {
      return;
    }
    if (*param_1 + DAT_404304bc == param_2) break;
    param_1 = (int *)(*param_1 + DAT_404304bc + 4);
    iVar1 = *param_1;
  }
  *param_1 = *(int *)(param_2 + 4);
  return;
}



/* 4040d47c FUN_4040d47c */

/* Boundary evidence: original MIPS .pdata 4040d47c..4040d4cb. Semantic name remains unreviewed. */

void FUN_4040d47c(int *param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  param_2[1] = *param_1;
  uVar1 = __GetUserKData(0xc);
  *param_2 = uVar1;
  *param_1 = (int)param_2 - DAT_404304bc;
  return;
}



/* 4040d4cc FUN_4040d4cc */

int FUN_4040d4cc(int param_1)

{
  *(undefined2 *)(param_1 + 0x40) = 0;
  return param_1;
}



/* 4040d4d8 FUN_4040d4d8 */

/* Boundary evidence: original MIPS .pdata 4040d4d8..4040d673. Semantic name remains unreviewed. */

int FUN_4040d4d8(int *param_1,int *param_2)

{
  int iVar1;
  undefined2 local_78 [2];
  undefined *local_74;
  int local_70;
  int local_6c;
  undefined1 auStack_68 [72];
  uint local_20;
  
  local_20 = DAT_404303e4;
  FUN_40415908(0x200,0x8000,(int *)&local_74,local_78);
  iVar1 = (**(code **)(*param_1 + 0x24))(param_1,auStack_68,1);
  if ((-1 < iVar1) && (iVar1 = (**(code **)(*param_2 + 0x18))(param_2), -1 < iVar1)) {
    iVar1 = (**(code **)(*param_1 + 0xc))(param_1);
    while( true ) {
      if (((iVar1 < 0) || (local_70 == 0)) ||
         (iVar1 = (**(code **)(*param_2 + 0x10))(param_2), iVar1 < 0)) goto LAB_4040d644;
      if (local_70 != local_6c) break;
      iVar1 = (**(code **)(*param_1 + 0xc))(param_1);
    }
    iVar1 = -0x7ffcffe3;
  }
LAB_4040d644:
  FUN_4041598c(local_74);
  FUN_4042f4c4(local_20);
  return iVar1;
}



/* 4040d674 FUN_4040d674 */

/* Boundary evidence: original MIPS .pdata 4040d674..4040d6bb. Semantic name remains unreviewed. */

void FUN_4040d674(void *param_1,uint param_2,void *param_3)

{
  if (param_2 < 0x41) {
    *(short *)((int)param_1 + 0x40) = (short)param_2;
  }
  else {
    *(undefined2 *)((int)param_1 + 0x40) = 0x40;
  }
  if (param_3 != (void *)0x0) {
    memcpy(param_1,param_3,(uint)*(ushort *)((int)param_1 + 0x40));
  }
  return;
}



/* 4040d6bc FUN_4040d6bc */

undefined2 FUN_4040d6bc(int param_1)

{
  return *(undefined2 *)(param_1 + 0x4a4);
}



/* 4040d6c4 FUN_4040d6c4 */

undefined4 FUN_4040d6c4(int *param_1)

{
  return *(undefined4 *)(*param_1 + DAT_404304bc);
}



/* 4040d6dc FUN_4040d6dc */

undefined4 FUN_4040d6dc(int param_1)

{
  return *(undefined4 *)(param_1 + 100);
}



/* 4040d6e4 FUN_4040d6e4 */

/* Boundary evidence: original MIPS .pdata 4040d6e4..4040d6ff. Semantic name remains unreviewed. */

void FUN_4040d6e4(int param_1,int param_2)

{
  FUN_4041818c((int *)(param_1 + 0x60),param_2);
  return;
}



/* 4040d700 FUN_4040d700 */

/* Boundary evidence: original MIPS .pdata 4040d700..4040d71b. Semantic name remains unreviewed. */

void FUN_4040d700(int param_1,int param_2)

{
  FUN_40418040((int *)(param_1 + 0x60),param_2);
  return;
}



/* 4040d71c FUN_4040d71c */

undefined4 FUN_4040d71c(int param_1)

{
  return *(undefined4 *)(param_1 + 0x4ac);
}



/* 4040d724 FUN_4040d724 */

undefined4 * FUN_4040d724(undefined4 *param_1)

{
  *param_1 = &PTR_LAB_40401928;
  *(undefined2 *)(param_1 + 0x13) = 0;
  return param_1;
}



/* 4040d73c FUN_4040d73c */

/* Boundary evidence: original MIPS .pdata 4040d73c..4040da13. Semantic name remains unreviewed. */

int FUN_4040d73c(int param_1,int *param_2)

{
  bool bVar1;
  ushort uVar2;
  int *piVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  int *piVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  int iVar11;
  int iVar12;
  uint uVar13;
  uint local_88;
  uint local_84;
  int local_80;
  int *local_7c;
  undefined1 auStack_78 [8];
  int local_70;
  uint local_30;
  
  local_30 = DAT_404303e4;
  uVar2 = *(ushort *)(DAT_404304bc + *(int *)(param_1 + 0x6c) + 0x4a4);
  uVar5 = (uint)uVar2;
  iVar11 = 0;
  iVar8 = 0;
  iVar12 = 0;
  uVar10 = 0;
  local_80 = param_1;
  local_7c = param_2;
  if ((*(ushort *)(param_1 + 0x68) & 2) == 0) {
    piVar7 = (int *)(*(int *)(param_1 + 0x54) + DAT_404304bc);
    if (*(int *)(param_1 + 0x54) == 0) {
      piVar7 = (int *)0x0;
    }
    while (piVar7 != (int *)0x0) {
      (**(code **)(*piVar7 + 0x14))(piVar7,&local_84,&local_88);
      if (piVar7[3] == 1) {
        if (local_88 < local_84) {
          iVar11 = (local_84 - local_88) + iVar11;
        }
      }
      else if ((piVar7[3] == 2) && (local_84 < local_88)) {
        if (local_88 < 0x1000) {
          iVar12 = ((local_88 + 0x3f >> 6) - (local_84 + 0x3f >> 6)) + iVar12;
        }
        else {
          if (uVar5 == 0) {
            trap(0x1c00);
          }
          if (uVar5 == 0) {
            trap(0x1c00);
          }
          iVar8 = (((local_88 + uVar5) - 1) / uVar5 - ((local_84 + uVar5) - 1) / uVar5) + iVar8;
        }
      }
      if (piVar7[2] == 0) {
        iVar4 = 0;
      }
      else {
        iVar4 = piVar7[2] + DAT_404304bc;
      }
      piVar7 = (int *)(iVar4 + -4);
      if (iVar4 == 0) {
        piVar7 = (int *)0x0;
      }
    }
    uVar13 = (uint)(uVar2 >> 7);
    uVar9 = (uint)(uVar2 >> 2);
    uVar6 = (uint)(uVar2 >> 6);
    if (uVar6 == 0) {
      trap(0x1c00);
    }
    if (uVar9 == 0) {
      trap(0x1c00);
    }
    if (uVar13 == 0) {
      trap(0x1c00);
    }
    iVar8 = ((uVar6 + iVar12) - 1) / uVar6 + ((uVar9 + iVar12) - 1) / uVar9 +
            ((uVar13 + iVar11) - 1) / uVar13 + iVar8;
    uVar6 = 0;
    do {
      uVar13 = ((uVar5 + uVar10 + uVar6 + iVar8) - 1) / uVar5;
      if (uVar5 == 0) {
        trap(0x1c00);
      }
      uVar10 = ((uVar9 + uVar13) - 1) / uVar9;
      if (uVar9 == 0) {
        trap(0x1c00);
      }
      bVar1 = uVar6 != uVar13;
      uVar6 = uVar13;
    } while (bVar1);
    iVar8 = uVar10 + uVar13 + iVar8;
  }
  piVar7 = local_7c;
  piVar3 = *(int **)(*(int *)(DAT_404304bc + *(int *)(local_80 + 0x6c)) + DAT_404304bc);
  iVar11 = (**(code **)(*piVar3 + 0x24))(piVar3,auStack_78,1);
  if (-1 < iVar11) {
    *piVar7 = uVar5 * iVar8 + local_70;
  }
  FUN_4042f4c4(local_30);
  return iVar11;
}



/* 4040da14 FUN_4040da14 */

/* Boundary evidence: original MIPS .pdata 4040da14..4040db6f. Semantic name remains unreviewed. */

int FUN_4040da14(int param_1,ushort *param_2,uint param_3,undefined4 *param_4)

{
  undefined4 *puVar1;
  int *piVar2;
  uint uVar3;
  int iVar4;
  int *local_28 [2];
  
  uVar3 = *(uint *)(param_1 + 8);
  if ((uVar3 & 0x20) == 0) {
    if ((uVar3 & 0x40) == 0) {
      iVar4 = -0x7ffcfffb;
    }
    else {
      iVar4 = FUN_404181e0((int *)(param_1 + 0x60),param_2,param_3,uVar3);
      if ((-1 < iVar4) &&
         (piVar2 = (int *)(*(int *)(param_1 + 0x5c) + DAT_404304bc),
         iVar4 = (**(code **)(*piVar2 + 0x3c))(piVar2,param_2,param_3,local_28), -1 < iVar4)) {
        iVar4 = local_28[0][1];
        puVar1 = (undefined4 *)FUN_4040a638(100);
        if (puVar1 == (undefined4 *)0x0) {
          puVar1 = (undefined4 *)0x0;
        }
        else {
          puVar1 = FUN_404196b0(puVar1,param_1,param_3,(int)param_2);
        }
        *param_4 = puVar1;
        if (puVar1 == (undefined4 *)0x0) {
          iVar4 = -0x7ffcfff8;
          (**(code **)(*local_28[0] + 4))();
        }
        else {
          FUN_404193c4((int)puVar1,(int)local_28[0],iVar4);
          iVar4 = 0;
        }
      }
    }
  }
  else {
    iVar4 = -0x7ffcfefe;
  }
  return iVar4;
}



/* 4040db70 FUN_4040db70 */

/* Boundary evidence: original MIPS .pdata 4040db70..4040dcaf. Semantic name remains unreviewed. */

int FUN_4040db70(int param_1,undefined4 *param_2,uint param_3)

{
  LPVOID pvVar1;
  uint uVar2;
  undefined4 *puVar3;
  int *piVar4;
  int iVar5;
  
  if ((*(uint *)(param_1 + 8) & 0x20) == 0) {
    *param_2 = 0;
    if ((param_3 & 1) == 0) {
      pvVar1 = FUN_40419804((void *)(param_1 + 0xc));
      *param_2 = pvVar1;
      if (pvVar1 == (LPVOID)0x0) {
        return -0x7ffcfff8;
      }
    }
    puVar3 = (undefined4 *)(DAT_404304bc + *(int *)(param_1 + 0x5c));
    iVar5 = (**(code **)*puVar3)(puVar3,0,param_2 + 6);
    if ((-1 < iVar5) &&
       (puVar3 = (undefined4 *)(DAT_404304bc + *(int *)(param_1 + 0x5c)),
       iVar5 = (**(code **)*puVar3)(puVar3,1,param_2 + 4), -1 < iVar5)) {
      param_2[9] = 0;
      param_2[8] = 0;
      piVar4 = (int *)(DAT_404304bc + *(int *)(param_1 + 0x5c));
      iVar5 = (**(code **)(*piVar4 + 0x20))(piVar4,param_2 + 0xc);
      if ((-1 < iVar5) &&
         (piVar4 = (int *)(DAT_404304bc + *(int *)(param_1 + 0x5c)),
         iVar5 = (**(code **)(*piVar4 + 0x28))(piVar4,param_2 + 0x10), -1 < iVar5)) {
        uVar2 = FUN_4040cba8(*(uint *)(param_1 + 8));
        param_2[10] = uVar2;
      }
    }
  }
  else {
    iVar5 = -0x7ffcfefe;
  }
  return iVar5;
}



/* 4040dcb0 FUN_4040dcb0 */

/* Boundary evidence: original MIPS .pdata 4040dcb0..4040de5f. Semantic name remains unreviewed. */

void FUN_4040dcb0(int param_1,int param_2,int param_3)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  int *piVar5;
  
  piVar5 = (int *)(param_1 + 0x54);
  iVar1 = *piVar5;
  piVar2 = (int *)(iVar1 + DAT_404304bc);
LAB_4040de24:
  iVar4 = DAT_404304bc;
  if (iVar1 != 0) goto LAB_4040de30;
LAB_4040de2c:
  piVar2 = (int *)0x0;
  iVar4 = DAT_404304bc;
LAB_4040de30:
  while( true ) {
    piVar3 = piVar2;
    if (piVar3 == (int *)0x0) {
      return;
    }
    if (piVar3[2] == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = piVar3[2] + iVar4;
    }
    piVar2 = (int *)(iVar1 + -4);
    if (iVar1 == 0) {
      piVar2 = (int *)0x0;
    }
    if ((param_2 == 0) || (piVar3[6] == param_2)) break;
    if (param_2 == piVar3[5]) {
      iVar1 = piVar3[1];
      if (iVar1 == 0) {
        iVar1 = 0;
      }
      else {
        iVar1 = iVar1 + iVar4;
      }
      iVar4 = iVar1 + -4;
      if (iVar1 == 0) {
        iVar4 = 0;
      }
      FUN_4040dcb0(param_1,piVar3[6],param_3);
      goto LAB_4040dde4;
    }
  }
  if (param_3 != 1) goto code_r0x4040dd98;
  (**(code **)(*piVar3 + 0x10))(piVar3);
  iVar1 = piVar3[2];
  goto LAB_4040de0c;
code_r0x4040dd98:
  if (param_3 == 2) {
    iVar1 = piVar3[1];
    if (iVar1 == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = iVar1 + iVar4;
    }
    iVar4 = iVar1 + -4;
    if (iVar1 == 0) {
      iVar4 = 0;
    }
    FUN_40418538(piVar5,(int)piVar3);
    (**(code **)(*piVar3 + 4))(piVar3);
LAB_4040dde4:
    if (iVar4 != 0) {
      iVar1 = *(int *)(iVar4 + 8);
LAB_4040de0c:
      if (iVar1 == 0) {
        iVar1 = 0;
      }
      else {
        iVar1 = iVar1 + DAT_404304bc;
      }
      piVar2 = (int *)(iVar1 + -4);
      goto LAB_4040de24;
    }
    if (*piVar5 != 0) {
      piVar2 = (int *)(*piVar5 + DAT_404304bc);
      iVar4 = DAT_404304bc;
      goto LAB_4040de30;
    }
    goto LAB_4040de2c;
  }
  goto LAB_4040de30;
}



/* 4040de60 FUN_4040de60 */

/* Boundary evidence: original MIPS .pdata 4040de60..4040ded3. Semantic name remains unreviewed. */

void FUN_4040de60(int param_1,int param_2,undefined4 *param_3,undefined4 param_4)

{
  int iVar1;
  code *pcVar2;
  undefined4 uVar3;
  
  if (param_2 == 0) {
    uVar3 = 0;
    iVar1 = 0;
  }
  else {
    uVar3 = *(undefined4 *)(param_2 + 0x18);
    iVar1 = *(int *)(param_2 + 0x1c) + 1;
  }
  param_3[7] = iVar1;
  pcVar2 = *(code **)*param_3;
  param_3[5] = uVar3;
  param_3[6] = param_4;
  param_3[4] = 0;
  (*pcVar2)(param_3);
  FUN_404183a0((int *)(param_1 + 0x54),(int)param_3);
  return;
}



/* 4040ded4 FUN_4040ded4 */

/* Boundary evidence: original MIPS .pdata 4040ded4..4040e00f. Semantic name remains unreviewed. */

undefined4 *
FUN_4040ded4(undefined4 *param_1,int param_2,int param_3,undefined4 param_4,undefined4 param_5,
            int param_6,void *param_7,undefined4 param_8,int param_9)

{
  int iVar1;
  
  *(undefined2 *)(param_1 + 0x13) = 0;
  *param_1 = &PTR_FUN_4040192c;
  param_1[0x15] = 0;
  param_1[0x18] = 0;
  if (param_2 == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = param_2 - DAT_404304bc;
  }
  param_1[0x16] = iVar1;
  if (param_3 == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = param_3 - DAT_404304bc;
  }
  param_1[0x17] = iVar1;
  param_1[2] = param_4;
  param_1[1] = param_5;
  if (param_6 == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = param_6 - DAT_404304bc;
  }
  param_1[0x1f] = iVar1;
  param_1[0x19] = param_8;
  *(undefined2 *)(param_1 + 0x1a) = 0;
  if (param_9 == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = param_9 - DAT_404304bc;
  }
  param_1[0x1b] = iVar1;
  param_1[0x1e] = 1;
  if (param_7 == (void *)0x0) {
    *(undefined2 *)(param_1 + 0x13) = 0;
  }
  else {
    if (*(ushort *)((int)param_7 + 0x40) < 0x41) {
      *(ushort *)(param_1 + 0x13) = *(ushort *)((int)param_7 + 0x40);
    }
    else {
      *(undefined2 *)(param_1 + 0x13) = 0x40;
    }
    memcpy(param_1 + 3,param_7,(uint)*(ushort *)(param_1 + 0x13));
  }
  if (param_1[0x16] != 0) {
    FUN_40418040((int *)(param_1[0x16] + DAT_404304bc + 0x60),(int)param_1);
  }
  param_1[0x1d] = 0x46444250;
  return param_1;
}



/* 4040e010 FUN_4040e010 */

/* Boundary evidence: original MIPS .pdata 4040e010..4040e147. Semantic name remains unreviewed. */

void FUN_4040e010(int *param_1)

{
  LONG LVar1;
  int iVar2;
  _FILETIME local_18;
  
  if (((param_1[0x17] != 0) && ((param_1[2] & 2U) == 0)) && ((param_1[2] & 0x20U) == 0)) {
    if ((*(ushort *)(param_1 + 0x1a) & 1) != 0) {
      FUN_40419894(&local_18);
      (**(code **)(*(int *)(DAT_404304bc + param_1[0x17]) + 4))
                ((int *)(DAT_404304bc + param_1[0x17]),1,local_18.dwLowDateTime,
                 local_18.dwHighDateTime);
      if (param_1[0x16] != 0) {
        iVar2 = param_1[0x16] + DAT_404304bc;
        do {
          *(ushort *)(iVar2 + 0x68) = *(ushort *)(iVar2 + 0x68) | 1;
          if ((*(uint *)(iVar2 + 8) & 2) != 0) break;
          if (*(int *)(iVar2 + 0x58) == 0) {
            iVar2 = 0;
          }
          else {
            iVar2 = *(int *)(iVar2 + 0x58) + DAT_404304bc;
          }
        } while (iVar2 != 0);
      }
      *(ushort *)(param_1 + 0x1a) = *(ushort *)(param_1 + 0x1a) & 0xfffe;
    }
    if ((param_1[0x16] == 0) && ((param_1[2] & 0x80U) != 0)) {
      FUN_404171fc((int *)(param_1[0x1b] + DAT_404304bc),0);
    }
  }
  LVar1 = InterlockedDecrement(param_1 + 0x1e);
  if (LVar1 == 0) {
    (**(code **)(*param_1 + 4))(param_1);
  }
  return;
}



/* 4040e148 FUN_4040e148 */

/* Boundary evidence: original MIPS .pdata 4040e148..4040e263. Semantic name remains unreviewed. */

int FUN_4040e148(int param_1)

{
  int iVar1;
  int *piVar2;
  uint local_70 [2];
  undefined1 auStack_68 [8];
  uint local_60;
  uint local_20;
  
  local_20 = DAT_404303e4;
  iVar1 = FUN_4040d73c(param_1,(int *)local_70);
  if ((-1 < iVar1) &&
     (((*(uint *)(param_1 + 8) & 4) == 0 ||
      ((piVar2 = *(int **)(*(int *)(param_1 + 0x7c) + DAT_404304bc + 0x14),
       iVar1 = (**(code **)(*piVar2 + 0x24))(piVar2,auStack_68,1), -1 < iVar1 &&
       ((local_70[0] <= local_60 ||
        (iVar1 = (**(code **)(**(int **)(*(int *)(param_1 + 0x7c) + DAT_404304bc + 0x14) + 0x18))(),
        -1 < iVar1)))))))) {
    iVar1 = (**(code **)(**(int **)(*(int *)(*(int *)(param_1 + 0x6c) + DAT_404304bc) + DAT_404304bc
                                   ) + 0x18))();
  }
  FUN_4042f4c4(local_20);
  return iVar1;
}



/* 4040e264 FUN_4040e264 */

/* Boundary evidence: original MIPS .pdata 4040e264..4040e9eb. Semantic name remains unreviewed. */

int FUN_4040e264(int param_1,uint param_2)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint local_c8;
  int local_c4;
  _FILETIME local_c0;
  undefined1 auStack_b8 [8];
  uint local_b0;
  undefined1 auStack_70 [8];
  uint local_68;
  uint local_28;
  
  local_28 = DAT_404303e4;
  local_c8 = 0;
  if ((*(uint *)(param_1 + 8) & 0x20) != 0) {
    iVar4 = -0x7ffcfefe;
    goto LAB_4040e7c0;
  }
  if ((*(uint *)(param_1 + 8) & 0x80) == 0) {
    iVar4 = -0x7ffcfffb;
    goto LAB_4040e7c0;
  }
  if (((*(ushort *)(param_1 + 0x68) & 1) != 0) &&
     ((iVar4 = FUN_40419894(&local_c0), iVar4 < 0 ||
      (piVar1 = (int *)(*(int *)(param_1 + 0x5c) + DAT_404304bc),
      iVar4 = (**(code **)(*piVar1 + 4))(piVar1,1,local_c0.dwLowDateTime,local_c0.dwHighDateTime),
      iVar4 < 0)))) goto LAB_4040e7c0;
  if (((*(uint *)(param_1 + 8) & 0x40000) != 0) && ((param_2 & 1) != 0)) {
    iVar4 = -0x7ffcff01;
    goto LAB_4040e7c0;
  }
  if ((*(uint *)(param_1 + 8) & 2) == 0) {
    if ((*(ushort *)(param_1 + 0x68) & 1) != 0) {
      if (*(int *)(param_1 + 0x58) != 0) {
        iVar4 = *(int *)(param_1 + 0x58) + DAT_404304bc;
        do {
          *(ushort *)(iVar4 + 0x68) = *(ushort *)(iVar4 + 0x68) | 1;
          if ((*(uint *)(iVar4 + 8) & 2) != 0) break;
          if (*(int *)(iVar4 + 0x58) == 0) {
            iVar4 = 0;
          }
          else {
            iVar4 = *(int *)(iVar4 + 0x58) + DAT_404304bc;
          }
        } while (iVar4 != 0);
      }
      *(ushort *)(param_1 + 0x68) = *(ushort *)(param_1 + 0x68) & 0xfffe;
    }
    if ((*(int *)(param_1 + 100) != 0) ||
       (iVar4 = FUN_404171fc((int *)(*(int *)(param_1 + 0x6c) + DAT_404304bc),
                             (uint)((param_2 & 4) == 0)), -1 < iVar4)) goto LAB_4040e9b4;
    goto LAB_4040e7c0;
  }
  if (*(int *)(param_1 + 100) != 1) goto LAB_4040e4e4;
  iVar4 = FUN_40417944((int *)(*(int *)(param_1 + 0x6c) + DAT_404304bc),param_2);
  if ((iVar4 < 0) || (((param_2 & 1) != 0 && (iVar4 = FUN_4040e148(param_1), iVar4 < 0))))
  goto LAB_4040e7c0;
  iVar4 = *(int *)(param_1 + 0x7c) + DAT_404304bc;
  if (((*(uint *)(iVar4 + 0x28) & 4) == 0) ||
     (iVar4 = FUN_4040c428(*(int **)(iVar4 + 0x14),0x80,(int *)&local_c8), -1 < iVar4)) {
    if ((*(uint *)(param_1 + 8) & 4) == 0) {
LAB_4040e4e4:
      iVar4 = *(int *)(param_1 + 0x54);
      piVar1 = (int *)(iVar4 + DAT_404304bc);
      iVar2 = DAT_404304bc;
      while( true ) {
        if (iVar4 == 0) {
          piVar1 = (int *)0x0;
        }
        if (piVar1 == (int *)0x0) break;
        if (((piVar1[4] & 4U) == 0) &&
           (iVar4 = (**(code **)(*piVar1 + 8))(piVar1,param_2), iVar2 = DAT_404304bc, iVar4 < 0))
        goto LAB_4040e6c0;
        if (piVar1[2] == 0) {
          iVar4 = 0;
        }
        else {
          iVar4 = piVar1[2] + iVar2;
        }
        piVar1 = (int *)(iVar4 + -4);
      }
      if (((*(uint *)(param_1 + 8) & 4) == 0) ||
         (((piVar1 = *(int **)(*(int *)(param_1 + 0x7c) + iVar2 + 0xc),
           iVar4 = (**(code **)(*piVar1 + 0x24))(piVar1,auStack_b8,1), -1 < iVar4 &&
           (piVar1 = *(int **)(*(int *)(param_1 + 0x7c) + DAT_404304bc + 0x14),
           iVar4 = (**(code **)(*piVar1 + 0x24))(piVar1,auStack_70,1), -1 < iVar4)) &&
          ((iVar2 = DAT_404304bc, local_b0 <= local_68 ||
           (iVar4 = (**(code **)(**(int **)(*(int *)(param_1 + 0x7c) + DAT_404304bc + 0x14) + 0x18))
                              (), iVar2 = DAT_404304bc, -1 < iVar4)))))) {
        if ((*(int *)(param_1 + 100) != 1) ||
           (iVar4 = FUN_40417bbc((int *)(*(int *)(param_1 + 0x6c) + iVar2),param_2,8),
           iVar2 = DAT_404304bc, -1 < iVar4)) {
          piVar1 = (int *)(*(int *)(param_1 + 0x54) + iVar2);
          if (*(int *)(param_1 + 0x54) == 0) {
            piVar1 = (int *)0x0;
          }
          if (piVar1 == (int *)0x0) goto LAB_4040e88c;
          goto LAB_4040e7ec;
        }
        if (((*(uint *)(param_1 + 8) & 4) != 0) && (local_68 < local_b0)) {
          (**(code **)(**(int **)(*(int *)(param_1 + 0x7c) + DAT_404304bc + 0x14) + 0x18))();
        }
      }
LAB_4040e6c0:
      piVar1 = (int *)(*(int *)(param_1 + 0x54) + DAT_404304bc);
      if (*(int *)(param_1 + 0x54) == 0) {
        piVar1 = (int *)0x0;
      }
      if (piVar1 != (int *)0x0) {
        do {
          if (piVar1[2] == 0) {
            iVar2 = 0;
          }
          else {
            iVar2 = piVar1[2] + DAT_404304bc;
          }
          iVar3 = iVar2 + -4;
          if (iVar2 == 0) {
            iVar3 = 0;
          }
          if (iVar3 == 0) break;
          if (piVar1[2] == 0) {
            iVar2 = 0;
          }
          else {
            iVar2 = piVar1[2] + DAT_404304bc;
          }
          piVar1 = (int *)(iVar2 + -4);
          if (iVar2 == 0) {
            piVar1 = (int *)0x0;
          }
        } while (piVar1 != (int *)0x0);
        while (piVar1 != (int *)0x0) {
          (**(code **)(*piVar1 + 0xc))(piVar1,0);
          if (piVar1[1] == 0) {
            iVar2 = 0;
          }
          else {
            iVar2 = piVar1[1] + DAT_404304bc;
          }
          piVar1 = (int *)(iVar2 + -4);
          if (iVar2 == 0) {
            piVar1 = (int *)0x0;
          }
        }
      }
    }
    else {
      if (*(int *)(param_1 + 0x70) == -1) {
        if (((param_2 & 2) == 0) ||
           (iVar4 = FUN_40419a10(*(int **)(*(int *)(param_1 + 0x7c) + DAT_404304bc + 0x14)),
           iVar4 != 0)) goto LAB_4040e4e4;
      }
      else {
        iVar4 = FUN_40419bdc(*(int **)(*(int *)(param_1 + 0x7c) + DAT_404304bc + 0x14),&local_c4);
        if (iVar4 < 0) goto LAB_4040e77c;
        if (((param_2 & 2) == 0) || (local_c4 == *(int *)(param_1 + 0x70))) goto LAB_4040e4e4;
      }
      iVar4 = -0x7ffcfeff;
    }
LAB_4040e77c:
    if (local_c8 != 0) {
      FUN_4040baa4(*(int **)(*(int *)(param_1 + 0x7c) + DAT_404304bc + 0x14),0x80,local_c8);
    }
  }
  if (*(int *)(param_1 + 100) == 1) {
    FUN_40417bbc((int *)(*(int *)(param_1 + 0x6c) + DAT_404304bc),param_2,0);
  }
LAB_4040e7c0:
  FUN_4042f4c4(local_28);
  return iVar4;
  while( true ) {
    if (piVar1[2] == 0) {
      iVar4 = 0;
    }
    else {
      iVar4 = piVar1[2] + iVar2;
    }
    piVar1 = (int *)(iVar4 + -4);
    if (iVar4 == 0) {
      piVar1 = (int *)0x0;
    }
    if (piVar1 == (int *)0x0) break;
LAB_4040e7ec:
    if (piVar1[2] == 0) {
      iVar4 = 0;
    }
    else {
      iVar4 = piVar1[2] + iVar2;
    }
    iVar3 = iVar4 + -4;
    if (iVar4 == 0) {
      iVar3 = 0;
    }
    if (iVar3 == 0) break;
  }
  while (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0xc))(piVar1,8);
    if (piVar1[1] == 0) {
      iVar4 = 0;
    }
    else {
      iVar4 = piVar1[1] + DAT_404304bc;
    }
    piVar1 = (int *)(iVar4 + -4);
    iVar2 = DAT_404304bc;
    if (iVar4 == 0) {
      piVar1 = (int *)0x0;
    }
  }
LAB_4040e88c:
  if ((*(uint *)(param_1 + 8) & 4) != 0) {
    iVar2 = *(int *)(param_1 + 0x7c) + iVar2;
    FUN_4040d4d8(*(int **)(iVar2 + 0xc),*(int **)(iVar2 + 0x14));
    (**(code **)(**(int **)(*(int *)(param_1 + 0x7c) + DAT_404304bc + 0x14) + 0x14))();
    piVar1 = (int *)(param_1 + 0x70);
    if (*piVar1 == -1) {
      FUN_40419bdc(*(int **)(*(int *)(param_1 + 0x7c) + DAT_404304bc + 0x14),piVar1);
      iVar2 = DAT_404304bc;
    }
    else {
      *piVar1 = local_c4 + 1;
      FUN_40419ac4(*(int **)(*(int *)(param_1 + 0x7c) + DAT_404304bc + 0x14),local_c4 + 1);
      iVar2 = DAT_404304bc;
    }
  }
  if (local_c8 != 0) {
    FUN_4040baa4(*(int **)(*(int *)(param_1 + 0x7c) + iVar2 + 0x14),0x80,local_c8);
    iVar2 = DAT_404304bc;
  }
  if ((*(ushort *)(param_1 + 0x68) & 1) != 0) {
    if (*(int *)(param_1 + 0x58) != 0) {
      iVar2 = *(int *)(param_1 + 0x58) + iVar2;
      do {
        *(ushort *)(iVar2 + 0x68) = *(ushort *)(iVar2 + 0x68) | 1;
        if ((*(uint *)(iVar2 + 8) & 2) != 0) break;
        if (*(int *)(iVar2 + 0x58) == 0) {
          iVar2 = 0;
        }
        else {
          iVar2 = *(int *)(iVar2 + 0x58) + DAT_404304bc;
        }
      } while (iVar2 != 0);
    }
    *(ushort *)(param_1 + 0x68) = *(ushort *)(param_1 + 0x68) & 0xfffe;
  }
  *(ushort *)(param_1 + 0x68) = *(ushort *)(param_1 + 0x68) & 0xfffd;
LAB_4040e9b4:
  FUN_4042f4c4(local_28);
  return 0;
}



/* 4040e9ec FUN_4040e9ec */

/* Boundary evidence: original MIPS .pdata 4040e9ec..4040eadb. Semantic name remains unreviewed. */

int FUN_4040e9ec(int param_1,ushort *param_2)

{
  int *piVar1;
  uint uVar2;
  int iVar3;
  
  uVar2 = *(uint *)(param_1 + 8);
  if ((uVar2 & 0x20) == 0) {
    if (((uVar2 & 2) == 0) && ((uVar2 & 0x80) == 0)) {
      iVar3 = -0x7ffcfffb;
    }
    else {
      piVar1 = (int *)(*(int *)(param_1 + 0x5c) + DAT_404304bc);
      iVar3 = (**(code **)(*piVar1 + 0x18))(piVar1,param_2);
      if (-1 < iVar3) {
        FUN_404180d8((int *)(param_1 + 0x60),param_2);
        do {
          *(ushort *)(param_1 + 0x68) = *(ushort *)(param_1 + 0x68) | 1;
          if ((*(uint *)(param_1 + 8) & 2) != 0) {
            return iVar3;
          }
          if (*(int *)(param_1 + 0x58) == 0) {
            param_1 = 0;
          }
          else {
            param_1 = *(int *)(param_1 + 0x58) + DAT_404304bc;
          }
        } while (param_1 != 0);
      }
    }
  }
  else {
    iVar3 = -0x7ffcfefe;
  }
  return iVar3;
}



/* 4040eadc FUN_4040eadc */

/* Boundary evidence: original MIPS .pdata 4040eadc..4040ebbf. Semantic name remains unreviewed. */

int FUN_4040eadc(int param_1,ushort *param_2,undefined4 param_3)

{
  int iVar1;
  int *piVar2;
  
  if ((*(uint *)(param_1 + 8) & 0x20) == 0) {
    iVar1 = FUN_404181e0((int *)(param_1 + 0x60),param_2,0x380,*(uint *)(param_1 + 8));
    if (iVar1 < 0) {
      iVar1 = -0x7ffcfffb;
    }
    else {
      piVar2 = (int *)(*(int *)(param_1 + 0x5c) + DAT_404304bc);
      iVar1 = (**(code **)(*piVar2 + 0x1c))(piVar2,param_2,param_3);
      if (-1 < iVar1) {
        do {
          *(ushort *)(param_1 + 0x68) = *(ushort *)(param_1 + 0x68) | 1;
          if ((*(uint *)(param_1 + 8) & 2) != 0) {
            return iVar1;
          }
          if (*(int *)(param_1 + 0x58) == 0) {
            param_1 = 0;
          }
          else {
            param_1 = *(int *)(param_1 + 0x58) + DAT_404304bc;
          }
        } while (param_1 != 0);
      }
    }
  }
  else {
    iVar1 = -0x7ffcfefe;
  }
  return iVar1;
}



/* 4040ebc0 FUN_4040ebc0 */

/* Boundary evidence: original MIPS .pdata 4040ebc0..4040efd3. Semantic name remains unreviewed. */

int FUN_4040ebc0(int param_1,ushort *param_2,uint param_3,int *param_4)

{
  int iVar1;
  undefined4 *puVar2;
  int *piVar3;
  int *piVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  int *local_30 [2];
  
  uVar5 = *(uint *)(param_1 + 8);
  if ((uVar5 & 0x20) != 0) {
    return -0x7ffcfefe;
  }
  if (((uVar5 & 2) == 0) && ((uVar5 & 0x80) == 0)) {
    return -0x7ffcfffb;
  }
  iVar1 = FUN_404181e0((int *)(param_1 + 0x60),param_2,param_3,uVar5);
  if (iVar1 < 0) {
    return iVar1;
  }
  if (*(int *)(param_1 + 0x7c) == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = *(int *)(param_1 + 0x7c) + DAT_404304bc;
  }
  iVar1 = FUN_40417de8((int *)(iVar1 + 0x30),*(undefined4 *)(iVar1 + 0x2c),1,0x20);
  if (iVar1 < 0) {
    return iVar1;
  }
  uVar8 = param_3 & 2;
  uVar5 = *(int *)(param_1 + 100) + (uint)(uVar8 != 0);
  if (*(int *)(param_1 + 0x7c) == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = *(int *)(param_1 + 0x7c) + DAT_404304bc;
  }
  iVar1 = FUN_40417de8((int *)(iVar1 + 0x38),*(undefined4 *)(iVar1 + 0x2c),uVar5,0xd4);
  if (-1 < iVar1) {
    piVar3 = (int *)(*(int *)(param_1 + 0x5c) + DAT_404304bc);
    iVar1 = (**(code **)(*piVar3 + 0x30))(piVar3,param_2,param_3,0,local_30);
    iVar7 = param_1;
    if (-1 < iVar1) {
      do {
        *(ushort *)(iVar7 + 0x68) = *(ushort *)(iVar7 + 0x68) | 1;
        if ((*(uint *)(iVar7 + 8) & 2) != 0) break;
        iVar1 = *(int *)(iVar7 + 0x58) + DAT_404304bc;
        if (*(int *)(iVar7 + 0x58) == 0) {
          iVar1 = 0;
        }
        iVar7 = iVar1;
      } while (iVar1 != 0);
      iVar1 = local_30[0][1];
      puVar2 = (undefined4 *)FUN_4040a638(0x80);
      if (puVar2 == (undefined4 *)0x0) {
        puVar2 = (undefined4 *)0x0;
      }
      else {
        iVar7 = *(int *)(param_1 + 0x6c) + DAT_404304bc;
        if (*(int *)(param_1 + 0x6c) == 0) {
          iVar7 = 0;
        }
        iVar6 = *(int *)(param_1 + 0x7c) + DAT_404304bc;
        if (*(int *)(param_1 + 0x7c) == 0) {
          iVar6 = 0;
        }
        puVar2 = FUN_4040ded4(puVar2,param_1,(int)local_30[0],param_3,iVar1,iVar6,param_2,uVar5,
                              iVar7);
      }
      *param_4 = (int)puVar2;
      if (puVar2 == (undefined4 *)0x0) {
        iVar7 = -0x7ffcfff8;
        (**(code **)(*local_30[0] + 0x14))();
        if (uVar8 != 0) {
          if (*(int *)(param_1 + 0x7c) == 0) {
            iVar1 = 0;
          }
          else {
            iVar1 = *(int *)(param_1 + 0x7c) + DAT_404304bc;
          }
          FUN_40417ee8((int *)(iVar1 + 0x38),1);
        }
LAB_4040ef28:
        piVar3 = (int *)(*(int *)(param_1 + 0x5c) + DAT_404304bc);
        (**(code **)(*piVar3 + 0x18))(piVar3,param_2,1);
        return iVar7;
      }
      if (uVar8 != 0) {
        iVar7 = *(int *)(param_1 + 0x7c) + DAT_404304bc;
        if (*(int *)(param_1 + 0x7c) == 0) {
          iVar7 = 0;
        }
        iVar6 = *(int *)(iVar7 + 0x38);
        puVar2 = (undefined4 *)(iVar6 + DAT_404304bc);
        if (iVar6 == 0) {
          puVar2 = (undefined4 *)0x0;
        }
        *(undefined4 *)(iVar7 + 0x38) = *(undefined4 *)(iVar6 + DAT_404304bc);
        if (puVar2 == (undefined4 *)0x0) {
          piVar3 = (int *)0x0;
        }
        else {
          if (*(int *)(param_1 + 0x7c) == 0) {
            iVar7 = 0;
          }
          else {
            iVar7 = *(int *)(param_1 + 0x7c) + DAT_404304bc;
          }
          piVar3 = FUN_404188dc(puVar2,param_2,iVar1,param_3,iVar7,*param_4);
        }
        iVar7 = FUN_40418684(piVar3,local_30[0]);
        if (iVar7 < 0) {
          if (piVar3 != (int *)0x0) {
            FUN_404189d4(piVar3);
            FUN_4040a65c(piVar3);
          }
          FUN_4040e010((int *)*param_4);
          goto LAB_4040ef28;
        }
        piVar4 = piVar3 + 2;
        if (piVar3 == (int *)0x0) {
          piVar4 = (int *)0x0;
        }
        FUN_4040de60(*param_4,0,piVar4,iVar1);
        if (piVar3 == (int *)0x0) {
          iVar1 = 0;
        }
        else {
          iVar1 = (int)piVar3 - DAT_404304bc;
        }
        *(int *)(*param_4 + 0x5c) = iVar1;
      }
      return 0;
    }
    if (*(int *)(param_1 + 0x7c) == 0) {
      iVar7 = 0;
    }
    else {
      iVar7 = *(int *)(param_1 + 0x7c) + DAT_404304bc;
    }
    FUN_40417ee8((int *)(iVar7 + 0x38),uVar5);
  }
  if (*(int *)(param_1 + 0x7c) == 0) {
    iVar7 = 0;
  }
  else {
    iVar7 = *(int *)(param_1 + 0x7c) + DAT_404304bc;
  }
  FUN_40417ee8((int *)(iVar7 + 0x30),1);
  return iVar1;
}



/* 4040efd4 FUN_4040efd4 */

/* Boundary evidence: original MIPS .pdata 4040efd4..4040f25f. Semantic name remains unreviewed. */

int FUN_4040efd4(int param_1,ushort *param_2,uint param_3,int *param_4)

{
  int iVar1;
  undefined4 *puVar2;
  int *piVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int *local_30 [2];
  
  uVar4 = *(uint *)(param_1 + 8);
  if ((uVar4 & 0x20) != 0) {
    return -0x7ffcfefe;
  }
  if ((uVar4 & 0x40) == 0) {
    return -0x7ffcfffb;
  }
  iVar1 = FUN_404181e0((int *)(param_1 + 0x60),param_2,param_3,uVar4);
  if (iVar1 < 0) {
    return iVar1;
  }
  piVar3 = (int *)(*(int *)(param_1 + 0x5c) + DAT_404304bc);
  iVar1 = (**(code **)(*piVar3 + 0x34))(piVar3,param_2,param_3,local_30);
  if (iVar1 < 0) {
    return iVar1;
  }
  iVar7 = local_30[0][1];
  iVar1 = *(int *)(param_1 + 100);
  puVar2 = (undefined4 *)FUN_4040a638(0x80);
  if (puVar2 == (undefined4 *)0x0) {
    puVar2 = (undefined4 *)0x0;
  }
  else {
    iVar6 = *(int *)(param_1 + 0x6c) + DAT_404304bc;
    if (*(int *)(param_1 + 0x6c) == 0) {
      iVar6 = 0;
    }
    iVar5 = *(int *)(param_1 + 0x7c) + DAT_404304bc;
    if (*(int *)(param_1 + 0x7c) == 0) {
      iVar5 = 0;
    }
    puVar2 = FUN_4040ded4(puVar2,param_1,(int)local_30[0],param_3,iVar7,iVar5,param_2,
                          iVar1 + (uint)((param_3 & 2) != 0),iVar6);
  }
  *param_4 = (int)puVar2;
  if (puVar2 == (undefined4 *)0x0) {
    (**(code **)(*local_30[0] + 0x14))();
    return -0x7ffcfff8;
  }
  if ((param_3 & 2) == 0) {
LAB_4040f22c:
    iVar1 = 0;
  }
  else {
    puVar2 = (undefined4 *)FUN_4040a638(0xd4);
    if (puVar2 == (undefined4 *)0x0) {
      piVar3 = (int *)0x0;
    }
    else {
      if (*(int *)(param_1 + 0x7c) == 0) {
        iVar1 = 0;
      }
      else {
        iVar1 = *(int *)(param_1 + 0x7c) + DAT_404304bc;
      }
      piVar3 = FUN_404188dc(puVar2,param_2,iVar7,param_3,iVar1,*param_4);
    }
    if (piVar3 == (int *)0x0) {
      iVar1 = -0x7ffcfff8;
    }
    else {
      iVar1 = FUN_40418684(piVar3,local_30[0]);
      if (-1 < iVar1) {
        FUN_4040de60(*param_4,0,piVar3 + 2,iVar7);
        *(int *)(*param_4 + 0x5c) = (int)piVar3 - DAT_404304bc;
        goto LAB_4040f22c;
      }
      FUN_404189d4(piVar3);
      FUN_4040a65c(piVar3);
    }
    FUN_4040e010((int *)*param_4);
  }
  return iVar1;
}



/* 4040f260 FUN_4040f260 */

/* Boundary evidence: original MIPS .pdata 4040f260..4040f4fb. Semantic name remains unreviewed. */

int FUN_4040f260(int param_1,ushort *param_2,uint param_3,undefined4 *param_4)

{
  undefined4 *puVar1;
  int *piVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int *local_28 [2];
  
  uVar3 = *(uint *)(param_1 + 8);
  if ((uVar3 & 0x20) == 0) {
    if (((uVar3 & 2) == 0) && ((uVar3 & 0x80) == 0)) {
      iVar5 = -0x7ffcfffb;
    }
    else {
      iVar5 = FUN_404181e0((int *)(param_1 + 0x60),param_2,param_3,uVar3);
      if (-1 < iVar5) {
        if (*(int *)(param_1 + 0x7c) == 0) {
          iVar5 = 0;
        }
        else {
          iVar5 = *(int *)(param_1 + 0x7c) + DAT_404304bc;
        }
        iVar5 = FUN_40417de8((int *)(iVar5 + 0x34),*(undefined4 *)(iVar5 + 0x2c),1,0xa0);
        if (-1 < iVar5) {
          if (*(int *)(param_1 + 0x7c) == 0) {
            iVar5 = 0;
          }
          else {
            iVar5 = *(int *)(param_1 + 0x7c) + DAT_404304bc;
          }
          iVar5 = FUN_40417de8((int *)(iVar5 + 0x3c),*(undefined4 *)(iVar5 + 0x2c),
                               *(uint *)(param_1 + 100),0xa8);
          if (-1 < iVar5) {
            piVar2 = (int *)(*(int *)(param_1 + 0x5c) + DAT_404304bc);
            iVar5 = (**(code **)(*piVar2 + 0x38))(piVar2,param_2,param_3,0,local_28);
            iVar4 = param_1;
            if (-1 < iVar5) {
              do {
                *(ushort *)(iVar4 + 0x68) = *(ushort *)(iVar4 + 0x68) | 1;
                if ((*(uint *)(iVar4 + 8) & 2) != 0) break;
                iVar5 = *(int *)(iVar4 + 0x58) + DAT_404304bc;
                if (*(int *)(iVar4 + 0x58) == 0) {
                  iVar5 = 0;
                }
                iVar4 = iVar5;
              } while (iVar5 != 0);
              iVar5 = local_28[0][1];
              puVar1 = (undefined4 *)FUN_4040a638(100);
              if (puVar1 == (undefined4 *)0x0) {
                puVar1 = (undefined4 *)0x0;
              }
              else {
                puVar1 = FUN_404196b0(puVar1,param_1,param_3,(int)param_2);
              }
              *param_4 = puVar1;
              if (puVar1 == (undefined4 *)0x0) {
                (**(code **)(*local_28[0] + 4))();
                piVar2 = (int *)(*(int *)(param_1 + 0x5c) + DAT_404304bc);
                (**(code **)(*piVar2 + 0x18))(piVar2,param_2,1);
                return -0x7ffcfff8;
              }
              FUN_404193c4((int)puVar1,(int)local_28[0],iVar5);
              return 0;
            }
            if (*(int *)(param_1 + 0x7c) == 0) {
              iVar4 = 0;
            }
            else {
              iVar4 = *(int *)(param_1 + 0x7c) + DAT_404304bc;
            }
            FUN_40417ee8((int *)(iVar4 + 0x3c),*(int *)(param_1 + 100));
          }
          if (*(int *)(param_1 + 0x7c) == 0) {
            iVar4 = 0;
          }
          else {
            iVar4 = *(int *)(param_1 + 0x7c) + DAT_404304bc;
          }
          FUN_40417ee8((int *)(iVar4 + 0x34),1);
        }
      }
    }
  }
  else {
    iVar5 = -0x7ffcfefe;
  }
  return iVar5;
}



/* 4040f4fc FUN_4040f4fc */

/* Boundary evidence: original MIPS .pdata 4040f4fc..4040f567. Semantic name remains unreviewed. */

void FUN_4040f4fc(int param_1)

{
  *(uint *)(param_1 + 8) = *(uint *)(param_1 + 8) | 0x20;
  FUN_404180d8((int *)(param_1 + 0x60),(ushort *)0x0);
  FUN_4040dcb0(param_1,0,2);
  (**(code **)(*(int *)(*(int *)(param_1 + 0x5c) + DAT_404304bc) + 0x14))();
  *(undefined4 *)(param_1 + 0x5c) = 0;
  return;
}



/* 4040f568 FUN_4040f568 */

/* Boundary evidence: original MIPS .pdata 4040f568..4040f7db. Semantic name remains unreviewed. */

int FUN_4040f568(ushort *param_1,ushort *param_2,undefined4 *param_3,undefined4 *param_4,
                undefined4 *param_5)

{
  ushort *puVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int *local_30 [2];
  
  uVar2 = *(uint *)(param_1 + 4);
  iVar4 = 0;
  if ((uVar2 & 0x20) != 0) {
    return -0x7ffcfefe;
  }
  iVar3 = 0;
  if (param_2 == (ushort *)0x0) {
    if (*(int *)(param_1 + 0x2e) == 0) {
      local_30[0] = (int *)0x0;
    }
    else {
      local_30[0] = (int *)(*(int *)(param_1 + 0x2e) + DAT_404304bc);
    }
  }
  else {
    if ((((uVar2 & 2) == 0) && ((uVar2 & 0x80) == 0)) ||
       (iVar4 = FUN_4041805c((int *)(param_1 + 0x30),param_2), iVar4 != 0)) {
      return -0x7ffcfffb;
    }
    iVar4 = FUN_404182f8((int *)(param_1 + 0x2a),param_2,*(int *)(param_1 + 2));
    if (iVar4 == 0) {
      iVar3 = (**(code **)(*(int *)(*(int *)(param_1 + 0x2e) + DAT_404304bc) + 0x34))
                        ((int *)(*(int *)(param_1 + 0x2e) + DAT_404304bc),param_2,0x80,local_30);
      if (iVar3 < 0) {
        return iVar3;
      }
    }
    else {
      if (*(int *)(iVar4 + 0xc) != 1) {
        return -0x7ffcfffb;
      }
      local_30[0] = (int *)(iVar4 + -8);
    }
  }
  if ((param_3 == (undefined4 *)0x0) ||
     (iVar3 = (**(code **)(*local_30[0] + 4))(local_30[0],0,*param_3,param_3[1]), -1 < iVar3)) {
    if (param_5 != (undefined4 *)0x0) {
      iVar3 = (**(code **)(*local_30[0] + 4))(local_30[0],1,*param_5,param_5[1]);
      if (iVar3 < 0) goto LAB_4040f78c;
      if ((*(int *)(param_1 + 0x2c) == 0) && (param_2 == (ushort *)0x0)) {
        *(undefined4 *)(*(int *)(param_1 + 0x36) + DAT_404304bc + 0x49c) = 1;
      }
    }
    puVar1 = param_2;
    if ((param_4 == (undefined4 *)0x0) ||
       (iVar3 = (**(code **)(*local_30[0] + 4))(local_30[0],2,*param_4,param_4[1]), -1 < iVar3)) {
      while ((puVar1 != (ushort *)0x0 &&
             (param_1[0x34] = param_1[0x34] | 1, (*(uint *)(param_1 + 4) & 2) == 0))) {
        if (*(int *)(param_1 + 0x2c) == 0) {
          param_1 = (ushort *)0x0;
          puVar1 = param_1;
        }
        else {
          param_1 = (ushort *)(*(int *)(param_1 + 0x2c) + DAT_404304bc);
          puVar1 = param_1;
        }
      }
    }
  }
LAB_4040f78c:
  if ((iVar4 == 0) && (param_2 != (ushort *)0x0)) {
    (**(code **)(*local_30[0] + 0x14))();
  }
  return iVar3;
}



/* 4040f7dc FUN_4040f7dc */

/* Boundary evidence: original MIPS .pdata 4040f7dc..4040f89f. Semantic name remains unreviewed. */

undefined4 FUN_4040f7dc(int param_1)

{
  undefined4 uVar1;
  uint uVar2;
  
  uVar2 = *(uint *)(param_1 + 8);
  if ((uVar2 & 0x20) == 0) {
    if (((uVar2 & 2) == 0) && ((uVar2 & 0x80) == 0)) {
      uVar1 = 0x80030005;
    }
    else {
      uVar1 = (**(code **)(*(int *)(*(int *)(param_1 + 0x5c) + DAT_404304bc) + 0x24))();
      do {
        *(ushort *)(param_1 + 0x68) = *(ushort *)(param_1 + 0x68) | 1;
        if ((*(uint *)(param_1 + 8) & 2) != 0) {
          return uVar1;
        }
        if (*(int *)(param_1 + 0x58) == 0) {
          param_1 = 0;
        }
        else {
          param_1 = *(int *)(param_1 + 0x58) + DAT_404304bc;
        }
      } while (param_1 != 0);
    }
  }
  else {
    uVar1 = 0x80030102;
  }
  return uVar1;
}



/* 4040f8a0 FUN_4040f8a0 */

/* Boundary evidence: original MIPS .pdata 4040f8a0..4040f963. Semantic name remains unreviewed. */

undefined4 FUN_4040f8a0(int param_1)

{
  undefined4 uVar1;
  uint uVar2;
  
  uVar2 = *(uint *)(param_1 + 8);
  if ((uVar2 & 0x20) == 0) {
    if (((uVar2 & 2) == 0) && ((uVar2 & 0x80) == 0)) {
      uVar1 = 0x80030005;
    }
    else {
      uVar1 = (**(code **)(*(int *)(*(int *)(param_1 + 0x5c) + DAT_404304bc) + 0x2c))();
      do {
        *(ushort *)(param_1 + 0x68) = *(ushort *)(param_1 + 0x68) | 1;
        if ((*(uint *)(param_1 + 8) & 2) != 0) {
          return uVar1;
        }
        if (*(int *)(param_1 + 0x58) == 0) {
          param_1 = 0;
        }
        else {
          param_1 = *(int *)(param_1 + 0x58) + DAT_404304bc;
        }
      } while (param_1 != 0);
    }
  }
  else {
    uVar1 = 0x80030102;
  }
  return uVar1;
}



/* 4040f964 FUN_4040f964 */

/* Boundary evidence: original MIPS .pdata 4040f964..4040fa13. Semantic name remains unreviewed. */

void FUN_4040f964(LPVOID param_1)

{
  *(undefined4 *)((int)param_1 + 0x74) = 0x66446250;
  if ((*(uint *)((int)param_1 + 8) & 0x20) == 0) {
    FUN_4040dcb0((int)param_1,0,2);
    FUN_4041818c((int *)(*(int *)((int)param_1 + 0x58) + DAT_404304bc + 0x60),(int)param_1);
    FUN_404180d8((int *)((int)param_1 + 0x60),(ushort *)0x0);
    if (*(int *)((int)param_1 + 0x5c) != 0) {
      (**(code **)(*(int *)(*(int *)((int)param_1 + 0x5c) + DAT_404304bc) + 0x14))();
    }
  }
  FUN_404182f0();
  FUN_4040a65c(param_1);
  return;
}



/* 4040fa14 FUN_4040fa14 */

/* Boundary evidence: original MIPS .pdata 4040fa14..4040fa4f. Semantic name remains unreviewed. */

void FUN_4040fa14(int param_1,int *param_2)

{
  if (*(uint *)(param_1 + 0x80) != 0) {
    FUN_4040baa4(param_2,0x40,*(uint *)(param_1 + 0x80));
    *(undefined4 *)(param_1 + 0x80) = 0;
  }
  return;
}



/* 4040fa50 FUN_4040fa50 */

/* Boundary evidence: original MIPS .pdata 4040fa50..4040fae3. Semantic name remains unreviewed. */

int FUN_4040fa50(int param_1,uint param_2)

{
  int iVar1;
  
  iVar1 = FUN_4040e264(param_1,param_2);
  if (-1 < iVar1) {
    if (((*(uint *)(param_1 + 8) & 0x4000) != 0) && ((*(uint *)(param_1 + 8) & 2) != 0)) {
      iVar1 = FUN_4041611c((int *)(*(int *)(param_1 + 0x6c) + DAT_404304bc),0,1,
                           (undefined4 *)(param_1 + 0x88));
      if (iVar1 < 0) {
        *(undefined4 *)(param_1 + 0x8c) = 0xffffffff;
        *(undefined4 *)(param_1 + 0x88) = 0xffffffff;
      }
    }
    iVar1 = 0;
  }
  return iVar1;
}



/* 4040fae4 FUN_4040fae4 */

int FUN_4040fae4(int param_1)

{
  return param_1 + 0x31c;
}



/* 4040faec FUN_4040faec */

undefined4 * FUN_4040faec(undefined4 *param_1,undefined4 param_2)

{
  *param_1 = param_2;
  return param_1;
}



/* 4040fb04 FUN_4040fb04 */

undefined4 * FUN_4040fb04(undefined4 *param_1)

{
  *param_1 = 0;
  param_1[1] = 0xffffffff;
  return param_1;
}



/* 4040fb1c FUN_4040fb1c */

void FUN_4040fb1c(int *param_1,int param_2,int param_3)

{
  int iVar1;
  
  if (param_2 == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = param_2 - DAT_404304bc;
  }
  *param_1 = iVar1;
  param_1[1] = param_3;
  return;
}



/* 4040fb44 FUN_4040fb44 */

undefined4 *
FUN_4040fb44(undefined4 *param_1,int param_2,undefined4 param_3,undefined4 param_4,int param_5)

{
  int iVar1;
  
  param_1[1] = param_4;
  *param_1 = &PTR_FUN_40401994;
  param_1[3] = 0;
  param_1[2] = 0;
  param_1[6] = 0xffffffff;
  param_1[5] = 0;
  if (param_5 == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = param_5 - DAT_404304bc;
  }
  param_1[7] = iVar1 + DAT_404304bc;
  if (param_2 == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = param_2 - DAT_404304bc;
  }
  param_1[5] = iVar1;
  param_1[6] = param_3;
  param_1[4] = 0;
  return param_1;
}



/* 4040fbb8 FUN_4040fbb8 */

/* Boundary evidence: original MIPS .pdata 4040fbb8..4040ffb3. Semantic name remains unreviewed. */

uint FUN_4040fbb8(int param_1,int *param_2,undefined4 *param_3,uint param_4,uint param_5)

{
  uint uVar1;
  undefined4 *puVar2;
  int *piVar3;
  int *piVar4;
  int *piVar5;
  int iVar6;
  uint uVar7;
  int *local_res4 [3];
  int *local_38;
  uint local_34;
  int *local_30 [2];
  
  local_34 = 0;
  local_res4[0] = param_2;
  uVar1 = FUN_40419bdc(param_2,(undefined4 *)(param_1 + 0x70));
  if ((uVar1 == 0x800300fb) || (uVar1 == 0x800300fd)) {
    *(undefined4 *)(param_1 + 0x70) = 0xffffffff;
  }
  else if ((int)uVar1 < 0) {
    return uVar1;
  }
  puVar2 = (undefined4 *)FUN_4040a638(0x50);
  if (puVar2 == (undefined4 *)0x0) {
    piVar3 = (int *)0x0;
  }
  else {
    piVar3 = FUN_4040c6e4(puVar2,*(undefined4 *)(param_1 + 0x84));
  }
  if (piVar3 == (int *)0x0) {
    return 0x80030008;
  }
  uVar1 = FUN_4040c740((int)piVar3,0x14,0xc0);
  if (((-1 < (int)uVar1) && (uVar1 = FUN_4040ac8c((int)piVar3,(wchar_t *)0x0,1), -1 < (int)uVar1))
     && ((uVar7 = param_5 & 0x400, uVar7 != 0 ||
         (((*(uint *)(*(int *)(param_1 + 0x7c) + DAT_404304bc + 0x28) & 4) == 0 ||
          (uVar1 = FUN_4040c428(local_res4[0],0x40,(int *)&local_34), -1 < (int)uVar1)))))) {
    if (param_3 == (undefined4 *)0x0) {
      if (((param_4 & 2) != 0) || (uVar1 = FUN_4040d4d8(local_res4[0],piVar3), -1 < (int)uVar1)) {
LAB_4040febc:
        if ((uVar7 == 0) && (local_34 != 0)) {
          FUN_4040baa4(local_res4[0],0x40,local_34);
        }
        *(int **)(DAT_404304bc + *(int *)(param_1 + 0x7c) + 0xc) = piVar3;
        *(int **)(DAT_404304bc + *(int *)(param_1 + 0x7c) + 0x14) = local_res4[0];
        return 0;
      }
    }
    else {
      local_30[0] = piVar3;
      uVar1 = FUN_40419cb0(*(int *)(param_1 + 0x84),&local_38,local_res4,param_4);
      if (-1 < (int)uVar1) {
        puVar2 = (undefined4 *)FUN_4040a638(0x20);
        if (puVar2 == (undefined4 *)0x0) {
          piVar4 = (int *)0x0;
        }
        else {
          if (*(int *)(param_1 + 0x7c) == 0) {
            iVar6 = 0;
          }
          else {
            iVar6 = *(int *)(param_1 + 0x7c) + DAT_404304bc;
          }
          piVar4 = FUN_4040fb44(puVar2,(int)local_38,0,1,iVar6);
        }
        if (piVar4 == (int *)0x0) {
          uVar1 = 0x80030008;
          FUN_404198f8(local_38);
        }
        else {
          (**(code **)(*piVar4 + 0x10))(piVar4);
          uVar1 = FUN_40419cb0(*(int *)(param_1 + 0x84),&local_38,local_30,4);
          if (-1 < (int)uVar1) {
            puVar2 = (undefined4 *)FUN_4040a638(0x20);
            if (puVar2 == (undefined4 *)0x0) {
              piVar5 = (int *)0x0;
            }
            else {
              if (*(int *)(param_1 + 0x7c) == 0) {
                iVar6 = 0;
              }
              else {
                iVar6 = *(int *)(param_1 + 0x7c) + DAT_404304bc;
              }
              piVar5 = FUN_4040fb44(puVar2,(int)local_38,0,1,iVar6);
            }
            if (piVar5 == (int *)0x0) {
              uVar1 = 0x80030008;
              FUN_404198f8(local_38);
            }
            else {
              (**(code **)(*piVar5 + 0x10))(piVar5);
              uVar1 = FUN_4041b314(piVar4,piVar5,1,param_3);
              if ((-1 < (int)uVar1) && (uVar1 = FUN_404171fc(local_38,0), -1 < (int)uVar1)) {
                (**(code **)(*piVar4 + 0x14))(piVar4);
                (**(code **)(*piVar5 + 0x14))(piVar5);
                goto LAB_4040febc;
              }
              (**(code **)(*piVar5 + 0x14))(piVar5);
            }
          }
          (**(code **)(*piVar4 + 0x14))(piVar4);
        }
      }
    }
    if ((uVar7 == 0) && (local_34 != 0)) {
      FUN_4040baa4(local_res4[0],0x40,local_34);
    }
  }
  (**(code **)(*piVar3 + 8))(piVar3);
  return uVar1;
}



/* 4040ffb4 FUN_4040ffb4 */

/* Boundary evidence: original MIPS .pdata 4040ffb4..4041013b. Semantic name remains unreviewed. */

int FUN_4040ffb4(int param_1,int *param_2,undefined4 *param_3,uint param_4)

{
  int iVar1;
  undefined4 *puVar2;
  int *piVar3;
  int *local_res4 [3];
  int *local_20 [2];
  
  local_res4[0] = param_2;
  if (param_3 == (undefined4 *)0x0) {
LAB_404100bc:
    *(int **)(*(int *)(param_1 + 0x7c) + DAT_404304bc + 0xc) = local_res4[0];
    (**(code **)(*local_res4[0] + 4))();
    iVar1 = 0;
    *(int **)(*(int *)(param_1 + 0x7c) + DAT_404304bc + 0x14) = local_res4[0];
  }
  else {
    iVar1 = FUN_40419cb0(*(int *)(param_1 + 0x84),local_20,local_res4,param_4);
    if (iVar1 < 0) {
      return iVar1;
    }
    puVar2 = (undefined4 *)FUN_4040a638(0x20);
    if (puVar2 == (undefined4 *)0x0) {
      piVar3 = (int *)0x0;
    }
    else {
      if (*(int *)(param_1 + 0x7c) == 0) {
        iVar1 = 0;
      }
      else {
        iVar1 = *(int *)(param_1 + 0x7c) + DAT_404304bc;
      }
      piVar3 = FUN_4040fb44(puVar2,(int)local_20[0],0,1,iVar1);
    }
    if (piVar3 == (int *)0x0) {
      iVar1 = -0x7ffcfff8;
    }
    else {
      (**(code **)(*piVar3 + 0x10))(piVar3);
      iVar1 = FUN_4041b964(piVar3,param_3);
      if ((-1 < iVar1) && (iVar1 = FUN_404171fc(local_20[0],0), -1 < iVar1)) {
        (**(code **)(*piVar3 + 0x14))(piVar3);
        goto LAB_404100bc;
      }
      (**(code **)(*piVar3 + 0x14))(piVar3);
    }
    FUN_404198f8(local_20[0]);
  }
  return iVar1;
}



/* 4041013c FUN_4041013c */

/* Boundary evidence: original MIPS .pdata 4041013c..4041023b. Semantic name remains unreviewed. */

int FUN_4041013c(int param_1,undefined4 *param_2)

{
  uint uVar1;
  int *piVar2;
  int iVar3;
  
  if ((*(uint *)(param_1 + 8) & 0x20) == 0) {
    piVar2 = *(int **)(*(int *)(param_1 + 0x7c) + DAT_404304bc + 0x14);
    iVar3 = (**(code **)(*piVar2 + 0x24))(piVar2,param_2);
    if (-1 < iVar3) {
      uVar1 = FUN_4040cba8(*(uint *)(param_1 + 8));
      param_2[10] = uVar1;
      piVar2 = (int *)(DAT_404304bc + *(int *)(param_1 + 0x5c));
      iVar3 = (**(code **)(*piVar2 + 0x20))(piVar2,param_2 + 0xc);
      if ((iVar3 < 0) ||
         (piVar2 = (int *)(DAT_404304bc + *(int *)(param_1 + 0x5c)),
         iVar3 = (**(code **)(*piVar2 + 0x28))(piVar2,param_2 + 0x10), iVar3 < 0)) {
        if ((LPVOID)*param_2 != (LPVOID)0x0) {
          CoTaskMemFree((LPVOID)*param_2);
        }
      }
      else {
        iVar3 = 0;
      }
    }
  }
  else {
    iVar3 = -0x7ffcfefe;
  }
  return iVar3;
}



/* 4041023c FUN_4041023c */

/* Boundary evidence: original MIPS .pdata 4041023c..404103db. Semantic name remains unreviewed. */

int FUN_4041023c(int param_1,undefined4 param_2,int *param_3,uint *param_4)

{
  int iVar1;
  int iVar2;
  undefined2 local_30 [2];
  int *local_2c;
  undefined *local_28;
  int local_24;
  uint local_20 [2];
  
  if (((((*(uint *)(param_1 + 8) & 2) != 0) || ((*(ushort *)(param_1 + 0x68) & 1) == 0)) ||
      ((iVar1 = FUN_404171fc((int *)(*(int *)(param_1 + 0x6c) + DAT_404304bc),0), -1 < iVar1 &&
       (iVar1 = (**(code **)(*param_3 + 0x14))(param_3), -1 < iVar1)))) &&
     (iVar1 = FUN_4040d73c(param_1,&local_24), -1 < iVar1)) {
    iVar1 = (**(code **)*param_3)(param_3,&DAT_40402264,&local_2c);
    if (iVar1 < 0) {
      iVar1 = -0x7ffcfef9;
    }
    else {
      if (*param_4 != 0) {
        FUN_4040c3fc(param_3,*(uint *)(param_1 + 8),*param_4);
      }
      FUN_40415908(0x200,0x8000,(int *)&local_28,local_30);
      iVar1 = (**(code **)(*local_2c + 0xc))(local_2c,param_2,local_24,local_30[0],local_28);
      (**(code **)(*local_2c + 8))();
      FUN_4041598c(local_28);
      *(ushort *)(param_1 + 0x68) = *(ushort *)(param_1 + 0x68) | 2;
      if ((*param_4 != 0) &&
         (iVar2 = FUN_4040c3b8(param_3,*(uint *)(param_1 + 8),0,(int *)local_20), -1 < iVar2)) {
        *param_4 = local_20[0];
      }
    }
  }
  return iVar1;
}



/* 404103dc FUN_404103dc */

/* Boundary evidence: original MIPS .pdata 404103dc..40410457. Semantic name remains unreviewed. */

undefined4 *
FUN_404103dc(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  param_1[2] = param_3;
  param_1[0xb] = param_2;
  FUN_4040a570((int)(param_1 + 0xc),4,4,&LAB_4040faf8);
  param_1[10] = param_4;
  param_1[6] = 1;
  param_1[7] = 0;
  param_1[8] = 0;
  param_1[9] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  *param_1 = 0;
  param_1[1] = 0;
  return param_1;
}



/* 40410458 FUN_40410458 */

/* Boundary evidence: original MIPS .pdata 40410458..404104d7. Semantic name remains unreviewed. */

undefined4 * FUN_40410458(undefined4 *param_1,undefined4 param_2)

{
  FUN_4040ded4(param_1,0,0,0,1,0,(void *)0x0,0,0);
  param_1[0x21] = param_2;
  *param_1 = &PTR_FUN_404019ec;
  param_1[0x20] = 0;
  param_1[0x23] = 0xffffffff;
  param_1[0x22] = 0xffffffff;
  return param_1;
}



/* 404104d8 FUN_404104d8 */

/* Boundary evidence: original MIPS .pdata 404104d8..40410b53. Semantic name remains unreviewed. */

uint FUN_404104d8(int param_1,int *param_2,uint param_3,uint param_4,undefined4 *param_5,
                 undefined4 *param_6,uint *param_7)

{
  int iVar1;
  uint uVar2;
  undefined4 *puVar3;
  int *piVar4;
  uint uVar5;
  int *piVar6;
  int *piVar7;
  LPVOID pvVar8;
  int iVar9;
  uint uVar10;
  int local_c8;
  int local_c4;
  undefined2 local_c0 [2];
  int *local_bc;
  undefined1 auStack_b8 [44];
  uint local_8c [7];
  undefined1 auStack_70 [64];
  undefined2 local_30;
  uint local_2c;
  
  local_2c = DAT_404303e4;
  iVar1 = (**(code **)*param_2)(param_2,&DAT_40402264,&local_bc);
  if (iVar1 < 0) {
    uVar2 = (**(code **)(*param_2 + 0x24))(param_2,auStack_b8,1);
  }
  else {
    uVar2 = (**(code **)(*local_bc + 0x18))(local_bc,local_8c);
    (**(code **)(*local_bc + 8))();
  }
  if (((int)uVar2 < 0) ||
     ((*param_7 = 0, (local_8c[0] & 4) != 0 &&
      (uVar2 = FUN_4040c3b8(param_2,param_4,1,(int *)param_7), (int)uVar2 < 0)))) goto LAB_40410894;
  if (((param_4 & 0x400) == 0) ||
     (((local_8c[0] & 4) == 0 ||
      (uVar2 = FUN_4040ba60(param_2,0x40,(int *)(param_1 + 0x80)), -1 < (int)uVar2)))) {
    puVar3 = (undefined4 *)FUN_4040a638(0x40);
    if (puVar3 == (undefined4 *)0x0) {
      puVar3 = (undefined4 *)0x0;
    }
    else {
      puVar3 = FUN_404103dc(puVar3,*(undefined4 *)(param_1 + 0x84),param_4,local_8c[0]);
    }
    *param_6 = puVar3;
    if (puVar3 == (undefined4 *)0x0) {
      uVar2 = 0x80030008;
    }
    else {
      *(int *)(param_1 + 0x7c) = (int)puVar3 - DAT_404304bc;
      if ((param_4 & 4) == 0) {
        uVar2 = FUN_4040ffb4(param_1,param_2,param_5,param_3);
      }
      else {
        uVar2 = FUN_4040fbb8(param_1,param_2,param_5,param_3,param_4);
      }
      if (-1 < (int)uVar2) {
        puVar3 = (undefined4 *)FUN_4040a638(0x50);
        if (puVar3 == (undefined4 *)0x0) {
          piVar4 = (int *)0x0;
        }
        else {
          piVar4 = FUN_4040c6e4(puVar3,*(undefined4 *)(param_1 + 0x84));
        }
        if (piVar4 == (int *)0x0) {
          uVar2 = 0x80030008;
        }
        else {
          uVar2 = FUN_4040c740((int)piVar4,0x14,0xc0);
          if (-1 < (int)uVar2) {
            *(int **)(DAT_404304bc + *(int *)(param_1 + 0x7c) + 0x10) = piVar4;
            if (((param_4 & 4) != 0) || (uVar2 = 8, (param_4 & 2) == 0)) {
              uVar2 = 0;
            }
            uVar5 = FUN_40419cb0(*(int *)(param_1 + 0x84),&local_c8,
                                 (undefined4 *)(DAT_404304bc + *(int *)(param_1 + 0x7c) + 0xc),
                                 uVar2 | param_3);
            if (local_c8 == 0) {
              iVar1 = 0;
            }
            else {
              iVar1 = local_c8 - DAT_404304bc;
            }
            *(int *)(param_1 + 0x6c) = iVar1;
            if (uVar5 == 0x800300fb) {
              uVar5 = 0x80030050;
            }
            uVar2 = uVar5;
            if (-1 < (int)uVar5) {
              puVar3 = (undefined4 *)FUN_4040a638(0x20);
              if (puVar3 == (undefined4 *)0x0) {
                piVar6 = (int *)0x0;
              }
              else {
                if (*(int *)(param_1 + 0x7c) == 0) {
                  iVar1 = 0;
                }
                else {
                  iVar1 = *(int *)(param_1 + 0x7c) + DAT_404304bc;
                }
                piVar6 = FUN_4040fb44(puVar3,local_c8,0,1,iVar1);
              }
              if (piVar6 == (int *)0x0) {
                uVar2 = 0x80030008;
                if (*(int *)(param_1 + 0x6c) == 0) {
                  pvVar8 = (LPVOID)0x0;
                }
                else {
                  pvVar8 = (LPVOID)(*(int *)(param_1 + 0x6c) + DAT_404304bc);
                }
                FUN_404198f8(pvVar8);
              }
              else {
                (**(code **)(*piVar6 + 0x10))(piVar6);
                if ((param_4 & 2) == 0) {
                  iVar1 = (int)piVar6 - DAT_404304bc;
LAB_40410a1c:
                  uVar10 = param_4 & 0x4000;
                  *(int *)(param_1 + 0x5c) = iVar1;
                  if (uVar10 != 0) {
                    iVar1 = FUN_4041611c((int *)(*(int *)(param_1 + 0x6c) + DAT_404304bc),0,1,
                                         (undefined4 *)(param_1 + 0x88));
                    if (iVar1 < 0) {
                      *(undefined4 *)(param_1 + 0x8c) = 0xffffffff;
                      *(undefined4 *)(param_1 + 0x88) = 0xffffffff;
                    }
                  }
                  uVar2 = FUN_4041991c(&local_c4,uVar10,
                                       DAT_404304bc + *(int *)(param_1 + 0x7c) + 0x10,local_c8);
                  if (-1 < (int)uVar2) {
                    iVar1 = local_c4 - DAT_404304bc;
                    if (local_c4 == 0) {
                      iVar1 = 0;
                    }
                    *(int *)(DAT_404304bc + *(int *)(param_1 + 0x7c) + 4) = iVar1;
                    if (uVar10 == 0) {
                      *(undefined4 *)(DAT_404304bc + *(int *)(param_1 + 0x7c)) = 0;
LAB_40410b40:
                      *(uint *)(param_1 + 8) = param_4;
                      FUN_4042f4c4(local_2c);
                      return uVar5;
                    }
                    if (local_c8 == 0) {
                      iVar1 = 0;
                    }
                    else {
                      iVar1 = local_c8 - DAT_404304bc;
                    }
                    *(int *)(DAT_404304bc + *(int *)(param_1 + 0x7c)) = iVar1;
                    uVar2 = FUN_404162e4(local_c4,local_c8,1);
                    if (-1 < (int)uVar2) {
                      iVar9 = *(int *)(param_1 + 0x6c) + DAT_404304bc;
                      iVar1 = local_c4 - DAT_404304bc;
                      if (local_c4 == 0) {
                        iVar1 = 0;
                      }
                      *(int *)(iVar9 + 0x480) = iVar1;
                      if (local_c4 + 0x31c == 0) {
                        iVar1 = 0;
                      }
                      else {
                        iVar1 = (local_c4 + 0x31c) - DAT_404304bc;
                      }
                      *(int *)(iVar9 + 0x268) = iVar1;
                      goto LAB_40410b40;
                    }
                  }
                }
                else {
                  *(undefined4 *)(param_1 + 100) = 1;
                  local_c0[0] = 0;
                  local_30 = 2;
                  memcpy(auStack_70,local_c0,2);
                  uVar2 = FUN_4040ac8c(*(int *)(DAT_404304bc + *(int *)(param_1 + 0x7c) + 0x10),
                                       (wchar_t *)0x0,1);
                  if (-1 < (int)uVar2) {
                    puVar3 = (undefined4 *)FUN_4040a638(0xd4);
                    if (puVar3 == (undefined4 *)0x0) {
                      piVar7 = (int *)0x0;
                    }
                    else {
                      if (*(int *)(param_1 + 0x7c) == 0) {
                        iVar1 = 0;
                      }
                      else {
                        iVar1 = *(int *)(param_1 + 0x7c) + DAT_404304bc;
                      }
                      piVar7 = FUN_404188dc(puVar3,auStack_70,piVar6[1],param_4,iVar1,param_1);
                    }
                    if (piVar7 == (int *)0x0) {
                      uVar2 = 0x80030008;
                    }
                    else {
                      uVar2 = FUN_40418684(piVar7,piVar6);
                      if (-1 < (int)uVar2) {
                        FUN_4040de60(param_1,0,piVar7 + 2,piVar7[1]);
                        iVar1 = (int)piVar7 - DAT_404304bc;
                        goto LAB_40410a1c;
                      }
                      FUN_404189d4(piVar7);
                      FUN_4040a65c(piVar7);
                    }
                  }
                  (**(code **)(*piVar6 + 0x14))(piVar6);
                }
              }
            }
          }
          (**(code **)(*piVar4 + 8))(piVar4);
          *(undefined4 *)(DAT_404304bc + *(int *)(param_1 + 0x7c) + 0x10) = 0;
        }
        (**(code **)(**(int **)(DAT_404304bc + *(int *)(param_1 + 0x7c) + 0xc) + 8))();
        *(undefined4 *)(DAT_404304bc + *(int *)(param_1 + 0x7c) + 0xc) = 0;
      }
    }
    if (*(uint *)(param_1 + 0x80) != 0) {
      FUN_4040baa4(param_2,0x40,*(uint *)(param_1 + 0x80));
      *(undefined4 *)(param_1 + 0x80) = 0;
    }
  }
  if (*param_7 != 0) {
    FUN_4040c3fc(param_2,param_4,*param_7);
    *param_7 = 0;
  }
LAB_40410894:
  FUN_4042f4c4(local_2c);
  return uVar2;
}



/* 40410b54 FUN_40410b54 */

/* Boundary evidence: original MIPS .pdata 40410b54..40410c63. Semantic name remains unreviewed. */

void FUN_40410b54(LPVOID param_1)

{
  if (((*(uint *)((int)param_1 + 8) & 0x4000) != 0) &&
     (*(DWORD *)((int)param_1 + 0x88) != 0xffffffff)) {
    FUN_40415e40((int *)(*(int *)((int)param_1 + 0x6c) + DAT_404304bc),1,
                 *(DWORD *)((int)param_1 + 0x88),*(DWORD *)((int)param_1 + 0x8c));
  }
  *(undefined4 *)((int)param_1 + 0x74) = 0x66446250;
  if ((*(uint *)((int)param_1 + 8) & 0x20) == 0) {
    FUN_4040dcb0((int)param_1,0,2);
    FUN_404180d8((int *)((int)param_1 + 0x60),(ushort *)0x0);
    if (*(uint *)((int)param_1 + 0x80) != 0) {
      FUN_4040baa4(*(int **)(*(int *)((int)param_1 + 0x7c) + DAT_404304bc + 0xc),0x40,
                   *(uint *)((int)param_1 + 0x80));
    }
    if (*(int *)((int)param_1 + 0x5c) != 0) {
      (**(code **)(*(int *)(*(int *)((int)param_1 + 0x5c) + DAT_404304bc) + 0x14))();
    }
    if (*(int *)((int)param_1 + 0x7c) != 0) {
      FUN_40417ff8((LPVOID)(*(int *)((int)param_1 + 0x7c) + DAT_404304bc));
    }
  }
  FUN_404182f0();
  FUN_4040a65c(param_1);
  return;
}



/* 40410c64 FUN_40410c64 */

/* Boundary evidence: original MIPS .pdata 40410c64..40410ca3. Semantic name remains unreviewed. */

void FUN_40410c64(void *param_1,void *param_2)

{
  if (*(ushort *)((int)param_2 + 0x40) < 0x41) {
    *(ushort *)((int)param_1 + 0x40) = *(ushort *)((int)param_2 + 0x40);
  }
  else {
    *(undefined2 *)((int)param_1 + 0x40) = 0x40;
  }
  memcpy(param_1,param_2,(uint)*(ushort *)((int)param_1 + 0x40));
  return;
}



/* 40410ca4 FUN_40410ca4 */

uint FUN_40410ca4(int param_1,int *param_2)

{
  uint uVar1;
  
  uVar1 = 3;
  for (; param_1 != 0; param_1 = param_1 + -1) {
    if ((((*param_2 == 0xb) && (param_2[1] == 0)) && (param_2[2] == 0xc0)) &&
       (param_2[3] == 0x46000000)) {
      uVar1 = uVar1 & 0xfffffffe;
    }
    else if (((*param_2 == 0xc) && (param_2[1] == 0)) &&
            ((param_2[2] == 0xc0 && (param_2[3] == 0x46000000)))) {
      uVar1 = uVar1 & 0xfffffffd;
    }
    param_2 = param_2 + 4;
  }
  return uVar1;
}



/* 40410d68 FUN_40410d68 */

/* Boundary evidence: original MIPS .pdata 40410d68..40410db7. Semantic name remains unreviewed. */

LONG FUN_40410d68(int param_1)

{
  LONG LVar1;
  
  if ((param_1 == 0) || (*(int *)(param_1 + 0x18) != 0x4c464445)) {
    LVar1 = 0;
  }
  else {
    InterlockedIncrement((LONG *)(param_1 + 0x1c));
    LVar1 = *(LONG *)(param_1 + 0x1c);
  }
  return LVar1;
}



/* 40410db8 FUN_40410db8 */

/* Boundary evidence: original MIPS .pdata 40410db8..40410e1f. Semantic name remains unreviewed. */

int FUN_40410db8(void)

{
  int iVar1;
  int iVar2;
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_4043047c);
  iVar1 = FUN_4040a6c4();
  if ((iVar1 < 0) && (iVar2 = __GetUserKData(8), DAT_40430480 == iVar2)) {
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_4043047c);
  }
  return iVar1;
}



/* 40410e20 FUN_40410e20 */

/* Boundary evidence: original MIPS .pdata 40410e20..40410ebf. Semantic name remains unreviewed. */

undefined4 *
FUN_40410e20(undefined4 *param_1,int param_2,int param_3,undefined4 param_4,undefined4 param_5)

{
  int iVar1;
  
  *param_1 = &PTR_FUN_40401a10;
  param_1[1] = &PTR_LAB_40401a00;
  param_1[4] = param_4;
  param_1[5] = param_5;
  if (param_2 == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = param_2 - DAT_404304bc;
  }
  param_1[2] = iVar1;
  if (param_3 == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = param_3 - DAT_404304bc;
  }
  param_1[3] = iVar1;
  InterlockedIncrement((LONG *)(iVar1 + DAT_404304bc + 0x18));
  param_1[7] = 1;
  param_1[6] = 0x4c464445;
  return param_1;
}



/* 40410ed4 FUN_40410ed4 */

/* Boundary evidence: original MIPS .pdata 40410ed4..40410f4b. Semantic name remains unreviewed. */

void FUN_40410ed4(void *param_1,wchar_t *param_2)

{
  size_t sVar1;
  uint uVar2;
  
  sVar1 = wcslen(param_2);
  uVar2 = (sVar1 + 1) * 2;
  if ((uVar2 & 0xffff) < 0x41) {
    *(short *)((int)param_1 + 0x40) = (short)uVar2;
  }
  else {
    *(undefined2 *)((int)param_1 + 0x40) = 0x40;
  }
  if (param_2 != (wchar_t *)0x0) {
    memcpy(param_1,param_2,(uint)*(ushort *)((int)param_1 + 0x40));
  }
  return;
}



/* 40410f4c FUN_40410f4c */

/* Boundary evidence: original MIPS .pdata 40410f4c..40410f77. Semantic name remains unreviewed. */

void * FUN_40410f4c(void *param_1,wchar_t *param_2)

{
  FUN_40410ed4(param_1,param_2);
  return param_1;
}



/* 40410f78 FUN_40410f78 */

undefined4 FUN_40410f78(int param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = *(int *)(param_1 + 0xc) + DAT_404304bc;
  iVar2 = *(int *)(iVar3 + 0x24);
  if (iVar2 == 0) {
    iVar2 = 0;
  }
  else {
    iVar2 = iVar2 + DAT_404304bc;
  }
  if (iVar2 != 0) {
    iVar2 = *(int *)(iVar3 + 0x24);
    iVar3 = iVar2 + DAT_404304bc;
    if (iVar2 == 0) {
      iVar3 = 0;
    }
    iVar2 = *(int *)(param_1 + 8) + DAT_404304bc;
    do {
      if (iVar2 == iVar3) {
        return 0x80030005;
      }
      piVar1 = (int *)(iVar2 + 0x58);
      iVar2 = *piVar1 + DAT_404304bc;
      if (*piVar1 == 0) {
        iVar2 = 0;
      }
    } while (iVar2 != 0);
    if (iVar3 == 0) {
      return 0x80030005;
    }
  }
  return 0;
}



/* 40411000 FUN_40411000 */

/* Boundary evidence: original MIPS .pdata 40411000..4041114f. Semantic name remains unreviewed. */

int FUN_40411000(int param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  undefined4 *local_b0;
  undefined4 *local_ac;
  ushort auStack_a8 [36];
  ushort auStack_60 [34];
  uint local_1c;
  
  local_1c = DAT_404303e4;
  FUN_40410ed4(auStack_a8,L"\\");
  FUN_40410ed4(auStack_60,L"CONTENTS");
  iVar1 = FUN_4040da14(DAT_404304bc + *(int *)(param_1 + 8),auStack_a8,0x3c0,&local_b0);
  if (-1 < iVar1) {
    if (*(int *)(param_2 + 8) == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = *(int *)(param_2 + 8) + DAT_404304bc;
    }
    iVar1 = FUN_4040f260(iVar1,auStack_60,0x380,&local_ac);
    if (-1 < iVar1) {
      piVar3 = (int *)(local_ac[0x15] + DAT_404304bc);
      if (local_ac[0x15] == 0) {
        piVar3 = (int *)0x0;
      }
      piVar2 = (int *)(local_b0[0x15] + DAT_404304bc);
      if (local_b0[0x15] == 0) {
        piVar2 = (int *)0x0;
      }
      iVar1 = FUN_4040d234(piVar2,piVar3);
      if ((-1 < iVar1) &&
         (iVar1 = FUN_4040e9ec(DAT_404304bc + *(int *)(param_1 + 8),auStack_a8), -1 < iVar1)) {
        iVar1 = 0;
      }
      FUN_4041977c(local_ac);
    }
    FUN_4041977c(local_b0);
  }
  FUN_4042f4c4(local_1c);
  return iVar1;
}



/* 40411150 FUN_40411150 */

/* Boundary evidence: original MIPS .pdata 40411150..404113bf. Semantic name remains unreviewed. */

uint FUN_40411150(int param_1,ushort *param_2,int param_3,uint param_4,undefined4 *param_5)

{
  uint uVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 *local_28;
  int *local_24;
  
  if ((param_4 & 0x70) != 0x10) {
    return 0x80030001;
  }
  if (((param_4 & 0x10000) == 0x10000) &&
     (uVar1 = FUN_4040ac8c(*(int *)(*(int *)(param_1 + 0x10) + 0xc),(wchar_t *)0x0,1),
     (int)uVar1 < 0)) {
    return uVar1;
  }
  if (param_3 == 2) {
    uVar1 = FUN_4040caa8(param_4);
    uVar1 = FUN_4040da14(*(int *)(param_1 + 8) + DAT_404304bc,param_2,uVar1,&local_28);
    if ((int)uVar1 < 0) {
      return uVar1;
    }
    puVar2 = (undefined4 *)FUN_4040a638(0x20);
    if (puVar2 == (undefined4 *)0x0) {
      puVar2 = (undefined4 *)0x0;
    }
    else {
      puVar2 = FUN_4041d0e8(puVar2);
    }
    if (puVar2 == (undefined4 *)0x0) {
      uVar1 = 0x80030008;
    }
    else {
      if (*(int *)(param_1 + 0xc) == 0) {
        iVar3 = 0;
      }
      else {
        iVar3 = *(int *)(param_1 + 0xc) + DAT_404304bc;
      }
      uVar1 = FUN_4041bcb8((int)puVar2,(int)local_28,iVar3,*(undefined4 *)(param_1 + 0x10),1,0);
      if (-1 < (int)uVar1) {
        *(int *)(*(int *)(param_1 + 0x10) + 0x1c) = *(int *)(*(int *)(param_1 + 0x10) + 0x1c) + 1;
        *param_5 = puVar2;
        goto LAB_40411394;
      }
      FUN_4041c150(puVar2);
      FUN_4040a65c(puVar2);
    }
    FUN_4041977c(local_28);
  }
  else {
    uVar1 = FUN_4040caa8(param_4);
    uVar1 = FUN_4040efd4(*(int *)(param_1 + 8) + DAT_404304bc,param_2,uVar1,(int *)&local_24);
    if ((int)uVar1 < 0) {
      return uVar1;
    }
    puVar2 = (undefined4 *)FUN_4040a638(0x20);
    if (puVar2 == (undefined4 *)0x0) {
      puVar2 = (undefined4 *)0x0;
    }
    else {
      if (*(int *)(param_1 + 0xc) == 0) {
        iVar3 = 0;
      }
      else {
        iVar3 = *(int *)(param_1 + 0xc) + DAT_404304bc;
      }
      puVar2 = FUN_40410e20(puVar2,(int)local_24,iVar3,*(undefined4 *)(param_1 + 0x10),1);
    }
    if (puVar2 == (undefined4 *)0x0) {
      FUN_4040e010(local_24);
      return 0x80030008;
    }
    *(int *)(*(int *)(param_1 + 0x10) + 0x1c) = *(int *)(*(int *)(param_1 + 0x10) + 0x1c) + 1;
    *param_5 = puVar2;
LAB_40411394:
    uVar1 = 0;
  }
  return uVar1;
}



/* 404113c0 FUN_404113c0 */

/* Boundary evidence: original MIPS .pdata 404113c0..404116ef. Semantic name remains unreviewed. */

int FUN_404113c0(int *param_1,ushort *param_2,int *param_3,ushort *param_4,uint param_5)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int *piVar4;
  int *local_88;
  int *local_84;
  int *local_80;
  int *local_7c;
  undefined1 auStack_78 [24];
  undefined1 auStack_60 [48];
  uint local_30;
  
  local_30 = DAT_404303e4;
  if ((param_1 == (int *)0x0) || (param_1[6] != 0x4c464445)) {
    iVar1 = -0x7ffcfffa;
    goto LAB_404116b8;
  }
  iVar1 = FUN_4040cd9c(param_2);
  if (iVar1 < 0) goto LAB_404116b8;
  iVar1 = 0;
  if ((param_5 & 0xfffffffe) != 0) {
    iVar1 = -0x7ffcff01;
  }
  if (iVar1 < 0) goto LAB_404116b8;
  iVar1 = (**(code **)(*param_1 + 0x18))(param_1,param_2,0,0x10,0,0,&local_80);
  piVar4 = local_80;
  if (iVar1 < 0) {
    if (iVar1 != -0x7ffcfffe) goto LAB_404116b8;
    iVar1 = (**(code **)(*param_1 + 0x10))(param_1,param_2,0,0x10,0,&local_88);
    piVar4 = local_88;
    if (iVar1 < 0) goto LAB_404116b8;
    iVar1 = (**(code **)(*local_88 + 0x30))(local_88,auStack_78,1);
    if (-1 < iVar1) {
      uVar3 = 0;
      if (param_5 != 0) {
        uVar3 = 0x1000;
      }
      iVar1 = (**(code **)(*param_3 + 0xc))(param_3,param_4,uVar3 | 0x11,0,0,&local_7c);
      if (-1 < iVar1) {
        iVar1 = (**(code **)(*local_88 + 0x1c))(local_88,local_7c,0xffffffff,0xffffffff,0,0);
        local_84 = local_7c;
        goto LAB_4041163c;
      }
    }
  }
  else {
    iVar1 = (**(code **)(*local_80 + 0x44))(local_80,auStack_78,1);
    if (-1 < iVar1) {
      iVar1 = (**(code **)(*param_3 + 0x14))(param_3,param_4,0x11,0,0,&local_84);
      if ((iVar1 == -0x7ffcffb0) && (param_5 == 1)) {
        iVar1 = (**(code **)(*param_3 + 0x18))(param_3,param_4,0,0x12,0,0,&local_84);
      }
      if (-1 < iVar1) {
        iVar1 = (**(code **)(*local_80 + 0x1c))(local_80,0,0,0,local_84);
LAB_4041163c:
        (**(code **)(*local_84 + 8))(local_84);
        iVar2 = *param_3;
        if (-1 < iVar1) {
          (**(code **)(iVar2 + 0x38))(param_3,param_4,auStack_60,0,0);
          if ((param_5 & 1) != 0) goto LAB_40411698;
          iVar2 = *param_1;
          param_3 = param_1;
          param_4 = param_2;
        }
        (**(code **)(iVar2 + 0x30))(param_3,param_4);
      }
    }
  }
LAB_40411698:
  (**(code **)(*piVar4 + 8))(piVar4);
LAB_404116b8:
  FUN_4042f4c4(local_30);
  return iVar1;
}



/* 404116f0 FUN_404116f0 */

/* Boundary evidence: original MIPS .pdata 404116f0..40411957. Semantic name remains unreviewed. */

int FUN_404116f0(int param_1,int *param_2,int *param_3)

{
  BOOL BVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int *local_20 [2];
  
  BVar1 = IsBadWritePtr(param_3,4);
  if (BVar1 != 0) {
    return -0x7ffcfff7;
  }
  *param_3 = 0;
  if ((param_1 == 0) || (*(int *)(param_1 + 0x18) != 0x4c464445)) {
    return -0x7ffcfffa;
  }
  iVar3 = *(int *)(param_1 + 8) + DAT_404304bc;
  if ((*(uint *)(iVar3 + 8) & 0x20) != 0) {
    return -0x7ffcfefe;
  }
  iVar4 = *param_2;
  iVar5 = 0;
  if (((((iVar4 == 0xb) && (param_2[1] == 0)) && (param_2[2] == 0xc0)) && (param_2[3] == 0x46000000)
      ) || (((iVar4 == 0 && (param_2[1] == 0)) &&
            ((param_2[2] == 0xc0 && (param_2[3] == 0x46000000)))))) {
LAB_404118b4:
    *param_3 = param_1;
LAB_40411920:
    FUN_40410d68(param_1);
  }
  else {
    if (((iVar4 == 3) && (param_2[1] == 0)) && ((param_2[2] == 0xc0 && (param_2[3] == 0x46000000))))
    {
      if (((*(uint *)(iVar3 + 8) & 0x400) == 0) || (*(int *)(iVar3 + 0x58) != 0)) {
        puVar2 = *(undefined4 **)(*(int *)(param_1 + 0x10) + 0x10);
        if (puVar2 == (undefined4 *)0x0) {
          puVar2 = *(undefined4 **)(*(int *)(param_1 + 0x10) + 8);
        }
        iVar5 = (**(code **)*puVar2)(puVar2,&DAT_40402294,local_20);
        if (-1 < iVar5) {
          (**(code **)(*local_20[0] + 8))();
          goto LAB_404118b4;
        }
      }
    }
    else if ((((iVar4 == 0x12) && (param_2[1] == 0)) && (param_2[2] == 0xc0)) &&
            ((param_2[3] == 0x46000000 && (*(int *)(iVar3 + 0x58) == 0)))) {
      *param_3 = param_1 + 4;
      goto LAB_40411920;
    }
    iVar5 = -0x7fffbffe;
  }
  return iVar5;
}



/* 4041196c FUN_4041196c */

/* Boundary evidence: original MIPS .pdata 4041196c..404119e7. Semantic name remains unreviewed. */

undefined4 FUN_4041196c(int param_1)

{
  undefined4 uVar1;
  
  if ((*(uint *)(param_1 + 8) & 0x20) == 0) {
    uVar1 = 0;
    if ((*(uint *)(param_1 + 8) & 2) != 0) {
      FUN_404180d8((int *)(param_1 + 0x60),(ushort *)0x0);
      FUN_4040dcb0(param_1,0,1);
      *(ushort *)(param_1 + 0x68) = *(ushort *)(param_1 + 0x68) & 0xfffc;
    }
  }
  else {
    uVar1 = 0x80030102;
  }
  return uVar1;
}



/* 404119e8 FUN_404119e8 */

/* Boundary evidence: original MIPS .pdata 404119e8..40411b83. Semantic name remains unreviewed. */

void FUN_404119e8(undefined4 *param_1)

{
  bool bVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int local_20;
  
  bVar1 = false;
  *param_1 = &PTR_FUN_40401a10;
  param_1[1] = &PTR_LAB_40401a00;
  if (param_1[4] != 0) {
    local_20 = FUN_40410db8();
    iVar3 = param_1[4];
    iVar4 = param_1[3] + DAT_404304bc;
    *(undefined4 *)(iVar4 + 0xc) = *(undefined4 *)(iVar3 + 8);
    *(undefined4 *)(iVar4 + 0x10) = *(undefined4 *)(iVar3 + 0xc);
    *(undefined4 *)(iVar4 + 0x14) = *(undefined4 *)(iVar3 + 0x10);
  }
  if (param_1[2] != 0) {
    piVar2 = (int *)(param_1[2] + DAT_404304bc);
    if ((piVar2[0x1e] == 1) && (piVar2[0x16] == 0)) {
      bVar1 = true;
    }
    FUN_4040e010(piVar2);
  }
  if (param_1[3] != 0) {
    FUN_40417ff8((LPVOID)(param_1[3] + DAT_404304bc));
  }
  if ((param_1[5] == 0) || (param_1[4] == 0)) {
    if ((param_1[4] != 0) && ((-1 < local_20 && (iVar3 = __GetUserKData(8), DAT_40430480 == iVar3)))
       ) {
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_4043047c);
    }
  }
  else {
    if (bVar1) {
      FUN_4040b7c4(param_1[4]);
    }
    if ((-1 < local_20) && (iVar3 = __GetUserKData(8), DAT_40430480 == iVar3)) {
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_4043047c);
    }
    FUN_40405860((LPVOID)param_1[4]);
  }
  param_1[6] = 0x6c466445;
  return;
}



/* 40411b84 FUN_40411b84 */

/* Boundary evidence: original MIPS .pdata 40411b84..40411fa7. Semantic name remains unreviewed. */

uint FUN_40411b84(int param_1,ushort *param_2,int param_3,uint param_4,undefined4 *param_5)

{
  bool bVar1;
  undefined4 *puVar2;
  int *piVar3;
  int iVar4;
  uint uVar5;
  int *local_88;
  undefined4 *local_84;
  undefined1 auStack_80 [4];
  int local_7c;
  undefined1 auStack_70 [68];
  uint local_2c;
  
  local_2c = DAT_404303e4;
  bVar1 = false;
  if ((param_4 & 0x70) != 0x10) {
    uVar5 = 0x80030001;
    goto LAB_40411f6c;
  }
  if ((param_4 & 0x200000) != 0) {
    uVar5 = 0x800300ff;
    goto LAB_40411f6c;
  }
  if (((param_4 & 0x10000) == 0x10000) &&
     (uVar5 = FUN_4040ac8c(*(int *)(*(int *)(param_1 + 0x10) + 0xc),(wchar_t *)0x0,1),
     (int)uVar5 < 0)) goto LAB_40411f6c;
  if ((param_4 & 0x21000) == 0) {
LAB_40411cf4:
    if (param_3 != 2) goto LAB_40411dc0;
    uVar5 = FUN_4040caa8(param_4);
    uVar5 = FUN_4040f260(*(int *)(param_1 + 8) + DAT_404304bc,param_2,uVar5,&local_84);
    if ((int)uVar5 < 0) goto LAB_40411f6c;
    puVar2 = (undefined4 *)FUN_4040a638(0x20);
    if (puVar2 == (undefined4 *)0x0) {
      piVar3 = (int *)0x0;
    }
    else {
      piVar3 = FUN_4041d0e8(puVar2);
    }
    if (piVar3 != (int *)0x0) {
      if (*(int *)(param_1 + 0xc) == 0) {
        iVar4 = 0;
      }
      else {
        iVar4 = *(int *)(param_1 + 0xc) + DAT_404304bc;
      }
      uVar5 = FUN_4041bcb8((int)piVar3,(int)local_84,iVar4,*(undefined4 *)(param_1 + 0x10),1,0);
      if ((int)uVar5 < 0) {
        FUN_4041c150(piVar3);
        FUN_4040a65c(piVar3);
        goto LAB_40411e9c;
      }
      *(int *)(*(int *)(param_1 + 0x10) + 0x1c) = *(int *)(*(int *)(param_1 + 0x10) + 0x1c) + 1;
      goto LAB_40411f68;
    }
    uVar5 = 0x80030008;
LAB_40411e9c:
    FUN_4041977c(local_84);
  }
  else {
    iVar4 = *(int *)(param_1 + 8) + DAT_404304bc;
    if ((*(uint *)(iVar4 + 8) & 0x20) == 0) {
      piVar3 = (int *)(*(int *)(iVar4 + 0x5c) + DAT_404304bc);
      uVar5 = (**(code **)(*piVar3 + 0x50))(piVar3,param_2,auStack_80);
    }
    else {
      uVar5 = 0x80030102;
    }
    iVar4 = DAT_404304bc;
    if ((int)uVar5 < 0) {
      if (uVar5 != 0x80030002) goto LAB_40411f6c;
      goto LAB_40411cf4;
    }
    if ((local_7c == param_3) && ((param_4 & 0x1000) != 0)) {
      uVar5 = FUN_4040e9ec(*(int *)(param_1 + 8) + DAT_404304bc,param_2);
      if ((int)uVar5 < 0) goto LAB_40411f6c;
      goto LAB_40411cf4;
    }
    if (((local_7c != 2) || ((param_4 & 0x20000) == 0)) || (param_3 != 1)) {
      uVar5 = 0x80030050;
      goto LAB_40411f6c;
    }
    FUN_40410ed4(auStack_70,L"\\");
    uVar5 = FUN_4040eadc(*(int *)(param_1 + 8) + iVar4,param_2,auStack_70);
    if ((int)uVar5 < 0) goto LAB_40411f6c;
    bVar1 = true;
LAB_40411dc0:
    uVar5 = FUN_4040caa8(param_4);
    uVar5 = FUN_4040ebc0(*(int *)(param_1 + 8) + DAT_404304bc,param_2,uVar5,(int *)&local_88);
    if ((int)uVar5 < 0) goto LAB_40411f6c;
    puVar2 = (undefined4 *)FUN_4040a638(0x20);
    if (puVar2 == (undefined4 *)0x0) {
      piVar3 = (int *)0x0;
    }
    else {
      if (*(int *)(param_1 + 0xc) == 0) {
        iVar4 = 0;
      }
      else {
        iVar4 = *(int *)(param_1 + 0xc) + DAT_404304bc;
      }
      piVar3 = FUN_40410e20(puVar2,(int)local_88,iVar4,*(undefined4 *)(param_1 + 0x10),1);
    }
    if (piVar3 != (int *)0x0) {
      *(int *)(*(int *)(param_1 + 0x10) + 0x1c) = *(int *)(*(int *)(param_1 + 0x10) + 0x1c) + 1;
      if (bVar1) {
        uVar5 = FUN_40411000(param_1,(int)piVar3);
        if ((int)uVar5 < 0) {
          (**(code **)(*piVar3 + 8))(piVar3);
          goto LAB_40411f40;
        }
        uVar5 = 0x30200;
      }
LAB_40411f68:
      *param_5 = piVar3;
      goto LAB_40411f6c;
    }
    uVar5 = 0x80030008;
    FUN_4040e010(local_88);
  }
LAB_40411f40:
  FUN_4040e9ec(*(int *)(param_1 + 8) + DAT_404304bc,param_2);
LAB_40411f6c:
  FUN_4042f4c4(local_2c);
  return uVar5;
}



/* 40411fa8 FUN_40411fa8 */

/* Boundary evidence: original MIPS .pdata 40411fa8..404121e7. Semantic name remains unreviewed. */

uint FUN_40411fa8(int param_1,wchar_t *param_2,uint param_3,int param_4,int param_5,
                 undefined4 *param_6)

{
  BOOL BVar1;
  uint uVar2;
  int *piVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  int *local_78;
  wchar_t *local_74;
  ushort auStack_70 [32];
  undefined2 local_30;
  uint local_2c;
  
  local_2c = DAT_404303e4;
  iVar6 = *(int *)(param_1 + 0x10);
  uVar4 = 0x80030100;
  if (*(int *)(param_1 + 0xc) == 0) {
    iVar5 = 0;
  }
  else {
    iVar5 = *(int *)(param_1 + 0xc) + DAT_404304bc;
  }
  local_78 = (int *)0x0;
  local_30 = 0;
  local_74 = param_2;
  BVar1 = IsBadWritePtr(param_6,4);
  if (BVar1 != 0) {
    uVar2 = 0x80030009;
    goto LAB_404121ac;
  }
  *param_6 = 0;
  uVar2 = FUN_4040cd9c((ushort *)param_2);
  if ((int)uVar2 < 0) goto LAB_404121ac;
  if ((param_4 == 0) && (param_5 == 0)) {
    uVar2 = FUN_4040cc70(param_3);
    if ((int)uVar2 < 0) goto LAB_404121ac;
    if ((param_3 & 0x4070000) != 0) {
      uVar2 = 0x80030001;
      goto LAB_404121ac;
    }
    if (*(int *)(param_1 + 0x18) != 0x4c464445) {
      uVar2 = 0x80030006;
      goto LAB_404121ac;
    }
    uVar4 = FUN_40410db8();
    uVar2 = uVar4;
    if ((int)uVar4 < 0) goto LAB_404121ac;
    uVar2 = FUN_40410f78(param_1);
    if (-1 < (int)uVar2) {
      *(undefined4 *)(iVar5 + 0xc) = *(undefined4 *)(iVar6 + 8);
      *(undefined4 *)(iVar5 + 0x10) = *(undefined4 *)(iVar6 + 0xc);
      *(undefined4 *)(iVar5 + 0x14) = *(undefined4 *)(iVar6 + 0x10);
      FUN_40410ed4(auStack_70,local_74);
      uVar2 = FUN_40411b84(param_1,auStack_70,2,param_3,&local_78);
      piVar3 = local_78;
      if ((int)uVar2 < 0) goto LAB_40412168;
      *param_6 = local_78;
    }
  }
  else {
    uVar2 = 0x80030057;
    piVar3 = (int *)0x0;
LAB_40412168:
    if (piVar3 != (int *)0x0) {
      (**(code **)(*piVar3 + 8))(piVar3);
    }
  }
  if ((-1 < (int)uVar4) && (iVar6 = __GetUserKData(8), DAT_40430480 == iVar6)) {
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_4043047c);
  }
LAB_404121ac:
  FUN_4042f4c4(local_2c);
  return uVar2;
}



/* 404121e8 FUN_404121e8 */

/* Boundary evidence: original MIPS .pdata 404121e8..40412433. Semantic name remains unreviewed. */

uint FUN_404121e8(int param_1,wchar_t *param_2,int param_3,uint param_4,int param_5,
                 undefined4 *param_6)

{
  BOOL BVar1;
  uint uVar2;
  int *piVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  int *local_78;
  wchar_t *local_74;
  ushort auStack_70 [32];
  undefined2 local_30;
  uint local_2c;
  
  local_2c = DAT_404303e4;
  iVar6 = *(int *)(param_1 + 0x10);
  uVar4 = 0x80030100;
  if (*(int *)(param_1 + 0xc) == 0) {
    iVar5 = 0;
  }
  else {
    iVar5 = *(int *)(param_1 + 0xc) + DAT_404304bc;
  }
  local_78 = (int *)0x0;
  local_30 = 0;
  local_74 = param_2;
  BVar1 = IsBadWritePtr(param_6,4);
  if (BVar1 != 0) {
    uVar2 = 0x80030009;
    goto LAB_404123f8;
  }
  *param_6 = 0;
  uVar2 = FUN_4040cd9c((ushort *)param_2);
  if ((int)uVar2 < 0) goto LAB_404123f8;
  if ((param_3 == 0) && (param_5 == 0)) {
    uVar2 = FUN_4040cc70(param_4);
    if ((int)uVar2 < 0) goto LAB_404123f8;
    if ((param_4 & 0x21000) != 0) {
      uVar2 = 0x800300ff;
      goto LAB_404123f8;
    }
    if ((param_4 & 0x4050000) != 0) {
      uVar2 = 0x80030001;
      goto LAB_404123f8;
    }
    if (*(int *)(param_1 + 0x18) != 0x4c464445) {
      uVar2 = 0x80030006;
      goto LAB_404123f8;
    }
    uVar4 = FUN_40410db8();
    uVar2 = uVar4;
    if ((int)uVar4 < 0) goto LAB_404123f8;
    *(undefined4 *)(iVar5 + 0xc) = *(undefined4 *)(iVar6 + 8);
    *(undefined4 *)(iVar5 + 0x10) = *(undefined4 *)(iVar6 + 0xc);
    *(undefined4 *)(iVar5 + 0x14) = *(undefined4 *)(iVar6 + 0x10);
    FUN_40410ed4(auStack_70,local_74);
    uVar2 = FUN_40411150(param_1,auStack_70,2,param_4,&local_78);
    piVar3 = local_78;
    if ((int)uVar2 < 0) goto LAB_404123b4;
    *param_6 = local_78;
  }
  else {
    uVar2 = 0x80030057;
    piVar3 = (int *)0x0;
LAB_404123b4:
    if (piVar3 != (int *)0x0) {
      (**(code **)(*piVar3 + 8))(piVar3);
    }
  }
  if ((-1 < (int)uVar4) && (iVar6 = __GetUserKData(8), DAT_40430480 == iVar6)) {
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_4043047c);
  }
LAB_404123f8:
  FUN_4042f4c4(local_2c);
  return uVar2;
}



/* 40412434 FUN_40412434 */

/* Boundary evidence: original MIPS .pdata 40412434..40412673. Semantic name remains unreviewed. */

uint FUN_40412434(int param_1,wchar_t *param_2,uint param_3,int param_4,int param_5,
                 undefined4 *param_6)

{
  BOOL BVar1;
  uint uVar2;
  int *piVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  int *local_78;
  wchar_t *local_74;
  ushort auStack_70 [32];
  undefined2 local_30;
  uint local_2c;
  
  local_2c = DAT_404303e4;
  iVar6 = *(int *)(param_1 + 0x10);
  uVar4 = 0x80030100;
  if (*(int *)(param_1 + 0xc) == 0) {
    iVar5 = 0;
  }
  else {
    iVar5 = *(int *)(param_1 + 0xc) + DAT_404304bc;
  }
  local_78 = (int *)0x0;
  local_30 = 0;
  local_74 = param_2;
  BVar1 = IsBadWritePtr(param_6,4);
  if (BVar1 != 0) {
    uVar2 = 0x80030009;
    goto LAB_40412638;
  }
  *param_6 = 0;
  uVar2 = FUN_4040cd9c((ushort *)param_2);
  if ((int)uVar2 < 0) goto LAB_40412638;
  if ((param_4 == 0) && (param_5 == 0)) {
    uVar2 = FUN_4040cc70(param_3);
    if ((int)uVar2 < 0) goto LAB_40412638;
    if ((param_3 & 0x4040000) != 0) {
      uVar2 = 0x80030001;
      goto LAB_40412638;
    }
    if (*(int *)(param_1 + 0x18) != 0x4c464445) {
      uVar2 = 0x80030006;
      goto LAB_40412638;
    }
    uVar4 = FUN_40410db8();
    uVar2 = uVar4;
    if ((int)uVar4 < 0) goto LAB_40412638;
    uVar2 = FUN_40410f78(param_1);
    if (-1 < (int)uVar2) {
      *(undefined4 *)(iVar5 + 0xc) = *(undefined4 *)(iVar6 + 8);
      *(undefined4 *)(iVar5 + 0x10) = *(undefined4 *)(iVar6 + 0xc);
      *(undefined4 *)(iVar5 + 0x14) = *(undefined4 *)(iVar6 + 0x10);
      FUN_40410ed4(auStack_70,local_74);
      uVar2 = FUN_40411b84(param_1,auStack_70,1,param_3,&local_78);
      piVar3 = local_78;
      if ((int)uVar2 < 0) goto LAB_404125f4;
      *param_6 = local_78;
    }
  }
  else {
    uVar2 = 0x80030057;
    piVar3 = (int *)0x0;
LAB_404125f4:
    if (piVar3 != (int *)0x0) {
      (**(code **)(*piVar3 + 8))(piVar3);
    }
  }
  if ((-1 < (int)uVar4) && (iVar6 = __GetUserKData(8), DAT_40430480 == iVar6)) {
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_4043047c);
  }
LAB_40412638:
  FUN_4042f4c4(local_2c);
  return uVar2;
}



/* 40412674 FUN_40412674 */

/* Boundary evidence: original MIPS .pdata 40412674..404128cb. Semantic name remains unreviewed. */

uint FUN_40412674(int param_1,wchar_t *param_2,int param_3,uint param_4,int param_5,int param_6,
                 undefined4 *param_7)

{
  BOOL BVar1;
  uint uVar2;
  int *piVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  int *local_78;
  wchar_t *local_74;
  ushort auStack_70 [32];
  undefined2 local_30;
  uint local_2c;
  
  local_2c = DAT_404303e4;
  iVar6 = *(int *)(param_1 + 0x10);
  uVar4 = 0x80030100;
  if (*(int *)(param_1 + 0xc) == 0) {
    iVar5 = 0;
  }
  else {
    iVar5 = *(int *)(param_1 + 0xc) + DAT_404304bc;
  }
  local_78 = (int *)0x0;
  local_30 = 0;
  local_74 = param_2;
  BVar1 = IsBadWritePtr(param_7,4);
  if (BVar1 != 0) {
    uVar2 = 0x80030009;
    goto LAB_40412890;
  }
  *param_7 = 0;
  uVar2 = FUN_4040cd9c((ushort *)param_2);
  if ((int)uVar2 < 0) goto LAB_40412890;
  if (param_6 != 0) {
LAB_40412744:
    uVar2 = 0x80030057;
    goto LAB_40412890;
  }
  uVar2 = FUN_4040cc70(param_4);
  if ((int)uVar2 < 0) goto LAB_40412890;
  if ((param_4 & 0x21000) != 0) {
    uVar2 = 0x800300ff;
    goto LAB_40412890;
  }
  if ((param_3 == 0) && ((param_4 & 0x4040000) == 0)) {
    if (*(int *)(param_1 + 0x18) != 0x4c464445) {
      uVar2 = 0x80030006;
      goto LAB_40412890;
    }
    if (param_5 != 0) goto LAB_40412744;
    uVar4 = FUN_40410db8();
    uVar2 = uVar4;
    if ((int)uVar4 < 0) goto LAB_40412890;
    *(undefined4 *)(iVar5 + 0xc) = *(undefined4 *)(iVar6 + 8);
    *(undefined4 *)(iVar5 + 0x10) = *(undefined4 *)(iVar6 + 0xc);
    *(undefined4 *)(iVar5 + 0x14) = *(undefined4 *)(iVar6 + 0x10);
    FUN_40410ed4(auStack_70,local_74);
    uVar2 = FUN_40411150(param_1,auStack_70,1,param_4,&local_78);
    piVar3 = local_78;
    if ((int)uVar2 < 0) goto LAB_4041284c;
    *param_7 = local_78;
  }
  else {
    uVar2 = 0x80030001;
    piVar3 = (int *)0x0;
LAB_4041284c:
    if (piVar3 != (int *)0x0) {
      (**(code **)(*piVar3 + 8))(piVar3);
    }
  }
  if ((-1 < (int)uVar4) && (iVar6 = __GetUserKData(8), DAT_40430480 == iVar6)) {
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_4043047c);
  }
LAB_40412890:
  FUN_4042f4c4(local_2c);
  return uVar2;
}



/* 404128cc FUN_404128cc */

/* Boundary evidence: original MIPS .pdata 404128cc..404129f3. Semantic name remains unreviewed. */

int FUN_404128cc(int param_1,uint param_2)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = *(int *)(param_1 + 0x10);
  if (*(int *)(param_1 + 0xc) == 0) {
    iVar3 = 0;
  }
  else {
    iVar3 = *(int *)(param_1 + 0xc) + DAT_404304bc;
  }
  if ((param_2 & 0xfffffff8) == 0) {
    if (*(int *)(param_1 + 0x18) == 0x4c464445) {
      iVar2 = FUN_40410db8();
      if (-1 < iVar2) {
        *(undefined4 *)(iVar3 + 0xc) = *(undefined4 *)(iVar4 + 8);
        *(undefined4 *)(iVar3 + 0x10) = *(undefined4 *)(iVar4 + 0xc);
        *(undefined4 *)(iVar3 + 0x14) = *(undefined4 *)(iVar4 + 0x10);
        piVar1 = (int *)(*(int *)(param_1 + 8) + DAT_404304bc);
        iVar2 = (**(code **)(*piVar1 + 0xc))(piVar1,param_2);
        iVar4 = __GetUserKData(8);
        if (DAT_40430480 == iVar4) {
          LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_4043047c);
        }
      }
    }
    else {
      iVar2 = -0x7ffcfffa;
    }
  }
  else {
    iVar2 = -0x7ffcff01;
  }
  return iVar2;
}



/* 404129f4 FUN_404129f4 */

/* Boundary evidence: original MIPS .pdata 404129f4..40412ae3. Semantic name remains unreviewed. */

int FUN_404129f4(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = *(int *)(param_1 + 0x10);
  if (*(int *)(param_1 + 0xc) == 0) {
    iVar2 = 0;
  }
  else {
    iVar2 = *(int *)(param_1 + 0xc) + DAT_404304bc;
  }
  if (*(int *)(param_1 + 0x18) == 0x4c464445) {
    iVar1 = FUN_40410db8();
    if (-1 < iVar1) {
      *(undefined4 *)(iVar2 + 0xc) = *(undefined4 *)(iVar3 + 8);
      *(undefined4 *)(iVar2 + 0x10) = *(undefined4 *)(iVar3 + 0xc);
      *(undefined4 *)(iVar2 + 0x14) = *(undefined4 *)(iVar3 + 0x10);
      iVar1 = FUN_4041196c(*(int *)(param_1 + 8) + DAT_404304bc);
      iVar3 = __GetUserKData(8);
      if (DAT_40430480 == iVar3) {
        LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_4043047c);
      }
    }
  }
  else {
    iVar1 = -0x7ffcfffa;
  }
  return iVar1;
}



/* 40412ae4 FUN_40412ae4 */

/* Boundary evidence: original MIPS .pdata 40412ae4..40412d2b. Semantic name remains unreviewed. */

int FUN_40412ae4(int param_1,int param_2,int param_3,int param_4,undefined4 *param_5)

{
  BOOL BVar1;
  undefined4 *puVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  undefined1 auStack_70 [64];
  undefined2 local_30;
  uint local_2c;
  
  local_2c = DAT_404303e4;
  iVar7 = *(int *)(param_1 + 0x10);
  iVar6 = -0x7ffcff00;
  if (*(int *)(param_1 + 0xc) == 0) {
    iVar5 = 0;
  }
  else {
    iVar5 = *(int *)(param_1 + 0xc) + DAT_404304bc;
  }
  local_30 = 0;
  BVar1 = IsBadWritePtr(param_5,4);
  if (BVar1 != 0) {
    iVar4 = -0x7ffcfff7;
    goto LAB_40412cf0;
  }
  *param_5 = 0;
  if (((param_2 == 0) && (param_3 == 0)) && (param_4 == 0)) {
    if (*(int *)(param_1 + 0x18) != 0x4c464445) {
      iVar4 = -0x7ffcfffa;
      goto LAB_40412cf0;
    }
    iVar6 = FUN_40410db8();
    iVar4 = iVar6;
    if (iVar6 < 0) goto LAB_40412cf0;
    uVar3 = *(uint *)(*(int *)(param_1 + 8) + DAT_404304bc + 8);
    if ((uVar3 & 0x40) == 0) {
      iVar4 = -0x7ffcfffb;
    }
    else if ((uVar3 & 0x20) == 0) {
      *(undefined4 *)(iVar5 + 0xc) = *(undefined4 *)(iVar7 + 8);
      iVar4 = 0;
      *(undefined4 *)(iVar5 + 0x10) = *(undefined4 *)(iVar7 + 0xc);
      *(undefined4 *)(iVar5 + 0x14) = *(undefined4 *)(iVar7 + 0x10);
      puVar2 = CoTaskMemAlloc(0xa8);
      if (puVar2 == (undefined4 *)0x0) {
        puVar2 = (undefined4 *)0x0;
      }
      else {
        iVar7 = *(int *)(param_1 + 0xc) + DAT_404304bc;
        if (*(int *)(param_1 + 0xc) == 0) {
          iVar7 = 0;
        }
        iVar5 = *(int *)(param_1 + 8) + DAT_404304bc;
        if (*(int *)(param_1 + 8) == 0) {
          iVar5 = 0;
        }
        puVar2 = FUN_4041d5dc(puVar2,iVar5,auStack_70,iVar7,*(undefined4 *)(param_1 + 0x10),1);
      }
      if (puVar2 == (undefined4 *)0x0) {
        iVar4 = -0x7ffcfff8;
      }
      else {
        *param_5 = puVar2;
        *(int *)(*(int *)(param_1 + 0x10) + 0x1c) = *(int *)(*(int *)(param_1 + 0x10) + 0x1c) + 1;
      }
    }
    else {
      iVar4 = -0x7ffcfefe;
    }
  }
  else {
    iVar4 = -0x7ffcffa9;
  }
  if ((-1 < iVar6) && (iVar6 = __GetUserKData(8), DAT_40430480 == iVar6)) {
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_4043047c);
  }
LAB_40412cf0:
  FUN_4042f4c4(local_2c);
  return iVar4;
}



/* 40412d2c FUN_40412d2c */

/* Boundary evidence: original MIPS .pdata 40412d2c..40412e63. Semantic name remains unreviewed. */

int FUN_40412d2c(int param_1,wchar_t *param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  ushort auStack_68 [32];
  undefined2 local_28;
  uint local_24;
  
  local_24 = DAT_404303e4;
  iVar3 = *(int *)(param_1 + 0x10);
  if (*(int *)(param_1 + 0xc) == 0) {
    iVar2 = 0;
  }
  else {
    iVar2 = *(int *)(param_1 + 0xc) + DAT_404304bc;
  }
  local_28 = 0;
  if (*(int *)(param_1 + 0x18) == 0x4c464445) {
    iVar1 = FUN_4040cd9c((ushort *)param_2);
    if (-1 < iVar1) {
      FUN_40410ed4(auStack_68,param_2);
      iVar1 = FUN_40410db8();
      if (-1 < iVar1) {
        *(undefined4 *)(iVar2 + 0xc) = *(undefined4 *)(iVar3 + 8);
        *(undefined4 *)(iVar2 + 0x10) = *(undefined4 *)(iVar3 + 0xc);
        *(undefined4 *)(iVar2 + 0x14) = *(undefined4 *)(iVar3 + 0x10);
        iVar1 = FUN_4040e9ec(*(int *)(param_1 + 8) + DAT_404304bc,auStack_68);
        iVar3 = __GetUserKData(8);
        if (DAT_40430480 == iVar3) {
          LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_4043047c);
        }
      }
    }
  }
  else {
    iVar1 = -0x7ffcfffa;
  }
  FUN_4042f4c4(local_24);
  return iVar1;
}



/* 40412e64 FUN_40412e64 */

/* Boundary evidence: original MIPS .pdata 40412e64..40412fcb. Semantic name remains unreviewed. */

int FUN_40412e64(int param_1,wchar_t *param_2,wchar_t *param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined1 auStack_b0 [64];
  undefined2 local_70;
  ushort auStack_68 [32];
  undefined2 local_28;
  uint local_24;
  
  local_24 = DAT_404303e4;
  iVar3 = *(int *)(param_1 + 0x10);
  if (*(int *)(param_1 + 0xc) == 0) {
    iVar2 = 0;
  }
  else {
    iVar2 = *(int *)(param_1 + 0xc) + DAT_404304bc;
  }
  local_28 = 0;
  local_70 = 0;
  if (*(int *)(param_1 + 0x18) == 0x4c464445) {
    iVar1 = FUN_4040cd9c((ushort *)param_2);
    if ((-1 < iVar1) && (iVar1 = FUN_4040cd9c((ushort *)param_3), -1 < iVar1)) {
      FUN_40410ed4(auStack_68,param_2);
      FUN_40410ed4(auStack_b0,param_3);
      iVar1 = FUN_40410db8();
      if (-1 < iVar1) {
        *(undefined4 *)(iVar2 + 0xc) = *(undefined4 *)(iVar3 + 8);
        *(undefined4 *)(iVar2 + 0x10) = *(undefined4 *)(iVar3 + 0xc);
        *(undefined4 *)(iVar2 + 0x14) = *(undefined4 *)(iVar3 + 0x10);
        iVar1 = FUN_4040eadc(*(int *)(param_1 + 8) + DAT_404304bc,auStack_68,auStack_b0);
        iVar3 = __GetUserKData(8);
        if (DAT_40430480 == iVar3) {
          LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_4043047c);
        }
      }
    }
  }
  else {
    iVar1 = -0x7ffcfffa;
  }
  FUN_4042f4c4(local_24);
  return iVar1;
}



/* 40412fcc FUN_40412fcc */

/* Boundary evidence: original MIPS .pdata 40412fcc..404131cf. Semantic name remains unreviewed. */

int FUN_40412fcc(int param_1,wchar_t *param_2,undefined4 *param_3,undefined4 *param_4,
                undefined4 *param_5)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  int iVar5;
  ushort *puVar6;
  int iVar7;
  undefined4 local_88;
  undefined4 local_84;
  undefined4 local_80;
  undefined4 local_7c;
  undefined4 local_78;
  undefined4 local_74;
  ushort auStack_70 [32];
  undefined2 local_30;
  uint local_2c;
  
  local_2c = DAT_404303e4;
  iVar7 = *(int *)(param_1 + 0x10);
  if (*(int *)(param_1 + 0xc) == 0) {
    iVar5 = 0;
  }
  else {
    iVar5 = *(int *)(param_1 + 0xc) + DAT_404304bc;
  }
  puVar6 = (ushort *)0x0;
  local_30 = 0;
  if (*(int *)(param_1 + 0x18) == 0x4c464445) {
    if ((param_2 == (wchar_t *)0x0) || (iVar1 = FUN_4040cd9c((ushort *)param_2), -1 < iVar1)) {
      puVar4 = (undefined4 *)0x0;
      if (param_3 != (undefined4 *)0x0) {
        IsBadReadPtr(param_3,8);
        local_78 = *param_3;
        local_74 = param_3[1];
        puVar4 = &local_78;
      }
      puVar2 = (undefined4 *)0x0;
      if (param_4 != (undefined4 *)0x0) {
        IsBadReadPtr(param_4,8);
        local_88 = *param_4;
        local_84 = param_4[1];
        puVar2 = &local_88;
      }
      puVar3 = (undefined4 *)0x0;
      if (param_5 != (undefined4 *)0x0) {
        IsBadReadPtr(param_5,8);
        local_80 = *param_5;
        local_7c = param_5[1];
        puVar3 = &local_80;
      }
      if (param_2 != (wchar_t *)0x0) {
        FUN_40410ed4(auStack_70,param_2);
        puVar6 = auStack_70;
      }
      iVar1 = FUN_40410db8();
      if (-1 < iVar1) {
        *(undefined4 *)(iVar5 + 0xc) = *(undefined4 *)(iVar7 + 8);
        *(undefined4 *)(iVar5 + 0x10) = *(undefined4 *)(iVar7 + 0xc);
        *(undefined4 *)(iVar5 + 0x14) = *(undefined4 *)(iVar7 + 0x10);
        iVar1 = FUN_4040f568((ushort *)(*(int *)(param_1 + 8) + DAT_404304bc),puVar6,puVar4,puVar2,
                             puVar3);
        iVar7 = __GetUserKData(8);
        if (DAT_40430480 == iVar7) {
          LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_4043047c);
        }
      }
    }
  }
  else {
    iVar1 = -0x7ffcfffa;
  }
  FUN_4042f4c4(local_2c);
  return iVar1;
}



/* 404131d0 FUN_404131d0 */

/* Boundary evidence: original MIPS .pdata 404131d0..4041332f. Semantic name remains unreviewed. */

int FUN_404131d0(int param_1,void *param_2)

{
  uint uVar1;
  BOOL BVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  uVar1 = DAT_404303e4;
  iVar5 = *(int *)(param_1 + 0x10);
  if (*(int *)(param_1 + 0xc) == 0) {
    iVar4 = 0;
  }
  else {
    iVar4 = *(int *)(param_1 + 0xc) + DAT_404304bc;
  }
  if (*(int *)(param_1 + 0x18) == 0x4c464445) {
    if ((param_2 == (void *)0x0) || (BVar2 = IsBadReadPtr(param_2,0x10), BVar2 != 0)) {
      iVar3 = -0x7ffcfff7;
    }
    else {
      iVar3 = FUN_40410db8();
      if (-1 < iVar3) {
        *(undefined4 *)(iVar4 + 0xc) = *(undefined4 *)(iVar5 + 8);
        *(undefined4 *)(iVar4 + 0x10) = *(undefined4 *)(iVar5 + 0xc);
        *(undefined4 *)(iVar4 + 0x14) = *(undefined4 *)(iVar5 + 0x10);
        iVar3 = FUN_4040f7dc(*(int *)(param_1 + 8) + DAT_404304bc);
        iVar5 = __GetUserKData(8);
        if (DAT_40430480 == iVar5) {
          LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_4043047c);
        }
      }
    }
  }
  else {
    iVar3 = -0x7ffcfffa;
  }
  FUN_4042f4c4(uVar1);
  return iVar3;
}



/* 40413330 FUN_40413330 */

/* Boundary evidence: original MIPS .pdata 40413330..4041343f. Semantic name remains unreviewed. */

int FUN_40413330(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = *(int *)(param_1 + 0x10);
  if (*(int *)(param_1 + 0xc) == 0) {
    iVar2 = 0;
  }
  else {
    iVar2 = *(int *)(param_1 + 0xc) + DAT_404304bc;
  }
  if (*(int *)(param_1 + 0x18) == 0x4c464445) {
    iVar1 = FUN_40410db8();
    if (-1 < iVar1) {
      *(undefined4 *)(iVar2 + 0xc) = *(undefined4 *)(iVar3 + 8);
      *(undefined4 *)(iVar2 + 0x10) = *(undefined4 *)(iVar3 + 0xc);
      *(undefined4 *)(iVar2 + 0x14) = *(undefined4 *)(iVar3 + 0x10);
      iVar1 = FUN_4040f8a0(*(int *)(param_1 + 8) + DAT_404304bc);
      iVar3 = __GetUserKData(8);
      if (DAT_40430480 == iVar3) {
        LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_4043047c);
      }
    }
  }
  else {
    iVar1 = -0x7ffcfffa;
  }
  return iVar1;
}



/* 40413440 FUN_40413440 */

/* Boundary evidence: original MIPS .pdata 40413440..404135c7. Semantic name remains unreviewed. */

int FUN_40413440(int param_1,void *param_2,uint param_3)

{
  BOOL BVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined1 auStack_70 [72];
  uint local_28;
  
  local_28 = DAT_404303e4;
  iVar5 = *(int *)(param_1 + 0x10);
  if (*(int *)(param_1 + 0xc) == 0) {
    iVar4 = 0;
  }
  else {
    iVar4 = *(int *)(param_1 + 0xc) + DAT_404304bc;
  }
  BVar1 = IsBadWritePtr(param_2,0x48);
  if (BVar1 == 0) {
    iVar3 = 0;
    if ((param_3 & 0xfffffffe) != 0) {
      iVar3 = -0x7ffcff01;
    }
    if ((-1 < iVar3) && (iVar3 = FUN_40410db8(), -1 < iVar3)) {
      *(undefined4 *)(iVar4 + 0xc) = *(undefined4 *)(iVar5 + 8);
      *(undefined4 *)(iVar4 + 0x10) = *(undefined4 *)(iVar5 + 0xc);
      *(undefined4 *)(iVar4 + 0x14) = *(undefined4 *)(iVar5 + 0x10);
      piVar2 = (int *)(*(int *)(param_1 + 8) + DAT_404304bc);
      iVar3 = (**(code **)(*piVar2 + 8))(piVar2,auStack_70,param_3);
      if (-1 < iVar3) {
        memcpy(param_2,auStack_70,0x48);
        *(undefined4 *)((int)param_2 + 4) = 1;
        *(undefined4 *)((int)param_2 + 0xc) = 0;
        *(undefined4 *)((int)param_2 + 8) = 0;
        *(undefined4 *)((int)param_2 + 0x2c) = 0;
        *(undefined4 *)((int)param_2 + 0x44) = 0;
      }
      iVar5 = __GetUserKData(8);
      if (DAT_40430480 == iVar5) {
        LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_4043047c);
      }
    }
  }
  else {
    iVar3 = -0x7ffcfff7;
  }
  FUN_4042f4c4(local_28);
  return iVar3;
}



/* 404135c8 FUN_404135c8 */

/* Boundary evidence: original MIPS .pdata 404135c8..404137bf. Semantic name remains unreviewed. */

int FUN_404135c8(int param_1,int *param_2,int *param_3)

{
  LPVOID pv;
  int iVar1;
  int iVar2;
  int iVar3;
  int local_30;
  undefined1 local_2c [4];
  int local_28 [2];
  
  pv = CoTaskMemAlloc(0x2000);
  if (pv == (LPVOID)0x0) {
    iVar3 = -0x7ffcfff8;
  }
  else {
    iVar3 = *(int *)(param_1 + 0x10);
    iVar1 = DAT_404304bc + *(int *)(param_1 + 0xc);
    *(undefined4 *)(iVar1 + 0xc) = *(undefined4 *)(iVar3 + 8);
    *(undefined4 *)(iVar1 + 0x10) = *(undefined4 *)(iVar3 + 0xc);
    *(undefined4 *)(iVar1 + 0x14) = *(undefined4 *)(iVar3 + 0x10);
    (**(code **)(*param_2 + 0x20))(param_2,local_2c);
    iVar3 = (**(code **)(*param_3 + 0x18))(param_3);
    if (-1 < iVar3) {
      iVar3 = *(int *)(param_1 + 0x10);
      iVar1 = DAT_404304bc + *(int *)(param_1 + 0xc);
      *(undefined4 *)(iVar1 + 0xc) = *(undefined4 *)(iVar3 + 8);
      *(undefined4 *)(iVar1 + 0x10) = *(undefined4 *)(iVar3 + 0xc);
      *(undefined4 *)(iVar1 + 0x14) = *(undefined4 *)(iVar3 + 0x10);
      iVar1 = 0;
      iVar3 = (**(code **)(*param_2 + 0x14))(param_2,0,pv,0x2000,&local_30);
      while (-1 < iVar3) {
        if (local_30 == 0) {
          iVar3 = 0;
          break;
        }
        iVar3 = (**(code **)(*param_3 + 0x10))(param_3,pv,local_30,local_28);
        if (iVar3 < 0) break;
        if (local_30 != local_28[0]) {
          iVar3 = -0x7ffcffe3;
          break;
        }
        iVar2 = *(int *)(param_1 + 0x10);
        iVar1 = local_28[0] + iVar1;
        iVar3 = DAT_404304bc + *(int *)(param_1 + 0xc);
        *(undefined4 *)(iVar3 + 0xc) = *(undefined4 *)(iVar2 + 8);
        *(undefined4 *)(iVar3 + 0x10) = *(undefined4 *)(iVar2 + 0xc);
        *(undefined4 *)(iVar3 + 0x14) = *(undefined4 *)(iVar2 + 0x10);
        iVar3 = (**(code **)(*param_2 + 0x14))(param_2,iVar1,pv,0x2000,&local_30);
      }
    }
  }
  CoTaskMemFree(pv);
  return iVar3;
}



/* 404137c0 FUN_404137c0 */

/* Boundary evidence: original MIPS .pdata 404137c0..40413d87. Semantic name remains unreviewed. */

int FUN_404137c0(int param_1,int *param_2,int *param_3,undefined4 *param_4,uint param_5)

{
  undefined4 *pv;
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  wchar_t *_Source;
  wchar_t *_Dest;
  undefined4 *_Dst;
  
  pv = CoTaskMemAlloc(0xf0);
  if (pv == (undefined4 *)0x0) {
    pv = (undefined4 *)0x0;
  }
  else {
    *(undefined2 *)(pv + 0x19) = 0;
    *(undefined2 *)(pv + 0x2a) = 0;
  }
  if (pv == (undefined4 *)0x0) {
    iVar2 = -0x7ffcfff8;
  }
  else {
    iVar2 = *(int *)(param_1 + 0x10);
    iVar1 = *(int *)(param_1 + 0xc) + DAT_404304bc;
    *(undefined4 *)(iVar1 + 0xc) = *(undefined4 *)(iVar2 + 8);
    *(undefined4 *)(iVar1 + 0x10) = *(undefined4 *)(iVar2 + 0xc);
    *(undefined4 *)(iVar1 + 0x14) = *(undefined4 *)(iVar2 + 0x10);
    iVar2 = (**(code **)(*param_2 + 0x20))(param_2,pv + 5);
    if ((-1 < iVar2) &&
       ((iVar2 = (**(code **)(*param_3 + 0x3c))(param_3,pv + 5), -1 < iVar2 ||
        (iVar2 == -0x7ffcffff)))) {
      iVar2 = *(int *)(param_1 + 0x10);
      iVar1 = *(int *)(param_1 + 0xc) + DAT_404304bc;
      *(undefined4 *)(iVar1 + 0xc) = *(undefined4 *)(iVar2 + 8);
      *(undefined4 *)(iVar1 + 0x10) = *(undefined4 *)(iVar2 + 0xc);
      *(undefined4 *)(iVar1 + 0x14) = *(undefined4 *)(iVar2 + 0x10);
      iVar2 = (**(code **)(*param_2 + 0x28))(param_2,pv + 4);
      if ((-1 < iVar2) &&
         ((iVar2 = (**(code **)(*param_3 + 0x40))(param_3,pv[4],0xffffffff), -1 < iVar2 ||
          (iVar2 == -0x7ffcffff)))) {
        iVar2 = *(int *)(param_1 + 0x10);
        iVar1 = *(int *)(param_1 + 0xc) + DAT_404304bc;
        _Source = (wchar_t *)(pv + 0x1a);
        *(undefined4 *)(iVar1 + 0xc) = *(undefined4 *)(iVar2 + 8);
        _Dst = pv + 9;
        *(undefined4 *)(iVar1 + 0x10) = *(undefined4 *)(iVar2 + 0xc);
        *(undefined4 *)(iVar1 + 0x14) = *(undefined4 *)(iVar2 + 0x10);
        iVar2 = (**(code **)(*param_2 + 0x40))(param_2,_Dst,_Source,0);
        while (iVar2 != -0x7ffcffee) {
          if (iVar2 < 0) goto LAB_40413ca8;
          if (*(ushort *)(pv + 0x2a) < 0x41) {
            *(ushort *)(pv + 0x19) = *(ushort *)(pv + 0x2a);
          }
          else {
            *(undefined2 *)(pv + 0x19) = 0x40;
          }
          memcpy(_Dst,_Source,(uint)*(ushort *)(pv + 0x19));
          if ((((param_4 == (undefined4 *)0x0) ||
               (iVar2 = FUN_4040d398((ushort *)_Source,param_4), iVar2 != 0)) &&
              ((iVar2 = pv[0x2b], iVar2 != 1 || ((param_5 & 1) != 0)))) &&
             ((iVar2 != 2 || ((param_5 & 2) != 0)))) {
            if (iVar2 == 1) {
              iVar2 = *(int *)(param_1 + 0x10);
              iVar1 = *(int *)(param_1 + 0xc) + DAT_404304bc;
              *(undefined4 *)(iVar1 + 0xc) = *(undefined4 *)(iVar2 + 8);
              *(undefined4 *)(iVar1 + 0x10) = *(undefined4 *)(iVar2 + 0xc);
              *(undefined4 *)(iVar1 + 0x14) = *(undefined4 *)(iVar2 + 0x10);
              iVar2 = (**(code **)(*param_2 + 0x34))(param_2,_Source,0x40,pv + 2);
              if (-1 < iVar2) {
                _Dest = (wchar_t *)(pv + 0x2c);
                wcscpy(_Dest,_Source);
                puVar3 = pv + 3;
                iVar2 = (**(code **)(*param_3 + 0x14))(param_3,_Dest,0x11,0,0,puVar3);
                if (iVar2 == -0x7ffcffb0) {
                  iVar2 = (**(code **)(*param_3 + 0x18))(param_3,_Dest,0,0x12,0,0,puVar3);
                }
                if (-1 < iVar2) {
                  iVar2 = FUN_404137c0(param_1,(int *)pv[2],(int *)*puVar3,(undefined4 *)0x0,param_5
                                      );
                  if (-1 < iVar2) {
                    (**(code **)(*(int *)pv[2] + 0x14))();
                    (**(code **)(*(int *)*puVar3 + 8))();
                    goto LAB_40413c48;
                  }
LAB_40413ce4:
                  if (pv[0x2b] == 1) {
                    (**(code **)(*(int *)pv[3] + 8))();
                  }
                  else {
                    (**(code **)(*(int *)pv[1] + 8))();
                  }
                  (**(code **)(*param_3 + 0x30))(param_3,pv + 0x2c);
                }
LAB_40413d44:
                if (pv[0x2b] == 1) {
                  (**(code **)(*(int *)pv[2] + 0x14))();
                }
                else {
                  (**(code **)(*(int *)*pv + 4))();
                }
              }
              goto LAB_40413ca8;
            }
            if (iVar2 == 2) {
              iVar2 = *(int *)(param_1 + 0x10);
              iVar1 = *(int *)(param_1 + 0xc) + DAT_404304bc;
              *(undefined4 *)(iVar1 + 0xc) = *(undefined4 *)(iVar2 + 8);
              *(undefined4 *)(iVar1 + 0x10) = *(undefined4 *)(iVar2 + 0xc);
              *(undefined4 *)(iVar1 + 0x14) = *(undefined4 *)(iVar2 + 0x10);
              iVar2 = (**(code **)(*param_2 + 0x3c))(param_2,_Source,0x40,pv);
              if (iVar2 < 0) goto LAB_40413ca8;
              wcscpy((wchar_t *)(pv + 0x2c),_Source);
              puVar3 = pv + 1;
              iVar2 = (**(code **)(*param_3 + 0xc))(param_3,pv + 0x2c,0x1011,0,0,puVar3);
              if (iVar2 < 0) goto LAB_40413d44;
              iVar2 = FUN_404135c8(param_1,(int *)*pv,(int *)*puVar3);
              if (iVar2 < 0) goto LAB_40413ce4;
              (**(code **)(*(int *)*pv + 4))();
              (**(code **)(*(int *)*puVar3 + 8))();
            }
          }
LAB_40413c48:
          iVar2 = *(int *)(param_1 + 0x10);
          iVar1 = *(int *)(param_1 + 0xc) + DAT_404304bc;
          *(undefined4 *)(iVar1 + 0xc) = *(undefined4 *)(iVar2 + 8);
          *(undefined4 *)(iVar1 + 0x10) = *(undefined4 *)(iVar2 + 0xc);
          *(undefined4 *)(iVar1 + 0x14) = *(undefined4 *)(iVar2 + 0x10);
          iVar2 = (**(code **)(*param_2 + 0x40))(param_2,_Dst,_Source,0);
        }
        iVar2 = 0;
      }
    }
  }
LAB_40413ca8:
  CoTaskMemFree(pv);
  return iVar2;
}



/* 40413d88 FUN_40413d88 */

/* Boundary evidence: original MIPS .pdata 40413d88..40413f07. Semantic name remains unreviewed. */

int FUN_40413d88(int param_1,void *param_2)

{
  BOOL BVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint local_28 [2];
  
  iVar4 = *(int *)(param_1 + 0xc);
  if (*(int *)(param_1 + 8) == 0) {
    iVar3 = 0;
  }
  else {
    iVar3 = *(int *)(param_1 + 8) + DAT_404304bc;
  }
  BVar1 = IsBadReadPtr(param_2,2);
  if (BVar1 == 0) {
    if ((param_1 == 4) || (*(int *)(param_1 + 0x14) != 0x4c464445)) {
      iVar2 = -0x7ffcfffa;
    }
    else {
      iVar2 = FUN_40410db8();
      if (-1 < iVar2) {
        if ((*(uint *)(DAT_404304bc + *(int *)(param_1 + 4) + 8) & 0x20) == 0) {
          *(undefined4 *)(iVar3 + 0xc) = *(undefined4 *)(iVar4 + 8);
          *(undefined4 *)(iVar3 + 0x10) = *(undefined4 *)(iVar4 + 0xc);
          *(undefined4 *)(iVar3 + 0x14) = *(undefined4 *)(iVar4 + 0x10);
          local_28[0] = *(uint *)(*(int *)(param_1 + 0xc) + 0x14);
          iVar2 = FUN_4041023c(DAT_404304bc + *(int *)(param_1 + 4),param_2,
                               *(int **)(*(int *)(param_1 + 0xc) + 0x10),local_28);
          *(uint *)(*(int *)(param_1 + 0xc) + 0x14) = local_28[0];
        }
        else {
          iVar2 = -0x7ffcfefe;
        }
        iVar4 = __GetUserKData(8);
        if (DAT_40430480 == iVar4) {
          LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_4043047c);
        }
      }
    }
  }
  else {
    iVar2 = -0x7ffcff04;
  }
  return iVar2;
}



/* 40413f08 FUN_40413f08 */

/* Boundary evidence: original MIPS .pdata 40413f08..40413fd3. Semantic name remains unreviewed. */

LONG FUN_40413f08(undefined4 *param_1)

{
  LONG LVar1;
  int iVar2;
  int iVar3;
  
  if ((param_1 != (undefined4 *)0x0) && (param_1[6] == 0x4c464445)) {
    LVar1 = InterlockedDecrement(param_1 + 7);
    if (LVar1 == 0) {
      if ((param_1[5] != 0) || ((*(uint *)(param_1[2] + DAT_404304bc + 8) & 0x20) == 0)) {
        iVar3 = param_1[4];
        iVar2 = param_1[3] + DAT_404304bc;
        *(undefined4 *)(iVar2 + 0xc) = *(undefined4 *)(iVar3 + 8);
        *(undefined4 *)(iVar2 + 0x10) = *(undefined4 *)(iVar3 + 0xc);
        *(undefined4 *)(iVar2 + 0x14) = *(undefined4 *)(iVar3 + 0x10);
      }
      FUN_404119e8(param_1);
      FUN_4040a65c(param_1);
      return 0;
    }
    if (-1 < LVar1) {
      return LVar1;
    }
  }
  return 0;
}



/* 40413fd4 FUN_40413fd4 */

/* Boundary evidence: original MIPS .pdata 40413fd4..404141db. Semantic name remains unreviewed. */

int FUN_40413fd4(int param_1,int param_2,int *param_3,undefined4 *param_4,int *param_5)

{
  int iVar1;
  BOOL BVar2;
  uint uVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  
  iVar6 = -0x7ffcff00;
  iVar1 = FUN_40409b68();
  if ((iVar1 == 0) ||
     ((param_3 != (int *)0x0 && (BVar2 = IsBadReadPtr(param_3,param_2 << 4), BVar2 != 0)))) {
    iVar1 = -0x7ffcfff7;
  }
  else if ((param_4 == (undefined4 *)0x0) || (iVar1 = FUN_4040ce80(param_4), -1 < iVar1)) {
    if (*(int *)(param_1 + 0x18) == 0x4c464445) {
      iVar6 = FUN_40410db8();
      iVar1 = iVar6;
      if (-1 < iVar6) {
        iVar1 = *(int *)(param_1 + 8) + DAT_404304bc;
        if ((*(uint *)(iVar1 + 8) & 0x20) == 0) {
          if (*(int *)(param_1 + 8) == 0) {
            iVar1 = 0;
          }
          iVar4 = iVar1 - DAT_404304bc;
          if (iVar1 == 0) {
            iVar4 = 0;
          }
          *(int *)(*(int *)(param_1 + 0xc) + DAT_404304bc + 0x24) = iVar4;
          iVar1 = *(int *)(param_1 + 0x10);
          iVar4 = *(int *)(param_1 + 0xc) + DAT_404304bc;
          *(undefined4 *)(iVar4 + 0xc) = *(undefined4 *)(iVar1 + 8);
          *(undefined4 *)(iVar4 + 0x10) = *(undefined4 *)(iVar1 + 0xc);
          *(undefined4 *)(iVar4 + 0x14) = *(undefined4 *)(iVar1 + 0x10);
          iVar1 = *(int *)(DAT_404304bc + *(int *)(param_1 + 8) + 0x5c);
          piVar5 = (int *)(iVar1 + DAT_404304bc);
          if (iVar1 == 0) {
            piVar5 = (int *)0x0;
          }
          uVar3 = FUN_40410ca4(param_2,param_3);
          iVar1 = FUN_404137c0(param_1,piVar5,param_5,param_4,uVar3);
        }
        else {
          iVar1 = -0x7ffcfefe;
        }
      }
    }
    else {
      iVar1 = -0x7ffcfffa;
    }
  }
  *(undefined4 *)(*(int *)(param_1 + 0xc) + DAT_404304bc + 0x24) = 0;
  if ((-1 < iVar6) && (iVar6 = __GetUserKData(8), DAT_40430480 == iVar6)) {
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_4043047c);
  }
  return iVar1;
}



/* 404141f0 FUN_404141f0 */

/* Boundary evidence: original MIPS .pdata 404141f0..4041421b. Semantic name remains unreviewed. */

void FUN_404141f0(int param_1)

{
  if (*(HLOCAL *)(param_1 + 0xc) != (HLOCAL)(param_1 + 0x20)) {
    LocalFree(*(HLOCAL *)(param_1 + 0xc));
  }
  return;
}



/* 4041421c FUN_4041421c */

void FUN_4041421c(int param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 4) = param_2;
  return;
}



/* 40414224 FUN_40414224 */

/* Boundary evidence: original MIPS .pdata 40414224..40414283. Semantic name remains unreviewed. */

void FUN_40414224(int *param_1)

{
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_40430428);
  (**(code **)(*param_1 + 4))(param_1,FUN_404141f0);
  FUN_4041e080(param_1 + 2);
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_40430428);
  return;
}



/* 40414284 FUN_40414284 */

/* Boundary evidence: original MIPS .pdata 40414284..4041436b. Semantic name remains unreviewed. */

undefined4 FUN_40414284(int param_1,int *param_2,wchar_t *param_3,uint param_4)

{
  int *piVar1;
  size_t sVar2;
  HLOCAL pvVar3;
  undefined4 uVar4;
  
  piVar1 = FUN_4041e204((int *)(param_1 + 8));
  if (piVar1 == (int *)0x0) {
    uVar4 = 0x8007000e;
  }
  else {
    piVar1[4] = *param_2;
    piVar1[5] = param_2[1];
    piVar1[6] = param_2[2];
    piVar1[7] = param_2[3];
    sVar2 = wcslen(param_3);
    if (sVar2 < 8) {
      piVar1[3] = (int)(piVar1 + 8);
    }
    else {
      pvVar3 = LocalAlloc(0,(sVar2 + 1) * 2);
      piVar1[3] = (int)pvVar3;
    }
    wcscpy((wchar_t *)piVar1[3],param_3);
    piVar1[2] = piVar1[3];
    FUN_4041dee8(param_1,param_4,piVar1);
    uVar4 = 0;
  }
  return uVar4;
}



/* 4041436c FUN_4041436c */

/* Boundary evidence: original MIPS .pdata 4041436c..4041449f. Semantic name remains unreviewed. */

int FUN_4041436c(int *param_1,wchar_t *param_2,LPCLSID param_3)

{
  size_t sVar1;
  uint uVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  wchar_t awStack_228 [260];
  uint local_20;
  
  local_20 = DAT_404303e4;
  iVar5 = 0;
  sVar1 = wcslen(param_2);
  if (sVar1 < 0x104) {
    wcscpy(awStack_228,param_2);
    CharLowerW(awStack_228);
    uVar2 = FUN_4041df1c(param_1,awStack_228);
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_40430428);
    piVar3 = FUN_4041de40(param_1,uVar2,awStack_228);
    if (piVar3 == (int *)0x0) {
      iVar5 = FUN_40406b68(awStack_228,param_3);
      if (-1 < iVar5) {
        iVar5 = FUN_40414284((int)param_1,(int *)param_3,awStack_228,uVar2);
      }
    }
    else {
      param_3->Data1 = piVar3[4];
      iVar4 = piVar3[5];
      param_3->Data2 = (short)iVar4;
      param_3->Data3 = (short)((uint)iVar4 >> 0x10);
      *(int *)param_3->Data4 = piVar3[6];
      *(int *)(param_3->Data4 + 4) = piVar3[7];
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_40430428);
    FUN_4042f4c4(local_20);
  }
  else {
    FUN_4042f4c4(local_20);
    iVar5 = -0x7ff8fff2;
  }
  return iVar5;
}



/* 404144a0 FUN_404144a0 */

/* Boundary evidence: original MIPS .pdata 404144a0..40414517. Semantic name remains unreviewed. */

undefined4 * FUN_404144a0(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_40401a58;
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_40430428);
  (**(code **)*param_1)(param_1,&PTR_LOOP_40430328);
  FUN_4041e064(param_1 + 2,0x30,0x20);
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_40430428);
  return param_1;
}



/* 40414518 FUN_40414518 */

/* Boundary evidence: original MIPS .pdata 40414518..4041468f. Semantic name remains unreviewed. */

int FUN_40414518(HKEY param_1,LPCWSTR param_2,wint_t *param_3,LPDWORD param_4)

{
  wint_t wVar1;
  LSTATUS LVar2;
  int iVar3;
  wint_t *pwVar4;
  HKEY local_20;
  DWORD DStack_1c;
  
  if (param_2 == (LPCWSTR)0x0) {
    LVar2 = 0;
    local_20 = param_1;
  }
  else {
    LVar2 = RegOpenKeyExW(param_1,param_2,0,0x20019,&local_20);
    if (LVar2 == 0x57) {
      LVar2 = 2;
    }
  }
  if (LVar2 == 0) {
    LVar2 = RegQueryValueExW(local_20,(LPCWSTR)0x0,(LPDWORD)0x0,&DStack_1c,(LPBYTE)param_3,param_4);
    if (LVar2 == 0x57) {
      LVar2 = 2;
    }
    if (LVar2 == 0) {
      pwVar4 = param_3;
      if (*param_3 == 0x22) {
        while( true ) {
          wVar1 = pwVar4[1];
          if ((wVar1 == 0) || (wVar1 == 0x22)) break;
          *pwVar4 = wVar1;
          pwVar4 = pwVar4 + 1;
        }
        *pwVar4 = 0;
        *param_4 = ((int)pwVar4 + (2 - (int)param_3) >> 1) << 1;
      }
      while (iVar3 = iswctype(*param_3,8), iVar3 != 0) {
        param_3 = param_3 + 1;
      }
      if (*param_3 == 0) {
        LVar2 = 2;
        *param_4 = 0;
      }
    }
    if (local_20 != param_1) {
      RegCloseKey(local_20);
    }
  }
  return LVar2;
}



/* 40414690 FUN_40414690 */

/* Boundary evidence: original MIPS .pdata 40414690..4041483f. Semantic name remains unreviewed. */

LSTATUS FUN_40414690(HKEY param_1,LPCWSTR param_2,wint_t *param_3,LPDWORD param_4,
                    undefined4 *param_5)

{
  LSTATUS LVar1;
  int iVar2;
  undefined4 uVar3;
  HKEY local_238;
  DWORD local_234;
  DWORD local_230 [2];
  WCHAR aWStack_228 [260];
  uint local_20;
  
  local_20 = DAT_404303e4;
  local_238 = (HKEY)0x0;
  LVar1 = RegOpenKeyExW(param_1,param_2,0,0x2001f,&local_238);
  if (LVar1 == 0x57) {
    LVar1 = 2;
    goto LAB_40414818;
  }
  if (LVar1 != 0) goto LAB_40414818;
  LVar1 = FUN_40414518(local_238,(LPCWSTR)0x0,param_3,param_4);
  if (LVar1 == 0) {
    local_234 = 0x208;
    *param_5 = 1;
    LVar1 = RegQueryValueExW(local_238,L"ThreadingModel",(LPDWORD)0x0,local_230,(LPBYTE)aWStack_228,
                             &local_234);
    if ((LVar1 == 0) && (local_230[0] == 1)) {
      iVar2 = lstrcmpiW(L"Apartment",aWStack_228);
      if (iVar2 == 0) {
        *param_5 = 0;
      }
      else {
        iVar2 = lstrcmpiW(L"Both",aWStack_228);
        if (iVar2 == 0) {
          uVar3 = 3;
LAB_40414800:
          *param_5 = uVar3;
        }
        else {
          iVar2 = lstrcmpiW(L"Free",aWStack_228);
          if (iVar2 == 0) {
            *param_5 = 1;
          }
          else {
            iVar2 = lstrcmpiW(L"Single",aWStack_228);
            if (iVar2 == 0) {
              uVar3 = 2;
              goto LAB_40414800;
            }
          }
        }
      }
    }
    LVar1 = 0;
  }
  RegCloseKey(local_238);
LAB_40414818:
  FUN_4042f4c4(local_20);
  return LVar1;
}



/* 40414840 FUN_40414840 */

undefined4 *
FUN_40414840(undefined4 *param_1,undefined4 param_2,int param_3,undefined4 param_4,
            undefined4 param_5,undefined4 param_6)

{
  *param_1 = param_2;
  param_1[1] = param_3;
  if (param_3 == 0) {
    param_3 = 8;
  }
  param_1[2] = param_3;
  param_1[3] = 0;
  param_1[4] = param_6;
  param_1[5] = param_5;
  param_1[6] = 0;
  param_1[7] = 0;
  param_1[8] = 0;
  param_1[9] = param_4;
  return param_1;
}



/* 40414880 FUN_40414880 */

/* Boundary evidence: original MIPS .pdata 40414880..404148e3. Semantic name remains unreviewed. */

undefined4 FUN_40414880(int param_1)

{
  HLOCAL _Dst;
  
  if (*(int *)(param_1 + 0xc) == 0) {
    _Dst = LocalAlloc(0,*(int *)(param_1 + 0x10) << 2);
    *(HLOCAL *)(param_1 + 0xc) = _Dst;
    if (_Dst == (HLOCAL)0x0) {
      return 0;
    }
    memset(_Dst,0,*(int *)(param_1 + 0x10) << 2);
  }
  return 1;
}



/* 404148e4 FUN_404148e4 */

/* Boundary evidence: original MIPS .pdata 404148e4..4041493f. Semantic name remains unreviewed. */

bool FUN_404148e4(size_t *param_1,int param_2,void *param_3)

{
  if (param_2 != 0) {
    memcpy(param_3,(void *)(param_1[2] + param_2 + 8),*param_1);
  }
  else {
    memset(param_3,0,*param_1);
  }
  return param_2 != 0;
}



/* 40414940 FUN_40414940 */

/* Boundary evidence: original MIPS .pdata 40414940..40414a6b. Semantic name remains unreviewed. */

void FUN_40414940(size_t *param_1,int *param_2,int *param_3,size_t *param_4,void *param_5)

{
  undefined4 *puVar1;
  size_t _Size;
  int iVar2;
  uint uVar3;
  int *piVar4;
  int *piVar5;
  
  piVar5 = (int *)*param_2;
  if (piVar5 == (int *)0xffffffff) {
    uVar3 = 0;
    if (param_1[4] != 0) {
      puVar1 = (undefined4 *)param_1[3];
      do {
        piVar5 = (int *)*puVar1;
        if (piVar5 != (int *)0x0) break;
        uVar3 = uVar3 + 1;
        puVar1 = puVar1 + 1;
      } while (uVar3 < param_1[4]);
    }
  }
  iVar2 = *piVar5;
  if (iVar2 == 0) {
    uVar3 = piVar5[1] + 1;
    if (uVar3 < param_1[4]) {
      piVar4 = (int *)(uVar3 * 4 + param_1[3]);
      do {
        iVar2 = *piVar4;
        if (iVar2 != 0) break;
        uVar3 = uVar3 + 1;
        piVar4 = piVar4 + 1;
      } while (uVar3 < param_1[4]);
    }
  }
  *param_2 = iVar2;
  _Size = param_1[1];
  if (_Size == 0) {
    _Size = piVar5[3];
    *param_3 = piVar5[2];
  }
  else {
    memcpy(param_3,piVar5 + 2,_Size);
  }
  if (param_4 != (size_t *)0x0) {
    *param_4 = _Size;
  }
  memcpy(param_5,(void *)((int)piVar5 + param_1[2] + 8),*param_1);
  return;
}



/* 40414a6c FUN_40414a6c */

/* Boundary evidence: original MIPS .pdata 40414a6c..40414b27. Semantic name remains unreviewed. */

void FUN_40414a6c(int param_1)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  
  if (*(int *)(param_1 + 0xc) != 0) {
    uVar3 = 0;
    if (*(int *)(param_1 + 0x10) != 0) {
      iVar2 = 0;
      do {
        for (piVar1 = *(int **)(iVar2 + *(int *)(param_1 + 0xc)); piVar1 != (int *)0x0;
            piVar1 = (int *)*piVar1) {
          if (*(int *)(param_1 + 4) == 0) {
            LocalFree((HLOCAL)piVar1[2]);
          }
        }
        uVar3 = uVar3 + 1;
        iVar2 = iVar2 + 4;
      } while (uVar3 < *(uint *)(param_1 + 0x10));
    }
    LocalFree(*(HLOCAL *)(param_1 + 0xc));
    *(undefined4 *)(param_1 + 0xc) = 0;
  }
  *(undefined4 *)(param_1 + 0x18) = 0;
  *(undefined4 *)(param_1 + 0x1c) = 0;
  FUN_4041e2d0(*(undefined4 **)(param_1 + 0x20));
  *(undefined4 *)(param_1 + 0x20) = 0;
  return;
}



/* 40414b28 FUN_40414b28 */

/* Boundary evidence: original MIPS .pdata 40414b28..40414b7f. Semantic name remains unreviewed. */

undefined4 FUN_40414b28(int param_1,int param_2,void *param_3,size_t param_4)

{
  int iVar1;
  undefined4 uVar2;
  void *_Buf1;
  size_t _Size;
  
  _Size = *(size_t *)(param_1 + 4);
  if (_Size == 0) {
    _Buf1 = *(void **)(param_2 + 8);
    _Size = *(size_t *)(param_2 + 0xc);
  }
  else {
    _Buf1 = (void *)(param_2 + 8);
  }
  if ((_Size == param_4) && (iVar1 = memcmp(_Buf1,param_3,_Size), iVar1 == 0)) {
    uVar2 = 1;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}



/* 40414b80 FUN_40414b80 */

/* Boundary evidence: original MIPS .pdata 40414b80..40414c13. Semantic name remains unreviewed. */

undefined4 FUN_40414b80(int param_1,int param_2,void *param_3,SIZE_T param_4)

{
  HLOCAL pvVar1;
  void *_Dst;
  size_t _Size;
  
  if (*(int *)(param_1 + 4) == 0) {
    pvVar1 = LocalAlloc(0,param_4);
    *(HLOCAL *)(param_2 + 8) = pvVar1;
    if (pvVar1 == (HLOCAL)0x0) {
      return 0;
    }
    *(SIZE_T *)(param_2 + 0xc) = param_4;
  }
  _Size = *(size_t *)(param_1 + 4);
  if (_Size == 0) {
    _Dst = *(void **)(param_2 + 8);
    _Size = *(size_t *)(param_2 + 0xc);
  }
  else {
    _Dst = (void *)(param_2 + 8);
  }
  memcpy(_Dst,param_3,_Size);
  return 1;
}



/* 40414c14 FUN_40414c14 */

/* Boundary evidence: original MIPS .pdata 40414c14..40414d67. Semantic name remains unreviewed. */

undefined4 FUN_40414c14(int param_1,byte *param_2,size_t param_3)

{
  byte bVar1;
  int *piVar2;
  uint uVar3;
  int iVar4;
  size_t sVar5;
  byte *pbVar6;
  int *piVar7;
  
  if (*(int *)(param_1 + 0xc) != 0) {
    if (*(code **)(param_1 + 0x14) == (code *)0x0) {
      uVar3 = 0;
      pbVar6 = param_2;
      for (sVar5 = param_3; sVar5 != 0; sVar5 = sVar5 - 1) {
        bVar1 = *pbVar6;
        pbVar6 = pbVar6 + 1;
        uVar3 = uVar3 * 0x101 + (uint)bVar1;
      }
      uVar3 = uVar3 % *(uint *)(param_1 + 0x10);
      if (*(uint *)(param_1 + 0x10) == 0) {
        trap(0x1c00);
      }
    }
    else {
      uVar3 = (**(code **)(param_1 + 0x14))(param_2,param_3);
      uVar3 = uVar3 % *(uint *)(param_1 + 0x10);
      if (*(uint *)(param_1 + 0x10) == 0) {
        trap(0x1c00);
      }
    }
    piVar7 = (int *)(uVar3 * 4 + *(int *)(param_1 + 0xc));
    for (piVar2 = (int *)*piVar7; piVar2 != (int *)0x0; piVar2 = (int *)*piVar2) {
      iVar4 = FUN_40414b28(param_1,(int)piVar2,param_2,param_3);
      if (iVar4 != 0) {
        *piVar7 = *piVar2;
        *piVar2 = *(undefined4 *)(param_1 + 0x1c);
        *(int **)(param_1 + 0x1c) = piVar2;
        *(int *)(param_1 + 0x18) = *(int *)(param_1 + 0x18) + -1;
        if (*(int *)(param_1 + 4) == 0) {
          LocalFree((HLOCAL)piVar2[2]);
        }
        return 1;
      }
      piVar7 = piVar2;
    }
  }
  return 0;
}



/* 40414d68 FUN_40414d68 */

/* Boundary evidence: original MIPS .pdata 40414d68..40414d83. Semantic name remains unreviewed. */

void FUN_40414d68(int param_1)

{
  FUN_40414a6c(param_1);
  return;
}



/* 40414d84 FUN_40414d84 */

/* Boundary evidence: original MIPS .pdata 40414d84..40414ec7. Semantic name remains unreviewed. */

size_t FUN_40414d84(size_t *param_1,undefined4 param_2,void *param_3,SIZE_T param_4,void *param_5)

{
  undefined4 *puVar1;
  void *_Dst;
  int iVar2;
  size_t *psVar3;
  size_t sVar4;
  
  if (param_1[7] == 0) {
    puVar1 = FUN_4041e254(param_1 + 8,param_1[9],*param_1 + param_1[2] + 8);
    if (puVar1 == (undefined4 *)0x0) {
      return 0;
    }
    iVar2 = param_1[9] - 1;
    psVar3 = (size_t *)((int)puVar1 + (*param_1 + param_1[2] + 8) * iVar2 + 0xc);
    for (; -1 < iVar2; iVar2 = iVar2 + -1) {
      *psVar3 = param_1[7];
      param_1[7] = (size_t)psVar3;
      psVar3 = (size_t *)((int)psVar3 + (-param_1[2] - *param_1) + -8);
    }
  }
  sVar4 = param_1[7];
  *(undefined4 *)(sVar4 + 4) = param_2;
  iVar2 = FUN_40414b80((int)param_1,sVar4,param_3,param_4);
  if (iVar2 == 0) {
    return 0;
  }
  _Dst = (void *)(param_1[2] + sVar4 + 8);
  if (param_5 == (void *)0x0) {
    memset(_Dst,0,*param_1);
  }
  else {
    memcpy(_Dst,param_5,*param_1);
  }
  param_1[7] = *(size_t *)param_1[7];
  param_1[6] = param_1[6] + 1;
  return sVar4;
}



/* 40414ec8 FUN_40414ec8 */

/* Boundary evidence: original MIPS .pdata 40414ec8..40414fcf. Semantic name remains unreviewed. */

int FUN_40414ec8(int param_1,byte *param_2,size_t param_3,uint *param_4)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  size_t sVar4;
  byte *pbVar5;
  int *piVar6;
  
  if (*(code **)(param_1 + 0x14) == (code *)0x0) {
    uVar2 = 0;
    pbVar5 = param_2;
    for (sVar4 = param_3; sVar4 != 0; sVar4 = sVar4 - 1) {
      bVar1 = *pbVar5;
      pbVar5 = pbVar5 + 1;
      uVar2 = uVar2 * 0x101 + (uint)bVar1;
    }
    uVar2 = uVar2 % *(uint *)(param_1 + 0x10);
    if (*(uint *)(param_1 + 0x10) == 0) {
      trap(0x1c00);
    }
  }
  else {
    uVar2 = (**(code **)(param_1 + 0x14))(param_2,param_3);
    uVar2 = uVar2 % *(uint *)(param_1 + 0x10);
    if (*(uint *)(param_1 + 0x10) == 0) {
      trap(0x1c00);
    }
  }
  *param_4 = uVar2;
  if (*(int *)(param_1 + 0xc) != 0) {
    for (piVar6 = *(int **)(uVar2 * 4 + *(int *)(param_1 + 0xc)); piVar6 != (int *)0x0;
        piVar6 = (int *)*piVar6) {
      iVar3 = FUN_40414b28(param_1,(int)piVar6,param_2,param_3);
      if (iVar3 != 0) {
        return (int)piVar6;
      }
    }
  }
  return 0;
}



/* 40414fd0 FUN_40414fd0 */

/* Boundary evidence: original MIPS .pdata 40414fd0..40415017. Semantic name remains unreviewed. */

void FUN_40414fd0(size_t *param_1,byte *param_2,size_t param_3,void *param_4)

{
  int iVar1;
  uint auStack_18 [2];
  
  iVar1 = FUN_40414ec8((int)param_1,param_2,param_3,auStack_18);
  FUN_404148e4(param_1,iVar1,param_4);
  return;
}



/* 40415018 FUN_40415018 */

/* Boundary evidence: original MIPS .pdata 40415018..4041510f. Semantic name remains unreviewed. */

undefined4 FUN_40415018(size_t *param_1,byte *param_2,size_t param_3,void *param_4)

{
  int iVar1;
  undefined4 *puVar2;
  void *_Dst;
  uint local_20 [2];
  
  iVar1 = FUN_40414ec8((int)param_1,param_2,param_3,local_20);
  if (iVar1 == 0) {
    iVar1 = FUN_40414880((int)param_1);
    if (iVar1 == 0) {
      return 0;
    }
    puVar2 = (undefined4 *)FUN_40414d84(param_1,local_20[0],param_2,param_3,param_4);
    if (puVar2 == (undefined4 *)0x0) {
      return 0;
    }
    *puVar2 = *(undefined4 *)(local_20[0] * 4 + param_1[3]);
    *(undefined4 **)(local_20[0] * 4 + param_1[3]) = puVar2;
  }
  else {
    _Dst = (void *)(param_1[2] + iVar1 + 8);
    if (param_4 == (void *)0x0) {
      memset(_Dst,0,*param_1);
    }
    else {
      memcpy(_Dst,param_4,*param_1);
    }
  }
  return 1;
}



/* 40415118 FUN_40415118 */

/* Boundary evidence: original MIPS .pdata 40415118..40415133. Semantic name remains unreviewed. */

void FUN_40415118(undefined4 param_1,SIZE_T param_2)

{
  CoTaskMemAlloc(param_2);
  return;
}



/* 40415134 FUN_40415134 */

/* Boundary evidence: original MIPS .pdata 40415134..40415153. Semantic name remains unreviewed. */

void FUN_40415134(undefined4 param_1,LPVOID param_2,SIZE_T param_3)

{
  CoTaskMemRealloc(param_2,param_3);
  return;
}



/* 40415154 FUN_40415154 */

/* Boundary evidence: original MIPS .pdata 40415154..4041516f. Semantic name remains unreviewed. */

void FUN_40415154(undefined4 param_1,LPVOID param_2)

{
  CoTaskMemFree(param_2);
  return;
}



/* 40415170 FUN_40415170 */

/* Boundary evidence: original MIPS .pdata 40415170..4041518b. Semantic name remains unreviewed. */

void FUN_40415170(undefined4 param_1,LPVOID param_2)

{
  CoTaskMemFree(param_2);
  return;
}



/* 4041518c FUN_4041518c */

/* Boundary evidence: original MIPS .pdata 4041518c..404151a7. Semantic name remains unreviewed. */

void FUN_4041518c(undefined4 param_1,HLOCAL param_2)

{
  LocalSize(param_2);
  return;
}



/* 404151a8 FUN_404151a8 */

void FUN_404151a8(void)

{
  DAT_404303e0 = DAT_404303e0 + 1;
  return;
}



/* 40415260 FUN_40415260 */

undefined4 FUN_40415260(int param_1)

{
  return *(undefined4 *)(param_1 + 0x74);
}



/* 40415270 FUN_40415270 */

undefined4 FUN_40415270(int param_1)

{
  return *(undefined4 *)(param_1 + 0x78);
}



/* 40415280 FUN_40415280 */

undefined4 * FUN_40415280(int param_1,undefined4 *param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = param_3 * 8 + param_1;
  uVar2 = *(undefined4 *)(iVar1 + 0x68);
  *param_2 = *(undefined4 *)(iVar1 + 100);
  param_2[1] = uVar2;
  return param_2;
}



/* 404152ac FUN_404152ac */

void FUN_404152ac(int param_1,undefined4 *param_2,undefined4 *param_3,undefined4 *param_4)

{
  *param_3 = *(undefined4 *)(param_1 + 0x6c);
  param_3[1] = *(undefined4 *)(param_1 + 0x70);
  *param_2 = *(undefined4 *)(param_1 + 0x6c);
  param_2[1] = *(undefined4 *)(param_1 + 0x70);
  *param_4 = *(undefined4 *)(param_1 + 100);
  param_4[1] = *(undefined4 *)(param_1 + 0x68);
  return;
}



/* 40415300 FUN_40415300 */

/* Boundary evidence: original MIPS .pdata 40415300..4041537b. Semantic name remains unreviewed. */

int FUN_40415300(int *param_1,uint param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 uVar2;
  int local_20 [2];
  
  iVar1 = FUN_4041ef6c((int)param_1,param_2,0,local_20);
  if (-1 < iVar1) {
    uVar2 = FUN_40415260(local_20[0]);
    *param_3 = uVar2;
    FUN_4041eb24(param_1,param_2);
  }
  return iVar1;
}



/* 4041537c FUN_4041537c */

/* Boundary evidence: original MIPS .pdata 4041537c..404153f7. Semantic name remains unreviewed. */

int FUN_4041537c(int *param_1,uint param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 uVar2;
  int local_20 [2];
  
  iVar1 = FUN_4041ef6c((int)param_1,param_2,0,local_20);
  if (-1 < iVar1) {
    uVar2 = FUN_40415270(local_20[0]);
    *param_3 = uVar2;
    FUN_4041eb24(param_1,param_2);
  }
  return iVar1;
}



/* 404153f8 FUN_404153f8 */

/* Boundary evidence: original MIPS .pdata 404153f8..404154a3. Semantic name remains unreviewed. */

int FUN_404153f8(int *param_1,uint param_2,int param_3,undefined4 *param_4)

{
  int iVar1;
  undefined4 *puVar2;
  int local_28 [2];
  undefined4 auStack_20 [2];
  
  iVar1 = FUN_4041ef6c((int)param_1,param_2,0,local_28);
  if (-1 < iVar1) {
    if (param_3 == 2) {
      param_3 = 1;
    }
    puVar2 = FUN_40415280(local_28[0],auStack_20,param_3);
    *param_4 = *puVar2;
    param_4[1] = puVar2[1];
    FUN_4041eb24(param_1,param_2);
  }
  return iVar1;
}



/* 404154a4 FUN_404154a4 */

/* Boundary evidence: original MIPS .pdata 404154a4..40415533. Semantic name remains unreviewed. */

int FUN_404154a4(int *param_1,uint param_2,undefined4 *param_3,undefined4 *param_4,
                undefined4 *param_5)

{
  int iVar1;
  int local_20 [2];
  
  iVar1 = FUN_4041ef6c((int)param_1,param_2,0,local_20);
  if (-1 < iVar1) {
    FUN_404152ac(local_20[0],param_3,param_4,param_5);
    FUN_4041eb24(param_1,param_2);
  }
  return iVar1;
}



/* 40415534 FUN_40415534 */

/* Boundary evidence: original MIPS .pdata 40415534..40415557. Semantic name remains unreviewed. */

void FUN_40415534(int param_1,uint param_2,int param_3,uint param_4,uint *param_5)

{
  FUN_4041f8bc((int *)(param_1 + 0x20c),param_2,param_3,param_4,param_5);
  return;
}



/* 40415558 FUN_40415558 */

undefined4 FUN_40415558(int param_1)

{
  return *(undefined4 *)(param_1 + 0x200);
}



/* 40415560 FUN_40415560 */

void FUN_40415560(int param_1)

{
  *(undefined4 *)(param_1 + 0x200) = 0;
  return;
}



/* 40415568 FUN_40415568 */

void FUN_40415568(int param_1)

{
  *(int *)(param_1 + 0x20) = *(int *)(param_1 + 0x20) + 1;
  return;
}



/* 40415578 FUN_40415578 */

/* Boundary evidence: original MIPS .pdata 40415578..404155c3. Semantic name remains unreviewed. */

LPVOID FUN_40415578(LPVOID param_1,uint param_2)

{
  FUN_40421570((int)param_1);
  if ((param_2 & 1) != 0) {
    FUN_4040a65c(param_1);
  }
  return param_1;
}



/* 404155c4 FUN_404155c4 */

void FUN_404155c4(int param_1,undefined2 param_2,undefined2 param_3)

{
  *(undefined2 *)(param_1 + 0x1e) = param_2;
  *(undefined2 *)(param_1 + 0x1c) = param_3;
  return;
}



/* 404155d0 FUN_404155d0 */

undefined2 FUN_404155d0(int param_1)

{
  return *(undefined2 *)(param_1 + 0x1c);
}



/* 404155d8 FUN_404155d8 */

undefined2 FUN_404155d8(int param_1)

{
  return *(undefined2 *)(param_1 + 0x1e);
}



/* 404155e0 FUN_404155e0 */

/* Boundary evidence: original MIPS .pdata 404155e0..40415623. Semantic name remains unreviewed. */

void FUN_404155e0(int *param_1,uint *param_2)

{
  int iVar1;
  
  iVar1 = FUN_40421ea8(param_1,(uint *)(param_1 + 0x13));
  if (-1 < iVar1) {
    *param_2 = param_1[0x13];
  }
  return;
}



/* 40415624 FUN_40415624 */

void FUN_40415624(int param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 0x30) = param_2;
  *(undefined4 *)(param_1 + 0x3c) = 0xffffffff;
  return;
}



/* 40415638 FUN_40415638 */

/* Boundary evidence: original MIPS .pdata 40415638..40415653. Semantic name remains unreviewed. */

void FUN_40415638(int param_1)

{
  FUN_404248c4(param_1);
  return;
}



/* 40415654 FUN_40415654 */

/* Boundary evidence: original MIPS .pdata 40415654..404156c7. Semantic name remains unreviewed. */

void FUN_40415654(int *param_1,int param_2)

{
  undefined2 uVar1;
  undefined2 uVar2;
  
  param_1[8] = *(int *)(param_2 + 0x20);
  param_1[9] = *(int *)(param_2 + 0x24);
  uVar1 = FUN_404155d0(param_2);
  uVar2 = FUN_404155d8(param_2);
  FUN_404155c4((int)param_1,uVar2,uVar1);
  FUN_404252fc(param_1,param_2);
  return;
}



/* 404156c8 FUN_404156c8 */

undefined2 FUN_404156c8(int param_1)

{
  return *(undefined2 *)(param_1 + 0x4a6);
}



/* 404156d0 FUN_404156d0 */

int FUN_404156d0(int param_1)

{
  return param_1 + 4;
}



/* 404156d8 FUN_404156d8 */

int FUN_404156d8(int param_1)

{
  return param_1 + 0x23c;
}



/* 404156e0 FUN_404156e0 */

int FUN_404156e0(int param_1)

{
  return param_1 + 0x28c;
}



/* 404156e8 FUN_404156e8 */

int FUN_404156e8(int param_1)

{
  return param_1 + 0x20c;
}



/* 404156f0 FUN_404156f0 */

void FUN_404156f0(int param_1)

{
  ushort *puVar1;
  uint uVar2;
  int iVar3;
  
  if ((*(int *)(param_1 + 0x18) != 0) && (uVar2 = 0, *(int *)(param_1 + 8) != 0)) {
    iVar3 = 0;
    do {
      puVar1 = (ushort *)(iVar3 + DAT_404304bc + *(int *)(param_1 + 0x18));
      *puVar1 = *puVar1 & 0xfffe;
      *(undefined2 *)(iVar3 + DAT_404304bc + *(int *)(param_1 + 0x18) + 2) = 0;
      uVar2 = uVar2 + 1;
      iVar3 = iVar3 + 4;
    } while (uVar2 < *(uint *)(param_1 + 8));
  }
  return;
}



/* 4041575c FUN_4041575c */

/* Boundary evidence: original MIPS .pdata 4041575c..404157a7. Semantic name remains unreviewed. */

LPVOID FUN_4041575c(LPVOID param_1,uint param_2)

{
  FUN_404168e4((int)param_1);
  if ((param_2 & 1) != 0) {
    FUN_4040a65c(param_1);
  }
  return param_1;
}



/* 404157a8 FUN_404157a8 */

/* Boundary evidence: original MIPS .pdata 404157a8..404157c3. Semantic name remains unreviewed. */

void FUN_404157a8(SIZE_T param_1)

{
  FUN_4040a638(param_1);
  return;
}



/* 404157c4 FUN_404157c4 */

int FUN_404157c4(int param_1,int param_2,uint param_3)

{
  return (param_1 << (param_3 & 0x1f)) + param_2 + 0x200;
}



/* 404157d4 FUN_404157d4 */

/* Boundary evidence: original MIPS .pdata 404157d4..40415877. Semantic name remains unreviewed. */

int FUN_404157d4(int *param_1)

{
  undefined2 uVar1;
  undefined2 extraout_var;
  uint uVar2;
  int iVar3;
  uint local_18 [2];
  
  iVar3 = 0;
  if ((param_1[0x122] == 0) && (iVar3 = FUN_404155e0(param_1 + 0x8f,local_18), -1 < iVar3)) {
    uVar1 = FUN_404156c8((int)param_1);
    uVar2 = FUN_404157c4(local_18[0],0,CONCAT22(extraout_var,uVar1));
    if ((uint)param_1[0x128] < uVar2) {
      iVar3 = (**(code **)(**(int **)(*param_1 + DAT_404304bc) + 0x18))();
    }
  }
  return iVar3;
}



/* 40415878 FUN_40415878 */

/* Boundary evidence: original MIPS .pdata 40415878..40415907. Semantic name remains unreviewed. */

undefined4 FUN_40415878(uint param_1,uint param_2,int *param_3,undefined2 *param_4)

{
  int iVar1;
  undefined4 uVar2;
  
  do {
    iVar1 = FUN_4040d1fc(param_2);
    if (iVar1 != 0) {
      *param_4 = (short)param_2;
      break;
    }
    param_2 = param_2 >> 1 & 0xffff;
  } while (param_1 <= param_2);
  *param_3 = iVar1;
  if (iVar1 == 0) {
    uVar2 = 0x80030008;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}



/* 40415908 FUN_40415908 */

/* Boundary evidence: original MIPS .pdata 40415908..4041598b. Semantic name remains unreviewed. */

void FUN_40415908(uint param_1,uint param_2,int *param_3,undefined2 *param_4)

{
  int iVar1;
  
  iVar1 = FUN_40415878(param_1,param_2,param_3,param_4);
  if (iVar1 < 0) {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_404304c8);
    DAT_404314dc = 1;
    *param_3 = (int)&DAT_404304dc;
    if (0xfff < param_2) {
      param_2 = 0x1000;
    }
    *param_4 = (short)param_2;
  }
  return;
}



/* 4041598c FUN_4041598c */

/* Boundary evidence: original MIPS .pdata 4041598c..404159cf. Semantic name remains unreviewed. */

void FUN_4041598c(undefined *param_1)

{
  if (param_1 == &DAT_404304dc) {
    DAT_404314dc = 0;
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_404304c8);
  }
  else {
    FUN_4040d218(param_1);
  }
  return;
}



/* 404159d0 FUN_404159d0 */

/* Boundary evidence: original MIPS .pdata 404159d0..404159eb. Semantic name remains unreviewed. */

void FUN_404159d0(int param_1)

{
  FUN_404248c4(param_1);
  return;
}



/* 404159ec FUN_404159ec */

/* Boundary evidence: original MIPS .pdata 404159ec..40415a2b. Semantic name remains unreviewed. */

void FUN_404159ec(int param_1)

{
  FUN_4042192c((int *)(param_1 + 0x23c));
  FUN_4042192c((int *)(param_1 + 0x31c));
  FUN_40425618((int *)(param_1 + 0x28c));
  FUN_4041e9e0((int *)(param_1 + 0x20c));
  return;
}



/* 40415a2c FUN_40415a2c */

/* Boundary evidence: original MIPS .pdata 40415a2c..40415b4f. Semantic name remains unreviewed. */

int FUN_40415a2c(int *param_1)

{
  undefined2 uVar1;
  undefined2 uVar2;
  undefined2 extraout_var;
  undefined2 extraout_var_00;
  int iVar3;
  int *piVar4;
  undefined2 auStack_30 [2];
  undefined *local_2c [3];
  
  uVar1 = FUN_4040d6bc((int)param_1);
  uVar2 = FUN_4040d6bc((int)param_1);
  FUN_40415908(CONCAT22(extraout_var_00,uVar2),CONCAT22(extraout_var,uVar1),(int *)local_2c,
               auStack_30);
  piVar4 = *(int **)(*param_1 + DAT_404304bc);
  iVar3 = *piVar4;
  FUN_4040d6bc((int)param_1);
  iVar3 = (**(code **)(iVar3 + 0xc))(piVar4);
  if (-1 < iVar3) {
    FUN_404156c8((int)param_1);
    piVar4 = *(int **)(*param_1 + DAT_404304bc);
    iVar3 = *piVar4;
    FUN_4040d6bc((int)param_1);
    iVar3 = (**(code **)(iVar3 + 0x10))(piVar4);
  }
  FUN_4041598c(local_2c[0]);
  return iVar3;
}



/* 40415b50 FUN_40415b50 */

/* Boundary evidence: original MIPS .pdata 40415b50..40415c3b. Semantic name remains unreviewed. */

int FUN_40415b50(int *param_1,uint param_2)

{
  int iVar1;
  int *piVar2;
  
  if ((((param_1[0x11e] == 0) && (param_1[0x122] == 0)) &&
      ((param_1[0x124] == 0 || ((param_2 & 1) != 0)))) &&
     (((param_2 & 1) != 0 || (iVar1 = FUN_40415558((int)(param_1 + 1)), iVar1 != 0)))) {
    piVar2 = *(int **)(*param_1 + DAT_404304bc);
    iVar1 = *piVar2;
    FUN_4040d1f4(param_1 + 1);
    iVar1 = (**(code **)(iVar1 + 0x10))(piVar2);
    if (-1 < iVar1) {
      FUN_40415560((int)(param_1 + 1));
    }
  }
  else {
    iVar1 = 0;
  }
  return iVar1;
}



/* 40415c3c FUN_40415c3c */

/* Boundary evidence: original MIPS .pdata 40415c3c..40415daf. Semantic name remains unreviewed. */

void FUN_40415c3c(int *param_1,int param_2,int param_3,int param_4,short param_5,void *param_6,
                 uint *param_7)

{
  undefined2 uVar1;
  undefined2 extraout_var;
  undefined2 extraout_var_00;
  uint _Size;
  int iVar2;
  int *piVar3;
  int iVar4;
  
  iVar2 = DAT_404304bc;
  iVar4 = param_1[0x11d] + DAT_404304bc;
  if (param_1[0x11d] == 0) {
    iVar4 = 0;
  }
  uVar1 = FUN_404156c8((int)param_1);
  FUN_404157c4(param_2,0,CONCAT22(extraout_var,uVar1));
  piVar3 = *(int **)(*param_1 + iVar2);
  iVar2 = *piVar3;
  FUN_4040d6bc((int)param_1);
  iVar2 = (**(code **)(iVar2 + 0xc))(piVar3);
  if (-1 < iVar2) {
    _Size = (param_5 - param_4) + 1U & 0xffff;
    memcpy((void *)(param_4 + iVar4),param_6,_Size);
    uVar1 = FUN_404156c8((int)param_1);
    FUN_404157c4(param_3,0,CONCAT22(extraout_var_00,uVar1));
    piVar3 = *(int **)(*param_1 + DAT_404304bc);
    iVar2 = *piVar3;
    FUN_4040d6bc((int)param_1);
    iVar2 = (**(code **)(iVar2 + 0x10))(piVar3);
    if (-1 < iVar2) {
      *param_7 = _Size;
    }
  }
  return;
}



/* 40415db0 FUN_40415db0 */

/* Boundary evidence: original MIPS .pdata 40415db0..40415e3f. Semantic name remains unreviewed. */

undefined4 FUN_40415db0(int *param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  int *local_10 [2];
  
  if ((param_2 == 0) || (iVar1 = (**(code **)*param_1)(param_1,&DAT_40402264,local_10), iVar1 < 0))
  {
    uVar2 = (**(code **)(*param_1 + 0x14))(param_1);
  }
  else {
    uVar2 = (**(code **)(*local_10[0] + 0x10))();
    (**(code **)(*local_10[0] + 8))();
  }
  return uVar2;
}



/* 40415e40 FUN_40415e40 */

/* Boundary evidence: original MIPS .pdata 40415e40..40415eef. Semantic name remains unreviewed. */

uint FUN_40415e40(int *param_1,int param_2,DWORD param_3,DWORD param_4)

{
  uint uVar1;
  int *piVar2;
  int *local_20 [2];
  
  uVar1 = (**(code **)**(undefined4 **)(*param_1 + DAT_404304bc))
                    (*(undefined4 **)(*param_1 + DAT_404304bc),&DAT_40402264,local_20);
  if (-1 < (int)uVar1) {
    piVar2 = local_20[0] + -1;
    if (local_20[0] == (int *)0x0) {
      piVar2 = (int *)0x0;
    }
    uVar1 = FUN_4040ab88((int)piVar2,param_2,param_3,param_4);
    (**(code **)(*local_20[0] + 8))();
  }
  return uVar1;
}



/* 40415ef0 FUN_40415ef0 */

/* Boundary evidence: original MIPS .pdata 40415ef0..40415fb7. Semantic name remains unreviewed. */

uint FUN_40415ef0(int *param_1,DWORD param_2,DWORD param_3,DWORD param_4)

{
  uint uVar1;
  int *piVar2;
  int *local_20 [2];
  
  uVar1 = (**(code **)**(undefined4 **)(*param_1 + DAT_404304bc))
                    (*(undefined4 **)(*param_1 + DAT_404304bc),&DAT_40402264,local_20);
  if (-1 < (int)uVar1) {
    piVar2 = local_20[0] + -1;
    if (local_20[0] == (int *)0x0) {
      piVar2 = (int *)0x0;
    }
    uVar1 = FUN_4040ac1c((int)piVar2,param_2,param_3,param_4);
    (**(code **)(*local_20[0] + 8))();
  }
  return uVar1;
}



/* 40415fb8 FUN_40415fb8 */

/* Boundary evidence: original MIPS .pdata 40415fb8..40416057. Semantic name remains unreviewed. */

void FUN_40415fb8(int *param_1,uint param_2,int param_3,DWORD param_4,DWORD param_5)

{
  uint uVar1;
  
  if ((param_2 != 0) ||
     (((param_3 == 1 && (param_1[0x127] == 0)) ||
      (uVar1 = FUN_40415e40(param_1,param_3,param_4,param_5), -1 < (int)uVar1)))) {
    FUN_4041f4ac(param_1 + 0x83,param_2,param_3,param_4,param_5);
  }
  return;
}



/* 40416058 FUN_40416058 */

/* Boundary evidence: original MIPS .pdata 40416058..4041611b. Semantic name remains unreviewed. */

void FUN_40416058(int *param_1,uint param_2,DWORD param_3,DWORD param_4,DWORD param_5,
                 undefined4 param_6,undefined4 param_7,undefined4 param_8)

{
  uint uVar1;
  
  if ((param_2 == 0) && (uVar1 = FUN_40415ef0(param_1,param_3,param_4,param_5), (int)uVar1 < 0)) {
    return;
  }
  FUN_4041f54c(param_1 + 0x83,param_2,param_3,param_4,param_5,param_6,param_7,param_8);
  return;
}



/* 4041611c FUN_4041611c */

/* Boundary evidence: original MIPS .pdata 4041611c..40416207. Semantic name remains unreviewed. */

int FUN_4041611c(int *param_1,uint param_2,int param_3,undefined4 *param_4)

{
  int iVar1;
  undefined1 auStack_68 [16];
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  uint local_20;
  
  local_20 = DAT_404303e4;
  if (param_2 == 0) {
    iVar1 = (**(code **)(**(int **)(*param_1 + DAT_404304bc) + 0x24))
                      (*(int **)(*param_1 + DAT_404304bc),auStack_68,1);
    if (-1 < iVar1) {
      if ((param_3 == 0) || (local_50 = local_58, local_4c = local_54, param_3 == 1)) {
        *param_4 = local_50;
        param_4[1] = local_4c;
      }
      else {
        *param_4 = local_48;
        param_4[1] = local_44;
      }
    }
  }
  else {
    iVar1 = FUN_404153f8(param_1 + 0x83,param_2,param_3,param_4);
  }
  FUN_4042f4c4(local_20);
  return iVar1;
}



/* 40416208 FUN_40416208 */

/* Boundary evidence: original MIPS .pdata 40416208..404162e3. Semantic name remains unreviewed. */

int FUN_40416208(int *param_1,uint param_2,undefined4 *param_3,undefined4 *param_4,
                undefined4 *param_5)

{
  int iVar1;
  undefined1 auStack_68 [16];
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  uint local_20;
  
  local_20 = DAT_404303e4;
  if (param_2 == 0) {
    iVar1 = (**(code **)(**(int **)(*param_1 + DAT_404304bc) + 0x24))
                      (*(int **)(*param_1 + DAT_404304bc),auStack_68,1);
    if (-1 < iVar1) {
      *param_5 = local_50;
      param_5[1] = local_4c;
      *param_4 = local_58;
      param_4[1] = local_54;
      *param_3 = local_48;
      param_3[1] = local_44;
    }
  }
  else {
    iVar1 = FUN_404154a4(param_1 + 0x83,param_2,param_3,param_4,param_5);
  }
  FUN_4042f4c4(local_20);
  return iVar1;
}



/* 404162e4 FUN_404162e4 */

/* Boundary evidence: original MIPS .pdata 404162e4..40416327. Semantic name remains unreviewed. */

void FUN_404162e4(int param_1,int param_2,int param_3)

{
  int *piVar1;
  
  piVar1 = (int *)FUN_404156d8(param_2);
  FUN_404232ac((int *)(param_1 + 0x31c),piVar1,param_3);
  return;
}



/* 40416328 FUN_40416328 */

/* Boundary evidence: original MIPS .pdata 40416328..4041635f. Semantic name remains unreviewed. */

void FUN_40416328(int param_1,int param_2)

{
  int iVar1;
  
  if (param_2 == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = param_2 - DAT_404304bc;
  }
  *(int *)(param_1 + 0x24) = iVar1;
  FUN_4042021c(param_1,param_2);
  return;
}



/* 40416360 FUN_40416360 */

/* Boundary evidence: original MIPS .pdata 40416360..4041638b. Semantic name remains unreviewed. */

void FUN_40416360(LPVOID param_1)

{
  int iVar1;
  
  iVar1 = *(int *)((int)param_1 + 0x20) + -1;
  *(int *)((int)param_1 + 0x20) = iVar1;
  if (iVar1 == 0) {
    FUN_40415578(param_1,1);
  }
  return;
}



/* 4041638c FUN_4041638c */

/* Boundary evidence: original MIPS .pdata 4041638c..404163db. Semantic name remains unreviewed. */

void FUN_4041638c(int param_1)

{
  *(undefined4 *)(param_1 + 0x48) = 0;
  *(undefined4 *)(param_1 + 0x3c) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x44) = 0;
  *(undefined4 *)(param_1 + 0x4c) = 0xfffffffe;
  FUN_404156f0(param_1);
  *(undefined4 *)(param_1 + 0x28) = 0;
  *(undefined4 *)(param_1 + 0x40) = 0;
  return;
}



/* 404163dc FUN_404163dc */

/* Boundary evidence: original MIPS .pdata 404163dc..4041642f. Semantic name remains unreviewed. */

void FUN_404163dc(int param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  
  if (param_2 == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = param_2 - DAT_404304bc;
  }
  *(int *)(param_1 + 0x28) = iVar1;
  *(undefined4 *)(param_1 + 0x48) = param_3;
  *(undefined4 *)(param_1 + 0x44) = 0;
  if (*(int *)(param_1 + 0x2c) != 0) {
    *(undefined4 *)(param_1 + 0x3c) = 0xffffffff;
    FUN_404156f0(param_1);
  }
  return;
}



/* 40416430 FUN_40416430 */

/* Boundary evidence: original MIPS .pdata 40416430..40416467. Semantic name remains unreviewed. */

void FUN_40416430(int param_1,int param_2)

{
  int iVar1;
  
  if (param_2 == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = param_2 - DAT_404304bc;
  }
  *(int *)(param_1 + 0x20) = iVar1;
  FUN_4042021c(param_1,param_2);
  return;
}



/* 40416468 FUN_40416468 */

/* Boundary evidence: original MIPS .pdata 40416468..40416483. Semantic name remains unreviewed. */

void FUN_40416468(int param_1)

{
  FUN_40415638(param_1);
  return;
}



/* 40416484 FUN_40416484 */

/* Boundary evidence: original MIPS .pdata 40416484..404164bb. Semantic name remains unreviewed. */

void FUN_40416484(int param_1,int param_2)

{
  int iVar1;
  
  if (param_2 == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = param_2 - DAT_404304bc;
  }
  *(int *)(param_1 + 0x20) = iVar1;
  FUN_4042021c(param_1,param_2);
  return;
}



/* 404164bc FUN_404164bc */

/* Boundary evidence: original MIPS .pdata 404164bc..404164d7. Semantic name remains unreviewed. */

void FUN_404164bc(int param_1)

{
  FUN_404159d0(param_1);
  return;
}



/* 404164d8 FUN_404164d8 */

/* Boundary evidence: original MIPS .pdata 404164d8..40416687. Semantic name remains unreviewed. */

int * FUN_404164d8(int *param_1,int *param_2)

{
  void *_Src;
  int iVar1;
  int iVar2;
  
  *param_1 = *param_2 + DAT_404304bc;
  memcpy(param_1 + 1,param_2 + 1,0x204);
  param_1[0x82] = param_2[0x82] + DAT_404304bc;
  _Src = (void *)FUN_404156e8((int)param_2);
  memcpy(param_1 + 0x83,_Src,0x30);
  iVar1 = FUN_404156d8((int)param_2);
  FUN_404217e0(param_1 + 0x8f,iVar1);
  FUN_404156e0((int)param_2);
  FUN_4042559c(param_1 + 0xa3);
  iVar1 = FUN_4040fae4((int)param_2);
  FUN_404217e0(param_1 + 199,iVar1);
  FUN_404270a4((int)(param_1 + 0xdb));
  FUN_404270a4((int)(param_1 + 0xfb));
  iVar1 = DAT_404304bc;
  iVar2 = param_2[0x11b];
  param_1[0x11c] = 0;
  param_1[0x11b] = iVar2 + iVar1;
  param_1[0x11e] = param_2[0x11e];
  param_1[0x122] = param_2[0x122];
  param_1[0x123] = param_2[0x123];
  param_1[0x124] = param_2[0x124];
  param_1[0x125] = param_2[0x125];
  param_1[0x126] = 1;
  *(short *)(param_1 + 0x129) = (short)param_2[0x129];
  *(undefined2 *)((int)param_1 + 0x4a6) = *(undefined2 *)((int)param_2 + 0x4a6);
  *(short *)(param_1 + 0x12a) = (short)param_2[0x12a];
  param_1[299] = param_2[299];
  param_1[0x11d] = param_2[0x11d];
  FUN_40416328((int)(param_1 + 0x83),(int)param_1);
  FUN_40416430((int)(param_1 + 0x8f),(int)param_1);
  FUN_40416430((int)(param_1 + 199),(int)param_1);
  FUN_40416484((int)(param_1 + 0xa3),(int)param_1);
  param_1[0x128] = 0;
  FUN_40415568(param_1[0x82] + DAT_404304bc);
  return param_1;
}



/* 40416688 FUN_40416688 */

/* Boundary evidence: original MIPS .pdata 40416688..404167c3. Semantic name remains unreviewed. */

int FUN_40416688(int *param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  
  FUN_4040d71c((int)param_1);
  piVar1 = (int *)FUN_4040a638(0x24);
  if (piVar1 == (int *)0x0) {
    piVar1 = (int *)0x0;
  }
  else {
    if (param_1[0x11e] == 0) {
      iVar3 = 0x18;
      iVar2 = 6;
    }
    else {
      iVar3 = 3;
      iVar2 = 2;
    }
    piVar1 = FUN_40420634(piVar1,(int)param_1,iVar2,iVar3);
  }
  if (piVar1 == (int *)0x0) {
LAB_40416768:
    iVar2 = -0x7ffcfff8;
  }
  else {
    param_1[0x82] = (int)piVar1 - DAT_404304bc;
    iVar2 = FUN_40420814(piVar1);
    if (iVar2 < 0) {
      return iVar2;
    }
    if (param_1[0x11e] == 0) {
      FUN_4040d71c((int)param_1);
      piVar1 = (int *)FUN_4040a638(0x4b0);
      if (piVar1 == (int *)0x0) {
        piVar1 = (int *)0x0;
      }
      else {
        piVar1 = FUN_404164d8(piVar1,param_1);
      }
      if (piVar1 == (int *)0x0) goto LAB_40416768;
      param_1[0x11c] = (int)piVar1 - DAT_404304bc;
    }
    FUN_40427bfc((int)(param_1 + 0xdb),(int)param_1,0xfffffffd,0);
    FUN_40427bfc((int)(param_1 + 0xfb),(int)param_1,0xfffffffc,0);
  }
  return iVar2;
}



/* 404167c4 FUN_404167c4 */

/* Boundary evidence: original MIPS .pdata 404167c4..404168e3. Semantic name remains unreviewed. */

void FUN_404167c4(int param_1,int param_2)

{
  int iVar1;
  void *_Src;
  
  FUN_40427bfc(param_1 + 0x36c,param_1,0xfffffffd,0);
  FUN_40427bfc(param_1 + 0x3ec,param_1,0xfffffffc,0);
  iVar1 = FUN_404156d8(param_2);
  FUN_4042185c((int *)(param_1 + 0x23c),iVar1);
  iVar1 = FUN_4040fae4(param_2);
  FUN_4042185c((int *)(param_1 + 0x31c),iVar1);
  iVar1 = FUN_404156e0(param_2);
  FUN_40415654((int *)(param_1 + 0x28c),iVar1);
  iVar1 = FUN_404156e8(param_2);
  FUN_4041ea18((int *)(param_1 + 0x20c),iVar1);
  FUN_40416328(param_1 + 0x20c,param_1);
  FUN_40416430(param_1 + 0x23c,param_1);
  FUN_40416430(param_1 + 0x31c,param_1);
  FUN_40416484(param_1 + 0x28c,param_1);
  _Src = (void *)FUN_404156d0(param_2);
  memcpy((void *)(param_1 + 4),_Src,0x204);
  return;
}



/* 404168e4 FUN_404168e4 */

/* Boundary evidence: original MIPS .pdata 404168e4..404169e7. Semantic name remains unreviewed. */

void FUN_404168e4(int param_1)

{
  int iVar1;
  LPVOID pvVar2;
  
  if (*(int *)(param_1 + 0x470) != 0) {
    FUN_4041575c((LPVOID)(*(int *)(param_1 + 0x470) + DAT_404304bc),0);
    iVar1 = *(int *)(param_1 + 0x470);
    pvVar2 = (LPVOID)(iVar1 + DAT_404304bc);
    if (iVar1 == 0) {
      pvVar2 = (LPVOID)0x0;
    }
    FUN_4040a688(iVar1 + DAT_404304bc,pvVar2);
  }
  if (*(int *)(param_1 + 0x474) == 0) {
    pvVar2 = (LPVOID)0x0;
  }
  else {
    pvVar2 = (LPVOID)(*(int *)(param_1 + 0x474) + DAT_404304bc);
  }
  FUN_40415170(&PTR_PTR_40430324,pvVar2);
  if ((*(int *)(param_1 + 0x498) == 0) && (*(int *)(param_1 + 0x46c) != 0)) {
    (**(code **)(*(int *)(*(int *)(param_1 + 0x46c) + DAT_404304bc) + 4))();
  }
  if (*(int *)(param_1 + 0x208) != 0) {
    FUN_40416360((LPVOID)(*(int *)(param_1 + 0x208) + DAT_404304bc));
  }
  FUN_404182f0();
  FUN_404182f0();
  FUN_40421984(param_1 + 0x31c);
  FUN_40416468(param_1 + 0x28c);
  FUN_40421984(param_1 + 0x23c);
  FUN_404164bc(param_1 + 0x20c);
  return;
}



/* 404169e8 FUN_404169e8 */

/* Boundary evidence: original MIPS .pdata 404169e8..40416c73. Semantic name remains unreviewed. */

int FUN_404169e8(int *param_1)

{
  ushort uVar1;
  undefined2 uVar2;
  uint uVar3;
  undefined4 *puVar4;
  short sVar5;
  int iVar6;
  int iVar7;
  int *piVar8;
  int *piVar9;
  int local_30;
  uint local_2c;
  undefined4 local_28 [2];
  
  piVar8 = *(int **)(*param_1 + DAT_404304bc);
  piVar9 = param_1 + 1;
  iVar7 = *piVar8;
  FUN_4040d1f4(piVar9);
  iVar7 = (**(code **)(iVar7 + 0xc))(piVar8);
  if (-1 < iVar7) {
    FUN_40415560((int)piVar9);
    uVar1 = FUN_404155d8((int)piVar9);
    sVar5 = (short)(1 << (uVar1 & 0x1f));
    *(short *)(param_1 + 0x129) = sVar5;
    *(short *)(param_1 + 0x12a) = sVar5 + -1;
    *(ushort *)((int)param_1 + 0x4a6) = uVar1;
    if (local_30 == 0x200) {
      iVar7 = FUN_4040c940(piVar9);
      if ((-1 < iVar7) && (iVar7 = FUN_40416688(param_1), -1 < iVar7)) {
        uVar3 = FUN_4040c920((int)piVar9);
        iVar7 = FUN_40425800(param_1 + 0xa3,(int)param_1,uVar3);
        if (-1 < iVar7) {
          uVar3 = FUN_4040c910((int)piVar9);
          iVar7 = FUN_40421a1c(param_1 + 0x8f,(int)param_1,uVar3);
          if (-1 < iVar7) {
            uVar3 = FUN_404055e4((int)piVar9);
            iVar7 = FUN_404220e8(param_1 + 0x8f,uVar3,&local_2c);
            if (-1 < iVar7) {
              iVar7 = FUN_4041ea90(param_1 + 0x83,(int)param_1,local_2c);
              if (-1 < iVar7) {
                uVar3 = FUN_4040c918((int)piVar9);
                iVar7 = FUN_40421a1c(param_1 + 199,(int)param_1,uVar3);
                if (-1 < iVar7) {
                  piVar8 = (int *)FUN_4040d71c((int)param_1);
                  iVar7 = *piVar8;
                  uVar2 = FUN_4040d6bc((int)param_1);
                  iVar7 = (**(code **)(iVar7 + 0xc))(piVar8,uVar2);
                  if (iVar7 != 0) {
                    param_1[0x11d] = iVar7 - DAT_404304bc;
                    iVar7 = FUN_4041537c(param_1 + 0x83,0,local_28);
                    if (iVar7 < 0) {
                      return iVar7;
                    }
                    FUN_4040d71c((int)param_1);
                    puVar4 = (undefined4 *)FUN_404157a8(0xa0);
                    if (puVar4 == (undefined4 *)0x0) {
                      puVar4 = (undefined4 *)0x0;
                    }
                    else {
                      puVar4 = FUN_4042917c(puVar4,2);
                    }
                    if (puVar4 != (undefined4 *)0x0) {
                      iVar6 = (int)puVar4 - DAT_404304bc;
                      param_1[0x11b] = iVar6;
                      FUN_40427e88((undefined4 *)(iVar6 + DAT_404304bc),(int)param_1,0,local_28[0]);
                      return iVar7;
                    }
                  }
                  iVar7 = -0x7ffcfff8;
                }
              }
            }
          }
        }
      }
    }
    else {
      iVar7 = -0x7ffcff05;
    }
  }
  return iVar7;
}



/* 40416c74 FUN_40416c74 */

/* Boundary evidence: original MIPS .pdata 40416c74..404171fb. Semantic name remains unreviewed. */

uint FUN_40416c74(int *param_1,uint param_2,int param_3,uint param_4,void *param_5,int param_6,
                 int param_7,int *param_8)

{
  undefined2 uVar1;
  undefined2 extraout_var;
  uint uVar2;
  int *piVar3;
  uint uVar4;
  ushort uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  int iVar11;
  uint uVar12;
  ushort local_1f8;
  uint local_1f4;
  ushort local_1f0;
  void *local_1ec;
  uint local_1e8;
  int *local_1e4;
  uint local_1e0;
  ushort local_1dc;
  uint local_1d8;
  uint local_1d4;
  uint local_1d0;
  int local_1cc;
  uint local_1c8;
  uint local_1c4;
  uint local_1c0 [2];
  uint uStack_1b8;
  uint local_1b4 [99];
  
  local_1ec = param_5;
  uVar1 = FUN_4040d6bc((int)param_1);
  iVar11 = CONCAT22(extraout_var,uVar1);
  local_1e4 = param_1 + 0x8f;
  local_1f0 = FUN_404156c8((int)param_1);
  uVar7 = (uint)local_1f0;
  local_1e0 = 0;
  local_1d4 = 0;
  local_1e8 = 0;
  if (((param_3 != 0) && (param_1[0x11e] == 0)) && (param_2 != 0)) {
    uVar7 = 6;
    local_1f0 = 6;
    iVar11 = 0x40;
    local_1e4 = (int *)FUN_4040fae4((int)param_1);
  }
  local_1dc = (short)iVar11 - 1;
  local_1f4 = param_4 + param_6;
  uVar8 = param_4 >> (uVar7 & 0x1f);
  uVar9 = local_1f4 - 1 >> (uVar7 & 0x1f);
  local_1f8 = (short)local_1f4 - 1U & local_1dc;
  uVar7 = (uint)(short)(local_1dc & (ushort)param_4);
  uVar12 = 0;
  uVar2 = FUN_4041537c(param_1 + 0x83,param_2,&local_1e8);
  if ((int)uVar2 < 0) {
    return uVar2;
  }
  if ((param_1[0x124] != 0) && (piVar3 = (int *)FUN_4040fae4((int)param_1), piVar3 != local_1e4)) {
    if (uVar8 == 0) {
      uVar2 = FUN_40415300(param_1 + 0x83,param_2,&local_1d8);
    }
    else {
      uVar2 = FUN_404273b4(param_7,uVar8 - 1,(int *)&local_1d8);
    }
    if ((int)uVar2 < 0) {
      return uVar2;
    }
    uVar4 = FUN_40423fe0(param_1 + 0x8f,local_1d8,(uint)(uVar8 != 0),(uVar9 - uVar8) + 1,&local_1c8,
                         &local_1d0,&local_1c4,local_1c0);
    if ((int)uVar4 < 0) {
      return uVar4;
    }
    uVar2 = 1;
    if ((uVar4 != 1) && (uVar2 = FUN_404276f8(param_7,uVar8,uVar9), (int)uVar2 < 0)) {
      return uVar2;
    }
    if (((uVar8 == 0) && (local_1d0 != 0xfffffffe)) &&
       (uVar2 = FUN_4041f3b4(param_1 + 0x83,param_2,local_1d0), (int)uVar2 < 0)) {
      return uVar2;
    }
    uVar4 = local_1e8;
    if (((uVar7 != 0) ||
        (((uVar9 == uVar8 && (local_1f4 != local_1e8)) && ((uint)local_1f8 != iVar11 - 1U)))) &&
       (local_1d0 != 0xfffffffe)) {
      uVar5 = local_1f8;
      if (uVar9 != uVar8) {
        uVar5 = (short)iVar11 - 1;
      }
      uVar2 = FUN_40415c3c(param_1,local_1c8,local_1d0,uVar7,uVar5,param_5,&local_1e8);
      if ((int)uVar2 < 0) {
        return uVar2;
      }
      param_5 = (void *)(local_1e8 + (int)param_5);
      uVar8 = uVar8 + 1;
      uVar7 = 0;
      uVar12 = local_1e8;
      local_1ec = param_5;
    }
    if (uVar9 < uVar8) goto LAB_40416f70;
    if ((((uint)local_1f8 != iVar11 - 1U) && (local_1f4 != uVar4)) && (local_1c0[0] != 0xfffffffe))
    {
      uVar2 = FUN_40415c3c(param_1,local_1c4,local_1c0[0],0,local_1f8,
                           (void *)(((uVar9 - uVar8 << (local_1f0 & 0x1f)) - uVar7) + (int)param_5),
                           &local_1d4);
      if ((int)uVar2 < 0) {
        return uVar2;
      }
      local_1f8 = (ushort)(iVar11 - 1U);
      uVar9 = uVar9 - 1;
      local_1e0 = local_1d4;
    }
  }
  if (uVar8 <= uVar9) {
    uVar2 = (uVar9 - uVar8) + 1;
    uVar7 = uVar7 & 0xffff;
    uVar9 = FUN_4042783c(param_7,uVar8,1,&uStack_1b8,uVar2,(int *)&local_1f4);
    do {
      if ((int)uVar9 < 0) {
        return uVar9;
      }
      uVar4 = (uint)local_1dc;
      uVar10 = 0;
      if (local_1f4 != 0) {
        piVar3 = (int *)FUN_4040fae4((int)param_1);
        do {
          iVar11 = uVar10 * 3;
          uVar9 = local_1b4[uVar10 * 3 + 1];
          if (uVar2 < local_1b4[uVar10 * 3 + 1]) {
            uVar9 = uVar2;
          }
          uVar2 = uVar2 - uVar9;
          uVar8 = uVar9 + uVar8;
          uVar10 = uVar10 + 1 & 0xffff;
          if (uVar2 == 0) {
            uVar4 = (uint)local_1f8;
          }
          uVar6 = (uint)local_1f0;
          if (piVar3 == local_1e4) {
            uVar9 = FUN_4042833c((int *)(param_1[0x11b] + DAT_404304bc),
                                 (local_1b4[iVar11] << (uVar6 & 0x1f)) + uVar7,local_1ec,
                                 ((uVar9 - 1 << (uVar6 & 0x1f)) - uVar7) + uVar4 + 1,&local_1cc);
          }
          else {
            FUN_404157c4(local_1b4[iVar11],(int)(short)uVar7,uVar6);
            uVar9 = (**(code **)(**(int **)(*param_1 + DAT_404304bc) + 0x10))();
          }
          uVar12 = local_1cc + uVar12;
          if (uVar2 == 0) goto LAB_404171b8;
          if ((int)uVar9 < 0) break;
          local_1ec = (void *)(local_1cc + (int)local_1ec);
          uVar7 = 0;
        } while (uVar10 < local_1f4);
      }
      if ((uVar2 == 0) || ((int)uVar9 < 0)) {
LAB_404171b8:
        *param_8 = uVar12 + local_1e0;
        return uVar9;
      }
      uVar9 = FUN_4042783c(param_7,uVar8,1,&uStack_1b8,uVar2,(int *)&local_1f4);
    } while( true );
  }
LAB_40416f70:
  *param_8 = uVar12 + local_1e0;
  return uVar2;
}



/* 404171fc FUN_404171fc */

/* Boundary evidence: original MIPS .pdata 404171fc..40417297. Semantic name remains unreviewed. */

int FUN_404171fc(int *param_1,int param_2)

{
  int iVar1;
  
  iVar1 = 0;
  if ((((param_1[0x11e] == 0) && (*(int *)(*param_1 + DAT_404304bc) != 0)) &&
      (iVar1 = FUN_4042099c((int *)(param_1[0x82] + DAT_404304bc)), -1 < iVar1)) &&
     (iVar1 = FUN_40415b50(param_1,0), -1 < iVar1)) {
    iVar1 = FUN_40415db0(*(int **)(*param_1 + DAT_404304bc),param_2);
  }
  return iVar1;
}



/* 40417298 FUN_40417298 */

/* Boundary evidence: original MIPS .pdata 40417298..404173ab. Semantic name remains unreviewed. */

int * FUN_40417298(int *param_1,int param_2,int param_3,int param_4,uint param_5,ushort param_6)

{
  short sVar1;
  int iVar2;
  
  iVar2 = param_3 - DAT_404304bc;
  if (param_3 == 0) {
    iVar2 = 0;
  }
  *param_1 = iVar2 + DAT_404304bc;
  FUN_4040c8d4(param_1 + 1,(uint)param_6);
  FUN_4041ed60(param_1 + 0x83);
  FUN_40421778(param_1 + 0x8f,0xfffffffe);
  FUN_404255d8(param_1 + 0xa3);
  FUN_40421778(param_1 + 199,0xfffffffc);
  FUN_404270a4((int)(param_1 + 0xdb));
  FUN_404270a4((int)(param_1 + 0xfb));
  param_1[0x11f] = param_5 & 0x4000;
  sVar1 = (short)(1 << (param_6 & 0x1f));
  param_1[0x11e] = param_4;
  *(ushort *)((int)param_1 + 0x4a6) = param_6;
  param_1[299] = param_2;
  param_1[0x120] = 0;
  param_1[0x121] = param_5 & 0x40000;
  *(short *)(param_1 + 0x129) = sVar1;
  *(short *)(param_1 + 0x12a) = sVar1 + -1;
  param_1[0x11c] = 0;
  param_1[0x11d] = 0;
  param_1[0x126] = 0;
  param_1[0x128] = 0;
  param_1[0x11b] = 0;
  param_1[0x82] = 0;
  param_1[0x125] = 0;
  param_1[0x124] = 0;
  param_1[0x123] = 0;
  param_1[0x122] = 0;
  param_1[0x127] = 0;
  return param_1;
}



/* 404173ac FUN_404173ac */

/* Boundary evidence: original MIPS .pdata 404173ac..40417603. Semantic name remains unreviewed. */

int FUN_404173ac(int *param_1,int param_2,int param_3)

{
  undefined2 uVar1;
  int iVar2;
  int *piVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined4 local_28 [2];
  
  iVar2 = FUN_40416688(param_1);
  if (iVar2 < 0) goto LAB_4041756c;
  iVar5 = 0;
  if (param_1[0x11e] == 0) {
    if ((param_2 == 0) && (param_3 != 0)) {
      (**(code **)(**(int **)(*param_1 + DAT_404304bc) + 0x18))();
    }
    iVar2 = param_2;
    iVar5 = param_3;
    if (param_3 == 0) goto LAB_40417440;
  }
  else {
LAB_40417440:
    iVar2 = 0;
  }
  param_1[0x122] = iVar2;
  iVar2 = FUN_40425898(param_1 + 0xa3,(int)param_1);
  if (((iVar2 < 0) || (iVar2 = FUN_404229e8(param_1 + 0x8f,param_1), iVar2 < 0)) ||
     (((param_1[0x11e] == 0 || (param_1[0x11f] != 0)) &&
      (iVar2 = FUN_404229e8(param_1 + 199,param_1), iVar2 < 0)))) goto LAB_4041756c;
  if (param_1[0x11e] == 0) {
    iVar2 = FUN_4041f740(param_1 + 0x83,(int)param_1);
    if (iVar2 < 0) goto LAB_4041756c;
    piVar3 = (int *)FUN_4040d71c((int)param_1);
    iVar2 = *piVar3;
    uVar1 = FUN_4040d6bc((int)param_1);
    iVar2 = (**(code **)(iVar2 + 0xc))(piVar3,uVar1);
    if (iVar2 != 0) {
      param_1[0x11d] = iVar2 - DAT_404304bc;
      iVar2 = FUN_4041537c(param_1 + 0x83,0,local_28);
      if (iVar2 < 0) goto LAB_4041756c;
      FUN_4040d71c((int)param_1);
      puVar4 = (undefined4 *)FUN_404157a8(0xa0);
      if (puVar4 == (undefined4 *)0x0) {
        puVar4 = (undefined4 *)0x0;
      }
      else {
        puVar4 = FUN_4042917c(puVar4,2);
      }
      if (puVar4 != (undefined4 *)0x0) {
        iVar2 = (int)puVar4 - DAT_404304bc;
        param_1[0x11b] = iVar2;
        FUN_40427e88((undefined4 *)(iVar2 + DAT_404304bc),(int)param_1,0,local_28[0]);
        goto LAB_404175c4;
      }
    }
    iVar2 = -0x7ffcfff8;
  }
  else {
LAB_404175c4:
    if ((param_1[0x122] != 0) || (iVar2 = FUN_404171fc(param_1,0), -1 < iVar2)) {
      param_1[0x123] = (uint)(iVar5 != 0);
      param_1[0x122] = param_2;
      return 0;
    }
  }
LAB_4041756c:
  FUN_404159ec((int)param_1);
  return iVar2;
}



/* 40417604 FUN_40417604 */

/* Boundary evidence: original MIPS .pdata 40417604..40417943. Semantic name remains unreviewed. */

int FUN_40417604(int *param_1,int param_2)

{
  bool bVar1;
  uint uVar2;
  undefined2 uVar3;
  ushort uVar4;
  int iVar5;
  undefined2 extraout_var;
  int *piVar6;
  undefined4 *puVar7;
  uint uVar8;
  uint uVar9;
  uint local_b8;
  uint local_b4;
  undefined1 auStack_b0 [8];
  uint local_a8;
  undefined1 auStack_68 [68];
  uint local_24;
  
  local_24 = DAT_404303e4;
  FUN_40410f4c(auStack_68,L"CONTENTS");
  param_1[0x122] = param_2;
  iVar5 = FUN_40416688(param_1);
  if (iVar5 < 0) goto LAB_40417898;
  (**(code **)(**(int **)(DAT_404304bc + *param_1) + 0x24))
            (*(int **)(DAT_404304bc + *param_1),auStack_b0,1);
  uVar3 = FUN_4040d6bc((int)param_1);
  uVar2 = local_a8;
  iVar5 = CONCAT22(extraout_var,uVar3) + local_a8;
  uVar4 = FUN_404156c8((int)param_1);
  uVar8 = iVar5 - 1U >> (uVar4 & 0x1f);
  bVar1 = uVar2 < 0x1000;
  uVar9 = local_b4;
  if (bVar1) {
    uVar9 = uVar2 + 0x3f >> 6;
  }
  piVar6 = (int *)FUN_4040d71c((int)param_1);
  iVar5 = *piVar6;
  uVar3 = FUN_4040d6bc((int)param_1);
  iVar5 = (**(code **)(iVar5 + 0xc))(piVar6,uVar3);
  if (iVar5 != 0) {
    param_1[0x11d] = iVar5 - DAT_404304bc;
    iVar5 = FUN_40425920(param_1 + 0xa3,(int)param_1,uVar8);
    if ((iVar5 < 0) || (iVar5 = FUN_4042435c(param_1 + 0x8f,param_1,uVar8), iVar5 < 0))
    goto LAB_40417898;
    piVar6 = param_1 + 0x83;
    iVar5 = FUN_4041f740(piVar6,(int)param_1);
    if (iVar5 < 0) goto LAB_40417898;
    if (bVar1) {
      iVar5 = FUN_4042435c(param_1 + 199,param_1,uVar9);
    }
    else {
      iVar5 = FUN_404229e8(param_1 + 199,param_1);
    }
    if (((iVar5 < 0) ||
        (iVar5 = FUN_40415534((int)param_1,0,(int)auStack_68,2,&local_b8), iVar5 < 0)) ||
       (iVar5 = FUN_4041f430(piVar6,local_b8,local_a8), iVar5 < 0)) goto LAB_40417898;
    if (bVar1) {
      iVar5 = FUN_4041f3b4(piVar6,local_b8,0);
      if ((iVar5 < 0) || (iVar5 = FUN_4041f3b4(piVar6,0,uVar8 - 1), iVar5 < 0)) goto LAB_40417898;
      iVar5 = FUN_4041f430(piVar6,0,local_a8);
    }
    else {
      iVar5 = FUN_4041f3b4(piVar6,local_b8,uVar8 - 1);
    }
    if ((iVar5 < 0) || (iVar5 = FUN_4041537c(piVar6,0,&local_b4), iVar5 < 0)) goto LAB_40417898;
    FUN_4040d71c((int)param_1);
    puVar7 = (undefined4 *)FUN_404157a8(0xa0);
    if (puVar7 == (undefined4 *)0x0) {
      puVar7 = (undefined4 *)0x0;
    }
    else {
      puVar7 = FUN_4042917c(puVar7,2);
    }
    if (puVar7 != (undefined4 *)0x0) {
      iVar5 = (int)puVar7 - DAT_404304bc;
      param_1[0x11b] = iVar5;
      FUN_40427e88((undefined4 *)(iVar5 + DAT_404304bc),(int)param_1,0,local_b4);
      if ((param_1[0x122] != 0) ||
         ((iVar5 = FUN_40415a2c(param_1), -1 < iVar5 &&
          (iVar5 = FUN_404171fc(param_1,0), -1 < iVar5)))) {
        FUN_4042f4c4(local_24);
        return 0;
      }
      goto LAB_40417898;
    }
  }
  iVar5 = -0x7ffcfff8;
LAB_40417898:
  FUN_404159ec((int)param_1);
  FUN_4042f4c4(local_24);
  return iVar5;
}



/* 40417944 FUN_40417944 */

/* Boundary evidence: original MIPS .pdata 40417944..40417bbb. Semantic name remains unreviewed. */

int FUN_40417944(int *param_1,uint param_2)

{
  undefined2 uVar1;
  undefined2 uVar2;
  int iVar3;
  undefined2 extraout_var;
  undefined2 extraout_var_00;
  int *piVar4;
  uint local_70 [2];
  undefined1 auStack_68 [8];
  int local_60;
  uint local_20;
  
  local_20 = DAT_404303e4;
  if (param_1[0x122] != 0) {
    if ((((param_1[0x123] != 0) && ((param_2 & 1) == 0)) && (param_1[0x120] == 0)) &&
       (iVar3 = (**(code **)(**(int **)(*param_1 + DAT_404304bc) + 0x18))
                          (*(int **)(*param_1 + DAT_404304bc),param_2,0,0), iVar3 < 0))
    goto LAB_40417b7c;
    if ((param_2 & 1) == 0) {
      param_1[0x124] = 1;
    }
    param_1[0x122] = 0;
    iVar3 = FUN_404171fc(param_1,0);
    if (iVar3 < 0) goto LAB_40417b7c;
    param_1[0x124] = 0;
    param_1[0x123] = 0;
  }
  iVar3 = (**(code **)(**(int **)(*param_1 + DAT_404304bc) + 0x24))
                    (*(int **)(*param_1 + DAT_404304bc),auStack_68,1);
  if (-1 < iVar3) {
    param_1[0x128] = local_60;
    if (param_1[0x121] != 0) {
      uVar1 = FUN_4040d6bc((int)param_1);
      uVar2 = FUN_4040d6bc((int)param_1);
      if (CONCAT22(extraout_var_00,uVar2) == 0) {
        trap(0x1c00);
      }
      FUN_40415624((int)(param_1 + 0x8f),
                   ((CONCAT22(extraout_var,uVar1) + local_60) - 0x201U) /
                   CONCAT22(extraout_var_00,uVar2));
    }
    iVar3 = FUN_404171fc(param_1,0);
    if (-1 < iVar3) {
      if ((param_2 & 1) == 0) {
        piVar4 = param_1 + 0x8f;
        if (param_1[0x120] == 0) {
          iVar3 = FUN_40421ea8(piVar4,local_70);
        }
        else {
          iVar3 = FUN_40421d1c(piVar4,(int *)local_70);
        }
        if (iVar3 < 0) goto LAB_40417b7c;
        FUN_404167c4(param_1[0x11c] + DAT_404304bc,(int)param_1);
        *(undefined4 *)(param_1[0x11c] + DAT_404304bc + 0x46c) = 0;
        iVar3 = FUN_404156d8(param_1[0x11c] + DAT_404304bc);
        FUN_404163dc((int)piVar4,iVar3,local_70[0]);
        param_1[0x124] = 1;
        FUN_40425b04(param_1 + 0xa3);
        if (param_1[0x11c] == 0) {
          iVar3 = 0;
        }
        else {
          iVar3 = param_1[0x11c] + DAT_404304bc;
        }
        FUN_404261cc(param_1 + 0xa3,iVar3);
      }
      else {
        FUN_404163dc((int)(param_1 + 0x8f),0,0);
      }
      FUN_4042f4c4(local_20);
      return 0;
    }
  }
LAB_40417b7c:
  param_1[0x124] = 0;
  FUN_404159ec(param_1[0x11c] + DAT_404304bc);
  FUN_4042f4c4(local_20);
  return iVar3;
}



/* 40417bbc FUN_40417bbc */

/* Boundary evidence: original MIPS .pdata 40417bbc..40417de7. Semantic name remains unreviewed. */

int FUN_40417bbc(int *param_1,uint param_2,uint param_3)

{
  undefined2 uVar1;
  undefined2 extraout_var;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint local_20 [2];
  
  iVar3 = 0;
  uVar4 = (uint)((param_2 & 4) == 0);
  if ((param_2 & 1) == 0) {
    if ((param_3 & 8) == 0) {
      FUN_404159ec((int)param_1);
      if (param_1[0x11c] == 0) {
        iVar2 = 0;
      }
      else {
        iVar2 = param_1[0x11c] + DAT_404304bc;
      }
      FUN_404167c4((int)param_1,iVar2);
      uVar5 = param_1[0x128];
    }
    else {
      if (param_1[0x11c] == 0) {
        iVar3 = 0;
      }
      else {
        iVar3 = param_1[0x11c] + DAT_404304bc;
      }
      iVar3 = FUN_404261cc(param_1 + 0xa3,iVar3);
      if (iVar3 < 0) {
        return iVar3;
      }
      iVar3 = FUN_404171fc(param_1,uVar4);
      if (iVar3 < 0) {
        return iVar3;
      }
      FUN_4041638c((int)(param_1 + 0x8f));
      iVar3 = FUN_404155e0(param_1 + 0x8f,local_20);
      if (iVar3 < 0) {
        return iVar3;
      }
      uVar1 = FUN_404156c8((int)param_1);
      uVar5 = FUN_404157c4(local_20[0],0,CONCAT22(extraout_var,uVar1));
      iVar3 = FUN_40415b50(param_1,1);
      if (iVar3 < 0) {
        return iVar3;
      }
      FUN_40415db0(*(int **)(*param_1 + DAT_404304bc),uVar4);
    }
    if (uVar5 < (uint)param_1[0x128]) {
      (**(code **)(**(int **)(*param_1 + DAT_404304bc) + 0x18))();
    }
    FUN_404159ec(param_1[0x11c] + DAT_404304bc);
    param_1[0x124] = 0;
    param_1[0x125] = 0;
  }
  else {
    if (param_1[0x120] != 0) {
      iVar3 = FUN_404261cc(param_1 + 0xa3,0);
      if (iVar3 < 0) {
        return iVar3;
      }
      FUN_4041638c((int)(param_1 + 0x8f));
    }
    iVar3 = FUN_404171fc(param_1,uVar4);
    if (iVar3 < 0) {
      return iVar3;
    }
  }
  if (param_1[0x120] != 0) {
    FUN_404162e4(param_1[0x120] + DAT_404304bc,(int)param_1,0);
  }
  FUN_40415624((int)(param_1 + 0x8f),0);
  param_1[0x128] = 0;
  FUN_404157d4(param_1);
  return iVar3;
}



/* 40417de8 FUN_40417de8 */

/* Boundary evidence: original MIPS .pdata 40417de8..40417ee7. Semantic name remains unreviewed. */

undefined4 FUN_40417de8(int *param_1,undefined4 param_2,uint param_3,SIZE_T param_4)

{
  int *piVar1;
  uint uVar2;
  int iVar3;
  
  uVar2 = 0;
  if (param_3 != 0) {
    do {
      piVar1 = (int *)FUN_4040a638(param_4);
      if (piVar1 == (int *)0x0) {
        for (; uVar2 != 0; uVar2 = uVar2 - 1) {
          piVar1 = (int *)(*param_1 + DAT_404304bc);
          iVar3 = *piVar1 + DAT_404304bc;
          if (*piVar1 == 0) {
            iVar3 = 0;
          }
          if (*param_1 == 0) {
            piVar1 = (int *)0x0;
          }
          FUN_4040a65c(piVar1);
          if (iVar3 == 0) {
            iVar3 = 0;
          }
          else {
            iVar3 = iVar3 - DAT_404304bc;
          }
          *param_1 = iVar3;
        }
        return 0x80030008;
      }
      uVar2 = uVar2 + 1;
      *piVar1 = *param_1;
      *param_1 = (int)piVar1 - DAT_404304bc;
    } while (uVar2 < param_3);
  }
  return 0;
}



/* 40417ee8 FUN_40417ee8 */

/* Boundary evidence: original MIPS .pdata 40417ee8..40417f7f. Semantic name remains unreviewed. */

void FUN_40417ee8(int *param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  
  for (; param_2 != 0; param_2 = param_2 + -1) {
    piVar1 = (int *)(*param_1 + DAT_404304bc);
    iVar2 = *piVar1 + DAT_404304bc;
    if (*piVar1 == 0) {
      iVar2 = 0;
    }
    if (*param_1 == 0) {
      piVar1 = (int *)0x0;
    }
    FUN_4040a65c(piVar1);
    if (iVar2 == 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = iVar2 - DAT_404304bc;
    }
    *param_1 = iVar2;
  }
  return;
}



/* 40417f80 FUN_40417f80 */

/* Boundary evidence: original MIPS .pdata 40417f80..40417ff7. Semantic name remains unreviewed. */

void FUN_40417f80(int param_1)

{
  LPVOID pvVar1;
  
  if (*(int *)(param_1 + 4) == 0) {
    pvVar1 = (LPVOID)0x0;
  }
  else {
    pvVar1 = (LPVOID)(*(int *)(param_1 + 4) + DAT_404304bc);
  }
  if (pvVar1 != (LPVOID)0x0) {
    FUN_404168e4((int)pvVar1);
    FUN_4040a65c(pvVar1);
  }
  FUN_4040a5cc(param_1 + 0x30,4,4,FUN_404182f0);
  return;
}



/* 40417ff8 FUN_40417ff8 */

/* Boundary evidence: original MIPS .pdata 40417ff8..4041803f. Semantic name remains unreviewed. */

void FUN_40417ff8(LPVOID param_1)

{
  LONG LVar1;
  
  LVar1 = InterlockedDecrement((LONG *)((int)param_1 + 0x18));
  if ((LVar1 == 0) && (param_1 != (LPVOID)0x0)) {
    FUN_40417f80((int)param_1);
    FUN_4040a65c(param_1);
  }
  return;
}



/* 40418040 FUN_40418040 */

void FUN_40418040(int *param_1,int param_2)

{
  *(int *)(param_2 + 0x50) = *param_1;
  *param_1 = param_2 - DAT_404304bc;
  return;
}



/* 4041805c FUN_4041805c */

/* Boundary evidence: original MIPS .pdata 4041805c..404180d7. Semantic name remains unreviewed. */

int FUN_4041805c(int *param_1,ushort *param_2)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *param_1;
  while( true ) {
    if (iVar2 == 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = iVar2 + DAT_404304bc;
    }
    if (iVar2 == 0) break;
    iVar1 = FUN_404197c0((ushort *)(iVar2 + 0xc),param_2);
    if (iVar1 != 0) {
      return iVar2;
    }
    iVar2 = *(int *)(iVar2 + 0x50);
  }
  return 0;
}



/* 404180d8 FUN_404180d8 */

/* Boundary evidence: original MIPS .pdata 404180d8..4041818b. Semantic name remains unreviewed. */

void FUN_404180d8(int *param_1,ushort *param_2)

{
  int iVar1;
  
  iVar1 = *param_1;
  while (iVar1 != 0) {
    if ((param_2 == (ushort *)0x0) ||
       (iVar1 = FUN_404197c0((ushort *)(*param_1 + DAT_404304bc + 0xc),param_2), iVar1 != 0)) {
      (*(code *)**(undefined4 **)(*param_1 + DAT_404304bc))();
      *param_1 = *(int *)(*param_1 + DAT_404304bc + 0x50);
    }
    else {
      param_1 = (int *)(*param_1 + DAT_404304bc + 0x50);
    }
    iVar1 = *param_1;
  }
  return;
}



/* 4041818c FUN_4041818c */

void FUN_4041818c(int *param_1,int param_2)

{
  int iVar1;
  
  iVar1 = *param_1;
  while( true ) {
    if (iVar1 == 0) {
      return;
    }
    if (*param_1 + DAT_404304bc == param_2) break;
    param_1 = (int *)(*param_1 + DAT_404304bc + 0x50);
    iVar1 = *param_1;
  }
  *param_1 = *(int *)(*param_1 + DAT_404304bc + 0x50);
  return;
}



/* 404181e0 FUN_404181e0 */

/* Boundary evidence: original MIPS .pdata 404181e0..404182ef. Semantic name remains unreviewed. */

undefined4 FUN_404181e0(int *param_1,ushort *param_2,uint param_3,uint param_4)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  
  uVar2 = 0x40;
  if ((param_4 & 2) == 0) {
    uVar2 = 0xc0;
  }
  if (((~param_4 & uVar2 & param_3) == 0) && ((~param_3 & param_4 & 0x300) == 0)) {
    iVar3 = *param_1;
    while( true ) {
      if (iVar3 == 0) {
        iVar3 = 0;
      }
      else {
        iVar3 = iVar3 + DAT_404304bc;
      }
      if (iVar3 == 0) {
        return 0;
      }
      iVar1 = FUN_404197c0((ushort *)(iVar3 + 0xc),param_2);
      if ((iVar1 != 0) &&
         (((*(uint *)(iVar3 + 8) >> 2 & param_3 & 0xc0) != 0 ||
          ((param_3 >> 2 & *(uint *)(iVar3 + 8) & 0xc0) != 0)))) break;
      iVar3 = *(int *)(iVar3 + 0x50);
    }
    uVar4 = 0x80030005;
  }
  else {
    uVar4 = 0x800300ff;
  }
  return uVar4;
}



/* 404182f0 FUN_404182f0 */

void FUN_404182f0(void)

{
  return;
}



/* 404182f8 FUN_404182f8 */

/* Boundary evidence: original MIPS .pdata 404182f8..4041839f. Semantic name remains unreviewed. */

int FUN_404182f8(int *param_1,ushort *param_2,int param_3)

{
  int iVar1;
  int iVar2;
  
  if (*param_1 == 0) goto LAB_40418374;
  iVar2 = *param_1 + DAT_404304bc;
  while ((iVar2 != 0 &&
         ((iVar1 = FUN_404197c0((ushort *)(iVar2 + 0x20),param_2), iVar1 == 0 ||
          (*(int *)(iVar2 + 0x14) != param_3))))) {
    if (*(int *)(iVar2 + 8) == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = *(int *)(iVar2 + 8) + DAT_404304bc;
    }
    iVar2 = iVar1 + -4;
    if (iVar1 == 0) {
LAB_40418374:
      iVar2 = 0;
    }
  }
  return iVar2;
}



/* 404183a0 FUN_404183a0 */

void FUN_404183a0(int *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  
  iVar2 = *param_1 + DAT_404304bc;
  if (*param_1 == 0) {
    iVar2 = 0;
  }
  if (iVar2 != 0) {
    iVar1 = 0;
    do {
      iVar3 = iVar2;
      iVar2 = iVar3;
      if (*(uint *)(param_2 + 0x1c) <= *(uint *)(iVar3 + 0x1c)) break;
      iVar1 = *(int *)(iVar3 + 8) + DAT_404304bc;
      if (*(int *)(iVar3 + 8) == 0) {
        iVar1 = 0;
      }
      iVar2 = iVar1 + -4;
      if (iVar1 == 0) {
        iVar2 = 0;
      }
      iVar1 = iVar3;
    } while (iVar2 != 0);
    if (iVar2 != 0) {
      piVar5 = (int *)(iVar2 + 4);
      iVar2 = (int)piVar5 - DAT_404304bc;
      if (piVar5 == (int *)0x0) {
        iVar2 = 0;
      }
      *(int *)(param_2 + 8) = iVar2;
      iVar2 = *piVar5 + DAT_404304bc;
      if (*piVar5 == 0) {
        iVar2 = 0;
      }
      iVar1 = iVar2 + -4;
      if (iVar2 == 0) {
        iVar1 = 0;
      }
      iVar2 = iVar1 + 4;
      if (iVar1 == 0) {
        iVar2 = 0;
      }
      iVar1 = iVar2 - DAT_404304bc;
      if (iVar2 == 0) {
        iVar1 = 0;
      }
      piVar4 = (int *)(param_2 + 4);
      *piVar4 = iVar1;
      if (*piVar5 == 0) {
        iVar2 = 0;
      }
      else {
        iVar2 = *piVar5 + DAT_404304bc;
      }
      iVar1 = iVar2 + -4;
      if (iVar2 == 0) {
        iVar1 = 0;
      }
      if (iVar1 == 0) {
        *param_1 = param_2 - DAT_404304bc;
      }
      else {
        if (*piVar5 == 0) {
          iVar2 = 0;
        }
        else {
          iVar2 = *piVar5 + DAT_404304bc;
        }
        iVar1 = iVar2 + -4;
        if (iVar2 == 0) {
          iVar1 = 0;
        }
        iVar2 = (int)piVar4 - DAT_404304bc;
        if (piVar4 == (int *)0x0) {
          iVar2 = 0;
        }
        *(int *)(iVar1 + 8) = iVar2;
      }
      if (piVar4 == (int *)0x0) {
        iVar2 = 0;
      }
      else {
        iVar2 = (int)piVar4 - DAT_404304bc;
      }
      *piVar5 = iVar2;
      return;
    }
    if (iVar1 != 0) {
      piVar5 = (int *)(param_2 + 4);
      iVar2 = (int)piVar5 - DAT_404304bc;
      if (piVar5 == (int *)0x0) {
        iVar2 = 0;
      }
      *(int *)(iVar1 + 8) = iVar2;
      if (iVar1 + 4 == 0) {
        iVar2 = 0;
      }
      else {
        iVar2 = (iVar1 + 4) - DAT_404304bc;
      }
      *piVar5 = iVar2;
      return;
    }
  }
  iVar2 = param_2 - DAT_404304bc;
  if (param_2 == 0) {
    iVar2 = 0;
  }
  *param_1 = iVar2;
  return;
}



/* 40418538 FUN_40418538 */

void FUN_40418538(int *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  if (*(int *)(param_2 + 8) == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = *(int *)(param_2 + 8) + DAT_404304bc;
  }
  if (iVar1 == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = iVar1 + -4;
  }
  if (*(int *)(param_2 + 4) == 0) {
    iVar2 = 0;
  }
  else {
    iVar2 = *(int *)(param_2 + 4) + DAT_404304bc;
  }
  iVar3 = iVar2 + -4;
  if (iVar2 == 0) {
    iVar3 = 0;
  }
  if (iVar3 == 0) {
    iVar2 = iVar1 - DAT_404304bc;
    if (iVar1 == 0) {
      iVar2 = 0;
    }
    *param_1 = iVar2;
  }
  else {
    iVar2 = iVar1 + 4;
    if (iVar1 == 0) {
      iVar2 = 0;
    }
    if (*(int *)(param_2 + 4) == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = *(int *)(param_2 + 4) + DAT_404304bc;
    }
    iVar3 = iVar1 + -4;
    if (iVar1 == 0) {
      iVar3 = 0;
    }
    iVar1 = iVar2 - DAT_404304bc;
    if (iVar2 == 0) {
      iVar1 = 0;
    }
    *(int *)(iVar3 + 8) = iVar1;
  }
  if (*(int *)(param_2 + 8) == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = *(int *)(param_2 + 8) + DAT_404304bc;
  }
  iVar2 = iVar1 + -4;
  if (iVar1 == 0) {
    iVar2 = 0;
  }
  if (iVar2 != 0) {
    if (*(int *)(param_2 + 4) == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = *(int *)(param_2 + 4) + DAT_404304bc;
    }
    iVar2 = iVar1 + -4;
    if (iVar1 == 0) {
      iVar2 = 0;
    }
    iVar1 = iVar2 + 4;
    if (iVar2 == 0) {
      iVar1 = 0;
    }
    if (*(int *)(param_2 + 8) == 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = *(int *)(param_2 + 8) + DAT_404304bc;
    }
    iVar3 = iVar2 + -4;
    if (iVar2 == 0) {
      iVar3 = 0;
    }
    iVar2 = iVar1 - DAT_404304bc;
    if (iVar1 == 0) {
      iVar2 = 0;
    }
    *(int *)(iVar3 + 4) = iVar2;
  }
  *(undefined4 *)(param_2 + 8) = 0;
  *(undefined4 *)(param_2 + 4) = 0;
  return;
}



/* 40418684 FUN_40418684 */

/* Boundary evidence: original MIPS .pdata 40418684..40418703. Semantic name remains unreviewed. */

int FUN_40418684(int *param_1,int *param_2)

{
  int iVar1;
  code *pcVar2;
  int iVar3;
  
  iVar1 = FUN_40429204(param_1,param_2);
  if (-1 < iVar1) {
    if (param_2 == (int *)0x0) {
      iVar3 = 0;
    }
    else {
      iVar3 = (int)param_2 - DAT_404304bc;
    }
    pcVar2 = *(code **)(*param_1 + 0x10);
    param_1[0x1d] = iVar3;
    (*pcVar2)(param_1);
  }
  return iVar1;
}



/* 4041873c FUN_4041873c */

/* Boundary evidence: original MIPS .pdata 4041873c..404187a7. Semantic name remains unreviewed. */

undefined4 * FUN_4041873c(undefined4 *param_1,void *param_2,undefined4 param_3)

{
  param_1[2] = 0;
  param_1[1] = 0;
  *param_1 = &PTR_LAB_40402028;
  param_1[3] = param_3;
  *(undefined2 *)(param_1 + 0x18) = 0;
  if (*(ushort *)((int)param_2 + 0x40) < 0x41) {
    *(ushort *)(param_1 + 0x18) = *(ushort *)((int)param_2 + 0x40);
  }
  else {
    *(undefined2 *)(param_1 + 0x18) = 0x40;
  }
  memcpy(param_1 + 8,param_2,(uint)*(ushort *)(param_1 + 0x18));
  return param_1;
}



/* 404187a8 FUN_404187a8 */

/* Boundary evidence: original MIPS .pdata 404187a8..4041888f. Semantic name remains unreviewed. */

void FUN_404187a8(int *param_1,ushort *param_2,int param_3,void *param_4)

{
  int iVar1;
  int iVar2;
  
  if (*param_1 == 0) goto LAB_4041882c;
  iVar2 = *param_1 + DAT_404304bc;
  while( true ) {
    if (iVar2 == 0) {
      return;
    }
    iVar1 = FUN_404197c0((ushort *)(iVar2 + 0x20),param_2);
    if ((iVar1 != 0) && (param_3 == *(int *)(iVar2 + 0x14))) break;
    if (*(int *)(iVar2 + 8) == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = *(int *)(iVar2 + 8) + DAT_404304bc;
    }
    iVar2 = iVar1 + -4;
    if (iVar1 == 0) {
LAB_4041882c:
      iVar2 = 0;
    }
  }
  if (*(ushort *)((int)param_4 + 0x40) < 0x41) {
    *(ushort *)(iVar2 + 0x60) = *(ushort *)((int)param_4 + 0x40);
  }
  else {
    *(undefined2 *)(iVar2 + 0x60) = 0x40;
  }
  memcpy((void *)(iVar2 + 0x20),param_4,(uint)*(ushort *)(iVar2 + 0x60));
  return;
}



/* 40418890 FUN_40418890 */

/* Boundary evidence: original MIPS .pdata 40418890..404188db. Semantic name remains unreviewed. */

LPVOID FUN_40418890(LPVOID param_1,uint param_2)

{
  FUN_404293e8((int)param_1);
  if ((param_2 & 1) != 0) {
    FUN_4040a65c(param_1);
  }
  return param_1;
}



/* 404188dc FUN_404188dc */

/* Boundary evidence: original MIPS .pdata 404188dc..404189bf. Semantic name remains unreviewed. */

undefined4 *
FUN_404188dc(undefined4 *param_1,void *param_2,undefined4 param_3,undefined4 param_4,int param_5,
            int param_6)

{
  int iVar1;
  
  param_1[1] = param_3;
  *param_1 = &PTR_LAB_4040193c;
  FUN_4041873c(param_1 + 2,param_2,1);
  *param_1 = &PTR_LAB_40402058;
  param_1[2] = &PTR_LAB_40402040;
  param_1[0x1f] = 0;
  param_1[0x1e] = 0;
  param_1[0x21] = 0;
  param_1[0x20] = 0;
  param_1[0x23] = 0;
  param_1[0x22] = 0;
  param_1[0x24] = 0;
  if (param_5 == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = param_5 - DAT_404304bc;
  }
  param_1[0x34] = iVar1 + DAT_404304bc;
  param_1[0x1b] = param_4;
  param_1[0x25] = 0;
  param_1[0x26] = 0;
  param_1[0x1c] = 0;
  if (param_6 == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = param_6 - DAT_404304bc;
  }
  param_1[0x2d] = iVar1;
  param_1[0x2e] = 0;
  param_1[0x1d] = 0;
  return param_1;
}



/* 404189d4 FUN_404189d4 */

/* Boundary evidence: original MIPS .pdata 404189d4..40418a4f. Semantic name remains unreviewed. */

void FUN_404189d4(undefined4 *param_1)

{
  *param_1 = &PTR_LAB_40402058;
  param_1[2] = &PTR_LAB_40402040;
  if (param_1[0x1d] != 0) {
    (**(code **)(*(int *)(param_1[0x1d] + DAT_404304bc) + 0x14))();
  }
  param_1[0x1d] = 0;
  FUN_4042a508((int)(param_1 + 2));
  FUN_404182f0();
  return;
}



/* 40418a50 FUN_40418a50 */

/* Boundary evidence: original MIPS .pdata 40418a50..40418b57. Semantic name remains unreviewed. */

undefined4 FUN_40418a50(int param_1,ushort *param_2,undefined4 *param_3)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  int local_20 [2];
  
  uVar3 = 0;
  iVar1 = FUN_404182f8((int *)(*(int *)(param_1 + 0xb4) + DAT_404304bc + 0x54),param_2,
                       *(int *)(param_1 + 0x20));
  if (iVar1 == 0) {
    iVar1 = FUN_404296f8(param_1 + 0x78,param_2,local_20);
    if (iVar1 == 0) {
      *param_3 = *(undefined4 *)(local_20[0] + 0x84);
      param_3[1] = *(uint *)(local_20[0] + 0x88) & 3;
    }
    else if ((iVar1 == 1) || (*(int *)(param_1 + 0x74) == 0)) {
      uVar3 = 0x80030002;
    }
    else {
      piVar2 = (int *)(DAT_404304bc + *(int *)(param_1 + 0x74));
      uVar3 = (**(code **)(*piVar2 + 0x50))(piVar2,param_2,param_3);
    }
  }
  else {
    *param_3 = *(undefined4 *)(iVar1 + 0x18);
    param_3[1] = *(undefined4 *)(iVar1 + 0xc);
  }
  return uVar3;
}



/* 40418b58 FUN_40418b58 */

/* Boundary evidence: original MIPS .pdata 40418b58..40418c63. Semantic name remains unreviewed. */

int FUN_40418b58(int *param_1,ushort *param_2,void *param_3)

{
  int iVar1;
  void *pvVar2;
  undefined4 local_28;
  undefined4 local_24;
  
  iVar1 = (**(code **)(*param_1 + 0x50))(param_1,param_3,&local_28);
  if (iVar1 < 0) {
    if ((iVar1 == -0x7ffcfffe) &&
       (iVar1 = (**(code **)(*param_1 + 0x50))(param_1,param_2,&local_28), -1 < iVar1)) {
      pvVar2 = FUN_4042987c(param_1 + 0x1e,*(undefined4 *)(param_1[0x34] + DAT_404304bc + 0x2c),
                            param_3,param_2,local_28,local_24,0);
      if (pvVar2 == (void *)0x0) {
        iVar1 = -0x7ffcfff8;
      }
      else {
        FUN_404187a8((int *)(param_1[0x2d] + DAT_404304bc + 0x54),param_2,param_1[8],param_3);
        iVar1 = 0;
      }
    }
  }
  else {
    iVar1 = -0x7ffcfffb;
  }
  return iVar1;
}



/* 40418d80 FUN_40418d80 */

/* Boundary evidence: original MIPS .pdata 40418d80..40418fcf. Semantic name remains unreviewed. */

int FUN_40418d80(int param_1,ushort *param_2,undefined4 param_3,int *param_4)

{
  undefined4 *puVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  ushort *local_30;
  int *local_2c;
  ushort *local_28 [2];
  
  puVar1 = (undefined4 *)
           FUN_404182f8((int *)(*(int *)(param_1 + 0xb4) + DAT_404304bc + 0x54),param_2,
                        *(int *)(param_1 + 0x20));
  if (puVar1 == (undefined4 *)0x0) {
    if (*(int *)(param_1 + 0x74) != 0) {
      iVar2 = FUN_404296f8(param_1 + 0x78,param_2,(undefined4 *)0x0);
      if (iVar2 != 1) {
        local_30 = param_2;
        iVar2 = FUN_404296f8(param_1 + 0x78,param_2,local_28);
        if (((iVar2 == 0) && (local_28[0][0x20] != 0)) && (local_28[0][0x41] != 0)) {
          local_30 = local_28[0];
          FUN_404297bc(local_28[0],&local_30);
        }
        piVar3 = (int *)(*(int *)(param_1 + 0x74) + DAT_404304bc);
        iVar2 = (**(code **)(*piVar3 + 0x34))(piVar3,local_30,param_3,&local_2c);
        if (-1 < iVar2) {
          if (*(int *)(param_1 + 0xd0) == 0) {
            iVar2 = 0;
          }
          else {
            iVar2 = *(int *)(param_1 + 0xd0) + DAT_404304bc;
          }
          puVar1 = (undefined4 *)FUN_4040a638(0xd4);
          if (puVar1 == (undefined4 *)0x0) {
            piVar3 = (int *)0x0;
          }
          else {
            if (*(int *)(param_1 + 0xb4) == 0) {
              iVar4 = 0;
            }
            else {
              iVar4 = *(int *)(param_1 + 0xb4) + DAT_404304bc;
            }
            piVar3 = FUN_404188dc(puVar1,param_2,local_2c[1],*(undefined4 *)(param_1 + 0x6c),iVar2,
                                  iVar4);
          }
          if (piVar3 == (int *)0x0) {
            iVar2 = -0x7ffcfff8;
          }
          else {
            iVar2 = FUN_40418684(piVar3,local_2c);
            if (-1 < iVar2) {
              FUN_4040de60(*(int *)(param_1 + 0xb4) + DAT_404304bc,param_1 + 8,piVar3 + 2,piVar3[1])
              ;
              *param_4 = (int)piVar3;
              return 0;
            }
            FUN_404189d4(piVar3);
            FUN_4040a65c(piVar3);
          }
          (**(code **)(*local_2c + 0x14))();
          return iVar2;
        }
        return iVar2;
      }
    }
  }
  else if (puVar1[3] == 1) {
    (**(code **)*puVar1)(puVar1);
    *param_4 = (int)(puVar1 + -2);
    return 0;
  }
  return -0x7ffcfffe;
}



/* 40418fd0 FUN_40418fd0 */

/* Boundary evidence: original MIPS .pdata 40418fd0..404190ff. Semantic name remains unreviewed. */

int FUN_40418fd0(int *param_1,ushort *param_2,int param_3)

{
  int iVar1;
  void *pvVar2;
  ushort *local_28 [2];
  undefined4 local_20;
  undefined4 local_1c;
  
  if (param_3 == 0) {
    iVar1 = (**(code **)(*param_1 + 0x50))(param_1,param_2,&local_20);
    if (iVar1 < 0) {
      return iVar1;
    }
    pvVar2 = FUN_4042987c(param_1 + 0x1e,*(undefined4 *)(param_1[0x34] + DAT_404304bc + 0x2c),
                          (void *)0x0,param_2,local_20,local_1c,0);
    if (pvVar2 == (void *)0x0) {
      return -0x7ffcfff8;
    }
    iVar1 = FUN_404182f8((int *)(DAT_404304bc + param_1[0x2d] + 0x54),param_2,param_1[8]);
    if (iVar1 != 0) {
      FUN_4040dcb0(DAT_404304bc + param_1[0x2d],*(int *)(iVar1 + 0x18),2);
    }
  }
  else {
    FUN_404296f8((int)(param_1 + 0x1e),param_2,local_28);
    FUN_404292ec((int)param_1,local_28[0]);
    FUN_40429588(param_1 + 0x1e,(int)local_28[0]);
    if (local_28[0] != (ushort *)0x0) {
      FUN_404293e8((int)local_28[0]);
      FUN_4040a65c(local_28[0]);
    }
  }
  return 0;
}



/* 40419100 FUN_40419100 */

/* Boundary evidence: original MIPS .pdata 40419100..4041913f. Semantic name remains unreviewed. */

void FUN_40419100(undefined4 *param_1)

{
  int iVar1;
  
  iVar1 = param_1[0x26];
  param_1[0x26] = iVar1 + -1;
  if (iVar1 + -1 == 0) {
    FUN_404189d4(param_1);
    FUN_4040a65c(param_1);
  }
  return;
}



/* 40419154 FUN_40419154 */

/* Boundary evidence: original MIPS .pdata 40419154..4041936b. Semantic name remains unreviewed. */

int FUN_40419154(int *param_1,void *param_2,uint param_3,int param_4,undefined4 *param_5)

{
  int iVar1;
  int *piVar2;
  undefined4 *puVar3;
  int *piVar4;
  int iVar5;
  void *pvVar6;
  undefined1 auStack_38 [16];
  
  pvVar6 = (LPVOID)0x0;
  if (param_1[0x34] == 0) {
    iVar5 = 0;
  }
  else {
    iVar5 = param_1[0x34] + DAT_404304bc;
  }
  iVar1 = (**(code **)(*param_1 + 0x50))(param_1,param_2,auStack_38);
  if (-1 < iVar1) {
    return -0x7ffcffb0;
  }
  if (param_4 == 0) {
    param_4 = FUN_4040b7a8();
  }
  iVar1 = *(int *)(iVar5 + 0x38);
  puVar3 = (undefined4 *)(iVar1 + DAT_404304bc);
  if (iVar1 == 0) {
    puVar3 = (undefined4 *)0x0;
  }
  *(undefined4 *)(iVar5 + 0x38) = *(undefined4 *)(iVar1 + DAT_404304bc);
  if (puVar3 == (undefined4 *)0x0) {
    piVar2 = (int *)0x0;
  }
  else {
    if (param_1[0x2d] == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = param_1[0x2d] + DAT_404304bc;
    }
    piVar2 = FUN_404188dc(puVar3,param_2,param_4,param_1[0x1b],iVar5,iVar1);
  }
  if ((param_3 & 0x2000) == 0) {
    piVar4 = piVar2 + 2;
    if (piVar2 == (int *)0x0) {
      piVar4 = (int *)0x0;
    }
    pvVar6 = FUN_4042987c(param_1 + 0x1e,*(undefined4 *)(iVar5 + 0x2c),param_2,(void *)0x0,param_4,1
                          ,(int)piVar4);
    if (pvVar6 == (void *)0x0) {
      iVar1 = -0x7ffcfff8;
      goto LAB_404192ec;
    }
  }
  iVar1 = FUN_40418684(piVar2,(int *)0x0);
  if (-1 < iVar1) {
    piVar4 = piVar2 + 2;
    if (piVar2 == (int *)0x0) {
      piVar4 = (int *)0x0;
    }
    FUN_4040de60(param_1[0x2d] + DAT_404304bc,(int)(param_1 + 2),piVar4,param_4);
    *param_5 = piVar2;
    return 0;
  }
  if (pvVar6 != (LPVOID)0x0) {
    FUN_40429588(param_1 + 0x1e,(int)pvVar6);
    FUN_404293e8((int)pvVar6);
    FUN_4040a65c(pvVar6);
  }
LAB_404192ec:
  FUN_404189d4(piVar2);
  *piVar2 = *(int *)(iVar5 + 0x38);
  *(int *)(iVar5 + 0x38) = (int)piVar2 - DAT_404304bc;
  return iVar1;
}



/* 4041936c FUN_4041936c */

int FUN_4041936c(int param_1)

{
  int iVar1;
  
  if (*(int *)(param_1 + 0x6c) == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = *(int *)(param_1 + 0x6c) + DAT_404304bc;
  }
  return iVar1;
}



/* 40419394 FUN_40419394 */

undefined4 FUN_40419394(int param_1)

{
  undefined4 uVar1;
  
  if ((*(uint *)(param_1 + 8) & 0x20) == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = 0x80030102;
  }
  return uVar1;
}



/* 404193bc FUN_404193bc */

void FUN_404193bc(int param_1)

{
  *(undefined4 *)(param_1 + 0x5c) = 0;
  return;
}



/* 404193c4 FUN_404193c4 */

void FUN_404193c4(int param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  
  if (param_2 == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = param_2 - DAT_404304bc;
  }
  *(int *)(param_1 + 0x54) = iVar1;
  *(undefined4 *)(param_1 + 4) = param_3;
  return;
}



/* 404193ec FUN_404193ec */

/* Boundary evidence: original MIPS .pdata 404193ec..4041946f. Semantic name remains unreviewed. */

void FUN_404193ec(undefined4 *param_1)

{
  int iVar1;
  
  *param_1 = &PTR_FUN_404020b0;
  iVar1 = FUN_40419394((int)param_1);
  if (-1 < iVar1) {
    if (param_1[0x16] != 0) {
      FUN_4040d6e4(param_1[0x16] + DAT_404304bc,(int)param_1);
    }
    if (param_1[0x15] != 0) {
      (**(code **)(*(int *)(param_1[0x15] + DAT_404304bc) + 4))();
    }
  }
  return;
}



/* 40419470 FUN_40419470 */

/* Boundary evidence: original MIPS .pdata 40419470..404194bb. Semantic name remains unreviewed. */

undefined4 * FUN_40419470(undefined4 *param_1,uint param_2)

{
  FUN_404193ec(param_1);
  if ((param_2 & 1) != 0) {
    FUN_4040a65c(param_1);
  }
  return param_1;
}



/* 404194bc FUN_404194bc */

/* Boundary evidence: original MIPS .pdata 404194bc..4041959f. Semantic name remains unreviewed. */

int FUN_404194bc(int param_1,undefined4 *param_2,uint param_3)

{
  int iVar1;
  uint uVar2;
  LPVOID pvVar3;
  int *piVar4;
  undefined4 local_20 [2];
  
  iVar1 = FUN_40419394(param_1);
  if (-1 < iVar1) {
    uVar2 = FUN_4040cba8(*(uint *)(param_1 + 8));
    param_2[10] = uVar2;
    param_2[0xc] = 0;
    param_2[0xd] = 0;
    param_2[0xe] = 0;
    param_2[0xf] = 0;
    param_2[0x10] = 0;
    *param_2 = 0;
    if ((param_3 & 1) == 0) {
      pvVar3 = FUN_40419804((void *)(param_1 + 0xc));
      *param_2 = pvVar3;
      if (pvVar3 == (LPVOID)0x0) {
        return -0x7ffcfff8;
      }
    }
    piVar4 = (int *)(*(int *)(param_1 + 0x54) + DAT_404304bc);
    (**(code **)(*piVar4 + 0x20))(piVar4,local_20);
    param_2[3] = 0;
    param_2[2] = local_20[0];
  }
  return iVar1;
}



/* 404195a0 FUN_404195a0 */

/* Boundary evidence: original MIPS .pdata 404195a0..404195df. Semantic name remains unreviewed. */

void FUN_404195a0(int param_1)

{
  *(uint *)(param_1 + 8) = *(uint *)(param_1 + 8) | 0x20;
  (**(code **)(*(int *)(*(int *)(param_1 + 0x54) + DAT_404304bc) + 4))();
  return;
}



/* 404195e0 FUN_404195e0 */

/* Boundary evidence: original MIPS .pdata 404195e0..404196af. Semantic name remains unreviewed. */

int FUN_404195e0(int param_1,uint param_2)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  
  iVar1 = FUN_40419394(param_1);
  if ((-1 < iVar1) && ((*(uint *)(param_1 + 8) & 0x80) != 0)) {
    iVar4 = *(int *)(param_1 + 0x58) + DAT_404304bc;
    iVar2 = FUN_4040d6dc(iVar4);
    if (iVar2 == 0) {
      iVar1 = FUN_4041936c(iVar4);
      if (iVar1 == 0) {
        return -0x7fff0001;
      }
      piVar3 = (int *)FUN_4041936c(iVar4);
      iVar1 = FUN_404171fc(piVar3,(uint)((param_2 & 4) == 0));
    }
    FUN_404193bc(param_1);
  }
  return iVar1;
}



/* 404196b0 FUN_404196b0 */

/* Boundary evidence: original MIPS .pdata 404196b0..4041977b. Semantic name remains unreviewed. */

undefined4 * FUN_404196b0(undefined4 *param_1,int param_2,undefined4 param_3,int param_4)

{
  undefined2 uVar1;
  void *pvVar2;
  undefined2 extraout_var;
  int iVar3;
  
  FUN_4040d724(param_1);
  *param_1 = &PTR_FUN_404020b0;
  param_1[0x15] = 0;
  param_1[2] = param_3;
  if (param_2 == 0) {
    iVar3 = 0;
  }
  else {
    iVar3 = param_2 - DAT_404304bc;
  }
  param_1[0x16] = iVar3;
  param_1[0x18] = 1;
  pvVar2 = (void *)FUN_4040d1f4(param_4);
  uVar1 = FUN_4040d1ec(param_4);
  FUN_4040d674(param_1 + 3,CONCAT22(extraout_var,uVar1),pvVar2);
  FUN_4040d700(param_1[0x16] + DAT_404304bc,(int)param_1);
  param_1[0x17] = 0;
  return param_1;
}



/* 4041977c FUN_4041977c */

/* Boundary evidence: original MIPS .pdata 4041977c..404197bf. Semantic name remains unreviewed. */

void FUN_4041977c(undefined4 *param_1)

{
  LONG LVar1;
  
  LVar1 = InterlockedDecrement(param_1 + 0x18);
  if ((LVar1 == 0) && (param_1 != (undefined4 *)0x0)) {
    FUN_40419470(param_1,1);
  }
  return;
}



/* 404197c0 FUN_404197c0 */

/* Boundary evidence: original MIPS .pdata 404197c0..40419803. Semantic name remains unreviewed. */

undefined4 FUN_404197c0(ushort *param_1,ushort *param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  if ((param_1[0x20] == param_2[0x20]) &&
     (iVar1 = FUN_4040cf10(param_1,param_2,(uint)(param_1[0x20] >> 1)), iVar1 == 0)) {
    uVar2 = 1;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}



/* 40419804 FUN_40419804 */

/* Boundary evidence: original MIPS .pdata 40419804..40419877. Semantic name remains unreviewed. */

LPVOID FUN_40419804(void *param_1)

{
  LPVOID _Dst;
  
  _Dst = CoTaskMemAlloc(*(ushort *)((int)param_1 + 0x40) + 2);
  if (_Dst == (LPVOID)0x0) {
    _Dst = (LPVOID)0x0;
  }
  else {
    memcpy(_Dst,param_1,(uint)*(ushort *)((int)param_1 + 0x40));
    *(undefined2 *)((uint)(*(ushort *)((int)param_1 + 0x40) >> 1) * 2 + (int)_Dst) = 0;
  }
  return _Dst;
}



/* 40419878 FUN_40419878 */

/* Boundary evidence: original MIPS .pdata 40419878..40419893. Semantic name remains unreviewed. */

void FUN_40419878(void *param_1,wchar_t *param_2)

{
  FUN_40410ed4(param_1,param_2);
  return;
}



/* 40419894 FUN_40419894 */

/* Boundary evidence: original MIPS .pdata 40419894..404198df. Semantic name remains unreviewed. */

undefined4 FUN_40419894(LPFILETIME param_1)

{
  BOOL BVar1;
  undefined4 uVar2;
  _SYSTEMTIME _Stack_18;
  
  GetSystemTime(&_Stack_18);
  BVar1 = SystemTimeToFileTime(&_Stack_18,param_1);
  if (BVar1 == 0) {
    uVar2 = 0x80004005;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}



/* 404198e0 FUN_404198e0 */

undefined4 FUN_404198e0(int param_1)

{
  return *(undefined4 *)(param_1 + 0x34);
}



/* 404198e8 FUN_404198e8 */

void FUN_404198e8(int param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 0x34) = param_2;
  *(undefined4 *)(param_1 + 0x200) = 1;
  return;
}



/* 404198f8 FUN_404198f8 */

/* Boundary evidence: original MIPS .pdata 404198f8..4041991b. Semantic name remains unreviewed. */

void FUN_404198f8(LPVOID param_1)

{
  if (param_1 != (LPVOID)0x0) {
    FUN_4041575c(param_1,1);
  }
  return;
}



/* 4041991c FUN_4041991c */

/* Boundary evidence: original MIPS .pdata 4041991c..40419a0f. Semantic name remains unreviewed. */

int FUN_4041991c(undefined4 *param_1,uint param_2,int param_3,int param_4)

{
  int *piVar1;
  int iVar2;
  
  FUN_4040d71c(param_4);
  piVar1 = (int *)FUN_4040a638(0x4b0);
  if (piVar1 == (int *)0x0) {
    piVar1 = (int *)0x0;
  }
  else {
    iVar2 = FUN_4040d71c(param_4);
    piVar1 = FUN_40417298(piVar1,iVar2,param_3,1,param_2,0xc);
  }
  if (piVar1 == (int *)0x0) {
    iVar2 = -0x7ffcfff8;
  }
  else {
    iVar2 = FUN_404173ac(piVar1,0,0);
    if (iVar2 < 0) {
      FUN_4041575c(piVar1,1);
    }
    else {
      *param_1 = piVar1;
      iVar2 = 0;
    }
  }
  return iVar2;
}



/* 40419a10 FUN_40419a10 */

/* Boundary evidence: original MIPS .pdata 40419a10..40419ac3. Semantic name remains unreviewed. */

int FUN_40419a10(int *param_1)

{
  int iVar1;
  undefined2 auStack_20 [2];
  undefined *local_1c;
  int local_18;
  
  FUN_40415908(0x204,0x204,(int *)&local_1c,auStack_20);
  iVar1 = *param_1;
  FUN_4040d1f4(local_1c);
  iVar1 = (**(code **)(iVar1 + 0xc))(param_1);
  if (-1 < iVar1) {
    if (local_18 == 0x200) {
      iVar1 = FUN_4040c940(local_1c);
    }
    else {
      iVar1 = -0x7ffcff03;
    }
  }
  FUN_4041598c(local_1c);
  return iVar1;
}



/* 40419ac4 FUN_40419ac4 */

/* Boundary evidence: original MIPS .pdata 40419ac4..40419bdb. Semantic name remains unreviewed. */

int FUN_40419ac4(int *param_1,undefined4 param_2)

{
  int iVar1;
  undefined2 auStack_28 [2];
  undefined *local_24;
  int local_20;
  
  FUN_40415908(0x204,0x204,(int *)&local_24,auStack_28);
  iVar1 = *param_1;
  FUN_4040d1f4(local_24);
  iVar1 = (**(code **)(iVar1 + 0xc))(param_1);
  if (iVar1 < 0) goto LAB_40419bb4;
  if (local_20 == 0x200) {
    iVar1 = FUN_4040c940(local_24);
    if (iVar1 < 0) goto LAB_40419bb4;
    FUN_404198e8((int)local_24,param_2);
    iVar1 = *param_1;
    FUN_4040d1f4(local_24);
    iVar1 = (**(code **)(iVar1 + 0x10))(param_1);
    if ((iVar1 < 0) || (local_20 == 0x200)) goto LAB_40419bb4;
  }
  iVar1 = -0x7ffcff03;
LAB_40419bb4:
  FUN_4041598c(local_24);
  return iVar1;
}



/* 40419bdc FUN_40419bdc */

/* Boundary evidence: original MIPS .pdata 40419bdc..40419caf. Semantic name remains unreviewed. */

int FUN_40419bdc(int *param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  int iVar2;
  undefined2 auStack_28 [2];
  undefined *local_24;
  int local_20;
  
  FUN_40415908(0x204,0x204,(int *)&local_24,auStack_28);
  iVar2 = *param_1;
  FUN_4040d1f4(local_24);
  iVar2 = (**(code **)(iVar2 + 0xc))(param_1);
  if (-1 < iVar2) {
    if (local_20 == 0x200) {
      iVar2 = FUN_4040c940(local_24);
      if (-1 < iVar2) {
        uVar1 = FUN_404198e0((int)local_24);
        *param_2 = uVar1;
      }
    }
    else {
      iVar2 = -0x7ffcff03;
    }
  }
  FUN_4041598c(local_24);
  return iVar2;
}



/* 40419cb0 FUN_40419cb0 */

/* Boundary evidence: original MIPS .pdata 40419cb0..40419ee7. Semantic name remains unreviewed. */

int FUN_40419cb0(int param_1,undefined4 *param_2,undefined4 *param_3,uint param_4)

{
  bool bVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  int *local_80 [2];
  undefined1 auStack_78 [8];
  int local_70 [16];
  uint local_30;
  
  local_30 = DAT_404303e4;
  bVar1 = (param_4 & 1) == 0;
  uVar4 = (uint)((param_4 & 8) != 0);
  piVar2 = (int *)FUN_4040a638(0x4b0);
  if (piVar2 == (int *)0x0) {
    piVar2 = (int *)0x0;
  }
  else {
    piVar2 = FUN_40417298(piVar2,param_1,(int)param_3,0,0,9);
  }
  if (piVar2 == (int *)0x0) {
    iVar3 = -0x7ffcfff8;
    goto LAB_40419eb0;
  }
  iVar3 = (*(code *)**(undefined4 **)*param_3)((undefined4 *)*param_3,&DAT_40402264,local_80);
  if (iVar3 < 0) {
    iVar3 = (**(code **)(*(int *)*param_3 + 0x24))((int *)*param_3,auStack_78,1);
  }
  else {
    iVar3 = (**(code **)(*local_80[0] + 0x1c))(local_80[0],local_70);
    (**(code **)(*local_80[0] + 8))();
  }
  if (-1 < iVar3) {
    if (local_70[0] == 0) {
      if ((param_4 & 4) == 0) goto LAB_40419e30;
LAB_40419e48:
      iVar3 = FUN_404173ac(piVar2,uVar4,local_70[0]);
    }
    else if (bVar1) {
LAB_40419e30:
      if ((param_4 & 2) != 0) goto LAB_40419e48;
      iVar3 = FUN_404169e8(piVar2);
    }
    else {
      iVar3 = FUN_40417604(piVar2,uVar4);
    }
    if (-1 < iVar3) {
      *param_2 = piVar2;
      if (((!bVar1) && (local_70[0] != 0)) && (uVar4 == 0)) {
        FUN_4042f4c4(local_30);
        return 0x30200;
      }
      FUN_4042f4c4(local_30);
      return 0;
    }
  }
  FUN_4041575c(piVar2,1);
LAB_40419eb0:
  FUN_4042f4c4(local_30);
  return iVar3;
}



/* 40419ee8 FUN_40419ee8 */

void FUN_40419ee8(int param_1)

{
  *(int *)(param_1 + 0x10) = *(int *)(param_1 + 0x10) + 1;
  return;
}



/* 40419ef8 FUN_40419ef8 */

undefined4 FUN_40419ef8(int param_1)

{
  return *(undefined4 *)(param_1 + 0x60);
}



/* 40419f08 FUN_40419f08 */

/* Boundary evidence: original MIPS .pdata 40419f08..40419f8b. Semantic name remains unreviewed. */

int FUN_40419f08(int *param_1,uint param_2,void *param_3)

{
  int iVar1;
  int local_20 [2];
  
  iVar1 = FUN_4041ef6c((int)param_1,param_2,0,local_20);
  if (-1 < iVar1) {
    memcpy(param_3,(void *)(local_20[0] + 0x50),0x10);
    FUN_4041eb24(param_1,param_2);
  }
  return iVar1;
}



/* 40419f8c FUN_40419f8c */

/* Boundary evidence: original MIPS .pdata 40419f8c..4041a00f. Semantic name remains unreviewed. */

int FUN_40419f8c(int *param_1,uint param_2,undefined4 *param_3)

{
  int iVar1;
  int local_20 [2];
  
  iVar1 = FUN_4041ef6c((int)param_1,param_2,0,local_20);
  if (-1 < iVar1) {
    *param_3 = *(undefined4 *)(local_20[0] + 0x60);
    FUN_4041eb24(param_1,param_2);
  }
  return iVar1;
}



/* 4041a010 FUN_4041a010 */

/* Boundary evidence: original MIPS .pdata 4041a010..4041a02f. Semantic name remains unreviewed. */

void FUN_4041a010(int *param_1,uint param_2,int param_3,undefined4 *param_4)

{
  FUN_4042b1f4(param_1,param_2,param_3,0,param_4);
  return;
}



/* 4041a030 FUN_4041a030 */

/* Boundary evidence: original MIPS .pdata 4041a030..4041a07b. Semantic name remains unreviewed. */

void FUN_4041a030(int *param_1,int param_2,uint param_3,int *param_4)

{
  *param_4 = *param_1;
  FUN_4041f8bc((int *)(*param_1 + DAT_404304bc + 0x20c),param_1[1],param_2,param_3,
               (uint *)(param_4 + 1));
  return;
}



/* 4041a07c FUN_4041a07c */

/* Boundary evidence: original MIPS .pdata 4041a07c..4041a10f. Semantic name remains unreviewed. */

int FUN_4041a07c(int *param_1,int param_2,int param_3,int *param_4)

{
  int iVar1;
  undefined4 uStack_20;
  int local_1c;
  int local_18;
  
  *param_4 = *param_1;
  iVar1 = FUN_4042b1f4((int *)(*param_1 + DAT_404304bc + 0x20c),param_1[1],param_2,0,&uStack_20);
  if (-1 < iVar1) {
    if ((param_3 == 0xff) || (param_3 == local_1c)) {
      param_4[1] = local_18;
    }
    else {
      iVar1 = -0x7ffcfffe;
    }
  }
  return iVar1;
}



/* 4041a110 FUN_4041a110 */

/* Boundary evidence: original MIPS .pdata 4041a110..4041a167. Semantic name remains unreviewed. */

void FUN_4041a110(int *param_1,DWORD param_2,DWORD param_3,DWORD param_4,undefined4 param_5,
                 undefined4 param_6,undefined4 param_7)

{
  FUN_40416058((int *)(*param_1 + DAT_404304bc),param_1[1],param_2,param_3,param_4,param_5,param_6,
               param_7);
  return;
}



/* 4041a168 FUN_4041a168 */

/* Boundary evidence: original MIPS .pdata 4041a168..4041a1c7. Semantic name remains unreviewed. */

void FUN_4041a168(undefined4 *param_1)

{
  LPVOID pvVar1;
  int iVar2;
  
  *param_1 = &PTR_FUN_40401994;
  iVar2 = param_1[5];
  if ((iVar2 != 0) && (param_1[6] == 0)) {
    if (iVar2 == 0) {
      pvVar1 = (LPVOID)0x0;
    }
    else {
      pvVar1 = (LPVOID)(iVar2 + DAT_404304bc);
    }
    FUN_404198f8(pvVar1);
  }
  return;
}



/* 4041a1c8 FUN_4041a1c8 */

/* Boundary evidence: original MIPS .pdata 4041a1c8..4041a26f. Semantic name remains unreviewed. */

int FUN_4041a1c8(int *param_1,int *param_2,int param_3,int param_4)

{
  int iVar1;
  
  if (param_4 == 0) {
    iVar1 = FUN_4041a07c(param_2,param_3,1,param_1 + 5);
  }
  else {
    param_1[5] = *param_2;
    iVar1 = FUN_4041f8bc((int *)(*param_2 + DAT_404304bc + 0x20c),param_2[1],param_3,1,
                         (uint *)(param_1 + 6));
  }
  if (-1 < iVar1) {
    (**(code **)(*param_1 + 0x10))(param_1);
  }
  return iVar1;
}



/* 4041a270 FUN_4041a270 */

/* Boundary evidence: original MIPS .pdata 4041a270..4041a2ab. Semantic name remains unreviewed. */

void FUN_4041a270(int param_1,int param_2,int param_3)

{
  FUN_4041fa74((int *)(*(int *)(param_1 + 0x14) + DAT_404304bc + 0x20c),*(uint *)(param_1 + 0x18),
               param_2,param_3);
  return;
}



/* 4041a2ac FUN_4041a2ac */

/* Boundary evidence: original MIPS .pdata 4041a2ac..4041a2f7. Semantic name remains unreviewed. */

void FUN_4041a2ac(int param_1,int param_2)

{
  int *piVar1;
  
  piVar1 = (int *)(*(int *)(param_1 + 0x14) + DAT_404304bc + 0x20c);
  if (param_2 == 0) {
    FUN_4041fb5c(piVar1,*(uint *)(param_1 + 0x18),0);
  }
  else {
    FUN_4041fcc4(piVar1,*(uint *)(param_1 + 0x18),param_2,0);
  }
  return;
}



/* 4041a2f8 FUN_4041a2f8 */

/* Boundary evidence: original MIPS .pdata 4041a2f8..4041a337. Semantic name remains unreviewed. */

void FUN_4041a2f8(int param_1,int param_2,undefined4 *param_3)

{
  FUN_4042b1f4((int *)(*(int *)(param_1 + 0x14) + DAT_404304bc + 0x20c),*(uint *)(param_1 + 0x18),
               param_2,0,param_3);
  return;
}



/* 4041a338 FUN_4041a338 */

/* Boundary evidence: original MIPS .pdata 4041a338..4041a36f. Semantic name remains unreviewed. */

void FUN_4041a338(int param_1,int param_2,undefined4 *param_3)

{
  FUN_4041611c((int *)(*(int *)(param_1 + 0x14) + DAT_404304bc),*(uint *)(param_1 + 0x18),param_2,
               param_3);
  return;
}



/* 4041a370 FUN_4041a370 */

/* Boundary evidence: original MIPS .pdata 4041a370..4041a3ab. Semantic name remains unreviewed. */

void FUN_4041a370(int param_1,undefined4 *param_2,undefined4 *param_3,undefined4 *param_4)

{
  FUN_40416208((int *)(*(int *)(param_1 + 0x14) + DAT_404304bc),*(uint *)(param_1 + 0x18),param_2,
               param_3,param_4);
  return;
}



/* 4041a3ac FUN_4041a3ac */

/* Boundary evidence: original MIPS .pdata 4041a3ac..4041a3df. Semantic name remains unreviewed. */

void FUN_4041a3ac(int param_1,DWORD param_2,DWORD param_3,DWORD param_4,undefined4 param_5,
                 undefined4 param_6,undefined4 param_7)

{
  FUN_4041a110((int *)(param_1 + 0x14),param_2,param_3,param_4,param_5,param_6,param_7);
  return;
}



/* 4041a3e0 FUN_4041a3e0 */

/* Boundary evidence: original MIPS .pdata 4041a3e0..4041a41f. Semantic name remains unreviewed. */

void FUN_4041a3e0(int param_1,int param_2,DWORD param_3,DWORD param_4)

{
  FUN_40415fb8((int *)(*(int *)(param_1 + 0x14) + DAT_404304bc),*(uint *)(param_1 + 0x18),param_2,
               param_3,param_4);
  return;
}



/* 4041a420 FUN_4041a420 */

/* Boundary evidence: original MIPS .pdata 4041a420..4041a453. Semantic name remains unreviewed. */

void FUN_4041a420(int param_1,void *param_2)

{
  FUN_40419f08((int *)(*(int *)(param_1 + 0x14) + DAT_404304bc + 0x20c),*(uint *)(param_1 + 0x18),
               param_2);
  return;
}



/* 4041a454 FUN_4041a454 */

/* Boundary evidence: original MIPS .pdata 4041a454..4041a49f. Semantic name remains unreviewed. */

void FUN_4041a454(int param_1,undefined4 *param_2)

{
  FUN_4041f5f4((int *)(*(int *)(param_1 + 0x14) + DAT_404304bc + 0x20c),*(uint *)(param_1 + 0x18),
               *param_2,param_2[1],param_2[2],param_2[3]);
  return;
}



/* 4041a4a0 FUN_4041a4a0 */

/* Boundary evidence: original MIPS .pdata 4041a4a0..4041a4d3. Semantic name remains unreviewed. */

void FUN_4041a4a0(int param_1,undefined4 *param_2)

{
  FUN_40419f8c((int *)(*(int *)(param_1 + 0x14) + DAT_404304bc + 0x20c),*(uint *)(param_1 + 0x18),
               param_2);
  return;
}



/* 4041a4d4 FUN_4041a4d4 */

/* Boundary evidence: original MIPS .pdata 4041a4d4..4041a50f. Semantic name remains unreviewed. */

void FUN_4041a4d4(int param_1,uint param_2,uint param_3)

{
  FUN_4041f6b4((int *)(*(int *)(param_1 + 0x14) + DAT_404304bc + 0x20c),*(uint *)(param_1 + 0x18),
               param_2,param_3);
  return;
}



/* 4041a510 FUN_4041a510 */

undefined4 * FUN_4041a510(int param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = *(int *)(param_1 + 0x1c) + DAT_404304bc;
  if (*(int *)(param_1 + 0x1c) == 0) {
    iVar3 = 0;
  }
  iVar2 = *(int *)(iVar3 + 0x30);
  puVar1 = (undefined4 *)(iVar2 + DAT_404304bc);
  if (iVar2 == 0) {
    puVar1 = (undefined4 *)0x0;
  }
  *(undefined4 *)(iVar3 + 0x30) = *(undefined4 *)(iVar2 + DAT_404304bc);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    puVar1[1] = param_2;
    *puVar1 = &PTR_FUN_40401994;
    puVar1[3] = 0;
    puVar1[2] = 0;
    puVar1[6] = 0xffffffff;
    puVar1[5] = 0;
    iVar2 = iVar3 - DAT_404304bc;
    if (iVar3 == 0) {
      iVar2 = 0;
    }
    puVar1[7] = iVar2 + DAT_404304bc;
    puVar1[4] = 0;
  }
  return puVar1;
}



/* 4041a59c FUN_4041a59c */

/* Boundary evidence: original MIPS .pdata 4041a59c..4041a703. Semantic name remains unreviewed. */

int FUN_4041a59c(int param_1,int param_2,undefined4 param_3,undefined4 *param_4)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  
  iVar1 = FUN_4040b7a8();
  piVar2 = (int *)FUN_4040a638(0x20);
  if (piVar2 == (int *)0x0) {
    piVar2 = (int *)0x0;
  }
  else {
    if (*(int *)(param_1 + 0x1c) == 0) {
      iVar3 = 0;
    }
    else {
      iVar3 = *(int *)(param_1 + 0x1c) + DAT_404304bc;
    }
    piVar2[1] = iVar1;
    *piVar2 = (int)&PTR_FUN_40401994;
    piVar2[3] = 0;
    piVar2[2] = 0;
    piVar2[6] = -1;
    piVar2[5] = 0;
    iVar1 = iVar3 - DAT_404304bc;
    if (iVar3 == 0) {
      iVar1 = 0;
    }
    piVar2[7] = iVar1 + DAT_404304bc;
    piVar2[4] = 0;
  }
  if (piVar2 == (int *)0x0) {
    iVar1 = -0x7ffcfff8;
  }
  else {
    iVar1 = FUN_4041a07c((int *)(param_1 + 0x14),param_2,1,piVar2 + 5);
    if (iVar1 < 0) {
      FUN_4041a168(piVar2);
      FUN_4040a65c(piVar2);
    }
    else {
      (**(code **)(*piVar2 + 0x10))(piVar2);
      *param_4 = piVar2;
      iVar1 = 0;
    }
  }
  return iVar1;
}



/* 4041a704 FUN_4041a704 */

/* Boundary evidence: original MIPS .pdata 4041a704..4041a743. Semantic name remains unreviewed. */

void FUN_4041a704(undefined4 *param_1)

{
  int iVar1;
  
  iVar1 = param_1[4];
  param_1[4] = iVar1 + -1;
  if (iVar1 + -1 == 0) {
    FUN_4041a168(param_1);
    FUN_4040a65c(param_1);
  }
  return;
}



/* 4041a744 FUN_4041a744 */

/* Boundary evidence: original MIPS .pdata 4041a744..4041a81b. Semantic name remains unreviewed. */

int FUN_4041a744(int param_1,int param_2,undefined4 param_3,int param_4,undefined4 *param_5)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  
  if (param_4 == 0) {
    param_4 = FUN_4040b7a8();
  }
  piVar1 = FUN_4041a510(param_1,param_4);
  iVar2 = FUN_4041a1c8(piVar1,(int *)(param_1 + 0x14),param_2,1);
  if (iVar2 < 0) {
    if (*(int *)(param_1 + 0x1c) == 0) {
      iVar3 = 0;
    }
    else {
      iVar3 = *(int *)(param_1 + 0x1c) + DAT_404304bc;
    }
    FUN_4041a168(piVar1);
    *piVar1 = *(int *)(iVar3 + 0x30);
    *(int *)(iVar3 + 0x30) = (int)piVar1 - DAT_404304bc;
  }
  else {
    iVar2 = 0;
    *param_5 = piVar1;
  }
  return iVar2;
}



/* 4041a81c FUN_4041a81c */

/* Boundary evidence: original MIPS .pdata 4041a81c..4041a867. Semantic name remains unreviewed. */

undefined4 * FUN_4041a81c(undefined4 *param_1,uint param_2)

{
  FUN_40427e60(param_1);
  if ((param_2 & 1) != 0) {
    FUN_4040a65c(param_1);
  }
  return param_1;
}



/* 4041a868 FUN_4041a868 */

/* Boundary evidence: original MIPS .pdata 4041a868..4041a95b. Semantic name remains unreviewed. */

int FUN_4041a868(int param_1,int param_2,undefined4 param_3,undefined4 *param_4)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int iVar3;
  
  uVar1 = FUN_4040b7a8();
  puVar2 = (undefined4 *)FUN_4040a638(0xa0);
  if (puVar2 == (undefined4 *)0x0) {
    puVar2 = (undefined4 *)0x0;
  }
  else {
    puVar2 = FUN_4042917c(puVar2,uVar1);
  }
  if (puVar2 == (undefined4 *)0x0) {
    iVar3 = -0x7ffcfff8;
  }
  else {
    iVar3 = FUN_40427f08(puVar2,(int *)(param_1 + 0x14),param_2,0);
    if (iVar3 < 0) {
      FUN_40427e60(puVar2);
      FUN_4040a65c(puVar2);
    }
    else {
      *param_4 = puVar2;
      iVar3 = 0;
    }
  }
  return iVar3;
}



/* 4041a95c FUN_4041a95c */

/* Boundary evidence: original MIPS .pdata 4041a95c..4041aa6b. Semantic name remains unreviewed. */

int FUN_4041a95c(int param_1,int param_2,undefined4 param_3,int param_4,undefined4 *param_5)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  
  if (param_4 == 0) {
    param_4 = FUN_4040b7a8();
  }
  iVar3 = *(int *)(param_1 + 0x1c) + DAT_404304bc;
  if (*(int *)(param_1 + 0x1c) == 0) {
    iVar3 = 0;
  }
  iVar2 = *(int *)(iVar3 + 0x34);
  puVar1 = (undefined4 *)(iVar2 + DAT_404304bc);
  if (iVar2 == 0) {
    puVar1 = (undefined4 *)0x0;
  }
  *(undefined4 *)(iVar3 + 0x34) = *(undefined4 *)(iVar2 + DAT_404304bc);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    puVar1 = FUN_4042917c(puVar1,param_4);
  }
  iVar3 = FUN_40427f08(puVar1,(int *)(param_1 + 0x14),param_2,1);
  if (iVar3 < 0) {
    if (*(int *)(param_1 + 0x1c) == 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = *(int *)(param_1 + 0x1c) + DAT_404304bc;
    }
    FUN_40427e60(puVar1);
    *puVar1 = *(undefined4 *)(iVar2 + 0x34);
    *(int *)(iVar2 + 0x34) = (int)puVar1 - DAT_404304bc;
  }
  else {
    iVar3 = 0;
    *param_5 = puVar1;
  }
  return iVar3;
}



/* 4041aa6c FUN_4041aa6c */

undefined4 FUN_4041aa6c(int param_1)

{
  return *(undefined4 *)(param_1 + 0x4c);
}



/* 4041aa7c FUN_4041aa7c */

/* Boundary evidence: original MIPS .pdata 4041aa7c..4041aaff. Semantic name remains unreviewed. */

int FUN_4041aa7c(int *param_1,uint param_2,undefined4 *param_3)

{
  int iVar1;
  int local_20 [2];
  
  iVar1 = FUN_4041ef6c((int)param_1,param_2,0,local_20);
  if (-1 < iVar1) {
    *param_3 = *(undefined4 *)(local_20[0] + 0x4c);
    FUN_4041eb24(param_1,param_2);
  }
  return iVar1;
}



/* 4041ab00 FUN_4041ab00 */

undefined4 FUN_4041ab00(int param_1)

{
  return *(undefined4 *)(param_1 + 4);
}



/* 4041ab08 FUN_4041ab08 */

/* Boundary evidence: original MIPS .pdata 4041ab08..4041ac0b. Semantic name remains unreviewed. */

int FUN_4041ab08(int param_1,int param_2,void *param_3,int *param_4)

{
  int iVar1;
  uint local_20;
  uint local_1c;
  
  if (*(int *)(param_1 + 0x14) == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = *(int *)(param_1 + 0x14) + DAT_404304bc;
  }
  iVar1 = FUN_4041aa7c((int *)(iVar1 + 0x20c),*(uint *)(param_1 + 0x18),&local_1c);
  if (-1 < iVar1) {
    if (local_1c == 0xffffffff) {
      iVar1 = -0x7ffcffee;
    }
    else {
      local_20 = 0;
      if (*(int *)(param_1 + 0x14) == 0) {
        iVar1 = 0;
      }
      else {
        iVar1 = *(int *)(param_1 + 0x14) + DAT_404304bc;
      }
      iVar1 = FUN_4041f148((int *)(iVar1 + 0x20c),local_1c,param_2,&local_20);
      if (-1 < iVar1) {
        if (*(int *)(param_1 + 0x14) == 0) {
          iVar1 = 0;
        }
        else {
          iVar1 = *(int *)(param_1 + 0x14) + DAT_404304bc;
        }
        iVar1 = FUN_4041fe64((int *)(iVar1 + 0x20c),local_20,param_3,param_4);
      }
    }
  }
  return iVar1;
}



/* 4041ac0c FUN_4041ac0c */

/* Boundary evidence: original MIPS .pdata 4041ac0c..4041acbf. Semantic name remains unreviewed. */

void FUN_4041ac0c(int param_1,int param_2,void *param_3,int *param_4)

{
  int iVar1;
  undefined4 auStack_28 [2];
  uint local_20;
  
  if (*(int *)(param_1 + 0x14) == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = *(int *)(param_1 + 0x14) + DAT_404304bc;
  }
  iVar1 = FUN_4042b1f4((int *)(iVar1 + 0x20c),*(uint *)(param_1 + 0x18),param_2,0,auStack_28);
  if (-1 < iVar1) {
    if (*(int *)(param_1 + 0x14) == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = *(int *)(param_1 + 0x14) + DAT_404304bc;
    }
    FUN_4041fe64((int *)(iVar1 + 0x20c),local_20,param_3,param_4);
  }
  return;
}



/* 4041acc0 FUN_4041acc0 */

/* Boundary evidence: original MIPS .pdata 4041acc0..4041ad4f. Semantic name remains unreviewed. */

void FUN_4041acc0(int param_1,int param_2)

{
  int iVar1;
  
  if (*(int *)(param_1 + 0x8c) != 0) {
    (**(code **)(*(int *)(*(int *)(param_1 + 0x8c) + DAT_404304bc) + 4))();
  }
  if (param_2 == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = param_2 - DAT_404304bc;
  }
  *(int *)(param_1 + 0x8c) = iVar1;
  if (iVar1 != 0) {
    (*(code *)**(undefined4 **)(iVar1 + DAT_404304bc))();
  }
  return;
}



/* 4041ad50 FUN_4041ad50 */

int FUN_4041ad50(int param_1)

{
  int iVar1;
  
  if (*(int *)(param_1 + 0x70) == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = *(int *)(param_1 + 0x70) + DAT_404304bc;
  }
  return iVar1;
}



/* 4041ad78 FUN_4041ad78 */

/* Boundary evidence: original MIPS .pdata 4041ad78..4041af6b. Semantic name remains unreviewed. */

int FUN_4041ad78(int *param_1,int *param_2,undefined4 param_3,int *param_4)

{
  int iVar1;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38 [2];
  undefined1 auStack_30 [16];
  uint local_20;
  
  local_20 = DAT_404303e4;
  if ((param_4[0x2e] & 1U) != 0) {
    (**(code **)*param_4)(param_4,0,&local_40);
    iVar1 = (**(code **)(*param_1 + 4))(param_1,0,local_40,local_3c);
    if (iVar1 < 0) goto LAB_4041af44;
  }
  if ((param_4[0x2e] & 2U) != 0) {
    (**(code **)*param_4)(param_4,1,&local_40);
    iVar1 = (**(code **)(*param_1 + 4))(param_1,1,local_40,local_3c);
    if (iVar1 < 0) goto LAB_4041af44;
  }
  if ((param_4[0x2e] & 4U) != 0) {
    (**(code **)*param_4)(param_4,2,&local_40);
    iVar1 = (**(code **)(*param_1 + 4))(param_1,2,local_40,local_3c);
    if (iVar1 < 0) goto LAB_4041af44;
  }
  if ((param_4[0x2e] & 8U) != 0) {
    (**(code **)(*param_4 + 0x20))(param_4,auStack_30);
    iVar1 = (**(code **)(*param_1 + 0x24))(param_1,auStack_30);
    if (iVar1 < 0) goto LAB_4041af44;
  }
  if ((param_4[0x2e] & 0x10U) != 0) {
    (**(code **)(*param_4 + 0x28))(param_4,local_38);
    iVar1 = (**(code **)(*param_1 + 0x2c))(param_1,local_38[0],0xffffffff);
    if (iVar1 < 0) goto LAB_4041af44;
  }
  param_1[2] = *param_2;
  param_1[3] = param_2[1];
  iVar1 = FUN_4041b250(param_1,param_2);
LAB_4041af44:
  FUN_4042f4c4(local_20);
  return iVar1;
}



/* 4041af6c FUN_4041af6c */

/* Boundary evidence: original MIPS .pdata 4041af6c..4041afdf. Semantic name remains unreviewed. */

void FUN_4041af6c(int param_1,undefined4 *param_2)

{
  int iVar1;
  
  param_2[0x26] = param_2[0x26] + -1;
  if (*(int *)(param_1 + 0x1c) == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = *(int *)(param_1 + 0x1c) + DAT_404304bc;
  }
  FUN_40427e60(param_2);
  *param_2 = *(undefined4 *)(iVar1 + 0x34);
  *(int *)(iVar1 + 0x34) = (int)param_2 - DAT_404304bc;
  return;
}



/* 4041afe0 FUN_4041afe0 */

/* Boundary evidence: original MIPS .pdata 4041afe0..4041b053. Semantic name remains unreviewed. */

void FUN_4041afe0(int param_1,undefined4 *param_2)

{
  int iVar1;
  
  param_2[4] = param_2[4] + -1;
  if (*(int *)(param_1 + 0x1c) == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = *(int *)(param_1 + 0x1c) + DAT_404304bc;
  }
  FUN_4041a168(param_2);
  *param_2 = *(undefined4 *)(iVar1 + 0x30);
  *(int *)(iVar1 + 0x30) = (int)param_2 - DAT_404304bc;
  return;
}



/* 4041b054 FUN_4041b054 */

/* Boundary evidence: original MIPS .pdata 4041b054..4041b21b. Semantic name remains unreviewed. */

void FUN_4041b054(int param_1,uint param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  undefined4 *puVar5;
  int *piVar6;
  int iVar7;
  
  if ((param_2 & 8) == 0) {
    iVar1 = *(int *)(param_1 + 0xc);
    iVar3 = DAT_404304bc;
    while( true ) {
      iVar2 = iVar1 + iVar3;
      if (iVar1 == 0) {
        iVar2 = 0;
      }
      if (iVar2 == 0) break;
      if (*(short *)(iVar2 + 0x82) == 0) {
        if ((*(uint *)(iVar2 + 0x88) & 3) == 1) {
          iVar1 = *(int *)(iVar2 + 0x8c) + iVar3;
          if (*(int *)(iVar2 + 0x8c) == 0) {
            iVar1 = 0;
          }
          piVar6 = (int *)(iVar1 + -8);
          if (iVar1 == 0) {
            piVar6 = (int *)0x0;
          }
          piVar4 = (int *)(piVar6[0x1d] + iVar3);
          if (piVar6[0x1d] == 0) {
            piVar4 = (int *)0x0;
          }
          if (piVar4 != (int *)0x0) {
            (**(code **)(*piVar4 + 0x10))(piVar4);
            FUN_4042a3b4(piVar6,(int *)0x0);
            FUN_4041afe0(param_1,piVar4);
            iVar3 = DAT_404304bc;
          }
        }
        else {
          if (*(int *)(iVar2 + 0x8c) == 0) {
            iVar1 = 0;
          }
          else {
            iVar1 = *(int *)(iVar2 + 0x8c) + iVar3;
          }
          iVar7 = iVar1 + -8;
          if (iVar1 == 0) {
            iVar7 = 0;
          }
          puVar5 = (undefined4 *)(*(int *)(iVar7 + 0x70) + iVar3);
          if (*(int *)(iVar7 + 0x70) == 0) {
            puVar5 = (undefined4 *)0x0;
          }
          if (puVar5 != (undefined4 *)0x0) {
            (**(code **)*puVar5)(puVar5);
            FUN_4042be7c(iVar7,0);
            FUN_4041af6c(param_1,puVar5);
            iVar3 = DAT_404304bc;
          }
        }
      }
      iVar1 = *(int *)(iVar2 + 0x94);
    }
    *(undefined4 *)(param_1 + 0xc) = 0;
    *(undefined4 *)(param_1 + 8) = 0;
  }
  else {
    iVar2 = *(int *)(param_1 + 8);
    iVar3 = iVar2 + DAT_404304bc;
    iVar1 = DAT_404304bc;
    while( true ) {
      if (iVar2 == 0) {
        iVar3 = 0;
      }
      if (iVar3 == 0) break;
      if (*(short *)(iVar3 + 0x82) == 0) {
        FUN_4041acc0(iVar3,0);
        iVar1 = DAT_404304bc;
      }
      iVar2 = *(int *)(iVar3 + 0x90);
      iVar3 = iVar2 + iVar1;
    }
    FUN_40429664((int *)(param_1 + 8));
  }
  return;
}



/* 4041b21c FUN_4041b21c */

/* Boundary evidence: original MIPS .pdata 4041b21c..4041b24f. Semantic name remains unreviewed. */

void FUN_4041b21c(int param_1)

{
  FUN_4041fb5c((int *)(*(int *)(param_1 + 0x14) + DAT_404304bc + 0x20c),*(uint *)(param_1 + 0x18),0)
  ;
  return;
}



/* 4041b250 FUN_4041b250 */

/* Boundary evidence: original MIPS .pdata 4041b250..4041b313. Semantic name remains unreviewed. */

int FUN_4041b250(int *param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  code *pcVar3;
  
  iVar2 = *param_2;
  iVar1 = 0;
  do {
    if (iVar2 == 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = iVar2 + DAT_404304bc;
    }
    if (iVar2 == 0) {
      return iVar1;
    }
    if (*(short *)(iVar2 + 0x40) == 0) {
      pcVar3 = *(code **)(*param_1 + 0x18);
      iVar1 = 0;
LAB_4041b290:
      iVar1 = (*pcVar3)(param_1,iVar2 + 0x42,iVar1);
    }
    else {
      if (*(short *)(iVar2 + 0x82) != 0) {
        pcVar3 = *(code **)(*param_1 + 0x1c);
        iVar1 = iVar2;
        goto LAB_4041b290;
      }
      iVar1 = FUN_4041b7cc(iVar2,param_1,0x80);
    }
    if (iVar1 < 0) {
      return iVar1;
    }
    iVar2 = *(int *)(iVar2 + 0x90);
  } while( true );
}



/* 4041b314 FUN_4041b314 */

/* Boundary evidence: original MIPS .pdata 4041b314..4041b7cb. Semantic name remains unreviewed. */

int FUN_4041b314(int *param_1,int *param_2,uint param_3,undefined4 *param_4)

{
  int iVar1;
  int *piVar2;
  code *pcVar3;
  size_t _Size;
  int iVar4;
  int *local_e0;
  int *local_dc;
  int *local_d8;
  int *local_d4;
  undefined4 local_d0 [2];
  ushort auStack_c8 [32];
  ushort local_88;
  int local_84;
  undefined1 auStack_80 [16];
  undefined1 auStack_70 [64];
  undefined2 local_30;
  uint local_2c;
  
  local_2c = DAT_404303e4;
  local_30 = 0;
  local_88 = 0;
  iVar1 = (**(code **)(*param_1 + 0x40))(param_1,auStack_70,auStack_c8,0);
  while( true ) {
    if (iVar1 < 0) {
      FUN_4042f4c4(local_2c);
      return 0;
    }
    _Size = (size_t)local_88;
    if (0x40 < _Size) {
      _Size = 0x40;
    }
    local_30 = (undefined2)_Size;
    memcpy(auStack_70,auStack_c8,_Size);
    if (local_84 == 1) break;
    if (local_84 == 2) {
      iVar1 = (**(code **)(*param_1 + 0x3c))(param_1,auStack_c8,0x40,&local_d8);
      if (iVar1 < 0) goto LAB_4041b7bc;
      if (param_1[7] == 0) {
        iVar1 = 0;
      }
      else {
        iVar1 = param_1[7] + DAT_404304bc;
      }
      iVar1 = FUN_40417de8((int *)(iVar1 + 0x34),*(undefined4 *)(iVar1 + 0x2c),1,0xa0);
      if (iVar1 < 0) goto LAB_4041b780;
      iVar1 = (**(code **)(*param_2 + 0x38))(param_2,auStack_c8,0x80,0,&local_d4);
      if (iVar1 < 0) goto LAB_4041b728;
      if ((((param_3 & 4) == 0) &&
          ((param_4 == (undefined4 *)0x0 || (iVar1 = FUN_4040d398(auStack_c8,param_4), iVar1 != 0)))
          ) && (iVar1 = FUN_4040d234(local_d8,local_d4), iVar1 < 0)) goto LAB_4041b6cc;
      (**(code **)(*local_d8 + 4))();
      pcVar3 = *(code **)(*local_d4 + 4);
LAB_4041b664:
      (*pcVar3)();
    }
    iVar1 = (**(code **)(*param_1 + 0x40))(param_1,auStack_70,auStack_c8,0);
  }
  iVar1 = (**(code **)(*param_1 + 0x34))(param_1,auStack_c8,0x40,&local_dc);
  if (iVar1 < 0) goto LAB_4041b7bc;
  if (param_1[7] == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = param_1[7] + DAT_404304bc;
  }
  iVar1 = FUN_40417de8((int *)(iVar1 + 0x30),*(undefined4 *)(iVar1 + 0x2c),1,0x20);
  if (-1 < iVar1) {
    iVar1 = (**(code **)(*param_2 + 0x30))(param_2,auStack_c8,0x80,0,&local_e0);
    if (iVar1 < 0) {
LAB_4041b728:
      if (local_84 == 0) {
        if (param_1[7] == 0) {
          iVar4 = 0;
        }
        else {
          iVar4 = param_1[7] + DAT_404304bc;
        }
        piVar2 = (int *)(iVar4 + 0x34);
      }
      else {
        if (param_1[7] == 0) {
          iVar4 = 0;
        }
        else {
          iVar4 = param_1[7] + DAT_404304bc;
        }
        piVar2 = (int *)(iVar4 + 0x30);
      }
      FUN_40417ee8(piVar2,1);
    }
    else {
      if ((param_3 & 1) != 0) {
        FUN_4040b72c(local_e0,local_dc);
      }
      iVar1 = (**(code **)(*local_dc + 0x20))(local_dc,auStack_80);
      if (((((-1 < iVar1) &&
            (iVar1 = (**(code **)(*local_e0 + 0x24))(local_e0,auStack_80), -1 < iVar1)) &&
           (iVar1 = (**(code **)(*local_dc + 0x28))(local_dc,local_d0), -1 < iVar1)) &&
          (iVar1 = (**(code **)(*local_e0 + 0x2c))(local_e0,local_d0[0],0xffffffff), -1 < iVar1)) &&
         ((((param_3 & 4) != 0 ||
           ((param_4 != (undefined4 *)0x0 && (iVar1 = FUN_4040d398(auStack_c8,param_4), iVar1 == 0))
           )) || (iVar1 = FUN_4041b314(local_dc,local_e0,param_3,(undefined4 *)0x0), -1 < iVar1))))
      {
        (**(code **)(*local_dc + 0x14))();
        pcVar3 = *(code **)(*local_e0 + 0x14);
        goto LAB_4041b664;
      }
LAB_4041b6cc:
      if (local_84 == 0) {
        (**(code **)(*local_d4 + 4))();
      }
      else {
        (**(code **)(*local_e0 + 0x14))();
      }
      (**(code **)(*param_2 + 0x18))(param_2,auStack_c8,1);
    }
  }
LAB_4041b780:
  if (local_84 == 0) {
    (**(code **)(*local_d8 + 4))();
  }
  else {
    (**(code **)(*local_dc + 0x14))();
  }
LAB_4041b7bc:
  FUN_4042f4c4(local_2c);
  return iVar1;
}



/* 4041b7cc FUN_4041b7cc */

/* Boundary evidence: original MIPS .pdata 4041b7cc..4041b963. Semantic name remains unreviewed. */

int FUN_4041b7cc(int param_1,int *param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  uint uVar4;
  int *local_20;
  int *local_1c;
  
  uVar4 = *(uint *)(param_1 + 0x88) & 3;
  if (uVar4 == 1) {
    iVar1 = (**(code **)(*param_2 + 0x30))
                      (param_2,param_1,param_3,*(undefined4 *)(param_1 + 0x84),&local_20);
    if (iVar1 < 0) {
      return iVar1;
    }
    if (*(int *)(param_1 + 0x8c) == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = *(int *)(param_1 + 0x8c) + DAT_404304bc;
    }
    piVar3 = (int *)(iVar1 + -8);
    if (iVar1 == 0) {
      piVar3 = (int *)0x0;
    }
    iVar1 = FUN_4042a3b4(piVar3,local_20);
  }
  else {
    if (uVar4 != 2) {
      return 0;
    }
    iVar1 = (**(code **)(*param_2 + 0x38))
                      (param_2,param_1,param_3,*(undefined4 *)(param_1 + 0x84),&local_1c);
    if (iVar1 < 0) {
      return iVar1;
    }
    if (*(int *)(param_1 + 0x8c) == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = *(int *)(param_1 + 0x8c) + DAT_404304bc;
    }
    iVar2 = iVar1 + -8;
    if (iVar1 == 0) {
      iVar2 = 0;
    }
    iVar1 = FUN_4042be7c(iVar2,(int)local_1c);
  }
  if (-1 < iVar1) {
    return 0;
  }
  if ((*(uint *)(param_1 + 0x88) & 3) == 1) {
    (**(code **)(*local_20 + 0x14))();
  }
  else {
    (**(code **)(*local_1c + 4))();
  }
  (**(code **)(*param_2 + 0x18))(param_2,param_1,1);
  return iVar1;
}



/* 4041b964 FUN_4041b964 */

/* Boundary evidence: original MIPS .pdata 4041b964..4041bb5b. Semantic name remains unreviewed. */

int FUN_4041b964(int *param_1,undefined4 *param_2)

{
  int iVar1;
  code *pcVar2;
  size_t _Size;
  int *local_a8;
  int *local_a4;
  ushort auStack_a0 [32];
  ushort local_60;
  int local_5c;
  undefined1 auStack_58 [64];
  undefined2 local_18;
  uint local_14;
  
  local_14 = DAT_404303e4;
  local_18 = 0;
  local_60 = 0;
  iVar1 = (**(code **)(*param_1 + 0x40))(param_1,auStack_58,auStack_a0,0);
  do {
    if (iVar1 < 0) {
      FUN_4042f4c4(local_14);
      return 0;
    }
    _Size = (size_t)local_60;
    if (0x40 < _Size) {
      _Size = 0x40;
    }
    local_18 = (undefined2)_Size;
    memcpy(auStack_58,auStack_a0,_Size);
    iVar1 = FUN_4040d398(auStack_a0,param_2);
    if (iVar1 == 0) {
      if (local_5c == 1) {
        iVar1 = (**(code **)(*param_1 + 0x34))(param_1,auStack_a0,0xc0,&local_a4);
        if (iVar1 < 0) goto LAB_4041bb4c;
        iVar1 = (**(code **)(*local_a4 + 0x54))();
        if (iVar1 < 0) {
LAB_4041bb10:
          if (local_5c == 0) {
            (**(code **)(*local_a8 + 4))();
          }
          else {
            (**(code **)(*local_a4 + 0x14))();
          }
LAB_4041bb4c:
          FUN_4042f4c4(local_14);
          return iVar1;
        }
        pcVar2 = *(code **)(*local_a4 + 0x14);
      }
      else {
        if (local_5c != 2) goto LAB_4041bac4;
        iVar1 = (**(code **)(*param_1 + 0x3c))(param_1,auStack_a0,0x80,&local_a8);
        if (iVar1 < 0) goto LAB_4041bb4c;
        iVar1 = (**(code **)(*local_a8 + 0x1c))(local_a8,0);
        if (iVar1 < 0) goto LAB_4041bb10;
        pcVar2 = *(code **)(*local_a8 + 4);
      }
      (*pcVar2)();
    }
LAB_4041bac4:
    iVar1 = (**(code **)(*param_1 + 0x40))(param_1,auStack_58,auStack_a0,0);
  } while( true );
}



/* 4041bb5c FUN_4041bb5c */

/* Boundary evidence: original MIPS .pdata 4041bb5c..4041bbc7. Semantic name remains unreviewed. */

undefined4 FUN_4041bb5c(int param_1)

{
  undefined4 uVar1;
  
  if ((*(uint *)(param_1 + 8) & 0x20) == 0) {
    if ((*(uint *)(param_1 + 8) & 0x40) == 0) {
      uVar1 = 0x80030005;
    }
    else {
      uVar1 = (**(code **)(*(int *)(*(int *)(param_1 + 0x54) + DAT_404304bc) + 0x14))();
    }
  }
  else {
    uVar1 = 0x80030102;
  }
  return uVar1;
}



/* 4041bbc8 FUN_4041bbc8 */

/* Boundary evidence: original MIPS .pdata 4041bbc8..4041bc23. Semantic name remains unreviewed. */

undefined4 FUN_4041bbc8(int param_1)

{
  undefined4 uVar1;
  
  if ((*(uint *)(param_1 + 8) & 0x20) == 0) {
    uVar1 = 0;
    (**(code **)(*(int *)(*(int *)(param_1 + 0x54) + DAT_404304bc) + 0x20))();
  }
  else {
    uVar1 = 0x80030102;
  }
  return uVar1;
}



/* 4041bc24 FUN_4041bc24 */

/* Boundary evidence: original MIPS .pdata 4041bc24..4041bc73. Semantic name remains unreviewed. */

LONG FUN_4041bc24(int param_1)

{
  LONG LVar1;
  
  if ((param_1 == 0) || (*(int *)(param_1 + 0x14) != 0x54535845)) {
    LVar1 = 0;
  }
  else {
    InterlockedIncrement((LONG *)(param_1 + 0x18));
    LVar1 = *(LONG *)(param_1 + 0x18);
  }
  return LVar1;
}



/* 4041bcb8 FUN_4041bcb8 */

/* Boundary evidence: original MIPS .pdata 4041bcb8..4041bdcf. Semantic name remains unreviewed. */

undefined4
FUN_4041bcb8(int param_1,int param_2,int param_3,undefined4 param_4,undefined4 param_5,int param_6)

{
  undefined4 *puVar1;
  int iVar2;
  
  if (param_6 == 0) {
    puVar1 = (undefined4 *)FUN_4040a638(8);
    if (puVar1 == (undefined4 *)0x0) {
      puVar1 = (undefined4 *)0x0;
    }
    else {
      *puVar1 = 0;
      puVar1[1] = 1;
    }
    if (puVar1 == (undefined4 *)0x0) {
      return 0x80030008;
    }
    iVar2 = (int)puVar1 - DAT_404304bc;
  }
  else {
    iVar2 = param_6 - DAT_404304bc;
  }
  *(int *)(param_1 + 0x1c) = iVar2;
  *(undefined4 *)(param_1 + 0xc) = param_4;
  *(undefined4 *)(param_1 + 0x10) = param_5;
  if (param_2 == 0) {
    iVar2 = 0;
  }
  else {
    iVar2 = param_2 - DAT_404304bc;
  }
  *(int *)(param_1 + 4) = iVar2;
  if (param_3 == 0) {
    iVar2 = 0;
  }
  else {
    iVar2 = param_3 - DAT_404304bc;
  }
  *(int *)(param_1 + 8) = iVar2;
  InterlockedIncrement((LONG *)(iVar2 + DAT_404304bc + 0x18));
  *(undefined4 *)(param_1 + 0x18) = 1;
  *(undefined4 *)(param_1 + 0x14) = 0x54535845;
  return 0;
}



/* 4041bdd0 FUN_4041bdd0 */

/* Boundary evidence: original MIPS .pdata 4041bdd0..4041bfc7. Semantic name remains unreviewed. */

int FUN_4041bdd0(int *param_1,int *param_2,int *param_3)

{
  BOOL BVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  int *local_20 [2];
  
  BVar1 = IsBadWritePtr(param_3,4);
  if (BVar1 != 0) {
    return -0x7ffcfff7;
  }
  *param_3 = 0;
  if ((param_1 == (int *)0x0) || (param_1[5] != 0x54535845)) {
    return -0x7ffcfffa;
  }
  if ((*(uint *)(param_1[1] + DAT_404304bc + 8) & 0x20) != 0) {
    return -0x7ffcfefe;
  }
  iVar3 = *param_2;
  iVar4 = 0;
  if (((((iVar3 == 0xc) && (param_2[1] == 0)) && (param_2[2] == 0xc0)) && (param_2[3] == 0x46000000)
      ) || (((iVar3 == 0 && (param_2[1] == 0)) &&
            ((param_2[2] == 0xc0 && (param_2[3] == 0x46000000)))))) {
LAB_4041bf84:
    *param_3 = (int)param_1;
    (**(code **)(*param_1 + 4))(param_1);
  }
  else {
    if (((iVar3 == 3) && (param_2[1] == 0)) && ((param_2[2] == 0xc0 && (param_2[3] == 0x46000000))))
    {
      puVar2 = *(undefined4 **)(param_1[3] + 0x10);
      if (puVar2 == (undefined4 *)0x0) {
        puVar2 = *(undefined4 **)(param_1[3] + 8);
      }
      iVar4 = (**(code **)*puVar2)(puVar2,&DAT_40402294,local_20);
      if (-1 < iVar4) {
        (**(code **)(*local_20[0] + 8))();
        goto LAB_4041bf84;
      }
    }
    iVar4 = -0x7fffbffe;
  }
  return iVar4;
}



/* 4041bfc8 FUN_4041bfc8 */

void FUN_4041bfc8(int param_1)

{
  int iVar1;
  
  *(undefined4 *)(param_1 + 0x5c) = 1;
  iVar1 = *(int *)(param_1 + 0x58) + DAT_404304bc;
  do {
    *(ushort *)(iVar1 + 0x68) = *(ushort *)(iVar1 + 0x68) | 1;
    if ((*(uint *)(iVar1 + 8) & 2) != 0) {
      return;
    }
    if (*(int *)(iVar1 + 0x58) == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = *(int *)(iVar1 + 0x58) + DAT_404304bc;
    }
  } while (iVar1 != 0);
  return;
}



/* 4041c024 FUN_4041c024 */

/* Boundary evidence: original MIPS .pdata 4041c024..4041c0bb. Semantic name remains unreviewed. */

int FUN_4041c024(int param_1)

{
  int iVar1;
  
  if ((*(uint *)(param_1 + 8) & 0x20) == 0) {
    if ((*(uint *)(param_1 + 8) & 0x80) == 0) {
      iVar1 = -0x7ffcfffb;
    }
    else {
      iVar1 = (**(code **)(*(int *)(*(int *)(param_1 + 0x54) + DAT_404304bc) + 0x18))();
      if (-1 < iVar1) {
        FUN_4041bfc8(param_1);
      }
    }
  }
  else {
    iVar1 = -0x7ffcfefe;
  }
  return iVar1;
}



/* 4041c0bc FUN_4041c0bc */

/* Boundary evidence: original MIPS .pdata 4041c0bc..4041c14f. Semantic name remains unreviewed. */

int FUN_4041c0bc(int param_1)

{
  int iVar1;
  
  if ((*(uint *)(param_1 + 8) & 0x20) == 0) {
    if ((*(uint *)(param_1 + 8) & 0x80) == 0) {
      iVar1 = -0x7ffcfffb;
    }
    else {
      iVar1 = (**(code **)(*(int *)(*(int *)(param_1 + 0x54) + DAT_404304bc) + 0x1c))();
      if (-1 < iVar1) {
        FUN_4041bfc8(param_1);
      }
    }
  }
  else {
    iVar1 = -0x7ffcfefe;
  }
  return iVar1;
}



/* 4041c150 FUN_4041c150 */

/* Boundary evidence: original MIPS .pdata 4041c150..4041c28b. Semantic name remains unreviewed. */

void FUN_4041c150(undefined4 *param_1)

{
  int iVar1;
  int iVar2;
  int local_18;
  
  *param_1 = &PTR_FUN_404020b4;
  param_1[5] = 0x74537845;
  if (param_1[3] != 0) {
    local_18 = FUN_40410db8();
    iVar1 = param_1[3];
    iVar2 = param_1[2] + DAT_404304bc;
    *(undefined4 *)(iVar2 + 0xc) = *(undefined4 *)(iVar1 + 8);
    *(undefined4 *)(iVar2 + 0x10) = *(undefined4 *)(iVar1 + 0xc);
    *(undefined4 *)(iVar2 + 0x14) = *(undefined4 *)(iVar1 + 0x10);
  }
  if (param_1[1] != 0) {
    FUN_4041977c((undefined4 *)(param_1[1] + DAT_404304bc));
  }
  if (param_1[7] != 0) {
    FUN_4042cfe8((LPVOID)(param_1[7] + DAT_404304bc));
  }
  if (param_1[2] != 0) {
    FUN_40417ff8((LPVOID)(param_1[2] + DAT_404304bc));
  }
  if ((param_1[4] == 0) || ((LPVOID)param_1[3] == (LPVOID)0x0)) {
    if ((param_1[3] != 0) && ((-1 < local_18 && (iVar1 = __GetUserKData(8), DAT_40430480 == iVar1)))
       ) {
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_4043047c);
    }
  }
  else {
    FUN_40405860((LPVOID)param_1[3]);
  }
  return;
}



/* 4041c28c FUN_4041c28c */

/* Boundary evidence: original MIPS .pdata 4041c28c..4041c443. Semantic name remains unreviewed. */

int FUN_4041c28c(int param_1,int param_2,undefined4 param_3,undefined4 *param_4)

{
  BOOL BVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  iVar6 = *(int *)(param_1 + 0xc);
  iVar4 = -0x7ffcff00;
  if (*(int *)(param_1 + 8) == 0) {
    iVar5 = 0;
  }
  else {
    iVar5 = *(int *)(param_1 + 8) + DAT_404304bc;
  }
  if ((param_4 == (undefined4 *)0x0) || (BVar1 = IsBadWritePtr(param_4,4), BVar1 == 0)) {
    if (param_2 == 0) {
      iVar3 = -0x7ffcfff7;
    }
    else if (*(int *)(param_1 + 0x14) == 0x54535845) {
      iVar4 = FUN_40410db8();
      iVar3 = iVar4;
      if (-1 < iVar4) {
        *(undefined4 *)(iVar5 + 0xc) = *(undefined4 *)(iVar6 + 8);
        *(undefined4 *)(iVar5 + 0x10) = *(undefined4 *)(iVar6 + 0xc);
        *(undefined4 *)(iVar5 + 0x14) = *(undefined4 *)(iVar6 + 0x10);
        iVar3 = FUN_4041bb5c(*(int *)(param_1 + 4) + DAT_404304bc);
        puVar2 = (undefined4 *)(DAT_404304bc + *(int *)(param_1 + 0x1c));
        *puVar2 = *puVar2;
      }
    }
    else {
      iVar3 = -0x7ffcfffa;
    }
    if (param_4 != (undefined4 *)0x0) {
      *param_4 = 0;
    }
    if ((-1 < iVar4) && (iVar4 = __GetUserKData(8), DAT_40430480 == iVar4)) {
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_4043047c);
    }
  }
  else {
    iVar3 = -0x7ffcfff7;
  }
  return iVar3;
}



/* 4041c444 FUN_4041c444 */

/* Boundary evidence: original MIPS .pdata 4041c444..4041c5fb. Semantic name remains unreviewed. */

int FUN_4041c444(int param_1,int param_2,undefined4 param_3,undefined4 *param_4)

{
  BOOL BVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  iVar6 = *(int *)(param_1 + 0xc);
  iVar4 = -0x7ffcff00;
  if (*(int *)(param_1 + 8) == 0) {
    iVar5 = 0;
  }
  else {
    iVar5 = *(int *)(param_1 + 8) + DAT_404304bc;
  }
  if ((param_4 == (undefined4 *)0x0) || (BVar1 = IsBadWritePtr(param_4,4), BVar1 == 0)) {
    if (param_2 == 0) {
      iVar3 = -0x7ffcfff7;
    }
    else if (*(int *)(param_1 + 0x14) == 0x54535845) {
      iVar4 = FUN_40410db8();
      iVar3 = iVar4;
      if (-1 < iVar4) {
        *(undefined4 *)(iVar5 + 0xc) = *(undefined4 *)(iVar6 + 8);
        *(undefined4 *)(iVar5 + 0x10) = *(undefined4 *)(iVar6 + 0xc);
        *(undefined4 *)(iVar5 + 0x14) = *(undefined4 *)(iVar6 + 0x10);
        iVar3 = FUN_4041c024(*(int *)(param_1 + 4) + DAT_404304bc);
        puVar2 = (undefined4 *)(DAT_404304bc + *(int *)(param_1 + 0x1c));
        *puVar2 = *puVar2;
      }
    }
    else {
      iVar3 = -0x7ffcfffa;
    }
    if (param_4 != (undefined4 *)0x0) {
      *param_4 = 0;
    }
    if ((-1 < iVar4) && (iVar4 = __GetUserKData(8), DAT_40430480 == iVar4)) {
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_4043047c);
    }
  }
  else {
    iVar3 = -0x7ffcfff7;
  }
  return iVar3;
}



/* 4041c5fc FUN_4041c5fc */

/* Boundary evidence: original MIPS .pdata 4041c5fc..4041c8df. Semantic name remains unreviewed. */

int FUN_4041c5fc(int param_1,undefined4 param_2,uint param_3,int param_4,int param_5,uint *param_6)

{
  BOOL BVar1;
  int iVar2;
  uint *puVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  uint local_30;
  
  iVar6 = *(int *)(param_1 + 0xc);
  if (*(int *)(param_1 + 8) == 0) {
    iVar5 = 0;
  }
  else {
    iVar5 = *(int *)(param_1 + 8) + DAT_404304bc;
  }
  if (param_6 != (uint *)0x0) {
    BVar1 = IsBadWritePtr(param_6,8);
    if (BVar1 != 0) {
      return -0x7ffcfff7;
    }
    param_6[1] = 0;
    *param_6 = 0;
  }
  if (param_5 == 0) {
    if (param_4 != 0) {
      param_3 = 0xffffffff;
    }
  }
  else {
    if ((param_5 != 1) && (param_5 != 2)) {
      return -0x7ffcffff;
    }
    if ((param_4 < 1) && ((param_4 != 0 || (param_3 < 0x80000000)))) {
      if ((param_4 < -1) || ((param_4 == -1 && (param_3 < 0x80000000)))) {
        param_3 = 0x80000000;
      }
    }
    else {
      param_3 = 0x7fffffff;
    }
  }
  if (*(int *)(param_1 + 0x14) != 0x54535845) {
    return -0x7ffcfffa;
  }
  iVar2 = FUN_40410db8();
  if (iVar2 < 0) {
    return iVar2;
  }
  if ((*(uint *)(*(int *)(param_1 + 4) + DAT_404304bc + 8) & 0x20) != 0) {
    iVar2 = -0x7ffcfefe;
    goto LAB_4041c888;
  }
  iVar2 = 0;
  *(undefined4 *)(iVar5 + 0xc) = *(undefined4 *)(iVar6 + 8);
  *(undefined4 *)(iVar5 + 0x10) = *(undefined4 *)(iVar6 + 0xc);
  *(undefined4 *)(iVar5 + 0x14) = *(undefined4 *)(iVar6 + 0x10);
  puVar3 = (uint *)(*(int *)(param_1 + 0x1c) + DAT_404304bc);
  uVar4 = param_3;
  if (param_5 != 0) {
    if (param_5 == 1) {
      uVar4 = *puVar3;
      if ((int)param_3 < 0) {
        if (uVar4 < -param_3) {
LAB_4041c804:
          iVar2 = -0x7ffcffff;
          goto LAB_4041c888;
        }
      }
      else if (-uVar4 - 1 < param_3) {
        param_3 = -uVar4 - 1;
      }
      uVar4 = uVar4 + param_3;
    }
    else {
      uVar4 = *puVar3;
      if (param_5 == 2) {
        iVar2 = FUN_4041bbc8(*(int *)(param_1 + 4) + DAT_404304bc);
        if (iVar2 < 0) goto LAB_4041c888;
        if ((int)param_3 < 0) {
          if (local_30 < -param_3) goto LAB_4041c804;
        }
        else if (-local_30 - 1 < param_3) {
          param_3 = -local_30 - 1;
        }
        uVar4 = local_30 + param_3;
      }
    }
  }
  *(uint *)(*(int *)(param_1 + 0x1c) + DAT_404304bc) = uVar4;
  if (param_6 != (uint *)0x0) {
    *param_6 = uVar4;
    param_6[1] = 0;
  }
LAB_4041c888:
  iVar6 = __GetUserKData(8);
  if (DAT_40430480 == iVar6) {
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_4043047c);
  }
  return iVar2;
}



/* 4041c8e0 FUN_4041c8e0 */

/* Boundary evidence: original MIPS .pdata 4041c8e0..4041c9f3. Semantic name remains unreviewed. */

int FUN_4041c8e0(int param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = *(int *)(param_1 + 0xc);
  if (*(int *)(param_1 + 8) == 0) {
    iVar2 = 0;
  }
  else {
    iVar2 = *(int *)(param_1 + 8) + DAT_404304bc;
  }
  if (param_4 == 0) {
    if (*(int *)(param_1 + 0x14) == 0x54535845) {
      iVar1 = FUN_40410db8();
      if (-1 < iVar1) {
        *(undefined4 *)(iVar2 + 0xc) = *(undefined4 *)(iVar3 + 8);
        *(undefined4 *)(iVar2 + 0x10) = *(undefined4 *)(iVar3 + 0xc);
        *(undefined4 *)(iVar2 + 0x14) = *(undefined4 *)(iVar3 + 0x10);
        iVar1 = FUN_4041c0bc(*(int *)(param_1 + 4) + DAT_404304bc);
        iVar3 = __GetUserKData(8);
        if (DAT_40430480 == iVar3) {
          LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_4043047c);
        }
      }
    }
    else {
      iVar1 = -0x7ffcfffa;
    }
  }
  else {
    iVar1 = -0x7ffcffff;
  }
  return iVar1;
}



/* 4041c9f4 FUN_4041c9f4 */

/* Boundary evidence: original MIPS .pdata 4041c9f4..4041ce37. Semantic name remains unreviewed. */

int FUN_4041c9f4(int *param_1,int *param_2,uint param_3,int param_4,int *param_5,int *param_6)

{
  bool bVar1;
  BOOL BVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  undefined4 uVar11;
  uint *puVar12;
  LPVOID pv;
  uint local_3c;
  uint local_38;
  uint local_34;
  uint local_30 [2];
  
  iVar9 = -0x7ffcff00;
  iVar8 = 0;
  pv = (LPVOID)0x0;
  if (param_5 == (int *)0x0) {
LAB_4041ca8c:
    if (param_6 != (int *)0x0) {
      BVar2 = IsBadWritePtr(param_6,8);
      if (BVar2 != 0) goto LAB_4041ca74;
      param_6[1] = 0;
      *param_6 = 0;
    }
    iVar3 = FUN_40409b68();
    if (iVar3 != 0) {
      if (param_1[5] == 0x54535845) {
        if (param_4 != 0) {
          param_3 = 0xffffffff;
        }
        iVar9 = FUN_40410db8();
        iVar3 = iVar9;
        if (-1 < iVar9) {
          iVar3 = param_1[3];
          iVar4 = param_1[2] + DAT_404304bc;
          *(undefined4 *)(iVar4 + 0xc) = *(undefined4 *)(iVar3 + 8);
          *(undefined4 *)(iVar4 + 0x10) = *(undefined4 *)(iVar3 + 0xc);
          *(undefined4 *)(iVar4 + 0x14) = *(undefined4 *)(iVar3 + 0x10);
          iVar4 = iVar9;
          iVar3 = FUN_4041bbc8(param_1[1] + DAT_404304bc);
          if (-1 < iVar3) {
            uVar7 = *(uint *)(DAT_404304bc + param_1[7]);
            if (local_3c < uVar7) {
              param_3 = 0;
            }
            else if (local_3c - uVar7 < param_3) {
              param_3 = local_3c - uVar7;
            }
            puVar12 = local_30;
            bVar1 = true;
            uVar11 = 1;
            iVar3 = (**(code **)(*param_2 + 0x14))(param_2);
            if (-1 < iVar3) {
              if (-local_30[0] - 1 < param_3) {
                param_3 = -local_30[0] - 1;
              }
              pv = CoTaskMemAlloc(0x2000);
              if (pv == (LPVOID)0x0) {
                iVar3 = -0x7ffcfff8;
              }
              else {
                iVar9 = iVar4;
                if ((uVar7 < local_30[0]) && (local_30[0] < uVar7 + param_3)) {
                  uVar5 = local_30[0] + param_3;
                  uVar10 = uVar7 + param_3;
                }
                else {
                  bVar1 = false;
                  uVar5 = local_34;
                  uVar10 = local_34;
                }
                for (; param_3 != 0; param_3 = param_3 - uVar6) {
                  uVar6 = param_3;
                  if (0x1fff < param_3) {
                    uVar6 = 0x2000;
                  }
                  if (bVar1) {
                    uVar10 = uVar10 - uVar6;
                    *(uint *)(DAT_404304bc + param_1[7]) = uVar10;
                    uVar5 = uVar5 - uVar6;
                    puVar12 = (uint *)0x0;
                    uVar11 = 0;
                    iVar3 = (**(code **)(*param_2 + 0x14))();
                    if (iVar3 < 0) goto LAB_4041cc9c;
                  }
                  iVar3 = (**(code **)(*param_1 + 0xc))
                                    (param_1,pv,uVar6,&local_38,uVar11,puVar12,iVar9,pv,uVar5);
                  if (iVar3 < 0) goto LAB_4041cc9c;
                  if (uVar6 != local_38) {
                    iVar3 = -0x7ffcffe2;
                    goto LAB_4041cc9c;
                  }
                  iVar3 = (**(code **)(*param_2 + 0x10))(param_2,pv,uVar6,&local_34);
                  if (iVar3 < 0) goto LAB_4041cc9c;
                  if (uVar6 != local_34) {
                    iVar3 = -0x7ffcffe3;
                    goto LAB_4041cc9c;
                  }
                  iVar8 = uVar6 + iVar8;
                }
                if (bVar1) {
                  *(uint *)(DAT_404304bc + param_1[7]) = uVar7 + iVar8;
                  iVar3 = (**(code **)(*param_2 + 0x14))(param_2);
                }
              }
            }
          }
        }
      }
      else {
        iVar3 = -0x7ffcfffa;
      }
      goto LAB_4041cc9c;
    }
  }
  else {
    BVar2 = IsBadWritePtr(param_5,8);
    if (BVar2 == 0) {
      param_5[1] = 0;
      *param_5 = 0;
      goto LAB_4041ca8c;
    }
  }
LAB_4041ca74:
  iVar3 = -0x7ffcfff7;
LAB_4041cc9c:
  CoTaskMemFree(pv);
  if (param_5 != (int *)0x0) {
    param_5[1] = 0;
    *param_5 = iVar8;
  }
  if (param_6 != (int *)0x0) {
    param_6[1] = 0;
    *param_6 = iVar8;
  }
  if ((-1 < iVar9) && (iVar8 = __GetUserKData(8), DAT_40430480 == iVar8)) {
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_4043047c);
  }
  return iVar3;
}



/* 4041ce38 FUN_4041ce38 */

/* Boundary evidence: original MIPS .pdata 4041ce38..4041cfe7. Semantic name remains unreviewed. */

int FUN_4041ce38(int param_1,void *param_2,uint param_3)

{
  BOOL BVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 auStack_70 [18];
  uint local_28;
  
  local_28 = DAT_404303e4;
  iVar4 = *(int *)(param_1 + 0xc);
  if (*(int *)(param_1 + 8) == 0) {
    iVar3 = 0;
  }
  else {
    iVar3 = *(int *)(param_1 + 8) + DAT_404304bc;
  }
  BVar1 = IsBadWritePtr(param_2,0x48);
  if (BVar1 == 0) {
    iVar2 = 0;
    if ((param_3 & 0xfffffffe) != 0) {
      iVar2 = -0x7ffcff01;
    }
    if (-1 < iVar2) {
      if (*(int *)(param_1 + 0x14) == 0x54535845) {
        iVar2 = FUN_40410db8();
        if (-1 < iVar2) {
          *(undefined4 *)(iVar3 + 0xc) = *(undefined4 *)(iVar4 + 8);
          *(undefined4 *)(iVar3 + 0x10) = *(undefined4 *)(iVar4 + 0xc);
          *(undefined4 *)(iVar3 + 0x14) = *(undefined4 *)(iVar4 + 0x10);
          iVar2 = FUN_404194bc(*(int *)(param_1 + 4) + DAT_404304bc,auStack_70,param_3);
          if (-1 < iVar2) {
            memcpy(param_2,auStack_70,0x48);
            *(undefined4 *)((int)param_2 + 4) = 2;
            *(undefined4 *)((int)param_2 + 0x2c) = 0;
            *(undefined4 *)((int)param_2 + 0x44) = 0;
            *(undefined4 *)((int)param_2 + 0x1c) = 0;
            *(undefined4 *)((int)param_2 + 0x18) = 0;
            *(undefined4 *)((int)param_2 + 0x14) = 0;
            *(undefined4 *)((int)param_2 + 0x10) = 0;
            *(undefined4 *)((int)param_2 + 0x24) = 0;
            *(undefined4 *)((int)param_2 + 0x20) = 0;
          }
          iVar4 = __GetUserKData(8);
          if (DAT_40430480 == iVar4) {
            LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_4043047c);
          }
        }
      }
      else {
        iVar2 = -0x7ffcfffa;
      }
    }
  }
  else {
    iVar2 = -0x7ffcfff7;
  }
  FUN_4042f4c4(local_28);
  return iVar2;
}



/* 4041cfe8 FUN_4041cfe8 */

/* Boundary evidence: original MIPS .pdata 4041cfe8..4041d0e7. Semantic name remains unreviewed. */

int FUN_4041cfe8(int param_1,uint param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = *(int *)(param_1 + 0xc);
  if (*(int *)(param_1 + 8) == 0) {
    iVar2 = 0;
  }
  else {
    iVar2 = *(int *)(param_1 + 8) + DAT_404304bc;
  }
  if (*(int *)(param_1 + 0x14) == 0x54535845) {
    iVar1 = FUN_40410db8();
    if (-1 < iVar1) {
      *(undefined4 *)(iVar2 + 0xc) = *(undefined4 *)(iVar3 + 8);
      *(undefined4 *)(iVar2 + 0x10) = *(undefined4 *)(iVar3 + 0xc);
      *(undefined4 *)(iVar2 + 0x14) = *(undefined4 *)(iVar3 + 0x10);
      iVar1 = FUN_404195e0(*(int *)(param_1 + 4) + DAT_404304bc,param_2);
      iVar3 = __GetUserKData(8);
      if (DAT_40430480 == iVar3) {
        LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_4043047c);
      }
    }
  }
  else {
    iVar1 = -0x7ffcfffa;
  }
  return iVar1;
}



/* 4041d0e8 FUN_4041d0e8 */

undefined4 * FUN_4041d0e8(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_404020b4;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[6] = 0;
  param_1[7] = 0;
  param_1[1] = 0;
  return param_1;
}



/* 4041d114 FUN_4041d114 */

/* Boundary evidence: original MIPS .pdata 4041d114..4041d1df. Semantic name remains unreviewed. */

LONG FUN_4041d114(undefined4 *param_1)

{
  LONG LVar1;
  int iVar2;
  int iVar3;
  
  if ((param_1 != (undefined4 *)0x0) && (param_1[5] == 0x54535845)) {
    LVar1 = InterlockedDecrement(param_1 + 6);
    if (LVar1 == 0) {
      if ((param_1[4] != 0) || ((*(uint *)(param_1[1] + DAT_404304bc + 8) & 0x20) == 0)) {
        iVar3 = param_1[3];
        iVar2 = param_1[2] + DAT_404304bc;
        *(undefined4 *)(iVar2 + 0xc) = *(undefined4 *)(iVar3 + 8);
        *(undefined4 *)(iVar2 + 0x10) = *(undefined4 *)(iVar3 + 0xc);
        *(undefined4 *)(iVar2 + 0x14) = *(undefined4 *)(iVar3 + 0x10);
      }
      FUN_4041c150(param_1);
      FUN_4040a65c(param_1);
      return 0;
    }
    if (-1 < LVar1) {
      return LVar1;
    }
  }
  return 0;
}



/* 4041d1e0 FUN_4041d1e0 */

/* Boundary evidence: original MIPS .pdata 4041d1e0..4041d48b. Semantic name remains unreviewed. */

int FUN_4041d1e0(int param_1,undefined4 *param_2)

{
  BOOL BVar1;
  int iVar2;
  undefined4 *puVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  
  iVar6 = *(int *)(param_1 + 0xc);
  piVar4 = (int *)0x0;
  if (*(int *)(param_1 + 8) == 0) {
    iVar5 = 0;
  }
  else {
    iVar5 = *(int *)(param_1 + 8) + DAT_404304bc;
  }
  BVar1 = IsBadWritePtr(param_2,4);
  if (BVar1 != 0) {
    return -0x7ffcfff7;
  }
  *param_2 = 0;
  if (*(int *)(param_1 + 0x14) != 0x54535845) {
    return -0x7ffcfffa;
  }
  iVar2 = FUN_40410db8();
  if (iVar2 < 0) {
    return iVar2;
  }
  if ((*(uint *)(*(int *)(param_1 + 4) + DAT_404304bc + 8) & 0x20) == 0) {
    *(undefined4 *)(iVar5 + 0xc) = *(undefined4 *)(iVar6 + 8);
    *(undefined4 *)(iVar5 + 0x10) = *(undefined4 *)(iVar6 + 0xc);
    *(undefined4 *)(iVar5 + 0x14) = *(undefined4 *)(iVar6 + 0x10);
    puVar3 = (undefined4 *)FUN_4040a638(8);
    if (puVar3 == (undefined4 *)0x0) {
      puVar3 = (undefined4 *)0x0;
    }
    else {
      *puVar3 = *(undefined4 *)(*(int *)(param_1 + 0x1c) + DAT_404304bc);
      puVar3[1] = 1;
    }
    if (puVar3 == (undefined4 *)0x0) {
      iVar6 = -0x7ffcfff8;
    }
    else {
      piVar4 = (int *)FUN_4040a638(0x20);
      if (piVar4 == (int *)0x0) {
        piVar4 = (int *)0x0;
      }
      else {
        *piVar4 = (int)&PTR_FUN_404020b4;
        piVar4[2] = 0;
        piVar4[3] = 0;
        piVar4[4] = 0;
        piVar4[6] = 0;
        piVar4[7] = 0;
        piVar4[1] = 0;
      }
      if (piVar4 == (int *)0x0) {
        iVar6 = -0x7ffcfff8;
      }
      else {
        iVar6 = *(int *)(param_1 + 8) + DAT_404304bc;
        if (*(int *)(param_1 + 8) == 0) {
          iVar6 = 0;
        }
        iVar5 = *(int *)(param_1 + 4) + DAT_404304bc;
        if (*(int *)(param_1 + 4) == 0) {
          iVar5 = 0;
        }
        iVar6 = FUN_4041bcb8((int)piVar4,iVar5,iVar6,*(undefined4 *)(param_1 + 0xc),1,(int)puVar3);
        if (-1 < iVar6) {
          *(int *)(*(int *)(param_1 + 0xc) + 0x1c) = *(int *)(*(int *)(param_1 + 0xc) + 0x1c) + 1;
          InterlockedIncrement((LONG *)(*(int *)(param_1 + 4) + DAT_404304bc + 0x60));
          *param_2 = piVar4;
          piVar4 = (int *)0x0;
          goto LAB_4041d424;
        }
        FUN_4041c150(piVar4);
        FUN_4040a65c(piVar4);
      }
      FUN_4042cfe8(puVar3);
    }
  }
  else {
    iVar6 = -0x7ffcfefe;
  }
LAB_4041d424:
  iVar5 = __GetUserKData(8);
  if (DAT_40430480 == iVar5) {
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_4043047c);
  }
  if (piVar4 != (int *)0x0) {
    (**(code **)(*piVar4 + 8))(piVar4);
  }
  return iVar6;
}



/* 4041d48c FUN_4041d48c */

/* Boundary evidence: original MIPS .pdata 4041d48c..4041d4d7. Semantic name remains unreviewed. */

int FUN_4041d48c(int param_1,int param_2)

{
  int iVar1;
  
  if ((param_1 == 0) || (*(int *)(param_1 + 0x5c) != 0x49464445)) {
    iVar1 = -0x7ffcfffa;
  }
  else {
    iVar1 = FUN_4042d1f4((int *)(param_1 + 4),param_2);
  }
  return iVar1;
}



/* 4041d4d8 FUN_4041d4d8 */

/* Boundary evidence: original MIPS .pdata 4041d4d8..4041d52f. Semantic name remains unreviewed. */

int FUN_4041d4d8(int param_1)

{
  int iVar1;
  
  if ((param_1 == 0) || (*(int *)(param_1 + 0x5c) != 0x49464445)) {
    iVar1 = -0x7ffcfffa;
  }
  else {
    iVar1 = FUN_4042d39c((int *)(param_1 + 4));
  }
  *(undefined4 *)(param_1 + 0xa4) = 0;
  return iVar1;
}



/* 4041d530 FUN_4041d530 */

/* Boundary evidence: original MIPS .pdata 4041d530..4041d583. Semantic name remains unreviewed. */

LONG FUN_4041d530(int param_1)

{
  LONG LVar1;
  
  if ((param_1 == 0) || (*(int *)(param_1 + 0x5c) != 0x49464445)) {
    LVar1 = 0;
  }
  else {
    InterlockedIncrement((LONG *)(param_1 + 0x58));
    LVar1 = *(LONG *)(param_1 + 0x58);
  }
  return LVar1;
}



/* 4041d584 FUN_4041d584 */

/* Boundary evidence: original MIPS .pdata 4041d584..4041d5db. Semantic name remains unreviewed. */

undefined4 FUN_4041d584(int param_1,int *param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  
  if ((param_1 == 0) || (*(int *)(param_1 + 0x5c) != 0x49464445)) {
    uVar1 = 0x80030006;
  }
  else {
    uVar1 = FUN_4042d0ac((int *)(param_1 + 4),param_2,(int *)&DAT_404022b4,param_1,param_3);
  }
  return uVar1;
}



/* 4041d5dc FUN_4041d5dc */

/* Boundary evidence: original MIPS .pdata 4041d5dc..4041d6e3. Semantic name remains unreviewed. */

undefined4 *
FUN_4041d5dc(undefined4 *param_1,int param_2,void *param_3,int param_4,undefined4 param_5,
            undefined4 param_6)

{
  int iVar1;
  
  *(undefined2 *)(param_1 + 0x12) = 0;
  *param_1 = &PTR_FUN_404020ec;
  *(undefined2 *)(param_1 + 0x28) = 0;
  param_1[0x29] = 0;
  param_1[0x14] = param_5;
  param_1[0x15] = param_6;
  if (param_2 == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = param_2 - DAT_404304bc;
  }
  param_1[1] = iVar1;
  InterlockedIncrement((LONG *)(iVar1 + DAT_404304bc + 0x78));
  if (*(ushort *)((int)param_3 + 0x40) < 0x41) {
    *(ushort *)(param_1 + 0x12) = *(ushort *)((int)param_3 + 0x40);
  }
  else {
    *(undefined2 *)(param_1 + 0x12) = 0x40;
  }
  memcpy(param_1 + 2,param_3,(uint)*(ushort *)(param_1 + 0x12));
  if (param_4 == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = param_4 - DAT_404304bc;
  }
  param_1[0x13] = iVar1;
  InterlockedIncrement((LONG *)(iVar1 + DAT_404304bc + 0x18));
  param_1[0x16] = 1;
  param_1[0x17] = 0x49464445;
  return param_1;
}



/* 4041d6e4 FUN_4041d6e4 */

/* Boundary evidence: original MIPS .pdata 4041d6e4..4041d807. Semantic name remains unreviewed. */

void FUN_4041d6e4(undefined4 *param_1)

{
  int iVar1;
  int iVar2;
  int local_18;
  
  *param_1 = &PTR_FUN_404020ec;
  param_1[0x17] = 0x69466445;
  if (param_1[0x14] != 0) {
    local_18 = FUN_40410db8();
    iVar1 = param_1[0x14];
    iVar2 = param_1[0x13] + DAT_404304bc;
    *(undefined4 *)(iVar2 + 0xc) = *(undefined4 *)(iVar1 + 8);
    *(undefined4 *)(iVar2 + 0x10) = *(undefined4 *)(iVar1 + 0xc);
    *(undefined4 *)(iVar2 + 0x14) = *(undefined4 *)(iVar1 + 0x10);
  }
  if (param_1[1] != 0) {
    FUN_4040e010((int *)(param_1[1] + DAT_404304bc));
  }
  if (param_1[0x13] != 0) {
    FUN_40417ff8((LPVOID)(param_1[0x13] + DAT_404304bc));
  }
  if ((param_1[0x15] == 0) || ((LPVOID)param_1[0x14] == (LPVOID)0x0)) {
    if ((param_1[0x14] != 0) &&
       ((-1 < local_18 && (iVar1 = __GetUserKData(8), DAT_40430480 == iVar1)))) {
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_4043047c);
    }
  }
  else {
    FUN_40405860((LPVOID)param_1[0x14]);
  }
  return;
}



/* 4041d808 FUN_4041d808 */

/* Boundary evidence: original MIPS .pdata 4041d808..4041dbd3. Semantic name remains unreviewed. */

int FUN_4041d808(int param_1,uint param_2,void *param_3,int *param_4)

{
  size_t ucb;
  bool bVar1;
  BOOL BVar2;
  int iVar3;
  undefined3 extraout_var;
  int *piVar4;
  int iVar5;
  size_t _Size;
  int iVar6;
  ushort *_Src;
  void *pvVar7;
  LPVOID local_1a0 [2];
  undefined4 local_198;
  undefined4 local_194;
  undefined4 *local_c8;
  undefined4 *local_c4;
  undefined4 local_c0;
  wchar_t *local_b8 [10];
  undefined4 local_90;
  undefined4 local_8c;
  undefined4 local_74;
  ushort auStack_70 [32];
  ushort local_30;
  uint local_2c;
  
  local_2c = DAT_404303e4;
  local_c8 = &local_198;
  local_c4 = &local_198;
  local_30 = 0;
  local_198 = 0;
  local_194 = 0;
  local_c0 = 0;
  pvVar7 = param_3;
  if (param_4 == (int *)0x0) {
    if (param_2 < 2) goto LAB_4041d8a8;
    iVar6 = -0x7ffcffa9;
LAB_4041db3c:
    if (iVar6 < 0) {
      local_c4 = local_c8;
      local_c0 = 0;
      while (bVar1 = FUN_4042d570((int)&local_198,local_1a0), CONCAT31(extraout_var,bVar1) != 0) {
        CoTaskMemFree(local_1a0[0]);
      }
    }
    else if (param_4 != (int *)0x0) {
      *param_4 = ((int)pvVar7 - (int)param_3) / 0x48;
    }
  }
  else {
    BVar2 = IsBadWritePtr(param_4,4);
    if (BVar2 == 0) {
      *param_4 = 0;
LAB_4041d8a8:
      ucb = param_2 * 0x48;
      BVar2 = IsBadWritePtr(param_3,ucb);
      if (BVar2 == 0) {
        memset(param_3,0,ucb);
        if ((param_1 == 0) || (*(int *)(param_1 + 0x5c) != 0x49464445)) {
          iVar6 = -0x7ffcfffa;
        }
        else {
          iVar6 = FUN_40410db8();
          if (-1 < iVar6) {
            if ((*(uint *)(DAT_404304bc + *(int *)(param_1 + 4) + 8) & 0x20) == 0) {
              iVar3 = *(int *)(param_1 + 0x50);
              iVar5 = *(int *)(param_1 + 0x4c) + DAT_404304bc;
              *(undefined4 *)(iVar5 + 0xc) = *(undefined4 *)(iVar3 + 8);
              _Src = (ushort *)(param_1 + 8);
              *(undefined4 *)(iVar5 + 0x10) = *(undefined4 *)(iVar3 + 0xc);
              iVar6 = 0;
              *(undefined4 *)(iVar5 + 0x14) = *(undefined4 *)(iVar3 + 0x10);
              _Size = (size_t)*(ushort *)(param_1 + 0x48);
              if (0x40 < _Size) {
                _Size = 0x40;
              }
              local_30 = (ushort)_Size;
              memcpy(auStack_70,_Src,_Size);
              if (param_3 < (void *)(ucb + (int)param_3)) {
                do {
                  piVar4 = (int *)(*(int *)(DAT_404304bc + *(int *)(param_1 + 4) + 0x5c) +
                                  DAT_404304bc);
                  iVar6 = (**(code **)(*piVar4 + 0x40))(piVar4,_Src,0,local_b8);
                  if (iVar6 < 0) {
                    if (iVar6 == -0x7ffcffee) {
                      iVar6 = 1;
                    }
                    break;
                  }
                  iVar6 = FUN_4042d4d0((int)&local_198,(int)local_b8[0]);
                  if (iVar6 < 0) {
                    CoTaskMemFree(local_b8[0]);
                    break;
                  }
                  FUN_40410ed4(_Src,local_b8[0]);
                  if (*(int *)(param_1 + 0xa4) == 0) {
                    FUN_40410ed4((ushort *)(param_1 + 0x60),local_b8[0]);
                    *(undefined4 *)(param_1 + 0xa4) = 1;
                  }
                  else {
                    iVar3 = FUN_404197c0((ushort *)(param_1 + 0x60),_Src);
                    if (iVar3 != 0) {
                      iVar6 = -0x7ffcfef7;
                      goto LAB_4041dad4;
                    }
                  }
                  iVar3 = FUN_404197c0(auStack_70,_Src);
                  if (iVar3 != 0) {
                    iVar6 = -0x7ffcfef7;
                    break;
                  }
                  local_90 = 0;
                  local_8c = 0;
                  local_74 = 0;
                  memcpy(pvVar7,local_b8,0x48);
                  pvVar7 = (void *)((int)pvVar7 + 0x48);
                } while (pvVar7 < (void *)(ucb + (int)param_3));
                if (iVar6 < 0) {
LAB_4041dad4:
                  if (local_30 < 0x41) {
                    *(ushort *)(param_1 + 0x48) = local_30;
                  }
                  else {
                    *(undefined2 *)(param_1 + 0x48) = 0x40;
                  }
                  memcpy(_Src,auStack_70,(uint)*(ushort *)(param_1 + 0x48));
                }
              }
            }
            else {
              iVar6 = -0x7ffcfefe;
            }
            iVar3 = __GetUserKData(8);
            if (DAT_40430480 == iVar3) {
              LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_4043047c);
            }
          }
        }
        goto LAB_4041db3c;
      }
    }
    iVar6 = -0x7ffcfff7;
  }
  FUN_4042d488((int)&local_198);
  FUN_4042f4c4(local_2c);
  return iVar6;
}



/* 4041dbd4 FUN_4041dbd4 */

/* Boundary evidence: original MIPS .pdata 4041dbd4..4041ddc7. Semantic name remains unreviewed. */

int FUN_4041dbd4(int param_1,undefined4 *param_2)

{
  BOOL BVar1;
  int iVar2;
  undefined4 *puVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  
  BVar1 = IsBadWritePtr(param_2,4);
  if (BVar1 == 0) {
    *param_2 = 0;
    if ((param_1 == 0) || (*(int *)(param_1 + 0x5c) != 0x49464445)) {
      iVar6 = -0x7ffcfffa;
    }
    else {
      iVar6 = FUN_40410db8();
      if (-1 < iVar6) {
        if ((*(uint *)(*(int *)(param_1 + 4) + DAT_404304bc + 8) & 0x20) == 0) {
          iVar2 = *(int *)(param_1 + 0x50);
          iVar5 = DAT_404304bc + *(int *)(param_1 + 0x4c);
          *(undefined4 *)(iVar5 + 0xc) = *(undefined4 *)(iVar2 + 8);
          *(undefined4 *)(iVar5 + 0x10) = *(undefined4 *)(iVar2 + 0xc);
          iVar6 = 0;
          *(undefined4 *)(iVar5 + 0x14) = *(undefined4 *)(iVar2 + 0x10);
          puVar3 = CoTaskMemAlloc(0xa8);
          if (puVar3 == (undefined4 *)0x0) {
            piVar4 = (int *)0x0;
          }
          else {
            iVar2 = *(int *)(param_1 + 0x4c) + DAT_404304bc;
            if (*(int *)(param_1 + 0x4c) == 0) {
              iVar2 = 0;
            }
            iVar5 = *(int *)(param_1 + 4) + DAT_404304bc;
            if (*(int *)(param_1 + 4) == 0) {
              iVar5 = 0;
            }
            piVar4 = FUN_4041d5dc(puVar3,iVar5,(void *)(param_1 + 8),iVar2,
                                  *(undefined4 *)(param_1 + 0x50),1);
          }
          if (piVar4 == (int *)0x0) {
            iVar6 = -0x7ffcfff8;
          }
          iVar2 = __GetUserKData(8);
          if (DAT_40430480 == iVar2) {
            LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_4043047c);
          }
          if (-1 < iVar6) {
            *param_2 = piVar4;
            piVar4 = (int *)0x0;
            *(int *)(*(int *)(param_1 + 0x50) + 0x1c) =
                 *(int *)(*(int *)(param_1 + 0x50) + 0x1c) + 1;
          }
          if (piVar4 != (int *)0x0) {
            (**(code **)(*piVar4 + 8))(piVar4);
          }
        }
        else {
          iVar6 = -0x7ffcfefe;
          iVar2 = __GetUserKData(8);
          if (DAT_40430480 == iVar2) {
            LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_4043047c);
          }
        }
      }
    }
  }
  else {
    iVar6 = -0x7ffcfff7;
  }
  return iVar6;
}



/* 4041ddc8 FUN_4041ddc8 */

/* Boundary evidence: original MIPS .pdata 4041ddc8..4041de3f. Semantic name remains unreviewed. */

LONG FUN_4041ddc8(undefined4 *param_1)

{
  LONG LVar1;
  
  if ((param_1 == (undefined4 *)0x0) || (param_1[0x17] != 0x49464445)) {
    LVar1 = 0;
  }
  else {
    LVar1 = FUN_4042d028(param_1 + 1);
    if (LVar1 == 0) {
      FUN_4041d6e4(param_1);
      CoTaskMemFree(param_1);
    }
  }
  return LVar1;
}



/* 4041de40 FUN_4041de40 */

/* Boundary evidence: original MIPS .pdata 4041de40..4041dee7. Semantic name remains unreviewed. */

int * FUN_4041de40(int *param_1,uint param_2,undefined4 param_3)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  
  iVar4 = (param_2 % 0x17) * 8;
  piVar2 = (int *)(param_1[1] + iVar4);
  piVar3 = (int *)*piVar2;
  if (piVar3 != piVar2) {
    do {
      iVar1 = (**(code **)(*param_1 + 8))(param_1,param_3,piVar3,param_2);
      if (iVar1 != 0) {
        return piVar3;
      }
      piVar3 = (int *)*piVar3;
    } while (piVar3 != (int *)(param_1[1] + iVar4));
  }
  return (int *)0x0;
}



/* 4041dee8 FUN_4041dee8 */

void FUN_4041dee8(int param_1,uint param_2,int *param_3)

{
  int *piVar1;
  
  piVar1 = (int *)((param_2 % 0x17) * 8 + *(int *)(param_1 + 4));
  param_3[1] = (int)piVar1;
  *(int **)(*piVar1 + 4) = param_3;
  *param_3 = *piVar1;
  *piVar1 = (int)param_3;
  return;
}



/* 4041df1c FUN_4041df1c */

/* Boundary evidence: original MIPS .pdata 4041df1c..4041df77. Semantic name remains unreviewed. */

uint FUN_4041df1c(undefined4 param_1,wchar_t *param_2)

{
  size_t sVar1;
  uint uVar2;
  
  uVar2 = 0;
  for (sVar1 = wcslen(param_2); sVar1 != 0; sVar1 = sVar1 - 1) {
    uVar2 = uVar2 << 8 ^ (uint)(ushort)*param_2;
    param_2 = param_2 + 1;
  }
  return uVar2;
}



/* 4041df78 FUN_4041df78 */

/* Boundary evidence: original MIPS .pdata 4041df78..4041df93. Semantic name remains unreviewed. */

void FUN_4041df78(undefined4 param_1,int param_2)

{
  FUN_4041df1c(param_1,*(wchar_t **)(param_2 + 8));
  return;
}



/* 4041df94 FUN_4041df94 */

/* Boundary evidence: original MIPS .pdata 4041df94..4041dfcf. Semantic name remains unreviewed. */

bool FUN_4041df94(undefined4 param_1,LPCWSTR param_2,int param_3)

{
  int iVar1;
  
  iVar1 = lstrcmpW(param_2,*(LPCWSTR *)(param_3 + 8));
  return iVar1 == 0;
}



/* 4041dfd0 FUN_4041dfd0 */

/* Boundary evidence: original MIPS .pdata 4041dfd0..4041e063. Semantic name remains unreviewed. */

void FUN_4041dfd0(int param_1,undefined *param_2)

{
  int *piVar1;
  int *piVar2;
  uint uVar3;
  
  uVar3 = 0;
  do {
    while ((piVar2 = *(int **)(uVar3 + *(int *)(param_1 + 4)), piVar2 == (int *)0x0 ||
           (piVar1 = (int *)(*(int *)(param_1 + 4) + uVar3), (int *)*piVar1 == piVar1))) {
      uVar3 = uVar3 + 8;
      if (0xb7 < uVar3) {
        return;
      }
    }
    *(int *)piVar2[1] = *piVar2;
    *(int *)(*piVar2 + 4) = piVar2[1];
    (*(code *)param_2)(piVar2);
  } while( true );
}



/* 4041e064 FUN_4041e064 */

void FUN_4041e064(undefined4 *param_1,undefined4 param_2,undefined4 param_3)

{
  param_1[4] = param_2;
  param_1[5] = param_3;
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  return;
}



/* 4041e080 FUN_4041e080 */

/* Boundary evidence: original MIPS .pdata 4041e080..4041e0ef. Semantic name remains unreviewed. */

void FUN_4041e080(undefined4 *param_1)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)param_1[1];
  if (puVar1 != (undefined4 *)0x0) {
    for (; puVar1 < (undefined4 *)param_1[2]; puVar1 = puVar1 + 1) {
      LocalFree((HLOCAL)*puVar1);
    }
    LocalFree((HLOCAL)param_1[1]);
    *param_1 = 0;
    param_1[1] = 0;
    param_1[2] = 0;
    param_1[3] = 0;
  }
  return;
}



/* 4041e0f0 FUN_4041e0f0 */

/* Boundary evidence: original MIPS .pdata 4041e0f0..4041e203. Semantic name remains unreviewed. */

void FUN_4041e0f0(int *param_1)

{
  undefined4 *hMem;
  HLOCAL _Dst;
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  
  iVar3 = param_1[5];
  iVar1 = param_1[4];
  hMem = LocalAlloc(0,iVar3 * iVar1);
  if (hMem != (undefined4 *)0x0) {
    iVar2 = *param_1;
    _Dst = LocalAlloc(0,iVar2 * 4 + 4);
    if (_Dst == (HLOCAL)0x0) {
      LocalFree(hMem);
    }
    else {
      memcpy(_Dst,(void *)param_1[1],iVar2 * 4);
      *(undefined4 **)(*param_1 * 4 + (int)_Dst) = hMem;
      *param_1 = *param_1 + 1;
      LocalFree((HLOCAL)param_1[1]);
      puVar4 = (undefined4 *)((int)hMem + (iVar3 * iVar1 - param_1[4]));
      param_1[1] = (int)_Dst;
      param_1[2] = (int)(*param_1 * 4 + (int)_Dst);
      param_1[3] = (int)hMem;
      while (hMem < puVar4) {
        iVar1 = param_1[4];
        *hMem = (undefined4 *)(iVar1 + (int)hMem);
        hMem = (undefined4 *)(iVar1 + (int)hMem);
      }
      *puVar4 = 0;
    }
  }
  return;
}



/* 4041e204 FUN_4041e204 */

/* Boundary evidence: original MIPS .pdata 4041e204..4041e253. Semantic name remains unreviewed. */

int * FUN_4041e204(int *param_1)

{
  int *piVar1;
  
  piVar1 = (int *)param_1[3];
  if (piVar1 == (int *)0x0) {
    FUN_4041e0f0(param_1);
    piVar1 = (int *)param_1[3];
    if (piVar1 == (int *)0x0) {
      return (int *)0x0;
    }
  }
  param_1[3] = *piVar1;
  return piVar1;
}



/* 4041e254 FUN_4041e254 */

/* Boundary evidence: original MIPS .pdata 4041e254..4041e2cf. Semantic name remains unreviewed. */

undefined4 * FUN_4041e254(undefined4 *param_1,uint param_2,uint param_3)

{
  uint uVar1;
  undefined4 *puVar2;
  uint uBytes;
  
  uVar1 = (uint)((ulonglong)param_2 * (ulonglong)param_3);
  if ((((int)((ulonglong)param_2 * (ulonglong)param_3 >> 0x20) == 0) &&
      (uBytes = uVar1 + 0xc, uVar1 <= uBytes)) &&
     (puVar2 = LocalAlloc(0,uBytes), puVar2 != (undefined4 *)0x0)) {
    puVar2[1] = param_2;
    puVar2[2] = 0;
    *puVar2 = *param_1;
    *param_1 = puVar2;
  }
  else {
    puVar2 = (undefined4 *)0x0;
  }
  return puVar2;
}



/* 4041e2d0 FUN_4041e2d0 */

/* Boundary evidence: original MIPS .pdata 4041e2d0..4041e307. Semantic name remains unreviewed. */

void FUN_4041e2d0(undefined4 *param_1)

{
  undefined4 *puVar1;
  
  while (param_1 != (undefined4 *)0x0) {
    puVar1 = (undefined4 *)*param_1;
    *param_1 = 0;
    LocalFree(param_1);
    param_1 = puVar1;
  }
  return;
}



/* 4041e308 FUN_4041e308 */

bool FUN_4041e308(int param_1)

{
  return *(char *)(param_1 + 0x42) == '\0';
}



/* 4041e320 FUN_4041e320 */

void FUN_4041e320(int param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 0x4c) = param_2;
  return;
}



/* 4041e32c FUN_4041e32c */

void FUN_4041e32c(int param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 0x74) = param_2;
  return;
}



/* 4041e338 FUN_4041e338 */

void FUN_4041e338(int param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 0x78) = param_2;
  return;
}



/* 4041e344 FUN_4041e344 */

void FUN_4041e344(int param_1,undefined1 param_2)

{
  *(undefined1 *)(param_1 + 0x42) = param_2;
  return;
}



/* 4041e34c FUN_4041e34c */

void FUN_4041e34c(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  
  iVar1 = param_2 * 8 + param_1;
  *(undefined4 *)(iVar1 + 100) = param_3;
  *(undefined4 *)(iVar1 + 0x68) = param_4;
  return;
}



/* 4041e368 FUN_4041e368 */

void FUN_4041e368(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,undefined4 param_7)

{
  *(undefined4 *)(param_1 + 0x6c) = param_4;
  *(undefined4 *)(param_1 + 0x70) = param_5;
  *(undefined4 *)(param_1 + 100) = param_6;
  *(undefined4 *)(param_1 + 0x68) = param_7;
  return;
}



/* 4041e398 FUN_4041e398 */

/* Boundary evidence: original MIPS .pdata 4041e398..4041e3e3. Semantic name remains unreviewed. */

void FUN_4041e398(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5)

{
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  uint local_10;
  
  local_10 = DAT_404303e4;
  local_14 = param_5;
  local_20 = param_2;
  local_1c = param_3;
  local_18 = param_4;
  memcpy((void *)(param_1 + 0x50),&local_20,0x10);
  FUN_4042f4c4(local_10);
  return;
}



/* 4041e3e4 FUN_4041e3e4 */

void FUN_4041e3e4(int param_1,uint param_2,uint param_3)

{
  *(uint *)(param_1 + 0x60) = ~param_3 & *(uint *)(param_1 + 0x60) | param_2 & param_3;
  return;
}



/* 4041e40c FUN_4041e40c */

undefined4 FUN_4041e40c(int param_1)

{
  return *(undefined4 *)(param_1 + 0x44);
}



/* 4041e41c FUN_4041e41c */

undefined4 FUN_4041e41c(int param_1)

{
  return *(undefined4 *)(param_1 + 0x48);
}



/* 4041e42c FUN_4041e42c */

undefined1 FUN_4041e42c(int param_1)

{
  return *(undefined1 *)(param_1 + 0x42);
}



/* 4041e438 FUN_4041e438 */

int FUN_4041e438(int param_1,int param_2)

{
  return param_2 * 0x80 + param_1;
}



/* 4041e444 FUN_4041e444 */

int FUN_4041e444(int param_1,int param_2,int param_3)

{
  return (uint)*(ushort *)(param_1 + 0x28) * param_2 + param_3;
}



/* 4041e458 FUN_4041e458 */

undefined4 FUN_4041e458(int param_1,uint param_2,uint *param_3,undefined2 *param_4)

{
  if (*(ushort *)(param_1 + 0x28) == 0) {
    trap(0x1c00);
  }
  *param_3 = param_2 / *(ushort *)(param_1 + 0x28);
  if (*(ushort *)(param_1 + 0x28) == 0) {
    trap(0x1c00);
  }
  *param_4 = (short)(param_2 % (uint)*(ushort *)(param_1 + 0x28));
  return 0;
}



/* 4041e498 FUN_4041e498 */

/* Boundary evidence: original MIPS .pdata 4041e498..4041e4cb. Semantic name remains unreviewed. */

void FUN_4041e498(void *param_1)

{
  memset(param_1,0,0x40);
  *(undefined2 *)((int)param_1 + 0x40) = 0;
  return;
}



/* 4041e4cc FUN_4041e4cc */

undefined4 FUN_4041e4cc(int param_1)

{
  return *(undefined4 *)(param_1 + 0x4c);
}



/* 4041e4d4 FUN_4041e4d4 */

undefined4 FUN_4041e4d4(int param_1)

{
  return *(undefined4 *)(param_1 + 0x3c);
}



/* 4041e4dc FUN_4041e4dc */

undefined4 FUN_4041e4dc(int param_1)

{
  return *(undefined4 *)(param_1 + 0x44);
}



/* 4041e4e4 FUN_4041e4e4 */

void FUN_4041e4e4(int param_1)

{
  *(int *)(param_1 + 0x1c) = *(int *)(param_1 + 0x1c) + -1;
  return;
}



/* 4041e4f4 FUN_4041e4f4 */

undefined4 * FUN_4041e4f4(undefined4 *param_1,undefined4 param_2)

{
  *param_1 = 0;
  param_1[1] = param_2;
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[6] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  return param_1;
}



/* 4041e518 FUN_4041e518 */

/* Boundary evidence: original MIPS .pdata 4041e518..4041e537. Semantic name remains unreviewed. */

void FUN_4041e518(int *param_1,uint param_2,uint param_3,int *param_4)

{
  FUN_40424e98(param_1,param_2,param_3,0xfffffffe,param_4);
  return;
}



/* 4041e538 FUN_4041e538 */

/* Boundary evidence: original MIPS .pdata 4041e538..4041e553. Semantic name remains unreviewed. */

void FUN_4041e538(void *param_1)

{
  FUN_40419804(param_1);
  return;
}



/* 4041e554 FUN_4041e554 */

void FUN_4041e554(int param_1,undefined2 param_2)

{
  *(undefined2 *)(param_1 + 0x1c) = param_2;
  return;
}



/* 4041e55c FUN_4041e55c */

/* Boundary evidence: original MIPS .pdata 4041e55c..4041e5bf. Semantic name remains unreviewed. */

void FUN_4041e55c(int *param_1,int param_2)

{
  int iVar1;
  
  if ((param_1[5] == 0) || (iVar1 = *(int *)(param_2 * 4 + param_1[5] + DAT_404304bc), iVar1 == 0))
  {
    FUN_40421540((int *)(*param_1 + DAT_404304bc),(int)param_1,param_1[1],param_2);
  }
  else {
    FUN_4041e4e4(iVar1 + DAT_404304bc);
  }
  return;
}



/* 4041e5c0 FUN_4041e5c0 */

/* Boundary evidence: original MIPS .pdata 4041e5c0..4041e673. Semantic name remains unreviewed. */

void FUN_4041e5c0(int *param_1,int param_2,uint param_3)

{
  int iVar1;
  int *local_18 [2];
  
  if (param_1[5] == 0) {
    iVar1 = FUN_4042121c((int *)(*param_1 + DAT_404304bc),(int)param_1,param_1[1],param_2,local_18);
    if (iVar1 < 0) {
      return;
    }
    iVar1 = *param_1 + DAT_404304bc;
  }
  else {
    iVar1 = *(int *)(param_2 * 4 + param_1[5] + DAT_404304bc);
    local_18[0] = (int *)(iVar1 + DAT_404304bc);
    if (iVar1 == 0) {
      local_18[0] = (int *)0x0;
    }
    iVar1 = *param_1 + DAT_404304bc;
  }
  FUN_404204d8(iVar1,local_18[0],param_3);
  return;
}



/* 4041e674 FUN_4041e674 */

/* Boundary evidence: original MIPS .pdata 4041e674..4041e707. Semantic name remains unreviewed. */

undefined4 FUN_4041e674(int param_1,int param_2)

{
  undefined4 local_10;
  
  if (param_2 == -5) {
    local_10 = FUN_4041e4dc(param_1 + 4);
  }
  else if (param_2 == -4) {
    local_10 = FUN_4041e4d4(param_1 + 4);
  }
  else if (param_2 == -3) {
    local_10 = FUN_404055e4(param_1 + 4);
  }
  else if (param_2 == -2) {
    local_10 = FUN_4041e4cc(param_1 + 4);
  }
  return local_10;
}



/* 4041e708 FUN_4041e708 */

/* Boundary evidence: original MIPS .pdata 4041e708..4041e99f. Semantic name remains unreviewed. */

int FUN_4041e708(int param_1,uint param_2,uint param_3,uint *param_4)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  uint local_40;
  int local_3c;
  uint uStack_38;
  uint uStack_34;
  uint uStack_30;
  uint uStack_2c;
  
  iVar2 = 0;
  if (((*(int *)(param_1 + 0x490) == 0) || (*(int *)(param_1 + 0x488) != 0)) ||
     (param_2 < 0xfffffffc)) {
LAB_4041e8e0:
    if (param_2 == 0xfffffffb) {
      iVar2 = FUN_40425720((int *)(param_1 + 0x28c),param_3,&local_40);
    }
    else {
      if (param_2 < 0xfffffffc) goto LAB_4041e964;
      if (0xfffffffd < param_2) {
        if (param_2 != 0xfffffffe) goto LAB_4041e964;
        goto LAB_4041e910;
      }
      iVar2 = param_1 + 0x36c;
      if (param_2 != 0xfffffffd) {
        iVar2 = param_1 + 0x3ec;
      }
      iVar2 = FUN_404273b4(iVar2,param_3,(int *)&local_40);
    }
  }
  else {
    if (param_2 < 0xfffffffe) {
      iVar3 = param_1 + 0x36c;
      if (param_2 != 0xfffffffd) {
        iVar3 = param_1 + 0x3ec;
      }
      if (param_3 == 0) {
        local_40 = FUN_4041e674(param_1,param_2);
        iVar2 = FUN_40423fe0((int *)(param_1 + 0x23c),local_40,0,1,&uStack_2c,&uStack_30,&uStack_34,
                             &uStack_38);
      }
      else {
        uVar1 = FUN_40427164(iVar3,param_3 - 1,&local_40);
        if ((int)uVar1 < 0) {
          return uVar1;
        }
        iVar2 = FUN_40423fe0((int *)(param_1 + 0x23c),local_40,1,1,&uStack_2c,&uStack_30,&uStack_34,
                             &uStack_38);
      }
      if (iVar2 < 0) {
        return iVar2;
      }
      if (iVar2 != 1) {
        FUN_404276f8(iVar3,param_3,param_3 + 1);
      }
      goto LAB_4041e8e0;
    }
    if (param_2 != 0xfffffffe) goto LAB_4041e8e0;
    iVar2 = FUN_40426b00((int *)(param_1 + 0x28c),param_3,&local_3c);
    if (iVar2 < 0) {
      return iVar2;
    }
    if (local_3c != -2) {
      if (*(int *)(param_1 + 0x470) == 0) {
        iVar2 = 0;
      }
      else {
        iVar2 = *(int *)(param_1 + 0x470) + DAT_404304bc;
      }
      iVar2 = FUN_404261cc((int *)(param_1 + 0x28c),iVar2);
      if (iVar2 < 0) {
        return iVar2;
      }
    }
LAB_4041e910:
    iVar2 = FUN_40425648((int *)(param_1 + 0x28c),param_3,&local_40);
  }
  if (iVar2 < 0) {
    return iVar2;
  }
LAB_4041e964:
  *param_4 = local_40;
  return iVar2;
}



/* 4041e9a0 FUN_4041e9a0 */

/* Boundary evidence: original MIPS .pdata 4041e9a0..4041e9df. Semantic name remains unreviewed. */

void FUN_4041e9a0(int param_1,uint param_2,uint param_3)

{
  int *piVar1;
  
  if ((*(int *)(param_1 + 0x478) == 0) && (param_3 < 0x1000)) {
    piVar1 = (int *)(param_1 + 0x31c);
  }
  else {
    piVar1 = (int *)(param_1 + 0x23c);
  }
  FUN_404225f0(piVar1,param_2,0);
  return;
}



/* 4041e9e0 FUN_4041e9e0 */

/* Boundary evidence: original MIPS .pdata 4041e9e0..4041ea17. Semantic name remains unreviewed. */

void FUN_4041e9e0(int *param_1)

{
  FUN_40424950(param_1);
  param_1[9] = 0;
  param_1[8] = 0;
  *(undefined2 *)(param_1 + 10) = 0;
  param_1[0xb] = 0;
  return;
}



/* 4041ea18 FUN_4041ea18 */

/* Boundary evidence: original MIPS .pdata 4041ea18..4041ea8f. Semantic name remains unreviewed. */

void FUN_4041ea18(int *param_1,int param_2)

{
  undefined2 uVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_2 + 0x24);
  param_1[9] = iVar2;
  *(undefined2 *)(param_1 + 10) = *(undefined2 *)(param_2 + 0x28);
  uVar1 = FUN_4040d6bc(iVar2 + DAT_404304bc);
  FUN_4041e554((int)param_1,uVar1);
  FUN_404252fc(param_1,param_2);
  param_1[8] = *(int *)(param_2 + 0x20);
  param_1[0xb] = *(int *)(param_2 + 0x2c);
  return;
}



/* 4041ea90 FUN_4041ea90 */

/* Boundary evidence: original MIPS .pdata 4041ea90..4041eb23. Semantic name remains unreviewed. */

void FUN_4041ea90(int *param_1,int param_2,uint param_3)

{
  undefined2 uVar1;
  undefined2 extraout_var;
  int iVar2;
  
  if (param_2 == 0) {
    iVar2 = 0;
  }
  else {
    iVar2 = param_2 - DAT_404304bc;
  }
  param_1[9] = iVar2;
  uVar1 = FUN_4040d6bc(param_2);
  *(short *)(param_1 + 10) = (short)(CONCAT22(extraout_var,uVar1) >> 7);
  uVar1 = FUN_4040d6bc(param_2);
  FUN_4041e554((int)param_1,uVar1);
  iVar2 = FUN_40424d38(param_1,param_2,param_3);
  if (-1 < iVar2) {
    param_1[8] = param_3;
  }
  return;
}



/* 4041eb24 FUN_4041eb24 */

/* Boundary evidence: original MIPS .pdata 4041eb24..4041eb57. Semantic name remains unreviewed. */

void FUN_4041eb24(int *param_1,uint param_2)

{
  if (*(ushort *)(param_1 + 10) == 0) {
    trap(0x1c00);
  }
  FUN_4041e55c(param_1,param_2 / *(ushort *)(param_1 + 10));
  return;
}



/* 4041eb58 FUN_4041eb58 */

/* Boundary evidence: original MIPS .pdata 4041eb58..4041ec47. Semantic name remains unreviewed. */

void FUN_4041eb58(void *param_1,undefined1 param_2)

{
  byte bVar1;
  
  memset(param_1,0,0x80);
  *(undefined1 *)((int)param_1 + 0x42) = param_2;
  *(undefined1 *)((int)param_1 + 0x43) = 0;
  FUN_4040d674(param_1,0,(void *)0x0);
  *(undefined4 *)((int)param_1 + 0x4c) = 0xffffffff;
  *(undefined4 *)((int)param_1 + 0x48) = 0xffffffff;
  *(undefined4 *)((int)param_1 + 0x44) = 0xffffffff;
  bVar1 = *(byte *)((int)param_1 + 0x42);
  if (((bVar1 & 3) == 1) || (bVar1 == 5)) {
    memcpy((void *)((int)param_1 + 0x50),&DAT_404021a4,0x10);
    *(undefined4 *)((int)param_1 + 0x60) = 0;
  }
  if (((bVar1 & 3) == 2) || (bVar1 == 5)) {
    *(undefined4 *)((int)param_1 + 0x74) = 0xfffffffe;
    *(undefined4 *)((int)param_1 + 0x78) = 0;
  }
  return;
}



/* 4041ec48 FUN_4041ec48 */

/* Boundary evidence: original MIPS .pdata 4041ec48..4041ec9f. Semantic name remains unreviewed. */

void FUN_4041ec48(void *param_1,int param_2)

{
  undefined2 uVar1;
  void *pvVar2;
  undefined2 extraout_var;
  
  pvVar2 = (void *)FUN_4040d1f4(param_2);
  uVar1 = FUN_4040d1ec(param_2);
  FUN_4040d674(param_1,CONCAT22(extraout_var,uVar1),pvVar2);
  return;
}



/* 4041eca0 FUN_4041eca0 */

/* Boundary evidence: original MIPS .pdata 4041eca0..4041ecbb. Semantic name remains unreviewed. */

void FUN_4041eca0(void *param_1)

{
  FUN_4041e498(param_1);
  return;
}



/* 4041ecbc FUN_4041ecbc */

/* Boundary evidence: original MIPS .pdata 4041ecbc..4041ecef. Semantic name remains unreviewed. */

undefined4 * FUN_4041ecbc(undefined4 *param_1)

{
  FUN_4041e4f4(param_1,0xfffffffd);
  *(undefined2 *)(param_1 + 7) = 0;
  return param_1;
}



/* 4041ecf0 FUN_4041ecf0 */

/* Boundary evidence: original MIPS .pdata 4041ecf0..4041ed5f. Semantic name remains unreviewed. */

undefined4 FUN_4041ecf0(void *param_1,uint param_2)

{
  uint uVar1;
  
  memset(param_1,0,param_2);
  for (uVar1 = param_2 >> 7 & 0xffff; uVar1 != 0; uVar1 = uVar1 - 1) {
    FUN_4041eb58(param_1,0);
    param_1 = (void *)((int)param_1 + 0x80);
  }
  return 0;
}



/* 4041ed60 FUN_4041ed60 */

/* Boundary evidence: original MIPS .pdata 4041ed60..4041ed9b. Semantic name remains unreviewed. */

undefined4 * FUN_4041ed60(undefined4 *param_1)

{
  FUN_4041ecbc(param_1);
  param_1[9] = 0;
  *(undefined2 *)(param_1 + 10) = 0;
  param_1[8] = 0;
  param_1[0xb] = 0;
  return param_1;
}



/* 4041ed9c FUN_4041ed9c */

/* Boundary evidence: original MIPS .pdata 4041ed9c..4041edff. Semantic name remains unreviewed. */

int FUN_4041ed9c(int *param_1,uint param_2,uint param_3,int *param_4)

{
  int iVar1;
  
  iVar1 = FUN_4041e518(param_1,param_2,param_3,param_4);
  if (iVar1 == 0x302ff) {
    FUN_4041ecf0((void *)*param_4,(uint)*(ushort *)(param_1 + 7));
  }
  return iVar1;
}



/* 4041ee00 FUN_4041ee00 */

/* Boundary evidence: original MIPS .pdata 4041ee00..4041ef6b. Semantic name remains unreviewed. */

int FUN_4041ee00(int *param_1,uint param_2)

{
  int iVar1;
  uint uVar2;
  uint local_20;
  int iStack_1c;
  
  if (param_2 == param_1[8]) {
    iVar1 = 0;
  }
  else {
    if (*(ushort *)(param_1 + 10) == 0) {
      trap(0x1c00);
    }
    if (0xfffffffa / *(ushort *)(param_1 + 10) < param_2) {
      iVar1 = -0x7ffcfeef;
    }
    else if (param_2 == 0) {
      iVar1 = -0x7ffcffa9;
    }
    else {
      iVar1 = FUN_4041e708(param_1[9] + DAT_404304bc,0xfffffffd,param_2 - 1,&local_20);
      if ((-1 < iVar1) && (iVar1 = FUN_40424a24((int)param_1,param_2), -1 < iVar1)) {
        for (uVar2 = param_1[8]; uVar2 < param_2; uVar2 = uVar2 + 1) {
          iVar1 = FUN_4041ed9c(param_1,uVar2,2,&iStack_1c);
          if (iVar1 < 0) {
            return iVar1;
          }
          iVar1 = FUN_4041e708(param_1[9] + DAT_404304bc,0xfffffffd,uVar2,&local_20);
          if (iVar1 < 0) {
            return iVar1;
          }
          FUN_4041e5c0(param_1,uVar2,local_20);
          FUN_4041e55c(param_1,uVar2);
        }
        param_1[8] = param_2;
      }
    }
  }
  return iVar1;
}



/* 4041ef6c FUN_4041ef6c */

/* Boundary evidence: original MIPS .pdata 4041ef6c..4041f007. Semantic name remains unreviewed. */

int FUN_4041ef6c(int param_1,uint param_2,uint param_3,int *param_4)

{
  int iVar1;
  int iVar2;
  int local_20 [2];
  
  if (*(ushort *)(param_1 + 0x28) == 0) {
    trap(0x1c00);
  }
  iVar1 = FUN_4041ed9c((int *)param_1,param_2 / *(ushort *)(param_1 + 0x28),param_3,local_20);
  if (-1 < iVar1) {
    if (*(ushort *)(param_1 + 0x28) == 0) {
      trap(0x1c00);
    }
    iVar2 = FUN_4041e438(local_20[0],param_2 % (uint)*(ushort *)(param_1 + 0x28));
    *param_4 = iVar2;
  }
  return iVar1;
}



/* 4041f008 FUN_4041f008 */

/* Boundary evidence: original MIPS .pdata 4041f008..4041f147. Semantic name remains unreviewed. */

int FUN_4041f008(int *param_1,int *param_2)

{
  uint uVar1;
  bool bVar2;
  undefined3 extraout_var;
  int iVar3;
  uint uVar4;
  uint uVar5;
  ushort local_28 [2];
  uint local_24;
  
  FUN_4041e458((int)param_1,param_1[0xb],&local_24,local_28);
  uVar5 = (uint)local_28[0];
  uVar4 = local_24;
  do {
    for (; uVar4 < (uint)param_1[8]; uVar4 = uVar4 + 1) {
      iVar3 = FUN_4041ed9c(param_1,uVar4,0,(int *)&local_24);
      uVar1 = local_24;
      if (iVar3 < 0) {
        return iVar3;
      }
      if (uVar5 < *(ushort *)(param_1 + 10)) {
        do {
          iVar3 = FUN_4041e438(uVar1,uVar5);
          bVar2 = FUN_4041e308(iVar3);
          if (CONCAT31(extraout_var,bVar2) != 0) {
            iVar3 = FUN_4041e444((int)param_1,uVar4,uVar5);
            *param_2 = iVar3;
            param_1[0xb] = iVar3 + 1;
            FUN_4041e55c(param_1,uVar4);
            return 0;
          }
          uVar5 = uVar5 + 1 & 0xffff;
        } while (uVar5 < *(ushort *)(param_1 + 10));
      }
      FUN_4041e55c(param_1,uVar4);
      uVar5 = 0;
    }
    iVar3 = FUN_4041ee00(param_1,param_1[8] + 1);
  } while (-1 < iVar3);
  return iVar3;
}



/* 4041f148 FUN_4041f148 */

/* Boundary evidence: original MIPS .pdata 4041f148..4041f3b3. Semantic name remains unreviewed. */

int FUN_4041f148(int *param_1,uint param_2,int param_3,uint *param_4)

{
  ushort uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int local_30 [2];
  
  iVar4 = param_1[8];
  uVar1 = *(ushort *)(param_1 + 10);
  uVar5 = *param_4;
  *param_4 = uVar5 + 1;
  if ((iVar4 + 1) * (uint)uVar1 < uVar5) {
    return -0x7ffcfef7;
  }
  iVar2 = FUN_4041ef6c((int)param_1,param_2,0,local_30);
  iVar4 = local_30[0];
  if (iVar2 < 0) {
    return iVar2;
  }
  iVar2 = FUN_4040d1f4(local_30[0]);
  iVar3 = FUN_4042aec0(param_3,iVar2);
  if (iVar3 < 0) {
    uVar5 = FUN_4041e40c(iVar4);
    if (uVar5 != 0xffffffff) {
      iVar4 = FUN_4041ef6c((int)param_1,uVar5,0,local_30);
      if (iVar4 < 0) {
LAB_4041f2ec:
        FUN_4041eb24(param_1,param_2);
        return iVar4;
      }
      iVar4 = FUN_4040d1f4(local_30[0]);
      iVar4 = FUN_4042aec0(iVar4,iVar2);
      FUN_4041eb24(param_1,uVar5);
      if (-1 < iVar4) {
LAB_4041f32c:
        FUN_4041eb24(param_1,param_2);
        return -0x7ffcfef7;
      }
    }
    FUN_4041eb24(param_1,param_2);
    if (uVar5 != param_2) {
      if ((uVar5 != 0xffffffff) &&
         (iVar4 = FUN_4041f148(param_1,uVar5,param_3,param_4), iVar4 != -0x7ffcffee)) {
        return iVar4;
      }
      *param_4 = param_2;
      return 0;
    }
  }
  else {
    uVar5 = FUN_4041e41c(iVar4);
    if (uVar5 != 0xffffffff) {
      iVar4 = FUN_4041ef6c((int)param_1,uVar5,0,local_30);
      if (iVar4 < 0) goto LAB_4041f2ec;
      iVar4 = FUN_4040d1f4(local_30[0]);
      iVar4 = FUN_4042aec0(iVar4,iVar2);
      FUN_4041eb24(param_1,uVar5);
      if (iVar4 < 1) goto LAB_4041f32c;
    }
    FUN_4041eb24(param_1,param_2);
    if (uVar5 != param_2) {
      if (uVar5 != 0xffffffff) {
        iVar4 = FUN_4041f148(param_1,uVar5,param_3,param_4);
        return iVar4;
      }
      return -0x7ffcffee;
    }
  }
  return -0x7ffcfff7;
}



/* 4041f3b4 FUN_4041f3b4 */

/* Boundary evidence: original MIPS .pdata 4041f3b4..4041f42f. Semantic name remains unreviewed. */

int FUN_4041f3b4(int *param_1,uint param_2,undefined4 param_3)

{
  int iVar1;
  int local_20 [2];
  
  iVar1 = FUN_4041ef6c((int)param_1,param_2,1,local_20);
  if (-1 < iVar1) {
    FUN_4041e32c(local_20[0],param_3);
    FUN_4041eb24(param_1,param_2);
  }
  return iVar1;
}



/* 4041f430 FUN_4041f430 */

/* Boundary evidence: original MIPS .pdata 4041f430..4041f4ab. Semantic name remains unreviewed. */

int FUN_4041f430(int *param_1,uint param_2,undefined4 param_3)

{
  int iVar1;
  int local_20 [2];
  
  iVar1 = FUN_4041ef6c((int)param_1,param_2,1,local_20);
  if (-1 < iVar1) {
    FUN_4041e338(local_20[0],param_3);
    FUN_4041eb24(param_1,param_2);
  }
  return iVar1;
}



/* 4041f4ac FUN_4041f4ac */

/* Boundary evidence: original MIPS .pdata 4041f4ac..4041f54b. Semantic name remains unreviewed. */

int FUN_4041f4ac(int *param_1,uint param_2,int param_3,undefined4 param_4,undefined4 param_5)

{
  int iVar1;
  int local_20 [2];
  
  if (param_3 == 2) {
    iVar1 = 0;
  }
  else {
    iVar1 = FUN_4041ef6c((int)param_1,param_2,1,local_20);
    if (-1 < iVar1) {
      FUN_4041e34c(local_20[0],param_3,param_4,param_5);
      FUN_4041eb24(param_1,param_2);
    }
  }
  return iVar1;
}



/* 4041f54c FUN_4041f54c */

/* Boundary evidence: original MIPS .pdata 4041f54c..4041f5f3. Semantic name remains unreviewed. */

int FUN_4041f54c(int *param_1,uint param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,
                undefined4 param_6,undefined4 param_7,undefined4 param_8)

{
  int iVar1;
  int local_20 [2];
  
  iVar1 = FUN_4041ef6c((int)param_1,param_2,1,local_20);
  if (-1 < iVar1) {
    FUN_4041e368(local_20[0],param_3,param_4,param_5,param_6,param_7,param_8);
    FUN_4041eb24(param_1,param_2);
  }
  return iVar1;
}



/* 4041f5f4 FUN_4041f5f4 */

/* Boundary evidence: original MIPS .pdata 4041f5f4..4041f6b3. Semantic name remains unreviewed. */

int FUN_4041f5f4(int *param_1,uint param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,
                undefined4 param_6)

{
  int iVar1;
  int local_28;
  uint local_24;
  
  local_24 = DAT_404303e4;
  iVar1 = FUN_4041ef6c((int)param_1,param_2,1,&local_28);
  if (-1 < iVar1) {
    FUN_4041e398(local_28,param_3,param_4,param_5,param_6);
    FUN_4041eb24(param_1,param_2);
  }
  FUN_4042f4c4(local_24);
  return iVar1;
}



/* 4041f6b4 FUN_4041f6b4 */

/* Boundary evidence: original MIPS .pdata 4041f6b4..4041f73f. Semantic name remains unreviewed. */

int FUN_4041f6b4(int *param_1,uint param_2,uint param_3,uint param_4)

{
  int iVar1;
  int local_20 [2];
  
  iVar1 = FUN_4041ef6c((int)param_1,param_2,1,local_20);
  if (-1 < iVar1) {
    FUN_4041e3e4(local_20[0],param_3,param_4);
    FUN_4041eb24(param_1,param_2);
  }
  return iVar1;
}



/* 4041f740 FUN_4041f740 */

/* Boundary evidence: original MIPS .pdata 4041f740..4041f8bb. Semantic name remains unreviewed. */

int FUN_4041f740(int *param_1,int param_2)

{
  void *pvVar1;
  undefined2 uVar2;
  undefined2 extraout_var;
  uint uVar3;
  int iVar4;
  void *local_68;
  int iStack_64;
  undefined1 auStack_60 [68];
  uint local_1c;
  
  local_1c = DAT_404303e4;
  FUN_40410f4c(auStack_60,L"Root Entry");
  if (param_2 == 0) {
    iVar4 = 0;
  }
  else {
    iVar4 = param_2 - DAT_404304bc;
  }
  param_1[9] = iVar4;
  uVar2 = FUN_4040d6bc(param_2);
  *(short *)(param_1 + 10) = (short)(CONCAT22(extraout_var,uVar2) >> 7);
  uVar2 = FUN_4040d6bc(param_2);
  FUN_4041e554((int)param_1,uVar2);
  iVar4 = FUN_40424d38(param_1,param_2,1);
  if ((-1 < iVar4) && (iVar4 = FUN_4041ed9c(param_1,0,2,&iStack_64), -1 < iVar4)) {
    iVar4 = FUN_404156d0(param_2);
    uVar3 = FUN_404055e4(iVar4);
    FUN_4041e5c0(param_1,0,uVar3);
    FUN_4041e55c(param_1,0);
    param_1[8] = 1;
    iVar4 = FUN_4041f008(param_1,(int *)&local_68);
    pvVar1 = local_68;
    if (-1 < iVar4) {
      iVar4 = FUN_4041ef6c((int)param_1,(uint)local_68,1,(int *)&local_68);
      if (-1 < iVar4) {
        FUN_4041eb58(local_68,5);
        FUN_4041ec48(local_68,(int)auStack_60);
        FUN_4041eb24(param_1,(uint)pvVar1);
      }
    }
  }
  FUN_4042f4c4(local_1c);
  return iVar4;
}



/* 4041f8bc FUN_4041f8bc */

/* Boundary evidence: original MIPS .pdata 4041f8bc..4041fa73. Semantic name remains unreviewed. */

int FUN_4041f8bc(int *param_1,uint param_2,int param_3,uint param_4,uint *param_5)

{
  void *pvVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  void *local_38 [2];
  _FILETIME local_30;
  
  iVar2 = FUN_4041f008(param_1,(int *)param_5);
  if (-1 < iVar2) {
    uVar4 = *param_5;
    iVar2 = FUN_4041ef6c((int)param_1,uVar4,1,(int *)local_38);
    pvVar1 = local_38[0];
    if (-1 < iVar2) {
      FUN_4041eb58(local_38[0],(char)param_4);
      if (((param_4 & 3) == 1) || (param_4 == 5)) {
        iVar2 = FUN_40419894(&local_30);
        if (iVar2 < 0) {
          FUN_4041eb24(param_1,uVar4);
          return iVar2;
        }
      }
      else {
        local_30.dwHighDateTime = 0;
        local_30.dwLowDateTime = 0;
      }
      FUN_4041e34c((int)pvVar1,0,local_30.dwLowDateTime,local_30.dwHighDateTime);
      FUN_4041e34c((int)pvVar1,1,local_30.dwLowDateTime,local_30.dwHighDateTime);
      FUN_4041ec48(pvVar1,param_3);
      FUN_4041eb24(param_1,uVar4);
      iVar2 = FUN_4042b8e4(param_1,param_2,uVar4,param_3);
      if ((iVar2 < 0) && (iVar3 = FUN_4041ef6c((int)param_1,uVar4,1,(int *)local_38), -1 < iVar3)) {
        FUN_4041e344((int)local_38[0],0);
        FUN_4041eb24(param_1,uVar4);
        if (uVar4 < (uint)param_1[0xb]) {
          param_1[0xb] = uVar4;
        }
      }
    }
  }
  return iVar2;
}



/* 4041fa74 FUN_4041fa74 */

/* Boundary evidence: original MIPS .pdata 4041fa74..4041fb5b. Semantic name remains unreviewed. */

int FUN_4041fa74(int *param_1,uint param_2,int param_3,int param_4)

{
  int iVar1;
  void *local_40 [2];
  undefined4 auStack_38 [2];
  uint local_30;
  undefined4 auStack_28 [4];
  
  iVar1 = FUN_4041a010(param_1,param_2,param_4,auStack_28);
  if (iVar1 == -0x7ffcfffe) {
    iVar1 = FUN_4042b1f4(param_1,param_2,param_3,1,auStack_38);
    if ((-1 < iVar1) && (iVar1 = FUN_4041ef6c((int)param_1,local_30,1,(int *)local_40), -1 < iVar1))
    {
      FUN_4041ec48(local_40[0],param_4);
      FUN_4041eb24(param_1,local_30);
      iVar1 = FUN_4042b8e4(param_1,param_2,local_30,param_4);
    }
  }
  else if (-1 < iVar1) {
    iVar1 = -0x7ffcfffb;
  }
  return iVar1;
}



/* 4041fb5c FUN_4041fb5c */

/* Boundary evidence: original MIPS .pdata 4041fb5c..4041fcc3. Semantic name remains unreviewed. */

int FUN_4041fb5c(int *param_1,uint param_2,uint param_3)

{
  ushort uVar1;
  int iVar2;
  uint uVar3;
  void *pvVar4;
  int iVar5;
  uint uVar6;
  int local_78;
  int local_74;
  undefined1 auStack_70 [68];
  uint local_2c;
  
  local_2c = DAT_404303e4;
  uVar1 = *(ushort *)(param_1 + 10);
  iVar5 = param_1[8];
  uVar6 = 0;
  FUN_4040d4cc((int)auStack_70);
  do {
    if ((uint)uVar1 * iVar5 < param_3) break;
    iVar2 = FUN_4041ef6c((int)param_1,param_2,0,&local_74);
    if (iVar2 < 0) goto LAB_4041fc8c;
    uVar3 = FUN_4041aa6c(local_74);
    FUN_4041eb24(param_1,param_2);
    if ((uVar3 == 0xffffffff) || (iVar2 = FUN_4041ef6c((int)param_1,uVar3,0,&local_78), iVar2 < 0))
    goto LAB_4041fc8c;
    pvVar4 = (void *)FUN_4040d1f4(local_78);
    FUN_40410c64(auStack_70,pvVar4);
    FUN_4041eb24(param_1,uVar3);
    iVar2 = FUN_4041fcc4(param_1,param_2,(int)auStack_70,param_3 + 1);
    if (iVar2 < 0) goto LAB_4041fc8c;
    uVar6 = uVar6 + 1;
    FUN_4040d4cc((int)auStack_70);
  } while (uVar6 <= (uint)uVar1 * iVar5);
  iVar2 = -0x7ffcfef7;
LAB_4041fc8c:
  FUN_4042f4c4(local_2c);
  return iVar2;
}



/* 4041fcc4 FUN_4041fcc4 */

/* Boundary evidence: original MIPS .pdata 4041fcc4..4041fe63. Semantic name remains unreviewed. */

int FUN_4041fcc4(int *param_1,uint param_2,int param_3,uint param_4)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  void *local_38 [2];
  undefined4 uStack_30;
  uint local_2c;
  uint local_28;
  
  iVar1 = FUN_4042b1f4(param_1,param_2,param_3,0,&uStack_30);
  if (iVar1 < 0) {
    return iVar1;
  }
  if ((((local_2c & 3) == 1) || (local_2c == 5)) &&
     (iVar1 = FUN_4041fb5c(param_1,local_28,param_4), iVar1 < 0)) {
    return iVar1;
  }
  iVar1 = FUN_4041ef6c((int)param_1,local_28,1,(int *)local_38);
  if (iVar1 < 0) {
    return iVar1;
  }
  if (((local_2c & 3) == 2) || (local_2c == 5)) {
    uVar2 = FUN_40415260((int)local_38[0]);
    FUN_4041e32c((int)local_38[0],0xfffffffe);
    uVar3 = FUN_40415270((int)local_38[0]);
    iVar1 = FUN_4041e9a0(param_1[9] + DAT_404304bc,uVar2,uVar3);
    if (iVar1 < 0) goto LAB_4041fe34;
  }
  iVar1 = FUN_4042b1f4(param_1,param_2,param_3,1,&uStack_30);
  if (-1 < iVar1) {
    FUN_4041e344((int)local_38[0],0);
    FUN_4041eca0(local_38[0]);
    if (local_28 < (uint)param_1[0xb]) {
      param_1[0xb] = local_28;
    }
  }
LAB_4041fe34:
  FUN_4041eb24(param_1,local_28);
  return iVar1;
}



/* 4041fe64 FUN_4041fe64 */

/* Boundary evidence: original MIPS .pdata 4041fe64..404200b7. Semantic name remains unreviewed. */

int FUN_4041fe64(int *param_1,uint param_2,void *param_3,int *param_4)

{
  void *pvVar1;
  undefined1 uVar2;
  ushort uVar3;
  int iVar4;
  void *pvVar5;
  STRSAFE_PCNZWCH psz;
  HRESULT HVar6;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  undefined3 extraout_var_01;
  undefined3 extraout_var_02;
  int iVar7;
  int *piVar8;
  void *local_40 [4];
  size_t local_30 [2];
  
  local_40[0] = (void *)0x0;
  local_30[0] = 0;
  iVar4 = FUN_4041ef6c((int)param_1,param_2,0,(int *)local_40);
  pvVar1 = local_40[0];
  if (iVar4 < 0) {
    return iVar4;
  }
  pvVar5 = (void *)FUN_4040d1f4(local_40[0]);
  uVar3 = FUN_4040d1ec((int)pvVar5);
  if (uVar3 < 0x41) {
    psz = (STRSAFE_PCNZWCH)FUN_4040d1f4(pvVar5);
    HVar6 = StringCbLengthW(psz,0x40,local_30);
    if (((-1 < HVar6) && ((int)(short)uVar3 == local_30[0] + 2)) &&
       ((uVar2 = FUN_4041e42c((int)pvVar1), CONCAT31(extraout_var,uVar2) == 1 ||
        (uVar2 = FUN_4041e42c((int)pvVar1), CONCAT31(extraout_var_00,uVar2) == 2)))) {
      if (param_3 == (void *)0x0) {
        uVar2 = FUN_4041e42c((int)pvVar1);
        param_4[1] = CONCAT31(extraout_var_02,uVar2);
        iVar7 = FUN_4041e538(pvVar1);
        *param_4 = iVar7;
        if (iVar7 == 0) {
          iVar4 = -0x7ffcfff8;
        }
        else {
          piVar8 = FUN_40415280((int)pvVar1,local_40,0);
          param_4[6] = *piVar8;
          param_4[7] = piVar8[1];
          piVar8 = FUN_40415280((int)pvVar1,local_40,1);
          param_4[4] = *piVar8;
          param_4[5] = piVar8[1];
          param_4[8] = *piVar8;
          param_4[9] = piVar8[1];
          param_4[3] = 0;
          if ((param_4[1] & 3U) == 1) {
            param_4[2] = 0;
            piVar8 = FUN_404055b0((int)pvVar1,local_40);
            param_4[0xc] = *piVar8;
            param_4[0xd] = piVar8[1];
            param_4[0xe] = piVar8[2];
            param_4[0xf] = piVar8[3];
            iVar7 = FUN_40419ef8((int)pvVar1);
            param_4[0x10] = iVar7;
          }
          else {
            iVar7 = FUN_40415270((int)pvVar1);
            param_4[2] = iVar7;
            param_4[0xc] = 0;
            param_4[0xd] = 0;
            param_4[0xe] = 0;
            param_4[0xf] = 0;
            param_4[0x10] = 0;
          }
        }
      }
      else {
        FUN_40410c64(param_3,pvVar5);
        uVar2 = FUN_4041e42c((int)pvVar1);
        *(uint *)((int)param_3 + 0x44) = CONCAT31(extraout_var_01,uVar2);
      }
      goto LAB_4042007c;
    }
  }
  iVar4 = -0x7ffcfef7;
LAB_4042007c:
  FUN_4041eb24(param_1,param_2);
  return iVar4;
}



/* 404200b8 FUN_404200b8 */

void FUN_404200b8(int *param_1)

{
  *(int *)(DAT_404304bc + param_1[1]) = *param_1;
  *(int *)(*param_1 + DAT_404304bc + 4) = param_1[1];
  param_1[1] = 0;
  *param_1 = 0;
  return;
}



/* 404200f0 FUN_404200f0 */

/* Boundary evidence: original MIPS .pdata 404200f0..4042010b. Semantic name remains unreviewed. */

void FUN_404200f0(undefined4 param_1,undefined4 param_2,int param_3)

{
  FUN_4040a638(param_3 + 0x20);
  return;
}



/* 4042010c FUN_4042010c */

int FUN_4042010c(int *param_1)

{
  int iVar1;
  
  if (*param_1 == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = *param_1 + DAT_404304bc;
  }
  return iVar1;
}



/* 40420134 FUN_40420134 */

int FUN_40420134(int param_1)

{
  int iVar1;
  
  if (*(int *)(param_1 + 4) == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = *(int *)(param_1 + 4) + DAT_404304bc;
  }
  return iVar1;
}



/* 4042015c FUN_4042015c */

undefined4 FUN_4042015c(int param_1)

{
  return *(undefined4 *)(param_1 + 8);
}



/* 40420164 FUN_40420164 */

undefined4 FUN_40420164(int param_1)

{
  return *(undefined4 *)(param_1 + 0xc);
}



/* 4042016c FUN_4042016c */

undefined4 FUN_4042016c(int param_1)

{
  return *(undefined4 *)(param_1 + 0x14);
}



/* 40420174 FUN_40420174 */

undefined4 FUN_40420174(int param_1)

{
  return *(undefined4 *)(param_1 + 0x18);
}



/* 4042017c FUN_4042017c */

int FUN_4042017c(int param_1)

{
  return param_1 + 0x20;
}



/* 40420184 FUN_40420184 */

void FUN_40420184(int *param_1,int param_2,int param_3)

{
  int iVar1;
  
  if (param_2 == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = param_2 - DAT_404304bc;
  }
  param_1[1] = iVar1;
  if (param_3 == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = param_3 - DAT_404304bc;
  }
  *param_1 = iVar1;
  return;
}



/* 404201bc FUN_404201bc */

void FUN_404201bc(int param_1,int param_2)

{
  int iVar1;
  
  if (param_2 == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = param_2 - DAT_404304bc;
  }
  *(int *)(param_1 + 4) = iVar1;
  return;
}



/* 404201e0 FUN_404201e0 */

void FUN_404201e0(int *param_1,int param_2)

{
  int iVar1;
  
  if (param_2 == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = param_2 - DAT_404304bc;
  }
  *param_1 = iVar1;
  return;
}



/* 40420204 FUN_40420204 */

void FUN_40420204(int param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 8) = param_2;
  return;
}



/* 4042020c FUN_4042020c */

void FUN_4042020c(int param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 0xc) = param_2;
  return;
}



/* 40420214 FUN_40420214 */

void FUN_40420214(int param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 0x18) = param_2;
  return;
}



/* 4042021c FUN_4042021c */

void FUN_4042021c(int param_1,int param_2)

{
  int iVar1;
  
  if (param_2 == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = param_2 - DAT_404304bc;
  }
  *(int *)(param_1 + 0x10) = iVar1;
  return;
}



/* 40420240 FUN_40420240 */

void FUN_40420240(int param_1)

{
  *(uint *)(param_1 + 0x18) = *(uint *)(param_1 + 0x18) & 0xfffffffe;
  return;
}



/* 40420258 FUN_40420258 */

bool FUN_40420258(int param_1)

{
  return (*(uint *)(param_1 + 0x18) & 1) != 0;
}



/* 40420274 FUN_40420274 */

bool FUN_40420274(int param_1)

{
  return *(int *)(param_1 + 0x1c) != 0;
}



/* 4042028c FUN_4042028c */

/* Boundary evidence: original MIPS .pdata 4042028c..404202d7. Semantic name remains unreviewed. */

undefined4 FUN_4042028c(int param_1)

{
  bool bVar1;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  undefined4 uVar2;
  
  bVar1 = FUN_40420258(param_1);
  if ((CONCAT31(extraout_var,bVar1) == 0) ||
     (bVar1 = FUN_40420274(param_1), CONCAT31(extraout_var_00,bVar1) != 0)) {
    uVar2 = 0;
  }
  else {
    uVar2 = 1;
  }
  return uVar2;
}



/* 404202d8 FUN_404202d8 */

void FUN_404202d8(int param_1)

{
  *(int *)(param_1 + 0x1c) = *(int *)(param_1 + 0x1c) + 1;
  return;
}



/* 404202e8 FUN_404202e8 */

void FUN_404202e8(int param_1,int param_2)

{
  int *piVar1;
  
  if ((*(int *)(param_1 + 0x14) != 0) &&
     (piVar1 = (int *)(param_2 * 4 + *(int *)(param_1 + 0x14) + DAT_404304bc), *piVar1 != 0)) {
    *piVar1 = 0;
  }
  return;
}



/* 40420320 FUN_40420320 */

int FUN_40420320(int param_1)

{
  int iVar1;
  
  if (*(int *)(param_1 + 0x10) == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = *(int *)(param_1 + 0x10) + DAT_404304bc;
  }
  return iVar1;
}



/* 40420348 FUN_40420348 */

/* Boundary evidence: original MIPS .pdata 40420348..40420417. Semantic name remains unreviewed. */

uint FUN_40420348(int param_1,uint param_2,uint param_3,uint *param_4)

{
  uint uVar1;
  int iVar2;
  uint local_10 [2];
  
  if (param_2 == 0xfffffffb) {
    uVar1 = FUN_40425720((int *)(param_1 + 0x28c),param_3,local_10);
  }
  else {
    uVar1 = local_10[0];
    if (param_2 < 0xfffffffc) goto LAB_40420400;
    if (param_2 < 0xfffffffe) {
      if (param_2 == 0xfffffffd) {
        iVar2 = param_1 + 0x36c;
      }
      else {
        iVar2 = param_1 + 0x3ec;
      }
      uVar1 = FUN_40427164(iVar2,param_3,local_10);
    }
    else {
      if (param_2 != 0xfffffffe) goto LAB_40420400;
      uVar1 = FUN_40425648((int *)(param_1 + 0x28c),param_3,local_10);
    }
  }
  if ((int)uVar1 < 0) {
    return uVar1;
  }
LAB_40420400:
  *param_4 = local_10[0];
  return uVar1;
}



/* 40420418 FUN_40420418 */

void FUN_40420418(int param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 0x14) = param_2;
  return;
}



/* 40420420 FUN_40420420 */

/* Boundary evidence: original MIPS .pdata 40420420..404204d7. Semantic name remains unreviewed. */

undefined4 FUN_40420420(int param_1,int *param_2)

{
  bool bVar1;
  uint uVar2;
  int *piVar3;
  uint uVar4;
  int iVar5;
  int *piVar6;
  
  uVar2 = FUN_4042016c((int)param_2);
  if (*(int *)(param_1 + 0x1c) == 0) {
    piVar6 = (int *)0x0;
  }
  else {
    piVar6 = (int *)(*(int *)(param_1 + 0x1c) + DAT_404304bc);
  }
  piVar3 = (int *)FUN_4042010c(param_2);
  if (param_2 == piVar6) {
    uVar4 = FUN_4042016c((int)piVar3);
    bVar1 = uVar4 < uVar2;
  }
  else {
    if ((piVar3 != piVar6) && (uVar4 = FUN_4042016c((int)piVar3), uVar4 < uVar2)) {
      return 0;
    }
    iVar5 = FUN_40420134((int)param_2);
    uVar4 = FUN_4042016c(iVar5);
    bVar1 = uVar2 < uVar4;
  }
  if (bVar1) {
    return 0;
  }
  return 1;
}



/* 404204d8 FUN_404204d8 */

/* Boundary evidence: original MIPS .pdata 404204d8..40420633. Semantic name remains unreviewed. */

void FUN_404204d8(int param_1,int *param_2,uint param_3)

{
  int iVar1;
  uint uVar2;
  int *piVar3;
  int *piVar4;
  int iVar5;
  int *piVar6;
  
  FUN_40420418((int)param_2,param_3);
  iVar1 = FUN_40420420(param_1,param_2);
  iVar5 = DAT_404304bc;
  if (iVar1 == 0) {
    piVar6 = (int *)(*(int *)(param_1 + 0x1c) + DAT_404304bc);
    if (*(int *)(param_1 + 0x1c) == 0) {
      piVar6 = (int *)0x0;
    }
    if (piVar6 == param_2) {
      piVar6 = (int *)FUN_4042010c(param_2);
      iVar5 = (int)piVar6 - iVar5;
      if (piVar6 == (int *)0x0) {
        iVar5 = 0;
      }
      *(int *)(param_1 + 0x1c) = iVar5;
    }
    FUN_404200b8(param_2);
    uVar2 = FUN_4042016c((int)piVar6);
    piVar3 = piVar6;
    while ((uVar2 < param_3 && (piVar3 = (int *)FUN_4042010c(piVar3), piVar3 != piVar6))) {
      uVar2 = FUN_4042016c((int)piVar3);
    }
    piVar4 = (int *)FUN_40420134((int)piVar3);
    FUN_404201e0(piVar4,(int)param_2);
    iVar5 = FUN_40420134((int)piVar3);
    FUN_40420184(param_2,iVar5,(int)piVar3);
    FUN_404201bc((int)piVar3,(int)param_2);
    uVar2 = FUN_4042016c((int)piVar6);
    if (param_3 <= uVar2) {
      if (param_2 == (int *)0x0) {
        iVar5 = 0;
      }
      else {
        iVar5 = (int)param_2 - DAT_404304bc;
      }
      *(int *)(param_1 + 0x1c) = iVar5;
    }
  }
  return;
}



/* 40420634 FUN_40420634 */

/* Boundary evidence: original MIPS .pdata 40420634..404206c3. Semantic name remains unreviewed. */

int * FUN_40420634(int *param_1,int param_2,int param_3,int param_4)

{
  undefined2 uVar1;
  undefined2 extraout_var;
  int iVar2;
  
  uVar1 = FUN_4040d6bc(param_2);
  param_1[1] = CONCAT22(extraout_var,uVar1);
  param_1[2] = param_3;
  param_1[3] = param_4;
  if (param_2 == 0) {
    iVar2 = 0;
  }
  else {
    iVar2 = param_2 - DAT_404304bc;
  }
  *param_1 = iVar2;
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[6] = 0;
  param_1[7] = 0;
  param_1[8] = 1;
  return param_1;
}



/* 404206c4 FUN_404206c4 */

/* Boundary evidence: original MIPS .pdata 404206c4..4042078f. Semantic name remains unreviewed. */

int * FUN_404206c4(int *param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  
  if (param_2 == 0) {
    FUN_40420184(param_1,(int)param_1,(int)param_1);
  }
  else {
    iVar1 = FUN_40420134(param_2);
    FUN_40420184(param_1,iVar1,param_2);
    piVar2 = (int *)FUN_40420134((int)param_1);
    FUN_404201e0(piVar2,(int)param_1);
    iVar1 = FUN_4042010c(param_1);
    FUN_404201bc(iVar1,(int)param_1);
  }
  FUN_40420204((int)param_1,0xffffffff);
  FUN_4042020c((int)param_1,0);
  param_1[5] = -2;
  FUN_40420214((int)param_1,0);
  FUN_4042021c((int)param_1,0);
  param_1[7] = 0;
  return param_1;
}



/* 40420790 FUN_40420790 */

/* Boundary evidence: original MIPS .pdata 40420790..40420813. Semantic name remains unreviewed. */

int * FUN_40420790(int *param_1)

{
  undefined4 uVar1;
  int *piVar2;
  int iVar3;
  
  uVar1 = FUN_4040d71c(*param_1 + DAT_404304bc);
  piVar2 = (int *)FUN_404200f0(0x20,uVar1,param_1[1]);
  if (piVar2 == (int *)0x0) {
    piVar2 = (int *)0x0;
  }
  else {
    if (param_1[7] == 0) {
      iVar3 = 0;
    }
    else {
      iVar3 = param_1[7] + DAT_404304bc;
    }
    piVar2 = FUN_404206c4(piVar2,iVar3);
  }
  return piVar2;
}



/* 40420814 FUN_40420814 */

/* Boundary evidence: original MIPS .pdata 40420814..404208b3. Semantic name remains unreviewed. */

undefined4 FUN_40420814(int *param_1)

{
  int *piVar1;
  uint uVar2;
  
  uVar2 = 0;
  if (param_1[2] != 0) {
    do {
      piVar1 = FUN_40420790(param_1);
      if (piVar1 == (int *)0x0) {
        return 0x80030008;
      }
      param_1[7] = (int)piVar1 - DAT_404304bc;
      uVar2 = uVar2 + 1;
    } while (uVar2 < (uint)param_1[2]);
  }
  param_1[5] = param_1[2];
  param_1[4] = 0;
  param_1[6] = param_1[7];
  return 0;
}



/* 404208b4 FUN_404208b4 */

/* Boundary evidence: original MIPS .pdata 404208b4..4042099b. Semantic name remains unreviewed. */

int FUN_404208b4(undefined4 param_1,int param_2)

{
  undefined2 uVar1;
  int iVar2;
  int *piVar3;
  undefined2 extraout_var;
  
  FUN_404202d8(param_2);
  iVar2 = FUN_40420320(param_2);
  piVar3 = (int *)FUN_40420320(iVar2);
  uVar1 = FUN_404156c8((int)piVar3);
  iVar2 = FUN_4042016c(param_2);
  FUN_404157c4(iVar2,0,CONCAT22(extraout_var,uVar1));
  piVar3 = (int *)FUN_4040d6c4(piVar3);
  iVar2 = *piVar3;
  FUN_4042017c(param_2);
  iVar2 = (**(code **)(iVar2 + 0x10))(piVar3);
  if (-1 < iVar2) {
    FUN_40420240(param_2);
  }
  FUN_4041e4e4(param_2);
  return iVar2;
}



/* 4042099c FUN_4042099c */

/* Boundary evidence: original MIPS .pdata 4042099c..40420cdb. Semantic name remains unreviewed. */

int FUN_4042099c(int *param_1)

{
  undefined2 uVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  void *_Src;
  int *piVar5;
  undefined2 extraout_var;
  uint uVar6;
  size_t _Size;
  int iVar7;
  uint uVar8;
  int iVar9;
  uint uVar10;
  void *pvVar11;
  int *piVar12;
  int *piVar13;
  uint local_34;
  uint local_2c;
  
  iVar7 = 0;
  pvVar11 = (void *)0x0;
  piVar12 = (int *)(param_1[7] + DAT_404304bc);
  local_34 = 0;
  iVar9 = DAT_404304bc;
  piVar13 = piVar12;
  if (param_1[7] == 0) {
    piVar12 = (int *)0x0;
    piVar13 = piVar12;
  }
LAB_40420a14:
  iVar2 = FUN_4042028c((int)piVar12);
  piVar4 = piVar12;
  if (iVar2 == 0) {
    piVar12 = (int *)FUN_4042010c(piVar12);
    piVar4 = piVar12;
    if (piVar12 != piVar13) goto LAB_40420a14;
  }
  iVar2 = FUN_4042028c((int)piVar4);
  piVar12 = piVar4;
  if (iVar2 != 0) {
    iVar2 = FUN_4042028c((int)piVar4);
    if (iVar2 != 0) {
      do {
        piVar5 = piVar12;
        piVar12 = (int *)FUN_4042010c(piVar5);
        if (piVar12 == (int *)0x0) {
          iVar7 = -0x7fff0001;
          goto LAB_40420c98;
        }
        iVar2 = FUN_4042016c((int)piVar5);
        iVar3 = FUN_4042016c((int)piVar12);
      } while ((iVar3 == iVar2 + 1) && (iVar2 = FUN_4042028c((int)piVar12), iVar2 != 0));
      if (piVar4 != piVar5) {
        iVar2 = FUN_4042016c((int)piVar4);
        iVar3 = FUN_4042016c((int)piVar5);
        uVar10 = (1 - iVar2) + iVar3;
        uVar6 = param_1[1] * uVar10;
        if (local_34 < uVar6) {
          operator_delete(pvVar11);
          pvVar11 = operator_new(uVar6);
          iVar9 = DAT_404304bc;
          local_34 = uVar6;
        }
        if (pvVar11 == (void *)0x0) {
          local_34 = 0;
          uVar6 = 0;
          if (uVar10 != 0) {
            do {
              iVar7 = FUN_404208b4(param_1,(int)piVar4);
              if (iVar7 < 0) {
                return iVar7;
              }
              piVar4 = (int *)FUN_4042010c(piVar4);
              uVar6 = uVar6 + 1;
              iVar9 = DAT_404304bc;
            } while (uVar6 < uVar10);
          }
          goto LAB_40420c74;
        }
        uVar8 = 0;
        piVar5 = piVar4;
        if (uVar10 != 0) {
          do {
            _Size = param_1[1];
            _Src = (void *)FUN_4042017c((int)piVar5);
            memcpy((void *)(_Size * uVar8 + (int)pvVar11),_Src,_Size);
            piVar5 = (int *)FUN_4042010c(piVar5);
            uVar8 = uVar8 + 1;
            iVar9 = DAT_404304bc;
          } while (uVar8 < uVar10);
        }
        iVar2 = *param_1;
        uVar1 = FUN_404156c8(iVar2 + iVar9);
        iVar7 = FUN_4042016c((int)piVar4);
        FUN_404157c4(iVar7,0,CONCAT22(extraout_var,uVar1));
        piVar5 = (int *)FUN_4040d6c4((int *)(iVar2 + iVar9));
        iVar7 = (**(code **)(*piVar5 + 0x10))(piVar5);
        if (iVar7 < 0) goto LAB_40420c98;
        iVar9 = DAT_404304bc;
        if (local_2c != uVar6) {
          iVar7 = -0x7ffcffe3;
          goto LAB_40420c98;
        }
        for (; DAT_404304bc = iVar9, uVar10 != 0; uVar10 = uVar10 - 1) {
          FUN_40420240((int)piVar4);
          piVar4 = (int *)FUN_4042010c(piVar4);
          iVar9 = DAT_404304bc;
        }
        goto LAB_40420c74;
      }
    }
    iVar7 = FUN_404208b4(param_1,(int)piVar4);
    iVar9 = DAT_404304bc;
    if (iVar7 < 0) goto LAB_40420c98;
  }
LAB_40420c74:
  if (piVar12 == piVar13) {
LAB_40420c98:
    if (pvVar11 != (void *)0x0) {
      operator_delete(pvVar11);
    }
    return iVar7;
  }
  goto LAB_40420a14;
}



/* 40420cdc FUN_40420cdc */

/* Boundary evidence: original MIPS .pdata 40420cdc..40420d93. Semantic name remains unreviewed. */

void FUN_40420cdc(int param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  
  piVar2 = (int *)(*(int *)(param_1 + 0x18) + DAT_404304bc);
  iVar3 = DAT_404304bc;
  if (*(int *)(param_1 + 0x18) == 0) {
    piVar2 = (int *)0x0;
  }
  do {
    iVar1 = FUN_40420320((int)piVar2);
    if (iVar1 == param_2) {
      FUN_40420204((int)piVar2,0xffffffff);
      FUN_4042021c((int)piVar2,0);
      FUN_40420240((int)piVar2);
      *(int *)(param_1 + 0x10) = *(int *)(param_1 + 0x10) + -1;
      iVar3 = DAT_404304bc;
    }
    piVar2 = (int *)FUN_4042010c(piVar2);
  } while (piVar2 != (int *)(iVar3 + *(int *)(param_1 + 0x18)));
  return;
}



/* 40420d94 FUN_40420d94 */

/* Boundary evidence: original MIPS .pdata 40420d94..40420e5f. Semantic name remains unreviewed. */

void FUN_40420d94(int param_1)

{
  bool bVar1;
  undefined3 extraout_var;
  uint uVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  
  do {
    while( true ) {
      iVar4 = DAT_404304bc;
      piVar5 = (int *)(DAT_404304bc + *(int *)(param_1 + 0x18));
      bVar1 = FUN_40420274((int)piVar5);
      if (CONCAT31(extraout_var,bVar1) == 0) break;
      iVar3 = FUN_4042010c(piVar5);
      iVar4 = iVar3 - iVar4;
      if (iVar3 == 0) {
        iVar4 = 0;
      }
      *(int *)(param_1 + 0x18) = iVar4;
    }
    uVar2 = FUN_40420174((int)piVar5);
    FUN_40420214((int)piVar5,uVar2 & 0xefffffff);
    iVar4 = DAT_404304bc;
    iVar3 = FUN_4042010c((int *)(DAT_404304bc + *(int *)(param_1 + 0x18)));
    iVar4 = iVar3 - iVar4;
    if (iVar3 == 0) {
      iVar4 = 0;
    }
    *(int *)(param_1 + 0x18) = iVar4;
  } while ((uVar2 & 0x10000000) != 0);
  FUN_40420134(iVar4 + DAT_404304bc);
  return;
}



/* 40420e60 FUN_40420e60 */

/* Boundary evidence: original MIPS .pdata 40420e60..40420fff. Semantic name remains unreviewed. */

undefined4 FUN_40420e60(int *param_1,int param_2,int param_3,int *param_4)

{
  ushort uVar1;
  undefined4 uVar2;
  void *_Src;
  void *_Dst;
  int iVar3;
  uint uVar4;
  int *piVar5;
  int *piVar6;
  
  if (param_3 != 0) {
    uVar4 = param_1[4];
    if (uVar4 < (uint)param_1[5]) {
      iVar3 = param_1[6];
      piVar5 = (int *)(iVar3 + DAT_404304bc);
      if (iVar3 == 0) {
        piVar5 = (int *)0x0;
      }
      piVar6 = (int *)(iVar3 + DAT_404304bc);
      do {
        piVar5 = (int *)FUN_4042010c(piVar5);
        if (piVar5 == piVar6) break;
        iVar3 = FUN_4042015c((int)piVar5);
      } while (iVar3 != -1);
      param_1[4] = uVar4 + 1;
    }
    else {
      if (((uint)param_1[3] <= (uint)param_1[5]) ||
         (piVar5 = FUN_40420790(param_1), piVar5 == (int *)0x0)) goto LAB_40420fc8;
      param_1[4] = param_1[4] + 1;
      param_1[5] = param_1[5] + 1;
    }
    if (piVar5 != (int *)0x0) {
      FUN_4042021c((int)piVar5,param_2);
      uVar2 = FUN_4042015c(param_3);
      FUN_40420204((int)piVar5,uVar2);
      uVar2 = FUN_40420164(param_3);
      FUN_4042020c((int)piVar5,uVar2);
      uVar4 = FUN_4042016c(param_3);
      FUN_404204d8((int)param_1,piVar5,uVar4);
      uVar1 = *(ushort *)(param_1 + 1);
      _Src = (void *)FUN_4042017c(param_3);
      _Dst = (void *)FUN_4042017c((int)piVar5);
      memcpy(_Dst,_Src,(uint)uVar1);
      iVar3 = (int)piVar5 - DAT_404304bc;
      goto LAB_40420fcc;
    }
  }
LAB_40420fc8:
  iVar3 = 0;
LAB_40420fcc:
  *param_4 = iVar3;
  return 0;
}



/* 40421000 FUN_40421000 */

/* Boundary evidence: original MIPS .pdata 40421000..4042101b. Semantic name remains unreviewed. */

void FUN_40421000(int *param_1)

{
  FUN_404200b8(param_1);
  return;
}



/* 4042101c FUN_4042101c */

/* Boundary evidence: original MIPS .pdata 4042101c..40421067. Semantic name remains unreviewed. */

int * FUN_4042101c(int *param_1,uint param_2)

{
  FUN_40421000(param_1);
  if ((param_2 & 1) != 0) {
    FUN_4040a65c(param_1);
  }
  return param_1;
}



/* 40421068 FUN_40421068 */

/* Boundary evidence: original MIPS .pdata 40421068..4042121b. Semantic name remains unreviewed. */

int FUN_40421068(int *param_1,int *param_2)

{
  bool bVar1;
  int iVar2;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  int iVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  int *piVar7;
  
  iVar6 = 0;
  if ((uint)param_1[4] < (uint)param_1[5]) {
    iVar6 = param_1[6];
    piVar5 = (int *)(iVar6 + DAT_404304bc);
    if (iVar6 == 0) {
      piVar5 = (int *)0x0;
    }
    piVar7 = (int *)(iVar6 + DAT_404304bc);
    do {
      piVar5 = (int *)FUN_4042010c(piVar5);
      if (piVar5 == piVar7) break;
      iVar6 = FUN_4042015c((int)piVar5);
    } while (iVar6 != -1);
    *param_2 = (int)piVar5;
    param_1[4] = param_1[4] + 1;
    return 0;
  }
  if (param_1[5] == param_1[3]) {
    iVar2 = FUN_40420d94((int)param_1);
    if (iVar2 == 0) {
      return -0x7ffcfff8;
    }
    bVar1 = FUN_40420258(iVar2);
    if ((CONCAT31(extraout_var,bVar1) != 0) && (iVar6 = FUN_404208b4(param_1,iVar2), iVar6 < 0)) {
      return iVar6;
    }
  }
  else {
    piVar5 = FUN_40420790(param_1);
    if (piVar5 != (int *)0x0) {
      *param_2 = (int)piVar5;
      param_1[4] = param_1[4] + 1;
      param_1[5] = param_1[5] + 1;
      return 0;
    }
    iVar2 = FUN_40420d94((int)param_1);
    if (iVar2 == 0) {
      return -0x7ffcfff8;
    }
    bVar1 = FUN_40420258(iVar2);
    if ((CONCAT31(extraout_var_00,bVar1) != 0) && (iVar6 = FUN_404208b4(param_1,iVar2), iVar6 < 0))
    {
      return iVar6;
    }
    iVar3 = FUN_40420320(iVar2);
    if (iVar3 == 0) goto LAB_404211f4;
  }
  iVar3 = FUN_40420164(iVar2);
  iVar4 = FUN_40420320(iVar2);
  FUN_404202e8(iVar4,iVar3);
LAB_404211f4:
  *param_2 = iVar2;
  return iVar6;
}



/* 4042121c FUN_4042121c */

/* Boundary evidence: original MIPS .pdata 4042121c..40421337. Semantic name remains unreviewed. */

int FUN_4042121c(int *param_1,int param_2,undefined4 param_3,int param_4,undefined4 *param_5)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int *local_28 [2];
  
  iVar2 = DAT_404304bc;
  iVar4 = param_1[6];
  piVar3 = (int *)(iVar4 + DAT_404304bc);
  if (iVar4 == 0) {
    piVar3 = (int *)0x0;
  }
  while ((iVar1 = FUN_40420320((int)piVar3), iVar1 != param_2 ||
         (iVar1 = FUN_40420164((int)piVar3), iVar1 != param_4))) {
    piVar3 = (int *)FUN_4042010c(piVar3);
    local_28[0] = piVar3;
    if (piVar3 == (int *)(iVar4 + iVar2)) {
      iVar2 = FUN_40421068(param_1,(int *)local_28);
      piVar3 = local_28[0];
      if (-1 < iVar2) {
        FUN_4042021c((int)local_28[0],param_2);
        FUN_40420204((int)piVar3,param_3);
        FUN_4042020c((int)piVar3,param_4);
        FUN_404204d8((int)param_1,piVar3,0xfffffffe);
        *param_5 = piVar3;
      }
      return iVar2;
    }
  }
  *param_5 = piVar3;
  return 0x30400;
}



/* 40421338 FUN_40421338 */

/* Boundary evidence: original MIPS .pdata 40421338..4042153f. Semantic name remains unreviewed. */

uint FUN_40421338(int *param_1,int param_2,uint param_3,uint param_4,uint param_5,int *param_6)

{
  undefined2 uVar1;
  uint uVar2;
  int iVar3;
  int *piVar4;
  undefined2 extraout_var;
  int iVar5;
  uint local_28;
  int local_24;
  
  *param_6 = 0;
  uVar2 = FUN_4042121c(param_1,param_2,param_3,param_4,param_6);
  if ((-1 < (int)uVar2) && (FUN_404202d8(*param_6), uVar2 != 0x30400)) {
    if (param_5 == 0xfffffffe) {
      iVar3 = FUN_40420320(param_2);
      uVar2 = FUN_40420348(iVar3,param_3,param_4,&local_28);
      param_5 = local_28;
      if ((int)uVar2 < 0) goto LAB_404214b0;
    }
    FUN_404204d8((int)param_1,(int *)*param_6,param_5);
    iVar5 = *param_6;
    iVar3 = FUN_40420320(iVar5);
    piVar4 = (int *)FUN_40420320(iVar3);
    if (piVar4 == (int *)0x0) {
      uVar2 = 0x8000ffff;
    }
    else {
      uVar1 = FUN_404156c8((int)piVar4);
      iVar3 = FUN_4042016c(iVar5);
      FUN_404157c4(iVar3,0,CONCAT22(extraout_var,uVar1));
      piVar4 = (int *)FUN_4040d6c4(piVar4);
      iVar3 = *piVar4;
      FUN_4042017c(iVar5);
      uVar2 = (**(code **)(iVar3 + 0xc))(piVar4);
      if ((-1 < (int)uVar2) && (local_24 != param_1[1])) {
        uVar2 = 0x80030109;
      }
    }
  }
LAB_404214b0:
  if (*param_6 != 0) {
    if ((int)uVar2 < 0) {
      FUN_40420204(*param_6,0xffffffff);
      FUN_4042020c(*param_6,0);
      FUN_404204d8((int)param_1,(int *)*param_6,0xfffffffe);
      FUN_40420214(*param_6,0);
      FUN_4042021c(*param_6,0);
      param_1[4] = param_1[4] + -1;
    }
    FUN_4041e4e4(*param_6);
  }
  return uVar2;
}



/* 40421540 FUN_40421540 */

/* Boundary evidence: original MIPS .pdata 40421540..4042156f. Semantic name remains unreviewed. */

void FUN_40421540(int *param_1,int param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  int local_10 [2];
  
  iVar1 = FUN_4042121c(param_1,param_2,param_3,param_4,local_10);
  if (-1 < iVar1) {
    FUN_4041e4e4(local_10[0]);
  }
  return;
}



/* 40421570 FUN_40421570 */

/* Boundary evidence: original MIPS .pdata 40421570..40421613. Semantic name remains unreviewed. */

void FUN_40421570(int param_1)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  
  if ((*(int *)(param_1 + 0x18) != 0) &&
     (piVar2 = (int *)(*(int *)(param_1 + 0x18) + DAT_404304bc), piVar2 != (int *)0x0)) {
    piVar1 = (int *)FUN_4042010c(piVar2);
    piVar3 = piVar2;
    if (piVar2 != piVar1) {
      do {
        piVar2 = (int *)FUN_4042010c(piVar3);
        FUN_4042101c(piVar3,0);
        FUN_4040a688(piVar3,piVar3);
        piVar1 = (int *)FUN_4042010c(piVar2);
        piVar3 = piVar2;
      } while (piVar2 != piVar1);
    }
    FUN_4042101c(piVar2,0);
    FUN_4040a688(piVar2,piVar2);
  }
  return;
}



/* 40421614 FUN_40421614 */

undefined4 FUN_40421614(int param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 0x2c) = param_2;
  *(undefined4 *)(param_1 + 0x200) = 1;
  return 0;
}



/* 40421628 FUN_40421628 */

undefined4 FUN_40421628(int param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 0x40) = param_2;
  *(undefined4 *)(param_1 + 0x200) = 1;
  return 0;
}



/* 4042163c FUN_4042163c */

undefined4 FUN_4042163c(int param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 0x30) = param_2;
  *(undefined4 *)(param_1 + 0x200) = 1;
  return 0;
}



/* 40421650 FUN_40421650 */

undefined4 FUN_40421650(int param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 0x3c) = param_2;
  *(undefined4 *)(param_1 + 0x200) = 1;
  return 0;
}



/* 40421664 FUN_40421664 */

/* Boundary evidence: original MIPS .pdata 40421664..4042168f. Semantic name remains unreviewed. */

undefined4 * FUN_40421664(undefined4 *param_1,undefined4 param_2)

{
  FUN_4041e4f4(param_1,param_2);
  return param_1;
}



/* 40421690 FUN_40421690 */

void FUN_40421690(int param_1,uint param_2,uint *param_3,ushort *param_4)

{
  *param_3 = param_2 >> (*(ushort *)(param_1 + 0x34) & 0x1f);
  *param_4 = *(ushort *)(param_1 + 0x36) & (ushort)param_2;
  return;
}



/* 404216ac FUN_404216ac */

int FUN_404216ac(int param_1,int param_2,int param_3)

{
  return (param_2 << (*(ushort *)(param_1 + 0x34) & 0x1f)) + param_3;
}



/* 404216bc FUN_404216bc */

void FUN_404216bc(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  if (*(ushort *)(param_1 + 0x2c) < 8) {
    *(undefined4 *)((*(ushort *)(param_1 + 0x2c) + 0xc) * 4 + param_1) = param_2;
    *(undefined4 *)((*(ushort *)(param_1 + 0x2c) + 0x14) * 4 + param_1) = param_3;
    *(undefined4 *)((*(ushort *)(param_1 + 0x2c) + 0x1c) * 4 + param_1) = param_4;
  }
  *(short *)(param_1 + 0x2c) = *(short *)(param_1 + 0x2c) + 1;
  return;
}



/* 40421714 FUN_40421714 */

undefined4 FUN_40421714(int param_1)

{
  return *(undefined4 *)(param_1 + 0x478);
}



/* 4042171c FUN_4042171c */

undefined4 FUN_4042171c(int param_1)

{
  return *(undefined4 *)(param_1 + 0x4a0);
}



/* 40421724 FUN_40421724 */

int FUN_40421724(int param_1,int param_2)

{
  int iVar1;
  
  if (*(int *)(param_1 + 0x18) == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = param_2 * 4 + *(int *)(param_1 + 0x18) + DAT_404304bc;
  }
  return iVar1;
}



/* 40421754 FUN_40421754 */

/* Boundary evidence: original MIPS .pdata 40421754..40421777. Semantic name remains unreviewed. */

undefined4 FUN_40421754(void *param_1,int param_2)

{
  memset(param_1,0xff,param_2 << 2);
  return 0;
}



/* 40421778 FUN_40421778 */

/* Boundary evidence: original MIPS .pdata 40421778..404217df. Semantic name remains unreviewed. */

undefined4 * FUN_40421778(undefined4 *param_1,undefined4 param_2)

{
  FUN_40421664(param_1,param_2);
  param_1[9] = param_2;
  param_1[8] = 0;
  param_1[10] = 0;
  param_1[0xb] = 0;
  param_1[0xc] = 0;
  param_1[0x11] = 0;
  param_1[0x12] = 0;
  param_1[0x13] = 0xfffffffe;
  param_1[0x10] = 0;
  return param_1;
}



/* 404217e0 FUN_404217e0 */

/* Boundary evidence: original MIPS .pdata 404217e0..4042185b. Semantic name remains unreviewed. */

undefined4 * FUN_404217e0(undefined4 *param_1,int param_2)

{
  FUN_40421664(param_1,*(undefined4 *)(param_2 + 0x24));
  param_1[8] = *(int *)(param_2 + 0x20) + DAT_404304bc;
  param_1[9] = *(undefined4 *)(param_2 + 0x24);
  param_1[10] = 0;
  param_1[0xc] = *(undefined4 *)(param_2 + 0x30);
  param_1[0x11] = 0;
  param_1[0x12] = 0;
  param_1[0x13] = 0xfffffffe;
  param_1[0x10] = 0;
  return param_1;
}



/* 4042185c FUN_4042185c */

/* Boundary evidence: original MIPS .pdata 4042185c..4042192b. Semantic name remains unreviewed. */

void FUN_4042185c(int *param_1,int param_2)

{
  ushort uVar1;
  undefined2 uVar2;
  undefined2 extraout_var;
  int iVar3;
  
  iVar3 = *(int *)(param_2 + 0x20);
  param_1[8] = iVar3;
  uVar1 = FUN_404156c8(iVar3 + DAT_404304bc);
  *(short *)(param_1 + 0xd) = (short)(uVar1 + 0xfffe);
  uVar2 = FUN_4040d6bc(param_1[8] + DAT_404304bc);
  *(short *)((int)param_1 + 0x36) = (short)(CONCAT22(extraout_var,uVar2) >> 2) + -1;
  uVar2 = (undefined2)(1 << (uVar1 + 0xfffe & 0x1f));
  FUN_404155c4((int)param_1,uVar2,uVar2);
  param_1[0xe] = *(int *)(param_2 + 0x38);
  FUN_404252fc(param_1,param_2);
  param_1[0xf] = -1;
  param_1[0x11] = *(int *)(param_2 + 0x44);
  param_1[0x12] = *(int *)(param_2 + 0x48);
  param_1[0x13] = *(int *)(param_2 + 0x4c);
  return;
}



/* 4042192c FUN_4042192c */

/* Boundary evidence: original MIPS .pdata 4042192c..40421983. Semantic name remains unreviewed. */

void FUN_4042192c(int *param_1)

{
  FUN_40424950(param_1);
  param_1[8] = 0;
  param_1[10] = 0;
  param_1[0xe] = 0;
  param_1[0xf] = -1;
  param_1[0x11] = 0;
  param_1[0x12] = 0;
  param_1[0x13] = -2;
  param_1[0x10] = 0;
  return;
}



/* 40421984 FUN_40421984 */

/* Boundary evidence: original MIPS .pdata 40421984..4042199f. Semantic name remains unreviewed. */

void FUN_40421984(int param_1)

{
  FUN_40415638(param_1);
  return;
}



/* 404219a0 FUN_404219a0 */

void FUN_404219a0(undefined4 param_1,int param_2)

{
  *(undefined4 *)(param_2 + 8) = 0;
  *(undefined4 *)(param_2 + 0x14) = 0xfffffffe;
  *(undefined4 *)(param_2 + 0x20) = 0;
  return;
}



/* 404219b8 FUN_404219b8 */

/* Boundary evidence: original MIPS .pdata 404219b8..40421a1b. Semantic name remains unreviewed. */

void FUN_404219b8(int *param_1,int param_2)

{
  if (*(int *)(param_2 + 8) != 0) {
    FUN_4041e55c(param_1,*(int *)(param_2 + 0x10));
  }
  if (*(int *)(param_2 + 0x20) != 0) {
    FUN_4041e55c((int *)(param_1[0xb] + DAT_404304bc),*(int *)(param_2 + 0x24));
  }
  return;
}



/* 40421a1c FUN_40421a1c */

/* Boundary evidence: original MIPS .pdata 40421a1c..40421ae3. Semantic name remains unreviewed. */

void FUN_40421a1c(int *param_1,int param_2,uint param_3)

{
  ushort uVar1;
  undefined2 uVar2;
  undefined2 extraout_var;
  int iVar3;
  
  if (param_2 == 0) {
    iVar3 = 0;
  }
  else {
    iVar3 = param_2 - DAT_404304bc;
  }
  param_1[8] = iVar3;
  uVar1 = FUN_404156c8(param_2);
  *(short *)(param_1 + 0xd) = (short)(uVar1 + 0xfffe);
  uVar2 = FUN_4040d6bc(param_2);
  *(short *)((int)param_1 + 0x36) = (short)(CONCAT22(extraout_var,uVar2) >> 2) + -1;
  uVar2 = (undefined2)(1 << (uVar1 + 0xfffe & 0x1f));
  FUN_404155c4((int)param_1,uVar2,uVar2);
  iVar3 = FUN_40424d38(param_1,param_2,param_3);
  if (-1 < iVar3) {
    param_1[0xe] = param_3;
    param_1[0xf] = -1;
  }
  return;
}



/* 40421ae4 FUN_40421ae4 */

/* Boundary evidence: original MIPS .pdata 40421ae4..40421b53. Semantic name remains unreviewed. */

int FUN_40421ae4(int param_1,uint param_2,uint param_3,undefined4 *param_4)

{
  int iVar1;
  
  *param_4 = 0;
  iVar1 = FUN_4041e518((int *)param_1,param_2,param_3,param_4);
  if ((iVar1 == 0x302ff) && ((void *)*param_4 != (void *)0x0)) {
    FUN_40421754((void *)*param_4,(uint)*(ushort *)(param_1 + 0x1e));
  }
  return iVar1;
}



/* 40421b54 FUN_40421b54 */

/* Boundary evidence: original MIPS .pdata 40421b54..40421bff. Semantic name remains unreviewed. */

int FUN_40421b54(int *param_1,uint param_2,uint *param_3)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  ushort local_20 [2];
  uint local_1c;
  
  FUN_40421690((int)param_1,param_2,&local_1c,local_20);
  uVar1 = local_1c;
  iVar2 = FUN_40421ae4((int)param_1,local_1c,0,&local_1c);
  if (-1 < iVar2) {
    uVar3 = FUN_404254d8(local_1c,(uint)local_20[0]);
    *param_3 = uVar3;
    FUN_4041e55c(param_1,uVar1);
    if (param_2 == *param_3) {
      iVar2 = -0x7ffcff06;
    }
    else {
      iVar2 = 0;
    }
  }
  return iVar2;
}



/* 40421c00 FUN_40421c00 */

/* Boundary evidence: original MIPS .pdata 40421c00..40421d1b. Semantic name remains unreviewed. */

int FUN_40421c00(int *param_1,uint param_2,uint param_3,uint *param_4)

{
  int iVar1;
  uint uVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  uint local_res4 [3];
  
  iVar4 = 0;
  if (param_3 != 0) {
    local_res4[0] = param_2;
    if (param_1[9] == -2) {
      iVar5 = param_1[8] + DAT_404304bc;
      iVar1 = FUN_404156d0(iVar5);
      uVar2 = FUN_4041e4cc(iVar1);
      if (uVar2 == param_2) {
        piVar3 = (int *)FUN_404156e0(iVar5);
        iVar4 = FUN_40425648(piVar3,param_3,local_res4);
        param_2 = local_res4[0];
        if (iVar4 < 0) {
          return iVar4;
        }
        goto LAB_40421cf0;
      }
    }
    uVar2 = 0;
    if (param_3 != 0) {
      do {
        iVar4 = FUN_40421b54(param_1,param_2,local_res4);
        if (iVar4 < 0) {
          return iVar4;
        }
        param_2 = local_res4[0];
      } while ((local_res4[0] < 0xfffffffb) && (uVar2 = uVar2 + 1, uVar2 < param_3));
    }
  }
LAB_40421cf0:
  *param_4 = param_2;
  return iVar4;
}



/* 40421d1c FUN_40421d1c */

/* Boundary evidence: original MIPS .pdata 40421d1c..40421ea7. Semantic name remains unreviewed. */

int FUN_40421d1c(int *param_1,int *param_2)

{
  undefined2 uVar1;
  undefined2 extraout_var;
  int *piVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  int local_30;
  int local_2c;
  
  iVar4 = param_1[0xe];
  iVar3 = 0;
  iVar5 = 0;
  do {
    if (iVar4 == 0) break;
    iVar4 = iVar4 + -1;
    uVar1 = FUN_404155d0((int)param_1);
    uVar6 = CONCAT22(extraout_var,uVar1);
    iVar3 = FUN_40421ae4((int)param_1,iVar4,0,&local_2c);
    if (iVar3 < 0) {
      return iVar3;
    }
    do {
      if (uVar6 == 0) goto LAB_40421e44;
      uVar6 = uVar6 + 0xffff & 0xffff;
      local_30 = FUN_404254d8(local_2c,uVar6);
      if (param_1[0x10] != 0) {
        if (local_30 != -1) break;
        iVar3 = FUN_404216ac((int)param_1,iVar4,uVar6);
        piVar2 = (int *)FUN_404156e0(param_1[8] + DAT_404304bc);
        iVar3 = FUN_40425f34(piVar2,iVar3,&local_30);
        if (iVar3 < 0) {
          FUN_4041e55c(param_1,iVar4);
          return iVar3;
        }
      }
    } while (local_30 == -1);
    iVar5 = FUN_404216ac((int)param_1,iVar4,uVar6 + 1 & 0xffff);
LAB_40421e44:
    FUN_4041e55c(param_1,iVar4);
  } while (iVar5 == 0);
  *param_2 = iVar5;
  return iVar3;
}



/* 40421ea8 FUN_40421ea8 */

/* Boundary evidence: original MIPS .pdata 40421ea8..40421f47. Semantic name remains unreviewed. */

int FUN_40421ea8(int *param_1,uint *param_2)

{
  int iVar1;
  
  iVar1 = param_1[0xb];
  while (iVar1 != 0) {
    param_1 = (int *)(iVar1 + DAT_404304bc);
    iVar1 = param_1[0xb];
  }
  iVar1 = 0;
  if (param_1[0x13] == 0xfffffffe) {
    iVar1 = FUN_40421d1c(param_1,(int *)param_2);
    if (iVar1 < 0) {
      return iVar1;
    }
  }
  else {
    *param_2 = param_1[0x13];
  }
  if (*param_2 < (uint)param_1[0x12]) {
    *param_2 = param_1[0x12];
  }
  return iVar1;
}



/* 40421f48 FUN_40421f48 */

/* Boundary evidence: original MIPS .pdata 40421f48..40421fb3. Semantic name remains unreviewed. */

int FUN_40421f48(int param_1,uint param_2)

{
  int iVar1;
  uint local_10 [2];
  
  if (((param_2 == 0xfffffffe) || (*(uint *)(param_1 + 0x48) <= param_2)) ||
     ((iVar1 = FUN_40421b54((int *)(*(int *)(param_1 + 0x28) + DAT_404304bc),param_2,local_10),
      -1 < iVar1 && (iVar1 = 1, local_10[0] == 0xffffffff)))) {
    iVar1 = 0;
  }
  return iVar1;
}



/* 40421fb4 FUN_40421fb4 */

/* Boundary evidence: original MIPS .pdata 40421fb4..404220e7. Semantic name remains unreviewed. */

int FUN_40421fb4(int param_1,uint param_2)

{
  int iVar1;
  int *piVar2;
  ushort auStack_28 [2];
  uint local_24;
  uint local_20 [2];
  
  iVar1 = 0;
  local_24 = 0xffffffff;
  if (param_2 < *(uint *)(param_1 + 0x30)) {
    return 1;
  }
  if (*(int *)(param_1 + 0x2c) == 0) {
    if (*(int *)(param_1 + 0x40) != 0) {
      piVar2 = (int *)FUN_404156e0(*(int *)(param_1 + 0x20) + DAT_404304bc);
      iVar1 = FUN_40425f34(piVar2,param_2,(int *)&local_24);
      if (iVar1 < 0) {
        return iVar1;
      }
    }
    if (*(uint *)(param_1 + 0x48) <= param_2) goto LAB_404220b4;
    if (local_24 != 0xffffffff) {
      return 1;
    }
    piVar2 = (int *)(*(int *)(param_1 + 0x28) + DAT_404304bc);
  }
  else {
    piVar2 = (int *)(*(int *)(param_1 + 0x2c) + DAT_404304bc);
    FUN_40421690((int)piVar2,param_2,local_20,auStack_28);
    if ((uint)piVar2[0xe] <= local_20[0]) {
      return 0;
    }
  }
  iVar1 = FUN_40421b54(piVar2,param_2,&local_24);
  if (iVar1 < 0) {
    return iVar1;
  }
LAB_404220b4:
  if (local_24 != 0xffffffff) {
    return 1;
  }
  return iVar1;
}



/* 404220e8 FUN_404220e8 */

/* Boundary evidence: original MIPS .pdata 404220e8..404221ef. Semantic name remains unreviewed. */

int FUN_404220e8(int *param_1,uint param_2,uint *param_3)

{
  bool bVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint local_res4 [3];
  uint local_30;
  
  iVar3 = 0;
  uVar4 = 0;
  bVar1 = false;
  local_res4[0] = param_2;
  uVar2 = FUN_404216ac((int)param_1,param_1[0xe] + 1,0);
  do {
    if (param_2 == 0xfffffffe) {
      *param_3 = uVar4;
      return iVar3;
    }
    uVar5 = param_2;
    if ((bVar1) && (uVar5 = local_30, param_2 == local_30)) {
      return -0x7ffcfef7;
    }
    bVar1 = true;
    iVar3 = FUN_40421b54(param_1,param_2,local_res4);
    if (iVar3 < 0) {
      return iVar3;
    }
    uVar4 = uVar4 + 1;
    param_2 = local_res4[0];
    local_30 = uVar5;
  } while (uVar4 <= uVar2);
  return -0x7ffcfef7;
}



/* 404221f0 FUN_404221f0 */

/* Boundary evidence: original MIPS .pdata 404221f0..40422453. Semantic name remains unreviewed. */

int FUN_404221f0(int *param_1,uint param_2,int param_3)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  ushort *puVar4;
  int iVar5;
  uint uVar6;
  ushort local_30 [2];
  uint local_2c;
  
  FUN_40421690((int)param_1,param_2,&local_2c,local_30);
  uVar1 = local_2c;
  if (((local_2c < (uint)param_1[0xe]) ||
      (uVar2 = FUN_40422d68(param_1,local_2c + 1), -1 < (int)uVar2)) &&
     (uVar2 = FUN_40421ae4((int)param_1,uVar1,1,&local_2c), -1 < (int)uVar2)) {
    uVar6 = (uint)local_30[0];
    iVar3 = FUN_404254d8(local_2c,uVar6);
    FUN_404254e8(local_2c,uVar6,param_3);
    FUN_4041e55c(param_1,uVar1);
    if (param_3 == -1) {
      puVar4 = (ushort *)FUN_40421724((int)param_1,uVar1);
      if ((puVar4 != (ushort *)0x0) && (((*puVar4 & 1) == 1 || (uVar6 < puVar4[1])))) {
        *puVar4 = *puVar4 & 0xfffe;
        puVar4[1] = local_30[0];
      }
      if (param_2 == param_1[0x13] - 1U) {
        param_1[0x13] = -2;
      }
      if (param_2 < (uint)param_1[0x11]) {
        param_1[0x11] = param_2;
      }
      if (param_1[0xf] != -1) {
        uVar2 = FUN_40421fb4((int)param_1,param_2);
        if ((int)uVar2 < 0) {
          return uVar2;
        }
        if (uVar2 != 1) {
          param_1[0xf] = param_1[0xf] + 1;
        }
      }
    }
    else if (param_1[0xb] == 0) {
      if ((uint)param_1[0x13] <= param_2) {
        param_1[0x13] = param_2 + 1;
      }
    }
    else {
      uVar2 = FUN_404221f0((int *)(param_1[0xb] + DAT_404304bc),param_2,param_3);
      if ((int)uVar2 < 0) {
        return uVar2;
      }
    }
    if (((param_1[9] == -4) && (iVar5 = FUN_40421714(param_1[8] + DAT_404304bc), iVar5 != 0)) &&
       ((iVar3 == -1 && ((param_3 != -1 && (param_1[0xf] != -1)))))) {
      param_1[0xf] = param_1[0xf] + -1;
    }
  }
  return uVar2;
}



/* 40422454 FUN_40422454 */

/* Boundary evidence: original MIPS .pdata 40422454..404225ef. Semantic name remains unreviewed. */

int FUN_40422454(int *param_1,int *param_2)

{
  undefined2 uVar1;
  ushort *puVar2;
  int iVar3;
  uint uVar4;
  undefined2 extraout_var;
  int iVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  ushort local_30 [2];
  uint local_2c;
  
  iVar5 = 0;
  iVar8 = 0;
  FUN_40421690((int)param_1,param_1[0x11],&local_2c,local_30);
  if (local_2c < (uint)param_1[0xe]) {
    uVar7 = (uint)local_30[0];
    uVar6 = local_2c;
    do {
      puVar2 = (ushort *)FUN_40421724((int)param_1,uVar6);
      if ((puVar2 == (ushort *)0x0) || ((*puVar2 & 1) == 0)) {
        iVar5 = FUN_40421ae4((int)param_1,uVar6,0,&local_2c);
        if (iVar5 < 0) {
          return iVar5;
        }
        if (puVar2 != (ushort *)0x0) {
          uVar7 = (uint)puVar2[1];
        }
        for (; uVar1 = FUN_404155d0((int)param_1), uVar7 < CONCAT22(extraout_var,uVar1);
            uVar7 = uVar7 + 1 & 0xffff) {
          iVar3 = FUN_404254d8(local_2c,uVar7);
          uVar4 = FUN_404216ac((int)param_1,uVar6,uVar7);
          if (iVar3 == -1) {
            iVar5 = FUN_40421fb4((int)param_1,uVar4);
            if (iVar5 < 0) {
              FUN_4041e55c(param_1,uVar6);
              return iVar5;
            }
            if (iVar5 != 1) {
              iVar8 = iVar8 + 1;
            }
          }
        }
        FUN_4041e55c(param_1,uVar6);
      }
      uVar6 = uVar6 + 1;
      uVar7 = 0;
    } while (uVar6 < (uint)param_1[0xe]);
  }
  *param_2 = iVar8;
  return iVar5;
}



/* 404225f0 FUN_404225f0 */

/* Boundary evidence: original MIPS .pdata 404225f0..40422717. Semantic name remains unreviewed. */

int FUN_404225f0(int *param_1,uint param_2,uint param_3)

{
  int iVar1;
  uint uVar2;
  uint local_res4 [3];
  uint local_20 [2];
  
  if (param_2 == 0xfffffffe) {
LAB_40422628:
    iVar1 = 0;
  }
  else {
    uVar2 = 1;
    local_res4[0] = param_2;
    if (1 < param_3) {
      do {
        iVar1 = FUN_40421b54(param_1,local_res4[0],local_res4);
        if (iVar1 < 0) {
          return iVar1;
        }
        if (local_res4[0] == 0xfffffffe) goto LAB_40422628;
        uVar2 = uVar2 + 1 & 0xffff;
      } while (uVar2 < param_3);
    }
    uVar2 = local_res4[0];
    iVar1 = FUN_40421b54(param_1,local_res4[0],local_res4);
    if (-1 < iVar1) {
      iVar1 = -2;
      if (param_3 == 0) {
        iVar1 = -1;
      }
      iVar1 = FUN_404221f0(param_1,uVar2,iVar1);
      if ((-1 < iVar1) && (uVar2 = local_res4[0], local_res4[0] != 0xfffffffe)) {
        while (iVar1 = FUN_40421b54(param_1,uVar2,local_20), -1 < iVar1) {
          iVar1 = FUN_404221f0(param_1,uVar2,-1);
          if (iVar1 < 0) {
            return iVar1;
          }
          uVar2 = local_20[0];
          if (local_20[0] == 0xfffffffe) {
            return iVar1;
          }
        }
      }
    }
  }
  return iVar1;
}



/* 40422718 FUN_40422718 */

/* Boundary evidence: original MIPS .pdata 40422718..404229e7. Semantic name remains unreviewed. */

int FUN_40422718(int *param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int *piVar4;
  int *piVar5;
  int *piVar6;
  ushort local_30 [2];
  uint local_2c;
  
  param_1[0xf] = param_1[0xf] + -1;
  piVar6 = param_2 + 2;
  piVar4 = param_2 + 8;
  if (*param_2 != 0) {
    *(short *)(*param_2 + 2) = (short)param_2[3] + 1;
  }
  param_1[0x11] = param_2[1] + 1;
  FUN_404254e8(*piVar6,(uint)*(ushort *)(param_2 + 3),0xfffffffe);
  iVar1 = DAT_404304bc;
  if (param_1[0xb] != 0) {
    piVar5 = (int *)(param_1[0xb] + DAT_404304bc);
    FUN_40421690((int)piVar5,param_2[1],&local_2c,local_30);
    uVar3 = local_2c;
    if (*piVar4 != 0) {
      if (param_2[9] != local_2c) {
        FUN_4041e55c(piVar5,param_2[9]);
        *piVar4 = 0;
        iVar1 = DAT_404304bc;
      }
      if (*piVar4 != 0) {
        FUN_404254e8(*piVar4,(uint)local_30[0],0xfffffffe);
        *(int *)(param_1[0xb] + DAT_404304bc + 0x3c) =
             *(int *)(param_1[0xb] + DAT_404304bc + 0x3c) + -1;
        goto LAB_40422860;
      }
    }
    iVar1 = FUN_404221f0((int *)(param_1[0xb] + iVar1),param_2[1],-2);
    if (iVar1 < 0) {
      return iVar1;
    }
    iVar1 = FUN_40421ae4(param_1[0xb] + DAT_404304bc,uVar3,1,piVar4);
    if (iVar1 < 0) {
      return iVar1;
    }
    param_2[9] = uVar3;
  }
LAB_40422860:
  if (((param_2[5] == -2) || (param_2[4] != param_2[6])) &&
     (iVar1 = FUN_40425148(param_1,param_2[4]), iVar1 < 0)) {
    return iVar1;
  }
  uVar3 = param_2[5];
  if (uVar3 != 0xfffffffe) {
    if (param_1[0xb] != 0) {
      piVar5 = (int *)(param_1[0xb] + DAT_404304bc);
      FUN_40421690((int)piVar5,uVar3,&local_2c,local_30);
      if (local_2c == param_2[9]) {
        FUN_404254e8(*piVar4,(uint)local_30[0],param_2[1]);
      }
      else {
        iVar1 = FUN_404221f0(piVar5,uVar3,param_2[1]);
        if (iVar1 < 0) {
          return iVar1;
        }
      }
    }
    iVar1 = param_2[4];
    if (param_2[6] == iVar1) {
      FUN_404254e8(*piVar6,(uint)*(ushort *)(param_2 + 7),param_2[1]);
    }
    else {
      iVar2 = FUN_40421714(param_1[8] + DAT_404304bc);
      if (iVar2 != 0) {
        FUN_4041e55c(param_1,iVar1);
      }
      iVar1 = FUN_40421ae4((int)param_1,param_2[6],1,&local_2c);
      if (iVar1 < 0) {
        return iVar1;
      }
      FUN_404254e8(local_2c,(uint)*(ushort *)(param_2 + 7),param_2[1]);
      FUN_4041e55c(param_1,param_2[6]);
      iVar1 = FUN_40421714(param_1[8] + DAT_404304bc);
      if ((iVar1 != 0) && (iVar1 = FUN_40421ae4((int)param_1,param_2[4],1,piVar6), iVar1 < 0)) {
        return iVar1;
      }
    }
  }
  return 0;
}



/* 404229e8 FUN_404229e8 */

/* Boundary evidence: original MIPS .pdata 404229e8..40422bef. Semantic name remains unreviewed. */

int FUN_404229e8(int *param_1,int *param_2)

{
  ushort uVar1;
  undefined2 uVar2;
  undefined2 extraout_var;
  uint uVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  ushort auStack_28 [2];
  uint local_24;
  
  if (param_2 == (int *)0x0) {
    iVar6 = 0;
  }
  else {
    iVar6 = (int)param_2 - DAT_404304bc;
  }
  param_1[8] = iVar6;
  uVar1 = FUN_404156c8((int)param_2);
  *(short *)(param_1 + 0xd) = (short)(uVar1 + 0xfffe);
  uVar2 = FUN_4040d6bc((int)param_2);
  *(short *)((int)param_1 + 0x36) = (short)(CONCAT22(extraout_var,uVar2) >> 2) + -1;
  uVar2 = (undefined2)(1 << (uVar1 + 0xfffe & 0x1f));
  FUN_404155c4((int)param_1,uVar2,uVar2);
  if (param_1[9] == -4) {
    iVar6 = FUN_404156d0((int)param_2);
    uVar3 = FUN_4040c918(iVar6);
  }
  else {
    iVar6 = FUN_404156d0((int)param_2);
    uVar3 = FUN_4040c910(iVar6);
  }
  iVar4 = FUN_40424d38(param_1,(int)param_2,uVar3);
  if (iVar4 < 0) {
    return iVar4;
  }
  param_1[0xe] = uVar3;
  if (param_1[9] == -2) {
    uVar5 = FUN_4041e4cc(iVar6);
    FUN_40421690((int)param_1,uVar5,&local_24,auStack_28);
    iVar4 = FUN_40421ae4((int)param_1,local_24,2,&local_24);
    if (iVar4 < 0) {
      return iVar4;
    }
    uVar5 = FUN_4041e4cc(iVar6);
    FUN_4041e5c0(param_1,local_24,uVar5);
    FUN_4041e55c(param_1,local_24);
    uVar5 = FUN_4041e4cc(iVar6);
    iVar4 = FUN_404221f0(param_1,uVar5,-3);
    if (iVar4 < 0) {
      return iVar4;
    }
    uVar5 = FUN_404055e4(iVar6);
    iVar4 = FUN_404221f0(param_1,uVar5,-2);
    if (iVar4 < 0) {
      return iVar4;
    }
    param_1[0xf] = (uVar3 << (*(ushort *)(param_1 + 0xd) & 0x1f)) + -2;
  }
  else {
    param_1[0xf] = 0;
  }
  iVar6 = FUN_40421714((int)param_2);
  if (iVar6 == 0) {
    iVar4 = FUN_404157d4(param_2);
  }
  return iVar4;
}



/* 40422bf0 FUN_40422bf0 */

/* Boundary evidence: original MIPS .pdata 40422bf0..40422cab. Semantic name remains unreviewed. */

int FUN_40422bf0(int *param_1,uint param_2,uint param_3)

{
  int iVar1;
  int *piVar2;
  uint local_18 [2];
  
  iVar1 = FUN_40423568(param_1,param_3,local_18,0);
  if (-1 < iVar1) {
    piVar2 = (int *)(param_1[8] + DAT_404304bc);
    iVar1 = FUN_40421714((int)piVar2);
    if ((iVar1 == 0) && (iVar1 = FUN_404157d4(piVar2), iVar1 < 0)) {
      FUN_404225f0(param_1,local_18[0],0);
    }
    else {
      iVar1 = FUN_404221f0(param_1,param_2,local_18[0]);
    }
  }
  return iVar1;
}



/* 40422cac FUN_40422cac */

/* Boundary evidence: original MIPS .pdata 40422cac..40422d67. Semantic name remains unreviewed. */

int FUN_40422cac(int *param_1,uint param_2,uint param_3,uint *param_4)

{
  int iVar1;
  uint uVar2;
  uint local_20 [2];
  
  iVar1 = 0;
  uVar2 = 0;
  if (param_3 != 0) {
    do {
      iVar1 = FUN_40421b54(param_1,param_2,local_20);
      if (iVar1 < 0) {
        return iVar1;
      }
      if (local_20[0] == 0xfffffffe) {
        iVar1 = FUN_40422bf0(param_1,param_2,param_3 - uVar2);
        if (iVar1 < 0) {
          return iVar1;
        }
      }
      else {
        uVar2 = uVar2 + 1;
        param_2 = local_20[0];
      }
    } while (uVar2 < param_3);
  }
  *param_4 = param_2;
  return iVar1;
}



/* 40422d68 FUN_40422d68 */

/* Boundary evidence: original MIPS .pdata 40422d68..404232ab. Semantic name remains unreviewed. */

uint FUN_40422d68(int *param_1,uint param_2)

{
  ushort uVar1;
  undefined2 uVar2;
  int *piVar3;
  int iVar4;
  uint uVar5;
  undefined2 extraout_var;
  uint uVar6;
  undefined2 extraout_var_00;
  uint uVar7;
  uint uVar8;
  int iVar9;
  int *piVar10;
  int iVar11;
  uint local_30;
  uint local_2c;
  
  uVar8 = param_1[0xe];
  if (param_2 == uVar8) {
    return 0;
  }
  uVar1 = *(ushort *)(param_1 + 0xd);
  if (0xfffffffaU >> (uVar1 & 0x1f) < param_2) {
    return 0x80030111;
  }
  iVar9 = param_1[8] + DAT_404304bc;
  piVar3 = (int *)FUN_404156d8(iVar9);
  iVar4 = FUN_40421714(iVar9);
  iVar11 = 2;
  if ((iVar4 == 0) && (param_1[9] == -2)) {
    uVar7 = (1 << (uVar1 & 0x1f)) - 1;
    if (uVar7 == 0) {
      trap(0x1c00);
    }
    uVar5 = FUN_40421ea8(param_1,&local_2c);
    if ((int)uVar5 < 0) {
      return uVar5;
    }
    if (param_1[0x12] == 0) {
      iVar11 = 1;
    }
    piVar10 = (int *)(param_1[8] + DAT_404304bc);
    uVar2 = FUN_404156c8((int)piVar10);
    uVar7 = FUN_404157c4((((uVar7 + (param_2 - uVar8)) - 1) / uVar7 + (param_2 - uVar8)) * iVar11 +
                         local_2c,0,CONCAT22(extraout_var,uVar2));
    uVar6 = FUN_4042171c((int)piVar10);
    if (uVar7 <= uVar6) goto LAB_40422eec;
    piVar10 = (int *)FUN_4040d6c4(piVar10);
    uVar5 = (**(code **)(*piVar10 + 0x18))(piVar10);
  }
  else {
    uVar5 = local_2c;
    if (param_1[9] == -2) goto LAB_40422eec;
    if (uVar8 == 0) {
      uVar5 = FUN_40424340(piVar3,param_2,&local_30);
      if ((int)uVar5 < 0) {
        return uVar5;
      }
      iVar4 = FUN_404156d0(param_1[8] + DAT_404304bc);
      FUN_40421650(iVar4,local_30);
    }
    else {
      iVar4 = FUN_404156d0(iVar9);
      local_30 = FUN_4041e4d4(iVar4);
      uVar5 = FUN_40422cac(piVar3,local_30,param_2 - 1,&local_2c);
      if ((int)uVar5 < 0) {
        return uVar5;
      }
    }
    piVar10 = (int *)(param_1[8] + DAT_404304bc);
    iVar4 = FUN_40421714((int)piVar10);
    if ((iVar4 == 0) && (uVar5 = FUN_404157d4(piVar10), (int)uVar5 < 0)) {
      return uVar5;
    }
    uVar5 = FUN_40421c00(piVar3,local_30,uVar8,&local_30);
  }
  if ((int)uVar5 < 0) {
    return uVar5;
  }
LAB_40422eec:
  FUN_40424a24((int)param_1,param_2);
  while (uVar8 < param_2) {
    uVar5 = FUN_40421ae4((int)param_1,uVar8,2,&local_2c);
    if ((int)uVar5 < 0) {
      return uVar5;
    }
    uVar7 = uVar8 + 1;
    param_1[0xe] = uVar7;
    if (param_1[9] == -2) {
      if (param_1[0xb] == 0) {
        param_1[0xf] = (1 << (*(ushort *)(param_1 + 0xd) & 0x1f)) + param_1[0xf];
        uVar5 = FUN_40423568(piVar3,1,&local_30,0);
        if ((int)uVar5 < 0) {
          return uVar5;
        }
        uVar5 = FUN_404221f0(piVar3,local_30,-3);
        if ((int)uVar5 < 0) {
          return uVar5;
        }
      }
      else {
        uVar5 = FUN_40423568(param_1,1,&local_30,1);
        if ((int)uVar5 < 0) {
          return uVar5;
        }
        iVar4 = FUN_404156e0(param_1[8] + DAT_404304bc);
        FUN_404216bc(iVar4,local_30,0xfffffffd,0xfffffffe);
        if (param_1[0xf] != -1) {
          uVar5 = FUN_404216ac((int)param_1,uVar8,0);
          uVar2 = FUN_404155d0((int)param_1);
          uVar6 = CONCAT22(extraout_var_00,uVar2) + uVar5;
          for (; uVar5 < uVar6; uVar5 = uVar5 + 1) {
            iVar4 = FUN_40421fb4((int)param_1,uVar5);
            if (iVar4 == 0) {
              param_1[0xf] = param_1[0xf] + 1;
            }
          }
        }
      }
      piVar10 = (int *)FUN_404156e0(param_1[8] + DAT_404304bc);
      uVar5 = FUN_40426a08(piVar10,uVar8,local_30);
      if ((int)uVar5 < 0) {
        return uVar5;
      }
    }
    FUN_4041e5c0(param_1,uVar8,local_30);
    FUN_4041e55c(param_1,uVar8);
    uVar8 = uVar7;
    if (param_1[9] == -4) {
      param_1[0xf] = (1 << (*(ushort *)(param_1 + 0xd) & 0x1f)) + param_1[0xf];
      uVar5 = FUN_40421b54(piVar3,local_30,&local_30);
      if ((int)uVar5 < 0) {
        return uVar5;
      }
    }
  }
  if (param_1[9] == -4) {
    iVar4 = FUN_404156d0(param_1[8] + DAT_404304bc);
    FUN_40421628(iVar4,param_1[0xe]);
  }
  else {
    iVar4 = FUN_404156d0(param_1[8] + DAT_404304bc);
    FUN_40421614(iVar4,param_1[0xe]);
  }
  piVar3 = (int *)(param_1[8] + DAT_404304bc);
  iVar4 = FUN_40421714((int)piVar3);
  if ((iVar4 == 0) && (uVar5 = FUN_404157d4(piVar3), (int)uVar5 < 0)) {
    return uVar5;
  }
  if (param_1[0xb] == 0) {
    return uVar5;
  }
  if (param_1[0xf] != -1) {
    return uVar5;
  }
  uVar8 = FUN_40422454(param_1,param_1 + 0xf);
  return uVar8;
}



/* 404232ac FUN_404232ac */

/* Boundary evidence: original MIPS .pdata 404232ac..40423567. Semantic name remains unreviewed. */

uint FUN_404232ac(int *param_1,int *param_2,int param_3)

{
  ushort uVar1;
  undefined2 uVar2;
  undefined2 extraout_var;
  undefined2 extraout_var_00;
  uint uVar3;
  int iVar4;
  undefined4 uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint _Size;
  int iVar10;
  uint uVar11;
  int local_4c;
  void *local_48;
  int local_44;
  uint local_40;
  int *local_3c;
  uint local_38;
  uint local_34;
  uint local_30;
  
  iVar10 = DAT_404304bc;
  local_44 = param_3;
  local_3c = param_2;
  uVar1 = FUN_4040d6bc(param_2[8] + DAT_404304bc);
  _Size = CONCAT22(extraout_var,uVar1);
  local_38 = _Size;
  uVar2 = FUN_4040d6bc(param_1[8] + iVar10);
  if (_Size == 0) {
    trap(0x1c00);
  }
  if ((_Size == 0xffffffff) && (CONCAT22(extraout_var_00,uVar2) == -0x80000000)) {
    trap(0x1800);
  }
  uVar6 = CONCAT22(extraout_var_00,uVar2) / (int)_Size & 0xffff;
  uVar8 = param_2[0xe];
  uVar11 = ((uVar6 + uVar8) - 1) / uVar6;
  if (uVar6 == 0) {
    trap(0x1c00);
  }
  param_1[10] = (int)param_2 - iVar10;
  uVar3 = uVar8;
  local_40 = uVar6;
  local_30 = uVar8;
  if ((uVar11 <= (uint)param_1[0xe]) || (uVar3 = FUN_40422d68(param_1,uVar11), -1 < (int)uVar3)) {
    uVar7 = 0;
    uVar11 = _Size;
    if (uVar8 != 0) {
      do {
        uVar8 = FUN_40421ae4((int)param_2,uVar7,0,&local_48);
        if ((int)uVar8 < 0) {
          return uVar8;
        }
        local_34 = uVar7 / uVar6;
        if (uVar6 == 0) {
          trap(0x1c00);
        }
        if (uVar6 == 0) {
          trap(0x1c00);
        }
        uVar8 = (uint)(short)((short)(uVar7 % uVar6) * (short)uVar11);
        uVar3 = FUN_40421ae4((int)param_1,local_34,1,&local_4c);
        if ((int)uVar3 < 0) {
          return uVar3;
        }
        if (param_3 == 0) {
          if (_Size >> 2 != 0) {
            uVar9 = 0;
            iVar10 = local_4c;
            do {
              uVar6 = uVar9 + (uVar8 >> 2) & 0xffff;
              iVar4 = FUN_404254d8(iVar10,uVar6);
              if (iVar4 != -5) {
                uVar5 = FUN_404254d8((int)local_48,uVar9);
                FUN_404254e8(iVar10,uVar6,uVar5);
                iVar10 = local_4c;
              }
              uVar9 = uVar9 + 1 & 0xffff;
              param_2 = local_3c;
              uVar11 = local_38;
              uVar6 = local_40;
            } while (uVar9 < _Size >> 2);
          }
          _Size = (uint)uVar1;
          param_3 = local_44;
        }
        else {
          memcpy((void *)(uVar8 + local_4c),local_48,_Size);
        }
        FUN_4041e55c(param_1,local_34);
        FUN_4041e55c(param_2,uVar7);
        uVar7 = uVar7 + 1;
      } while (uVar7 < local_30);
    }
    FUN_404156f0((int)param_1);
    param_1[0xf] = -1;
    param_1[0x11] = 0;
    param_1[0x12] = 0;
    param_1[0x13] = -2;
  }
  return uVar3;
}



/* 40423568 FUN_40423568 */

/* Boundary evidence: original MIPS .pdata 40423568..404238db. Semantic name remains unreviewed. */

int FUN_40423568(int *param_1,uint param_2,uint *param_3,int param_4)

{
  undefined2 uVar1;
  uint uVar2;
  undefined2 extraout_var;
  int iVar3;
  undefined2 extraout_var_00;
  uint uVar4;
  uint *puVar5;
  ushort local_58 [2];
  uint local_54;
  ushort *local_50;
  uint local_4c;
  int local_48;
  ushort local_44;
  uint local_40;
  uint local_3c;
  uint local_38;
  ushort local_34;
  
  FUN_404219a0(param_1,(int)&local_50);
  *param_3 = 0xfffffffe;
  if ((param_4 != 0) && (param_1[0xb] != 0)) {
    uVar2 = FUN_40423568((int *)(param_1[0xb] + DAT_404304bc),1,param_3,0);
    if ((int)uVar2 < 0) {
LAB_4042389c:
      FUN_404219b8(param_1,(int)&local_50);
    }
    else {
      if (param_1[0xf] != -1) {
        param_1[0xf] = param_1[0xf] + -1;
      }
      param_1[0x10] = param_1[0x10] + 1;
      if ((uint)param_1[0x13] <= *param_3) {
        param_1[0x13] = *param_3 + 1;
      }
      uVar2 = 0;
    }
    return uVar2;
  }
  puVar5 = (uint *)(param_1 + 0xf);
  do {
    if (*puVar5 != 0xffffffff) goto LAB_404236a8;
    uVar2 = FUN_40422454(param_1,(int *)puVar5);
    while( true ) {
      if ((int)uVar2 < 0) goto LAB_4042389c;
LAB_404236a8:
      if (param_2 <= *puVar5) break;
      uVar1 = FUN_404155d0((int)param_1);
      uVar2 = FUN_40422d68(param_1,((CONCAT22(extraout_var,uVar1) + (param_2 - *puVar5)) - 1 >>
                                   (*(ushort *)(param_1 + 0xd) & 0x1f)) + param_1[0xe]);
    }
    FUN_40421690((int)param_1,param_1[0x11],&local_54,local_58);
    local_40 = local_54;
    if (local_54 < (uint)param_1[0xe]) {
      uVar4 = (uint)local_58[0];
      uVar2 = local_54;
      do {
        local_40 = uVar2;
        local_50 = (ushort *)FUN_40421724((int)param_1,uVar2);
        if ((local_50 == (ushort *)0x0) || ((*local_50 & 1) == 0)) {
          uVar2 = FUN_40421ae4((int)param_1,uVar2,0,&local_48);
          if ((int)uVar2 < 0) goto LAB_4042389c;
          if (local_50 != (ushort *)0x0) {
            uVar4 = (uint)local_50[1];
          }
          while( true ) {
            local_44 = (ushort)uVar4;
            uVar1 = FUN_404155d0((int)param_1);
            if (CONCAT22(extraout_var_00,uVar1) <= uVar4) break;
            iVar3 = FUN_404254d8(local_48,uVar4);
            local_4c = FUN_404216ac((int)param_1,local_40,uVar4);
            if (iVar3 == -1) {
              uVar2 = FUN_40421fb4((int)param_1,local_4c);
              if (uVar2 != 0) {
                uVar4 = (uint)local_44;
                goto LAB_404237f4;
              }
              if (param_4 == 0) {
                uVar2 = FUN_40422718(param_1,(int *)&local_50);
                if ((int)uVar2 < 0) goto LAB_4042389c;
              }
              else {
                param_1[0x10] = param_1[0x10] + 1;
                *puVar5 = *puVar5 - 1;
              }
              if (*param_3 == 0xfffffffe) {
                *param_3 = local_4c;
              }
              param_2 = param_2 - 1;
              if (param_2 == 0) {
                if ((uint)param_1[0x13] <= local_4c) {
                  param_1[0x13] = local_4c + 1;
                }
                uVar2 = 0;
                goto LAB_4042389c;
              }
              uVar4 = (uint)local_44;
              local_3c = local_4c;
              local_38 = local_40;
              local_34 = local_44;
            }
            else {
LAB_404237f4:
              if ((int)uVar2 < 0) goto LAB_4042389c;
            }
            uVar4 = uVar4 + 1 & 0xffff;
          }
          FUN_4041e55c(param_1,local_40);
          uVar2 = local_40;
          if (local_50 != (ushort *)0x0) {
            *local_50 = *local_50 | 1;
          }
        }
        uVar2 = uVar2 + 1;
        uVar4 = 0;
        local_58[0] = 0;
        local_40 = uVar2;
      } while (uVar2 < (uint)param_1[0xe]);
    }
    if ((uint)param_1[0x13] <= local_3c) {
      param_1[0x13] = local_3c + 1;
    }
  } while( true );
}



/* 404238dc FUN_404238dc */

/* Boundary evidence: original MIPS .pdata 404238dc..40423c63. Semantic name remains unreviewed. */

uint FUN_404238dc(int *param_1,uint param_2,int param_3,uint param_4,uint *param_5)

{
  uint uVar1;
  undefined2 uVar2;
  uint uVar3;
  undefined2 extraout_var;
  undefined2 extraout_var_00;
  undefined2 extraout_var_01;
  uint uVar4;
  int iVar5;
  uint uVar6;
  int *piVar7;
  int *piVar8;
  uint *puVar9;
  ushort local_60 [2];
  uint local_5c;
  int local_58;
  ushort *local_50;
  uint local_4c;
  int local_48;
  ushort local_44;
  uint local_40;
  uint local_3c;
  uint local_38;
  ushort local_34 [6];
  
  local_58 = param_3;
  FUN_404219a0(param_1,(int)&local_50);
  iVar5 = param_4 * 0xc + param_3;
  local_3c = (*(int *)(iVar5 + 8) + *(int *)(iVar5 + 4)) - 1;
  FUN_40421690((int)param_1,local_3c,&local_38,local_34);
  uVar1 = local_38;
  puVar9 = (uint *)(param_1 + 0xf);
  do {
    if (*puVar9 != 0xffffffff) goto LAB_404239c8;
    uVar3 = FUN_40422454(param_1,(int *)puVar9);
    while( true ) {
      if ((int)uVar3 < 0) goto LAB_40423c24;
LAB_404239c8:
      if (param_2 <= *puVar9) break;
      uVar2 = FUN_404155d0((int)param_1);
      uVar3 = FUN_40422d68(param_1,((CONCAT22(extraout_var,uVar2) + (param_2 - *puVar9)) - 1 >>
                                   (*(ushort *)(param_1 + 0xd) & 0x1f)) + param_1[0xe]);
    }
    FUN_40421690((int)param_1,param_1[0x11],&local_5c,local_60);
    local_40 = local_5c;
    if (local_5c < (uint)param_1[0xe]) {
      uVar6 = (uint)local_60[0];
      uVar3 = local_5c;
      do {
        local_40 = uVar3;
        local_50 = (ushort *)FUN_40421724((int)param_1,uVar3);
        if ((local_50 == (ushort *)0x0) || ((*local_50 & 1) == 0)) {
          uVar3 = FUN_40421ae4((int)param_1,uVar3,(uint)(uVar3 == uVar1),&local_48);
          if ((int)uVar3 < 0) {
LAB_40423c24:
            FUN_404219b8(param_1,(int)&local_50);
            return uVar3;
          }
          if (local_50 != (ushort *)0x0) {
            uVar6 = (uint)local_50[1];
          }
          local_44 = (ushort)uVar6;
          uVar2 = FUN_404155d0((int)param_1);
          if (uVar6 < CONCAT22(extraout_var_00,uVar2)) {
            piVar7 = (int *)(param_4 * 0xc + param_3 + -4);
            do {
              iVar5 = FUN_404254d8(local_48,uVar6);
              local_4c = FUN_404216ac((int)param_1,local_40,uVar6);
              if (iVar5 == -1) {
                uVar3 = FUN_40421fb4((int)param_1,local_4c);
                if (uVar3 != 0) {
                  uVar6 = (uint)local_44;
                  goto LAB_40423b6c;
                }
                uVar3 = FUN_40422718(param_1,(int *)&local_50);
                if ((int)uVar3 < 0) goto LAB_40423c24;
                param_2 = param_2 - 1;
                piVar8 = piVar7;
                if (param_4 < 0x20) {
                  if (local_4c == local_3c + 1) {
                    piVar7[3] = piVar7[3] + 1;
                  }
                  else {
                    param_4 = param_4 + 1;
                    piVar8 = piVar7 + 3;
                    if (param_4 < 0x20) {
                      piVar7[5] = local_4c;
                      piVar7[4] = piVar7[1] + *piVar8;
                      piVar7[6] = 1;
                    }
                  }
                }
                if (param_2 == 0) {
                  if ((uint)param_1[0x13] <= local_4c) {
                    param_1[0x13] = local_4c + 1;
                  }
                  uVar3 = 0;
                  *param_5 = param_4;
                  goto LAB_40423c24;
                }
                uVar6 = (uint)local_44;
                local_3c = local_4c;
                local_38 = local_40;
                local_34[0] = local_44;
                piVar7 = piVar8;
              }
              else {
LAB_40423b6c:
                if ((int)uVar3 < 0) goto LAB_40423c24;
              }
              uVar4 = uVar6 + 1;
              uVar6 = uVar4 & 0xffff;
              local_44 = (ushort)uVar4;
              uVar2 = FUN_404155d0((int)param_1);
              param_3 = local_58;
            } while (uVar6 < CONCAT22(extraout_var_01,uVar2));
          }
          FUN_4041e55c(param_1,local_40);
          uVar3 = local_40;
          if (local_50 != (ushort *)0x0) {
            *local_50 = *local_50 | 1;
          }
        }
        uVar3 = uVar3 + 1;
        uVar6 = 0;
        local_60[0] = 0;
        local_40 = uVar3;
      } while (uVar3 < (uint)param_1[0xe]);
    }
    if ((uint)param_1[0x13] <= local_3c) {
      param_1[0x13] = local_3c + 1;
    }
  } while( true );
}



/* 40423c64 FUN_40423c64 */

/* Boundary evidence: original MIPS .pdata 40423c64..40423f33. Semantic name remains unreviewed. */

uint FUN_40423c64(int *param_1,undefined4 *param_2,uint param_3,uint param_4,int param_5,
                 int *param_6)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  undefined4 *puVar4;
  int *piVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  ushort local_38 [2];
  uint local_34;
  int local_30;
  uint local_2c;
  
  uVar3 = 0xffffffff;
  local_34 = 0xffffffff;
  param_2[1] = param_4;
  uVar8 = 0;
  param_2[2] = 1;
  *param_2 = 0;
  iVar10 = 1;
  uVar6 = 0;
  uVar9 = param_5 - 1;
  local_2c = param_3;
  do {
    FUN_40421690((int)param_1,param_4,&local_34,local_38);
    uVar1 = local_34;
    if (local_34 != uVar3) {
      if (uVar3 != 0xffffffff) {
        FUN_4041e55c(param_1,uVar3);
      }
      uVar8 = FUN_40421ae4((int)param_1,uVar1,0,&local_30);
      uVar3 = uVar1;
      if ((int)uVar8 < 0) {
        return uVar8;
      }
    }
    uVar2 = FUN_404254d8(local_30,(uint)local_38[0]);
    if (uVar2 == 0xfffffffe) {
      if ((uVar9 != 0) && (local_2c != 0)) {
        if (uVar1 != 0xffffffff) {
          FUN_4041e55c(param_1,uVar1);
        }
        param_2[uVar6 * 3 + 2] = iVar10;
        uVar6 = FUN_404238dc(param_1,uVar9,(int)param_2,uVar6,&local_2c);
        if ((int)uVar6 < 0) {
          return uVar6;
        }
        if (local_2c == 0x20) {
          param_2[0x60] = 0;
          param_2[0x62] = 0;
          param_2[0x61] = 0xffffffff;
        }
        else {
          param_2[local_2c * 3 + 4] = 0xfffffffe;
        }
        *param_6 = local_2c + 1;
        return 0;
      }
      break;
    }
    if (uVar2 == param_4 + 1) {
      iVar10 = iVar10 + 1;
    }
    else {
      if (uVar9 == 0) break;
      uVar7 = uVar6 + 1 & 0xffff;
      param_2[uVar6 * 3 + 2] = iVar10;
      piVar5 = param_2 + uVar7 * 3;
      piVar5[1] = uVar2;
      *piVar5 = piVar5[-3] + iVar10;
      iVar10 = 1;
      uVar6 = uVar7;
    }
    if (uVar9 != 0) {
      uVar9 = uVar9 - 1;
    }
    param_4 = uVar2;
  } while (uVar6 < 0x20);
  if (uVar1 != 0xffffffff) {
    FUN_4041e55c(param_1,uVar1);
  }
  if (uVar6 < 0x20) {
    param_2[uVar6 * 3 + 2] = iVar10;
    param_2[uVar6 * 3 + 4] = 0xfffffffe;
  }
  else {
    puVar4 = param_2 + uVar6 * 3;
    *puVar4 = 0;
    puVar4[2] = 0;
    puVar4[1] = 0xffffffff;
  }
  *param_6 = uVar6 + 1;
  return uVar8;
}



/* 40423f34 FUN_40423f34 */

/* Boundary evidence: original MIPS .pdata 40423f34..40423fdf. Semantic name remains unreviewed. */

uint FUN_40423f34(int *param_1,uint param_2)

{
  undefined2 uVar1;
  uint uVar2;
  undefined2 extraout_var;
  uint *puVar3;
  uint uVar4;
  
  puVar3 = (uint *)(param_1 + 0xf);
  uVar2 = 0;
  if (*puVar3 != 0xffffffff) goto LAB_40423fb4;
  uVar2 = FUN_40422454(param_1,(int *)puVar3);
  while( true ) {
    if ((int)uVar2 < 0) {
      return uVar2;
    }
LAB_40423fb4:
    uVar4 = *puVar3;
    if (param_2 <= uVar4) break;
    uVar1 = FUN_404155d0((int)param_1);
    uVar2 = FUN_40422d68(param_1,((CONCAT22(extraout_var,uVar1) + (param_2 - uVar4)) - 1 >>
                                 (*(ushort *)(param_1 + 0xd) & 0x1f)) + param_1[0xe]);
  }
  return uVar2;
}



/* 40423fe0 FUN_40423fe0 */

/* Boundary evidence: original MIPS .pdata 40423fe0..4042433f. Semantic name remains unreviewed. */

int FUN_40423fe0(int *param_1,uint param_2,int param_3,uint param_4,uint *param_5,uint *param_6,
                uint *param_7,uint *param_8)

{
  bool bVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  uint local_3c;
  uint local_38;
  int local_34;
  uint local_30 [2];
  
  uVar5 = 0xfffffffe;
  bVar1 = false;
  *param_6 = 0xfffffffe;
  iVar6 = 0;
  uVar7 = 0;
  *param_8 = 0xfffffffe;
  uVar3 = param_2;
  local_34 = param_3;
  if ((param_3 == 0) ||
     ((iVar6 = FUN_40422cac(param_1,param_2,param_3 - 1,&local_38), uVar5 = local_38, -1 < iVar6 &&
      (iVar6 = FUN_40421b54(param_1,local_38,&local_38), uVar3 = local_38, -1 < iVar6)))) {
    local_38 = uVar3;
    *param_5 = local_38;
    bVar1 = false;
    if (param_4 != 0) {
      do {
        uVar3 = local_38;
        param_3 = local_34;
        if (local_38 == 0xfffffffe) break;
        if (uVar7 == param_4 - 1) {
          *param_7 = local_38;
        }
        iVar6 = FUN_40421f48((int)param_1,local_38);
        if (iVar6 < 0) goto LAB_404242f8;
        if (iVar6 == 1) {
          iVar6 = FUN_40423568(param_1,1,&local_3c,0);
          if (((iVar6 < 0) ||
              (((uVar5 != 0xfffffffe &&
                ((iVar6 = FUN_404221f0(param_1,uVar5,local_3c), iVar6 < 0 ||
                 ((param_1[0xb] != 0 &&
                  (iVar6 = FUN_404221f0((int *)(param_1[0xb] + DAT_404304bc),uVar5,local_3c),
                  iVar6 < 0)))))) ||
               (iVar6 = FUN_40421b54(param_1,uVar3,local_30), uVar5 = local_30[0], iVar6 < 0)))) ||
             ((iVar6 = FUN_404221f0(param_1,local_3c,local_30[0]), iVar6 < 0 ||
              (((param_1[0xb] != 0 &&
                (iVar6 = FUN_404221f0((int *)(param_1[0xb] + DAT_404304bc),local_3c,uVar5),
                iVar6 < 0)) || (iVar6 = FUN_404221f0(param_1,uVar3,-1), iVar6 < 0))))))
          goto LAB_404242f8;
          bVar1 = true;
          if (uVar7 == 0) {
            *param_6 = local_3c;
          }
          if (uVar7 == param_4 - 1) {
            *param_8 = local_3c;
          }
          local_38 = local_3c;
          uVar3 = local_3c;
        }
        iVar6 = FUN_40421b54(param_1,uVar3,&local_38);
        if (iVar6 < 0) goto LAB_404242f8;
        uVar7 = uVar7 + 1 & 0xffff;
        uVar5 = uVar3;
        param_3 = local_34;
      } while (uVar7 < param_4);
    }
    iVar4 = DAT_404304bc;
    uVar5 = *param_6;
    if ((uVar5 != 0xfffffffe) && (param_3 == 0)) {
      iVar2 = FUN_404156d0(DAT_404304bc + param_1[8]);
      uVar3 = FUN_404055e4(iVar2);
      if (param_2 == uVar3) {
        FUN_4042163c(iVar2,uVar5);
        iVar4 = DAT_404304bc;
      }
      iVar4 = FUN_404156d0(iVar4 + param_1[8]);
      uVar5 = FUN_4041e4d4(iVar4);
      if (param_2 == uVar5) {
        FUN_40421650(iVar4,*param_6);
      }
    }
  }
LAB_404242f8:
  if ((iVar6 == 0) && (!bVar1)) {
    iVar6 = 1;
  }
  return iVar6;
}



/* 40424340 FUN_40424340 */

/* Boundary evidence: original MIPS .pdata 40424340..4042435b. Semantic name remains unreviewed. */

void FUN_40424340(int *param_1,uint param_2,uint *param_3)

{
  FUN_40423568(param_1,param_2,param_3,0);
  return;
}



/* 4042435c FUN_4042435c */

/* Boundary evidence: original MIPS .pdata 4042435c..404247cf. Semantic name remains unreviewed. */

int FUN_4042435c(int *param_1,int *param_2,uint param_3)

{
  bool bVar1;
  ushort uVar2;
  undefined2 uVar3;
  undefined2 extraout_var;
  undefined2 extraout_var_00;
  int iVar4;
  undefined2 extraout_var_01;
  int *piVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint local_30;
  undefined4 uStack_2c;
  
  if (param_2 == (int *)0x0) {
    iVar6 = 0;
  }
  else {
    iVar6 = (int)param_2 - DAT_404304bc;
  }
  param_1[8] = iVar6;
  uVar2 = FUN_404156c8((int)param_2);
  *(short *)(param_1 + 0xd) = (short)(uVar2 + 0xfffe);
  uVar3 = FUN_4040d6bc((int)param_2);
  *(short *)((int)param_1 + 0x36) = (short)(CONCAT22(extraout_var,uVar3) >> 2) + -1;
  uVar3 = (undefined2)(1 << (uVar2 + 0xfffe & 0x1f));
  FUN_404155c4((int)param_1,uVar3,uVar3);
  if (param_1[9] == -2) {
    iVar6 = FUN_404156d0((int)param_2);
    uVar2 = *(ushort *)(param_1 + 0xd);
    uVar7 = 0;
    do {
      uVar3 = FUN_404155d0((int)param_1);
      iVar4 = FUN_4040c920(iVar6);
      uVar10 = CONCAT22(extraout_var_00,uVar3) + iVar4 + uVar7 + param_3 >> (uVar2 & 0x1f);
      bVar1 = uVar7 != uVar10;
      uVar7 = uVar10;
    } while (bVar1);
    iVar6 = FUN_4040c920(iVar6);
    uVar7 = iVar6 + param_3;
  }
  else {
    uVar3 = FUN_404155d0((int)param_1);
    uVar10 = (CONCAT22(extraout_var_01,uVar3) + param_3) - 1 >> (*(ushort *)(param_1 + 0xd) & 0x1f);
    uVar7 = param_3;
  }
  iVar6 = FUN_40424d38(param_1,(int)param_2,uVar10);
  if (iVar6 < 0) {
    return iVar6;
  }
  if (param_1[9] == -4) {
    piVar5 = (int *)FUN_404156d8((int)param_2);
    iVar6 = FUN_40424340(piVar5,uVar10,&local_30);
    if (iVar6 < 0) {
      return iVar6;
    }
    iVar6 = FUN_404156d0((int)param_2);
    FUN_40421650(iVar6,local_30);
    FUN_40421628(iVar6,uVar10);
  }
  uVar8 = 0;
  if (uVar10 != 0) {
    do {
      iVar6 = FUN_40421ae4((int)param_1,uVar8,2,&uStack_2c);
      if (iVar6 < 0) {
        return iVar6;
      }
      if (param_1[9] == 0xfffffffe) {
        FUN_4041e5c0(param_1,uVar8,uVar8 + uVar7);
        piVar5 = (int *)FUN_404156e0((int)param_2);
        FUN_40426a08(piVar5,uVar8,uVar8 + uVar7);
      }
      else {
        iVar6 = FUN_4041e708((int)param_2,param_1[9],uVar8,&local_30);
        if (iVar6 < 0) {
          return iVar6;
        }
        FUN_4041e5c0(param_1,uVar8,local_30);
      }
      FUN_4041e55c(param_1,uVar8);
      uVar8 = uVar8 + 1;
    } while (uVar8 < uVar10);
  }
  param_1[0xe] = uVar10;
  if (param_1[9] == -4) {
    uVar10 = param_3 - 1;
    uVar7 = 0;
    if (uVar10 != 0) {
      do {
        uVar8 = uVar7 + 1;
        iVar6 = FUN_404221f0(param_1,uVar7,uVar8);
        if (iVar6 < 0) {
          return iVar6;
        }
        uVar7 = uVar8;
      } while (uVar8 < uVar10);
    }
    iVar6 = FUN_404221f0(param_1,uVar10,-2);
    if (iVar6 < 0) {
      return iVar6;
    }
    param_1[0xf] = (param_1[0xe] << (*(ushort *)(param_1 + 0xd) & 0x1f)) - param_3;
  }
  else {
    iVar4 = FUN_404156d0((int)param_2);
    FUN_40421614(iVar4,uVar10);
    if (param_3 < 2) {
      iVar6 = -2;
      uVar8 = 0;
    }
    else {
      uVar9 = param_3 - 2;
      uVar8 = 0;
      if (uVar9 != 0) {
        do {
          uVar11 = uVar8 + 1;
          iVar6 = FUN_404221f0(param_1,uVar8,uVar11);
          if (iVar6 < 0) {
            return iVar6;
          }
          uVar8 = uVar11;
        } while (uVar11 < uVar9);
      }
      iVar6 = FUN_404221f0(param_1,uVar9,-2);
      if (iVar6 < 0) {
        return iVar6;
      }
      uVar8 = param_3 - 1;
      iVar6 = 0;
    }
    iVar6 = FUN_404221f0(param_1,uVar8,iVar6);
    if (iVar6 < 0) {
      return iVar6;
    }
    for (; param_3 < uVar7; param_3 = param_3 + 1) {
      iVar6 = FUN_404221f0(param_1,param_3,-4);
      if (iVar6 < 0) {
        return iVar6;
      }
    }
    uVar8 = 0;
    if (uVar10 != 0) {
      uVar8 = 0;
      do {
        iVar6 = FUN_404221f0(param_1,uVar8 + uVar7,-3);
        if (iVar6 < 0) {
          return iVar6;
        }
        uVar8 = uVar8 + 1 & 0xffff;
      } while (uVar8 < uVar10);
    }
    iVar6 = FUN_404221f0(param_1,uVar8 + uVar7,-2);
    if (iVar6 < 0) {
      return iVar6;
    }
    FUN_4042163c(iVar4,uVar8 + uVar7);
    param_1[0xf] = (((param_1[0xe] << (*(ushort *)(param_1 + 0xd) & 0x1f)) - uVar10) - uVar7) + -1;
  }
  iVar4 = FUN_40421714((int)param_2);
  if (iVar4 == 0) {
    iVar6 = FUN_404157d4(param_2);
  }
  return iVar6;
}



/* 404247d0 FUN_404247d0 */

/* Boundary evidence: original MIPS .pdata 404247d0..40424853. Semantic name remains unreviewed. */

void * FUN_404247d0(int param_1,uint param_2)

{
  int *piVar1;
  void *_Dst;
  
  _Dst = (void *)0x0;
  if (param_2 < 0x40000000) {
    piVar1 = (int *)FUN_4040d71c(*(int *)(param_1 + 0x10) + DAT_404304bc);
    _Dst = (void *)(**(code **)(*piVar1 + 0xc))(piVar1,param_2 << 2);
    if (_Dst != (void *)0x0) {
      memset(_Dst,0,param_2 << 2);
    }
  }
  return _Dst;
}



/* 40424854 FUN_40424854 */

/* Boundary evidence: original MIPS .pdata 40424854..404248b3. Semantic name remains unreviewed. */

undefined4 FUN_40424854(int param_1,uint param_2)

{
  undefined4 uVar1;
  int *piVar2;
  
  if (param_2 < 0x40000000) {
    piVar2 = (int *)FUN_4040d71c(*(int *)(param_1 + 0x10) + DAT_404304bc);
    uVar1 = (**(code **)(*piVar2 + 0xc))(piVar2,param_2 << 2);
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}



/* 404248b4 FUN_404248b4 */

void FUN_404248b4(int param_1)

{
  *(uint *)(param_1 + 0x18) = *(uint *)(param_1 + 0x18) | 1;
  return;
}



/* 404248c4 FUN_404248c4 */

/* Boundary evidence: original MIPS .pdata 404248c4..4042494f. Semantic name remains unreviewed. */

void FUN_404248c4(int param_1)

{
  LPVOID pvVar1;
  
  if (*(int *)(param_1 + 0x10) != 0) {
    if (*(int *)(param_1 + 0x14) == 0) {
      pvVar1 = (LPVOID)0x0;
    }
    else {
      pvVar1 = (LPVOID)(*(int *)(param_1 + 0x14) + DAT_404304bc);
    }
    FUN_40415170(&PTR_PTR_40430324,pvVar1);
    if (*(int *)(param_1 + 0x18) == 0) {
      pvVar1 = (LPVOID)0x0;
    }
    else {
      pvVar1 = (LPVOID)(*(int *)(param_1 + 0x18) + DAT_404304bc);
    }
    FUN_40415170(&PTR_PTR_40430324,pvVar1);
  }
  return;
}



/* 40424950 FUN_40424950 */

/* Boundary evidence: original MIPS .pdata 40424950..40424a23. Semantic name remains unreviewed. */

void FUN_40424950(int *param_1)

{
  int *piVar1;
  int iVar2;
  
  if (*param_1 != 0) {
    FUN_40420cdc(*param_1 + DAT_404304bc,(int)param_1);
  }
  if (param_1[4] != 0) {
    iVar2 = param_1[5] + DAT_404304bc;
    if (param_1[5] == 0) {
      iVar2 = 0;
    }
    piVar1 = (int *)FUN_4040d71c(param_1[4] + DAT_404304bc);
    (**(code **)(*piVar1 + 0x14))(piVar1,iVar2);
    iVar2 = param_1[6] + DAT_404304bc;
    if (param_1[6] == 0) {
      iVar2 = 0;
    }
    piVar1 = (int *)FUN_4040d71c(DAT_404304bc + param_1[4]);
    (**(code **)(*piVar1 + 0x14))(piVar1,iVar2);
  }
  param_1[5] = 0;
  param_1[6] = 0;
  *param_1 = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  return;
}



/* 40424a24 FUN_40424a24 */

/* Boundary evidence: original MIPS .pdata 40424a24..40424d0f. Semantic name remains unreviewed. */

undefined4 FUN_40424a24(int param_1,uint param_2)

{
  undefined4 *puVar1;
  void *pvVar2;
  int *piVar3;
  undefined4 *puVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  
  if (param_2 <= *(uint *)(param_1 + 0xc)) goto LAB_40424ca0;
  uVar8 = param_2;
  if (0x400 < param_2) {
    uVar8 = param_2 + 0x3ff & 0xfffffc00;
  }
  puVar1 = (undefined4 *)FUN_40424854(param_1,uVar8);
  pvVar2 = FUN_404247d0(param_1,uVar8);
  *(uint *)(param_1 + 0xc) = uVar8;
  if ((puVar1 == (undefined4 *)0x0) || (pvVar2 == (void *)0x0)) {
    piVar3 = (int *)FUN_4040d71c(*(int *)(param_1 + 0x10) + DAT_404304bc);
    (**(code **)(*piVar3 + 0x14))(piVar3,pvVar2);
    pvVar2 = (void *)0x0;
    piVar3 = (int *)FUN_4040d71c(*(int *)(param_1 + 0x10) + DAT_404304bc);
    (**(code **)(*piVar3 + 0x14))(piVar3,puVar1);
    puVar1 = (undefined4 *)0x0;
  }
  else if (*(int *)(param_1 + 0x14) == 0) {
LAB_40424b80:
    uVar8 = 0;
    puVar4 = puVar1;
    if (*(int *)(param_1 + 8) != 0) {
      do {
        *puVar4 = 0;
        uVar8 = uVar8 + 1;
        puVar4 = puVar4 + 1;
      } while (uVar8 < *(uint *)(param_1 + 8));
    }
  }
  else if (*(int *)(param_1 + 0x18) == 0) {
    if (*(int *)(param_1 + 0x14) == 0) goto LAB_40424b80;
    uVar8 = 0;
    if (*(int *)(param_1 + 8) != 0) {
      iVar7 = 0;
      do {
        *(undefined4 *)(iVar7 + (int)puVar1) =
             *(undefined4 *)(*(int *)(param_1 + 0x14) + iVar7 + DAT_404304bc);
        uVar8 = uVar8 + 1;
        iVar7 = iVar7 + 4;
      } while (uVar8 < *(uint *)(param_1 + 8));
    }
  }
  else {
    uVar8 = 0;
    if (*(int *)(param_1 + 8) != 0) {
      iVar7 = 0;
      do {
        *(undefined4 *)(((int)puVar1 - (int)pvVar2) + iVar7 + (int)pvVar2) =
             *(undefined4 *)(*(int *)(param_1 + 0x14) + iVar7 + DAT_404304bc);
        uVar8 = uVar8 + 1;
        *(undefined4 *)(iVar7 + (int)pvVar2) =
             *(undefined4 *)(*(int *)(param_1 + 0x18) + iVar7 + DAT_404304bc);
        iVar7 = iVar7 + 4;
      } while (uVar8 < *(uint *)(param_1 + 8));
    }
  }
  iVar7 = *(int *)(param_1 + 0x14) + DAT_404304bc;
  if (*(int *)(param_1 + 0x14) == 0) {
    iVar7 = 0;
  }
  piVar3 = (int *)FUN_4040d71c(*(int *)(param_1 + 0x10) + DAT_404304bc);
  (**(code **)(*piVar3 + 0x14))(piVar3,iVar7);
  if (puVar1 == (undefined4 *)0x0) {
    iVar7 = 0;
  }
  else {
    iVar7 = (int)puVar1 - DAT_404304bc;
  }
  *(int *)(param_1 + 0x14) = iVar7;
  iVar7 = *(int *)(param_1 + 0x18) + DAT_404304bc;
  if (*(int *)(param_1 + 0x18) == 0) {
    iVar7 = 0;
  }
  piVar3 = (int *)FUN_4040d71c(*(int *)(param_1 + 0x10) + DAT_404304bc);
  (**(code **)(*piVar3 + 0x14))(piVar3,iVar7);
  if (pvVar2 == (void *)0x0) {
    iVar7 = 0;
  }
  else {
    iVar7 = (int)pvVar2 - DAT_404304bc;
  }
  *(int *)(param_1 + 0x18) = iVar7;
LAB_40424ca0:
  if ((*(int *)(param_1 + 0x14) != 0) && (uVar8 = *(uint *)(param_1 + 8), uVar8 < param_2)) {
    iVar7 = uVar8 << 2;
    iVar6 = param_2 - uVar8;
    do {
      iVar5 = *(int *)(param_1 + 0x14) + iVar7;
      iVar7 = iVar7 + 4;
      iVar6 = iVar6 + -1;
      *(undefined4 *)(iVar5 + DAT_404304bc) = 0;
    } while (iVar6 != 0);
  }
  *(uint *)(param_1 + 8) = param_2;
  return 0;
}



/* 40424d10 FUN_40424d10 */

int FUN_40424d10(int param_1)

{
  int iVar1;
  
  if (*(int *)(param_1 + 0x208) == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = *(int *)(param_1 + 0x208) + DAT_404304bc;
  }
  return iVar1;
}



/* 40424d38 FUN_40424d38 */

/* Boundary evidence: original MIPS .pdata 40424d38..40424e97. Semantic name remains unreviewed. */

undefined4 FUN_40424d38(int *param_1,int param_2,uint param_3)

{
  undefined4 *puVar1;
  void *pvVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  undefined4 *puVar6;
  uint uVar7;
  
  if (param_2 == 0) {
    iVar5 = 0;
  }
  else {
    iVar5 = param_2 - DAT_404304bc;
  }
  param_1[4] = iVar5;
  iVar4 = DAT_404304bc;
  iVar5 = FUN_40424d10(iVar5 + DAT_404304bc);
  iVar4 = iVar5 - iVar4;
  if (iVar5 == 0) {
    iVar4 = 0;
  }
  *param_1 = iVar4;
  param_1[2] = param_3;
  param_1[3] = param_3;
  if (param_3 != 0) {
    puVar1 = (undefined4 *)FUN_40424854((int)param_1,param_3);
    if (puVar1 != (undefined4 *)0x0) {
      uVar7 = 0;
      puVar6 = puVar1;
      if (param_1[2] != 0) {
        do {
          *puVar6 = 0;
          uVar7 = uVar7 + 1;
          puVar6 = puVar6 + 1;
        } while (uVar7 < (uint)param_1[2]);
      }
      param_1[5] = (int)puVar1 - DAT_404304bc;
      pvVar2 = FUN_404247d0((int)param_1,param_3);
      if (pvVar2 != (void *)0x0) {
        param_1[6] = (int)pvVar2 - DAT_404304bc;
        return 0;
      }
    }
    iVar5 = param_1[5] + DAT_404304bc;
    if (param_1[5] == 0) {
      iVar5 = 0;
    }
    piVar3 = (int *)FUN_4040d71c(param_1[4] + DAT_404304bc);
    (**(code **)(*piVar3 + 0x14))(piVar3,iVar5);
    param_1[5] = 0;
    iVar5 = param_1[6] + DAT_404304bc;
    if (param_1[6] == 0) {
      iVar5 = 0;
    }
    piVar3 = (int *)FUN_4040d71c(param_1[4] + DAT_404304bc);
    (**(code **)(*piVar3 + 0x14))(piVar3,iVar5);
    param_1[6] = 0;
  }
  return 0;
}



/* 40424e98 FUN_40424e98 */

/* Boundary evidence: original MIPS .pdata 40424e98..40425147. Semantic name remains unreviewed. */

uint FUN_40424e98(int *param_1,uint param_2,uint param_3,uint param_4,int *param_5)

{
  bool bVar1;
  undefined3 extraout_var;
  uint uVar2;
  int iVar3;
  int *piVar4;
  uint uVar5;
  int *local_28;
  uint local_24;
  
  if ((uint)param_1[2] <= param_2) {
    return 0x80030009;
  }
  uVar5 = 0x302ff;
  if ((param_1[5] == 0) || (iVar3 = *(int *)(param_2 * 4 + param_1[5] + DAT_404304bc), iVar3 == 0))
  {
    if ((param_3 & 2) == 0) {
      uVar5 = FUN_40421338((int *)(*param_1 + DAT_404304bc),(int)param_1,param_1[1],param_2,param_4,
                           (int *)&local_28);
      if ((int)uVar5 < 0) {
        return uVar5;
      }
    }
    else {
      uVar2 = FUN_40421068((int *)(*param_1 + DAT_404304bc),(int *)&local_28);
      if ((int)uVar2 < 0) {
        return uVar2;
      }
      FUN_4042021c((int)local_28,(int)param_1);
      FUN_40420204((int)local_28,param_1[1]);
      FUN_4042020c((int)local_28,param_2);
      FUN_404204d8(*param_1 + DAT_404304bc,local_28,0xfffffffe);
      param_3 = param_3 & 0xfffffffd | 1;
    }
    if (param_1[5] != 0) {
      iVar3 = (int)local_28 - DAT_404304bc;
      if (local_28 == (int *)0x0) {
        iVar3 = 0;
      }
      *(int *)(param_2 * 4 + param_1[5] + DAT_404304bc) = iVar3;
    }
  }
  else {
    local_28 = (int *)(iVar3 + DAT_404304bc);
    uVar5 = 0;
  }
  if (local_28 == (int *)0x0) {
    return 0x800300fd;
  }
  FUN_404202d8((int)local_28);
  piVar4 = local_28;
  if ((((param_3 & 1) != 0) &&
      (bVar1 = FUN_40420258((int)local_28), CONCAT31(extraout_var,bVar1) == 0)) &&
     (uVar5 != 0x302ff)) {
    uVar5 = FUN_4042016c((int)piVar4);
    iVar3 = FUN_404156d8(param_1[4] + DAT_404304bc);
    uVar5 = FUN_40421f48(iVar3,uVar5);
    if ((int)uVar5 < 0) {
LAB_40425138:
      FUN_4041e4e4((int)local_28);
      return uVar5;
    }
    piVar4 = local_28;
    if (uVar5 == 1) {
      FUN_404204d8(*param_1 + DAT_404304bc,local_28,0xfffffffe);
      piVar4 = local_28;
      uVar5 = FUN_40420164((int)local_28);
      uVar2 = FUN_4042015c((int)piVar4);
      uVar5 = FUN_4041e708(param_1[4] + DAT_404304bc,uVar2,uVar5,&local_24);
      if ((int)uVar5 < 0) goto LAB_40425138;
      FUN_404204d8(*param_1 + DAT_404304bc,local_28,local_24);
      piVar4 = local_28;
    }
  }
  uVar2 = FUN_40420174((int)piVar4);
  FUN_40420214((int)piVar4,uVar2 | param_3 | 0x10000000);
  iVar3 = FUN_4042017c((int)local_28);
  *param_5 = iVar3;
  return uVar5;
}



/* 40425148 FUN_40425148 */

/* Boundary evidence: original MIPS .pdata 40425148..404252fb. Semantic name remains unreviewed. */

int FUN_40425148(int *param_1,int param_2)

{
  bool bVar1;
  undefined3 extraout_var;
  uint uVar2;
  uint uVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  int *local_20;
  uint local_1c;
  
  iVar6 = 0;
  if (param_1[5] == 0) {
    iVar6 = FUN_4042121c((int *)(*param_1 + DAT_404304bc),(int)param_1,param_1[1],param_2,&local_20)
    ;
    if (iVar6 < 0) {
      return iVar6;
    }
  }
  else {
    iVar4 = *(int *)(param_2 * 4 + param_1[5] + DAT_404304bc);
    local_20 = (int *)(iVar4 + DAT_404304bc);
    if (iVar4 == 0) {
      local_20 = (int *)0x0;
    }
  }
  piVar5 = local_20;
  if (local_20 == (int *)0x0) {
    return -0x7ffcff03;
  }
  bVar1 = FUN_40420258((int)local_20);
  if (CONCAT31(extraout_var,bVar1) == 0) {
    FUN_404202d8((int)piVar5);
    uVar2 = FUN_4042016c((int)local_20);
    iVar6 = FUN_404156d8(DAT_404304bc + param_1[4]);
    iVar6 = FUN_40421f48(iVar6,uVar2);
    if (iVar6 < 0) {
LAB_404252ec:
      FUN_4041e4e4((int)local_20);
      return iVar6;
    }
    if (iVar6 == 1) {
      FUN_404204d8(*param_1 + DAT_404304bc,local_20,0xfffffffe);
      piVar5 = local_20;
      uVar2 = FUN_40420164((int)local_20);
      uVar3 = FUN_4042015c((int)piVar5);
      iVar6 = FUN_4041e708(DAT_404304bc + param_1[4],uVar3,uVar2,&local_1c);
      if (iVar6 < 0) goto LAB_404252ec;
      FUN_404204d8(*param_1 + DAT_404304bc,local_20,local_1c);
    }
    FUN_4041e4e4((int)local_20);
    piVar5 = local_20;
  }
  FUN_404248b4((int)piVar5);
  return iVar6;
}



/* 404252fc FUN_404252fc */

/* Boundary evidence: original MIPS .pdata 404252fc..4042547b. Semantic name remains unreviewed. */

void FUN_404252fc(int *param_1,int param_2)

{
  void *pvVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  
  iVar3 = *(int *)(param_2 + 0x10);
  param_1[4] = iVar3;
  iVar4 = DAT_404304bc;
  iVar3 = FUN_40424d10(iVar3 + DAT_404304bc);
  iVar4 = iVar3 - iVar4;
  if (iVar3 == 0) {
    iVar4 = 0;
  }
  *param_1 = iVar4;
  uVar5 = *(uint *)(param_2 + 8);
  param_1[2] = uVar5;
  param_1[3] = uVar5;
  if ((uVar5 != 0) && (iVar4 = FUN_40424854((int)param_1,uVar5), iVar4 != 0)) {
    uVar5 = 0;
    if (param_1[2] != 0) {
      iVar3 = 0;
      do {
        *(int *)(iVar3 + iVar4) = 0;
        if (*(int *)(param_2 + 0x14) != 0) {
          iVar6 = *(int *)(iVar3 + *(int *)(param_2 + 0x14) + DAT_404304bc);
          iVar2 = iVar6 + DAT_404304bc;
          if (iVar6 == 0) {
            iVar2 = 0;
          }
          FUN_40420e60((int *)(*param_1 + DAT_404304bc),(int)param_1,iVar2,(int *)(iVar3 + iVar4));
        }
        uVar5 = uVar5 + 1;
        iVar3 = iVar3 + 4;
      } while (uVar5 < (uint)param_1[2]);
    }
    param_1[5] = iVar4 - DAT_404304bc;
    pvVar1 = FUN_404247d0((int)param_1,param_1[2]);
    if (pvVar1 != (void *)0x0) {
      if ((*(int *)(param_2 + 0x18) != 0) && (uVar5 = 0, param_1[2] != 0)) {
        iVar4 = 0;
        do {
          *(undefined4 *)(iVar4 + (int)pvVar1) =
               *(undefined4 *)(*(int *)(param_2 + 0x18) + iVar4 + DAT_404304bc);
          uVar5 = uVar5 + 1;
          iVar4 = iVar4 + 4;
        } while (uVar5 < (uint)param_1[2]);
      }
      param_1[6] = (int)pvVar1 - DAT_404304bc;
    }
  }
  return;
}



/* 4042547c FUN_4042547c */

undefined4 FUN_4042547c(int param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 0x44) = param_2;
  *(undefined4 *)(param_1 + 0x200) = 1;
  return 0;
}



/* 40425490 FUN_40425490 */

undefined4 FUN_40425490(int param_1,int param_2)

{
  return *(undefined4 *)((param_2 + 0x13) * 4 + param_1);
}



/* 404254a4 FUN_404254a4 */

undefined4 FUN_404254a4(int param_1,int param_2,undefined4 param_3)

{
  *(undefined4 *)((param_2 + 0x13) * 4 + param_1) = param_3;
  *(undefined4 *)(param_1 + 0x200) = 1;
  return 0;
}



/* 404254c4 FUN_404254c4 */

undefined4 FUN_404254c4(int param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 0x48) = param_2;
  *(undefined4 *)(param_1 + 0x200) = 1;
  return 0;
}



/* 404254d8 FUN_404254d8 */

undefined4 FUN_404254d8(int param_1,int param_2)

{
  return *(undefined4 *)(param_2 * 4 + param_1);
}



/* 404254e8 FUN_404254e8 */

void FUN_404254e8(int param_1,int param_2,undefined4 param_3)

{
  *(undefined4 *)(param_2 * 4 + param_1) = param_3;
  return;
}



/* 404254f8 FUN_404254f8 */

void FUN_404254f8(int param_1)

{
  *(undefined4 *)(param_1 + 0x40) = 0;
  return;
}



/* 40425500 FUN_40425500 */

/* Boundary evidence: original MIPS .pdata 40425500..40425583. Semantic name remains unreviewed. */

void FUN_40425500(int param_1,int param_2,uint *param_3,undefined2 *param_4)

{
  undefined2 uVar1;
  undefined2 extraout_var;
  undefined2 extraout_var_00;
  
  uVar1 = FUN_404155d0(param_1);
  if (CONCAT22(extraout_var,uVar1) == 0) {
    trap(0x1c00);
  }
  *param_3 = (param_2 - 0x6dU) / CONCAT22(extraout_var,uVar1);
  uVar1 = FUN_404155d0(param_1);
  if (CONCAT22(extraout_var_00,uVar1) == 0) {
    trap(0x1c00);
  }
  *param_4 = (short)((param_2 - 0x6dU) % CONCAT22(extraout_var_00,uVar1));
  return;
}



/* 40425584 FUN_40425584 */

bool FUN_40425584(int param_1)

{
  return *(int *)(param_1 + 0x480) != 0;
}



/* 4042559c FUN_4042559c */

/* Boundary evidence: original MIPS .pdata 4042559c..404255d7. Semantic name remains unreviewed. */

undefined4 * FUN_4042559c(undefined4 *param_1)

{
  FUN_40421664(param_1,0xfffffffb);
  param_1[8] = 0;
  *(undefined2 *)(param_1 + 0xb) = 0;
  param_1[10] = 0;
  return param_1;
}



/* 404255d8 FUN_404255d8 */

/* Boundary evidence: original MIPS .pdata 404255d8..40425617. Semantic name remains unreviewed. */

undefined4 * FUN_404255d8(undefined4 *param_1)

{
  FUN_40421664(param_1,0xfffffffb);
  param_1[8] = 0;
  param_1[9] = 0;
  *(undefined2 *)(param_1 + 0xb) = 0;
  param_1[10] = 0;
  return param_1;
}



/* 40425618 FUN_40425618 */

/* Boundary evidence: original MIPS .pdata 40425618..40425647. Semantic name remains unreviewed. */

void FUN_40425618(int *param_1)

{
  FUN_40424950(param_1);
  param_1[8] = 0;
  param_1[9] = 0;
  return;
}



/* 40425648 FUN_40425648 */

/* Boundary evidence: original MIPS .pdata 40425648..4042571f. Semantic name remains unreviewed. */

int FUN_40425648(int *param_1,uint param_2,undefined4 *param_3)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  ushort local_20 [2];
  uint local_1c;
  
  iVar4 = 0;
  if (param_2 < 0x6d) {
    iVar2 = FUN_404156d0(param_1[8] + DAT_404304bc);
    uVar3 = FUN_40425490(iVar2,param_2);
  }
  else {
    FUN_40425500((int)param_1,param_2,&local_1c,local_20);
    uVar1 = local_1c;
    iVar4 = FUN_40421ae4((int)param_1,local_1c,0,&local_1c);
    if (iVar4 < 0) {
      return iVar4;
    }
    uVar3 = FUN_404254d8(local_1c,(uint)local_20[0]);
    FUN_4041e55c(param_1,uVar1);
  }
  *param_3 = uVar3;
  return iVar4;
}



/* 40425720 FUN_40425720 */

/* Boundary evidence: original MIPS .pdata 40425720..404257ff. Semantic name remains unreviewed. */

int FUN_40425720(int *param_1,uint param_2,undefined4 *param_3)

{
  undefined2 uVar1;
  int iVar2;
  uint uVar3;
  undefined2 extraout_var;
  uint uVar4;
  uint uVar5;
  int local_28 [2];
  
  uVar4 = 0;
  iVar2 = FUN_404156d0(param_1[8] + DAT_404304bc);
  uVar3 = FUN_4041e4dc(iVar2);
  uVar5 = 0;
  if (param_2 != 0) {
    do {
      uVar4 = FUN_40424e98(param_1,uVar5,0,uVar3,local_28);
      if ((int)uVar4 < 0) {
        return uVar4;
      }
      uVar1 = FUN_404155d0((int)param_1);
      uVar3 = FUN_404254d8(local_28[0],CONCAT22(extraout_var,uVar1));
      FUN_4041e55c(param_1,uVar5);
      uVar5 = uVar5 + 1;
    } while (uVar5 < param_2);
  }
  *param_3 = uVar3;
  return uVar4;
}



/* 40425800 FUN_40425800 */

/* Boundary evidence: original MIPS .pdata 40425800..40425897. Semantic name remains unreviewed. */

void FUN_40425800(int *param_1,int param_2,uint param_3)

{
  short sVar1;
  undefined2 uVar2;
  undefined2 extraout_var;
  int iVar3;
  
  if (param_2 == 0) {
    iVar3 = 0;
  }
  else {
    iVar3 = param_2 - DAT_404304bc;
  }
  param_1[8] = iVar3;
  uVar2 = FUN_4040d6bc(param_2);
  sVar1 = (short)(CONCAT22(extraout_var,uVar2) >> 2);
  FUN_404155c4((int)param_1,sVar1,sVar1 + -1);
  iVar3 = FUN_40424d38(param_1,param_2,param_3);
  if (-1 < iVar3) {
    param_1[9] = param_3;
  }
  return;
}



/* 40425898 FUN_40425898 */

/* Boundary evidence: original MIPS .pdata 40425898..4042591f. Semantic name remains unreviewed. */

undefined4 FUN_40425898(int *param_1,int param_2)

{
  short sVar1;
  undefined2 uVar2;
  undefined2 extraout_var;
  int iVar3;
  
  if (param_2 == 0) {
    iVar3 = 0;
  }
  else {
    iVar3 = param_2 - DAT_404304bc;
  }
  param_1[8] = iVar3;
  uVar2 = FUN_4040d6bc(param_2);
  sVar1 = (short)(CONCAT22(extraout_var,uVar2) >> 2);
  FUN_404155c4((int)param_1,sVar1,sVar1 + -1);
  FUN_40424d38(param_1,param_2,0);
  param_1[9] = 0;
  return 0;
}



/* 40425920 FUN_40425920 */

/* Boundary evidence: original MIPS .pdata 40425920..40425b03. Semantic name remains unreviewed. */

int FUN_40425920(int *param_1,int param_2,uint param_3)

{
  short sVar1;
  uint uVar2;
  undefined2 uVar3;
  undefined2 extraout_var;
  undefined2 extraout_var_00;
  int iVar4;
  undefined2 extraout_var_01;
  uint uVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  undefined2 auStack_28 [2];
  uint local_24;
  
  if (param_2 == 0) {
    iVar6 = 0;
  }
  else {
    iVar6 = param_2 - DAT_404304bc;
  }
  param_1[8] = iVar6;
  uVar3 = FUN_4040d6bc(param_2);
  uVar5 = CONCAT22(extraout_var,uVar3) >> 2;
  local_24 = 0;
  uVar8 = 0;
  do {
    uVar7 = uVar8;
    uVar2 = local_24;
    uVar8 = (uVar5 + local_24 + uVar7 + param_3) / uVar5;
    if (uVar5 == 0) {
      trap(0x1c00);
    }
    if (uVar8 < 0x6d) {
      local_24 = 0;
    }
    else {
      FUN_40425500((int)param_1,uVar8,&local_24,auStack_28);
      local_24 = local_24 + 1;
    }
  } while ((local_24 != uVar2) || (uVar8 != uVar7));
  param_1[9] = local_24;
  uVar3 = FUN_4040d6bc(param_2);
  sVar1 = (short)(CONCAT22(extraout_var_00,uVar3) >> 2);
  FUN_404155c4((int)param_1,sVar1,sVar1 + -1);
  iVar6 = FUN_40424d38(param_1,param_2,param_1[9]);
  if (-1 < iVar6) {
    iVar4 = FUN_404156d0(param_2);
    FUN_404254c4(iVar4,param_1[9]);
    if (param_1[9] != 0) {
      FUN_4042547c(iVar4,param_3);
      uVar8 = 0;
      if (param_1[9] != 0) {
        do {
          iVar6 = FUN_40421ae4((int)param_1,uVar8,2,&local_24);
          if (iVar6 < 0) {
            return iVar6;
          }
          FUN_4041e5c0(param_1,uVar8,param_3);
          param_3 = param_3 + 1;
          uVar3 = FUN_404155d0((int)param_1);
          FUN_404254e8(local_24,CONCAT22(extraout_var_01,uVar3),param_3);
          FUN_4041e55c(param_1,uVar8);
          uVar8 = uVar8 + 1;
        } while (uVar8 < (uint)param_1[9]);
      }
    }
  }
  return iVar6;
}



/* 40425b04 FUN_40425b04 */

/* Boundary evidence: original MIPS .pdata 40425b04..40425d3b. Semantic name remains unreviewed. */

int FUN_40425b04(int *param_1)

{
  undefined2 uVar1;
  int iVar2;
  int *piVar3;
  undefined4 uVar4;
  undefined2 extraout_var;
  undefined2 extraout_var_00;
  int iVar5;
  uint uVar6;
  uint local_28;
  int local_24;
  undefined4 auStack_20 [2];
  
  uVar6 = 1;
  iVar2 = local_24;
  if (param_1[9] != 0) {
    iVar2 = FUN_40421ae4((int)param_1,0,1,&local_24);
    if (iVar2 < 0) {
      return iVar2;
    }
    piVar3 = (int *)FUN_404156d8(param_1[8] + DAT_404304bc);
    iVar2 = FUN_40423568(piVar3,1,&local_28,1);
    if (iVar2 < 0) {
      iVar5 = 0;
LAB_40425d10:
      FUN_4041e55c(param_1,iVar5);
      return iVar2;
    }
    iVar5 = FUN_404156d0(param_1[8] + DAT_404304bc);
    uVar4 = FUN_4041e4dc(iVar5);
    FUN_404216bc((int)param_1,local_28,0xfffffffc,uVar4);
    iVar5 = FUN_404156d0(param_1[8] + DAT_404304bc);
    FUN_4042547c(iVar5,local_28);
    FUN_4041e5c0(param_1,0,local_28);
    FUN_4041e55c(param_1,0);
  }
  if (1 < (uint)param_1[9]) {
    do {
      iVar2 = FUN_40421ae4((int)param_1,uVar6 - 1,1,&local_24);
      if (iVar2 < 0) {
        return iVar2;
      }
      iVar2 = FUN_40421ae4((int)param_1,uVar6,1,auStack_20);
      if (iVar2 < 0) {
LAB_40425d0c:
        iVar5 = uVar6 - 1;
        goto LAB_40425d10;
      }
      piVar3 = (int *)FUN_404156d8(param_1[8] + DAT_404304bc);
      iVar2 = FUN_40423568(piVar3,1,&local_28,1);
      if (iVar2 < 0) {
        FUN_4041e55c(param_1,uVar6);
        goto LAB_40425d0c;
      }
      uVar1 = FUN_404155d0((int)param_1);
      uVar4 = FUN_404254d8(local_24,CONCAT22(extraout_var,uVar1));
      FUN_404216bc((int)param_1,local_28,0xfffffffc,uVar4);
      uVar1 = FUN_404155d0((int)param_1);
      FUN_404254e8(local_24,CONCAT22(extraout_var_00,uVar1),local_28);
      FUN_4041e5c0(param_1,uVar6,local_28);
      FUN_4041e55c(param_1,uVar6 - 1);
      FUN_4041e55c(param_1,uVar6);
      uVar6 = uVar6 + 1;
    } while (uVar6 < (uint)param_1[9]);
  }
  return iVar2;
}



/* 40425d3c FUN_40425d3c */

/* Boundary evidence: original MIPS .pdata 40425d3c..40425f33. Semantic name remains unreviewed. */

int FUN_40425d3c(int *param_1,uint param_2)

{
  bool bVar1;
  undefined2 uVar2;
  int iVar3;
  undefined3 extraout_var;
  int *piVar4;
  undefined2 extraout_var_00;
  int iVar5;
  int iVar6;
  uint local_30;
  int local_2c;
  undefined4 auStack_28 [2];
  
  iVar3 = FUN_40424a24((int)param_1,param_2);
  if (-1 < iVar3) {
    iVar5 = param_2 - 1;
    iVar3 = FUN_40421ae4((int)param_1,iVar5,2,auStack_28);
    if (-1 < iVar3) {
      iVar6 = param_1[9];
      param_1[9] = param_2;
      iVar3 = param_1[8] + DAT_404304bc;
      bVar1 = FUN_40425584(iVar3);
      if (CONCAT31(extraout_var,bVar1) == 0) {
        piVar4 = (int *)FUN_404156d8(iVar3);
        iVar3 = FUN_40423568(piVar4,1,&local_30,0);
        if (iVar3 < 0) {
          return iVar3;
        }
        piVar4 = (int *)FUN_404156d8(param_1[8] + DAT_404304bc);
        iVar3 = FUN_404221f0(piVar4,local_30,-4);
        if (iVar3 < 0) {
          return iVar3;
        }
      }
      else {
        piVar4 = (int *)FUN_404156d8(iVar3);
        iVar3 = FUN_40423568(piVar4,1,&local_30,1);
        if (iVar3 < 0) {
          return iVar3;
        }
        FUN_404216bc((int)param_1,local_30,0xfffffffc,0xfffffffe);
      }
      FUN_4041e5c0(param_1,iVar5,local_30);
      FUN_4041e55c(param_1,iVar5);
      if (iVar6 == 0) {
        iVar5 = FUN_404156d0(param_1[8] + DAT_404304bc);
        FUN_4042547c(iVar5,local_30);
      }
      else {
        iVar6 = iVar6 + -1;
        iVar3 = FUN_40421ae4((int)param_1,iVar6,1,&local_2c);
        if (iVar3 < 0) {
          return iVar3;
        }
        uVar2 = FUN_404155d0((int)param_1);
        FUN_404254e8(local_2c,CONCAT22(extraout_var_00,uVar2),local_30);
        FUN_4041e55c(param_1,iVar6);
      }
      iVar5 = FUN_404156d0(param_1[8] + DAT_404304bc);
      FUN_404254c4(iVar5,param_1[9]);
    }
  }
  return iVar3;
}



/* 40425f34 FUN_40425f34 */

/* Boundary evidence: original MIPS .pdata 40425f34..404261cb. Semantic name remains unreviewed. */

int FUN_40425f34(int *param_1,int param_2,int *param_3)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  ushort local_38 [2];
  uint local_34;
  int local_30;
  int local_2c;
  
  *param_3 = -1;
  iVar5 = DAT_404304bc;
  uVar4 = (uint)*(ushort *)(param_1 + 0xb);
  iVar7 = 0;
  if (uVar4 < 9) {
    uVar6 = 0;
    if (uVar4 != 0) {
      do {
        if (param_1[uVar6 + 0xc] == param_2) {
          *param_3 = param_1[uVar6 + 0x14];
          return 0;
        }
        uVar6 = uVar6 + 1 & 0xffff;
      } while (uVar6 < uVar4);
    }
  }
  else {
    uVar4 = 0;
    iVar1 = FUN_404156d0(param_1[8] + DAT_404304bc);
    iVar1 = FUN_4040c920(iVar1);
    if (iVar1 != 0) {
      do {
        iVar7 = FUN_40425720(param_1,uVar4,&local_2c);
        iVar5 = DAT_404304bc;
        if (iVar7 < 0) {
          return iVar7;
        }
        if (local_2c == param_2) {
          iVar5 = -4;
          goto LAB_40426190;
        }
        uVar4 = uVar4 + 1;
        iVar1 = FUN_404156d0(param_1[8] + DAT_404304bc);
        uVar6 = FUN_4040c920(iVar1);
      } while (uVar4 < uVar6);
    }
    iVar1 = 0;
    local_30 = 0;
    uVar6 = 0xffff;
    uVar8 = 0;
    local_2c = FUN_404156d0(param_1[8] + iVar5);
    iVar2 = FUN_4040c910(local_2c);
    uVar4 = local_34;
    if (iVar2 == 0) {
      return iVar7;
    }
    while( true ) {
      if (uVar8 < 0x6d) {
        iVar2 = FUN_40425490(local_2c,uVar8);
      }
      else {
        FUN_40425500((int)param_1,uVar8,&local_34,local_38);
        uVar4 = local_34;
        if (local_34 != uVar6) {
          if (iVar1 != 0) {
            FUN_4041e55c(param_1,uVar6);
          }
          iVar7 = FUN_40421ae4((int)param_1,uVar4,0,&local_30);
          iVar1 = local_30;
          iVar5 = DAT_404304bc;
          if (iVar7 < 0) {
            return iVar7;
          }
        }
        iVar2 = FUN_404254d8(iVar1,(uint)local_38[0]);
        uVar6 = uVar4;
      }
      if (param_2 == iVar2) break;
      uVar8 = uVar8 + 1;
      local_2c = FUN_404156d0(param_1[8] + iVar5);
      uVar3 = FUN_4040c910(local_2c);
      if (uVar3 <= uVar8) {
        if (iVar1 == 0) {
          return iVar7;
        }
        FUN_4041e55c(param_1,uVar4);
        return iVar7;
      }
    }
    if (iVar1 != 0) {
      FUN_4041e55c(param_1,uVar4);
    }
    iVar5 = -3;
LAB_40426190:
    *param_3 = iVar5;
  }
  return 0;
}



/* 404261cc FUN_404261cc */

/* Boundary evidence: original MIPS .pdata 404261cc..40426a07. Semantic name remains unreviewed. */

int FUN_404261cc(int *param_1,int param_2)

{
  bool bVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  ushort local_60;
  ushort local_5e;
  ushort auStack_5c [2];
  int local_58;
  uint local_54;
  uint local_50;
  uint local_4c;
  int *local_48;
  uint local_44;
  uint local_40;
  uint local_3c;
  uint local_38;
  uint local_34;
  uint local_30;
  uint local_2c;
  
  uVar8 = 0;
  piVar2 = (int *)FUN_404156d8(DAT_404304bc + param_1[8]);
  if (param_1[10] == 0) {
    param_1[10] = 1;
    if ((*(ushort *)(param_1 + 0xb) < 9) && (uVar9 = 0, *(ushort *)(param_1 + 0xb) != 0)) {
      do {
        if (8 < *(ushort *)(param_1 + 0xb)) break;
        FUN_40421690((int)piVar2,param_1[uVar9 + 0xc],&local_40,&local_5e);
        iVar3 = FUN_404156d0(DAT_404304bc + param_1[8]);
        uVar8 = FUN_4040c910(iVar3);
        if ((((uVar8 <= local_40) && (uVar8 = FUN_40422d68(piVar2,local_40 + 1), (int)uVar8 < 0)) ||
            (uVar8 = FUN_404221f0(piVar2,param_1[uVar9 + 0xc],param_1[uVar9 + 0x14]), (int)uVar8 < 0
            )) || ((param_1[uVar9 + 0x1c] != 0xfffffffe &&
                   (uVar8 = FUN_404221f0(piVar2,param_1[uVar9 + 0x1c],-1), (int)uVar8 < 0))))
        goto LAB_404269d0;
        uVar9 = uVar9 + 1 & 0xffff;
      } while (uVar9 < *(ushort *)(param_1 + 0xb));
    }
    if (*(ushort *)(param_1 + 0xb) < 9) {
      *(undefined2 *)(param_1 + 0xb) = 0;
      FUN_404254f8((int)piVar2);
      uVar8 = 0;
    }
    else {
      iVar3 = DAT_404304bc;
      if (param_2 == 0) {
        do {
          bVar1 = false;
          uVar9 = 0;
          iVar3 = FUN_404156d0(iVar3 + param_1[8]);
          iVar3 = FUN_4040c910(iVar3);
          if (iVar3 == 0) break;
          do {
            uVar8 = FUN_40425648(param_1,uVar9,&local_2c);
            uVar10 = local_2c;
            if ((int)uVar8 < 0) goto LAB_404269d0;
            FUN_40421690((int)piVar2,local_2c,&local_30,auStack_5c);
            iVar3 = FUN_404156d0(DAT_404304bc + param_1[8]);
            uVar8 = FUN_4040c910(iVar3);
            if (uVar8 <= local_30) {
              uVar8 = FUN_40422d68(piVar2,local_30 + 1);
              if ((int)uVar8 < 0) goto LAB_404269d0;
              bVar1 = true;
            }
            uVar8 = FUN_40421b54(piVar2,uVar10,&local_34);
            if ((int)uVar8 < 0) goto LAB_404269d0;
            if (local_34 != 0xfffffffd) {
              uVar8 = FUN_404221f0(piVar2,uVar10,-3);
              if ((int)uVar8 < 0) goto LAB_404269d0;
              bVar1 = true;
            }
            iVar3 = DAT_404304bc;
            uVar9 = uVar9 + 1;
            iVar5 = FUN_404156d0(DAT_404304bc + param_1[8]);
            uVar10 = FUN_4040c910(iVar5);
          } while (uVar9 < uVar10);
        } while (bVar1);
      }
      else {
        piVar4 = (int *)FUN_404156e0(param_2);
        local_48 = piVar4;
        uVar9 = FUN_404156d0(param_2);
        local_34 = uVar9;
        local_38 = FUN_4040c910(uVar9);
        uVar9 = FUN_4040c920(uVar9);
        iVar3 = DAT_404304bc;
        uVar10 = 0;
        iVar5 = FUN_404156d0(DAT_404304bc + param_1[8]);
        iVar5 = FUN_4040c920(iVar5);
        if (iVar5 != 0) {
          do {
            local_40 = 0xfffffffe;
            uVar8 = FUN_40425720(param_1,uVar10,&local_44);
            if (((int)uVar8 < 0) ||
               ((uVar6 = 0xfffffffe, uVar10 < uVar9 &&
                (uVar8 = FUN_40425720(piVar4,uVar10,&local_40), uVar6 = local_40, (int)uVar8 < 0))))
            goto LAB_404269d0;
            uVar11 = local_44;
            if ((local_44 != uVar6) || (uVar6 == 0xfffffffe)) {
              FUN_40421690((int)piVar2,local_44,&local_50,&local_5e);
              iVar3 = FUN_404156d0(DAT_404304bc + param_1[8]);
              uVar8 = FUN_4040c910(iVar3);
              if (((((uVar8 <= local_50) &&
                    (uVar8 = FUN_40422d68(piVar2,local_50 + 1), (int)uVar8 < 0)) ||
                   (uVar8 = FUN_40421b54(piVar2,uVar11,&local_4c), (int)uVar8 < 0)) ||
                  ((local_4c != 0xfffffffc &&
                   (uVar8 = FUN_404221f0(piVar2,uVar11,-4), (int)uVar8 < 0)))) ||
                 ((uVar6 != 0xfffffffe &&
                  ((uVar8 = FUN_40421b54(piVar2,uVar6,&local_4c), (int)uVar8 < 0 ||
                   ((local_4c != 0xffffffff &&
                    (uVar8 = FUN_404221f0(piVar2,uVar6,-1), (int)uVar8 < 0))))))))
              goto LAB_404269d0;
            }
            iVar3 = DAT_404304bc;
            uVar10 = uVar10 + 1;
            iVar5 = FUN_404156d0(DAT_404304bc + param_1[8]);
            uVar6 = FUN_4040c920(iVar5);
            piVar4 = local_48;
          } while (uVar10 < uVar6);
        }
        do {
          local_54 = 0xffff;
          local_58 = 0;
          local_50 = 0;
          uVar10 = 0;
          local_40 = 0xffff;
          local_4c = 0;
          iVar5 = FUN_404156d0(iVar3 + param_1[8]);
          iVar5 = FUN_4040c910(iVar5);
          uVar9 = 0xffff;
          if (iVar5 == 0) break;
          do {
            uVar6 = 0xfffffffe;
            if (0x6c < uVar10) {
              FUN_40425500((int)param_1,uVar10,&local_3c,&local_60);
              uVar11 = local_3c;
              if (local_3c != uVar9) {
                if (local_50 != 0) {
                  FUN_4041e55c(param_1,uVar9);
                }
                uVar8 = FUN_40421ae4((int)param_1,uVar11,0,&local_50);
                iVar3 = DAT_404304bc;
                if ((int)uVar8 < 0) goto LAB_404269d0;
              }
              uVar9 = FUN_404254d8(local_50,(uint)local_60);
              local_40 = uVar11;
            }
            else {
              iVar5 = FUN_404156d0(iVar3 + param_1[8]);
              uVar9 = FUN_40425490(iVar5,uVar10);
            }
            if (uVar10 < local_38) {
              if (0x6c < uVar10) {
                FUN_40425500((int)param_1,uVar10,&local_30,&local_5e);
                uVar6 = local_30;
                uVar11 = local_30;
                if (local_30 != local_54) {
                  if (local_4c != 0) {
                    FUN_4041e55c(local_48,local_54);
                  }
                  uVar8 = FUN_40421ae4((int)local_48,uVar6,0,&local_4c);
                  iVar3 = DAT_404304bc;
                  if ((int)uVar8 < 0) goto LAB_404269d0;
                }
                uVar6 = FUN_404254d8(local_4c,(uint)local_5e);
                local_54 = uVar11;
              }
              else {
                uVar6 = FUN_40425490(local_34,uVar10);
              }
            }
            uVar11 = local_54;
            if ((uVar9 != uVar6) || (iVar5 = local_58, uVar6 == 0xfffffffe)) {
              FUN_40421690((int)piVar2,uVar9,&local_2c,auStack_5c);
              iVar3 = FUN_404156d0(iVar3 + param_1[8]);
              uVar8 = FUN_4040c910(iVar3);
              if (uVar8 <= local_2c) {
                uVar8 = FUN_40422d68(piVar2,local_2c + 1);
                if ((int)uVar8 < 0) goto LAB_404269d0;
                local_58 = 1;
              }
              iVar5 = local_58;
              uVar8 = FUN_40421b54(piVar2,uVar9,&local_44);
              if ((int)uVar8 < 0) goto LAB_404269d0;
              if (local_44 != 0xfffffffd) {
                uVar8 = FUN_404221f0(piVar2,uVar9,-3);
                if ((int)uVar8 < 0) goto LAB_404269d0;
                iVar5 = 1;
                local_58 = 1;
              }
              iVar3 = DAT_404304bc;
              if (uVar6 != 0xfffffffe) {
                uVar8 = FUN_40421b54(piVar2,uVar6,&local_44);
                if ((int)uVar8 < 0) goto LAB_404269d0;
                iVar3 = DAT_404304bc;
                if (local_44 != 0xffffffff) {
                  uVar8 = FUN_404221f0(piVar2,uVar6,-1);
                  if ((int)uVar8 < 0) goto LAB_404269d0;
                  local_58 = 1;
                  iVar3 = DAT_404304bc;
                  iVar5 = 1;
                }
              }
            }
            uVar10 = uVar10 + 1;
            iVar7 = FUN_404156d0(iVar3 + param_1[8]);
            uVar6 = FUN_4040c910(iVar7);
            uVar9 = local_40;
          } while (uVar10 < uVar6);
          if (local_50 != 0) {
            FUN_4041e55c(param_1,local_40);
            iVar3 = DAT_404304bc;
          }
          if (local_4c != 0) {
            FUN_4041e55c(local_48,uVar11);
            iVar3 = DAT_404304bc;
          }
        } while (iVar5 != 0);
      }
      FUN_404254f8((int)piVar2);
      *(undefined2 *)(param_1 + 0xb) = 0;
    }
LAB_404269d0:
    param_1[10] = 0;
  }
  else {
    uVar8 = 0;
  }
  return uVar8;
}



/* 40426a08 FUN_40426a08 */

/* Boundary evidence: original MIPS .pdata 40426a08..40426aff. Semantic name remains unreviewed. */

int FUN_40426a08(int *param_1,uint param_2,undefined4 param_3)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  ushort local_20 [2];
  uint local_1c;
  
  iVar3 = 0;
  if (param_2 < 0x6d) {
    iVar2 = FUN_404156d0(param_1[8] + DAT_404304bc);
    FUN_404254a4(iVar2,param_2,param_3);
  }
  else {
    FUN_40425500((int)param_1,param_2,&local_1c,local_20);
    uVar1 = local_1c;
    if (((local_1c < (uint)param_1[9]) || (iVar3 = FUN_40425d3c(param_1,param_1[9] + 1), -1 < iVar3)
        ) && (iVar3 = FUN_40421ae4((int)param_1,uVar1,1,&local_1c), -1 < iVar3)) {
      FUN_404254e8(local_1c,(uint)local_20[0],param_3);
      FUN_4041e55c(param_1,uVar1);
    }
  }
  return iVar3;
}



/* 40426b00 FUN_40426b00 */

/* Boundary evidence: original MIPS .pdata 40426b00..40426c03. Semantic name remains unreviewed. */

void FUN_40426b00(int *param_1,uint param_2,undefined4 *param_3)

{
  int iVar1;
  int *piVar2;
  uint local_20;
  uint local_1c;
  
  iVar1 = FUN_40425648(param_1,param_2,&local_1c);
  if (-1 < iVar1) {
    iVar1 = FUN_404156d8(param_1[8] + DAT_404304bc);
    iVar1 = FUN_40421f48(iVar1,local_1c);
    if (-1 < iVar1) {
      if (iVar1 == 1) {
        piVar2 = (int *)FUN_404156d8(param_1[8] + DAT_404304bc);
        iVar1 = FUN_40423568(piVar2,1,&local_20,1);
        if (iVar1 < 0) {
          return;
        }
        FUN_404216bc((int)param_1,local_20,0xfffffffd,local_1c);
        iVar1 = FUN_40426a08(param_1,param_2,local_20);
        if (iVar1 < 0) {
          return;
        }
      }
      else {
        local_20 = 0xfffffffe;
      }
      *param_3 = local_20;
    }
  }
  return;
}



/* 40426c04 FUN_40426c04 */

undefined4 FUN_40426c04(int param_1)

{
  return *(undefined4 *)(param_1 + 0x20);
}



/* 40426c0c FUN_40426c0c */

int FUN_40426c0c(undefined4 param_1,int param_2,int param_3)

{
  return param_3 + param_2 + -1;
}



/* 40426c1c FUN_40426c1c */

undefined4 FUN_40426c1c(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  return param_3;
}



/* 40426c2c FUN_40426c2c */

int FUN_40426c2c(int param_1,undefined4 param_2,int param_3)

{
  return param_3 + param_1 + -1;
}



/* 40426c60 FUN_40426c60 */

/* Boundary evidence: original MIPS .pdata 40426c60..40426cd3. Semantic name remains unreviewed. */

undefined4 FUN_40426c60(int param_1,int param_2,int *param_3)

{
  undefined2 uVar1;
  int iVar2;
  undefined2 extraout_var;
  
  if (param_2 == -3) {
    iVar2 = FUN_40426c04(param_1 + 0x20c);
  }
  else {
    iVar2 = FUN_4040c918(param_1 + 4);
  }
  uVar1 = FUN_4040d6bc(param_1);
  *param_3 = CONCAT22(extraout_var,uVar1) * iVar2;
  return 0;
}



/* 40426cd4 FUN_40426cd4 */

undefined4 FUN_40426cd4(undefined4 param_1,undefined4 param_2)

{
  return param_2;
}



/* 40426ce4 FUN_40426ce4 */

undefined4 FUN_40426ce4(undefined4 param_1)

{
  return param_1;
}



/* 40426cf4 FUN_40426cf4 */

/* Boundary evidence: original MIPS .pdata 40426cf4..40426e03. Semantic name remains unreviewed. */

undefined4
FUN_40426cf4(undefined4 param_1,uint param_2,int param_3,int param_4,int param_5,uint *param_6,
            int *param_7,uint *param_8)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  
  uVar1 = FUN_40426ce4(param_3);
  if (param_2 < uVar1) {
LAB_40426ddc:
    uVar4 = 0;
  }
  else {
    uVar2 = FUN_40426c2c(param_3,param_4,param_5);
    if (uVar2 < param_2) {
      if (*param_6 <= param_2 - uVar2) goto LAB_40426ddc;
      *param_6 = param_2 - uVar2;
      iVar3 = FUN_40426c0c(param_3,param_4,param_5);
      *param_7 = iVar3;
      *param_8 = uVar2;
    }
    else {
      *param_6 = 0;
      *param_8 = param_2;
      iVar3 = FUN_40426cd4(param_3,param_4);
      *param_7 = iVar3 + (param_2 - uVar1);
    }
    uVar4 = 1;
  }
  return uVar4;
}



/* 40426e04 FUN_40426e04 */

/* Boundary evidence: original MIPS .pdata 40426e04..40426e2b. Semantic name remains unreviewed. */

void FUN_40426e04(int param_1)

{
  FUN_404156e8(*(int *)(param_1 + 0x70) + DAT_404304bc);
  return;
}



/* 40426e2c FUN_40426e2c */

/* Boundary evidence: original MIPS .pdata 40426e2c..40426e53. Semantic name remains unreviewed. */

void FUN_40426e2c(int param_1)

{
  FUN_404156d8(*(int *)(param_1 + 0x70) + DAT_404304bc);
  return;
}



/* 40426e54 FUN_40426e54 */

/* Boundary evidence: original MIPS .pdata 40426e54..40426e7b. Semantic name remains unreviewed. */

void FUN_40426e54(int param_1)

{
  FUN_4040fae4(*(int *)(param_1 + 0x70) + DAT_404304bc);
  return;
}



/* 40426e7c FUN_40426e7c */

/* Boundary evidence: original MIPS .pdata 40426e7c..40426edb. Semantic name remains unreviewed. */

int FUN_40426e7c(int param_1)

{
  int local_10 [2];
  
  local_10[0] = 0;
  if (*(int *)(param_1 + 0x6c) == 0) {
    FUN_40426c60(*(int *)(param_1 + 0x70) + DAT_404304bc,*(int *)(param_1 + 0x74),local_10);
  }
  else {
    FUN_40429170(*(int *)(param_1 + 0x6c) + DAT_404304bc,local_10);
  }
  return local_10[0];
}



/* 40426edc FUN_40426edc */

undefined4 FUN_40426edc(int param_1)

{
  return *(undefined4 *)(param_1 + 0x74);
}



/* 40426ee4 FUN_40426ee4 */

/* Boundary evidence: original MIPS .pdata 40426ee4..40426f4b. Semantic name remains unreviewed. */

void FUN_40426ee4(int param_1)

{
  uint uVar1;
  int iVar2;
  
  if (((*(int *)(param_1 + 0x6c) == 0) || (uVar1 = FUN_40426e7c(param_1), 0xfff < uVar1)) ||
     (iVar2 = FUN_40426edc(param_1), iVar2 == 0)) {
    FUN_40426e2c(param_1);
  }
  else {
    FUN_40426e54(param_1);
  }
  return;
}



/* 40426f4c FUN_40426f4c */

/* Boundary evidence: original MIPS .pdata 40426f4c..40427023. Semantic name remains unreviewed. */

void FUN_40426f4c(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  ushort uVar2;
  uint uVar3;
  undefined4 *puVar4;
  
  if (8 < *(ushort *)(param_1 + 0x7a)) {
    *(undefined2 *)(param_1 + 0x7a) = 0;
  }
  uVar2 = *(ushort *)(param_1 + 0x7a);
  puVar4 = (undefined4 *)((uint)uVar2 * 0xc + param_1);
  uVar1 = FUN_40426ce4(*param_2);
  *puVar4 = uVar1;
  uVar1 = FUN_40426c1c(*param_2,param_2[1],param_2[2]);
  puVar4[2] = uVar1;
  uVar1 = FUN_40426cd4(*param_2,param_2[1]);
  uVar3 = uVar2 + 1;
  puVar4[1] = uVar1;
  *(short *)(param_1 + 0x7a) = *(short *)(param_1 + 0x7a) + 1;
  uVar2 = *(ushort *)(param_1 + 0x78);
  if (uVar2 <= uVar3) {
    uVar2 = (ushort)uVar3;
  }
  *(ushort *)(param_1 + 0x78) = uVar2;
  *(short *)(param_1 + 0x7c) = *(short *)(param_1 + 0x7c) + 1;
  return;
}



/* 40427024 FUN_40427024 */

/* Boundary evidence: original MIPS .pdata 40427024..404270a3. Semantic name remains unreviewed. */

int FUN_40427024(int param_1,undefined4 *param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  
  iVar3 = 0;
  if (*(int *)(param_1 + 0x6c) == 0) {
    uVar2 = FUN_4041e674(*(int *)(param_1 + 0x70) + DAT_404304bc,*(int *)(param_1 + 0x74));
    *param_2 = uVar2;
  }
  else {
    piVar1 = (int *)FUN_40426e04(param_1);
    iVar3 = FUN_40415300(piVar1,*(uint *)(param_1 + 0x74),param_2);
  }
  return iVar3;
}



/* 404270a4 FUN_404270a4 */

/* Boundary evidence: original MIPS .pdata 404270a4..404270ff. Semantic name remains unreviewed. */

int FUN_404270a4(int param_1)

{
  FUN_4040a570(param_1,0xc,9,&LAB_40426c3c);
  *(undefined4 *)(param_1 + 0x74) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x70) = 0;
  *(undefined4 *)(param_1 + 0x6c) = 0;
  *(undefined2 *)(param_1 + 0x78) = 0;
  *(undefined2 *)(param_1 + 0x7a) = 0;
  *(undefined2 *)(param_1 + 0x7c) = 0;
  return param_1;
}



/* 40427100 FUN_40427100 */

void FUN_40427100(int param_1)

{
  undefined4 *puVar1;
  uint uVar2;
  
  uVar2 = 0;
  do {
    puVar1 = (undefined4 *)(uVar2 * 0xc + param_1);
    *puVar1 = 0xffffffff;
    puVar1[1] = 0xfffffffe;
    puVar1[2] = 0;
    uVar2 = uVar2 + 1 & 0xffff;
  } while (uVar2 < 9);
  *(undefined2 *)(param_1 + 0x78) = 0;
  *(undefined2 *)(param_1 + 0x7a) = 0;
  *(short *)(param_1 + 0x7c) = *(short *)(param_1 + 0x7c) + 1;
  return;
}



/* 40427164 FUN_40427164 */

/* Boundary evidence: original MIPS .pdata 40427164..404273b3. Semantic name remains unreviewed. */

uint FUN_40427164(int param_1,uint param_2,uint *param_3)

{
  ushort uVar1;
  uint uVar2;
  uint uVar3;
  int *piVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  int *piVar8;
  uint uVar9;
  uint *puVar10;
  uint local_1c8;
  uint local_1c4 [98];
  int local_3c;
  
  local_1c4[2] = -1;
  local_1c8 = 0xfffffffe;
  local_1c4[0] = 0xffffffff;
  *param_3 = 0xfffffffe;
  piVar4 = (int *)FUN_40426ee4(param_1);
  uVar1 = *(ushort *)(param_1 + 0x78);
  if (uVar1 != 0) {
    uVar9 = 0;
    do {
      piVar8 = (int *)(uVar9 * 0xc + param_1);
      FUN_40426cf4(param_1,param_2,*piVar8,piVar8[1],piVar8[2],local_1c4 + 2,(int *)&local_1c8,
                   local_1c4);
      uVar9 = uVar9 + 1 & 0xffff;
    } while (uVar9 < uVar1);
    if (local_1c4[2] == 0) {
      *param_3 = local_1c8;
      return 0;
    }
    uVar9 = local_1c4[0];
    if (local_1c4[0] != 0xffffffff) goto LAB_4042727c;
  }
  uVar9 = FUN_40427024(param_1,&local_1c8);
  if ((int)uVar9 < 0) {
    return uVar9;
  }
  uVar9 = 0;
LAB_4042727c:
  uVar5 = FUN_40423c64(piVar4,local_1c4 + 3,0,local_1c8,(param_2 - uVar9) + 1,(int *)(local_1c4 + 1)
                      );
  uVar2 = local_1c4[0x60];
  uVar3 = local_1c4[0x61];
  iVar7 = local_3c;
  while( true ) {
    if ((int)uVar5 < 0) {
      return uVar5;
    }
    if (local_1c4[1] < 0x21) break;
    local_1c4[0x60] = uVar2;
    local_1c4[0x61] = uVar3;
    local_3c = iVar7;
    iVar6 = FUN_40426c2c(uVar2,uVar3,iVar7);
    uVar9 = iVar6 + uVar9;
    uVar5 = FUN_40426c0c(uVar2,uVar3,iVar7);
    uVar5 = FUN_40423c64(piVar4,local_1c4 + 3,0,uVar5,(param_2 - uVar9) + 1,(int *)(local_1c4 + 1));
    uVar2 = local_1c4[0x60];
    uVar3 = local_1c4[0x61];
    iVar7 = local_3c;
  }
  puVar10 = local_1c4 + local_1c4[1] * 3;
  iVar7 = FUN_40426ce4(*puVar10);
  iVar6 = FUN_40426cd4(*puVar10,local_1c4[local_1c4[1] * 3 + 1]);
  *puVar10 = iVar7 + uVar9;
  *param_3 = iVar6 + (param_2 - (iVar7 + uVar9));
  FUN_40426f4c(param_1,puVar10);
  return uVar5;
}



/* 404273b4 FUN_404273b4 */

/* Boundary evidence: original MIPS .pdata 404273b4..404276f7. Semantic name remains unreviewed. */

int FUN_404273b4(int param_1,uint param_2,int *param_3)

{
  ushort uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  int *piVar9;
  uint uVar10;
  int *piVar11;
  int **ppiVar12;
  uint uVar13;
  uint local_1d0;
  uint local_1cc;
  uint local_1c8;
  int *local_1c4;
  uint local_1c0 [102];
  
  local_1c0[0] = 0xffffffff;
  local_1d0 = 0xfffffffe;
  local_1cc = 0xffffffff;
  uVar13 = 10;
  *param_3 = -2;
  local_1c4 = (int *)FUN_40426ee4(param_1);
  uVar1 = *(ushort *)(param_1 + 0x78);
  if (uVar1 != 0) {
    uVar10 = 0;
    do {
      piVar9 = (int *)(uVar10 * 0xc + param_1);
      iVar6 = FUN_40426cf4(param_1,param_2,*piVar9,piVar9[1],piVar9[2],local_1c0,(int *)&local_1d0,
                           &local_1cc);
      if (iVar6 != 0) {
        uVar13 = uVar10;
      }
      uVar10 = uVar10 + 1 & 0xffff;
    } while (uVar10 < uVar1);
    if (local_1c0[0] == 0) {
      *param_3 = local_1d0;
      return 0;
    }
    uVar10 = local_1cc;
    if (local_1cc != 0xffffffff) goto LAB_404274e8;
  }
  iVar6 = FUN_40427024(param_1,&local_1d0);
  if (iVar6 < 0) {
    return iVar6;
  }
  uVar10 = 0;
LAB_404274e8:
  uVar7 = FUN_40423c64(local_1c4,local_1c0 + 2,1,local_1d0,(param_2 - uVar10) + 1,(int *)&local_1c8)
  ;
  uVar2 = local_1c8;
  uVar3 = local_1c0[0x5f];
  uVar4 = local_1c0[0x60];
  uVar5 = local_1c0[0x61];
  while( true ) {
    if ((int)uVar7 < 0) {
      return uVar7;
    }
    if (uVar2 < 0x21) break;
    local_1c8 = uVar2;
    local_1c0[0x5f] = uVar3;
    local_1c0[0x60] = uVar4;
    local_1c0[0x61] = uVar5;
    iVar6 = FUN_40426c2c(uVar3,uVar4,uVar5);
    uVar10 = iVar6 + uVar10;
    uVar7 = FUN_40426c0c(uVar3,uVar4,uVar5);
    uVar7 = FUN_40423c64(local_1c4,local_1c0 + 2,1,uVar7,(param_2 - uVar10) + 1,(int *)&local_1c8);
    uVar2 = local_1c8;
    uVar3 = local_1c0[0x5f];
    uVar4 = local_1c0[0x60];
    uVar5 = local_1c0[0x61];
  }
  ppiVar12 = &local_1c4 + uVar2 * 3;
  iVar6 = FUN_40426ce4(*ppiVar12);
  piVar9 = (int *)(iVar6 + uVar10);
  iVar6 = FUN_40426cd4(*ppiVar12,local_1c0[uVar2 * 3]);
  *ppiVar12 = piVar9;
  *param_3 = iVar6 + (param_2 - (int)piVar9);
  if (uVar13 != 10) {
    piVar11 = (int *)(uVar13 * 0xc + param_1);
    iVar6 = FUN_40426c0c(*piVar11,piVar11[1],piVar11[2]);
    uVar13 = FUN_40426cd4(piVar9,local_1c0[uVar2 * 3]);
    if ((uVar13 <= iVar6 + 1U) && (uVar10 = FUN_40426cd4(*piVar11,piVar11[1]), uVar10 < uVar13)) {
      iVar8 = FUN_40426c2c(*piVar11,piVar11[1],piVar11[2]);
      uVar10 = FUN_40426ce4(*ppiVar12);
      if (uVar10 <= iVar8 + 1U) {
        iVar8 = FUN_40426c1c(*ppiVar12,local_1c0[uVar2 * 3],local_1c0[uVar2 * 3 + 1]);
        piVar11[2] = iVar8 + (piVar11[2] - iVar6) + uVar13 + -1;
        *(short *)(param_1 + 0x7c) = *(short *)(param_1 + 0x7c) + 1;
        return uVar7;
      }
    }
  }
  FUN_40426f4c(param_1,ppiVar12);
  return uVar7;
}



/* 404276f8 FUN_404276f8 */

/* Boundary evidence: original MIPS .pdata 404276f8..4042783b. Semantic name remains unreviewed. */

undefined4 FUN_404276f8(int param_1,uint param_2,uint param_3)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  uint uVar6;
  
  uVar6 = 0;
  do {
    piVar5 = (int *)(uVar6 * 0xc + param_1);
    uVar1 = FUN_40426ce4(*piVar5);
    uVar2 = FUN_40426c2c(*piVar5,piVar5[1],piVar5[2]);
    if ((uVar1 <= param_3) && (param_2 <= uVar2)) {
      if (uVar1 < param_2) {
        iVar3 = (param_2 - uVar2) + piVar5[2] + -1;
LAB_404277ec:
        piVar5[2] = iVar3;
      }
      else {
        if (param_3 < uVar2) {
          iVar4 = (param_3 - uVar1) + 1;
          iVar3 = piVar5[2] - iVar4;
          *piVar5 = *piVar5 + iVar4;
          piVar5[1] = piVar5[1] + iVar4;
          goto LAB_404277ec;
        }
        *piVar5 = -1;
        piVar5[1] = -2;
        piVar5[2] = 0;
      }
      *(short *)(param_1 + 0x7c) = *(short *)(param_1 + 0x7c) + 1;
    }
    uVar6 = uVar6 + 1 & 0xffff;
    if (8 < uVar6) {
      return 0;
    }
  } while( true );
}



/* 4042783c FUN_4042783c */

/* Boundary evidence: original MIPS .pdata 4042783c..40427a7f. Semantic name remains unreviewed. */

uint FUN_4042783c(int param_1,uint param_2,uint param_3,uint *param_4,int param_5,int *param_6)

{
  short sVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  uint *puVar5;
  uint uVar6;
  uint local_30 [2];
  
  uVar6 = 0;
  if (*(ushort *)(param_1 + 0x78) != 0) {
    do {
      puVar5 = (uint *)(uVar6 * 0xc + param_1);
      uVar4 = *puVar5;
      if ((uVar4 <= param_2) && (param_2 < puVar5[2] + uVar4)) goto LAB_40427914;
      uVar6 = uVar6 + 1 & 0xffff;
    } while (uVar6 < *(ushort *)(param_1 + 0x78));
  }
  sVar1 = *(short *)(param_1 + 0x7c);
  if (param_3 == 0) {
    uVar6 = FUN_40427164(param_1,param_2,local_30);
  }
  else {
    uVar6 = FUN_404273b4(param_1,(param_2 + param_5) - 1,(int *)local_30);
    if ((int)uVar6 < 0) {
      return uVar6;
    }
    uVar6 = FUN_404273b4(param_1,param_2,(int *)local_30);
  }
  if (-1 < (int)uVar6) {
    if (sVar1 != *(short *)(param_1 + 0x7c)) {
      uVar6 = 0;
      if (*(ushort *)(param_1 + 0x78) != 0) {
        do {
          puVar5 = (uint *)(uVar6 * 0xc + param_1);
          uVar4 = *puVar5;
          if ((uVar4 <= param_2) && (param_2 < puVar5[2] + uVar4)) {
LAB_40427914:
            piVar2 = (int *)(uVar6 * 0xc + param_1);
            iVar3 = *piVar2;
            *param_4 = param_2;
            param_4[1] = piVar2[1] + (param_2 - iVar3);
            param_4[2] = piVar2[2] - (param_2 - iVar3);
            *param_6 = 1;
            return 0;
          }
          uVar6 = uVar6 + 1 & 0xffff;
        } while (uVar6 < *(ushort *)(param_1 + 0x78));
      }
    }
    piVar2 = (int *)FUN_40426ee4(param_1);
    uVar6 = FUN_40423c64(piVar2,param_4,param_3,local_30[0],param_5,param_6);
    if (-1 < (int)uVar6) {
      iVar3 = *param_6;
      if (iVar3 == 0) {
        uVar6 = 0x8000ffff;
      }
      else {
        param_4[iVar3 * 3 + -3] = param_2 + param_4[iVar3 * 3 + -3];
        FUN_40426f4c(param_1,param_4 + *param_6 * 3 + -3);
      }
    }
  }
  return uVar6;
}



/* 40427a80 FUN_40427a80 */

/* Boundary evidence: original MIPS .pdata 40427a80..40427bfb. Semantic name remains unreviewed. */

uint FUN_40427a80(int param_1,int *param_2,uint param_3,uint *param_4)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  int iVar7;
  uint local_1b8 [2];
  int aiStack_1b0 [93];
  int local_3c;
  int local_38;
  int local_34;
  
  uVar3 = FUN_40423f34(param_2,param_3);
  if ((-1 < (int)uVar3) && (uVar3 = FUN_40423568(param_2,1,param_4,0), -1 < (int)uVar3)) {
    iVar7 = 0;
    uVar3 = FUN_40423c64(param_2,aiStack_1b0,1,*param_4,param_3,(int *)local_1b8);
    iVar5 = local_3c;
    iVar1 = local_38;
    iVar2 = local_34;
    while (-1 < (int)uVar3) {
      if (local_1b8[0] < 0x21) {
        piVar6 = aiStack_1b0 + local_1b8[0] * 3 + -3;
        iVar5 = FUN_40426ce4(*piVar6);
        *piVar6 = iVar5 + iVar7;
        FUN_40426f4c(param_1,piVar6);
        return uVar3;
      }
      local_3c = iVar5;
      local_38 = iVar1;
      local_34 = iVar2;
      iVar4 = FUN_40426c2c(iVar5,iVar1,iVar2);
      iVar7 = iVar4 + iVar7;
      uVar3 = FUN_40426c0c(iVar5,iVar1,iVar2);
      uVar3 = FUN_40423c64(param_2,aiStack_1b0,1,uVar3,param_3 - iVar7,(int *)local_1b8);
      iVar5 = local_3c;
      iVar1 = local_38;
      iVar2 = local_34;
    }
  }
  return uVar3;
}



/* 40427bfc FUN_40427bfc */

/* Boundary evidence: original MIPS .pdata 40427bfc..40427c4b. Semantic name remains unreviewed. */

void FUN_40427bfc(int param_1,int param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  
  if (param_2 == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = param_2 - DAT_404304bc;
  }
  *(int *)(param_1 + 0x70) = iVar1;
  *(undefined4 *)(param_1 + 0x74) = param_3;
  if (param_4 == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = param_4 - DAT_404304bc;
  }
  *(int *)(param_1 + 0x6c) = iVar1;
  FUN_40427100(param_1);
  return;
}



/* 40427c4c FUN_40427c4c */

/* Boundary evidence: original MIPS .pdata 40427c4c..40427c67. Semantic name remains unreviewed. */

void FUN_40427c4c(int param_1,uint param_2,undefined4 *param_3)

{
  FUN_4041537c((int *)(param_1 + 0x20c),param_2,param_3);
  return;
}



/* 40427c68 FUN_40427c68 */

/* Boundary evidence: original MIPS .pdata 40427c68..40427c9b. Semantic name remains unreviewed. */

void FUN_40427c68(int *param_1,undefined4 *param_2)

{
  FUN_40427c4c(*param_1 + DAT_404304bc,param_1[1],param_2);
  return;
}



/* 40427c9c FUN_40427c9c */

/* Boundary evidence: original MIPS .pdata 40427c9c..40427cd3. Semantic name remains unreviewed. */

undefined4 * FUN_40427c9c(undefined4 *param_1,undefined4 param_2)

{
  FUN_4040faec(param_1 + 1,param_2);
  *param_1 = &PTR_LAB_40402120;
  return param_1;
}



/* 40427cd4 FUN_40427cd4 */

undefined2 FUN_40427cd4(int param_1)

{
  return *(undefined2 *)(param_1 + 0x4a8);
}



/* 40427cdc FUN_40427cdc */

int FUN_40427cdc(int param_1)

{
  int iVar1;
  
  if (*(int *)(param_1 + 0x46c) == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = *(int *)(param_1 + 0x46c) + DAT_404304bc;
  }
  return iVar1;
}



/* 40427d04 FUN_40427d04 */

/* Boundary evidence: original MIPS .pdata 40427d04..40427d37. Semantic name remains unreviewed. */

void FUN_40427d04(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0xc);
  if (iVar1 == 0) {
    iVar1 = *(int *)(param_1 + 8);
  }
  FUN_4040d6c4((int *)(iVar1 + DAT_404304bc));
  return;
}



/* 40427d38 FUN_40427d38 */

/* Boundary evidence: original MIPS .pdata 40427d38..40427d6b. Semantic name remains unreviewed. */

void FUN_40427d38(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0xc);
  if (iVar1 == 0) {
    iVar1 = *(int *)(param_1 + 8);
  }
  FUN_4040d6bc(iVar1 + DAT_404304bc);
  return;
}



/* 40427d6c FUN_40427d6c */

/* Boundary evidence: original MIPS .pdata 40427d6c..40427d9f. Semantic name remains unreviewed. */

void FUN_40427d6c(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0xc);
  if (iVar1 == 0) {
    iVar1 = *(int *)(param_1 + 8);
  }
  FUN_404156c8(iVar1 + DAT_404304bc);
  return;
}



/* 40427da0 FUN_40427da0 */

bool FUN_40427da0(int param_1)

{
  return *(int *)(param_1 + 0xc) != 0;
}



/* 40427db8 FUN_40427db8 */

undefined4 FUN_40427db8(int *param_1)

{
  undefined4 uVar1;
  
  if ((*param_1 != 0) || (uVar1 = 1, param_1[5] != -2)) {
    uVar1 = 0;
  }
  return uVar1;
}



/* 40427de4 FUN_40427de4 */

/* Boundary evidence: original MIPS .pdata 40427de4..40427e33. Semantic name remains unreviewed. */

void FUN_40427de4(int param_1)

{
  int iVar1;
  uint local_10 [2];
  
  iVar1 = FUN_404155e0((int *)(param_1 + 0x31c),local_10);
  if (-1 < iVar1) {
    FUN_404284c4((int *)(*(int *)(param_1 + 0x46c) + DAT_404304bc),(HWND)(local_10[0] << 6));
  }
  return;
}



/* 40427e34 FUN_40427e34 */

/* Boundary evidence: original MIPS .pdata 40427e34..40427e5f. Semantic name remains unreviewed. */

undefined4 * FUN_40427e34(undefined4 *param_1)

{
  FUN_4040fb04(param_1);
  return param_1;
}



/* 40427e60 FUN_40427e60 */

/* Boundary evidence: original MIPS .pdata 40427e60..40427e87. Semantic name remains unreviewed. */

void FUN_40427e60(undefined4 *param_1)

{
  *param_1 = &PTR_LAB_40402144;
  FUN_404182f0();
  return;
}



/* 40427e88 FUN_40427e88 */

/* Boundary evidence: original MIPS .pdata 40427e88..40427f07. Semantic name remains unreviewed. */

void FUN_40427e88(undefined4 *param_1,int param_2,int param_3,undefined4 param_4)

{
  FUN_4040fb1c(param_1 + 2,param_2,param_3);
  param_1[0x25] = param_4;
  param_1[0x24] = param_4;
  FUN_40427bfc((int)(param_1 + 4),param_2,param_3,(int)param_1);
  (**(code **)*param_1)(param_1);
  return;
}



/* 40427f08 FUN_40427f08 */

/* Boundary evidence: original MIPS .pdata 40427f08..40427fdb. Semantic name remains unreviewed. */

int FUN_40427f08(undefined4 *param_1,int *param_2,int param_3,int param_4)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int *piVar4;
  
  piVar4 = param_1 + 2;
  if (param_4 == 0) {
    iVar1 = FUN_4041a07c(param_2,param_3,2,piVar4);
  }
  else {
    iVar1 = FUN_4041a030(param_2,param_3,2,piVar4);
  }
  if (-1 < iVar1) {
    iVar1 = FUN_40427c68(piVar4,param_1 + 0x24);
    param_1[0x25] = param_1[0x24];
    if (-1 < iVar1) {
      (**(code **)*param_1)(param_1);
    }
    uVar2 = FUN_4041ab00((int)piVar4);
    iVar3 = FUN_4042010c(piVar4);
    FUN_40427bfc((int)(param_1 + 4),iVar3,uVar2,(int)param_1);
  }
  return iVar1;
}



/* 40427fdc FUN_40427fdc */

/* Boundary evidence: original MIPS .pdata 40427fdc..4042833b. Semantic name remains unreviewed. */

uint FUN_40427fdc(int param_1,uint param_2,int param_3,int param_4,int *param_5)

{
  uint uVar1;
  uint uVar2;
  undefined2 uVar3;
  int *piVar4;
  uint uVar5;
  undefined2 extraout_var;
  int iVar6;
  int iVar7;
  int *piVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  ushort local_1e0;
  ushort local_1de;
  uint local_1dc;
  uint local_1d4;
  int local_1d0;
  int local_1cc;
  int local_1c8;
  int local_1c4;
  uint local_1c0;
  uint uStack_1b8;
  uint local_1b4 [99];
  
  piVar4 = (int *)FUN_4042010c((int *)(param_1 + 8));
  *param_5 = 0;
  if (piVar4 == (int *)0x0) {
    uVar5 = 0x800300fd;
  }
  else {
    uVar5 = *(uint *)(param_1 + 0x90);
    if ((param_2 < uVar5) && (param_4 != 0)) {
      if (uVar5 < param_2 + param_4) {
        param_4 = uVar5 - param_2;
      }
      local_1d0 = FUN_404156d8((int)piVar4);
      local_1de = FUN_4040d6bc((int)piVar4);
      local_1e0 = FUN_404156c8((int)piVar4);
      uVar3 = FUN_40427cd4((int)piVar4);
      uVar15 = CONCAT22(extraout_var,uVar3);
      if (((uVar5 < 0x1000) && (iVar6 = FUN_40421714((int)piVar4), iVar6 == 0)) &&
         (iVar6 = FUN_4041ab00(param_1 + 8), iVar6 != 0)) {
        local_1de = 0x40;
        local_1e0 = 6;
        uVar15 = 0x3f;
        local_1d0 = FUN_4040fae4((int)piVar4);
      }
      local_1c0 = (uint)local_1e0;
      uVar11 = param_2 >> (local_1c0 & 0x1f);
      local_1c4 = param_1 + 0x10;
      uVar14 = (((param_2 + param_4) - 1 >> (local_1c0 & 0x1f)) - uVar11) + 1;
      iVar6 = 0;
      uVar12 = uVar15 & param_2;
      uVar5 = FUN_4042783c(local_1c4,uVar11,0,&uStack_1b8,uVar14,(int *)&local_1d4);
      local_1dc = uVar11;
      while (-1 < (int)uVar5) {
        if (0x20 < local_1d4) {
          return 0x8000ffff;
        }
        uVar5 = local_1de + 0xffff & 0xffff;
        uVar13 = 0;
        if (local_1d4 != 0) {
          local_1c8 = FUN_4040fae4((int)piVar4);
          do {
            uVar9 = local_1b4[uVar13 * 3];
            uVar10 = local_1b4[uVar13 * 3 + 1];
            if (uVar14 < local_1b4[uVar13 * 3 + 1]) {
              uVar10 = uVar14;
            }
            uVar11 = uVar10 + local_1dc;
            uVar14 = uVar14 - uVar10;
            uVar13 = uVar13 + 1 & 0xffff;
            if (uVar14 == 0) {
              uVar5 = (uint)(short)((short)(param_2 + param_4) - 1U & (ushort)uVar15);
            }
            uVar1 = local_1c0 & 0x1f;
            if (local_1c8 == local_1d0) {
              uVar2 = local_1c0 & 0x1f;
              iVar7 = FUN_40427cdc((int)piVar4);
              uVar12 = FUN_40427fdc(iVar7,(uVar9 << uVar2) + uVar12,param_3,
                                    ((uVar10 - 1 << uVar1) - uVar12) + uVar5 + 1,&local_1cc);
            }
            else {
              FUN_404157c4(uVar9,(int)(short)uVar12,(uint)local_1e0);
              piVar8 = (int *)FUN_4040d6c4(piVar4);
              uVar12 = (**(code **)(*piVar8 + 0xc))(piVar8);
            }
            iVar6 = local_1cc + iVar6;
            if ((uVar14 == 0) || ((int)uVar12 < 0)) {
              *param_5 = iVar6;
              return uVar12;
            }
            param_3 = local_1cc + param_3;
            uVar12 = 0;
            local_1dc = uVar11;
          } while (uVar13 < local_1d4);
        }
        uVar5 = FUN_4042783c(local_1c4,uVar11,0,&uStack_1b8,uVar14,(int *)&local_1d4);
      }
    }
    else {
      uVar5 = 0;
    }
  }
  return uVar5;
}



/* 4042833c FUN_4042833c */

/* Boundary evidence: original MIPS .pdata 4042833c..404284c3. Semantic name remains unreviewed. */

int FUN_4042833c(int *param_1,int param_2,void *param_3,int param_4,int *param_5)

{
  int *piVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int *piVar5;
  
  *param_5 = 0;
  if (param_4 == 0) {
    uVar2 = 0;
  }
  else {
    piVar5 = param_1 + 2;
    piVar1 = (int *)FUN_4042010c(piVar5);
    if (piVar1 == (int *)0x0) {
      uVar2 = 0x800300fd;
    }
    else {
      if ((((uint)(param_2 + param_4) <= (uint)param_1[0x24]) || (0x1000 < (uint)param_1[0x24])) ||
         (uVar2 = (**(code **)(*param_1 + 0x1c))(param_1), -1 < (int)uVar2)) {
        uVar4 = param_1[0x24];
        uVar2 = FUN_4041ab00((int)piVar5);
        uVar2 = FUN_40416c74(piVar1,uVar2,(uint)(uVar4 < 0x1000),param_2,param_3,param_4,
                             (int)(param_1 + 4),param_5);
      }
      if ((*param_5 != 0) && (uVar4 = *param_5 + param_2, (uint)param_1[0x24] < uVar4)) {
        param_1[0x24] = uVar4;
        uVar3 = FUN_4041ab00((int)piVar5);
        piVar1 = (int *)FUN_404156e8((int)piVar1);
        uVar4 = FUN_4041f430(piVar1,uVar3,uVar4);
        if ((-1 < (int)uVar2) && ((int)uVar4 < 0)) {
          uVar2 = uVar4;
        }
      }
    }
  }
  return uVar2;
}



/* 404284c4 FUN_404284c4 */

/* Boundary evidence: original MIPS .pdata 404284c4..4042898f. Semantic name remains unreviewed. */

uint FUN_404284c4(int *param_1,HWND param_2)

{
  undefined2 uVar1;
  uint uVar2;
  int *holemenu;
  undefined2 extraout_var;
  int *piVar3;
  int iVar4;
  LPOLEINPLACEFRAME lpFrame;
  HWND pHVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  IOleInPlaceActiveObject *in_stack_ffffffb0;
  ushort local_48 [2];
  int *local_44;
  uint local_40;
  uint local_3c;
  int *local_38;
  undefined *local_34;
  uint local_30;
  IOleInPlaceActiveObject local_2c;
  
  local_34 = (undefined *)0x0;
  uVar2 = FUN_4041ab00((int)(param_1 + 2));
  holemenu = (int *)FUN_4042010c(param_1 + 2);
  if (holemenu == (int *)0x0) {
    return 0x800300fd;
  }
  local_38 = (int *)FUN_404156e8((int)holemenu);
  pHVar5 = (HWND)param_1[0x24];
  if (pHVar5 == param_2) {
    return 0;
  }
  uVar1 = FUN_4040d6bc((int)holemenu);
  uVar6 = CONCAT22(extraout_var,uVar1);
  piVar3 = (int *)FUN_404156d8((int)holemenu);
  local_44 = piVar3;
  iVar4 = FUN_40421714((int)holemenu);
  uVar7 = uVar6;
  if ((iVar4 == 0) && (uVar2 != 0)) {
    if (param_2 < (HWND)0x1000) {
      uVar7 = 0x40;
      piVar3 = (int *)FUN_4040fae4((int)holemenu);
    }
    if (pHVar5 < (HWND)0x1000) {
      uVar6 = 0x40;
      local_44 = (int *)FUN_4040fae4((int)holemenu);
    }
  }
  uVar8 = ((int)pHVar5 + (uVar6 - 1)) / uVar6;
  if (uVar6 == 0) {
    trap(0x1c00);
  }
  uVar9 = ((int)param_2 + (uVar7 - 1)) / uVar7;
  if (uVar7 == 0) {
    trap(0x1c00);
  }
  local_40 = uVar7;
  local_30 = uVar6;
  uVar6 = FUN_40415300(local_38,uVar2,&local_3c);
  uVar7 = local_3c;
  if ((int)uVar6 < 0) goto LAB_40428938;
  uVar6 = 0;
  local_48[0] = 0;
  if (local_30 != local_40) {
    pHVar5 = (HWND)param_1[0x24];
    if (param_2 <= (HWND)param_1[0x24]) {
      pHVar5 = param_2;
    }
    uVar6 = (uint)pHVar5 & 0xffff;
    local_48[0] = (ushort)pHVar5;
  }
  if (uVar6 == 0) {
    if (uVar9 < uVar8) {
      uVar6 = uVar9;
      if (uVar9 == 0) {
        uVar6 = FUN_4041f3b4(local_38,uVar2,0xfffffffe);
        if ((int)uVar6 < 0) goto LAB_40428938;
        local_3c = 0xfffffffe;
        uVar6 = 0;
      }
      piVar3 = local_44;
      uVar6 = FUN_404225f0(local_44,uVar7,uVar6);
      if ((int)uVar6 < 0) goto LAB_40428938;
      FUN_40427100((int)(param_1 + 4));
    }
    else {
      if (uVar8 == 0) goto LAB_404286c4;
      piVar3 = local_44;
      if (uVar8 < uVar9) {
        uVar6 = FUN_404273b4((int)(param_1 + 4),uVar9 - 1,(int *)&local_2c);
        goto LAB_40428780;
      }
    }
LAB_40428794:
    if (((((local_30 == 0x40) && (uVar8 != 0)) || ((local_40 == 0x40 && (uVar9 != 0)))) &&
        (uVar6 = FUN_40427de4((int)holemenu), (int)uVar6 < 0)) ||
       ((uVar6 = FUN_404157d4(holemenu), (int)uVar6 < 0 ||
        (((local_3c != uVar7 && (uVar6 = FUN_4041f3b4(local_38,uVar2,local_3c), (int)uVar6 < 0)) ||
         (uVar6 = FUN_4041f430(local_38,uVar2,param_2), (int)uVar6 < 0)))))) goto LAB_40428938;
    param_1[0x24] = (int)param_2;
    if (local_48[0] != 0) {
      in_stack_ffffffb0 = &local_2c;
      uVar6 = (**(code **)(*param_1 + 0x18))(param_1,0,local_34);
      if ((int)uVar6 < 0) goto LAB_40428938;
      if (local_2c.lpVtbl != (IOleInPlaceActiveObjectVtbl *)(uint)local_48[0]) goto LAB_40428878;
      uVar6 = FUN_404225f0(piVar3,uVar7,0);
      if ((((int)uVar6 < 0) || (uVar6 = FUN_40427de4((int)holemenu), (int)uVar6 < 0)) ||
         (uVar6 = FUN_404157d4(holemenu), (int)uVar6 < 0)) goto LAB_40428938;
    }
    if (((uVar8 < uVar9) || (local_48[0] != 0)) &&
       (((local_40 - 1 & (uint)param_2) != 0 &&
        (uVar6 = FUN_40427164((int)(param_1 + 4),uVar9 - 1,(uint *)&local_2c), -1 < (int)uVar6)))) {
      if (((HWND)0xfff < param_2) || (lpFrame = (LPOLEINPLACEFRAME)0x1, uVar2 == 0)) {
        lpFrame = (LPOLEINPLACEFRAME)0x0;
      }
      OleSetMenuDescriptor(holemenu,(HWND)local_2c.lpVtbl,param_2,lpFrame,in_stack_ffffffb0);
    }
  }
  else {
    FUN_40415908(uVar6,uVar6,(int *)&local_34,local_48);
    in_stack_ffffffb0 = &local_2c;
    uVar6 = (**(code **)(*param_1 + 0x14))(param_1,0,local_34,local_48[0]);
    if ((int)uVar6 < 0) goto LAB_40428938;
    if (local_2c.lpVtbl == (IOleInPlaceActiveObjectVtbl *)(uint)local_48[0]) {
      FUN_40427100((int)(param_1 + 4));
LAB_404286c4:
      uVar6 = FUN_40427a80((int)(param_1 + 4),piVar3,uVar9,&local_3c);
LAB_40428780:
      piVar3 = local_44;
      if ((int)uVar6 < 0) goto LAB_40428938;
      goto LAB_40428794;
    }
LAB_40428878:
    uVar6 = 0x800300fd;
  }
LAB_40428938:
  if (local_34 != (undefined *)0x0) {
    FUN_4041598c(local_34);
  }
  if ((int)uVar6 < 0) {
    FUN_40427100((int)(param_1 + 4));
  }
  return uVar6;
}



/* 40428990 FUN_40428990 */

/* Boundary evidence: original MIPS .pdata 40428990..40429123. Semantic name remains unreviewed. */

uint FUN_40428990(int *param_1,uint param_2,int *param_3)

{
  undefined *puVar1;
  bool bVar2;
  ushort uVar3;
  undefined3 extraout_var;
  int *piVar4;
  uint uVar5;
  int *piVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  int *piVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  undefined1 *puVar15;
  uint local_5c;
  uint local_58;
  uint local_54;
  undefined *local_50;
  uint local_4c;
  uint local_48;
  undefined *local_44;
  uint local_40;
  uint local_3c;
  undefined1 auStack_38 [4];
  uint local_34;
  int *local_30;
  uint local_2c;
  
  local_50 = (undefined *)0x0;
  if (param_3 == (int *)0x0) {
    iVar7 = 0;
  }
  else {
    iVar7 = (int)param_3 - DAT_404304bc;
  }
  uVar8 = param_1[0x24];
  param_1[0x27] = iVar7;
  param_1[0x25] = uVar8;
  bVar2 = FUN_40427da0((int)param_3);
  if ((((CONCAT31(extraout_var,bVar2) == 0) || (param_2 < 0x1000)) ||
      ((uVar8 < 0x1000 && (uVar8 != 0)))) || (iVar7 = FUN_40427db8(param_3), iVar7 != 0)) {
    uVar8 = (**(code **)(*param_1 + 0x1c))(param_1,param_2);
    if ((-1 < (int)uVar8) && (iVar7 = FUN_40427db8(param_3), iVar7 == 0)) {
      uVar14 = FUN_40427d38((int)param_3);
      uVar3 = FUN_40427d6c((int)param_3);
      local_4c = uVar14;
      FUN_40415908(uVar14,uVar14 * 0xf & 0xffff,(int *)&local_50,(undefined2 *)&local_5c);
      local_44 = local_50;
      uVar5 = (int)(local_5c & 0xffff) / (int)uVar14;
      if (uVar14 == 0) {
        trap(0x1c00);
      }
      if ((uVar14 == 0xffffffff) && ((local_5c & 0xffff) == 0x80000000)) {
        trap(0x1800);
      }
      if (uVar14 == 0) {
        trap(0x1c00);
      }
      local_58 = CONCAT22(local_58._2_2_,(short)((param_1[0x24] - 1U) % uVar14) + 1);
      local_34 = ((uVar14 + param_1[0x24]) - 1) / uVar14;
      if (uVar14 == 0) {
        trap(0x1c00);
      }
      uVar10 = 0xfffffffe;
      local_54 = 0xfffffffe;
      local_48 = 0xfffffffe;
      uVar13 = 0;
      local_2c = uVar14;
      local_30 = (int *)FUN_40427d04((int)param_3);
      uVar12 = 0;
      uVar14 = uVar10;
      if (local_34 != 0) {
        local_40 = local_4c * -2;
        local_3c = 0;
        uVar9 = uVar10;
        do {
          if (uVar9 == 0xfffffffe) {
            uVar10 = uVar12;
            local_40 = local_3c;
          }
          uVar8 = FUN_4042e104(param_3,uVar12,2,&local_48);
          if ((int)uVar8 < 0) goto LAB_404290e8;
          if ((uVar13 == 0) ||
             (((local_48 != 0xfffffffe && (local_48 == uVar13 + local_54)) &&
              (uVar12 - uVar10 != (uVar5 & 0xffff))))) {
            if (local_48 == 0xfffffffe) goto LAB_4042900c;
            if (local_54 == 0xfffffffe) goto LAB_40428f80;
            if (local_48 == uVar13 + local_54) {
              uVar13 = uVar13 + 1 & 0xffff;
            }
LAB_40428fa0:
            uVar14 = local_54;
            if (uVar12 - uVar10 == (uVar5 & 0xffff)) goto LAB_40428fb0;
          }
          else {
            FUN_404157c4(local_54,0,(uint)uVar3);
            puVar1 = local_44;
            uVar8 = (**(code **)(*local_30 + 0xc))(local_30);
            if ((int)uVar8 < 0) goto LAB_404290e8;
            local_44 = puVar1 + uVar13 * local_2c;
            local_54 = local_48;
            if (local_48 != 0xfffffffe) {
LAB_40428f80:
              uVar13 = 1;
              local_54 = local_48;
              goto LAB_40428fa0;
            }
            uVar13 = 0;
LAB_4042900c:
            if (uVar10 == uVar12) goto LAB_40428fa0;
LAB_40428fb0:
            uVar14 = local_54;
            uVar8 = (**(code **)(*param_1 + 0x18))
                              (param_1,local_40,local_50,(uVar12 - uVar10) * local_4c,auStack_38);
            if ((int)uVar8 < 0) goto LAB_404290e8;
            local_44 = local_50;
            local_40 = local_3c;
            uVar10 = uVar12;
          }
          local_3c = local_3c + local_4c;
          uVar12 = uVar12 + 1;
          uVar9 = local_48;
        } while (uVar12 < local_34);
      }
      if (uVar13 != 0) {
        FUN_404157c4(uVar14,0,(uint)uVar3);
        uVar14 = local_4c;
        iVar7 = uVar13 * local_4c;
        puVar15 = auStack_38;
        uVar8 = (**(code **)(*local_30 + 0xc))();
        if (-1 < (int)uVar8) {
          uVar8 = (**(code **)(*param_1 + 0x18))
                            (param_1,uVar14 * uVar10,local_50,
                             ((uVar12 - uVar10) + -1) * uVar14 + (int)(short)local_58,auStack_38,
                             iVar7,puVar15);
        }
      }
    }
  }
  else {
    uVar8 = FUN_40427d38((int)param_3);
    uVar14 = ((uVar8 + param_2) - 1) / uVar8;
    if (uVar8 == 0) {
      trap(0x1c00);
    }
    piVar11 = param_1 + 2;
    local_54 = 0xfffffffe;
    param_1[0x24] = param_2;
    uVar8 = FUN_4041ab00((int)piVar11);
    iVar7 = FUN_4042010c(piVar11);
    piVar4 = (int *)FUN_404156e8(iVar7);
    uVar8 = FUN_4041f430(piVar4,uVar8,param_2);
    if (-1 < (int)uVar8) {
      if ((uint)param_1[0x24] < (uint)param_1[0x25]) {
        uVar5 = FUN_4041ab00((int)piVar11);
        iVar7 = FUN_4042010c(piVar11);
        piVar4 = (int *)FUN_404156e8(iVar7);
        FUN_40415300(piVar4,uVar5,&local_30);
        iVar7 = FUN_4042010c(piVar11);
        piVar4 = (int *)FUN_404156d8(iVar7);
        FUN_404225f0(piVar4,(uint)local_30,uVar14);
        FUN_40427100((int)(param_1 + 4));
      }
      uVar5 = 0;
      if (uVar14 != 0) {
        while (uVar8 = FUN_4042e104(param_3,uVar5,2,&local_5c), -1 < (int)uVar8) {
          if (local_5c != 0xfffffffe) {
            if (uVar5 == 0) {
              iVar7 = FUN_4042010c(piVar11);
              piVar4 = (int *)FUN_404156d8(iVar7);
              iVar7 = FUN_4042010c(piVar11);
              piVar6 = (int *)FUN_404156e8(iVar7);
              local_58 = 0xfffffffe;
              uVar8 = FUN_4041ab00((int)piVar11);
              uVar8 = FUN_40415300(piVar6,uVar8,&local_54);
              if (((int)uVar8 < 0) ||
                 (((local_54 != 0xfffffffe &&
                   ((uVar8 = FUN_40421b54(piVar4,local_54,&local_58), (int)uVar8 < 0 ||
                    (uVar8 = FUN_404221f0(piVar4,local_54,-1), (int)uVar8 < 0)))) ||
                  (uVar8 = FUN_404221f0(piVar4,local_5c,local_58), (int)uVar8 < 0)))) break;
              uVar8 = FUN_4041ab00((int)piVar11);
              uVar8 = FUN_4041f3b4(piVar6,uVar8,local_5c);
            }
            else {
              iVar7 = FUN_4042010c(piVar11);
              piVar4 = (int *)FUN_404156d8(iVar7);
              uVar8 = FUN_40427164((int)(param_1 + 4),uVar5 - 1,&local_54);
              if ((((int)uVar8 < 0) ||
                  (uVar8 = FUN_40421b54(piVar4,local_54,&local_3c), (int)uVar8 < 0)) ||
                 (uVar8 = FUN_404221f0(piVar4,local_54,local_5c), (int)uVar8 < 0)) break;
              if (local_3c == 0xfffffffe) {
                local_58 = 0xfffffffe;
              }
              else {
                uVar8 = FUN_40421b54(piVar4,local_3c,&local_58);
                if (((int)uVar8 < 0) || (uVar8 = FUN_404221f0(piVar4,local_3c,-1), (int)uVar8 < 0))
                break;
              }
              uVar8 = FUN_404221f0(piVar4,local_5c,local_58);
            }
            if (((int)uVar8 < 0) ||
               (uVar8 = FUN_404276f8((int)(param_1 + 4),uVar5,uVar5), (int)uVar8 < 0)) break;
          }
          uVar5 = uVar5 + 1;
          if (uVar14 <= uVar5) break;
        }
      }
    }
  }
LAB_404290e8:
  FUN_4041598c(local_50);
  return uVar8;
}



/* 40429124 FUN_40429124 */

/* Boundary evidence: original MIPS .pdata 40429124..4042915f. Semantic name remains unreviewed. */

void FUN_40429124(int param_1,uint param_2)

{
  if ((param_2 & 8) == 0) {
    *(undefined4 *)(param_1 + 0x90) = *(undefined4 *)(param_1 + 0x94);
    FUN_40427100(param_1 + 0x10);
  }
  *(undefined4 *)(param_1 + 0x9c) = 0;
  return;
}



/* 40429170 FUN_40429170 */

void FUN_40429170(int param_1,undefined4 *param_2)

{
  *param_2 = *(undefined4 *)(param_1 + 0x90);
  return;
}



/* 4042917c FUN_4042917c */

/* Boundary evidence: original MIPS .pdata 4042917c..404291cb. Semantic name remains unreviewed. */

undefined4 * FUN_4042917c(undefined4 *param_1,undefined4 param_2)

{
  FUN_40427c9c(param_1,param_2);
  *param_1 = &PTR_LAB_40402144;
  FUN_40427e34(param_1 + 2);
  FUN_404270a4((int)(param_1 + 4));
  param_1[0x27] = 0;
  param_1[0x26] = 0;
  return param_1;
}



/* 404291cc FUN_404291cc */

/* Boundary evidence: original MIPS .pdata 404291cc..404291f7. Semantic name remains unreviewed. */

void FUN_404291cc(undefined4 *param_1)

{
  int iVar1;
  
  iVar1 = param_1[0x26];
  param_1[0x26] = iVar1 + -1;
  if (iVar1 + -1 == 0) {
    FUN_4041a81c(param_1,1);
  }
  return;
}



/* 40429204 FUN_40429204 */

/* Boundary evidence: original MIPS .pdata 40429204..404292eb. Semantic name remains unreviewed. */

void FUN_40429204(int *param_1,int *param_2)

{
  int iVar1;
  _FILETIME local_18;
  
  if (param_2 == (int *)0x0) {
    iVar1 = FUN_40419894(&local_18);
    if (-1 < iVar1) {
      param_1[0x27] = local_18.dwLowDateTime;
      param_1[0x28] = local_18.dwHighDateTime;
      param_1[0x29] = local_18.dwLowDateTime;
      param_1[0x2a] = local_18.dwHighDateTime;
      param_1[0x2b] = local_18.dwLowDateTime;
      param_1[0x2c] = local_18.dwHighDateTime;
      param_1[0x2f] = 0;
      param_1[0x30] = 0;
      param_1[0x31] = 0;
      param_1[0x32] = 0;
      param_1[0x33] = 0;
    }
  }
  else {
    iVar1 = FUN_4040b72c(param_1,param_2);
    if (-1 < iVar1) {
      param_1[0x2e] = param_1[0x2e] & 0xfffffff8;
      iVar1 = (**(code **)(*param_2 + 0x20))(param_2,param_1 + 0x2f);
      if (-1 < iVar1) {
        (**(code **)(*param_2 + 0x28))(param_2,param_1 + 0x33);
      }
    }
  }
  return;
}



/* 404292ec FUN_404292ec */

/* Boundary evidence: original MIPS .pdata 404292ec..404293e7. Semantic name remains unreviewed. */

void FUN_404292ec(int param_1,ushort *param_2)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  
  if (param_2[0x41] == 0) {
    iVar3 = *(int *)(param_1 + 0xd0) + DAT_404304bc;
    if (*(int *)(param_1 + 0xd0) == 0) {
      iVar3 = 0;
    }
    FUN_4040dcb0(*(int *)(param_1 + 0xb4) + DAT_404304bc,*(int *)(param_2 + 0x42),2);
    if ((*(uint *)(param_2 + 0x44) & 3) == 1) {
      FUN_40417ee8((int *)(iVar3 + 0x30),1);
      iVar2 = *(int *)(param_1 + 0xb4) + DAT_404304bc;
      piVar1 = (int *)(iVar3 + 0x38);
    }
    else {
      FUN_40417ee8((int *)(iVar3 + 0x34),1);
      iVar2 = *(int *)(param_1 + 0xb4) + DAT_404304bc;
      piVar1 = (int *)(iVar3 + 0x3c);
    }
    FUN_40417ee8(piVar1,*(int *)(iVar2 + 100) + -1);
  }
  else if (param_2[0x20] != 0) {
    FUN_404187a8((int *)(*(int *)(param_1 + 0xb4) + DAT_404304bc + 0x54),param_2,
                 *(int *)(param_1 + 0x20),param_2 + 0x21);
  }
  return;
}



/* 404293e8 FUN_404293e8 */

/* Boundary evidence: original MIPS .pdata 404293e8..40429427. Semantic name remains unreviewed. */

void FUN_404293e8(int param_1)

{
  if (*(int *)(param_1 + 0x8c) != 0) {
    (**(code **)(*(int *)(DAT_404304bc + *(int *)(param_1 + 0x8c)) + 4))();
  }
  return;
}



/* 40429428 FUN_40429428 */

/* Boundary evidence: original MIPS .pdata 40429428..404294fb. Semantic name remains unreviewed. */

void * FUN_40429428(void *param_1,void *param_2,void *param_3,undefined4 param_4,undefined4 param_5,
                   int param_6)

{
  int iVar1;
  
  *(undefined2 *)((int)param_1 + 0x40) = 0;
  *(undefined2 *)((int)param_1 + 0x82) = 0;
  if (param_2 == (void *)0x0) {
    *(undefined2 *)((int)param_1 + 0x40) = 0;
  }
  else {
    memcpy(param_1,param_2,0x42);
  }
  if (param_3 == (void *)0x0) {
    *(undefined2 *)((int)param_1 + 0x82) = 0;
  }
  else {
    memcpy((void *)((int)param_1 + 0x42),param_3,0x42);
  }
  *(undefined4 *)((int)param_1 + 0x84) = param_4;
  *(undefined4 *)((int)param_1 + 0x88) = param_5;
  if (param_6 == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = param_6 - DAT_404304bc;
  }
  *(int *)((int)param_1 + 0x8c) = iVar1;
  *(undefined4 *)((int)param_1 + 0x94) = 0;
  *(undefined4 *)((int)param_1 + 0x90) = 0;
  if (iVar1 != 0) {
    (*(code *)**(undefined4 **)(iVar1 + DAT_404304bc))();
  }
  return param_1;
}



/* 404294fc FUN_404294fc */

void FUN_404294fc(int *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  if (param_1[1] == 0) {
    if (param_2 == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = param_2 - DAT_404304bc;
    }
    *param_1 = iVar1;
  }
  else {
    iVar1 = param_2 - DAT_404304bc;
    if (param_2 == 0) {
      iVar1 = 0;
    }
    *(int *)(param_1[1] + DAT_404304bc + 0x90) = iVar1;
  }
  if (param_1[1] == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = param_1[1] + DAT_404304bc;
  }
  iVar2 = iVar1 - DAT_404304bc;
  if (iVar1 == 0) {
    iVar2 = 0;
  }
  *(int *)(param_2 + 0x94) = iVar2;
  *(undefined4 *)(param_2 + 0x90) = 0;
  param_1[1] = param_2 - DAT_404304bc;
  return;
}



/* 40429588 FUN_40429588 */

void FUN_40429588(int *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = *(int *)(param_2 + 0x90);
  iVar2 = iVar1 + DAT_404304bc;
  if (iVar1 == 0) {
    iVar2 = 0;
  }
  iVar3 = *(int *)(param_2 + 0x94) + DAT_404304bc;
  if (*(int *)(param_2 + 0x94) == 0) {
    iVar3 = 0;
  }
  if (iVar1 == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = iVar1 + DAT_404304bc;
  }
  if (iVar1 != 0) {
    iVar1 = iVar3 - DAT_404304bc;
    if (iVar3 == 0) {
      iVar1 = 0;
    }
    *(int *)(iVar2 + 0x94) = iVar1;
  }
  iVar1 = *(int *)(param_2 + 0x94) + DAT_404304bc;
  if (*(int *)(param_2 + 0x94) == 0) {
    iVar1 = 0;
  }
  if (iVar1 != 0) {
    iVar1 = iVar2 - DAT_404304bc;
    if (iVar2 == 0) {
      iVar1 = 0;
    }
    *(int *)(iVar3 + 0x90) = iVar1;
  }
  if (param_2 == *param_1 + DAT_404304bc) {
    if (iVar2 == 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = iVar2 - DAT_404304bc;
    }
    *param_1 = iVar2;
  }
  if (param_2 == DAT_404304bc + param_1[1]) {
    iVar1 = iVar3 - DAT_404304bc;
    if (iVar3 == 0) {
      iVar1 = 0;
    }
    param_1[1] = iVar1;
  }
  *(undefined4 *)(param_2 + 0x90) = 0;
  *(undefined4 *)(param_2 + 0x94) = 0;
  return;
}



/* 40429664 FUN_40429664 */

/* Boundary evidence: original MIPS .pdata 40429664..404296f7. Semantic name remains unreviewed. */

void FUN_40429664(int *param_1)

{
  LPVOID pvVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = *param_1;
  while (iVar2 != 0) {
    pvVar1 = (LPVOID)(*param_1 + DAT_404304bc);
    iVar3 = *(int *)((int)pvVar1 + 0x90) + DAT_404304bc;
    if (*(int *)((int)pvVar1 + 0x90) == 0) {
      iVar3 = 0;
    }
    if (*param_1 == 0) {
      pvVar1 = (LPVOID)0x0;
    }
    if (pvVar1 != (LPVOID)0x0) {
      FUN_40418890(pvVar1,1);
    }
    iVar2 = iVar3 - DAT_404304bc;
    if (iVar3 == 0) {
      iVar2 = 0;
    }
    *param_1 = iVar2;
  }
  param_1[1] = 0;
  return;
}



/* 404296f8 FUN_404296f8 */

/* Boundary evidence: original MIPS .pdata 404296f8..404297bb. Semantic name remains unreviewed. */

undefined4 FUN_404296f8(int param_1,ushort *param_2,undefined4 *param_3)

{
  int iVar1;
  ushort *puVar2;
  undefined4 uVar3;
  
  iVar1 = *(int *)(param_1 + 4);
  uVar3 = 2;
  while( true ) {
    if (iVar1 == 0) {
      puVar2 = (ushort *)0x0;
    }
    else {
      puVar2 = (ushort *)(iVar1 + DAT_404304bc);
    }
    if (puVar2 == (ushort *)0x0) goto LAB_4042978c;
    iVar1 = FUN_404197c0(param_2,puVar2);
    if (iVar1 != 0) break;
    iVar1 = FUN_404197c0(param_2,puVar2 + 0x21);
    if (iVar1 != 0) {
      uVar3 = 1;
LAB_4042978c:
      if (param_3 != (undefined4 *)0x0) {
        *param_3 = puVar2;
      }
      return uVar3;
    }
    iVar1 = *(int *)(puVar2 + 0x4a);
  }
  uVar3 = 0;
  goto LAB_4042978c;
}



/* 404297bc FUN_404297bc */

/* Boundary evidence: original MIPS .pdata 404297bc..4042987b. Semantic name remains unreviewed. */

ushort * FUN_404297bc(ushort *param_1,undefined4 *param_2)

{
  ushort *puVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = DAT_404304bc;
  do {
    if (param_1 == (ushort *)0x0) {
      return (ushort *)0x0;
    }
    if (((param_1[0x20] == 0) || (param_1[0x41] == 0)) ||
       (iVar2 = FUN_404197c0((ushort *)*param_2,param_1), iVar3 = DAT_404304bc, iVar2 == 0)) {
      if ((param_1[0x41] == 0) &&
         (iVar2 = FUN_404197c0((ushort *)*param_2,param_1), iVar3 = DAT_404304bc, iVar2 != 0)) {
        return param_1;
      }
    }
    else {
      *param_2 = param_1 + 0x21;
      iVar3 = DAT_404304bc;
    }
    puVar1 = param_1 + 0x4a;
    param_1 = (ushort *)(*(int *)puVar1 + iVar3);
    if (*(int *)puVar1 == 0) {
      param_1 = (ushort *)0x0;
    }
  } while( true );
}



/* 4042987c FUN_4042987c */

/* Boundary evidence: original MIPS .pdata 4042987c..4042990b. Semantic name remains unreviewed. */

void * FUN_4042987c(int *param_1,undefined4 param_2,void *param_3,void *param_4,undefined4 param_5,
                   undefined4 param_6,int param_7)

{
  void *pvVar1;
  
  pvVar1 = (void *)FUN_4040a638(0x98);
  if (pvVar1 == (void *)0x0) {
    pvVar1 = (void *)0x0;
  }
  else {
    pvVar1 = FUN_40429428(pvVar1,param_3,param_4,param_5,param_6,param_7);
  }
  if (pvVar1 != (void *)0x0) {
    FUN_404294fc(param_1,(int)pvVar1);
  }
  return pvVar1;
}



/* 4042990c FUN_4042990c */

/* Boundary evidence: original MIPS .pdata 4042990c..40429957. Semantic name remains unreviewed. */

undefined4 * FUN_4042990c(undefined4 *param_1,uint param_2)

{
  FUN_4042bc58(param_1);
  if ((param_2 & 1) != 0) {
    FUN_4040a65c(param_1);
  }
  return param_1;
}



/* 40429958 FUN_40429958 */

/* Boundary evidence: original MIPS .pdata 40429958..404299df. Semantic name remains unreviewed. */

undefined4 * FUN_40429958(int param_1,void *param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  
  piVar4 = (int *)(*(int *)(param_1 + 0xd0) + DAT_404304bc);
  if (*(int *)(param_1 + 0xd0) == 0) {
    piVar4 = (int *)0x0;
  }
  iVar2 = piVar4[0xf];
  puVar1 = (undefined4 *)(iVar2 + DAT_404304bc);
  if (iVar2 == 0) {
    puVar1 = (undefined4 *)0x0;
  }
  piVar4[0xf] = *(int *)(iVar2 + DAT_404304bc);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    iVar2 = piVar4[1] + DAT_404304bc;
    if (piVar4[1] == 0) {
      iVar2 = 0;
    }
    iVar3 = *piVar4 + DAT_404304bc;
    if (*piVar4 == 0) {
      iVar3 = 0;
    }
    puVar1 = FUN_4042c044(puVar1,param_2,param_3,param_4,iVar3,iVar2);
  }
  return puVar1;
}



/* 404299e0 FUN_404299e0 */

/* Boundary evidence: original MIPS .pdata 404299e0..40429c2f. Semantic name remains unreviewed. */

int FUN_404299e0(int param_1,ushort *param_2,undefined4 param_3,int *param_4)

{
  undefined4 *puVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  ushort *local_30;
  int *local_2c;
  ushort *local_28 [2];
  
  puVar1 = (undefined4 *)
           FUN_404182f8((int *)(*(int *)(param_1 + 0xb4) + DAT_404304bc + 0x54),param_2,
                        *(int *)(param_1 + 0x20));
  if (puVar1 == (undefined4 *)0x0) {
    if (*(int *)(param_1 + 0x74) != 0) {
      iVar2 = FUN_404296f8(param_1 + 0x78,param_2,(undefined4 *)0x0);
      if (iVar2 != 1) {
        local_30 = param_2;
        iVar2 = FUN_404296f8(param_1 + 0x78,param_2,local_28);
        if (((iVar2 == 0) && (local_28[0][0x20] != 0)) && (local_28[0][0x41] != 0)) {
          local_30 = local_28[0];
          FUN_404297bc(local_28[0],&local_30);
        }
        piVar3 = (int *)(*(int *)(param_1 + 0x74) + DAT_404304bc);
        iVar2 = (**(code **)(*piVar3 + 0x3c))(piVar3,local_30,param_3,&local_2c);
        if (-1 < iVar2) {
          puVar1 = (undefined4 *)FUN_4040a638(0xa8);
          if (puVar1 == (undefined4 *)0x0) {
            puVar1 = (undefined4 *)0x0;
          }
          else {
            piVar3 = (int *)(*(int *)(param_1 + 0xd0) + DAT_404304bc);
            iVar2 = piVar3[1];
            iVar5 = iVar2 + DAT_404304bc;
            if (iVar2 == 0) {
              iVar5 = 0;
            }
            iVar2 = *piVar3;
            iVar4 = iVar2 + DAT_404304bc;
            if (iVar2 == 0) {
              iVar4 = 0;
            }
            puVar1 = FUN_4042c044(puVar1,param_2,local_2c[1],*(undefined4 *)(param_1 + 0x6c),iVar4,
                                  iVar5);
          }
          if (puVar1 == (undefined4 *)0x0) {
            iVar2 = -0x7ffcfff8;
          }
          else {
            iVar2 = FUN_4042c0e8(puVar1,local_2c);
            if (-1 < iVar2) {
              *param_4 = (int)puVar1;
              FUN_4040de60(*(int *)(param_1 + 0xb4) + DAT_404304bc,param_1 + 8,puVar1 + 2,puVar1[1])
              ;
              return 0;
            }
            FUN_4042bc58(puVar1);
            FUN_4040a65c(puVar1);
          }
          (**(code **)(*local_2c + 4))();
          return iVar2;
        }
        return iVar2;
      }
    }
  }
  else if (puVar1[3] == 2) {
    (**(code **)*puVar1)(puVar1);
    *param_4 = (int)(puVar1 + -2);
    return 0;
  }
  return -0x7ffcfffe;
}



/* 40429c30 FUN_40429c30 */

/* Boundary evidence: original MIPS .pdata 40429c30..40429dfb. Semantic name remains unreviewed. */

int FUN_40429c30(int *param_1,void *param_2,uint param_3,int param_4,undefined4 *param_5)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int iVar4;
  void *pvVar5;
  undefined1 auStack_30 [16];
  
  pvVar5 = (LPVOID)0x0;
  iVar1 = (**(code **)(*param_1 + 0x50))(param_1,param_2,auStack_30);
  if (-1 < iVar1) {
    return -0x7ffcffb0;
  }
  if (param_4 == 0) {
    param_4 = FUN_4040b7a8();
  }
  puVar2 = FUN_40429958((int)param_1,param_2,param_4,param_1[0x1b]);
  if ((param_3 & 0x2000) == 0) {
    puVar3 = puVar2 + 2;
    if (puVar2 == (undefined4 *)0x0) {
      puVar3 = (undefined4 *)0x0;
    }
    pvVar5 = FUN_4042987c(param_1 + 0x1e,*(undefined4 *)(param_1[0x34] + DAT_404304bc + 0x2c),
                          param_2,(void *)0x0,param_4,2,(int)puVar3);
    if (pvVar5 == (void *)0x0) {
      iVar1 = -0x7ffcfff8;
      goto LAB_40429d64;
    }
  }
  iVar1 = FUN_4042c0e8(puVar2,(int *)0x0);
  if (-1 < iVar1) {
    puVar3 = puVar2 + 2;
    if (puVar2 == (undefined4 *)0x0) {
      puVar3 = (undefined4 *)0x0;
    }
    FUN_4040de60(param_1[0x2d] + DAT_404304bc,(int)(param_1 + 2),puVar3,param_4);
    *param_5 = puVar2;
    return 0;
  }
  if (pvVar5 != (LPVOID)0x0) {
    FUN_40429588(param_1 + 0x1e,(int)pvVar5);
    FUN_404293e8((int)pvVar5);
    FUN_4040a65c(pvVar5);
  }
LAB_40429d64:
  if (param_1[0x34] == 0) {
    iVar4 = 0;
  }
  else {
    iVar4 = param_1[0x34] + DAT_404304bc;
  }
  FUN_4042bc58(puVar2);
  *puVar2 = *(undefined4 *)(iVar4 + 0x3c);
  *(int *)(iVar4 + 0x3c) = (int)puVar2 - DAT_404304bc;
  return iVar1;
}



/* 40429dfc FUN_40429dfc */

/* Boundary evidence: original MIPS .pdata 40429dfc..4042a18f. Semantic name remains unreviewed. */

int FUN_40429dfc(int *param_1,void *param_2,void *param_3,undefined4 *param_4)

{
  int iVar1;
  int iVar2;
  size_t sVar3;
  ushort *puVar4;
  ushort *_Src;
  LPVOID pv;
  int *piVar5;
  ushort auStack_70 [32];
  undefined2 local_30;
  uint local_2c;
  
  local_2c = DAT_404303e4;
  piVar5 = param_1 + 0x1e;
  iVar2 = *piVar5;
  _Src = (ushort *)0x0;
  iVar1 = DAT_404304bc;
  while( true ) {
    puVar4 = (ushort *)(iVar2 + iVar1);
    if (iVar2 == 0) {
      puVar4 = (ushort *)0x0;
    }
    if (puVar4 == (ushort *)0x0) break;
    if ((((puVar4[0x41] == 0) || (puVar4[0x20] != 0)) &&
        (iVar2 = FUN_404296f8((int)piVar5,puVar4,(undefined4 *)0x0), iVar1 = DAT_404304bc,
        iVar2 == 0)) &&
       ((iVar2 = FUN_4042aec0((int)puVar4,(int)param_2), iVar1 = DAT_404304bc, 0 < iVar2 &&
        ((_Src == (ushort *)0x0 ||
         (iVar2 = FUN_4042aec0((int)puVar4,(int)_Src), iVar1 = DAT_404304bc, iVar2 < 0)))))) {
      _Src = puVar4;
      iVar1 = DAT_404304bc;
    }
    iVar2 = *(int *)(puVar4 + 0x48);
  }
  if (param_1[0x1d] != 0) {
    sVar3 = (size_t)*(ushort *)((int)param_2 + 0x40);
    if (0x40 < sVar3) {
      sVar3 = 0x40;
    }
    local_30 = (undefined2)sVar3;
    memcpy(auStack_70,param_2,sVar3);
    iVar2 = (**(code **)(*(int *)(param_1[0x1d] + iVar1) + 0x40))
                      ((int *)(param_1[0x1d] + iVar1),auStack_70,param_3,param_4);
    iVar1 = DAT_404304bc;
    while (DAT_404304bc = iVar1, -1 < iVar2) {
      if (param_3 == (void *)0x0) {
        FUN_40419878(auStack_70,(wchar_t *)*param_4);
      }
      else {
        sVar3 = (size_t)*(ushort *)((int)param_3 + 0x40);
        if (0x40 < sVar3) {
          sVar3 = 0x40;
        }
        local_30 = (undefined2)sVar3;
        memcpy(auStack_70,param_3,sVar3);
      }
      iVar1 = FUN_404296f8((int)piVar5,auStack_70,(undefined4 *)0x0);
      if (iVar1 != 1) {
        if ((_Src == (ushort *)0x0) || (iVar1 = FUN_4042aec0((int)auStack_70,(int)_Src), iVar1 < 0))
        {
          if ((param_4 != (undefined4 *)0x0) &&
             (iVar1 = FUN_404182f8((int *)(param_1[0x2d] + DAT_404304bc + 0x54),auStack_70,
                                   param_1[8]), iVar1 != 0)) {
            pv = (LPVOID)*param_4;
            iVar2 = FUN_4042ef3c(iVar1,param_4,1);
            if (iVar2 < 0) {
              CoTaskMemFree(pv);
            }
            else {
              *param_4 = pv;
            }
          }
          goto LAB_4042a154;
        }
        iVar1 = DAT_404304bc;
        if (param_4 != (undefined4 *)0x0) {
          CoTaskMemFree((LPVOID)*param_4);
          iVar1 = DAT_404304bc;
        }
        goto LAB_4042a038;
      }
      if (param_4 != (undefined4 *)0x0) {
        CoTaskMemFree((LPVOID)*param_4);
      }
      iVar2 = (**(code **)(*(int *)(param_1[0x1d] + DAT_404304bc) + 0x40))
                        ((int *)(param_1[0x1d] + DAT_404304bc),auStack_70,param_3,param_4);
      iVar1 = DAT_404304bc;
    }
    if (iVar2 != -0x7ffcffee) goto LAB_4042a154;
  }
LAB_4042a038:
  iVar2 = -0x7ffcffee;
  if (_Src != (ushort *)0x0) {
    if (param_4 == (undefined4 *)0x0) {
      if (_Src[0x20] < 0x41) {
        *(ushort *)((int)param_3 + 0x40) = _Src[0x20];
      }
      else {
        *(undefined2 *)((int)param_3 + 0x40) = 0x40;
      }
      memcpy(param_3,_Src,(uint)*(ushort *)((int)param_3 + 0x40));
      *(uint *)((int)param_3 + 0x44) = *(uint *)(_Src + 0x44) & 3;
    }
    else {
      if (_Src[0x41] == 0) {
        iVar1 = *(int *)(_Src + 0x46) + iVar1;
        if (*(int *)(_Src + 0x46) == 0) {
          iVar1 = 0;
        }
        iVar2 = FUN_4042ef3c(iVar1,param_4,0);
      }
      else {
        iVar2 = (**(code **)(*param_1 + 0x44))(param_1,_Src,param_3,param_4);
      }
      if (iVar2 < 0) goto LAB_4042a154;
    }
    iVar2 = 0;
  }
LAB_4042a154:
  FUN_4042f4c4(local_2c);
  return iVar2;
}



/* 4042a190 FUN_4042a190 */

/* Boundary evidence: original MIPS .pdata 4042a190..4042a35f. Semantic name remains unreviewed. */

int FUN_4042a190(int param_1,ushort *param_2,void *param_3,undefined4 *param_4)

{
  int iVar1;
  int iVar2;
  LPVOID pvVar3;
  int *piVar4;
  ushort *local_20;
  ushort *local_1c;
  
  local_1c = param_2;
  iVar1 = FUN_404296f8(param_1 + 0x78,param_2,&local_20);
  if (iVar1 != 1) {
    if (iVar1 == 0) {
      if (param_3 != (void *)0x0) {
        if (local_20[0x20] < 0x41) {
          *(ushort *)((int)param_3 + 0x40) = local_20[0x20];
        }
        else {
          *(undefined2 *)((int)param_3 + 0x40) = 0x40;
        }
        memcpy(param_3,local_20,(uint)*(ushort *)((int)param_3 + 0x40));
        *(uint *)((int)param_3 + 0x44) = *(uint *)(local_20 + 0x44) & 3;
        return 0;
      }
      local_20 = FUN_404297bc(local_20,&local_1c);
      if (local_20 != (ushort *)0x0) {
        if (*(int *)(local_20 + 0x46) == 0) {
          iVar1 = 0;
        }
        else {
          iVar1 = *(int *)(local_20 + 0x46) + DAT_404304bc;
        }
        iVar1 = FUN_4042ef3c(iVar1,param_4,0);
        return iVar1;
      }
    }
    if (*(int *)(param_1 + 0x74) != 0) {
      piVar4 = (int *)(*(int *)(param_1 + 0x74) + DAT_404304bc);
      iVar1 = (**(code **)(*piVar4 + 0x44))(piVar4,local_1c,param_3,param_4);
      if (iVar1 < 0) {
        return iVar1;
      }
      iVar2 = FUN_404197c0(param_2,local_1c);
      if (iVar2 != 0) {
        return iVar1;
      }
      if (param_3 != (void *)0x0) {
        if (param_2[0x20] < 0x41) {
          *(ushort *)((int)param_3 + 0x40) = param_2[0x20];
        }
        else {
          *(undefined2 *)((int)param_3 + 0x40) = 0x40;
        }
        memcpy(param_3,param_2,(uint)*(ushort *)((int)param_3 + 0x40));
        return iVar1;
      }
      CoTaskMemFree((LPVOID)*param_4);
      pvVar3 = FUN_40419804(param_2);
      *param_4 = pvVar3;
      if (pvVar3 != (LPVOID)0x0) {
        return iVar1;
      }
      return -0x7ffcfff8;
    }
  }
  return -0x7ffcfffe;
}



/* 4042a360 FUN_4042a360 */

/* Boundary evidence: original MIPS .pdata 4042a360..4042a3b3. Semantic name remains unreviewed. */

int FUN_4042a360(int param_1,undefined4 param_2)

{
  int iVar1;
  int *piVar2;
  
  *(undefined4 *)(param_1 + 0x8c) = 1;
  piVar2 = (int *)(*(int *)(param_1 + 0x6c) + DAT_404304bc);
  iVar1 = (**(code **)(*piVar2 + 0x48))(piVar2,param_1 + 0x70,param_2,param_1 + -8);
  if (-1 < iVar1) {
    iVar1 = 0;
  }
  return iVar1;
}



/* 4042a3b4 FUN_4042a3b4 */

/* Boundary evidence: original MIPS .pdata 4042a3b4..4042a493. Semantic name remains unreviewed. */

int FUN_4042a3b4(int *param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  if (param_1[0x1d] != 0) {
    (**(code **)(*(int *)(param_1[0x1d] + DAT_404304bc) + 0x14))();
  }
  if (param_2 == (int *)0x0) {
    iVar1 = 0;
  }
  else {
    iVar2 = FUN_4040b72c(param_2,param_1);
    if (iVar2 < 0) {
      return iVar2;
    }
    iVar2 = (**(code **)(*param_2 + 0x24))(param_2,param_1 + 0x2f);
    if (iVar2 < 0) {
      return iVar2;
    }
    iVar2 = (**(code **)(*param_2 + 0x2c))(param_2,param_1[0x33],0xffffffff);
    if (iVar2 < 0) {
      return iVar2;
    }
    iVar1 = (int)param_2 - DAT_404304bc;
  }
  param_1[0x1d] = iVar1;
  return iVar2;
}



/* 4042a494 FUN_4042a494 */

/* Boundary evidence: original MIPS .pdata 4042a494..4042a507. Semantic name remains unreviewed. */

void FUN_4042a494(int param_1,uint param_2)

{
  int *piVar1;
  
  if (*(int *)(param_1 + 0x8c) != 0) {
    *(undefined4 *)(param_1 + 0x8c) = 0;
    piVar1 = (int *)(*(int *)(param_1 + 0x6c) + DAT_404304bc);
    (**(code **)(*piVar1 + 0x4c))(piVar1,param_2,param_1 + -8);
    if ((param_2 & 8) != 0) {
      *(undefined4 *)(param_1 + 0x74) = 0;
      *(undefined4 *)(param_1 + 0x70) = 0;
      *(undefined4 *)(param_1 + 0xb0) = 0;
    }
  }
  return;
}



/* 4042a508 FUN_4042a508 */

/* Boundary evidence: original MIPS .pdata 4042a508..4042a5d3. Semantic name remains unreviewed. */

void FUN_4042a508(int param_1)

{
  int *piVar1;
  ushort *puVar2;
  
  if (*(int *)(param_1 + 0x74) == 0) {
    puVar2 = (ushort *)0x0;
  }
  else {
    puVar2 = (ushort *)(*(int *)(param_1 + 0x74) + DAT_404304bc);
  }
  if (puVar2 != (ushort *)0x0) {
    do {
      FUN_404292ec(param_1 + -8,puVar2);
      if (*(int *)(puVar2 + 0x4a) == 0) {
        puVar2 = (ushort *)0x0;
      }
      else {
        puVar2 = (ushort *)(*(int *)(puVar2 + 0x4a) + DAT_404304bc);
      }
    } while (puVar2 != (ushort *)0x0);
  }
  FUN_40429664((int *)(param_1 + 0x70));
  if (*(int *)(param_1 + 0x6c) == 0) {
    piVar1 = (int *)0x0;
  }
  else {
    piVar1 = (int *)(*(int *)(param_1 + 0x6c) + DAT_404304bc);
  }
  FUN_40429204((int *)(param_1 + -8),piVar1);
  *(undefined4 *)(param_1 + 0xb0) = 0;
  return;
}



/* 4042a5d4 FUN_4042a5d4 */

/* Boundary evidence: original MIPS .pdata 4042a5d4..4042a75f. Semantic name remains unreviewed. */

undefined4 FUN_4042a5d4(int *param_1,int *param_2)

{
  int *piVar1;
  void *pvVar2;
  void *pvVar3;
  
  param_1[0x20] = *param_2;
  param_1[0x21] = param_2[1];
  param_1[0x22] = param_1[0x1e];
  param_1[0x23] = param_1[0x1f];
  pvVar2 = (void *)(*param_2 + DAT_404304bc);
  if (*param_2 == 0) {
    pvVar2 = (void *)0x0;
  }
  do {
    if (pvVar2 == (void *)0x0) {
      return 0;
    }
    if (*(short *)((int)pvVar2 + 0x40) == 0) {
LAB_4042a680:
      piVar1 = (int *)FUN_404182f8((int *)(param_1[0x2d] + DAT_404304bc + 0x54),
                                   (ushort *)((int)pvVar2 + 0x42),param_1[8]);
      if (piVar1 != (int *)0x0) {
        (**(code **)*piVar1)(piVar1);
        FUN_40418538((int *)(param_1[0x2d] + DAT_404304bc + 0x54),(int)piVar1);
        (**(code **)(*piVar1 + 4))(piVar1);
        FUN_404183a0(param_1 + 0x24,(int)piVar1);
      }
    }
    else if (*(short *)((int)pvVar2 + 0x82) == 0) {
      if (*(short *)((int)pvVar2 + 0x40) == 0) goto LAB_4042a680;
      if (*(short *)((int)pvVar2 + 0x82) == 0) {
        FUN_4041b7cc((int)pvVar2,param_1,0x2082);
      }
    }
    else {
      FUN_404187a8((int *)(param_1[0x2d] + DAT_404304bc + 0x54),(ushort *)((int)pvVar2 + 0x42),
                   param_1[8],pvVar2);
    }
    pvVar3 = (void *)(*(int *)((int)pvVar2 + 0x90) + DAT_404304bc);
    if (*(int *)((int)pvVar2 + 0x90) == 0) {
      pvVar3 = (void *)0x0;
    }
    FUN_404294fc(param_1 + 0x1e,(int)pvVar2);
    pvVar2 = pvVar3;
  } while( true );
}



/* 4042a7a0 FUN_4042a7a0 */

/* Boundary evidence: original MIPS .pdata 4042a7a0..4042a857. Semantic name remains unreviewed. */

void FUN_4042a7a0(int param_1,undefined4 *param_2)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = param_2 + 2;
  if (param_2 == (undefined4 *)0x0) {
    piVar1 = (int *)0x0;
  }
  FUN_40418538((int *)(*(int *)(param_1 + 0xb4) + DAT_404304bc + 0x54),(int)piVar1);
  (**(code **)(*piVar1 + 4))(piVar1);
  param_2[0x26] = param_2[0x26] + -1;
  if (*(int *)(param_1 + 0xd0) == 0) {
    iVar2 = 0;
  }
  else {
    iVar2 = *(int *)(param_1 + 0xd0) + DAT_404304bc;
  }
  FUN_404189d4(param_2);
  *param_2 = *(undefined4 *)(iVar2 + 0x38);
  *(int *)(iVar2 + 0x38) = (int)param_2 - DAT_404304bc;
  return;
}



/* 4042a858 FUN_4042a858 */

/* Boundary evidence: original MIPS .pdata 4042a858..4042a90f. Semantic name remains unreviewed. */

void FUN_4042a858(int param_1,undefined4 *param_2)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = param_2 + 2;
  if (param_2 == (undefined4 *)0x0) {
    piVar1 = (int *)0x0;
  }
  FUN_40418538((int *)(*(int *)(param_1 + 0xb4) + DAT_404304bc + 0x54),(int)piVar1);
  (**(code **)(*piVar1 + 4))(piVar1);
  param_2[0x27] = param_2[0x27] + -1;
  if (*(int *)(param_1 + 0xd0) == 0) {
    iVar2 = 0;
  }
  else {
    iVar2 = *(int *)(param_1 + 0xd0) + DAT_404304bc;
  }
  FUN_4042bc58(param_2);
  *param_2 = *(undefined4 *)(iVar2 + 0x3c);
  *(int *)(iVar2 + 0x3c) = (int)param_2 - DAT_404304bc;
  return;
}



/* 4042a910 FUN_4042a910 */

/* Boundary evidence: original MIPS .pdata 4042a910..4042ae3f. Semantic name remains unreviewed. */

void FUN_4042a910(int *param_1,uint param_2,int *param_3)

{
  ushort *puVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  undefined4 *puVar6;
  ushort *puVar7;
  int iVar8;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40 [2];
  undefined1 auStack_38 [16];
  uint local_28;
  
  local_28 = DAT_404303e4;
  if ((param_2 & 8) == 0) {
    iVar4 = param_1[0x23];
    param_1[0x1e] = param_1[0x22];
    param_1[0x1f] = iVar4;
    iVar2 = iVar4 + DAT_404304bc;
    if (iVar4 == 0) {
      iVar2 = 0;
    }
    if (iVar2 != 0) {
      iVar2 = param_1[0x1f] + DAT_404304bc;
      if (param_1[0x1f] == 0) {
        iVar2 = 0;
      }
      *(undefined4 *)(iVar2 + 0x90) = 0;
    }
    iVar2 = param_1[0x20] + DAT_404304bc;
    if (param_1[0x20] == 0) {
      iVar2 = 0;
    }
    if (iVar2 != 0) {
      if (param_1[0x20] == 0) {
        iVar2 = 0;
      }
      else {
        iVar2 = param_1[0x20] + DAT_404304bc;
      }
      *(undefined4 *)(iVar2 + 0x94) = 0;
    }
    puVar7 = (ushort *)(param_1[0x21] + DAT_404304bc);
    iVar2 = DAT_404304bc;
    if (param_1[0x21] == 0) {
      puVar7 = (ushort *)0x0;
    }
    while (puVar7 != (ushort *)0x0) {
      if (puVar7[0x41] == 0) {
        if ((*(uint *)(puVar7 + 0x44) & 3) == 1) {
          iVar4 = *(int *)(puVar7 + 0x46) + iVar2;
          if (*(int *)(puVar7 + 0x46) == 0) {
            iVar4 = 0;
          }
          iVar8 = iVar4 + -8;
          if (iVar4 == 0) {
            iVar8 = 0;
          }
          piVar5 = (int *)(*(int *)(iVar8 + 0x74) + iVar2);
          if (*(int *)(iVar8 + 0x74) == 0) {
            piVar5 = (int *)0x0;
          }
          if (piVar5 != (int *)0x0) {
            (**(code **)(*piVar5 + 0x10))(piVar5);
            if (*(int *)(iVar8 + 0x74) != 0) {
              (**(code **)(*(int *)(*(int *)(iVar8 + 0x74) + DAT_404304bc) + 0x14))();
            }
            *(undefined4 *)(iVar8 + 0x74) = 0;
            FUN_4042a7a0((int)param_1,piVar5);
            iVar2 = DAT_404304bc;
          }
        }
        else {
          if (*(int *)(puVar7 + 0x46) == 0) {
            iVar4 = 0;
          }
          else {
            iVar4 = *(int *)(puVar7 + 0x46) + iVar2;
          }
          iVar8 = iVar4 + -8;
          if (iVar4 == 0) {
            iVar8 = 0;
          }
          puVar6 = (undefined4 *)(*(int *)(iVar8 + 0x70) + iVar2);
          if (*(int *)(iVar8 + 0x70) == 0) {
            puVar6 = (undefined4 *)0x0;
          }
          if (puVar6 != (undefined4 *)0x0) {
            (**(code **)*puVar6)(puVar6);
            FUN_4042be7c(iVar8,0);
            FUN_4042a858((int)param_1,puVar6);
            iVar2 = DAT_404304bc;
          }
        }
      }
      else if (puVar7[0x20] == 0) {
        piVar5 = (int *)FUN_404182f8(param_1 + 0x24,puVar7 + 0x21,param_1[8]);
        iVar2 = DAT_404304bc;
        if (piVar5 != (int *)0x0) {
          FUN_40418538(param_1 + 0x24,(int)piVar5);
          iVar2 = param_1[0x2d] + DAT_404304bc;
          (**(code **)*piVar5)(piVar5);
          FUN_404183a0((int *)(iVar2 + 0x54),(int)piVar5);
          (**(code **)(*piVar5 + 4))(piVar5);
          iVar2 = DAT_404304bc;
        }
      }
      else {
        FUN_404187a8((int *)(param_1[0x2d] + iVar2 + 0x54),puVar7,param_1[8],puVar7 + 0x21);
        iVar2 = DAT_404304bc;
      }
      puVar1 = puVar7 + 0x4a;
      puVar7 = (ushort *)(*(int *)puVar1 + iVar2);
      if (*(int *)puVar1 == 0) {
        puVar7 = (ushort *)0x0;
      }
    }
  }
  else {
    iVar2 = param_1[0x20] + DAT_404304bc;
    iVar4 = DAT_404304bc;
    if (param_1[0x20] == 0) {
      iVar2 = 0;
    }
    while (iVar2 != 0) {
      if (*(short *)(iVar2 + 0x82) == 0) {
        if ((*(uint *)(iVar2 + 0x88) & 3) == 1) {
          iVar8 = *(int *)(iVar2 + 0x8c) + iVar4;
          if (*(int *)(iVar2 + 0x8c) == 0) {
            iVar8 = 0;
          }
          iVar3 = iVar8 + -8;
          if (iVar8 == 0) {
            iVar3 = 0;
          }
          iVar8 = *(int *)(iVar3 + 0x74);
        }
        else {
          if (*(int *)(iVar2 + 0x8c) == 0) {
            iVar8 = 0;
          }
          else {
            iVar8 = *(int *)(iVar2 + 0x8c) + iVar4;
          }
          iVar3 = iVar8 + -8;
          if (iVar8 == 0) {
            iVar3 = 0;
          }
          iVar8 = *(int *)(iVar3 + 0x70);
        }
        if (iVar8 == 0) {
          iVar8 = 0;
        }
        else {
          iVar8 = iVar8 + iVar4;
        }
        iVar4 = iVar8 + 8;
        if (iVar8 == 0) {
          iVar4 = 0;
        }
        FUN_4041acc0(iVar2,iVar4);
        iVar4 = DAT_404304bc;
      }
      piVar5 = (int *)(iVar2 + 0x90);
      iVar2 = *piVar5 + iVar4;
      if (*piVar5 == 0) {
        iVar2 = 0;
      }
    }
    while( true ) {
      iVar2 = param_1[0x24];
      piVar5 = (int *)(iVar2 + iVar4);
      if (iVar2 == 0) {
        piVar5 = (int *)0x0;
      }
      if (piVar5 == (int *)0x0) break;
      FUN_4040dcb0(param_1[0x2d] + iVar4,piVar5[6],2);
      FUN_40418538(param_1 + 0x24,(int)piVar5);
      (**(code **)(*piVar5 + 4))(piVar5);
      iVar4 = DAT_404304bc;
    }
    if ((param_3[0x2e] & 1U) != 0) {
      (**(code **)*param_3)(param_3,0,&local_48);
      (**(code **)(*param_1 + 4))(param_1,0,local_48,local_44);
    }
    if ((param_3[0x2e] & 2U) != 0) {
      (**(code **)*param_3)(param_3,1,&local_48);
      (**(code **)(*param_1 + 4))(param_1,1,local_48,local_44);
    }
    if ((param_3[0x2e] & 4U) != 0) {
      (**(code **)*param_3)(param_3,2,&local_48);
      (**(code **)(*param_1 + 4))(param_1,2,local_48,local_44);
    }
    if ((param_3[0x2e] & 8U) != 0) {
      (**(code **)(*param_3 + 0x20))(param_3,auStack_38);
      (**(code **)(*param_1 + 0x24))(param_1,auStack_38);
    }
    if ((param_3[0x2e] & 0x10U) != 0) {
      (**(code **)(*param_3 + 0x28))(param_3,local_40);
      (**(code **)(*param_1 + 0x2c))(param_1,local_40[0],0xffffffff);
    }
  }
  param_1[0x23] = 0;
  param_1[0x22] = 0;
  param_1[0x21] = 0;
  param_1[0x20] = 0;
  FUN_4042f4c4(local_28);
  return;
}



/* 4042ae40 FUN_4042ae40 */

void FUN_4042ae40(int param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 0x44) = param_2;
  return;
}



/* 4042ae4c FUN_4042ae4c */

void FUN_4042ae4c(int param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 0x48) = param_2;
  return;
}



/* 4042ae58 FUN_4042ae58 */

void FUN_4042ae58(int param_1,byte param_2,byte param_3)

{
  *(byte *)(param_1 + 0x43) = ~param_3 & *(byte *)(param_1 + 0x43) | param_2 & param_3;
  return;
}



/* 4042ae78 FUN_4042ae78 */

/* Boundary evidence: original MIPS .pdata 4042ae78..4042ae97. Semantic name remains unreviewed. */

void FUN_4042ae78(int param_1,byte param_2)

{
  FUN_4042ae58(param_1,param_2,1);
  return;
}



/* 4042ae98 FUN_4042ae98 */

undefined1 FUN_4042ae98(int param_1)

{
  return *(undefined1 *)(param_1 + 0x43);
}



/* 4042aea0 FUN_4042aea0 */

/* Boundary evidence: original MIPS .pdata 4042aea0..4042aebf. Semantic name remains unreviewed. */

byte FUN_4042aea0(int param_1)

{
  byte bVar1;
  
  bVar1 = FUN_4042ae98(param_1);
  return bVar1 & 1;
}



/* 4042aec0 FUN_4042aec0 */

/* Boundary evidence: original MIPS .pdata 4042aec0..4042af4b. Semantic name remains unreviewed. */

void FUN_4042aec0(int param_1,int param_2)

{
  undefined2 uVar1;
  undefined2 uVar2;
  undefined2 extraout_var;
  undefined2 extraout_var_00;
  undefined2 extraout_var_01;
  ushort *puVar3;
  ushort *puVar4;
  
  uVar1 = FUN_4040d1ec(param_1);
  uVar2 = FUN_4040d1ec(param_2);
  if (CONCAT22(extraout_var,uVar1) == CONCAT22(extraout_var_00,uVar2)) {
    uVar1 = FUN_4040d1ec(param_1);
    puVar3 = (ushort *)FUN_4040d1f4(param_2);
    puVar4 = (ushort *)FUN_4040d1f4(param_1);
    FUN_4040cf10(puVar4,puVar3,CONCAT22(extraout_var_01,uVar1) >> 1);
  }
  return;
}



/* 4042af4c FUN_4042af4c */

/* Boundary evidence: original MIPS .pdata 4042af4c..4042afbb. Semantic name remains unreviewed. */

int FUN_4042af4c(int *param_1,uint param_2)

{
  int iVar1;
  int local_18 [2];
  
  iVar1 = FUN_4041ef6c((int)param_1,param_2,1,local_18);
  if (-1 < iVar1) {
    FUN_4042ae78(local_18[0],1);
    FUN_4041eb24(param_1,param_2);
  }
  return iVar1;
}



/* 4042afbc FUN_4042afbc */

/* Boundary evidence: original MIPS .pdata 4042afbc..4042b1f3. Semantic name remains unreviewed. */

int FUN_4042afbc(int *param_1,int param_2,uint param_3,uint param_4,uint *param_5)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  undefined4 uVar4;
  int iVar5;
  int local_30;
  int local_2c;
  int local_28 [2];
  
  iVar1 = FUN_4041ef6c((int)param_1,param_4,1,&local_30);
  if (iVar1 < 0) {
    return iVar1;
  }
  if (param_4 == param_3) {
    uVar2 = FUN_4041aa6c(local_30);
  }
  else {
    iVar1 = FUN_4040d1f4(local_30);
    iVar1 = FUN_4042aec0(param_2,iVar1);
    if (iVar1 < 0) {
      uVar2 = FUN_4041e40c(local_30);
    }
    else {
      uVar2 = FUN_4041e41c(local_30);
    }
  }
  iVar1 = FUN_4041ef6c((int)param_1,uVar2,1,local_28);
  if (iVar1 < 0) goto LAB_4042b1bc;
  iVar1 = FUN_4040d1f4(local_28[0]);
  iVar1 = FUN_4042aec0(param_2,iVar1);
  if (iVar1 < 0) {
    uVar3 = FUN_4041e40c(local_28[0]);
    iVar1 = FUN_4041ef6c((int)param_1,uVar3,1,&local_2c);
    if (-1 < iVar1) {
      uVar4 = FUN_4041e41c(local_2c);
      FUN_4042ae40(local_28[0],uVar4);
      FUN_4042ae4c(local_2c,uVar2);
LAB_4042b13c:
      if (param_4 == param_3) {
        FUN_4042ae78(local_2c,1);
        FUN_4041e320(local_30,uVar3);
      }
      else {
        iVar5 = FUN_4040d1f4(local_30);
        iVar5 = FUN_4042aec0(param_2,iVar5);
        if (iVar5 < 0) {
          FUN_4042ae40(local_30,uVar3);
        }
        else {
          FUN_4042ae4c(local_30,uVar3);
        }
      }
      FUN_4041eb24(param_1,uVar3);
      *param_5 = uVar3;
    }
  }
  else {
    uVar3 = FUN_4041e41c(local_28[0]);
    iVar1 = FUN_4041ef6c((int)param_1,uVar3,1,&local_2c);
    if (-1 < iVar1) {
      uVar4 = FUN_4041e40c(local_2c);
      FUN_4042ae4c(local_28[0],uVar4);
      FUN_4042ae40(local_2c,uVar2);
      goto LAB_4042b13c;
    }
  }
  FUN_4041eb24(param_1,uVar2);
LAB_4042b1bc:
  FUN_4041eb24(param_1,param_4);
  return iVar1;
}



/* 4042b1f4 FUN_4042b1f4 */

/* Boundary evidence: original MIPS .pdata 4042b1f4..4042b653. Semantic name remains unreviewed. */

int FUN_4042b1f4(int *param_1,uint param_2,int param_3,int param_4,undefined4 *param_5)

{
  ushort uVar1;
  undefined1 uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  undefined3 extraout_var;
  uint uVar6;
  undefined4 uVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  int local_40;
  int local_3c;
  int local_38;
  int local_34;
  int local_30;
  uint local_2c;
  
  iVar8 = param_1[8];
  uVar1 = *(ushort *)(param_1 + 10);
  local_30 = 0;
  uVar9 = 0;
  local_2c = param_2;
  iVar3 = FUN_4041ef6c((int)param_1,param_2,0,&local_38);
  if (-1 < iVar3) {
    uVar4 = FUN_4041aa6c(local_38);
    while (uVar9 = uVar9 + 1, uVar9 <= (iVar8 + 1) * (uint)uVar1) {
      if (uVar4 == 0xffffffff) {
        iVar3 = -0x7ffcfffe;
        goto LAB_4042b614;
      }
      iVar3 = FUN_4041ef6c((int)param_1,uVar4,0,&local_3c);
      if (iVar3 < 0) goto LAB_4042b614;
      iVar5 = FUN_4040d1f4(local_3c);
      iVar5 = FUN_4042aec0(param_3,iVar5);
      if (iVar5 == 0) {
        param_5[2] = uVar4;
        uVar2 = FUN_4041e42c(local_3c);
        param_5[1] = CONCAT31(extraout_var,uVar2);
        *param_5 = 0;
        if (param_4 != 1) goto LAB_4042b5ec;
        FUN_4041eb24(param_1,uVar4);
        FUN_4041eb24(param_1,param_2);
        iVar3 = FUN_4041ef6c((int)param_1,param_2,1,&local_38);
        if (iVar3 < 0) {
          return iVar3;
        }
        iVar3 = FUN_4041ef6c((int)param_1,uVar4,1,&local_3c);
        iVar8 = local_3c;
        if (iVar3 < 0) goto LAB_4042b614;
        uVar9 = FUN_4041e41c(local_3c);
        if (uVar9 == 0xffffffff) {
          uVar9 = FUN_4041e40c(iVar8);
          if (uVar9 == 0xffffffff) goto LAB_4042b588;
          iVar3 = FUN_4042af4c(param_1,uVar9);
          if (-1 < iVar3) goto LAB_4042b590;
          goto LAB_4042b614;
        }
        iVar3 = FUN_4041ef6c((int)param_1,uVar9,0,&local_40);
        iVar8 = local_40;
        if (iVar3 < 0) goto LAB_4042b5ec;
        iVar3 = FUN_4041e40c(local_40);
        if (iVar3 == -1) {
          FUN_4041eb24(param_1,uVar9);
          iVar3 = FUN_4041ef6c((int)param_1,uVar9,1,&local_40);
          if (-1 < iVar3) goto LAB_4042b55c;
          goto LAB_4042b5ec;
        }
        local_34 = iVar8;
        uVar6 = FUN_4041e40c(iVar8);
        iVar3 = FUN_4041ef6c((int)param_1,uVar6,0,&local_40);
        if (iVar3 < 0) goto LAB_4042b57c;
        uVar6 = FUN_4041e40c(local_34);
        uVar10 = uVar9;
        goto LAB_4042b48c;
      }
      FUN_4041eb24(param_1,param_2);
      local_38 = local_3c;
      param_2 = uVar4;
      local_30 = iVar5;
      if (iVar5 < 0) {
        uVar4 = FUN_4041e40c(local_3c);
      }
      else {
        uVar4 = FUN_4041e41c(local_3c);
      }
    }
    iVar3 = -0x7ffcfef7;
LAB_4042b614:
    FUN_4041eb24(param_1,param_2);
  }
  return iVar3;
LAB_4042b48c:
  uVar9 = uVar6;
  uVar6 = FUN_4041e40c(local_40);
  FUN_4041eb24(param_1,uVar10);
  if (uVar6 != 0xffffffff) goto LAB_4042b460;
  iVar3 = FUN_4041ef6c((int)param_1,uVar10,1,&local_34);
  if (-1 < iVar3) {
    uVar7 = FUN_4041e41c(local_40);
    FUN_4042ae40(local_34,uVar7);
    FUN_4041eb24(param_1,uVar10);
    FUN_4041eb24(param_1,uVar9);
    iVar3 = FUN_4041ef6c((int)param_1,uVar9,1,&local_40);
    if (iVar3 < 0) goto LAB_4042b5ec;
    uVar7 = FUN_4041e41c(local_3c);
    FUN_4042ae4c(local_40,uVar7);
LAB_4042b55c:
    FUN_4042ae78(local_40,1);
    uVar7 = FUN_4041e40c(local_3c);
    FUN_4042ae40(local_40,uVar7);
  }
  goto LAB_4042b57c;
LAB_4042b460:
  local_34 = local_40;
  iVar3 = FUN_4041ef6c((int)param_1,uVar6,0,&local_40);
  uVar10 = uVar9;
  if (iVar3 < 0) {
LAB_4042b57c:
    FUN_4041eb24(param_1,uVar9);
LAB_4042b588:
    if (-1 < iVar3) {
LAB_4042b590:
      if (param_2 == local_2c) {
        FUN_4041e320(local_38,uVar9);
      }
      else if (local_30 < 0) {
        FUN_4042ae40(local_38,uVar9);
      }
      else {
        FUN_4042ae4c(local_38,uVar9);
      }
      FUN_4042ae40(local_3c,0xffffffff);
      FUN_4042ae4c(local_3c,0xffffffff);
    }
LAB_4042b5ec:
    FUN_4041eb24(param_1,uVar4);
    goto LAB_4042b614;
  }
  goto LAB_4042b48c;
}



/* 4042b654 FUN_4042b654 */

/* Boundary evidence: original MIPS .pdata 4042b654..4042b8e3. Semantic name remains unreviewed. */

int FUN_4042b654(int *param_1,int param_2,uint param_3,uint param_4,uint param_5,uint param_6,
                uint param_7,uint *param_8)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  undefined3 extraout_var;
  bool bVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  int local_38;
  int local_34;
  int local_30;
  uint local_2c;
  
  uVar6 = param_7;
  local_38 = param_2;
  local_2c = param_4;
  iVar2 = FUN_4041ef6c((int)param_1,param_7,1,&local_34);
  if (iVar2 < 0) {
    return iVar2;
  }
  uVar3 = FUN_4041e40c(local_34);
  uVar4 = FUN_4041e41c(local_34);
  FUN_4042ae78(local_34,param_6 == param_3);
  FUN_4041eb24(param_1,uVar6);
  if ((uVar3 != 0xffffffff) && (iVar2 = FUN_4042af4c(param_1,uVar3), iVar2 < 0)) {
    return iVar2;
  }
  if ((uVar4 != 0xffffffff) && (iVar2 = FUN_4042af4c(param_1,uVar4), iVar2 < 0)) {
    return iVar2;
  }
  if (param_6 == param_3) goto LAB_4042b8a8;
  iVar8 = 0;
  iVar2 = FUN_4041ef6c((int)param_1,param_6,0,&local_30);
  if (iVar2 < 0) {
    return iVar2;
  }
  bVar1 = FUN_4042aea0(local_30);
  bVar5 = CONCAT31(extraout_var,bVar1) == 0;
  iVar7 = local_38;
  if (bVar5) {
    iVar8 = FUN_4040d1f4(local_30);
    iVar7 = local_38;
    iVar8 = FUN_4042aec0(local_38,iVar8);
  }
  FUN_4041eb24(param_1,param_6);
  if (!bVar5) goto LAB_4042b8a8;
  if (param_5 == param_3) {
LAB_4042b824:
    bVar5 = false;
  }
  else {
    iVar2 = FUN_4041ef6c((int)param_1,param_5,1,&local_38);
    if (iVar2 < 0) {
      return iVar2;
    }
    iVar2 = FUN_4040d1f4(local_38);
    iVar2 = FUN_4042aec0(iVar7,iVar2);
    FUN_4042ae78(local_38,0);
    FUN_4041eb24(param_1,param_5);
    bVar5 = true;
    if (-1 < iVar2) goto LAB_4042b824;
  }
  if ((bVar5 != iVar8 < 0) &&
     (iVar2 = FUN_4042afbc(param_1,iVar7,param_3,param_5,&param_7), iVar2 < 0)) {
    return iVar2;
  }
  iVar2 = FUN_4042afbc(param_1,iVar7,param_3,local_2c,&param_7);
  uVar6 = param_7;
  if (iVar2 < 0) {
    return iVar2;
  }
  iVar2 = FUN_4042af4c(param_1,param_7);
  if (iVar2 < 0) {
    return iVar2;
  }
LAB_4042b8a8:
  *param_8 = uVar6;
  return iVar2;
}



/* 4042b8e4 FUN_4042b8e4 */

/* Boundary evidence: original MIPS .pdata 4042b8e4..4042bc4f. Semantic name remains unreviewed. */

int FUN_4042b8e4(int *param_1,uint param_2,uint param_3,int param_4)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  uint uVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  uint uVar10;
  uint uVar11;
  int local_50;
  uint local_4c;
  int local_48;
  uint local_44;
  uint local_40;
  uint local_3c;
  int local_38;
  int local_34;
  uint local_30 [2];
  
  local_3c = (param_1[8] + 1) * (uint)*(ushort *)(param_1 + 10);
  uVar11 = 0;
  iVar9 = 0;
  local_4c = param_2;
  local_48 = param_4;
  local_40 = param_2;
  iVar2 = FUN_4041ef6c((int)param_1,param_2,0,&local_50);
  if (-1 < iVar2) {
    uVar3 = FUN_4041aa6c(local_50);
    uVar6 = param_2;
    uVar10 = param_2;
    while (uVar8 = uVar6, local_44 = uVar3, uVar3 != 0xffffffff) {
      FUN_4041eb24(param_1,uVar8);
      uVar11 = uVar11 + 1;
      if (local_3c < uVar11) {
        return -0x7ffcfef7;
      }
      iVar9 = FUN_4041ef6c((int)param_1,uVar3,0,&local_38);
      iVar2 = local_38;
      if (iVar9 < 0) {
        return iVar9;
      }
      uVar4 = FUN_4041e40c(local_38);
      uVar5 = FUN_4041e41c(iVar2);
      FUN_4041eb24(param_1,uVar3);
      uVar6 = uVar3;
      uVar10 = local_4c;
      if ((uVar4 != 0xffffffff) && (uVar5 != 0xffffffff)) {
        iVar2 = FUN_4041ef6c((int)param_1,uVar4,0,&local_34);
        if (iVar2 < 0) {
          return iVar2;
        }
        bVar1 = FUN_4042aea0(local_34);
        FUN_4041eb24(param_1,uVar4);
        uVar10 = local_4c;
        if (CONCAT31(extraout_var,bVar1) == 0) {
          iVar2 = FUN_4041ef6c((int)param_1,uVar5,0,(int *)local_30);
          if (iVar2 < 0) {
            return iVar2;
          }
          bVar1 = FUN_4042aea0(local_30[0]);
          FUN_4041eb24(param_1,uVar5);
          uVar10 = local_4c;
          if ((CONCAT31(extraout_var_00,bVar1) == 0) &&
             (iVar2 = FUN_4042b654(param_1,local_48,param_2,local_40,local_4c,uVar8,uVar3,&local_44)
             , uVar6 = local_44, iVar2 < 0)) {
            return iVar2;
          }
        }
      }
      local_4c = uVar8;
      local_40 = uVar10;
      iVar2 = FUN_4041ef6c((int)param_1,uVar6,0,&local_50);
      if (iVar2 < 0) {
        return iVar2;
      }
      iVar2 = FUN_4040d1f4(local_50);
      iVar7 = local_48;
      iVar9 = FUN_4042aec0(local_48,iVar2);
      uVar10 = uVar8;
      if (iVar9 == 0) {
        iVar2 = -0x7ffcffb0;
        goto LAB_4042bbdc;
      }
      if (iVar9 < 0) {
        uVar3 = FUN_4041e40c(local_50);
      }
      else {
        uVar3 = FUN_4041e41c(local_50);
      }
    }
    FUN_4041eb24(param_1,uVar8);
    iVar2 = FUN_4041ef6c((int)param_1,uVar8,1,&local_50);
    if (-1 < iVar2) {
      uVar6 = uVar8;
      if (uVar8 == param_2) {
        FUN_4041e320(local_50,param_3);
        iVar7 = local_48;
      }
      else if (iVar9 < 0) {
        FUN_4042ae40(local_50,param_3);
        iVar7 = local_48;
      }
      else {
        FUN_4042ae4c(local_50,param_3);
        iVar7 = local_48;
      }
LAB_4042bbdc:
      FUN_4041eb24(param_1,uVar6);
      if (-1 < iVar2) {
        iVar2 = FUN_4042b654(param_1,iVar7,param_2,local_40,uVar10,uVar6,param_3,local_30);
      }
    }
  }
  return iVar2;
}



/* 4042bc50 FUN_4042bc50 */

void FUN_4042bc50(int param_1)

{
  *(undefined4 *)(param_1 + 0x94) = 0;
  return;
}



/* 4042bc58 FUN_4042bc58 */

/* Boundary evidence: original MIPS .pdata 4042bc58..4042bcd3. Semantic name remains unreviewed. */

void FUN_4042bc58(undefined4 *param_1)

{
  *param_1 = &PTR_LAB_40402180;
  param_1[2] = &PTR_LAB_40402168;
  FUN_4042ee14(param_1 + 0x1e);
  if (param_1[0x1c] != 0) {
    (**(code **)(*(int *)(param_1[0x1c] + DAT_404304bc) + 4))();
  }
  FUN_4042ef20(param_1 + 0x1e);
  return;
}



/* 4042bcd4 FUN_4042bcd4 */

/* Boundary evidence: original MIPS .pdata 4042bcd4..4042bd47. Semantic name remains unreviewed. */

undefined4 FUN_4042bcd4(int param_1,undefined4 param_2,int param_3)

{
  undefined4 uVar1;
  int iVar2;
  
  FUN_4042021c(param_1 + 0x78,param_1);
  if (param_3 == 0) {
    iVar2 = 0;
  }
  else {
    iVar2 = param_3 - DAT_404304bc;
  }
  uVar1 = *(undefined4 *)(param_1 + 0x6c);
  *(undefined4 *)(param_1 + 0x6c) = param_2;
  *(int *)(param_1 + 0xa0) = iVar2;
  *(undefined4 *)(param_1 + 0xa4) = uVar1;
  return 0;
}



/* 4042bd48 FUN_4042bd48 */

/* Boundary evidence: original MIPS .pdata 4042bd48..4042bdb7. Semantic name remains unreviewed. */

void FUN_4042bd48(int param_1,uint param_2)

{
  int *piVar1;
  
  if (*(int *)(param_1 + 0xa0) == 0) {
    piVar1 = (int *)0x0;
  }
  else {
    piVar1 = (int *)(*(int *)(param_1 + 0xa0) + DAT_404304bc);
  }
  FUN_4042e500((int *)(param_1 + 0x78),piVar1,param_2);
  *(undefined4 *)(param_1 + 0xa0) = 0;
  if ((param_2 & 8) == 0) {
    *(undefined4 *)(param_1 + 0x6c) = *(undefined4 *)(param_1 + 0xa4);
  }
  else {
    *(undefined4 *)(param_1 + 0xa4) = 0;
  }
  return;
}



/* 4042bdb8 FUN_4042bdb8 */

/* Boundary evidence: original MIPS .pdata 4042bdb8..4042bdff. Semantic name remains unreviewed. */

void FUN_4042bdb8(int param_1)

{
  int *piVar1;
  
  *(undefined4 *)(param_1 + 0x90) = 1;
  piVar1 = (int *)(*(int *)(param_1 + 0x68) + DAT_404304bc);
  (**(code **)(*piVar1 + 8))(piVar1,*(undefined4 *)(param_1 + 100),param_1 + 0x70,param_1 + -8);
  return;
}



/* 4042be00 FUN_4042be00 */

/* Boundary evidence: original MIPS .pdata 4042be00..4042be7b. Semantic name remains unreviewed. */

void FUN_4042be00(int param_1,uint param_2)

{
  int *piVar1;
  
  if (*(int *)(param_1 + 0x90) != 0) {
    *(undefined4 *)(param_1 + 0x90) = 0;
    if (*(int *)(param_1 + 0x68) != 0) {
      piVar1 = (int *)(*(int *)(param_1 + 0x68) + DAT_404304bc);
      (**(code **)(*piVar1 + 0xc))(piVar1,param_2,param_1 + -8);
    }
    if ((param_2 & 8) != 0) {
      FUN_4042ee14((int *)(param_1 + 0x70));
      FUN_4042bc50(param_1 + -8);
    }
  }
  return;
}



/* 4042be7c FUN_4042be7c */

/* Boundary evidence: original MIPS .pdata 4042be7c..4042bef3. Semantic name remains unreviewed. */

undefined4 FUN_4042be7c(int param_1,int param_2)

{
  int iVar1;
  
  if (*(int *)(param_1 + 0x70) != 0) {
    (**(code **)(*(int *)(*(int *)(param_1 + 0x70) + DAT_404304bc) + 4))();
  }
  if (param_2 == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = param_2 - DAT_404304bc;
  }
  *(int *)(param_1 + 0x70) = iVar1;
  return 0;
}



/* 4042bf04 FUN_4042bf04 */

/* Boundary evidence: original MIPS .pdata 4042bf04..4042bf6b. Semantic name remains unreviewed. */

void FUN_4042bf04(int param_1,undefined4 *param_2,undefined4 *param_3)

{
  if (*(int *)(param_1 + 0x68) == 0) {
    *param_2 = 0;
  }
  else {
    (**(code **)(*(int *)(DAT_404304bc + *(int *)(param_1 + 0x68)) + 0x20))();
  }
  *param_3 = *(undefined4 *)(param_1 + 100);
  return;
}



/* 4042bf78 FUN_4042bf78 */

/* Boundary evidence: original MIPS .pdata 4042bf78..4042bfb7. Semantic name remains unreviewed. */

undefined4 FUN_4042bf78(int param_1,int *param_2)

{
  if (param_2 == (int *)0x0) {
    *(undefined4 *)(param_1 + 0x6c) = 0;
  }
  else {
    (**(code **)(*param_2 + 0x20))(param_2,param_1 + 0x6c);
  }
  return 0;
}



/* 4042bfb8 FUN_4042bfb8 */

/* Boundary evidence: original MIPS .pdata 4042bfb8..4042c02f. Semantic name remains unreviewed. */

int * FUN_4042bfb8(int param_1)

{
  int iVar1;
  int *piVar2;
  
  piVar2 = (int *)(param_1 + 0x78);
  iVar1 = FUN_40427db8(piVar2);
  if (iVar1 != 0) {
    if (*(int *)(param_1 + 0x70) == 0) {
      piVar2 = (int *)0x0;
    }
    else {
      piVar2 = (int *)(**(code **)(*(int *)(*(int *)(param_1 + 0x70) + DAT_404304bc) + 0x10))();
    }
  }
  return piVar2;
}



/* 4042c044 FUN_4042c044 */

/* Boundary evidence: original MIPS .pdata 4042c044..4042c0e7. Semantic name remains unreviewed. */

undefined4 *
FUN_4042c044(undefined4 *param_1,void *param_2,undefined4 param_3,undefined4 param_4,int param_5,
            int param_6)

{
  FUN_40427c9c(param_1,param_3);
  FUN_4041873c(param_1 + 2,param_2,2);
  *param_1 = &PTR_LAB_40402180;
  param_1[2] = &PTR_LAB_40402168;
  FUN_4042d7f4(param_1 + 0x1e,param_5,param_6);
  param_1[0x24] = param_4;
  param_1[0x1c] = 0;
  param_1[0x28] = 0;
  param_1[0x27] = 0;
  param_1[0x25] = 0;
  param_1[0x26] = 0;
  return param_1;
}



/* 4042c0e8 FUN_4042c0e8 */

/* Boundary evidence: original MIPS .pdata 4042c0e8..4042c16b. Semantic name remains unreviewed. */

int FUN_4042c0e8(undefined4 *param_1,int *param_2)

{
  int iVar1;
  code *pcVar2;
  int iVar3;
  
  iVar1 = FUN_4042bf78((int)param_1,param_2);
  if (-1 < iVar1) {
    if (param_2 == (int *)0x0) {
      iVar3 = 0;
    }
    else {
      iVar3 = (int)param_2 - DAT_404304bc;
    }
    pcVar2 = *(code **)*param_1;
    param_1[0x1c] = iVar3;
    param_1[0x1d] = 0;
    (*pcVar2)(param_1);
  }
  return iVar1;
}



/* 4042c16c FUN_4042c16c */

/* Boundary evidence: original MIPS .pdata 4042c16c..4042c5a7. Semantic name remains unreviewed. */

int FUN_4042c16c(int param_1,uint param_2,int param_3,int param_4,int *param_5)

{
  bool bVar1;
  ushort uVar2;
  int iVar3;
  int *piVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  int *piVar10;
  uint uVar11;
  uint uVar12;
  int local_44;
  int local_40;
  uint local_3c;
  uint local_38;
  int *local_34;
  uint local_30 [2];
  
  uVar6 = *(uint *)(param_1 + 0x6c);
  if (uVar6 < param_2 + param_4) {
    param_4 = uVar6 - param_2;
  }
  if ((param_4 == 0) || (uVar6 < param_2)) {
    iVar3 = 0;
    *param_5 = 0;
  }
  else {
    piVar10 = (int *)(param_1 + 0x78);
    iVar3 = FUN_40427db8(piVar10);
    if (iVar3 == 0) {
      local_34 = (int *)FUN_40427d04((int)piVar10);
      uVar6 = FUN_40427d38((int)piVar10);
      uVar2 = FUN_40427d6c((int)piVar10);
      uVar5 = (param_2 + param_4) - 1;
      local_38 = uVar5 / uVar6;
      local_44 = 0;
      local_40 = 0;
      if (uVar6 == 0) {
        trap(0x1c00);
      }
      if (uVar6 == 0) {
        trap(0x1c00);
      }
      uVar12 = param_2 / uVar6;
      if (uVar6 == 0) {
        trap(0x1c00);
      }
      if (uVar6 == 0) {
        trap(0x1c00);
      }
      uVar11 = param_2 % uVar6 & 0xffff;
      iVar3 = FUN_4042e104(piVar10,uVar12,2,local_30);
      if (-1 < iVar3) {
        bVar1 = local_30[0] == 0xfffffffe;
        uVar7 = uVar12;
        if (!bVar1) {
          uVar7 = local_30[0];
        }
        uVar12 = uVar12 + 1;
        uVar8 = uVar7;
        uVar9 = uVar7;
        if (uVar12 <= local_38) {
          do {
            iVar3 = FUN_4042e104(piVar10,uVar12,2,&local_3c);
            if (iVar3 < 0) {
              return iVar3;
            }
            if (local_3c == 0xfffffffe) {
              uVar9 = uVar12;
              if (!bVar1) goto LAB_4042c35c;
            }
            else if ((bVar1) || (uVar9 = local_3c, local_3c != uVar8 + 1)) {
LAB_4042c35c:
              if (bVar1) {
                piVar4 = (int *)(*(int *)(param_1 + 0x70) + DAT_404304bc);
                iVar3 = (**(code **)(*piVar4 + 0x14))
                                  (piVar4,uVar6 * uVar7 + uVar11,param_3,
                                   ((uVar8 - uVar7) + 1) * uVar6 - uVar11,&local_44);
              }
              else {
                FUN_404157c4(uVar7,(int)(short)uVar11,(uint)uVar2);
                iVar3 = (**(code **)(*local_34 + 0xc))(local_34);
              }
              if (iVar3 < 0) {
                return iVar3;
              }
              local_40 = local_40 + local_44;
              param_3 = param_3 + local_44;
              uVar11 = 0;
              if (local_3c == 0xfffffffe) {
                bVar1 = true;
                uVar7 = uVar12;
                uVar9 = uVar12;
              }
              else {
                bVar1 = false;
                uVar7 = local_3c;
                uVar9 = local_3c;
              }
            }
            uVar12 = uVar12 + 1;
            uVar8 = uVar9;
          } while (uVar12 <= local_38);
        }
        if (bVar1) {
          piVar10 = (int *)(*(int *)(param_1 + 0x70) + DAT_404304bc);
          iVar3 = (**(code **)(*piVar10 + 0x14))
                            (piVar10,uVar6 * uVar7 + uVar11,param_3,
                             (((uVar9 - uVar7) + 1) * uVar6 -
                             ((uVar6 - (int)(short)(uVar5 % uVar6)) + 0xffff & 0xffff)) - uVar11,
                             &local_44);
        }
        else {
          FUN_404157c4(uVar7,(int)(short)uVar11,(uint)uVar2);
          iVar3 = (**(code **)(*local_34 + 0xc))();
        }
        if (-1 < iVar3) {
          *param_5 = local_40 + local_44;
        }
      }
    }
    else {
      piVar10 = (int *)(*(int *)(param_1 + 0x70) + DAT_404304bc);
      iVar3 = (**(code **)(*piVar10 + 0x14))(piVar10,param_2,param_3,param_4,param_5);
    }
  }
  return iVar3;
}



/* 4042c5a8 FUN_4042c5a8 */

/* Boundary evidence: original MIPS .pdata 4042c5a8..4042c817. Semantic name remains unreviewed. */

int FUN_4042c5a8(int param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  int *piVar3;
  int iVar4;
  int *piVar5;
  uint uVar6;
  undefined2 auStack_38 [2];
  uint local_34;
  undefined *local_30;
  undefined1 auStack_2c [4];
  
  piVar5 = (int *)(param_1 + 0x78);
  local_30 = (undefined *)0x0;
  iVar4 = 0;
  if (param_2 == 0) {
    FUN_4042ee14(piVar5);
  }
  else {
    iVar4 = FUN_40427db8(piVar5);
    if (iVar4 == 0) {
      iVar4 = FUN_4042de88(piVar5,param_2);
    }
    else {
      iVar4 = FUN_4042e92c(piVar5,param_2,param_1);
    }
    if (iVar4 < 0) goto LAB_4042c7dc;
  }
  uVar6 = *(uint *)(param_1 + 0x6c);
  if (uVar6 < param_2) {
    uVar1 = FUN_40427d38((int)piVar5);
    uVar2 = FUN_40427d6c((int)piVar5);
    if (uVar6 == 0) {
      uVar6 = 0;
    }
    else {
      uVar6 = (uVar6 - 1) / uVar1;
      if (uVar1 == 0) {
        trap(0x1c00);
      }
    }
    if (uVar1 == 0) {
      trap(0x1c00);
    }
    iVar4 = FUN_4042e104(piVar5,uVar6,0,&local_34);
    if (-1 < iVar4) {
      if (local_34 != 0xfffffffe) goto LAB_4042c7cc;
      if (*(int *)(param_1 + 0x70) == 0) goto LAB_4042c7cc;
      if (*(int *)(param_1 + 0x6c) == 0) goto LAB_4042c7cc;
      FUN_40415908(uVar1,uVar1,(int *)&local_30,auStack_38);
      piVar3 = (int *)(DAT_404304bc + *(int *)(param_1 + 0x70));
      iVar4 = (**(code **)(*piVar3 + 0x14))
                        (piVar3,uVar6 << (uVar2 & 0x1f),local_30,uVar1,auStack_2c);
      if ((-1 < iVar4) && (iVar4 = FUN_4042e104(piVar5,uVar6,1,&local_34), -1 < iVar4)) {
        FUN_404157c4(local_34,0,uVar2);
        piVar3 = (int *)FUN_40427d04((int)piVar5);
        iVar4 = (**(code **)(*piVar3 + 0x10))(piVar3);
        while (-1 < iVar4) {
          uVar6 = uVar6 + 1;
LAB_4042c7cc:
          if ((param_2 - 1) / uVar1 < uVar6) goto LAB_4042c7d8;
          iVar4 = FUN_4042e104(piVar5,uVar6,1,&local_34);
        }
      }
    }
  }
  else {
LAB_4042c7d8:
    *(uint *)(param_1 + 0x6c) = param_2;
  }
LAB_4042c7dc:
  FUN_4041598c(local_30);
  return iVar4;
}



/* 4042c818 FUN_4042c818 */

/* Boundary evidence: original MIPS .pdata 4042c818..4042c87f. Semantic name remains unreviewed. */

void FUN_4042c818(int param_1)

{
  int *piVar1;
  
  FUN_4042ee14((int *)(param_1 + 0x70));
  if (*(int *)(param_1 + 0x68) == 0) {
    piVar1 = (int *)0x0;
  }
  else {
    piVar1 = (int *)(*(int *)(param_1 + 0x68) + DAT_404304bc);
  }
  FUN_4042bf78(param_1 + -8,piVar1);
  *(undefined4 *)(param_1 + 0x6c) = 0;
  FUN_4042bc50(param_1 + -8);
  return;
}



/* 4042c880 FUN_4042c880 */

/* Boundary evidence: original MIPS .pdata 4042c880..4042c8ab. Semantic name remains unreviewed. */

void FUN_4042c880(undefined4 *param_1)

{
  int iVar1;
  
  iVar1 = param_1[0x27];
  param_1[0x27] = iVar1 + -1;
  if (iVar1 + -1 == 0) {
    FUN_4042990c(param_1,1);
  }
  return;
}



/* 4042c8ac FUN_4042c8ac */

/* Boundary evidence: original MIPS .pdata 4042c8ac..4042ca13. Semantic name remains unreviewed. */

int FUN_4042c8ac(int param_1,int param_2,int param_3,void *param_4,ushort param_5,ushort param_6)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  undefined2 auStack_38 [2];
  undefined *local_34;
  undefined1 auStack_30 [8];
  
  iVar5 = param_1 + 0x78;
  local_34 = (undefined *)0x0;
  uVar1 = FUN_40427d38(iVar5);
  uVar2 = FUN_40427d6c(iVar5);
  if (param_6 != uVar1) {
    FUN_40415908(uVar1,uVar1,(int *)&local_34,auStack_38);
    if (*(int *)(param_1 + 0x70) != 0) {
      piVar4 = (int *)(DAT_404304bc + *(int *)(param_1 + 0x70));
      iVar3 = (**(code **)(*piVar4 + 0x14))
                        (piVar4,param_2 << (uVar2 & 0x1f),local_34,uVar1,auStack_30);
      if (iVar3 < 0) goto LAB_4042c9d8;
    }
    memcpy(local_34 + param_5,param_4,(uint)param_6);
  }
  FUN_404157c4(param_3,0,uVar2);
  piVar4 = (int *)FUN_40427d04(iVar5);
  iVar3 = (**(code **)(*piVar4 + 0x10))(piVar4);
LAB_4042c9d8:
  FUN_4041598c(local_34);
  return iVar3;
}



/* 4042ca28 FUN_4042ca28 */

/* Boundary evidence: original MIPS .pdata 4042ca28..4042cfe7. Semantic name remains unreviewed. */

int FUN_4042ca28(int *param_1,uint param_2,void *param_3,int param_4,int *param_5)

{
  ushort uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  short sVar5;
  int iVar6;
  int *piVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  int iVar11;
  uint uVar12;
  uint uVar13;
  uint local_48;
  uint local_44;
  int *local_40;
  uint local_3c;
  uint local_38;
  uint local_34;
  int local_30;
  uint local_2c;
  
  piVar7 = param_1 + 0x1e;
  uVar2 = FUN_40427d38((int)piVar7);
  uVar1 = FUN_40427d6c((int)piVar7);
  local_44 = 0;
  if (param_4 == 0) {
    *param_5 = 0;
  }
  else {
    uVar8 = param_2 + param_4;
    if (((uint)param_1[0x1b] < uVar8) &&
       (iVar3 = (**(code **)(*param_1 + 0x1c))(param_1,uVar8), iVar3 < 0)) {
      return iVar3;
    }
    iVar3 = FUN_40427db8(piVar7);
    if ((iVar3 != 0) && (iVar3 = FUN_4042e92c(piVar7,param_1[0x1b],(int)param_1), iVar3 < 0)) {
      return iVar3;
    }
    local_40 = (int *)FUN_40427d04((int)piVar7);
    uVar12 = param_2 / uVar2;
    if (uVar2 == 0) {
      trap(0x1c00);
    }
    if (uVar2 == 0) {
      trap(0x1c00);
    }
    uVar13 = (uVar8 - 1) / uVar2;
    iVar3 = (int)(short)(param_2 % uVar2);
    if (uVar2 == 0) {
      trap(0x1c00);
    }
    if (uVar2 == 0) {
      trap(0x1c00);
    }
    iVar6 = ((uVar8 - 1) % uVar2 + 1) * 0x10000;
    sVar5 = (short)((uint)iVar6 >> 0x10);
    iVar11 = 0;
    iVar10 = 0;
    if (uVar12 == uVar13) {
      iVar11 = (int)(((uVar2 & 0xffff) - (iVar6 >> 0x10)) * 0x10000) >> 0x10;
    }
    local_38 = uVar2;
    local_2c = uVar13;
    iVar6 = FUN_4042e104(piVar7,uVar12,0,&local_3c);
    if (iVar6 < 0) {
      return iVar6;
    }
    local_30 = 1;
    while( true ) {
      if ((iVar3 == 0) && (uVar12 != uVar13)) {
        uVar13 = local_3c;
        uVar9 = local_3c;
        uVar8 = local_2c;
        if (local_3c == 0xfffffffe) {
          iVar3 = FUN_4042e104(piVar7,uVar12,1,&local_48);
          if (iVar3 < 0) {
            return iVar3;
          }
          uVar13 = local_3c;
          uVar9 = local_3c;
          uVar8 = local_2c;
          if (local_3c == 0xfffffffe) {
            uVar13 = local_48;
            uVar9 = local_48;
          }
        }
        while( true ) {
          uVar12 = uVar12 + 1;
          local_34 = uVar9;
          if (uVar8 <= uVar12) break;
          iVar3 = FUN_4042e104(piVar7,uVar12,1,&local_48);
          if (iVar3 < 0) {
            return iVar3;
          }
          uVar4 = uVar9 + 1;
          uVar9 = local_48;
          if (local_48 != uVar4) {
            FUN_404157c4(uVar13,0,(uint)uVar1);
            iVar3 = (**(code **)(*local_40 + 0x10))(local_40);
            if (iVar3 < 0) {
              return iVar3;
            }
            param_3 = (void *)((int)param_3 + local_44);
            iVar10 = iVar10 + local_44;
            uVar13 = local_48;
            uVar9 = local_48;
          }
        }
        iVar3 = FUN_4042e104(piVar7,uVar12,0,&local_48);
        if (-1 < iVar3) {
          iVar3 = (int)(((uVar2 & 0xffff) - (int)sVar5) * 0x10000) >> 0x10;
          if (local_48 == 0xfffffffe) {
            local_30 = 0;
            iVar6 = FUN_4042e104(piVar7,uVar12,1,&local_48);
            if (iVar6 < 0) {
              return iVar6;
            }
          }
          if ((local_48 != local_34 + 1) || (uVar2 = local_38, iVar3 != 0)) {
            FUN_404157c4(uVar13,0,(uint)uVar1);
            uVar2 = local_38;
            iVar6 = (**(code **)(*local_40 + 0x10))(local_40);
            if (iVar6 < 0) {
              return iVar6;
            }
            param_3 = (void *)((int)param_3 + local_44);
            iVar10 = iVar10 + local_44;
            uVar13 = local_48;
          }
          if (iVar3 == 0) {
            FUN_404157c4(uVar13,0,(uint)uVar1);
            iVar3 = (**(code **)(*local_40 + 0x10))();
            uVar8 = local_44;
          }
          else {
            uVar8 = uVar2 - iVar3 & 0xffff;
            if (local_30 == 0) {
              iVar3 = FUN_4042c8ac((int)param_1,uVar12,local_48,param_3,0,(ushort)(uVar2 - iVar3));
            }
            else {
              FUN_404157c4(local_48,0,(uint)uVar1);
              iVar3 = (**(code **)(*local_40 + 0x10))(local_40);
            }
          }
          if (-1 < iVar3) {
            *param_5 = iVar10 + uVar8;
          }
        }
        return iVar3;
      }
      uVar8 = (local_38 - iVar11) - iVar3;
      uVar9 = uVar8 & 0xffff;
      if (local_3c == 0xfffffffe) {
        iVar6 = FUN_4042e104(piVar7,uVar12,1,&local_48);
        if (iVar6 < 0) {
          return iVar6;
        }
        iVar3 = FUN_4042c8ac((int)param_1,uVar12,local_48,param_3,(ushort)iVar3,(ushort)uVar8);
      }
      else {
        local_48 = local_3c;
        FUN_404157c4(local_3c,iVar3,(uint)uVar1);
        iVar3 = (**(code **)(*local_40 + 0x10))(local_40);
      }
      if (iVar3 < 0) {
        return iVar3;
      }
      param_3 = (void *)(uVar9 + (int)param_3);
      iVar10 = uVar9 + iVar10;
      if (uVar12 == uVar13) break;
      uVar12 = uVar12 + 1;
      iVar3 = 0;
      iVar6 = FUN_4042e104(piVar7,uVar12,0,&local_3c);
      if (iVar6 < 0) {
        return iVar6;
      }
      if (uVar12 == uVar13) {
        iVar11 = (int)(((uVar2 & 0xffff) - (int)sVar5) * 0x10000) >> 0x10;
      }
    }
    *param_5 = iVar10;
  }
  return 0;
}



/* 4042cfe8 FUN_4042cfe8 */

/* Boundary evidence: original MIPS .pdata 4042cfe8..4042d027. Semantic name remains unreviewed. */

void FUN_4042cfe8(LPVOID param_1)

{
  LONG LVar1;
  
  LVar1 = InterlockedDecrement((LONG *)((int)param_1 + 4));
  if ((LVar1 == 0) && (param_1 != (LPVOID)0x0)) {
    FUN_4040a65c(param_1);
  }
  return;
}



/* 4042d028 FUN_4042d028 */

/* Boundary evidence: original MIPS .pdata 4042d028..4042d0ab. Semantic name remains unreviewed. */

LONG FUN_4042d028(int *param_1)

{
  LONG LVar1;
  int iVar2;
  int iVar3;
  
  LVar1 = InterlockedDecrement(param_1 + 0x15);
  if (LVar1 == 0) {
    if ((*(uint *)(*param_1 + DAT_404304bc + 8) & 0x20) == 0) {
      iVar3 = param_1[0x13];
      iVar2 = param_1[0x12] + DAT_404304bc;
      *(undefined4 *)(iVar2 + 0xc) = *(undefined4 *)(iVar3 + 8);
      *(undefined4 *)(iVar2 + 0x10) = *(undefined4 *)(iVar3 + 0xc);
      *(undefined4 *)(iVar2 + 0x14) = *(undefined4 *)(iVar3 + 0x10);
    }
  }
  else if (LVar1 < 0) {
    LVar1 = 0;
  }
  return LVar1;
}



/* 4042d0ac FUN_4042d0ac */

/* Boundary evidence: original MIPS .pdata 4042d0ac..4042d1f3. Semantic name remains unreviewed. */

undefined4
FUN_4042d0ac(int *param_1,int *param_2,int *param_3,undefined4 param_4,undefined4 *param_5)

{
  BOOL BVar1;
  undefined4 uVar2;
  
  BVar1 = IsBadWritePtr(param_5,4);
  if (BVar1 == 0) {
    *param_5 = 0;
    if ((*(uint *)(*param_1 + DAT_404304bc + 8) & 0x20) == 0) {
      if (((((*param_2 == *param_3) && (param_2[1] == param_3[1])) && (param_2[2] == param_3[2])) &&
          (param_2[3] == param_3[3])) ||
         (((*param_2 == 0 && (param_2[1] == 0)) &&
          ((param_2[2] == 0xc0 && (param_2[3] == 0x46000000)))))) {
        *param_5 = param_4;
        InterlockedIncrement(param_1 + 0x15);
        uVar2 = 0;
      }
      else {
        uVar2 = 0x80004002;
      }
    }
    else {
      uVar2 = 0x80030102;
    }
  }
  else {
    uVar2 = 0x80030009;
  }
  return uVar2;
}



/* 4042d1f4 FUN_4042d1f4 */

/* Boundary evidence: original MIPS .pdata 4042d1f4..4042d39b. Semantic name remains unreviewed. */

int FUN_4042d1f4(int *param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  undefined1 auStack_70 [64];
  ushort local_30;
  uint local_28;
  
  local_28 = DAT_404303e4;
  iVar4 = param_1[0x13];
  if (param_1[0x12] == 0) {
    iVar3 = 0;
  }
  else {
    iVar3 = param_1[0x12] + DAT_404304bc;
  }
  local_30 = 0;
  iVar1 = FUN_40410db8();
  if (-1 < iVar1) {
    if ((*(uint *)(DAT_404304bc + *param_1 + 8) & 0x20) == 0) {
      iVar1 = 0;
      *(undefined4 *)(iVar3 + 0xc) = *(undefined4 *)(iVar4 + 8);
      *(undefined4 *)(iVar3 + 0x10) = *(undefined4 *)(iVar4 + 0xc);
      *(undefined4 *)(iVar3 + 0x14) = *(undefined4 *)(iVar4 + 0x10);
      if (param_2 != 0) {
        do {
          piVar2 = (int *)(*(int *)(DAT_404304bc + *param_1 + 0x5c) + DAT_404304bc);
          iVar1 = (**(code **)(*piVar2 + 0x40))(piVar2,param_1 + 1,auStack_70,0);
          if (iVar1 < 0) {
            if (iVar1 == -0x7ffcffee) {
              iVar1 = 1;
            }
            break;
          }
          if (local_30 < 0x41) {
            *(ushort *)(param_1 + 0x11) = local_30;
          }
          else {
            *(undefined2 *)(param_1 + 0x11) = 0x40;
          }
          memcpy(param_1 + 1,auStack_70,(uint)*(ushort *)(param_1 + 0x11));
          param_2 = param_2 + -1;
        } while (param_2 != 0);
      }
    }
    else {
      iVar1 = -0x7ffcfefe;
    }
    iVar4 = __GetUserKData(8);
    if (DAT_40430480 == iVar4) {
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_4043047c);
    }
  }
  FUN_4042f4c4(local_28);
  return iVar1;
}



/* 4042d39c FUN_4042d39c */

/* Boundary evidence: original MIPS .pdata 4042d39c..4042d487. Semantic name remains unreviewed. */

int FUN_4042d39c(int *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = param_1[0x13];
  if (param_1[0x12] == 0) {
    iVar2 = 0;
  }
  else {
    iVar2 = param_1[0x12] + DAT_404304bc;
  }
  iVar1 = FUN_40410db8();
  if (-1 < iVar1) {
    *(undefined4 *)(iVar2 + 0xc) = *(undefined4 *)(iVar3 + 8);
    *(undefined4 *)(iVar2 + 0x10) = *(undefined4 *)(iVar3 + 0xc);
    *(undefined4 *)(iVar2 + 0x14) = *(undefined4 *)(iVar3 + 0x10);
    *(undefined2 *)(param_1 + 0x11) = 0;
    if ((*(uint *)(*param_1 + DAT_404304bc + 8) & 0x20) == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = -0x7ffcfefe;
    }
    iVar3 = __GetUserKData(8);
    if (DAT_40430480 == iVar3) {
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_4043047c);
    }
  }
  return iVar1;
}



/* 4042d488 FUN_4042d488 */

/* Boundary evidence: original MIPS .pdata 4042d488..4042d4cf. Semantic name remains unreviewed. */

void FUN_4042d488(int param_1)

{
  undefined4 uVar1;
  
  while (*(int *)(param_1 + 0xd0) != param_1) {
    uVar1 = *(undefined4 *)((int)*(void **)(param_1 + 0xd0) + 4);
    operator_delete(*(void **)(param_1 + 0xd0));
    *(undefined4 *)(param_1 + 0xd0) = uVar1;
  }
  return;
}



/* 4042d4d0 FUN_4042d4d0 */

/* Boundary evidence: original MIPS .pdata 4042d4d0..4042d56f. Semantic name remains unreviewed. */

undefined4 FUN_4042d4d0(int param_1,int param_2)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int *piVar3;
  
  if (**(int **)(param_1 + 0xd0) == 0x32) {
    puVar1 = operator_new(0xd0);
    if (puVar1 == (undefined4 *)0x0) {
      puVar1 = (undefined4 *)0x0;
    }
    else {
      uVar2 = *(undefined4 *)(param_1 + 0xd0);
      *puVar1 = 0;
      puVar1[1] = uVar2;
    }
    if (puVar1 == (undefined4 *)0x0) {
      return 0x8007000e;
    }
    *(undefined4 **)(param_1 + 0xd0) = puVar1;
  }
  piVar3 = *(int **)(param_1 + 0xd0);
  piVar3[*piVar3 + 2] = param_2;
  *piVar3 = *piVar3 + 1;
  return 0;
}



/* 4042d570 FUN_4042d570 */

bool FUN_4042d570(int param_1,undefined4 *param_2)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  
  piVar2 = *(int **)(param_1 + 0xd4);
  if ((piVar2 != (int *)0x0) && (*piVar2 <= *(int *)(param_1 + 0xd8))) {
    *(int *)(param_1 + 0xd4) = piVar2[1];
  }
  iVar3 = *(int *)(param_1 + 0xd4);
  if (iVar3 != 0) {
    iVar1 = *(int *)(param_1 + 0xd8);
    *(int *)(param_1 + 0xd8) = iVar1 + 1;
    *param_2 = *(undefined4 *)((iVar1 + 2) * 4 + iVar3);
  }
  return iVar3 != 0;
}



/* 4042d5d8 FUN_4042d5d8 */

bool FUN_4042d5d8(int param_1,uint param_2)

{
  return (1 << ((int)param_2 % 0x10 & 0x1fU) &
         (uint)*(ushort *)(((param_2 >> 4) + 0x20) * 2 + param_1)) != 0;
}



/* 4042d61c FUN_4042d61c */

void FUN_4042d61c(int param_1,uint param_2)

{
  ushort *puVar1;
  
  puVar1 = (ushort *)(((param_2 >> 4) + 0x20) * 2 + param_1);
  *puVar1 = (ushort)(1 << ((int)param_2 % 0x10 & 0x1fU)) | *puVar1;
  return;
}



/* 4042d654 FUN_4042d654 */

/* Boundary evidence: original MIPS .pdata 4042d654..4042d67b. Semantic name remains unreviewed. */

void FUN_4042d654(int param_1)

{
  FUN_4040d6c4((int *)(*(int *)(param_1 + 8) + DAT_404304bc));
  return;
}



/* 4042d67c FUN_4042d67c */

/* Boundary evidence: original MIPS .pdata 4042d67c..4042d6cb. Semantic name remains unreviewed. */

void FUN_4042d67c(int param_1)

{
  if (*(int *)(param_1 + 0xc) == 0) {
    FUN_404156d8(*(int *)(param_1 + 8) + DAT_404304bc);
  }
  else {
    FUN_4040fae4(*(int *)(param_1 + 8) + DAT_404304bc);
  }
  return;
}



/* 4042d6cc FUN_4042d6cc */

/* Boundary evidence: original MIPS .pdata 4042d6cc..4042d6f3. Semantic name remains unreviewed. */

void FUN_4042d6cc(int param_1)

{
  FUN_404156d8(*(int *)(param_1 + 8) + DAT_404304bc);
  return;
}



/* 4042d6f4 FUN_4042d6f4 */

/* Boundary evidence: original MIPS .pdata 4042d6f4..4042d71b. Semantic name remains unreviewed. */

void FUN_4042d6f4(int param_1)

{
  FUN_4040d6bc(*(int *)(param_1 + 8) + DAT_404304bc);
  return;
}



/* 4042d71c FUN_4042d71c */

bool FUN_4042d71c(int *param_1)

{
  return *param_1 != 0;
}



/* 4042d734 FUN_4042d734 */

undefined4 FUN_4042d734(int *param_1)

{
  undefined4 uVar1;
  
  if ((*param_1 != 0) || (uVar1 = 1, param_1[5] == -2)) {
    uVar1 = 0;
  }
  return uVar1;
}



/* 4042d760 FUN_4042d760 */

/* Boundary evidence: original MIPS .pdata 4042d760..4042d78b. Semantic name remains unreviewed. */

void FUN_4042d760(undefined4 param_1,int *param_2)

{
  (**(code **)(*param_2 + 0xc))(param_2,param_1);
  return;
}



/* 4042d78c FUN_4042d78c */

int FUN_4042d78c(int param_1)

{
  uint uVar1;
  
  uVar1 = 0;
  do {
    *(undefined4 *)(uVar1 * 4 + param_1) = 0xfffffffe;
    uVar1 = uVar1 + 1 & 0xffff;
  } while (uVar1 < 0x10);
  *(undefined2 *)(param_1 + 0x40) = 0;
  return param_1;
}



/* 4042d7f4 FUN_4042d7f4 */

undefined4 * FUN_4042d7f4(undefined4 *param_1,int param_2,int param_3)

{
  int iVar1;
  
  if (param_2 == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = param_2 - DAT_404304bc;
  }
  param_1[3] = iVar1;
  if (param_3 == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = param_3 - DAT_404304bc;
  }
  param_1[2] = iVar1;
  *param_1 = 0;
  param_1[5] = 0xfffffffe;
  param_1[1] = 0;
  param_1[4] = 0;
  return param_1;
}



/* 4042d848 FUN_4042d848 */

/* Boundary evidence: original MIPS .pdata 4042d848..4042d8a7. Semantic name remains unreviewed. */

undefined4 FUN_4042d848(int param_1,uint param_2)

{
  undefined4 uVar1;
  int *piVar2;
  
  if (param_2 < 0x40000000) {
    piVar2 = (int *)FUN_4040d71c(*(int *)(param_1 + 8) + DAT_404304bc);
    uVar1 = (**(code **)(*piVar2 + 0xc))(piVar2,param_2 << 2);
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}



/* 4042d8a8 FUN_4042d8a8 */

/* Boundary evidence: original MIPS .pdata 4042d8a8..4042d9fb. Semantic name remains unreviewed. */

void FUN_4042d8a8(int *param_1,int param_2)

{
  bool bVar1;
  int *piVar2;
  undefined3 extraout_var;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint *puVar6;
  uint uVar7;
  uint local_30 [2];
  
  piVar2 = (int *)FUN_4042d67c((int)param_1);
  iVar3 = *(int *)(param_2 * 4 + *param_1 + DAT_404304bc);
  iVar4 = iVar3 + DAT_404304bc;
  if (iVar3 == 0) {
    iVar4 = 0;
  }
  if (iVar4 != 0) {
    uVar5 = 0;
    do {
      puVar6 = (uint *)(uVar5 * 4 + iVar4);
      uVar7 = *puVar6;
      if (((uVar7 != 0xfffffffe) &&
          (bVar1 = FUN_4042d5d8(iVar4,uVar5), CONCAT31(extraout_var,bVar1) != 0)) &&
         (FUN_40421b54(piVar2,uVar7,local_30), local_30[0] == 0xfffffffb)) {
        FUN_404221f0(piVar2,*puVar6,-1);
      }
      uVar5 = uVar5 + 1 & 0xffff;
    } while (uVar5 < 0x10);
    piVar2 = (int *)FUN_4040d71c(param_1[2] + DAT_404304bc);
    (**(code **)(*piVar2 + 0x14))(piVar2,iVar4);
    *(undefined4 *)(param_2 * 4 + *param_1 + DAT_404304bc) = 0;
  }
  return;
}



/* 4042d9fc FUN_4042d9fc */

/* Boundary evidence: original MIPS .pdata 4042d9fc..4042db43. Semantic name remains unreviewed. */

int FUN_4042d9fc(int param_1,uint *param_2,int param_3,int *param_4,int param_5)

{
  undefined2 uVar1;
  uint uVar2;
  int *piVar3;
  int iVar4;
  undefined2 extraout_var;
  int iVar5;
  uint uVar6;
  uint local_30 [2];
  
  uVar2 = FUN_4042d6f4(param_1);
  uVar6 = (uint)(param_3 << 2) / uVar2;
  if (uVar2 == 0) {
    trap(0x1c00);
  }
  piVar3 = (int *)FUN_4042d6cc(param_1);
  if (param_5 == 0) {
    iVar4 = FUN_40421c00(piVar3,*param_2,uVar6,local_30);
  }
  else {
    if ((*param_2 == 0xfffffffe) && (iVar4 = FUN_40424340(piVar3,1,param_2), iVar4 < 0)) {
      return iVar4;
    }
    iVar4 = FUN_40422cac(piVar3,*param_2,uVar6,local_30);
  }
  if (-1 < iVar4) {
    uVar1 = FUN_404156c8(*(int *)(param_1 + 8) + DAT_404304bc);
    if (uVar2 == 0) {
      trap(0x1c00);
    }
    iVar5 = FUN_404157c4(local_30[0],(int)(short)((uint)(param_3 << 2) % uVar2),
                         CONCAT22(extraout_var,uVar1));
    *param_4 = iVar5;
    param_4[1] = 0;
  }
  return iVar4;
}



/* 4042db44 FUN_4042db44 */

/* Boundary evidence: original MIPS .pdata 4042db44..4042dbf3. Semantic name remains unreviewed. */

int FUN_4042db44(int param_1,uint *param_2,int param_3,undefined4 *param_4)

{
  int iVar1;
  int *piVar2;
  int local_20;
  int local_18 [2];
  
  if (*(int *)(param_1 + 0x14) == -2) {
    iVar1 = 0;
  }
  else {
    iVar1 = FUN_4042d9fc(param_1,param_2,param_3,local_18,0);
    if (iVar1 < 0) {
      return iVar1;
    }
    piVar2 = (int *)FUN_4042d654(param_1);
    iVar1 = (**(code **)(*piVar2 + 0xc))(piVar2);
    if (iVar1 < 0) {
      return iVar1;
    }
    if (local_20 == 4) {
      return iVar1;
    }
  }
  *param_4 = 0xfffffffe;
  return iVar1;
}



/* 4042dbf4 FUN_4042dbf4 */

/* Boundary evidence: original MIPS .pdata 4042dbf4..4042dcaf. Semantic name remains unreviewed. */

int FUN_4042dbf4(int param_1,uint *param_2,int param_3)

{
  int iVar1;
  int *piVar2;
  uint uVar3;
  int local_20;
  int local_18 [2];
  
  uVar3 = *param_2;
  iVar1 = FUN_4042d9fc(param_1,param_2,param_3,local_18,1);
  if (-1 < iVar1) {
    piVar2 = (int *)FUN_4042d654(param_1);
    iVar1 = (**(code **)(*piVar2 + 0x10))(piVar2);
    if (-1 < iVar1) {
      if (local_20 == 4) {
        return 0;
      }
      iVar1 = -0x7ffcffe3;
    }
  }
  *param_2 = uVar3;
  return iVar1;
}



/* 4042dcb0 FUN_4042dcb0 */

/* Boundary evidence: original MIPS .pdata 4042dcb0..4042dd2b. Semantic name remains unreviewed. */

int FUN_4042dcb0(int param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  
  uVar2 = param_2 * 0x10;
  uVar3 = uVar2 + 0x10;
  iVar1 = 0;
  if (uVar2 < uVar3) {
    do {
      iVar1 = FUN_4042dbf4(param_1,(uint *)(param_1 + 0x14),uVar2);
      if (iVar1 < 0) {
        return iVar1;
      }
      uVar2 = uVar2 + 1;
    } while (uVar2 < uVar3);
  }
  return iVar1;
}



/* 4042dd2c FUN_4042dd2c */

/* Boundary evidence: original MIPS .pdata 4042dd2c..4042de87. Semantic name remains unreviewed. */

int FUN_4042dd2c(int *param_1)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  int *piVar5;
  int iVar6;
  int iVar7;
  uint local_28 [2];
  
  iVar3 = param_1[1];
  iVar6 = 0;
  uVar4 = 0;
  if (iVar3 << 4 != 0) {
    do {
      iVar6 = FUN_4042e104(param_1,uVar4,0,local_28);
      if (iVar6 < 0) {
        return iVar6;
      }
      iVar6 = FUN_4042dbf4((int)param_1,(uint *)(param_1 + 5),uVar4);
      if (iVar6 < 0) {
        return iVar6;
      }
      uVar4 = uVar4 + 1;
    } while (uVar4 < (uint)(iVar3 << 4));
  }
  piVar5 = (int *)(*param_1 + DAT_404304bc);
  if (*param_1 == 0) {
    piVar5 = (int *)0x0;
  }
  if (piVar5 != (int *)0x0) {
    uVar4 = 0;
    iVar3 = DAT_404304bc;
    piVar2 = piVar5;
    if (param_1[1] != 0) {
      do {
        iVar7 = *piVar2 + iVar3;
        if (*piVar2 == 0) {
          iVar7 = 0;
        }
        if (iVar7 != 0) {
          piVar1 = (int *)FUN_4040d71c(param_1[2] + iVar3);
          (**(code **)(*piVar1 + 0x14))(piVar1,iVar7);
          iVar3 = DAT_404304bc;
        }
        uVar4 = uVar4 + 1;
        piVar2 = piVar2 + 1;
      } while (uVar4 < (uint)param_1[1]);
    }
    piVar2 = (int *)FUN_4040d71c(param_1[2] + iVar3);
    (**(code **)(*piVar2 + 0x14))(piVar2,piVar5);
    *param_1 = 0;
  }
  return iVar6;
}



/* 4042de88 FUN_4042de88 */

/* Boundary evidence: original MIPS .pdata 4042de88..4042e103. Semantic name remains unreviewed. */

int FUN_4042de88(int *param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  int *piVar3;
  uint uVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  uint uVar7;
  undefined4 *puVar8;
  
  uVar1 = FUN_40427d38((int)param_1);
  if (uVar1 == 0) {
    trap(0x1c00);
  }
  uVar7 = param_1[1];
  uVar1 = ((uVar1 + param_2) - 1) / uVar1 + 0xf >> 4;
  if (uVar1 != uVar7) {
    iVar2 = FUN_4042d734(param_1);
    if (iVar2 == 0) {
      if (uVar1 < 0x40000000) {
        iVar2 = FUN_4042d848((int)param_1,uVar1);
        if (iVar2 != 0) {
          if (*param_1 == 0) {
            puVar8 = (undefined4 *)0x0;
          }
          else {
            puVar8 = (undefined4 *)(*param_1 + DAT_404304bc);
          }
          if (puVar8 != (undefined4 *)0x0) {
            uVar7 = 0;
            puVar6 = puVar8;
            while( true ) {
              uVar4 = param_1[1];
              if (uVar1 <= (uint)param_1[1]) {
                uVar4 = uVar1;
              }
              if (uVar4 <= uVar7) break;
              *(undefined4 *)((iVar2 - (int)puVar8) + (int)puVar6) = *puVar6;
              *puVar6 = 0;
              uVar7 = uVar7 + 1;
              puVar6 = puVar6 + 1;
            }
          }
          uVar7 = param_1[1];
          if (uVar7 < uVar1) {
            puVar6 = (undefined4 *)(uVar7 * 4 + iVar2);
            if (uVar1 - uVar7 != 0) {
              puVar5 = puVar6 + (uVar1 - uVar7);
              do {
                *puVar6 = 0;
                puVar6 = puVar6 + 1;
              } while (puVar6 != puVar5);
            }
          }
          uVar7 = uVar1;
          if (uVar1 < (uint)param_1[1]) {
            do {
              FUN_4042d8a8(param_1,uVar7);
              uVar7 = uVar7 + 1;
            } while (uVar7 < (uint)param_1[1]);
          }
          param_1[1] = uVar1;
          piVar3 = (int *)FUN_4040d71c(param_1[2] + DAT_404304bc);
          (**(code **)(*piVar3 + 0x14))(piVar3,puVar8);
          *param_1 = iVar2 - DAT_404304bc;
          return 0;
        }
        iVar2 = FUN_4042dd2c(param_1);
        if (iVar2 < 0) {
          return iVar2;
        }
        for (uVar7 = param_1[1]; uVar7 < uVar1; uVar7 = uVar7 + 1) {
          iVar2 = FUN_4042dcb0((int)param_1,uVar7);
          if (iVar2 < 0) {
            return iVar2;
          }
        }
      }
      else {
        iVar2 = FUN_4042dd2c(param_1);
        if (iVar2 < 0) {
          return iVar2;
        }
        for (uVar7 = param_1[1]; uVar7 < uVar1; uVar7 = uVar7 + 1) {
          iVar2 = FUN_4042dcb0((int)param_1,uVar7);
          if (iVar2 < 0) {
            return iVar2;
          }
        }
      }
    }
    else {
      for (; uVar7 < uVar1; uVar7 = uVar7 + 1) {
        iVar2 = FUN_4042dcb0((int)param_1,uVar7);
        if (iVar2 < 0) {
          return iVar2;
        }
      }
    }
    param_1[1] = uVar1;
  }
  return 0;
}



/* 4042e104 FUN_4042e104 */

/* Boundary evidence: original MIPS .pdata 4042e104..4042e4ff. Semantic name remains unreviewed. */

int FUN_4042e104(int *param_1,uint param_2,uint param_3,uint *param_4)

{
  bool bVar1;
  int iVar2;
  int *piVar3;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  undefined3 extraout_var_01;
  int iVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  uint local_30;
  uint local_2c;
  
  iVar5 = 0;
  uVar8 = param_2 & 0xf;
  iVar2 = FUN_4042d734(param_1);
  if (iVar2 != 0) {
    local_2c = 1;
    iVar2 = FUN_4042db44((int)param_1,(uint *)(param_1 + 5),param_2,param_4);
    if (iVar2 < 0) {
      return iVar2;
    }
    if (param_3 != 2) {
      iVar5 = param_1[4] + DAT_404304bc;
      iVar2 = FUN_4041ad50(iVar5);
      if (iVar2 != 0) {
        piVar3 = (int *)FUN_4041ad50(iVar5);
        piVar3 = (int *)(**(code **)(*piVar3 + 0x10))(piVar3);
        if ((piVar3 != (int *)0x0) &&
           (iVar2 = FUN_4042e83c(piVar3,param_2,*param_4,&local_2c), iVar2 < 0)) {
          return iVar2;
        }
      }
      if (local_2c == 0) {
        *param_4 = 0xfffffffe;
      }
      if ((param_3 == 1) && (*param_4 == 0xfffffffe)) {
        piVar3 = (int *)FUN_4042d67c((int)param_1);
        iVar2 = FUN_40423568(piVar3,1,param_4,0);
        if (iVar2 < 0) {
          return iVar2;
        }
        piVar3 = (int *)FUN_4042d67c((int)param_1);
        iVar2 = FUN_404221f0(piVar3,*param_4,-5);
        if (iVar2 < 0) {
          return iVar2;
        }
        bVar1 = FUN_40427da0((int)param_1);
        if (CONCAT31(extraout_var,bVar1) == 0) {
          iVar2 = param_1[2];
        }
        else {
          iVar2 = param_1[3];
        }
        iVar2 = FUN_404157d4((int *)(iVar2 + DAT_404304bc));
        if (iVar2 < 0) {
          return iVar2;
        }
        iVar2 = FUN_4042dbf4((int)param_1,(uint *)(param_1 + 5),param_2);
        if (iVar2 < 0) {
          return iVar2;
        }
      }
    }
    return 0;
  }
  iVar7 = (param_2 >> 4) * 4;
  piVar3 = (int *)(iVar7 + *param_1 + DAT_404304bc);
  iVar2 = *piVar3;
  if (iVar2 == 0) {
    if ((param_3 & 1) == 0) {
      *param_4 = 0xfffffffe;
      return 0;
    }
    piVar3 = (int *)FUN_4040d71c(param_1[2] + DAT_404304bc);
    iVar2 = FUN_4042d760(0x44,piVar3);
    if (iVar2 == 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = FUN_4042d78c(iVar2);
    }
    iVar4 = iVar2 - DAT_404304bc;
    if (iVar2 == 0) {
      iVar4 = 0;
    }
    *(int *)(iVar7 + *param_1 + DAT_404304bc) = iVar4;
    piVar3 = (int *)(iVar7 + *param_1 + DAT_404304bc);
    iVar2 = *piVar3;
    if (iVar2 == 0) {
      iVar2 = FUN_4042dd2c(param_1);
      if (-1 < iVar2) {
        iVar2 = FUN_4042e104(param_1,param_2,param_3,param_4);
        return iVar2;
      }
      return iVar2;
    }
  }
  uVar6 = *(uint *)(uVar8 * 4 + iVar2 + DAT_404304bc);
  if (param_3 != 2) {
    local_30 = uVar6;
    bVar1 = FUN_4042d5d8(DAT_404304bc + *piVar3,uVar8);
    if (CONCAT31(extraout_var_00,bVar1) == 0) {
      local_30 = 0xfffffffe;
      uVar6 = 0xfffffffe;
    }
    if ((param_3 == 1) && (uVar6 == 0xfffffffe)) {
      piVar3 = (int *)FUN_4042d67c((int)param_1);
      iVar2 = FUN_40423568(piVar3,1,&local_30,0);
      if (iVar2 < 0) {
        return iVar2;
      }
      piVar3 = (int *)FUN_4042d67c((int)param_1);
      iVar2 = FUN_404221f0(piVar3,local_30,-5);
      if (iVar2 < 0) {
        return iVar2;
      }
      bVar1 = FUN_40427da0((int)param_1);
      if (CONCAT31(extraout_var_01,bVar1) == 0) {
        iVar2 = param_1[2];
      }
      else {
        iVar2 = param_1[3];
      }
      iVar5 = FUN_404157d4((int *)(iVar2 + DAT_404304bc));
      if (iVar5 < 0) {
        return iVar5;
      }
      *(uint *)(*(int *)(iVar7 + *param_1 + DAT_404304bc) + uVar8 * 4 + DAT_404304bc) = local_30;
      FUN_4042d61c(*(int *)(iVar7 + *param_1 + DAT_404304bc) + DAT_404304bc,uVar8);
      uVar6 = local_30;
    }
  }
  *param_4 = uVar6;
  return iVar5;
}



/* 4042e500 FUN_4042e500 */

/* Boundary evidence: original MIPS .pdata 4042e500..4042e83b. Semantic name remains unreviewed. */

void FUN_4042e500(int *param_1,int *param_2,uint param_3)

{
  uint uVar1;
  bool bVar2;
  int iVar3;
  int *piVar4;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  int *piVar5;
  int *piVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  ushort *puVar10;
  uint local_30;
  uint local_2c;
  
  iVar3 = FUN_40427db8(param_2);
  if (iVar3 == 0) {
    uVar8 = param_1[1];
    if ((uint)param_2[1] <= (uint)param_1[1]) {
      uVar8 = param_2[1];
    }
    if ((param_3 & 8) != 0) {
      uVar7 = 0;
      if (uVar8 << 4 != 0) {
        do {
          local_2c = 0xfffffffe;
          local_30 = 0xfffffffe;
          FUN_4042e104(param_1,uVar7,0,&local_2c);
          FUN_4042e104(param_2,uVar7,0,&local_30);
          uVar1 = local_2c;
          if (((local_2c != local_30) && (local_2c != 0xfffffffe)) && (local_30 != 0xfffffffe)) {
            piVar4 = (int *)FUN_4042d67c((int)param_1);
            FUN_404221f0(piVar4,uVar1,-1);
          }
          uVar7 = uVar7 + 1;
        } while (uVar7 < uVar8 << 4);
      }
      bVar2 = FUN_4042d71c(param_1);
      if (CONCAT31(extraout_var,bVar2) == 0) {
        iVar3 = FUN_4042d734(param_1);
        if (iVar3 != 0) {
          uVar8 = param_2[1] << 4;
          if (uVar8 < (uint)(param_1[1] << 4)) {
            do {
              local_2c = 0xfffffffe;
              FUN_4042e104(param_1,uVar8,0,&local_2c);
              uVar7 = local_2c;
              if (local_2c != 0xfffffffe) {
                piVar4 = (int *)FUN_4042d67c((int)param_1);
                FUN_404221f0(piVar4,uVar7,-1);
              }
              uVar8 = uVar8 + 1;
            } while (uVar8 < (uint)(param_1[1] << 4));
          }
          piVar4 = (int *)FUN_4042d6cc((int)param_1);
          FUN_404225f0(piVar4,param_1[5],0);
        }
      }
      else {
        for (uVar7 = param_2[1]; uVar7 < (uint)param_1[1]; uVar7 = uVar7 + 1) {
          FUN_4042d8a8(param_1,uVar7);
        }
        piVar4 = (int *)(*param_1 + DAT_404304bc);
        if (*param_1 == 0) {
          piVar4 = (int *)0x0;
        }
        uVar7 = 0;
        piVar6 = piVar4;
        if (uVar8 != 0) {
          do {
            iVar3 = DAT_404304bc;
            if (*piVar6 == 0) {
LAB_4042e6dc:
              iVar9 = 0;
            }
            else {
              bVar2 = FUN_4042d71c(param_2);
              if (CONCAT31(extraout_var_00,bVar2) != 0) {
                puVar10 = (ushort *)(*(int *)(uVar7 * 4 + *param_2 + iVar3) + 0x40 + iVar3);
                *puVar10 = *(ushort *)(*piVar6 + 0x40 + iVar3) | *puVar10;
                iVar3 = DAT_404304bc;
              }
              iVar9 = *piVar6 + iVar3;
              if (*piVar6 == 0) goto LAB_4042e6dc;
            }
            piVar5 = (int *)FUN_4040d71c(iVar3 + param_1[2]);
            (**(code **)(*piVar5 + 0x14))(piVar5,iVar9);
            uVar7 = uVar7 + 1;
            piVar6 = piVar6 + 1;
          } while (uVar7 < uVar8);
        }
        piVar6 = (int *)FUN_4040d71c(param_1[2] + DAT_404304bc);
        (**(code **)(*piVar6 + 0x14))(piVar6,piVar4);
      }
      *param_1 = *param_2;
      param_1[1] = param_2[1];
      param_1[5] = param_2[5];
      *param_2 = 0;
      param_2[1] = 0;
      param_2[5] = -2;
      param_2[4] = 0;
    }
  }
  return;
}



/* 4042e83c FUN_4042e83c */

/* Boundary evidence: original MIPS .pdata 4042e83c..4042e92b. Semantic name remains unreviewed. */

int FUN_4042e83c(int *param_1,uint param_2,uint param_3,uint *param_4)

{
  bool bVar1;
  undefined3 extraout_var;
  int iVar2;
  uint local_20 [2];
  
  iVar2 = 0;
  if (param_2 < (uint)(param_1[1] << 4)) {
    bVar1 = FUN_4042d71c(param_1);
    if (CONCAT31(extraout_var,bVar1) == 0) {
      iVar2 = FUN_4042e104(param_1,param_2,2,local_20);
      if (iVar2 < 0) {
        return iVar2;
      }
    }
    else {
      local_20[0] = *(uint *)(*(int *)((param_2 >> 4) * 4 + *param_1 + DAT_404304bc) +
                              (param_2 & 0xf) * 4 + DAT_404304bc);
    }
    *param_4 = (uint)(local_20[0] != param_3);
  }
  else {
    *param_4 = 1;
  }
  return iVar2;
}



/* 4042e92c FUN_4042e92c */

/* Boundary evidence: original MIPS .pdata 4042e92c..4042ece3. Semantic name remains unreviewed. */

int FUN_4042e92c(int *param_1,int param_2,int param_3)

{
  bool bVar1;
  uint uVar2;
  int iVar3;
  undefined3 extraout_var;
  int *piVar4;
  int *piVar5;
  int iVar6;
  uint uVar7;
  int *piVar8;
  int iVar9;
  uint local_28 [2];
  
  iVar9 = 0;
  uVar2 = FUN_40427d38((int)param_1);
  if (uVar2 == 0) {
    trap(0x1c00);
  }
  param_1[1] = ((uVar2 + param_2) - 1) / uVar2 + 0xf >> 4;
  if (param_3 == 0) {
    iVar6 = 0;
  }
  else {
    iVar6 = param_3 - DAT_404304bc;
  }
  param_1[4] = iVar6;
  iVar6 = iVar6 + DAT_404304bc;
  piVar8 = (int *)0x0;
  iVar3 = FUN_4041ad50(iVar6);
  if (iVar3 != 0) {
    piVar8 = (int *)FUN_4041ad50(iVar6);
    piVar8 = (int *)(**(code **)(*piVar8 + 0x10))(piVar8);
    if ((piVar8 != (int *)0x0) && (bVar1 = FUN_4042d71c(piVar8), CONCAT31(extraout_var,bVar1) == 0))
    goto LAB_4042eba4;
  }
  piVar4 = (int *)FUN_4042d848((int)param_1,param_1[1]);
  if (piVar4 != (int *)0x0) {
    uVar2 = 0;
    piVar5 = piVar4;
    if (param_1[1] != 0) {
      do {
        *piVar5 = 0;
        uVar2 = uVar2 + 1;
        piVar5 = piVar5 + 1;
      } while (uVar2 < (uint)param_1[1]);
    }
    iVar9 = DAT_404304bc;
    if ((piVar8 != (int *)0x0) && (uVar2 = 0, param_1[1] != 0)) {
      iVar6 = 0;
      do {
        if ((uVar2 < (uint)piVar8[1]) && (*(int *)(iVar6 + *piVar8 + iVar9) != 0)) {
          piVar5 = (int *)FUN_4040d71c(param_1[2] + iVar9);
          iVar9 = FUN_4042d760(0x44,piVar5);
          if (iVar9 == 0) {
            iVar3 = 0;
          }
          else {
            iVar3 = FUN_4042d78c(iVar9);
          }
          if (iVar3 == 0) {
            iVar9 = -0x7ffcfff8;
            uVar2 = 0;
            if (param_1[1] != 0) {
              do {
                iVar6 = *piVar4 + DAT_404304bc;
                if (*piVar4 == 0) {
                  iVar6 = 0;
                }
                piVar5 = (int *)FUN_4040d71c(param_1[2] + DAT_404304bc);
                (**(code **)(*piVar5 + 0x14))(piVar5,iVar6);
                uVar2 = uVar2 + 1;
                *piVar4 = 0;
                piVar4 = piVar4 + 1;
              } while (uVar2 < (uint)param_1[1]);
            }
            goto LAB_4042eba4;
          }
          *(int *)(iVar6 + (int)piVar4) = iVar3 - DAT_404304bc;
          uVar7 = 0;
          do {
            iVar9 = uVar7 * 4;
            uVar7 = uVar7 + 1 & 0xffff;
            *(undefined4 *)(iVar9 + iVar3) =
                 *(undefined4 *)(*(int *)(iVar6 + *piVar8 + DAT_404304bc) + iVar9 + DAT_404304bc);
            iVar9 = DAT_404304bc;
          } while (uVar7 < 0x10);
        }
        uVar2 = uVar2 + 1;
        iVar6 = iVar6 + 4;
      } while (uVar2 < (uint)param_1[1]);
    }
    *param_1 = (int)piVar4 - iVar9;
    return 0;
  }
  iVar9 = -0x7ffcfff8;
LAB_4042eba4:
  *param_1 = 0;
  if (piVar8 == (int *)0x0) {
    uVar2 = 0;
    if (param_1[1] != 0) {
      do {
        iVar9 = FUN_4042dcb0((int)param_1,uVar2);
        if (iVar9 < 0) {
          return iVar9;
        }
        uVar2 = uVar2 + 1;
      } while (uVar2 < (uint)param_1[1]);
    }
  }
  else {
    uVar2 = 0;
    while( true ) {
      uVar7 = param_1[1];
      if ((uint)piVar8[1] <= (uint)param_1[1]) {
        uVar7 = piVar8[1];
      }
      if (uVar7 << 4 <= uVar2) break;
      iVar9 = FUN_4042e104(piVar8,uVar2,2,local_28);
      if (iVar9 < 0) {
        return iVar9;
      }
      iVar9 = FUN_4042dbf4((int)param_1,(uint *)(param_1 + 5),uVar2);
      if (iVar9 < 0) {
        return iVar9;
      }
      uVar2 = uVar2 + 1;
    }
    uVar2 = piVar8[1];
    if (uVar2 < (uint)param_1[1]) {
      do {
        iVar9 = FUN_4042dcb0((int)param_1,uVar2);
        if (iVar9 < 0) {
          return iVar9;
        }
        uVar2 = uVar2 + 1;
      } while (uVar2 < (uint)param_1[1]);
      return iVar9;
    }
  }
  return iVar9;
}



/* 4042ece4 FUN_4042ece4 */

/* Boundary evidence: original MIPS .pdata 4042ece4..4042ee13. Semantic name remains unreviewed. */

void FUN_4042ece4(int param_1,uint param_2,int param_3)

{
  uint uVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  uint uVar5;
  int *piVar6;
  uint uVar7;
  uint local_res4 [3];
  uint local_28;
  uint local_24;
  
  iVar4 = *(int *)(param_1 + 0x10) + DAT_404304bc;
  uVar7 = 1;
  local_28 = 1;
  piVar6 = (int *)0x0;
  local_res4[0] = param_2;
  iVar2 = FUN_4041ad50(iVar4);
  if (iVar2 != 0) {
    piVar6 = (int *)FUN_4041ad50(iVar4);
    piVar6 = (int *)(**(code **)(*piVar6 + 0x10))(piVar6);
  }
  uVar5 = 0;
  if (param_3 << 4 != 0) {
    do {
      FUN_4042db44(param_1,local_res4,uVar5,&local_24);
      if (piVar6 != (int *)0x0) {
        FUN_4042e83c(piVar6,uVar5,local_24,&local_28);
        uVar7 = local_28;
      }
      uVar1 = local_24;
      if ((local_24 != 0xfffffffe) && (uVar7 != 0)) {
        piVar3 = (int *)FUN_4042d67c(param_1);
        FUN_404221f0(piVar3,uVar1,-1);
      }
      uVar5 = uVar5 + 1;
    } while (uVar5 < (uint)(param_3 << 4));
  }
  piVar6 = (int *)FUN_4042d6cc(param_1);
  FUN_404225f0(piVar6,local_res4[0],0);
  return;
}



/* 4042ee14 FUN_4042ee14 */

/* Boundary evidence: original MIPS .pdata 4042ee14..4042ef1f. Semantic name remains unreviewed. */

void FUN_4042ee14(int *param_1)

{
  bool bVar1;
  undefined3 extraout_var;
  int *piVar2;
  int iVar3;
  int *piVar4;
  uint uVar5;
  
  bVar1 = FUN_4042d71c(param_1);
  if (CONCAT31(extraout_var,bVar1) == 0) {
    iVar3 = FUN_4042d734(param_1);
    if (iVar3 != 0) {
      if (param_1[5] != 0xfffffffe) {
        FUN_4042ece4((int)param_1,param_1[5],param_1[1]);
      }
      param_1[5] = -2;
    }
  }
  else {
    piVar4 = (int *)(*param_1 + DAT_404304bc);
    if (*param_1 == 0) {
      piVar4 = (int *)0x0;
    }
    uVar5 = 0;
    piVar2 = piVar4;
    if (param_1[1] != 0) {
      do {
        if (*piVar2 != 0) {
          FUN_4042d8a8(param_1,uVar5);
        }
        uVar5 = uVar5 + 1;
        piVar2 = piVar2 + 1;
      } while (uVar5 < (uint)param_1[1]);
    }
    piVar2 = (int *)FUN_4040d71c(param_1[2] + DAT_404304bc);
    (**(code **)(*piVar2 + 0x14))(piVar2,piVar4);
    *param_1 = 0;
  }
  param_1[4] = 0;
  param_1[1] = 0;
  return;
}



/* 4042ef20 FUN_4042ef20 */

/* Boundary evidence: original MIPS .pdata 4042ef20..4042ef3b. Semantic name remains unreviewed. */

void FUN_4042ef20(int *param_1)

{
  FUN_4042ee14(param_1);
  return;
}



/* 4042ef3c FUN_4042ef3c */

/* Boundary evidence: original MIPS .pdata 4042ef3c..4042f07f. Semantic name remains unreviewed. */

int FUN_4042ef3c(int param_1,undefined4 *param_2,uint param_3)

{
  int iVar1;
  LPVOID pvVar2;
  uint uVar3;
  int *piVar4;
  undefined4 local_20 [2];
  
  uVar3 = *(uint *)(param_1 + 0xc);
  param_2[1] = uVar3;
  if ((uVar3 & 3) == 1) {
    piVar4 = (int *)(param_1 + -8);
    iVar1 = (**(code **)*piVar4)(piVar4,0,param_2 + 6);
    if (iVar1 < 0) {
      return iVar1;
    }
    iVar1 = (**(code **)*piVar4)(piVar4,2,param_2 + 8);
    if (iVar1 < 0) {
      return iVar1;
    }
    iVar1 = (**(code **)*piVar4)(piVar4,1,param_2 + 4);
    if (iVar1 < 0) {
      return iVar1;
    }
    iVar1 = (**(code **)(*piVar4 + 0x20))(piVar4,param_2 + 0xc);
    if (iVar1 < 0) {
      return iVar1;
    }
    iVar1 = (**(code **)(*piVar4 + 0x28))(piVar4,param_2 + 0x10);
    if (iVar1 < 0) {
      return iVar1;
    }
    param_2[2] = 0;
  }
  else {
    (**(code **)(*(int *)(param_1 + -8) + 0x20))((int *)(param_1 + -8),local_20);
    param_2[2] = local_20[0];
  }
  param_2[3] = 0;
  if ((param_3 & 1) == 0) {
    pvVar2 = FUN_40419804((void *)(param_1 + 0x20));
    *param_2 = pvVar2;
    if (pvVar2 == (LPVOID)0x0) {
      return -0x7ffcfff8;
    }
  }
  else {
    *param_2 = 0;
  }
  return 0;
}



/* 4042f210 FUN_4042f210 */

/* Boundary evidence: original MIPS .pdata 4042f210..4042f34b. Semantic name remains unreviewed. */

int FUN_4042f210(undefined4 param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 1;
  if (param_2 == 1) {
    if (DAT_404314f0 != (code *)0x0) {
      iVar2 = (*DAT_404314f0)(param_1,1,param_3);
    }
    iVar1 = 0;
    if (iVar2 == 0) goto LAB_4042f2c0;
    FUN_4042f6a4();
  }
  iVar1 = 0;
  if (iVar2 != 0) {
    iVar1 = FUN_404024f4(param_1,param_2,param_3);
  }
LAB_4042f2c0:
  if (((param_2 == 0) && (FUN_4042f62c(), iVar1 != 0)) && (DAT_404314f0 != (code *)0x0)) {
    iVar1 = (*DAT_404314f0)(param_1,0,param_3);
  }
  return iVar1;
}



/* 4042f34c FUN_4042f34c */

/* Boundary evidence: original MIPS .pdata 4042f34c..4042f377. Semantic name remains unreviewed. */

void FUN_4042f34c(_EXCEPTION_POINTERS *param_1)

{
  _XcptFilter(param_1->ExceptionRecord->ExceptionCode,param_1);
  return;
}



/* 4042f378 entry */

/* Boundary evidence: original MIPS .pdata 4042f378..4042f3cf. Semantic name remains unreviewed. */

void entry(undefined4 param_1,int param_2,int param_3)

{
  if (param_2 == 1) {
    FUN_4042f3d0();
  }
  FUN_4042f210(param_1,param_2,param_3);
  return;
}



/* 4042f3d0 FUN_4042f3d0 */

/* Boundary evidence: original MIPS .pdata 4042f3d0..4042f443. Semantic name remains unreviewed. */

void FUN_4042f3d0(void)

{
  uint uVar1;
  
  if ((DAT_404303e4 == 0) || (DAT_404303e4 == 0xb064)) {
    uVar1 = __security_gen_cookie2();
    DAT_404303e4 = uVar1 >> 0x10 ^ uVar1 & 0xffff;
    if (DAT_404303e4 == 0) {
      DAT_404303e4 = 0xb064;
    }
  }
  DAT_404303e8 = ~DAT_404303e4;
  return;
}



/* 4042f444 FUN_4042f444 */

/* Boundary evidence: original MIPS .pdata 4042f444..4042f497. Semantic name remains unreviewed. */

void FUN_4042f444(int param_1,undefined4 param_2,uint *param_3)

{
  if ((*param_3 & 1) != 0) {
    param_1 = ((-param_3[2] & param_3[1] + param_1) - (param_3[1] + param_1)) + param_1;
  }
  FUN_4042f4c4(*(uint *)(param_1 + (*param_3 & 0xfffffffc)));
  return;
}



/* 4042f498 FUN_4042f498 */

/* Boundary evidence: original MIPS .pdata 4042f498..4042f4c3. Semantic name remains unreviewed. */

undefined4 FUN_4042f498(undefined4 param_1,int param_2,undefined4 param_3,int param_4)

{
  FUN_4042f444(param_2,param_4,*(uint **)(*(int *)(param_4 + 4) + 0xc));
  return 1;
}



/* 4042f4c4 FUN_4042f4c4 */

/* Boundary evidence: original MIPS .pdata 4042f4c4..4042f50b. Semantic name remains unreviewed. */

void FUN_4042f4c4(uint param_1)

{
  if ((param_1 == DAT_404303e4) && (param_1 >> 0x10 == 0)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __report_gsfailure();
}



/* 4042f50c FUN_4042f50c */

/* Boundary evidence: original MIPS .pdata 4042f50c..4042f62b. Semantic name remains unreviewed. */

void FUN_4042f50c(UINT param_1,int param_2,int param_3)

{
  LPCRITICAL_SECTION lpCriticalSection;
  undefined4 *_Memory;
  
  DAT_404314e0 = (undefined1)param_3;
  if (param_2 == 0) {
    _Memory = DAT_404314e8;
    if (DAT_404314e8 != (undefined4 *)0x0) {
      while (DAT_404314e4 = DAT_404314e4 + -1, _Memory <= DAT_404314e4) {
        if ((code *)*DAT_404314e4 != (code *)0x0) {
          (*(code *)*DAT_404314e4)();
          _Memory = DAT_404314e8;
        }
      }
      free(_Memory);
      DAT_404314e4 = (undefined4 *)0x0;
      DAT_404314e8 = (undefined4 *)0x0;
    }
    FUN_4042f650((undefined4 *)&DAT_40401014,(undefined4 *)&DAT_40401018);
  }
  FUN_4042f650((undefined4 *)&DAT_4040101c,(undefined4 *)&DAT_40401020);
  if (param_3 == 0) {
    TerminateProcess((HANDLE)0x42,param_1);
  }
  else {
    lpCriticalSection = (LPCRITICAL_SECTION)InterlockedExchange((LONG *)&DAT_404314ec,0);
    if (lpCriticalSection != (LPCRITICAL_SECTION)0x0) {
      DeleteCriticalSection(lpCriticalSection);
      free(lpCriticalSection);
    }
  }
  return;
}



/* 4042f62c FUN_4042f62c */

/* Boundary evidence: original MIPS .pdata 4042f62c..4042f64f. Semantic name remains unreviewed. */

void FUN_4042f62c(void)

{
  FUN_4042f50c(0,0,1);
  return;
}



/* 4042f650 FUN_4042f650 */

/* Boundary evidence: original MIPS .pdata 4042f650..4042f6a3. Semantic name remains unreviewed. */

void FUN_4042f650(undefined4 *param_1,undefined4 *param_2)

{
  for (; param_1 < param_2; param_1 = param_1 + 1) {
    if ((code *)*param_1 != (code *)0x0) {
      (*(code *)*param_1)();
    }
  }
  return;
}



/* 4042f6a4 FUN_4042f6a4 */

/* Boundary evidence: original MIPS .pdata 4042f6a4..4042f6df. Semantic name remains unreviewed. */

void FUN_4042f6a4(void)

{
  FUN_4042f650((undefined4 *)&DAT_4040100c,(undefined4 *)&DAT_40401010);
  FUN_4042f650((undefined4 *)&DAT_40401000,(undefined4 *)&DAT_40401008);
  return;
}



/* 4042f820 FUN_4042f820 */

/* Boundary evidence: original MIPS .pdata 4042f820..4042f83f. Semantic name remains unreviewed. */

void FUN_4042f820(void)

{
  FUN_40406c8c((undefined4 *)&DAT_40430458);
  return;
}


