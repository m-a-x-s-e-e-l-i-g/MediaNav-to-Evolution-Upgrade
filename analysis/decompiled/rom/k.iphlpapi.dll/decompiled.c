/* Automatic Ghidra pseudocode. Not original source; not runtime-verified. */

/* c0481504 FUN_c0481504 */

/* Boundary evidence: original MIPS .pdata c0481504..c0481547. Semantic name remains unreviewed. */

DWORD FUN_c0481504(int param_1)

{
  int iVar1;
  DWORD DVar2;
  
  iVar1 = FUN_c048c620();
  if ((iVar1 != 0) || (DVar2 = FUN_c0484914((undefined2 *)(param_1 + 8),0), DVar2 == 0)) {
    DVar2 = 0;
  }
  return DVar2;
}



/* c0481548 FUN_c0481548 */

/* Boundary evidence: original MIPS .pdata c0481548..c0481597. Semantic name remains unreviewed. */

int FUN_c0481548(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_c048c620();
  if (((iVar1 != 0) && (iVar1 = FUN_c048c620(), iVar1 != 0)) ||
     (iVar1 = FUN_c0484d2c((undefined4 *)(param_1 + 8)), iVar1 == 0)) {
    iVar1 = 0;
  }
  return iVar1;
}



/* c0481598 FUN_c0481598 */

/* Boundary evidence: original MIPS .pdata c0481598..c04815e7. Semantic name remains unreviewed. */

int FUN_c0481598(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_c048c620();
  if (((iVar1 != 0) && (iVar1 = FUN_c048c620(), iVar1 != 0)) ||
     (iVar1 = FUN_c0484d2c((undefined4 *)(param_1 + 8)), iVar1 == 0)) {
    iVar1 = 0;
  }
  return iVar1;
}



/* c04815e8 FUN_c04815e8 */

/* Boundary evidence: original MIPS .pdata c04815e8..c048163f. Semantic name remains unreviewed. */

int FUN_c04815e8(int param_1)

{
  int iVar1;
  
  *(undefined4 *)(param_1 + 0x1c) = 2;
  iVar1 = FUN_c048c620();
  if (((iVar1 != 0) && (iVar1 = FUN_c048c620(), iVar1 != 0)) ||
     (iVar1 = FUN_c0484d2c((undefined4 *)(param_1 + 8)), iVar1 == 0)) {
    iVar1 = 0;
  }
  return iVar1;
}



/* c0481640 FUN_c0481640 */

/* Boundary evidence: original MIPS .pdata c0481640..c048167f. Semantic name remains unreviewed. */

int FUN_c0481640(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_c048c620();
  if ((iVar1 != 0) || (iVar1 = FUN_c0483750((void *)(param_1 + 8)), iVar1 == 0)) {
    iVar1 = 0;
  }
  return iVar1;
}



/* c0481680 FUN_c0481680 */

/* Boundary evidence: original MIPS .pdata c0481680..c04816c3. Semantic name remains unreviewed. */

int FUN_c0481680(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_c048c620();
  if ((iVar1 != 0) || (iVar1 = FUN_c0483bec((uint *)(param_1 + 8),0), iVar1 == 0)) {
    iVar1 = 0;
  }
  return iVar1;
}



/* c04816c4 FUN_c04816c4 */

/* Boundary evidence: original MIPS .pdata c04816c4..c0481707. Semantic name remains unreviewed. */

int FUN_c04816c4(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_c048c620();
  if ((iVar1 != 0) || (iVar1 = FUN_c0483bec((uint *)(param_1 + 8),0), iVar1 == 0)) {
    iVar1 = 0;
  }
  return iVar1;
}



/* c0481708 FUN_c0481708 */

/* Boundary evidence: original MIPS .pdata c0481708..c0481753. Semantic name remains unreviewed. */

int FUN_c0481708(int param_1)

{
  int iVar1;
  
  *(undefined4 *)(param_1 + 0x1c) = 2;
  iVar1 = FUN_c048c620();
  if ((iVar1 != 0) || (iVar1 = FUN_c0483bec((uint *)(param_1 + 8),0), iVar1 == 0)) {
    iVar1 = 0;
  }
  return iVar1;
}



/* c0481754 FUN_c0481754 */

/* Boundary evidence: original MIPS .pdata c0481754..c048176f. Semantic name remains unreviewed. */

void FUN_c0481754(int param_1)

{
  FUN_c048319c((void *)(param_1 + 8));
  return;
}



/* c0481770 GetInterfaceInfo */

/* Boundary evidence: original MIPS .pdata c0481770..c0481867. Semantic name remains unreviewed. */

DWORD GetInterfaceInfo(LPVOID param_1,LPDWORD param_2)

{
  BOOL BVar1;
  DWORD DVar2;
  DWORD local_78 [2];
  undefined1 auStack_70 [80];
  int local_20;
  
                    /* 0x1770  25  GetInterfaceInfo */
  local_78[0] = 0;
  BVar1 = IsBadWritePtr(param_2,4);
  if ((BVar1 == 0) && (BVar1 = IsBadWritePtr(param_1,*param_2), BVar1 == 0)) {
    DVar2 = FUN_c04836b0(auStack_70);
    if (DVar2 == 0) {
      if (local_20 == 0) {
        DVar2 = 0xe8;
      }
      else if ((param_1 == (LPVOID)0x0) || (*param_2 < (uint)(local_20 * 0x104))) {
        DVar2 = 0x7a;
        *param_2 = (local_20 + 10) * 0x104;
      }
      else {
        DVar2 = FUN_c0482aa8(DAT_c048f5b4,0x120040,(LPVOID)0x0,local_78,param_1,param_2);
      }
    }
  }
  else {
    DVar2 = 0x57;
  }
  return DVar2;
}



/* c0481868 GetUniDirectionalAdapterInfo */

/* Boundary evidence: original MIPS .pdata c0481868..c04818af. Semantic name remains unreviewed. */

DWORD GetUniDirectionalAdapterInfo(LPVOID param_1,LPDWORD param_2)

{
  DWORD DVar1;
  DWORD local_10 [2];
  
                    /* 0x1868  41  GetUniDirectionalAdapterInfo */
  local_10[0] = 0;
  if (param_2 == (LPDWORD)0x0) {
    DVar1 = 0x57;
  }
  else {
    DVar1 = FUN_c0482aa8(DAT_c048f5b4,0x120094,(LPVOID)0x0,local_10,param_1,param_2);
  }
  return DVar1;
}



/* c04818b0 FUN_c04818b0 */

/* Boundary evidence: original MIPS .pdata c04818b0..c04819c7. Semantic name remains unreviewed. */

DWORD FUN_c04818b0(undefined4 param_1,LPVOID param_2,LPDWORD param_3)

{
  DWORD DVar1;
  BOOL BVar2;
  undefined4 local_res0 [4];
  DWORD local_20 [2];
  
  local_20[0] = 4;
  if ((param_3 == (LPDWORD)0x0) ||
     (local_res0[0] = param_1, BVar2 = IsBadWritePtr(param_3,4), BVar2 != 0)) {
LAB_c04818e0:
    DVar1 = 0x57;
  }
  else {
    if (param_2 == (LPVOID)0x0) {
      local_20[1] = 4;
      DVar1 = FUN_c0482aa8(DAT_c048f5b4,0x120054,local_res0,local_20,param_3,local_20 + 1);
    }
    else {
      BVar2 = IsBadWritePtr(param_2,*param_3);
      if ((BVar2 != 0) || (*param_3 < 5)) goto LAB_c04818e0;
      DVar1 = FUN_c0482aa8(DAT_c048f5b4,0x120054,local_res0,local_20,param_2,param_3);
    }
    if ((DVar1 == 0xea) || (DVar1 == 0x80000005)) {
      DVar1 = 0x7a;
    }
  }
  return DVar1;
}



/* c04819c8 GetAdapterIndex */

/* Boundary evidence: original MIPS .pdata c04819c8..c0481b47. Semantic name remains unreviewed. */

DWORD GetAdapterIndex(LPCWSTR param_1,int *param_2)

{
  DWORD DVar1;
  int *lpMem;
  int iVar2;
  int iVar3;
  LPCWSTR lpString2;
  int local_30;
  SIZE_T local_2c;
  
                    /* 0x19c8  13  GetAdapterIndex */
  if ((param_1 == (LPCWSTR)0x0) || (param_2 == (int *)0x0)) {
    DVar1 = 0x57;
  }
  else {
    DVar1 = GetNumberOfInterfaces(&local_30);
    if (DVar1 == 0) {
      if (local_30 == 0) {
        DVar1 = 0xe8;
      }
      else {
        local_2c = (local_30 + 10) * 0x104;
        lpMem = HeapAlloc(DAT_c048f5d4,0,local_2c);
        if (lpMem == (int *)0x0) {
          DVar1 = 8;
        }
        else {
          DVar1 = GetInterfaceInfo(lpMem,&local_2c);
          if (DVar1 == 0) {
            iVar3 = 0;
            if (0 < *lpMem) {
              lpString2 = (LPCWSTR)(lpMem + 2);
              do {
                iVar2 = lstrcmpiW(param_1,lpString2);
                if (iVar2 == 0) break;
                iVar3 = iVar3 + 1;
                lpString2 = lpString2 + 0x82;
              } while (iVar3 < *lpMem);
            }
            if (*lpMem <= iVar3) {
              HeapFree(DAT_c048f5d4,0,lpMem);
              return 0x37;
            }
            DVar1 = 0;
            *param_2 = lpMem[iVar3 * 0x41 + 1];
          }
          HeapFree(DAT_c048f5d4,0,lpMem);
        }
      }
    }
  }
  return DVar1;
}



/* c0481b48 AddIPAddress */

/* Boundary evidence: original MIPS .pdata c0481b48..c0481d63. Semantic name remains unreviewed. */

DWORD AddIPAddress(uint param_1,uint param_2,uint param_3,uint *param_4,uint *param_5)

{
  u_long uVar1;
  u_long uVar2;
  BOOL BVar3;
  DWORD DVar4;
  uint uVar5;
  DWORD local_48 [2];
  uint local_40;
  uint local_3c;
  uint local_38;
  uint local_28;
  
                    /* 0x1b48  1  AddIPAddress */
  local_28 = DAT_c048f418;
  local_48[0] = 0x18;
  local_48[1] = 0x18;
  if ((((param_1 != 0xffffffff) && (uVar1 = ntohl(param_1), (uVar1 & 0xff000000) != 0x7f000000)) &&
      (param_1 != 0)) && (uVar1 = ntohl(param_1), (uVar1 & 0xf0000000) != 0xe0000000)) {
    uVar5 = ~param_2 & param_1;
    if ((uVar5 != 0) && (uVar5 != ~param_2)) {
      uVar1 = ntohl(param_2);
      uVar2 = ntohl(param_2);
      if (((((~uVar2 & ~uVar1 + 1) == 0) && ((param_4 != (uint *)0x0 && (param_5 != (uint *)0x0))))
          && (BVar3 = IsBadWritePtr(param_4,4), BVar3 == 0)) &&
         (BVar3 = IsBadWritePtr(param_5,4), BVar3 == 0)) {
        local_40 = param_3;
        local_3c = param_1;
        local_38 = param_2;
        FUN_c0485020();
        DVar4 = FUN_c0482aa8(DAT_c048f5a8,0x12801c,&local_40,local_48,&local_40,local_48 + 1);
        if (DVar4 == 0) {
          *param_4 = local_40 & 0xffff;
          *param_5 = local_3c;
        }
        else if (DVar4 == 0xc000022a) {
          DVar4 = 0x4c5;
        }
        else if (DVar4 == 0xc00000bd) {
          DVar4 = 0xb7;
        }
        else if (DVar4 == 0xc00000c0) {
          DVar4 = 0x37;
        }
        FUN_c048e238(local_28);
        return DVar4;
      }
    }
  }
  FUN_c048e238(local_28);
  return 0x57;
}



/* c0481d64 DeleteIPAddress */

/* Boundary evidence: original MIPS .pdata c0481d64..c0481dc7. Semantic name remains unreviewed. */

DWORD DeleteIPAddress(undefined2 param_1)

{
  DWORD DVar1;
  undefined2 local_18 [2];
  DWORD local_14 [3];
  
                    /* 0x1d64  7  DeleteIPAddress */
  local_14[1] = 2;
  local_14[0] = 0;
  local_18[0] = param_1;
  FUN_c0485020();
  DVar1 = FUN_c0482aa8(DAT_c048f5a8,0x128020,local_18,local_14 + 1,(LPVOID)0x0,local_14);
  if (DVar1 == 0xc00000c0) {
    DVar1 = 0x37;
  }
  return DVar1;
}



/* c0481dc8 FUN_c0481dc8 */

/* Boundary evidence: original MIPS .pdata c0481dc8..c0481f97. Semantic name remains unreviewed. */

undefined4 FUN_c0481dc8(IPAddr param_1,undefined4 *param_2)

{
  BOOL BVar1;
  HANDLE IcmpHandle;
  LPVOID ReplyBuffer;
  DWORD DVar2;
  undefined4 *IcmpHandle_00;
  char *pcVar3;
  uint uVar4;
  undefined4 uVar5;
  uint uVar6;
  ip_option_information local_50;
  char local_48 [32];
  uint local_28;
  
  local_28 = DAT_c048f418;
  IcmpHandle_00 = param_2;
  BVar1 = IsBadWritePtr(param_2,4);
  if (BVar1 != 0) {
    FUN_c048e238(local_28);
    return 0x57;
  }
  IcmpHandle = (HANDLE)Icmp6CreateFile(IcmpHandle_00);
  if (IcmpHandle == (HANDLE)0xffffffff) {
    FUN_c048e238(local_28);
    return 0;
  }
  ReplyBuffer = HeapAlloc(DAT_c048f5d4,0,0x1000);
  if (ReplyBuffer != (LPVOID)0x0) {
    uVar4 = 0;
    do {
      uVar6 = uVar4 % 0x17;
      pcVar3 = local_48 + uVar4;
      uVar4 = uVar4 + 1;
      *pcVar3 = (char)uVar6 + 'a';
    } while (uVar4 < 0x20);
    local_50.Ttl = ' ';
    local_50.OptionsData = (PUCHAR)0x0;
    local_50.OptionsSize = '\0';
    local_50.Tos = '\0';
    local_50.Flags = '\0';
    DVar2 = IcmpSendEcho(IcmpHandle,param_1,local_48,0x20,&local_50,ReplyBuffer,0x1000,5000);
    if ((DVar2 != 0) &&
       (DVar2 = IcmpSendEcho(IcmpHandle,param_1,local_48,0x20,&local_50,ReplyBuffer,0x1000,5000),
       DVar2 != 0)) {
      *param_2 = *(undefined4 *)((int)ReplyBuffer + 8);
      HeapFree(DAT_c048f5d4,0,ReplyBuffer);
      uVar5 = 1;
      goto LAB_c0481f5c;
    }
    HeapFree(DAT_c048f5d4,0,ReplyBuffer);
  }
  uVar5 = 0;
LAB_c0481f5c:
  Icmp6CreateFile(IcmpHandle);
  FUN_c048e238(local_28);
  return uVar5;
}



/* c0481f98 GetRTTAndHopCount */

/* Boundary evidence: original MIPS .pdata c0481f98..c04821eb. Semantic name remains unreviewed. */

undefined4 GetRTTAndHopCount(IPAddr param_1,uint *param_2,uint param_3,undefined4 *param_4)

{
  BOOL BVar1;
  HANDLE IcmpHandle;
  LPVOID ReplyBuffer;
  DWORD DVar2;
  int iVar3;
  uint *IcmpHandle_00;
  char *pcVar4;
  uint uVar5;
  uint uVar6;
  ip_option_information local_60;
  undefined4 local_58 [2];
  char local_50 [32];
  uint local_30;
  
                    /* 0x1f98  34  GetRTTAndHopCount */
  local_30 = DAT_c048f418;
  if (((((param_2 != (uint *)0x0) && (param_4 != (undefined4 *)0x0)) && (param_1 != 0xffffffff)) &&
      ((BVar1 = IsBadWritePtr(param_4,4), BVar1 == 0 &&
       (IcmpHandle_00 = param_2, BVar1 = IsBadWritePtr(param_2,4), BVar1 == 0)))) &&
     (IcmpHandle = (HANDLE)Icmp6CreateFile(IcmpHandle_00), IcmpHandle != (HANDLE)0xffffffff)) {
    ReplyBuffer = HeapAlloc(DAT_c048f5d4,0,0x1000);
    if (ReplyBuffer != (LPVOID)0x0) {
      uVar5 = 0;
      do {
        uVar6 = uVar5 % 0x17;
        pcVar4 = local_50 + uVar5;
        uVar5 = uVar5 + 1;
        *pcVar4 = (char)uVar6 + 'a';
      } while (uVar5 < 0x20);
      local_60.OptionsData = (PUCHAR)0x0;
      local_60.OptionsSize = '\0';
      local_60.Ttl = 1;
      local_60.Tos = '\0';
      local_60.Flags = '\0';
      if (param_3 != 0) {
        do {
          DVar2 = IcmpSendEcho(IcmpHandle,param_1,local_50,0x20,&local_60,ReplyBuffer,0x1000,5000);
          if (DVar2 == 0) {
            DVar2 = GetLastError();
          }
          else {
            DVar2 = *(DWORD *)((int)ReplyBuffer + 4);
          }
          if (DVar2 == 0) {
            *param_2 = (uint)local_60.Ttl;
            HeapFree(DAT_c048f5d4,0,ReplyBuffer);
            Icmp6CreateFile(IcmpHandle);
            iVar3 = FUN_c0481dc8(param_1,local_58);
            if (iVar3 != 0) {
              *param_4 = local_58[0];
              FUN_c048e238(local_30);
              return 1;
            }
            goto LAB_c0482160;
          }
        } while (((DVar2 == 0x2b05) || (DVar2 == 0x2b02)) &&
                (local_60.Ttl = local_60.Ttl + 1, local_60.Ttl <= param_3));
      }
      HeapFree(DAT_c048f5d4,0,ReplyBuffer);
    }
    Icmp6CreateFile(IcmpHandle);
  }
LAB_c0482160:
  FUN_c048e238(local_30);
  return 0;
}



/* c04821ec IsLocalAddress */

/* Boundary evidence: original MIPS .pdata c04821ec..c04822ab. Semantic name remains unreviewed. */

DWORD IsLocalAddress(int param_1)

{
  DWORD DVar1;
  int *piVar2;
  int iVar3;
  int *local_18 [2];
  
                    /* 0x21ec  52  IsLocalAddress */
  DVar1 = AllocateAndGetIpAddrTableFromStack(local_18,0,DAT_c048f5d4,0);
  if (DVar1 == 0) {
    if (param_1 == 0x100007f) {
      HeapFree(DAT_c048f5d4,0,local_18[0]);
      DVar1 = 0;
    }
    else {
      iVar3 = 0;
      if (0 < *local_18[0]) {
        piVar2 = local_18[0] + 1;
        do {
          if (*piVar2 == param_1) {
            DVar1 = 0;
            goto LAB_c048227c;
          }
          iVar3 = iVar3 + 1;
          piVar2 = piVar2 + 6;
        } while (iVar3 < *local_18[0]);
      }
      DVar1 = 0x1e7;
LAB_c048227c:
      HeapFree(DAT_c048f5d4,0,local_18[0]);
    }
  }
  return DVar1;
}



/* c04822ac FUN_c04822ac */

/* Boundary evidence: original MIPS .pdata c04822ac..c048237b. Semantic name remains unreviewed. */

undefined4 FUN_c04822ac(undefined4 *param_1,int param_2,LPCWSTR param_3)

{
  undefined4 uVar1;
  HANDLE hHandle;
  DWORD DVar2;
  
  if (param_2 == 0) {
    hHandle = CreateEventW((LPSECURITY_ATTRIBUTES)0x0,1,0,param_3);
    if (hHandle == (HANDLE)0x0) {
      uVar1 = 8;
    }
    else {
      DVar2 = GetLastError();
      if (DVar2 == 0xb7) {
        if (param_1 == (undefined4 *)0x0) {
          WaitForSingleObject(hHandle,0xffffffff);
          CloseHandle(hHandle);
        }
        else {
          *param_1 = hHandle;
        }
        uVar1 = 0;
      }
      else {
        CloseHandle(hHandle);
        uVar1 = 0x32;
      }
    }
  }
  else {
    uVar1 = 0x57;
  }
  return uVar1;
}



/* c048237c NotifyAddrChange */

/* Boundary evidence: original MIPS .pdata c048237c..c048239b. Semantic name remains unreviewed. */

void NotifyAddrChange(undefined4 *param_1,int param_2)

{
                    /* 0x237c  53  NotifyAddrChange */
  FUN_c04822ac(param_1,param_2,L"IP_ADDR_CHANGE_EVENT");
  return;
}



/* c048239c EnableRouter */

undefined4 EnableRouter(void)

{
                    /* 0x239c  11  EnableRouter
                       0x239c  62  UnenableRouter */
  return 0x32;
}



/* c04823a4 GetNetworkParams */

/* Boundary evidence: original MIPS .pdata c04823a4..c0482447. Semantic name remains unreviewed. */

undefined4 GetNetworkParams(void *param_1,uint *param_2)

{
  BOOL BVar1;
  undefined4 uVar2;
  
                    /* 0x23a4  31  GetNetworkParams */
  FUN_c0485020();
  BVar1 = IsBadReadPtr(param_2,4);
  if (((BVar1 == 0) && (BVar1 = IsBadWritePtr(param_2,4), BVar1 == 0)) &&
     ((param_1 == (void *)0x0 || (BVar1 = IsBadWritePtr(param_1,0x248), BVar1 == 0)))) {
    uVar2 = FUN_c048ba7c(param_1,param_2);
  }
  else {
    uVar2 = 0x57;
  }
  return uVar2;
}



/* c0482448 GetAdaptersInfo */

/* Boundary evidence: original MIPS .pdata c0482448..c04824eb. Semantic name remains unreviewed. */

undefined4 GetAdaptersInfo(undefined4 *param_1,uint *param_2)

{
  BOOL BVar1;
  undefined4 uVar2;
  
                    /* 0x2448  16  GetAdaptersInfo */
  FUN_c0485020();
  BVar1 = IsBadReadPtr(param_2,4);
  if (((BVar1 == 0) && (BVar1 = IsBadWritePtr(param_2,4), BVar1 == 0)) &&
     ((param_1 == (undefined4 *)0x0 || (BVar1 = IsBadWritePtr(param_1,0x280), BVar1 == 0)))) {
    uVar2 = FUN_c048aec8(param_1,param_2);
  }
  else {
    uVar2 = 0x57;
  }
  return uVar2;
}



/* c04824ec GetPerAdapterInfo */

/* Boundary evidence: original MIPS .pdata c04824ec..c048259f. Semantic name remains unreviewed. */

undefined4 GetPerAdapterInfo(int param_1,void *param_2,uint *param_3)

{
  BOOL BVar1;
  undefined4 uVar2;
  
                    /* 0x24ec  33  GetPerAdapterInfo */
  FUN_c0485020();
  BVar1 = IsBadReadPtr(param_3,4);
  if (((BVar1 == 0) && (BVar1 = IsBadWritePtr(param_3,4), BVar1 == 0)) &&
     ((param_2 == (void *)0x0 || (BVar1 = IsBadWritePtr(param_2,0x34), BVar1 == 0)))) {
    uVar2 = FUN_c048b6d0(param_1,param_2,param_3);
  }
  else {
    uVar2 = 0x57;
  }
  return uVar2;
}



/* c04825a0 IpReleaseAddress */

/* Boundary evidence: original MIPS .pdata c04825a0..c048262f. Semantic name remains unreviewed. */

DWORD IpReleaseAddress(LPVOID param_1)

{
  DWORD DVar1;
  BOOL BVar2;
  DWORD local_18 [2];
  
                    /* 0x25a0  50  IpReleaseAddress */
  if ((param_1 == (LPVOID)0x0) || (BVar2 = IsBadReadPtr(param_1,0x104), BVar2 != 0)) {
    DVar1 = 0x57;
  }
  else {
    FUN_c0485020();
    local_18[1] = 0x104;
    local_18[0] = 0;
    DVar1 = FUN_c0482aa8(DAT_c048f5a8,0x128080,param_1,local_18 + 1,(LPVOID)0x0,local_18);
  }
  return DVar1;
}



/* c0482630 IpRenewAddress */

/* Boundary evidence: original MIPS .pdata c0482630..c04826bf. Semantic name remains unreviewed. */

DWORD IpRenewAddress(LPVOID param_1)

{
  DWORD DVar1;
  BOOL BVar2;
  DWORD local_18 [2];
  
                    /* 0x2630  51  IpRenewAddress */
  if ((param_1 == (LPVOID)0x0) || (BVar2 = IsBadReadPtr(param_1,0x104), BVar2 != 0)) {
    DVar1 = 0x57;
  }
  else {
    FUN_c0485020();
    local_18[1] = 0x104;
    local_18[0] = 0;
    DVar1 = FUN_c0482aa8(DAT_c048f5a8,0x12807c,param_1,local_18 + 1,(LPVOID)0x0,local_18);
  }
  return DVar1;
}



/* c04826c0 SendARP */

/* Boundary evidence: original MIPS .pdata c04826c0..c048276b. Semantic name remains unreviewed. */

DWORD SendARP(undefined4 param_1,undefined4 param_2,LPVOID param_3,LPDWORD param_4)

{
  BOOL BVar1;
  DWORD DVar2;
  DWORD local_20 [2];
  undefined4 local_18;
  undefined4 local_14;
  
                    /* 0x26c0  55  SendARP */
  local_20[0] = 8;
  local_18 = param_1;
  local_14 = param_2;
  BVar1 = IsBadWritePtr(param_3,4);
  if ((BVar1 == 0) && (BVar1 = IsBadWritePtr(param_4,4), BVar1 == 0)) {
    FUN_c0485020();
    DVar2 = FUN_c0482aa8(DAT_c048f5b4,0x12003c,&local_18,local_20,param_3,param_4);
  }
  else {
    DVar2 = 0x57;
  }
  return DVar2;
}



/* c048276c FUN_c048276c */

/* Boundary evidence: original MIPS .pdata c048276c..c04827c3. Semantic name remains unreviewed. */

bool FUN_c048276c(void)

{
  int iVar1;
  WSADATA WStack_1a0;
  uint local_10;
  
  local_10 = DAT_c048f418;
  iVar1 = WSAStartup(0x101,&WStack_1a0);
  if (iVar1 == 0) {
    FUN_c048e238(local_10);
  }
  else {
    FUN_c048e238(local_10);
  }
  return iVar1 == 0;
}



/* c04827c4 NotifyRouteChange */

/* Boundary evidence: original MIPS .pdata c04827c4..c04827e3. Semantic name remains unreviewed. */

void NotifyRouteChange(undefined4 *param_1,int param_2)

{
                    /* 0x27c4  54  NotifyRouteChange */
  FUN_c04822ac(param_1,param_2,L"IP_ROUTE_CHANGE_EVENT");
  return;
}



/* c04827e4 GetAdaptersAddresses */

/* Boundary evidence: original MIPS .pdata c04827e4..c048294b. Semantic name remains unreviewed. */

DWORD GetAdaptersAddresses(int param_1,uint param_2,int param_3,void *param_4,uint *param_5)

{
  bool bVar1;
  BOOL BVar2;
  undefined3 extraout_var;
  DWORD DVar3;
  int iVar4;
  
                    /* 0x27e4  15  GetAdaptersAddresses */
  FUN_c0485020();
  BVar2 = IsBadReadPtr(param_5,4);
  if ((((BVar2 == 0) && (BVar2 = IsBadWritePtr(param_5,4), BVar2 == 0)) && (param_3 == 0)) &&
     ((param_4 == (void *)0x0 || (BVar2 = IsBadWritePtr(param_4,0x98), BVar2 == 0)))) {
    bVar1 = FUN_c048276c();
    if (CONCAT31(extraout_var,bVar1) == 0) {
      DVar3 = 0x32;
    }
    else {
      iVar4 = 0;
      do {
        DVar3 = FUN_c048b17c(param_1,param_2,param_4,param_5);
        if (((DVar3 == 0) || (DVar3 == 0xe8)) || ((DVar3 == 0x6f || (DVar3 == 0x57)))) break;
        Sleep(100);
        iVar4 = iVar4 + 1;
      } while (iVar4 < 5);
      WSACleanup();
    }
  }
  else {
    DVar3 = 0x57;
  }
  return DVar3;
}



/* c048294c FUN_c048294c */

undefined4 FUN_c048294c(int param_1)

{
  undefined4 uVar1;
  
  if (param_1 == 9) {
LAB_c04829a0:
    uVar1 = 0x7a;
  }
  else {
    if (param_1 != 0x1f) {
      if (param_1 == 0x21) goto LAB_c04829a0;
      if (param_1 != 0xfe) {
        if (param_1 != 0xff) {
          return 0x57;
        }
        return 0xa2;
      }
    }
    uVar1 = 1;
  }
  return uVar1;
}



/* c04829ac FUN_c04829ac */

/* Boundary evidence: original MIPS .pdata c04829ac..c0482aa7. Semantic name remains unreviewed. */

DWORD FUN_c04829ac(int param_1,LPVOID param_2,DWORD *param_3,LPVOID param_4,LPDWORD param_5)

{
  BOOL BVar1;
  DWORD DVar2;
  int iVar3;
  
  if (param_1 == 2) {
    iVar3 = WSAControl(6,0,param_2,param_3,param_4,param_5);
    if (iVar3 != 0) {
      DVar2 = FUN_c048294c(iVar3);
      return DVar2;
    }
  }
  else {
    if (param_1 != 0x17) {
      return 0x32;
    }
    FUN_c0485020();
    BVar1 = DeviceIoControl(DAT_c048f598,0x120003,param_2,*param_3,param_4,*param_5,param_5,
                            (LPOVERLAPPED)0x0);
    if (BVar1 == 0) {
      DVar2 = GetLastError();
      *param_5 = 0;
      return DVar2;
    }
  }
  return 0;
}



/* c0482aa8 FUN_c0482aa8 */

/* Boundary evidence: original MIPS .pdata c0482aa8..c0482b0b. Semantic name remains unreviewed. */

DWORD FUN_c0482aa8(HANDLE param_1,DWORD param_2,LPVOID param_3,DWORD *param_4,LPVOID param_5,
                  LPDWORD param_6)

{
  BOOL BVar1;
  DWORD DVar2;
  
  BVar1 = DeviceIoControl(param_1,param_2,param_3,*param_4,param_5,*param_6,param_6,
                          (LPOVERLAPPED)0x0);
  if (BVar1 == 0) {
    DVar2 = GetLastError();
  }
  else {
    DVar2 = 0;
  }
  return DVar2;
}



/* c0482b0c FUN_c0482b0c */

/* Boundary evidence: original MIPS .pdata c0482b0c..c0482be7. Semantic name remains unreviewed. */

DWORD FUN_c0482b0c(int param_1)

{
  HANDLE pvVar1;
  wchar_t *lpFileName;
  DWORD DVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  
  DVar2 = 0;
  if (param_1 == 2) {
    lpFileName = L"IPD0:";
    puVar3 = &DAT_c048f5a8;
    puVar4 = &DAT_c048f5b4;
  }
  else {
    if (param_1 != 0x17) {
      return 0x57;
    }
    lpFileName = L"IP60:";
    puVar3 = &DAT_c048f5a0;
    puVar4 = &DAT_c048f598;
  }
  pvVar1 = CreateFileW(lpFileName,0xc0000000,3,(LPSECURITY_ATTRIBUTES)0x0,3,0x80,(HANDLE)0x0);
  *puVar3 = pvVar1;
  if (pvVar1 == (HANDLE)0xffffffff) {
    DVar2 = GetLastError();
  }
  *puVar4 = *puVar3;
  return DVar2;
}



/* c0482be8 FUN_c0482be8 */

/* Boundary evidence: original MIPS .pdata c0482be8..c0482d47. Semantic name remains unreviewed. */

DWORD FUN_c0482be8(uint param_1,uint param_2,undefined4 *param_3)

{
  undefined1 *puVar1;
  uint uVar2;
  DWORD DVar3;
  DWORD local_90 [3];
  undefined4 local_84;
  undefined4 local_80;
  undefined4 local_7c;
  undefined4 local_78;
  undefined4 local_74;
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_50;
  undefined1 auStack_4c [4];
  undefined1 auStack_48 [4];
  undefined1 auStack_44 [4];
  undefined1 auStack_40 [4];
  undefined4 local_3c;
  undefined1 auStack_38 [4];
  undefined1 auStack_34 [28];
  uint local_18;
  
  local_18 = DAT_c048f418;
  local_90[0] = 0x33;
  FUN_c0485020();
  if (DAT_c048f5a4 == 0) {
    FUN_c048e238(local_18);
    DVar3 = 0x32;
  }
  else {
    local_3c = 1;
    local_50 = 0x301;
    puVar1 = auStack_38 + 3;
    uVar2 = (uint)puVar1 & 3;
    *(uint *)(puVar1 + -uVar2) =
         *(uint *)(puVar1 + -uVar2) & -1 << (uVar2 + 1) * 8 | param_1 >> (3 - uVar2) * 8;
    puVar1 = auStack_34 + 3;
    uVar2 = (uint)puVar1 & 3;
    *(uint *)(puVar1 + -uVar2) =
         *(uint *)(puVar1 + -uVar2) & -1 << (uVar2 + 1) * 8 | param_2 >> (3 - uVar2) * 8;
    puVar1 = auStack_4c + 3;
    uVar2 = (uint)puVar1 & 3;
    *(uint *)(puVar1 + -uVar2) =
         *(uint *)(puVar1 + -uVar2) & -1 << (uVar2 + 1) * 8 | 0U >> (3 - uVar2) * 8;
    puVar1 = auStack_48 + 3;
    uVar2 = (uint)puVar1 & 3;
    *(uint *)(puVar1 + -uVar2) =
         *(uint *)(puVar1 + -uVar2) & -1 << (uVar2 + 1) * 8 | 0x200U >> (3 - uVar2) * 8;
    puVar1 = auStack_44 + 3;
    uVar2 = (uint)puVar1 & 3;
    *(uint *)(puVar1 + -uVar2) =
         *(uint *)(puVar1 + -uVar2) & -1 << (uVar2 + 1) * 8 | 0x100U >> (3 - uVar2) * 8;
    puVar1 = auStack_40 + 3;
    uVar2 = (uint)puVar1 & 3;
    *(uint *)(puVar1 + -uVar2) =
         *(uint *)(puVar1 + -uVar2) & -1 << (uVar2 + 1) * 8 | 0x104U >> (3 - uVar2) * 8;
    auStack_4c = (undefined1  [4])0x0;
    auStack_48 = (undefined1  [4])0x200;
    auStack_44 = (undefined1  [4])0x100;
    auStack_40 = (undefined1  [4])0x104;
    local_90[1] = 0x34;
    auStack_38 = (undefined1  [4])param_1;
    auStack_34._0_4_ = param_2;
    DVar3 = FUN_c04829ac(2,&local_50,local_90,local_90 + 2,local_90 + 1);
    *param_3 = local_90[2];
    param_3[4] = local_84;
    param_3[9] = local_80;
    param_3[10] = local_7c;
    param_3[0xb] = local_78;
    param_3[0xc] = local_74;
    param_3[0xd] = local_5c;
    param_3[3] = local_70;
    param_3[5] = local_6c;
    param_3[6] = local_68;
    param_3[7] = local_64;
    param_3[1] = local_60;
    param_3[8] = 0;
    param_3[2] = 0;
    FUN_c048e238(local_18);
  }
  return DVar3;
}



/* c0482d48 FUN_c0482d48 */

/* Boundary evidence: original MIPS .pdata c0482d48..c0482e27. Semantic name remains unreviewed. */

LPVOID FUN_c0482d48(uint *param_1)

{
  LPVOID lpMem;
  DWORD DVar1;
  DWORD local_40 [7];
  undefined1 auStack_24 [20];
  
  *param_1 = 0;
  local_40[1] = 0x24;
  local_40[0] = 0x1000;
  lpMem = HeapAlloc(DAT_c048f5d4,0,0x1000);
  if (lpMem != (LPVOID)0x0) {
    local_40[2] = 0;
    local_40[3] = 0;
    local_40[4] = 0x100;
    local_40[5] = 0x100;
    local_40[6] = 0;
    memset(auStack_24,0,0x10);
    DVar1 = FUN_c04829ac(2,local_40 + 2,local_40 + 1,lpMem,local_40);
    if (DVar1 == 0) {
      *param_1 = local_40[0] >> 3;
      return lpMem;
    }
    HeapFree(DAT_c048f5d4,0,lpMem);
  }
  return (LPVOID)0x0;
}



/* c0482e28 FUN_c0482e28 */

/* WARNING: Type propagation algorithm not settling */
/* Boundary evidence: original MIPS .pdata c0482e28..c0482fab. Semantic name remains unreviewed. */

DWORD FUN_c0482e28(int param_1,undefined4 param_2,undefined2 *param_3)

{
  undefined4 *lpMem;
  int iVar1;
  DWORD DVar2;
  DWORD local_48 [4];
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined1 auStack_2c [20];
  
  if (param_1 == 0) {
    local_48[1] = 0x24;
    local_48[2] = 0x200;
    local_38 = 0x200;
    local_34 = 0x100;
    local_30 = 1;
    local_48[0] = 0x15c;
    local_48[3] = param_2;
    memset(auStack_2c,0,0x10);
    *param_3 = 0;
    *(undefined1 *)(param_3 + 0x12e) = 0;
    DVar2 = FUN_c04829ac(2,local_48 + 2,local_48 + 1,param_3 + 0x100,local_48);
  }
  else if (param_1 == 1) {
    local_48[1] = 0x7b;
    lpMem = HeapAlloc(DAT_c048f5d4,0,0x7b);
    if (lpMem == (undefined4 *)0x0) {
      DVar2 = 8;
    }
    else {
      lpMem[2] = 0x200;
      lpMem[3] = 0x100;
      *lpMem = 0x200;
      lpMem[4] = 1;
      lpMem[1] = param_2;
      lpMem[5] = 0x60;
      local_48[0] = 0;
      memcpy(lpMem + 6,param_3 + 0x100,0x60);
      iVar1 = WSAControl(6,1,lpMem,local_48 + 1,0,local_48);
      if (iVar1 == 0) {
        DVar2 = 0;
      }
      else {
        DVar2 = FUN_c048294c(iVar1);
      }
      HeapFree(DAT_c048f5d4,0,lpMem);
    }
  }
  else {
    DVar2 = 0x57;
  }
  return DVar2;
}



/* c0482fac FUN_c0482fac */

/* WARNING: Type propagation algorithm not settling */
/* Boundary evidence: original MIPS .pdata c0482fac..c04830a3. Semantic name remains unreviewed. */

DWORD FUN_c0482fac(uint *param_1,int param_2,int param_3)

{
  DWORD DVar1;
  uint _NumOfElements;
  uint local_40;
  DWORD local_3c [6];
  undefined1 auStack_24 [20];
  
  FUN_c0485020();
  if (DAT_c048f5a4 == 0) {
    DVar1 = 0x32;
  }
  else {
    local_3c[1] = 0x301;
    local_3c[2] = 0;
    local_3c[3] = 0x200;
    local_3c[4] = 0x100;
    local_3c[5] = 0x102;
    memset(auStack_24,0,0x10);
    local_40 = param_2 - 4;
    local_3c[0] = 0x24;
    DVar1 = FUN_c04829ac(2,local_3c + 1,local_3c,param_1 + 1,&local_40);
    if (DVar1 == 0) {
      _NumOfElements = local_40 / 0x18;
      *param_1 = _NumOfElements;
      if ((_NumOfElements != 0) && (param_3 != 0)) {
        qsort(param_1 + 1,_NumOfElements,0x18,(_PtFuncCompare *)&LAB_c048c65c);
      }
      DVar1 = 0;
    }
  }
  return DVar1;
}



/* c04830a4 FUN_c04830a4 */

/* WARNING: Type propagation algorithm not settling */
/* Boundary evidence: original MIPS .pdata c04830a4..c048319b. Semantic name remains unreviewed. */

DWORD FUN_c04830a4(uint *param_1,int param_2,int param_3)

{
  DWORD DVar1;
  uint _NumOfElements;
  uint local_40;
  DWORD local_3c [6];
  undefined1 auStack_24 [20];
  
  FUN_c0485020();
  if (DAT_c048f5a4 == 0) {
    DVar1 = 0x32;
  }
  else {
    local_3c[1] = 0x400;
    local_3c[2] = 0;
    local_3c[3] = 0x200;
    local_3c[4] = 0x100;
    local_3c[5] = 0x101;
    memset(auStack_24,0,0x10);
    local_40 = param_2 - 4;
    local_3c[0] = 0x24;
    DVar1 = FUN_c04829ac(2,local_3c + 1,local_3c,param_1 + 1,&local_40);
    if (DVar1 == 0) {
      _NumOfElements = local_40 / 0x14;
      *param_1 = _NumOfElements;
      if ((_NumOfElements != 0) && (param_3 != 0)) {
        qsort(param_1 + 1,_NumOfElements,0x14,FUN_c048c6c0);
      }
      DVar1 = 0;
    }
  }
  return DVar1;
}



/* c048319c FUN_c048319c */

/* Boundary evidence: original MIPS .pdata c048319c..c0483297. Semantic name remains unreviewed. */

undefined4 FUN_c048319c(void *param_1)

{
  undefined1 *puVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 local_50;
  undefined1 auStack_4c [4];
  undefined1 auStack_48 [4];
  undefined1 auStack_44 [4];
  undefined1 auStack_40 [4];
  undefined1 auStack_3c [4];
  undefined1 auStack_38 [4];
  undefined4 local_34;
  undefined1 auStack_30 [28];
  uint local_14;
  
  local_14 = DAT_c048f418;
  local_50 = 0x2f;
  FUN_c0485020();
  if (DAT_c048f5a4 == 0) {
    FUN_c048e238(local_14);
    uVar4 = 0x32;
  }
  else {
    puVar1 = auStack_40 + 3;
    uVar2 = (uint)puVar1 & 3;
    *(uint *)(puVar1 + -uVar2) =
         *(uint *)(puVar1 + -uVar2) & -1 << (uVar2 + 1) * 8 | 0x200U >> (3 - uVar2) * 8;
    puVar1 = auStack_3c + 3;
    uVar2 = (uint)puVar1 & 3;
    *(uint *)(puVar1 + -uVar2) =
         *(uint *)(puVar1 + -uVar2) & -1 << (uVar2 + 1) * 8 | 0x100U >> (3 - uVar2) * 8;
    puVar1 = auStack_48 + 3;
    uVar2 = (uint)puVar1 & 3;
    *(uint *)(puVar1 + -uVar2) =
         *(uint *)(puVar1 + -uVar2) & -1 << (uVar2 + 1) * 8 | 0x400U >> (3 - uVar2) * 8;
    puVar1 = auStack_38 + 3;
    uVar2 = (uint)puVar1 & 3;
    *(uint *)(puVar1 + -uVar2) =
         *(uint *)(puVar1 + -uVar2) & -1 << (uVar2 + 1) * 8 | 0x101U >> (3 - uVar2) * 8;
    puVar1 = auStack_44 + 3;
    uVar2 = (uint)puVar1 & 3;
    *(uint *)(puVar1 + -uVar2) =
         *(uint *)(puVar1 + -uVar2) & -1 << (uVar2 + 1) * 8 | 0U >> (3 - uVar2) * 8;
    auStack_40 = (undefined1  [4])0x200;
    auStack_3c = (undefined1  [4])0x100;
    auStack_48 = (undefined1  [4])0x400;
    auStack_38 = (undefined1  [4])0x101;
    auStack_44 = (undefined1  [4])0x0;
    memcpy(auStack_30,param_1,0x14);
    local_34 = 0x14;
    iVar3 = WSAControl(6,1,auStack_48,&local_50,0,auStack_4c);
    if (iVar3 == 0) {
      uVar4 = 0;
    }
    else {
      uVar4 = FUN_c048294c(iVar3);
    }
    FUN_c048e238(local_14);
  }
  return uVar4;
}



/* c0483298 FUN_c0483298 */

/* WARNING: Type propagation algorithm not settling */
/* Boundary evidence: original MIPS .pdata c0483298..c0483387. Semantic name remains unreviewed. */

DWORD FUN_c0483298(uint *param_1,int param_2,int param_3)

{
  DWORD DVar1;
  uint _NumOfElements;
  uint local_40;
  DWORD local_3c [6];
  undefined1 auStack_24 [20];
  
  FUN_c0485020();
  if (DAT_c048f5a4 == 0) {
    DVar1 = 0x32;
  }
  else {
    local_3c[1] = 0x401;
    local_3c[2] = 0;
    local_3c[3] = 0x200;
    local_3c[4] = 0x100;
    local_3c[5] = 0x101;
    memset(auStack_24,0,0x10);
    local_40 = param_2 - 4;
    local_3c[0] = 0x24;
    DVar1 = FUN_c04829ac(2,local_3c + 1,local_3c,param_1 + 1,&local_40);
    if (DVar1 == 0) {
      _NumOfElements = local_40 >> 3;
      *param_1 = _NumOfElements;
      if ((_NumOfElements != 0) && (param_3 != 0)) {
        qsort(param_1 + 1,_NumOfElements,8,FUN_c048c820);
      }
      DVar1 = 0;
    }
  }
  return DVar1;
}



/* c0483388 FUN_c0483388 */

/* Boundary evidence: original MIPS .pdata c0483388..c04835b7. Semantic name remains unreviewed. */

undefined4 FUN_c0483388(size_t *param_1,int param_2,int param_3,int param_4)

{
  DWORD DVar1;
  undefined4 uVar2;
  size_t _NumOfElements;
  uint uVar3;
  int iVar4;
  size_t *psVar5;
  uint local_60;
  int local_5c;
  DWORD local_58 [2];
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined1 auStack_3c [20];
  
  FUN_c0485020();
  if (DAT_c048f5a4 == 0) {
    uVar2 = 0x32;
  }
  else {
    _NumOfElements = 0;
    uVar2 = 0;
    memset(auStack_3c,0,0x10);
    local_48 = 0x200;
    local_44 = 0x100;
    local_50 = 0x280;
    local_5c = (int)param_1 + param_2;
    local_40 = 0x101;
    local_58[0] = 0x24;
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c048f5c0);
    if ((((param_4 == 0) && (DAT_c048f5b8 != 0)) &&
        (DVar1 = GetTickCount(), DVar1 - DAT_c048f5b8 < 0xea61)) ||
       (DVar1 = FUN_c048cf1c(), DVar1 == 0)) {
      uVar3 = 0;
      if (DAT_c048f594 != 0) {
        iVar4 = 0;
        psVar5 = param_1 + 1;
        do {
          local_60 = local_5c - (int)psVar5;
          if (local_60 < 0x18) {
            uVar2 = 0xea;
            break;
          }
          local_4c = *(undefined4 *)(iVar4 + DAT_c048f5dc);
          memset(auStack_3c,0,0x10);
          DVar1 = FUN_c04829ac(2,&local_50,local_58,psVar5,&local_60);
          if (DVar1 == 0) {
            psVar5 = (size_t *)(local_60 + (int)psVar5);
            _NumOfElements = local_60 / 0x18 + _NumOfElements;
          }
          else {
            uVar2 = 0xea;
          }
          uVar3 = uVar3 + 1;
          iVar4 = iVar4 + 4;
        } while (uVar3 < DAT_c048f594);
      }
      *param_1 = _NumOfElements;
      if ((_NumOfElements != 0) && (param_3 != 0)) {
        qsort(param_1 + 1,_NumOfElements,0x18,(_PtFuncCompare *)&LAB_c048c8e0);
      }
    }
    else {
      uVar2 = 0x3eb;
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c048f5c0);
  }
  return uVar2;
}



/* c04835b8 FUN_c04835b8 */

/* Boundary evidence: original MIPS .pdata c04835b8..c04836af. Semantic name remains unreviewed. */

DWORD FUN_c04835b8(LPVOID param_1,int param_2)

{
  DWORD DVar1;
  DWORD local_48 [7];
  undefined1 auStack_2c [20];
  
  if ((param_2 == 2) || (param_2 == 0x17)) {
    FUN_c0485020();
    if (((param_2 == 2) && (DAT_c048f5a4 == 0)) || ((param_2 == 0x17 && (DAT_c048f5ac == 0)))) {
      DVar1 = 0x32;
    }
    else {
      local_48[1] = 0x24;
      local_48[0] = 0x5c;
      local_48[2] = 0x301;
      local_48[3] = 0;
      local_48[4] = 0x200;
      local_48[5] = 0x100;
      local_48[6] = 1;
      memset(auStack_2c,0,0x10);
      DVar1 = FUN_c04829ac(param_2,local_48 + 2,local_48 + 1,param_1,local_48);
    }
  }
  else {
    DVar1 = 0x57;
  }
  return DVar1;
}



/* c04836b0 FUN_c04836b0 */

/* Boundary evidence: original MIPS .pdata c04836b0..c048374f. Semantic name remains unreviewed. */

DWORD FUN_c04836b0(LPVOID param_1)

{
  DWORD DVar1;
  DWORD local_38 [7];
  undefined1 auStack_1c [20];
  
  FUN_c0485020();
  if (DAT_c048f5a4 == 0) {
    DVar1 = 0x32;
  }
  else {
    local_38[1] = 0x24;
    local_38[0] = 0x5c;
    local_38[2] = 0x301;
    local_38[3] = 0;
    local_38[4] = 0x200;
    local_38[5] = 0x100;
    local_38[6] = 1;
    memset(auStack_1c,0,0x10);
    DVar1 = FUN_c04829ac(2,local_38 + 2,local_38 + 1,param_1,local_38);
  }
  return DVar1;
}



/* c0483750 FUN_c0483750 */

/* Boundary evidence: original MIPS .pdata c0483750..c048384b. Semantic name remains unreviewed. */

undefined4 FUN_c0483750(void *param_1)

{
  undefined1 *puVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 local_98;
  undefined1 auStack_94 [4];
  undefined1 auStack_90 [4];
  undefined1 auStack_8c [4];
  undefined1 auStack_88 [4];
  undefined1 auStack_84 [4];
  undefined1 auStack_80 [4];
  undefined4 local_7c;
  undefined1 auStack_78 [100];
  uint local_14;
  
  local_14 = DAT_c048f418;
  local_98 = 0x77;
  FUN_c0485020();
  if (DAT_c048f5a4 == 0) {
    FUN_c048e238(local_14);
    uVar4 = 0x32;
  }
  else {
    puVar1 = auStack_88 + 3;
    uVar2 = (uint)puVar1 & 3;
    *(uint *)(puVar1 + -uVar2) =
         *(uint *)(puVar1 + -uVar2) & -1 << (uVar2 + 1) * 8 | 0x200U >> (3 - uVar2) * 8;
    puVar1 = auStack_84 + 3;
    uVar2 = (uint)puVar1 & 3;
    *(uint *)(puVar1 + -uVar2) =
         *(uint *)(puVar1 + -uVar2) & -1 << (uVar2 + 1) * 8 | 0x100U >> (3 - uVar2) * 8;
    puVar1 = auStack_90 + 3;
    uVar2 = (uint)puVar1 & 3;
    *(uint *)(puVar1 + -uVar2) =
         *(uint *)(puVar1 + -uVar2) & -1 << (uVar2 + 1) * 8 | 0x301U >> (3 - uVar2) * 8;
    puVar1 = auStack_80 + 3;
    uVar2 = (uint)puVar1 & 3;
    *(uint *)(puVar1 + -uVar2) =
         *(uint *)(puVar1 + -uVar2) & -1 << (uVar2 + 1) * 8 | 1U >> (3 - uVar2) * 8;
    puVar1 = auStack_8c + 3;
    uVar2 = (uint)puVar1 & 3;
    *(uint *)(puVar1 + -uVar2) =
         *(uint *)(puVar1 + -uVar2) & -1 << (uVar2 + 1) * 8 | 0U >> (3 - uVar2) * 8;
    auStack_88 = (undefined1  [4])0x200;
    auStack_84 = (undefined1  [4])0x100;
    auStack_90 = (undefined1  [4])0x301;
    auStack_80 = (undefined1  [4])0x1;
    auStack_8c = (undefined1  [4])0x0;
    memcpy(auStack_78,param_1,0x5c);
    local_7c = 0x5c;
    iVar3 = WSAControl(6,1,auStack_90,&local_98,0,auStack_94);
    if (iVar3 == 0) {
      uVar4 = 0;
    }
    else {
      uVar4 = FUN_c048294c(iVar3);
    }
    FUN_c048e238(local_14);
  }
  return uVar4;
}



/* c048384c FUN_c048384c */

/* Boundary evidence: original MIPS .pdata c048384c..c048395b. Semantic name remains unreviewed. */

DWORD FUN_c048384c(LPVOID param_1,int param_2)

{
  DWORD DVar1;
  DWORD local_48 [3];
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined1 auStack_2c [20];
  
  if ((param_2 == 2) || (param_2 == 0x17)) {
    FUN_c0485020();
    if (((param_2 == 2) && (DAT_c048f5a4 == 0)) || ((param_2 == 0x17 && (DAT_c048f5ac == 0)))) {
      DVar1 = 0x32;
    }
    else {
      local_48[1] = 0x24;
      local_3c = 0;
      local_38 = 0x200;
      local_34 = 0x100;
      if (param_2 == 2) {
        local_30 = 1;
        local_48[2] = 0x380;
        local_48[0] = 0x68;
      }
      else {
        local_30 = 4;
        local_48[2] = 0x301;
        local_48[0] = 0x810;
      }
      memset(auStack_2c,0,0x10);
      DVar1 = FUN_c04829ac(param_2,local_48 + 2,local_48 + 1,param_1,local_48);
    }
  }
  else {
    DVar1 = 0x57;
  }
  return DVar1;
}



/* c048395c FUN_c048395c */

/* Boundary evidence: original MIPS .pdata c048395c..c04839fb. Semantic name remains unreviewed. */

DWORD FUN_c048395c(LPVOID param_1)

{
  DWORD DVar1;
  DWORD local_38 [7];
  undefined1 auStack_1c [20];
  
  FUN_c0485020();
  if (DAT_c048f5a4 == 0) {
    DVar1 = 0x32;
  }
  else {
    local_38[1] = 0x24;
    local_38[3] = 0;
    local_38[4] = 0x200;
    local_38[5] = 0x100;
    local_38[2] = 0x380;
    local_38[6] = 1;
    local_38[0] = 0x68;
    memset(auStack_1c,0,0x10);
    DVar1 = FUN_c04829ac(2,local_38 + 2,local_38 + 1,param_1,local_38);
  }
  return DVar1;
}



/* c04839fc FUN_c04839fc */

/* Boundary evidence: original MIPS .pdata c04839fc..c0483af3. Semantic name remains unreviewed. */

DWORD FUN_c04839fc(LPVOID param_1,int param_2)

{
  DWORD DVar1;
  DWORD local_48 [7];
  undefined1 auStack_2c [20];
  
  if ((param_2 == 2) || (param_2 == 0x17)) {
    FUN_c0485020();
    if (((param_2 == 2) && (DAT_c048f5a4 == 0)) || ((param_2 == 0x17 && (DAT_c048f5ac == 0)))) {
      DVar1 = 0x32;
    }
    else {
      local_48[1] = 0x24;
      local_48[0] = 0x14;
      local_48[2] = 0x401;
      local_48[3] = 0;
      local_48[4] = 0x200;
      local_48[5] = 0x100;
      local_48[6] = 1;
      memset(auStack_2c,0,0x10);
      DVar1 = FUN_c04829ac(param_2,local_48 + 2,local_48 + 1,param_1,local_48);
    }
  }
  else {
    DVar1 = 0x57;
  }
  return DVar1;
}



/* c0483af4 FUN_c0483af4 */

/* Boundary evidence: original MIPS .pdata c0483af4..c0483beb. Semantic name remains unreviewed. */

DWORD FUN_c0483af4(LPVOID param_1,int param_2)

{
  DWORD DVar1;
  DWORD local_48 [7];
  undefined1 auStack_2c [20];
  
  if ((param_2 == 2) || (param_2 == 0x17)) {
    FUN_c0485020();
    if (((param_2 == 2) && (DAT_c048f5a4 == 0)) || ((param_2 == 0x17 && (DAT_c048f5ac == 0)))) {
      DVar1 = 0x32;
    }
    else {
      local_48[1] = 0x24;
      local_48[0] = 0x3c;
      local_48[2] = 0x400;
      local_48[3] = 0;
      local_48[4] = 0x200;
      local_48[5] = 0x100;
      local_48[6] = 1;
      memset(auStack_2c,0,0x10);
      DVar1 = FUN_c04829ac(param_2,local_48 + 2,local_48 + 1,param_1,local_48);
    }
  }
  else {
    DVar1 = 0x57;
  }
  return DVar1;
}



/* c0483bec FUN_c0483bec */

/* Boundary evidence: original MIPS .pdata c0483bec..c0483dbb. Semantic name remains unreviewed. */

undefined4 FUN_c0483bec(uint *param_1,int param_2)

{
  undefined1 *puVar1;
  uint uVar2;
  DWORD DVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 local_60;
  undefined4 local_5c;
  undefined1 auStack_58 [4];
  int local_54;
  undefined1 auStack_50 [4];
  undefined1 auStack_4c [4];
  undefined1 auStack_48 [4];
  undefined1 auStack_44 [4];
  undefined1 auStack_40 [32];
  uint local_20;
  
  local_20 = DAT_c048f418;
  local_60 = 0x33;
  FUN_c0485020();
  if (DAT_c048f5a4 == 0) {
    FUN_c048e238(local_20);
    uVar5 = 0x32;
  }
  else {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c048f5c0);
    if ((((param_2 != 0) || (DAT_c048f5b8 == 0)) ||
        (DVar3 = GetTickCount(), 60000 < DVar3 - DAT_c048f5b8)) ||
       (iVar4 = FUN_c048ccf4(*param_1), iVar4 == -1)) {
      DVar3 = FUN_c048cf1c();
      if (DVar3 != 0) {
        LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c048f5c0);
        FUN_c048e238(local_20);
        return 0x3eb;
      }
      iVar4 = FUN_c048ccf4(*param_1);
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c048f5c0);
    if (iVar4 == -1) {
      FUN_c048e238(local_20);
      uVar5 = 0xd;
    }
    else {
      puVar1 = auStack_50 + 3;
      uVar2 = (uint)puVar1 & 3;
      *(uint *)(puVar1 + -uVar2) =
           *(uint *)(puVar1 + -uVar2) & -1 << (uVar2 + 1) * 8 | 0x200U >> (3 - uVar2) * 8;
      puVar1 = auStack_58 + 3;
      uVar2 = (uint)puVar1 & 3;
      *(uint *)(puVar1 + -uVar2) =
           *(uint *)(puVar1 + -uVar2) & -1 << (uVar2 + 1) * 8 | 0x280U >> (3 - uVar2) * 8;
      puVar1 = auStack_4c + 3;
      uVar2 = (uint)puVar1 & 3;
      *(uint *)(puVar1 + -uVar2) =
           *(uint *)(puVar1 + -uVar2) & -1 << (uVar2 + 1) * 8 | 0x100U >> (3 - uVar2) * 8;
      puVar1 = auStack_48 + 3;
      uVar2 = (uint)puVar1 & 3;
      *(uint *)(puVar1 + -uVar2) =
           *(uint *)(puVar1 + -uVar2) & -1 << (uVar2 + 1) * 8 | 0x101U >> (3 - uVar2) * 8;
      auStack_50 = (undefined1  [4])0x200;
      auStack_58 = (undefined1  [4])0x280;
      auStack_4c = (undefined1  [4])0x100;
      auStack_48 = (undefined1  [4])0x101;
      local_54 = iVar4;
      memcpy(auStack_40,param_1,0x18);
      puVar1 = auStack_44 + 3;
      uVar2 = (uint)puVar1 & 3;
      *(uint *)(puVar1 + -uVar2) =
           *(uint *)(puVar1 + -uVar2) & -1 << (uVar2 + 1) * 8 | 0x18U >> (3 - uVar2) * 8;
      local_5c = 0;
      auStack_44 = (undefined1  [4])0x18;
      iVar4 = WSAControl(6,1,auStack_58,&local_60,0,&local_5c);
      if (iVar4 == 0) {
        uVar5 = 0;
      }
      else {
        uVar5 = FUN_c048294c(iVar4);
      }
      FUN_c048e238(local_20);
    }
  }
  return uVar5;
}



/* c0483dbc FUN_c0483dbc */

/* Boundary evidence: original MIPS .pdata c0483dbc..c0483e23. Semantic name remains unreviewed. */

DWORD FUN_c0483dbc(undefined4 param_1)

{
  DWORD DVar1;
  undefined4 local_res0 [4];
  DWORD local_10 [2];
  
  local_10[1] = 4;
  local_10[0] = 0;
  local_res0[0] = param_1;
  FUN_c0485020();
  if (DAT_c048f5a4 == 0) {
    DVar1 = 0x32;
  }
  else {
    DVar1 = FUN_c0482aa8(DAT_c048f5a8,0x128050,local_res0,local_10 + 1,(LPVOID)0x0,local_10);
  }
  return DVar1;
}



/* c0483e24 FUN_c0483e24 */

/* Boundary evidence: original MIPS .pdata c0483e24..c048402b. Semantic name remains unreviewed. */

undefined4 FUN_c0483e24(uint param_1,uint param_2,uint param_3,int param_4,int param_5)

{
  undefined1 *puVar1;
  uint uVar2;
  DWORD DVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  int local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined1 auStack_40 [4];
  undefined1 auStack_3c [4];
  undefined1 auStack_38 [4];
  undefined1 auStack_34 [4];
  undefined1 auStack_30 [12];
  uint local_24;
  
  local_24 = DAT_c048f418;
  local_58 = 0x27;
  FUN_c0485020();
  if (DAT_c048f5a4 == 0) {
    FUN_c048e238(local_24);
    uVar5 = 0x32;
  }
  else {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c048f5c0);
    if ((((param_5 != 0) || (DAT_c048f5b8 == 0)) ||
        (DVar3 = GetTickCount(), 60000 < DVar3 - DAT_c048f5b8)) ||
       (local_4c = FUN_c048ccf4(param_3), local_4c == -1)) {
      DVar3 = FUN_c048cf1c();
      if (DVar3 != 0) {
        LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c048f5c0);
        FUN_c048e238(local_24);
        return 0x3eb;
      }
      local_4c = FUN_c048ccf4(param_3);
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c048f5c0);
    if (local_4c == -1) {
      FUN_c048e238(local_24);
      uVar5 = 0xd;
    }
    else {
      local_50 = 0x280;
      puVar1 = auStack_40 + 3;
      uVar2 = (uint)puVar1 & 3;
      *(uint *)(puVar1 + -uVar2) =
           *(uint *)(puVar1 + -uVar2) & -1 << (uVar2 + 1) * 8 | 0x101U >> (3 - uVar2) * 8;
      auStack_38 = (undefined1  [4])0x1;
      local_44 = 0x100;
      local_48 = 0x300;
      auStack_40 = (undefined1  [4])0x101;
      if (param_4 == 0) {
        auStack_38 = (undefined1  [4])0x2;
      }
      puVar1 = auStack_38 + 3;
      uVar2 = (uint)puVar1 & 3;
      *(uint *)(puVar1 + -uVar2) =
           *(uint *)(puVar1 + -uVar2) & -1 << (uVar2 + 1) * 8 | (uint)auStack_38 >> (3 - uVar2) * 8;
      puVar1 = auStack_34 + 3;
      uVar2 = (uint)puVar1 & 3;
      *(uint *)(puVar1 + -uVar2) =
           *(uint *)(puVar1 + -uVar2) & -1 << (uVar2 + 1) * 8 | param_1 >> (3 - uVar2) * 8;
      puVar1 = auStack_30 + 3;
      uVar2 = (uint)puVar1 & 3;
      *(uint *)(puVar1 + -uVar2) =
           *(uint *)(puVar1 + -uVar2) & -1 << (uVar2 + 1) * 8 | param_2 >> (3 - uVar2) * 8;
      puVar1 = auStack_3c + 3;
      uVar2 = (uint)puVar1 & 3;
      *(uint *)(puVar1 + -uVar2) =
           *(uint *)(puVar1 + -uVar2) & -1 << (uVar2 + 1) * 8 | 0xcU >> (3 - uVar2) * 8;
      auStack_3c = (undefined1  [4])0xc;
      local_54 = 0;
      auStack_34 = (undefined1  [4])param_1;
      auStack_30._0_4_ = param_2;
      iVar4 = WSAControl(6,1,&local_50,&local_58,0,&local_54);
      if (iVar4 == 0) {
        uVar5 = 0;
      }
      else {
        uVar5 = FUN_c048294c(iVar4);
      }
      FUN_c048e238(local_24);
    }
  }
  return uVar5;
}



/* c048402c FUN_c048402c */

/* Boundary evidence: original MIPS .pdata c048402c..c048419b. Semantic name remains unreviewed. */

DWORD FUN_c048402c(int *param_1)

{
  DWORD DVar1;
  uint uVar2;
  int iVar3;
  DWORD local_58 [4];
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined1 auStack_34 [20];
  
  *param_1 = 0;
  memset(auStack_34,0,0x10);
  local_3c = 0x100;
  local_48 = 0x280;
  local_58[1] = 0x24;
  if (((DAT_c048f5b8 == 0) || (DVar1 = GetTickCount(), 60000 < DVar1 - DAT_c048f5b8)) &&
     (DVar1 = FUN_c048cf1c(), DVar1 != 0)) {
    DVar1 = 0x3eb;
  }
  else {
    uVar2 = 0;
    if (DAT_c048f594 != 0) {
      iVar3 = 0;
      do {
        local_40 = 0x200;
        local_38 = 1;
        local_44 = *(undefined4 *)(iVar3 + DAT_c048f5dc);
        local_58[0] = 8;
        memset(auStack_34,0,0x10);
        DVar1 = FUN_c04829ac(2,&local_48,local_58 + 1,local_58 + 2,local_58);
        if (DVar1 == 1) {
          local_58[2] = 0;
        }
        else if (DVar1 != 0) {
          return DVar1;
        }
        *param_1 = *param_1 + local_58[2];
        uVar2 = uVar2 + 1;
        iVar3 = iVar3 + 4;
      } while (uVar2 < DAT_c048f594);
    }
    DVar1 = 0;
  }
  return DVar1;
}



/* c048419c FUN_c048419c */

/* Boundary evidence: original MIPS .pdata c048419c..c04843d3. Semantic name remains unreviewed. */

DWORD FUN_c048419c(int *param_1,int *param_2,HANDLE param_3,DWORD param_4,DWORD param_5)

{
  uint uVar1;
  LPVOID lpMem;
  LPVOID pvVar2;
  undefined4 *puVar3;
  DWORD DVar4;
  int iVar5;
  int iVar6;
  undefined4 *puVar7;
  uint uVar8;
  uint local_68;
  DWORD local_64 [3];
  int *local_58;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined1 auStack_3c [20];
  
  *param_1 = 0;
  *param_2 = 0;
  local_58 = param_2;
  lpMem = FUN_c0482d48(&local_68);
  if (lpMem == (LPVOID)0x0) {
    DVar4 = 8;
  }
  else {
    iVar6 = 0x10;
    pvVar2 = HeapAlloc(param_3,param_4,0x40);
    uVar1 = local_68;
    *param_1 = (int)pvVar2;
    if (pvVar2 == (LPVOID)0x0) {
      DVar4 = 8;
LAB_c04843b8:
      HeapFree(DAT_c048f5d4,0,lpMem);
    }
    else {
      iVar5 = 0;
      uVar8 = 0;
      if (local_68 != 0) {
        local_68 = 0;
        puVar7 = (undefined4 *)((int)lpMem + 4);
        do {
          if (puVar7[-1] == 0x280) {
            local_48 = 0x100;
            local_44 = 0x100;
            local_50 = 0x280;
            local_40 = 1;
            local_4c = *puVar7;
            local_64[1] = 0x24;
            local_64[0] = 4;
            memset(auStack_3c,0,0x10);
            DVar4 = FUN_c04829ac(2,&local_50,local_64 + 1,local_64 + 2,local_64);
            if (DVar4 != 1) {
              if (DVar4 != 0) {
LAB_c04843a8:
                HeapFree(param_3,0,(LPVOID)*param_1);
                goto LAB_c04843b8;
              }
              if (local_64[2] == 0x280) {
                if (iVar5 == iVar6) {
                  pvVar2 = HeapReAlloc(param_3,param_5,(LPVOID)*param_1,iVar6 << 3);
                  if (pvVar2 == (LPVOID)0x0) {
                    DVar4 = GetLastError();
                    goto LAB_c04843a8;
                  }
                  *param_1 = (int)pvVar2;
                  iVar6 = iVar6 << 1;
                }
                puVar3 = (undefined4 *)(*param_1 + local_68);
                local_68 = local_68 + 4;
                iVar5 = iVar5 + 1;
                *puVar3 = *puVar7;
              }
            }
          }
          uVar8 = uVar8 + 1;
          puVar7 = puVar7 + 2;
        } while (uVar8 < uVar1);
      }
      HeapFree(DAT_c048f5d4,0,lpMem);
      DVar4 = 0;
      *local_58 = iVar5;
    }
  }
  return DVar4;
}



/* c04843d4 FUN_c04843d4 */

/* Boundary evidence: original MIPS .pdata c04843d4..c04844cb. Semantic name remains unreviewed. */

undefined4 FUN_c04843d4(void *param_1)

{
  undefined1 *puVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 local_68;
  undefined4 local_64;
  undefined1 auStack_60 [4];
  undefined1 auStack_5c [4];
  undefined1 auStack_58 [4];
  undefined1 auStack_54 [4];
  undefined1 auStack_50 [4];
  undefined4 local_4c;
  undefined1 auStack_48 [60];
  uint local_c;
  
  local_c = DAT_c048f418;
  local_68 = 0x4f;
  FUN_c0485020();
  if (DAT_c048f5a4 == 0) {
    FUN_c048e238(local_c);
    uVar4 = 0x32;
  }
  else {
    local_4c = 0x34;
    puVar1 = auStack_50 + 3;
    uVar2 = (uint)puVar1 & 3;
    *(uint *)(puVar1 + -uVar2) =
         *(uint *)(puVar1 + -uVar2) & -1 << (uVar2 + 1) * 8 | 0x101U >> (3 - uVar2) * 8;
    puVar1 = auStack_54 + 3;
    uVar2 = (uint)puVar1 & 3;
    *(uint *)(puVar1 + -uVar2) =
         *(uint *)(puVar1 + -uVar2) & -1 << (uVar2 + 1) * 8 | 0x100U >> (3 - uVar2) * 8;
    puVar1 = auStack_58 + 3;
    uVar2 = (uint)puVar1 & 3;
    *(uint *)(puVar1 + -uVar2) =
         *(uint *)(puVar1 + -uVar2) & -1 << (uVar2 + 1) * 8 | 0x200U >> (3 - uVar2) * 8;
    puVar1 = auStack_60 + 3;
    uVar2 = (uint)puVar1 & 3;
    *(uint *)(puVar1 + -uVar2) =
         *(uint *)(puVar1 + -uVar2) & -1 << (uVar2 + 1) * 8 | 0x301U >> (3 - uVar2) * 8;
    puVar1 = auStack_5c + 3;
    uVar2 = (uint)puVar1 & 3;
    *(uint *)(puVar1 + -uVar2) =
         *(uint *)(puVar1 + -uVar2) & -1 << (uVar2 + 1) * 8 | 0U >> (3 - uVar2) * 8;
    auStack_50 = (undefined1  [4])0x101;
    auStack_54 = (undefined1  [4])0x100;
    auStack_58 = (undefined1  [4])0x200;
    auStack_60 = (undefined1  [4])0x301;
    auStack_5c = (undefined1  [4])0x0;
    local_64 = 0;
    memcpy(auStack_48,param_1,0x34);
    iVar3 = WSAControl(6,1,auStack_60,&local_68,0,&local_64);
    if (iVar3 == 0) {
      uVar4 = 0;
    }
    else {
      uVar4 = FUN_c048294c(iVar3);
    }
    FUN_c048e238(local_c);
  }
  return uVar4;
}



/* c04844cc FUN_c04844cc */

/* Boundary evidence: original MIPS .pdata c04844cc..c048453f. Semantic name remains unreviewed. */

DWORD FUN_c04844cc(undefined4 param_1,LPVOID param_2)

{
  DWORD DVar1;
  undefined4 local_res0 [4];
  DWORD local_10 [2];
  
  local_10[1] = 4;
  local_10[0] = 4;
  local_res0[0] = param_1;
  FUN_c0485020();
  if (DAT_c048f5a4 == 0) {
    DVar1 = 0x32;
  }
  else {
    DVar1 = FUN_c0482aa8(DAT_c048f5b4,0x120044,local_res0,local_10 + 1,param_2,local_10);
  }
  return DVar1;
}



/* c0484540 FUN_c0484540 */

/* Boundary evidence: original MIPS .pdata c0484540..c048457b. Semantic name remains unreviewed. */

DWORD FUN_c0484540(int param_1)

{
  DWORD DVar1;
  
  if ((param_1 == 2) || (param_1 == 0x17)) {
    DVar1 = FUN_c0482b0c(param_1);
  }
  else {
    DVar1 = 0x57;
  }
  return DVar1;
}



/* c048457c FUN_c048457c */

/* Boundary evidence: original MIPS .pdata c048457c..c04845cf. Semantic name remains unreviewed. */

undefined4 FUN_c048457c(void)

{
  if (DAT_c048f5a8 != 0) {
    CloseHandle((HANDLE)DAT_c048f5a8);
  }
  DAT_c048f5a8 = 0;
  DAT_c048f5b4 = 0;
  return 0;
}



/* c04845d0 FUN_c04845d0 */

/* Boundary evidence: original MIPS .pdata c04845d0..c0484623. Semantic name remains unreviewed. */

undefined4 FUN_c04845d0(void)

{
  if (DAT_c048f5a0 != 0) {
    CloseHandle((HANDLE)DAT_c048f5a0);
  }
  DAT_c048f5a0 = 0;
  DAT_c048f598 = 0;
  return 0;
}



/* c0484624 FUN_c0484624 */

/* Boundary evidence: original MIPS .pdata c0484624..c048481b. Semantic name remains unreviewed. */

undefined4 FUN_c0484624(size_t *param_1,int param_2,int param_3,int param_4)

{
  DWORD DVar1;
  int iVar2;
  size_t _NumOfElements;
  undefined4 *puVar3;
  undefined4 uVar4;
  size_t *psVar5;
  undefined4 *puVar6;
  
  _NumOfElements = 0;
  uVar4 = 0;
  FUN_c0485020();
  if (DAT_c048f5a4 == 0) {
    uVar4 = 0x32;
  }
  else {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c048f600);
    if ((((param_4 == 0) && (DAT_c048f5d8 != 0)) &&
        (DVar1 = GetTickCount(), DVar1 - DAT_c048f5d8 < 0xea61)) ||
       (iVar2 = FUN_c048cd28(), iVar2 == 0)) {
      puVar6 = &DAT_c048f440;
      do {
        puVar3 = (undefined4 *)*puVar6;
        if (puVar3 != puVar6) {
          psVar5 = param_1 + _NumOfElements * 0xd7 + 1;
          do {
            if (puVar3[4] != -1) {
              if ((param_2 - 4U) / 0x35c <= _NumOfElements) {
                uVar4 = 0xea;
                break;
              }
              DVar1 = FUN_c0482e28(0,puVar3[4],(undefined2 *)psVar5);
              if (DVar1 == 0) {
                _NumOfElements = _NumOfElements + 1;
                psVar5 = psVar5 + 0xd7;
              }
              else {
                DAT_c048f5d8 = 0;
              }
            }
            puVar3 = (undefined4 *)*puVar3;
          } while (puVar3 != puVar6);
        }
        puVar6 = puVar6 + 2;
      } while (puVar6 < (undefined4 *)0xc048f568);
      DAT_c048f614 = _NumOfElements;
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c048f600);
      *param_1 = _NumOfElements;
      if ((param_3 != 0) && (_NumOfElements != 0)) {
        qsort(param_1 + 1,_NumOfElements,0x35c,(_PtFuncCompare *)&LAB_c048c628);
      }
    }
    else {
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c048f600);
      uVar4 = 0x3eb;
    }
  }
  return uVar4;
}



/* c048481c FUN_c048481c */

/* Boundary evidence: original MIPS .pdata c048481c..c0484913. Semantic name remains unreviewed. */

DWORD FUN_c048481c(undefined2 *param_1,uint param_2,int param_3)

{
  DWORD DVar1;
  int iVar2;
  
  if (param_1 == (undefined2 *)0x0) {
    DVar1 = 0x57;
  }
  else {
    FUN_c0485020();
    if (DAT_c048f5a4 == 0) {
      DVar1 = 0x32;
    }
    else {
      EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c048f600);
      if ((param_3 != 0) || (iVar2 = FUN_c048ccc0(param_2), iVar2 == -1)) {
        iVar2 = FUN_c048cd28();
        if (iVar2 != 0) {
          LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c048f600);
          return 0x3eb;
        }
        iVar2 = FUN_c048ccc0(param_2);
      }
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c048f600);
      if (iVar2 == -1) {
        DVar1 = 0xd;
      }
      else {
        DVar1 = FUN_c0482e28(0,iVar2,param_1);
      }
    }
  }
  return DVar1;
}



/* c0484914 FUN_c0484914 */

/* Boundary evidence: original MIPS .pdata c0484914..c0484a07. Semantic name remains unreviewed. */

DWORD FUN_c0484914(undefined2 *param_1,int param_2)

{
  int iVar1;
  DWORD DVar2;
  
  FUN_c0485020();
  if (DAT_c048f5a4 == 0) {
    return 0x32;
  }
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c048f600);
  if (param_2 == 0) {
    iVar1 = FUN_c048ccc0(*(uint *)(param_1 + 0x100));
    if (iVar1 == -1) {
      iVar1 = FUN_c048cd28();
      if (iVar1 != 0) {
        DVar2 = 0x3eb;
        goto LAB_c04849e0;
      }
      goto LAB_c04849b4;
    }
  }
  else {
    iVar1 = FUN_c048cd28();
    if (iVar1 != 0) {
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c048f600);
      return 0x3eb;
    }
LAB_c04849b4:
    iVar1 = FUN_c048ccc0(*(uint *)(param_1 + 0x100));
    if (iVar1 == -1) {
      DVar2 = 0xd;
      goto LAB_c04849e0;
    }
  }
  DVar2 = FUN_c0482e28(1,iVar1,param_1);
LAB_c04849e0:
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c048f600);
  return DVar2;
}



/* c0484a08 AllocateAndGetIpAddrTableFromStack */

/* Boundary evidence: original MIPS .pdata c0484a08..c0484aeb. Semantic name remains unreviewed. */

DWORD AllocateAndGetIpAddrTableFromStack
                (undefined4 *param_1,int param_2,HANDLE param_3,DWORD param_4)

{
  DWORD DVar1;
  uint *puVar2;
  SIZE_T dwBytes;
  undefined1 auStack_78 [84];
  int local_24;
  
                    /* 0x4a08  3  AllocateAndGetIpAddrTableFromStack */
  *param_1 = 0;
  DVar1 = FUN_c04836b0(auStack_78);
  if (DVar1 == 0) {
    dwBytes = local_24 * 0x18 + 0xfc;
    puVar2 = HeapAlloc(param_3,param_4,dwBytes);
    *param_1 = puVar2;
    if (puVar2 == (uint *)0x0) {
      DVar1 = 8;
    }
    else if (local_24 == 0) {
      *puVar2 = 0;
      DVar1 = 0;
    }
    else {
      DVar1 = FUN_c0482fac(puVar2,dwBytes,param_2);
      if (DVar1 != 0) {
        HeapFree(param_3,param_4,(LPVOID)*param_1);
        *param_1 = 0;
      }
    }
  }
  return DVar1;
}



/* c0484aec FUN_c0484aec */

/* WARNING: Type propagation algorithm not settling */
/* Boundary evidence: original MIPS .pdata c0484aec..c0484d2b. Semantic name remains unreviewed. */

DWORD FUN_c0484aec(size_t *param_1,int param_2,int param_3)

{
  size_t *psVar1;
  longlong lVar2;
  DWORD DVar3;
  LPVOID lpMem;
  size_t *psVar4;
  size_t *psVar5;
  uint uVar6;
  SIZE_T local_b0;
  DWORD local_ac [6];
  undefined1 auStack_94 [20];
  undefined1 auStack_80 [88];
  uint local_28;
  
  uVar6 = (param_2 - 4U) / 0x38;
  DVar3 = FUN_c04836b0(auStack_80);
  if (DVar3 == 0) {
    if (((local_28 <= local_28 + 0x14) &&
        (lVar2 = (ulonglong)(local_28 + 0x14) * 0x34, local_b0 = (SIZE_T)lVar2,
        (int)((ulonglong)lVar2 >> 0x20) == 0)) &&
       (lpMem = HeapAlloc(DAT_c048f5d4,0,local_b0), lpMem != (LPVOID)0x0)) {
      local_ac[1] = 0x301;
      local_ac[2] = 0;
      local_ac[3] = 0x200;
      local_ac[4] = 0x100;
      local_ac[5] = 0x101;
      memset(auStack_94,0,0x10);
      local_ac[0] = 0x24;
      DVar3 = FUN_c04829ac(2,local_ac + 1,local_ac,lpMem,&local_b0);
      if (DVar3 != 0) {
        HeapFree(DAT_c048f5d4,0,lpMem);
        return DVar3;
      }
      if (uVar6 < local_b0 / 0x34) {
        *param_1 = uVar6;
        DVar3 = 0xea;
      }
      else {
        *param_1 = local_b0 / 0x34;
        DVar3 = 0;
      }
      uVar6 = 0;
      if (*param_1 != 0) {
        psVar5 = param_1 + 4;
        psVar4 = (size_t *)((int)lpMem + 0x10);
        do {
          uVar6 = uVar6 + 1;
          psVar5[-3] = psVar4[-4];
          psVar5[1] = psVar4[-3];
          psVar5[6] = psVar4[-2];
          psVar5[7] = psVar4[-1];
          psVar5[8] = *psVar4;
          psVar5[9] = psVar4[1];
          psVar5[10] = psVar4[7];
          *psVar5 = psVar4[2];
          psVar5[2] = psVar4[3];
          psVar5[3] = psVar4[4];
          psVar5[4] = psVar4[5];
          psVar1 = psVar4 + 6;
          psVar4 = psVar4 + 0xd;
          psVar5[-2] = *psVar1;
          psVar5[5] = 0;
          psVar5[-1] = 0;
          psVar5 = psVar5 + 0xe;
        } while (uVar6 < *param_1);
      }
      HeapFree(DAT_c048f5d4,0,lpMem);
      if (*param_1 == 0) {
        return DVar3;
      }
      if (param_3 == 0) {
        return DVar3;
      }
      qsort(param_1 + 1,*param_1,0x38,(_PtFuncCompare *)&LAB_c048c958);
      return DVar3;
    }
    DVar3 = 8;
  }
  return DVar3;
}



/* c0484d2c FUN_c0484d2c */

/* Boundary evidence: original MIPS .pdata c0484d2c..c0484dd3. Semantic name remains unreviewed. */

undefined4 FUN_c0484d2c(undefined4 *param_1)

{
  undefined4 uVar1;
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
  
  FUN_c0485020();
  if (DAT_c048f5a4 == 0) {
    uVar1 = 0x32;
  }
  else {
    local_40 = *param_1;
    local_3c = param_1[4];
    local_38 = param_1[9];
    local_34 = param_1[10];
    local_30 = param_1[0xb];
    local_2c = param_1[0xc];
    local_14 = param_1[0xd];
    local_28 = param_1[3];
    local_24 = param_1[5];
    local_20 = param_1[6];
    local_1c = param_1[7];
    local_18 = param_1[1];
    local_10 = 0;
    uVar1 = FUN_c04843d4(&local_40);
  }
  return uVar1;
}



/* c0484dd4 AllocateAndGetIfTableFromStack */

/* Boundary evidence: original MIPS .pdata c0484dd4..c0484f07. Semantic name remains unreviewed. */

DWORD AllocateAndGetIfTableFromStack
                (undefined4 *param_1,int param_2,HANDLE param_3,DWORD param_4,int param_5)

{
  DWORD DVar1;
  undefined4 *puVar2;
  SIZE_T dwBytes;
  undefined1 auStack_80 [80];
  int local_30;
  
                    /* 0x4dd4  2  AllocateAndGetIfTableFromStack */
  *param_1 = 0;
  DVar1 = FUN_c04836b0(auStack_80);
  if (DVar1 == 0) {
    dwBytes = local_30 * 0x35c + 0x21a4;
    puVar2 = HeapAlloc(param_3,param_4,dwBytes);
    *param_1 = puVar2;
    if (puVar2 == (undefined4 *)0x0) {
      DVar1 = 8;
    }
    else if (local_30 == 0) {
      *puVar2 = 0;
      DVar1 = 0;
    }
    else {
      EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c048f600);
      if ((param_5 == 0) && (local_30 != DAT_c048f614)) {
        param_5 = 1;
      }
      DAT_c048f614 = local_30;
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c048f600);
      DVar1 = FUN_c0484624((size_t *)*param_1,dwBytes,param_2,param_5);
      if (DVar1 != 0) {
        HeapFree(param_3,param_4,(LPVOID)*param_1);
        *param_1 = 0;
      }
    }
  }
  return DVar1;
}



/* c0484f08 FUN_c0484f08 */

undefined4 FUN_c0484f08(short *param_1)

{
  undefined4 uVar1;
  
  if ((((*param_1 != 0) || (param_1[1] != 0)) || (param_1[2] != 0)) ||
     (((param_1[3] != 0 || (param_1[4] != 0)) || (uVar1 = 1, param_1[5] != -1)))) {
    uVar1 = 0;
  }
  return uVar1;
}



/* c0484f60 FUN_c0484f60 */

/* Boundary evidence: original MIPS .pdata c0484f60..c048500f. Semantic name remains unreviewed. */

void FUN_c0484f60(undefined4 *param_1,undefined4 *param_2)

{
  *param_1 = *param_2;
  param_1[1] = param_2[1];
  memset(param_1 + 2,0,0x400);
  param_1[5] = param_2[2];
  param_1[0xd] = param_2[3];
  param_1[0xe] = param_2[4];
  param_1[6] = param_2[5];
  param_1[7] = param_2[6];
  param_1[10] = param_2[7];
  param_1[2] = param_2[8];
  param_1[0xf] = param_2[9];
  param_1[0x10] = param_2[10];
  param_1[0x13] = param_2[0xb];
  param_1[0x14] = param_2[0xc];
  return;
}



/* c0485010 GetFriendlyIfIndex */

uint GetFriendlyIfIndex(uint param_1)

{
                    /* 0x5010  20  GetFriendlyIfIndex */
  return param_1 & 0xffffff;
}



/* c0485020 FUN_c0485020 */

/* Boundary evidence: original MIPS .pdata c0485020..c04850f3. Semantic name remains unreviewed. */

void FUN_c0485020(void)

{
  DWORD DVar1;
  int iVar2;
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c048f5e0);
  if ((DAT_c048f5a4 == 0) && (DVar1 = FUN_c0484540(2), DVar1 == 0)) {
    iVar2 = FUN_c048cd28();
    if ((iVar2 == 0) &&
       ((DVar1 = FUN_c048cf1c(), DVar1 == 0 && (iVar2 = FUN_c0488cac(0,1), iVar2 != 0)))) {
      DAT_c048f5a4 = 1;
    }
    else {
      FUN_c048457c();
    }
  }
  if ((DAT_c048f5ac == 0) && (DVar1 = FUN_c0484540(0x17), DVar1 == 0)) {
    DAT_c048f5ac = 1;
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c048f5e0);
  return;
}



/* c04850f4 GetNumberOfInterfaces */

/* Boundary evidence: original MIPS .pdata c04850f4..c048515f. Semantic name remains unreviewed. */

DWORD GetNumberOfInterfaces(undefined4 *param_1)

{
  DWORD DVar1;
  undefined1 auStack_68 [80];
  undefined4 local_18;
  
                    /* 0x50f4  32  GetNumberOfInterfaces */
  FUN_c0485020();
  if (DAT_c048f5a4 == 0) {
    DVar1 = 0x32;
  }
  else if (param_1 == (undefined4 *)0x0) {
    DVar1 = 0x57;
  }
  else {
    *param_1 = 0;
    DVar1 = FUN_c04836b0(auStack_68);
    if (DVar1 == 0) {
      DVar1 = 0;
      *param_1 = local_18;
    }
  }
  return DVar1;
}



/* c0485160 GetIfTable */

/* Boundary evidence: original MIPS .pdata c0485160..c0485313. Semantic name remains unreviewed. */

DWORD GetIfTable(size_t *param_1,UINT_PTR *param_2,int param_3)

{
  bool bVar1;
  BOOL BVar2;
  DWORD DVar3;
  int local_28 [2];
  
                    /* 0x5160  24  GetIfTable */
  FUN_c0485020();
  if (DAT_c048f5a4 == 0) {
    DVar3 = 0x32;
  }
  else if (((param_2 == (UINT_PTR *)0x0) || (BVar2 = IsBadWritePtr(param_2,4), BVar2 != 0)) ||
          (BVar2 = IsBadWritePtr(param_1,*param_2), BVar2 != 0)) {
    DVar3 = 0x57;
  }
  else {
    DVar3 = GetNumberOfInterfaces(local_28);
    if (DVar3 == 0) {
      if (local_28[0] == 0) {
        DVar3 = 0xe8;
      }
      else if ((*param_2 < local_28[0] * 0x35c + 0xcU) || (param_1 == (size_t *)0x0)) {
        *param_2 = local_28[0] * 0x35c + 0x21a4;
        DVar3 = 0x7a;
      }
      else {
        EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c048f600);
        bVar1 = local_28[0] != DAT_c048f614;
        DAT_c048f614 = local_28[0];
        LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c048f600);
        DVar3 = FUN_c0484624(param_1,*param_2,param_3,(uint)bVar1);
        if ((param_3 == 0) && (DVar3 == 0)) {
          EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c048f600);
          DAT_c048f42c = GetAdapterOrderMap();
          if (DAT_c048f42c != (uint *)0x0) {
            qsort(param_1 + 1,*param_1,0x35c,FUN_c048caa4);
            LocalFree(DAT_c048f42c);
          }
          LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c048f600);
        }
      }
    }
  }
  return DVar3;
}



/* c0485314 GetIpAddrTable */

/* Boundary evidence: original MIPS .pdata c0485314..c0485483. Semantic name remains unreviewed. */

DWORD GetIpAddrTable(uint *param_1,UINT_PTR *param_2,int param_3)

{
  BOOL BVar1;
  DWORD DVar2;
  undefined1 auStack_78 [84];
  int local_24;
  
                    /* 0x5314  26  GetIpAddrTable */
  FUN_c0485020();
  if (DAT_c048f5a4 == 0) {
    DVar2 = 0x32;
  }
  else if (((param_2 == (UINT_PTR *)0x0) || (BVar1 = IsBadWritePtr(param_2,4), BVar1 != 0)) ||
          (BVar1 = IsBadWritePtr(param_1,*param_2), BVar1 != 0)) {
    DVar2 = 0x57;
  }
  else {
    DVar2 = FUN_c04836b0(auStack_78);
    if (DVar2 == 0) {
      if (local_24 == 0) {
        DVar2 = 0xe8;
      }
      else if ((*param_2 < local_24 * 0x18 + 0xcU) || (param_1 == (uint *)0x0)) {
        *param_2 = local_24 * 0x18 + 0xfc;
        DVar2 = 0x7a;
      }
      else {
        DVar2 = FUN_c0482fac(param_1,*param_2,param_3);
        if ((param_3 == 0) && (DVar2 == 0)) {
          EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c048f600);
          DAT_c048f42c = GetAdapterOrderMap();
          if (DAT_c048f42c != (uint *)0x0) {
            qsort(param_1 + 1,*param_1,0x18,FUN_c048cac4);
            LocalFree(DAT_c048f42c);
          }
          LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c048f600);
        }
      }
    }
  }
  return DVar2;
}



/* c0485484 GetIpNetTable */

/* Boundary evidence: original MIPS .pdata c0485484..c04855c7. Semantic name remains unreviewed. */

DWORD GetIpNetTable(size_t *param_1,uint *param_2,int param_3)

{
  BOOL BVar1;
  DWORD DVar2;
  int local_28 [2];
  
                    /* 0x5484  28  GetIpNetTable */
  FUN_c0485020();
  if (DAT_c048f5a4 == 0) {
    return 0x32;
  }
  if ((param_2 != (uint *)0x0) && (BVar1 = IsBadWritePtr(param_2,4), BVar1 == 0)) {
    local_28[0] = 0;
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c048f5c0);
    DVar2 = FUN_c048402c(local_28);
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c048f5c0);
    if (DVar2 != 0) {
      return DVar2;
    }
    if (local_28[0] == 0) {
      return 0xe8;
    }
    if ((*param_2 < local_28[0] * 0x18 + 0xcU) || (param_1 == (size_t *)0x0)) {
      *param_2 = local_28[0] * 0x18 + 0xfc;
      return 0x7a;
    }
    BVar1 = IsBadWritePtr(param_1,*param_2);
    if (BVar1 == 0) {
      DVar2 = FUN_c0483388(param_1,*param_2,param_3,0);
      return DVar2;
    }
  }
  return 0x57;
}



/* c04855c8 GetIpStatisticsEx */

/* Boundary evidence: original MIPS .pdata c04855c8..c048568b. Semantic name remains unreviewed. */

DWORD GetIpStatisticsEx(LPVOID param_1,int param_2)

{
  DWORD DVar1;
  BOOL BVar2;
  
                    /* 0x55c8  30  GetIpStatisticsEx */
  if ((param_1 == (LPVOID)0x0) ||
     (((param_2 != 2 && (param_2 != 0x17)) || (BVar2 = IsBadWritePtr(param_1,0x5c), BVar2 != 0)))) {
    DVar1 = 0x57;
  }
  else {
    FUN_c0485020();
    if (((param_2 == 2) && (DAT_c048f5a4 == 0)) || ((param_2 == 0x17 && (DAT_c048f5ac == 0)))) {
      DVar1 = 0x32;
    }
    else {
      DVar1 = FUN_c04835b8(param_1,param_2);
    }
  }
  return DVar1;
}



/* c048568c GetIpStatistics */

/* Boundary evidence: original MIPS .pdata c048568c..c0485707. Semantic name remains unreviewed. */

DWORD GetIpStatistics(LPVOID param_1)

{
  DWORD DVar1;
  BOOL BVar2;
  
                    /* 0x568c  29  GetIpStatistics */
  if ((param_1 == (LPVOID)0x0) || (BVar2 = IsBadWritePtr(param_1,0x5c), BVar2 != 0)) {
    DVar1 = 0x57;
  }
  else {
    FUN_c0485020();
    if (DAT_c048f5a4 == 0) {
      DVar1 = 0x32;
    }
    else {
      DVar1 = FUN_c04835b8(param_1,2);
    }
  }
  return DVar1;
}



/* c0485708 GetIcmpStatistics */

/* Boundary evidence: original MIPS .pdata c0485708..c048577b. Semantic name remains unreviewed. */

undefined4 GetIcmpStatistics(LPVOID param_1)

{
  undefined4 uVar1;
  BOOL BVar2;
  
                    /* 0x5708  21  GetIcmpStatistics */
  FUN_c0485020();
  if (DAT_c048f5a4 == 0) {
    uVar1 = 0x32;
  }
  else if ((param_1 == (LPVOID)0x0) || (BVar2 = IsBadWritePtr(param_1,0x68), BVar2 != 0)) {
    uVar1 = 0x57;
  }
  else {
    FUN_c048395c(param_1);
    uVar1 = 0;
  }
  return uVar1;
}



/* c048577c GetIcmpStatisticsEx */

/* Boundary evidence: original MIPS .pdata c048577c..c0485883. Semantic name remains unreviewed. */

DWORD GetIcmpStatisticsEx(undefined4 *param_1,int param_2)

{
  BOOL BVar1;
  DWORD DVar2;
  undefined4 auStack_80 [13];
  undefined4 auStack_4c [13];
  
                    /* 0x577c  22  GetIcmpStatisticsEx */
  if ((param_1 == (undefined4 *)0x0) ||
     (((param_2 != 2 && (param_2 != 0x17)) || (BVar1 = IsBadWritePtr(param_1,0x810), BVar1 != 0))))
  {
    return 0x57;
  }
  FUN_c0485020();
  if ((param_2 == 2) && (DAT_c048f5a4 == 0)) {
LAB_c0485810:
    DVar2 = 0x32;
  }
  else {
    if (param_2 == 0x17) {
      if (DAT_c048f5ac == 0) goto LAB_c0485810;
    }
    else if (param_2 == 2) {
      DVar2 = GetIcmpStatistics(auStack_80);
      if (DVar2 != 0) {
        return DVar2;
      }
      FUN_c0484f60(param_1,auStack_80);
      FUN_c0484f60(param_1 + 0x102,auStack_4c);
      return 0;
    }
    DVar2 = FUN_c048384c(param_1,param_2);
  }
  return DVar2;
}



/* c0485884 GetTcpStatisticsEx */

/* Boundary evidence: original MIPS .pdata c0485884..c048594b. Semantic name remains unreviewed. */

DWORD GetTcpStatisticsEx(LPVOID param_1,int param_2)

{
  BOOL BVar1;
  DWORD DVar2;
  
                    /* 0x5884  36  GetTcpStatisticsEx */
  if ((param_2 == 2) || (param_2 == 0x17)) {
    FUN_c0485020();
    if (((param_2 == 2) && (DAT_c048f5a4 == 0)) || ((param_2 == 0x17 && (DAT_c048f5ac == 0)))) {
      return 0x32;
    }
    if ((param_1 != (LPVOID)0x0) && (BVar1 = IsBadWritePtr(param_1,0x3c), BVar1 == 0)) {
      DVar2 = FUN_c0483af4(param_1,param_2);
      return DVar2;
    }
  }
  return 0x57;
}



/* c048594c GetTcpStatistics */

/* Boundary evidence: original MIPS .pdata c048594c..c04859c3. Semantic name remains unreviewed. */

DWORD GetTcpStatistics(LPVOID param_1)

{
  DWORD DVar1;
  BOOL BVar2;
  
                    /* 0x594c  35  GetTcpStatistics */
  FUN_c0485020();
  if (DAT_c048f5a4 == 0) {
    DVar1 = 0x32;
  }
  else if ((param_1 == (LPVOID)0x0) || (BVar2 = IsBadWritePtr(param_1,0x3c), BVar2 != 0)) {
    DVar1 = 0x57;
  }
  else {
    DVar1 = FUN_c0483af4(param_1,2);
  }
  return DVar1;
}



/* c04859c4 GetUdpStatisticsEx */

/* Boundary evidence: original MIPS .pdata c04859c4..c0485a8b. Semantic name remains unreviewed. */

DWORD GetUdpStatisticsEx(LPVOID param_1,int param_2)

{
  BOOL BVar1;
  DWORD DVar2;
  
                    /* 0x59c4  39  GetUdpStatisticsEx */
  if ((param_2 == 2) || (param_2 == 0x17)) {
    FUN_c0485020();
    if (((param_2 == 2) && (DAT_c048f5a4 == 0)) || ((param_2 == 0x17 && (DAT_c048f5ac == 0)))) {
      return 0x32;
    }
    if ((param_1 != (LPVOID)0x0) && (BVar1 = IsBadWritePtr(param_1,0x14), BVar1 == 0)) {
      DVar2 = FUN_c04839fc(param_1,param_2);
      return DVar2;
    }
  }
  return 0x57;
}



/* c0485a8c GetUdpStatistics */

/* Boundary evidence: original MIPS .pdata c0485a8c..c0485b03. Semantic name remains unreviewed. */

DWORD GetUdpStatistics(LPVOID param_1)

{
  DWORD DVar1;
  BOOL BVar2;
  
                    /* 0x5a8c  38  GetUdpStatistics */
  FUN_c0485020();
  if (DAT_c048f5a4 == 0) {
    DVar1 = 0x32;
  }
  else if ((param_1 == (LPVOID)0x0) || (BVar2 = IsBadWritePtr(param_1,0x14), BVar2 != 0)) {
    DVar1 = 0x57;
  }
  else {
    DVar1 = FUN_c04839fc(param_1,2);
  }
  return DVar1;
}



/* c0485b04 GetIfEntry */

/* Boundary evidence: original MIPS .pdata c0485b04..c0485b83. Semantic name remains unreviewed. */

DWORD GetIfEntry(undefined2 *param_1)

{
  BOOL BVar1;
  DWORD DVar2;
  
                    /* 0x5b04  23  GetIfEntry */
  if ((param_1 == (undefined2 *)0x0) || (BVar1 = IsBadWritePtr(param_1,0x35c), BVar1 != 0)) {
    DVar2 = 0x57;
  }
  else {
    FUN_c0485020();
    if (DAT_c048f5a4 == 0) {
      DVar2 = 0x32;
    }
    else {
      DVar2 = FUN_c048481c(param_1,*(uint *)(param_1 + 0x100),1);
    }
  }
  return DVar2;
}



/* c0485b84 SetIfEntry */

/* Boundary evidence: original MIPS .pdata c0485b84..c0485c0f. Semantic name remains unreviewed. */

DWORD SetIfEntry(void *param_1)

{
  DWORD DVar1;
  BOOL BVar2;
  undefined4 local_370 [2];
  undefined1 auStack_368 [864];
  
                    /* 0x5b84  56  SetIfEntry */
  if ((param_1 == (void *)0x0) || (BVar2 = IsBadReadPtr(param_1,0x35c), BVar2 != 0)) {
    DVar1 = 0x57;
  }
  else {
    FUN_c0485020();
    if (DAT_c048f5a4 == 0) {
      DVar1 = 0x32;
    }
    else {
      local_370[0] = 2;
      memcpy(auStack_368,param_1,0x35c);
      DVar1 = FUN_c0481504((int)local_370);
    }
  }
  return DVar1;
}



/* c0485c10 CreateIpForwardEntry */

/* Boundary evidence: original MIPS .pdata c0485c10..c0485ca3. Semantic name remains unreviewed. */

int CreateIpForwardEntry(void *param_1)

{
  int iVar1;
  BOOL BVar2;
  undefined4 local_50 [2];
  undefined1 auStack_48 [64];
  
                    /* 0x5c10  4  CreateIpForwardEntry */
  FUN_c0485020();
  if (DAT_c048f5a4 == 0) {
    iVar1 = 0x32;
  }
  else {
    if ((param_1 != (void *)0x0) && (BVar2 = IsBadReadPtr(param_1,0x38), BVar2 == 0)) {
      local_50[0] = 8;
      memcpy(auStack_48,param_1,0x38);
      iVar1 = FUN_c0481548((int)local_50);
      if (iVar1 != -0x3ffffff3) {
        return iVar1;
      }
    }
    iVar1 = 0x57;
  }
  return iVar1;
}



/* c0485ca4 SetIpForwardEntry */

/* Boundary evidence: original MIPS .pdata c0485ca4..c0485d37. Semantic name remains unreviewed. */

int SetIpForwardEntry(void *param_1)

{
  int iVar1;
  BOOL BVar2;
  undefined4 local_50 [2];
  undefined1 auStack_48 [64];
  
                    /* 0x5ca4  57  SetIpForwardEntry */
  FUN_c0485020();
  if (DAT_c048f5a4 == 0) {
    iVar1 = 0x32;
  }
  else {
    if ((param_1 != (void *)0x0) && (BVar2 = IsBadReadPtr(param_1,0x38), BVar2 == 0)) {
      local_50[0] = 8;
      memcpy(auStack_48,param_1,0x38);
      iVar1 = FUN_c0481598((int)local_50);
      if (iVar1 != -0x3ffffff3) {
        return iVar1;
      }
    }
    iVar1 = 0x57;
  }
  return iVar1;
}



/* c0485d38 DeleteIpForwardEntry */

/* Boundary evidence: original MIPS .pdata c0485d38..c0485dd3. Semantic name remains unreviewed. */

int DeleteIpForwardEntry(void *param_1)

{
  int iVar1;
  BOOL BVar2;
  undefined4 local_50 [2];
  undefined1 auStack_48 [64];
  
                    /* 0x5d38  8  DeleteIpForwardEntry */
  FUN_c0485020();
  if (DAT_c048f5a4 == 0) {
    iVar1 = 0x32;
  }
  else if ((param_1 == (void *)0x0) || (BVar2 = IsBadReadPtr(param_1,0x38), BVar2 != 0)) {
    iVar1 = 0x57;
  }
  else {
    local_50[0] = 8;
    memcpy(auStack_48,param_1,0x38);
    iVar1 = FUN_c04815e8((int)local_50);
    if (iVar1 == -0x3ffffff3) {
      iVar1 = 0x490;
    }
  }
  return iVar1;
}



/* c0485dd4 SetIpStatistics */

/* Boundary evidence: original MIPS .pdata c0485dd4..c0485e5b. Semantic name remains unreviewed. */

int SetIpStatistics(void *param_1)

{
  int iVar1;
  BOOL BVar2;
  undefined4 local_70 [2];
  undefined1 auStack_68 [96];
  
                    /* 0x5dd4  59  SetIpStatistics */
  FUN_c0485020();
  if (DAT_c048f5a4 == 0) {
    iVar1 = 0x32;
  }
  else if ((param_1 == (void *)0x0) || (BVar2 = IsBadReadPtr(param_1,0x5c), BVar2 != 0)) {
    iVar1 = 0x57;
  }
  else {
    local_70[0] = 3;
    memcpy(auStack_68,param_1,0x5c);
    iVar1 = FUN_c0481640((int)local_70);
  }
  return iVar1;
}



/* c0485e5c CreateIpNetEntry */

/* Boundary evidence: original MIPS .pdata c0485e5c..c0485f03. Semantic name remains unreviewed. */

int CreateIpNetEntry(void *param_1)

{
  int iVar1;
  uint uVar2;
  undefined4 local_30 [2];
  undefined1 auStack_28 [32];
  
                    /* 0x5e5c  5  CreateIpNetEntry */
  FUN_c0485020();
  if (DAT_c048f5a4 == 0) {
    iVar1 = 0x32;
  }
  else {
    if (param_1 != (void *)0x0) {
      local_30[0] = 10;
      memcpy(auStack_28,param_1,0x18);
      if ((((*(uint *)((int)param_1 + 4) != 0) && (*(uint *)((int)param_1 + 4) < 9)) &&
          (uVar2 = *(uint *)((int)param_1 + 0x10) & 0xff, uVar2 != 0x7f)) && (uVar2 < 0xe0)) {
        iVar1 = FUN_c0481680((int)local_30);
        return iVar1;
      }
    }
    iVar1 = 0x57;
  }
  return iVar1;
}



/* c0485f04 SetIpNetEntry */

/* Boundary evidence: original MIPS .pdata c0485f04..c0485f8b. Semantic name remains unreviewed. */

int SetIpNetEntry(void *param_1)

{
  int iVar1;
  BOOL BVar2;
  undefined4 local_30 [2];
  undefined1 auStack_28 [32];
  
                    /* 0x5f04  58  SetIpNetEntry */
  FUN_c0485020();
  if (DAT_c048f5a4 == 0) {
    iVar1 = 0x32;
  }
  else if ((param_1 == (void *)0x0) || (BVar2 = IsBadReadPtr(param_1,0x18), BVar2 != 0)) {
    iVar1 = 0x57;
  }
  else {
    local_30[0] = 10;
    memcpy(auStack_28,param_1,0x18);
    iVar1 = FUN_c04816c4((int)local_30);
  }
  return iVar1;
}



/* c0485f8c DeleteIpNetEntry */

/* Boundary evidence: original MIPS .pdata c0485f8c..c0486013. Semantic name remains unreviewed. */

int DeleteIpNetEntry(void *param_1)

{
  int iVar1;
  BOOL BVar2;
  undefined4 local_30 [2];
  undefined1 auStack_28 [32];
  
                    /* 0x5f8c  9  DeleteIpNetEntry */
  FUN_c0485020();
  if (DAT_c048f5a4 == 0) {
    iVar1 = 0x32;
  }
  else if ((param_1 == (void *)0x0) || (BVar2 = IsBadReadPtr(param_1,0x18), BVar2 != 0)) {
    iVar1 = 0x57;
  }
  else {
    local_30[0] = 10;
    memcpy(auStack_28,param_1,0x18);
    iVar1 = FUN_c0481708((int)local_30);
  }
  return iVar1;
}



/* c0486014 FlushIpNetTable */

/* Boundary evidence: original MIPS .pdata c0486014..c0486067. Semantic name remains unreviewed. */

DWORD FlushIpNetTable(int param_1)

{
  DWORD DVar1;
  
                    /* 0x6014  12  FlushIpNetTable */
  FUN_c0485020();
  if (DAT_c048f5a4 == 0) {
    DVar1 = 0x32;
  }
  else if (param_1 == 0) {
    DVar1 = 0x57;
  }
  else {
    DVar1 = FUN_c0483dbc(param_1);
  }
  return DVar1;
}



/* c0486068 SetTcpEntry */

/* Boundary evidence: original MIPS .pdata c0486068..c048610b. Semantic name remains unreviewed. */

undefined4 SetTcpEntry(undefined4 *param_1)

{
  BOOL BVar1;
  undefined4 uVar2;
  undefined4 local_28 [2];
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  
                    /* 0x6068  61  SetTcpEntry */
  if (param_1 != (undefined4 *)0x0) {
    FUN_c0485020();
    if (DAT_c048f5a4 == 0) {
      return 0x32;
    }
    BVar1 = IsBadReadPtr(param_1,0x14);
    if (BVar1 == 0) {
      local_28[0] = 0xe;
      local_20 = *param_1;
      local_1c = param_1[1];
      local_18 = param_1[2];
      local_14 = param_1[3];
      local_10 = param_1[4];
      uVar2 = FUN_c0481754((int)local_28);
      return uVar2;
    }
  }
  return 0x57;
}



/* c048610c GetBestInterface */

/* Boundary evidence: original MIPS .pdata c048610c..c048619f. Semantic name remains unreviewed. */

undefined4 GetBestInterface(undefined4 param_1,LPVOID param_2)

{
  undefined4 uVar1;
  BOOL BVar2;
  DWORD DVar3;
  
                    /* 0x610c  17  GetBestInterface */
  if ((param_2 == (LPVOID)0x0) || (BVar2 = IsBadWritePtr(param_2,4), BVar2 != 0)) {
    uVar1 = 0x57;
  }
  else {
    FUN_c0485020();
    if (DAT_c048f5a4 == 0) {
      uVar1 = 0x32;
    }
    else {
      DVar3 = FUN_c04844cc(param_1,param_2);
      if (DVar3 == 0) {
        uVar1 = 0;
      }
      else {
        uVar1 = 0x3eb;
      }
    }
  }
  return uVar1;
}



/* c04861a0 GetBestInterfaceEx */

/* Boundary evidence: original MIPS .pdata c04861a0..c04862b3. Semantic name remains unreviewed. */

DWORD GetBestInterfaceEx(short *param_1,undefined4 *param_2)

{
  BOOL BVar1;
  DWORD DVar2;
  int iVar3;
  undefined4 uVar4;
  
                    /* 0x61a0  18  GetBestInterfaceEx */
  BVar1 = IsBadReadPtr(param_1,0x10);
  if (BVar1 == 0) {
    if (*param_1 == 2) {
      uVar4 = *(undefined4 *)(param_1 + 2);
LAB_c04861f8:
      DVar2 = GetBestInterface(uVar4,param_2);
      return DVar2;
    }
    if ((*param_1 == 0x17) && (BVar1 = IsBadReadPtr(param_1,0x1c), BVar1 == 0)) {
      iVar3 = FUN_c0484f08(param_1 + 4);
      if (iVar3 != 0) {
        uVar4 = *(undefined4 *)(param_1 + 10);
        goto LAB_c04861f8;
      }
      if ((param_2 != (undefined4 *)0x0) && (BVar1 = IsBadWritePtr(param_2,4), BVar1 == 0)) {
        FUN_c0485020();
        if (DAT_c048f5ac == 0) {
          return 0x32;
        }
        DVar2 = FUN_c048d080((int)param_1,param_2);
        return DVar2;
      }
    }
  }
  return 0x57;
}



/* c04862b4 GetBestRoute */

/* Boundary evidence: original MIPS .pdata c04862b4..c0486357. Semantic name remains unreviewed. */

undefined4 GetBestRoute(uint param_1,uint param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  BOOL BVar2;
  DWORD DVar3;
  
                    /* 0x62b4  19  GetBestRoute */
  FUN_c0485020();
  if (DAT_c048f5a4 == 0) {
    uVar1 = 0x32;
  }
  else if ((param_3 == (undefined4 *)0x0) || (BVar2 = IsBadWritePtr(param_3,0x38), BVar2 != 0)) {
    uVar1 = 0x57;
  }
  else {
    DVar3 = FUN_c0482be8(param_1,param_2,param_3);
    if (DVar3 == 0) {
      uVar1 = 0;
    }
    else {
      uVar1 = 0x3eb;
    }
  }
  return uVar1;
}



/* c0486358 CreateProxyArpEntry */

/* Boundary evidence: original MIPS .pdata c0486358..c048648f. Semantic name remains unreviewed. */

int CreateProxyArpEntry(uint param_1,uint param_2,uint param_3)

{
  int iVar1;
  uint uVar2;
  
                    /* 0x6358  6  CreateProxyArpEntry */
  FUN_c0485020();
  if (DAT_c048f5a4 == 0) {
    return 0x32;
  }
  if ((param_1 & 0x80) == 0) {
    uVar2 = 0xff;
  }
  else if ((param_1 & 0xc0) == 0x80) {
    uVar2 = 0xffff;
  }
  else {
    if ((param_1 & 0xe0) == 0xc0) {
      uVar2 = 0xff0000;
    }
    else {
      uVar2 = 0xe0;
      if ((param_1 & 0xf0) == 0xe0) goto LAB_c04863fc;
      uVar2 = 0xffff0000;
    }
    uVar2 = uVar2 | 0xffff;
  }
LAB_c04863fc:
  if (((((param_1 & 0xff) == 0x7f) || (param_1 == 0)) || (0xdf < (param_1 & 0xff))) ||
     (((param_1 & param_2) != param_1 || (param_1 == (~uVar2 | param_1))))) {
    iVar1 = 0x57;
  }
  else {
    iVar1 = FUN_c048c620();
    if ((iVar1 == 0) && (iVar1 = FUN_c0483e24(param_1,param_2,param_3,1,0), iVar1 != 0)) {
      return iVar1;
    }
    iVar1 = 0;
  }
  return iVar1;
}



/* c0486490 DeleteProxyArpEntry */

/* Boundary evidence: original MIPS .pdata c0486490..c04865c7. Semantic name remains unreviewed. */

int DeleteProxyArpEntry(uint param_1,uint param_2,uint param_3)

{
  int iVar1;
  uint uVar2;
  
                    /* 0x6490  10  DeleteProxyArpEntry */
  FUN_c0485020();
  if (DAT_c048f5a4 == 0) {
    return 0x32;
  }
  if ((param_1 & 0x80) == 0) {
    uVar2 = 0xff;
  }
  else if ((param_1 & 0xc0) == 0x80) {
    uVar2 = 0xffff;
  }
  else {
    if ((param_1 & 0xe0) == 0xc0) {
      uVar2 = 0xff0000;
    }
    else {
      uVar2 = 0xe0;
      if ((param_1 & 0xf0) == 0xe0) goto LAB_c0486534;
      uVar2 = 0xffff0000;
    }
    uVar2 = uVar2 | 0xffff;
  }
LAB_c0486534:
  if (((((param_1 & 0xff) == 0x7f) || (param_1 == 0)) || (0xdf < (param_1 & 0xff))) ||
     (((param_1 & param_2) != param_1 || (param_1 == (~uVar2 | param_1))))) {
    iVar1 = 0x57;
  }
  else {
    iVar1 = FUN_c048c620();
    if ((iVar1 == 0) && (iVar1 = FUN_c0483e24(param_1,param_2,param_3,0,0), iVar1 != 0)) {
      return iVar1;
    }
    iVar1 = 0;
  }
  return iVar1;
}



/* c04865c8 GetIpForwardTable */

/* Boundary evidence: original MIPS .pdata c04865c8..c04866d3. Semantic name remains unreviewed. */

DWORD GetIpForwardTable(size_t *param_1,UINT_PTR *param_2,int param_3)

{
  DWORD DVar1;
  BOOL BVar2;
  undefined1 auStack_78 [88];
  int local_20;
  
                    /* 0x65c8  27  GetIpForwardTable */
  FUN_c0485020();
  if (DAT_c048f5a4 == 0) {
    DVar1 = 0x32;
  }
  else if (((param_2 == (UINT_PTR *)0x0) || (BVar2 = IsBadWritePtr(param_2,4), BVar2 != 0)) ||
          (BVar2 = IsBadWritePtr(param_1,*param_2), BVar2 != 0)) {
    DVar1 = 0x57;
  }
  else {
    DVar1 = GetIpStatistics(auStack_78);
    if (DVar1 == 0) {
      if (local_20 == 0) {
        DVar1 = 0xe8;
      }
      else if ((*param_2 < local_20 * 0x38 + 0xcU) || (param_1 == (size_t *)0x0)) {
        *param_2 = local_20 * 0x38 + 0x46c;
        DVar1 = 0x7a;
      }
      else {
        DVar1 = FUN_c0484aec(param_1,*param_2,param_3);
      }
    }
  }
  return DVar1;
}



/* c04866d4 GetTcpTable */

/* Boundary evidence: original MIPS .pdata c04866d4..c04867df. Semantic name remains unreviewed. */

DWORD GetTcpTable(uint *param_1,UINT_PTR *param_2,int param_3)

{
  DWORD DVar1;
  BOOL BVar2;
  undefined1 auStack_58 [56];
  int local_20;
  
                    /* 0x66d4  37  GetTcpTable */
  FUN_c0485020();
  if (DAT_c048f5a4 == 0) {
    DVar1 = 0x32;
  }
  else if (((param_2 == (UINT_PTR *)0x0) || (BVar2 = IsBadWritePtr(param_2,4), BVar2 != 0)) ||
          (BVar2 = IsBadWritePtr(param_1,*param_2), BVar2 != 0)) {
    DVar1 = 0x57;
  }
  else {
    DVar1 = GetTcpStatistics(auStack_58);
    if (DVar1 == 0) {
      if (local_20 == 0) {
        DVar1 = 0xe8;
      }
      else if ((*param_2 < local_20 * 0x14 + 0xcU) || (param_1 == (uint *)0x0)) {
        *param_2 = local_20 * 0x14 + 0xd4;
        DVar1 = 0x7a;
      }
      else {
        DVar1 = FUN_c04830a4(param_1,*param_2,param_3);
      }
    }
  }
  return DVar1;
}



/* c04867e0 GetUdpTable */

/* Boundary evidence: original MIPS .pdata c04867e0..c04868e3. Semantic name remains unreviewed. */

DWORD GetUdpTable(uint *param_1,UINT_PTR *param_2,int param_3)

{
  DWORD DVar1;
  BOOL BVar2;
  undefined1 auStack_30 [16];
  int local_20;
  
                    /* 0x67e0  40  GetUdpTable */
  FUN_c0485020();
  if (DAT_c048f5a4 == 0) {
    DVar1 = 0x32;
  }
  else if (((param_2 == (UINT_PTR *)0x0) || (BVar2 = IsBadWritePtr(param_2,4), BVar2 != 0)) ||
          (BVar2 = IsBadWritePtr(param_1,*param_2), BVar2 != 0)) {
    DVar1 = 0x57;
  }
  else {
    DVar1 = GetUdpStatistics(auStack_30);
    if (DVar1 == 0) {
      if (local_20 == 0) {
        DVar1 = 0xe8;
      }
      else if ((*param_2 < local_20 * 8 + 0xcU) || (param_1 == (uint *)0x0)) {
        *param_2 = local_20 * 8 + 0x5c;
        DVar1 = 0x7a;
      }
      else {
        DVar1 = FUN_c0483298(param_1,*param_2,param_3);
      }
    }
  }
  return DVar1;
}



/* c04868e4 SetIpTTL */

/* Boundary evidence: original MIPS .pdata c04868e4..c0486947. Semantic name remains unreviewed. */

DWORD SetIpTTL(undefined4 param_1)

{
  DWORD DVar1;
  undefined4 local_68;
  undefined4 local_64;
  
                    /* 0x68e4  60  SetIpTTL */
  FUN_c0485020();
  if (DAT_c048f5a4 == 0) {
    DVar1 = 0x32;
  }
  else {
    DVar1 = GetIpStatistics(&local_68);
    if (DVar1 == 0) {
      local_68 = 0xffffffff;
      local_64 = param_1;
      DVar1 = SetIpStatistics(&local_68);
    }
  }
  return DVar1;
}



/* c0486948 FUN_c0486948 */

undefined4 FUN_c0486948(short *param_1)

{
  undefined4 uVar1;
  
  if (((((*param_1 != 0) || (param_1[1] != 0)) || (param_1[2] != 0)) ||
      ((param_1[3] != 0 || (param_1[4] != 0)))) ||
     ((param_1[5] != 0 || ((param_1[6] != 0 || (uVar1 = 1, param_1[7] != 0)))))) {
    uVar1 = 0;
  }
  return uVar1;
}



/* c04869b4 FUN_c04869b4 */

undefined4 FUN_c04869b4(short *param_1)

{
  undefined4 uVar1;
  
  if (((((*param_1 != 0) || (param_1[1] != 0)) || (param_1[2] != 0)) ||
      ((param_1[3] != 0 || (param_1[4] != 0)))) ||
     ((param_1[5] != 0 || ((param_1[6] != 0 || (uVar1 = 1, param_1[7] != 0x100)))))) {
    uVar1 = 0;
  }
  return uVar1;
}



/* c0486a24 FUN_c0486a24 */

undefined4 FUN_c0486a24(short *param_1)

{
  undefined4 uVar1;
  
  if (((((*param_1 != 0) || (param_1[1] != 0)) || (param_1[2] != 0)) ||
      ((param_1[3] != 0 || (param_1[4] != 0)))) ||
     ((param_1[5] != 0 ||
      (((uVar1 = 1, param_1[6] == 0 && ((char)param_1[7] == '\0')) &&
       ((*(char *)((int)param_1 + 0xf) == '\0' || (*(char *)((int)param_1 + 0xf) == '\x01')))))))) {
    uVar1 = 0;
  }
  return uVar1;
}



/* c0486aa8 FUN_c0486aa8 */

/* Boundary evidence: original MIPS .pdata c0486aa8..c0486b3b. Semantic name remains unreviewed. */

bool FUN_c0486aa8(uint *param_1)

{
  LSTATUS LVar1;
  
  *param_1 = 3;
  LVar1 = RegOpenKeyExW((HKEY)0x80000002,L"Comm\\Tcpip\\Parms",0,0x20019,(PHKEY)&DAT_c048f128);
  if (LVar1 != 0) {
    *param_1 = *param_1 & 0xfffffffd;
    DAT_c048f128 = 0xffffffff;
  }
  return LVar1 == 0;
}



/* c0486b3c FUN_c0486b3c */

/* Boundary evidence: original MIPS .pdata c0486b3c..c0486b93. Semantic name remains unreviewed. */

undefined4 FUN_c0486b3c(undefined4 *param_1)

{
  undefined4 uVar1;
  longlong lVar2;
  
  lVar2 = __ull_div(*param_1,param_1[1],10000000,0);
  uVar1 = (undefined4)(lVar2 + -0x2b6109100);
  if ((int)((ulonglong)(lVar2 + -0x2b6109100) >> 0x20) != 0) {
    uVar1 = 0xffffffff;
  }
  return uVar1;
}



/* c0486b94 FUN_c0486b94 */

/* Boundary evidence: original MIPS .pdata c0486b94..c0486d47. Semantic name remains unreviewed. */

undefined4 FUN_c0486b94(undefined4 param_1,int param_2,undefined4 *param_3)

{
  HANDLE pvVar1;
  undefined4 *lpMem;
  undefined2 *_Dst;
  int iVar2;
  short *_Src;
  
  pvVar1 = GetProcessHeap();
  lpMem = HeapAlloc(pvVar1,0,0x30);
  if (lpMem != (undefined4 *)0x0) {
    pvVar1 = GetProcessHeap();
    _Dst = HeapAlloc(pvVar1,0,0x1c);
    if (_Dst != (undefined2 *)0x0) {
      memset(_Dst,0,0x1c);
      *_Dst = 0x17;
      _Src = (short *)(param_2 + 0x38);
      *(undefined4 *)(_Dst + 0xc) = *(undefined4 *)(param_2 + 0x50);
      memcpy(_Dst + 4,_Src,0x10);
      *(undefined4 **)*param_3 = lpMem;
      *param_3 = lpMem + 2;
      lpMem[2] = 0;
      *lpMem = 0x30;
      lpMem[8] = *(undefined4 *)(param_2 + 0x60);
      lpMem[9] = *(undefined4 *)(param_2 + 100);
      lpMem[10] = 0xffffffff;
      lpMem[1] = 0;
      lpMem[4] = 0x1c;
      lpMem[3] = _Dst;
      lpMem[5] = *(undefined4 *)(param_2 + 0x58);
      iVar2 = *(int *)(param_2 + 0x5c);
      lpMem[6] = iVar2;
      lpMem[7] = *(undefined4 *)(param_2 + 0x54);
      if ((((*(int *)(param_2 + 0x54) == 4) && (iVar2 != 5)) &&
          (iVar2 = FUN_c04869b4(_Src), iVar2 == 0)) &&
         ((*(char *)_Src != -2 || ((*(byte *)(param_2 + 0x39) & 0xc0) != 0x80)))) {
        lpMem[1] = 1;
      }
      return 0;
    }
    pvVar1 = GetProcessHeap();
    HeapFree(pvVar1,0,lpMem);
  }
  return 8;
}



/* c0486d48 FUN_c0486d48 */

/* Boundary evidence: original MIPS .pdata c0486d48..c0486e5f. Semantic name remains unreviewed. */

undefined4 FUN_c0486d48(undefined4 param_1,int param_2,undefined4 *param_3)

{
  HANDLE pvVar1;
  undefined4 *lpMem;
  undefined2 *_Dst;
  
  pvVar1 = GetProcessHeap();
  lpMem = HeapAlloc(pvVar1,0,0x18);
  if (lpMem != (undefined4 *)0x0) {
    pvVar1 = GetProcessHeap();
    _Dst = HeapAlloc(pvVar1,0,0x1c);
    if (_Dst != (undefined2 *)0x0) {
      memset(_Dst,0,0x1c);
      *_Dst = 0x17;
      *(undefined4 *)(_Dst + 0xc) = *(undefined4 *)(param_2 + 0x50);
      memcpy(_Dst + 4,(void *)(param_2 + 0x38),0x10);
      *(undefined4 **)*param_3 = lpMem;
      *param_3 = lpMem + 2;
      lpMem[2] = 0;
      *lpMem = 0x18;
      lpMem[1] = 0;
      lpMem[4] = 0x1c;
      lpMem[3] = _Dst;
      return 0;
    }
    pvVar1 = GetProcessHeap();
    HeapFree(pvVar1,0,lpMem);
  }
  return 8;
}



/* c0486e60 FUN_c0486e60 */

/* Boundary evidence: original MIPS .pdata c0486e60..c0486f77. Semantic name remains unreviewed. */

undefined4 FUN_c0486e60(undefined4 param_1,int param_2,undefined4 *param_3)

{
  HANDLE pvVar1;
  undefined4 *lpMem;
  undefined2 *_Dst;
  
  pvVar1 = GetProcessHeap();
  lpMem = HeapAlloc(pvVar1,0,0x18);
  if (lpMem != (undefined4 *)0x0) {
    pvVar1 = GetProcessHeap();
    _Dst = HeapAlloc(pvVar1,0,0x1c);
    if (_Dst != (undefined2 *)0x0) {
      memset(_Dst,0,0x1c);
      *_Dst = 0x17;
      *(undefined4 *)(_Dst + 0xc) = *(undefined4 *)(param_2 + 0x50);
      memcpy(_Dst + 4,(void *)(param_2 + 0x38),0x10);
      *(undefined4 **)*param_3 = lpMem;
      *param_3 = lpMem + 2;
      lpMem[2] = 0;
      *lpMem = 0x18;
      lpMem[1] = 0;
      lpMem[4] = 0x1c;
      lpMem[3] = _Dst;
      return 0;
    }
    pvVar1 = GetProcessHeap();
    HeapFree(pvVar1,0,lpMem);
  }
  return 8;
}



/* c0486f78 FUN_c0486f78 */

/* Boundary evidence: original MIPS .pdata c0486f78..c048700f. Semantic name remains unreviewed. */

undefined4
FUN_c0486f78(undefined4 param_1,int param_2,undefined4 *param_3,undefined4 *param_4,
            undefined4 *param_5,undefined4 param_6,uint param_7)

{
  undefined4 uVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_2 + 0x48);
  if (iVar2 == 0) {
    if ((param_7 & 1) == 0) {
      uVar1 = FUN_c0486b94(param_1,param_2,param_3);
      return uVar1;
    }
  }
  else if (iVar2 == 1) {
    if ((param_7 & 2) == 0) {
      uVar1 = FUN_c0486d48(param_1,param_2,param_4);
      return uVar1;
    }
  }
  else if ((iVar2 == 2) && ((param_7 & 4) == 0)) {
    uVar1 = FUN_c0486e60(param_1,param_2,param_5);
    return uVar1;
  }
  return 0;
}



/* c0487010 FUN_c0487010 */

/* Boundary evidence: original MIPS .pdata c0487010..c048720b. Semantic name remains unreviewed. */

DWORD FUN_c0487010(int param_1,undefined *param_2,undefined4 param_3,undefined4 param_4,
                  undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8)

{
  DWORD DVar1;
  int iVar2;
  DWORD local_d0;
  DWORD local_cc;
  undefined4 local_c8;
  undefined4 local_c0;
  undefined4 local_bc;
  undefined4 local_b8;
  undefined4 local_b4;
  undefined4 local_b0;
  undefined4 local_ac;
  undefined4 local_a8;
  undefined4 local_a4;
  undefined4 local_a0;
  undefined1 auStack_98 [20];
  undefined1 auStack_84 [88];
  uint local_2c;
  
  local_2c = DAT_c048f418;
  local_c8 = param_6;
  local_c0 = *(undefined4 *)(param_1 + 0x14);
  local_ac = 0;
  local_cc = 0x24;
  local_bc = *(undefined4 *)(param_1 + 0x18);
  local_d0 = 0x6c;
  local_b8 = *(undefined4 *)(param_1 + 0x1c);
  local_b4 = *(undefined4 *)(param_1 + 0x20);
  local_b0 = *(undefined4 *)(param_1 + 0x24);
  local_a8 = 0;
  local_a4 = 0;
  local_a0 = 0;
  DVar1 = FUN_c048d228(0x29,0x120008,&local_c0,&local_cc,auStack_98,&local_d0);
  while ((DVar1 == 0 &&
         ((iVar2 = memcmp(&local_ac,&DAT_c04810ac,0x10), iVar2 == 0 ||
          (DVar1 = (*(code *)param_2)(param_1,auStack_98,param_3,param_4,param_5,local_c8,param_7,
                                      param_8), DVar1 == 0))))) {
    iVar2 = memcmp(auStack_84,&DAT_c04810ac,0x10);
    if (iVar2 == 0) {
      FUN_c048e238(local_2c);
      return 0;
    }
    memcpy(&local_c0,auStack_98,0x24);
    local_cc = 0x24;
    local_d0 = 0x6c;
    DVar1 = FUN_c048d228(0x29,0x120008,&local_c0,&local_cc,auStack_98,&local_d0);
  }
  FUN_c048e238(local_2c);
  return DVar1;
}



/* c048720c FUN_c048720c */

/* Boundary evidence: original MIPS .pdata c048720c..c04872a7. Semantic name remains unreviewed. */

int FUN_c048720c(int *param_1,ulong param_2,int *param_3)

{
  ulong uVar1;
  int *piVar2;
  
  do {
    if (param_1 == (int *)0x0) {
      return 0;
    }
    for (piVar2 = param_1 + 0x6b; piVar2 != (int *)0x0; piVar2 = (int *)*piVar2) {
      uVar1 = inet_addr((char *)(piVar2 + 1));
      if (uVar1 == param_2) {
        *param_3 = (int)(param_1 + 0x43);
        return (int)(param_1 + 2);
      }
    }
    param_1 = (int *)*param_1;
  } while( true );
}



/* c04872a8 FUN_c04872a8 */

/* Boundary evidence: original MIPS .pdata c04872a8..c0487333. Semantic name remains unreviewed. */

void FUN_c04872a8(undefined4 *param_1,char *param_2)

{
  _snprintf(param_2,0x27,"{%08lX-%04X-%04X-%02X%02X-%02X%02X%02X%02X%02X%02X}",*param_1,
            (uint)*(ushort *)(param_1 + 1),(uint)*(ushort *)((int)param_1 + 6),
            (uint)*(byte *)(param_1 + 2),(uint)*(byte *)((int)param_1 + 9),
            (uint)*(byte *)((int)param_1 + 10),(uint)*(byte *)((int)param_1 + 0xb),
            (uint)*(byte *)(param_1 + 3),(uint)*(byte *)((int)param_1 + 0xd),
            (uint)*(byte *)((int)param_1 + 0xe),(uint)*(byte *)((int)param_1 + 0xf));
  param_2[0x26] = '\0';
  return;
}



/* c0487334 FUN_c0487334 */

/* Boundary evidence: original MIPS .pdata c0487334..c04873bb. Semantic name remains unreviewed. */

void FUN_c0487334(char *param_1,undefined4 *param_2)

{
  size_t sVar1;
  undefined1 auStack_80 [88];
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  uint local_18;
  
  local_18 = DAT_c048f418;
  MD5Init(auStack_80);
  sVar1 = strlen(param_1);
  MD5Update(auStack_80,param_1,sVar1);
  MD5Final(auStack_80);
  *param_2 = local_28;
  param_2[1] = local_24;
  param_2[2] = local_20;
  param_2[3] = local_1c;
  FUN_c048e238(local_18);
  return;
}



/* c04873bc FUN_c04873bc */

/* Boundary evidence: original MIPS .pdata c04873bc..c048749f. Semantic name remains unreviewed. */

int FUN_c04873bc(int *param_1,undefined4 *param_2,LPWSTR param_3)

{
  int iVar1;
  undefined4 auStack_50 [4];
  char acStack_40 [40];
  uint local_18;
  
  local_18 = DAT_c048f418;
  FUN_c04872a8(param_2,acStack_40);
  while( true ) {
    if (param_1 == (int *)0x0) {
      *param_3 = L'\0';
      FUN_c048e238(local_18);
      return 0;
    }
    FUN_c0487334((char *)(param_1 + 2),auStack_50);
    iVar1 = memcmp(param_2,auStack_50,0x10);
    if (iVar1 == 0) break;
    param_1 = (int *)*param_1;
  }
  iVar1 = MultiByteToWideChar(0,0,(LPCSTR)(param_1 + 0x43),-1,param_3,0x80);
  if (iVar1 == 0) {
    *param_3 = L'\0';
  }
  FUN_c048e238(local_18);
  return (int)(param_1 + 2);
}



/* c04874a0 FUN_c04874a0 */

/* Boundary evidence: original MIPS .pdata c04874a0..c0487593. Semantic name remains unreviewed. */

undefined4 FUN_c04874a0(undefined4 *param_1,void *param_2,SIZE_T param_3)

{
  HANDLE pvVar1;
  undefined4 *lpMem;
  LPVOID _Dst;
  
  pvVar1 = GetProcessHeap();
  lpMem = HeapAlloc(pvVar1,0,0x18);
  if (lpMem != (undefined4 *)0x0) {
    pvVar1 = GetProcessHeap();
    _Dst = HeapAlloc(pvVar1,0,param_3);
    if (_Dst != (LPVOID)0x0) {
      memcpy(_Dst,param_2,param_3);
      *(undefined4 **)*param_1 = lpMem;
      *param_1 = lpMem + 2;
      lpMem[2] = 0;
      *lpMem = 0x18;
      lpMem[4] = param_3;
      lpMem[3] = _Dst;
      return 0;
    }
    pvVar1 = GetProcessHeap();
    HeapFree(pvVar1,0,lpMem);
  }
  return 8;
}



/* c0487594 FUN_c0487594 */

/* Boundary evidence: original MIPS .pdata c0487594..c04876bb. Semantic name remains unreviewed. */

undefined4 FUN_c0487594(LPCSTR param_1)

{
  int iVar1;
  HANDLE hDevice;
  BOOL BVar2;
  undefined4 uVar3;
  DWORD aDStack_298 [2];
  undefined1 auStack_290 [4];
  WCHAR *local_28c;
  undefined4 local_27c;
  WCHAR aWStack_220 [260];
  uint local_18;
  
  local_18 = DAT_c048f418;
  uVar3 = 0;
  if (param_1 != (LPCSTR)0x0) {
    iVar1 = MultiByteToWideChar(0,0,param_1,-1,aWStack_220,0x104);
    if (iVar1 != 0) {
      hDevice = CreateFileW(L"UIO1:",0,0,(LPSECURITY_ATTRIBUTES)0x0,3,0x40000080,(HANDLE)0xffffffff)
      ;
      if (hDevice != (HANDLE)0xffffffff) {
        local_28c = aWStack_220;
        BVar2 = DeviceIoControl(hDevice,0x120824,(LPVOID)0x0,0,auStack_290,0x70,aDStack_298,
                                (LPOVERLAPPED)0x0);
        if (BVar2 != 0) {
          uVar3 = local_27c;
        }
        CloseHandle(hDevice);
      }
    }
  }
  FUN_c048e238(local_18);
  return uVar3;
}



/* c04876bc FUN_c04876bc */

/* Boundary evidence: original MIPS .pdata c04876bc..c048782f. Semantic name remains unreviewed. */

undefined4 FUN_c04876bc(void *param_1,int param_2,int *param_3,undefined4 *param_4)

{
  int iVar1;
  HANDLE pvVar2;
  undefined4 *lpMem;
  undefined2 *_Dst;
  int iVar3;
  
  iVar3 = *param_3;
  while( true ) {
    if (iVar3 == 0) {
      pvVar2 = GetProcessHeap();
      lpMem = HeapAlloc(pvVar2,0,0x18);
      if (lpMem != (undefined4 *)0x0) {
        pvVar2 = GetProcessHeap();
        _Dst = HeapAlloc(pvVar2,0,0x1c);
        if (_Dst != (undefined2 *)0x0) {
          memset(_Dst,0,0x1c);
          *_Dst = 0x17;
          memcpy(_Dst + 4,param_1,0x10);
          *(undefined4 **)*param_4 = lpMem;
          *param_4 = lpMem + 2;
          *lpMem = 0x18;
          lpMem[1] = 0;
          lpMem[2] = 0;
          lpMem[3] = _Dst;
          lpMem[4] = 0x1c;
          lpMem[5] = param_2;
          return 0;
        }
        pvVar2 = GetProcessHeap();
        HeapFree(pvVar2,0,lpMem);
      }
      return 8;
    }
    if (((*(int *)(iVar3 + 0x14) == param_2) && (**(short **)(iVar3 + 0xc) == 0x17)) &&
       (iVar1 = memcmp(*(short **)(iVar3 + 0xc) + 4,param_1,0x10), iVar1 == 0)) break;
    iVar3 = *(int *)(iVar3 + 8);
  }
  return 0;
}



/* c0487830 FUN_c0487830 */

/* Boundary evidence: original MIPS .pdata c0487830..c0487a3f. Semantic name remains unreviewed. */

DWORD FUN_c0487830(int param_1,undefined *param_2,undefined4 param_3,undefined4 param_4)

{
  bool bVar1;
  DWORD DVar2;
  int iVar3;
  DWORD local_100 [2];
  undefined1 auStack_f8 [40];
  short asStack_d0 [16];
  int local_b0;
  char local_a0;
  byte local_9f;
  undefined4 local_90;
  int local_8c;
  undefined1 auStack_68 [20];
  int local_54;
  uint local_30;
  
  local_30 = DAT_c048f418;
  bVar1 = false;
  memset(auStack_68,0,0x38);
  memcpy(&local_a0,auStack_68,0x38);
  local_100[0] = 0x38;
  local_100[1] = 0x54;
  DVar2 = FUN_c048d228(0x29,0x120034,&local_a0,local_100,auStack_f8,local_100 + 1);
  do {
    if (DVar2 != 0) {
LAB_c0487a04:
      FUN_c048e238(local_30);
      return DVar2;
    }
    memcpy(auStack_68,auStack_f8,0x38);
    memcpy(auStack_f8,&local_a0,0x38);
    if ((local_8c == param_1) && (local_a0 != -1)) {
      if ((local_a0 == -2) && ((local_9f & 0xc0) == 0x80)) {
        bVar1 = true;
      }
      if (((local_b0 != 2) && (iVar3 = FUN_c0486948(asStack_d0), iVar3 != 0)) &&
         (DVar2 = (*(code *)param_2)(auStack_f8,local_90,param_3,param_4), DVar2 != 0))
      goto LAB_c0487a04;
    }
    if (local_54 == 0) {
      if (bVar1) {
        DVar2 = (*(code *)param_2)(0xc048f160,0x40,param_3,param_4);
      }
      goto LAB_c0487a04;
    }
    memcpy(&local_a0,auStack_68,0x38);
    local_100[0] = 0x38;
    local_100[1] = 0x54;
    DVar2 = FUN_c048d228(0x29,0x120034,&local_a0,local_100,auStack_f8,local_100 + 1);
  } while( true );
}



/* c0487a40 FUN_c0487a40 */

/* Boundary evidence: original MIPS .pdata c0487a40..c0487c63. Semantic name remains unreviewed. */

DWORD FUN_c0487a40(undefined *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                  undefined4 param_5,undefined4 param_6)

{
  HANDLE pvVar1;
  int *lpMem;
  DWORD DVar2;
  int iVar3;
  int iVar4;
  DWORD local_48 [4];
  int local_38;
  int local_34;
  int local_30;
  uint local_2c;
  
  local_2c = DAT_c048f418;
  pvVar1 = GetProcessHeap();
  lpMem = HeapAlloc(pvVar1,0,0x158);
  if (lpMem == (int *)0x0) {
    FUN_c048e238(local_2c);
    return 8;
  }
  local_48[2] = -1;
  do {
    local_48[1] = 0x14;
    local_48[0] = 0x158;
    DVar2 = FUN_c048d228(0x29,0x120004,local_48 + 2,local_48 + 1,lpMem,local_48);
    if (DVar2 == 0) {
      if (local_48[2] != -1) {
        if ((0xd7 < local_48[0]) && (0xd7 < (uint)lpMem[10])) {
          if (lpMem[0xc] == 0) {
            iVar4 = 0;
          }
          else {
            iVar4 = lpMem[0xb];
          }
          if (lpMem[0xd] == 0) {
            iVar3 = 0;
          }
          else {
            iVar3 = lpMem[0xb];
          }
          if (local_48[0] == lpMem[10] + iVar3 + iVar4) {
            DVar2 = (*(code *)param_1)(lpMem,param_2,param_3,param_4,param_5,param_6);
            if (DVar2 == 0) goto LAB_c0487bbc;
            goto LAB_c0487c10;
          }
        }
        DVar2 = 0x57;
LAB_c0487c10:
        pvVar1 = GetProcessHeap();
        HeapFree(pvVar1,0,lpMem);
        FUN_c048e238(local_2c);
        return DVar2;
      }
    }
    else {
      if (DVar2 != 0xc00000f0) {
        if (DVar2 == 2) {
          DVar2 = 0;
        }
        goto LAB_c0487c10;
      }
      DVar2 = 0;
    }
LAB_c0487bbc:
    if (*lpMem == -1) goto LAB_c0487c10;
    local_48[3] = lpMem[1];
    local_38 = lpMem[2];
    local_34 = lpMem[3];
    local_30 = lpMem[4];
    local_48[2] = *lpMem;
  } while( true );
}



/* c0487c64 FUN_c0487c64 */

/* Boundary evidence: original MIPS .pdata c0487c64..c0487da3. Semantic name remains unreviewed. */

undefined4 FUN_c0487c64(undefined4 param_1,int param_2,int *param_3,undefined4 *param_4)

{
  HANDLE pvVar1;
  undefined4 *lpMem;
  undefined2 *_Dst;
  int iVar2;
  
  iVar2 = *param_3;
  while( true ) {
    if (iVar2 == 0) {
      pvVar1 = GetProcessHeap();
      lpMem = HeapAlloc(pvVar1,0,0x18);
      if (lpMem != (undefined4 *)0x0) {
        pvVar1 = GetProcessHeap();
        _Dst = HeapAlloc(pvVar1,0,0x10);
        if (_Dst != (undefined2 *)0x0) {
          memset(_Dst,0,0x10);
          *_Dst = 2;
          *(int *)(_Dst + 2) = param_2;
          *(undefined4 **)*param_4 = lpMem;
          *param_4 = lpMem + 2;
          lpMem[2] = 0;
          *lpMem = 0x18;
          lpMem[1] = 0;
          lpMem[4] = 0x10;
          lpMem[3] = _Dst;
          return 0;
        }
        pvVar1 = GetProcessHeap();
        HeapFree(pvVar1,0,lpMem);
      }
      return 8;
    }
    if ((**(short **)(iVar2 + 0xc) == 2) && (*(int *)(*(short **)(iVar2 + 0xc) + 2) == param_2))
    break;
    iVar2 = *(int *)(iVar2 + 8);
  }
  return 0;
}



/* c0487da4 FUN_c0487da4 */

/* Boundary evidence: original MIPS .pdata c0487da4..c04880b3. Semantic name remains unreviewed. */

DWORD FUN_c0487da4(int param_1,uint *param_2,undefined4 *param_3,int *param_4,undefined4 *param_5,
                  uint *param_6,uint param_7)

{
  HANDLE pvVar1;
  undefined4 *lpMem;
  undefined2 *_Dst;
  int iVar2;
  DWORD DVar3;
  int *lpMem_00;
  int *piVar4;
  uint uVar5;
  uint uVar6;
  int *local_48 [2];
  _FILETIME _Stack_40;
  _SYSTEMTIME _Stack_38;
  
  uVar5 = *param_2;
  if (uVar5 == 0) {
    return 0;
  }
  if ((uVar5 & 0xff) == 0) {
    *param_6 = *param_6 | 8;
    return 0;
  }
  if ((param_7 & 1) == 0) {
    local_48[0] = param_4;
    pvVar1 = GetProcessHeap();
    lpMem = HeapAlloc(pvVar1,0,0x30);
    if (lpMem == (undefined4 *)0x0) {
      return 8;
    }
    pvVar1 = GetProcessHeap();
    _Dst = HeapAlloc(pvVar1,0,0x10);
    if (_Dst == (undefined2 *)0x0) {
      pvVar1 = GetProcessHeap();
      HeapFree(pvVar1,0,lpMem);
      return 8;
    }
    memset(_Dst,0,0x10);
    *_Dst = 2;
    *(uint *)(_Dst + 2) = uVar5;
    *(undefined4 **)*param_3 = lpMem;
    *param_3 = lpMem + 2;
    GetSystemTime(&_Stack_38);
    SystemTimeToFileTime(&_Stack_38,&_Stack_40);
    lpMem[2] = 0;
    *lpMem = 0x30;
    iVar2 = FUN_c0486b3c(&_Stack_40.dwLowDateTime);
    iVar2 = *(int *)(param_1 + 0x27c) - iVar2;
    lpMem[10] = iVar2;
    lpMem[9] = iVar2;
    lpMem[8] = iVar2;
    lpMem[1] = 0;
    lpMem[4] = 0x10;
    lpMem[3] = _Dst;
    lpMem[5] = 1;
    lpMem[6] = 1;
    if (*(int *)(param_1 + 0x1a4) != 0) {
      if ((uVar5 & 0xffff) == 0xfea9) {
        lpMem[5] = 2;
        lpMem[6] = 5;
      }
      else {
        lpMem[5] = 3;
        lpMem[6] = 3;
      }
    }
    lpMem[7] = 4;
    if (((lpMem[6] != 5) && (uVar5 != 0x7f000001)) && ((uVar5 & 0xffff) != 0xfea9)) {
      lpMem[1] = 1;
    }
    param_4 = local_48[0];
    if ((*(ushort *)((int)param_2 + 0x16) & 0x80) != 0) {
      lpMem[1] = lpMem[1] | 2;
    }
  }
  if ((param_7 & 4) != 0) {
    return 0;
  }
  local_48[0] = (int *)0x0;
  lpMem_00 = (int *)0x0;
  DVar3 = FUN_c04818b0(uVar5,(LPVOID)0x0,(LPDWORD)local_48);
  if (DVar3 == 0x7a) {
    pvVar1 = GetProcessHeap();
    lpMem_00 = HeapAlloc(pvVar1,0,(SIZE_T)local_48[0]);
    if (lpMem_00 == (int *)0x0) {
      return 8;
    }
    DVar3 = FUN_c04818b0(uVar5,lpMem_00,(LPDWORD)local_48);
  }
  if (DVar3 == 0) {
    uVar6 = (uint)local_48[0] >> 2;
    uVar5 = 0;
    piVar4 = lpMem_00;
    if (uVar6 != 0) {
      do {
        if (DVar3 != 0) break;
        DVar3 = FUN_c0487c64(param_1,*piVar4,param_4,param_5);
        uVar5 = uVar5 + 1;
        piVar4 = piVar4 + 1;
      } while (uVar5 < uVar6);
    }
  }
  if (lpMem_00 != (int *)0x0) {
    pvVar1 = GetProcessHeap();
    HeapFree(pvVar1,0,lpMem_00);
    return DVar3;
  }
  return DVar3;
}



/* c04880b4 FUN_c04880b4 */

/* Boundary evidence: original MIPS .pdata c04880b4..c0488193. Semantic name remains unreviewed. */

int FUN_c04880b4(int param_1,undefined *param_2,undefined4 param_3,undefined4 param_4,
                undefined4 param_5,undefined4 param_6,undefined4 param_7,uint *param_8)

{
  int iVar1;
  uint *puVar2;
  uint uVar3;
  
  uVar3 = 0;
  if (*param_8 != 0) {
    puVar2 = param_8 + 2;
    do {
      if ((*puVar2 == *(uint *)(param_1 + 0x19c)) &&
         (iVar1 = (*(code *)param_2)(param_1,puVar2 + -1,param_3,param_4,param_5,param_6,param_7),
         iVar1 != 0)) {
        return iVar1;
      }
      uVar3 = uVar3 + 1;
      puVar2 = puVar2 + 6;
    } while (uVar3 < *param_8);
  }
  return 0;
}



/* c0488194 FUN_c0488194 */

/* Boundary evidence: original MIPS .pdata c0488194..c04882ef. Semantic name remains unreviewed. */

undefined4 FUN_c0488194(int param_1,int param_2,int *param_3,undefined4 *param_4)

{
  HANDLE pvVar1;
  undefined4 *lpMem;
  undefined2 *_Dst;
  int iVar2;
  
  iVar2 = *param_3;
  while( true ) {
    if (iVar2 == 0) {
      pvVar1 = GetProcessHeap();
      lpMem = HeapAlloc(pvVar1,0,0x18);
      if (lpMem != (undefined4 *)0x0) {
        pvVar1 = GetProcessHeap();
        _Dst = HeapAlloc(pvVar1,0,0x10);
        if (_Dst != (undefined2 *)0x0) {
          memset(_Dst,0,0x10);
          *_Dst = 2;
          *(int *)(_Dst + 2) = param_1;
          *(undefined4 **)*param_4 = lpMem;
          *param_4 = lpMem + 2;
          *lpMem = 0x18;
          lpMem[1] = 0;
          lpMem[2] = 0;
          lpMem[3] = _Dst;
          lpMem[4] = 0x10;
          lpMem[5] = param_2;
          return 0;
        }
        pvVar1 = GetProcessHeap();
        HeapFree(pvVar1,0,lpMem);
      }
      return 8;
    }
    if (((*(int *)(iVar2 + 0x14) == param_2) && (**(short **)(iVar2 + 0xc) == 2)) &&
       (*(int *)(*(short **)(iVar2 + 0xc) + 2) == param_1)) break;
    iVar2 = *(int *)(iVar2 + 8);
  }
  return 0;
}



/* c04882f0 FUN_c04882f0 */

/* Boundary evidence: original MIPS .pdata c04882f0..c04883f3. Semantic name remains unreviewed. */

int FUN_c04882f0(int param_1,undefined *param_2,undefined4 param_3,undefined4 param_4)

{
  ulong netlong;
  ulong uVar1;
  u_long uVar2;
  int iVar3;
  uint uVar4;
  int *piVar5;
  
  piVar5 = (int *)(param_1 + 0x1ac);
  do {
    if (piVar5 == (int *)0x0) {
      return 0;
    }
    if (*(char *)(piVar5 + 1) != '\0') {
      netlong = inet_addr((char *)(piVar5 + 5));
      uVar1 = inet_addr((char *)(piVar5 + 1));
      uVar2 = ntohl(netlong);
      uVar4 = 0;
      do {
        if ((1 << (uVar4 & 0x1f) & uVar2) != 0) break;
        uVar4 = uVar4 + 1;
      } while ((int)uVar4 < 0x20);
      iVar3 = (*(code *)param_2)(uVar1 & netlong,0x20 - uVar4,param_3,param_4);
      if (iVar3 != 0) {
        return iVar3;
      }
    }
    piVar5 = (int *)*piVar5;
  } while( true );
}



/* c04883f4 FUN_c04883f4 */

/* Boundary evidence: original MIPS .pdata c04883f4..c04884bb. Semantic name remains unreviewed. */

void FUN_c04883f4(undefined *param_1,undefined4 param_2,undefined4 param_3,int *param_4,
                 undefined4 param_5,undefined4 param_6,undefined4 param_7)

{
  int iVar1;
  
  while( true ) {
    if (param_4 == (int *)0x0) {
      (*(code *)param_1)(0xc048f194,param_2,param_3,param_5,param_6,param_7);
      return;
    }
    if ((*(char *)(param_4 + 2) != '\0') &&
       (iVar1 = (*(code *)param_1)(param_4,param_2,param_3,param_5,param_6,param_7), iVar1 != 0))
    break;
    param_4 = (int *)*param_4;
  }
  return;
}



/* c04884bc FUN_c04884bc */

/* Boundary evidence: original MIPS .pdata c04884bc..c0488583. Semantic name remains unreviewed. */

bool FUN_c04884bc(int param_1,undefined4 param_2,REGSAM param_3,PHKEY param_4)

{
  LSTATUS LVar1;
  wchar_t *pszFormat;
  wchar_t awStack_268 [298];
  uint local_14;
  
  local_14 = DAT_c048f418;
  if (param_1 == 1) {
    pszFormat = L"Comm\\%hs\\Parms\\TcpIp";
  }
  else {
    if (param_1 != 3) {
      FUN_c048e238(DAT_c048f418);
      return false;
    }
    pszFormat = L"Comm\\%hs\\Parms\\TcpIp6";
  }
  StringCchPrintfW(awStack_268,0x12a,pszFormat,param_2);
  LVar1 = RegOpenKeyExW((HKEY)0x80000002,awStack_268,0,param_3,param_4);
  FUN_c048e238(local_14);
  return LVar1 == 0;
}



/* c0488584 FUN_c0488584 */

/* Boundary evidence: original MIPS .pdata c0488584..c04885eb. Semantic name remains unreviewed. */

undefined4 FUN_c0488584(HKEY param_1,LPCWSTR param_2,LPBYTE param_3)

{
  LSTATUS LVar1;
  undefined4 uVar2;
  DWORD local_10;
  DWORD local_c;
  
  local_10 = 4;
  LVar1 = RegQueryValueExW(param_1,param_2,(LPDWORD)0x0,&local_c,param_3,&local_10);
  if (((LVar1 != 0) || (local_c != 4)) || (uVar2 = 1, local_10 != 4)) {
    uVar2 = 0;
  }
  return uVar2;
}



/* c04885ec FUN_c04885ec */

/* Boundary evidence: original MIPS .pdata c04885ec..c0488687. Semantic name remains unreviewed. */

void FUN_c04885ec(void)

{
  if (DAT_c048f12c != -1) {
    RegCloseKey((HKEY)DAT_c048f12c);
  }
  if (DAT_c048f130 != -1) {
    RegCloseKey((HKEY)DAT_c048f130);
  }
  if (DAT_c048f128 != -1) {
    RegCloseKey((HKEY)DAT_c048f128);
  }
  if (DAT_c048f124 != -1) {
    RegCloseKey((HKEY)DAT_c048f124);
  }
  return;
}



/* c0488688 FUN_c0488688 */

/* Boundary evidence: original MIPS .pdata c0488688..c04886d3. Semantic name remains unreviewed. */

void FUN_c0488688(HLOCAL param_1)

{
  undefined4 *hMem;
  HLOCAL pvVar1;
  
  hMem = *(HLOCAL *)((int)param_1 + 0x10c);
  while (hMem != (HLOCAL)0x0) {
    pvVar1 = (HLOCAL)*hMem;
    LocalFree(hMem);
    hMem = pvVar1;
  }
  LocalFree(param_1);
  return;
}



/* c04886d4 FUN_c04886d4 */

/* Boundary evidence: original MIPS .pdata c04886d4..c048876b. Semantic name remains unreviewed. */

void FUN_c04886d4(undefined4 *param_1)

{
  undefined4 *puVar1;
  HLOCAL pvVar2;
  
  while (param_1 != (HLOCAL)0x0) {
    puVar1 = (HLOCAL)param_1[0x6b];
    while (puVar1 != (HLOCAL)0x0) {
      pvVar2 = (HLOCAL)*puVar1;
      LocalFree(puVar1);
      puVar1 = pvVar2;
    }
    puVar1 = (HLOCAL)param_1[0x75];
    while (puVar1 != (HLOCAL)0x0) {
      pvVar2 = (HLOCAL)*puVar1;
      LocalFree(puVar1);
      puVar1 = pvVar2;
    }
    puVar1 = (HLOCAL)param_1[0x94];
    while (puVar1 != (HLOCAL)0x0) {
      pvVar2 = (HLOCAL)*puVar1;
      LocalFree(puVar1);
      puVar1 = pvVar2;
    }
    pvVar2 = (HLOCAL)*param_1;
    LocalFree(param_1);
    param_1 = pvVar2;
  }
  return;
}



/* c048876c FUN_c048876c */

/* Boundary evidence: original MIPS .pdata c048876c..c0488977. Semantic name remains unreviewed. */

void FUN_c048876c(LPVOID param_1)

{
  HANDLE pvVar1;
  LPVOID pvVar2;
  LPVOID pvVar3;
  
  while (param_1 != (LPVOID)0x0) {
    pvVar1 = GetProcessHeap();
    HeapFree(pvVar1,0,*(LPVOID *)((int)param_1 + 0x24));
    pvVar1 = GetProcessHeap();
    HeapFree(pvVar1,0,*(LPVOID *)((int)param_1 + 0x28));
    pvVar1 = GetProcessHeap();
    HeapFree(pvVar1,0,*(LPVOID *)((int)param_1 + 0x20));
    pvVar1 = GetProcessHeap();
    HeapFree(pvVar1,0,*(LPVOID *)((int)param_1 + 0xc));
    pvVar3 = *(LPVOID *)((int)param_1 + 0x10);
    while (pvVar3 != (LPVOID)0x0) {
      pvVar1 = GetProcessHeap();
      HeapFree(pvVar1,0,*(LPVOID *)((int)pvVar3 + 0xc));
      pvVar2 = *(LPVOID *)((int)pvVar3 + 8);
      pvVar1 = GetProcessHeap();
      HeapFree(pvVar1,0,pvVar3);
      pvVar3 = pvVar2;
    }
    pvVar3 = *(LPVOID *)((int)param_1 + 0x14);
    while (pvVar3 != (LPVOID)0x0) {
      pvVar1 = GetProcessHeap();
      HeapFree(pvVar1,0,*(LPVOID *)((int)pvVar3 + 0xc));
      pvVar2 = *(LPVOID *)((int)pvVar3 + 8);
      pvVar1 = GetProcessHeap();
      HeapFree(pvVar1,0,pvVar3);
      pvVar3 = pvVar2;
    }
    pvVar3 = *(LPVOID *)((int)param_1 + 0x18);
    while (pvVar3 != (LPVOID)0x0) {
      pvVar1 = GetProcessHeap();
      HeapFree(pvVar1,0,*(LPVOID *)((int)pvVar3 + 0xc));
      pvVar2 = *(LPVOID *)((int)pvVar3 + 8);
      pvVar1 = GetProcessHeap();
      HeapFree(pvVar1,0,pvVar3);
      pvVar3 = pvVar2;
    }
    pvVar3 = *(LPVOID *)((int)param_1 + 0x1c);
    while (pvVar3 != (LPVOID)0x0) {
      pvVar1 = GetProcessHeap();
      HeapFree(pvVar1,0,*(LPVOID *)((int)pvVar3 + 0xc));
      pvVar2 = *(LPVOID *)((int)pvVar3 + 8);
      pvVar1 = GetProcessHeap();
      HeapFree(pvVar1,0,pvVar3);
      pvVar3 = pvVar2;
    }
    pvVar3 = *(LPVOID *)((int)param_1 + 0x8c);
    while (pvVar3 != (LPVOID)0x0) {
      pvVar1 = GetProcessHeap();
      HeapFree(pvVar1,0,*(LPVOID *)((int)pvVar3 + 0xc));
      pvVar2 = *(LPVOID *)((int)pvVar3 + 8);
      pvVar1 = GetProcessHeap();
      HeapFree(pvVar1,0,pvVar3);
      pvVar3 = pvVar2;
    }
    pvVar3 = *(LPVOID *)((int)param_1 + 8);
    pvVar1 = GetProcessHeap();
    HeapFree(pvVar1,0,param_1);
    param_1 = pvVar3;
  }
  return;
}



/* c0488978 FUN_c0488978 */

/* Boundary evidence: original MIPS .pdata c0488978..c04889c3. Semantic name remains unreviewed. */

void FUN_c0488978(HLOCAL param_1)

{
  undefined4 *hMem;
  HLOCAL pvVar1;
  
  hMem = *(HLOCAL *)((int)param_1 + 0xc);
  while (hMem != (HLOCAL)0x0) {
    pvVar1 = (HLOCAL)*hMem;
    LocalFree(hMem);
    hMem = pvVar1;
  }
  LocalFree(param_1);
  return;
}



/* c04889c4 FUN_c04889c4 */

int FUN_c04889c4(int *param_1)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar1 = 0;
  for (; param_1 != (int *)0x0; param_1 = (int *)*param_1) {
    iVar3 = 0;
    for (piVar2 = (int *)param_1[0x6b]; piVar2 != (int *)0x0; piVar2 = (int *)*piVar2) {
      iVar3 = iVar3 + 1;
    }
    iVar5 = 0;
    for (piVar2 = (int *)param_1[0x75]; piVar2 != (int *)0x0; piVar2 = (int *)*piVar2) {
      iVar5 = iVar5 + 1;
    }
    iVar4 = 0;
    for (piVar2 = (int *)param_1[0x94]; piVar2 != (int *)0x0; piVar2 = (int *)*piVar2) {
      iVar4 = iVar4 + 1;
    }
    iVar1 = (iVar4 + iVar5 + iVar3 + 0x10) * 0x28 + iVar1;
  }
  return iVar1;
}



/* c0488a40 FUN_c0488a40 */

/* Boundary evidence: original MIPS .pdata c0488a40..c0488bb3. Semantic name remains unreviewed. */

uint FUN_c0488a40(int param_1)

{
  size_t sVar1;
  size_t sVar2;
  size_t sVar3;
  size_t sVar4;
  int iVar5;
  uint uVar6;
  
  uVar6 = 0;
  for (; param_1 != 0; param_1 = *(int *)(param_1 + 8)) {
    sVar1 = wcslen(*(wchar_t **)(param_1 + 0x28));
    sVar2 = wcslen(*(wchar_t **)(param_1 + 0x24));
    sVar3 = wcslen(*(wchar_t **)(param_1 + 0x20));
    sVar4 = strlen(*(char **)(param_1 + 0xc));
    uVar6 = (sVar3 + sVar2 + sVar1 + 0x51) * 2 + sVar4 + uVar6 & 0xfffffffc;
    for (iVar5 = *(int *)(param_1 + 0x10); iVar5 != 0; iVar5 = *(int *)(iVar5 + 8)) {
      uVar6 = (*(int *)(iVar5 + 0x10) + 3U & 0xfffffffc) + uVar6 + 0x30;
    }
    for (iVar5 = *(int *)(param_1 + 0x14); iVar5 != 0; iVar5 = *(int *)(iVar5 + 8)) {
      uVar6 = (*(int *)(iVar5 + 0x10) + 3U & 0xfffffffc) + uVar6 + 0x18;
    }
    for (iVar5 = *(int *)(param_1 + 0x18); iVar5 != 0; iVar5 = *(int *)(iVar5 + 8)) {
      uVar6 = (*(int *)(iVar5 + 0x10) + 3U & 0xfffffffc) + uVar6 + 0x18;
    }
    for (iVar5 = *(int *)(param_1 + 0x1c); iVar5 != 0; iVar5 = *(int *)(iVar5 + 8)) {
      uVar6 = (*(int *)(iVar5 + 0x10) + 3U & 0xfffffffc) + uVar6 + 0x18;
    }
    for (iVar5 = *(int *)(param_1 + 0x8c); iVar5 != 0; iVar5 = *(int *)(iVar5 + 8)) {
      uVar6 = (*(int *)(iVar5 + 0x10) + 3U & 0xfffffffc) + uVar6 + 0x18;
    }
  }
  return uVar6;
}



/* c0488bb4 GetAdapterOrderMap */

/* Boundary evidence: original MIPS .pdata c0488bb4..c0488cab. Semantic name remains unreviewed. */

uint * GetAdapterOrderMap(void)

{
  DWORD DVar1;
  uint *hMem;
  uint *puVar2;
  uint uVar3;
  uint *puVar4;
  uint *puVar5;
  DWORD local_18 [2];
  
                    /* 0x8bb4  14  GetAdapterOrderMap */
  local_18[0] = 0;
  DVar1 = GetInterfaceInfo((LPVOID)0x0,local_18);
  if (((DVar1 == 0x7a) || (DVar1 == 0x6f)) &&
     (hMem = LocalAlloc(0,local_18[0]), hMem != (uint *)0x0)) {
    DVar1 = GetInterfaceInfo(hMem,local_18);
    if ((DVar1 == 0) && (puVar2 = LocalAlloc(0,(*hMem + 1) * 4), puVar2 != (uint *)0x0)) {
      uVar3 = 0;
      if (*hMem != 0) {
        puVar5 = hMem + 1;
        puVar4 = puVar2;
        do {
          puVar4 = puVar4 + 1;
          uVar3 = uVar3 + 1;
          *puVar4 = *puVar5;
          puVar5 = puVar5 + 0x41;
        } while (uVar3 < *hMem);
      }
      *puVar2 = uVar3;
      LocalFree(hMem);
      LocalFree((HLOCAL)0x0);
      return puVar2;
    }
    LocalFree(hMem);
  }
  return (uint *)0x0;
}



/* c0488cac FUN_c0488cac */

/* Boundary evidence: original MIPS .pdata c0488cac..c0488d03. Semantic name remains unreviewed. */

undefined4 FUN_c0488cac(undefined4 param_1,int param_2)

{
  bool bVar1;
  undefined3 extraout_var;
  undefined4 uVar2;
  uint auStack_10 [2];
  
  uVar2 = 1;
  if (param_2 == 0) {
    FUN_c04885ec();
  }
  else if ((param_2 == 1) && (bVar1 = FUN_c0486aa8(auStack_10), CONCAT31(extraout_var,bVar1) == 0))
  {
    FUN_c04885ec();
    uVar2 = 0;
  }
  return uVar2;
}



/* c0488d04 FUN_c0488d04 */

/* Boundary evidence: original MIPS .pdata c0488d04..c0488daf. Semantic name remains unreviewed. */

int * FUN_c0488d04(void)

{
  DWORD DVar1;
  int *hMem;
  DWORD local_10 [2];
  
  local_10[0] = 0;
  hMem = (int *)0x0;
  while( true ) {
    DVar1 = GetInterfaceInfo(hMem,local_10);
    if ((DVar1 != 0x7a) && (DVar1 != 0x6f)) {
      if ((DVar1 == 0) && (*hMem != 0)) {
        return hMem;
      }
      if (hMem != (int *)0x0) {
        LocalFree(hMem);
      }
      return (int *)0x0;
    }
    if (hMem != (int *)0x0) {
      LocalFree(hMem);
    }
    if (local_10[0] == 0) break;
    hMem = LocalAlloc(0,local_10[0]);
    if (hMem == (int *)0x0) {
      return (int *)0x0;
    }
  }
  return (int *)0x0;
}



/* c0488db0 FUN_c0488db0 */

/* Boundary evidence: original MIPS .pdata c0488db0..c0488eeb. Semantic name remains unreviewed. */

undefined4 FUN_c0488db0(HKEY param_1,LPCWSTR param_2,LPSTR param_3,int *param_4)

{
  LSTATUS LVar1;
  LPCWSTR lpWideCharStr;
  SIZE_T local_28;
  DWORD local_24;
  
  *param_3 = '\0';
  LVar1 = RegQueryValueExW(param_1,param_2,(LPDWORD)0x0,&local_24,(LPBYTE)0x0,&local_28);
  if (((LVar1 == 0) &&
      (((local_24 == 1 || (local_24 == 7)) &&
       (lpWideCharStr = LocalAlloc(0,local_28), lpWideCharStr != (LPCWSTR)0x0)))) &&
     (LVar1 = RegQueryValueExW(param_1,param_2,(LPDWORD)0x0,&local_24,(LPBYTE)lpWideCharStr,
                               &local_28), LVar1 == 0)) {
    WideCharToMultiByte(0,0,lpWideCharStr,local_28 >> 1,param_3,*param_4,(LPCSTR)0x0,(LPBOOL)0x0);
    LocalFree(lpWideCharStr);
    return 1;
  }
  return 0;
}



/* c0488eec FUN_c0488eec */

/* Boundary evidence: original MIPS .pdata c0488eec..c048917b. Semantic name remains unreviewed. */

undefined4 FUN_c0488eec(HKEY param_1,LPCWSTR param_2,int *param_3)

{
  undefined4 *puVar1;
  LSTATUS LVar2;
  char *_Str;
  int iVar3;
  undefined4 *hMem;
  size_t sVar4;
  char *pcVar5;
  size_t sVar6;
  int iVar7;
  undefined4 *puVar8;
  uint local_30;
  DWORD local_2c;
  
  LVar2 = RegQueryValueExW(param_1,param_2,(LPDWORD)0x0,&local_2c,(LPBYTE)0x0,&local_30);
  if (LVar2 != 0) {
    return 0;
  }
  if (((local_30 < 2) || (local_2c != 1)) && ((local_30 < 3 || (local_2c != 7)))) {
    iVar3 = 3;
    goto LAB_c048913c;
  }
  _Str = LocalAlloc(0,local_30);
  if (_Str == (char *)0x0) {
    return 0;
  }
  iVar3 = FUN_c0488db0(param_1,param_2,_Str,(int *)&local_30);
  if ((iVar3 == 0) || (local_30 < 2)) {
    iVar3 = 3;
  }
  else {
    hMem = LocalAlloc(0,(local_30 >> 1) << 2);
    if (hMem == (undefined4 *)0x0) {
      iVar3 = 8;
    }
    else {
      iVar3 = 0;
      if (local_2c == 1) {
        sVar4 = strspn(_Str," \t,;");
        *hMem = _Str + sVar4;
        iVar7 = 1;
        pcVar5 = strpbrk(_Str + sVar4," \t,;");
        puVar1 = hMem;
        if (pcVar5 != (char *)0x0) {
          puVar8 = hMem + 1;
          do {
            *pcVar5 = '\0';
            sVar4 = strspn(pcVar5 + 1," \t,;");
            pcVar5 = pcVar5 + 1 + sVar4;
            *puVar8 = pcVar5;
            if (*pcVar5 != '\0') {
              iVar7 = iVar7 + 1;
              puVar8 = puVar8 + 1;
            }
            pcVar5 = strpbrk(pcVar5," \t,;");
          } while (pcVar5 != (char *)0x0);
        }
        for (; iVar7 != 0; iVar7 = iVar7 + -1) {
          FUN_c048d440(param_3,(char *)*puVar1,"");
          puVar1 = puVar1 + 1;
        }
      }
      else {
        if (local_2c == 7) {
          iVar7 = 0;
          sVar4 = strlen(_Str);
          pcVar5 = _Str;
          if (sVar4 != 0) {
            do {
              FUN_c048d440(param_3,pcVar5,"");
              sVar4 = strlen(pcVar5);
              iVar7 = iVar7 + 1;
              sVar6 = strlen(pcVar5 + sVar4 + 1);
              pcVar5 = pcVar5 + sVar4 + 1;
            } while (sVar6 != 0);
            if (iVar7 != 0) goto LAB_c048910c;
          }
        }
        iVar3 = 3;
      }
LAB_c048910c:
      LocalFree(hMem);
    }
  }
  LocalFree(_Str);
LAB_c048913c:
  if (iVar3 != 0) {
    return 0;
  }
  return 1;
}



/* c048917c FUN_c048917c */

/* Boundary evidence: original MIPS .pdata c048917c..c04894ef. Semantic name remains unreviewed. */

int * FUN_c048917c(void)

{
  bool bVar1;
  int *piVar2;
  int *piVar3;
  undefined3 extraout_var;
  LSTATUS LVar4;
  size_t sVar5;
  int *piVar6;
  wchar_t *_Str;
  int iVar7;
  HKEY local_370;
  wchar_t *local_36c;
  DWORD DStack_368;
  int local_364 [2];
  int *local_35c;
  BYTE aBStack_358 [4];
  BYTE aBStack_354 [4];
  CHAR aCStack_350 [16];
  CHAR CStack_340;
  char acStack_33f [263];
  WCHAR local_238 [260];
  uint local_30;
  
  local_30 = DAT_c048f418;
  piVar2 = FUN_c0488d04();
  if (piVar2 == (int *)0x0) {
    piVar2 = (int *)0x0;
  }
  else {
    piVar3 = FUN_c048d51c();
    local_35c = piVar3;
    if ((piVar3 != (int *)0x0) && (iVar7 = 0, 0 < *piVar2)) {
      _Str = (wchar_t *)(piVar2 + 2);
      do {
        piVar6 = piVar3;
        do {
          if (piVar6[0x67] == *(int *)(_Str + -2)) {
            sVar5 = wcslen(_Str);
            sVar5 = wcstombs((char *)(piVar6 + 2),_Str,sVar5 + 1);
            if (sVar5 == 0xffffffff) {
              *(undefined1 *)(piVar6 + 2) = 0;
            }
            break;
          }
          piVar6 = (int *)*piVar6;
        } while (piVar6 != (int *)0x0);
        iVar7 = iVar7 + 1;
        _Str = _Str + 0x82;
      } while (iVar7 < *piVar2);
    }
    LocalFree(piVar2);
    piVar2 = piVar3;
    if (piVar3 != (int *)0x0) {
      local_36c = L"LeaseObtainedHigh";
      do {
        if (((char)piVar3[2] != '\0') &&
           (bVar1 = FUN_c04884bc(1,piVar3 + 2,0x20019,&local_370), CONCAT31(extraout_var,bVar1) != 0
           )) {
          FUN_c0488584(local_370,L"EnableDHCP",(LPBYTE)(piVar3 + 0x69));
          if (piVar3[0x69] != 0) {
            FUN_c0488584(local_370,L"Lease",(LPBYTE)local_364);
            FUN_c0488584(local_370,L"LeaseObtainedHigh",aBStack_354);
            FUN_c0488584(local_370,L"LeaseObtainedLow",aBStack_358);
            iVar7 = FUN_c0486b3c((undefined4 *)aBStack_358);
            piVar3[0x9e] = iVar7;
            piVar3[0x9f] = iVar7 + local_364[0];
          }
          local_364[1] = 0x10;
          iVar7 = FUN_c0488db0(local_370,L"DhcpServer",aCStack_350,local_364 + 1);
          if (iVar7 != 0) {
            FUN_c048d440(piVar3 + 0x7f,aCStack_350,"");
          }
          local_36c = (wchar_t *)0x208;
          LVar4 = RegQueryValueExW(local_370,L"WINS",(LPDWORD)0x0,&DStack_368,(LPBYTE)local_238,
                                   (LPDWORD)&local_36c);
          if ((LVar4 == 0) && (local_238[0] != L'\0')) {
LAB_c04893f8:
            piVar3[0x89] = 1;
            WideCharToMultiByte(0,0,local_238,0x104,&CStack_340,0x104,(LPCSTR)0x0,(LPBOOL)0x0);
            if (local_36c != (wchar_t *)0x0) {
              FUN_c048d440(piVar3 + 0x8a,&CStack_340,"");
              sVar5 = strlen(&CStack_340);
              if (sVar5 + 1 < (uint)local_36c >> 1) {
                sVar5 = strlen(&CStack_340);
                FUN_c048d440(piVar3 + 0x94,acStack_33f + sVar5,"");
              }
            }
          }
          else {
            local_36c = (wchar_t *)0x208;
            LVar4 = RegQueryValueExW(local_370,L"DhcpWINS",(LPDWORD)0x0,&DStack_368,
                                     (LPBYTE)local_238,(LPDWORD)&local_36c);
            if (LVar4 == 0) goto LAB_c04893f8;
          }
          RegCloseKey(local_370);
        }
        piVar3 = (int *)*piVar3;
        piVar2 = local_35c;
      } while (piVar3 != (int *)0x0);
    }
  }
  FUN_c048e238(local_30);
  return piVar2;
}



/* c04894f0 FUN_c04894f0 */

/* Boundary evidence: original MIPS .pdata c04894f0..c048964b. Semantic name remains unreviewed. */

undefined4 FUN_c04894f0(HKEY param_1,int param_2)

{
  int iVar1;
  size_t sVar2;
  char *_Str;
  int *local_360;
  int local_35c;
  undefined4 local_358 [8];
  char local_338 [800];
  uint local_18;
  
  local_18 = DAT_c048f418;
  local_360 = (int *)0x320;
  memset(local_338,0,800);
  iVar1 = FUN_c0488db0(param_1,L"DNS",local_338,(int *)&local_360);
  if (iVar1 == 0) {
    FUN_c0488db0(param_1,L"DhcpDNS",local_338,(int *)&local_360);
  }
  memset(local_358,0,0x20);
  local_360 = (int *)(param_2 + 0x1c);
  local_358[0] = 4;
  iVar1 = *local_360;
  while (iVar1 != 0) {
    local_360 = (int *)(*local_360 + 8);
    iVar1 = *local_360;
  }
  sVar2 = strlen(local_338);
  if (sVar2 != 0) {
    _Str = local_338;
    while (local_338[0] != '\0') {
      iVar1 = getaddrinfo(_Str,0,local_358,&local_35c);
      if (iVar1 == 0) {
        FUN_c04874a0(&local_360,*(void **)(local_35c + 0x18),*(SIZE_T *)(local_35c + 0x10));
        freeaddrinfo(local_35c);
      }
      sVar2 = strlen(_Str);
      _Str = _Str + sVar2 + 1;
      local_338[0] = *_Str;
    }
  }
  FUN_c048e238(local_18);
  return 0;
}



/* c048964c FUN_c048964c */

/* Boundary evidence: original MIPS .pdata c048964c..c0489a3f. Semantic name remains unreviewed. */

LSTATUS FUN_c048964c(int param_1,int param_2,int param_3,uint param_4)

{
  bool bVar1;
  undefined3 extraout_var;
  int iVar2;
  undefined3 extraout_var_00;
  size_t sVar3;
  HANDLE hHeap;
  wchar_t *_Dest;
  short *psVar4;
  int *piVar5;
  LSTATUS LVar6;
  byte bVar7;
  HKEY local_168;
  DWORD local_164;
  int local_160;
  DWORD local_15c;
  HKEY local_158;
  int *local_154;
  undefined2 local_150 [4];
  undefined2 local_148;
  undefined2 local_142;
  byte local_139;
  wchar_t local_130 [130];
  uint local_2c;
  
  local_2c = DAT_c048f418;
  local_168 = (HKEY)0x0;
  LVar6 = 0;
  local_130[0] = L'\0';
  *(undefined4 *)(param_3 + 0x20) = 0;
  *(undefined4 *)(param_3 + 0x38) = 1;
  if (param_2 == 0) goto LAB_c04899cc;
  bVar1 = FUN_c04884bc(1,param_2,0x20019,&local_168);
  if (CONCAT31(extraout_var,bVar1) == 0) {
    LVar6 = 0x3eb;
  }
  else {
    local_164 = 0x102;
    LVar6 = RegQueryValueExW(local_168,L"Domain",(LPDWORD)0x0,&local_15c,(LPBYTE)local_130,
                             &local_164);
    if (LVar6 != 0) {
      if (LVar6 != 2) goto LAB_c04899b4;
      local_164 = 0;
      local_15c = 1;
    }
    if (local_15c == 1) {
      if ((local_164 == 0) || (sVar3 = wcslen(local_130), sVar3 == 0)) {
        local_164 = 0x102;
        LVar6 = RegQueryValueExW(local_168,L"DhcpDomain",(LPDWORD)0x0,&local_15c,(LPBYTE)local_130,
                                 &local_164);
        if (LVar6 != 0) {
          if (LVar6 != 2) goto LAB_c04899b4;
          local_164 = 0;
          local_130[0] = L'\0';
        }
      }
      iVar2 = FUN_c0488584(local_168,L"RegistrationEnabled",(LPBYTE)&local_160);
      if ((iVar2 != 0) && (local_160 == 0)) {
        *(uint *)(param_3 + 0x38) = *(uint *)(param_3 + 0x38) & 0xfffffffe;
      }
      iVar2 = FUN_c0488584(local_168,L"RegisterAdapterName",(LPBYTE)&local_160);
      if ((iVar2 != 0) && (local_160 != 0)) {
        *(uint *)(param_3 + 0x38) = *(uint *)(param_3 + 0x38) | 2;
      }
      if ((param_4 & 8) == 0) {
        if ((param_1 != 2) && (DAT_c048f634 != 0)) {
          local_158 = (HKEY)0x0;
          bVar1 = FUN_c04884bc(3,param_2,0x20019,&local_158);
          if (CONCAT31(extraout_var_00,bVar1) != 0) {
            FUN_c04894f0(local_158,param_3);
            RegCloseKey(local_158);
          }
          piVar5 = (int *)(param_3 + 0x1c);
          if (*piVar5 == 0) {
            memset(local_150,0,0x1c);
            local_148 = 0xc0fe;
            iVar2 = *piVar5;
            local_150[0] = 0x17;
            local_142 = 0xffff;
            local_154 = piVar5;
            while (iVar2 != 0) {
              local_154 = (int *)(*local_154 + 8);
              iVar2 = *local_154;
            }
            bVar7 = 1;
            do {
              local_139 = bVar7;
              FUN_c04874a0(&local_154,local_150,0x1c);
              bVar7 = bVar7 + 1;
            } while (bVar7 < 4);
          }
          for (iVar2 = *piVar5; iVar2 != 0; iVar2 = *(int *)(iVar2 + 8)) {
            psVar4 = *(short **)(iVar2 + 0xc);
            if (*psVar4 == 0x17) {
              if (((char)psVar4[4] == -2) && ((*(byte *)((int)psVar4 + 9) & 0xc0) == 0x80)) {
                *(undefined4 *)(psVar4 + 0xc) = *(undefined4 *)(param_3 + 0x54);
              }
              else if (((char)psVar4[4] == -2) && ((*(byte *)((int)psVar4 + 9) & 0xc0) == 0xc0)) {
                *(undefined4 *)(psVar4 + 0xc) = *(undefined4 *)(param_3 + 0x60);
              }
            }
          }
        }
        if (param_1 != 0x17) {
          FUN_c04894f0(local_168,param_3);
        }
      }
    }
    else {
      LVar6 = 0xd;
    }
  }
LAB_c04899b4:
  if (local_168 != (HKEY)0x0) {
    RegCloseKey(local_168);
  }
LAB_c04899cc:
  sVar3 = wcslen(local_130);
  hHeap = GetProcessHeap();
  _Dest = HeapAlloc(hHeap,0,(sVar3 + 1) * 2);
  *(wchar_t **)(param_3 + 0x20) = _Dest;
  if (_Dest != (wchar_t *)0x0) {
    wcscpy(_Dest,local_130);
  }
  FUN_c048e238(local_2c);
  return LVar6;
}



/* c0489a40 FUN_c0489a40 */

/* Boundary evidence: original MIPS .pdata c0489a40..c0489d6f. Semantic name remains unreviewed. */

undefined4
FUN_c0489a40(int *param_1,int *param_2,char *param_3,char *param_4,undefined4 param_5,
            undefined4 param_6,uint param_7,undefined4 param_8,undefined4 param_9,void *param_10,
            size_t param_11,wchar_t *param_12,wchar_t *param_13,void *param_14,int param_15)

{
  HANDLE pvVar1;
  LPVOID pvVar2;
  size_t sVar3;
  undefined4 uVar4;
  int iVar5;
  
  pvVar1 = GetProcessHeap();
  pvVar2 = HeapAlloc(pvVar1,0,0x98);
  *param_1 = (int)pvVar2;
  if (pvVar2 != (LPVOID)0x0) {
    memset(pvVar2,0,0x98);
    sVar3 = strlen(param_3);
    pvVar1 = GetProcessHeap();
    pvVar2 = HeapAlloc(pvVar1,0,sVar3 + 1);
    *(LPVOID *)(*param_1 + 0xc) = pvVar2;
    iVar5 = *param_1;
    if (*(int *)(iVar5 + 0xc) != 0) {
      sVar3 = wcslen(param_12);
      pvVar1 = GetProcessHeap();
      pvVar2 = HeapAlloc(pvVar1,0,(sVar3 + 1) * 2);
      *(LPVOID *)(*param_1 + 0x24) = pvVar2;
      iVar5 = *param_1;
      if (*(int *)(iVar5 + 0x24) != 0) {
        sVar3 = wcslen(param_13);
        pvVar1 = GetProcessHeap();
        pvVar2 = HeapAlloc(pvVar1,0,(sVar3 + 1) * 2);
        *(LPVOID *)(*param_1 + 0x28) = pvVar2;
        iVar5 = *param_1;
        if (*(int *)(iVar5 + 0x28) != 0) {
          *(undefined4 *)(iVar5 + 8) = 0;
          *(undefined4 *)*param_1 = 0x98;
          strcpy(*(char **)(*param_1 + 0xc),param_3);
          *(undefined4 *)(*param_1 + 4) = param_5;
          *(undefined4 *)(*param_1 + 0x48) = param_6;
          *(undefined4 *)(*param_1 + 0x10) = 0;
          *(undefined4 *)(*param_1 + 0x14) = 0;
          *(undefined4 *)(*param_1 + 0x18) = 0;
          *(undefined4 *)(*param_1 + 0x1c) = 0;
          *(undefined4 *)(*param_1 + 0x44) = 1;
          memcpy((void *)(*param_1 + 0x4c),param_14,0x38);
          *(undefined4 *)(*param_1 + 0x84) = 0;
          *(undefined4 *)(*param_1 + 0x88) = 0;
          *(undefined4 *)(*param_1 + 0x3c) = param_9;
          *(undefined4 *)(*param_1 + 0x40) = param_8;
          if (8 < param_11) {
            param_11 = 8;
          }
          *(size_t *)(*param_1 + 0x34) = param_11;
          memcpy((void *)(*param_1 + 0x2c),param_10,param_11);
          wcscpy(*(wchar_t **)(*param_1 + 0x24),param_12);
          wcscpy(*(wchar_t **)(*param_1 + 0x28),param_13);
          if (param_4 == (char *)0x0) {
            param_4 = param_3;
          }
          FUN_c048964c(param_15,(int)param_4,*param_1,param_7);
          iVar5 = *param_1;
          if (*(int *)(iVar5 + 0x20) != 0) {
            uVar4 = FUN_c0487594(param_3);
            *(undefined4 *)(*param_1 + 0x90) = uVar4;
            *(int *)*param_2 = *param_1;
            *param_2 = *param_1 + 8;
            return 0;
          }
        }
      }
    }
    pvVar2 = *(LPVOID *)(iVar5 + 0xc);
    if (pvVar2 != (LPVOID)0x0) {
      pvVar1 = GetProcessHeap();
      HeapFree(pvVar1,0,pvVar2);
    }
    pvVar2 = *(LPVOID *)(*param_1 + 0x28);
    if (pvVar2 != (LPVOID)0x0) {
      pvVar1 = GetProcessHeap();
      HeapFree(pvVar1,0,pvVar2);
    }
    pvVar2 = *(LPVOID *)(*param_1 + 0x24);
    if (pvVar2 != (LPVOID)0x0) {
      pvVar1 = GetProcessHeap();
      HeapFree(pvVar1,0,pvVar2);
    }
    pvVar1 = GetProcessHeap();
    HeapFree(pvVar1,0,(LPVOID)*param_1);
  }
  return 8;
}



/* c0489d70 FUN_c0489d70 */

/* Boundary evidence: original MIPS .pdata c0489d70..c0489f03. Semantic name remains unreviewed. */

undefined4
FUN_c0489d70(int param_1,int *param_2,int *param_3,char *param_4,char *param_5,int param_6,
            int param_7,uint param_8,undefined4 param_9,undefined4 param_10,void *param_11,
            size_t param_12,wchar_t *param_13,wchar_t *param_14,void *param_15,int param_16)

{
  int iVar1;
  undefined4 uVar2;
  short *psVar3;
  
  while( true ) {
    if (param_1 == 0) {
      uVar2 = FUN_c0489a40(param_2,param_3,param_4,param_5,param_6,param_7,param_8,param_9,param_10,
                           param_11,param_12,param_13,param_14,param_15,param_16);
      return uVar2;
    }
    iVar1 = strcmp(param_4,*(char **)(param_1 + 0xc));
    if (iVar1 == 0) break;
    param_1 = *(int *)(param_1 + 8);
  }
  if (param_6 != 0) {
    *(int *)(param_1 + 4) = param_6;
  }
  if (param_7 != 0) {
    *(int *)(param_1 + 0x48) = param_7;
    memcpy((void *)(param_1 + 0x4c),param_15,0x38);
    for (iVar1 = *(int *)(param_1 + 0x1c); iVar1 != 0; iVar1 = *(int *)(iVar1 + 8)) {
      psVar3 = *(short **)(iVar1 + 0xc);
      if (*psVar3 == 0x17) {
        if (((char)psVar3[4] == -2) && ((*(byte *)((int)psVar3 + 9) & 0xc0) == 0x80)) {
          uVar2 = *(undefined4 *)((int)param_15 + 8);
        }
        else {
          if (((char)psVar3[4] != -2) || ((*(byte *)((int)psVar3 + 9) & 0xc0) != 0xc0))
          goto LAB_c0489eec;
          uVar2 = *(undefined4 *)((int)param_15 + 0x14);
        }
        *(undefined4 *)(psVar3 + 0xc) = uVar2;
      }
LAB_c0489eec:
    }
  }
  *param_2 = param_1;
  return 0;
}



/* c0489f04 FUN_c0489f04 */

/* Boundary evidence: original MIPS .pdata c0489f04..c048a2fb. Semantic name remains unreviewed. */

int FUN_c0489f04(int param_1,int param_2,int *param_3,int *param_4,int *param_5,int *param_6,
                uint param_7,int param_8)

{
  char *_Str2;
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  short *_Src;
  int *piVar4;
  wchar_t *_Source;
  int *local_2a8;
  int *local_2a4;
  int *local_2a0;
  int *local_29c;
  int *local_298;
  undefined1 auStack_290 [16];
  char acStack_280 [80];
  wchar_t awStack_230 [258];
  uint local_2c;
  
  local_2c = DAT_c048f418;
  local_2a4 = (int *)0x40;
  local_2a0 = param_4;
  local_298 = param_3;
  if (*(int *)(param_2 + 0x48) != 0) goto LAB_c0489f64;
  FUN_c04872a8((undefined4 *)(param_1 + 0x18),acStack_280);
  _Src = (short *)(param_2 + 0x38);
  if (*(int *)(param_1 + 0x38) == 6) {
    if ((*(char *)_Src != ' ') || (*(char *)(param_2 + 0x39) != '\x02')) goto LAB_c0489f64;
    piVar4 = *(int **)(param_2 + 0x3a);
    _Source = L"6to4 Tunneling Pseudo-Interface";
    local_29c = piVar4;
  }
  else {
    iVar1 = FUN_c0486a24(_Src);
    if ((iVar1 == 0) &&
       (((*(ushort *)(param_2 + 0x40) & 0xfffd) != 0 || (*(short *)(param_2 + 0x42) != -0x1a2))))
    goto LAB_c0489f64;
    piVar4 = *(int **)(param_2 + 0x44);
    _Source = L"Automatic Tunneling Pseudo-Interface";
    local_29c = piVar4;
    iVar1 = FUN_c0486a24(_Src);
    if (iVar1 != 0) {
      local_2a4 = (int *)0x60;
    }
  }
  piVar2 = (int *)*param_5;
  if (piVar2 == (int *)0x0) {
LAB_c048a06c:
    _Str2 = (char *)FUN_c048720c(local_2a0,(ulong)piVar4,(int *)&local_2a0);
    if (_Str2 == (char *)0x0) {
LAB_c0489f64:
      FUN_c048e238(local_2c);
      return 0;
    }
    wcscpy(awStack_230,_Source);
    if (*(uint *)(param_1 + 0x38) < 0xb) {
      uVar3 = *(undefined4 *)(&DAT_c048f134 + *(uint *)(param_1 + 0x38) * 4);
    }
    else {
      uVar3 = 1;
    }
    for (; local_2a8 = param_6, param_6 != (int *)0x0; param_6 = (int *)param_6[2]) {
      iVar1 = strcmp((char *)param_6[3],_Str2);
      if (iVar1 == 0) {
        *(int *)(param_1 + 0x74) = param_6[0x18];
        if (param_6[0x17] == param_6[0x18]) {
          *(int *)(param_1 + 0x70) = param_6[0x17];
          if (param_6[0x16] == param_6[0x18]) {
            *(int *)(param_1 + 0x6c) = param_6[0x16];
          }
        }
        break;
      }
    }
    iVar1 = FUN_c0489a40((int *)&local_2a8,local_298,acStack_280,_Str2,0,
                         *(undefined4 *)(param_2 + 0x24),param_7,uVar3,
                         *(undefined4 *)(param_1 + 0xa4),&local_29c,4,_Source,awStack_230,
                         (void *)(param_1 + 0x60),param_8);
    if (iVar1 != 0) goto LAB_c048a2c0;
    local_2a8[0xe] = local_2a8[0xe] | 0x10;
    piVar2 = local_2a8;
    if (*param_5 == 0) {
      *param_5 = (int)local_2a8;
    }
  }
  else {
    do {
      if ((piVar2[0x12] == *(int *)(param_2 + 0x24)) && ((int *)piVar2[0xb] == piVar4)) break;
      piVar2 = (int *)piVar2[2];
    } while (piVar2 != (int *)0x0);
    if (piVar2 == (int *)0x0) goto LAB_c048a06c;
  }
  local_2a0 = piVar2 + 4;
  iVar1 = *local_2a0;
  while (iVar1 != 0) {
    local_2a0 = (int *)(*local_2a0 + 8);
    iVar1 = *local_2a0;
  }
  local_2a8 = piVar2 + 5;
  iVar1 = *local_2a8;
  while (iVar1 != 0) {
    local_2a8 = (int *)(*local_2a8 + 8);
    iVar1 = *local_2a8;
  }
  local_29c = piVar2 + 6;
  iVar1 = *local_29c;
  while (iVar1 != 0) {
    local_29c = (int *)(*local_29c + 8);
    iVar1 = *local_29c;
  }
  iVar1 = FUN_c0486f78(param_1,param_2,&local_2a0,&local_2a8,&local_29c,0,param_7);
  if ((iVar1 == 0) && ((param_7 & 0x10) != 0)) {
    memset(auStack_290,0,0x10);
    piVar4 = local_2a4;
    memcpy(auStack_290,_Src,(uint)local_2a4 >> 3);
    piVar2 = piVar2 + 0x23;
    iVar1 = *piVar2;
    local_2a4 = piVar2;
    while (iVar1 != 0) {
      local_2a4 = (int *)(*local_2a4 + 8);
      iVar1 = *local_2a4;
    }
    iVar1 = FUN_c04876bc(auStack_290,(int)piVar4,piVar2,&local_2a4);
  }
LAB_c048a2c0:
  FUN_c048e238(local_2c);
  return iVar1;
}



/* c048a2fc FUN_c048a2fc */

/* Boundary evidence: original MIPS .pdata c048a2fc..c048a84b. Semantic name remains unreviewed. */

DWORD FUN_c048a2fc(int param_1,int *param_2,int *param_3,int *param_4,uint param_5,int param_6)

{
  STRSAFE_LPCSTR pszSrc;
  DWORD DVar1;
  wchar_t *pwVar2;
  int *piVar3;
  int iVar4;
  undefined4 uVar5;
  ulong *puVar6;
  undefined4 uVar7;
  wchar_t *_Source;
  int iVar8;
  int local_458;
  int *local_454;
  int *local_450;
  int *local_44c;
  int *local_448;
  int iStack_444;
  char acStack_440 [264];
  WCHAR aWStack_338 [132];
  wchar_t local_230 [258];
  uint local_2c;
  
  local_2c = DAT_c048f418;
  iVar8 = *param_3;
  puVar6 = (ulong *)(param_1 + 0xd8);
  FUN_c04872a8((undefined4 *)(param_1 + 0x18),acStack_440);
  iVar4 = *(int *)(param_1 + 0x38);
  _Source = L"Teredo Tunneling Pseudo-Interface";
  uVar7 = 4;
  if (iVar4 == 0) {
    pwVar2 = L"Loopback Pseudo-Interface";
LAB_c048a5b8:
    wcscpy(aWStack_338,pwVar2);
LAB_c048a5c0:
    pszSrc = acStack_440;
  }
  else {
    if (iVar4 == 3) {
      wcscpy(aWStack_338,L"Automatic Tunneling Pseudo-Interface");
      local_458 = 0;
      DVar1 = FUN_c0487010(param_1,FUN_c0489f04,param_2,param_4,&local_458,iVar8,param_5,param_6);
      if ((DVar1 == 0) && (local_458 == 0)) {
        DVar1 = FUN_c0489a40(&local_458,param_2,acStack_440,acStack_440,0,
                             *(undefined4 *)(param_1 + 0x14),param_5,0x83,
                             *(undefined4 *)(param_1 + 0xa4),puVar6,*(size_t *)(param_1 + 0x2c),
                             aWStack_338,aWStack_338,(void *)(param_1 + 0x60),param_6);
      }
      goto LAB_c048a810;
    }
    if (iVar4 == 4) {
      pwVar2 = L"6over4 Pseudo-Interface";
LAB_c048a4b4:
      wcscpy(aWStack_338,pwVar2);
      pszSrc = (STRSAFE_LPCSTR)FUN_c048720c(param_4,*puVar6,&iStack_444);
      if (pszSrc == (char *)0x0) goto LAB_c048a5c0;
    }
    else {
      if (iVar4 == 5) {
        pwVar2 = L"Configured Tunnel Interface";
        goto LAB_c048a4b4;
      }
      if (iVar4 == 6) {
        wcscpy(aWStack_338,L"6to4 Pseudo-Interface");
        local_458 = 0;
        DVar1 = FUN_c0487010(param_1,FUN_c0489f04,param_2,param_4,&local_458,iVar8,param_5,param_6);
        if ((DVar1 == 0) && (local_458 == 0)) {
          DVar1 = FUN_c0489a40(&local_458,param_2,acStack_440,acStack_440,0,
                               *(undefined4 *)(param_1 + 0x14),param_5,0x83,
                               *(undefined4 *)(param_1 + 0xa4),puVar6,*(size_t *)(param_1 + 0x2c),
                               aWStack_338,aWStack_338,(void *)(param_1 + 0x60),param_6);
        }
        goto LAB_c048a810;
      }
      pwVar2 = _Source;
      if (iVar4 == 7) goto LAB_c048a5b8;
      pszSrc = (STRSAFE_LPCSTR)FUN_c04873bc(param_4,(undefined4 *)(param_1 + 0x18),aWStack_338);
      if (pszSrc != (STRSAFE_LPCSTR)0x0) {
        StringCchCopyA(acStack_440,0x104,pszSrc);
      }
    }
  }
  if ((param_5 & 0x20) == 0) {
    if (*(int *)(param_1 + 0x38) != 7) {
      if (*(int *)(param_1 + 0x38) != 0) {
        MultiByteToWideChar(0,0,acStack_440,-1,local_230,0x101);
        goto LAB_c048a63c;
      }
      _Source = L"Loopback Pseudo-Interface";
    }
    wcscpy(local_230,_Source);
  }
  else {
    local_230[0] = L'\0';
  }
LAB_c048a63c:
  if (*(uint *)(param_1 + 0x38) < 0xb) {
    uVar5 = *(undefined4 *)(&DAT_c048f134 + *(uint *)(param_1 + 0x38) * 4);
  }
  else {
    uVar5 = 1;
  }
  DVar1 = FUN_c0489d70(iVar8,&local_458,param_2,acStack_440,pszSrc,0,*(int *)(param_1 + 0x14),
                       param_5,uVar5,*(undefined4 *)(param_1 + 0xa4),puVar6,
                       *(size_t *)(param_1 + 0x2c),aWStack_338,local_230,(void *)(param_1 + 0x60),
                       param_6);
  if (DVar1 == 0) {
    if (*(int *)(param_1 + 0x54) != 0) {
      *(uint *)(local_458 + 0x38) = *(uint *)(local_458 + 0x38) | 0x20;
    }
    if (*(uint *)(param_1 + 0x50) < 3) {
      uVar7 = *(undefined4 *)(&DAT_c048f170 + *(uint *)(param_1 + 0x50) * 4);
    }
    *(undefined4 *)(local_458 + 0x44) = uVar7;
    for (local_450 = (int *)(local_458 + 0x10); *local_450 != 0; local_450 = (int *)(*local_450 + 8)
        ) {
    }
    for (local_44c = (int *)(local_458 + 0x14); *local_44c != 0; local_44c = (int *)(*local_44c + 8)
        ) {
    }
    for (local_448 = (int *)(local_458 + 0x18); *local_448 != 0; local_448 = (int *)(*local_448 + 8)
        ) {
    }
    DVar1 = FUN_c0487010(param_1,FUN_c0486f78,&local_450,&local_44c,&local_448,0,param_5,param_6);
    if ((DVar1 == 0) && ((param_5 & 0x10) != 0)) {
      piVar3 = (int *)(local_458 + 0x8c);
      iVar4 = *piVar3;
      local_454 = piVar3;
      while (iVar4 != 0) {
        local_454 = (int *)(*local_454 + 8);
        iVar4 = *local_454;
      }
      DVar1 = FUN_c0487830(*(int *)(param_1 + 0x14),FUN_c04876bc,piVar3,&local_454);
    }
  }
LAB_c048a810:
  FUN_c048e238(local_2c);
  return DVar1;
}



/* c048a84c FUN_c048a84c */

/* Boundary evidence: original MIPS .pdata c048a84c..c048aaab. Semantic name remains unreviewed. */

DWORD FUN_c048a84c(int param_1,int *param_2,int *param_3,uint param_4,int param_5,uint *param_6)

{
  DWORD DVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  int iVar4;
  int local_6e0;
  int local_6dc;
  int local_6d8;
  int local_6d4;
  undefined4 local_6d0;
  undefined4 local_6cc;
  undefined4 local_6c8;
  undefined4 local_6c4;
  undefined4 local_6c0 [12];
  undefined4 auStack_690 [130];
  undefined4 local_488;
  uint local_470;
  WCHAR aWStack_330 [132];
  WCHAR local_228 [258];
  uint local_24;
  
  local_24 = DAT_c048f418;
  iVar4 = *param_3;
  MultiByteToWideChar(0,0,(LPCSTR)(param_1 + 0x10c),-1,aWStack_330,0x80);
  DVar1 = FUN_c048481c((undefined2 *)auStack_690,*(uint *)(param_1 + 0x19c),0);
  if (DVar1 == 0) {
    local_6d0 = *(undefined4 *)(param_1 + 0x19c);
    puVar2 = local_6c0;
    do {
      *puVar2 = 1;
      puVar2 = puVar2 + 1;
    } while (puVar2 != auStack_690);
    local_6cc = local_6d0;
    local_6c8 = local_6d0;
    local_6c4 = local_6d0;
    if ((param_4 & 0x20) == 0) {
      MultiByteToWideChar(0,0,(LPCSTR)(param_1 + 8),-1,local_228,0x101);
    }
    else {
      local_228[0] = L'\0';
    }
    DVar1 = FUN_c0489d70(iVar4,&local_6d4,param_2,(char *)(param_1 + 8),(char *)(param_1 + 8),
                         *(int *)(param_1 + 0x19c),0,param_4,*(undefined4 *)(param_1 + 0x1a0),
                         local_488,(void *)(param_1 + 0x194),*(size_t *)(param_1 + 400),aWStack_330,
                         local_228,&local_6d0,param_5);
    if (DVar1 == 0) {
      if (local_470 < 6) {
        uVar3 = *(undefined4 *)(&DAT_c048f17c + local_470 * 4);
      }
      else {
        uVar3 = 4;
      }
      *(undefined4 *)(local_6d4 + 0x44) = uVar3;
      if (*(int *)(param_1 + 0x1a4) != 0) {
        *(uint *)(local_6d4 + 0x38) = *(uint *)(local_6d4 + 0x38) | 4;
      }
      local_6dc = local_6d4 + 0x10;
      local_6d8 = local_6d4 + 0x18;
      DVar1 = FUN_c04880b4(param_1,FUN_c0487da4,&local_6dc,local_6d8,&local_6d8,local_6d4 + 0x38,
                           param_4,param_6);
      if ((DVar1 == 0) && ((param_4 & 0x10) != 0)) {
        local_6e0 = local_6d4 + 0x8c;
        DVar1 = FUN_c04882f0(param_1,FUN_c0488194,local_6e0,&local_6e0);
      }
    }
  }
  FUN_c048e238(local_24);
  return DVar1;
}



/* c048aaac FUN_c048aaac */

/* Boundary evidence: original MIPS .pdata c048aaac..c048acdb. Semantic name remains unreviewed. */

DWORD FUN_c048aaac(int param_1,uint param_2,undefined4 *param_3)

{
  int *piVar1;
  DWORD DVar2;
  HANDLE pvVar3;
  uint *lpMem;
  LPVOID local_78;
  DWORD local_74;
  LPVOID *local_70;
  DWORD local_6c;
  undefined1 auStack_68 [64];
  
  lpMem = (uint *)0x0;
  piVar1 = FUN_c048917c();
  local_70 = &local_78;
  local_78 = (LPVOID)0x0;
  *param_3 = 0;
  if ((param_1 != 2) && ((param_2 & 8) == 0)) {
    local_74 = 0x40;
    local_6c = 0;
    DVar2 = FUN_c048d228(0x29,0x120078,(LPVOID)0x0,&local_6c,auStack_68,&local_74);
    DAT_c048f634 = (uint)(DVar2 == 0);
  }
  DVar2 = 0;
  if ((param_1 == 0) || (param_1 == 2)) {
    local_74 = 0;
    DVar2 = GetIpAddrTable((uint *)0x0,&local_74,1);
    if (DVar2 == 0x7a) {
      pvVar3 = GetProcessHeap();
      lpMem = HeapAlloc(pvVar3,0,local_74);
      if (lpMem == (uint *)0x0) {
        DVar2 = 8;
        goto LAB_c048ac68;
      }
      DVar2 = GetIpAddrTable(lpMem,&local_74,1);
    }
    if ((DVar2 != 0) ||
       (DVar2 = FUN_c04883f4(FUN_c048a84c,&local_70,&local_78,piVar1,param_2,param_1,lpMem),
       DVar2 != 0)) goto LAB_c048ac68;
  }
  if (((param_1 != 0) && (param_1 != 0x17)) ||
     (DVar2 = FUN_c0487a40(FUN_c048a2fc,&local_70,&local_78,piVar1,param_2,param_1), DVar2 == 0)) {
    *param_3 = local_78;
    local_78 = (LPVOID)0x0;
  }
LAB_c048ac68:
  if (lpMem != (uint *)0x0) {
    pvVar3 = GetProcessHeap();
    HeapFree(pvVar3,0,lpMem);
  }
  if (piVar1 != (int *)0x0) {
    FUN_c04886d4(piVar1);
  }
  if (local_78 != (LPVOID)0x0) {
    FUN_c048876c(local_78);
  }
  return DVar2;
}



/* c048acdc FUN_c048acdc */

/* Boundary evidence: original MIPS .pdata c048acdc..c048aec7. Semantic name remains unreviewed. */

int * FUN_c048acdc(int param_1)

{
  bool bVar1;
  int *piVar2;
  undefined3 extraout_var;
  int iVar3;
  int *_Dst;
  int *piVar4;
  HKEY local_50;
  int local_4c [3];
  CHAR aCStack_40 [16];
  CHAR aCStack_30 [16];
  uint local_20;
  
  local_20 = DAT_c048f418;
  _Dst = (int *)0x0;
  piVar2 = FUN_c048917c();
  piVar4 = piVar2;
  if (piVar2 != (int *)0x0) {
    do {
      if (((piVar4[0x67] == param_1) && ((char)piVar4[2] != '\0')) &&
         (bVar1 = FUN_c04884bc(1,piVar4 + 2,0x20019,&local_50), CONCAT31(extraout_var,bVar1) != 0))
      {
        _Dst = LocalAlloc(0x40,0x34);
        if (_Dst == (int *)0x0) {
          FUN_c04886d4(piVar2);
          RegCloseKey(local_50);
          FUN_c048e238(local_20);
          return (int *)0x0;
        }
        memset(_Dst,0,0x34);
        iVar3 = FUN_c0488584(local_50,L"AutoCfg",(LPBYTE)_Dst);
        if (iVar3 == 0) {
          *_Dst = 1;
        }
        if (*_Dst != 0) {
          local_4c[1] = 0x10;
          local_4c[0] = 0x10;
          iVar3 = FUN_c0488db0(local_50,L"AutoIP",aCStack_30,local_4c + 1);
          if (((iVar3 != 0) &&
              (iVar3 = FUN_c0488db0(local_50,L"DhcpIPAddress",aCStack_40,local_4c), iVar3 != 0)) &&
             (iVar3 = strcmp(aCStack_30,aCStack_40), iVar3 == 0)) {
            _Dst[1] = 1;
          }
        }
        iVar3 = FUN_c0488eec(local_50,L"DNS",_Dst + 3);
        if (iVar3 == 0) {
          FUN_c0488eec(local_50,L"DhcpDNS",_Dst + 3);
        }
        RegCloseKey(local_50);
        break;
      }
      piVar4 = (int *)*piVar4;
    } while (piVar4 != (int *)0x0);
    FUN_c04886d4(piVar2);
  }
  FUN_c048e238(local_20);
  return _Dst;
}



/* c048aec8 FUN_c048aec8 */

/* Boundary evidence: original MIPS .pdata c048aec8..c048b153. Semantic name remains unreviewed. */

undefined4 FUN_c048aec8(undefined4 *param_1,uint *param_2)

{
  undefined4 uVar1;
  int *piVar2;
  uint uVar3;
  int *_Src;
  undefined4 *_Dst;
  undefined4 *puVar4;
  uint _Size;
  undefined4 *puVar5;
  int iVar6;
  
  if (param_2 == (uint *)0x0) {
    uVar1 = 0x57;
  }
  else {
    piVar2 = FUN_c048917c();
    if (piVar2 == (int *)0x0) {
      uVar1 = 0xe8;
    }
    else {
      if (param_1 != (undefined4 *)0x0) {
        _Size = *param_2;
        uVar3 = FUN_c04889c4(piVar2);
        if (uVar3 <= _Size) {
          memset(param_1,0,_Size);
          puVar4 = param_1;
          for (_Src = piVar2; _Dst = param_1, _Src != (int *)0x0; _Src = (int *)*_Src) {
            memcpy(_Dst,_Src,0x280);
            puVar5 = _Dst + 0x6b;
            _Dst[0x6a] = puVar5;
            puVar4 = (undefined4 *)_Src[0x6b];
            *puVar5 = 0;
            iVar6 = 0x280;
            for (; puVar4 != (void *)0x0; puVar4 = (undefined4 *)*puVar4) {
              *puVar5 = (void *)(iVar6 + (int)_Dst);
              memcpy((void *)(iVar6 + (int)_Dst),puVar4,0x28);
              puVar5 = (undefined4 *)*puVar5;
              iVar6 = iVar6 + 0x28;
            }
            puVar4 = (undefined4 *)_Src[0x75];
            puVar5 = _Dst + 0x75;
            *puVar5 = 0;
            for (; puVar4 != (void *)0x0; puVar4 = (undefined4 *)*puVar4) {
              *puVar5 = (void *)(iVar6 + (int)_Dst);
              memcpy((void *)(iVar6 + (int)_Dst),puVar4,0x28);
              puVar5 = (undefined4 *)*puVar5;
              iVar6 = iVar6 + 0x28;
            }
            puVar4 = (undefined4 *)_Src[0x94];
            puVar5 = _Dst + 0x94;
            *puVar5 = 0;
            for (; puVar4 != (void *)0x0; puVar4 = (undefined4 *)*puVar4) {
              *puVar5 = (void *)(iVar6 + (int)_Dst);
              memcpy((void *)(iVar6 + (int)_Dst),puVar4,0x28);
              puVar5 = (undefined4 *)*puVar5;
              iVar6 = iVar6 + 0x28;
            }
            *_Dst = (undefined4 *)(iVar6 + (int)_Dst);
            param_1 = (undefined4 *)(iVar6 + (int)_Dst);
            puVar4 = _Dst;
          }
          *puVar4 = 0;
          FUN_c04886d4(piVar2);
          return 0;
        }
      }
      uVar3 = FUN_c04889c4(piVar2);
      *param_2 = uVar3;
      FUN_c04886d4(piVar2);
      uVar1 = 0x6f;
    }
  }
  return uVar1;
}



/* c048b154 FUN_c048b154 */

/* Boundary evidence: original MIPS .pdata c048b154..c048b17b. Semantic name remains unreviewed. */

bool FUN_c048b154(undefined4 *param_1)

{
  return *(int *)*param_1 == -0x3ffffffb;
}



/* c048b17c FUN_c048b17c */

/* Boundary evidence: original MIPS .pdata c048b17c..c048b6a7. Semantic name remains unreviewed. */

DWORD FUN_c048b17c(int param_1,uint param_2,void *param_3,uint *param_4)

{
  LPVOID pvVar1;
  uint uVar2;
  size_t sVar3;
  DWORD DVar4;
  uint _Size;
  wchar_t *pwVar5;
  void *pvVar6;
  LPVOID _Src;
  void *_Dst;
  void *pvVar7;
  int *piVar8;
  LPVOID local_34 [2];
  LPVOID local_2c;
  
  if (param_4 == (uint *)0x0) {
    DVar4 = 0x57;
  }
  else {
    DVar4 = FUN_c048aaac(param_1,param_2,local_34);
    pvVar1 = local_34[0];
    if (DVar4 == 0) {
      if (local_34[0] == (LPVOID)0x0) {
        DVar4 = 0xe8;
      }
      else {
        local_2c = local_34[0];
        if (param_3 != (void *)0x0) {
          _Size = *param_4;
          uVar2 = FUN_c0488a40((int)local_34[0]);
          if (uVar2 <= _Size) {
            memset(param_3,0,_Size);
            _Src = pvVar1;
            pvVar7 = param_3;
            while (_Dst = param_3, _Src != (void *)0x0) {
              memcpy(_Dst,_Src,0x98);
              pwVar5 = (wchar_t *)((int)_Dst + 0x98);
              *(wchar_t **)((int)_Dst + 0x28) = pwVar5;
              wcscpy(pwVar5,*(wchar_t **)((int)_Src + 0x28));
              sVar3 = wcslen(*(wchar_t **)((int)_Dst + 0x28));
              pwVar5 = pwVar5 + sVar3 + 1;
              *(wchar_t **)((int)_Dst + 0x24) = pwVar5;
              wcscpy(pwVar5,*(wchar_t **)((int)_Src + 0x24));
              sVar3 = wcslen(*(wchar_t **)((int)_Dst + 0x24));
              pwVar5 = pwVar5 + sVar3 + 1;
              *(wchar_t **)((int)_Dst + 0x20) = pwVar5;
              wcscpy(pwVar5,*(wchar_t **)((int)_Src + 0x20));
              sVar3 = wcslen(*(wchar_t **)((int)_Dst + 0x20));
              pwVar5 = pwVar5 + sVar3 + 1;
              *(wchar_t **)((int)_Dst + 0xc) = pwVar5;
              strcpy((char *)pwVar5,*(char **)((int)_Src + 0xc));
              sVar3 = strlen(*(char **)((int)_Dst + 0xc));
              param_3 = (void *)((int)pwVar5 + sVar3 + 4 & 0xfffffffc);
              if ((param_2 & 1) == 0) {
                piVar8 = (int *)((int)_Dst + 0x10);
                for (pvVar7 = *(void **)((int)_Src + 0x10); pvVar7 != (void *)0x0;
                    pvVar7 = *(void **)((int)pvVar7 + 8)) {
                  *piVar8 = (int)param_3;
                  memcpy(param_3,pvVar7,0x30);
                  pvVar6 = (void *)((int)param_3 + 0x30);
                  *(void **)(*piVar8 + 0xc) = pvVar6;
                  memcpy(pvVar6,*(void **)((int)pvVar7 + 0xc),*(size_t *)((int)pvVar7 + 0x10));
                  param_3 = (void *)((int)pvVar6 + *(int *)((int)pvVar7 + 0x10) + 3 & 0xfffffffc);
                  piVar8 = (int *)(*piVar8 + 8);
                }
              }
              if ((param_2 & 2) == 0) {
                piVar8 = (int *)((int)_Dst + 0x14);
                for (pvVar7 = *(void **)((int)_Src + 0x14); pvVar7 != (void *)0x0;
                    pvVar7 = *(void **)((int)pvVar7 + 8)) {
                  *piVar8 = (int)param_3;
                  memcpy(param_3,pvVar7,0x18);
                  pvVar6 = (void *)((int)param_3 + 0x18);
                  *(void **)(*piVar8 + 0xc) = pvVar6;
                  memcpy(pvVar6,*(void **)((int)pvVar7 + 0xc),*(size_t *)((int)pvVar7 + 0x10));
                  param_3 = (void *)((int)pvVar6 + *(int *)((int)pvVar7 + 0x10) + 3 & 0xfffffffc);
                  piVar8 = (int *)(*piVar8 + 8);
                }
              }
              if ((param_2 & 4) == 0) {
                piVar8 = (int *)((int)_Dst + 0x18);
                for (pvVar7 = *(void **)((int)_Src + 0x18); pvVar7 != (void *)0x0;
                    pvVar7 = *(void **)((int)pvVar7 + 8)) {
                  *piVar8 = (int)param_3;
                  memcpy(param_3,pvVar7,0x18);
                  pvVar6 = (void *)((int)param_3 + 0x18);
                  *(void **)(*piVar8 + 0xc) = pvVar6;
                  memcpy(pvVar6,*(void **)((int)pvVar7 + 0xc),*(size_t *)((int)pvVar7 + 0x10));
                  param_3 = (void *)((int)pvVar6 + *(int *)((int)pvVar7 + 0x10) + 3 & 0xfffffffc);
                  piVar8 = (int *)(*piVar8 + 8);
                }
              }
              if ((param_2 & 8) == 0) {
                piVar8 = (int *)((int)_Dst + 0x1c);
                for (pvVar7 = *(void **)((int)_Src + 0x1c); pvVar7 != (void *)0x0;
                    pvVar7 = *(void **)((int)pvVar7 + 8)) {
                  *piVar8 = (int)param_3;
                  memcpy(param_3,pvVar7,0x18);
                  pvVar6 = (void *)((int)param_3 + 0x18);
                  *(void **)(*piVar8 + 0xc) = pvVar6;
                  memcpy(pvVar6,*(void **)((int)pvVar7 + 0xc),*(size_t *)((int)pvVar7 + 0x10));
                  param_3 = (void *)((int)pvVar6 + *(int *)((int)pvVar7 + 0x10) + 3 & 0xfffffffc);
                  piVar8 = (int *)(*piVar8 + 8);
                }
              }
              if ((param_2 & 0x10) != 0) {
                piVar8 = (int *)((int)_Dst + 0x8c);
                for (pvVar7 = *(void **)((int)_Src + 0x8c); pvVar7 != (void *)0x0;
                    pvVar7 = *(void **)((int)pvVar7 + 8)) {
                  *piVar8 = (int)param_3;
                  memcpy(param_3,pvVar7,0x18);
                  pvVar6 = (void *)((int)param_3 + 0x18);
                  *(void **)(*piVar8 + 0xc) = pvVar6;
                  memcpy(pvVar6,*(void **)((int)pvVar7 + 0xc),*(size_t *)((int)pvVar7 + 0x10));
                  param_3 = (void *)((int)pvVar6 + *(int *)((int)pvVar7 + 0x10) + 3 & 0xfffffffc);
                  piVar8 = (int *)(*piVar8 + 8);
                }
              }
              *(void **)((int)_Dst + 8) = param_3;
              _Src = *(LPVOID *)((int)_Src + 8);
              pvVar7 = _Dst;
              local_34[0] = _Src;
            }
            *(undefined4 *)((int)pvVar7 + 8) = 0;
            FUN_c048876c(pvVar1);
            return 0;
          }
        }
        uVar2 = FUN_c0488a40((int)pvVar1);
        *param_4 = uVar2;
        FUN_c048876c(pvVar1);
        DVar4 = 0x6f;
      }
    }
    else if (local_34[0] != (LPVOID)0x0) {
      FUN_c048876c(local_34[0]);
    }
  }
  return DVar4;
}



/* c048b6a8 FUN_c048b6a8 */

/* Boundary evidence: original MIPS .pdata c048b6a8..c048b6cf. Semantic name remains unreviewed. */

bool FUN_c048b6a8(undefined4 *param_1)

{
  return *(int *)*param_1 == -0x3ffffffb;
}



/* c048b6d0 FUN_c048b6d0 */

/* Boundary evidence: original MIPS .pdata c048b6d0..c048b89f. Semantic name remains unreviewed. */

undefined4 FUN_c048b6d0(int param_1,void *param_2,uint *param_3)

{
  undefined4 uVar1;
  int *_Src;
  int *piVar2;
  int iVar3;
  undefined4 *_Src_00;
  undefined4 *puVar4;
  
  if (param_3 == (uint *)0x0) {
    uVar1 = 0x57;
  }
  else {
    _Src = FUN_c048acdc(param_1);
    if (_Src == (int *)0x0) {
      uVar1 = 0xe8;
    }
    else {
      if (param_2 != (void *)0x0) {
        iVar3 = 0;
        for (piVar2 = (int *)_Src[3]; piVar2 != (int *)0x0; piVar2 = (int *)*piVar2) {
          iVar3 = iVar3 + 1;
        }
        if (iVar3 * 0x28 + 0x34U <= *param_3) {
          memset(param_2,0,*param_3);
          iVar3 = 0x34;
          memcpy(param_2,_Src,0x34);
          _Src_00 = (undefined4 *)_Src[3];
          puVar4 = (undefined4 *)((int)param_2 + 0xc);
          *puVar4 = 0;
          for (; _Src_00 != (void *)0x0; _Src_00 = (undefined4 *)*_Src_00) {
            *puVar4 = (void *)(iVar3 + (int)param_2);
            memcpy((void *)(iVar3 + (int)param_2),_Src_00,0x28);
            puVar4 = (undefined4 *)*puVar4;
            iVar3 = iVar3 + 0x28;
          }
          FUN_c0488978(_Src);
          return 0;
        }
      }
      iVar3 = 0;
      for (piVar2 = (int *)_Src[3]; piVar2 != (int *)0x0; piVar2 = (int *)*piVar2) {
        iVar3 = iVar3 + 1;
      }
      *param_3 = iVar3 * 0x28 + 0x34;
      FUN_c0488978(_Src);
      uVar1 = 0x6f;
    }
  }
  return uVar1;
}



/* c048b8a0 FUN_c048b8a0 */

/* Boundary evidence: original MIPS .pdata c048b8a0..c048b8ab. Semantic name remains unreviewed. */

undefined4 FUN_c048b8a0(void)

{
  return 1;
}



/* c048b8ac FUN_c048b8ac */

/* Boundary evidence: original MIPS .pdata c048b8ac..c048b9c3. Semantic name remains unreviewed. */

undefined4 FUN_c048b8ac(int *param_1)

{
  bool bVar1;
  int *piVar2;
  undefined3 extraout_var;
  int iVar3;
  int *piVar4;
  int iVar5;
  HKEY local_30 [2];
  
  iVar5 = 3;
  piVar2 = FUN_c048917c();
  piVar4 = piVar2;
  if (piVar2 != (int *)0x0) {
    do {
      if (((char)piVar4[2] != '\0') &&
         (bVar1 = FUN_c04884bc(1,piVar4 + 2,0x20019,local_30), CONCAT31(extraout_var,bVar1) != 0)) {
        iVar3 = FUN_c0488eec(local_30[0],L"DNS",param_1);
        if ((iVar3 != 0) || (iVar3 = FUN_c0488eec(local_30[0],L"DhcpDNS",param_1), iVar3 != 0)) {
          iVar5 = 0;
        }
        RegCloseKey(local_30[0]);
      }
      piVar4 = (int *)*piVar4;
    } while (piVar4 != (int *)0x0);
    FUN_c04886d4(piVar2);
    if (iVar5 == 0) {
      return 1;
    }
  }
  return 0;
}



/* c048b9c4 FUN_c048b9c4 */

/* Boundary evidence: original MIPS .pdata c048b9c4..c048ba7b. Semantic name remains unreviewed. */

char * FUN_c048b9c4(void)

{
  char *name;
  LPBYTE pBVar1;
  int local_18 [2];
  
  name = LocalAlloc(0x40,0x248);
  if (name != (char *)0x0) {
    name[0x134] = '\b';
    name[0x135] = '\0';
    name[0x136] = '\0';
    name[0x137] = '\0';
    pBVar1 = (LPBYTE)(name + 0x23c);
    name[0x138] = '\0';
    pBVar1[0] = '\0';
    pBVar1[1] = '\0';
    pBVar1[2] = '\0';
    pBVar1[3] = '\0';
    name[0x240] = '\0';
    name[0x241] = '\0';
    name[0x242] = '\0';
    name[0x243] = '\0';
    name[0x244] = '\0';
    name[0x245] = '\0';
    name[0x246] = '\0';
    name[0x247] = '\0';
    gethostname(name,0x84);
    local_18[0] = 0x84;
    FUN_c0488db0(DAT_c048f128,L"DNSDomain",name + 0x84,local_18);
    FUN_c048b8ac((int *)(name + 0x10c));
    FUN_c0488584(DAT_c048f128,L"IPEnableRouter",pBVar1);
  }
  return name;
}



/* c048ba7c FUN_c048ba7c */

/* Boundary evidence: original MIPS .pdata c048ba7c..c048bc4b. Semantic name remains unreviewed. */

undefined4 FUN_c048ba7c(void *param_1,uint *param_2)

{
  undefined4 uVar1;
  char *_Src;
  int *piVar2;
  int iVar3;
  undefined4 *_Src_00;
  undefined4 *puVar4;
  
  if (param_2 == (uint *)0x0) {
    uVar1 = 0x57;
  }
  else {
    _Src = FUN_c048b9c4();
    if (_Src == (char *)0x0) {
      uVar1 = 0xe;
    }
    else {
      if (param_1 != (void *)0x0) {
        iVar3 = 0;
        for (piVar2 = *(int **)(_Src + 0x10c); piVar2 != (int *)0x0; piVar2 = (int *)*piVar2) {
          iVar3 = iVar3 + 1;
        }
        if (iVar3 * 0x28 + 0x248U <= *param_2) {
          memset(param_1,0,*param_2);
          iVar3 = 0x248;
          memcpy(param_1,_Src,0x248);
          _Src_00 = *(undefined4 **)(_Src + 0x10c);
          puVar4 = (undefined4 *)((int)param_1 + 0x10c);
          *puVar4 = 0;
          for (; _Src_00 != (void *)0x0; _Src_00 = (undefined4 *)*_Src_00) {
            *puVar4 = (void *)(iVar3 + (int)param_1);
            memcpy((void *)(iVar3 + (int)param_1),_Src_00,0x28);
            puVar4 = (undefined4 *)*puVar4;
            iVar3 = iVar3 + 0x28;
          }
          FUN_c0488688(_Src);
          return 0;
        }
      }
      iVar3 = 0;
      for (piVar2 = *(int **)(_Src + 0x10c); piVar2 != (int *)0x0; piVar2 = (int *)*piVar2) {
        iVar3 = iVar3 + 1;
      }
      *param_2 = iVar3 * 0x28 + 0x248;
      FUN_c0488688(_Src);
      uVar1 = 0x6f;
    }
  }
  return uVar1;
}



/* c048bc4c FUN_c048bc4c */

/* Boundary evidence: original MIPS .pdata c048bc4c..c048bc57. Semantic name remains unreviewed. */

undefined4 FUN_c048bc4c(void)

{
  return 1;
}



/* c048bc58 Icmp6CreateFile */

BOOL Icmp6CreateFile(HANDLE IcmpHandle)

{
                    /* 0xbc58  42  Icmp6CreateFile
                       0xbc58  45  IcmpCloseHandle
                       0xbc58  46  IcmpCreateFile */
  return 1;
}



/* c048bc60 IcmpParseReplies */

/* Boundary evidence: original MIPS .pdata c048bc60..c048bd1f. Semantic name remains unreviewed. */

DWORD IcmpParseReplies(LPVOID ReplyBuffer,DWORD ReplySize)

{
  uint uVar1;
  uint uVar2;
  int *piVar3;
  
                    /* 0xbc60  47  IcmpParseReplies */
  if ((ReplyBuffer == (LPVOID)0x0) || (ReplySize == 0)) {
    uVar1 = 0;
  }
  else {
    if (*(int *)((int)ReplyBuffer + 4) == 0x2b18) {
      *(undefined4 *)((int)ReplyBuffer + 4) = 0x2afb;
    }
    uVar1 = (uint)*(ushort *)((int)ReplyBuffer + 0xe);
    *(undefined2 *)((int)ReplyBuffer + 0xe) = 0;
    if (uVar1 == 0) {
      SetLastError(*(DWORD *)((int)ReplyBuffer + 4));
    }
    else if (uVar1 != 0) {
      uVar2 = 0;
      piVar3 = (int *)((int)ReplyBuffer + 0x10);
      do {
        uVar2 = uVar2 + 1 & 0xffff;
        *piVar3 = (int)piVar3 + *piVar3 + -0x10;
        piVar3[2] = (int)piVar3 + piVar3[2] + -0x10;
        piVar3 = piVar3 + 7;
      } while (uVar2 < uVar1);
    }
  }
  return uVar1;
}



/* c048bd20 FUN_c048bd20 */

/* Boundary evidence: original MIPS .pdata c048bd20..c048bdc7. Semantic name remains unreviewed. */

ushort FUN_c048bd20(int param_1,int param_2)

{
  ushort uVar1;
  int *piVar2;
  ushort uVar3;
  
  if ((param_1 == 0) || (param_2 == 0)) {
    uVar3 = 0;
  }
  else {
    uVar3 = *(ushort *)(param_1 + 0xe);
    *(undefined2 *)(param_1 + 0xe) = 0;
    if (uVar3 == 0) {
      SetLastError(*(DWORD *)(param_1 + 4));
    }
    else if (uVar3 != 0) {
      uVar1 = 0;
      piVar2 = (int *)(param_1 + 0x10);
      do {
        uVar1 = uVar1 + 1;
        *piVar2 = (int)piVar2 + *piVar2 + -0x10;
        piVar2[2] = (int)piVar2 + piVar2[2] + -0x10;
        piVar2 = piVar2 + 7;
      } while (uVar1 < uVar3);
    }
  }
  return uVar3;
}



/* c048bdc8 IcmpSendEcho */

/* Boundary evidence: original MIPS .pdata c048bdc8..c048bfc3. Semantic name remains unreviewed. */

DWORD IcmpSendEcho(HANDLE IcmpHandle,IPAddr DestinationAddress,LPVOID RequestData,WORD RequestSize,
                  PIP_OPTION_INFORMATION RequestOptions,LPVOID ReplyBuffer,DWORD ReplySize,
                  DWORD Timeout)

{
  IPAddr *hMem;
  DWORD dwErrCode;
  undefined2 in_register_0000001e;
  size_t _Size;
  ushort uVar1;
  DWORD DVar2;
  DWORD local_30;
  DWORD local_2c;
  
                    /* 0xbdc8  48  IcmpSendEcho */
  _Size = CONCAT22(in_register_0000001e,RequestSize);
  DVar2 = 0;
  if (ReplySize < 0x1c) {
    SetLastError(0x7a);
    return 0;
  }
  local_30 = _Size + 0x14;
  if (RequestOptions != (PIP_OPTION_INFORMATION)0x0) {
    local_30 = RequestOptions->OptionsSize + local_30;
  }
  if (local_30 < ReplySize) {
    local_30 = ReplySize;
  }
  hMem = LocalAlloc(0,local_30);
  if (hMem == (IPAddr *)0x0) {
    SetLastError(8);
    return 0;
  }
  *hMem = DestinationAddress;
  hMem[1] = Timeout;
  *(WORD *)((int)hMem + 10) = RequestSize;
  *(undefined2 *)(hMem + 4) = 0x14;
  if (RequestOptions == (PIP_OPTION_INFORMATION)0x0) {
    *(undefined1 *)(hMem + 3) = 0;
    *(undefined1 *)((int)hMem + 0x12) = 0;
  }
  else {
    *(undefined1 *)(hMem + 3) = 1;
    *(UCHAR *)((int)hMem + 0xd) = RequestOptions->Ttl;
    *(UCHAR *)((int)hMem + 0xe) = RequestOptions->Tos;
    *(UCHAR *)((int)hMem + 0xf) = RequestOptions->Flags;
    *(UCHAR *)((int)hMem + 0x12) = RequestOptions->OptionsSize;
    if (RequestOptions->OptionsSize != 0) {
      memcpy(hMem + 5,RequestOptions->OptionsData,(uint)RequestOptions->OptionsSize);
    }
  }
  uVar1 = (short)hMem[4] + (ushort)*(byte *)((int)hMem + 0x12);
  *(ushort *)(hMem + 2) = uVar1;
  if ((_Size != 0) && (RequestData != (LPVOID)0x0)) {
    memcpy((void *)((uint)uVar1 + (int)hMem),RequestData,_Size);
  }
  if (DAT_c048f414 != 0) {
    local_2c = ReplySize;
    dwErrCode = FUN_c048d228(6,2,hMem,&local_30,ReplyBuffer,&local_2c);
    if (dwErrCode != 0) {
      SetLastError(dwErrCode);
      goto LAB_c048bf8c;
    }
  }
  DVar2 = IcmpParseReplies(ReplyBuffer,ReplySize);
LAB_c048bf8c:
  LocalFree(hMem);
  return DVar2;
}



/* c048bfc4 IcmpSendEcho2 */

/* Boundary evidence: original MIPS .pdata c048bfc4..c048c1cb. Semantic name remains unreviewed. */

DWORD IcmpSendEcho2(HANDLE IcmpHandle,HANDLE Event,FARPROC ApcRoutine,PVOID ApcContext,
                   IPAddr DestinationAddress,LPVOID RequestData,WORD RequestSize,
                   PIP_OPTION_INFORMATION RequestOptions,LPVOID ReplyBuffer,DWORD ReplySize,
                   DWORD Timeout)

{
  ushort uVar1;
  IPAddr *hMem;
  DWORD dwErrCode;
  undefined2 extraout_var;
  DWORD DVar2;
  uint _Size;
  DWORD local_28;
  DWORD local_24;
  
                    /* 0xbfc4  49  IcmpSendEcho2 */
  DVar2 = 0;
  if (ReplyBuffer == (LPVOID)0x0) {
    DVar2 = 0x3e6;
LAB_c048bff8:
    SetLastError(DVar2);
    return 0;
  }
  if (ReplySize < 0x1c) {
    SetLastError(0x7a);
    return 0;
  }
  _Size = (uint)RequestSize;
  local_28 = _Size + 0x14;
  if (RequestOptions != (PIP_OPTION_INFORMATION)0x0) {
    local_28 = RequestOptions->OptionsSize + local_28;
  }
  if (local_28 < ReplySize) {
    local_28 = ReplySize;
  }
  hMem = LocalAlloc(0,local_28);
  if (hMem == (IPAddr *)0x0) {
    DVar2 = 8;
    goto LAB_c048bff8;
  }
  *hMem = DestinationAddress;
  hMem[1] = Timeout;
  *(WORD *)((int)hMem + 10) = RequestSize;
  *(undefined2 *)(hMem + 4) = 0x14;
  if (RequestOptions == (PIP_OPTION_INFORMATION)0x0) {
    *(undefined1 *)(hMem + 3) = 0;
    *(undefined1 *)((int)hMem + 0x12) = 0;
  }
  else {
    *(undefined1 *)(hMem + 3) = 1;
    *(UCHAR *)((int)hMem + 0xd) = RequestOptions->Ttl;
    *(UCHAR *)((int)hMem + 0xe) = RequestOptions->Tos;
    *(UCHAR *)((int)hMem + 0xf) = RequestOptions->Flags;
    *(UCHAR *)((int)hMem + 0x12) = RequestOptions->OptionsSize;
    if (RequestOptions->OptionsSize != 0) {
      memcpy(hMem + 5,RequestOptions->OptionsData,(uint)RequestOptions->OptionsSize);
    }
  }
  uVar1 = (short)hMem[4] + (ushort)*(byte *)((int)hMem + 0x12);
  *(ushort *)(hMem + 2) = uVar1;
  if ((_Size != 0) && (RequestData != (LPVOID)0x0)) {
    memcpy((void *)((uint)uVar1 + (int)hMem),RequestData,_Size);
  }
  if (DAT_c048f414 != 0) {
    local_24 = ReplySize;
    dwErrCode = FUN_c048d228(6,2,hMem,&local_28,ReplyBuffer,&local_24);
    if (dwErrCode != 0) {
      SetLastError(dwErrCode);
      goto LAB_c048c198;
    }
  }
  uVar1 = FUN_c048bd20((int)ReplyBuffer,ReplySize);
  DVar2 = CONCAT22(extraout_var,uVar1);
LAB_c048c198:
  LocalFree(hMem);
  return DVar2;
}



/* c048c1cc Icmp6ParseReplies */

/* Boundary evidence: original MIPS .pdata c048c1cc..c048c23b. Semantic name remains unreviewed. */

undefined4 Icmp6ParseReplies(int param_1,int param_2)

{
  DWORD dwErrCode;
  
                    /* 0xc1cc  43  Icmp6ParseReplies */
  if ((param_1 != 0) && (param_2 != 0)) {
    if (*(int *)(param_1 + 0x1c) == 0x2b18) {
      *(undefined4 *)(param_1 + 0x1c) = 0x2afb;
    }
    dwErrCode = *(DWORD *)(param_1 + 0x1c);
    if ((dwErrCode == 0) || (dwErrCode == 0x2b05)) {
      return 1;
    }
    SetLastError(dwErrCode);
  }
  return 0;
}



/* c048c23c Icmp6SendEcho2 */

/* Boundary evidence: original MIPS .pdata c048c23c..c048c3bf. Semantic name remains unreviewed. */

undefined4 Icmp6SendEcho2(void)

{
  HLOCAL _Dst;
  BOOL BVar1;
  DWORD dwErrCode;
  uint _Size;
  undefined4 uVar2;
  int in_stack_00000010;
  int in_stack_00000014;
  void *in_stack_00000018;
  ushort in_stack_0000001c;
  undefined1 *in_stack_00000020;
  LPVOID in_stack_00000024;
  uint in_stack_00000028;
  undefined4 in_stack_0000002c;
  
                    /* 0xc23c  44  Icmp6SendEcho2 */
  uVar2 = 0;
  if (in_stack_00000024 == (LPVOID)0x0) {
    dwErrCode = 0x3e6;
  }
  else {
    if (in_stack_00000028 < 0x24) {
      SetLastError(0x7a);
      return 0;
    }
    _Size = (uint)in_stack_0000001c;
    _Dst = LocalAlloc(0,_Size + 0x40);
    if (_Dst != (HLOCAL)0x0) {
      memcpy(_Dst,(void *)(in_stack_00000014 + 2),0x1a);
      memcpy((void *)((int)_Dst + 0x1a),(void *)(in_stack_00000010 + 2),0x1a);
      *(undefined4 *)((int)_Dst + 0x34) = in_stack_0000002c;
      if (in_stack_00000020 != (undefined1 *)0x0) {
        *(undefined1 *)((int)_Dst + 0x38) = *in_stack_00000020;
        *(uint *)((int)_Dst + 0x3c) = (uint)(byte)in_stack_00000020[2];
      }
      if ((_Size != 0) && (in_stack_00000018 != (void *)0x0)) {
        memcpy((void *)((int)_Dst + 0x40),in_stack_00000018,_Size);
      }
      FUN_c0485020();
      BVar1 = DeviceIoControl(DAT_c048f5a0,0x120000,_Dst,_Size + 0x40,in_stack_00000024,
                              in_stack_00000028,&stack0x00000028,(LPOVERLAPPED)0x0);
      if (BVar1 != 0) {
        uVar2 = Icmp6ParseReplies((int)in_stack_00000024,in_stack_00000028);
      }
      LocalFree(_Dst);
      return uVar2;
    }
    dwErrCode = 8;
  }
  SetLastError(dwErrCode);
  return 0;
}



/* c048c3c0 FUN_c048c3c0 */

/* Boundary evidence: original MIPS .pdata c048c3c0..c048c43b. Semantic name remains unreviewed. */

undefined4 FUN_c048c3c0(undefined4 param_1,int param_2)

{
  undefined4 *hMem;
  
  if (param_2 == 0) {
    DeleteCriticalSection((LPCRITICAL_SECTION)&DAT_c048f620);
    while (hMem = DAT_c048f430, DAT_c048f430 != (HLOCAL)0x0) {
      DAT_c048f430 = (undefined4 *)*DAT_c048f430;
      LocalFree(hMem);
    }
  }
  else if (param_2 == 1) {
    InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_c048f620);
    DAT_c048f414 = 1;
  }
  return 1;
}



/* c048c43c FUN_c048c43c */

/* Boundary evidence: original MIPS .pdata c048c43c..c048c61f. Semantic name remains unreviewed. */

undefined4 FUN_c048c43c(HMODULE param_1,int param_2)

{
  int iVar1;
  
  if (param_2 == 0) {
    if (DAT_c048f59c == 0) {
      return 1;
    }
    if (DAT_c048f5d4 != (HANDLE)0x0) {
      HeapDestroy(DAT_c048f5d4);
    }
    DeleteCriticalSection((LPCRITICAL_SECTION)&DAT_c048f600);
    DeleteCriticalSection((LPCRITICAL_SECTION)&DAT_c048f5c0);
    DeleteCriticalSection((LPCRITICAL_SECTION)&DAT_c048f580);
    DeleteCriticalSection((LPCRITICAL_SECTION)&DAT_c048f5e0);
    if (DAT_c048f5a4 != 0) {
      FUN_c048457c();
    }
    if (DAT_c048f5ac != 0) {
      FUN_c04845d0();
    }
    FUN_c0488cac(param_1,0);
    DAT_c048f59c = 0;
    iVar1 = FUN_c048c3c0(param_1,0);
    if (iVar1 != 0) {
      return 1;
    }
  }
  else {
    if (param_2 != 1) {
      return 1;
    }
    DAT_c048f59c = 0;
    DisableThreadLibraryCalls(param_1);
    iVar1 = FUN_c048c3c0(param_1,1);
    if (iVar1 != 0) {
      DAT_c048f5d4 = HeapCreate(0,0x1000,0);
      if (DAT_c048f5d4 != (HANDLE)0x0) {
        InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_c048f600);
        InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_c048f5c0);
        InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_c048f580);
        InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_c048f5e0);
        DAT_c048f5b8 = 0;
        DAT_c048f5d8 = 0;
        DAT_c048f5dc = 0;
        DAT_c048f594 = 0;
        DAT_c048f614 = 0;
        FUN_c048cae4();
        DAT_c048f59c = 1;
        DAT_c048f5a4 = 0;
        DAT_c048f5b0 = param_1;
        return 1;
      }
      FUN_c048c3c0(param_1,0);
    }
  }
  return 0;
}



/* c048c620 FUN_c048c620 */

undefined4 FUN_c048c620(void)

{
  return 0;
}



/* c048c6c0 FUN_c048c6c0 */

/* Boundary evidence: original MIPS .pdata c048c6c0..c048c81f. Semantic name remains unreviewed. */

int FUN_c048c6c0(int param_1,int param_2)

{
  u_short uVar1;
  u_short uVar2;
  int iVar3;
  undefined2 extraout_var;
  undefined2 extraout_var_00;
  undefined2 extraout_var_01;
  undefined2 extraout_var_02;
  uint uVar4;
  uint uVar5;
  
  uVar5 = *(uint *)(param_2 + 4);
  uVar4 = *(uint *)(param_1 + 4);
  iVar3 = (uVar4 & 0xff) - (uVar5 & 0xff);
  if ((((iVar3 == 0) && (iVar3 = (uVar4 & 0xff00) - (uVar5 & 0xff00), iVar3 == 0)) &&
      (iVar3 = (uVar4 & 0xff0000) - (uVar5 & 0xff0000), iVar3 == 0)) &&
     (iVar3 = (uVar4 >> 8 & 0xff0000) - (uVar5 >> 8 & 0xff0000), iVar3 == 0)) {
    uVar1 = ntohs(*(u_short *)(param_2 + 8));
    uVar2 = ntohs(*(u_short *)(param_1 + 8));
    iVar3 = CONCAT22(extraout_var_00,uVar2) - CONCAT22(extraout_var,uVar1);
    if (iVar3 == 0) {
      uVar5 = *(uint *)(param_2 + 0xc);
      uVar4 = *(uint *)(param_1 + 0xc);
      iVar3 = (uVar4 & 0xff) - (uVar5 & 0xff);
      if (((iVar3 == 0) && (iVar3 = (uVar4 & 0xff00) - (uVar5 & 0xff00), iVar3 == 0)) &&
         ((iVar3 = (uVar4 & 0xff0000) - (uVar5 & 0xff0000), iVar3 == 0 &&
          (iVar3 = (uVar4 >> 8 & 0xff0000) - (uVar5 >> 8 & 0xff0000), iVar3 == 0)))) {
        uVar1 = ntohs(*(u_short *)(param_2 + 0x10));
        uVar2 = ntohs(*(u_short *)(param_1 + 0x10));
        iVar3 = CONCAT22(extraout_var_02,uVar2) - CONCAT22(extraout_var_01,uVar1);
      }
    }
  }
  return iVar3;
}



/* c048c820 FUN_c048c820 */

/* Boundary evidence: original MIPS .pdata c048c820..c048c8df. Semantic name remains unreviewed. */

int FUN_c048c820(uint *param_1,uint *param_2)

{
  u_short uVar1;
  u_short uVar2;
  int iVar3;
  undefined2 extraout_var;
  undefined2 extraout_var_00;
  uint uVar4;
  uint uVar5;
  
  uVar5 = *param_2;
  uVar4 = *param_1;
  iVar3 = (uVar4 & 0xff) - (uVar5 & 0xff);
  if ((((iVar3 == 0) && (iVar3 = (uVar4 & 0xff00) - (uVar5 & 0xff00), iVar3 == 0)) &&
      (iVar3 = (uVar4 & 0xff0000) - (uVar5 & 0xff0000), iVar3 == 0)) &&
     (iVar3 = (uVar4 >> 8 & 0xff0000) - (uVar5 >> 8 & 0xff0000), iVar3 == 0)) {
    uVar1 = ntohs((u_short)param_2[1]);
    uVar2 = ntohs((u_short)param_1[1]);
    iVar3 = CONCAT22(extraout_var_00,uVar2) - CONCAT22(extraout_var,uVar1);
  }
  return iVar3;
}



/* c048ca40 FUN_c048ca40 */

int FUN_c048ca40(uint param_1,uint param_2)

{
  uint *puVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  
  uVar5 = 0x3fffffff;
  uVar3 = 0;
  uVar4 = uVar5;
  puVar1 = DAT_c048f42c;
  if (*DAT_c048f42c != 0) {
    do {
      uVar2 = puVar1[1];
      if (((param_1 == uVar2) && (uVar5 = uVar3, uVar4 != 0x3fffffff)) ||
         ((param_2 == uVar2 && (uVar4 = uVar3, uVar5 != 0x3fffffff)))) break;
      uVar3 = uVar3 + 1;
      puVar1 = puVar1 + 1;
    } while (uVar3 < *DAT_c048f42c);
  }
  return uVar5 - uVar4;
}



/* c048caa4 FUN_c048caa4 */

/* Boundary evidence: original MIPS .pdata c048caa4..c048cac3. Semantic name remains unreviewed. */

void FUN_c048caa4(int param_1,int param_2)

{
  FUN_c048ca40(*(uint *)(param_1 + 0x200),*(uint *)(param_2 + 0x200));
  return;
}



/* c048cac4 FUN_c048cac4 */

/* Boundary evidence: original MIPS .pdata c048cac4..c048cae3. Semantic name remains unreviewed. */

void FUN_c048cac4(int param_1,int param_2)

{
  FUN_c048ca40(*(uint *)(param_1 + 4),*(uint *)(param_2 + 4));
  return;
}



/* c048cae4 FUN_c048cae4 */

void FUN_c048cae4(void)

{
  undefined4 *puVar1;
  int iVar2;
  
  puVar1 = &DAT_c048f440;
  iVar2 = 0x25;
  do {
    puVar1[1] = puVar1;
    *puVar1 = puVar1;
    iVar2 = iVar2 + -1;
    puVar1 = puVar1 + 2;
  } while (iVar2 != 0);
  return;
}



/* c048cb0c FUN_c048cb0c */

undefined4 * FUN_c048cb0c(uint param_1)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)(&DAT_c048f440)[(param_1 % 0x25) * 2];
  while( true ) {
    if (puVar1 == &DAT_c048f440 + (param_1 % 0x25) * 2) {
      return (undefined4 *)0x0;
    }
    if (puVar1[2] == param_1) break;
    puVar1 = (undefined4 *)*puVar1;
  }
  return puVar1;
}



/* c048cb58 FUN_c048cb58 */

/* Boundary evidence: original MIPS .pdata c048cb58..c048cc0b. Semantic name remains unreviewed. */

undefined4 FUN_c048cb58(uint param_1,int param_2)

{
  undefined4 *puVar1;
  int *piVar2;
  int *piVar3;
  
  puVar1 = FUN_c048cb0c(param_1);
  if (puVar1 == (undefined4 *)0x0) {
    piVar2 = HeapAlloc(DAT_c048f5d4,0,0x14);
    if (piVar2 == (int *)0x0) {
      return 8;
    }
    piVar2[4] = -1;
    piVar2[2] = param_1;
    piVar2[3] = param_2;
    piVar3 = &DAT_c048f440 + (param_1 % 0x25) * 2;
    *piVar2 = *piVar3;
    piVar2[1] = (int)piVar3;
    *(int **)(*piVar3 + 4) = piVar2;
    *piVar3 = (int)piVar2;
  }
  else {
    puVar1[3] = param_2;
  }
  return 0;
}



/* c048cc0c FUN_c048cc0c */

/* Boundary evidence: original MIPS .pdata c048cc0c..c048ccbf. Semantic name remains unreviewed. */

undefined4 FUN_c048cc0c(uint param_1,int param_2)

{
  undefined4 *puVar1;
  int *piVar2;
  int *piVar3;
  
  puVar1 = FUN_c048cb0c(param_1);
  if (puVar1 == (undefined4 *)0x0) {
    piVar2 = HeapAlloc(DAT_c048f5d4,0,0x14);
    if (piVar2 == (int *)0x0) {
      return 8;
    }
    piVar2[3] = -1;
    piVar2[2] = param_1;
    piVar2[4] = param_2;
    piVar3 = &DAT_c048f440 + (param_1 % 0x25) * 2;
    *piVar2 = *piVar3;
    piVar2[1] = (int)piVar3;
    *(int **)(*piVar3 + 4) = piVar2;
    *piVar3 = (int)piVar2;
  }
  else {
    puVar1[4] = param_2;
  }
  return 0;
}



/* c048ccc0 FUN_c048ccc0 */

/* Boundary evidence: original MIPS .pdata c048ccc0..c048ccf3. Semantic name remains unreviewed. */

undefined4 FUN_c048ccc0(uint param_1)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  puVar1 = FUN_c048cb0c(param_1);
  if (puVar1 == (undefined4 *)0x0) {
    uVar2 = 0xffffffff;
  }
  else {
    uVar2 = puVar1[4];
  }
  return uVar2;
}



/* c048ccf4 FUN_c048ccf4 */

/* Boundary evidence: original MIPS .pdata c048ccf4..c048cd27. Semantic name remains unreviewed. */

undefined4 FUN_c048ccf4(uint param_1)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  puVar1 = FUN_c048cb0c(param_1);
  if (puVar1 == (undefined4 *)0x0) {
    uVar2 = 0xffffffff;
  }
  else {
    uVar2 = puVar1[3];
  }
  return uVar2;
}



/* c048cd28 FUN_c048cd28 */

/* Boundary evidence: original MIPS .pdata c048cd28..c048cf1b. Semantic name remains unreviewed. */

undefined4 FUN_c048cd28(void)

{
  LPVOID lpMem;
  undefined4 uVar1;
  DWORD DVar2;
  int *piVar3;
  int *piVar4;
  uint uVar5;
  int *piVar6;
  uint local_3b8;
  DWORD local_3b4;
  DWORD local_3b0 [2];
  undefined4 local_3a8;
  int local_3a4;
  undefined4 local_3a0;
  undefined4 local_39c;
  undefined4 local_398;
  undefined1 auStack_394 [532];
  uint local_180 [87];
  uint local_24;
  
  local_24 = DAT_c048f418;
  lpMem = FUN_c0482d48(&local_3b8);
  if (lpMem == (LPVOID)0x0) {
    FUN_c048e238(local_24);
    uVar1 = 0x1f;
  }
  else {
    local_3b4 = 0x24;
    piVar6 = &DAT_c048f440;
    local_398 = 1;
    local_3a8 = 0x200;
    local_3a0 = 0x200;
    local_39c = 0x100;
    piVar4 = piVar6;
    do {
      for (piVar3 = (int *)*piVar4; piVar3 != piVar4; piVar3 = (int *)*piVar3) {
        piVar3[4] = -1;
      }
      piVar4 = piVar4 + 2;
    } while (piVar4 < (int *)0xc048f568);
    uVar5 = 0;
    if (local_3b8 != 0) {
      piVar4 = (int *)((int)lpMem + 4);
      do {
        if (piVar4[-1] == 0x200) {
          local_3b0[0] = 0x15c;
          local_3a4 = *piVar4;
          memset(auStack_394,0,0x10);
          DVar2 = FUN_c04829ac(2,&local_3a8,&local_3b4,local_180,local_3b0);
          if (DVar2 == 0) {
            FUN_c048cc0c(local_180[0],*piVar4);
          }
        }
        uVar5 = uVar5 + 1;
        piVar4 = piVar4 + 2;
      } while (uVar5 < local_3b8);
    }
    do {
      piVar4 = (int *)*piVar6;
      while (piVar3 = piVar4, piVar3 != piVar6) {
        piVar4 = (int *)*piVar3;
        if (piVar3[4] == -1) {
          *(int *)piVar3[1] = *piVar3;
          *(int *)(*piVar3 + 4) = piVar3[1];
          HeapFree(DAT_c048f5d4,0,piVar3);
        }
      }
      piVar6 = piVar6 + 2;
    } while (piVar6 < (int *)0xc048f568);
    DAT_c048f5d8 = GetTickCount();
    HeapFree(DAT_c048f5d4,0,lpMem);
    FUN_c048e238(local_24);
    uVar1 = 0;
  }
  return uVar1;
}



/* c048cf1c FUN_c048cf1c */

/* Boundary evidence: original MIPS .pdata c048cf1c..c048d07f. Semantic name remains unreviewed. */

DWORD FUN_c048cf1c(void)

{
  DWORD DVar1;
  int iVar2;
  uint uVar3;
  DWORD local_50 [2];
  undefined1 auStack_48 [4];
  uint local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined1 auStack_2c [20];
  
  if (DAT_c048f5dc != (LPVOID)0x0) {
    HeapFree(DAT_c048f5d4,1,DAT_c048f5dc);
    DAT_c048f5dc = (LPVOID)0x0;
  }
  DVar1 = FUN_c048419c((int *)&DAT_c048f5dc,(int *)&DAT_c048f594,DAT_c048f5d4,0,0);
  if (DVar1 == 0) {
    uVar3 = 0;
    local_50[1] = 0x24;
    if (DAT_c048f594 != 0) {
      iVar2 = 0;
      do {
        local_38 = 0x200;
        local_34 = 0x100;
        local_40 = 0x280;
        local_30 = 1;
        local_3c = *(undefined4 *)(iVar2 + (int)DAT_c048f5dc);
        local_50[0] = 8;
        memset(auStack_2c,0,0x10);
        DVar1 = FUN_c04829ac(2,&local_40,local_50 + 1,auStack_48,local_50);
        if (DVar1 != 0) {
          return DVar1;
        }
        FUN_c048cb58(local_44,*(int *)(iVar2 + (int)DAT_c048f5dc));
        uVar3 = uVar3 + 1;
        iVar2 = iVar2 + 4;
      } while (uVar3 < DAT_c048f594);
    }
    DAT_c048f5b8 = GetTickCount();
    DVar1 = 0;
  }
  else {
    DAT_c048f5dc = (LPVOID)0x0;
    DVar1 = 0x3eb;
  }
  return DVar1;
}



/* c048d080 FUN_c048d080 */

/* Boundary evidence: original MIPS .pdata c048d080..c048d15b. Semantic name remains unreviewed. */

DWORD FUN_c048d080(int param_1,undefined4 *param_2)

{
  undefined1 *puVar1;
  uint uVar2;
  DWORD DVar3;
  DWORD local_70 [2];
  undefined1 auStack_68 [24];
  undefined4 local_50;
  undefined1 auStack_48 [4];
  undefined1 auStack_44 [4];
  undefined1 auStack_40 [4];
  undefined1 auStack_3c [4];
  undefined1 auStack_38 [4];
  undefined1 auStack_34 [28];
  uint local_18;
  
  local_18 = DAT_c048f418;
  puVar1 = auStack_48 + 3;
  uVar2 = (uint)puVar1 & 3;
  *(uint *)(puVar1 + -uVar2) =
       *(uint *)(puVar1 + -uVar2) & -1 << (uVar2 + 1) * 8 | 0x301U >> (3 - uVar2) * 8;
  puVar1 = auStack_44 + 3;
  uVar2 = (uint)puVar1 & 3;
  *(uint *)(puVar1 + -uVar2) =
       *(uint *)(puVar1 + -uVar2) & -1 << (uVar2 + 1) * 8 | 0U >> (3 - uVar2) * 8;
  puVar1 = auStack_40 + 3;
  uVar2 = (uint)puVar1 & 3;
  *(uint *)(puVar1 + -uVar2) =
       *(uint *)(puVar1 + -uVar2) & -1 << (uVar2 + 1) * 8 | 0x200U >> (3 - uVar2) * 8;
  puVar1 = auStack_3c + 3;
  uVar2 = (uint)puVar1 & 3;
  *(uint *)(puVar1 + -uVar2) =
       *(uint *)(puVar1 + -uVar2) & -1 << (uVar2 + 1) * 8 | 0x100U >> (3 - uVar2) * 8;
  puVar1 = auStack_38 + 3;
  uVar2 = (uint)puVar1 & 3;
  *(uint *)(puVar1 + -uVar2) =
       *(uint *)(puVar1 + -uVar2) & -1 << (uVar2 + 1) * 8 | 3U >> (3 - uVar2) * 8;
  auStack_48 = (undefined1  [4])0x301;
  auStack_44 = (undefined1  [4])0x0;
  auStack_40 = (undefined1  [4])0x200;
  auStack_3c = (undefined1  [4])0x100;
  auStack_38 = (undefined1  [4])0x3;
  memcpy(auStack_34,(void *)(param_1 + 2),0x1a);
  local_70[0] = 0x2e;
  local_70[1] = 0x1c;
  DVar3 = FUN_c04829ac(0x17,auStack_48,local_70,auStack_68,local_70 + 1);
  if (DVar3 == 0) {
    *param_2 = local_50;
    FUN_c048e238(local_18);
    DVar3 = 0;
  }
  else {
    FUN_c048e238(local_18);
  }
  return DVar3;
}



/* c048d15c FUN_c048d15c */

/* Boundary evidence: original MIPS .pdata c048d15c..c048d227. Semantic name remains unreviewed. */

DWORD FUN_c048d15c(DWORD param_1,LPVOID param_2,DWORD *param_3,LPVOID param_4,DWORD *param_5)

{
  DWORD DVar1;
  BOOL BVar2;
  DWORD local_20 [2];
  
  FUN_c0485020();
  if (DAT_c048f5a0 == (HANDLE)0xffffffff) {
    DVar1 = 2;
  }
  else {
    BVar2 = DeviceIoControl(DAT_c048f5a0,param_1,param_2,*param_3,param_4,*param_5,local_20,
                            (LPOVERLAPPED)0x0);
    *param_5 = local_20[0];
    if (BVar2 == 0) {
      DVar1 = GetLastError();
    }
    else {
      DVar1 = 0;
    }
  }
  return DVar1;
}



/* c048d228 FUN_c048d228 */

/* Boundary evidence: original MIPS .pdata c048d228..c048d2d3. Semantic name remains unreviewed. */

DWORD FUN_c048d228(int param_1,DWORD param_2,LPVOID param_3,DWORD *param_4,LPVOID param_5,
                  DWORD *param_6)

{
  DWORD DVar1;
  int iVar2;
  
  if (param_1 == 0x29) {
    DVar1 = FUN_c048d15c(param_2,param_3,param_4,param_5,param_6);
  }
  else {
    FUN_c0485020();
    iVar2 = WSAControl(6,param_2,param_3,param_4,param_5,param_6);
    if (iVar2 == 0) {
      DVar1 = 0;
    }
    else {
      DVar1 = FUN_c048294c(iVar2);
    }
  }
  return DVar1;
}



/* c048d2d4 FUN_c048d2d4 */

/* Boundary evidence: original MIPS .pdata c048d2d4..c048d31f. Semantic name remains unreviewed. */

void FUN_c048d2d4(uint param_1,char *param_2)

{
  sprintf(param_2,"%d.%d.%d.%d",param_1 & 0xff,param_1 >> 8 & 0xff,param_1 >> 0x10 & 0xff,
          param_1 >> 0x18);
  return;
}



/* c048d320 FUN_c048d320 */

/* Boundary evidence: original MIPS .pdata c048d320..c048d393. Semantic name remains unreviewed. */

void FUN_c048d320(char *param_1,int param_2,char *param_3)

{
  size_t sVar1;
  size_t _Count;
  
  sVar1 = strlen(param_3);
  _Count = param_2 - 1;
  if (sVar1 <= _Count) {
    _Count = strlen(param_3);
  }
  strncpy(param_1,param_3,_Count);
  param_1[_Count] = '\0';
  return;
}



/* c048d394 FUN_c048d394 */

/* Boundary evidence: original MIPS .pdata c048d394..c048d43f. Semantic name remains unreviewed. */

undefined4 FUN_c048d394(undefined4 *param_1,uint param_2,uint param_3,undefined4 param_4)

{
  undefined4 *puVar1;
  
  if (*(char *)(param_1 + 1) != '\0') {
    do {
      puVar1 = param_1;
      param_1 = (undefined4 *)*puVar1;
    } while (param_1 != (undefined4 *)0x0);
    param_1 = LocalAlloc(0x40,0x28);
    *puVar1 = param_1;
    if (param_1 == (undefined4 *)0x0) {
      return 0;
    }
  }
  FUN_c048d2d4(param_2,(char *)(param_1 + 1));
  FUN_c048d2d4(param_3,(char *)(param_1 + 5));
  param_1[9] = param_4;
  *param_1 = 0;
  return 1;
}



/* c048d440 FUN_c048d440 */

/* Boundary evidence: original MIPS .pdata c048d440..c048d51b. Semantic name remains unreviewed. */

undefined4 FUN_c048d440(int *param_1,char *param_2,char *param_3)

{
  undefined4 uVar1;
  int iVar2;
  int *piVar3;
  
  if ((char)param_1[1] == '\0') {
LAB_c048d4dc:
    FUN_c048d320((char *)(param_1 + 1),0x10,param_2);
    FUN_c048d320((char *)(param_1 + 5),0x10,param_3);
    uVar1 = 1;
  }
  else {
    iVar2 = *param_1;
    piVar3 = param_1;
    while (iVar2 != 0) {
      iVar2 = strncmp((char *)(piVar3 + 1),param_2,0x10);
      if (iVar2 == 0) goto LAB_c048d4d0;
      piVar3 = (int *)*piVar3;
      iVar2 = *piVar3;
    }
    iVar2 = strncmp((char *)(piVar3 + 1),param_2,0x10);
    if (iVar2 != 0) {
      param_1 = LocalAlloc(0x40,0x28);
      *piVar3 = (int)param_1;
      if (param_1 != (int *)0x0) goto LAB_c048d4dc;
    }
LAB_c048d4d0:
    uVar1 = 0;
  }
  return uVar1;
}



/* c048d51c FUN_c048d51c */

/* Boundary evidence: original MIPS .pdata c048d51c..c048de9f. Semantic name remains unreviewed. */

int * FUN_c048d51c(void)

{
  bool bVar1;
  DWORD *hMem;
  DWORD DVar2;
  int *piVar3;
  HANDLE pvVar4;
  DWORD DVar5;
  int *piVar6;
  int iVar7;
  uint *puVar8;
  int *piVar9;
  uint uVar10;
  DWORD DVar11;
  int *piVar12;
  int *piVar13;
  DWORD DVar14;
  uint uVar15;
  DWORD *pDVar16;
  uint *puVar17;
  uint *lpMem;
  uint uVar18;
  DWORD local_248;
  DWORD local_244;
  uint local_240;
  DWORD local_23c;
  DWORD local_238;
  uint local_234;
  DWORD local_230;
  DWORD local_22c;
  undefined4 local_228;
  undefined4 local_224;
  undefined4 local_220;
  uint *local_20c;
  DWORD local_208;
  int local_204;
  int *local_200;
  int local_1fc;
  DWORD local_1f8;
  DWORD local_1f4;
  undefined4 local_1f0;
  undefined4 local_1ec;
  undefined4 local_1e8;
  undefined1 auStack_1d0 [84];
  uint local_17c;
  int local_178;
  undefined1 auStack_170 [88];
  int local_118;
  uint local_110;
  int local_10c;
  uint local_100;
  undefined1 auStack_fc [68];
  uint local_b8;
  char acStack_b4 [136];
  uint local_2c;
  
  local_2c = DAT_c048f418;
  piVar13 = (int *)0x0;
  lpMem = (uint *)0x0;
  local_200 = (int *)0x0;
  hMem = FUN_c048dea0(&local_240);
  if (hMem == (DWORD *)0x0) goto LAB_c048ddec;
  local_20c = GetAdapterOrderMap();
  if (local_20c == (uint *)0x0) {
    LocalFree(hMem);
    goto LAB_c048ddec;
  }
  uVar18 = 0;
  pDVar16 = hMem;
  if (local_240 != 0) {
    do {
      if (*pDVar16 == 0x200) {
        memset(&local_230,0,0x24);
        DVar11 = *pDVar16;
        DVar14 = pDVar16[1];
        local_228 = 0x100;
        local_224 = 0x100;
        local_220 = 1;
        local_244 = 0x24;
        local_248 = 4;
        local_230 = DVar11;
        local_22c = DVar14;
        DVar2 = FUN_c048d228(6,0,&local_230,&local_244,&local_204,&local_248);
        if ((DVar2 == 0) && (local_204 == 0x202)) {
          memset(&local_230,0,0x24);
          local_228 = 0x200;
          local_220 = 1;
          local_224 = 0x100;
          local_244 = 0x24;
          local_248 = 0xe1;
          local_230 = DVar11;
          local_22c = DVar14;
          DVar2 = FUN_c048d228(6,0,&local_230,&local_244,&local_110,&local_248);
          if (((DVar2 == 0) || (DVar2 == 0xea)) && (local_10c != 0x18)) {
            piVar3 = LocalAlloc(0x40,0x280);
            if (piVar3 == (int *)0x0) goto LAB_c048ddb4;
            memset(piVar3,0,0x280);
            uVar15 = local_b8;
            if (0x80 < local_b8) {
              uVar15 = 0x80;
            }
            strncpy((char *)(piVar3 + 0x43),acStack_b4,uVar15);
            *(undefined1 *)((int)piVar3 + uVar15 + 0x10c) = 0;
            uVar15 = local_100;
            if (8 < local_100) {
              uVar15 = 8;
            }
            piVar3[100] = uVar15 & 0xff;
            memcpy(piVar3 + 0x65,auStack_fc,uVar15);
            piVar3[0x67] = local_110;
            piVar3[0x68] = local_10c;
            uVar15 = 0;
            puVar17 = local_20c;
            if (*local_20c != 0) {
              do {
                if (puVar17[1] == local_110) break;
                uVar15 = uVar15 + 1;
                puVar17 = puVar17 + 1;
              } while (uVar15 < *local_20c);
            }
            piVar3[1] = uVar15;
            *piVar3 = (int)piVar13;
            piVar12 = (int *)0x0;
            if (piVar13 != (int *)0x0) {
              do {
                piVar6 = (int *)*piVar3;
                if (uVar15 < (uint)piVar6[1]) break;
                iVar7 = *piVar6;
                *piVar3 = iVar7;
                piVar12 = piVar6;
              } while (iVar7 != 0);
              if (piVar12 != (int *)0x0) {
                *piVar12 = (int)piVar3;
              }
            }
            if (piVar13 == (int *)*piVar3) {
              piVar13 = piVar3;
            }
          }
        }
      }
      uVar18 = uVar18 + 1;
      pDVar16 = pDVar16 + 2;
    } while (uVar18 < local_240);
  }
  local_23c = 0x30;
  pvVar4 = GetProcessHeap();
  lpMem = HeapAlloc(pvVar4,0,0x30);
  if (lpMem != (uint *)0x0) {
    *lpMem = 0;
    DVar2 = GetUniDirectionalAdapterInfo(lpMem,&local_23c);
    if (DVar2 == 0xea) {
      local_23c = (*lpMem + 2) * 4;
      pvVar4 = GetProcessHeap();
      HeapFree(pvVar4,0,lpMem);
      pvVar4 = GetProcessHeap();
      lpMem = HeapAlloc(pvVar4,0,local_23c);
      if (lpMem == (uint *)0x0) goto LAB_c048ddb4;
      DVar2 = GetUniDirectionalAdapterInfo(lpMem,&local_23c);
    }
    if (DVar2 == 0) {
      local_234 = 0;
      piVar3 = (int *)0x0;
      pDVar16 = hMem;
      if (local_240 != 0) {
        do {
          uVar18 = local_234;
          if (*pDVar16 == 0x301) {
            memset(&local_230,0,0x24);
            DVar2 = *pDVar16;
            DVar11 = pDVar16[1];
            local_228 = 0x100;
            local_224 = 0x100;
            local_220 = 1;
            local_244 = 0x24;
            local_248 = 4;
            local_238 = DVar2;
            local_230 = DVar2;
            local_22c = DVar11;
            local_208 = DVar11;
            DVar14 = FUN_c048d228(6,0,&local_230,&local_244,&local_1fc,&local_248);
            if ((DVar14 == 0) && (local_1fc == 0x303)) {
              memset(&local_230,0,0x24);
              local_220 = 1;
              local_224 = 0x100;
              local_244 = 0x24;
              local_228 = 0x200;
              local_248 = 0x5c;
              local_230 = DVar2;
              local_22c = DVar11;
              DVar14 = FUN_c048d228(6,0,&local_230,&local_244,auStack_1d0,&local_248);
              if ((DVar14 == 0) && (local_248 == 0x5c)) {
                if (local_17c != 0) {
                  local_248 = (local_17c + 10) * 0x18;
                  piVar3 = LocalAlloc(0,local_248);
                  if (piVar3 == (int *)0x0) goto LAB_c048ddb4;
                  memset(&local_230,0,0x24);
                  local_224 = 0x100;
                  local_244 = 0x24;
                  local_220 = 0x102;
                  local_228 = 0x200;
                  local_230 = DVar2;
                  local_22c = DVar11;
                  DVar2 = FUN_c048d228(6,0,&local_230,&local_244,piVar3,&local_248);
                  if (DVar2 != 0) {
                    LocalFree(piVar3);
                    uVar18 = local_234;
                    goto LAB_c048dd40;
                  }
                  uVar18 = local_248 / 0x18;
                  if (local_17c <= local_248 / 0x18) {
                    uVar18 = local_17c;
                  }
                  uVar15 = 0;
                  if (uVar18 != 0) {
                    puVar17 = (uint *)(piVar3 + 2);
LAB_c048da9c:
                    if (piVar13 != (int *)0x0) {
                      piVar12 = piVar13;
                      do {
                        if (piVar12[0x67] == puVar17[-1]) {
                          iVar7 = FUN_c048d394(piVar12 + 0x6b,puVar17[-2],*puVar17,
                                               (uint)(ushort)puVar17[3]);
                          if (iVar7 == 0) goto LAB_c048ddac;
                          uVar10 = 0;
                          if (*lpMem != 0) {
                            puVar8 = lpMem;
                            goto LAB_c048dafc;
                          }
                          break;
                        }
                        piVar12 = (int *)*piVar12;
                      } while (piVar12 != (int *)0x0);
                    }
                    goto LAB_c048db28;
                  }
LAB_c048db38:
                  LocalFree(piVar3);
                  uVar18 = local_234;
                  DVar2 = local_238;
                  DVar11 = local_208;
                }
                iVar7 = local_178;
                if (local_178 != 0) {
                  bVar1 = true;
                  memset(&local_230,0,0x24);
                  local_248 = iVar7 * 0x34;
                  local_228 = 0x200;
                  local_224 = 0x100;
                  local_220 = 0x101;
                  local_244 = 0x24;
                  piVar3 = (int *)0x0;
                  local_230 = DVar2;
                  local_22c = DVar11;
                  do {
                    DVar14 = local_248;
                    if (piVar3 != (int *)0x0) {
                      LocalFree(piVar3);
                    }
                    piVar3 = LocalAlloc(0,local_248);
                    if (piVar3 == (int *)0x0) goto LAB_c048ddb4;
                    DVar5 = FUN_c048d228(6,0,&local_230,&local_244,piVar3,&local_248);
                    if (DVar5 != 0) {
                      if (DVar5 != 0xea) goto LAB_c048ddac;
                      memset(&local_1f8,0,0x24);
                      local_1f0 = 0x200;
                      local_1ec = 0x100;
                      local_1e8 = 1;
                      local_208 = 0x24;
                      local_238 = 0x5c;
                      local_1f8 = DVar2;
                      local_1f4 = DVar11;
                      DVar5 = FUN_c048d228(6,0,&local_1f8,&local_208,auStack_170,&local_238);
                      if ((DVar5 != 0) || (local_238 != 0x5c)) goto LAB_c048ddac;
                      local_248 = local_118 * 0x34;
                    }
                    if (local_248 <= DVar14) {
                      bVar1 = false;
                    }
                  } while (bVar1);
                  uVar15 = local_248 / 0x34;
                  uVar18 = 0;
                  piVar12 = piVar3;
                  if (uVar15 != 0) {
                    do {
                      piVar6 = piVar13;
                      if (*piVar12 == 0) {
                        for (; piVar6 != (int *)0x0; piVar6 = (int *)*piVar6) {
                          if ((piVar6[0x67] == piVar12[1]) &&
                             (iVar7 = FUN_c048d394(piVar6 + 0x75,piVar12[6],0,0), iVar7 == 0))
                          goto LAB_c048ddac;
                        }
                      }
                      uVar18 = uVar18 + 1;
                      piVar12 = piVar12 + 0xd;
                    } while (uVar18 < uVar15);
                  }
                  LocalFree(piVar3);
                  uVar18 = local_234;
                }
              }
            }
          }
LAB_c048dd40:
          local_234 = uVar18 + 1;
          piVar3 = local_200;
          pDVar16 = pDVar16 + 2;
        } while (local_234 < local_240);
      }
      LocalFree(hMem);
      LocalFree(local_20c);
      piVar12 = piVar13;
      if ((*lpMem != 0) &&
         (piVar9 = (int *)0x0, piVar6 = piVar13, piVar12 = piVar3, piVar13 != (int *)0x0)) {
        do {
          if (piVar6[0x69] == 0x91) {
            if (piVar9 == (int *)0x0) {
              piVar9 = (int *)*piVar6;
              piVar13 = piVar9;
            }
            else {
              *piVar9 = *piVar6;
            }
            piVar3 = (int *)*piVar6;
            *piVar6 = (int)piVar12;
            piVar6[0x69] = 0;
            piVar12 = piVar6;
          }
          else {
            piVar3 = (int *)*piVar6;
            piVar9 = piVar6;
          }
          piVar6 = piVar3;
        } while (piVar3 != (int *)0x0);
        if (piVar9 != (int *)0x0) {
          *piVar9 = (int)piVar12;
          piVar12 = piVar13;
        }
      }
      pvVar4 = GetProcessHeap();
      HeapFree(pvVar4,0,lpMem);
      FUN_c048e238(local_2c);
      return piVar12;
    }
  }
LAB_c048ddb4:
  LocalFree(hMem);
  LocalFree(local_20c);
  if (lpMem != (uint *)0x0) {
    pvVar4 = GetProcessHeap();
    HeapFree(pvVar4,0,lpMem);
  }
  FUN_c04886d4(piVar13);
LAB_c048ddec:
  FUN_c048e238(local_2c);
  return (int *)0x0;
  while (uVar10 = uVar10 + 1, uVar10 < *lpMem) {
LAB_c048dafc:
    puVar8 = puVar8 + 1;
    if (puVar17[-1] == *puVar8) {
      piVar12[0x69] = 0x91;
      break;
    }
  }
LAB_c048db28:
  uVar15 = uVar15 + 1;
  puVar17 = puVar17 + 6;
  if (uVar18 <= uVar15) goto LAB_c048db38;
  goto LAB_c048da9c;
LAB_c048ddac:
  LocalFree(piVar3);
  goto LAB_c048ddb4;
}



/* c048dea0 FUN_c048dea0 */

/* WARNING: Type propagation algorithm not settling */
/* Boundary evidence: original MIPS .pdata c048dea0..c048df8f. Semantic name remains unreviewed. */

HLOCAL FUN_c048dea0(uint *param_1)

{
  DWORD DVar1;
  SIZE_T SVar2;
  HLOCAL hMem;
  SIZE_T local_40;
  DWORD local_3c [11];
  
  hMem = (HLOCAL)0x0;
  memset(local_3c + 1,0,0x24);
  SVar2 = 0x100;
  local_3c[1] = 0;
  local_3c[2] = 0;
  local_3c[3] = 0x100;
  local_3c[4] = 0x100;
  local_3c[5] = 0;
  local_3c[0] = 0x24;
  while( true ) {
    local_40 = SVar2;
    if (hMem != (HLOCAL)0x0) {
      LocalFree(hMem);
    }
    hMem = LocalAlloc(0,local_40);
    if (hMem == (HLOCAL)0x0) {
      return (HLOCAL)0x0;
    }
    DVar1 = FUN_c048d228(6,0,local_3c + 1,local_3c,hMem,&local_40);
    if (DVar1 == 0) {
      *param_1 = local_40 >> 3;
      return hMem;
    }
    if (DVar1 != 0x7a) break;
    SVar2 = SVar2 + 0x100;
  }
  LocalFree(hMem);
  return (HLOCAL)0x0;
}



/* c048e0d0 entry */

/* Boundary evidence: original MIPS .pdata c048e0d0..c048e143. Semantic name remains unreviewed. */

undefined4 entry(HMODULE param_1,int param_2)

{
  undefined4 uVar1;
  
  if (param_2 == 1) {
    FUN_c048e144();
    FUN_c048e418();
  }
  uVar1 = FUN_c048c43c(param_1,param_2);
  if (param_2 == 0) {
    FUN_c048e3a0();
  }
  return uVar1;
}



/* c048e144 FUN_c048e144 */

/* Boundary evidence: original MIPS .pdata c048e144..c048e1b7. Semantic name remains unreviewed. */

void FUN_c048e144(void)

{
  uint uVar1;
  
  if ((DAT_c048f418 == 0) || (DAT_c048f418 == 0xb064)) {
    uVar1 = __security_gen_cookie2();
    DAT_c048f418 = uVar1 >> 0x10 ^ uVar1 & 0xffff;
    if (DAT_c048f418 == 0) {
      DAT_c048f418 = 0xb064;
    }
  }
  DAT_c048f41c = ~DAT_c048f418;
  return;
}



/* c048e1b8 FUN_c048e1b8 */

/* Boundary evidence: original MIPS .pdata c048e1b8..c048e20b. Semantic name remains unreviewed. */

void FUN_c048e1b8(int param_1,undefined4 param_2,uint *param_3)

{
  if ((*param_3 & 1) != 0) {
    param_1 = ((-param_3[2] & param_3[1] + param_1) - (param_3[1] + param_1)) + param_1;
  }
  FUN_c048e238(*(uint *)(param_1 + (*param_3 & 0xfffffffc)));
  return;
}



/* c048e20c FUN_c048e20c */

/* Boundary evidence: original MIPS .pdata c048e20c..c048e237. Semantic name remains unreviewed. */

undefined4 FUN_c048e20c(undefined4 param_1,int param_2,undefined4 param_3,int param_4)

{
  FUN_c048e1b8(param_2,param_4,*(uint **)(*(int *)(param_4 + 4) + 0xc));
  return 1;
}



/* c048e238 FUN_c048e238 */

/* Boundary evidence: original MIPS .pdata c048e238..c048e27f. Semantic name remains unreviewed. */

void FUN_c048e238(uint param_1)

{
  if ((param_1 == DAT_c048f418) && (param_1 >> 0x10 == 0)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __report_gsfailure();
}



/* c048e280 FUN_c048e280 */

/* Boundary evidence: original MIPS .pdata c048e280..c048e39f. Semantic name remains unreviewed. */

void FUN_c048e280(UINT param_1,int param_2,int param_3)

{
  LPCRITICAL_SECTION lpCriticalSection;
  undefined4 *_Memory;
  
  DAT_c048f434 = (undefined1)param_3;
  if (param_2 == 0) {
    _Memory = DAT_c048f63c;
    if (DAT_c048f63c != (undefined4 *)0x0) {
      while (DAT_c048f638 = DAT_c048f638 + -1, _Memory <= DAT_c048f638) {
        if ((code *)*DAT_c048f638 != (code *)0x0) {
          (*(code *)*DAT_c048f638)();
          _Memory = DAT_c048f63c;
        }
      }
      free(_Memory);
      DAT_c048f638 = (undefined4 *)0x0;
      DAT_c048f63c = (undefined4 *)0x0;
    }
    FUN_c048e3c4((undefined4 *)&DAT_c0481010,(undefined4 *)&DAT_c0481014);
  }
  FUN_c048e3c4((undefined4 *)&DAT_c0481018,(undefined4 *)&DAT_c048101c);
  if (param_3 == 0) {
    TerminateProcess((HANDLE)0x42,param_1);
  }
  else {
    lpCriticalSection = (LPCRITICAL_SECTION)InterlockedExchange((LONG *)&DAT_c048f640,0);
    if (lpCriticalSection != (LPCRITICAL_SECTION)0x0) {
      DeleteCriticalSection(lpCriticalSection);
      free(lpCriticalSection);
    }
  }
  return;
}



/* c048e3a0 FUN_c048e3a0 */

/* Boundary evidence: original MIPS .pdata c048e3a0..c048e3c3. Semantic name remains unreviewed. */

void FUN_c048e3a0(void)

{
  FUN_c048e280(0,0,1);
  return;
}



/* c048e3c4 FUN_c048e3c4 */

/* Boundary evidence: original MIPS .pdata c048e3c4..c048e417. Semantic name remains unreviewed. */

void FUN_c048e3c4(undefined4 *param_1,undefined4 *param_2)

{
  for (; param_1 < param_2; param_1 = param_1 + 1) {
    if ((code *)*param_1 != (code *)0x0) {
      (*(code *)*param_1)();
    }
  }
  return;
}



/* c048e418 FUN_c048e418 */

/* Boundary evidence: original MIPS .pdata c048e418..c048e453. Semantic name remains unreviewed. */

void FUN_c048e418(void)

{
  FUN_c048e3c4((undefined4 *)&DAT_c0481008,(undefined4 *)&DAT_c048100c);
  FUN_c048e3c4((undefined4 *)&DAT_c0481000,(undefined4 *)&DAT_c0481004);
  return;
}


