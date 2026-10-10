/* Automatic Ghidra pseudocode. Not original source; not runtime-verified. */

/* 405e38b4 FUN_405e38b4 */

/* Boundary evidence: original MIPS .pdata 405e38b4..405e3d37. Semantic name remains unreviewed. */

void FUN_405e38b4(void)

{
  undefined *puVar1;
  HRESULT HVar2;
  int iVar3;
  LPWSTR pWVar4;
  wchar_t *pwVar5;
  uint uVar6;
  SIZE_T uBytes;
  uint uVar7;
  uint uVar8;
  int iVar9;
  LPVOID local_38;
  uint local_34;
  int local_30;
  
  iVar9 = 0;
  local_30 = 0;
  if (DAT_405fb778 != (int *)0x0) {
    (**(code **)(*DAT_405fb778 + 8))();
    DAT_405fb778 = (int *)0x0;
  }
  if (DAT_405fb780 != (HLOCAL)0x0) {
    LocalFree(DAT_405fb780);
    DAT_405fb780 = (HLOCAL)0x0;
  }
  if (DAT_405fb784 != 0) {
    DAT_405fb784 = 0;
  }
  if (DAT_405fb774 != 0) {
    DAT_405fb774 = 0;
  }
  HVar2 = CoInitializeEx((LPVOID)0x0,0);
  if (((-1 < HVar2) &&
      (HVar2 = CoCreateInstance((IID *)&DAT_405e131c,(LPUNKNOWN)0x0,1,(IID *)&DAT_405e130c,
                                &DAT_405fb778), -1 < HVar2)) && (DAT_405fb778 != (int *)0x0)) {
    local_34 = 0;
    local_38 = (LPVOID)0x0;
    iVar3 = (**(code **)(*DAT_405fb778 + 0x30))(DAT_405fb778,&local_34,&local_38);
    if (((-1 < iVar3) && (local_38 != (LPVOID)0x0)) && (local_34 != 0)) {
      uVar6 = 0;
      uVar7 = 0;
      if (local_34 != 0) {
        iVar3 = 0;
        do {
          puVar1 = PTR_u___BMP_405fb400;
          pWVar4 = CharUpperW(*(LPWSTR *)((int)local_38 + iVar3 + 0x2c));
          pwVar5 = wcsstr(pWVar4,(wchar_t *)puVar1);
          puVar1 = PTR_u___GIF_405fb408;
          if (pwVar5 == (wchar_t *)0x0) {
            pWVar4 = CharUpperW(*(LPWSTR *)((int)local_38 + iVar3 + 0x2c));
            pwVar5 = wcsstr(pWVar4,(wchar_t *)puVar1);
            puVar1 = PTR_u___JPG_405fb40c;
            if (pwVar5 != (wchar_t *)0x0) goto LAB_405e3a84;
            pWVar4 = CharUpperW(*(LPWSTR *)((int)local_38 + iVar3 + 0x2c));
            pwVar5 = wcsstr(pWVar4,(wchar_t *)puVar1);
            if (pwVar5 != (wchar_t *)0x0) goto LAB_405e3a84;
          }
          else {
            DAT_405fb774 = 1;
LAB_405e3a84:
            uVar6 = uVar6 + 1;
          }
          uVar7 = uVar7 + 1;
          iVar3 = iVar3 + 0x4c;
        } while (uVar7 < local_34);
        if (((uVar6 != 0) && (uVar6 <= local_34)) && (uVar6 < 4)) {
          uBytes = uVar6 * 0x4c;
          DAT_405fb780 = LocalAlloc(0x40,uBytes);
          if (DAT_405fb780 != (HLOCAL)0x0) {
            uVar8 = 0;
            uVar7 = uVar6;
            if (local_34 != 0) {
              iVar3 = 0;
              do {
                puVar1 = PTR_u___BMP_405fb400;
                pWVar4 = CharUpperW(*(LPWSTR *)((int)local_38 + iVar3 + 0x2c));
                pwVar5 = wcsstr(pWVar4,(wchar_t *)puVar1);
                if (((pwVar5 == (wchar_t *)0x0) ||
                    (HVar2 = StringCchCopyExW((STRSAFE_LPWSTR)((int)DAT_405fb780 + (uBytes - 0x4c)),
                                              6,(STRSAFE_LPCWSTR)PTR_u___BMP_405fb400,
                                              (STRSAFE_LPWSTR *)0x0,(size_t *)0x0,0x800), HVar2 < 0)
                    ) || (HVar2 = StringCchCopyExW((STRSAFE_LPWSTR)
                                                   ((int)DAT_405fb780 + (uBytes - 0x40)),0x20,
                                                   *(STRSAFE_LPCWSTR *)
                                                    ((int)local_38 + iVar3 + 0x28),
                                                   (STRSAFE_LPWSTR *)0x0,(size_t *)0x0,0x800),
                         HVar2 < 0)) {
                  puVar1 = PTR_u___GIF_405fb408;
                  pWVar4 = CharUpperW(*(LPWSTR *)((int)local_38 + iVar3 + 0x2c));
                  pwVar5 = wcsstr(pWVar4,(wchar_t *)puVar1);
                  if (((pwVar5 != (wchar_t *)0x0) &&
                      (HVar2 = StringCchCopyExW((STRSAFE_LPWSTR)
                                                ((int)DAT_405fb780 + (uBytes - 0x4c)),6,
                                                (STRSAFE_LPCWSTR)PTR_u___GIF_405fb408,
                                                (STRSAFE_LPWSTR *)0x0,(size_t *)0x0,0x800),
                      -1 < HVar2)) &&
                     (HVar2 = StringCchCopyExW((STRSAFE_LPWSTR)((int)DAT_405fb780 + (uBytes - 0x40))
                                               ,0x20,*(STRSAFE_LPCWSTR *)
                                                      ((int)local_38 + iVar3 + 0x28),
                                               (STRSAFE_LPWSTR *)0x0,(size_t *)0x0,0x800),
                     -1 < HVar2)) goto LAB_405e3c8c;
                  puVar1 = PTR_u___JPG_405fb40c;
                  pWVar4 = CharUpperW(*(LPWSTR *)((int)local_38 + iVar3 + 0x2c));
                  pwVar5 = wcsstr(pWVar4,(wchar_t *)puVar1);
                  if (((pwVar5 != (wchar_t *)0x0) &&
                      (HVar2 = StringCchCopyExW((STRSAFE_LPWSTR)
                                                ((int)DAT_405fb780 + (uBytes - 0x4c)),6,
                                                (STRSAFE_LPCWSTR)PTR_u___JPG_405fb40c,
                                                (STRSAFE_LPWSTR *)0x0,(size_t *)0x0,0x800),
                      -1 < HVar2)) &&
                     (HVar2 = StringCchCopyExW((STRSAFE_LPWSTR)((int)DAT_405fb780 + (uBytes - 0x40))
                                               ,0x20,*(STRSAFE_LPCWSTR *)
                                                      ((int)local_38 + iVar3 + 0x28),
                                               (STRSAFE_LPWSTR *)0x0,(size_t *)0x0,0x800),
                     -1 < HVar2)) goto LAB_405e3c8c;
                }
                else {
LAB_405e3c8c:
                  uVar7 = uVar7 - 1;
                  uBytes = uBytes - 0x4c;
                }
                uVar8 = uVar8 + 1;
                iVar3 = iVar3 + 0x4c;
                iVar9 = local_30;
              } while (uVar8 < local_34);
            }
            if (uVar7 == 0) {
              iVar9 = 1;
              DAT_405fb784 = uVar6;
            }
            else {
              LocalFree(DAT_405fb780);
              DAT_405fb780 = (HLOCAL)0x0;
              DAT_405fb774 = 0;
            }
          }
        }
      }
      CoTaskMemFree(local_38);
      if (iVar9 != 0) {
        return;
      }
    }
    (**(code **)(*DAT_405fb778 + 8))();
    DAT_405fb778 = (int *)0x0;
  }
  return;
}



/* 405e3d38 FUN_405e3d38 */

/* Boundary evidence: original MIPS .pdata 405e3d38..405e3dd3. Semantic name remains unreviewed. */

void FUN_405e3d38(void)

{
  if (DAT_405fb778 != (int *)0x0) {
    (**(code **)(*DAT_405fb778 + 8))();
    DAT_405fb778 = (int *)0x0;
  }
  if (DAT_405fb77c != (int *)0x0) {
    (**(code **)(*DAT_405fb77c + 8))();
    DAT_405fb77c = (int *)0x0;
  }
  if (DAT_405fb780 != (HLOCAL)0x0) {
    LocalFree(DAT_405fb780);
    DAT_405fb780 = (HLOCAL)0x0;
  }
  DAT_405fb774 = 0;
  DAT_405fb784 = 0;
  CoUninitialize();
  return;
}



/* 405e3dd4 FUN_405e3dd4 */

/* Boundary evidence: original MIPS .pdata 405e3dd4..405e3e87. Semantic name remains unreviewed. */

undefined4 FUN_405e3dd4(LPWSTR param_1)

{
  undefined *puVar1;
  LPWSTR pWVar2;
  wchar_t *pwVar3;
  
  puVar1 = PTR_DAT_405fb3f4;
  pWVar2 = CharLowerW(param_1);
  pwVar3 = wcsstr(pWVar2,(wchar_t *)puVar1);
  puVar1 = PTR_DAT_405fb3f0;
  if ((pwVar3 == (wchar_t *)0x0) && (DAT_405fb778 != 0)) {
    pWVar2 = CharUpperW(param_1);
    pwVar3 = wcsstr(pWVar2,(wchar_t *)puVar1);
    if (pwVar3 == (wchar_t *)0x0) {
      return 1;
    }
    if (DAT_405fb774 != 0) {
      return 1;
    }
  }
  return 0;
}



/* 405e3e88 FUN_405e3e88 */

/* Boundary evidence: original MIPS .pdata 405e3e88..405e3f57. Semantic name remains unreviewed. */

int FUN_405e3e88(HWND param_1,short *param_2)

{
  DWORD DVar1;
  LPCWSTR lpCaption;
  LPCWSTR lpText;
  int iVar2;
  UINT uID;
  
  iVar2 = 0;
  if (((param_2 != (short *)0x0) && (*param_2 != 0)) &&
     (iVar2 = SHLoadDIBitmap(param_2), iVar2 == 0)) {
    DVar1 = GetLastError();
    uID = 0x810b;
    if (DVar1 != 0xe) {
      uID = 0x810a;
    }
    lpCaption = (LPCWSTR)LoadStringW(DAT_405fb7fc,0x8109,(LPWSTR)0x0,0);
    lpText = (LPCWSTR)LoadStringW(DAT_405fb7fc,uID,(LPWSTR)0x0,0);
    MessageBoxW(param_1,lpText,lpCaption,0x30);
  }
  return iVar2;
}



/* 405e3f58 FUN_405e3f58 */

/* Boundary evidence: original MIPS .pdata 405e3f58..405e3fc3. Semantic name remains unreviewed. */

bool FUN_405e3f58(PHKEY param_1,HKEY param_2,LPCWSTR param_3)

{
  LSTATUS LVar1;
  DWORD aDStack_10 [2];
  
  LVar1 = RegCreateKeyExW(param_2,param_3,0,(LPWSTR)0x0,0,0xf003f,(LPSECURITY_ATTRIBUTES)0x0,param_1
                          ,aDStack_10);
  return LVar1 == 0;
}



/* 405e3fc4 FUN_405e3fc4 */

/* Boundary evidence: original MIPS .pdata 405e3fc4..405e401f. Semantic name remains unreviewed. */

PHKEY FUN_405e3fc4(PHKEY param_1,HKEY param_2,LPCWSTR param_3)

{
  *param_1 = (HKEY)0x0;
  param_1[1] = (HKEY)0x0;
  param_1[2] = (HKEY)0x0;
  RegOpenKeyExW(param_2,param_3,0,0x20019,param_1);
  return param_1;
}



/* 405e4020 FUN_405e4020 */

/* Boundary evidence: original MIPS .pdata 405e4020..405e406f. Semantic name remains unreviewed. */

void FUN_405e4020(undefined4 *param_1)

{
  if ((HKEY)*param_1 != (HKEY)0x0) {
    RegCloseKey((HKEY)*param_1);
  }
  if ((HLOCAL)param_1[2] != (HLOCAL)0x0) {
    LocalFree((HLOCAL)param_1[2]);
  }
  return;
}



/* 405e4070 FUN_405e4070 */

/* Boundary evidence: original MIPS .pdata 405e4070..405e4193. Semantic name remains unreviewed. */

undefined4 FUN_405e4070(HWND param_1,int param_2,undefined4 param_3,int param_4)

{
  wchar_t wVar1;
  HRESULT HVar2;
  wchar_t *pwVar3;
  int iVar4;
  int iVar5;
  wchar_t local_20;
  undefined1 auStack_1e [10];
  uint local_14;
  
  local_14 = DAT_405fb760;
  if (((param_2 == 0x4e) && (param_4 != 0)) && (*(int *)(param_4 + 8) == -0x25f)) {
    local_20 = L'\0';
    memset(auStack_1e,0,8);
    iVar5 = *(int *)(*(int *)(param_4 + 0xc) + 0x18);
    pwVar3 = *(wchar_t **)(*(int *)(param_4 + 0xc) + 0xc);
    iVar4 = iVar5 * 2 + -1;
    if (0 < iVar4) {
      do {
        wVar1 = *pwVar3;
        while (wVar1 != L'\0') {
          pwVar3 = pwVar3 + 1;
          wVar1 = *pwVar3;
        }
        iVar4 = iVar4 + -1;
        pwVar3 = pwVar3 + 1;
      } while (iVar4 != 0);
    }
    HVar2 = StringCchCopyW(&local_20,5,pwVar3);
    if (((HVar2 < 0) || (iVar5 < 1)) || (pwVar3 = &local_20, 4 < iVar5)) {
      pwVar3 = (wchar_t *)0x0;
    }
    SendMessageW(param_1,0x46a,0,(LPARAM)pwVar3);
  }
  FUN_405f9bec(local_14);
  return 0;
}



/* 405e4194 FUN_405e4194 */

/* Boundary evidence: original MIPS .pdata 405e4194..405e41ef. Semantic name remains unreviewed. */

undefined4 FUN_405e4194(undefined4 *param_1,LPCWSTR param_2,undefined4 param_3)

{
  undefined4 local_10;
  DWORD local_c;
  
  if ((HKEY)*param_1 == (HKEY)0x0) {
    local_10 = 0;
  }
  else {
    local_c = 4;
    local_10 = param_3;
    RegQueryValueExW((HKEY)*param_1,param_2,(LPDWORD)0x0,(LPDWORD)0x0,(LPBYTE)&local_10,&local_c);
  }
  return local_10;
}



/* 405e41f0 FUN_405e41f0 */

/* Boundary evidence: original MIPS .pdata 405e41f0..405e424b. Semantic name remains unreviewed. */

undefined4 FUN_405e41f0(undefined4 *param_1,LPCWSTR param_2,BYTE *param_3,int param_4)

{
  LSTATUS LVar1;
  
  if (((HKEY)*param_1 != (HKEY)0x0) &&
     (LVar1 = RegSetValueExW((HKEY)*param_1,param_2,0,1,param_3,param_4 << 1), LVar1 == 0)) {
    return 1;
  }
  return 0;
}



/* 405e424c FUN_405e424c */

/* Boundary evidence: original MIPS .pdata 405e424c..405e429f. Semantic name remains unreviewed. */

void FUN_405e424c(undefined4 *param_1,LPCWSTR param_2,wchar_t *param_3)

{
  size_t sVar1;
  
  sVar1 = wcslen(param_3);
  FUN_405e41f0(param_1,param_2,(BYTE *)param_3,sVar1 + 1);
  return;
}



/* 405e42a0 FUN_405e42a0 */

/* Boundary evidence: original MIPS .pdata 405e42a0..405e4617. Semantic name remains unreviewed. */

void FUN_405e42a0(HWND param_1,HDC param_2,int *param_3,int param_4)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  HDC hdc;
  HBITMAP hbm;
  HGDIOBJ h;
  HBRUSH h_00;
  HGDIOBJ h_01;
  int iVar4;
  uint xRight;
  int *local_90 [2];
  tagRECT local_88;
  tagRECT local_78;
  undefined4 local_68;
  undefined1 auStack_64 [16];
  int local_54;
  int local_50;
  uint local_28;
  
  local_28 = DAT_405fb760;
  local_68 = 0;
  memset(auStack_64,0,0x3c);
  local_88.left = 0;
  memset(&local_88.top,0,0xc);
  GetClientRect(param_1,&local_88);
  iVar1 = (**(code **)(*param_3 + 0x10))(param_3,&local_68);
  if (((-1 < iVar1) && (local_54 != 0)) && (local_50 != 0)) {
    uVar2 = GetSystemMetrics(0);
    uVar3 = GetSystemMetrics(1);
    if ((uVar2 != 0) && (uVar3 != 0)) {
      local_90[0] = (int *)0x0;
      xRight = (uint)((local_88.right - local_88.left) * local_54) / uVar2;
      if (uVar2 == 0) {
        trap(0x1c00);
      }
      uVar2 = (uint)((local_88.bottom - local_88.top) * local_50) / uVar3;
      if (uVar3 == 0) {
        trap(0x1c00);
      }
      if (((xRight != 0) && (uVar2 != 0)) &&
         ((iVar1 = (**(code **)(*param_3 + 0x20))(param_3,xRight,uVar2,local_90), -1 < iVar1 &&
          (local_90[0] != (int *)0x0)))) {
        local_78.left = 0;
        memset(&local_78.top,0,0xc);
        SetRect(&local_78,0,0,xRight,uVar2);
        hdc = CreateCompatibleDC(param_2);
        hbm = CreateCompatibleBitmap(param_2,xRight,uVar2);
        h = SelectObject(hdc,hbm);
        if ((((hdc != (HDC)0x0) && (hbm != (HBITMAP)0x0)) && (h != (HGDIOBJ)0x0)) &&
           (iVar1 = (**(code **)(*local_90[0] + 0x18))(local_90[0],hdc,&local_78,0), -1 < iVar1)) {
          if (param_4 == 0) {
            iVar1 = local_88.bottom - local_88.top;
            if (iVar1 < 0) {
              iVar1 = iVar1 + 1;
            }
            iVar4 = local_88.right - local_88.left;
            if (iVar4 < 0) {
              iVar4 = iVar4 + 1;
            }
            OffsetRect(&local_78,(iVar4 >> 1) - (xRight >> 1),(iVar1 >> 1) - (uVar2 >> 1));
            BitBlt(param_2,local_78.left,local_78.top,xRight,uVar2,hdc,0,0,0xcc0020);
          }
          else {
            h_00 = CreatePatternBrush(hbm);
            if (h_00 != (HBRUSH)0x0) {
              h_01 = SelectObject(param_2,h_00);
              PatBlt(param_2,0,0,local_88.right - local_88.left,local_88.bottom - local_88.top,
                     0xf00021);
              if (h_01 != (HGDIOBJ)0x0) {
                SelectObject(param_2,h_01);
              }
              DeleteObject(h_00);
            }
          }
        }
        SelectObject(hdc,h);
        if (hbm != (HBITMAP)0x0) {
          DeleteObject(hbm);
        }
        if (hdc != (HDC)0x0) {
          DeleteDC(hdc);
        }
        (**(code **)(*local_90[0] + 8))();
      }
    }
  }
  FUN_405f9bec(local_28);
  return;
}



/* 405e4618 FUN_405e4618 */

/* Boundary evidence: original MIPS .pdata 405e4618..405e466f. Semantic name remains unreviewed. */

undefined4 FUN_405e4618(undefined4 *param_1,LPCWSTR param_2,undefined4 param_3)

{
  LSTATUS LVar1;
  undefined4 local_res8 [2];
  
  if (((HKEY)*param_1 != (HKEY)0x0) &&
     (local_res8[0] = param_3,
     LVar1 = RegSetValueExW((HKEY)*param_1,param_2,0,4,(BYTE *)local_res8,4), LVar1 == 0)) {
    return 1;
  }
  return 0;
}



/* 405e4670 FUN_405e4670 */

/* Boundary evidence: original MIPS .pdata 405e4670..405e497f. Semantic name remains unreviewed. */

void FUN_405e4670(HWND param_1,HDC param_2,HANDLE param_3,int param_4)

{
  HDC hdc;
  HDC hdc_00;
  HBITMAP h;
  HGDIOBJ h_00;
  LONG LVar1;
  int iVar2;
  int iVar3;
  int x;
  int cy;
  int iVar4;
  int iVar5;
  HGDIOBJ local_58;
  tagRECT local_50;
  undefined4 local_40;
  int local_3c;
  int local_38;
  
  local_40 = 0;
  memset(&local_3c,0,0x14);
  local_50.left = 0;
  iVar2 = 0;
  iVar3 = 0;
  memset(&local_50.top,0,0xc);
  if (param_3 != (HANDLE)0x0) {
    GetClientRect(param_1,&local_50);
    GetObjectW(param_3,0x18,&local_40);
    iVar4 = (local_3c << 2) / 10;
    iVar5 = (local_38 << 2) / 10;
    hdc = CreateCompatibleDC(param_2);
    if (hdc != (HDC)0x0) {
      local_58 = SelectObject(hdc,param_3);
    }
    hdc_00 = CreateCompatibleDC(param_2);
    h = CreateCompatibleBitmap(param_2,iVar4,iVar5);
    h_00 = SelectObject(hdc_00,h);
    StretchBlt(hdc_00,0,0,iVar4,iVar5,hdc,0,0,local_3c,local_38,0xcc0020);
    if (param_4 == 0) {
      if (iVar5 < local_50.bottom) {
        iVar5 = local_50.bottom - iVar5;
        iVar2 = iVar5 >> 1;
        if (iVar5 < 0) {
          iVar2 = iVar5 + 1 >> 1;
        }
      }
      if (iVar4 < local_50.right) {
        iVar4 = local_50.right - iVar4;
        iVar3 = iVar4 >> 1;
        if (iVar4 < 0) {
          iVar3 = iVar4 + 1 >> 1;
        }
      }
      BitBlt(param_2,iVar3,iVar2,local_50.right,local_50.bottom,hdc_00,0,0,0xcc0020);
    }
    else {
      iVar3 = 0;
      iVar2 = local_50.bottom;
      LVar1 = local_50.right;
      if (0 < local_50.bottom) {
        do {
          x = 0;
          if (iVar5 == 0) break;
          cy = iVar2 - iVar3;
          if (iVar5 <= iVar2 - iVar3) {
            cy = iVar5;
          }
          if (0 < LVar1) {
            do {
              iVar2 = local_50.bottom;
              if (iVar4 == 0) break;
              iVar2 = LVar1 - x;
              if (iVar4 <= LVar1 - x) {
                iVar2 = iVar4;
              }
              BitBlt(param_2,x,iVar3,iVar2,cy,hdc_00,0,0,0xcc0020);
              x = iVar2 + x;
              iVar2 = local_50.bottom;
              LVar1 = local_50.right;
            } while (x < local_50.right);
          }
          iVar3 = cy + iVar3;
        } while (iVar3 < iVar2);
      }
    }
    if (hdc != (HDC)0x0) {
      SelectObject(hdc,local_58);
      DeleteDC(hdc);
    }
    if (hdc_00 != (HDC)0x0) {
      SelectObject(hdc_00,h_00);
      DeleteDC(hdc_00);
    }
    DeleteObject(h);
  }
  return;
}



/* 405e4980 FUN_405e4980 */

/* Boundary evidence: original MIPS .pdata 405e4980..405e4a13. Semantic name remains unreviewed. */

WPARAM FUN_405e4980(HWND param_1,int param_2)

{
  int iVar1;
  WPARAM wParam;
  WPARAM WVar2;
  
  wParam = 0;
  iVar1 = SendMessageW(param_1,0x150,0,0);
  while ((WVar2 = 0xffffffff, iVar1 != -1 && (WVar2 = wParam, param_2 != iVar1))) {
    wParam = wParam + 1;
    iVar1 = SendMessageW(param_1,0x150,wParam,0);
  }
  return WVar2;
}



/* 405e4a14 BacklightDlgProc */

/* Boundary evidence: original MIPS .pdata 405e4a14..405e5023. Semantic name remains unreviewed. */

undefined4 BacklightDlgProc(HWND param_1,int param_2,short param_3)

{
  HWND pHVar1;
  BOOL bEnable;
  HANDLE pvVar2;
  WPARAM WVar3;
  LRESULT LVar4;
  LRESULT LVar5;
  LRESULT LVar6;
  HWND hWnd;
  WPARAM wParam;
  int iVar7;
  WPARAM WVar8;
  LPCWSTR lpLibFileName;
  HKEY *ppHVar9;
  int iVar10;
  wchar_t *pwVar11;
  HKEY local_48;
  undefined4 local_44;
  undefined4 local_40;
  HKEY apHStack_38 [4];
  
                    /* 0x4a14  2  BacklightDlgProc */
  if (param_2 == 2) {
LAB_405e4fd0:
    if (DAT_405fb788 != (HMODULE)0x0) {
      FreeLibrary(DAT_405fb788);
    }
    return 0;
  }
  if (param_2 != 0x110) {
    if (param_2 != 0x111) {
      return 0;
    }
    if (param_3 != 1) {
      if (param_3 == 0x24b) {
        if (DAT_405fb78c == (code *)0x0) {
          return 1;
        }
        iVar10 = (*DAT_405fb78c)(param_1);
        if (iVar10 != 0) {
          pvVar2 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,L"BackLightChangeEvent");
          if (pvVar2 != (HANDLE)0x0) {
            EventModify(pvVar2,3);
            CloseHandle(pvVar2);
            return 1;
          }
          return 1;
        }
        return 1;
      }
      if (param_3 == 0x24c) {
        pHVar1 = GetDlgItem(param_1,0x24c);
        bEnable = SendMessageW(pHVar1,0xf0,0,0);
        iVar10 = 0x249;
      }
      else {
        if (param_3 != 0x24d) goto LAB_405e4fd0;
        pHVar1 = GetDlgItem(param_1,0x24d);
        bEnable = SendMessageW(pHVar1,0xf0,0,0);
        iVar10 = 0x24a;
      }
      pHVar1 = GetDlgItem(param_1,iVar10);
      EnableWindow(pHVar1,bEnable);
      return 1;
    }
    local_48 = (HKEY)0x0;
    local_44 = 0;
    local_40 = 0;
    FUN_405e3f58(&local_48,(HKEY)0x80000001,L"ControlPanel\\BackLight");
    pHVar1 = GetDlgItem(param_1,0x249);
    WVar3 = SendMessageW(pHVar1,0x147,0,0);
    pHVar1 = GetDlgItem(param_1,0x249);
    LVar4 = SendMessageW(pHVar1,0x150,WVar3,0);
    pHVar1 = GetDlgItem(param_1,0x24a);
    WVar3 = SendMessageW(pHVar1,0x147,0,0);
    pHVar1 = GetDlgItem(param_1,0x24a);
    LVar5 = SendMessageW(pHVar1,0x150,WVar3,0);
    pHVar1 = GetDlgItem(param_1,0x24c);
    LVar6 = SendMessageW(pHVar1,0xf0,0,0);
    if (LVar6 == 0) {
      if (local_48 != (HKEY)0x0) {
        RegDeleteValueW(local_48,L"BatteryTimeout");
      }
      FUN_405e4618(&local_48,L"UseBattery",0);
      pwVar11 = L"OldBatteryTimeout";
    }
    else {
      FUN_405e4618(&local_48,L"UseBattery",1);
      pwVar11 = L"BatteryTimeout";
    }
    FUN_405e4618(&local_48,pwVar11,LVar4);
    pHVar1 = GetDlgItem(param_1,0x24d);
    LVar4 = SendMessageW(pHVar1,0xf0,0,0);
    if (LVar4 == 0) {
      if (local_48 != (HKEY)0x0) {
        RegDeleteValueW(local_48,L"ACTimeout");
      }
      FUN_405e4618(&local_48,L"UseExt",0);
      pwVar11 = L"OldACTimeout";
    }
    else {
      FUN_405e4618(&local_48,L"UseExt",1);
      pwVar11 = L"ACTimeout";
    }
    FUN_405e4618(&local_48,pwVar11,LVar5);
    pvVar2 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,L"BackLightChangeEvent");
    if (pvVar2 != (HANDLE)0x0) {
      EventModify(pvVar2,3);
      CloseHandle(pvVar2);
    }
    ppHVar9 = &local_48;
    goto LAB_405e4fc0;
  }
  pHVar1 = GetDlgItem(param_1,0x249);
  hWnd = GetDlgItem(param_1,0x24a);
  FUN_405f7b84(pHVar1,(UINT *)&DAT_405e14ec,1);
  FUN_405f7b84(hWnd,(UINT *)&DAT_405e14ec,1);
  FUN_405f7b84(hWnd,(UINT *)&DAT_405e151c,1);
  FUN_405e3fc4(apHStack_38,(HKEY)0x80000001,L"ControlPanel\\BackLight");
  WVar3 = FUN_405e4194(apHStack_38,L"UseBattery",1);
  wParam = FUN_405e4194(apHStack_38,L"UseExt",1);
  if (WVar3 == 0) {
    pwVar11 = L"OldBatteryTimeout";
  }
  else {
    pwVar11 = L"BatteryTimeout";
  }
  iVar10 = FUN_405e4194(apHStack_38,pwVar11,0xf);
  if (wParam == 0) {
    pwVar11 = L"OldACTimeout";
  }
  else {
    pwVar11 = L"ACTimeout";
  }
  iVar7 = FUN_405e4194(apHStack_38,pwVar11,0x3c);
  WVar8 = FUN_405e4980(pHVar1,iVar10);
  SendMessageW(pHVar1,0x14e,WVar8,0);
  WVar8 = FUN_405e4980(hWnd,iVar7);
  SendMessageW(hWnd,0x14e,WVar8,0);
  EnableWindow(pHVar1,WVar3);
  pHVar1 = GetDlgItem(param_1,0x24c);
  SendMessageW(pHVar1,0xf1,WVar3,0);
  EnableWindow(hWnd,wParam);
  pHVar1 = GetDlgItem(param_1,0x24d);
  SendMessageW(pHVar1,0xf1,wParam,0);
  lpLibFileName = (LPCWSTR)FUN_405f7da0(apHStack_38,L"AdvancedCPL");
  DAT_405fb788 = (HMODULE)0x0;
  DAT_405fb78c = (code *)0x0;
  if (lpLibFileName == (LPCWSTR)0x0) {
LAB_405e4f94:
    iVar10 = 0;
  }
  else {
    DAT_405fb788 = LoadLibraryW(lpLibFileName);
    if (DAT_405fb788 != (HMODULE)0x0) {
      DAT_405fb78c = (code *)GetProcAddressW(DAT_405fb788,L"BacklightAdvApplet");
    }
    iVar10 = 5;
    if (DAT_405fb78c == (code *)0x0) goto LAB_405e4f94;
  }
  pHVar1 = GetDlgItem(param_1,0x24b);
  ShowWindow(pHVar1,iVar10);
  FUN_405f7378(param_1,8);
  ppHVar9 = apHStack_38;
LAB_405e4fc0:
  FUN_405e4020(ppHVar9);
  return 1;
}



/* 405e5024 FUN_405e5024 */

/* Boundary evidence: original MIPS .pdata 405e5024..405e5343. Semantic name remains unreviewed. */

BOOL FUN_405e5024(HWND param_1,LPWSTR param_2,uint param_3)

{
  undefined1 *puVar1;
  uint *puVar2;
  int iVar3;
  int iVar4;
  HRESULT HVar5;
  size_t sVar6;
  DWORD *pDVar7;
  int iVar8;
  wchar_t *_Str1;
  uint uVar9;
  uint uVar10;
  wchar_t *_Str2;
  BOOL local_298;
  tagOFNW atStack_288 [6];
  uint local_30;
  
  local_30 = DAT_405fb760;
  *param_2 = L'\0';
  local_298 = 0;
  atStack_288[0].dwReserved._0_2_ = 0;
  iVar3 = LoadStringW(DAT_405fb7fc,0x8108,(LPWSTR)&atStack_288[0].dwReserved,0x104);
  if (1 < iVar3) {
    if (DAT_405fb780 != 0) {
      *(undefined2 *)((int)&atStack_288[0].pvReserved + iVar3 * 2) = 0;
      uVar10 = 0;
      if (DAT_405fb784 != 0) {
        iVar8 = 0;
        iVar3 = DAT_405fb780;
        uVar9 = DAT_405fb784;
        _Str2 = (wchar_t *)PTR_u___JPG_405fb40c;
        do {
          _Str1 = (wchar_t *)(iVar8 + iVar3);
          iVar4 = wcsncmp(_Str1,(wchar_t *)PTR_u___GIF_405fb408,5);
          if (((iVar4 == 0) || (iVar4 = wcsncmp(_Str1,_Str2,5), iVar4 == 0)) &&
             ((HVar5 = StringCchCatExW((STRSAFE_LPWSTR)&atStack_288[0].dwReserved,0x104,_Str1 + 6,
                                       (STRSAFE_LPWSTR *)0x0,(size_t *)0x0,0x800), HVar5 < 0 ||
              (((HVar5 = StringCchCatExW((STRSAFE_LPWSTR)&atStack_288[0].dwReserved,0x104,L"\x01",
                                         (STRSAFE_LPWSTR *)0x0,(size_t *)0x0,0x800), HVar5 < 0 ||
                (HVar5 = StringCchCatExW((STRSAFE_LPWSTR)&atStack_288[0].dwReserved,0x104,
                                         (STRSAFE_LPCWSTR)(iVar8 + DAT_405fb780),
                                         (STRSAFE_LPWSTR *)0x0,(size_t *)0x0,0x800), HVar5 < 0)) ||
               (HVar5 = StringCchCatExW((STRSAFE_LPWSTR)&atStack_288[0].dwReserved,0x104,L"\x01",
                                        (STRSAFE_LPWSTR *)0x0,(size_t *)0x0,0x800),
               iVar3 = DAT_405fb780, uVar9 = DAT_405fb784, _Str2 = (wchar_t *)PTR_u___JPG_405fb40c,
               HVar5 < 0)))))) goto LAB_405e5308;
          uVar10 = uVar10 + 1;
          iVar8 = iVar8 + 0x4c;
        } while (uVar10 < uVar9);
      }
      HVar5 = StringCchCatExW((STRSAFE_LPWSTR)&atStack_288[0].dwReserved,0x104,L"\x01",
                              (STRSAFE_LPWSTR *)0x0,(size_t *)0x0,0x800);
      if (HVar5 < 0) goto LAB_405e5308;
    }
    sVar6 = wcslen((wchar_t *)&atStack_288[0].dwReserved);
    if (0 < (int)sVar6) {
      pDVar7 = &atStack_288[0].dwReserved;
      do {
        if ((short)*pDVar7 == 1) {
          *(short *)pDVar7 = 0;
        }
        sVar6 = sVar6 - 1;
        pDVar7 = (DWORD *)((int)pDVar7 + 2);
      } while (sVar6 != 0);
    }
    memset(atStack_288,0,0x4c);
    atStack_288[0].lpstrFilter = (LPCWSTR)&atStack_288[0].dwReserved;
    puVar1 = (undefined1 *)((int)&atStack_288[0].lStructSize + 3);
    uVar10 = (uint)puVar1 & 3;
    puVar2 = (uint *)(puVar1 + -uVar10);
    *puVar2 = *puVar2 & -1 << (uVar10 + 1) * 8 | 0x4cU >> (3 - uVar10) * 8;
    puVar1 = (undefined1 *)((int)&atStack_288[0].hwndOwner + 3);
    uVar10 = (uint)puVar1 & 3;
    puVar2 = (uint *)(puVar1 + -uVar10);
    *puVar2 = *puVar2 & -1 << (uVar10 + 1) * 8 | (uint)param_1 >> (3 - uVar10) * 8;
    puVar1 = (undefined1 *)((int)&atStack_288[0].lpstrCustomFilter + 3);
    uVar10 = (uint)puVar1 & 3;
    puVar2 = (uint *)(puVar1 + -uVar10);
    *puVar2 = *puVar2 & -1 << (uVar10 + 1) * 8 | 0U >> (3 - uVar10) * 8;
    puVar1 = (undefined1 *)((int)&atStack_288[0].nFilterIndex + 3);
    uVar10 = (uint)puVar1 & 3;
    puVar2 = (uint *)(puVar1 + -uVar10);
    *puVar2 = *puVar2 & -1 << (uVar10 + 1) * 8 | 1U >> (3 - uVar10) * 8;
    puVar1 = (undefined1 *)((int)&atStack_288[0].lpstrFile + 3);
    uVar10 = (uint)puVar1 & 3;
    puVar2 = (uint *)(puVar1 + -uVar10);
    *puVar2 = *puVar2 & -1 << (uVar10 + 1) * 8 | (uint)param_2 >> (3 - uVar10) * 8;
    puVar1 = (undefined1 *)((int)&atStack_288[0].nMaxFile + 3);
    uVar10 = (uint)puVar1 & 3;
    puVar2 = (uint *)(puVar1 + -uVar10);
    *puVar2 = *puVar2 & -1 << (uVar10 + 1) * 8 | param_3 >> (3 - uVar10) * 8;
    puVar1 = (undefined1 *)((int)&atStack_288[0].lpstrInitialDir + 3);
    uVar10 = (uint)puVar1 & 3;
    puVar2 = (uint *)(puVar1 + -uVar10);
    *puVar2 = *puVar2 & -1 << (uVar10 + 1) * 8 | 0x405e167cU >> (3 - uVar10) * 8;
    atStack_288[0].lStructSize = 0x4c;
    atStack_288[0].lpstrCustomFilter = (LPWSTR)0x0;
    atStack_288[0].nFilterIndex = 1;
    atStack_288[0].lpstrInitialDir = L"\\Windows";
    atStack_288[0].hwndOwner = param_1;
    atStack_288[0].lpstrFile = param_2;
    atStack_288[0].nMaxFile = param_3;
    atStack_288[0].lpstrTitle = (LPCWSTR)LoadStringW(DAT_405fb7fc,0x8507,(LPWSTR)0x0,0);
    atStack_288[0].Flags = 0x1004;
    atStack_288[0].lpfnHook = FUN_405e4070;
    atStack_288[0].lpstrDefExt = L"bmp";
    local_298 = GetOpenFileNameW(atStack_288);
  }
LAB_405e5308:
  FUN_405f9bec(local_30);
  return local_298;
}



/* 405e5344 FUN_405e5344 */

/* Boundary evidence: original MIPS .pdata 405e5344..405e549b. Semantic name remains unreviewed. */

LRESULT FUN_405e5344(HWND param_1,UINT param_2,WPARAM param_3,LPARAM param_4)

{
  HDC hDC;
  DWORD color;
  HBRUSH hbr;
  LRESULT LVar1;
  tagRECT local_68;
  tagPAINTSTRUCT local_58;
  uint local_18;
  
  local_18 = DAT_405fb760;
  if (param_2 == 0xf) {
    local_58.hdc = (HDC)0x0;
    memset(&local_58.fErase,0,0x3c);
    local_68.left = 0;
    memset(&local_68.top,0,0xc);
    hDC = BeginPaint(param_1,&local_58);
    GetClientRect(param_1,&local_68);
    color = GetSysColor(0x40000001);
    hbr = CreateSolidBrush(color);
    if (hbr != (HBRUSH)0x0) {
      FillRect(hDC,&local_68,hbr);
      DeleteObject(hbr);
    }
    if (DAT_405fb76c == (HANDLE)0x0) {
      if (DAT_405fb77c != (int *)0x0) {
        FUN_405e42a0(param_1,hDC,DAT_405fb77c,DAT_405fb770);
      }
    }
    else {
      FUN_405e4670(param_1,hDC,DAT_405fb76c,DAT_405fb770);
    }
    EndPaint(param_1,&local_58);
    FUN_405f9bec(local_18);
    LVar1 = 0;
  }
  else {
    LVar1 = CallWindowProcW(DAT_405fb768,param_1,param_2,param_3,param_4);
    FUN_405f9bec(local_18);
  }
  return LVar1;
}



/* 405e549c BackgroundDlgProc */

/* Boundary evidence: original MIPS .pdata 405e549c..405e5d0f. Semantic name remains unreviewed. */

undefined4 BackgroundDlgProc(HWND param_1,int param_2,uint param_3)

{
  HGDIOBJ ho;
  HWND pHVar1;
  BOOL BVar2;
  int iVar3;
  WPARAM WVar4;
  LRESULT LVar5;
  LPWSTR pWVar6;
  undefined4 *puVar7;
  HKEY *ppHVar8;
  uint uVar9;
  int iVar10;
  HGDIOBJ pvVar11;
  int *local_260 [2];
  HKEY local_258;
  undefined4 local_254;
  undefined4 local_250;
  HKEY apHStack_248 [4];
  WCHAR aWStack_238 [262];
  uint local_2c;
  
                    /* 0x549c  1  BackgroundDlgProc */
  local_2c = DAT_405fb760;
  if (param_2 == 2) {
    if (DAT_405fb76c != (HGDIOBJ)0x0) {
      DeleteObject(DAT_405fb76c);
    }
    DAT_405fb76c = (HGDIOBJ)0x0;
    FUN_405e3d38();
    goto LAB_405e5cd4;
  }
  if (param_2 == 0x110) {
    pHVar1 = GetDlgItem(param_1,0x244);
    DAT_405fb768 = SetWindowLongW(pHVar1,-4,0x405e5344);
    FUN_405e3fc4(apHStack_248,(HKEY)0x80000001,L"ControlPanel\\Desktop");
    DAT_405fb770 = FUN_405e4194(apHStack_248,L"Tile",0);
    DAT_405fb790 = (LPWSTR)FUN_405f7da0(apHStack_248,L"Wallpaper");
    DAT_405fb798 = 0;
    pHVar1 = GetDlgItem(param_1,0x248);
    SendMessageW(pHVar1,0xf1,DAT_405fb770,0);
    FUN_405e38b4();
    puVar7 = operator_new(8);
    if (puVar7 == (undefined4 *)0x0) {
      puVar7 = (undefined4 *)0x0;
    }
    else {
      pHVar1 = GetDlgItem(param_1,0x245);
      *puVar7 = pHVar1;
    }
    DAT_405fb794 = puVar7;
    if (puVar7 != (undefined4 *)0x0) {
      FUN_405f8bd4(puVar7,L"\\Windows",(int)PTR_u___2bp_405fb404);
      if (DAT_405fb778 == (int *)0x0) {
LAB_405e5b0c:
        FUN_405f8bd4(DAT_405fb794,L"\\Windows",(int)PTR_u___BMP_405fb400);
      }
      else {
        uVar9 = 0;
        if (DAT_405fb784 != 0) {
          iVar3 = 0;
          do {
            FUN_405f8bd4(DAT_405fb794,L"\\Windows",iVar3 + DAT_405fb780);
            uVar9 = uVar9 + 1;
            iVar3 = iVar3 + 0x4c;
          } while (uVar9 < DAT_405fb784);
        }
        if ((DAT_405fb778 == (int *)0x0) || (DAT_405fb774 == 0)) goto LAB_405e5b0c;
      }
      iVar3 = LoadStringW(DAT_405fb7fc,0x8508,(LPWSTR)0x0,0);
      FUN_405f8cd4(DAT_405fb794,iVar3,L"",0);
    }
    if (DAT_405fb76c != (HGDIOBJ)0x0) {
      DeleteObject(DAT_405fb76c);
    }
    DAT_405fb76c = (HGDIOBJ)0x0;
    if (DAT_405fb77c != (int *)0x0) {
      (**(code **)(*DAT_405fb77c + 8))();
      DAT_405fb77c = (int *)0x0;
    }
    iVar3 = FUN_405e3dd4(DAT_405fb790);
    if (iVar3 == 0) {
      DAT_405fb76c = (HGDIOBJ)FUN_405e3e88(param_1,DAT_405fb790);
    }
    else {
      (**(code **)(*DAT_405fb778 + 0x10))(DAT_405fb778,DAT_405fb790,&DAT_405fb77c);
    }
    if ((DAT_405fb76c == (HGDIOBJ)0x0) && (DAT_405fb77c == (int *)0x0)) {
      pHVar1 = GetDlgItem(param_1,0x248);
      EnableWindow(pHVar1,0);
    }
    if (DAT_405fb794 != (undefined4 *)0x0) {
      FUN_405f8e8c(DAT_405fb794,DAT_405fb790);
      pHVar1 = GetDlgItem(param_1,0x245);
      WVar4 = SendMessageW(pHVar1,0x147,0,0);
      pHVar1 = GetDlgItem(param_1,0x245);
      DAT_405fb790 = (LPWSTR)SendMessageW(pHVar1,0x150,WVar4,0);
      puVar7 = DAT_405fb794;
      LVar5 = SendMessageW((HWND)*DAT_405fb794,0x147,0,0);
      puVar7[1] = LVar5;
    }
    pHVar1 = GetDlgItem(param_1,0x244);
    InvalidateRect(pHVar1,(RECT *)0x0,1);
    FUN_405f7378(param_1,8);
    ppHVar8 = apHStack_248;
  }
  else {
    if (param_2 != 0x111) goto LAB_405e5cd4;
    uVar9 = param_3 & 0xffff;
    if (uVar9 != 1) {
      if (uVar9 == 0x245) {
        if (param_3 >> 0x10 != 1) {
LAB_405e5cd4:
          FUN_405f9bec(local_2c);
          return 0;
        }
        pHVar1 = GetDlgItem(param_1,0x245);
        WVar4 = SendMessageW(pHVar1,0x147,0,0);
        if (WVar4 == 0xffffffff) goto LAB_405e5cd4;
        local_260[0] = (int *)0x0;
        pvVar11 = (HGDIOBJ)0x0;
        pHVar1 = GetDlgItem(param_1,0x245);
        pWVar6 = (LPWSTR)SendMessageW(pHVar1,0x150,WVar4,0);
        if (*pWVar6 == L'\0') {
          DAT_405fb770 = 0;
          pHVar1 = GetDlgItem(param_1,0x248);
          SendMessageW(pHVar1,0xf1,0,0);
          pHVar1 = GetDlgItem(param_1,0x248);
          BVar2 = 0;
        }
        else {
          iVar3 = FUN_405e3dd4(pWVar6);
          if (iVar3 != 0) {
            iVar3 = (**(code **)(*DAT_405fb778 + 0x10))(DAT_405fb778,pWVar6,local_260);
            if (-1 < iVar3) {
              if (local_260[0] == (int *)0x0) goto LAB_405e57d0;
              goto LAB_405e57d8;
            }
LAB_405e57e0:
            SendMessageW((HWND)*DAT_405fb794,0x14e,DAT_405fb794[1],0);
            goto LAB_405e5ca0;
          }
          pvVar11 = (HGDIOBJ)FUN_405e3e88(param_1,pWVar6);
          if (pvVar11 == (HGDIOBJ)0x0) {
LAB_405e57d0:
            iVar3 = -0x7fffbffb;
LAB_405e57d8:
            if (iVar3 < 0) goto LAB_405e57e0;
          }
          pHVar1 = GetDlgItem(param_1,0x248);
          BVar2 = 1;
        }
        EnableWindow(pHVar1,BVar2);
        DAT_405fb798 = 1;
        if (DAT_405fb76c != (HGDIOBJ)0x0) {
          DeleteObject(DAT_405fb76c);
        }
        DAT_405fb76c = (HGDIOBJ)0x0;
        if (DAT_405fb77c != (int *)0x0) {
          (**(code **)(*DAT_405fb77c + 8))();
          DAT_405fb77c = (int *)0x0;
        }
        puVar7 = DAT_405fb794;
        if (pvVar11 == (HGDIOBJ)0x0) {
          DAT_405fb77c = local_260[0];
          pvVar11 = DAT_405fb76c;
        }
        DAT_405fb76c = pvVar11;
        DAT_405fb790 = pWVar6;
        LVar5 = SendMessageW((HWND)*DAT_405fb794,0x147,0,0);
        puVar7[1] = LVar5;
      }
      else {
        if (uVar9 == 0x246) {
          BVar2 = FUN_405e5024(param_1,aWStack_238,0x104);
          if (BVar2 != 0) {
            local_260[0] = (int *)0x0;
            pvVar11 = (HGDIOBJ)0x0;
            iVar10 = 0;
            iVar3 = FUN_405e3dd4(aWStack_238);
            if (iVar3 == 0) {
              pvVar11 = (HGDIOBJ)FUN_405e3e88(param_1,aWStack_238);
            }
            else {
              iVar10 = (**(code **)(*DAT_405fb778 + 0x10))(DAT_405fb778,aWStack_238,local_260);
            }
            if ((-1 < iVar10) && ((pvVar11 != (HGDIOBJ)0x0 || (local_260[0] != (int *)0x0)))) {
              WVar4 = FUN_405f8e8c(DAT_405fb794,aWStack_238);
              puVar7 = DAT_405fb794;
              LVar5 = SendMessageW((HWND)*DAT_405fb794,0x147,0,0);
              ho = DAT_405fb76c;
              puVar7[1] = LVar5;
              DAT_405fb798 = 1;
              if (ho != (HGDIOBJ)0x0) {
                DeleteObject(ho);
              }
              DAT_405fb76c = (HGDIOBJ)0x0;
              if (DAT_405fb77c != (int *)0x0) {
                (**(code **)(*DAT_405fb77c + 8))();
                DAT_405fb77c = (int *)0x0;
              }
              if (pvVar11 == (HGDIOBJ)0x0) {
                DAT_405fb77c = local_260[0];
                pvVar11 = DAT_405fb76c;
              }
              DAT_405fb76c = pvVar11;
              pHVar1 = GetDlgItem(param_1,0x245);
              DAT_405fb790 = (LPWSTR)SendMessageW(pHVar1,0x150,WVar4,0);
              pHVar1 = GetDlgItem(param_1,0x244);
              InvalidateRect(pHVar1,(RECT *)0x0,1);
              pHVar1 = GetDlgItem(param_1,0x248);
              EnableWindow(pHVar1,1);
            }
          }
          pHVar1 = GetDlgItem(param_1,0x246);
          SetFocus(pHVar1);
          goto LAB_405e5ca0;
        }
        if (uVar9 != 0x248) goto LAB_405e5cd4;
        DAT_405fb798 = 1;
        pHVar1 = GetDlgItem(param_1,0x248);
        DAT_405fb770 = SendMessageW(pHVar1,0xf0,0,0);
      }
      pHVar1 = GetDlgItem(param_1,0x244);
      InvalidateRect(pHVar1,(RECT *)0x0,1);
      goto LAB_405e5ca0;
    }
    if (DAT_405fb798 == 0) goto LAB_405e5ca0;
    pHVar1 = GetDlgItem(param_1,0x248);
    DAT_405fb770 = SendMessageW(pHVar1,0xf0,0,0);
    local_258 = (HKEY)0x0;
    local_254 = 0;
    local_250 = 0;
    FUN_405e3f58(&local_258,(HKEY)0x80000001,L"ControlPanel\\Desktop");
    FUN_405e4618(&local_258,L"Tile",DAT_405fb770);
    FUN_405e424c(&local_258,L"Wallpaper",DAT_405fb790);
    PostMessageW((HWND)0xffff,0x1a,0x14,0);
    ppHVar8 = &local_258;
  }
  FUN_405e4020(ppHVar8);
LAB_405e5ca0:
  FUN_405f9bec(local_2c);
  return 1;
}



/* 405e5d10 FUN_405e5d10 */

/* Boundary evidence: original MIPS .pdata 405e5d10..405e5e53. Semantic name remains unreviewed. */

void FUN_405e5d10(HWND param_1,int param_2)

{
  HWND hWnd;
  int iVar1;
  UINT uID;
  int iVar2;
  int iVar3;
  int iVar4;
  wchar_t awStack_58 [20];
  uint local_30;
  
  local_30 = DAT_405fb760;
  hWnd = GetDlgItem(param_1,param_2);
  SendMessageW(hWnd,0x14b,0,0);
  iVar3 = 6;
  if (param_2 != 0x1f6) {
    iVar3 = 5;
  }
  iVar2 = 0;
  if (iVar3 != 0) {
    do {
      uID = 0x8055;
      if (iVar2 != 0) {
        uID = 0x8056;
      }
      if (param_2 == 500) {
        iVar4 = (&DAT_405e1918)[iVar2];
      }
      else {
        iVar4 = (&DAT_405e192c)[iVar2];
      }
      iVar1 = LoadStringW(DAT_405fb7fc,uID,(LPWSTR)0x0,0);
      StringCbPrintfW(awStack_58,0x28,L"%d %s",iVar4 / 0x3c,iVar1);
      SendMessageW(hWnd,0x143,0,(LPARAM)awStack_58);
      iVar2 = iVar2 + 1;
    } while (iVar2 < iVar3);
  }
  FUN_405f9bec(local_30);
  return;
}



/* 405e5e54 FUN_405e5e54 */

/* Boundary evidence: original MIPS .pdata 405e5e54..405e5ec7. Semantic name remains unreviewed. */

void FUN_405e5e54(HWND param_1,int param_2)

{
  HWND pHVar1;
  
  pHVar1 = GetDlgItem(param_1,0x1c7);
  ShowWindow(pHVar1,param_2);
  pHVar1 = GetDlgItem(param_1,0x1b9);
  ShowWindow(pHVar1,param_2);
  pHVar1 = GetDlgItem(param_1,0x1f6);
  ShowWindow(pHVar1,param_2);
  return;
}



/* 405e5ec8 FUN_405e5ec8 */

/* Boundary evidence: original MIPS .pdata 405e5ec8..405e6017. Semantic name remains unreviewed. */

undefined4 FUN_405e5ec8(HWND param_1)

{
  int iVar1;
  int iVar2;
  DWORD DVar3;
  undefined4 uVar4;
  HANDLE local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined1 auStack_4c [4];
  undefined1 auStack_48 [8];
  undefined1 auStack_40 [44];
  uint local_14;
  
  local_14 = DAT_405fb760;
  local_68 = (HANDLE)0x0;
  memset(&local_64,0,4);
  uVar4 = 1;
  memset(&local_60,0,0x14);
  local_60 = 0x14;
  local_5c = 0;
  local_58 = 0;
  local_54 = 0x2c;
  local_50 = 1;
  local_68 = (HANDLE)CreateMsgQueue(0,&local_60);
  if (local_68 != (HANDLE)0x0) {
    iVar1 = RequestPowerNotifications(local_68,8);
    if (iVar1 != 0) {
      local_64 = DAT_405fb7a0;
      while( true ) {
        DVar3 = WaitForMultipleObjects(2,&local_68,0,0xffffffff);
        if (DVar3 != 0) break;
        iVar2 = ReadMsgQueue(local_68,auStack_40,0x2c,auStack_48,0,auStack_4c);
        if (iVar2 != 0) {
          SendMessageW(param_1,0x401,0,(LPARAM)auStack_40);
        }
      }
      uVar4 = 0;
      StopPowerNotifications(iVar1);
    }
    if (local_68 != (HANDLE)0x0) {
      CloseHandle(local_68);
    }
  }
  FUN_405f9bec(local_14);
  return uVar4;
}



/* 405e6018 FUN_405e6018 */

/* Boundary evidence: original MIPS .pdata 405e6018..405e6113. Semantic name remains unreviewed. */

void FUN_405e6018(wchar_t *param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  undefined4 local_30;
  undefined1 local_2c [4];
  undefined1 auStack_28 [4];
  undefined1 auStack_24 [4];
  undefined1 auStack_20 [4];
  undefined1 auStack_1c [4];
  undefined1 auStack_18 [4];
  undefined1 auStack_14 [4];
  
  iVar1 = swscanf(param_1,L"{%08lX-%04X-%04X-%02X%02X-%02X%02X%02X%02X%02X%02X}",param_2,param_2 + 4
                  ,param_2 + 6,&local_30,local_2c,auStack_28,auStack_24,auStack_20,auStack_1c,
                  auStack_18,auStack_14);
  if (iVar1 == 0xb) {
    for (uVar2 = 0; uVar2 < 8; uVar2 = uVar2 + 1) {
      *(char *)(uVar2 + param_2 + 8) = (char)*(undefined4 *)(local_2c + uVar2 * 4 + -4);
    }
  }
  return;
}



/* 405e6114 FUN_405e6114 */

/* Boundary evidence: original MIPS .pdata 405e6114..405e611f. Semantic name remains unreviewed. */

undefined4 FUN_405e6114(void)

{
  return 1;
}



/* 405e6120 FUN_405e6120 */

/* Boundary evidence: original MIPS .pdata 405e6120..405e626b. Semantic name remains unreviewed. */

undefined4 FUN_405e6120(HWND param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  LRESULT LVar2;
  WPARAM wParam;
  int iVar3;
  tagRECT local_50;
  undefined4 local_40 [2];
  int local_38;
  undefined4 local_34;
  
  if (param_3 < 1) {
LAB_405e6150:
    uVar1 = 0;
  }
  else {
    SendMessageW(param_1,0x1009,0,0);
    local_40[0] = 6;
    GetClientRect(param_1,&local_50);
    iVar3 = local_50.right - local_50.left;
    if (param_3 == 0) {
      trap(0x1c00);
    }
    if ((param_3 == -1) && (iVar3 == -0x80000000)) {
      trap(0x1800);
    }
    wParam = 0;
    if (0 < param_3) {
      do {
        local_38 = iVar3 / param_3;
        if (wParam == 0) {
          if (param_3 == 0) {
            trap(0x1c00);
          }
          if ((param_3 == -1) && (iVar3 == -0x80000000)) {
            trap(0x1800);
          }
          local_38 = iVar3 % param_3 + iVar3 / param_3;
        }
        local_34 = *(undefined4 *)(wParam * 4 + param_2);
        LVar2 = SendMessageW(param_1,0x1061,wParam,(LPARAM)local_40);
        if (LVar2 == -1) goto LAB_405e6150;
        wParam = wParam + 1;
      } while ((int)wParam < param_3);
    }
    uVar1 = 1;
  }
  return uVar1;
}



/* 405e626c FUN_405e626c */

/* Boundary evidence: original MIPS .pdata 405e626c..405e63ff. Semantic name remains unreviewed. */

undefined4 FUN_405e626c(HWND param_1,undefined4 *param_2)

{
  int iVar1;
  WPARAM wParam;
  int local_288 [2];
  undefined4 local_280;
  undefined4 local_27c;
  undefined4 local_278;
  undefined4 *local_26c;
  undefined1 auStack_250 [8];
  undefined4 local_248;
  int local_23c;
  wchar_t awStack_220 [260];
  undefined2 local_18;
  uint local_14;
  
  local_14 = DAT_405fb760;
  local_18 = 0;
  _snwprintf(awStack_220,0x104,L"{%08x-%04x-%04x-%04x-%02x%02x%02x%02x%02x%02x}\\%s",*param_2,
             (uint)*(ushort *)(param_2 + 1),(uint)*(ushort *)((int)param_2 + 6),
             (uint)*(byte *)(param_2 + 2) * 0x100 + (uint)*(byte *)((int)param_2 + 9),
             (uint)*(byte *)((int)param_2 + 10),(uint)*(byte *)((int)param_2 + 0xb),
             (uint)*(byte *)(param_2 + 3),(uint)*(byte *)((int)param_2 + 0xd),
             (uint)*(byte *)((int)param_2 + 0xe),(uint)*(byte *)((int)param_2 + 0xf),param_2 + 7);
  iVar1 = GetDevicePower(awStack_220,1,local_288);
  if (((iVar1 == 0) && (-1 < local_288[0])) && (local_288[0] < 5)) {
    memset(&local_280,0,0x2c);
    local_280 = 1;
    local_27c = 0;
    local_278 = 0;
    local_26c = param_2 + 7;
    wParam = SendMessageW(param_1,0x104d,0,(LPARAM)&local_280);
    if (wParam != 0xffffffff) {
      local_248 = 1;
      local_23c = LoadStringW(DAT_405fb7fc,*(UINT *)(&DAT_405e1a98 + local_288[0] * 4),(LPWSTR)0x0,0
                             );
      SendMessageW(param_1,0x1074,wParam,(LPARAM)auStack_250);
      FUN_405f9bec(local_14);
      return 1;
    }
  }
  FUN_405f9bec(local_14);
  return 0;
}



/* 405e6400 FUN_405e6400 */

/* Boundary evidence: original MIPS .pdata 405e6400..405e647b. Semantic name remains unreviewed. */

undefined4
FUN_405e6400(undefined4 *param_1,LPWSTR param_2,DWORD param_3,LPBYTE param_4,DWORD param_5)

{
  LSTATUS LVar1;
  DWORD dwIndex;
  DWORD local_res8 [2];
  DWORD aDStack_10 [2];
  
  if ((HKEY)*param_1 != (HKEY)0x0) {
    dwIndex = param_1[1];
    param_5 = param_5 << 1;
    param_1[1] = dwIndex + 1;
    local_res8[0] = param_3;
    LVar1 = RegEnumValueW((HKEY)*param_1,dwIndex,param_2,local_res8,(LPDWORD)0x0,aDStack_10,param_4,
                          &param_5);
    if (LVar1 == 0) {
      return 1;
    }
  }
  return 0;
}



/* 405e647c FUN_405e647c */

/* Boundary evidence: original MIPS .pdata 405e647c..405e665b. Semantic name remains unreviewed. */

undefined4 FUN_405e647c(HWND param_1,int *param_2,uint *param_3,int param_4)

{
  HWND hWnd;
  int iVar1;
  int iVar2;
  LRESULT LVar3;
  UINT uID;
  uint *puVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  wchar_t awStack_a8 [60];
  undefined2 local_30;
  uint local_2c;
  
  local_2c = DAT_405fb760;
  iVar6 = 0;
  local_30 = 0;
  do {
    hWnd = GetDlgItem(param_1,*param_2);
    SendMessageW(hWnd,0x14b,0,0);
    iVar5 = 0;
    puVar4 = param_3;
    if (0 < param_4) {
      do {
        if (*puVar4 == 0) {
          iVar1 = LoadStringW(DAT_405fb7fc,0x83c4,(LPWSTR)0x0,0);
          _snwprintf(awStack_a8,0x3c,L"%s",iVar1);
        }
        else {
          uVar7 = *puVar4 / 0x3c;
          uID = 0x8055;
          if (uVar7 != 1) {
            uID = 0x8056;
          }
          iVar1 = LoadStringW(DAT_405fb7fc,uID,(LPWSTR)0x0,0);
          iVar2 = LoadStringW(DAT_405fb7fc,0x83c5,(LPWSTR)0x0,0);
          _snwprintf(awStack_a8,0x3c,L"%s%u %s",iVar2,uVar7,iVar1);
        }
        LVar3 = SendMessageW(hWnd,0x143,0,(LPARAM)awStack_a8);
        if ((LVar3 == -1) || (LVar3 == -2)) {
          FUN_405f9bec(local_2c);
          return 0;
        }
        iVar5 = iVar5 + 1;
        puVar4 = puVar4 + 1;
      } while (iVar5 < param_4);
    }
    iVar6 = iVar6 + 1;
    param_2 = param_2 + 1;
    if (2 < iVar6) {
      FUN_405f9bec(local_2c);
      return 1;
    }
  } while( true );
}



/* 405e665c FUN_405e665c */

/* Boundary evidence: original MIPS .pdata 405e665c..405e6743. Semantic name remains unreviewed. */

undefined4 FUN_405e665c(HWND param_1,int param_2,int param_3,int *param_4,int *param_5,int param_6)

{
  HWND hWnd;
  WPARAM WVar1;
  int *piVar2;
  WPARAM WVar3;
  WPARAM wParam;
  int iVar4;
  int iVar5;
  int iVar6;
  
  iVar4 = param_3 - (int)param_4;
  iVar6 = param_2 - (int)param_4;
  iVar5 = 3;
  do {
    WVar3 = *(WPARAM *)(iVar4 + (int)param_4);
    WVar1 = 0;
    wParam = WVar3;
    if (0 < param_6) {
      piVar2 = param_5;
      do {
        wParam = WVar1;
        if (*param_4 == *piVar2) break;
        WVar1 = WVar1 + 1;
        piVar2 = piVar2 + 1;
        wParam = WVar3;
      } while ((int)WVar1 < param_6);
    }
    hWnd = GetDlgItem(param_1,*(int *)(iVar6 + (int)param_4));
    SendMessageW(hWnd,0x14e,wParam,0);
    param_4 = param_4 + 1;
    iVar5 = iVar5 + -1;
    if (iVar5 == 0) {
      return 1;
    }
  } while( true );
}



/* 405e6744 FUN_405e6744 */

/* Boundary evidence: original MIPS .pdata 405e6744..405e6843. Semantic name remains unreviewed. */

undefined4 FUN_405e6744(HWND param_1,int param_2,int *param_3)

{
  HICON hIcon;
  HWND hWnd;
  int iVar1;
  
  hIcon = LoadImageW(DAT_405fb7fc,(LPCWSTR)(uint)*(ushort *)(param_2 + 4),1,0,0,0);
  if (hIcon != (HICON)0x0) {
    hWnd = GetDlgItem(param_1,0x1ac);
    SendMessageW(hWnd,0x172,1,(LPARAM)hIcon);
    DestroyIcon(hIcon);
  }
  iVar1 = FUN_405e647c(param_1,(int *)&DAT_405e19c8,*(uint **)(param_2 + 0x14),
                       *(int *)(param_2 + 0x18));
  if ((iVar1 != 0) &&
     (iVar1 = FUN_405e665c(param_1,0x405e19c8,param_2 + 0x1c,param_3,*(int **)(param_2 + 0x14),
                           *(int *)(param_2 + 0x18)), iVar1 != 0)) {
    return 1;
  }
  return 0;
}



/* 405e6844 FUN_405e6844 */

/* Boundary evidence: original MIPS .pdata 405e6844..405e68b7. Semantic name remains unreviewed. */

void FUN_405e6844(HWND param_1,int *param_2,int param_3,int param_4)

{
  HWND hWnd;
  
  if (0 < param_3) {
    do {
      hWnd = GetDlgItem(param_1,*param_2);
      ShowWindow(hWnd,param_4);
      param_2 = param_2 + 1;
      param_3 = param_3 + -1;
    } while (param_3 != 0);
  }
  return;
}



/* 405e68b8 FUN_405e68b8 */

/* Boundary evidence: original MIPS .pdata 405e68b8..405e6933. Semantic name remains unreviewed. */

void FUN_405e68b8(undefined4 *param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  HKEY apHStack_20 [4];
  
  FUN_405e3fc4(apHStack_20,(HKEY)0x80000002,L"SYSTEM\\CurrentControlSet\\Control\\Power");
  uVar1 = FUN_405e4194(apHStack_20,L"BattPowerOff",0);
  *param_1 = uVar1;
  uVar1 = FUN_405e4194(apHStack_20,L"ExtPowerOff",0);
  *param_2 = uVar1;
  FUN_405e4020(apHStack_20);
  return;
}



/* 405e6934 FUN_405e6934 */

/* Boundary evidence: original MIPS .pdata 405e6934..405e69bb. Semantic name remains unreviewed. */

void FUN_405e6934(undefined4 param_1,undefined4 param_2)

{
  HKEY local_20;
  undefined4 local_1c;
  undefined4 local_18;
  
  local_20 = (HKEY)0x0;
  local_1c = 0;
  local_18 = 0;
  FUN_405e3f58(&local_20,(HKEY)0x80000002,L"SYSTEM\\CurrentControlSet\\Control\\Power");
  FUN_405e4618(&local_20,L"BattPowerOff",param_1);
  FUN_405e4618(&local_20,L"ExtPowerOff",param_2);
  NotifyWinUserSystem(3);
  FUN_405e4020(&local_20);
  return;
}



/* 405e69bc SleepDlgProc */

/* Boundary evidence: original MIPS .pdata 405e69bc..405e6c3f. Semantic name remains unreviewed. */

undefined4 SleepDlgProc(HWND param_1,int param_2,short param_3)

{
  HWND pHVar1;
  LRESULT LVar2;
  int iVar3;
  undefined4 uVar4;
  WPARAM WVar5;
  int *piVar6;
  undefined4 uVar7;
  int local_20;
  int local_1c;
  
                    /* 0x69bc  23  SleepDlgProc */
  if (param_2 == 0x110) {
    FUN_405e68b8(&local_20,&local_1c);
    FUN_405e5d10(param_1,500);
    FUN_405e5d10(param_1,0x1f6);
    piVar6 = &DAT_405e1918;
    if (local_20 != 0) {
      WVar5 = 0;
      do {
        if (local_20 == *piVar6) goto LAB_405e6b5c;
        piVar6 = piVar6 + 1;
        WVar5 = WVar5 + 1;
      } while ((int)piVar6 < 0x405e192c);
    }
    WVar5 = 2;
LAB_405e6b5c:
    pHVar1 = GetDlgItem(param_1,500);
    SendMessageW(pHVar1,0x14e,WVar5,0);
    if (local_1c != 0) {
      WVar5 = 0;
      piVar6 = &DAT_405e192c;
      do {
        if (local_1c == *piVar6) goto LAB_405e6bb8;
        piVar6 = piVar6 + 1;
        WVar5 = WVar5 + 1;
      } while ((int)piVar6 < 0x405e1944);
    }
    WVar5 = 2;
LAB_405e6bb8:
    pHVar1 = GetDlgItem(param_1,0x1f6);
    SendMessageW(pHVar1,0x14e,WVar5,0);
    pHVar1 = GetDlgItem(param_1,0x1f5);
    SendMessageW(pHVar1,0xf1,(uint)(0 < local_1c),0);
    iVar3 = 5;
    if (local_1c < 1) {
LAB_405e6c10:
      iVar3 = 0;
    }
LAB_405e6c14:
    uVar4 = 1;
    FUN_405e5e54(param_1,iVar3);
  }
  else {
    if (param_2 == 0x111) {
      if (param_3 == 1) {
        uVar4 = 0;
        uVar7 = 0;
        pHVar1 = GetDlgItem(param_1,500);
        LVar2 = SendMessageW(pHVar1,0x147,0,0);
        if (-1 < LVar2) {
          uVar4 = (&DAT_405e1918)[LVar2];
        }
        pHVar1 = GetDlgItem(param_1,0x1f5);
        LVar2 = SendMessageW(pHVar1,0xf0,0,0);
        if (LVar2 != 0) {
          pHVar1 = GetDlgItem(param_1,0x1f6);
          LVar2 = SendMessageW(pHVar1,0x147,0,0);
          if (-1 < LVar2) {
            uVar7 = (&DAT_405e192c)[LVar2];
          }
        }
        FUN_405e6934(uVar4,uVar7);
        return 1;
      }
      if (param_3 == 0x1f5) {
        pHVar1 = GetDlgItem(param_1,0x1f5);
        LVar2 = SendMessageW(pHVar1,0xf0,0,0);
        iVar3 = 5;
        if (LVar2 == 0) goto LAB_405e6c10;
        goto LAB_405e6c14;
      }
    }
    uVar4 = 0;
  }
  return uVar4;
}



/* 405e6c40 FUN_405e6c40 */

/* Boundary evidence: original MIPS .pdata 405e6c40..405e7043. Semantic name remains unreviewed. */

void FUN_405e6c40(HWND param_1,int param_2)

{
  int iVar1;
  HWND pHVar2;
  BOOL BVar3;
  size_t sVar4;
  uint uVar5;
  uint *puVar6;
  uint uVar7;
  int *piVar8;
  int nCmdShow;
  uint *puVar9;
  int iVar10;
  uint local_448 [2];
  uint local_440 [2];
  SYSTEMTIME SStack_438;
  WCHAR local_428 [256];
  WCHAR aWStack_228 [256];
  uint local_28;
  
  local_28 = DAT_405fb760;
  local_428[0] = L'\0';
  iVar1 = BatteryDrvrSupportsChangeNotification();
  iVar10 = 2;
  if (iVar1 == 0) {
    pHVar2 = GetDlgItem(param_1,0x1f7);
    BVar3 = IsWindowVisible(pHVar2);
    if (BVar3 != 0) {
      FUN_405e6844(param_1,(int *)&DAT_405e1968,4,0);
    }
  }
  else {
    pHVar2 = GetDlgItem(param_1,0x1f7);
    BVar3 = IsWindowVisible(pHVar2);
    if (BVar3 == 0) {
      FUN_405e6844(param_1,(int *)&DAT_405e1968,4,5);
    }
    BatteryGetLifeTimeInfo(&SStack_438,local_448,local_440);
    GetDateFormatW(0x400,1,&SStack_438,(LPCWSTR)0x0,local_428,0x100);
    sVar4 = wcslen(local_428);
    if (sVar4 + 2 < 0x100) {
      local_428[sVar4] = L' ';
      GetTimeFormatW(0x400,2,&SStack_438,(LPCWSTR)0x0,local_428 + sVar4 + 1,0x100 - (sVar4 + 1));
    }
    GetDlgItemTextW(param_1,0x1f7,aWStack_228,0x100);
    iVar1 = lstrcmpW(local_428,aWStack_228);
    if (iVar1 != 0) {
      SetDlgItemTextW(param_1,0x1f7,local_428);
    }
    local_448[0] = local_448[0] / 60000;
    StringCbPrintfW(local_428,0x200,L"%d:%02d",local_448[0] / 0x3c,local_448[0] % 0x3c);
    GetDlgItemTextW(param_1,0x1f8,aWStack_228,0x100);
    iVar1 = lstrcmpW(local_428,aWStack_228);
    if (iVar1 != 0) {
      SetDlgItemTextW(param_1,0x1f8,local_428);
    }
  }
  if (*(byte *)(param_2 + 0x22) < 0x65) {
    wsprintfW(local_428,L"%d%%",(uint)*(byte *)(param_2 + 0x22));
    GetDlgItemTextW(param_1,0x1f9,aWStack_228,0x100);
    iVar1 = lstrcmpW(local_428,aWStack_228);
    if (iVar1 != 0) {
      SetDlgItemTextW(param_1,0x1f9,local_428);
    }
    pHVar2 = GetDlgItem(param_1,0x1f9);
    BVar3 = IsWindowVisible(pHVar2);
    if (BVar3 != 0) goto LAB_405e6f1c;
    iVar1 = 5;
  }
  else {
    pHVar2 = GetDlgItem(param_1,0x1f9);
    BVar3 = IsWindowVisible(pHVar2);
    if (BVar3 == 0) goto LAB_405e6f1c;
    iVar1 = 0;
  }
  FUN_405e6844(param_1,(int *)&DAT_405e1978,2,iVar1);
LAB_405e6f1c:
  if ((*(byte *)(param_2 + 0x21) & 8) == 0) {
    iVar1 = 0x1fc;
    if (*(char *)(param_2 + 0x20) != '\x01') {
      iVar1 = 0x1fa;
    }
  }
  else {
    iVar1 = 0x1fb;
  }
  uVar7 = 0;
  do {
    nCmdShow = 5;
    if (iVar1 != *(int *)((int)&DAT_405e1980 + uVar7)) {
      nCmdShow = 0;
    }
    pHVar2 = GetDlgItem(param_1,*(int *)((int)&DAT_405e1980 + uVar7));
    ShowWindow(pHVar2,nCmdShow);
    uVar7 = uVar7 + 4;
  } while (uVar7 < 0xc);
  puVar6 = local_440;
  local_440[0] = (uint)*(byte *)(param_2 + 0x21);
  local_440[1] = (uint)*(byte *)(param_2 + 0x23);
  do {
    if (*puVar6 == 0xff) {
      *puVar6 = 0;
    }
    iVar10 = iVar10 + -1;
    puVar6 = puVar6 + 1;
  } while (iVar10 != 0);
  piVar8 = &DAT_405e1944;
  puVar6 = local_440;
  do {
    uVar7 = *puVar6;
    puVar9 = &DAT_405e195c;
    do {
      uVar5 = *puVar9;
      pHVar2 = GetDlgItem(param_1,*piVar8);
      EnableWindow(pHVar2,uVar7 & uVar5);
      puVar9 = puVar9 + 1;
      piVar8 = piVar8 + 1;
    } while ((int)puVar9 < 0x405e1968);
    puVar6 = puVar6 + 1;
  } while ((int)piVar8 < 0x405e195c);
  FUN_405f9bec(local_28);
  return;
}



/* 405e7044 FUN_405e7044 */

/* Boundary evidence: original MIPS .pdata 405e7044..405e7217. Semantic name remains unreviewed. */

undefined4 FUN_405e7044(int param_1,int *param_2,uint param_3,undefined4 param_4,uint *param_5)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  HKEY local_270 [4];
  undefined4 local_260;
  undefined4 local_25c;
  undefined4 local_258;
  undefined4 local_254;
  undefined4 local_250;
  undefined1 auStack_248 [16];
  WCHAR aWStack_238 [260];
  undefined2 local_30;
  uint local_2c;
  
  local_2c = DAT_405fb760;
  FUN_405e3fc4(local_270,(HKEY)0x80000002,L"SYSTEM\\CurrentControlSet\\Control\\Power\\Interfaces");
  uVar2 = 0;
  uVar3 = 0;
  local_30 = 0;
  if (local_270[0] != (HKEY)0x0) {
    memset(&local_260,0,0x14);
    local_260 = 0x14;
    local_25c = 0;
    local_258 = 0;
    local_250 = 1;
    local_254 = param_4;
    if (((param_1 != 0) && (param_2 != (int *)0x0)) && (param_3 != 0)) {
      iVar4 = param_1 - (int)param_2;
      do {
        iVar1 = FUN_405e6400(local_270,aWStack_238,0x104,(LPBYTE)0x0,0);
        if (iVar1 == 0) break;
        iVar1 = FUN_405e6018(aWStack_238,(int)auStack_248);
        if (iVar1 != 0) {
          iVar1 = CreateMsgQueue(0,&local_260);
          *(int *)(iVar4 + (int)param_2) = iVar1;
          if (iVar1 == 0) goto LAB_405e71d8;
          iVar1 = RequestDeviceNotifications(auStack_248,iVar1,1);
          *param_2 = iVar1;
          if (iVar1 == 0) goto LAB_405e71d8;
          param_2 = param_2 + 1;
          uVar2 = uVar2 + 1;
        }
      } while (uVar2 < param_3);
    }
    iVar4 = FUN_405e6400(local_270,aWStack_238,0x104,(LPBYTE)0x0,0);
    while (iVar4 != 0) {
      iVar4 = FUN_405e6018(aWStack_238,(int)auStack_248);
      if (iVar4 != 0) {
        uVar2 = uVar2 + 1;
      }
      iVar4 = FUN_405e6400(local_270,aWStack_238,0x104,(LPBYTE)0x0,0);
    }
    *param_5 = uVar2;
    uVar3 = 1;
  }
LAB_405e71d8:
  FUN_405e4020(local_270);
  FUN_405f9bec(local_2c);
  return uVar3;
}



/* 405e7218 FUN_405e7218 */

/* Boundary evidence: original MIPS .pdata 405e7218..405e745b. Semantic name remains unreviewed. */

undefined4 FUN_405e7218(HWND param_1)

{
  uint uVar1;
  int iVar2;
  DWORD DVar3;
  uint uVar4;
  int *hMem;
  SIZE_T uBytes;
  HANDLE *lpHandles;
  HANDLE *ppvVar5;
  undefined4 uVar6;
  uint local_d8;
  undefined1 auStack_d4 [4];
  undefined1 auStack_d0 [8];
  undefined4 local_c8;
  undefined1 auStack_c4 [156];
  uint local_28;
  
  local_28 = DAT_405fb760;
  local_c8 = 0;
  memset(auStack_c4,0,0x9c);
  local_d8 = 0;
  lpHandles = (HANDLE *)0x0;
  hMem = (int *)0x0;
  uVar6 = 1;
  iVar2 = FUN_405e7044(0,(int *)0x0,0,0xa0,&local_d8);
  uVar1 = local_d8;
  uVar4 = uVar1;
  if (iVar2 != 0) {
    uBytes = local_d8 * 4;
    lpHandles = LocalAlloc(0x40,uBytes + 4);
    hMem = LocalAlloc(0x40,uBytes);
    if (((lpHandles != (HANDLE *)0x0) && (hMem != (int *)0x0)) &&
       (iVar2 = FUN_405e7044((int)lpHandles,hMem,uVar1,0xa0,&local_d8), uVar4 = local_d8, iVar2 != 0
       )) {
      if (uVar1 < local_d8) {
        uVar4 = uVar1;
      }
      if (uVar4 == 0) goto LAB_405e7408;
      lpHandles[uVar4] = DAT_405fb79c;
      while (DVar3 = WaitForMultipleObjects(uVar4 + 1,lpHandles,0,0xffffffff), DVar3 < uVar4) {
        iVar2 = ReadMsgQueue(lpHandles[DVar3],&local_c8,0xa0,auStack_d0,0,auStack_d4);
        if (iVar2 != 0) {
          SendMessageW(param_1,0x401,0,(LPARAM)&local_c8);
        }
      }
      uVar6 = 0;
    }
  }
  if (uVar4 != 0) {
    ppvVar5 = lpHandles;
    do {
      if ((hMem != (int *)0x0) && (*(int *)(((int)hMem - (int)lpHandles) + (int)ppvVar5) != 0)) {
        StopDeviceNotifications();
      }
      if ((lpHandles != (HANDLE *)0x0) && (*ppvVar5 != (HANDLE)0x0)) {
        CloseHandle(*ppvVar5);
      }
      uVar4 = uVar4 - 1;
      ppvVar5 = ppvVar5 + 1;
    } while (uVar4 != 0);
  }
LAB_405e7408:
  if (lpHandles != (HANDLE *)0x0) {
    LocalFree(lpHandles);
  }
  if (hMem != (int *)0x0) {
    LocalFree(hMem);
  }
  FUN_405f9bec(local_28);
  return uVar6;
}



/* 405e745c PowerDeviceDlgProc */

/* Boundary evidence: original MIPS .pdata 405e745c..405e7663. Semantic name remains unreviewed. */

undefined4 PowerDeviceDlgProc(HWND param_1,int param_2,ushort param_3,undefined4 *param_4)

{
  HWND pHVar1;
  WPARAM wParam;
  undefined4 uVar2;
  int local_30;
  int local_2c;
  undefined4 local_28;
  undefined4 *local_24;
  
                    /* 0x745c  19  PowerDeviceDlgProc */
  if (param_2 == 0x110) {
    pHVar1 = GetDlgItem(param_1,0x209);
    local_30 = LoadStringW(DAT_405fb7fc,0x83c1,(LPWSTR)0x0,0);
    local_2c = LoadStringW(DAT_405fb7fc,0x83c2,(LPWSTR)0x0,0);
    FUN_405e6120(pHVar1,(int)&local_30,2);
    DAT_405fb79c = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
    if (DAT_405fb79c != (HANDLE)0x0) {
      DAT_405fb7a4 = CreateThread((LPSECURITY_ATTRIBUTES)0x0,0,FUN_405e7218,param_1,0,(LPDWORD)0x0);
    }
LAB_405e7644:
    uVar2 = 1;
  }
  else {
    if (param_2 == 0x111) {
      if ((param_3 != 0) && (param_3 < 3)) {
        if (DAT_405fb79c != (HANDLE)0x0) {
          if (DAT_405fb7a4 != (HANDLE)0x0) {
            EventModify(DAT_405fb79c,3);
            WaitForSingleObject(DAT_405fb7a4,0xffffffff);
            CloseHandle(DAT_405fb7a4);
            DAT_405fb7a4 = (HANDLE)0x0;
          }
          CloseHandle(DAT_405fb79c);
          DAT_405fb79c = (HANDLE)0x0;
        }
        goto LAB_405e7644;
      }
    }
    else if (param_2 == 0x401) {
      pHVar1 = GetDlgItem(param_1,0x209);
      if (param_4[5] == 1) {
        FUN_405e626c(pHVar1,param_4);
        return 1;
      }
      local_28 = 2;
      local_24 = param_4 + 7;
      wParam = SendMessageW(pHVar1,0x1053,0xffffffff,(LPARAM)&local_28);
      if (wParam == 0xffffffff) {
        return 1;
      }
      SendMessageW(pHVar1,0x1008,wParam,0);
      return 1;
    }
    uVar2 = 0;
  }
  return uVar2;
}



/* 405e7664 FUN_405e7664 */

/* Boundary evidence: original MIPS .pdata 405e7664..405e7723. Semantic name remains unreviewed. */

undefined4 FUN_405e7664(LPCWSTR param_1,int param_2,int *param_3)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  HKEY local_28 [4];
  
  FUN_405e3fc4(local_28,(HKEY)0x80000002,param_1);
  if (local_28[0] == (HKEY)0x0) {
    FUN_405e4020(local_28);
    uVar2 = 0;
  }
  else {
    iVar3 = 0;
    iVar4 = param_2 - (int)param_3;
    do {
      iVar1 = FUN_405e4194(local_28,*(LPCWSTR *)(iVar4 + (int)param_3),0xbeef);
      *param_3 = iVar1;
      if (iVar1 == 0xbeef) {
        uVar2 = 0;
        goto LAB_405e76fc;
      }
      iVar3 = iVar3 + 1;
      param_3 = param_3 + 1;
    } while (iVar3 < 3);
    uVar2 = 1;
LAB_405e76fc:
    FUN_405e4020(local_28);
  }
  return uVar2;
}



/* 405e7724 FUN_405e7724 */

/* Boundary evidence: original MIPS .pdata 405e7724..405e77d7. Semantic name remains unreviewed. */

undefined4 FUN_405e7724(LPCWSTR param_1,undefined4 *param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  HKEY local_20 [4];
  
  FUN_405e3fc4(local_20,(HKEY)0x80000002,param_1);
  if (local_20[0] == (HKEY)0x0) {
    FUN_405e4020(local_20);
    uVar2 = 0;
  }
  else {
    iVar3 = 0;
    iVar4 = param_3 - (int)param_2;
    do {
      iVar1 = FUN_405e4618(local_20,(LPCWSTR)*param_2,*(undefined4 *)(iVar4 + (int)param_2));
      if (iVar1 == 0) {
        uVar2 = 0;
        goto LAB_405e77b4;
      }
      iVar3 = iVar3 + 1;
      param_2 = param_2 + 1;
    } while (iVar3 < 3);
    uVar2 = 1;
LAB_405e77b4:
    FUN_405e4020(local_20);
  }
  return uVar2;
}



/* 405e77d8 PowerTimeoutsDlgProc */

/* Boundary evidence: original MIPS .pdata 405e77d8..405e7b97. Semantic name remains unreviewed. */

undefined4 PowerTimeoutsDlgProc(HWND param_1,int param_2,uint param_3,HWND param_4)

{
  HWND pHVar1;
  LRESULT LVar2;
  WPARAM WVar3;
  HANDLE hObject;
  uint uVar4;
  int iVar5;
  undefined **ppuVar6;
  undefined *puVar7;
  undefined4 *puVar8;
  int iVar9;
  int *piVar10;
  int iVar11;
  char local_40 [24];
  
                    /* 0x77d8  20  PowerTimeoutsDlgProc */
  if (param_2 == 0x110) {
    pHVar1 = GetDlgItem(param_1,0x20d);
    uVar4 = 0;
    ppuVar6 = &PTR_DAT_405fb410;
    do {
      iVar5 = LoadStringW(DAT_405fb7fc,**(UINT **)((int)&PTR_DAT_405fb410 + uVar4),(LPWSTR)0x0,0);
      SendMessageW(pHVar1,0x143,0,iVar5);
      uVar4 = uVar4 + 4;
    } while (uVar4 < 8);
    iVar5 = GetSystemPowerStatusEx(local_40,1);
    if ((iVar5 != 0) && (local_40[0] == '\x01')) {
      DAT_405fb7c0 = 1;
    }
    SendMessageW(pHVar1,0x14e,DAT_405fb7c0,0);
    piVar10 = (int *)&DAT_405fb7a8;
    iVar5 = 2;
    do {
      FUN_405e7664(L"SYSTEM\\CurrentControlSet\\Control\\Power\\Timeouts",(int)(*ppuVar6 + 8),
                   piVar10);
      piVar10 = piVar10 + 3;
      iVar5 = iVar5 + -1;
      ppuVar6 = ppuVar6 + 1;
    } while (iVar5 != 0);
    FUN_405e6744(param_1,(int)(&PTR_DAT_405fb410)[DAT_405fb7c0],
                 (int *)(&DAT_405fb7a8 + DAT_405fb7c0 * 0xc));
    return 1;
  }
  if (param_2 == 0x111) {
    uVar4 = param_3 & 0xffff;
    if (uVar4 == 1) {
      iVar5 = DAT_405fb7c0 * 0xc;
      ppuVar6 = &PTR_DAT_405fb410;
      puVar7 = &DAT_405fb7a8;
      iVar11 = *(int *)((&PTR_DAT_405fb410)[DAT_405fb7c0] + 0x14);
      iVar9 = 3;
      puVar8 = (undefined4 *)(&DAT_405fb7a8 + iVar5);
      do {
        pHVar1 = GetDlgItem(param_1,*(int *)(((int)&DAT_405e19c8 - (int)(&DAT_405fb7a8 + iVar5)) +
                                            (int)puVar8));
        LVar2 = SendMessageW(pHVar1,0x147,0,0);
        *puVar8 = *(undefined4 *)(LVar2 * 4 + iVar11);
        iVar9 = iVar9 + -1;
        puVar8 = puVar8 + 1;
      } while (iVar9 != 0);
      iVar5 = 2;
      do {
        FUN_405e7724(L"SYSTEM\\CurrentControlSet\\Control\\Power\\Timeouts",
                     (undefined4 *)(*ppuVar6 + 8),(int)puVar7);
        puVar7 = puVar7 + 0xc;
        iVar5 = iVar5 + -1;
        ppuVar6 = ppuVar6 + 1;
      } while (iVar5 != 0);
      hObject = OpenEventW(0x1f0003,0,L"PowerManager/ReloadActivityTimeouts");
      if (hObject == (HANDLE)0x0) {
        return 1;
      }
      EventModify(hObject,3);
      CloseHandle(hObject);
      return 1;
    }
    if (uVar4 == 2) {
      return 1;
    }
    if ((uVar4 == 0x20d) && (param_3 >> 0x10 == 1)) {
      iVar5 = DAT_405fb7c0 * 0xc;
      iVar9 = 3;
      iVar11 = *(int *)((&PTR_DAT_405fb410)[DAT_405fb7c0] + 0x14);
      puVar8 = (undefined4 *)(&DAT_405fb7a8 + iVar5);
      do {
        pHVar1 = GetDlgItem(param_1,*(int *)(((int)&DAT_405e19c8 - (int)(&DAT_405fb7a8 + iVar5)) +
                                            (int)puVar8));
        LVar2 = SendMessageW(pHVar1,0x147,0,0);
        *puVar8 = *(undefined4 *)(LVar2 * 4 + iVar11);
        iVar9 = iVar9 + -1;
        puVar8 = puVar8 + 1;
      } while (iVar9 != 0);
      WVar3 = SendMessageW(param_4,0x147,0,0);
      if (WVar3 != 0xffffffff) {
        DAT_405fb7c0 = WVar3;
      }
      FUN_405e6744(param_1,(int)(&PTR_DAT_405fb410)[DAT_405fb7c0],
                   (int *)(&DAT_405fb7a8 + DAT_405fb7c0 * 0xc));
      return 1;
    }
  }
  return 0;
}



/* 405e7b98 PowerCallback */

/* Boundary evidence: original MIPS .pdata 405e7b98..405e7c3f. Semantic name remains unreviewed. */

undefined4 PowerCallback(int param_1)

{
  int iVar1;
  uint uVar2;
  int aiStack_28 [4];
  
                    /* 0x7b98  18  PowerCallback */
  uVar2 = 0;
  do {
    iVar1 = FUN_405e7664(L"SYSTEM\\CurrentControlSet\\Control\\Power\\Timeouts",
                         *(int *)((int)&PTR_DAT_405fb410 + uVar2) + 8,aiStack_28);
    if (iVar1 == 0) {
      *(undefined **)(param_1 + 0x24) = &DAT_405e18c4;
      return 1;
    }
    uVar2 = uVar2 + 4;
  } while (uVar2 < 8);
  *(undefined **)(param_1 + 0x24) = &DAT_405e18fc;
  *(undefined **)(param_1 + 0x28) = &DAT_405e18e0;
  return 1;
}



/* 405e7c40 BatteryDlgProc */

/* Boundary evidence: original MIPS .pdata 405e7c40..405e7e53. Semantic name remains unreviewed. */

undefined4 BatteryDlgProc(HWND param_1,int param_2,ushort param_3,int param_4)

{
  uint uVar1;
  HWND hWnd;
  LPCWSTR lpString;
  uint uVar2;
  uint *puVar3;
  int *piVar4;
  int *piVar5;
  uint local_30 [2];
  
                    /* 0x7c40  3  BatteryDlgProc */
  if (param_2 == 0x110) {
    uVar1 = BatteryDrvrGetLevels();
    piVar5 = &DAT_405e1944;
    local_30[0] = uVar1 & 0xffff;
    local_30[1] = uVar1 >> 0x10;
    puVar3 = local_30;
    do {
      uVar2 = *puVar3;
      piVar4 = piVar5;
      uVar1 = uVar2;
      if (0 < (int)uVar2) {
        do {
          hWnd = GetDlgItem(param_1,*piVar4);
          ShowWindow(hWnd,5);
          uVar1 = uVar1 - 1;
          piVar4 = piVar4 + 1;
        } while (uVar1 != 0);
      }
      if (uVar2 == 2) {
        lpString = (LPCWSTR)LoadStringW(DAT_405fb7fc,0x8057,(LPWSTR)0x0,0);
        SetDlgItemTextW(param_1,piVar5[1],lpString);
      }
      piVar5 = piVar5 + 3;
      puVar3 = puVar3 + 1;
    } while ((int)piVar5 < 0x405e195c);
    DAT_405fb7a0 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
    if (DAT_405fb7a0 != (HANDLE)0x0) {
      DAT_405fb7c4 = CreateThread((LPSECURITY_ATTRIBUTES)0x0,0,FUN_405e5ec8,param_1,0,(LPDWORD)0x0);
    }
  }
  else if (param_2 == 0x111) {
    if (param_3 == 0) {
      return 0;
    }
    if (2 < param_3) {
      return 0;
    }
    if (DAT_405fb7a0 != (HANDLE)0x0) {
      if (DAT_405fb7c4 != (HANDLE)0x0) {
        EventModify(DAT_405fb7a0,3);
        WaitForSingleObject(DAT_405fb7c4,0xffffffff);
        CloseHandle(DAT_405fb7c4);
        DAT_405fb7c4 = (HANDLE)0x0;
      }
      CloseHandle(DAT_405fb7a0);
      DAT_405fb7a0 = (HANDLE)0x0;
    }
  }
  else {
    if (param_2 != 0x401) {
      return 0;
    }
    FUN_405e6c40(param_1,param_4);
  }
  return 1;
}



/* 405e7e54 FUN_405e7e54 */

/* Boundary evidence: original MIPS .pdata 405e7e54..405e7f2b. Semantic name remains unreviewed. */

undefined4 FUN_405e7e54(undefined4 param_1,int param_2)

{
  if (param_2 == 0) {
    DeleteCriticalSection((LPCRITICAL_SECTION)&DAT_405fb7c8);
  }
  else if (param_2 == 1) {
    DAT_405fb7fc = param_1;
    DAT_405fb7e4 = LoadLibraryW(L"coredll.dll");
    if (DAT_405fb7e4 == (HMODULE)0x0) {
      DAT_405fb7dc = 0;
      DAT_405fb7e0 = 0;
    }
    else {
      DAT_405fb7e0 = GetProcAddressW(DAT_405fb7e4,L"SipGetInfo");
      DAT_405fb7dc = GetProcAddressW(DAT_405fb7e4,L"SipSetInfo");
    }
    FUN_405f8350();
    InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_405fb7c8);
  }
  return 1;
}



/* 405e7f2c FUN_405e7f2c */

/* Boundary evidence: original MIPS .pdata 405e7f2c..405e8043. Semantic name remains unreviewed. */

undefined4 FUN_405e7f2c(uint param_1,undefined4 *param_2)

{
  int iVar1;
  int iVar2;
  HICON pHVar3;
  
  if (param_1 < 0x10) {
    iVar1 = param_1 * 0x34;
    iVar2 = GetProcAddressW(DAT_405fb7fc,*(undefined4 *)((&PTR_DAT_405fb438)[param_1 * 0xd] + 8));
    if (iVar2 != 0) {
      memset(param_2,0,0x1d4);
      *param_2 = 0x1d4;
      param_2[3] = *(undefined4 *)(&DAT_405fb424 + iVar1);
      pHVar3 = LoadIconW(DAT_405fb7fc,(LPCWSTR)(uint)*(ushort *)(&DAT_405fb424 + iVar1));
      param_2[4] = pHVar3;
      LoadStringW(DAT_405fb7fc,*(UINT *)(&DAT_405fb428 + iVar1),(LPWSTR)(param_2 + 5),0x20);
      LoadStringW(DAT_405fb7fc,*(UINT *)(&DAT_405fb42c + iVar1),(LPWSTR)(param_2 + 0x15),0x40);
      return 0;
    }
  }
  return 0xffffffff;
}



/* 405e8044 FUN_405e8044 */

/* Boundary evidence: original MIPS .pdata 405e8044..405e8103. Semantic name remains unreviewed. */

undefined4 *
FUN_405e8044(undefined4 *param_1,int param_2,int param_3,undefined4 param_4,undefined4 param_5)

{
  undefined4 uVar1;
  
  param_1[8] = 0;
  memset(param_1,0,0x2c);
  param_1[3] = param_2;
  param_1[4] = param_3;
  param_1[1] = param_4;
  *param_1 = (&PTR_DAT_405fb438)[param_2 * 0xd + param_3];
  uVar1 = GetProcAddressW(DAT_405fb7fc,
                          *(undefined4 *)((&PTR_DAT_405fb438)[param_2 * 0xd + param_3] + 8));
  param_1[2] = uVar1;
  param_1[9] = param_5;
  param_1[10] = 0;
  return param_1;
}



/* 405e8104 FUN_405e8104 */

/* Boundary evidence: original MIPS .pdata 405e8104..405e8527. Semantic name remains unreviewed. */

uint FUN_405e8104(HWND param_1,int param_2,uint param_3,int param_4)

{
  int *dwNewLong;
  HWND pHVar1;
  HFONT pHVar2;
  uint *puVar3;
  uint uVar4;
  LONG dwNewLong_00;
  int iVar5;
  uint uVar6;
  int iVar7;
  
  dwNewLong = (int *)GetWindowLongW(param_1,-0x15);
  uVar6 = 0;
  if (param_2 == 2) {
    if (dwNewLong == (int *)0x0) {
      return 0;
    }
    if (DAT_405fb7e8 == 0) goto LAB_405e84d0;
    puVar3 = (uint *)GetWindowLongW((HWND)dwNewLong[6],-0x15);
    FUN_405f7834(*puVar3 & 1);
  }
  else {
    if (param_2 != 6) {
      if (param_2 == 0x10) {
        if (dwNewLong == (int *)0x0) {
          return 0;
        }
        SendMessageW((HWND)dwNewLong[6],0x471,2,0);
        return 1;
      }
      if (param_2 != 0x1a) {
        if (param_2 == 0x28) {
          if (dwNewLong == (int *)0x0) {
            return 0;
          }
          uVar6 = SendMessageW((HWND)dwNewLong[6],0x28,param_3,param_4);
          return uVar6;
        }
        if (param_2 != 0x4e) {
          if (param_2 == 0x110) {
            dwNewLong = *(int **)(param_4 + 0x1c);
            SetWindowLongW(param_1,-0x15,(LONG)dwNewLong);
            pHVar1 = GetParent(param_1);
            dwNewLong[6] = (int)pHVar1;
            if (*(int *)(*dwNewLong + 0xc) != 0) {
              pHVar2 = FUN_405f8800(param_1);
              dwNewLong[7] = (int)pHVar2;
              if ((pHVar2 != (HFONT)0x0) && (iVar7 = 0, 0 < *(int *)(*dwNewLong + 0x10))) {
                iVar5 = 0;
                do {
                  SendDlgItemMessageW(param_1,*(int *)(*(int *)(*dwNewLong + 0xc) + iVar5),0x30,
                                      dwNewLong[7],0);
                  iVar7 = iVar7 + 1;
                  iVar5 = iVar5 + 4;
                } while (iVar7 < *(int *)(*dwNewLong + 0x10));
              }
            }
            if (dwNewLong[9] != 0) {
              param_4 = dwNewLong[9];
            }
          }
          goto LAB_405e84d0;
        }
        if (dwNewLong == (int *)0x0) {
          return 0;
        }
        iVar7 = *(int *)(param_4 + 8);
        if (iVar7 == -0xcd) {
          CreateProcessW(L"peghelp",*(LPWSTR *)(*dwNewLong + 0x18),(LPSECURITY_ATTRIBUTES)0x0,
                         (LPSECURITY_ATTRIBUTES)0x0,0,0,(LPVOID)0x0,(LPCWSTR)0x0,(LPSTARTUPINFOW)0x0
                         ,(LPPROCESS_INFORMATION)0x0);
        }
        else {
          if (iVar7 == -0xcb) {
            (*(code *)dwNewLong[2])(param_1,0x111,2,0);
            return 1;
          }
          if (iVar7 == -0xca) {
            iVar7 = (*(code *)dwNewLong[2])(param_1,0x111,1,0);
            dwNewLong_00 = 2;
            if (iVar7 != 0) {
              dwNewLong_00 = 0;
            }
            SetWindowLongW(param_1,0,dwNewLong_00);
            return 1;
          }
          if ((iVar7 != -200) || (DAT_405fb7e8 == 0)) goto LAB_405e834c;
          FUN_405f7834(*(int *)(*dwNewLong + 0x14));
        }
        uVar6 = 1;
      }
LAB_405e834c:
      if (DAT_405fb7f0 == 0) {
        if (param_3 == 0x2f) {
          pHVar1 = GetParent(param_1);
          FUN_405f7658(pHVar1,1);
        }
        else if ((param_3 == 0xe0) && (DAT_405fb7ec != 0)) {
          pHVar1 = GetParent(param_1);
          FUN_405f7658(pHVar1,0);
          uVar6 = 1;
        }
      }
      goto LAB_405e84d0;
    }
    if (dwNewLong == (int *)0x0) {
      return 0;
    }
    if ((param_3 & 0xffff) == 0) {
      pHVar1 = GetFocus();
      dwNewLong[5] = (int)pHVar1;
    }
    else {
      if (DAT_405fb7e8 != 0) {
        FUN_405f7834(*(int *)(*dwNewLong + 0x14));
      }
      if ((HWND)dwNewLong[5] == (HWND)0x0) {
        pHVar1 = GetFocus();
        dwNewLong[5] = (int)pHVar1;
      }
      else {
        SetFocus((HWND)dwNewLong[5]);
      }
      if (DAT_405fb7f8 != (HWND)0x0) {
        PostMessageW(DAT_405fb7f8,0x402,param_3,param_4);
      }
    }
  }
  uVar6 = 1;
LAB_405e84d0:
  if (dwNewLong != (int *)0x0) {
    uVar4 = (*(code *)dwNewLong[2])(param_1,param_2,param_3,param_4);
    return uVar4 | uVar6;
  }
  return uVar6;
}



/* 405e8528 FUN_405e8528 */

/* Boundary evidence: original MIPS .pdata 405e8528..405e861f. Semantic name remains unreviewed. */

undefined4 FUN_405e8528(HWND param_1,int param_2,uint *param_3)

{
  uint uVar1;
  undefined4 uVar2;
  undefined4 *dwNewLong;
  
  dwNewLong = (undefined4 *)0x0;
  if (param_2 == 1) {
    if (DAT_405fb7f4 != 0) {
      uVar1 = GetWindowLongW(param_1,-0x14);
      SetWindowLongW(param_1,-0x14,uVar1 | 0x40000000);
    }
    if (DAT_405fb7e8 != 0) {
      dwNewLong = operator_new(4);
      if (dwNewLong == (undefined4 *)0x0) {
        dwNewLong = (undefined4 *)0x0;
      }
      else {
        *dwNewLong = 0;
      }
      if (dwNewLong != (undefined4 *)0x0) {
        uVar2 = FUN_405f77d8();
        *dwNewLong = uVar2;
      }
    }
    SetWindowLongW(param_1,-0x15,(LONG)dwNewLong);
    if (dwNewLong != (undefined4 *)0x0) {
      operator_delete(dwNewLong);
    }
  }
  else if (param_2 == 2) {
    *param_3 = *param_3 & 0x7fffffff;
  }
  return 0;
}



/* 405e8620 FUN_405e8620 */

/* Boundary evidence: original MIPS .pdata 405e8620..405e8a77. Semantic name remains unreviewed. */

INT_PTR FUN_405e8620(int param_1,_union_1965 param_2)

{
  _union_1966 hMem;
  int iVar1;
  code *pcVar2;
  INT_PTR IVar3;
  undefined4 *puVar4;
  LPCWSTR pWVar5;
  DWORD DVar6;
  UINT *pUVar7;
  _union_1946 _Var8;
  undefined **ppuVar9;
  HLOCAL hMem_00;
  void *pvVar10;
  undefined **ppuVar11;
  LPARAM *pLVar12;
  UINT UVar13;
  _union_1947 *p_Var14;
  int iVar15;
  int iVar16;
  _union_1966 local_68;
  int local_64;
  int local_60;
  undefined **local_5c;
  _union_1965 local_58;
  DWORD local_50;
  uint local_4c;
  HWND local_48;
  HINSTANCE local_44;
  _union_1964 local_40;
  LPCWSTR local_3c;
  UINT local_38;
  _union_1965 local_34;
  _union_1966 local_30;
  code *local_2c;
  
  iVar16 = param_1 * 0x34;
  local_5c = &PTR_u_CPL_Comm_405fb418;
  hMem_00 = (HLOCAL)0x0;
  ppuVar11 = &PTR_DAT_405fb438 + param_1 * 0xd;
  local_60 = iVar16;
  local_58 = param_2;
  iVar1 = GetProcAddressW(DAT_405fb7fc,*(undefined4 *)(*ppuVar11 + 8));
  if (((iVar1 != 0) &&
      ((DAT_405fb7f8 = FindWindowW(L"Welcome",(LPCWSTR)0x0), *(int *)(&DAT_405fb41c + iVar16) == 0
       || ((pcVar2 = (code *)GetProcAddressW(DAT_405fb7fc), pcVar2 != (code *)0x0 &&
           (iVar1 = (*pcVar2)(&PTR_u_CPL_Comm_405fb418 + param_1 * 0xd), iVar1 != 0)))))) &&
     ((*(int *)(&DAT_405fb420 + iVar16) == 0 ||
      (hMem_00 = (HLOCAL)FUN_405f8754((HWND)0x0), hMem_00 != (HLOCAL)0x0)))) {
    if (*(int *)(&DAT_405fb434 + iVar16) != 0) {
      local_68 = (_union_1966)0x8;
      local_64 = *(int *)(&DAT_405fb434 + iVar16);
      InitCommonControlsEx((INITCOMMONCONTROLSEX *)&local_68);
    }
    if (*(int *)*ppuVar11 == 0) {
      if (hMem_00 != (HLOCAL)0x0) {
        LocalFree(hMem_00);
      }
      pcVar2 = (code *)GetProcAddressW(DAT_405fb7fc,*(undefined4 *)(*ppuVar11 + 8));
      IVar3 = (*pcVar2)();
      return IVar3;
    }
    iVar1 = 0;
    ppuVar9 = ppuVar11;
    do {
      if (*ppuVar9 == (undefined *)0x0) break;
      iVar1 = iVar1 + 1;
      ppuVar9 = ppuVar9 + 1;
    } while (iVar1 < 5);
    local_68.ppsp = LocalAlloc(0x40,iVar1 * 0x28);
    if (local_68.ppsp != (LPCPROPSHEETPAGEW)0x0) {
      UVar13 = 0;
      iVar15 = 0;
      ppuVar9 = &PTR_u_CPL_Comm_405fb418;
      if (0 < iVar1) {
        p_Var14 = &(local_68.ppsp)->u2;
        do {
          pUVar7 = (UINT *)*ppuVar11;
          puVar4 = operator_new(0x2c);
          if (puVar4 == (undefined4 *)0x0) {
            puVar4 = (undefined4 *)0x0;
          }
          else {
            puVar4 = FUN_405e8044(puVar4,param_1,iVar15,(PROPSHEETPAGEW_V4 *)(p_Var14 + -4),hMem_00)
            ;
          }
          if ((puVar4 == (undefined4 *)0x0) || (puVar4[2] != 0)) {
            ((PROPSHEETPAGEW_V4 *)(p_Var14 + -4))->dwSize = 0x28;
            p_Var14[-3] = (_union_1947)0x8;
            p_Var14[-2].hIcon = (HICON)DAT_405fb7fc;
            _Var8._2_2_ = 0;
            _Var8._0_2_ = (ushort)pUVar7[1];
            *(_union_1946 *)(p_Var14 + -1) = _Var8;
            p_Var14->hIcon = (HICON)0x0;
            p_Var14[2].hIcon = (HICON)FUN_405e8104;
            pWVar5 = (LPCWSTR)LoadStringW(DAT_405fb7fc,*pUVar7,(LPWSTR)0x0,0);
            UVar13 = UVar13 + 1;
            p_Var14[1] = (_union_1947)pWVar5;
            p_Var14[4].hIcon = (HICON)0x0;
            p_Var14[3].hIcon = (HICON)puVar4;
            p_Var14 = p_Var14 + 10;
          }
          else {
            if ((HGDIOBJ)puVar4[7] != (HGDIOBJ)0x0) {
              DeleteObject((HGDIOBJ)puVar4[7]);
            }
            operator_delete(puVar4);
          }
          iVar15 = iVar15 + 1;
          ppuVar11 = ppuVar11 + 1;
          param_2 = local_58;
          iVar16 = local_60;
          ppuVar9 = local_5c;
        } while (iVar15 < iVar1);
      }
      hMem = local_68;
      if ((int)UVar13 <= (int)param_2.nStartPage) {
        param_2.nStartPage = 0;
      }
      local_50 = 0x28;
      local_4c = 0x10c;
      DVar6 = GetFileAttributesW(L"\\Windows\\peghelp.exe");
      if (DVar6 != 0xffffffff) {
        local_4c = local_4c | 0x200;
      }
      if (DAT_405fb7f0 != 0) {
        local_4c = local_4c | 0x2000;
      }
      local_40._2_2_ = 0;
      local_40._0_2_ = *(ushort *)((int)ppuVar9 + iVar16 + 0xc);
      local_48 = (HWND)0x0;
      local_44 = DAT_405fb7fc;
      local_3c = (LPCWSTR)LoadStringW(DAT_405fb7fc,*(UINT *)((int)ppuVar9 + iVar16 + 0x18),
                                      (LPWSTR)0x0,0);
      local_2c = FUN_405e8528;
      local_38 = UVar13;
      local_34 = param_2;
      local_30 = hMem;
      FUN_405f723c();
      IVar3 = PropertySheetW((LPCPROPSHEETHEADERW)&local_50);
      if (0 < (int)UVar13) {
        pLVar12 = &(hMem.ppsp)->lParam;
        do {
          pvVar10 = (void *)*pLVar12;
          if (pvVar10 != (void *)0x0) {
            if (*(HGDIOBJ *)((int)pvVar10 + 0x1c) != (HGDIOBJ)0x0) {
              DeleteObject(*(HGDIOBJ *)((int)pvVar10 + 0x1c));
            }
            operator_delete(pvVar10);
          }
          UVar13 = UVar13 - 1;
          pLVar12 = pLVar12 + 10;
        } while (UVar13 != 0);
      }
      LocalFree(hMem.ppsp);
      if (hMem_00 != (HLOCAL)0x0) {
        LocalFree(hMem_00);
      }
      FUN_405f72e0();
      return IVar3;
    }
    if (hMem_00 != (HLOCAL)0x0) {
      LocalFree(hMem_00);
    }
  }
  return 0;
}



/* 405e8a78 CPlApplet */

/* Boundary evidence: original MIPS .pdata 405e8a78..405e8bc7. Semantic name remains unreviewed. */

undefined4 CPlApplet(undefined4 param_1,int param_2,uint param_3,undefined4 *param_4)

{
  undefined4 uVar1;
  LPCWSTR pWVar2;
  HANDLE hObject;
  uint uVar3;
  
                    /* 0x8a78  4  CPlApplet */
  if (param_2 == 1) {
    return 1;
  }
  if (param_2 == 2) {
    return 0x10;
  }
  if (param_2 != 5) {
    if (param_2 == 8) {
      uVar1 = FUN_405e7f2c(param_3,param_4);
      return uVar1;
    }
    if (param_2 != 9) {
      return 0;
    }
  }
  uVar3 = param_3 & 0xffff;
  if (0xf < uVar3) {
    return 0;
  }
  pWVar2 = (LPCWSTR)LoadStringW(DAT_405fb7fc,*(UINT *)(&DAT_405fb430 + uVar3 * 0x34),(LPWSTR)0x0,0);
  hObject = FUN_405f756c((LPCWSTR)(&PTR_u_CPL_Comm_405fb418)[uVar3 * 0xd],pWVar2,
                         *(int *)(&DAT_405fb420 + uVar3 * 0x34));
  if (hObject != (HANDLE)0x0) {
    FUN_405e8620(uVar3,(_union_1965)(param_3 >> 0x10));
    if (hObject != (HANDLE)0xffffffff) {
      CloseHandle(hObject);
      return 1;
    }
    return 1;
  }
  return 1;
}



/* 405e8bc8 CalibrateDlgProc */

/* Boundary evidence: original MIPS .pdata 405e8bc8..405e8c67. Semantic name remains unreviewed. */

undefined4 CalibrateDlgProc(HWND param_1,int param_2,short param_3)

{
  HWND hWnd;
  
                    /* 0x8bc8  5  CalibrateDlgProc */
  if (param_2 == 0x110) {
    FUN_405f83f4(param_1,600,0x8137);
    return 1;
  }
  if (param_2 == 0x111) {
    if (param_3 == 1) {
      return 1;
    }
    if (param_3 == 0x259) {
      TouchCalibrate();
      hWnd = GetDlgItem(param_1,0x259);
      SetFocus(hWnd);
      return 1;
    }
  }
  return 0;
}



/* 405e8c68 FUN_405e8c68 */

void FUN_405e8c68(int param_1,int *param_2,int *param_3)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *param_3 - *param_2;
  if (iVar1 < 0) {
    iVar1 = *param_2 - *param_3;
  }
  *(int *)(param_1 + 0x18) = iVar1;
  iVar2 = param_3[1] - param_2[1];
  if (iVar2 < 0) {
    iVar2 = param_2[1] - param_3[1];
  }
  *(int *)(param_1 + 0x1c) = iVar2;
  if (iVar1 < 10) {
    *(undefined4 *)(param_1 + 0x18) = 10;
  }
  if (iVar2 < 10) {
    *(undefined4 *)(param_1 + 0x1c) = 10;
  }
  return;
}



/* 405e8cc8 FUN_405e8cc8 */

/* Boundary evidence: original MIPS .pdata 405e8cc8..405e8ddb. Semantic name remains unreviewed. */

undefined4 * FUN_405e8cc8(undefined4 *param_1,undefined4 param_2,undefined4 param_3)

{
  UINT UVar1;
  int iVar2;
  uint uVar3;
  HBITMAP pHVar4;
  uint uVar5;
  
  memset(param_1,0,0x4c);
  *param_1 = param_3;
  param_1[1] = param_2;
  UVar1 = GetDoubleClickTime();
  param_1[2] = UVar1;
  iVar2 = GetSystemMetrics(0x24);
  param_1[3] = iVar2;
  uVar3 = GetSystemMetrics(0x25);
  uVar5 = param_1[2];
  param_1[4] = uVar3;
  if (uVar5 < 0x7d1) {
    if (uVar5 < 0xfa) {
      uVar5 = 0xfa;
    }
  }
  else {
    uVar5 = 2000;
  }
  param_1[2] = uVar5;
  param_1[5] = uVar5;
  uVar5 = param_1[3];
  if (uVar5 < 0x33) {
    if (uVar5 < 10) {
      uVar5 = 10;
    }
  }
  else {
    uVar5 = 0x32;
  }
  param_1[3] = uVar5;
  param_1[6] = uVar5;
  uVar5 = 0x32;
  if ((uVar3 < 0x33) && (uVar5 = 10, 9 < uVar3)) {
    uVar5 = uVar3;
  }
  param_1[4] = uVar5;
  param_1[7] = uVar5;
  pHVar4 = LoadBitmapW(DAT_405fb7fc,(LPCWSTR)0x13ee);
  param_1[8] = pHVar4;
  pHVar4 = LoadBitmapW(DAT_405fb7fc,(LPCWSTR)0x13ef);
  param_1[9] = pHVar4;
  return param_1;
}



/* 405e8ddc FUN_405e8ddc */

/* Boundary evidence: original MIPS .pdata 405e8ddc..405e8f3b. Semantic name remains unreviewed. */

void FUN_405e8ddc(undefined4 *param_1,int param_2,undefined4 param_3,int param_4)

{
  HWND pHVar1;
  uint uVar2;
  uint uVar3;
  int nCmdShow;
  int nCmdShow_00;
  int local_res4;
  undefined4 local_res8;
  
  local_res4 = param_2;
  local_res8 = param_3;
  if (param_1[0x10] != 0) {
    KillTimer((HWND)*param_1,1);
    param_1[0xf] = 0;
    param_1[0x10] = 0;
  }
  if (param_1[0xf] == 0) {
    param_1[10] = param_4;
    param_1[0xb] = param_2;
    param_1[0xc] = param_3;
    SetTimer((HWND)*param_1,1,0x7d1,(TIMERPROC)0x0);
  }
  else {
    KillTimer((HWND)*param_1,1);
    FUN_405e8c68((int)param_1,&local_res4,param_1 + 0xb);
    uVar3 = param_4 - param_1[10];
    if (uVar3 < 0x7d1) {
      if (uVar3 < 0xfa) {
        uVar3 = 0xfa;
      }
    }
    else {
      uVar3 = 2000;
    }
    uVar2 = param_1[0x12];
    param_1[5] = uVar3;
    nCmdShow = 5;
    param_1[0x12] = ~uVar2;
    nCmdShow_00 = 0;
    if (~uVar2 == 0) {
      nCmdShow_00 = 5;
    }
    pHVar1 = GetDlgItem((HWND)*param_1,0x272);
    ShowWindow(pHVar1,nCmdShow_00);
    if (param_1[0x12] == 0) {
      nCmdShow = 0;
    }
    pHVar1 = GetDlgItem((HWND)*param_1,0x273);
    ShowWindow(pHVar1,nCmdShow);
  }
  param_1[0xf] = (uint)(param_1[0xf] == 0);
  param_1[0x10] = 0;
  return;
}



/* 405e8f3c FUN_405e8f3c */

/* Boundary evidence: original MIPS .pdata 405e8f3c..405e90a7. Semantic name remains unreviewed. */

void FUN_405e8f3c(undefined4 *param_1,int param_2,int param_3,int param_4)

{
  HWND pHVar1;
  int iVar2;
  uint uVar3;
  int nCmdShow;
  
  if (param_1[0xf] != 0) {
    KillTimer((HWND)*param_1,1);
    param_1[0xf] = 0;
    param_1[0x10] = 0;
  }
  param_1[0xf] = 0;
  if ((param_1[0x10] != 0) &&
     (KillTimer((HWND)*param_1,1), (uint)(param_4 - param_1[10]) <= (uint)param_1[5])) {
    iVar2 = param_1[0xe] - param_3;
    if (iVar2 < 0) {
      iVar2 = param_3 - param_1[0xe];
    }
    if (iVar2 <= (int)param_1[7]) {
      iVar2 = param_1[0xd] - param_2;
      if (iVar2 < 0) {
        iVar2 = param_2 - param_1[0xd];
      }
      if (iVar2 <= (int)param_1[6]) {
        uVar3 = param_1[0x11];
        param_1[0x11] = ~uVar3;
        iVar2 = 5;
        nCmdShow = 0;
        if (~uVar3 == 0) {
          nCmdShow = 5;
        }
        pHVar1 = GetDlgItem((HWND)*param_1,0x270);
        ShowWindow(pHVar1,nCmdShow);
        if (param_1[0x11] == 0) {
          iVar2 = 0;
        }
        pHVar1 = GetDlgItem((HWND)*param_1,0x271);
        ShowWindow(pHVar1,iVar2);
        param_1[0x10] = 0;
        return;
      }
    }
  }
  param_1[10] = param_4;
  param_1[0xd] = param_2;
  param_1[0xe] = param_3;
  SetTimer((HWND)*param_1,1,0x7d1,(TIMERPROC)0x0);
  param_1[0x10] = 1;
  return;
}



/* 405e90a8 FUN_405e90a8 */

/* Boundary evidence: original MIPS .pdata 405e90a8..405e910f. Semantic name remains unreviewed. */

void * FUN_405e90a8(void *param_1,uint param_2)

{
  if (*(HGDIOBJ *)((int)param_1 + 0x20) != (HGDIOBJ)0x0) {
    DeleteObject(*(HGDIOBJ *)((int)param_1 + 0x20));
  }
  if (*(HGDIOBJ *)((int)param_1 + 0x24) != (HGDIOBJ)0x0) {
    DeleteObject(*(HGDIOBJ *)((int)param_1 + 0x24));
  }
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}



/* 405e9110 FUN_405e9110 */

/* Boundary evidence: original MIPS .pdata 405e9110..405e9247. Semantic name remains unreviewed. */

void FUN_405e9110(int param_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  HKEY local_18;
  undefined4 local_14;
  undefined4 local_10;
  
  uVar2 = *(uint *)(param_1 + 0x14);
  if (uVar2 < 0x7d1) {
    if (uVar2 < 0xfa) {
      uVar2 = 0xfa;
    }
  }
  else {
    uVar2 = 2000;
  }
  uVar3 = *(uint *)(param_1 + 0x18);
  *(uint *)(param_1 + 0x14) = uVar2;
  if (uVar3 < 0x33) {
    if (uVar3 < 10) {
      uVar3 = 10;
    }
  }
  else {
    uVar3 = 0x32;
  }
  uVar5 = *(uint *)(param_1 + 0x1c);
  *(uint *)(param_1 + 0x18) = uVar3;
  uVar4 = 0x32;
  if ((uVar5 < 0x33) && (uVar4 = 10, 9 < uVar5)) {
    uVar4 = uVar5;
  }
  *(uint *)(param_1 + 0x1c) = uVar4;
  if (((uVar2 != *(uint *)(param_1 + 8)) || (uVar3 != *(uint *)(param_1 + 0xc))) ||
     (uVar4 != *(uint *)(param_1 + 0x10))) {
    local_18 = (HKEY)0x0;
    local_14 = 0;
    local_10 = 0;
    FUN_405e3f58(&local_18,(HKEY)0x80000001,L"ControlPanel\\Pen");
    FUN_405e4618(&local_18,L"DblTapTime",*(undefined4 *)(param_1 + 0x14));
    iVar1 = *(int *)(param_1 + 0x18);
    if (*(int *)(param_1 + 0x18) <= *(int *)(param_1 + 0x1c)) {
      iVar1 = *(int *)(param_1 + 0x1c);
    }
    if (iVar1 < 0) {
      iVar1 = iVar1 + 1;
    }
    FUN_405e4618(&local_18,L"DblTapDist",iVar1 >> 1);
    NotifyWinUserSystem(1);
    FUN_405e4020(&local_18);
  }
  return;
}



/* 405e9248 DblTapDlgProc */

/* Boundary evidence: original MIPS .pdata 405e9248..405e94cb. Semantic name remains unreviewed. */

undefined4 DblTapDlgProc(HWND param_1,int param_2,short param_3,uint param_4)

{
  undefined4 *puVar1;
  DWORD DVar2;
  HWND hWnd;
  int iVar3;
  LPCWSTR pWVar4;
  UINT UVar5;
  uint uVar6;
  
                    /* 0x9248  11  DblTapDlgProc */
  puVar1 = (undefined4 *)GetWindowLongW(param_1,8);
  if (param_2 == 2) {
    KillTimer((HWND)*puVar1,1);
    puVar1[0xf] = 0;
    puVar1[0x10] = 0;
    FUN_405e90a8(puVar1,1);
    SetWindowLongW(param_1,8,0);
  }
  else {
    if (param_2 == 0x110) {
      pWVar4 = (LPCWSTR)LoadStringW(DAT_405fb7fc,0x8153,(LPWSTR)0x0,0);
      iVar3 = lstrcmpiW(pWVar4,*(LPCWSTR *)(param_4 + 0x14));
      uVar6 = (uint)(iVar3 == 0);
      puVar1 = operator_new(0x4c);
      if (puVar1 == (undefined4 *)0x0) {
        puVar1 = (undefined4 *)0x0;
      }
      else {
        puVar1 = FUN_405e8cc8(puVar1,uVar6,param_1);
      }
      SetWindowLongW(param_1,8,(LONG)puVar1);
      UVar5 = 0x8154;
      if (uVar6 == 0) {
        UVar5 = 0x8135;
      }
      pWVar4 = (LPCWSTR)LoadStringW(DAT_405fb7fc,UVar5,(LPWSTR)0x0,0);
      SetDlgItemTextW(param_1,0x26c,pWVar4);
      UVar5 = 0x8155;
      if (uVar6 == 0) {
        UVar5 = 0x8136;
      }
      pWVar4 = (LPCWSTR)LoadStringW(DAT_405fb7fc,UVar5,(LPWSTR)0x0,0);
      SetDlgItemTextW(param_1,0x26e,pWVar4);
      return 1;
    }
    if (param_2 == 0x111) {
      if (param_3 == 1) {
        FUN_405e9110((int)puVar1);
        return 1;
      }
    }
    else {
      if (param_2 != 0x113) {
        if ((param_2 != 0x201) && (param_2 != 0x203)) {
          return 0;
        }
        DVar2 = GetTickCount();
        uVar6 = param_4 >> 0x10;
        hWnd = ChildWindowFromPoint(param_1,(POINT)(CONCAT44(uVar6,param_4) & 0xffffffff0000ffff));
        iVar3 = GetDlgCtrlID(hWnd);
        if (0x26e < iVar3) {
          if (iVar3 < 0x272) {
            FUN_405e8f3c(puVar1,param_4 & 0xffff,uVar6,DVar2);
            return 1;
          }
          if (iVar3 < 0x274) {
            FUN_405e8ddc(puVar1,param_4 & 0xffff,uVar6,DVar2);
            return 1;
          }
        }
      }
      KillTimer((HWND)*puVar1,1);
      puVar1[0xf] = 0;
      puVar1[0x10] = 0;
    }
  }
  return 0;
}



/* 405e94cc DblClickDlgProc */

/* Boundary evidence: original MIPS .pdata 405e94cc..405e94e7. Semantic name remains unreviewed. */

void DblClickDlgProc(HWND param_1,int param_2,short param_3,uint param_4)

{
                    /* 0x94cc  10  DblClickDlgProc */
  DblTapDlgProc(param_1,param_2,param_3,param_4);
  return;
}



/* 405e94e8 FUN_405e94e8 */

/* Boundary evidence: original MIPS .pdata 405e94e8..405e9543. Semantic name remains unreviewed. */

void FUN_405e94e8(HWND param_1)

{
  if (DAT_405fb8b0 != (HLOCAL)0x0) {
    SetWindowLongW(param_1,8,0);
    LocalFree(DAT_405fb8b0);
    DAT_405fb8b0 = (HLOCAL)0x0;
  }
  UnregisterClassW(L"MSPreview",DAT_405fb7fc);
  return;
}



/* 405e9544 FUN_405e9544 */

/* Boundary evidence: original MIPS .pdata 405e9544..405e95df. Semantic name remains unreviewed. */

void FUN_405e9544(wchar_t *param_1)

{
  size_t sVar1;
  LPWSTR pWVar2;
  wchar_t *_Source;
  
  _Source = param_1;
  if (*param_1 == L' ') {
    do {
      _Source = _Source + 1;
    } while (*_Source == L' ');
    if (_Source != param_1) {
      wcscpy(param_1,_Source);
    }
  }
  sVar1 = wcslen(param_1);
  pWVar2 = param_1 + sVar1;
  if (pWVar2 != param_1) {
    do {
      pWVar2 = CharPrevW(param_1,pWVar2);
    } while (*pWVar2 == L' ');
    pWVar2 = CharNextW(pWVar2);
    *pWVar2 = L'\0';
  }
  return;
}



/* 405e95e0 FUN_405e95e0 */

/* Boundary evidence: original MIPS .pdata 405e95e0..405e9833. Semantic name remains unreviewed. */

undefined4 FUN_405e95e0(HWND param_1,int param_2,uint param_3)

{
  wchar_t wVar1;
  HWND pHVar2;
  LPCWSTR lpText;
  wchar_t *_Str2;
  int iVar3;
  UINT uID;
  uint nResult;
  undefined4 uVar4;
  WCHAR local_e8 [100];
  uint local_20;
  
  local_20 = DAT_405fb760;
  if (param_2 == 2) {
    FUN_405f72e0();
LAB_405e9808:
    FUN_405f9bec(local_20);
    uVar4 = 0;
  }
  else {
    if (param_2 == 0x110) {
      FUN_405f723c();
      SetDlgItemTextW(param_1,0x255,DAT_405fb8b0);
      SendDlgItemMessageW(param_1,0x255,0xb1,0,-1);
      SendDlgItemMessageW(param_1,0x255,0xc5,0x20,0);
      wVar1 = *DAT_405fb8b0;
      pHVar2 = GetDlgItem(param_1,1);
      EnableWindow(pHVar2,(uint)(wVar1 != L'\0'));
      FUN_405f74b0(param_1);
    }
    else {
      if (param_2 != 0x111) goto LAB_405e9808;
      nResult = param_3 & 0xffff;
      if (nResult == 1) {
        GetDlgItemTextW(param_1,0x255,local_e8,100);
        FUN_405e9544(local_e8);
        if (local_e8[0] == L'\0') {
          uID = 0x8279;
        }
        else {
          _Str2 = (wchar_t *)LoadStringW(DAT_405fb7fc,0x827b,(LPWSTR)0x0,0);
          iVar3 = _wcsicmp(local_e8,_Str2);
          if (iVar3 != 0) {
            wcscpy(DAT_405fb8b0,local_e8);
            goto LAB_405e9754;
          }
          uID = 0x827c;
        }
        lpText = (LPCWSTR)LoadStringW(DAT_405fb7fc,uID,(LPWSTR)0x0,0);
        MessageBoxW(param_1,lpText,(LPCWSTR)0x0,0x30);
      }
      else {
        if (nResult != 2) {
          if ((nResult == 0x255) && (param_3 >> 0x10 == 0x300)) {
            GetDlgItemTextW(param_1,0x255,local_e8,100);
            FUN_405e9544(local_e8);
            pHVar2 = GetDlgItem(param_1,1);
            EnableWindow(pHVar2,(uint)(local_e8[0] != L'\0'));
          }
          goto LAB_405e9808;
        }
LAB_405e9754:
        EndDialog(param_1,nResult);
      }
    }
    uVar4 = 1;
    FUN_405f9bec(local_20);
  }
  return uVar4;
}



/* 405e9834 FUN_405e9834 */

/* Boundary evidence: original MIPS .pdata 405e9834..405e98bf. Semantic name remains unreviewed. */

undefined4 FUN_405e9834(HWND param_1,LRESULT *param_2)

{
  HWND hWnd;
  WPARAM wParam;
  LRESULT LVar1;
  undefined4 uVar2;
  
  hWnd = GetDlgItem(param_1,0x253);
  wParam = SendMessageW(hWnd,0x147,0,0);
  LVar1 = SendMessageW(hWnd,0x150,wParam,0);
  uVar2 = *(undefined4 *)(LVar1 * 4 + *(int *)(DAT_405fb8b4 + 0xc));
  if (param_2 != (LRESULT *)0x0) {
    *param_2 = LVar1;
  }
  return uVar2;
}



/* 405e98c0 FUN_405e98c0 */

/* Boundary evidence: original MIPS .pdata 405e98c0..405e991b. Semantic name remains unreviewed. */

void FUN_405e98c0(undefined4 *param_1)

{
  if ((HKEY)*param_1 != (HKEY)0x0) {
    RegCloseKey((HKEY)*param_1);
  }
  if ((HLOCAL)param_1[2] != (HLOCAL)0x0) {
    LocalFree((HLOCAL)param_1[2]);
  }
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  return;
}



/* 405e991c FUN_405e991c */

/* Boundary evidence: original MIPS .pdata 405e991c..405e9983. Semantic name remains unreviewed. */

undefined4 FUN_405e991c(undefined4 *param_1,LPWSTR param_2,DWORD param_3)

{
  LSTATUS LVar1;
  DWORD dwIndex;
  DWORD local_res8 [2];
  
  if ((HKEY)*param_1 != (HKEY)0x0) {
    dwIndex = param_1[1];
    param_1[1] = dwIndex + 1;
    local_res8[0] = param_3;
    LVar1 = RegEnumKeyExW((HKEY)*param_1,dwIndex,param_2,local_res8,(LPDWORD)0x0,(LPWSTR)0x0,
                          (LPDWORD)0x0,(PFILETIME)0x0);
    if (LVar1 == 0) {
      return 1;
    }
  }
  return 0;
}



/* 405e9984 FUN_405e9984 */

/* Boundary evidence: original MIPS .pdata 405e9984..405e99df. Semantic name remains unreviewed. */

undefined4 FUN_405e9984(undefined4 *param_1,LPCWSTR param_2,LPBYTE param_3,int param_4)

{
  LSTATUS LVar1;
  DWORD local_resc;
  
  if ((HKEY)*param_1 != (HKEY)0x0) {
    local_resc = param_4 << 1;
    LVar1 = RegQueryValueExW((HKEY)*param_1,param_2,(LPDWORD)0x0,(LPDWORD)0x0,param_3,&local_resc);
    if (LVar1 == 0) {
      return 1;
    }
  }
  return 0;
}



/* 405e99e0 FUN_405e99e0 */

/* Boundary evidence: original MIPS .pdata 405e99e0..405e9abb. Semantic name remains unreviewed. */

void FUN_405e99e0(void)

{
  undefined4 *hMem;
  HGDIOBJ ho;
  int iVar1;
  
  if (DAT_405fb8b4 != (undefined4 *)0x0) {
    if ((HGDIOBJ)DAT_405fb8b4[1] != (HGDIOBJ)0x0) {
      DeleteObject((HGDIOBJ)DAT_405fb8b4[1]);
    }
    if ((HDC)*DAT_405fb8b4 != (HDC)0x0) {
      DeleteDC((HDC)*DAT_405fb8b4);
    }
    iVar1 = 0;
    hMem = DAT_405fb8b4;
    do {
      ho = *(HGDIOBJ *)((int)hMem + iVar1 + 0x10);
      if (ho != (HGDIOBJ)0x0) {
        DeleteObject(ho);
        hMem = DAT_405fb8b4;
      }
      iVar1 = iVar1 + 0x60;
    } while (iVar1 < 0xc1);
    if ((HGDIOBJ)hMem[0xbf] != (HGDIOBJ)0x0) {
      DeleteObject((HGDIOBJ)hMem[0xbf]);
      hMem = DAT_405fb8b4;
    }
    if ((HIMAGELIST)hMem[0xc0] != (HIMAGELIST)0x0) {
      ImageList_Destroy((HIMAGELIST)hMem[0xc0]);
      hMem = DAT_405fb8b4;
    }
    LocalFree(hMem);
    DAT_405fb8b4 = (undefined4 *)0x0;
  }
  return;
}



/* 405e9abc FUN_405e9abc */

/* Boundary evidence: original MIPS .pdata 405e9abc..405e9c67. Semantic name remains unreviewed. */

void FUN_405e9abc(HWND param_1,LONG param_2,LONG param_3)

{
  BOOL BVar1;
  WPARAM wParam;
  HWND pHVar2;
  undefined *lParam;
  undefined *puVar3;
  int iVar4;
  HWND pHVar5;
  int iVar6;
  POINT pt;
  
  lParam = &DAT_405e1694;
  pHVar5 = (HWND)0x0;
  iVar6 = 0x2a0;
  iVar4 = 0x130;
  pHVar2 = param_1;
  do {
    pt.y = param_3;
    pt.x = param_2;
    BVar1 = PtInRect((RECT *)(iVar4 + DAT_405fb8b4),pt);
    if (BVar1 != 0) {
      lParam = (undefined *)(&DAT_405fb81c)[*(int *)(iVar6 + DAT_405fb8b4)];
      pHVar2 = pHVar5;
    }
    iVar4 = iVar4 + 0x10;
    pHVar5 = (HWND)((int)&pHVar5->unused + 1);
    iVar6 = iVar6 + 4;
  } while (iVar4 < 0x291);
  if ((pHVar2 == *(HWND *)(DAT_405fb8b4 + 0x344)) &&
     (((puVar3 = DAT_405fb82c, pHVar2 == (HWND)0x4 || (puVar3 = DAT_405fb854, pHVar2 == (HWND)0x6))
      || (puVar3 = DAT_405fb864, pHVar2 == (HWND)0x16)))) {
    pHVar2 = (HWND)0xffffffff;
    lParam = puVar3;
  }
  pHVar5 = GetParent(param_1);
  pHVar5 = GetDlgItem(pHVar5,0x253);
  wParam = SendMessageW(pHVar5,0x158,0,(LPARAM)lParam);
  if (wParam != 0xffffffff) {
    SendMessageW(pHVar5,0x14e,wParam,0);
    pHVar5 = GetParent(param_1);
    pHVar5 = GetDlgItem(pHVar5,0x254);
    InvalidateRect(pHVar5,(RECT *)0x0,0);
  }
  *(HWND *)(DAT_405fb8b4 + 0x344) = pHVar2;
  return;
}



/* 405e9c68 FUN_405e9c68 */

/* Boundary evidence: original MIPS .pdata 405e9c68..405e9d1b. Semantic name remains unreviewed. */

void FUN_405e9c68(HWND param_1,HDC param_2)

{
  HGDIOBJ h;
  tagRECT local_20;
  
  GetClientRect(param_1,&local_20);
  h = SelectObject((HDC)*DAT_405fb8b4,(HGDIOBJ)DAT_405fb8b4[1]);
  BitBlt(param_2,0,0,local_20.right - local_20.left,local_20.bottom - local_20.top,
         (HDC)*DAT_405fb8b4,0,0,0xcc0020);
  if (h != (HGDIOBJ)0x0) {
    SelectObject((HDC)*DAT_405fb8b4,h);
  }
  return;
}



/* 405e9d1c FUN_405e9d1c */

/* Boundary evidence: original MIPS .pdata 405e9d1c..405e9e9f. Semantic name remains unreviewed. */

void FUN_405e9d1c(HDC param_1,int *param_2,int param_3,int param_4,HGDIOBJ param_5,HGDIOBJ param_6,
                 uint param_7)

{
  HGDIOBJ h;
  int x;
  int y;
  int x_00;
  int y_00;
  
  x = *param_2;
  y = param_2[1];
  x_00 = param_2[2];
  y_00 = param_2[3];
  h = SelectObject(param_1,param_6);
  if ((param_7 & 2) != 0) {
    x_00 = x_00 - param_3;
    PatBlt(param_1,x_00,y,param_3,y_00 - y,0xf00021);
  }
  if ((param_7 & 8) != 0) {
    y_00 = y_00 - param_4;
    PatBlt(param_1,x,y_00,x_00 - x,param_4,0xf00021);
  }
  SelectObject(param_1,param_5);
  if ((param_7 & 1) != 0) {
    PatBlt(param_1,x,y,param_3,y_00 - y,0xf00021);
    x = param_3 + x;
  }
  if ((param_7 & 4) != 0) {
    PatBlt(param_1,x,y,x_00 - x,param_4,0xf00021);
  }
  if (h != (HGDIOBJ)0x0) {
    SelectObject(param_1,h);
  }
  return;
}



/* 405e9ea0 FUN_405e9ea0 */

/* Boundary evidence: original MIPS .pdata 405e9ea0..405e9f8f. Semantic name remains unreviewed. */

void FUN_405e9ea0(HDC param_1,int param_2,int param_3,int param_4,int param_5)

{
  int iVar1;
  int iVar2;
  
  iVar1 = param_4 + 1;
  if (iVar1 < 0) {
    iVar1 = param_4 + 2;
  }
  iVar1 = iVar1 >> 1;
  if (param_5 == -1) {
    iVar2 = param_4 % 2;
    param_4 = 1;
    if (iVar2 == 0) {
      param_4 = 2;
    }
    param_2 = iVar1 + param_2 + -1;
  }
  if (0 < iVar1) {
    do {
      PatBlt(param_1,param_2,param_3,param_4,1,0xf00021);
      iVar1 = iVar1 + -1;
      param_3 = param_3 + 1;
      param_4 = param_4 + param_5 * -2;
      param_2 = param_2 + param_5;
    } while (iVar1 != 0);
  }
  return;
}



/* 405e9f90 FUN_405e9f90 */

/* Boundary evidence: original MIPS .pdata 405e9f90..405ea043. Semantic name remains unreviewed. */

void FUN_405e9f90(void)

{
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined2 local_54;
  undefined2 local_52;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
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
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  
  local_60 = 0x28;
  local_58 = 8;
  local_5c = 8;
  local_54 = 1;
  local_52 = 2;
  local_34 = 0x808080;
  local_50 = 0;
  local_4c = 0;
  local_48 = 0;
  local_44 = 0;
  local_40 = 0;
  local_3c = 0;
  local_38 = 0;
  local_30 = 0xc0c0c0;
  local_2c = 0xffffff;
  local_28 = 0xeeeeeeee;
  local_24 = 0xbbbbbbbb;
  local_20 = 0xeeeeeeee;
  local_1c = 0xbbbbbbbb;
  local_18 = 0xeeeeeeee;
  local_14 = 0xbbbbbbbb;
  local_10 = 0xeeeeeeee;
  local_c = 0xbbbbbbbb;
  CreateDIBPatternBrushPt(&local_60,0);
  return;
}



/* 405ea044 FUN_405ea044 */

/* Boundary evidence: original MIPS .pdata 405ea044..405ea21b. Semantic name remains unreviewed. */

void FUN_405ea044(LPBYTE param_1,LPCWSTR param_2,undefined4 param_3)

{
  LSTATUS LVar1;
  DWORD local_28;
  HKEY local_24;
  BYTE local_20 [4];
  BYTE local_1c [4];
  
  param_1[0] = '\r';
  param_1[1] = '\0';
  param_1[2] = '\0';
  param_1[3] = '\0';
  param_1[4] = '\0';
  param_1[5] = '\0';
  param_1[6] = '\0';
  param_1[7] = '\0';
  param_1[8] = '\0';
  param_1[9] = '\0';
  param_1[10] = '\0';
  param_1[0xb] = '\0';
  param_1[0xc] = '\0';
  param_1[0xd] = '\0';
  param_1[0xe] = '\0';
  param_1[0xf] = '\0';
  *(undefined4 *)(param_1 + 0x10) = param_3;
  param_1[0x14] = '\0';
  param_1[0x15] = '\0';
  param_1[0x16] = '\0';
  param_1[0x17] = '\0';
  param_1[0x18] = '\0';
  param_1[0x19] = '\0';
  param_1[0x1a] = '\0';
  param_1[0x1b] = ' ';
  wcscpy((wchar_t *)(param_1 + 0x1c),L"MS Sans Serif");
  LVar1 = RegOpenKeyExW((HKEY)0x80000002,param_2,0,0x20019,&local_24);
  if (LVar1 == 0) {
    local_28 = 4;
    RegQueryValueExW(local_24,L"Ht",(LPDWORD)0x0,(LPDWORD)0x0,param_1,&local_28);
    RegQueryValueExW(local_24,L"Wt",(LPDWORD)0x0,(LPDWORD)0x0,param_1 + 0x10,&local_28);
    LVar1 = RegQueryValueExW(local_24,L"CS",(LPDWORD)0x0,(LPDWORD)0x0,local_20,&local_28);
    if (LVar1 == 0) {
      param_1[0x17] = local_20[0];
    }
    LVar1 = RegQueryValueExW(local_24,L"It",(LPDWORD)0x0,(LPDWORD)0x0,local_1c,&local_28);
    if (LVar1 == 0) {
      param_1[0x14] = local_1c[0];
    }
    local_28 = 0x40;
    RegQueryValueExW(local_24,L"Nm",(LPDWORD)0x0,(LPDWORD)0x0,param_1 + 0x1c,&local_28);
    RegCloseKey(local_24);
  }
  return;
}



/* 405ea21c FUN_405ea21c */

/* Boundary evidence: original MIPS .pdata 405ea21c..405ea317. Semantic name remains unreviewed. */

undefined4 FUN_405ea21c(void)

{
  HFONT pHVar1;
  HGDIOBJ h;
  LPVOID pv;
  
  FUN_405ea044((LPBYTE)(DAT_405fb8b4 + 0x14),L"SYSTEM\\GWE\\Menu\\BarFnt",700);
  pHVar1 = CreateFontIndirectW((LOGFONTW *)(DAT_405fb8b4 + 0x14));
  *(HFONT *)(DAT_405fb8b4 + 0x10) = pHVar1;
  if (*(int *)(DAT_405fb8b4 + 0x10) != 0) {
    pv = (LPVOID)(DAT_405fb8b4 + 0x74);
    h = GetStockObject(0xd);
    GetObjectW(h,0x5c,pv);
    *(undefined4 *)(DAT_405fb8b4 + 0x84) = 700;
    pHVar1 = CreateFontIndirectW((LOGFONTW *)(DAT_405fb8b4 + 0x74));
    *(HFONT *)(DAT_405fb8b4 + 0x70) = pHVar1;
    if (*(int *)(DAT_405fb8b4 + 0x70) != 0) {
      FUN_405ea044((LPBYTE)(DAT_405fb8b4 + 0xd4),L"SYSTEM\\GWE\\OOMFnt",400);
      pHVar1 = CreateFontIndirectW((LOGFONTW *)(DAT_405fb8b4 + 0xd4));
      *(HFONT *)(DAT_405fb8b4 + 0xd0) = pHVar1;
      if (*(int *)(DAT_405fb8b4 + 0xd0) == 0) {
        return 0;
      }
      return 1;
    }
  }
  return 0;
}



/* 405ea318 FUN_405ea318 */

/* Boundary evidence: original MIPS .pdata 405ea318..405eae03. Semantic name remains unreviewed. */

void FUN_405ea318(HWND param_1)

{
  wchar_t *pwVar1;
  HDC hdc;
  int iVar2;
  int iVar3;
  HGDIOBJ pvVar4;
  size_t sVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  tagSIZE local_80;
  tagRECT local_78;
  tagTEXTMETRICW tStack_68;
  
  GetClientRect(param_1,&local_78);
  hdc = GetDC((HWND)0x0);
  iVar2 = GetSystemMetrics(4);
  iVar9 = (int)(short)iVar2;
  iVar2 = GetSystemMetrics(5);
  iVar6 = (int)(short)iVar2;
  iVar2 = GetSystemMetrics(6);
  iVar7 = (int)(short)iVar2;
  iVar2 = GetSystemMetrics(0x2d);
  iVar10 = (int)(short)iVar2;
  iVar3 = GetSystemMetrics(0x2e);
  *(undefined4 *)(DAT_405fb8b4 + 0x2a0) = 0x40000001;
  iVar2 = DAT_405fb8b4;
  *(LONG *)(DAT_405fb8b4 + 0x130) = local_78.left;
  *(LONG *)(iVar2 + 0x134) = local_78.top;
  iVar3 = (int)(short)iVar3;
  *(LONG *)(iVar2 + 0x138) = local_78.right;
  *(LONG *)(iVar2 + 0x13c) = local_78.bottom;
  *(undefined4 *)(DAT_405fb8b4 + 0x2a4) = 0x40000005;
  *(int *)(DAT_405fb8b4 + 0x140) = *(int *)(DAT_405fb8b4 + 0x130) + 0xc;
  *(int *)(DAT_405fb8b4 + 0x144) = *(int *)(DAT_405fb8b4 + 0x134) + 0xc;
  *(undefined4 *)(DAT_405fb8b4 + 0x14c) = *(undefined4 *)(DAT_405fb8b4 + 0x13c);
  *(undefined4 *)(DAT_405fb8b4 + 0x148) = *(undefined4 *)(DAT_405fb8b4 + 0x138);
  *(undefined4 *)(DAT_405fb8b4 + 0x2a8) = 0x4000000f;
  *(undefined4 *)(DAT_405fb8b4 + 0x150) = *(undefined4 *)(DAT_405fb8b4 + 0x140);
  *(undefined4 *)(DAT_405fb8b4 + 0x154) = *(undefined4 *)(DAT_405fb8b4 + 0x144);
  *(int *)(DAT_405fb8b4 + 0x15c) = (iVar6 + 0xb) * 2 + *(int *)(DAT_405fb8b4 + 0x154);
  *(undefined4 *)(DAT_405fb8b4 + 0x158) = *(undefined4 *)(DAT_405fb8b4 + 0x148);
  pvVar4 = SelectObject(hdc,*(HGDIOBJ *)(DAT_405fb8b4 + 0x10));
  GetTextMetricsW(hdc,&tStack_68);
  pwVar1 = DAT_405fb8ac;
  iVar2 = (tStack_68.tmAveCharWidth << 0x11) >> 0x10;
  sVar5 = wcslen(DAT_405fb8ac);
  GetTextExtentExPointW(hdc,pwVar1,sVar5,0,(LPINT)0x0,(LPINT)0x0,&local_80);
  *(undefined4 *)(DAT_405fb8b4 + 0x2b0) = 0x40000007;
  *(int *)(DAT_405fb8b4 + 0x170) = iVar6 * 2 + *(int *)(DAT_405fb8b4 + 0x140);
  *(int *)(DAT_405fb8b4 + 0x174) = iVar7 * 2 + *(int *)(DAT_405fb8b4 + 0x144);
  *(int *)(DAT_405fb8b4 + 0x178) = *(int *)(DAT_405fb8b4 + 0x170) + iVar2 + local_80.cx;
  *(int *)(DAT_405fb8b4 + 0x17c) = (*(int *)(DAT_405fb8b4 + 0x174) - iVar7) + 0x16;
  pwVar1 = DAT_405fb8a8;
  sVar5 = wcslen(DAT_405fb8a8);
  GetTextExtentExPointW(hdc,pwVar1,sVar5,0,(LPINT)0x0,(LPINT)0x0,&local_80);
  *(undefined4 *)(DAT_405fb8b4 + 0x2b4) = 0x40000011;
  *(undefined4 *)(DAT_405fb8b4 + 0x180) = *(undefined4 *)(DAT_405fb8b4 + 0x178);
  *(undefined4 *)(DAT_405fb8b4 + 0x184) = *(undefined4 *)(DAT_405fb8b4 + 0x174);
  *(int *)(DAT_405fb8b4 + 0x188) = *(int *)(DAT_405fb8b4 + 0x180) + iVar2 + local_80.cx;
  *(undefined4 *)(DAT_405fb8b4 + 0x18c) = *(undefined4 *)(DAT_405fb8b4 + 0x17c);
  pwVar1 = DAT_405fb8a4;
  sVar5 = wcslen(DAT_405fb8a4);
  GetTextExtentExPointW(hdc,pwVar1,sVar5,0,(LPINT)0x0,(LPINT)0x0,&local_80);
  *(undefined4 *)(DAT_405fb8b4 + 0x2b8) = 0x4000000d;
  *(undefined4 *)(DAT_405fb8b4 + 400) = *(undefined4 *)(DAT_405fb8b4 + 0x188);
  *(undefined4 *)(DAT_405fb8b4 + 0x194) = *(undefined4 *)(DAT_405fb8b4 + 0x174);
  *(int *)(DAT_405fb8b4 + 0x198) = *(int *)(DAT_405fb8b4 + 400) + iVar2 + local_80.cx;
  *(undefined4 *)(DAT_405fb8b4 + 0x19c) = *(undefined4 *)(DAT_405fb8b4 + 0x17c);
  *(undefined4 *)(DAT_405fb8b4 + 0x2ac) = 0x40000004;
  *(int *)(DAT_405fb8b4 + 0x160) = *(int *)(DAT_405fb8b4 + 0x140) + iVar6;
  *(int *)(DAT_405fb8b4 + 0x164) = *(int *)(DAT_405fb8b4 + 0x144) + iVar7;
  *(undefined4 *)(DAT_405fb8b4 + 0x168) = *(undefined4 *)(DAT_405fb8b4 + 0x198);
  *(int *)(DAT_405fb8b4 + 0x16c) = *(int *)(DAT_405fb8b4 + 0x164) + 0x16;
  SelectObject(hdc,pvVar4);
  *(undefined4 *)(DAT_405fb8b4 + 700) = 0x4000000f;
  *(undefined4 *)(DAT_405fb8b4 + 0x1a0) = *(undefined4 *)(DAT_405fb8b4 + 0x168);
  *(undefined4 *)(DAT_405fb8b4 + 0x1a4) = *(undefined4 *)(DAT_405fb8b4 + 0x164);
  *(undefined4 *)(DAT_405fb8b4 + 0x1a8) = *(undefined4 *)(DAT_405fb8b4 + 0x1b0);
  *(undefined4 *)(DAT_405fb8b4 + 0x1ac) = *(undefined4 *)(DAT_405fb8b4 + 0x16c);
  *(undefined4 *)(DAT_405fb8b4 + 0x2c0) = 0x4000000f;
  *(int *)(DAT_405fb8b4 + 0x1b0) = *(int *)(DAT_405fb8b4 + 0x148) + -0x32;
  *(undefined4 *)(DAT_405fb8b4 + 0x1b4) = *(undefined4 *)(DAT_405fb8b4 + 0x164);
  *(undefined4 *)(DAT_405fb8b4 + 0x1b8) = *(undefined4 *)(DAT_405fb8b4 + 0x148);
  *(undefined4 *)(DAT_405fb8b4 + 0x1bc) = *(undefined4 *)(DAT_405fb8b4 + 0x16c);
  *(undefined4 *)(DAT_405fb8b4 + 0x2c8) = 0x4000000f;
  iVar2 = GetSystemMetrics(2);
  *(int *)(DAT_405fb8b4 + 0x1d0) = *(int *)(DAT_405fb8b4 + 0x148) - iVar2;
  *(undefined4 *)(DAT_405fb8b4 + 0x1d4) = *(undefined4 *)(DAT_405fb8b4 + 0x15c);
  *(undefined4 *)(DAT_405fb8b4 + 0x1d8) = *(undefined4 *)(DAT_405fb8b4 + 0x148);
  iVar2 = GetSystemMetrics(0x14);
  *(int *)(DAT_405fb8b4 + 0x1dc) = iVar2 + *(int *)(DAT_405fb8b4 + 0x1d4);
  *(undefined4 *)(DAT_405fb8b4 + 0x2cc) = 0x4000000f;
  *(undefined4 *)(DAT_405fb8b4 + 0x1e0) = *(undefined4 *)(DAT_405fb8b4 + 0x1d0);
  iVar2 = GetSystemMetrics(0x14);
  *(int *)(DAT_405fb8b4 + 0x1e4) = *(int *)(DAT_405fb8b4 + 0x14c) - iVar2;
  *(undefined4 *)(DAT_405fb8b4 + 0x1e8) = *(undefined4 *)(DAT_405fb8b4 + 0x148);
  *(undefined4 *)(DAT_405fb8b4 + 0x1ec) = *(undefined4 *)(DAT_405fb8b4 + 0x14c);
  *(undefined4 *)(DAT_405fb8b4 + 0x2c4) = 0x4000000f;
  *(undefined4 *)(DAT_405fb8b4 + 0x1c0) = *(undefined4 *)(DAT_405fb8b4 + 0x1d0);
  *(undefined4 *)(DAT_405fb8b4 + 0x1c4) = *(undefined4 *)(DAT_405fb8b4 + 0x1dc);
  *(undefined4 *)(DAT_405fb8b4 + 0x1c8) = *(undefined4 *)(DAT_405fb8b4 + 0x148);
  *(undefined4 *)(DAT_405fb8b4 + 0x1cc) = *(undefined4 *)(DAT_405fb8b4 + 0x1e4);
  *(undefined4 *)(DAT_405fb8b4 + 0x2d0) = 0x40000005;
  iVar2 = iVar9;
  if (iVar9 < 0) {
    iVar2 = iVar9 + 1;
  }
  iVar2 = iVar2 >> 1;
  *(int *)(DAT_405fb8b4 + 0x1f0) = (*(int *)(DAT_405fb8b4 + 0x140) - iVar10) + iVar2;
  *(int *)(DAT_405fb8b4 + 500) = (*(int *)(DAT_405fb8b4 + 0x144) - iVar3) + iVar9;
  *(int *)(DAT_405fb8b4 + 0x1f8) = (*(int *)(DAT_405fb8b4 + 0x1c0) - iVar2) + iVar10;
  *(undefined4 *)(DAT_405fb8b4 + 0x1fc) = *(undefined4 *)(DAT_405fb8b4 + 0x14c);
  *(undefined4 *)(DAT_405fb8b4 + 0x2d4) = 0x40000003;
  *(int *)(DAT_405fb8b4 + 0x200) = *(int *)(DAT_405fb8b4 + 0x1f0) + iVar10 + iVar6;
  *(int *)(DAT_405fb8b4 + 0x204) = *(int *)(DAT_405fb8b4 + 500) + iVar3 + iVar7;
  *(int *)(DAT_405fb8b4 + 0x208) = (*(int *)(DAT_405fb8b4 + 0x1f8) - iVar10) - iVar6;
  *(int *)(DAT_405fb8b4 + 0x20c) = *(int *)(DAT_405fb8b4 + 0x204) + iVar9;
  pvVar4 = SelectObject(hdc,*(HGDIOBJ *)(DAT_405fb8b4 + 0x70));
  pwVar1 = DAT_405fb89c;
  sVar5 = wcslen(DAT_405fb89c);
  GetTextExtentExPointW(hdc,pwVar1,sVar5,0,(LPINT)0x0,(LPINT)0x0,&local_80);
  SelectObject(hdc,pvVar4);
  *(undefined4 *)(DAT_405fb8b4 + 0x2d8) = 0x40000013;
  *(undefined4 *)(DAT_405fb8b4 + 0x214) = *(undefined4 *)(DAT_405fb8b4 + 0x204);
  *(int *)(DAT_405fb8b4 + 0x210) = *(int *)(DAT_405fb8b4 + 0x200) + 1;
  *(undefined4 *)(DAT_405fb8b4 + 0x21c) = *(undefined4 *)(DAT_405fb8b4 + 0x20c);
  *(int *)(DAT_405fb8b4 + 0x218) = *(int *)(DAT_405fb8b4 + 0x210) + iVar10 + local_80.cx;
  *(undefined4 *)(DAT_405fb8b4 + 0x2dc) = 0x4000000f;
  *(int *)(DAT_405fb8b4 + 0x220) = (*(int *)(DAT_405fb8b4 + 0x208) - iVar10) + -0x47;
  *(int *)(DAT_405fb8b4 + 0x224) = *(int *)(DAT_405fb8b4 + 0x204) + iVar7;
  *(undefined4 *)(DAT_405fb8b4 + 0x228) = *(undefined4 *)(DAT_405fb8b4 + 0x208);
  *(undefined4 *)(DAT_405fb8b4 + 0x22c) = *(undefined4 *)(DAT_405fb8b4 + 0x20c);
  pvVar4 = SelectObject(hdc,*(HGDIOBJ *)(DAT_405fb8b4 + 0x70));
  pwVar1 = DAT_405fb894;
  sVar5 = wcslen(DAT_405fb894);
  GetTextExtentExPointW(hdc,pwVar1,sVar5,0,(LPINT)0x0,(LPINT)0x0,&local_80);
  SelectObject(hdc,pvVar4);
  *(undefined4 *)(DAT_405fb8b4 + 0x2f0) = 0x40000008;
  *(int *)(DAT_405fb8b4 + 0x274) = *(int *)(DAT_405fb8b4 + 0x20c) + iVar10;
  *(int *)(DAT_405fb8b4 + 0x27c) = *(int *)(DAT_405fb8b4 + 0x274) + iVar7 + local_80.cy;
  iVar8 = (iVar10 + iVar6) * 2;
  *(int *)(DAT_405fb8b4 + 0x270) = *(int *)(DAT_405fb8b4 + 0x1f0) + iVar8;
  *(int *)(DAT_405fb8b4 + 0x278) = *(int *)(DAT_405fb8b4 + 0x270) + iVar10 + iVar6 + local_80.cx;
  *(undefined4 *)(DAT_405fb8b4 + 0x2e0) = 0x40000019;
  *(int *)(DAT_405fb8b4 + 0x230) = (*(int *)(DAT_405fb8b4 + 0x1f0) - iVar10) + iVar2;
  *(int *)(DAT_405fb8b4 + 0x234) = *(int *)(DAT_405fb8b4 + 0x20c) + iVar3 * 2 + local_80.cy;
  *(int *)(DAT_405fb8b4 + 0x238) = (*(int *)(DAT_405fb8b4 + 0x1c0) - iVar9) + iVar10;
  *(undefined4 *)(DAT_405fb8b4 + 0x23c) = *(undefined4 *)(DAT_405fb8b4 + 0x14c);
  *(undefined4 *)(DAT_405fb8b4 + 0x2e4) = 0x40000002;
  *(int *)(DAT_405fb8b4 + 0x240) = *(int *)(DAT_405fb8b4 + 0x230) + iVar10 + iVar6;
  *(int *)(DAT_405fb8b4 + 0x244) = *(int *)(DAT_405fb8b4 + 0x234) + iVar3 + iVar7;
  *(int *)(DAT_405fb8b4 + 0x248) = (*(int *)(DAT_405fb8b4 + 0x238) - iVar10) - iVar6;
  *(int *)(DAT_405fb8b4 + 0x24c) = *(int *)(DAT_405fb8b4 + 0x244) + iVar9;
  pvVar4 = SelectObject(hdc,*(HGDIOBJ *)(DAT_405fb8b4 + 0x70));
  pwVar1 = DAT_405fb898;
  sVar5 = wcslen(DAT_405fb898);
  GetTextExtentExPointW(hdc,pwVar1,sVar5,0,(LPINT)0x0,(LPINT)0x0,&local_80);
  SelectObject(hdc,pvVar4);
  *(undefined4 *)(DAT_405fb8b4 + 0x2e8) = 0x40000009;
  *(undefined4 *)(DAT_405fb8b4 + 0x254) = *(undefined4 *)(DAT_405fb8b4 + 0x244);
  *(int *)(DAT_405fb8b4 + 0x250) = *(int *)(DAT_405fb8b4 + 0x240) + 1;
  *(undefined4 *)(DAT_405fb8b4 + 0x25c) = *(undefined4 *)(DAT_405fb8b4 + 0x24c);
  *(int *)(DAT_405fb8b4 + 600) = *(int *)(DAT_405fb8b4 + 0x250) + iVar10 + local_80.cx;
  *(undefined4 *)(DAT_405fb8b4 + 0x2ec) = 0x4000000f;
  *(int *)(DAT_405fb8b4 + 0x260) = (*(int *)(DAT_405fb8b4 + 0x248) - iVar10) + -0x47;
  *(int *)(DAT_405fb8b4 + 0x264) = *(int *)(DAT_405fb8b4 + 0x244) + iVar7;
  *(undefined4 *)(DAT_405fb8b4 + 0x268) = *(undefined4 *)(DAT_405fb8b4 + 0x248);
  *(undefined4 *)(DAT_405fb8b4 + 0x26c) = *(undefined4 *)(DAT_405fb8b4 + 0x24c);
  pvVar4 = SelectObject(hdc,*(HGDIOBJ *)(DAT_405fb8b4 + 0xd0));
  pwVar1 = DAT_405fb890;
  sVar5 = wcslen(DAT_405fb890);
  GetTextExtentExPointW(hdc,pwVar1,sVar5,0,(LPINT)0x0,(LPINT)0x0,&local_80);
  SelectObject(hdc,pvVar4);
  *(undefined4 *)(DAT_405fb8b4 + 0x2f4) = 0x4000001a;
  *(int *)(DAT_405fb8b4 + 0x284) = *(int *)(DAT_405fb8b4 + 0x24c) + iVar10;
  *(int *)(DAT_405fb8b4 + 0x28c) = *(int *)(DAT_405fb8b4 + 0x284) + iVar7 + local_80.cy;
  *(int *)(DAT_405fb8b4 + 0x280) = *(int *)(DAT_405fb8b4 + 0x230) + iVar8;
  *(int *)(DAT_405fb8b4 + 0x288) = *(int *)(DAT_405fb8b4 + 0x280) + iVar10 + iVar6 + local_80.cx;
  pvVar4 = SelectObject(hdc,*(HGDIOBJ *)(DAT_405fb8b4 + 0x70));
  pwVar1 = DAT_405fb8a0;
  sVar5 = wcslen(DAT_405fb8a0);
  GetTextExtentExPointW(hdc,pwVar1,sVar5,0,(LPINT)0x0,(LPINT)0x0,&local_80);
  SelectObject(hdc,pvVar4);
  *(undefined4 *)(DAT_405fb8b4 + 0x2f8) = 0x4000000f;
  *(int *)(DAT_405fb8b4 + 0x29c) = *(int *)(DAT_405fb8b4 + 0x14c) + iVar3 * -2;
  *(int *)(DAT_405fb8b4 + 0x294) = (*(int *)(DAT_405fb8b4 + 0x29c) + iVar3 * -4) - local_80.cy;
  *(int *)(DAT_405fb8b4 + 0x298) = *(int *)(DAT_405fb8b4 + 0x238) + iVar10 * -10;
  *(int *)(DAT_405fb8b4 + 0x290) = (*(int *)(DAT_405fb8b4 + 0x298) + iVar10 * -0xc) - local_80.cx;
  return;
}



/* 405eae04 FUN_405eae04 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_405eae04(uint param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  
  uVar5 = (param_1 & 0xffff) >> 8;
  uVar1 = param_1 & 0xff;
  uVar7 = param_1 >> 0x10 & 0xff;
  uVar2 = uVar1;
  if (uVar1 <= uVar5) {
    uVar2 = uVar5;
  }
  uVar3 = uVar7;
  if ((uVar7 < uVar2) && (uVar3 = uVar5, uVar1 > uVar5)) {
    uVar3 = uVar1;
  }
  uVar2 = uVar1;
  if (uVar5 <= uVar1) {
    uVar2 = uVar5;
  }
  uVar6 = uVar7;
  if ((uVar2 < uVar7) && (uVar6 = uVar5, uVar5 > uVar1)) {
    uVar6 = uVar1;
  }
  uVar2 = uVar3 + uVar6;
  DAT_405fb814 = (uVar2 * 0xf0 + 0xff) / 0x1fe;
  uVar6 = uVar3 - uVar6 & 0xffff;
  if (uVar6 == 0) {
    _DAT_405fb810 = 0;
    _DAT_405fb818 = 0xa0;
  }
  else {
    if (DAT_405fb814 < 0x79) {
      _DAT_405fb810 = (uVar6 * 0xf0 + (uVar2 >> 1)) / uVar2;
      if (uVar2 == 0) {
        trap(0x1c00);
      }
    }
    else {
      iVar4 = -uVar2 + 0x1fe;
      if (iVar4 < 0) {
        iVar4 = -uVar2 + 0x1ff;
      }
      _DAT_405fb810 = ((iVar4 >> 1) + uVar6 * 0xf0) / (0x1fe - uVar2);
      if (0x1fe - uVar2 == 0) {
        trap(0x1c00);
      }
    }
    _DAT_405fb810 = _DAT_405fb810 & 0xffff;
    uVar2 = uVar6 >> 1;
    uVar8 = ((uVar3 - uVar1) * 0x28 + uVar2) / uVar6;
    if (uVar6 == 0) {
      trap(0x1c00);
    }
    uVar9 = ((uVar3 - uVar5) * 0x28 + uVar2) / uVar6;
    if (uVar6 == 0) {
      trap(0x1c00);
    }
    uVar2 = ((uVar3 - uVar7) * 0x28 + uVar2) / uVar6;
    if (uVar6 == 0) {
      trap(0x1c00);
    }
    if (uVar1 == uVar3) {
      _DAT_405fb818 = uVar2 - uVar9;
    }
    else if (uVar5 == uVar3) {
      _DAT_405fb818 = (uVar8 - uVar2) + 0x50;
    }
    else {
      _DAT_405fb818 = (uVar9 - uVar8) + 0xa0;
    }
    if (_DAT_405fb818 < 0) {
      _DAT_405fb818 = _DAT_405fb818 + 0xf0;
    }
    if (0xf0 < _DAT_405fb818) {
      _DAT_405fb818 = _DAT_405fb818 + -0xf0;
    }
  }
  return;
}



/* 405eb074 FUN_405eb074 */

uint FUN_405eb074(uint param_1,uint param_2,uint param_3)

{
  int iVar1;
  
  if (0xf0 < param_3) {
    param_3 = param_3 + 0xff10 & 0xffff;
  }
  if (param_3 < 0x28) {
    iVar1 = (param_2 - param_1) * param_3;
  }
  else {
    if (param_3 < 0x78) {
      return param_2;
    }
    if (0x9f < param_3) {
      return param_1;
    }
    iVar1 = (param_2 - param_1) * (0xa0 - param_3);
  }
  return (iVar1 + 0x14) / 0x28 + param_1 & 0xffff;
}



/* 405eb100 FUN_405eb100 */

/* Boundary evidence: original MIPS .pdata 405eb100..405eb2ab. Semantic name remains unreviewed. */

uint FUN_405eb100(uint param_1,uint param_2,int param_3)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  if (param_3 == 0) {
    uVar2 = (int)(param_2 * 0xff) / 0xf0 & 0xffff;
    uVar1 = uVar2;
    uVar4 = uVar2;
  }
  else {
    if (param_2 < 0x79) {
      uVar2 = ((param_3 + 0xf0) * param_2 + 0x78) / 0xf0;
    }
    else {
      uVar2 = (param_2 - (param_2 * param_3 + 0x78) / 0xf0) + param_3;
    }
    uVar2 = uVar2 & 0xffff;
    uVar3 = param_2 * 2 - uVar2 & 0xffff;
    uVar1 = FUN_405eb074(uVar3,uVar2,param_1 + 0x50 & 0xffff);
    uVar4 = (uVar1 * 0xff + 0x78 & 0xffff) / 0xf0;
    uVar1 = FUN_405eb074(uVar3,uVar2,param_1);
    uVar1 = (uVar1 * 0xff + 0x78 & 0xffff) / 0xf0;
    uVar2 = FUN_405eb074(uVar3,uVar2,param_1 + 0xffb0 & 0xffff);
    uVar2 = (uVar2 * 0xff + 0x78 & 0xffff) / 0xf0;
  }
  return ((uVar2 & 0xff) << 8 | uVar1 & 0xff) << 8 | uVar4 & 0xff;
}



/* 405eb2ac FUN_405eb2ac */

/* Boundary evidence: original MIPS .pdata 405eb2ac..405eb407. Semantic name remains unreviewed. */

uint FUN_405eb2ac(uint param_1,int param_2,int param_3)

{
  uint uVar1;
  
  if (param_2 != 0) {
    FUN_405eae04(param_1);
    if (param_3 == 0) {
      DAT_405fb814 = (param_2 * 0xf0) / 1000 + DAT_405fb814;
      if ((int)DAT_405fb814 < 0) {
        DAT_405fb814 = 0;
      }
      uVar1 = DAT_405fb814;
      if (0xf0 < (int)DAT_405fb814) {
        DAT_405fb814 = 0xf0;
        uVar1 = DAT_405fb814;
      }
    }
    else if (param_2 < 1) {
      uVar1 = (int)((param_2 + 1000) * DAT_405fb814) / 1000;
    }
    else {
      uVar1 = (int)((1000 - param_2) * DAT_405fb814 + param_2 * 0xf1) / 1000;
    }
    param_1 = FUN_405eb100((uint)DAT_405fb818,uVar1 & 0xffff,(uint)DAT_405fb810);
  }
  return param_1;
}



/* 405eb408 FUN_405eb408 */

/* Boundary evidence: original MIPS .pdata 405eb408..405eb573. Semantic name remains unreviewed. */

HKEY FUN_405eb408(wchar_t *param_1,STRSAFE_LPWSTR param_2,size_t param_3,PHKEY param_4)

{
  int iVar1;
  HKEY pHVar2;
  HKEY local_458;
  undefined4 local_454;
  undefined4 local_450;
  HKEY local_448;
  undefined4 local_444;
  undefined4 local_440;
  WCHAR aWStack_438 [260];
  wchar_t awStack_230 [260];
  uint local_28;
  
  local_28 = DAT_405fb760;
  local_458 = (HKEY)0x0;
  local_454 = 0;
  local_450 = 0;
  local_448 = (HKEY)0x0;
  local_444 = 0;
  local_440 = 0;
  if (param_4 == (PHKEY)0x0) {
    param_4 = &local_448;
  }
  FUN_405e3f58(&local_458,(HKEY)0x80000001,L"ControlPanel\\Appearance\\Schemes");
  iVar1 = FUN_405e991c(&local_458,aWStack_438,0x104);
  do {
    if (iVar1 == 0) {
LAB_405eb530:
      pHVar2 = *param_4;
      FUN_405e4020(&local_448);
      FUN_405e4020(&local_458);
      FUN_405f9bec(local_28);
      return pHVar2;
    }
    RegOpenKeyExW(local_458,aWStack_438,0,0x20019,param_4);
    iVar1 = FUN_405e9984(param_4,L"DisplayName",(LPBYTE)awStack_230,0x104);
    if ((iVar1 != 0) && (iVar1 = _wcsicmp(param_1,awStack_230), iVar1 == 0)) {
      if (param_2 != (STRSAFE_LPWSTR)0x0) {
        StringCchCopyW(param_2,param_3,aWStack_438);
      }
      goto LAB_405eb530;
    }
    FUN_405e98c0(param_4);
    iVar1 = FUN_405e991c(&local_458,aWStack_438,0x104);
  } while( true );
}



/* 405eb574 FUN_405eb574 */

/* Boundary evidence: original MIPS .pdata 405eb574..405eb73b. Semantic name remains unreviewed. */

void FUN_405eb574(HWND param_1)

{
  HRSRC hResInfo;
  LPCDLGTEMPLATEW hDialogTemplate;
  INT_PTR IVar1;
  HKEY pHVar2;
  LSTATUS LVar3;
  HWND hWnd;
  WPARAM wParam;
  undefined4 uVar4;
  undefined4 *puVar5;
  wchar_t *pwVar6;
  int iVar7;
  HKEY local_a8;
  undefined4 local_a4;
  undefined4 local_a0;
  HKEY local_98 [4];
  BYTE local_88 [4];
  undefined4 local_84 [29];
  
  hResInfo = FindResourceW(DAT_405fb7fc,(LPCWSTR)0xb7,(LPCWSTR)0x5);
  hDialogTemplate = LoadResource(DAT_405fb7fc,hResInfo);
  IVar1 = DialogBoxIndirectParamW(DAT_405fb7fc,hDialogTemplate,param_1,FUN_405e95e0,0);
  if (IVar1 == 1) {
    local_a8 = (HKEY)0x0;
    local_a4 = 0;
    local_a0 = 0;
    pHVar2 = FUN_405eb408(DAT_405fb8b0,(STRSAFE_LPWSTR)0x0,0,&local_a8);
    if (pHVar2 == (HKEY)0x0) {
      FUN_405e3fc4(local_98,(HKEY)0x80000001,L"ControlPanel\\Appearance\\Schemes");
      FUN_405e3f58(&local_a8,local_98[0],DAT_405fb8b0);
      FUN_405e424c(&local_a8,L"DisplayName",DAT_405fb8b0);
      FUN_405e4020(local_98);
    }
    puVar5 = local_84;
    local_88[0] = 0xff;
    local_88[1] = 0xff;
    pwVar6 = DAT_405fb8b0 + 0x104;
    local_88[2] = '\0';
    local_88[3] = '\0';
    iVar7 = 0x1d;
    do {
      uVar4 = *(undefined4 *)pwVar6;
      pwVar6 = pwVar6 + 2;
      *puVar5 = uVar4;
      iVar7 = iVar7 + -1;
      puVar5 = puVar5 + 1;
    } while (iVar7 != 0);
    if (local_a8 != (HKEY)0x0) {
      LVar3 = RegSetValueExW(local_a8,L"Settings",0,3,local_88,0x78);
      if (LVar3 == 0) {
        hWnd = GetDlgItem(param_1,0x250);
        wParam = SendMessageW(hWnd,0x158,0,(LPARAM)DAT_405fb8b0);
        if (wParam == 0xffffffff) {
          wParam = SendMessageW(hWnd,0x143,0,(LPARAM)DAT_405fb8b0);
        }
        SendMessageW(hWnd,0x14e,wParam,0);
      }
    }
    FUN_405e4020(&local_a8);
  }
  return;
}



/* 405eb73c FUN_405eb73c */

/* Boundary evidence: original MIPS .pdata 405eb73c..405eb8f7. Semantic name remains unreviewed. */

void FUN_405eb73c(HWND param_1)

{
  HWND hWnd;
  WPARAM WVar1;
  wchar_t *_Str2;
  int iVar2;
  HKEY pHVar3;
  LPCWSTR lpText;
  UINT uID;
  HKEY local_308 [4];
  wchar_t awStack_2f8 [100];
  wchar_t awStack_230 [260];
  uint local_28;
  
  local_28 = DAT_405fb760;
  hWnd = GetDlgItem(param_1,0x250);
  WVar1 = SendMessageW(hWnd,0x147,0,0);
  if (WVar1 == 0xffffffff) {
    uID = 0x827a;
  }
  else {
    SendMessageW(hWnd,0x148,WVar1,(LPARAM)awStack_2f8);
    _Str2 = (wchar_t *)LoadStringW(DAT_405fb7fc,0x827b,(LPWSTR)0x0,0);
    if ((_Str2 == (wchar_t *)0x0) || (iVar2 = wcscmp(awStack_2f8,_Str2), iVar2 != 0)) {
      SendMessageW(hWnd,0x144,WVar1,0);
      WVar1 = SendMessageW(hWnd,0x14c,0xffffffff,(LPARAM)_Str2);
      if (WVar1 == 0xffffffff) {
        WVar1 = 0;
      }
      SendMessageW(hWnd,0x14e,WVar1,0);
      pHVar3 = FUN_405eb408(awStack_2f8,awStack_230,0x104,(PHKEY)0x0);
      if (pHVar3 != (HKEY)0x0) {
        FUN_405e3fc4(local_308,(HKEY)0x80000001,L"ControlPanel\\Appearance\\Schemes");
        if (local_308[0] != (HKEY)0x0) {
          RegDeleteKeyW(local_308[0],awStack_230);
        }
        FUN_405e4020(local_308);
      }
      goto LAB_405eb8cc;
    }
    uID = 0x827d;
  }
  lpText = (LPCWSTR)LoadStringW(DAT_405fb7fc,uID,(LPWSTR)0x0,0);
  MessageBoxW(param_1,lpText,(LPCWSTR)0x0,0x30);
LAB_405eb8cc:
  FUN_405f9bec(local_28);
  return;
}



/* 405eb8f8 FUN_405eb8f8 */

/* Boundary evidence: original MIPS .pdata 405eb8f8..405eb9c7. Semantic name remains unreviewed. */

void FUN_405eb8f8(HWND param_1,int param_2)

{
  COLORREF color;
  HBRUSH hbr;
  UINT edge;
  LPRECT qrc;
  
  qrc = (LPRECT)(param_2 + 0x1c);
  edge = 10;
  if ((*(uint *)(param_2 + 0x10) & 1) == 0) {
    edge = 5;
  }
  DrawEdge(*(HDC *)(param_2 + 0x18),qrc,edge,0x100f);
  InflateRect(qrc,-2,-2);
  color = FUN_405e9834(param_1,(LRESULT *)0x0);
  hbr = CreateSolidBrush(color);
  if (hbr != (HBRUSH)0x0) {
    FillRect(*(HDC *)(param_2 + 0x18),qrc,hbr);
    DeleteObject(hbr);
  }
  if ((*(uint *)(param_2 + 0x10) & 0x10) != 0) {
    InflateRect(qrc,-1,-1);
    DrawFocusRect(*(HDC *)(param_2 + 0x18),qrc);
  }
  return;
}



/* 405eb9c8 FUN_405eb9c8 */

/* Boundary evidence: original MIPS .pdata 405eb9c8..405ebadf. Semantic name remains unreviewed. */

void FUN_405eb9c8(uint param_1)

{
  int iVar1;
  uint uVar2;
  
  *(uint *)(*(int *)(DAT_405fb8b4 + 0xc) + 0x3c) = param_1;
  uVar2 = FUN_405eb2ac(param_1,500,1);
  *(uint *)(*(int *)(DAT_405fb8b4 + 0xc) + 0x58) = uVar2;
  iVar1 = DAT_405fb8b4;
  uVar2 = FUN_405eb2ac(*(uint *)(*(int *)(DAT_405fb8b4 + 0xc) + 0x58),500,1);
  *(uint *)(*(int *)(iVar1 + 0xc) + 0x50) = uVar2;
  uVar2 = FUN_405eb2ac(param_1,-0x14d,1);
  *(uint *)(*(int *)(DAT_405fb8b4 + 0xc) + 0x40) = uVar2;
  iVar1 = DAT_405fb8b4;
  uVar2 = FUN_405eb2ac(*(uint *)(*(int *)(DAT_405fb8b4 + 0xc) + 0x40),-0x14d,1);
  *(uint *)(*(int *)(iVar1 + 0xc) + 0x54) = uVar2;
  *(uint *)(*(int *)(DAT_405fb8b4 + 0xc) + 0x28) = param_1;
  *(uint *)(*(int *)(DAT_405fb8b4 + 0xc) + 0x2c) = param_1;
  **(undefined4 **)(DAT_405fb8b4 + 0xc) = (*(undefined4 **)(DAT_405fb8b4 + 0xc))[0x14];
  if ((((*(uint **)(DAT_405fb8b4 + 0xc))[5] ^ **(uint **)(DAT_405fb8b4 + 0xc)) & 0xffffff) == 0) {
    **(undefined4 **)(DAT_405fb8b4 + 0xc) = 0xc0c0c0;
  }
  return;
}



/* 405ebae0 FUN_405ebae0 */

/* Boundary evidence: original MIPS .pdata 405ebae0..405ebbd7. Semantic name remains unreviewed. */

void FUN_405ebae0(HWND param_1)

{
  int iVar1;
  HKEY local_240 [4];
  HKEY apHStack_230 [4];
  WCHAR aWStack_220 [260];
  uint local_18;
  
  local_18 = DAT_405fb760;
  SendMessageW(param_1,0xc5,0x103,0);
  FUN_405e3fc4(local_240,(HKEY)0x80000001,L"ControlPanel\\Appearance\\Schemes");
  iVar1 = FUN_405e991c(local_240,aWStack_220,0x104);
  while (iVar1 != 0) {
    FUN_405e3fc4(apHStack_230,local_240[0],aWStack_220);
    iVar1 = FUN_405e9984(apHStack_230,L"DisplayName",(LPBYTE)aWStack_220,0x104);
    if (iVar1 != 0) {
      SendMessageW(param_1,0x143,0,(LPARAM)aWStack_220);
    }
    FUN_405e98c0(apHStack_230);
    FUN_405e4020(apHStack_230);
    iVar1 = FUN_405e991c(local_240,aWStack_220,0x104);
  }
  FUN_405e4020(local_240);
  FUN_405f9bec(local_18);
  return;
}



/* 405ebbd8 FUN_405ebbd8 */

/* Boundary evidence: original MIPS .pdata 405ebbd8..405ebdbf. Semantic name remains unreviewed. */

undefined4 FUN_405ebbd8(HWND param_1,wchar_t *param_2)

{
  HWND pHVar1;
  wchar_t *_Source;
  WPARAM WVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  undefined4 *puVar6;
  HKEY apHStack_30 [4];
  
  pHVar1 = GetDlgItem(param_1,0x250);
  FUN_405ebae0(pHVar1);
  FUN_405e3fc4(apHStack_30,(HKEY)0x80000001,L"ControlPanel\\Appearance");
  _Source = (wchar_t *)FUN_405f7da0(apHStack_30,L"Current");
  if (_Source == (wchar_t *)0x0) {
    *param_2 = L'\0';
  }
  else {
    WVar2 = SendMessageW(pHVar1,0x158,0,(LPARAM)_Source);
    if (WVar2 != 0xffffffff) {
      SendMessageW(pHVar1,0x14e,WVar2,0);
    }
    wcscpy(param_2,_Source);
  }
  uVar3 = FUN_405e4194(apHStack_30,L"FullControl",0);
  *(undefined4 *)(DAT_405fb8b0 + 0x2e4) = uVar3;
  pHVar1 = GetDlgItem(param_1,0x253);
  puVar6 = &DAT_405fb81c;
  uVar5 = 0;
  iVar4 = DAT_405fb8b0;
  do {
    if ((*(short *)*puVar6 != 0x28) || (*(int *)(iVar4 + 0x2e4) != 0)) {
      WVar2 = SendMessageW(pHVar1,0x143,0,(LPARAM)*puVar6);
      if ((WVar2 == 0xffffffff) || (WVar2 == 0xfffffffe)) {
        FUN_405e4020(apHStack_30);
        return 0;
      }
      SendMessageW(pHVar1,0x151,WVar2,uVar5 | 0x40000000);
      WVar2 = SendMessageW(pHVar1,0x158,0,DAT_405fb820);
      if (WVar2 == 0xffffffff) {
        WVar2 = 0;
      }
      SendMessageW(pHVar1,0x14e,WVar2,0);
      iVar4 = DAT_405fb8b0;
    }
    puVar6 = puVar6 + 1;
    uVar5 = uVar5 + 1;
    if (0x405fb887 < (int)puVar6) {
      FUN_405e4020(apHStack_30);
      return 1;
    }
  } while( true );
}



/* 405ebdc0 FUN_405ebdc0 */

/* Boundary evidence: original MIPS .pdata 405ebdc0..405ebf0f. Semantic name remains unreviewed. */

undefined4 FUN_405ebdc0(wchar_t *param_1,undefined4 *param_2)

{
  HKEY pHVar1;
  LSTATUS LVar2;
  DWORD DVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  uint uVar6;
  DWORD *pDVar7;
  DWORD local_a0 [2];
  HKEY local_98;
  undefined4 local_94;
  undefined4 local_90;
  short local_88 [2];
  undefined4 local_84 [29];
  
  local_98 = (HKEY)0x0;
  local_94 = 0;
  local_90 = 0;
  pHVar1 = FUN_405eb408(param_1,(STRSAFE_LPWSTR)0x0,0,&local_98);
  if ((pHVar1 != (HKEY)0x0) && (local_a0[0] = 0x78, local_98 != (HKEY)0x0)) {
    LVar2 = RegQueryValueExW(local_98,L"Settings",(LPDWORD)0x0,(LPDWORD)0x0,(LPBYTE)local_88,
                             local_a0);
    DVar3 = local_a0[0];
    if (LVar2 != 0) {
      DVar3 = 0;
    }
    if ((DVar3 != 0) && (local_88[0] == -1)) {
      if (DVar3 < 0x78) {
        uVar6 = 0x1d - (0x78 - DVar3 >> 2);
      }
      else {
        uVar6 = 0x1d;
      }
      if ((0 < (int)uVar6) && (puVar5 = local_84, uVar6 != 0)) {
        puVar4 = param_2;
        do {
          *puVar4 = *puVar5;
          puVar4 = puVar4 + 1;
          puVar5 = puVar5 + 1;
        } while (puVar4 != param_2 + uVar6);
      }
      if ((int)uVar6 < 0x1d) {
        pDVar7 = param_2 + uVar6;
        do {
          DVar3 = GetSysColor(uVar6 | 0x40000000);
          uVar6 = uVar6 + 1;
          *pDVar7 = DVar3;
          pDVar7 = pDVar7 + 1;
        } while ((int)uVar6 < 0x1d);
      }
      FUN_405e4020(&local_98);
      return 1;
    }
  }
  FUN_405e4020(&local_98);
  return 0;
}



/* 405ebf10 FUN_405ebf10 */

/* Boundary evidence: original MIPS .pdata 405ebf10..405ebfa7. Semantic name remains unreviewed. */

void FUN_405ebf10(wchar_t *param_1)

{
  HKEY local_18;
  undefined4 local_14;
  undefined4 local_10;
  
  local_18 = (HKEY)0x0;
  local_14 = 0;
  local_10 = 0;
  FUN_405e3f58(&local_18,(HKEY)0x80000001,L"ControlPanel\\Appearance");
  if (*param_1 == L'\0') {
    if (local_18 != (HKEY)0x0) {
      RegDeleteValueW(local_18,L"Current");
    }
  }
  else {
    FUN_405e424c(&local_18,L"Current",param_1);
  }
  FUN_405e4020(&local_18);
  return;
}



/* 405ebfa8 FUN_405ebfa8 */

/* Boundary evidence: original MIPS .pdata 405ebfa8..405ec137. Semantic name remains unreviewed. */

void FUN_405ebfa8(HDC param_1,int param_2,int param_3,int param_4,int param_5,short param_6,
                 short param_7)

{
  HGDIOBJ pvVar1;
  HBRUSH pHVar2;
  HBRUSH ho;
  int iVar3;
  int iVar4;
  tagRECT tStack_38;
  
  SetRect(&tStack_38,param_2,param_3,param_2 + param_4,param_3 + param_5);
  pvVar1 = GetStockObject(2);
  pHVar2 = CreateSolidBrush(*(COLORREF *)(*(int *)(DAT_405fb8b4 + 0xc) + 0x54));
  iVar3 = (int)param_7;
  iVar4 = (int)param_6;
  if (pHVar2 != (HBRUSH)0x0) {
    FUN_405e9d1c(param_1,&tStack_38.left,iVar4,iVar3,pvVar1,pHVar2,0xf);
    DeleteObject(pHVar2);
  }
  InflateRect(&tStack_38,-iVar4,-iVar3);
  pHVar2 = CreateSolidBrush(*(COLORREF *)(*(int *)(DAT_405fb8b4 + 0xc) + 0x58));
  if (pHVar2 != (HBRUSH)0x0) {
    ho = CreateSolidBrush(*(COLORREF *)(*(int *)(DAT_405fb8b4 + 0xc) + 0x40));
    if (ho != (HBRUSH)0x0) {
      FUN_405e9d1c(param_1,&tStack_38.left,iVar4,iVar3,pHVar2,ho,0xf);
      DeleteObject(ho);
    }
    DeleteObject(pHVar2);
  }
  InflateRect(&tStack_38,-iVar4,-iVar3);
  pHVar2 = CreateSolidBrush(*(COLORREF *)(*(int *)(DAT_405fb8b4 + 0xc) + 0x3c));
  FillRect(param_1,&tStack_38,pHVar2);
  DeleteObject(pHVar2);
  return;
}



/* 405ec138 FUN_405ec138 */

/* Boundary evidence: original MIPS .pdata 405ec138..405ec24b. Semantic name remains unreviewed. */

void FUN_405ec138(HWND param_1,HWND param_2)

{
  WPARAM wParam;
  int iVar1;
  DWORD DVar2;
  DWORD *pDVar3;
  uint uVar4;
  
  wParam = SendMessageW(param_2,0x147,0,0);
  if (wParam != 0xffffffff) {
    SendMessageW(param_2,0x148,wParam,(LPARAM)DAT_405fb8b0);
    iVar1 = FUN_405ebdc0(DAT_405fb8b0,(undefined4 *)(DAT_405fb8b0 + 0x104));
    if (iVar1 == 0) {
      uVar4 = 0;
      iVar1 = 0x208;
      *DAT_405fb8b0 = L'\0';
      do {
        DVar2 = GetSysColor(uVar4 | 0x40000000);
        pDVar3 = (DWORD *)(iVar1 + (int)DAT_405fb8b0);
        iVar1 = iVar1 + 4;
        *pDVar3 = DVar2;
        uVar4 = uVar4 + 1;
      } while (iVar1 < 0x27c);
      SendMessageW(param_2,0x14e,0xffffffff,0);
    }
    SendDlgItemMessageW(param_1,0x24f,0x401,0x1d,(LPARAM)(DAT_405fb8b0 + 0x104));
    SendDlgItemMessageW(param_1,0x24f,0x400,0,0);
  }
  return;
}



/* 405ec24c FUN_405ec24c */

/* Boundary evidence: original MIPS .pdata 405ec24c..405ec2f3. Semantic name remains unreviewed. */

void FUN_405ec24c(HWND param_1)

{
  HWND hWnd;
  LRESULT LVar1;
  wchar_t *pwVar2;
  uint uVar3;
  uint uVar4;
  uint *puVar5;
  uint local_88 [30];
  
  uVar4 = 0;
  puVar5 = local_88;
  do {
    uVar3 = uVar4 | 0x40000000;
    uVar4 = uVar4 + 1;
    *puVar5 = uVar3;
    puVar5 = puVar5 + 1;
  } while ((int)uVar4 < 0x1d);
  SetSysColors(0x1d,(INT *)local_88,(COLORREF *)(DAT_405fb8b0 + 0x104));
  hWnd = GetDlgItem(param_1,0x250);
  LVar1 = SendMessageW(hWnd,0x147,0,0);
  pwVar2 = DAT_405fb8b0;
  if (LVar1 == -1) {
    pwVar2 = L"";
  }
  FUN_405ebf10(pwVar2);
  return;
}



/* 405ec2f4 FUN_405ec2f4 */

/* Boundary evidence: original MIPS .pdata 405ec2f4..405ec447. Semantic name remains unreviewed. */

void FUN_405ec2f4(HWND param_1)

{
  undefined4 uVar1;
  int iVar2;
  HWND pHVar3;
  int local_18 [2];
  
  if (*(int *)(DAT_405fb8b0 + 0x280) == 0) {
    *(int *)(DAT_405fb8b0 + 0x280) = 0x24;
    *(HWND *)(DAT_405fb8b0 + 0x284) = param_1;
    *(int *)(DAT_405fb8b0 + 0x290) = DAT_405fb8b0 + 0x2a4;
    *(undefined4 *)(DAT_405fb8b0 + 0x294) = 1;
  }
  uVar1 = FUN_405e9834(param_1,local_18);
  *(undefined4 *)(DAT_405fb8b0 + 0x28c) = uVar1;
  iVar2 = ChooseColor(DAT_405fb8b0 + 0x280);
  if (iVar2 != 0) {
    pHVar3 = GetDlgItem(param_1,0x250);
    SendMessageW(pHVar3,0x14e,0xffffffff,0);
    if (local_18[0] == 0x4000000f) {
      FUN_405eb9c8(*(uint *)(DAT_405fb8b0 + 0x28c));
    }
    else {
      *(undefined4 *)(local_18[0] * 4 + *(int *)(DAT_405fb8b4 + 0xc)) =
           *(undefined4 *)(DAT_405fb8b0 + 0x28c);
    }
    pHVar3 = GetDlgItem(param_1,0x254);
    InvalidateRect(pHVar3,(RECT *)0x0,0);
    SendDlgItemMessageW(param_1,0x24f,0x400,0,0);
  }
  return;
}



/* 405ec448 FUN_405ec448 */

/* Boundary evidence: original MIPS .pdata 405ec448..405ec5fb. Semantic name remains unreviewed. */

void FUN_405ec448(HDC param_1,undefined4 param_2,int param_3,int param_4)

{
  COLORREF color;
  COLORREF color_00;
  int iVar1;
  
  iVar1 = *(int *)(*(int *)(DAT_405fb8b4 + 0xc) + 0x3c);
  if (*(int *)(DAT_405fb8b4 + 0x304) == 0) {
    *(undefined4 *)(DAT_405fb8b4 + 0x304) = 0x38;
    *(undefined4 *)(DAT_405fb8b4 + 0x308) = *(undefined4 *)(DAT_405fb8b4 + 0x300);
    *(HDC *)(DAT_405fb8b4 + 0x310) = param_1;
    *(undefined4 *)(DAT_405fb8b4 + 0x31c) = 0;
    *(undefined4 *)(DAT_405fb8b4 + 800) = 0;
    *(undefined4 *)(DAT_405fb8b4 + 0x324) = 0;
    *(undefined4 *)(DAT_405fb8b4 + 0x328) = 0;
    *(undefined4 *)(DAT_405fb8b4 + 0x32c) = 0xffffffff;
    *(undefined4 *)(DAT_405fb8b4 + 0x330) = 0xff000000;
    *(undefined4 *)(DAT_405fb8b4 + 0x338) = 0x660046;
  }
  FUN_405ebfa8(param_1,param_3,param_4,0x17,0x16,1,1);
  *(undefined4 *)(DAT_405fb8b4 + 0x30c) = param_2;
  *(int *)(DAT_405fb8b4 + 0x314) = param_3 + 3;
  *(int *)(DAT_405fb8b4 + 0x318) = param_4 + 3;
  *(undefined4 *)(DAT_405fb8b4 + 0x334) = 1;
  ImageList_DrawIndirect((IMAGELISTDRAWPARAMS *)(DAT_405fb8b4 + 0x304));
  if (iVar1 == 0) {
    color = SetBkColor(param_1,0);
    color_00 = SetTextColor(param_1,0xffffff);
    *(undefined4 *)(DAT_405fb8b4 + 0x334) = 0x50;
    ImageList_DrawIndirect((IMAGELISTDRAWPARAMS *)(DAT_405fb8b4 + 0x304));
    SetBkColor(param_1,color);
    SetTextColor(param_1,color_00);
  }
  return;
}



/* 405ec5fc FUN_405ec5fc */

/* Boundary evidence: original MIPS .pdata 405ec5fc..405ed70b. Semantic name remains unreviewed. */

void FUN_405ec5fc(undefined4 param_1,HDC param_2)

{
  wchar_t *pwVar1;
  LONG LVar2;
  int iVar3;
  HBRUSH pHVar4;
  HGDIOBJ pvVar5;
  size_t sVar6;
  HBRUSH pHVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  short sVar11;
  int iVar12;
  short sVar13;
  int iVar14;
  int iVar15;
  undefined8 uVar16;
  tagRECT local_38;
  
  if ((0x1c < *(short *)(DAT_405fb8b4 + 8)) && (*(int *)(DAT_405fb8b4 + 0xc) != 0)) {
    iVar3 = GetSystemMetrics(5);
    sVar11 = (short)iVar3;
    iVar12 = (int)sVar11;
    iVar3 = GetSystemMetrics(6);
    sVar13 = (short)iVar3;
    iVar14 = (int)sVar13;
    iVar3 = GetSystemMetrics(0x2d);
    GetSystemMetrics(0x2e);
    SaveDC(param_2);
    pHVar4 = CreateSolidBrush(*(COLORREF *)
                               (*(int *)(DAT_405fb8b4 + 0x2a0) * 4 + *(int *)(DAT_405fb8b4 + 0xc)));
    if (pHVar4 != (HBRUSH)0x0) {
      FillRect(param_2,(RECT *)(DAT_405fb8b4 + 0x130),pHVar4);
      DeleteObject(pHVar4);
    }
    pHVar4 = CreateSolidBrush(*(COLORREF *)
                               (*(int *)(DAT_405fb8b4 + 0x2a4) * 4 + *(int *)(DAT_405fb8b4 + 0xc)));
    FillRect(param_2,(RECT *)(DAT_405fb8b4 + 0x140),pHVar4);
    DeleteObject(pHVar4);
    iVar9 = 0;
    if (*(int *)(*(int *)(DAT_405fb8b4 + 0xc) + 0x14) != 0) {
      iVar9 = 4;
    }
    pvVar5 = GetStockObject(iVar9);
    local_38.left = *(LONG *)(DAT_405fb8b4 + 0x140);
    local_38.top = *(LONG *)(DAT_405fb8b4 + 0x144);
    local_38.right = *(LONG *)(DAT_405fb8b4 + 0x148);
    local_38.bottom = *(LONG *)(DAT_405fb8b4 + 0x14c);
    InflateRect(&local_38,1,1);
    FUN_405e9d1c(param_2,&local_38.left,iVar12,iVar14,pvVar5,pvVar5,5);
    pHVar4 = CreateSolidBrush(*(COLORREF *)
                               (*(int *)(DAT_405fb8b4 + 0x2a8) * 4 + *(int *)(DAT_405fb8b4 + 0xc)));
    FillRect(param_2,(RECT *)(DAT_405fb8b4 + 0x150),pHVar4);
    DeleteObject(pHVar4);
    pHVar4 = CreateSolidBrush(*(COLORREF *)
                               (*(int *)(DAT_405fb8b4 + 0x2ac) * 4 + *(int *)(DAT_405fb8b4 + 0xc)));
    FillRect(param_2,(RECT *)(DAT_405fb8b4 + 0x160),pHVar4);
    DeleteObject(pHVar4);
    SelectObject(param_2,*(HGDIOBJ *)(DAT_405fb8b4 + 0x10));
    SetTextColor(param_2,*(COLORREF *)
                          (*(int *)(DAT_405fb8b4 + 0x2b0) * 4 + *(int *)(DAT_405fb8b4 + 0xc)));
    SetBkColor(param_2,*(COLORREF *)
                        (*(int *)(DAT_405fb8b4 + 0x2ac) * 4 + *(int *)(DAT_405fb8b4 + 0xc)));
    pwVar1 = DAT_405fb8ac;
    sVar6 = wcslen(DAT_405fb8ac);
    DrawTextW(param_2,pwVar1,sVar6,(LPRECT)(DAT_405fb8b4 + 0x170),0x25);
    SetTextColor(param_2,*(COLORREF *)
                          (*(int *)(DAT_405fb8b4 + 0x2b4) * 4 + *(int *)(DAT_405fb8b4 + 0xc)));
    pwVar1 = DAT_405fb8a8;
    sVar6 = wcslen(DAT_405fb8a8);
    DrawTextW(param_2,pwVar1,sVar6,(LPRECT)(DAT_405fb8b4 + 0x180),0x25);
    pHVar4 = CreateSolidBrush(*(COLORREF *)
                               (*(int *)(DAT_405fb8b4 + 0x2b8) * 4 + *(int *)(DAT_405fb8b4 + 0xc)));
    FillRect(param_2,(RECT *)(DAT_405fb8b4 + 400),pHVar4);
    DeleteObject(pHVar4);
    SetTextColor(param_2,*(COLORREF *)(*(int *)(DAT_405fb8b4 + 0xc) + 0x38));
    SetBkColor(param_2,*(COLORREF *)
                        (*(int *)(DAT_405fb8b4 + 0x2b8) * 4 + *(int *)(DAT_405fb8b4 + 0xc)));
    pwVar1 = DAT_405fb8a4;
    sVar6 = wcslen(DAT_405fb8a4);
    DrawTextW(param_2,pwVar1,sVar6,(LPRECT)(DAT_405fb8b4 + 400),0x25);
    iVar9 = 0;
    if (*(int *)(*(int *)(DAT_405fb8b4 + 0xc) + 0x14) != 0) {
      iVar9 = 4;
    }
    pvVar5 = GetStockObject(iVar9);
    FUN_405e9d1c(param_2,(int *)(DAT_405fb8b4 + 0x160),iVar12,iVar14,pvVar5,pvVar5,0xf);
    iVar15 = 2;
    local_38.top = *(int *)(DAT_405fb8b4 + 0x154);
    local_38.right = *(LONG *)(DAT_405fb8b4 + 0x158);
    local_38.bottom = *(int *)(DAT_405fb8b4 + 0x15c);
    local_38.left = *(int *)(DAT_405fb8b4 + 0x1a0) + 1;
    pvVar5 = GetStockObject(2);
    FUN_405e9d1c(param_2,&local_38.left,iVar12,iVar14,pvVar5,pvVar5,1);
    pHVar4 = CreateSolidBrush(*(COLORREF *)(*(int *)(DAT_405fb8b4 + 0xc) + 0x50));
    local_38.left = local_38.left + 1;
    FUN_405e9d1c(param_2,&local_38.left,iVar12,iVar14,pHVar4,pHVar4,1);
    DeleteObject(pHVar4);
    pHVar4 = CreateSolidBrush(*(COLORREF *)(*(int *)(DAT_405fb8b4 + 0xc) + 0x54));
    pHVar7 = CreateSolidBrush(*(COLORREF *)(*(int *)(DAT_405fb8b4 + 0xc) + 0x40));
    local_38.top = iVar14 + local_38.top;
    local_38.left = iVar12 + local_38.left + 4;
    local_38.bottom = local_38.bottom - iVar14;
    local_38.right = iVar12 * 7 + local_38.left;
    FUN_405e9d1c(param_2,&local_38.left,iVar12,iVar14,pHVar4,pHVar4,5);
    DeleteObject(pHVar4);
    pHVar4 = CreateSolidBrush(*(COLORREF *)(*(int *)(DAT_405fb8b4 + 0xc) + 0x50));
    iVar9 = iVar12 * 3;
    local_38.top = iVar14 + local_38.top;
    local_38.left = iVar12 + local_38.left;
    local_38.right = iVar9 + local_38.left;
    FUN_405e9d1c(param_2,&local_38.left,iVar12,iVar14,pHVar4,pHVar7,0xf);
    local_38.left = iVar9 + local_38.left;
    local_38.right = iVar9 + local_38.left;
    FUN_405e9d1c(param_2,&local_38.left,iVar12,iVar14,pHVar4,pHVar7,0xf);
    DeleteObject(pHVar4);
    DeleteObject(pHVar7);
    LVar2 = local_38.right;
    FUN_405ec448(param_2,0,local_38.right + 3,*(int *)(DAT_405fb8b4 + 0x1a4));
    FUN_405ec448(param_2,1,LVar2 + 0x1a,*(int *)(DAT_405fb8b4 + 0x1a4));
    FUN_405ec448(param_2,2,LVar2 + 0x31,*(int *)(DAT_405fb8b4 + 0x1a4));
    pHVar4 = CreateSolidBrush(*(COLORREF *)
                               (*(int *)(DAT_405fb8b4 + 0x2c0) * 4 + *(int *)(DAT_405fb8b4 + 0xc)));
    FillRect(param_2,(RECT *)(DAT_405fb8b4 + 0x1b0),pHVar4);
    DeleteObject(pHVar4);
    iVar9 = *(int *)(DAT_405fb8b4 + 0x1b0);
    FUN_405ec448(param_2,3,iVar9,*(int *)(DAT_405fb8b4 + 0x1b4));
    FUN_405ec448(param_2,4,iVar9 + 0x1b,*(int *)(DAT_405fb8b4 + 0x1b4));
    if (**(COLORREF **)(DAT_405fb8b4 + 0xc) == 0xe0e0e0) {
      pHVar4 = *(HBRUSH *)(DAT_405fb8b4 + 0x2fc);
      if (pHVar4 == (HBRUSH)0x0) {
        pHVar4 = GetStockObject(1);
      }
    }
    else {
      pHVar4 = CreateSolidBrush(**(COLORREF **)(DAT_405fb8b4 + 0xc));
    }
    FillRect(param_2,(RECT *)(DAT_405fb8b4 + 0x1c0),pHVar4);
    if (pHVar4 != *(HBRUSH *)(DAT_405fb8b4 + 0x2fc)) {
      DeleteObject(pHVar4);
    }
    iVar9 = DAT_405fb8b4;
    iVar10 = *(int *)(DAT_405fb8b4 + 0x1dc);
    uVar16 = __litodp(iVar10 - *(int *)(DAT_405fb8b4 + 0x1d4));
    uVar16 = __dpmul((int)uVar16,(int)((ulonglong)uVar16 >> 0x20),0,0x3ff80000);
    iVar8 = __dptoli((int)uVar16,(int)((ulonglong)uVar16 >> 0x20));
    FUN_405ebfa8(param_2,*(int *)(iVar9 + 0x1d0),(short)iVar3 * 2 + iVar10,
                 *(int *)(iVar9 + 0x1c8) - *(int *)(iVar9 + 0x1c0),iVar8,sVar11,sVar13);
    pHVar4 = CreateSolidBrush(*(COLORREF *)(*(int *)(DAT_405fb8b4 + 0xc) + 0x48));
    pvVar5 = SelectObject(param_2,pHVar4);
    FUN_405ebfa8(param_2,*(int *)(DAT_405fb8b4 + 0x1d0),*(int *)(DAT_405fb8b4 + 0x1d4),
                 *(int *)(DAT_405fb8b4 + 0x1d8) - *(int *)(DAT_405fb8b4 + 0x1d0),
                 *(int *)(DAT_405fb8b4 + 0x1dc) - *(int *)(DAT_405fb8b4 + 0x1d4),sVar11,sVar13);
    local_38.left = *(int *)(DAT_405fb8b4 + 0x1d0);
    local_38.top = *(int *)(DAT_405fb8b4 + 0x1d4);
    local_38.right = *(int *)(DAT_405fb8b4 + 0x1d8);
    local_38.bottom = *(int *)(DAT_405fb8b4 + 0x1dc);
    InflateRect(&local_38,-1,-1);
    iVar3 = local_38.bottom - local_38.top;
    if (6 < iVar3) {
      iVar9 = iVar3 + -7;
      if (iVar9 < 0) {
        iVar9 = iVar3 + -4;
      }
      iVar15 = (iVar9 >> 2) + 3;
    }
    iVar9 = (local_38.bottom - iVar15) - local_38.top;
    iVar3 = iVar9 + 1;
    iVar8 = iVar15 * 2 + -1;
    if (iVar3 < 0) {
      iVar3 = iVar9 + 2;
    }
    iVar10 = (local_38.right - iVar8) - local_38.left;
    iVar9 = iVar10 + 1;
    if (iVar9 < 0) {
      iVar9 = iVar10 + 2;
    }
    FUN_405e9ea0(param_2,(iVar9 >> 1) + local_38.left,(iVar3 >> 1) + local_38.top,iVar8,-1);
    FUN_405ebfa8(param_2,*(int *)(DAT_405fb8b4 + 0x1e0),*(int *)(DAT_405fb8b4 + 0x1e4),
                 *(int *)(DAT_405fb8b4 + 0x1e8) - *(int *)(DAT_405fb8b4 + 0x1e0),
                 *(int *)(DAT_405fb8b4 + 0x1ec) - *(int *)(DAT_405fb8b4 + 0x1e4),sVar11,sVar13);
    local_38.left = *(int *)(DAT_405fb8b4 + 0x1e0);
    local_38.top = *(int *)(DAT_405fb8b4 + 0x1e4);
    local_38.right = *(int *)(DAT_405fb8b4 + 0x1e8);
    local_38.bottom = *(int *)(DAT_405fb8b4 + 0x1ec);
    InflateRect(&local_38,-1,-1);
    iVar9 = (local_38.bottom - iVar15) - local_38.top;
    iVar3 = iVar9 + 1;
    if (iVar3 < 0) {
      iVar3 = iVar9 + 2;
    }
    iVar15 = (local_38.right - iVar8) - local_38.left;
    iVar9 = iVar15 + 1;
    if (iVar9 < 0) {
      iVar9 = iVar15 + 2;
    }
    FUN_405e9ea0(param_2,(iVar9 >> 1) + local_38.left,(iVar3 >> 1) + local_38.top,iVar8,1);
    SelectObject(param_2,pvVar5);
    DeleteObject(pHVar4);
    pHVar4 = CreateSolidBrush(*(COLORREF *)
                               (*(int *)(DAT_405fb8b4 + 0x2d0) * 4 + *(int *)(DAT_405fb8b4 + 0xc)));
    FillRect(param_2,(RECT *)(DAT_405fb8b4 + 0x1f0),pHVar4);
    DeleteObject(pHVar4);
    local_38.left = *(LONG *)(DAT_405fb8b4 + 0x1f0);
    local_38.top = *(LONG *)(DAT_405fb8b4 + 500);
    local_38.right = *(LONG *)(DAT_405fb8b4 + 0x1f8);
    local_38.bottom = *(LONG *)(DAT_405fb8b4 + 0x1fc);
    iVar3 = 0;
    if (*(int *)(*(int *)(DAT_405fb8b4 + 0xc) + 0x14) != 0) {
      iVar3 = 4;
    }
    pvVar5 = GetStockObject(iVar3);
    FUN_405e9d1c(param_2,&local_38.left,iVar12,iVar14,pvVar5,pvVar5,7);
    iVar3 = -iVar12;
    iVar9 = -iVar14;
    InflateRect(&local_38,iVar3,iVar9);
    pHVar4 = CreateSolidBrush(*(COLORREF *)(*(int *)(DAT_405fb8b4 + 0xc) + 0x58));
    pHVar7 = CreateSolidBrush(*(COLORREF *)(*(int *)(DAT_405fb8b4 + 0xc) + 0x54));
    FUN_405e9d1c(param_2,&local_38.left,iVar12,iVar14,pHVar4,pHVar7,7);
    DeleteObject(pHVar4);
    DeleteObject(pHVar7);
    InflateRect(&local_38,iVar3,iVar9);
    pHVar4 = CreateSolidBrush(*(COLORREF *)(*(int *)(DAT_405fb8b4 + 0xc) + 0x50));
    pHVar7 = CreateSolidBrush(*(COLORREF *)(*(int *)(DAT_405fb8b4 + 0xc) + 0x40));
    FUN_405e9d1c(param_2,&local_38.left,iVar12,iVar14,pHVar4,pHVar7,7);
    DeleteObject(pHVar4);
    DeleteObject(pHVar7);
    pHVar4 = CreateSolidBrush(*(COLORREF *)
                               (*(int *)(DAT_405fb8b4 + 0x2d4) * 4 + *(int *)(DAT_405fb8b4 + 0xc)));
    FillRect(param_2,(RECT *)(DAT_405fb8b4 + 0x200),pHVar4);
    DeleteObject(pHVar4);
    SelectObject(param_2,*(HGDIOBJ *)(DAT_405fb8b4 + 0x70));
    SetTextColor(param_2,*(COLORREF *)
                          (*(int *)(DAT_405fb8b4 + 0x2d8) * 4 + *(int *)(DAT_405fb8b4 + 0xc)));
    SetBkColor(param_2,*(COLORREF *)
                        (*(int *)(DAT_405fb8b4 + 0x2d4) * 4 + *(int *)(DAT_405fb8b4 + 0xc)));
    pwVar1 = DAT_405fb89c;
    local_38.top = *(LONG *)(DAT_405fb8b4 + 0x214);
    local_38.left = iVar12 + *(int *)(DAT_405fb8b4 + 0x210);
    local_38.right = *(LONG *)(DAT_405fb8b4 + 0x218);
    local_38.bottom = *(LONG *)(DAT_405fb8b4 + 0x21c);
    sVar6 = wcslen(DAT_405fb89c);
    DrawTextW(param_2,pwVar1,sVar6,&local_38,0x24);
    iVar15 = *(int *)(DAT_405fb8b4 + 0x220);
    FUN_405ec448(param_2,3,iVar15,*(int *)(DAT_405fb8b4 + 0x224));
    FUN_405ec448(param_2,5,iVar15 + 0x19,*(int *)(DAT_405fb8b4 + 0x224));
    FUN_405ec448(param_2,4,iVar15 + 0x32,*(int *)(DAT_405fb8b4 + 0x224));
    SelectObject(param_2,*(HGDIOBJ *)(DAT_405fb8b4 + 0x70));
    SetTextColor(param_2,*(COLORREF *)
                          (*(int *)(DAT_405fb8b4 + 0x2f0) * 4 + *(int *)(DAT_405fb8b4 + 0xc)));
    SetBkColor(param_2,*(COLORREF *)
                        (*(int *)(DAT_405fb8b4 + 0x2d0) * 4 + *(int *)(DAT_405fb8b4 + 0xc)));
    pwVar1 = DAT_405fb894;
    sVar6 = wcslen(DAT_405fb894);
    DrawTextW(param_2,pwVar1,sVar6,(LPRECT)(DAT_405fb8b4 + 0x270),0x24);
    pHVar4 = CreateSolidBrush(*(COLORREF *)
                               (*(int *)(DAT_405fb8b4 + 0x2e0) * 4 + *(int *)(DAT_405fb8b4 + 0xc)));
    FillRect(param_2,(RECT *)(DAT_405fb8b4 + 0x230),pHVar4);
    DeleteObject(pHVar4);
    local_38.left = *(LONG *)(DAT_405fb8b4 + 0x230);
    local_38.top = *(LONG *)(DAT_405fb8b4 + 0x234);
    local_38.right = *(LONG *)(DAT_405fb8b4 + 0x238);
    local_38.bottom = *(LONG *)(DAT_405fb8b4 + 0x23c);
    iVar15 = 0;
    if (*(int *)(*(int *)(DAT_405fb8b4 + 0xc) + 0x14) != 0) {
      iVar15 = 4;
    }
    pvVar5 = GetStockObject(iVar15);
    FUN_405e9d1c(param_2,&local_38.left,iVar12,iVar14,pvVar5,pvVar5,7);
    InflateRect(&local_38,iVar3,iVar9);
    pHVar4 = CreateSolidBrush(*(COLORREF *)(*(int *)(DAT_405fb8b4 + 0xc) + 0x58));
    pHVar7 = CreateSolidBrush(*(COLORREF *)(*(int *)(DAT_405fb8b4 + 0xc) + 0x54));
    FUN_405e9d1c(param_2,&local_38.left,iVar12,iVar14,pHVar4,pHVar7,7);
    DeleteObject(pHVar4);
    DeleteObject(pHVar7);
    InflateRect(&local_38,iVar3,iVar9);
    pHVar4 = CreateSolidBrush(*(COLORREF *)(*(int *)(DAT_405fb8b4 + 0xc) + 0x50));
    pHVar7 = CreateSolidBrush(*(COLORREF *)(*(int *)(DAT_405fb8b4 + 0xc) + 0x40));
    FUN_405e9d1c(param_2,&local_38.left,iVar12,iVar14,pHVar4,pHVar7,7);
    DeleteObject(pHVar4);
    DeleteObject(pHVar7);
    pHVar4 = CreateSolidBrush(*(COLORREF *)
                               (*(int *)(DAT_405fb8b4 + 0x2e4) * 4 + *(int *)(DAT_405fb8b4 + 0xc)));
    FillRect(param_2,(RECT *)(DAT_405fb8b4 + 0x240),pHVar4);
    DeleteObject(pHVar4);
    SelectObject(param_2,*(HGDIOBJ *)(DAT_405fb8b4 + 0x70));
    SetTextColor(param_2,*(COLORREF *)
                          (*(int *)(DAT_405fb8b4 + 0x2e8) * 4 + *(int *)(DAT_405fb8b4 + 0xc)));
    SetBkColor(param_2,*(COLORREF *)
                        (*(int *)(DAT_405fb8b4 + 0x2e4) * 4 + *(int *)(DAT_405fb8b4 + 0xc)));
    pwVar1 = DAT_405fb898;
    local_38.top = *(LONG *)(DAT_405fb8b4 + 0x254);
    local_38.left = iVar12 + *(int *)(DAT_405fb8b4 + 0x250);
    local_38.right = *(LONG *)(DAT_405fb8b4 + 600);
    local_38.bottom = *(LONG *)(DAT_405fb8b4 + 0x25c);
    sVar6 = wcslen(DAT_405fb898);
    DrawTextW(param_2,pwVar1,sVar6,&local_38,0x24);
    iVar3 = *(int *)(DAT_405fb8b4 + 0x260);
    FUN_405ec448(param_2,3,iVar3,*(int *)(DAT_405fb8b4 + 0x264));
    FUN_405ec448(param_2,5,iVar3 + 0x19,*(int *)(DAT_405fb8b4 + 0x264));
    FUN_405ec448(param_2,4,iVar3 + 0x32,*(int *)(DAT_405fb8b4 + 0x264));
    SelectObject(param_2,*(HGDIOBJ *)(DAT_405fb8b4 + 0xd0));
    SetTextColor(param_2,*(COLORREF *)
                          (*(int *)(DAT_405fb8b4 + 0x2f4) * 4 + *(int *)(DAT_405fb8b4 + 0xc)));
    SetBkColor(param_2,*(COLORREF *)
                        (*(int *)(DAT_405fb8b4 + 0x2e0) * 4 + *(int *)(DAT_405fb8b4 + 0xc)));
    pwVar1 = DAT_405fb890;
    sVar6 = wcslen(DAT_405fb890);
    DrawTextW(param_2,pwVar1,sVar6,(LPRECT)(DAT_405fb8b4 + 0x280),0x24);
    FUN_405ebfa8(param_2,*(int *)(DAT_405fb8b4 + 0x290),*(int *)(DAT_405fb8b4 + 0x294),
                 *(int *)(DAT_405fb8b4 + 0x298) - *(int *)(DAT_405fb8b4 + 0x290),
                 *(int *)(DAT_405fb8b4 + 0x29c) - *(int *)(DAT_405fb8b4 + 0x294),sVar11,sVar13);
    SelectObject(param_2,*(HGDIOBJ *)(DAT_405fb8b4 + 0x70));
    SetTextColor(param_2,*(COLORREF *)(*(int *)(DAT_405fb8b4 + 0xc) + 0x48));
    SetBkColor(param_2,*(COLORREF *)
                        (*(int *)(DAT_405fb8b4 + 0x2f8) * 4 + *(int *)(DAT_405fb8b4 + 0xc)));
    pwVar1 = DAT_405fb8a0;
    sVar6 = wcslen(DAT_405fb8a0);
    DrawTextW(param_2,pwVar1,sVar6,(LPRECT)(DAT_405fb8b4 + 0x290),0x25);
    RestoreDC(param_2,-1);
  }
  return;
}



/* 405ed70c FUN_405ed70c */

/* Boundary evidence: original MIPS .pdata 405ed70c..405ed787. Semantic name remains unreviewed. */

void FUN_405ed70c(HWND param_1)

{
  tagPAINTSTRUCT local_50;
  uint local_10;
  
  local_10 = DAT_405fb760;
  BeginPaint(param_1,&local_50);
  if (*(int *)(DAT_405fb8b4 + 4) == 0) {
    FUN_405ec5fc(param_1,local_50.hdc);
  }
  else {
    FUN_405e9c68(param_1,local_50.hdc);
  }
  EndPaint(param_1,&local_50);
  FUN_405f9bec(local_10);
  return;
}



/* 405ed788 FUN_405ed788 */

/* Boundary evidence: original MIPS .pdata 405ed788..405ed80f. Semantic name remains unreviewed. */

void FUN_405ed788(HWND param_1)

{
  HGDIOBJ h;
  
  if ((HGDIOBJ)DAT_405fb8b4[1] != (HGDIOBJ)0x0) {
    h = SelectObject((HDC)*DAT_405fb8b4,(HGDIOBJ)DAT_405fb8b4[1]);
    FUN_405ec5fc(param_1,(HDC)*DAT_405fb8b4);
    if (h != (HGDIOBJ)0x0) {
      SelectObject((HDC)*DAT_405fb8b4,h);
    }
  }
  InvalidateRect(param_1,(RECT *)0x0,0);
  return;
}



/* 405ed810 FUN_405ed810 */

/* Boundary evidence: original MIPS .pdata 405ed810..405ed9ff. Semantic name remains unreviewed. */

undefined4 FUN_405ed810(HWND param_1)

{
  HDC hdc;
  HDC pHVar1;
  HBITMAP pHVar2;
  int iVar3;
  HIMAGELIST p_Var4;
  undefined4 uVar5;
  tagRECT local_30;
  
  if (DAT_405fb8b4 == (int *)0x0) {
    DAT_405fb8b4 = LocalAlloc(0x40,0x348);
    if (DAT_405fb8b4 != (int *)0x0) {
      DAT_405fb8b4[0xd1] = -1;
      GetClientRect(param_1,&local_30);
      hdc = GetDC(param_1);
      pHVar1 = CreateCompatibleDC(hdc);
      *DAT_405fb8b4 = (int)pHVar1;
      if (*DAT_405fb8b4 != 0) {
        pHVar2 = CreateCompatibleBitmap
                           (hdc,local_30.right - local_30.left,local_30.bottom - local_30.top);
        DAT_405fb8b4[1] = (int)pHVar2;
      }
      ReleaseDC(param_1,hdc);
      iVar3 = FUN_405ea21c();
      if (iVar3 != 0) {
        iVar3 = FUN_405e9f90();
        DAT_405fb8b4[0xbf] = iVar3;
        FUN_405ea318(param_1);
        p_Var4 = ImageList_Create(0x10,0x10,0xff,5,1);
        DAT_405fb8b4[0xc0] = (int)p_Var4;
        if (DAT_405fb8b4[0xc0] != 0) {
          pHVar2 = LoadBitmapW(DAT_405fb7fc,(LPCWSTR)0x13d1);
          ImageList_AddMasked((HIMAGELIST)DAT_405fb8b4[0xc0],pHVar2,0xff000000);
          pHVar2 = LoadBitmapW(DAT_405fb7fc,(LPCWSTR)0x13d3);
          ImageList_AddMasked((HIMAGELIST)DAT_405fb8b4[0xc0],pHVar2,0xff000000);
          pHVar2 = LoadBitmapW(DAT_405fb7fc,(LPCWSTR)0x13d2);
          ImageList_AddMasked((HIMAGELIST)DAT_405fb8b4[0xc0],pHVar2,0xff000000);
          if (DAT_405fb8b4[1] == 0) {
            return 1;
          }
          FUN_405ed788(param_1);
          return 1;
        }
      }
      FUN_405e99e0();
    }
    uVar5 = 0;
  }
  else {
    uVar5 = 1;
  }
  return uVar5;
}



/* 405eda00 FUN_405eda00 */

/* Boundary evidence: original MIPS .pdata 405eda00..405edb1f. Semantic name remains unreviewed. */

LRESULT FUN_405eda00(HWND param_1,UINT param_2,WPARAM param_3,uint param_4)

{
  LRESULT LVar1;
  HWND pHVar2;
  int iVar3;
  
  if (param_2 == 1) {
    iVar3 = FUN_405ed810(param_1);
    if (iVar3 == 0) {
      return -1;
    }
  }
  else if (param_2 == 2) {
    FUN_405e99e0();
  }
  else if (param_2 == 0xf) {
    FUN_405ed70c(param_1);
  }
  else if (param_2 == 0x201) {
    *(uint *)(DAT_405fb8b4 + 0x33c) = param_4 & 0xffff;
    *(uint *)(DAT_405fb8b4 + 0x340) = param_4 >> 0x10;
    FUN_405e9abc(param_1,*(LONG *)(DAT_405fb8b4 + 0x33c),*(LONG *)(DAT_405fb8b4 + 0x340));
  }
  else if (param_2 == 0x400) {
    FUN_405ed788(param_1);
  }
  else {
    if (param_2 != 0x401) {
      LVar1 = DefWindowProcW(param_1,param_2,param_3,param_4);
      return LVar1;
    }
    *(short *)(DAT_405fb8b4 + 8) = (short)param_3;
    *(uint *)(DAT_405fb8b4 + 0xc) = param_4;
    pHVar2 = GetParent(param_1);
    pHVar2 = GetDlgItem(pHVar2,0x254);
    InvalidateRect(pHVar2,(RECT *)0x0,0);
  }
  return 0;
}



/* 405edb20 FUN_405edb20 */

/* Boundary evidence: original MIPS .pdata 405edb20..405edbcb. Semantic name remains unreviewed. */

undefined4 FUN_405edb20(HINSTANCE param_1)

{
  ATOM AVar1;
  BOOL BVar2;
  undefined2 extraout_var;
  tagWNDCLASSW local_38;
  
  BVar2 = GetClassInfoW(param_1,L"MSPreview",&local_38);
  if (BVar2 == 0) {
    local_38.style = 0;
    local_38.lpfnWndProc = FUN_405eda00;
    local_38.cbClsExtra = 0;
    local_38.cbWndExtra = 4;
    local_38.hIcon = (HICON)0x0;
    local_38.hInstance = param_1;
    local_38.hCursor = LoadCursorW((HINSTANCE)0x0,(LPCWSTR)0x7f00);
    local_38.hbrBackground = (HBRUSH)0x40000010;
    local_38.lpszMenuName = (LPCWSTR)0x0;
    local_38.lpszClassName = L"MSPreview";
    AVar1 = RegisterClassW(&local_38);
    if (CONCAT22(extraout_var,AVar1) == 0) {
      return 0;
    }
  }
  return 1;
}



/* 405edbcc FUN_405edbcc */

/* Boundary evidence: original MIPS .pdata 405edbcc..405edd37. Semantic name remains unreviewed. */

void FUN_405edbcc(HINSTANCE param_1)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  
  DAT_405fb8ac = LoadStringW(DAT_405fb7fc,0x8271,(LPWSTR)0x0,0);
  DAT_405fb8a8 = LoadStringW(DAT_405fb7fc,0x8272,(LPWSTR)0x0,0);
  DAT_405fb8a4 = LoadStringW(DAT_405fb7fc,0x8273,(LPWSTR)0x0,0);
  DAT_405fb8a0 = LoadStringW(DAT_405fb7fc,0x8274,(LPWSTR)0x0,0);
  DAT_405fb898 = LoadStringW(DAT_405fb7fc,0x8275,(LPWSTR)0x0,0);
  DAT_405fb89c = LoadStringW(DAT_405fb7fc,0x8276,(LPWSTR)0x0,0);
  DAT_405fb894 = LoadStringW(DAT_405fb7fc,0x8277,(LPWSTR)0x0,0);
  DAT_405fb890 = LoadStringW(DAT_405fb7fc,0x8278,(LPWSTR)0x0,0);
  piVar3 = &DAT_405fb81c;
  iVar2 = 0;
  do {
    iVar1 = LoadStringW(DAT_405fb7fc,iVar2 + 0x8300,(LPWSTR)0x0,0);
    *piVar3 = iVar1;
    piVar3 = piVar3 + 1;
    iVar2 = iVar2 + 1;
  } while ((int)piVar3 < 0x405fb888);
  FUN_405edb20(param_1);
  return;
}



/* 405edd38 FUN_405edd38 */

/* Boundary evidence: original MIPS .pdata 405edd38..405edf07. Semantic name remains unreviewed. */

void FUN_405edd38(HWND param_1)

{
  wchar_t *dwNewLong;
  int iVar1;
  HWND pHVar2;
  LRESULT LVar3;
  DWORD DVar4;
  wchar_t *pwVar5;
  uint uVar6;
  tagRECT local_28;
  
  dwNewLong = LocalAlloc(0x40,0x2e8);
  DAT_405fb8b0 = dwNewLong;
  SetWindowLongW(param_1,8,(LONG)dwNewLong);
  if ((dwNewLong != (wchar_t *)0x0) && (iVar1 = FUN_405edbcc(DAT_405fb7fc), iVar1 != 0)) {
    pHVar2 = GetDlgItem(param_1,0x256);
    GetWindowRect(pHVar2,&local_28);
    MapWindowPoints((HWND)0x0,param_1,(LPPOINT)&local_28,2);
    pHVar2 = CreateWindowExW(0,L"MSPreview",(LPCWSTR)0x0,0x50800000,local_28.left,local_28.top,
                             local_28.right - local_28.left,local_28.bottom - local_28.top,param_1,
                             (HMENU)0x24f,DAT_405fb7fc,(LPVOID)0x0);
    *(HWND *)(dwNewLong + 0x13e) = pHVar2;
    if (pHVar2 != (HWND)0x0) {
      iVar1 = FUN_405ebbd8(param_1,dwNewLong);
      if (iVar1 == 0) {
        FUN_405e94e8(param_1);
      }
      else {
        pHVar2 = GetDlgItem(param_1,0x250);
        LVar3 = SendMessageW(pHVar2,0x147,0,0);
        if (LVar3 == -1) {
          uVar6 = 0;
          pwVar5 = dwNewLong + 0x104;
          do {
            DVar4 = GetSysColor(uVar6 | 0x40000000);
            uVar6 = uVar6 + 1;
            *(DWORD *)pwVar5 = DVar4;
            pwVar5 = pwVar5 + 2;
          } while ((int)uVar6 < 0x1d);
          SendDlgItemMessageW(param_1,0x24f,0x401,0x1d,(LPARAM)(dwNewLong + 0x104));
          SendDlgItemMessageW(param_1,0x24f,0x400,0,0);
        }
        else {
          pHVar2 = GetDlgItem(param_1,0x250);
          FUN_405ec138(param_1,pHVar2);
        }
      }
    }
  }
  return;
}



/* 405edf08 ColSchemeDlgProc */

/* Boundary evidence: original MIPS .pdata 405edf08..405ee0eb. Semantic name remains unreviewed. */

undefined4 ColSchemeDlgProc(HWND param_1,int param_2,uint param_3,HWND param_4)

{
  HWND hWnd;
  uint uVar1;
  
                    /* 0xdf08  6  ColSchemeDlgProc */
  if ((param_2 == 0x110) || (DAT_405fb8b0 != 0)) {
    if (param_2 == 0x10) {
      FUN_405e94e8(param_1);
    }
    else {
      if (param_2 != 0x2b) {
        if (param_2 == 0x110) {
          FUN_405edd38(param_1);
          FUN_405f7378(param_1,8);
        }
        else {
          if (param_2 != 0x111) {
            return 0;
          }
          uVar1 = param_3 & 0xffff;
          if (uVar1 < 0x253) {
            if (uVar1 != 0x252) {
              if (uVar1 == 1) {
                FUN_405ec24c(param_1);
              }
              else if (uVar1 != 2) {
                if (uVar1 == 0x250) {
                  if (param_3 >> 0x10 != 8) {
                    return 0;
                  }
                  UpdateWindow(param_1);
                  FUN_405ec138(param_1,param_4);
                  return 1;
                }
                if (uVar1 != 0x251) {
                  return 0;
                }
                FUN_405eb574(param_1);
                return 1;
              }
              FUN_405e94e8(param_1);
              return 1;
            }
            FUN_405ec24c(param_1);
          }
          else {
            if (uVar1 == 0x253) {
              if (param_3 >> 0x10 != 1) {
                return 0;
              }
              hWnd = GetDlgItem(param_1,0x254);
              InvalidateRect(hWnd,(RECT *)0x0,0);
              return 1;
            }
            if (uVar1 == 0x254) {
              FUN_405ec2f4(param_1);
            }
            else {
              if (uVar1 != 0x29d) {
                return 0;
              }
              FUN_405eb73c(param_1);
            }
          }
        }
        return 1;
      }
      FUN_405eb8f8(param_1,(int)param_4);
    }
  }
  return 0;
}



/* 405ee0f4 ShowLineTranslateDlg */

/* Boundary evidence: original MIPS .pdata 405ee0f4..405ee157. Semantic name remains unreviewed. */

undefined4 ShowLineTranslateDlg(void)

{
  HLINEAPP local_10;
  DWORD DStack_c;
  
                    /* 0xe0f4  21  ShowLineTranslateDlg */
  local_10 = 0;
  lineInitialize(&local_10,DAT_405fb7fc,(LINECALLBACK)&LAB_405ee0ec,(LPCSTR)0x0,&DStack_c);
  lineTranslateDialog(local_10,0,0x10005,(HWND)0x0,(LPCSTR)0x0);
  lineShutdown(local_10);
  return 0;
}



/* 405ee158 FUN_405ee158 */

/* Boundary evidence: original MIPS .pdata 405ee158..405ee1eb. Semantic name remains unreviewed. */

void FUN_405ee158(HWND param_1,short *param_2)

{
  HWND pHVar1;
  wchar_t awStack_120 [132];
  uint local_18;
  
  local_18 = DAT_405fb760;
  if (*param_2 != 0) {
    pHVar1 = GetDlgItem(param_1,0x1a9);
    EnableWindow(pHVar1,1);
    StringCchPrintfW(awStack_120,0x83,L"\'%s\'",param_2);
    pHVar1 = GetDlgItem(param_1,0x1a9);
    SetWindowTextW(pHVar1,awStack_120);
  }
  FUN_405f9bec(local_18);
  return;
}



/* 405ee1ec FUN_405ee1ec */

/* Boundary evidence: original MIPS .pdata 405ee1ec..405ee26f. Semantic name remains unreviewed. */

void FUN_405ee1ec(HWND param_1,wchar_t *param_2)

{
  UINT UVar1;
  size_t sVar2;
  WCHAR aWStack_112 [2];
  wchar_t awStack_10e [127];
  uint local_10;
  
  local_10 = DAT_405fb760;
  UVar1 = GetDlgItemTextW(param_1,0x1a9,aWStack_112 + 1,0x80);
  if (UVar1 != 0) {
    sVar2 = wcslen(aWStack_112 + 1);
    if ((int)sVar2 < 1) {
      *param_2 = L'\0';
    }
    else {
      aWStack_112[sVar2] = L'\0';
      wcscpy(param_2,awStack_10e);
    }
  }
  FUN_405f9bec(local_10);
  return;
}



/* 405ee270 FUN_405ee270 */

/* Boundary evidence: original MIPS .pdata 405ee270..405ee303. Semantic name remains unreviewed. */

void FUN_405ee270(HWND param_1)

{
  HWND pHVar1;
  LRESULT bEnable;
  uint uVar2;
  
  pHVar1 = GetDlgItem(param_1,0x1a8);
  bEnable = SendMessageW(pHVar1,0xf0,0,0);
  uVar2 = 0;
  do {
    pHVar1 = GetDlgItem(param_1,*(int *)((int)&DAT_405e304c + uVar2));
    EnableWindow(pHVar1,bEnable);
    uVar2 = uVar2 + 4;
  } while (uVar2 < 0x10);
  return;
}



/* 405ee304 FUN_405ee304 */

/* WARNING: Type propagation algorithm not settling */
/* Boundary evidence: original MIPS .pdata 405ee304..405ee457. Semantic name remains unreviewed. */

void FUN_405ee304(HWND param_1)

{
  HLOCAL hMem;
  int iVar1;
  int iVar2;
  uint uVar3;
  SIZE_T local_dc0;
  uint local_dbc [474];
  WCHAR aWStack_654 [790];
  uint local_28;
  
  local_28 = DAT_405fb760;
  RasEnumEntries(0,0,0,&local_dc0,0);
  if (local_dc0 != 0) {
    hMem = LocalAlloc(0x40,local_dc0);
    if (hMem != (HLOCAL)0x0) {
      iVar1 = RasEnumEntries(0,0,hMem,&local_dc0,local_dbc);
      if ((iVar1 == 0) && (uVar3 = 0, local_dbc[0] != 0)) {
        iVar1 = (int)hMem + 4;
        do {
          local_dc0 = 0xd90;
          local_dbc[1] = 0xd90;
          iVar2 = RasGetEntryProperties(0,iVar1,local_dbc + 1,&local_dc0,0,0);
          if ((iVar2 == 0) && (iVar2 = lstrcmpW(aWStack_654,L"direct"), iVar2 == 0)) {
            SendMessageW(param_1,0x143,0,iVar1);
          }
          uVar3 = uVar3 + 1;
          iVar1 = iVar1 + 0x30;
        } while (uVar3 < local_dbc[0]);
      }
    }
    LocalFree(hMem);
  }
  FUN_405f9bec(local_28);
  return;
}



/* 405ee458 FUN_405ee458 */

/* Boundary evidence: original MIPS .pdata 405ee458..405ee4c3. Semantic name remains unreviewed. */

wchar_t * FUN_405ee458(wchar_t *param_1)

{
  size_t sVar1;
  wchar_t *_Dest;
  
  if (param_1 == (wchar_t *)0x0) {
    _Dest = (wchar_t *)0x0;
  }
  else {
    sVar1 = wcslen(param_1);
    _Dest = LocalAlloc(0x40,(sVar1 + 1) * 2);
    if (_Dest != (wchar_t *)0x0) {
      wcscpy(_Dest,param_1);
    }
  }
  return _Dest;
}



/* 405ee4c4 FUN_405ee4c4 */

/* Boundary evidence: original MIPS .pdata 405ee4c4..405ee6a7. Semantic name remains unreviewed. */

undefined4 FUN_405ee4c4(HWND param_1,int param_2,short param_3,LPARAM param_4)

{
  HWND pHVar1;
  WPARAM WVar2;
  LRESULT LVar3;
  HCURSOR pHVar4;
  wchar_t *nResult;
  wchar_t awStack_120 [130];
  uint local_1c;
  
  local_1c = DAT_405fb760;
  if (param_2 == 0x53) {
    CreateProcessW(L"peghelp",L"file:ctpnl.htm#adjust_pc_connection_settings",
                   (LPSECURITY_ATTRIBUTES)0x0,(LPSECURITY_ATTRIBUTES)0x0,0,0,(LPVOID)0x0,
                   (LPCWSTR)0x0,(LPSTARTUPINFOW)0x0,(LPPROCESS_INFORMATION)0x0);
LAB_405ee67c:
    FUN_405f9bec(local_1c);
    return 0;
  }
  if (param_2 == 0x110) {
    FUN_405f7658(param_1,1);
    pHVar1 = GetDlgItem(param_1,0x1ab);
    pHVar4 = LoadCursorW((HINSTANCE)0x0,(LPCWSTR)0x7f02);
    pHVar4 = SetCursor(pHVar4);
    FUN_405ee304(pHVar1);
    WVar2 = SendMessageW(pHVar1,0x14c,0xffffffff,param_4);
    if (WVar2 == 0xffffffff) {
      WVar2 = 0;
    }
    SendMessageW(pHVar1,0x14e,WVar2,0);
    SetCursor(pHVar4);
    SetFocus(pHVar1);
    FUN_405f7378(param_1,8);
    goto LAB_405ee67c;
  }
  if (param_2 != 0x111) goto LAB_405ee67c;
  if (param_3 == 1) {
    pHVar1 = GetDlgItem(param_1,0x1ab);
    WVar2 = SendMessageW(pHVar1,0x147,0,0);
    if ((WVar2 != 0xffffffff) &&
       (LVar3 = SendMessageW(pHVar1,0x148,WVar2,(LPARAM)awStack_120), 0 < LVar3)) {
      nResult = FUN_405ee458(awStack_120);
      goto LAB_405ee594;
    }
  }
  else if (param_3 != 2) goto LAB_405ee67c;
  nResult = (wchar_t *)0x0;
LAB_405ee594:
  EndDialog(param_1,(INT_PTR)nResult);
  FUN_405f9bec(local_1c);
  return 1;
}



/* 405ee6a8 CommRASDlgProc */

/* Boundary evidence: original MIPS .pdata 405ee6a8..405ee937. Semantic name remains unreviewed. */

undefined4 CommRASDlgProc(HWND param_1,int param_2,short param_3)

{
  HRSRC hResInfo;
  LPCDLGTEMPLATEW hDialogTemplate;
  short *hMem;
  HWND pHVar1;
  LRESULT LVar2;
  int iVar3;
  WPARAM wParam;
  HKEY local_128;
  undefined4 local_124;
  undefined4 local_120;
  wchar_t awStack_118 [130];
  uint local_14;
  
                    /* 0xe6a8  7  CommRASDlgProc */
  local_14 = DAT_405fb760;
  local_128 = (HKEY)0x0;
  local_124 = 0;
  local_120 = 0;
  if (param_2 == 0x110) {
    FUN_405f83f4(param_1,0x1a5,0x8018);
    RegOpenKeyExW((HKEY)0x80000001,L"ControlPanel\\Comm",0,0x20019,&local_128);
    iVar3 = FUN_405e9984(&local_128,L"Cnct",(LPBYTE)awStack_118,0x81);
    if (iVar3 != 0) {
      FUN_405ee158(param_1,awStack_118);
    }
    wParam = FUN_405e4194(&local_128,L"AutoCnct",0);
    pHVar1 = GetDlgItem(param_1,0x1a8);
    SendMessageW(pHVar1,0xf1,wParam,0);
    pHVar1 = GetDlgItem(param_1,0x1a8);
    SetFocus(pHVar1);
    FUN_405ee270(param_1);
    FUN_405f7378(param_1,8);
  }
  else if (param_2 == 0x111) {
    if (param_3 == 1) {
      FUN_405ee1ec(param_1,awStack_118);
      pHVar1 = GetDlgItem(param_1,0x1a8);
      LVar2 = SendMessageW(pHVar1,0xf0,0,0);
      FUN_405e3f58(&local_128,(HKEY)0x80000001,L"ControlPanel\\Comm");
      FUN_405e424c(&local_128,L"Cnct",awStack_118);
      FUN_405e4618(&local_128,L"AutoCnct",LVar2);
    }
    else {
      if (param_3 != 0x1a8) {
        if (param_3 != 0x1aa) goto LAB_405ee908;
        FUN_405ee1ec(param_1,awStack_118);
        hResInfo = FindResourceW(DAT_405fb7fc,(LPCWSTR)0x1a10,(LPCWSTR)0x5);
        hDialogTemplate = LoadResource(DAT_405fb7fc,hResInfo);
        hMem = (short *)DialogBoxIndirectParamW
                                  (DAT_405fb7fc,hDialogTemplate,param_1,FUN_405ee4c4,
                                   (LPARAM)awStack_118);
        if ((hMem != (short *)0x0) && (hMem != (short *)0xffffffff)) {
          FUN_405ee158(param_1,hMem);
          LocalFree(hMem);
        }
      }
      FUN_405ee270(param_1);
    }
    FUN_405e4020(&local_128);
    FUN_405f9bec(local_14);
    return 1;
  }
LAB_405ee908:
  FUN_405e4020(&local_128);
  FUN_405f9bec(local_14);
  return 0;
}



/* 405ee938 CopyrightsDlgProc */

/* Boundary evidence: original MIPS .pdata 405ee938..405eeba3. Semantic name remains unreviewed. */

undefined4 CopyrightsDlgProc(HWND param_1,int param_2,short param_3)

{
  HANDLE hFile;
  uint uVar1;
  LPCSTR lpMultiByteStr;
  HWND hWnd;
  BOOL BVar2;
  LPWSTR lpWideCharStr;
  undefined4 uVar3;
  uint nNumberOfBytesToRead;
  DWORD local_60;
  HWND local_5c;
  WCHAR aWStack_58 [22];
  uint local_2c;
  
                    /* 0xe938  8  CopyrightsDlgProc */
  local_2c = DAT_405fb760;
  local_5c = param_1;
  memcpy(aWStack_58,L"\\windows\\copyrts.txt",0x2a);
  local_60 = 0;
  if (param_2 == 0x110) {
    hFile = CreateFileW(aWStack_58,0x80000000,0,(LPSECURITY_ATTRIBUTES)0x0,3,0x80,(HANDLE)0x0);
    if (hFile != (HANDLE)0xffffffff) {
      uVar1 = GetFileSize(hFile,(LPDWORD)0x0);
      if (uVar1 != 0xffffffff) {
        lpMultiByteStr = LocalAlloc(0x40,0x400);
        hWnd = GetDlgItem(param_1,0x234);
        if (lpMultiByteStr != (LPCSTR)0x0) {
          while (uVar1 != 0) {
            nNumberOfBytesToRead = uVar1;
            if (0x3fe < uVar1) {
              nNumberOfBytesToRead = 0x3ff;
            }
            local_60 = 0;
            BVar2 = ReadFile(hFile,lpMultiByteStr,nNumberOfBytesToRead,&local_60,(LPOVERLAPPED)0x0);
            param_1 = local_5c;
            if ((BVar2 == 0) || (nNumberOfBytesToRead != local_60)) break;
            lpWideCharStr = LocalAlloc(0x40,nNumberOfBytesToRead * 2 + 2);
            param_1 = local_5c;
            if (lpWideCharStr != (LPWSTR)0x0) {
              MultiByteToWideChar(0,0,lpMultiByteStr,nNumberOfBytesToRead,lpWideCharStr,
                                  nNumberOfBytesToRead + 1);
              lpWideCharStr[nNumberOfBytesToRead] = L'\0';
              SendMessageW(hWnd,0xb1,0xffffffff,-1);
              SendMessageW(hWnd,0xc2,0,(LPARAM)lpWideCharStr);
              uVar1 = uVar1 - nNumberOfBytesToRead;
              LocalFree(lpWideCharStr);
              param_1 = local_5c;
            }
          }
          LocalFree(lpMultiByteStr);
        }
      }
      CloseHandle(hFile);
    }
    FUN_405f7378(param_1,8);
    FUN_405f9bec(local_2c);
    uVar3 = 1;
  }
  else if ((param_2 == 0x111) && (uVar3 = 1, param_3 == 1)) {
    FUN_405f9bec(local_2c);
  }
  else {
    FUN_405f9bec(local_2c);
    uVar3 = 0;
  }
  return uVar3;
}



/* 405eeba4 FUN_405eeba4 */

/* Boundary evidence: original MIPS .pdata 405eeba4..405eebf3. Semantic name remains unreviewed. */

void FUN_405eeba4(int param_1)

{
  if (*(int *)(param_1 + 0x15c) == 0) {
    SetTimer(*(HWND *)(param_1 + 0x158),1,1000,(TIMERPROC)0x0);
    *(undefined4 *)(param_1 + 0x15c) = 1;
  }
  return;
}



/* 405eebf4 FUN_405eebf4 */

/* Boundary evidence: original MIPS .pdata 405eebf4..405eeceb. Semantic name remains unreviewed. */

void FUN_405eebf4(undefined4 param_1,HWND param_2)

{
  _FILETIME local_28;
  SYSTEMTIME SStack_20;
  
  local_28.dwLowDateTime = 0;
  local_28.dwHighDateTime = 0;
  SendMessageW(param_2,0x100d,0,(LPARAM)&SStack_20);
  SystemTimeToFileTime(&SStack_20,&local_28);
  local_28.dwHighDateTime =
       local_28.dwHighDateTime + 0xc9 +
       (uint)(local_28.dwLowDateTime + 0x2a69c000 < local_28.dwLowDateTime);
  local_28.dwLowDateTime = local_28.dwLowDateTime + 0x2a69c000;
  FileTimeToSystemTime(&local_28,&SStack_20);
  SendMessageW(param_2,0x100c,0,(LPARAM)&SStack_20);
  SendMessageW(param_2,0x1001,0,(LPARAM)&SStack_20);
  SystemTimeToFileTime(&SStack_20,&local_28);
  local_28.dwHighDateTime =
       local_28.dwHighDateTime + 0xc9 +
       (uint)(local_28.dwLowDateTime + 0x2a69c000 < local_28.dwLowDateTime);
  local_28.dwLowDateTime = local_28.dwLowDateTime + 0x2a69c000;
  FileTimeToSystemTime(&local_28,&SStack_20);
  SendMessageW(param_2,0x1002,0,(LPARAM)&SStack_20);
  return;
}



/* 405eecec FUN_405eecec */

/* Boundary evidence: original MIPS .pdata 405eecec..405eed77. Semantic name remains unreviewed. */

void FUN_405eecec(HWND param_1,UINT param_2,WPARAM param_3,LONG *param_4)

{
  POINT Point;
  HWND hWndTo;
  tagPOINT local_10;
  
  if (param_2 == 0x410) {
    local_10.x = *param_4;
    local_10.y = param_4[1];
    hWndTo = (HWND)GetWindowLongW(param_1,-0x15);
    MapWindowPoints((HWND)0x0,hWndTo,&local_10,1);
    Point.y = local_10.y;
    Point.x = local_10.x;
    ChildWindowFromPoint(hWndTo,Point);
  }
  else {
    CallWindowProcW(DAT_405fb8bc,param_1,param_2,param_3,(LPARAM)param_4);
  }
  return;
}



/* 405eed78 FUN_405eed78 */

/* Boundary evidence: original MIPS .pdata 405eed78..405eedd3. Semantic name remains unreviewed. */

void * FUN_405eed78(void *param_1,uint param_2)

{
  if (*(int *)((int)param_1 + 0x15c) != 0) {
    KillTimer(*(HWND *)((int)param_1 + 0x158),1);
    *(undefined4 *)((int)param_1 + 0x15c) = 0;
  }
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}



/* 405eedd4 FUN_405eedd4 */

/* Boundary evidence: original MIPS .pdata 405eedd4..405ef09f. Semantic name remains unreviewed. */

void FUN_405eedd4(LPTIME_ZONE_INFORMATION param_1,HWND param_2)

{
  HWND pHVar1;
  DWORD DVar2;
  WPARAM wParam;
  int iVar3;
  LSTATUS LVar4;
  wchar_t *_Source;
  BOOL bEnable;
  HKEY local_178;
  undefined4 local_174;
  undefined4 local_170;
  HKEY local_168 [4];
  HKEY apHStack_158 [4];
  undefined1 auStack_148 [16];
  WCHAR aWStack_138 [64];
  wchar_t awStack_b8 [70];
  uint local_2c;
  
  local_2c = DAT_405fb760;
  param_1[2].Bias = (LONG)param_2;
  pHVar1 = GetDlgItem(param_2,0x2f2);
  EnableWindow(pHVar1,0);
  DVar2 = GetTimeZoneInformation(param_1);
  bEnable = 1;
  *(uint *)(param_1[2].StandardName + 2) = (uint)(DVar2 == 2);
  FUN_405e3fc4(apHStack_158,(HKEY)0x80000002,L"Software\\Microsoft\\Clock");
  wParam = FUN_405e4194(apHStack_158,L"AutoDST",0);
  pHVar1 = GetDlgItem(param_2,0x2f3);
  SendMessageW(pHVar1,0xf1,wParam,0);
  if (((param_1->DaylightDate).wMonth == 0) || (param_1->DaylightBias == 0)) {
    bEnable = 0;
  }
  pHVar1 = GetDlgItem(param_2,0x2f3);
  EnableWindow(pHVar1,bEnable);
  pHVar1 = GetDlgItem(param_2,0x2f0);
  FUN_405e3fc4(local_168,(HKEY)0x80000002,L"Time Zones");
  local_178 = (HKEY)0x0;
  local_174 = 0;
  local_170 = 0;
  iVar3 = FUN_405e991c(local_168,aWStack_138,0x40);
  while (iVar3 != 0) {
    FUN_405e98c0(&local_178);
    LVar4 = RegOpenKeyExW(local_168[0],aWStack_138,0,0x20019,&local_178);
    if (LVar4 == 0) {
      _Source = (wchar_t *)FUN_405f7da0(&local_178,L"Display");
      FUN_405e9984(&local_178,L"Std",(LPBYTE)aWStack_138,0x40);
      if ((_Source != (wchar_t *)0x0) &&
         (iVar3 = lstrcmpW(aWStack_138,param_1->StandardName), iVar3 == 0)) {
        wcscpy(awStack_b8,_Source);
      }
      SendMessageW(pHVar1,0x143,0,(LPARAM)_Source);
    }
    iVar3 = FUN_405e991c(local_168,aWStack_138,0x40);
  }
  SendMessageW(pHVar1,0x14d,0,(LPARAM)awStack_b8);
  SetFocus(pHVar1);
  memcpy(param_1 + 1,param_1,0xac);
  pHVar1 = GetDlgItem(param_2,0x2ef);
  SendMessageW(pHVar1,0x1001,0,(LPARAM)auStack_148);
  pHVar1 = GetDlgItem(param_2,0x2ef);
  SendMessageW(pHVar1,0x100c,0,(LPARAM)auStack_148);
  FUN_405e4020(&local_178);
  FUN_405e4020(local_168);
  FUN_405e4020(apHStack_158);
  FUN_405f9bec(local_2c);
  return;
}



/* 405ef0a0 FUN_405ef0a0 */

/* Boundary evidence: original MIPS .pdata 405ef0a0..405ef2df. Semantic name remains unreviewed. */

void FUN_405ef0a0(int param_1)

{
  HWND pHVar1;
  WPARAM wParam;
  int iVar2;
  LSTATUS LVar3;
  LPCWSTR lpString2;
  undefined4 *puVar4;
  BOOL bEnable;
  HKEY local_150;
  undefined4 local_14c;
  undefined4 local_148;
  HKEY local_140 [4];
  WCHAR aWStack_130 [64];
  WCHAR aWStack_b0 [70];
  uint local_24;
  
  local_24 = DAT_405fb760;
  pHVar1 = GetDlgItem(*(HWND *)(param_1 + 0x158),0x2f0);
  wParam = SendMessageW(pHVar1,0x147,0,0);
  SendMessageW(pHVar1,0x148,wParam,(LPARAM)aWStack_b0);
  FUN_405e3fc4(local_140,(HKEY)0x80000002,L"Time Zones");
  local_150 = (HKEY)0x0;
  local_14c = 0;
  local_148 = 0;
  iVar2 = FUN_405e991c(local_140,aWStack_130,0x40);
  do {
    if (iVar2 == 0) {
LAB_405ef254:
      if ((*(short *)(param_1 + 0x146) == 0) || (bEnable = 1, *(int *)(param_1 + 0x154) == 0)) {
        bEnable = 0;
      }
      pHVar1 = GetDlgItem(*(HWND *)(param_1 + 0x158),0x2f3);
      EnableWindow(pHVar1,bEnable);
      pHVar1 = GetDlgItem(*(HWND *)(param_1 + 0x158),0x2f2);
      EnableWindow(pHVar1,1);
      *(undefined4 *)(param_1 + 0x164) = 1;
      FUN_405e4020(&local_150);
      FUN_405e4020(local_140);
      FUN_405f9bec(local_24);
      return;
    }
    FUN_405e98c0(&local_150);
    LVar3 = RegOpenKeyExW(local_140[0],aWStack_130,0,0x20019,&local_150);
    if (LVar3 == 0) {
      lpString2 = (LPCWSTR)FUN_405f7da0(&local_150,L"Display");
      iVar2 = lstrcmpW(aWStack_b0,lpString2);
      if ((iVar2 == 0) &&
         (puVar4 = (undefined4 *)FUN_405f7da0(&local_150,L"TZI"), puVar4 != (undefined4 *)0x0)) {
        *(undefined4 *)(param_1 + 0xac) = *puVar4;
        *(undefined4 *)(param_1 + 0x100) = puVar4[1];
        *(undefined4 *)(param_1 + 0x154) = puVar4[2];
        memcpy((void *)(param_1 + 0xf0),puVar4 + 3,0x10);
        memcpy((void *)(param_1 + 0x144),puVar4 + 7,0x10);
        FUN_405e9984(&local_150,L"Dlt",(LPBYTE)(param_1 + 0x104),0x20);
        FUN_405e9984(&local_150,L"Std",(LPBYTE)(param_1 + 0xb0),0x20);
        goto LAB_405ef254;
      }
    }
    iVar2 = FUN_405e991c(local_140,aWStack_130,0x40);
  } while( true );
}



/* 405ef2e0 FUN_405ef2e0 */

/* Boundary evidence: original MIPS .pdata 405ef2e0..405ef4bf. Semantic name remains unreviewed. */

undefined4 FUN_405ef2e0(int *param_1,SYSTEMTIME *param_2)

{
  uint uVar1;
  HWND hWnd;
  LRESULT LVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  undefined4 uVar9;
  TIME_ZONE_INFORMATION *lpTimeZoneInformation;
  int iVar10;
  _FILETIME local_50;
  FILETIME local_48;
  HKEY apHStack_40 [4];
  _SYSTEMTIME _Stack_30;
  longlong lVar2;
  
  uVar9 = 0;
  hWnd = GetDlgItem((HWND)param_1[0x56],0x2f3);
  LVar3 = SendMessageW(hWnd,0xf0,0,0);
  if (((LVar3 == 0) || (*(short *)((int)param_1 + 0x146) == 0)) || (iVar10 = 1, param_1[0x55] == 0))
  {
    iVar10 = 0;
  }
  if (param_1[0x59] != 0) {
    if (param_1[0x58] == 0) {
      iVar7 = param_1[0x15];
    }
    else {
      iVar7 = param_1[0x2a];
    }
    iVar5 = *param_1;
    if (param_1[0x58] == 0) {
      iVar8 = param_1[0x40];
    }
    else {
      iVar8 = param_1[0x55];
    }
    lpTimeZoneInformation = (TIME_ZONE_INFORMATION *)(param_1 + 0x2b);
    iVar6 = lpTimeZoneInformation->Bias;
    local_50.dwLowDateTime = 0;
    local_50.dwHighDateTime = 0;
    local_48.dwLowDateTime = 0;
    local_48.dwHighDateTime = 0;
    SystemTimeToFileTime(param_2,&local_50);
    uVar4 = (iVar5 + iVar7) - (iVar6 + iVar8);
    lVar2 = (ulonglong)uVar4 * 600000000;
    uVar1 = (uint)lVar2;
    local_48.dwLowDateTime = uVar1 + local_50.dwLowDateTime;
    local_48.dwHighDateTime =
         ((int)uVar4 >> 0x1f) * 600000000 + (int)((ulonglong)lVar2 >> 0x20) +
         local_50.dwHighDateTime + (uint)(local_48.dwLowDateTime < uVar1);
    FileTimeToSystemTime(&local_48,&_Stack_30);
    SetLocalTime(&_Stack_30);
    SetTimeZoneInformation(lpTimeZoneInformation);
    memcpy(param_1,lpTimeZoneInformation,0xac);
    param_1[0x59] = 0;
    if ((*(short *)((int)param_1 + 0x146) == 0) || (param_1[0x55] == 0)) {
      iVar10 = 0;
      param_1[0x58] = 0;
    }
    else {
      param_1[0x58] = iVar10;
    }
    uVar9 = 1;
  }
  FUN_405e3fc4(apHStack_40,(HKEY)0x80000002,L"Software\\Microsoft\\Clock");
  FUN_405e4618(apHStack_40,L"AutoDST",iVar10);
  SetTimeZoneInformation((TIME_ZONE_INFORMATION *)(param_1 + 0x2b));
  FUN_405e4020(apHStack_40);
  return uVar9;
}



/* 405ef4c0 FUN_405ef4c0 */

/* Boundary evidence: original MIPS .pdata 405ef4c0..405ef5d3. Semantic name remains unreviewed. */

void FUN_405ef4c0(int *param_1)

{
  HWND pHVar1;
  int iVar2;
  SYSTEMTIME local_28;
  WORD local_18;
  WORD local_16;
  WORD local_14;
  WORD local_12;
  
  pHVar1 = GetDlgItem((HWND)param_1[0x56],0x2ee);
  SendMessageW(pHVar1,0x1001,0,(LPARAM)&local_28);
  pHVar1 = GetDlgItem((HWND)param_1[0x56],0x2ef);
  SendMessageW(pHVar1,0x1001,0,(LPARAM)&local_18);
  local_28.wYear = local_18;
  local_28.wDayOfWeek = local_14;
  local_28.wDay = local_12;
  local_28.wMonth = local_16;
  iVar2 = FUN_405ef2e0(param_1,&local_28);
  if ((iVar2 == 0) && (param_1[0x5a] != 0)) {
    SetLocalTime(&local_28);
  }
  GetLocalTime(&local_28);
  pHVar1 = GetDlgItem((HWND)param_1[0x56],0x2ee);
  SendMessageW(pHVar1,0x1002,0,(LPARAM)&local_28);
  pHVar1 = GetDlgItem((HWND)param_1[0x56],0x2ef);
  SendMessageW(pHVar1,0x100c,0,(LPARAM)&local_28);
  pHVar1 = GetDlgItem((HWND)param_1[0x56],0x2ef);
  SendMessageW(pHVar1,0x1002,0,(LPARAM)&local_28);
  param_1[0x5a] = 0;
  return;
}



/* 405ef5d4 DateTimeDlgProc */

/* Boundary evidence: original MIPS .pdata 405ef5d4..405efcc7. Semantic name remains unreviewed. */

undefined4 DateTimeDlgProc(HWND param_1,UINT param_2,uint param_3,int param_4)

{
  int *piVar1;
  HWND pHVar2;
  LPTIME_ZONE_INFORMATION _Dst;
  HMONITOR pHVar3;
  HDC hdc;
  LRESULT cchString;
  LPCWSTR lpszString;
  uint uVar4;
  BOOL BVar5;
  uint uVar6;
  int iVar7;
  undefined4 uVar8;
  tagRECT local_d8;
  tagSIZE local_c8;
  undefined4 local_c0;
  int local_bc;
  HWND local_b8;
  HWND local_b4;
  int local_a4;
  undefined4 local_9c;
  HWND local_94;
  HKEY apHStack_88 [4];
  _SYSTEMTIME _Stack_78;
  tagRECT local_68;
  undefined4 local_58;
  int local_54;
  int local_50;
  
                    /* 0xf5d4  9  DateTimeDlgProc */
  piVar1 = (int *)GetWindowLongW(param_1,8);
  FUN_405e3fc4(apHStack_88,(HKEY)0x80000002,L"Software\\Microsoft\\Clock");
  if ((param_2 != 0x110) && (piVar1 == (int *)0x0)) {
    uVar8 = 0;
    goto LAB_405efc98;
  }
  if (param_2 == 2) {
    uVar8 = 1;
    if (piVar1 != (int *)0x0) {
      FUN_405eed78(piVar1,1);
    }
    goto LAB_405efc98;
  }
  if ((param_2 == 0x15) || (param_2 == 0x1a)) {
    pHVar2 = GetDlgItem(param_1,0x2ee);
    SendMessageW(pHVar2,param_2,param_3,param_4);
    pHVar2 = GetDlgItem(param_1,0x2ef);
    SendMessageW(pHVar2,param_2,param_3,param_4);
LAB_405efc7c:
    uVar8 = 1;
  }
  else {
    if (param_2 == 0x4e) {
      iVar7 = *(int *)(param_4 + 8);
      if (iVar7 == -0x2f7) {
        uVar8 = 1;
        if (piVar1[0x57] != 0) {
          KillTimer((HWND)piVar1[0x56],1);
          piVar1[0x57] = 0;
        }
        pHVar2 = GetDlgItem(param_1,0x2f2);
        EnableWindow(pHVar2,1);
        piVar1[0x5a] = 1;
        goto LAB_405efc98;
      }
      if (iVar7 != -0x2ed) {
        if (iVar7 != -0x212) {
          if (iVar7 != -0x209) goto LAB_405ef968;
          pHVar2 = *(HWND *)(param_4 + 4);
          memset(&local_54,0,0x30);
          local_58 = 0x34;
          SendMessageW(pHVar2,0x162,0,(LPARAM)&local_58);
          local_d8.left = 0;
          memset(&local_d8.top,0,0xc);
          GetWindowRect(pHVar2,&local_d8);
          local_68.left = 0;
          memset(&local_68.top,0,0xc);
          GetWindowRect(DAT_405fb8b8,&local_68);
          iVar7 = local_68.right - local_68.left;
          pHVar3 = MonitorFromWindow(pHVar2,2);
          if (pHVar3 != (HMONITOR)0x0) {
            memset(&local_bc,0,0x24);
            local_c0 = 0x28;
            GetMonitorInfo(pHVar3,&local_c0);
            local_d8.left = local_54 + local_d8.left;
            local_d8.top = local_d8.top + local_50;
            if (local_a4 < iVar7 + local_d8.left) {
              local_d8.left = local_a4 - iVar7;
            }
          }
          SetWindowPos(DAT_405fb8b8,(HWND)0x0,local_d8.left,local_d8.top,0,0,0x15);
          uVar8 = 1;
          SetWindowLongW(param_1,0,1);
          goto LAB_405efc98;
        }
        memset(&local_bc,0,0x30);
        local_c8.cx = 0;
        memset(&local_c8.cy,0,4);
        local_c0 = 0x34;
        SendMessageW(*(HWND *)(param_4 + 4),0x162,0,(LPARAM)&local_c0);
        hdc = GetDC(local_94);
        if (hdc != (HDC)0x0) {
          cchString = SendMessageW(local_94,0xe,0,0);
          if (cchString != 0) {
            uVar6 = cchString + 1;
            if (uVar6 < 0x80000000) {
              uVar4 = uVar6 * 2;
            }
            else {
              uVar4 = 0xffffffff;
            }
            lpszString = operator_new(uVar4);
            if (lpszString != (LPCWSTR)0x0) {
              SendMessageW(local_94,0xd,uVar6,(LPARAM)lpszString);
              BVar5 = GetTextExtentExPointW
                                (hdc,lpszString,cchString,0,(LPINT)0x0,(LPINT)0x0,&local_c8);
              if ((BVar5 != 0) && ((int)local_b4 - local_bc <= local_c8.cx)) {
                memset((wchar_t *)(param_4 + 0x10),0,0xa0);
                wcsncpy((wchar_t *)(param_4 + 0x10),lpszString,0x4f);
              }
              operator_delete(lpszString);
            }
          }
          ReleaseDC(local_94,hdc);
        }
        goto LAB_405efc7c;
      }
      piVar1[0x5a] = 1;
LAB_405ef748:
      pHVar2 = GetDlgItem(param_1,0x2f2);
      BVar5 = 1;
    }
    else {
      if (param_2 == 0x110) {
        _Dst = operator_new(0x16c);
        if (_Dst == (LPTIME_ZONE_INFORMATION)0x0) {
          _Dst = (LPTIME_ZONE_INFORMATION)0x0;
        }
        else {
          memset(_Dst,0,0x16c);
        }
        if (_Dst != (LPTIME_ZONE_INFORMATION)0x0) {
          SetWindowLongW(param_1,8,(LONG)_Dst);
          FUN_405eedd4(_Dst,param_1);
          FUN_405eeba4((int)_Dst);
          DAT_405fb8b8 = CreateWindowExW(8,L"tooltips_class32",(LPCWSTR)0x0,0x80000003,-0x80000000,
                                         -0x80000000,-0x80000000,-0x80000000,param_1,(HMENU)0x0,
                                         DAT_405fb7fc,(LPVOID)0x0);
          if (DAT_405fb8b8 != (HWND)0x0) {
            memset(&local_bc,0,0x28);
            local_c0 = 0x2c;
            local_bc = 0x111;
            local_9c = 0xffffffff;
            local_b8 = param_1;
            local_b4 = GetDlgItem(param_1,0x2f0);
            SendMessageW(DAT_405fb8b8,0x432,0,(LPARAM)&local_c0);
            DAT_405fb8bc = SetWindowLongW(DAT_405fb8b8,-4,0x405eecec);
            SetWindowLongW(DAT_405fb8b8,-0x15,(LONG)param_1);
          }
          pHVar2 = GetDlgItem(param_1,0x2ee);
          ImmAssociateContext(pHVar2,(HIMC)0x0);
        }
        FUN_405f7378(param_1,8);
        goto LAB_405efc7c;
      }
      if (param_2 != 0x111) {
        if ((param_2 != 0x113) || (uVar8 = 1, param_3 != 1)) {
LAB_405ef968:
          FUN_405e4020(apHStack_88);
          return 0;
        }
        GetLocalTime(&_Stack_78);
        if (((_Stack_78.wHour == 0) && (_Stack_78.wMinute == 0)) && (_Stack_78.wSecond == 0)) {
          pHVar2 = GetDlgItem(param_1,0x2ef);
          FUN_405eebf4(piVar1,pHVar2);
        }
        pHVar2 = GetDlgItem(param_1,0x2ee);
        SendMessageW(pHVar2,0x1002,0,(LPARAM)&_Stack_78);
        goto LAB_405efc98;
      }
      uVar6 = param_3 & 0xffff;
      uVar8 = 1;
      if (uVar6 == 1) {
        FUN_405ef4c0(piVar1);
        goto LAB_405efc98;
      }
      if (uVar6 == 0x2f0) {
        if (param_3 >> 0x10 == 1) {
          FUN_405ef0a0((int)piVar1);
        }
        goto LAB_405efc98;
      }
      if (uVar6 != 0x2f2) {
        if (uVar6 != 0x2f3) goto LAB_405ef968;
        goto LAB_405ef748;
      }
      FUN_405ef4c0(piVar1);
      FUN_405eeba4((int)piVar1);
      pHVar2 = GetDlgItem(param_1,0x2ef);
      SetFocus(pHVar2);
      pHVar2 = GetDlgItem(param_1,0x2f2);
      BVar5 = 0;
    }
    uVar8 = 1;
    EnableWindow(pHVar2,BVar5);
  }
LAB_405efc98:
  FUN_405e4020(apHStack_88);
  return uVar8;
}



/* 405efcc8 FUN_405efcc8 */

/* Boundary evidence: original MIPS .pdata 405efcc8..405eff0b. Semantic name remains unreviewed. */

void FUN_405efcc8(HWND param_1,int param_2)

{
  HWND hWnd;
  HWND hWnd_00;
  int iVar1;
  int iVar2;
  
  hWnd = GetDlgItem(param_1,0x1bd);
  hWnd_00 = GetDlgItem(param_1,0x1c4);
  iVar2 = *(int *)(param_2 + 0xc);
  if (iVar2 == 0) {
    trap(0x1c00);
  }
  if ((iVar2 == -1) && (*(int *)(param_2 + 0x18) == -0x80000000)) {
    trap(0x1800);
  }
  if (iVar2 == 0) {
    trap(0x1c00);
  }
  if ((iVar2 == -1) && (*(int *)(param_2 + 0x14) == -0x80000000)) {
    trap(0x1800);
  }
  SendMessageW(hWnd,0x406,1,
               *(int *)(param_2 + 0x18) / iVar2 << 0x10 | *(int *)(param_2 + 0x14) / iVar2 & 0xffffU
              );
  SendMessageW(hWnd,0x414,1,0);
  SendMessageW(hWnd,0x415,0,3);
  iVar2 = *(int *)(param_2 + 0x10);
  if (iVar2 == 0) {
    trap(0x1c00);
  }
  if ((iVar2 == -1) && (*(int *)(param_2 + 0x20) == -0x80000000)) {
    trap(0x1800);
  }
  if (iVar2 == 0) {
    trap(0x1c00);
  }
  if ((iVar2 == -1) && (*(int *)(param_2 + 0x1c) == -0x80000000)) {
    trap(0x1800);
  }
  SendMessageW(hWnd_00,0x406,1,
               *(int *)(param_2 + 0x20) / iVar2 << 0x10 | *(int *)(param_2 + 0x1c) / iVar2 & 0xffffU
              );
  SendMessageW(hWnd_00,0x414,1,0);
  SendMessageW(hWnd_00,0x415,0,3);
  iVar2 = *(int *)(param_2 + 0xc);
  iVar1 = (*(int *)(param_2 + 0x14) - *(int *)(param_2 + 4)) + *(int *)(param_2 + 0x18);
  if (iVar2 == 0) {
    trap(0x1c00);
  }
  if ((iVar2 == -1) && (iVar1 == -0x80000000)) {
    trap(0x1800);
  }
  SendMessageW(hWnd,0x405,1,iVar1 / iVar2);
  iVar2 = *(int *)(param_2 + 0x10);
  if (iVar2 == 0) {
    trap(0x1c00);
  }
  if ((iVar2 == -1) && (*(int *)(param_2 + 8) == -0x80000000)) {
    trap(0x1800);
  }
  SendMessageW(hWnd_00,0x405,1,*(int *)(param_2 + 8) / iVar2);
  return;
}



/* 405eff0c FUN_405eff0c */

/* Boundary evidence: original MIPS .pdata 405eff0c..405effe7. Semantic name remains unreviewed. */

void FUN_405eff0c(HWND param_1,int param_2)

{
  HWND pHVar1;
  LRESULT bEnable;
  uint uVar2;
  
  if (param_2 == 0) {
    uVar2 = 0;
    do {
      pHVar1 = GetDlgItem(param_1,*(int *)((int)&DAT_405e3184 + uVar2));
      ShowWindow(pHVar1,0);
      uVar2 = uVar2 + 4;
    } while (uVar2 < 0x48);
  }
  else {
    pHVar1 = GetDlgItem(param_1,0x1b8);
    bEnable = SendMessageW(pHVar1,0xf0,0,0);
    uVar2 = 0;
    do {
      pHVar1 = GetDlgItem(param_1,*(int *)((int)&DAT_405e31cc + uVar2));
      EnableWindow(pHVar1,bEnable);
      uVar2 = uVar2 + 4;
    } while (uVar2 < 0x38);
  }
  return;
}



/* 405effe8 FUN_405effe8 */

/* Boundary evidence: original MIPS .pdata 405effe8..405f0087. Semantic name remains unreviewed. */

void FUN_405effe8(HWND param_1,UINT param_2,WPARAM param_3,LPARAM param_4)

{
  int iVar1;
  WNDPROC lpPrevWndFunc;
  
  if ((param_2 == 8) ||
     ((param_2 == 0x102 && (iVar1 = GetWindowTextLengthW(param_1), 0x13 < iVar1)))) {
    SetWindowTextW(param_1,L"");
  }
  lpPrevWndFunc = (WNDPROC)GetWindowLongW(param_1,-0x15);
  CallWindowProcW(lpPrevWndFunc,param_1,param_2,param_3,param_4);
  return;
}



/* 405f0088 FUN_405f0088 */

/* Boundary evidence: original MIPS .pdata 405f0088..405f0243. Semantic name remains unreviewed. */

void FUN_405f0088(int *param_1,int *param_2)

{
  int *hMem;
  int iVar1;
  int *piVar2;
  int iVar3;
  HKEY apHStack_30 [4];
  
  KeybdGetDeviceInfo(1,param_1);
  iVar1 = param_1[2];
  if (iVar1 == -1) {
    iVar1 = 2;
  }
  iVar3 = 2;
  if (param_1[3] != -1) {
    iVar3 = param_1[3];
  }
  hMem = LocalAlloc(0,(iVar3 + iVar1) * 4);
  if (hMem != (int *)0x0) {
    piVar2 = hMem + iVar1;
    KeybdGetDeviceInfo(2,hMem);
    if (param_1[2] == -1) {
      param_2[5] = *hMem;
      param_2[6] = hMem[1];
    }
    else {
      param_2[5] = *hMem;
      param_2[6] = piVar2[-1];
    }
    if (piVar2 != (int *)0x0) {
      if (param_1[3] == -1) {
        param_2[7] = *piVar2;
        iVar1 = piVar2[1];
      }
      else {
        param_2[7] = *piVar2;
        iVar1 = piVar2[iVar3 + -1];
      }
      param_2[8] = iVar1;
    }
  }
  param_2[3] = (param_2[6] - param_2[5]) / 0xf;
  param_2[4] = (param_2[8] - param_2[7]) / 10;
  param_2[1] = *param_1;
  iVar1 = param_1[1];
  *param_2 = iVar1;
  param_2[2] = iVar1;
  if (iVar1 == 0) {
    FUN_405e3fc4(apHStack_30,(HKEY)0x80000001,L"ControlPanel\\Keybd");
    iVar1 = FUN_405e4194(apHStack_30,L"DispDly",0);
    param_2[2] = iVar1;
    FUN_405e4020(apHStack_30);
  }
  if (hMem != (int *)0x0) {
    LocalFree(hMem);
  }
  return;
}



/* 405f0244 FUN_405f0244 */

/* Boundary evidence: original MIPS .pdata 405f0244..405f03e7. Semantic name remains unreviewed. */

void FUN_405f0244(HWND param_1,int param_2)

{
  HWND pHVar1;
  HWND hWnd;
  LRESULT LVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  HKEY local_28;
  undefined4 local_24;
  undefined4 local_20;
  
  pHVar1 = GetDlgItem(param_1,0x1bd);
  hWnd = GetDlgItem(param_1,0x1c4);
  LVar2 = SendMessageW(pHVar1,0x400,0,0);
  iVar5 = LVar2 * *(int *)(param_2 + 0xc);
  LVar2 = SendMessageW(hWnd,0x400,0,0);
  iVar6 = LVar2 * *(int *)(param_2 + 0x10);
  iVar4 = *(int *)(param_2 + 0x14);
  iVar7 = iVar4;
  if ((iVar4 <= iVar5) && (iVar7 = iVar5, *(int *)(param_2 + 0x18) < iVar5)) {
    iVar7 = *(int *)(param_2 + 0x18);
  }
  iVar3 = *(int *)(param_2 + 0x18);
  iVar5 = *(int *)(param_2 + 0x1c);
  if ((iVar5 <= iVar6) && (iVar5 = iVar6, *(int *)(param_2 + 0x20) < iVar6)) {
    iVar5 = *(int *)(param_2 + 0x20);
  }
  pHVar1 = GetDlgItem(param_1,0x1b8);
  LVar2 = SendMessageW(pHVar1,0xf0,0,0);
  iVar6 = iVar5;
  if (LVar2 == 0) {
    iVar6 = 0;
  }
  local_28 = (HKEY)0x0;
  local_24 = 0;
  local_20 = 0;
  FUN_405e3f58(&local_28,(HKEY)0x80000001,L"ControlPanel\\Keybd");
  FUN_405e4618(&local_28,L"InitialDelay",(iVar3 - iVar7) + iVar4);
  FUN_405e4618(&local_28,L"RepeatRate",iVar6);
  FUN_405e4618(&local_28,L"DispDly",iVar5);
  NotifyWinUserSystem(2);
  FUN_405e4020(&local_28);
  return;
}



/* 405f03e8 FUN_405f03e8 */

/* Boundary evidence: original MIPS .pdata 405f03e8..405f048f. Semantic name remains unreviewed. */

void FUN_405f03e8(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  HKEY local_20;
  undefined4 local_1c;
  undefined4 local_18;
  
  local_20 = (HKEY)0x0;
  local_1c = 0;
  local_18 = 0;
  FUN_405e3f58(&local_20,(HKEY)0x80000001,L"ControlPanel\\Keybd");
  FUN_405e4618(&local_20,L"InitialDelay",param_1);
  FUN_405e4618(&local_20,L"RepeatRate",param_2);
  FUN_405e4618(&local_20,L"DispDly",param_3);
  NotifyWinUserSystem(2);
  FUN_405e4020(&local_20);
  return;
}



/* 405f0490 KeybdDlgProc */

/* Boundary evidence: original MIPS .pdata 405f0490..405f07e7. Semantic name remains unreviewed. */

undefined4 KeybdDlgProc(HWND param_1,UINT param_2,uint param_3,int param_4)

{
  bool bVar1;
  HWND pHVar2;
  LRESULT LVar3;
  LONG dwNewLong;
  int iVar4;
  uint uVar5;
  uint uVar6;
  
                    /* 0x10490  12  KeybdDlgProc */
  if (param_2 == 0x15) {
LAB_405f0778:
    pHVar2 = GetDlgItem(param_1,0x1c4);
    SendMessageW(pHVar2,param_2,param_3,param_4);
    pHVar2 = GetDlgItem(param_1,0x1bd);
    SendMessageW(pHVar2,param_2,param_3,param_4);
    return 0;
  }
  if (param_2 == 0x2b) {
    if (((param_3 & 0xffff) == 0x1bb) || (uVar5 = 0x13a0, (param_3 & 0xffff) == 0x1c2)) {
      uVar5 = 0x139f;
    }
    FUN_405f7b00(param_4,uVar5);
    return 0;
  }
  if (param_2 == 0x110) {
    pHVar2 = GetDlgItem(param_1,0x1c8);
    dwNewLong = GetWindowLongW(pHVar2,-4);
    pHVar2 = GetDlgItem(param_1,0x1c8);
    SetWindowLongW(pHVar2,-0x15,dwNewLong);
    pHVar2 = GetDlgItem(param_1,0x1c8);
    SetWindowLongW(pHVar2,-4,0x405effe8);
    FUN_405f0088((int *)&DAT_405fb8c0,&DAT_405fb8d0);
    if (DAT_405fb8f0 < 1) {
      DAT_405fb758 = 0;
    }
    FUN_405efcc8(param_1,0x405fb8d0);
    bVar1 = 0 < DAT_405fb8d0;
    pHVar2 = GetDlgItem(param_1,0x1b8);
    SendMessageW(pHVar2,0xf1,(uint)bVar1,0);
    pHVar2 = GetDlgItem(param_1,0x1b8);
    SetFocus(pHVar2);
    FUN_405eff0c(param_1,DAT_405fb758);
    FUN_405f0244(param_1,0x405fb8d0);
    FUN_405f7378(param_1,8);
    return 0;
  }
  if (param_2 != 0x111) {
    if (param_2 != 0x114) {
      return 0;
    }
    uVar5 = param_3 & 0xffff;
    if (4 < uVar5) {
      if (uVar5 < 6) {
        return 0;
      }
      if (7 < uVar5) {
        return 0;
      }
    }
    FUN_405f0244(param_1,0x405fb8d0);
    return 1;
  }
  uVar5 = param_3 & 0xffff;
  if (uVar5 != 1) {
    if (uVar5 == 2) {
      FUN_405f03e8(DAT_405fb8d4,DAT_405fb8d0,DAT_405fb8d8);
      return 1;
    }
    if (uVar5 == 0x1b8) {
      FUN_405eff0c(param_1,DAT_405fb758);
    }
    else {
      uVar6 = 0x1bf;
      if ((uVar5 == 0x1bb) || (uVar5 == 0x1bf)) {
        iVar4 = 0x1bd;
      }
      else {
        uVar6 = 0x1c6;
        if ((uVar5 != 0x1c2) && (uVar5 != 0x1c6)) goto LAB_405f0778;
        iVar4 = 0x1c4;
      }
      pHVar2 = GetDlgItem(param_1,iVar4);
      LVar3 = SendMessageW(pHVar2,0x400,0,0);
      iVar4 = 1;
      if (uVar5 != uVar6) {
        iVar4 = -1;
      }
      SendMessageW(pHVar2,0x405,1,iVar4 + LVar3);
    }
  }
  FUN_405f0244(param_1,0x405fb8d0);
  return 1;
}



/* 405f07e8 FUN_405f07e8 */

/* Boundary evidence: original MIPS .pdata 405f07e8..405f087b. Semantic name remains unreviewed. */

undefined4 * FUN_405f07e8(undefined4 *param_1)

{
  int iVar1;
  HLOCAL pvVar2;
  SIZE_T local_10 [2];
  
  param_1[2] = 0;
  *param_1 = 0;
  param_1[1] = 0;
  local_10[0] = 0x104;
  iVar1 = EnumPnpIds(0,local_10);
  if (iVar1 == 0xea) {
    local_10[0] = 0;
  }
  if (local_10[0] != 0) {
    pvVar2 = LocalAlloc(0x40,local_10[0]);
    *param_1 = pvVar2;
    if ((pvVar2 != (HLOCAL)0x0) && (iVar1 = EnumPnpIds(pvVar2,local_10), iVar1 == 0)) {
      param_1[1] = *param_1;
    }
  }
  return param_1;
}



/* 405f087c FUN_405f087c */

/* Boundary evidence: original MIPS .pdata 405f087c..405f08f3. Semantic name remains unreviewed. */

void FUN_405f087c(int param_1,int *param_2)

{
  uint uVar1;
  _MEMORYSTATUS local_30;
  
  local_30.dwLength = 0x20;
  GlobalMemoryStatus(&local_30);
  uVar1 = param_1 << 10;
  if (uVar1 == 0) {
    trap(0x1c00);
  }
  if (uVar1 == 0) {
    trap(0x1c00);
  }
  *param_2 = (local_30.dwTotalPhys / uVar1 - local_30.dwAvailPhys / uVar1) + 1;
  return;
}



/* 405f08f4 FUN_405f08f4 */

/* Boundary evidence: original MIPS .pdata 405f08f4..405f09c7. Semantic name remains unreviewed. */

void FUN_405f08f4(uint *param_1,int *param_2,int *param_3,int *param_4,int *param_5)

{
  uint uVar1;
  int local_28 [2];
  uint local_20;
  uint local_1c;
  
  GetSystemMemoryDivision(param_5,local_28,param_1);
  GetStoreInformation(&local_20);
  uVar1 = *param_1;
  local_20 = local_20 / uVar1;
  if (uVar1 == 0) {
    trap(0x1c00);
  }
  local_1c = local_1c / uVar1;
  if (uVar1 == 0) {
    trap(0x1c00);
  }
  *param_1 = uVar1 >> 10;
  *param_2 = *param_5 + local_28[0];
  *param_3 = *param_5 - local_1c;
  FUN_405f087c(*param_1,param_4);
  return;
}



/* 405f09c8 FUN_405f09c8 */

/* Boundary evidence: original MIPS .pdata 405f09c8..405f0a53. Semantic name remains unreviewed. */

void FUN_405f09c8(HWND param_1,UINT param_2,WPARAM param_3,LONG *param_4)

{
  POINT Point;
  HWND hWndTo;
  tagPOINT local_10;
  
  if (param_2 == 0x410) {
    local_10.x = *param_4;
    local_10.y = param_4[1];
    hWndTo = (HWND)GetWindowLongW(param_1,-0x15);
    MapWindowPoints((HWND)0x0,hWndTo,&local_10,1);
    Point.y = local_10.y;
    Point.x = local_10.x;
    ChildWindowFromPoint(hWndTo,Point);
  }
  else {
    CallWindowProcW(DAT_405fb900,param_1,param_2,param_3,(LPARAM)param_4);
  }
  return;
}



/* 405f0a54 FUN_405f0a54 */

undefined4 FUN_405f0a54(ushort *param_1)

{
  ushort uVar1;
  int iVar2;
  ushort *puVar3;
  
  if (((param_1 != (ushort *)0x0) && (uVar1 = *param_1, uVar1 != 0)) &&
     (((0x60 < uVar1 && (uVar1 < 0x7b)) || ((0x40 < uVar1 && (uVar1 < 0x5b)))))) {
    iVar2 = 1;
    puVar3 = param_1;
    while (puVar3 = puVar3 + 1, *puVar3 != 0) {
      if (0xe < iVar2) {
        return 0;
      }
      uVar1 = *puVar3;
      if ((((uVar1 != 0x2d) && (uVar1 != 0x5f)) && ((uVar1 < 0x61 || (0x7a < uVar1)))) &&
         ((uVar1 < 0x41 || (0x5a < uVar1)))) {
        if (uVar1 < 0x30) {
          return 0;
        }
        if (0x39 < uVar1) {
          return 0;
        }
      }
      iVar2 = iVar2 + 1;
    }
    if ((param_1[iVar2 + -1] != 0x2d) && (param_1[iVar2 + -1] != 0x5f)) {
      return 1;
    }
  }
  return 0;
}



/* 405f0b60 FUN_405f0b60 */

/* Boundary evidence: original MIPS .pdata 405f0b60..405f0cf3. Semantic name remains unreviewed. */

void FUN_405f0b60(HWND param_1,int param_2)

{
  int iVar1;
  HWND hWnd;
  wchar_t *pwVar2;
  uint uVar3;
  uint uVar4;
  uint local_108;
  int local_104;
  int local_100;
  uint local_fc;
  int aiStack_f8 [2];
  wchar_t awStack_f0 [99];
  undefined2 local_2a;
  uint local_28;
  
  local_28 = DAT_405fb760;
  FUN_405f08f4(&local_108,&local_100,(int *)&local_fc,&local_104,aiStack_f8);
  uVar4 = local_fc >> 4;
  uVar3 = (local_100 - local_104) - 0x30U >> 4;
  hWnd = GetDlgItem(param_1,0x21e);
  if ((*(uint *)(param_2 + 0xc) != uVar4) || (*(uint *)(param_2 + 0x10) != uVar3)) {
    SendMessageW(hWnd,0x40a,1,uVar3 << 0x10 | uVar4 & 0xffff);
    *(uint *)(param_2 + 0xc) = uVar4;
    *(uint *)(param_2 + 0x10) = uVar3;
  }
  if (*(uint *)(param_2 + 0x14) != local_fc) {
    iVar1 = local_108 * local_fc;
    pwVar2 = (wchar_t *)LoadStringW(DAT_405fb7fc,0x8066,(LPWSTR)0x0,0);
    _snwprintf(awStack_f0,99,pwVar2,iVar1);
    local_2a = 0;
    SetDlgItemTextW(param_1,0x225,awStack_f0);
    *(uint *)(param_2 + 0x14) = local_fc;
  }
  if (*(int *)(param_2 + 0x18) != local_104) {
    pwVar2 = (wchar_t *)LoadStringW(DAT_405fb7fc,0x8066,(LPWSTR)0x0,0);
    _snwprintf(awStack_f0,99,pwVar2,local_108 * local_104);
    local_2a = 0;
    SetDlgItemTextW(param_1,0x226,awStack_f0);
    *(int *)(param_2 + 0x18) = local_104;
  }
  FUN_405f9bec(local_28);
  return;
}



/* 405f0cf4 FUN_405f0cf4 */

/* WARNING: Removing unreachable block (ram,0x405f0db4) */
/* Boundary evidence: original MIPS .pdata 405f0cf4..405f0ed3. Semantic name remains unreviewed. */

void FUN_405f0cf4(HWND param_1)

{
  HWND hWnd;
  int lParam;
  wchar_t *pwVar1;
  int iVar2;
  uint uVar3;
  uint local_108;
  int local_104;
  int local_100;
  uint local_fc;
  int aiStack_f8 [2];
  wchar_t awStack_f0 [99];
  undefined2 local_2a;
  uint local_28;
  
  local_28 = DAT_405fb760;
  FUN_405f08f4(&local_108,&local_104,(int *)&local_fc,&local_100,aiStack_f8);
  hWnd = GetDlgItem(param_1,0x21e);
  lParam = SendMessageW(hWnd,0x400,0,0);
  uVar3 = local_108 << 4;
  if (uVar3 == 0) {
    trap(0x1c00);
  }
  if (lParam < (int)(0x20 / (int)uVar3 + (local_fc >> 4))) {
    if (uVar3 == 0) {
      trap(0x1c00);
    }
    lParam = 0x20 / uVar3 + (local_fc >> 4);
  }
  else {
    iVar2 = ((local_104 - local_100) - 0x30U >> 4) - 2;
    if (iVar2 < lParam) {
      lParam = iVar2;
    }
  }
  SendMessageW(hWnd,0x405,1,lParam);
  iVar2 = lParam * 0x10 * local_108;
  pwVar1 = (wchar_t *)LoadStringW(DAT_405fb7fc,0x8066,(LPWSTR)0x0,0);
  _snwprintf(awStack_f0,99,pwVar1,iVar2);
  local_2a = 0;
  SetDlgItemTextW(param_1,0x21f,awStack_f0);
  pwVar1 = (wchar_t *)LoadStringW(DAT_405fb7fc,0x8066,(LPWSTR)0x0,0);
  _snwprintf(awStack_f0,99,pwVar1,(local_104 + lParam * -0x10) * local_108);
  local_2a = 0;
  SetDlgItemTextW(param_1,0x220,awStack_f0);
  FUN_405f9bec(local_28);
  return;
}



/* 405f0ed4 FUN_405f0ed4 */

/* Boundary evidence: original MIPS .pdata 405f0ed4..405f10bf. Semantic name remains unreviewed. */

void FUN_405f0ed4(HWND param_1,int param_2)

{
  bool bVar1;
  HWND hWnd;
  LRESULT LVar2;
  int iVar3;
  LPCWSTR lpCaption;
  LPCWSTR lpText;
  int iVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  uint local_38;
  int local_34;
  int local_30;
  int iStack_2c;
  uint auStack_28 [2];
  
  hWnd = GetDlgItem(param_1,0x21e);
  LVar2 = SendMessageW(hWnd,0x400,0,0);
  FUN_405f08f4(auStack_28,&local_30,(int *)&local_38,&local_34,&iStack_2c);
  uVar5 = (local_30 - local_34) - 0x30U & 0xfffffff0;
  iVar4 = uVar5 - 0x28;
  iVar6 = LVar2 << 4;
  if (iVar4 < LVar2 << 4) {
    iVar6 = iVar4;
  }
  iVar4 = SetSystemMemoryDivision(iVar6);
  if (iVar4 != 0) {
    iVar9 = uVar5 - 0x10;
    iVar8 = (local_38 & 0xfffffff0) + 0x10;
    iVar4 = iVar6;
    do {
      iVar6 = iVar6 + 0x10;
      iVar7 = iVar4 + -0x10;
      bVar1 = false;
      if ((iVar8 <= iVar7) && (iVar7 <= iVar9)) {
        iVar3 = SetSystemMemoryDivision(iVar7);
        if (iVar3 == 0) {
          SetSystemMemoryDivision(iVar4 + -0x38);
          iVar3 = iVar4 + -0x38;
          break;
        }
        bVar1 = true;
      }
      if ((iVar8 <= iVar6) && (iVar6 <= iVar9)) {
        iVar4 = SetSystemMemoryDivision(iVar6);
        iVar3 = iVar6;
        if (iVar4 == 0) break;
        bVar1 = true;
      }
      iVar3 = param_2;
      iVar4 = iVar7;
    } while (bVar1);
    if (iVar3 < 0) {
      iVar3 = iVar3 + 0xf;
    }
    SendMessageW(hWnd,0x405,1,iVar3 >> 4);
    UpdateWindow(param_1);
    Sleep(1000);
    lpCaption = (LPCWSTR)LoadStringW(DAT_405fb7fc,0x8068,(LPWSTR)0x0,0);
    lpText = (LPCWSTR)LoadStringW(DAT_405fb7fc,0x8067,(LPWSTR)0x0,0);
    MessageBoxW(param_1,lpText,lpCaption,0x30);
  }
  return;
}



/* 405f10c0 FUN_405f10c0 */

/* Boundary evidence: original MIPS .pdata 405f10c0..405f11d3. Semantic name remains unreviewed. */

wchar_t * FUN_405f10c0(int param_1)

{
  size_t sVar1;
  wchar_t *pwVar2;
  HKEY apHStack_30 [4];
  HKEY local_20 [4];
  
  if (*(HLOCAL *)(param_1 + 8) != (HLOCAL)0x0) {
    LocalFree(*(HLOCAL *)(param_1 + 8));
  }
  *(undefined4 *)(param_1 + 8) = 0;
  if ((*(short **)(param_1 + 4) == (short *)0x0) || (**(short **)(param_1 + 4) == 0)) {
    pwVar2 = (wchar_t *)0x0;
  }
  else {
    FUN_405e3fc4(local_20,(HKEY)0x80000002,L"Drivers\\PCMCIA");
    FUN_405e3fc4(apHStack_30,local_20[0],*(LPCWSTR *)(param_1 + 4));
    sVar1 = wcslen(*(wchar_t **)(param_1 + 4));
    pwVar2 = (wchar_t *)FUN_405f7da0(apHStack_30,L"FriendlyName");
    if (pwVar2 == (wchar_t *)0x0) {
      pwVar2 = FUN_405ee458(*(wchar_t **)(param_1 + 4));
      if (4 < (int)sVar1) {
        pwVar2[sVar1 - 5] = L'\0';
      }
    }
    else {
      pwVar2 = FUN_405ee458(pwVar2);
    }
    *(size_t *)(param_1 + 4) = (sVar1 + 1) * 2 + *(int *)(param_1 + 4);
    *(wchar_t **)(param_1 + 8) = pwVar2;
    FUN_405e4020(apHStack_30);
    FUN_405e4020(local_20);
  }
  return pwVar2;
}



/* 405f11d4 FUN_405f11d4 */

/* Boundary evidence: original MIPS .pdata 405f11d4..405f12e7. Semantic name remains unreviewed. */

void FUN_405f11d4(HWND param_1)

{
  HWND hWnd;
  int iVar1;
  wchar_t *lParam;
  LRESULT LVar2;
  HLOCAL local_18 [2];
  HLOCAL local_10;
  
  FUN_405f07e8(local_18);
  hWnd = GetDlgItem(param_1,0x233);
  iVar1 = SendMessageW(hWnd,0x146,0,0);
  while (0 < iVar1) {
    SendMessageW(hWnd,0x144,0,0);
    iVar1 = SendMessageW(hWnd,0x146,0,0);
  }
  while (lParam = FUN_405f10c0((int)local_18), lParam != (wchar_t *)0x0) {
    SendMessageW(hWnd,0x143,0,(LPARAM)lParam);
  }
  LVar2 = SendMessageW(hWnd,0x146,0,0);
  if (LVar2 == 0) {
    EnableWindow(hWnd,0);
  }
  else {
    EnableWindow(hWnd,1);
    SendMessageW(hWnd,0x14e,0,0);
  }
  if (local_18[0] != (HLOCAL)0x0) {
    LocalFree(local_18[0]);
  }
  if (local_10 != (HLOCAL)0x0) {
    LocalFree(local_10);
  }
  return;
}



/* 405f12e8 SystemDlgProc */

/* Boundary evidence: original MIPS .pdata 405f12e8..405f1947. Semantic name remains unreviewed. */

undefined4 SystemDlgProc(HWND param_1,int param_2,short param_3,int param_4)

{
  STRSAFE_LPCWSTR pwVar1;
  HWND pHVar2;
  HMONITOR pHVar3;
  HDC hdc;
  LRESULT cchString;
  LPCWSTR lpszString;
  BOOL BVar4;
  uint uVar5;
  uint wParam;
  int iVar6;
  tagRECT local_7b8;
  tagRECT local_7a8;
  int local_798;
  uint local_794;
  int iStack_790;
  undefined1 auStack_78c [4];
  int aiStack_788 [2];
  undefined4 local_780;
  undefined4 local_77c;
  HWND local_778;
  HWND local_774;
  undefined4 local_75c;
  _union_530 local_750;
  undefined1 auStack_74c [24];
  int local_734;
  _OSVERSIONINFOW local_728;
  undefined1 auStack_610 [2];
  wchar_t local_60e [41];
  wchar_t local_5bc [141];
  wchar_t local_4a2 [105];
  wchar_t awStack_3d0 [33];
  wchar_t awStack_38e [247];
  wchar_t awStack_1a0 [190];
  uint local_24;
  
                    /* 0x112e8  25  SystemDlgProc */
  local_24 = DAT_405fb760;
  if (param_2 == 0x4e) {
    if (*(int *)(param_4 + 8) == -0x212) {
      local_7a8.left = 0;
      memset(&local_7a8.top,0,0xc);
      local_7b8.left = 0;
      memset(&local_7b8.top,0,4);
      pHVar2 = GetDlgItem(param_1,0x229);
      GetClientRect(pHVar2,&local_7a8);
      hdc = GetDC(pHVar2);
      if (hdc != (HDC)0x0) {
        cchString = SendMessageW(pHVar2,0xe,0,0);
        if (cchString != 0) {
          wParam = cchString + 1;
          if (wParam < 0x80000000) {
            uVar5 = wParam * 2;
          }
          else {
            uVar5 = 0xffffffff;
          }
          lpszString = operator_new(uVar5);
          if (lpszString != (LPCWSTR)0x0) {
            SendMessageW(pHVar2,0xd,wParam,(LPARAM)lpszString);
            BVar4 = GetTextExtentExPointW
                              (hdc,lpszString,cchString,0,(LPINT)0x0,(LPINT)0x0,(LPSIZE)&local_7b8);
            if ((BVar4 != 0) && (local_7a8.right <= local_7b8.left)) {
              memset((wchar_t *)(param_4 + 0x10),0,0xa0);
              wcsncpy((wchar_t *)(param_4 + 0x10),lpszString,0x4f);
            }
            operator_delete(lpszString);
          }
        }
        ReleaseDC(pHVar2,hdc);
      }
LAB_405f1914:
      FUN_405f9bec(local_24);
      return 1;
    }
    if (*(int *)(param_4 + 8) == -0x209) {
      pHVar2 = *(HWND *)(param_4 + 4);
      local_7b8.left = 0;
      memset(&local_7b8.top,0,0xc);
      GetWindowRect(pHVar2,&local_7b8);
      local_7a8.left = 0;
      memset(&local_7a8.top,0,0xc);
      GetWindowRect(DAT_405fb8fc,&local_7a8);
      iVar6 = local_7a8.right - local_7a8.left;
      pHVar3 = MonitorFromWindow(pHVar2,2);
      if (pHVar3 != (HMONITOR)0x0) {
        memset(auStack_74c,0,0x24);
        local_750.dwOemId = 0x28;
        GetMonitorInfo(pHVar3,&local_750);
        if (local_734 < iVar6 + local_7b8.left) {
          local_7b8.left = local_734 - iVar6;
        }
      }
      local_7b8.top = local_7b8.top + 2;
      local_7b8.left = local_7b8.left + 2;
      SetWindowPos(DAT_405fb8fc,(HWND)0x0,local_7b8.left,local_7b8.top,0,0,0x15);
      SetWindowLongW(param_1,0,1);
LAB_405f136c:
      FUN_405f9bec(local_24);
      return 1;
    }
  }
  else if (param_2 == 0x110) {
    local_728.dwOSVersionInfoSize = 0x114;
    GetVersionExW(&local_728);
    if (local_728.dwBuildNumber == 0) {
      pwVar1 = (STRSAFE_LPCWSTR)LoadStringW(DAT_405fb7fc,0x806a,(LPWSTR)0x0,0);
      StringCbPrintfW(awStack_1a0,0x17c,pwVar1,local_728.dwMajorVersion,local_728.dwMinorVersion);
    }
    else {
      pwVar1 = (STRSAFE_LPCWSTR)LoadStringW(DAT_405fb7fc,0x8069,(LPWSTR)0x0,0);
      StringCbPrintfW(awStack_1a0,0x17c,pwVar1,local_728.dwMajorVersion,local_728.dwMinorVersion,
                      local_728.dwBuildNumber);
    }
    SetDlgItemTextW(param_1,0x228,awStack_1a0);
    memset(&local_750,0,0x24);
    GetSystemInfo((LPSYSTEM_INFO)&local_750.s);
    KernelIoControl(0x1010064,0,0,auStack_610,0x240,auStack_78c);
    wcscpy(awStack_1a0,local_4a2);
    if ((local_4a2[0] != L'\0') && ((local_60e[0] != L'\0' || (local_5bc[0] != L'\0')))) {
      wcscat(awStack_1a0,L", ");
    }
    wcscat(awStack_1a0,local_60e);
    if ((local_60e[0] != L'\0') && (local_5bc[0] != L'\0')) {
      wcscat(awStack_1a0,L"-");
    }
    wcscat(awStack_1a0,local_5bc);
    SetDlgItemTextW(param_1,0x229,awStack_1a0);
    pHVar2 = GetDlgItem(param_1,0x229);
    PostMessageW(pHVar2,0xb1,0,0);
    FUN_405f08f4(&local_794,&local_798,&local_7b8.left,&iStack_790,aiStack_788);
    pwVar1 = (STRSAFE_LPCWSTR)LoadStringW(DAT_405fb7fc,0x8065,(LPWSTR)0x0,0);
    StringCbPrintfW(awStack_1a0,0x17c,pwVar1,local_794 * local_798);
    SetDlgItemTextW(param_1,0x22c,awStack_1a0);
    FUN_405f11d4(param_1);
    FUN_405f2e1c((LPBYTE)awStack_3d0,(LPBYTE)0x0);
    pHVar2 = GetDlgItem(param_1,0x22d);
    FUN_405f88fc(pHVar2,awStack_3d0);
    pHVar2 = GetDlgItem(param_1,0x22e);
    if (pHVar2 != (HWND)0x0) {
      FUN_405f88fc(pHVar2,awStack_38e);
    }
    DAT_405fb8fc = CreateWindowExW(8,L"tooltips_class32",(LPCWSTR)0x0,0x80000003,-0x80000000,
                                   -0x80000000,-0x80000000,-0x80000000,param_1,(HMENU)0x0,
                                   DAT_405fb7fc,(LPVOID)0x0);
    if (DAT_405fb8fc != (HWND)0x0) {
      memset(&local_77c,0,0x28);
      local_780 = 0x2c;
      local_77c = 0x111;
      local_75c = 0xffffffff;
      local_778 = param_1;
      local_774 = GetDlgItem(param_1,0x229);
      SendMessageW(DAT_405fb8fc,0x432,0,(LPARAM)&local_780);
      DAT_405fb900 = SetWindowLongW(DAT_405fb8fc,-4,0x405f09c8);
      SetWindowLongW(DAT_405fb8fc,-0x15,(LONG)param_1);
    }
    FUN_405f7378(param_1,8);
    pHVar2 = GetDlgItem(param_1,0x233);
    SetFocus(pHVar2);
  }
  else if (param_2 == 0x111) {
    if (param_3 == 1) goto LAB_405f136c;
  }
  else if (param_2 == 0x219) {
    FUN_405f11d4(param_1);
    goto LAB_405f1914;
  }
  FUN_405f9bec(local_24);
  return 0;
}



/* 405f1948 MemoryDlgProc */

/* Boundary evidence: original MIPS .pdata 405f1948..405f1cc7. Semantic name remains unreviewed. */

undefined4 MemoryDlgProc(HWND param_1,int param_2,uint param_3,LPARAM param_4)

{
  int iVar1;
  int *piVar2;
  uint *_Dst;
  HWND pHVar3;
  wchar_t *pwVar4;
  UINT_PTR UVar5;
  uint uVar6;
  uint local_108;
  uint local_104;
  uint local_100;
  int iStack_fc;
  int aiStack_f8 [2];
  wchar_t awStack_f0 [99];
  undefined2 local_2a;
  uint local_28;
  
                    /* 0x11948  13  MemoryDlgProc */
  local_28 = DAT_405fb760;
  piVar2 = (int *)GetWindowLongW(param_1,8);
  if ((param_2 == 0x110) || (piVar2 != (int *)0x0)) {
    if (param_2 == 2) {
      operator_delete(piVar2);
      SetWindowLongW(param_1,8,0);
    }
    else if (param_2 == 0x15) {
      pHVar3 = GetDlgItem(param_1,0x21e);
      SendMessageW(pHVar3,0x15,param_3,param_4);
    }
    else if (param_2 == 0x110) {
      FUN_405f08f4(&local_104,(int *)&local_100,&iStack_fc,aiStack_f8,(int *)&local_108);
      _Dst = operator_new(0x1c);
      if (_Dst != (uint *)0x0) {
        memset(_Dst,0,0x1c);
        SetWindowLongW(param_1,8,(LONG)_Dst);
        _Dst[2] = 0;
        *_Dst = local_108;
        pHVar3 = GetDlgItem(param_1,0x21e);
        SendMessageW(pHVar3,0x406,1,(local_100 >> 4) << 0x10 | 1);
        SendMessageW(pHVar3,0x414,(local_100 >> 4 & 0xffff) / 0x4b,0);
        SendMessageW(pHVar3,0x415,0,3);
        SendMessageW(pHVar3,0x405,1,local_108 >> 4);
        iVar1 = local_104 * local_108;
        pwVar4 = (wchar_t *)LoadStringW(DAT_405fb7fc,0x8066,(LPWSTR)0x0,0);
        _snwprintf(awStack_f0,99,pwVar4,iVar1);
        local_2a = 0;
        SetDlgItemTextW(param_1,0x21f,awStack_f0);
        pwVar4 = (wchar_t *)LoadStringW(DAT_405fb7fc,0x8066,(LPWSTR)0x0,0);
        _snwprintf(awStack_f0,99,pwVar4,(local_100 - local_108) * local_104);
        local_2a = 0;
        SetDlgItemTextW(param_1,0x220,awStack_f0);
        UVar5 = SetTimer(param_1,2,0x5dc,(TIMERPROC)0x0);
        _Dst[1] = UVar5;
        FUN_405f0b60(param_1,(int)_Dst);
        FUN_405f7378(param_1,8);
        goto LAB_405f1c44;
      }
    }
    else if (param_2 == 0x111) {
      if ((param_3 & 0xffff) == 1) {
        if (piVar2[2] != 0) {
          FUN_405f0ed4(param_1,*piVar2);
        }
        if (piVar2[1] != 0) {
          KillTimer(param_1,piVar2[1]);
          piVar2[1] = 0;
        }
        goto LAB_405f1c44;
      }
    }
    else {
      if (param_2 == 0x113) {
        FUN_405f0b60(param_1,(int)piVar2);
        FUN_405f9bec(local_28);
        return 1;
      }
      if ((param_2 == 0x114) &&
         ((uVar6 = param_3 & 0xffff, uVar6 < 5 || ((5 < uVar6 && (uVar6 < 8)))))) {
        piVar2[2] = 1;
        FUN_405f0cf4(param_1);
LAB_405f1c44:
        FUN_405f9bec(local_28);
        return 1;
      }
    }
  }
  FUN_405f9bec(local_28);
  return 0;
}



/* 405f1cc8 FUN_405f1cc8 */

/* Boundary evidence: original MIPS .pdata 405f1cc8..405f1fbb. Semantic name remains unreviewed. */

undefined4 FUN_405f1cc8(undefined *param_1,HWND param_2,int param_3,int param_4)

{
  int iVar1;
  LPCWSTR pWVar2;
  LPCWSTR pWVar3;
  HWND pHVar4;
  HCURSOR pHVar5;
  size_t sVar6;
  int iVar7;
  int iVar8;
  HKEY *_Str;
  undefined4 uVar9;
  HKEY *lpString;
  int aiStack_1d8 [4];
  HKEY local_1c8 [4];
  undefined1 auStack_1b8 [400];
  uint local_28;
  
  local_28 = DAT_405fb760;
  iVar7 = (param_4 + 1) * 2 + 7 >> 3;
  iVar8 = param_4 + 8 >> 3;
  lpString = local_1c8 + iVar7 * -2;
  local_1c8[0] = (HKEY)0x0;
  local_1c8[1] = (HKEY)0x0;
  local_1c8[2] = (HKEY)0x0;
  *(wchar_t *)lpString = L'\0';
  _Str = local_1c8 + iVar7 * -2 + iVar8 * -2;
  GetDlgItemTextW(param_2,param_3,(LPWSTR)lpString,param_4);
  iVar1 = FUN_405f0a54((ushort *)lpString);
  if (iVar1 == 0) {
    pWVar2 = (LPCWSTR)LoadStringW(DAT_405fb7fc,0x8504,(LPWSTR)0x0,0);
    pWVar3 = (LPCWSTR)LoadStringW(DAT_405fb7fc,0x8503,(LPWSTR)0x0,0);
    MessageBoxW(param_2,pWVar3,pWVar2,0x30);
    pHVar4 = GetDlgItem(param_2,param_3);
    SetFocus(pHVar4);
    pHVar4 = GetDlgItem(param_2,param_3);
    SendMessageW(pHVar4,0xb1,0,-1);
LAB_405f1f5c:
    uVar9 = 0;
  }
  else {
    if (param_1 == (undefined *)0x0) {
      FUN_405e3f58(local_1c8,(HKEY)0x80000002,L"Ident");
      iVar1 = FUN_405e424c(local_1c8,L"Name",(wchar_t *)lpString);
      if (iVar1 == 0) {
        pWVar2 = (LPCWSTR)LoadStringW(DAT_405fb7fc,0x850b,(LPWSTR)0x0,0);
        pWVar3 = (LPCWSTR)LoadStringW(DAT_405fb7fc,0x850a,(LPWSTR)0x0,0);
        MessageBoxW(param_2,pWVar3,pWVar2,0x30);
      }
    }
    else {
      aiStack_1d8[iVar7 * -2 + iVar8 * -2 + 3] = 0;
      aiStack_1d8[iVar7 * -2 + iVar8 * -2 + 2] = 0;
      aiStack_1d8[iVar7 * -2 + iVar8 * -2 + 1] = param_4;
      aiStack_1d8[iVar7 * -2 + iVar8 * -2] = (int)_Str;
      WideCharToMultiByte(0,0,(LPCWSTR)lpString,-1,(LPSTR)aiStack_1d8[iVar7 * -2 + iVar8 * -2],
                          aiStack_1d8[iVar7 * -2 + iVar8 * -2 + 1],
                          (LPCSTR)aiStack_1d8[iVar7 * -2 + iVar8 * -2 + 2],
                          (LPBOOL)aiStack_1d8[iVar7 * -2 + iVar8 * -2 + 3]);
      pHVar5 = LoadCursorW((HINSTANCE)0x0,(LPCWSTR)0x7f02);
      pHVar5 = SetCursor(pHVar5);
      if (((DAT_405fb8f4 != (code *)0x0) && (DAT_405fb8f8 != (code *)0x0)) &&
         (iVar1 = (*DAT_405fb8f4)(DAT_405fb75c,auStack_1b8), iVar1 == 0)) {
        sVar6 = strlen((char *)_Str);
        iVar1 = (*(code *)param_1)(_Str,sVar6 + 1);
        if (iVar1 != 0) {
          SetCursor(pHVar5);
          pHVar4 = GetDlgItem(param_2,param_3);
          SetFocus(pHVar4);
          pHVar4 = GetDlgItem(param_2,param_3);
          SendMessageW(pHVar4,0xb1,0,-1);
          (*DAT_405fb8f8)();
          goto LAB_405f1f5c;
        }
        (*DAT_405fb8f8)();
      }
      SetCursor(pHVar5);
    }
    uVar9 = 1;
  }
  FUN_405e4020(local_1c8);
  FUN_405f9bec(local_28);
  return uVar9;
}



/* 405f1fbc SystemIdentDlgProc */

/* Boundary evidence: original MIPS .pdata 405f1fbc..405f243f. Semantic name remains unreviewed. */

undefined4 SystemIdentDlgProc(HWND param_1,int param_2,short param_3,int param_4)

{
  int iVar1;
  code *pcVar2;
  LONG dwNewLong;
  HWND pHVar3;
  LPCWSTR lpString;
  UINT Msg;
  undefined4 uVar4;
  undefined *puVar5;
  HKEY local_280;
  undefined4 local_27c;
  undefined4 local_278;
  undefined1 auStack_270 [400];
  WCHAR aWStack_e0 [16];
  WCHAR local_c0;
  undefined1 auStack_be [102];
  CHAR aCStack_58 [52];
  uint local_24;
  
                    /* 0x11fbc  26  SystemIdentDlgProc */
  local_24 = DAT_405fb760;
  local_280 = (HKEY)0x0;
  puVar5 = (undefined *)0x0;
  local_27c = 0;
  local_278 = 0;
  if (param_2 != 0x110) {
    puVar5 = (undefined *)GetWindowLongW(param_1,8);
  }
  if (param_2 == 2) {
    FUN_405f72e0();
  }
  else if (param_2 == 0x4e) {
    if (*(int *)(param_4 + 8) == -0xc9) {
      pHVar3 = GetDlgItem(param_1,0x21a);
      Msg = 8;
    }
    else {
      if (*(int *)(param_4 + 8) != -200) goto LAB_405f2404;
      pHVar3 = GetDlgItem(param_1,0x21a);
      Msg = 7;
    }
    PostMessageW(pHVar3,Msg,0,0);
  }
  else {
    if (param_2 == 0x110) {
      DAT_405fb904 = LoadLibraryW(L"winsock.dll");
      if (DAT_405fb904 == (HMODULE)0x0) {
        FUN_405f83f4(param_1,0x219,0x8083);
        pHVar3 = GetDlgItem(param_1,0x21a);
        EnableWindow(pHVar3,0);
        pHVar3 = GetDlgItem(param_1,0x21b);
        EnableWindow(pHVar3,0);
        FUN_405e4020(&local_280);
        FUN_405f9bec(local_24);
        return 1;
      }
      pcVar2 = (code *)GetProcAddressW(DAT_405fb904,L"gethostname");
      dwNewLong = GetProcAddressW(DAT_405fb904,L"sethostname");
      DAT_405fb8f4 = (code *)GetProcAddressW(DAT_405fb904,L"WSAStartup");
      DAT_405fb8f8 = (code *)GetProcAddressW(DAT_405fb904,L"WSACleanup");
      SetWindowLongW(param_1,8,dwNewLong);
      FUN_405f83f4(param_1,0x219,0x8082);
      pHVar3 = GetDlgItem(param_1,0x21a);
      SendMessageW(pHVar3,0xc5,0xf,0);
      pHVar3 = GetDlgItem(param_1,0x21b);
      SendMessageW(pHVar3,0xc5,0x32,0);
      pHVar3 = GetDlgItem(param_1,0x21a);
      ImmAssociateContext(pHVar3,(HIMC)0x0);
      RegOpenKeyExW((HKEY)0x80000002,L"Ident",0,0x20019,&local_280);
      if ((((pcVar2 != (code *)0x0) && (DAT_405fb8f4 != (code *)0x0)) &&
          (DAT_405fb8f8 != (code *)0x0)) &&
         ((iVar1 = (*DAT_405fb8f4)(DAT_405fb75c,auStack_270), iVar1 == 0 &&
          (iVar1 = (*pcVar2)(aCStack_58,0x33), iVar1 == 0)))) {
        MultiByteToWideChar(0,0,aCStack_58,-1,(LPWSTR)&DAT_405fb908,0x33);
        SetDlgItemTextW(param_1,0x21a,(LPCWSTR)&DAT_405fb908);
        (*DAT_405fb8f8)();
      }
      lpString = (LPCWSTR)FUN_405f7da0(&local_280,L"Desc");
      SetDlgItemTextW(param_1,0x21b,lpString);
      FUN_405f723c();
      FUN_405f74b0(param_1);
      uVar4 = 1;
      goto LAB_405f2408;
    }
    if ((param_2 == 0x111) && (uVar4 = 1, param_3 == 1)) {
      local_c0 = L'\0';
      memset(auStack_be,0,100);
      GetDlgItemTextW(param_1,0x21a,aWStack_e0,0x10);
      RegOpenKeyExW((HKEY)0x80000002,L"Ident",0,0x20019,&local_280);
      GetDlgItemTextW(param_1,0x21b,&local_c0,0x32);
      FUN_405e424c(&local_280,L"Desc",&local_c0);
      iVar1 = lstrcmpiW((LPCWSTR)&DAT_405fb908,aWStack_e0);
      if ((iVar1 == 0) || (iVar1 = FUN_405f1cc8(puVar5,param_1,0x21a,0x33), iVar1 != 0))
      goto LAB_405f2408;
      FUN_405e424c(&local_280,L"Name",(wchar_t *)&DAT_405fb908);
      SetDlgItemTextW(param_1,0x21a,(LPCWSTR)&DAT_405fb908);
    }
  }
LAB_405f2404:
  uVar4 = 0;
LAB_405f2408:
  FUN_405e4020(&local_280);
  FUN_405f9bec(local_24);
  return uVar4;
}



/* 405f2440 FUN_405f2440 */

/* Boundary evidence: original MIPS .pdata 405f2440..405f24af. Semantic name remains unreviewed. */

void FUN_405f2440(HWND param_1,int *param_2,int param_3)

{
  HWND hWnd;
  
  if (0 < param_3) {
    do {
      hWnd = GetDlgItem(param_1,*param_2);
      SendMessageW(hWnd,0xc5,param_2[1],0);
      param_2 = param_2 + 2;
      param_3 = param_3 + -1;
    } while (param_3 != 0);
  }
  return;
}



/* 405f24b0 FUN_405f24b0 */

/* Boundary evidence: original MIPS .pdata 405f24b0..405f2633. Semantic name remains unreviewed. */

undefined4
FUN_405f24b0(short *param_1,undefined2 *param_2,uint *param_3,void *param_4,uint *param_5)

{
  short sVar1;
  undefined4 uVar2;
  uint uVar3;
  short *psVar4;
  uint uVar5;
  
  if ((((param_1 == (short *)0x0) || (param_4 == (void *)0x0)) || (param_5 == (uint *)0x0)) ||
     (((*param_5 == 0 || (param_2 == (undefined2 *)0x0)) ||
      ((param_3 == (uint *)0x0 || (uVar3 = *param_3, uVar3 == 0)))))) {
    uVar2 = 0x57;
  }
  else {
    sVar1 = *param_1;
    psVar4 = param_1;
    while (sVar1 != 0) {
      if (sVar1 == 0x5c) {
        uVar5 = (int)psVar4 - (int)param_1 >> 1;
        if (uVar3 < uVar5 + 1) goto LAB_405f25dc;
        memcpy(param_2,param_1,uVar5 * 2);
        param_2[uVar5] = 0;
        param_1 = psVar4 + 1;
        goto LAB_405f2560;
      }
      psVar4 = psVar4 + 1;
      sVar1 = *psVar4;
    }
    if (uVar3 != 0) {
      *param_2 = 0;
      uVar5 = 0;
LAB_405f2560:
      sVar1 = *psVar4;
      while (sVar1 != 0) {
        psVar4 = psVar4 + 1;
        sVar1 = *psVar4;
      }
      uVar3 = (int)psVar4 - (int)param_1 >> 1;
      if (uVar3 + 1 <= *param_5) {
        memcpy(param_4,param_1,uVar3 * 2);
        *(undefined2 *)(uVar3 * 2 + (int)param_4) = 0;
        *param_3 = uVar5;
        *param_5 = uVar3;
        return 0;
      }
    }
LAB_405f25dc:
    uVar2 = 0x7a;
  }
  return uVar2;
}



/* 405f2634 FUN_405f2634 */

/* Boundary evidence: original MIPS .pdata 405f2634..405f278b. Semantic name remains unreviewed. */

undefined4
FUN_405f2634(undefined2 *param_1,uint *param_2,void *param_3,uint param_4,void *param_5,int param_6)

{
  undefined4 uVar1;
  uint uVar2;
  undefined2 *_Dst;
  
  if (((param_1 == (undefined2 *)0x0) || (param_2 == (uint *)0x0)) || (*param_2 == 0)) {
    return 0x57;
  }
  if ((param_5 == (void *)0x0) || (param_6 == 0)) {
    *param_1 = 0;
    *param_2 = 0;
LAB_405f275c:
    uVar1 = 0;
  }
  else {
    uVar2 = param_4 + param_6;
    if ((param_4 < uVar2) && (uVar2 < uVar2 + 2)) {
      if (*param_2 < uVar2 + 2) {
        return 0x7a;
      }
      _Dst = param_1;
      if ((param_3 != (void *)0x0) && (param_4 != 0)) {
        memcpy(param_1,param_3,param_4 * 2);
        param_1[param_4] = 0x5c;
        _Dst = param_1 + param_4 + 1;
      }
      if (param_6 + 1U <= *param_2 - ((int)_Dst - (int)param_1 >> 1)) {
        memcpy(_Dst,param_5,param_6 * 2);
        _Dst[param_6] = 0;
        *param_2 = (param_6 * 2 - (int)param_1) + (int)_Dst >> 1;
        goto LAB_405f275c;
      }
    }
    uVar1 = 0x54f;
  }
  return uVar1;
}



/* 405f278c FUN_405f278c */

/* Boundary evidence: original MIPS .pdata 405f278c..405f2847. Semantic name remains unreviewed. */

undefined4 FUN_405f278c(undefined2 *param_1,uint *param_2,void *param_3,uint *param_4)

{
  int iVar1;
  undefined4 uVar2;
  short *psVar3;
  undefined2 local_20 [2];
  int local_1c;
  
  local_1c = 0;
  local_20[0] = 0;
  iVar1 = CredRead(local_20,1,0x10001,0x1800,&local_1c);
  if ((iVar1 == 0) && (local_1c != 0)) {
    psVar3 = *(short **)(local_1c + 8);
  }
  else {
    psVar3 = (short *)&DAT_405e1694;
  }
  uVar2 = FUN_405f24b0(psVar3,param_1,param_2,param_3,param_4);
  if (local_1c != 0) {
    CredFree();
  }
  return uVar2;
}



/* 405f2848 FUN_405f2848 */

/* WARNING: Type propagation algorithm not settling */
/* Boundary evidence: original MIPS .pdata 405f2848..405f29d3. Semantic name remains unreviewed. */

int FUN_405f2848(wchar_t *param_1,size_t param_2,wchar_t *param_3,size_t param_4,wchar_t *param_5,
                size_t param_6)

{
  int iVar1;
  undefined2 local_278 [2];
  uint local_274 [3];
  undefined2 *local_268;
  int local_264;
  undefined2 *local_260;
  undefined4 local_25c;
  wchar_t *local_258;
  int local_254;
  undefined4 local_250;
  undefined2 auStack_248 [274];
  uint local_24;
  
  local_24 = DAT_405fb760;
  if ((param_2 < 0x10) && (param_4 < 0x101)) {
    local_278[0] = 0;
    local_274[0] = 0x111;
    if ((param_4 == 0) && (param_3 != (wchar_t *)0x0)) {
      param_4 = wcslen(param_3);
    }
    if ((param_2 == 0) && (param_1 != (wchar_t *)0x0)) {
      param_2 = wcslen(param_1);
    }
    if ((param_6 == 0) && (param_5 != (wchar_t *)0x0)) {
      param_6 = wcslen(param_5);
    }
    iVar1 = FUN_405f2634(auStack_248,local_274,param_1,param_2,param_3,param_4);
    if (iVar1 == 0) {
      local_258 = param_5;
      local_274[2] = 0x10001;
      local_260 = local_278;
      local_274[1] = 1;
      local_25c = 1;
      local_268 = auStack_248;
      local_264 = local_274[0] + 1;
      local_250 = 3;
      if (param_5 == (wchar_t *)0x0) {
        local_254 = 0;
      }
      else {
        local_254 = (param_6 + 1) * 2;
      }
      iVar1 = CredWrite(local_274 + 1,0);
    }
    FUN_405f9bec(local_24);
  }
  else {
    FUN_405f9bec(DAT_405fb760);
    iVar1 = 0x57;
  }
  return iVar1;
}



/* 405f29d4 FUN_405f29d4 */

/* Boundary evidence: original MIPS .pdata 405f29d4..405f2a5b. Semantic name remains unreviewed. */

undefined4 FUN_405f29d4(void)

{
  LSTATUS LVar1;
  undefined4 uVar2;
  HKEY local_18;
  undefined4 local_14;
  undefined4 local_10;
  
  uVar2 = 0;
  local_18 = (HKEY)0x0;
  local_14 = 0;
  local_10 = 0;
  LVar1 = RegOpenKeyExW((HKEY)0x80000002,L"Comm\\Security",0,0x20019,&local_18);
  if (LVar1 == 0) {
    uVar2 = FUN_405e4194(&local_18,L"DisallowSavedNetworkPasswords",0);
  }
  FUN_405e4020(&local_18);
  return uVar2;
}



/* 405f2a5c NetIdentDlgProc */

/* Boundary evidence: original MIPS .pdata 405f2a5c..405f2e1b. Semantic name remains unreviewed. */

undefined4 NetIdentDlgProc(HWND param_1,int param_2,uint param_3)

{
  UINT UVar1;
  UINT UVar2;
  UINT UVar3;
  HWND pHVar4;
  uint uVar5;
  int iVar6;
  WCHAR *pWVar7;
  undefined4 uVar8;
  undefined2 local_478 [4];
  HKEY local_470;
  undefined4 local_46c;
  undefined4 local_468;
  uint local_464 [3];
  undefined4 local_458;
  undefined4 local_454;
  undefined4 local_450;
  WCHAR local_448;
  undefined1 auStack_446 [28];
  undefined2 local_42a;
  WCHAR local_428;
  undefined1 auStack_426 [510];
  undefined2 local_228;
  WCHAR local_220;
  undefined1 auStack_21e [510];
  undefined2 local_20;
  uint local_1c;
  
                    /* 0x12a5c  14  NetIdentDlgProc */
  local_1c = DAT_405fb760;
  local_458 = 0;
  local_454 = 0;
  local_450 = 0;
  local_428 = L'\0';
  memset(auStack_426,0,0x200);
  local_448 = L'\0';
  memset(auStack_446,0,0x1e);
  local_220 = L'\0';
  memset(auStack_21e,0,0x200);
  local_464[0] = 0x10;
  local_464[1] = 0x101;
  local_478[0] = 0;
  if (param_2 == 2) {
    FUN_405f72e0();
  }
  else {
    if (param_2 == 0x110) {
      FUN_405f723c();
      pHVar4 = GetDlgItem(param_1,0x192);
      SendMessageW(pHVar4,0xc5,0x100,0);
      pHVar4 = GetDlgItem(param_1,0x193);
      SendMessageW(pHVar4,0xc5,0xf,0);
      pHVar4 = GetDlgItem(param_1,0x194);
      SendMessageW(pHVar4,0xc5,0x100,0);
      FUN_405f278c(&local_448,local_464,&local_428,local_464 + 1);
      DAT_405fb970 = FUN_405f29d4();
      if (DAT_405fb970 != 0) {
        pHVar4 = GetDlgItem(param_1,0x194);
        EnableWindow(pHVar4,0);
      }
      SetDlgItemTextW(param_1,0x192,&local_428);
      SetDlgItemTextW(param_1,0x193,&local_448);
      DAT_405fb97c = 0;
      DAT_405fb974 = 0;
      DAT_405fb978 = 0;
      FUN_405f74b0(param_1);
      FUN_405e4020(&local_458);
      FUN_405f9bec(local_1c);
      return 1;
    }
    if (param_2 == 0x111) {
      uVar5 = param_3 & 0xffff;
      uVar8 = 1;
      if (uVar5 == 1) {
        UVar1 = GetDlgItemTextW(param_1,0x192,&local_428,0x100);
        local_228 = 0;
        UVar2 = GetDlgItemTextW(param_1,0x193,&local_448,0xf);
        local_42a = 0;
        UVar3 = GetDlgItemTextW(param_1,0x194,&local_220,0x100);
        local_20 = 0;
        if (UVar1 == 0) {
          CredDelete(local_478,1,0x10001,0);
LAB_405f2c58:
          if (DAT_405fb978 != 0) {
            local_470 = (HKEY)0x0;
            local_46c = 0;
            local_468 = 0;
            RegOpenKeyExW((HKEY)0x80000002,L"Ident",0,0x20019,&local_470);
            FUN_405e41f0(&local_470,L"ComputerDomain",(BYTE *)&local_448,0x10);
            FUN_405e4020(&local_470);
          }
        }
        else if (((DAT_405fb974 != 0) || (DAT_405fb97c != 0)) || (DAT_405fb978 != 0)) {
          FUN_405f2848(&local_448,UVar2,&local_428,UVar1,&local_220,UVar3);
          goto LAB_405f2c58;
        }
        iVar6 = 0x202;
        pWVar7 = &local_220;
        do {
          *(undefined1 *)pWVar7 = 0;
          iVar6 = iVar6 + -1;
          pWVar7 = (WCHAR *)((int)pWVar7 + 1);
        } while (iVar6 != 0);
        goto LAB_405f2dec;
      }
      if (uVar5 == 0x192) {
        if (param_3 >> 0x10 == 0x300) {
          DAT_405fb974 = 1;
        }
      }
      else if (uVar5 == 0x193) {
        if (param_3 >> 0x10 == 0x300) {
          DAT_405fb978 = 1;
        }
      }
      else if ((uVar5 == 0x194) && (param_3 >> 0x10 == 0x300)) {
        DAT_405fb97c = 1;
      }
    }
  }
  uVar8 = 0;
LAB_405f2dec:
  FUN_405e4020(&local_458);
  FUN_405f9bec(local_1c);
  return uVar8;
}



/* 405f2e1c FUN_405f2e1c */

/* Boundary evidence: original MIPS .pdata 405f2e1c..405f2f1b. Semantic name remains unreviewed. */

void FUN_405f2e1c(LPBYTE param_1,LPBYTE param_2)

{
  DWORD local_30 [2];
  HKEY local_28 [4];
  
  FUN_405e3fc4(local_28,(HKEY)0x80000001,L"ControlPanel\\Owner");
  if (param_1 != (LPBYTE)0x0) {
    memset(param_1,0,0x22c);
    local_30[0] = 0x22c;
    if (local_28[0] != (HKEY)0x0) {
      RegQueryValueExW(local_28[0],L"Owner",(LPDWORD)0x0,(LPDWORD)0x0,param_1,local_30);
    }
  }
  if (param_2 != (LPBYTE)0x0) {
    memset(param_2,0,0x184);
    local_30[0] = 0x184;
    if (local_28[0] != (HKEY)0x0) {
      RegQueryValueExW(local_28[0],L"Notes",(LPDWORD)0x0,(LPDWORD)0x0,param_2,local_30);
    }
  }
  FUN_405e4020(local_28);
  return;
}



/* 405f2f1c FUN_405f2f1c */

/* Boundary evidence: original MIPS .pdata 405f2f1c..405f2feb. Semantic name remains unreviewed. */

void FUN_405f2f1c(BYTE *param_1,BYTE *param_2)

{
  HKEY local_20;
  undefined4 local_1c;
  undefined4 local_18;
  
  local_20 = (HKEY)0x0;
  local_1c = 0;
  local_18 = 0;
  FUN_405e3f58(&local_20,(HKEY)0x80000001,L"ControlPanel\\Owner");
  if ((param_1 != (BYTE *)0x0) && (local_20 != (HKEY)0x0)) {
    RegSetValueExW(local_20,L"Owner",0,3,param_1,0x22c);
  }
  if ((param_2 != (BYTE *)0x0) && (local_20 != (HKEY)0x0)) {
    RegSetValueExW(local_20,L"Notes",0,3,param_2,0x184);
  }
  FUN_405e4020(&local_20);
  return;
}



/* 405f2fec OwnerDlgProc */

/* Boundary evidence: original MIPS .pdata 405f2fec..405f32b3. Semantic name remains unreviewed. */

undefined4 OwnerDlgProc(HWND param_1,int param_2,uint param_3)

{
  HWND pHVar1;
  LRESULT LVar2;
  WCHAR aWStack_240 [33];
  WCHAR aWStack_1fe [33];
  WCHAR aWStack_1bc [134];
  WCHAR aWStack_b0 [11];
  WCHAR aWStack_9a [30];
  WCHAR aWStack_5e [11];
  WCHAR aWStack_48 [25];
  byte local_16;
  uint local_14;
  
                    /* 0x12fec  16  OwnerDlgProc */
  local_14 = DAT_405fb760;
  if (param_2 == 2) {
    FUN_405f72e0();
  }
  else {
    if (param_2 == 0x110) {
      FUN_405f723c();
      FUN_405f2440(param_1,(int *)&DAT_405e3354,7);
      FUN_405f74b0(param_1);
      FUN_405f2e1c((LPBYTE)aWStack_240,(LPBYTE)0x0);
      pHVar1 = GetDlgItem(param_1,0x1e0);
      SetWindowTextW(pHVar1,aWStack_240);
      pHVar1 = GetDlgItem(param_1,0x1e1);
      SetWindowTextW(pHVar1,aWStack_1fe);
      pHVar1 = GetDlgItem(param_1,0x1e2);
      SetWindowTextW(pHVar1,aWStack_1bc);
      pHVar1 = GetDlgItem(param_1,0x1e3);
      SetWindowTextW(pHVar1,aWStack_b0);
      pHVar1 = GetDlgItem(param_1,0x1e4);
      SetWindowTextW(pHVar1,aWStack_9a);
      pHVar1 = GetDlgItem(param_1,0x1e5);
      SetWindowTextW(pHVar1,aWStack_5e);
      pHVar1 = GetDlgItem(param_1,0x1e6);
      SetWindowTextW(pHVar1,aWStack_48);
      pHVar1 = GetDlgItem(param_1,0x1e9);
      SendMessageW(pHVar1,0xf1,(uint)local_16,0);
      pHVar1 = GetDlgItem(param_1,0x1e4);
      ImmAssociateContext(pHVar1,(HIMC)0x0);
      pHVar1 = GetDlgItem(param_1,0x1e6);
      ImmAssociateContext(pHVar1,(HIMC)0x0);
      FUN_405f9bec(local_14);
      return 1;
    }
    if (param_2 == 0x111) {
      if ((param_3 & 0xffff) == 1) {
        memset(aWStack_240,0,0x22c);
        GetDlgItemTextW(param_1,0x1e0,aWStack_240,0x21);
        GetDlgItemTextW(param_1,0x1e1,aWStack_1fe,0x21);
        GetDlgItemTextW(param_1,0x1e2,aWStack_1bc,0x81);
        GetDlgItemTextW(param_1,0x1e3,aWStack_b0,0xb);
        GetDlgItemTextW(param_1,0x1e4,aWStack_9a,0x19);
        GetDlgItemTextW(param_1,0x1e5,aWStack_5e,0xb);
        GetDlgItemTextW(param_1,0x1e6,aWStack_48,0x19);
        pHVar1 = GetDlgItem(param_1,0x1e9);
        LVar2 = SendMessageW(pHVar1,0xf0,0,0);
        local_16 = (byte)LVar2;
        FUN_405f2f1c((BYTE *)aWStack_240,(BYTE *)0x0);
      }
      else {
        if ((param_3 & 0xffff) != 0x1e2) goto LAB_405f3290;
        if (param_3 >> 0x10 == 0x501) {
          MessageBeep(0);
        }
      }
      FUN_405f9bec(local_14);
      return 1;
    }
  }
LAB_405f3290:
  FUN_405f9bec(local_14);
  return 0;
}



/* 405f32b4 NotesDlgProc */

/* Boundary evidence: original MIPS .pdata 405f32b4..405f343f. Semantic name remains unreviewed. */

undefined4 NotesDlgProc(HWND param_1,int param_2,uint param_3)

{
  HWND pHVar1;
  LRESULT LVar2;
  WCHAR aWStack_198 [193];
  byte local_16;
  uint local_14;
  
                    /* 0x132b4  15  NotesDlgProc */
  local_14 = DAT_405fb760;
  if (param_2 == 2) {
    FUN_405f72e0();
  }
  else {
    if (param_2 == 0x110) {
      FUN_405f723c();
      FUN_405f2e1c((LPBYTE)0x0,(LPBYTE)aWStack_198);
      pHVar1 = GetDlgItem(param_1,0x1e7);
      SendMessageW(pHVar1,0xc5,0xc0,0);
      pHVar1 = GetDlgItem(param_1,0x1e8);
      SendMessageW(pHVar1,0xf1,(uint)local_16,0);
      pHVar1 = GetDlgItem(param_1,0x1e7);
      SetWindowTextW(pHVar1,aWStack_198);
      FUN_405f74b0(param_1);
      FUN_405f9bec(local_14);
      return 1;
    }
    if (param_2 == 0x111) {
      if ((param_3 & 0xffff) == 1) {
        GetDlgItemTextW(param_1,0x1e7,aWStack_198,0xc1);
        pHVar1 = GetDlgItem(param_1,0x1e8);
        LVar2 = SendMessageW(pHVar1,0xf0,0,0);
        local_16 = (byte)LVar2;
        FUN_405f2f1c((BYTE *)0x0,(BYTE *)aWStack_198);
      }
      else {
        if ((param_3 & 0xffff) != 0x1e7) goto LAB_405f341c;
        if (param_3 >> 0x10 == 0x501) {
          MessageBeep(0);
        }
      }
      FUN_405f9bec(local_14);
      return 1;
    }
  }
LAB_405f341c:
  FUN_405f9bec(local_14);
  return 0;
}



/* 405f3440 FUN_405f3440 */

/* Boundary evidence: original MIPS .pdata 405f3440..405f35df. Semantic name remains unreviewed. */

void FUN_405f3440(HWND param_1)

{
  int iVar1;
  HWND pHVar2;
  LRESULT LVar3;
  WCHAR local_c0 [44];
  WCHAR local_68 [42];
  uint local_14;
  
  local_14 = DAT_405fb760;
  GetDlgItemTextW(param_1,0x1cc,local_68,0x29);
  GetDlgItemTextW(param_1,0x1cd,local_c0,0x29);
  if (((local_68[0] == L'\0') || (local_c0[0] == L'\0')) ||
     (iVar1 = _wcsicmp(local_68,local_c0), iVar1 != 0)) {
    pHVar2 = GetDlgItem(param_1,0x1ce);
    EnableWindow(pHVar2,0);
    pHVar2 = GetDlgItem(param_1,0x1d1);
    SendMessageW(pHVar2,0xf1,0,0);
    pHVar2 = GetDlgItem(param_1,0x1d1);
    EnableWindow(pHVar2,0);
    if ((local_68[0] == L'\0') && (local_c0[0] == L'\0')) {
      pHVar2 = GetDlgItem(param_1,0x1ce);
      SendMessageW(pHVar2,0xf1,0,0);
    }
  }
  else {
    pHVar2 = GetDlgItem(param_1,0x1ce);
    EnableWindow(pHVar2,1);
    pHVar2 = GetDlgItem(param_1,0x1ce);
    LVar3 = SendMessageW(pHVar2,0xf0,0,0);
    if (LVar3 == 1) {
      pHVar2 = GetDlgItem(param_1,0x1d1);
      SendMessageW(pHVar2,0xf1,DAT_405fb980,0);
      pHVar2 = GetDlgItem(param_1,0x1d1);
      EnableWindow(pHVar2,1);
    }
  }
  FUN_405f9bec(local_14);
  return;
}



/* 405f35e0 PasswdDlgProc */

/* WARNING: Type propagation algorithm not settling */
/* Boundary evidence: original MIPS .pdata 405f35e0..405f3b1b. Semantic name remains unreviewed. */

undefined4 PasswdDlgProc(HWND param_1,int param_2,uint param_3,LPCWSTR param_4)

{
  HWND pHVar1;
  LRESULT LVar2;
  LPCWSTR pWVar3;
  LPCWSTR lpText;
  int iVar4;
  uint uVar5;
  WCHAR *pWVar6;
  size_t local_1d8 [2];
  WCHAR local_1d0;
  undefined1 auStack_1ce [86];
  WCHAR local_178;
  undefined1 auStack_176 [86];
  undefined1 auStack_120 [256];
  uint local_20;
  
                    /* 0x135e0  17  PasswdDlgProc */
  local_20 = DAT_405fb760;
  if (param_2 == 0x110) {
    DAT_405fb984 = param_4;
    pHVar1 = GetDlgItem(param_1,0x1cc);
    SendMessageW(pHVar1,0xc5,0x28,0);
    pHVar1 = GetDlgItem(param_1,0x1cd);
    SendMessageW(pHVar1,0xc5,0x28,0);
    SetDlgItemTextW(param_1,0x1cc,DAT_405fb984);
    SetDlgItemTextW(param_1,0x1cd,DAT_405fb984);
    pHVar1 = GetDlgItem(param_1,0x1cc);
    SetFocus(pHVar1);
    pHVar1 = GetDlgItem(param_1,0x1cc);
    SendMessageW(pHVar1,0xb1,0,-1);
    uVar5 = GetPasswordStatus();
    pHVar1 = GetDlgItem(param_1,0x1ce);
    SendMessageW(pHVar1,0xf1,uVar5 & 1,0);
    pHVar1 = GetDlgItem(param_1,0x1d1);
    EnableWindow(pHVar1,uVar5 & 1);
    DAT_405fb980 = uVar5 & 2;
    pHVar1 = GetDlgItem(param_1,0x1d1);
    SendMessageW(pHVar1,0xf1,DAT_405fb980,0);
    FUN_405f3440(param_1);
    FUN_405f7378(param_1,8);
    DAT_405fb988 = 1;
  }
  else if (param_2 == 0x111) {
    uVar5 = param_3 & 0xffff;
    if (uVar5 == 1) {
      local_1d0 = L'\0';
      memset(auStack_1ce,0,0x52);
      local_178 = L'\0';
      memset(auStack_176,0,0x50);
      local_1d8[0] = 0;
      pWVar6 = (WCHAR *)0x0;
      GetDlgItemTextW(param_1,0x1cc,&local_1d0,0x29);
      GetDlgItemTextW(param_1,0x1cd,&local_178,0x29);
      iVar4 = _wcsicmp(&local_1d0,&local_178);
      if (iVar4 == 0) {
        _wcslwr(&local_1d0);
        iVar4 = CheckPassword(0);
        pWVar3 = (LPCWSTR)0x0;
        if (iVar4 == 0) {
          pWVar3 = DAT_405fb984;
        }
        StringCchLengthW(&local_1d0,0x2a,local_1d8);
        if (local_1d8[0] != 0) {
          pWVar6 = &local_1d0;
        }
        iVar4 = SetPassword(pWVar3,pWVar6);
        if (iVar4 != 0) {
          pHVar1 = GetDlgItem(param_1,0x1ce);
          LVar2 = SendMessageW(pHVar1,0xf0,0,0);
          if (LVar2 == 0) {
            uVar5 = 0;
          }
          else {
            pHVar1 = GetDlgItem(param_1,0x1d1);
            LVar2 = SendMessageW(pHVar1,0xf0,0,0);
            uVar5 = 2;
            if (LVar2 == 0) {
              uVar5 = 0;
            }
            uVar5 = uVar5 | 1;
          }
          iVar4 = SetPasswordStatus(uVar5,pWVar6);
          if (iVar4 != 0) {
            local_1d8[1] = 0x80;
            iVar4 = GetUserNameExW(0x80000001,auStack_120,local_1d8 + 1);
            if (iVar4 != 0) {
              if (uVar5 == 0) {
                iVar4 = 0;
                pWVar6 = (WCHAR *)0x0;
              }
              else {
                iVar4 = local_1d8[0] << 1;
              }
              SetUserData(pWVar6,iVar4);
            }
          }
        }
LAB_405f37a4:
        FUN_405f9bec(local_20);
        return 1;
      }
      pWVar3 = (LPCWSTR)LoadStringW(DAT_405fb7fc,0x8034,(LPWSTR)0x0,0);
      lpText = (LPCWSTR)LoadStringW(DAT_405fb7fc,0x8035,(LPWSTR)0x0,0);
      MessageBoxW(param_1,lpText,pWVar3,0x40);
      pHVar1 = GetDlgItem(param_1,0x1cd);
      SetFocus(pHVar1);
      pHVar1 = GetDlgItem(param_1,0x1cd);
      SendMessageW(pHVar1,0xb1,0,-1);
    }
    else if (0x1cb < uVar5) {
      if (uVar5 < 0x1ce) {
        if (param_3 >> 0x10 == 0x300) {
          if (DAT_405fb988 != 0) {
            iVar4 = 0x1cc;
            DAT_405fb988 = 0;
            if (uVar5 == 0x1cc) {
              iVar4 = 0x1cd;
            }
            SetDlgItemTextW(param_1,iVar4,L"");
          }
          FUN_405f3440(param_1);
        }
        goto LAB_405f37a4;
      }
      if (uVar5 == 0x1ce) {
        if (param_3 >> 0x10 == 0) {
          pHVar1 = GetDlgItem(param_1,0x1ce);
          LVar2 = SendMessageW(pHVar1,0xf0,0,0);
          if (LVar2 != 1) {
            pHVar1 = GetDlgItem(param_1,0x1d1);
            SendMessageW(pHVar1,0xf1,0,0);
            pHVar1 = GetDlgItem(param_1,0x1d1);
          }
          else {
            pHVar1 = GetDlgItem(param_1,0x1d1);
            SendMessageW(pHVar1,0xf1,DAT_405fb980,0);
            pHVar1 = GetDlgItem(param_1,0x1d1);
          }
          EnableWindow(pHVar1,(uint)(LVar2 == 1));
        }
      }
      else if ((uVar5 == 0x1d1) && (param_3 >> 0x10 == 0)) {
        pHVar1 = GetDlgItem(param_1,0x1d1);
        LVar2 = SendMessageW(pHVar1,0xf0,0,0);
        if (LVar2 == 1) {
          DAT_405fb980 = 1;
        }
        else {
          DAT_405fb980 = 0;
        }
      }
    }
  }
  FUN_405f9bec(local_20);
  return 0;
}



/* 405f3b1c FUN_405f3b1c */

/* Boundary evidence: original MIPS .pdata 405f3b1c..405f3b8b. Semantic name remains unreviewed. */

LRESULT FUN_405f3b1c(HWND param_1)

{
  HWND hWnd;
  WPARAM wParam;
  LRESULT LVar1;
  
  hWnd = GetDlgItem(param_1,0x2a8);
  wParam = SendMessageW(hWnd,0x147,0,0);
  if ((wParam == 0xffffffff) || (LVar1 = SendMessageW(hWnd,0x150,wParam,0), LVar1 == -1)) {
    LVar1 = 0;
  }
  return LVar1;
}



/* 405f3b8c FUN_405f3b8c */

/* Boundary evidence: original MIPS .pdata 405f3b8c..405f3ccb. Semantic name remains unreviewed. */

void FUN_405f3b8c(HWND param_1,int param_2)

{
  IID *rclsid;
  HRESULT HVar1;
  LPCWSTR pWVar2;
  LPCWSTR pWVar3;
  int iVar4;
  int *local_18 [2];
  
  local_18[0] = (int *)0x0;
  rclsid = (IID *)FUN_405f3b1c(param_1);
  if ((rclsid != (IID *)0x0) && (param_2 != 0)) {
    HVar1 = CoCreateInstance(rclsid,(LPUNKNOWN)0x0,0x17,(IID *)&DAT_405e3454,local_18);
    if (HVar1 < 0) {
      pWVar2 = (LPCWSTR)LoadStringW(DAT_405fb7fc,0x8213,(LPWSTR)0x0,0);
      pWVar3 = (LPCWSTR)LoadStringW(DAT_405fb7fc,0x8214,(LPWSTR)0x0,0);
      MessageBoxW(param_1,pWVar3,pWVar2,0x30);
    }
    else {
      iVar4 = (**(code **)(*local_18[0] + 0x30))(local_18[0],param_1);
      if (iVar4 < 0) {
        pWVar2 = (LPCWSTR)LoadStringW(DAT_405fb7fc,0x8213,(LPWSTR)0x0,0);
        pWVar3 = (LPCWSTR)LoadStringW(DAT_405fb7fc,0x8215,(LPWSTR)0x0,0);
        MessageBoxW(param_1,pWVar3,pWVar2,0);
      }
      (**(code **)(*local_18[0] + 8))();
    }
  }
  return;
}



/* 405f3ccc FUN_405f3ccc */

/* Boundary evidence: original MIPS .pdata 405f3ccc..405f3d23. Semantic name remains unreviewed. */

PHKEY FUN_405f3ccc(PHKEY param_1)

{
  *param_1 = (HKEY)0x0;
  param_1[1] = (HKEY)0x0;
  param_1[2] = (HKEY)0x0;
  RegOpenKeyExW((HKEY)0x80000000,L"CLSID",0,0x20019,param_1);
  return param_1;
}



/* 405f3d24 FUN_405f3d24 */

/* Boundary evidence: original MIPS .pdata 405f3d24..405f3f2b. Semantic name remains unreviewed. */

undefined4 * FUN_405f3d24(undefined4 *param_1)

{
  int iVar1;
  short *psVar2;
  wchar_t *pwVar3;
  HRESULT HVar4;
  size_t sVar5;
  ulong *puVar6;
  long nIconIndex;
  HKEY local_268 [4];
  HKEY apHStack_258 [4];
  HKEY apHStack_248 [4];
  CLSID local_238;
  WCHAR aWStack_228 [260];
  uint local_20;
  
  local_20 = DAT_405fb760;
  iVar1 = FUN_405e991c(param_1,aWStack_228,0x104);
  do {
    if (iVar1 == 0) {
      FUN_405f9bec(local_20);
      return (undefined4 *)0x0;
    }
    FUN_405e3fc4(local_268,(HKEY)*param_1,aWStack_228);
    FUN_405e3fc4(apHStack_258,local_268[0],L"IsSIPInputMethod");
    psVar2 = (short *)FUN_405f7da0(apHStack_258,(LPCWSTR)0x0);
    if ((((psVar2 != (short *)0x0) && (*psVar2 == 0x31)) &&
        (pwVar3 = (wchar_t *)FUN_405f7da0(local_268,(LPCWSTR)0x0), pwVar3 != (wchar_t *)0x0)) &&
       (HVar4 = CLSIDFromString(aWStack_228,&local_238), -1 < HVar4)) {
      sVar5 = wcslen(pwVar3);
      puVar6 = LocalAlloc(0x40,(sVar5 + 0xd) * 2);
      if (puVar6 != (ulong *)0x0) {
        wcscpy((wchar_t *)(puVar6 + 6),pwVar3);
        *puVar6 = local_238.Data1;
        puVar6[1] = local_238._4_4_;
        puVar6[2] = local_238.Data4._0_4_;
        puVar6[3] = local_238.Data4._4_4_;
        FUN_405e3fc4(apHStack_248,local_268[0],L"DefaultIcon");
        iVar1 = FUN_405e9984(apHStack_248,(LPCWSTR)0x0,(LPBYTE)aWStack_228,0x104);
        if (iVar1 != 0) {
          nIconIndex = 0;
          pwVar3 = wcschr(aWStack_228,L',');
          if (pwVar3 != (wchar_t *)0x0) {
            *pwVar3 = L'\0';
            nIconIndex = _wtol(pwVar3 + 1);
          }
          ExtractIconExW(aWStack_228,nIconIndex,(HICON *)(puVar6 + 4),(HICON *)(puVar6 + 5),1);
        }
        FUN_405e4020(apHStack_248);
        FUN_405e4020(apHStack_258);
        FUN_405e4020(local_268);
        FUN_405f9bec(local_20);
        return puVar6;
      }
    }
    FUN_405e4020(apHStack_258);
    FUN_405e4020(local_268);
    iVar1 = FUN_405e991c(param_1,aWStack_228,0x104);
  } while( true );
}



/* 405f3f2c FUN_405f3f2c */

/* Boundary evidence: original MIPS .pdata 405f3f2c..405f3f8f. Semantic name remains unreviewed. */

undefined4 * FUN_405f3f2c(undefined4 *param_1,uint param_2)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)*param_1;
  if (puVar1 != (undefined4 *)0x0) {
    FUN_405f7e78(puVar1);
    operator_delete(puVar1);
  }
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}



/* 405f3f90 FUN_405f3f90 */

/* Boundary evidence: original MIPS .pdata 405f3f90..405f409b. Semantic name remains unreviewed. */

void FUN_405f3f90(HWND param_1,HWND param_2)

{
  int iVar1;
  void *_Buf1;
  WPARAM wParam;
  undefined1 auStack_38 [16];
  uint local_28;
  
  local_28 = DAT_405fb760;
  iVar1 = SipGetCurrentIM(auStack_38);
  if (iVar1 != 0) {
    wParam = 0;
    _Buf1 = (void *)SendMessageW(param_1,0x150,0,0);
    while (_Buf1 != (void *)0xffffffff) {
      iVar1 = memcmp(_Buf1,auStack_38,0x10);
      if (iVar1 == 0) {
        SendMessageW(param_1,0x14e,wParam,0);
        iVar1 = *(int *)((int)_Buf1 + 0x10);
        if (*(int *)((int)_Buf1 + 0x10) == 0) {
          iVar1 = DAT_405fb98c;
        }
        SendMessageW(param_2,0x172,1,iVar1);
      }
      wParam = wParam + 1;
      _Buf1 = (void *)SendMessageW(param_1,0x150,wParam,0);
    }
  }
  FUN_405f9bec(local_28);
  return;
}



/* 405f409c SipDlgProc */

/* Boundary evidence: original MIPS .pdata 405f409c..405f447b. Semantic name remains unreviewed. */

undefined4 SipDlgProc(HWND param_1,int param_2,uint param_3)

{
  undefined4 *puVar1;
  LRESULT LVar2;
  HWND pHVar3;
  HRESULT HVar4;
  undefined4 *puVar5;
  PHKEY ppHVar6;
  WPARAM WVar7;
  HWND pHVar8;
  uint uVar9;
  HICON lParam;
  HKEY apHStack_28 [4];
  
                    /* 0x1409c  22  SipDlgProc */
  puVar1 = (undefined4 *)GetWindowLongW(param_1,8);
  if ((param_2 == 0x110) || (puVar1 != (undefined4 *)0x0)) {
    if (param_2 == 2) {
      if (puVar1[1] != 0) {
        CoUninitialize();
      }
      SetWindowLongW(param_1,8,0);
      FUN_405f3f2c(puVar1,1);
    }
    else if (param_2 == 0x1a) {
      if (param_3 == 0xe2) {
        pHVar3 = GetDlgItem(param_1,0x2ab);
        pHVar8 = GetDlgItem(param_1,0x2a8);
        FUN_405f3f90(pHVar8,pHVar3);
      }
    }
    else {
      if (param_2 == 0x110) {
        puVar1 = operator_new(8);
        if (puVar1 == (undefined4 *)0x0) {
          puVar1 = (undefined4 *)0x0;
        }
        else {
          *puVar1 = 0;
          puVar1[1] = 0;
        }
        SetWindowLongW(param_1,8,(LONG)puVar1);
        if (puVar1 == (undefined4 *)0x0) {
          return 1;
        }
        HVar4 = CoInitializeEx((LPVOID)0x0,0);
        if (-1 < HVar4) {
          puVar1[1] = 1;
        }
        DAT_405fb98c = LoadIconW(DAT_405fb7fc,(LPCWSTR)0x1414);
        puVar5 = operator_new(8);
        if (puVar5 == (undefined4 *)0x0) {
          puVar5 = (undefined4 *)0x0;
        }
        else {
          pHVar3 = GetDlgItem(param_1,0x2a8);
          *puVar5 = pHVar3;
        }
        *puVar1 = puVar5;
        ppHVar6 = operator_new(0xc);
        if (ppHVar6 == (PHKEY)0x0) {
          ppHVar6 = (PHKEY)0x0;
        }
        else {
          ppHVar6 = FUN_405f3ccc(ppHVar6);
        }
        if (ppHVar6 != (PHKEY)0x0) {
          while (puVar1 = FUN_405f3d24(ppHVar6), puVar1 != (undefined4 *)0x0) {
            pHVar3 = GetDlgItem(param_1,0x2a8);
            WVar7 = SendMessageW(pHVar3,0x143,0,(LPARAM)(puVar1 + 6));
            pHVar3 = GetDlgItem(param_1,0x2a8);
            SendMessageW(pHVar3,0x151,WVar7,(LPARAM)puVar1);
          }
          FUN_405e4020(ppHVar6);
          operator_delete(ppHVar6);
        }
        FUN_405e3fc4(apHStack_28,(HKEY)0x80000001,L"ControlPanel\\Sip");
        WVar7 = FUN_405e4194(apHStack_28,L"AllowChange",0);
        pHVar3 = GetDlgItem(param_1,0x2aa);
        SendMessageW(pHVar3,0xf1,WVar7,0);
        pHVar3 = GetDlgItem(param_1,0x2ab);
        pHVar8 = GetDlgItem(param_1,0x2a8);
        FUN_405f3f90(pHVar8,pHVar3);
LAB_405f43d0:
        FUN_405e4020(apHStack_28);
        return 1;
      }
      if (param_2 == 0x111) {
        uVar9 = param_3 & 0xffff;
        if (uVar9 == 1) {
          FUN_405e3fc4(apHStack_28,(HKEY)0x80000001,L"ControlPanel\\Sip");
          pHVar3 = GetDlgItem(param_1,0x2aa);
          LVar2 = SendMessageW(pHVar3,0xf0,0,0);
          FUN_405e4618(apHStack_28,L"AllowChange",LVar2);
          LVar2 = FUN_405f3b1c(param_1);
          if (LVar2 != 0) {
            SipSetCurrentIM(LVar2);
          }
          goto LAB_405f43d0;
        }
        if (uVar9 == 0x2a8) {
          if (param_3 >> 0x10 != 1) {
            return 1;
          }
          LVar2 = FUN_405f3b1c(param_1);
          if (LVar2 == 0) {
            return 1;
          }
          lParam = *(HICON *)(LVar2 + 0x10);
          if (*(HICON *)(LVar2 + 0x10) == (HICON)0x0) {
            lParam = DAT_405fb98c;
          }
          pHVar3 = GetDlgItem(param_1,0x2ab);
          SendMessageW(pHVar3,0x172,1,(LPARAM)lParam);
          return 1;
        }
        if (uVar9 == 0x2a9) {
          FUN_405f3b8c(param_1,puVar1[1]);
          return 1;
        }
      }
    }
  }
  return 0;
}



/* 405f447c FUN_405f447c */

/* Boundary evidence: original MIPS .pdata 405f447c..405f458b. Semantic name remains unreviewed. */

undefined4 FUN_405f447c(undefined4 param_1,wchar_t *param_2,wchar_t *param_3,int param_4)

{
  wchar_t wVar1;
  size_t sVar2;
  DWORD DVar3;
  undefined4 uVar4;
  
  *param_3 = L'\0';
  uVar4 = 0;
  if (((param_2 != (wchar_t *)0x0) && (wVar1 = *param_2, wVar1 != L' ')) &&
     (sVar2 = wcslen(param_2), (int)(sVar2 + 0xe) <= param_4)) {
    if (wVar1 == L'\\') {
      wcscpy(param_3,param_2);
    }
    else {
      wcscpy(param_3,L"\\Windows\\");
      wcscat(param_3,param_2);
    }
    sVar2 = wcslen(param_3);
    if (param_3[sVar2 - 4] != L'.') {
      wcscat(param_3,L".wav");
    }
    DVar3 = GetFileAttributesW(param_3);
    uVar4 = 1;
    if (DVar3 == 0xffffffff) {
      uVar4 = 0;
    }
  }
  return uVar4;
}



/* 405f458c FUN_405f458c */

/* Boundary evidence: original MIPS .pdata 405f458c..405f466f. Semantic name remains unreviewed. */

void FUN_405f458c(undefined4 *param_1,LPCWSTR param_2)

{
  HWND pHVar1;
  int lParam;
  WPARAM wParam;
  
  if (param_2 == (LPCWSTR)0x0) {
    pHVar1 = GetDlgItem((HWND)*param_1,0x299);
    EnableWindow(pHVar1,0);
    pHVar1 = GetDlgItem((HWND)*param_1,0x29a);
    EnableWindow(pHVar1,0);
    lParam = LoadStringW(DAT_405fb7fc,0x8508,(LPWSTR)0x0,0);
    wParam = SendMessageW((HWND)param_1[2],0x158,0xffffffff,lParam);
    SendMessageW((HWND)param_1[2],0x14e,wParam,0);
  }
  else {
    pHVar1 = GetDlgItem((HWND)*param_1,0x299);
    EnableWindow(pHVar1,1);
    pHVar1 = GetDlgItem((HWND)*param_1,0x29a);
    EnableWindow(pHVar1,1);
    FUN_405f8e8c((undefined4 *)param_1[0x89],param_2);
  }
  return;
}



/* 405f4670 FUN_405f4670 */

/* Boundary evidence: original MIPS .pdata 405f4670..405f4707. Semantic name remains unreviewed. */

void FUN_405f4670(undefined4 *param_1)

{
  WPARAM wParam;
  wchar_t *pwVar1;
  undefined4 uVar2;
  
  wParam = SendMessageW((HWND)param_1[2],0x147,0,0);
  if (wParam != 0xffffffff) {
    pwVar1 = (wchar_t *)SendMessageW((HWND)param_1[2],0x150,wParam,0);
    uVar2 = 1;
    if (pwVar1 == (wchar_t *)0x0) {
      uVar2 = 2;
    }
    FUN_405f8fa0((undefined4 *)param_1[0x8b],param_1[0x87],pwVar1,uVar2);
    param_1[0x8c] = 1;
    FUN_405f458c(param_1,pwVar1);
  }
  return;
}



/* 405f4708 FUN_405f4708 */

/* Boundary evidence: original MIPS .pdata 405f4708..405f48f7. Semantic name remains unreviewed. */

void FUN_405f4708(undefined4 *param_1)

{
  undefined1 *puVar1;
  uint *puVar2;
  int iVar3;
  BOOL BVar4;
  DWORD *pDVar5;
  short *psVar6;
  uint uVar7;
  wchar_t *_Dest;
  tagOFNW atStack_2f8 [2];
  wchar_t local_228 [262];
  uint local_1c;
  
  local_1c = DAT_405fb760;
  atStack_2f8[0].dwReserved._0_2_ = 0;
  iVar3 = LoadStringW(DAT_405fb7fc,0x8180,(LPWSTR)&atStack_2f8[0].dwReserved,0x40);
  if (0 < iVar3) {
    pDVar5 = &atStack_2f8[0].dwReserved;
    do {
      if ((short)*pDVar5 == 1) {
        *(short *)pDVar5 = 0;
      }
      iVar3 = iVar3 + -1;
      pDVar5 = (DWORD *)((int)pDVar5 + 2);
    } while (iVar3 != 0);
  }
  local_228[0] = L'\0';
  memset(atStack_2f8,0,0x4c);
  atStack_2f8[0].hwndOwner = (HWND)*param_1;
  _Dest = (wchar_t *)(param_1 + 5);
  puVar1 = (undefined1 *)((int)&atStack_2f8[0].lStructSize + 3);
  uVar7 = (uint)puVar1 & 3;
  puVar2 = (uint *)(puVar1 + -uVar7);
  *puVar2 = *puVar2 & -1 << (uVar7 + 1) * 8 | 0x4cU >> (3 - uVar7) * 8;
  puVar1 = (undefined1 *)((int)&atStack_2f8[0].hInstance + 3);
  uVar7 = (uint)puVar1 & 3;
  puVar2 = (uint *)(puVar1 + -uVar7);
  *puVar2 = *puVar2 & -1 << (uVar7 + 1) * 8 | (uint)DAT_405fb7fc >> (3 - uVar7) * 8;
  puVar1 = (undefined1 *)((int)&atStack_2f8[0].lpstrFilter + 3);
  uVar7 = (uint)puVar1 & 3;
  puVar2 = (uint *)(puVar1 + -uVar7);
  *puVar2 = *puVar2 & -1 << (uVar7 + 1) * 8 | (uint)&atStack_2f8[0].dwReserved >> (3 - uVar7) * 8;
  puVar1 = (undefined1 *)((int)&atStack_2f8[0].nFilterIndex + 3);
  uVar7 = (uint)puVar1 & 3;
  puVar2 = (uint *)(puVar1 + -uVar7);
  *puVar2 = *puVar2 & -1 << (uVar7 + 1) * 8 | 1U >> (3 - uVar7) * 8;
  puVar1 = (undefined1 *)((int)&atStack_2f8[0].lpstrFile + 3);
  uVar7 = (uint)puVar1 & 3;
  puVar2 = (uint *)(puVar1 + -uVar7);
  *puVar2 = *puVar2 & -1 << (uVar7 + 1) * 8 | (uint)local_228 >> (3 - uVar7) * 8;
  puVar1 = (undefined1 *)((int)&atStack_2f8[0].nMaxFile + 3);
  uVar7 = (uint)puVar1 & 3;
  puVar2 = (uint *)(puVar1 + -uVar7);
  *puVar2 = *puVar2 & -1 << (uVar7 + 1) * 8 | 0x106U >> (3 - uVar7) * 8;
  puVar1 = (undefined1 *)((int)&atStack_2f8[0].lpstrInitialDir + 3);
  uVar7 = (uint)puVar1 & 3;
  puVar2 = (uint *)(puVar1 + -uVar7);
  *puVar2 = *puVar2 & -1 << (uVar7 + 1) * 8 | (uint)_Dest >> (3 - uVar7) * 8;
  atStack_2f8[0].lStructSize = 0x4c;
  atStack_2f8[0].hInstance = DAT_405fb7fc;
  atStack_2f8[0].nFilterIndex = 1;
  atStack_2f8[0].nMaxFile = 0x106;
  atStack_2f8[0].lpstrFilter = (LPCWSTR)&atStack_2f8[0].dwReserved;
  atStack_2f8[0].lpstrFile = local_228;
  atStack_2f8[0].lpstrInitialDir = _Dest;
  atStack_2f8[0].lpstrTitle = (LPCWSTR)LoadStringW(DAT_405fb7fc,0x8507,(LPWSTR)0x0,0);
  atStack_2f8[0].Flags = 0x1004;
  atStack_2f8[0].lpstrDefExt = L"wav";
  BVar4 = GetOpenFileNameW(atStack_2f8);
  if (BVar4 != 0) {
    FUN_405f8fa0((undefined4 *)param_1[0x8b],param_1[0x87],atStack_2f8[0].lpstrFile,1);
    uVar7 = (uint)atStack_2f8[0].nFileOffset;
    param_1[0x8c] = 1;
    if ((uVar7 != 0) && (uVar7 < 0x104)) {
      wcscpy(_Dest,atStack_2f8[0].lpstrFile);
      *(undefined2 *)((uVar7 + 10) * 2 + (int)param_1) = 0;
      psVar6 = (short *)((atStack_2f8[0].nFileOffset + 9) * 2 + (int)param_1);
      if (*psVar6 == 0x5c) {
        *psVar6 = 0;
      }
    }
    FUN_405f458c(param_1,atStack_2f8[0].lpstrFile);
  }
  FUN_405f9bec(local_1c);
  return;
}



/* 405f48f8 FUN_405f48f8 */

/* Boundary evidence: original MIPS .pdata 405f48f8..405f49a7. Semantic name remains unreviewed. */

void FUN_405f48f8(undefined4 *param_1)

{
  LPCWSTR pWVar1;
  BOOL BVar2;
  LPCWSTR lpText;
  
  pWVar1 = (LPCWSTR)FUN_405f8170((undefined4 *)param_1[0x8b],param_1[0x87],(undefined2 *)0x0,0);
  Sleep(0x96);
  BVar2 = sndPlaySoundW(pWVar1,1);
  if (BVar2 == 0) {
    pWVar1 = (LPCWSTR)LoadStringW(DAT_405fb7fc,0x8179,(LPWSTR)0x0,0);
    lpText = (LPCWSTR)LoadStringW(DAT_405fb7fc,0x8178,(LPWSTR)0x0,0);
    MessageBoxW((HWND)*param_1,lpText,pWVar1,0x10);
  }
  return;
}



/* 405f49a8 FUN_405f49a8 */

/* Boundary evidence: original MIPS .pdata 405f49a8..405f4a1b. Semantic name remains unreviewed. */

void FUN_405f49a8(HWND param_1,int *param_2,int param_3,BOOL param_4)

{
  HWND hWnd;
  
  if (0 < param_3) {
    do {
      hWnd = GetDlgItem(param_1,*param_2);
      EnableWindow(hWnd,param_4);
      param_2 = param_2 + 1;
      param_3 = param_3 + -1;
    } while (param_3 != 0);
  }
  return;
}



/* 405f4a1c FUN_405f4a1c */

/* Boundary evidence: original MIPS .pdata 405f4a1c..405f4ab3. Semantic name remains unreviewed. */

void FUN_405f4a1c(undefined4 *param_1)

{
  HWND hWnd;
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)param_1[0x89];
  if (puVar1 != (undefined4 *)0x0) {
    FUN_405f7e78(puVar1);
    operator_delete(puVar1);
  }
  puVar1 = (undefined4 *)param_1[0x8a];
  if (puVar1 != (undefined4 *)0x0) {
    FUN_405f7e78(puVar1);
    operator_delete(puVar1);
  }
  operator_delete((void *)param_1[0x8b]);
  hWnd = GetDlgItem((HWND)*param_1,0x295);
  DestroyWindow(hWnd);
  if ((HIMAGELIST)param_1[4] != (HIMAGELIST)0x0) {
    ImageList_Destroy((HIMAGELIST)param_1[4]);
  }
  return;
}



/* 405f4ab4 FUN_405f4ab4 */

/* Boundary evidence: original MIPS .pdata 405f4ab4..405f4cc7. Semantic name remains unreviewed. */

undefined4 FUN_405f4ab4(int param_1,LPCWSTR param_2)

{
  wchar_t *pwVar1;
  LPARAM lParam;
  int iVar2;
  size_t sVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  uint uVar6;
  int iVar7;
  HKEY apHStack_248 [4];
  wchar_t awStack_238 [260];
  uint local_30;
  
  local_30 = DAT_405fb760;
  FUN_405f80f4(*(undefined4 **)(param_1 + 0x22c));
  SendMessageW(*(HWND *)(param_1 + 0xc),0xb,0,0);
  pwVar1 = (wchar_t *)LoadStringW(DAT_405fb7fc,0x8205,(LPWSTR)0x0,0);
  lParam = FUN_405f8f24(*(undefined4 **)(param_1 + 0x22c),0xffff0000,pwVar1,(wchar_t *)0x0,0,
                        0xffff0000);
  FUN_405e3fc4(apHStack_248,(HKEY)0x80000002,L"Snd\\Event");
  pwVar1 = (wchar_t *)FUN_405f7da0(apHStack_248,param_2);
  if (pwVar1 == (wchar_t *)0x0) {
    uVar4 = 0;
  }
  else {
    uVar4 = 1;
    uVar6 = 1;
    puVar5 = (undefined4 *)(param_1 + 0x440);
    iVar7 = 0x15;
    do {
      if ((*(uint *)(param_1 + 0x220) & uVar6) != 0) {
        if (((*pwVar1 == L'\0') || (*pwVar1 == L' ')) ||
           (iVar2 = FUN_405f447c(param_1,pwVar1,awStack_238,0x104), iVar2 == 0)) {
          FUN_405f8f24(*(undefined4 **)(param_1 + 0x22c),lParam,(wchar_t *)*puVar5,(wchar_t *)0x0,2,
                       0xffff0003);
        }
        else {
          FUN_405f8f24(*(undefined4 **)(param_1 + 0x22c),lParam,(wchar_t *)*puVar5,awStack_238,1,
                       0xffff0003);
        }
      }
      puVar5 = puVar5 + 1;
      uVar6 = uVar6 << 1;
      sVar3 = wcslen(pwVar1);
      iVar7 = iVar7 + -1;
      pwVar1 = pwVar1 + sVar3 + 1;
    } while (iVar7 != 0);
    SendMessageW(*(HWND *)(param_1 + 0xc),0x1102,2,lParam);
    SendMessageW(*(HWND *)(param_1 + 0xc),0x115,6,0);
    SendMessageW(*(HWND *)(param_1 + 0xc),0xb,1,0);
  }
  FUN_405e4020(apHStack_248);
  FUN_405f9bec(local_30);
  return uVar4;
}



/* 405f4cc8 FUN_405f4cc8 */

/* Boundary evidence: original MIPS .pdata 405f4cc8..405f4d63. Semantic name remains unreviewed. */

void FUN_405f4cc8(undefined4 *param_1,undefined4 param_2,int param_3)

{
  LRESULT LVar1;
  HWND pHVar2;
  LPCWSTR in_stack_00000028;
  
  param_1[0x87] = param_3;
  FUN_405f458c(param_1,in_stack_00000028);
  LVar1 = SendMessageW((HWND)param_1[3],0x110a,0,0);
  pHVar2 = GetDlgItem((HWND)*param_1,0x297);
  EnableWindow(pHVar2,(uint)(param_3 != LVar1));
  pHVar2 = GetDlgItem((HWND)*param_1,0x298);
  EnableWindow(pHVar2,(uint)(param_3 != LVar1));
  return;
}



/* 405f4d64 FUN_405f4d64 */

/* Boundary evidence: original MIPS .pdata 405f4d64..405f4e43. Semantic name remains unreviewed. */

void FUN_405f4d64(int param_1,WPARAM param_2)

{
  LPCWSTR lpValueName;
  HKEY local_38 [4];
  HKEY local_28 [4];
  
  lpValueName = (LPCWSTR)SendMessageW(*(HWND *)(param_1 + 4),0x150,param_2,0);
  FUN_405e3fc4(local_28,(HKEY)0x80000002,L"Snd\\Event");
  if (local_28[0] != (HKEY)0x0) {
    RegDeleteValueW(local_28[0],lpValueName);
  }
  FUN_405e3fc4(local_38,(HKEY)0x80000002,L"Snd\\Scheme");
  if (local_38[0] != (HKEY)0x0) {
    RegDeleteValueW(local_38[0],lpValueName);
  }
  FUN_405f7f1c(*(undefined4 **)(param_1 + 0x228),param_2);
  *(undefined4 *)(param_1 + 0x43c) = 1;
  FUN_405e4020(local_38);
  FUN_405e4020(local_28);
  return;
}



/* 405f4e44 FUN_405f4e44 */

/* Boundary evidence: original MIPS .pdata 405f4e44..405f4eb7. Semantic name remains unreviewed. */

void FUN_405f4e44(int param_1,wchar_t *param_2)

{
  HKEY local_20;
  undefined4 local_1c;
  undefined4 local_18;
  
  local_20 = (HKEY)0x0;
  local_1c = 0;
  local_18 = 0;
  FUN_405e3f58(&local_20,(HKEY)0x80000002,L"Snd\\Event");
  FUN_405e424c(&local_20,L".Scheme",param_2);
  *(undefined4 *)(param_1 + 0x43c) = 1;
  FUN_405e4020(&local_20);
  return;
}



/* 405f4eb8 FUN_405f4eb8 */

/* Boundary evidence: original MIPS .pdata 405f4eb8..405f51b3. Semantic name remains unreviewed. */

void FUN_405f4eb8(int param_1,wchar_t *param_2,LPCWSTR param_3)

{
  LRESULT lParam;
  int iVar1;
  wchar_t *pwVar2;
  int iVar3;
  BYTE *lpData;
  wchar_t *pwVar4;
  size_t sVar5;
  int iVar6;
  undefined4 *puVar7;
  BYTE *_Dst;
  int iVar8;
  HKEY local_2b0;
  undefined4 local_2ac;
  undefined4 local_2a8;
  wchar_t *local_2a4;
  HKEY local_2a0;
  undefined4 local_29c;
  undefined4 local_298;
  undefined4 local_290 [22];
  WCHAR aWStack_238 [260];
  uint local_30;
  
  local_30 = DAT_405fb760;
  iVar8 = 0x2c;
  local_2a4 = param_2;
  memset(local_290,0,0x54);
  lParam = SendMessageW(*(HWND *)(param_1 + 0xc),0x110a,0,0);
  for (iVar1 = SendMessageW(*(HWND *)(param_1 + 0xc),0x110a,4,lParam); iVar1 != 0;
      iVar1 = SendMessageW(*(HWND *)(param_1 + 0xc),0x110a,1,iVar1)) {
    pwVar2 = (wchar_t *)FUN_405f8170(*(undefined4 **)(param_1 + 0x22c),iVar1,aWStack_238,0x104);
    if (pwVar2 != (wchar_t *)0x0) {
      iVar6 = 0;
      puVar7 = (undefined4 *)(param_1 + 0x440);
      do {
        iVar3 = lstrcmpiW(aWStack_238,(LPCWSTR)*puVar7);
        if (iVar3 == 0) {
          local_290[iVar6] = pwVar2;
          sVar5 = wcslen(pwVar2);
          iVar8 = sVar5 + iVar8;
          break;
        }
        iVar6 = iVar6 + 1;
        puVar7 = puVar7 + 1;
      } while (iVar6 < 0x15);
    }
  }
  lpData = LocalAlloc(0x40,(iVar8 + 1) * 2);
  puVar7 = local_290;
  iVar8 = 0x15;
  _Dst = lpData;
  do {
    pwVar2 = (wchar_t *)*puVar7;
    if (pwVar2 == (wchar_t *)0x0) {
      if (_Dst != (BYTE *)0x0) {
        _Dst[0] = ' ';
        _Dst[1] = '\0';
        _Dst = _Dst + 2;
        goto LAB_405f50a0;
      }
    }
    else {
      iVar1 = _wcsnicmp(pwVar2,L"\\Windows\\",9);
      if (iVar1 == 0) {
        pwVar4 = wcschr(pwVar2 + 9,L'\\');
        if (pwVar4 == (wchar_t *)0x0) {
          *puVar7 = pwVar2 + 9;
        }
      }
      pwVar4 = (wchar_t *)*puVar7;
      pwVar2 = wcsrchr(pwVar4,L'.');
      if (pwVar2 == (wchar_t *)0x0) {
        sVar5 = wcslen(pwVar4);
      }
      else {
        sVar5 = (int)pwVar2 - (int)pwVar4 >> 1;
      }
      memcpy(_Dst,pwVar4,sVar5 * 2);
      _Dst = _Dst + sVar5 * 2;
LAB_405f50a0:
      if (_Dst != (BYTE *)0x0) {
        _Dst[0] = '\0';
        _Dst[1] = '\0';
        _Dst = _Dst + 2;
      }
    }
    iVar8 = iVar8 + -1;
    puVar7 = puVar7 + 1;
    if (iVar8 == 0) {
      if (_Dst != (BYTE *)0x0) {
        _Dst[0] = '\0';
        _Dst[1] = '\0';
        _Dst = _Dst + 2;
      }
      local_2b0 = (HKEY)0x0;
      local_2ac = 0;
      local_2a8 = 0;
      FUN_405e3f58(&local_2b0,(HKEY)0x80000002,L"Snd\\Event");
      RegSetValueExW(local_2b0,param_3,0,7,lpData,((int)_Dst - (int)lpData >> 1) << 1);
      if (lpData != (BYTE *)0x0) {
        LocalFree(lpData);
      }
      local_2a0 = (HKEY)0x0;
      local_29c = 0;
      local_298 = 0;
      FUN_405e3f58(&local_2a0,(HKEY)0x80000002,L"Snd\\Scheme");
      FUN_405e424c(&local_2a0,param_3,local_2a4);
      *(undefined4 *)(param_1 + 0x43c) = 1;
      FUN_405e4020(&local_2a0);
      FUN_405e4020(&local_2b0);
      FUN_405f9bec(local_30);
      return;
    }
  } while( true );
}



/* 405f51b4 FUN_405f51b4 */

/* Boundary evidence: original MIPS .pdata 405f51b4..405f52b7. Semantic name remains unreviewed. */

undefined4 FUN_405f51b4(wchar_t *param_1,LPCWSTR param_2)

{
  size_t sVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  LPCWSTR pWVar5;
  HKEY apHStack_20 [4];
  
  sVar1 = wcslen(param_1);
  if (sVar1 < 8) {
    sVar1 = wcslen(param_1);
  }
  else {
    sVar1 = 8;
  }
  memcpy(param_2,param_1,sVar1 * 2);
  pWVar5 = param_2 + sVar1;
  *pWVar5 = L'0';
  pWVar5[1] = L'\0';
  FUN_405e3fc4(apHStack_20,(HKEY)0x80000002,L"Snd\\Scheme");
  iVar3 = 0;
  iVar2 = FUN_405f7da0(apHStack_20,param_2);
  if (iVar2 != 0) {
    do {
      if (0x31 < iVar3) goto LAB_405f5288;
      *pWVar5 = *pWVar5 + L'\x01';
      iVar3 = iVar3 + 1;
      iVar2 = FUN_405f7da0(apHStack_20,param_2);
    } while (iVar2 != 0);
    if (0x31 < iVar3) {
LAB_405f5288:
      uVar4 = 0;
      goto LAB_405f5294;
    }
  }
  uVar4 = 1;
LAB_405f5294:
  FUN_405e4020(apHStack_20);
  return uVar4;
}



/* 405f52b8 FUN_405f52b8 */

/* Boundary evidence: original MIPS .pdata 405f52b8..405f54d7. Semantic name remains unreviewed. */

undefined4 FUN_405f52b8(undefined4 *param_1,WPARAM param_2,LPCWSTR param_3,int param_4)

{
  int iVar1;
  HWND pHVar2;
  BOOL bEnable;
  
  while( true ) {
    if (param_3 == (LPCWSTR)0x0) {
      if (param_2 != 0xffffffff) {
        param_3 = (LPCWSTR)SendMessageW((HWND)param_1[1],0x150,param_2,0);
      }
    }
    else if (param_2 == 0xffffffff) {
      param_2 = FUN_405f7f90((undefined4 *)param_1[0x8a],param_3);
    }
    param_1[0x8c] = 0;
    if (((param_3 != (LPCWSTR)0x0) && (param_2 != 0xffffffff)) &&
       (iVar1 = FUN_405f4ab4((int)param_1,param_3), iVar1 != 0)) break;
    if (param_4 == 0) {
      FUN_405f80f4((undefined4 *)param_1[0x8b]);
      SendMessageW((HWND)param_1[1],0x14e,0xffffffff,0);
      pHVar2 = GetDlgItem((HWND)*param_1,0x29d);
      EnableWindow(pHVar2,0);
      pHVar2 = GetDlgItem((HWND)*param_1,0x29c);
      EnableWindow(pHVar2,0);
      return 0;
    }
    param_4 = 0;
    param_2 = 0xffffffff;
    param_3 = L".DefaultSounds";
  }
  pHVar2 = GetDlgItem((HWND)*param_1,0x29c);
  EnableWindow(pHVar2,1);
  iVar1 = CompareStringW(0x409,1,param_3,-1,L".DefaultSounds",-1);
  if ((iVar1 != 2) && (iVar1 = CompareStringW(0x409,1,param_3,-1,L".NoSounds",-1), iVar1 != 2)) {
    iVar1 = CompareStringW(0x409,1,param_3,-1,L".AllSounds",-1);
    bEnable = 1;
    if (iVar1 != 2) goto LAB_405f5428;
  }
  bEnable = 0;
LAB_405f5428:
  pHVar2 = GetDlgItem((HWND)*param_1,0x29d);
  EnableWindow(pHVar2,bEnable);
  SendMessageW((HWND)param_1[1],0x14e,param_2,0);
  return 1;
}



/* 405f54d8 FUN_405f54d8 */

/* Boundary evidence: original MIPS .pdata 405f54d8..405f551f. Semantic name remains unreviewed. */

void FUN_405f54d8(undefined4 *param_1)

{
  WPARAM WVar1;
  
  WVar1 = SendMessageW((HWND)param_1[1],0x147,0,0);
  FUN_405f52b8(param_1,WVar1,(LPCWSTR)0x0,1);
  return;
}



/* 405f5520 FUN_405f5520 */

/* Boundary evidence: original MIPS .pdata 405f5520..405f5623. Semantic name remains unreviewed. */

void FUN_405f5520(undefined4 *param_1)

{
  WPARAM WVar1;
  LPCWSTR lpCaption;
  LPCWSTR lpText;
  int iVar2;
  HWND hWnd;
  
  WVar1 = SendMessageW((HWND)param_1[1],0x147,0,0);
  if (WVar1 != 0xffffffff) {
    lpCaption = (LPCWSTR)LoadStringW(DAT_405fb7fc,0x8181,(LPWSTR)0x0,0);
    lpText = (LPCWSTR)LoadStringW(DAT_405fb7fc,0x8175,(LPWSTR)0x0,0);
    iVar2 = MessageBoxW((HWND)*param_1,lpText,lpCaption,0x34);
    if (iVar2 == 6) {
      FUN_405f4d64((int)param_1,WVar1);
      WVar1 = FUN_405f7f90((undefined4 *)param_1[0x8a],L".NoSounds");
      if (WVar1 == 0xffffffff) {
        WVar1 = 0;
      }
      FUN_405f52b8(param_1,WVar1,(LPCWSTR)0x0,1);
    }
    hWnd = GetDlgItem((HWND)*param_1,0x29b);
    SetFocus(hWnd);
  }
  return;
}



/* 405f5624 FUN_405f5624 */

/* Boundary evidence: original MIPS .pdata 405f5624..405f56a7. Semantic name remains unreviewed. */

void FUN_405f5624(undefined4 *param_1,wchar_t *param_2)

{
  WPARAM WVar1;
  WCHAR aWStack_38 [16];
  uint local_18;
  
  local_18 = DAT_405fb760;
  FUN_405f51b4(param_2,aWStack_38);
  FUN_405f4eb8((int)param_1,param_2,aWStack_38);
  WVar1 = FUN_405f8d64((undefined4 *)param_1[0x8a],(LPARAM)param_2,aWStack_38);
  FUN_405f52b8(param_1,WVar1,(LPCWSTR)0x0,1);
  FUN_405f9bec(local_18);
  return;
}



/* 405f56a8 FUN_405f56a8 */

/* Boundary evidence: original MIPS .pdata 405f56a8..405f5acf. Semantic name remains unreviewed. */

undefined4 FUN_405f56a8(HWND param_1,int param_2,int param_3,undefined4 *param_4)

{
  HWND pHVar1;
  STRSAFE_LPCWSTR pszFormat;
  LPCWSTR pWVar2;
  WPARAM wParam;
  PCNZWCH lpString1;
  int iVar3;
  INT_PTR nResult;
  LPWSTR lpString;
  short *lParam;
  undefined4 *puVar4;
  wchar_t awStack_238 [260];
  uint local_30;
  
  local_30 = DAT_405fb760;
  if (param_2 == 0x53) {
    CreateProcessW(L"peghelp",L"file:ctpnl.htm#change_event_sounds",(LPSECURITY_ATTRIBUTES)0x0,
                   (LPSECURITY_ATTRIBUTES)0x0,0,0,(LPVOID)0x0,(LPCWSTR)0x0,(LPSTARTUPINFOW)0x0,
                   (LPPROCESS_INFORMATION)0x0);
LAB_405f5a94:
    FUN_405f9bec(local_30);
    return 0;
  }
  if (param_2 == 0x110) {
    FUN_405f7658(param_1,1);
    DAT_405fb990 = param_4;
    pHVar1 = GetDlgItem(param_1,0x29e);
    SendMessageW(pHVar1,0xc5,0x25,0);
    SetWindowTextW(pHVar1,(LPCWSTR)(DAT_405fb990 + 0x8d));
    SetFocus(pHVar1);
    SendMessageW(pHVar1,0xb1,0,-1);
    goto LAB_405f5a94;
  }
  if (param_2 != 0x111) goto LAB_405f5a94;
  if (param_3 == 1) {
    lpString = (LPWSTR)(DAT_405fb990 + 0x8d);
    pHVar1 = GetDlgItem(param_1,0x29e);
    GetWindowTextW(pHVar1,lpString,0x104);
    lParam = (short *)(DAT_405fb990 + 0x8d);
    if (*lParam == 0) {
      pszFormat = (STRSAFE_LPCWSTR)LoadStringW(DAT_405fb7fc,0x8173,(LPWSTR)0x0,0);
      StringCbPrintfW(awStack_238,0x208,pszFormat,lParam);
      pWVar2 = (LPCWSTR)LoadStringW(DAT_405fb7fc,0x8182,(LPWSTR)0x0,0);
      MessageBoxW(param_1,awStack_238,pWVar2,0x31);
      goto LAB_405f57b8;
    }
    wParam = SendMessageW((HWND)DAT_405fb990[1],0x158,0xffffffff,(LPARAM)lParam);
    if (wParam != 0xffffffff) {
      lpString1 = (PCNZWCH)SendMessageW((HWND)DAT_405fb990[1],0x150,wParam,0);
      if ((lpString1 == (PCNZWCH)0x0) ||
         (((iVar3 = CompareStringW(0x409,1,lpString1,-1,L".DefaultSounds",-1), iVar3 != 2 &&
           (iVar3 = CompareStringW(0x409,1,lpString1,-1,L".NoSounds",-1), iVar3 != 2)) &&
          (iVar3 = CompareStringW(0x409,1,lpString1,-1,L".AllSounds",-1), iVar3 != 2)))) {
        puVar4 = DAT_405fb990 + 0x8d;
        pWVar2 = (LPCWSTR)LoadStringW(DAT_405fb7fc,0x8174,(LPWSTR)0x0,0);
        wsprintfW(awStack_238,pWVar2,puVar4);
        pWVar2 = (LPCWSTR)LoadStringW(DAT_405fb7fc,0x8182,(LPWSTR)0x0,0);
        iVar3 = MessageBoxW(param_1,awStack_238,pWVar2,0x33);
        if (iVar3 == 6) {
          FUN_405f4d64((int)DAT_405fb990,wParam);
          FUN_405f5624(DAT_405fb990,(wchar_t *)(DAT_405fb990 + 0x8d));
          EndDialog(param_1,1);
          goto LAB_405f5a94;
        }
      }
      else {
        puVar4 = DAT_405fb990 + 0x8d;
        pWVar2 = (LPCWSTR)LoadStringW(DAT_405fb7fc,0x8173,(LPWSTR)0x0,0);
        wsprintfW(awStack_238,pWVar2,puVar4);
        pWVar2 = (LPCWSTR)LoadStringW(DAT_405fb7fc,0x8182,(LPWSTR)0x0,0);
        MessageBoxW(param_1,awStack_238,pWVar2,0x31);
      }
      pHVar1 = GetDlgItem(param_1,0x29e);
      SetFocus(pHVar1);
      pHVar1 = GetDlgItem(param_1,0x29e);
      SendMessageW(pHVar1,0xb1,0,-1);
      goto LAB_405f57b8;
    }
    FUN_405f5624(DAT_405fb990,(wchar_t *)(DAT_405fb990 + 0x8d));
    nResult = 1;
  }
  else {
    if (param_3 != 2) goto LAB_405f5a94;
    nResult = 0;
  }
  EndDialog(param_1,nResult);
LAB_405f57b8:
  FUN_405f9bec(local_30);
  return 1;
}



/* 405f5ad0 FUN_405f5ad0 */

/* Boundary evidence: original MIPS .pdata 405f5ad0..405f5bef. Semantic name remains unreviewed. */

void FUN_405f5ad0(int param_1)

{
  int iVar1;
  WPARAM wParam;
  wchar_t *pwVar2;
  WPARAM WVar3;
  
  if (*(int *)(param_1 + 0x230) == 0) {
    wParam = SendMessageW(*(HWND *)(param_1 + 4),0x147,0,0);
  }
  else {
    iVar1 = LoadStringW(DAT_405fb7fc,0x8204,(LPWSTR)0x0,0);
    wParam = FUN_405f8df0(*(undefined4 **)(param_1 + 0x228),iVar1,L"Curr0");
    pwVar2 = (wchar_t *)LoadStringW(DAT_405fb7fc,0x8204,(LPWSTR)0x0,0);
    FUN_405f4eb8(param_1,pwVar2,L"Curr0");
  }
  if (wParam != 0xffffffff) {
    pwVar2 = (wchar_t *)SendMessageW(*(HWND *)(param_1 + 4),0x150,wParam,0);
    FUN_405f4e44(param_1,pwVar2);
    iVar1 = LoadStringW(DAT_405fb7fc,0x8204,(LPWSTR)0x0,0);
    WVar3 = SendMessageW(*(HWND *)(param_1 + 4),0x158,0xffffffff,iVar1);
    if ((WVar3 != 0xffffffff) && (WVar3 != wParam)) {
      FUN_405f4d64(param_1,WVar3);
    }
  }
  return;
}



/* 405f5bf0 FUN_405f5bf0 */

/* Boundary evidence: original MIPS .pdata 405f5bf0..405f5edb. Semantic name remains unreviewed. */

undefined4 * FUN_405f5bf0(undefined4 *param_1,HWND param_2)

{
  int iVar1;
  HWND pHVar2;
  undefined4 *puVar3;
  LPCWSTR pWVar4;
  int *piVar5;
  UINT *pUVar6;
  HKEY apHStack_460 [4];
  HKEY apHStack_450 [4];
  BYTE aBStack_440 [528];
  WCHAR aWStack_230 [262];
  uint local_24;
  
  local_24 = DAT_405fb760;
  memset(param_1,0,0x494);
  pUVar6 = &DAT_405e34e8;
  *param_1 = param_2;
  piVar5 = param_1 + 0x110;
  do {
    iVar1 = LoadStringW(DAT_405fb7fc,*pUVar6,(LPWSTR)0x0,0);
    pUVar6 = pUVar6 + 1;
    *piVar5 = iVar1;
    piVar5 = piVar5 + 1;
  } while ((int)pUVar6 < 0x405e353c);
  pHVar2 = GetDlgItem(param_2,0x29b);
  param_1[1] = pHVar2;
  pHVar2 = GetDlgItem(param_2,0x297);
  param_1[2] = pHVar2;
  pHVar2 = GetDlgItem(param_2,0x295);
  param_1[3] = pHVar2;
  puVar3 = operator_new(8);
  if (puVar3 == (undefined4 *)0x0) {
    puVar3 = (undefined4 *)0x0;
  }
  else {
    pHVar2 = GetDlgItem(param_2,0x297);
    *puVar3 = pHVar2;
  }
  param_1[0x89] = puVar3;
  puVar3 = operator_new(8);
  if (puVar3 == (undefined4 *)0x0) {
    puVar3 = (undefined4 *)0x0;
  }
  else {
    pHVar2 = GetDlgItem(param_2,0x29b);
    *puVar3 = pHVar2;
  }
  param_1[0x8a] = puVar3;
  puVar3 = operator_new(4);
  if (puVar3 == (undefined4 *)0x0) {
    puVar3 = (undefined4 *)0x0;
  }
  else {
    pHVar2 = GetDlgItem(param_2,0x295);
    *puVar3 = pHVar2;
  }
  param_1[0x8b] = puVar3;
  FUN_405f7c50(param_1 + 4,1,(ushort *)&DAT_405e353c,3);
  SendMessageW((HWND)param_1[3],0x1109,0,param_1[4]);
  FUN_405f49a8((HWND)*param_1,(int *)&DAT_405e3548,6,0);
  wcscpy((wchar_t *)(param_1 + 5),L"\\Windows");
  FUN_405f8bd4((undefined4 *)param_1[0x89],(wchar_t *)(param_1 + 5),0x405e3630);
  iVar1 = LoadStringW(DAT_405fb7fc,0x8508,(LPWSTR)0x0,0);
  FUN_405f8cd4((undefined4 *)param_1[0x89],iVar1,(wchar_t *)0x0,0);
  FUN_405e3fc4(apHStack_460,(HKEY)0x80000002,L"Snd\\Scheme");
  iVar1 = FUN_405e6400(apHStack_460,aWStack_230,0x104,aBStack_440,0x104);
  while (iVar1 != 0) {
    FUN_405f8d64((undefined4 *)param_1[0x8a],(LPARAM)aBStack_440,aWStack_230);
    iVar1 = FUN_405e6400(apHStack_460,aWStack_230,0x104,aBStack_440,0x104);
  }
  FUN_405e3fc4(apHStack_450,(HKEY)0x80000002,L"Snd\\Event");
  pWVar4 = (LPCWSTR)FUN_405f7da0(apHStack_450,L".Scheme");
  iVar1 = FUN_405e4194(apHStack_450,L"EventMask",0);
  param_1[0x88] = iVar1;
  if (iVar1 == 0) {
    param_1[0x88] = 0xffffffff;
  }
  FUN_405f52b8(param_1,0xffffffff,pWVar4,1);
  FUN_405e4020(apHStack_450);
  FUN_405e4020(apHStack_460);
  FUN_405f9bec(local_24);
  return param_1;
}



/* 405f5edc FUN_405f5edc */

/* Boundary evidence: original MIPS .pdata 405f5edc..405f5f83. Semantic name remains unreviewed. */

void FUN_405f5edc(undefined4 *param_1)

{
  WPARAM wParam;
  HRSRC hResInfo;
  LPCDLGTEMPLATEW hDialogTemplate;
  
  wParam = SendMessageW((HWND)param_1[1],0x147,0,0);
  if (wParam != 0xffffffff) {
    SendMessageW((HWND)param_1[1],0x148,wParam,(LPARAM)(param_1 + 0x8d));
    hResInfo = FindResourceW(DAT_405fb7fc,(LPCWSTR)0xd4,(LPCWSTR)0x5);
    hDialogTemplate = LoadResource(DAT_405fb7fc,hResInfo);
    DialogBoxIndirectParamW
              (DAT_405fb7fc,hDialogTemplate,(HWND)*param_1,FUN_405f56a8,(LPARAM)param_1);
  }
  return;
}



/* 405f5f84 SndSchemeDlgProc */

/* Boundary evidence: original MIPS .pdata 405f5f84..405f6313. Semantic name remains unreviewed. */

undefined4 SndSchemeDlgProc(HWND param_1,int param_2,uint param_3,int param_4)

{
  undefined4 *puVar1;
  uint uVar2;
  
                    /* 0x15f84  24  SndSchemeDlgProc */
  puVar1 = DAT_405fb99c;
  if (param_2 == 2) {
    if (DAT_405fb99c != (undefined4 *)0x0) {
      FUN_405f4a1c(DAT_405fb99c);
      operator_delete(puVar1);
    }
  }
  else if (param_2 == 0x2b) {
    uVar2 = 0x13a0;
    if ((param_3 & 0xffff) != 0x299) {
      uVar2 = 0x140d;
    }
    FUN_405f7b00(param_4,uVar2);
  }
  else {
    if (param_2 != 0x4e) {
      if (param_2 == 0x110) {
        puVar1 = operator_new(0x494);
        if (puVar1 == (undefined4 *)0x0) {
          DAT_405fb99c = (undefined4 *)0x0;
        }
        else {
          DAT_405fb99c = FUN_405f5bf0(puVar1,param_1);
        }
        DAT_405fb998 = 0;
        DAT_405fb994 = 0;
      }
      else {
        if (param_2 != 0x111) {
          return 0;
        }
        uVar2 = param_3 & 0xffff;
        if (uVar2 < 0x29a) {
          if (uVar2 != 0x299) {
            if (uVar2 == 1) {
              FUN_405f5ad0((int)DAT_405fb99c);
            }
            else if (uVar2 != 2) {
              if (uVar2 == 0x297) {
                uVar2 = param_3 >> 0x10;
                if (uVar2 == 1) {
                  if (DAT_405fb998 != 0) {
                    return 1;
                  }
                }
                else {
                  if (uVar2 == 7) {
                    DAT_405fb998 = 1;
                    return 1;
                  }
                  if (uVar2 == 8) {
                    DAT_405fb998 = 0;
                  }
                  else if (uVar2 != 9) {
                    return 1;
                  }
                }
                FUN_405f4670(DAT_405fb99c);
                return 1;
              }
              if (uVar2 != 0x298) {
                return 0;
              }
              FUN_405f4708(DAT_405fb99c);
              return 1;
            }
            if (DAT_405fb99c[0x10f] != 0) {
              AudioUpdateFromRegistry();
              return 1;
            }
            return 1;
          }
          FUN_405f48f8(DAT_405fb99c);
        }
        else if (uVar2 == 0x29a) {
          sndPlaySoundW((LPCWSTR)0x0,0);
        }
        else {
          if (uVar2 == 0x29b) {
            uVar2 = param_3 >> 0x10;
            if (uVar2 == 1) {
              if (DAT_405fb994 != 0) {
                return 1;
              }
            }
            else {
              if (uVar2 == 7) {
                DAT_405fb994 = 1;
                return 1;
              }
              if (uVar2 == 8) {
                DAT_405fb994 = 0;
                return 1;
              }
              if (uVar2 != 9) {
                return 1;
              }
            }
            FUN_405f54d8(DAT_405fb99c);
            return 1;
          }
          if (uVar2 == 0x29c) {
            FUN_405f5edc(DAT_405fb99c);
          }
          else {
            if (uVar2 != 0x29d) {
              return 0;
            }
            FUN_405f5520(DAT_405fb99c);
          }
        }
      }
      return 1;
    }
    if (*(int *)(param_4 + 8) == -0x1c6) {
      if ((*(uint *)(param_4 + 0x40) & 0x40) == 0) {
        return 1;
      }
    }
    else if (*(int *)(param_4 + 8) == -0x1c3) {
      FUN_405f4cc8(DAT_405fb99c,*(undefined4 *)(param_4 + 0x38),*(int *)(param_4 + 0x3c));
    }
  }
  return 0;
}



/* 405f6314 FUN_405f6314 */

/* Boundary evidence: original MIPS .pdata 405f6314..405f63e7. Semantic name remains unreviewed. */

void FUN_405f6314(int param_1,HWND param_2)

{
  ushort uVar1;
  HWND pHVar2;
  uint uVar3;
  
  uVar1 = *(ushort *)(param_1 + 0x14);
  pHVar2 = GetDlgItem(param_2,0x28b);
  EnableWindow(pHVar2,(uint)uVar1);
  uVar1 = *(ushort *)(param_1 + 0x14);
  pHVar2 = GetDlgItem(param_2,0x28c);
  EnableWindow(pHVar2,(uint)uVar1);
  uVar1 = *(ushort *)(param_1 + 0x18);
  pHVar2 = GetDlgItem(param_2,0x28e);
  EnableWindow(pHVar2,(uint)uVar1);
  uVar1 = *(ushort *)(param_1 + 0x18);
  pHVar2 = GetDlgItem(param_2,0x28f);
  EnableWindow(pHVar2,(uint)uVar1);
  uVar3 = *(uint *)(param_1 + 0x1c);
  pHVar2 = GetDlgItem(param_2,0x288);
  EnableWindow(pHVar2,uVar3 & 2);
  return;
}



/* 405f63e8 FUN_405f63e8 */

/* Boundary evidence: original MIPS .pdata 405f63e8..405f6567. Semantic name remains unreviewed. */

void FUN_405f63e8(undefined4 *param_1,int param_2)

{
  HWND pHVar1;
  LRESULT LVar2;
  MMRESULT MVar3;
  int lParam;
  LPDWORD pdwVolume;
  uint uVar4;
  
  pHVar1 = GetDlgItem((HWND)*param_1,0x21e);
  LVar2 = SendMessageW(pHVar1,0x400,0,0);
  if (param_2 != 0) {
    if (param_1[9] != 0) {
      param_2 = -param_2;
    }
    lParam = LVar2 + param_2;
    if ((-1 < lParam) && (lParam < 6)) {
      pHVar1 = GetDlgItem((HWND)*param_1,0x21e);
      SendMessageW(pHVar1,0x405,1,lParam);
      LVar2 = lParam;
    }
  }
  if (param_1[9] != 0) {
    LVar2 = 5 - LVar2;
  }
  pdwVolume = param_1 + 8;
  uVar4 = (LVar2 * 0xffff) / 5;
  *pdwVolume = uVar4;
  uVar4 = uVar4 << 0x10 | uVar4 & 0xffff;
  *pdwVolume = uVar4;
  MVar3 = waveOutSetVolume((HWAVEOUT)0x0,uVar4);
  if (MVar3 == 0) {
    sndPlaySoundW(L"SystemDefault",0x10001);
  }
  else {
    *pdwVolume = 0;
    waveOutGetVolume((HWAVEOUT)0x0,pdwVolume);
    uVar4 = ((*pdwVolume & 0xffff) * 5) / 0xffff;
    if (param_1[9] != 0) {
      uVar4 = 5 - uVar4;
    }
    pHVar1 = GetDlgItem((HWND)*param_1,0x21e);
    SendMessageW(pHVar1,0x405,1,uVar4);
  }
  return;
}



/* 405f6568 FUN_405f6568 */

/* Boundary evidence: original MIPS .pdata 405f6568..405f660f. Semantic name remains unreviewed. */

void FUN_405f6568(undefined4 *param_1)

{
  MMRESULT MVar1;
  HWND hWnd;
  uint lParam;
  DWORD local_18 [2];
  
  local_18[0] = 0;
  MVar1 = waveOutGetVolume((HWAVEOUT)0x0,local_18);
  if ((MVar1 == 0) && (local_18[0] != param_1[8])) {
    param_1[8] = local_18[0];
    lParam = ((local_18[0] & 0xffff) * 5) / 0xffff;
    if (param_1[9] != 0) {
      lParam = 5 - lParam;
    }
    hWnd = GetDlgItem((HWND)*param_1,0x21e);
    SendMessageW(hWnd,0x405,1,lParam);
  }
  return;
}



/* 405f6610 FUN_405f6610 */

/* Boundary evidence: original MIPS .pdata 405f6610..405f6693. Semantic name remains unreviewed. */

void FUN_405f6610(HWND param_1,int param_2,int param_3,int *param_4)

{
  HWND pHVar1;
  tagRECT local_30;
  tagRECT local_20;
  
  pHVar1 = GetDlgItem(param_1,param_2);
  GetWindowRect(pHVar1,&local_30);
  pHVar1 = GetDlgItem(param_1,param_3);
  GetWindowRect(pHVar1,&local_20);
  *param_4 = local_20.left - local_30.left;
  param_4[1] = local_20.top - local_30.top;
  return;
}



/* 405f6694 FUN_405f6694 */

/* Boundary evidence: original MIPS .pdata 405f6694..405f678b. Semantic name remains unreviewed. */

void FUN_405f6694(HWND param_1,int *param_2,int param_3,int param_4,int param_5)

{
  HWND pHVar1;
  int nWidth;
  int nHeight;
  tagRECT local_30;
  
  if (0 < param_3) {
    do {
      pHVar1 = GetDlgItem(param_1,*param_2);
      GetWindowRect(pHVar1,&local_30);
      MapWindowPoints((HWND)0x0,param_1,(LPPOINT)&local_30,2);
      OffsetRect(&local_30,param_4,param_5);
      nHeight = local_30.bottom - local_30.top;
      nWidth = local_30.right - local_30.left;
      pHVar1 = GetDlgItem(param_1,*param_2);
      MoveWindow(pHVar1,local_30.left,local_30.top,nWidth,nHeight,1);
      param_2 = param_2 + 1;
      param_3 = param_3 + -1;
    } while (param_3 != 0);
  }
  return;
}



/* 405f678c FUN_405f678c */

/* Boundary evidence: original MIPS .pdata 405f678c..405f687b. Semantic name remains unreviewed. */

void FUN_405f678c(int param_1)

{
  undefined4 uVar1;
  LPDWORD pdwVolume;
  HKEY apHStack_30 [4];
  HKEY apHStack_20 [4];
  
  FUN_405e3fc4(apHStack_30,(HKEY)0x80000001,L"ControlPanel\\Volume");
  uVar1 = FUN_405e4194(apHStack_30,L"Key",0);
  *(undefined4 *)(param_1 + 0x14) = uVar1;
  *(undefined4 *)(param_1 + 4) = uVar1;
  uVar1 = FUN_405e4194(apHStack_30,L"Screen",0);
  *(undefined4 *)(param_1 + 0x18) = uVar1;
  *(undefined4 *)(param_1 + 8) = uVar1;
  uVar1 = FUN_405e4194(apHStack_30,L"Mute",0);
  pdwVolume = (LPDWORD)(param_1 + 0x20);
  *(undefined4 *)(param_1 + 0x1c) = uVar1;
  *(undefined4 *)(param_1 + 0xc) = uVar1;
  *pdwVolume = 0;
  waveOutGetVolume((HWAVEOUT)0x0,pdwVolume);
  *(DWORD *)(param_1 + 0x10) = *pdwVolume;
  FUN_405e3fc4(apHStack_20,(HKEY)0x80000002,L"ControlPanel");
  uVar1 = FUN_405e4194(apHStack_20,L"InputConfig",0);
  *(undefined4 *)(param_1 + 0x28) = uVar1;
  FUN_405e4020(apHStack_20);
  FUN_405e4020(apHStack_30);
  return;
}



/* 405f687c FUN_405f687c */

/* Boundary evidence: original MIPS .pdata 405f687c..405f694f. Semantic name remains unreviewed. */

void FUN_405f687c(int param_1,int param_2)

{
  HKEY local_18;
  undefined4 local_14;
  undefined4 local_10;
  
  local_18 = (HKEY)0x0;
  local_14 = 0;
  local_10 = 0;
  if (param_2 != 0) {
    *(undefined4 *)(param_1 + 0x14) = *(undefined4 *)(param_1 + 4);
    *(undefined4 *)(param_1 + 0x18) = *(undefined4 *)(param_1 + 8);
    *(undefined4 *)(param_1 + 0x1c) = *(undefined4 *)(param_1 + 0xc);
    *(undefined4 *)(param_1 + 0x20) = *(undefined4 *)(param_1 + 0x10);
  }
  FUN_405e3f58(&local_18,(HKEY)0x80000001,L"ControlPanel\\Volume");
  FUN_405e4618(&local_18,L"Key",*(undefined4 *)(param_1 + 0x14));
  FUN_405e4618(&local_18,L"Screen",*(undefined4 *)(param_1 + 0x18));
  FUN_405e4618(&local_18,L"Mute",*(undefined4 *)(param_1 + 0x1c));
  FUN_405e4618(&local_18,L"Volume",*(undefined4 *)(param_1 + 0x20));
  waveOutSetVolume((HWAVEOUT)0x0,*(DWORD *)(param_1 + 0x20));
  AudioUpdateFromRegistry();
  FUN_405e4020(&local_18);
  return;
}



/* 405f6950 FUN_405f6950 */

/* Boundary evidence: original MIPS .pdata 405f6950..405f6d1b. Semantic name remains unreviewed. */

void FUN_405f6950(undefined4 *param_1)

{
  ushort uVar1;
  HWND pHVar2;
  LPCWSTR lpString;
  int iVar3;
  int iVar4;
  uint uVar5;
  int iStack_30;
  int local_2c;
  tagRECT local_28;
  
  pHVar2 = GetDlgItem((HWND)*param_1,0x21e);
  GetWindowRect(pHVar2,&local_28);
  param_1[9] = (uint)(local_28.right - local_28.left < local_28.bottom - local_28.top);
  SendMessageW(pHVar2,0x406,1,0x50000);
  SendMessageW(pHVar2,0x414,1,0);
  SendMessageW(pHVar2,0x415,0,1);
  iVar4 = 5;
  uVar5 = ((param_1[8] & 0xffff) * 5) / 0xffff;
  if (param_1[9] != 0) {
    uVar5 = 5 - uVar5;
  }
  SendMessageW(pHVar2,0x405,1,uVar5);
  uVar1 = *(ushort *)(param_1 + 5);
  pHVar2 = GetDlgItem((HWND)*param_1,0x28a);
  SendMessageW(pHVar2,0xf1,(uint)uVar1,0);
  uVar5 = param_1[5];
  pHVar2 = GetDlgItem((HWND)*param_1,0x28b);
  SendMessageW(pHVar2,0xf1,uVar5 & 0x10002,0);
  uVar5 = param_1[5];
  pHVar2 = GetDlgItem((HWND)*param_1,0x28c);
  SendMessageW(pHVar2,0xf1,(uint)((uVar5 & 0x10002) == 0),0);
  uVar1 = *(ushort *)(param_1 + 6);
  pHVar2 = GetDlgItem((HWND)*param_1,0x28d);
  SendMessageW(pHVar2,0xf1,(uint)uVar1,0);
  uVar5 = param_1[6];
  pHVar2 = GetDlgItem((HWND)*param_1,0x28e);
  SendMessageW(pHVar2,0xf1,uVar5 & 0x10002,0);
  uVar5 = param_1[6];
  pHVar2 = GetDlgItem((HWND)*param_1,0x28f);
  SendMessageW(pHVar2,0xf1,(uint)((uVar5 & 0x10002) == 0),0);
  iVar3 = 5;
  if ((param_1[10] & 5) == 0) {
    iVar3 = 0;
  }
  FUN_405e6844((HWND)*param_1,(int *)&DAT_405e363c,3,iVar3);
  if ((param_1[10] & 2) == 0) {
    iVar4 = 0;
  }
  FUN_405e6844((HWND)*param_1,(int *)&DAT_405e3648,3,iVar4);
  if (((param_1[10] & 5) == 0) && ((param_1[10] & 2) != 0)) {
    FUN_405f6610((HWND)*param_1,0x28d,0x28a,&iStack_30);
    FUN_405f6694((HWND)*param_1,(int *)&DAT_405e3648,3,0,local_2c);
  }
  if (((param_1[10] & 5) == 0) && ((param_1[10] & 2) == 0)) {
    pHVar2 = GetDlgItem((HWND)*param_1,0x289);
    ShowWindow(pHVar2,0);
  }
  if ((param_1[10] & 4) != 0) {
    lpString = (LPCWSTR)LoadStringW(DAT_405fb7fc,0x8166,(LPWSTR)0x0,0);
    pHVar2 = GetDlgItem((HWND)*param_1,0x28a);
    SetWindowTextW(pHVar2,lpString);
  }
  uVar5 = param_1[7];
  pHVar2 = GetDlgItem((HWND)*param_1,0x286);
  SendMessageW(pHVar2,0xf1,uVar5 & 4,0);
  uVar5 = param_1[7];
  pHVar2 = GetDlgItem((HWND)*param_1,0x287);
  SendMessageW(pHVar2,0xf1,uVar5 & 2,0);
  uVar5 = param_1[7];
  pHVar2 = GetDlgItem((HWND)*param_1,0x288);
  SendMessageW(pHVar2,0xf1,(uint)((uVar5 & 3) == 3),0);
  FUN_405f6314((int)param_1,(HWND)*param_1);
  return;
}



/* 405f6d1c FUN_405f6d1c */

/* Boundary evidence: original MIPS .pdata 405f6d1c..405f6dd7. Semantic name remains unreviewed. */

void FUN_405f6d1c(undefined4 *param_1,int param_2)

{
  HWND hWnd;
  LRESULT LVar1;
  uint uVar2;
  
  uVar2 = 0;
  if (param_2 == 0x286) {
    uVar2 = 4;
  }
  else if (param_2 == 0x287) {
    uVar2 = 2;
  }
  else if (param_2 == 0x288) {
    uVar2 = 1;
  }
  hWnd = GetDlgItem((HWND)*param_1,param_2);
  LVar1 = SendMessageW(hWnd,0xf0,0,0);
  if (LVar1 == 0) {
    param_1[7] = ~uVar2 & param_1[7];
  }
  else {
    param_1[7] = param_1[7] | uVar2;
  }
  FUN_405f6314((int)param_1,(HWND)*param_1);
  FUN_405f687c((int)param_1,0);
  return;
}



/* 405f6dd8 FUN_405f6dd8 */

/* Boundary evidence: original MIPS .pdata 405f6dd8..405f6f0b. Semantic name remains unreviewed. */

void FUN_405f6dd8(undefined4 *param_1,int param_2)

{
  bool bVar1;
  HWND pHVar2;
  LRESULT LVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  int nIDDlgItem;
  
  uVar5 = 1;
  nIDDlgItem = 0x28b;
  if (((param_2 == 0x28a) || (param_2 == 0x28b)) || (param_2 == 0x28c)) {
    bVar1 = true;
    puVar4 = param_1 + 5;
  }
  else {
    bVar1 = false;
    puVar4 = param_1 + 6;
  }
  if ((param_2 == 0x28a) || (param_2 == 0x28d)) {
    pHVar2 = GetDlgItem((HWND)*param_1,param_2);
    LVar3 = SendMessageW(pHVar2,0xf0,0,0);
    if (LVar3 == 0) {
      *(undefined2 *)puVar4 = 0;
      goto LAB_405f6ed4;
    }
    if (!bVar1) {
      nIDDlgItem = 0x28e;
    }
    pHVar2 = GetDlgItem((HWND)*param_1,nIDDlgItem);
    LVar3 = SendMessageW(pHVar2,0xf0,0,0);
    if (LVar3 != 0) {
      uVar5 = 0x10002;
    }
  }
  else if ((param_2 != 0x28c) && (param_2 != 0x28f)) {
    *puVar4 = 0x10002;
    goto LAB_405f6ed4;
  }
  *puVar4 = uVar5;
LAB_405f6ed4:
  FUN_405f6314((int)param_1,(HWND)*param_1);
  FUN_405f687c((int)param_1,0);
  return;
}



/* 405f6f0c VolumeDlgProc */

/* Boundary evidence: original MIPS .pdata 405f6f0c..405f723b. Semantic name remains unreviewed. */

undefined4 VolumeDlgProc(HWND param_1,uint param_2,uint param_3,int param_4)

{
  HWND hWnd;
  UINT UVar1;
  undefined4 *_Dst;
  uint uVar2;
  int iVar3;
  WCHAR aWStack_120 [128];
  uint local_20;
  
                    /* 0x16f0c  27  VolumeDlgProc */
  local_20 = DAT_405fb760;
  if (((DAT_405fb9a0 == (undefined4 *)0x0) && (param_2 != 0x110)) && (param_2 != 0x15)) {
LAB_405f6f60:
    FUN_405f9bec(local_20);
    return 0;
  }
  if (param_2 < 0x2c) {
    if (param_2 == 0x2b) {
      if (DAT_405fb9a0[9] == 0) {
        uVar2 = 0x13a0;
        if ((param_3 & 0xffff) != 0x281) {
          uVar2 = 0x139f;
        }
      }
      else {
        uVar2 = 0x1400;
        if ((param_3 & 0xffff) != 0x281) {
          uVar2 = 0x1401;
        }
      }
      FUN_405f7b00(param_4,uVar2);
    }
    else if (param_2 == 2) {
      operator_delete(DAT_405fb9a0);
      DAT_405fb9a0 = (undefined4 *)0x0;
    }
    else if (param_2 == 6) {
      if ((param_3 & 0xffff) != 0) {
        FUN_405f6568(DAT_405fb9a0);
      }
    }
    else if (param_2 == 0x15) {
      hWnd = GetDlgItem(param_1,0x21e);
      SendMessageW(hWnd,0x15,param_3,param_4);
    }
    goto LAB_405f6f60;
  }
  if (param_2 == 0x110) {
    UVar1 = waveOutGetNumDevs();
    if (UVar1 == 0) {
      waveOutGetErrorText(6,aWStack_120,0x80);
      MessageBoxW(param_1,aWStack_120,(LPCWSTR)0x0,0x30);
      DestroyWindow(param_1);
    }
    else {
      _Dst = operator_new(0x2c);
      if (_Dst == (undefined4 *)0x0) {
        _Dst = (undefined4 *)0x0;
      }
      else {
        memset(_Dst,0,0x2c);
        *_Dst = param_1;
      }
      DAT_405fb9a0 = _Dst;
      if (_Dst != (undefined4 *)0x0) {
        FUN_405f678c((int)_Dst);
        FUN_405f6950(DAT_405fb9a0);
      }
    }
    goto LAB_405f7210;
  }
  if (param_2 != 0x111) {
    if (((0x113 < param_2) && (param_2 < 0x116)) &&
       ((uVar2 = param_3 & 0xffff, uVar2 < 5 || ((5 < uVar2 && (uVar2 < 8)))))) {
      FUN_405f63e8(DAT_405fb9a0,0);
    }
    goto LAB_405f6f60;
  }
  uVar2 = param_3 & 0xffff;
  if (0x284 < uVar2) {
    if (0x285 < uVar2) {
      if (uVar2 < 0x289) {
        FUN_405f6d1c(DAT_405fb9a0,uVar2);
      }
      else {
        if ((uVar2 < 0x28a) || (0x28f < uVar2)) goto LAB_405f6f60;
        FUN_405f6dd8(DAT_405fb9a0,uVar2);
      }
LAB_405f7210:
      FUN_405f9bec(local_20);
      return 1;
    }
    goto LAB_405f6f60;
  }
  if (uVar2 == 0x284) {
LAB_405f70f4:
    iVar3 = 1;
    if (uVar2 != 0x281) {
      iVar3 = -1;
    }
    FUN_405f63e8(DAT_405fb9a0,iVar3);
  }
  else {
    if (uVar2 == 1) {
      iVar3 = 0;
    }
    else {
      if (uVar2 != 2) {
        if (uVar2 != 0x281) goto LAB_405f6f60;
        goto LAB_405f70f4;
      }
      iVar3 = 1;
    }
    FUN_405f687c((int)DAT_405fb9a0,iVar3);
  }
  FUN_405f9bec(local_20);
  return 1;
}



/* 405f723c FUN_405f723c */

/* Boundary evidence: original MIPS .pdata 405f723c..405f72df. Semantic name remains unreviewed. */

undefined4 FUN_405f723c(void)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_405fb7c8);
  if (DAT_405fb800 == (HMODULE)0x0) {
    DAT_405fb800 = LoadLibraryW(L"aygshell.dll");
    if (DAT_405fb800 != (HMODULE)0x0) {
      DAT_405fb80c = DAT_405fb80c + 1;
      uVar1 = 1;
      DAT_405fb808 = 1;
    }
  }
  else {
    DAT_405fb80c = DAT_405fb80c + 1;
    uVar1 = 1;
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_405fb7c8);
  return uVar1;
}



/* 405f72e0 FUN_405f72e0 */

/* Boundary evidence: original MIPS .pdata 405f72e0..405f7377. Semantic name remains unreviewed. */

undefined4 FUN_405f72e0(void)

{
  undefined4 uVar1;
  
  if (DAT_405fb808 == 0) {
    uVar1 = 0;
  }
  else {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_405fb7c8);
    DAT_405fb80c = DAT_405fb80c + -1;
    if (DAT_405fb80c < 1) {
      FreeLibrary(DAT_405fb800);
      DAT_405fb800 = (HMODULE)0x0;
      DAT_405fb804 = 0;
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_405fb7c8);
    uVar1 = 1;
  }
  return uVar1;
}



/* 405f7378 FUN_405f7378 */

/* Boundary evidence: original MIPS .pdata 405f7378..405f742b. Semantic name remains unreviewed. */

undefined4 FUN_405f7378(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  code *pcVar2;
  undefined4 uVar3;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  
  local_20 = 0;
  uVar3 = 0;
  memset(&local_1c,0,8);
  iVar1 = FUN_405f723c();
  if (iVar1 != 0) {
    local_20 = 1;
    local_1c = param_1;
    local_18 = param_2;
    pcVar2 = (code *)GetProcAddressW(DAT_405fb800,L"SHInitDialog");
    if (pcVar2 != (code *)0x0) {
      uVar3 = (*pcVar2)(&local_20);
    }
    iVar1 = FUN_405f72e0();
    if (iVar1 != 0) {
      return uVar3;
    }
  }
  return 0;
}



/* 405f742c FUN_405f742c */

/* Boundary evidence: original MIPS .pdata 405f742c..405f74af. Semantic name remains unreviewed. */

int FUN_405f742c(void)

{
  int iVar1;
  code *pcVar2;
  int iVar3;
  
  iVar3 = 0;
  iVar1 = DAT_405fb804;
  if (DAT_405fb800 == 0) {
    iVar3 = 0;
  }
  else if (DAT_405fb804 == 0) {
    pcVar2 = (code *)GetProcAddressW(DAT_405fb800,L"SHInitExtraControls");
    iVar1 = iVar3;
    if (pcVar2 != (code *)0x0) {
      iVar3 = (*pcVar2)();
      iVar1 = iVar3;
    }
  }
  else {
    iVar3 = 1;
  }
  DAT_405fb804 = iVar1;
  return iVar3;
}



/* 405f74b0 FUN_405f74b0 */

/* Boundary evidence: original MIPS .pdata 405f74b0..405f756b. Semantic name remains unreviewed. */

undefined4 FUN_405f74b0(HWND param_1)

{
  int iVar1;
  BOOL BVar2;
  undefined4 uVar3;
  tagWNDCLASSW tStack_38;
  
  if (((DAT_405fb800 == 0) || (iVar1 = FUN_405f742c(), iVar1 == 0)) ||
     (BVar2 = GetClassInfoW(DAT_405fb7fc,L"SIPPREF",&tStack_38), BVar2 == 0)) {
    uVar3 = 0;
  }
  else {
    CreateWindowExW(0,L"SIPPREF",(LPCWSTR)0x0,0x40000000,-10,-10,5,5,param_1,(HMENU)0x0,DAT_405fb7fc
                    ,(LPVOID)0x0);
    uVar3 = 1;
  }
  return uVar3;
}



/* 405f756c FUN_405f756c */

/* Boundary evidence: original MIPS .pdata 405f756c..405f7657. Semantic name remains unreviewed. */

HANDLE FUN_405f756c(LPCWSTR param_1,LPCWSTR param_2,int param_3)

{
  HANDLE hObject;
  DWORD DVar1;
  HWND pHVar2;
  LPCWSTR lpWindowName;
  
  hObject = CreateMutexW((LPSECURITY_ATTRIBUTES)0x0,0,param_1);
  if (hObject != (HANDLE)0x0) {
    DVar1 = GetLastError();
    if (DVar1 != 0xb7) {
      return hObject;
    }
    CloseHandle(hObject);
    pHVar2 = FindWindowW(L"Dialog",param_2);
    if (pHVar2 != (HWND)0x0) {
LAB_405f75f4:
      SetForegroundWindow((HWND)((uint)pHVar2 | 1));
      return (HANDLE)0x0;
    }
    if (param_3 != 0) {
      lpWindowName = (LPCWSTR)LoadStringW(DAT_405fb7fc,0x8505,(LPWSTR)0x0,0);
      pHVar2 = FindWindowW(L"Dialog",lpWindowName);
      if (pHVar2 != (HWND)0x0) goto LAB_405f75f4;
    }
  }
  return (HANDLE)0xffffffff;
}



/* 405f7658 FUN_405f7658 */

/* Boundary evidence: original MIPS .pdata 405f7658..405f77d7. Semantic name remains unreviewed. */

BOOL FUN_405f7658(HWND param_1,int param_2)

{
  int iVar1;
  BOOL BVar2;
  int iVar3;
  int local_60;
  int local_5c;
  int local_58;
  int local_54;
  tagRECT local_50;
  undefined4 local_40;
  uint local_3c;
  int local_38;
  int local_34;
  int local_30;
  int local_2c;
  
  local_60 = 0;
  memset(&local_5c,0,0xc);
  GetWindowRect(param_1,&local_50);
  memset(&local_40,0,0x30);
  local_40 = 0x30;
  if (((DAT_405fb7ec == 0) || (DAT_405fb7e0 == (code *)0x0)) ||
     (iVar1 = (*DAT_405fb7e0)(&local_40), iVar1 == 0)) {
    SystemParametersInfoW(0x30,0,&local_60,0);
  }
  else {
    local_60 = local_38;
    local_5c = local_34;
    local_58 = local_30;
    local_54 = local_2c;
    if ((param_2 == 0) && ((local_3c & 1) == 0)) {
      return 0;
    }
  }
  iVar1 = ((local_50.left - local_50.right) - local_60) + local_58;
  if (iVar1 < 0) {
    iVar1 = iVar1 + 1;
  }
  iVar1 = iVar1 >> 1;
  iVar3 = ((local_50.top - local_50.bottom) - local_5c) + local_54;
  if (iVar3 < 0) {
    iVar3 = iVar3 + 1;
  }
  iVar3 = iVar3 >> 1;
  if (iVar1 < 0) {
    iVar1 = 0;
  }
  if (iVar3 < 0) {
    iVar3 = 0;
  }
  BVar2 = SetWindowPos(param_1,(HWND)0x0,iVar1 + local_60,local_5c + iVar3,0,0,5);
  return BVar2;
}



/* 405f77d8 FUN_405f77d8 */

/* Boundary evidence: original MIPS .pdata 405f77d8..405f7833. Semantic name remains unreviewed. */

undefined4 FUN_405f77d8(void)

{
  int iVar1;
  undefined4 local_38;
  undefined4 local_34;
  
  memset(&local_38,0,0x30);
  local_38 = 0x30;
  if ((DAT_405fb7e0 == (code *)0x0) || (iVar1 = (*DAT_405fb7e0)(&local_38), iVar1 == 0)) {
    local_34 = 0;
  }
  return local_34;
}



/* 405f7834 FUN_405f7834 */

/* Boundary evidence: original MIPS .pdata 405f7834..405f78d7. Semantic name remains unreviewed. */

void FUN_405f7834(int param_1)

{
  int iVar1;
  undefined4 local_40;
  uint local_3c;
  
  memset(&local_40,0,0x30);
  local_40 = 0x30;
  if (((DAT_405fb7e0 != (code *)0x0) && (DAT_405fb7dc != (code *)0x0)) &&
     (iVar1 = (*DAT_405fb7e0)(&local_40), iVar1 != 0)) {
    if (param_1 == 0) {
      local_3c = local_3c & 0xfffffffe;
    }
    else {
      local_3c = local_3c | 1;
    }
    (*DAT_405fb7dc)(&local_40);
  }
  return;
}



/* 405f78d8 FUN_405f78d8 */

/* Boundary evidence: original MIPS .pdata 405f78d8..405f7aff. Semantic name remains unreviewed. */

void FUN_405f78d8(int param_1,uint param_2,int param_3)

{
  HBITMAP h;
  HDC hdc;
  HGDIOBJ h_00;
  DWORD DVar1;
  COLORREF color;
  COLORREF CVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  HDC hdc_00;
  LPRECT lprc;
  undefined1 auStack_40 [4];
  int local_3c;
  int local_38;
  
  uVar3 = *(uint *)(param_1 + 0x10);
  hdc_00 = *(HDC *)(param_1 + 0x18);
  lprc = (LPRECT)(param_1 + 0x1c);
  h = LoadBitmapW(DAT_405fb7fc,(LPCWSTR)(param_2 & 0xffff));
  if (h != (HBITMAP)0x0) {
    hdc = CreateCompatibleDC(hdc_00);
    if (hdc != (HDC)0x0) {
      h_00 = SelectObject(hdc,h);
      GetObjectW(h,0x18,auStack_40);
      iVar4 = (*(int *)(param_1 + 0x24) - local_3c) + lprc->left;
      if (iVar4 < 0) {
        iVar4 = iVar4 + 1;
      }
      iVar4 = iVar4 >> 1;
      iVar5 = (*(int *)(param_1 + 0x28) + *(int *)(param_1 + 0x20)) - local_38;
      if (iVar5 < 0) {
        iVar5 = iVar5 + 1;
      }
      iVar5 = iVar5 >> 1;
      if ((uVar3 & 1) != 0) {
        iVar4 = iVar4 + 1;
        iVar5 = iVar5 + 1;
      }
      DVar1 = GetSysColor(0x4000000f);
      color = SetBkColor(hdc_00,DVar1);
      if (param_3 == 0) {
        DVar1 = GetSysColor(0x4000000f);
        if (DVar1 == 0) {
          CVar2 = 0xffffff;
        }
        else {
          CVar2 = 0;
        }
      }
      else {
        DVar1 = GetSysColor(0x4000000f);
        CVar2 = 0x808080;
        if (DVar1 == 0x808080) {
          CVar2 = 0xc0c0c0;
        }
      }
      CVar2 = SetTextColor(hdc_00,CVar2);
      BitBlt(hdc_00,iVar4,iVar5,local_3c,local_38,hdc,0,0,0xcc0020);
      SetBkColor(hdc_00,color);
      SetTextColor(hdc_00,CVar2);
      h = SelectObject(hdc,h_00);
      DeleteDC(hdc);
    }
    DeleteObject(h);
  }
  if ((uVar3 & 0x10) != 0) {
    InflateRect(lprc,-3,-3);
    DrawFocusRect(hdc_00,lprc);
  }
  return;
}



/* 405f7b00 FUN_405f7b00 */

/* Boundary evidence: original MIPS .pdata 405f7b00..405f7b83. Semantic name remains unreviewed. */

void FUN_405f7b00(int param_1,uint param_2)

{
  UINT edge;
  
  FillRect(*(HDC *)(param_1 + 0x18),(RECT *)(param_1 + 0x1c),(HBRUSH)0x40000010);
  edge = 10;
  if ((*(uint *)(param_1 + 0x10) & 1) == 0) {
    edge = 5;
  }
  DrawEdge(*(HDC *)(param_1 + 0x18),(RECT *)(param_1 + 0x1c),edge,0x100f);
  FUN_405f78d8(param_1,param_2,*(uint *)(param_1 + 0x10) & 4);
  return;
}



/* 405f7b84 FUN_405f7b84 */

/* Boundary evidence: original MIPS .pdata 405f7b84..405f7c4f. Semantic name remains unreviewed. */

void FUN_405f7b84(HWND param_1,UINT *param_2,int param_3)

{
  int lParam;
  WPARAM wParam;
  UINT UVar1;
  UINT *pUVar2;
  int iVar3;
  
  iVar3 = 0;
  UVar1 = *param_2;
  pUVar2 = param_2;
  while (UVar1 != 0) {
    lParam = LoadStringW(DAT_405fb7fc,*pUVar2,(LPWSTR)0x0,0);
    wParam = SendMessageW(param_1,0x143,0,lParam);
    if ((param_3 != 0) && (wParam != 0xffffffff)) {
      SendMessageW(param_1,0x151,wParam,pUVar2[1]);
    }
    iVar3 = iVar3 + 1;
    pUVar2 = param_2 + iVar3 * 2;
    UVar1 = *pUVar2;
  }
  return;
}



/* 405f7c50 FUN_405f7c50 */

/* Boundary evidence: original MIPS .pdata 405f7c50..405f7d9f. Semantic name remains unreviewed. */

void FUN_405f7c50(undefined4 *param_1,int param_2,ushort *param_3,int param_4)

{
  uint uVar1;
  uint uVar2;
  HIMAGELIST p_Var3;
  HICON hicon;
  int iVar4;
  
  if ((HIMAGELIST)*param_1 != (HIMAGELIST)0x0) {
    ImageList_Destroy((HIMAGELIST)*param_1);
    *param_1 = 0;
  }
  iVar4 = 0x31;
  if (param_2 == 0) {
    iVar4 = 0xb;
  }
  uVar1 = GetSystemMetrics(iVar4);
  iVar4 = 0x32;
  if (param_2 == 0) {
    iVar4 = 0xc;
  }
  uVar2 = GetSystemMetrics(iVar4);
  p_Var3 = ImageList_Create(uVar1 & 0xffff,uVar2 & 0xffff,1,param_4,2);
  *param_1 = p_Var3;
  if ((p_Var3 != (HIMAGELIST)0x0) && (0 < param_4)) {
    do {
      hicon = LoadImageW(DAT_405fb7fc,(LPCWSTR)(uint)*param_3,1,uVar1 & 0xffff,uVar2 & 0xffff,0);
      if (hicon != (HICON)0x0) {
        ImageList_ReplaceIcon((HIMAGELIST)*param_1,-1,hicon);
        DestroyIcon(hicon);
      }
      param_3 = param_3 + 2;
      param_4 = param_4 + -1;
    } while (param_4 != 0);
  }
  return;
}



/* 405f7da0 FUN_405f7da0 */

/* Boundary evidence: original MIPS .pdata 405f7da0..405f7e77. Semantic name remains unreviewed. */

undefined4 FUN_405f7da0(undefined4 *param_1,LPCWSTR param_2)

{
  LSTATUS LVar1;
  LPBYTE lpData;
  DWORD local_18 [2];
  
  if ((HKEY)*param_1 != (HKEY)0x0) {
    local_18[0] = 0;
    LVar1 = RegQueryValueExW((HKEY)*param_1,param_2,(LPDWORD)0x0,(LPDWORD)0x0,(LPBYTE)0x0,local_18);
    if ((LVar1 == 0) && (local_18[0] != 0)) {
      if ((HLOCAL)param_1[2] != (HLOCAL)0x0) {
        LocalFree((HLOCAL)param_1[2]);
      }
      lpData = LocalAlloc(0x40,local_18[0]);
      param_1[2] = lpData;
      if ((lpData != (LPBYTE)0x0) &&
         (LVar1 = RegQueryValueExW((HKEY)*param_1,param_2,(LPDWORD)0x0,(LPDWORD)0x0,lpData,local_18)
         , LVar1 == 0)) {
        return param_1[2];
      }
    }
  }
  return 0;
}



/* 405f7e78 FUN_405f7e78 */

/* Boundary evidence: original MIPS .pdata 405f7e78..405f7f1b. Semantic name remains unreviewed. */

void FUN_405f7e78(undefined4 *param_1)

{
  HLOCAL hMem;
  WPARAM wParam;
  
  wParam = 0;
  hMem = (HLOCAL)SendMessageW((HWND)*param_1,0x150,0,0);
  while (hMem != (HLOCAL)0xffffffff) {
    SendMessageW((HWND)*param_1,0x151,wParam,0);
    if (hMem != (HLOCAL)0x0) {
      LocalFree(hMem);
    }
    wParam = wParam + 1;
    hMem = (HLOCAL)SendMessageW((HWND)*param_1,0x150,wParam,0);
  }
  return;
}



/* 405f7f1c FUN_405f7f1c */

/* Boundary evidence: original MIPS .pdata 405f7f1c..405f7f8f. Semantic name remains unreviewed. */

void FUN_405f7f1c(undefined4 *param_1,WPARAM param_2)

{
  HLOCAL hMem;
  
  hMem = (HLOCAL)SendMessageW((HWND)*param_1,0x150,param_2,0);
  if ((hMem != (HLOCAL)0xffffffff) && (hMem != (HLOCAL)0x0)) {
    LocalFree(hMem);
  }
  SendMessageW((HWND)*param_1,0x144,param_2,0);
  return;
}



/* 405f7f90 FUN_405f7f90 */

/* Boundary evidence: original MIPS .pdata 405f7f90..405f803b. Semantic name remains unreviewed. */

WPARAM FUN_405f7f90(undefined4 *param_1,LPCWSTR param_2)

{
  LPCWSTR lpString2;
  int iVar1;
  WPARAM wParam;
  
  wParam = 0;
  lpString2 = (LPCWSTR)SendMessageW((HWND)*param_1,0x150,0,0);
  while( true ) {
    if (lpString2 == (LPCWSTR)0xffffffff) {
      return 0xffffffff;
    }
    iVar1 = lstrcmpiW(param_2,lpString2);
    if (iVar1 == 0) break;
    wParam = wParam + 1;
    lpString2 = (LPCWSTR)SendMessageW((HWND)*param_1,0x150,wParam,0);
  }
  return wParam;
}



/* 405f803c FUN_405f803c */

/* Boundary evidence: original MIPS .pdata 405f803c..405f8087. Semantic name remains unreviewed. */

void FUN_405f803c(undefined4 *param_1,undefined4 param_2)

{
  undefined4 local_30;
  undefined4 local_2c;
  HLOCAL local_c;
  
  local_30 = 4;
  local_c = (HLOCAL)0x0;
  local_2c = param_2;
  SendMessageW((HWND)*param_1,0x113e,0,(LPARAM)&local_30);
  if (local_c != (HLOCAL)0x0) {
    LocalFree(local_c);
  }
  return;
}



/* 405f8088 FUN_405f8088 */

/* Boundary evidence: original MIPS .pdata 405f8088..405f80f3. Semantic name remains unreviewed. */

void FUN_405f8088(undefined4 *param_1,LRESULT param_2)

{
  WPARAM wParam;
  
  FUN_405f803c(param_1,param_2);
  wParam = 4;
  while (param_2 = SendMessageW((HWND)*param_1,0x110a,wParam,param_2), param_2 != 0) {
    FUN_405f8088(param_1,param_2);
    wParam = 1;
  }
  return;
}



/* 405f80f4 FUN_405f80f4 */

/* Boundary evidence: original MIPS .pdata 405f80f4..405f816f. Semantic name remains unreviewed. */

void FUN_405f80f4(undefined4 *param_1)

{
  LRESULT LVar1;
  
  LVar1 = SendMessageW((HWND)*param_1,0x110a,0,0);
  FUN_405f8088(param_1,LVar1);
  SendMessageW((HWND)*param_1,0xb,0,0);
  SendMessageW((HWND)*param_1,0x1101,0,-0x10000);
  SendMessageW((HWND)*param_1,0xb,1,0);
  return;
}



/* 405f8170 FUN_405f8170 */

/* Boundary evidence: original MIPS .pdata 405f8170..405f81c3. Semantic name remains unreviewed. */

undefined4
FUN_405f8170(undefined4 *param_1,undefined4 param_2,undefined2 *param_3,undefined4 param_4)

{
  undefined4 local_30;
  undefined4 local_2c;
  undefined2 *local_20;
  undefined4 local_1c;
  undefined4 local_c;
  
  local_30 = 4;
  local_c = 0;
  if (param_3 != (undefined2 *)0x0) {
    *param_3 = 0;
    local_30 = 5;
    local_20 = param_3;
    local_1c = param_4;
  }
  local_2c = param_2;
  SendMessageW((HWND)*param_1,0x113e,0,(LPARAM)&local_30);
  return local_c;
}



/* 405f81c4 FUN_405f81c4 */

/* Boundary evidence: original MIPS .pdata 405f81c4..405f8267. Semantic name remains unreviewed. */

void FUN_405f81c4(wchar_t *param_1)

{
  size_t sVar1;
  int iVar2;
  wchar_t *pwVar3;
  
  sVar1 = wcslen(param_1);
  iVar2 = sVar1 - 1;
  if (-1 < iVar2) {
    pwVar3 = param_1 + iVar2;
    do {
      if (((*pwVar3 == L'\\') && (0 < iVar2)) && (iVar2 < (int)sVar1)) {
        memmove(param_1,param_1 + iVar2 + 1,(sVar1 - iVar2) * 2 + 2);
        param_1[(sVar1 - iVar2) + 1] = L'\0';
        return;
      }
      iVar2 = iVar2 + -1;
      pwVar3 = pwVar3 + -1;
    } while (-1 < iVar2);
  }
  return;
}



/* 405f8268 FUN_405f8268 */

/* Boundary evidence: original MIPS .pdata 405f8268..405f82d3. Semantic name remains unreviewed. */

void FUN_405f8268(wchar_t *param_1)

{
  size_t sVar1;
  int iVar2;
  wchar_t *pwVar3;
  
  sVar1 = wcslen(param_1);
  iVar2 = sVar1 - 1;
  if (-1 < iVar2) {
    pwVar3 = param_1 + iVar2;
    do {
      if (*pwVar3 == L'.') {
        param_1[iVar2] = L'\0';
        return;
      }
      iVar2 = iVar2 + -1;
      pwVar3 = pwVar3 + -1;
    } while (-1 < iVar2);
  }
  return;
}



/* 405f82d4 FUN_405f82d4 */

/* Boundary evidence: original MIPS .pdata 405f82d4..405f834f. Semantic name remains unreviewed. */

void FUN_405f82d4(wchar_t *param_1)

{
  int iVar1;
  int iVar2;
  
  FUN_405f81c4(param_1);
  FUN_405f8268(param_1);
  if (*param_1 != L'\0') {
    iVar1 = iswctype(param_1[1],1);
    iVar2 = iswctype(*param_1,1);
    if (iVar2 == iVar1) {
      CharLowerW(param_1);
      CharUpperBuffW(param_1,1);
    }
  }
  return;
}



/* 405f8350 FUN_405f8350 */

/* Boundary evidence: original MIPS .pdata 405f8350..405f83f3. Semantic name remains unreviewed. */

void FUN_405f8350(void)

{
  HKEY apHStack_18 [4];
  
  FUN_405e3fc4(apHStack_18,(HKEY)0x80000002,L"ControlPanel");
  DAT_405fb7f4 = FUN_405e4194(apHStack_18,L"NoDrag",0);
  DAT_405fb7f0 = FUN_405e4194(apHStack_18,L"FullScreen",0);
  DAT_405fb7ec = FUN_405e4194(apHStack_18,L"RecenterForSIP",0);
  DAT_405fb7e8 = FUN_405e4194(apHStack_18,L"RaiseLowerSIP",0);
  FUN_405e4020(apHStack_18);
  return;
}



/* 405f83f4 FUN_405f83f4 */

/* Boundary evidence: original MIPS .pdata 405f83f4..405f8533. Semantic name remains unreviewed. */

void FUN_405f83f4(HWND param_1,int param_2,UINT param_3)

{
  wchar_t *_Str;
  wchar_t *_Str_00;
  size_t sVar1;
  size_t sVar2;
  HKEY apHStack_30 [3];
  uint local_24;
  
  local_24 = DAT_405fb760;
  _Str = (wchar_t *)LoadStringW(DAT_405fb7fc,param_3,(LPWSTR)0x0,0);
  FUN_405e3fc4(apHStack_30,(HKEY)0x80000002,L"ControlPanel");
  _Str_00 = (wchar_t *)FUN_405f7da0(apHStack_30,L"DeviceName");
  if (((_Str_00 != (wchar_t *)0x0) ||
      (_Str_00 = (wchar_t *)LoadStringW(DAT_405fb7fc,0x8500,(LPWSTR)0x0,0),
      _Str_00 != (wchar_t *)0x0)) && (_Str != (wchar_t *)0x0)) {
    sVar1 = wcslen(_Str);
    sVar2 = wcslen(_Str_00);
    swprintf((wchar_t *)(apHStack_30 + ((int)((sVar2 + sVar1 + 2) * 2 + 7) >> 3) * -2),(size_t)_Str,
             _Str_00);
    SetDlgItemTextW(param_1,param_2,
                    (LPCWSTR)(apHStack_30 + ((int)((sVar2 + sVar1 + 2) * 2 + 7) >> 3) * -2));
  }
  FUN_405e4020(apHStack_30);
  FUN_405f9bec(local_24);
  return;
}



/* 405f8534 FUN_405f8534 */

/* Boundary evidence: original MIPS .pdata 405f8534..405f8753. Semantic name remains unreviewed. */

undefined4 FUN_405f8534(HWND param_1,int param_2,short param_3,LPCWSTR param_4)

{
  int iVar1;
  LPCWSTR pWVar2;
  HWND pHVar3;
  wchar_t *nResult;
  undefined4 uVar4;
  WCHAR aWStack_68 [42];
  uint local_14;
  
  local_14 = DAT_405fb760;
  if (param_2 == 0x53) {
    CreateProcessW(L"peghelp",L"file:ctpnl.htm#prompt_for_password",(LPSECURITY_ATTRIBUTES)0x0,
                   (LPSECURITY_ATTRIBUTES)0x0,0,0,(LPVOID)0x0,(LPCWSTR)0x0,(LPSTARTUPINFOW)0x0,
                   (LPPROCESS_INFORMATION)0x0);
LAB_405f872c:
    FUN_405f9bec(local_14);
    uVar4 = 0;
  }
  else {
    if (param_2 == 0x110) {
      pWVar2 = (LPCWSTR)LoadStringW(DAT_405fb7fc,0x8505,(LPWSTR)0x0,0);
      SetWindowTextW(param_1,pWVar2);
      FUN_405f7658(param_1,1);
      pHVar3 = GetDlgItem(param_1,0x3c);
      SendMessageW(pHVar3,0xc5,0x28,0);
      if ((param_4 != (LPCWSTR)0x0) && (*param_4 != L'\0')) {
        pHVar3 = GetDlgItem(param_1,0x3c);
        SetWindowTextW(pHVar3,param_4);
LAB_405f86c8:
        pHVar3 = GetDlgItem(param_1,0x3c);
        SendMessageW(pHVar3,0xb1,0,-1);
      }
    }
    else {
      if (param_2 != 0x111) goto LAB_405f872c;
      if (param_3 == 1) {
        GetDlgItemTextW(param_1,0x3c,aWStack_68,0x29);
        _wcslwr(aWStack_68);
        iVar1 = CheckPassword(aWStack_68);
        if (iVar1 == 0) {
          pWVar2 = (LPCWSTR)LoadStringW(DAT_405fb7fc,0x8506,(LPWSTR)0x0,0);
          pHVar3 = GetDlgItem(param_1,0x3d);
          SetWindowTextW(pHVar3,pWVar2);
          MessageBeep(0x40);
          pHVar3 = GetDlgItem(param_1,0x3c);
          SetFocus(pHVar3);
          goto LAB_405f86c8;
        }
        nResult = FUN_405ee458(aWStack_68);
      }
      else {
        if (param_3 != 2) goto LAB_405f872c;
        nResult = (wchar_t *)0x0;
      }
      EndDialog(param_1,(INT_PTR)nResult);
    }
    uVar4 = 1;
    FUN_405f9bec(local_14);
  }
  return uVar4;
}



/* 405f8754 FUN_405f8754 */

/* Boundary evidence: original MIPS .pdata 405f8754..405f87ff. Semantic name remains unreviewed. */

void FUN_405f8754(HWND param_1)

{
  int iVar1;
  HRSRC hResInfo;
  LPCDLGTEMPLATEW hDialogTemplate;
  
  iVar1 = CheckPassword(&DAT_405e1694);
  if ((iVar1 == 0) && (iVar1 = CheckPassword(0), iVar1 == 0)) {
    hResInfo = FindResourceW(DAT_405fb7fc,(LPCWSTR)0x32,(LPCWSTR)0x5);
    hDialogTemplate = LoadResource(DAT_405fb7fc,hResInfo);
    DialogBoxIndirectParamW(DAT_405fb7fc,hDialogTemplate,param_1,FUN_405f8534,0);
  }
  else {
    FUN_405ee458(L"");
  }
  return;
}



/* 405f8800 FUN_405f8800 */

/* Boundary evidence: original MIPS .pdata 405f8800..405f88fb. Semantic name remains unreviewed. */

HFONT FUN_405f8800(HWND param_1)

{
  uint uVar1;
  HANDLE h;
  HFONT pHVar2;
  HKEY apHStack_80 [4];
  LOGFONTW local_70;
  uint local_14;
  
  local_14 = DAT_405fb760;
  FUN_405e3fc4(apHStack_80,(HKEY)0x80000002,L"SYSTEM\\GWE\\Button");
  uVar1 = FUN_405e4194(apHStack_80,L"FontWeight",0);
  if (uVar1 == 0) {
    uVar1 = 700;
  }
  if (400 < uVar1) {
    memset(&local_70,0,0x5c);
    h = (HANDLE)SendMessageW(param_1,0x31,0,0);
    if (h == (HANDLE)0x0) {
      h = GetStockObject(0xd);
    }
    GetObjectW(h,0x5c,&local_70);
    if (local_70.lfHeight != 0) {
      local_70.lfWeight = uVar1;
      pHVar2 = CreateFontIndirectW(&local_70);
      if (pHVar2 != (HFONT)0x0) goto LAB_405f88d4;
    }
  }
  pHVar2 = (HFONT)0x0;
LAB_405f88d4:
  FUN_405e4020(apHStack_80);
  FUN_405f9bec(local_14);
  return pHVar2;
}



/* 405f88fc FUN_405f88fc */

/* Boundary evidence: original MIPS .pdata 405f88fc..405f8a3b. Semantic name remains unreviewed. */

void FUN_405f88fc(HWND param_1,wchar_t *param_2)

{
  HDC hdc;
  size_t sVar1;
  wchar_t *lpString;
  size_t local_30 [2];
  tagSIZE tStack_28;
  tagRECT local_20;
  
  hdc = GetDC(param_1);
  GetClientRect(param_1,&local_20);
  local_30[0] = wcslen(param_2);
  GetTextExtentExPointW
            (hdc,param_2,local_30[0],local_20.right - local_20.left,(LPINT)local_30,(LPINT)0x0,
             &tStack_28);
  ReleaseDC(param_1,hdc);
  sVar1 = wcslen(param_2);
  if ((((int)sVar1 < (int)local_30[0]) || ((int)local_30[0] < 7)) ||
     (lpString = FUN_405ee458(param_2), lpString == (wchar_t *)0x0)) {
    SetWindowTextW(param_1,param_2);
  }
  else {
    lpString[local_30[0] - 3] = L'.';
    lpString[local_30[0] - 2] = L'.';
    lpString[local_30[0] - 1] = L'.';
    lpString[local_30[0]] = L'\0';
    SetWindowTextW(param_1,lpString);
    LocalFree(lpString);
  }
  return;
}



/* 405f8a3c FUN_405f8a3c */

/* Boundary evidence: original MIPS .pdata 405f8a3c..405f8bd3. Semantic name remains unreviewed. */

WPARAM FUN_405f8a3c(undefined4 *param_1,wchar_t *param_2,wchar_t *param_3)

{
  size_t sVar1;
  HRESULT HVar2;
  WPARAM wParam;
  wchar_t *hMem;
  LRESULT LVar3;
  size_t sVar4;
  wchar_t local_230;
  undefined1 auStack_22e [530];
  uint local_1c;
  
  local_1c = DAT_405fb760;
  local_230 = L'\0';
  memset(auStack_22e,0,0x210);
  sVar4 = 0;
  if (param_2 != (wchar_t *)0x0) {
    sVar4 = wcslen(param_2);
  }
  if (param_3 != (wchar_t *)0x0) {
    sVar1 = wcslen(param_3);
    sVar4 = sVar1 + sVar4;
  }
  if (((sVar4 + 1 < 0x213) && (param_3 != (wchar_t *)0x0)) &&
     (HVar2 = StringCbCopyW(&local_230,0x212,param_3), -1 < HVar2)) {
    FUN_405f82d4(&local_230);
    wParam = SendMessageW((HWND)*param_1,0x143,0,(LPARAM)&local_230);
    if (wParam != 0xffffffff) {
      local_230 = L'\0';
      if (param_2 != (wchar_t *)0x0) {
        StringCchCopyW(&local_230,0x109,param_2);
        StringCchCatW(&local_230,0x109,L"\\");
      }
      StringCchCatW(&local_230,0x109,param_3);
      hMem = FUN_405ee458(&local_230);
      LVar3 = SendMessageW((HWND)*param_1,0x151,wParam,(LPARAM)hMem);
      if (LVar3 != -1) {
        FUN_405f9bec(local_1c);
        return wParam;
      }
      if (hMem != (wchar_t *)0x0) {
        LocalFree(hMem);
      }
    }
    FUN_405f9bec(local_1c);
  }
  else {
    FUN_405f9bec(local_1c);
  }
  return 0xffffffff;
}



/* 405f8bd4 FUN_405f8bd4 */

/* Boundary evidence: original MIPS .pdata 405f8bd4..405f8cd3. Semantic name remains unreviewed. */

void FUN_405f8bd4(undefined4 *param_1,wchar_t *param_2,int param_3)

{
  HRESULT HVar1;
  HANDLE hFindFile;
  BOOL BVar2;
  _WIN32_FIND_DATAW local_458;
  uint local_20;
  
  local_20 = DAT_405fb760;
  if (((param_2 != (wchar_t *)0x0) && (param_3 != 0)) &&
     (HVar1 = StringCbPrintfW(local_458.cFileName + 0x102,0x208,L"%s\\%s",param_2,param_3),
     -1 < HVar1)) {
    hFindFile = FindFirstFileW(local_458.cFileName + 0x102,&local_458);
    if ((hFindFile != (HANDLE)0x0) && (hFindFile != (HANDLE)0xffffffff)) {
      do {
        if ((local_458.dwFileAttributes & 2) == 0) {
          FUN_405f8a3c(param_1,param_2,(wchar_t *)&local_458.dwReserved1);
        }
        BVar2 = FindNextFileW(hFindFile,&local_458);
      } while (BVar2 != 0);
    }
    FindClose(hFindFile);
  }
  FUN_405f9bec(local_20);
  return;
}



/* 405f8cd4 FUN_405f8cd4 */

/* Boundary evidence: original MIPS .pdata 405f8cd4..405f8d63. Semantic name remains unreviewed. */

WPARAM FUN_405f8cd4(undefined4 *param_1,LPARAM param_2,wchar_t *param_3,WPARAM param_4)

{
  WPARAM wParam;
  wchar_t *lParam;
  
  wParam = SendMessageW((HWND)*param_1,0x14a,param_4,param_2);
  if (wParam != 0xffffffff) {
    lParam = FUN_405ee458(param_3);
    SendMessageW((HWND)*param_1,0x151,wParam,(LPARAM)lParam);
    SendMessageW((HWND)*param_1,0x14e,wParam,0);
  }
  return wParam;
}



/* 405f8d64 FUN_405f8d64 */

/* Boundary evidence: original MIPS .pdata 405f8d64..405f8def. Semantic name remains unreviewed. */

WPARAM FUN_405f8d64(undefined4 *param_1,LPARAM param_2,wchar_t *param_3)

{
  WPARAM wParam;
  wchar_t *lParam;
  
  wParam = SendMessageW((HWND)*param_1,0x143,0,param_2);
  if (wParam != 0xffffffff) {
    lParam = FUN_405ee458(param_3);
    SendMessageW((HWND)*param_1,0x151,wParam,(LPARAM)lParam);
    SendMessageW((HWND)*param_1,0x14e,wParam,0);
  }
  return wParam;
}



/* 405f8df0 FUN_405f8df0 */

/* Boundary evidence: original MIPS .pdata 405f8df0..405f8e8b. Semantic name remains unreviewed. */

WPARAM FUN_405f8df0(undefined4 *param_1,LPARAM param_2,wchar_t *param_3)

{
  WPARAM wParam;
  
  wParam = SendMessageW((HWND)*param_1,0x158,0xffffffff,param_2);
  if (wParam == 0xffffffff) {
    wParam = FUN_405f8d64(param_1,param_2,param_3);
  }
  SendMessageW((HWND)*param_1,0x14e,wParam,0);
  return wParam;
}



/* 405f8e8c FUN_405f8e8c */

/* Boundary evidence: original MIPS .pdata 405f8e8c..405f8f23. Semantic name remains unreviewed. */

WPARAM FUN_405f8e8c(undefined4 *param_1,LPCWSTR param_2)

{
  WPARAM wParam;
  
  if ((param_2 == (LPCWSTR)0x0) || (*param_2 == L'\0')) {
    wParam = 0xffffffff;
  }
  else {
    wParam = FUN_405f7f90(param_1,param_2);
    if (wParam == 0xffffffff) {
      wParam = FUN_405f8a3c(param_1,(wchar_t *)0x0,param_2);
    }
    SendMessageW((HWND)*param_1,0x14e,wParam,0);
  }
  return wParam;
}



/* 405f8f24 FUN_405f8f24 */

/* Boundary evidence: original MIPS .pdata 405f8f24..405f8f9f. Semantic name remains unreviewed. */

void FUN_405f8f24(undefined4 *param_1,undefined4 param_2,wchar_t *param_3,wchar_t *param_4,
                 undefined4 param_5,undefined4 param_6)

{
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  wchar_t *local_28;
  size_t local_24;
  undefined4 local_20;
  undefined4 local_1c;
  wchar_t *local_14;
  
  local_38 = 0x27;
  local_3c = param_6;
  local_1c = param_5;
  local_20 = param_5;
  local_40 = param_2;
  local_28 = param_3;
  local_24 = wcslen(param_3);
  local_14 = FUN_405ee458(param_4);
  SendMessageW((HWND)*param_1,0x1132,0,(LPARAM)&local_40);
  return;
}



/* 405f8fa0 FUN_405f8fa0 */

/* Boundary evidence: original MIPS .pdata 405f8fa0..405f9023. Semantic name remains unreviewed. */

void FUN_405f8fa0(undefined4 *param_1,undefined4 param_2,wchar_t *param_3,undefined4 param_4)

{
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_28;
  undefined4 local_24;
  wchar_t *local_1c;
  
  FUN_405f803c(param_1,param_2);
  local_40 = 0x26;
  local_3c = param_2;
  local_1c = FUN_405ee458(param_3);
  local_28 = param_4;
  local_24 = param_4;
  SendMessageW((HWND)*param_1,0x113f,0,(LPARAM)&local_40);
  return;
}



/* 405f9a84 entry */

/* Boundary evidence: original MIPS .pdata 405f9a84..405f9af7. Semantic name remains unreviewed. */

undefined4 entry(undefined4 param_1,int param_2)

{
  undefined4 uVar1;
  
  if (param_2 == 1) {
    FUN_405f9af8();
    FUN_405f9dcc();
  }
  uVar1 = FUN_405e7e54(param_1,param_2);
  if (param_2 == 0) {
    FUN_405f9d54();
  }
  return uVar1;
}



/* 405f9af8 FUN_405f9af8 */

/* Boundary evidence: original MIPS .pdata 405f9af8..405f9b6b. Semantic name remains unreviewed. */

void FUN_405f9af8(void)

{
  uint uVar1;
  
  if ((DAT_405fb760 == 0) || (DAT_405fb760 == 0xb064)) {
    uVar1 = __security_gen_cookie2();
    DAT_405fb760 = uVar1 >> 0x10 ^ uVar1 & 0xffff;
    if (DAT_405fb760 == 0) {
      DAT_405fb760 = 0xb064;
    }
  }
  DAT_405fb764 = ~DAT_405fb760;
  return;
}



/* 405f9b6c FUN_405f9b6c */

/* Boundary evidence: original MIPS .pdata 405f9b6c..405f9bbf. Semantic name remains unreviewed. */

void FUN_405f9b6c(int param_1,undefined4 param_2,uint *param_3)

{
  if ((*param_3 & 1) != 0) {
    param_1 = ((-param_3[2] & param_3[1] + param_1) - (param_3[1] + param_1)) + param_1;
  }
  FUN_405f9bec(*(uint *)(param_1 + (*param_3 & 0xfffffffc)));
  return;
}



/* 405f9bc0 FUN_405f9bc0 */

/* Boundary evidence: original MIPS .pdata 405f9bc0..405f9beb. Semantic name remains unreviewed. */

undefined4 FUN_405f9bc0(undefined4 param_1,int param_2,undefined4 param_3,int param_4)

{
  FUN_405f9b6c(param_2,param_4,*(uint **)(*(int *)(param_4 + 4) + 0xc));
  return 1;
}



/* 405f9bec FUN_405f9bec */

/* Boundary evidence: original MIPS .pdata 405f9bec..405f9c33. Semantic name remains unreviewed. */

void FUN_405f9bec(uint param_1)

{
  if ((param_1 == DAT_405fb760) && (param_1 >> 0x10 == 0)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __report_gsfailure();
}



/* 405f9c34 FUN_405f9c34 */

/* Boundary evidence: original MIPS .pdata 405f9c34..405f9d53. Semantic name remains unreviewed. */

void FUN_405f9c34(UINT param_1,int param_2,int param_3)

{
  LPCRITICAL_SECTION lpCriticalSection;
  undefined4 *_Memory;
  
  DAT_405fb9a8 = (undefined1)param_3;
  if (param_2 == 0) {
    _Memory = DAT_405fb9b0;
    if (DAT_405fb9b0 != (undefined4 *)0x0) {
      while (DAT_405fb9ac = DAT_405fb9ac + -1, _Memory <= DAT_405fb9ac) {
        if ((code *)*DAT_405fb9ac != (code *)0x0) {
          (*(code *)*DAT_405fb9ac)();
          _Memory = DAT_405fb9b0;
        }
      }
      free(_Memory);
      DAT_405fb9ac = (undefined4 *)0x0;
      DAT_405fb9b0 = (undefined4 *)0x0;
    }
    FUN_405f9d78((undefined4 *)&DAT_405e1010,(undefined4 *)&DAT_405e1014);
  }
  FUN_405f9d78((undefined4 *)&DAT_405e1018,(undefined4 *)&DAT_405e101c);
  if (param_3 == 0) {
    TerminateProcess((HANDLE)0x42,param_1);
  }
  else {
    lpCriticalSection = (LPCRITICAL_SECTION)InterlockedExchange((LONG *)&DAT_405fb9b4,0);
    if (lpCriticalSection != (LPCRITICAL_SECTION)0x0) {
      DeleteCriticalSection(lpCriticalSection);
      free(lpCriticalSection);
    }
  }
  return;
}



/* 405f9d54 FUN_405f9d54 */

/* Boundary evidence: original MIPS .pdata 405f9d54..405f9d77. Semantic name remains unreviewed. */

void FUN_405f9d54(void)

{
  FUN_405f9c34(0,0,1);
  return;
}



/* 405f9d78 FUN_405f9d78 */

/* Boundary evidence: original MIPS .pdata 405f9d78..405f9dcb. Semantic name remains unreviewed. */

void FUN_405f9d78(undefined4 *param_1,undefined4 *param_2)

{
  for (; param_1 < param_2; param_1 = param_1 + 1) {
    if ((code *)*param_1 != (code *)0x0) {
      (*(code *)*param_1)();
    }
  }
  return;
}



/* 405f9dcc FUN_405f9dcc */

/* Boundary evidence: original MIPS .pdata 405f9dcc..405f9e07. Semantic name remains unreviewed. */

void FUN_405f9dcc(void)

{
  FUN_405f9d78((undefined4 *)&DAT_405e1008,(undefined4 *)&DAT_405e100c);
  FUN_405f9d78((undefined4 *)&DAT_405e1000,(undefined4 *)&DAT_405e1004);
  return;
}


