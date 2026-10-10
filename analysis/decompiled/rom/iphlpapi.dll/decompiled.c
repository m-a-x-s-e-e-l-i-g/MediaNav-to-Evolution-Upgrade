/* Automatic Ghidra pseudocode. Not original source; not runtime-verified. */

/* 40261504 FUN_40261504 */

/* Boundary evidence: original MIPS .pdata 40261504..40261547. Semantic name remains unreviewed. */

DWORD FUN_40261504(int param_1)

{
  int iVar1;
  DWORD DVar2;
  
  iVar1 = FUN_4026c620();
  if ((iVar1 != 0) || (DVar2 = FUN_40264914((undefined2 *)(param_1 + 8),0), DVar2 == 0)) {
    DVar2 = 0;
  }
  return DVar2;
}



/* 40261548 FUN_40261548 */

/* Boundary evidence: original MIPS .pdata 40261548..40261597. Semantic name remains unreviewed. */

int FUN_40261548(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_4026c620();
  if (((iVar1 != 0) && (iVar1 = FUN_4026c620(), iVar1 != 0)) ||
     (iVar1 = FUN_40264d2c((undefined4 *)(param_1 + 8)), iVar1 == 0)) {
    iVar1 = 0;
  }
  return iVar1;
}



/* 40261598 FUN_40261598 */

/* Boundary evidence: original MIPS .pdata 40261598..402615e7. Semantic name remains unreviewed. */

int FUN_40261598(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_4026c620();
  if (((iVar1 != 0) && (iVar1 = FUN_4026c620(), iVar1 != 0)) ||
     (iVar1 = FUN_40264d2c((undefined4 *)(param_1 + 8)), iVar1 == 0)) {
    iVar1 = 0;
  }
  return iVar1;
}



/* 402615e8 FUN_402615e8 */

/* Boundary evidence: original MIPS .pdata 402615e8..4026163f. Semantic name remains unreviewed. */

int FUN_402615e8(int param_1)

{
  int iVar1;
  
  *(undefined4 *)(param_1 + 0x1c) = 2;
  iVar1 = FUN_4026c620();
  if (((iVar1 != 0) && (iVar1 = FUN_4026c620(), iVar1 != 0)) ||
     (iVar1 = FUN_40264d2c((undefined4 *)(param_1 + 8)), iVar1 == 0)) {
    iVar1 = 0;
  }
  return iVar1;
}



/* 40261640 FUN_40261640 */

/* Boundary evidence: original MIPS .pdata 40261640..4026167f. Semantic name remains unreviewed. */

int FUN_40261640(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_4026c620();
  if ((iVar1 != 0) || (iVar1 = FUN_40263750((void *)(param_1 + 8)), iVar1 == 0)) {
    iVar1 = 0;
  }
  return iVar1;
}



/* 40261680 FUN_40261680 */

/* Boundary evidence: original MIPS .pdata 40261680..402616c3. Semantic name remains unreviewed. */

int FUN_40261680(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_4026c620();
  if ((iVar1 != 0) || (iVar1 = FUN_40263bec((uint *)(param_1 + 8),0), iVar1 == 0)) {
    iVar1 = 0;
  }
  return iVar1;
}



/* 402616c4 FUN_402616c4 */

/* Boundary evidence: original MIPS .pdata 402616c4..40261707. Semantic name remains unreviewed. */

int FUN_402616c4(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_4026c620();
  if ((iVar1 != 0) || (iVar1 = FUN_40263bec((uint *)(param_1 + 8),0), iVar1 == 0)) {
    iVar1 = 0;
  }
  return iVar1;
}



/* 40261708 FUN_40261708 */

/* Boundary evidence: original MIPS .pdata 40261708..40261753. Semantic name remains unreviewed. */

int FUN_40261708(int param_1)

{
  int iVar1;
  
  *(undefined4 *)(param_1 + 0x1c) = 2;
  iVar1 = FUN_4026c620();
  if ((iVar1 != 0) || (iVar1 = FUN_40263bec((uint *)(param_1 + 8),0), iVar1 == 0)) {
    iVar1 = 0;
  }
  return iVar1;
}



/* 40261754 FUN_40261754 */

/* Boundary evidence: original MIPS .pdata 40261754..4026176f. Semantic name remains unreviewed. */

void FUN_40261754(int param_1)

{
  FUN_4026319c((void *)(param_1 + 8));
  return;
}



/* 40261770 GetInterfaceInfo */

/* Boundary evidence: original MIPS .pdata 40261770..40261867. Semantic name remains unreviewed. */

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
    DVar2 = FUN_402636b0(auStack_70);
    if (DVar2 == 0) {
      if (local_20 == 0) {
        DVar2 = 0xe8;
      }
      else if ((param_1 == (LPVOID)0x0) || (*param_2 < (uint)(local_20 * 0x104))) {
        DVar2 = 0x7a;
        *param_2 = (local_20 + 10) * 0x104;
      }
      else {
        DVar2 = FUN_40262aa8(DAT_4026f5b4,0x120040,(LPVOID)0x0,local_78,param_1,param_2);
      }
    }
  }
  else {
    DVar2 = 0x57;
  }
  return DVar2;
}



/* 40261868 GetUniDirectionalAdapterInfo */

/* Boundary evidence: original MIPS .pdata 40261868..402618af. Semantic name remains unreviewed. */

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
    DVar1 = FUN_40262aa8(DAT_4026f5b4,0x120094,(LPVOID)0x0,local_10,param_1,param_2);
  }
  return DVar1;
}



/* 402618b0 FUN_402618b0 */

/* Boundary evidence: original MIPS .pdata 402618b0..402619c7. Semantic name remains unreviewed. */

DWORD FUN_402618b0(undefined4 param_1,LPVOID param_2,LPDWORD param_3)

{
  DWORD DVar1;
  BOOL BVar2;
  undefined4 local_res0 [4];
  DWORD local_20 [2];
  
  local_20[0] = 4;
  if ((param_3 == (LPDWORD)0x0) ||
     (local_res0[0] = param_1, BVar2 = IsBadWritePtr(param_3,4), BVar2 != 0)) {
LAB_402618e0:
    DVar1 = 0x57;
  }
  else {
    if (param_2 == (LPVOID)0x0) {
      local_20[1] = 4;
      DVar1 = FUN_40262aa8(DAT_4026f5b4,0x120054,local_res0,local_20,param_3,local_20 + 1);
    }
    else {
      BVar2 = IsBadWritePtr(param_2,*param_3);
      if ((BVar2 != 0) || (*param_3 < 5)) goto LAB_402618e0;
      DVar1 = FUN_40262aa8(DAT_4026f5b4,0x120054,local_res0,local_20,param_2,param_3);
    }
    if ((DVar1 == 0xea) || (DVar1 == 0x80000005)) {
      DVar1 = 0x7a;
    }
  }
  return DVar1;
}



/* 402619c8 GetAdapterIndex */

/* Boundary evidence: original MIPS .pdata 402619c8..40261b47. Semantic name remains unreviewed. */

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
        lpMem = HeapAlloc(DAT_4026f5d4,0,local_2c);
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
              HeapFree(DAT_4026f5d4,0,lpMem);
              return 0x37;
            }
            DVar1 = 0;
            *param_2 = lpMem[iVar3 * 0x41 + 1];
          }
          HeapFree(DAT_4026f5d4,0,lpMem);
        }
      }
    }
  }
  return DVar1;
}



/* 40261b48 AddIPAddress */

/* Boundary evidence: original MIPS .pdata 40261b48..40261d63. Semantic name remains unreviewed. */

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
  local_28 = DAT_4026f418;
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
        FUN_40265020();
        DVar4 = FUN_40262aa8(DAT_4026f5a8,0x12801c,&local_40,local_48,&local_40,local_48 + 1);
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
        FUN_4026e238(local_28);
        return DVar4;
      }
    }
  }
  FUN_4026e238(local_28);
  return 0x57;
}



/* 40261d64 DeleteIPAddress */

/* Boundary evidence: original MIPS .pdata 40261d64..40261dc7. Semantic name remains unreviewed. */

DWORD DeleteIPAddress(undefined2 param_1)

{
  DWORD DVar1;
  undefined2 local_18 [2];
  DWORD local_14 [3];
  
                    /* 0x1d64  7  DeleteIPAddress */
  local_14[1] = 2;
  local_14[0] = 0;
  local_18[0] = param_1;
  FUN_40265020();
  DVar1 = FUN_40262aa8(DAT_4026f5a8,0x128020,local_18,local_14 + 1,(LPVOID)0x0,local_14);
  if (DVar1 == 0xc00000c0) {
    DVar1 = 0x37;
  }
  return DVar1;
}



/* 40261dc8 FUN_40261dc8 */

/* Boundary evidence: original MIPS .pdata 40261dc8..40261f97. Semantic name remains unreviewed. */

undefined4 FUN_40261dc8(IPAddr param_1,undefined4 *param_2)

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
  
  local_28 = DAT_4026f418;
  IcmpHandle_00 = param_2;
  BVar1 = IsBadWritePtr(param_2,4);
  if (BVar1 != 0) {
    FUN_4026e238(local_28);
    return 0x57;
  }
  IcmpHandle = (HANDLE)Icmp6CreateFile(IcmpHandle_00);
  if (IcmpHandle == (HANDLE)0xffffffff) {
    FUN_4026e238(local_28);
    return 0;
  }
  ReplyBuffer = HeapAlloc(DAT_4026f5d4,0,0x1000);
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
      HeapFree(DAT_4026f5d4,0,ReplyBuffer);
      uVar5 = 1;
      goto LAB_40261f5c;
    }
    HeapFree(DAT_4026f5d4,0,ReplyBuffer);
  }
  uVar5 = 0;
LAB_40261f5c:
  Icmp6CreateFile(IcmpHandle);
  FUN_4026e238(local_28);
  return uVar5;
}



/* 40261f98 GetRTTAndHopCount */

/* Boundary evidence: original MIPS .pdata 40261f98..402621eb. Semantic name remains unreviewed. */

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
  local_30 = DAT_4026f418;
  if (((((param_2 != (uint *)0x0) && (param_4 != (undefined4 *)0x0)) && (param_1 != 0xffffffff)) &&
      ((BVar1 = IsBadWritePtr(param_4,4), BVar1 == 0 &&
       (IcmpHandle_00 = param_2, BVar1 = IsBadWritePtr(param_2,4), BVar1 == 0)))) &&
     (IcmpHandle = (HANDLE)Icmp6CreateFile(IcmpHandle_00), IcmpHandle != (HANDLE)0xffffffff)) {
    ReplyBuffer = HeapAlloc(DAT_4026f5d4,0,0x1000);
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
            HeapFree(DAT_4026f5d4,0,ReplyBuffer);
            Icmp6CreateFile(IcmpHandle);
            iVar3 = FUN_40261dc8(param_1,local_58);
            if (iVar3 != 0) {
              *param_4 = local_58[0];
              FUN_4026e238(local_30);
              return 1;
            }
            goto LAB_40262160;
          }
        } while (((DVar2 == 0x2b05) || (DVar2 == 0x2b02)) &&
                (local_60.Ttl = local_60.Ttl + 1, local_60.Ttl <= param_3));
      }
      HeapFree(DAT_4026f5d4,0,ReplyBuffer);
    }
    Icmp6CreateFile(IcmpHandle);
  }
LAB_40262160:
  FUN_4026e238(local_30);
  return 0;
}



/* 402621ec IsLocalAddress */

/* Boundary evidence: original MIPS .pdata 402621ec..402622ab. Semantic name remains unreviewed. */

DWORD IsLocalAddress(int param_1)

{
  DWORD DVar1;
  int *piVar2;
  int iVar3;
  int *local_18 [2];
  
                    /* 0x21ec  52  IsLocalAddress */
  DVar1 = AllocateAndGetIpAddrTableFromStack(local_18,0,DAT_4026f5d4,0);
  if (DVar1 == 0) {
    if (param_1 == 0x100007f) {
      HeapFree(DAT_4026f5d4,0,local_18[0]);
      DVar1 = 0;
    }
    else {
      iVar3 = 0;
      if (0 < *local_18[0]) {
        piVar2 = local_18[0] + 1;
        do {
          if (*piVar2 == param_1) {
            DVar1 = 0;
            goto LAB_4026227c;
          }
          iVar3 = iVar3 + 1;
          piVar2 = piVar2 + 6;
        } while (iVar3 < *local_18[0]);
      }
      DVar1 = 0x1e7;
LAB_4026227c:
      HeapFree(DAT_4026f5d4,0,local_18[0]);
    }
  }
  return DVar1;
}



/* 402622ac FUN_402622ac */

/* Boundary evidence: original MIPS .pdata 402622ac..4026237b. Semantic name remains unreviewed. */

undefined4 FUN_402622ac(undefined4 *param_1,int param_2,LPCWSTR param_3)

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



/* 4026237c NotifyAddrChange */

/* Boundary evidence: original MIPS .pdata 4026237c..4026239b. Semantic name remains unreviewed. */

void NotifyAddrChange(undefined4 *param_1,int param_2)

{
                    /* 0x237c  53  NotifyAddrChange */
  FUN_402622ac(param_1,param_2,L"IP_ADDR_CHANGE_EVENT");
  return;
}



/* 4026239c EnableRouter */

undefined4 EnableRouter(void)

{
                    /* 0x239c  11  EnableRouter
                       0x239c  62  UnenableRouter */
  return 0x32;
}



/* 402623a4 GetNetworkParams */

/* Boundary evidence: original MIPS .pdata 402623a4..40262447. Semantic name remains unreviewed. */

undefined4 GetNetworkParams(void *param_1,uint *param_2)

{
  BOOL BVar1;
  undefined4 uVar2;
  
                    /* 0x23a4  31  GetNetworkParams */
  FUN_40265020();
  BVar1 = IsBadReadPtr(param_2,4);
  if (((BVar1 == 0) && (BVar1 = IsBadWritePtr(param_2,4), BVar1 == 0)) &&
     ((param_1 == (void *)0x0 || (BVar1 = IsBadWritePtr(param_1,0x248), BVar1 == 0)))) {
    uVar2 = FUN_4026ba7c(param_1,param_2);
  }
  else {
    uVar2 = 0x57;
  }
  return uVar2;
}



/* 40262448 GetAdaptersInfo */

/* Boundary evidence: original MIPS .pdata 40262448..402624eb. Semantic name remains unreviewed. */

undefined4 GetAdaptersInfo(undefined4 *param_1,uint *param_2)

{
  BOOL BVar1;
  undefined4 uVar2;
  
                    /* 0x2448  16  GetAdaptersInfo */
  FUN_40265020();
  BVar1 = IsBadReadPtr(param_2,4);
  if (((BVar1 == 0) && (BVar1 = IsBadWritePtr(param_2,4), BVar1 == 0)) &&
     ((param_1 == (undefined4 *)0x0 || (BVar1 = IsBadWritePtr(param_1,0x280), BVar1 == 0)))) {
    uVar2 = FUN_4026aec8(param_1,param_2);
  }
  else {
    uVar2 = 0x57;
  }
  return uVar2;
}



/* 402624ec GetPerAdapterInfo */

/* Boundary evidence: original MIPS .pdata 402624ec..4026259f. Semantic name remains unreviewed. */

undefined4 GetPerAdapterInfo(int param_1,void *param_2,uint *param_3)

{
  BOOL BVar1;
  undefined4 uVar2;
  
                    /* 0x24ec  33  GetPerAdapterInfo */
  FUN_40265020();
  BVar1 = IsBadReadPtr(param_3,4);
  if (((BVar1 == 0) && (BVar1 = IsBadWritePtr(param_3,4), BVar1 == 0)) &&
     ((param_2 == (void *)0x0 || (BVar1 = IsBadWritePtr(param_2,0x34), BVar1 == 0)))) {
    uVar2 = FUN_4026b6d0(param_1,param_2,param_3);
  }
  else {
    uVar2 = 0x57;
  }
  return uVar2;
}



/* 402625a0 IpReleaseAddress */

/* Boundary evidence: original MIPS .pdata 402625a0..4026262f. Semantic name remains unreviewed. */

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
    FUN_40265020();
    local_18[1] = 0x104;
    local_18[0] = 0;
    DVar1 = FUN_40262aa8(DAT_4026f5a8,0x128080,param_1,local_18 + 1,(LPVOID)0x0,local_18);
  }
  return DVar1;
}



/* 40262630 IpRenewAddress */

/* Boundary evidence: original MIPS .pdata 40262630..402626bf. Semantic name remains unreviewed. */

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
    FUN_40265020();
    local_18[1] = 0x104;
    local_18[0] = 0;
    DVar1 = FUN_40262aa8(DAT_4026f5a8,0x12807c,param_1,local_18 + 1,(LPVOID)0x0,local_18);
  }
  return DVar1;
}



/* 402626c0 SendARP */

/* Boundary evidence: original MIPS .pdata 402626c0..4026276b. Semantic name remains unreviewed. */

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
    FUN_40265020();
    DVar2 = FUN_40262aa8(DAT_4026f5b4,0x12003c,&local_18,local_20,param_3,param_4);
  }
  else {
    DVar2 = 0x57;
  }
  return DVar2;
}



/* 4026276c FUN_4026276c */

/* Boundary evidence: original MIPS .pdata 4026276c..402627c3. Semantic name remains unreviewed. */

bool FUN_4026276c(void)

{
  int iVar1;
  WSADATA WStack_1a0;
  uint local_10;
  
  local_10 = DAT_4026f418;
  iVar1 = WSAStartup(0x101,&WStack_1a0);
  if (iVar1 == 0) {
    FUN_4026e238(local_10);
  }
  else {
    FUN_4026e238(local_10);
  }
  return iVar1 == 0;
}



/* 402627c4 NotifyRouteChange */

/* Boundary evidence: original MIPS .pdata 402627c4..402627e3. Semantic name remains unreviewed. */

void NotifyRouteChange(undefined4 *param_1,int param_2)

{
                    /* 0x27c4  54  NotifyRouteChange */
  FUN_402622ac(param_1,param_2,L"IP_ROUTE_CHANGE_EVENT");
  return;
}



/* 402627e4 GetAdaptersAddresses */

/* Boundary evidence: original MIPS .pdata 402627e4..4026294b. Semantic name remains unreviewed. */

DWORD GetAdaptersAddresses(int param_1,uint param_2,int param_3,void *param_4,uint *param_5)

{
  bool bVar1;
  BOOL BVar2;
  undefined3 extraout_var;
  DWORD DVar3;
  int iVar4;
  
                    /* 0x27e4  15  GetAdaptersAddresses */
  FUN_40265020();
  BVar2 = IsBadReadPtr(param_5,4);
  if ((((BVar2 == 0) && (BVar2 = IsBadWritePtr(param_5,4), BVar2 == 0)) && (param_3 == 0)) &&
     ((param_4 == (void *)0x0 || (BVar2 = IsBadWritePtr(param_4,0x98), BVar2 == 0)))) {
    bVar1 = FUN_4026276c();
    if (CONCAT31(extraout_var,bVar1) == 0) {
      DVar3 = 0x32;
    }
    else {
      iVar4 = 0;
      do {
        DVar3 = FUN_4026b17c(param_1,param_2,param_4,param_5);
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



/* 4026294c FUN_4026294c */

undefined4 FUN_4026294c(int param_1)

{
  undefined4 uVar1;
  
  if (param_1 == 9) {
LAB_402629a0:
    uVar1 = 0x7a;
  }
  else {
    if (param_1 != 0x1f) {
      if (param_1 == 0x21) goto LAB_402629a0;
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



/* 402629ac FUN_402629ac */

/* Boundary evidence: original MIPS .pdata 402629ac..40262aa7. Semantic name remains unreviewed. */

DWORD FUN_402629ac(int param_1,LPVOID param_2,DWORD *param_3,LPVOID param_4,LPDWORD param_5)

{
  BOOL BVar1;
  DWORD DVar2;
  int iVar3;
  
  if (param_1 == 2) {
    iVar3 = WSAControl(6,0,param_2,param_3,param_4,param_5);
    if (iVar3 != 0) {
      DVar2 = FUN_4026294c(iVar3);
      return DVar2;
    }
  }
  else {
    if (param_1 != 0x17) {
      return 0x32;
    }
    FUN_40265020();
    BVar1 = DeviceIoControl(DAT_4026f598,0x120003,param_2,*param_3,param_4,*param_5,param_5,
                            (LPOVERLAPPED)0x0);
    if (BVar1 == 0) {
      DVar2 = GetLastError();
      *param_5 = 0;
      return DVar2;
    }
  }
  return 0;
}



/* 40262aa8 FUN_40262aa8 */

/* Boundary evidence: original MIPS .pdata 40262aa8..40262b0b. Semantic name remains unreviewed. */

DWORD FUN_40262aa8(HANDLE param_1,DWORD param_2,LPVOID param_3,DWORD *param_4,LPVOID param_5,
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



/* 40262b0c FUN_40262b0c */

/* Boundary evidence: original MIPS .pdata 40262b0c..40262be7. Semantic name remains unreviewed. */

DWORD FUN_40262b0c(int param_1)

{
  HANDLE pvVar1;
  wchar_t *lpFileName;
  DWORD DVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  
  DVar2 = 0;
  if (param_1 == 2) {
    lpFileName = L"IPD0:";
    puVar3 = &DAT_4026f5a8;
    puVar4 = &DAT_4026f5b4;
  }
  else {
    if (param_1 != 0x17) {
      return 0x57;
    }
    lpFileName = L"IP60:";
    puVar3 = &DAT_4026f5a0;
    puVar4 = &DAT_4026f598;
  }
  pvVar1 = CreateFileW(lpFileName,0xc0000000,3,(LPSECURITY_ATTRIBUTES)0x0,3,0x80,(HANDLE)0x0);
  *puVar3 = pvVar1;
  if (pvVar1 == (HANDLE)0xffffffff) {
    DVar2 = GetLastError();
  }
  *puVar4 = *puVar3;
  return DVar2;
}



/* 40262be8 FUN_40262be8 */

/* Boundary evidence: original MIPS .pdata 40262be8..40262d47. Semantic name remains unreviewed. */

DWORD FUN_40262be8(uint param_1,uint param_2,undefined4 *param_3)

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
  
  local_18 = DAT_4026f418;
  local_90[0] = 0x33;
  FUN_40265020();
  if (DAT_4026f5a4 == 0) {
    FUN_4026e238(local_18);
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
    DVar3 = FUN_402629ac(2,&local_50,local_90,local_90 + 2,local_90 + 1);
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
    FUN_4026e238(local_18);
  }
  return DVar3;
}



/* 40262d48 FUN_40262d48 */

/* Boundary evidence: original MIPS .pdata 40262d48..40262e27. Semantic name remains unreviewed. */

LPVOID FUN_40262d48(uint *param_1)

{
  LPVOID lpMem;
  DWORD DVar1;
  DWORD local_40 [7];
  undefined1 auStack_24 [20];
  
  *param_1 = 0;
  local_40[1] = 0x24;
  local_40[0] = 0x1000;
  lpMem = HeapAlloc(DAT_4026f5d4,0,0x1000);
  if (lpMem != (LPVOID)0x0) {
    local_40[2] = 0;
    local_40[3] = 0;
    local_40[4] = 0x100;
    local_40[5] = 0x100;
    local_40[6] = 0;
    memset(auStack_24,0,0x10);
    DVar1 = FUN_402629ac(2,local_40 + 2,local_40 + 1,lpMem,local_40);
    if (DVar1 == 0) {
      *param_1 = local_40[0] >> 3;
      return lpMem;
    }
    HeapFree(DAT_4026f5d4,0,lpMem);
  }
  return (LPVOID)0x0;
}



/* 40262e28 FUN_40262e28 */

/* WARNING: Type propagation algorithm not settling */
/* Boundary evidence: original MIPS .pdata 40262e28..40262fab. Semantic name remains unreviewed. */

DWORD FUN_40262e28(int param_1,undefined4 param_2,undefined2 *param_3)

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
    DVar2 = FUN_402629ac(2,local_48 + 2,local_48 + 1,param_3 + 0x100,local_48);
  }
  else if (param_1 == 1) {
    local_48[1] = 0x7b;
    lpMem = HeapAlloc(DAT_4026f5d4,0,0x7b);
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
        DVar2 = FUN_4026294c(iVar1);
      }
      HeapFree(DAT_4026f5d4,0,lpMem);
    }
  }
  else {
    DVar2 = 0x57;
  }
  return DVar2;
}



/* 40262fac FUN_40262fac */

/* WARNING: Type propagation algorithm not settling */
/* Boundary evidence: original MIPS .pdata 40262fac..402630a3. Semantic name remains unreviewed. */

DWORD FUN_40262fac(uint *param_1,int param_2,int param_3)

{
  DWORD DVar1;
  uint _NumOfElements;
  uint local_40;
  DWORD local_3c [6];
  undefined1 auStack_24 [20];
  
  FUN_40265020();
  if (DAT_4026f5a4 == 0) {
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
    DVar1 = FUN_402629ac(2,local_3c + 1,local_3c,param_1 + 1,&local_40);
    if (DVar1 == 0) {
      _NumOfElements = local_40 / 0x18;
      *param_1 = _NumOfElements;
      if ((_NumOfElements != 0) && (param_3 != 0)) {
        qsort(param_1 + 1,_NumOfElements,0x18,(_PtFuncCompare *)&LAB_4026c65c);
      }
      DVar1 = 0;
    }
  }
  return DVar1;
}



/* 402630a4 FUN_402630a4 */

/* WARNING: Type propagation algorithm not settling */
/* Boundary evidence: original MIPS .pdata 402630a4..4026319b. Semantic name remains unreviewed. */

DWORD FUN_402630a4(uint *param_1,int param_2,int param_3)

{
  DWORD DVar1;
  uint _NumOfElements;
  uint local_40;
  DWORD local_3c [6];
  undefined1 auStack_24 [20];
  
  FUN_40265020();
  if (DAT_4026f5a4 == 0) {
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
    DVar1 = FUN_402629ac(2,local_3c + 1,local_3c,param_1 + 1,&local_40);
    if (DVar1 == 0) {
      _NumOfElements = local_40 / 0x14;
      *param_1 = _NumOfElements;
      if ((_NumOfElements != 0) && (param_3 != 0)) {
        qsort(param_1 + 1,_NumOfElements,0x14,FUN_4026c6c0);
      }
      DVar1 = 0;
    }
  }
  return DVar1;
}



/* 4026319c FUN_4026319c */

/* Boundary evidence: original MIPS .pdata 4026319c..40263297. Semantic name remains unreviewed. */

undefined4 FUN_4026319c(void *param_1)

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
  
  local_14 = DAT_4026f418;
  local_50 = 0x2f;
  FUN_40265020();
  if (DAT_4026f5a4 == 0) {
    FUN_4026e238(local_14);
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
      uVar4 = FUN_4026294c(iVar3);
    }
    FUN_4026e238(local_14);
  }
  return uVar4;
}



/* 40263298 FUN_40263298 */

/* WARNING: Type propagation algorithm not settling */
/* Boundary evidence: original MIPS .pdata 40263298..40263387. Semantic name remains unreviewed. */

DWORD FUN_40263298(uint *param_1,int param_2,int param_3)

{
  DWORD DVar1;
  uint _NumOfElements;
  uint local_40;
  DWORD local_3c [6];
  undefined1 auStack_24 [20];
  
  FUN_40265020();
  if (DAT_4026f5a4 == 0) {
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
    DVar1 = FUN_402629ac(2,local_3c + 1,local_3c,param_1 + 1,&local_40);
    if (DVar1 == 0) {
      _NumOfElements = local_40 >> 3;
      *param_1 = _NumOfElements;
      if ((_NumOfElements != 0) && (param_3 != 0)) {
        qsort(param_1 + 1,_NumOfElements,8,FUN_4026c820);
      }
      DVar1 = 0;
    }
  }
  return DVar1;
}



/* 40263388 FUN_40263388 */

/* Boundary evidence: original MIPS .pdata 40263388..402635b7. Semantic name remains unreviewed. */

undefined4 FUN_40263388(size_t *param_1,int param_2,int param_3,int param_4)

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
  
  FUN_40265020();
  if (DAT_4026f5a4 == 0) {
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
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_4026f5c0);
    if ((((param_4 == 0) && (DAT_4026f5b8 != 0)) &&
        (DVar1 = GetTickCount(), DVar1 - DAT_4026f5b8 < 0xea61)) ||
       (DVar1 = FUN_4026cf1c(), DVar1 == 0)) {
      uVar3 = 0;
      if (DAT_4026f594 != 0) {
        iVar4 = 0;
        psVar5 = param_1 + 1;
        do {
          local_60 = local_5c - (int)psVar5;
          if (local_60 < 0x18) {
            uVar2 = 0xea;
            break;
          }
          local_4c = *(undefined4 *)(iVar4 + DAT_4026f5dc);
          memset(auStack_3c,0,0x10);
          DVar1 = FUN_402629ac(2,&local_50,local_58,psVar5,&local_60);
          if (DVar1 == 0) {
            psVar5 = (size_t *)(local_60 + (int)psVar5);
            _NumOfElements = local_60 / 0x18 + _NumOfElements;
          }
          else {
            uVar2 = 0xea;
          }
          uVar3 = uVar3 + 1;
          iVar4 = iVar4 + 4;
        } while (uVar3 < DAT_4026f594);
      }
      *param_1 = _NumOfElements;
      if ((_NumOfElements != 0) && (param_3 != 0)) {
        qsort(param_1 + 1,_NumOfElements,0x18,(_PtFuncCompare *)&LAB_4026c8e0);
      }
    }
    else {
      uVar2 = 0x3eb;
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_4026f5c0);
  }
  return uVar2;
}



/* 402635b8 FUN_402635b8 */

/* Boundary evidence: original MIPS .pdata 402635b8..402636af. Semantic name remains unreviewed. */

DWORD FUN_402635b8(LPVOID param_1,int param_2)

{
  DWORD DVar1;
  DWORD local_48 [7];
  undefined1 auStack_2c [20];
  
  if ((param_2 == 2) || (param_2 == 0x17)) {
    FUN_40265020();
    if (((param_2 == 2) && (DAT_4026f5a4 == 0)) || ((param_2 == 0x17 && (DAT_4026f5ac == 0)))) {
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
      DVar1 = FUN_402629ac(param_2,local_48 + 2,local_48 + 1,param_1,local_48);
    }
  }
  else {
    DVar1 = 0x57;
  }
  return DVar1;
}



/* 402636b0 FUN_402636b0 */

/* Boundary evidence: original MIPS .pdata 402636b0..4026374f. Semantic name remains unreviewed. */

DWORD FUN_402636b0(LPVOID param_1)

{
  DWORD DVar1;
  DWORD local_38 [7];
  undefined1 auStack_1c [20];
  
  FUN_40265020();
  if (DAT_4026f5a4 == 0) {
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
    DVar1 = FUN_402629ac(2,local_38 + 2,local_38 + 1,param_1,local_38);
  }
  return DVar1;
}



/* 40263750 FUN_40263750 */

/* Boundary evidence: original MIPS .pdata 40263750..4026384b. Semantic name remains unreviewed. */

undefined4 FUN_40263750(void *param_1)

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
  
  local_14 = DAT_4026f418;
  local_98 = 0x77;
  FUN_40265020();
  if (DAT_4026f5a4 == 0) {
    FUN_4026e238(local_14);
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
      uVar4 = FUN_4026294c(iVar3);
    }
    FUN_4026e238(local_14);
  }
  return uVar4;
}



/* 4026384c FUN_4026384c */

/* Boundary evidence: original MIPS .pdata 4026384c..4026395b. Semantic name remains unreviewed. */

DWORD FUN_4026384c(LPVOID param_1,int param_2)

{
  DWORD DVar1;
  DWORD local_48 [3];
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined1 auStack_2c [20];
  
  if ((param_2 == 2) || (param_2 == 0x17)) {
    FUN_40265020();
    if (((param_2 == 2) && (DAT_4026f5a4 == 0)) || ((param_2 == 0x17 && (DAT_4026f5ac == 0)))) {
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
      DVar1 = FUN_402629ac(param_2,local_48 + 2,local_48 + 1,param_1,local_48);
    }
  }
  else {
    DVar1 = 0x57;
  }
  return DVar1;
}



/* 4026395c FUN_4026395c */

/* Boundary evidence: original MIPS .pdata 4026395c..402639fb. Semantic name remains unreviewed. */

DWORD FUN_4026395c(LPVOID param_1)

{
  DWORD DVar1;
  DWORD local_38 [7];
  undefined1 auStack_1c [20];
  
  FUN_40265020();
  if (DAT_4026f5a4 == 0) {
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
    DVar1 = FUN_402629ac(2,local_38 + 2,local_38 + 1,param_1,local_38);
  }
  return DVar1;
}



/* 402639fc FUN_402639fc */

/* Boundary evidence: original MIPS .pdata 402639fc..40263af3. Semantic name remains unreviewed. */

DWORD FUN_402639fc(LPVOID param_1,int param_2)

{
  DWORD DVar1;
  DWORD local_48 [7];
  undefined1 auStack_2c [20];
  
  if ((param_2 == 2) || (param_2 == 0x17)) {
    FUN_40265020();
    if (((param_2 == 2) && (DAT_4026f5a4 == 0)) || ((param_2 == 0x17 && (DAT_4026f5ac == 0)))) {
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
      DVar1 = FUN_402629ac(param_2,local_48 + 2,local_48 + 1,param_1,local_48);
    }
  }
  else {
    DVar1 = 0x57;
  }
  return DVar1;
}



/* 40263af4 FUN_40263af4 */

/* Boundary evidence: original MIPS .pdata 40263af4..40263beb. Semantic name remains unreviewed. */

DWORD FUN_40263af4(LPVOID param_1,int param_2)

{
  DWORD DVar1;
  DWORD local_48 [7];
  undefined1 auStack_2c [20];
  
  if ((param_2 == 2) || (param_2 == 0x17)) {
    FUN_40265020();
    if (((param_2 == 2) && (DAT_4026f5a4 == 0)) || ((param_2 == 0x17 && (DAT_4026f5ac == 0)))) {
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
      DVar1 = FUN_402629ac(param_2,local_48 + 2,local_48 + 1,param_1,local_48);
    }
  }
  else {
    DVar1 = 0x57;
  }
  return DVar1;
}



/* 40263bec FUN_40263bec */

/* Boundary evidence: original MIPS .pdata 40263bec..40263dbb. Semantic name remains unreviewed. */

undefined4 FUN_40263bec(uint *param_1,int param_2)

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
  
  local_20 = DAT_4026f418;
  local_60 = 0x33;
  FUN_40265020();
  if (DAT_4026f5a4 == 0) {
    FUN_4026e238(local_20);
    uVar5 = 0x32;
  }
  else {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_4026f5c0);
    if ((((param_2 != 0) || (DAT_4026f5b8 == 0)) ||
        (DVar3 = GetTickCount(), 60000 < DVar3 - DAT_4026f5b8)) ||
       (iVar4 = FUN_4026ccf4(*param_1), iVar4 == -1)) {
      DVar3 = FUN_4026cf1c();
      if (DVar3 != 0) {
        LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_4026f5c0);
        FUN_4026e238(local_20);
        return 0x3eb;
      }
      iVar4 = FUN_4026ccf4(*param_1);
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_4026f5c0);
    if (iVar4 == -1) {
      FUN_4026e238(local_20);
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
        uVar5 = FUN_4026294c(iVar4);
      }
      FUN_4026e238(local_20);
    }
  }
  return uVar5;
}



/* 40263dbc FUN_40263dbc */

/* Boundary evidence: original MIPS .pdata 40263dbc..40263e23. Semantic name remains unreviewed. */

DWORD FUN_40263dbc(undefined4 param_1)

{
  DWORD DVar1;
  undefined4 local_res0 [4];
  DWORD local_10 [2];
  
  local_10[1] = 4;
  local_10[0] = 0;
  local_res0[0] = param_1;
  FUN_40265020();
  if (DAT_4026f5a4 == 0) {
    DVar1 = 0x32;
  }
  else {
    DVar1 = FUN_40262aa8(DAT_4026f5a8,0x128050,local_res0,local_10 + 1,(LPVOID)0x0,local_10);
  }
  return DVar1;
}



/* 40263e24 FUN_40263e24 */

/* Boundary evidence: original MIPS .pdata 40263e24..4026402b. Semantic name remains unreviewed. */

undefined4 FUN_40263e24(uint param_1,uint param_2,uint param_3,int param_4,int param_5)

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
  
  local_24 = DAT_4026f418;
  local_58 = 0x27;
  FUN_40265020();
  if (DAT_4026f5a4 == 0) {
    FUN_4026e238(local_24);
    uVar5 = 0x32;
  }
  else {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_4026f5c0);
    if ((((param_5 != 0) || (DAT_4026f5b8 == 0)) ||
        (DVar3 = GetTickCount(), 60000 < DVar3 - DAT_4026f5b8)) ||
       (local_4c = FUN_4026ccf4(param_3), local_4c == -1)) {
      DVar3 = FUN_4026cf1c();
      if (DVar3 != 0) {
        LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_4026f5c0);
        FUN_4026e238(local_24);
        return 0x3eb;
      }
      local_4c = FUN_4026ccf4(param_3);
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_4026f5c0);
    if (local_4c == -1) {
      FUN_4026e238(local_24);
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
        uVar5 = FUN_4026294c(iVar4);
      }
      FUN_4026e238(local_24);
    }
  }
  return uVar5;
}



/* 4026402c FUN_4026402c */

/* Boundary evidence: original MIPS .pdata 4026402c..4026419b. Semantic name remains unreviewed. */

DWORD FUN_4026402c(int *param_1)

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
  if (((DAT_4026f5b8 == 0) || (DVar1 = GetTickCount(), 60000 < DVar1 - DAT_4026f5b8)) &&
     (DVar1 = FUN_4026cf1c(), DVar1 != 0)) {
    DVar1 = 0x3eb;
  }
  else {
    uVar2 = 0;
    if (DAT_4026f594 != 0) {
      iVar3 = 0;
      do {
        local_40 = 0x200;
        local_38 = 1;
        local_44 = *(undefined4 *)(iVar3 + DAT_4026f5dc);
        local_58[0] = 8;
        memset(auStack_34,0,0x10);
        DVar1 = FUN_402629ac(2,&local_48,local_58 + 1,local_58 + 2,local_58);
        if (DVar1 == 1) {
          local_58[2] = 0;
        }
        else if (DVar1 != 0) {
          return DVar1;
        }
        *param_1 = *param_1 + local_58[2];
        uVar2 = uVar2 + 1;
        iVar3 = iVar3 + 4;
      } while (uVar2 < DAT_4026f594);
    }
    DVar1 = 0;
  }
  return DVar1;
}



/* 4026419c FUN_4026419c */

/* Boundary evidence: original MIPS .pdata 4026419c..402643d3. Semantic name remains unreviewed. */

DWORD FUN_4026419c(int *param_1,int *param_2,HANDLE param_3,DWORD param_4,DWORD param_5)

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
  lpMem = FUN_40262d48(&local_68);
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
LAB_402643b8:
      HeapFree(DAT_4026f5d4,0,lpMem);
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
            DVar4 = FUN_402629ac(2,&local_50,local_64 + 1,local_64 + 2,local_64);
            if (DVar4 != 1) {
              if (DVar4 != 0) {
LAB_402643a8:
                HeapFree(param_3,0,(LPVOID)*param_1);
                goto LAB_402643b8;
              }
              if (local_64[2] == 0x280) {
                if (iVar5 == iVar6) {
                  pvVar2 = HeapReAlloc(param_3,param_5,(LPVOID)*param_1,iVar6 << 3);
                  if (pvVar2 == (LPVOID)0x0) {
                    DVar4 = GetLastError();
                    goto LAB_402643a8;
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
      HeapFree(DAT_4026f5d4,0,lpMem);
      DVar4 = 0;
      *local_58 = iVar5;
    }
  }
  return DVar4;
}



/* 402643d4 FUN_402643d4 */

/* Boundary evidence: original MIPS .pdata 402643d4..402644cb. Semantic name remains unreviewed. */

undefined4 FUN_402643d4(void *param_1)

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
  
  local_c = DAT_4026f418;
  local_68 = 0x4f;
  FUN_40265020();
  if (DAT_4026f5a4 == 0) {
    FUN_4026e238(local_c);
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
      uVar4 = FUN_4026294c(iVar3);
    }
    FUN_4026e238(local_c);
  }
  return uVar4;
}



/* 402644cc FUN_402644cc */

/* Boundary evidence: original MIPS .pdata 402644cc..4026453f. Semantic name remains unreviewed. */

DWORD FUN_402644cc(undefined4 param_1,LPVOID param_2)

{
  DWORD DVar1;
  undefined4 local_res0 [4];
  DWORD local_10 [2];
  
  local_10[1] = 4;
  local_10[0] = 4;
  local_res0[0] = param_1;
  FUN_40265020();
  if (DAT_4026f5a4 == 0) {
    DVar1 = 0x32;
  }
  else {
    DVar1 = FUN_40262aa8(DAT_4026f5b4,0x120044,local_res0,local_10 + 1,param_2,local_10);
  }
  return DVar1;
}



/* 40264540 FUN_40264540 */

/* Boundary evidence: original MIPS .pdata 40264540..4026457b. Semantic name remains unreviewed. */

DWORD FUN_40264540(int param_1)

{
  DWORD DVar1;
  
  if ((param_1 == 2) || (param_1 == 0x17)) {
    DVar1 = FUN_40262b0c(param_1);
  }
  else {
    DVar1 = 0x57;
  }
  return DVar1;
}



/* 4026457c FUN_4026457c */

/* Boundary evidence: original MIPS .pdata 4026457c..402645cf. Semantic name remains unreviewed. */

undefined4 FUN_4026457c(void)

{
  if (DAT_4026f5a8 != 0) {
    CloseHandle((HANDLE)DAT_4026f5a8);
  }
  DAT_4026f5a8 = 0;
  DAT_4026f5b4 = 0;
  return 0;
}



/* 402645d0 FUN_402645d0 */

/* Boundary evidence: original MIPS .pdata 402645d0..40264623. Semantic name remains unreviewed. */

undefined4 FUN_402645d0(void)

{
  if (DAT_4026f5a0 != 0) {
    CloseHandle((HANDLE)DAT_4026f5a0);
  }
  DAT_4026f5a0 = 0;
  DAT_4026f598 = 0;
  return 0;
}



/* 40264624 FUN_40264624 */

/* Boundary evidence: original MIPS .pdata 40264624..4026481b. Semantic name remains unreviewed. */

undefined4 FUN_40264624(size_t *param_1,int param_2,int param_3,int param_4)

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
  FUN_40265020();
  if (DAT_4026f5a4 == 0) {
    uVar4 = 0x32;
  }
  else {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_4026f600);
    if ((((param_4 == 0) && (DAT_4026f5d8 != 0)) &&
        (DVar1 = GetTickCount(), DVar1 - DAT_4026f5d8 < 0xea61)) ||
       (iVar2 = FUN_4026cd28(), iVar2 == 0)) {
      puVar6 = &DAT_4026f440;
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
              DVar1 = FUN_40262e28(0,puVar3[4],(undefined2 *)psVar5);
              if (DVar1 == 0) {
                _NumOfElements = _NumOfElements + 1;
                psVar5 = psVar5 + 0xd7;
              }
              else {
                DAT_4026f5d8 = 0;
              }
            }
            puVar3 = (undefined4 *)*puVar3;
          } while (puVar3 != puVar6);
        }
        puVar6 = puVar6 + 2;
      } while (puVar6 < (undefined4 *)0x4026f568);
      DAT_4026f614 = _NumOfElements;
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_4026f600);
      *param_1 = _NumOfElements;
      if ((param_3 != 0) && (_NumOfElements != 0)) {
        qsort(param_1 + 1,_NumOfElements,0x35c,(_PtFuncCompare *)&LAB_4026c628);
      }
    }
    else {
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_4026f600);
      uVar4 = 0x3eb;
    }
  }
  return uVar4;
}



/* 4026481c FUN_4026481c */

/* Boundary evidence: original MIPS .pdata 4026481c..40264913. Semantic name remains unreviewed. */

DWORD FUN_4026481c(undefined2 *param_1,uint param_2,int param_3)

{
  DWORD DVar1;
  int iVar2;
  
  if (param_1 == (undefined2 *)0x0) {
    DVar1 = 0x57;
  }
  else {
    FUN_40265020();
    if (DAT_4026f5a4 == 0) {
      DVar1 = 0x32;
    }
    else {
      EnterCriticalSection((LPCRITICAL_SECTION)&DAT_4026f600);
      if ((param_3 != 0) || (iVar2 = FUN_4026ccc0(param_2), iVar2 == -1)) {
        iVar2 = FUN_4026cd28();
        if (iVar2 != 0) {
          LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_4026f600);
          return 0x3eb;
        }
        iVar2 = FUN_4026ccc0(param_2);
      }
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_4026f600);
      if (iVar2 == -1) {
        DVar1 = 0xd;
      }
      else {
        DVar1 = FUN_40262e28(0,iVar2,param_1);
      }
    }
  }
  return DVar1;
}



/* 40264914 FUN_40264914 */

/* Boundary evidence: original MIPS .pdata 40264914..40264a07. Semantic name remains unreviewed. */

DWORD FUN_40264914(undefined2 *param_1,int param_2)

{
  int iVar1;
  DWORD DVar2;
  
  FUN_40265020();
  if (DAT_4026f5a4 == 0) {
    return 0x32;
  }
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_4026f600);
  if (param_2 == 0) {
    iVar1 = FUN_4026ccc0(*(uint *)(param_1 + 0x100));
    if (iVar1 == -1) {
      iVar1 = FUN_4026cd28();
      if (iVar1 != 0) {
        DVar2 = 0x3eb;
        goto LAB_402649e0;
      }
      goto LAB_402649b4;
    }
  }
  else {
    iVar1 = FUN_4026cd28();
    if (iVar1 != 0) {
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_4026f600);
      return 0x3eb;
    }
LAB_402649b4:
    iVar1 = FUN_4026ccc0(*(uint *)(param_1 + 0x100));
    if (iVar1 == -1) {
      DVar2 = 0xd;
      goto LAB_402649e0;
    }
  }
  DVar2 = FUN_40262e28(1,iVar1,param_1);
LAB_402649e0:
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_4026f600);
  return DVar2;
}



/* 40264a08 AllocateAndGetIpAddrTableFromStack */

/* Boundary evidence: original MIPS .pdata 40264a08..40264aeb. Semantic name remains unreviewed. */

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
  DVar1 = FUN_402636b0(auStack_78);
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
      DVar1 = FUN_40262fac(puVar2,dwBytes,param_2);
      if (DVar1 != 0) {
        HeapFree(param_3,param_4,(LPVOID)*param_1);
        *param_1 = 0;
      }
    }
  }
  return DVar1;
}



/* 40264aec FUN_40264aec */

/* WARNING: Type propagation algorithm not settling */
/* Boundary evidence: original MIPS .pdata 40264aec..40264d2b. Semantic name remains unreviewed. */

DWORD FUN_40264aec(size_t *param_1,int param_2,int param_3)

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
  DVar3 = FUN_402636b0(auStack_80);
  if (DVar3 == 0) {
    if (((local_28 <= local_28 + 0x14) &&
        (lVar2 = (ulonglong)(local_28 + 0x14) * 0x34, local_b0 = (SIZE_T)lVar2,
        (int)((ulonglong)lVar2 >> 0x20) == 0)) &&
       (lpMem = HeapAlloc(DAT_4026f5d4,0,local_b0), lpMem != (LPVOID)0x0)) {
      local_ac[1] = 0x301;
      local_ac[2] = 0;
      local_ac[3] = 0x200;
      local_ac[4] = 0x100;
      local_ac[5] = 0x101;
      memset(auStack_94,0,0x10);
      local_ac[0] = 0x24;
      DVar3 = FUN_402629ac(2,local_ac + 1,local_ac,lpMem,&local_b0);
      if (DVar3 != 0) {
        HeapFree(DAT_4026f5d4,0,lpMem);
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
      HeapFree(DAT_4026f5d4,0,lpMem);
      if (*param_1 == 0) {
        return DVar3;
      }
      if (param_3 == 0) {
        return DVar3;
      }
      qsort(param_1 + 1,*param_1,0x38,(_PtFuncCompare *)&LAB_4026c958);
      return DVar3;
    }
    DVar3 = 8;
  }
  return DVar3;
}



/* 40264d2c FUN_40264d2c */

/* Boundary evidence: original MIPS .pdata 40264d2c..40264dd3. Semantic name remains unreviewed. */

undefined4 FUN_40264d2c(undefined4 *param_1)

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
  
  FUN_40265020();
  if (DAT_4026f5a4 == 0) {
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
    uVar1 = FUN_402643d4(&local_40);
  }
  return uVar1;
}



/* 40264dd4 AllocateAndGetIfTableFromStack */

/* Boundary evidence: original MIPS .pdata 40264dd4..40264f07. Semantic name remains unreviewed. */

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
  DVar1 = FUN_402636b0(auStack_80);
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
      EnterCriticalSection((LPCRITICAL_SECTION)&DAT_4026f600);
      if ((param_5 == 0) && (local_30 != DAT_4026f614)) {
        param_5 = 1;
      }
      DAT_4026f614 = local_30;
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_4026f600);
      DVar1 = FUN_40264624((size_t *)*param_1,dwBytes,param_2,param_5);
      if (DVar1 != 0) {
        HeapFree(param_3,param_4,(LPVOID)*param_1);
        *param_1 = 0;
      }
    }
  }
  return DVar1;
}



/* 40264f08 FUN_40264f08 */

undefined4 FUN_40264f08(short *param_1)

{
  undefined4 uVar1;
  
  if ((((*param_1 != 0) || (param_1[1] != 0)) || (param_1[2] != 0)) ||
     (((param_1[3] != 0 || (param_1[4] != 0)) || (uVar1 = 1, param_1[5] != -1)))) {
    uVar1 = 0;
  }
  return uVar1;
}



/* 40264f60 FUN_40264f60 */

/* Boundary evidence: original MIPS .pdata 40264f60..4026500f. Semantic name remains unreviewed. */

void FUN_40264f60(undefined4 *param_1,undefined4 *param_2)

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



/* 40265010 GetFriendlyIfIndex */

uint GetFriendlyIfIndex(uint param_1)

{
                    /* 0x5010  20  GetFriendlyIfIndex */
  return param_1 & 0xffffff;
}



/* 40265020 FUN_40265020 */

/* Boundary evidence: original MIPS .pdata 40265020..402650f3. Semantic name remains unreviewed. */

void FUN_40265020(void)

{
  DWORD DVar1;
  int iVar2;
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_4026f5e0);
  if ((DAT_4026f5a4 == 0) && (DVar1 = FUN_40264540(2), DVar1 == 0)) {
    iVar2 = FUN_4026cd28();
    if ((iVar2 == 0) &&
       ((DVar1 = FUN_4026cf1c(), DVar1 == 0 && (iVar2 = FUN_40268cac(0,1), iVar2 != 0)))) {
      DAT_4026f5a4 = 1;
    }
    else {
      FUN_4026457c();
    }
  }
  if ((DAT_4026f5ac == 0) && (DVar1 = FUN_40264540(0x17), DVar1 == 0)) {
    DAT_4026f5ac = 1;
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_4026f5e0);
  return;
}



/* 402650f4 GetNumberOfInterfaces */

/* Boundary evidence: original MIPS .pdata 402650f4..4026515f. Semantic name remains unreviewed. */

DWORD GetNumberOfInterfaces(undefined4 *param_1)

{
  DWORD DVar1;
  undefined1 auStack_68 [80];
  undefined4 local_18;
  
                    /* 0x50f4  32  GetNumberOfInterfaces */
  FUN_40265020();
  if (DAT_4026f5a4 == 0) {
    DVar1 = 0x32;
  }
  else if (param_1 == (undefined4 *)0x0) {
    DVar1 = 0x57;
  }
  else {
    *param_1 = 0;
    DVar1 = FUN_402636b0(auStack_68);
    if (DVar1 == 0) {
      DVar1 = 0;
      *param_1 = local_18;
    }
  }
  return DVar1;
}



/* 40265160 GetIfTable */

/* Boundary evidence: original MIPS .pdata 40265160..40265313. Semantic name remains unreviewed. */

DWORD GetIfTable(size_t *param_1,UINT_PTR *param_2,int param_3)

{
  bool bVar1;
  BOOL BVar2;
  DWORD DVar3;
  int local_28 [2];
  
                    /* 0x5160  24  GetIfTable */
  FUN_40265020();
  if (DAT_4026f5a4 == 0) {
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
        EnterCriticalSection((LPCRITICAL_SECTION)&DAT_4026f600);
        bVar1 = local_28[0] != DAT_4026f614;
        DAT_4026f614 = local_28[0];
        LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_4026f600);
        DVar3 = FUN_40264624(param_1,*param_2,param_3,(uint)bVar1);
        if ((param_3 == 0) && (DVar3 == 0)) {
          EnterCriticalSection((LPCRITICAL_SECTION)&DAT_4026f600);
          DAT_4026f42c = GetAdapterOrderMap();
          if (DAT_4026f42c != (uint *)0x0) {
            qsort(param_1 + 1,*param_1,0x35c,FUN_4026caa4);
            LocalFree(DAT_4026f42c);
          }
          LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_4026f600);
        }
      }
    }
  }
  return DVar3;
}



/* 40265314 GetIpAddrTable */

/* Boundary evidence: original MIPS .pdata 40265314..40265483. Semantic name remains unreviewed. */

DWORD GetIpAddrTable(uint *param_1,UINT_PTR *param_2,int param_3)

{
  BOOL BVar1;
  DWORD DVar2;
  undefined1 auStack_78 [84];
  int local_24;
  
                    /* 0x5314  26  GetIpAddrTable */
  FUN_40265020();
  if (DAT_4026f5a4 == 0) {
    DVar2 = 0x32;
  }
  else if (((param_2 == (UINT_PTR *)0x0) || (BVar1 = IsBadWritePtr(param_2,4), BVar1 != 0)) ||
          (BVar1 = IsBadWritePtr(param_1,*param_2), BVar1 != 0)) {
    DVar2 = 0x57;
  }
  else {
    DVar2 = FUN_402636b0(auStack_78);
    if (DVar2 == 0) {
      if (local_24 == 0) {
        DVar2 = 0xe8;
      }
      else if ((*param_2 < local_24 * 0x18 + 0xcU) || (param_1 == (uint *)0x0)) {
        *param_2 = local_24 * 0x18 + 0xfc;
        DVar2 = 0x7a;
      }
      else {
        DVar2 = FUN_40262fac(param_1,*param_2,param_3);
        if ((param_3 == 0) && (DVar2 == 0)) {
          EnterCriticalSection((LPCRITICAL_SECTION)&DAT_4026f600);
          DAT_4026f42c = GetAdapterOrderMap();
          if (DAT_4026f42c != (uint *)0x0) {
            qsort(param_1 + 1,*param_1,0x18,FUN_4026cac4);
            LocalFree(DAT_4026f42c);
          }
          LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_4026f600);
        }
      }
    }
  }
  return DVar2;
}



/* 40265484 GetIpNetTable */

/* Boundary evidence: original MIPS .pdata 40265484..402655c7. Semantic name remains unreviewed. */

DWORD GetIpNetTable(size_t *param_1,uint *param_2,int param_3)

{
  BOOL BVar1;
  DWORD DVar2;
  int local_28 [2];
  
                    /* 0x5484  28  GetIpNetTable */
  FUN_40265020();
  if (DAT_4026f5a4 == 0) {
    return 0x32;
  }
  if ((param_2 != (uint *)0x0) && (BVar1 = IsBadWritePtr(param_2,4), BVar1 == 0)) {
    local_28[0] = 0;
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_4026f5c0);
    DVar2 = FUN_4026402c(local_28);
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_4026f5c0);
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
      DVar2 = FUN_40263388(param_1,*param_2,param_3,0);
      return DVar2;
    }
  }
  return 0x57;
}



/* 402655c8 GetIpStatisticsEx */

/* Boundary evidence: original MIPS .pdata 402655c8..4026568b. Semantic name remains unreviewed. */

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
    FUN_40265020();
    if (((param_2 == 2) && (DAT_4026f5a4 == 0)) || ((param_2 == 0x17 && (DAT_4026f5ac == 0)))) {
      DVar1 = 0x32;
    }
    else {
      DVar1 = FUN_402635b8(param_1,param_2);
    }
  }
  return DVar1;
}



/* 4026568c GetIpStatistics */

/* Boundary evidence: original MIPS .pdata 4026568c..40265707. Semantic name remains unreviewed. */

DWORD GetIpStatistics(LPVOID param_1)

{
  DWORD DVar1;
  BOOL BVar2;
  
                    /* 0x568c  29  GetIpStatistics */
  if ((param_1 == (LPVOID)0x0) || (BVar2 = IsBadWritePtr(param_1,0x5c), BVar2 != 0)) {
    DVar1 = 0x57;
  }
  else {
    FUN_40265020();
    if (DAT_4026f5a4 == 0) {
      DVar1 = 0x32;
    }
    else {
      DVar1 = FUN_402635b8(param_1,2);
    }
  }
  return DVar1;
}



/* 40265708 GetIcmpStatistics */

/* Boundary evidence: original MIPS .pdata 40265708..4026577b. Semantic name remains unreviewed. */

undefined4 GetIcmpStatistics(LPVOID param_1)

{
  undefined4 uVar1;
  BOOL BVar2;
  
                    /* 0x5708  21  GetIcmpStatistics */
  FUN_40265020();
  if (DAT_4026f5a4 == 0) {
    uVar1 = 0x32;
  }
  else if ((param_1 == (LPVOID)0x0) || (BVar2 = IsBadWritePtr(param_1,0x68), BVar2 != 0)) {
    uVar1 = 0x57;
  }
  else {
    FUN_4026395c(param_1);
    uVar1 = 0;
  }
  return uVar1;
}



/* 4026577c GetIcmpStatisticsEx */

/* Boundary evidence: original MIPS .pdata 4026577c..40265883. Semantic name remains unreviewed. */

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
  FUN_40265020();
  if ((param_2 == 2) && (DAT_4026f5a4 == 0)) {
LAB_40265810:
    DVar2 = 0x32;
  }
  else {
    if (param_2 == 0x17) {
      if (DAT_4026f5ac == 0) goto LAB_40265810;
    }
    else if (param_2 == 2) {
      DVar2 = GetIcmpStatistics(auStack_80);
      if (DVar2 != 0) {
        return DVar2;
      }
      FUN_40264f60(param_1,auStack_80);
      FUN_40264f60(param_1 + 0x102,auStack_4c);
      return 0;
    }
    DVar2 = FUN_4026384c(param_1,param_2);
  }
  return DVar2;
}



/* 40265884 GetTcpStatisticsEx */

/* Boundary evidence: original MIPS .pdata 40265884..4026594b. Semantic name remains unreviewed. */

DWORD GetTcpStatisticsEx(LPVOID param_1,int param_2)

{
  BOOL BVar1;
  DWORD DVar2;
  
                    /* 0x5884  36  GetTcpStatisticsEx */
  if ((param_2 == 2) || (param_2 == 0x17)) {
    FUN_40265020();
    if (((param_2 == 2) && (DAT_4026f5a4 == 0)) || ((param_2 == 0x17 && (DAT_4026f5ac == 0)))) {
      return 0x32;
    }
    if ((param_1 != (LPVOID)0x0) && (BVar1 = IsBadWritePtr(param_1,0x3c), BVar1 == 0)) {
      DVar2 = FUN_40263af4(param_1,param_2);
      return DVar2;
    }
  }
  return 0x57;
}



/* 4026594c GetTcpStatistics */

/* Boundary evidence: original MIPS .pdata 4026594c..402659c3. Semantic name remains unreviewed. */

DWORD GetTcpStatistics(LPVOID param_1)

{
  DWORD DVar1;
  BOOL BVar2;
  
                    /* 0x594c  35  GetTcpStatistics */
  FUN_40265020();
  if (DAT_4026f5a4 == 0) {
    DVar1 = 0x32;
  }
  else if ((param_1 == (LPVOID)0x0) || (BVar2 = IsBadWritePtr(param_1,0x3c), BVar2 != 0)) {
    DVar1 = 0x57;
  }
  else {
    DVar1 = FUN_40263af4(param_1,2);
  }
  return DVar1;
}



/* 402659c4 GetUdpStatisticsEx */

/* Boundary evidence: original MIPS .pdata 402659c4..40265a8b. Semantic name remains unreviewed. */

DWORD GetUdpStatisticsEx(LPVOID param_1,int param_2)

{
  BOOL BVar1;
  DWORD DVar2;
  
                    /* 0x59c4  39  GetUdpStatisticsEx */
  if ((param_2 == 2) || (param_2 == 0x17)) {
    FUN_40265020();
    if (((param_2 == 2) && (DAT_4026f5a4 == 0)) || ((param_2 == 0x17 && (DAT_4026f5ac == 0)))) {
      return 0x32;
    }
    if ((param_1 != (LPVOID)0x0) && (BVar1 = IsBadWritePtr(param_1,0x14), BVar1 == 0)) {
      DVar2 = FUN_402639fc(param_1,param_2);
      return DVar2;
    }
  }
  return 0x57;
}



/* 40265a8c GetUdpStatistics */

/* Boundary evidence: original MIPS .pdata 40265a8c..40265b03. Semantic name remains unreviewed. */

DWORD GetUdpStatistics(LPVOID param_1)

{
  DWORD DVar1;
  BOOL BVar2;
  
                    /* 0x5a8c  38  GetUdpStatistics */
  FUN_40265020();
  if (DAT_4026f5a4 == 0) {
    DVar1 = 0x32;
  }
  else if ((param_1 == (LPVOID)0x0) || (BVar2 = IsBadWritePtr(param_1,0x14), BVar2 != 0)) {
    DVar1 = 0x57;
  }
  else {
    DVar1 = FUN_402639fc(param_1,2);
  }
  return DVar1;
}



/* 40265b04 GetIfEntry */

/* Boundary evidence: original MIPS .pdata 40265b04..40265b83. Semantic name remains unreviewed. */

DWORD GetIfEntry(undefined2 *param_1)

{
  BOOL BVar1;
  DWORD DVar2;
  
                    /* 0x5b04  23  GetIfEntry */
  if ((param_1 == (undefined2 *)0x0) || (BVar1 = IsBadWritePtr(param_1,0x35c), BVar1 != 0)) {
    DVar2 = 0x57;
  }
  else {
    FUN_40265020();
    if (DAT_4026f5a4 == 0) {
      DVar2 = 0x32;
    }
    else {
      DVar2 = FUN_4026481c(param_1,*(uint *)(param_1 + 0x100),1);
    }
  }
  return DVar2;
}



/* 40265b84 SetIfEntry */

/* Boundary evidence: original MIPS .pdata 40265b84..40265c0f. Semantic name remains unreviewed. */

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
    FUN_40265020();
    if (DAT_4026f5a4 == 0) {
      DVar1 = 0x32;
    }
    else {
      local_370[0] = 2;
      memcpy(auStack_368,param_1,0x35c);
      DVar1 = FUN_40261504((int)local_370);
    }
  }
  return DVar1;
}



/* 40265c10 CreateIpForwardEntry */

/* Boundary evidence: original MIPS .pdata 40265c10..40265ca3. Semantic name remains unreviewed. */

int CreateIpForwardEntry(void *param_1)

{
  int iVar1;
  BOOL BVar2;
  undefined4 local_50 [2];
  undefined1 auStack_48 [64];
  
                    /* 0x5c10  4  CreateIpForwardEntry */
  FUN_40265020();
  if (DAT_4026f5a4 == 0) {
    iVar1 = 0x32;
  }
  else {
    if ((param_1 != (void *)0x0) && (BVar2 = IsBadReadPtr(param_1,0x38), BVar2 == 0)) {
      local_50[0] = 8;
      memcpy(auStack_48,param_1,0x38);
      iVar1 = FUN_40261548((int)local_50);
      if (iVar1 != -0x3ffffff3) {
        return iVar1;
      }
    }
    iVar1 = 0x57;
  }
  return iVar1;
}



/* 40265ca4 SetIpForwardEntry */

/* Boundary evidence: original MIPS .pdata 40265ca4..40265d37. Semantic name remains unreviewed. */

int SetIpForwardEntry(void *param_1)

{
  int iVar1;
  BOOL BVar2;
  undefined4 local_50 [2];
  undefined1 auStack_48 [64];
  
                    /* 0x5ca4  57  SetIpForwardEntry */
  FUN_40265020();
  if (DAT_4026f5a4 == 0) {
    iVar1 = 0x32;
  }
  else {
    if ((param_1 != (void *)0x0) && (BVar2 = IsBadReadPtr(param_1,0x38), BVar2 == 0)) {
      local_50[0] = 8;
      memcpy(auStack_48,param_1,0x38);
      iVar1 = FUN_40261598((int)local_50);
      if (iVar1 != -0x3ffffff3) {
        return iVar1;
      }
    }
    iVar1 = 0x57;
  }
  return iVar1;
}



/* 40265d38 DeleteIpForwardEntry */

/* Boundary evidence: original MIPS .pdata 40265d38..40265dd3. Semantic name remains unreviewed. */

int DeleteIpForwardEntry(void *param_1)

{
  int iVar1;
  BOOL BVar2;
  undefined4 local_50 [2];
  undefined1 auStack_48 [64];
  
                    /* 0x5d38  8  DeleteIpForwardEntry */
  FUN_40265020();
  if (DAT_4026f5a4 == 0) {
    iVar1 = 0x32;
  }
  else if ((param_1 == (void *)0x0) || (BVar2 = IsBadReadPtr(param_1,0x38), BVar2 != 0)) {
    iVar1 = 0x57;
  }
  else {
    local_50[0] = 8;
    memcpy(auStack_48,param_1,0x38);
    iVar1 = FUN_402615e8((int)local_50);
    if (iVar1 == -0x3ffffff3) {
      iVar1 = 0x490;
    }
  }
  return iVar1;
}



/* 40265dd4 SetIpStatistics */

/* Boundary evidence: original MIPS .pdata 40265dd4..40265e5b. Semantic name remains unreviewed. */

int SetIpStatistics(void *param_1)

{
  int iVar1;
  BOOL BVar2;
  undefined4 local_70 [2];
  undefined1 auStack_68 [96];
  
                    /* 0x5dd4  59  SetIpStatistics */
  FUN_40265020();
  if (DAT_4026f5a4 == 0) {
    iVar1 = 0x32;
  }
  else if ((param_1 == (void *)0x0) || (BVar2 = IsBadReadPtr(param_1,0x5c), BVar2 != 0)) {
    iVar1 = 0x57;
  }
  else {
    local_70[0] = 3;
    memcpy(auStack_68,param_1,0x5c);
    iVar1 = FUN_40261640((int)local_70);
  }
  return iVar1;
}



/* 40265e5c CreateIpNetEntry */

/* Boundary evidence: original MIPS .pdata 40265e5c..40265f03. Semantic name remains unreviewed. */

int CreateIpNetEntry(void *param_1)

{
  int iVar1;
  uint uVar2;
  undefined4 local_30 [2];
  undefined1 auStack_28 [32];
  
                    /* 0x5e5c  5  CreateIpNetEntry */
  FUN_40265020();
  if (DAT_4026f5a4 == 0) {
    iVar1 = 0x32;
  }
  else {
    if (param_1 != (void *)0x0) {
      local_30[0] = 10;
      memcpy(auStack_28,param_1,0x18);
      if ((((*(uint *)((int)param_1 + 4) != 0) && (*(uint *)((int)param_1 + 4) < 9)) &&
          (uVar2 = *(uint *)((int)param_1 + 0x10) & 0xff, uVar2 != 0x7f)) && (uVar2 < 0xe0)) {
        iVar1 = FUN_40261680((int)local_30);
        return iVar1;
      }
    }
    iVar1 = 0x57;
  }
  return iVar1;
}



/* 40265f04 SetIpNetEntry */

/* Boundary evidence: original MIPS .pdata 40265f04..40265f8b. Semantic name remains unreviewed. */

int SetIpNetEntry(void *param_1)

{
  int iVar1;
  BOOL BVar2;
  undefined4 local_30 [2];
  undefined1 auStack_28 [32];
  
                    /* 0x5f04  58  SetIpNetEntry */
  FUN_40265020();
  if (DAT_4026f5a4 == 0) {
    iVar1 = 0x32;
  }
  else if ((param_1 == (void *)0x0) || (BVar2 = IsBadReadPtr(param_1,0x18), BVar2 != 0)) {
    iVar1 = 0x57;
  }
  else {
    local_30[0] = 10;
    memcpy(auStack_28,param_1,0x18);
    iVar1 = FUN_402616c4((int)local_30);
  }
  return iVar1;
}



/* 40265f8c DeleteIpNetEntry */

/* Boundary evidence: original MIPS .pdata 40265f8c..40266013. Semantic name remains unreviewed. */

int DeleteIpNetEntry(void *param_1)

{
  int iVar1;
  BOOL BVar2;
  undefined4 local_30 [2];
  undefined1 auStack_28 [32];
  
                    /* 0x5f8c  9  DeleteIpNetEntry */
  FUN_40265020();
  if (DAT_4026f5a4 == 0) {
    iVar1 = 0x32;
  }
  else if ((param_1 == (void *)0x0) || (BVar2 = IsBadReadPtr(param_1,0x18), BVar2 != 0)) {
    iVar1 = 0x57;
  }
  else {
    local_30[0] = 10;
    memcpy(auStack_28,param_1,0x18);
    iVar1 = FUN_40261708((int)local_30);
  }
  return iVar1;
}



/* 40266014 FlushIpNetTable */

/* Boundary evidence: original MIPS .pdata 40266014..40266067. Semantic name remains unreviewed. */

DWORD FlushIpNetTable(int param_1)

{
  DWORD DVar1;
  
                    /* 0x6014  12  FlushIpNetTable */
  FUN_40265020();
  if (DAT_4026f5a4 == 0) {
    DVar1 = 0x32;
  }
  else if (param_1 == 0) {
    DVar1 = 0x57;
  }
  else {
    DVar1 = FUN_40263dbc(param_1);
  }
  return DVar1;
}



/* 40266068 SetTcpEntry */

/* Boundary evidence: original MIPS .pdata 40266068..4026610b. Semantic name remains unreviewed. */

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
    FUN_40265020();
    if (DAT_4026f5a4 == 0) {
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
      uVar2 = FUN_40261754((int)local_28);
      return uVar2;
    }
  }
  return 0x57;
}



/* 4026610c GetBestInterface */

/* Boundary evidence: original MIPS .pdata 4026610c..4026619f. Semantic name remains unreviewed. */

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
    FUN_40265020();
    if (DAT_4026f5a4 == 0) {
      uVar1 = 0x32;
    }
    else {
      DVar3 = FUN_402644cc(param_1,param_2);
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



/* 402661a0 GetBestInterfaceEx */

/* Boundary evidence: original MIPS .pdata 402661a0..402662b3. Semantic name remains unreviewed. */

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
LAB_402661f8:
      DVar2 = GetBestInterface(uVar4,param_2);
      return DVar2;
    }
    if ((*param_1 == 0x17) && (BVar1 = IsBadReadPtr(param_1,0x1c), BVar1 == 0)) {
      iVar3 = FUN_40264f08(param_1 + 4);
      if (iVar3 != 0) {
        uVar4 = *(undefined4 *)(param_1 + 10);
        goto LAB_402661f8;
      }
      if ((param_2 != (undefined4 *)0x0) && (BVar1 = IsBadWritePtr(param_2,4), BVar1 == 0)) {
        FUN_40265020();
        if (DAT_4026f5ac == 0) {
          return 0x32;
        }
        DVar2 = FUN_4026d080((int)param_1,param_2);
        return DVar2;
      }
    }
  }
  return 0x57;
}



/* 402662b4 GetBestRoute */

/* Boundary evidence: original MIPS .pdata 402662b4..40266357. Semantic name remains unreviewed. */

undefined4 GetBestRoute(uint param_1,uint param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  BOOL BVar2;
  DWORD DVar3;
  
                    /* 0x62b4  19  GetBestRoute */
  FUN_40265020();
  if (DAT_4026f5a4 == 0) {
    uVar1 = 0x32;
  }
  else if ((param_3 == (undefined4 *)0x0) || (BVar2 = IsBadWritePtr(param_3,0x38), BVar2 != 0)) {
    uVar1 = 0x57;
  }
  else {
    DVar3 = FUN_40262be8(param_1,param_2,param_3);
    if (DVar3 == 0) {
      uVar1 = 0;
    }
    else {
      uVar1 = 0x3eb;
    }
  }
  return uVar1;
}



/* 40266358 CreateProxyArpEntry */

/* Boundary evidence: original MIPS .pdata 40266358..4026648f. Semantic name remains unreviewed. */

int CreateProxyArpEntry(uint param_1,uint param_2,uint param_3)

{
  int iVar1;
  uint uVar2;
  
                    /* 0x6358  6  CreateProxyArpEntry */
  FUN_40265020();
  if (DAT_4026f5a4 == 0) {
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
      if ((param_1 & 0xf0) == 0xe0) goto LAB_402663fc;
      uVar2 = 0xffff0000;
    }
    uVar2 = uVar2 | 0xffff;
  }
LAB_402663fc:
  if (((((param_1 & 0xff) == 0x7f) || (param_1 == 0)) || (0xdf < (param_1 & 0xff))) ||
     (((param_1 & param_2) != param_1 || (param_1 == (~uVar2 | param_1))))) {
    iVar1 = 0x57;
  }
  else {
    iVar1 = FUN_4026c620();
    if ((iVar1 == 0) && (iVar1 = FUN_40263e24(param_1,param_2,param_3,1,0), iVar1 != 0)) {
      return iVar1;
    }
    iVar1 = 0;
  }
  return iVar1;
}



/* 40266490 DeleteProxyArpEntry */

/* Boundary evidence: original MIPS .pdata 40266490..402665c7. Semantic name remains unreviewed. */

int DeleteProxyArpEntry(uint param_1,uint param_2,uint param_3)

{
  int iVar1;
  uint uVar2;
  
                    /* 0x6490  10  DeleteProxyArpEntry */
  FUN_40265020();
  if (DAT_4026f5a4 == 0) {
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
      if ((param_1 & 0xf0) == 0xe0) goto LAB_40266534;
      uVar2 = 0xffff0000;
    }
    uVar2 = uVar2 | 0xffff;
  }
LAB_40266534:
  if (((((param_1 & 0xff) == 0x7f) || (param_1 == 0)) || (0xdf < (param_1 & 0xff))) ||
     (((param_1 & param_2) != param_1 || (param_1 == (~uVar2 | param_1))))) {
    iVar1 = 0x57;
  }
  else {
    iVar1 = FUN_4026c620();
    if ((iVar1 == 0) && (iVar1 = FUN_40263e24(param_1,param_2,param_3,0,0), iVar1 != 0)) {
      return iVar1;
    }
    iVar1 = 0;
  }
  return iVar1;
}



/* 402665c8 GetIpForwardTable */

/* Boundary evidence: original MIPS .pdata 402665c8..402666d3. Semantic name remains unreviewed. */

DWORD GetIpForwardTable(size_t *param_1,UINT_PTR *param_2,int param_3)

{
  DWORD DVar1;
  BOOL BVar2;
  undefined1 auStack_78 [88];
  int local_20;
  
                    /* 0x65c8  27  GetIpForwardTable */
  FUN_40265020();
  if (DAT_4026f5a4 == 0) {
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
        DVar1 = FUN_40264aec(param_1,*param_2,param_3);
      }
    }
  }
  return DVar1;
}



/* 402666d4 GetTcpTable */

/* Boundary evidence: original MIPS .pdata 402666d4..402667df. Semantic name remains unreviewed. */

DWORD GetTcpTable(uint *param_1,UINT_PTR *param_2,int param_3)

{
  DWORD DVar1;
  BOOL BVar2;
  undefined1 auStack_58 [56];
  int local_20;
  
                    /* 0x66d4  37  GetTcpTable */
  FUN_40265020();
  if (DAT_4026f5a4 == 0) {
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
        DVar1 = FUN_402630a4(param_1,*param_2,param_3);
      }
    }
  }
  return DVar1;
}



/* 402667e0 GetUdpTable */

/* Boundary evidence: original MIPS .pdata 402667e0..402668e3. Semantic name remains unreviewed. */

DWORD GetUdpTable(uint *param_1,UINT_PTR *param_2,int param_3)

{
  DWORD DVar1;
  BOOL BVar2;
  undefined1 auStack_30 [16];
  int local_20;
  
                    /* 0x67e0  40  GetUdpTable */
  FUN_40265020();
  if (DAT_4026f5a4 == 0) {
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
        DVar1 = FUN_40263298(param_1,*param_2,param_3);
      }
    }
  }
  return DVar1;
}



/* 402668e4 SetIpTTL */

/* Boundary evidence: original MIPS .pdata 402668e4..40266947. Semantic name remains unreviewed. */

DWORD SetIpTTL(undefined4 param_1)

{
  DWORD DVar1;
  undefined4 local_68;
  undefined4 local_64;
  
                    /* 0x68e4  60  SetIpTTL */
  FUN_40265020();
  if (DAT_4026f5a4 == 0) {
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



/* 40266948 FUN_40266948 */

undefined4 FUN_40266948(short *param_1)

{
  undefined4 uVar1;
  
  if (((((*param_1 != 0) || (param_1[1] != 0)) || (param_1[2] != 0)) ||
      ((param_1[3] != 0 || (param_1[4] != 0)))) ||
     ((param_1[5] != 0 || ((param_1[6] != 0 || (uVar1 = 1, param_1[7] != 0)))))) {
    uVar1 = 0;
  }
  return uVar1;
}



/* 402669b4 FUN_402669b4 */

undefined4 FUN_402669b4(short *param_1)

{
  undefined4 uVar1;
  
  if (((((*param_1 != 0) || (param_1[1] != 0)) || (param_1[2] != 0)) ||
      ((param_1[3] != 0 || (param_1[4] != 0)))) ||
     ((param_1[5] != 0 || ((param_1[6] != 0 || (uVar1 = 1, param_1[7] != 0x100)))))) {
    uVar1 = 0;
  }
  return uVar1;
}



/* 40266a24 FUN_40266a24 */

undefined4 FUN_40266a24(short *param_1)

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



/* 40266aa8 FUN_40266aa8 */

/* Boundary evidence: original MIPS .pdata 40266aa8..40266b3b. Semantic name remains unreviewed. */

bool FUN_40266aa8(uint *param_1)

{
  LSTATUS LVar1;
  
  *param_1 = 3;
  LVar1 = RegOpenKeyExW((HKEY)0x80000002,L"Comm\\Tcpip\\Parms",0,0x20019,(PHKEY)&DAT_4026f128);
  if (LVar1 != 0) {
    *param_1 = *param_1 & 0xfffffffd;
    DAT_4026f128 = 0xffffffff;
  }
  return LVar1 == 0;
}



/* 40266b3c FUN_40266b3c */

/* Boundary evidence: original MIPS .pdata 40266b3c..40266b93. Semantic name remains unreviewed. */

undefined4 FUN_40266b3c(undefined4 *param_1)

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



/* 40266b94 FUN_40266b94 */

/* Boundary evidence: original MIPS .pdata 40266b94..40266d47. Semantic name remains unreviewed. */

undefined4 FUN_40266b94(undefined4 param_1,int param_2,undefined4 *param_3)

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
          (iVar2 = FUN_402669b4(_Src), iVar2 == 0)) &&
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



/* 40266d48 FUN_40266d48 */

/* Boundary evidence: original MIPS .pdata 40266d48..40266e5f. Semantic name remains unreviewed. */

undefined4 FUN_40266d48(undefined4 param_1,int param_2,undefined4 *param_3)

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



/* 40266e60 FUN_40266e60 */

/* Boundary evidence: original MIPS .pdata 40266e60..40266f77. Semantic name remains unreviewed. */

undefined4 FUN_40266e60(undefined4 param_1,int param_2,undefined4 *param_3)

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



/* 40266f78 FUN_40266f78 */

/* Boundary evidence: original MIPS .pdata 40266f78..4026700f. Semantic name remains unreviewed. */

undefined4
FUN_40266f78(undefined4 param_1,int param_2,undefined4 *param_3,undefined4 *param_4,
            undefined4 *param_5,undefined4 param_6,uint param_7)

{
  undefined4 uVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_2 + 0x48);
  if (iVar2 == 0) {
    if ((param_7 & 1) == 0) {
      uVar1 = FUN_40266b94(param_1,param_2,param_3);
      return uVar1;
    }
  }
  else if (iVar2 == 1) {
    if ((param_7 & 2) == 0) {
      uVar1 = FUN_40266d48(param_1,param_2,param_4);
      return uVar1;
    }
  }
  else if ((iVar2 == 2) && ((param_7 & 4) == 0)) {
    uVar1 = FUN_40266e60(param_1,param_2,param_5);
    return uVar1;
  }
  return 0;
}



/* 40267010 FUN_40267010 */

/* Boundary evidence: original MIPS .pdata 40267010..4026720b. Semantic name remains unreviewed. */

DWORD FUN_40267010(int param_1,undefined *param_2,undefined4 param_3,undefined4 param_4,
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
  
  local_2c = DAT_4026f418;
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
  DVar1 = FUN_4026d228(0x29,0x120008,&local_c0,&local_cc,auStack_98,&local_d0);
  while ((DVar1 == 0 &&
         ((iVar2 = memcmp(&local_ac,&DAT_402610ac,0x10), iVar2 == 0 ||
          (DVar1 = (*(code *)param_2)(param_1,auStack_98,param_3,param_4,param_5,local_c8,param_7,
                                      param_8), DVar1 == 0))))) {
    iVar2 = memcmp(auStack_84,&DAT_402610ac,0x10);
    if (iVar2 == 0) {
      FUN_4026e238(local_2c);
      return 0;
    }
    memcpy(&local_c0,auStack_98,0x24);
    local_cc = 0x24;
    local_d0 = 0x6c;
    DVar1 = FUN_4026d228(0x29,0x120008,&local_c0,&local_cc,auStack_98,&local_d0);
  }
  FUN_4026e238(local_2c);
  return DVar1;
}



/* 4026720c FUN_4026720c */

/* Boundary evidence: original MIPS .pdata 4026720c..402672a7. Semantic name remains unreviewed. */

int FUN_4026720c(int *param_1,ulong param_2,int *param_3)

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



/* 402672a8 FUN_402672a8 */

/* Boundary evidence: original MIPS .pdata 402672a8..40267333. Semantic name remains unreviewed. */

void FUN_402672a8(undefined4 *param_1,char *param_2)

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



/* 40267334 FUN_40267334 */

/* Boundary evidence: original MIPS .pdata 40267334..402673bb. Semantic name remains unreviewed. */

void FUN_40267334(char *param_1,undefined4 *param_2)

{
  size_t sVar1;
  undefined1 auStack_80 [88];
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  uint local_18;
  
  local_18 = DAT_4026f418;
  MD5Init(auStack_80);
  sVar1 = strlen(param_1);
  MD5Update(auStack_80,param_1,sVar1);
  MD5Final(auStack_80);
  *param_2 = local_28;
  param_2[1] = local_24;
  param_2[2] = local_20;
  param_2[3] = local_1c;
  FUN_4026e238(local_18);
  return;
}



/* 402673bc FUN_402673bc */

/* Boundary evidence: original MIPS .pdata 402673bc..4026749f. Semantic name remains unreviewed. */

int FUN_402673bc(int *param_1,undefined4 *param_2,LPWSTR param_3)

{
  int iVar1;
  undefined4 auStack_50 [4];
  char acStack_40 [40];
  uint local_18;
  
  local_18 = DAT_4026f418;
  FUN_402672a8(param_2,acStack_40);
  while( true ) {
    if (param_1 == (int *)0x0) {
      *param_3 = L'\0';
      FUN_4026e238(local_18);
      return 0;
    }
    FUN_40267334((char *)(param_1 + 2),auStack_50);
    iVar1 = memcmp(param_2,auStack_50,0x10);
    if (iVar1 == 0) break;
    param_1 = (int *)*param_1;
  }
  iVar1 = MultiByteToWideChar(0,0,(LPCSTR)(param_1 + 0x43),-1,param_3,0x80);
  if (iVar1 == 0) {
    *param_3 = L'\0';
  }
  FUN_4026e238(local_18);
  return (int)(param_1 + 2);
}



/* 402674a0 FUN_402674a0 */

/* Boundary evidence: original MIPS .pdata 402674a0..40267593. Semantic name remains unreviewed. */

undefined4 FUN_402674a0(undefined4 *param_1,void *param_2,SIZE_T param_3)

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



/* 40267594 FUN_40267594 */

/* Boundary evidence: original MIPS .pdata 40267594..402676bb. Semantic name remains unreviewed. */

undefined4 FUN_40267594(LPCSTR param_1)

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
  
  local_18 = DAT_4026f418;
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
  FUN_4026e238(local_18);
  return uVar3;
}



/* 402676bc FUN_402676bc */

/* Boundary evidence: original MIPS .pdata 402676bc..4026782f. Semantic name remains unreviewed. */

undefined4 FUN_402676bc(void *param_1,int param_2,int *param_3,undefined4 *param_4)

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



/* 40267830 FUN_40267830 */

/* Boundary evidence: original MIPS .pdata 40267830..40267a3f. Semantic name remains unreviewed. */

DWORD FUN_40267830(int param_1,undefined *param_2,undefined4 param_3,undefined4 param_4)

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
  
  local_30 = DAT_4026f418;
  bVar1 = false;
  memset(auStack_68,0,0x38);
  memcpy(&local_a0,auStack_68,0x38);
  local_100[0] = 0x38;
  local_100[1] = 0x54;
  DVar2 = FUN_4026d228(0x29,0x120034,&local_a0,local_100,auStack_f8,local_100 + 1);
  do {
    if (DVar2 != 0) {
LAB_40267a04:
      FUN_4026e238(local_30);
      return DVar2;
    }
    memcpy(auStack_68,auStack_f8,0x38);
    memcpy(auStack_f8,&local_a0,0x38);
    if ((local_8c == param_1) && (local_a0 != -1)) {
      if ((local_a0 == -2) && ((local_9f & 0xc0) == 0x80)) {
        bVar1 = true;
      }
      if (((local_b0 != 2) && (iVar3 = FUN_40266948(asStack_d0), iVar3 != 0)) &&
         (DVar2 = (*(code *)param_2)(auStack_f8,local_90,param_3,param_4), DVar2 != 0))
      goto LAB_40267a04;
    }
    if (local_54 == 0) {
      if (bVar1) {
        DVar2 = (*(code *)param_2)(0x4026f160,0x40,param_3,param_4);
      }
      goto LAB_40267a04;
    }
    memcpy(&local_a0,auStack_68,0x38);
    local_100[0] = 0x38;
    local_100[1] = 0x54;
    DVar2 = FUN_4026d228(0x29,0x120034,&local_a0,local_100,auStack_f8,local_100 + 1);
  } while( true );
}



/* 40267a40 FUN_40267a40 */

/* Boundary evidence: original MIPS .pdata 40267a40..40267c63. Semantic name remains unreviewed. */

DWORD FUN_40267a40(undefined *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
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
  
  local_2c = DAT_4026f418;
  pvVar1 = GetProcessHeap();
  lpMem = HeapAlloc(pvVar1,0,0x158);
  if (lpMem == (int *)0x0) {
    FUN_4026e238(local_2c);
    return 8;
  }
  local_48[2] = -1;
  do {
    local_48[1] = 0x14;
    local_48[0] = 0x158;
    DVar2 = FUN_4026d228(0x29,0x120004,local_48 + 2,local_48 + 1,lpMem,local_48);
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
            if (DVar2 == 0) goto LAB_40267bbc;
            goto LAB_40267c10;
          }
        }
        DVar2 = 0x57;
LAB_40267c10:
        pvVar1 = GetProcessHeap();
        HeapFree(pvVar1,0,lpMem);
        FUN_4026e238(local_2c);
        return DVar2;
      }
    }
    else {
      if (DVar2 != 0xc00000f0) {
        if (DVar2 == 2) {
          DVar2 = 0;
        }
        goto LAB_40267c10;
      }
      DVar2 = 0;
    }
LAB_40267bbc:
    if (*lpMem == -1) goto LAB_40267c10;
    local_48[3] = lpMem[1];
    local_38 = lpMem[2];
    local_34 = lpMem[3];
    local_30 = lpMem[4];
    local_48[2] = *lpMem;
  } while( true );
}



/* 40267c64 FUN_40267c64 */

/* Boundary evidence: original MIPS .pdata 40267c64..40267da3. Semantic name remains unreviewed. */

undefined4 FUN_40267c64(undefined4 param_1,int param_2,int *param_3,undefined4 *param_4)

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



/* 40267da4 FUN_40267da4 */

/* Boundary evidence: original MIPS .pdata 40267da4..402680b3. Semantic name remains unreviewed. */

DWORD FUN_40267da4(int param_1,uint *param_2,undefined4 *param_3,int *param_4,undefined4 *param_5,
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
    iVar2 = FUN_40266b3c(&_Stack_40.dwLowDateTime);
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
  DVar3 = FUN_402618b0(uVar5,(LPVOID)0x0,(LPDWORD)local_48);
  if (DVar3 == 0x7a) {
    pvVar1 = GetProcessHeap();
    lpMem_00 = HeapAlloc(pvVar1,0,(SIZE_T)local_48[0]);
    if (lpMem_00 == (int *)0x0) {
      return 8;
    }
    DVar3 = FUN_402618b0(uVar5,lpMem_00,(LPDWORD)local_48);
  }
  if (DVar3 == 0) {
    uVar6 = (uint)local_48[0] >> 2;
    uVar5 = 0;
    piVar4 = lpMem_00;
    if (uVar6 != 0) {
      do {
        if (DVar3 != 0) break;
        DVar3 = FUN_40267c64(param_1,*piVar4,param_4,param_5);
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



/* 402680b4 FUN_402680b4 */

/* Boundary evidence: original MIPS .pdata 402680b4..40268193. Semantic name remains unreviewed. */

int FUN_402680b4(int param_1,undefined *param_2,undefined4 param_3,undefined4 param_4,
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



/* 40268194 FUN_40268194 */

/* Boundary evidence: original MIPS .pdata 40268194..402682ef. Semantic name remains unreviewed. */

undefined4 FUN_40268194(int param_1,int param_2,int *param_3,undefined4 *param_4)

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



/* 402682f0 FUN_402682f0 */

/* Boundary evidence: original MIPS .pdata 402682f0..402683f3. Semantic name remains unreviewed. */

int FUN_402682f0(int param_1,undefined *param_2,undefined4 param_3,undefined4 param_4)

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



/* 402683f4 FUN_402683f4 */

/* Boundary evidence: original MIPS .pdata 402683f4..402684bb. Semantic name remains unreviewed. */

void FUN_402683f4(undefined *param_1,undefined4 param_2,undefined4 param_3,int *param_4,
                 undefined4 param_5,undefined4 param_6,undefined4 param_7)

{
  int iVar1;
  
  while( true ) {
    if (param_4 == (int *)0x0) {
      (*(code *)param_1)(0x4026f194,param_2,param_3,param_5,param_6,param_7);
      return;
    }
    if ((*(char *)(param_4 + 2) != '\0') &&
       (iVar1 = (*(code *)param_1)(param_4,param_2,param_3,param_5,param_6,param_7), iVar1 != 0))
    break;
    param_4 = (int *)*param_4;
  }
  return;
}



/* 402684bc FUN_402684bc */

/* Boundary evidence: original MIPS .pdata 402684bc..40268583. Semantic name remains unreviewed. */

bool FUN_402684bc(int param_1,undefined4 param_2,REGSAM param_3,PHKEY param_4)

{
  LSTATUS LVar1;
  wchar_t *pszFormat;
  wchar_t awStack_268 [298];
  uint local_14;
  
  local_14 = DAT_4026f418;
  if (param_1 == 1) {
    pszFormat = L"Comm\\%hs\\Parms\\TcpIp";
  }
  else {
    if (param_1 != 3) {
      FUN_4026e238(DAT_4026f418);
      return false;
    }
    pszFormat = L"Comm\\%hs\\Parms\\TcpIp6";
  }
  StringCchPrintfW(awStack_268,0x12a,pszFormat,param_2);
  LVar1 = RegOpenKeyExW((HKEY)0x80000002,awStack_268,0,param_3,param_4);
  FUN_4026e238(local_14);
  return LVar1 == 0;
}



/* 40268584 FUN_40268584 */

/* Boundary evidence: original MIPS .pdata 40268584..402685eb. Semantic name remains unreviewed. */

undefined4 FUN_40268584(HKEY param_1,LPCWSTR param_2,LPBYTE param_3)

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



/* 402685ec FUN_402685ec */

/* Boundary evidence: original MIPS .pdata 402685ec..40268687. Semantic name remains unreviewed. */

void FUN_402685ec(void)

{
  if (DAT_4026f12c != -1) {
    RegCloseKey((HKEY)DAT_4026f12c);
  }
  if (DAT_4026f130 != -1) {
    RegCloseKey((HKEY)DAT_4026f130);
  }
  if (DAT_4026f128 != -1) {
    RegCloseKey((HKEY)DAT_4026f128);
  }
  if (DAT_4026f124 != -1) {
    RegCloseKey((HKEY)DAT_4026f124);
  }
  return;
}



/* 40268688 FUN_40268688 */

/* Boundary evidence: original MIPS .pdata 40268688..402686d3. Semantic name remains unreviewed. */

void FUN_40268688(HLOCAL param_1)

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



/* 402686d4 FUN_402686d4 */

/* Boundary evidence: original MIPS .pdata 402686d4..4026876b. Semantic name remains unreviewed. */

void FUN_402686d4(undefined4 *param_1)

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



/* 4026876c FUN_4026876c */

/* Boundary evidence: original MIPS .pdata 4026876c..40268977. Semantic name remains unreviewed. */

void FUN_4026876c(LPVOID param_1)

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



/* 40268978 FUN_40268978 */

/* Boundary evidence: original MIPS .pdata 40268978..402689c3. Semantic name remains unreviewed. */

void FUN_40268978(HLOCAL param_1)

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



/* 402689c4 FUN_402689c4 */

int FUN_402689c4(int *param_1)

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



/* 40268a40 FUN_40268a40 */

/* Boundary evidence: original MIPS .pdata 40268a40..40268bb3. Semantic name remains unreviewed. */

uint FUN_40268a40(int param_1)

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



/* 40268bb4 GetAdapterOrderMap */

/* Boundary evidence: original MIPS .pdata 40268bb4..40268cab. Semantic name remains unreviewed. */

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



/* 40268cac FUN_40268cac */

/* Boundary evidence: original MIPS .pdata 40268cac..40268d03. Semantic name remains unreviewed. */

undefined4 FUN_40268cac(undefined4 param_1,int param_2)

{
  bool bVar1;
  undefined3 extraout_var;
  undefined4 uVar2;
  uint auStack_10 [2];
  
  uVar2 = 1;
  if (param_2 == 0) {
    FUN_402685ec();
  }
  else if ((param_2 == 1) && (bVar1 = FUN_40266aa8(auStack_10), CONCAT31(extraout_var,bVar1) == 0))
  {
    FUN_402685ec();
    uVar2 = 0;
  }
  return uVar2;
}



/* 40268d04 FUN_40268d04 */

/* Boundary evidence: original MIPS .pdata 40268d04..40268daf. Semantic name remains unreviewed. */

int * FUN_40268d04(void)

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



/* 40268db0 FUN_40268db0 */

/* Boundary evidence: original MIPS .pdata 40268db0..40268eeb. Semantic name remains unreviewed. */

undefined4 FUN_40268db0(HKEY param_1,LPCWSTR param_2,LPSTR param_3,int *param_4)

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



/* 40268eec FUN_40268eec */

/* Boundary evidence: original MIPS .pdata 40268eec..4026917b. Semantic name remains unreviewed. */

undefined4 FUN_40268eec(HKEY param_1,LPCWSTR param_2,int *param_3)

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
    goto LAB_4026913c;
  }
  _Str = LocalAlloc(0,local_30);
  if (_Str == (char *)0x0) {
    return 0;
  }
  iVar3 = FUN_40268db0(param_1,param_2,_Str,(int *)&local_30);
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
          FUN_4026d440(param_3,(char *)*puVar1,"");
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
              FUN_4026d440(param_3,pcVar5,"");
              sVar4 = strlen(pcVar5);
              iVar7 = iVar7 + 1;
              sVar6 = strlen(pcVar5 + sVar4 + 1);
              pcVar5 = pcVar5 + sVar4 + 1;
            } while (sVar6 != 0);
            if (iVar7 != 0) goto LAB_4026910c;
          }
        }
        iVar3 = 3;
      }
LAB_4026910c:
      LocalFree(hMem);
    }
  }
  LocalFree(_Str);
LAB_4026913c:
  if (iVar3 != 0) {
    return 0;
  }
  return 1;
}



/* 4026917c FUN_4026917c */

/* Boundary evidence: original MIPS .pdata 4026917c..402694ef. Semantic name remains unreviewed. */

int * FUN_4026917c(void)

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
  
  local_30 = DAT_4026f418;
  piVar2 = FUN_40268d04();
  if (piVar2 == (int *)0x0) {
    piVar2 = (int *)0x0;
  }
  else {
    piVar3 = FUN_4026d51c();
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
           (bVar1 = FUN_402684bc(1,piVar3 + 2,0x20019,&local_370), CONCAT31(extraout_var,bVar1) != 0
           )) {
          FUN_40268584(local_370,L"EnableDHCP",(LPBYTE)(piVar3 + 0x69));
          if (piVar3[0x69] != 0) {
            FUN_40268584(local_370,L"Lease",(LPBYTE)local_364);
            FUN_40268584(local_370,L"LeaseObtainedHigh",aBStack_354);
            FUN_40268584(local_370,L"LeaseObtainedLow",aBStack_358);
            iVar7 = FUN_40266b3c((undefined4 *)aBStack_358);
            piVar3[0x9e] = iVar7;
            piVar3[0x9f] = iVar7 + local_364[0];
          }
          local_364[1] = 0x10;
          iVar7 = FUN_40268db0(local_370,L"DhcpServer",aCStack_350,local_364 + 1);
          if (iVar7 != 0) {
            FUN_4026d440(piVar3 + 0x7f,aCStack_350,"");
          }
          local_36c = (wchar_t *)0x208;
          LVar4 = RegQueryValueExW(local_370,L"WINS",(LPDWORD)0x0,&DStack_368,(LPBYTE)local_238,
                                   (LPDWORD)&local_36c);
          if ((LVar4 == 0) && (local_238[0] != L'\0')) {
LAB_402693f8:
            piVar3[0x89] = 1;
            WideCharToMultiByte(0,0,local_238,0x104,&CStack_340,0x104,(LPCSTR)0x0,(LPBOOL)0x0);
            if (local_36c != (wchar_t *)0x0) {
              FUN_4026d440(piVar3 + 0x8a,&CStack_340,"");
              sVar5 = strlen(&CStack_340);
              if (sVar5 + 1 < (uint)local_36c >> 1) {
                sVar5 = strlen(&CStack_340);
                FUN_4026d440(piVar3 + 0x94,acStack_33f + sVar5,"");
              }
            }
          }
          else {
            local_36c = (wchar_t *)0x208;
            LVar4 = RegQueryValueExW(local_370,L"DhcpWINS",(LPDWORD)0x0,&DStack_368,
                                     (LPBYTE)local_238,(LPDWORD)&local_36c);
            if (LVar4 == 0) goto LAB_402693f8;
          }
          RegCloseKey(local_370);
        }
        piVar3 = (int *)*piVar3;
        piVar2 = local_35c;
      } while (piVar3 != (int *)0x0);
    }
  }
  FUN_4026e238(local_30);
  return piVar2;
}



/* 402694f0 FUN_402694f0 */

/* Boundary evidence: original MIPS .pdata 402694f0..4026964b. Semantic name remains unreviewed. */

undefined4 FUN_402694f0(HKEY param_1,int param_2)

{
  int iVar1;
  size_t sVar2;
  char *_Str;
  int *local_360;
  int local_35c;
  undefined4 local_358 [8];
  char local_338 [800];
  uint local_18;
  
  local_18 = DAT_4026f418;
  local_360 = (int *)0x320;
  memset(local_338,0,800);
  iVar1 = FUN_40268db0(param_1,L"DNS",local_338,(int *)&local_360);
  if (iVar1 == 0) {
    FUN_40268db0(param_1,L"DhcpDNS",local_338,(int *)&local_360);
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
        FUN_402674a0(&local_360,*(void **)(local_35c + 0x18),*(SIZE_T *)(local_35c + 0x10));
        freeaddrinfo(local_35c);
      }
      sVar2 = strlen(_Str);
      _Str = _Str + sVar2 + 1;
      local_338[0] = *_Str;
    }
  }
  FUN_4026e238(local_18);
  return 0;
}



/* 4026964c FUN_4026964c */

/* Boundary evidence: original MIPS .pdata 4026964c..40269a3f. Semantic name remains unreviewed. */

LSTATUS FUN_4026964c(int param_1,int param_2,int param_3,uint param_4)

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
  
  local_2c = DAT_4026f418;
  local_168 = (HKEY)0x0;
  LVar6 = 0;
  local_130[0] = L'\0';
  *(undefined4 *)(param_3 + 0x20) = 0;
  *(undefined4 *)(param_3 + 0x38) = 1;
  if (param_2 == 0) goto LAB_402699cc;
  bVar1 = FUN_402684bc(1,param_2,0x20019,&local_168);
  if (CONCAT31(extraout_var,bVar1) == 0) {
    LVar6 = 0x3eb;
  }
  else {
    local_164 = 0x102;
    LVar6 = RegQueryValueExW(local_168,L"Domain",(LPDWORD)0x0,&local_15c,(LPBYTE)local_130,
                             &local_164);
    if (LVar6 != 0) {
      if (LVar6 != 2) goto LAB_402699b4;
      local_164 = 0;
      local_15c = 1;
    }
    if (local_15c == 1) {
      if ((local_164 == 0) || (sVar3 = wcslen(local_130), sVar3 == 0)) {
        local_164 = 0x102;
        LVar6 = RegQueryValueExW(local_168,L"DhcpDomain",(LPDWORD)0x0,&local_15c,(LPBYTE)local_130,
                                 &local_164);
        if (LVar6 != 0) {
          if (LVar6 != 2) goto LAB_402699b4;
          local_164 = 0;
          local_130[0] = L'\0';
        }
      }
      iVar2 = FUN_40268584(local_168,L"RegistrationEnabled",(LPBYTE)&local_160);
      if ((iVar2 != 0) && (local_160 == 0)) {
        *(uint *)(param_3 + 0x38) = *(uint *)(param_3 + 0x38) & 0xfffffffe;
      }
      iVar2 = FUN_40268584(local_168,L"RegisterAdapterName",(LPBYTE)&local_160);
      if ((iVar2 != 0) && (local_160 != 0)) {
        *(uint *)(param_3 + 0x38) = *(uint *)(param_3 + 0x38) | 2;
      }
      if ((param_4 & 8) == 0) {
        if ((param_1 != 2) && (DAT_4026f634 != 0)) {
          local_158 = (HKEY)0x0;
          bVar1 = FUN_402684bc(3,param_2,0x20019,&local_158);
          if (CONCAT31(extraout_var_00,bVar1) != 0) {
            FUN_402694f0(local_158,param_3);
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
              FUN_402674a0(&local_154,local_150,0x1c);
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
          FUN_402694f0(local_168,param_3);
        }
      }
    }
    else {
      LVar6 = 0xd;
    }
  }
LAB_402699b4:
  if (local_168 != (HKEY)0x0) {
    RegCloseKey(local_168);
  }
LAB_402699cc:
  sVar3 = wcslen(local_130);
  hHeap = GetProcessHeap();
  _Dest = HeapAlloc(hHeap,0,(sVar3 + 1) * 2);
  *(wchar_t **)(param_3 + 0x20) = _Dest;
  if (_Dest != (wchar_t *)0x0) {
    wcscpy(_Dest,local_130);
  }
  FUN_4026e238(local_2c);
  return LVar6;
}



/* 40269a40 FUN_40269a40 */

/* Boundary evidence: original MIPS .pdata 40269a40..40269d6f. Semantic name remains unreviewed. */

undefined4
FUN_40269a40(int *param_1,int *param_2,char *param_3,char *param_4,undefined4 param_5,
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
          FUN_4026964c(param_15,(int)param_4,*param_1,param_7);
          iVar5 = *param_1;
          if (*(int *)(iVar5 + 0x20) != 0) {
            uVar4 = FUN_40267594(param_3);
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



/* 40269d70 FUN_40269d70 */

/* Boundary evidence: original MIPS .pdata 40269d70..40269f03. Semantic name remains unreviewed. */

undefined4
FUN_40269d70(int param_1,int *param_2,int *param_3,char *param_4,char *param_5,int param_6,
            int param_7,uint param_8,undefined4 param_9,undefined4 param_10,void *param_11,
            size_t param_12,wchar_t *param_13,wchar_t *param_14,void *param_15,int param_16)

{
  int iVar1;
  undefined4 uVar2;
  short *psVar3;
  
  while( true ) {
    if (param_1 == 0) {
      uVar2 = FUN_40269a40(param_2,param_3,param_4,param_5,param_6,param_7,param_8,param_9,param_10,
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
          goto LAB_40269eec;
          uVar2 = *(undefined4 *)((int)param_15 + 0x14);
        }
        *(undefined4 *)(psVar3 + 0xc) = uVar2;
      }
LAB_40269eec:
    }
  }
  *param_2 = param_1;
  return 0;
}



/* 40269f04 FUN_40269f04 */

/* Boundary evidence: original MIPS .pdata 40269f04..4026a2fb. Semantic name remains unreviewed. */

int FUN_40269f04(int param_1,int param_2,int *param_3,int *param_4,int *param_5,int *param_6,
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
  
  local_2c = DAT_4026f418;
  local_2a4 = (int *)0x40;
  local_2a0 = param_4;
  local_298 = param_3;
  if (*(int *)(param_2 + 0x48) != 0) goto LAB_40269f64;
  FUN_402672a8((undefined4 *)(param_1 + 0x18),acStack_280);
  _Src = (short *)(param_2 + 0x38);
  if (*(int *)(param_1 + 0x38) == 6) {
    if ((*(char *)_Src != ' ') || (*(char *)(param_2 + 0x39) != '\x02')) goto LAB_40269f64;
    piVar4 = *(int **)(param_2 + 0x3a);
    _Source = L"6to4 Tunneling Pseudo-Interface";
    local_29c = piVar4;
  }
  else {
    iVar1 = FUN_40266a24(_Src);
    if ((iVar1 == 0) &&
       (((*(ushort *)(param_2 + 0x40) & 0xfffd) != 0 || (*(short *)(param_2 + 0x42) != -0x1a2))))
    goto LAB_40269f64;
    piVar4 = *(int **)(param_2 + 0x44);
    _Source = L"Automatic Tunneling Pseudo-Interface";
    local_29c = piVar4;
    iVar1 = FUN_40266a24(_Src);
    if (iVar1 != 0) {
      local_2a4 = (int *)0x60;
    }
  }
  piVar2 = (int *)*param_5;
  if (piVar2 == (int *)0x0) {
LAB_4026a06c:
    _Str2 = (char *)FUN_4026720c(local_2a0,(ulong)piVar4,(int *)&local_2a0);
    if (_Str2 == (char *)0x0) {
LAB_40269f64:
      FUN_4026e238(local_2c);
      return 0;
    }
    wcscpy(awStack_230,_Source);
    if (*(uint *)(param_1 + 0x38) < 0xb) {
      uVar3 = *(undefined4 *)(&DAT_4026f134 + *(uint *)(param_1 + 0x38) * 4);
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
    iVar1 = FUN_40269a40((int *)&local_2a8,local_298,acStack_280,_Str2,0,
                         *(undefined4 *)(param_2 + 0x24),param_7,uVar3,
                         *(undefined4 *)(param_1 + 0xa4),&local_29c,4,_Source,awStack_230,
                         (void *)(param_1 + 0x60),param_8);
    if (iVar1 != 0) goto LAB_4026a2c0;
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
    if (piVar2 == (int *)0x0) goto LAB_4026a06c;
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
  iVar1 = FUN_40266f78(param_1,param_2,&local_2a0,&local_2a8,&local_29c,0,param_7);
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
    iVar1 = FUN_402676bc(auStack_290,(int)piVar4,piVar2,&local_2a4);
  }
LAB_4026a2c0:
  FUN_4026e238(local_2c);
  return iVar1;
}



/* 4026a2fc FUN_4026a2fc */

/* Boundary evidence: original MIPS .pdata 4026a2fc..4026a84b. Semantic name remains unreviewed. */

DWORD FUN_4026a2fc(int param_1,int *param_2,int *param_3,int *param_4,uint param_5,int param_6)

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
  
  local_2c = DAT_4026f418;
  iVar8 = *param_3;
  puVar6 = (ulong *)(param_1 + 0xd8);
  FUN_402672a8((undefined4 *)(param_1 + 0x18),acStack_440);
  iVar4 = *(int *)(param_1 + 0x38);
  _Source = L"Teredo Tunneling Pseudo-Interface";
  uVar7 = 4;
  if (iVar4 == 0) {
    pwVar2 = L"Loopback Pseudo-Interface";
LAB_4026a5b8:
    wcscpy(aWStack_338,pwVar2);
LAB_4026a5c0:
    pszSrc = acStack_440;
  }
  else {
    if (iVar4 == 3) {
      wcscpy(aWStack_338,L"Automatic Tunneling Pseudo-Interface");
      local_458 = 0;
      DVar1 = FUN_40267010(param_1,FUN_40269f04,param_2,param_4,&local_458,iVar8,param_5,param_6);
      if ((DVar1 == 0) && (local_458 == 0)) {
        DVar1 = FUN_40269a40(&local_458,param_2,acStack_440,acStack_440,0,
                             *(undefined4 *)(param_1 + 0x14),param_5,0x83,
                             *(undefined4 *)(param_1 + 0xa4),puVar6,*(size_t *)(param_1 + 0x2c),
                             aWStack_338,aWStack_338,(void *)(param_1 + 0x60),param_6);
      }
      goto LAB_4026a810;
    }
    if (iVar4 == 4) {
      pwVar2 = L"6over4 Pseudo-Interface";
LAB_4026a4b4:
      wcscpy(aWStack_338,pwVar2);
      pszSrc = (STRSAFE_LPCSTR)FUN_4026720c(param_4,*puVar6,&iStack_444);
      if (pszSrc == (char *)0x0) goto LAB_4026a5c0;
    }
    else {
      if (iVar4 == 5) {
        pwVar2 = L"Configured Tunnel Interface";
        goto LAB_4026a4b4;
      }
      if (iVar4 == 6) {
        wcscpy(aWStack_338,L"6to4 Pseudo-Interface");
        local_458 = 0;
        DVar1 = FUN_40267010(param_1,FUN_40269f04,param_2,param_4,&local_458,iVar8,param_5,param_6);
        if ((DVar1 == 0) && (local_458 == 0)) {
          DVar1 = FUN_40269a40(&local_458,param_2,acStack_440,acStack_440,0,
                               *(undefined4 *)(param_1 + 0x14),param_5,0x83,
                               *(undefined4 *)(param_1 + 0xa4),puVar6,*(size_t *)(param_1 + 0x2c),
                               aWStack_338,aWStack_338,(void *)(param_1 + 0x60),param_6);
        }
        goto LAB_4026a810;
      }
      pwVar2 = _Source;
      if (iVar4 == 7) goto LAB_4026a5b8;
      pszSrc = (STRSAFE_LPCSTR)FUN_402673bc(param_4,(undefined4 *)(param_1 + 0x18),aWStack_338);
      if (pszSrc != (STRSAFE_LPCSTR)0x0) {
        StringCchCopyA(acStack_440,0x104,pszSrc);
      }
    }
  }
  if ((param_5 & 0x20) == 0) {
    if (*(int *)(param_1 + 0x38) != 7) {
      if (*(int *)(param_1 + 0x38) != 0) {
        MultiByteToWideChar(0,0,acStack_440,-1,local_230,0x101);
        goto LAB_4026a63c;
      }
      _Source = L"Loopback Pseudo-Interface";
    }
    wcscpy(local_230,_Source);
  }
  else {
    local_230[0] = L'\0';
  }
LAB_4026a63c:
  if (*(uint *)(param_1 + 0x38) < 0xb) {
    uVar5 = *(undefined4 *)(&DAT_4026f134 + *(uint *)(param_1 + 0x38) * 4);
  }
  else {
    uVar5 = 1;
  }
  DVar1 = FUN_40269d70(iVar8,&local_458,param_2,acStack_440,pszSrc,0,*(int *)(param_1 + 0x14),
                       param_5,uVar5,*(undefined4 *)(param_1 + 0xa4),puVar6,
                       *(size_t *)(param_1 + 0x2c),aWStack_338,local_230,(void *)(param_1 + 0x60),
                       param_6);
  if (DVar1 == 0) {
    if (*(int *)(param_1 + 0x54) != 0) {
      *(uint *)(local_458 + 0x38) = *(uint *)(local_458 + 0x38) | 0x20;
    }
    if (*(uint *)(param_1 + 0x50) < 3) {
      uVar7 = *(undefined4 *)(&DAT_4026f170 + *(uint *)(param_1 + 0x50) * 4);
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
    DVar1 = FUN_40267010(param_1,FUN_40266f78,&local_450,&local_44c,&local_448,0,param_5,param_6);
    if ((DVar1 == 0) && ((param_5 & 0x10) != 0)) {
      piVar3 = (int *)(local_458 + 0x8c);
      iVar4 = *piVar3;
      local_454 = piVar3;
      while (iVar4 != 0) {
        local_454 = (int *)(*local_454 + 8);
        iVar4 = *local_454;
      }
      DVar1 = FUN_40267830(*(int *)(param_1 + 0x14),FUN_402676bc,piVar3,&local_454);
    }
  }
LAB_4026a810:
  FUN_4026e238(local_2c);
  return DVar1;
}



/* 4026a84c FUN_4026a84c */

/* Boundary evidence: original MIPS .pdata 4026a84c..4026aaab. Semantic name remains unreviewed. */

DWORD FUN_4026a84c(int param_1,int *param_2,int *param_3,uint param_4,int param_5,uint *param_6)

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
  
  local_24 = DAT_4026f418;
  iVar4 = *param_3;
  MultiByteToWideChar(0,0,(LPCSTR)(param_1 + 0x10c),-1,aWStack_330,0x80);
  DVar1 = FUN_4026481c((undefined2 *)auStack_690,*(uint *)(param_1 + 0x19c),0);
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
    DVar1 = FUN_40269d70(iVar4,&local_6d4,param_2,(char *)(param_1 + 8),(char *)(param_1 + 8),
                         *(int *)(param_1 + 0x19c),0,param_4,*(undefined4 *)(param_1 + 0x1a0),
                         local_488,(void *)(param_1 + 0x194),*(size_t *)(param_1 + 400),aWStack_330,
                         local_228,&local_6d0,param_5);
    if (DVar1 == 0) {
      if (local_470 < 6) {
        uVar3 = *(undefined4 *)(&DAT_4026f17c + local_470 * 4);
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
      DVar1 = FUN_402680b4(param_1,FUN_40267da4,&local_6dc,local_6d8,&local_6d8,local_6d4 + 0x38,
                           param_4,param_6);
      if ((DVar1 == 0) && ((param_4 & 0x10) != 0)) {
        local_6e0 = local_6d4 + 0x8c;
        DVar1 = FUN_402682f0(param_1,FUN_40268194,local_6e0,&local_6e0);
      }
    }
  }
  FUN_4026e238(local_24);
  return DVar1;
}



/* 4026aaac FUN_4026aaac */

/* Boundary evidence: original MIPS .pdata 4026aaac..4026acdb. Semantic name remains unreviewed. */

DWORD FUN_4026aaac(int param_1,uint param_2,undefined4 *param_3)

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
  piVar1 = FUN_4026917c();
  local_70 = &local_78;
  local_78 = (LPVOID)0x0;
  *param_3 = 0;
  if ((param_1 != 2) && ((param_2 & 8) == 0)) {
    local_74 = 0x40;
    local_6c = 0;
    DVar2 = FUN_4026d228(0x29,0x120078,(LPVOID)0x0,&local_6c,auStack_68,&local_74);
    DAT_4026f634 = (uint)(DVar2 == 0);
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
        goto LAB_4026ac68;
      }
      DVar2 = GetIpAddrTable(lpMem,&local_74,1);
    }
    if ((DVar2 != 0) ||
       (DVar2 = FUN_402683f4(FUN_4026a84c,&local_70,&local_78,piVar1,param_2,param_1,lpMem),
       DVar2 != 0)) goto LAB_4026ac68;
  }
  if (((param_1 != 0) && (param_1 != 0x17)) ||
     (DVar2 = FUN_40267a40(FUN_4026a2fc,&local_70,&local_78,piVar1,param_2,param_1), DVar2 == 0)) {
    *param_3 = local_78;
    local_78 = (LPVOID)0x0;
  }
LAB_4026ac68:
  if (lpMem != (uint *)0x0) {
    pvVar3 = GetProcessHeap();
    HeapFree(pvVar3,0,lpMem);
  }
  if (piVar1 != (int *)0x0) {
    FUN_402686d4(piVar1);
  }
  if (local_78 != (LPVOID)0x0) {
    FUN_4026876c(local_78);
  }
  return DVar2;
}



/* 4026acdc FUN_4026acdc */

/* Boundary evidence: original MIPS .pdata 4026acdc..4026aec7. Semantic name remains unreviewed. */

int * FUN_4026acdc(int param_1)

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
  
  local_20 = DAT_4026f418;
  _Dst = (int *)0x0;
  piVar2 = FUN_4026917c();
  piVar4 = piVar2;
  if (piVar2 != (int *)0x0) {
    do {
      if (((piVar4[0x67] == param_1) && ((char)piVar4[2] != '\0')) &&
         (bVar1 = FUN_402684bc(1,piVar4 + 2,0x20019,&local_50), CONCAT31(extraout_var,bVar1) != 0))
      {
        _Dst = LocalAlloc(0x40,0x34);
        if (_Dst == (int *)0x0) {
          FUN_402686d4(piVar2);
          RegCloseKey(local_50);
          FUN_4026e238(local_20);
          return (int *)0x0;
        }
        memset(_Dst,0,0x34);
        iVar3 = FUN_40268584(local_50,L"AutoCfg",(LPBYTE)_Dst);
        if (iVar3 == 0) {
          *_Dst = 1;
        }
        if (*_Dst != 0) {
          local_4c[1] = 0x10;
          local_4c[0] = 0x10;
          iVar3 = FUN_40268db0(local_50,L"AutoIP",aCStack_30,local_4c + 1);
          if (((iVar3 != 0) &&
              (iVar3 = FUN_40268db0(local_50,L"DhcpIPAddress",aCStack_40,local_4c), iVar3 != 0)) &&
             (iVar3 = strcmp(aCStack_30,aCStack_40), iVar3 == 0)) {
            _Dst[1] = 1;
          }
        }
        iVar3 = FUN_40268eec(local_50,L"DNS",_Dst + 3);
        if (iVar3 == 0) {
          FUN_40268eec(local_50,L"DhcpDNS",_Dst + 3);
        }
        RegCloseKey(local_50);
        break;
      }
      piVar4 = (int *)*piVar4;
    } while (piVar4 != (int *)0x0);
    FUN_402686d4(piVar2);
  }
  FUN_4026e238(local_20);
  return _Dst;
}



/* 4026aec8 FUN_4026aec8 */

/* Boundary evidence: original MIPS .pdata 4026aec8..4026b153. Semantic name remains unreviewed. */

undefined4 FUN_4026aec8(undefined4 *param_1,uint *param_2)

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
    piVar2 = FUN_4026917c();
    if (piVar2 == (int *)0x0) {
      uVar1 = 0xe8;
    }
    else {
      if (param_1 != (undefined4 *)0x0) {
        _Size = *param_2;
        uVar3 = FUN_402689c4(piVar2);
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
          FUN_402686d4(piVar2);
          return 0;
        }
      }
      uVar3 = FUN_402689c4(piVar2);
      *param_2 = uVar3;
      FUN_402686d4(piVar2);
      uVar1 = 0x6f;
    }
  }
  return uVar1;
}



/* 4026b154 FUN_4026b154 */

/* Boundary evidence: original MIPS .pdata 4026b154..4026b17b. Semantic name remains unreviewed. */

bool FUN_4026b154(undefined4 *param_1)

{
  return *(int *)*param_1 == -0x3ffffffb;
}



/* 4026b17c FUN_4026b17c */

/* Boundary evidence: original MIPS .pdata 4026b17c..4026b6a7. Semantic name remains unreviewed. */

DWORD FUN_4026b17c(int param_1,uint param_2,void *param_3,uint *param_4)

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
    DVar4 = FUN_4026aaac(param_1,param_2,local_34);
    pvVar1 = local_34[0];
    if (DVar4 == 0) {
      if (local_34[0] == (LPVOID)0x0) {
        DVar4 = 0xe8;
      }
      else {
        local_2c = local_34[0];
        if (param_3 != (void *)0x0) {
          _Size = *param_4;
          uVar2 = FUN_40268a40((int)local_34[0]);
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
            FUN_4026876c(pvVar1);
            return 0;
          }
        }
        uVar2 = FUN_40268a40((int)pvVar1);
        *param_4 = uVar2;
        FUN_4026876c(pvVar1);
        DVar4 = 0x6f;
      }
    }
    else if (local_34[0] != (LPVOID)0x0) {
      FUN_4026876c(local_34[0]);
    }
  }
  return DVar4;
}



/* 4026b6a8 FUN_4026b6a8 */

/* Boundary evidence: original MIPS .pdata 4026b6a8..4026b6cf. Semantic name remains unreviewed. */

bool FUN_4026b6a8(undefined4 *param_1)

{
  return *(int *)*param_1 == -0x3ffffffb;
}



/* 4026b6d0 FUN_4026b6d0 */

/* Boundary evidence: original MIPS .pdata 4026b6d0..4026b89f. Semantic name remains unreviewed. */

undefined4 FUN_4026b6d0(int param_1,void *param_2,uint *param_3)

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
    _Src = FUN_4026acdc(param_1);
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
          FUN_40268978(_Src);
          return 0;
        }
      }
      iVar3 = 0;
      for (piVar2 = (int *)_Src[3]; piVar2 != (int *)0x0; piVar2 = (int *)*piVar2) {
        iVar3 = iVar3 + 1;
      }
      *param_3 = iVar3 * 0x28 + 0x34;
      FUN_40268978(_Src);
      uVar1 = 0x6f;
    }
  }
  return uVar1;
}



/* 4026b8a0 FUN_4026b8a0 */

/* Boundary evidence: original MIPS .pdata 4026b8a0..4026b8ab. Semantic name remains unreviewed. */

undefined4 FUN_4026b8a0(void)

{
  return 1;
}



/* 4026b8ac FUN_4026b8ac */

/* Boundary evidence: original MIPS .pdata 4026b8ac..4026b9c3. Semantic name remains unreviewed. */

undefined4 FUN_4026b8ac(int *param_1)

{
  bool bVar1;
  int *piVar2;
  undefined3 extraout_var;
  int iVar3;
  int *piVar4;
  int iVar5;
  HKEY local_30 [2];
  
  iVar5 = 3;
  piVar2 = FUN_4026917c();
  piVar4 = piVar2;
  if (piVar2 != (int *)0x0) {
    do {
      if (((char)piVar4[2] != '\0') &&
         (bVar1 = FUN_402684bc(1,piVar4 + 2,0x20019,local_30), CONCAT31(extraout_var,bVar1) != 0)) {
        iVar3 = FUN_40268eec(local_30[0],L"DNS",param_1);
        if ((iVar3 != 0) || (iVar3 = FUN_40268eec(local_30[0],L"DhcpDNS",param_1), iVar3 != 0)) {
          iVar5 = 0;
        }
        RegCloseKey(local_30[0]);
      }
      piVar4 = (int *)*piVar4;
    } while (piVar4 != (int *)0x0);
    FUN_402686d4(piVar2);
    if (iVar5 == 0) {
      return 1;
    }
  }
  return 0;
}



/* 4026b9c4 FUN_4026b9c4 */

/* Boundary evidence: original MIPS .pdata 4026b9c4..4026ba7b. Semantic name remains unreviewed. */

char * FUN_4026b9c4(void)

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
    FUN_40268db0(DAT_4026f128,L"DNSDomain",name + 0x84,local_18);
    FUN_4026b8ac((int *)(name + 0x10c));
    FUN_40268584(DAT_4026f128,L"IPEnableRouter",pBVar1);
  }
  return name;
}



/* 4026ba7c FUN_4026ba7c */

/* Boundary evidence: original MIPS .pdata 4026ba7c..4026bc4b. Semantic name remains unreviewed. */

undefined4 FUN_4026ba7c(void *param_1,uint *param_2)

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
    _Src = FUN_4026b9c4();
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
          FUN_40268688(_Src);
          return 0;
        }
      }
      iVar3 = 0;
      for (piVar2 = *(int **)(_Src + 0x10c); piVar2 != (int *)0x0; piVar2 = (int *)*piVar2) {
        iVar3 = iVar3 + 1;
      }
      *param_2 = iVar3 * 0x28 + 0x248;
      FUN_40268688(_Src);
      uVar1 = 0x6f;
    }
  }
  return uVar1;
}



/* 4026bc4c FUN_4026bc4c */

/* Boundary evidence: original MIPS .pdata 4026bc4c..4026bc57. Semantic name remains unreviewed. */

undefined4 FUN_4026bc4c(void)

{
  return 1;
}



/* 4026bc58 Icmp6CreateFile */

BOOL Icmp6CreateFile(HANDLE IcmpHandle)

{
                    /* 0xbc58  42  Icmp6CreateFile
                       0xbc58  45  IcmpCloseHandle
                       0xbc58  46  IcmpCreateFile */
  return 1;
}



/* 4026bc60 IcmpParseReplies */

/* Boundary evidence: original MIPS .pdata 4026bc60..4026bd1f. Semantic name remains unreviewed. */

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



/* 4026bd20 FUN_4026bd20 */

/* Boundary evidence: original MIPS .pdata 4026bd20..4026bdc7. Semantic name remains unreviewed. */

ushort FUN_4026bd20(int param_1,int param_2)

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



/* 4026bdc8 IcmpSendEcho */

/* Boundary evidence: original MIPS .pdata 4026bdc8..4026bfc3. Semantic name remains unreviewed. */

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
  if (DAT_4026f414 != 0) {
    local_2c = ReplySize;
    dwErrCode = FUN_4026d228(6,2,hMem,&local_30,ReplyBuffer,&local_2c);
    if (dwErrCode != 0) {
      SetLastError(dwErrCode);
      goto LAB_4026bf8c;
    }
  }
  DVar2 = IcmpParseReplies(ReplyBuffer,ReplySize);
LAB_4026bf8c:
  LocalFree(hMem);
  return DVar2;
}



/* 4026bfc4 IcmpSendEcho2 */

/* Boundary evidence: original MIPS .pdata 4026bfc4..4026c1cb. Semantic name remains unreviewed. */

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
LAB_4026bff8:
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
    goto LAB_4026bff8;
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
  if (DAT_4026f414 != 0) {
    local_24 = ReplySize;
    dwErrCode = FUN_4026d228(6,2,hMem,&local_28,ReplyBuffer,&local_24);
    if (dwErrCode != 0) {
      SetLastError(dwErrCode);
      goto LAB_4026c198;
    }
  }
  uVar1 = FUN_4026bd20((int)ReplyBuffer,ReplySize);
  DVar2 = CONCAT22(extraout_var,uVar1);
LAB_4026c198:
  LocalFree(hMem);
  return DVar2;
}



/* 4026c1cc Icmp6ParseReplies */

/* Boundary evidence: original MIPS .pdata 4026c1cc..4026c23b. Semantic name remains unreviewed. */

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



/* 4026c23c Icmp6SendEcho2 */

/* Boundary evidence: original MIPS .pdata 4026c23c..4026c3bf. Semantic name remains unreviewed. */

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
      FUN_40265020();
      BVar1 = DeviceIoControl(DAT_4026f5a0,0x120000,_Dst,_Size + 0x40,in_stack_00000024,
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



/* 4026c3c0 FUN_4026c3c0 */

/* Boundary evidence: original MIPS .pdata 4026c3c0..4026c43b. Semantic name remains unreviewed. */

undefined4 FUN_4026c3c0(undefined4 param_1,int param_2)

{
  undefined4 *hMem;
  
  if (param_2 == 0) {
    DeleteCriticalSection((LPCRITICAL_SECTION)&DAT_4026f620);
    while (hMem = DAT_4026f430, DAT_4026f430 != (HLOCAL)0x0) {
      DAT_4026f430 = (undefined4 *)*DAT_4026f430;
      LocalFree(hMem);
    }
  }
  else if (param_2 == 1) {
    InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_4026f620);
    DAT_4026f414 = 1;
  }
  return 1;
}



/* 4026c43c FUN_4026c43c */

/* Boundary evidence: original MIPS .pdata 4026c43c..4026c61f. Semantic name remains unreviewed. */

undefined4 FUN_4026c43c(HMODULE param_1,int param_2)

{
  int iVar1;
  
  if (param_2 == 0) {
    if (DAT_4026f59c == 0) {
      return 1;
    }
    if (DAT_4026f5d4 != (HANDLE)0x0) {
      HeapDestroy(DAT_4026f5d4);
    }
    DeleteCriticalSection((LPCRITICAL_SECTION)&DAT_4026f600);
    DeleteCriticalSection((LPCRITICAL_SECTION)&DAT_4026f5c0);
    DeleteCriticalSection((LPCRITICAL_SECTION)&DAT_4026f580);
    DeleteCriticalSection((LPCRITICAL_SECTION)&DAT_4026f5e0);
    if (DAT_4026f5a4 != 0) {
      FUN_4026457c();
    }
    if (DAT_4026f5ac != 0) {
      FUN_402645d0();
    }
    FUN_40268cac(param_1,0);
    DAT_4026f59c = 0;
    iVar1 = FUN_4026c3c0(param_1,0);
    if (iVar1 != 0) {
      return 1;
    }
  }
  else {
    if (param_2 != 1) {
      return 1;
    }
    DAT_4026f59c = 0;
    DisableThreadLibraryCalls(param_1);
    iVar1 = FUN_4026c3c0(param_1,1);
    if (iVar1 != 0) {
      DAT_4026f5d4 = HeapCreate(0,0x1000,0);
      if (DAT_4026f5d4 != (HANDLE)0x0) {
        InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_4026f600);
        InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_4026f5c0);
        InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_4026f580);
        InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_4026f5e0);
        DAT_4026f5b8 = 0;
        DAT_4026f5d8 = 0;
        DAT_4026f5dc = 0;
        DAT_4026f594 = 0;
        DAT_4026f614 = 0;
        FUN_4026cae4();
        DAT_4026f59c = 1;
        DAT_4026f5a4 = 0;
        DAT_4026f5b0 = param_1;
        return 1;
      }
      FUN_4026c3c0(param_1,0);
    }
  }
  return 0;
}



/* 4026c620 FUN_4026c620 */

undefined4 FUN_4026c620(void)

{
  return 0;
}



/* 4026c6c0 FUN_4026c6c0 */

/* Boundary evidence: original MIPS .pdata 4026c6c0..4026c81f. Semantic name remains unreviewed. */

int FUN_4026c6c0(int param_1,int param_2)

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



/* 4026c820 FUN_4026c820 */

/* Boundary evidence: original MIPS .pdata 4026c820..4026c8df. Semantic name remains unreviewed. */

int FUN_4026c820(uint *param_1,uint *param_2)

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



/* 4026ca40 FUN_4026ca40 */

int FUN_4026ca40(uint param_1,uint param_2)

{
  uint *puVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  
  uVar5 = 0x3fffffff;
  uVar3 = 0;
  uVar4 = uVar5;
  puVar1 = DAT_4026f42c;
  if (*DAT_4026f42c != 0) {
    do {
      uVar2 = puVar1[1];
      if (((param_1 == uVar2) && (uVar5 = uVar3, uVar4 != 0x3fffffff)) ||
         ((param_2 == uVar2 && (uVar4 = uVar3, uVar5 != 0x3fffffff)))) break;
      uVar3 = uVar3 + 1;
      puVar1 = puVar1 + 1;
    } while (uVar3 < *DAT_4026f42c);
  }
  return uVar5 - uVar4;
}



/* 4026caa4 FUN_4026caa4 */

/* Boundary evidence: original MIPS .pdata 4026caa4..4026cac3. Semantic name remains unreviewed. */

void FUN_4026caa4(int param_1,int param_2)

{
  FUN_4026ca40(*(uint *)(param_1 + 0x200),*(uint *)(param_2 + 0x200));
  return;
}



/* 4026cac4 FUN_4026cac4 */

/* Boundary evidence: original MIPS .pdata 4026cac4..4026cae3. Semantic name remains unreviewed. */

void FUN_4026cac4(int param_1,int param_2)

{
  FUN_4026ca40(*(uint *)(param_1 + 4),*(uint *)(param_2 + 4));
  return;
}



/* 4026cae4 FUN_4026cae4 */

void FUN_4026cae4(void)

{
  undefined4 *puVar1;
  int iVar2;
  
  puVar1 = &DAT_4026f440;
  iVar2 = 0x25;
  do {
    puVar1[1] = puVar1;
    *puVar1 = puVar1;
    iVar2 = iVar2 + -1;
    puVar1 = puVar1 + 2;
  } while (iVar2 != 0);
  return;
}



/* 4026cb0c FUN_4026cb0c */

undefined4 * FUN_4026cb0c(uint param_1)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)(&DAT_4026f440)[(param_1 % 0x25) * 2];
  while( true ) {
    if (puVar1 == &DAT_4026f440 + (param_1 % 0x25) * 2) {
      return (undefined4 *)0x0;
    }
    if (puVar1[2] == param_1) break;
    puVar1 = (undefined4 *)*puVar1;
  }
  return puVar1;
}



/* 4026cb58 FUN_4026cb58 */

/* Boundary evidence: original MIPS .pdata 4026cb58..4026cc0b. Semantic name remains unreviewed. */

undefined4 FUN_4026cb58(uint param_1,int param_2)

{
  undefined4 *puVar1;
  int *piVar2;
  int *piVar3;
  
  puVar1 = FUN_4026cb0c(param_1);
  if (puVar1 == (undefined4 *)0x0) {
    piVar2 = HeapAlloc(DAT_4026f5d4,0,0x14);
    if (piVar2 == (int *)0x0) {
      return 8;
    }
    piVar2[4] = -1;
    piVar2[2] = param_1;
    piVar2[3] = param_2;
    piVar3 = &DAT_4026f440 + (param_1 % 0x25) * 2;
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



/* 4026cc0c FUN_4026cc0c */

/* Boundary evidence: original MIPS .pdata 4026cc0c..4026ccbf. Semantic name remains unreviewed. */

undefined4 FUN_4026cc0c(uint param_1,int param_2)

{
  undefined4 *puVar1;
  int *piVar2;
  int *piVar3;
  
  puVar1 = FUN_4026cb0c(param_1);
  if (puVar1 == (undefined4 *)0x0) {
    piVar2 = HeapAlloc(DAT_4026f5d4,0,0x14);
    if (piVar2 == (int *)0x0) {
      return 8;
    }
    piVar2[3] = -1;
    piVar2[2] = param_1;
    piVar2[4] = param_2;
    piVar3 = &DAT_4026f440 + (param_1 % 0x25) * 2;
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



/* 4026ccc0 FUN_4026ccc0 */

/* Boundary evidence: original MIPS .pdata 4026ccc0..4026ccf3. Semantic name remains unreviewed. */

undefined4 FUN_4026ccc0(uint param_1)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  puVar1 = FUN_4026cb0c(param_1);
  if (puVar1 == (undefined4 *)0x0) {
    uVar2 = 0xffffffff;
  }
  else {
    uVar2 = puVar1[4];
  }
  return uVar2;
}



/* 4026ccf4 FUN_4026ccf4 */

/* Boundary evidence: original MIPS .pdata 4026ccf4..4026cd27. Semantic name remains unreviewed. */

undefined4 FUN_4026ccf4(uint param_1)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  puVar1 = FUN_4026cb0c(param_1);
  if (puVar1 == (undefined4 *)0x0) {
    uVar2 = 0xffffffff;
  }
  else {
    uVar2 = puVar1[3];
  }
  return uVar2;
}



/* 4026cd28 FUN_4026cd28 */

/* Boundary evidence: original MIPS .pdata 4026cd28..4026cf1b. Semantic name remains unreviewed. */

undefined4 FUN_4026cd28(void)

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
  
  local_24 = DAT_4026f418;
  lpMem = FUN_40262d48(&local_3b8);
  if (lpMem == (LPVOID)0x0) {
    FUN_4026e238(local_24);
    uVar1 = 0x1f;
  }
  else {
    local_3b4 = 0x24;
    piVar6 = &DAT_4026f440;
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
    } while (piVar4 < (int *)0x4026f568);
    uVar5 = 0;
    if (local_3b8 != 0) {
      piVar4 = (int *)((int)lpMem + 4);
      do {
        if (piVar4[-1] == 0x200) {
          local_3b0[0] = 0x15c;
          local_3a4 = *piVar4;
          memset(auStack_394,0,0x10);
          DVar2 = FUN_402629ac(2,&local_3a8,&local_3b4,local_180,local_3b0);
          if (DVar2 == 0) {
            FUN_4026cc0c(local_180[0],*piVar4);
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
          HeapFree(DAT_4026f5d4,0,piVar3);
        }
      }
      piVar6 = piVar6 + 2;
    } while (piVar6 < (int *)0x4026f568);
    DAT_4026f5d8 = GetTickCount();
    HeapFree(DAT_4026f5d4,0,lpMem);
    FUN_4026e238(local_24);
    uVar1 = 0;
  }
  return uVar1;
}



/* 4026cf1c FUN_4026cf1c */

/* Boundary evidence: original MIPS .pdata 4026cf1c..4026d07f. Semantic name remains unreviewed. */

DWORD FUN_4026cf1c(void)

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
  
  if (DAT_4026f5dc != (LPVOID)0x0) {
    HeapFree(DAT_4026f5d4,1,DAT_4026f5dc);
    DAT_4026f5dc = (LPVOID)0x0;
  }
  DVar1 = FUN_4026419c((int *)&DAT_4026f5dc,(int *)&DAT_4026f594,DAT_4026f5d4,0,0);
  if (DVar1 == 0) {
    uVar3 = 0;
    local_50[1] = 0x24;
    if (DAT_4026f594 != 0) {
      iVar2 = 0;
      do {
        local_38 = 0x200;
        local_34 = 0x100;
        local_40 = 0x280;
        local_30 = 1;
        local_3c = *(undefined4 *)(iVar2 + (int)DAT_4026f5dc);
        local_50[0] = 8;
        memset(auStack_2c,0,0x10);
        DVar1 = FUN_402629ac(2,&local_40,local_50 + 1,auStack_48,local_50);
        if (DVar1 != 0) {
          return DVar1;
        }
        FUN_4026cb58(local_44,*(int *)(iVar2 + (int)DAT_4026f5dc));
        uVar3 = uVar3 + 1;
        iVar2 = iVar2 + 4;
      } while (uVar3 < DAT_4026f594);
    }
    DAT_4026f5b8 = GetTickCount();
    DVar1 = 0;
  }
  else {
    DAT_4026f5dc = (LPVOID)0x0;
    DVar1 = 0x3eb;
  }
  return DVar1;
}



/* 4026d080 FUN_4026d080 */

/* Boundary evidence: original MIPS .pdata 4026d080..4026d15b. Semantic name remains unreviewed. */

DWORD FUN_4026d080(int param_1,undefined4 *param_2)

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
  
  local_18 = DAT_4026f418;
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
  DVar3 = FUN_402629ac(0x17,auStack_48,local_70,auStack_68,local_70 + 1);
  if (DVar3 == 0) {
    *param_2 = local_50;
    FUN_4026e238(local_18);
    DVar3 = 0;
  }
  else {
    FUN_4026e238(local_18);
  }
  return DVar3;
}



/* 4026d15c FUN_4026d15c */

/* Boundary evidence: original MIPS .pdata 4026d15c..4026d227. Semantic name remains unreviewed. */

DWORD FUN_4026d15c(DWORD param_1,LPVOID param_2,DWORD *param_3,LPVOID param_4,DWORD *param_5)

{
  DWORD DVar1;
  BOOL BVar2;
  DWORD local_20 [2];
  
  FUN_40265020();
  if (DAT_4026f5a0 == (HANDLE)0xffffffff) {
    DVar1 = 2;
  }
  else {
    BVar2 = DeviceIoControl(DAT_4026f5a0,param_1,param_2,*param_3,param_4,*param_5,local_20,
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



/* 4026d228 FUN_4026d228 */

/* Boundary evidence: original MIPS .pdata 4026d228..4026d2d3. Semantic name remains unreviewed. */

DWORD FUN_4026d228(int param_1,DWORD param_2,LPVOID param_3,DWORD *param_4,LPVOID param_5,
                  DWORD *param_6)

{
  DWORD DVar1;
  int iVar2;
  
  if (param_1 == 0x29) {
    DVar1 = FUN_4026d15c(param_2,param_3,param_4,param_5,param_6);
  }
  else {
    FUN_40265020();
    iVar2 = WSAControl(6,param_2,param_3,param_4,param_5,param_6);
    if (iVar2 == 0) {
      DVar1 = 0;
    }
    else {
      DVar1 = FUN_4026294c(iVar2);
    }
  }
  return DVar1;
}



/* 4026d2d4 FUN_4026d2d4 */

/* Boundary evidence: original MIPS .pdata 4026d2d4..4026d31f. Semantic name remains unreviewed. */

void FUN_4026d2d4(uint param_1,char *param_2)

{
  sprintf(param_2,"%d.%d.%d.%d",param_1 & 0xff,param_1 >> 8 & 0xff,param_1 >> 0x10 & 0xff,
          param_1 >> 0x18);
  return;
}



/* 4026d320 FUN_4026d320 */

/* Boundary evidence: original MIPS .pdata 4026d320..4026d393. Semantic name remains unreviewed. */

void FUN_4026d320(char *param_1,int param_2,char *param_3)

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



/* 4026d394 FUN_4026d394 */

/* Boundary evidence: original MIPS .pdata 4026d394..4026d43f. Semantic name remains unreviewed. */

undefined4 FUN_4026d394(undefined4 *param_1,uint param_2,uint param_3,undefined4 param_4)

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
  FUN_4026d2d4(param_2,(char *)(param_1 + 1));
  FUN_4026d2d4(param_3,(char *)(param_1 + 5));
  param_1[9] = param_4;
  *param_1 = 0;
  return 1;
}



/* 4026d440 FUN_4026d440 */

/* Boundary evidence: original MIPS .pdata 4026d440..4026d51b. Semantic name remains unreviewed. */

undefined4 FUN_4026d440(int *param_1,char *param_2,char *param_3)

{
  undefined4 uVar1;
  int iVar2;
  int *piVar3;
  
  if ((char)param_1[1] == '\0') {
LAB_4026d4dc:
    FUN_4026d320((char *)(param_1 + 1),0x10,param_2);
    FUN_4026d320((char *)(param_1 + 5),0x10,param_3);
    uVar1 = 1;
  }
  else {
    iVar2 = *param_1;
    piVar3 = param_1;
    while (iVar2 != 0) {
      iVar2 = strncmp((char *)(piVar3 + 1),param_2,0x10);
      if (iVar2 == 0) goto LAB_4026d4d0;
      piVar3 = (int *)*piVar3;
      iVar2 = *piVar3;
    }
    iVar2 = strncmp((char *)(piVar3 + 1),param_2,0x10);
    if (iVar2 != 0) {
      param_1 = LocalAlloc(0x40,0x28);
      *piVar3 = (int)param_1;
      if (param_1 != (int *)0x0) goto LAB_4026d4dc;
    }
LAB_4026d4d0:
    uVar1 = 0;
  }
  return uVar1;
}



/* 4026d51c FUN_4026d51c */

/* Boundary evidence: original MIPS .pdata 4026d51c..4026de9f. Semantic name remains unreviewed. */

int * FUN_4026d51c(void)

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
  
  local_2c = DAT_4026f418;
  piVar13 = (int *)0x0;
  lpMem = (uint *)0x0;
  local_200 = (int *)0x0;
  hMem = FUN_4026dea0(&local_240);
  if (hMem == (DWORD *)0x0) goto LAB_4026ddec;
  local_20c = GetAdapterOrderMap();
  if (local_20c == (uint *)0x0) {
    LocalFree(hMem);
    goto LAB_4026ddec;
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
        DVar2 = FUN_4026d228(6,0,&local_230,&local_244,&local_204,&local_248);
        if ((DVar2 == 0) && (local_204 == 0x202)) {
          memset(&local_230,0,0x24);
          local_228 = 0x200;
          local_220 = 1;
          local_224 = 0x100;
          local_244 = 0x24;
          local_248 = 0xe1;
          local_230 = DVar11;
          local_22c = DVar14;
          DVar2 = FUN_4026d228(6,0,&local_230,&local_244,&local_110,&local_248);
          if (((DVar2 == 0) || (DVar2 == 0xea)) && (local_10c != 0x18)) {
            piVar3 = LocalAlloc(0x40,0x280);
            if (piVar3 == (int *)0x0) goto LAB_4026ddb4;
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
      if (lpMem == (uint *)0x0) goto LAB_4026ddb4;
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
            DVar14 = FUN_4026d228(6,0,&local_230,&local_244,&local_1fc,&local_248);
            if ((DVar14 == 0) && (local_1fc == 0x303)) {
              memset(&local_230,0,0x24);
              local_220 = 1;
              local_224 = 0x100;
              local_244 = 0x24;
              local_228 = 0x200;
              local_248 = 0x5c;
              local_230 = DVar2;
              local_22c = DVar11;
              DVar14 = FUN_4026d228(6,0,&local_230,&local_244,auStack_1d0,&local_248);
              if ((DVar14 == 0) && (local_248 == 0x5c)) {
                if (local_17c != 0) {
                  local_248 = (local_17c + 10) * 0x18;
                  piVar3 = LocalAlloc(0,local_248);
                  if (piVar3 == (int *)0x0) goto LAB_4026ddb4;
                  memset(&local_230,0,0x24);
                  local_224 = 0x100;
                  local_244 = 0x24;
                  local_220 = 0x102;
                  local_228 = 0x200;
                  local_230 = DVar2;
                  local_22c = DVar11;
                  DVar2 = FUN_4026d228(6,0,&local_230,&local_244,piVar3,&local_248);
                  if (DVar2 != 0) {
                    LocalFree(piVar3);
                    uVar18 = local_234;
                    goto LAB_4026dd40;
                  }
                  uVar18 = local_248 / 0x18;
                  if (local_17c <= local_248 / 0x18) {
                    uVar18 = local_17c;
                  }
                  uVar15 = 0;
                  if (uVar18 != 0) {
                    puVar17 = (uint *)(piVar3 + 2);
LAB_4026da9c:
                    if (piVar13 != (int *)0x0) {
                      piVar12 = piVar13;
                      do {
                        if (piVar12[0x67] == puVar17[-1]) {
                          iVar7 = FUN_4026d394(piVar12 + 0x6b,puVar17[-2],*puVar17,
                                               (uint)(ushort)puVar17[3]);
                          if (iVar7 == 0) goto LAB_4026ddac;
                          uVar10 = 0;
                          if (*lpMem != 0) {
                            puVar8 = lpMem;
                            goto LAB_4026dafc;
                          }
                          break;
                        }
                        piVar12 = (int *)*piVar12;
                      } while (piVar12 != (int *)0x0);
                    }
                    goto LAB_4026db28;
                  }
LAB_4026db38:
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
                    if (piVar3 == (int *)0x0) goto LAB_4026ddb4;
                    DVar5 = FUN_4026d228(6,0,&local_230,&local_244,piVar3,&local_248);
                    if (DVar5 != 0) {
                      if (DVar5 != 0xea) goto LAB_4026ddac;
                      memset(&local_1f8,0,0x24);
                      local_1f0 = 0x200;
                      local_1ec = 0x100;
                      local_1e8 = 1;
                      local_208 = 0x24;
                      local_238 = 0x5c;
                      local_1f8 = DVar2;
                      local_1f4 = DVar11;
                      DVar5 = FUN_4026d228(6,0,&local_1f8,&local_208,auStack_170,&local_238);
                      if ((DVar5 != 0) || (local_238 != 0x5c)) goto LAB_4026ddac;
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
                             (iVar7 = FUN_4026d394(piVar6 + 0x75,piVar12[6],0,0), iVar7 == 0))
                          goto LAB_4026ddac;
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
LAB_4026dd40:
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
      FUN_4026e238(local_2c);
      return piVar12;
    }
  }
LAB_4026ddb4:
  LocalFree(hMem);
  LocalFree(local_20c);
  if (lpMem != (uint *)0x0) {
    pvVar4 = GetProcessHeap();
    HeapFree(pvVar4,0,lpMem);
  }
  FUN_402686d4(piVar13);
LAB_4026ddec:
  FUN_4026e238(local_2c);
  return (int *)0x0;
  while (uVar10 = uVar10 + 1, uVar10 < *lpMem) {
LAB_4026dafc:
    puVar8 = puVar8 + 1;
    if (puVar17[-1] == *puVar8) {
      piVar12[0x69] = 0x91;
      break;
    }
  }
LAB_4026db28:
  uVar15 = uVar15 + 1;
  puVar17 = puVar17 + 6;
  if (uVar18 <= uVar15) goto LAB_4026db38;
  goto LAB_4026da9c;
LAB_4026ddac:
  LocalFree(piVar3);
  goto LAB_4026ddb4;
}



/* 4026dea0 FUN_4026dea0 */

/* WARNING: Type propagation algorithm not settling */
/* Boundary evidence: original MIPS .pdata 4026dea0..4026df8f. Semantic name remains unreviewed. */

HLOCAL FUN_4026dea0(uint *param_1)

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
    DVar1 = FUN_4026d228(6,0,local_3c + 1,local_3c,hMem,&local_40);
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



/* 4026e0d0 entry */

/* Boundary evidence: original MIPS .pdata 4026e0d0..4026e143. Semantic name remains unreviewed. */

undefined4 entry(HMODULE param_1,int param_2)

{
  undefined4 uVar1;
  
  if (param_2 == 1) {
    FUN_4026e144();
    FUN_4026e418();
  }
  uVar1 = FUN_4026c43c(param_1,param_2);
  if (param_2 == 0) {
    FUN_4026e3a0();
  }
  return uVar1;
}



/* 4026e144 FUN_4026e144 */

/* Boundary evidence: original MIPS .pdata 4026e144..4026e1b7. Semantic name remains unreviewed. */

void FUN_4026e144(void)

{
  uint uVar1;
  
  if ((DAT_4026f418 == 0) || (DAT_4026f418 == 0xb064)) {
    uVar1 = __security_gen_cookie2();
    DAT_4026f418 = uVar1 >> 0x10 ^ uVar1 & 0xffff;
    if (DAT_4026f418 == 0) {
      DAT_4026f418 = 0xb064;
    }
  }
  DAT_4026f41c = ~DAT_4026f418;
  return;
}



/* 4026e1b8 FUN_4026e1b8 */

/* Boundary evidence: original MIPS .pdata 4026e1b8..4026e20b. Semantic name remains unreviewed. */

void FUN_4026e1b8(int param_1,undefined4 param_2,uint *param_3)

{
  if ((*param_3 & 1) != 0) {
    param_1 = ((-param_3[2] & param_3[1] + param_1) - (param_3[1] + param_1)) + param_1;
  }
  FUN_4026e238(*(uint *)(param_1 + (*param_3 & 0xfffffffc)));
  return;
}



/* 4026e20c FUN_4026e20c */

/* Boundary evidence: original MIPS .pdata 4026e20c..4026e237. Semantic name remains unreviewed. */

undefined4 FUN_4026e20c(undefined4 param_1,int param_2,undefined4 param_3,int param_4)

{
  FUN_4026e1b8(param_2,param_4,*(uint **)(*(int *)(param_4 + 4) + 0xc));
  return 1;
}



/* 4026e238 FUN_4026e238 */

/* Boundary evidence: original MIPS .pdata 4026e238..4026e27f. Semantic name remains unreviewed. */

void FUN_4026e238(uint param_1)

{
  if ((param_1 == DAT_4026f418) && (param_1 >> 0x10 == 0)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __report_gsfailure();
}



/* 4026e280 FUN_4026e280 */

/* Boundary evidence: original MIPS .pdata 4026e280..4026e39f. Semantic name remains unreviewed. */

void FUN_4026e280(UINT param_1,int param_2,int param_3)

{
  LPCRITICAL_SECTION lpCriticalSection;
  undefined4 *_Memory;
  
  DAT_4026f434 = (undefined1)param_3;
  if (param_2 == 0) {
    _Memory = DAT_4026f63c;
    if (DAT_4026f63c != (undefined4 *)0x0) {
      while (DAT_4026f638 = DAT_4026f638 + -1, _Memory <= DAT_4026f638) {
        if ((code *)*DAT_4026f638 != (code *)0x0) {
          (*(code *)*DAT_4026f638)();
          _Memory = DAT_4026f63c;
        }
      }
      free(_Memory);
      DAT_4026f638 = (undefined4 *)0x0;
      DAT_4026f63c = (undefined4 *)0x0;
    }
    FUN_4026e3c4((undefined4 *)&DAT_40261010,(undefined4 *)&DAT_40261014);
  }
  FUN_4026e3c4((undefined4 *)&DAT_40261018,(undefined4 *)&DAT_4026101c);
  if (param_3 == 0) {
    TerminateProcess((HANDLE)0x42,param_1);
  }
  else {
    lpCriticalSection = (LPCRITICAL_SECTION)InterlockedExchange((LONG *)&DAT_4026f640,0);
    if (lpCriticalSection != (LPCRITICAL_SECTION)0x0) {
      DeleteCriticalSection(lpCriticalSection);
      free(lpCriticalSection);
    }
  }
  return;
}



/* 4026e3a0 FUN_4026e3a0 */

/* Boundary evidence: original MIPS .pdata 4026e3a0..4026e3c3. Semantic name remains unreviewed. */

void FUN_4026e3a0(void)

{
  FUN_4026e280(0,0,1);
  return;
}



/* 4026e3c4 FUN_4026e3c4 */

/* Boundary evidence: original MIPS .pdata 4026e3c4..4026e417. Semantic name remains unreviewed. */

void FUN_4026e3c4(undefined4 *param_1,undefined4 *param_2)

{
  for (; param_1 < param_2; param_1 = param_1 + 1) {
    if ((code *)*param_1 != (code *)0x0) {
      (*(code *)*param_1)();
    }
  }
  return;
}



/* 4026e418 FUN_4026e418 */

/* Boundary evidence: original MIPS .pdata 4026e418..4026e453. Semantic name remains unreviewed. */

void FUN_4026e418(void)

{
  FUN_4026e3c4((undefined4 *)&DAT_40261008,(undefined4 *)&DAT_4026100c);
  FUN_4026e3c4((undefined4 *)&DAT_40261000,(undefined4 *)&DAT_40261004);
  return;
}


