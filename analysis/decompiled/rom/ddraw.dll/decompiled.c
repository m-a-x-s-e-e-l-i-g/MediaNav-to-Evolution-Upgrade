/* Automatic Ghidra pseudocode. Not original source; not runtime-verified. */

/* 408313f0 FUN_408313f0 */

/* Boundary evidence: original MIPS .pdata 408313f0..408314ab. Semantic name remains unreviewed. */

undefined4 FUN_408313f0(HMODULE param_1,int param_2)

{
  int iVar1;
  
  if (param_2 == 0) {
    if (DAT_40838510 != (void *)0x0) {
      operator_delete(DAT_40838510);
    }
    DAT_40838510 = (void *)0x0;
    DeleteCriticalSection((LPCRITICAL_SECTION)&DAT_408384f4);
  }
  else if (param_2 == 1) {
    InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_408384f4);
    DisableThreadLibraryCalls(param_1);
    DAT_40838510 = operator_new(0x138);
    if ((DAT_40838510 != (void *)0x0) && (iVar1 = FUN_40831ef4((int)DAT_40838510), iVar1 == 0)) {
      if (DAT_40838510 != (void *)0x0) {
        operator_delete(DAT_40838510);
      }
      DAT_40838510 = (void *)0x0;
    }
  }
  return 1;
}



/* 408314ac FUN_408314ac */

/* Boundary evidence: original MIPS .pdata 408314ac..40831507. Semantic name remains unreviewed. */

undefined4 * FUN_408314ac(undefined4 *param_1)

{
  HANDLE hHandle;
  
  hHandle = CreateMutexW((LPSECURITY_ATTRIBUTES)0x0,0,L"_DDrawClientMutex_");
  *param_1 = hHandle;
  if (hHandle != (HANDLE)0x0) {
    WaitForSingleObject(hHandle,0xffffffff);
  }
  return param_1;
}



/* 40831508 FUN_40831508 */

/* Boundary evidence: original MIPS .pdata 40831508..40831553. Semantic name remains unreviewed. */

void FUN_40831508(undefined4 *param_1)

{
  if ((HANDLE)*param_1 != (HANDLE)0x0) {
    ReleaseMutex((HANDLE)*param_1);
    CloseHandle((HANDLE)*param_1);
  }
  return;
}



/* 40831554 FUN_40831554 */

/* Boundary evidence: original MIPS .pdata 40831554..408315d3. Semantic name remains unreviewed. */

void FUN_40831554(undefined *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,undefined4 *param_7)

{
  undefined4 uVar1;
  
  uVar1 = (*(code *)param_1)(param_2,param_3,param_4,param_5,param_6);
  *param_7 = uVar1;
  return;
}



/* 408315d4 FUN_408315d4 */

/* Boundary evidence: original MIPS .pdata 408315d4..408315df. Semantic name remains unreviewed. */

undefined4 FUN_408315d4(void)

{
  return 1;
}



/* 408315e0 FUN_408315e0 */

/* Boundary evidence: original MIPS .pdata 408315e0..4083165f. Semantic name remains unreviewed. */

void FUN_408315e0(void *param_1,void *param_2,uint *param_3)

{
  int iVar1;
  
  iVar1 = memcmp(param_1,param_2,0x10);
  *param_3 = (uint)(iVar1 == 0);
  return;
}



/* 40831660 FUN_40831660 */

/* Boundary evidence: original MIPS .pdata 40831660..4083166b. Semantic name remains unreviewed. */

undefined4 FUN_40831660(void)

{
  return 1;
}



/* 4083166c DirectDrawCreateClipper */

/* Boundary evidence: original MIPS .pdata 4083166c..408316ff. Semantic name remains unreviewed. */

int DirectDrawCreateClipper(int param_1,undefined4 *param_2,int param_3)

{
  int iVar1;
  
                    /* 0x166c  2  DirectDrawCreateClipper */
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_408384f4);
  if (DAT_40838510 == 0) {
    iVar1 = -0x7fffbffb;
  }
  else {
    iVar1 = FUN_4083261c(0xffffffff,param_1,param_2,param_3,(int *)0x0);
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_408384f4);
  return iVar1;
}



/* 4083170c FUN_4083170c */

/* Boundary evidence: original MIPS .pdata 4083170c..408317a3. Semantic name remains unreviewed. */

undefined4 FUN_4083170c(void)

{
  int iVar1;
  LSTATUS LVar2;
  undefined4 uVar3;
  
  if ((DAT_4083850c == 0) &&
     ((iVar1 = (**(code **)(DAT_40838510 + 8))(), iVar1 == 0 ||
      (LVar2 = RegOpenKeyExW((HKEY)0x80000002,L"\\System\\DDraw\\DeviceEnum",0,0,
                             (PHKEY)&DAT_40838508), LVar2 != 0)))) {
    uVar3 = 0;
  }
  else {
    DAT_4083850c = DAT_4083850c + 1;
    uVar3 = DAT_40838508;
  }
  return uVar3;
}



/* 408317a4 FUN_408317a4 */

/* Boundary evidence: original MIPS .pdata 408317a4..408317ef. Semantic name remains unreviewed. */

void FUN_408317a4(undefined4 *param_1,undefined4 param_2)

{
  *param_1 = param_2;
  return;
}



/* 408317f0 FUN_408317f0 */

/* Boundary evidence: original MIPS .pdata 408317f0..408317fb. Semantic name remains unreviewed. */

undefined4 FUN_408317f0(void)

{
  return 1;
}



/* 408317fc DirectDrawCreate */

/* Boundary evidence: original MIPS .pdata 408317fc..40831b6f. Semantic name remains unreviewed. */

int DirectDrawCreate(void *param_1,undefined4 *param_2,int param_3)

{
  HKEY hKey;
  LSTATUS LVar1;
  LSTATUS LVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  DWORD dwIndex;
  HKEY local_260;
  int local_25c [5];
  int local_248 [2];
  BYTE aBStack_240 [16];
  WCHAR aWStack_230 [256];
  uint local_30;
  
                    /* 0x17fc  1  DirectDrawCreate */
  local_30 = DAT_408384ec;
  FUN_408314ac(local_25c + 4);
  if (DAT_40838510 != 0) {
    if ((param_2 == (undefined4 *)0x0) || (param_3 != 0)) {
      iVar5 = -0x7ff8ffa9;
      goto LAB_40831b30;
    }
    hKey = (HKEY)FUN_4083170c();
    if (hKey != (HKEY)0x0) {
      local_25c[3] = 0x100;
      local_25c[0] = -1;
      dwIndex = 0;
      piVar6 = (int *)0x0;
      local_25c[2] = 0;
      do {
        local_260 = (HKEY)0x0;
        LVar1 = RegEnumKeyExW(hKey,dwIndex,aWStack_230,(LPDWORD)(local_25c + 3),(LPDWORD)0x0,
                              (LPWSTR)0x0,(LPDWORD)0x0,(PFILETIME)0x0);
        if (LVar1 != 0) goto LAB_40831a0c;
        LVar2 = RegOpenKeyExW(hKey,aWStack_230,0,0,&local_260);
        if (LVar2 != 0) {
LAB_40831a6c:
          iVar5 = -0x7fffbffb;
          goto LAB_40831a3c;
        }
        if (param_1 == (void *)0x0) {
          local_25c[1] = 4;
          LVar2 = RegQueryValueExW(local_260,L"DesktopFlags",(LPDWORD)0x0,(LPDWORD)0x0,
                                   (LPBYTE)local_248,(LPDWORD)(local_25c + 1));
          if (LVar2 != 0) goto LAB_40831a6c;
          if (local_248[0] == 0) goto LAB_4083198c;
        }
        else {
          local_25c[1] = 0x10;
          LVar2 = RegQueryValueExW(local_260,L"GUID",(LPDWORD)0x0,(LPDWORD)0x0,aBStack_240,
                                   (LPDWORD)(local_25c + 1));
          if (LVar2 != 0) goto LAB_40831a6c;
          iVar5 = FUN_408315e0(aBStack_240,param_1,(uint *)(local_25c + 2));
          if (iVar5 == 0) break;
          if (local_25c[2] != 0) {
LAB_4083198c:
            iVar5 = (**(code **)(DAT_40838510 + 0xc))(aWStack_230,local_25c);
            if (-1 < iVar5) {
              if (local_25c[0] == -1) {
                iVar5 = -0x7fffbffb;
              }
              else {
                puVar3 = operator_new(0x22c);
                if (puVar3 == (undefined4 *)0x0) {
                  piVar6 = (int *)0x0;
                }
                else {
                  piVar6 = FUN_408343c4(puVar3,local_25c[0],aWStack_230);
                }
                if (piVar6 == (int *)0x0) {
                  iVar5 = -0x7ff8fff2;
                }
                else {
                  iVar4 = FUN_408317a4(param_2,piVar6);
                  if (iVar4 == 0) {
                    iVar5 = -0x7ff8ffa9;
                  }
                }
              }
            }
            goto LAB_40831a3c;
          }
        }
LAB_40831a0c:
        RegCloseKey(local_260);
        dwIndex = dwIndex + 1;
        local_260 = (HKEY)0x0;
      } while (LVar1 == 0);
      iVar5 = -0x7ff8ffa9;
LAB_40831a3c:
      DAT_4083850c = DAT_4083850c + -1;
      if (DAT_4083850c == 0) {
        RegCloseKey(DAT_40838508);
        DAT_40838508 = (HKEY)0x0;
      }
      if (local_260 != (HKEY)0x0) {
        RegCloseKey(local_260);
      }
      if (iVar5 < 0) {
        if (local_25c[0] != -1) {
          (**(code **)(DAT_40838510 + 0x10))();
        }
        if (piVar6 != (int *)0x0) {
          (**(code **)(*piVar6 + 8))(piVar6);
        }
      }
      goto LAB_40831b30;
    }
  }
  iVar5 = -0x7fffbffb;
LAB_40831b30:
  FUN_40831508(local_25c + 4);
  FUN_4083752c(local_30);
  return iVar5;
}



/* 40831b70 DirectDrawEnumerateEx */

/* Boundary evidence: original MIPS .pdata 40831b70..40831ef3. Semantic name remains unreviewed. */

undefined4 DirectDrawEnumerateEx(undefined *param_1,undefined4 param_2,uint param_3)

{
  HKEY hKey;
  LSTATUS LVar1;
  LSTATUS LVar2;
  HDC hdc;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  wchar_t *lpValueName;
  DWORD dwIndex;
  HKEY local_460;
  DWORD local_45c;
  wchar_t *local_458;
  undefined4 local_454;
  int local_450 [3];
  undefined4 uStack_444;
  BYTE aBStack_440 [16];
  WCHAR aWStack_430 [256];
  BYTE aBStack_230 [512];
  uint local_30;
  
                    /* 0x1b70  3  DirectDrawEnumerateEx */
  local_30 = DAT_408384ec;
  FUN_408314ac(&uStack_444);
  if (DAT_40838510 != 0) {
    if (((param_3 & 0xfffffffc) != 0) || (param_1 == (undefined *)0x0)) {
      uVar5 = 0x80070057;
      goto LAB_40831eb4;
    }
    hKey = (HKEY)FUN_4083170c();
    if (hKey != (HKEY)0x0) {
      local_450[1] = 0x100;
      lpValueName = L"Description";
      dwIndex = 0;
      local_460 = (HKEY)0x0;
      local_450[0] = 0;
      uVar5 = 0;
      local_458 = L"Description";
      do {
        LVar1 = RegEnumKeyExW(hKey,dwIndex,aWStack_430,(LPDWORD)(local_450 + 1),(LPDWORD)0x0,
                              (LPWSTR)0x0,(LPDWORD)0x0,(PFILETIME)0x0);
        if (LVar1 == 0) {
          LVar2 = RegOpenKeyExW(hKey,aWStack_430,0,0,&local_460);
          if (LVar2 != 0) goto LAB_40831e60;
          local_45c = 0x10;
          LVar2 = RegQueryValueExW(local_460,L"GUID",(LPDWORD)0x0,(LPDWORD)0x0,aBStack_440,
                                   &local_45c);
          if (LVar2 != 0) goto LAB_40831e60;
          local_45c = 4;
          LVar2 = RegQueryValueExW(local_460,L"DesktopFlags",(LPDWORD)0x0,(LPDWORD)0x0,
                                   (LPBYTE)(local_450 + 2),&local_45c);
          if (LVar2 != 0) goto LAB_40831e60;
          local_45c = 0x200;
          LVar2 = RegQueryValueExW(local_460,lpValueName,(LPDWORD)0x0,(LPDWORD)0x0,aBStack_230,
                                   &local_45c);
          if (LVar2 != 0) goto LAB_40831e60;
          RegCloseKey(local_460);
          local_460 = (HKEY)0x0;
          hdc = CreateDCW(aWStack_430,(LPCWSTR)0x0,(LPCWSTR)0x0,(DEVMODEW *)0x0);
          if (hdc == (HDC)0x0) {
            uVar4 = 0;
          }
          else {
            local_454 = 0;
            EnumDisplayMonitors(hdc,(LPCRECT)0x0,(MONITORENUMPROC)&LAB_40831700,(LPARAM)&local_454);
            DeleteDC(hdc);
            uVar4 = local_454;
          }
          if (((local_450[2] == 0) || ((local_450[2] == 1 && ((param_3 & 1) != 0)))) ||
             ((lpValueName = local_458, local_450[2] == 2 && ((param_3 & 2) != 0)))) {
            iVar3 = FUN_40831554(param_1,aBStack_440,aBStack_230,aWStack_430,param_2,uVar4,local_450
                                );
            if (iVar3 == 0) goto LAB_40831e60;
            lpValueName = local_458;
            if (local_450[0] == 0) {
              LVar1 = 0x103;
              break;
            }
          }
        }
        dwIndex = dwIndex + 1;
      } while (LVar1 == 0);
      if (LVar1 != 0x103) {
LAB_40831e60:
        uVar5 = 0x80004005;
      }
      DAT_4083850c = DAT_4083850c + -1;
      if (DAT_4083850c == 0) {
        RegCloseKey(DAT_40838508);
        DAT_40838508 = (HKEY)0x0;
      }
      if (local_460 != (HKEY)0x0) {
        RegCloseKey(local_460);
      }
      goto LAB_40831eb4;
    }
  }
  uVar5 = 0x80004005;
LAB_40831eb4:
  FUN_40831508(&uStack_444);
  FUN_4083752c(local_30);
  return uVar5;
}



/* 40831ef4 FUN_40831ef4 */

/* Boundary evidence: original MIPS .pdata 40831ef4..40831f4f. Semantic name remains unreviewed. */

undefined4 FUN_40831ef4(int param_1)

{
  int iVar1;
  uint uVar2;
  int *piVar3;
  
  uVar2 = 2;
  piVar3 = (int *)(param_1 + 8);
  do {
    iVar1 = GetAPIAddress(0x5b,uVar2);
    *piVar3 = iVar1;
    if (iVar1 == 0) {
      return 0;
    }
    uVar2 = uVar2 + 1;
    piVar3 = piVar3 + 1;
  } while (uVar2 < 0x4e);
  return 1;
}



/* 40831f50 FUN_40831f50 */

/* Boundary evidence: original MIPS .pdata 40831f50..40831fb7. Semantic name remains unreviewed. */

void FUN_40831f50(void *param_1,void *param_2)

{
  memcmp(param_1,param_2,0x10);
  return;
}



/* 40831fb8 FUN_40831fb8 */

/* Boundary evidence: original MIPS .pdata 40831fb8..40831fc3. Semantic name remains unreviewed. */

undefined4 FUN_40831fb8(void)

{
  return 1;
}



/* 40831fc4 FUN_40831fc4 */

/* Boundary evidence: original MIPS .pdata 40831fc4..4083201f. Semantic name remains unreviewed. */

void FUN_40831fc4(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_408310d8;
  (**(code **)(DAT_40838510 + 0x18))(param_1[2]);
  if ((int *)param_1[3] != (int *)0x0) {
    (**(code **)(*(int *)param_1[3] + 8))();
  }
  return;
}



/* 40832020 FUN_40832020 */

/* Boundary evidence: original MIPS .pdata 40832020..4083204b. Semantic name remains unreviewed. */

LONG FUN_40832020(int param_1)

{
  InterlockedIncrement((LONG *)(param_1 + 4));
  return *(LONG *)(param_1 + 4);
}



/* 4083204c FUN_4083204c */

/* Boundary evidence: original MIPS .pdata 4083204c..408320cb. Semantic name remains unreviewed. */

undefined4 FUN_4083204c(int param_1,int param_2)

{
  undefined4 uVar1;
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_408384f4);
  if (param_2 == 0) {
    uVar1 = 0x80070057;
  }
  else {
    uVar1 = (**(code **)(DAT_40838510 + 0xd4))(*(undefined4 *)(param_1 + 8),param_2);
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_408384f4);
  return uVar1;
}



/* 408320cc FUN_408320cc */

/* Boundary evidence: original MIPS .pdata 408320cc..40832173. Semantic name remains unreviewed. */

undefined4 FUN_408320cc(int param_1,undefined4 param_2,int param_3,int param_4)

{
  undefined4 uVar1;
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_408384f4);
  if ((param_3 == 0) && (param_4 == 0)) {
    uVar1 = 0x80070057;
  }
  else {
    uVar1 = (**(code **)(DAT_40838510 + 200))(*(undefined4 *)(param_1 + 8),param_2,param_3,param_4);
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_408384f4);
  return uVar1;
}



/* 40832174 FUN_40832174 */

/* Boundary evidence: original MIPS .pdata 40832174..40832203. Semantic name remains unreviewed. */

undefined4 FUN_40832174(int param_1,undefined4 param_2,int param_3)

{
  undefined4 uVar1;
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_408384f4);
  if (param_3 == 0) {
    uVar1 = (**(code **)(DAT_40838510 + 0xc4))(*(undefined4 *)(param_1 + 8),param_2,0);
  }
  else {
    uVar1 = 0x80070057;
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_408384f4);
  return uVar1;
}



/* 40832204 FUN_40832204 */

/* Boundary evidence: original MIPS .pdata 40832204..40832283. Semantic name remains unreviewed. */

undefined4 FUN_40832204(int param_1,int param_2)

{
  undefined4 uVar1;
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_408384f4);
  if (param_2 == 0) {
    uVar1 = 0x80070057;
  }
  else {
    uVar1 = (**(code **)(DAT_40838510 + 0xd0))(*(undefined4 *)(param_1 + 8),param_2);
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_408384f4);
  return uVar1;
}



/* 40832284 FUN_40832284 */

/* Boundary evidence: original MIPS .pdata 40832284..4083233f. Semantic name remains unreviewed. */

undefined4 FUN_40832284(int param_1,int param_2,HWND param_3)

{
  BOOL BVar1;
  undefined4 uVar2;
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_408384f4);
  if ((param_3 == (HWND)0x0) || (BVar1 = IsWindow(param_3), BVar1 != 0)) {
    if (param_2 == 0) {
      uVar2 = (**(code **)(DAT_40838510 + 0xcc))(*(undefined4 *)(param_1 + 8),0,param_3);
    }
    else {
      uVar2 = 0x80070057;
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_408384f4);
  }
  else {
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_408384f4);
    uVar2 = 0x80070057;
  }
  return uVar2;
}



/* 40832340 FUN_40832340 */

/* Boundary evidence: original MIPS .pdata 40832340..4083238b. Semantic name remains unreviewed. */

void FUN_40832340(undefined4 *param_1,undefined4 param_2)

{
  *param_1 = param_2;
  return;
}



/* 4083238c FUN_4083238c */

/* Boundary evidence: original MIPS .pdata 4083238c..40832397. Semantic name remains unreviewed. */

undefined4 FUN_4083238c(void)

{
  return 1;
}



/* 40832398 FUN_40832398 */

/* Boundary evidence: original MIPS .pdata 40832398..408323e3. Semantic name remains unreviewed. */

void FUN_40832398(undefined4 *param_1,undefined4 param_2)

{
  *param_1 = param_2;
  return;
}



/* 408323e4 FUN_408323e4 */

/* Boundary evidence: original MIPS .pdata 408323e4..408323ef. Semantic name remains unreviewed. */

undefined4 FUN_408323e4(void)

{
  return 1;
}



/* 408323f0 FUN_408323f0 */

/* Boundary evidence: original MIPS .pdata 408323f0..4083243b. Semantic name remains unreviewed. */

void FUN_408323f0(undefined4 *param_1,undefined4 param_2)

{
  *param_1 = param_2;
  return;
}



/* 4083243c FUN_4083243c */

/* Boundary evidence: original MIPS .pdata 4083243c..40832447. Semantic name remains unreviewed. */

undefined4 FUN_4083243c(void)

{
  return 1;
}



/* 40832448 FUN_40832448 */

/* Boundary evidence: original MIPS .pdata 40832448..408324bf. Semantic name remains unreviewed. */

int FUN_40832448(undefined4 *param_1)

{
  int iVar1;
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_408384f4);
  InterlockedDecrement(param_1 + 1);
  iVar1 = param_1[1];
  if (iVar1 == 0) {
    FUN_40831fc4(param_1);
    operator_delete(param_1);
    iVar1 = 0;
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_408384f4);
  return iVar1;
}



/* 408324c0 FUN_408324c0 */

/* Boundary evidence: original MIPS .pdata 408324c0..40832513. Semantic name remains unreviewed. */

undefined4 * FUN_408324c0(undefined4 *param_1,undefined4 param_2,int *param_3)

{
  *param_1 = &PTR_FUN_408310d8;
  param_1[1] = 1;
  param_1[2] = param_2;
  param_1[3] = param_3;
  if (param_3 != (int *)0x0) {
    (**(code **)(*param_3 + 4))(param_3);
  }
  return param_1;
}



/* 40832514 FUN_40832514 */

/* Boundary evidence: original MIPS .pdata 40832514..4083261b. Semantic name remains unreviewed. */

undefined4 FUN_40832514(int *param_1,void *param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_408384f4);
  if (param_3 == (undefined4 *)0x0) {
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_408384f4);
    return 0x80070057;
  }
  iVar1 = FUN_40831f50(param_2,&DAT_4083127c);
  if (iVar1 == 0) {
    iVar1 = FUN_40831f50(param_2,&DAT_408312bc);
    if (iVar1 != 0) {
      iVar1 = FUN_40832340(param_3,param_1);
      goto LAB_408325c8;
    }
    iVar1 = FUN_40832398(param_3,0);
    if (iVar1 != 0) {
      uVar2 = 0x80004002;
      goto LAB_408325f4;
    }
  }
  else {
    iVar1 = FUN_408323f0(param_3,param_1);
LAB_408325c8:
    if (iVar1 != 0) {
      (**(code **)(*param_1 + 4))(param_1);
      uVar2 = 0;
      goto LAB_408325f4;
    }
  }
  uVar2 = 0x80070057;
LAB_408325f4:
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_408384f4);
  return uVar2;
}



/* 4083261c FUN_4083261c */

/* Boundary evidence: original MIPS .pdata 4083261c..40832753. Semantic name remains unreviewed. */

int FUN_4083261c(undefined4 param_1,int param_2,undefined4 *param_3,int param_4,int *param_5)

{
  undefined4 *puVar1;
  int *piVar2;
  int iVar3;
  int local_20 [2];
  
  if ((param_2 == 0) && (param_3 != (undefined4 *)0x0)) {
    if (param_4 == 0) {
      iVar3 = (**(code **)(DAT_40838510 + 0x14))(param_1,local_20);
      if (-1 < iVar3) {
        if (local_20[0] == -1) {
          iVar3 = -0x7fffbffb;
        }
        else {
          puVar1 = operator_new(0x10);
          if (puVar1 == (undefined4 *)0x0) {
            piVar2 = (int *)0x0;
          }
          else {
            piVar2 = FUN_408324c0(puVar1,local_20[0],param_5);
          }
          if (piVar2 == (int *)0x0) {
            iVar3 = -0x7ff8fff2;
          }
          else {
            iVar3 = FUN_40832340(param_3,piVar2);
            if (iVar3 != 0) {
              return 0;
            }
            iVar3 = -0x7ff8ffa9;
          }
          if (DAT_40838510 != 0) {
            (**(code **)(DAT_40838510 + 0x18))(local_20[0]);
          }
          if (piVar2 != (int *)0x0) {
            (**(code **)(*piVar2 + 8))(piVar2);
          }
        }
      }
    }
    else {
      iVar3 = -0x7ffbfef0;
    }
  }
  else {
    iVar3 = -0x7ff8ffa9;
  }
  return iVar3;
}



/* 40832754 FUN_40832754 */

/* Boundary evidence: original MIPS .pdata 40832754..4083277f. Semantic name remains unreviewed. */

LONG FUN_40832754(int param_1)

{
  InterlockedIncrement((LONG *)(param_1 + 8));
  return *(LONG *)(param_1 + 8);
}



/* 40832780 FUN_40832780 */

/* Boundary evidence: original MIPS .pdata 40832780..40832803. Semantic name remains unreviewed. */

int FUN_40832780(int *param_1,int param_2,undefined4 *param_3,int param_4)

{
  int iVar1;
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_408384f4);
  iVar1 = FUN_4083261c(param_1[3],param_2,param_3,param_4,param_1);
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_408384f4);
  return iVar1;
}



/* 40832804 FUN_40832804 */

/* Boundary evidence: original MIPS .pdata 40832804..4083283f. Semantic name remains unreviewed. */

undefined4 FUN_40832804(void)

{
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_408384f4);
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_408384f4);
  return 0x80004001;
}



/* 40832840 FUN_40832840 */

/* Boundary evidence: original MIPS .pdata 40832840..4083291b. Semantic name remains unreviewed. */

int FUN_40832840(int *param_1,uint param_2,undefined4 param_3,undefined4 param_4,undefined *param_5)

{
  int iVar1;
  undefined4 *local_28;
  uint local_24;
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_408384f4);
  if (param_5 == (undefined *)0x0) {
    iVar1 = -0x7ff8ffa9;
  }
  else {
    iVar1 = (**(code **)(DAT_40838510 + 0x54))(param_1[3],param_2,param_3,&local_24,&local_28);
    if (-1 < iVar1) {
      iVar1 = FUN_40835da8(param_1,local_24,local_28,param_2,param_4,param_5);
    }
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_408384f4);
  return iVar1;
}



/* 4083291c FUN_4083291c */

/* Boundary evidence: original MIPS .pdata 4083291c..40832977. Semantic name remains unreviewed. */

undefined4 FUN_4083291c(int param_1)

{
  undefined4 uVar1;
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_408384f4);
  uVar1 = (**(code **)(DAT_40838510 + 0x7c))(*(undefined4 *)(param_1 + 0xc));
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_408384f4);
  return uVar1;
}



/* 40832978 FUN_40832978 */

/* Boundary evidence: original MIPS .pdata 40832978..40832a0f. Semantic name remains unreviewed. */

undefined4 FUN_40832978(int param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_408384f4);
  if ((param_2 == 0) && (param_3 == 0)) {
    uVar1 = 0x80070057;
  }
  else {
    uVar1 = (**(code **)(DAT_40838510 + 0x1c))(*(undefined4 *)(param_1 + 0xc),param_2,param_3);
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_408384f4);
  return uVar1;
}



/* 40832a10 FUN_40832a10 */

/* Boundary evidence: original MIPS .pdata 40832a10..40832a9f. Semantic name remains unreviewed. */

undefined4 FUN_40832a10(int param_1,int param_2,undefined4 param_3)

{
  undefined4 uVar1;
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_408384f4);
  if (param_2 == 0) {
    uVar1 = 0x80070057;
  }
  else {
    uVar1 = (**(code **)(DAT_40838510 + 0x20))(*(undefined4 *)(param_1 + 0xc),param_2,param_3);
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_408384f4);
  return uVar1;
}



/* 40832aa0 FUN_40832aa0 */

/* Boundary evidence: original MIPS .pdata 40832aa0..40832b2b. Semantic name remains unreviewed. */

undefined4 FUN_40832aa0(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_408384f4);
  uVar1 = (**(code **)(DAT_40838510 + 0x30))(*(undefined4 *)(param_1 + 0xc),param_2,param_3,param_4)
  ;
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_408384f4);
  return uVar1;
}



/* 40832b2c FUN_40832b2c */

/* Boundary evidence: original MIPS .pdata 40832b2c..40832bb7. Semantic name remains unreviewed. */

undefined4 FUN_40832b2c(int param_1,undefined4 param_2,int param_3)

{
  undefined4 uVar1;
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_408384f4);
  if (param_3 == 0) {
    uVar1 = (**(code **)(DAT_40838510 + 0x34))(*(undefined4 *)(param_1 + 0xc),param_2);
  }
  else {
    uVar1 = 0x80070057;
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_408384f4);
  return uVar1;
}



/* 40832bb8 FUN_40832bb8 */

/* Boundary evidence: original MIPS .pdata 40832bb8..40832c23. Semantic name remains unreviewed. */

undefined4 FUN_40832bb8(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_408384f4);
  uVar1 = (**(code **)(DAT_40838510 + 0x24))(*(undefined4 *)(param_1 + 0xc),param_2);
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_408384f4);
  return uVar1;
}



/* 40832c24 FUN_40832c24 */

/* Boundary evidence: original MIPS .pdata 40832c24..40832c8f. Semantic name remains unreviewed. */

undefined4 FUN_40832c24(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_408384f4);
  uVar1 = (**(code **)(DAT_40838510 + 0x28))(*(undefined4 *)(param_1 + 0xc),param_2);
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_408384f4);
  return uVar1;
}



/* 40832c90 FUN_40832c90 */

/* Boundary evidence: original MIPS .pdata 40832c90..40832d1b. Semantic name remains unreviewed. */

undefined4 FUN_40832c90(int param_1,undefined4 param_2,int param_3)

{
  undefined4 uVar1;
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_408384f4);
  if (param_3 == 0) {
    uVar1 = (**(code **)(DAT_40838510 + 0x2c))(*(undefined4 *)(param_1 + 0xc),param_2);
  }
  else {
    uVar1 = 0x80070057;
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_408384f4);
  return uVar1;
}



/* 40832d1c FUN_40832d1c */

/* Boundary evidence: original MIPS .pdata 40832d1c..40832d8b. Semantic name remains unreviewed. */

void FUN_40832d1c(undefined *param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4)

{
  undefined4 uVar1;
  
  uVar1 = (*(code *)param_1)(param_2,param_3);
  *param_4 = uVar1;
  return;
}



/* 40832d8c FUN_40832d8c */

/* Boundary evidence: original MIPS .pdata 40832d8c..40832d97. Semantic name remains unreviewed. */

undefined4 FUN_40832d8c(void)

{
  return 1;
}



/* 40832d98 FUN_40832d98 */

/* Boundary evidence: original MIPS .pdata 40832d98..40832e07. Semantic name remains unreviewed. */

undefined4 FUN_40832d98(int *param_1)

{
  undefined4 uVar1;
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_408384f4);
  uVar1 = (**(code **)(*param_1 + 0x48))
                    (param_1,param_1[0x87],param_1[0x88],param_1[0x89],param_1[0x8a],0);
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_408384f4);
  return uVar1;
}



/* 40832e08 FUN_40832e08 */

/* Boundary evidence: original MIPS .pdata 40832e08..40832eaf. Semantic name remains unreviewed. */

int FUN_40832e08(int param_1,undefined4 param_2,uint param_3)

{
  int iVar1;
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_408384f4);
  iVar1 = (**(code **)(DAT_40838510 + 0x3c))(*(undefined4 *)(param_1 + 0xc),param_2,param_3);
  if (iVar1 < 0) {
    *(undefined4 *)(param_1 + 0x214) = 0;
    *(undefined4 *)(param_1 + 0x218) = 0xffffffff;
  }
  else {
    *(uint *)(param_1 + 0x214) = param_3 & 1;
    *(undefined4 *)(param_1 + 0x218) = param_2;
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_408384f4);
  return iVar1;
}



/* 40832eb0 FUN_40832eb0 */

/* Boundary evidence: original MIPS .pdata 40832eb0..40832f2f. Semantic name remains unreviewed. */

undefined4 FUN_40832eb0(int param_1)

{
  undefined4 uVar1;
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_408384f4);
  if (*(int *)(param_1 + 0x218) == -1) {
    uVar1 = 0x887600d4;
  }
  else {
    uVar1 = (**(code **)(DAT_40838510 + 0x38))
                      (*(undefined4 *)(param_1 + 0xc),*(undefined4 *)(param_1 + 0x214));
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_408384f4);
  return uVar1;
}



/* 40832f30 FUN_40832f30 */

/* Boundary evidence: original MIPS .pdata 40832f30..40832fcf. Semantic name remains unreviewed. */

void FUN_40832f30(undefined4 param_1,undefined4 *param_2,int param_3)

{
  memset(param_2,0,0x6c);
  *param_2 = 0x6c;
  param_2[1] = 0x41006;
  param_2[2] = *(undefined4 *)(param_3 + 0xb0);
  param_2[3] = *(undefined4 *)(param_3 + 0xac);
  param_2[7] = *(undefined4 *)(param_3 + 0xb8);
  param_2[0x11] = 0x20;
  param_2[0x14] = *(undefined4 *)(param_3 + 0xa8);
  if (*(int *)(param_3 + 0xa8) == 8) {
    param_2[0x12] = 0x20;
  }
  else {
    param_2[0x12] = 0x40;
  }
  return;
}



/* 40832fd0 FUN_40832fd0 */

/* Boundary evidence: original MIPS .pdata 40832fd0..4083306f. Semantic name remains unreviewed. */

void FUN_40832fd0(int param_1)

{
  int iVar1;
  undefined1 auStack_d8 [68];
  undefined2 local_94;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_20;
  uint local_18;
  
  local_18 = DAT_408384ec;
  memset(auStack_d8,0,0xc0);
  local_94 = 0xc0;
  iVar1 = EnumDisplaySettings(param_1 + 0x10,0xffffffff,auStack_d8);
  if (iVar1 == 0) {
    *(undefined4 *)(param_1 + 0x21c) = 0;
    *(undefined4 *)(param_1 + 0x220) = 0;
    *(undefined4 *)(param_1 + 0x224) = 0;
    *(undefined4 *)(param_1 + 0x228) = 0;
  }
  else {
    *(undefined4 *)(param_1 + 0x21c) = local_2c;
    *(undefined4 *)(param_1 + 0x220) = local_28;
    *(undefined4 *)(param_1 + 0x224) = local_30;
    *(undefined4 *)(param_1 + 0x228) = local_20;
  }
  FUN_4083752c(local_18);
  return;
}



/* 40833070 FUN_40833070 */

/* Boundary evidence: original MIPS .pdata 40833070..408330b3. Semantic name remains unreviewed. */

undefined4 FUN_40833070(int *param_1)

{
  (**(code **)(*param_1 + 0x54))(param_1);
  (**(code **)(*param_1 + 8))(param_1);
  return 1;
}



/* 408330b4 FUN_408330b4 */

/* Boundary evidence: original MIPS .pdata 408330b4..40833123. Semantic name remains unreviewed. */

void FUN_408330b4(undefined *param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4)

{
  undefined4 uVar1;
  
  uVar1 = (*(code *)param_1)(param_2,param_3);
  *param_4 = uVar1;
  return;
}



/* 40833124 FUN_40833124 */

/* Boundary evidence: original MIPS .pdata 40833124..4083312f. Semantic name remains unreviewed. */

undefined4 FUN_40833124(void)

{
  return 1;
}



/* 40833130 FUN_40833130 */

/* Boundary evidence: original MIPS .pdata 40833130..4083333b. Semantic name remains unreviewed. */

int FUN_40833130(int param_1,int param_2,int param_3,undefined4 param_4,undefined *param_5)

{
  undefined4 *_Dst;
  int iVar1;
  uint uVar2;
  undefined4 *puVar3;
  int iVar4;
  uint local_30;
  int local_2c;
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_408384f4);
  if (param_5 == (undefined *)0x0) {
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_408384f4);
    iVar4 = -0x7ff8ffa9;
  }
  else {
    if (param_3 == 0) {
      param_2 = 0;
    }
    if (param_2 == 0) {
      local_30 = 0;
      iVar4 = (**(code **)(DAT_40838510 + 0xf0))(*(undefined4 *)(param_1 + 8),0,param_3,&local_30,0)
      ;
      if (-1 < iVar4) {
        if (local_30 < 0x38e38e4) {
          uVar2 = local_30 * 0x48;
        }
        else {
          uVar2 = 0xffffffff;
        }
        _Dst = operator_new(uVar2);
        if (_Dst == (undefined4 *)0x0) {
          iVar4 = -0x7ff8fff2;
        }
        else {
          memset(_Dst,0,local_30 * 0x48);
          uVar2 = 0;
          puVar3 = _Dst;
          if (local_30 != 0) {
            do {
              *puVar3 = 0x48;
              uVar2 = uVar2 + 1;
              puVar3 = puVar3 + 0x12;
            } while (uVar2 < local_30);
          }
          iVar4 = (**(code **)(DAT_40838510 + 0xf0))
                            (*(undefined4 *)(param_1 + 8),0,param_3,&local_30,_Dst);
          if ((-1 < iVar4) && (uVar2 = 0, puVar3 = _Dst, local_30 != 0)) {
            do {
              local_2c = 0;
              iVar1 = FUN_408330b4(param_5,puVar3,param_4,&local_2c);
              if (iVar1 == 0) {
                iVar4 = -0x7fffbffb;
              }
              if (local_2c == 0) break;
              uVar2 = uVar2 + 1;
              puVar3 = puVar3 + 0x12;
            } while (uVar2 < local_30);
          }
          operator_delete(_Dst);
        }
      }
    }
    else {
      iVar4 = -0x7ff8ffa9;
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_408384f4);
  }
  return iVar4;
}



/* 4083333c FUN_4083333c */

/* Boundary evidence: original MIPS .pdata 4083333c..408333db. Semantic name remains unreviewed. */

undefined4 FUN_4083333c(int param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  undefined4 uVar1;
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_408384f4);
  if (param_3 == 0) {
    uVar1 = 0x80070057;
  }
  else {
    uVar1 = (**(code **)(DAT_40838510 + 0xf4))(*(undefined4 *)(param_1 + 8),param_2,param_3,param_4)
    ;
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_408384f4);
  return uVar1;
}



/* 408333dc FUN_408333dc */

/* Boundary evidence: original MIPS .pdata 408333dc..4083346b. Semantic name remains unreviewed. */

undefined4 FUN_408333dc(int param_1,undefined4 param_2,int param_3)

{
  undefined4 uVar1;
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_408384f4);
  if (param_3 == 0) {
    uVar1 = 0x80070057;
  }
  else {
    uVar1 = (**(code **)(DAT_40838510 + 0xf8))(*(undefined4 *)(param_1 + 8),param_2,param_3);
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_408384f4);
  return uVar1;
}



/* 4083346c FUN_4083346c */

/* Boundary evidence: original MIPS .pdata 4083346c..408334b7. Semantic name remains unreviewed. */

void FUN_4083346c(undefined4 *param_1,undefined4 param_2)

{
  *param_1 = param_2;
  return;
}



/* 408334b8 FUN_408334b8 */

/* Boundary evidence: original MIPS .pdata 408334b8..408334c3. Semantic name remains unreviewed. */

undefined4 FUN_408334b8(void)

{
  return 1;
}



/* 408334c4 FUN_408334c4 */

/* Boundary evidence: original MIPS .pdata 408334c4..4083350f. Semantic name remains unreviewed. */

void FUN_408334c4(undefined4 *param_1,undefined4 param_2)

{
  *param_1 = param_2;
  return;
}



/* 40833510 FUN_40833510 */

/* Boundary evidence: original MIPS .pdata 40833510..4083351b. Semantic name remains unreviewed. */

undefined4 FUN_40833510(void)

{
  return 1;
}



/* 4083351c FUN_4083351c */

/* Boundary evidence: original MIPS .pdata 4083351c..4083357f. Semantic name remains unreviewed. */

void FUN_4083351c(void *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 local_res4;
  undefined4 local_res8;
  undefined4 local_resc;
  
  local_res4 = param_2;
  local_res8 = param_3;
  local_resc = param_4;
  memcpy(param_1,&local_res4,0x6c);
  return;
}



/* 40833580 FUN_40833580 */

/* Boundary evidence: original MIPS .pdata 40833580..4083358b. Semantic name remains unreviewed. */

undefined4 FUN_40833580(void)

{
  return 1;
}



/* 4083358c FUN_4083358c */

/* Boundary evidence: original MIPS .pdata 4083358c..408335d7. Semantic name remains unreviewed. */

void FUN_4083358c(undefined4 *param_1,undefined4 param_2)

{
  *param_1 = param_2;
  return;
}



/* 408335d8 FUN_408335d8 */

/* Boundary evidence: original MIPS .pdata 408335d8..408335e3. Semantic name remains unreviewed. */

undefined4 FUN_408335d8(void)

{
  return 1;
}



/* 408335e4 FUN_408335e4 */

/* Boundary evidence: original MIPS .pdata 408335e4..4083362f. Semantic name remains unreviewed. */

void FUN_408335e4(undefined4 *param_1,undefined4 param_2)

{
  *param_1 = param_2;
  return;
}



/* 40833630 FUN_40833630 */

/* Boundary evidence: original MIPS .pdata 40833630..4083363b. Semantic name remains unreviewed. */

undefined4 FUN_40833630(void)

{
  return 1;
}



/* 4083363c FUN_4083363c */

/* Boundary evidence: original MIPS .pdata 4083363c..408336cf. Semantic name remains unreviewed. */

void FUN_4083363c(undefined4 *param_1)

{
  int iVar1;
  
  *param_1 = &PTR_FUN_40831130;
  param_1[1] = &PTR_LAB_40831114;
  if ((HDC)param_1[0x84] != (HDC)0x0) {
    DeleteDC((HDC)param_1[0x84]);
    param_1[0x84] = 0;
  }
  iVar1 = param_1[0x86];
  if (((iVar1 != 0) && (iVar1 != -1)) && (param_1[0x85] != 0)) {
    FUN_40832e08((int)param_1,iVar1,0);
  }
  (**(code **)(DAT_40838510 + 0x10))(param_1[3]);
  return;
}



/* 408336e4 FUN_408336e4 */

/* Boundary evidence: original MIPS .pdata 408336e4..4083389f. Semantic name remains unreviewed. */

int FUN_408336e4(int *param_1,int param_2,undefined4 *param_3,int param_4)

{
  undefined4 *puVar1;
  int *piVar2;
  int iVar3;
  int local_28 [2];
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_408384f4);
  if ((param_2 == 0) || (param_3 == (undefined4 *)0x0)) {
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_408384f4);
    return -0x7ff8ffa9;
  }
  if (param_4 == 0) {
    if (param_1[0x86] == -1) {
      iVar3 = -0x7789ff2c;
    }
    else {
      iVar3 = (**(code **)(DAT_40838510 + 0x40))(param_1[3],param_2,local_28);
      if (-1 < iVar3) {
        if (local_28[0] == -1) {
          iVar3 = -0x7fffbffb;
        }
        else {
          puVar1 = operator_new(0x18);
          if (puVar1 == (undefined4 *)0x0) {
            piVar2 = (int *)0x0;
          }
          else {
            piVar2 = FUN_40835a44(puVar1,local_28[0],param_1,0);
          }
          if (piVar2 == (int *)0x0) {
            iVar3 = -0x7ff8fff2;
          }
          else {
            iVar3 = FUN_4083346c(param_3,piVar2);
            if (iVar3 == 0) {
              iVar3 = -0x7ff8ffa9;
            }
            else {
              iVar3 = (**(code **)(DAT_40838510 + 0xe4))(local_28[0],piVar2);
              if (-1 < iVar3) goto LAB_40833870;
            }
          }
          if (DAT_40838510 != 0) {
            (**(code **)(DAT_40838510 + 0x48))(local_28[0]);
          }
          if (piVar2 != (int *)0x0) {
            (**(code **)(*piVar2 + 8))(piVar2);
          }
        }
      }
    }
  }
  else {
    iVar3 = -0x7ff8ffa9;
  }
LAB_40833870:
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_408384f4);
  return iVar3;
}



/* 408338a0 FUN_408338a0 */

/* Boundary evidence: original MIPS .pdata 408338a0..40833a13. Semantic name remains unreviewed. */

int FUN_408338a0(int *param_1,undefined4 param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int local_28 [2];
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_408384f4);
  if (param_3 == (undefined4 *)0x0) {
    iVar4 = -0x7ff8ffa9;
  }
  else if (param_1[0x86] == -1) {
    iVar4 = -0x7789ff2c;
  }
  else {
    iVar4 = (**(code **)(DAT_40838510 + 0x44))(param_1[3],param_2,local_28);
    if (-1 < iVar4) {
      if (local_28[0] == -1) {
        iVar4 = -0x7fffbffb;
      }
      else {
        iVar4 = 0;
        puVar1 = operator_new(0x18);
        if (puVar1 == (undefined4 *)0x0) {
          piVar2 = (int *)0x0;
        }
        else {
          piVar2 = FUN_40835a44(puVar1,local_28[0],param_1,0);
        }
        if (piVar2 == (int *)0x0) {
          iVar4 = -0x7ff8fff2;
        }
        else {
          iVar3 = FUN_4083346c(param_3,piVar2);
          if (iVar3 != 0) goto LAB_408339e4;
          iVar4 = -0x7ff8ffa9;
        }
        if (DAT_40838510 != 0) {
          (**(code **)(DAT_40838510 + 0x48))(local_28[0]);
        }
        if (piVar2 != (int *)0x0) {
          (**(code **)(*piVar2 + 8))(piVar2);
        }
      }
    }
  }
LAB_408339e4:
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_408384f4);
  return iVar4;
}



/* 40833a14 FUN_40833a14 */

/* Boundary evidence: original MIPS .pdata 40833a14..40833b87. Semantic name remains unreviewed. */

int FUN_40833a14(int *param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 local_28;
  int *local_24;
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_408384f4);
  if (param_2 != (undefined4 *)0x0) {
    iVar1 = (**(code **)(DAT_40838510 + 0xe8))(param_1[3],&local_28);
    if (iVar1 < 0) goto LAB_40833b58;
    iVar1 = (**(code **)(DAT_40838510 + 0xe0))(local_28,&local_24);
    if (iVar1 < 0) {
      iVar1 = -0x7fffbffb;
      goto LAB_40833b58;
    }
    if (local_24 == (int *)0x0) {
      puVar2 = operator_new(0x18);
      if (puVar2 == (undefined4 *)0x0) {
        local_24 = (int *)0x0;
      }
      else {
        local_24 = FUN_40835a44(puVar2,local_28,param_1,1);
      }
      if (local_24 == (int *)0x0) {
        iVar1 = -0x7ff8fff2;
        goto LAB_40833b58;
      }
      iVar1 = (**(code **)(DAT_40838510 + 0xe4))(local_28,local_24);
      if (iVar1 < 0) goto LAB_40833b58;
    }
    else {
      (**(code **)(*local_24 + 4))(local_24);
    }
    iVar3 = FUN_4083346c(param_2,local_24);
    if (iVar3 != 0) goto LAB_40833b58;
    (**(code **)(*local_24 + 8))(local_24);
  }
  iVar1 = -0x7ff8ffa9;
LAB_40833b58:
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_408384f4);
  return iVar1;
}



/* 40833b88 FUN_40833b88 */

/* Boundary evidence: original MIPS .pdata 40833b88..40833bf7. Semantic name remains unreviewed. */

undefined4 FUN_40833b88(int *param_1)

{
  undefined4 uVar1;
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_408384f4);
  uVar1 = (**(code **)(*param_1 + 0x1c))(param_1,0x11,0,0,FUN_40833070);
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_408384f4);
  return uVar1;
}



/* 40833bf8 FUN_40833bf8 */

/* Boundary evidence: original MIPS .pdata 40833bf8..40833ccb. Semantic name remains unreviewed. */

undefined4 FUN_40833bf8(int param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 auStack_e0 [68];
  undefined2 local_9c;
  undefined4 local_28;
  uint local_20;
  
  local_20 = DAT_408384ec;
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_408384f4);
  if (param_2 == (undefined4 *)0x0) {
    uVar2 = 0x80070057;
  }
  else {
    memset(auStack_e0,0,0xc0);
    local_9c = 0xc0;
    iVar1 = EnumDisplaySettings(param_1 + 0x10,0xffffffff,auStack_e0);
    if ((iVar1 == 0) || (iVar1 = FUN_408334c4(param_2,local_28), iVar1 == 0)) {
      uVar2 = 0x80004005;
    }
    else {
      uVar2 = 0;
    }
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_408384f4);
  FUN_4083752c(local_20);
  return uVar2;
}



/* 40833ccc FUN_40833ccc */

/* Boundary evidence: original MIPS .pdata 40833ccc..40833f1f. Semantic name remains unreviewed. */

undefined4 FUN_40833ccc(int param_1,int param_2,int param_3,undefined4 param_4,undefined *param_5)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  undefined4 uVar5;
  int *piVar6;
  int local_1d8 [2];
  int local_1d0 [28];
  undefined4 auStack_160 [28];
  undefined1 auStack_f0 [68];
  undefined2 local_ac;
  int local_48;
  int local_44;
  int local_40;
  uint local_30;
  
  local_30 = DAT_408384ec;
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_408384f4);
  piVar6 = (int *)0x0;
  if ((param_2 == 0) &&
     ((param_3 == 0 ||
      ((iVar2 = CeSafeCopyMemory(local_1d0,param_3,0x6c), iVar2 != 0 &&
       (piVar6 = local_1d0, local_1d0[0] == 0x6c)))))) {
    if (param_5 == (undefined *)0x0) {
      uVar5 = 0x80070057;
    }
    else {
      local_1d8[0] = 0;
      iVar2 = 0;
      memset(auStack_f0,0,0xc0);
      while( true ) {
        local_ac = 0xc0;
        bVar1 = true;
        iVar3 = EnumDisplaySettings(param_1 + 0x10,iVar2,auStack_f0);
        if (iVar3 == 0) break;
        if (piVar6 != (int *)0x0) {
          uVar4 = piVar6[1];
          if (((uVar4 & 2) != 0) && (piVar6[2] != local_40)) {
            bVar1 = false;
          }
          if (((uVar4 & 4) != 0) && (piVar6[3] != local_44)) {
            bVar1 = false;
          }
          if (((uVar4 & 0x1000) != 0) && (piVar6[0x14] != local_48)) {
            bVar1 = false;
          }
        }
        if ((((local_48 != 8) && (local_48 != 0x10)) && (local_48 != 0x18)) && (local_48 != 0x20)) {
          bVar1 = false;
        }
        if (bVar1) {
          FUN_40832f30(param_1,auStack_160,(int)auStack_f0);
          iVar3 = FUN_40832d1c(param_5,auStack_160,param_4,local_1d8);
          if (iVar3 == 0) {
            uVar5 = 0x80004005;
            goto LAB_40833ed4;
          }
          if (local_1d8[0] == 0) break;
        }
        iVar2 = iVar2 + 1;
        memset(auStack_f0,0,0xc0);
      }
      uVar5 = 0;
    }
LAB_40833ed4:
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_408384f4);
    FUN_4083752c(local_30);
  }
  else {
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_408384f4);
    FUN_4083752c(local_30);
    uVar5 = 0x80070057;
  }
  return uVar5;
}



/* 40833f20 FUN_40833f20 */

/* Boundary evidence: original MIPS .pdata 40833f20..408340d3. Semantic name remains unreviewed. */

undefined4 FUN_40833f20(int param_1,void *param_2)

{
  int iVar1;
  HDC pHVar2;
  HBITMAP h;
  undefined4 uVar3;
  undefined1 auStack_208 [96];
  undefined4 local_1a8;
  undefined4 local_1a4;
  undefined4 local_1a0;
  undefined1 auStack_19c [60];
  uint local_160;
  undefined4 local_154;
  undefined4 local_150;
  undefined4 local_14c;
  int local_148;
  undefined1 auStack_138 [64];
  undefined4 local_f8;
  undefined4 local_f4;
  undefined4 local_f0;
  int local_e4;
  undefined1 auStack_e0 [68];
  undefined2 local_9c;
  int local_38;
  uint local_20;
  
  local_20 = DAT_408384ec;
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_408384f4);
  if (param_2 == (void *)0x0) {
    uVar3 = 0x80070057;
    goto LAB_408340a4;
  }
  memset(auStack_e0,0,0xc0);
  local_9c = 0xc0;
  iVar1 = EnumDisplaySettings((LPCWSTR)(param_1 + 0x10),0xffffffff,auStack_e0);
  if (iVar1 != 0) {
    FUN_40832f30(param_1,&local_1a8,(int)auStack_e0);
    if (local_38 == 8) {
LAB_40834074:
      memcpy(auStack_208,auStack_19c,0x60);
      iVar1 = FUN_4083351c(param_2,local_1a8,local_1a4,local_1a0);
      if (iVar1 != 0) {
        uVar3 = 0;
        goto LAB_408340a4;
      }
    }
    else {
      if (*(int *)(param_1 + 0x210) == 0) {
        pHVar2 = CreateDCW((LPCWSTR)(param_1 + 0x10),(LPCWSTR)0x0,(LPCWSTR)0x0,(DEVMODEW *)0x0);
        *(HDC *)(param_1 + 0x210) = pHVar2;
        if (pHVar2 == (HDC)0x0) goto LAB_40833fa4;
      }
      h = CreateCompatibleBitmap(*(HDC *)(param_1 + 0x210),0x10,0x10);
      if (h != (HBITMAP)0x0) {
        iVar1 = GetObjectW(h,0x58,auStack_138);
        if (iVar1 != 0) {
          local_154 = local_f8;
          local_150 = local_f4;
          local_14c = local_f0;
          if (local_e4 != 0) {
            local_148 = local_e4;
            local_160 = local_160 | 1;
          }
          DeleteObject(h);
          goto LAB_40834074;
        }
        DeleteObject(h);
      }
    }
  }
LAB_40833fa4:
  uVar3 = 0x80004005;
LAB_408340a4:
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_408384f4);
  FUN_4083752c(local_20);
  return uVar3;
}



/* 408340d4 FUN_408340d4 */

/* Boundary evidence: original MIPS .pdata 408340d4..4083423f. Semantic name remains unreviewed. */

undefined4 FUN_408340d4(int param_1,int param_2,int param_3,int param_4,int param_5,int param_6)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 auStack_e8 [68];
  undefined2 local_a4;
  undefined4 local_a0;
  int local_40;
  int local_3c;
  int local_38;
  int local_30;
  uint local_28;
  
  local_28 = DAT_408384ec;
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_408384f4);
  if (param_6 == 0) {
    if (*(int *)(param_1 + 0x214) == 0) {
      uVar2 = 0x887600d4;
    }
    else {
      FUN_40832fd0(param_1);
      if ((((*(int *)(param_1 + 0x21c) != param_2) || (*(int *)(param_1 + 0x220) != param_3)) ||
          (*(int *)(param_1 + 0x224) != param_4)) || (*(int *)(param_1 + 0x228) != param_5)) {
        memset(auStack_e8,0,0xc0);
        local_a4 = 0xc0;
        local_30 = param_5;
        local_a0 = 0x1c0000;
        local_40 = param_4;
        local_3c = param_2;
        local_38 = param_3;
        iVar1 = ChangeDisplaySettingsEx(param_1 + 0x10,auStack_e8,0,0,0);
        if (iVar1 == -2) {
          uVar2 = 0x88760078;
          goto LAB_40834204;
        }
        if (iVar1 != 0) {
          uVar2 = 0x80004005;
          goto LAB_40834204;
        }
      }
      uVar2 = 0;
    }
  }
  else {
    uVar2 = 0x80070057;
  }
LAB_40834204:
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_408384f4);
  FUN_4083752c(local_28);
  return uVar2;
}



/* 40834240 FUN_40834240 */

/* Boundary evidence: original MIPS .pdata 40834240..408343c3. Semantic name remains unreviewed. */

int FUN_40834240(int param_1,undefined4 param_2,int param_3,undefined4 *param_4,int param_5)

{
  undefined4 *puVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int local_20 [2];
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_408384f4);
  if ((param_3 == 0) || (param_4 == (undefined4 *)0x0)) {
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_408384f4);
    return -0x7ff8ffa9;
  }
  if (param_5 == 0) {
    iVar4 = (**(code **)(DAT_40838510 + 0xec))
                      (*(undefined4 *)(param_1 + 8),param_2,param_3,local_20);
    if (-1 < iVar4) {
      if (local_20[0] == -1) {
        iVar4 = -0x7fffbffb;
      }
      else {
        puVar1 = operator_new(0x10);
        if (puVar1 == (undefined4 *)0x0) {
          piVar2 = (int *)0x0;
        }
        else {
          piVar2 = FUN_40836964(puVar1,local_20[0],(int *)(param_1 + -4));
        }
        if (piVar2 == (int *)0x0) {
          iVar4 = -0x7ff8fff2;
        }
        else {
          iVar3 = FUN_4083358c(param_4,piVar2);
          if (iVar3 == 0) {
            iVar4 = -0x7ff8ffa9;
          }
          if (-1 < iVar4) goto LAB_40834398;
        }
        if (DAT_40838510 != 0) {
          (**(code **)(DAT_40838510 + 0x100))(local_20[0]);
        }
        if (piVar2 != (int *)0x0) {
          (**(code **)(*piVar2 + 8))(piVar2);
        }
      }
    }
  }
  else {
    iVar4 = -0x7ff8ffa9;
  }
LAB_40834398:
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_408384f4);
  return iVar4;
}



/* 408343c4 FUN_408343c4 */

/* Boundary evidence: original MIPS .pdata 408343c4..4083443b. Semantic name remains unreviewed. */

undefined4 * FUN_408343c4(undefined4 *param_1,undefined4 param_2,STRSAFE_LPCWSTR param_3)

{
  param_1[1] = &PTR_LAB_408310f8;
  *param_1 = &PTR_FUN_40831130;
  param_1[3] = param_2;
  param_1[1] = &PTR_LAB_40831114;
  param_1[2] = 1;
  param_1[0x84] = 0;
  param_1[0x85] = 0;
  param_1[0x86] = 0xffffffff;
  StringCchCopyW((STRSAFE_LPWSTR)(param_1 + 4),0x100,param_3);
  FUN_40832fd0((int)param_1);
  return param_1;
}



/* 4083443c FUN_4083443c */

/* Boundary evidence: original MIPS .pdata 4083443c..4083457f. Semantic name remains unreviewed. */

undefined4 FUN_4083443c(int *param_1,void *param_2,undefined4 *param_3)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_408384f4);
  if (param_3 == (undefined4 *)0x0) {
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_408384f4);
    return 0x80070057;
  }
  iVar1 = FUN_40831f50(param_2,&DAT_4083127c);
  if (iVar1 == 0) {
    iVar1 = FUN_40831f50(param_2,&DAT_4083128c);
    if (iVar1 != 0) {
      iVar1 = FUN_408317a4(param_3,param_1);
      goto LAB_408344f4;
    }
    iVar1 = FUN_40831f50(param_2,&DAT_408312ec);
    if (iVar1 != 0) {
      piVar2 = param_1 + 1;
      if (param_1 == (int *)0x0) {
        piVar2 = (int *)0x0;
      }
      iVar1 = FUN_408335e4(param_3,piVar2);
      goto LAB_408344f4;
    }
    iVar1 = FUN_40832398(param_3,0);
    if (iVar1 != 0) {
      uVar3 = 0x80004002;
      goto LAB_40834558;
    }
  }
  else {
    iVar1 = FUN_408323f0(param_3,param_1);
LAB_408344f4:
    if (iVar1 != 0) {
      (**(code **)(*param_1 + 4))(param_1);
      uVar3 = 0;
      goto LAB_40834558;
    }
  }
  uVar3 = 0x80070057;
LAB_40834558:
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_408384f4);
  return uVar3;
}



/* 40834580 FUN_40834580 */

/* Boundary evidence: original MIPS .pdata 40834580..408345f7. Semantic name remains unreviewed. */

int FUN_40834580(undefined4 *param_1)

{
  int iVar1;
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_408384f4);
  InterlockedDecrement(param_1 + 2);
  iVar1 = param_1[2];
  if (iVar1 == 0) {
    FUN_4083363c(param_1);
    operator_delete(param_1);
    iVar1 = 0;
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_408384f4);
  return iVar1;
}



/* 40834620 FUN_40834620 */

/* Boundary evidence: original MIPS .pdata 40834620..408346bf. Semantic name remains unreviewed. */

void FUN_40834620(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_40831194;
  if (*(char *)(param_1 + 4) == '\0') {
    (**(code **)(DAT_40838510 + 0x48))();
  }
  else {
    (**(code **)(DAT_40838510 + 0xe4))(param_1[2],0);
  }
  if ((int *)param_1[3] != (int *)0x0) {
    (**(code **)(*(int *)param_1[3] + 8))();
  }
  if ((int *)param_1[5] != (int *)0x0) {
    (**(code **)(*(int *)param_1[5] + 8))();
  }
  return;
}



/* 408346c0 FUN_408346c0 */

/* Boundary evidence: original MIPS .pdata 408346c0..408346eb. Semantic name remains unreviewed. */

LONG FUN_408346c0(int param_1)

{
  InterlockedIncrement((LONG *)(param_1 + 4));
  return *(LONG *)(param_1 + 4);
}



/* 408346ec FUN_408346ec */

/* Boundary evidence: original MIPS .pdata 408346ec..40834757. Semantic name remains unreviewed. */

undefined4 FUN_408346ec(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_408384f4);
  uVar1 = (**(code **)(DAT_40838510 + 0x4c))(*(undefined4 *)(param_1 + 8),param_2);
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_408384f4);
  return uVar1;
}



/* 40834758 FUN_40834758 */

/* Boundary evidence: original MIPS .pdata 40834758..408347b7. Semantic name remains unreviewed. */

undefined4 FUN_40834758(int param_1,undefined4 *param_2)

{
  if (param_1 != 0) {
    *param_2 = *(undefined4 *)(param_1 + 8);
  }
  return 1;
}



/* 408347b8 FUN_408347b8 */

/* Boundary evidence: original MIPS .pdata 408347b8..408347c3. Semantic name remains unreviewed. */

undefined4 FUN_408347b8(void)

{
  return 1;
}



/* 408347c4 FUN_408347c4 */

/* Boundary evidence: original MIPS .pdata 408347c4..4083488b. Semantic name remains unreviewed. */

undefined4
FUN_408347c4(int param_1,undefined4 param_2,int param_3,undefined4 param_4,undefined4 param_5,
            undefined4 param_6)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 local_20 [2];
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_408384f4);
  local_20[0] = 0xffffffff;
  iVar1 = FUN_40834758(param_3,local_20);
  if (iVar1 == 0) {
    uVar2 = 0x80070057;
  }
  else {
    uVar2 = (**(code **)(DAT_40838510 + 0xb8))
                      (*(undefined4 *)(param_1 + 8),param_2,local_20[0],param_4,param_5,param_6);
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_408384f4);
  return uVar2;
}



/* 4083488c FUN_4083488c */

/* Boundary evidence: original MIPS .pdata 4083488c..40834953. Semantic name remains unreviewed. */

undefined4
FUN_4083488c(int param_1,undefined4 param_2,int param_3,undefined4 param_4,undefined4 param_5,
            undefined4 param_6)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 local_20 [2];
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_408384f4);
  local_20[0] = 0xffffffff;
  iVar1 = FUN_40834758(param_3,local_20);
  if (iVar1 == 0) {
    uVar2 = 0x80070057;
  }
  else {
    uVar2 = (**(code **)(DAT_40838510 + 0xbc))
                      (*(undefined4 *)(param_1 + 8),param_2,local_20[0],param_4,param_5,param_6);
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_408384f4);
  return uVar2;
}



/* 40834954 FUN_40834954 */

/* Boundary evidence: original MIPS .pdata 40834954..408349bf. Semantic name remains unreviewed. */

undefined4 FUN_40834954(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_408384f4);
  uVar1 = (**(code **)(DAT_40838510 + 0xc0))(*(undefined4 *)(param_1 + 8),param_2);
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_408384f4);
  return uVar1;
}



/* 408349c0 FUN_408349c0 */

/* Boundary evidence: original MIPS .pdata 408349c0..40834a67. Semantic name remains unreviewed. */

undefined4 FUN_408349c0(int param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 local_20 [2];
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_408384f4);
  local_20[0] = 0xffffffff;
  iVar1 = FUN_40834758(param_2,local_20);
  if (iVar1 == 0) {
    uVar2 = 0x80070057;
  }
  else {
    uVar2 = (**(code **)(DAT_40838510 + 0x78))(*(undefined4 *)(param_1 + 8),local_20[0],param_3);
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_408384f4);
  return uVar2;
}



/* 40834a68 FUN_40834a68 */

/* Boundary evidence: original MIPS .pdata 40834a68..40834ad3. Semantic name remains unreviewed. */

undefined4 FUN_40834a68(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_408384f4);
  uVar1 = (**(code **)(DAT_40838510 + 0x74))(*(undefined4 *)(param_1 + 8),param_2);
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_408384f4);
  return uVar1;
}



/* 40834ad4 FUN_40834ad4 */

/* Boundary evidence: original MIPS .pdata 40834ad4..40834b37. Semantic name remains unreviewed. */

undefined4 FUN_40834ad4(int param_1,int *param_2,undefined4 *param_3)

{
  if (param_1 != 0) {
    *param_2 = param_1;
    *param_3 = *(undefined4 *)(param_1 + 8);
  }
  return 1;
}



/* 40834b38 FUN_40834b38 */

/* Boundary evidence: original MIPS .pdata 40834b38..40834b43. Semantic name remains unreviewed. */

undefined4 FUN_40834b38(void)

{
  return 1;
}



/* 40834b44 FUN_40834b44 */

/* Boundary evidence: original MIPS .pdata 40834b44..40834c3b. Semantic name remains unreviewed. */

undefined4 FUN_40834b44(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 local_18;
  int *local_14;
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_408384f4);
  local_18 = 0xffffffff;
  local_14 = (int *)0x0;
  if ((param_2 == 0) && (*(int *)(param_1 + 0x14) == 0)) {
    uVar2 = 0x88760238;
  }
  else {
    if (*(int **)(param_1 + 0x14) != (int *)0x0) {
      (**(code **)(**(int **)(param_1 + 0x14) + 8))();
      *(undefined4 *)(param_1 + 0x14) = 0;
    }
    iVar1 = FUN_40834ad4(param_2,(int *)&local_14,&local_18);
    if (iVar1 == 0) {
      uVar2 = 0x80070057;
    }
    else {
      uVar2 = (**(code **)(DAT_40838510 + 0xd8))(*(undefined4 *)(param_1 + 8),local_18);
      *(int **)(param_1 + 0x14) = local_14;
      if (local_14 != (int *)0x0) {
        (**(code **)(*local_14 + 4))();
      }
    }
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_408384f4);
  return uVar2;
}



/* 40834c3c FUN_40834c3c */

/* Boundary evidence: original MIPS .pdata 40834c3c..40834c77. Semantic name remains unreviewed. */

undefined4 FUN_40834c3c(void)

{
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_408384f4);
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_408384f4);
  return 0x80004001;
}



/* 40834c78 FUN_40834c78 */

/* Boundary evidence: original MIPS .pdata 40834c78..40834cb3. Semantic name remains unreviewed. */

undefined4 FUN_40834c78(void)

{
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_408384f4);
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_408384f4);
  return 0x80004001;
}



/* 40834cb4 FUN_40834cb4 */

/* Boundary evidence: original MIPS .pdata 40834cb4..40834d2f. Semantic name remains unreviewed. */

undefined4 FUN_40834cb4(int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_408384f4);
  uVar1 = (**(code **)(DAT_40838510 + 0x50))(*(undefined4 *)(param_1 + 8),param_3,param_2);
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_408384f4);
  return uVar1;
}



/* 40834d30 FUN_40834d30 */

/* Boundary evidence: original MIPS .pdata 40834d30..40834dd3. Semantic name remains unreviewed. */

undefined4
FUN_40834d30(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,int param_5)

{
  undefined4 uVar1;
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_408384f4);
  if (param_5 == 0) {
    uVar1 = (**(code **)(DAT_40838510 + 0x58))(*(undefined4 *)(param_1 + 8),param_3,param_2,param_4)
    ;
  }
  else {
    uVar1 = 0x80070057;
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_408384f4);
  return uVar1;
}



/* 40834dd4 FUN_40834dd4 */

/* Boundary evidence: original MIPS .pdata 40834dd4..40834e3f. Semantic name remains unreviewed. */

undefined4 FUN_40834dd4(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_408384f4);
  uVar1 = (**(code **)(DAT_40838510 + 0x5c))(*(undefined4 *)(param_1 + 8),param_2);
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_408384f4);
  return uVar1;
}



/* 40834e40 FUN_40834e40 */

/* Boundary evidence: original MIPS .pdata 40834e40..40834eab. Semantic name remains unreviewed. */

undefined4 FUN_40834e40(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_408384f4);
  uVar1 = (**(code **)(DAT_40838510 + 0x60))(*(undefined4 *)(param_1 + 8),param_2);
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_408384f4);
  return uVar1;
}



/* 40834eac FUN_40834eac */

/* Boundary evidence: original MIPS .pdata 40834eac..40834f17. Semantic name remains unreviewed. */

undefined4 FUN_40834eac(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_408384f4);
  uVar1 = (**(code **)(DAT_40838510 + 100))(*(undefined4 *)(param_1 + 8),param_2);
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_408384f4);
  return uVar1;
}



/* 40834f18 FUN_40834f18 */

/* Boundary evidence: original MIPS .pdata 40834f18..40834f73. Semantic name remains unreviewed. */

undefined4 FUN_40834f18(int param_1)

{
  undefined4 uVar1;
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_408384f4);
  uVar1 = (**(code **)(DAT_40838510 + 0x6c))(*(undefined4 *)(param_1 + 8));
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_408384f4);
  return uVar1;
}



/* 40834f74 FUN_40834f74 */

/* Boundary evidence: original MIPS .pdata 40834f74..40834fcf. Semantic name remains unreviewed. */

undefined4 FUN_40834f74(int param_1)

{
  undefined4 uVar1;
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_408384f4);
  uVar1 = (**(code **)(DAT_40838510 + 0x68))(*(undefined4 *)(param_1 + 8));
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_408384f4);
  return uVar1;
}



/* 40834fd0 FUN_40834fd0 */

/* Boundary evidence: original MIPS .pdata 40834fd0..4083503b. Semantic name remains unreviewed. */

undefined4 FUN_40834fd0(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_408384f4);
  uVar1 = (**(code **)(DAT_40838510 + 0x80))(*(undefined4 *)(param_1 + 8),param_2);
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_408384f4);
  return uVar1;
}



/* 4083503c FUN_4083503c */

/* Boundary evidence: original MIPS .pdata 4083503c..408350b7. Semantic name remains unreviewed. */

undefined4 FUN_4083503c(int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_408384f4);
  uVar1 = (**(code **)(DAT_40838510 + 0x88))(*(undefined4 *)(param_1 + 8),param_2,param_3);
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_408384f4);
  return uVar1;
}



/* 408350b8 FUN_408350b8 */

/* Boundary evidence: original MIPS .pdata 408350b8..40835133. Semantic name remains unreviewed. */

undefined4 FUN_408350b8(int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_408384f4);
  uVar1 = (**(code **)(DAT_40838510 + 0x8c))(*(undefined4 *)(param_1 + 8),param_2,param_3);
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_408384f4);
  return uVar1;
}



/* 40835134 FUN_40835134 */

/* Boundary evidence: original MIPS .pdata 40835134..4083520b. Semantic name remains unreviewed. */

undefined4
FUN_40835134(int param_1,undefined4 param_2,int param_3,undefined4 param_4,undefined4 param_5,
            undefined4 param_6)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 local_20 [2];
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_408384f4);
  if (param_3 == 0) {
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_408384f4);
    uVar2 = 0x80070057;
  }
  else {
    iVar1 = FUN_40834758(param_3,local_20);
    if (iVar1 == 0) {
      uVar2 = 0x80070057;
    }
    else {
      uVar2 = (**(code **)(DAT_40838510 + 0x90))
                        (*(undefined4 *)(param_1 + 8),param_2,local_20[0],param_4,param_5,param_6);
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_408384f4);
  }
  return uVar2;
}



/* 4083520c FUN_4083520c */

/* Boundary evidence: original MIPS .pdata 4083520c..408352e3. Semantic name remains unreviewed. */

undefined4 FUN_4083520c(int param_1,int param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 local_20 [2];
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_408384f4);
  local_20[0] = 0xffffffff;
  if ((param_2 == 4) || (param_2 == 5)) {
    if (param_3 == 0) {
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_408384f4);
      return 0x80070057;
    }
    iVar1 = FUN_40834758(param_3,local_20);
    if (iVar1 == 0) {
      uVar2 = 0x80070057;
      goto LAB_408352bc;
    }
  }
  uVar2 = (**(code **)(DAT_40838510 + 0x94))(*(undefined4 *)(param_1 + 8),param_2,local_20[0]);
LAB_408352bc:
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_408384f4);
  return uVar2;
}



/* 408352e4 FUN_408352e4 */

/* Boundary evidence: original MIPS .pdata 408352e4..4083534b. Semantic name remains unreviewed. */

void FUN_408352e4(undefined *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  (*(code *)param_1)(param_2,param_3,param_4);
  return;
}



/* 4083534c FUN_4083534c */

/* Boundary evidence: original MIPS .pdata 4083534c..40835357. Semantic name remains unreviewed. */

undefined4 FUN_4083534c(void)

{
  return 1;
}



/* 40835358 FUN_40835358 */

/* Boundary evidence: original MIPS .pdata 40835358..408353a3. Semantic name remains unreviewed. */

void FUN_40835358(undefined4 *param_1,undefined4 param_2)

{
  *param_1 = param_2;
  return;
}



/* 408353a4 FUN_408353a4 */

/* Boundary evidence: original MIPS .pdata 408353a4..408353af. Semantic name remains unreviewed. */

undefined4 FUN_408353a4(void)

{
  return 1;
}



/* 408353b0 FUN_408353b0 */

/* Boundary evidence: original MIPS .pdata 408353b0..40835413. Semantic name remains unreviewed. */

void FUN_408353b0(void *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 local_res4;
  undefined4 local_res8;
  undefined4 local_resc;
  
  local_res4 = param_2;
  local_res8 = param_3;
  local_resc = param_4;
  memcpy(param_1,&local_res4,0x20);
  return;
}



/* 40835414 FUN_40835414 */

/* Boundary evidence: original MIPS .pdata 40835414..4083541f. Semantic name remains unreviewed. */

undefined4 FUN_40835414(void)

{
  return 1;
}



/* 40835420 FUN_40835420 */

/* Boundary evidence: original MIPS .pdata 40835420..4083546f. Semantic name remains unreviewed. */

void FUN_40835420(undefined4 *param_1,undefined4 param_2,undefined4 param_3)

{
  *param_1 = param_2;
  param_1[1] = param_3;
  return;
}



/* 40835470 FUN_40835470 */

/* Boundary evidence: original MIPS .pdata 40835470..4083547b. Semantic name remains unreviewed. */

undefined4 FUN_40835470(void)

{
  return 1;
}



/* 4083547c FUN_4083547c */

/* Boundary evidence: original MIPS .pdata 4083547c..408354c7. Semantic name remains unreviewed. */

void FUN_4083547c(undefined4 *param_1,undefined4 param_2)

{
  *param_1 = param_2;
  return;
}



/* 408354c8 FUN_408354c8 */

/* Boundary evidence: original MIPS .pdata 408354c8..408354d3. Semantic name remains unreviewed. */

undefined4 FUN_408354c8(void)

{
  return 1;
}



/* 408354d4 FUN_408354d4 */

/* Boundary evidence: original MIPS .pdata 408354d4..4083551f. Semantic name remains unreviewed. */

void FUN_408354d4(undefined4 *param_1,undefined4 param_2)

{
  *param_1 = param_2;
  return;
}



/* 40835520 FUN_40835520 */

/* Boundary evidence: original MIPS .pdata 40835520..4083552b. Semantic name remains unreviewed. */

undefined4 FUN_40835520(void)

{
  return 1;
}



/* 4083552c FUN_4083552c */

/* Boundary evidence: original MIPS .pdata 4083552c..408355a3. Semantic name remains unreviewed. */

int FUN_4083552c(undefined4 *param_1)

{
  int iVar1;
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_408384f4);
  InterlockedDecrement(param_1 + 1);
  iVar1 = param_1[1];
  if (iVar1 == 0) {
    FUN_40834620(param_1);
    operator_delete(param_1);
    iVar1 = 0;
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_408384f4);
  return iVar1;
}



/* 408355a4 FUN_408355a4 */

/* Boundary evidence: original MIPS .pdata 408355a4..40835637. Semantic name remains unreviewed. */

undefined4 FUN_408355a4(int param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_408384f4);
  uVar2 = 0;
  if ((param_2 == (undefined4 *)0x0) ||
     (iVar1 = FUN_408317a4(param_2,*(undefined4 *)(param_1 + 0xc)), iVar1 == 0)) {
    uVar2 = 0x80070057;
  }
  else {
    (**(code **)(**(int **)(param_1 + 0xc) + 4))();
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_408384f4);
  return uVar2;
}



/* 40835638 FUN_40835638 */

/* Boundary evidence: original MIPS .pdata 40835638..4083571b. Semantic name remains unreviewed. */

int FUN_40835638(int *param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 local_88;
  uint local_84;
  undefined4 local_24;
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_408384f4);
  if (param_2 != (undefined4 *)0x0) {
    memset(&local_88,0,0x6c);
    local_88 = 0x6c;
    iVar1 = (**(code **)(*param_1 + 0x44))(param_1,&local_88);
    if ((iVar1 < 0) || ((local_84 & 1) == 0)) {
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_408384f4);
      return iVar1;
    }
    iVar1 = FUN_40835358(param_2,local_24);
    if (iVar1 != 0) {
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_408384f4);
      return 0;
    }
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_408384f4);
  return -0x7ff8ffa9;
}



/* 4083571c FUN_4083571c */

/* Boundary evidence: original MIPS .pdata 4083571c..4083582f. Semantic name remains unreviewed. */

int FUN_4083571c(int *param_1,void *param_2)

{
  int iVar1;
  undefined4 local_88;
  uint local_84;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_408384f4);
  if (param_2 != (void *)0x0) {
    memset(&local_88,0,0x6c);
    local_88 = 0x6c;
    iVar1 = (**(code **)(*param_1 + 0x44))(param_1,&local_88);
    if ((iVar1 < 0) || ((local_84 & 0x1000) == 0)) {
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_408384f4);
      return iVar1;
    }
    iVar1 = FUN_408353b0(param_2,local_44,local_40,local_3c);
    if (iVar1 != 0) {
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_408384f4);
      return 0;
    }
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_408384f4);
  return -0x7ff8ffa9;
}



/* 40835830 FUN_40835830 */

/* Boundary evidence: original MIPS .pdata 40835830..408358d3. Semantic name remains unreviewed. */

undefined4 FUN_40835830(int param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_408384f4);
  if (param_2 != (undefined4 *)0x0) {
    if (*(int *)(param_1 + 0x14) == 0) {
      uVar2 = 0x88760238;
      goto LAB_408358b0;
    }
    iVar1 = FUN_40832340(param_2,*(int *)(param_1 + 0x14));
    if (iVar1 != 0) {
      (**(code **)(**(int **)(param_1 + 0x14) + 4))();
      uVar2 = 0;
      goto LAB_408358b0;
    }
  }
  uVar2 = 0x80070057;
LAB_408358b0:
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_408384f4);
  return uVar2;
}



/* 408358d4 FUN_408358d4 */

/* Boundary evidence: original MIPS .pdata 408358d4..40835a43. Semantic name remains unreviewed. */

int FUN_408358d4(int *param_1,int param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 local_88;
  uint local_84;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_408384f4);
  if (param_3 != (undefined4 *)0x0) {
    memset(&local_88,0,0x6c);
    local_88 = 0x6c;
    iVar1 = (**(code **)(*param_1 + 0x44))(param_1,&local_88);
    if (iVar1 < 0) goto LAB_40835a18;
    if (param_2 == 2) {
      local_84 = local_84 & 0x4000;
    }
    else if (param_2 == 4) {
      local_84 = local_84 & 0x2000;
      local_5c = local_64;
      local_58 = local_60;
    }
    else if (param_2 == 8) {
      local_84 = local_84 & 0x10000;
      local_5c = local_4c;
      local_58 = local_48;
    }
    else {
      if (param_2 != 0x10) goto LAB_4083597c;
      local_84 = local_84 & 0x8000;
      local_5c = local_54;
      local_58 = local_50;
    }
    if (local_84 == 0) {
      iVar1 = -0x7789fe70;
      goto LAB_40835a18;
    }
    iVar1 = FUN_40835420(param_3,local_5c,local_58);
    if (iVar1 != 0) {
      iVar1 = 0;
      goto LAB_40835a18;
    }
  }
LAB_4083597c:
  iVar1 = -0x7ff8ffa9;
LAB_40835a18:
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_408384f4);
  return iVar1;
}



/* 40835a44 FUN_40835a44 */

/* Boundary evidence: original MIPS .pdata 40835a44..40835a9f. Semantic name remains unreviewed. */

undefined4 * FUN_40835a44(undefined4 *param_1,undefined4 param_2,int *param_3,undefined1 param_4)

{
  *param_1 = &PTR_FUN_40831194;
  param_1[1] = 1;
  param_1[2] = param_2;
  param_1[3] = param_3;
  *(undefined1 *)(param_1 + 4) = param_4;
  param_1[5] = 0;
  if (param_3 != (int *)0x0) {
    (**(code **)(*param_3 + 4))(param_3);
  }
  return param_1;
}



/* 40835aa0 FUN_40835aa0 */

/* Boundary evidence: original MIPS .pdata 40835aa0..40835da7. Semantic name remains unreviewed. */

int FUN_40835aa0(int *param_1,void *param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 *puVar2;
  int *piVar3;
  int iVar4;
  code *pcVar5;
  int local_28;
  int local_24;
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_408384f4);
  if ((param_3 == (undefined4 *)0x0) || (iVar1 = FUN_40832398(param_3,0), iVar1 == 0)) {
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_408384f4);
    return -0x7ff8ffa9;
  }
  iVar1 = FUN_40831f50(param_2,&DAT_4083127c);
  if (iVar1 == 0) {
    iVar1 = FUN_40831f50(param_2,&DAT_4083129c);
    if (iVar1 != 0) {
      iVar1 = FUN_4083346c(param_3,param_1);
      goto LAB_40835b74;
    }
    iVar1 = FUN_40831f50(param_2,&DAT_408312cc);
    if (iVar1 != 0) {
      iVar1 = (**(code **)(DAT_40838510 + 0x98))(param_1[2],&local_28);
      if (-1 < iVar1) {
        if (local_28 != -1) {
          puVar2 = operator_new(0x10);
          if (puVar2 == (undefined4 *)0x0) {
            piVar3 = (int *)0x0;
          }
          else {
            piVar3 = FUN_40836ee4(puVar2,local_28,param_1);
          }
          if (piVar3 == (int *)0x0) {
            iVar1 = -0x7ff8fff2;
          }
          if (-1 < iVar1) {
            iVar4 = FUN_4083547c(param_3,piVar3);
            if (iVar4 == 0) {
              iVar1 = -0x7ff8ffa9;
            }
            if (-1 < iVar1) goto LAB_40835d78;
          }
          pcVar5 = *(code **)(DAT_40838510 + 0x9c);
LAB_40835c70:
          (*pcVar5)(local_28);
          if (piVar3 != (int *)0x0) {
            (**(code **)(*piVar3 + 8))(piVar3);
          }
          goto LAB_40835d78;
        }
LAB_40835bf0:
        iVar1 = -0x7fffbffb;
        goto LAB_40835d78;
      }
LAB_40835bc4:
      if (iVar1 != -0x7fffbfff) goto LAB_40835d78;
LAB_40835d70:
      iVar1 = -0x7fffbffe;
      goto LAB_40835d78;
    }
    iVar1 = FUN_40831f50(param_2,&DAT_408312dc);
    if (iVar1 != 0) {
      iVar1 = (**(code **)(DAT_40838510 + 0xa8))(param_1[2],&local_24);
      if (-1 < iVar1) {
        if (local_24 != -1) {
          puVar2 = operator_new(0x10);
          if (puVar2 == (undefined4 *)0x0) {
            piVar3 = (int *)0x0;
          }
          else {
            piVar3 = FUN_40836e18(puVar2,local_24,param_1);
          }
          if (piVar3 == (int *)0x0) {
            iVar1 = -0x7ff8fff2;
          }
          if (-1 < iVar1) {
            iVar4 = FUN_408354d4(param_3,piVar3);
            if (iVar4 == 0) {
              iVar1 = -0x7ff8fff2;
            }
            if (-1 < iVar1) goto LAB_40835d78;
          }
          pcVar5 = *(code **)(DAT_40838510 + 0xac);
          local_28 = local_24;
          goto LAB_40835c70;
        }
        goto LAB_40835bf0;
      }
      goto LAB_40835bc4;
    }
    iVar1 = FUN_40832398(param_3,0);
    if (iVar1 != 0) goto LAB_40835d70;
  }
  else {
    iVar1 = FUN_408323f0(param_3,param_1);
LAB_40835b74:
    if (iVar1 != 0) {
      (**(code **)(*param_1 + 4))(param_1);
      iVar1 = 0;
      goto LAB_40835d78;
    }
  }
  iVar1 = -0x7ff8ffa9;
LAB_40835d78:
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_408384f4);
  return iVar1;
}



/* 40835da8 FUN_40835da8 */

/* Boundary evidence: original MIPS .pdata 40835da8..40835fcb. Semantic name remains unreviewed. */

int FUN_40835da8(int *param_1,uint param_2,undefined4 *param_3,uint param_4,undefined4 param_5,
                undefined *param_6)

{
  undefined4 *puVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  int *local_a8;
  int *local_a4;
  uint local_a0;
  undefined4 local_98 [28];
  
  iVar3 = 0;
  uVar5 = 0;
  local_a4 = param_1;
  if (param_2 != 0) {
    local_a0 = param_4 & 0x10;
    puVar6 = param_3;
    puVar7 = param_3;
    do {
      if (local_a0 == 0) {
        piVar2 = (int *)0x0;
        puVar1 = puVar6;
      }
      else {
        uVar4 = *puVar7;
        iVar3 = (**(code **)(DAT_40838510 + 0xe0))(uVar4,&local_a8);
        piVar2 = local_a8;
        if (iVar3 < 0) break;
        if (local_a8 == (int *)0x0) {
          puVar1 = operator_new(0x18);
          if (puVar1 == (undefined4 *)0x0) {
            piVar2 = (int *)0x0;
          }
          else {
            piVar2 = FUN_40835a44(puVar1,uVar4,local_a4,1);
          }
          if (piVar2 == (int *)0x0) {
            iVar3 = -0x7ff8fff2;
            break;
          }
          iVar3 = (**(code **)(DAT_40838510 + 0xe4))(uVar4,piVar2);
          if (iVar3 < 0) break;
        }
        else {
          (**(code **)(*local_a8 + 4))(local_a8);
        }
        memset(local_98,0,0x6c);
        local_98[0] = 0x6c;
        iVar3 = (**(code **)(*piVar2 + 0x44))(piVar2,local_98);
        if (iVar3 < 0) {
          (**(code **)(*piVar2 + 8))(piVar2);
          break;
        }
        puVar1 = local_98;
      }
      iVar3 = FUN_408352e4(param_6,piVar2,puVar1,param_5);
      if (iVar3 < 0) break;
      if (iVar3 != 1) {
        if (iVar3 == 0) {
          iVar3 = 0;
        }
        else {
          iVar3 = -0x7fffbffb;
        }
        break;
      }
      uVar5 = uVar5 + 1;
      iVar3 = 0;
      puVar7 = puVar7 + 1;
      puVar6 = puVar6 + 0x1b;
    } while (uVar5 < param_2);
  }
  if (param_3 != (undefined4 *)0x0) {
    LocalFree(param_3);
  }
  return iVar3;
}



/* 40835fcc FUN_40835fcc */

/* Boundary evidence: original MIPS .pdata 40835fcc..4083608b. Semantic name remains unreviewed. */

int FUN_40835fcc(int param_1,undefined4 param_2,undefined *param_3)

{
  int iVar1;
  undefined4 *local_20;
  uint local_1c;
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_408384f4);
  if (param_3 == (undefined *)0x0) {
    iVar1 = -0x7ff8ffa9;
  }
  else {
    iVar1 = (**(code **)(DAT_40838510 + 0x70))(*(undefined4 *)(param_1 + 8),&local_1c,&local_20);
    if (-1 < iVar1) {
      iVar1 = FUN_40835da8(*(int **)(param_1 + 0xc),local_1c,local_20,0x10,param_2,param_3);
    }
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_408384f4);
  return iVar1;
}



/* 4083608c FUN_4083608c */

/* Boundary evidence: original MIPS .pdata 4083608c..40836153. Semantic name remains unreviewed. */

int FUN_4083608c(int param_1,undefined4 param_2,undefined4 param_3,undefined *param_4)

{
  int iVar1;
  undefined4 *local_20;
  uint local_1c;
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_408384f4);
  if (param_4 == (undefined *)0x0) {
    iVar1 = -0x7ff8ffa9;
  }
  else {
    iVar1 = (**(code **)(DAT_40838510 + 0x84))
                      (*(undefined4 *)(param_1 + 8),&local_1c,&local_20,param_2);
    if (-1 < iVar1) {
      iVar1 = FUN_40835da8(*(int **)(param_1 + 0xc),local_1c,local_20,0x10,param_3,param_4);
    }
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_408384f4);
  return iVar1;
}



/* 40836154 FUN_40836154 */

/* Boundary evidence: original MIPS .pdata 40836154..408361af. Semantic name remains unreviewed. */

void FUN_40836154(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_40831210;
  (**(code **)(DAT_40838510 + 0x100))(param_1[2]);
  if ((int *)param_1[3] != (int *)0x0) {
    (**(code **)(*(int *)param_1[3] + 8))();
  }
  return;
}



/* 408361b0 FUN_408361b0 */

/* Boundary evidence: original MIPS .pdata 408361b0..408361db. Semantic name remains unreviewed. */

LONG FUN_408361b0(int param_1)

{
  InterlockedIncrement((LONG *)(param_1 + 4));
  return *(LONG *)(param_1 + 4);
}



/* 408361dc FUN_408361dc */

/* Boundary evidence: original MIPS .pdata 408361dc..40836297. Semantic name remains unreviewed. */

undefined4 FUN_408361dc(int param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 local_20 [2];
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_408384f4);
  if (param_2 == 0) {
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_408384f4);
    uVar2 = 0x80070057;
  }
  else {
    local_20[0] = 0;
    iVar1 = FUN_40834758(param_2,local_20);
    if (iVar1 == 0) {
      uVar2 = 0x80070057;
    }
    else {
      uVar2 = (**(code **)(DAT_40838510 + 0xfc))(*(undefined4 *)(param_1 + 8),local_20[0],param_3);
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_408384f4);
  }
  return uVar2;
}



/* 40836298 FUN_40836298 */

/* Boundary evidence: original MIPS .pdata 40836298..40836333. Semantic name remains unreviewed. */

undefined4
FUN_40836298(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5
            ,undefined4 param_6)

{
  undefined4 uVar1;
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_408384f4);
  uVar1 = (**(code **)(DAT_40838510 + 0x104))
                    (*(undefined4 *)(param_1 + 8),param_2,param_3,param_4,param_5,param_6);
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_408384f4);
  return uVar1;
}



/* 40836334 FUN_40836334 */

/* Boundary evidence: original MIPS .pdata 40836334..4083639f. Semantic name remains unreviewed. */

undefined4 FUN_40836334(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_408384f4);
  uVar1 = (**(code **)(DAT_40838510 + 0x108))(*(undefined4 *)(param_1 + 8),param_2);
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_408384f4);
  return uVar1;
}



/* 408363a0 FUN_408363a0 */

/* Boundary evidence: original MIPS .pdata 408363a0..4083642b. Semantic name remains unreviewed. */

undefined4 FUN_408363a0(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_408384f4);
  uVar1 = (**(code **)(DAT_40838510 + 0x10c))(*(undefined4 *)(param_1 + 8),param_2,param_3,param_4);
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_408384f4);
  return uVar1;
}



/* 4083642c FUN_4083642c */

/* Boundary evidence: original MIPS .pdata 4083642c..408364bf. Semantic name remains unreviewed. */

undefined4
FUN_4083642c(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5
            )

{
  undefined4 uVar1;
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_408384f4);
  uVar1 = (**(code **)(DAT_40838510 + 0x110))
                    (*(undefined4 *)(param_1 + 8),param_2,param_3,param_4,param_5);
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_408384f4);
  return uVar1;
}



/* 408364c0 FUN_408364c0 */

/* Boundary evidence: original MIPS .pdata 408364c0..4083652b. Semantic name remains unreviewed. */

undefined4 FUN_408364c0(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_408384f4);
  uVar1 = (**(code **)(DAT_40838510 + 0x114))(*(undefined4 *)(param_1 + 8),param_2);
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_408384f4);
  return uVar1;
}



/* 4083652c FUN_4083652c */

/* Boundary evidence: original MIPS .pdata 4083652c..40836597. Semantic name remains unreviewed. */

undefined4 FUN_4083652c(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_408384f4);
  uVar1 = (**(code **)(DAT_40838510 + 0x118))(*(undefined4 *)(param_1 + 8),param_2);
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_408384f4);
  return uVar1;
}



/* 40836598 FUN_40836598 */

/* Boundary evidence: original MIPS .pdata 40836598..40836603. Semantic name remains unreviewed. */

undefined4 FUN_40836598(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_408384f4);
  uVar1 = (**(code **)(DAT_40838510 + 0x11c))(*(undefined4 *)(param_1 + 8),param_2);
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_408384f4);
  return uVar1;
}



/* 40836604 FUN_40836604 */

/* Boundary evidence: original MIPS .pdata 40836604..4083666f. Semantic name remains unreviewed. */

undefined4 FUN_40836604(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_408384f4);
  uVar1 = (**(code **)(DAT_40838510 + 0x120))(*(undefined4 *)(param_1 + 8),param_2);
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_408384f4);
  return uVar1;
}



/* 40836670 FUN_40836670 */

/* Boundary evidence: original MIPS .pdata 40836670..4083672b. Semantic name remains unreviewed. */

undefined4 FUN_40836670(int param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 local_20 [2];
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_408384f4);
  if (param_2 == 0) {
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_408384f4);
    uVar2 = 0x80070057;
  }
  else {
    local_20[0] = 0;
    iVar1 = FUN_40834758(param_2,local_20);
    if (iVar1 == 0) {
      uVar2 = 0x80070057;
    }
    else {
      uVar2 = (**(code **)(DAT_40838510 + 0x124))(*(undefined4 *)(param_1 + 8),local_20[0],param_3);
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_408384f4);
  }
  return uVar2;
}



/* 4083672c FUN_4083672c */

/* Boundary evidence: original MIPS .pdata 4083672c..40836797. Semantic name remains unreviewed. */

undefined4 FUN_4083672c(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_408384f4);
  uVar1 = (**(code **)(DAT_40838510 + 0x128))(*(undefined4 *)(param_1 + 8),param_2);
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_408384f4);
  return uVar1;
}



/* 40836798 FUN_40836798 */

/* Boundary evidence: original MIPS .pdata 40836798..408367f3. Semantic name remains unreviewed. */

undefined4 FUN_40836798(int param_1)

{
  undefined4 uVar1;
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_408384f4);
  uVar1 = (**(code **)(DAT_40838510 + 300))(*(undefined4 *)(param_1 + 8));
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_408384f4);
  return uVar1;
}



/* 408367f4 FUN_408367f4 */

/* Boundary evidence: original MIPS .pdata 408367f4..4083685f. Semantic name remains unreviewed. */

undefined4 FUN_408367f4(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_408384f4);
  uVar1 = (**(code **)(DAT_40838510 + 0x130))(*(undefined4 *)(param_1 + 8),param_2);
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_408384f4);
  return uVar1;
}



/* 40836860 FUN_40836860 */

/* Boundary evidence: original MIPS .pdata 40836860..408368eb. Semantic name remains unreviewed. */

undefined4 FUN_40836860(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_408384f4);
  uVar1 = (**(code **)(DAT_40838510 + 0x134))(*(undefined4 *)(param_1 + 8),param_2,param_3,param_4);
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_408384f4);
  return uVar1;
}



/* 408368ec FUN_408368ec */

/* Boundary evidence: original MIPS .pdata 408368ec..40836963. Semantic name remains unreviewed. */

int FUN_408368ec(undefined4 *param_1)

{
  int iVar1;
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_408384f4);
  InterlockedDecrement(param_1 + 1);
  iVar1 = param_1[1];
  if (iVar1 == 0) {
    FUN_40836154(param_1);
    operator_delete(param_1);
    iVar1 = 0;
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_408384f4);
  return iVar1;
}



/* 40836964 FUN_40836964 */

/* Boundary evidence: original MIPS .pdata 40836964..408369b7. Semantic name remains unreviewed. */

undefined4 * FUN_40836964(undefined4 *param_1,undefined4 param_2,int *param_3)

{
  *param_1 = &PTR_FUN_40831210;
  param_1[1] = 1;
  param_1[2] = param_2;
  param_1[3] = param_3;
  if (param_3 != (int *)0x0) {
    (**(code **)(*param_3 + 4))(param_3);
  }
  return param_1;
}



/* 408369b8 FUN_408369b8 */

/* Boundary evidence: original MIPS .pdata 408369b8..40836abf. Semantic name remains unreviewed. */

undefined4 FUN_408369b8(int *param_1,void *param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_408384f4);
  if (param_3 == (undefined4 *)0x0) {
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_408384f4);
    return 0x80070057;
  }
  iVar1 = FUN_40831f50(param_2,&DAT_4083127c);
  if (iVar1 == 0) {
    iVar1 = FUN_40831f50(param_2,&DAT_408312fc);
    if (iVar1 != 0) {
      iVar1 = FUN_4083358c(param_3,param_1);
      goto LAB_40836a6c;
    }
    iVar1 = FUN_40832398(param_3,0);
    if (iVar1 != 0) {
      uVar2 = 0x80004002;
      goto LAB_40836a98;
    }
  }
  else {
    iVar1 = FUN_408323f0(param_3,param_1);
LAB_40836a6c:
    if (iVar1 != 0) {
      (**(code **)(*param_1 + 4))(param_1);
      uVar2 = 0;
      goto LAB_40836a98;
    }
  }
  uVar2 = 0x80070057;
LAB_40836a98:
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_408384f4);
  return uVar2;
}



/* 40836ac0 FUN_40836ac0 */

/* Boundary evidence: original MIPS .pdata 40836ac0..40836b1b. Semantic name remains unreviewed. */

void FUN_40836ac0(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_40831254;
  (**(code **)(DAT_40838510 + 0x9c))(param_1[2]);
  if ((int *)param_1[3] != (int *)0x0) {
    (**(code **)(*(int *)param_1[3] + 8))();
  }
  return;
}



/* 40836b1c FUN_40836b1c */

/* Boundary evidence: original MIPS .pdata 40836b1c..40836b47. Semantic name remains unreviewed. */

LONG FUN_40836b1c(int param_1)

{
  InterlockedIncrement((LONG *)(param_1 + 4));
  return *(LONG *)(param_1 + 4);
}



/* 40836b48 FUN_40836b48 */

/* Boundary evidence: original MIPS .pdata 40836b48..40836bb3. Semantic name remains unreviewed. */

undefined4 FUN_40836b48(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_408384f4);
  uVar1 = (**(code **)(DAT_40838510 + 0xa0))(*(undefined4 *)(param_1 + 8),param_2);
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_408384f4);
  return uVar1;
}



/* 40836bb4 FUN_40836bb4 */

/* Boundary evidence: original MIPS .pdata 40836bb4..40836c1f. Semantic name remains unreviewed. */

undefined4 FUN_40836bb4(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_408384f4);
  uVar1 = (**(code **)(DAT_40838510 + 0xa4))(*(undefined4 *)(param_1 + 8),param_2);
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_408384f4);
  return uVar1;
}



/* 40836c20 FUN_40836c20 */

/* Boundary evidence: original MIPS .pdata 40836c20..40836c7b. Semantic name remains unreviewed. */

void FUN_40836c20(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_40831268;
  (**(code **)(DAT_40838510 + 0xac))(param_1[2]);
  if ((int *)param_1[3] != (int *)0x0) {
    (**(code **)(*(int *)param_1[3] + 8))();
  }
  return;
}



/* 40836c7c FUN_40836c7c */

/* Boundary evidence: original MIPS .pdata 40836c7c..40836ca7. Semantic name remains unreviewed. */

LONG FUN_40836c7c(int param_1)

{
  InterlockedIncrement((LONG *)(param_1 + 4));
  return *(LONG *)(param_1 + 4);
}



/* 40836ca8 FUN_40836ca8 */

/* Boundary evidence: original MIPS .pdata 40836ca8..40836d23. Semantic name remains unreviewed. */

undefined4 FUN_40836ca8(int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_408384f4);
  uVar1 = (**(code **)(DAT_40838510 + 0xb0))(*(undefined4 *)(param_1 + 8),param_2,param_3);
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_408384f4);
  return uVar1;
}



/* 40836d24 FUN_40836d24 */

/* Boundary evidence: original MIPS .pdata 40836d24..40836d9f. Semantic name remains unreviewed. */

undefined4 FUN_40836d24(int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_408384f4);
  uVar1 = (**(code **)(DAT_40838510 + 0xb4))(*(undefined4 *)(param_1 + 8),param_2,param_3);
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_408384f4);
  return uVar1;
}



/* 40836da0 FUN_40836da0 */

/* Boundary evidence: original MIPS .pdata 40836da0..40836e17. Semantic name remains unreviewed. */

int FUN_40836da0(undefined4 *param_1)

{
  int iVar1;
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_408384f4);
  InterlockedDecrement(param_1 + 1);
  iVar1 = param_1[1];
  if (iVar1 == 0) {
    FUN_40836ac0(param_1);
    operator_delete(param_1);
    iVar1 = 0;
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_408384f4);
  return iVar1;
}



/* 40836e18 FUN_40836e18 */

/* Boundary evidence: original MIPS .pdata 40836e18..40836e6b. Semantic name remains unreviewed. */

undefined4 * FUN_40836e18(undefined4 *param_1,undefined4 param_2,int *param_3)

{
  *param_1 = &PTR_FUN_40831268;
  param_1[1] = 1;
  param_1[2] = param_2;
  param_1[3] = param_3;
  if (param_3 != (int *)0x0) {
    (**(code **)(*param_3 + 4))(param_3);
  }
  return param_1;
}



/* 40836e6c FUN_40836e6c */

/* Boundary evidence: original MIPS .pdata 40836e6c..40836ee3. Semantic name remains unreviewed. */

int FUN_40836e6c(undefined4 *param_1)

{
  int iVar1;
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_408384f4);
  InterlockedDecrement(param_1 + 1);
  iVar1 = param_1[1];
  if (iVar1 == 0) {
    FUN_40836c20(param_1);
    operator_delete(param_1);
    iVar1 = 0;
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_408384f4);
  return iVar1;
}



/* 40836ee4 FUN_40836ee4 */

/* Boundary evidence: original MIPS .pdata 40836ee4..40836f37. Semantic name remains unreviewed. */

undefined4 * FUN_40836ee4(undefined4 *param_1,undefined4 param_2,int *param_3)

{
  *param_1 = &PTR_FUN_40831254;
  param_1[1] = 1;
  param_1[2] = param_2;
  param_1[3] = param_3;
  if (param_3 != (int *)0x0) {
    (**(code **)(*param_3 + 4))(param_3);
  }
  return param_1;
}



/* 40836f38 FUN_40836f38 */

/* Boundary evidence: original MIPS .pdata 40836f38..4083703f. Semantic name remains unreviewed. */

undefined4 FUN_40836f38(int *param_1,void *param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_408384f4);
  if (param_3 == (undefined4 *)0x0) {
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_408384f4);
    return 0x80070057;
  }
  iVar1 = FUN_40831f50(param_2,&DAT_4083127c);
  if (iVar1 == 0) {
    iVar1 = FUN_40831f50(param_2,&DAT_408312cc);
    if (iVar1 != 0) {
      iVar1 = FUN_4083547c(param_3,param_1);
      goto LAB_40836fec;
    }
    iVar1 = FUN_40832398(param_3,0);
    if (iVar1 != 0) {
      uVar2 = 0x80004002;
      goto LAB_40837018;
    }
  }
  else {
    iVar1 = FUN_408323f0(param_3,param_1);
LAB_40836fec:
    if (iVar1 != 0) {
      (**(code **)(*param_1 + 4))(param_1);
      uVar2 = 0;
      goto LAB_40837018;
    }
  }
  uVar2 = 0x80070057;
LAB_40837018:
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_408384f4);
  return uVar2;
}



/* 40837040 FUN_40837040 */

/* Boundary evidence: original MIPS .pdata 40837040..40837147. Semantic name remains unreviewed. */

undefined4 FUN_40837040(int *param_1,void *param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_408384f4);
  if (param_3 == (undefined4 *)0x0) {
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_408384f4);
    return 0x80070057;
  }
  iVar1 = FUN_40831f50(param_2,&DAT_4083127c);
  if (iVar1 == 0) {
    iVar1 = FUN_40831f50(param_2,&DAT_408312dc);
    if (iVar1 != 0) {
      iVar1 = FUN_408354d4(param_3,param_1);
      goto LAB_408370f4;
    }
    iVar1 = FUN_40832398(param_3,0);
    if (iVar1 != 0) {
      uVar2 = 0x80004002;
      goto LAB_40837120;
    }
  }
  else {
    iVar1 = FUN_408323f0(param_3,param_1);
LAB_408370f4:
    if (iVar1 != 0) {
      (**(code **)(*param_1 + 4))(param_1);
      uVar2 = 0;
      goto LAB_40837120;
    }
  }
  uVar2 = 0x80070057;
LAB_40837120:
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_408384f4);
  return uVar2;
}



/* 40837278 FUN_40837278 */

/* Boundary evidence: original MIPS .pdata 40837278..408373b3. Semantic name remains unreviewed. */

int FUN_40837278(HMODULE param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 1;
  if (param_2 == 1) {
    if (DAT_40838524 != (code *)0x0) {
      iVar2 = (*DAT_40838524)(param_1,1,param_3);
    }
    iVar1 = 0;
    if (iVar2 == 0) goto LAB_40837328;
    FUN_4083770c();
  }
  iVar1 = 0;
  if (iVar2 != 0) {
    iVar1 = FUN_408313f0(param_1,param_2);
  }
LAB_40837328:
  if (((param_2 == 0) && (FUN_40837694(), iVar1 != 0)) && (DAT_40838524 != (code *)0x0)) {
    iVar1 = (*DAT_40838524)(param_1,0,param_3);
  }
  return iVar1;
}



/* 408373b4 FUN_408373b4 */

/* Boundary evidence: original MIPS .pdata 408373b4..408373df. Semantic name remains unreviewed. */

void FUN_408373b4(_EXCEPTION_POINTERS *param_1)

{
  _XcptFilter(param_1->ExceptionRecord->ExceptionCode,param_1);
  return;
}



/* 408373e0 entry */

/* Boundary evidence: original MIPS .pdata 408373e0..40837437. Semantic name remains unreviewed. */

void entry(HMODULE param_1,int param_2,undefined4 param_3)

{
  if (param_2 == 1) {
    FUN_40837438();
  }
  FUN_40837278(param_1,param_2,param_3);
  return;
}



/* 40837438 FUN_40837438 */

/* Boundary evidence: original MIPS .pdata 40837438..408374ab. Semantic name remains unreviewed. */

void FUN_40837438(void)

{
  uint uVar1;
  
  if ((DAT_408384ec == 0) || (DAT_408384ec == 0xb064)) {
    uVar1 = __security_gen_cookie2();
    DAT_408384ec = uVar1 >> 0x10 ^ uVar1 & 0xffff;
    if (DAT_408384ec == 0) {
      DAT_408384ec = 0xb064;
    }
  }
  DAT_408384f0 = ~DAT_408384ec;
  return;
}



/* 408374ac FUN_408374ac */

/* Boundary evidence: original MIPS .pdata 408374ac..408374ff. Semantic name remains unreviewed. */

void FUN_408374ac(int param_1,undefined4 param_2,uint *param_3)

{
  if ((*param_3 & 1) != 0) {
    param_1 = ((-param_3[2] & param_3[1] + param_1) - (param_3[1] + param_1)) + param_1;
  }
  FUN_4083752c(*(uint *)(param_1 + (*param_3 & 0xfffffffc)));
  return;
}



/* 40837500 FUN_40837500 */

/* Boundary evidence: original MIPS .pdata 40837500..4083752b. Semantic name remains unreviewed. */

undefined4 FUN_40837500(undefined4 param_1,int param_2,undefined4 param_3,int param_4)

{
  FUN_408374ac(param_2,param_4,*(uint **)(*(int *)(param_4 + 4) + 0xc));
  return 1;
}



/* 4083752c FUN_4083752c */

/* Boundary evidence: original MIPS .pdata 4083752c..40837573. Semantic name remains unreviewed. */

void FUN_4083752c(uint param_1)

{
  if ((param_1 == DAT_408384ec) && (param_1 >> 0x10 == 0)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __report_gsfailure();
}



/* 40837574 FUN_40837574 */

/* Boundary evidence: original MIPS .pdata 40837574..40837693. Semantic name remains unreviewed. */

void FUN_40837574(UINT param_1,int param_2,int param_3)

{
  LPCRITICAL_SECTION lpCriticalSection;
  undefined4 *_Memory;
  
  DAT_40838514 = (undefined1)param_3;
  if (param_2 == 0) {
    _Memory = DAT_4083851c;
    if (DAT_4083851c != (undefined4 *)0x0) {
      while (DAT_40838518 = DAT_40838518 + -1, _Memory <= DAT_40838518) {
        if ((code *)*DAT_40838518 != (code *)0x0) {
          (*(code *)*DAT_40838518)();
          _Memory = DAT_4083851c;
        }
      }
      free(_Memory);
      DAT_40838518 = (undefined4 *)0x0;
      DAT_4083851c = (undefined4 *)0x0;
    }
    FUN_408376b8((undefined4 *)&DAT_40831010,(undefined4 *)&DAT_40831014);
  }
  FUN_408376b8((undefined4 *)&DAT_40831018,(undefined4 *)&DAT_4083101c);
  if (param_3 == 0) {
    TerminateProcess((HANDLE)0x42,param_1);
  }
  else {
    lpCriticalSection = (LPCRITICAL_SECTION)InterlockedExchange((LONG *)&DAT_40838520,0);
    if (lpCriticalSection != (LPCRITICAL_SECTION)0x0) {
      DeleteCriticalSection(lpCriticalSection);
      free(lpCriticalSection);
    }
  }
  return;
}



/* 40837694 FUN_40837694 */

/* Boundary evidence: original MIPS .pdata 40837694..408376b7. Semantic name remains unreviewed. */

void FUN_40837694(void)

{
  FUN_40837574(0,0,1);
  return;
}



/* 408376b8 FUN_408376b8 */

/* Boundary evidence: original MIPS .pdata 408376b8..4083770b. Semantic name remains unreviewed. */

void FUN_408376b8(undefined4 *param_1,undefined4 *param_2)

{
  for (; param_1 < param_2; param_1 = param_1 + 1) {
    if ((code *)*param_1 != (code *)0x0) {
      (*(code *)*param_1)();
    }
  }
  return;
}



/* 4083770c FUN_4083770c */

/* Boundary evidence: original MIPS .pdata 4083770c..40837747. Semantic name remains unreviewed. */

void FUN_4083770c(void)

{
  FUN_408376b8((undefined4 *)&DAT_40831008,(undefined4 *)&DAT_4083100c);
  FUN_408376b8((undefined4 *)&DAT_40831000,(undefined4 *)&DAT_40831004);
  return;
}


