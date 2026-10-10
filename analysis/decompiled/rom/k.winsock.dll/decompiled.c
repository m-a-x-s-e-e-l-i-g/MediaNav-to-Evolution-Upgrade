/* Automatic Ghidra pseudocode. Not original source; not runtime-verified. */

/* c07d1060 WSAStartup */

/* Boundary evidence: original MIPS .pdata c07d1060..c07d1133. Semantic name remains unreviewed. */

int WSAStartup(WORD wVersionRequired,LPWSADATA lpWSAData)

{
  int iVar1;
  
                    /* 0x1060  4  WSAStartup */
  if ((wVersionRequired & 0xff) == 0) {
    iVar1 = 0x276c;
  }
  else {
    iVar1 = WSAStartup(wVersionRequired,lpWSAData);
    if (((wVersionRequired & 0xff) == 1) && (wVersionRequired >> 8 == 0)) {
      lpWSAData->wVersion = 1;
    }
    else {
      lpWSAData->wVersion = 0x101;
    }
    lpWSAData->wHighVersion = 0x101;
    lpWSAData->szDescription[0] = '\0';
    lpWSAData->szSystemStatus[0] = '\0';
    if (iVar1 == 0) {
      if (DAT_c07d30a4 != 0) {
        WSACleanup();
        DAT_c07d30a4 = 0;
      }
      DAT_c07d30a0 = DAT_c07d30a0 + 1;
    }
  }
  return iVar1;
}



/* c07d1134 WSACleanup */

/* Boundary evidence: original MIPS .pdata c07d1134..c07d117b. Semantic name remains unreviewed. */

int WSACleanup(void)

{
  int iVar1;
  
                    /* 0x1134  2  WSACleanup */
  if (DAT_c07d30a0 == 0) {
    SetLastError(0x276d);
    iVar1 = -1;
  }
  else {
    DAT_c07d30a0 = DAT_c07d30a0 + -1;
    iVar1 = WSACleanup();
  }
  return iVar1;
}



/* c07d117c socket */

/* Boundary evidence: original MIPS .pdata c07d117c..c07d1197. Semantic name remains unreviewed. */

SOCKET socket(int af,int type,int protocol)

{
  SOCKET SVar1;
  
                    /* 0x117c  33  socket */
  SVar1 = socket(af,type,protocol);
  return SVar1;
}



/* c07d1198 closesocket */

/* Boundary evidence: original MIPS .pdata c07d1198..c07d11b3. Semantic name remains unreviewed. */

int closesocket(SOCKET s)

{
  int iVar1;
  
                    /* 0x1198  9  closesocket */
  iVar1 = closesocket(s);
  return iVar1;
}



/* c07d11b4 accept */

/* Boundary evidence: original MIPS .pdata c07d11b4..c07d11cf. Semantic name remains unreviewed. */

SOCKET accept(SOCKET s,sockaddr *addr,int *addrlen)

{
  SOCKET SVar1;
  
                    /* 0x11b4  7  accept */
  SVar1 = accept(s,addr,addrlen);
  return SVar1;
}



/* c07d11d0 bind */

/* Boundary evidence: original MIPS .pdata c07d11d0..c07d11eb. Semantic name remains unreviewed. */

int bind(SOCKET s,sockaddr *addr,int namelen)

{
  int iVar1;
  
                    /* 0x11d0  8  bind */
  iVar1 = bind(s,addr,namelen);
  return iVar1;
}



/* c07d11ec connect */

/* Boundary evidence: original MIPS .pdata c07d11ec..c07d1207. Semantic name remains unreviewed. */

int connect(SOCKET s,sockaddr *name,int namelen)

{
  int iVar1;
  
                    /* 0x11ec  10  connect */
  iVar1 = connect(s,name,namelen);
  return iVar1;
}



/* c07d1208 getsockopt */

/* Boundary evidence: original MIPS .pdata c07d1208..c07d1227. Semantic name remains unreviewed. */

int getsockopt(SOCKET s,int level,int optname,char *optval,int *optlen)

{
  int iVar1;
  
                    /* 0x1208  16  getsockopt */
  iVar1 = getsockopt(s,level,optname,optval,optlen);
  return iVar1;
}



/* c07d1228 inet_addr */

/* Boundary evidence: original MIPS .pdata c07d1228..c07d1243. Semantic name remains unreviewed. */

ulong inet_addr(char *cp)

{
  ulong uVar1;
  
                    /* 0x1228  19  inet_addr */
  uVar1 = inet_addr(cp);
  return uVar1;
}



/* c07d1244 inet_ntoa */

/* Boundary evidence: original MIPS .pdata c07d1244..c07d125f. Semantic name remains unreviewed. */

char * inet_ntoa(in_addr in)

{
  char *pcVar1;
  
                    /* 0x1244  20  inet_ntoa */
  pcVar1 = inet_ntoa(in);
  return pcVar1;
}



/* c07d1260 ioctlsocket */

/* Boundary evidence: original MIPS .pdata c07d1260..c07d127b. Semantic name remains unreviewed. */

int ioctlsocket(SOCKET s,long cmd,u_long *argp)

{
  int iVar1;
  
                    /* 0x1260  21  ioctlsocket */
  iVar1 = ioctlsocket(s,cmd,argp);
  return iVar1;
}



/* c07d127c listen */

/* Boundary evidence: original MIPS .pdata c07d127c..c07d1297. Semantic name remains unreviewed. */

int listen(SOCKET s,int backlog)

{
  int iVar1;
  
                    /* 0x127c  22  listen */
  iVar1 = listen(s,backlog);
  return iVar1;
}



/* c07d1298 recv */

/* Boundary evidence: original MIPS .pdata c07d1298..c07d12b3. Semantic name remains unreviewed. */

int recv(SOCKET s,char *buf,int len,int flags)

{
  int iVar1;
  
                    /* 0x1298  25  recv */
  iVar1 = recv(s,buf,len,flags);
  return iVar1;
}



/* c07d12b4 recvfrom */

/* Boundary evidence: original MIPS .pdata c07d12b4..c07d12db. Semantic name remains unreviewed. */

int recvfrom(SOCKET s,char *buf,int len,int flags,sockaddr *from,int *fromlen)

{
  int iVar1;
  
                    /* 0x12b4  26  recvfrom */
  iVar1 = recvfrom(s,buf,len,flags,from,fromlen);
  return iVar1;
}



/* c07d12dc select */

/* Boundary evidence: original MIPS .pdata c07d12dc..c07d12fb. Semantic name remains unreviewed. */

int select(int nfds,fd_set *readfds,fd_set *writefds,fd_set *exceptfds,timeval *timeout)

{
  int iVar1;
  
                    /* 0x12dc  27  select */
  iVar1 = select(nfds,readfds,writefds,exceptfds,timeout);
  return iVar1;
}



/* c07d12fc send */

/* Boundary evidence: original MIPS .pdata c07d12fc..c07d1317. Semantic name remains unreviewed. */

int send(SOCKET s,char *buf,int len,int flags)

{
  int iVar1;
  
                    /* 0x12fc  28  send */
  iVar1 = send(s,buf,len,flags);
  return iVar1;
}



/* c07d1318 sendto */

/* Boundary evidence: original MIPS .pdata c07d1318..c07d133f. Semantic name remains unreviewed. */

int sendto(SOCKET s,char *buf,int len,int flags,sockaddr *to,int tolen)

{
  int iVar1;
  
                    /* 0x1318  29  sendto */
  iVar1 = sendto(s,buf,len,flags,to,tolen);
  return iVar1;
}



/* c07d1340 shutdown */

/* Boundary evidence: original MIPS .pdata c07d1340..c07d135b. Semantic name remains unreviewed. */

int shutdown(SOCKET s,int how)

{
  int iVar1;
  
                    /* 0x1340  32  shutdown */
  iVar1 = shutdown(s,how);
  return iVar1;
}



/* c07d135c getpeername */

/* Boundary evidence: original MIPS .pdata c07d135c..c07d1377. Semantic name remains unreviewed. */

int getpeername(SOCKET s,sockaddr *name,int *namelen)

{
  int iVar1;
  
                    /* 0x135c  14  getpeername */
  iVar1 = getpeername(s,name,namelen);
  return iVar1;
}



/* c07d1378 getsockname */

/* Boundary evidence: original MIPS .pdata c07d1378..c07d1393. Semantic name remains unreviewed. */

int getsockname(SOCKET s,sockaddr *name,int *namelen)

{
  int iVar1;
  
                    /* 0x1378  15  getsockname */
  iVar1 = getsockname(s,name,namelen);
  return iVar1;
}



/* c07d1394 __WSAFDIsSet */

/* WARNING: Type propagation algorithm not settling */

int __WSAFDIsSet(SOCKET param_1,fd_set *param_2)

{
  uint uVar1;
  fd_set *pfVar2;
  
                    /* 0x1394  6  __WSAFDIsSet */
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



/* c07d13dc WsControl */

/* Boundary evidence: original MIPS .pdata c07d13dc..c07d1417. Semantic name remains unreviewed. */

void WsControl(void)

{
                    /* 0x13dc  5  WsControl */
  (*(code *)&SUB_fffe6ff6)();
  return;
}



/* c07d1418 EnumProtocolsW */

/* Boundary evidence: original MIPS .pdata c07d1418..c07d143b. Semantic name remains unreviewed. */

INT EnumProtocolsW(LPINT lpiProtocols,LPVOID lpProtocolBuffer,LPDWORD lpdwBufferLength)

{
  INT IVar1;
  
                    /* 0x1418  1  EnumProtocolsW */
  IVar1 = (*(code *)&SUB_fffe6ff2)();
  return IVar1;
}



/* c07d143c gethostbyaddr */

/* Boundary evidence: original MIPS .pdata c07d143c..c07d1457. Semantic name remains unreviewed. */

hostent * gethostbyaddr(char *addr,int len,int type)

{
  hostent *phVar1;
  
                    /* 0x143c  11  gethostbyaddr */
  phVar1 = gethostbyaddr(addr,len,type);
  return phVar1;
}



/* c07d1458 gethostbyname */

/* Boundary evidence: original MIPS .pdata c07d1458..c07d1473. Semantic name remains unreviewed. */

hostent * gethostbyname(char *name)

{
  hostent *phVar1;
  
                    /* 0x1458  12  gethostbyname */
  phVar1 = gethostbyname(name);
  return phVar1;
}



/* c07d1474 gethostname */

/* Boundary evidence: original MIPS .pdata c07d1474..c07d148f. Semantic name remains unreviewed. */

int gethostname(char *name,int namelen)

{
  int iVar1;
  
                    /* 0x1474  13  gethostname */
  iVar1 = gethostname(name,namelen);
  return iVar1;
}



/* c07d1490 sethostname */

/* Boundary evidence: original MIPS .pdata c07d1490..c07d14ab. Semantic name remains unreviewed. */

void sethostname(void)

{
                    /* 0x1490  30  sethostname */
  sethostname();
  return;
}



/* c07d14ac WSAIoctl */

/* Boundary evidence: original MIPS .pdata c07d14ac..c07d14eb. Semantic name remains unreviewed. */

void WSAIoctl(void)

{
                    /* 0x14ac  3  WSAIoctl */
  WSAIoctl();
  return;
}



/* c07d14ec setsockopt */

/* Boundary evidence: original MIPS .pdata c07d14ec..c07d150b. Semantic name remains unreviewed. */

int setsockopt(SOCKET s,int level,int optname,char *optval,int optlen)

{
  int iVar1;
  
                    /* 0x14ec  31  setsockopt */
  iVar1 = setsockopt(s,level,optname,optval,optlen);
  return iVar1;
}



/* c07d150c htons */

u_short htons(u_short netshort)

{
  undefined2 in_register_00000012;
  
                    /* 0x150c  18  htons
                       0x150c  24  ntohs */
  return netshort << 8 | (ushort)(CONCAT22(in_register_00000012,netshort) >> 8);
}



/* c07d1524 htonl */

u_long htonl(u_long netlong)

{
                    /* 0x1524  17  htonl
                       0x1524  23  ntohl */
  return (netlong & 0xff00 | netlong << 0x10) << 8 | (netlong & 0xff0000 | netlong >> 0x10) >> 8;
}



/* c07d1550 FUN_c07d1550 */

/* Boundary evidence: original MIPS .pdata c07d1550..c07d15cf. Semantic name remains unreviewed. */

undefined4 FUN_c07d1550(HMODULE param_1,int param_2)

{
  int iVar1;
  WSADATA WStack_1a0;
  uint local_10;
  
  local_10 = DAT_c07d3094;
  if ((param_2 != 0) && (param_2 == 1)) {
    DisableThreadLibraryCalls(param_1);
    memset(&WStack_1a0,0,400);
    iVar1 = WSAStartup(0x101,&WStack_1a0);
    if (iVar1 == 0) {
      DAT_c07d30a4 = DAT_c07d30a4 + 1;
    }
  }
  FUN_c07d18d8(local_10);
  return 1;
}



/* c07d1770 entry */

/* Boundary evidence: original MIPS .pdata c07d1770..c07d17e3. Semantic name remains unreviewed. */

undefined4 entry(HMODULE param_1,int param_2)

{
  undefined4 uVar1;
  
  if (param_2 == 1) {
    FUN_c07d17e4();
    FUN_c07d1ab8();
  }
  uVar1 = FUN_c07d1550(param_1,param_2);
  if (param_2 == 0) {
    FUN_c07d1a40();
  }
  return uVar1;
}



/* c07d17e4 FUN_c07d17e4 */

/* Boundary evidence: original MIPS .pdata c07d17e4..c07d1857. Semantic name remains unreviewed. */

void FUN_c07d17e4(void)

{
  uint uVar1;
  
  if ((DAT_c07d3094 == 0) || (DAT_c07d3094 == 0xb064)) {
    uVar1 = __security_gen_cookie2();
    DAT_c07d3094 = uVar1 >> 0x10 ^ uVar1 & 0xffff;
    if (DAT_c07d3094 == 0) {
      DAT_c07d3094 = 0xb064;
    }
  }
  DAT_c07d3098 = ~DAT_c07d3094;
  return;
}



/* c07d1858 FUN_c07d1858 */

/* Boundary evidence: original MIPS .pdata c07d1858..c07d18ab. Semantic name remains unreviewed. */

void FUN_c07d1858(int param_1,undefined4 param_2,uint *param_3)

{
  if ((*param_3 & 1) != 0) {
    param_1 = ((-param_3[2] & param_3[1] + param_1) - (param_3[1] + param_1)) + param_1;
  }
  FUN_c07d18d8(*(uint *)(param_1 + (*param_3 & 0xfffffffc)));
  return;
}



/* c07d18ac FUN_c07d18ac */

/* Boundary evidence: original MIPS .pdata c07d18ac..c07d18d7. Semantic name remains unreviewed. */

undefined4 FUN_c07d18ac(undefined4 param_1,int param_2,undefined4 param_3,int param_4)

{
  FUN_c07d1858(param_2,param_4,*(uint **)(*(int *)(param_4 + 4) + 0xc));
  return 1;
}



/* c07d18d8 FUN_c07d18d8 */

/* Boundary evidence: original MIPS .pdata c07d18d8..c07d191f. Semantic name remains unreviewed. */

void FUN_c07d18d8(uint param_1)

{
  if ((param_1 == DAT_c07d3094) && (param_1 >> 0x10 == 0)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __report_gsfailure();
}



/* c07d1920 FUN_c07d1920 */

/* Boundary evidence: original MIPS .pdata c07d1920..c07d1a3f. Semantic name remains unreviewed. */

void FUN_c07d1920(UINT param_1,int param_2,int param_3)

{
  LPCRITICAL_SECTION lpCriticalSection;
  undefined4 *_Memory;
  
  DAT_c07d309c = (undefined1)param_3;
  if (param_2 == 0) {
    _Memory = DAT_c07d30ac;
    if (DAT_c07d30ac != (undefined4 *)0x0) {
      while (DAT_c07d30a8 = DAT_c07d30a8 + -1, _Memory <= DAT_c07d30a8) {
        if ((code *)*DAT_c07d30a8 != (code *)0x0) {
          (*(code *)*DAT_c07d30a8)();
          _Memory = DAT_c07d30ac;
        }
      }
      free(_Memory);
      DAT_c07d30a8 = (undefined4 *)0x0;
      DAT_c07d30ac = (undefined4 *)0x0;
    }
    FUN_c07d1a64((undefined4 *)&DAT_c07d1010,(undefined4 *)&DAT_c07d1014);
  }
  FUN_c07d1a64((undefined4 *)&DAT_c07d1018,(undefined4 *)&DAT_c07d101c);
  if (param_3 == 0) {
    TerminateProcess((HANDLE)0x42,param_1);
  }
  else {
    lpCriticalSection = (LPCRITICAL_SECTION)InterlockedExchange((LONG *)&DAT_c07d30b0,0);
    if (lpCriticalSection != (LPCRITICAL_SECTION)0x0) {
      DeleteCriticalSection(lpCriticalSection);
      free(lpCriticalSection);
    }
  }
  return;
}



/* c07d1a40 FUN_c07d1a40 */

/* Boundary evidence: original MIPS .pdata c07d1a40..c07d1a63. Semantic name remains unreviewed. */

void FUN_c07d1a40(void)

{
  FUN_c07d1920(0,0,1);
  return;
}



/* c07d1a64 FUN_c07d1a64 */

/* Boundary evidence: original MIPS .pdata c07d1a64..c07d1ab7. Semantic name remains unreviewed. */

void FUN_c07d1a64(undefined4 *param_1,undefined4 *param_2)

{
  for (; param_1 < param_2; param_1 = param_1 + 1) {
    if ((code *)*param_1 != (code *)0x0) {
      (*(code *)*param_1)();
    }
  }
  return;
}



/* c07d1ab8 FUN_c07d1ab8 */

/* Boundary evidence: original MIPS .pdata c07d1ab8..c07d1af3. Semantic name remains unreviewed. */

void FUN_c07d1ab8(void)

{
  FUN_c07d1a64((undefined4 *)&DAT_c07d1008,(undefined4 *)&DAT_c07d100c);
  FUN_c07d1a64((undefined4 *)&DAT_c07d1000,(undefined4 *)&DAT_c07d1004);
  return;
}


