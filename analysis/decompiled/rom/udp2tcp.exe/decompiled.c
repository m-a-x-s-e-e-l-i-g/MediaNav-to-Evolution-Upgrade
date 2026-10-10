/* Automatic Ghidra pseudocode. Not original source; not runtime-verified. */

/* 000110d8 FUN_000110d8 */

/* Boundary evidence: original MIPS .pdata 000110d8..0001116b. Semantic name remains unreviewed. */

void FUN_000110d8(HINSTANCE param_1,int param_2)

{
  UINT UVar1;
  
  FUN_000113e8();
  UVar1 = FUN_00012020(param_1,param_2);
  FUN_00011328(UVar1);
  FUN_00011348(UVar1);
  return;
}



/* 0001116c FUN_0001116c */

/* Boundary evidence: original MIPS .pdata 0001116c..000111ab. Semantic name remains unreviewed. */

void FUN_0001116c(_EXCEPTION_POINTERS *param_1)

{
  int in_v0;
  
  *(DWORD *)(in_v0 + -0x20) = param_1->ExceptionRecord->ExceptionCode;
  _XcptFilter(*(ulong *)(in_v0 + -0x20),param_1);
  return;
}



/* 000111ac entry */

/* Boundary evidence: original MIPS .pdata 000111ac..00011207. Semantic name remains unreviewed. */

void entry(HINSTANCE param_1,int param_2)

{
  FUN_00011424();
  FUN_000110d8(param_1,param_2);
  return;
}



/* 00011208 FUN_00011208 */

/* Boundary evidence: original MIPS .pdata 00011208..00011327. Semantic name remains unreviewed. */

void FUN_00011208(UINT param_1,int param_2,int param_3)

{
  LPCRITICAL_SECTION lpCriticalSection;
  undefined4 *_Memory;
  
  DAT_000130f0 = (undefined1)param_3;
  if (param_2 == 0) {
    _Memory = DAT_00013114;
    if (DAT_00013114 != (undefined4 *)0x0) {
      while (DAT_00013110 = DAT_00013110 + -1, _Memory <= DAT_00013110) {
        if ((code *)*DAT_00013110 != (code *)0x0) {
          (*(code *)*DAT_00013110)();
          _Memory = DAT_00013114;
        }
      }
      free(_Memory);
      DAT_00013110 = (undefined4 *)0x0;
      DAT_00013114 = (undefined4 *)0x0;
    }
    FUN_00011394((undefined4 *)&DAT_00011010,(undefined4 *)&DAT_00011014);
  }
  FUN_00011394((undefined4 *)&DAT_00011018,(undefined4 *)&DAT_0001101c);
  if (param_3 == 0) {
    TerminateProcess((HANDLE)0x42,param_1);
  }
  else {
    lpCriticalSection = (LPCRITICAL_SECTION)InterlockedExchange(&DAT_00013118,0);
    if (lpCriticalSection != (LPCRITICAL_SECTION)0x0) {
      DeleteCriticalSection(lpCriticalSection);
      free(lpCriticalSection);
    }
  }
  return;
}



/* 00011328 FUN_00011328 */

/* Boundary evidence: original MIPS .pdata 00011328..00011347. Semantic name remains unreviewed. */

void FUN_00011328(UINT param_1)

{
  FUN_00011208(param_1,0,0);
  return;
}



/* 00011348 FUN_00011348 */

/* Boundary evidence: original MIPS .pdata 00011348..00011393. Semantic name remains unreviewed. */

void FUN_00011348(UINT param_1)

{
  DAT_000130f0 = 0;
  FUN_00011394((undefined4 *)&DAT_00011018,(undefined4 *)&DAT_0001101c);
  TerminateProcess((HANDLE)0x42,param_1);
  return;
}



/* 00011394 FUN_00011394 */

/* Boundary evidence: original MIPS .pdata 00011394..000113e7. Semantic name remains unreviewed. */

void FUN_00011394(undefined4 *param_1,undefined4 *param_2)

{
  for (; param_1 < param_2; param_1 = param_1 + 1) {
    if ((code *)*param_1 != (code *)0x0) {
      (*(code *)*param_1)();
    }
  }
  return;
}



/* 000113e8 FUN_000113e8 */

/* Boundary evidence: original MIPS .pdata 000113e8..00011423. Semantic name remains unreviewed. */

void FUN_000113e8(void)

{
  FUN_00011394((undefined4 *)&DAT_00011008,(undefined4 *)&DAT_0001100c);
  FUN_00011394((undefined4 *)&DAT_00011000,(undefined4 *)&DAT_00011004);
  return;
}



/* 00011424 FUN_00011424 */

/* Boundary evidence: original MIPS .pdata 00011424..00011497. Semantic name remains unreviewed. */

void FUN_00011424(void)

{
  uint uVar1;
  
  if ((DAT_000130e4 == 0) || (DAT_000130e4 == 0xb064)) {
    uVar1 = __security_gen_cookie2();
    DAT_000130e4 = uVar1 >> 0x10 ^ uVar1 & 0xffff;
    if (DAT_000130e4 == 0) {
      DAT_000130e4 = 0xb064;
    }
  }
  DAT_000130e8 = ~DAT_000130e4;
  return;
}



/* 00011498 FUN_00011498 */

/* Boundary evidence: original MIPS .pdata 00011498..000115a3. Semantic name remains unreviewed. */

undefined4 FUN_00011498(undefined4 param_1)

{
  void *_Memory;
  uint uVar1;
  void *pvVar2;
  uint _NewSize;
  undefined4 *puVar3;
  int iVar4;
  
  _Memory = DAT_00013114;
  puVar3 = DAT_00013110;
  iVar4 = (int)DAT_00013110 - (int)DAT_00013114;
  uVar1 = 0;
  if (iVar4 < 0) {
LAB_000114dc:
    param_1 = 0;
  }
  else {
    if (DAT_00013114 != (void *)0x0) {
      uVar1 = _msize(DAT_00013114);
    }
    pvVar2 = _Memory;
    if (uVar1 < iVar4 + 4U) {
      if (_Memory == (void *)0x0) {
        pvVar2 = malloc(0x10);
LAB_00011550:
        if (pvVar2 == (void *)0x0) goto LAB_000114dc;
      }
      else {
        _NewSize = uVar1 << 1;
        if (0x200 < uVar1) {
          _NewSize = uVar1 + 0x200;
        }
        if ((_NewSize <= uVar1) || (pvVar2 = realloc(_Memory,_NewSize), pvVar2 == (void *)0x0)) {
          pvVar2 = realloc(_Memory,iVar4 + 4U);
          goto LAB_00011550;
        }
      }
      puVar3 = (undefined4 *)((iVar4 >> 2) * 4 + (int)pvVar2);
    }
    DAT_00013110 = puVar3 + 1;
    *puVar3 = param_1;
    DAT_00013114 = pvVar2;
  }
  return param_1;
}



/* 000115a4 FUN_000115a4 */

/* Boundary evidence: original MIPS .pdata 000115a4..0001168f. Semantic name remains unreviewed. */

undefined4 FUN_000115a4(undefined4 param_1)

{
  LPCRITICAL_SECTION lpCriticalSection;
  LONG LVar1;
  undefined4 uVar2;
  
  if (DAT_00013118 == (LPCRITICAL_SECTION)0x0) {
    lpCriticalSection = malloc(0x14);
    if (lpCriticalSection != (LPCRITICAL_SECTION)0x0) {
      InitializeCriticalSection(lpCriticalSection);
      LVar1 = InterlockedCompareExchange((LONG *)&DAT_00013118,(LONG)lpCriticalSection,0);
      if (LVar1 != 0) {
        DeleteCriticalSection(lpCriticalSection);
        free(lpCriticalSection);
      }
    }
    if (DAT_00013118 == (LPCRITICAL_SECTION)0x0) goto LAB_00011648;
  }
  EnterCriticalSection(DAT_00013118);
LAB_00011648:
  uVar2 = FUN_00011498(param_1);
  FUN_00011690();
  return uVar2;
}



/* 00011690 FUN_00011690 */

/* Boundary evidence: original MIPS .pdata 00011690..000116db. Semantic name remains unreviewed. */

void FUN_00011690(void)

{
  if (DAT_00013118 != (LPCRITICAL_SECTION)0x0) {
    LeaveCriticalSection(DAT_00013118);
  }
  return;
}



/* 000116dc FUN_000116dc */

/* Boundary evidence: original MIPS .pdata 000116dc..0001170b. Semantic name remains unreviewed. */

undefined4 FUN_000116dc(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_000115a4(param_1);
  if (iVar1 == 0) {
    uVar2 = 0xffffffff;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}



/* 000117ec FUN_000117ec */

/* Boundary evidence: original MIPS .pdata 000117ec..000119e7. Semantic name remains unreviewed. */

DWORD FUN_000117ec(u_short *param_1)

{
  undefined1 *puVar1;
  uint uVar2;
  uint3 uVar3;
  u_short uVar4;
  SOCKET s;
  int iVar5;
  size_t _Size;
  DWORD DVar6;
  undefined4 local_850;
  uint local_84c;
  int local_848 [2];
  sockaddr local_840;
  sockaddr sStack_830;
  uint local_820;
  undefined1 auStack_81c [4];
  undefined1 auStack_818 [1016];
  char acStack_420 [1024];
  uint local_20;
  
  local_20 = DAT_000130e4;
  local_850 = local_850 & 0xffff0000;
  memset((void *)((int)&local_850 + 2),0,6);
  local_848[0] = 0x10;
  if (param_1 == (u_short *)0x0) {
    FUN_00012844(local_20);
    DVar6 = 0x57;
  }
  else {
    s = socket(2,2,0);
    if (s != 0xffffffff) {
      local_840.sa_family = 2;
      local_840.sa_data._0_2_ = htons(*param_1);
      local_840.sa_data._2_4_ = htonl(0);
      iVar5 = bind(s,&local_840,0x10);
      if ((iVar5 == 0) &&
         (_Size = recvfrom(s,acStack_420,0x3f8,0,&sStack_830,local_848), _Size != 0xffffffff)) {
        while (_Size != 0) {
          local_850._0_3_ = CONCAT12(local_840.sa_data[0],sStack_830.sa_data._0_2_) & 0xff00ff;
          uVar3 = (uint3)local_850 >> 0x10;
          local_850._0_2_ = CONCAT11(sStack_830.sa_data[1],(undefined1)local_850);
          local_850 = CONCAT13(local_840.sa_data[1],CONCAT12((char)uVar3,(undefined2)local_850));
          uVar4 = htons((u_short)(_Size + 8));
          local_84c = CONCAT22(local_84c._2_2_,uVar4);
          puVar1 = auStack_81c + 3;
          uVar2 = (uint)puVar1 & 3;
          *(uint *)(puVar1 + -uVar2) =
               *(uint *)(puVar1 + -uVar2) & -1 << (uVar2 + 1) * 8 | local_84c >> (3 - uVar2) * 8;
          local_820 = local_850;
          auStack_81c = (undefined1  [4])local_84c;
          memcpy(auStack_818,acStack_420,_Size);
          iVar5 = send(DAT_000130ec,(char *)&local_820,_Size + 8,0);
          if ((iVar5 == -1) ||
             (_Size = recvfrom(s,acStack_420,0x3f8,0,&sStack_830,local_848), _Size == 0xffffffff))
          break;
        }
      }
      closesocket(s);
    }
    DVar6 = GetLastError();
    FUN_00012844(local_20);
  }
  return DVar6;
}



/* 000119e8 FUN_000119e8 */

/* Boundary evidence: original MIPS .pdata 000119e8..00011c8b. Semantic name remains unreviewed. */

int FUN_000119e8(undefined2 *param_1,undefined2 *param_2,DWORD *param_3)

{
  int iVar1;
  undefined2 *puVar2;
  DWORD dwIndex;
  DWORD local_448;
  HKEY local_444;
  HKEY local_440;
  undefined4 local_43c;
  DWORD local_438 [2];
  WCHAR aWStack_430 [512];
  uint local_30;
  
  local_30 = DAT_000130e4;
  if (param_3 == (DWORD *)0x0) {
    FUN_00012844(DAT_000130e4);
    iVar1 = 0x57;
  }
  else {
    local_444 = (HKEY)0x0;
    dwIndex = 0;
    local_440 = (HKEY)0x0;
    local_448 = 0x200;
    iVar1 = RegOpenKeyExW((HKEY)0x80000002,L"Comm\\UDP2TCP",0,0,&local_444);
    if (iVar1 == 0) {
      local_448 = 4;
      iVar1 = RegQueryValueExW(local_444,L"Port",(LPDWORD)0x0,local_438,(LPBYTE)&local_43c,
                               &local_448);
      if ((iVar1 == 0) && (local_438[0] == 4)) {
        *param_1 = (short)local_43c;
        local_448 = 0x200;
        iVar1 = RegEnumKeyExW(local_444,0,aWStack_430,&local_448,(LPDWORD)0x0,(LPWSTR)0x0,
                              (LPDWORD)0x0,(PFILETIME)0x0);
        puVar2 = param_2;
        while ((iVar1 != 0x103 && (iVar1 == 0))) {
          iVar1 = RegOpenKeyExW(local_444,aWStack_430,0,0,&local_440);
          if (iVar1 != 0) goto LAB_00011c20;
          local_448 = 4;
          iVar1 = RegQueryValueExW(local_440,L"Port",(LPDWORD)0x0,local_438,(LPBYTE)&local_43c,
                                   &local_448);
          if ((iVar1 != 0) || (local_438[0] != 4)) goto LAB_00011c20;
          if (param_2 != (undefined2 *)0x0) {
            *puVar2 = (short)local_43c;
          }
          dwIndex = dwIndex + 1;
          puVar2 = puVar2 + 4;
          RegCloseKey(local_440);
          local_448 = 0x200;
          local_440 = (HKEY)0x0;
          iVar1 = RegEnumKeyExW(local_444,dwIndex,aWStack_430,&local_448,(LPDWORD)0x0,(LPWSTR)0x0,
                                (LPDWORD)0x0,(PFILETIME)0x0);
        }
        *param_3 = dwIndex;
        if (iVar1 == 0x103) {
          iVar1 = 0;
        }
      }
    }
LAB_00011c20:
    if (local_444 != (HKEY)0x0) {
      RegCloseKey(local_444);
    }
    if (local_440 != (HKEY)0x0) {
      RegCloseKey(local_440);
    }
    FUN_00012844(local_30);
  }
  return iVar1;
}



/* 00011c8c FUN_00011c8c */

/* Boundary evidence: original MIPS .pdata 00011c8c..00011ce3. Semantic name remains unreviewed. */

LRESULT FUN_00011c8c(HWND param_1,UINT param_2,WPARAM param_3,LPARAM param_4)

{
  LRESULT LVar1;
  
  if (param_2 == 2) {
    PostQuitMessage(0);
  }
  else {
    if (param_2 != 0x47c) {
      LVar1 = DefWindowProcW(param_1,param_2,param_3,param_4);
      return LVar1;
    }
    DestroyWindow(param_1);
  }
  return 0;
}



/* 00011ce4 FUN_00011ce4 */

/* Boundary evidence: original MIPS .pdata 00011ce4..00011f0f. Semantic name remains unreviewed. */

int FUN_00011ce4(SOCKET param_1,char *param_2,uint param_3,int param_4)

{
  u_short uVar1;
  uint uVar2;
  DWORD dwErrCode;
  uint uVar3;
  char *buf;
  
  if ((DAT_0001310c & 1) == 0) {
    DAT_0001310c = DAT_0001310c | 1;
    FUN_00012458((undefined4 *)&DAT_000130f8,0x1000);
    FUN_000116dc(FUN_0001299c);
  }
  if ((param_2 == (char *)0x0) || (param_3 < 0x400)) {
    SetLastError(0x57);
    return -1;
  }
  do {
    if (7 < DAT_000130fc) {
      dwErrCode = FUN_000125c8((int *)&DAT_000130f8,param_2,8);
      if (dwErrCode == 0) {
        uVar1 = ntohs(*(u_short *)(param_2 + 4));
        uVar2 = uVar1 + 0xfff8 & 0xffff;
        buf = param_2 + 8;
        if (uVar2 + 8 <= param_3) {
          if (uVar2 <= DAT_000130fc) goto LAB_00011e7c;
          goto LAB_00011e2c;
        }
        dwErrCode = 0x6f;
      }
      break;
    }
    uVar2 = recv(param_1,param_2,param_3,param_4);
    if (uVar2 == 0) {
      return 0;
    }
    if (uVar2 == 0xffffffff) {
      return -1;
    }
    dwErrCode = FUN_0001249c((uint *)&DAT_000130f8,param_2,uVar2);
  } while (dwErrCode == 0);
  goto LAB_00011ea0;
  while (DAT_000130fc < uVar2) {
LAB_00011e2c:
    uVar3 = recv(param_1,buf,param_3 - 8,param_4);
    if (uVar3 == 0) {
      return 0;
    }
    if (uVar3 == 0xffffffff) {
      return -1;
    }
    dwErrCode = FUN_0001249c((uint *)&DAT_000130f8,buf,uVar3);
    if (dwErrCode != 0) goto LAB_00011ea0;
  }
LAB_00011e7c:
  dwErrCode = FUN_000125c8((int *)&DAT_000130f8,buf,uVar2);
  if (dwErrCode == 0) {
    return uVar2 + 8;
  }
LAB_00011ea0:
  SetLastError(dwErrCode);
  return -1;
}



/* 00011f10 FUN_00011f10 */

/* Boundary evidence: original MIPS .pdata 00011f10..0001201f. Semantic name remains unreviewed. */

undefined4 FUN_00011f10(void)

{
  SOCKET s;
  int iVar1;
  sockaddr local_428;
  char acStack_418 [2];
  char local_416 [6];
  char acStack_410 [1016];
  uint local_18;
  
  local_18 = DAT_000130e4;
  s = socket(2,2,0);
  if (s != 0xffffffff) {
    local_428.sa_family = 2;
    local_428.sa_data._2_4_ = inet_addr("127.0.0.1");
    while ((iVar1 = FUN_00011ce4(DAT_000130ec,acStack_418,0x400,0), iVar1 != -1 && (iVar1 != 0))) {
      local_428.sa_data[0] = local_416[0];
      local_428.sa_data[1] = local_416[1];
      sendto(s,acStack_410,iVar1 + -8,0,&local_428,0x10);
    }
  }
  PostMessageW(DAT_000130f4,0x47c,0,0);
  if (s != 0xffffffff) {
    closesocket(s);
  }
  FUN_00012844(local_18);
  return 0;
}



/* 00012020 FUN_00012020 */

/* Boundary evidence: original MIPS .pdata 00012020..00012457. Semantic name remains unreviewed. */

undefined4 FUN_00012020(HINSTANCE param_1,int param_2)

{
  ATOM AVar1;
  HWND pHVar2;
  undefined2 extraout_var;
  int iVar3;
  hostent *phVar4;
  HANDLE pvVar5;
  SOCKET s;
  BOOL BVar6;
  uint uVar7;
  undefined2 *_Dst;
  undefined2 *lpParameter;
  uint uVar8;
  undefined4 *puVar9;
  HANDLE hObject;
  undefined4 local_240;
  u_short local_238 [2];
  char local_234 [4];
  DWORD aDStack_230 [2];
  WNDCLASSW local_228;
  MSG MStack_200;
  sockaddr local_1e0;
  sockaddr local_1d0;
  WSADATA WStack_1c0;
  uint local_30;
  
  local_30 = DAT_000130e4;
  hObject = (HANDLE)0x0;
  local_240 = 0;
  _Dst = (undefined2 *)0x0;
  pHVar2 = FindWindowW(L"U2TPROXY",L"UDP to TCP proxy");
  if (pHVar2 != (HWND)0x0) goto LAB_000123d8;
  if (param_2 == 0) {
    local_228.style = 0;
    local_228.lpfnWndProc = FUN_00011c8c;
    local_228.cbClsExtra = 0;
    local_228.cbWndExtra = 0;
    local_228.hIcon = (HICON)0x0;
    local_228.hCursor = (HCURSOR)0x0;
    local_228.hInstance = param_1;
    local_228.hbrBackground = GetStockObject(0);
    local_228.lpszMenuName = (LPCWSTR)0x0;
    local_228.lpszClassName = L"U2TPROXY";
    AVar1 = RegisterClassW(&local_228);
    if (CONCAT22(extraout_var,AVar1) == 0) goto LAB_000123d8;
  }
  DAT_000130f4 = CreateWindowExW(0,L"U2TPROXY",L"UDP to TCP proxy",0xc80000,0,0,1,1,(HWND)0x0,
                                 (HMENU)0x0,param_1,(LPVOID)0x0);
  iVar3 = FUN_000119e8(local_238,(undefined2 *)0x0,&local_240);
  uVar7 = local_240;
  if ((iVar3 == 0) && (local_240 != 0)) {
    uVar8 = local_240 << 3;
    if (0x1fffffff < local_240) {
      uVar8 = 0xffffffff;
    }
    _Dst = operator_new(uVar8);
    if (_Dst == (undefined2 *)0x0) goto LAB_000122cc;
    memset(_Dst,0,uVar7 << 3);
    iVar3 = FUN_000119e8(local_238,_Dst,&local_240);
    uVar7 = local_240;
    if ((iVar3 != 0) || (iVar3 = WSAStartup(0x101,&WStack_1c0), uVar7 = local_240, iVar3 != 0))
    goto LAB_000122cc;
    DAT_000130ec = socket(2,1,0);
    uVar7 = local_240;
    if (DAT_000130ec != 0xffffffff) {
      local_234[0] = '\x01';
      local_234[1] = '\0';
      local_234[2] = '\0';
      local_234[3] = '\0';
      setsockopt(DAT_000130ec,0xffff,0x80,local_234,4);
      phVar4 = gethostbyname("ppp_peer");
      uVar7 = local_240;
      if (phVar4 != (hostent *)0x0) {
        local_1e0.sa_family = 2;
        local_1e0.sa_data._0_2_ = htons(local_238[0]);
        memcpy(local_1e0.sa_data + 2,*phVar4->h_addr_list,(int)phVar4->h_length);
        iVar3 = connect(DAT_000130ec,&local_1e0,0x10);
        uVar7 = local_240;
        if (iVar3 == 0) {
          uVar8 = 0;
          lpParameter = _Dst;
          if (local_240 != 0) {
            do {
              pvVar5 = CreateThread((LPSECURITY_ATTRIBUTES)0x0,0,FUN_000117ec,lpParameter,0,
                                    aDStack_230);
              *(HANDLE *)(lpParameter + 2) = pvVar5;
              if (pvVar5 == (HANDLE)0x0) goto LAB_000122cc;
              uVar8 = uVar8 + 1;
              lpParameter = lpParameter + 4;
            } while (uVar8 < uVar7);
          }
          hObject = CreateThread((LPSECURITY_ATTRIBUTES)0x0,0,FUN_00011f10,(LPVOID)0x0,0,aDStack_230
                                );
          if (hObject != (HANDLE)0x0) {
            while (BVar6 = GetMessageW(&MStack_200,(HWND)0x0,0,0), BVar6 != 0) {
              TranslateMessage(&MStack_200);
              DispatchMessageW(&MStack_200);
            }
          }
        }
      }
      goto LAB_000122cc;
    }
  }
  else {
LAB_000122cc:
    if ((DAT_000130ec != 0xffffffff) && (closesocket(DAT_000130ec), hObject != (HANDLE)0x0)) {
      CloseHandle(hObject);
    }
  }
  if (_Dst != (undefined2 *)0x0) {
    local_240 = local_240 & 0xffff0000;
    memset((void *)((int)&local_240 + 2),0,6);
    s = socket(2,2,0);
    local_1d0.sa_family = 2;
    local_1d0.sa_data._2_4_ = inet_addr("127.0.0.1");
    if (uVar7 != 0) {
      puVar9 = (undefined4 *)(_Dst + 2);
      do {
        local_1d0.sa_data._0_2_ = htons(*(u_short *)(puVar9 + -1));
        local_240 = CONCAT13((char)((ushort)local_1d0.sa_data._0_2_ >> 8),
                             CONCAT12((char)local_1d0.sa_data._0_2_,(undefined2)local_240));
        sendto(s,(char *)&local_240,8,0,&local_1d0,0x10);
        WaitForSingleObject((HANDLE)*puVar9,10000);
        CloseHandle((HANDLE)*puVar9);
        uVar7 = uVar7 - 1;
        puVar9 = puVar9 + 2;
      } while (uVar7 != 0);
    }
    operator_delete(_Dst);
    closesocket(s);
  }
  WSACleanup();
LAB_000123d8:
  FUN_00012844(local_30);
  return 0;
}



/* 00012458 FUN_00012458 */

undefined4 * FUN_00012458(undefined4 *param_1,undefined4 param_2)

{
  *param_1 = param_2;
  param_1[1] = 0;
  param_1[4] = 0;
  param_1[3] = 0;
  param_1[2] = 0;
  return param_1;
}



/* 00012474 FUN_00012474 */

/* Boundary evidence: original MIPS .pdata 00012474..0001249b. Semantic name remains unreviewed. */

void FUN_00012474(int param_1)

{
  if (*(void **)(param_1 + 8) != (void *)0x0) {
    operator_delete(*(void **)(param_1 + 8));
  }
  return;
}



/* 0001249c FUN_0001249c */

/* Boundary evidence: original MIPS .pdata 0001249c..000125c7. Semantic name remains unreviewed. */

undefined4 FUN_0001249c(uint *param_1,void *param_2,uint param_3)

{
  void *pvVar1;
  uint uVar2;
  size_t _Size;
  undefined4 uVar3;
  
  uVar3 = 0;
  if (param_2 == (void *)0x0) {
    uVar3 = 0x57;
  }
  else {
    if (param_1[2] == 0) {
      pvVar1 = operator_new(*param_1);
      param_1[2] = (uint)pvVar1;
      if (pvVar1 == (void *)0x0) {
        return 0xe;
      }
      param_1[4] = (uint)pvVar1;
      param_1[3] = (uint)pvVar1;
      param_1[1] = 0;
    }
    uVar2 = *param_1;
    if (uVar2 - param_1[1] < param_3) {
      uVar3 = 0x6f;
    }
    else {
      pvVar1 = (void *)param_1[4];
      if (uVar2 + param_1[2] < (int)pvVar1 + param_3) {
        memcpy(pvVar1,param_2,(uVar2 - (int)pvVar1) + param_1[2]);
        pvVar1 = (void *)param_1[2];
        _Size = ((param_1[4] - (int)pvVar1) - *param_1) + param_3;
        param_1[4] = (uint)pvVar1;
        memcpy(pvVar1,(void *)((int)param_2 + (param_3 - _Size)),_Size);
        uVar2 = param_1[4] + _Size;
      }
      else {
        memcpy(pvVar1,param_2,param_3);
        uVar2 = param_1[4] + param_3;
      }
      param_1[4] = uVar2;
      param_1[1] = param_3 + param_1[1];
    }
  }
  return uVar3;
}



/* 000125c8 FUN_000125c8 */

/* Boundary evidence: original MIPS .pdata 000125c8..000126c3. Semantic name remains unreviewed. */

undefined4 FUN_000125c8(int *param_1,void *param_2,uint param_3)

{
  undefined4 uVar1;
  void *pvVar2;
  int iVar3;
  size_t _Size;
  
  if (param_2 == (void *)0x0) {
    uVar1 = 0x57;
  }
  else {
    iVar3 = param_1[2];
    if (iVar3 == 0) {
      uVar1 = 0xe;
    }
    else if ((uint)param_1[1] < param_3) {
      uVar1 = 0x490;
    }
    else {
      pvVar2 = (void *)param_1[3];
      if ((uint)(*param_1 + iVar3) < (int)pvVar2 + param_3) {
        memcpy(param_2,pvVar2,(*param_1 - (int)pvVar2) + iVar3);
        pvVar2 = (void *)param_1[2];
        _Size = ((param_1[3] - (int)pvVar2) - *param_1) + param_3;
        param_1[3] = (int)pvVar2;
        memcpy((void *)((int)param_2 + (param_3 - _Size)),pvVar2,_Size);
        iVar3 = param_1[3] + _Size;
      }
      else {
        memcpy(param_2,pvVar2,param_3);
        iVar3 = param_1[3] + param_3;
      }
      param_1[3] = iVar3;
      uVar1 = 0;
      param_1[1] = param_1[1] - param_3;
    }
  }
  return uVar1;
}



/* 000127c4 FUN_000127c4 */

/* Boundary evidence: original MIPS .pdata 000127c4..00012817. Semantic name remains unreviewed. */

void FUN_000127c4(int param_1,undefined4 param_2,uint *param_3)

{
  if ((*param_3 & 1) != 0) {
    param_1 = ((-param_3[2] & param_3[1] + param_1) - (param_3[1] + param_1)) + param_1;
  }
  FUN_00012844(*(uint *)(param_1 + (*param_3 & 0xfffffffc)));
  return;
}



/* 00012818 FUN_00012818 */

/* Boundary evidence: original MIPS .pdata 00012818..00012843. Semantic name remains unreviewed. */

undefined4 FUN_00012818(undefined4 param_1,int param_2,undefined4 param_3,int param_4)

{
  FUN_000127c4(param_2,param_4,*(uint **)(*(int *)(param_4 + 4) + 0xc));
  return 1;
}



/* 00012844 FUN_00012844 */

/* Boundary evidence: original MIPS .pdata 00012844..0001288b. Semantic name remains unreviewed. */

void FUN_00012844(uint param_1)

{
  if ((param_1 == DAT_000130e4) && (param_1 >> 0x10 == 0)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __report_gsfailure();
}



/* 0001299c FUN_0001299c */

/* Boundary evidence: original MIPS .pdata 0001299c..000129bb. Semantic name remains unreviewed. */

void FUN_0001299c(void)

{
  FUN_00012474(0x130f8);
  return;
}


