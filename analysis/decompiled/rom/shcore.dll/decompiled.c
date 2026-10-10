/* Automatic Ghidra pseudocode. Not original source; not runtime-verified. */

/* 405d10fc FUN_405d10fc */

undefined4 FUN_405d10fc(uint param_1)

{
  if ((int)param_1 < 0x3c) {
    if ((param_1 == 0x3b) || (param_1 == 0x20)) {
      return 1;
    }
    if (param_1 == 0x22) {
      return 0;
    }
    if (param_1 == 0x2a) {
      return 4;
    }
    if (param_1 == 0x2c) {
      return 1;
    }
    if (param_1 == 0x2f) {
      return 8;
    }
    if (param_1 == 0x3a) {
      return 0;
    }
  }
  else {
    if (param_1 == 0x3c) {
      return 0;
    }
    if (param_1 == 0x3e) {
      return 0;
    }
    if (param_1 == 0x3f) {
      return 4;
    }
    if (param_1 == 0x5c) {
      return 8;
    }
    if (param_1 == 0x7c) {
      return 0;
    }
  }
  if (param_1 < 0x21) {
    return 0;
  }
  return 3;
}



/* 405d11d4 PathIsValidFileName */

/* Boundary evidence: original MIPS .pdata 405d11d4..405d122b. Semantic name remains unreviewed. */

undefined4 PathIsValidFileName(ushort *param_1)

{
  undefined4 uVar1;
  uint uVar2;
  
                    /* 0x11d4  18  PathIsValidFileName */
  if (param_1 == (ushort *)0x0) {
LAB_405d11ec:
    uVar1 = 0;
  }
  else {
    for (; *param_1 != 0; param_1 = param_1 + 1) {
      uVar2 = FUN_405d10fc((uint)*param_1);
      if ((uVar2 & 3) == 0) goto LAB_405d11ec;
    }
    uVar1 = 1;
  }
  return uVar1;
}



/* 405d122c PathIsValidPath */

/* Boundary evidence: original MIPS .pdata 405d122c..405d1283. Semantic name remains unreviewed. */

undefined4 PathIsValidPath(ushort *param_1)

{
  undefined4 uVar1;
  uint uVar2;
  
                    /* 0x122c  19  PathIsValidPath */
  if (param_1 == (ushort *)0x0) {
LAB_405d1244:
    uVar1 = 0;
  }
  else {
    for (; *param_1 != 0; param_1 = param_1 + 1) {
      uVar2 = FUN_405d10fc((uint)*param_1);
      if ((uVar2 & 0xb) == 0) goto LAB_405d1244;
    }
    uVar1 = 1;
  }
  return uVar1;
}



/* 405d1284 PathIsRemovableDevice */

/* Boundary evidence: original MIPS .pdata 405d1284..405d135b. Semantic name remains unreviewed. */

undefined4 PathIsRemovableDevice(STRSAFE_LPCWSTR param_1)

{
  HRESULT HVar1;
  DWORD DVar2;
  wchar_t *pwVar3;
  undefined4 uVar4;
  wchar_t local_218 [260];
  uint local_10;
  
                    /* 0x1284  15  PathIsRemovableDevice */
  local_10 = DAT_405d4090;
  uVar4 = 0;
  if (((param_1 != (STRSAFE_LPCWSTR)0x0) && (*param_1 != L'\0')) &&
     (HVar1 = StringCchCopyW(local_218,0x104,param_1), -1 < HVar1)) {
    for (pwVar3 = local_218; (*pwVar3 == L'\\' || (*pwVar3 == L'/')); pwVar3 = pwVar3 + 1) {
    }
    for (; (*pwVar3 != L'\0' && ((*pwVar3 != L'\\' && (*pwVar3 != L'/')))); pwVar3 = pwVar3 + 1) {
    }
    *pwVar3 = L'\0';
    DVar2 = GetFileAttributesW(local_218);
    uVar4 = 1;
    if ((DVar2 & 0x100) == 0) {
      uVar4 = 0;
    }
  }
  FUN_405d2e10(local_10);
  return uVar4;
}



/* 405d135c PathRemoveBlanksW */

/* Boundary evidence: original MIPS .pdata 405d135c..405d1403. Semantic name remains unreviewed. */

void PathRemoveBlanksW(LPWSTR pszPath)

{
  LPWSTR pWVar1;
  LPCWSTR lpsz;
  
                    /* 0x135c  25  PathRemoveBlanksW */
  pWVar1 = pszPath;
  lpsz = pszPath;
  if (*pszPath == L' ') {
    do {
      pWVar1 = pWVar1 + 1;
    } while (*pWVar1 == L' ');
    if (pWVar1 != pszPath) {
      wcscpy(pszPath,pWVar1);
    }
  }
  while (*pszPath != L'\0') {
    if (*pszPath != L' ') {
      lpsz = pszPath;
    }
    pszPath = CharNextW(pszPath);
  }
  if (*lpsz != L'\0') {
    pWVar1 = CharNextW(lpsz);
    *pWVar1 = L'\0';
  }
  return;
}



/* 405d1404 PathRemoveTrailingSlashes */

/* Boundary evidence: original MIPS .pdata 405d1404..405d1497. Semantic name remains unreviewed. */

void PathRemoveTrailingSlashes(LPWSTR param_1)

{
  int iVar1;
  LPWSTR pWVar2;
  LPCWSTR lpsz;
  
                    /* 0x1404  30  PathRemoveTrailingSlashes */
  iVar1 = lstrcmpW(param_1,L"\\");
  lpsz = param_1;
  if (iVar1 != 0) {
    while (*param_1 != L'\0') {
      if (*param_1 != L'\\') {
        lpsz = param_1;
      }
      param_1 = CharNextW(param_1);
    }
    if (*lpsz != L'\0') {
      pWVar2 = CharNextW(lpsz);
      *pWVar2 = L'\0';
    }
  }
  return;
}



/* 405d1498 PathGetArgsW */

/* Boundary evidence: original MIPS .pdata 405d1498..405d1527. Semantic name remains unreviewed. */

LPWSTR PathGetArgsW(LPCWSTR pszPath)

{
  WCHAR WVar1;
  bool bVar2;
  
                    /* 0x1498  7  PathGetArgsW */
  bVar2 = false;
  if (pszPath == (LPCWSTR)0x0) {
    pszPath = (LPWSTR)0x0;
  }
  else {
    for (; WVar1 = *pszPath, WVar1 != L'\0'; pszPath = CharNextW(pszPath)) {
      if (WVar1 == L'\"') {
        if (bVar2) {
          bVar2 = false;
        }
        else {
          bVar2 = true;
        }
      }
      else if ((!bVar2) && (WVar1 == L' ')) {
        return pszPath + 1;
      }
    }
  }
  return pszPath;
}



/* 405d1528 PathRemoveArgsW */

/* Boundary evidence: original MIPS .pdata 405d1528..405d158b. Semantic name remains unreviewed. */

void PathRemoveArgsW(LPWSTR pszPath)

{
  LPWSTR pWVar1;
  
                    /* 0x1528  24  PathRemoveArgsW */
  if (pszPath != (LPWSTR)0x0) {
    pWVar1 = PathGetArgsW(pszPath);
    if (*pWVar1 == L'\0') {
      pWVar1 = CharPrevW(pszPath,pWVar1);
      if (*pWVar1 == L' ') {
        *pWVar1 = L'\0';
      }
    }
    else {
      pWVar1[-1] = L'\0';
    }
  }
  return;
}



/* 405d158c PathRemoveQuotesAndArgs */

/* Boundary evidence: original MIPS .pdata 405d158c..405d1617. Semantic name remains unreviewed. */

void PathRemoveQuotesAndArgs(LPWSTR param_1)

{
  LPWSTR pWVar1;
  
                    /* 0x158c  29  PathRemoveQuotesAndArgs */
  if (param_1 != (LPWSTR)0x0) {
    pWVar1 = param_1;
    if (*param_1 == L'\"') {
      do {
        pWVar1 = CharNextW(pWVar1);
        if (*pWVar1 == L'\0') break;
      } while (*pWVar1 != L'\"');
      *pWVar1 = L'\0';
      pWVar1 = CharNextW(param_1);
      wcscpy(param_1,pWVar1);
    }
    else {
      PathRemoveArgsW(param_1);
    }
  }
  return;
}



/* 405d1618 PathRemoveQuotes */

/* Boundary evidence: original MIPS .pdata 405d1618..405d16a7. Semantic name remains unreviewed. */

void PathRemoveQuotes(LPCWSTR param_1)

{
  LPCWSTR lpsz;
  LPWSTR _Source;
  
                    /* 0x1618  28  PathRemoveQuotes */
  if ((param_1 != (LPCWSTR)0x0) && (lpsz = param_1, *param_1 == L'\"')) {
    do {
      lpsz = CharNextW(lpsz);
      if (*lpsz == L'\0') break;
    } while (*lpsz != L'\"');
    if (*lpsz == L'\"') {
      *lpsz = L'\0';
    }
    _Source = CharNextW(param_1);
    wcscpy(param_1,_Source);
  }
  return;
}



/* 405d16a8 PathFindExtensionW */

/* Boundary evidence: original MIPS .pdata 405d16a8..405d1727. Semantic name remains unreviewed. */

LPWSTR PathFindExtensionW(LPCWSTR pszPath)

{
  WCHAR WVar1;
  LPCWSTR pWVar2;
  LPCWSTR pWVar3;
  
                    /* 0x16a8  4  PathFindExtensionW */
  WVar1 = *pszPath;
  pWVar2 = (LPCWSTR)0x0;
  if (WVar1 != L'\0') {
    do {
      if ((WVar1 == L' ') ||
         ((pWVar3 = pszPath, WVar1 != L'.' && (pWVar3 = pWVar2, WVar1 == L'\\')))) {
        pWVar3 = (LPCWSTR)0x0;
      }
      pszPath = CharNextW(pszPath);
      WVar1 = *pszPath;
      pWVar2 = pWVar3;
    } while (WVar1 != L'\0');
    if (pWVar3 != (LPCWSTR)0x0) {
      return pWVar3;
    }
  }
  return pszPath;
}



/* 405d1728 PathFindFileNameW */

/* Boundary evidence: original MIPS .pdata 405d1728..405d17b3. Semantic name remains unreviewed. */

LPWSTR PathFindFileNameW(LPCWSTR pszPath)

{
  WCHAR WVar1;
  LPCWSTR pWVar2;
  
                    /* 0x1728  5  PathFindFileNameW */
  WVar1 = *pszPath;
  pWVar2 = pszPath;
  while (WVar1 != L'\0') {
    if ((WVar1 == L'\\') || (WVar1 == L':')) {
      WVar1 = pszPath[1];
      if ((WVar1 != L'\0') && (WVar1 != L'\\')) {
        pWVar2 = pszPath + 1;
      }
    }
    pszPath = CharNextW(pszPath);
    WVar1 = *pszPath;
  }
  return pWVar2;
}



/* 405d17b4 PathStripPathW */

/* Boundary evidence: original MIPS .pdata 405d17b4..405d17ef. Semantic name remains unreviewed. */

void PathStripPathW(LPWSTR pszPath)

{
  LPWSTR _Source;
  
                    /* 0x17b4  31  PathStripPathW */
  _Source = PathFindFileNameW(pszPath);
  if (_Source != pszPath) {
    wcscpy(pszPath,_Source);
  }
  return;
}



/* 405d17f0 PathCompactSlashes */

/* Boundary evidence: original MIPS .pdata 405d17f0..405d1887. Semantic name remains unreviewed. */

void PathCompactSlashes(wchar_t *param_1)

{
  bool bVar1;
  size_t sVar2;
  wchar_t *pwVar3;
  int iVar4;
  wchar_t *pwVar5;
  
                    /* 0x17f0  2  PathCompactSlashes */
  bVar1 = false;
  if (param_1 != (wchar_t *)0x0) {
    sVar2 = wcslen(param_1);
    iVar4 = 0;
    pwVar3 = param_1;
    pwVar5 = param_1;
    if (0 < (int)sVar2) {
      do {
        if ((*pwVar3 != L'\\') || (!bVar1)) {
          *pwVar5 = *pwVar3;
          iVar4 = iVar4 + 1;
          pwVar5 = pwVar5 + 1;
        }
        bVar1 = *pwVar3 == L'\\';
        sVar2 = sVar2 - 1;
        pwVar3 = pwVar3 + 1;
      } while (sVar2 != 0);
    }
    param_1[iVar4] = L'\0';
  }
  return;
}



/* 405d1888 PathIsDirectoryW */

/* Boundary evidence: original MIPS .pdata 405d1888..405d18cf. Semantic name remains unreviewed. */

BOOL PathIsDirectoryW(LPCWSTR pszPath)

{
  DWORD DVar1;
  
                    /* 0x1888  10  PathIsDirectoryW */
  if ((pszPath != (LPCWSTR)0x0) && (DVar1 = GetFileAttributesW(pszPath), DVar1 != 0xffffffff)) {
    return DVar1 & 0x10;
  }
  return 0;
}



/* 405d18d0 PathGetAssociation */

/* Boundary evidence: original MIPS .pdata 405d18d0..405d1a87. Semantic name remains unreviewed. */

undefined4 PathGetAssociation(LPCWSTR param_1,wchar_t *param_2)

{
  LPWSTR lpSubKey;
  LSTATUS LVar1;
  undefined4 uVar2;
  HKEY local_240;
  DWORD local_23c;
  HKEY local_238;
  DWORD DStack_234;
  WCHAR local_230 [259];
  undefined2 local_2a;
  uint local_28;
  
                    /* 0x18d0  8  PathGetAssociation */
  local_28 = DAT_405d4090;
  lpSubKey = PathFindExtensionW(param_1);
  *param_2 = L'\0';
  if (*lpSubKey == L'\0') {
LAB_405d1a54:
    FUN_405d2e10(local_28);
    uVar2 = 1;
  }
  else {
    LVar1 = RegOpenKeyExW((HKEY)0x80000000,lpSubKey,0,0,&local_240);
    if (LVar1 == 0) {
      local_23c = 0x104;
      LVar1 = RegQueryValueExW(local_240,(LPCWSTR)0x0,(LPDWORD)0x0,&DStack_234,(LPBYTE)local_230,
                               &local_23c);
      RegCloseKey(local_240);
      local_2a = 0;
      if (LVar1 == 0) {
        LVar1 = RegOpenKeyExW((HKEY)0x80000000,local_230,0,0,&local_240);
        if (LVar1 == 0) {
          local_230[0] = L'\0';
          LVar1 = RegOpenKeyExW(local_240,L"Shell\\Open\\Command",0,0,&local_238);
          if (LVar1 == 0) {
            local_23c = 0x104;
            RegQueryValueExW(local_238,(LPCWSTR)0x0,(LPDWORD)0x0,&DStack_234,(LPBYTE)local_230,
                             &local_23c);
            RegCloseKey(local_238);
          }
          RegCloseKey(local_240);
          wcscpy(param_2,local_230);
          goto LAB_405d1a54;
        }
      }
    }
    FUN_405d2e10(local_28);
    uVar2 = 0;
  }
  return uVar2;
}



/* 405d1a88 PathIsGUID */

/* Boundary evidence: original MIPS .pdata 405d1a88..405d1acf. Semantic name remains unreviewed. */

HRESULT PathIsGUID(LPCOLESTR param_1)

{
  HRESULT HVar1;
  CLSID CStack_20;
  uint local_10;
  
                    /* 0x1a88  13  PathIsGUID */
  local_10 = DAT_405d4090;
  HVar1 = CLSIDFromString(param_1,&CStack_20);
  FUN_405d2e10(local_10);
  return HVar1;
}



/* 405d1ad0 PathIsURLW */

/* Boundary evidence: original MIPS .pdata 405d1ad0..405d1bbf. Semantic name remains unreviewed. */

BOOL PathIsURLW(LPCWSTR pszPath)

{
  wchar_t *pwVar1;
  HRESULT HVar2;
  LSTATUS LVar3;
  uint uVar4;
  HKEY local_228 [2];
  wchar_t awStack_220 [260];
  uint local_18;
  
                    /* 0x1ad0  17  PathIsURLW */
  local_18 = DAT_405d4090;
  uVar4 = 0;
  local_228[0] = (HKEY)0x0;
  if ((((pszPath != (LPCWSTR)0x0) && (pwVar1 = wcschr(pszPath,L':'), pwVar1 != (wchar_t *)0x0)) &&
      (HVar2 = StringCchCopyNW(awStack_220,0x104,pszPath,(int)pwVar1 - (int)pszPath >> 1),
      -1 < HVar2)) &&
     (LVar3 = RegOpenKeyExW((HKEY)0x80000000,awStack_220,0,0,local_228), LVar3 == 0)) {
    LVar3 = RegQueryValueExW(local_228[0],L"URL Protocol",(LPDWORD)0x0,(LPDWORD)0x0,(LPBYTE)0x0,
                             (LPDWORD)0x0);
    uVar4 = (uint)(LVar3 == 0);
    RegCloseKey(local_228[0]);
  }
  FUN_405d2e10(local_18);
  return uVar4;
}



/* 405d1bc0 FUN_405d1bc0 */

/* Boundary evidence: original MIPS .pdata 405d1bc0..405d1c53. Semantic name remains unreviewed. */

undefined4 FUN_405d1bc0(wchar_t *param_1,wchar_t *param_2)

{
  wchar_t wVar1;
  int iVar2;
  size_t sVar3;
  
  if ((param_1 != (wchar_t *)0x0) && (param_2 != (wchar_t *)0x0)) {
    wVar1 = *param_1;
    while (wVar1 != L'\0') {
      iVar2 = _wcsicmp(param_2,param_1);
      if (iVar2 == 0) {
        return 1;
      }
      sVar3 = wcslen(param_1);
      param_1 = param_1 + sVar3 + 1;
      wVar1 = *param_1;
    }
  }
  return 0;
}



/* 405d1c54 PathIsExe */

/* Boundary evidence: original MIPS .pdata 405d1c54..405d1c87. Semantic name remains unreviewed. */

BOOL PathIsExe(LPCWSTR pszPath)

{
  BOOL BVar1;
  LPWSTR pWVar2;
  
                    /* 0x1c54  11  PathIsExe */
  BVar1 = 0;
  if (pszPath != (LPCWSTR)0x0) {
    pWVar2 = PathFindExtensionW(pszPath);
    BVar1 = FUN_405d1bc0(L".exe",pWVar2);
  }
  return BVar1;
}



/* 405d1c88 PathIsLink */

/* Boundary evidence: original MIPS .pdata 405d1c88..405d1ccf. Semantic name remains unreviewed. */

undefined4 PathIsLink(LPCWSTR param_1)

{
  undefined4 uVar1;
  LPWSTR _Str2;
  int iVar2;
  
                    /* 0x1c88  14  PathIsLink */
  uVar1 = 0;
  if (param_1 != (LPCWSTR)0x0) {
    _Str2 = PathFindExtensionW(param_1);
    iVar2 = _wcsicmp(L".lnk",_Str2);
    if (iVar2 == 0) {
      uVar1 = 1;
    }
    else {
      uVar1 = 0;
    }
  }
  return uVar1;
}



/* 405d1cd0 PathIsExtension */

/* Boundary evidence: original MIPS .pdata 405d1cd0..405d1d27. Semantic name remains unreviewed. */

undefined4 PathIsExtension(LPCWSTR param_1,wchar_t *param_2)

{
  undefined4 uVar1;
  LPWSTR _Str2;
  int iVar2;
  
                    /* 0x1cd0  12  PathIsExtension */
  uVar1 = 0;
  if ((param_1 != (LPCWSTR)0x0) && (param_2 != (wchar_t *)0x0)) {
    _Str2 = PathFindExtensionW(param_1);
    iVar2 = _wcsicmp(param_2,_Str2);
    if (iVar2 == 0) {
      uVar1 = 1;
    }
    else {
      uVar1 = 0;
    }
  }
  return uVar1;
}



/* 405d1d28 PathMakePrettyW */

/* Boundary evidence: original MIPS .pdata 405d1d28..405d1daf. Semantic name remains unreviewed. */

BOOL PathMakePrettyW(LPWSTR pszPath)

{
  WCHAR WVar1;
  LPWSTR lpsz;
  
                    /* 0x1d28  20  PathMakePrettyW */
  WVar1 = *pszPath;
  lpsz = pszPath;
  while( true ) {
    if (WVar1 == L'\0') {
      CharLowerW(pszPath);
      CharUpperBuffW(pszPath,1);
      return 1;
    }
    if ((0x60 < (ushort)WVar1) && ((ushort)WVar1 < 0x7b)) break;
    lpsz = CharNextW(lpsz);
    WVar1 = *lpsz;
  }
  return 0;
}



/* 405d1db0 PathFileExistsW */

/* Boundary evidence: original MIPS .pdata 405d1db0..405d1def. Semantic name remains unreviewed. */

BOOL PathFileExistsW(LPCWSTR pszPath)

{
  DWORD DVar1;
  
                    /* 0x1db0  3  PathFileExistsW */
  DVar1 = GetFileAttributesW(pszPath);
  return (uint)(DVar1 != 0xffffffff);
}



/* 405d1df0 PathRemoveExtensionW */

/* Boundary evidence: original MIPS .pdata 405d1df0..405d1e1b. Semantic name remains unreviewed. */

void PathRemoveExtensionW(LPWSTR pszPath)

{
  LPWSTR pWVar1;
  
                    /* 0x1df0  26  PathRemoveExtensionW */
  pWVar1 = PathFindExtensionW(pszPath);
  if (*pWVar1 != L'\0') {
    *pWVar1 = L'\0';
  }
  return;
}



/* 405d1e1c PathRemoveFileSpecW */

BOOL PathRemoveFileSpecW(LPWSTR pszPath)

{
  LPWSTR pWVar1;
  
                    /* 0x1e1c  27  PathRemoveFileSpecW */
  pWVar1 = pszPath;
  if (*pszPath != L'\0') {
    do {
      pWVar1 = pWVar1 + 1;
    } while (*pWVar1 != L'\0');
    for (; (pWVar1 != pszPath && (*pWVar1 != L'\\')); pWVar1 = pWVar1 + -1) {
    }
  }
  *pWVar1 = L'\0';
  return 1;
}



/* 405d1e68 FUN_405d1e68 */

/* Boundary evidence: original MIPS .pdata 405d1e68..405d206b. Semantic name remains unreviewed. */

undefined4 FUN_405d1e68(ushort *param_1,ushort *param_2)

{
  ushort uVar1;
  LPWSTR pWVar2;
  LPWSTR pWVar3;
  int iVar4;
  
  for (; *param_2 == 0x20; param_2 = param_2 + 1) {
  }
  uVar1 = *param_1;
  while( true ) {
    if (((uVar1 == 0) || (uVar1 = *param_2, uVar1 == 0)) || (uVar1 == 0x3b)) {
      if ((*param_1 == 0) &&
         (((uVar1 = *param_2, uVar1 == 0 || (uVar1 == 0x3b)) ||
          ((uVar1 == 0x2a &&
           (((uVar1 = param_2[1], uVar1 == 0 || (uVar1 == 0x3b)) ||
            (((uVar1 == 0x2e && (param_2[2] == 0x2a)) && ((param_2[3] == 0 || (param_2[3] == 0x3b)))
             ))))))))) {
        return 1;
      }
      return 0;
    }
    if (uVar1 == 0x2a) break;
    if (uVar1 != 0x3f) {
      pWVar2 = CharUpperW((LPWSTR)(uint)*param_1);
      pWVar3 = CharUpperW((LPWSTR)(uint)*param_2);
      if (pWVar3 != pWVar2) {
        return 0;
      }
    }
    param_1 = param_1 + 1;
    uVar1 = *param_1;
    param_2 = param_2 + 1;
  }
  uVar1 = param_2[1];
  if (uVar1 == 0) {
    return 1;
  }
  if (uVar1 != 0x3b) {
    if (uVar1 != 0x2e) {
      while( true ) {
        if (*param_1 == 0) {
          return 0;
        }
        iVar4 = FUN_405d1e68(param_1,param_2 + 1);
        if (iVar4 != 0) break;
        param_1 = param_1 + 1;
      }
      return 1;
    }
    if (param_2[2] == 0x2a) {
      if (param_2[3] == 0) {
        return 1;
      }
      if (param_2[3] == 0x3b) {
        return 1;
      }
    }
    do {
      uVar1 = *param_1;
      if (uVar1 == 0) {
        return 0;
      }
      param_1 = param_1 + 1;
    } while ((uVar1 != 0x2e) || (iVar4 = FUN_405d1e68(param_1,param_2 + 2), iVar4 == 0));
    return 1;
  }
  return 1;
}



/* 405d206c PathMatchSpecW */

/* Boundary evidence: original MIPS .pdata 405d206c..405d210b. Semantic name remains unreviewed. */

BOOL PathMatchSpecW(LPCWSTR pszFile,LPCWSTR pszSpec)

{
  WCHAR WVar1;
  int iVar2;
  
                    /* 0x206c  23  PathMatchSpecW */
  if ((pszSpec != (LPCWSTR)0x0) && (pszFile != (LPCWSTR)0x0)) {
    if (*pszSpec == L'\0') {
      return 1;
    }
    do {
      iVar2 = FUN_405d1e68((ushort *)pszFile,(ushort *)pszSpec);
      if (iVar2 != 0) {
        return 1;
      }
      for (; (*pszSpec != L'\0' && (*pszSpec != L';')); pszSpec = pszSpec + 1) {
      }
      WVar1 = *pszSpec;
      pszSpec = pszSpec + 1;
    } while (WVar1 == L';');
  }
  return 0;
}



/* 405d210c FUN_405d210c */

/* Boundary evidence: original MIPS .pdata 405d210c..405d2207. Semantic name remains unreviewed. */

undefined4 FUN_405d210c(LPCWSTR param_1,int param_2)

{
  WCHAR WVar1;
  LPWSTR pWVar2;
  wchar_t *lpsz;
  WCHAR *pWVar3;
  wchar_t *pwVar4;
  
  if ((param_2 == 0) && (pWVar2 = PathFindExtensionW(param_1), *pWVar2 != L'\0')) {
    *pWVar2 = L'\0';
  }
  lpsz = wcschr(param_1,L'(');
  if (lpsz != (wchar_t *)0x0) {
    do {
      pWVar3 = CharNextW(lpsz);
      WVar1 = *pWVar3;
      while (((WVar1 != L'\0' && (0x2f < (ushort)WVar1)) && ((ushort)WVar1 < 0x3a))) {
        pWVar3 = pWVar3 + 1;
        WVar1 = *pWVar3;
      }
      if (*pWVar3 == L')') break;
      pWVar2 = CharNextW(lpsz);
      lpsz = wcschr(pWVar2,L'(');
    } while (lpsz != (wchar_t *)0x0);
    if (lpsz != (wchar_t *)0x0) {
      pwVar4 = lpsz;
      if ((lpsz != param_1) && (pwVar4 = lpsz + -1, lpsz[-1] != L' ')) {
        pwVar4 = lpsz;
      }
      *pwVar4 = L'\0';
    }
  }
  return 1;
}



/* 405d2208 PathMakeUniqueNameEx */

/* Boundary evidence: original MIPS .pdata 405d2208..405d25d3. Semantic name remains unreviewed. */

undefined4
PathMakeUniqueNameEx
          (LPCWSTR param_1,wchar_t *param_2,wchar_t *param_3,int param_4,int param_5,
          STRSAFE_LPWSTR param_6,size_t param_7)

{
  size_t sVar1;
  LPWSTR pWVar2;
  size_t sVar3;
  HRESULT HVar4;
  DWORD DVar5;
  STRSAFE_LPCWSTR pwVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  undefined4 local_450;
  wchar_t awStack_440 [260];
  wchar_t awStack_238 [260];
  uint local_30;
  
                    /* 0x2208  22  PathMakeUniqueNameEx */
  local_30 = DAT_405d4090;
  iVar9 = 1;
  local_450 = 0;
  if ((param_1 != (LPCWSTR)0x0) && (param_6 != (STRSAFE_LPWSTR)0x0)) {
    if (param_2 == (wchar_t *)0x0) {
      iVar11 = 0;
    }
    else {
      sVar1 = wcslen(param_2);
      iVar11 = sVar1 + 1;
    }
    if (param_3 == (wchar_t *)0x0) {
      iVar10 = 0;
    }
    else {
      sVar1 = wcslen(param_3);
      iVar10 = sVar1 + 1;
    }
    StringCchCopyW(param_6,param_7,param_1);
    PathRemoveFileSpecW(param_6);
    sVar1 = wcslen(param_6);
    if (param_4 == 0) {
      pWVar2 = PathFindFileNameW(param_1);
      sVar3 = wcslen(pWVar2);
      iVar7 = sVar3 + 1;
    }
    else {
      pWVar2 = PathFindFileNameW(param_1);
      StringCchCopyW(param_6,param_7,pWVar2);
      FUN_405d210c(param_6,param_5);
      sVar3 = wcslen(param_6);
      iVar7 = sVar3 + 5;
    }
    do {
      if (iVar9 == 1) {
        iVar8 = 0;
      }
      else if (iVar9 < 10) {
        iVar8 = 4;
      }
      else {
        iVar8 = 5;
        if (99 < iVar9) {
          iVar8 = 6;
        }
      }
      if (0x104 < (int)(iVar7 + sVar1 + 1 + iVar10 + iVar11 + iVar8)) {
        SetLastError(0xce);
        goto LAB_405d2598;
      }
      StringCchCopyW(param_6,param_7,param_1);
      PathRemoveFileSpecW(param_6);
      StringCchCatW(param_6,param_7,L"\\");
      pwVar6 = L".lnk";
      if (param_2 == (wchar_t *)0x0) {
        pWVar2 = PathFindFileNameW(param_1);
        StringCchCatW(param_6,param_7,pWVar2);
        if (param_4 != 0) {
          FUN_405d210c(param_6,param_5);
        }
        if (1 < iVar9) {
          StringCchPrintfW(awStack_440,0x104,L" (%d)",iVar9);
          StringCchCatW(param_6,param_7,awStack_440);
        }
        if (param_4 != 0) goto LAB_405d2544;
      }
      else {
        pWVar2 = PathFindFileNameW(param_1);
        HVar4 = StringCchCopyW(awStack_238,0x104,pWVar2);
        if (HVar4 < 0) goto LAB_405d2598;
        if (((param_4 != 0) && (param_5 == 0)) &&
           (pWVar2 = PathFindExtensionW(awStack_238), *pWVar2 != L'\0')) {
          *pWVar2 = L'\0';
        }
        StringCchPrintfW(awStack_440,0x104,param_2,awStack_238);
        StringCchCatW(param_6,param_7,awStack_440);
        if (1 < iVar9) {
          StringCchCatW(param_6,param_7,L" ");
          StringCchPrintfW(awStack_440,0x104,L"(%d)",iVar9);
          StringCchCatW(param_6,param_7,awStack_440);
        }
        if (param_3 != (wchar_t *)0x0) {
          StringCchCatW(param_6,param_7,L" ");
          StringCchCatW(param_6,param_7,param_3);
          StringCchCatW(param_6,param_7,L" ");
        }
        if (param_4 == 0) {
          pwVar6 = awStack_238;
        }
LAB_405d2544:
        StringCchCatW(param_6,param_7,pwVar6);
      }
      iVar9 = iVar9 + 1;
      if (999 < iVar9) goto LAB_405d2598;
      DVar5 = GetFileAttributesW(param_6);
    } while (DVar5 != 0xffffffff);
    local_450 = 1;
  }
LAB_405d2598:
  FUN_405d2e10(local_30);
  return local_450;
}



/* 405d25d4 PathFindRootDevice */

short * PathFindRootDevice(short *param_1)

{
  short sVar1;
  int iVar2;
  short *psVar3;
  short *psVar4;
  
                    /* 0x25d4  6  PathFindRootDevice */
  iVar2 = 0;
  for (psVar3 = param_1; (*psVar3 == 0x5c || (*psVar3 == 0x2f)); psVar3 = psVar3 + 1) {
    iVar2 = iVar2 + 1;
  }
  for (; ((sVar1 = *psVar3, sVar1 != 0 && (sVar1 != 0x5c)) && (sVar1 != 0x2f)); psVar3 = psVar3 + 1)
  {
  }
  if (((1 < iVar2) && (*psVar3 != 0)) && (psVar4 = psVar3 + 1, *psVar4 != 0)) {
    sVar1 = *psVar4;
    psVar3 = psVar4;
    while (((sVar1 != 0 && (sVar1 != 0x5c)) && (sVar1 != 0x2f))) {
      psVar3 = psVar3 + 1;
      sVar1 = *psVar3;
    }
  }
  *psVar3 = 0;
  return param_1;
}



/* 405d2698 PathIsSameDevice */

/* Boundary evidence: original MIPS .pdata 405d2698..405d2823. Semantic name remains unreviewed. */

bool PathIsSameDevice(wchar_t *param_1,wchar_t *param_2)

{
  int iVar1;
  DWORD DVar2;
  bool bVar3;
  wchar_t local_428;
  short local_426;
  undefined2 local_222;
  wchar_t local_220;
  short local_21e;
  undefined2 local_1a;
  uint local_18;
  
                    /* 0x2698  16  PathIsSameDevice */
  local_18 = DAT_405d4090;
  wcsncpy(&local_220,param_1,0x103);
  local_1a = 0;
  PathFindRootDevice(&local_220);
  wcsncpy(&local_428,param_2,0x103);
  local_222 = 0;
  PathFindRootDevice(&local_428);
  if ((((local_220 == L'\\') || (local_220 == L'/')) && ((local_21e == 0x5c || (local_21e == 0x2f)))
      ) || (((local_428 == L'\\' || (local_428 == L'/')) &&
            ((local_426 == 0x5c || (local_426 == 0x2f)))))) {
    iVar1 = lstrcmpiW(&local_220,&local_428);
    bVar3 = iVar1 == 0;
    FUN_405d2e10(local_18);
  }
  else {
    iVar1 = lstrcmpiW(&local_220,&local_428);
    if ((iVar1 == 0) ||
       (((DVar2 = GetFileAttributesW(&local_220), DVar2 == 0xffffffff || ((DVar2 & 0x100) == 0)) &&
        ((DVar2 = GetFileAttributesW(&local_428), DVar2 == 0xffffffff || ((DVar2 & 0x100) == 0))))))
    {
      FUN_405d2e10(local_18);
      bVar3 = true;
    }
    else {
      FUN_405d2e10(local_18);
      bVar3 = false;
    }
  }
  return bVar3;
}



/* 405d2824 PathCompactPathW */

/* Boundary evidence: original MIPS .pdata 405d2824..405d2b17. Semantic name remains unreviewed. */

BOOL PathCompactPathW(HDC hDC,LPWSTR pszPath,UINT dx)

{
  bool bVar1;
  LONG LVar2;
  size_t sVar3;
  LPWSTR lpszCurrent;
  wchar_t *_Dest;
  HDC hDC_00;
  int iVar4;
  BOOL BVar5;
  tagSIZE local_248;
  uint local_240;
  wchar_t awStack_238 [259];
  undefined2 local_32;
  uint local_30;
  
                    /* 0x2824  1  PathCompactPathW */
  local_30 = DAT_405d4090;
  BVar5 = 1;
  hDC_00 = (HDC)0x0;
  if (hDC == (HDC)0x0) {
    hDC = GetDC((HWND)0x0);
    hDC_00 = hDC;
  }
  sVar3 = wcslen(pszPath);
  GetTextExtentExPointW(hDC,pszPath,sVar3,0,(LPINT)0x0,(LPINT)0x0,&local_248);
  if (dx < (uint)local_248.cx) {
    lpszCurrent = PathFindFileNameW(pszPath);
    if (lpszCurrent != pszPath) {
      lpszCurrent = CharPrevW(pszPath,lpszCurrent);
    }
    wcsncpy(awStack_238,lpszCurrent,0x103);
    local_32 = 0;
    bVar1 = false;
    sVar3 = wcslen(lpszCurrent);
    GetTextExtentExPointW(hDC,lpszCurrent,sVar3,0,(LPINT)0x0,(LPINT)0x0,&local_248);
    local_240 = local_248.cx;
    GetTextExtentExPointW(hDC,L"...",3,0,(LPINT)0x0,(LPINT)0x0,&local_248);
    LVar2 = local_248.cx;
    if (lpszCurrent == pszPath) {
      sVar3 = wcslen(pszPath);
      _Dest = pszPath + sVar3;
      if (0x207 < (int)((int)_Dest + (6 - (int)lpszCurrent) & 0xfffffffeU)) {
        _Dest = lpszCurrent + 0x100;
      }
      wcscpy(_Dest,L"...");
      iVar4 = (int)_Dest + (6 - (int)lpszCurrent);
      GetTextExtentExPointW(hDC,lpszCurrent,iVar4 >> 1,0,(LPINT)0x0,(LPINT)0x0,&local_248);
      while ((int)dx < local_248.cx) {
        _Dest = _Dest + -1;
        iVar4 = iVar4 + -2;
        wcscpy(_Dest,L"...");
        GetTextExtentExPointW(hDC,lpszCurrent,iVar4 >> 1,0,(LPINT)0x0,(LPINT)0x0,&local_248);
      }
    }
    else {
      while( true ) {
        GetTextExtentExPointW
                  (hDC,pszPath,(int)lpszCurrent - (int)pszPath >> 1,0,(LPINT)0x0,(LPINT)0x0,
                   &local_248);
        iVar4 = local_240 + local_248.cx;
        if (bVar1) {
          iVar4 = iVar4 + LVar2;
        }
        if (iVar4 <= (int)dx) {
          if (bVar1) {
            wcscpy(lpszCurrent,L"...");
            wcscat(lpszCurrent,awStack_238);
          }
          goto LAB_405d2ac8;
        }
        bVar1 = true;
        if (lpszCurrent <= pszPath) break;
        lpszCurrent = CharPrevW(pszPath,lpszCurrent);
      }
      wcscpy(pszPath,L"...");
      wcscat(pszPath,awStack_238);
      BVar5 = 0;
    }
  }
LAB_405d2ac8:
  if (hDC_00 != (HDC)0x0) {
    ReleaseDC((HWND)0x0,hDC_00);
  }
  FUN_405d2e10(local_30);
  return BVar5;
}



/* 405d2b18 PathIsDatabase */

/* Boundary evidence: original MIPS .pdata 405d2b18..405d2bbb. Semantic name remains unreviewed. */

undefined4 PathIsDatabase(wchar_t *param_1)

{
  size_t _MaxCount;
  int iVar1;
  DWORD DVar2;
  wchar_t awStack_28 [12];
  uint local_10;
  
                    /* 0x2b18  9  PathIsDatabase */
  local_10 = DAT_405d4090;
  if (param_1 != (wchar_t *)0x0) {
    memcpy(awStack_28,&DAT_405d10c0,0x18);
    _MaxCount = wcslen(awStack_28);
    iVar1 = _wcsnicmp(param_1,awStack_28,_MaxCount);
    if ((iVar1 == 0) && (DVar2 = GetFileAttributesW(param_1), DVar2 == 0xffffffff)) {
      FUN_405d2e10(local_10);
      return 1;
    }
  }
  FUN_405d2e10(local_10);
  return 0;
}



/* 405d2bbc PathMakeUniqueName */

/* Boundary evidence: original MIPS .pdata 405d2bbc..405d2be7. Semantic name remains unreviewed. */

BOOL PathMakeUniqueName(LPWSTR pszUniqueName,UINT cchMax,LPCWSTR pszTemplate,LPCWSTR pszLongPlate,
                       LPCWSTR pszDir)

{
  BOOL BVar1;
  size_t in_stack_00000014;
  
                    /* 0x2bbc  21  PathMakeUniqueName */
  BVar1 = PathMakeUniqueNameEx
                    (pszUniqueName,(wchar_t *)cchMax,pszTemplate,(int)pszLongPlate,0,pszDir,
                     in_stack_00000014);
  return BVar1;
}



/* 405d2ca8 entry */

/* Boundary evidence: original MIPS .pdata 405d2ca8..405d2d1b. Semantic name remains unreviewed. */

undefined4 entry(undefined4 param_1,int param_2)

{
  undefined4 uVar1;
  
  if (param_2 == 1) {
    FUN_405d2d1c();
    FUN_405d2ff0();
  }
  uVar1 = FUN_405d30dc(param_1,param_2);
  if (param_2 == 0) {
    FUN_405d2f78();
  }
  return uVar1;
}



/* 405d2d1c FUN_405d2d1c */

/* Boundary evidence: original MIPS .pdata 405d2d1c..405d2d8f. Semantic name remains unreviewed. */

void FUN_405d2d1c(void)

{
  uint uVar1;
  
  if ((DAT_405d4090 == 0) || (DAT_405d4090 == 0xb064)) {
    uVar1 = __security_gen_cookie2();
    DAT_405d4090 = uVar1 >> 0x10 ^ uVar1 & 0xffff;
    if (DAT_405d4090 == 0) {
      DAT_405d4090 = 0xb064;
    }
  }
  DAT_405d4094 = ~DAT_405d4090;
  return;
}



/* 405d2d90 FUN_405d2d90 */

/* Boundary evidence: original MIPS .pdata 405d2d90..405d2de3. Semantic name remains unreviewed. */

void FUN_405d2d90(int param_1,undefined4 param_2,uint *param_3)

{
  if ((*param_3 & 1) != 0) {
    param_1 = ((-param_3[2] & param_3[1] + param_1) - (param_3[1] + param_1)) + param_1;
  }
  FUN_405d2e10(*(uint *)(param_1 + (*param_3 & 0xfffffffc)));
  return;
}



/* 405d2de4 FUN_405d2de4 */

/* Boundary evidence: original MIPS .pdata 405d2de4..405d2e0f. Semantic name remains unreviewed. */

undefined4 FUN_405d2de4(undefined4 param_1,int param_2,undefined4 param_3,int param_4)

{
  FUN_405d2d90(param_2,param_4,*(uint **)(*(int *)(param_4 + 4) + 0xc));
  return 1;
}



/* 405d2e10 FUN_405d2e10 */

/* Boundary evidence: original MIPS .pdata 405d2e10..405d2e57. Semantic name remains unreviewed. */

void FUN_405d2e10(uint param_1)

{
  if ((param_1 == DAT_405d4090) && (param_1 >> 0x10 == 0)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __report_gsfailure();
}



/* 405d2e58 FUN_405d2e58 */

/* Boundary evidence: original MIPS .pdata 405d2e58..405d2f77. Semantic name remains unreviewed. */

void FUN_405d2e58(UINT param_1,int param_2,int param_3)

{
  LPCRITICAL_SECTION lpCriticalSection;
  undefined4 *_Memory;
  
  DAT_405d4098 = (undefined1)param_3;
  if (param_2 == 0) {
    _Memory = DAT_405d40a4;
    if (DAT_405d40a4 != (undefined4 *)0x0) {
      while (DAT_405d40a0 = DAT_405d40a0 + -1, _Memory <= DAT_405d40a0) {
        if ((code *)*DAT_405d40a0 != (code *)0x0) {
          (*(code *)*DAT_405d40a0)();
          _Memory = DAT_405d40a4;
        }
      }
      free(_Memory);
      DAT_405d40a0 = (undefined4 *)0x0;
      DAT_405d40a4 = (undefined4 *)0x0;
    }
    FUN_405d2f9c((undefined4 *)&DAT_405d1010,(undefined4 *)&DAT_405d1014);
  }
  FUN_405d2f9c((undefined4 *)&DAT_405d1018,(undefined4 *)&DAT_405d101c);
  if (param_3 == 0) {
    TerminateProcess((HANDLE)0x42,param_1);
  }
  else {
    lpCriticalSection = (LPCRITICAL_SECTION)InterlockedExchange((LONG *)&DAT_405d40a8,0);
    if (lpCriticalSection != (LPCRITICAL_SECTION)0x0) {
      DeleteCriticalSection(lpCriticalSection);
      free(lpCriticalSection);
    }
  }
  return;
}



/* 405d2f78 FUN_405d2f78 */

/* Boundary evidence: original MIPS .pdata 405d2f78..405d2f9b. Semantic name remains unreviewed. */

void FUN_405d2f78(void)

{
  FUN_405d2e58(0,0,1);
  return;
}



/* 405d2f9c FUN_405d2f9c */

/* Boundary evidence: original MIPS .pdata 405d2f9c..405d2fef. Semantic name remains unreviewed. */

void FUN_405d2f9c(undefined4 *param_1,undefined4 *param_2)

{
  for (; param_1 < param_2; param_1 = param_1 + 1) {
    if ((code *)*param_1 != (code *)0x0) {
      (*(code *)*param_1)();
    }
  }
  return;
}



/* 405d2ff0 FUN_405d2ff0 */

/* Boundary evidence: original MIPS .pdata 405d2ff0..405d302b. Semantic name remains unreviewed. */

void FUN_405d2ff0(void)

{
  FUN_405d2f9c((undefined4 *)&DAT_405d1008,(undefined4 *)&DAT_405d100c);
  FUN_405d2f9c((undefined4 *)&DAT_405d1000,(undefined4 *)&DAT_405d1004);
  return;
}



/* 405d30dc FUN_405d30dc */

undefined4 FUN_405d30dc(undefined4 param_1,int param_2)

{
  if (param_2 == 1) {
    DAT_405d409c = param_1;
  }
  return 1;
}


