/* Automatic Ghidra pseudocode. Not original source; not runtime-verified. */

/* 00011600 FUN_00011600 */

/* Boundary evidence: original MIPS .pdata 00011600..00011693. Semantic name remains unreviewed. */

void FUN_00011600(HINSTANCE param_1,int param_2)

{
  UINT UVar1;
  
  FUN_00011910();
  UVar1 = FUN_00012910(param_1,param_2);
  FUN_00011850(UVar1);
  FUN_00011870(UVar1);
  return;
}



/* 00011694 FUN_00011694 */

/* Boundary evidence: original MIPS .pdata 00011694..000116d3. Semantic name remains unreviewed. */

void FUN_00011694(_EXCEPTION_POINTERS *param_1)

{
  int in_v0;
  
  *(DWORD *)(in_v0 + -0x20) = param_1->ExceptionRecord->ExceptionCode;
  _XcptFilter(*(ulong *)(in_v0 + -0x20),param_1);
  return;
}



/* 000116d4 entry */

/* Boundary evidence: original MIPS .pdata 000116d4..0001172f. Semantic name remains unreviewed. */

void entry(HINSTANCE param_1,int param_2)

{
  FUN_0001194c();
  FUN_00011600(param_1,param_2);
  return;
}



/* 00011730 FUN_00011730 */

/* Boundary evidence: original MIPS .pdata 00011730..0001184f. Semantic name remains unreviewed. */

void FUN_00011730(UINT param_1,int param_2,int param_3)

{
  LPCRITICAL_SECTION lpCriticalSection;
  undefined4 *_Memory;
  
  DAT_0001e2ac = (undefined1)param_3;
  if (param_2 == 0) {
    _Memory = DAT_0001e2e8;
    if (DAT_0001e2e8 != (undefined4 *)0x0) {
      while (DAT_0001e2e4 = DAT_0001e2e4 + -1, _Memory <= DAT_0001e2e4) {
        if ((code *)*DAT_0001e2e4 != (code *)0x0) {
          (*(code *)*DAT_0001e2e4)();
          _Memory = DAT_0001e2e8;
        }
      }
      free(_Memory);
      DAT_0001e2e4 = (undefined4 *)0x0;
      DAT_0001e2e8 = (undefined4 *)0x0;
    }
    FUN_000118bc((undefined4 *)&DAT_00011010,(undefined4 *)&DAT_00011014);
  }
  FUN_000118bc((undefined4 *)&DAT_00011018,(undefined4 *)&DAT_0001101c);
  if (param_3 == 0) {
    TerminateProcess((HANDLE)0x42,param_1);
  }
  else {
    lpCriticalSection = (LPCRITICAL_SECTION)InterlockedExchange((LONG *)&DAT_0001e2ec,0);
    if (lpCriticalSection != (LPCRITICAL_SECTION)0x0) {
      DeleteCriticalSection(lpCriticalSection);
      free(lpCriticalSection);
    }
  }
  return;
}



/* 00011850 FUN_00011850 */

/* Boundary evidence: original MIPS .pdata 00011850..0001186f. Semantic name remains unreviewed. */

void FUN_00011850(UINT param_1)

{
  FUN_00011730(param_1,0,0);
  return;
}



/* 00011870 FUN_00011870 */

/* Boundary evidence: original MIPS .pdata 00011870..000118bb. Semantic name remains unreviewed. */

void FUN_00011870(UINT param_1)

{
  DAT_0001e2ac = 0;
  FUN_000118bc((undefined4 *)&DAT_00011018,(undefined4 *)&DAT_0001101c);
  TerminateProcess((HANDLE)0x42,param_1);
  return;
}



/* 000118bc FUN_000118bc */

/* Boundary evidence: original MIPS .pdata 000118bc..0001190f. Semantic name remains unreviewed. */

void FUN_000118bc(undefined4 *param_1,undefined4 *param_2)

{
  for (; param_1 < param_2; param_1 = param_1 + 1) {
    if ((code *)*param_1 != (code *)0x0) {
      (*(code *)*param_1)();
    }
  }
  return;
}



/* 00011910 FUN_00011910 */

/* Boundary evidence: original MIPS .pdata 00011910..0001194b. Semantic name remains unreviewed. */

void FUN_00011910(void)

{
  FUN_000118bc((undefined4 *)&DAT_00011008,(undefined4 *)&DAT_0001100c);
  FUN_000118bc((undefined4 *)&DAT_00011000,(undefined4 *)&DAT_00011004);
  return;
}



/* 0001194c FUN_0001194c */

/* Boundary evidence: original MIPS .pdata 0001194c..000119bf. Semantic name remains unreviewed. */

void FUN_0001194c(void)

{
  uint uVar1;
  
  if ((DAT_0001e29c == 0) || (DAT_0001e29c == 0xb064)) {
    uVar1 = __security_gen_cookie2();
    DAT_0001e29c = uVar1 >> 0x10 ^ uVar1 & 0xffff;
    if (DAT_0001e29c == 0) {
      DAT_0001e29c = 0xb064;
    }
  }
  DAT_0001e2a0 = ~DAT_0001e29c;
  return;
}



/* 00011a60 FUN_00011a60 */

/* Boundary evidence: original MIPS .pdata 00011a60..00011bab. Semantic name remains unreviewed. */

undefined4 FUN_00011a60(HINSTANCE param_1)

{
  HWND pHVar1;
  BOOL BVar2;
  int iVar3;
  undefined4 uVar4;
  WCHAR aWStack_270 [40];
  WCHAR aWStack_220 [260];
  uint local_18;
  
  local_18 = DAT_0001e29c;
  uVar4 = 1;
  pHVar1 = CreateWindowExW(0,L"RapiSrv",L"Pegasus Remote API Server",0xc80000,0,0,1,1,(HWND)0x0,
                           (HMENU)0x0,param_1,(LPVOID)0x0);
  if (pHVar1 == (HWND)0x0) {
    FUN_0001d140(local_18);
    uVar4 = 0;
  }
  else {
    BVar2 = SystemParametersInfoW(0x104,0x208,aWStack_220,0);
    if (BVar2 == 0) {
      DAT_0001e2dc = 0;
    }
    else {
      LoadStringW(param_1,0x3f3,aWStack_270,0x28);
      iVar3 = lstrcmpW(aWStack_220,aWStack_270);
      if (iVar3 == 0) {
        DAT_0001e2dc = 0;
      }
      else {
        LoadStringW(param_1,0x3f4,aWStack_270,0x28);
        iVar3 = lstrcmpW(aWStack_220,aWStack_270);
        if (iVar3 == 0) {
          DAT_0001e2dc = 1;
        }
        else {
          DAT_0001e2dc = 2;
        }
      }
    }
    FUN_0001d140(local_18);
  }
  return uVar4;
}



/* 00011bac FUN_00011bac */

/* Boundary evidence: original MIPS .pdata 00011bac..00011c43. Semantic name remains unreviewed. */

int FUN_00011bac(SOCKET param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  
  iVar1 = 0;
  iVar2 = 0;
  if (param_3 != 0) {
    do {
      iVar1 = recv(param_1,(char *)(iVar2 + param_2),param_3 - iVar2,0);
      if ((iVar1 == -1) || (iVar1 == 0)) {
        return 0;
      }
      iVar2 = iVar2 + iVar1;
    } while (iVar1 != param_3);
  }
  return iVar1;
}



/* 00011c44 FUN_00011c44 */

/* Boundary evidence: original MIPS .pdata 00011c44..00011d1f. Semantic name remains unreviewed. */

void FUN_00011c44(LPCWSTR param_1)

{
  undefined1 auStack_50 [4];
  undefined4 local_4c;
  undefined4 local_48;
  char acStack_30 [16];
  CHAR aCStack_20 [20];
  uint local_c;
  
  local_c = DAT_0001e29c;
  WideCharToMultiByte(0,0,param_1,0x11,aCStack_20,0x11,(LPCSTR)0x0,(LPBOOL)0x0);
  if (DAT_0001e2d8 != 0) {
    freeaddrinfo();
    DAT_0001e2d8 = 0;
  }
  memset(auStack_50,0,0x20);
  local_4c = 0;
  local_48 = 1;
  sprintf(acStack_30,"%d",0x162f);
  getaddrinfo(aCStack_20,acStack_30,auStack_50,&DAT_0001e2d8);
  FUN_0001d140(local_c);
  return;
}



/* 00011d20 FUN_00011d20 */

/* Boundary evidence: original MIPS .pdata 00011d20..00011da7. Semantic name remains unreviewed. */

undefined4 FUN_00011d20(short *param_1)

{
  int *piVar1;
  short *psVar2;
  short *psVar3;
  int iVar4;
  
  psVar2 = DAT_0001e2d8;
  psVar3 = param_1;
  if (DAT_0001e2d8 != (short *)0x0) {
    while (psVar3 != (short *)0x0) {
      if ((*(int *)(psVar2 + 2) == (int)*param_1) &&
         (iVar4 = FUN_000132e0(param_1,*(short **)(psVar2 + 0xc)), iVar4 != 0)) {
        return 1;
      }
      piVar1 = (int *)(psVar2 + 0xe);
      psVar2 = (short *)*piVar1;
      psVar3 = (short *)*piVar1;
    }
  }
  return 0;
}



/* 00011da8 FUN_00011da8 */

/* Boundary evidence: original MIPS .pdata 00011da8..00011f77. Semantic name remains unreviewed. */

LRESULT FUN_00011da8(HWND param_1,UINT param_2,WPARAM param_3,int *param_4)

{
  LRESULT LVar1;
  uint _Size;
  WCHAR aWStack_40 [18];
  uint local_1c;
  
  local_1c = DAT_0001e29c;
  if (param_2 == 2) {
    if ((DAT_0001e2a4 != -1) || (DAT_0001e2a8 != -1)) {
      DAT_0001e2c8 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCWSTR)0x0);
      if (DAT_0001e2a4 != -1) {
        closesocket(DAT_0001e2a4);
        DAT_0001e2a4 = -1;
      }
      if (DAT_0001e2a8 != -1) {
        closesocket(DAT_0001e2a8);
        DAT_0001e2a8 = -1;
      }
      if (DAT_0001e2c8 != (HANDLE)0x0) {
        WaitForSingleObject(DAT_0001e2c8,10000);
        CloseHandle(DAT_0001e2c8);
        DAT_0001e2c8 = (HANDLE)0x0;
      }
    }
    PostQuitMessage(0);
  }
  else if (param_2 == 0x4a) {
    if (((param_4 != (int *)0x0) && (*param_4 == 0x1f5)) && (_Size = param_4[1], _Size < 0x21)) {
      DAT_0001e2d4 = param_3;
      memcpy(aWStack_40,(void *)param_4[2],_Size);
      *(undefined2 *)((int)aWStack_40 + (_Size & 0xfffffffe)) = 0;
      FUN_00011c44(aWStack_40);
    }
  }
  else {
    if (param_2 != 0x47c) {
      LVar1 = DefWindowProcW(param_1,param_2,param_3,(LPARAM)param_4);
      FUN_0001d140(local_1c);
      return LVar1;
    }
    DestroyWindow(param_1);
  }
  FUN_0001d140(local_1c);
  return 0;
}



/* 00011f78 FUN_00011f78 */

/* Boundary evidence: original MIPS .pdata 00011f78..0001203f. Semantic name remains unreviewed. */

undefined4 FUN_00011f78(SOCKET param_1)

{
  undefined4 *puVar1;
  int *piVar2;
  int iVar3;
  
  puVar1 = operator_new(0xc);
  if (puVar1 == (undefined4 *)0x0) {
    piVar2 = (int *)0x0;
  }
  else {
    piVar2 = FUN_00012a90(puVar1);
  }
  if (piVar2 != (int *)0x0) {
    iVar3 = FUN_00012aa4(piVar2,param_1);
    if (-1 < iVar3) {
      FUN_00012e30(piVar2);
    }
    FUN_00012be4();
    FUN_00012db4(piVar2);
    operator_delete(piVar2);
  }
  closesocket(param_1);
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_0001e2b0);
  if (DAT_0001e2d0 != (int *)0x0) {
    FUN_00013100(DAT_0001e2d0,param_1);
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_0001e2b0);
  return 0;
}



/* 00012040 FUN_00012040 */

/* Boundary evidence: original MIPS .pdata 00012040..0001290f. Semantic name remains unreviewed. */

undefined4 FUN_00012040(void)

{
  int *piVar1;
  char cVar2;
  int iVar3;
  uint uVar4;
  undefined4 *puVar5;
  int iVar6;
  LSTATUS LVar7;
  code *pcVar8;
  SOCKET s;
  SOCKET *pSVar9;
  byte *pbVar10;
  uint uVar11;
  uint uVar12;
  int iVar13;
  SOCKET SVar14;
  SOCKET *pSVar15;
  uint nfds;
  HANDLE pvVar16;
  char local_598 [4];
  DWORD local_594;
  ushort local_590 [2];
  HKEY local_58c;
  DWORD local_588;
  int local_584;
  char local_580 [8];
  SOCKET local_578 [3];
  SOCKET *local_56c;
  HANDLE local_568;
  DWORD local_564 [3];
  timeval local_558;
  fd_set local_550;
  sockaddr asStack_448 [8];
  WSADATA WStack_3c8;
  byte local_238 [520];
  uint local_30;
  
  local_30 = DAT_0001e29c;
  iVar13 = 0;
  pvVar16 = (HANDLE)0x0;
  local_564[1] = 4;
  local_578[2] = GetPasswordActive();
  iVar3 = WSAStartup(0x202,&WStack_3c8);
  pSVar15 = &DAT_0001e2a4;
  local_56c = &DAT_0001e2a4;
  if (iVar3 == 0) {
    uVar4 = FUN_00013360();
    iVar3 = FUN_000135c8(&DAT_0001e2a4,0x3de,0,0,2);
    if (iVar3 != 0) {
      local_578[0] = DAT_0001e2a4;
    }
    nfds = (uint)(iVar3 != 0);
    if (((uVar4 & 2) != 0) && (iVar13 = FUN_000135c8(&DAT_0001e2a8,0x3de,0,1,2), iVar13 != 0)) {
      local_578[nfds] = DAT_0001e2a8;
      nfds = nfds + 1;
    }
    if ((iVar3 == 0) && (SVar14 = DAT_0001e2a8, s = DAT_0001e2a4, iVar13 == 0)) goto LAB_00012830;
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_0001e2b0);
    puVar5 = operator_new(4);
    if (puVar5 == (undefined4 *)0x0) {
      DAT_0001e2d0 = (int *)0x0;
    }
    else {
      DAT_0001e2d0 = FUN_00012f60(puVar5);
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_0001e2b0);
    if (DAT_0001e2d0 != (int *)0x0) {
      local_568 = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,0,0,L"RAPI:STARTEVNT");
      EventModify(local_568,3);
LAB_00012200:
      memset(&local_558,0,8);
      uVar4 = 0;
      local_558.tv_sec = -1;
      local_550.fd_count = 0;
      if (nfds != 0) {
        pSVar15 = local_578;
        uVar12 = nfds;
        do {
          uVar11 = 0;
          if (uVar4 != 0) {
            pSVar9 = local_550.fd_array;
            do {
              if (*pSVar9 == *pSVar15) break;
              uVar11 = uVar11 + 1;
              pSVar9 = pSVar9 + 1;
            } while (uVar11 < uVar4);
          }
          if ((uVar11 == uVar4) && (uVar4 < 0x40)) {
            local_550.fd_array[uVar11] = *pSVar15;
            uVar4 = local_550.fd_count + 1;
            local_550.fd_count = uVar4;
          }
          uVar12 = uVar12 - 1;
          pSVar15 = pSVar15 + 1;
        } while (uVar12 != 0);
      }
      iVar3 = select(nfds,&local_550,(fd_set *)0x0,(fd_set *)0x0,&local_558);
      pSVar15 = local_56c;
      pvVar16 = local_568;
      if (iVar3 != -1) {
        iVar3 = 0;
        if (nfds != 0) {
          pSVar15 = local_578;
          do {
            SVar14 = *pSVar15;
            local_584 = 0x80;
            iVar13 = __WSAFDIsSet(SVar14,&local_550);
            if (iVar13 != 0) {
              uVar4 = 0;
              if (local_550.fd_count != 0) {
                pSVar9 = local_550.fd_array;
LAB_000122f4:
                if (*pSVar9 != SVar14) goto code_r0x00012300;
                if (uVar4 < local_550.fd_count - 1) {
                  pSVar9 = local_550.fd_array + uVar4;
                  do {
                    uVar4 = uVar4 + 1;
                    *pSVar9 = pSVar9[1];
                    pSVar9 = pSVar9 + 1;
                  } while (uVar4 < local_550.fd_count - 1);
                }
                local_550.fd_count = local_550.fd_count - 1;
              }
LAB_0001235c:
              pvVar16 = (HANDLE)accept(SVar14,asStack_448,&local_584);
              if (pvVar16 == (LPVOID)0xffffffff) break;
              iVar13 = getsockopt((SOCKET)pvVar16,0xffff,0x1001,(char *)&DAT_0001e2cc,
                                  (int *)(local_564 + 1));
              if (iVar13 != 0) {
                DAT_0001e2cc = 0x800;
              }
              if (DAT_0001e2d8 == 0) {
                local_594 = 0x100;
                WSAAddressToStringW(asStack_448,local_584,0,local_238,&local_594);
                pcVar8 = closesocket_exref;
              }
              else {
                iVar13 = FUN_00011d20((short *)asStack_448);
                if (iVar13 == 0) {
                  local_594 = 0x100;
                  WSAAddressToStringW(asStack_448,local_584,0,local_238,&local_594);
                  pcVar8 = closesocket_exref;
                }
                else {
                  local_580[0] = '\x01';
                  local_580[1] = '\0';
                  local_580[2] = '\0';
                  local_580[3] = '\0';
                  iVar13 = setsockopt((SOCKET)pvVar16,0xffff,0x80,local_580,4);
                  if (iVar13 != 0) {
                    closesocket((SOCKET)pvVar16);
                    break;
                  }
                  if ((local_578[2] == 0) || (DAT_0001e2d4 != 0)) {
LAB_00012760:
                    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_0001e2b0);
                    iVar13 = FUN_0001308c(DAT_0001e2d0,pvVar16,3);
                    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_0001e2b0);
                    if (iVar13 == 0) {
                      closesocket((SOCKET)pvVar16);
                      break;
                    }
                    pvVar16 = CreateThread((LPSECURITY_ATTRIBUTES)0x0,0,FUN_00011f78,pvVar16,0,
                                           (LPDWORD)0x0);
                    pcVar8 = CloseHandle_exref;
                    if (pvVar16 == (HANDLE)0x0) goto LAB_000127d0;
                  }
                  else {
                    local_594 = 0;
                    iVar13 = 0;
                    local_564[0] = 0;
                    do {
                      iVar6 = recv((SOCKET)pvVar16,(char *)((int)local_590 + iVar13),2 - iVar13,0);
                      pcVar8 = closesocket_exref;
                      if ((iVar6 == -1) || (iVar6 == 0)) goto LAB_000127c4;
                      iVar13 = iVar13 + iVar6;
                    } while (iVar6 != 2);
                    uVar4 = (uint)local_590[0];
                    if (uVar4 < 0x208) {
                      memset(local_238,0,0x208);
                      uVar4 = FUN_00011bac((SOCKET)pvVar16,(int)local_238,uVar4);
                      pcVar8 = closesocket_exref;
                      if (uVar4 == local_590[0]) {
                        LVar7 = RegOpenKeyExW((HKEY)0x80000002,L"Ident",0,0xf003f,&local_58c);
                        if (LVar7 == 0) {
                          local_594 = 4;
                          LVar7 = RegQueryValueExW(local_58c,L"PegId",(LPDWORD)0x0,(LPDWORD)0x0,
                                                   (LPBYTE)(local_580 + 4),&local_594);
                          if (LVar7 == 0) {
                            uVar4 = 0;
                            if (local_590[0] != 0) {
                              do {
                                pbVar10 = local_238 + uVar4;
                                uVar4 = uVar4 + 1;
                                *pbVar10 = *pbVar10 ^ (byte)local_580._4_4_;
                              } while (uVar4 < local_590[0]);
                            }
                          }
                          RegCloseKey(local_58c);
                        }
                        local_58c = (HKEY)0x0;
                        local_588 = 0;
                        LVar7 = RegCreateKeyExW((HKEY)0x80000002,L"ControlPanel\\Password",0,
                                                (LPWSTR)0x0,0,0xf003f,(LPSECURITY_ATTRIBUTES)0x0,
                                                &local_58c,local_564);
                        if (LVar7 == 0) {
                          local_594 = 4;
                          RegQueryValueExW(local_58c,L"TimeOut",(LPDWORD)0x0,(LPDWORD)0x0,
                                           (LPBYTE)&local_588,&local_594);
                          Sleep(local_588);
                          local_598[0] = GetPasswordActive();
                          cVar2 = '\0';
                          if (local_598[0] != '\0') {
                            cVar2 = CheckPassword(local_238);
                          }
                          local_598[0] = cVar2;
                          memset(local_238,0,0x208);
                          if (cVar2 == '\0') {
                            local_588 = (local_588 + 1) * 2;
                          }
                          else {
                            local_588 = 0;
                          }
                          if (local_58c != (HKEY)0x0) {
                            RegSetValueExW(local_58c,L"TimeOut",0,0,(BYTE *)&local_588,local_594);
                            RegCloseKey(local_58c);
                          }
                          iVar13 = send((SOCKET)pvVar16,local_598,1,0);
                          pcVar8 = closesocket_exref;
                          if ((iVar13 == 1) && (local_598[0] != '\0')) goto LAB_00012760;
                        }
                        else {
                          local_598[0] = '\0';
                          pcVar8 = closesocket_exref;
                        }
                      }
                    }
                  }
                }
              }
LAB_000127c4:
              (*pcVar8)(pvVar16);
            }
LAB_000127d0:
            iVar3 = iVar3 + 1;
            pSVar15 = pSVar15 + 1;
          } while (iVar3 < (int)nfds);
        }
        goto LAB_00012200;
      }
    }
  }
  s = *pSVar15;
  SVar14 = pSVar15[1];
LAB_00012830:
  if (s != 0xffffffff) {
    closesocket(s);
    SVar14 = pSVar15[1];
    *pSVar15 = 0xffffffff;
  }
  if (SVar14 != 0xffffffff) {
    closesocket(SVar14);
    pSVar15[1] = 0xffffffff;
  }
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_0001e2b0);
  piVar1 = DAT_0001e2d0;
  if (DAT_0001e2d0 != (int *)0x0) {
    FUN_00012f6c(DAT_0001e2d0);
    operator_delete(piVar1);
    DAT_0001e2d0 = (int *)0x0;
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_0001e2b0);
  WSACleanup();
  if (DAT_0001e2c8 != 0) {
    EventModify(DAT_0001e2c8,3);
  }
  if (pvVar16 != (HANDLE)0x0) {
    CloseHandle(pvVar16);
  }
  FUN_0001d140(local_30);
  return 0;
code_r0x00012300:
  uVar4 = uVar4 + 1;
  pSVar9 = pSVar9 + 1;
  if (local_550.fd_count <= uVar4) goto LAB_0001235c;
  goto LAB_000122f4;
}



/* 00012910 FUN_00012910 */

/* Boundary evidence: original MIPS .pdata 00012910..00012a8f. Semantic name remains unreviewed. */

undefined4 FUN_00012910(HINSTANCE param_1,int param_2)

{
  ATOM AVar1;
  HWND pHVar2;
  undefined2 extraout_var;
  int iVar3;
  HANDLE hObject;
  BOOL BVar4;
  MSG MStack_60;
  WNDCLASSW local_40;
  
  DAT_0001e2c4 = param_1;
  pHVar2 = FindWindowW(L"RapiSrv",L"Pegasus Remote API Server");
  if (pHVar2 == (HWND)0x0) {
    if (param_2 == 0) {
      local_40.style = 0;
      local_40.lpfnWndProc = FUN_00011da8;
      local_40.cbClsExtra = 0;
      local_40.cbWndExtra = 0;
      local_40.hInstance = param_1;
      local_40.hIcon = LoadImageW(param_1,(LPCWSTR)0x3e9,1,0x10,0x10,0);
      local_40.hCursor = (HCURSOR)0x0;
      local_40.hbrBackground = GetStockObject(0);
      local_40.lpszMenuName = (LPCWSTR)0x0;
      local_40.lpszClassName = L"RapiSrv";
      AVar1 = RegisterClassW(&local_40);
      if (CONCAT22(extraout_var,AVar1) == 0) {
        return 0;
      }
    }
    iVar3 = FUN_00011a60(param_1);
    if (iVar3 != 0) {
      InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_0001e2b0);
      hObject = CreateThread((LPSECURITY_ATTRIBUTES)0x0,0,FUN_00012040,(LPVOID)0x0,0,(LPDWORD)0x0);
      while (BVar4 = GetMessageW(&MStack_60,(HWND)0x0,0,0), BVar4 != 0) {
        TranslateMessage(&MStack_60);
        DispatchMessageW(&MStack_60);
      }
      if (hObject != (HANDLE)0x0) {
        CloseHandle(hObject);
      }
      DeleteCriticalSection((LPCRITICAL_SECTION)&DAT_0001e2b0);
      return MStack_60.wParam;
    }
  }
  return 0;
}



/* 00012a90 FUN_00012a90 */

undefined4 * FUN_00012a90(undefined4 *param_1)

{
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  return param_1;
}



/* 00012aa4 FUN_00012aa4 */

/* Boundary evidence: original MIPS .pdata 00012aa4..00012be3. Semantic name remains unreviewed. */

undefined4 FUN_00012aa4(undefined4 *param_1,SOCKET param_2)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int *piVar3;
  
  if (param_2 == 0xffffffff) {
    uVar1 = 0x80070057;
  }
  else {
    puVar2 = operator_new(0x118);
    if (puVar2 == (undefined4 *)0x0) {
      puVar2 = (undefined4 *)0x0;
    }
    else {
      puVar2 = FUN_0001c7cc(puVar2,param_2);
    }
    *param_1 = puVar2;
    if (puVar2 != (undefined4 *)0x0) {
      puVar2 = operator_new(0x14);
      if (puVar2 == (undefined4 *)0x0) {
        puVar2 = (undefined4 *)0x0;
      }
      else {
        puVar2 = FUN_0001c8a0(puVar2);
      }
      param_1[1] = puVar2;
      if (puVar2 != (undefined4 *)0x0) {
        puVar2 = operator_new(4);
        if (puVar2 == (undefined4 *)0x0) {
          puVar2 = (undefined4 *)0x0;
        }
        else {
          puVar2 = FUN_00012f60(puVar2);
        }
        param_1[2] = puVar2;
        if (puVar2 != (undefined4 *)0x0) {
          return 0;
        }
      }
    }
    uVar1 = 0x8007000e;
  }
  puVar2 = (undefined4 *)*param_1;
  if (puVar2 != (undefined4 *)0x0) {
    FUN_0001c09c(puVar2);
    operator_delete(puVar2);
  }
  puVar2 = (undefined4 *)param_1[1];
  if (puVar2 != (undefined4 *)0x0) {
    FUN_0001c8e4(puVar2);
    operator_delete(puVar2);
  }
  piVar3 = (int *)param_1[2];
  if (piVar3 != (int *)0x0) {
    FUN_00012f6c(piVar3);
    operator_delete(piVar3);
    param_1[2] = 0;
  }
  return uVar1;
}



/* 00012be4 FUN_00012be4 */

undefined4 FUN_00012be4(void)

{
  return 0;
}



/* 00012bec FUN_00012bec */

/* Boundary evidence: original MIPS .pdata 00012bec..00012db3. Semantic name remains unreviewed. */

uint FUN_00012bec(int *param_1,uint param_2,uint param_3)

{
  int iVar1;
  uint uVar2;
  DWORD DVar3;
  undefined4 local_18 [2];
  
  local_18[0] = 0;
  if (0x55 < param_2) {
    return 0x80004005;
  }
  if (((param_2 == 0x30) || (param_2 == 0x31)) && (iVar1 = WaitForAPIReady(0x55,0), iVar1 != 0)) {
    FUN_0001ca4c(param_1[1]);
    return 0x80004005;
  }
  if (param_2 == 0x45) {
    uVar2 = FUN_0001c660(*param_1,(int *)param_1[1],param_3);
    if ((int)uVar2 < 0) {
      return uVar2;
    }
    iVar1 = FUN_0001a60c(param_1);
    if (iVar1 == 0x9d) {
      return 0;
    }
  }
  else {
    if (param_2 == 0x46) {
      uVar2 = FUN_00019ec4(param_1);
    }
    else {
      if ((0x46 < param_2) && (param_2 < 0x49)) {
        FUN_0001c660(*param_1,(int *)param_1[1],param_3);
        (*(code *)(&PTR_FUN_000110f8)[param_2])(param_1,param_1[2]);
        return 0;
      }
      uVar2 = FUN_0001c660(*param_1,(int *)param_1[1],param_3);
      if ((int)uVar2 < 0) {
        return uVar2;
      }
      uVar2 = (*(code *)(&PTR_FUN_000110f8)[param_2])(param_1[1],param_1[2]);
    }
    if ((int)uVar2 < 0) {
      return uVar2;
    }
  }
  uVar2 = FUN_0001ce7c((int *)param_1[1],local_18,4);
  if ((int)uVar2 < 0) {
    return uVar2;
  }
  DVar3 = FUN_0001c100(*param_1,(int *)param_1[1]);
  if (-1 < (int)DVar3) {
    return 0;
  }
  return DVar3;
}



/* 00012db4 FUN_00012db4 */

/* Boundary evidence: original MIPS .pdata 00012db4..00012e2f. Semantic name remains unreviewed. */

void FUN_00012db4(undefined4 *param_1)

{
  int *piVar1;
  undefined4 *puVar2;
  
  puVar2 = (undefined4 *)*param_1;
  if (puVar2 != (undefined4 *)0x0) {
    FUN_0001c09c(puVar2);
    operator_delete(puVar2);
  }
  puVar2 = (undefined4 *)param_1[1];
  if (puVar2 != (undefined4 *)0x0) {
    FUN_0001c8e4(puVar2);
    operator_delete(puVar2);
  }
  piVar1 = (int *)param_1[2];
  if (piVar1 != (int *)0x0) {
    FUN_00012f6c(piVar1);
    operator_delete(piVar1);
  }
  return;
}



/* 00012e30 FUN_00012e30 */

/* WARNING: Type propagation algorithm not settling */
/* Boundary evidence: original MIPS .pdata 00012e30..00012f5f. Semantic name remains unreviewed. */

uint FUN_00012e30(int *param_1)

{
  uint local_18;
  int local_14;
  uint local_10 [2];
  
  local_18 = 0;
  local_18 = FUN_0001ca4c(param_1[1]);
  if (-1 < (int)local_18) {
    while (local_18 = FUN_0001c250(*param_1,(int)&local_14,4,(uint *)0x0), -1 < (int)local_18) {
      if (local_14 == 0) {
LAB_00012ed8:
        local_18 = 0x80004005;
        break;
      }
      local_18 = FUN_0001c250(*param_1,(int)local_10,4,(uint *)0x0);
      if ((int)local_18 < 0) break;
      if (0x55 < local_10[0]) goto LAB_00012ed8;
      local_18 = FUN_00012bec(param_1,local_10[0],local_14 - 4);
      if (((int)local_18 < 0) || (local_18 = FUN_0001ca4c(param_1[1]), (int)local_18 < 0)) break;
    }
  }
  if (((local_18 & 0xffff0000) != 0x80070000) || ((local_18 & 0xffff) < 0x2711)) {
    local_10[1] = 1;
    FUN_0001ca4c(param_1[1]);
    FUN_0001cd50((int *)param_1[1],local_10 + 1,4);
    FUN_0001cd50((int *)param_1[1],&local_18,4);
    FUN_0001c100(*param_1,(int *)param_1[1]);
    FUN_0001ca4c(param_1[1]);
  }
  return local_18;
}



/* 00012f60 FUN_00012f60 */

undefined4 * FUN_00012f60(undefined4 *param_1)

{
  *param_1 = 0;
  return param_1;
}



/* 00012f6c FUN_00012f6c */

/* Boundary evidence: original MIPS .pdata 00012f6c..0001308b. Semantic name remains unreviewed. */

void FUN_00012f6c(int *param_1)

{
  int iVar1;
  code *pcVar2;
  void *pvVar3;
  
  iVar1 = *param_1;
  do {
    if (iVar1 == 0) {
      return;
    }
    pvVar3 = (void *)*param_1;
    *param_1 = *(int *)((int)pvVar3 + 4);
    iVar1 = *(int *)((int)pvVar3 + 8);
    if (iVar1 == 2) {
      iVar1 = *(int *)((int)pvVar3 + 0xc);
      pcVar2 = FindClose_exref;
      if (iVar1 != -1) goto LAB_0001304c;
    }
    else if (iVar1 == 3) {
      if (*(SOCKET *)((int)pvVar3 + 0xc) != 0xffffffff) {
        closesocket(*(SOCKET *)((int)pvVar3 + 0xc));
      }
    }
    else if (iVar1 == 4) {
      iVar1 = *(int *)((int)pvVar3 + 0xc);
      pcVar2 = RegCloseKey_exref;
      if (iVar1 != 0) goto LAB_0001304c;
    }
    else if (iVar1 == 5) {
      CeUnmountDBVol((int)pvVar3 + 0xc);
    }
    else {
      iVar1 = *(int *)((int)pvVar3 + 0xc);
      pcVar2 = CloseHandle_exref;
LAB_0001304c:
      (*pcVar2)(iVar1);
    }
    operator_delete(pvVar3);
    iVar1 = *param_1;
  } while( true );
}



/* 0001308c FUN_0001308c */

/* Boundary evidence: original MIPS .pdata 0001308c..000130ff. Semantic name remains unreviewed. */

undefined4 FUN_0001308c(undefined4 *param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  
  puVar1 = operator_new(0x1c);
  if (puVar1 == (undefined4 *)0x0) {
    uVar2 = 0;
  }
  else {
    *puVar1 = 0;
    puVar1[3] = param_2;
    puVar1[2] = param_3;
    puVar3 = (undefined4 *)*param_1;
    puVar1[1] = puVar3;
    if (puVar3 != (undefined4 *)0x0) {
      *puVar3 = puVar1;
    }
    *param_1 = puVar1;
    uVar2 = 1;
  }
  return uVar2;
}



/* 00013100 FUN_00013100 */

/* Boundary evidence: original MIPS .pdata 00013100..0001318f. Semantic name remains unreviewed. */

int FUN_00013100(int *param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = (int *)*param_1;
  while( true ) {
    if (piVar1 == (int *)0x0) {
      return 0;
    }
    if (piVar1[3] == param_2) break;
    piVar1 = (int *)piVar1[1];
  }
  if ((int *)piVar1[1] != (int *)0x0) {
    *(int *)piVar1[1] = *piVar1;
  }
  if (*piVar1 == 0) {
    *param_1 = piVar1[1];
  }
  else {
    *(int *)(*piVar1 + 4) = piVar1[1];
  }
  iVar2 = piVar1[2];
  operator_delete(piVar1);
  return iVar2;
}



/* 00013190 FUN_00013190 */

/* Boundary evidence: original MIPS .pdata 00013190..0001321f. Semantic name remains unreviewed. */

undefined4 FUN_00013190(undefined4 *param_1,undefined4 param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  
  puVar1 = operator_new(0x1c);
  if (puVar1 == (undefined4 *)0x0) {
    uVar2 = 0;
  }
  else {
    *puVar1 = 0;
    puVar1[3] = *param_3;
    puVar1[4] = param_3[1];
    puVar1[5] = param_3[2];
    puVar1[6] = param_3[3];
    puVar1[2] = param_2;
    puVar3 = (undefined4 *)*param_1;
    puVar1[1] = puVar3;
    if (puVar3 != (undefined4 *)0x0) {
      *puVar3 = puVar1;
    }
    *param_1 = puVar1;
    uVar2 = 1;
  }
  return uVar2;
}



/* 00013220 FUN_00013220 */

/* Boundary evidence: original MIPS .pdata 00013220..000132df. Semantic name remains unreviewed. */

undefined4 FUN_00013220(int *param_1,int param_2,void *param_3)

{
  int iVar1;
  int *piVar2;
  
  piVar2 = (int *)*param_1;
  while( true ) {
    if (piVar2 == (int *)0x0) {
      return 0;
    }
    if ((piVar2[2] == param_2) && (iVar1 = memcmp(piVar2 + 3,param_3,0x10), iVar1 == 0)) break;
    piVar2 = (int *)piVar2[1];
  }
  if ((int *)piVar2[1] != (int *)0x0) {
    *(int *)piVar2[1] = *piVar2;
  }
  if (*piVar2 == 0) {
    *param_1 = piVar2[1];
  }
  else {
    *(int *)(*piVar2 + 4) = piVar2[1];
  }
  operator_delete(piVar2);
  return 1;
}



/* 000132e0 FUN_000132e0 */

/* Boundary evidence: original MIPS .pdata 000132e0..0001335f. Semantic name remains unreviewed. */

undefined4 FUN_000132e0(short *param_1,short *param_2)

{
  int iVar1;
  
  if ((*param_1 == 0x17) && (*param_2 == 0x17)) {
    iVar1 = memcmp(param_1 + 4,param_2 + 4,0x10);
    if (iVar1 == 0) {
      return 1;
    }
  }
  else {
    if (*param_1 != 2) {
      return 0;
    }
    if (*param_2 != 2) {
      return 0;
    }
    if (*(int *)(param_1 + 2) == *(int *)(param_2 + 2)) {
      return 1;
    }
  }
  return 0;
}



/* 00013360 FUN_00013360 */

/* Boundary evidence: original MIPS .pdata 00013360..0001343b. Semantic name remains unreviewed. */

uint FUN_00013360(void)

{
  LSTATUS LVar1;
  uint uVar2;
  uint local_70;
  HKEY local_6c;
  DWORD local_68 [2];
  WCHAR aWStack_60 [40];
  uint local_10;
  
  local_10 = DAT_0001e29c;
  local_70 = 0;
  memcpy(aWStack_60,L"Software\\Microsoft\\Windows CE Services",0x4e);
  LVar1 = RegOpenKeyExW((HKEY)0x80000002,aWStack_60,0,0x20019,&local_6c);
  if (LVar1 == 0) {
    local_68[0] = 4;
    RegQueryValueExW(local_6c,L"IPVersionSetting",(LPDWORD)0x0,(LPDWORD)0x0,(LPBYTE)&local_70,
                     local_68);
    RegCloseKey(local_6c);
  }
  uVar2 = local_70 & 3;
  if (uVar2 == 0) {
    uVar2 = 3;
  }
  FUN_0001d140(local_10);
  return uVar2;
}



/* 0001343c FUN_0001343c */

/* Boundary evidence: original MIPS .pdata 0001343c..000135c7. Semantic name remains unreviewed. */

undefined4 FUN_0001343c(SOCKET *param_1,u_short param_2,int param_3,int param_4,int param_5)

{
  int iVar1;
  undefined4 uVar2;
  sockaddr local_a0;
  undefined4 local_88;
  uint local_20;
  
  local_20 = DAT_0001e29c;
  if (param_4 == 0) {
    memset(&local_a0,0,0x80);
    local_a0.sa_family = 2;
    local_a0.sa_data[2] = '\0';
    local_a0.sa_data[3] = '\0';
    local_a0.sa_data[4] = '\0';
    local_a0.sa_data[5] = '\0';
  }
  else {
    memset(&local_a0,0,0x80);
    local_a0.sa_family = 0x17;
    local_a0.sa_data[0] = '\0';
    local_a0.sa_data[1] = '\0';
    local_a0.sa_data[2] = '\0';
    local_a0.sa_data[3] = '\0';
    local_a0.sa_data[4] = '\0';
    local_a0.sa_data[5] = '\0';
    memset(local_a0.sa_data + 6,0,0x10);
    local_88 = 0;
  }
  local_a0.sa_data._0_2_ = htons(param_2);
  if (*param_1 != 0xffffffff) {
    iVar1 = bind(*param_1,&local_a0,0x80);
    if ((((iVar1 == -1) && (iVar1 = WSAGetLastError(), iVar1 != 0x2740)) ||
        (iVar1 = listen(*param_1,param_5), iVar1 == -1)) ||
       ((param_3 != 0 && (iVar1 = WSAEventSelect(*param_1,param_3,8), iVar1 == -1)))) {
      iVar1 = WSAGetLastError();
      closesocket(*param_1);
      *param_1 = 0xffffffff;
      WSASetLastError(iVar1);
    }
    uVar2 = 1;
    if (*param_1 != 0xffffffff) goto LAB_000135a0;
  }
  uVar2 = 0;
LAB_000135a0:
  FUN_0001d140(local_20);
  return uVar2;
}



/* 000135c8 FUN_000135c8 */

/* Boundary evidence: original MIPS .pdata 000135c8..000136b3. Semantic name remains unreviewed. */

undefined4 FUN_000135c8(SOCKET *param_1,u_short param_2,int param_3,int param_4,int param_5)

{
  SOCKET s;
  int iVar1;
  undefined4 uVar2;
  char local_28 [8];
  
  local_28[0] = '\x01';
  local_28[1] = '\0';
  local_28[2] = '\0';
  local_28[3] = '\0';
  *param_1 = 0xffffffff;
  uVar2 = 0;
  iVar1 = 2;
  if (param_4 != 0) {
    iVar1 = 0x17;
  }
  s = socket(iVar1,1,0);
  *param_1 = s;
  if (s != 0xffffffff) {
    iVar1 = setsockopt(s,0xffff,0x80,local_28,4);
    if (iVar1 != -1) {
      uVar2 = FUN_0001343c(param_1,param_2,param_3,param_4,param_5);
    }
  }
  return uVar2;
}



/* 000136b4 FUN_000136b4 */

/* Boundary evidence: original MIPS .pdata 000136b4..00013827. Semantic name remains unreviewed. */

int FUN_000136b4(int *param_1)

{
  int iVar1;
  PLONG local_28;
  DWORD local_24;
  LONG local_20;
  HANDLE local_1c;
  DWORD local_18;
  DWORD local_14;
  
  local_18 = 0;
  local_1c = (HANDLE)0x0;
  local_20 = 0;
  local_28 = (PLONG)0x0;
  local_24 = 0;
  if (param_1 == (int *)0x0) {
    iVar1 = -0x7ff8ffa9;
  }
  else {
    iVar1 = FUN_0001c900(param_1,&local_1c,4,1);
    if ((((-1 < iVar1) && (iVar1 = FUN_0001c900(param_1,&local_20,4,1), -1 < iVar1)) &&
        (iVar1 = FUN_0001cb2c(param_1,(int *)&local_28,0), -1 < iVar1)) &&
       (iVar1 = FUN_0001c900(param_1,&local_24,4,1), -1 < iVar1)) {
      FUN_0001ca4c((int)param_1);
      local_14 = SetFilePointer(local_1c,local_20,local_28,local_24);
      local_18 = GetLastError();
      iVar1 = FUN_0001cd50(param_1,&local_18,4);
      if (((-1 < iVar1) && (iVar1 = FUN_0001cd50(param_1,&local_14,4), -1 < iVar1)) &&
         (iVar1 = FUN_0001cf9c(param_1,local_28,4,1), -1 < iVar1)) {
        iVar1 = 0;
      }
    }
    if (local_28 != (PLONG)0x0) {
      operator_delete(local_28);
    }
  }
  return iVar1;
}



/* 00013828 FUN_00013828 */

/* Boundary evidence: original MIPS .pdata 00013828..000138db. Semantic name remains unreviewed. */

int FUN_00013828(int *param_1)

{
  int iVar1;
  HANDLE local_18;
  DWORD local_14;
  BOOL local_10 [2];
  
  local_14 = 0;
  local_18 = (HANDLE)0x0;
  if (param_1 == (int *)0x0) {
    iVar1 = -0x7ff8ffa9;
  }
  else {
    iVar1 = FUN_0001c900(param_1,&local_18,4,1);
    if (-1 < iVar1) {
      FUN_0001ca4c((int)param_1);
      local_10[0] = SetEndOfFile(local_18);
      local_14 = GetLastError();
      iVar1 = FUN_0001cd50(param_1,&local_14,4);
      if ((-1 < iVar1) && (iVar1 = FUN_0001cd50(param_1,local_10,4), -1 < iVar1)) {
        iVar1 = 0;
      }
    }
  }
  return iVar1;
}



/* 000138dc FUN_000138dc */

/* Boundary evidence: original MIPS .pdata 000138dc..000139ef. Semantic name remains unreviewed. */

int FUN_000138dc(int *param_1)

{
  int iVar1;
  LPCWSTR local_20;
  LPSECURITY_ATTRIBUTES local_1c;
  DWORD local_18;
  BOOL local_14;
  
  local_18 = 0;
  local_20 = (LPCWSTR)0x0;
  local_1c = (LPSECURITY_ATTRIBUTES)0x0;
  if (param_1 == (int *)0x0) {
    iVar1 = -0x7ff8ffa9;
  }
  else {
    iVar1 = FUN_0001cb2c(param_1,(int *)&local_20,0);
    if ((-1 < iVar1) && (iVar1 = FUN_0001cb2c(param_1,(int *)&local_1c,0), -1 < iVar1)) {
      FUN_0001ca4c((int)param_1);
      local_14 = CreateDirectoryW(local_20,local_1c);
      local_18 = GetLastError();
      iVar1 = FUN_0001cd50(param_1,&local_18,4);
      if ((-1 < iVar1) && (iVar1 = FUN_0001cd50(param_1,&local_14,4), -1 < iVar1)) {
        iVar1 = 0;
      }
    }
    if (local_20 != (LPCWSTR)0x0) {
      operator_delete(local_20);
    }
    if (local_1c != (LPSECURITY_ATTRIBUTES)0x0) {
      operator_delete(local_1c);
    }
  }
  return iVar1;
}



/* 000139f0 FUN_000139f0 */

/* Boundary evidence: original MIPS .pdata 000139f0..00013acb. Semantic name remains unreviewed. */

int FUN_000139f0(int *param_1)

{
  int iVar1;
  LPCWSTR local_20;
  DWORD local_1c;
  BOOL local_18 [2];
  
  local_1c = 0;
  local_20 = (LPCWSTR)0x0;
  if (param_1 == (int *)0x0) {
    iVar1 = -0x7ff8ffa9;
  }
  else {
    iVar1 = FUN_0001cb2c(param_1,(int *)&local_20,0);
    if (-1 < iVar1) {
      FUN_0001ca4c((int)param_1);
      local_18[0] = RemoveDirectoryW(local_20);
      local_1c = GetLastError();
      iVar1 = FUN_0001cd50(param_1,&local_1c,4);
      if ((-1 < iVar1) && (iVar1 = FUN_0001cd50(param_1,local_18,4), -1 < iVar1)) {
        iVar1 = 0;
      }
    }
    if (local_20 != (LPCWSTR)0x0) {
      operator_delete(local_20);
    }
  }
  return iVar1;
}



/* 00013acc FUN_00013acc */

/* Boundary evidence: original MIPS .pdata 00013acc..00013daf. Semantic name remains unreviewed. */

int FUN_00013acc(int *param_1)

{
  int iVar1;
  LPPROCESS_INFORMATION local_40;
  LPCWSTR local_3c;
  LPWSTR local_38;
  LPSECURITY_ATTRIBUTES local_34;
  LPSECURITY_ATTRIBUTES local_30;
  LPVOID local_2c;
  LPCWSTR local_28;
  LPSTARTUPINFOW local_24;
  DWORD local_20;
  BOOL local_1c;
  DWORD local_18;
  BOOL local_14;
  
  local_18 = 0;
  local_3c = (LPCWSTR)0x0;
  local_38 = (LPWSTR)0x0;
  local_34 = (LPSECURITY_ATTRIBUTES)0x0;
  local_30 = (LPSECURITY_ATTRIBUTES)0x0;
  local_1c = 0;
  local_20 = 0;
  local_2c = (LPVOID)0x0;
  local_28 = (LPCWSTR)0x0;
  local_24 = (LPSTARTUPINFOW)0x0;
  local_40 = (LPPROCESS_INFORMATION)0x0;
  if (param_1 == (int *)0x0) {
    iVar1 = -0x7ff8ffa9;
  }
  else {
    iVar1 = FUN_0001cb2c(param_1,(int *)&local_3c,0);
    if (((((-1 < iVar1) && (iVar1 = FUN_0001cb2c(param_1,(int *)&local_38,0), -1 < iVar1)) &&
         (iVar1 = FUN_0001cb2c(param_1,(int *)&local_34,0), -1 < iVar1)) &&
        ((((iVar1 = FUN_0001cb2c(param_1,(int *)&local_30,0), -1 < iVar1 &&
           (iVar1 = FUN_0001c900(param_1,&local_1c,4,1), -1 < iVar1)) &&
          ((iVar1 = FUN_0001c900(param_1,&local_20,4,1), -1 < iVar1 &&
           ((iVar1 = FUN_0001cb2c(param_1,(int *)&local_2c,0), -1 < iVar1 &&
            (iVar1 = FUN_0001cb2c(param_1,(int *)&local_28,0), -1 < iVar1)))))) &&
         (iVar1 = FUN_0001cb2c(param_1,(int *)&local_24,0), -1 < iVar1)))) &&
       (iVar1 = FUN_0001cb2c(param_1,(int *)&local_40,0), -1 < iVar1)) {
      FUN_0001ca4c((int)param_1);
      local_14 = CreateProcessW(local_3c,local_38,local_34,local_30,local_1c,local_20,local_2c,
                                local_28,local_24,local_40);
      local_18 = GetLastError();
      iVar1 = FUN_0001cd50(param_1,&local_18,4);
      if (((-1 < iVar1) && (iVar1 = FUN_0001cd50(param_1,&local_14,4), -1 < iVar1)) &&
         (iVar1 = FUN_0001cf9c(param_1,local_40,0x10,1), -1 < iVar1)) {
        iVar1 = 0;
      }
    }
    if (local_3c != (LPCWSTR)0x0) {
      operator_delete(local_3c);
    }
    if (local_38 != (LPWSTR)0x0) {
      operator_delete(local_38);
    }
    if (local_34 != (LPSECURITY_ATTRIBUTES)0x0) {
      operator_delete(local_34);
    }
    if (local_30 != (LPSECURITY_ATTRIBUTES)0x0) {
      operator_delete(local_30);
    }
    if (local_2c != (void *)0x0) {
      operator_delete(local_2c);
    }
    if (local_28 != (LPCWSTR)0x0) {
      operator_delete(local_28);
    }
    if (local_24 != (LPSTARTUPINFOW)0x0) {
      operator_delete(local_24);
    }
    if (local_40 != (LPPROCESS_INFORMATION)0x0) {
      operator_delete(local_40);
    }
  }
  return iVar1;
}



/* 00013db0 FUN_00013db0 */

/* Boundary evidence: original MIPS .pdata 00013db0..00013ec3. Semantic name remains unreviewed. */

int FUN_00013db0(int *param_1)

{
  int iVar1;
  LPCWSTR local_20;
  LPCWSTR local_1c;
  DWORD local_18;
  BOOL local_14;
  
  local_18 = 0;
  local_20 = (LPCWSTR)0x0;
  local_1c = (LPCWSTR)0x0;
  if (param_1 == (int *)0x0) {
    iVar1 = -0x7ff8ffa9;
  }
  else {
    iVar1 = FUN_0001cb2c(param_1,(int *)&local_20,0);
    if ((-1 < iVar1) && (iVar1 = FUN_0001cb2c(param_1,(int *)&local_1c,0), -1 < iVar1)) {
      FUN_0001ca4c((int)param_1);
      local_14 = MoveFileW(local_20,local_1c);
      local_18 = GetLastError();
      iVar1 = FUN_0001cd50(param_1,&local_18,4);
      if ((-1 < iVar1) && (iVar1 = FUN_0001cd50(param_1,&local_14,4), -1 < iVar1)) {
        iVar1 = 0;
      }
    }
    if (local_20 != (LPCWSTR)0x0) {
      operator_delete(local_20);
    }
    if (local_1c != (LPCWSTR)0x0) {
      operator_delete(local_1c);
    }
  }
  return iVar1;
}



/* 00013ec4 FUN_00013ec4 */

/* Boundary evidence: original MIPS .pdata 00013ec4..00013fff. Semantic name remains unreviewed. */

int FUN_00013ec4(int *param_1)

{
  int iVar1;
  LPCWSTR local_28;
  LPCWSTR local_24;
  BOOL local_20;
  DWORD local_1c;
  BOOL local_18 [2];
  
  local_1c = 0;
  local_28 = (LPCWSTR)0x0;
  local_24 = (LPCWSTR)0x0;
  local_20 = 0;
  if (param_1 == (int *)0x0) {
    iVar1 = -0x7ff8ffa9;
  }
  else {
    iVar1 = FUN_0001cb2c(param_1,(int *)&local_28,0);
    if (((-1 < iVar1) && (iVar1 = FUN_0001cb2c(param_1,(int *)&local_24,0), -1 < iVar1)) &&
       (iVar1 = FUN_0001c900(param_1,&local_20,4,1), -1 < iVar1)) {
      FUN_0001ca4c((int)param_1);
      local_18[0] = CopyFileW(local_28,local_24,local_20);
      local_1c = GetLastError();
      iVar1 = FUN_0001cd50(param_1,&local_1c,4);
      if ((-1 < iVar1) && (iVar1 = FUN_0001cd50(param_1,local_18,4), -1 < iVar1)) {
        iVar1 = 0;
      }
    }
    if (local_28 != (LPCWSTR)0x0) {
      operator_delete(local_28);
    }
    if (local_24 != (LPCWSTR)0x0) {
      operator_delete(local_24);
    }
  }
  return iVar1;
}



/* 00014000 FUN_00014000 */

/* Boundary evidence: original MIPS .pdata 00014000..00014123. Semantic name remains unreviewed. */

int FUN_00014000(int *param_1)

{
  int iVar1;
  LPDWORD local_20;
  HANDLE local_1c;
  DWORD local_18;
  DWORD local_14;
  
  local_18 = 0;
  local_1c = (HANDLE)0x0;
  local_20 = (LPDWORD)0x0;
  if (param_1 == (int *)0x0) {
    iVar1 = -0x7ff8ffa9;
  }
  else {
    iVar1 = FUN_0001c900(param_1,&local_1c,4,1);
    if ((-1 < iVar1) && (iVar1 = FUN_0001cb2c(param_1,(int *)&local_20,0), -1 < iVar1)) {
      FUN_0001ca4c((int)param_1);
      local_14 = GetFileSize(local_1c,local_20);
      local_18 = GetLastError();
      iVar1 = FUN_0001cd50(param_1,&local_18,4);
      if ((-1 < iVar1) &&
         ((iVar1 = FUN_0001cd50(param_1,&local_14,4), -1 < iVar1 &&
          (iVar1 = FUN_0001cf9c(param_1,local_20,4,1), -1 < iVar1)))) {
        iVar1 = 0;
      }
    }
    if (local_20 != (LPDWORD)0x0) {
      operator_delete(local_20);
    }
  }
  return iVar1;
}



/* 00014124 FUN_00014124 */

/* Boundary evidence: original MIPS .pdata 00014124..0001444f. Semantic name remains unreviewed. */

int FUN_00014124(int *param_1)

{
  uint uVar1;
  int iVar2;
  LPDWORD local_38;
  LPDWORD local_34;
  LPWSTR local_30;
  LPWSTR local_2c;
  PFILETIME local_28;
  LPDWORD local_24;
  DWORD local_20;
  HKEY local_1c;
  DWORD local_18;
  LSTATUS local_14;
  
  local_18 = 0;
  local_1c = (HKEY)0x0;
  local_20 = 0;
  local_30 = (LPWSTR)0x0;
  local_38 = (LPDWORD)0x0;
  local_24 = (LPDWORD)0x0;
  local_2c = (LPWSTR)0x0;
  local_34 = (LPDWORD)0x0;
  local_28 = (PFILETIME)0x0;
  if (param_1 == (int *)0x0) {
    iVar2 = -0x7ff8ffa9;
  }
  else {
    iVar2 = FUN_0001c900(param_1,&local_1c,4,1);
    if ((((-1 < iVar2) && (iVar2 = FUN_0001c900(param_1,&local_20,4,1), -1 < iVar2)) &&
        (iVar2 = FUN_0001cb2c(param_1,(int *)&local_30,0), -1 < iVar2)) &&
       (((iVar2 = FUN_0001cb2c(param_1,(int *)&local_38,0), -1 < iVar2 &&
         (iVar2 = FUN_0001cb2c(param_1,(int *)&local_24,0), -1 < iVar2)) &&
        ((iVar2 = FUN_0001cb2c(param_1,(int *)&local_2c,0), -1 < iVar2 &&
         ((iVar2 = FUN_0001cb2c(param_1,(int *)&local_34,0), -1 < iVar2 &&
          (iVar2 = FUN_0001cb2c(param_1,(int *)&local_28,0), -1 < iVar2)))))))) {
      FUN_0001ca4c((int)param_1);
      local_14 = RegEnumKeyExW(local_1c,local_20,local_30,local_38,local_24,local_2c,local_34,
                               local_28);
      local_18 = GetLastError();
      iVar2 = FUN_0001cd50(param_1,&local_18,4);
      if ((-1 < iVar2) && (iVar2 = FUN_0001cd50(param_1,&local_14,4), -1 < iVar2)) {
        if (local_38 == (LPDWORD)0x0) {
          uVar1 = 0;
        }
        else {
          uVar1 = (*local_38 + 1) * 2;
        }
        iVar2 = FUN_0001cf9c(param_1,local_30,uVar1,1);
        if ((-1 < iVar2) && (iVar2 = FUN_0001cf9c(param_1,local_38,4,1), -1 < iVar2)) {
          if (local_34 == (LPDWORD)0x0) {
            uVar1 = 0;
          }
          else {
            uVar1 = (*local_34 + 1) * 2;
          }
          iVar2 = FUN_0001cf9c(param_1,local_2c,uVar1,1);
          if (((-1 < iVar2) && (iVar2 = FUN_0001cf9c(param_1,local_34,4,1), -1 < iVar2)) &&
             (iVar2 = FUN_0001cf9c(param_1,local_28,8,1), -1 < iVar2)) {
            iVar2 = 0;
          }
        }
      }
    }
    if (local_30 != (LPWSTR)0x0) {
      operator_delete(local_30);
    }
    if (local_38 != (LPDWORD)0x0) {
      operator_delete(local_38);
    }
    if (local_24 != (LPDWORD)0x0) {
      operator_delete(local_24);
    }
    if (local_2c != (LPWSTR)0x0) {
      operator_delete(local_2c);
    }
    if (local_34 != (LPDWORD)0x0) {
      operator_delete(local_34);
    }
    if (local_28 != (PFILETIME)0x0) {
      operator_delete(local_28);
    }
  }
  return iVar2;
}



/* 00014450 FUN_00014450 */

/* Boundary evidence: original MIPS .pdata 00014450..00014553. Semantic name remains unreviewed. */

int FUN_00014450(int *param_1)

{
  int iVar1;
  LPCWSTR local_20;
  HKEY local_1c;
  DWORD local_18;
  LSTATUS local_14;
  
  local_18 = 0;
  local_1c = (HKEY)0x0;
  local_20 = (LPCWSTR)0x0;
  if (param_1 == (int *)0x0) {
    iVar1 = -0x7ff8ffa9;
  }
  else {
    iVar1 = FUN_0001c900(param_1,&local_1c,4,1);
    if ((-1 < iVar1) && (iVar1 = FUN_0001cb2c(param_1,(int *)&local_20,0), -1 < iVar1)) {
      FUN_0001ca4c((int)param_1);
      local_14 = RegDeleteKeyW(local_1c,local_20);
      local_18 = GetLastError();
      iVar1 = FUN_0001cd50(param_1,&local_18,4);
      if ((-1 < iVar1) && (iVar1 = FUN_0001cd50(param_1,&local_14,4), -1 < iVar1)) {
        iVar1 = 0;
      }
    }
    if (local_20 != (LPCWSTR)0x0) {
      operator_delete(local_20);
    }
  }
  return iVar1;
}



/* 00014554 FUN_00014554 */

/* Boundary evidence: original MIPS .pdata 00014554..00014877. Semantic name remains unreviewed. */

int FUN_00014554(int *param_1)

{
  uint uVar1;
  int iVar2;
  LPDWORD local_38;
  uint *local_34;
  LPWSTR local_30;
  LPDWORD local_2c;
  LPBYTE local_28;
  LPDWORD local_24;
  DWORD local_20;
  HKEY local_1c;
  DWORD local_18;
  LSTATUS local_14;
  
  local_18 = 0;
  local_1c = (HKEY)0x0;
  local_20 = 0;
  local_30 = (LPWSTR)0x0;
  local_38 = (LPDWORD)0x0;
  local_24 = (LPDWORD)0x0;
  local_2c = (LPDWORD)0x0;
  local_28 = (LPBYTE)0x0;
  local_34 = (uint *)0x0;
  if (param_1 == (int *)0x0) {
    iVar2 = -0x7ff8ffa9;
  }
  else {
    iVar2 = FUN_0001c900(param_1,&local_1c,4,1);
    if ((((-1 < iVar2) && (iVar2 = FUN_0001c900(param_1,&local_20,4,1), -1 < iVar2)) &&
        (iVar2 = FUN_0001cb2c(param_1,(int *)&local_30,0), -1 < iVar2)) &&
       (((iVar2 = FUN_0001cb2c(param_1,(int *)&local_38,0), -1 < iVar2 &&
         (iVar2 = FUN_0001cb2c(param_1,(int *)&local_24,0), -1 < iVar2)) &&
        ((iVar2 = FUN_0001cb2c(param_1,(int *)&local_2c,0), -1 < iVar2 &&
         ((iVar2 = FUN_0001cb2c(param_1,(int *)&local_28,0), -1 < iVar2 &&
          (iVar2 = FUN_0001cb2c(param_1,(int *)&local_34,0), -1 < iVar2)))))))) {
      FUN_0001ca4c((int)param_1);
      local_14 = RegEnumValueW(local_1c,local_20,local_30,local_38,local_24,local_2c,local_28,
                               local_34);
      local_18 = GetLastError();
      iVar2 = FUN_0001cd50(param_1,&local_18,4);
      if ((-1 < iVar2) && (iVar2 = FUN_0001cd50(param_1,&local_14,4), -1 < iVar2)) {
        if (local_38 == (LPDWORD)0x0) {
          uVar1 = 0;
        }
        else {
          uVar1 = (*local_38 + 1) * 2;
        }
        iVar2 = FUN_0001cf9c(param_1,local_30,uVar1,1);
        if (((-1 < iVar2) && (iVar2 = FUN_0001cf9c(param_1,local_38,4,1), -1 < iVar2)) &&
           (iVar2 = FUN_0001cf9c(param_1,local_2c,4,1), -1 < iVar2)) {
          if (local_34 == (uint *)0x0) {
            uVar1 = 0;
          }
          else {
            uVar1 = *local_34;
          }
          iVar2 = FUN_0001cf9c(param_1,local_28,uVar1,1);
          if ((-1 < iVar2) && (iVar2 = FUN_0001cf9c(param_1,local_34,4,1), -1 < iVar2)) {
            iVar2 = 0;
          }
        }
      }
    }
    if (local_30 != (LPWSTR)0x0) {
      operator_delete(local_30);
    }
    if (local_38 != (LPDWORD)0x0) {
      operator_delete(local_38);
    }
    if (local_24 != (LPDWORD)0x0) {
      operator_delete(local_24);
    }
    if (local_2c != (LPDWORD)0x0) {
      operator_delete(local_2c);
    }
    if (local_28 != (LPBYTE)0x0) {
      operator_delete(local_28);
    }
    if (local_34 != (uint *)0x0) {
      operator_delete(local_34);
    }
  }
  return iVar2;
}



/* 00014878 FUN_00014878 */

/* Boundary evidence: original MIPS .pdata 00014878..0001497b. Semantic name remains unreviewed. */

int FUN_00014878(int *param_1)

{
  int iVar1;
  LPCWSTR local_20;
  HKEY local_1c;
  DWORD local_18;
  LSTATUS local_14;
  
  local_18 = 0;
  local_1c = (HKEY)0x0;
  local_20 = (LPCWSTR)0x0;
  if (param_1 == (int *)0x0) {
    iVar1 = -0x7ff8ffa9;
  }
  else {
    iVar1 = FUN_0001c900(param_1,&local_1c,4,1);
    if ((-1 < iVar1) && (iVar1 = FUN_0001cb2c(param_1,(int *)&local_20,0), -1 < iVar1)) {
      FUN_0001ca4c((int)param_1);
      local_14 = RegDeleteValueW(local_1c,local_20);
      local_18 = GetLastError();
      iVar1 = FUN_0001cd50(param_1,&local_18,4);
      if ((-1 < iVar1) && (iVar1 = FUN_0001cd50(param_1,&local_14,4), -1 < iVar1)) {
        iVar1 = 0;
      }
    }
    if (local_20 != (LPCWSTR)0x0) {
      operator_delete(local_20);
    }
  }
  return iVar1;
}



/* 0001497c FUN_0001497c */

/* Boundary evidence: original MIPS .pdata 0001497c..00014e2b. Semantic name remains unreviewed. */

int FUN_0001497c(int *param_1)

{
  uint uVar1;
  int iVar2;
  LPDWORD local_48;
  LPWSTR local_44;
  LPDWORD local_40;
  LPDWORD local_3c;
  LPDWORD local_38;
  LPDWORD local_34;
  LPDWORD local_30;
  LPDWORD local_2c;
  LPDWORD local_28;
  PFILETIME local_24;
  LPDWORD local_20;
  HKEY local_1c;
  DWORD local_18;
  LSTATUS local_14;
  
  local_18 = 0;
  local_1c = (HKEY)0x0;
  local_44 = (LPWSTR)0x0;
  local_48 = (LPDWORD)0x0;
  local_20 = (LPDWORD)0x0;
  local_40 = (LPDWORD)0x0;
  local_3c = (LPDWORD)0x0;
  local_38 = (LPDWORD)0x0;
  local_34 = (LPDWORD)0x0;
  local_30 = (LPDWORD)0x0;
  local_2c = (LPDWORD)0x0;
  local_28 = (LPDWORD)0x0;
  local_24 = (PFILETIME)0x0;
  if (param_1 == (int *)0x0) {
    iVar2 = -0x7ff8ffa9;
  }
  else {
    iVar2 = FUN_0001c900(param_1,&local_1c,4,1);
    if (((((-1 < iVar2) && (iVar2 = FUN_0001cb2c(param_1,(int *)&local_44,0), -1 < iVar2)) &&
         (iVar2 = FUN_0001cb2c(param_1,(int *)&local_48,0), -1 < iVar2)) &&
        ((((iVar2 = FUN_0001cb2c(param_1,(int *)&local_20,0), -1 < iVar2 &&
           (iVar2 = FUN_0001cb2c(param_1,(int *)&local_40,0), -1 < iVar2)) &&
          ((iVar2 = FUN_0001cb2c(param_1,(int *)&local_3c,0), -1 < iVar2 &&
           ((iVar2 = FUN_0001cb2c(param_1,(int *)&local_38,0), -1 < iVar2 &&
            (iVar2 = FUN_0001cb2c(param_1,(int *)&local_34,0), -1 < iVar2)))))) &&
         (iVar2 = FUN_0001cb2c(param_1,(int *)&local_30,0), -1 < iVar2)))) &&
       (((iVar2 = FUN_0001cb2c(param_1,(int *)&local_2c,0), -1 < iVar2 &&
         (iVar2 = FUN_0001cb2c(param_1,(int *)&local_28,0), -1 < iVar2)) &&
        (iVar2 = FUN_0001cb2c(param_1,(int *)&local_24,0), -1 < iVar2)))) {
      FUN_0001ca4c((int)param_1);
      local_14 = RegQueryInfoKeyW(local_1c,local_44,local_48,local_20,local_40,local_3c,local_38,
                                  local_34,local_30,local_2c,local_28,local_24);
      local_18 = GetLastError();
      iVar2 = FUN_0001cd50(param_1,&local_18,4);
      if ((-1 < iVar2) && (iVar2 = FUN_0001cd50(param_1,&local_14,4), -1 < iVar2)) {
        if (local_48 == (LPDWORD)0x0) {
          uVar1 = 0;
        }
        else {
          uVar1 = (*local_48 + 1) * 2;
        }
        iVar2 = FUN_0001cf9c(param_1,local_44,uVar1,1);
        if ((((-1 < iVar2) && (iVar2 = FUN_0001cf9c(param_1,local_48,4,1), -1 < iVar2)) &&
            ((iVar2 = FUN_0001cf9c(param_1,local_40,4,1), -1 < iVar2 &&
             ((((iVar2 = FUN_0001cf9c(param_1,local_3c,4,1), -1 < iVar2 &&
                (iVar2 = FUN_0001cf9c(param_1,local_38,4,1), -1 < iVar2)) &&
               (iVar2 = FUN_0001cf9c(param_1,local_34,4,1), -1 < iVar2)) &&
              ((iVar2 = FUN_0001cf9c(param_1,local_30,4,1), -1 < iVar2 &&
               (iVar2 = FUN_0001cf9c(param_1,local_2c,4,1), -1 < iVar2)))))))) &&
           ((iVar2 = FUN_0001cf9c(param_1,local_28,4,1), -1 < iVar2 &&
            (iVar2 = FUN_0001cf9c(param_1,local_24,8,1), -1 < iVar2)))) {
          iVar2 = 0;
        }
      }
    }
    if (local_44 != (LPWSTR)0x0) {
      operator_delete(local_44);
    }
    if (local_48 != (LPDWORD)0x0) {
      operator_delete(local_48);
    }
    if (local_20 != (LPDWORD)0x0) {
      operator_delete(local_20);
    }
    if (local_40 != (LPDWORD)0x0) {
      operator_delete(local_40);
    }
    if (local_3c != (LPDWORD)0x0) {
      operator_delete(local_3c);
    }
    if (local_38 != (LPDWORD)0x0) {
      operator_delete(local_38);
    }
    if (local_34 != (LPDWORD)0x0) {
      operator_delete(local_34);
    }
    if (local_30 != (LPDWORD)0x0) {
      operator_delete(local_30);
    }
    if (local_2c != (LPDWORD)0x0) {
      operator_delete(local_2c);
    }
    if (local_28 != (LPDWORD)0x0) {
      operator_delete(local_28);
    }
    if (local_24 != (PFILETIME)0x0) {
      operator_delete(local_24);
    }
  }
  return iVar2;
}



/* 00014e2c FUN_00014e2c */

/* Boundary evidence: original MIPS .pdata 00014e2c..0001508b. Semantic name remains unreviewed. */

int FUN_00014e2c(int *param_1)

{
  uint uVar1;
  int iVar2;
  uint *local_30;
  LPDWORD local_2c;
  LPBYTE local_28;
  LPCWSTR local_24;
  LPDWORD local_20;
  HKEY local_1c;
  DWORD local_18;
  LSTATUS local_14;
  
  local_18 = 0;
  local_1c = (HKEY)0x0;
  local_24 = (LPCWSTR)0x0;
  local_20 = (LPDWORD)0x0;
  local_2c = (LPDWORD)0x0;
  local_28 = (LPBYTE)0x0;
  local_30 = (uint *)0x0;
  if (param_1 == (int *)0x0) {
    iVar2 = -0x7ff8ffa9;
  }
  else {
    iVar2 = FUN_0001c900(param_1,&local_1c,4,1);
    if (((((-1 < iVar2) && (iVar2 = FUN_0001cb2c(param_1,(int *)&local_24,0), -1 < iVar2)) &&
         (iVar2 = FUN_0001cb2c(param_1,(int *)&local_20,0), -1 < iVar2)) &&
        ((iVar2 = FUN_0001cb2c(param_1,(int *)&local_2c,0), -1 < iVar2 &&
         (iVar2 = FUN_0001cb2c(param_1,(int *)&local_28,0), -1 < iVar2)))) &&
       (iVar2 = FUN_0001cb2c(param_1,(int *)&local_30,0), -1 < iVar2)) {
      FUN_0001ca4c((int)param_1);
      local_14 = RegQueryValueExW(local_1c,local_24,local_20,local_2c,local_28,local_30);
      local_18 = GetLastError();
      iVar2 = FUN_0001cd50(param_1,&local_18,4);
      if (((-1 < iVar2) && (iVar2 = FUN_0001cd50(param_1,&local_14,4), -1 < iVar2)) &&
         (iVar2 = FUN_0001cf9c(param_1,local_2c,4,1), -1 < iVar2)) {
        if (local_30 == (uint *)0x0) {
          uVar1 = 0;
        }
        else {
          uVar1 = *local_30;
        }
        iVar2 = FUN_0001cf9c(param_1,local_28,uVar1,1);
        if ((-1 < iVar2) && (iVar2 = FUN_0001cf9c(param_1,local_30,4,1), -1 < iVar2)) {
          iVar2 = 0;
        }
      }
    }
    if (local_24 != (LPCWSTR)0x0) {
      operator_delete(local_24);
    }
    if (local_20 != (LPDWORD)0x0) {
      operator_delete(local_20);
    }
    if (local_2c != (LPDWORD)0x0) {
      operator_delete(local_2c);
    }
    if (local_28 != (LPBYTE)0x0) {
      operator_delete(local_28);
    }
    if (local_30 != (uint *)0x0) {
      operator_delete(local_30);
    }
  }
  return iVar2;
}



/* 0001508c FUN_0001508c */

/* Boundary evidence: original MIPS .pdata 0001508c..00015227. Semantic name remains unreviewed. */

int FUN_0001508c(int *param_1)

{
  int iVar1;
  LPCWSTR local_30;
  BYTE *local_2c;
  DWORD local_28;
  DWORD local_24;
  HKEY local_20;
  DWORD local_1c;
  DWORD local_18;
  LSTATUS local_14;
  
  local_1c = 0;
  local_20 = (HKEY)0x0;
  local_30 = (LPCWSTR)0x0;
  local_18 = 0;
  local_24 = 0;
  local_2c = (BYTE *)0x0;
  local_28 = 0;
  if (param_1 == (int *)0x0) {
    iVar1 = -0x7ff8ffa9;
  }
  else {
    iVar1 = FUN_0001c900(param_1,&local_20,4,1);
    if ((((-1 < iVar1) && (iVar1 = FUN_0001cb2c(param_1,(int *)&local_30,0), -1 < iVar1)) &&
        (iVar1 = FUN_0001c900(param_1,&local_24,4,1), -1 < iVar1)) &&
       ((iVar1 = FUN_0001cb2c(param_1,(int *)&local_2c,0), -1 < iVar1 &&
        (iVar1 = FUN_0001c900(param_1,&local_28,4,1), -1 < iVar1)))) {
      FUN_0001ca4c((int)param_1);
      local_14 = RegSetValueExW(local_20,local_30,local_18,local_24,local_2c,local_28);
      local_1c = GetLastError();
      iVar1 = FUN_0001cd50(param_1,&local_1c,4);
      if ((-1 < iVar1) && (iVar1 = FUN_0001cd50(param_1,&local_14,4), -1 < iVar1)) {
        iVar1 = 0;
      }
    }
    if (local_30 != (LPCWSTR)0x0) {
      operator_delete(local_30);
    }
    if (local_2c != (BYTE *)0x0) {
      operator_delete(local_2c);
    }
  }
  return iVar1;
}



/* 00015228 FUN_00015228 */

/* Boundary evidence: original MIPS .pdata 00015228..000153cb. Semantic name remains unreviewed. */

int FUN_00015228(int *param_1)

{
  int iVar1;
  void *local_28;
  void *local_24;
  void *local_20;
  DWORD local_1c;
  undefined4 local_18 [2];
  
  local_1c = 0;
  local_28 = (void *)0x0;
  local_24 = (void *)0x0;
  local_20 = (void *)0x0;
  if (param_1 == (int *)0x0) {
    iVar1 = -0x7ff8ffa9;
  }
  else {
    iVar1 = FUN_0001cb2c(param_1,(int *)&local_28,0);
    if (((-1 < iVar1) && (iVar1 = FUN_0001cb2c(param_1,(int *)&local_24,0), -1 < iVar1)) &&
       (iVar1 = FUN_0001cb2c(param_1,(int *)&local_20,0), -1 < iVar1)) {
      FUN_0001ca4c((int)param_1);
      local_18[0] = GetSystemMemoryDivision(local_28,local_24,local_20);
      local_1c = GetLastError();
      iVar1 = FUN_0001cd50(param_1,&local_1c,4);
      if (((-1 < iVar1) && (iVar1 = FUN_0001cd50(param_1,local_18,4), -1 < iVar1)) &&
         ((iVar1 = FUN_0001cf9c(param_1,local_28,4,1), -1 < iVar1 &&
          ((iVar1 = FUN_0001cf9c(param_1,local_24,4,1), -1 < iVar1 &&
           (iVar1 = FUN_0001cf9c(param_1,local_20,4,1), -1 < iVar1)))))) {
        iVar1 = 0;
      }
    }
    if (local_28 != (void *)0x0) {
      operator_delete(local_28);
    }
    if (local_24 != (void *)0x0) {
      operator_delete(local_24);
    }
    if (local_20 != (void *)0x0) {
      operator_delete(local_20);
    }
  }
  return iVar1;
}



/* 000153cc FUN_000153cc */

/* Boundary evidence: original MIPS .pdata 000153cc..00015477. Semantic name remains unreviewed. */

int FUN_000153cc(int *param_1)

{
  int iVar1;
  undefined4 local_18;
  DWORD local_14;
  undefined4 local_10 [2];
  
  local_14 = 0;
  local_18 = 0;
  if (param_1 == (int *)0x0) {
    iVar1 = -0x7ff8ffa9;
  }
  else {
    iVar1 = FUN_0001c900(param_1,&local_18,4,1);
    if (-1 < iVar1) {
      FUN_0001ca4c((int)param_1);
      local_10[0] = SetSystemMemoryDivision(local_18);
      local_14 = GetLastError();
      iVar1 = FUN_0001cd50(param_1,&local_14,4);
      if ((-1 < iVar1) && (iVar1 = FUN_0001cd50(param_1,local_10,4), -1 < iVar1)) {
        iVar1 = 0;
      }
    }
  }
  return iVar1;
}



/* 00015478 FUN_00015478 */

/* Boundary evidence: original MIPS .pdata 00015478..00015523. Semantic name remains unreviewed. */

int FUN_00015478(int *param_1)

{
  int iVar1;
  int local_18;
  DWORD local_14;
  int local_10 [2];
  
  local_14 = 0;
  local_18 = 0;
  if (param_1 == (int *)0x0) {
    iVar1 = -0x7ff8ffa9;
  }
  else {
    iVar1 = FUN_0001c900(param_1,&local_18,4,1);
    if (-1 < iVar1) {
      FUN_0001ca4c((int)param_1);
      local_10[0] = GetSystemMetrics(local_18);
      local_14 = GetLastError();
      iVar1 = FUN_0001cd50(param_1,&local_14,4);
      if ((-1 < iVar1) && (iVar1 = FUN_0001cd50(param_1,local_10,4), -1 < iVar1)) {
        iVar1 = 0;
      }
    }
  }
  return iVar1;
}



/* 00015524 FUN_00015524 */

/* Boundary evidence: original MIPS .pdata 00015524..000155f7. Semantic name remains unreviewed. */

int FUN_00015524(int *param_1)

{
  int iVar1;
  void *local_20;
  DWORD local_1c;
  undefined4 local_18 [2];
  
  local_1c = 0;
  local_20 = (void *)0x0;
  if (param_1 == (int *)0x0) {
    iVar1 = -0x7ff8ffa9;
  }
  else {
    iVar1 = FUN_0001cb2c(param_1,(int *)&local_20,0);
    if (-1 < iVar1) {
      FUN_0001ca4c((int)param_1);
      local_18[0] = RegCopyFile(local_20);
      local_1c = GetLastError();
      iVar1 = FUN_0001cd50(param_1,&local_1c,4);
      if ((-1 < iVar1) && (iVar1 = FUN_0001cd50(param_1,local_18,4), -1 < iVar1)) {
        iVar1 = 0;
      }
    }
    if (local_20 != (void *)0x0) {
      operator_delete(local_20);
    }
  }
  return iVar1;
}



/* 000155f8 FUN_000155f8 */

/* Boundary evidence: original MIPS .pdata 000155f8..000156cb. Semantic name remains unreviewed. */

int FUN_000155f8(int *param_1)

{
  int iVar1;
  void *local_20;
  DWORD local_1c;
  undefined4 local_18 [2];
  
  local_1c = 0;
  local_20 = (void *)0x0;
  if (param_1 == (int *)0x0) {
    iVar1 = -0x7ff8ffa9;
  }
  else {
    iVar1 = FUN_0001cb2c(param_1,(int *)&local_20,0);
    if (-1 < iVar1) {
      FUN_0001ca4c((int)param_1);
      local_18[0] = RegRestoreFile(local_20);
      local_1c = GetLastError();
      iVar1 = FUN_0001cd50(param_1,&local_1c,4);
      if ((-1 < iVar1) && (iVar1 = FUN_0001cd50(param_1,local_18,4), -1 < iVar1)) {
        iVar1 = 0;
      }
    }
    if (local_20 != (void *)0x0) {
      operator_delete(local_20);
    }
  }
  return iVar1;
}



/* 000156cc FUN_000156cc */

/* Boundary evidence: original MIPS .pdata 000156cc..000157ab. Semantic name remains unreviewed. */

int FUN_000156cc(int *param_1)

{
  int iVar1;
  LPSYSTEM_INFO local_18;
  DWORD local_14;
  
  local_14 = 0;
  local_18 = (LPSYSTEM_INFO)0x0;
  if (param_1 == (int *)0x0) {
    iVar1 = -0x7ff8ffa9;
  }
  else {
    iVar1 = FUN_0001cb2c(param_1,(int *)&local_18,0);
    if (-1 < iVar1) {
      FUN_0001ca4c((int)param_1);
      GetSystemInfo(local_18);
      local_14 = GetLastError();
      iVar1 = FUN_0001cd50(param_1,&local_14,4);
      if ((-1 < iVar1) && (iVar1 = FUN_0001cf9c(param_1,local_18,0x24,1), -1 < iVar1)) {
        iVar1 = 0;
      }
    }
    if (local_18 != (LPSYSTEM_INFO)0x0) {
      operator_delete(local_18);
    }
  }
  return iVar1;
}



/* 000157ac FUN_000157ac */

/* Boundary evidence: original MIPS .pdata 000157ac..000158b7. Semantic name remains unreviewed. */

int FUN_000157ac(int *param_1)

{
  int iVar1;
  void *local_20;
  void *local_1c;
  DWORD local_18;
  undefined4 local_14;
  
  local_18 = 0;
  local_20 = (void *)0x0;
  local_1c = (void *)0x0;
  if (param_1 == (int *)0x0) {
    iVar1 = -0x7ff8ffa9;
  }
  else {
    iVar1 = FUN_0001cb2c(param_1,(int *)&local_20,0);
    if ((-1 < iVar1) && (iVar1 = FUN_0001cb2c(param_1,(int *)&local_1c,0), -1 < iVar1)) {
      FUN_0001ca4c((int)param_1);
      local_14 = SHCreateShortcut(local_20,local_1c);
      local_18 = GetLastError();
      iVar1 = FUN_0001cd50(param_1,&local_18,4);
      if ((-1 < iVar1) && (iVar1 = FUN_0001cd50(param_1,&local_14,4), -1 < iVar1)) {
        iVar1 = 0;
      }
    }
    if (local_20 != (void *)0x0) {
      operator_delete(local_20);
    }
    if (local_1c != (void *)0x0) {
      operator_delete(local_1c);
    }
  }
  return iVar1;
}



/* 000158b8 FUN_000158b8 */

/* Boundary evidence: original MIPS .pdata 000158b8..00015a0f. Semantic name remains unreviewed. */

int FUN_000158b8(int *param_1)

{
  int iVar1;
  void *local_28;
  int local_24;
  void *local_20;
  DWORD local_1c;
  undefined4 local_18 [2];
  
  local_1c = 0;
  local_20 = (void *)0x0;
  local_28 = (void *)0x0;
  local_24 = 0;
  if (param_1 == (int *)0x0) {
    iVar1 = -0x7ff8ffa9;
  }
  else {
    iVar1 = FUN_0001cb2c(param_1,(int *)&local_20,0);
    if (((-1 < iVar1) && (iVar1 = FUN_0001cb2c(param_1,(int *)&local_28,0), -1 < iVar1)) &&
       (iVar1 = FUN_0001c900(param_1,&local_24,4,1), -1 < iVar1)) {
      FUN_0001ca4c((int)param_1);
      local_18[0] = SHGetShortcutTarget(local_20,local_28,local_24);
      local_1c = GetLastError();
      iVar1 = FUN_0001cd50(param_1,&local_1c,4);
      if (((-1 < iVar1) && (iVar1 = FUN_0001cd50(param_1,local_18,4), -1 < iVar1)) &&
         (iVar1 = FUN_0001cf9c(param_1,local_28,local_24 << 1,1), -1 < iVar1)) {
        iVar1 = 0;
      }
    }
    if (local_20 != (void *)0x0) {
      operator_delete(local_20);
    }
    if (local_28 != (void *)0x0) {
      operator_delete(local_28);
    }
  }
  return iVar1;
}



/* 00015a10 FUN_00015a10 */

/* Boundary evidence: original MIPS .pdata 00015a10..00015a9b. Semantic name remains unreviewed. */

int FUN_00015a10(int *param_1)

{
  int iVar1;
  DWORD local_10;
  undefined4 local_c;
  
  local_10 = 0;
  if (param_1 == (int *)0x0) {
    iVar1 = -0x7ff8ffa9;
  }
  else {
    FUN_0001ca4c((int)param_1);
    local_c = GetPasswordActive();
    local_10 = GetLastError();
    iVar1 = FUN_0001cd50(param_1,&local_10,4);
    if ((-1 < iVar1) && (iVar1 = FUN_0001cd50(param_1,&local_c,4), -1 < iVar1)) {
      iVar1 = 0;
    }
  }
  return iVar1;
}



/* 00015a9c FUN_00015a9c */

/* Boundary evidence: original MIPS .pdata 00015a9c..00015b97. Semantic name remains unreviewed. */

int FUN_00015a9c(int *param_1)

{
  int iVar1;
  void *local_20;
  undefined4 local_1c;
  DWORD local_18;
  undefined4 local_14;
  
  local_18 = 0;
  local_1c = 0;
  local_20 = (void *)0x0;
  if (param_1 == (int *)0x0) {
    iVar1 = -0x7ff8ffa9;
  }
  else {
    iVar1 = FUN_0001c900(param_1,&local_1c,4,1);
    if ((-1 < iVar1) && (iVar1 = FUN_0001cb2c(param_1,(int *)&local_20,0), -1 < iVar1)) {
      FUN_0001ca4c((int)param_1);
      local_14 = SetPasswordActive(local_1c,local_20);
      local_18 = GetLastError();
      iVar1 = FUN_0001cd50(param_1,&local_18,4);
      if ((-1 < iVar1) && (iVar1 = FUN_0001cd50(param_1,&local_14,4), -1 < iVar1)) {
        iVar1 = 0;
      }
    }
    if (local_20 != (void *)0x0) {
      operator_delete(local_20);
    }
  }
  return iVar1;
}



/* 00015b98 FUN_00015b98 */

/* Boundary evidence: original MIPS .pdata 00015b98..00015c6b. Semantic name remains unreviewed. */

int FUN_00015b98(int *param_1)

{
  int iVar1;
  void *local_20;
  DWORD local_1c;
  undefined4 local_18 [2];
  
  local_1c = 0;
  local_20 = (void *)0x0;
  if (param_1 == (int *)0x0) {
    iVar1 = -0x7ff8ffa9;
  }
  else {
    iVar1 = FUN_0001cb2c(param_1,(int *)&local_20,0);
    if (-1 < iVar1) {
      FUN_0001ca4c((int)param_1);
      local_18[0] = CheckPassword(local_20);
      local_1c = GetLastError();
      iVar1 = FUN_0001cd50(param_1,&local_1c,4);
      if ((-1 < iVar1) && (iVar1 = FUN_0001cd50(param_1,local_18,4), -1 < iVar1)) {
        iVar1 = 0;
      }
    }
    if (local_20 != (void *)0x0) {
      operator_delete(local_20);
    }
  }
  return iVar1;
}



/* 00015c6c FUN_00015c6c */

/* Boundary evidence: original MIPS .pdata 00015c6c..00015d77. Semantic name remains unreviewed. */

int FUN_00015c6c(int *param_1)

{
  int iVar1;
  void *local_20;
  void *local_1c;
  DWORD local_18;
  undefined4 local_14;
  
  local_18 = 0;
  local_20 = (void *)0x0;
  local_1c = (void *)0x0;
  if (param_1 == (int *)0x0) {
    iVar1 = -0x7ff8ffa9;
  }
  else {
    iVar1 = FUN_0001cb2c(param_1,(int *)&local_20,0);
    if ((-1 < iVar1) && (iVar1 = FUN_0001cb2c(param_1,(int *)&local_1c,0), -1 < iVar1)) {
      FUN_0001ca4c((int)param_1);
      local_14 = SetPassword(local_20,local_1c);
      local_18 = GetLastError();
      iVar1 = FUN_0001cd50(param_1,&local_18,4);
      if ((-1 < iVar1) && (iVar1 = FUN_0001cd50(param_1,&local_14,4), -1 < iVar1)) {
        iVar1 = 0;
      }
    }
    if (local_20 != (void *)0x0) {
      operator_delete(local_20);
    }
    if (local_1c != (void *)0x0) {
      operator_delete(local_1c);
    }
  }
  return iVar1;
}



/* 00015d78 FUN_00015d78 */

/* Boundary evidence: original MIPS .pdata 00015d78..00015f4b. Semantic name remains unreviewed. */

int FUN_00015d78(int *param_1)

{
  int iVar1;
  LPFILETIME local_28;
  LPFILETIME local_24;
  LPFILETIME local_20;
  HANDLE local_1c;
  DWORD local_18;
  BOOL local_14;
  
  local_18 = 0;
  local_1c = (HANDLE)0x0;
  local_28 = (LPFILETIME)0x0;
  local_24 = (LPFILETIME)0x0;
  local_20 = (LPFILETIME)0x0;
  if (param_1 == (int *)0x0) {
    iVar1 = -0x7ff8ffa9;
  }
  else {
    iVar1 = FUN_0001c900(param_1,&local_1c,4,1);
    if ((((-1 < iVar1) && (iVar1 = FUN_0001cb2c(param_1,(int *)&local_28,0), -1 < iVar1)) &&
        (iVar1 = FUN_0001cb2c(param_1,(int *)&local_24,0), -1 < iVar1)) &&
       (iVar1 = FUN_0001cb2c(param_1,(int *)&local_20,0), -1 < iVar1)) {
      FUN_0001ca4c((int)param_1);
      local_14 = GetFileTime(local_1c,local_28,local_24,local_20);
      local_18 = GetLastError();
      iVar1 = FUN_0001cd50(param_1,&local_18,4);
      if (((-1 < iVar1) && (iVar1 = FUN_0001cd50(param_1,&local_14,4), -1 < iVar1)) &&
         ((iVar1 = FUN_0001cf9c(param_1,local_28,8,1), -1 < iVar1 &&
          ((iVar1 = FUN_0001cf9c(param_1,local_24,8,1), -1 < iVar1 &&
           (iVar1 = FUN_0001cf9c(param_1,local_20,8,1), -1 < iVar1)))))) {
        iVar1 = 0;
      }
    }
    if (local_28 != (LPFILETIME)0x0) {
      operator_delete(local_28);
    }
    if (local_24 != (LPFILETIME)0x0) {
      operator_delete(local_24);
    }
    if (local_20 != (LPFILETIME)0x0) {
      operator_delete(local_20);
    }
  }
  return iVar1;
}



/* 00015f4c FUN_00015f4c */

/* Boundary evidence: original MIPS .pdata 00015f4c..000160bf. Semantic name remains unreviewed. */

int FUN_00015f4c(int *param_1)

{
  int iVar1;
  FILETIME *local_28;
  FILETIME *local_24;
  FILETIME *local_20;
  HANDLE local_1c;
  DWORD local_18;
  BOOL local_14;
  
  local_18 = 0;
  local_1c = (HANDLE)0x0;
  local_28 = (FILETIME *)0x0;
  local_24 = (FILETIME *)0x0;
  local_20 = (FILETIME *)0x0;
  if (param_1 == (int *)0x0) {
    iVar1 = -0x7ff8ffa9;
  }
  else {
    iVar1 = FUN_0001c900(param_1,&local_1c,4,1);
    if ((((-1 < iVar1) && (iVar1 = FUN_0001cb2c(param_1,(int *)&local_28,0), -1 < iVar1)) &&
        (iVar1 = FUN_0001cb2c(param_1,(int *)&local_24,0), -1 < iVar1)) &&
       (iVar1 = FUN_0001cb2c(param_1,(int *)&local_20,0), -1 < iVar1)) {
      FUN_0001ca4c((int)param_1);
      local_14 = SetFileTime(local_1c,local_28,local_24,local_20);
      local_18 = GetLastError();
      iVar1 = FUN_0001cd50(param_1,&local_18,4);
      if ((-1 < iVar1) && (iVar1 = FUN_0001cd50(param_1,&local_14,4), -1 < iVar1)) {
        iVar1 = 0;
      }
    }
    if (local_28 != (FILETIME *)0x0) {
      operator_delete(local_28);
    }
    if (local_24 != (FILETIME *)0x0) {
      operator_delete(local_24);
    }
    if (local_20 != (FILETIME *)0x0) {
      operator_delete(local_20);
    }
  }
  return iVar1;
}



/* 000160c0 FUN_000160c0 */

/* Boundary evidence: original MIPS .pdata 000160c0..0001618f. Semantic name remains unreviewed. */

int FUN_000160c0(int *param_1)

{
  int iVar1;
  UINT local_18;
  HWND local_14;
  DWORD local_10;
  HWND local_c;
  
  local_10 = 0;
  local_14 = (HWND)0x0;
  local_18 = 0;
  if (param_1 == (int *)0x0) {
    iVar1 = -0x7ff8ffa9;
  }
  else {
    iVar1 = FUN_0001c900(param_1,&local_14,4,1);
    if ((-1 < iVar1) && (iVar1 = FUN_0001c900(param_1,&local_18,4,1), -1 < iVar1)) {
      FUN_0001ca4c((int)param_1);
      local_c = GetWindow(local_14,local_18);
      local_10 = GetLastError();
      iVar1 = FUN_0001cd50(param_1,&local_10,4);
      if ((-1 < iVar1) && (iVar1 = FUN_0001cd50(param_1,&local_c,4), -1 < iVar1)) {
        iVar1 = 0;
      }
    }
  }
  return iVar1;
}



/* 00016190 FUN_00016190 */

/* Boundary evidence: original MIPS .pdata 00016190..0001625f. Semantic name remains unreviewed. */

int FUN_00016190(int *param_1)

{
  int iVar1;
  int local_18;
  HWND local_14;
  DWORD local_10;
  LONG local_c;
  
  local_10 = 0;
  local_14 = (HWND)0x0;
  local_18 = 0;
  if (param_1 == (int *)0x0) {
    iVar1 = -0x7ff8ffa9;
  }
  else {
    iVar1 = FUN_0001c900(param_1,&local_14,4,1);
    if ((-1 < iVar1) && (iVar1 = FUN_0001c900(param_1,&local_18,4,1), -1 < iVar1)) {
      FUN_0001ca4c((int)param_1);
      local_c = GetWindowLongW(local_14,local_18);
      local_10 = GetLastError();
      iVar1 = FUN_0001cd50(param_1,&local_10,4);
      if ((-1 < iVar1) && (iVar1 = FUN_0001cd50(param_1,&local_c,4), -1 < iVar1)) {
        iVar1 = 0;
      }
    }
  }
  return iVar1;
}



/* 00016260 FUN_00016260 */

/* Boundary evidence: original MIPS .pdata 00016260..000163a7. Semantic name remains unreviewed. */

int FUN_00016260(int *param_1)

{
  int iVar1;
  LPWSTR local_28;
  int local_24;
  HWND local_20;
  DWORD local_1c;
  int local_18 [2];
  
  local_1c = 0;
  local_20 = (HWND)0x0;
  local_28 = (LPWSTR)0x0;
  local_24 = 0;
  if (param_1 == (int *)0x0) {
    iVar1 = -0x7ff8ffa9;
  }
  else {
    iVar1 = FUN_0001c900(param_1,&local_20,4,1);
    if (((-1 < iVar1) && (iVar1 = FUN_0001cb2c(param_1,(int *)&local_28,0), -1 < iVar1)) &&
       (iVar1 = FUN_0001c900(param_1,&local_24,4,1), -1 < iVar1)) {
      FUN_0001ca4c((int)param_1);
      local_18[0] = GetWindowTextW(local_20,local_28,local_24);
      local_1c = GetLastError();
      iVar1 = FUN_0001cd50(param_1,&local_1c,4);
      if (((-1 < iVar1) && (iVar1 = FUN_0001cd50(param_1,local_18,4), -1 < iVar1)) &&
         (iVar1 = FUN_0001cf9c(param_1,local_28,local_24 << 1,1), -1 < iVar1)) {
        iVar1 = 0;
      }
    }
    if (local_28 != (LPWSTR)0x0) {
      operator_delete(local_28);
    }
  }
  return iVar1;
}



/* 000163a8 FUN_000163a8 */

/* Boundary evidence: original MIPS .pdata 000163a8..000164ef. Semantic name remains unreviewed. */

int FUN_000163a8(int *param_1)

{
  int iVar1;
  LPWSTR local_28;
  int local_24;
  HWND local_20;
  DWORD local_1c;
  int local_18 [2];
  
  local_1c = 0;
  local_20 = (HWND)0x0;
  local_28 = (LPWSTR)0x0;
  local_24 = 0;
  if (param_1 == (int *)0x0) {
    iVar1 = -0x7ff8ffa9;
  }
  else {
    iVar1 = FUN_0001c900(param_1,&local_20,4,1);
    if (((-1 < iVar1) && (iVar1 = FUN_0001cb2c(param_1,(int *)&local_28,0), -1 < iVar1)) &&
       (iVar1 = FUN_0001c900(param_1,&local_24,4,1), -1 < iVar1)) {
      FUN_0001ca4c((int)param_1);
      local_18[0] = GetClassNameW(local_20,local_28,local_24);
      local_1c = GetLastError();
      iVar1 = FUN_0001cd50(param_1,&local_1c,4);
      if (((-1 < iVar1) && (iVar1 = FUN_0001cd50(param_1,local_18,4), -1 < iVar1)) &&
         (iVar1 = FUN_0001cf9c(param_1,local_28,local_24 << 1,1), -1 < iVar1)) {
        iVar1 = 0;
      }
    }
    if (local_28 != (LPWSTR)0x0) {
      operator_delete(local_28);
    }
  }
  return iVar1;
}



/* 000164f0 FUN_000164f0 */

/* Boundary evidence: original MIPS .pdata 000164f0..000165c7. Semantic name remains unreviewed. */

int FUN_000164f0(int *param_1)

{
  int iVar1;
  LPMEMORYSTATUS local_18;
  DWORD local_14;
  
  local_14 = 0;
  local_18 = (LPMEMORYSTATUS)0x0;
  if (param_1 == (int *)0x0) {
    iVar1 = -0x7ff8ffa9;
  }
  else {
    iVar1 = FUN_0001cb2c(param_1,(int *)&local_18,0);
    if (-1 < iVar1) {
      FUN_0001ca4c((int)param_1);
      GlobalMemoryStatus(local_18);
      local_14 = GetLastError();
      iVar1 = FUN_0001cd50(param_1,&local_14,4);
      if ((-1 < iVar1) && (iVar1 = FUN_0001cf9c(param_1,local_18,0x20,1), -1 < iVar1)) {
        iVar1 = 0;
      }
    }
    if (local_18 != (LPMEMORYSTATUS)0x0) {
      operator_delete(local_18);
    }
  }
  return iVar1;
}



/* 000165c8 FUN_000165c8 */

/* Boundary evidence: original MIPS .pdata 000165c8..000166ef. Semantic name remains unreviewed. */

int FUN_000165c8(int *param_1)

{
  int iVar1;
  LPWSTR local_20;
  DWORD local_1c;
  DWORD local_18;
  DWORD local_14;
  
  local_18 = 0;
  local_1c = 0;
  local_20 = (LPWSTR)0x0;
  if (param_1 == (int *)0x0) {
    iVar1 = -0x7ff8ffa9;
  }
  else {
    iVar1 = FUN_0001c900(param_1,&local_1c,4,1);
    if ((-1 < iVar1) && (iVar1 = FUN_0001cb2c(param_1,(int *)&local_20,0), -1 < iVar1)) {
      FUN_0001ca4c((int)param_1);
      local_14 = GetTempPathW(local_1c,local_20);
      local_18 = GetLastError();
      iVar1 = FUN_0001cd50(param_1,&local_18,4);
      if ((-1 < iVar1) &&
         ((iVar1 = FUN_0001cd50(param_1,&local_14,4), -1 < iVar1 &&
          (iVar1 = FUN_0001cf9c(param_1,local_20,local_1c << 1,1), -1 < iVar1)))) {
        iVar1 = 0;
      }
    }
    if (local_20 != (LPWSTR)0x0) {
      operator_delete(local_20);
    }
  }
  return iVar1;
}



/* 000166f0 FUN_000166f0 */

/* Boundary evidence: original MIPS .pdata 000166f0..00016753. Semantic name remains unreviewed. */

int FUN_000166f0(int param_1)

{
  HWND hWnd;
  HDC hdc;
  int iVar1;
  
  hWnd = GetForegroundWindow();
  hdc = GetDC(hWnd);
  iVar1 = GetDeviceCaps(hdc,param_1);
  ReleaseDC(hWnd,hdc);
  return iVar1;
}



/* 00016754 FUN_00016754 */

/* Boundary evidence: original MIPS .pdata 00016754..000167af. Semantic name remains unreviewed. */

void FUN_00016754(void)

{
  if (DAT_0001e2e0 == (HMODULE)0x0) {
    DAT_0001e2e0 = LoadLibraryW(L"ceshell.dll");
    if (DAT_0001e2e0 == (HMODULE)0x0) {
      DAT_0001e2e0 = LoadLibraryW(L"ceshellg.dll");
      if (DAT_0001e2e0 == (HMODULE)0x0) {
        DAT_0001e2e0 = (HMODULE)0xffffffff;
      }
    }
  }
  return;
}



/* 000167b0 FUN_000167b0 */

/* Boundary evidence: original MIPS .pdata 000167b0..0001690f. Semantic name remains unreviewed. */

int FUN_000167b0(int *param_1,undefined4 *param_2)

{
  int iVar1;
  size_t sVar2;
  uint local_258;
  LPCWSTR local_254;
  HANDLE local_250;
  DWORD local_24c;
  undefined1 auStack_248 [40];
  wchar_t awStack_220 [260];
  uint local_18;
  
  local_18 = DAT_0001e29c;
  iVar1 = FUN_0001cc40(param_1,&local_254);
  if (-1 < iVar1) {
    FUN_0001ca4c((int)param_1);
    local_250 = FindFirstFileW(local_254,(LPWIN32_FIND_DATAW)auStack_248);
    if (local_254 != (LPCWSTR)0x0) {
      operator_delete(local_254);
    }
    local_24c = GetLastError();
    iVar1 = FUN_0001cd50(param_1,&local_24c,4);
    if (-1 < iVar1) {
      if (local_250 != (HANDLE)0xffffffff) {
        FUN_0001308c(param_2,local_250,2);
      }
      iVar1 = FUN_0001cd50(param_1,&local_250,4);
      if (-1 < iVar1) {
        sVar2 = wcslen(awStack_220);
        local_258 = (sVar2 + 0x15) * 2;
        iVar1 = FUN_0001cd50(param_1,&local_258,4);
        if (-1 < iVar1) {
          iVar1 = FUN_0001cd50(param_1,auStack_248,local_258);
          FUN_0001d140(local_18);
          if (iVar1 < 0) {
            return iVar1;
          }
          return 0;
        }
      }
    }
  }
  FUN_0001d140(local_18);
  return iVar1;
}



/* 00016910 FUN_00016910 */

/* Boundary evidence: original MIPS .pdata 00016910..00016a37. Semantic name remains unreviewed. */

int FUN_00016910(int *param_1)

{
  int iVar1;
  size_t sVar2;
  uint local_258;
  DWORD local_254;
  BOOL local_250;
  HANDLE local_24c;
  undefined1 auStack_248 [40];
  wchar_t awStack_220 [260];
  uint local_18;
  
  local_18 = DAT_0001e29c;
  iVar1 = FUN_0001c900(param_1,&local_24c,4,1);
  if (-1 < iVar1) {
    FUN_0001ca4c((int)param_1);
    local_250 = FindNextFileW(local_24c,(LPWIN32_FIND_DATAW)auStack_248);
    local_254 = GetLastError();
    iVar1 = FUN_0001cd50(param_1,&local_254,4);
    if ((-1 < iVar1) && (iVar1 = FUN_0001cd50(param_1,&local_250,4), -1 < iVar1)) {
      sVar2 = wcslen(awStack_220);
      local_258 = (sVar2 + 0x15) * 2;
      iVar1 = FUN_0001cd50(param_1,&local_258,4);
      if (-1 < iVar1) {
        iVar1 = FUN_0001cd50(param_1,auStack_248,local_258);
        FUN_0001d140(local_18);
        if (iVar1 < 0) {
          return iVar1;
        }
        return 0;
      }
    }
  }
  FUN_0001d140(local_18);
  return iVar1;
}



/* 00016a38 FUN_00016a38 */

/* Boundary evidence: original MIPS .pdata 00016a38..00016af7. Semantic name remains unreviewed. */

int FUN_00016a38(int *param_1,int *param_2)

{
  int iVar1;
  HANDLE local_20;
  BOOL local_1c;
  DWORD local_18 [2];
  
  iVar1 = FUN_0001c900(param_1,&local_20,4,1);
  if (-1 < iVar1) {
    FUN_0001ca4c((int)param_1);
    local_1c = FindClose(local_20);
    local_18[0] = GetLastError();
    iVar1 = FUN_0001cd50(param_1,local_18,4);
    if (-1 < iVar1) {
      if (local_1c != 0) {
        FUN_00013100(param_2,(int)local_20);
      }
      iVar1 = FUN_0001cd50(param_1,&local_1c,4);
      if (-1 < iVar1) {
        iVar1 = 0;
      }
    }
  }
  return iVar1;
}



/* 00016af8 FUN_00016af8 */

/* Boundary evidence: original MIPS .pdata 00016af8..00016b9f. Semantic name remains unreviewed. */

int FUN_00016af8(int *param_1)

{
  int iVar1;
  LPCWSTR local_18;
  DWORD local_14;
  DWORD local_10 [2];
  
  iVar1 = FUN_0001cc40(param_1,&local_18);
  if (-1 < iVar1) {
    FUN_0001ca4c((int)param_1);
    local_10[0] = GetFileAttributesW(local_18);
    if (local_18 != (LPCWSTR)0x0) {
      operator_delete(local_18);
    }
    local_14 = GetLastError();
    iVar1 = FUN_0001cd50(param_1,&local_14,4);
    if ((-1 < iVar1) && (iVar1 = FUN_0001cd50(param_1,local_10,4), -1 < iVar1)) {
      iVar1 = 0;
    }
  }
  return iVar1;
}



/* 00016ba0 FUN_00016ba0 */

/* Boundary evidence: original MIPS .pdata 00016ba0..00016c67. Semantic name remains unreviewed. */

int FUN_00016ba0(int *param_1)

{
  int iVar1;
  LPCWSTR local_18;
  DWORD local_14;
  DWORD local_10;
  BOOL local_c;
  
  iVar1 = FUN_0001c900(param_1,&local_14,4,1);
  if ((-1 < iVar1) && (iVar1 = FUN_0001cc40(param_1,&local_18), -1 < iVar1)) {
    FUN_0001ca4c((int)param_1);
    local_c = SetFileAttributesW(local_18,local_14);
    if (local_18 != (LPCWSTR)0x0) {
      operator_delete(local_18);
    }
    local_10 = GetLastError();
    iVar1 = FUN_0001cd50(param_1,&local_10,4);
    if ((-1 < iVar1) && (iVar1 = FUN_0001cd50(param_1,&local_c,4), -1 < iVar1)) {
      iVar1 = 0;
    }
  }
  return iVar1;
}



/* 00016c68 FUN_00016c68 */

/* Boundary evidence: original MIPS .pdata 00016c68..00016def. Semantic name remains unreviewed. */

int FUN_00016c68(int *param_1,undefined4 *param_2)

{
  int iVar1;
  LPCWSTR local_30;
  HANDLE local_2c;
  HANDLE local_28;
  DWORD local_24;
  DWORD local_20;
  DWORD local_1c;
  DWORD local_18;
  DWORD local_14;
  
  iVar1 = FUN_0001c900(param_1,&local_18,4,1);
  if (((((-1 < iVar1) && (iVar1 = FUN_0001c900(param_1,&local_1c,4,1), -1 < iVar1)) &&
       (iVar1 = FUN_0001c900(param_1,&local_20,4,1), -1 < iVar1)) &&
      ((iVar1 = FUN_0001c900(param_1,&local_24,4,1), -1 < iVar1 &&
       (iVar1 = FUN_0001c900(param_1,&local_28,4,1), -1 < iVar1)))) &&
     (iVar1 = FUN_0001cc40(param_1,&local_30), -1 < iVar1)) {
    FUN_0001ca4c((int)param_1);
    local_2c = CreateFileW(local_30,local_18,local_1c,(LPSECURITY_ATTRIBUTES)0x0,local_20,local_24,
                           local_28);
    if (local_30 != (LPCWSTR)0x0) {
      operator_delete(local_30);
    }
    if (local_2c != (HANDLE)0xffffffff) {
      FUN_0001308c(param_2,local_2c,1);
    }
    local_14 = GetLastError();
    iVar1 = FUN_0001cd50(param_1,&local_14,4);
    if ((-1 < iVar1) && (iVar1 = FUN_0001cd50(param_1,&local_2c,4), -1 < iVar1)) {
      iVar1 = 0;
    }
  }
  return iVar1;
}



/* 00016df0 FUN_00016df0 */

/* Boundary evidence: original MIPS .pdata 00016df0..00016fdb. Semantic name remains unreviewed. */

int FUN_00016df0(int *param_1)

{
  int iVar1;
  void *lpBuffer;
  LPOVERLAPPED lpOverlapped;
  uint local_50;
  int local_4c;
  uint local_48;
  int local_44;
  HANDLE local_40;
  DWORD local_3c;
  BOOL local_38 [2];
  _OVERLAPPED _Stack_30;
  
  lpOverlapped = (LPOVERLAPPED)0x0;
  lpBuffer = (void *)0x0;
  iVar1 = FUN_0001c900(param_1,&local_40,4,1);
  if ((((-1 < iVar1) && (iVar1 = FUN_0001c900(param_1,&local_4c,4,1), -1 < iVar1)) &&
      (iVar1 = FUN_0001c900(param_1,&local_50,4,1), -1 < iVar1)) &&
     (iVar1 = FUN_0001c900(param_1,&local_44,4,1), -1 < iVar1)) {
    if (local_44 != 0) {
      iVar1 = FUN_0001c900(param_1,&_Stack_30,0x14,1);
      if (iVar1 < 0) {
        return iVar1;
      }
      lpOverlapped = &_Stack_30;
    }
    if ((local_4c == 0) || (lpBuffer = operator_new(local_50), lpBuffer != (void *)0x0)) {
      FUN_0001ca4c((int)param_1);
      local_38[0] = ReadFile(local_40,lpBuffer,local_50,&local_48,lpOverlapped);
      local_3c = GetLastError();
      iVar1 = FUN_0001cd50(param_1,&local_3c,4);
      if (((-1 < iVar1) &&
          ((iVar1 = FUN_0001cd50(param_1,local_38,4), -1 < iVar1 &&
           (iVar1 = FUN_0001cd50(param_1,&local_48,4), -1 < iVar1)))) &&
         ((local_4c == 0 || (iVar1 = FUN_0001cd50(param_1,lpBuffer,local_48), -1 < iVar1)))) {
        iVar1 = 0;
      }
    }
    else {
      iVar1 = -0x7ff8fff2;
    }
    if (lpBuffer != (void *)0x0) {
      operator_delete(lpBuffer);
    }
  }
  return iVar1;
}



/* 00016fdc FUN_00016fdc */

/* Boundary evidence: original MIPS .pdata 00016fdc..000171cf. Semantic name remains unreviewed. */

int FUN_00016fdc(int *param_1)

{
  int iVar1;
  void *lpBuffer;
  LPOVERLAPPED lpOverlapped;
  uint local_50;
  int local_4c;
  int local_48;
  HANDLE local_44;
  DWORD local_40;
  BOOL local_3c;
  DWORD aDStack_38 [2];
  _OVERLAPPED _Stack_30;
  
  lpOverlapped = (LPOVERLAPPED)0x0;
  lpBuffer = (LPCVOID)0x0;
  iVar1 = FUN_0001c900(param_1,&local_44,4,1);
  if (iVar1 < 0) {
    return iVar1;
  }
  iVar1 = FUN_0001c900(param_1,&local_48,4,1);
  if (iVar1 < 0) {
    return iVar1;
  }
  iVar1 = FUN_0001c900(param_1,&local_50,4,1);
  if (iVar1 < 0) {
    return iVar1;
  }
  if (local_48 != 0) {
    lpBuffer = operator_new(local_50);
    if (lpBuffer == (void *)0x0) {
      iVar1 = -0x7ff8fff2;
      goto LAB_0001719c;
    }
    iVar1 = FUN_0001c900(param_1,lpBuffer,local_50,1);
    if (iVar1 < 0) goto LAB_0001719c;
  }
  local_4c = 0;
  iVar1 = FUN_0001c900(param_1,&local_4c,4,1);
  if (-1 < iVar1) {
    if (local_4c == 1) {
      iVar1 = FUN_0001c900(param_1,&_Stack_30,0x14,1);
      if (iVar1 < 0) goto LAB_0001719c;
      lpOverlapped = &_Stack_30;
    }
    FUN_0001ca4c((int)param_1);
    local_3c = WriteFile(local_44,lpBuffer,local_50,aDStack_38,lpOverlapped);
    local_40 = GetLastError();
    iVar1 = FUN_0001cd50(param_1,&local_40,4);
    if (((-1 < iVar1) && (iVar1 = FUN_0001cd50(param_1,&local_3c,4), -1 < iVar1)) &&
       (iVar1 = FUN_0001cd50(param_1,aDStack_38,4), -1 < iVar1)) {
      iVar1 = 0;
    }
  }
LAB_0001719c:
  if (lpBuffer != (void *)0x0) {
    operator_delete(lpBuffer);
  }
  return iVar1;
}



/* 000171d0 FUN_000171d0 */

/* Boundary evidence: original MIPS .pdata 000171d0..0001728f. Semantic name remains unreviewed. */

int FUN_000171d0(int *param_1,int *param_2)

{
  int iVar1;
  HANDLE local_20;
  BOOL local_1c;
  DWORD local_18 [2];
  
  iVar1 = FUN_0001c900(param_1,&local_20,4,1);
  if (-1 < iVar1) {
    FUN_0001ca4c((int)param_1);
    local_1c = CloseHandle(local_20);
    local_18[0] = GetLastError();
    iVar1 = FUN_0001cd50(param_1,local_18,4);
    if (-1 < iVar1) {
      if (local_1c != 0) {
        FUN_00013100(param_2,(int)local_20);
      }
      iVar1 = FUN_0001cd50(param_1,&local_1c,4);
      if (-1 < iVar1) {
        iVar1 = 0;
      }
    }
  }
  return iVar1;
}



/* 00017290 FUN_00017290 */

/* Boundary evidence: original MIPS .pdata 00017290..0001731f. Semantic name remains unreviewed. */

LPCWSTR FUN_00017290(LPWSTR param_1)

{
  WCHAR WVar1;
  bool bVar2;
  
  bVar2 = false;
  if (param_1 == (LPWSTR)0x0) {
    param_1 = (LPCWSTR)0x0;
  }
  else {
    for (; WVar1 = *param_1, WVar1 != L'\0'; param_1 = CharNextW(param_1)) {
      if (WVar1 == L'\"') {
        if (bVar2) {
          bVar2 = false;
        }
        else {
          bVar2 = true;
        }
      }
      else if ((!bVar2) && (WVar1 == L' ')) {
        return param_1 + 1;
      }
    }
  }
  return param_1;
}



/* 00017320 FUN_00017320 */

/* Boundary evidence: original MIPS .pdata 00017320..0001737b. Semantic name remains unreviewed. */

void FUN_00017320(LPWSTR param_1)

{
  LPCWSTR lpszCurrent;
  LPWSTR pWVar1;
  
  lpszCurrent = FUN_00017290(param_1);
  if (*lpszCurrent == L'\0') {
    pWVar1 = CharPrevW(param_1,lpszCurrent);
    if (*pWVar1 == L' ') {
      *pWVar1 = L'\0';
    }
  }
  else {
    lpszCurrent[-1] = L'\0';
  }
  return;
}



/* 0001737c FUN_0001737c */

/* Boundary evidence: original MIPS .pdata 0001737c..000173ff. Semantic name remains unreviewed. */

void FUN_0001737c(LPCWSTR param_1)

{
  LPCWSTR lpsz;
  LPWSTR _Source;
  
  if ((param_1 != (LPCWSTR)0x0) && (lpsz = param_1, *param_1 == L'\"')) {
    do {
      lpsz = CharNextW(lpsz);
      if (*lpsz == L'\0') break;
    } while (*lpsz != L'\"');
    *lpsz = L'\0';
    _Source = CharNextW(param_1);
    wcscpy(param_1,_Source);
  }
  return;
}



/* 00017400 FUN_00017400 */

/* Boundary evidence: original MIPS .pdata 00017400..000174b3. Semantic name remains unreviewed. */

undefined4 FUN_00017400(LPWSTR param_1,wchar_t *param_2,undefined4 *param_3,int param_4)

{
  LPCWSTR pWVar1;
  undefined4 uVar2;
  
  if (param_1 == (LPWSTR)0x0) {
    uVar2 = 0;
  }
  else {
    if (param_3 != (undefined4 *)0x0) {
      pWVar1 = FUN_00017290(param_1);
      *param_3 = pWVar1;
    }
    if (param_2 != (wchar_t *)0x0) {
      wcscpy(param_2,param_1);
      if (*param_2 == L'\"') {
        FUN_0001737c(param_2);
      }
      else {
        FUN_00017320(param_2);
      }
    }
    if (param_4 != 0) {
      FUN_0001737c(param_1);
    }
    uVar2 = 1;
  }
  return uVar2;
}



/* 000174b4 FUN_000174b4 */

/* Boundary evidence: original MIPS .pdata 000174b4..00017573. Semantic name remains unreviewed. */

int FUN_000174b4(int *param_1,undefined4 *param_2)

{
  int iVar1;
  int local_20;
  undefined4 local_1c;
  DWORD local_18 [2];
  
  iVar1 = FUN_0001c900(param_1,&local_1c,4,1);
  if (-1 < iVar1) {
    FUN_0001ca4c((int)param_1);
    local_20 = CeFindFirstDatabase(local_1c);
    local_18[0] = GetLastError();
    iVar1 = FUN_0001cd50(param_1,local_18,4);
    if (-1 < iVar1) {
      if (local_20 != -1) {
        FUN_0001308c(param_2,local_20,1);
      }
      iVar1 = FUN_0001cd50(param_1,&local_20,4);
      if (-1 < iVar1) {
        iVar1 = 0;
      }
    }
  }
  return iVar1;
}



/* 00017574 FUN_00017574 */

/* Boundary evidence: original MIPS .pdata 00017574..00017667. Semantic name remains unreviewed. */

int FUN_00017574(int *param_1,undefined4 *param_2)

{
  int iVar1;
  void *local_20;
  int local_1c;
  undefined4 local_18;
  DWORD local_14;
  
  local_20 = (void *)0x0;
  iVar1 = FUN_0001cb2c(param_1,(int *)&local_20,0);
  if ((-1 < iVar1) && (iVar1 = FUN_0001c900(param_1,&local_18,4,1), -1 < iVar1)) {
    FUN_0001ca4c((int)param_1);
    local_1c = CeFindFirstDatabaseEx(local_20,local_18);
    if (local_20 != (void *)0x0) {
      operator_delete(local_20);
    }
    local_14 = GetLastError();
    iVar1 = FUN_0001cd50(param_1,&local_14,4);
    if (-1 < iVar1) {
      if (local_1c != -1) {
        FUN_0001308c(param_2,local_1c,1);
      }
      iVar1 = FUN_0001cd50(param_1,&local_1c,4);
      if (-1 < iVar1) {
        iVar1 = 0;
      }
    }
  }
  return iVar1;
}



/* 00017668 FUN_00017668 */

/* Boundary evidence: original MIPS .pdata 00017668..000176fb. Semantic name remains unreviewed. */

int FUN_00017668(int *param_1)

{
  int iVar1;
  undefined4 local_18;
  DWORD local_14;
  undefined4 local_10 [2];
  
  iVar1 = FUN_0001c900(param_1,&local_18,4,1);
  if (-1 < iVar1) {
    FUN_0001ca4c((int)param_1);
    local_10[0] = CeFindNextDatabase(local_18);
    local_14 = GetLastError();
    iVar1 = FUN_0001cd50(param_1,&local_14,4);
    if ((-1 < iVar1) && (iVar1 = FUN_0001cd50(param_1,local_10,4), -1 < iVar1)) {
      iVar1 = 0;
    }
  }
  return iVar1;
}



/* 000176fc FUN_000176fc */

/* Boundary evidence: original MIPS .pdata 000176fc..000177c3. Semantic name remains unreviewed. */

int FUN_000176fc(int *param_1)

{
  int iVar1;
  void *local_18;
  undefined4 local_14;
  DWORD local_10;
  undefined4 local_c;
  
  local_18 = (void *)0x0;
  iVar1 = FUN_0001c900(param_1,&local_14,4,1);
  if ((-1 < iVar1) && (iVar1 = FUN_0001cb2c(param_1,(int *)&local_18,0), -1 < iVar1)) {
    FUN_0001ca4c((int)param_1);
    local_c = CeFindNextDatabaseEx(local_14,local_18);
    if (local_18 != (void *)0x0) {
      operator_delete(local_18);
    }
    local_10 = GetLastError();
    iVar1 = FUN_0001cd50(param_1,&local_10,4);
    if ((-1 < iVar1) && (iVar1 = FUN_0001cd50(param_1,&local_c,4), -1 < iVar1)) {
      iVar1 = 0;
    }
  }
  return iVar1;
}



/* 000177c4 FUN_000177c4 */

/* Boundary evidence: original MIPS .pdata 000177c4..000179df. Semantic name remains unreviewed. */

int FUN_000177c4(int *param_1)

{
  int iVar1;
  size_t sVar2;
  undefined1 *puVar3;
  uint uVar4;
  ushort local_248 [2];
  DWORD local_244;
  undefined4 local_240;
  undefined4 local_23c;
  short local_238 [2];
  undefined1 auStack_234 [4];
  wchar_t awStack_230 [2];
  wchar_t awStack_22c [30];
  undefined1 auStack_1f0 [460];
  undefined1 auStack_24 [12];
  
  iVar1 = FUN_0001c900(param_1,&local_23c,4,1);
  if (iVar1 < 0) {
    return iVar1;
  }
  FUN_0001ca4c((int)param_1);
  local_240 = CeOidGetInfo(local_23c,local_238);
  local_244 = GetLastError();
  iVar1 = FUN_0001cd50(param_1,&local_244,4);
  if (iVar1 < 0) {
    return iVar1;
  }
  iVar1 = FUN_0001cd50(param_1,&local_240,4);
  if (iVar1 < 0) {
    return iVar1;
  }
  iVar1 = FUN_0001cd50(param_1,local_238,2);
  if (iVar1 < 0) {
    return iVar1;
  }
  if (local_238[0] == 1) {
    sVar2 = wcslen(awStack_22c);
    local_248[0] = ((short)sVar2 + 5) * 2;
    iVar1 = FUN_0001cd50(param_1,local_248,2);
    if (iVar1 < 0) {
      return iVar1;
    }
    iVar1 = FUN_0001cd50(param_1,auStack_234,(uint)local_248[0]);
    if (iVar1 < 0) {
      return iVar1;
    }
    local_248[0] = 0xc;
    iVar1 = FUN_0001cd50(param_1,auStack_24,0xc);
    goto joined_r0x000179b8;
  }
  if (local_238[0] == 2) {
    sVar2 = wcslen(awStack_22c);
    local_248[0] = ((short)sVar2 + 5) * 2;
    iVar1 = FUN_0001cd50(param_1,local_248,2);
    if (iVar1 < 0) {
      return iVar1;
    }
    uVar4 = (uint)local_248[0];
LAB_0001793c:
    puVar3 = auStack_234;
  }
  else {
    if (local_238[0] != 3) {
      if (local_238[0] != 4) {
        return 0;
      }
      uVar4 = 4;
      goto LAB_0001793c;
    }
    sVar2 = wcslen(awStack_230);
    local_248[0] = ((short)sVar2 + 3) * 2;
    iVar1 = FUN_0001cd50(param_1,local_248,2);
    if (iVar1 < 0) {
      return iVar1;
    }
    iVar1 = FUN_0001cd50(param_1,auStack_234,(uint)local_248[0]);
    if (iVar1 < 0) {
      return iVar1;
    }
    local_248[0] = 0x34;
    uVar4 = 0x34;
    puVar3 = auStack_1f0;
  }
  iVar1 = FUN_0001cd50(param_1,puVar3,uVar4);
joined_r0x000179b8:
  if (-1 < iVar1) {
    return 0;
  }
  return iVar1;
}



/* 000179e0 FUN_000179e0 */

/* Boundary evidence: original MIPS .pdata 000179e0..00017c2f. Semantic name remains unreviewed. */

int FUN_000179e0(int *param_1)

{
  int iVar1;
  size_t sVar2;
  undefined1 *puVar3;
  uint uVar4;
  ushort local_250 [2];
  void *local_24c;
  undefined4 local_248;
  undefined4 local_244;
  DWORD local_240 [2];
  short local_238 [2];
  undefined1 auStack_234 [4];
  wchar_t awStack_230 [2];
  wchar_t awStack_22c [30];
  undefined1 auStack_1f0 [460];
  undefined1 auStack_24 [12];
  
  local_24c = (void *)0x0;
  iVar1 = FUN_0001cb2c(param_1,(int *)&local_24c,0);
  if (iVar1 < 0) {
    return iVar1;
  }
  iVar1 = FUN_0001c900(param_1,&local_248,4,1);
  if (iVar1 < 0) {
    return iVar1;
  }
  FUN_0001ca4c((int)param_1);
  local_244 = CeOidGetInfoEx(local_24c,local_248,local_238);
  if (local_24c != (void *)0x0) {
    operator_delete(local_24c);
  }
  local_240[0] = GetLastError();
  iVar1 = FUN_0001cd50(param_1,local_240,4);
  if (iVar1 < 0) {
    return iVar1;
  }
  iVar1 = FUN_0001cd50(param_1,&local_244,4);
  if (iVar1 < 0) {
    return iVar1;
  }
  iVar1 = FUN_0001cd50(param_1,local_238,2);
  if (iVar1 < 0) {
    return iVar1;
  }
  if (local_238[0] == 1) {
    sVar2 = wcslen(awStack_22c);
    local_250[0] = ((short)sVar2 + 5) * 2;
    iVar1 = FUN_0001cd50(param_1,local_250,2);
    if (iVar1 < 0) {
      return iVar1;
    }
    iVar1 = FUN_0001cd50(param_1,auStack_234,(uint)local_250[0]);
    if (iVar1 < 0) {
      return iVar1;
    }
    local_250[0] = 0xc;
    iVar1 = FUN_0001cd50(param_1,auStack_24,0xc);
    goto joined_r0x00017c08;
  }
  if (local_238[0] == 2) {
    sVar2 = wcslen(awStack_22c);
    local_250[0] = ((short)sVar2 + 5) * 2;
    iVar1 = FUN_0001cd50(param_1,local_250,2);
    if (iVar1 < 0) {
      return iVar1;
    }
    uVar4 = (uint)local_250[0];
LAB_00017b8c:
    puVar3 = auStack_234;
  }
  else {
    if (local_238[0] != 3) {
      if (local_238[0] != 4) {
        return 0;
      }
      uVar4 = 4;
      goto LAB_00017b8c;
    }
    sVar2 = wcslen(awStack_230);
    local_250[0] = ((short)sVar2 + 3) * 2;
    iVar1 = FUN_0001cd50(param_1,local_250,2);
    if (iVar1 < 0) {
      return iVar1;
    }
    iVar1 = FUN_0001cd50(param_1,auStack_234,(uint)local_250[0]);
    if (iVar1 < 0) {
      return iVar1;
    }
    local_250[0] = 0x34;
    uVar4 = 0x34;
    puVar3 = auStack_1f0;
  }
  iVar1 = FUN_0001cd50(param_1,puVar3,uVar4);
joined_r0x00017c08:
  if (-1 < iVar1) {
    return 0;
  }
  return iVar1;
}



/* 00017c30 FUN_00017c30 */

/* Boundary evidence: original MIPS .pdata 00017c30..00017d4f. Semantic name remains unreviewed. */

int FUN_00017c30(int *param_1)

{
  int iVar1;
  undefined1 *puVar2;
  ushort local_48 [2];
  void *local_44;
  undefined4 local_40;
  DWORD local_3c;
  undefined4 local_38 [2];
  undefined1 auStack_30 [32];
  
  puVar2 = (undefined1 *)0x0;
  iVar1 = FUN_0001c900(param_1,&local_40,4,1);
  if ((-1 < iVar1) && (iVar1 = FUN_0001c900(param_1,local_48,2,1), -1 < iVar1)) {
    if (local_48[0] != 0) {
      iVar1 = FUN_0001c900(param_1,auStack_30,(uint)local_48[0] << 3,1);
      if (iVar1 < 0) {
        return iVar1;
      }
      puVar2 = auStack_30;
    }
    iVar1 = FUN_0001cc40(param_1,&local_44);
    if (-1 < iVar1) {
      FUN_0001ca4c((int)param_1);
      local_38[0] = CeCreateDatabase(local_44,local_40,local_48[0],puVar2);
      if (local_44 != (void *)0x0) {
        operator_delete(local_44);
      }
      local_3c = GetLastError();
      iVar1 = FUN_0001cd50(param_1,&local_3c,4);
      if ((-1 < iVar1) && (iVar1 = FUN_0001cd50(param_1,local_38,4), -1 < iVar1)) {
        iVar1 = 0;
      }
    }
  }
  return iVar1;
}



/* 00017d50 FUN_00017d50 */

/* Boundary evidence: original MIPS .pdata 00017d50..00017e2b. Semantic name remains unreviewed. */

int FUN_00017d50(int *param_1)

{
  int iVar1;
  void *local_18;
  void *local_14;
  DWORD local_10;
  undefined4 local_c;
  
  local_18 = (void *)0x0;
  local_14 = (void *)0x0;
  iVar1 = FUN_0001cb2c(param_1,(int *)&local_18,0);
  if ((-1 < iVar1) && (iVar1 = FUN_0001cb2c(param_1,(int *)&local_14,0), -1 < iVar1)) {
    FUN_0001ca4c((int)param_1);
    local_c = CeCreateDatabaseEx(local_18,local_14);
    if (local_18 != (void *)0x0) {
      operator_delete(local_18);
    }
    if (local_14 != (void *)0x0) {
      operator_delete(local_14);
    }
    local_10 = GetLastError();
    iVar1 = FUN_0001cd50(param_1,&local_10,4);
    if ((-1 < iVar1) && (iVar1 = FUN_0001cd50(param_1,&local_c,4), -1 < iVar1)) {
      iVar1 = 0;
    }
  }
  return iVar1;
}



/* 00017e2c FUN_00017e2c */

/* Boundary evidence: original MIPS .pdata 00017e2c..00017f9b. Semantic name remains unreviewed. */

int FUN_00017e2c(int *param_1,undefined4 *param_2)

{
  bool bVar1;
  int iVar2;
  void *local_28;
  int local_24;
  int local_20;
  undefined4 local_1c;
  undefined4 local_18;
  DWORD local_14;
  
  local_28 = (void *)0x0;
  bVar1 = false;
  iVar2 = FUN_0001c900(param_1,&local_24,4,1);
  if (((-1 < iVar2) && (iVar2 = FUN_0001c900(param_1,&local_18,4,1), -1 < iVar2)) &&
     (iVar2 = FUN_0001c900(param_1,&local_1c,4,1), -1 < iVar2)) {
    if (local_24 == 0) {
      bVar1 = true;
      iVar2 = FUN_0001cc40(param_1,&local_28);
      if (iVar2 < 0) {
        return iVar2;
      }
    }
    FUN_0001ca4c((int)param_1);
    local_20 = CeOpenDatabase(&local_24,local_28,local_18,local_1c,0);
    if (local_28 != (void *)0x0) {
      operator_delete(local_28);
    }
    local_14 = GetLastError();
    iVar2 = FUN_0001cd50(param_1,&local_14,4);
    if (-1 < iVar2) {
      if (local_20 != -1) {
        FUN_0001308c(param_2,local_20,1);
      }
      iVar2 = FUN_0001cd50(param_1,&local_20,4);
      if ((-1 < iVar2) && ((!bVar1 || (iVar2 = FUN_0001cd50(param_1,&local_24,4), -1 < iVar2)))) {
        iVar2 = 0;
      }
    }
  }
  return iVar2;
}



/* 00017f9c FUN_00017f9c */

/* Boundary evidence: original MIPS .pdata 00017f9c..00018143. Semantic name remains unreviewed. */

int FUN_00017f9c(int *param_1,undefined4 *param_2)

{
  bool bVar1;
  int iVar2;
  void *local_30;
  void *local_2c;
  int local_28;
  int local_24;
  undefined4 local_20;
  undefined4 local_1c;
  DWORD local_18 [2];
  
  local_30 = (void *)0x0;
  local_2c = (void *)0x0;
  bVar1 = false;
  iVar2 = FUN_0001cb2c(param_1,(int *)&local_30,0);
  if ((((-1 < iVar2) && (iVar2 = FUN_0001c900(param_1,&local_28,4,1), -1 < iVar2)) &&
      (iVar2 = FUN_0001c900(param_1,&local_1c,4,1), -1 < iVar2)) &&
     (iVar2 = FUN_0001c900(param_1,&local_20,4,1), -1 < iVar2)) {
    if (local_28 == 0) {
      bVar1 = true;
      iVar2 = FUN_0001cc40(param_1,&local_2c);
      if (iVar2 < 0) {
        return iVar2;
      }
    }
    FUN_0001ca4c((int)param_1);
    local_24 = CeOpenDatabaseEx(local_30,&local_28,local_2c,local_1c,local_20,0);
    if (local_30 != (void *)0x0) {
      operator_delete(local_30);
    }
    if (local_2c != (void *)0x0) {
      operator_delete(local_2c);
    }
    local_18[0] = GetLastError();
    iVar2 = FUN_0001cd50(param_1,local_18,4);
    if (-1 < iVar2) {
      if (local_24 != -1) {
        FUN_0001308c(param_2,local_24,1);
      }
      iVar2 = FUN_0001cd50(param_1,&local_24,4);
      if ((-1 < iVar2) && ((!bVar1 || (iVar2 = FUN_0001cd50(param_1,&local_28,4), -1 < iVar2)))) {
        iVar2 = 0;
      }
    }
  }
  return iVar2;
}



/* 00018144 FUN_00018144 */

/* Boundary evidence: original MIPS .pdata 00018144..000181d7. Semantic name remains unreviewed. */

int FUN_00018144(int *param_1)

{
  int iVar1;
  undefined4 local_18;
  DWORD local_14;
  undefined4 local_10 [2];
  
  iVar1 = FUN_0001c900(param_1,&local_18,4,1);
  if (-1 < iVar1) {
    FUN_0001ca4c((int)param_1);
    local_10[0] = CeDeleteDatabase(local_18);
    local_14 = GetLastError();
    iVar1 = FUN_0001cd50(param_1,&local_14,4);
    if ((-1 < iVar1) && (iVar1 = FUN_0001cd50(param_1,local_10,4), -1 < iVar1)) {
      iVar1 = 0;
    }
  }
  return iVar1;
}



/* 000181d8 FUN_000181d8 */

/* Boundary evidence: original MIPS .pdata 000181d8..0001829f. Semantic name remains unreviewed. */

int FUN_000181d8(int *param_1)

{
  int iVar1;
  void *local_18;
  undefined4 local_14;
  DWORD local_10;
  undefined4 local_c;
  
  local_18 = (void *)0x0;
  iVar1 = FUN_0001cb2c(param_1,(int *)&local_18,0);
  if ((-1 < iVar1) && (iVar1 = FUN_0001c900(param_1,&local_14,4,1), -1 < iVar1)) {
    FUN_0001ca4c((int)param_1);
    local_c = CeDeleteDatabaseEx(local_18,local_14);
    if (local_18 != (void *)0x0) {
      operator_delete(local_18);
    }
    local_10 = GetLastError();
    iVar1 = FUN_0001cd50(param_1,&local_10,4);
    if ((-1 < iVar1) && (iVar1 = FUN_0001cd50(param_1,&local_c,4), -1 < iVar1)) {
      iVar1 = 0;
    }
  }
  return iVar1;
}



/* 000182a0 FUN_000182a0 */

/* Boundary evidence: original MIPS .pdata 000182a0..0001858b. Semantic name remains unreviewed. */

int FUN_000182a0(int *param_1)

{
  int iVar1;
  int *piVar2;
  void *pvVar3;
  ushort local_30 [2];
  void *local_2c;
  uint local_28;
  int local_24;
  int local_20;
  undefined4 local_1c;
  undefined4 local_18;
  DWORD local_14;
  
  local_2c = (void *)0x0;
  pvVar3 = (void *)0x0;
  iVar1 = FUN_0001c900(param_1,&local_18,4,1);
  if ((((iVar1 < 0) || (iVar1 = FUN_0001c900(param_1,&local_1c,4,1), iVar1 < 0)) ||
      (iVar1 = FUN_0001c900(param_1,local_30,2,1), iVar1 < 0)) ||
     (iVar1 = FUN_0001c900(param_1,&local_24,4,1), iVar1 < 0)) goto LAB_00018384;
  if (local_24 == 0) {
LAB_000183d4:
    iVar1 = FUN_0001c900(param_1,&local_28,4,1);
    if (-1 < iVar1) {
      if ((local_28 == 0) || (local_2c = operator_new(local_28), local_2c != (void *)0x0)) {
        FUN_0001ca4c((int)param_1);
        local_20 = CeReadRecordProps(local_18,local_1c,local_30,pvVar3,&local_2c,&local_28);
        local_14 = GetLastError();
        iVar1 = FUN_0001cd50(param_1,&local_14,4);
        if (((-1 < iVar1) &&
            ((iVar1 = FUN_0001cd50(param_1,&local_20,4), -1 < iVar1 &&
             (iVar1 = FUN_0001cd50(param_1,&local_28,4), -1 < iVar1)))) &&
           ((local_24 != 0 || (iVar1 = FUN_0001cd50(param_1,local_30,2), -1 < iVar1)))) {
          if (((local_20 != 0) && (local_28 != 0)) && (local_2c != (void *)0x0)) {
            iVar1 = 0;
            if (local_30[0] != 0) {
              piVar2 = (int *)((int)local_2c + 8);
              do {
                if ((short)piVar2[-2] == 0x1f) {
                  *piVar2 = *piVar2 - (int)local_2c;
                }
                else if ((short)piVar2[-2] == 0x41) {
                  piVar2[1] = piVar2[1] - (int)local_2c;
                }
                iVar1 = iVar1 + 1;
                piVar2 = piVar2 + 4;
              } while (iVar1 < (int)(uint)local_30[0]);
            }
            iVar1 = FUN_0001cd50(param_1,local_2c,local_28);
            if (iVar1 < 0) goto LAB_00018370;
          }
          iVar1 = 0;
        }
      }
      else {
        iVar1 = -0x7ff8fff2;
      }
    }
  }
  else {
    pvVar3 = operator_new((uint)local_30[0] << 2);
    if (pvVar3 == (void *)0x0) {
      iVar1 = -0x7ff8fff2;
    }
    else {
      iVar1 = FUN_0001c900(param_1,pvVar3,(uint)local_30[0] << 2,1);
      if (-1 < iVar1) goto LAB_000183d4;
    }
  }
LAB_00018370:
  if (pvVar3 != (void *)0x0) {
    operator_delete(pvVar3);
  }
LAB_00018384:
  if (local_2c != (void *)0x0) {
    operator_delete(local_2c);
  }
  return iVar1;
}



/* 0001858c FUN_0001858c */

/* Boundary evidence: original MIPS .pdata 0001858c..0001889f. Semantic name remains unreviewed. */

int FUN_0001858c(int *param_1)

{
  int iVar1;
  int *piVar2;
  void *pvVar3;
  ushort local_38 [2];
  void *local_34;
  uint local_30;
  int local_2c;
  int local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  DWORD local_18 [2];
  
  local_34 = (void *)0x0;
  pvVar3 = (void *)0x0;
  iVar1 = FUN_0001c900(param_1,&local_1c,4,1);
  if ((((iVar1 < 0) || (iVar1 = FUN_0001c900(param_1,&local_20,4,1), iVar1 < 0)) ||
      (iVar1 = FUN_0001c900(param_1,local_38,2,1), iVar1 < 0)) ||
     (iVar1 = FUN_0001c900(param_1,&local_2c,4,1), iVar1 < 0)) goto LAB_00018670;
  if (local_2c == 0) {
LAB_000186c0:
    iVar1 = FUN_0001c900(param_1,&local_30,4,1);
    if (-1 < iVar1) {
      if ((local_30 == 0) || (local_34 = operator_new(local_30), local_34 != (void *)0x0)) {
        iVar1 = FUN_0001c900(param_1,&local_24,4,1);
        if (-1 < iVar1) {
          FUN_0001ca4c((int)param_1);
          local_28 = CeReadRecordPropsEx(local_1c,local_20,local_38,pvVar3,&local_34,&local_30,
                                         local_24);
          local_18[0] = GetLastError();
          iVar1 = FUN_0001cd50(param_1,local_18,4);
          if (((-1 < iVar1) && (iVar1 = FUN_0001cd50(param_1,&local_28,4), -1 < iVar1)) &&
             ((iVar1 = FUN_0001cd50(param_1,&local_30,4), -1 < iVar1 &&
              ((local_2c != 0 || (iVar1 = FUN_0001cd50(param_1,local_38,2), -1 < iVar1)))))) {
            if ((local_28 != 0) && ((local_30 != 0 && (local_34 != (void *)0x0)))) {
              iVar1 = 0;
              if (local_38[0] != 0) {
                piVar2 = (int *)((int)local_34 + 8);
                do {
                  if ((short)piVar2[-2] == 0x1f) {
                    *piVar2 = *piVar2 - (int)local_34;
                  }
                  else if ((short)piVar2[-2] == 0x41) {
                    piVar2[1] = piVar2[1] - (int)local_34;
                  }
                  iVar1 = iVar1 + 1;
                  piVar2 = piVar2 + 4;
                } while (iVar1 < (int)(uint)local_38[0]);
              }
              iVar1 = FUN_0001cd50(param_1,local_34,local_30);
              if (iVar1 < 0) goto LAB_0001865c;
            }
            iVar1 = 0;
          }
        }
      }
      else {
        iVar1 = -0x7ff8fff2;
      }
    }
  }
  else {
    pvVar3 = operator_new((uint)local_38[0] << 2);
    if (pvVar3 == (void *)0x0) {
      iVar1 = -0x7ff8fff2;
    }
    else {
      iVar1 = FUN_0001c900(param_1,pvVar3,(uint)local_38[0] << 2,1);
      if (-1 < iVar1) goto LAB_000186c0;
    }
  }
LAB_0001865c:
  if (pvVar3 != (void *)0x0) {
    operator_delete(pvVar3);
  }
LAB_00018670:
  if (local_34 != (void *)0x0) {
    operator_delete(local_34);
  }
  return iVar1;
}



/* 000188a0 FUN_000188a0 */

/* Boundary evidence: original MIPS .pdata 000188a0..00018a97. Semantic name remains unreviewed. */

int FUN_000188a0(int *param_1)

{
  int iVar1;
  int *piVar2;
  void *pvVar3;
  ushort local_28 [2];
  uint local_24;
  undefined4 local_20;
  undefined4 local_1c;
  DWORD local_18;
  undefined4 local_14;
  
  pvVar3 = (void *)0x0;
  iVar1 = FUN_0001c900(param_1,&local_1c,4,1);
  if (iVar1 < 0) {
    return iVar1;
  }
  iVar1 = FUN_0001c900(param_1,&local_20,4,1);
  if (iVar1 < 0) {
    return iVar1;
  }
  iVar1 = FUN_0001c900(param_1,local_28,2,1);
  if (iVar1 < 0) {
    return iVar1;
  }
  if (local_28[0] != 0) {
    local_24 = 0;
    iVar1 = FUN_0001c900(param_1,&local_24,4,1);
    if (iVar1 < 0) {
      return iVar1;
    }
    pvVar3 = operator_new(local_24);
    if (pvVar3 == (void *)0x0) {
      return -0x7ff8fff2;
    }
    iVar1 = FUN_0001c900(param_1,pvVar3,local_24,1);
    if (iVar1 < 0) {
      operator_delete(pvVar3);
      return iVar1;
    }
    iVar1 = 0;
    if (local_28[0] != 0) {
      piVar2 = (int *)((int)pvVar3 + 8);
      do {
        if ((short)piVar2[-2] == 0x1f) {
          *piVar2 = *piVar2 + (int)pvVar3;
        }
        else if ((short)piVar2[-2] == 0x41) {
          piVar2[1] = piVar2[1] + (int)pvVar3;
        }
        iVar1 = iVar1 + 1;
        piVar2 = piVar2 + 4;
      } while (iVar1 < (int)(uint)local_28[0]);
    }
  }
  FUN_0001ca4c((int)param_1);
  local_14 = CeWriteRecordProps(local_1c,local_20,local_28[0],pvVar3);
  if (pvVar3 != (void *)0x0) {
    operator_delete(pvVar3);
  }
  local_18 = GetLastError();
  iVar1 = FUN_0001cd50(param_1,&local_18,4);
  if ((-1 < iVar1) && (iVar1 = FUN_0001cd50(param_1,&local_14,4), -1 < iVar1)) {
    iVar1 = 0;
  }
  return iVar1;
}



/* 00018a98 FUN_00018a98 */

/* Boundary evidence: original MIPS .pdata 00018a98..00018b4b. Semantic name remains unreviewed. */

int FUN_00018a98(int *param_1)

{
  int iVar1;
  undefined4 local_18;
  undefined4 local_14;
  DWORD local_10;
  undefined4 local_c;
  
  iVar1 = FUN_0001c900(param_1,&local_14,4,1);
  if ((-1 < iVar1) && (iVar1 = FUN_0001c900(param_1,&local_18,4,1), -1 < iVar1)) {
    FUN_0001ca4c((int)param_1);
    local_c = CeDeleteRecord(local_14,local_18);
    local_10 = GetLastError();
    iVar1 = FUN_0001cd50(param_1,&local_10,4);
    if ((-1 < iVar1) && (iVar1 = FUN_0001cd50(param_1,&local_c,4), -1 < iVar1)) {
      iVar1 = 0;
    }
  }
  return iVar1;
}



/* 00018b4c FUN_00018b4c */

/* Boundary evidence: original MIPS .pdata 00018b4c..00018d43. Semantic name remains unreviewed. */

int FUN_00018b4c(int *param_1)

{
  int iVar1;
  short *psVar2;
  short *local_28;
  int local_24;
  undefined4 local_20;
  DWORD local_1c;
  undefined4 local_18;
  undefined1 auStack_14 [4];
  
  psVar2 = (short *)0x0;
  iVar1 = FUN_0001c900(param_1,&local_20,4,1);
  if (iVar1 < 0) {
    return iVar1;
  }
  iVar1 = FUN_0001c900(param_1,&local_24,4,1);
  if (iVar1 < 0) {
    return iVar1;
  }
  iVar1 = FUN_0001c900(param_1,&local_28,4,1);
  if (iVar1 < 0) {
    return iVar1;
  }
  if ((((local_24 == 0x10) || (local_24 == 0x20)) || (local_24 == 0x80)) || (local_24 == 0x40)) {
    psVar2 = operator_new((uint)local_28);
    if (psVar2 == (short *)0x0) {
      return -0x7ff8fff2;
    }
    iVar1 = FUN_0001c900(param_1,psVar2,(uint)local_28,1);
    if (iVar1 < 0) {
      operator_delete(psVar2);
      return iVar1;
    }
    local_28 = psVar2;
    if (*psVar2 == 0x1f) {
      *(int *)(psVar2 + 4) = *(int *)(psVar2 + 4) + (int)psVar2;
    }
    else if (*psVar2 == 0x41) {
      *(int *)(psVar2 + 6) = *(int *)(psVar2 + 6) + (int)psVar2;
    }
  }
  FUN_0001ca4c((int)param_1);
  local_18 = CeSeekDatabase(local_20,local_24,local_28,auStack_14);
  if (psVar2 != (short *)0x0) {
    operator_delete(psVar2);
  }
  local_1c = GetLastError();
  iVar1 = FUN_0001cd50(param_1,&local_1c,4);
  if (((-1 < iVar1) && (iVar1 = FUN_0001cd50(param_1,&local_18,4), -1 < iVar1)) &&
     (iVar1 = FUN_0001cd50(param_1,auStack_14,4), -1 < iVar1)) {
    iVar1 = 0;
  }
  return iVar1;
}



/* 00018d44 FUN_00018d44 */

/* Boundary evidence: original MIPS .pdata 00018d44..00018e37. Semantic name remains unreviewed. */

int FUN_00018d44(int *param_1)

{
  int iVar1;
  DWORD local_a0;
  undefined4 local_9c;
  undefined4 local_98 [2];
  undefined1 auStack_90 [120];
  uint local_18;
  
  local_18 = DAT_0001e29c;
  iVar1 = FUN_0001c900(param_1,local_98,4,1);
  if ((-1 < iVar1) && (iVar1 = FUN_0001c900(param_1,auStack_90,0x78,1), -1 < iVar1)) {
    FUN_0001ca4c((int)param_1);
    local_9c = CeSetDatabaseInfo(local_98[0],auStack_90);
    local_a0 = GetLastError();
    iVar1 = FUN_0001cd50(param_1,&local_a0,4);
    if (-1 < iVar1) {
      iVar1 = FUN_0001cd50(param_1,&local_9c,4);
      FUN_0001d140(local_18);
      if (iVar1 < 0) {
        return iVar1;
      }
      return 0;
    }
  }
  FUN_0001d140(local_18);
  return iVar1;
}



/* 00018e38 FUN_00018e38 */

/* Boundary evidence: original MIPS .pdata 00018e38..00018f63. Semantic name remains unreviewed. */

int FUN_00018e38(int *param_1)

{
  int iVar1;
  void *local_a0;
  DWORD local_9c;
  undefined4 local_98;
  undefined4 local_94;
  undefined1 auStack_90 [120];
  uint local_18;
  
  local_18 = DAT_0001e29c;
  local_a0 = (void *)0x0;
  iVar1 = FUN_0001cb2c(param_1,(int *)&local_a0,0);
  if (((-1 < iVar1) && (iVar1 = FUN_0001c900(param_1,&local_94,4,1), -1 < iVar1)) &&
     (iVar1 = FUN_0001c900(param_1,auStack_90,0x78,1), -1 < iVar1)) {
    FUN_0001ca4c((int)param_1);
    local_98 = CeSetDatabaseInfoEx(local_a0,local_94,auStack_90);
    if (local_a0 != (void *)0x0) {
      operator_delete(local_a0);
    }
    local_9c = GetLastError();
    iVar1 = FUN_0001cd50(param_1,&local_9c,4);
    if (-1 < iVar1) {
      iVar1 = FUN_0001cd50(param_1,&local_98,4);
      FUN_0001d140(local_18);
      if (iVar1 < 0) {
        return iVar1;
      }
      return 0;
    }
  }
  FUN_0001d140(local_18);
  return iVar1;
}



/* 00018f64 FUN_00018f64 */

/* Boundary evidence: original MIPS .pdata 00018f64..000191df. Semantic name remains unreviewed. */

int FUN_00018f64(int *param_1)

{
  int iVar1;
  HANDLE hObject;
  size_t sVar2;
  undefined1 *puVar3;
  uint uVar4;
  uint *puVar5;
  uint uVar6;
  short local_278;
  ushort local_276;
  int local_274;
  int local_270;
  undefined4 local_26c;
  uint local_268 [8];
  undefined1 auStack_248 [4];
  undefined1 auStack_244 [4];
  wchar_t awStack_240 [268];
  
  iVar1 = FUN_0001c900(param_1,&local_26c,4,1);
  if ((-1 < iVar1) && (iVar1 = FUN_0001c900(param_1,&local_276,2,1), -1 < iVar1)) {
    local_278 = 0;
    FUN_0001ca4c((int)param_1);
    hObject = (HANDLE)CeFindFirstDatabase(local_26c);
    if (hObject == (HANDLE)0xffffffff) {
      iVar1 = FUN_0001cd50(param_1,&local_278,2);
      if (-1 < iVar1) {
        iVar1 = 0;
      }
    }
    else {
      local_268[0] = 4;
      local_268[2] = 4;
      local_268[3] = 2;
      local_268[4] = 2;
      local_268[5] = 4;
      local_268[6] = 8;
      local_268[7] = 0x20;
      while (local_274 = CeFindNextDatabase(hObject), local_274 != 0) {
        local_278 = local_278 + 1;
        if (((local_276 & 1) != 0) && (iVar1 = FUN_0001cd50(param_1,&local_274,4), iVar1 < 0))
        goto LAB_00019194;
        if ((local_276 & 0xfffe) != 0) {
          iVar1 = CeOidGetInfo(local_274,auStack_248);
          if (iVar1 == 0) {
            iVar1 = -0x7fffbffb;
            goto LAB_00019194;
          }
          if ((local_276 & 4) != 0) {
            sVar2 = wcslen(awStack_240);
            local_270 = sVar2 + 1;
            iVar1 = FUN_0001cd50(param_1,&local_270,4);
            if (iVar1 < 0) goto LAB_00019194;
            local_268[1] = local_270 << 1;
          }
          puVar3 = auStack_244;
          uVar4 = 0;
          puVar5 = local_268;
          do {
            uVar4 = uVar4 + 1;
            uVar6 = 1 << (uVar4 & 0x1f);
            if (((local_276 & uVar6) != 0) &&
               (iVar1 = FUN_0001cd50(param_1,puVar3,*puVar5), iVar1 < 0)) goto LAB_00019194;
            if ((uVar6 & 4) == 0) {
              puVar3 = puVar3 + *puVar5;
            }
            else {
              puVar3 = puVar3 + 0x40;
            }
            puVar5 = puVar5 + 1;
          } while (uVar4 < 8);
        }
      }
      iVar1 = FUN_0001ce7c(param_1,&local_278,2);
      if (-1 < iVar1) {
        iVar1 = 0;
LAB_00019194:
        CloseHandle(hObject);
      }
    }
  }
  return iVar1;
}



/* 000191e0 FUN_000191e0 */

/* Boundary evidence: original MIPS .pdata 000191e0..0001930f. Semantic name remains unreviewed. */

undefined4 FUN_000191e0(wchar_t *param_1,wchar_t *param_2)

{
  size_t sVar1;
  HANDLE hFindFile;
  BOOL BVar2;
  _WIN32_FIND_DATAW local_450;
  uint local_18;
  
  local_18 = DAT_0001e29c;
  if ((((param_1 != (wchar_t *)0x0) && (param_2 != (wchar_t *)0x0)) &&
      (sVar1 = wcslen(param_1), sVar1 != 0)) && (sVar1 = wcslen(param_2), sVar1 != 0)) {
    wcscpy(local_450.cFileName + 0x102,param_1);
    sVar1 = wcslen(local_450.cFileName + 0x102);
    wcscpy(local_450.cFileName + sVar1 + 0x101,param_2);
    wcscat(local_450.cFileName + 0x102,L"\\*");
    hFindFile = FindFirstFileW(local_450.cFileName + 0x102,&local_450);
    if (hFindFile != (HANDLE)0xffffffff) {
      do {
        if ((local_450.dwFileAttributes & 0x10) != 0) {
          FindClose(hFindFile);
          FUN_0001d140(local_18);
          return 1;
        }
        BVar2 = FindNextFileW(hFindFile,&local_450);
      } while (BVar2 != 0);
      FindClose(hFindFile);
    }
  }
  FUN_0001d140(local_18);
  return 0;
}



/* 00019310 FUN_00019310 */

/* Boundary evidence: original MIPS .pdata 00019310..000193cf. Semantic name remains unreviewed. */

int FUN_00019310(int *param_1)

{
  int iVar1;
  void *local_18;
  undefined4 local_14;
  DWORD local_10;
  undefined4 local_c;
  
  iVar1 = FUN_0001c900(param_1,&local_14,4,1);
  if ((-1 < iVar1) && (iVar1 = FUN_0001cc40(param_1,&local_18), -1 < iVar1)) {
    FUN_0001ca4c((int)param_1);
    local_c = CeEventHasOccurred(local_14,local_18);
    if (local_18 != (void *)0x0) {
      operator_delete(local_18);
    }
    local_10 = GetLastError();
    iVar1 = FUN_0001cd50(param_1,&local_10,4);
    if ((-1 < iVar1) && (iVar1 = FUN_0001cd50(param_1,&local_c,4), -1 < iVar1)) {
      iVar1 = 0;
    }
  }
  return iVar1;
}



/* 000193d0 FUN_000193d0 */

/* Boundary evidence: original MIPS .pdata 000193d0..000194eb. Semantic name remains unreviewed. */

int FUN_000193d0(int *param_1,undefined4 *param_2)

{
  int iVar1;
  HKEY local_28;
  LPCWSTR local_24;
  LSTATUS local_20;
  HKEY local_1c;
  DWORD local_18 [2];
  
  local_28 = (HKEY)0x0;
  iVar1 = FUN_0001c900(param_1,&local_1c,4,1);
  if ((-1 < iVar1) && (iVar1 = FUN_0001cc40(param_1,&local_24), -1 < iVar1)) {
    FUN_0001ca4c((int)param_1);
    local_20 = RegOpenKeyExW(local_1c,local_24,0,0,&local_28);
    if (local_24 != (LPCWSTR)0x0) {
      operator_delete(local_24);
    }
    local_18[0] = GetLastError();
    iVar1 = FUN_0001cd50(param_1,local_18,4);
    if (-1 < iVar1) {
      if (local_20 == 0) {
        FUN_0001308c(param_2,local_28,4);
      }
      iVar1 = FUN_0001cd50(param_1,&local_20,4);
      if ((-1 < iVar1) && (iVar1 = FUN_0001cd50(param_1,&local_28,4), -1 < iVar1)) {
        iVar1 = 0;
      }
    }
  }
  return iVar1;
}



/* 000194ec FUN_000194ec */

/* Boundary evidence: original MIPS .pdata 000194ec..00019657. Semantic name remains unreviewed. */

int FUN_000194ec(int *param_1,undefined4 *param_2)

{
  int iVar1;
  LPCWSTR local_30;
  LPWSTR local_2c;
  LSTATUS local_28;
  HKEY local_24;
  HKEY local_20;
  DWORD local_1c;
  DWORD aDStack_18 [2];
  
  iVar1 = FUN_0001c900(param_1,&local_20,4,1);
  if (((-1 < iVar1) && (iVar1 = FUN_0001cc40(param_1,&local_30), -1 < iVar1)) &&
     (iVar1 = FUN_0001cc40(param_1,&local_2c), -1 < iVar1)) {
    FUN_0001ca4c((int)param_1);
    local_28 = RegCreateKeyExW(local_20,local_30,0,local_2c,0,0,(LPSECURITY_ATTRIBUTES)0x0,&local_24
                               ,aDStack_18);
    if (local_30 != (LPCWSTR)0x0) {
      operator_delete(local_30);
    }
    if (local_2c != (LPWSTR)0x0) {
      operator_delete(local_2c);
    }
    local_1c = GetLastError();
    iVar1 = FUN_0001cd50(param_1,&local_1c,4);
    if (-1 < iVar1) {
      if (local_28 == 0) {
        FUN_0001308c(param_2,local_24,4);
      }
      iVar1 = FUN_0001cd50(param_1,&local_28,4);
      if (((-1 < iVar1) && (iVar1 = FUN_0001cd50(param_1,&local_24,4), -1 < iVar1)) &&
         (iVar1 = FUN_0001cd50(param_1,aDStack_18,4), -1 < iVar1)) {
        iVar1 = 0;
      }
    }
  }
  return iVar1;
}



/* 00019658 FUN_00019658 */

/* Boundary evidence: original MIPS .pdata 00019658..00019717. Semantic name remains unreviewed. */

int FUN_00019658(int *param_1,int *param_2)

{
  int iVar1;
  HKEY local_20;
  LSTATUS local_1c;
  DWORD local_18 [2];
  
  iVar1 = FUN_0001c900(param_1,&local_20,4,1);
  if (-1 < iVar1) {
    FUN_0001ca4c((int)param_1);
    local_1c = RegCloseKey(local_20);
    local_18[0] = GetLastError();
    iVar1 = FUN_0001cd50(param_1,local_18,4);
    if (-1 < iVar1) {
      if (local_1c == 0) {
        FUN_00013100(param_2,(int)local_20);
      }
      iVar1 = FUN_0001cd50(param_1,&local_1c,4);
      if (-1 < iVar1) {
        iVar1 = 0;
      }
    }
  }
  return iVar1;
}



/* 00019718 FUN_00019718 */

/* Boundary evidence: original MIPS .pdata 00019718..00019933. Semantic name remains unreviewed. */

undefined8
FUN_00019718(undefined4 param_1,uint param_2,undefined4 param_3,undefined4 param_4,WORD param_5)

{
  bool bVar1;
  uint *puVar2;
  undefined1 *puVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  SYSTEMTIME local_res0;
  _FILETIME local_28;
  SYSTEMTIME local_20;
  
  puVar3 = (undefined1 *)((int)&local_res0.wDay + 1);
  uVar4 = (uint)puVar3 & 3;
  puVar2 = (uint *)(puVar3 + -uVar4);
  *puVar2 = *puVar2 & -1 << (uVar4 + 1) * 8 | param_2 >> (3 - uVar4) * 8;
  local_res0.wYear = (WORD)param_1;
  local_res0._0_4_ = param_1;
  local_res0._4_4_ = param_2;
  local_res0._8_4_ = param_3;
  local_res0._12_4_ = param_4;
  if (local_res0.wYear == 0) {
    memcpy(&local_20,&local_res0,0x10);
    local_20.wYear = param_5;
    local_20.wMonth = local_res0.wMonth;
    local_20.wDay = 1;
    if (local_res0.wDay == 5) {
      if (local_res0.wMonth == 0xc) {
        local_20.wYear = param_5 + 1;
        local_20.wMonth = 1;
      }
      else {
        local_20.wMonth = local_res0.wMonth + 1;
      }
    }
    SystemTimeToFileTime(&local_20,&local_28);
    FileTimeToSystemTime(&local_28,&local_20);
    uVar4 = local_res0._4_4_ & 0xffff;
    uVar5 = (uint)local_20.wDayOfWeek;
    if (uVar5 != uVar4) {
      if (uVar5 < uVar4) {
        uVar4 = uVar4 - uVar5;
        iVar6 = uVar4 * 0xc9 + ((int)uVar4 >> 0x1f) * 0x2a69c000;
      }
      else {
        uVar4 = (uVar4 - uVar5) + 7;
        iVar6 = uVar4 * 0xc9 + ((int)uVar4 >> 0x1f) * 0x2a69c000;
      }
      uVar5 = (uint)((ulonglong)uVar4 * 0x2a69c000);
      local_28.dwLowDateTime = uVar5 + local_28.dwLowDateTime;
      local_28.dwHighDateTime =
           iVar6 + (int)((ulonglong)uVar4 * 0x2a69c000 >> 0x20) + local_28.dwHighDateTime +
           (uint)(local_28.dwLowDateTime < uVar5);
    }
    local_res0._4_4_ = (uint)local_res0._4_4_ >> 0x10;
    if (local_res0._4_4_ == 5) {
      bVar1 = local_28.dwLowDateTime < 0x28e44000;
      local_28.dwLowDateTime = local_28.dwLowDateTime + 0xd71bc000;
      local_28.dwHighDateTime = (local_28.dwHighDateTime - 0x580) - (uint)bVar1;
    }
    else if (local_res0._4_4_ != 1) {
      uVar5 = local_res0._4_4_ * 7 - 7;
      uVar4 = (uint)((ulonglong)uVar5 * 0x2a69c000);
      local_28.dwLowDateTime = uVar4 + local_28.dwLowDateTime;
      local_28.dwHighDateTime =
           uVar5 * 0xc9 + ((int)uVar5 >> 0x1f) * 0x2a69c000 +
           (int)((ulonglong)uVar5 * 0x2a69c000 >> 0x20) + local_28.dwHighDateTime +
           (uint)(local_28.dwLowDateTime < uVar4);
    }
  }
  else {
    SystemTimeToFileTime(&local_res0,&local_28);
  }
  return CONCAT44(local_28.dwHighDateTime,local_28.dwLowDateTime);
}



/* 00019934 FUN_00019934 */

/* WARNING: Removing unreachable block (ram,0x00019a98) */
/* WARNING: Removing unreachable block (ram,0x00019a28) */
/* WARNING: Removing unreachable block (ram,0x00019a4c) */
/* WARNING: Removing unreachable block (ram,0x00019ab8) */
/* WARNING: Removing unreachable block (ram,0x00019a6c) */
/* Boundary evidence: original MIPS .pdata 00019934..00019af7. Semantic name remains unreviewed. */

undefined4 FUN_00019934(int param_1,SYSTEMTIME *param_2,undefined4 *param_3)

{
  BOOL BVar1;
  longlong lVar2;
  longlong lVar3;
  _FILETIME local_28;
  
  if (param_1 == 0) {
    return 0;
  }
  if (param_2 == (SYSTEMTIME *)0x0) {
    return 0;
  }
  if (param_3 == (undefined4 *)0x0) {
    return 0;
  }
  if ((*(short *)(param_1 + 0x46) != 0) && (*(short *)(param_1 + 0x9a) != 0)) {
    lVar2 = FUN_00019718(*(undefined4 *)(param_1 + 0x98),*(uint *)(param_1 + 0x9c),
                         *(undefined4 *)(param_1 + 0xa0),*(undefined4 *)(param_1 + 0xa4),
                         param_2->wYear);
    lVar3 = FUN_00019718(*(undefined4 *)(param_1 + 0x44),*(uint *)(param_1 + 0x48),
                         *(undefined4 *)(param_1 + 0x4c),*(undefined4 *)(param_1 + 0x50),
                         param_2->wYear);
    BVar1 = SystemTimeToFileTime(param_2,&local_28);
    if (BVar1 == 0) {
      return 0;
    }
    if (lVar2 < lVar3) {
      if ((lVar2 <= CONCAT44(local_28.dwHighDateTime,local_28.dwLowDateTime)) &&
         (CONCAT44(local_28.dwHighDateTime,local_28.dwLowDateTime) < lVar3)) {
LAB_00019ac4:
        *param_3 = 1;
        return 1;
      }
    }
    else if ((CONCAT44(local_28.dwHighDateTime,local_28.dwLowDateTime) < lVar3) ||
            (lVar2 <= CONCAT44(local_28.dwHighDateTime,local_28.dwLowDateTime))) goto LAB_00019ac4;
  }
  *param_3 = 0;
  return 1;
}



/* 00019af8 FUN_00019af8 */

/* Boundary evidence: original MIPS .pdata 00019af8..00019cd7. Semantic name remains unreviewed. */

int FUN_00019af8(int *param_1)

{
  int iVar1;
  DWORD DVar2;
  BOOL BVar3;
  uint uVar4;
  int iVar5;
  undefined4 local_100;
  undefined4 local_fc;
  FILETIME local_f8;
  uint local_f0 [2];
  _FILETIME local_e8;
  _SYSTEMTIME _Stack_e0;
  _SYSTEMTIME _Stack_d0;
  _TIME_ZONE_INFORMATION _Stack_c0;
  uint local_14;
  
  local_14 = DAT_0001e29c;
  iVar1 = FUN_0001c900(param_1,&local_f8,8,1);
  if (((iVar1 < 0) || (iVar1 = FUN_0001c900(param_1,&local_100,4,1), iVar1 < 0)) ||
     (iVar1 = FUN_0001c900(param_1,local_f0,4,1), iVar1 < 0)) {
    FUN_0001d140(local_14);
  }
  else {
    FUN_0001ca4c((int)param_1);
    local_fc = 0;
    DVar2 = GetTimeZoneInformation(&_Stack_c0);
    if (DVar2 != 0xffffffff) {
      GetSystemTime(&_Stack_d0);
      BVar3 = SystemTimeToFileTime(&_Stack_d0,&local_e8);
      if (BVar3 != 0) {
        if (((int)local_f8.dwHighDateTime < (int)local_e8.dwHighDateTime) ||
           ((local_f8.dwHighDateTime == local_e8.dwHighDateTime &&
            (local_f8.dwLowDateTime <= local_e8.dwLowDateTime)))) {
          iVar1 = local_e8.dwLowDateTime - local_f8.dwLowDateTime;
          iVar5 = (local_e8.dwHighDateTime - local_f8.dwHighDateTime) -
                  (uint)(local_e8.dwLowDateTime < local_f8.dwLowDateTime);
        }
        else {
          iVar1 = local_f8.dwLowDateTime - local_e8.dwLowDateTime;
          iVar5 = (local_f8.dwHighDateTime - local_e8.dwHighDateTime) -
                  (uint)(local_f8.dwLowDateTime < local_e8.dwLowDateTime);
        }
        uVar4 = __ll_div(iVar1,iVar5,10000,0);
        if ((local_f0[0] < uVar4) &&
           (BVar3 = FileTimeToSystemTime(&local_f8,&_Stack_e0), BVar3 != 0)) {
          iVar1 = FUN_00019934((int)&_Stack_c0,&_Stack_e0,&local_100);
          if (iVar1 == 0) {
            local_100 = 0;
          }
          SetDaylightTime(local_100);
          BVar3 = SetSystemTime(&_Stack_e0);
          if (BVar3 != 0) {
            local_fc = 1;
          }
        }
      }
    }
    iVar1 = FUN_0001cd50(param_1,&local_fc,4);
    FUN_0001d140(local_14);
    if (-1 < iVar1) {
      iVar1 = 0;
    }
  }
  return iVar1;
}



/* 00019cd8 FUN_00019cd8 */

/* Boundary evidence: original MIPS .pdata 00019cd8..00019d53. Semantic name remains unreviewed. */

int FUN_00019cd8(int *param_1)

{
  HWND hWnd;
  int iVar1;
  LRESULT local_10 [2];
  
  FUN_0001ca4c((int)param_1);
  hWnd = FindWindowW(L"ReplLog",(LPCWSTR)0x0);
  local_10[0] = -0x7fffbffb;
  if (hWnd != (HWND)0x0) {
    local_10[0] = SendMessageW(hWnd,0x4c9,0,0);
  }
  iVar1 = FUN_0001cd50(param_1,local_10,4);
  if (-1 < iVar1) {
    iVar1 = 0;
  }
  return iVar1;
}



/* 00019d54 FUN_00019d54 */

/* Boundary evidence: original MIPS .pdata 00019d54..00019e63. Semantic name remains unreviewed. */

int FUN_00019d54(int *param_1)

{
  int iVar1;
  size_t sVar2;
  uint local_138;
  BOOL local_134;
  DWORD local_130 [2];
  _OSVERSIONINFOW local_128;
  uint local_14;
  
  local_14 = DAT_0001e29c;
  FUN_0001ca4c((int)param_1);
  local_128.dwOSVersionInfoSize = 0x114;
  local_134 = GetVersionExW(&local_128);
  local_130[0] = GetLastError();
  iVar1 = FUN_0001cd50(param_1,local_130,4);
  if ((iVar1 < 0) || (iVar1 = FUN_0001cd50(param_1,&local_134,4), iVar1 < 0)) {
LAB_00019dbc:
    FUN_0001d140(local_14);
  }
  else {
    if (local_134 != 0) {
      sVar2 = wcslen(local_128.szCSDVersion);
      local_138 = (sVar2 + 0xb) * 2;
      iVar1 = FUN_0001cd50(param_1,&local_138,4);
      if ((iVar1 < 0) || (iVar1 = FUN_0001cd50(param_1,&local_128,local_138), iVar1 < 0))
      goto LAB_00019dbc;
    }
    FUN_0001d140(local_14);
    iVar1 = 0;
  }
  return iVar1;
}



/* 00019e64 FUN_00019e64 */

short * FUN_00019e64(short *param_1)

{
  short *psVar1;
  short *psVar2;
  short sVar3;
  
  sVar3 = *param_1;
  psVar1 = (short *)0x0;
  if (sVar3 != 0) {
    do {
      if ((sVar3 == 0x20) || ((psVar2 = param_1, sVar3 != 0x2e && (psVar2 = psVar1, sVar3 == 0x5c)))
         ) {
        psVar2 = (short *)0x0;
      }
      param_1 = param_1 + 1;
      sVar3 = *param_1;
      psVar1 = psVar2;
    } while (sVar3 != 0);
    if (psVar2 != (short *)0x0) {
      return psVar2;
    }
  }
  return param_1;
}



/* 00019ec4 FUN_00019ec4 */

/* Boundary evidence: original MIPS .pdata 00019ec4..0001a233. Semantic name remains unreviewed. */

int FUN_00019ec4(undefined4 *param_1)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  void *pvVar4;
  HANDLE hObject;
  uint uVar5;
  int local_c8;
  int *local_c4;
  ushort local_c0 [2];
  uint local_bc;
  undefined1 auStack_b8 [4];
  undefined4 local_b4;
  int local_b0;
  DWORD local_ac;
  undefined1 auStack_a8 [4];
  undefined1 auStack_a4 [64];
  undefined4 local_64;
  undefined2 local_5e;
  undefined1 auStack_50 [32];
  uint local_30;
  
  local_30 = DAT_0001e29c;
  pvVar4 = (void *)0x0;
  hObject = (HANDLE)0xffffffff;
  local_b0 = 0;
  local_b4 = 0;
  local_c4 = (int *)0x0;
  iVar1 = FUN_0001c5a0((int *)*param_1,(int *)&local_c4);
  if (iVar1 < 0) goto LAB_0001a1e4;
  iVar1 = (**(code **)(*local_c4 + 0xc))(local_c4,&local_c8,4,auStack_b8);
  if ((-1 < iVar1) &&
     (iVar1 = (**(code **)(*local_c4 + 0xc))(local_c4,auStack_a8,0x78,auStack_b8), -1 < iVar1)) {
    local_c8 = local_c8 + -0x78;
    local_b0 = CeCreateDatabase(auStack_a4,local_64,local_5e,auStack_50);
    if (local_b0 == 0) {
      GetLastError();
    }
    else if (local_c8 == 0) {
LAB_0001a150:
      local_b4 = 1;
    }
    else {
      hObject = (HANDLE)CeOpenDatabase(&local_b0,0,0,1,0);
      if (hObject != (HANDLE)0xffffffff) {
        uVar5 = 0x100;
        pvVar4 = operator_new(0x100);
        if (pvVar4 != (void *)0x0) {
          for (; local_c8 != 0; local_c8 = local_c8 - local_bc) {
            local_bc = 0;
            iVar1 = (**(code **)(*local_c4 + 0xc))(local_c4,&local_bc,4,auStack_b8);
            if (iVar1 < 0) goto LAB_0001a154;
            local_c8 = local_c8 + -4;
            iVar1 = (**(code **)(*local_c4 + 0xc))(local_c4,local_c0,2,auStack_b8);
            if (iVar1 < 0) goto LAB_0001a1a0;
            local_c8 = local_c8 + -2;
            if (uVar5 < local_bc) {
              operator_delete(pvVar4);
              pvVar4 = operator_new(local_bc);
              uVar5 = local_bc;
              if (pvVar4 == (void *)0x0) goto LAB_0001a1a0;
            }
            iVar1 = (**(code **)(*local_c4 + 0xc))(local_c4,pvVar4,local_bc,auStack_b8);
            if (iVar1 < 0) {
              if (pvVar4 != (void *)0x0) {
                operator_delete(pvVar4);
              }
              goto LAB_0001a1a0;
            }
            iVar3 = 0;
            if (local_c0[0] != 0) {
              piVar2 = (int *)((int)pvVar4 + 8);
              do {
                if ((short)piVar2[-2] == 0x1f) {
                  *piVar2 = *piVar2 + (int)pvVar4;
                }
                else if ((short)piVar2[-2] == 0x41) {
                  piVar2[1] = piVar2[1] + (int)pvVar4;
                }
                iVar3 = iVar3 + 1;
                piVar2 = piVar2 + 4;
              } while (iVar3 < (int)(uint)local_c0[0]);
            }
            iVar3 = CeWriteRecordProps(hObject,0,local_c0[0],pvVar4);
            if (iVar3 == 0) goto LAB_0001a1a0;
          }
          goto LAB_0001a150;
        }
      }
    }
  }
LAB_0001a154:
  local_ac = GetLastError();
  iVar1 = FUN_0001cd50((int *)param_1[1],&local_ac,4);
  if ((-1 < iVar1) && (iVar1 = FUN_0001cd50((int *)param_1[1],&local_b4,4), -1 < iVar1)) {
    iVar1 = 0;
  }
LAB_0001a1a0:
  if (hObject != (HANDLE)0xffffffff) {
    CloseHandle(hObject);
  }
  if (pvVar4 != (void *)0x0) {
    operator_delete(pvVar4);
  }
  if (local_c4 != (int *)0x0) {
    (**(code **)(*local_c4 + 8))();
  }
LAB_0001a1e4:
  FUN_0001d140(local_30);
  return iVar1;
}



/* 0001a234 FUN_0001a234 */

/* Boundary evidence: original MIPS .pdata 0001a234..0001a60b. Semantic name remains unreviewed. */

int FUN_0001a234(undefined4 *param_1)

{
  HLOCAL hMem;
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  undefined1 *puVar5;
  int *piVar6;
  int iVar7;
  uint uVar8;
  DWORD DVar9;
  uint uVar10;
  SIZE_T SVar11;
  int iVar12;
  ushort local_40 [2];
  uint local_3c;
  int *local_38;
  HLOCAL local_34;
  undefined1 auStack_30 [4];
  int local_2c;
  
  DVar9 = 0;
  local_34 = (HLOCAL)0x0;
  local_38 = (int *)0x0;
  hMem = LocalAlloc(0x40,DAT_0001e2cc);
  SVar11 = DAT_0001e2cc;
  iVar12 = -0x7ff8fff2;
  iVar7 = iVar12;
  iVar4 = local_2c;
  if (hMem != (HLOCAL)0x0) {
    iVar4 = 0;
    iVar1 = FUN_0001c900((int *)param_1[1],&local_2c,4,1);
    if (iVar1 < 0) {
      return iVar1;
    }
    if (local_2c == 0) {
      iVar7 = -0x7ff8ffa9;
    }
    else {
      FUN_0001ca4c(param_1[1]);
      iVar1 = FUN_0001c5a0((int *)*param_1,(int *)&local_38);
      if (iVar1 < 0) {
        return iVar1;
      }
      iVar1 = CeOpenDatabase(&local_2c,0,0,1,0);
      uVar10 = SVar11;
      if (iVar1 == -1) {
        DVar9 = GetLastError();
LAB_0001a348:
        iVar7 = -0x7fffbffb;
      }
      else {
        do {
          while( true ) {
            local_40[0] = 0;
            local_3c = 0;
            if (local_34 != (HLOCAL)0x0) {
              LocalFree(local_34);
            }
            local_34 = (HLOCAL)0x0;
            iVar3 = CeReadRecordProps(iVar1,1,local_40,0,&local_34,&local_3c);
            if (iVar3 == 0) break;
            iVar3 = 0;
            if (local_40[0] != 0) {
              piVar6 = (int *)((int)local_34 + 8);
              do {
                if ((short)piVar6[-2] == 0x1f) {
                  *piVar6 = *piVar6 - (int)local_34;
                }
                else if ((short)piVar6[-2] == 0x41) {
                  piVar6[1] = piVar6[1] - (int)local_34;
                }
                iVar3 = iVar3 + 1;
                piVar6 = piVar6 + 4;
              } while (iVar3 < (int)(uint)local_40[0]);
            }
            if (SVar11 < 6) {
              iVar3 = (**(code **)(*local_38 + 0x10))(local_38,hMem,iVar4,auStack_30);
              if (iVar3 < 0) goto LAB_0001a348;
              iVar4 = 0;
              SVar11 = uVar10;
            }
            *(uint *)(iVar4 + (int)hMem) = local_3c;
            puVar5 = (undefined1 *)(iVar4 + 4 + (int)hMem);
            *puVar5 = (char)local_40[0];
            puVar5[1] = (char)(local_40[0] >> 8);
            iVar4 = iVar4 + 6;
            uVar8 = SVar11 - 6;
            if (SVar11 - 6 < local_3c) {
              iVar3 = (**(code **)(*local_38 + 0x10))(local_38,hMem,iVar4,auStack_30);
              if (iVar3 < 0) goto LAB_0001a348;
              iVar4 = 0;
              uVar8 = uVar10;
              if (uVar10 < local_3c) {
                LocalFree(hMem);
                hMem = LocalAlloc(0x40,local_3c);
                uVar8 = local_3c;
                uVar10 = local_3c;
                if (hMem == (HLOCAL)0x0) goto LAB_0001a34c;
              }
            }
            memcpy((void *)(iVar4 + (int)hMem),local_34,local_3c);
            SVar11 = uVar8 - local_3c;
            iVar4 = local_3c + iVar4;
          }
          DVar9 = GetLastError();
        } while (DVar9 != 0x103);
        DVar9 = 0x12345678;
        iVar7 = 0;
      }
    }
  }
LAB_0001a34c:
  puVar2 = operator_new(0xc);
  if (puVar2 != (undefined4 *)0x0) {
    *puVar2 = 0;
    puVar2[1] = DVar9;
    puVar2[2] = iVar7;
    if (((hMem != (HLOCAL)0x0) &&
        (iVar12 = (**(code **)(*local_38 + 0x10))(local_38,hMem,iVar4,auStack_30), iVar12 < 0)) ||
       (iVar4 = (**(code **)(*local_38 + 0x10))(local_38,puVar2,0xc,auStack_30), iVar12 = iVar7,
       iVar4 < 0)) {
      iVar12 = -0x7fffbffb;
    }
    if (local_38 != (int *)0x0) {
      (**(code **)(*local_38 + 8))();
      local_38 = (int *)0x0;
    }
    if (hMem != (HLOCAL)0x0) {
      LocalFree(hMem);
    }
    operator_delete(puVar2);
  }
  return iVar12;
}



/* 0001a60c FUN_0001a60c */

/* WARNING: Removing unreachable block (ram,0x0001a9c0) */
/* WARNING: Removing unreachable block (ram,0x0001a9e4) */
/* Boundary evidence: original MIPS .pdata 0001a60c..0001aad7. Semantic name remains unreviewed. */

int FUN_0001a60c(undefined4 *param_1)

{
  int iVar1;
  code *pcVar2;
  void *pvVar3;
  HMODULE hLibModule;
  int *local_58;
  DWORD local_54;
  int local_50;
  uint local_4c;
  DWORD local_48;
  uint local_44;
  HLOCAL local_40;
  void *local_3c;
  LPCWSTR local_38;
  void *local_34;
  HMODULE local_30;
  code *local_2c;
  
  local_38 = (LPCWSTR)0x0;
  local_3c = (void *)0x0;
  local_4c = 0;
  pvVar3 = (void *)0x0;
  local_40 = (HLOCAL)0x0;
  hLibModule = (HMODULE)0x0;
  local_58 = (int *)0x0;
  local_54 = 0;
  iVar1 = FUN_0001c900((int *)param_1[1],&local_2c,4,1);
  if (iVar1 < 0) {
    return iVar1;
  }
  iVar1 = FUN_0001cc40((int *)param_1[1],&local_38);
  if (((iVar1 < 0) || (iVar1 = FUN_0001cc40((int *)param_1[1],&local_3c), iVar1 < 0)) ||
     (iVar1 = FUN_0001c900((int *)param_1[1],&local_44,4,1), iVar1 < 0)) goto LAB_0001a70c;
  pvVar3 = operator_new(local_44);
  local_34 = pvVar3;
  if (pvVar3 == (void *)0x0) {
    iVar1 = -0x7ff8fff2;
    goto LAB_0001a70c;
  }
  iVar1 = FUN_0001c900((int *)param_1[1],pvVar3,local_44,1);
  if (((iVar1 < 0) || (iVar1 = FUN_0001c900((int *)param_1[1],&local_50,4,1), iVar1 < 0)) ||
     ((FUN_0001ca4c(param_1[1]), local_50 != 0 &&
      (iVar1 = FUN_0001c5a0((int *)*param_1,(int *)&local_58), iVar1 < 0)))) goto LAB_0001a70c;
  hLibModule = LoadLibraryW(local_38);
  local_30 = hLibModule;
  if (hLibModule == (HMODULE)0x0) {
    local_54 = 2;
    local_48 = 2;
    pcVar2 = local_2c;
joined_r0x0001a8a0:
    if (local_50 == 0) goto LAB_0001a70c;
  }
  else {
    pcVar2 = (code *)GetProcAddressW(hLibModule,local_3c);
    if (pcVar2 == (code *)0x0) {
      local_54 = 0x78;
      local_48 = 0x78;
      goto joined_r0x0001a8a0;
    }
  }
  if (local_50 != 0) {
    iVar1 = (**(code **)(*local_58 + 0x10))(local_58,&local_54,4,&local_4c);
    if ((iVar1 < 0) || (local_4c != 4)) {
      (**(code **)(*local_58 + 8))();
      local_58 = (int *)0x0;
      iVar1 = -0x7fffbffb;
      goto LAB_0001a70c;
    }
    if (local_54 != 0) {
      local_48 = local_54;
      SetLastError(local_54);
      (**(code **)(*local_58 + 8))();
      local_58 = (int *)0x0;
      goto LAB_0001a70c;
    }
  }
  SetLastError(0);
  local_48 = (*pcVar2)(local_44,pvVar3,&local_4c,&local_40,local_58);
  if (local_54 == 0) {
    local_54 = GetLastError();
  }
  if (local_50 == 0) {
    iVar1 = FUN_0001cd50((int *)param_1[1],&local_54,4);
    if ((((-1 < iVar1) && (iVar1 = FUN_0001cd50((int *)param_1[1],&local_48,4), -1 < iVar1)) &&
        (iVar1 = FUN_0001cd50((int *)param_1[1],&local_4c,4), -1 < iVar1)) &&
       ((local_4c != 0 && (local_40 != (void *)0x0)))) {
      iVar1 = FUN_0001cd50((int *)param_1[1],local_40,local_4c);
    }
  }
  else {
    iVar1 = 0x9d;
  }
LAB_0001a70c:
  if (local_40 != (HLOCAL)0x0) {
    LocalFree(local_40);
  }
  if (hLibModule != (HMODULE)0x0) {
    FreeLibrary(hLibModule);
  }
  if (pvVar3 != (void *)0x0) {
    operator_delete(pvVar3);
  }
  if (local_3c != (void *)0x0) {
    operator_delete(local_3c);
  }
  if (local_38 != (LPCWSTR)0x0) {
    operator_delete(local_38);
  }
  return iVar1;
}



/* 0001aad8 FUN_0001aad8 */

/* Boundary evidence: original MIPS .pdata 0001aad8..0001aae3. Semantic name remains unreviewed. */

undefined4 FUN_0001aad8(void)

{
  return 1;
}



/* 0001aae4 FUN_0001aae4 */

/* Boundary evidence: original MIPS .pdata 0001aae4..0001ad07. Semantic name remains unreviewed. */

int FUN_0001aae4(undefined4 *param_1)

{
  HLOCAL lpBuffer;
  int iVar1;
  HANDLE hFile;
  BOOL BVar2;
  int iVar3;
  DWORD local_30;
  LPCWSTR local_2c;
  int *local_28;
  DWORD local_24;
  DWORD local_20 [2];
  
  iVar3 = 0;
  local_2c = (LPCWSTR)0x0;
  local_30 = 0;
  local_28 = (int *)0x0;
  lpBuffer = LocalAlloc(0x40,DAT_0001e2cc);
  if (lpBuffer == (HLOCAL)0x0) {
    iVar3 = -0x7ff8fff2;
  }
  else {
    iVar1 = FUN_0001cc40((int *)param_1[1],&local_2c);
    if (iVar1 < 0) {
      return iVar1;
    }
    if ((local_2c == (LPCWSTR)0x0) || (*local_2c == L'\0')) {
      iVar3 = -0x7ff8ffa9;
    }
    else {
      FUN_0001ca4c(param_1[1]);
      iVar1 = FUN_0001c5a0((int *)*param_1,(int *)&local_28);
      if (iVar1 < 0) {
        return iVar1;
      }
      hFile = CreateFileW(local_2c,0x80000000,1,(LPSECURITY_ATTRIBUTES)0x0,3,0,(HANDLE)0x0);
      if (hFile != (HANDLE)0xffffffff) {
        local_30 = GetFileSize(hFile,(LPDWORD)0x0);
        if (local_30 == 0xffffffff) {
          GetLastError();
        }
        else {
          iVar1 = (**(code **)(*local_28 + 0x10))(local_28,&local_30,4,&local_24);
          if ((-1 < iVar1) && (local_24 == 4)) {
            local_24 = 4;
            for (; local_30 != 0; local_30 = local_30 - local_24) {
              BVar2 = ReadFile(hFile,lpBuffer,DAT_0001e2cc,local_20,(LPOVERLAPPED)0x0);
              if (((BVar2 == 0) ||
                  (iVar1 = (**(code **)(*local_28 + 0x10))(local_28,lpBuffer,local_20[0],&local_24),
                  iVar1 < 0)) || (local_20[0] != local_24)) goto LAB_0001acb4;
            }
            iVar3 = 0;
          }
        }
      }
    }
  }
LAB_0001acb4:
  if (local_2c != (LPCWSTR)0x0) {
    operator_delete(local_2c);
  }
  if (local_28 != (int *)0x0) {
    (**(code **)(*local_28 + 8))();
  }
  return iVar3;
}



/* 0001ad08 FUN_0001ad08 */

/* Boundary evidence: original MIPS .pdata 0001ad08..0001ae3f. Semantic name remains unreviewed. */

int FUN_0001ad08(int *param_1)

{
  int iVar1;
  HMODULE pHVar2;
  code *pcVar3;
  void *local_20;
  undefined4 local_1c;
  DWORD local_18;
  undefined4 local_14;
  
  local_20 = (void *)0x0;
  iVar1 = FUN_0001cb2c(param_1,(int *)&local_20,0);
  if ((-1 < iVar1) && (iVar1 = FUN_0001c900(param_1,&local_1c,4,1), -1 < iVar1)) {
    FUN_0001ca4c((int)param_1);
    pHVar2 = LoadLibraryW(L"coredll.dll");
    if ((pHVar2 == (HMODULE)0x0) ||
       (pcVar3 = (code *)GetProcAddressW(pHVar2,L"GetSystemPowerStatusEx"), pcVar3 == (code *)0x0))
    {
      iVar1 = -0x7fffbffb;
    }
    else {
      local_14 = (*pcVar3)(local_20,local_1c);
      local_18 = GetLastError();
      iVar1 = FUN_0001cd50(param_1,&local_18,4);
      if ((-1 < iVar1) && (iVar1 = FUN_0001cd50(param_1,&local_14,4), -1 < iVar1)) {
        iVar1 = FUN_0001cf9c(param_1,local_20,0x18,1);
      }
    }
  }
  if (local_20 != (void *)0x0) {
    operator_delete(local_20);
  }
  return iVar1;
}



/* 0001ae40 FUN_0001ae40 */

/* Boundary evidence: original MIPS .pdata 0001ae40..0001b0ab. Semantic name remains unreviewed. */

int FUN_0001ae40(int *param_1)

{
  int iVar1;
  code *pcVar2;
  code *pcVar3;
  code *pcVar4;
  DWORD local_240;
  undefined4 local_23c;
  size_t local_238;
  int *local_234;
  uint local_230;
  undefined4 local_22c;
  wchar_t local_228 [260];
  uint local_20;
  
  local_20 = DAT_0001e29c;
  local_230 = 0;
  local_240 = 0;
  iVar1 = FUN_0001c900(param_1,&local_22c,4,1);
  if ((-1 < iVar1) && (iVar1 = FUN_0001c900(param_1,&local_230,4,1), -1 < iVar1)) {
    FUN_0001ca4c((int)param_1);
    local_238 = 0;
    local_23c = 0;
    FUN_00016754();
    if (DAT_0001e2e0 == -1) {
      wcscpy(local_228,L"\\");
      local_240 = 0;
    }
    else {
      pcVar2 = (code *)GetProcAddressW(DAT_0001e2e0,L"SHGetSpecialFolderLocation");
      if (((pcVar2 == (code *)0x0) ||
          (pcVar3 = (code *)GetProcAddressW(DAT_0001e2e0,L"SHGetPathFromIDList"),
          pcVar3 == (code *)0x0)) ||
         (pcVar4 = (code *)GetProcAddressW(DAT_0001e2e0,L"SHGetMalloc"), pcVar4 == (code *)0x0)) {
        FUN_0001d140(local_20);
        return -0x7fffbffb;
      }
      iVar1 = (*pcVar2)(0,local_22c,&local_23c);
      if (-1 < iVar1) {
        local_228[0] = L'\0';
        iVar1 = (*pcVar3)(local_23c,local_228);
        if (iVar1 != 0) {
          local_238 = wcslen(local_228);
        }
        iVar1 = (*pcVar4)(&local_234);
        if (-1 < iVar1) {
          (**(code **)(*local_234 + 0x14))(local_234,local_23c);
          (**(code **)(*local_234 + 8))();
        }
      }
      local_240 = GetLastError();
    }
    iVar1 = FUN_0001cd50(param_1,&local_240,4);
    if (((-1 < iVar1) && (iVar1 = FUN_0001cd50(param_1,&local_238,4), -1 < iVar1)) &&
       ((local_238 == 0 ||
        ((local_230 <= local_238 ||
         (iVar1 = FUN_0001cd50(param_1,local_228,(local_238 + 1) * 2), -1 < iVar1)))))) {
      FUN_0001d140(local_20);
      return 0;
    }
  }
  FUN_0001d140(local_20);
  return iVar1;
}



/* 0001b0ac FUN_0001b0ac */

/* Boundary evidence: original MIPS .pdata 0001b0ac..0001b1cf. Semantic name remains unreviewed. */

int FUN_0001b0ac(int *param_1)

{
  HMODULE hLibModule;
  code *pcVar1;
  int iVar2;
  undefined4 local_18;
  DWORD local_14;
  
  local_18 = 0;
  FUN_0001ca4c((int)param_1);
  hLibModule = LoadLibraryW(L"system.cpl");
  if (((hLibModule != (HMODULE)0x0) ||
      (hLibModule = LoadLibraryW(L"systemg.cpl"), hLibModule != (HMODULE)0x0)) ||
     (hLibModule = LoadLibraryW(L"cplmain.cpl"), hLibModule != (HMODULE)0x0)) {
    pcVar1 = (code *)GetProcAddressW(hLibModule,L"KillAllApps");
    if (pcVar1 != (code *)0x0) {
      local_18 = (*pcVar1)();
      FreeLibrary(hLibModule);
      local_14 = GetLastError();
      iVar2 = FUN_0001cd50(param_1,&local_14,4);
      if (iVar2 < 0) {
        return iVar2;
      }
      iVar2 = FUN_0001cd50(param_1,&local_18,4);
      if (iVar2 < 0) {
        return iVar2;
      }
      return 0;
    }
    FreeLibrary(hLibModule);
  }
  return -0x7fffbffb;
}



/* 0001b1d0 FUN_0001b1d0 */

/* Boundary evidence: original MIPS .pdata 0001b1d0..0001b28f. Semantic name remains unreviewed. */

undefined4 FUN_0001b1d0(undefined4 param_1)

{
  code *pcVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  
  uVar3 = 0;
  FUN_00016754();
  if (DAT_0001e2e0 != -1) {
    pcVar1 = (code *)GetProcAddressW(DAT_0001e2e0,L"SHRemoveFontResource");
    if ((pcVar1 == (code *)0x0) || (iVar2 = (*pcVar1)(param_1), iVar2 == 0)) {
      memset(&local_34,0,0x20);
      local_38 = 0x24;
      uVar3 = 1;
      local_30 = 1;
      local_34 = 4;
      local_2c = param_1;
      (*(code *)&SUB_fffe67a6)(&local_38);
    }
    else {
      uVar3 = 1;
    }
  }
  return uVar3;
}



/* 0001b290 FUN_0001b290 */

/* Boundary evidence: original MIPS .pdata 0001b290..0001b473. Semantic name remains unreviewed. */

undefined4 FUN_0001b290(wchar_t *param_1)

{
  wchar_t wVar1;
  size_t _MaxCount;
  int iVar2;
  wchar_t *pwVar3;
  LPCWSTR lpString1;
  undefined4 uVar4;
  WCHAR aWStack_90 [8];
  WCHAR aWStack_80 [8];
  WCHAR aWStack_70 [8];
  WCHAR aWStack_60 [8];
  WCHAR aWStack_50 [8];
  wchar_t awStack_40 [16];
  uint local_20;
  
  local_20 = DAT_0001e29c;
  memcpy(awStack_40,L"\\Windows\\Fonts\\",0x20);
  memcpy(aWStack_50,L".fnt",10);
  memcpy(aWStack_70,L".fon",10);
  memcpy(aWStack_90,L".ttf",10);
  memcpy(aWStack_60,L".ttc",10);
  memcpy(aWStack_80,L".tte",10);
  uVar4 = 0;
  _MaxCount = wcslen(awStack_40);
  if ((param_1 != (wchar_t *)0x0) && (iVar2 = _wcsnicmp(param_1,awStack_40,_MaxCount), iVar2 == 0))
  {
    pwVar3 = param_1 + _MaxCount;
    iVar2 = 0;
    wVar1 = *pwVar3;
    while ((wVar1 != L'\0' && (wVar1 != L'\\'))) {
      iVar2 = iVar2 + 1;
      wVar1 = pwVar3[iVar2];
    }
    if ((pwVar3[iVar2] == L'\0') && (4 < iVar2)) {
      lpString1 = pwVar3 + iVar2 + -4;
      iVar2 = lstrcmpiW(lpString1,aWStack_50);
      if (((iVar2 == 0) ||
          (((iVar2 = lstrcmpiW(lpString1,aWStack_70), iVar2 == 0 ||
            (iVar2 = lstrcmpiW(lpString1,aWStack_90), iVar2 == 0)) ||
           (iVar2 = lstrcmpiW(lpString1,aWStack_80), iVar2 == 0)))) ||
         (iVar2 = lstrcmpiW(lpString1,aWStack_60), iVar2 == 0)) {
        uVar4 = FUN_0001b1d0(param_1);
      }
    }
  }
  FUN_0001d140(local_20);
  return uVar4;
}



/* 0001b474 FUN_0001b474 */

/* Boundary evidence: original MIPS .pdata 0001b474..0001b52b. Semantic name remains unreviewed. */

int FUN_0001b474(int *param_1)

{
  int iVar1;
  wchar_t *local_18;
  DWORD local_14;
  BOOL local_10 [2];
  
  local_18 = (wchar_t *)0x0;
  iVar1 = FUN_0001cb2c(param_1,(int *)&local_18,0);
  if (-1 < iVar1) {
    FUN_0001ca4c((int)param_1);
    FUN_0001b290(local_18);
    local_10[0] = DeleteFileW(local_18);
    if (local_18 != (LPCWSTR)0x0) {
      operator_delete(local_18);
    }
    local_14 = GetLastError();
    iVar1 = FUN_0001cd50(param_1,&local_14,4);
    if ((-1 < iVar1) && (iVar1 = FUN_0001cd50(param_1,local_10,4), -1 < iVar1)) {
      iVar1 = 0;
    }
  }
  return iVar1;
}



/* 0001b52c FUN_0001b52c */

/* Boundary evidence: original MIPS .pdata 0001b52c..0001b653. Semantic name remains unreviewed. */

int FUN_0001b52c(int *param_1,undefined4 *param_2)

{
  int iVar1;
  void *local_30;
  int local_2c;
  undefined4 local_28;
  DWORD local_24;
  undefined4 auStack_20 [4];
  
  local_30 = (void *)0x0;
  iVar1 = FUN_0001cb2c(param_1,(int *)&local_30,0);
  if ((-1 < iVar1) && (iVar1 = FUN_0001c900(param_1,&local_28,4,1), -1 < iVar1)) {
    FUN_0001ca4c((int)param_1);
    local_2c = CeMountDBVol(auStack_20,local_30,local_28);
    if (local_30 != (void *)0x0) {
      operator_delete(local_30);
    }
    if ((local_2c == 0) || (iVar1 = FUN_00013190(param_2,5,auStack_20), iVar1 != 0)) {
      local_24 = GetLastError();
      iVar1 = FUN_0001cd50(param_1,&local_24,4);
      if (((-1 < iVar1) && (iVar1 = FUN_0001cd50(param_1,&local_2c,4), -1 < iVar1)) &&
         ((local_2c == 0 || (iVar1 = FUN_0001cd50(param_1,auStack_20,0x10), -1 < iVar1)))) {
        iVar1 = 0;
      }
    }
    else {
      iVar1 = 0xe;
    }
  }
  return iVar1;
}



/* 0001b654 FUN_0001b654 */

/* Boundary evidence: original MIPS .pdata 0001b654..0001b71f. Semantic name remains unreviewed. */

int FUN_0001b654(int *param_1,int *param_2)

{
  int iVar1;
  void *local_20;
  DWORD local_1c;
  int local_18 [2];
  
  local_20 = (void *)0x0;
  iVar1 = FUN_0001cb2c(param_1,(int *)&local_20,0);
  if (-1 < iVar1) {
    FUN_0001ca4c((int)param_1);
    local_18[0] = CeUnmountDBVol(local_20);
    if (local_18[0] != 0) {
      FUN_00013220(param_2,5,local_20);
    }
    if (local_20 != (void *)0x0) {
      operator_delete(local_20);
    }
    local_1c = GetLastError();
    iVar1 = FUN_0001cd50(param_1,&local_1c,4);
    if ((-1 < iVar1) && (iVar1 = FUN_0001cd50(param_1,local_18,4), -1 < iVar1)) {
      iVar1 = 0;
    }
  }
  return iVar1;
}



/* 0001b720 FUN_0001b720 */

/* Boundary evidence: original MIPS .pdata 0001b720..0001b7c7. Semantic name remains unreviewed. */

int FUN_0001b720(int *param_1)

{
  int iVar1;
  void *local_18;
  DWORD local_14;
  undefined4 local_10 [2];
  
  local_18 = (void *)0x0;
  iVar1 = FUN_0001cb2c(param_1,(int *)&local_18,0);
  if (-1 < iVar1) {
    FUN_0001ca4c((int)param_1);
    local_10[0] = CeFlushDBVol(local_18);
    if (local_18 != (void *)0x0) {
      operator_delete(local_18);
    }
    local_14 = GetLastError();
    iVar1 = FUN_0001cd50(param_1,&local_14,4);
    if ((-1 < iVar1) && (iVar1 = FUN_0001cd50(param_1,local_10,4), -1 < iVar1)) {
      iVar1 = 0;
    }
  }
  return iVar1;
}



/* 0001b7c8 FUN_0001b7c8 */

/* Boundary evidence: original MIPS .pdata 0001b7c8..0001b923. Semantic name remains unreviewed. */

int FUN_0001b7c8(int *param_1)

{
  int iVar1;
  wchar_t *_Str;
  size_t sVar2;
  uint uVar3;
  int local_30;
  int local_2c;
  DWORD local_28 [2];
  undefined1 auStack_20 [16];
  
  iVar1 = FUN_0001c900(param_1,auStack_20,0x10,1);
  if ((-1 < iVar1) && (iVar1 = FUN_0001c900(param_1,&local_30,4,1), -1 < iVar1)) {
    FUN_0001ca4c((int)param_1);
    if (local_30 + 1U < 0x80000000) {
      uVar3 = (local_30 + 1U) * 2;
    }
    else {
      uVar3 = 0xffffffff;
    }
    _Str = operator_new(uVar3);
    if (_Str == (wchar_t *)0x0) {
      iVar1 = -0x7ff8fff2;
    }
    else {
      local_2c = CeEnumDBVolumes(auStack_20,_Str,local_30);
      local_28[0] = GetLastError();
      iVar1 = FUN_0001cd50(param_1,local_28,4);
      if ((-1 < iVar1) && (iVar1 = FUN_0001cd50(param_1,&local_2c,4), -1 < iVar1)) {
        if (local_2c != 0) {
          iVar1 = FUN_0001cd50(param_1,auStack_20,0x10);
          if (iVar1 < 0) {
            return iVar1;
          }
          sVar2 = wcslen(_Str);
          iVar1 = FUN_0001cf9c(param_1,_Str,(sVar2 + 1) * 2,1);
          if (iVar1 < 0) {
            return iVar1;
          }
        }
        operator_delete(_Str);
        iVar1 = 0;
      }
    }
  }
  return iVar1;
}



/* 0001b924 FUN_0001b924 */

/* Boundary evidence: original MIPS .pdata 0001b924..0001ba27. Semantic name remains unreviewed. */

int FUN_0001b924(int *param_1)

{
  int iVar1;
  DWORD *local_38;
  DWORD local_34;
  BOOL local_30 [2];
  ULARGE_INTEGER local_28;
  ULARGE_INTEGER local_20;
  ULARGE_INTEGER UStack_18;
  
  local_38 = (DWORD *)0x0;
  iVar1 = FUN_0001cb2c(param_1,(int *)&local_38,0);
  if (-1 < iVar1) {
    FUN_0001ca4c((int)param_1);
    local_30[0] = GetDiskFreeSpaceExW(L"\\",&local_20,&local_28,&UStack_18);
    if (local_30[0] != 0) {
      *local_38 = local_28.s.LowPart;
      local_38[1] = local_20.s.LowPart;
    }
    local_34 = GetLastError();
    iVar1 = FUN_0001cd50(param_1,&local_34,4);
    if ((-1 < iVar1) && (iVar1 = FUN_0001cd50(param_1,local_30,4), -1 < iVar1)) {
      iVar1 = FUN_0001cf9c(param_1,local_38,8,1);
    }
  }
  if (local_38 != (DWORD *)0x0) {
    operator_delete(local_38);
  }
  return iVar1;
}



/* 0001ba28 FUN_0001ba28 */

/* Boundary evidence: original MIPS .pdata 0001ba28..0001bad3. Semantic name remains unreviewed. */

int FUN_0001ba28(int *param_1)

{
  int iVar1;
  int local_18;
  DWORD local_14;
  int local_10 [2];
  
  local_14 = 0;
  local_18 = 0;
  if (param_1 == (int *)0x0) {
    iVar1 = -0x7ff8ffa9;
  }
  else {
    iVar1 = FUN_0001c900(param_1,&local_18,4,1);
    if (-1 < iVar1) {
      FUN_0001ca4c((int)param_1);
      local_10[0] = FUN_000166f0(local_18);
      local_14 = GetLastError();
      iVar1 = FUN_0001cd50(param_1,&local_14,4);
      if ((-1 < iVar1) && (iVar1 = FUN_0001cd50(param_1,local_10,4), -1 < iVar1)) {
        iVar1 = 0;
      }
    }
  }
  return iVar1;
}



/* 0001bad4 FUN_0001bad4 */

/* Boundary evidence: original MIPS .pdata 0001bad4..0001bb5f. Semantic name remains unreviewed. */

undefined4 FUN_0001bad4(short *param_1)

{
  wchar_t *_Str1;
  int iVar1;
  undefined4 uVar2;
  
  if (((param_1 == (short *)0x0) || (_Str1 = FUN_00019e64(param_1), _Str1 == (wchar_t *)0x0)) ||
     ((iVar1 = _wcsicmp(_Str1,L".DLL"), iVar1 != 0 &&
      ((iVar1 = _wcsicmp(_Str1,L".CPL"), iVar1 != 0 && (iVar1 = _wcsicmp(_Str1,L".DRV"), iVar1 != 0)
       ))))) {
    uVar2 = 0;
  }
  else {
    uVar2 = 1;
  }
  return uVar2;
}



/* 0001bb60 FUN_0001bb60 */

/* Boundary evidence: original MIPS .pdata 0001bb60..0001bbe7. Semantic name remains unreviewed. */

undefined4 FUN_0001bb60(uint *param_1,uint param_2)

{
  undefined4 uVar1;
  int iVar2;
  
  if (((((param_2 & 0x4000) == 0) || ((*param_1 & 0x10) != 0)) &&
      (((param_2 & 0x8000) == 0 || ((*param_1 & 0x2006) != 0x2006)))) &&
     (((param_2 & 0x2000) == 0 ||
      (((*param_1 & 2) == 0 && (iVar2 = FUN_0001bad4((short *)(param_1 + 10)), iVar2 == 0)))))) {
    uVar1 = 0;
  }
  else {
    uVar1 = 1;
  }
  return uVar1;
}



/* 0001bbe8 FUN_0001bbe8 */

/* Boundary evidence: original MIPS .pdata 0001bbe8..0001c09b. Semantic name remains unreviewed. */

int FUN_0001bbe8(int *param_1)

{
  bool bVar1;
  bool bVar2;
  LPCWSTR _Source;
  int iVar3;
  HANDLE hFindFile;
  size_t sVar4;
  BOOL BVar5;
  uint *puVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  size_t _Count;
  _WIN32_FIND_DATAW *p_Var10;
  uint local_8b0;
  int local_8ac;
  uint local_8a8;
  LPCWSTR local_8a4;
  DWORD local_8a0 [2];
  uint local_898 [8];
  _WIN32_FIND_DATAW local_878;
  wchar_t awStack_440 [260];
  wchar_t awStack_238 [260];
  uint local_30;
  
  local_30 = DAT_0001e29c;
  _Count = 0;
  local_8a4 = (LPCWSTR)0x0;
  bVar1 = false;
  local_8ac = 0;
  local_8b0 = 0;
  iVar3 = FUN_0001cc40(param_1,&local_8a4);
  if (iVar3 < 0) goto LAB_0001c064;
  iVar3 = FUN_0001c900(param_1,&local_8a8,4,1);
  if (-1 < iVar3) {
    FUN_0001ca4c((int)param_1);
    hFindFile = FindFirstFileW(local_8a4,&local_878);
    _Source = local_8a4;
    uVar7 = local_8a8;
    if (hFindFile == (HANDLE)0xffffffff) {
      iVar3 = FUN_0001cd50(param_1,&local_8ac,4);
      if (iVar3 < 0) goto LAB_0001c050;
LAB_0001c02c:
      iVar3 = 0;
    }
    else {
      local_898[1] = 8;
      local_898[2] = 8;
      local_898[3] = 8;
      local_898[0] = 4;
      local_898[4] = 4;
      local_898[5] = 4;
      local_898[6] = 4;
      if ((local_8a8 & 0x10000) != 0) {
        _Count = wcslen(local_8a4);
        iVar3 = wcscmp(_Source + (_Count - 2),L"\\*");
        if (iVar3 == 0) {
          _Count = _Count - 1;
        }
        wcsncpy(awStack_440,_Source,_Count);
      }
      do {
        bVar2 = false;
        iVar3 = FUN_0001bb60(&local_878.dwFileAttributes,uVar7);
        if (iVar3 == 0) {
          local_8ac = local_8ac + 1;
          if ((local_8a8 & 0x80) == 0) {
            local_898[7] = 0;
          }
          else {
            sVar4 = wcslen((wchar_t *)&local_878.dwReserved1);
            local_8b0 = sVar4 + 1;
            iVar3 = FUN_0001cd50(param_1,&local_8b0,4);
            if (iVar3 < 0) goto LAB_0001c030;
            local_898[7] = local_8b0 << 1;
          }
          p_Var10 = &local_878;
          uVar9 = 0;
          uVar7 = local_8b0;
          uVar8 = local_8a8;
          do {
            if ((1 << (uVar9 & 0x1f) & uVar8) != 0) {
              if (uVar9 == 0) {
                if ((local_878.dwFileAttributes & 0x10) == 0) {
                  if ((uVar8 & 0x10000) != 0) {
                    if (uVar7 == 0) {
                      sVar4 = wcslen((wchar_t *)&local_878.dwReserved1);
                      uVar7 = sVar4 + 1;
                      local_8b0 = uVar7;
                    }
                    if ((5 < uVar7) &&
                       (iVar3 = _wcsicmp(local_878.cFileName + (uVar7 - 7),L".lnk"), iVar3 == 0)) {
                      bVar1 = true;
                      uVar7 = 0x20000;
                      goto LAB_0001be7c;
                    }
                  }
                }
                else if ((((uVar8 & 0x1000) != 0) && (!bVar2)) &&
                        (iVar3 = FUN_000191e0(local_8a4,(wchar_t *)&local_878.dwReserved1),
                        iVar3 != 0)) {
                  bVar2 = true;
                  uVar7 = 0x10000;
LAB_0001be7c:
                  local_878.dwFileAttributes = local_878.dwFileAttributes | uVar7;
                }
              }
              iVar3 = FUN_0001cd50(param_1,p_Var10,local_898[uVar9]);
              uVar7 = local_8b0;
              uVar8 = local_8a8;
              if (iVar3 < 0) goto LAB_0001c030;
            }
            puVar6 = local_898 + uVar9;
            uVar9 = uVar9 + 1;
            p_Var10 = (_WIN32_FIND_DATAW *)((int)p_Var10->cFileName + (*puVar6 - 0x2c));
          } while (uVar9 < 8);
          if (bVar1) {
            local_8a0[0] = 0;
            local_8b0 = 0;
            awStack_440[_Count] = L'\0';
            wcscat(awStack_440,(wchar_t *)&local_878.dwReserved1);
            iVar3 = SHGetShortcutTarget(awStack_440,local_878.cFileName + 0x102,0x104);
            if (iVar3 == 0) {
              GetLastError();
            }
            else {
              sVar4 = wcslen(local_878.cFileName + 0x102);
              local_8b0 = sVar4 + 1;
              if (1 < local_8b0) {
                FUN_00017400(local_878.cFileName + 0x102,awStack_238,(undefined4 *)0x0,0);
                local_8a0[0] = GetFileAttributesW(awStack_238);
              }
              local_8b0 = local_8b0 << 1;
            }
            iVar3 = FUN_0001cd50(param_1,&local_8b0,4);
            if (((iVar3 < 0) ||
                ((local_8b0 != 0 &&
                 (iVar3 = FUN_0001cd50(param_1,local_878.cFileName + 0x102,local_8b0), iVar3 < 0))))
               || (iVar3 = FUN_0001cd50(param_1,local_8a0,4), iVar3 < 0)) goto LAB_0001c030;
            local_8ac = local_8ac + 1;
            bVar1 = false;
          }
        }
        BVar5 = FindNextFileW(hFindFile,&local_878);
        uVar7 = local_8a8;
      } while (BVar5 != 0);
      iVar3 = FUN_0001ce7c(param_1,&local_8ac,4);
      if (-1 < iVar3) goto LAB_0001c02c;
    }
LAB_0001c030:
    if (hFindFile != (HANDLE)0xffffffff) {
      FindClose(hFindFile);
    }
  }
LAB_0001c050:
  if (local_8a4 != (LPCWSTR)0x0) {
    operator_delete(local_8a4);
  }
LAB_0001c064:
  FUN_0001d140(local_30);
  return iVar3;
}



/* 0001c09c FUN_0001c09c */

/* Boundary evidence: original MIPS .pdata 0001c09c..0001c0d7. Semantic name remains unreviewed. */

void FUN_0001c09c(undefined4 *param_1)

{
  *param_1 = &PTR_LAB_0001159c;
  if (param_1[0x45] != 0xffffffff) {
    closesocket(param_1[0x45]);
  }
  return;
}



/* 0001c0d8 FUN_0001c0d8 */

/* Boundary evidence: original MIPS .pdata 0001c0d8..0001c0f3. Semantic name remains unreviewed. */

void FUN_0001c0d8(int param_1)

{
  InterlockedIncrement((LONG *)(param_1 + 4));
  return;
}



/* 0001c100 FUN_0001c100 */

/* Boundary evidence: original MIPS .pdata 0001c100..0001c24f. Semantic name remains unreviewed. */

DWORD FUN_0001c100(int param_1,int *param_2)

{
  uint *buf;
  uint uVar1;
  DWORD DVar2;
  uint len;
  uint local_20 [2];
  
  local_20[0] = 0;
  if (param_2 == (int *)0x0) {
    DVar2 = 0x80070057;
  }
  else if (*(int *)(param_1 + 0x114) == -1) {
    DVar2 = 0x80004005;
  }
  else {
    DVar2 = FUN_0001ca24((int)param_2,local_20);
    if (-1 < (int)DVar2) {
      if (local_20[0] == 0) {
        DVar2 = 0;
      }
      else {
        len = local_20[0] + 4;
        buf = operator_new(len);
        if (buf == (uint *)0x0) {
          DVar2 = 0x8007000e;
        }
        else {
          *buf = local_20[0];
          DVar2 = FUN_0001c900(param_2,buf + 1,local_20[0],1);
          if (-1 < (int)DVar2) {
            uVar1 = send(*(SOCKET *)(param_1 + 0x114),(char *)buf,len,0);
            if (uVar1 == len) {
              DVar2 = 0;
            }
            else {
              DVar2 = GetLastError();
              if (0 < (int)DVar2) {
                DVar2 = DVar2 & 0xffff | 0x80070000;
              }
            }
          }
        }
        if (buf != (uint *)0x0) {
          operator_delete(buf);
        }
      }
    }
  }
  return DVar2;
}



/* 0001c250 FUN_0001c250 */

/* Boundary evidence: original MIPS .pdata 0001c250..0001c36b. Semantic name remains unreviewed. */

uint FUN_0001c250(int param_1,int param_2,uint param_3,uint *param_4)

{
  int iVar1;
  DWORD DVar2;
  uint uVar3;
  
  uVar3 = 0;
  if (param_3 != 0) {
    if (param_2 == 0) {
      return 0x80070057;
    }
    if (*(int *)(param_1 + 0x114) == -1) {
      return 0x80004005;
    }
    if (param_3 != 0) {
      do {
        iVar1 = recv(*(SOCKET *)(param_1 + 0x114),(char *)(uVar3 + param_2),param_3 - uVar3,0);
        if ((iVar1 == -1) || (iVar1 == 0)) {
          DVar2 = GetLastError();
          if (DVar2 != 0) {
            if (0 < (int)DVar2) {
              return DVar2 & 0xffff | 0x80070000;
            }
            return DVar2;
          }
          if (iVar1 == 0) {
            return 0x80004005;
          }
          return 0;
        }
        uVar3 = iVar1 + uVar3;
        if (param_4 != (uint *)0x0) {
          *param_4 = uVar3;
        }
      } while (uVar3 < param_3);
    }
  }
  return 0;
}



/* 0001c36c FUN_0001c36c */

/* Boundary evidence: original MIPS .pdata 0001c36c..0001c3e7. Semantic name remains unreviewed. */

LONG FUN_0001c36c(int *param_1)

{
  LONG LVar1;
  undefined1 auStack_20 [8];
  undefined4 local_18;
  DWORD local_14;
  
  LVar1 = InterlockedDecrement(param_1 + 1);
  if (LVar1 == 0) {
    local_18 = 0xa1a1a1a1;
    local_14 = GetLastError();
    (**(code **)(*param_1 + 0x10))(param_1,&local_18,8,auStack_20);
  }
  return LVar1;
}



/* 0001c3e8 FUN_0001c3e8 */

/* Boundary evidence: original MIPS .pdata 0001c3e8..0001c4f3. Semantic name remains unreviewed. */

uint FUN_0001c3e8(int param_1,int param_2,uint param_3,uint *param_4)

{
  uint uVar1;
  int iVar2;
  DWORD DVar3;
  
  if ((param_4 == (uint *)0x0) || (param_2 == 0)) {
    uVar1 = 0x80070057;
  }
  else if (*(int *)(param_1 + 0x114) == -1) {
    uVar1 = 0x80004004;
  }
  else {
    if (((timeval *)(param_1 + 8))->tv_sec != -1) {
      *param_4 = 0;
      iVar2 = select(0,(fd_set *)(param_1 + 0x10),(fd_set *)0x0,(fd_set *)0x0,
                     (timeval *)(param_1 + 8));
      if (iVar2 == -1) {
        DVar3 = GetLastError();
        if ((int)DVar3 < 1) {
          return DVar3;
        }
        return DVar3 & 0xffff | 0x80070000;
      }
      if (iVar2 == 0) {
        return 0x80070461;
      }
    }
    uVar1 = FUN_0001c250(param_1,param_2,param_3,param_4);
  }
  return uVar1;
}



/* 0001c4f4 FUN_0001c4f4 */

/* Boundary evidence: original MIPS .pdata 0001c4f4..0001c59f. Semantic name remains unreviewed. */

uint FUN_0001c4f4(int param_1,char *param_2,int param_3,int *param_4)

{
  int iVar1;
  DWORD DVar2;
  
  if ((param_2 == (char *)0x0) || (param_4 == (int *)0x0)) {
    return 0x80070057;
  }
  *param_4 = 0;
  if (param_3 != 0) {
    if (*(SOCKET *)(param_1 + 0x114) == 0xffffffff) {
      return 0x80004004;
    }
    iVar1 = send(*(SOCKET *)(param_1 + 0x114),param_2,param_3,0);
    if (iVar1 == -1) {
      DVar2 = GetLastError();
      if ((int)DVar2 < 1) {
        return DVar2;
      }
      return DVar2 & 0xffff | 0x80070000;
    }
    *param_4 = iVar1;
  }
  return 0;
}



/* 0001c5a0 FUN_0001c5a0 */

/* Boundary evidence: original MIPS .pdata 0001c5a0..0001c60b. Semantic name remains unreviewed. */

undefined4 FUN_0001c5a0(int *param_1,int *param_2)

{
  undefined4 uVar1;
  
  if (param_2 == (int *)0x0) {
    uVar1 = 0x80070057;
  }
  else if (param_1[1] == 0) {
    (**(code **)(*param_1 + 4))(param_1);
    *param_2 = (int)param_1;
    uVar1 = 0;
  }
  else {
    uVar1 = 0x80070005;
  }
  return uVar1;
}



/* 0001c660 FUN_0001c660 */

/* Boundary evidence: original MIPS .pdata 0001c660..0001c7cb. Semantic name remains unreviewed. */

uint FUN_0001c660(int param_1,int *param_2,uint param_3)

{
  void *pvVar1;
  BOOL BVar2;
  uint uVar3;
  uint local_res8 [2];
  
  uVar3 = 0;
  if (param_2 == (int *)0x0) {
    return 0x80070057;
  }
  local_res8[0] = param_3;
  if (param_3 == 0xffffffff) {
    uVar3 = FUN_0001c250(param_1,(int)local_res8,4,(uint *)0x0);
    if ((int)uVar3 < 0) {
      return uVar3;
    }
    if (local_res8[0] == 0) {
      return 0x80004005;
    }
  }
  else if (param_3 == 0) {
    return 0;
  }
  pvVar1 = operator_new(local_res8[0]);
  if (pvVar1 != (void *)0x0) {
    BVar2 = IsBadWritePtr((LPVOID)*param_2,4);
    if (BVar2 != 0) {
      trap(0x400);
    }
    uVar3 = FUN_0001c250(param_1,(int)pvVar1,local_res8[0],(uint *)0x0);
    if (-1 < (int)uVar3) {
      BVar2 = IsBadWritePtr((LPVOID)*param_2,4);
      if (BVar2 != 0) {
        trap(0x400);
      }
      uVar3 = FUN_0001cd50(param_2,pvVar1,local_res8[0]);
      if (-1 < (int)uVar3) {
        BVar2 = IsBadWritePtr((LPVOID)*param_2,4);
        if (BVar2 != 0) {
          trap(0x400);
        }
        uVar3 = 0;
      }
    }
    operator_delete(pvVar1);
  }
  return uVar3;
}



/* 0001c7cc FUN_0001c7cc */

/* Boundary evidence: original MIPS .pdata 0001c7cc..0001c89f. Semantic name remains unreviewed. */

undefined4 * FUN_0001c7cc(undefined4 *param_1,SOCKET param_2)

{
  int iVar1;
  fd_set *pfVar2;
  char local_18 [8];
  
  pfVar2 = (fd_set *)(param_1 + 4);
  *param_1 = &PTR_LAB_0001159c;
  param_1[1] = 0;
  pfVar2->fd_count = 0;
  iVar1 = __WSAFDIsSet(param_2,pfVar2);
  if ((iVar1 == 0) && (pfVar2->fd_count < 0x40)) {
    param_1[pfVar2->fd_count + 5] = param_2;
    pfVar2->fd_count = pfVar2->fd_count + 1;
  }
  param_1[3] = 0;
  param_1[2] = 0xffffffff;
  param_1[0x45] = param_2;
  if (param_2 != 0xffffffff) {
    local_18[0] = '\x01';
    local_18[1] = '\0';
    local_18[2] = '\0';
    local_18[3] = '\0';
    iVar1 = setsockopt(param_2,6,1,local_18,4);
    if (iVar1 == -1) {
      param_1[0x45] = 0xffffffff;
    }
  }
  return param_1;
}



/* 0001c8a0 FUN_0001c8a0 */

/* Boundary evidence: original MIPS .pdata 0001c8a0..0001c8e3. Semantic name remains unreviewed. */

undefined4 * FUN_0001c8a0(undefined4 *param_1)

{
  void *pvVar1;
  
  param_1[1] = 500;
  pvVar1 = operator_new(500);
  *param_1 = pvVar1;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  return param_1;
}



/* 0001c8e4 FUN_0001c8e4 */

/* Boundary evidence: original MIPS .pdata 0001c8e4..0001c8ff. Semantic name remains unreviewed. */

void FUN_0001c8e4(undefined4 *param_1)

{
  operator_delete((void *)*param_1);
  return;
}



/* 0001c900 FUN_0001c900 */

/* Boundary evidence: original MIPS .pdata 0001c900..0001ca23. Semantic name remains unreviewed. */

undefined4 FUN_0001c900(int *param_1,void *param_2,uint param_3,int param_4)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint _Size;
  
  if (param_3 != 0) {
    if (param_2 == (void *)0x0) {
      return 0x80070057;
    }
    uVar2 = param_1[2];
    if (uVar2 < param_3) {
      return 0x80004005;
    }
    uVar3 = param_1[4];
    _Size = param_1[1] - uVar3;
    if ((uVar3 < (uint)param_1[3]) || (param_3 <= _Size)) {
      memcpy(param_2,(void *)(uVar3 + *param_1),param_3);
      if (param_4 == 0) {
        return 0;
      }
      iVar1 = param_1[4];
      param_1[4] = param_3 + iVar1;
      if (param_3 + iVar1 == param_1[1]) {
        param_1[4] = 0;
      }
    }
    else {
      memcpy(param_2,(void *)(uVar3 + *param_1),_Size);
      memcpy((void *)(_Size + (int)param_2),(void *)*param_1,param_3 - _Size);
      if (param_4 == 0) {
        return 0;
      }
      param_1[4] = param_3 - _Size;
    }
    param_1[2] = uVar2 - param_3;
  }
  return 0;
}



/* 0001ca24 FUN_0001ca24 */

undefined4 FUN_0001ca24(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  if (param_2 == (undefined4 *)0x0) {
    uVar1 = 0x80070057;
  }
  else {
    uVar1 = 0;
    *param_2 = *(undefined4 *)(param_1 + 8);
  }
  return uVar1;
}



/* 0001ca4c FUN_0001ca4c */

undefined4 FUN_0001ca4c(int param_1)

{
  *(undefined4 *)(param_1 + 8) = 0;
  *(undefined4 *)(param_1 + 0xc) = 0;
  *(undefined4 *)(param_1 + 0x10) = 0;
  return 0;
}



/* 0001ca60 FUN_0001ca60 */

/* Boundary evidence: original MIPS .pdata 0001ca60..0001cb2b. Semantic name remains unreviewed. */

int FUN_0001ca60(int *param_1,uint param_2)

{
  void *pvVar1;
  int iVar2;
  
  if ((uint)param_1[1] < param_2) {
    pvVar1 = operator_new(param_2);
    if (pvVar1 == (void *)0x0) {
      iVar2 = -0x7ff8fff2;
    }
    else {
      iVar2 = FUN_0001c900(param_1,pvVar1,param_1[2],0);
      if (-1 < iVar2) {
        operator_delete((void *)*param_1);
        *param_1 = (int)pvVar1;
        param_1[1] = param_2;
        param_1[3] = param_1[2];
        param_1[4] = 0;
        return 0;
      }
    }
    if (pvVar1 != (void *)0x0) {
      operator_delete(pvVar1);
    }
  }
  else {
    iVar2 = -0x7fff0001;
  }
  return iVar2;
}



/* 0001cb2c FUN_0001cb2c */

/* Boundary evidence: original MIPS .pdata 0001cb2c..0001cc3f. Semantic name remains unreviewed. */

int FUN_0001cb2c(int *param_1,int *param_2,uint param_3)

{
  uint uVar1;
  int iVar2;
  void *pvVar3;
  uint local_20 [2];
  
  if (param_2 == (int *)0x0) {
    return -0x7ff8ffa9;
  }
  iVar2 = FUN_0001c900(param_1,local_20,4,1);
  if (iVar2 < 0) {
    return iVar2;
  }
  if (local_20[0] == 0) {
    *param_2 = 0;
  }
  else {
    iVar2 = FUN_0001c900(param_1,local_20,4,1);
    uVar1 = local_20[0];
    if (iVar2 < 0) {
      return iVar2;
    }
    if (*param_2 == 0) {
      pvVar3 = operator_new(local_20[0]);
      *param_2 = (int)pvVar3;
      if (pvVar3 == (void *)0x0) {
        return -0x7ff8fff2;
      }
    }
    else if (param_3 < local_20[0]) {
      return -0x7ff8ffa9;
    }
    iVar2 = FUN_0001c900(param_1,local_20,4,1);
    if (iVar2 < 0) {
      return iVar2;
    }
    if (local_20[0] != 0) {
      iVar2 = FUN_0001c900(param_1,(void *)*param_2,uVar1,1);
      return iVar2;
    }
  }
  return 0;
}



/* 0001cc40 FUN_0001cc40 */

/* Boundary evidence: original MIPS .pdata 0001cc40..0001cd4f. Semantic name remains unreviewed. */

int FUN_0001cc40(int *param_1,undefined4 *param_2)

{
  void *pvVar1;
  uint uVar2;
  int iVar3;
  uint local_18 [2];
  
  if (param_2 == (undefined4 *)0x0) {
    iVar3 = -0x7ff8ffa9;
  }
  else {
    *param_2 = 0;
    iVar3 = FUN_0001c900(param_1,local_18,4,1);
    if (-1 < iVar3) {
      if (local_18[0] == 0) {
        return 0;
      }
      iVar3 = FUN_0001c900(param_1,local_18,4,1);
      if (-1 < iVar3) {
        if (local_18[0] < 0x80000000) {
          uVar2 = local_18[0] << 1;
        }
        else {
          uVar2 = 0xffffffff;
        }
        pvVar1 = operator_new(uVar2);
        *param_2 = pvVar1;
        if (pvVar1 == (void *)0x0) {
          iVar3 = -0x7ff8fff2;
        }
        else {
          iVar3 = FUN_0001c900(param_1,pvVar1,local_18[0] << 1,1);
          if (-1 < iVar3) {
            return 0;
          }
        }
      }
    }
  }
  if ((void *)*param_2 != (void *)0x0) {
    operator_delete((void *)*param_2);
  }
  return iVar3;
}



/* 0001cd50 FUN_0001cd50 */

/* Boundary evidence: original MIPS .pdata 0001cd50..0001ce7b. Semantic name remains unreviewed. */

int FUN_0001cd50(int *param_1,void *param_2,uint param_3)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint _Size;
  
  if (param_3 != 0) {
    if (param_2 == (void *)0x0) {
      return -0x7ff8ffa9;
    }
    uVar3 = param_1[2] + param_3;
    if (uVar3 < (uint)param_1[2]) {
      return -0x7fffbffb;
    }
    if (((uint)param_1[1] < uVar3) && (iVar1 = FUN_0001ca60(param_1,uVar3), iVar1 < 0)) {
      return iVar1;
    }
    uVar2 = param_1[3];
    _Size = param_1[1] - uVar2;
    if ((uVar2 < (uint)param_1[4]) || (param_3 <= _Size)) {
      memcpy((void *)(uVar2 + *param_1),param_2,param_3);
      iVar1 = param_1[3];
      param_1[3] = iVar1 + param_3;
      if (iVar1 + param_3 == param_1[1]) {
        param_1[3] = 0;
      }
    }
    else {
      memcpy((void *)(uVar2 + *param_1),param_2,_Size);
      memcpy((void *)*param_1,(void *)(_Size + (int)param_2),param_3 - _Size);
      param_1[3] = param_3 - _Size;
    }
    param_1[2] = uVar3;
  }
  return 0;
}



/* 0001ce7c FUN_0001ce7c */

/* Boundary evidence: original MIPS .pdata 0001ce7c..0001cf9b. Semantic name remains unreviewed. */

int FUN_0001ce7c(int *param_1,void *param_2,uint param_3)

{
  int iVar1;
  uint _Size;
  size_t _Size_00;
  uint uVar2;
  
  if (param_3 != 0) {
    if (param_2 == (void *)0x0) {
      return -0x7ff8ffa9;
    }
    uVar2 = param_1[2] + param_3;
    if (uVar2 < (uint)param_1[2]) {
      return -0x7fffbffb;
    }
    if (((uint)param_1[1] < uVar2) && (iVar1 = FUN_0001ca60(param_1,uVar2), iVar1 < 0)) {
      return iVar1;
    }
    _Size = param_1[4];
    if (((uint)param_1[3] < _Size) || (param_3 <= _Size)) {
      param_1[4] = _Size - param_3;
      memcpy((void *)((_Size - param_3) + *param_1),param_2,param_3);
    }
    else {
      _Size_00 = param_3 - _Size;
      memcpy((void *)*param_1,(void *)((int)param_2 + _Size_00),_Size);
      memcpy((void *)((*param_1 - _Size_00) + param_1[1]),param_2,_Size_00);
      param_1[4] = param_1[1] - _Size_00;
    }
    param_1[2] = uVar2;
  }
  return 0;
}



/* 0001cf9c FUN_0001cf9c */

/* Boundary evidence: original MIPS .pdata 0001cf9c..0001d05f. Semantic name remains unreviewed. */

int FUN_0001cf9c(int *param_1,void *param_2,uint param_3,int param_4)

{
  int iVar1;
  uint local_res8;
  int local_resc;
  uint local_18 [2];
  
  local_18[0] = (uint)(param_2 != (void *)0x0);
  local_res8 = param_3;
  local_resc = param_4;
  iVar1 = FUN_0001cd50(param_1,local_18,4);
  if (iVar1 < 0) {
    return iVar1;
  }
  if (local_18[0] != 0) {
    iVar1 = FUN_0001cd50(param_1,&local_res8,4);
    if (iVar1 < 0) {
      return iVar1;
    }
    iVar1 = FUN_0001cd50(param_1,&local_resc,4);
    if (iVar1 < 0) {
      return iVar1;
    }
    if (local_resc != 0) {
      iVar1 = FUN_0001cd50(param_1,param_2,local_res8);
      return iVar1;
    }
  }
  return 0;
}



/* 0001d0c0 FUN_0001d0c0 */

/* Boundary evidence: original MIPS .pdata 0001d0c0..0001d113. Semantic name remains unreviewed. */

void FUN_0001d0c0(int param_1,undefined4 param_2,uint *param_3)

{
  if ((*param_3 & 1) != 0) {
    param_1 = ((-param_3[2] & param_3[1] + param_1) - (param_3[1] + param_1)) + param_1;
  }
  FUN_0001d140(*(uint *)(param_1 + (*param_3 & 0xfffffffc)));
  return;
}



/* 0001d114 FUN_0001d114 */

/* Boundary evidence: original MIPS .pdata 0001d114..0001d13f. Semantic name remains unreviewed. */

undefined4 FUN_0001d114(undefined4 param_1,int param_2,undefined4 param_3,int param_4)

{
  FUN_0001d0c0(param_2,param_4,*(uint **)(*(int *)(param_4 + 4) + 0xc));
  return 1;
}



/* 0001d140 FUN_0001d140 */

/* Boundary evidence: original MIPS .pdata 0001d140..0001d187. Semantic name remains unreviewed. */

void FUN_0001d140(uint param_1)

{
  if ((param_1 == DAT_0001e29c) && (param_1 >> 0x10 == 0)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __report_gsfailure();
}


