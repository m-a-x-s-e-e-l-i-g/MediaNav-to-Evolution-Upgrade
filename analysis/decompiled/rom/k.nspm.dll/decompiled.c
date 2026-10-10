/* Automatic Ghidra pseudocode. Not original source; not runtime-verified. */

/* c04e1168 FUN_c04e1168 */

/* Boundary evidence: original MIPS .pdata c04e1168..c04e1257. Semantic name remains unreviewed. */

undefined4 FUN_c04e1168(void *param_1)

{
  int iVar1;
  DWORD dwErrCode;
  undefined4 uVar2;
  
  dwErrCode = 0;
  iVar1 = memcmp(param_1,&DAT_c04e4084,0x10);
  if (iVar1 == 0) {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c04e4160);
    if (DAT_c04e4140 < 1) {
      dwErrCode = 0x276d;
    }
    else {
      DAT_c04e4140 = DAT_c04e4140 + -1;
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c04e4160);
  }
  else {
    dwErrCode = 0x2726;
  }
  uVar2 = 0;
  if (dwErrCode != 0) {
    SetLastError(dwErrCode);
    uVar2 = 0xffffffff;
  }
  return uVar2;
}



/* c04e1258 FUN_c04e1258 */

/* Boundary evidence: original MIPS .pdata c04e1258..c04e1263. Semantic name remains unreviewed. */

undefined4 FUN_c04e1258(void)

{
  return 1;
}



/* c04e1264 NSPStartup */

/* Boundary evidence: original MIPS .pdata c04e1264..c04e139b. Semantic name remains unreviewed. */

undefined4 NSPStartup(undefined4 param_1,uint *param_2)

{
  DWORD dwErrCode;
  undefined4 uVar1;
  
                    /* 0x1264  1  NSPStartup */
  dwErrCode = 0;
  if (*param_2 < 0x2c) {
    dwErrCode = 0x2726;
  }
  else {
    param_2[1] = 1;
    param_2[2] = 1;
    param_2[3] = (uint)FUN_c04e1168;
    param_2[4] = (uint)FUN_c04e19f0;
    param_2[5] = (uint)FUN_c04e1f30;
    param_2[6] = (uint)FUN_c04e2ad8;
    param_2[7] = (uint)FUN_c04e2bb8;
    param_2[8] = (uint)FUN_c04e2be0;
    param_2[9] = (uint)FUN_c04e2e40;
    param_2[10] = (uint)FUN_c04e2e68;
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c04e4160);
    DAT_c04e4140 = DAT_c04e4140 + 1;
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c04e4160);
  }
  uVar1 = 0;
  if (dwErrCode != 0) {
    SetLastError(dwErrCode);
    uVar1 = 0xffffffff;
  }
  return uVar1;
}



/* c04e139c FUN_c04e139c */

/* Boundary evidence: original MIPS .pdata c04e139c..c04e13a7. Semantic name remains unreviewed. */

undefined4 FUN_c04e139c(void)

{
  return 1;
}



/* c04e13a8 FUN_c04e13a8 */

/* Boundary evidence: original MIPS .pdata c04e13a8..c04e140b. Semantic name remains unreviewed. */

undefined4 FUN_c04e13a8(HMODULE param_1,int param_2)

{
  if (param_2 == 0) {
    DeleteCriticalSection((LPCRITICAL_SECTION)&DAT_c04e4160);
  }
  else if (param_2 == 1) {
    InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_c04e4160);
    DisableThreadLibraryCalls(param_1);
  }
  return 1;
}



/* c04e140c FUN_c04e140c */

/* Boundary evidence: original MIPS .pdata c04e140c..c04e14e7. Semantic name remains unreviewed. */

undefined4 FUN_c04e140c(wchar_t *param_1)

{
  size_t sVar1;
  undefined4 uVar2;
  char acStack_30 [24];
  uint local_18;
  
  local_18 = DAT_c04e4130;
  uVar2 = 0xffffffff;
  if (DAT_c04e414c == (HMODULE)0x0) {
    DAT_c04e414c = LoadLibraryW(L"ws2.dll");
    if (DAT_c04e414c == (HMODULE)0x0) goto LAB_c04e14c4;
  }
  if (DAT_c04e4148 == (code *)0x0) {
    DAT_c04e4148 = (code *)GetProcAddressW(DAT_c04e414c,L"inet_addr");
    if (DAT_c04e4148 == (code *)0x0) goto LAB_c04e14c4;
  }
  sVar1 = wcslen(param_1);
  if ((sVar1 + 1 < 0x17) && (sVar1 = wcstombs(acStack_30,param_1,sVar1 + 1), sVar1 != 0xffffffff)) {
    uVar2 = (*DAT_c04e4148)(acStack_30);
  }
LAB_c04e14c4:
  FUN_c04e3068(local_18);
  return uVar2;
}



/* c04e14e8 FUN_c04e14e8 */

undefined4 FUN_c04e14e8(short *param_1,undefined4 param_2)

{
  byte bVar1;
  short sVar2;
  short *psVar3;
  short *psVar4;
  int iVar5;
  uint uVar6;
  undefined4 local_res4 [3];
  
  local_res4[0] = param_2;
  iVar5 = 3;
  psVar3 = param_1;
  do {
    do {
      psVar4 = psVar3;
      bVar1 = *(byte *)((int)local_res4 + iVar5);
      uVar6 = bVar1 / 10;
      *psVar4 = (ushort)bVar1 % 10 + 0x30;
      *(byte *)((int)local_res4 + iVar5) = (byte)uVar6;
      psVar3 = psVar4 + 1;
    } while (uVar6 != 0);
    psVar4[1] = 0x2e;
    iVar5 = iVar5 + -1;
    psVar3 = psVar4 + 2;
  } while (-1 < iVar5);
  psVar4[1] = 0;
  for (; param_1 < psVar4; param_1 = param_1 + 1) {
    sVar2 = *psVar4;
    *psVar4 = *param_1;
    *param_1 = sVar2;
    psVar4 = psVar4 + -1;
  }
  return 1;
}



/* c04e1588 FUN_c04e1588 */

/* Boundary evidence: original MIPS .pdata c04e1588..c04e1667. Semantic name remains unreviewed. */

undefined4 FUN_c04e1588(wchar_t *param_1,wchar_t *param_2)

{
  size_t _MaxCount;
  size_t sVar1;
  int iVar2;
  
  if (param_1 == param_2) {
    return 1;
  }
  if (param_1 == (wchar_t *)0x0) {
    return 0;
  }
  if (param_2 == (wchar_t *)0x0) {
    return 0;
  }
  _MaxCount = wcslen(param_1);
  sVar1 = wcslen(param_2);
  if (_MaxCount != sVar1) {
    if (_MaxCount == sVar1 + 1) {
      if (param_1[_MaxCount] != L'.') {
        return 0;
      }
      _MaxCount = _MaxCount - 1;
    }
    else {
      if (_MaxCount != sVar1 - 1) {
        return 0;
      }
      if (param_2[sVar1] != L'.') {
        return 0;
      }
    }
  }
  iVar2 = _wcsnicmp(param_1,param_2,_MaxCount);
  if (iVar2 != 0) {
    return 0;
  }
  return 1;
}



/* c04e1668 FUN_c04e1668 */

void FUN_c04e1668(int *param_1)

{
  int iVar1;
  int iVar2;
  
  *param_1 = *param_1 - (int)param_1;
  if ((int *)param_1[1] != (int *)0x0) {
    iVar1 = 0;
    if (*(int *)param_1[1] != 0) {
      iVar2 = 0;
      do {
        *(int *)(param_1[1] + iVar2) = *(int *)(param_1[1] + iVar2) - (int)param_1;
        iVar1 = iVar1 + 1;
        iVar2 = iVar1 * 4;
      } while (*(int *)(param_1[1] + iVar2) != 0);
    }
    param_1[1] = param_1[1] - (int)param_1;
  }
  iVar1 = 0;
  if (*(int *)param_1[3] != 0) {
    iVar2 = 0;
    do {
      *(int *)(param_1[3] + iVar2) = *(int *)(param_1[3] + iVar2) - (int)param_1;
      iVar1 = iVar1 + 1;
      iVar2 = iVar1 * 4;
    } while (*(int *)(param_1[3] + iVar2) != 0);
  }
  param_1[3] = param_1[3] - (int)param_1;
  return;
}



/* c04e171c FUN_c04e171c */

/* Boundary evidence: original MIPS .pdata c04e171c..c04e1973. Semantic name remains unreviewed. */

undefined4 FUN_c04e171c(int *param_1,undefined4 *param_2,int param_3,int *param_4)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  char *pcVar6;
  char *_Dst;
  uint _Size;
  
  if (param_3 < 0x10) {
    param_2 = (undefined4 *)0x0;
    _Dst = (char *)0x0;
  }
  else {
    _Dst = (char *)(param_2 + 4);
  }
  if (param_2 != (undefined4 *)0x0) {
    *(undefined2 *)((int)param_2 + 10) = *(undefined2 *)((int)param_1 + 10);
    *(short *)(param_2 + 2) = (short)param_1[2];
  }
  piVar5 = (int *)param_1[1];
  if (piVar5 == (int *)0x0) {
    iVar4 = 4;
  }
  else {
    iVar4 = 0;
    do {
      iVar2 = *piVar5;
      iVar4 = iVar4 + 1;
      piVar5 = piVar5 + 1;
    } while (iVar2 != 0);
    iVar4 = iVar4 * 4;
  }
  if (param_2 != (undefined4 *)0x0) {
    param_2[1] = _Dst;
    _Dst = _Dst + iVar4;
  }
  piVar5 = (int *)param_1[3];
  iVar2 = 0;
  do {
    iVar3 = *piVar5;
    iVar2 = iVar2 + 1;
    piVar5 = piVar5 + 1;
  } while (iVar3 != 0);
  if (param_2 != (undefined4 *)0x0) {
    param_2[3] = _Dst;
    _Dst = _Dst + iVar2 * 4;
  }
  iVar4 = iVar2 * 4 + iVar4 + 0x10;
  _Size = (int)*(short *)((int)param_1 + 10) + 3U & 0xfffffffc;
  iVar2 = 0;
  if (*(int *)param_1[3] != 0) {
    iVar3 = 0;
    do {
      iVar4 = _Size + iVar4;
      if (iVar4 <= param_3) {
        if (param_2 != (undefined4 *)0x0) {
          *(char **)(param_2[3] + iVar3) = _Dst;
        }
        memcpy(_Dst,*(void **)(iVar3 + param_1[3]),_Size);
        _Dst = _Dst + _Size;
      }
      iVar2 = iVar2 + 1;
      iVar3 = iVar2 * 4;
    } while (*(int *)(iVar3 + param_1[3]) != 0);
  }
  if (*param_1 != 0) {
    if (param_2 != (undefined4 *)0x0) {
      *param_2 = _Dst;
    }
    pcVar6 = (char *)*param_1;
    while( true ) {
      iVar4 = iVar4 + 1;
      if (*pcVar6 == '\0') break;
      if (iVar4 <= param_3) {
        *_Dst = *pcVar6;
        _Dst = _Dst + 1;
      }
      pcVar6 = pcVar6 + 1;
    }
    if (iVar4 <= param_3) {
      *_Dst = '\0';
      _Dst = _Dst + 1;
    }
  }
  piVar5 = (int *)param_1[1];
  if (piVar5 != (int *)0x0) {
    for (; *piVar5 != 0; piVar5 = piVar5 + 1) {
      if (param_2 != (undefined4 *)0x0) {
        *(char **)param_2[1] = _Dst;
      }
      pcVar6 = (char *)*piVar5;
      while( true ) {
        iVar4 = iVar4 + 1;
        if (*pcVar6 == '\0') break;
        if (iVar4 <= param_3) {
          *_Dst = *pcVar6;
          _Dst = _Dst + 1;
        }
        pcVar6 = pcVar6 + 1;
      }
      if (iVar4 <= param_3) {
        *_Dst = '\0';
        _Dst = _Dst + 1;
      }
    }
  }
  *param_4 = iVar4;
  uVar1 = 0x271e;
  if (iVar4 <= param_3) {
    uVar1 = 0;
  }
  return uVar1;
}



/* c04e1974 FUN_c04e1974 */

undefined4 FUN_c04e1974(int param_1)

{
  int iVar1;
  int *piVar2;
  uint uVar3;
  
  piVar2 = *(int **)(param_1 + 0x24);
  uVar3 = 0;
  if (*(uint *)(param_1 + 0x20) != 0) {
    do {
      iVar1 = *piVar2;
      if ((iVar1 == 0) ||
         (((iVar1 == 2 || (iVar1 == 0x17)) &&
          ((iVar1 = piVar2[1], iVar1 == 0 || ((iVar1 == 6 || (iVar1 == 0x11)))))))) {
        return 1;
      }
      uVar3 = uVar3 + 1;
      piVar2 = piVar2 + 2;
    } while (uVar3 < *(uint *)(param_1 + 0x20));
  }
  return 0;
}



/* c04e19f0 FUN_c04e19f0 */

/* Boundary evidence: original MIPS .pdata c04e19f0..c04e1f2f. Semantic name remains unreviewed. */

undefined4
FUN_c04e19f0(undefined4 param_1,uint *param_2,undefined4 param_3,uint param_4,undefined4 *param_5)

{
  bool bVar1;
  int iVar2;
  size_t sVar3;
  undefined4 *puVar4;
  wchar_t *pwVar5;
  int *piVar6;
  uint uVar7;
  uint *_Buf1;
  DWORD dwErrCode;
  undefined4 uVar8;
  wchar_t *_Str;
  uint uVar9;
  uint uVar10;
  short asStack_50 [18];
  uint local_2c;
  
  local_2c = DAT_c04e4130;
  uVar10 = 0;
  dwErrCode = 0;
  if (*param_2 < 0x3c) {
    dwErrCode = 0x271e;
  }
  else {
    _Buf1 = (uint *)param_2[2];
    if (_Buf1 != (uint *)0x0) {
      if ((param_4 & 2) == 0) {
LAB_c04e1a8c:
        if ((param_2[8] == 0) || (iVar2 = FUN_c04e1974((int)param_2), iVar2 != 0)) {
          pwVar5 = (wchar_t *)param_2[7];
          if ((pwVar5 != (wchar_t *)0x0) &&
             ((*pwVar5 != L'\0' && (iVar2 = wcscmp(pwVar5,L"\\"), iVar2 != 0)))) goto LAB_c04e1a84;
          pwVar5 = LocalAlloc(0x40,0x800);
          if (pwVar5 == (wchar_t *)0x0) {
            dwErrCode = 8;
            goto LAB_c04e1ee0;
          }
          uVar9 = 0;
          iVar2 = memcmp(_Buf1,&DAT_c04e40e0,0x10);
          if (iVar2 == 0) {
            uVar9 = 2;
          }
          else {
            iVar2 = memcmp(_Buf1,&DAT_c04e4100,0x10);
            if (iVar2 == 0) {
              uVar9 = 0x10;
              param_4 = param_4 & 0xfffffeff;
            }
            else {
              iVar2 = memcmp(_Buf1,&DAT_c04e4120,0x10);
              if (iVar2 == 0) {
                uVar9 = 0x100;
              }
            }
          }
          iVar2 = memcmp(_Buf1,&DAT_c04e40d0,0x10);
          if (((iVar2 == 0) ||
              (((((((*_Buf1 & 0xffff0000) == 0x90000 && ((short)_Buf1[1] == 0)) &&
                  ((char)_Buf1[2] == -0x40)) &&
                 ((*(char *)((int)_Buf1 + 9) == '\0' && (*(char *)((int)_Buf1 + 10) == '\0')))) &&
                (*(char *)((int)_Buf1 + 0xb) == '\0')) &&
               ((((char)_Buf1[3] == '\0' && (*(char *)((int)_Buf1 + 0xd) == '\0')) &&
                ((*(char *)((int)_Buf1 + 0xe) == '\0' && (*(char *)((int)_Buf1 + 0xf) == 'F'))))))))
             || ((((((((*_Buf1 & 0xffff0000) == 0xa0000 && ((short)_Buf1[1] == 0)) &&
                     ((char)_Buf1[2] == -0x40)) &&
                    ((*(char *)((int)_Buf1 + 9) == '\0' && (*(char *)((int)_Buf1 + 10) == '\0'))))
                   && (*(char *)((int)_Buf1 + 0xb) == '\0')) &&
                  ((((char)_Buf1[3] == '\0' && (*(char *)((int)_Buf1 + 0xd) == '\0')) &&
                   ((*(char *)((int)_Buf1 + 0xe) == '\0' && (*(char *)((int)_Buf1 + 0xf) == 'F')))))
                  ) || (((iVar2 = memcmp(_Buf1,&DAT_c04e40f0,0x10), iVar2 == 0 ||
                         (iVar2 = memcmp(_Buf1,&DAT_c04e4120,0x10), iVar2 == 0)) ||
                        (iVar2 = memcmp(_Buf1,&DAT_c04e4110,0x10), iVar2 == 0)))))) {
            bVar1 = true;
          }
          else {
            bVar1 = false;
          }
          _Str = (wchar_t *)param_2[1];
          if ((_Str == (wchar_t *)0x0) || (*_Str == L'\0')) {
            if (bVar1) {
              uVar9 = uVar9 | 4;
              _Str = L"";
              goto LAB_c04e1da0;
            }
            if ((((uVar9 & 2) != 0) && (param_2[0xc] != 0)) &&
               ((param_2[0xb] == 1 &&
                (iVar2 = FUN_c04e14e8(asStack_50,*(undefined4 *)(*(int *)(param_2[0xc] + 8) + 4)),
                _Str = pwVar5, iVar2 != 0)))) goto LAB_c04e1da0;
            dwErrCode = 0x2726;
          }
          else {
            if ((bVar1) &&
               ((iVar2 = FUN_c04e1588(_Str,L"localhost"), iVar2 != 0 ||
                (iVar2 = FUN_c04e1588(_Str,L"loopback"), iVar2 != 0)))) {
              uVar9 = uVar9 | 0x24;
            }
LAB_c04e1da0:
            uVar7 = param_2[8];
            if (uVar7 == 0) {
LAB_c04e1e20:
              uVar10 = 3;
            }
            else {
              piVar6 = (int *)param_2[9];
              do {
                uVar7 = uVar7 - 1;
                if (piVar6 == (int *)0x0) break;
                iVar2 = *piVar6;
                if (iVar2 == 0) goto LAB_c04e1e2c;
                if ((iVar2 == 2) || (iVar2 == 0x17)) {
                  iVar2 = ((int *)param_2[9])[1];
                  if (iVar2 == 0) goto LAB_c04e1e20;
                  if (iVar2 == 0x11) {
                    uVar10 = uVar10 | 1;
                  }
                  else if (iVar2 == 6) {
                    uVar10 = uVar10 | 2;
                  }
                }
                piVar6 = piVar6 + 2;
              } while (uVar7 != 0);
            }
            if (uVar10 == 0) {
              dwErrCode = 0x2afc;
            }
            else {
LAB_c04e1e2c:
              sVar3 = wcslen(_Str);
              puVar4 = LocalAlloc(0x40,(sVar3 + 0x12) * 2);
              if (puVar4 == (undefined4 *)0x0) {
                dwErrCode = 8;
              }
              else {
                puVar4[6] = 1;
                puVar4[5] = uVar9;
                puVar4[7] = param_4;
                puVar4[1] = *_Buf1;
                puVar4[2] = _Buf1[1];
                puVar4[3] = _Buf1[2];
                puVar4[4] = _Buf1[3];
                wcscpy((wchar_t *)(puVar4 + 8),_Str);
                EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c04e4160);
                *puVar4 = DAT_c04e4150;
                DAT_c04e4150 = puVar4;
                LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c04e4160);
                *param_5 = puVar4;
              }
            }
          }
          LocalFree(pwVar5);
          uVar8 = 0;
          if (dwErrCode == 0) goto LAB_c04e1ef4;
          goto LAB_c04e1ee0;
        }
      }
      else if ((param_4 & 4) == 0) {
        if ((param_4 & 2) == 0) goto LAB_c04e1a8c;
LAB_c04e1a84:
        dwErrCode = 0x2afc;
        goto LAB_c04e1ee0;
      }
    }
    dwErrCode = 0x2726;
  }
LAB_c04e1ee0:
  SetLastError(dwErrCode);
  uVar8 = 0xffffffff;
LAB_c04e1ef4:
  FUN_c04e3068(local_2c);
  return uVar8;
}



/* c04e1f30 FUN_c04e1f30 */

/* Boundary evidence: original MIPS .pdata c04e1f30..c04e2ad7. Semantic name remains unreviewed. */

undefined4 FUN_c04e1f30(undefined4 *param_1,uint param_2,uint *param_3,undefined4 *param_4)

{
  HLOCAL pvVar1;
  int iVar2;
  LSTATUS LVar3;
  undefined4 *puVar4;
  uint uVar5;
  uint uVar6;
  short sVar7;
  int *piVar8;
  undefined4 *puVar9;
  int iVar10;
  short *_Dst;
  undefined2 *_Dst_00;
  undefined4 uVar11;
  LPWSTR pWVar12;
  LPWSTR pWVar13;
  LPWSTR pWVar14;
  DWORD dwErrCode;
  LPWSTR pWVar15;
  LPWSTR pWVar16;
  size_t sVar17;
  int *piVar18;
  uint local_210;
  undefined4 *local_20c;
  undefined2 local_208 [2];
  DWORD local_204;
  int local_200;
  LPWSTR local_1fc;
  undefined4 *local_1f8;
  HLOCAL local_1f4;
  HKEY local_1f0;
  DWORD local_1ec;
  LPWSTR local_1e8;
  undefined4 local_1e4;
  DWORD local_1e0;
  uint *local_1dc;
  uint local_1d8;
  undefined4 local_1d0;
  LPWSTR local_1cc;
  LPWSTR local_1c8;
  undefined4 local_1bc;
  LPWSTR local_1b8;
  int local_1a4;
  LPWSTR local_1a0;
  LPWSTR local_198;
  int local_190 [4];
  wchar_t awStack_180 [168];
  uint local_30;
  
  local_30 = DAT_c04e4130;
  dwErrCode = 0;
  local_1e0 = 0;
  local_20c = param_1;
  local_1f8 = param_4;
  local_1dc = param_3;
  if (((param_1 == (undefined4 *)0x0) || (param_3 == (uint *)0x0)) || (param_4 == (undefined4 *)0x0)
     ) {
    dwErrCode = 0x271e;
LAB_c04e2a80:
    uVar11 = 0;
    if (dwErrCode == 0) goto LAB_c04e2a9c;
  }
  else {
    if ((param_2 & 2) == 0) {
LAB_c04e1fd4:
      if (*param_3 < 0x3c) {
        param_4 = &local_1d0;
      }
      iVar10 = 0x3c;
      local_1f8 = param_4;
      memset(param_4,0,0x3c);
      param_4[5] = 0xc;
      *param_4 = 0x3c;
      EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c04e4160);
      puVar4 = &DAT_c04e4150;
      for (puVar9 = DAT_c04e4150; (puVar9 != (undefined4 *)0x0 && (puVar9 != param_1));
          puVar9 = (undefined4 *)*puVar9) {
        puVar4 = puVar9;
      }
      pWVar16 = (LPWSTR)*puVar4;
      *(int *)(pWVar16 + 0xc) = *(int *)(pWVar16 + 0xc) + 1;
      local_1fc = pWVar16;
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c04e4160);
      sVar17 = 0x10;
      if ((*(uint *)(pWVar16 + 10) & 0x100) == 0) {
        local_208[0] = 1;
        sVar7 = 2;
      }
      else {
        sVar17 = 0x1c;
        local_208[0] = 0x1c;
        sVar7 = 0x17;
      }
      uVar6 = *(uint *)(pWVar16 + 10);
      local_210 = CONCAT22(local_210._2_2_,sVar7);
      if ((uVar6 & 0x1000) == 0) {
        if ((uVar6 & 0x10) == 0) {
          if ((uVar6 & 2) == 0) {
            if ((uVar6 & 4) == 0) {
              local_200 = 0;
              pWVar12 = local_1fc;
              pWVar13 = local_1fc;
            }
            else {
              local_200 = 1;
              if (((*(uint *)(pWVar16 + 0xe) & 0x110) == 0) ||
                 ((*(uint *)(pWVar16 + 0xe) & 0x310) == 0)) {
                dwErrCode = 0x2726;
                param_1 = local_20c;
                goto LAB_c04e29f4;
              }
              pWVar12 = (LPWSTR)(param_4 + 0xf);
              memset(&local_1d0,0,0x3c);
              local_1bc = 0xc;
              local_1d0 = 0x3c;
              pWVar13 = (LPWSTR)0x4c;
              if (0x4b < *param_3) {
                local_1b8 = pWVar12;
                memcpy(pWVar12,&DAT_c04e4084,0x10);
                pWVar12 = (LPWSTR)(param_4 + 0x13);
              }
              LVar3 = RegOpenKeyExW((HKEY)0x80000002,L"Ident",0,0,&local_1f0);
              if (LVar3 == 0) {
                local_204 = 0x150;
                LVar3 = RegQueryValueExW(local_1f0,L"Name",(LPDWORD)0x0,&local_1ec,
                                         (LPBYTE)awStack_180,&local_204);
                RegCloseKey(local_1f0);
                if ((LVar3 != 0) || (local_1ec != 1)) goto LAB_c04e2510;
              }
              else {
LAB_c04e2510:
                wcscpy(awStack_180,L"WindowsCE");
                local_204 = 0x14;
              }
              uVar6 = local_204 + 3 & 0xfffffffc;
              if (((*(uint *)(pWVar16 + 0xe) & 0x10) != 0) &&
                 (pWVar13 = (LPWSTR)(uVar6 + 0x4c), pWVar13 <= (LPWSTR)*param_3)) {
                local_1cc = pWVar12;
                memcpy(pWVar12,awStack_180,local_204);
                pWVar12 = (LPWSTR)(uVar6 + (int)pWVar12);
              }
              if (((*(uint *)(pWVar16 + 0xe) & 0x20) != 0) &&
                 (pWVar13 = pWVar13 + 8, pWVar13 <= (LPWSTR)*param_3)) {
                local_1c8 = pWVar12;
                memcpy(pWVar12,pWVar16 + 2,0x10);
                pWVar12 = pWVar12 + 8;
              }
              if ((*(uint *)(pWVar16 + 0xe) & 0x300) == 0) {
                if ((LPWSTR)*param_3 < pWVar13) {
                  dwErrCode = 0x271e;
                  *param_3 = (uint)pWVar13;
                  param_1 = local_20c;
                }
                else {
                  memcpy(param_4,&local_1d0,0x3c);
                  param_1 = local_20c;
                }
                goto LAB_c04e29f4;
              }
            }
            iVar10 = local_200;
            iVar2 = 0x3c;
            local_1f4 = LocalAlloc(0x40,0x450);
            if (local_1f4 == (HLOCAL)0x0) {
LAB_c04e29ec:
              dwErrCode = 8;
              param_1 = local_20c;
            }
            else {
              if ((iVar10 == 0) || (pWVar14 = awStack_180, (*(uint *)(pWVar16 + 10) & 0x20) != 0)) {
                pWVar14 = pWVar16 + 0x10;
              }
              iVar10 = (*(code *)&SUB_fffe6fe6)(local_1f4,0x450,pWVar14,0,local_208,2);
              pvVar1 = local_1f4;
              if (iVar10 == 0) {
                dwErrCode = GetLastError();
                pvVar1 = local_1f4;
              }
              else {
                piVar18 = (int *)((int)local_1f4 + 0x14);
                if (local_200 == 0) {
                  pWVar12 = (LPWSTR)(param_4 + 0xf);
                  memset(&local_1d0,0,0x3c);
                  local_1d0 = 0x3c;
                  if (((*(uint *)(pWVar16 + 0xe) & 0x20) != 0) && (iVar2 = 0x4c, 0x4b < *param_3)) {
                    local_1c8 = pWVar12;
                    memcpy(pWVar12,pWVar16 + 2,0x10);
                    pWVar12 = (LPWSTR)(param_4 + 0x13);
                  }
                  local_1bc = 0xc;
                  pWVar13 = (LPWSTR)(iVar2 + 0x10);
                  if (pWVar13 <= (LPWSTR)*param_3) {
                    local_1b8 = pWVar12;
                    memcpy(pWVar12,&DAT_c04e4084,0x10);
                    pWVar12 = pWVar12 + 8;
                  }
                }
                pWVar14 = pWVar12;
                if ((*(uint *)(pWVar16 + 0xe) & 0x100) != 0) {
                  piVar8 = *(int **)((int)pvVar1 + 0x20);
                  iVar10 = 0;
                  iVar2 = *piVar8;
                  while (iVar2 != 0) {
                    piVar8 = piVar8 + 1;
                    iVar10 = iVar10 + 1;
                    iVar2 = *piVar8;
                  }
                  local_1e8 = (LPWSTR)(iVar10 * (sVar17 + 0xc) * 2 + (int)pWVar13);
                  pWVar13 = local_1e8;
                  if (local_1e8 <= (LPWSTR)*param_3) {
                    pWVar14 = pWVar12 + iVar10 * 0xc;
                    local_1e4 = 0;
                    local_1a4 = iVar10;
                    local_1a0 = pWVar12;
                    if (**(int **)((int)pvVar1 + 0x20) != 0) {
                      uVar6 = local_210 & 0xffff;
                      iVar10 = 0;
                      pWVar15 = pWVar14 + 4;
                      pWVar12 = pWVar12 + 8;
                      iVar2 = 0;
                      local_1d8 = uVar6;
                      do {
                        memset(pWVar12 + -8,0,0x18);
                        *(size_t *)(pWVar12 + -2) = sVar17;
                        *(size_t *)(pWVar12 + -6) = sVar17;
                        pWVar12[0] = L'\x01';
                        pWVar12[1] = L'\0';
                        pWVar12[2] = L'\x06';
                        pWVar12[3] = L'\0';
                        *(LPWSTR *)(pWVar12 + -8) = pWVar14;
                        memset(pWVar14,0,sVar17);
                        _Dst_00 = (undefined2 *)((int)pWVar14 + sVar17);
                        *pWVar14 = (WCHAR)local_210;
                        *(undefined2 **)(pWVar12 + -4) = _Dst_00;
                        memset(_Dst_00,0,sVar17);
                        *_Dst_00 = (WCHAR)local_210;
                        if (uVar6 == 2) {
                          *(undefined4 *)(_Dst_00 + 2) =
                               **(undefined4 **)(iVar10 + *(int *)((int)pvVar1 + 0x20));
                        }
                        else {
                          memcpy((void *)((int)pWVar15 + sVar17),
                                 *(void **)(iVar10 + *(int *)((int)pvVar1 + 0x20)),0x14);
                        }
                        iVar2 = iVar2 + 1;
                        iVar10 = iVar2 * 4;
                        pWVar14 = (LPWSTR)((int)_Dst_00 + sVar17);
                        pWVar15 = (LPWSTR)((int)((int)pWVar15 + sVar17) + sVar17);
                        pWVar12 = pWVar12 + 0xc;
                        dwErrCode = local_1e0;
                        param_3 = local_1dc;
                        pWVar13 = local_1e8;
                        pWVar16 = local_1fc;
                        param_4 = local_1f8;
                      } while (*(int *)(iVar10 + *(int *)((int)pvVar1 + 0x20)) != 0);
                    }
                  }
                }
                if ((*(uint *)(pWVar16 + 0xe) & 0x200) != 0) {
                  local_210 = 8;
                  pWVar13 = pWVar13 + 4;
                  pWVar12 = pWVar14;
                  if (pWVar13 <= (LPWSTR)*param_3) {
                    pWVar12 = pWVar14 + 4;
                    *(LPWSTR *)(pWVar14 + 2) = pWVar12;
                  }
                  local_198 = pWVar14;
                  dwErrCode = FUN_c04e171c(piVar18,(undefined4 *)pWVar12,*param_3 - (int)pWVar13,
                                           (int *)&local_210);
                  if (dwErrCode == 0) {
                    FUN_c04e1668((int *)pWVar12);
                    *(uint *)pWVar14 = local_210;
                    uVar6 = local_210 + 3 & 0xfffffffc;
                    pWVar13 = (LPWSTR)(uVar6 + (int)pWVar13);
                    pWVar14 = (LPWSTR)(uVar6 + (int)pWVar12);
                  }
                  else {
                    pWVar13 = (LPWSTR)((local_210 + 3 & 0xfffffffc) + (int)pWVar13);
                    pWVar14 = pWVar12;
                  }
                }
                if (((*(uint *)(pWVar16 + 0xe) & 0x10) == 0) || (local_200 != 0)) {
LAB_c04e2998:
                  if (pWVar13 <= (LPWSTR)*param_3) {
                    memcpy(param_4,&local_1d0,0x3c);
                    pvVar1 = local_1f4;
                    goto LAB_c04e23e0;
                  }
                }
                else {
                  sVar17 = strlen((char *)*piVar18);
                  local_204 = sVar17 + 1;
                  pWVar13 = (LPWSTR)(((sVar17 + 2) * 2 & 0xfffffffc) + (int)pWVar13);
                  if (pWVar13 <= (LPWSTR)*param_3) {
                    local_1cc = pWVar14;
                    MultiByteToWideChar(0,0,(LPCSTR)*piVar18,-1,pWVar14,local_204);
                    goto LAB_c04e2998;
                  }
                }
                dwErrCode = 0x271e;
                *param_3 = (uint)pWVar13;
                pvVar1 = local_1f4;
              }
LAB_c04e23e0:
              LocalFree(pvVar1);
              param_1 = local_20c;
            }
          }
          else if (sVar7 == 0x17) {
            dwErrCode = 0x2afc;
          }
          else {
            local_190[0] = FUN_c04e140c(pWVar16 + 0x10);
            if (local_190[0] != -1) {
              pvVar1 = LocalAlloc(0x40,0x450);
              if (pvVar1 != (HLOCAL)0x0) {
                iVar2 = (*(code *)&SUB_fffe6fe6)(pvVar1,0x450,0,local_190,local_208,2);
                if (iVar2 == 0) {
                  dwErrCode = GetLastError();
                }
                else {
                  pWVar12 = (LPWSTR)(param_4 + 0xf);
                  memset(&local_1d0,0,0x3c);
                  local_1d0 = 0x3c;
                  if (((*(uint *)(pWVar16 + 0xe) & 0x20) != 0) && (iVar10 = 0x4c, 0x4b < *param_3))
                  {
                    local_1c8 = pWVar12;
                    memcpy(pWVar12,pWVar16 + 2,0x10);
                    pWVar12 = (LPWSTR)(param_4 + 0x13);
                  }
                  local_1bc = 0xc;
                  uVar6 = iVar10 + 0x10;
                  if (uVar6 <= *param_3) {
                    local_1b8 = pWVar12;
                    memcpy(pWVar12,&DAT_c04e4084,0x10);
                    pWVar12 = pWVar12 + 8;
                  }
                  if (((*(uint *)(pWVar16 + 0xe) & 0x100) != 0) &&
                     (uVar6 = (sVar17 + 0xc) * 2 + uVar6, uVar6 <= *param_3)) {
                    local_1a4 = 1;
                    pWVar13 = pWVar12 + 0xc;
                    local_1a0 = pWVar12;
                    memset(pWVar12,0,0x18);
                    *(size_t *)(pWVar12 + 6) = sVar17;
                    *(size_t *)(pWVar12 + 2) = sVar17;
                    pWVar12[8] = L'\x01';
                    pWVar12[9] = L'\0';
                    pWVar12[10] = L'\x06';
                    pWVar12[0xb] = L'\0';
                    *(LPWSTR *)pWVar12 = pWVar13;
                    memset(pWVar13,0,sVar17);
                    *pWVar13 = (WCHAR)local_210;
                    _Dst = (short *)((int)pWVar13 + sVar17);
                    *(short **)(pWVar12 + 4) = _Dst;
                    memset(_Dst,0,sVar17);
                    *_Dst = (WCHAR)local_210;
                    if ((WCHAR)local_210 == 2) {
                      *(int *)(_Dst + 2) = local_190[0];
                    }
                    else {
                      memcpy(_Dst + 4,local_190,0x10);
                    }
                    pWVar12 = (LPWSTR)((int)_Dst + sVar17);
                  }
                  pWVar13 = pWVar12;
                  if ((*(uint *)(pWVar16 + 0xe) & 0x200) != 0) {
                    local_210 = 8;
                    uVar6 = uVar6 + 8;
                    if (uVar6 <= *param_3) {
                      pWVar13 = pWVar12 + 4;
                      *(LPWSTR *)(pWVar12 + 2) = pWVar13;
                    }
                    local_198 = pWVar12;
                    dwErrCode = FUN_c04e171c((int *)((int)pvVar1 + 0x14),(undefined4 *)pWVar13,
                                             *param_3 - uVar6,(int *)&local_210);
                    if (dwErrCode == 0) {
                      FUN_c04e1668((int *)pWVar13);
                      uVar5 = local_210 + 3 & 0xfffffffc;
                      *(uint *)pWVar12 = local_210;
                      pWVar13 = (LPWSTR)(uVar5 + (int)pWVar13);
                    }
                    else {
                      uVar5 = local_210 + 3 & 0xfffffffc;
                    }
                    uVar6 = uVar5 + uVar6;
                  }
                  if ((*(uint *)(pWVar16 + 0xe) & 0x10) == 0) {
LAB_c04e2394:
                    if (uVar6 <= *param_3) {
                      memcpy(param_4,&local_1d0,0x3c);
                      goto LAB_c04e23e0;
                    }
                  }
                  else {
                    local_204 = strlen(*(char **)((int)pvVar1 + 0x14));
                    local_204 = local_204 + 1;
                    uVar6 = (local_204 * 2 + 3 & 0xfffffffc) + uVar6;
                    if (uVar6 <= *param_3) {
                      local_1cc = pWVar13;
                      MultiByteToWideChar(0,0,*(LPCSTR *)((int)pvVar1 + 0x14),-1,pWVar13,local_204);
                      goto LAB_c04e2394;
                    }
                  }
                  dwErrCode = 0x271e;
                  *param_3 = uVar6;
                }
                goto LAB_c04e23e0;
              }
              goto LAB_c04e29ec;
            }
            dwErrCode = 0x2726;
          }
        }
      }
      else {
        dwErrCode = 0x277e;
      }
LAB_c04e29f4:
      EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c04e4160);
      puVar4 = &DAT_c04e4150;
      do {
        puVar9 = puVar4;
        puVar4 = (undefined4 *)*puVar9;
        if (puVar4 == (undefined4 *)0x0) break;
      } while (puVar4 != param_1);
      puVar4 = (undefined4 *)*puVar9;
      if (puVar4 != (undefined4 *)0x0) {
        iVar10 = puVar4[6];
        puVar4[6] = iVar10 + -1;
        if (iVar10 + -1 == 0) {
          *puVar9 = *puVar4;
          LocalFree(puVar4);
        }
        else if (dwErrCode == 0) {
          puVar4[5] = puVar4[5] | 0x1000;
        }
      }
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c04e4160);
      goto LAB_c04e2a80;
    }
    if ((param_2 & 4) == 0) {
      if ((param_2 & 2) == 0) goto LAB_c04e1fd4;
      dwErrCode = 0x2afc;
    }
    else {
      dwErrCode = 0x2726;
    }
  }
  uVar11 = 0xffffffff;
  SetLastError(dwErrCode);
LAB_c04e2a9c:
  FUN_c04e3068(local_30);
  return uVar11;
}



/* c04e2ad8 FUN_c04e2ad8 */

/* Boundary evidence: original MIPS .pdata c04e2ad8..c04e2bb7. Semantic name remains unreviewed. */

undefined4 FUN_c04e2ad8(undefined4 *param_1)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  DWORD dwErrCode;
  undefined4 uVar4;
  
  dwErrCode = 0;
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c04e4160);
  puVar1 = &DAT_c04e4150;
  do {
    puVar3 = puVar1;
    puVar1 = (undefined4 *)*puVar3;
    if (puVar1 == (undefined4 *)0x0) break;
  } while (puVar1 != param_1);
  puVar1 = (undefined4 *)*puVar3;
  if (puVar1 == (undefined4 *)0x0) {
    dwErrCode = 6;
  }
  else {
    iVar2 = puVar1[6];
    puVar1[6] = iVar2 + -1;
    if (iVar2 + -1 == 0) {
      *puVar3 = *puVar1;
    }
    else {
      puVar1[5] = puVar1[5] | 1;
      puVar1 = (undefined4 *)0x0;
    }
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c04e4160);
  if (puVar1 != (undefined4 *)0x0) {
    LocalFree(puVar1);
  }
  uVar4 = 0;
  if (dwErrCode != 0) {
    SetLastError(dwErrCode);
    uVar4 = 0xffffffff;
  }
  return uVar4;
}



/* c04e2bb8 FUN_c04e2bb8 */

/* Boundary evidence: original MIPS .pdata c04e2bb8..c04e2bdf. Semantic name remains unreviewed. */

undefined4 FUN_c04e2bb8(void)

{
  SetLastError(0x273d);
  return 0xffffffff;
}



/* c04e2be0 FUN_c04e2be0 */

/* Boundary evidence: original MIPS .pdata c04e2be0..c04e2e33. Semantic name remains unreviewed. */

undefined4 FUN_c04e2be0(undefined4 param_1,undefined4 *param_2)

{
  DWORD dwErrCode;
  undefined4 *puVar1;
  int iVar2;
  HKEY local_30;
  DWORD local_2c;
  HKEY local_28;
  DWORD DStack_24;
  undefined4 *local_20;
  int local_1c;
  
  dwErrCode = RegCreateKeyExW((HKEY)0x80000002,L"Comm\\Winsock2\\ServiceProvider\\ServiceTypes",0,
                              (LPWSTR)0x0,0,0x2001f,(LPSECURITY_ATTRIBUTES)0x0,&local_28,&DStack_24)
  ;
  if (dwErrCode == 0) {
    local_30 = (HKEY)0x0;
    dwErrCode = RegCreateKeyExW(local_28,(LPCWSTR)param_2[1],0,(LPWSTR)0x0,0,0x2001f,
                                (LPSECURITY_ATTRIBUTES)0x0,&local_30,&DStack_24);
    local_2c = dwErrCode;
    if (dwErrCode == 0) {
      dwErrCode = RegSetValueExW(local_30,L"GUID",0,3,(BYTE *)*param_2,0x10);
      local_2c = dwErrCode;
      if (dwErrCode == 0) {
        puVar1 = (undefined4 *)param_2[3];
        iVar2 = param_2[2];
        while ((local_20 = puVar1, local_1c = iVar2, iVar2 != 0 && (dwErrCode == 0))) {
          if (puVar1[1] == 0xc) {
            dwErrCode = RegSetValueExW(local_30,(LPCWSTR)*puVar1,0,puVar1[2],(BYTE *)puVar1[4],
                                       puVar1[3]);
            local_2c = dwErrCode;
          }
          puVar1 = puVar1 + 5;
          iVar2 = iVar2 + -1;
        }
      }
      RegCloseKey(local_30);
    }
    RegCloseKey(local_28);
    if (dwErrCode == 0) {
      return 0;
    }
  }
  SetLastError(dwErrCode);
  return 0xffffffff;
}



/* c04e2e34 FUN_c04e2e34 */

/* Boundary evidence: original MIPS .pdata c04e2e34..c04e2e3f. Semantic name remains unreviewed. */

undefined4 FUN_c04e2e34(void)

{
  return 1;
}



/* c04e2e40 FUN_c04e2e40 */

/* Boundary evidence: original MIPS .pdata c04e2e40..c04e2e67. Semantic name remains unreviewed. */

undefined4 FUN_c04e2e40(void)

{
  SetLastError(0x273d);
  return 0xffffffff;
}



/* c04e2e68 FUN_c04e2e68 */

/* Boundary evidence: original MIPS .pdata c04e2e68..c04e2e8f. Semantic name remains unreviewed. */

undefined4 FUN_c04e2e68(void)

{
  SetLastError(0x273d);
  return 0xffffffff;
}



/* c04e2f00 entry */

/* Boundary evidence: original MIPS .pdata c04e2f00..c04e2f73. Semantic name remains unreviewed. */

undefined4 entry(HMODULE param_1,int param_2)

{
  undefined4 uVar1;
  
  if (param_2 == 1) {
    FUN_c04e2f74();
    FUN_c04e3248();
  }
  uVar1 = FUN_c04e13a8(param_1,param_2);
  if (param_2 == 0) {
    FUN_c04e31d0();
  }
  return uVar1;
}



/* c04e2f74 FUN_c04e2f74 */

/* Boundary evidence: original MIPS .pdata c04e2f74..c04e2fe7. Semantic name remains unreviewed. */

void FUN_c04e2f74(void)

{
  uint uVar1;
  
  if ((DAT_c04e4130 == 0) || (DAT_c04e4130 == 0xb064)) {
    uVar1 = __security_gen_cookie2();
    DAT_c04e4130 = uVar1 >> 0x10 ^ uVar1 & 0xffff;
    if (DAT_c04e4130 == 0) {
      DAT_c04e4130 = 0xb064;
    }
  }
  DAT_c04e4134 = ~DAT_c04e4130;
  return;
}



/* c04e2fe8 FUN_c04e2fe8 */

/* Boundary evidence: original MIPS .pdata c04e2fe8..c04e303b. Semantic name remains unreviewed. */

void FUN_c04e2fe8(int param_1,undefined4 param_2,uint *param_3)

{
  if ((*param_3 & 1) != 0) {
    param_1 = ((-param_3[2] & param_3[1] + param_1) - (param_3[1] + param_1)) + param_1;
  }
  FUN_c04e3068(*(uint *)(param_1 + (*param_3 & 0xfffffffc)));
  return;
}



/* c04e303c FUN_c04e303c */

/* Boundary evidence: original MIPS .pdata c04e303c..c04e3067. Semantic name remains unreviewed. */

undefined4 FUN_c04e303c(undefined4 param_1,int param_2,undefined4 param_3,int param_4)

{
  FUN_c04e2fe8(param_2,param_4,*(uint **)(*(int *)(param_4 + 4) + 0xc));
  return 1;
}



/* c04e3068 FUN_c04e3068 */

/* Boundary evidence: original MIPS .pdata c04e3068..c04e30af. Semantic name remains unreviewed. */

void FUN_c04e3068(uint param_1)

{
  if ((param_1 == DAT_c04e4130) && (param_1 >> 0x10 == 0)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __report_gsfailure();
}



/* c04e30b0 FUN_c04e30b0 */

/* Boundary evidence: original MIPS .pdata c04e30b0..c04e31cf. Semantic name remains unreviewed. */

void FUN_c04e30b0(UINT param_1,int param_2,int param_3)

{
  LPCRITICAL_SECTION lpCriticalSection;
  undefined4 *_Memory;
  
  DAT_c04e4144 = (undefined1)param_3;
  if (param_2 == 0) {
    _Memory = DAT_c04e4178;
    if (DAT_c04e4178 != (undefined4 *)0x0) {
      while (DAT_c04e4174 = DAT_c04e4174 + -1, _Memory <= DAT_c04e4174) {
        if ((code *)*DAT_c04e4174 != (code *)0x0) {
          (*(code *)*DAT_c04e4174)();
          _Memory = DAT_c04e4178;
        }
      }
      free(_Memory);
      DAT_c04e4174 = (undefined4 *)0x0;
      DAT_c04e4178 = (undefined4 *)0x0;
    }
    FUN_c04e31f4((undefined4 *)&DAT_c04e1010,(undefined4 *)&DAT_c04e1014);
  }
  FUN_c04e31f4((undefined4 *)&DAT_c04e1018,(undefined4 *)&DAT_c04e101c);
  if (param_3 == 0) {
    TerminateProcess((HANDLE)0x42,param_1);
  }
  else {
    lpCriticalSection = (LPCRITICAL_SECTION)InterlockedExchange((LONG *)&DAT_c04e417c,0);
    if (lpCriticalSection != (LPCRITICAL_SECTION)0x0) {
      DeleteCriticalSection(lpCriticalSection);
      free(lpCriticalSection);
    }
  }
  return;
}



/* c04e31d0 FUN_c04e31d0 */

/* Boundary evidence: original MIPS .pdata c04e31d0..c04e31f3. Semantic name remains unreviewed. */

void FUN_c04e31d0(void)

{
  FUN_c04e30b0(0,0,1);
  return;
}



/* c04e31f4 FUN_c04e31f4 */

/* Boundary evidence: original MIPS .pdata c04e31f4..c04e3247. Semantic name remains unreviewed. */

void FUN_c04e31f4(undefined4 *param_1,undefined4 *param_2)

{
  for (; param_1 < param_2; param_1 = param_1 + 1) {
    if ((code *)*param_1 != (code *)0x0) {
      (*(code *)*param_1)();
    }
  }
  return;
}



/* c04e3248 FUN_c04e3248 */

/* Boundary evidence: original MIPS .pdata c04e3248..c04e3283. Semantic name remains unreviewed. */

void FUN_c04e3248(void)

{
  FUN_c04e31f4((undefined4 *)&DAT_c04e1008,(undefined4 *)&DAT_c04e100c);
  FUN_c04e31f4((undefined4 *)&DAT_c04e1000,(undefined4 *)&DAT_c04e1004);
  return;
}


