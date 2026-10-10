/* Automatic Ghidra pseudocode. Not original source; not runtime-verified. */

/* 402c107c FUN_402c107c */

/* Boundary evidence: original MIPS .pdata 402c107c..402c10af. Semantic name remains unreviewed. */

undefined4 FUN_402c107c(HMODULE param_1,int param_2)

{
  if (param_2 == 1) {
    DisableThreadLibraryCalls(param_1);
  }
  return 1;
}



/* 402c10b0 WSS_Init */

undefined4 WSS_Init(void)

{
                    /* 0x10b0  5  WSS_Init */
  return 0x12345678;
}



/* 402c10bc WSS_Close */

undefined4 WSS_Close(void)

{
                    /* 0x10bc  2  WSS_Close
                       0x10bc  3  WSS_Deinit
                       0x10bc  6  WSS_Open */
  return 1;
}



/* 402c10c4 DriverEntry */

undefined4 DriverEntry(void)

{
                    /* 0x10c4  1  DriverEntry
                       0x10c4  7  WSS_Read
                       0x10c4  9  WSS_Write */
  return 0;
}



/* 402c10cc WSS_Seek */

undefined4 WSS_Seek(void)

{
                    /* 0x10cc  8  WSS_Seek */
  return 0xffffffff;
}



/* 402c10d4 FUN_402c10d4 */

/* Boundary evidence: original MIPS .pdata 402c10d4..402c10ff. Semantic name remains unreviewed. */

undefined4 FUN_402c10d4(int *param_1)

{
  int iVar1;
  
  iVar1 = WSACleanup();
  *param_1 = iVar1;
  return 1;
}



/* 402c1100 FUN_402c1100 */

/* Boundary evidence: original MIPS .pdata 402c1100..402c113f. Semantic name remains unreviewed. */

undefined4 FUN_402c1100(SOCKET *param_1,int param_2,int param_3,int param_4)

{
  SOCKET SVar1;
  
  SVar1 = socket(param_2,param_3,param_4);
  *param_1 = SVar1;
  return 1;
}



/* 402c1140 FUN_402c1140 */

/* Boundary evidence: original MIPS .pdata 402c1140..402c116f. Semantic name remains unreviewed. */

undefined4 FUN_402c1140(int *param_1,SOCKET param_2)

{
  int iVar1;
  
  iVar1 = closesocket(param_2);
  *param_1 = iVar1;
  return 1;
}



/* 402c1170 FUN_402c1170 */

/* Boundary evidence: original MIPS .pdata 402c1170..402c11af. Semantic name remains unreviewed. */

undefined4 FUN_402c1170(int *param_1,SOCKET param_2,long param_3,u_long *param_4)

{
  int iVar1;
  
  iVar1 = ioctlsocket(param_2,param_3,param_4);
  *param_1 = iVar1;
  return 1;
}



/* 402c11b0 FUN_402c11b0 */

/* Boundary evidence: original MIPS .pdata 402c11b0..402c11e7. Semantic name remains unreviewed. */

undefined4 FUN_402c11b0(int *param_1,SOCKET param_2,int param_3)

{
  int iVar1;
  
  iVar1 = listen(param_2,param_3);
  *param_1 = iVar1;
  return 1;
}



/* 402c11e8 FUN_402c11e8 */

/* Boundary evidence: original MIPS .pdata 402c11e8..402c121f. Semantic name remains unreviewed. */

undefined4 FUN_402c11e8(int *param_1,SOCKET param_2,int param_3)

{
  int iVar1;
  
  iVar1 = shutdown(param_2,param_3);
  *param_1 = iVar1;
  return 1;
}



/* 402c1220 FUN_402c1220 */

/* Boundary evidence: original MIPS .pdata 402c1220..402c1373. Semantic name remains unreviewed. */

hostent * FUN_402c1220(int *param_1)

{
  hostent *_Src;
  DWORD DVar1;
  char **ppcVar2;
  char *pcVar3;
  int iVar4;
  int iVar5;
  int *_Dst;
  
  _Src = gethostbyaddr((char *)(param_1 + 3),*param_1,param_1[1]);
  if (_Src == (hostent *)0x0) {
    DVar1 = GetLastError();
    param_1[2] = DVar1;
    if (DVar1 == 0) {
      param_1[2] = 0x2af9;
    }
  }
  else {
    param_1[2] = 0;
    memset(param_1,0,0x450);
    _Dst = param_1 + 5;
    memcpy(_Dst,_Src,0x43c);
    *_Dst = (int)_Src->h_name - (int)_Src;
    if (_Src->h_aliases != (char **)0x0) {
      param_1[6] = (int)_Src->h_aliases + ((int)_Dst - (int)_Src);
      ppcVar2 = _Src->h_aliases;
      if (*ppcVar2 != (char *)0x0) {
        iVar5 = 0;
        do {
          *(int *)(param_1[6] + iVar5) = *(int *)(iVar5 + (int)ppcVar2) - (int)_Src;
          ppcVar2 = _Src->h_aliases;
          iVar5 = iVar5 + 4;
        } while (*ppcVar2 != (char *)0x0);
      }
      param_1[6] = (int)_Src->h_aliases - (int)_Src;
    }
    param_1[8] = (int)_Src->h_addr_list + ((int)_Dst - (int)_Src);
    pcVar3 = *_Src->h_addr_list;
    iVar5 = 0;
    if (pcVar3 != (char *)0x0) {
      iVar4 = 0;
      do {
        *(int *)(param_1[8] + iVar4) = (int)pcVar3 - (int)_Src;
        iVar5 = iVar5 + 1;
        iVar4 = iVar5 * 4;
        pcVar3 = _Src->h_addr_list[iVar5];
      } while (pcVar3 != (char *)0x0);
    }
    param_1[8] = (int)_Src->h_addr_list - (int)_Src;
  }
  return _Src;
}



/* 402c1374 FUN_402c1374 */

/* Boundary evidence: original MIPS .pdata 402c1374..402c14bb. Semantic name remains unreviewed. */

hostent * FUN_402c1374(DWORD *param_1)

{
  hostent *_Src;
  DWORD DVar1;
  char **ppcVar2;
  char *pcVar3;
  int iVar4;
  int iVar5;
  DWORD *_Dst;
  
  _Src = gethostbyname((char *)(param_1 + 0x19));
  if (_Src == (hostent *)0x0) {
    DVar1 = GetLastError();
    if (DVar1 == 0) {
      DVar1 = 0x2af9;
    }
    *param_1 = DVar1;
  }
  else {
    memset(param_1,0,0x450);
    _Dst = param_1 + 5;
    memcpy(_Dst,_Src,0x43c);
    *_Dst = (int)_Src->h_name - (int)_Src;
    if (_Src->h_aliases != (char **)0x0) {
      param_1[6] = (int)_Src->h_aliases + ((int)_Dst - (int)_Src);
      ppcVar2 = _Src->h_aliases;
      if (*ppcVar2 != (char *)0x0) {
        iVar5 = 0;
        do {
          *(int *)(param_1[6] + iVar5) = *(int *)(iVar5 + (int)ppcVar2) - (int)_Src;
          ppcVar2 = _Src->h_aliases;
          iVar5 = iVar5 + 4;
        } while (*ppcVar2 != (char *)0x0);
      }
      param_1[6] = (int)_Src->h_aliases - (int)_Src;
    }
    param_1[8] = (int)_Src->h_addr_list + ((int)_Dst - (int)_Src);
    pcVar3 = *_Src->h_addr_list;
    iVar5 = 0;
    if (pcVar3 != (char *)0x0) {
      iVar4 = 0;
      do {
        *(int *)(param_1[8] + iVar4) = (int)pcVar3 - (int)_Src;
        iVar5 = iVar5 + 1;
        iVar4 = iVar5 * 4;
        pcVar3 = _Src->h_addr_list[iVar5];
      } while (pcVar3 != (char *)0x0);
    }
    param_1[8] = (int)_Src->h_addr_list - (int)_Src;
  }
  return _Src;
}



/* 402c14bc FUN_402c14bc */

/* Boundary evidence: original MIPS .pdata 402c14bc..402c1513. Semantic name remains unreviewed. */

void FUN_402c14bc(int param_1)

{
  if (*(HANDLE *)(param_1 + 0x14) != (HANDLE)0x0) {
    CloseHandle(*(HANDLE *)(param_1 + 0x14));
  }
  if (*(HANDLE *)(param_1 + 0x18) != (HANDLE)0x0) {
    CloseHandle(*(HANDLE *)(param_1 + 0x18));
  }
  return;
}



/* 402c1514 FUN_402c1514 */

/* Boundary evidence: original MIPS .pdata 402c1514..402c15bf. Semantic name remains unreviewed. */

undefined4 FUN_402c1514(int param_1,HANDLE param_2)

{
  HANDLE pvVar1;
  BOOL BVar2;
  undefined4 uVar3;
  
  uVar3 = 0;
  pvVar1 = (HANDLE)__GetUserKData(0xc);
  BVar2 = DuplicateHandle(param_2,*(HANDLE *)(param_1 + 0x10),pvVar1,(LPHANDLE)(param_1 + 0x18),0,0,
                          2);
  if (BVar2 == 0) {
    uVar3 = 0x2726;
  }
  else {
    pvVar1 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,1,0,(LPCWSTR)0x0);
    *(HANDLE *)(param_1 + 0x14) = pvVar1;
    *(HANDLE *)(param_1 + 0x10) = pvVar1;
    if (pvVar1 == (HANDLE)0x0) {
      uVar3 = 0x2747;
    }
  }
  return uVar3;
}



/* 402c15c0 FUN_402c15c0 */

/* Boundary evidence: original MIPS .pdata 402c15c0..402c168f. Semantic name remains unreviewed. */

undefined4
FUN_402c15c0(undefined4 *param_1,undefined4 param_2,HANDLE param_3,HANDLE param_4,undefined4 param_5
            )

{
  HANDLE hTargetProcessHandle;
  BOOL BVar1;
  undefined4 uVar2;
  HANDLE local_20 [2];
  
  local_20[0] = (HANDLE)0x0;
  hTargetProcessHandle = (HANDLE)__GetUserKData(0xc);
  BVar1 = DuplicateHandle(param_4,param_3,hTargetProcessHandle,local_20,0,0,2);
  if (BVar1 == 0) {
    local_20[0] = (HANDLE)0x0;
  }
  if (local_20[0] == (HANDLE)0x0) {
    *param_1 = 0x2726;
  }
  else {
    uVar2 = WSAEventSelect(param_2,local_20[0],param_5);
    *param_1 = uVar2;
    CloseHandle(local_20[0]);
  }
  return 1;
}



/* 402c1690 FUN_402c1690 */

/* Boundary evidence: original MIPS .pdata 402c1690..402c16cf. Semantic name remains unreviewed. */

undefined4
FUN_402c1690(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  
  uVar1 = WSAHtonl(param_2,param_3,param_4);
  *param_1 = uVar1;
  return 1;
}



/* 402c16d0 FUN_402c16d0 */

/* Boundary evidence: original MIPS .pdata 402c16d0..402c170f. Semantic name remains unreviewed. */

undefined4
FUN_402c16d0(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  
  uVar1 = WSAHtons(param_2,param_3,param_4);
  *param_1 = uVar1;
  return 1;
}



/* 402c1710 FUN_402c1710 */

/* Boundary evidence: original MIPS .pdata 402c1710..402c1777. Semantic name remains unreviewed. */

void * FUN_402c1710(int param_1,int param_2)

{
  void *pvVar1;
  
  pvVar1 = operator_new(0x1c);
  if (pvVar1 == (void *)0x0) {
    pvVar1 = (void *)0x0;
  }
  else {
    *(int *)((int)pvVar1 + 0x14) = param_2;
    *(undefined4 *)((int)pvVar1 + 0x18) = *(undefined4 *)(param_2 + 0x18);
    *(void **)(*(int *)(param_2 + 0x18) + 0x14) = pvVar1;
    *(void **)(param_2 + 0x18) = pvVar1;
    *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + 1;
  }
  return pvVar1;
}



/* 402c1778 FUN_402c1778 */

/* Boundary evidence: original MIPS .pdata 402c1778..402c17df. Semantic name remains unreviewed. */

void * FUN_402c1778(int param_1,int param_2)

{
  void *pvVar1;
  
  pvVar1 = operator_new(0xc);
  if (pvVar1 == (void *)0x0) {
    pvVar1 = (void *)0x0;
  }
  else {
    *(int *)((int)pvVar1 + 4) = param_2;
    *(undefined4 *)((int)pvVar1 + 8) = *(undefined4 *)(param_2 + 8);
    *(void **)(*(int *)(param_2 + 8) + 4) = pvVar1;
    *(void **)(param_2 + 8) = pvVar1;
    *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + 1;
  }
  return pvVar1;
}



/* 402c17e0 FUN_402c17e0 */

/* Boundary evidence: original MIPS .pdata 402c17e0..402c18b3. Semantic name remains unreviewed. */

undefined4 FUN_402c17e0(undefined4 *param_1,uint param_2)

{
  void *_Dst;
  uint uVar1;
  
  uVar1 = param_1[7];
  if (uVar1 < param_2) {
    uVar1 = (uVar1 >> 1) + uVar1;
    if (uVar1 < param_2) {
      uVar1 = param_2;
    }
    _Dst = operator_new(uVar1 + 1);
    if ((_Dst == (void *)0x0) &&
       (_Dst = operator_new(param_2 + 1), uVar1 = param_2, _Dst == (void *)0x0)) {
      return 0;
    }
    memmove(_Dst,(void *)*param_1,param_1[7]);
    if (param_1[7] != 0x10) {
      operator_delete((void *)*param_1);
    }
    *param_1 = _Dst;
    param_1[7] = uVar1;
    *(undefined1 *)((int)_Dst + uVar1) = 0;
  }
  return 1;
}



/* 402c18b4 FUN_402c18b4 */

/* Boundary evidence: original MIPS .pdata 402c18b4..402c199b. Semantic name remains unreviewed. */

undefined4 FUN_402c18b4(undefined4 *param_1,uint param_2)

{
  void *_Dst;
  uint uVar1;
  int iVar2;
  
  uVar1 = param_1[0xb];
  if (uVar1 < param_2) {
    uVar1 = (uVar1 >> 1) + uVar1;
    if (uVar1 < param_2) {
      uVar1 = param_2;
    }
    iVar2 = uVar1 * 2;
    _Dst = operator_new(iVar2 + 2);
    if (_Dst == (void *)0x0) {
      iVar2 = param_2 * 2;
      _Dst = operator_new(iVar2 + 2);
      uVar1 = param_2;
      if (_Dst == (void *)0x0) {
        return 0;
      }
    }
    memmove(_Dst,(void *)*param_1,param_1[0xb] << 1);
    if (param_1[0xb] != 0x10) {
      operator_delete((void *)*param_1);
    }
    *param_1 = _Dst;
    param_1[0xb] = uVar1;
    *(undefined2 *)(iVar2 + (int)_Dst) = 0;
  }
  return 1;
}



/* 402c19d4 FUN_402c19d4 */

/* Boundary evidence: original MIPS .pdata 402c19d4..402c1a13. Semantic name remains unreviewed. */

undefined4 FUN_402c19d4(int *param_1,WORD param_2,LPWSADATA param_3,int param_4)

{
  int iVar1;
  
  if (param_4 == 0) {
    param_3 = (LPWSADATA)0x0;
  }
  iVar1 = WSAStartup(param_2,param_3);
  *param_1 = iVar1;
  return 1;
}



/* 402c1a14 FUN_402c1a14 */

/* Boundary evidence: original MIPS .pdata 402c1a14..402c1a77. Semantic name remains unreviewed. */

undefined4 FUN_402c1a14(int *param_1,DWORD *param_2,SOCKET param_3,sockaddr *param_4,int param_5)

{
  int iVar1;
  DWORD DVar2;
  
  iVar1 = bind(param_3,param_4,param_5);
  *param_1 = iVar1;
  if (iVar1 == -1) {
    DVar2 = GetLastError();
    *param_2 = DVar2;
  }
  return 1;
}



/* 402c1a78 FUN_402c1a78 */

/* Boundary evidence: original MIPS .pdata 402c1a78..402c1abb. Semantic name remains unreviewed. */

undefined4
FUN_402c1a78(SOCKET *param_1,SOCKET param_2,sockaddr *param_3,undefined4 param_4,int *param_5)

{
  SOCKET SVar1;
  
  SVar1 = accept(param_2,param_3,param_5);
  *param_1 = SVar1;
  return 1;
}



/* 402c1abc FUN_402c1abc */

/* Boundary evidence: original MIPS .pdata 402c1abc..402c1afb. Semantic name remains unreviewed. */

undefined4 FUN_402c1abc(int *param_1,SOCKET param_2,sockaddr *param_3,int param_4)

{
  int iVar1;
  
  iVar1 = connect(param_2,param_3,param_4);
  *param_1 = iVar1;
  return 1;
}



/* 402c1afc FUN_402c1afc */

/* Boundary evidence: original MIPS .pdata 402c1afc..402c1b3f. Semantic name remains unreviewed. */

undefined4
FUN_402c1afc(int *param_1,SOCKET param_2,sockaddr *param_3,undefined4 param_4,int *param_5)

{
  int iVar1;
  
  iVar1 = getpeername(param_2,param_3,param_5);
  *param_1 = iVar1;
  return 1;
}



/* 402c1b40 FUN_402c1b40 */

/* Boundary evidence: original MIPS .pdata 402c1b40..402c1b83. Semantic name remains unreviewed. */

undefined4
FUN_402c1b40(int *param_1,SOCKET param_2,sockaddr *param_3,undefined4 param_4,int *param_5)

{
  int iVar1;
  
  iVar1 = getsockname(param_2,param_3,param_5);
  *param_1 = iVar1;
  return 1;
}



/* 402c1b84 FUN_402c1b84 */

/* Boundary evidence: original MIPS .pdata 402c1b84..402c1bd3. Semantic name remains unreviewed. */

undefined4
FUN_402c1b84(int *param_1,SOCKET param_2,int param_3,int param_4,char *param_5,undefined4 param_6,
            int *param_7)

{
  int iVar1;
  
  iVar1 = getsockopt(param_2,param_3,param_4,param_5,param_7);
  *param_1 = iVar1;
  return 1;
}



/* 402c1bd4 FUN_402c1bd4 */

/* Boundary evidence: original MIPS .pdata 402c1bd4..402c1c1b. Semantic name remains unreviewed. */

undefined4
FUN_402c1bd4(int *param_1,SOCKET param_2,char *param_3,undefined4 param_4,int param_5,int param_6)

{
  int iVar1;
  
  iVar1 = recv(param_2,param_3,param_5,param_6);
  *param_1 = iVar1;
  return 1;
}



/* 402c1c1c FUN_402c1c1c */

/* Boundary evidence: original MIPS .pdata 402c1c1c..402c1c73. Semantic name remains unreviewed. */

undefined4
FUN_402c1c1c(int *param_1,SOCKET param_2,char *param_3,undefined4 param_4,int param_5,int param_6,
            sockaddr *param_7,undefined4 param_8,int *param_9)

{
  int iVar1;
  
  iVar1 = recvfrom(param_2,param_3,param_5,param_6,param_7,param_9);
  *param_1 = iVar1;
  return 1;
}



/* 402c1c74 FUN_402c1c74 */

/* Boundary evidence: original MIPS .pdata 402c1c74..402c1cff. Semantic name remains unreviewed. */

undefined4
FUN_402c1c74(int *param_1,fd_set *param_2,undefined4 param_3,fd_set *param_4,undefined4 param_5,
            fd_set *param_6,undefined4 param_7,timeval *param_8)

{
  int iVar1;
  
  if ((param_2 != (fd_set *)0x0) && (param_2->fd_count == 0)) {
    param_2 = (fd_set *)0x0;
  }
  if ((param_4 != (fd_set *)0x0) && (param_4->fd_count == 0)) {
    param_4 = (fd_set *)0x0;
  }
  if ((param_6 != (fd_set *)0x0) && (param_6->fd_count == 0)) {
    param_6 = (fd_set *)0x0;
  }
  iVar1 = select(0,param_2,param_4,param_6,param_8);
  *param_1 = iVar1;
  return 1;
}



/* 402c1d00 FUN_402c1d00 */

/* Boundary evidence: original MIPS .pdata 402c1d00..402c1d47. Semantic name remains unreviewed. */

undefined4
FUN_402c1d00(int *param_1,SOCKET param_2,char *param_3,undefined4 param_4,int param_5,int param_6)

{
  int iVar1;
  
  iVar1 = send(param_2,param_3,param_5,param_6);
  *param_1 = iVar1;
  return 1;
}



/* 402c1d48 FUN_402c1d48 */

/* Boundary evidence: original MIPS .pdata 402c1d48..402c1d9f. Semantic name remains unreviewed. */

undefined4
FUN_402c1d48(int *param_1,SOCKET param_2,char *param_3,undefined4 param_4,int param_5,int param_6,
            sockaddr *param_7,int param_8)

{
  int iVar1;
  
  iVar1 = sendto(param_2,param_3,param_5,param_6,param_7,param_8);
  *param_1 = iVar1;
  return 1;
}



/* 402c1da0 FUN_402c1da0 */

/* Boundary evidence: original MIPS .pdata 402c1da0..402c1def. Semantic name remains unreviewed. */

undefined4
FUN_402c1da0(int *param_1,SOCKET param_2,int param_3,int param_4,char *param_5,int param_6)

{
  int iVar1;
  
  iVar1 = setsockopt(param_2,param_3,param_4,param_5,param_6);
  *param_1 = iVar1;
  return 1;
}



/* 402c1df0 FUN_402c1df0 */

/* Boundary evidence: original MIPS .pdata 402c1df0..402c1f53. Semantic name remains unreviewed. */

undefined4
FUN_402c1df0(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,STRSAFE_LPSTR param_6,undefined4 param_7,undefined4 param_8,
            int param_9)

{
  undefined4 uVar1;
  size_t sVar2;
  uint cbDest;
  char *_Str;
  void *_Src;
  STRSAFE_LPSTR _Dst;
  STRSAFE_LPSTR pszDest;
  void *local_30 [2];
  
  local_30[0] = (void *)0x0;
  uVar1 = getaddrinfo(param_2,param_3,param_4,local_30);
  *param_1 = uVar1;
  _Src = local_30[0];
  _Dst = param_6;
  if (local_30[0] != (void *)0x0) {
    do {
      memcpy(_Dst,_Src,0x20);
      pszDest = _Dst + 0x20;
      if (*(int *)((int)_Src + 0x18) != 0) {
        *(STRSAFE_LPSTR *)(_Dst + 0x18) = pszDest + (param_9 - (int)param_6);
        memcpy(pszDest,*(void **)((int)_Src + 0x18),*(size_t *)((int)_Src + 0x10));
        pszDest = pszDest + (*(int *)((int)_Src + 0x10) + 3U & 0xfffffffc);
      }
      if (*(int *)((int)_Src + 0x14) != 0) {
        *(STRSAFE_LPSTR *)(_Dst + 0x14) = pszDest + (param_9 - (int)param_6);
        _Str = *(char **)((int)_Src + 0x14);
        sVar2 = strlen(_Str);
        cbDest = sVar2 + 3 & 0xfffffffc;
        StringCbCopyA(pszDest,cbDest,_Str);
        pszDest = pszDest + cbDest;
      }
      if (*(int *)((int)_Src + 0x1c) != 0) {
        *(STRSAFE_LPSTR *)(_Dst + 0x1c) = pszDest + (param_9 - (int)param_6);
      }
      _Src = *(void **)((int)_Src + 0x1c);
      _Dst = pszDest;
    } while (_Src != (void *)0x0);
    if (local_30[0] != (void *)0x0) {
      freeaddrinfo();
    }
  }
  return 1;
}



/* 402c1f54 FUN_402c1f54 */

/* Boundary evidence: original MIPS .pdata 402c1f54..402c1fb3. Semantic name remains unreviewed. */

undefined4
FUN_402c1f54(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
            undefined4 param_9,undefined4 param_10,undefined4 param_11)

{
  undefined4 uVar1;
  
  uVar1 = getnameinfo(param_2,param_4,param_5,param_7,param_8,param_10,param_11);
  *param_1 = uVar1;
  return 1;
}



/* 402c1fb4 FUN_402c1fb4 */

/* Boundary evidence: original MIPS .pdata 402c1fb4..402c2063. Semantic name remains unreviewed. */

undefined4
FUN_402c1fb4(size_t *param_1,void *param_2,undefined4 param_3,size_t param_4,size_t param_5,
            size_t *param_6)

{
  HANDLE hHandle;
  undefined4 uVar1;
  
  if (((int)param_4 < 0x445) && (param_6 != (size_t *)0x0)) {
    *param_6 = param_4;
    param_6[1] = param_5;
    memcpy(param_6 + 3,param_2,param_4);
    hHandle = CreateThread((LPSECURITY_ATTRIBUTES)0x0,0,FUN_402c1220,param_6,0,(LPDWORD)0x0);
    WaitForSingleObject(hHandle,0xffffffff);
    uVar1 = 1;
    *param_1 = param_6[2];
  }
  else {
    SetLastError(0x2747);
    uVar1 = 0;
  }
  return uVar1;
}



/* 402c2064 FUN_402c2064 */

/* Boundary evidence: original MIPS .pdata 402c2064..402c20f7. Semantic name remains unreviewed. */

bool FUN_402c2064(undefined4 *param_1,char *param_2,undefined4 *param_3)

{
  HANDLE hHandle;
  
  if (param_3 == (undefined4 *)0x0) {
    SetLastError(0x2747);
  }
  else {
    strcpy((char *)(param_3 + 0x19),param_2);
    hHandle = CreateThread((LPSECURITY_ATTRIBUTES)0x0,0,FUN_402c1374,param_3,0,(LPDWORD)0x0);
    WaitForSingleObject(hHandle,0xffffffff);
    *param_1 = *param_3;
  }
  return param_3 != (undefined4 *)0x0;
}



/* 402c20f8 FUN_402c20f8 */

/* Boundary evidence: original MIPS .pdata 402c20f8..402c2133. Semantic name remains unreviewed. */

undefined4 FUN_402c20f8(int *param_1,char *param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  
  iVar1 = gethostname(param_2,param_4);
  *param_1 = iVar1;
  return 1;
}



/* 402c2134 FUN_402c2134 */

/* Boundary evidence: original MIPS .pdata 402c2134..402c216f. Semantic name remains unreviewed. */

undefined4
FUN_402c2134(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  
  uVar1 = sethostname(param_2,param_4);
  *param_1 = uVar1;
  return 1;
}



/* 402c2170 FUN_402c2170 */

/* Boundary evidence: original MIPS .pdata 402c2170..402c21bf. Semantic name remains unreviewed. */

undefined4
FUN_402c2170(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
            undefined4 param_9)

{
  undefined4 uVar1;
  
  uVar1 = WSAAddressToStringW(param_2,param_4,param_5,param_7,param_9);
  *param_1 = uVar1;
  return 1;
}



/* 402c21c0 FUN_402c21c0 */

/* Boundary evidence: original MIPS .pdata 402c21c0..402c220f. Semantic name remains unreviewed. */

undefined4
FUN_402c21c0(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8)

{
  undefined4 uVar1;
  
  uVar1 = WSAStringToAddressW(param_2,param_3,param_4,param_6,param_8);
  *param_1 = uVar1;
  return 1;
}



/* 402c2210 FUN_402c2210 */

/* Boundary evidence: original MIPS .pdata 402c2210..402c2267. Semantic name remains unreviewed. */

undefined4
FUN_402c2210(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8)

{
  undefined4 uVar1;
  
  uVar1 = WSASocketW(param_2,param_3,param_4,param_5,param_7,param_8);
  *param_1 = uVar1;
  return 1;
}



/* 402c2268 FUN_402c2268 */

/* Boundary evidence: original MIPS .pdata 402c2268..402c22bb. Semantic name remains unreviewed. */

undefined4 FUN_402c2268(void *param_1)

{
  WaitForSingleObject(*(HANDLE *)((int)param_1 + 0x14),0xffffffff);
  EventModify(*(undefined4 *)((int)param_1 + 0x18),3);
  FUN_402c14bc((int)param_1);
  operator_delete(param_1);
  return 1;
}



/* 402c22bc FUN_402c22bc */

/* Boundary evidence: original MIPS .pdata 402c22bc..402c250b. Semantic name remains unreviewed. */

undefined4
FUN_402c22bc(int *param_1,DWORD *param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,
            undefined4 param_6,undefined4 param_7,undefined4 param_8,undefined4 param_9,
            undefined4 *param_10,int param_11,HANDLE param_12)

{
  undefined4 *lpParameter;
  undefined4 *puVar1;
  DWORD DVar2;
  HANDLE hThread;
  int iVar3;
  
  iVar3 = -1;
  DVar2 = 0;
  hThread = (HANDLE)0x0;
  if (param_11 == 0) {
    param_10 = (undefined4 *)0x0;
  }
  puVar1 = (undefined4 *)0x0;
  if ((param_10 == (undefined4 *)0x0) || (param_10[4] == 0)) {
LAB_402c2404:
    lpParameter = (undefined4 *)0x0;
LAB_402c2408:
    iVar3 = WSAIoctl(param_3,param_4,param_5,param_6,param_7,param_8,param_9,lpParameter,0);
    if (iVar3 == -1) {
      DVar2 = GetLastError();
    }
    if (puVar1 != (undefined4 *)0x0) {
      if ((iVar3 == -1) && (DVar2 == 0x3e5)) {
        ResumeThread(hThread);
      }
      else {
        TerminateThread(hThread,0);
        FUN_402c14bc((int)puVar1);
        operator_delete(puVar1);
      }
    }
    if (iVar3 != -1) goto LAB_402c24bc;
  }
  else {
    lpParameter = operator_new(0x1c);
    if (lpParameter == (undefined4 *)0x0) {
      lpParameter = (undefined4 *)0x0;
    }
    else {
      *lpParameter = *param_10;
      lpParameter[1] = param_10[1];
      lpParameter[2] = param_10[2];
      lpParameter[3] = param_10[3];
      lpParameter[4] = param_10[4];
      lpParameter[6] = 0;
      lpParameter[5] = 0;
    }
    if (lpParameter != (undefined4 *)0x0) {
      DVar2 = FUN_402c1514((int)lpParameter,param_12);
      if (DVar2 != 0) {
LAB_402c23d8:
        FUN_402c14bc((int)lpParameter);
        operator_delete(lpParameter);
        lpParameter = (undefined4 *)0x0;
        goto LAB_402c23f4;
      }
      hThread = CreateThread((LPSECURITY_ATTRIBUTES)0x0,0,FUN_402c2268,lpParameter,4,(LPDWORD)0x0);
      if (hThread == (HANDLE)0x0) {
        DVar2 = 0x2747;
      }
      if (DVar2 != 0) goto LAB_402c23d8;
LAB_402c23fc:
      puVar1 = lpParameter;
      if (lpParameter == (undefined4 *)0x0) goto LAB_402c2404;
      goto LAB_402c2408;
    }
    DVar2 = 0x2747;
LAB_402c23f4:
    if (DVar2 == 0) goto LAB_402c23fc;
  }
  *param_2 = DVar2;
LAB_402c24bc:
  if (hThread != (HANDLE)0x0) {
    CloseHandle(hThread);
  }
  *param_1 = iVar3;
  return 1;
}



/* 402c250c FUN_402c250c */

/* Boundary evidence: original MIPS .pdata 402c250c..402c25a3. Semantic name remains unreviewed. */

undefined4
FUN_402c250c(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
            undefined4 param_9,undefined4 param_10,undefined4 param_11,undefined4 param_12,
            undefined4 param_13,undefined4 param_14,undefined4 param_15)

{
  undefined4 uVar1;
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
  
  local_28 = param_6;
  local_24 = param_5;
  local_20 = param_8;
  local_1c = param_7;
  local_18 = param_10;
  local_14 = param_9;
  local_10 = param_12;
  local_c = param_11;
  local_30 = param_4;
  local_2c = param_3;
  uVar1 = WSARecv(param_2,&local_30,param_13,param_14,param_15,0,0);
  *param_1 = uVar1;
  return 1;
}



/* 402c25a4 FUN_402c25a4 */

/* Boundary evidence: original MIPS .pdata 402c25a4..402c264b. Semantic name remains unreviewed. */

undefined4
FUN_402c25a4(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
            undefined4 param_9,undefined4 param_10,undefined4 param_11,undefined4 param_12,
            undefined4 param_13,undefined4 param_14,undefined4 param_15,undefined4 param_16,
            undefined4 param_17,undefined4 param_18)

{
  undefined4 uVar1;
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
  
  local_28 = param_6;
  local_24 = param_5;
  local_20 = param_8;
  local_1c = param_7;
  local_14 = param_9;
  local_10 = param_12;
  local_18 = param_10;
  local_c = param_11;
  local_30 = param_4;
  local_2c = param_3;
  uVar1 = WSARecvFrom(param_2,&local_30,param_13,param_14,param_15,param_16,param_18,0,0);
  *param_1 = uVar1;
  return 1;
}



/* 402c264c FUN_402c264c */

/* Boundary evidence: original MIPS .pdata 402c264c..402c26e3. Semantic name remains unreviewed. */

undefined4
FUN_402c264c(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
            undefined4 param_9,undefined4 param_10,undefined4 param_11,undefined4 param_12,
            undefined4 param_13,undefined4 param_14,undefined4 param_15)

{
  undefined4 uVar1;
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
  
  local_28 = param_6;
  local_24 = param_5;
  local_20 = param_8;
  local_1c = param_7;
  local_18 = param_10;
  local_14 = param_9;
  local_10 = param_12;
  local_c = param_11;
  local_30 = param_4;
  local_2c = param_3;
  uVar1 = WSASend(param_2,&local_30,param_13,param_14,param_15,0,0);
  *param_1 = uVar1;
  return 1;
}



/* 402c26e4 FUN_402c26e4 */

/* Boundary evidence: original MIPS .pdata 402c26e4..402c278b. Semantic name remains unreviewed. */

undefined4
FUN_402c26e4(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
            undefined4 param_9,undefined4 param_10,undefined4 param_11,undefined4 param_12,
            undefined4 param_13,undefined4 param_14,undefined4 param_15,undefined4 param_16,
            undefined4 param_17,undefined4 param_18)

{
  undefined4 uVar1;
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
  
  local_28 = param_6;
  local_24 = param_5;
  local_20 = param_8;
  local_1c = param_7;
  local_14 = param_9;
  local_10 = param_12;
  local_18 = param_10;
  local_c = param_11;
  local_30 = param_4;
  local_2c = param_3;
  uVar1 = WSASendTo(param_2,&local_30,param_13,param_14,param_15,param_16,param_18,0,0);
  *param_1 = uVar1;
  return 1;
}



/* 402c278c FUN_402c278c */

/* Boundary evidence: original MIPS .pdata 402c278c..402c2803. Semantic name remains unreviewed. */

undefined4 FUN_402c278c(int *param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = WSAEnumNameSpaceProvidersW(param_2,param_3);
  *param_1 = iVar1;
  if ((iVar1 != -1) && (0 < iVar1)) {
    piVar2 = (int *)(param_3 + 0x1c);
    do {
      *piVar2 = (*piVar2 - (int)piVar2) + 0x1c;
      iVar1 = iVar1 + -1;
      piVar2 = piVar2 + 8;
    } while (0 < iVar1);
  }
  return 1;
}



/* 402c2804 FUN_402c2804 */

/* Boundary evidence: original MIPS .pdata 402c2804..402c28cb. Semantic name remains unreviewed. */

undefined4
FUN_402c2804(undefined4 *param_1,undefined4 param_2,HANDLE param_3,HANDLE param_4,undefined4 param_5
            )

{
  HANDLE hTargetProcessHandle;
  BOOL BVar1;
  undefined4 uVar2;
  HANDLE local_20 [2];
  
  local_20[0] = (HANDLE)0x0;
  if (param_3 != (HANDLE)0x0) {
    hTargetProcessHandle = (HANDLE)__GetUserKData(0xc);
    BVar1 = DuplicateHandle(param_4,param_3,hTargetProcessHandle,local_20,0,0,2);
    if (BVar1 == 0) {
      *param_1 = 0x2726;
      return 1;
    }
  }
  uVar2 = WSAEnumNetworkEvents(param_2,local_20[0],param_5);
  *param_1 = uVar2;
  if (local_20[0] != (HANDLE)0x0) {
    CloseHandle(local_20[0]);
  }
  return 1;
}



/* 402c28cc FUN_402c28cc */

/* Boundary evidence: original MIPS .pdata 402c28cc..402c290b. Semantic name remains unreviewed. */

undefined4
FUN_402c28cc(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,undefined4 param_6)

{
  undefined4 uVar1;
  
  uVar1 = WSAEnumProtocolsW(param_2,param_4,param_6);
  *param_1 = uVar1;
  return 1;
}



/* 402c290c FUN_402c290c */

/* Boundary evidence: original MIPS .pdata 402c290c..402c2987. Semantic name remains unreviewed. */

undefined4
FUN_402c290c(int *param_1,DWORD *param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,
            undefined4 param_6,undefined4 param_7,undefined4 param_8,undefined4 param_9,
            undefined4 param_10)

{
  int iVar1;
  DWORD DVar2;
  
  iVar1 = WSAControl(param_3,param_4,param_5,param_7,param_8,param_10);
  *param_1 = iVar1;
  if (iVar1 == -1) {
    DVar2 = GetLastError();
    *param_2 = DVar2;
  }
  return 1;
}



/* 402c2988 FUN_402c2988 */

/* Boundary evidence: original MIPS .pdata 402c2988..402c29e7. Semantic name remains unreviewed. */

undefined * FUN_402c2988(void)

{
  if ((DAT_402ca198 & 1) == 0) {
    DAT_402ca198 = DAT_402ca198 | 1;
    InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_402ca184);
    FUN_402c8a60(FUN_402c8ef8);
  }
  return &DAT_402ca184;
}



/* 402c29e8 FUN_402c29e8 */

/* Boundary evidence: original MIPS .pdata 402c29e8..402c2a47. Semantic name remains unreviewed. */

undefined * FUN_402c29e8(void)

{
  if ((DAT_402ca1b0 & 1) == 0) {
    DAT_402ca1b0 = DAT_402ca1b0 | 1;
    InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_402ca19c);
    FUN_402c8a60(FUN_402c8f18);
  }
  return &DAT_402ca19c;
}



/* 402c2a48 FUN_402c2a48 */

/* Boundary evidence: original MIPS .pdata 402c2a48..402c2aaf. Semantic name remains unreviewed. */

undefined4 * FUN_402c2a48(undefined4 *param_1,undefined4 *param_2,int param_3,undefined4 *param_4)

{
  undefined4 *puVar1;
  
  puVar1 = FUN_402c1778((int)param_1,param_3);
  if (puVar1 == (undefined4 *)0x0) {
    *param_2 = *param_1;
  }
  else {
    *puVar1 = *param_4;
    *param_2 = puVar1;
  }
  return param_2;
}



/* 402c2ab0 FUN_402c2ab0 */

/* Boundary evidence: original MIPS .pdata 402c2ab0..402c2b63. Semantic name remains unreviewed. */

int * FUN_402c2ab0(undefined4 *param_1,int *param_2,undefined4 *param_3)

{
  int iVar1;
  int iVar2;
  
  iVar1 = 0;
  if ((param_1[1] == 0) || (iVar1 = (**(code **)*param_3)(param_3,*param_1,param_1[1]), iVar1 == 0))
  {
    iVar2 = 0;
  }
  else {
    iVar2 = param_1[1];
  }
  *param_2 = iVar1;
  if (iVar1 == 0) {
    iVar2 = 0;
  }
  param_2[1] = iVar2;
  return param_2;
}



/* 402c2b64 FUN_402c2b64 */

/* Boundary evidence: original MIPS .pdata 402c2b64..402c2c17. Semantic name remains unreviewed. */

int * FUN_402c2b64(undefined4 *param_1,int *param_2,undefined4 *param_3)

{
  int iVar1;
  int iVar2;
  
  iVar1 = 0;
  if ((param_1[1] == 0) || (iVar1 = (**(code **)*param_3)(param_3,*param_1,param_1[1]), iVar1 == 0))
  {
    iVar2 = 0;
  }
  else {
    iVar2 = param_1[1];
  }
  *param_2 = iVar1;
  if (iVar1 == 0) {
    iVar2 = 0;
  }
  param_2[1] = iVar2;
  return param_2;
}



/* 402c2c18 FUN_402c2c18 */

/* Boundary evidence: original MIPS .pdata 402c2c18..402c2ccb. Semantic name remains unreviewed. */

int * FUN_402c2c18(undefined4 *param_1,int *param_2,undefined4 *param_3)

{
  int iVar1;
  int iVar2;
  
  iVar1 = 0;
  if ((param_1[1] == 0) || (iVar1 = (**(code **)*param_3)(param_3,*param_1,param_1[1]), iVar1 == 0))
  {
    iVar2 = 0;
  }
  else {
    iVar2 = param_1[1];
  }
  *param_2 = iVar1;
  if (iVar1 == 0) {
    iVar2 = 0;
  }
  param_2[1] = iVar2;
  return param_2;
}



/* 402c2ccc FUN_402c2ccc */

/* Boundary evidence: original MIPS .pdata 402c2ccc..402c2d7f. Semantic name remains unreviewed. */

int * FUN_402c2ccc(undefined4 *param_1,int *param_2,undefined4 *param_3)

{
  int iVar1;
  int iVar2;
  
  iVar1 = 0;
  if ((param_1[1] == 0) || (iVar1 = (**(code **)*param_3)(param_3,*param_1,param_1[1]), iVar1 == 0))
  {
    iVar2 = 0;
  }
  else {
    iVar2 = param_1[1];
  }
  *param_2 = iVar1;
  if (iVar1 == 0) {
    iVar2 = 0;
  }
  param_2[1] = iVar2;
  return param_2;
}



/* 402c2d80 FUN_402c2d80 */

/* Boundary evidence: original MIPS .pdata 402c2d80..402c2e43. Semantic name remains unreviewed. */

int * FUN_402c2d80(undefined4 *param_1,int *param_2,undefined4 *param_3)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  uVar3 = param_1[1];
  iVar1 = 0;
  if ((uVar3 >= 0x40000000) || ((uVar3 & 0x3fffffff) != 0)) {
    if (uVar3 < 0x40000000) {
      iVar1 = uVar3 << 2;
    }
    else {
      iVar1 = -1;
    }
    iVar1 = (**(code **)*param_3)(param_3,*param_1,iVar1);
    if (iVar1 != 0) {
      iVar2 = param_1[1];
      goto LAB_402c2e1c;
    }
  }
  iVar2 = 0;
LAB_402c2e1c:
  *param_2 = iVar1;
  if (iVar1 == 0) {
    iVar2 = 0;
  }
  param_2[1] = iVar2;
  return param_2;
}



/* 402c2e44 FUN_402c2e44 */

/* Boundary evidence: original MIPS .pdata 402c2e44..402c2f07. Semantic name remains unreviewed. */

int * FUN_402c2e44(undefined4 *param_1,int *param_2,undefined4 *param_3)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  uVar3 = param_1[1];
  iVar1 = 0;
  if ((uVar3 >= 0x80000000) || ((uVar3 & 0x7fffffff) != 0)) {
    if (uVar3 < 0x80000000) {
      iVar1 = uVar3 << 1;
    }
    else {
      iVar1 = -1;
    }
    iVar1 = (**(code **)*param_3)(param_3,*param_1,iVar1);
    if (iVar1 != 0) {
      iVar2 = param_1[1];
      goto LAB_402c2ee0;
    }
  }
  iVar2 = 0;
LAB_402c2ee0:
  *param_2 = iVar1;
  if (iVar1 == 0) {
    iVar2 = 0;
  }
  param_2[1] = iVar2;
  return param_2;
}



/* 402c2f08 FUN_402c2f08 */

/* Boundary evidence: original MIPS .pdata 402c2f08..402c2fa3. Semantic name remains unreviewed. */

undefined4 FUN_402c2f08(int *param_1,void *param_2,uint param_3,int param_4)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  
  uVar3 = param_3 + param_4;
  if ((uVar3 < param_3) || (iVar1 = FUN_402c17e0(param_1,uVar3), iVar1 == 0)) {
    uVar2 = 0;
  }
  else {
    memmove((void *)(*param_1 + param_4),param_2,param_3);
    param_1[6] = uVar3;
    *(undefined1 *)(*param_1 + uVar3) = 0;
    uVar2 = 1;
  }
  return uVar2;
}



/* 402c2fa4 FUN_402c2fa4 */

/* Boundary evidence: original MIPS .pdata 402c2fa4..402c3047. Semantic name remains unreviewed. */

undefined4 FUN_402c2fa4(int *param_1,void *param_2,uint param_3,int param_4)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  
  uVar3 = param_3 + param_4;
  if ((uVar3 < param_3) || (iVar1 = FUN_402c18b4(param_1,uVar3), iVar1 == 0)) {
    uVar2 = 0;
  }
  else {
    memmove((void *)(param_4 * 2 + *param_1),param_2,param_3 << 1);
    param_1[10] = uVar3;
    *(undefined2 *)(uVar3 * 2 + *param_1) = 0;
    uVar2 = 1;
  }
  return uVar2;
}



/* 402c3048 FUN_402c3048 */

/* Boundary evidence: original MIPS .pdata 402c3048..402c3253. Semantic name remains unreviewed. */

undefined4 FUN_402c3048(uint *param_1,undefined4 *param_2,uint param_3,undefined4 *param_4)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  uint uVar4;
  undefined4 *puVar5;
  int iVar6;
  uint uVar7;
  undefined4 *puVar8;
  
  uVar7 = (int)(param_1[1] - *param_1) >> 3;
  if (((int)(param_1[2] - *param_1) >> 3) - uVar7 < param_3) {
    if (((param_3 <= param_3 + 10) && (uVar4 = uVar7 + param_3 + 10, uVar4 < 0x20000000)) &&
       (uVar7 <= uVar4)) {
      puVar2 = operator_new(uVar4 * 8);
      if (puVar2 != (undefined4 *)0x0) {
        puVar8 = puVar2;
        for (puVar5 = (undefined4 *)*param_1; puVar5 != param_2; puVar5 = puVar5 + 2) {
          if (puVar8 != (undefined4 *)0x0) {
            *puVar8 = *puVar5;
            puVar8[1] = puVar5[1];
          }
          puVar8 = puVar8 + 2;
        }
        for (; param_3 != 0; param_3 = param_3 - 1) {
          if (puVar8 != (undefined4 *)0x0) {
            *puVar8 = *param_4;
            puVar8[1] = param_4[1];
          }
          puVar8 = puVar8 + 2;
        }
        puVar5 = (undefined4 *)param_1[1];
        if (param_2 != puVar5) {
          iVar6 = (int)param_2 - (int)puVar8;
          do {
            if (puVar8 != (undefined4 *)0x0) {
              puVar3 = (undefined4 *)(iVar6 + (int)puVar8);
              *puVar8 = *puVar3;
              puVar8[1] = puVar3[1];
            }
            puVar8 = puVar8 + 2;
          } while ((undefined4 *)(iVar6 + (int)puVar8) != puVar5);
        }
        operator_delete((void *)*param_1);
        *param_1 = (uint)puVar2;
        param_1[1] = (uint)puVar8;
        param_1[2] = (uint)(puVar2 + uVar4 * 2);
        goto LAB_402c3228;
      }
    }
    uVar1 = 0;
  }
  else {
    puVar2 = (undefined4 *)(param_1[1] - 8);
    puVar5 = param_2 + (((int)puVar2 - (int)param_2 >> 3) + param_3) * 2;
    for (; param_2 <= puVar2; puVar2 = puVar2 + -2) {
      if (puVar5 != (undefined4 *)0x0) {
        *puVar5 = *puVar2;
        puVar5[1] = puVar2[1];
      }
      puVar5 = puVar5 + -2;
    }
    for (; param_3 != 0; param_3 = param_3 - 1) {
      if (param_2 != (undefined4 *)0x0) {
        *param_2 = *param_4;
        param_2[1] = param_4[1];
      }
      param_1[1] = param_1[1] + 8;
      param_2 = param_2 + 2;
    }
LAB_402c3228:
    uVar1 = 1;
  }
  return uVar1;
}



/* 402c3254 FUN_402c3254 */

/* Boundary evidence: original MIPS .pdata 402c3254..402c32bf. Semantic name remains unreviewed. */

undefined4 * FUN_402c3254(int param_1,undefined4 *param_2,void *param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = *(undefined4 *)((int)param_3 + 4);
  *(undefined4 *)(*(int *)((int)param_3 + 8) + 4) = uVar2;
  *(undefined4 *)(*(int *)((int)param_3 + 4) + 8) = *(undefined4 *)((int)param_3 + 8);
  operator_delete(param_3);
  iVar1 = *(int *)(param_1 + 0xc);
  *param_2 = uVar2;
  *(int *)(param_1 + 0xc) = iVar1 + -1;
  return param_2;
}



/* 402c32c0 FUN_402c32c0 */

void FUN_402c32c0(int param_1,undefined4 *param_2,int param_3)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  
  iVar3 = *(int *)(param_1 + 4);
  if (param_3 != iVar3) {
    puVar2 = param_2;
    do {
      if (puVar2 != (undefined4 *)0x0) {
        puVar1 = (undefined4 *)((param_3 - (int)param_2) + (int)puVar2);
        *puVar2 = *puVar1;
        puVar2[1] = puVar1[1];
      }
      puVar2 = puVar2 + 2;
    } while ((param_3 - (int)param_2) + (int)puVar2 != iVar3);
  }
  *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + (param_3 - (int)param_2 >> 3) * -8;
  return;
}



/* 402c3318 FUN_402c3318 */

/* Boundary evidence: original MIPS .pdata 402c3318..402c33d7. Semantic name remains unreviewed. */

undefined4 FUN_402c3318(int *param_1,int param_2,undefined4 *param_3,undefined4 *param_4)

{
  int *piVar1;
  int iVar2;
  undefined4 auStack_28 [2];
  
  while( true ) {
    if (param_3 == param_4) {
      return 1;
    }
    iVar2 = *param_1;
    piVar1 = FUN_402c2a48(param_1,auStack_28,param_2,param_3);
    if (iVar2 == *piVar1) break;
    param_3 = (undefined4 *)param_3[1];
  }
  return 0;
}



/* 402c33d8 FUN_402c33d8 */

/* Boundary evidence: original MIPS .pdata 402c33d8..402c3463. Semantic name remains unreviewed. */

undefined4 * FUN_402c33d8(int param_1,undefined4 *param_2,void *param_3,void *param_4)

{
  void *pvVar1;
  undefined4 auStack_20 [2];
  
  while (param_3 != param_4) {
    pvVar1 = *(void **)((int)param_3 + 4);
    FUN_402c3254(param_1,auStack_20,param_3);
    param_3 = pvVar1;
  }
  *param_2 = param_3;
  return param_2;
}



/* 402c3464 FUN_402c3464 */

/* Boundary evidence: original MIPS .pdata 402c3464..402c34bb. Semantic name remains unreviewed. */

bool FUN_402c3464(int *param_1,undefined4 *param_2)

{
  int *piVar1;
  int iVar2;
  undefined4 auStack_10 [2];
  
  iVar2 = *param_1;
  piVar1 = FUN_402c2a48(param_1,auStack_10,*(int *)(iVar2 + 4),param_2);
  return iVar2 != *piVar1;
}



/* 402c34bc FUN_402c34bc */

/* Boundary evidence: original MIPS .pdata 402c34bc..402c352b. Semantic name remains unreviewed. */

undefined4 FUN_402c34bc(uint *param_1,uint param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  uint uVar3;
  uint uVar4;
  
  puVar2 = (undefined4 *)param_1[1];
  uVar4 = *param_1;
  uVar3 = (int)((int)puVar2 - uVar4) >> 3;
  if (uVar3 < param_2) {
    uVar1 = FUN_402c3048(param_1,puVar2,param_2 - ((int)((int)puVar2 - uVar4) >> 3),param_3);
  }
  else {
    if (param_2 < uVar3) {
      FUN_402c32c0((int)param_1,(undefined4 *)(param_2 * 8 + uVar4),(int)puVar2);
    }
    uVar1 = 1;
  }
  return uVar1;
}



/* 402c352c FUN_402c352c */

/* Boundary evidence: original MIPS .pdata 402c352c..402c357b. Semantic name remains unreviewed. */

void FUN_402c352c(int *param_1,short *param_2)

{
  short sVar1;
  uint uVar2;
  short *psVar3;
  
  if (param_2 == (short *)0x0) {
    uVar2 = 0;
  }
  else {
    sVar1 = *param_2;
    psVar3 = param_2;
    while (sVar1 != 0) {
      psVar3 = psVar3 + 1;
      sVar1 = *psVar3;
    }
    uVar2 = (int)psVar3 - (int)param_2 >> 1;
  }
  FUN_402c2fa4(param_1,param_2,uVar2,0);
  return;
}



/* 402c357c FUN_402c357c */

/* Boundary evidence: original MIPS .pdata 402c357c..402c361b. Semantic name remains unreviewed. */

undefined4 * FUN_402c357c(undefined4 *param_1,undefined4 param_2,uint param_3)

{
  void *_Dst;
  
  param_1[1] = 0;
  param_1[2] = 0;
  *param_1 = &PTR_LAB_402c104c;
  param_1[3] = 0;
  param_1[4] = param_2;
  _Dst = operator_new__(param_3);
  if ((void *)param_1[3] != (void *)0x0) {
    operator_delete((void *)param_1[3]);
  }
  param_1[3] = _Dst;
  if (_Dst != (void *)0x0) {
    param_1[2] = _Dst;
    param_1[1] = param_3;
    memcpy(_Dst,(void *)param_1[4],param_3);
  }
  return param_1;
}



/* 402c361c FUN_402c361c */

/* Boundary evidence: original MIPS .pdata 402c361c..402c366f. Semantic name remains unreviewed. */

void FUN_402c361c(undefined4 *param_1)

{
  *param_1 = &PTR_LAB_402c104c;
  if ((void *)param_1[2] != (void *)0x0) {
    memcpy((void *)param_1[4],(void *)param_1[2],param_1[1]);
  }
  if ((void *)param_1[3] != (void *)0x0) {
    operator_delete((void *)param_1[3]);
  }
  return;
}



/* 402c3670 FUN_402c3670 */

int * FUN_402c3670(int *param_1,int *param_2,uint *param_3)

{
  int *piVar1;
  uint *puVar2;
  int iVar3;
  
  if ((param_1[5] - param_1[4] & 0xfffffff8U) != 0) {
    piVar1 = (int *)((param_1[7] & *param_3) * 8 + param_1[4]);
    iVar3 = piVar1[1];
    puVar2 = (uint *)*piVar1;
    while (iVar3 != 0) {
      iVar3 = iVar3 + -1;
      if (*puVar2 == *param_3) {
        *param_2 = (int)puVar2;
        return param_2;
      }
      puVar2 = (uint *)puVar2[5];
    }
  }
  *param_2 = *param_1;
  return param_2;
}



/* 402c36ec FUN_402c36ec */

/* Boundary evidence: original MIPS .pdata 402c36ec..402c373f. Semantic name remains unreviewed. */

int * FUN_402c36ec(int *param_1,undefined4 *param_2)

{
  *param_1 = (int)param_1;
  param_1[3] = 0;
  param_1[1] = (int)param_1;
  *(undefined4 *)(*param_1 + 8) = *(undefined4 *)(*param_1 + 4);
  FUN_402c3318(param_1,*(int *)(*param_1 + 4),(undefined4 *)((undefined4 *)*param_2)[1],
               (undefined4 *)*param_2);
  return param_1;
}



/* 402c3740 FUN_402c3740 */

/* Boundary evidence: original MIPS .pdata 402c3740..402c37bb. Semantic name remains unreviewed. */

int * FUN_402c3740(int *param_1,char *param_2)

{
  char cVar1;
  uint uVar2;
  char *pcVar3;
  
  param_1[7] = 0x10;
  *param_1 = (int)(param_1 + 1);
  *(undefined1 *)(param_1 + 5) = 0;
  param_1[6] = 0;
  *(undefined1 *)*param_1 = 0;
  if (param_2 == (char *)0x0) {
    uVar2 = 0;
  }
  else {
    cVar1 = *param_2;
    pcVar3 = param_2;
    while (cVar1 != '\0') {
      pcVar3 = pcVar3 + 1;
      cVar1 = *pcVar3;
    }
    uVar2 = (int)pcVar3 - (int)param_2;
  }
  FUN_402c2f08(param_1,param_2,uVar2,0);
  return param_1;
}



/* 402c37bc FUN_402c37bc */

/* Boundary evidence: original MIPS .pdata 402c37bc..402c38db. Semantic name remains unreviewed. */

undefined4 FUN_402c37bc(int param_1,undefined *param_2)

{
  undefined2 uVar1;
  int *piVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  undefined4 *puVar6;
  int iVar7;
  int local_30 [2];
  int local_28;
  int local_24;
  
  iVar4 = *(int *)(param_1 + 4);
  if ((iVar4 == 0) || (*(uint *)(param_1 + 8) < 0x18)) {
    uVar3 = 0x57;
  }
  else {
    puVar6 = (undefined4 *)(param_1 + 0xc);
    piVar2 = FUN_402c2b64((undefined4 *)(iVar4 + 0x10),local_30,puVar6);
    iVar5 = piVar2[1];
    iVar7 = *piVar2;
    if (iVar7 == 0) {
      iVar5 = 0;
    }
    uVar1 = *(undefined2 *)(iVar4 + 0xc);
    local_28 = iVar7;
    local_24 = iVar5;
    if (*(int *)(iVar4 + 8) == 0) {
      uVar3 = 0;
    }
    else {
      uVar3 = (**(code **)*puVar6)(puVar6,*(int *)(iVar4 + 8),4);
    }
    uVar3 = (*(code *)param_2)(uVar3,uVar1,iVar7,iVar5);
  }
  return uVar3;
}



/* 402c38dc FUN_402c38dc */

/* Boundary evidence: original MIPS .pdata 402c38dc..402c38e7. Semantic name remains unreviewed. */

undefined4 FUN_402c38dc(void)

{
  return 1;
}



/* 402c38e8 FUN_402c38e8 */

/* Boundary evidence: original MIPS .pdata 402c38e8..402c39c3. Semantic name remains unreviewed. */

undefined4 FUN_402c38e8(int param_1,undefined *param_2)

{
  undefined4 uVar1;
  int iVar2;
  
  if ((*(int *)(param_1 + 4) == 0) || (*(uint *)(param_1 + 8) < 0xc)) {
    SetLastError(0x57);
    uVar1 = 0;
  }
  else {
    iVar2 = *(int *)(*(int *)(param_1 + 4) + 8);
    if (iVar2 == 0) {
      uVar1 = 0;
    }
    else {
      uVar1 = (*(code *)**(undefined4 **)(param_1 + 0xc))((undefined4 *)(param_1 + 0xc),iVar2,4);
    }
    uVar1 = (*(code *)param_2)(uVar1);
  }
  return uVar1;
}



/* 402c39c4 FUN_402c39c4 */

/* Boundary evidence: original MIPS .pdata 402c39c4..402c39cf. Semantic name remains unreviewed. */

undefined4 FUN_402c39c4(void)

{
  return 1;
}



/* 402c39d0 FUN_402c39d0 */

/* Boundary evidence: original MIPS .pdata 402c39d0..402c3adb. Semantic name remains unreviewed. */

undefined4 FUN_402c39d0(int param_1,undefined *param_2)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  
  iVar2 = *(int *)(param_1 + 4);
  if ((iVar2 == 0) || (*(uint *)(param_1 + 8) < 0x18)) {
    SetLastError(0x57);
    uVar3 = 0;
  }
  else {
    uVar3 = *(undefined4 *)(iVar2 + 0x14);
    uVar4 = *(undefined4 *)(iVar2 + 0x10);
    uVar5 = *(undefined4 *)(iVar2 + 0xc);
    if (*(int *)(iVar2 + 8) == 0) {
      uVar1 = 0;
    }
    else {
      uVar1 = (*(code *)**(undefined4 **)(param_1 + 0xc))
                        ((undefined4 *)(param_1 + 0xc),*(int *)(iVar2 + 8),4);
    }
    uVar3 = (*(code *)param_2)(uVar1,uVar5,uVar4,uVar3);
  }
  return uVar3;
}



/* 402c3adc FUN_402c3adc */

/* Boundary evidence: original MIPS .pdata 402c3adc..402c3ae7. Semantic name remains unreviewed. */

undefined4 FUN_402c3adc(void)

{
  return 1;
}



/* 402c3ae8 FUN_402c3ae8 */

/* Boundary evidence: original MIPS .pdata 402c3ae8..402c3c7f. Semantic name remains unreviewed. */

undefined4 FUN_402c3ae8(int param_1,undefined *param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 *puVar6;
  undefined4 uVar7;
  int iVar8;
  undefined4 uVar9;
  int local_38 [2];
  int local_30;
  int local_2c;
  
  iVar3 = *(int *)(param_1 + 4);
  if ((iVar3 == 0) || (*(uint *)(param_1 + 8) < 0x20)) {
    SetLastError(0x57);
    uVar9 = 0;
  }
  else {
    uVar9 = *(undefined4 *)(iVar3 + 0x1c);
    puVar6 = (undefined4 *)(param_1 + 0xc);
    piVar1 = FUN_402c2b64((undefined4 *)(iVar3 + 0x14),local_38,puVar6);
    iVar4 = piVar1[1];
    iVar8 = *piVar1;
    if (iVar8 == 0) {
      iVar4 = 0;
    }
    uVar7 = *(undefined4 *)(iVar3 + 0x10);
    local_30 = iVar8;
    local_2c = iVar4;
    if (*(int *)(iVar3 + 0xc) == 0) {
      uVar5 = 0;
    }
    else {
      uVar5 = (**(code **)*puVar6)(puVar6,*(int *)(iVar3 + 0xc),4);
    }
    if (*(int *)(iVar3 + 8) == 0) {
      uVar2 = 0;
    }
    else {
      uVar2 = (**(code **)*puVar6)(puVar6,*(int *)(iVar3 + 8),4);
    }
    uVar9 = (*(code *)param_2)(uVar2,uVar5,uVar7,iVar8,iVar4,uVar9);
  }
  return uVar9;
}



/* 402c3c80 FUN_402c3c80 */

/* Boundary evidence: original MIPS .pdata 402c3c80..402c3c8b. Semantic name remains unreviewed. */

undefined4 FUN_402c3c80(void)

{
  return 1;
}



/* 402c3c8c FUN_402c3c8c */

/* Boundary evidence: original MIPS .pdata 402c3c8c..402c3e13. Semantic name remains unreviewed. */

undefined4 FUN_402c3c8c(int param_1,undefined *param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  int iVar8;
  int local_38 [2];
  int local_30;
  int local_2c;
  
  iVar3 = *(int *)(param_1 + 4);
  if ((iVar3 == 0) || (*(uint *)(param_1 + 8) < 0x1c)) {
    SetLastError(0x57);
    uVar6 = 0;
  }
  else {
    puVar4 = (undefined4 *)(param_1 + 0xc);
    if (*(int *)(iVar3 + 0x18) == 0) {
      uVar6 = 0;
    }
    else {
      uVar6 = (**(code **)*puVar4)(puVar4,*(int *)(iVar3 + 0x18),4);
    }
    piVar1 = FUN_402c2b64((undefined4 *)(iVar3 + 0x10),local_38,puVar4);
    iVar5 = piVar1[1];
    iVar8 = *piVar1;
    if (iVar8 == 0) {
      iVar5 = 0;
    }
    uVar7 = *(undefined4 *)(iVar3 + 0xc);
    local_30 = iVar8;
    local_2c = iVar5;
    if (*(int *)(iVar3 + 8) == 0) {
      uVar2 = 0;
    }
    else {
      uVar2 = (**(code **)*puVar4)(puVar4,*(int *)(iVar3 + 8),4);
    }
    uVar6 = (*(code *)param_2)(uVar2,uVar7,iVar8,iVar5,uVar6);
  }
  return uVar6;
}



/* 402c3e14 FUN_402c3e14 */

/* Boundary evidence: original MIPS .pdata 402c3e14..402c3e1f. Semantic name remains unreviewed. */

undefined4 FUN_402c3e14(void)

{
  return 1;
}



/* 402c3e20 FUN_402c3e20 */

/* Boundary evidence: original MIPS .pdata 402c3e20..402c3f0b. Semantic name remains unreviewed. */

undefined4 FUN_402c3e20(int param_1,undefined *param_2)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar2 = *(int *)(param_1 + 4);
  if ((iVar2 == 0) || (*(uint *)(param_1 + 8) < 0x10)) {
    SetLastError(0x57);
    uVar3 = 0;
  }
  else {
    uVar3 = *(undefined4 *)(iVar2 + 0xc);
    if (*(int *)(iVar2 + 8) == 0) {
      uVar1 = 0;
    }
    else {
      uVar1 = (*(code *)**(undefined4 **)(param_1 + 0xc))
                        ((undefined4 *)(param_1 + 0xc),*(int *)(iVar2 + 8),4);
    }
    uVar3 = (*(code *)param_2)(uVar1,uVar3);
  }
  return uVar3;
}



/* 402c3f0c FUN_402c3f0c */

/* Boundary evidence: original MIPS .pdata 402c3f0c..402c3f17. Semantic name remains unreviewed. */

undefined4 FUN_402c3f0c(void)

{
  return 1;
}



/* 402c3f18 FUN_402c3f18 */

/* Boundary evidence: original MIPS .pdata 402c3f18..402c406f. Semantic name remains unreviewed. */

undefined4 FUN_402c3f18(int param_1,undefined *param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 uVar6;
  int iVar7;
  undefined4 uVar8;
  int local_38 [2];
  int local_30;
  int local_2c;
  
  iVar3 = *(int *)(param_1 + 4);
  if ((iVar3 == 0) || (*(uint *)(param_1 + 8) < 0x1c)) {
    SetLastError(0x57);
    uVar8 = 0;
  }
  else {
    uVar8 = *(undefined4 *)(iVar3 + 0x18);
    puVar5 = (undefined4 *)(param_1 + 0xc);
    piVar1 = FUN_402c2b64((undefined4 *)(iVar3 + 0x10),local_38,puVar5);
    iVar4 = piVar1[1];
    iVar7 = *piVar1;
    if (iVar7 == 0) {
      iVar4 = 0;
    }
    uVar6 = *(undefined4 *)(iVar3 + 0xc);
    local_30 = iVar7;
    local_2c = iVar4;
    if (*(int *)(iVar3 + 8) == 0) {
      uVar2 = 0;
    }
    else {
      uVar2 = (**(code **)*puVar5)(puVar5,*(int *)(iVar3 + 8),4);
    }
    uVar8 = (*(code *)param_2)(uVar2,uVar6,iVar7,iVar4,uVar8);
  }
  return uVar8;
}



/* 402c4070 FUN_402c4070 */

/* Boundary evidence: original MIPS .pdata 402c4070..402c407b. Semantic name remains unreviewed. */

undefined4 FUN_402c4070(void)

{
  return 1;
}



/* 402c407c FUN_402c407c */

/* Boundary evidence: original MIPS .pdata 402c407c..402c41ef. Semantic name remains unreviewed. */

undefined4 FUN_402c407c(int param_1,undefined *param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  int iVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  int local_40;
  undefined4 local_3c;
  int local_38;
  int local_34;
  int aiStack_30 [2];
  
  iVar3 = *(int *)(param_1 + 4);
  if ((iVar3 == 0) || (*(uint *)(param_1 + 8) < 0x24)) {
    SetLastError(0x57);
    uVar7 = 0;
  }
  else {
    puVar5 = (undefined4 *)(param_1 + 0xc);
    piVar1 = FUN_402c2b64((undefined4 *)(iVar3 + 0x1c),aiStack_30,puVar5);
    iVar4 = piVar1[1];
    iVar6 = *piVar1;
    if (iVar6 == 0) {
      iVar4 = 0;
    }
    uVar7 = *(undefined4 *)(iVar3 + 0x18);
    uVar8 = *(undefined4 *)(iVar3 + 0x14);
    local_38 = iVar6;
    local_34 = iVar4;
    FUN_402c2c18((undefined4 *)(iVar3 + 0xc),&local_40,puVar5);
    if (*(int *)(iVar3 + 8) == 0) {
      uVar2 = 0;
    }
    else {
      uVar2 = (**(code **)*puVar5)(puVar5,*(int *)(iVar3 + 8),4);
    }
    uVar7 = (*(code *)param_2)(uVar2,local_40,local_3c,uVar8,uVar7,iVar6,iVar4);
  }
  return uVar7;
}



/* 402c41f0 FUN_402c41f0 */

/* Boundary evidence: original MIPS .pdata 402c41f0..402c41fb. Semantic name remains unreviewed. */

undefined4 FUN_402c41f0(void)

{
  return 1;
}



/* 402c41fc FUN_402c41fc */

/* Boundary evidence: original MIPS .pdata 402c41fc..402c4317. Semantic name remains unreviewed. */

undefined4 FUN_402c41fc(int param_1,undefined *param_2)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  int local_20;
  undefined4 local_1c;
  
  iVar2 = *(int *)(param_1 + 4);
  if ((iVar2 == 0) || (*(uint *)(param_1 + 8) < 0x18)) {
    SetLastError(0x57);
    uVar4 = 0;
  }
  else {
    uVar4 = *(undefined4 *)(iVar2 + 0x14);
    puVar3 = (undefined4 *)(param_1 + 0xc);
    FUN_402c2c18((undefined4 *)(iVar2 + 0xc),&local_20,puVar3);
    if (*(int *)(iVar2 + 8) == 0) {
      uVar1 = 0;
    }
    else {
      uVar1 = (**(code **)*puVar3)(puVar3,*(int *)(iVar2 + 8),4);
    }
    uVar4 = (*(code *)param_2)(uVar1,local_20,local_1c,uVar4);
  }
  return uVar4;
}



/* 402c4318 FUN_402c4318 */

/* Boundary evidence: original MIPS .pdata 402c4318..402c4323. Semantic name remains unreviewed. */

undefined4 FUN_402c4318(void)

{
  return 1;
}



/* 402c4324 FUN_402c4324 */

/* Boundary evidence: original MIPS .pdata 402c4324..402c443f. Semantic name remains unreviewed. */

undefined4 FUN_402c4324(int param_1,undefined *param_2)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  int local_20;
  undefined4 local_1c;
  
  iVar2 = *(int *)(param_1 + 4);
  if ((iVar2 == 0) || (*(uint *)(param_1 + 8) < 0x18)) {
    SetLastError(0x57);
    uVar4 = 0;
  }
  else {
    uVar4 = *(undefined4 *)(iVar2 + 0x14);
    puVar3 = (undefined4 *)(param_1 + 0xc);
    FUN_402c2ccc((undefined4 *)(iVar2 + 0xc),&local_20,puVar3);
    if (*(int *)(iVar2 + 8) == 0) {
      uVar1 = 0;
    }
    else {
      uVar1 = (**(code **)*puVar3)(puVar3,*(int *)(iVar2 + 8),4);
    }
    uVar4 = (*(code *)param_2)(uVar1,local_20,local_1c,uVar4);
  }
  return uVar4;
}



/* 402c4440 FUN_402c4440 */

/* Boundary evidence: original MIPS .pdata 402c4440..402c444b. Semantic name remains unreviewed. */

undefined4 FUN_402c4440(void)

{
  return 1;
}



/* 402c444c FUN_402c444c */

/* Boundary evidence: original MIPS .pdata 402c444c..402c4607. Semantic name remains unreviewed. */

undefined4 FUN_402c444c(int param_1,undefined *param_2)

{
  int *piVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  undefined4 *puVar6;
  int iVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  int local_48;
  undefined4 local_44;
  int local_40;
  undefined4 local_3c;
  int local_38;
  int local_34;
  int aiStack_30 [2];
  
  iVar4 = *(int *)(param_1 + 4);
  if ((iVar4 == 0) || (*(uint *)(param_1 + 8) < 0x34)) {
    SetLastError(0x57);
    uVar3 = 0;
  }
  else {
    uVar8 = *(undefined4 *)(iVar4 + 0x30);
    uVar9 = *(undefined4 *)(iVar4 + 0x2c);
    puVar6 = (undefined4 *)(param_1 + 0xc);
    FUN_402c2c18((undefined4 *)(iVar4 + 0x24),&local_48,puVar6);
    uVar10 = *(undefined4 *)(iVar4 + 0x20);
    FUN_402c2c18((undefined4 *)(iVar4 + 0x18),&local_40,puVar6);
    uVar3 = *(undefined4 *)(iVar4 + 0x14);
    piVar1 = FUN_402c2b64((undefined4 *)(iVar4 + 0xc),aiStack_30,puVar6);
    iVar5 = piVar1[1];
    iVar7 = *piVar1;
    if (iVar7 == 0) {
      iVar5 = 0;
    }
    local_38 = iVar7;
    local_34 = iVar5;
    if (*(int *)(iVar4 + 8) == 0) {
      uVar2 = 0;
    }
    else {
      uVar2 = (**(code **)*puVar6)(puVar6,*(int *)(iVar4 + 8),4);
    }
    uVar3 = (*(code *)param_2)(uVar2,iVar7,iVar5,uVar3,local_40,local_3c,uVar10,local_48,local_44,
                               uVar9,uVar8);
  }
  return uVar3;
}



/* 402c4608 FUN_402c4608 */

/* Boundary evidence: original MIPS .pdata 402c4608..402c4613. Semantic name remains unreviewed. */

undefined4 FUN_402c4608(void)

{
  return 1;
}



/* 402c4614 FUN_402c4614 */

/* Boundary evidence: original MIPS .pdata 402c4614..402c479b. Semantic name remains unreviewed. */

undefined4 FUN_402c4614(int param_1,undefined *param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  int iVar8;
  int local_38 [2];
  int local_30;
  int local_2c;
  
  iVar3 = *(int *)(param_1 + 4);
  if ((iVar3 == 0) || (*(uint *)(param_1 + 8) < 0x1c)) {
    SetLastError(0x57);
    uVar6 = 0;
  }
  else {
    puVar4 = (undefined4 *)(param_1 + 0xc);
    if (*(int *)(iVar3 + 0x18) == 0) {
      uVar6 = 0;
    }
    else {
      uVar6 = (**(code **)*puVar4)(puVar4,*(int *)(iVar3 + 0x18),4);
    }
    piVar1 = FUN_402c2b64((undefined4 *)(iVar3 + 0x10),local_38,puVar4);
    iVar5 = piVar1[1];
    iVar8 = *piVar1;
    if (iVar8 == 0) {
      iVar5 = 0;
    }
    uVar7 = *(undefined4 *)(iVar3 + 0xc);
    local_30 = iVar8;
    local_2c = iVar5;
    if (*(int *)(iVar3 + 8) == 0) {
      uVar2 = 0;
    }
    else {
      uVar2 = (**(code **)*puVar4)(puVar4,*(int *)(iVar3 + 8),4);
    }
    uVar6 = (*(code *)param_2)(uVar2,uVar7,iVar8,iVar5,uVar6);
  }
  return uVar6;
}



/* 402c479c FUN_402c479c */

/* Boundary evidence: original MIPS .pdata 402c479c..402c47a7. Semantic name remains unreviewed. */

undefined4 FUN_402c479c(void)

{
  return 1;
}



/* 402c47a8 FUN_402c47a8 */

/* Boundary evidence: original MIPS .pdata 402c47a8..402c492b. Semantic name remains unreviewed. */

undefined4 FUN_402c47a8(int param_1,undefined *param_2)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  int local_30;
  undefined4 local_2c;
  
  iVar2 = *(int *)(param_1 + 4);
  if ((iVar2 == 0) || (*(uint *)(param_1 + 8) < 0x24)) {
    SetLastError(0x57);
    uVar4 = 0;
  }
  else {
    puVar3 = (undefined4 *)(param_1 + 0xc);
    if (*(int *)(iVar2 + 0x20) == 0) {
      uVar4 = 0;
    }
    else {
      uVar4 = (**(code **)*puVar3)(puVar3,*(int *)(iVar2 + 0x20),4);
    }
    FUN_402c2ab0((undefined4 *)(iVar2 + 0x18),&local_30,puVar3);
    uVar5 = *(undefined4 *)(iVar2 + 0x14);
    uVar6 = *(undefined4 *)(iVar2 + 0x10);
    uVar7 = *(undefined4 *)(iVar2 + 0xc);
    if (*(int *)(iVar2 + 8) == 0) {
      uVar1 = 0;
    }
    else {
      uVar1 = (**(code **)*puVar3)(puVar3,*(int *)(iVar2 + 8),4);
    }
    uVar4 = (*(code *)param_2)(uVar1,uVar7,uVar6,uVar5,local_30,local_2c,uVar4);
  }
  return uVar4;
}



/* 402c492c FUN_402c492c */

/* Boundary evidence: original MIPS .pdata 402c492c..402c4937. Semantic name remains unreviewed. */

undefined4 FUN_402c492c(void)

{
  return 1;
}



/* 402c4938 FUN_402c4938 */

/* Boundary evidence: original MIPS .pdata 402c4938..402c4a87. Semantic name remains unreviewed. */

undefined4 FUN_402c4938(int param_1,undefined *param_2)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  
  iVar2 = *(int *)(param_1 + 4);
  if ((iVar2 == 0) || (*(uint *)(param_1 + 8) < 0x18)) {
    SetLastError(0x57);
    uVar3 = 0;
  }
  else {
    puVar4 = (undefined4 *)(param_1 + 0xc);
    if (*(int *)(iVar2 + 0x14) == 0) {
      uVar3 = 0;
    }
    else {
      uVar3 = (**(code **)*puVar4)(puVar4,*(int *)(iVar2 + 0x14),4);
    }
    uVar5 = *(undefined4 *)(iVar2 + 0x10);
    uVar6 = *(undefined4 *)(iVar2 + 0xc);
    if (*(int *)(iVar2 + 8) == 0) {
      uVar1 = 0;
    }
    else {
      uVar1 = (**(code **)*puVar4)(puVar4,*(int *)(iVar2 + 8),4);
    }
    uVar3 = (*(code *)param_2)(uVar1,uVar6,uVar5,uVar3);
  }
  return uVar3;
}



/* 402c4a88 FUN_402c4a88 */

/* Boundary evidence: original MIPS .pdata 402c4a88..402c4a93. Semantic name remains unreviewed. */

undefined4 FUN_402c4a88(void)

{
  return 1;
}



/* 402c4a94 FUN_402c4a94 */

/* Boundary evidence: original MIPS .pdata 402c4a94..402c4b8f. Semantic name remains unreviewed. */

undefined4 FUN_402c4a94(int param_1,undefined *param_2)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  
  iVar2 = *(int *)(param_1 + 4);
  if ((iVar2 == 0) || (*(uint *)(param_1 + 8) < 0x14)) {
    SetLastError(0x57);
    uVar3 = 0;
  }
  else {
    uVar3 = *(undefined4 *)(iVar2 + 0x10);
    uVar4 = *(undefined4 *)(iVar2 + 0xc);
    if (*(int *)(iVar2 + 8) == 0) {
      uVar1 = 0;
    }
    else {
      uVar1 = (*(code *)**(undefined4 **)(param_1 + 0xc))
                        ((undefined4 *)(param_1 + 0xc),*(int *)(iVar2 + 8),4);
    }
    uVar3 = (*(code *)param_2)(uVar1,uVar4,uVar3);
  }
  return uVar3;
}



/* 402c4b90 FUN_402c4b90 */

/* Boundary evidence: original MIPS .pdata 402c4b90..402c4b9b. Semantic name remains unreviewed. */

undefined4 FUN_402c4b90(void)

{
  return 1;
}



/* 402c4b9c FUN_402c4b9c */

/* Boundary evidence: original MIPS .pdata 402c4b9c..402c4cd7. Semantic name remains unreviewed. */

undefined4 FUN_402c4b9c(int param_1,undefined *param_2)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  int local_28;
  undefined4 local_24;
  
  iVar2 = *(int *)(param_1 + 4);
  if ((iVar2 == 0) || (*(uint *)(param_1 + 8) < 0x20)) {
    SetLastError(0x57);
    uVar4 = 0;
  }
  else {
    uVar4 = *(undefined4 *)(iVar2 + 0x1c);
    uVar5 = *(undefined4 *)(iVar2 + 0x18);
    puVar3 = (undefined4 *)(param_1 + 0xc);
    FUN_402c2c18((undefined4 *)(iVar2 + 0x10),&local_28,puVar3);
    uVar6 = *(undefined4 *)(iVar2 + 0xc);
    if (*(int *)(iVar2 + 8) == 0) {
      uVar1 = 0;
    }
    else {
      uVar1 = (**(code **)*puVar3)(puVar3,*(int *)(iVar2 + 8),4);
    }
    uVar4 = (*(code *)param_2)(uVar1,uVar6,local_28,local_24,uVar5,uVar4);
  }
  return uVar4;
}



/* 402c4cd8 FUN_402c4cd8 */

/* Boundary evidence: original MIPS .pdata 402c4cd8..402c4ce3. Semantic name remains unreviewed. */

undefined4 FUN_402c4cd8(void)

{
  return 1;
}



/* 402c4ce4 FUN_402c4ce4 */

/* Boundary evidence: original MIPS .pdata 402c4ce4..402c4ea7. Semantic name remains unreviewed. */

undefined4 FUN_402c4ce4(int param_1,undefined *param_2)

{
  int *piVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  int iVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  int local_38;
  int local_34;
  int aiStack_30 [2];
  
  iVar5 = *(int *)(param_1 + 4);
  if ((iVar5 == 0) || (*(uint *)(param_1 + 8) < 0x2c)) {
    SetLastError(0x57);
    uVar7 = 0;
  }
  else {
    puVar4 = (undefined4 *)(param_1 + 0xc);
    if (*(int *)(iVar5 + 0x28) == 0) {
      uVar7 = 0;
    }
    else {
      uVar7 = (**(code **)*puVar4)(puVar4,*(int *)(iVar5 + 0x28),4);
    }
    piVar1 = FUN_402c2b64((undefined4 *)(iVar5 + 0x20),aiStack_30,puVar4);
    iVar6 = piVar1[1];
    iVar8 = *piVar1;
    if (iVar8 == 0) {
      iVar6 = 0;
    }
    uVar9 = *(undefined4 *)(iVar5 + 0x1c);
    uVar10 = *(undefined4 *)(iVar5 + 0x18);
    local_38 = iVar8;
    local_34 = iVar6;
    FUN_402c2c18((undefined4 *)(iVar5 + 0x10),&local_38,puVar4);
    uVar3 = *(undefined4 *)(iVar5 + 0xc);
    if (*(int *)(iVar5 + 8) == 0) {
      uVar2 = 0;
    }
    else {
      uVar2 = (**(code **)*puVar4)(puVar4,*(int *)(iVar5 + 8),4);
    }
    uVar7 = (*(code *)param_2)(uVar2,uVar3,local_38,local_34,uVar10,uVar9,iVar8,iVar6,uVar7);
  }
  return uVar7;
}



/* 402c4ea8 FUN_402c4ea8 */

/* Boundary evidence: original MIPS .pdata 402c4ea8..402c4eb3. Semantic name remains unreviewed. */

undefined4 FUN_402c4ea8(void)

{
  return 1;
}



/* 402c4eb4 FUN_402c4eb4 */

/* Boundary evidence: original MIPS .pdata 402c4eb4..402c5043. Semantic name remains unreviewed. */

undefined4 FUN_402c4eb4(int param_1,undefined *param_2)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 uVar4;
  int local_30;
  undefined4 local_2c;
  int local_28;
  undefined4 local_24;
  int local_20;
  undefined4 local_1c;
  
  iVar3 = *(int *)(param_1 + 4);
  if ((iVar3 == 0) || (*(uint *)(param_1 + 8) < 0x28)) {
    SetLastError(0x57);
    uVar4 = 0;
  }
  else {
    puVar2 = (undefined4 *)(param_1 + 0xc);
    if (*(int *)(iVar3 + 0x24) == 0) {
      uVar4 = 0;
    }
    else {
      uVar4 = (**(code **)*puVar2)(puVar2,*(int *)(iVar3 + 0x24),8);
    }
    FUN_402c2d80((undefined4 *)(iVar3 + 0x1c),&local_30,puVar2);
    FUN_402c2d80((undefined4 *)(iVar3 + 0x14),&local_28,puVar2);
    FUN_402c2d80((undefined4 *)(iVar3 + 0xc),&local_20,puVar2);
    if (*(int *)(iVar3 + 8) == 0) {
      uVar1 = 0;
    }
    else {
      uVar1 = (**(code **)*puVar2)(puVar2,*(int *)(iVar3 + 8),4);
    }
    uVar4 = (*(code *)param_2)(uVar1,local_20,local_1c,local_28,local_24,local_30,local_2c,uVar4);
  }
  return uVar4;
}



/* 402c5044 FUN_402c5044 */

/* Boundary evidence: original MIPS .pdata 402c5044..402c504f. Semantic name remains unreviewed. */

undefined4 FUN_402c5044(void)

{
  return 1;
}



/* 402c5050 FUN_402c5050 */

/* Boundary evidence: original MIPS .pdata 402c5050..402c51bf. Semantic name remains unreviewed. */

undefined4 FUN_402c5050(int param_1,undefined *param_2)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  int local_38;
  undefined4 local_34;
  int local_30;
  undefined4 local_2c;
  
  iVar2 = *(int *)(param_1 + 4);
  if ((iVar2 == 0) || (*(uint *)(param_1 + 8) < 0x2c)) {
    SetLastError(0x57);
    uVar4 = 0;
  }
  else {
    uVar4 = *(undefined4 *)(iVar2 + 0x28);
    puVar3 = (undefined4 *)(param_1 + 0xc);
    FUN_402c2c18((undefined4 *)(iVar2 + 0x20),&local_38,puVar3);
    uVar5 = *(undefined4 *)(iVar2 + 0x1c);
    uVar6 = *(undefined4 *)(iVar2 + 0x18);
    FUN_402c2c18((undefined4 *)(iVar2 + 0x10),&local_30,puVar3);
    uVar7 = *(undefined4 *)(iVar2 + 0xc);
    if (*(int *)(iVar2 + 8) == 0) {
      uVar1 = 0;
    }
    else {
      uVar1 = (**(code **)*puVar3)(puVar3,*(int *)(iVar2 + 8),4);
    }
    uVar4 = (*(code *)param_2)(uVar1,uVar7,local_30,local_2c,uVar6,uVar5,local_38,local_34,uVar4);
  }
  return uVar4;
}



/* 402c51c0 FUN_402c51c0 */

/* Boundary evidence: original MIPS .pdata 402c51c0..402c51cb. Semantic name remains unreviewed. */

undefined4 FUN_402c51c0(void)

{
  return 1;
}



/* 402c51cc FUN_402c51cc */

/* Boundary evidence: original MIPS .pdata 402c51cc..402c531f. Semantic name remains unreviewed. */

undefined4 FUN_402c51cc(int param_1,undefined *param_2)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  int local_30;
  undefined4 local_2c;
  
  iVar2 = *(int *)(param_1 + 4);
  if ((iVar2 == 0) || (*(uint *)(param_1 + 8) < 0x24)) {
    SetLastError(0x57);
    uVar4 = 0;
  }
  else {
    uVar4 = *(undefined4 *)(iVar2 + 0x20);
    puVar3 = (undefined4 *)(param_1 + 0xc);
    FUN_402c2c18((undefined4 *)(iVar2 + 0x18),&local_30,puVar3);
    uVar5 = *(undefined4 *)(iVar2 + 0x14);
    uVar6 = *(undefined4 *)(iVar2 + 0x10);
    uVar7 = *(undefined4 *)(iVar2 + 0xc);
    if (*(int *)(iVar2 + 8) == 0) {
      uVar1 = 0;
    }
    else {
      uVar1 = (**(code **)*puVar3)(puVar3,*(int *)(iVar2 + 8),4);
    }
    uVar4 = (*(code *)param_2)(uVar1,uVar7,uVar6,uVar5,local_30,local_2c,uVar4);
  }
  return uVar4;
}



/* 402c5320 FUN_402c5320 */

/* Boundary evidence: original MIPS .pdata 402c5320..402c532b. Semantic name remains unreviewed. */

undefined4 FUN_402c5320(void)

{
  return 1;
}



/* 402c532c FUN_402c532c */

/* Boundary evidence: original MIPS .pdata 402c532c..402c551b. Semantic name remains unreviewed. */

undefined4 FUN_402c532c(int param_1,undefined *param_2)

{
  int *piVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 *puVar5;
  int iVar6;
  undefined4 uVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int local_48;
  undefined4 local_44;
  int local_40;
  int local_3c;
  int local_38;
  int local_34;
  int aiStack_30 [2];
  
  iVar4 = *(int *)(param_1 + 4);
  if ((iVar4 == 0) || (*(uint *)(param_1 + 8) < 0x2c)) {
    SetLastError(0x57);
    uVar7 = 0;
  }
  else {
    puVar5 = (undefined4 *)(param_1 + 0xc);
    if (*(int *)(iVar4 + 0x28) == 0) {
      uVar7 = 0;
    }
    else {
      uVar7 = (**(code **)*puVar5)(puVar5,*(int *)(iVar4 + 0x28),4);
    }
    FUN_402c2e44((undefined4 *)(iVar4 + 0x20),&local_48,puVar5);
    piVar1 = FUN_402c2b64((undefined4 *)(iVar4 + 0x18),aiStack_30,puVar5);
    iVar8 = piVar1[1];
    iVar10 = *piVar1;
    if (iVar10 == 0) {
      iVar8 = 0;
    }
    uVar3 = *(undefined4 *)(iVar4 + 0x14);
    local_40 = iVar10;
    local_3c = iVar8;
    piVar1 = FUN_402c2b64((undefined4 *)(iVar4 + 0xc),&local_40,puVar5);
    iVar6 = piVar1[1];
    iVar9 = *piVar1;
    if (iVar9 == 0) {
      iVar6 = 0;
    }
    local_38 = iVar9;
    local_34 = iVar6;
    if (*(int *)(iVar4 + 8) == 0) {
      uVar2 = 0;
    }
    else {
      uVar2 = (**(code **)*puVar5)(puVar5,*(int *)(iVar4 + 8),4);
    }
    uVar7 = (*(code *)param_2)(uVar2,iVar9,iVar6,uVar3,iVar10,iVar8,local_48,local_44,uVar7);
  }
  return uVar7;
}



/* 402c551c FUN_402c551c */

/* Boundary evidence: original MIPS .pdata 402c551c..402c5527. Semantic name remains unreviewed. */

undefined4 FUN_402c551c(void)

{
  return 1;
}



/* 402c5528 FUN_402c5528 */

/* Boundary evidence: original MIPS .pdata 402c5528..402c56af. Semantic name remains unreviewed. */

undefined4 FUN_402c5528(int param_1,undefined *param_2)

{
  int *piVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  undefined4 *puVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  int aiStack_30 [2];
  
  iVar5 = *(int *)(param_1 + 4);
  if ((iVar5 == 0) || (*(uint *)(param_1 + 8) < 0x28)) {
    SetLastError(0x57);
    uVar3 = 0;
  }
  else {
    uVar3 = *(undefined4 *)(iVar5 + 0x24);
    uVar4 = *(undefined4 *)(iVar5 + 0x20);
    puVar7 = (undefined4 *)(param_1 + 0xc);
    piVar1 = FUN_402c2b64((undefined4 *)(iVar5 + 0x18),aiStack_30,puVar7);
    iVar6 = piVar1[1];
    iVar11 = *piVar1;
    if (iVar11 == 0) {
      iVar6 = 0;
    }
    uVar8 = *(undefined4 *)(iVar5 + 0x14);
    uVar9 = *(undefined4 *)(iVar5 + 0x10);
    uVar10 = *(undefined4 *)(iVar5 + 0xc);
    iVar12 = iVar11;
    iVar13 = iVar6;
    if (*(int *)(iVar5 + 8) == 0) {
      uVar2 = 0;
    }
    else {
      uVar2 = (**(code **)*puVar7)(puVar7,*(int *)(iVar5 + 8),4);
    }
    uVar3 = (*(code *)param_2)(uVar2,uVar10,uVar9,uVar8,iVar11,iVar6,uVar4,uVar3,uVar3,uVar4,iVar12,
                               iVar13);
  }
  return uVar3;
}



/* 402c56b0 FUN_402c56b0 */

/* Boundary evidence: original MIPS .pdata 402c56b0..402c56bb. Semantic name remains unreviewed. */

undefined4 FUN_402c56b0(void)

{
  return 1;
}



/* 402c56bc FUN_402c56bc */

/* Boundary evidence: original MIPS .pdata 402c56bc..402c592b. Semantic name remains unreviewed. */

undefined4 FUN_402c56bc(int param_1,undefined *param_2)

{
  int *piVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  int iVar8;
  undefined4 *puVar9;
  int iVar10;
  undefined4 uVar11;
  int iVar12;
  int iVar13;
  undefined4 uVar14;
  int iVar15;
  int aiStack_40 [2];
  int aiStack_38 [2];
  int aiStack_30 [2];
  
  iVar8 = *(int *)(param_1 + 4);
  if ((iVar8 == 0) || (*(uint *)(param_1 + 8) < 0x38)) {
    SetLastError(0x57);
    uVar3 = 0;
  }
  else {
    uVar3 = *(undefined4 *)(iVar8 + 0x34);
    puVar9 = (undefined4 *)(param_1 + 0xc);
    piVar1 = FUN_402c2b64((undefined4 *)(iVar8 + 0x2c),aiStack_40,puVar9);
    iVar10 = piVar1[1];
    iVar4 = *piVar1;
    if (iVar4 == 0) {
      iVar10 = 0;
    }
    if (*(int *)(iVar8 + 0x28) == 0) {
      uVar14 = 0;
    }
    else {
      uVar14 = (**(code **)*puVar9)(puVar9,*(int *)(iVar8 + 0x28),4);
    }
    piVar1 = FUN_402c2b64((undefined4 *)(iVar8 + 0x20),aiStack_38,puVar9);
    iVar13 = piVar1[1];
    iVar15 = *piVar1;
    if (iVar15 == 0) {
      iVar13 = 0;
    }
    piVar1 = FUN_402c2b64((undefined4 *)(iVar8 + 0x18),aiStack_30,puVar9);
    iVar12 = piVar1[1];
    iVar5 = *piVar1;
    if (iVar5 == 0) {
      iVar12 = 0;
    }
    uVar6 = *(undefined4 *)(iVar8 + 0x14);
    uVar7 = *(undefined4 *)(iVar8 + 0x10);
    if (*(int *)(iVar8 + 0xc) == 0) {
      uVar11 = 0;
    }
    else {
      uVar11 = (**(code **)*puVar9)(puVar9,*(int *)(iVar8 + 0xc),4);
    }
    if (*(int *)(iVar8 + 8) == 0) {
      uVar2 = 0;
    }
    else {
      uVar2 = (**(code **)*puVar9)(puVar9,*(int *)(iVar8 + 8),4);
    }
    uVar3 = (*(code *)param_2)(uVar2,uVar11,uVar7,uVar6,iVar5,iVar12,iVar15,iVar13,uVar14,iVar4,
                               iVar10,uVar3);
  }
  return uVar3;
}



/* 402c592c FUN_402c592c */

/* Boundary evidence: original MIPS .pdata 402c592c..402c5937. Semantic name remains unreviewed. */

undefined4 FUN_402c592c(void)

{
  return 1;
}



/* 402c5938 FUN_402c5938 */

/* Boundary evidence: original MIPS .pdata 402c5938..402c5b73. Semantic name remains unreviewed. */

undefined4 FUN_402c5938(int param_1,undefined *param_2)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  int local_50;
  undefined4 local_4c;
  int local_48;
  undefined4 local_44;
  int local_40;
  undefined4 local_3c;
  int local_38;
  undefined4 local_34;
  int local_30;
  undefined4 local_2c;
  
  iVar3 = *(int *)(param_1 + 4);
  if ((iVar3 == 0) || (*(uint *)(param_1 + 8) < 0x44)) {
    SetLastError(0x57);
    uVar5 = 0;
  }
  else {
    puVar2 = (undefined4 *)(param_1 + 0xc);
    if (*(int *)(iVar3 + 0x40) == 0) {
      uVar5 = 0;
    }
    else {
      uVar5 = (**(code **)*puVar2)(puVar2,*(int *)(iVar3 + 0x40),4);
    }
    if (*(int *)(iVar3 + 0x3c) == 0) {
      uVar4 = 0;
    }
    else {
      uVar4 = (**(code **)*puVar2)(puVar2,*(int *)(iVar3 + 0x3c),4);
    }
    uVar6 = *(undefined4 *)(iVar3 + 0x38);
    FUN_402c2c18((undefined4 *)(iVar3 + 0x30),&local_50,puVar2);
    FUN_402c2c18((undefined4 *)(iVar3 + 0x28),&local_48,puVar2);
    FUN_402c2c18((undefined4 *)(iVar3 + 0x20),&local_40,puVar2);
    FUN_402c2c18((undefined4 *)(iVar3 + 0x18),&local_38,puVar2);
    FUN_402c2c18((undefined4 *)(iVar3 + 0x10),&local_30,puVar2);
    uVar7 = *(undefined4 *)(iVar3 + 0xc);
    if (*(int *)(iVar3 + 8) == 0) {
      uVar1 = 0;
    }
    else {
      uVar1 = (**(code **)*puVar2)(puVar2,*(int *)(iVar3 + 8),4);
    }
    uVar5 = (*(code *)param_2)(uVar1,uVar7,local_30,local_2c,local_38,local_34,local_40,local_3c,
                               local_48,local_44,local_50,local_4c,uVar6,uVar4,uVar5);
  }
  return uVar5;
}



/* 402c5b74 FUN_402c5b74 */

/* Boundary evidence: original MIPS .pdata 402c5b74..402c5b7f. Semantic name remains unreviewed. */

undefined4 FUN_402c5b74(void)

{
  return 1;
}



/* 402c5b80 FUN_402c5b80 */

/* Boundary evidence: original MIPS .pdata 402c5b80..402c5e3f. Semantic name remains unreviewed. */

undefined4 FUN_402c5b80(int param_1,undefined *param_2)

{
  int *piVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  int local_58;
  undefined4 local_54;
  int local_50;
  undefined4 local_4c;
  int local_48;
  undefined4 local_44;
  int local_40;
  undefined4 local_3c;
  int local_38;
  int local_34;
  int aiStack_30 [2];
  
  iVar6 = *(int *)(param_1 + 4);
  if ((iVar6 == 0) || (*(uint *)(param_1 + 8) < 0x50)) {
    SetLastError(0x57);
    uVar11 = 0;
  }
  else {
    puVar5 = (undefined4 *)(param_1 + 0xc);
    if (*(int *)(iVar6 + 0x4c) == 0) {
      uVar11 = 0;
    }
    else {
      uVar11 = (**(code **)*puVar5)(puVar5,*(int *)(iVar6 + 0x4c),4);
    }
    piVar1 = FUN_402c2b64((undefined4 *)(iVar6 + 0x44),aiStack_30,puVar5);
    iVar7 = piVar1[1];
    iVar8 = *piVar1;
    if (iVar8 == 0) {
      iVar7 = 0;
    }
    local_38 = iVar8;
    local_34 = iVar7;
    if (*(int *)(iVar6 + 0x40) == 0) {
      uVar10 = 0;
    }
    else {
      uVar10 = (**(code **)*puVar5)(puVar5,*(int *)(iVar6 + 0x40),4);
    }
    if (*(int *)(iVar6 + 0x3c) == 0) {
      uVar9 = 0;
    }
    else {
      uVar9 = (**(code **)*puVar5)(puVar5,*(int *)(iVar6 + 0x3c),4);
    }
    uVar3 = *(undefined4 *)(iVar6 + 0x38);
    FUN_402c2c18((undefined4 *)(iVar6 + 0x30),&local_58,puVar5);
    FUN_402c2c18((undefined4 *)(iVar6 + 0x28),&local_50,puVar5);
    FUN_402c2c18((undefined4 *)(iVar6 + 0x20),&local_48,puVar5);
    FUN_402c2c18((undefined4 *)(iVar6 + 0x18),&local_40,puVar5);
    FUN_402c2c18((undefined4 *)(iVar6 + 0x10),&local_38,puVar5);
    uVar4 = *(undefined4 *)(iVar6 + 0xc);
    if (*(int *)(iVar6 + 8) == 0) {
      uVar2 = 0;
    }
    else {
      uVar2 = (**(code **)*puVar5)(puVar5,*(int *)(iVar6 + 8),4);
    }
    uVar11 = (*(code *)param_2)(uVar2,uVar4,local_38,local_34,local_40,local_3c,local_48,local_44,
                                local_50,local_4c,local_58,local_54,uVar3,uVar9,uVar10,iVar8,iVar7,
                                uVar11);
  }
  return uVar11;
}



/* 402c5e40 FUN_402c5e40 */

/* Boundary evidence: original MIPS .pdata 402c5e40..402c5e4b. Semantic name remains unreviewed. */

undefined4 FUN_402c5e40(void)

{
  return 1;
}



/* 402c5e4c FUN_402c5e4c */

/* Boundary evidence: original MIPS .pdata 402c5e4c..402c6057. Semantic name remains unreviewed. */

undefined4 FUN_402c5e4c(int param_1,undefined *param_2)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  int local_50;
  undefined4 local_4c;
  int local_48;
  undefined4 local_44;
  int local_40;
  undefined4 local_3c;
  int local_38;
  undefined4 local_34;
  int local_30;
  undefined4 local_2c;
  
  iVar3 = *(int *)(param_1 + 4);
  if ((iVar3 == 0) || (*(uint *)(param_1 + 8) < 0x44)) {
    SetLastError(0x57);
    uVar5 = 0;
  }
  else {
    uVar5 = *(undefined4 *)(iVar3 + 0x40);
    puVar2 = (undefined4 *)(param_1 + 0xc);
    if (*(int *)(iVar3 + 0x3c) == 0) {
      uVar4 = 0;
    }
    else {
      uVar4 = (**(code **)*puVar2)(puVar2,*(int *)(iVar3 + 0x3c),4);
    }
    uVar6 = *(undefined4 *)(iVar3 + 0x38);
    FUN_402c2c18((undefined4 *)(iVar3 + 0x30),&local_50,puVar2);
    FUN_402c2c18((undefined4 *)(iVar3 + 0x28),&local_48,puVar2);
    FUN_402c2c18((undefined4 *)(iVar3 + 0x20),&local_40,puVar2);
    FUN_402c2c18((undefined4 *)(iVar3 + 0x18),&local_38,puVar2);
    FUN_402c2c18((undefined4 *)(iVar3 + 0x10),&local_30,puVar2);
    uVar7 = *(undefined4 *)(iVar3 + 0xc);
    if (*(int *)(iVar3 + 8) == 0) {
      uVar1 = 0;
    }
    else {
      uVar1 = (**(code **)*puVar2)(puVar2,*(int *)(iVar3 + 8),4);
    }
    uVar5 = (*(code *)param_2)(uVar1,uVar7,local_30,local_2c,local_38,local_34,local_40,local_3c,
                               local_48,local_44,local_50,local_4c,uVar6,uVar4,uVar5);
  }
  return uVar5;
}



/* 402c6058 FUN_402c6058 */

/* Boundary evidence: original MIPS .pdata 402c6058..402c6063. Semantic name remains unreviewed. */

undefined4 FUN_402c6058(void)

{
  return 1;
}



/* 402c6064 FUN_402c6064 */

/* Boundary evidence: original MIPS .pdata 402c6064..402c62c3. Semantic name remains unreviewed. */

undefined4 FUN_402c6064(int param_1,undefined *param_2)

{
  int *piVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  undefined4 *puVar6;
  int iVar7;
  int iVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  int local_58;
  undefined4 local_54;
  int local_50;
  undefined4 local_4c;
  int local_48;
  undefined4 local_44;
  int local_40;
  undefined4 local_3c;
  int local_38;
  int local_34;
  int aiStack_30 [2];
  
  iVar5 = *(int *)(param_1 + 4);
  if ((iVar5 == 0) || (*(uint *)(param_1 + 8) < 0x50)) {
    SetLastError(0x57);
    uVar11 = 0;
  }
  else {
    uVar11 = *(undefined4 *)(iVar5 + 0x4c);
    puVar6 = (undefined4 *)(param_1 + 0xc);
    piVar1 = FUN_402c2b64((undefined4 *)(iVar5 + 0x44),aiStack_30,puVar6);
    iVar7 = piVar1[1];
    iVar8 = *piVar1;
    if (iVar8 == 0) {
      iVar7 = 0;
    }
    uVar10 = *(undefined4 *)(iVar5 + 0x40);
    local_38 = iVar8;
    local_34 = iVar7;
    if (*(int *)(iVar5 + 0x3c) == 0) {
      uVar9 = 0;
    }
    else {
      uVar9 = (**(code **)*puVar6)(puVar6,*(int *)(iVar5 + 0x3c),4);
    }
    uVar3 = *(undefined4 *)(iVar5 + 0x38);
    FUN_402c2c18((undefined4 *)(iVar5 + 0x30),&local_58,puVar6);
    FUN_402c2c18((undefined4 *)(iVar5 + 0x28),&local_50,puVar6);
    FUN_402c2c18((undefined4 *)(iVar5 + 0x20),&local_48,puVar6);
    FUN_402c2c18((undefined4 *)(iVar5 + 0x18),&local_40,puVar6);
    FUN_402c2c18((undefined4 *)(iVar5 + 0x10),&local_38,puVar6);
    uVar4 = *(undefined4 *)(iVar5 + 0xc);
    if (*(int *)(iVar5 + 8) == 0) {
      uVar2 = 0;
    }
    else {
      uVar2 = (**(code **)*puVar6)(puVar6,*(int *)(iVar5 + 8),4);
    }
    uVar11 = (*(code *)param_2)(uVar2,uVar4,local_38,local_34,local_40,local_3c,local_48,local_44,
                                local_50,local_4c,local_58,local_54,uVar3,uVar9,uVar10,iVar8,iVar7,
                                uVar11);
  }
  return uVar11;
}



/* 402c62c4 FUN_402c62c4 */

/* Boundary evidence: original MIPS .pdata 402c62c4..402c62cf. Semantic name remains unreviewed. */

undefined4 FUN_402c62c4(void)

{
  return 1;
}



/* 402c62d0 FUN_402c62d0 */

/* Boundary evidence: original MIPS .pdata 402c62d0..402c6447. Semantic name remains unreviewed. */

undefined4 FUN_402c62d0(int param_1,undefined *param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 *puVar6;
  int iVar7;
  int local_30 [2];
  int local_28;
  int local_24;
  
  iVar3 = *(int *)(param_1 + 4);
  if ((iVar3 == 0) || (*(uint *)(param_1 + 8) < 0x18)) {
    SetLastError(0x57);
    uVar5 = 0;
  }
  else {
    puVar6 = (undefined4 *)(param_1 + 0xc);
    piVar1 = FUN_402c2b64((undefined4 *)(iVar3 + 0x10),local_30,puVar6);
    iVar4 = piVar1[1];
    iVar7 = *piVar1;
    if (iVar7 == 0) {
      iVar4 = 0;
    }
    local_28 = iVar7;
    local_24 = iVar4;
    if (*(int *)(iVar3 + 0xc) == 0) {
      uVar5 = 0;
    }
    else {
      uVar5 = (**(code **)*puVar6)(puVar6,*(int *)(iVar3 + 0xc),4);
    }
    if (*(int *)(iVar3 + 8) == 0) {
      uVar2 = 0;
    }
    else {
      uVar2 = (**(code **)*puVar6)(puVar6,*(int *)(iVar3 + 8),4);
    }
    uVar5 = (*(code *)param_2)(uVar2,uVar5,iVar7,iVar4);
  }
  return uVar5;
}



/* 402c6448 FUN_402c6448 */

/* Boundary evidence: original MIPS .pdata 402c6448..402c6453. Semantic name remains unreviewed. */

undefined4 FUN_402c6448(void)

{
  return 1;
}



/* 402c6454 FUN_402c6454 */

/* Boundary evidence: original MIPS .pdata 402c6454..402c65bb. Semantic name remains unreviewed. */

undefined4 FUN_402c6454(int param_1,undefined *param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  int iVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  int local_38 [2];
  int local_30;
  int local_2c;
  
  iVar3 = *(int *)(param_1 + 4);
  if ((iVar3 == 0) || (*(uint *)(param_1 + 8) < 0x20)) {
    SetLastError(0x57);
    uVar7 = 0;
  }
  else {
    puVar5 = (undefined4 *)(param_1 + 0xc);
    piVar1 = FUN_402c2b64((undefined4 *)(iVar3 + 0x18),local_38,puVar5);
    iVar4 = piVar1[1];
    iVar6 = *piVar1;
    if (iVar6 == 0) {
      iVar4 = 0;
    }
    uVar7 = *(undefined4 *)(iVar3 + 0x14);
    uVar8 = *(undefined4 *)(iVar3 + 0x10);
    uVar9 = *(undefined4 *)(iVar3 + 0xc);
    local_30 = iVar6;
    local_2c = iVar4;
    if (*(int *)(iVar3 + 8) == 0) {
      uVar2 = 0;
    }
    else {
      uVar2 = (**(code **)*puVar5)(puVar5,*(int *)(iVar3 + 8),4);
    }
    uVar7 = (*(code *)param_2)(uVar2,uVar9,uVar8,uVar7,iVar6,iVar4);
  }
  return uVar7;
}



/* 402c65bc FUN_402c65bc */

/* Boundary evidence: original MIPS .pdata 402c65bc..402c65c7. Semantic name remains unreviewed. */

undefined4 FUN_402c65bc(void)

{
  return 1;
}



/* 402c65c8 FUN_402c65c8 */

/* Boundary evidence: original MIPS .pdata 402c65c8..402c675b. Semantic name remains unreviewed. */

undefined4 FUN_402c65c8(int param_1,undefined *param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  int local_38;
  undefined4 local_34;
  int local_30;
  int local_2c;
  int aiStack_28 [2];
  
  iVar3 = *(int *)(param_1 + 4);
  if ((iVar3 == 0) || (*(uint *)(param_1 + 8) < 0x20)) {
    SetLastError(0x57);
    uVar6 = 0;
  }
  else {
    puVar4 = (undefined4 *)(param_1 + 0xc);
    if (*(int *)(iVar3 + 0x1c) == 0) {
      uVar6 = 0;
    }
    else {
      uVar6 = (**(code **)*puVar4)(puVar4,*(int *)(iVar3 + 0x1c),4);
    }
    piVar1 = FUN_402c2b64((undefined4 *)(iVar3 + 0x14),aiStack_28,puVar4);
    iVar5 = piVar1[1];
    iVar7 = *piVar1;
    if (iVar7 == 0) {
      iVar5 = 0;
    }
    local_30 = iVar7;
    local_2c = iVar5;
    FUN_402c2ab0((undefined4 *)(iVar3 + 0xc),&local_38,puVar4);
    if (*(int *)(iVar3 + 8) == 0) {
      uVar2 = 0;
    }
    else {
      uVar2 = (**(code **)*puVar4)(puVar4,*(int *)(iVar3 + 8),4);
    }
    uVar6 = (*(code *)param_2)(uVar2,local_38,local_34,iVar7,iVar5,uVar6);
  }
  return uVar6;
}



/* 402c675c FUN_402c675c */

/* Boundary evidence: original MIPS .pdata 402c675c..402c6767. Semantic name remains unreviewed. */

undefined4 FUN_402c675c(void)

{
  return 1;
}



/* 402c6768 FUN_402c6768 */

/* Boundary evidence: original MIPS .pdata 402c6768..402c6883. Semantic name remains unreviewed. */

undefined4 FUN_402c6768(int param_1,undefined *param_2)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  
  iVar2 = *(int *)(param_1 + 4);
  if ((iVar2 == 0) || (*(uint *)(param_1 + 8) < 0x1c)) {
    SetLastError(0x57);
    uVar3 = 0;
  }
  else {
    uVar3 = *(undefined4 *)(iVar2 + 0x18);
    uVar4 = *(undefined4 *)(iVar2 + 0x14);
    uVar5 = *(undefined4 *)(iVar2 + 0x10);
    uVar6 = *(undefined4 *)(iVar2 + 0xc);
    if (*(int *)(iVar2 + 8) == 0) {
      uVar1 = 0;
    }
    else {
      uVar1 = (*(code *)**(undefined4 **)(param_1 + 0xc))
                        ((undefined4 *)(param_1 + 0xc),*(int *)(iVar2 + 8),4);
    }
    uVar3 = (*(code *)param_2)(uVar1,uVar6,uVar5,uVar4,uVar3);
  }
  return uVar3;
}



/* 402c6884 FUN_402c6884 */

/* Boundary evidence: original MIPS .pdata 402c6884..402c688f. Semantic name remains unreviewed. */

undefined4 FUN_402c6884(void)

{
  return 1;
}



/* 402c6890 FUN_402c6890 */

/* Boundary evidence: original MIPS .pdata 402c6890..402c6a3b. Semantic name remains unreviewed. */

undefined4 FUN_402c6890(int param_1,undefined *param_2)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  int local_30;
  undefined4 local_2c;
  
  iVar2 = *(int *)(param_1 + 4);
  if ((iVar2 == 0) || (*(uint *)(param_1 + 8) < 0x24)) {
    SetLastError(0x57);
    uVar4 = 0;
  }
  else {
    puVar3 = (undefined4 *)(param_1 + 0xc);
    if (*(int *)(iVar2 + 0x20) == 0) {
      uVar4 = 0;
    }
    else {
      uVar4 = (**(code **)*puVar3)(puVar3,*(int *)(iVar2 + 0x20),4);
    }
    uVar6 = *(undefined4 *)(iVar2 + 0x1c);
    if (*(int *)(iVar2 + 0x18) == 0) {
      uVar5 = 0;
    }
    else {
      uVar5 = (**(code **)*puVar3)(puVar3,*(int *)(iVar2 + 0x18),4);
    }
    FUN_402c2c18((undefined4 *)(iVar2 + 0x10),&local_30,puVar3);
    uVar7 = *(undefined4 *)(iVar2 + 0xc);
    if (*(int *)(iVar2 + 8) == 0) {
      uVar1 = 0;
    }
    else {
      uVar1 = (**(code **)*puVar3)(puVar3,*(int *)(iVar2 + 8),4);
    }
    uVar4 = (*(code *)param_2)(uVar1,uVar7,local_30,local_2c,uVar5,uVar6,uVar4);
  }
  return uVar4;
}



/* 402c6a3c FUN_402c6a3c */

/* Boundary evidence: original MIPS .pdata 402c6a3c..402c6a47. Semantic name remains unreviewed. */

undefined4 FUN_402c6a3c(void)

{
  return 1;
}



/* 402c6a48 FUN_402c6a48 */

/* Boundary evidence: original MIPS .pdata 402c6a48..402c6b97. Semantic name remains unreviewed. */

undefined4 FUN_402c6a48(int param_1,undefined *param_2)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  
  iVar2 = *(int *)(param_1 + 4);
  if ((iVar2 == 0) || (*(uint *)(param_1 + 8) < 0x18)) {
    SetLastError(0x57);
    uVar3 = 0;
  }
  else {
    puVar4 = (undefined4 *)(param_1 + 0xc);
    if (*(int *)(iVar2 + 0x14) == 0) {
      uVar3 = 0;
    }
    else {
      uVar3 = (**(code **)*puVar4)(puVar4,*(int *)(iVar2 + 0x14),4);
    }
    uVar5 = *(undefined4 *)(iVar2 + 0x10);
    uVar6 = *(undefined4 *)(iVar2 + 0xc);
    if (*(int *)(iVar2 + 8) == 0) {
      uVar1 = 0;
    }
    else {
      uVar1 = (**(code **)*puVar4)(puVar4,*(int *)(iVar2 + 8),4);
    }
    uVar3 = (*(code *)param_2)(uVar1,uVar6,uVar5,uVar3);
  }
  return uVar3;
}



/* 402c6b98 FUN_402c6b98 */

/* Boundary evidence: original MIPS .pdata 402c6b98..402c6ba3. Semantic name remains unreviewed. */

undefined4 FUN_402c6b98(void)

{
  return 1;
}



/* 402c6ba4 FUN_402c6ba4 */

/* Boundary evidence: original MIPS .pdata 402c6ba4..402c6cf3. Semantic name remains unreviewed. */

undefined4 FUN_402c6ba4(int param_1,undefined *param_2)

{
  undefined2 uVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  undefined4 uVar6;
  
  iVar3 = *(int *)(param_1 + 4);
  if ((iVar3 == 0) || (*(uint *)(param_1 + 8) < 0x18)) {
    SetLastError(0x57);
    uVar4 = 0;
  }
  else {
    puVar5 = (undefined4 *)(param_1 + 0xc);
    if (*(int *)(iVar3 + 0x14) == 0) {
      uVar4 = 0;
    }
    else {
      uVar4 = (**(code **)*puVar5)(puVar5,*(int *)(iVar3 + 0x14),2);
    }
    uVar1 = *(undefined2 *)(iVar3 + 0x10);
    uVar6 = *(undefined4 *)(iVar3 + 0xc);
    if (*(int *)(iVar3 + 8) == 0) {
      uVar2 = 0;
    }
    else {
      uVar2 = (**(code **)*puVar5)(puVar5,*(int *)(iVar3 + 8),4);
    }
    uVar4 = (*(code *)param_2)(uVar2,uVar6,uVar1,uVar4);
  }
  return uVar4;
}



/* 402c6cf4 FUN_402c6cf4 */

/* Boundary evidence: original MIPS .pdata 402c6cf4..402c6cff. Semantic name remains unreviewed. */

undefined4 FUN_402c6cf4(void)

{
  return 1;
}



/* 402c6d00 FUN_402c6d00 */

/* Boundary evidence: original MIPS .pdata 402c6d00..402c6f33. Semantic name remains unreviewed. */

undefined4 FUN_402c6d00(int param_1,undefined *param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  undefined4 *puVar7;
  int iVar8;
  int iVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  undefined4 uVar13;
  int aiStack_38 [2];
  int aiStack_30 [2];
  
  iVar6 = *(int *)(param_1 + 4);
  if ((iVar6 == 0) || (*(uint *)(param_1 + 8) < 0x30)) {
    uVar12 = 0x57;
  }
  else {
    puVar7 = (undefined4 *)(param_1 + 0xc);
    if (*(int *)(iVar6 + 0x2c) == 0) {
      uVar12 = 0;
    }
    else {
      uVar12 = (**(code **)*puVar7)(puVar7,*(int *)(iVar6 + 0x2c),4);
    }
    piVar1 = FUN_402c2b64((undefined4 *)(iVar6 + 0x24),aiStack_38,puVar7);
    iVar8 = piVar1[1];
    iVar3 = *piVar1;
    if (iVar3 == 0) {
      iVar8 = 0;
    }
    if (*(int *)(iVar6 + 0x20) == 0) {
      uVar11 = 0;
    }
    else {
      uVar11 = (**(code **)*puVar7)(puVar7,*(int *)(iVar6 + 0x20),4);
    }
    piVar1 = FUN_402c2b64((undefined4 *)(iVar6 + 0x18),aiStack_30,puVar7);
    iVar9 = piVar1[1];
    iVar4 = *piVar1;
    if (iVar4 == 0) {
      iVar9 = 0;
    }
    uVar13 = *(undefined4 *)(iVar6 + 0x14);
    uVar5 = *(undefined4 *)(iVar6 + 0x10);
    if (*(int *)(iVar6 + 0xc) == 0) {
      uVar10 = 0;
    }
    else {
      uVar10 = (**(code **)*puVar7)(puVar7,*(int *)(iVar6 + 0xc),4);
    }
    if (*(int *)(iVar6 + 8) == 0) {
      uVar2 = 0;
    }
    else {
      uVar2 = (**(code **)*puVar7)(puVar7,*(int *)(iVar6 + 8),4);
    }
    uVar12 = (*(code *)param_2)(uVar2,uVar10,uVar5,uVar13,iVar4,iVar9,uVar11,iVar3,iVar8,uVar12);
  }
  return uVar12;
}



/* 402c6f34 FUN_402c6f34 */

/* Boundary evidence: original MIPS .pdata 402c6f34..402c6f3f. Semantic name remains unreviewed. */

undefined4 FUN_402c6f34(void)

{
  return 1;
}



/* 402c6f40 FUN_402c6f40 */

/* Boundary evidence: original MIPS .pdata 402c6f40..402c704b. Semantic name remains unreviewed. */

undefined4 FUN_402c6f40(int *param_1,undefined4 *param_2)

{
  short *psVar1;
  int iVar2;
  undefined4 uVar3;
  undefined2 *local_50;
  undefined2 local_4c [16];
  undefined2 local_2c;
  int local_28;
  int local_24;
  uint local_20;
  
  local_20 = DAT_402ca140;
  if (*param_1 == 0) {
    FUN_402c8b84(DAT_402ca140);
    uVar3 = 0;
  }
  else {
    psVar1 = (short *)(**(code **)*param_2)(param_2,*param_1,1);
    local_50 = local_4c;
    local_24 = 0x10;
    local_2c = 0;
    local_28 = 0;
    local_4c[0] = 0;
    FUN_402c352c((int *)&local_50,psVar1);
    if (local_28 + 1U < 0x80000000) {
      iVar2 = (local_28 + 1U) * 2;
    }
    else {
      iVar2 = -1;
    }
    uVar3 = (**(code **)*param_2)(param_2,*param_1,iVar2);
    if (local_24 != 0x10) {
      operator_delete(local_50);
    }
    FUN_402c8b84(local_20);
  }
  return uVar3;
}



/* 402c704c FUN_402c704c */

/* Boundary evidence: original MIPS .pdata 402c704c..402c70ff. Semantic name remains unreviewed. */

undefined4 FUN_402c704c(int *param_1,undefined4 *param_2)

{
  char *pcVar1;
  undefined4 uVar2;
  void *local_38 [6];
  int local_20;
  int local_1c;
  uint local_18;
  
  local_18 = DAT_402ca140;
  if (*param_1 == 0) {
    FUN_402c8b84(DAT_402ca140);
    uVar2 = 0;
  }
  else {
    pcVar1 = (char *)(**(code **)*param_2)(param_2,*param_1,1);
    FUN_402c3740((int *)local_38,pcVar1);
    uVar2 = (**(code **)*param_2)(param_2,*param_1,local_20 + 1);
    if (local_1c != 0x10) {
      operator_delete(local_38[0]);
    }
    FUN_402c8b84(local_18);
  }
  return uVar2;
}



/* 402c7100 FUN_402c7100 */

/* Boundary evidence: original MIPS .pdata 402c7100..402c7157. Semantic name remains unreviewed. */

void * FUN_402c7100(void *param_1,uint param_2)

{
  void *pvVar1;
  undefined4 auStack_18 [2];
  
  pvVar1 = *(void **)((int)param_1 + 4);
  FUN_402c33d8((int)((int)param_1 + 4),auStack_18,*(void **)((int)pvVar1 + 4),pvVar1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}



/* 402c7158 FUN_402c7158 */

/* Boundary evidence: original MIPS .pdata 402c7158..402c71d7. Semantic name remains unreviewed. */

undefined4 * FUN_402c7158(undefined4 *param_1,undefined4 *param_2,int param_3,undefined4 *param_4)

{
  undefined4 *puVar1;
  
  puVar1 = FUN_402c1710((int)param_1,param_3);
  if (puVar1 == (undefined4 *)0x0) {
    *param_2 = *param_1;
  }
  else {
    *puVar1 = *param_4;
    FUN_402c36ec(puVar1 + 1,param_4 + 1);
    *param_2 = puVar1;
  }
  return param_2;
}



/* 402c71d8 FUN_402c71d8 */

/* Boundary evidence: original MIPS .pdata 402c71d8..402c72fb. Semantic name remains unreviewed. */

uint * FUN_402c71d8(int *param_1,uint *param_2)

{
  int *piVar1;
  uint *puVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 *****local_38;
  undefined4 *****local_34;
  undefined4 *****local_30;
  undefined4 local_2c;
  uint local_28;
  void *local_24 [5];
  
  local_28 = *param_2;
  piVar5 = (int *)((param_1[7] & local_28) * 8 + param_1[4]);
  iVar3 = piVar5[1];
  puVar2 = (uint *)*piVar5;
  while( true ) {
    if (iVar3 == 0) {
      local_38 = &local_38;
      local_34 = &local_38;
      local_30 = &local_38;
      local_2c = 0;
      FUN_402c36ec((int *)local_24,&local_38);
      iVar4 = *param_1;
      piVar1 = FUN_402c7158(param_1,&uStack_40,*piVar5,&local_28);
      iVar3 = *piVar1;
      FUN_402c33d8((int)local_24,&uStack_3c,*(void **)((int)local_24[0] + 4),local_24[0]);
      FUN_402c33d8((int)&local_38,&uStack_3c,local_38[1],local_38);
      if (iVar4 == iVar3) {
        puVar2 = (uint *)0x0;
      }
      else {
        piVar5[1] = piVar5[1] + 1;
        puVar2 = (uint *)(*(int *)(*piVar5 + 0x18) + 4);
        *piVar5 = *(int *)(*piVar5 + 0x18);
      }
      return puVar2;
    }
    iVar3 = iVar3 + -1;
    if (*puVar2 == local_28) break;
    puVar2 = (uint *)puVar2[5];
  }
  return puVar2 + 1;
}



/* 402c72fc FUN_402c72fc */

/* Boundary evidence: original MIPS .pdata 402c72fc..402c737f. Semantic name remains unreviewed. */

undefined4 * FUN_402c72fc(int param_1,undefined4 *param_2,void *param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = *(undefined4 *)((int)param_3 + 0x14);
  *(undefined4 *)(*(int *)((int)param_3 + 0x18) + 0x14) = uVar2;
  *(undefined4 *)(*(int *)((int)param_3 + 0x14) + 0x18) = *(undefined4 *)((int)param_3 + 0x18);
  FUN_402c7100(param_3,0);
  operator_delete(param_3);
  iVar1 = *(int *)(param_1 + 0xc);
  *param_2 = uVar2;
  *(int *)(param_1 + 0xc) = iVar1 + -1;
  return param_2;
}



/* 402c7380 FUN_402c7380 */

/* Boundary evidence: original MIPS .pdata 402c7380..402c740b. Semantic name remains unreviewed. */

undefined4 * FUN_402c7380(int param_1,undefined4 *param_2,void *param_3,void *param_4)

{
  void *pvVar1;
  undefined4 auStack_20 [2];
  
  while (param_3 != param_4) {
    pvVar1 = *(void **)((int)param_3 + 0x14);
    FUN_402c72fc(param_1,auStack_20,param_3);
    param_3 = pvVar1;
  }
  *param_2 = param_3;
  return param_2;
}



/* 402c740c FUN_402c740c */

/* Boundary evidence: original MIPS .pdata 402c740c..402c746b. Semantic name remains unreviewed. */

uint * FUN_402c740c(int *param_1)

{
  uint *puVar1;
  LPCRITICAL_SECTION lpCriticalSection;
  uint local_18 [2];
  
  lpCriticalSection = (LPCRITICAL_SECTION)(param_1 + 8);
  EnterCriticalSection(lpCriticalSection);
  local_18[0] = __GetUserKData(8);
  puVar1 = FUN_402c71d8(param_1,local_18);
  if (lpCriticalSection != (LPCRITICAL_SECTION)0x0) {
    LeaveCriticalSection(lpCriticalSection);
  }
  return puVar1;
}



/* 402c746c FUN_402c746c */

/* Boundary evidence: original MIPS .pdata 402c746c..402c74f3. Semantic name remains unreviewed. */

undefined4 * FUN_402c746c(uint *param_1,undefined4 *param_2,uint *param_3)

{
  uint *puVar1;
  
  puVar1 = (uint *)((param_1[7] & *param_3) * 8 + param_1[4]);
  puVar1[1] = puVar1[1] - 1;
  if ((uint *)*puVar1 == param_3) {
    if (puVar1[1] == 0) {
      *puVar1 = *param_1;
    }
    else {
      *puVar1 = ((uint *)*puVar1)[5];
    }
  }
  FUN_402c72fc((int)param_1,param_2,param_3);
  return param_2;
}



/* 402c74f4 FUN_402c74f4 */

/* Boundary evidence: original MIPS .pdata 402c74f4..402c76f7. Semantic name remains unreviewed. */

undefined4 FUN_402c74f4(int param_1,undefined *param_2)

{
  int *piVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  int iVar6;
  undefined4 *puVar7;
  int iVar8;
  int iVar9;
  undefined4 uVar10;
  int iVar11;
  int iVar12;
  int aiStack_38 [2];
  int aiStack_30 [2];
  
  iVar6 = *(int *)(param_1 + 4);
  if ((iVar6 == 0) || (*(uint *)(param_1 + 8) < 0x2c)) {
    SetLastError(0x57);
    uVar5 = 0;
  }
  else {
    uVar5 = *(undefined4 *)(iVar6 + 0x28);
    puVar7 = (undefined4 *)(param_1 + 0xc);
    if (*(int *)(iVar6 + 0x24) == 0) {
      uVar10 = 0;
    }
    else {
      uVar10 = (**(code **)*puVar7)(puVar7,*(int *)(iVar6 + 0x24),4);
    }
    piVar1 = FUN_402c2b64((undefined4 *)(iVar6 + 0x1c),aiStack_38,puVar7);
    iVar8 = piVar1[1];
    iVar11 = *piVar1;
    if (iVar11 == 0) {
      iVar8 = 0;
    }
    piVar1 = FUN_402c2b64((undefined4 *)(iVar6 + 0x14),aiStack_30,puVar7);
    iVar9 = piVar1[1];
    iVar12 = *piVar1;
    if (iVar12 == 0) {
      iVar9 = 0;
    }
    uVar2 = FUN_402c704c((int *)(iVar6 + 0x10),puVar7);
    uVar3 = FUN_402c704c((int *)(iVar6 + 0xc),puVar7);
    if (*(int *)(iVar6 + 8) == 0) {
      uVar4 = 0;
    }
    else {
      uVar4 = (**(code **)*puVar7)(puVar7,*(int *)(iVar6 + 8),4);
    }
    uVar5 = (*(code *)param_2)(uVar4,uVar3,uVar2,iVar12,iVar9,iVar11,iVar8,uVar10,uVar5);
  }
  return uVar5;
}



/* 402c76f8 FUN_402c76f8 */

/* Boundary evidence: original MIPS .pdata 402c76f8..402c7703. Semantic name remains unreviewed. */

undefined4 FUN_402c76f8(void)

{
  return 1;
}



/* 402c7704 FUN_402c7704 */

/* Boundary evidence: original MIPS .pdata 402c7704..402c785b. Semantic name remains unreviewed. */

undefined4 FUN_402c7704(int param_1,undefined *param_2)

{
  int *piVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  undefined4 *puVar6;
  int iVar7;
  int local_30 [2];
  int local_28;
  int local_24;
  
  iVar4 = *(int *)(param_1 + 4);
  if ((iVar4 == 0) || (*(uint *)(param_1 + 8) < 0x18)) {
    SetLastError(0x57);
    uVar2 = 0;
  }
  else {
    puVar6 = (undefined4 *)(param_1 + 0xc);
    piVar1 = FUN_402c2b64((undefined4 *)(iVar4 + 0x10),local_30,puVar6);
    iVar5 = piVar1[1];
    iVar7 = *piVar1;
    if (iVar7 == 0) {
      iVar5 = 0;
    }
    local_28 = iVar7;
    local_24 = iVar5;
    uVar2 = FUN_402c704c((int *)(iVar4 + 0xc),puVar6);
    if (*(int *)(iVar4 + 8) == 0) {
      uVar3 = 0;
    }
    else {
      uVar3 = (**(code **)*puVar6)(puVar6,*(int *)(iVar4 + 8),4);
    }
    uVar2 = (*(code *)param_2)(uVar3,uVar2,iVar7,iVar5);
  }
  return uVar2;
}



/* 402c785c FUN_402c785c */

/* Boundary evidence: original MIPS .pdata 402c785c..402c7867. Semantic name remains unreviewed. */

undefined4 FUN_402c785c(void)

{
  return 1;
}



/* 402c7868 FUN_402c7868 */

/* Boundary evidence: original MIPS .pdata 402c7868..402c7a53. Semantic name remains unreviewed. */

undefined4 FUN_402c7868(int param_1,undefined *param_2)

{
  int *piVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  undefined4 *puVar6;
  int iVar7;
  undefined4 uVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int aiStack_38 [2];
  int aiStack_30 [2];
  
  iVar5 = *(int *)(param_1 + 4);
  if ((iVar5 == 0) || (*(uint *)(param_1 + 8) < 0x28)) {
    SetLastError(0x57);
    uVar8 = 0;
  }
  else {
    puVar6 = (undefined4 *)(param_1 + 0xc);
    if (*(int *)(iVar5 + 0x24) == 0) {
      uVar8 = 0;
    }
    else {
      uVar8 = (**(code **)*puVar6)(puVar6,*(int *)(iVar5 + 0x24),4);
    }
    piVar1 = FUN_402c2b64((undefined4 *)(iVar5 + 0x1c),aiStack_38,puVar6);
    iVar7 = piVar1[1];
    iVar10 = *piVar1;
    if (iVar10 == 0) {
      iVar7 = 0;
    }
    iVar12 = iVar7;
    piVar1 = FUN_402c2b64((undefined4 *)(iVar5 + 0x14),aiStack_30,puVar6);
    iVar9 = piVar1[1];
    iVar11 = *piVar1;
    if (iVar11 == 0) {
      iVar9 = 0;
    }
    uVar4 = *(undefined4 *)(iVar5 + 0x10);
    uVar2 = FUN_402c6f40((int *)(iVar5 + 0xc),puVar6);
    if (*(int *)(iVar5 + 8) == 0) {
      uVar3 = 0;
    }
    else {
      uVar3 = (**(code **)*puVar6)(puVar6,*(int *)(iVar5 + 8),4);
    }
    uVar8 = (*(code *)param_2)(uVar3,uVar2,uVar4,iVar11,iVar9,iVar10,iVar7,uVar8,uVar2,iVar12);
  }
  return uVar8;
}



/* 402c7a54 FUN_402c7a54 */

/* Boundary evidence: original MIPS .pdata 402c7a54..402c7a5f. Semantic name remains unreviewed. */

undefined4 FUN_402c7a54(void)

{
  return 1;
}



/* 402c7a60 FUN_402c7a60 */

/* Boundary evidence: original MIPS .pdata 402c7a60..402c7ae3. Semantic name remains unreviewed. */

bool FUN_402c7a60(uint *param_1,uint *param_2)

{
  uint *puVar1;
  uint *local_18 [2];
  
  FUN_402c3670((int *)param_1,(int *)local_18,param_2);
  puVar1 = (uint *)*param_1;
  if (puVar1 != local_18[0]) {
    FUN_402c746c(param_1,local_18,local_18[0]);
  }
  return puVar1 != local_18[0];
}



/* 402c7ae4 FUN_402c7ae4 */

/* Boundary evidence: original MIPS .pdata 402c7ae4..402c7b4f. Semantic name remains unreviewed. */

int * FUN_402c7ae4(int *param_1,uint param_2)

{
  int local_10 [2];
  
  *param_1 = (int)(param_1 + -4);
  param_1[3] = 0;
  param_1[1] = (int)(param_1 + -4);
  *(undefined4 *)(*param_1 + 0x18) = *(undefined4 *)(*param_1 + 0x14);
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[6] = 0;
  local_10[0] = *param_1;
  param_1[7] = param_2 - 1;
  local_10[1] = 0;
  FUN_402c34bc((uint *)(param_1 + 4),param_2,local_10);
  return param_1;
}



/* 402c7b50 FUN_402c7b50 */

/* Boundary evidence: original MIPS .pdata 402c7b50..402c7bab. Semantic name remains unreviewed. */

void FUN_402c7b50(uint *param_1)

{
  LPCRITICAL_SECTION lpCriticalSection;
  uint local_18 [2];
  
  lpCriticalSection = (LPCRITICAL_SECTION)(param_1 + 8);
  EnterCriticalSection(lpCriticalSection);
  local_18[0] = __GetUserKData(8);
  FUN_402c7a60(param_1,local_18);
  if (lpCriticalSection != (LPCRITICAL_SECTION)0x0) {
    LeaveCriticalSection(lpCriticalSection);
  }
  return;
}



/* 402c7bac FUN_402c7bac */

/* Boundary evidence: original MIPS .pdata 402c7bac..402c7c03. Semantic name remains unreviewed. */

void FUN_402c7bac(undefined4 *param_1)

{
  undefined4 *puVar1;
  undefined4 auStack_18 [2];
  
  puVar1 = param_1 + 4;
  FUN_402c32c0((int)puVar1,(undefined4 *)*puVar1,param_1[5]);
  operator_delete((void *)*puVar1);
  FUN_402c7380((int)param_1,auStack_18,*(void **)((int)*param_1 + 0x14),(void *)*param_1);
  return;
}



/* 402c7c04 FUN_402c7c04 */

/* Boundary evidence: original MIPS .pdata 402c7c04..402c7c97. Semantic name remains unreviewed. */

void FUN_402c7c04(void)

{
  LPCRITICAL_SECTION lpCriticalSection;
  
  lpCriticalSection = (LPCRITICAL_SECTION)FUN_402c2988();
  EnterCriticalSection(lpCriticalSection);
  if (DAT_402ca1b4 == (undefined *)0x0) {
    FUN_402c7ae4((int *)&DAT_402ca150,0x20);
    InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_402ca170);
    DAT_402ca1b4 = &DAT_402ca150;
  }
  if (lpCriticalSection != (LPCRITICAL_SECTION)0x0) {
    LeaveCriticalSection(lpCriticalSection);
  }
  return;
}



/* 402c7c98 FUN_402c7c98 */

/* Boundary evidence: original MIPS .pdata 402c7c98..402c7d27. Semantic name remains unreviewed. */

void FUN_402c7c98(void)

{
  undefined4 *puVar1;
  LONG LVar2;
  LPCRITICAL_SECTION lpCriticalSection;
  
  LVar2 = InterlockedDecrement((LONG *)&DAT_402ca1b8);
  if (LVar2 == 0) {
    lpCriticalSection = (LPCRITICAL_SECTION)FUN_402c2988();
    EnterCriticalSection(lpCriticalSection);
    puVar1 = DAT_402ca1b4;
    if (DAT_402ca1b4 != (undefined4 *)0x0) {
      DeleteCriticalSection((LPCRITICAL_SECTION)(DAT_402ca1b4 + 8));
      FUN_402c7bac(puVar1);
      DAT_402ca1b4 = (undefined4 *)0x0;
    }
    if (lpCriticalSection != (LPCRITICAL_SECTION)0x0) {
      LeaveCriticalSection(lpCriticalSection);
    }
  }
  return;
}



/* 402c7d28 FUN_402c7d28 */

/* Boundary evidence: original MIPS .pdata 402c7d28..402c7def. Semantic name remains unreviewed. */

void FUN_402c7d28(undefined4 *param_1)

{
  uint *puVar1;
  undefined4 auStack_20 [2];
  
  *param_1 = &PTR_FUN_402c1050;
  FUN_402c7c04();
  puVar1 = FUN_402c740c((int *)DAT_402ca1b4);
  if (puVar1 != (uint *)0x0) {
    if (puVar1[3] != 0) {
      FUN_402c3254((int)puVar1,auStack_20,*(void **)(*puVar1 + 4));
    }
    if (puVar1[3] == 0) {
      FUN_402c7c04();
      FUN_402c7b50(DAT_402ca1b4);
    }
  }
  FUN_402c361c(param_1 + 3);
  return;
}



/* 402c7df0 FUN_402c7df0 */

/* Boundary evidence: original MIPS .pdata 402c7df0..402c7e3b. Semantic name remains unreviewed. */

undefined4 * FUN_402c7df0(undefined4 *param_1,uint param_2)

{
  FUN_402c7d28(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}



/* 402c7e3c FUN_402c7e3c */

/* Boundary evidence: original MIPS .pdata 402c7e3c..402c7f23. Semantic name remains unreviewed. */

undefined4 * FUN_402c7e3c(undefined4 *param_1,undefined4 param_2,uint param_3)

{
  bool bVar1;
  uint *puVar2;
  undefined3 extraout_var;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *local_18 [2];
  
  puVar4 = param_1 + 3;
  *param_1 = &PTR_FUN_402c1050;
  param_1[1] = 0;
  param_1[2] = 0;
  FUN_402c357c(puVar4,param_2,param_3);
  if ((DAT_402ca1bc & 1) == 0) {
    DAT_402ca1bc = DAT_402ca1bc | 1;
    InterlockedIncrement((LONG *)&DAT_402ca1b8);
    FUN_402c7c04();
    FUN_402c8a60(FUN_402c8f38);
  }
  FUN_402c7c04();
  puVar2 = FUN_402c740c(DAT_402ca1b4);
  if (puVar2 != (uint *)0x0) {
    local_18[0] = param_1;
    bVar1 = FUN_402c3464((int *)puVar2,local_18);
    if ((CONCAT31(extraout_var,bVar1) != 0) &&
       (iVar3 = (**(code **)*puVar4)(puVar4,0,4), iVar3 != 0)) {
      param_1[1] = iVar3;
      param_1[2] = param_1[4];
    }
  }
  return param_1;
}



/* 402c7f24 FUN_402c7f24 */

/* Boundary evidence: original MIPS .pdata 402c7f24..402c7f6f. Semantic name remains unreviewed. */

undefined4 * FUN_402c7f24(undefined4 *param_1,uint param_2)

{
  FUN_402c7d28(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}



/* 402c7f70 WSS_IOControl */

/* Boundary evidence: original MIPS .pdata 402c7f70..402c8467. Semantic name remains unreviewed. */

undefined4
WSS_IOControl(undefined4 param_1,int param_2,undefined4 param_3,uint param_4,undefined4 *param_5,
             int param_6)

{
  code *pcVar1;
  undefined2 uVar2;
  undefined4 uVar3;
  undefined **local_30;
  undefined2 *local_2c;
  
                    /* 0x7f70  4  WSS_IOControl */
  uVar3 = 0x57;
  if (param_2 != 100) {
    if (param_2 != 0x65) {
      return 0x57;
    }
    if (param_5 == (undefined4 *)0x0) {
      return 0x57;
    }
    if (param_6 != 4) {
      return 0x57;
    }
    __GetUserKData(0xc);
    uVar3 = __GetUserKData(0xc);
    *param_5 = uVar3;
    return 1;
  }
  FUN_402c7e3c(&local_30,param_3,param_4);
  local_30 = &PTR_FUN_402c1054;
  if (local_2c == (undefined2 *)0x0) {
    uVar2 = 0xffff;
  }
  else {
    uVar2 = *local_2c;
  }
  switch(uVar2) {
  case 0:
    uVar3 = FUN_402c37bc((int)&local_30,FUN_402c19d4);
    break;
  case 1:
    uVar3 = FUN_402c38e8((int)&local_30,FUN_402c10d4);
    break;
  case 2:
    uVar3 = FUN_402c39d0((int)&local_30,FUN_402c1100);
    break;
  case 3:
    uVar3 = FUN_402c3ae8((int)&local_30,FUN_402c1a14);
    break;
  case 4:
    uVar3 = FUN_402c3c8c((int)&local_30,FUN_402c1a78);
    break;
  case 5:
    uVar3 = FUN_402c3e20((int)&local_30,FUN_402c1140);
    break;
  case 6:
    uVar3 = FUN_402c3f18((int)&local_30,FUN_402c1abc);
    break;
  case 7:
    uVar3 = FUN_402c47a8((int)&local_30,FUN_402c1b84);
    break;
  case 8:
    uVar3 = FUN_402c4938((int)&local_30,FUN_402c1170);
    break;
  case 9:
    pcVar1 = FUN_402c11b0;
    goto LAB_402c8214;
  case 10:
    pcVar1 = FUN_402c1bd4;
    goto LAB_402c822c;
  case 0xb:
    uVar3 = FUN_402c4ce4((int)&local_30,FUN_402c1c1c);
    break;
  case 0xc:
    uVar3 = FUN_402c4eb4((int)&local_30,FUN_402c1c74);
    break;
  case 0xd:
    pcVar1 = FUN_402c1d00;
LAB_402c822c:
    uVar3 = FUN_402c4b9c((int)&local_30,pcVar1);
    break;
  case 0xe:
    uVar3 = FUN_402c5050((int)&local_30,FUN_402c1d48);
    break;
  case 0xf:
    uVar3 = FUN_402c51cc((int)&local_30,FUN_402c1da0);
    break;
  case 0x10:
    pcVar1 = FUN_402c11e8;
LAB_402c8214:
    uVar3 = FUN_402c4a94((int)&local_30,pcVar1);
    break;
  case 0x12:
    uVar3 = FUN_402c74f4((int)&local_30,FUN_402c1df0);
    break;
  case 0x13:
    uVar3 = FUN_402c407c((int)&local_30,FUN_402c1fb4);
    break;
  case 0x14:
    uVar3 = FUN_402c7704((int)&local_30,FUN_402c2064);
    break;
  case 0x15:
    uVar3 = FUN_402c41fc((int)&local_30,FUN_402c20f8);
    break;
  case 0x16:
    uVar3 = FUN_402c444c((int)&local_30,FUN_402c1f54);
    break;
  case 0x17:
    pcVar1 = FUN_402c1afc;
    goto LAB_402c81c0;
  case 0x18:
    pcVar1 = FUN_402c1b40;
LAB_402c81c0:
    uVar3 = FUN_402c4614((int)&local_30,pcVar1);
    break;
  case 0x19:
    uVar3 = FUN_402c4324((int)&local_30,FUN_402c2134);
    break;
  case 0x1a:
    uVar3 = FUN_402c5528((int)&local_30,FUN_402c2210);
    break;
  case 0x1c:
    uVar3 = FUN_402c532c((int)&local_30,FUN_402c2170);
    break;
  case 0x1f:
    uVar3 = FUN_402c62d0((int)&local_30,FUN_402c278c);
    break;
  case 0x20:
    uVar3 = FUN_402c6454((int)&local_30,FUN_402c2804);
    break;
  case 0x21:
    uVar3 = FUN_402c65c8((int)&local_30,FUN_402c28cc);
    break;
  case 0x22:
    uVar3 = FUN_402c6768((int)&local_30,FUN_402c15c0);
    break;
  case 0x23:
    uVar3 = FUN_402c6890((int)&local_30,WSS_Close);
    break;
  case 0x24:
    uVar3 = FUN_402c6a48((int)&local_30,FUN_402c1690);
    break;
  case 0x25:
    uVar3 = FUN_402c6ba4((int)&local_30,FUN_402c16d0);
    break;
  case 0x26:
    uVar3 = FUN_402c56bc((int)&local_30,FUN_402c22bc);
    break;
  case 0x28:
    uVar3 = FUN_402c5938((int)&local_30,FUN_402c250c);
    break;
  case 0x29:
    uVar3 = FUN_402c5b80((int)&local_30,FUN_402c25a4);
    break;
  case 0x2b:
    uVar3 = FUN_402c5e4c((int)&local_30,FUN_402c264c);
    break;
  case 0x2c:
    uVar3 = FUN_402c6064((int)&local_30,FUN_402c26e4);
    break;
  case 0x2f:
    uVar3 = FUN_402c7868((int)&local_30,FUN_402c21c0);
    break;
  case 0x31:
    uVar3 = FUN_402c6d00((int)&local_30,FUN_402c290c);
  }
  FUN_402c7d28(&local_30);
  return uVar3;
}



/* 402c87a8 entry */

/* Boundary evidence: original MIPS .pdata 402c87a8..402c881b. Semantic name remains unreviewed. */

undefined4 entry(HMODULE param_1,int param_2)

{
  undefined4 uVar1;
  
  if (param_2 == 1) {
    FUN_402c8a90();
    FUN_402c8d64();
  }
  uVar1 = FUN_402c107c(param_1,param_2);
  if (param_2 == 0) {
    FUN_402c8cec();
  }
  return uVar1;
}



/* 402c881c FUN_402c881c */

/* Boundary evidence: original MIPS .pdata 402c881c..402c8927. Semantic name remains unreviewed. */

undefined4 FUN_402c881c(undefined4 param_1)

{
  void *_Memory;
  uint uVar1;
  void *pvVar2;
  uint _NewSize;
  undefined4 *puVar3;
  int iVar4;
  
  _Memory = DAT_402ca1cc;
  puVar3 = DAT_402ca1c8;
  iVar4 = (int)DAT_402ca1c8 - (int)DAT_402ca1cc;
  uVar1 = 0;
  if (iVar4 < 0) {
LAB_402c8860:
    param_1 = 0;
  }
  else {
    if (DAT_402ca1cc != (void *)0x0) {
      uVar1 = _msize(DAT_402ca1cc);
    }
    pvVar2 = _Memory;
    if (uVar1 < iVar4 + 4U) {
      if (_Memory == (void *)0x0) {
        pvVar2 = malloc(0x10);
LAB_402c88d4:
        if (pvVar2 == (void *)0x0) goto LAB_402c8860;
      }
      else {
        _NewSize = uVar1 << 1;
        if (0x200 < uVar1) {
          _NewSize = uVar1 + 0x200;
        }
        if ((_NewSize <= uVar1) || (pvVar2 = realloc(_Memory,_NewSize), pvVar2 == (void *)0x0)) {
          pvVar2 = realloc(_Memory,iVar4 + 4U);
          goto LAB_402c88d4;
        }
      }
      puVar3 = (undefined4 *)((iVar4 >> 2) * 4 + (int)pvVar2);
    }
    DAT_402ca1c8 = puVar3 + 1;
    *puVar3 = param_1;
    DAT_402ca1cc = pvVar2;
  }
  return param_1;
}



/* 402c8928 FUN_402c8928 */

/* Boundary evidence: original MIPS .pdata 402c8928..402c8a13. Semantic name remains unreviewed. */

undefined4 FUN_402c8928(undefined4 param_1)

{
  LPCRITICAL_SECTION lpCriticalSection;
  LONG LVar1;
  undefined4 uVar2;
  
  if (DAT_402ca1d0 == (LPCRITICAL_SECTION)0x0) {
    lpCriticalSection = malloc(0x14);
    if (lpCriticalSection != (LPCRITICAL_SECTION)0x0) {
      InitializeCriticalSection(lpCriticalSection);
      LVar1 = InterlockedCompareExchange((LONG *)&DAT_402ca1d0,(LONG)lpCriticalSection,0);
      if (LVar1 != 0) {
        DeleteCriticalSection(lpCriticalSection);
        free(lpCriticalSection);
      }
    }
    if (DAT_402ca1d0 == (LPCRITICAL_SECTION)0x0) goto LAB_402c89cc;
  }
  EnterCriticalSection(DAT_402ca1d0);
LAB_402c89cc:
  uVar2 = FUN_402c881c(param_1);
  FUN_402c8a14();
  return uVar2;
}



/* 402c8a14 FUN_402c8a14 */

/* Boundary evidence: original MIPS .pdata 402c8a14..402c8a5f. Semantic name remains unreviewed. */

void FUN_402c8a14(void)

{
  if (DAT_402ca1d0 != (LPCRITICAL_SECTION)0x0) {
    LeaveCriticalSection(DAT_402ca1d0);
  }
  return;
}



/* 402c8a60 FUN_402c8a60 */

/* Boundary evidence: original MIPS .pdata 402c8a60..402c8a8f. Semantic name remains unreviewed. */

undefined4 FUN_402c8a60(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_402c8928(param_1);
  if (iVar1 == 0) {
    uVar2 = 0xffffffff;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}



/* 402c8a90 FUN_402c8a90 */

/* Boundary evidence: original MIPS .pdata 402c8a90..402c8b03. Semantic name remains unreviewed. */

void FUN_402c8a90(void)

{
  uint uVar1;
  
  if ((DAT_402ca140 == 0) || (DAT_402ca140 == 0xb064)) {
    uVar1 = __security_gen_cookie2();
    DAT_402ca140 = uVar1 >> 0x10 ^ uVar1 & 0xffff;
    if (DAT_402ca140 == 0) {
      DAT_402ca140 = 0xb064;
    }
  }
  DAT_402ca144 = ~DAT_402ca140;
  return;
}



/* 402c8b04 FUN_402c8b04 */

/* Boundary evidence: original MIPS .pdata 402c8b04..402c8b57. Semantic name remains unreviewed. */

void FUN_402c8b04(int param_1,undefined4 param_2,uint *param_3)

{
  if ((*param_3 & 1) != 0) {
    param_1 = ((-param_3[2] & param_3[1] + param_1) - (param_3[1] + param_1)) + param_1;
  }
  FUN_402c8b84(*(uint *)(param_1 + (*param_3 & 0xfffffffc)));
  return;
}



/* 402c8b58 FUN_402c8b58 */

/* Boundary evidence: original MIPS .pdata 402c8b58..402c8b83. Semantic name remains unreviewed. */

undefined4 FUN_402c8b58(undefined4 param_1,int param_2,undefined4 param_3,int param_4)

{
  FUN_402c8b04(param_2,param_4,*(uint **)(*(int *)(param_4 + 4) + 0xc));
  return 1;
}



/* 402c8b84 FUN_402c8b84 */

/* Boundary evidence: original MIPS .pdata 402c8b84..402c8bcb. Semantic name remains unreviewed. */

void FUN_402c8b84(uint param_1)

{
  if ((param_1 == DAT_402ca140) && (param_1 >> 0x10 == 0)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __report_gsfailure();
}



/* 402c8bcc FUN_402c8bcc */

/* Boundary evidence: original MIPS .pdata 402c8bcc..402c8ceb. Semantic name remains unreviewed. */

void FUN_402c8bcc(UINT param_1,int param_2,int param_3)

{
  LPCRITICAL_SECTION lpCriticalSection;
  undefined4 *_Memory;
  
  DAT_402ca1c5 = (undefined1)param_3;
  if (param_2 == 0) {
    _Memory = DAT_402ca1cc;
    if (DAT_402ca1cc != (undefined4 *)0x0) {
      while (DAT_402ca1c8 = DAT_402ca1c8 + -1, _Memory <= DAT_402ca1c8) {
        if ((code *)*DAT_402ca1c8 != (code *)0x0) {
          (*(code *)*DAT_402ca1c8)();
          _Memory = DAT_402ca1cc;
        }
      }
      free(_Memory);
      DAT_402ca1c8 = (undefined4 *)0x0;
      DAT_402ca1cc = (undefined4 *)0x0;
    }
    FUN_402c8d10((undefined4 *)&DAT_402c1018,(undefined4 *)&DAT_402c101c);
  }
  FUN_402c8d10((undefined4 *)&DAT_402c1020,(undefined4 *)&DAT_402c1024);
  if (param_3 == 0) {
    TerminateProcess((HANDLE)0x42,param_1);
  }
  else {
    lpCriticalSection = (LPCRITICAL_SECTION)InterlockedExchange(&DAT_402ca1d0,0);
    if (lpCriticalSection != (LPCRITICAL_SECTION)0x0) {
      DeleteCriticalSection(lpCriticalSection);
      free(lpCriticalSection);
    }
  }
  return;
}



/* 402c8cec FUN_402c8cec */

/* Boundary evidence: original MIPS .pdata 402c8cec..402c8d0f. Semantic name remains unreviewed. */

void FUN_402c8cec(void)

{
  FUN_402c8bcc(0,0,1);
  return;
}



/* 402c8d10 FUN_402c8d10 */

/* Boundary evidence: original MIPS .pdata 402c8d10..402c8d63. Semantic name remains unreviewed. */

void FUN_402c8d10(undefined4 *param_1,undefined4 *param_2)

{
  for (; param_1 < param_2; param_1 = param_1 + 1) {
    if ((code *)*param_1 != (code *)0x0) {
      (*(code *)*param_1)();
    }
  }
  return;
}



/* 402c8d64 FUN_402c8d64 */

/* Boundary evidence: original MIPS .pdata 402c8d64..402c8d9f. Semantic name remains unreviewed. */

void FUN_402c8d64(void)

{
  FUN_402c8d10((undefined4 *)&DAT_402c1010,(undefined4 *)&DAT_402c1014);
  FUN_402c8d10((undefined4 *)&DAT_402c1000,(undefined4 *)&DAT_402c100c);
  return;
}



/* 402c8ec0 FUN_402c8ec0 */

/* Boundary evidence: original MIPS .pdata 402c8ec0..402c8edb. Semantic name remains unreviewed. */

void FUN_402c8ec0(void)

{
  FUN_402c29e8();
  return;
}



/* 402c8edc FUN_402c8edc */

/* Boundary evidence: original MIPS .pdata 402c8edc..402c8ef7. Semantic name remains unreviewed. */

void FUN_402c8edc(void)

{
  FUN_402c2988();
  return;
}



/* 402c8ef8 FUN_402c8ef8 */

/* Boundary evidence: original MIPS .pdata 402c8ef8..402c8f17. Semantic name remains unreviewed. */

void FUN_402c8ef8(void)

{
  DeleteCriticalSection((LPCRITICAL_SECTION)&DAT_402ca184);
  return;
}



/* 402c8f18 FUN_402c8f18 */

/* Boundary evidence: original MIPS .pdata 402c8f18..402c8f37. Semantic name remains unreviewed. */

void FUN_402c8f18(void)

{
  DeleteCriticalSection((LPCRITICAL_SECTION)&DAT_402ca19c);
  return;
}



/* 402c8f38 FUN_402c8f38 */

/* Boundary evidence: original MIPS .pdata 402c8f38..402c8f53. Semantic name remains unreviewed. */

void FUN_402c8f38(void)

{
  FUN_402c7c98();
  return;
}


