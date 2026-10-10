/* Automatic Ghidra pseudocode. Not original source; not runtime-verified. */

/* 40773208 FUN_40773208 */

/* Boundary evidence: original MIPS .pdata 40773208..407732f3. Semantic name remains unreviewed. */

undefined4 FUN_40773208(int *param_1,int *param_2,int *param_3)

{
  undefined4 uVar1;
  
  if (param_3 == (int *)0x0) {
    uVar1 = 0x80004003;
  }
  else {
    *param_3 = 0;
    if (((((*param_2 == 0) && (param_2[1] == 0)) && (param_2[2] == 0xc0)) &&
        (param_2[3] == 0x46000000)) ||
       (((*param_2 == 1 && (param_2[1] == 0)) &&
        ((param_2[2] == 0xc0 && (param_2[3] == 0x46000000)))))) {
      *param_3 = (int)param_1;
      (**(code **)(*param_1 + 4))();
      uVar1 = 0;
    }
    else {
      uVar1 = (*(code *)**(undefined4 **)param_1[10])();
    }
  }
  return uVar1;
}



/* 407732f4 FUN_407732f4 */

void FUN_407732f4(int param_1)

{
  *(int *)(param_1 + 0x24) = *(int *)(param_1 + 0x24) + 1;
  return;
}



/* 40773304 FUN_40773304 */

/* Boundary evidence: original MIPS .pdata 40773304..40773513. Semantic name remains unreviewed. */

HRESULT FUN_40773304(LPUNKNOWN param_1,int param_2,int *param_3,undefined4 *param_4)

{
  int iVar1;
  HRESULT HVar2;
  LPUNKNOWN pIVar3;
  int *local_20;
  int *local_1c;
  
  if (param_4 == (undefined4 *)0x0) {
    HVar2 = -0x7fffbffd;
  }
  else if ((param_2 == 0) &&
          ((((((iVar1 = *param_3, iVar1 == 0 && (param_3[1] == 0)) && (param_3[2] == 0xc0)) &&
             (param_3[3] == 0x46000000)) ||
            (((iVar1 == 1 && (param_3[1] == 0)) &&
             ((param_3[2] == 0xc0 && (param_3[3] == 0x46000000)))))) ||
           (((iVar1 == 0x56a86895 && (param_3[1] == 0x11ce0ad4)) &&
            ((param_3[2] == 0x20003ab0 && (param_3[3] == 0x70a70baf)))))))) {
    HVar2 = CoCreateInstance((IID *)&DAT_40772234,param_1,3,(IID *)&DAT_40771584,&local_20);
    if (-1 < HVar2) {
      pIVar3 = param_1 + 10;
      HVar2 = (**(code **)*local_20)(local_20,&DAT_40772bc4,pIVar3);
      (**(code **)(*local_20 + 8))();
      if (-1 < HVar2) {
        HVar2 = (**(code **)pIVar3->lpVtbl->QueryInterface)(pIVar3->lpVtbl,&UNK_407730c4,&local_1c);
        if (-1 < HVar2) {
          HVar2 = (**(code **)(*local_1c + 0xc))(local_1c,param_1 + 1,param_1 + 5);
          (**(code **)(*local_1c + 8))();
          *param_4 = pIVar3->lpVtbl;
          return HVar2;
        }
        (**(code **)(pIVar3->lpVtbl->QueryInterface + 8))();
      }
    }
    *param_4 = 0;
  }
  else {
    HVar2 = -0x7fffbffe;
  }
  return HVar2;
}



/* 40773548 FUN_40773548 */

/* Boundary evidence: original MIPS .pdata 40773548..4077384b. Semantic name remains unreviewed. */

undefined4 FUN_40773548(undefined4 *param_1,void *param_2,void *param_3)

{
  LSTATUS LVar1;
  int iVar2;
  HKEY local_1a0;
  DWORD local_19c;
  HKEY local_198;
  DWORD local_194;
  undefined1 auStack_190 [16];
  undefined1 auStack_180 [16];
  wchar_t awStack_170 [7];
  wchar_t wStack_162;
  undefined1 auStack_160 [144];
  WCHAR aWStack_d0 [80];
  uint local_30;
  
  local_30 = DAT_407780a0;
  memcpy(param_2,&DAT_40771594,0x10);
  memcpy(param_3,&DAT_40771594,0x10);
  memcpy(awStack_170,L"CLSID\\{",0x10);
  memset(auStack_160,0,0x90);
  DMOGuidToStrW(&wStack_162,param_1);
  wcscat(awStack_170,L"}");
  RegOpenKeyExW((HKEY)0x80000000,awStack_170,0,0xf003f,&local_1a0);
  if (local_1a0 != (HKEY)0x0) {
    local_19c = 0x50;
    LVar1 = RegQueryValueExW(local_1a0,L"DMOGUID",(LPDWORD)0x0,&local_194,(LPBYTE)aWStack_d0,
                             &local_19c);
    if ((((LVar1 == 0) && (local_194 == 1)) && (local_19c == 0x4a)) &&
       (iVar2 = DMOStrToGuidW(aWStack_d0,(int)auStack_180), iVar2 != 0)) {
      wsprintfW(awStack_170,L"CLSID\\{%s}",aWStack_d0);
      LVar1 = RegOpenKeyExW((HKEY)0x80000000,awStack_170,0,0xf003f,&local_198);
      if (local_198 != (HKEY)0x0) {
        RegCloseKey(local_198);
      }
      if (LVar1 == 0) {
        memcpy(param_2,auStack_180,0x10);
        local_19c = 0x50;
        LVar1 = RegQueryValueExW(local_1a0,L"DMOCategory",(LPDWORD)0x0,&local_194,(LPBYTE)aWStack_d0
                                 ,&local_19c);
        RegCloseKey(local_1a0);
        if (((LVar1 == 0) && (local_194 == 1)) &&
           ((local_19c == 0x4a && (iVar2 = DMOStrToGuidW(aWStack_d0,(int)auStack_190), iVar2 != 0)))
           ) {
          wsprintfW(awStack_170,L"\\DirectShow\\MediaObjects\\Categories\\%s",aWStack_d0);
          LVar1 = RegOpenKeyExW((HKEY)0x80000000,awStack_170,0,0xf003f,&local_198);
          if (local_198 != (HKEY)0x0) {
            RegCloseKey(local_198);
          }
          if (LVar1 == 0) {
            memcpy(param_3,auStack_190,0x10);
            FUN_40777488(local_30);
            return 0;
          }
        }
        goto LAB_4077380c;
      }
    }
    RegCloseKey(local_1a0);
  }
LAB_4077380c:
  FUN_40777488(local_30);
  return 0x80004005;
}



/* 4077384c DllCanUnloadNow */

HRESULT DllCanUnloadNow(void)

{
  HRESULT HVar1;
  
                    /* 0x384c  12  DllCanUnloadNow */
  if ((0 < DAT_407780b0) || (HVar1 = 0, DAT_407780ac != 0)) {
    HVar1 = 1;
  }
  return HVar1;
}



/* 40773878 FUN_40773878 */

/* Boundary evidence: original MIPS .pdata 40773878..407738bb. Semantic name remains unreviewed. */

undefined4 FUN_40773878(HMODULE param_1,int param_2)

{
  if (param_2 == 1) {
    DisableThreadLibraryCalls(param_1);
    DAT_407780a8 = param_1;
  }
  return 1;
}



/* 407738bc FUN_407738bc */

/* Boundary evidence: original MIPS .pdata 407738bc..407738f7. Semantic name remains unreviewed. */

int FUN_407738bc(void *param_1)

{
  int iVar1;
  
  iVar1 = *(int *)((int)param_1 + 0x24) + -1;
  *(int *)((int)param_1 + 0x24) = iVar1;
  if (iVar1 == 0) {
    DAT_407780ac = DAT_407780ac + -1;
    operator_delete(param_1);
    iVar1 = 0;
  }
  return iVar1;
}



/* 407738f8 DllGetClassObject */

/* Boundary evidence: original MIPS .pdata 407738f8..40773a93. Semantic name remains unreviewed. */

HRESULT DllGetClassObject(IID *rclsid,IID *riid,LPVOID *ppv)

{
  int iVar1;
  HRESULT HVar2;
  int *piVar3;
  int iVar4;
  undefined1 auStack_38 [16];
  undefined1 auStack_28 [16];
  uint local_18;
  
                    /* 0x38f8  13  DllGetClassObject */
  local_18 = DAT_407780a0;
  if (((((riid->Data1 == 0) && (iVar1._0_2_ = riid->Data2, iVar1._2_2_ = riid->Data3, iVar1 == 0))
       && (*(int *)riid->Data4 == 0xc0)) && (*(int *)(riid->Data4 + 4) == 0x46000000)) ||
     (((riid->Data1 == 1 && (iVar4._0_2_ = riid->Data2, iVar4._2_2_ = riid->Data3, iVar4 == 0)) &&
      ((*(int *)riid->Data4 == 0xc0 && (*(int *)(riid->Data4 + 4) == 0x46000000)))))) {
    iVar1 = FUN_40773548(&rclsid->Data1,auStack_38,auStack_28);
    if (iVar1 < 0) {
      FUN_40777488(local_18);
      HVar2 = -0x7ffbfeef;
    }
    else {
      piVar3 = operator_new(0x2c);
      if (piVar3 == (int *)0x0) {
        piVar3 = (int *)0x0;
      }
      else {
        DAT_407780ac = DAT_407780ac + 1;
        *piVar3 = (int)&PTR_FUN_407710e0;
        piVar3[9] = 0;
        piVar3[10] = 0;
        memcpy(piVar3 + 1,auStack_38,0x10);
        memcpy(piVar3 + 5,auStack_28,0x10);
      }
      *ppv = piVar3;
      if (piVar3 == (int *)0x0) {
        FUN_40777488(local_18);
        HVar2 = -0x7ff8fff2;
      }
      else {
        (**(code **)(*piVar3 + 4))(piVar3);
        FUN_40777488(local_18);
        HVar2 = 0;
      }
    }
  }
  else {
    FUN_40777488(DAT_407780a0);
    HVar2 = -0x7fffbffe;
  }
  return HVar2;
}



/* 40773a94 FUN_40773a94 */

/* Boundary evidence: original MIPS .pdata 40773a94..40773b5b. Semantic name remains unreviewed. */

LSTATUS FUN_40773a94(HKEY param_1,LPCWSTR param_2,LPBYTE param_3,LPDWORD param_4)

{
  LSTATUS LVar1;
  HKEY local_20;
  DWORD local_1c;
  
  local_1c = 1;
  local_20 = param_1;
  if (((param_2 == (LPCWSTR)0x0) ||
      (LVar1 = RegOpenKeyExW(param_1,param_2,0,0xf003f,&local_20), LVar1 == 0)) &&
     (LVar1 = RegQueryValueExW(local_20,(LPCWSTR)0x0,(LPDWORD)0x0,&local_1c,param_3,param_4),
     param_1 != local_20)) {
    RegCloseKey(local_20);
  }
  return LVar1;
}



/* 40773b5c FUN_40773b5c */

/* Boundary evidence: original MIPS .pdata 40773b5c..40773c83. Semantic name remains unreviewed. */

LSTATUS FUN_40773b5c(HKEY param_1,LPCWSTR param_2,uint param_3,wchar_t *param_4,DWORD param_5)

{
  size_t sVar1;
  LSTATUS LVar2;
  HKEY local_20 [2];
  
  if (((param_4 != (wchar_t *)0x0) && (param_5 == 0)) && ((param_3 | 1) != 0)) {
    sVar1 = wcslen(param_4);
    param_5 = (sVar1 + 1) * 2;
  }
  if (param_2 == (LPCWSTR)0x0) {
    LVar2 = RegSetValueExW(param_1,(LPCWSTR)0x0,0,param_3,(BYTE *)param_4,param_5);
  }
  else {
    LVar2 = RegCreateKeyExW(param_1,param_2,0,(LPWSTR)0x0,0,0xf003f,(LPSECURITY_ATTRIBUTES)0x0,
                            local_20,(LPDWORD)0x0);
    if (LVar2 == 0) {
      LVar2 = RegSetValueExW(local_20[0],(LPCWSTR)0x0,0,param_3,(BYTE *)param_4,param_5);
      RegCloseKey(local_20[0]);
    }
  }
  return LVar2;
}



/* 40773c84 FUN_40773c84 */

/* Boundary evidence: original MIPS .pdata 40773c84..40773e0b. Semantic name remains unreviewed. */

LSTATUS FUN_40773c84(HKEY param_1,LPCWSTR param_2)

{
  LSTATUS LVar1;
  int iVar2;
  HKEY local_440;
  DWORD local_43c;
  DWORD local_438;
  DWORD local_434;
  WCHAR aWStack_430 [264];
  WCHAR aWStack_220 [260];
  uint local_18;
  
  local_18 = DAT_407780a0;
  LVar1 = RegOpenKeyExW(param_1,param_2,0,0xf003f,&local_440);
  if (LVar1 == 0) {
    local_438 = 0x105;
    local_434 = 0x104;
    LVar1 = RegQueryInfoKeyW(local_440,aWStack_220,&local_434,(LPDWORD)0x0,&local_43c,(LPDWORD)0x0,
                             (LPDWORD)0x0,(LPDWORD)0x0,(LPDWORD)0x0,(LPDWORD)0x0,(LPDWORD)0x0,
                             (PFILETIME)0x0);
    if ((LVar1 == 0) && (local_43c != 0)) {
      local_43c = local_43c - 1;
      iVar2 = RegEnumKeyExW(local_440,local_43c,aWStack_430,&local_438,(LPDWORD)0x0,(LPWSTR)0x0,
                            (LPDWORD)0x0,(PFILETIME)0x0);
      while (iVar2 == 0) {
        FUN_40773c84(local_440,aWStack_430);
        local_43c = local_43c - 1;
        iVar2 = RegEnumKeyExW(local_440,local_43c,aWStack_430,&local_438,(LPDWORD)0x0,(LPWSTR)0x0,
                              (LPDWORD)0x0,(PFILETIME)0x0);
      }
    }
    RegCloseKey(local_440);
    LVar1 = RegDeleteKeyW(param_1,param_2);
  }
  FUN_40777488(local_18);
  return LVar1;
}



/* 40773e0c FUN_40773e0c */

/* Boundary evidence: original MIPS .pdata 40773e0c..40773e97. Semantic name remains unreviewed. */

undefined4 * FUN_40773e0c(undefined4 *param_1,HKEY param_2,LPCWSTR param_3,PHKEY param_4)

{
  LSTATUS LVar1;
  
  LVar1 = RegCreateKeyExW(param_2,param_3,0,L"",0,0x2000000,(LPSECURITY_ATTRIBUTES)0x0,param_4,
                          (LPDWORD)0x0);
  if (LVar1 == 0) {
    *param_1 = *param_4;
  }
  else {
    *param_4 = (HKEY)0x0;
    *param_1 = 0;
  }
  return param_1;
}



/* 40773e98 FUN_40773e98 */

/* Boundary evidence: original MIPS .pdata 40773e98..40773f0b. Semantic name remains unreviewed. */

undefined4 *
FUN_40773e98(undefined4 *param_1,HKEY param_2,LPCWSTR param_3,PHKEY param_4,REGSAM param_5)

{
  LSTATUS LVar1;
  
  LVar1 = RegOpenKeyExW(param_2,param_3,0,param_5,param_4);
  if (LVar1 == 0) {
    *param_1 = *param_4;
  }
  else {
    *param_4 = (HKEY)0x0;
    *param_1 = 0;
  }
  return param_1;
}



/* 40773f0c FUN_40773f0c */

/* Boundary evidence: original MIPS .pdata 40773f0c..407741d7. Semantic name remains unreviewed. */

undefined4 FUN_40773f0c(HKEY param_1,LPCWSTR param_2,int *param_3,undefined4 *param_4)

{
  bool bVar1;
  LPVOID pvVar2;
  LSTATUS LVar3;
  int iVar4;
  int iVar5;
  DWORD dwIndex;
  int iVar6;
  LPVOID pv;
  DWORD dwIndex_00;
  HKEY local_470;
  HKEY local_46c;
  DWORD local_468 [2];
  undefined1 auStack_460 [16];
  undefined1 auStack_450 [16];
  WCHAR aWStack_440 [260];
  WCHAR aWStack_238 [260];
  uint local_30;
  
  local_30 = DAT_407780a0;
  pvVar2 = CoTaskMemAlloc(0);
  local_470 = (HKEY)0x0;
  iVar6 = 0;
  LVar3 = RegOpenKeyExW(param_1,param_2,0,0xf003f,&local_470);
  dwIndex_00 = 0;
  if (LVar3 == 0) {
    bVar1 = true;
    do {
      local_468[0] = 0x104;
      LVar3 = RegEnumKeyExW(local_470,dwIndex_00,aWStack_440,local_468,(LPDWORD)0x0,(LPWSTR)0x0,
                            (LPDWORD)0x0,(PFILETIME)0x0);
      if (LVar3 != 0) {
        if (LVar3 != 0x103) {
          bVar1 = false;
        }
        if ((bVar1) && (iVar6 != 0)) {
          *param_4 = pvVar2;
          *param_3 = iVar6 << 5;
          if (local_470 != (HKEY)0x0) {
            RegCloseKey(local_470);
          }
          FUN_40777488(local_30);
          return 0;
        }
        break;
      }
      iVar4 = DMOStrToGuidW(aWStack_440,(int)auStack_460);
      if (iVar4 != 0) {
        local_46c = (HKEY)0x0;
        RegOpenKeyExW(local_470,aWStack_440,0,0xf003f,&local_46c);
        if (local_46c == (HKEY)0x0) {
          bVar1 = false;
        }
        else {
          dwIndex = 0;
          if (bVar1) {
            iVar4 = iVar6 << 5;
            pv = pvVar2;
            do {
              local_468[0] = 0x104;
              LVar3 = RegEnumKeyExW(local_46c,dwIndex,aWStack_238,local_468,(LPDWORD)0x0,(LPWSTR)0x0
                                    ,(LPDWORD)0x0,(PFILETIME)0x0);
              pvVar2 = pv;
              if (LVar3 != 0) {
                if (LVar3 != 0x103) {
                  bVar1 = false;
                }
                break;
              }
              iVar5 = DMOStrToGuidW(aWStack_238,(int)auStack_450);
              if (iVar5 != 0) {
                pvVar2 = CoTaskMemRealloc(pv,iVar4 + 0x20);
                if (pvVar2 == (LPVOID)0x0) {
                  bVar1 = false;
                  pvVar2 = pv;
                }
                else {
                  memcpy((void *)(iVar4 + (int)pvVar2),auStack_460,0x20);
                  iVar6 = iVar6 + 1;
                  iVar4 = iVar4 + 0x20;
                }
              }
              dwIndex = dwIndex + 1;
              pv = pvVar2;
            } while (bVar1);
          }
          if (local_46c != (HKEY)0x0) {
            RegCloseKey(local_46c);
          }
        }
      }
      dwIndex_00 = dwIndex_00 + 1;
    } while (bVar1);
  }
  CoTaskMemFree(pvVar2);
  if (local_470 != (HKEY)0x0) {
    RegCloseKey(local_470);
  }
  FUN_40777488(local_30);
  return 1;
}



/* 407741d8 FUN_407741d8 */

/* Boundary evidence: original MIPS .pdata 407741d8..407742ef. Semantic name remains unreviewed. */

undefined4 FUN_407741d8(HKEY param_1,LPCWSTR param_2,SIZE_T *param_3,undefined4 *param_4)

{
  LSTATUS LVar1;
  undefined4 uVar2;
  LPBYTE lpData;
  SIZE_T local_28 [2];
  
  *param_3 = 0;
  LVar1 = RegQueryValueExW(param_1,param_2,(LPDWORD)0x0,(LPDWORD)0x0,(LPBYTE)0x0,local_28);
  if (LVar1 != 0) {
    uVar2 = FUN_40773f0c(param_1,param_2,(int *)param_3,param_4);
    return uVar2;
  }
  if (local_28[0] == 0) {
LAB_40774264:
    uVar2 = 0;
  }
  else {
    lpData = CoTaskMemAlloc(local_28[0]);
    if (lpData != (LPBYTE)0x0) {
      LVar1 = RegQueryValueExW(param_1,param_2,(LPDWORD)0x0,(LPDWORD)0x0,lpData,local_28);
      if (LVar1 == 0) {
        *param_4 = lpData;
        *param_3 = local_28[0];
        goto LAB_40774264;
      }
      CoTaskMemFree(lpData);
    }
    uVar2 = 0x8007000e;
  }
  return uVar2;
}



/* 407742f0 DMORegister */

/* Boundary evidence: original MIPS .pdata 407742f0..40774b5f. Semantic name remains unreviewed. */

undefined4
DMORegister(wchar_t *param_1,int *param_2,int *param_3,uint param_4,int param_5,BYTE *param_6,
           int param_7,BYTE *param_8)

{
  HKEY pHVar1;
  LSTATUS LVar2;
  size_t sVar3;
  int iVar4;
  wchar_t *_Str;
  HKEY local_100;
  HKEY local_fc;
  HKEY local_f8;
  HKEY local_f4;
  HKEY local_f0;
  HKEY local_ec;
  HKEY local_e8;
  HKEY local_e4;
  HKEY local_e0;
  HKEY local_dc;
  DWORD local_d8 [2];
  wchar_t awStack_d0 [80];
  uint local_30;
  
                    /* 0x42f0  6  DMORegister */
  local_30 = DAT_407780a0;
  if (((((*param_2 == 0) && (param_2[1] == 0)) && (param_2[2] == 0)) && (param_2[3] == 0)) ||
     (((*param_3 == 0 && (param_3[1] == 0)) && ((param_3[2] == 0 && (param_3[3] == 0)))))) {
    FUN_40777488(DAT_407780a0);
    return 0x80070057;
  }
  FUN_40773e0c(&local_100,(HKEY)0x80000000,L"DirectShow\\MediaObjects",&local_e4);
  if (local_e4 != (HKEY)0x0) {
    FUN_40773e0c(&local_fc,local_e4,L"Categories",&local_e0);
    if (local_e0 == (HKEY)0x0) {
      if (local_fc != (HKEY)0x0) {
        RegCloseKey(local_fc);
      }
    }
    else {
      DMOGuidToStrW(awStack_d0,param_3);
      FUN_40773e0c(&local_f8,local_e0,awStack_d0,&local_f4);
      if (local_f4 == (HKEY)0x0) {
        if (local_f8 != (HKEY)0x0) {
          RegCloseKey(local_f8);
        }
        if (local_fc != (HKEY)0x0) {
          RegCloseKey(local_fc);
        }
      }
      else {
        FUN_40773c84(local_f4,L"InputTypes");
        FUN_40773c84(local_f4,L"OutputTypes");
        LVar2 = FUN_40773a94(local_f4,(LPCWSTR)0x0,(LPBYTE)0x0,local_d8);
        if ((LVar2 != 0) || ((int)local_d8[0] < 2)) {
          iVar4 = *param_3;
          if ((iVar4 == 0x57f2db8b) &&
             (((param_3[1] == 0x4513e6bb && (param_3[2] == -0x2d23bc63)) &&
              (param_3[3] == 0x253159a6)))) {
            _Str = L"Audio decoders";
          }
          else if ((((iVar4 == 0x33d9a761) && (param_3[1] == 0x11d090c8)) &&
                   (param_3[2] == -0x5fffbc43)) && (param_3[3] == -0x7931ee37)) {
            _Str = L"Audio encoders";
          }
          else if (((iVar4 == 0x4a69b442) && (param_3[1] == 0x499128be)) &&
                  ((param_3[2] == 0xb59c96 && (param_3[3] == -0x57270a53)))) {
            _Str = L"Video decoders";
          }
          else if ((((iVar4 == 0x33d9a760) && (param_3[1] == 0x11d090c8)) &&
                   (param_3[2] == -0x5fffbc43)) && (param_3[3] == -0x7931ee37)) {
            _Str = L"Video encoders";
          }
          else if (((iVar4 == -0xc9fd4c1) && (param_3[1] == 0x48df0592)) &&
                  ((param_3[2] == 0x4767cda4 && (param_3[3] == -0x141418df)))) {
            _Str = L"Audio effects";
          }
          else if (((iVar4 == -0x266f11ec) && (param_3[1] == 0x4723776c)) &&
                  ((param_3[2] == -0x5dc2b942 && (param_3[3] == -0x46ef900b)))) {
            _Str = L"Video effects";
          }
          else if ((((iVar4 == -0x99a5546) && (param_3[1] == 0x49203e09)) &&
                   (param_3[2] == -0x67dea056)) && (param_3[3] == 0x98f1411)) {
            _Str = L"Audio capture effects";
          }
          else if (((iVar4 == -0x4069c280) && (param_3[1] == 0x11d0c559)) &&
                  ((param_3[2] == -0x5fffd476 && (param_3[3] == -0x3ea5da37)))) {
            _Str = L"Acoustic Echo Canceller";
          }
          else if ((((iVar4 == -0x1f806fc1) && (param_3[1] == 0x4e6062fd)) &&
                   (param_3[2] == -0x58212274)) && (param_3[3] == -0x4a9a99dd)) {
            _Str = L"Audio Noise Suppressor";
          }
          else if ((((iVar4 == -0x17736460) && (param_3[1] == 0x11d0c557)) &&
                   (param_3[2] == -0x5fffd476)) && (param_3[3] == -0x3ea5da37)) {
            _Str = L"Automatic Gain Control";
          }
          else {
            _Str = L"Unknown DMO category";
          }
          sVar3 = wcslen(_Str);
          FUN_40773b5c(local_f4,(LPCWSTR)0x0,1,_Str,(sVar3 + 1) * 2);
        }
        DMOGuidToStrW(awStack_d0,param_2);
        FUN_40773c84(local_e4,awStack_d0);
        FUN_40773e0c(&local_f0,local_f4,awStack_d0,&local_dc);
        if (local_dc == (HKEY)0x0) {
          if (local_f0 != (HKEY)0x0) {
            RegCloseKey(local_f0);
          }
        }
        else {
          DMOGuidToStrW(awStack_d0,param_2);
          FUN_40773e0c(&local_e8,local_e4,awStack_d0,&local_ec);
          pHVar1 = local_ec;
          if (local_ec == (HKEY)0x0) {
            if (local_e8 != (HKEY)0x0) {
              RegCloseKey(local_e8);
            }
            if (local_f0 != (HKEY)0x0) {
              RegCloseKey(local_f0);
            }
            if (local_f8 != (HKEY)0x0) {
              RegCloseKey(local_f8);
            }
            if (local_fc != (HKEY)0x0) {
              RegCloseKey(local_fc);
            }
            goto joined_r0x40774990;
          }
          sVar3 = wcslen(param_1);
          LVar2 = FUN_40773b5c(pHVar1,(LPCWSTR)0x0,1,param_1,(sVar3 + 1) * 2);
          if ((LVar2 == 0) &&
             (((param_4 & 1) == 0 || (LVar2 = FUN_40773b5c(local_ec,L"Keyed",1,L"",0), LVar2 == 0)))
             ) {
            if (param_5 != 0) {
              RegSetValueExW(local_ec,L"InputTypes",0,3,param_6,param_5 << 5);
            }
            if (param_7 != 0) {
              RegSetValueExW(local_ec,L"OutputTypes",0,3,param_8,param_7 << 5);
            }
            FUN_40773c84((HKEY)0x80000001,
                         L"Software\\Microsoft\\Multimedia\\ActiveMovie\\Filter Cache");
            if (local_e8 != (HKEY)0x0) {
              RegCloseKey(local_e8);
            }
            if (local_f0 != (HKEY)0x0) {
              RegCloseKey(local_f0);
            }
            if (local_f8 != (HKEY)0x0) {
              RegCloseKey(local_f8);
            }
            if (local_fc != (HKEY)0x0) {
              RegCloseKey(local_fc);
            }
            if (local_100 != (HKEY)0x0) {
              RegCloseKey(local_100);
            }
            FUN_40777488(local_30);
            return 0;
          }
          if (local_e8 != (HKEY)0x0) {
            RegCloseKey(local_e8);
          }
          if (local_f0 != (HKEY)0x0) {
            RegCloseKey(local_f0);
          }
        }
        if (local_f8 != (HKEY)0x0) {
          RegCloseKey(local_f8);
        }
        if (local_fc != (HKEY)0x0) {
          RegCloseKey(local_fc);
        }
      }
    }
  }
joined_r0x40774990:
  if (local_100 != (HKEY)0x0) {
    RegCloseKey(local_100);
  }
  FUN_40777488(local_30);
  return 0x80004005;
}



/* 40774b60 FUN_40774b60 */

/* Boundary evidence: original MIPS .pdata 40774b60..40774bbb. Semantic name remains unreviewed. */

void FUN_40774b60(wchar_t *param_1,undefined4 *param_2,undefined4 *param_3)

{
  size_t sVar1;
  
  DMOGuidToStrW(param_1,param_2);
  wcscat(param_1,L"\\");
  sVar1 = wcslen(param_1);
  DMOGuidToStrW(param_1 + sVar1,param_3);
  return;
}



/* 40774bbc DMORegisterFilter */

/* Boundary evidence: original MIPS .pdata 40774bbc..4077547f. Semantic name remains unreviewed. */

undefined4
DMORegisterFilter(wchar_t *param_1,GUID *param_2,int *param_3,GUID *param_4,uint param_5,
                 uint param_6,GUID *param_7,uint param_8,GUID *param_9)

{
  int iVar1;
  size_t sVar2;
  LSTATUS LVar3;
  HKEY hKey;
  uint uVar4;
  HKEY local_2c0;
  HKEY local_2bc;
  HKEY local_2b8;
  HKEY local_2b4;
  HKEY local_2b0;
  HKEY local_2ac;
  HKEY local_2a8;
  HKEY local_2a4;
  HKEY local_2a0;
  HKEY local_29c;
  HKEY local_298;
  undefined4 local_294;
  HKEY local_290;
  HKEY local_28c;
  HKEY local_288;
  HKEY local_284;
  HKEY local_280;
  undefined4 local_27c;
  HKEY local_278;
  HKEY local_274;
  DWORD local_270;
  HKEY local_26c;
  DWORD aDStack_268 [2];
  OLECHAR aOStack_260 [40];
  OLECHAR aOStack_210 [40];
  wchar_t awStack_1c0 [40];
  wchar_t awStack_170 [40];
  OLECHAR aOStack_120 [40];
  wchar_t awStack_d0 [10];
  undefined1 auStack_bc [140];
  uint local_30;
  
                    /* 0x4bbc  7  DMORegisterFilter */
  local_30 = DAT_407780a0;
  iVar1 = DMORegister(param_1,(int *)param_2,param_3,param_5,param_6,(BYTE *)param_7,param_8,
                      (BYTE *)param_9);
  if (iVar1 < 0) goto LAB_40774c40;
  if ((((param_4->Data1 == 0) &&
       (iVar1._0_2_ = param_4->Data2, iVar1._2_2_ = param_4->Data3, iVar1 == 0)) &&
      (*(int *)param_4->Data4 == 0)) && (*(int *)(param_4->Data4 + 4) == 0)) goto LAB_40775444;
  FUN_40773e0c(&local_2c0,(HKEY)0x80000000,L"CLSID",&local_29c);
  iVar1 = StringFromGUID2(param_4,aOStack_210,0x27);
  if (-1 < iVar1) {
    FUN_40773e98(&local_2b8,local_29c,aOStack_210,&local_288,0x2000000);
    if (local_288 != (HKEY)0x0) {
      FUN_40773c84(local_29c,aOStack_210);
    }
    FUN_40773e0c(&local_2bc,local_29c,aOStack_210,&local_2a0);
    sVar2 = wcslen(param_1);
    LVar3 = RegSetValueExW(local_2a0,(LPCWSTR)0x0,0,1,(BYTE *)param_1,(sVar2 + 1) * 2);
    if (LVar3 == 0) {
      DMOGuidToStrW(awStack_1c0,&param_2->Data1);
      sVar2 = wcslen(awStack_1c0);
      LVar3 = RegSetValueExW(local_2a0,L"DMOGuid",0,1,(BYTE *)awStack_1c0,(sVar2 + 1) * 2);
      if (LVar3 == 0) {
        DMOGuidToStrW(awStack_170,param_3);
        sVar2 = wcslen(awStack_170);
        LVar3 = RegSetValueExW(local_2a0,L"DMOCategory",0,1,(BYTE *)awStack_170,(sVar2 + 1) * 2);
        if (LVar3 == 0) {
          local_270 = 4;
          local_294 = 0x600800;
          iVar1 = StringFromGUID2(param_2,aOStack_120,0x27);
          if (-1 < iVar1) {
            FUN_40773e98(&local_2b0,local_29c,aOStack_120,&local_26c,0x2000000);
            if ((local_26c != (HKEY)0x0) &&
               (LVar3 = RegQueryValueExW(local_26c,L"Merit",(LPDWORD)0x0,aDStack_268,
                                         (LPBYTE)&local_294,&local_270), LVar3 != 0)) {
              local_294 = 0x600800;
            }
            LVar3 = RegSetValueExW(local_2a0,L"Merit",0,4,(BYTE *)&local_294,4);
            if (LVar3 == 0) {
              FUN_40773e0c(&local_2ac,local_2a0,L"InprocServer32",&local_278);
              memcpy(awStack_d0,L"msdmo.dll",0x14);
              memset(auStack_bc,0,0x8c);
              sVar2 = wcslen(awStack_d0);
              LVar3 = RegSetValueExW(local_278,(LPCWSTR)0x0,0,1,(BYTE *)awStack_d0,(sVar2 + 1) * 2);
              if (LVar3 == 0) {
                if (param_6 == 0) {
LAB_40775174:
                  if (param_8 == 0) {
LAB_40775320:
                    FUN_40773e0c(&local_2a8,(HKEY)0x80000000,L"Filter",&local_274);
                    hKey = local_2a8;
                    if (local_274 != (HKEY)0x0) {
                      FUN_40773e0c(&local_2b4,local_274,aOStack_210,&local_284);
                      if (local_284 != (HKEY)0x0) {
                        if (local_2b4 != (HKEY)0x0) {
                          RegCloseKey(local_2b4);
                        }
                        if (local_2a8 != (HKEY)0x0) {
                          RegCloseKey(local_2a8);
                        }
                        if (local_2ac != (HKEY)0x0) {
                          RegCloseKey(local_2ac);
                        }
                        if (local_2b0 != (HKEY)0x0) {
                          RegCloseKey(local_2b0);
                        }
                        if (local_2bc != (HKEY)0x0) {
                          RegCloseKey(local_2bc);
                        }
                        if (local_2b8 != (HKEY)0x0) {
                          RegCloseKey(local_2b8);
                        }
                        if (local_2c0 != (HKEY)0x0) {
                          RegCloseKey(local_2c0);
                        }
LAB_40775444:
                        FUN_40777488(local_30);
                        return 0;
                      }
                      hKey = local_2a8;
                      if (local_2b4 != (HKEY)0x0) {
                        RegCloseKey(local_2b4);
                        hKey = local_2a8;
                      }
                    }
                  }
                  else {
                    FUN_40773e0c(&local_2b4,local_2a0,L"Pins\\Output",&local_280);
                    hKey = local_2b4;
                    if (local_280 != (HKEY)0x0) {
                      local_27c = 1;
                      LVar3 = RegSetValueExW(local_280,L"Direction",0,4,(BYTE *)&local_27c,4);
                      hKey = local_2b4;
                      if (LVar3 == 0) {
                        FUN_40773e0c(&local_2a8,local_2a0,L"Pins\\Output\\Types",&local_28c);
                        if (local_28c != (HKEY)0x0) {
                          uVar4 = 0;
                          if (param_8 != 0) {
                            do {
                              iVar1 = StringFromGUID2(param_9,aOStack_260,0x27);
                              if ((iVar1 < 0) ||
                                 (LVar3 = RegCreateKeyExW(local_28c,aOStack_260,0,L"",0,0x2000000,
                                                          (LPSECURITY_ATTRIBUTES)0x0,&local_2a4,
                                                          (LPDWORD)0x0), LVar3 != 0))
                              goto LAB_40775200;
                              iVar1 = StringFromGUID2(param_9 + 1,aOStack_260,0x27);
                              if ((iVar1 < 0) ||
                                 (LVar3 = RegCreateKeyExW(local_2a4,aOStack_260,0,L"",0,0x2000000,
                                                          (LPSECURITY_ATTRIBUTES)0x0,&local_298,
                                                          (LPDWORD)0x0), LVar3 != 0)) {
                                RegCloseKey(local_2a4);
                                goto LAB_40775200;
                              }
                              RegCloseKey(local_2a4);
                              RegCloseKey(local_298);
                              uVar4 = uVar4 + 1;
                              param_9 = param_9 + 2;
                            } while (uVar4 < param_8);
                          }
                          if (local_2a8 != (HKEY)0x0) {
                            RegCloseKey(local_2a8);
                          }
                          if (local_2b4 != (HKEY)0x0) {
                            RegCloseKey(local_2b4);
                          }
                          goto LAB_40775320;
                        }
LAB_40775200:
                        local_2a4 = local_2a8;
                        hKey = local_2b4;
                        if (local_2a8 != (HKEY)0x0) {
LAB_40775210:
                          RegCloseKey(local_2a4);
                          hKey = local_2b4;
                        }
                      }
                    }
                  }
                }
                else {
                  FUN_40773e0c(&local_2b4,local_2a0,L"Pins\\Input\\Types",&local_290);
                  hKey = local_2b4;
                  if (local_290 != (HKEY)0x0) {
                    uVar4 = 0;
                    if (param_6 != 0) {
                      do {
                        iVar1 = StringFromGUID2(param_7,aOStack_260,0x27);
                        hKey = local_2b4;
                        if ((iVar1 < 0) ||
                           (LVar3 = RegCreateKeyExW(local_290,aOStack_260,0,L"",0,0x2000000,
                                                    (LPSECURITY_ATTRIBUTES)0x0,&local_2a4,
                                                    (LPDWORD)0x0), hKey = local_2b4, LVar3 != 0))
                        goto LAB_40775004;
                        iVar1 = StringFromGUID2(param_7 + 1,aOStack_260,0x27);
                        if ((iVar1 < 0) ||
                           (LVar3 = RegCreateKeyExW(local_2a4,aOStack_260,0,L"",0,0x2000000,
                                                    (LPSECURITY_ATTRIBUTES)0x0,&local_298,
                                                    (LPDWORD)0x0), LVar3 != 0)) goto LAB_40775210;
                        RegCloseKey(local_2a4);
                        RegCloseKey(local_298);
                        uVar4 = uVar4 + 1;
                        param_7 = param_7 + 2;
                      } while (uVar4 < param_6);
                    }
                    if (local_2b4 != (HKEY)0x0) {
                      RegCloseKey(local_2b4);
                    }
                    goto LAB_40775174;
                  }
                }
LAB_40775004:
                if (hKey != (HKEY)0x0) {
                  RegCloseKey(hKey);
                }
                if (local_2ac != (HKEY)0x0) {
                  RegCloseKey(local_2ac);
                }
                if (local_2b0 != (HKEY)0x0) {
                  RegCloseKey(local_2b0);
                }
                if (local_2bc != (HKEY)0x0) {
                  RegCloseKey(local_2bc);
                }
                if (local_2b8 != (HKEY)0x0) {
                  RegCloseKey(local_2b8);
                }
                goto joined_r0x4077507c;
              }
              if (local_2ac != (HKEY)0x0) {
                RegCloseKey(local_2ac);
              }
            }
            if (local_2b0 != (HKEY)0x0) {
              RegCloseKey(local_2b0);
            }
          }
        }
      }
    }
    if (local_2bc != (HKEY)0x0) {
      RegCloseKey(local_2bc);
    }
    if (local_2b8 != (HKEY)0x0) {
      RegCloseKey(local_2b8);
    }
  }
joined_r0x4077507c:
  if (local_2c0 != (HKEY)0x0) {
    RegCloseKey(local_2c0);
  }
LAB_40774c40:
  FUN_40777488(local_30);
  return 0x80004005;
}



/* 40775480 DMOUnregister */

/* Boundary evidence: original MIPS .pdata 40775480..407757ab. Semantic name remains unreviewed. */

undefined4 DMOUnregister(undefined4 *param_1,int *param_2)

{
  bool bVar1;
  bool bVar2;
  LSTATUS LVar3;
  int iVar4;
  undefined4 uVar5;
  DWORD dwIndex;
  HKEY local_348;
  HKEY local_344;
  HKEY local_340;
  HKEY local_33c;
  DWORD local_338;
  HKEY local_334;
  int local_330;
  int local_32c;
  int local_328;
  int local_324;
  wchar_t awStack_320 [80];
  wchar_t awStack_280 [40];
  wchar_t awStack_230 [256];
  uint local_30;
  
                    /* 0x5480  10  DMOUnregister */
  local_30 = DAT_407780a0;
  FUN_40773e98(&local_344,(HKEY)0x80000000,L"DirectShow\\MediaObjects",&local_340,0x2000000);
  if (local_340 == (HKEY)0x0) {
joined_r0x4077555c:
    if (local_344 != (HKEY)0x0) {
      RegCloseKey(local_344);
    }
    FUN_40777488(local_30);
    return 0x80004005;
  }
  FUN_40773e98(&local_334,local_340,L"Categories",&local_348,0x2000000);
  if (local_348 == (HKEY)0x0) {
    if (local_334 != (HKEY)0x0) {
      RegCloseKey(local_334);
    }
    goto joined_r0x4077555c;
  }
  dwIndex = 0;
  bVar1 = false;
  bVar2 = true;
  DMOGuidToStrW(awStack_320,param_2);
  local_338 = 0x50;
  LVar3 = RegEnumKeyExW(local_348,0,awStack_320,&local_338,(LPDWORD)0x0,(LPWSTR)0x0,(LPDWORD)0x0,
                        (PFILETIME)0x0);
  if (LVar3 == 0) {
    do {
      iVar4 = DMOStrToGuidW(awStack_320,(int)&local_330);
      if (iVar4 != 0) {
        FUN_40774b60(awStack_230,&local_330,param_1);
        if (((((*param_2 == 0) && (param_2[1] == 0)) && (param_2[2] == 0)) && (param_2[3] == 0)) ||
           (((local_330 == *param_2 && (local_32c == param_2[1])) &&
            ((local_328 == param_2[2] && (local_324 == param_2[3])))))) {
          LVar3 = FUN_40773c84(local_348,awStack_230);
          if (LVar3 == 0) {
            bVar1 = true;
          }
        }
        else {
          local_33c = (HKEY)0x0;
          LVar3 = RegOpenKeyExW(local_348,awStack_230,0,0xf003f,&local_33c);
          if (LVar3 != 2) {
            bVar2 = false;
          }
          if (local_33c != (HKEY)0x0) {
            RegCloseKey(local_33c);
          }
        }
      }
      dwIndex = dwIndex + 1;
      LVar3 = RegEnumKeyExW(local_348,dwIndex,awStack_320,&local_338,(LPDWORD)0x0,(LPWSTR)0x0,
                            (LPDWORD)0x0,(PFILETIME)0x0);
    } while (LVar3 == 0);
    if (bVar1) {
      uVar5 = 0;
      if (!bVar2) goto LAB_40775740;
      DMOGuidToStrW(awStack_280,param_1);
      LVar3 = FUN_40773c84(local_340,awStack_280);
      if (LVar3 == 0) goto LAB_40775740;
    }
  }
  uVar5 = 1;
LAB_40775740:
  if (local_334 != (HKEY)0x0) {
    RegCloseKey(local_334);
  }
  if (local_344 != (HKEY)0x0) {
    RegCloseKey(local_344);
  }
  FUN_40777488(local_30);
  return uVar5;
}



/* 407757ac DMOUnregisterFilter */

/* Boundary evidence: original MIPS .pdata 407757ac..40775a0b. Semantic name remains unreviewed. */

undefined4 DMOUnregisterFilter(GUID *param_1)

{
  int iVar1;
  LSTATUS LVar2;
  HKEY local_158;
  HKEY local_154;
  HKEY local_150;
  DWORD local_14c;
  HKEY local_148;
  DWORD local_144;
  HKEY local_140;
  DWORD local_13c;
  DWORD aDStack_138 [2];
  int aiStack_130 [4];
  undefined4 auStack_120 [4];
  OLECHAR aOStack_110 [40];
  WCHAR aWStack_c0 [40];
  WCHAR aWStack_70 [40];
  uint local_20;
  
                    /* 0x57ac  11  DMOUnregisterFilter */
  local_20 = DAT_407780a0;
  FUN_40773e0c(&local_158,(HKEY)0x80000000,L"CLSID",&local_148);
  iVar1 = StringFromGUID2(param_1,aOStack_110,0x27);
  if (-1 < iVar1) {
    FUN_40773e98(&local_154,local_148,aOStack_110,&local_150,0x2000000);
    if (local_150 != (HKEY)0x0) {
      local_13c = 0x4e;
      LVar2 = RegQueryValueExW(local_150,L"DMOGuid",(LPDWORD)0x0,&local_14c,(LPBYTE)aWStack_c0,
                               &local_13c);
      if ((LVar2 == 0) && (local_14c == 1)) {
        DMOStrToGuidW(aWStack_c0,(int)auStack_120);
        local_144 = 0x4e;
        LVar2 = RegQueryValueExW(local_150,L"DMOCategory",(LPDWORD)0x0,aDStack_138,
                                 (LPBYTE)aWStack_70,&local_144);
        if ((LVar2 == 0) && (local_14c == 1)) {
          DMOStrToGuidW(aWStack_70,(int)aiStack_130);
          iVar1 = DMOUnregister(auStack_120,aiStack_130);
          if (iVar1 == 0) {
            if (local_154 != (HKEY)0x0) {
              RegCloseKey(local_154);
            }
            LVar2 = FUN_40773c84(local_148,aOStack_110);
            if (LVar2 != 0) goto joined_r0x407759c8;
            FUN_40773e98(&local_154,(HKEY)0x80000000,L"Filter",&local_140,0x2000000);
            if ((local_140 != (HKEY)0x0) &&
               (LVar2 = FUN_40773c84(local_140,aOStack_110), LVar2 == 0)) {
              if (local_154 != (HKEY)0x0) {
                RegCloseKey(local_154);
              }
              if (local_158 != (HKEY)0x0) {
                RegCloseKey(local_158);
              }
              FUN_40777488(local_20);
              return 0;
            }
          }
        }
      }
    }
    if (local_154 != (HKEY)0x0) {
      RegCloseKey(local_154);
    }
  }
joined_r0x407759c8:
  if (local_158 != (HKEY)0x0) {
    RegCloseKey(local_158);
  }
  FUN_40777488(local_20);
  return 0x80004005;
}



/* 40775a0c FUN_40775a0c */

/* Boundary evidence: original MIPS .pdata 40775a0c..40775a5b. Semantic name remains unreviewed. */

bool FUN_40775a0c(HKEY param_1,LPBYTE param_2)

{
  LSTATUS LVar1;
  DWORD local_10 [2];
  
  local_10[0] = 0x50;
  LVar1 = FUN_40773a94(param_1,(LPCWSTR)0x0,param_2,local_10);
  if (LVar1 != 0) {
    param_2[0] = '\0';
    param_2[1] = '\0';
  }
  return LVar1 != 0;
}



/* 40775a5c FUN_40775a5c */

/* Boundary evidence: original MIPS .pdata 40775a5c..40775af7. Semantic name remains unreviewed. */

void FUN_40775a5c(HKEY param_1,undefined4 param_2,uint param_3,undefined4 *param_4,int param_5)

{
  LSTATUS LVar1;
  int3 extraout_var;
  DWORD aDStack_c0 [2];
  wchar_t local_b8 [80];
  uint local_18;
  
  local_18 = DAT_407780a0;
  if (((param_3 & 1) != 0) ||
     (LVar1 = FUN_40773a94(param_1,L"Keyed",(LPBYTE)0x0,aDStack_c0), LVar1 != 0)) {
    FUN_40775a0c(param_1,(LPBYTE)local_b8);
    if (extraout_var < 0) {
      local_b8[0] = L'\0';
    }
    FUN_40777000(param_5,param_4,local_b8);
  }
  FUN_40777488(local_18);
  return;
}



/* 40775af8 FUN_40775af8 */

/* Boundary evidence: original MIPS .pdata 40775af8..40775cff. Semantic name remains unreviewed. */

undefined4 FUN_40775af8(HKEY param_1,uint param_2,int *param_3,LPCWSTR param_4)

{
  int iVar1;
  uint uVar2;
  int *piVar3;
  int *piVar4;
  undefined4 uVar5;
  LPVOID local_18;
  SIZE_T local_14;
  
  if (param_2 == 0) {
    uVar5 = 1;
  }
  else {
    local_18 = (LPVOID)0x0;
    iVar1 = FUN_407741d8(param_1,param_4,&local_14,&local_18);
    if ((iVar1 == 0) && (uVar2 = 0, param_2 != 0)) {
      do {
        if ((int *)((int)local_18 + 0x20U) <= (int *)(local_14 + (int)local_18)) {
          piVar4 = (int *)((int)local_18 + 0x10);
          do {
            if (((((((piVar4[-4] == *param_3) && (piVar4[-3] == param_3[1])) &&
                   (piVar4[-2] == param_3[2])) && (piVar4[-1] == param_3[3])) ||
                 (((piVar4[-4] == 0 && (piVar4[-3] == 0)) &&
                  ((piVar4[-2] == 0 && (piVar4[-1] == 0)))))) ||
                (((*param_3 == 0 && (param_3[1] == 0)) && ((param_3[2] == 0 && (param_3[3] == 0)))))
                ) && ((((((param_3[4] == 0 && (param_3[5] == 0)) && (param_3[6] == 0)) &&
                        (param_3[7] == 0)) ||
                       (((*piVar4 == 0 && (piVar4[1] == 0)) &&
                        ((piVar4[2] == 0 && (piVar4[3] == 0)))))) ||
                      (((param_3[4] == *piVar4 && (param_3[5] == piVar4[1])) &&
                       ((param_3[6] == piVar4[2] && (param_3[7] == piVar4[3])))))))) {
              uVar5 = 1;
              goto LAB_40775cd8;
            }
            piVar3 = piVar4 + 0xc;
            piVar4 = piVar4 + 8;
          } while (piVar3 <= (int *)(local_14 + (int)local_18));
        }
        uVar2 = uVar2 + 1;
        param_3 = param_3 + 8;
      } while (uVar2 < param_2);
    }
    uVar5 = 0;
LAB_40775cd8:
    CoTaskMemFree(local_18);
  }
  return uVar5;
}



/* 40775d00 FUN_40775d00 */

/* Boundary evidence: original MIPS .pdata 40775d00..40775eeb. Semantic name remains unreviewed. */

undefined4
FUN_40775d00(HKEY param_1,HKEY param_2,uint param_3,uint param_4,int *param_5,uint param_6,
            int *param_7,int param_8)

{
  int iVar1;
  LSTATUS LVar2;
  DWORD dwIndex;
  HKEY local_f0;
  DWORD local_ec;
  HKEY local_e8;
  HKEY local_e4;
  undefined4 auStack_e0 [4];
  WCHAR aWStack_d0 [80];
  uint local_30;
  
  local_30 = DAT_407780a0;
  local_ec = 0x50;
  dwIndex = 0;
  local_e8 = param_1;
  local_e4 = param_2;
  iVar1 = RegEnumKeyExW(param_2,0,aWStack_d0,&local_ec,(LPDWORD)0x0,(LPWSTR)0x0,(LPDWORD)0x0,
                        (PFILETIME)0x0);
  while (iVar1 != 0x103) {
    iVar1 = DMOStrToGuidW(aWStack_d0,(int)auStack_e0);
    if (iVar1 != 0) {
      local_f0 = (HKEY)0x0;
      LVar2 = RegOpenKeyExW(local_e8,aWStack_d0,0,0xf003f,&local_f0);
      if (((LVar2 == 0) &&
          (iVar1 = FUN_40775af8(local_f0,param_4,param_5,L"InputTypes"), iVar1 != 0)) &&
         (iVar1 = FUN_40775af8(local_f0,param_6,param_7,L"OutputTypes"), iVar1 != 0)) {
        FUN_40775a5c(local_f0,aWStack_d0,param_3,auStack_e0,param_8);
      }
      if (local_f0 != (HKEY)0x0) {
        RegCloseKey(local_f0);
      }
    }
    local_ec = 0x50;
    dwIndex = dwIndex + 1;
    iVar1 = RegEnumKeyExW(local_e4,dwIndex,aWStack_d0,&local_ec,(LPDWORD)0x0,(LPWSTR)0x0,
                          (LPDWORD)0x0,(PFILETIME)0x0);
  }
  FUN_40777488(local_30);
  return 0;
}



/* 40775eec FUN_40775eec */

/* Boundary evidence: original MIPS .pdata 40775eec..40775f7b. Semantic name remains unreviewed. */

bool FUN_40775eec(HKEY param_1,LPCWSTR param_2,uint param_3,uint *param_4,void *param_5)

{
  int iVar1;
  uint uVar2;
  uint local_18;
  LPVOID local_14;
  
  uVar2 = 0;
  iVar1 = FUN_407741d8(param_1,param_2,&local_18,&local_14);
  if (iVar1 == 0) {
    uVar2 = local_18 >> 5;
    if (param_3 < local_18 >> 5) {
      uVar2 = param_3;
    }
    memcpy(param_5,local_14,uVar2 << 5);
    CoTaskMemFree(local_14);
  }
  *param_4 = uVar2;
  return uVar2 == 0;
}



/* 40775f7c FUN_40775f7c */

/* Boundary evidence: original MIPS .pdata 40775f7c..40776027. Semantic name remains unreviewed. */

undefined4
FUN_40775f7c(HKEY param_1,uint param_2,uint *param_3,void *param_4,uint param_5,uint *param_6,
            void *param_7)

{
  bool bVar1;
  undefined3 extraout_var;
  int iVar2;
  undefined3 extraout_var_00;
  undefined4 uVar3;
  int iVar4;
  
  iVar4 = 0;
  if (param_2 == 0) {
    *param_3 = 0;
  }
  else {
    bVar1 = FUN_40775eec(param_1,L"InputTypes",param_2,param_3,param_4);
    iVar4 = CONCAT31(extraout_var,bVar1);
  }
  iVar2 = 0;
  if (param_5 == 0) {
    *param_6 = 0;
  }
  else {
    bVar1 = FUN_40775eec(param_1,L"OutputTypes",param_5,param_6,param_7);
    iVar2 = CONCAT31(extraout_var_00,bVar1);
  }
  if ((iVar4 == 0) && (iVar2 == 0)) {
    uVar3 = 0;
  }
  else {
    uVar3 = 1;
  }
  return uVar3;
}



/* 40776028 DMOGetTypes */

/* Boundary evidence: original MIPS .pdata 40776028..407761b3. Semantic name remains unreviewed. */

undefined4
DMOGetTypes(undefined4 *param_1,uint param_2,uint *param_3,void *param_4,uint param_5,uint *param_6,
           void *param_7)

{
  undefined4 uVar1;
  HKEY local_d8;
  HKEY local_d4;
  HKEY local_d0;
  HKEY local_cc;
  wchar_t awStack_c8 [80];
  uint local_28;
  
                    /* 0x6028  3  DMOGetTypes */
  local_28 = DAT_407780a0;
  FUN_40773e98(&local_d8,(HKEY)0x80000000,L"DirectShow\\MediaObjects",&local_d0,0x20019);
  if (local_d0 != (HKEY)0x0) {
    DMOGuidToStrW(awStack_c8,param_1);
    FUN_40773e98(&local_d4,local_d0,awStack_c8,&local_cc,0x20019);
    if (local_cc != (HKEY)0x0) {
      uVar1 = FUN_40775f7c(local_cc,param_2,param_3,param_4,param_5,param_6,param_7);
      if (local_d4 != (HKEY)0x0) {
        RegCloseKey(local_d4);
      }
      if (local_d8 != (HKEY)0x0) {
        RegCloseKey(local_d8);
      }
      FUN_40777488(local_28);
      return uVar1;
    }
    if (local_d4 != (HKEY)0x0) {
      RegCloseKey(local_d4);
    }
  }
  if (local_d8 != (HKEY)0x0) {
    RegCloseKey(local_d8);
  }
  FUN_40777488(local_28);
  return 0x80004005;
}



/* 407761b4 DMOGetName */

/* Boundary evidence: original MIPS .pdata 407761b4..407762f7. Semantic name remains unreviewed. */

undefined1 DMOGetName(undefined4 *param_1,LPBYTE param_2)

{
  bool bVar1;
  HKEY local_c8;
  HKEY local_c4;
  HKEY local_c0;
  HKEY local_bc;
  wchar_t awStack_b8 [80];
  uint local_18;
  
                    /* 0x61b4  2  DMOGetName */
  local_18 = DAT_407780a0;
  FUN_40773e98(&local_c8,(HKEY)0x80000000,L"DirectShow\\MediaObjects",&local_c0,0x20019);
  if (local_c0 != (HKEY)0x0) {
    DMOGuidToStrW(awStack_b8,param_1);
    FUN_40773e98(&local_c4,local_c0,awStack_b8,&local_bc,0x20019);
    if (local_bc != (HKEY)0x0) {
      bVar1 = FUN_40775a0c(local_bc,param_2);
      if (local_c4 != (HKEY)0x0) {
        RegCloseKey(local_c4);
      }
      if (local_c8 != (HKEY)0x0) {
        RegCloseKey(local_c8);
      }
      FUN_40777488(local_18);
      return bVar1;
    }
    if (local_c4 != (HKEY)0x0) {
      RegCloseKey(local_c4);
    }
  }
  if (local_c8 != (HKEY)0x0) {
    RegCloseKey(local_c8);
  }
  FUN_40777488(local_18);
  return 5;
}



/* 407762f8 DMOEnum */

/* Boundary evidence: original MIPS .pdata 407762f8..407765cb. Semantic name remains unreviewed. */

int DMOEnum(int *param_1,uint param_2,uint param_3,int *param_4,uint param_5,int *param_6,
           undefined4 *param_7)

{
  undefined4 *puVar1;
  int iVar2;
  HKEY local_290;
  HKEY local_28c;
  wchar_t awStack_288 [40];
  WCHAR aWStack_238 [260];
  uint local_30;
  
                    /* 0x62f8  1  DMOEnum */
  local_30 = DAT_407780a0;
  if (param_7 == (undefined4 *)0x0) {
    FUN_40777488(DAT_407780a0);
    return -0x7fffbffd;
  }
  if (((param_3 != 0) && (param_4 == (int *)0x0)) || ((param_5 != 0 && (param_6 == (int *)0x0)))) {
    FUN_40777488(DAT_407780a0);
    return -0x7ff8ffa9;
  }
  *param_7 = 0;
  local_290 = (HKEY)0x0;
  RegOpenKeyExW((HKEY)0x80000000,L"DirectShow\\MediaObjects",0,0xf003f,&local_290);
  if (local_290 == (HKEY)0x0) {
    FUN_40777488(local_30);
    return -0x7fffbffb;
  }
  puVar1 = operator_new(0x18);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    puVar1 = FUN_407770d8(puVar1);
  }
  if (puVar1 == (undefined4 *)0x0) {
    if (local_290 != (HKEY)0x0) {
      RegCloseKey(local_290);
    }
    FUN_40777488(local_30);
    return -0x7ff8fff2;
  }
  if ((((*param_1 == 0) && (param_1[1] == 0)) && (param_1[2] == 0)) && (param_1[3] == 0)) {
    iVar2 = FUN_40775d00(local_290,local_290,param_2,param_3,param_4,param_5,param_6,(int)puVar1);
LAB_40776550:
    if (iVar2 < 0) {
      FUN_40776d90(puVar1);
      operator_delete(puVar1);
      goto LAB_40776578;
    }
  }
  else {
    DMOGuidToStrW(awStack_288,param_1);
    wsprintfW(aWStack_238,L"Categories\\%s",awStack_288);
    local_28c = (HKEY)0x0;
    RegOpenKeyExW(local_290,aWStack_238,0,0xf003f,&local_28c);
    if (local_28c != (HKEY)0x0) {
      iVar2 = FUN_40775d00(local_290,local_28c,param_2,param_3,param_4,param_5,param_6,(int)puVar1);
      if (local_28c != (HKEY)0x0) {
        RegCloseKey(local_28c);
      }
      goto LAB_40776550;
    }
  }
  *param_7 = puVar1;
  iVar2 = 0;
LAB_40776578:
  if (local_290 != (HKEY)0x0) {
    RegCloseKey(local_290);
  }
  FUN_40777488(local_30);
  return iVar2;
}



/* 407765cc DMOGuidToStrA */

/* Boundary evidence: original MIPS .pdata 407765cc..4077663f. Semantic name remains unreviewed. */

void DMOGuidToStrA(char *param_1,undefined4 *param_2)

{
                    /* 0x65cc  4  DMOGuidToStrA */
  sprintf(param_1,"%08x-%04x-%04x-%02x%02x-%02x%02x%02x%02x%02x%02x",*param_2,
          (uint)*(ushort *)(param_2 + 1),(uint)*(ushort *)((int)param_2 + 6),
          (uint)*(byte *)(param_2 + 2),(uint)*(byte *)((int)param_2 + 9),
          (uint)*(byte *)((int)param_2 + 10),(uint)*(byte *)((int)param_2 + 0xb),
          (uint)*(byte *)(param_2 + 3),(uint)*(byte *)((int)param_2 + 0xd),
          (uint)*(byte *)((int)param_2 + 0xe),(uint)*(byte *)((int)param_2 + 0xf));
  return;
}



/* 40776640 DMOGuidToStrW */

/* Boundary evidence: original MIPS .pdata 40776640..407766b3. Semantic name remains unreviewed. */

void DMOGuidToStrW(wchar_t *param_1,undefined4 *param_2)

{
                    /* 0x6640  5  DMOGuidToStrW */
  swprintf(param_1,0x407714c0,(wchar_t *)*param_2,(uint)*(ushort *)(param_2 + 1),
           (uint)*(ushort *)((int)param_2 + 6),(uint)*(byte *)(param_2 + 2),
           (uint)*(byte *)((int)param_2 + 9),(uint)*(byte *)((int)param_2 + 10),
           (uint)*(byte *)((int)param_2 + 0xb),(uint)*(byte *)(param_2 + 3),
           (uint)*(byte *)((int)param_2 + 0xd),(uint)*(byte *)((int)param_2 + 0xe),
           (uint)*(byte *)((int)param_2 + 0xf));
  return;
}



/* 407766b4 DMOStrToGuidA */

/* Boundary evidence: original MIPS .pdata 407766b4..4077676f. Semantic name remains unreviewed. */

undefined4 DMOStrToGuidA(char *param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 *puVar3;
  uint uVar4;
  undefined4 *puVar5;
  undefined4 local_28;
  undefined1 auStack_24 [4];
  undefined1 auStack_20 [4];
  undefined1 auStack_1c [4];
  undefined1 auStack_18 [4];
  undefined1 auStack_14 [4];
  undefined1 auStack_10 [4];
  undefined1 auStack_c [4];
  
                    /* 0x66b4  8  DMOStrToGuidA */
  iVar1 = sscanf(param_1,"%08x-%04hx-%04hx-%02x%02x-%02x%02x%02x%02x%02x%02x",param_2,param_2 + 4,
                 param_2 + 6,&local_28,auStack_24,auStack_20,auStack_1c,auStack_18,auStack_14,
                 auStack_10,auStack_c);
  if (iVar1 == 0xb) {
    uVar4 = 0;
    puVar5 = &local_28;
    do {
      puVar3 = (undefined1 *)(param_2 + 8 + uVar4);
      uVar4 = uVar4 + 1;
      *puVar3 = (char)*puVar5;
      puVar5 = puVar5 + 1;
    } while (uVar4 < 8);
    uVar2 = 1;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}



/* 40776770 DMOStrToGuidW */

/* Boundary evidence: original MIPS .pdata 40776770..407767eb. Semantic name remains unreviewed. */

undefined4 DMOStrToGuidW(LPCWSTR param_1,int param_2)

{
  undefined4 uVar1;
  CHAR aCStack_60 [80];
  uint local_10;
  
                    /* 0x6770  9  DMOStrToGuidW */
  local_10 = DAT_407780a0;
  WideCharToMultiByte(0,0,param_1,-1,aCStack_60,0x50,(LPCSTR)0x0,(LPBOOL)0x0);
  uVar1 = DMOStrToGuidA(aCStack_60,param_2);
  FUN_40777488(local_10);
  return uVar1;
}



/* 407767ec MoInitMediaType */

/* Boundary evidence: original MIPS .pdata 407767ec..40776857. Semantic name remains unreviewed. */

undefined4 MoInitMediaType(int param_1,SIZE_T param_2)

{
  undefined4 uVar1;
  LPVOID pvVar2;
  
                    /* 0x67ec  19  MoInitMediaType */
  if (param_1 == 0) {
    uVar1 = 0x80004003;
  }
  else {
    *(undefined4 *)(param_1 + 0x3c) = 0;
    if (param_2 == 0) {
      *(undefined4 *)(param_1 + 0x44) = 0;
    }
    else {
      pvVar2 = CoTaskMemAlloc(param_2);
      *(LPVOID *)(param_1 + 0x44) = pvVar2;
      if (pvVar2 == (LPVOID)0x0) {
        return 0x8007000e;
      }
    }
    *(SIZE_T *)(param_1 + 0x40) = param_2;
    uVar1 = 0;
  }
  return uVar1;
}



/* 40776858 MoFreeMediaType */

/* Boundary evidence: original MIPS .pdata 40776858..407768c7. Semantic name remains unreviewed. */

undefined4 MoFreeMediaType(int param_1)

{
  undefined4 uVar1;
  
                    /* 0x6858  18  MoFreeMediaType */
  if (param_1 == 0) {
    uVar1 = 0x80004003;
  }
  else {
    if (*(int **)(param_1 + 0x3c) != (int *)0x0) {
      (**(code **)(**(int **)(param_1 + 0x3c) + 8))();
      *(undefined4 *)(param_1 + 0x3c) = 0;
    }
    if (*(LPVOID *)(param_1 + 0x44) != (LPVOID)0x0) {
      CoTaskMemFree(*(LPVOID *)(param_1 + 0x44));
      *(undefined4 *)(param_1 + 0x44) = 0;
    }
    uVar1 = 0;
  }
  return uVar1;
}



/* 407768c8 FUN_407768c8 */

/* Boundary evidence: original MIPS .pdata 407768c8..407769a7. Semantic name remains unreviewed. */

void FUN_407768c8(undefined4 *param_1,undefined4 *param_2)

{
  if (param_1[0x10] != 0) {
    memcpy((void *)param_1[0x11],(void *)param_2[0x11],param_1[0x10]);
  }
  if ((int *)param_2[0xf] != (int *)0x0) {
    (**(code **)(*(int *)param_2[0xf] + 4))();
    param_1[0xf] = param_2[0xf];
  }
  *param_1 = *param_2;
  param_1[1] = param_2[1];
  param_1[2] = param_2[2];
  param_1[3] = param_2[3];
  param_1[4] = param_2[4];
  param_1[5] = param_2[5];
  param_1[6] = param_2[6];
  param_1[7] = param_2[7];
  param_1[8] = param_2[8];
  param_1[9] = param_2[9];
  param_1[10] = param_2[10];
  param_1[0xb] = param_2[0xb];
  param_1[0xc] = param_2[0xc];
  param_1[0xd] = param_2[0xd];
  param_1[0xe] = param_2[0xe];
  return;
}



/* 407769a8 MoCopyMediaType */

/* Boundary evidence: original MIPS .pdata 407769a8..40776a23. Semantic name remains unreviewed. */

int MoCopyMediaType(undefined4 *param_1,undefined4 *param_2)

{
  int iVar1;
  SIZE_T SVar2;
  
                    /* 0x69a8  14  MoCopyMediaType */
  if ((param_1 == (undefined4 *)0x0) || (param_2 == (undefined4 *)0x0)) {
    iVar1 = -0x7fffbffd;
  }
  else {
    if (param_2[0x11] == 0) {
      SVar2 = 0;
    }
    else {
      SVar2 = param_2[0x10];
    }
    iVar1 = MoInitMediaType((int)param_1,SVar2);
    if (-1 < iVar1) {
      FUN_407768c8(param_1,param_2);
      iVar1 = 0;
    }
  }
  return iVar1;
}



/* 40776a24 MoCreateMediaType */

/* Boundary evidence: original MIPS .pdata 40776a24..40776aa3. Semantic name remains unreviewed. */

int MoCreateMediaType(undefined4 *param_1,SIZE_T param_2)

{
  LPVOID pvVar1;
  int iVar2;
  
                    /* 0x6a24  15  MoCreateMediaType */
  if (param_1 == (undefined4 *)0x0) {
    iVar2 = -0x7fffbffd;
  }
  else {
    pvVar1 = CoTaskMemAlloc(0x48);
    *param_1 = pvVar1;
    if (pvVar1 == (LPVOID)0x0) {
      iVar2 = -0x7ff8fff2;
    }
    else {
      iVar2 = MoInitMediaType((int)pvVar1,param_2);
      if (iVar2 < 0) {
        CoTaskMemFree((LPVOID)*param_1);
        *param_1 = 0;
      }
    }
  }
  return iVar2;
}



/* 40776aa4 MoDeleteMediaType */

/* Boundary evidence: original MIPS .pdata 40776aa4..40776af7. Semantic name remains unreviewed. */

undefined4 MoDeleteMediaType(LPVOID param_1)

{
  undefined4 uVar1;
  
                    /* 0x6aa4  16  MoDeleteMediaType */
  if (param_1 == (LPVOID)0x0) {
    uVar1 = 0x80004003;
  }
  else {
    uVar1 = MoFreeMediaType((int)param_1);
    CoTaskMemFree(param_1);
  }
  return uVar1;
}



/* 40776af8 MoDuplicateMediaType */

/* Boundary evidence: original MIPS .pdata 40776af8..40776b73. Semantic name remains unreviewed. */

int MoDuplicateMediaType(undefined4 *param_1,undefined4 *param_2)

{
  int iVar1;
  SIZE_T SVar2;
  
                    /* 0x6af8  17  MoDuplicateMediaType */
  if ((param_1 == (undefined4 *)0x0) || (param_2 == (undefined4 *)0x0)) {
    iVar1 = -0x7fffbffd;
  }
  else {
    if (param_2[0x11] == 0) {
      SVar2 = 0;
    }
    else {
      SVar2 = param_2[0x10];
    }
    iVar1 = MoCreateMediaType(param_1,SVar2);
    if (-1 < iVar1) {
      FUN_407768c8((undefined4 *)*param_1,param_2);
      iVar1 = 0;
    }
  }
  return iVar1;
}



/* 40776b74 FUN_40776b74 */

/* Boundary evidence: original MIPS .pdata 40776b74..40776c5f. Semantic name remains unreviewed. */

undefined4 FUN_40776b74(int *param_1,int *param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  
  if (param_3 == (undefined4 *)0x0) {
    uVar1 = 0x80004003;
  }
  else if (((((*param_2 == 0) && (param_2[1] == 0)) && (param_2[2] == 0xc0)) &&
           (param_2[3] == 0x46000000)) ||
          (((*param_2 == 0x2c3cd98a && (param_2[1] == 0x4a532bfa)) &&
           ((param_2[2] == 0x4952279c && (param_2[3] == 0xfba64ba)))))) {
    (**(code **)(*param_1 + 4))(param_1);
    uVar1 = 0;
    *param_3 = param_1;
  }
  else {
    uVar1 = 0x80004002;
  }
  return uVar1;
}



/* 40776c60 FUN_40776c60 */

/* Boundary evidence: original MIPS .pdata 40776c60..40776c7b. Semantic name remains unreviewed. */

void FUN_40776c60(int param_1)

{
  InterlockedIncrement((LONG *)(param_1 + 4));
  return;
}



/* 40776c94 FUN_40776c94 */

/* Boundary evidence: original MIPS .pdata 40776c94..40776d8f. Semantic name remains unreviewed. */

undefined4 FUN_40776c94(int *param_1,undefined4 *param_2)

{
  void *pvVar1;
  undefined4 *puVar2;
  uint uVar3;
  
  if ((void *)*param_1 == (void *)0x0) {
    param_1[1] = 0x14;
    param_1[2] = 0;
    pvVar1 = malloc(400);
    *param_1 = (int)pvVar1;
    if (pvVar1 == (void *)0x0) {
      return 0x8007000e;
    }
  }
  else if (param_1[2] == param_1[1]) {
    uVar3 = param_1[1] + 0x14;
    if ((int)((ulonglong)uVar3 * 0x14 >> 0x20) != 0) {
      return 0x8007000e;
    }
    pvVar1 = realloc((void *)*param_1,uVar3 * 0x14);
    if (pvVar1 == (void *)0x0) {
      return 0x8007000e;
    }
    param_1[1] = uVar3;
    *param_1 = (int)pvVar1;
  }
  puVar2 = (undefined4 *)(param_1[2] * 0x14 + *param_1);
  *puVar2 = *param_2;
  puVar2[1] = param_2[1];
  puVar2[2] = param_2[2];
  puVar2[3] = param_2[3];
  puVar2[4] = param_2[4];
  param_1[2] = param_1[2] + 1;
  return 0;
}



/* 40776d90 FUN_40776d90 */

/* Boundary evidence: original MIPS .pdata 40776d90..40776e1b. Semantic name remains unreviewed. */

void FUN_40776d90(undefined4 *param_1)

{
  uint uVar1;
  int iVar2;
  
  *param_1 = &PTR_FUN_40771558;
  uVar1 = 0;
  for (iVar2 = 0; (uVar1 < (uint)param_1[4] && (param_1[2] + iVar2 != 0)); iVar2 = iVar2 + 0x14) {
    operator_delete(*(void **)(param_1[2] + iVar2 + 0x10));
    uVar1 = uVar1 + 1;
  }
  if ((void *)param_1[2] != (void *)0x0) {
    free((void *)param_1[2]);
  }
  return;
}



/* 40776e1c FUN_40776e1c */

/* Boundary evidence: original MIPS .pdata 40776e1c..40776fd7. Semantic name remains unreviewed. */

undefined4
FUN_40776e1c(int param_1,uint param_2,undefined4 *param_3,undefined4 *param_4,uint *param_5)

{
  size_t sVar1;
  wchar_t *_Dest;
  uint uVar2;
  undefined4 *puVar3;
  uint uVar4;
  undefined4 uVar5;
  wchar_t *_Str;
  undefined4 *puVar6;
  
  if (param_3 == (undefined4 *)0x0) {
    uVar5 = 0x80004003;
  }
  else {
    uVar5 = 1;
    if ((param_2 == 1) || (param_5 != (uint *)0x0)) {
      uVar4 = 0;
      puVar6 = param_4;
      if (param_2 != 0) {
        do {
          uVar2 = *(int *)(param_1 + 0x14) + uVar4;
          if ((*(uint *)(param_1 + 0x10) <= uVar2) ||
             (puVar3 = (undefined4 *)(uVar2 * 0x14 + *(int *)(param_1 + 8)),
             puVar3 == (undefined4 *)0x0)) break;
          *param_3 = *puVar3;
          param_3[1] = puVar3[1];
          param_3[2] = puVar3[2];
          param_3[3] = puVar3[3];
          _Str = (wchar_t *)puVar3[4];
          if ((wchar_t *)puVar3[4] == (wchar_t *)0x0) {
            _Str = L"";
          }
          if (param_4 != (undefined4 *)0x0) {
            sVar1 = wcslen(_Str);
            _Dest = CoTaskMemAlloc((sVar1 + 1) * 2);
            *puVar6 = _Dest;
            if (_Dest == (wchar_t *)0x0) {
              for (; uVar4 != 0; uVar4 = uVar4 - 1) {
                CoTaskMemFree((LPVOID)*param_4);
                *param_4 = 0;
                param_4 = param_4 + 1;
              }
              return 0x8007000e;
            }
            wcscpy(_Dest,_Str);
          }
          uVar4 = uVar4 + 1;
          param_3 = param_3 + 4;
          puVar6 = puVar6 + 1;
        } while (uVar4 < param_2);
      }
      if (param_5 != (uint *)0x0) {
        *param_5 = uVar4;
      }
      *(uint *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + uVar4;
      if (uVar4 == param_2) {
        uVar5 = 0;
      }
    }
    else {
      uVar5 = 0x80070057;
    }
  }
  return uVar5;
}



/* 40777000 FUN_40777000 */

/* Boundary evidence: original MIPS .pdata 40777000..407770d7. Semantic name remains unreviewed. */

void FUN_40777000(int param_1,undefined4 *param_2,wchar_t *param_3)

{
  size_t sVar1;
  uint uVar2;
  wchar_t *_Dest;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  wchar_t *local_20;
  uint local_1c;
  
  local_1c = DAT_407780a0;
  _Dest = (wchar_t *)0x0;
  if (param_3 != (wchar_t *)0x0) {
    sVar1 = wcslen(param_3);
    if (sVar1 + 1 < 0x80000000) {
      uVar2 = (sVar1 + 1) * 2;
    }
    else {
      uVar2 = 0xffffffff;
    }
    _Dest = operator_new(uVar2);
    if (_Dest == (wchar_t *)0x0) goto LAB_407770b4;
    wcscpy(_Dest,param_3);
  }
  local_30 = *param_2;
  local_2c = param_2[1];
  local_28 = param_2[2];
  local_24 = param_2[3];
  local_20 = _Dest;
  FUN_40776c94((int *)(param_1 + 8),&local_30);
LAB_407770b4:
  FUN_40777488(local_1c);
  return;
}



/* 407770d8 FUN_407770d8 */

undefined4 * FUN_407770d8(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_40771558;
  param_1[2] = 0;
  param_1[1] = 1;
  param_1[5] = 0;
  return param_1;
}



/* 407770fc FUN_407770fc */

/* Boundary evidence: original MIPS .pdata 407770fc..40777153. Semantic name remains unreviewed. */

LONG FUN_407770fc(undefined4 *param_1)

{
  LONG LVar1;
  
  LVar1 = InterlockedDecrement(param_1 + 1);
  if ((LVar1 == 0) && (param_1 != (undefined4 *)0x0)) {
    FUN_40776d90(param_1);
    operator_delete(param_1);
  }
  return LVar1;
}



/* 407771d4 FUN_407771d4 */

/* Boundary evidence: original MIPS .pdata 407771d4..4077730f. Semantic name remains unreviewed. */

int FUN_407771d4(HMODULE param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 1;
  if (param_2 == 1) {
    if (DAT_407780c4 != (code *)0x0) {
      iVar2 = (*DAT_407780c4)(param_1,1,param_3);
    }
    iVar1 = 0;
    if (iVar2 == 0) goto LAB_40777284;
    FUN_40777668();
  }
  iVar1 = 0;
  if (iVar2 != 0) {
    iVar1 = FUN_40773878(param_1,param_2);
  }
LAB_40777284:
  if (((param_2 == 0) && (FUN_407775f0(), iVar1 != 0)) && (DAT_407780c4 != (code *)0x0)) {
    iVar1 = (*DAT_407780c4)(param_1,0,param_3);
  }
  return iVar1;
}



/* 40777310 FUN_40777310 */

/* Boundary evidence: original MIPS .pdata 40777310..4077733b. Semantic name remains unreviewed. */

void FUN_40777310(_EXCEPTION_POINTERS *param_1)

{
  _XcptFilter(param_1->ExceptionRecord->ExceptionCode,param_1);
  return;
}



/* 4077733c entry */

/* Boundary evidence: original MIPS .pdata 4077733c..40777393. Semantic name remains unreviewed. */

void entry(HMODULE param_1,int param_2,undefined4 param_3)

{
  if (param_2 == 1) {
    FUN_40777394();
  }
  FUN_407771d4(param_1,param_2,param_3);
  return;
}



/* 40777394 FUN_40777394 */

/* Boundary evidence: original MIPS .pdata 40777394..40777407. Semantic name remains unreviewed. */

void FUN_40777394(void)

{
  uint uVar1;
  
  if ((DAT_407780a0 == 0) || (DAT_407780a0 == 0xb064)) {
    uVar1 = __security_gen_cookie2();
    DAT_407780a0 = uVar1 >> 0x10 ^ uVar1 & 0xffff;
    if (DAT_407780a0 == 0) {
      DAT_407780a0 = 0xb064;
    }
  }
  DAT_407780a4 = ~DAT_407780a0;
  return;
}



/* 40777408 FUN_40777408 */

/* Boundary evidence: original MIPS .pdata 40777408..4077745b. Semantic name remains unreviewed. */

void FUN_40777408(int param_1,undefined4 param_2,uint *param_3)

{
  if ((*param_3 & 1) != 0) {
    param_1 = ((-param_3[2] & param_3[1] + param_1) - (param_3[1] + param_1)) + param_1;
  }
  FUN_40777488(*(uint *)(param_1 + (*param_3 & 0xfffffffc)));
  return;
}



/* 4077745c FUN_4077745c */

/* Boundary evidence: original MIPS .pdata 4077745c..40777487. Semantic name remains unreviewed. */

undefined4 FUN_4077745c(undefined4 param_1,int param_2,undefined4 param_3,int param_4)

{
  FUN_40777408(param_2,param_4,*(uint **)(*(int *)(param_4 + 4) + 0xc));
  return 1;
}



/* 40777488 FUN_40777488 */

/* Boundary evidence: original MIPS .pdata 40777488..407774cf. Semantic name remains unreviewed. */

void FUN_40777488(uint param_1)

{
  if ((param_1 == DAT_407780a0) && (param_1 >> 0x10 == 0)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __report_gsfailure();
}



/* 407774d0 FUN_407774d0 */

/* Boundary evidence: original MIPS .pdata 407774d0..407775ef. Semantic name remains unreviewed. */

void FUN_407774d0(UINT param_1,int param_2,int param_3)

{
  LPCRITICAL_SECTION lpCriticalSection;
  undefined4 *_Memory;
  
  DAT_407780b4 = (undefined1)param_3;
  if (param_2 == 0) {
    _Memory = DAT_407780bc;
    if (DAT_407780bc != (undefined4 *)0x0) {
      while (DAT_407780b8 = DAT_407780b8 + -1, _Memory <= DAT_407780b8) {
        if ((code *)*DAT_407780b8 != (code *)0x0) {
          (*(code *)*DAT_407780b8)();
          _Memory = DAT_407780bc;
        }
      }
      free(_Memory);
      DAT_407780b8 = (undefined4 *)0x0;
      DAT_407780bc = (undefined4 *)0x0;
    }
    FUN_40777614((undefined4 *)&DAT_40771010,(undefined4 *)&DAT_40771014);
  }
  FUN_40777614((undefined4 *)&DAT_40771018,(undefined4 *)&DAT_4077101c);
  if (param_3 == 0) {
    TerminateProcess((HANDLE)0x42,param_1);
  }
  else {
    lpCriticalSection = (LPCRITICAL_SECTION)InterlockedExchange((LONG *)&DAT_407780c0,0);
    if (lpCriticalSection != (LPCRITICAL_SECTION)0x0) {
      DeleteCriticalSection(lpCriticalSection);
      free(lpCriticalSection);
    }
  }
  return;
}



/* 407775f0 FUN_407775f0 */

/* Boundary evidence: original MIPS .pdata 407775f0..40777613. Semantic name remains unreviewed. */

void FUN_407775f0(void)

{
  FUN_407774d0(0,0,1);
  return;
}



/* 40777614 FUN_40777614 */

/* Boundary evidence: original MIPS .pdata 40777614..40777667. Semantic name remains unreviewed. */

void FUN_40777614(undefined4 *param_1,undefined4 *param_2)

{
  for (; param_1 < param_2; param_1 = param_1 + 1) {
    if ((code *)*param_1 != (code *)0x0) {
      (*(code *)*param_1)();
    }
  }
  return;
}



/* 40777668 FUN_40777668 */

/* Boundary evidence: original MIPS .pdata 40777668..407776a3. Semantic name remains unreviewed. */

void FUN_40777668(void)

{
  FUN_40777614((undefined4 *)&DAT_40771008,(undefined4 *)&DAT_4077100c);
  FUN_40777614((undefined4 *)&DAT_40771000,(undefined4 *)&DAT_40771004);
  return;
}


