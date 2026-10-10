/* Automatic Ghidra pseudocode. Not original source; not runtime-verified. */

/* c04f10a4 FUN_c04f10a4 */

/* Boundary evidence: original MIPS .pdata c04f10a4..c04f111f. Semantic name remains unreviewed. */

undefined4 FUN_c04f10a4(int *param_1,int param_2,int *param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = (**(code **)(*param_1 + 8))(param_1,param_2);
  if (iVar1 == 0) {
    uVar2 = 0xe;
  }
  else {
    if (param_3 != (int *)0x0) {
      *param_3 = param_1[1];
    }
    param_1[1] = param_2 + param_1[1];
    uVar2 = 0;
  }
  return uVar2;
}



/* c04f1128 __WSAFDIsSet */

/* WARNING: Type propagation algorithm not settling */

int __WSAFDIsSet(SOCKET param_1,fd_set *param_2)

{
  uint uVar1;
  fd_set *pfVar2;
  
                    /* 0x1128  33  __WSAFDIsSet */
  uVar1 = param_2->fd_count & 0xffff;
  if (uVar1 != 0) {
    pfVar2 = (fd_set *)(param_2->fd_array + uVar1);
    do {
      pfVar2 = (fd_set *)((int)(pfVar2 + 0xffffffff) + 0x100);
      uVar1 = uVar1 - 1;
      if (*(SOCKET *)pfVar2 == param_1) {
        return 1;
      }
    } while (uVar1 != 0);
  }
  return 0;
}



/* c04f1170 htons */

u_short htons(u_short netshort)

{
  undefined2 in_register_00000012;
  
                    /* 0x1170  52  htons
                       0x1170  58  ntohs */
  return netshort << 8 | (ushort)(CONCAT22(in_register_00000012,netshort) >> 8);
}



/* c04f1188 htonl */

u_long htonl(u_long netlong)

{
                    /* 0x1188  51  htonl
                       0x1188  57  ntohl */
  return (netlong & 0xff00 | netlong << 0x10) << 8 | (netlong & 0xff0000 | netlong >> 0x10) >> 8;
}



/* c04f11b4 inet_addr */

/* Boundary evidence: original MIPS .pdata c04f11b4..c04f1477. Semantic name remains unreviewed. */

ulong inet_addr(char *cp)

{
  int iVar1;
  byte bVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint *puVar7;
  uint local_28 [4];
  
                    /* 0x11b4  53  inet_addr */
  uVar5 = 0xffffffff;
  uVar6 = uVar5;
  if (cp != (char *)0x0) {
    memset(local_28,0,0x10);
    uVar4 = 0;
    puVar7 = local_28;
    do {
      if (*cp == 0) break;
      if (*cp == 0x30) {
        cp = cp + 1;
        if ((*cp == 0x58) || (*cp == 0x78)) {
          uVar3 = 0x10;
          goto LAB_c04f12d0;
        }
        uVar3 = 8;
      }
      else {
        uVar3 = 10;
      }
      for (; bVar2 = *cp, bVar2 != 0; cp = cp + 1) {
        if ((bVar2 < 0x30) || (0x39 < bVar2)) {
          if ((bVar2 < 0x41) || (0x46 < bVar2)) {
            if ((bVar2 < 0x61) || (0x66 < bVar2)) break;
            bVar2 = bVar2 + 0xa9;
          }
          else {
            bVar2 = bVar2 - 0x37;
          }
        }
        else {
          bVar2 = bVar2 - 0x30;
        }
        if (uVar3 < bVar2) goto LAB_c04f1438;
        *puVar7 = *puVar7 * uVar3 + (uint)bVar2;
LAB_c04f12d0:
      }
      iVar1 = (int)*cp;
      if (iVar1 == 0x2e) {
        if (2 < uVar4) goto LAB_c04f1438;
        cp = cp + 1;
      }
      else if ((iVar1 != 0) && (iVar1 = _isctype(iVar1,8), iVar1 == 0)) goto LAB_c04f1438;
      if (*cp == 0) break;
      uVar4 = uVar4 + 1;
      puVar7 = puVar7 + 1;
    } while (uVar4 < 4);
    uVar6 = local_28[0];
    if (uVar4 != 0) {
      if (uVar4 == 1) {
        uVar6 = uVar5;
        if ((local_28[0] < 0x100) && (local_28[1] < 0x1000000)) {
          uVar6 = local_28[0] << 0x18 | local_28[1];
        }
      }
      else if (uVar4 == 2) {
        uVar6 = uVar5;
        if (((local_28[0] < 0x100) && (local_28[1] < 0x100)) && (local_28[2] < 0x10000)) {
          uVar6 = (local_28[0] << 8 | local_28[1]) << 0x10 | local_28[2];
        }
      }
      else {
        uVar6 = uVar5;
        if ((((local_28[0] < 0x100) && (local_28[1] < 0x100)) && (local_28[2] < 0x100)) &&
           (local_28[3] < 0x100)) {
          uVar6 = ((local_28[0] << 8 | local_28[1]) << 8 | local_28[2]) << 8 | local_28[3];
        }
      }
    }
  }
LAB_c04f1438:
  return uVar6 >> 8 & 0xff00 | (uVar6 & 0xff00) << 8 | uVar6 << 0x18 | uVar6 >> 0x18;
}



/* c04f1478 freeaddrinfo */

/* Boundary evidence: original MIPS .pdata c04f1478..c04f1493. Semantic name remains unreviewed. */

void freeaddrinfo(HLOCAL param_1)

{
                    /* 0x1478  38  freeaddrinfo */
  LocalFree(param_1);
  return;
}



/* c04f1494 FUN_c04f1494 */

/* Boundary evidence: original MIPS .pdata c04f1494..c04f14ef. Semantic name remains unreviewed. */

LPVOID FUN_c04f1494(void)

{
  LPVOID lpTlsValue;
  
  lpTlsValue = TlsGetValue(DAT_c04ff098);
  if (lpTlsValue == (LPVOID)0x0) {
    lpTlsValue = LocalAlloc(0x40,0x450);
    TlsSetValue(DAT_c04ff098,lpTlsValue);
  }
  return lpTlsValue;
}



/* c04f14f0 FUN_c04f14f0 */

void FUN_c04f14f0(int *param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = param_1[3];
  *param_1 = *param_1 + (int)param_1;
  param_1[1] = param_1[1] + (int)param_1;
  param_1[3] = iVar1 + (int)param_1;
  iVar2 = 0;
  if (*(int *)(iVar1 + (int)param_1) != 0) {
    iVar1 = 0;
    do {
      *(int *)(param_1[3] + iVar1) = (int)param_1 + *(int *)(param_1[3] + iVar1);
      iVar2 = iVar2 + 1;
      iVar1 = iVar2 * 4;
    } while (*(int *)(param_1[3] + iVar1) != 0);
  }
  return;
}



/* c04f155c getprotobynumber */

/* Boundary evidence: original MIPS .pdata c04f155c..c04f1583. Semantic name remains unreviewed. */

protoent * getprotobynumber(int proto)

{
                    /* 0x155c  46  getprotobynumber */
  SetLastError(0x2afb);
  return (protoent *)0x0;
}



/* c04f1584 getprotobyname */

/* Boundary evidence: original MIPS .pdata c04f1584..c04f15ab. Semantic name remains unreviewed. */

protoent * getprotobyname(char *name)

{
                    /* 0x1584  45  getprotobyname */
  SetLastError(0x2afb);
  return (protoent *)0x0;
}



/* c04f15ac getservbyport */

/* Boundary evidence: original MIPS .pdata c04f15ac..c04f15d3. Semantic name remains unreviewed. */

servent * getservbyport(int port,char *proto)

{
                    /* 0x15ac  48  getservbyport */
  SetLastError(0x2afb);
  return (servent *)0x0;
}



/* c04f15d4 getservbyname */

/* Boundary evidence: original MIPS .pdata c04f15d4..c04f15fb. Semantic name remains unreviewed. */

servent * getservbyname(char *name,char *proto)

{
                    /* 0x15d4  47  getservbyname */
  SetLastError(0x2afb);
  return (servent *)0x0;
}



/* c04f15fc inet_ntoa */

/* Boundary evidence: original MIPS .pdata c04f15fc..c04f16c7. Semantic name remains unreviewed. */

char * inet_ntoa(in_addr in)

{
  char cVar1;
  byte bVar2;
  char *pcVar3;
  char *pcVar4;
  char *pcVar5;
  int iVar6;
  char *pcVar7;
  uint uVar8;
  _union_1226 local_res0;
  
                    /* 0x15fc  54  inet_ntoa */
  local_res0 = in.S_un;
  pcVar3 = FUN_c04f1494();
  pcVar7 = (char *)0x0;
  if (pcVar3 != (char *)0x0) {
    iVar6 = 3;
    pcVar7 = pcVar3;
    do {
      do {
        pcVar5 = pcVar7;
        bVar2 = *(byte *)((int)&local_res0 + iVar6);
        uVar8 = bVar2 / 10;
        *pcVar5 = bVar2 % 10 + 0x30;
        *(byte *)((int)&local_res0 + iVar6) = (byte)uVar8;
        pcVar7 = pcVar5 + 1;
      } while (uVar8 != 0);
      pcVar5[1] = '.';
      iVar6 = iVar6 + -1;
      pcVar7 = pcVar5 + 2;
    } while (-1 < iVar6);
    pcVar5[1] = '\0';
    for (pcVar4 = pcVar3; pcVar7 = pcVar3, pcVar4 < pcVar5; pcVar4 = pcVar4 + 1) {
      cVar1 = *pcVar5;
      *pcVar5 = *pcVar4;
      *pcVar4 = cVar1;
      pcVar5 = pcVar5 + -1;
    }
  }
  return pcVar7;
}



/* c04f16c8 WSAAsyncSelect */

/* Boundary evidence: original MIPS .pdata c04f16c8..c04f16ef. Semantic name remains unreviewed. */

int WSAAsyncSelect(SOCKET s,HWND hWnd,u_int wMsg,long lEvent)

{
                    /* 0x16c8  3  WSAAsyncSelect */
  SetLastError(0x273d);
  return -1;
}



/* c04f16f0 WSACloseEvent */

/* Boundary evidence: original MIPS .pdata c04f16f0..c04f1713. Semantic name remains unreviewed. */

void WSACloseEvent(HANDLE param_1)

{
                    /* 0x16f0  5  WSACloseEvent */
  CloseHandle(param_1);
  return;
}



/* c04f1714 WSACreateEvent */

/* Boundary evidence: original MIPS .pdata c04f1714..c04f1743. Semantic name remains unreviewed. */

void WSACreateEvent(void)

{
                    /* 0x1714  8  WSACreateEvent */
  CreateEventW((LPSECURITY_ATTRIBUTES)0x0,1,0,(LPCWSTR)0x0);
  return;
}



/* c04f1744 WSAGetLastError */

/* Boundary evidence: original MIPS .pdata c04f1744..c04f1767. Semantic name remains unreviewed. */

int WSAGetLastError(void)

{
  DWORD DVar1;
  
                    /* 0x1744  13  WSAGetLastError */
  DVar1 = GetLastError();
  return DVar1;
}



/* c04f1768 WSAGetOverlappedResult */

/* Boundary evidence: original MIPS .pdata c04f1768..c04f178f. Semantic name remains unreviewed. */

undefined4 WSAGetOverlappedResult(void)

{
                    /* 0x1768  14  WSAGetOverlappedResult */
  SetLastError(0x273d);
  return 0;
}



/* c04f1790 WSAJoinLeaf */

/* Boundary evidence: original MIPS .pdata c04f1790..c04f17b7. Semantic name remains unreviewed. */

undefined4 WSAJoinLeaf(void)

{
                    /* 0x1790  18  WSAJoinLeaf */
  SetLastError(0x273d);
  return 0xffffffff;
}



/* c04f17b8 WSAResetEvent */

/* Boundary evidence: original MIPS .pdata c04f17b8..c04f17d3. Semantic name remains unreviewed. */

void WSAResetEvent(undefined4 param_1)

{
                    /* 0x17b8  23  WSAResetEvent */
  EventModify(param_1,2);
  return;
}



/* c04f17d4 WSASetEvent */

/* Boundary evidence: original MIPS .pdata c04f17d4..c04f17ef. Semantic name remains unreviewed. */

void WSASetEvent(undefined4 param_1)

{
                    /* 0x17d4  26  WSASetEvent */
  EventModify(param_1,3);
  return;
}



/* c04f17f0 WSASetLastError */

/* Boundary evidence: original MIPS .pdata c04f17f0..c04f1813. Semantic name remains unreviewed. */

void WSASetLastError(int iError)

{
                    /* 0x17f0  27  WSASetLastError */
  SetLastError(iError);
  return;
}



/* c04f1814 WSASetServiceW */

/* Boundary evidence: original MIPS .pdata c04f1814..c04f183b. Semantic name remains unreviewed. */

undefined4 WSASetServiceW(void)

{
                    /* 0x1814  28  WSASetServiceW */
  SetLastError(0x273d);
  return 0xffffffff;
}



/* c04f183c WSAWaitForMultipleEvents */

/* Boundary evidence: original MIPS .pdata c04f183c..c04f185f. Semantic name remains unreviewed. */

void WSAWaitForMultipleEvents(DWORD param_1,HANDLE *param_2,BOOL param_3,DWORD param_4)

{
                    /* 0x183c  32  WSAWaitForMultipleEvents */
  WaitForMultipleObjects(param_1,param_2,param_3,param_4);
  return;
}



/* c04f1860 FUN_c04f1860 */

/* Boundary evidence: original MIPS .pdata c04f1860..c04f18a7. Semantic name remains unreviewed. */

undefined4 FUN_c04f1860(HMODULE param_1,int param_2)

{
  if (param_2 == 1) {
    DisableThreadLibraryCalls(param_1);
    DAT_c04ff098 = TlsCall(0,0);
  }
  return 1;
}



/* c04f18a8 FUN_c04f18a8 */

/* Boundary evidence: original MIPS .pdata c04f18a8..c04f190f. Semantic name remains unreviewed. */

void FUN_c04f18a8(undefined4 *param_1)

{
  *param_1 = &PTR_FUN_c04f1050;
  if ((*(char *)(param_1 + 3) != '\0') && ((HANDLE)param_1[2] != (HANDLE)0xffffffff)) {
    CloseHandle((HANDLE)param_1[2]);
  }
  *param_1 = &PTR_LAB_c04f104c;
  return;
}



/* c04f1910 FUN_c04f1910 */

/* Boundary evidence: original MIPS .pdata c04f1910..c04f1a27. Semantic name remains unreviewed. */

DWORD FUN_c04f1910(int param_1,LPVOID param_2,DWORD param_3)

{
  HANDLE hObject;
  LONG LVar1;
  BOOL BVar2;
  DWORD DVar3;
  LONG *Destination;
  
  Destination = (LONG *)(param_1 + 8);
  if (*Destination == -1) {
    hObject = CreateFileW(*(LPCWSTR *)(param_1 + 0x10),0xc0000000,3,(LPSECURITY_ATTRIBUTES)0x0,3,0,
                          (HANDLE)0x0);
    if (hObject != (HANDLE)0xffffffff) {
      *(undefined1 *)(param_1 + 0xc) = 1;
      LVar1 = InterlockedCompareExchange(Destination,(LONG)hObject,-1);
      if (LVar1 != -1) {
        CloseHandle(hObject);
      }
    }
  }
  BVar2 = DeviceIoControl((HANDLE)*Destination,*(DWORD *)(param_1 + 0x14),param_2,param_3,
                          (LPVOID)0x0,0,(LPDWORD)0x0,(LPOVERLAPPED)0x0);
  if (BVar2 == 0) {
    DVar3 = GetLastError();
  }
  else {
    DVar3 = 0;
  }
  return DVar3;
}



/* c04f1a28 FUN_c04f1a28 */

/* Boundary evidence: original MIPS .pdata c04f1a28..c04f1afb. Semantic name remains unreviewed. */

undefined4 FUN_c04f1a28(undefined4 *param_1,uint param_2)

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



/* c04f1afc FUN_c04f1afc */

/* Boundary evidence: original MIPS .pdata c04f1afc..c04f1be3. Semantic name remains unreviewed. */

undefined4 FUN_c04f1afc(undefined4 *param_1,uint param_2)

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



/* c04f1bfc FUN_c04f1bfc */

/* Boundary evidence: original MIPS .pdata c04f1bfc..c04f1c5b. Semantic name remains unreviewed. */

undefined * FUN_c04f1bfc(void)

{
  if ((DAT_c04ff0d0 & 1) == 0) {
    DAT_c04ff0d0 = DAT_c04ff0d0 | 1;
    InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_c04ff0bc);
    FUN_c04fe268(FUN_c04fe714);
  }
  return &DAT_c04ff0bc;
}



/* c04f1c5c FUN_c04f1c5c */

/* Boundary evidence: original MIPS .pdata c04f1c5c..c04f1d0f. Semantic name remains unreviewed. */

int * FUN_c04f1c5c(undefined4 *param_1,int *param_2,undefined4 *param_3)

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



/* c04f1d10 FUN_c04f1d10 */

/* Boundary evidence: original MIPS .pdata c04f1d10..c04f1dc3. Semantic name remains unreviewed. */

int * FUN_c04f1d10(undefined4 *param_1,int *param_2,undefined4 *param_3)

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



/* c04f1dc4 FUN_c04f1dc4 */

/* Boundary evidence: original MIPS .pdata c04f1dc4..c04f1e87. Semantic name remains unreviewed. */

int * FUN_c04f1dc4(undefined4 *param_1,int *param_2,undefined4 *param_3)

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
      goto LAB_c04f1e60;
    }
  }
  iVar2 = 0;
LAB_c04f1e60:
  *param_2 = iVar1;
  if (iVar1 == 0) {
    iVar2 = 0;
  }
  param_2[1] = iVar2;
  return param_2;
}



/* c04f1e88 FUN_c04f1e88 */

/* Boundary evidence: original MIPS .pdata c04f1e88..c04f1eef. Semantic name remains unreviewed. */

undefined4 FUN_c04f1e88(undefined4 *param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  size_t _Size;
  uint uVar2;
  
  uVar2 = param_1[1];
  if (uVar2 == param_2[1]) {
    if (uVar2 < 0x40000000) {
      _Size = uVar2 << 2;
    }
    else {
      _Size = 0xffffffff;
    }
    memcpy((void *)*param_1,(void *)*param_2,_Size);
    uVar1 = 0;
  }
  else {
    uVar1 = 0x57;
  }
  return uVar1;
}



/* c04f1ef0 FUN_c04f1ef0 */

/* Boundary evidence: original MIPS .pdata c04f1ef0..c04f1fa3. Semantic name remains unreviewed. */

int * FUN_c04f1ef0(undefined4 *param_1,int *param_2,undefined4 *param_3)

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



/* c04f1fa4 FUN_c04f1fa4 */

/* Boundary evidence: original MIPS .pdata c04f1fa4..c04f2067. Semantic name remains unreviewed. */

int * FUN_c04f1fa4(undefined4 *param_1,int *param_2,undefined4 *param_3)

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
      goto LAB_c04f2040;
    }
  }
  iVar2 = 0;
LAB_c04f2040:
  *param_2 = iVar1;
  if (iVar1 == 0) {
    iVar2 = 0;
  }
  param_2[1] = iVar2;
  return param_2;
}



/* c04f2068 FUN_c04f2068 */

/* Boundary evidence: original MIPS .pdata c04f2068..c04f20cf. Semantic name remains unreviewed. */

undefined4 FUN_c04f2068(undefined4 *param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  size_t _Size;
  uint uVar2;
  
  uVar2 = param_1[1];
  if (uVar2 == param_2[1]) {
    if (uVar2 < 0x80000000) {
      _Size = uVar2 << 1;
    }
    else {
      _Size = 0xffffffff;
    }
    memcpy((void *)*param_1,(void *)*param_2,_Size);
    uVar1 = 0;
  }
  else {
    uVar1 = 0x57;
  }
  return uVar1;
}



/* c04f20d0 FUN_c04f20d0 */

/* Boundary evidence: original MIPS .pdata c04f20d0..c04f216b. Semantic name remains unreviewed. */

undefined4 FUN_c04f20d0(int *param_1,void *param_2,uint param_3,int param_4)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  
  uVar3 = param_3 + param_4;
  if ((uVar3 < param_3) || (iVar1 = FUN_c04f1a28(param_1,uVar3), iVar1 == 0)) {
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



/* c04f216c FUN_c04f216c */

/* Boundary evidence: original MIPS .pdata c04f216c..c04f220f. Semantic name remains unreviewed. */

undefined4 FUN_c04f216c(int *param_1,void *param_2,uint param_3,int param_4)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  
  uVar3 = param_3 + param_4;
  if ((uVar3 < param_3) || (iVar1 = FUN_c04f1afc(param_1,uVar3), iVar1 == 0)) {
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



/* c04f2210 FUN_c04f2210 */

/* Boundary evidence: original MIPS .pdata c04f2210..c04f225f. Semantic name remains unreviewed. */

void FUN_c04f2210(int *param_1,short *param_2)

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
  FUN_c04f216c(param_1,param_2,uVar2,0);
  return;
}



/* c04f2260 FUN_c04f2260 */

/* Boundary evidence: original MIPS .pdata c04f2260..c04f2307. Semantic name remains unreviewed. */

int FUN_c04f2260(int *param_1,undefined4 param_2,int param_3,int *param_4)

{
  int iVar1;
  int iVar2;
  int local_20 [2];
  
  if ((param_1[1] & 3U) == 0) {
    iVar2 = 0;
  }
  else {
    iVar2 = 4 - (param_1[1] & 3U);
  }
  iVar1 = FUN_c04f10a4(param_1,iVar2 + param_3,local_20);
  if (iVar1 == 0) {
    *param_4 = iVar2 + local_20[0];
    (**(code **)(*param_1 + 0xc))(param_1,iVar2 + local_20[0],param_2,param_3);
    iVar1 = 0;
  }
  return iVar1;
}



/* c04f2308 FUN_c04f2308 */

/* Boundary evidence: original MIPS .pdata c04f2308..c04f23af. Semantic name remains unreviewed. */

int FUN_c04f2308(int *param_1,undefined4 param_2,int param_3,int *param_4)

{
  int iVar1;
  int iVar2;
  int local_20 [2];
  
  if ((param_1[1] & 3U) == 0) {
    iVar2 = 0;
  }
  else {
    iVar2 = 4 - (param_1[1] & 3U);
  }
  iVar1 = FUN_c04f10a4(param_1,iVar2 + param_3,local_20);
  if (iVar1 == 0) {
    *param_4 = iVar2 + local_20[0];
    (**(code **)(*param_1 + 0xc))(param_1,iVar2 + local_20[0],param_2,param_3);
    iVar1 = 0;
  }
  return iVar1;
}



/* c04f23b0 FUN_c04f23b0 */

/* Boundary evidence: original MIPS .pdata c04f23b0..c04f2457. Semantic name remains unreviewed. */

int FUN_c04f23b0(int *param_1,undefined4 param_2,int param_3,int *param_4)

{
  int iVar1;
  int iVar2;
  int local_20 [2];
  
  if ((param_1[1] & 3U) == 0) {
    iVar2 = 0;
  }
  else {
    iVar2 = 4 - (param_1[1] & 3U);
  }
  iVar1 = FUN_c04f10a4(param_1,iVar2 + param_3,local_20);
  if (iVar1 == 0) {
    *param_4 = iVar2 + local_20[0];
    (**(code **)(*param_1 + 0xc))(param_1,iVar2 + local_20[0],param_2,param_3);
    iVar1 = 0;
  }
  return iVar1;
}



/* c04f2458 FUN_c04f2458 */

/* Boundary evidence: original MIPS .pdata c04f2458..c04f24ff. Semantic name remains unreviewed. */

int FUN_c04f2458(int *param_1,undefined4 param_2,int param_3,int *param_4)

{
  int iVar1;
  int iVar2;
  int local_20 [2];
  
  if ((param_1[1] & 1U) == 0) {
    iVar2 = 0;
  }
  else {
    iVar2 = 2 - (param_1[1] & 1U);
  }
  iVar1 = FUN_c04f10a4(param_1,iVar2 + param_3,local_20);
  if (iVar1 == 0) {
    *param_4 = iVar2 + local_20[0];
    (**(code **)(*param_1 + 0xc))(param_1,iVar2 + local_20[0],param_2,param_3);
    iVar1 = 0;
  }
  return iVar1;
}



/* c04f2500 FUN_c04f2500 */

/* Boundary evidence: original MIPS .pdata c04f2500..c04f257f. Semantic name remains unreviewed. */

int FUN_c04f2500(int *param_1,undefined4 param_2,int param_3,int *param_4)

{
  int iVar1;
  int local_20 [2];
  
  iVar1 = FUN_c04f10a4(param_1,param_3,local_20);
  if (iVar1 == 0) {
    *param_4 = local_20[0];
    (**(code **)(*param_1 + 0xc))(param_1,local_20[0],param_2,param_3);
    iVar1 = 0;
  }
  return iVar1;
}



/* c04f2580 FUN_c04f2580 */

/* Boundary evidence: original MIPS .pdata c04f2580..c04f25ff. Semantic name remains unreviewed. */

int FUN_c04f2580(int *param_1,undefined4 param_2,int param_3,int *param_4)

{
  int iVar1;
  int local_20 [2];
  
  iVar1 = FUN_c04f10a4(param_1,param_3,local_20);
  if (iVar1 == 0) {
    *param_4 = local_20[0];
    (**(code **)(*param_1 + 0xc))(param_1,local_20[0],param_2,param_3);
    iVar1 = 0;
  }
  return iVar1;
}



/* c04f2600 FUN_c04f2600 */

/* Boundary evidence: original MIPS .pdata c04f2600..c04f2673. Semantic name remains unreviewed. */

void FUN_c04f2600(int *param_1,int *param_2,int *param_3)

{
  int iVar1;
  
  if (*param_3 == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = param_3[1];
  }
  *param_1 = *param_3;
  param_1[1] = iVar1;
  if ((uint)param_3[1] < 0x40000000) {
    iVar1 = param_3[1] << 2;
  }
  else {
    iVar1 = -1;
  }
  FUN_c04f2260(param_2,*param_1,iVar1,param_1);
  return;
}



/* c04f2674 FUN_c04f2674 */

/* Boundary evidence: original MIPS .pdata c04f2674..c04f271b. Semantic name remains unreviewed. */

int FUN_c04f2674(int *param_1,undefined4 param_2,int param_3,int *param_4)

{
  int iVar1;
  int iVar2;
  int local_20 [2];
  
  if ((param_1[1] & 3U) == 0) {
    iVar2 = 0;
  }
  else {
    iVar2 = 4 - (param_1[1] & 3U);
  }
  iVar1 = FUN_c04f10a4(param_1,iVar2 + param_3,local_20);
  if (iVar1 == 0) {
    *param_4 = iVar2 + local_20[0];
    (**(code **)(*param_1 + 0xc))(param_1,iVar2 + local_20[0],param_2,param_3);
    iVar1 = 0;
  }
  return iVar1;
}



/* c04f271c FUN_c04f271c */

/* Boundary evidence: original MIPS .pdata c04f271c..c04f27c3. Semantic name remains unreviewed. */

int FUN_c04f271c(int *param_1,undefined4 param_2,int param_3,int *param_4)

{
  int iVar1;
  int iVar2;
  int local_20 [2];
  
  if ((param_1[1] & 1U) == 0) {
    iVar2 = 0;
  }
  else {
    iVar2 = 2 - (param_1[1] & 1U);
  }
  iVar1 = FUN_c04f10a4(param_1,iVar2 + param_3,local_20);
  if (iVar1 == 0) {
    *param_4 = iVar2 + local_20[0];
    (**(code **)(*param_1 + 0xc))(param_1,iVar2 + local_20[0],param_2,param_3);
    iVar1 = 0;
  }
  return iVar1;
}



/* c04f27c4 FUN_c04f27c4 */

/* Boundary evidence: original MIPS .pdata c04f27c4..c04f2843. Semantic name remains unreviewed. */

int FUN_c04f27c4(int *param_1,undefined4 param_2,int param_3,int *param_4)

{
  int iVar1;
  int local_20 [2];
  
  iVar1 = FUN_c04f10a4(param_1,param_3,local_20);
  if (iVar1 == 0) {
    *param_4 = local_20[0];
    (**(code **)(*param_1 + 0xc))(param_1,local_20[0],param_2,param_3);
    iVar1 = 0;
  }
  return iVar1;
}



/* c04f2844 FUN_c04f2844 */

/* Boundary evidence: original MIPS .pdata c04f2844..c04f28c3. Semantic name remains unreviewed. */

int FUN_c04f2844(int *param_1,undefined4 param_2,int param_3,int *param_4)

{
  int iVar1;
  int local_20 [2];
  
  iVar1 = FUN_c04f10a4(param_1,param_3,local_20);
  if (iVar1 == 0) {
    *param_4 = local_20[0];
    (**(code **)(*param_1 + 0xc))(param_1,local_20[0],param_2,param_3);
    iVar1 = 0;
  }
  return iVar1;
}



/* c04f28c4 FUN_c04f28c4 */

/* Boundary evidence: original MIPS .pdata c04f28c4..c04f296b. Semantic name remains unreviewed. */

int FUN_c04f28c4(int *param_1,undefined4 param_2,int param_3,int *param_4)

{
  int iVar1;
  int iVar2;
  int local_20 [2];
  
  if ((param_1[1] & 1U) == 0) {
    iVar2 = 0;
  }
  else {
    iVar2 = 2 - (param_1[1] & 1U);
  }
  iVar1 = FUN_c04f10a4(param_1,iVar2 + param_3,local_20);
  if (iVar1 == 0) {
    *param_4 = iVar2 + local_20[0];
    (**(code **)(*param_1 + 0xc))(param_1,iVar2 + local_20[0],param_2,param_3);
    iVar1 = 0;
  }
  return iVar1;
}



/* c04f296c FUN_c04f296c */

/* Boundary evidence: original MIPS .pdata c04f296c..c04f29bb. Semantic name remains unreviewed. */

undefined4 * FUN_c04f296c(undefined4 *param_1,uint param_2)

{
  void *pvVar1;
  
  param_1[1] = 0;
  *param_1 = &PTR_LAB_c04f1064;
  pvVar1 = operator_new__(param_2);
  param_1[2] = pvVar1;
  param_1[3] = param_2;
  return param_1;
}



/* c04f29f4 FUN_c04f29f4 */

/* Boundary evidence: original MIPS .pdata c04f29f4..c04f2a1f. Semantic name remains unreviewed. */

void FUN_c04f29f4(int param_1,int param_2,void *param_3,size_t param_4)

{
  memcpy((void *)(*(int *)(param_1 + 8) + param_2),param_3,param_4);
  return;
}



/* c04f2a20 FUN_c04f2a20 */

/* Boundary evidence: original MIPS .pdata c04f2a20..c04f2ab3. Semantic name remains unreviewed. */

undefined4 FUN_c04f2a20(int param_1,undefined4 *param_2,int param_3)

{
  undefined4 *puVar1;
  
  if (*(int *)(param_3 + 4) != 0) {
    (**(code **)*param_2)(param_2,*(int *)(param_3 + 4),1);
  }
  if (*(int *)(param_3 + 8) == 0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    puVar1 = (undefined4 *)(**(code **)*param_2)(param_2,*(int *)(param_3 + 8),4);
  }
  if (*(undefined4 **)(param_1 + 8) != (undefined4 *)0x0) {
    **(undefined4 **)(param_1 + 8) = *puVar1;
  }
  return 0;
}



/* c04f2ab4 FUN_c04f2ab4 */

/* Boundary evidence: original MIPS .pdata c04f2ab4..c04f2b2f. Semantic name remains unreviewed. */

int * FUN_c04f2ab4(int *param_1,char *param_2)

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
  FUN_c04f20d0(param_1,param_2,uVar2,0);
  return param_1;
}



/* c04f2b30 FUN_c04f2b30 */

/* Boundary evidence: original MIPS .pdata c04f2b30..c04f2b8b. Semantic name remains unreviewed. */

int FUN_c04f2b30(undefined4 *param_1)

{
  void *local_30 [6];
  int local_18;
  int local_14;
  uint local_10;
  
  local_10 = DAT_c04ff0b4;
  FUN_c04f2ab4((int *)local_30,(char *)*param_1);
  if (local_14 != 0x10) {
    operator_delete(local_30[0]);
  }
  FUN_c04fe38c(local_10);
  return local_18 + 1;
}



/* c04f2b8c FUN_c04f2b8c */

/* Boundary evidence: original MIPS .pdata c04f2b8c..c04f2c37. Semantic name remains unreviewed. */

int FUN_c04f2b8c(undefined4 *param_1)

{
  int iVar1;
  undefined2 *local_48;
  undefined2 local_44 [16];
  undefined2 local_24;
  int local_20;
  int local_1c;
  uint local_18;
  
  local_18 = DAT_c04ff0b4;
  local_48 = local_44;
  local_1c = 0x10;
  local_24 = 0;
  local_20 = 0;
  local_44[0] = 0;
  FUN_c04f2210((int *)&local_48,(short *)*param_1);
  if (local_20 + 1U < 0x80000000) {
    iVar1 = (local_20 + 1U) * 2;
  }
  else {
    iVar1 = -1;
  }
  if (local_1c != 0x10) {
    operator_delete(local_48);
  }
  FUN_c04fe38c(local_18);
  return iVar1;
}



/* c04f2c38 FUN_c04f2c38 */

/* Boundary evidence: original MIPS .pdata c04f2c38..c04f2cab. Semantic name remains unreviewed. */

void FUN_c04f2c38(int *param_1,int *param_2,int *param_3)

{
  int iVar1;
  
  if (*param_3 == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = param_3[1];
  }
  *param_1 = *param_3;
  param_1[1] = iVar1;
  if ((uint)param_3[1] < 0x80000000) {
    iVar1 = param_3[1] << 1;
  }
  else {
    iVar1 = -1;
  }
  FUN_c04f28c4(param_2,*param_1,iVar1,param_1);
  return;
}



/* c04f2cac FUN_c04f2cac */

/* Boundary evidence: original MIPS .pdata c04f2cac..c04f2d3f. Semantic name remains unreviewed. */

undefined4 FUN_c04f2cac(int param_1,undefined4 *param_2,int param_3)

{
  undefined4 *puVar1;
  
  if (*(int *)(param_3 + 4) != 0) {
    (**(code **)*param_2)(param_2,*(int *)(param_3 + 4),1);
  }
  if (*(int *)(param_3 + 8) == 0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    puVar1 = (undefined4 *)(**(code **)*param_2)(param_2,*(int *)(param_3 + 8),4);
  }
  if (*(undefined4 **)(param_1 + 8) != (undefined4 *)0x0) {
    **(undefined4 **)(param_1 + 8) = *puVar1;
  }
  return 0;
}



/* c04f2d40 FUN_c04f2d40 */

/* Boundary evidence: original MIPS .pdata c04f2d40..c04f2d93. Semantic name remains unreviewed. */

int FUN_c04f2d40(int param_1,undefined4 *param_2,int param_3)

{
  int iVar1;
  int aiStack_18 [2];
  
  iVar1 = FUN_c04f2cac(param_1,param_2,param_3);
  if (iVar1 == 0) {
    FUN_c04f1c5c((undefined4 *)(param_3 + 0x10),aiStack_18,param_2);
    iVar1 = 0;
  }
  return iVar1;
}



/* c04f2d94 FUN_c04f2d94 */

/* Boundary evidence: original MIPS .pdata c04f2d94..c04f2e1b. Semantic name remains unreviewed. */

int FUN_c04f2d94(int param_1,undefined4 *param_2,int param_3)

{
  int iVar1;
  void *local_18;
  size_t local_14;
  
  iVar1 = FUN_c04f2cac(param_1,param_2,param_3);
  if (iVar1 == 0) {
    FUN_c04f1ef0((undefined4 *)(param_3 + 0xc),(int *)&local_18,param_2);
    if (*(size_t *)(param_1 + 0x10) == local_14) {
      memcpy(*(void **)(param_1 + 0xc),local_18,*(size_t *)(param_1 + 0x10));
      iVar1 = 0;
    }
    else {
      iVar1 = 0x57;
    }
  }
  return iVar1;
}



/* c04f2e1c FUN_c04f2e1c */

/* Boundary evidence: original MIPS .pdata c04f2e1c..c04f2eb3. Semantic name remains unreviewed. */

int FUN_c04f2e1c(int param_1,undefined4 *param_2,int param_3)

{
  int iVar1;
  int *piVar2;
  size_t sVar3;
  int aiStack_18 [2];
  
  iVar1 = FUN_c04f2cac(param_1,param_2,param_3);
  if (iVar1 == 0) {
    piVar2 = FUN_c04f1c5c((undefined4 *)(param_3 + 0x10),aiStack_18,param_2);
    if ((void *)*piVar2 == (void *)0x0) {
      sVar3 = 0;
    }
    else {
      sVar3 = piVar2[1];
    }
    if (*(size_t *)(param_1 + 0x14) == sVar3) {
      memcpy(*(void **)(param_1 + 0x10),(void *)*piVar2,*(size_t *)(param_1 + 0x14));
      iVar1 = 0;
    }
    else {
      iVar1 = 0x57;
    }
  }
  return iVar1;
}



/* c04f2eb4 FUN_c04f2eb4 */

/* Boundary evidence: original MIPS .pdata c04f2eb4..c04f2f07. Semantic name remains unreviewed. */

int FUN_c04f2eb4(int param_1,undefined4 *param_2,int param_3)

{
  int iVar1;
  int aiStack_18 [2];
  
  iVar1 = FUN_c04f2cac(param_1,param_2,param_3);
  if (iVar1 == 0) {
    FUN_c04f1ef0((undefined4 *)(param_3 + 0xc),aiStack_18,param_2);
    iVar1 = 0;
  }
  return iVar1;
}



/* c04f2f08 FUN_c04f2f08 */

/* Boundary evidence: original MIPS .pdata c04f2f08..c04f2f97. Semantic name remains unreviewed. */

int FUN_c04f2f08(int param_1,undefined4 *param_2,int param_3)

{
  int iVar1;
  undefined4 *puVar2;
  
  iVar1 = FUN_c04f2cac(param_1,param_2,param_3);
  if (iVar1 == 0) {
    if (*(int *)(param_3 + 0xc) == 0) {
      puVar2 = (undefined4 *)0x0;
    }
    else {
      puVar2 = (undefined4 *)(**(code **)*param_2)(param_2,*(int *)(param_3 + 0xc),4);
    }
    if (*(undefined4 **)(param_1 + 0xc) != (undefined4 *)0x0) {
      **(undefined4 **)(param_1 + 0xc) = *puVar2;
    }
    iVar1 = 0;
  }
  return iVar1;
}



/* c04f2f98 FUN_c04f2f98 */

/* Boundary evidence: original MIPS .pdata c04f2f98..c04f301f. Semantic name remains unreviewed. */

int FUN_c04f2f98(int param_1,undefined4 *param_2,int param_3)

{
  int iVar1;
  void *local_18;
  size_t local_14;
  
  iVar1 = FUN_c04f2cac(param_1,param_2,param_3);
  if (iVar1 == 0) {
    FUN_c04f1d10((undefined4 *)(param_3 + 0x10),(int *)&local_18,param_2);
    if (*(size_t *)(param_1 + 0x14) == local_14) {
      memcpy(*(void **)(param_1 + 0x10),local_18,*(size_t *)(param_1 + 0x14));
      iVar1 = 0;
    }
    else {
      iVar1 = 0x57;
    }
  }
  return iVar1;
}



/* c04f3020 FUN_c04f3020 */

/* Boundary evidence: original MIPS .pdata c04f3020..c04f3073. Semantic name remains unreviewed. */

int FUN_c04f3020(int param_1,undefined4 *param_2,int param_3)

{
  int iVar1;
  int aiStack_18 [2];
  
  iVar1 = FUN_c04f2cac(param_1,param_2,param_3);
  if (iVar1 == 0) {
    FUN_c04f1d10((undefined4 *)(param_3 + 0x10),aiStack_18,param_2);
    iVar1 = 0;
  }
  return iVar1;
}



/* c04f3074 FUN_c04f3074 */

/* Boundary evidence: original MIPS .pdata c04f3074..c04f30c7. Semantic name remains unreviewed. */

int FUN_c04f3074(int param_1,undefined4 *param_2,int param_3)

{
  int iVar1;
  int aiStack_18 [2];
  
  iVar1 = FUN_c04f2cac(param_1,param_2,param_3);
  if (iVar1 == 0) {
    FUN_c04f1dc4((undefined4 *)(param_3 + 0xc),aiStack_18,param_2);
    iVar1 = 0;
  }
  return iVar1;
}



/* c04f30c8 FUN_c04f30c8 */

/* Boundary evidence: original MIPS .pdata c04f30c8..c04f312f. Semantic name remains unreviewed. */

int FUN_c04f30c8(int *param_1,int *param_2,int *param_3)

{
  int iVar1;
  
  if (*param_3 == 0) {
    *param_1 = 0;
    iVar1 = 0;
  }
  else {
    iVar1 = FUN_c04f2b30(param_3);
    iVar1 = FUN_c04f2500(param_2,*param_3,iVar1,param_1);
  }
  return iVar1;
}



/* c04f3130 FUN_c04f3130 */

/* Boundary evidence: original MIPS .pdata c04f3130..c04f31e3. Semantic name remains unreviewed. */

undefined4 FUN_c04f3130(int *param_1,undefined4 *param_2)

{
  char *pcVar1;
  undefined4 uVar2;
  void *local_38 [6];
  int local_20;
  int local_1c;
  uint local_18;
  
  local_18 = DAT_c04ff0b4;
  if (*param_1 == 0) {
    FUN_c04fe38c(DAT_c04ff0b4);
    uVar2 = 0;
  }
  else {
    pcVar1 = (char *)(**(code **)*param_2)(param_2,*param_1,1);
    FUN_c04f2ab4((int *)local_38,pcVar1);
    uVar2 = (**(code **)*param_2)(param_2,*param_1,local_20 + 1);
    if (local_1c != 0x10) {
      operator_delete(local_38[0]);
    }
    FUN_c04fe38c(local_18);
  }
  return uVar2;
}



/* c04f31e4 FUN_c04f31e4 */

/* Boundary evidence: original MIPS .pdata c04f31e4..c04f3273. Semantic name remains unreviewed. */

int FUN_c04f31e4(int param_1,undefined4 *param_2,int param_3)

{
  int iVar1;
  undefined4 *puVar2;
  
  iVar1 = FUN_c04f2cac(param_1,param_2,param_3);
  if (iVar1 == 0) {
    if (*(int *)(param_3 + 0xc) == 0) {
      puVar2 = (undefined4 *)0x0;
    }
    else {
      puVar2 = (undefined4 *)(**(code **)*param_2)(param_2,*(int *)(param_3 + 0xc),4);
    }
    if (*(undefined4 **)(param_1 + 0xc) != (undefined4 *)0x0) {
      **(undefined4 **)(param_1 + 0xc) = *puVar2;
    }
    iVar1 = 0;
  }
  return iVar1;
}



/* c04f3274 FUN_c04f3274 */

/* Boundary evidence: original MIPS .pdata c04f3274..c04f32df. Semantic name remains unreviewed. */

void FUN_c04f3274(int param_1,undefined4 *param_2,int param_3)

{
  int iVar1;
  int aiStack_18 [2];
  
  iVar1 = FUN_c04f2cac(param_1,param_2,param_3);
  if (iVar1 == 0) {
    FUN_c04f1dc4((undefined4 *)(param_3 + 0xc),aiStack_18,param_2);
    FUN_c04f1e88((undefined4 *)(param_1 + 0xc),aiStack_18);
  }
  return;
}



/* c04f32e0 FUN_c04f32e0 */

/* Boundary evidence: original MIPS .pdata c04f32e0..c04f3333. Semantic name remains unreviewed. */

int FUN_c04f32e0(int param_1,undefined4 *param_2,int param_3)

{
  int iVar1;
  int aiStack_18 [2];
  
  iVar1 = FUN_c04f2cac(param_1,param_2,param_3);
  if (iVar1 == 0) {
    FUN_c04f1d10((undefined4 *)(param_3 + 0xc),aiStack_18,param_2);
    iVar1 = 0;
  }
  return iVar1;
}



/* c04f3334 FUN_c04f3334 */

/* Boundary evidence: original MIPS .pdata c04f3334..c04f3387. Semantic name remains unreviewed. */

int FUN_c04f3334(int param_1,undefined4 *param_2,int param_3)

{
  int iVar1;
  int aiStack_18 [2];
  
  iVar1 = FUN_c04f2cac(param_1,param_2,param_3);
  if (iVar1 == 0) {
    FUN_c04f1c5c((undefined4 *)(param_3 + 0xc),aiStack_18,param_2);
    iVar1 = 0;
  }
  return iVar1;
}



/* c04f3388 FUN_c04f3388 */

/* Boundary evidence: original MIPS .pdata c04f3388..c04f33ef. Semantic name remains unreviewed. */

int FUN_c04f3388(int *param_1,int *param_2,int *param_3)

{
  int iVar1;
  
  if (*param_3 == 0) {
    *param_1 = 0;
    iVar1 = 0;
  }
  else {
    iVar1 = FUN_c04f2b8c(param_3);
    iVar1 = FUN_c04f271c(param_2,*param_3,iVar1,param_1);
  }
  return iVar1;
}



/* c04f33f0 FUN_c04f33f0 */

/* Boundary evidence: original MIPS .pdata c04f33f0..c04f34fb. Semantic name remains unreviewed. */

undefined4 FUN_c04f33f0(int *param_1,undefined4 *param_2)

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
  
  local_20 = DAT_c04ff0b4;
  if (*param_1 == 0) {
    FUN_c04fe38c(DAT_c04ff0b4);
    uVar3 = 0;
  }
  else {
    psVar1 = (short *)(**(code **)*param_2)(param_2,*param_1,1);
    local_50 = local_4c;
    local_24 = 0x10;
    local_2c = 0;
    local_28 = 0;
    local_4c[0] = 0;
    FUN_c04f2210((int *)&local_50,psVar1);
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
    FUN_c04fe38c(local_20);
  }
  return uVar3;
}



/* c04f34fc FUN_c04f34fc */

/* Boundary evidence: original MIPS .pdata c04f34fc..c04f3583. Semantic name remains unreviewed. */

int FUN_c04f34fc(int param_1,undefined4 *param_2,int param_3)

{
  int iVar1;
  void *local_18;
  size_t local_14;
  
  iVar1 = FUN_c04f2f98(param_1,param_2,param_3);
  if (iVar1 == 0) {
    FUN_c04f1d10((undefined4 *)(param_3 + 0x18),(int *)&local_18,param_2);
    if (*(size_t *)(param_1 + 0x1c) == local_14) {
      memcpy(*(void **)(param_1 + 0x18),local_18,*(size_t *)(param_1 + 0x1c));
      iVar1 = 0;
    }
    else {
      iVar1 = 0x57;
    }
  }
  return iVar1;
}



/* c04f3584 FUN_c04f3584 */

/* Boundary evidence: original MIPS .pdata c04f3584..c04f35d7. Semantic name remains unreviewed. */

int FUN_c04f3584(int param_1,undefined4 *param_2,int param_3)

{
  int iVar1;
  int aiStack_18 [2];
  
  iVar1 = FUN_c04f3020(param_1,param_2,param_3);
  if (iVar1 == 0) {
    FUN_c04f1d10((undefined4 *)(param_3 + 0x18),aiStack_18,param_2);
    iVar1 = 0;
  }
  return iVar1;
}



/* c04f35d8 FUN_c04f35d8 */

/* Boundary evidence: original MIPS .pdata c04f35d8..c04f366f. Semantic name remains unreviewed. */

int FUN_c04f35d8(int param_1,undefined4 *param_2,int param_3)

{
  int iVar1;
  int *piVar2;
  size_t sVar3;
  int aiStack_18 [2];
  
  iVar1 = FUN_c04f2cac(param_1,param_2,param_3);
  if (iVar1 == 0) {
    piVar2 = FUN_c04f1c5c((undefined4 *)(param_3 + 0x10),aiStack_18,param_2);
    if ((void *)*piVar2 == (void *)0x0) {
      sVar3 = 0;
    }
    else {
      sVar3 = piVar2[1];
    }
    if (*(size_t *)(param_1 + 0x14) == sVar3) {
      memcpy(*(void **)(param_1 + 0x10),(void *)*piVar2,*(size_t *)(param_1 + 0x14));
      iVar1 = 0;
    }
    else {
      iVar1 = 0x57;
    }
  }
  return iVar1;
}



/* c04f3670 FUN_c04f3670 */

/* Boundary evidence: original MIPS .pdata c04f3670..c04f36ff. Semantic name remains unreviewed. */

int FUN_c04f3670(int param_1,undefined4 *param_2,int param_3)

{
  int iVar1;
  undefined4 *puVar2;
  
  iVar1 = FUN_c04f2e1c(param_1,param_2,param_3);
  if (iVar1 == 0) {
    if (*(int *)(param_3 + 0x18) == 0) {
      puVar2 = (undefined4 *)0x0;
    }
    else {
      puVar2 = (undefined4 *)(**(code **)*param_2)(param_2,*(int *)(param_3 + 0x18),4);
    }
    if (*(undefined4 **)(param_1 + 0x18) != (undefined4 *)0x0) {
      **(undefined4 **)(param_1 + 0x18) = *puVar2;
    }
    iVar1 = 0;
  }
  return iVar1;
}



/* c04f3700 FUN_c04f3700 */

/* Boundary evidence: original MIPS .pdata c04f3700..c04f378f. Semantic name remains unreviewed. */

int FUN_c04f3700(int param_1,undefined4 *param_2,int param_3)

{
  int iVar1;
  undefined4 *puVar2;
  
  iVar1 = FUN_c04f2cac(param_1,param_2,param_3);
  if (iVar1 == 0) {
    if (*(int *)(param_3 + 0x14) == 0) {
      puVar2 = (undefined4 *)0x0;
    }
    else {
      puVar2 = (undefined4 *)(**(code **)*param_2)(param_2,*(int *)(param_3 + 0x14),4);
    }
    if (*(undefined4 **)(param_1 + 0x14) != (undefined4 *)0x0) {
      **(undefined4 **)(param_1 + 0x14) = *puVar2;
    }
    iVar1 = 0;
  }
  return iVar1;
}



/* c04f3790 FUN_c04f3790 */

/* Boundary evidence: original MIPS .pdata c04f3790..c04f3827. Semantic name remains unreviewed. */

int FUN_c04f3790(int param_1,undefined4 *param_2,int param_3)

{
  int iVar1;
  int *piVar2;
  size_t sVar3;
  int aiStack_18 [2];
  
  iVar1 = FUN_c04f2f08(param_1,param_2,param_3);
  if (iVar1 == 0) {
    piVar2 = FUN_c04f1c5c((undefined4 *)(param_3 + 0x10),aiStack_18,param_2);
    if ((void *)*piVar2 == (void *)0x0) {
      sVar3 = 0;
    }
    else {
      sVar3 = piVar2[1];
    }
    if (*(size_t *)(param_1 + 0x14) == sVar3) {
      memcpy(*(void **)(param_1 + 0x10),(void *)*piVar2,*(size_t *)(param_1 + 0x14));
      iVar1 = 0;
    }
    else {
      iVar1 = 0x57;
    }
  }
  return iVar1;
}



/* c04f3828 FUN_c04f3828 */

/* Boundary evidence: original MIPS .pdata c04f3828..c04f38bf. Semantic name remains unreviewed. */

int FUN_c04f3828(int param_1,undefined4 *param_2,int param_3)

{
  int iVar1;
  int *piVar2;
  size_t sVar3;
  int aiStack_18 [2];
  
  iVar1 = FUN_c04f2cac(param_1,param_2,param_3);
  if (iVar1 == 0) {
    piVar2 = FUN_c04f1c5c((undefined4 *)(param_3 + 0x18),aiStack_18,param_2);
    if ((void *)*piVar2 == (void *)0x0) {
      sVar3 = 0;
    }
    else {
      sVar3 = piVar2[1];
    }
    if (*(size_t *)(param_1 + 0x1c) == sVar3) {
      memcpy(*(void **)(param_1 + 0x18),(void *)*piVar2,*(size_t *)(param_1 + 0x1c));
      iVar1 = 0;
    }
    else {
      iVar1 = 0x57;
    }
  }
  return iVar1;
}



/* c04f38c0 FUN_c04f38c0 */

/* Boundary evidence: original MIPS .pdata c04f38c0..c04f394f. Semantic name remains unreviewed. */

int FUN_c04f38c0(int param_1,undefined4 *param_2,int param_3)

{
  int iVar1;
  undefined4 *puVar2;
  
  iVar1 = FUN_c04f2cac(param_1,param_2,param_3);
  if (iVar1 == 0) {
    if (*(int *)(param_3 + 0x14) == 0) {
      puVar2 = (undefined4 *)0x0;
    }
    else {
      puVar2 = (undefined4 *)(**(code **)*param_2)(param_2,*(int *)(param_3 + 0x14),4);
    }
    if (*(undefined4 **)(param_1 + 0x14) != (undefined4 *)0x0) {
      **(undefined4 **)(param_1 + 0x14) = *puVar2;
    }
    iVar1 = 0;
  }
  return iVar1;
}



/* c04f3950 FUN_c04f3950 */

/* Boundary evidence: original MIPS .pdata c04f3950..c04f39df. Semantic name remains unreviewed. */

int FUN_c04f3950(int param_1,undefined4 *param_2,int param_3)

{
  int iVar1;
  undefined2 *puVar2;
  
  iVar1 = FUN_c04f2cac(param_1,param_2,param_3);
  if (iVar1 == 0) {
    if (*(int *)(param_3 + 0x14) == 0) {
      puVar2 = (undefined2 *)0x0;
    }
    else {
      puVar2 = (undefined2 *)(**(code **)*param_2)(param_2,*(int *)(param_3 + 0x14),2);
    }
    if (*(undefined2 **)(param_1 + 0x14) != (undefined2 *)0x0) {
      **(undefined2 **)(param_1 + 0x14) = *puVar2;
    }
    iVar1 = 0;
  }
  return iVar1;
}



/* c04f39e0 FUN_c04f39e0 */

/* Boundary evidence: original MIPS .pdata c04f39e0..c04f3a77. Semantic name remains unreviewed. */

int FUN_c04f39e0(int param_1,undefined4 *param_2,int param_3)

{
  int iVar1;
  int *piVar2;
  size_t sVar3;
  int aiStack_18 [2];
  
  iVar1 = FUN_c04f2a20(param_1,param_2,param_3);
  if (iVar1 == 0) {
    piVar2 = FUN_c04f1c5c((undefined4 *)(param_3 + 0x10),aiStack_18,param_2);
    if ((void *)*piVar2 == (void *)0x0) {
      sVar3 = 0;
    }
    else {
      sVar3 = piVar2[1];
    }
    if (*(size_t *)(param_1 + 0x14) == sVar3) {
      memcpy(*(void **)(param_1 + 0x10),(void *)*piVar2,*(size_t *)(param_1 + 0x14));
      iVar1 = 0;
    }
    else {
      iVar1 = 0x57;
    }
  }
  return iVar1;
}



/* c04f3a78 FUN_c04f3a78 */

/* Boundary evidence: original MIPS .pdata c04f3a78..c04f3acb. Semantic name remains unreviewed. */

int FUN_c04f3a78(int param_1,undefined4 *param_2,int param_3)

{
  int iVar1;
  int aiStack_18 [2];
  
  iVar1 = FUN_c04f2cac(param_1,param_2,param_3);
  if (iVar1 == 0) {
    FUN_c04f1d10((undefined4 *)(param_3 + 0x18),aiStack_18,param_2);
    iVar1 = 0;
  }
  return iVar1;
}



/* c04f3acc FUN_c04f3acc */

/* Boundary evidence: original MIPS .pdata c04f3acc..c04f3b53. Semantic name remains unreviewed. */

int FUN_c04f3acc(int param_1,undefined4 *param_2,int param_3)

{
  int iVar1;
  void *local_18;
  size_t local_14;
  
  iVar1 = FUN_c04f2cac(param_1,param_2,param_3);
  if (iVar1 == 0) {
    FUN_c04f1d10((undefined4 *)(param_3 + 0x18),(int *)&local_18,param_2);
    if (*(size_t *)(param_1 + 0x1c) == local_14) {
      memcpy(*(void **)(param_1 + 0x18),local_18,*(size_t *)(param_1 + 0x1c));
      iVar1 = 0;
    }
    else {
      iVar1 = 0x57;
    }
  }
  return iVar1;
}



/* c04f3b54 FUN_c04f3b54 */

/* Boundary evidence: original MIPS .pdata c04f3b54..c04f3beb. Semantic name remains unreviewed. */

int FUN_c04f3b54(int param_1,undefined4 *param_2,int param_3)

{
  int iVar1;
  int *piVar2;
  size_t sVar3;
  int aiStack_18 [2];
  
  iVar1 = FUN_c04f3074(param_1,param_2,param_3);
  if (iVar1 == 0) {
    piVar2 = FUN_c04f1c5c((undefined4 *)(param_3 + 0x14),aiStack_18,param_2);
    if ((void *)*piVar2 == (void *)0x0) {
      sVar3 = 0;
    }
    else {
      sVar3 = piVar2[1];
    }
    if (*(size_t *)(param_1 + 0x18) == sVar3) {
      memcpy(*(void **)(param_1 + 0x14),(void *)*piVar2,*(size_t *)(param_1 + 0x18));
      iVar1 = 0;
    }
    else {
      iVar1 = 0x57;
    }
  }
  return iVar1;
}



/* c04f3bec FUN_c04f3bec */

/* Boundary evidence: original MIPS .pdata c04f3bec..c04f3c57. Semantic name remains unreviewed. */

void FUN_c04f3bec(int param_1,undefined4 *param_2,int param_3)

{
  int iVar1;
  int aiStack_18 [2];
  
  iVar1 = FUN_c04f3274(param_1,param_2,param_3);
  if (iVar1 == 0) {
    FUN_c04f1dc4((undefined4 *)(param_3 + 0x14),aiStack_18,param_2);
    FUN_c04f1e88((undefined4 *)(param_1 + 0x14),aiStack_18);
  }
  return;
}



/* c04f3c58 FUN_c04f3c58 */

/* Boundary evidence: original MIPS .pdata c04f3c58..c04f3cdb. Semantic name remains unreviewed. */

undefined4 FUN_c04f3c58(undefined2 *param_1,int *param_2,undefined2 *param_3)

{
  int iVar1;
  
  *param_1 = *param_3;
  iVar1 = *(int *)(param_3 + 2);
  *(int *)(param_1 + 2) = iVar1;
  if (iVar1 != 0) {
    FUN_c04f2580(param_2,*(undefined4 *)(param_3 + 2),1,(int *)(param_1 + 2));
  }
  iVar1 = *(int *)(param_3 + 4);
  *(int *)(param_1 + 4) = iVar1;
  if (iVar1 != 0) {
    FUN_c04f2674(param_2,*(undefined4 *)(param_3 + 4),4,(int *)(param_1 + 4));
  }
  return 0;
}



/* c04f3cdc FUN_c04f3cdc */

/* Boundary evidence: original MIPS .pdata c04f3cdc..c04f3d63. Semantic name remains unreviewed. */

int FUN_c04f3cdc(int param_1,undefined4 *param_2,int param_3)

{
  int iVar1;
  void *local_18;
  size_t local_14;
  
  iVar1 = FUN_c04f3334(param_1,param_2,param_3);
  if (iVar1 == 0) {
    FUN_c04f1ef0((undefined4 *)(param_3 + 0x18),(int *)&local_18,param_2);
    if (*(size_t *)(param_1 + 0x1c) == local_14) {
      memcpy(*(void **)(param_1 + 0x18),local_18,*(size_t *)(param_1 + 0x1c));
      iVar1 = 0;
    }
    else {
      iVar1 = 0x57;
    }
  }
  return iVar1;
}



/* c04f3d64 FUN_c04f3d64 */

/* Boundary evidence: original MIPS .pdata c04f3d64..c04f3deb. Semantic name remains unreviewed. */

int FUN_c04f3d64(int param_1,undefined4 *param_2,int param_3)

{
  int iVar1;
  void *local_18;
  size_t local_14;
  
  iVar1 = FUN_c04f34fc(param_1,param_2,param_3);
  if (iVar1 == 0) {
    FUN_c04f1d10((undefined4 *)(param_3 + 0x20),(int *)&local_18,param_2);
    if (*(size_t *)(param_1 + 0x24) == local_14) {
      memcpy(*(void **)(param_1 + 0x20),local_18,*(size_t *)(param_1 + 0x24));
      iVar1 = 0;
    }
    else {
      iVar1 = 0x57;
    }
  }
  return iVar1;
}



/* c04f3dec FUN_c04f3dec */

/* Boundary evidence: original MIPS .pdata c04f3dec..c04f3e3f. Semantic name remains unreviewed. */

int FUN_c04f3dec(int param_1,undefined4 *param_2,int param_3)

{
  int iVar1;
  int aiStack_18 [2];
  
  iVar1 = FUN_c04f3584(param_1,param_2,param_3);
  if (iVar1 == 0) {
    FUN_c04f1d10((undefined4 *)(param_3 + 0x20),aiStack_18,param_2);
    iVar1 = 0;
  }
  return iVar1;
}



/* c04f3e40 FUN_c04f3e40 */

/* Boundary evidence: original MIPS .pdata c04f3e40..c04f3ec3. Semantic name remains unreviewed. */

undefined4 FUN_c04f3e40(undefined2 *param_1,int *param_2,undefined2 *param_3)

{
  int iVar1;
  
  *param_1 = *param_3;
  iVar1 = *(int *)(param_3 + 2);
  *(int *)(param_1 + 2) = iVar1;
  if (iVar1 != 0) {
    FUN_c04f2580(param_2,*(undefined4 *)(param_3 + 2),1,(int *)(param_1 + 2));
  }
  iVar1 = *(int *)(param_3 + 4);
  *(int *)(param_1 + 4) = iVar1;
  if (iVar1 != 0) {
    FUN_c04f2260(param_2,*(undefined4 *)(param_3 + 4),4,(int *)(param_1 + 4));
  }
  return 0;
}



/* c04f3ec4 FUN_c04f3ec4 */

/* Boundary evidence: original MIPS .pdata c04f3ec4..c04f3f53. Semantic name remains unreviewed. */

int FUN_c04f3ec4(int param_1,undefined4 *param_2,int param_3)

{
  int iVar1;
  undefined4 *puVar2;
  
  iVar1 = FUN_c04f39e0(param_1,param_2,param_3);
  if (iVar1 == 0) {
    if (*(int *)(param_3 + 0x18) == 0) {
      puVar2 = (undefined4 *)0x0;
    }
    else {
      puVar2 = (undefined4 *)(**(code **)*param_2)(param_2,*(int *)(param_3 + 0x18),4);
    }
    if (*(undefined4 **)(param_1 + 0x18) != (undefined4 *)0x0) {
      **(undefined4 **)(param_1 + 0x18) = *puVar2;
    }
    iVar1 = 0;
  }
  return iVar1;
}



/* c04f3f54 FUN_c04f3f54 */

/* Boundary evidence: original MIPS .pdata c04f3f54..c04f3faf. Semantic name remains unreviewed. */

int FUN_c04f3f54(undefined2 *param_1,int *param_2,undefined2 *param_3)

{
  int iVar1;
  
  iVar1 = FUN_c04f3e40(param_1,param_2,param_3);
  if (iVar1 == 0) {
    *(undefined4 *)(param_1 + 6) = *(undefined4 *)(param_3 + 6);
    iVar1 = 0;
    *(undefined4 *)(param_1 + 8) = *(undefined4 *)(param_3 + 8);
  }
  return iVar1;
}



/* c04f3fb0 FUN_c04f3fb0 */

/* Boundary evidence: original MIPS .pdata c04f3fb0..c04f403f. Semantic name remains unreviewed. */

int FUN_c04f3fb0(int param_1,undefined4 *param_2,int param_3)

{
  int iVar1;
  undefined4 *puVar2;
  
  iVar1 = FUN_c04f3acc(param_1,param_2,param_3);
  if (iVar1 == 0) {
    if (*(int *)(param_3 + 0x20) == 0) {
      puVar2 = (undefined4 *)0x0;
    }
    else {
      puVar2 = (undefined4 *)(**(code **)*param_2)(param_2,*(int *)(param_3 + 0x20),4);
    }
    if (*(undefined4 **)(param_1 + 0x20) != (undefined4 *)0x0) {
      **(undefined4 **)(param_1 + 0x20) = *puVar2;
    }
    iVar1 = 0;
  }
  return iVar1;
}



/* c04f4040 FUN_c04f4040 */

/* Boundary evidence: original MIPS .pdata c04f4040..c04f40cf. Semantic name remains unreviewed. */

int FUN_c04f4040(int param_1,undefined4 *param_2,int param_3)

{
  int iVar1;
  undefined4 *puVar2;
  
  iVar1 = FUN_c04f3b54(param_1,param_2,param_3);
  if (iVar1 == 0) {
    if (*(int *)(param_3 + 0x1c) == 0) {
      puVar2 = (undefined4 *)0x0;
    }
    else {
      puVar2 = (undefined4 *)(**(code **)*param_2)(param_2,*(int *)(param_3 + 0x1c),4);
    }
    if (*(undefined4 **)(param_1 + 0x1c) != (undefined4 *)0x0) {
      **(undefined4 **)(param_1 + 0x1c) = *puVar2;
    }
    iVar1 = 0;
  }
  return iVar1;
}



/* c04f40d0 FUN_c04f40d0 */

/* Boundary evidence: original MIPS .pdata c04f40d0..c04f4123. Semantic name remains unreviewed. */

int FUN_c04f40d0(int param_1,undefined4 *param_2,int param_3)

{
  int iVar1;
  int aiStack_18 [2];
  
  iVar1 = FUN_c04f31e4(param_1,param_2,param_3);
  if (iVar1 == 0) {
    FUN_c04f1c5c((undefined4 *)(param_3 + 0x14),aiStack_18,param_2);
    iVar1 = 0;
  }
  return iVar1;
}



/* c04f4124 FUN_c04f4124 */

/* Boundary evidence: original MIPS .pdata c04f4124..c04f41bb. Semantic name remains unreviewed. */

int FUN_c04f4124(undefined2 *param_1,int *param_2,undefined2 *param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_c04f3e40(param_1,param_2,param_3);
  if (iVar1 == 0) {
    *(undefined4 *)(param_1 + 6) = *(undefined4 *)(param_3 + 6);
    iVar1 = *(int *)(param_3 + 8);
    if (iVar1 == 0) {
      uVar2 = 0;
    }
    else {
      uVar2 = *(undefined4 *)(param_3 + 10);
    }
    *(int *)(param_1 + 8) = iVar1;
    *(undefined4 *)(param_1 + 10) = uVar2;
    FUN_c04f23b0(param_2,iVar1,*(int *)(param_3 + 10),(int *)(param_1 + 8));
    iVar1 = 0;
  }
  return iVar1;
}



/* c04f41bc FUN_c04f41bc */

/* Boundary evidence: original MIPS .pdata c04f41bc..c04f4253. Semantic name remains unreviewed. */

int FUN_c04f41bc(int param_1,undefined4 *param_2,int param_3)

{
  int iVar1;
  int *piVar2;
  size_t sVar3;
  int aiStack_18 [2];
  
  iVar1 = FUN_c04f2f98(param_1,param_2,param_3);
  if (iVar1 == 0) {
    piVar2 = FUN_c04f1c5c((undefined4 *)(param_3 + 0x20),aiStack_18,param_2);
    if ((void *)*piVar2 == (void *)0x0) {
      sVar3 = 0;
    }
    else {
      sVar3 = piVar2[1];
    }
    if (*(size_t *)(param_1 + 0x24) == sVar3) {
      memcpy(*(void **)(param_1 + 0x20),(void *)*piVar2,*(size_t *)(param_1 + 0x24));
      iVar1 = 0;
    }
    else {
      iVar1 = 0x57;
    }
  }
  return iVar1;
}



/* c04f4254 FUN_c04f4254 */

/* Boundary evidence: original MIPS .pdata c04f4254..c04f42bf. Semantic name remains unreviewed. */

void FUN_c04f4254(int param_1,undefined4 *param_2,int param_3)

{
  int iVar1;
  int aiStack_18 [2];
  
  iVar1 = FUN_c04f3bec(param_1,param_2,param_3);
  if (iVar1 == 0) {
    FUN_c04f1dc4((undefined4 *)(param_3 + 0x1c),aiStack_18,param_2);
    FUN_c04f1e88((undefined4 *)(param_1 + 0x1c),aiStack_18);
  }
  return;
}



/* c04f42c0 FUN_c04f42c0 */

/* Boundary evidence: original MIPS .pdata c04f42c0..c04f4313. Semantic name remains unreviewed. */

int FUN_c04f42c0(int param_1,undefined4 *param_2,int param_3)

{
  int iVar1;
  int aiStack_18 [2];
  
  iVar1 = FUN_c04f3020(param_1,param_2,param_3);
  if (iVar1 == 0) {
    FUN_c04f1d10((undefined4 *)(param_3 + 0x20),aiStack_18,param_2);
    iVar1 = 0;
  }
  return iVar1;
}



/* c04f4314 FUN_c04f4314 */

/* Boundary evidence: original MIPS .pdata c04f4314..c04f4377. Semantic name remains unreviewed. */

int FUN_c04f4314(undefined2 *param_1,int *param_2,undefined2 *param_3)

{
  int iVar1;
  
  iVar1 = FUN_c04f3e40(param_1,param_2,param_3);
  if (iVar1 == 0) {
    FUN_c04f30c8((int *)(param_1 + 6),param_2,(int *)(param_3 + 6));
    iVar1 = 0;
  }
  return iVar1;
}



/* c04f4378 FUN_c04f4378 */

/* Boundary evidence: original MIPS .pdata c04f4378..c04f43ff. Semantic name remains unreviewed. */

int FUN_c04f4378(undefined2 *param_1,int *param_2,undefined2 *param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_c04f3e40(param_1,param_2,param_3);
  if (iVar1 == 0) {
    iVar1 = *(int *)(param_3 + 6);
    if (iVar1 == 0) {
      uVar2 = 0;
    }
    else {
      uVar2 = *(undefined4 *)(param_3 + 8);
    }
    *(int *)(param_1 + 6) = iVar1;
    *(undefined4 *)(param_1 + 8) = uVar2;
    FUN_c04f2844(param_2,iVar1,*(int *)(param_3 + 8),(int *)(param_1 + 6));
    iVar1 = 0;
  }
  return iVar1;
}



/* c04f4400 FUN_c04f4400 */

/* Boundary evidence: original MIPS .pdata c04f4400..c04f4497. Semantic name remains unreviewed. */

int FUN_c04f4400(undefined2 *param_1,int *param_2,undefined2 *param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_c04f3e40(param_1,param_2,param_3);
  if (iVar1 == 0) {
    *(undefined4 *)(param_1 + 6) = *(undefined4 *)(param_3 + 6);
    iVar1 = *(int *)(param_3 + 8);
    if (iVar1 == 0) {
      uVar2 = 0;
    }
    else {
      uVar2 = *(undefined4 *)(param_3 + 10);
    }
    *(int *)(param_1 + 8) = iVar1;
    *(undefined4 *)(param_1 + 10) = uVar2;
    FUN_c04f23b0(param_2,iVar1,*(int *)(param_3 + 10),(int *)(param_1 + 8));
    iVar1 = 0;
  }
  return iVar1;
}



/* c04f4498 FUN_c04f4498 */

/* Boundary evidence: original MIPS .pdata c04f4498..c04f44f3. Semantic name remains unreviewed. */

int FUN_c04f4498(undefined2 *param_1,int *param_2,undefined2 *param_3)

{
  int iVar1;
  
  iVar1 = FUN_c04f3e40(param_1,param_2,param_3);
  if (iVar1 == 0) {
    *(undefined4 *)(param_1 + 6) = *(undefined4 *)(param_3 + 6);
    iVar1 = 0;
    *(undefined4 *)(param_1 + 8) = *(undefined4 *)(param_3 + 8);
  }
  return iVar1;
}



/* c04f44f4 FUN_c04f44f4 */

/* Boundary evidence: original MIPS .pdata c04f44f4..c04f457b. Semantic name remains unreviewed. */

int FUN_c04f44f4(undefined2 *param_1,int *param_2,undefined2 *param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_c04f3e40(param_1,param_2,param_3);
  if (iVar1 == 0) {
    iVar1 = *(int *)(param_3 + 6);
    if (iVar1 == 0) {
      uVar2 = 0;
    }
    else {
      uVar2 = *(undefined4 *)(param_3 + 8);
    }
    *(int *)(param_1 + 6) = iVar1;
    *(undefined4 *)(param_1 + 8) = uVar2;
    FUN_c04f2844(param_2,iVar1,*(int *)(param_3 + 8),(int *)(param_1 + 6));
    iVar1 = 0;
  }
  return iVar1;
}



/* c04f457c FUN_c04f457c */

/* Boundary evidence: original MIPS .pdata c04f457c..c04f45ef. Semantic name remains unreviewed. */

int FUN_c04f457c(undefined2 *param_1,int *param_2,undefined2 *param_3)

{
  int iVar1;
  
  iVar1 = FUN_c04f3e40(param_1,param_2,param_3);
  if (iVar1 == 0) {
    iVar1 = *(int *)(param_3 + 6);
    *(int *)(param_1 + 6) = iVar1;
    if (iVar1 != 0) {
      FUN_c04f23b0(param_2,*(undefined4 *)(param_3 + 6),4,(int *)(param_1 + 6));
    }
    iVar1 = 0;
  }
  return iVar1;
}



/* c04f45f0 FUN_c04f45f0 */

/* Boundary evidence: original MIPS .pdata c04f45f0..c04f464b. Semantic name remains unreviewed. */

int FUN_c04f45f0(undefined2 *param_1,int *param_2,undefined2 *param_3)

{
  int iVar1;
  
  iVar1 = FUN_c04f3e40(param_1,param_2,param_3);
  if (iVar1 == 0) {
    *(undefined4 *)(param_1 + 6) = *(undefined4 *)(param_3 + 6);
    iVar1 = 0;
    *(undefined4 *)(param_1 + 8) = *(undefined4 *)(param_3 + 8);
  }
  return iVar1;
}



/* c04f464c FUN_c04f464c */

/* Boundary evidence: original MIPS .pdata c04f464c..c04f46a7. Semantic name remains unreviewed. */

int FUN_c04f464c(undefined2 *param_1,int *param_2,undefined2 *param_3)

{
  int iVar1;
  
  iVar1 = FUN_c04f3e40(param_1,param_2,param_3);
  if (iVar1 == 0) {
    *(undefined4 *)(param_1 + 6) = *(undefined4 *)(param_3 + 6);
    iVar1 = 0;
    param_1[8] = param_3[8];
  }
  return iVar1;
}



/* c04f46a8 FUN_c04f46a8 */

/* Boundary evidence: original MIPS .pdata c04f46a8..c04f473f. Semantic name remains unreviewed. */

int FUN_c04f46a8(undefined2 *param_1,int *param_2,undefined2 *param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_c04f3e40(param_1,param_2,param_3);
  if (iVar1 == 0) {
    *(undefined4 *)(param_1 + 6) = *(undefined4 *)(param_3 + 6);
    iVar1 = *(int *)(param_3 + 8);
    if (iVar1 == 0) {
      uVar2 = 0;
    }
    else {
      uVar2 = *(undefined4 *)(param_3 + 10);
    }
    *(int *)(param_1 + 8) = iVar1;
    *(undefined4 *)(param_1 + 10) = uVar2;
    FUN_c04f27c4(param_2,iVar1,*(int *)(param_3 + 10),(int *)(param_1 + 8));
    iVar1 = 0;
  }
  return iVar1;
}



/* c04f4740 FUN_c04f4740 */

/* Boundary evidence: original MIPS .pdata c04f4740..c04f47d7. Semantic name remains unreviewed. */

int FUN_c04f4740(undefined2 *param_1,int *param_2,undefined2 *param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_c04f3e40(param_1,param_2,param_3);
  if (iVar1 == 0) {
    *(undefined4 *)(param_1 + 6) = *(undefined4 *)(param_3 + 6);
    iVar1 = *(int *)(param_3 + 8);
    if (iVar1 == 0) {
      uVar2 = 0;
    }
    else {
      uVar2 = *(undefined4 *)(param_3 + 10);
    }
    *(int *)(param_1 + 8) = iVar1;
    *(undefined4 *)(param_1 + 10) = uVar2;
    FUN_c04f27c4(param_2,iVar1,*(int *)(param_3 + 10),(int *)(param_1 + 8));
    iVar1 = 0;
  }
  return iVar1;
}



/* c04f47d8 FUN_c04f47d8 */

/* Boundary evidence: original MIPS .pdata c04f47d8..c04f486f. Semantic name remains unreviewed. */

int FUN_c04f47d8(int param_1,undefined4 *param_2,int param_3)

{
  int iVar1;
  int *piVar2;
  size_t sVar3;
  int aiStack_18 [2];
  
  iVar1 = FUN_c04f2a20(param_1,param_2,param_3);
  if (iVar1 == 0) {
    piVar2 = FUN_c04f1c5c((undefined4 *)(param_3 + 0x18),aiStack_18,param_2);
    if ((void *)*piVar2 == (void *)0x0) {
      sVar3 = 0;
    }
    else {
      sVar3 = piVar2[1];
    }
    if (*(size_t *)(param_1 + 0x1c) == sVar3) {
      memcpy(*(void **)(param_1 + 0x18),(void *)*piVar2,*(size_t *)(param_1 + 0x1c));
      iVar1 = 0;
    }
    else {
      iVar1 = 0x57;
    }
  }
  return iVar1;
}



/* c04f4870 FUN_c04f4870 */

/* Boundary evidence: original MIPS .pdata c04f4870..c04f48d3. Semantic name remains unreviewed. */

int FUN_c04f4870(undefined2 *param_1,int *param_2,undefined2 *param_3)

{
  int iVar1;
  
  iVar1 = FUN_c04f3e40(param_1,param_2,param_3);
  if (iVar1 == 0) {
    FUN_c04f2600((int *)(param_1 + 6),param_2,(int *)(param_3 + 6));
    iVar1 = 0;
  }
  return iVar1;
}



/* c04f48d4 FUN_c04f48d4 */

/* Boundary evidence: original MIPS .pdata c04f48d4..c04f4927. Semantic name remains unreviewed. */

int FUN_c04f48d4(int param_1,undefined4 *param_2,int param_3)

{
  int iVar1;
  int aiStack_18 [2];
  
  iVar1 = FUN_c04f3334(param_1,param_2,param_3);
  if (iVar1 == 0) {
    FUN_c04f1c5c((undefined4 *)(param_3 + 0x18),aiStack_18,param_2);
    iVar1 = 0;
  }
  return iVar1;
}



/* c04f4928 FUN_c04f4928 */

/* Boundary evidence: original MIPS .pdata c04f4928..c04f499b. Semantic name remains unreviewed. */

int FUN_c04f4928(undefined2 *param_1,int *param_2,undefined2 *param_3)

{
  int iVar1;
  
  iVar1 = FUN_c04f3e40(param_1,param_2,param_3);
  if (iVar1 == 0) {
    iVar1 = *(int *)(param_3 + 6);
    *(int *)(param_1 + 6) = iVar1;
    if (iVar1 != 0) {
      FUN_c04f2260(param_2,*(undefined4 *)(param_3 + 6),4,(int *)(param_1 + 6));
    }
    iVar1 = 0;
  }
  return iVar1;
}



/* c04f499c FUN_c04f499c */

/* Boundary evidence: original MIPS .pdata c04f499c..c04f49ff. Semantic name remains unreviewed. */

int FUN_c04f499c(undefined2 *param_1,int *param_2,undefined2 *param_3)

{
  int iVar1;
  
  iVar1 = FUN_c04f3e40(param_1,param_2,param_3);
  if (iVar1 == 0) {
    FUN_c04f2600((int *)(param_1 + 6),param_2,(int *)(param_3 + 6));
    iVar1 = 0;
  }
  return iVar1;
}



/* c04f4a00 FUN_c04f4a00 */

/* Boundary evidence: original MIPS .pdata c04f4a00..c04f4a87. Semantic name remains unreviewed. */

int FUN_c04f4a00(undefined2 *param_1,int *param_2,undefined2 *param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_c04f3e40(param_1,param_2,param_3);
  if (iVar1 == 0) {
    iVar1 = *(int *)(param_3 + 6);
    if (iVar1 == 0) {
      uVar2 = 0;
    }
    else {
      uVar2 = *(undefined4 *)(param_3 + 8);
    }
    *(int *)(param_1 + 6) = iVar1;
    *(undefined4 *)(param_1 + 8) = uVar2;
    FUN_c04f27c4(param_2,iVar1,*(int *)(param_3 + 8),(int *)(param_1 + 6));
    iVar1 = 0;
  }
  return iVar1;
}



/* c04f4a88 FUN_c04f4a88 */

/* Boundary evidence: original MIPS .pdata c04f4a88..c04f4adb. Semantic name remains unreviewed. */

int FUN_c04f4a88(int param_1,undefined4 *param_2,int param_3)

{
  int iVar1;
  int aiStack_18 [2];
  
  iVar1 = FUN_c04f2f08(param_1,param_2,param_3);
  if (iVar1 == 0) {
    FUN_c04f1c5c((undefined4 *)(param_3 + 0x18),aiStack_18,param_2);
    iVar1 = 0;
  }
  return iVar1;
}



/* c04f4adc FUN_c04f4adc */

/* Boundary evidence: original MIPS .pdata c04f4adc..c04f4b3f. Semantic name remains unreviewed. */

int FUN_c04f4adc(undefined2 *param_1,int *param_2,undefined2 *param_3)

{
  int iVar1;
  
  iVar1 = FUN_c04f4314(param_1,param_2,param_3);
  if (iVar1 == 0) {
    FUN_c04f30c8((int *)(param_1 + 8),param_2,(int *)(param_3 + 8));
    iVar1 = 0;
  }
  return iVar1;
}



/* c04f4b40 FUN_c04f4b40 */

/* Boundary evidence: original MIPS .pdata c04f4b40..c04f4ba7. Semantic name remains unreviewed. */

int FUN_c04f4b40(int param_1,undefined4 *param_2,int param_3)

{
  int iVar1;
  
  iVar1 = FUN_c04f2cac(param_1,param_2,param_3);
  if (iVar1 == 0) {
    FUN_c04f3130((int *)(param_3 + 0xc),param_2);
    FUN_c04f3130((int *)(param_3 + 0x10),param_2);
    iVar1 = 0;
  }
  return iVar1;
}



/* c04f4ba8 FUN_c04f4ba8 */

/* Boundary evidence: original MIPS .pdata c04f4ba8..c04f4c2f. Semantic name remains unreviewed. */

int FUN_c04f4ba8(undefined2 *param_1,int *param_2,undefined2 *param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_c04f3e40(param_1,param_2,param_3);
  if (iVar1 == 0) {
    iVar1 = *(int *)(param_3 + 6);
    if (iVar1 == 0) {
      uVar2 = 0;
    }
    else {
      uVar2 = *(undefined4 *)(param_3 + 8);
    }
    *(int *)(param_1 + 6) = iVar1;
    *(undefined4 *)(param_1 + 8) = uVar2;
    FUN_c04f23b0(param_2,iVar1,*(int *)(param_3 + 8),(int *)(param_1 + 6));
    iVar1 = 0;
  }
  return iVar1;
}



/* c04f4c30 FUN_c04f4c30 */

/* Boundary evidence: original MIPS .pdata c04f4c30..c04f4c83. Semantic name remains unreviewed. */

int FUN_c04f4c30(int param_1,undefined4 *param_2,int param_3)

{
  int iVar1;
  int aiStack_18 [2];
  
  iVar1 = FUN_c04f2f08(param_1,param_2,param_3);
  if (iVar1 == 0) {
    FUN_c04f1c5c((undefined4 *)(param_3 + 0x18),aiStack_18,param_2);
    iVar1 = 0;
  }
  return iVar1;
}



/* c04f4c84 FUN_c04f4c84 */

/* Boundary evidence: original MIPS .pdata c04f4c84..c04f4d0b. Semantic name remains unreviewed. */

int FUN_c04f4c84(int param_1,undefined4 *param_2,int param_3)

{
  int iVar1;
  void *local_18;
  size_t local_14;
  
  iVar1 = FUN_c04f3d64(param_1,param_2,param_3);
  if (iVar1 == 0) {
    FUN_c04f1d10((undefined4 *)(param_3 + 0x28),(int *)&local_18,param_2);
    if (*(size_t *)(param_1 + 0x2c) == local_14) {
      memcpy(*(void **)(param_1 + 0x28),local_18,*(size_t *)(param_1 + 0x2c));
      iVar1 = 0;
    }
    else {
      iVar1 = 0x57;
    }
  }
  return iVar1;
}



/* c04f4d0c FUN_c04f4d0c */

/* Boundary evidence: original MIPS .pdata c04f4d0c..c04f4d5f. Semantic name remains unreviewed. */

int FUN_c04f4d0c(int param_1,undefined4 *param_2,int param_3)

{
  int iVar1;
  int aiStack_18 [2];
  
  iVar1 = FUN_c04f3dec(param_1,param_2,param_3);
  if (iVar1 == 0) {
    FUN_c04f1d10((undefined4 *)(param_3 + 0x28),aiStack_18,param_2);
    iVar1 = 0;
  }
  return iVar1;
}



/* c04f4d60 FUN_c04f4d60 */

/* Boundary evidence: original MIPS .pdata c04f4d60..c04f4dc3. Semantic name remains unreviewed. */

int FUN_c04f4d60(undefined2 *param_1,int *param_2,undefined2 *param_3)

{
  int iVar1;
  
  iVar1 = FUN_c04f3e40(param_1,param_2,param_3);
  if (iVar1 == 0) {
    FUN_c04f3388((int *)(param_1 + 6),param_2,(int *)(param_3 + 6));
    iVar1 = 0;
  }
  return iVar1;
}



/* c04f4dc4 FUN_c04f4dc4 */

/* Boundary evidence: original MIPS .pdata c04f4dc4..c04f4e4b. Semantic name remains unreviewed. */

int FUN_c04f4dc4(undefined2 *param_1,int *param_2,undefined2 *param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_c04f46a8(param_1,param_2,param_3);
  if (iVar1 == 0) {
    iVar1 = *(int *)(param_3 + 0xc);
    if (iVar1 == 0) {
      uVar2 = 0;
    }
    else {
      uVar2 = *(undefined4 *)(param_3 + 0xe);
    }
    *(int *)(param_1 + 0xc) = iVar1;
    *(undefined4 *)(param_1 + 0xe) = uVar2;
    FUN_c04f27c4(param_2,iVar1,*(int *)(param_3 + 0xe),(int *)(param_1 + 0xc));
    iVar1 = 0;
  }
  return iVar1;
}



/* c04f4e4c FUN_c04f4e4c */

/* Boundary evidence: original MIPS .pdata c04f4e4c..c04f4ed3. Semantic name remains unreviewed. */

int FUN_c04f4e4c(undefined2 *param_1,int *param_2,undefined2 *param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_c04f4740(param_1,param_2,param_3);
  if (iVar1 == 0) {
    iVar1 = *(int *)(param_3 + 0xc);
    if (iVar1 == 0) {
      uVar2 = 0;
    }
    else {
      uVar2 = *(undefined4 *)(param_3 + 0xe);
    }
    *(int *)(param_1 + 0xc) = iVar1;
    *(undefined4 *)(param_1 + 0xe) = uVar2;
    FUN_c04f27c4(param_2,iVar1,*(int *)(param_3 + 0xe),(int *)(param_1 + 0xc));
    iVar1 = 0;
  }
  return iVar1;
}



/* c04f4ed4 FUN_c04f4ed4 */

/* Boundary evidence: original MIPS .pdata c04f4ed4..c04f4f6f. Semantic name remains unreviewed. */

int FUN_c04f4ed4(undefined4 param_1,undefined2 *param_2,undefined4 *param_3)

{
  int iVar1;
  undefined **local_28;
  undefined4 local_24;
  undefined2 auStack_20 [6];
  uint local_14;
  
  local_14 = DAT_c04ff0b4;
  local_24 = 0;
  local_28 = &PTR_LAB_c04f1054;
  FUN_c04f10a4((int *)&local_28,0xc,(int *)0x0);
  iVar1 = FUN_c04f3e40(auStack_20,(int *)&local_28,param_2);
  if (iVar1 == 0) {
    *param_3 = local_24;
    FUN_c04fe38c(local_14);
    iVar1 = 0;
  }
  else {
    FUN_c04fe38c(local_14);
  }
  return iVar1;
}



/* c04f4f70 FUN_c04f4f70 */

/* Boundary evidence: original MIPS .pdata c04f4f70..c04f500b. Semantic name remains unreviewed. */

int FUN_c04f4f70(undefined4 param_1,undefined2 *param_2,undefined4 *param_3)

{
  int iVar1;
  undefined **local_30;
  undefined4 local_2c;
  undefined2 auStack_28 [8];
  uint local_18;
  
  local_18 = DAT_c04ff0b4;
  local_2c = 0;
  local_30 = &PTR_LAB_c04f1054;
  FUN_c04f10a4((int *)&local_30,0x10,(int *)0x0);
  iVar1 = FUN_c04f3e40(auStack_28,(int *)&local_30,param_2);
  if (iVar1 == 0) {
    *param_3 = local_2c;
    FUN_c04fe38c(local_18);
    iVar1 = 0;
  }
  else {
    FUN_c04fe38c(local_18);
  }
  return iVar1;
}



/* c04f500c FUN_c04f500c */

/* Boundary evidence: original MIPS .pdata c04f500c..c04f50a7. Semantic name remains unreviewed. */

int FUN_c04f500c(undefined4 param_1,undefined2 *param_2,undefined4 *param_3)

{
  int iVar1;
  undefined **local_30;
  undefined4 local_2c;
  undefined2 auStack_28 [10];
  uint local_14;
  
  local_14 = DAT_c04ff0b4;
  local_2c = 0;
  local_30 = &PTR_LAB_c04f1054;
  FUN_c04f10a4((int *)&local_30,0x14,(int *)0x0);
  iVar1 = FUN_c04f3f54(auStack_28,(int *)&local_30,param_2);
  if (iVar1 == 0) {
    *param_3 = local_2c;
    FUN_c04fe38c(local_14);
    iVar1 = 0;
  }
  else {
    FUN_c04fe38c(local_14);
  }
  return iVar1;
}



/* c04f50a8 FUN_c04f50a8 */

/* Boundary evidence: original MIPS .pdata c04f50a8..c04f512f. Semantic name remains unreviewed. */

undefined4 * FUN_c04f50a8(uint param_1)

{
  undefined4 *puVar1;
  
  puVar1 = operator_new(0x10);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    puVar1 = FUN_c04f296c(puVar1,param_1);
  }
  if (puVar1[2] == 0) {
    if ((void *)puVar1[2] != (void *)0x0) {
      operator_delete((void *)puVar1[2]);
    }
    operator_delete(puVar1);
    puVar1 = (undefined4 *)0x0;
  }
  return puVar1;
}



/* c04f5130 FUN_c04f5130 */

/* Boundary evidence: original MIPS .pdata c04f5130..c04f5237. Semantic name remains unreviewed. */

int FUN_c04f5130(undefined4 *param_1,undefined2 *param_2)

{
  int iVar1;
  int *piVar2;
  undefined2 *puVar3;
  uint local_28 [2];
  
  iVar1 = FUN_c04f4ed4(param_1,param_2,local_28);
  if (iVar1 == 0) {
    piVar2 = FUN_c04f50a8(local_28[0]);
    if (piVar2 == (int *)0x0) {
      iVar1 = 0xe;
    }
    else {
      FUN_c04f10a4(piVar2,0xc,(int *)0x0);
      puVar3 = (undefined2 *)piVar2[2];
      iVar1 = FUN_c04f3e40(puVar3,piVar2,param_2);
      if (iVar1 == 0) {
        iVar1 = (**(code **)*param_1)(param_1,puVar3,local_28[0]);
        FUN_c04f2cac((int)param_2,piVar2,(int)puVar3);
      }
      if ((void *)piVar2[2] != (void *)0x0) {
        operator_delete((void *)piVar2[2]);
      }
      operator_delete(piVar2);
    }
  }
  else {
    iVar1 = 0x57;
  }
  return iVar1;
}



/* c04f5238 FUN_c04f5238 */

/* Boundary evidence: original MIPS .pdata c04f5238..c04f534f. Semantic name remains unreviewed. */

int FUN_c04f5238(undefined4 *param_1,undefined2 *param_2)

{
  int iVar1;
  int *piVar2;
  undefined2 *puVar3;
  uint local_28 [2];
  
  iVar1 = FUN_c04f4f70(param_1,param_2,local_28);
  if (iVar1 == 0) {
    piVar2 = FUN_c04f50a8(local_28[0]);
    if (piVar2 == (int *)0x0) {
      iVar1 = 0xe;
    }
    else {
      FUN_c04f10a4(piVar2,0x10,(int *)0x0);
      puVar3 = (undefined2 *)piVar2[2];
      iVar1 = FUN_c04f3e40(puVar3,piVar2,param_2);
      if (iVar1 == 0) {
        *(undefined4 *)(puVar3 + 6) = *(undefined4 *)(param_2 + 6);
        iVar1 = (**(code **)*param_1)(param_1,puVar3,local_28[0]);
        FUN_c04f2cac((int)param_2,piVar2,(int)puVar3);
      }
      if ((void *)piVar2[2] != (void *)0x0) {
        operator_delete((void *)piVar2[2]);
      }
      operator_delete(piVar2);
    }
  }
  else {
    iVar1 = 0x57;
  }
  return iVar1;
}



/* c04f5350 FUN_c04f5350 */

/* Boundary evidence: original MIPS .pdata c04f5350..c04f5457. Semantic name remains unreviewed. */

int FUN_c04f5350(undefined4 *param_1,undefined2 *param_2)

{
  int iVar1;
  int *piVar2;
  undefined2 *puVar3;
  uint local_28 [2];
  
  iVar1 = FUN_c04f500c(param_1,param_2,local_28);
  if (iVar1 == 0) {
    piVar2 = FUN_c04f50a8(local_28[0]);
    if (piVar2 == (int *)0x0) {
      iVar1 = 0xe;
    }
    else {
      FUN_c04f10a4(piVar2,0x14,(int *)0x0);
      puVar3 = (undefined2 *)piVar2[2];
      iVar1 = FUN_c04f3f54(puVar3,piVar2,param_2);
      if (iVar1 == 0) {
        iVar1 = (**(code **)*param_1)(param_1,puVar3,local_28[0]);
        FUN_c04f2cac((int)param_2,piVar2,(int)puVar3);
      }
      if ((void *)piVar2[2] != (void *)0x0) {
        operator_delete((void *)piVar2[2]);
      }
      operator_delete(piVar2);
    }
  }
  else {
    iVar1 = 0x57;
  }
  return iVar1;
}



/* c04f5458 FUN_c04f5458 */

/* Boundary evidence: original MIPS .pdata c04f5458..c04f54ef. Semantic name remains unreviewed. */

int FUN_c04f5458(undefined2 *param_1,int *param_2,undefined2 *param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_c04f3e40(param_1,param_2,param_3);
  if (iVar1 == 0) {
    param_1[6] = param_3[6];
    iVar1 = *(int *)(param_3 + 8);
    if (iVar1 == 0) {
      uVar2 = 0;
    }
    else {
      uVar2 = *(undefined4 *)(param_3 + 10);
    }
    *(int *)(param_1 + 8) = iVar1;
    *(undefined4 *)(param_1 + 10) = uVar2;
    FUN_c04f23b0(param_2,iVar1,*(int *)(param_3 + 10),(int *)(param_1 + 8));
    iVar1 = 0;
  }
  return iVar1;
}



/* c04f54f0 FUN_c04f54f0 */

/* Boundary evidence: original MIPS .pdata c04f54f0..c04f557f. Semantic name remains unreviewed. */

int FUN_c04f54f0(int param_1,undefined4 *param_2,int param_3)

{
  int iVar1;
  undefined4 *puVar2;
  
  iVar1 = FUN_c04f41bc(param_1,param_2,param_3);
  if (iVar1 == 0) {
    if (*(int *)(param_3 + 0x28) == 0) {
      puVar2 = (undefined4 *)0x0;
    }
    else {
      puVar2 = (undefined4 *)(**(code **)*param_2)(param_2,*(int *)(param_3 + 0x28),4);
    }
    if (*(undefined4 **)(param_1 + 0x28) != (undefined4 *)0x0) {
      **(undefined4 **)(param_1 + 0x28) = *puVar2;
    }
    iVar1 = 0;
  }
  return iVar1;
}



/* c04f5580 FUN_c04f5580 */

/* Boundary evidence: original MIPS .pdata c04f5580..c04f55e3. Semantic name remains unreviewed. */

int FUN_c04f5580(int param_1,undefined4 *param_2,int param_3)

{
  int iVar1;
  
  iVar1 = FUN_c04f4254(param_1,param_2,param_3);
  if (iVar1 == 0) {
    if (*(int *)(param_3 + 0x24) != 0) {
      (**(code **)*param_2)(param_2,*(int *)(param_3 + 0x24),8);
    }
    iVar1 = 0;
  }
  return iVar1;
}



/* c04f55e4 FUN_c04f55e4 */

/* Boundary evidence: original MIPS .pdata c04f55e4..c04f567b. Semantic name remains unreviewed. */

int FUN_c04f55e4(int param_1,undefined4 *param_2,int param_3)

{
  int iVar1;
  int *piVar2;
  size_t sVar3;
  int aiStack_18 [2];
  
  iVar1 = FUN_c04f32e0(param_1,param_2,param_3);
  if (iVar1 == 0) {
    piVar2 = FUN_c04f1c5c((undefined4 *)(param_3 + 0x1c),aiStack_18,param_2);
    if ((void *)*piVar2 == (void *)0x0) {
      sVar3 = 0;
    }
    else {
      sVar3 = piVar2[1];
    }
    if (*(size_t *)(param_1 + 0x20) == sVar3) {
      memcpy(*(void **)(param_1 + 0x1c),(void *)*piVar2,*(size_t *)(param_1 + 0x20));
      iVar1 = 0;
    }
    else {
      iVar1 = 0x57;
    }
  }
  return iVar1;
}



/* c04f567c FUN_c04f567c */

/* Boundary evidence: original MIPS .pdata c04f567c..c04f5703. Semantic name remains unreviewed. */

int FUN_c04f567c(undefined2 *param_1,int *param_2,undefined2 *param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_c04f4314(param_1,param_2,param_3);
  if (iVar1 == 0) {
    iVar1 = *(int *)(param_3 + 8);
    if (iVar1 == 0) {
      uVar2 = 0;
    }
    else {
      uVar2 = *(undefined4 *)(param_3 + 10);
    }
    *(int *)(param_1 + 8) = iVar1;
    *(undefined4 *)(param_1 + 10) = uVar2;
    FUN_c04f23b0(param_2,iVar1,*(int *)(param_3 + 10),(int *)(param_1 + 8));
    iVar1 = 0;
  }
  return iVar1;
}



/* c04f5704 FUN_c04f5704 */

/* Boundary evidence: original MIPS .pdata c04f5704..c04f57b3. Semantic name remains unreviewed. */

int FUN_c04f5704(int param_1,undefined4 *param_2,int param_3)

{
  int iVar1;
  int *piVar2;
  size_t sVar3;
  int aiStack_18 [2];
  
  iVar1 = FUN_c04f2cac(param_1,param_2,param_3);
  if (iVar1 == 0) {
    FUN_c04f3130((int *)(param_3 + 0xc),param_2);
    piVar2 = FUN_c04f1c5c((undefined4 *)(param_3 + 0x10),aiStack_18,param_2);
    if ((void *)*piVar2 == (void *)0x0) {
      sVar3 = 0;
    }
    else {
      sVar3 = piVar2[1];
    }
    if (*(size_t *)(param_1 + 0x14) == sVar3) {
      memcpy(*(void **)(param_1 + 0x10),(void *)*piVar2,*(size_t *)(param_1 + 0x14));
      iVar1 = 0;
    }
    else {
      iVar1 = 0x57;
    }
  }
  return iVar1;
}



/* c04f57b4 FUN_c04f57b4 */

/* Boundary evidence: original MIPS .pdata c04f57b4..c04f5827. Semantic name remains unreviewed. */

int FUN_c04f57b4(undefined2 *param_1,int *param_2,undefined2 *param_3)

{
  int iVar1;
  
  iVar1 = FUN_c04f4400(param_1,param_2,param_3);
  if (iVar1 == 0) {
    iVar1 = *(int *)(param_3 + 0xc);
    *(int *)(param_1 + 0xc) = iVar1;
    if (iVar1 != 0) {
      FUN_c04f2260(param_2,*(undefined4 *)(param_3 + 0xc),4,(int *)(param_1 + 0xc));
    }
    iVar1 = 0;
  }
  return iVar1;
}



/* c04f5828 FUN_c04f5828 */

/* Boundary evidence: original MIPS .pdata c04f5828..c04f589b. Semantic name remains unreviewed. */

int FUN_c04f5828(undefined2 *param_1,int *param_2,undefined2 *param_3)

{
  int iVar1;
  
  iVar1 = FUN_c04f4498(param_1,param_2,param_3);
  if (iVar1 == 0) {
    iVar1 = *(int *)(param_3 + 10);
    *(int *)(param_1 + 10) = iVar1;
    if (iVar1 != 0) {
      FUN_c04f23b0(param_2,*(undefined4 *)(param_3 + 10),4,(int *)(param_1 + 10));
    }
    iVar1 = 0;
  }
  return iVar1;
}



/* c04f589c FUN_c04f589c */

/* Boundary evidence: original MIPS .pdata c04f589c..c04f5923. Semantic name remains unreviewed. */

int FUN_c04f589c(undefined2 *param_1,int *param_2,undefined2 *param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_c04f457c(param_1,param_2,param_3);
  if (iVar1 == 0) {
    iVar1 = *(int *)(param_3 + 8);
    if (iVar1 == 0) {
      uVar2 = 0;
    }
    else {
      uVar2 = *(undefined4 *)(param_3 + 10);
    }
    *(int *)(param_1 + 8) = iVar1;
    *(undefined4 *)(param_1 + 10) = uVar2;
    FUN_c04f23b0(param_2,iVar1,*(int *)(param_3 + 10),(int *)(param_1 + 8));
    iVar1 = 0;
  }
  return iVar1;
}



/* c04f5924 FUN_c04f5924 */

/* Boundary evidence: original MIPS .pdata c04f5924..c04f59bb. Semantic name remains unreviewed. */

int FUN_c04f5924(undefined2 *param_1,int *param_2,undefined2 *param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_c04f3f54(param_1,param_2,param_3);
  if (iVar1 == 0) {
    *(undefined4 *)(param_1 + 10) = *(undefined4 *)(param_3 + 10);
    iVar1 = *(int *)(param_3 + 0xc);
    if (iVar1 == 0) {
      uVar2 = 0;
    }
    else {
      uVar2 = *(undefined4 *)(param_3 + 0xe);
    }
    *(int *)(param_1 + 0xc) = iVar1;
    *(undefined4 *)(param_1 + 0xe) = uVar2;
    FUN_c04f23b0(param_2,iVar1,*(int *)(param_3 + 0xe),(int *)(param_1 + 0xc));
    iVar1 = 0;
  }
  return iVar1;
}



/* c04f59bc FUN_c04f59bc */

/* Boundary evidence: original MIPS .pdata c04f59bc..c04f5a17. Semantic name remains unreviewed. */

int FUN_c04f59bc(undefined2 *param_1,int *param_2,undefined2 *param_3)

{
  int iVar1;
  
  iVar1 = FUN_c04f3f54(param_1,param_2,param_3);
  if (iVar1 == 0) {
    *(undefined4 *)(param_1 + 10) = *(undefined4 *)(param_3 + 10);
    iVar1 = 0;
    *(undefined4 *)(param_1 + 0xc) = *(undefined4 *)(param_3 + 0xc);
  }
  return iVar1;
}



/* c04f5a18 FUN_c04f5a18 */

/* Boundary evidence: original MIPS .pdata c04f5a18..c04f5a8b. Semantic name remains unreviewed. */

int FUN_c04f5a18(undefined2 *param_1,int *param_2,undefined2 *param_3)

{
  int iVar1;
  
  iVar1 = FUN_c04f45f0(param_1,param_2,param_3);
  if (iVar1 == 0) {
    iVar1 = *(int *)(param_3 + 10);
    *(int *)(param_1 + 10) = iVar1;
    if (iVar1 != 0) {
      FUN_c04f23b0(param_2,*(undefined4 *)(param_3 + 10),4,(int *)(param_1 + 10));
    }
    iVar1 = 0;
  }
  return iVar1;
}



/* c04f5a8c FUN_c04f5a8c */

/* Boundary evidence: original MIPS .pdata c04f5a8c..c04f5aff. Semantic name remains unreviewed. */

int FUN_c04f5a8c(undefined2 *param_1,int *param_2,undefined2 *param_3)

{
  int iVar1;
  
  iVar1 = FUN_c04f464c(param_1,param_2,param_3);
  if (iVar1 == 0) {
    iVar1 = *(int *)(param_3 + 10);
    *(int *)(param_1 + 10) = iVar1;
    if (iVar1 != 0) {
      FUN_c04f2458(param_2,*(undefined4 *)(param_3 + 10),2,(int *)(param_1 + 10));
    }
    iVar1 = 0;
  }
  return iVar1;
}



/* c04f5b00 FUN_c04f5b00 */

/* Boundary evidence: original MIPS .pdata c04f5b00..c04f5b5b. Semantic name remains unreviewed. */

int FUN_c04f5b00(undefined2 *param_1,int *param_2,undefined2 *param_3)

{
  int iVar1;
  
  iVar1 = FUN_c04f3c58(param_1,param_2,param_3);
  if (iVar1 == 0) {
    *(undefined4 *)(param_1 + 6) = *(undefined4 *)(param_3 + 6);
    iVar1 = 0;
    *(undefined4 *)(param_1 + 8) = *(undefined4 *)(param_3 + 8);
  }
  return iVar1;
}



/* c04f5b5c FUN_c04f5b5c */

/* Boundary evidence: original MIPS .pdata c04f5b5c..c04f5bf3. Semantic name remains unreviewed. */

int FUN_c04f5b5c(undefined2 *param_1,int *param_2,undefined2 *param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_c04f3c58(param_1,param_2,param_3);
  if (iVar1 == 0) {
    *(undefined4 *)(param_1 + 6) = *(undefined4 *)(param_3 + 6);
    iVar1 = *(int *)(param_3 + 8);
    if (iVar1 == 0) {
      uVar2 = 0;
    }
    else {
      uVar2 = *(undefined4 *)(param_3 + 10);
    }
    *(int *)(param_1 + 8) = iVar1;
    *(undefined4 *)(param_1 + 10) = uVar2;
    FUN_c04f23b0(param_2,iVar1,*(int *)(param_3 + 10),(int *)(param_1 + 8));
    iVar1 = 0;
  }
  return iVar1;
}



/* c04f5bf4 FUN_c04f5bf4 */

/* Boundary evidence: original MIPS .pdata c04f5bf4..c04f5c8b. Semantic name remains unreviewed. */

int FUN_c04f5bf4(undefined2 *param_1,int *param_2,undefined2 *param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_c04f3f54(param_1,param_2,param_3);
  if (iVar1 == 0) {
    *(undefined4 *)(param_1 + 10) = *(undefined4 *)(param_3 + 10);
    iVar1 = *(int *)(param_3 + 0xc);
    if (iVar1 == 0) {
      uVar2 = 0;
    }
    else {
      uVar2 = *(undefined4 *)(param_3 + 0xe);
    }
    *(int *)(param_1 + 0xc) = iVar1;
    *(undefined4 *)(param_1 + 0xe) = uVar2;
    FUN_c04f27c4(param_2,iVar1,*(int *)(param_3 + 0xe),(int *)(param_1 + 0xc));
    iVar1 = 0;
  }
  return iVar1;
}



/* c04f5c8c FUN_c04f5c8c */

/* Boundary evidence: original MIPS .pdata c04f5c8c..c04f5d23. Semantic name remains unreviewed. */

int FUN_c04f5c8c(undefined2 *param_1,int *param_2,undefined2 *param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_c04f3f54(param_1,param_2,param_3);
  if (iVar1 == 0) {
    *(undefined4 *)(param_1 + 10) = *(undefined4 *)(param_3 + 10);
    iVar1 = *(int *)(param_3 + 0xc);
    if (iVar1 == 0) {
      uVar2 = 0;
    }
    else {
      uVar2 = *(undefined4 *)(param_3 + 0xe);
    }
    *(int *)(param_1 + 0xc) = iVar1;
    *(undefined4 *)(param_1 + 0xe) = uVar2;
    FUN_c04f27c4(param_2,iVar1,*(int *)(param_3 + 0xe),(int *)(param_1 + 0xc));
    iVar1 = 0;
  }
  return iVar1;
}



/* c04f5d24 FUN_c04f5d24 */

/* Boundary evidence: original MIPS .pdata c04f5d24..c04f5dab. Semantic name remains unreviewed. */

int FUN_c04f5d24(undefined2 *param_1,int *param_2,undefined2 *param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_c04f4870(param_1,param_2,param_3);
  if (iVar1 == 0) {
    iVar1 = *(int *)(param_3 + 10);
    if (iVar1 == 0) {
      uVar2 = 0;
    }
    else {
      uVar2 = *(undefined4 *)(param_3 + 0xc);
    }
    *(int *)(param_1 + 10) = iVar1;
    *(undefined4 *)(param_1 + 0xc) = uVar2;
    FUN_c04f23b0(param_2,iVar1,*(int *)(param_3 + 0xc),(int *)(param_1 + 10));
    iVar1 = 0;
  }
  return iVar1;
}



/* c04f5dac FUN_c04f5dac */

/* Boundary evidence: original MIPS .pdata c04f5dac..c04f5e17. Semantic name remains unreviewed. */

void FUN_c04f5dac(int param_1,undefined4 *param_2,int param_3)

{
  int iVar1;
  int aiStack_18 [2];
  
  iVar1 = FUN_c04f48d4(param_1,param_2,param_3);
  if (iVar1 == 0) {
    FUN_c04f1fa4((undefined4 *)(param_3 + 0x20),aiStack_18,param_2);
    FUN_c04f2068((undefined4 *)(param_1 + 0x20),aiStack_18);
  }
  return;
}



/* c04f5e18 FUN_c04f5e18 */

/* Boundary evidence: original MIPS .pdata c04f5e18..c04f5e7b. Semantic name remains unreviewed. */

int FUN_c04f5e18(undefined2 *param_1,int *param_2,undefined2 *param_3)

{
  int iVar1;
  
  iVar1 = FUN_c04f499c(param_1,param_2,param_3);
  if (iVar1 == 0) {
    FUN_c04f2600((int *)(param_1 + 10),param_2,(int *)(param_3 + 10));
    iVar1 = 0;
  }
  return iVar1;
}



/* c04f5e7c FUN_c04f5e7c */

/* Boundary evidence: original MIPS .pdata c04f5e7c..c04f5f03. Semantic name remains unreviewed. */

int FUN_c04f5e7c(int param_1,undefined4 *param_2,int param_3)

{
  int iVar1;
  void *local_18;
  size_t local_14;
  
  iVar1 = FUN_c04f3cdc(param_1,param_2,param_3);
  if (iVar1 == 0) {
    FUN_c04f1d10((undefined4 *)(param_3 + 0x24),(int *)&local_18,param_2);
    if (*(size_t *)(param_1 + 0x28) == local_14) {
      memcpy(*(void **)(param_1 + 0x24),local_18,*(size_t *)(param_1 + 0x28));
      iVar1 = 0;
    }
    else {
      iVar1 = 0x57;
    }
  }
  return iVar1;
}



/* c04f5f04 FUN_c04f5f04 */

/* Boundary evidence: original MIPS .pdata c04f5f04..c04f5f93. Semantic name remains unreviewed. */

int FUN_c04f5f04(int param_1,undefined4 *param_2,int param_3)

{
  int iVar1;
  undefined4 *puVar2;
  
  iVar1 = FUN_c04f4a88(param_1,param_2,param_3);
  if (iVar1 == 0) {
    if (*(int *)(param_3 + 0x20) == 0) {
      puVar2 = (undefined4 *)0x0;
    }
    else {
      puVar2 = (undefined4 *)(**(code **)*param_2)(param_2,*(int *)(param_3 + 0x20),4);
    }
    if (*(undefined4 **)(param_1 + 0x20) != (undefined4 *)0x0) {
      **(undefined4 **)(param_1 + 0x20) = *puVar2;
    }
    iVar1 = 0;
  }
  return iVar1;
}



/* c04f5f94 FUN_c04f5f94 */

/* Boundary evidence: original MIPS .pdata c04f5f94..c04f601b. Semantic name remains unreviewed. */

int FUN_c04f5f94(undefined2 *param_1,int *param_2,undefined2 *param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_c04f4adc(param_1,param_2,param_3);
  if (iVar1 == 0) {
    iVar1 = *(int *)(param_3 + 10);
    if (iVar1 == 0) {
      uVar2 = 0;
    }
    else {
      uVar2 = *(undefined4 *)(param_3 + 0xc);
    }
    *(int *)(param_1 + 10) = iVar1;
    *(undefined4 *)(param_1 + 0xc) = uVar2;
    FUN_c04f23b0(param_2,iVar1,*(int *)(param_3 + 0xc),(int *)(param_1 + 10));
    iVar1 = 0;
  }
  return iVar1;
}



/* c04f601c FUN_c04f601c */

/* Boundary evidence: original MIPS .pdata c04f601c..c04f606f. Semantic name remains unreviewed. */

int FUN_c04f601c(int param_1,undefined4 *param_2,int param_3)

{
  int iVar1;
  int aiStack_18 [2];
  
  iVar1 = FUN_c04f4b40(param_1,param_2,param_3);
  if (iVar1 == 0) {
    FUN_c04f1c5c((undefined4 *)(param_3 + 0x14),aiStack_18,param_2);
    iVar1 = 0;
  }
  return iVar1;
}



/* c04f6070 FUN_c04f6070 */

/* Boundary evidence: original MIPS .pdata c04f6070..c04f6107. Semantic name remains unreviewed. */

int FUN_c04f6070(int param_1,undefined4 *param_2,int param_3)

{
  int iVar1;
  int *piVar2;
  size_t sVar3;
  int aiStack_18 [2];
  
  iVar1 = FUN_c04f4c30(param_1,param_2,param_3);
  if (iVar1 == 0) {
    piVar2 = FUN_c04f1c5c((undefined4 *)(param_3 + 0x20),aiStack_18,param_2);
    if ((void *)*piVar2 == (void *)0x0) {
      sVar3 = 0;
    }
    else {
      sVar3 = piVar2[1];
    }
    if (*(size_t *)(param_1 + 0x24) == sVar3) {
      memcpy(*(void **)(param_1 + 0x20),(void *)*piVar2,*(size_t *)(param_1 + 0x24));
      iVar1 = 0;
    }
    else {
      iVar1 = 0x57;
    }
  }
  return iVar1;
}



/* c04f6108 FUN_c04f6108 */

/* Boundary evidence: original MIPS .pdata c04f6108..c04f618f. Semantic name remains unreviewed. */

int FUN_c04f6108(int param_1,undefined4 *param_2,int param_3)

{
  int iVar1;
  void *local_18;
  size_t local_14;
  
  iVar1 = FUN_c04f4c84(param_1,param_2,param_3);
  if (iVar1 == 0) {
    FUN_c04f1d10((undefined4 *)(param_3 + 0x30),(int *)&local_18,param_2);
    if (*(size_t *)(param_1 + 0x34) == local_14) {
      memcpy(*(void **)(param_1 + 0x30),local_18,*(size_t *)(param_1 + 0x34));
      iVar1 = 0;
    }
    else {
      iVar1 = 0x57;
    }
  }
  return iVar1;
}



/* c04f6190 FUN_c04f6190 */

/* Boundary evidence: original MIPS .pdata c04f6190..c04f61e3. Semantic name remains unreviewed. */

int FUN_c04f6190(int param_1,undefined4 *param_2,int param_3)

{
  int iVar1;
  int aiStack_18 [2];
  
  iVar1 = FUN_c04f4d0c(param_1,param_2,param_3);
  if (iVar1 == 0) {
    FUN_c04f1d10((undefined4 *)(param_3 + 0x30),aiStack_18,param_2);
    iVar1 = 0;
  }
  return iVar1;
}



/* c04f61e4 FUN_c04f61e4 */

/* Boundary evidence: original MIPS .pdata c04f61e4..c04f627b. Semantic name remains unreviewed. */

int FUN_c04f61e4(undefined2 *param_1,int *param_2,undefined2 *param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_c04f4ba8(param_1,param_2,param_3);
  if (iVar1 == 0) {
    *(undefined4 *)(param_1 + 10) = *(undefined4 *)(param_3 + 10);
    iVar1 = *(int *)(param_3 + 0xc);
    if (iVar1 == 0) {
      uVar2 = 0;
    }
    else {
      uVar2 = *(undefined4 *)(param_3 + 0xe);
    }
    *(int *)(param_1 + 0xc) = iVar1;
    *(undefined4 *)(param_1 + 0xe) = uVar2;
    FUN_c04f2844(param_2,iVar1,*(int *)(param_3 + 0xe),(int *)(param_1 + 0xc));
    iVar1 = 0;
  }
  return iVar1;
}



/* c04f627c FUN_c04f627c */

/* Boundary evidence: original MIPS .pdata c04f627c..c04f62d7. Semantic name remains unreviewed. */

int FUN_c04f627c(undefined2 *param_1,int *param_2,undefined2 *param_3)

{
  int iVar1;
  
  iVar1 = FUN_c04f457c(param_1,param_2,param_3);
  if (iVar1 == 0) {
    *(undefined4 *)(param_1 + 8) = *(undefined4 *)(param_3 + 8);
    iVar1 = 0;
    *(undefined4 *)(param_1 + 10) = *(undefined4 *)(param_3 + 10);
  }
  return iVar1;
}



/* c04f62d8 FUN_c04f62d8 */

/* Boundary evidence: original MIPS .pdata c04f62d8..c04f6333. Semantic name remains unreviewed. */

int FUN_c04f62d8(undefined2 *param_1,int *param_2,undefined2 *param_3)

{
  int iVar1;
  
  iVar1 = FUN_c04f457c(param_1,param_2,param_3);
  if (iVar1 == 0) {
    *(undefined4 *)(param_1 + 8) = *(undefined4 *)(param_3 + 8);
    iVar1 = 0;
    *(undefined4 *)(param_1 + 10) = *(undefined4 *)(param_3 + 10);
  }
  return iVar1;
}



/* c04f6334 FUN_c04f6334 */

/* Boundary evidence: original MIPS .pdata c04f6334..c04f63bb. Semantic name remains unreviewed. */

int FUN_c04f6334(undefined2 *param_1,int *param_2,undefined2 *param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_c04f4dc4(param_1,param_2,param_3);
  if (iVar1 == 0) {
    iVar1 = *(int *)(param_3 + 0x10);
    if (iVar1 == 0) {
      uVar2 = 0;
    }
    else {
      uVar2 = *(undefined4 *)(param_3 + 0x12);
    }
    *(int *)(param_1 + 0x10) = iVar1;
    *(undefined4 *)(param_1 + 0x12) = uVar2;
    FUN_c04f27c4(param_2,iVar1,*(int *)(param_3 + 0x12),(int *)(param_1 + 0x10));
    iVar1 = 0;
  }
  return iVar1;
}



/* c04f63bc FUN_c04f63bc */

/* Boundary evidence: original MIPS .pdata c04f63bc..c04f6443. Semantic name remains unreviewed. */

int FUN_c04f63bc(undefined2 *param_1,int *param_2,undefined2 *param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_c04f4e4c(param_1,param_2,param_3);
  if (iVar1 == 0) {
    iVar1 = *(int *)(param_3 + 0x10);
    if (iVar1 == 0) {
      uVar2 = 0;
    }
    else {
      uVar2 = *(undefined4 *)(param_3 + 0x12);
    }
    *(int *)(param_1 + 0x10) = iVar1;
    *(undefined4 *)(param_1 + 0x12) = uVar2;
    FUN_c04f27c4(param_2,iVar1,*(int *)(param_3 + 0x12),(int *)(param_1 + 0x10));
    iVar1 = 0;
  }
  return iVar1;
}



/* c04f6444 FUN_c04f6444 */

/* Boundary evidence: original MIPS .pdata c04f6444..c04f64df. Semantic name remains unreviewed. */

int FUN_c04f6444(undefined4 param_1,undefined2 *param_2,undefined4 *param_3)

{
  int iVar1;
  undefined **local_38;
  undefined4 local_34;
  undefined2 auStack_30 [12];
  uint local_18;
  
  local_18 = DAT_c04ff0b4;
  local_34 = 0;
  local_38 = &PTR_LAB_c04f1054;
  FUN_c04f10a4((int *)&local_38,0x18,(int *)0x0);
  iVar1 = FUN_c04f5458(auStack_30,(int *)&local_38,param_2);
  if (iVar1 == 0) {
    *param_3 = local_34;
    FUN_c04fe38c(local_18);
    iVar1 = 0;
  }
  else {
    FUN_c04fe38c(local_18);
  }
  return iVar1;
}



/* c04f64e0 FUN_c04f64e0 */

/* Boundary evidence: original MIPS .pdata c04f64e0..c04f657b. Semantic name remains unreviewed. */

int FUN_c04f64e0(undefined4 param_1,undefined2 *param_2,undefined4 *param_3)

{
  int iVar1;
  undefined **local_38;
  undefined4 local_34;
  undefined2 auStack_30 [14];
  uint local_14;
  
  local_14 = DAT_c04ff0b4;
  local_34 = 0;
  local_38 = &PTR_LAB_c04f1054;
  FUN_c04f10a4((int *)&local_38,0x1c,(int *)0x0);
  iVar1 = FUN_c04f4124(auStack_30,(int *)&local_38,param_2);
  if (iVar1 == 0) {
    *param_3 = local_34;
    FUN_c04fe38c(local_14);
    iVar1 = 0;
  }
  else {
    FUN_c04fe38c(local_14);
  }
  return iVar1;
}



/* c04f657c FUN_c04f657c */

/* Boundary evidence: original MIPS .pdata c04f657c..c04f6617. Semantic name remains unreviewed. */

int FUN_c04f657c(undefined4 param_1,undefined2 *param_2,undefined4 *param_3)

{
  int iVar1;
  undefined **local_38;
  undefined4 local_34;
  undefined2 auStack_30 [12];
  uint local_18;
  
  local_18 = DAT_c04ff0b4;
  local_34 = 0;
  local_38 = &PTR_LAB_c04f1054;
  FUN_c04f10a4((int *)&local_38,0x18,(int *)0x0);
  iVar1 = FUN_c04f567c(auStack_30,(int *)&local_38,param_2);
  if (iVar1 == 0) {
    *param_3 = local_34;
    FUN_c04fe38c(local_18);
    iVar1 = 0;
  }
  else {
    FUN_c04fe38c(local_18);
  }
  return iVar1;
}



/* c04f6618 FUN_c04f6618 */

/* Boundary evidence: original MIPS .pdata c04f6618..c04f66b3. Semantic name remains unreviewed. */

int FUN_c04f6618(undefined4 param_1,undefined2 *param_2,undefined4 *param_3)

{
  int iVar1;
  undefined **local_38;
  undefined4 local_34;
  undefined2 auStack_30 [12];
  uint local_18;
  
  local_18 = DAT_c04ff0b4;
  local_34 = 0;
  local_38 = &PTR_LAB_c04f1054;
  FUN_c04f10a4((int *)&local_38,0x18,(int *)0x0);
  iVar1 = FUN_c04f4378(auStack_30,(int *)&local_38,param_2);
  if (iVar1 == 0) {
    *param_3 = local_34;
    FUN_c04fe38c(local_18);
    iVar1 = 0;
  }
  else {
    FUN_c04fe38c(local_18);
  }
  return iVar1;
}



/* c04f66b4 FUN_c04f66b4 */

/* Boundary evidence: original MIPS .pdata c04f66b4..c04f674f. Semantic name remains unreviewed. */

int FUN_c04f66b4(undefined4 param_1,undefined2 *param_2,undefined4 *param_3)

{
  int iVar1;
  undefined **local_38;
  undefined4 local_34;
  undefined2 auStack_30 [14];
  uint local_14;
  
  local_14 = DAT_c04ff0b4;
  local_34 = 0;
  local_38 = &PTR_LAB_c04f1054;
  FUN_c04f10a4((int *)&local_38,0x1c,(int *)0x0);
  iVar1 = FUN_c04f57b4(auStack_30,(int *)&local_38,param_2);
  if (iVar1 == 0) {
    *param_3 = local_34;
    FUN_c04fe38c(local_14);
    iVar1 = 0;
  }
  else {
    FUN_c04fe38c(local_14);
  }
  return iVar1;
}



/* c04f6750 FUN_c04f6750 */

/* Boundary evidence: original MIPS .pdata c04f6750..c04f67eb. Semantic name remains unreviewed. */

int FUN_c04f6750(undefined4 param_1,undefined2 *param_2,undefined4 *param_3)

{
  int iVar1;
  undefined **local_38;
  undefined4 local_34;
  undefined2 auStack_30 [12];
  uint local_18;
  
  local_18 = DAT_c04ff0b4;
  local_34 = 0;
  local_38 = &PTR_LAB_c04f1054;
  FUN_c04f10a4((int *)&local_38,0x18,(int *)0x0);
  iVar1 = FUN_c04f5828(auStack_30,(int *)&local_38,param_2);
  if (iVar1 == 0) {
    *param_3 = local_34;
    FUN_c04fe38c(local_18);
    iVar1 = 0;
  }
  else {
    FUN_c04fe38c(local_18);
  }
  return iVar1;
}



/* c04f67ec FUN_c04f67ec */

/* Boundary evidence: original MIPS .pdata c04f67ec..c04f6887. Semantic name remains unreviewed. */

int FUN_c04f67ec(undefined4 param_1,undefined2 *param_2,undefined4 *param_3)

{
  int iVar1;
  undefined **local_38;
  undefined4 local_34;
  undefined2 auStack_30 [12];
  uint local_18;
  
  local_18 = DAT_c04ff0b4;
  local_34 = 0;
  local_38 = &PTR_LAB_c04f1054;
  FUN_c04f10a4((int *)&local_38,0x18,(int *)0x0);
  iVar1 = FUN_c04f44f4(auStack_30,(int *)&local_38,param_2);
  if (iVar1 == 0) {
    *param_3 = local_34;
    FUN_c04fe38c(local_18);
    iVar1 = 0;
  }
  else {
    FUN_c04fe38c(local_18);
  }
  return iVar1;
}



/* c04f6888 FUN_c04f6888 */

/* Boundary evidence: original MIPS .pdata c04f6888..c04f6923. Semantic name remains unreviewed. */

int FUN_c04f6888(undefined4 param_1,undefined2 *param_2,undefined4 *param_3)

{
  int iVar1;
  undefined **local_38;
  undefined4 local_34;
  undefined2 auStack_30 [12];
  uint local_18;
  
  local_18 = DAT_c04ff0b4;
  local_34 = 0;
  local_38 = &PTR_LAB_c04f1054;
  FUN_c04f10a4((int *)&local_38,0x18,(int *)0x0);
  iVar1 = FUN_c04f589c(auStack_30,(int *)&local_38,param_2);
  if (iVar1 == 0) {
    *param_3 = local_34;
    FUN_c04fe38c(local_18);
    iVar1 = 0;
  }
  else {
    FUN_c04fe38c(local_18);
  }
  return iVar1;
}



/* c04f6924 FUN_c04f6924 */

/* Boundary evidence: original MIPS .pdata c04f6924..c04f69bf. Semantic name remains unreviewed. */

int FUN_c04f6924(undefined4 param_1,undefined2 *param_2,undefined4 *param_3)

{
  int iVar1;
  undefined **local_40;
  undefined4 local_3c;
  undefined2 auStack_38 [16];
  uint local_18;
  
  local_18 = DAT_c04ff0b4;
  local_3c = 0;
  local_40 = &PTR_LAB_c04f1054;
  FUN_c04f10a4((int *)&local_40,0x20,(int *)0x0);
  iVar1 = FUN_c04f5924(auStack_38,(int *)&local_40,param_2);
  if (iVar1 == 0) {
    *param_3 = local_3c;
    FUN_c04fe38c(local_18);
    iVar1 = 0;
  }
  else {
    FUN_c04fe38c(local_18);
  }
  return iVar1;
}



/* c04f69c0 FUN_c04f69c0 */

/* Boundary evidence: original MIPS .pdata c04f69c0..c04f6a5b. Semantic name remains unreviewed. */

int FUN_c04f69c0(undefined4 param_1,undefined2 *param_2,undefined4 *param_3)

{
  int iVar1;
  undefined **local_38;
  undefined4 local_34;
  undefined2 auStack_30 [14];
  uint local_14;
  
  local_14 = DAT_c04ff0b4;
  local_34 = 0;
  local_38 = &PTR_LAB_c04f1054;
  FUN_c04f10a4((int *)&local_38,0x1c,(int *)0x0);
  iVar1 = FUN_c04f59bc(auStack_30,(int *)&local_38,param_2);
  if (iVar1 == 0) {
    *param_3 = local_34;
    FUN_c04fe38c(local_14);
    iVar1 = 0;
  }
  else {
    FUN_c04fe38c(local_14);
  }
  return iVar1;
}



/* c04f6a5c FUN_c04f6a5c */

/* Boundary evidence: original MIPS .pdata c04f6a5c..c04f6af7. Semantic name remains unreviewed. */

int FUN_c04f6a5c(undefined4 param_1,undefined2 *param_2,undefined4 *param_3)

{
  int iVar1;
  undefined **local_38;
  undefined4 local_34;
  undefined2 auStack_30 [12];
  uint local_18;
  
  local_18 = DAT_c04ff0b4;
  local_34 = 0;
  local_38 = &PTR_LAB_c04f1054;
  FUN_c04f10a4((int *)&local_38,0x18,(int *)0x0);
  iVar1 = FUN_c04f5a18(auStack_30,(int *)&local_38,param_2);
  if (iVar1 == 0) {
    *param_3 = local_34;
    FUN_c04fe38c(local_18);
    iVar1 = 0;
  }
  else {
    FUN_c04fe38c(local_18);
  }
  return iVar1;
}



/* c04f6af8 FUN_c04f6af8 */

/* Boundary evidence: original MIPS .pdata c04f6af8..c04f6b93. Semantic name remains unreviewed. */

int FUN_c04f6af8(undefined4 param_1,undefined2 *param_2,undefined4 *param_3)

{
  int iVar1;
  undefined **local_38;
  undefined4 local_34;
  undefined2 auStack_30 [12];
  uint local_18;
  
  local_18 = DAT_c04ff0b4;
  local_34 = 0;
  local_38 = &PTR_LAB_c04f1054;
  FUN_c04f10a4((int *)&local_38,0x18,(int *)0x0);
  iVar1 = FUN_c04f5a8c(auStack_30,(int *)&local_38,param_2);
  if (iVar1 == 0) {
    *param_3 = local_34;
    FUN_c04fe38c(local_18);
    iVar1 = 0;
  }
  else {
    FUN_c04fe38c(local_18);
  }
  return iVar1;
}



/* c04f6b94 FUN_c04f6b94 */

/* Boundary evidence: original MIPS .pdata c04f6b94..c04f6c9b. Semantic name remains unreviewed. */

int FUN_c04f6b94(undefined4 *param_1,undefined2 *param_2)

{
  int iVar1;
  int *piVar2;
  undefined2 *puVar3;
  uint local_28 [2];
  
  iVar1 = FUN_c04f6444(param_1,param_2,local_28);
  if (iVar1 == 0) {
    piVar2 = FUN_c04f50a8(local_28[0]);
    if (piVar2 == (int *)0x0) {
      iVar1 = 0xe;
    }
    else {
      FUN_c04f10a4(piVar2,0x18,(int *)0x0);
      puVar3 = (undefined2 *)piVar2[2];
      iVar1 = FUN_c04f5458(puVar3,piVar2,param_2);
      if (iVar1 == 0) {
        iVar1 = (**(code **)*param_1)(param_1,puVar3,local_28[0]);
        FUN_c04f35d8((int)param_2,piVar2,(int)puVar3);
      }
      if ((void *)piVar2[2] != (void *)0x0) {
        operator_delete((void *)piVar2[2]);
      }
      operator_delete(piVar2);
    }
  }
  else {
    iVar1 = 0x57;
  }
  return iVar1;
}



/* c04f6c9c FUN_c04f6c9c */

/* Boundary evidence: original MIPS .pdata c04f6c9c..c04f6db3. Semantic name remains unreviewed. */

int FUN_c04f6c9c(undefined4 *param_1,undefined2 *param_2)

{
  int iVar1;
  int *piVar2;
  undefined2 *puVar3;
  uint local_28 [2];
  
  iVar1 = FUN_c04f64e0(param_1,param_2,local_28);
  if (iVar1 == 0) {
    piVar2 = FUN_c04f50a8(local_28[0]);
    if (piVar2 == (int *)0x0) {
      iVar1 = 0xe;
    }
    else {
      FUN_c04f10a4(piVar2,0x1c,(int *)0x0);
      puVar3 = (undefined2 *)piVar2[2];
      iVar1 = FUN_c04f4124(puVar3,piVar2,param_2);
      if (iVar1 == 0) {
        *(undefined4 *)(puVar3 + 0xc) = *(undefined4 *)(param_2 + 0xc);
        iVar1 = (**(code **)*param_1)(param_1,puVar3,local_28[0]);
        FUN_c04f2d40((int)param_2,piVar2,(int)puVar3);
      }
      if ((void *)piVar2[2] != (void *)0x0) {
        operator_delete((void *)piVar2[2]);
      }
      operator_delete(piVar2);
    }
  }
  else {
    iVar1 = 0x57;
  }
  return iVar1;
}



/* c04f6db4 FUN_c04f6db4 */

/* Boundary evidence: original MIPS .pdata c04f6db4..c04f6ebb. Semantic name remains unreviewed. */

int FUN_c04f6db4(undefined4 *param_1,undefined2 *param_2)

{
  int iVar1;
  int *piVar2;
  undefined2 *puVar3;
  uint local_28 [2];
  
  iVar1 = FUN_c04f657c(param_1,param_2,local_28);
  if (iVar1 == 0) {
    piVar2 = FUN_c04f50a8(local_28[0]);
    if (piVar2 == (int *)0x0) {
      iVar1 = 0xe;
    }
    else {
      FUN_c04f10a4(piVar2,0x18,(int *)0x0);
      puVar3 = (undefined2 *)piVar2[2];
      iVar1 = FUN_c04f567c(puVar3,piVar2,param_2);
      if (iVar1 == 0) {
        iVar1 = (**(code **)*param_1)(param_1,puVar3,local_28[0]);
        FUN_c04f5704((int)param_2,piVar2,(int)puVar3);
      }
      if ((void *)piVar2[2] != (void *)0x0) {
        operator_delete((void *)piVar2[2]);
      }
      operator_delete(piVar2);
    }
  }
  else {
    iVar1 = 0x57;
  }
  return iVar1;
}



/* c04f6ebc FUN_c04f6ebc */

/* Boundary evidence: original MIPS .pdata c04f6ebc..c04f6fd3. Semantic name remains unreviewed. */

int FUN_c04f6ebc(undefined4 *param_1,undefined2 *param_2)

{
  int iVar1;
  int *piVar2;
  undefined2 *puVar3;
  uint local_28 [2];
  
  iVar1 = FUN_c04f6618(param_1,param_2,local_28);
  if (iVar1 == 0) {
    piVar2 = FUN_c04f50a8(local_28[0]);
    if (piVar2 == (int *)0x0) {
      iVar1 = 0xe;
    }
    else {
      FUN_c04f10a4(piVar2,0x18,(int *)0x0);
      puVar3 = (undefined2 *)piVar2[2];
      iVar1 = FUN_c04f4378(puVar3,piVar2,param_2);
      if (iVar1 == 0) {
        *(undefined4 *)(puVar3 + 10) = *(undefined4 *)(param_2 + 10);
        iVar1 = (**(code **)*param_1)(param_1,puVar3,local_28[0]);
        FUN_c04f2d94((int)param_2,piVar2,(int)puVar3);
      }
      if ((void *)piVar2[2] != (void *)0x0) {
        operator_delete((void *)piVar2[2]);
      }
      operator_delete(piVar2);
    }
  }
  else {
    iVar1 = 0x57;
  }
  return iVar1;
}



/* c04f6fd4 FUN_c04f6fd4 */

/* Boundary evidence: original MIPS .pdata c04f6fd4..c04f70db. Semantic name remains unreviewed. */

int FUN_c04f6fd4(undefined4 *param_1,undefined2 *param_2)

{
  int iVar1;
  int *piVar2;
  undefined2 *puVar3;
  uint local_28 [2];
  
  iVar1 = FUN_c04f66b4(param_1,param_2,local_28);
  if (iVar1 == 0) {
    piVar2 = FUN_c04f50a8(local_28[0]);
    if (piVar2 == (int *)0x0) {
      iVar1 = 0xe;
    }
    else {
      FUN_c04f10a4(piVar2,0x1c,(int *)0x0);
      puVar3 = (undefined2 *)piVar2[2];
      iVar1 = FUN_c04f57b4(puVar3,piVar2,param_2);
      if (iVar1 == 0) {
        iVar1 = (**(code **)*param_1)(param_1,puVar3,local_28[0]);
        FUN_c04f3670((int)param_2,piVar2,(int)puVar3);
      }
      if ((void *)piVar2[2] != (void *)0x0) {
        operator_delete((void *)piVar2[2]);
      }
      operator_delete(piVar2);
    }
  }
  else {
    iVar1 = 0x57;
  }
  return iVar1;
}



/* c04f70dc FUN_c04f70dc */

/* Boundary evidence: original MIPS .pdata c04f70dc..c04f71e3. Semantic name remains unreviewed. */

int FUN_c04f70dc(undefined4 *param_1,undefined2 *param_2)

{
  int iVar1;
  int *piVar2;
  undefined2 *puVar3;
  uint local_28 [2];
  
  iVar1 = FUN_c04f6750(param_1,param_2,local_28);
  if (iVar1 == 0) {
    piVar2 = FUN_c04f50a8(local_28[0]);
    if (piVar2 == (int *)0x0) {
      iVar1 = 0xe;
    }
    else {
      FUN_c04f10a4(piVar2,0x18,(int *)0x0);
      puVar3 = (undefined2 *)piVar2[2];
      iVar1 = FUN_c04f5828(puVar3,piVar2,param_2);
      if (iVar1 == 0) {
        iVar1 = (**(code **)*param_1)(param_1,puVar3,local_28[0]);
        FUN_c04f3700((int)param_2,piVar2,(int)puVar3);
      }
      if ((void *)piVar2[2] != (void *)0x0) {
        operator_delete((void *)piVar2[2]);
      }
      operator_delete(piVar2);
    }
  }
  else {
    iVar1 = 0x57;
  }
  return iVar1;
}



/* c04f71e4 FUN_c04f71e4 */

/* Boundary evidence: original MIPS .pdata c04f71e4..c04f72fb. Semantic name remains unreviewed. */

int FUN_c04f71e4(undefined4 *param_1,undefined2 *param_2)

{
  int iVar1;
  int *piVar2;
  undefined2 *puVar3;
  uint local_28 [2];
  
  iVar1 = FUN_c04f67ec(param_1,param_2,local_28);
  if (iVar1 == 0) {
    piVar2 = FUN_c04f50a8(local_28[0]);
    if (piVar2 == (int *)0x0) {
      iVar1 = 0xe;
    }
    else {
      FUN_c04f10a4(piVar2,0x18,(int *)0x0);
      puVar3 = (undefined2 *)piVar2[2];
      iVar1 = FUN_c04f44f4(puVar3,piVar2,param_2);
      if (iVar1 == 0) {
        *(undefined4 *)(puVar3 + 10) = *(undefined4 *)(param_2 + 10);
        iVar1 = (**(code **)*param_1)(param_1,puVar3,local_28[0]);
        FUN_c04f2eb4((int)param_2,piVar2,(int)puVar3);
      }
      if ((void *)piVar2[2] != (void *)0x0) {
        operator_delete((void *)piVar2[2]);
      }
      operator_delete(piVar2);
    }
  }
  else {
    iVar1 = 0x57;
  }
  return iVar1;
}



/* c04f72fc FUN_c04f72fc */

/* Boundary evidence: original MIPS .pdata c04f72fc..c04f7403. Semantic name remains unreviewed. */

int FUN_c04f72fc(undefined4 *param_1,undefined2 *param_2)

{
  int iVar1;
  int *piVar2;
  undefined2 *puVar3;
  uint local_28 [2];
  
  iVar1 = FUN_c04f6888(param_1,param_2,local_28);
  if (iVar1 == 0) {
    piVar2 = FUN_c04f50a8(local_28[0]);
    if (piVar2 == (int *)0x0) {
      iVar1 = 0xe;
    }
    else {
      FUN_c04f10a4(piVar2,0x18,(int *)0x0);
      puVar3 = (undefined2 *)piVar2[2];
      iVar1 = FUN_c04f589c(puVar3,piVar2,param_2);
      if (iVar1 == 0) {
        iVar1 = (**(code **)*param_1)(param_1,puVar3,local_28[0]);
        FUN_c04f3790((int)param_2,piVar2,(int)puVar3);
      }
      if ((void *)piVar2[2] != (void *)0x0) {
        operator_delete((void *)piVar2[2]);
      }
      operator_delete(piVar2);
    }
  }
  else {
    iVar1 = 0x57;
  }
  return iVar1;
}



/* c04f7404 FUN_c04f7404 */

/* Boundary evidence: original MIPS .pdata c04f7404..c04f750b. Semantic name remains unreviewed. */

int FUN_c04f7404(undefined4 *param_1,undefined2 *param_2)

{
  int iVar1;
  int *piVar2;
  undefined2 *puVar3;
  uint local_28 [2];
  
  iVar1 = FUN_c04f6924(param_1,param_2,local_28);
  if (iVar1 == 0) {
    piVar2 = FUN_c04f50a8(local_28[0]);
    if (piVar2 == (int *)0x0) {
      iVar1 = 0xe;
    }
    else {
      FUN_c04f10a4(piVar2,0x20,(int *)0x0);
      puVar3 = (undefined2 *)piVar2[2];
      iVar1 = FUN_c04f5924(puVar3,piVar2,param_2);
      if (iVar1 == 0) {
        iVar1 = (**(code **)*param_1)(param_1,puVar3,local_28[0]);
        FUN_c04f3828((int)param_2,piVar2,(int)puVar3);
      }
      if ((void *)piVar2[2] != (void *)0x0) {
        operator_delete((void *)piVar2[2]);
      }
      operator_delete(piVar2);
    }
  }
  else {
    iVar1 = 0x57;
  }
  return iVar1;
}



/* c04f750c FUN_c04f750c */

/* Boundary evidence: original MIPS .pdata c04f750c..c04f7613. Semantic name remains unreviewed. */

int FUN_c04f750c(undefined4 *param_1,undefined2 *param_2)

{
  int iVar1;
  int *piVar2;
  undefined2 *puVar3;
  uint local_28 [2];
  
  iVar1 = FUN_c04f69c0(param_1,param_2,local_28);
  if (iVar1 == 0) {
    piVar2 = FUN_c04f50a8(local_28[0]);
    if (piVar2 == (int *)0x0) {
      iVar1 = 0xe;
    }
    else {
      FUN_c04f10a4(piVar2,0x1c,(int *)0x0);
      puVar3 = (undefined2 *)piVar2[2];
      iVar1 = FUN_c04f59bc(puVar3,piVar2,param_2);
      if (iVar1 == 0) {
        iVar1 = (**(code **)*param_1)(param_1,puVar3,local_28[0]);
        FUN_c04f2cac((int)param_2,piVar2,(int)puVar3);
      }
      if ((void *)piVar2[2] != (void *)0x0) {
        operator_delete((void *)piVar2[2]);
      }
      operator_delete(piVar2);
    }
  }
  else {
    iVar1 = 0x57;
  }
  return iVar1;
}



/* c04f7614 FUN_c04f7614 */

/* Boundary evidence: original MIPS .pdata c04f7614..c04f771b. Semantic name remains unreviewed. */

int FUN_c04f7614(undefined4 *param_1,undefined2 *param_2)

{
  int iVar1;
  int *piVar2;
  undefined2 *puVar3;
  uint local_28 [2];
  
  iVar1 = FUN_c04f6a5c(param_1,param_2,local_28);
  if (iVar1 == 0) {
    piVar2 = FUN_c04f50a8(local_28[0]);
    if (piVar2 == (int *)0x0) {
      iVar1 = 0xe;
    }
    else {
      FUN_c04f10a4(piVar2,0x18,(int *)0x0);
      puVar3 = (undefined2 *)piVar2[2];
      iVar1 = FUN_c04f5a18(puVar3,piVar2,param_2);
      if (iVar1 == 0) {
        iVar1 = (**(code **)*param_1)(param_1,puVar3,local_28[0]);
        FUN_c04f38c0((int)param_2,piVar2,(int)puVar3);
      }
      if ((void *)piVar2[2] != (void *)0x0) {
        operator_delete((void *)piVar2[2]);
      }
      operator_delete(piVar2);
    }
  }
  else {
    iVar1 = 0x57;
  }
  return iVar1;
}



/* c04f771c FUN_c04f771c */

/* Boundary evidence: original MIPS .pdata c04f771c..c04f7823. Semantic name remains unreviewed. */

int FUN_c04f771c(undefined4 *param_1,undefined2 *param_2)

{
  int iVar1;
  int *piVar2;
  undefined2 *puVar3;
  uint local_28 [2];
  
  iVar1 = FUN_c04f6af8(param_1,param_2,local_28);
  if (iVar1 == 0) {
    piVar2 = FUN_c04f50a8(local_28[0]);
    if (piVar2 == (int *)0x0) {
      iVar1 = 0xe;
    }
    else {
      FUN_c04f10a4(piVar2,0x18,(int *)0x0);
      puVar3 = (undefined2 *)piVar2[2];
      iVar1 = FUN_c04f5a8c(puVar3,piVar2,param_2);
      if (iVar1 == 0) {
        iVar1 = (**(code **)*param_1)(param_1,puVar3,local_28[0]);
        FUN_c04f3950((int)param_2,piVar2,(int)puVar3);
      }
      if ((void *)piVar2[2] != (void *)0x0) {
        operator_delete((void *)piVar2[2]);
      }
      operator_delete(piVar2);
    }
  }
  else {
    iVar1 = 0x57;
  }
  return iVar1;
}



/* c04f7824 FUN_c04f7824 */

/* Boundary evidence: original MIPS .pdata c04f7824..c04f7897. Semantic name remains unreviewed. */

int FUN_c04f7824(undefined2 *param_1,int *param_2,undefined2 *param_3)

{
  int iVar1;
  
  iVar1 = FUN_c04f5b5c(param_1,param_2,param_3);
  if (iVar1 == 0) {
    iVar1 = *(int *)(param_3 + 0xc);
    *(int *)(param_1 + 0xc) = iVar1;
    if (iVar1 != 0) {
      FUN_c04f2260(param_2,*(undefined4 *)(param_3 + 0xc),4,(int *)(param_1 + 0xc));
    }
    iVar1 = 0;
  }
  return iVar1;
}



/* c04f7898 FUN_c04f7898 */

/* Boundary evidence: original MIPS .pdata c04f7898..c04f78f3. Semantic name remains unreviewed. */

int FUN_c04f7898(undefined2 *param_1,int *param_2,undefined2 *param_3)

{
  int iVar1;
  
  iVar1 = FUN_c04f46a8(param_1,param_2,param_3);
  if (iVar1 == 0) {
    *(undefined4 *)(param_1 + 0xc) = *(undefined4 *)(param_3 + 0xc);
    iVar1 = 0;
    *(undefined4 *)(param_1 + 0xe) = *(undefined4 *)(param_3 + 0xe);
  }
  return iVar1;
}



/* c04f78f4 FUN_c04f78f4 */

/* Boundary evidence: original MIPS .pdata c04f78f4..c04f794f. Semantic name remains unreviewed. */

int FUN_c04f78f4(undefined2 *param_1,int *param_2,undefined2 *param_3)

{
  int iVar1;
  
  iVar1 = FUN_c04f4740(param_1,param_2,param_3);
  if (iVar1 == 0) {
    *(undefined4 *)(param_1 + 0xc) = *(undefined4 *)(param_3 + 0xc);
    iVar1 = 0;
    *(undefined4 *)(param_1 + 0xe) = *(undefined4 *)(param_3 + 0xe);
  }
  return iVar1;
}



/* c04f7950 FUN_c04f7950 */

/* Boundary evidence: original MIPS .pdata c04f7950..c04f79c3. Semantic name remains unreviewed. */

int FUN_c04f7950(undefined2 *param_1,int *param_2,undefined2 *param_3)

{
  int iVar1;
  
  iVar1 = FUN_c04f5c8c(param_1,param_2,param_3);
  if (iVar1 == 0) {
    iVar1 = *(int *)(param_3 + 0x10);
    *(int *)(param_1 + 0x10) = iVar1;
    if (iVar1 != 0) {
      FUN_c04f2260(param_2,*(undefined4 *)(param_3 + 0x10),4,(int *)(param_1 + 0x10));
    }
    iVar1 = 0;
  }
  return iVar1;
}



/* c04f79c4 FUN_c04f79c4 */

/* Boundary evidence: original MIPS .pdata c04f79c4..c04f7a37. Semantic name remains unreviewed. */

int FUN_c04f79c4(undefined2 *param_1,int *param_2,undefined2 *param_3)

{
  int iVar1;
  
  iVar1 = FUN_c04f5d24(param_1,param_2,param_3);
  if (iVar1 == 0) {
    iVar1 = *(int *)(param_3 + 0xe);
    *(int *)(param_1 + 0xe) = iVar1;
    if (iVar1 != 0) {
      FUN_c04f23b0(param_2,*(undefined4 *)(param_3 + 0xe),4,(int *)(param_1 + 0xe));
    }
    iVar1 = 0;
  }
  return iVar1;
}



/* c04f7a38 FUN_c04f7a38 */

/* Boundary evidence: original MIPS .pdata c04f7a38..c04f7ac7. Semantic name remains unreviewed. */

int FUN_c04f7a38(int param_1,undefined4 *param_2,int param_3)

{
  int iVar1;
  undefined4 *puVar2;
  
  iVar1 = FUN_c04f5dac(param_1,param_2,param_3);
  if (iVar1 == 0) {
    if (*(int *)(param_3 + 0x28) == 0) {
      puVar2 = (undefined4 *)0x0;
    }
    else {
      puVar2 = (undefined4 *)(**(code **)*param_2)(param_2,*(int *)(param_3 + 0x28),4);
    }
    if (*(undefined4 **)(param_1 + 0x28) != (undefined4 *)0x0) {
      **(undefined4 **)(param_1 + 0x28) = *puVar2;
    }
    iVar1 = 0;
  }
  return iVar1;
}



/* c04f7ac8 FUN_c04f7ac8 */

/* Boundary evidence: original MIPS .pdata c04f7ac8..c04f7b5f. Semantic name remains unreviewed. */

int FUN_c04f7ac8(undefined2 *param_1,int *param_2,undefined2 *param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_c04f4928(param_1,param_2,param_3);
  if (iVar1 == 0) {
    *(undefined4 *)(param_1 + 8) = *(undefined4 *)(param_3 + 8);
    iVar1 = *(int *)(param_3 + 10);
    if (iVar1 == 0) {
      uVar2 = 0;
    }
    else {
      uVar2 = *(undefined4 *)(param_3 + 0xc);
    }
    *(int *)(param_1 + 10) = iVar1;
    *(undefined4 *)(param_1 + 0xc) = uVar2;
    FUN_c04f23b0(param_2,iVar1,*(int *)(param_3 + 0xc),(int *)(param_1 + 10));
    iVar1 = 0;
  }
  return iVar1;
}



/* c04f7b60 FUN_c04f7b60 */

/* Boundary evidence: original MIPS .pdata c04f7b60..c04f7be7. Semantic name remains unreviewed. */

int FUN_c04f7b60(undefined2 *param_1,int *param_2,undefined2 *param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_c04f7898(param_1,param_2,param_3);
  if (iVar1 == 0) {
    iVar1 = *(int *)(param_3 + 0x10);
    if (iVar1 == 0) {
      uVar2 = 0;
    }
    else {
      uVar2 = *(undefined4 *)(param_3 + 0x12);
    }
    *(int *)(param_1 + 0x10) = iVar1;
    *(undefined4 *)(param_1 + 0x12) = uVar2;
    FUN_c04f23b0(param_2,iVar1,*(int *)(param_3 + 0x12),(int *)(param_1 + 0x10));
    iVar1 = 0;
  }
  return iVar1;
}



/* c04f7be8 FUN_c04f7be8 */

/* Boundary evidence: original MIPS .pdata c04f7be8..c04f7c4b. Semantic name remains unreviewed. */

int FUN_c04f7be8(undefined2 *param_1,int *param_2,undefined2 *param_3)

{
  int iVar1;
  
  iVar1 = FUN_c04f5e18(param_1,param_2,param_3);
  if (iVar1 == 0) {
    FUN_c04f2600((int *)(param_1 + 0xe),param_2,(int *)(param_3 + 0xe));
    iVar1 = 0;
  }
  return iVar1;
}



/* c04f7c4c FUN_c04f7c4c */

/* Boundary evidence: original MIPS .pdata c04f7c4c..c04f7cd3. Semantic name remains unreviewed. */

int FUN_c04f7c4c(undefined2 *param_1,int *param_2,undefined2 *param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_c04f78f4(param_1,param_2,param_3);
  if (iVar1 == 0) {
    iVar1 = *(int *)(param_3 + 0x10);
    if (iVar1 == 0) {
      uVar2 = 0;
    }
    else {
      uVar2 = *(undefined4 *)(param_3 + 0x12);
    }
    *(int *)(param_1 + 0x10) = iVar1;
    *(undefined4 *)(param_1 + 0x12) = uVar2;
    FUN_c04f27c4(param_2,iVar1,*(int *)(param_3 + 0x12),(int *)(param_1 + 0x10));
    iVar1 = 0;
  }
  return iVar1;
}



/* c04f7cd4 FUN_c04f7cd4 */

/* Boundary evidence: original MIPS .pdata c04f7cd4..c04f7d2f. Semantic name remains unreviewed. */

int FUN_c04f7cd4(undefined2 *param_1,int *param_2,undefined2 *param_3)

{
  int iVar1;
  
  iVar1 = FUN_c04f4a00(param_1,param_2,param_3);
  if (iVar1 == 0) {
    *(undefined4 *)(param_1 + 10) = *(undefined4 *)(param_3 + 10);
    iVar1 = 0;
    *(undefined4 *)(param_1 + 0xc) = *(undefined4 *)(param_3 + 0xc);
  }
  return iVar1;
}



/* c04f7d30 FUN_c04f7d30 */

/* Boundary evidence: original MIPS .pdata c04f7d30..c04f7dc7. Semantic name remains unreviewed. */

int FUN_c04f7d30(int param_1,undefined4 *param_2,int param_3)

{
  int iVar1;
  int *piVar2;
  size_t sVar3;
  int aiStack_18 [2];
  
  iVar1 = FUN_c04f5f04(param_1,param_2,param_3);
  if (iVar1 == 0) {
    piVar2 = FUN_c04f1c5c((undefined4 *)(param_3 + 0x24),aiStack_18,param_2);
    if ((void *)*piVar2 == (void *)0x0) {
      sVar3 = 0;
    }
    else {
      sVar3 = piVar2[1];
    }
    if (*(size_t *)(param_1 + 0x28) == sVar3) {
      memcpy(*(void **)(param_1 + 0x24),(void *)*piVar2,*(size_t *)(param_1 + 0x28));
      iVar1 = 0;
    }
    else {
      iVar1 = 0x57;
    }
  }
  return iVar1;
}



/* c04f7dc8 FUN_c04f7dc8 */

/* Boundary evidence: original MIPS .pdata c04f7dc8..c04f7e4f. Semantic name remains unreviewed. */

int FUN_c04f7dc8(undefined2 *param_1,int *param_2,undefined2 *param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_c04f5f94(param_1,param_2,param_3);
  if (iVar1 == 0) {
    iVar1 = *(int *)(param_3 + 0xe);
    if (iVar1 == 0) {
      uVar2 = 0;
    }
    else {
      uVar2 = *(undefined4 *)(param_3 + 0x10);
    }
    *(int *)(param_1 + 0xe) = iVar1;
    *(undefined4 *)(param_1 + 0x10) = uVar2;
    FUN_c04f23b0(param_2,iVar1,*(int *)(param_3 + 0x10),(int *)(param_1 + 0xe));
    iVar1 = 0;
  }
  return iVar1;
}



/* c04f7e50 FUN_c04f7e50 */

/* Boundary evidence: original MIPS .pdata c04f7e50..c04f7ee7. Semantic name remains unreviewed. */

int FUN_c04f7e50(int param_1,undefined4 *param_2,int param_3)

{
  int iVar1;
  int *piVar2;
  size_t sVar3;
  int aiStack_18 [2];
  
  iVar1 = FUN_c04f601c(param_1,param_2,param_3);
  if (iVar1 == 0) {
    piVar2 = FUN_c04f1c5c((undefined4 *)(param_3 + 0x1c),aiStack_18,param_2);
    if ((void *)*piVar2 == (void *)0x0) {
      sVar3 = 0;
    }
    else {
      sVar3 = piVar2[1];
    }
    if (*(size_t *)(param_1 + 0x20) == sVar3) {
      memcpy(*(void **)(param_1 + 0x1c),(void *)*piVar2,*(size_t *)(param_1 + 0x20));
      iVar1 = 0;
    }
    else {
      iVar1 = 0x57;
    }
  }
  return iVar1;
}



/* c04f7ee8 FUN_c04f7ee8 */

/* Boundary evidence: original MIPS .pdata c04f7ee8..c04f7f7f. Semantic name remains unreviewed. */

int FUN_c04f7ee8(undefined2 *param_1,int *param_2,undefined2 *param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_c04f5b00(param_1,param_2,param_3);
  if (iVar1 == 0) {
    *(undefined4 *)(param_1 + 10) = *(undefined4 *)(param_3 + 10);
    iVar1 = *(int *)(param_3 + 0xc);
    if (iVar1 == 0) {
      uVar2 = 0;
    }
    else {
      uVar2 = *(undefined4 *)(param_3 + 0xe);
    }
    *(int *)(param_1 + 0xc) = iVar1;
    *(undefined4 *)(param_1 + 0xe) = uVar2;
    FUN_c04f23b0(param_2,iVar1,*(int *)(param_3 + 0xe),(int *)(param_1 + 0xc));
    iVar1 = 0;
  }
  return iVar1;
}



/* c04f7f80 FUN_c04f7f80 */

/* Boundary evidence: original MIPS .pdata c04f7f80..c04f800f. Semantic name remains unreviewed. */

int FUN_c04f7f80(int param_1,undefined4 *param_2,int param_3)

{
  int iVar1;
  undefined4 *puVar2;
  
  iVar1 = FUN_c04f6070(param_1,param_2,param_3);
  if (iVar1 == 0) {
    if (*(int *)(param_3 + 0x28) == 0) {
      puVar2 = (undefined4 *)0x0;
    }
    else {
      puVar2 = (undefined4 *)(**(code **)*param_2)(param_2,*(int *)(param_3 + 0x28),4);
    }
    if (*(undefined4 **)(param_1 + 0x28) != (undefined4 *)0x0) {
      **(undefined4 **)(param_1 + 0x28) = *puVar2;
    }
    iVar1 = 0;
  }
  return iVar1;
}



/* c04f8010 FUN_c04f8010 */

/* Boundary evidence: original MIPS .pdata c04f8010..c04f80a7. Semantic name remains unreviewed. */

int FUN_c04f8010(undefined2 *param_1,int *param_2,undefined2 *param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_c04f4ba8(param_1,param_2,param_3);
  if (iVar1 == 0) {
    *(undefined4 *)(param_1 + 10) = *(undefined4 *)(param_3 + 10);
    iVar1 = *(int *)(param_3 + 0xc);
    if (iVar1 == 0) {
      uVar2 = 0;
    }
    else {
      uVar2 = *(undefined4 *)(param_3 + 0xe);
    }
    *(int *)(param_1 + 0xc) = iVar1;
    *(undefined4 *)(param_1 + 0xe) = uVar2;
    FUN_c04f23b0(param_2,iVar1,*(int *)(param_3 + 0xe),(int *)(param_1 + 0xc));
    iVar1 = 0;
  }
  return iVar1;
}



/* c04f80a8 FUN_c04f80a8 */

/* Boundary evidence: original MIPS .pdata c04f80a8..c04f813f. Semantic name remains unreviewed. */

int FUN_c04f80a8(undefined2 *param_1,int *param_2,undefined2 *param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_c04f4d60(param_1,param_2,param_3);
  if (iVar1 == 0) {
    *(undefined4 *)(param_1 + 8) = *(undefined4 *)(param_3 + 8);
    iVar1 = *(int *)(param_3 + 10);
    if (iVar1 == 0) {
      uVar2 = 0;
    }
    else {
      uVar2 = *(undefined4 *)(param_3 + 0xc);
    }
    *(int *)(param_1 + 10) = iVar1;
    *(undefined4 *)(param_1 + 0xc) = uVar2;
    FUN_c04f23b0(param_2,iVar1,*(int *)(param_3 + 0xc),(int *)(param_1 + 10));
    iVar1 = 0;
  }
  return iVar1;
}



/* c04f8140 FUN_c04f8140 */

/* Boundary evidence: original MIPS .pdata c04f8140..c04f81ab. Semantic name remains unreviewed. */

int FUN_c04f8140(int param_1,undefined4 *param_2,int param_3)

{
  int iVar1;
  int aiStack_18 [2];
  
  iVar1 = FUN_c04f2cac(param_1,param_2,param_3);
  if (iVar1 == 0) {
    FUN_c04f33f0((int *)(param_3 + 0xc),param_2);
    FUN_c04f1c5c((undefined4 *)(param_3 + 0x14),aiStack_18,param_2);
    iVar1 = 0;
  }
  return iVar1;
}



/* c04f81ac FUN_c04f81ac */

/* Boundary evidence: original MIPS .pdata c04f81ac..c04f8233. Semantic name remains unreviewed. */

int FUN_c04f81ac(undefined2 *param_1,int *param_2,undefined2 *param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_c04f627c(param_1,param_2,param_3);
  if (iVar1 == 0) {
    iVar1 = *(int *)(param_3 + 0xc);
    if (iVar1 == 0) {
      uVar2 = 0;
    }
    else {
      uVar2 = *(undefined4 *)(param_3 + 0xe);
    }
    *(int *)(param_1 + 0xc) = iVar1;
    *(undefined4 *)(param_1 + 0xe) = uVar2;
    FUN_c04f23b0(param_2,iVar1,*(int *)(param_3 + 0xe),(int *)(param_1 + 0xc));
    iVar1 = 0;
  }
  return iVar1;
}



/* c04f8234 FUN_c04f8234 */

/* Boundary evidence: original MIPS .pdata c04f8234..c04f82bb. Semantic name remains unreviewed. */

int FUN_c04f8234(undefined2 *param_1,int *param_2,undefined2 *param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_c04f62d8(param_1,param_2,param_3);
  if (iVar1 == 0) {
    iVar1 = *(int *)(param_3 + 0xc);
    if (iVar1 == 0) {
      uVar2 = 0;
    }
    else {
      uVar2 = *(undefined4 *)(param_3 + 0xe);
    }
    *(int *)(param_1 + 0xc) = iVar1;
    *(undefined4 *)(param_1 + 0xe) = uVar2;
    FUN_c04f23b0(param_2,iVar1,*(int *)(param_3 + 0xe),(int *)(param_1 + 0xc));
    iVar1 = 0;
  }
  return iVar1;
}



/* c04f82bc FUN_c04f82bc */

/* Boundary evidence: original MIPS .pdata c04f82bc..c04f8343. Semantic name remains unreviewed. */

int FUN_c04f82bc(undefined2 *param_1,int *param_2,undefined2 *param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_c04f6334(param_1,param_2,param_3);
  if (iVar1 == 0) {
    iVar1 = *(int *)(param_3 + 0x14);
    if (iVar1 == 0) {
      uVar2 = 0;
    }
    else {
      uVar2 = *(undefined4 *)(param_3 + 0x16);
    }
    *(int *)(param_1 + 0x14) = iVar1;
    *(undefined4 *)(param_1 + 0x16) = uVar2;
    FUN_c04f27c4(param_2,iVar1,*(int *)(param_3 + 0x16),(int *)(param_1 + 0x14));
    iVar1 = 0;
  }
  return iVar1;
}



/* c04f8344 FUN_c04f8344 */

/* Boundary evidence: original MIPS .pdata c04f8344..c04f83cb. Semantic name remains unreviewed. */

int FUN_c04f8344(undefined2 *param_1,int *param_2,undefined2 *param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_c04f63bc(param_1,param_2,param_3);
  if (iVar1 == 0) {
    iVar1 = *(int *)(param_3 + 0x14);
    if (iVar1 == 0) {
      uVar2 = 0;
    }
    else {
      uVar2 = *(undefined4 *)(param_3 + 0x16);
    }
    *(int *)(param_1 + 0x14) = iVar1;
    *(undefined4 *)(param_1 + 0x16) = uVar2;
    FUN_c04f27c4(param_2,iVar1,*(int *)(param_3 + 0x16),(int *)(param_1 + 0x14));
    iVar1 = 0;
  }
  return iVar1;
}



/* c04f83cc FUN_c04f83cc */

/* Boundary evidence: original MIPS .pdata c04f83cc..c04f8467. Semantic name remains unreviewed. */

int FUN_c04f83cc(undefined4 param_1,undefined2 *param_2,undefined4 *param_3)

{
  int iVar1;
  undefined **local_38;
  undefined4 local_34;
  undefined2 auStack_30 [12];
  uint local_18;
  
  local_18 = DAT_c04ff0b4;
  local_34 = 0;
  local_38 = &PTR_LAB_c04f1054;
  FUN_c04f10a4((int *)&local_38,0x18,(int *)0x0);
  iVar1 = FUN_c04f5b00(auStack_30,(int *)&local_38,param_2);
  if (iVar1 == 0) {
    *param_3 = local_34;
    FUN_c04fe38c(local_18);
    iVar1 = 0;
  }
  else {
    FUN_c04fe38c(local_18);
  }
  return iVar1;
}



/* c04f8468 FUN_c04f8468 */

/* Boundary evidence: original MIPS .pdata c04f8468..c04f8503. Semantic name remains unreviewed. */

int FUN_c04f8468(undefined4 param_1,undefined2 *param_2,undefined4 *param_3)

{
  int iVar1;
  undefined **local_38;
  undefined4 local_34;
  undefined2 auStack_30 [14];
  uint local_14;
  
  local_14 = DAT_c04ff0b4;
  local_34 = 0;
  local_38 = &PTR_LAB_c04f1054;
  FUN_c04f10a4((int *)&local_38,0x1c,(int *)0x0);
  iVar1 = FUN_c04f7824(auStack_30,(int *)&local_38,param_2);
  if (iVar1 == 0) {
    *param_3 = local_34;
    FUN_c04fe38c(local_14);
    iVar1 = 0;
  }
  else {
    FUN_c04fe38c(local_14);
  }
  return iVar1;
}



/* c04f8504 FUN_c04f8504 */

/* Boundary evidence: original MIPS .pdata c04f8504..c04f859f. Semantic name remains unreviewed. */

int FUN_c04f8504(undefined4 param_1,undefined2 *param_2,undefined4 *param_3)

{
  int iVar1;
  undefined **local_40;
  undefined4 local_3c;
  undefined2 auStack_38 [16];
  uint local_18;
  
  local_18 = DAT_c04ff0b4;
  local_3c = 0;
  local_40 = &PTR_LAB_c04f1054;
  FUN_c04f10a4((int *)&local_40,0x20,(int *)0x0);
  iVar1 = FUN_c04f7898(auStack_38,(int *)&local_40,param_2);
  if (iVar1 == 0) {
    *param_3 = local_3c;
    FUN_c04fe38c(local_18);
    iVar1 = 0;
  }
  else {
    FUN_c04fe38c(local_18);
  }
  return iVar1;
}



/* c04f85a0 FUN_c04f85a0 */

/* Boundary evidence: original MIPS .pdata c04f85a0..c04f863b. Semantic name remains unreviewed. */

int FUN_c04f85a0(undefined4 param_1,undefined2 *param_2,undefined4 *param_3)

{
  int iVar1;
  undefined **local_40;
  undefined4 local_3c;
  undefined2 auStack_38 [16];
  uint local_18;
  
  local_18 = DAT_c04ff0b4;
  local_3c = 0;
  local_40 = &PTR_LAB_c04f1054;
  FUN_c04f10a4((int *)&local_40,0x20,(int *)0x0);
  iVar1 = FUN_c04f78f4(auStack_38,(int *)&local_40,param_2);
  if (iVar1 == 0) {
    *param_3 = local_3c;
    FUN_c04fe38c(local_18);
    iVar1 = 0;
  }
  else {
    FUN_c04fe38c(local_18);
  }
  return iVar1;
}



/* c04f863c FUN_c04f863c */

/* Boundary evidence: original MIPS .pdata c04f863c..c04f86d7. Semantic name remains unreviewed. */

int FUN_c04f863c(undefined4 param_1,undefined2 *param_2,undefined4 *param_3)

{
  int iVar1;
  undefined **local_40;
  undefined4 local_3c;
  undefined2 auStack_38 [18];
  uint local_14;
  
  local_14 = DAT_c04ff0b4;
  local_3c = 0;
  local_40 = &PTR_LAB_c04f1054;
  FUN_c04f10a4((int *)&local_40,0x24,(int *)0x0);
  iVar1 = FUN_c04f5bf4(auStack_38,(int *)&local_40,param_2);
  if (iVar1 == 0) {
    *param_3 = local_3c;
    FUN_c04fe38c(local_14);
    iVar1 = 0;
  }
  else {
    FUN_c04fe38c(local_14);
  }
  return iVar1;
}



/* c04f86d8 FUN_c04f86d8 */

/* Boundary evidence: original MIPS .pdata c04f86d8..c04f8773. Semantic name remains unreviewed. */

int FUN_c04f86d8(undefined4 param_1,undefined2 *param_2,undefined4 *param_3)

{
  int iVar1;
  undefined **local_40;
  undefined4 local_3c;
  undefined2 auStack_38 [18];
  uint local_14;
  
  local_14 = DAT_c04ff0b4;
  local_3c = 0;
  local_40 = &PTR_LAB_c04f1054;
  FUN_c04f10a4((int *)&local_40,0x24,(int *)0x0);
  iVar1 = FUN_c04f7950(auStack_38,(int *)&local_40,param_2);
  if (iVar1 == 0) {
    *param_3 = local_3c;
    FUN_c04fe38c(local_14);
    iVar1 = 0;
  }
  else {
    FUN_c04fe38c(local_14);
  }
  return iVar1;
}



/* c04f8774 FUN_c04f8774 */

/* Boundary evidence: original MIPS .pdata c04f8774..c04f880f. Semantic name remains unreviewed. */

int FUN_c04f8774(undefined4 param_1,undefined2 *param_2,undefined4 *param_3)

{
  int iVar1;
  undefined **local_40;
  undefined4 local_3c;
  undefined2 auStack_38 [16];
  uint local_18;
  
  local_18 = DAT_c04ff0b4;
  local_3c = 0;
  local_40 = &PTR_LAB_c04f1054;
  FUN_c04f10a4((int *)&local_40,0x20,(int *)0x0);
  iVar1 = FUN_c04f79c4(auStack_38,(int *)&local_40,param_2);
  if (iVar1 == 0) {
    *param_3 = local_3c;
    FUN_c04fe38c(local_18);
    iVar1 = 0;
  }
  else {
    FUN_c04fe38c(local_18);
  }
  return iVar1;
}



/* c04f8810 WSACleanup */

/* Boundary evidence: original MIPS .pdata c04f8810..c04f886f. Semantic name remains unreviewed. */

int WSACleanup(void)

{
  int iVar1;
  int local_20 [2];
  undefined2 local_18 [2];
  undefined4 local_14;
  int *local_10;
  
                    /* 0x8810  4  WSACleanup */
  local_18[0] = 1;
  local_10 = local_20;
  local_14 = DAT_c04ff0a0;
  iVar1 = FUN_c04f5130(&PTR_PTR_c04ff09c,local_18);
  if (iVar1 != 0) {
    SetLastError(0x271d);
    local_20[0] = -1;
  }
  return local_20[0];
}



/* c04f8870 closesocket */

/* Boundary evidence: original MIPS .pdata c04f8870..c04f88d7. Semantic name remains unreviewed. */

int closesocket(SOCKET s)

{
  int iVar1;
  int local_20 [2];
  undefined2 local_18 [2];
  undefined4 local_14;
  int *local_10;
  SOCKET local_c;
  
                    /* 0x8870  36  closesocket */
  local_18[0] = 5;
  local_10 = local_20;
  local_14 = DAT_c04ff0a0;
  local_c = s;
  iVar1 = FUN_c04f5238(&PTR_PTR_c04ff09c,local_18);
  if (iVar1 != 0) {
    SetLastError(0x271d);
    local_20[0] = -1;
  }
  return local_20[0];
}



/* c04f88d8 listen */

/* Boundary evidence: original MIPS .pdata c04f88d8..c04f8943. Semantic name remains unreviewed. */

int listen(SOCKET s,int backlog)

{
  int iVar1;
  int local_28 [2];
  undefined2 local_20 [2];
  undefined4 local_1c;
  int *local_18;
  SOCKET local_14;
  int local_10;
  
                    /* 0x88d8  56  listen */
  local_20[0] = 9;
  local_18 = local_28;
  local_1c = DAT_c04ff0a0;
  local_14 = s;
  local_10 = backlog;
  iVar1 = FUN_c04f5350(&PTR_PTR_c04ff09c,local_20);
  if (iVar1 != 0) {
    SetLastError(0x271d);
    local_28[0] = -1;
  }
  return local_28[0];
}



/* c04f8944 shutdown */

/* Boundary evidence: original MIPS .pdata c04f8944..c04f89af. Semantic name remains unreviewed. */

int shutdown(SOCKET s,int how)

{
  int iVar1;
  int local_28 [2];
  undefined2 local_20 [2];
  undefined4 local_1c;
  int *local_18;
  SOCKET local_14;
  int local_10;
  
                    /* 0x8944  66  shutdown */
  local_20[0] = 0x10;
  local_18 = local_28;
  local_1c = DAT_c04ff0a0;
  local_14 = s;
  local_10 = how;
  iVar1 = FUN_c04f5350(&PTR_PTR_c04ff09c,local_20);
  if (iVar1 != 0) {
    SetLastError(0x271d);
    local_28[0] = -1;
  }
  return local_28[0];
}



/* c04f89b0 FUN_c04f89b0 */

/* Boundary evidence: original MIPS .pdata c04f89b0..c04f8ac7. Semantic name remains unreviewed. */

int FUN_c04f89b0(undefined4 *param_1,undefined2 *param_2)

{
  int iVar1;
  int *piVar2;
  undefined2 *puVar3;
  uint local_28 [2];
  
  iVar1 = FUN_c04f83cc(param_1,param_2,local_28);
  if (iVar1 == 0) {
    piVar2 = FUN_c04f50a8(local_28[0]);
    if (piVar2 == (int *)0x0) {
      iVar1 = 0xe;
    }
    else {
      FUN_c04f10a4(piVar2,0x18,(int *)0x0);
      puVar3 = (undefined2 *)piVar2[2];
      iVar1 = FUN_c04f5b00(puVar3,piVar2,param_2);
      if (iVar1 == 0) {
        *(undefined4 *)(puVar3 + 10) = *(undefined4 *)(param_2 + 10);
        iVar1 = (**(code **)*param_1)(param_1,puVar3,local_28[0]);
        FUN_c04f2a20((int)param_2,piVar2,(int)puVar3);
      }
      if ((void *)piVar2[2] != (void *)0x0) {
        operator_delete((void *)piVar2[2]);
      }
      operator_delete(piVar2);
    }
  }
  else {
    iVar1 = 0x57;
  }
  return iVar1;
}



/* c04f8ac8 FUN_c04f8ac8 */

/* Boundary evidence: original MIPS .pdata c04f8ac8..c04f8bcf. Semantic name remains unreviewed. */

int FUN_c04f8ac8(undefined4 *param_1,undefined2 *param_2)

{
  int iVar1;
  int *piVar2;
  undefined2 *puVar3;
  uint local_28 [2];
  
  iVar1 = FUN_c04f8468(param_1,param_2,local_28);
  if (iVar1 == 0) {
    piVar2 = FUN_c04f50a8(local_28[0]);
    if (piVar2 == (int *)0x0) {
      iVar1 = 0xe;
    }
    else {
      FUN_c04f10a4(piVar2,0x1c,(int *)0x0);
      puVar3 = (undefined2 *)piVar2[2];
      iVar1 = FUN_c04f7824(puVar3,piVar2,param_2);
      if (iVar1 == 0) {
        iVar1 = (**(code **)*param_1)(param_1,puVar3,local_28[0]);
        FUN_c04f3ec4((int)param_2,piVar2,(int)puVar3);
      }
      if ((void *)piVar2[2] != (void *)0x0) {
        operator_delete((void *)piVar2[2]);
      }
      operator_delete(piVar2);
    }
  }
  else {
    iVar1 = 0x57;
  }
  return iVar1;
}



/* c04f8bd0 FUN_c04f8bd0 */

/* Boundary evidence: original MIPS .pdata c04f8bd0..c04f8cd7. Semantic name remains unreviewed. */

int FUN_c04f8bd0(undefined4 *param_1,undefined2 *param_2)

{
  int iVar1;
  int *piVar2;
  undefined2 *puVar3;
  uint local_28 [2];
  
  iVar1 = FUN_c04f8504(param_1,param_2,local_28);
  if (iVar1 == 0) {
    piVar2 = FUN_c04f50a8(local_28[0]);
    if (piVar2 == (int *)0x0) {
      iVar1 = 0xe;
    }
    else {
      FUN_c04f10a4(piVar2,0x20,(int *)0x0);
      puVar3 = (undefined2 *)piVar2[2];
      iVar1 = FUN_c04f7898(puVar3,piVar2,param_2);
      if (iVar1 == 0) {
        iVar1 = (**(code **)*param_1)(param_1,puVar3,local_28[0]);
        FUN_c04f2f98((int)param_2,piVar2,(int)puVar3);
      }
      if ((void *)piVar2[2] != (void *)0x0) {
        operator_delete((void *)piVar2[2]);
      }
      operator_delete(piVar2);
    }
  }
  else {
    iVar1 = 0x57;
  }
  return iVar1;
}



/* c04f8cd8 FUN_c04f8cd8 */

/* Boundary evidence: original MIPS .pdata c04f8cd8..c04f8ddf. Semantic name remains unreviewed. */

int FUN_c04f8cd8(undefined4 *param_1,undefined2 *param_2)

{
  int iVar1;
  int *piVar2;
  undefined2 *puVar3;
  uint local_28 [2];
  
  iVar1 = FUN_c04f85a0(param_1,param_2,local_28);
  if (iVar1 == 0) {
    piVar2 = FUN_c04f50a8(local_28[0]);
    if (piVar2 == (int *)0x0) {
      iVar1 = 0xe;
    }
    else {
      FUN_c04f10a4(piVar2,0x20,(int *)0x0);
      puVar3 = (undefined2 *)piVar2[2];
      iVar1 = FUN_c04f78f4(puVar3,piVar2,param_2);
      if (iVar1 == 0) {
        iVar1 = (**(code **)*param_1)(param_1,puVar3,local_28[0]);
        FUN_c04f3020((int)param_2,piVar2,(int)puVar3);
      }
      if ((void *)piVar2[2] != (void *)0x0) {
        operator_delete((void *)piVar2[2]);
      }
      operator_delete(piVar2);
    }
  }
  else {
    iVar1 = 0x57;
  }
  return iVar1;
}



/* c04f8de0 FUN_c04f8de0 */

/* Boundary evidence: original MIPS .pdata c04f8de0..c04f8ef7. Semantic name remains unreviewed. */

int FUN_c04f8de0(undefined4 *param_1,undefined2 *param_2)

{
  int iVar1;
  int *piVar2;
  undefined2 *puVar3;
  uint local_28 [2];
  
  iVar1 = FUN_c04f863c(param_1,param_2,local_28);
  if (iVar1 == 0) {
    piVar2 = FUN_c04f50a8(local_28[0]);
    if (piVar2 == (int *)0x0) {
      iVar1 = 0xe;
    }
    else {
      FUN_c04f10a4(piVar2,0x24,(int *)0x0);
      puVar3 = (undefined2 *)piVar2[2];
      iVar1 = FUN_c04f5bf4(puVar3,piVar2,param_2);
      if (iVar1 == 0) {
        *(undefined4 *)(puVar3 + 0x10) = *(undefined4 *)(param_2 + 0x10);
        iVar1 = (**(code **)*param_1)(param_1,puVar3,local_28[0]);
        FUN_c04f3a78((int)param_2,piVar2,(int)puVar3);
      }
      if ((void *)piVar2[2] != (void *)0x0) {
        operator_delete((void *)piVar2[2]);
      }
      operator_delete(piVar2);
    }
  }
  else {
    iVar1 = 0x57;
  }
  return iVar1;
}



/* c04f8ef8 FUN_c04f8ef8 */

/* Boundary evidence: original MIPS .pdata c04f8ef8..c04f8fff. Semantic name remains unreviewed. */

int FUN_c04f8ef8(undefined4 *param_1,undefined2 *param_2)

{
  int iVar1;
  int *piVar2;
  undefined2 *puVar3;
  uint local_28 [2];
  
  iVar1 = FUN_c04f86d8(param_1,param_2,local_28);
  if (iVar1 == 0) {
    piVar2 = FUN_c04f50a8(local_28[0]);
    if (piVar2 == (int *)0x0) {
      iVar1 = 0xe;
    }
    else {
      FUN_c04f10a4(piVar2,0x24,(int *)0x0);
      puVar3 = (undefined2 *)piVar2[2];
      iVar1 = FUN_c04f7950(puVar3,piVar2,param_2);
      if (iVar1 == 0) {
        iVar1 = (**(code **)*param_1)(param_1,puVar3,local_28[0]);
        FUN_c04f3fb0((int)param_2,piVar2,(int)puVar3);
      }
      if ((void *)piVar2[2] != (void *)0x0) {
        operator_delete((void *)piVar2[2]);
      }
      operator_delete(piVar2);
    }
  }
  else {
    iVar1 = 0x57;
  }
  return iVar1;
}



/* c04f9000 FUN_c04f9000 */

/* Boundary evidence: original MIPS .pdata c04f9000..c04f9107. Semantic name remains unreviewed. */

int FUN_c04f9000(undefined4 *param_1,undefined2 *param_2)

{
  int iVar1;
  int *piVar2;
  undefined2 *puVar3;
  uint local_28 [2];
  
  iVar1 = FUN_c04f8774(param_1,param_2,local_28);
  if (iVar1 == 0) {
    piVar2 = FUN_c04f50a8(local_28[0]);
    if (piVar2 == (int *)0x0) {
      iVar1 = 0xe;
    }
    else {
      FUN_c04f10a4(piVar2,0x20,(int *)0x0);
      puVar3 = (undefined2 *)piVar2[2];
      iVar1 = FUN_c04f79c4(puVar3,piVar2,param_2);
      if (iVar1 == 0) {
        iVar1 = (**(code **)*param_1)(param_1,puVar3,local_28[0]);
        FUN_c04f4040((int)param_2,piVar2,(int)puVar3);
      }
      if ((void *)piVar2[2] != (void *)0x0) {
        operator_delete((void *)piVar2[2]);
      }
      operator_delete(piVar2);
    }
  }
  else {
    iVar1 = 0x57;
  }
  return iVar1;
}



/* c04f9108 FUN_c04f9108 */

/* Boundary evidence: original MIPS .pdata c04f9108..c04f917b. Semantic name remains unreviewed. */

int FUN_c04f9108(undefined2 *param_1,int *param_2,undefined2 *param_3)

{
  int iVar1;
  
  iVar1 = FUN_c04f7b60(param_1,param_2,param_3);
  if (iVar1 == 0) {
    iVar1 = *(int *)(param_3 + 0x14);
    *(int *)(param_1 + 0x14) = iVar1;
    if (iVar1 != 0) {
      FUN_c04f2260(param_2,*(undefined4 *)(param_3 + 0x14),4,(int *)(param_1 + 0x14));
    }
    iVar1 = 0;
  }
  return iVar1;
}



/* c04f917c FUN_c04f917c */

/* Boundary evidence: original MIPS .pdata c04f917c..c04f91ef. Semantic name remains unreviewed. */

int FUN_c04f917c(undefined2 *param_1,int *param_2,undefined2 *param_3)

{
  int iVar1;
  
  iVar1 = FUN_c04f7be8(param_1,param_2,param_3);
  if (iVar1 == 0) {
    iVar1 = *(int *)(param_3 + 0x12);
    *(int *)(param_1 + 0x12) = iVar1;
    if (iVar1 != 0) {
      FUN_c04f2308(param_2,*(undefined4 *)(param_3 + 0x12),8,(int *)(param_1 + 0x12));
    }
    iVar1 = 0;
  }
  return iVar1;
}



/* c04f91f0 FUN_c04f91f0 */

/* Boundary evidence: original MIPS .pdata c04f91f0..c04f9277. Semantic name remains unreviewed. */

int FUN_c04f91f0(undefined2 *param_1,int *param_2,undefined2 *param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_c04f7cd4(param_1,param_2,param_3);
  if (iVar1 == 0) {
    iVar1 = *(int *)(param_3 + 0xe);
    if (iVar1 == 0) {
      uVar2 = 0;
    }
    else {
      uVar2 = *(undefined4 *)(param_3 + 0x10);
    }
    *(int *)(param_1 + 0xe) = iVar1;
    *(undefined4 *)(param_1 + 0x10) = uVar2;
    FUN_c04f23b0(param_2,iVar1,*(int *)(param_3 + 0x10),(int *)(param_1 + 0xe));
    iVar1 = 0;
  }
  return iVar1;
}



/* c04f9278 FUN_c04f9278 */

/* Boundary evidence: original MIPS .pdata c04f9278..c04f9307. Semantic name remains unreviewed. */

int FUN_c04f9278(int param_1,undefined4 *param_2,int param_3)

{
  int iVar1;
  undefined4 *puVar2;
  
  iVar1 = FUN_c04f7d30(param_1,param_2,param_3);
  if (iVar1 == 0) {
    if (*(int *)(param_3 + 0x2c) == 0) {
      puVar2 = (undefined4 *)0x0;
    }
    else {
      puVar2 = (undefined4 *)(**(code **)*param_2)(param_2,*(int *)(param_3 + 0x2c),4);
    }
    if (*(undefined4 **)(param_1 + 0x2c) != (undefined4 *)0x0) {
      **(undefined4 **)(param_1 + 0x2c) = *puVar2;
    }
    iVar1 = 0;
  }
  return iVar1;
}



/* c04f9308 FUN_c04f9308 */

/* Boundary evidence: original MIPS .pdata c04f9308..c04f937b. Semantic name remains unreviewed. */

int FUN_c04f9308(undefined2 *param_1,int *param_2,undefined2 *param_3)

{
  int iVar1;
  
  iVar1 = FUN_c04f7dc8(param_1,param_2,param_3);
  if (iVar1 == 0) {
    iVar1 = *(int *)(param_3 + 0x12);
    *(int *)(param_1 + 0x12) = iVar1;
    if (iVar1 != 0) {
      FUN_c04f2260(param_2,*(undefined4 *)(param_3 + 0x12),4,(int *)(param_1 + 0x12));
    }
    iVar1 = 0;
  }
  return iVar1;
}



/* c04f937c FUN_c04f937c */

/* Boundary evidence: original MIPS .pdata c04f937c..c04f940b. Semantic name remains unreviewed. */

int FUN_c04f937c(int param_1,undefined4 *param_2,int param_3)

{
  int iVar1;
  undefined4 *puVar2;
  
  iVar1 = FUN_c04f7e50(param_1,param_2,param_3);
  if (iVar1 == 0) {
    if (*(int *)(param_3 + 0x24) == 0) {
      puVar2 = (undefined4 *)0x0;
    }
    else {
      puVar2 = (undefined4 *)(**(code **)*param_2)(param_2,*(int *)(param_3 + 0x24),4);
    }
    if (*(undefined4 **)(param_1 + 0x24) != (undefined4 *)0x0) {
      **(undefined4 **)(param_1 + 0x24) = *puVar2;
    }
    iVar1 = 0;
  }
  return iVar1;
}



/* c04f940c FUN_c04f940c */

/* Boundary evidence: original MIPS .pdata c04f940c..c04f94a3. Semantic name remains unreviewed. */

int FUN_c04f940c(int param_1,undefined4 *param_2,int param_3)

{
  int iVar1;
  int *piVar2;
  size_t sVar3;
  int aiStack_18 [2];
  
  iVar1 = FUN_c04f7f80(param_1,param_2,param_3);
  if (iVar1 == 0) {
    piVar2 = FUN_c04f1c5c((undefined4 *)(param_3 + 0x2c),aiStack_18,param_2);
    if ((void *)*piVar2 == (void *)0x0) {
      sVar3 = 0;
    }
    else {
      sVar3 = piVar2[1];
    }
    if (*(size_t *)(param_1 + 0x30) == sVar3) {
      memcpy(*(void **)(param_1 + 0x2c),(void *)*piVar2,*(size_t *)(param_1 + 0x30));
      iVar1 = 0;
    }
    else {
      iVar1 = 0x57;
    }
  }
  return iVar1;
}



/* c04f94a4 FUN_c04f94a4 */

/* Boundary evidence: original MIPS .pdata c04f94a4..c04f9533. Semantic name remains unreviewed. */

int FUN_c04f94a4(int param_1,undefined4 *param_2,int param_3)

{
  int iVar1;
  undefined4 *puVar2;
  
  iVar1 = FUN_c04f6108(param_1,param_2,param_3);
  if (iVar1 == 0) {
    if (*(int *)(param_3 + 0x3c) == 0) {
      puVar2 = (undefined4 *)0x0;
    }
    else {
      puVar2 = (undefined4 *)(**(code **)*param_2)(param_2,*(int *)(param_3 + 0x3c),4);
    }
    if (*(undefined4 **)(param_1 + 0x3c) != (undefined4 *)0x0) {
      **(undefined4 **)(param_1 + 0x3c) = *puVar2;
    }
    iVar1 = 0;
  }
  return iVar1;
}



/* c04f9534 FUN_c04f9534 */

/* Boundary evidence: original MIPS .pdata c04f9534..c04f95c3. Semantic name remains unreviewed. */

int FUN_c04f9534(int param_1,undefined4 *param_2,int param_3)

{
  int iVar1;
  undefined4 *puVar2;
  
  iVar1 = FUN_c04f6190(param_1,param_2,param_3);
  if (iVar1 == 0) {
    if (*(int *)(param_3 + 0x3c) == 0) {
      puVar2 = (undefined4 *)0x0;
    }
    else {
      puVar2 = (undefined4 *)(**(code **)*param_2)(param_2,*(int *)(param_3 + 0x3c),4);
    }
    if (*(undefined4 **)(param_1 + 0x3c) != (undefined4 *)0x0) {
      **(undefined4 **)(param_1 + 0x3c) = *puVar2;
    }
    iVar1 = 0;
  }
  return iVar1;
}



/* c04f95c4 FUN_c04f95c4 */

/* Boundary evidence: original MIPS .pdata c04f95c4..c04f9627. Semantic name remains unreviewed. */

int FUN_c04f95c4(undefined2 *param_1,int *param_2,undefined2 *param_3)

{
  int iVar1;
  
  iVar1 = FUN_c04f8010(param_1,param_2,param_3);
  if (iVar1 == 0) {
    FUN_c04f2c38((int *)(param_1 + 0x10),param_2,(int *)(param_3 + 0x10));
    iVar1 = 0;
  }
  return iVar1;
}



/* c04f9628 FUN_c04f9628 */

/* Boundary evidence: original MIPS .pdata c04f9628..c04f96af. Semantic name remains unreviewed. */

int FUN_c04f9628(undefined2 *param_1,int *param_2,undefined2 *param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_c04f80a8(param_1,param_2,param_3);
  if (iVar1 == 0) {
    iVar1 = *(int *)(param_3 + 0xe);
    if (iVar1 == 0) {
      uVar2 = 0;
    }
    else {
      uVar2 = *(undefined4 *)(param_3 + 0x10);
    }
    *(int *)(param_1 + 0xe) = iVar1;
    *(undefined4 *)(param_1 + 0x10) = uVar2;
    FUN_c04f23b0(param_2,iVar1,*(int *)(param_3 + 0x10),(int *)(param_1 + 0xe));
    iVar1 = 0;
  }
  return iVar1;
}



/* c04f96b0 FUN_c04f96b0 */

/* Boundary evidence: original MIPS .pdata c04f96b0..c04f9747. Semantic name remains unreviewed. */

int FUN_c04f96b0(int param_1,undefined4 *param_2,int param_3)

{
  int iVar1;
  int *piVar2;
  size_t sVar3;
  int aiStack_18 [2];
  
  iVar1 = FUN_c04f8140(param_1,param_2,param_3);
  if (iVar1 == 0) {
    piVar2 = FUN_c04f1c5c((undefined4 *)(param_3 + 0x1c),aiStack_18,param_2);
    if ((void *)*piVar2 == (void *)0x0) {
      sVar3 = 0;
    }
    else {
      sVar3 = piVar2[1];
    }
    if (*(size_t *)(param_1 + 0x20) == sVar3) {
      memcpy(*(void **)(param_1 + 0x1c),(void *)*piVar2,*(size_t *)(param_1 + 0x20));
      iVar1 = 0;
    }
    else {
      iVar1 = 0x57;
    }
  }
  return iVar1;
}



/* c04f9748 FUN_c04f9748 */

/* Boundary evidence: original MIPS .pdata c04f9748..c04f97df. Semantic name remains unreviewed. */

int FUN_c04f9748(undefined2 *param_1,int *param_2,undefined2 *param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_c04f61e4(param_1,param_2,param_3);
  if (iVar1 == 0) {
    *(undefined4 *)(param_1 + 0x10) = *(undefined4 *)(param_3 + 0x10);
    iVar1 = *(int *)(param_3 + 0x12);
    if (iVar1 == 0) {
      uVar2 = 0;
    }
    else {
      uVar2 = *(undefined4 *)(param_3 + 0x14);
    }
    *(int *)(param_1 + 0x12) = iVar1;
    *(undefined4 *)(param_1 + 0x14) = uVar2;
    FUN_c04f27c4(param_2,iVar1,*(int *)(param_3 + 0x14),(int *)(param_1 + 0x12));
    iVar1 = 0;
  }
  return iVar1;
}



/* c04f97e0 FUN_c04f97e0 */

/* Boundary evidence: original MIPS .pdata c04f97e0..c04f9853. Semantic name remains unreviewed. */

int FUN_c04f97e0(undefined2 *param_1,int *param_2,undefined2 *param_3)

{
  int iVar1;
  
  iVar1 = FUN_c04f81ac(param_1,param_2,param_3);
  if (iVar1 == 0) {
    iVar1 = *(int *)(param_3 + 0x10);
    *(int *)(param_1 + 0x10) = iVar1;
    if (iVar1 != 0) {
      FUN_c04f23b0(param_2,*(undefined4 *)(param_3 + 0x10),4,(int *)(param_1 + 0x10));
    }
    iVar1 = 0;
  }
  return iVar1;
}



/* c04f9854 FUN_c04f9854 */

/* Boundary evidence: original MIPS .pdata c04f9854..c04f98db. Semantic name remains unreviewed. */

int FUN_c04f9854(undefined2 *param_1,int *param_2,undefined2 *param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_c04f8234(param_1,param_2,param_3);
  if (iVar1 == 0) {
    iVar1 = *(int *)(param_3 + 0x10);
    if (iVar1 == 0) {
      uVar2 = 0;
    }
    else {
      uVar2 = *(undefined4 *)(param_3 + 0x12);
    }
    *(int *)(param_1 + 0x10) = iVar1;
    *(undefined4 *)(param_1 + 0x12) = uVar2;
    FUN_c04f23b0(param_2,iVar1,*(int *)(param_3 + 0x12),(int *)(param_1 + 0x10));
    iVar1 = 0;
  }
  return iVar1;
}



/* c04f98dc FUN_c04f98dc */

/* Boundary evidence: original MIPS .pdata c04f98dc..c04f9963. Semantic name remains unreviewed. */

int FUN_c04f98dc(undefined2 *param_1,int *param_2,undefined2 *param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_c04f82bc(param_1,param_2,param_3);
  if (iVar1 == 0) {
    iVar1 = *(int *)(param_3 + 0x18);
    if (iVar1 == 0) {
      uVar2 = 0;
    }
    else {
      uVar2 = *(undefined4 *)(param_3 + 0x1a);
    }
    *(int *)(param_1 + 0x18) = iVar1;
    *(undefined4 *)(param_1 + 0x1a) = uVar2;
    FUN_c04f27c4(param_2,iVar1,*(int *)(param_3 + 0x1a),(int *)(param_1 + 0x18));
    iVar1 = 0;
  }
  return iVar1;
}



/* c04f9964 FUN_c04f9964 */

/* Boundary evidence: original MIPS .pdata c04f9964..c04f99eb. Semantic name remains unreviewed. */

int FUN_c04f9964(undefined2 *param_1,int *param_2,undefined2 *param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_c04f8344(param_1,param_2,param_3);
  if (iVar1 == 0) {
    iVar1 = *(int *)(param_3 + 0x18);
    if (iVar1 == 0) {
      uVar2 = 0;
    }
    else {
      uVar2 = *(undefined4 *)(param_3 + 0x1a);
    }
    *(int *)(param_1 + 0x18) = iVar1;
    *(undefined4 *)(param_1 + 0x1a) = uVar2;
    FUN_c04f27c4(param_2,iVar1,*(int *)(param_3 + 0x1a),(int *)(param_1 + 0x18));
    iVar1 = 0;
  }
  return iVar1;
}



/* c04f99ec FUN_c04f99ec */

/* Boundary evidence: original MIPS .pdata c04f99ec..c04f9a87. Semantic name remains unreviewed. */

int FUN_c04f99ec(undefined4 param_1,undefined2 *param_2,undefined4 *param_3)

{
  int iVar1;
  undefined **local_40;
  undefined4 local_3c;
  undefined2 auStack_38 [16];
  uint local_18;
  
  local_18 = DAT_c04ff0b4;
  local_3c = 0;
  local_40 = &PTR_LAB_c04f1054;
  FUN_c04f10a4((int *)&local_40,0x20,(int *)0x0);
  iVar1 = FUN_c04f7ac8(auStack_38,(int *)&local_40,param_2);
  if (iVar1 == 0) {
    *param_3 = local_3c;
    FUN_c04fe38c(local_18);
    iVar1 = 0;
  }
  else {
    FUN_c04fe38c(local_18);
  }
  return iVar1;
}



/* c04f9a88 FUN_c04f9a88 */

/* Boundary evidence: original MIPS .pdata c04f9a88..c04f9b23. Semantic name remains unreviewed. */

int FUN_c04f9a88(undefined4 param_1,undefined2 *param_2,undefined4 *param_3)

{
  int iVar1;
  undefined **local_48;
  undefined4 local_44;
  undefined2 auStack_40 [22];
  uint local_14;
  
  local_14 = DAT_c04ff0b4;
  local_44 = 0;
  local_48 = &PTR_LAB_c04f1054;
  FUN_c04f10a4((int *)&local_48,0x2c,(int *)0x0);
  iVar1 = FUN_c04f9108(auStack_40,(int *)&local_48,param_2);
  if (iVar1 == 0) {
    *param_3 = local_44;
    FUN_c04fe38c(local_14);
    iVar1 = 0;
  }
  else {
    FUN_c04fe38c(local_14);
  }
  return iVar1;
}



/* c04f9b24 FUN_c04f9b24 */

/* Boundary evidence: original MIPS .pdata c04f9b24..c04f9bbf. Semantic name remains unreviewed. */

int FUN_c04f9b24(undefined4 param_1,undefined2 *param_2,undefined4 *param_3)

{
  int iVar1;
  undefined **local_48;
  undefined4 local_44;
  undefined2 auStack_40 [20];
  uint local_18;
  
  local_18 = DAT_c04ff0b4;
  local_44 = 0;
  local_48 = &PTR_LAB_c04f1054;
  FUN_c04f10a4((int *)&local_48,0x28,(int *)0x0);
  iVar1 = FUN_c04f917c(auStack_40,(int *)&local_48,param_2);
  if (iVar1 == 0) {
    *param_3 = local_44;
    FUN_c04fe38c(local_18);
    iVar1 = 0;
  }
  else {
    FUN_c04fe38c(local_18);
  }
  return iVar1;
}



/* c04f9bc0 FUN_c04f9bc0 */

/* Boundary evidence: original MIPS .pdata c04f9bc0..c04f9c5b. Semantic name remains unreviewed. */

int FUN_c04f9bc0(undefined4 param_1,undefined2 *param_2,undefined4 *param_3)

{
  int iVar1;
  undefined **local_48;
  undefined4 local_44;
  undefined2 auStack_40 [22];
  uint local_14;
  
  local_14 = DAT_c04ff0b4;
  local_44 = 0;
  local_48 = &PTR_LAB_c04f1054;
  FUN_c04f10a4((int *)&local_48,0x2c,(int *)0x0);
  iVar1 = FUN_c04f7c4c(auStack_40,(int *)&local_48,param_2);
  if (iVar1 == 0) {
    *param_3 = local_44;
    FUN_c04fe38c(local_14);
    iVar1 = 0;
  }
  else {
    FUN_c04fe38c(local_14);
  }
  return iVar1;
}



/* c04f9c5c FUN_c04f9c5c */

/* Boundary evidence: original MIPS .pdata c04f9c5c..c04f9cf7. Semantic name remains unreviewed. */

int FUN_c04f9c5c(undefined4 param_1,undefined2 *param_2,undefined4 *param_3)

{
  int iVar1;
  undefined **local_40;
  undefined4 local_3c;
  undefined2 auStack_38 [18];
  uint local_14;
  
  local_14 = DAT_c04ff0b4;
  local_3c = 0;
  local_40 = &PTR_LAB_c04f1054;
  FUN_c04f10a4((int *)&local_40,0x24,(int *)0x0);
  iVar1 = FUN_c04f91f0(auStack_38,(int *)&local_40,param_2);
  if (iVar1 == 0) {
    *param_3 = local_3c;
    FUN_c04fe38c(local_14);
    iVar1 = 0;
  }
  else {
    FUN_c04fe38c(local_14);
  }
  return iVar1;
}



/* c04f9cf8 WSAStartup */

/* Boundary evidence: original MIPS .pdata c04f9cf8..c04f9d5f. Semantic name remains unreviewed. */

int WSAStartup(WORD wVersionRequired,LPWSADATA lpWSAData)

{
  int iVar1;
  int local_28 [2];
  undefined2 local_20 [2];
  undefined4 local_1c;
  int *local_18;
  WORD local_14;
  LPWSADATA local_10;
  undefined4 local_c;
  
                    /* 0x9cf8  30  WSAStartup */
  local_c = 400;
  if (lpWSAData == (LPWSADATA)0x0) {
    local_c = 0;
  }
  local_18 = local_28;
  local_20[0] = 0;
  local_1c = DAT_c04ff0a0;
  local_14 = wVersionRequired;
  local_10 = lpWSAData;
  iVar1 = FUN_c04f6b94(&PTR_PTR_c04ff09c,local_20);
  if (iVar1 != 0) {
    local_28[0] = 0x271d;
  }
  return local_28[0];
}



/* c04f9d60 connect */

/* Boundary evidence: original MIPS .pdata c04f9d60..c04f9ddf. Semantic name remains unreviewed. */

int connect(SOCKET s,sockaddr *name,int namelen)

{
  int iVar1;
  int local_30 [2];
  undefined2 local_28 [2];
  undefined4 local_24;
  int *local_20;
  SOCKET local_1c;
  sockaddr *local_18;
  int local_14;
  int local_10;
  
                    /* 0x9d60  37  connect */
  local_14 = namelen;
  if (name == (sockaddr *)0x0) {
    local_14 = 0;
  }
  local_28[0] = 6;
  local_20 = local_30;
  local_24 = DAT_c04ff0a0;
  local_1c = s;
  local_18 = name;
  local_10 = namelen;
  iVar1 = FUN_c04f6c9c(&PTR_PTR_c04ff09c,local_28);
  if (iVar1 != 0) {
    SetLastError(0x271d);
    local_30[0] = -1;
  }
  return local_30[0];
}



/* c04f9de0 gethostbyname */

/* Boundary evidence: original MIPS .pdata c04f9de0..c04f9ea3. Semantic name remains unreviewed. */

hostent * gethostbyname(char *name)

{
  LPVOID pvVar1;
  int iVar2;
  DWORD local_30 [2];
  undefined2 local_28 [2];
  undefined4 local_24;
  DWORD *local_20;
  char *local_1c;
  LPVOID local_18;
  undefined4 local_14;
  
                    /* 0x9de0  41  gethostbyname */
  pvVar1 = FUN_c04f1494();
  if (pvVar1 == (LPVOID)0x0) {
    local_30[0] = 0x2747;
  }
  else {
    local_28[0] = 0x14;
    local_20 = local_30;
    local_24 = DAT_c04ff0a0;
    local_14 = 0x450;
    local_1c = name;
    local_18 = pvVar1;
    iVar2 = FUN_c04f6db4(&PTR_PTR_c04ff09c,local_28);
    if (iVar2 != 0) {
      return (hostent *)0x0;
    }
    if (local_30[0] == 0) {
      FUN_c04f14f0((int *)((int)pvVar1 + 0x14));
      return (hostent *)((int)pvVar1 + 0x14);
    }
  }
  SetLastError(local_30[0]);
  return (hostent *)0x0;
}



/* c04f9ea4 gethostname */

/* Boundary evidence: original MIPS .pdata c04f9ea4..c04f9f1f. Semantic name remains unreviewed. */

int gethostname(char *name,int namelen)

{
  int iVar1;
  int local_28 [2];
  undefined2 local_20 [2];
  undefined4 local_1c;
  int *local_18;
  char *local_14;
  int local_10;
  int local_c;
  
                    /* 0x9ea4  42  gethostname */
  local_10 = namelen;
  if (name == (char *)0x0) {
    local_10 = 0;
  }
  local_20[0] = 0x15;
  local_18 = local_28;
  local_1c = DAT_c04ff0a0;
  local_14 = name;
  local_c = namelen;
  iVar1 = FUN_c04f6ebc(&PTR_PTR_c04ff09c,local_20);
  if (iVar1 != 0) {
    SetLastError(0x271d);
    local_28[0] = -1;
  }
  return local_28[0];
}



/* c04f9f20 getpeername */

/* Boundary evidence: original MIPS .pdata c04f9f20..c04f9fa3. Semantic name remains unreviewed. */

int getpeername(SOCKET s,sockaddr *name,int *namelen)

{
  int iVar1;
  int local_30 [2];
  undefined2 local_28 [2];
  undefined4 local_24;
  int *local_20;
  SOCKET local_1c;
  sockaddr *local_18;
  int local_14;
  int *local_10;
  
                    /* 0x9f20  44  getpeername */
  if (name == (sockaddr *)0x0) {
    local_14 = 0;
  }
  else {
    local_14 = *namelen;
  }
  local_28[0] = 0x17;
  local_20 = local_30;
  local_24 = DAT_c04ff0a0;
  local_1c = s;
  local_18 = name;
  local_10 = namelen;
  iVar1 = FUN_c04f6fd4(&PTR_PTR_c04ff09c,local_28);
  if (iVar1 != 0) {
    SetLastError(0x271d);
    local_30[0] = -1;
  }
  return local_30[0];
}



/* c04f9fa4 getsockname */

/* Boundary evidence: original MIPS .pdata c04f9fa4..c04fa027. Semantic name remains unreviewed. */

int getsockname(SOCKET s,sockaddr *name,int *namelen)

{
  int iVar1;
  int local_30 [2];
  undefined2 local_28 [2];
  undefined4 local_24;
  int *local_20;
  SOCKET local_1c;
  sockaddr *local_18;
  int local_14;
  int *local_10;
  
                    /* 0x9fa4  49  getsockname */
  if (name == (sockaddr *)0x0) {
    local_14 = 0;
  }
  else {
    local_14 = *namelen;
  }
  local_28[0] = 0x18;
  local_20 = local_30;
  local_24 = DAT_c04ff0a0;
  local_1c = s;
  local_18 = name;
  local_10 = namelen;
  iVar1 = FUN_c04f6fd4(&PTR_PTR_c04ff09c,local_28);
  if (iVar1 != 0) {
    SetLastError(0x271d);
    local_30[0] = -1;
  }
  return local_30[0];
}



/* c04fa028 ioctlsocket */

/* Boundary evidence: original MIPS .pdata c04fa028..c04fa0cf. Semantic name remains unreviewed. */

int ioctlsocket(SOCKET s,long cmd,u_long *argp)

{
  int iVar1;
  DWORD dwErrCode;
  u_long local_28 [2];
  undefined2 local_20 [2];
  undefined4 local_1c;
  u_long *local_18;
  SOCKET local_14;
  long local_10;
  u_long *local_c;
  
                    /* 0xa028  55  ioctlsocket */
  if ((cmd == -0x7ffb9982) || (cmd == 0x4004667f)) {
    local_28[0] = *argp;
    local_20[0] = 8;
    local_18 = local_28;
    local_1c = DAT_c04ff0a0;
    local_14 = s;
    local_10 = cmd;
    local_c = argp;
    iVar1 = FUN_c04f70dc(&PTR_PTR_c04ff09c,local_20);
    if (iVar1 == 0) {
      return local_28[0];
    }
    dwErrCode = 0x271d;
  }
  else {
    dwErrCode = 0x273a;
  }
  SetLastError(dwErrCode);
  return -1;
}



/* c04fa0d0 sethostname */

/* Boundary evidence: original MIPS .pdata c04fa0d0..c04fa14b. Semantic name remains unreviewed. */

undefined4 sethostname(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 local_28 [2];
  undefined2 local_20 [2];
  undefined4 local_1c;
  undefined4 *local_18;
  int local_14;
  undefined4 local_10;
  undefined4 local_c;
  
                    /* 0xa0d0  64  sethostname */
  local_10 = param_2;
  if (param_1 == 0) {
    local_10 = 0;
  }
  local_20[0] = 0x19;
  local_18 = local_28;
  local_1c = DAT_c04ff0a0;
  local_14 = param_1;
  local_c = param_2;
  iVar1 = FUN_c04f71e4(&PTR_PTR_c04ff09c,local_20);
  if (iVar1 != 0) {
    SetLastError(0x271d);
    local_28[0] = 0xffffffff;
  }
  return local_28[0];
}



/* c04fa14c WSAConnect */

/* Boundary evidence: original MIPS .pdata c04fa14c..c04fa1af. Semantic name remains unreviewed. */

int WSAConnect(SOCKET param_1,sockaddr *param_2,int param_3,int param_4,int param_5,int param_6,
              int param_7)

{
  int iVar1;
  
                    /* 0xa14c  6  WSAConnect */
  if ((((param_4 == 0) && (param_5 == 0)) && (param_6 == 0)) && (param_7 == 0)) {
    iVar1 = connect(param_1,param_2,param_3);
  }
  else {
    SetLastError(0x273d);
    iVar1 = -1;
  }
  return iVar1;
}



/* c04fa1b0 WSAEnumNameSpaceProvidersW */

/* Boundary evidence: original MIPS .pdata c04fa1b0..c04fa273. Semantic name remains unreviewed. */

void WSAEnumNameSpaceProvidersW(undefined4 *param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  int local_30 [2];
  undefined2 local_28 [2];
  undefined4 local_24;
  int *local_20;
  undefined4 *local_1c;
  int local_18;
  undefined4 local_14;
  
                    /* 0xa1b0  9  WSAEnumNameSpaceProvidersW */
  if (param_2 == 0) {
    local_14 = 0;
  }
  else {
    local_14 = *param_1;
  }
  local_28[0] = 0x1f;
  local_20 = local_30;
  local_24 = DAT_c04ff0a0;
  local_1c = param_1;
  local_18 = param_2;
  iVar1 = FUN_c04f72fc(&PTR_PTR_c04ff09c,local_28);
  if (iVar1 != 0) {
    SetLastError(0x271d);
    local_30[0] = -1;
  }
  if ((local_30[0] != -1) && (local_30[0] != 0)) {
    piVar2 = (int *)(param_2 + 0x1c);
    do {
      *piVar2 = (int)piVar2 + *piVar2 + -0x1c;
      local_30[0] = local_30[0] + -1;
      piVar2 = piVar2 + 8;
    } while (local_30[0] != 0);
  }
  return;
}



/* c04fa274 WSAEnumNetworkEvents */

/* Boundary evidence: original MIPS .pdata c04fa274..c04fa31f. Semantic name remains unreviewed. */

undefined4 WSAEnumNetworkEvents(undefined4 param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  undefined4 local_38 [2];
  undefined2 local_30 [2];
  undefined4 local_2c;
  undefined4 *local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  int local_18;
  undefined4 local_14;
  
                    /* 0xa274  10  WSAEnumNetworkEvents */
  local_1c = __GetUserKData(0xc);
  local_14 = 0x2c;
  if (param_3 == 0) {
    local_14 = 0;
  }
  local_30[0] = 0x20;
  local_28 = local_38;
  local_2c = DAT_c04ff0a0;
  local_24 = param_1;
  local_20 = param_2;
  local_18 = param_3;
  iVar1 = FUN_c04f7404(&PTR_PTR_c04ff09c,local_30);
  if (iVar1 != 0) {
    SetLastError(0x271d);
    local_38[0] = 0xffffffff;
  }
  return local_38[0];
}



/* c04fa320 WSAEventSelect */

/* Boundary evidence: original MIPS .pdata c04fa320..c04fa3bb. Semantic name remains unreviewed. */

undefined4 WSAEventSelect(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 local_38 [2];
  undefined2 local_30 [2];
  undefined4 local_2c;
  undefined4 *local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  
                    /* 0xa320  12  WSAEventSelect */
  local_1c = __GetUserKData(0xc);
  local_30[0] = 0x22;
  local_28 = local_38;
  local_2c = DAT_c04ff0a0;
  local_24 = param_1;
  local_20 = param_2;
  local_18 = param_3;
  iVar1 = FUN_c04f750c(&PTR_PTR_c04ff09c,local_30);
  if (iVar1 != 0) {
    SetLastError(0x271d);
    local_38[0] = 0xffffffff;
  }
  return local_38[0];
}



/* c04fa3bc WSAHtonl */

/* Boundary evidence: original MIPS .pdata c04fa3bc..c04fa42b. Semantic name remains unreviewed. */

undefined4 WSAHtonl(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 local_28 [2];
  undefined2 local_20 [2];
  undefined4 local_1c;
  undefined4 *local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  
                    /* 0xa3bc  15  WSAHtonl */
  local_20[0] = 0x24;
  local_18 = local_28;
  local_1c = DAT_c04ff0a0;
  local_14 = param_1;
  local_10 = param_2;
  local_c = param_3;
  iVar1 = FUN_c04f7614(&PTR_PTR_c04ff09c,local_20);
  if (iVar1 != 0) {
    SetLastError(0x271d);
    local_28[0] = 0xffffffff;
  }
  return local_28[0];
}



/* c04fa42c WSAHtons */

/* Boundary evidence: original MIPS .pdata c04fa42c..c04fa49b. Semantic name remains unreviewed. */

undefined4 WSAHtons(undefined4 param_1,undefined2 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 local_28 [2];
  undefined2 local_20 [2];
  undefined4 local_1c;
  undefined4 *local_18;
  undefined4 local_14;
  undefined2 local_10;
  undefined4 local_c;
  
                    /* 0xa42c  16  WSAHtons */
  local_20[0] = 0x25;
  local_18 = local_28;
  local_1c = DAT_c04ff0a0;
  local_14 = param_1;
  local_10 = param_2;
  local_c = param_3;
  iVar1 = FUN_c04f771c(&PTR_PTR_c04ff09c,local_20);
  if (iVar1 != 0) {
    SetLastError(0x271d);
    local_28[0] = 0xffffffff;
  }
  return local_28[0];
}



/* c04fa49c WSANtohl */

/* Boundary evidence: original MIPS .pdata c04fa49c..c04fa50b. Semantic name remains unreviewed. */

undefined4 WSANtohl(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 local_28 [2];
  undefined2 local_20 [2];
  undefined4 local_1c;
  undefined4 *local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  
                    /* 0xa49c  19  WSANtohl */
  local_20[0] = 0x24;
  local_18 = local_28;
  local_1c = DAT_c04ff0a0;
  local_14 = param_1;
  local_10 = param_2;
  local_c = param_3;
  iVar1 = FUN_c04f7614(&PTR_PTR_c04ff09c,local_20);
  if (iVar1 != 0) {
    SetLastError(0x271d);
    local_28[0] = 0xffffffff;
  }
  return local_28[0];
}



/* c04fa50c WSANtohs */

/* Boundary evidence: original MIPS .pdata c04fa50c..c04fa57b. Semantic name remains unreviewed. */

undefined4 WSANtohs(undefined4 param_1,undefined2 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 local_28 [2];
  undefined2 local_20 [2];
  undefined4 local_1c;
  undefined4 *local_18;
  undefined4 local_14;
  undefined2 local_10;
  undefined4 local_c;
  
                    /* 0xa50c  20  WSANtohs */
  local_20[0] = 0x25;
  local_18 = local_28;
  local_1c = DAT_c04ff0a0;
  local_14 = param_1;
  local_10 = param_2;
  local_c = param_3;
  iVar1 = FUN_c04f771c(&PTR_PTR_c04ff09c,local_20);
  if (iVar1 != 0) {
    SetLastError(0x271d);
    local_28[0] = 0xffffffff;
  }
  return local_28[0];
}



/* c04fa57c FUN_c04fa57c */

/* Boundary evidence: original MIPS .pdata c04fa57c..c04fa693. Semantic name remains unreviewed. */

int FUN_c04fa57c(undefined4 *param_1,undefined2 *param_2)

{
  int iVar1;
  int *piVar2;
  undefined2 *puVar3;
  uint local_28 [2];
  
  iVar1 = FUN_c04f99ec(param_1,param_2,local_28);
  if (iVar1 == 0) {
    piVar2 = FUN_c04f50a8(local_28[0]);
    if (piVar2 == (int *)0x0) {
      iVar1 = 0xe;
    }
    else {
      FUN_c04f10a4(piVar2,0x20,(int *)0x0);
      puVar3 = (undefined2 *)piVar2[2];
      iVar1 = FUN_c04f7ac8(puVar3,piVar2,param_2);
      if (iVar1 == 0) {
        *(undefined4 *)(puVar3 + 0xe) = *(undefined4 *)(param_2 + 0xe);
        iVar1 = (**(code **)*param_1)(param_1,puVar3,local_28[0]);
        FUN_c04f40d0((int)param_2,piVar2,(int)puVar3);
      }
      if ((void *)piVar2[2] != (void *)0x0) {
        operator_delete((void *)piVar2[2]);
      }
      operator_delete(piVar2);
    }
  }
  else {
    iVar1 = 0x57;
  }
  return iVar1;
}



/* c04fa694 FUN_c04fa694 */

/* Boundary evidence: original MIPS .pdata c04fa694..c04fa79b. Semantic name remains unreviewed. */

int FUN_c04fa694(undefined4 *param_1,undefined2 *param_2)

{
  int iVar1;
  int *piVar2;
  undefined2 *puVar3;
  uint local_28 [2];
  
  iVar1 = FUN_c04f9a88(param_1,param_2,local_28);
  if (iVar1 == 0) {
    piVar2 = FUN_c04f50a8(local_28[0]);
    if (piVar2 == (int *)0x0) {
      iVar1 = 0xe;
    }
    else {
      FUN_c04f10a4(piVar2,0x2c,(int *)0x0);
      puVar3 = (undefined2 *)piVar2[2];
      iVar1 = FUN_c04f9108(puVar3,piVar2,param_2);
      if (iVar1 == 0) {
        iVar1 = (**(code **)*param_1)(param_1,puVar3,local_28[0]);
        FUN_c04f54f0((int)param_2,piVar2,(int)puVar3);
      }
      if ((void *)piVar2[2] != (void *)0x0) {
        operator_delete((void *)piVar2[2]);
      }
      operator_delete(piVar2);
    }
  }
  else {
    iVar1 = 0x57;
  }
  return iVar1;
}



/* c04fa79c FUN_c04fa79c */

/* Boundary evidence: original MIPS .pdata c04fa79c..c04fa8a3. Semantic name remains unreviewed. */

int FUN_c04fa79c(undefined4 *param_1,undefined2 *param_2)

{
  int iVar1;
  int *piVar2;
  undefined2 *puVar3;
  uint local_28 [2];
  
  iVar1 = FUN_c04f9b24(param_1,param_2,local_28);
  if (iVar1 == 0) {
    piVar2 = FUN_c04f50a8(local_28[0]);
    if (piVar2 == (int *)0x0) {
      iVar1 = 0xe;
    }
    else {
      FUN_c04f10a4(piVar2,0x28,(int *)0x0);
      puVar3 = (undefined2 *)piVar2[2];
      iVar1 = FUN_c04f917c(puVar3,piVar2,param_2);
      if (iVar1 == 0) {
        iVar1 = (**(code **)*param_1)(param_1,puVar3,local_28[0]);
        FUN_c04f5580((int)param_2,piVar2,(int)puVar3);
      }
      if ((void *)piVar2[2] != (void *)0x0) {
        operator_delete((void *)piVar2[2]);
      }
      operator_delete(piVar2);
    }
  }
  else {
    iVar1 = 0x57;
  }
  return iVar1;
}



/* c04fa8a4 FUN_c04fa8a4 */

/* Boundary evidence: original MIPS .pdata c04fa8a4..c04fa9bb. Semantic name remains unreviewed. */

int FUN_c04fa8a4(undefined4 *param_1,undefined2 *param_2)

{
  int iVar1;
  int *piVar2;
  undefined2 *puVar3;
  uint local_28 [2];
  
  iVar1 = FUN_c04f9bc0(param_1,param_2,local_28);
  if (iVar1 == 0) {
    piVar2 = FUN_c04f50a8(local_28[0]);
    if (piVar2 == (int *)0x0) {
      iVar1 = 0xe;
    }
    else {
      FUN_c04f10a4(piVar2,0x2c,(int *)0x0);
      puVar3 = (undefined2 *)piVar2[2];
      iVar1 = FUN_c04f7c4c(puVar3,piVar2,param_2);
      if (iVar1 == 0) {
        *(undefined4 *)(puVar3 + 0x14) = *(undefined4 *)(param_2 + 0x14);
        iVar1 = (**(code **)*param_1)(param_1,puVar3,local_28[0]);
        FUN_c04f42c0((int)param_2,piVar2,(int)puVar3);
      }
      if ((void *)piVar2[2] != (void *)0x0) {
        operator_delete((void *)piVar2[2]);
      }
      operator_delete(piVar2);
    }
  }
  else {
    iVar1 = 0x57;
  }
  return iVar1;
}



/* c04fa9bc FUN_c04fa9bc */

/* Boundary evidence: original MIPS .pdata c04fa9bc..c04faac3. Semantic name remains unreviewed. */

int FUN_c04fa9bc(undefined4 *param_1,undefined2 *param_2)

{
  int iVar1;
  int *piVar2;
  undefined2 *puVar3;
  uint local_28 [2];
  
  iVar1 = FUN_c04f9c5c(param_1,param_2,local_28);
  if (iVar1 == 0) {
    piVar2 = FUN_c04f50a8(local_28[0]);
    if (piVar2 == (int *)0x0) {
      iVar1 = 0xe;
    }
    else {
      FUN_c04f10a4(piVar2,0x24,(int *)0x0);
      puVar3 = (undefined2 *)piVar2[2];
      iVar1 = FUN_c04f91f0(puVar3,piVar2,param_2);
      if (iVar1 == 0) {
        iVar1 = (**(code **)*param_1)(param_1,puVar3,local_28[0]);
        FUN_c04f55e4((int)param_2,piVar2,(int)puVar3);
      }
      if ((void *)piVar2[2] != (void *)0x0) {
        operator_delete((void *)piVar2[2]);
      }
      operator_delete(piVar2);
    }
  }
  else {
    iVar1 = 0x57;
  }
  return iVar1;
}



/* c04faac4 FUN_c04faac4 */

/* Boundary evidence: original MIPS .pdata c04faac4..c04fab1f. Semantic name remains unreviewed. */

int FUN_c04faac4(undefined2 *param_1,int *param_2,undefined2 *param_3)

{
  int iVar1;
  
  iVar1 = FUN_c04f7ee8(param_1,param_2,param_3);
  if (iVar1 == 0) {
    *(undefined4 *)(param_1 + 0x10) = *(undefined4 *)(param_3 + 0x10);
    iVar1 = 0;
    *(undefined4 *)(param_1 + 0x12) = *(undefined4 *)(param_3 + 0x12);
  }
  return iVar1;
}



/* c04fab20 FUN_c04fab20 */

/* Boundary evidence: original MIPS .pdata c04fab20..c04fabaf. Semantic name remains unreviewed. */

int FUN_c04fab20(int param_1,undefined4 *param_2,int param_3)

{
  int iVar1;
  undefined4 *puVar2;
  
  iVar1 = FUN_c04f94a4(param_1,param_2,param_3);
  if (iVar1 == 0) {
    if (*(int *)(param_3 + 0x40) == 0) {
      puVar2 = (undefined4 *)0x0;
    }
    else {
      puVar2 = (undefined4 *)(**(code **)*param_2)(param_2,*(int *)(param_3 + 0x40),4);
    }
    if (*(undefined4 **)(param_1 + 0x40) != (undefined4 *)0x0) {
      **(undefined4 **)(param_1 + 0x40) = *puVar2;
    }
    iVar1 = 0;
  }
  return iVar1;
}



/* c04fabb0 FUN_c04fabb0 */

/* Boundary evidence: original MIPS .pdata c04fabb0..c04fac23. Semantic name remains unreviewed. */

int FUN_c04fabb0(undefined2 *param_1,int *param_2,undefined2 *param_3)

{
  int iVar1;
  
  iVar1 = FUN_c04f95c4(param_1,param_2,param_3);
  if (iVar1 == 0) {
    iVar1 = *(int *)(param_3 + 0x14);
    *(int *)(param_1 + 0x14) = iVar1;
    if (iVar1 != 0) {
      FUN_c04f23b0(param_2,*(undefined4 *)(param_3 + 0x14),4,(int *)(param_1 + 0x14));
    }
    iVar1 = 0;
  }
  return iVar1;
}



/* c04fac24 FUN_c04fac24 */

/* Boundary evidence: original MIPS .pdata c04fac24..c04fac97. Semantic name remains unreviewed. */

int FUN_c04fac24(undefined2 *param_1,int *param_2,undefined2 *param_3)

{
  int iVar1;
  
  iVar1 = FUN_c04f9628(param_1,param_2,param_3);
  if (iVar1 == 0) {
    iVar1 = *(int *)(param_3 + 0x12);
    *(int *)(param_1 + 0x12) = iVar1;
    if (iVar1 != 0) {
      FUN_c04f2260(param_2,*(undefined4 *)(param_3 + 0x12),4,(int *)(param_1 + 0x12));
    }
    iVar1 = 0;
  }
  return iVar1;
}



/* c04fac98 FUN_c04fac98 */

/* Boundary evidence: original MIPS .pdata c04fac98..c04fad27. Semantic name remains unreviewed. */

int FUN_c04fac98(int param_1,undefined4 *param_2,int param_3)

{
  int iVar1;
  undefined4 *puVar2;
  
  iVar1 = FUN_c04f96b0(param_1,param_2,param_3);
  if (iVar1 == 0) {
    if (*(int *)(param_3 + 0x24) == 0) {
      puVar2 = (undefined4 *)0x0;
    }
    else {
      puVar2 = (undefined4 *)(**(code **)*param_2)(param_2,*(int *)(param_3 + 0x24),4);
    }
    if (*(undefined4 **)(param_1 + 0x24) != (undefined4 *)0x0) {
      **(undefined4 **)(param_1 + 0x24) = *puVar2;
    }
    iVar1 = 0;
  }
  return iVar1;
}



/* c04fad28 FUN_c04fad28 */

/* Boundary evidence: original MIPS .pdata c04fad28..c04fadbf. Semantic name remains unreviewed. */

int FUN_c04fad28(int param_1,undefined4 *param_2,int param_3)

{
  int iVar1;
  int *piVar2;
  size_t sVar3;
  int aiStack_18 [2];
  
  iVar1 = FUN_c04fab20(param_1,param_2,param_3);
  if (iVar1 == 0) {
    piVar2 = FUN_c04f1c5c((undefined4 *)(param_3 + 0x44),aiStack_18,param_2);
    if ((void *)*piVar2 == (void *)0x0) {
      sVar3 = 0;
    }
    else {
      sVar3 = piVar2[1];
    }
    if (*(size_t *)(param_1 + 0x48) == sVar3) {
      memcpy(*(void **)(param_1 + 0x44),(void *)*piVar2,*(size_t *)(param_1 + 0x48));
      iVar1 = 0;
    }
    else {
      iVar1 = 0x57;
    }
  }
  return iVar1;
}



/* c04fadc0 FUN_c04fadc0 */

/* Boundary evidence: original MIPS .pdata c04fadc0..c04fae13. Semantic name remains unreviewed. */

int FUN_c04fadc0(int param_1,undefined4 *param_2,int param_3)

{
  int iVar1;
  int aiStack_18 [2];
  
  iVar1 = FUN_c04f9534(param_1,param_2,param_3);
  if (iVar1 == 0) {
    FUN_c04f1c5c((undefined4 *)(param_3 + 0x44),aiStack_18,param_2);
    iVar1 = 0;
  }
  return iVar1;
}



/* c04fae14 FUN_c04fae14 */

/* Boundary evidence: original MIPS .pdata c04fae14..c04fae9b. Semantic name remains unreviewed. */

int FUN_c04fae14(undefined2 *param_1,int *param_2,undefined2 *param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_c04f97e0(param_1,param_2,param_3);
  if (iVar1 == 0) {
    iVar1 = *(int *)(param_3 + 0x12);
    if (iVar1 == 0) {
      uVar2 = 0;
    }
    else {
      uVar2 = *(undefined4 *)(param_3 + 0x14);
    }
    *(int *)(param_1 + 0x12) = iVar1;
    *(undefined4 *)(param_1 + 0x14) = uVar2;
    FUN_c04f23b0(param_2,iVar1,*(int *)(param_3 + 0x14),(int *)(param_1 + 0x12));
    iVar1 = 0;
  }
  return iVar1;
}



/* c04fae9c FUN_c04fae9c */

/* Boundary evidence: original MIPS .pdata c04fae9c..c04faf0f. Semantic name remains unreviewed. */

int FUN_c04fae9c(undefined2 *param_1,int *param_2,undefined2 *param_3)

{
  int iVar1;
  
  iVar1 = FUN_c04f9854(param_1,param_2,param_3);
  if (iVar1 == 0) {
    iVar1 = *(int *)(param_3 + 0x14);
    *(int *)(param_1 + 0x14) = iVar1;
    if (iVar1 != 0) {
      FUN_c04f23b0(param_2,*(undefined4 *)(param_3 + 0x14),4,(int *)(param_1 + 0x14));
    }
    iVar1 = 0;
  }
  return iVar1;
}



/* c04faf10 FUN_c04faf10 */

/* Boundary evidence: original MIPS .pdata c04faf10..c04fafab. Semantic name remains unreviewed. */

int FUN_c04faf10(undefined4 param_1,undefined2 *param_2,undefined4 *param_3)

{
  int iVar1;
  undefined **local_48;
  undefined4 local_44;
  undefined2 auStack_40 [22];
  uint local_14;
  
  local_14 = DAT_c04ff0b4;
  local_44 = 0;
  local_48 = &PTR_LAB_c04f1054;
  FUN_c04f10a4((int *)&local_48,0x2c,(int *)0x0);
  iVar1 = FUN_c04f9308(auStack_40,(int *)&local_48,param_2);
  if (iVar1 == 0) {
    *param_3 = local_44;
    FUN_c04fe38c(local_14);
    iVar1 = 0;
  }
  else {
    FUN_c04fe38c(local_14);
  }
  return iVar1;
}



/* c04fafac FUN_c04fafac */

/* Boundary evidence: original MIPS .pdata c04fafac..c04fb047. Semantic name remains unreviewed. */

int FUN_c04fafac(undefined4 param_1,undefined2 *param_2,undefined4 *param_3)

{
  int iVar1;
  undefined **local_48;
  undefined4 local_44;
  undefined2 auStack_40 [20];
  uint local_18;
  
  local_18 = DAT_c04ff0b4;
  local_44 = 0;
  local_48 = &PTR_LAB_c04f1054;
  FUN_c04f10a4((int *)&local_48,0x28,(int *)0x0);
  iVar1 = FUN_c04faac4(auStack_40,(int *)&local_48,param_2);
  if (iVar1 == 0) {
    *param_3 = local_44;
    FUN_c04fe38c(local_18);
    iVar1 = 0;
  }
  else {
    FUN_c04fe38c(local_18);
  }
  return iVar1;
}



/* c04fb048 FUN_c04fb048 */

/* Boundary evidence: original MIPS .pdata c04fb048..c04fb0e3. Semantic name remains unreviewed. */

int FUN_c04fb048(undefined4 param_1,undefined2 *param_2,undefined4 *param_3)

{
  int iVar1;
  undefined **local_48;
  undefined4 local_44;
  undefined2 auStack_40 [22];
  uint local_14;
  
  local_14 = DAT_c04ff0b4;
  local_44 = 0;
  local_48 = &PTR_LAB_c04f1054;
  FUN_c04f10a4((int *)&local_48,0x2c,(int *)0x0);
  iVar1 = FUN_c04fabb0(auStack_40,(int *)&local_48,param_2);
  if (iVar1 == 0) {
    *param_3 = local_44;
    FUN_c04fe38c(local_14);
    iVar1 = 0;
  }
  else {
    FUN_c04fe38c(local_14);
  }
  return iVar1;
}



/* c04fb0e4 FUN_c04fb0e4 */

/* Boundary evidence: original MIPS .pdata c04fb0e4..c04fb17f. Semantic name remains unreviewed. */

int FUN_c04fb0e4(undefined4 param_1,undefined2 *param_2,undefined4 *param_3)

{
  int iVar1;
  undefined **local_48;
  undefined4 local_44;
  undefined2 auStack_40 [20];
  uint local_18;
  
  local_18 = DAT_c04ff0b4;
  local_44 = 0;
  local_48 = &PTR_LAB_c04f1054;
  FUN_c04f10a4((int *)&local_48,0x28,(int *)0x0);
  iVar1 = FUN_c04fac24(auStack_40,(int *)&local_48,param_2);
  if (iVar1 == 0) {
    *param_3 = local_44;
    FUN_c04fe38c(local_18);
    iVar1 = 0;
  }
  else {
    FUN_c04fe38c(local_18);
  }
  return iVar1;
}



/* c04fb180 socket */

/* Boundary evidence: original MIPS .pdata c04fb180..c04fb1f3. Semantic name remains unreviewed. */

SOCKET socket(int af,int type,int protocol)

{
  int iVar1;
  SOCKET local_28 [2];
  undefined2 local_20 [2];
  undefined4 local_1c;
  SOCKET *local_18;
  int local_14;
  int local_10;
  int local_c;
  
                    /* 0xb180  67  socket */
  local_20[0] = 2;
  local_18 = local_28;
  local_1c = DAT_c04ff0a0;
  local_14 = af;
  local_10 = type;
  local_c = protocol;
  iVar1 = FUN_c04f89b0(&PTR_PTR_c04ff09c,local_20);
  if (iVar1 != 0) {
    SetLastError(0x271d);
    local_28[0] = 0xffffffff;
  }
  return local_28[0];
}



/* c04fb1f4 accept */

/* Boundary evidence: original MIPS .pdata c04fb1f4..c04fb287. Semantic name remains unreviewed. */

SOCKET accept(SOCKET s,sockaddr *addr,int *addrlen)

{
  int iVar1;
  SOCKET local_30 [2];
  undefined2 local_28 [2];
  undefined4 local_24;
  SOCKET *local_20;
  SOCKET local_1c;
  sockaddr *local_18;
  int local_14;
  int *local_10;
  
                    /* 0xb1f4  34  accept */
  if (addrlen == (int *)0x0) {
    local_14 = 0;
  }
  else {
    local_14 = *addrlen;
  }
  if (addr == (sockaddr *)0x0) {
    local_14 = 0;
  }
  local_28[0] = 4;
  local_20 = local_30;
  local_24 = DAT_c04ff0a0;
  local_1c = s;
  local_18 = addr;
  local_10 = addrlen;
  iVar1 = FUN_c04f8ac8(&PTR_PTR_c04ff09c,local_28);
  if (iVar1 != 0) {
    SetLastError(0x271d);
    local_30[0] = 0xffffffff;
  }
  return local_30[0];
}



/* c04fb288 recv */

/* Boundary evidence: original MIPS .pdata c04fb288..c04fb2ef. Semantic name remains unreviewed. */

int recv(SOCKET s,char *buf,int len,int flags)

{
  int local_30 [2];
  undefined2 local_28 [2];
  undefined4 local_24;
  int *local_20;
  SOCKET local_1c;
  char *local_18;
  int local_14;
  int local_10;
  int local_c;
  
                    /* 0xb288  59  recv */
  local_30[0] = 0;
  local_14 = len;
  if (buf == (char *)0x0) {
    local_14 = 0;
  }
  local_28[0] = 10;
  local_20 = local_30;
  local_24 = DAT_c04ff0a0;
  local_1c = s;
  local_18 = buf;
  local_10 = len;
  local_c = flags;
  FUN_c04f8bd0(&PTR_PTR_c04ff09c,local_28);
  return local_30[0];
}



/* c04fb2f0 send */

/* Boundary evidence: original MIPS .pdata c04fb2f0..c04fb353. Semantic name remains unreviewed. */

int send(SOCKET s,char *buf,int len,int flags)

{
  int local_30 [2];
  undefined2 local_28 [2];
  undefined4 local_24;
  int *local_20;
  SOCKET local_1c;
  char *local_18;
  int local_14;
  int local_10;
  int local_c;
  
                    /* 0xb2f0  62  send */
  local_14 = len;
  if (buf == (char *)0x0) {
    local_14 = 0;
  }
  local_28[0] = 0xd;
  local_20 = local_30;
  local_24 = DAT_c04ff0a0;
  local_1c = s;
  local_18 = buf;
  local_10 = len;
  local_c = flags;
  FUN_c04f8cd8(&PTR_PTR_c04ff09c,local_28);
  return local_30[0];
}



/* c04fb354 setsockopt */

/* Boundary evidence: original MIPS .pdata c04fb354..c04fb3bf. Semantic name remains unreviewed. */

int setsockopt(SOCKET s,int level,int optname,char *optval,int optlen)

{
  int local_38 [2];
  undefined2 local_30 [2];
  undefined4 local_2c;
  int *local_28;
  SOCKET local_24;
  int local_20;
  int local_1c;
  char *local_18;
  int local_14;
  int local_10;
  
                    /* 0xb354  65  setsockopt */
  local_14 = optlen;
  if (optval == (char *)0x0) {
    local_14 = 0;
  }
  local_30[0] = 0xf;
  local_28 = local_38;
  local_2c = DAT_c04ff0a0;
  local_10 = optlen;
  local_24 = s;
  local_20 = level;
  local_1c = optname;
  local_18 = optval;
  FUN_c04f8de0(&PTR_PTR_c04ff09c,local_30);
  return local_38[0];
}



/* c04fb3c0 getsockopt */

/* Boundary evidence: original MIPS .pdata c04fb3c0..c04fb44f. Semantic name remains unreviewed. */

int getsockopt(SOCKET s,int level,int optname,char *optval,int *optlen)

{
  int iVar1;
  int local_38 [2];
  undefined2 local_30 [2];
  undefined4 local_2c;
  int *local_28;
  SOCKET local_24;
  int local_20;
  int local_1c;
  char *local_18;
  int local_14;
  int *local_10;
  
                    /* 0xb3c0  50  getsockopt */
  if (optval == (char *)0x0) {
    local_14 = 0;
  }
  else {
    local_14 = *optlen;
  }
  local_30[0] = 7;
  local_28 = local_38;
  local_2c = DAT_c04ff0a0;
  local_10 = optlen;
  local_24 = s;
  local_20 = level;
  local_1c = optname;
  local_18 = optval;
  iVar1 = FUN_c04f8ef8(&PTR_PTR_c04ff09c,local_30);
  if (iVar1 != 0) {
    SetLastError(0x271d);
    local_38[0] = -1;
  }
  return local_38[0];
}



/* c04fb450 WSAAccept */

/* Boundary evidence: original MIPS .pdata c04fb450..c04fb48f. Semantic name remains unreviewed. */

SOCKET WSAAccept(SOCKET param_1,sockaddr *param_2,int *param_3,int param_4)

{
  SOCKET SVar1;
  
                    /* 0xb450  1  WSAAccept */
  if (param_4 == 0) {
    SVar1 = accept(param_1,param_2,param_3);
  }
  else {
    SetLastError(0x273d);
    SVar1 = 0xffffffff;
  }
  return SVar1;
}



/* c04fb490 WSAEnumProtocolsW */

/* Boundary evidence: original MIPS .pdata c04fb490..c04fb54b. Semantic name remains unreviewed. */

undefined4 WSAEnumProtocolsW(int *param_1,int param_2,undefined4 *param_3)

{
  int iVar1;
  int *piVar2;
  undefined4 local_30 [2];
  undefined2 local_28 [2];
  undefined4 local_24;
  undefined4 *local_20;
  int *local_1c;
  int local_18;
  int local_14;
  undefined4 local_10;
  undefined4 *local_c;
  
                    /* 0xb490  11  WSAEnumProtocolsW */
  local_10 = *param_3;
  local_18 = 0;
  if (param_1 != (int *)0x0) {
    local_18 = 1;
    iVar1 = *param_1;
    piVar2 = param_1;
    while (iVar1 != 0) {
      piVar2 = piVar2 + 1;
      local_18 = local_18 + 1;
      iVar1 = *piVar2;
    }
  }
  if (param_2 == 0) {
    local_10 = 0;
  }
  if (param_1 == (int *)0x0) {
    local_18 = 0;
  }
  local_28[0] = 0x21;
  local_20 = local_30;
  local_24 = DAT_c04ff0a0;
  local_1c = param_1;
  local_14 = param_2;
  local_c = param_3;
  iVar1 = FUN_c04f9000(&PTR_PTR_c04ff09c,local_28);
  if (iVar1 != 0) {
    SetLastError(0x271d);
    local_30[0] = 0xffffffff;
  }
  return local_30[0];
}



/* c04fb54c FUN_c04fb54c */

/* Boundary evidence: original MIPS .pdata c04fb54c..c04fb663. Semantic name remains unreviewed. */

int FUN_c04fb54c(undefined4 *param_1,undefined2 *param_2)

{
  int iVar1;
  int *piVar2;
  undefined2 *puVar3;
  uint local_28 [2];
  
  iVar1 = FUN_c04faf10(param_1,param_2,local_28);
  if (iVar1 == 0) {
    piVar2 = FUN_c04f50a8(local_28[0]);
    if (piVar2 == (int *)0x0) {
      iVar1 = 0xe;
    }
    else {
      FUN_c04f10a4(piVar2,0x2c,(int *)0x0);
      puVar3 = (undefined2 *)piVar2[2];
      iVar1 = FUN_c04f9308(puVar3,piVar2,param_2);
      if (iVar1 == 0) {
        *(undefined4 *)(puVar3 + 0x14) = *(undefined4 *)(param_2 + 0x14);
        iVar1 = (**(code **)*param_1)(param_1,puVar3,local_28[0]);
        FUN_c04f937c((int)param_2,piVar2,(int)puVar3);
      }
      if ((void *)piVar2[2] != (void *)0x0) {
        operator_delete((void *)piVar2[2]);
      }
      operator_delete(piVar2);
    }
  }
  else {
    iVar1 = 0x57;
  }
  return iVar1;
}



/* c04fb664 FUN_c04fb664 */

/* Boundary evidence: original MIPS .pdata c04fb664..c04fb76b. Semantic name remains unreviewed. */

int FUN_c04fb664(undefined4 *param_1,undefined2 *param_2)

{
  int iVar1;
  int *piVar2;
  undefined2 *puVar3;
  uint local_28 [2];
  
  iVar1 = FUN_c04fafac(param_1,param_2,local_28);
  if (iVar1 == 0) {
    piVar2 = FUN_c04f50a8(local_28[0]);
    if (piVar2 == (int *)0x0) {
      iVar1 = 0xe;
    }
    else {
      FUN_c04f10a4(piVar2,0x28,(int *)0x0);
      puVar3 = (undefined2 *)piVar2[2];
      iVar1 = FUN_c04faac4(puVar3,piVar2,param_2);
      if (iVar1 == 0) {
        iVar1 = (**(code **)*param_1)(param_1,puVar3,local_28[0]);
        FUN_c04f47d8((int)param_2,piVar2,(int)puVar3);
      }
      if ((void *)piVar2[2] != (void *)0x0) {
        operator_delete((void *)piVar2[2]);
      }
      operator_delete(piVar2);
    }
  }
  else {
    iVar1 = 0x57;
  }
  return iVar1;
}



/* c04fb76c FUN_c04fb76c */

/* Boundary evidence: original MIPS .pdata c04fb76c..c04fb873. Semantic name remains unreviewed. */

int FUN_c04fb76c(undefined4 *param_1,undefined2 *param_2)

{
  int iVar1;
  int *piVar2;
  undefined2 *puVar3;
  uint local_28 [2];
  
  iVar1 = FUN_c04fb048(param_1,param_2,local_28);
  if (iVar1 == 0) {
    piVar2 = FUN_c04f50a8(local_28[0]);
    if (piVar2 == (int *)0x0) {
      iVar1 = 0xe;
    }
    else {
      FUN_c04f10a4(piVar2,0x2c,(int *)0x0);
      puVar3 = (undefined2 *)piVar2[2];
      iVar1 = FUN_c04fabb0(puVar3,piVar2,param_2);
      if (iVar1 == 0) {
        iVar1 = (**(code **)*param_1)(param_1,puVar3,local_28[0]);
        FUN_c04f7a38((int)param_2,piVar2,(int)puVar3);
      }
      if ((void *)piVar2[2] != (void *)0x0) {
        operator_delete((void *)piVar2[2]);
      }
      operator_delete(piVar2);
    }
  }
  else {
    iVar1 = 0x57;
  }
  return iVar1;
}



/* c04fb874 FUN_c04fb874 */

/* Boundary evidence: original MIPS .pdata c04fb874..c04fb97b. Semantic name remains unreviewed. */

int FUN_c04fb874(undefined4 *param_1,undefined2 *param_2)

{
  int iVar1;
  int *piVar2;
  undefined2 *puVar3;
  uint local_28 [2];
  
  iVar1 = FUN_c04fb0e4(param_1,param_2,local_28);
  if (iVar1 == 0) {
    piVar2 = FUN_c04f50a8(local_28[0]);
    if (piVar2 == (int *)0x0) {
      iVar1 = 0xe;
    }
    else {
      FUN_c04f10a4(piVar2,0x28,(int *)0x0);
      puVar3 = (undefined2 *)piVar2[2];
      iVar1 = FUN_c04fac24(puVar3,piVar2,param_2);
      if (iVar1 == 0) {
        iVar1 = (**(code **)*param_1)(param_1,puVar3,local_28[0]);
        FUN_c04fac98((int)param_2,piVar2,(int)puVar3);
      }
      if ((void *)piVar2[2] != (void *)0x0) {
        operator_delete((void *)piVar2[2]);
      }
      operator_delete(piVar2);
    }
  }
  else {
    iVar1 = 0x57;
  }
  return iVar1;
}



/* c04fb97c FUN_c04fb97c */

/* Boundary evidence: original MIPS .pdata c04fb97c..c04fb9d7. Semantic name remains unreviewed. */

int FUN_c04fb97c(undefined2 *param_1,int *param_2,undefined2 *param_3)

{
  int iVar1;
  
  iVar1 = FUN_c04f9748(param_1,param_2,param_3);
  if (iVar1 == 0) {
    *(undefined4 *)(param_1 + 0x16) = *(undefined4 *)(param_3 + 0x16);
    iVar1 = 0;
    *(undefined4 *)(param_1 + 0x18) = *(undefined4 *)(param_3 + 0x18);
  }
  return iVar1;
}



/* c04fb9d8 FUN_c04fb9d8 */

/* Boundary evidence: original MIPS .pdata c04fb9d8..c04fba67. Semantic name remains unreviewed. */

int FUN_c04fb9d8(int param_1,undefined4 *param_2,int param_3)

{
  int iVar1;
  undefined4 *puVar2;
  
  iVar1 = FUN_c04fad28(param_1,param_2,param_3);
  if (iVar1 == 0) {
    if (*(int *)(param_3 + 0x4c) == 0) {
      puVar2 = (undefined4 *)0x0;
    }
    else {
      puVar2 = (undefined4 *)(**(code **)*param_2)(param_2,*(int *)(param_3 + 0x4c),4);
    }
    if (*(undefined4 **)(param_1 + 0x4c) != (undefined4 *)0x0) {
      **(undefined4 **)(param_1 + 0x4c) = *puVar2;
    }
    iVar1 = 0;
  }
  return iVar1;
}



/* c04fba68 FUN_c04fba68 */

/* Boundary evidence: original MIPS .pdata c04fba68..c04fbadb. Semantic name remains unreviewed. */

int FUN_c04fba68(undefined2 *param_1,int *param_2,undefined2 *param_3)

{
  int iVar1;
  
  iVar1 = FUN_c04fae14(param_1,param_2,param_3);
  if (iVar1 == 0) {
    iVar1 = *(int *)(param_3 + 0x16);
    *(int *)(param_1 + 0x16) = iVar1;
    if (iVar1 != 0) {
      FUN_c04f23b0(param_2,*(undefined4 *)(param_3 + 0x16),4,(int *)(param_1 + 0x16));
    }
    iVar1 = 0;
  }
  return iVar1;
}



/* c04fbadc FUN_c04fbadc */

/* Boundary evidence: original MIPS .pdata c04fbadc..c04fbb63. Semantic name remains unreviewed. */

int FUN_c04fbadc(undefined2 *param_1,int *param_2,undefined2 *param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_c04fae9c(param_1,param_2,param_3);
  if (iVar1 == 0) {
    iVar1 = *(int *)(param_3 + 0x16);
    if (iVar1 == 0) {
      uVar2 = 0;
    }
    else {
      uVar2 = *(undefined4 *)(param_3 + 0x18);
    }
    *(int *)(param_1 + 0x16) = iVar1;
    *(undefined4 *)(param_1 + 0x18) = uVar2;
    FUN_c04f23b0(param_2,iVar1,*(int *)(param_3 + 0x18),(int *)(param_1 + 0x16));
    iVar1 = 0;
  }
  return iVar1;
}



/* c04fbb64 FUN_c04fbb64 */

/* Boundary evidence: original MIPS .pdata c04fbb64..c04fbbe7. Semantic name remains unreviewed. */

int FUN_c04fbb64(undefined2 *param_1,int *param_2,undefined2 *param_3)

{
  int iVar1;
  
  iVar1 = FUN_c04f98dc(param_1,param_2,param_3);
  if (iVar1 == 0) {
    *(undefined4 *)(param_1 + 0x1c) = *(undefined4 *)(param_3 + 0x1c);
    iVar1 = *(int *)(param_3 + 0x1e);
    *(int *)(param_1 + 0x1e) = iVar1;
    if (iVar1 != 0) {
      FUN_c04f23b0(param_2,*(undefined4 *)(param_3 + 0x1e),4,(int *)(param_1 + 0x1e));
    }
    iVar1 = 0;
  }
  return iVar1;
}



/* c04fbbe8 FUN_c04fbbe8 */

/* Boundary evidence: original MIPS .pdata c04fbbe8..c04fbc6b. Semantic name remains unreviewed. */

int FUN_c04fbbe8(undefined2 *param_1,int *param_2,undefined2 *param_3)

{
  int iVar1;
  
  iVar1 = FUN_c04f9964(param_1,param_2,param_3);
  if (iVar1 == 0) {
    *(undefined4 *)(param_1 + 0x1c) = *(undefined4 *)(param_3 + 0x1c);
    iVar1 = *(int *)(param_3 + 0x1e);
    *(int *)(param_1 + 0x1e) = iVar1;
    if (iVar1 != 0) {
      FUN_c04f23b0(param_2,*(undefined4 *)(param_3 + 0x1e),4,(int *)(param_1 + 0x1e));
    }
    iVar1 = 0;
  }
  return iVar1;
}



/* c04fbc6c FUN_c04fbc6c */

/* Boundary evidence: original MIPS .pdata c04fbc6c..c04fbd07. Semantic name remains unreviewed. */

int FUN_c04fbc6c(undefined4 param_1,undefined2 *param_2,undefined4 *param_3)

{
  int iVar1;
  undefined **local_50;
  undefined4 local_4c;
  undefined2 auStack_48 [26];
  uint local_14;
  
  local_14 = DAT_c04ff0b4;
  local_4c = 0;
  local_50 = &PTR_LAB_c04f1054;
  FUN_c04f10a4((int *)&local_50,0x34,(int *)0x0);
  iVar1 = FUN_c04fb97c(auStack_48,(int *)&local_50,param_2);
  if (iVar1 == 0) {
    *param_3 = local_4c;
    FUN_c04fe38c(local_14);
    iVar1 = 0;
  }
  else {
    FUN_c04fe38c(local_14);
  }
  return iVar1;
}



/* c04fbd08 FUN_c04fbd08 */

/* Boundary evidence: original MIPS .pdata c04fbd08..c04fbda3. Semantic name remains unreviewed. */

int FUN_c04fbd08(undefined4 param_1,undefined2 *param_2,undefined4 *param_3)

{
  int iVar1;
  undefined **local_50;
  undefined4 local_4c;
  undefined2 auStack_48 [24];
  uint local_18;
  
  local_18 = DAT_c04ff0b4;
  local_4c = 0;
  local_50 = &PTR_LAB_c04f1054;
  FUN_c04f10a4((int *)&local_50,0x30,(int *)0x0);
  iVar1 = FUN_c04fba68(auStack_48,(int *)&local_50,param_2);
  if (iVar1 == 0) {
    *param_3 = local_4c;
    FUN_c04fe38c(local_18);
    iVar1 = 0;
  }
  else {
    FUN_c04fe38c(local_18);
  }
  return iVar1;
}



/* c04fbda4 bind */

/* Boundary evidence: original MIPS .pdata c04fbda4..c04fbe47. Semantic name remains unreviewed. */

int bind(SOCKET s,sockaddr *addr,int namelen)

{
  int iVar1;
  int local_30;
  DWORD local_2c;
  undefined2 local_28 [2];
  undefined4 local_24;
  int *local_20;
  DWORD *local_1c;
  SOCKET local_18;
  sockaddr *local_14;
  int local_10;
  int local_c;
  
                    /* 0xbda4  35  bind */
  local_10 = namelen;
  if (addr == (sockaddr *)0x0) {
    local_10 = 0;
  }
  local_28[0] = 3;
  local_20 = &local_30;
  local_1c = &local_2c;
  local_24 = DAT_c04ff0a0;
  local_18 = s;
  local_14 = addr;
  local_c = namelen;
  iVar1 = FUN_c04fa57c(&PTR_PTR_c04ff09c,local_28);
  if (iVar1 != 0) {
    local_2c = 0x271d;
    local_30 = -1;
  }
  if (local_30 == -1) {
    SetLastError(local_2c);
  }
  return local_30;
}



/* c04fbe48 recvfrom */

/* Boundary evidence: original MIPS .pdata c04fbe48..c04fbedb. Semantic name remains unreviewed. */

int recvfrom(SOCKET s,char *buf,int len,int flags,sockaddr *from,int *fromlen)

{
  int local_40 [2];
  undefined2 local_38 [2];
  undefined4 local_34;
  int *local_30;
  SOCKET local_2c;
  char *local_28;
  int local_24;
  int local_20;
  int local_1c;
  sockaddr *local_18;
  int local_14;
  int *local_10;
  
                    /* 0xbe48  60  recvfrom */
  if (fromlen == (int *)0x0) {
    local_14 = 0;
  }
  else {
    local_14 = *fromlen;
  }
  local_40[0] = 0;
  if (from == (sockaddr *)0x0) {
    local_14 = 0;
  }
  local_24 = len;
  if (buf == (char *)0x0) {
    local_24 = 0;
  }
  local_38[0] = 0xb;
  local_30 = local_40;
  local_34 = DAT_c04ff0a0;
  local_18 = from;
  local_10 = fromlen;
  local_2c = s;
  local_28 = buf;
  local_20 = len;
  local_1c = flags;
  FUN_c04fa694(&PTR_PTR_c04ff09c,local_38);
  return local_40[0];
}



/* c04fbedc select */

/* Boundary evidence: original MIPS .pdata c04fbedc..c04fbfaf. Semantic name remains unreviewed. */

int select(int nfds,fd_set *readfds,fd_set *writefds,fd_set *exceptfds,timeval *timeout)

{
  int local_38 [2];
  undefined2 local_30 [2];
  undefined4 local_2c;
  int *local_28;
  fd_set *local_24;
  int local_20;
  fd_set *local_1c;
  int local_18;
  fd_set *local_14;
  int local_10;
  timeval *local_c;
  
                    /* 0xbedc  61  select */
  local_10 = 0;
  local_18 = 0;
  local_20 = 0;
  local_24 = (fd_set *)0x0;
  if (readfds != (fd_set *)0x0) {
    local_20 = readfds->fd_count + 1;
    local_24 = readfds;
  }
  local_1c = (fd_set *)0x0;
  if (writefds != (fd_set *)0x0) {
    local_18 = writefds->fd_count + 1;
    local_1c = writefds;
  }
  local_14 = (fd_set *)0x0;
  if (exceptfds != (fd_set *)0x0) {
    local_10 = exceptfds->fd_count + 1;
    local_14 = exceptfds;
  }
  if (local_14 == (fd_set *)0x0) {
    local_10 = 0;
  }
  if (local_1c == (fd_set *)0x0) {
    local_18 = 0;
  }
  if (local_24 == (fd_set *)0x0) {
    local_20 = 0;
  }
  local_30[0] = 0xc;
  local_28 = local_38;
  local_2c = DAT_c04ff0a0;
  local_c = timeout;
  FUN_c04fa79c(&PTR_PTR_c04ff09c,local_30);
  return local_38[0];
}



/* c04fbfb0 sendto */

/* Boundary evidence: original MIPS .pdata c04fbfb0..c04fc033. Semantic name remains unreviewed. */

int sendto(SOCKET s,char *buf,int len,int flags,sockaddr *to,int tolen)

{
  int local_40 [2];
  undefined2 local_38 [2];
  undefined4 local_34;
  int *local_30;
  SOCKET local_2c;
  char *local_28;
  int local_24;
  int local_20;
  int local_1c;
  sockaddr *local_18;
  int local_14;
  int local_10;
  
                    /* 0xbfb0  63  sendto */
  local_14 = tolen;
  if (to == (sockaddr *)0x0) {
    local_14 = 0;
  }
  local_24 = len;
  if (buf == (char *)0x0) {
    local_24 = 0;
  }
  local_38[0] = 0xe;
  local_30 = local_40;
  local_34 = DAT_c04ff0a0;
  local_18 = to;
  local_10 = tolen;
  local_2c = s;
  local_28 = buf;
  local_20 = len;
  local_1c = flags;
  FUN_c04fa8a4(&PTR_PTR_c04ff09c,local_38);
  return local_40[0];
}



/* c04fc034 gethostbyaddr */

/* Boundary evidence: original MIPS .pdata c04fc034..c04fc127. Semantic name remains unreviewed. */

hostent * gethostbyaddr(char *addr,int len,int type)

{
  LPVOID pvVar1;
  int iVar2;
  DWORD local_48 [2];
  undefined2 local_40 [2];
  undefined4 local_3c;
  DWORD *local_38;
  char *local_34;
  int local_30;
  int local_2c;
  int local_28;
  LPVOID local_24;
  undefined4 local_20;
  
                    /* 0xc034  40  gethostbyaddr */
  pvVar1 = FUN_c04f1494();
  if (pvVar1 == (LPVOID)0x0) {
    local_48[0] = 0x2747;
  }
  else {
    local_30 = len;
    if (addr == (char *)0x0) {
      local_30 = 0;
    }
    local_40[0] = 0x13;
    local_38 = local_48;
    local_3c = DAT_c04ff0a0;
    local_20 = 0x450;
    local_34 = addr;
    local_2c = len;
    local_28 = type;
    local_24 = pvVar1;
    iVar2 = FUN_c04fa9bc(&PTR_PTR_c04ff09c,local_40);
    if (iVar2 != 0) {
      return (hostent *)0x0;
    }
    if (local_48[0] == 0) {
      FUN_c04f14f0((int *)((int)pvVar1 + 0x14));
      return (hostent *)((int)pvVar1 + 0x14);
    }
  }
  SetLastError(local_48[0]);
  return (hostent *)0x0;
}



/* c04fc128 FUN_c04fc128 */

/* Boundary evidence: original MIPS .pdata c04fc128..c04fc18f. Semantic name remains unreviewed. */

void FUN_c04fc128(undefined4 *param_1,undefined2 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
                 undefined4 param_9,undefined4 param_10,undefined4 param_11)

{
  undefined2 local_38 [2];
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
  
  local_34 = param_1[1];
  local_28 = param_5;
  local_24 = param_6;
  local_20 = param_7;
  local_1c = param_8;
  local_18 = param_9;
  local_14 = param_10;
  local_10 = param_11;
  local_38[0] = param_2;
  local_30 = param_3;
  local_2c = param_4;
  FUN_c04fb76c(param_1,local_38);
  return;
}



/* c04fc190 FUN_c04fc190 */

/* Boundary evidence: original MIPS .pdata c04fc190..c04fc297. Semantic name remains unreviewed. */

int FUN_c04fc190(undefined4 *param_1,undefined2 *param_2)

{
  int iVar1;
  int *piVar2;
  undefined2 *puVar3;
  uint local_28 [2];
  
  iVar1 = FUN_c04fbc6c(param_1,param_2,local_28);
  if (iVar1 == 0) {
    piVar2 = FUN_c04f50a8(local_28[0]);
    if (piVar2 == (int *)0x0) {
      iVar1 = 0xe;
    }
    else {
      FUN_c04f10a4(piVar2,0x34,(int *)0x0);
      puVar3 = (undefined2 *)piVar2[2];
      iVar1 = FUN_c04fb97c(puVar3,piVar2,param_2);
      if (iVar1 == 0) {
        iVar1 = (**(code **)*param_1)(param_1,puVar3,local_28[0]);
        FUN_c04f5e7c((int)param_2,piVar2,(int)puVar3);
      }
      if ((void *)piVar2[2] != (void *)0x0) {
        operator_delete((void *)piVar2[2]);
      }
      operator_delete(piVar2);
    }
  }
  else {
    iVar1 = 0x57;
  }
  return iVar1;
}



/* c04fc298 FUN_c04fc298 */

/* Boundary evidence: original MIPS .pdata c04fc298..c04fc39f. Semantic name remains unreviewed. */

int FUN_c04fc298(undefined4 *param_1,undefined2 *param_2)

{
  int iVar1;
  int *piVar2;
  undefined2 *puVar3;
  uint local_28 [2];
  
  iVar1 = FUN_c04fbd08(param_1,param_2,local_28);
  if (iVar1 == 0) {
    piVar2 = FUN_c04f50a8(local_28[0]);
    if (piVar2 == (int *)0x0) {
      iVar1 = 0xe;
    }
    else {
      FUN_c04f10a4(piVar2,0x30,(int *)0x0);
      puVar3 = (undefined2 *)piVar2[2];
      iVar1 = FUN_c04fba68(puVar3,piVar2,param_2);
      if (iVar1 == 0) {
        iVar1 = (**(code **)*param_1)(param_1,puVar3,local_28[0]);
        FUN_c04f9278((int)param_2,piVar2,(int)puVar3);
      }
      if ((void *)piVar2[2] != (void *)0x0) {
        operator_delete((void *)piVar2[2]);
      }
      operator_delete(piVar2);
    }
  }
  else {
    iVar1 = 0x57;
  }
  return iVar1;
}



/* c04fc3a0 FUN_c04fc3a0 */

/* Boundary evidence: original MIPS .pdata c04fc3a0..c04fc413. Semantic name remains unreviewed. */

int FUN_c04fc3a0(undefined2 *param_1,int *param_2,undefined2 *param_3)

{
  int iVar1;
  
  iVar1 = FUN_c04fbb64(param_1,param_2,param_3);
  if (iVar1 == 0) {
    iVar1 = *(int *)(param_3 + 0x20);
    *(int *)(param_1 + 0x20) = iVar1;
    if (iVar1 != 0) {
      FUN_c04f23b0(param_2,*(undefined4 *)(param_3 + 0x20),4,(int *)(param_1 + 0x20));
    }
    iVar1 = 0;
  }
  return iVar1;
}



/* c04fc414 FUN_c04fc414 */

/* Boundary evidence: original MIPS .pdata c04fc414..c04fc49b. Semantic name remains unreviewed. */

int FUN_c04fc414(undefined2 *param_1,int *param_2,undefined2 *param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_c04fc3a0(param_1,param_2,param_3);
  if (iVar1 == 0) {
    iVar1 = *(int *)(param_3 + 0x22);
    if (iVar1 == 0) {
      uVar2 = 0;
    }
    else {
      uVar2 = *(undefined4 *)(param_3 + 0x24);
    }
    *(int *)(param_1 + 0x22) = iVar1;
    *(undefined4 *)(param_1 + 0x24) = uVar2;
    FUN_c04f23b0(param_2,iVar1,*(int *)(param_3 + 0x24),(int *)(param_1 + 0x22));
    iVar1 = 0;
  }
  return iVar1;
}



/* c04fc49c FUN_c04fc49c */

/* Boundary evidence: original MIPS .pdata c04fc49c..c04fc533. Semantic name remains unreviewed. */

int FUN_c04fc49c(undefined2 *param_1,int *param_2,undefined2 *param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_c04fbbe8(param_1,param_2,param_3);
  if (iVar1 == 0) {
    *(undefined4 *)(param_1 + 0x20) = *(undefined4 *)(param_3 + 0x20);
    iVar1 = *(int *)(param_3 + 0x22);
    if (iVar1 == 0) {
      uVar2 = 0;
    }
    else {
      uVar2 = *(undefined4 *)(param_3 + 0x24);
    }
    *(int *)(param_1 + 0x22) = iVar1;
    *(undefined4 *)(param_1 + 0x24) = uVar2;
    FUN_c04f23b0(param_2,iVar1,*(int *)(param_3 + 0x24),(int *)(param_1 + 0x22));
    iVar1 = 0;
  }
  return iVar1;
}



/* c04fc534 FUN_c04fc534 */

/* Boundary evidence: original MIPS .pdata c04fc534..c04fc5cf. Semantic name remains unreviewed. */

int FUN_c04fc534(undefined4 param_1,undefined2 *param_2,undefined4 *param_3)

{
  int iVar1;
  undefined **local_58;
  undefined4 local_54;
  undefined2 auStack_50 [28];
  uint local_18;
  
  local_18 = DAT_c04ff0b4;
  local_54 = 0;
  local_58 = &PTR_LAB_c04f1054;
  FUN_c04f10a4((int *)&local_58,0x38,(int *)0x0);
  iVar1 = FUN_c04fbadc(auStack_50,(int *)&local_58,param_2);
  if (iVar1 == 0) {
    *param_3 = local_54;
    FUN_c04fe38c(local_18);
    iVar1 = 0;
  }
  else {
    FUN_c04fe38c(local_18);
  }
  return iVar1;
}



/* c04fc5d0 FUN_c04fc5d0 */

/* Boundary evidence: original MIPS .pdata c04fc5d0..c04fc66b. Semantic name remains unreviewed. */

int FUN_c04fc5d0(undefined4 param_1,undefined2 *param_2,undefined4 *param_3)

{
  int iVar1;
  undefined **local_60;
  undefined4 local_5c;
  undefined2 auStack_58 [34];
  uint local_14;
  
  local_14 = DAT_c04ff0b4;
  local_5c = 0;
  local_60 = &PTR_LAB_c04f1054;
  FUN_c04f10a4((int *)&local_60,0x44,(int *)0x0);
  iVar1 = FUN_c04fc3a0(auStack_58,(int *)&local_60,param_2);
  if (iVar1 == 0) {
    *param_3 = local_5c;
    FUN_c04fe38c(local_14);
    iVar1 = 0;
  }
  else {
    FUN_c04fe38c(local_14);
  }
  return iVar1;
}



/* c04fc66c FUN_c04fc66c */

/* Boundary evidence: original MIPS .pdata c04fc66c..c04fc707. Semantic name remains unreviewed. */

int FUN_c04fc66c(undefined4 param_1,undefined2 *param_2,undefined4 *param_3)

{
  int iVar1;
  undefined **local_60;
  undefined4 local_5c;
  undefined2 auStack_58 [34];
  uint local_14;
  
  local_14 = DAT_c04ff0b4;
  local_5c = 0;
  local_60 = &PTR_LAB_c04f1054;
  FUN_c04f10a4((int *)&local_60,0x44,(int *)0x0);
  iVar1 = FUN_c04fbbe8(auStack_58,(int *)&local_60,param_2);
  if (iVar1 == 0) {
    *param_3 = local_5c;
    FUN_c04fe38c(local_14);
    iVar1 = 0;
  }
  else {
    FUN_c04fe38c(local_14);
  }
  return iVar1;
}



/* c04fc708 getaddrinfo */

/* WARNING: Type propagation algorithm not settling */
/* Boundary evidence: original MIPS .pdata c04fc708..c04fc823. Semantic name remains unreviewed. */

int getaddrinfo(undefined4 param_1,undefined4 param_2,int param_3,undefined4 *param_4)

{
  int iVar1;
  int local_50 [2];
  undefined2 local_48 [2];
  undefined4 local_44;
  int *local_40;
  undefined4 local_3c;
  undefined4 local_38;
  int local_34;
  undefined4 local_30;
  HLOCAL local_2c;
  undefined4 local_28;
  int *local_24;
  HLOCAL local_20;
  
                    /* 0xc708  39  getaddrinfo */
  local_50[0] = 0;
  local_50[1] = 0x400;
  local_2c = LocalAlloc(0x40,0x400);
  *param_4 = local_2c;
  if (local_2c == (HLOCAL)0x0) {
    SetLastError(0x2747);
    local_50[0] = -1;
  }
  else {
    local_30 = 0x20;
    if (param_3 == 0) {
      local_30 = 0;
    }
    local_48[0] = 0x12;
    local_40 = local_50;
    local_44 = DAT_c04ff0a0;
    local_24 = local_50 + 1;
    local_28 = 0x400;
    local_3c = param_1;
    local_38 = param_2;
    local_34 = param_3;
    local_20 = local_2c;
    iVar1 = FUN_c04fb54c(&PTR_PTR_c04ff09c,local_48);
    if (iVar1 != 0) {
      SetLastError(0x271d);
      local_50[0] = -1;
    }
    if (local_50[0] != 0) {
      LocalFree((HLOCAL)*param_4);
      *param_4 = 0;
    }
  }
  return local_50[0];
}



/* c04fc824 WSASocketW */

/* Boundary evidence: original MIPS .pdata c04fc824..c04fc897. Semantic name remains unreviewed. */

undefined4
WSASocketW(undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4,undefined4 param_5,
          undefined4 param_6)

{
  undefined4 local_38 [2];
  undefined2 local_30 [2];
  undefined4 local_2c;
  undefined4 *local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  int local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  
                    /* 0xc824  29  WSASocketW */
  local_14 = 0x274;
  if (param_4 == 0) {
    local_14 = 0;
  }
  local_30[0] = 0x1a;
  local_28 = local_38;
  local_2c = DAT_c04ff0a0;
  local_10 = param_5;
  local_c = param_6;
  local_24 = param_1;
  local_20 = param_2;
  local_1c = param_3;
  local_18 = param_4;
  FUN_c04fb664(&PTR_PTR_c04ff09c,local_30);
  return local_38[0];
}



/* c04fc898 WSAAddressToStringW */

/* Boundary evidence: original MIPS .pdata c04fc898..c04fc933. Semantic name remains unreviewed. */

undefined4
WSAAddressToStringW(int param_1,undefined4 param_2,int param_3,int param_4,undefined4 *param_5)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 local_10 [2];
  
                    /* 0xc898  2  WSAAddressToStringW */
  if (param_4 == 0) {
    uVar4 = 0;
  }
  else {
    uVar4 = *param_5;
  }
  uVar3 = 0x274;
  if (param_3 == 0) {
    uVar3 = 0;
  }
  uVar2 = param_2;
  if (param_1 == 0) {
    uVar2 = 0;
  }
  iVar1 = FUN_c04fc128(&PTR_PTR_c04ff09c,0x1c,local_10,param_1,uVar2,param_2,param_3,uVar3,param_4,
                       uVar4,param_5);
  if (iVar1 != 0) {
    SetLastError(0x271d);
    local_10[0] = 0xffffffff;
  }
  return local_10[0];
}



/* c04fc934 WSAStringToAddressW */

/* Boundary evidence: original MIPS .pdata c04fc934..c04fc9d3. Semantic name remains unreviewed. */

undefined4
WSAStringToAddressW(undefined4 param_1,undefined4 param_2,int param_3,int param_4,
                   undefined4 *param_5)

{
  int iVar1;
  undefined4 local_38 [2];
  undefined2 local_30 [2];
  undefined4 local_2c;
  undefined4 *local_28;
  undefined4 local_24;
  undefined4 local_20;
  int local_1c;
  undefined4 local_18;
  int local_14;
  undefined4 local_10;
  undefined4 *local_c;
  
                    /* 0xc934  31  WSAStringToAddressW */
  if (param_4 == 0) {
    local_10 = 0;
  }
  else {
    local_10 = *param_5;
  }
  local_18 = 0x274;
  if (param_3 == 0) {
    local_18 = 0;
  }
  local_30[0] = 0x2f;
  local_28 = local_38;
  local_2c = DAT_c04ff0a0;
  local_c = param_5;
  local_24 = param_1;
  local_20 = param_2;
  local_1c = param_3;
  local_14 = param_4;
  iVar1 = FUN_c04fb874(&PTR_PTR_c04ff09c,local_30);
  if (iVar1 != 0) {
    SetLastError(0x271d);
    local_38[0] = 0xffffffff;
  }
  return local_38[0];
}



/* c04fc9d4 FUN_c04fc9d4 */

/* Boundary evidence: original MIPS .pdata c04fc9d4..c04fca4b. Semantic name remains unreviewed. */

void FUN_c04fc9d4(undefined4 *param_1,undefined2 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
                 undefined4 param_9,undefined4 param_10,undefined4 param_11,undefined4 param_12,
                 undefined4 param_13)

{
  undefined2 local_40 [2];
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
  
  local_3c = param_1[1];
  local_30 = param_5;
  local_2c = param_6;
  local_28 = param_7;
  local_24 = param_8;
  local_20 = param_9;
  local_1c = param_10;
  local_18 = param_11;
  local_14 = param_12;
  local_10 = param_13;
  local_40[0] = param_2;
  local_38 = param_3;
  local_34 = param_4;
  FUN_c04fc190(param_1,local_40);
  return;
}



/* c04fca4c FUN_c04fca4c */

/* Boundary evidence: original MIPS .pdata c04fca4c..c04fcabb. Semantic name remains unreviewed. */

void FUN_c04fca4c(undefined4 *param_1,undefined2 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
                 undefined4 param_9,undefined4 param_10,undefined4 param_11,undefined4 param_12)

{
  undefined2 local_38 [2];
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
  
  local_34 = param_1[1];
  local_28 = param_5;
  local_24 = param_6;
  local_20 = param_7;
  local_1c = param_8;
  local_18 = param_9;
  local_14 = param_10;
  local_10 = param_11;
  local_c = param_12;
  local_38[0] = param_2;
  local_30 = param_3;
  local_2c = param_4;
  FUN_c04fc298(param_1,local_38);
  return;
}



/* c04fcabc FUN_c04fcabc */

/* Boundary evidence: original MIPS .pdata c04fcabc..c04fcbd3. Semantic name remains unreviewed. */

int FUN_c04fcabc(undefined4 *param_1,undefined2 *param_2)

{
  int iVar1;
  int *piVar2;
  undefined2 *puVar3;
  uint local_28 [2];
  
  iVar1 = FUN_c04fc534(param_1,param_2,local_28);
  if (iVar1 == 0) {
    piVar2 = FUN_c04f50a8(local_28[0]);
    if (piVar2 == (int *)0x0) {
      iVar1 = 0xe;
    }
    else {
      FUN_c04f10a4(piVar2,0x38,(int *)0x0);
      puVar3 = (undefined2 *)piVar2[2];
      iVar1 = FUN_c04fbadc(puVar3,piVar2,param_2);
      if (iVar1 == 0) {
        *(undefined4 *)(puVar3 + 0x1a) = *(undefined4 *)(param_2 + 0x1a);
        iVar1 = (**(code **)*param_1)(param_1,puVar3,local_28[0]);
        FUN_c04f940c((int)param_2,piVar2,(int)puVar3);
      }
      if ((void *)piVar2[2] != (void *)0x0) {
        operator_delete((void *)piVar2[2]);
      }
      operator_delete(piVar2);
    }
  }
  else {
    iVar1 = 0x57;
  }
  return iVar1;
}



/* c04fcbd4 FUN_c04fcbd4 */

/* Boundary evidence: original MIPS .pdata c04fcbd4..c04fccdb. Semantic name remains unreviewed. */

int FUN_c04fcbd4(undefined4 *param_1,undefined2 *param_2)

{
  int iVar1;
  int *piVar2;
  undefined2 *puVar3;
  uint local_28 [2];
  
  iVar1 = FUN_c04fc5d0(param_1,param_2,local_28);
  if (iVar1 == 0) {
    piVar2 = FUN_c04f50a8(local_28[0]);
    if (piVar2 == (int *)0x0) {
      iVar1 = 0xe;
    }
    else {
      FUN_c04f10a4(piVar2,0x44,(int *)0x0);
      puVar3 = (undefined2 *)piVar2[2];
      iVar1 = FUN_c04fc3a0(puVar3,piVar2,param_2);
      if (iVar1 == 0) {
        iVar1 = (**(code **)*param_1)(param_1,puVar3,local_28[0]);
        FUN_c04fab20((int)param_2,piVar2,(int)puVar3);
      }
      if ((void *)piVar2[2] != (void *)0x0) {
        operator_delete((void *)piVar2[2]);
      }
      operator_delete(piVar2);
    }
  }
  else {
    iVar1 = 0x57;
  }
  return iVar1;
}



/* c04fccdc FUN_c04fccdc */

/* Boundary evidence: original MIPS .pdata c04fccdc..c04fcdf3. Semantic name remains unreviewed. */

int FUN_c04fccdc(undefined4 *param_1,undefined2 *param_2)

{
  int iVar1;
  int *piVar2;
  undefined2 *puVar3;
  uint local_28 [2];
  
  iVar1 = FUN_c04fc66c(param_1,param_2,local_28);
  if (iVar1 == 0) {
    piVar2 = FUN_c04f50a8(local_28[0]);
    if (piVar2 == (int *)0x0) {
      iVar1 = 0xe;
    }
    else {
      FUN_c04f10a4(piVar2,0x44,(int *)0x0);
      puVar3 = (undefined2 *)piVar2[2];
      iVar1 = FUN_c04fbbe8(puVar3,piVar2,param_2);
      if (iVar1 == 0) {
        *(undefined4 *)(puVar3 + 0x20) = *(undefined4 *)(param_2 + 0x20);
        iVar1 = (**(code **)*param_1)(param_1,puVar3,local_28[0]);
        FUN_c04f9534((int)param_2,piVar2,(int)puVar3);
      }
      if ((void *)piVar2[2] != (void *)0x0) {
        operator_delete((void *)piVar2[2]);
      }
      operator_delete(piVar2);
    }
  }
  else {
    iVar1 = 0x57;
  }
  return iVar1;
}



/* c04fcdf4 FUN_c04fcdf4 */

/* Boundary evidence: original MIPS .pdata c04fcdf4..c04fce67. Semantic name remains unreviewed. */

int FUN_c04fcdf4(undefined2 *param_1,int *param_2,undefined2 *param_3)

{
  int iVar1;
  
  iVar1 = FUN_c04fc414(param_1,param_2,param_3);
  if (iVar1 == 0) {
    iVar1 = *(int *)(param_3 + 0x26);
    *(int *)(param_1 + 0x26) = iVar1;
    if (iVar1 != 0) {
      FUN_c04f2260(param_2,*(undefined4 *)(param_3 + 0x26),4,(int *)(param_1 + 0x26));
    }
    iVar1 = 0;
  }
  return iVar1;
}



/* c04fce68 FUN_c04fce68 */

/* Boundary evidence: original MIPS .pdata c04fce68..c04fcf03. Semantic name remains unreviewed. */

int FUN_c04fce68(undefined4 param_1,undefined2 *param_2,undefined4 *param_3)

{
  int iVar1;
  undefined **local_70;
  undefined4 local_6c;
  undefined2 auStack_68 [40];
  uint local_18;
  
  local_18 = DAT_c04ff0b4;
  local_6c = 0;
  local_70 = &PTR_LAB_c04f1054;
  FUN_c04f10a4((int *)&local_70,0x50,(int *)0x0);
  iVar1 = FUN_c04fcdf4(auStack_68,(int *)&local_70,param_2);
  if (iVar1 == 0) {
    *param_3 = local_6c;
    FUN_c04fe38c(local_18);
    iVar1 = 0;
  }
  else {
    FUN_c04fe38c(local_18);
  }
  return iVar1;
}



/* c04fcf04 FUN_c04fcf04 */

/* Boundary evidence: original MIPS .pdata c04fcf04..c04fcf9f. Semantic name remains unreviewed. */

int FUN_c04fcf04(undefined4 param_1,undefined2 *param_2,undefined4 *param_3)

{
  int iVar1;
  undefined **local_70;
  undefined4 local_6c;
  undefined2 auStack_68 [40];
  uint local_18;
  
  local_18 = DAT_c04ff0b4;
  local_6c = 0;
  local_70 = &PTR_LAB_c04f1054;
  FUN_c04f10a4((int *)&local_70,0x50,(int *)0x0);
  iVar1 = FUN_c04fc49c(auStack_68,(int *)&local_70,param_2);
  if (iVar1 == 0) {
    *param_3 = local_6c;
    FUN_c04fe38c(local_18);
    iVar1 = 0;
  }
  else {
    FUN_c04fe38c(local_18);
  }
  return iVar1;
}



/* c04fcfa0 getnameinfo */

/* Boundary evidence: original MIPS .pdata c04fcfa0..c04fd04b. Semantic name remains unreviewed. */

undefined4
getnameinfo(int param_1,undefined4 param_2,int param_3,undefined4 param_4,int param_5,
           undefined4 param_6,undefined4 param_7)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 local_10 [2];
  
                    /* 0xcfa0  43  getnameinfo */
  local_10[0] = 0;
  uVar4 = param_6;
  if (param_5 == 0) {
    uVar4 = 0;
  }
  uVar3 = param_4;
  if (param_3 == 0) {
    uVar3 = 0;
  }
  uVar2 = param_2;
  if (param_1 == 0) {
    uVar2 = 0;
  }
  iVar1 = FUN_c04fc9d4(&PTR_PTR_c04ff09c,0x16,local_10,param_1,uVar2,param_2,param_3,uVar3,param_4,
                       param_5,uVar4,param_6,param_7);
  if (iVar1 != 0) {
    SetLastError(0x271d);
    local_10[0] = 0xffffffff;
  }
  return local_10[0];
}



/* c04fd04c WSAControl */

/* Boundary evidence: original MIPS .pdata c04fd04c..c04fd177. Semantic name remains unreviewed. */

int WSAControl(undefined4 param_1,undefined4 param_2,int param_3,undefined4 *param_4,int param_5,
              undefined4 *param_6)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 local_20;
  undefined4 local_1c;
  int local_18;
  DWORD local_14;
  
                    /* 0xd04c  7  WSAControl */
  if ((param_4 == (undefined4 *)0x0) || (param_3 == 0)) {
    local_20 = 0;
    param_3 = 0;
  }
  else {
    local_20 = *param_4;
  }
  if ((param_6 == (undefined4 *)0x0) || (param_5 == 0)) {
    local_1c = 0;
    param_5 = 0;
  }
  else {
    local_1c = *param_6;
  }
  uVar3 = local_1c;
  if (param_5 == 0) {
    uVar3 = 0;
  }
  uVar2 = local_20;
  if (param_3 == 0) {
    uVar2 = 0;
  }
  iVar1 = FUN_c04fca4c(&PTR_PTR_c04ff09c,0x31,&local_18,&local_14,param_1,param_2,param_3,uVar2,
                       &local_20,param_5,uVar3,&local_1c);
  if (iVar1 == 0) {
    if (param_4 != (undefined4 *)0x0) {
      *param_4 = local_20;
    }
    if (param_6 != (undefined4 *)0x0) {
      *param_6 = local_1c;
    }
    if (local_18 == -1) {
      SetLastError(local_14);
    }
  }
  else {
    SetLastError(0x271d);
    local_18 = -1;
  }
  return local_18;
}



/* c04fd178 FUN_c04fd178 */

/* Boundary evidence: original MIPS .pdata c04fd178..c04fd1f7. Semantic name remains unreviewed. */

void FUN_c04fd178(undefined4 *param_1,undefined2 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
                 undefined4 param_9,undefined4 param_10,undefined4 param_11,undefined4 param_12,
                 undefined4 param_13,undefined4 param_14)

{
  undefined2 local_40 [2];
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
  
  local_3c = param_1[1];
  local_30 = param_5;
  local_2c = param_6;
  local_28 = param_7;
  local_24 = param_8;
  local_20 = param_9;
  local_1c = param_10;
  local_18 = param_11;
  local_14 = param_12;
  local_10 = param_13;
  local_c = param_14;
  local_40[0] = param_2;
  local_38 = param_3;
  local_34 = param_4;
  FUN_c04fcabc(param_1,local_40);
  return;
}



/* c04fd1f8 FUN_c04fd1f8 */

/* Boundary evidence: original MIPS .pdata c04fd1f8..c04fd28f. Semantic name remains unreviewed. */

void FUN_c04fd1f8(undefined4 *param_1,undefined2 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
                 undefined4 param_9,undefined4 param_10,undefined4 param_11,undefined4 param_12,
                 undefined4 param_13,undefined4 param_14,undefined4 param_15,undefined4 param_16,
                 undefined4 param_17)

{
  undefined2 local_50 [2];
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
  
  local_4c = param_1[1];
  local_40 = param_5;
  local_3c = param_6;
  local_38 = param_7;
  local_34 = param_8;
  local_30 = param_9;
  local_2c = param_10;
  local_28 = param_11;
  local_24 = param_12;
  local_20 = param_13;
  local_1c = param_14;
  local_18 = param_15;
  local_14 = param_16;
  local_10 = param_17;
  local_50[0] = param_2;
  local_48 = param_3;
  local_44 = param_4;
  FUN_c04fcbd4(param_1,local_50);
  return;
}



/* c04fd290 FUN_c04fd290 */

/* Boundary evidence: original MIPS .pdata c04fd290..c04fd327. Semantic name remains unreviewed. */

void FUN_c04fd290(undefined4 *param_1,undefined2 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
                 undefined4 param_9,undefined4 param_10,undefined4 param_11,undefined4 param_12,
                 undefined4 param_13,undefined4 param_14,undefined4 param_15,undefined4 param_16,
                 undefined4 param_17)

{
  undefined2 local_50 [2];
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
  
  local_4c = param_1[1];
  local_40 = param_5;
  local_3c = param_6;
  local_38 = param_7;
  local_34 = param_8;
  local_30 = param_9;
  local_2c = param_10;
  local_28 = param_11;
  local_24 = param_12;
  local_20 = param_13;
  local_1c = param_14;
  local_18 = param_15;
  local_14 = param_16;
  local_10 = param_17;
  local_50[0] = param_2;
  local_48 = param_3;
  local_44 = param_4;
  FUN_c04fccdc(param_1,local_50);
  return;
}



/* c04fd328 FUN_c04fd328 */

/* Boundary evidence: original MIPS .pdata c04fd328..c04fd42f. Semantic name remains unreviewed. */

int FUN_c04fd328(undefined4 *param_1,undefined2 *param_2)

{
  int iVar1;
  int *piVar2;
  undefined2 *puVar3;
  uint local_28 [2];
  
  iVar1 = FUN_c04fce68(param_1,param_2,local_28);
  if (iVar1 == 0) {
    piVar2 = FUN_c04f50a8(local_28[0]);
    if (piVar2 == (int *)0x0) {
      iVar1 = 0xe;
    }
    else {
      FUN_c04f10a4(piVar2,0x50,(int *)0x0);
      puVar3 = (undefined2 *)piVar2[2];
      iVar1 = FUN_c04fcdf4(puVar3,piVar2,param_2);
      if (iVar1 == 0) {
        iVar1 = (**(code **)*param_1)(param_1,puVar3,local_28[0]);
        FUN_c04fb9d8((int)param_2,piVar2,(int)puVar3);
      }
      if ((void *)piVar2[2] != (void *)0x0) {
        operator_delete((void *)piVar2[2]);
      }
      operator_delete(piVar2);
    }
  }
  else {
    iVar1 = 0x57;
  }
  return iVar1;
}



/* c04fd430 FUN_c04fd430 */

/* Boundary evidence: original MIPS .pdata c04fd430..c04fd547. Semantic name remains unreviewed. */

int FUN_c04fd430(undefined4 *param_1,undefined2 *param_2)

{
  int iVar1;
  int *piVar2;
  undefined2 *puVar3;
  uint local_28 [2];
  
  iVar1 = FUN_c04fcf04(param_1,param_2,local_28);
  if (iVar1 == 0) {
    piVar2 = FUN_c04f50a8(local_28[0]);
    if (piVar2 == (int *)0x0) {
      iVar1 = 0xe;
    }
    else {
      FUN_c04f10a4(piVar2,0x50,(int *)0x0);
      puVar3 = (undefined2 *)piVar2[2];
      iVar1 = FUN_c04fc49c(puVar3,piVar2,param_2);
      if (iVar1 == 0) {
        *(undefined4 *)(puVar3 + 0x26) = *(undefined4 *)(param_2 + 0x26);
        iVar1 = (**(code **)*param_1)(param_1,puVar3,local_28[0]);
        FUN_c04fadc0((int)param_2,piVar2,(int)puVar3);
      }
      if ((void *)piVar2[2] != (void *)0x0) {
        operator_delete((void *)piVar2[2]);
      }
      operator_delete(piVar2);
    }
  }
  else {
    iVar1 = 0x57;
  }
  return iVar1;
}



/* c04fd548 WSAIoctl */

/* Boundary evidence: original MIPS .pdata c04fd548..c04fd6a7. Semantic name remains unreviewed. */

int WSAIoctl(undefined4 param_1,int param_2,int param_3,undefined4 param_4,int param_5,
            undefined4 param_6,undefined4 param_7,int param_8,int param_9)

{
  undefined4 uVar1;
  int iVar2;
  DWORD dwErrCode;
  undefined4 uVar3;
  int local_20;
  DWORD local_1c;
  
                    /* 0xd548  17  WSAIoctl */
  uVar1 = __GetUserKData(0xc);
  if (param_9 != 0) {
    SetLastError(0x273d);
    return -1;
  }
  if (param_8 == 0) {
LAB_c04fd5e0:
    uVar3 = 0;
  }
  else {
    if ((param_2 != 0x28000017) && (param_2 != -0x77ffffeb)) {
      dwErrCode = 0x273d;
      goto LAB_c04fd658;
    }
    uVar3 = 0x14;
    if (param_8 == 0) goto LAB_c04fd5e0;
  }
  if (param_5 == 0) {
    param_6 = 0;
  }
  if (param_3 == 0) {
    param_4 = 0;
  }
  iVar2 = FUN_c04fd178(&PTR_PTR_c04ff09c,0x26,&local_20,&local_1c,param_1,param_2,param_3,param_4,
                       param_5,param_6,param_7,param_8,uVar3,uVar1);
  if (iVar2 == 0) {
    if (local_20 == -1) {
      SetLastError(local_1c);
      return local_20;
    }
    return local_20;
  }
  dwErrCode = 0x271d;
LAB_c04fd658:
  SetLastError(dwErrCode);
  return -1;
}



/* c04fd6a8 WSARecv */

/* Boundary evidence: original MIPS .pdata c04fd6a8..c04fd847. Semantic name remains unreviewed. */

undefined4
WSARecv(undefined4 param_1,undefined4 *param_2,uint param_3,undefined4 param_4,undefined4 param_5,
       int param_6,int param_7)

{
  DWORD dwErrCode;
  int iVar1;
  uint uVar2;
  undefined4 local_50 [2];
  int local_48 [4];
  int local_38;
  undefined4 local_30 [4];
  undefined4 local_20;
  
                    /* 0xd6a8  21  WSARecv */
  if ((param_6 == 0) && (param_7 == 0)) {
    if (param_3 < 6) {
      memset(local_48,0,0x14);
      memset(local_30,0,0x14);
      if (param_3 != 0) {
        iVar1 = 0;
        uVar2 = param_3;
        do {
          *(undefined4 *)((int)local_48 + iVar1) = param_2[1];
          *(undefined4 *)((int)local_30 + iVar1) = *param_2;
          param_2 = param_2 + 2;
          uVar2 = uVar2 - 1;
          iVar1 = iVar1 + 4;
        } while (uVar2 != 0);
      }
      if (local_38 == 0) {
        local_20 = 0;
      }
      if (local_48[3] == 0) {
        local_30[3] = 0;
      }
      if (local_48[2] == 0) {
        local_30[2] = 0;
      }
      if (local_48[1] == 0) {
        local_30[1] = 0;
      }
      if (local_48[0] == 0) {
        local_30[0] = 0;
      }
      iVar1 = FUN_c04fd1f8(&PTR_PTR_c04ff09c,0x28,local_50,param_1,local_48[0],local_30[0],
                           local_48[1],local_30[1],local_48[2],local_30[2],local_48[3],local_30[3],
                           local_38,local_20,param_3,param_4,param_5);
      if (iVar1 == 0) {
        return local_50[0];
      }
      dwErrCode = 0x271d;
    }
    else {
      dwErrCode = 0x2747;
    }
  }
  else {
    dwErrCode = 0x273d;
  }
  SetLastError(dwErrCode);
  return 0xffffffff;
}



/* c04fd848 WSASend */

/* Boundary evidence: original MIPS .pdata c04fd848..c04fd9e7. Semantic name remains unreviewed. */

undefined4
WSASend(undefined4 param_1,undefined4 *param_2,uint param_3,undefined4 param_4,undefined4 param_5,
       int param_6,int param_7)

{
  DWORD dwErrCode;
  int iVar1;
  uint uVar2;
  undefined4 local_50 [2];
  int local_48 [4];
  int local_38;
  undefined4 local_30 [4];
  undefined4 local_20;
  
                    /* 0xd848  24  WSASend */
  if ((param_6 == 0) && (param_7 == 0)) {
    if (param_3 < 6) {
      memset(local_48,0,0x14);
      memset(local_30,0,0x14);
      if (param_3 != 0) {
        iVar1 = 0;
        uVar2 = param_3;
        do {
          *(undefined4 *)((int)local_48 + iVar1) = param_2[1];
          *(undefined4 *)((int)local_30 + iVar1) = *param_2;
          param_2 = param_2 + 2;
          uVar2 = uVar2 - 1;
          iVar1 = iVar1 + 4;
        } while (uVar2 != 0);
      }
      if (local_38 == 0) {
        local_20 = 0;
      }
      if (local_48[3] == 0) {
        local_30[3] = 0;
      }
      if (local_48[2] == 0) {
        local_30[2] = 0;
      }
      if (local_48[1] == 0) {
        local_30[1] = 0;
      }
      if (local_48[0] == 0) {
        local_30[0] = 0;
      }
      iVar1 = FUN_c04fd290(&PTR_PTR_c04ff09c,0x2b,local_50,param_1,local_48[0],local_30[0],
                           local_48[1],local_30[1],local_48[2],local_30[2],local_48[3],local_30[3],
                           local_38,local_20,param_3,param_4,param_5);
      if (iVar1 == 0) {
        return local_50[0];
      }
      dwErrCode = 0x271d;
    }
    else {
      dwErrCode = 0x2747;
    }
  }
  else {
    dwErrCode = 0x273d;
  }
  SetLastError(dwErrCode);
  return 0xffffffff;
}



/* c04fd9e8 FUN_c04fd9e8 */

/* Boundary evidence: original MIPS .pdata c04fd9e8..c04fda97. Semantic name remains unreviewed. */

void FUN_c04fd9e8(undefined4 *param_1,undefined2 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
                 undefined4 param_9,undefined4 param_10,undefined4 param_11,undefined4 param_12,
                 undefined4 param_13,undefined4 param_14,undefined4 param_15,undefined4 param_16,
                 undefined4 param_17,undefined4 param_18,undefined4 param_19,undefined4 param_20)

{
  undefined2 local_58 [2];
  undefined4 local_54;
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
  
  local_54 = param_1[1];
  local_48 = param_5;
  local_44 = param_6;
  local_40 = param_7;
  local_3c = param_8;
  local_38 = param_9;
  local_34 = param_10;
  local_30 = param_11;
  local_2c = param_12;
  local_28 = param_13;
  local_24 = param_14;
  local_20 = param_15;
  local_1c = param_16;
  local_18 = param_17;
  local_14 = param_18;
  local_10 = param_19;
  local_c = param_20;
  local_58[0] = param_2;
  local_50 = param_3;
  local_4c = param_4;
  FUN_c04fd328(param_1,local_58);
  return;
}



/* c04fda98 FUN_c04fda98 */

/* Boundary evidence: original MIPS .pdata c04fda98..c04fdb47. Semantic name remains unreviewed. */

void FUN_c04fda98(undefined4 *param_1,undefined2 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
                 undefined4 param_9,undefined4 param_10,undefined4 param_11,undefined4 param_12,
                 undefined4 param_13,undefined4 param_14,undefined4 param_15,undefined4 param_16,
                 undefined4 param_17,undefined4 param_18,undefined4 param_19,undefined4 param_20)

{
  undefined2 local_58 [2];
  undefined4 local_54;
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
  
  local_54 = param_1[1];
  local_48 = param_5;
  local_44 = param_6;
  local_40 = param_7;
  local_3c = param_8;
  local_38 = param_9;
  local_34 = param_10;
  local_30 = param_11;
  local_2c = param_12;
  local_28 = param_13;
  local_24 = param_14;
  local_20 = param_15;
  local_1c = param_16;
  local_18 = param_17;
  local_14 = param_18;
  local_10 = param_19;
  local_c = param_20;
  local_58[0] = param_2;
  local_50 = param_3;
  local_4c = param_4;
  FUN_c04fd430(param_1,local_58);
  return;
}



/* c04fdb48 WSARecvFrom */

/* Boundary evidence: original MIPS .pdata c04fdb48..c04fdd37. Semantic name remains unreviewed. */

undefined4
WSARecvFrom(undefined4 param_1,undefined4 *param_2,uint param_3,undefined4 param_4,
           undefined4 param_5,int param_6,undefined4 *param_7,int param_8,int param_9)

{
  DWORD dwErrCode;
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  undefined4 local_58 [2];
  int local_50 [4];
  int local_40;
  undefined4 local_38 [4];
  undefined4 local_28;
  
                    /* 0xdb48  22  WSARecvFrom */
  if ((param_8 == 0) && (param_9 == 0)) {
    if (param_3 < 6) {
      if ((param_6 == 0) || (param_7 == (undefined4 *)0x0)) {
        uVar3 = 0;
      }
      else {
        uVar3 = *param_7;
      }
      memset(local_50,0,0x14);
      memset(local_38,0,0x14);
      if (param_3 != 0) {
        iVar1 = 0;
        uVar2 = param_3;
        do {
          *(undefined4 *)((int)local_50 + iVar1) = param_2[1];
          *(undefined4 *)((int)local_38 + iVar1) = *param_2;
          param_2 = param_2 + 2;
          uVar2 = uVar2 - 1;
          iVar1 = iVar1 + 4;
        } while (uVar2 != 0);
      }
      if (param_6 == 0) {
        uVar3 = 0;
      }
      if (local_40 == 0) {
        local_28 = 0;
      }
      if (local_50[3] == 0) {
        local_38[3] = 0;
      }
      if (local_50[2] == 0) {
        local_38[2] = 0;
      }
      if (local_50[1] == 0) {
        local_38[1] = 0;
      }
      if (local_50[0] == 0) {
        local_38[0] = 0;
      }
      iVar1 = FUN_c04fd9e8(&PTR_PTR_c04ff09c,0x29,local_58,param_1,local_50[0],local_38[0],
                           local_50[1],local_38[1],local_50[2],local_38[2],local_50[3],local_38[3],
                           local_40,local_28,param_3,param_4,param_5,param_6,uVar3,param_7);
      if (iVar1 == 0) {
        return local_58[0];
      }
      dwErrCode = 0x271d;
    }
    else {
      dwErrCode = 0x2747;
    }
  }
  else {
    dwErrCode = 0x273d;
  }
  SetLastError(dwErrCode);
  return 0xffffffff;
}



/* c04fdd38 WSASendTo */

/* Boundary evidence: original MIPS .pdata c04fdd38..c04fdf0f. Semantic name remains unreviewed. */

undefined4
WSASendTo(undefined4 param_1,undefined4 *param_2,uint param_3,undefined4 param_4,undefined4 param_5,
         int param_6,undefined4 param_7,int param_8,int param_9)

{
  DWORD dwErrCode;
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  undefined4 local_58 [2];
  int local_50 [4];
  int local_40;
  undefined4 local_38 [4];
  undefined4 local_28;
  
                    /* 0xdd38  25  WSASendTo */
  if ((param_8 == 0) && (param_9 == 0)) {
    if (param_3 < 6) {
      uVar4 = 0;
      if (param_6 != 0) {
        uVar4 = param_7;
      }
      memset(local_50,0,0x14);
      memset(local_38,0,0x14);
      if (param_3 != 0) {
        iVar2 = 0;
        uVar3 = param_3;
        do {
          *(undefined4 *)((int)local_50 + iVar2) = param_2[1];
          *(undefined4 *)((int)local_38 + iVar2) = *param_2;
          param_2 = param_2 + 2;
          uVar3 = uVar3 - 1;
          iVar2 = iVar2 + 4;
        } while (uVar3 != 0);
      }
      uVar1 = uVar4;
      if (param_6 == 0) {
        uVar1 = 0;
      }
      if (local_40 == 0) {
        local_28 = 0;
      }
      if (local_50[3] == 0) {
        local_38[3] = 0;
      }
      if (local_50[2] == 0) {
        local_38[2] = 0;
      }
      if (local_50[1] == 0) {
        local_38[1] = 0;
      }
      if (local_50[0] == 0) {
        local_38[0] = 0;
      }
      iVar2 = FUN_c04fda98(&PTR_PTR_c04ff09c,0x2c,local_58,param_1,local_50[0],local_38[0],
                           local_50[1],local_38[1],local_50[2],local_38[2],local_50[3],local_38[3],
                           local_40,local_28,param_3,param_4,param_5,param_6,uVar1,uVar4);
      if (iVar2 == 0) {
        return local_58[0];
      }
      dwErrCode = 0x271d;
    }
    else {
      dwErrCode = 0x2747;
    }
  }
  else {
    dwErrCode = 0x273d;
  }
  SetLastError(dwErrCode);
  return 0xffffffff;
}



/* c04fdfb0 entry */

/* Boundary evidence: original MIPS .pdata c04fdfb0..c04fe023. Semantic name remains unreviewed. */

undefined4 entry(HMODULE param_1,int param_2)

{
  undefined4 uVar1;
  
  if (param_2 == 1) {
    FUN_c04fe298();
    FUN_c04fe56c();
  }
  uVar1 = FUN_c04f1860(param_1,param_2);
  if (param_2 == 0) {
    FUN_c04fe4f4();
  }
  return uVar1;
}



/* c04fe024 FUN_c04fe024 */

/* Boundary evidence: original MIPS .pdata c04fe024..c04fe12f. Semantic name remains unreviewed. */

undefined4 FUN_c04fe024(undefined4 param_1)

{
  void *_Memory;
  uint uVar1;
  void *pvVar2;
  uint _NewSize;
  undefined4 *puVar3;
  int iVar4;
  
  _Memory = DAT_c04ff0dc;
  puVar3 = DAT_c04ff0d8;
  iVar4 = (int)DAT_c04ff0d8 - (int)DAT_c04ff0dc;
  uVar1 = 0;
  if (iVar4 < 0) {
LAB_c04fe068:
    param_1 = 0;
  }
  else {
    if (DAT_c04ff0dc != (void *)0x0) {
      uVar1 = _msize(DAT_c04ff0dc);
    }
    pvVar2 = _Memory;
    if (uVar1 < iVar4 + 4U) {
      if (_Memory == (void *)0x0) {
        pvVar2 = malloc(0x10);
LAB_c04fe0dc:
        if (pvVar2 == (void *)0x0) goto LAB_c04fe068;
      }
      else {
        _NewSize = uVar1 << 1;
        if (0x200 < uVar1) {
          _NewSize = uVar1 + 0x200;
        }
        if ((_NewSize <= uVar1) || (pvVar2 = realloc(_Memory,_NewSize), pvVar2 == (void *)0x0)) {
          pvVar2 = realloc(_Memory,iVar4 + 4U);
          goto LAB_c04fe0dc;
        }
      }
      puVar3 = (undefined4 *)((iVar4 >> 2) * 4 + (int)pvVar2);
    }
    DAT_c04ff0d8 = puVar3 + 1;
    *puVar3 = param_1;
    DAT_c04ff0dc = pvVar2;
  }
  return param_1;
}



/* c04fe130 FUN_c04fe130 */

/* Boundary evidence: original MIPS .pdata c04fe130..c04fe21b. Semantic name remains unreviewed. */

undefined4 FUN_c04fe130(undefined4 param_1)

{
  LPCRITICAL_SECTION lpCriticalSection;
  LONG LVar1;
  undefined4 uVar2;
  
  if (DAT_c04ff0e0 == (LPCRITICAL_SECTION)0x0) {
    lpCriticalSection = malloc(0x14);
    if (lpCriticalSection != (LPCRITICAL_SECTION)0x0) {
      InitializeCriticalSection(lpCriticalSection);
      LVar1 = InterlockedCompareExchange((LONG *)&DAT_c04ff0e0,(LONG)lpCriticalSection,0);
      if (LVar1 != 0) {
        DeleteCriticalSection(lpCriticalSection);
        free(lpCriticalSection);
      }
    }
    if (DAT_c04ff0e0 == (LPCRITICAL_SECTION)0x0) goto LAB_c04fe1d4;
  }
  EnterCriticalSection(DAT_c04ff0e0);
LAB_c04fe1d4:
  uVar2 = FUN_c04fe024(param_1);
  FUN_c04fe21c();
  return uVar2;
}



/* c04fe21c FUN_c04fe21c */

/* Boundary evidence: original MIPS .pdata c04fe21c..c04fe267. Semantic name remains unreviewed. */

void FUN_c04fe21c(void)

{
  if (DAT_c04ff0e0 != (LPCRITICAL_SECTION)0x0) {
    LeaveCriticalSection(DAT_c04ff0e0);
  }
  return;
}



/* c04fe268 FUN_c04fe268 */

/* Boundary evidence: original MIPS .pdata c04fe268..c04fe297. Semantic name remains unreviewed. */

undefined4 FUN_c04fe268(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_c04fe130(param_1);
  if (iVar1 == 0) {
    uVar2 = 0xffffffff;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}



/* c04fe298 FUN_c04fe298 */

/* Boundary evidence: original MIPS .pdata c04fe298..c04fe30b. Semantic name remains unreviewed. */

void FUN_c04fe298(void)

{
  uint uVar1;
  
  if ((DAT_c04ff0b4 == 0) || (DAT_c04ff0b4 == 0xb064)) {
    uVar1 = __security_gen_cookie2();
    DAT_c04ff0b4 = uVar1 >> 0x10 ^ uVar1 & 0xffff;
    if (DAT_c04ff0b4 == 0) {
      DAT_c04ff0b4 = 0xb064;
    }
  }
  DAT_c04ff0b8 = ~DAT_c04ff0b4;
  return;
}



/* c04fe30c FUN_c04fe30c */

/* Boundary evidence: original MIPS .pdata c04fe30c..c04fe35f. Semantic name remains unreviewed. */

void FUN_c04fe30c(int param_1,undefined4 param_2,uint *param_3)

{
  if ((*param_3 & 1) != 0) {
    param_1 = ((-param_3[2] & param_3[1] + param_1) - (param_3[1] + param_1)) + param_1;
  }
  FUN_c04fe38c(*(uint *)(param_1 + (*param_3 & 0xfffffffc)));
  return;
}



/* c04fe360 FUN_c04fe360 */

/* Boundary evidence: original MIPS .pdata c04fe360..c04fe38b. Semantic name remains unreviewed. */

undefined4 FUN_c04fe360(undefined4 param_1,int param_2,undefined4 param_3,int param_4)

{
  FUN_c04fe30c(param_2,param_4,*(uint **)(*(int *)(param_4 + 4) + 0xc));
  return 1;
}



/* c04fe38c FUN_c04fe38c */

/* Boundary evidence: original MIPS .pdata c04fe38c..c04fe3d3. Semantic name remains unreviewed. */

void FUN_c04fe38c(uint param_1)

{
  if ((param_1 == DAT_c04ff0b4) && (param_1 >> 0x10 == 0)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __report_gsfailure();
}



/* c04fe3d4 FUN_c04fe3d4 */

/* Boundary evidence: original MIPS .pdata c04fe3d4..c04fe4f3. Semantic name remains unreviewed. */

void FUN_c04fe3d4(UINT param_1,int param_2,int param_3)

{
  LPCRITICAL_SECTION lpCriticalSection;
  undefined4 *_Memory;
  
  DAT_c04ff0d5 = (undefined1)param_3;
  if (param_2 == 0) {
    _Memory = DAT_c04ff0dc;
    if (DAT_c04ff0dc != (undefined4 *)0x0) {
      while (DAT_c04ff0d8 = DAT_c04ff0d8 + -1, _Memory <= DAT_c04ff0d8) {
        if ((code *)*DAT_c04ff0d8 != (code *)0x0) {
          (*(code *)*DAT_c04ff0d8)();
          _Memory = DAT_c04ff0dc;
        }
      }
      free(_Memory);
      DAT_c04ff0d8 = (undefined4 *)0x0;
      DAT_c04ff0dc = (undefined4 *)0x0;
    }
    FUN_c04fe518((undefined4 *)&DAT_c04f101c,(undefined4 *)&DAT_c04f1020);
  }
  FUN_c04fe518((undefined4 *)&DAT_c04f1024,(undefined4 *)&DAT_c04f1028);
  if (param_3 == 0) {
    TerminateProcess((HANDLE)0x42,param_1);
  }
  else {
    lpCriticalSection = (LPCRITICAL_SECTION)InterlockedExchange(&DAT_c04ff0e0,0);
    if (lpCriticalSection != (LPCRITICAL_SECTION)0x0) {
      DeleteCriticalSection(lpCriticalSection);
      free(lpCriticalSection);
    }
  }
  return;
}



/* c04fe4f4 FUN_c04fe4f4 */

/* Boundary evidence: original MIPS .pdata c04fe4f4..c04fe517. Semantic name remains unreviewed. */

void FUN_c04fe4f4(void)

{
  FUN_c04fe3d4(0,0,1);
  return;
}



/* c04fe518 FUN_c04fe518 */

/* Boundary evidence: original MIPS .pdata c04fe518..c04fe56b. Semantic name remains unreviewed. */

void FUN_c04fe518(undefined4 *param_1,undefined4 *param_2)

{
  for (; param_1 < param_2; param_1 = param_1 + 1) {
    if ((code *)*param_1 != (code *)0x0) {
      (*(code *)*param_1)();
    }
  }
  return;
}



/* c04fe56c FUN_c04fe56c */

/* Boundary evidence: original MIPS .pdata c04fe56c..c04fe5a7. Semantic name remains unreviewed. */

void FUN_c04fe56c(void)

{
  FUN_c04fe518((undefined4 *)&DAT_c04f1014,(undefined4 *)&DAT_c04f1018);
  FUN_c04fe518((undefined4 *)&DAT_c04f1000,(undefined4 *)&DAT_c04f1010);
  return;
}



/* c04fe6d8 FUN_c04fe6d8 */

/* Boundary evidence: original MIPS .pdata c04fe6d8..c04fe6f7. Semantic name remains unreviewed. */

void FUN_c04fe6d8(void)

{
  FUN_c04fe268(FUN_c04fe734);
  return;
}



/* c04fe6f8 FUN_c04fe6f8 */

/* Boundary evidence: original MIPS .pdata c04fe6f8..c04fe713. Semantic name remains unreviewed. */

void FUN_c04fe6f8(void)

{
  FUN_c04f1bfc();
  return;
}



/* c04fe714 FUN_c04fe714 */

/* Boundary evidence: original MIPS .pdata c04fe714..c04fe733. Semantic name remains unreviewed. */

void FUN_c04fe714(void)

{
  DeleteCriticalSection((LPCRITICAL_SECTION)&DAT_c04ff0bc);
  return;
}



/* c04fe734 FUN_c04fe734 */

/* Boundary evidence: original MIPS .pdata c04fe734..c04fe753. Semantic name remains unreviewed. */

void FUN_c04fe734(void)

{
  FUN_c04f18a8(&PTR_PTR_c04ff09c);
  return;
}


