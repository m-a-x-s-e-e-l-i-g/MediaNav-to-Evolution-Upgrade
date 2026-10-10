/* Automatic Ghidra pseudocode. Not original source; not runtime-verified. */

/* c04611c4 FUN_c04611c4 */

/* Boundary evidence: original MIPS .pdata c04611c4..c046121b. Semantic name remains unreviewed. */

undefined4 FUN_c04611c4(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 local_10 [2];
  
  iVar1 = NdisAllocateMemory(local_10,param_1,0,param_4,DAT_c04651a0,DAT_c04651a4);
  if (iVar1 != 0) {
    local_10[0] = 0;
  }
  return local_10[0];
}



/* c046121c FUN_c046121c */

/* Boundary evidence: original MIPS .pdata c046121c..c046123f. Semantic name remains unreviewed. */

void FUN_c046121c(undefined4 param_1,undefined4 param_2)

{
  NdisFreeMemory(param_1,param_2,0);
  return;
}



/* c0461240 FUN_c0461240 */

/* Boundary evidence: original MIPS .pdata c0461240..c04612ab. Semantic name remains unreviewed. */

undefined4 FUN_c0461240(HMODULE param_1,int param_2)

{
  if (param_2 == 0) {
    DeleteCriticalSection((LPCRITICAL_SECTION)&DAT_c0465480);
  }
  else if (param_2 == 1) {
    DAT_c0465494 = param_1;
    InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_c0465480);
    DisableThreadLibraryCalls(param_1);
  }
  return 1;
}



/* c04612ac FUN_c04612ac */

/* Boundary evidence: original MIPS .pdata c04612ac..c046132f. Semantic name remains unreviewed. */

void FUN_c04612ac(int param_1)

{
  undefined1 auStack_18 [8];
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0465480);
  NdisMCancelTimer(param_1 + 0x10,auStack_18);
  NdisFreeMemory(param_1,0xd0,0);
  DAT_c04654a0 = DAT_c04654a0 + -1;
  DAT_c0465498 = 0;
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0465480);
  return;
}



/* c0461330 FUN_c0461330 */

/* Boundary evidence: original MIPS .pdata c0461330..c0461743. Semantic name remains unreviewed. */

int FUN_c0461330(undefined4 param_1,uint *param_2,int *param_3,uint param_4,undefined4 param_5,
                undefined4 param_6)

{
  int iVar1;
  undefined4 *puVar2;
  uint uVar3;
  int local_60;
  int local_5c;
  undefined4 local_58 [2];
  undefined2 local_50;
  undefined2 local_4e;
  wchar_t *local_4c;
  undefined2 local_48;
  undefined2 local_46;
  wchar_t *local_44;
  undefined2 local_40;
  undefined2 local_3e;
  wchar_t *local_3c;
  undefined2 local_38;
  undefined2 local_36;
  wchar_t *local_34;
  undefined2 local_30;
  undefined2 local_2e;
  wchar_t *local_2c;
  undefined2 local_28;
  undefined2 local_26;
  wchar_t *local_24;
  undefined2 local_20;
  undefined2 local_1e;
  wchar_t *local_1c;
  
  local_48 = 0x20;
  local_40 = 0x20;
  local_4c = L"MaxFrameSize";
  local_44 = L"MaxSendFrameSize";
  local_3c = L"MaxRecvFrameSize";
  local_36 = 0x24;
  local_46 = 0x22;
  local_3e = 0x22;
  local_38 = 0x22;
  local_1c = L"MaxTxPackets";
  local_34 = L"ReceiveBufferSize";
  local_2e = 0x32;
  local_28 = 0x32;
  local_30 = 0x30;
  local_26 = 0x34;
  local_2c = L"ReceiveThreadPriority256";
  local_50 = 0x18;
  local_4e = 0x1a;
  local_20 = 0x18;
  local_1e = 0x1a;
  local_24 = L"TransmitThreadPriority256";
  if (DAT_c04654a0 == 0) {
    uVar3 = 0;
    if (param_4 != 0) {
      do {
        if (*param_3 == 3) {
          *param_2 = uVar3;
          puVar2 = (undefined4 *)FUN_c04611c4(0xd0,param_2,param_3,param_4);
          if (puVar2 == (undefined4 *)0x0) {
            return -0x3fffff66;
          }
          *puVar2 = param_5;
          NdisOpenConfiguration(&local_60,local_58,param_6);
          if (local_60 != 0) {
            NdisFreeMemory(puVar2,0xd0,0);
            return local_60;
          }
          puVar2[0x18] = 0x5de;
          NdisReadConfiguration(&local_60,&local_5c,local_58[0],&local_50,0);
          if (local_60 == 0) {
            puVar2[0x18] = *(undefined4 *)(local_5c + 4);
          }
          puVar2[0x22] = puVar2[0x18];
          NdisReadConfiguration(&local_60,&local_5c,local_58[0],&local_48,0);
          if (local_60 == 0) {
            puVar2[0x22] = *(undefined4 *)(local_5c + 4);
          }
          puVar2[0x23] = puVar2[0x18];
          NdisReadConfiguration(&local_60,&local_5c,local_58[0],&local_40,0);
          if (local_60 == 0) {
            puVar2[0x23] = *(undefined4 *)(local_5c + 4);
          }
          puVar2[0x24] = 2000;
          NdisReadConfiguration(&local_60,&local_5c,local_58[0],&local_38,0);
          if (local_60 == 0) {
            puVar2[0x24] = *(undefined4 *)(local_5c + 4);
          }
          puVar2[0x25] = 0x82;
          NdisReadConfiguration(&local_60,&local_5c,local_58[0],&local_30,0);
          if (local_60 == 0) {
            puVar2[0x25] = *(undefined4 *)(local_5c + 4);
          }
          puVar2[0x26] = 0x82;
          NdisReadConfiguration(&local_60,&local_5c,local_58[0],&local_28,0);
          if (local_60 == 0) {
            puVar2[0x26] = *(undefined4 *)(local_5c + 4);
          }
          puVar2[0x19] = 0x10;
          NdisReadConfiguration(&local_60,&local_5c,local_58[0],&local_20,0);
          if (local_60 == 0) {
            puVar2[0x19] = *(undefined4 *)(local_5c + 4);
          }
          NdisCloseConfiguration(local_58[0]);
          puVar2[0x1a] = puVar2[0x18] + 4 & 0xfffffffc;
          puVar2[0x1b] = 5;
          puVar2[0x1c] = 1;
          puVar2[0x1d] = 0;
          puVar2[0x20] = 0x1f00;
          puVar2[0x21] = 0;
          NdisMSetAttributesEx(param_5,puVar2,0xfffff,0x20,0);
          puVar2[2] = 0x20000;
          puVar2[0x2a] = FUN_c0463308;
          puVar2[0x28] = 0;
          puVar2[0x29] = puVar2;
          NdisScheduleWorkItem();
          EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0465480);
          DAT_c04654a0 = DAT_c04654a0 + 1;
          DAT_c0465498 = puVar2;
          LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0465480);
          return 0;
        }
        uVar3 = uVar3 + 1;
        param_3 = param_3 + 1;
      } while (uVar3 < param_4);
    }
    iVar1 = -0x3ffeffe7;
  }
  else {
    iVar1 = -0x3fffffff;
  }
  return iVar1;
}



/* c0461744 FUN_c0461744 */

/* Boundary evidence: original MIPS .pdata c0461744..c046192b. Semantic name remains unreviewed. */

undefined4 FUN_c0461744(uint param_1)

{
  undefined4 uVar1;
  
  if (param_1 < 0x80000030) {
    if (param_1 != 0x8000002f) {
      if (param_1 < 0x80000012) {
        if (param_1 < 0x80000010) {
          if (param_1 == 0) {
            return 0;
          }
          if (param_1 != 0x80000002) {
            if (param_1 == 0x80000005) {
              return 0xc0012002;
            }
            if ((param_1 != 0x8000000c) && (param_1 == 0x8000000d)) {
              return 0xc0012007;
            }
            goto switchD_c046187c_caseD_80000033;
          }
        }
      }
      else if (param_1 != 0x80000014) {
        if (param_1 == 0x80000018) {
          return 0xc001200d;
        }
        if (param_1 == 0x8000001e) goto switchD_c046187c_caseD_80000042;
        if (param_1 != 0x80000023) {
          if (param_1 == 0x8000002c) {
            return 0xc0012012;
          }
          goto switchD_c046187c_caseD_80000033;
        }
      }
    }
switchD_c046187c_caseD_80000032:
    uVar1 = 0xc001201d;
  }
  else {
    switch(param_1) {
    case 0x80000032:
    case 0x80000035:
      goto switchD_c046187c_caseD_80000032;
    default:
switchD_c046187c_caseD_80000033:
      uVar1 = 0xc0000001;
      break;
    case 0x80000042:
    case 0x80000050:
switchD_c046187c_caseD_80000042:
      uVar1 = 0xc001201e;
      break;
    case 0x80000043:
      uVar1 = 0xc0012015;
      break;
    case 0x80000044:
      uVar1 = 0xc000009a;
      break;
    case 0x80000049:
      uVar1 = 0xc0012016;
      break;
    case 0x8000004b:
      uVar1 = 0xc0012018;
      break;
    case 0x8000004d:
      uVar1 = 0xc0012019;
    }
  }
  return uVar1;
}



/* c046192c FUN_c046192c */

/* Boundary evidence: original MIPS .pdata c046192c..c046197f. Semantic name remains unreviewed. */

void FUN_c046192c(int param_1)

{
  LPCSTR lpszDeviceClass;
  
  lpszDeviceClass = (LPCSTR)(param_1 + 0x1c);
  if (*(int *)(param_1 + 0xc) == 0) {
    lpszDeviceClass = (LPCSTR)0x0;
  }
  lineConfigDialogEdit
            (*(DWORD *)(param_1 + 4),*(HWND *)(param_1 + 8),lpszDeviceClass,
             (LPVOID)(*(int *)(param_1 + 0x10) + param_1 + 0x1c),*(DWORD *)(param_1 + 0x14),
             (LPVARSTRING)(*(int *)(param_1 + 0x18) + param_1 + 0x1c));
  return;
}



/* c0461980 FUN_c0461980 */

/* Boundary evidence: original MIPS .pdata c0461980..c04619ff. Semantic name remains unreviewed. */

void FUN_c0461980(int param_1)

{
  if ((*(uint *)(param_1 + 0x48) & 8) != 0) {
    *(uint *)(param_1 + 0x48) = *(uint *)(param_1 + 0x48) & 0xfffffff7;
    NdisSetEvent(param_1 + 100);
  }
  if ((*(uint *)(param_1 + 0x48) & 4) != 0) {
    *(uint *)(param_1 + 0x48) = *(uint *)(param_1 + 0x48) & 0xfffffffb;
    if (*(HANDLE *)(param_1 + 0x40) != (HANDLE)0x0) {
      SetCommMask(*(HANDLE *)(param_1 + 0x40),0);
    }
  }
  return;
}



/* c0461a00 FUN_c0461a00 */

/* Boundary evidence: original MIPS .pdata c0461a00..c0461a83. Semantic name remains unreviewed. */

void FUN_c0461a00(int param_1)

{
  if (*(HANDLE *)(param_1 + 0x54) != (HANDLE)0x0) {
    WaitForSingleObject(*(HANDLE *)(param_1 + 0x54),0xffffffff);
    CloseHandle(*(HANDLE *)(param_1 + 0x54));
    *(undefined4 *)(param_1 + 0x54) = 0;
  }
  if (*(HANDLE *)(param_1 + 0x58) != (HANDLE)0x0) {
    WaitForSingleObject(*(HANDLE *)(param_1 + 0x58),0xffffffff);
    CloseHandle(*(HANDLE *)(param_1 + 0x58));
    *(undefined4 *)(param_1 + 0x58) = 0;
  }
  return;
}



/* c0461a84 FUN_c0461a84 */

undefined4 FUN_c0461a84(int *param_1,int param_2,uint param_3,uint *param_4)

{
  while( true ) {
    if (*param_1 == 0) {
      return 0xc0010017;
    }
    if (*param_1 == param_2) break;
    param_1 = param_1 + 2;
  }
  if (param_3 < (uint)param_1[1]) {
    *param_4 = param_1[1];
    return 0xc0010016;
  }
  return 0;
}



/* c0461af0 FUN_c0461af0 */

/* Boundary evidence: original MIPS .pdata c0461af0..c0461bcb. Semantic name remains unreviewed. */

undefined4 FUN_c0461af0(undefined4 param_1,int param_2,int *param_3)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  
  if ((((param_2 == 0) || (param_2 == -1)) || (*(int *)(param_2 + 0x40) == 0)) ||
     ((*(uint *)(param_2 + 0x48) & 8) == 0)) {
    uVar1 = 0xc0000001;
  }
  else {
    if ((*(uint *)(param_2 + 0x7c) & 0x100) == 0) {
      FUN_c04633e4(param_2,(int)param_3);
    }
    else {
      FUN_c046345c(param_2,(int)param_3);
    }
    EnterCriticalSection((LPCRITICAL_SECTION)(param_2 + 4));
    puVar2 = *(undefined4 **)(param_2 + 0x60);
    param_3[1] = (int)puVar2;
    *param_3 = param_2 + 0x5c;
    *puVar2 = param_3;
    *(int **)(param_2 + 0x60) = param_3;
    NdisSetEvent(param_2 + 100);
    LeaveCriticalSection((LPCRITICAL_SECTION)(param_2 + 4));
    uVar1 = 0x103;
  }
  return uVar1;
}



/* c0461bcc FUN_c0461bcc */

undefined4 FUN_c0461bcc(int param_1)

{
  int *piVar1;
  
  if (DAT_c0465498 != 0) {
    for (piVar1 = *(int **)(DAT_c0465498 + 0x9c); piVar1 != (int *)0x0; piVar1 = (int *)*piVar1) {
      if (piVar1 == (int *)param_1) {
        return 1;
      }
    }
  }
  return 0;
}



/* c0461c10 FUN_c0461c10 */

/* Boundary evidence: original MIPS .pdata c0461c10..c0461ceb. Semantic name remains unreviewed. */

void FUN_c0461c10(undefined4 *param_1)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0465480);
  iVar2 = FUN_c0461bcc((int)param_1);
  if ((iVar2 != 0) && (iVar2 = param_1[6], param_1[6] = iVar2 + -1, iVar2 + -1 == 0)) {
    puVar3 = *(undefined4 **)(param_1[7] + 0x9c);
    if (param_1 == puVar3) {
      *(undefined4 *)(param_1[7] + 0x9c) = *param_1;
    }
    else {
      do {
        puVar1 = puVar3;
        if (puVar1 == (undefined4 *)0x0) goto LAB_c0461ca0;
        puVar3 = (undefined4 *)*puVar1;
      } while ((undefined4 *)*puVar1 != param_1);
      *puVar1 = *param_1;
    }
LAB_c0461ca0:
    DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 1));
    NdisFreeEvent(param_1 + 0x19);
    NdisFreeMemory(param_1,0xd0,0);
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0465480);
  return;
}



/* c0461cec FUN_c0461cec */

/* Boundary evidence: original MIPS .pdata c0461cec..c0461d53. Semantic name remains unreviewed. */

int FUN_c0461cec(int param_1)

{
  int iVar1;
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c0465480);
  iVar1 = FUN_c0461bcc(param_1);
  if (iVar1 == 0) {
    param_1 = 0;
  }
  else {
    *(int *)(param_1 + 0x18) = *(int *)(param_1 + 0x18) + 1;
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c0465480);
  return param_1;
}



/* c0461d54 FUN_c0461d54 */

/* Boundary evidence: original MIPS .pdata c0461d54..c04620f3. Semantic name remains unreviewed. */

int FUN_c0461d54(undefined4 param_1,uint param_2,int *param_3,uint param_4,undefined4 *param_5,
                uint *param_6)

{
  int iVar1;
  undefined4 *puVar2;
  LONG LVar3;
  int iVar4;
  
  iVar1 = FUN_c0461a84((int *)&DAT_c0465208,param_2,param_4,param_6);
  if (iVar1 != 0) {
    return iVar1;
  }
  iVar1 = 0;
  if (param_2 < 0x703011e) {
    if (param_2 == 0x703011d) {
      return -0x3fffff45;
    }
    if (param_2 == 0x4010108) {
      puVar2 = (undefined4 *)FUN_c0461cec(*param_3);
      if (puVar2 == (undefined4 *)0x0) {
        return 0x40010007;
      }
      if (puVar2 == (undefined4 *)0xffffffff) {
        *param_6 = 8;
        return -0x3fffffff;
      }
      memcpy(puVar2 + 0x1a,param_3,0x2c);
    }
    else if (param_2 == 0x7030102) {
      puVar2 = (undefined4 *)FUN_c0461cec(param_3[1]);
      if (puVar2 == (undefined4 *)0x0) {
        return 0x40010007;
      }
      lineAnswer(puVar2[0xb],(LPCSTR)(param_3 + 3),param_3[2]);
    }
    else if (param_2 == 0x7030103) {
      puVar2 = (undefined4 *)FUN_c0461cec(param_3[1]);
      if (puVar2 == (undefined4 *)0x0) {
        return 0x40010007;
      }
      FUN_c0461980((int)puVar2);
      FUN_c0461a00((int)puVar2);
      LVar3 = lineClose(puVar2[9]);
      if (LVar3 < 1) {
        FUN_c0461c10(puVar2);
      }
      else {
        puVar2[0xe] = LVar3;
        iVar1 = 0x103;
      }
    }
    else if (param_2 == 0x7030104) {
      puVar2 = (undefined4 *)FUN_c0461cec(param_3[1]);
      if (puVar2 == (undefined4 *)0x0) {
        return 0x40010007;
      }
      if (puVar2[0x10] != 0) {
        FUN_c0461980((int)puVar2);
        puVar2[0x10] = 0;
      }
      LVar3 = lineDeallocateCall(puVar2[0xb]);
      puVar2[0xb] = 0;
      if (0 < LVar3) {
        puVar2[0xe] = LVar3;
        return 0x103;
      }
    }
    else {
      if (param_2 != 0x7030109) {
        if (param_2 == 0x7030119) {
          return -0x3fffff45;
        }
        goto LAB_c0461fb8;
      }
      puVar2 = (undefined4 *)FUN_c0461cec(param_3[1]);
      if (puVar2 == (undefined4 *)0x0) {
        return 0x40010007;
      }
      FUN_c0461980((int)puVar2);
      LVar3 = lineDrop(puVar2[0xb],(LPCSTR)(param_3 + 3),param_3[2]);
      if (0 < LVar3) {
        puVar2[0xe] = LVar3;
        return 0x103;
      }
    }
  }
  else {
    if (param_2 == 0x703011e) {
      puVar2 = (undefined4 *)FUN_c0461cec(param_3[1]);
      if (puVar2 == (undefined4 *)0x0) {
        return 0x40010007;
      }
      iVar4 = lineSetCallParams(puVar2[0xb],param_3[2],param_3[3],param_3[4],
                                (LPLINEDIALPARAMS)(param_3 + 6));
    }
    else {
      if (param_2 == 0x703011f) {
        puVar2 = (undefined4 *)FUN_c0461cec(param_3[1]);
        if (puVar2 == (undefined4 *)0x0) {
          return 0x40010007;
        }
        puVar2[0x14] = param_3[2] & 0x10;
        goto LAB_c04620cc;
      }
      if (param_2 == 0x7030120) {
        if (param_3[4] == 0) {
          return 0;
        }
        LVar3 = lineSetDevConfig(param_3[1],param_3 + 5,param_3[4],(LPCSTR)L"comm/datamodem");
        if (LVar3 == 0) {
          return 0;
        }
        return -0x3ffedfe3;
      }
      if (param_2 == 0x7030121) {
        puVar2 = (undefined4 *)FUN_c0461cec(param_3[1]);
        if (puVar2 == (undefined4 *)0x0) {
          return 0x40010007;
        }
        iVar4 = lineSetMediaMode(puVar2[0xb],param_3[2]);
      }
      else {
        if (param_2 != 0x7030122) {
LAB_c0461fb8:
          *param_5 = 0;
          *param_6 = 0;
          return -0x3ffeffe9;
        }
        puVar2 = (undefined4 *)FUN_c0461cec(param_3[1]);
        if (puVar2 == (undefined4 *)0x0) {
          return 0x40010007;
        }
        iVar4 = lineSetStatusMessages(puVar2[9],param_3[2],param_3[3]);
      }
    }
    if (iVar4 != 0) {
      iVar1 = -0x3fffffff;
    }
  }
LAB_c04620cc:
  FUN_c0461c10(puVar2);
  return iVar1;
}



/* c04620f4 FUN_c04620f4 */

/* Boundary evidence: original MIPS .pdata c04620f4..c04622d7. Semantic name remains unreviewed. */

undefined4 FUN_c04620f4(int param_1)

{
  undefined4 *puVar1;
  BOOL BVar2;
  int *piVar3;
  uint uVar4;
  int *piVar5;
  int *piVar6;
  undefined4 uVar7;
  uint uVar8;
  DWORD local_30 [2];
  
  puVar1 = (undefined4 *)FUN_c0461cec(param_1);
  if (puVar1 != (undefined4 *)0x0) {
    if ((puVar1[0x12] & 8) != 0) {
      do {
        NdisWaitEvent(puVar1 + 0x19,0);
        if ((puVar1[0x12] & 8) == 0) break;
        piVar6 = puVar1 + 0x17;
        while( true ) {
          piVar5 = (int *)0x0;
          EnterCriticalSection((LPCRITICAL_SECTION)(puVar1 + 1));
          piVar3 = (int *)*piVar6;
          if (piVar3 == piVar6) {
            NdisResetEvent(puVar1 + 0x19);
          }
          else {
            *(int **)(*piVar3 + 4) = piVar6;
            *piVar6 = *piVar3;
            piVar5 = piVar3;
          }
          LeaveCriticalSection((LPCRITICAL_SECTION)(puVar1 + 1));
          if (piVar5 == (int *)0x0) break;
          if ((puVar1[0x12] & 8) == 0) {
            uVar7 = 0xc0010002;
          }
          else {
            uVar4 = piVar5[3];
            uVar7 = 0;
            uVar8 = 0;
            if (uVar4 != 0) {
              do {
                BVar2 = WriteFile((HANDLE)puVar1[0x10],(LPCVOID)(piVar5[2] + uVar8),uVar4 - uVar8,
                                  local_30,(LPOVERLAPPED)0x0);
                if ((BVar2 == 0) || (local_30[0] == 0)) {
                  uVar7 = 0xc0000001;
                  puVar1[0x2b] = puVar1[0x2b] + 1;
                  goto LAB_c0462258;
                }
                puVar1[0x26] = puVar1[0x26] + local_30[0];
                uVar4 = piVar5[3];
                uVar8 = local_30[0] + uVar8;
              } while (uVar8 < uVar4);
            }
            puVar1[0x28] = puVar1[0x28] + 1;
          }
LAB_c0462258:
          (**(code **)(*DAT_c0465498 + 0x234))(*DAT_c0465498,piVar5,uVar7);
        }
      } while ((puVar1[0x12] & 8) != 0);
    }
    FUN_c0461c10(puVar1);
  }
  return 0;
}



/* c04622d8 FUN_c04622d8 */

/* Boundary evidence: original MIPS .pdata c04622d8..c04623d7. Semantic name remains unreviewed. */

undefined4 FUN_c04622d8(LPVOID param_1,int param_2)

{
  HANDLE pvVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  DWORD aDStack_20 [2];
  
  *(uint *)((int)param_1 + 0x48) = *(uint *)((int)param_1 + 0x48) | 0xc;
  uVar2 = 0;
  if (*(int *)((int)param_1 + 0x54) == 0) {
    pvVar1 = CreateThread((LPSECURITY_ATTRIBUTES)0x0,0,FUN_c04638c4,param_1,0,aDStack_20);
    *(HANDLE *)((int)param_1 + 0x54) = pvVar1;
    uVar2 = 0xc000009a;
    if (pvVar1 != (HANDLE)0x0) {
      CeSetThreadPriority(pvVar1,*(undefined4 *)(param_2 + 0x94));
      uVar2 = 0;
    }
  }
  uVar3 = uVar2;
  if (*(int *)((int)param_1 + 0x58) == 0) {
    pvVar1 = CreateThread((LPSECURITY_ATTRIBUTES)0x0,0,FUN_c04620f4,param_1,0,aDStack_20);
    *(HANDLE *)((int)param_1 + 0x58) = pvVar1;
    uVar3 = 0xc000009a;
    if (pvVar1 != (HANDLE)0x0) {
      CeSetThreadPriority(pvVar1,*(undefined4 *)(param_2 + 0x98));
      uVar3 = uVar2;
    }
  }
  return uVar3;
}



/* c04623d8 FUN_c04623d8 */

/* Boundary evidence: original MIPS .pdata c04623d8..c0462ce7. Semantic name remains unreviewed. */

int FUN_c04623d8(int param_1,uint param_2,DWORD *param_3,uint param_4,uint *param_5,uint *param_6)

{
  int iVar1;
  uint uVar2;
  HANDLE hHandle;
  LPLINECALLPARAMS lpCallParams;
  int iVar3;
  undefined4 *puVar4;
  char *_Src;
  DWORD DVar5;
  uint _Size;
  undefined4 *puVar6;
  DWORD DVar7;
  DWORD *_Src_00;
  DWORD local_48;
  undefined2 local_44 [2];
  uint *local_40;
  DWORD local_3c [2];
  undefined1 local_34;
  undefined1 local_33;
  undefined1 local_32;
  undefined1 local_31;
  undefined1 local_30;
  undefined1 local_2f;
  uint local_2c;
  
  local_2c = DAT_c0465440;
  local_3c[1] = 3;
  local_34 = 0x20;
  local_40 = param_6;
  local_3c[0] = 0;
  puVar6 = (undefined4 *)0x0;
  local_48 = 0;
  local_44[0] = 0;
  local_33 = 0x41;
  local_32 = 0x53;
  local_31 = 0x59;
  local_30 = 0x4e;
  local_2f = 0xff;
  if ((param_1 == 0) || (param_1 == -1)) {
    FUN_c0463f94(DAT_c0465440);
    return -0x3fffffff;
  }
  uVar2 = param_4;
  iVar1 = FUN_c0461a84((int *)&DAT_c04651a8,param_2,param_4,param_6);
  if (iVar1 == -0x3ffeffea) {
    FUN_c0463f94(local_2c);
    return -0x3ffeffea;
  }
  iVar1 = 0;
  _Src = (char *)&local_48;
  _Size = 4;
  if (param_2 < 0x4010103) {
    if (param_2 < 0x4010101) {
      switch(param_2) {
      case 0x10101:
        _Src = &DAT_c0465108;
        _Size = 0x98;
        break;
      case 0x10102:
        _Src = (char *)local_3c;
        break;
      case 0x10103:
      case 0x10104:
        _Src = (char *)(local_3c + 1);
        break;
      case 0x10105:
      case 0x10106:
      case 0x1010a:
      case 0x1010b:
      case 0x1010f:
      case 0x10111:
        local_48 = *(DWORD *)(param_1 + 0x60);
        break;
      case 0x10107:
        local_48 = 0x120;
        break;
      case 0x10108:
      case 0x10109:
        local_48 = *(int *)(param_1 + 0x60) << 1;
        break;
      case 0x1010c:
        local_48 = 0xffffffff;
        _Size = 3;
        break;
      case 0x1010d:
        _Src = "AsyncMac Adapter";
        _Size = 0x10;
        break;
      default:
switchD_c0462520_caseD_1010e:
        iVar1 = -0x3fffff45;
        goto LAB_c0462c94;
      case 0x10110:
        local_44[0] = 0x300;
        _Src = (char *)local_44;
        _Size = 2;
        break;
      case 0x10113:
        local_48 = 0x17;
      }
    }
    else {
      _Src = &local_34;
      _Size = 6;
    }
    goto LAB_c0462784;
  }
  if (param_2 < 0x7030112) {
    if (param_2 == 0x7030111) {
      uVar2 = lineGetDevConfig(param_3[1],(LPVARSTRING)(param_3 + 4),(LPCSTR)L"comm/datamodem");
LAB_c0462688:
      if (uVar2 == 0) goto LAB_c0462c94;
LAB_c0462694:
      iVar1 = FUN_c0461744(uVar2);
      goto LAB_c0462c94;
    }
    if (param_2 == 0x4010105) {
      local_48 = 3;
    }
    else if (param_2 == 0x4010106) {
      local_48 = 0;
    }
    else {
      if (param_2 != 0x4010107) {
        if (param_2 == 0x4010109) {
          puVar6 = (undefined4 *)FUN_c0461cec(*param_3);
          if (puVar6 != (undefined4 *)0x0) {
            _Src = (char *)(puVar6 + 0x1a);
            _Size = 0x2c;
            *(DWORD *)_Src = *param_3;
            goto LAB_c0462784;
          }
        }
        else if (param_2 == 0x401020e) {
          puVar6 = (undefined4 *)FUN_c0461cec(*param_3);
          if (puVar6 != (undefined4 *)0x0) {
            _Src = (char *)(puVar6 + 0x25);
            _Size = 0x3c;
            *(DWORD *)_Src = *param_3;
            goto LAB_c0462784;
          }
        }
        else {
          if (param_2 != 0x703010e) {
            if (param_2 != 0x7030110) goto switchD_c0462520_caseD_1010e;
            uVar2 = lineGetDevCaps(*(HLINEAPP *)(param_1 + 4),param_3[1],*(DWORD *)(param_1 + 8),0,
                                   (LPLINEDEVCAPS)(param_3 + 3));
            goto LAB_c0462688;
          }
          puVar6 = (undefined4 *)FUN_c0461cec(param_3[1]);
          if (puVar6 != (undefined4 *)0x0) {
            if (puVar6[0xb] == -1) {
              iVar1 = -0x3fffffff;
            }
            else {
              ((LPLINECALLINFO)(param_3 + 2))->dwTotalSize = 0x148;
              uVar2 = lineGetCallInfo(puVar6[0xb],(LPLINECALLINFO)(param_3 + 2));
              if (uVar2 != 0) {
                iVar1 = FUN_c0461744(uVar2);
              }
            }
            goto LAB_c0462c8c;
          }
        }
LAB_c04626bc:
        iVar1 = 0x40010007;
        goto LAB_c0462c94;
      }
      _Src = (char *)(param_1 + 0x60);
      _Size = 0x28;
    }
LAB_c0462784:
    if (param_4 < _Size) {
      *local_40 = _Size;
      iVar1 = -0x3ffeffea;
    }
    else {
      memcpy(param_3,_Src,_Size);
      *param_5 = _Size;
    }
    if (puVar6 == (undefined4 *)0x0) goto LAB_c0462c94;
  }
  else if (param_2 == 0x7030113) {
    if (param_4 < param_3[5] + 0x34) {
      iVar1 = -0x3ffeffea;
      goto LAB_c0462c94;
    }
    DVar7 = param_3[6];
    if ((param_3[4] & 4) == 0) {
      puVar6 = (undefined4 *)FUN_c0461cec(param_3[1]);
      if (puVar6 == (undefined4 *)0x0) {
        iVar1 = -0x3ffedfef;
        goto LAB_c0462c94;
      }
    }
    else {
      puVar6 = (undefined4 *)FUN_c0461cec(param_3[3]);
      if (puVar6 == (undefined4 *)0x0) {
        iVar1 = -0x3ffedff3;
        goto LAB_c0462c94;
      }
    }
    iVar3 = _wcsicmp((wchar_t *)(DVar7 + (int)param_3),L"ndis");
    if ((iVar3 != 0) || (iVar1 = FUN_c04622d8(puVar6,param_1), iVar1 == 0)) {
      uVar2 = lineGetID(puVar6[9],param_3[2],puVar6[0xb],param_3[4],(LPVARSTRING)(param_3 + 7),
                        (LPCSTR)(DVar7 + (int)param_3));
      *local_40 = param_3[8] + param_3[5] + 0x34;
      if (uVar2 != 0) {
        iVar1 = FUN_c0461744(uVar2);
      }
    }
  }
  else {
    if (param_2 != 0x7030115) {
      if (param_2 == 0x7030117) {
        puVar6 = (undefined4 *)FUN_c04611c4(0xd0,_Src,uVar2,param_6);
        if (puVar6 != (undefined4 *)0x0) {
          puVar6[6] = 1;
          puVar6[7] = param_1;
          if (*param_3 == 1) {
            puVar6[0x13] = 4;
            puVar6[0x14] = 0x10;
          }
          else {
            puVar6[0x13] = 2;
            puVar6[0x14] = 0;
          }
          puVar6[8] = param_3[1];
          puVar6[10] = param_3[2];
          puVar6[0x11] = 0x120;
          puVar6[0x1b] = *(undefined4 *)(param_1 + 0x88);
          puVar6[0x1c] = *(undefined4 *)(param_1 + 0x8c);
          puVar6[0x1d] = *(undefined4 *)(param_1 + 0x68);
          puVar6[0x1e] = *(undefined4 *)(param_1 + 0x6c);
          puVar6[0x1f] = 0x100;
          puVar6[0x20] = 0x100;
          puVar6[0x21] = 0;
          puVar6[0x22] = 0;
          puVar6[0x23] = 0xffffffff;
          puVar6[0x24] = 0xffffffff;
          memset(puVar6 + 0x25,0,0x3c);
          uVar2 = lineOpen(*(HLINEAPP *)(param_1 + 4),param_3[1],puVar6 + 9,*(DWORD *)(param_1 + 8),
                           0,(DWORD_PTR)puVar6,puVar6[0x13],puVar6[0x14],(LPLINECALLPARAMS)0x0);
          if (uVar2 == 0) {
            param_3[3] = (DWORD)puVar6;
            InitializeCriticalSection((LPCRITICAL_SECTION)(puVar6 + 1));
            puVar4 = puVar6 + 0x17;
            puVar6[0x18] = puVar4;
            *puVar4 = puVar4;
            NdisInitializeEvent(puVar6 + 0x19);
            *puVar6 = *(undefined4 *)(param_1 + 0x9c);
            *(undefined4 **)(param_1 + 0x9c) = puVar6;
            goto LAB_c0462c94;
          }
          NdisFreeMemory(puVar6,0xd0,0);
          goto LAB_c0462694;
        }
      }
      else {
        if (param_2 == 0x7030118) {
          param_3[2] = *(DWORD *)(param_1 + 0xc);
          *param_5 = 0x10;
          *(undefined4 *)(param_1 + 0xa0) = 1;
          goto LAB_c0462c94;
        }
        if (param_2 == 0x7030200) {
          uVar2 = lineTranslateAddress
                            (*(HLINEAPP *)(param_1 + 4),param_3[1],*(DWORD *)(param_1 + 8),
                             (LPCSTR)(param_3 + 6),0,param_3[4],
                             (LPLINETRANSLATEOUTPUT)((int)param_3 + param_3[5] + 0x18));
          goto LAB_c0462688;
        }
        if (param_2 != 0x7030201) goto switchD_c0462520_caseD_1010e;
        hHandle = CreateThread((LPSECURITY_ATTRIBUTES)0x0,0,FUN_c046192c,param_3,0,local_3c);
        if (hHandle != (HANDLE)0xffffffff) {
          WaitForSingleObject(hHandle,0xffffffff);
          GetExitCodeThread(hHandle,local_3c + 1);
          CloseHandle(hHandle);
          goto LAB_c0462c94;
        }
      }
      iVar1 = -0x3fffff66;
      goto LAB_c0462c94;
    }
    puVar6 = (undefined4 *)FUN_c0461cec(param_3[1]);
    if (puVar6 == (undefined4 *)0x0) goto LAB_c04626bc;
    puVar6[0xd] = param_3[2];
    if ((char)param_3[6] == '\0') {
      _Src_00 = param_3 + 7;
      DVar7 = *_Src_00 + 0x1e;
      if ((*_Src_00 <= DVar7) &&
         (lpCallParams = (LPLINECALLPARAMS)FUN_c04611c4(DVar7,_Src,uVar2,param_6),
         lpCallParams != (LPLINECALLPARAMS)0x0)) {
        memcpy(lpCallParams,_Src_00,*_Src_00);
        lpCallParams->dwDeviceClassSize = 0x1e;
        DVar5 = *_Src_00;
        lpCallParams->dwDeviceClassOffset = DVar5;
        memcpy((void *)((int)&lpCallParams->dwTotalSize + DVar5),L"comm/datamodem",0x1e);
        goto LAB_c0462b38;
      }
    }
    else {
      DVar7 = 0xb4;
      lpCallParams = (LPLINECALLPARAMS)FUN_c04611c4(0xb4,_Src,uVar2,param_6);
      if (lpCallParams != (LPLINECALLPARAMS)0x0) {
        memset(lpCallParams,0,0xb4);
        lpCallParams->dwBearerMode = 8;
        lpCallParams->dwMinRate = 0;
        lpCallParams->dwMaxRate = 0;
        lpCallParams->dwMediaMode = 0x10;
        lpCallParams->dwCallParamFlags = 2;
        lpCallParams->dwAddressMode = 1;
        lpCallParams->dwAddressID = 0;
LAB_c0462b38:
        lpCallParams->dwTotalSize = DVar7;
        uVar2 = lineMakeCall(puVar6[9],puVar6 + 0xb,(LPCSTR)(param_3[5] + (int)param_3),0,
                             lpCallParams);
        if ((int)uVar2 < 0) {
          iVar1 = FUN_c0461744(uVar2);
        }
        else {
          param_3[3] = (DWORD)puVar6;
        }
        NdisFreeMemory(lpCallParams,DVar7,0);
        goto LAB_c0462c8c;
      }
    }
    iVar1 = -0x3fffff66;
  }
LAB_c0462c8c:
  FUN_c0461c10(puVar6);
LAB_c0462c94:
  FUN_c0463f94(local_2c);
  return iVar1;
}



/* c0462ce8 DriverEntry */

/* Boundary evidence: original MIPS .pdata c0462ce8..c0462dff. Semantic name remains unreviewed. */

undefined4 DriverEntry(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 local_58;
  undefined1 local_57;
  undefined4 local_54;
  code *local_44;
  code *local_3c;
  code *local_34;
  undefined1 *local_30;
  undefined1 *local_2c;
  code *local_28;
  code *local_24;
  
                    /* 0x2ce8  1  DriverEntry */
  DAT_c0465498 = 0;
  DAT_c046549c = param_1;
  NdisInitializeWrapper(&DAT_c04654a4,param_1,param_2,0);
  memset(&local_58,0,0x48);
  local_54 = 1;
  local_44 = FUN_c04612ac;
  local_3c = FUN_c0461330;
  local_30 = &LAB_c0461adc;
  local_34 = FUN_c04623d8;
  local_2c = &LAB_c0461ae4;
  local_58 = 4;
  local_24 = FUN_c0461d54;
  local_57 = 0;
  local_28 = FUN_c0461af0;
  iVar1 = NdisMRegisterMiniport(DAT_c04654a4,&local_58,0x48);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    NdisTerminateWrapper(DAT_c04654a4,param_1);
    uVar2 = 0xc0000001;
  }
  return uVar2;
}



/* c0462e00 FUN_c0462e00 */

/* Boundary evidence: original MIPS .pdata c0462e00..c0462f07. Semantic name remains unreviewed. */

undefined4 FUN_c0462e00(HLINE param_1,HCALL param_2)

{
  LPVARSTRING lpDeviceID;
  LONG LVar1;
  DWORD uBytes;
  undefined4 uVar2;
  
  uBytes = 0x18;
  lpDeviceID = LocalAlloc(0x40,0x18);
  while( true ) {
    if (lpDeviceID == (LPVARSTRING)0x0) {
      return 0xffffffff;
    }
    lpDeviceID->dwTotalSize = uBytes;
    LVar1 = lineGetID(param_1,0,param_2,4,lpDeviceID,(LPCSTR)L"comm/datamodem");
    if (LVar1 != 0) break;
    uBytes = lpDeviceID->dwNeededSize;
    if (uBytes <= lpDeviceID->dwTotalSize) goto LAB_c0462ec4;
    LocalFree(lpDeviceID);
    lpDeviceID = LocalAlloc(0x40,uBytes);
  }
  LocalFree(lpDeviceID);
  lpDeviceID = (LPVARSTRING)0x0;
LAB_c0462ec4:
  if (lpDeviceID == (LPVARSTRING)0x0) {
    return 0xffffffff;
  }
  uVar2 = *(undefined4 *)((int)&lpDeviceID->dwTotalSize + lpDeviceID->dwStringOffset);
  LocalFree(lpDeviceID);
  return uVar2;
}



/* c0462f08 FUN_c0462f08 */

/* Boundary evidence: original MIPS .pdata c0462f08..c0462fd3. Semantic name remains unreviewed. */

void FUN_c0462f08(int param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  undefined4 local_30 [2];
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  
  piVar2 = *(int **)(param_1 + 0x1c);
  if ((*(uint *)(param_1 + 0x48) & 1) != 0) {
    local_30[0] = *(undefined4 *)(param_1 + 0x3c);
    iVar1 = *piVar2;
    (**(code **)(iVar1 + 0x220))(iVar1,0x40010009,local_30,4);
    *(uint *)(param_1 + 0x48) = *(uint *)(param_1 + 0x48) & 0xfffffffe;
    if (param_2 != 0) {
      local_28 = *(undefined4 *)(param_1 + 0x28);
      local_24 = *(undefined4 *)(param_1 + 0x34);
      local_20 = 2;
      local_1c = 1;
      local_18 = 0;
      local_14 = 0;
      iVar1 = *piVar2;
      (**(code **)(iVar1 + 0x220))(iVar1,0x40010080,&local_28,0x18);
    }
  }
  return;
}



/* c0462fd4 FUN_c0462fd4 */

/* Boundary evidence: original MIPS .pdata c0462fd4..c0463307. Semantic name remains unreviewed. */

void FUN_c0462fd4(HCALL param_1,uint param_2,int param_3,undefined4 *param_4,HCALL param_5,
                 int param_6)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  LONG LVar3;
  int *piVar4;
  undefined4 local_198;
  undefined4 local_194;
  uint local_190;
  undefined4 *local_18c;
  HCALL local_188;
  int local_184;
  undefined4 local_180 [2];
  undefined2 local_178;
  undefined4 local_174;
  undefined4 *local_170;
  undefined4 local_16c;
  linecallinfo_tag local_168;
  
  local_198 = 0;
  local_194 = 0;
  local_188 = param_5;
  local_184 = param_6;
  local_190 = param_2;
  local_18c = param_4;
  if (param_2 == 0x13) {
    if (DAT_c0465498 != (int *)0x0) {
      DAT_c0465498[3] = (int)param_4 + 1;
      (**(code **)(*DAT_c0465498 + 0x220))(*DAT_c0465498,0x40010080,&local_198,0x18);
    }
  }
  else if ((param_3 != 0) &&
          (puVar1 = (undefined4 *)FUN_c0461cec(param_3), puVar1 != (undefined4 *)0x0)) {
    piVar4 = (int *)puVar1[7];
    if ((param_2 == 0) ||
       (((2 < param_2 && ((param_2 < 6 || ((7 < param_2 && ((param_2 < 9 || (0xb < param_2))))))))
        || (param_1 == puVar1[0xb])))) {
      if (param_2 == 2) {
        puVar1[0xc] = param_4;
        if (param_4 == (undefined4 *)0x1) {
          if ((puVar1[0x12] & 1) != 0) {
            FUN_c0462f08((int)puVar1,0);
            FUN_c0461980((int)puVar1);
          }
        }
        else if (param_4 == (undefined4 *)0x100) {
          uVar2 = FUN_c0462e00(puVar1[9],puVar1[0xb]);
          puVar1[0x10] = uVar2;
          puVar1[0x12] = puVar1[0x12] | 1;
          memset(local_180,0,0x18);
          local_168.dwTotalSize = 0x148;
          LVar3 = lineGetCallInfo(puVar1[0xb],&local_168);
          if (LVar3 == 0) {
            puVar1[0x11] = local_168.dwRate / 100;
          }
          local_180[0] = puVar1[0x11];
          local_178 = 1;
          local_174 = puVar1[0xd];
          local_170 = puVar1;
          (**(code **)(*piVar4 + 0x220))(*piVar4,0x40010008,local_180,0x18);
          puVar1[0xf] = local_16c;
        }
      }
      else if (param_2 == 0xc) {
        if (param_4 == (undefined4 *)puVar1[0xe]) {
          puVar1[0xe] = 0xffffffff;
          FUN_c0461c10(puVar1);
          uVar2 = FUN_c0461744(param_5);
          (**(code **)(*piVar4 + 0x230))(*piVar4,uVar2);
        }
      }
      else if (param_2 == 0x17) {
        if (param_6 == 2) {
          lineDeallocateCall(param_5);
        }
        else if ((puVar1[0x14] != 0) && (puVar1[0xb] == 0)) {
          local_198 = puVar1[10];
          puVar1[0xb] = param_5;
          local_194 = 0;
          local_190 = 500;
          local_188 = 0;
          local_184 = 0;
          local_18c = puVar1;
          (**(code **)(*piVar4 + 0x220))(*piVar4,0x40010080,&local_198,0x18);
          puVar1[0xd] = local_188;
        }
      }
      local_198 = puVar1[10];
      local_194 = puVar1[0xd];
      (**(code **)(*piVar4 + 0x220))(*piVar4,0x40010080,&local_198,0x18);
    }
    else {
      lineDeallocateCall(param_1);
    }
    FUN_c0461c10(puVar1);
  }
  return;
}



/* c0463308 FUN_c0463308 */

/* Boundary evidence: original MIPS .pdata c0463308..c04633e3. Semantic name remains unreviewed. */

void FUN_c0463308(undefined4 param_1,int *param_2)

{
  int iVar1;
  LONG LVar2;
  uint uVar3;
  LPDWORD lpdwNumDevs;
  undefined1 auStack_28 [8];
  undefined4 local_20;
  uint local_1c;
  
  iVar1 = WaitForAPIReady(0x57,60000);
  if (iVar1 == 0) {
    lpdwNumDevs = (LPDWORD)(param_2 + 3);
    LVar2 = lineInitialize((LPHLINEAPP)(param_2 + 1),DAT_c0465494,FUN_c0462fd4,(LPCSTR)L"ASYNCMAC",
                           lpdwNumDevs);
    if ((LVar2 == 0) && (param_2[0x28] != 0)) {
      memset(auStack_28,0,0x18);
      local_20 = 0x13;
      uVar3 = 0;
      if (*lpdwNumDevs != 0) {
        do {
          local_1c = uVar3;
          (**(code **)(*param_2 + 0x220))(*param_2,0x40010080,auStack_28,0x18);
          uVar3 = uVar3 + 1;
        } while (uVar3 < *lpdwNumDevs);
      }
    }
  }
  return;
}



/* c04633e4 FUN_c04633e4 */

void FUN_c04633e4(undefined4 param_1,int param_2)

{
  char cVar1;
  char *pcVar2;
  int iVar3;
  char *pcVar4;
  
  pcVar2 = *(char **)(param_2 + 0x10);
  pcVar4 = *(char **)(param_2 + 8);
  iVar3 = *(int *)(param_2 + 0xc);
  *pcVar2 = -0x40;
  do {
    pcVar2 = pcVar2 + 1;
    if (iVar3 == 0) {
      *pcVar2 = -0x40;
      *(char **)(param_2 + 0xc) = pcVar2 + (1 - *(int *)(param_2 + 0x10));
      *(int *)(param_2 + 8) = *(int *)(param_2 + 0x10);
      return;
    }
    cVar1 = *pcVar4;
    iVar3 = iVar3 + -1;
    pcVar4 = pcVar4 + 1;
    if (cVar1 == -0x25) {
      cVar1 = -0x23;
LAB_c046342c:
      *pcVar2 = -0x25;
      pcVar2 = pcVar2 + 1;
    }
    else if (cVar1 == -0x40) {
      cVar1 = -0x24;
      goto LAB_c046342c;
    }
    *pcVar2 = cVar1;
  } while( true );
}



/* c046345c FUN_c046345c */

/* Boundary evidence: original MIPS .pdata c046345c..c0463583. Semantic name remains unreviewed. */

void FUN_c046345c(int param_1,int param_2)

{
  uint uVar1;
  byte bVar2;
  uint uVar3;
  byte *pbVar4;
  int iVar5;
  byte *pbVar6;
  uint uVar7;
  
  pbVar6 = *(byte **)(param_2 + 8);
  iVar5 = *(int *)(param_2 + 0xc);
  uVar7 = *(uint *)(param_1 + 0x8c);
  pbVar4 = *(byte **)(param_2 + 0x10);
  uVar1 = FUN_c0463c04(pbVar6,iVar5);
  *pbVar4 = 0x7e;
  while (pbVar4 = pbVar4 + 1, -2 < iVar5) {
    iVar5 = iVar5 + -1;
    if (iVar5 < 0) {
      if (iVar5 == -1) {
        uVar3 = ~uVar1 & 0xff;
      }
      else {
        uVar3 = (~uVar1 & 0xffff) >> 8;
      }
    }
    else {
      uVar3 = (uint)*pbVar6;
      pbVar6 = pbVar6 + 1;
    }
    bVar2 = (byte)uVar3;
    if (((uVar3 == 0x7d) || (uVar3 == 0x7e)) ||
       ((uVar7 != 0 && ((uVar3 < 0x20 && ((1 << (uVar3 & 0x1f) & uVar7) != 0)))))) {
      bVar2 = bVar2 ^ 0x20;
      *pbVar4 = 0x7d;
      pbVar4 = pbVar4 + 1;
    }
    *pbVar4 = bVar2;
  }
  *pbVar4 = 0x7e;
  *(byte **)(param_2 + 0xc) = pbVar4 + (1 - *(int *)(param_2 + 0x10));
  *(int *)(param_2 + 8) = *(int *)(param_2 + 0x10);
  return;
}



/* c0463584 FUN_c0463584 */

/* Boundary evidence: original MIPS .pdata c0463584..c046368f. Semantic name remains unreviewed. */

void FUN_c0463584(int param_1,int param_2,uint param_3)

{
  bool bVar1;
  ushort uVar2;
  uint uVar3;
  int iVar4;
  int *piVar5;
  undefined1 auStack_28 [8];
  
  piVar5 = *(int **)(param_1 + 0x1c);
  bVar1 = true;
  if ((*(uint *)(param_1 + 0x80) & 0x100) != 0) {
    if (param_3 < 3) {
      return;
    }
    uVar2 = *(ushort *)(param_2 + param_3 + -2);
    param_3 = param_3 - 2;
    uVar3 = FUN_c0463c04(param_2,param_3);
    bVar1 = (~(uint)uVar2 & 0xffff) == uVar3;
  }
  if (bVar1) {
    *(int *)(param_1 + 0xa4) = *(int *)(param_1 + 0xa4) + 1;
    iVar4 = *piVar5;
    (**(code **)(iVar4 + 0x238))(auStack_28,iVar4,*(undefined4 *)(param_1 + 0x3c),param_2,param_3);
    iVar4 = *piVar5;
    (**(code **)(iVar4 + 0x23c))(iVar4,*(undefined4 *)(param_1 + 0x3c));
  }
  else {
    *(int *)(param_1 + 0xa8) = *(int *)(param_1 + 0xa8) + 1;
  }
  return;
}



/* c0463690 FUN_c0463690 */

/* Boundary evidence: original MIPS .pdata c0463690..c04636d7. Semantic name remains unreviewed. */

void FUN_c0463690(HANDLE param_1,LPVOID param_2)

{
  DWORD aDStack_10 [2];
  
  DeviceIoControl(param_1,0x1b0030,(LPVOID)0x0,0,param_2,0x10,aDStack_10,(LPOVERLAPPED)0x0);
  return;
}



/* c04636d8 FUN_c04636d8 */

/* Boundary evidence: original MIPS .pdata c04636d8..c04637ab. Semantic name remains unreviewed. */

undefined4 FUN_c04636d8(int param_1,uint param_2)

{
  int iVar1;
  undefined4 uVar2;
  DWORD local_28 [2];
  uint local_20 [4];
  
  if (((param_2 & 0x80) != 0) &&
     (iVar1 = FUN_c0463690(*(HANDLE *)(param_1 + 0x40),local_20), iVar1 != 0)) {
    if ((local_20[0] & 8) != 0) {
      *(int *)(param_1 + 0xb8) = *(int *)(param_1 + 0xb8) + 1;
    }
    if ((local_20[0] & 2) != 0) {
      *(int *)(param_1 + 0xb4) = *(int *)(param_1 + 0xb4) + 1;
    }
  }
  if ((param_2 & 0x2000) == 0) {
    if ((param_2 & 0x20) != 0) {
      local_28[0] = 0;
      GetCommModemStatus(*(HANDLE *)(param_1 + 0x40),local_28);
      if ((local_28[0] & 0x80) == 0) goto LAB_c046374c;
    }
    uVar2 = 0;
  }
  else {
LAB_c046374c:
    uVar2 = 1;
    FUN_c0462f08(param_1,1);
  }
  return uVar2;
}



/* c04637ac FUN_c04637ac */

/* Boundary evidence: original MIPS .pdata c04637ac..c0463813. Semantic name remains unreviewed. */

void FUN_c04637ac(int param_1)

{
  DWORD DVar1;
  
  DVar1 = GetLastError();
  if (((DVar1 == 6) || (DVar1 == 0x1f)) && ((*(uint *)(param_1 + 0x48) & 2) == 0)) {
    *(uint *)(param_1 + 0x48) = *(uint *)(param_1 + 0x48) | 2;
    FUN_c0462f08(param_1,1);
  }
  return;
}



/* c0463814 FUN_c0463814 */

/* Boundary evidence: original MIPS .pdata c0463814..c04638c3. Semantic name remains unreviewed. */

undefined4 FUN_c0463814(int param_1,int *param_2,int *param_3,undefined4 *param_4)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  int *piVar4;
  undefined4 *puVar5;
  uint uVar6;
  undefined4 uVar7;
  uint uVar8;
  
  uVar6 = *(uint *)(*(int *)(param_1 + 0x1c) + 0x8c);
  uVar8 = uVar6 + 0x36;
  uVar7 = 0;
  if (uVar6 <= uVar8) {
    piVar3 = param_2;
    piVar4 = param_3;
    puVar5 = param_4;
    iVar1 = FUN_c04611c4(uVar8,param_2,param_3,param_4);
    *param_2 = iVar1;
    if (iVar1 != 0) {
      uVar2 = *(undefined4 *)(*(int *)(param_1 + 0x1c) + 0x90);
      *param_4 = uVar2;
      iVar1 = FUN_c04611c4(uVar2,piVar3,piVar4,puVar5);
      *param_3 = iVar1;
      if (iVar1 == 0) {
        FUN_c046121c(*param_2,uVar8);
      }
      else {
        uVar7 = 1;
      }
    }
  }
  return uVar7;
}



/* c04638c4 FUN_c04638c4 */

/* Boundary evidence: original MIPS .pdata c04638c4..c0463c03. Semantic name remains unreviewed. */

undefined4 FUN_c04638c4(int param_1)

{
  bool bVar1;
  bool bVar2;
  byte *pbVar3;
  byte *pbVar4;
  undefined4 *puVar5;
  int iVar6;
  BOOL BVar7;
  byte *pbVar8;
  byte bVar9;
  byte *pbVar10;
  byte bVar11;
  byte *pbVar12;
  byte bVar13;
  DWORD nNumberOfBytesToRead;
  byte *local_5c;
  DWORD local_58;
  uint local_54;
  byte *local_50;
  byte *local_4c;
  byte *local_48;
  _COMMTIMEOUTS local_40;
  
  puVar5 = (undefined4 *)FUN_c0461cec(param_1);
  if (puVar5 != (undefined4 *)0x0) {
    SetCommMask((HANDLE)puVar5[0x10],0x20a1);
    GetCommTimeouts((HANDLE)puVar5[0x10],&local_40);
    local_40.ReadIntervalTimeout = 0xffffffff;
    local_40.ReadTotalTimeoutMultiplier = 0;
    local_40.ReadTotalTimeoutConstant = 0;
    local_40.WriteTotalTimeoutMultiplier = 2;
    local_40.WriteTotalTimeoutConstant = 500;
    SetCommTimeouts((HANDLE)puVar5[0x10],&local_40);
    iVar6 = FUN_c0463814((int)puVar5,(int *)&local_5c,(int *)&local_50,&local_58);
    pbVar3 = local_5c;
    if (iVar6 == 0) {
      CloseHandle((HANDLE)puVar5[0x15]);
      puVar5[0x15] = 0;
    }
    else {
      bVar2 = false;
      local_4c = local_5c + *(int *)(puVar5[7] + 0x8c) + 0x36;
      bVar1 = true;
      pbVar10 = local_5c;
      pbVar12 = local_50;
      nNumberOfBytesToRead = local_58;
      if ((puVar5[0x12] & 4) != 0) {
        while (BVar7 = WaitCommEvent((HANDLE)puVar5[0x10],&local_54,(LPOVERLAPPED)0x0), BVar7 != 0)
        {
          if ((local_54 == 0) ||
             (((local_54 & 0x20a0) != 0 && (iVar6 = FUN_c04636d8((int)puVar5,local_54), iVar6 != 0))
             )) goto LAB_c0463ba8;
          if ((local_54 & 1) != 0) {
            bVar11 = 0x7e;
            bVar13 = 0x7d;
            if ((puVar5[0x20] & 0x100) == 0) {
              bVar11 = 0xc0;
              bVar13 = 0xdb;
            }
            do {
              BVar7 = ReadFile((HANDLE)puVar5[0x10],pbVar12,nNumberOfBytesToRead,(LPDWORD)&local_5c,
                               (LPOVERLAPPED)0x0);
              pbVar4 = local_4c;
              if (BVar7 == 0) goto LAB_c0463ba0;
              puVar5[0x27] = local_5c + puVar5[0x27];
              pbVar8 = pbVar12;
              local_48 = local_5c;
              nNumberOfBytesToRead = local_58;
              while (local_58 = nNumberOfBytesToRead, local_5c != (byte *)0x0) {
                local_5c = local_5c + -1;
                bVar9 = *pbVar8;
                pbVar8 = pbVar8 + 1;
                if (bVar9 == bVar11) {
                  if ((pbVar3 < pbVar10) && (!bVar1)) {
                    FUN_c0463584((int)puVar5,(int)pbVar3,(int)pbVar10 - (int)pbVar3);
                  }
                  bVar1 = false;
                  bVar2 = false;
                  pbVar10 = pbVar3;
                  pbVar12 = local_50;
                  nNumberOfBytesToRead = local_58;
                }
                else {
                  pbVar12 = local_50;
                  if (bVar9 == bVar13) {
                    bVar2 = true;
                  }
                  else if (pbVar10 < pbVar4) {
                    if (bVar2) {
                      if ((puVar5[0x20] & 0x100) == 0) {
                        if (bVar9 == 0xdd) {
                          bVar9 = 0xdb;
                        }
                        else if (bVar9 == 0xdc) {
                          bVar9 = 0xc0;
                        }
                      }
                      else {
                        bVar9 = bVar9 ^ 0x20;
                      }
                      bVar2 = false;
                    }
                    *pbVar10 = bVar9;
                    pbVar10 = pbVar10 + 1;
                  }
                  else if (!bVar1) {
                    bVar1 = true;
                    puVar5[0x2f] = puVar5[0x2f] + 1;
                  }
                }
              }
              local_5c = (byte *)0xffffffff;
            } while (local_48 != (byte *)0x0);
          }
          if ((puVar5[0x12] & 4) == 0) goto LAB_c0463ba8;
        }
LAB_c0463ba0:
        FUN_c04637ac((int)puVar5);
      }
LAB_c0463ba8:
      FUN_c046121c(pbVar12,nNumberOfBytesToRead);
      FUN_c046121c(pbVar3,*(int *)(puVar5[7] + 0x8c) + 0x36);
    }
    FUN_c0461c10(puVar5);
  }
  return 0;
}



/* c0463c04 FUN_c0463c04 */

void FUN_c0463c04(undefined4 param_1,int param_2)

{
  for (; param_2 != 0; param_2 = param_2 + -1) {
  }
  return;
}



/* c0463e2c entry */

/* Boundary evidence: original MIPS .pdata c0463e2c..c0463e9f. Semantic name remains unreviewed. */

undefined4 entry(HMODULE param_1,int param_2)

{
  undefined4 uVar1;
  
  if (param_2 == 1) {
    FUN_c0463ea0();
    FUN_c0464174();
  }
  uVar1 = FUN_c0461240(param_1,param_2);
  if (param_2 == 0) {
    FUN_c04640fc();
  }
  return uVar1;
}



/* c0463ea0 FUN_c0463ea0 */

/* Boundary evidence: original MIPS .pdata c0463ea0..c0463f13. Semantic name remains unreviewed. */

void FUN_c0463ea0(void)

{
  uint uVar1;
  
  if ((DAT_c0465440 == 0) || (DAT_c0465440 == 0xb064)) {
    uVar1 = __security_gen_cookie2();
    DAT_c0465440 = uVar1 >> 0x10 ^ uVar1 & 0xffff;
    if (DAT_c0465440 == 0) {
      DAT_c0465440 = 0xb064;
    }
  }
  DAT_c0465444 = ~DAT_c0465440;
  return;
}



/* c0463f14 FUN_c0463f14 */

/* Boundary evidence: original MIPS .pdata c0463f14..c0463f67. Semantic name remains unreviewed. */

void FUN_c0463f14(int param_1,undefined4 param_2,uint *param_3)

{
  if ((*param_3 & 1) != 0) {
    param_1 = ((-param_3[2] & param_3[1] + param_1) - (param_3[1] + param_1)) + param_1;
  }
  FUN_c0463f94(*(uint *)(param_1 + (*param_3 & 0xfffffffc)));
  return;
}



/* c0463f68 FUN_c0463f68 */

/* Boundary evidence: original MIPS .pdata c0463f68..c0463f93. Semantic name remains unreviewed. */

undefined4 FUN_c0463f68(undefined4 param_1,int param_2,undefined4 param_3,int param_4)

{
  FUN_c0463f14(param_2,param_4,*(uint **)(*(int *)(param_4 + 4) + 0xc));
  return 1;
}



/* c0463f94 FUN_c0463f94 */

/* Boundary evidence: original MIPS .pdata c0463f94..c0463fdb. Semantic name remains unreviewed. */

void FUN_c0463f94(uint param_1)

{
  if ((param_1 == DAT_c0465440) && (param_1 >> 0x10 == 0)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __report_gsfailure();
}



/* c0463fdc FUN_c0463fdc */

/* Boundary evidence: original MIPS .pdata c0463fdc..c04640fb. Semantic name remains unreviewed. */

void FUN_c0463fdc(UINT param_1,int param_2,int param_3)

{
  LPCRITICAL_SECTION lpCriticalSection;
  undefined4 *_Memory;
  
  DAT_c0465460 = (undefined1)param_3;
  if (param_2 == 0) {
    _Memory = DAT_c04654ac;
    if (DAT_c04654ac != (undefined4 *)0x0) {
      while (DAT_c04654a8 = DAT_c04654a8 + -1, _Memory <= DAT_c04654a8) {
        if ((code *)*DAT_c04654a8 != (code *)0x0) {
          (*(code *)*DAT_c04654a8)();
          _Memory = DAT_c04654ac;
        }
      }
      free(_Memory);
      DAT_c04654a8 = (undefined4 *)0x0;
      DAT_c04654ac = (undefined4 *)0x0;
    }
    FUN_c0464120((undefined4 *)&DAT_c0461010,(undefined4 *)&DAT_c0461014);
  }
  FUN_c0464120((undefined4 *)&DAT_c0461018,(undefined4 *)&DAT_c046101c);
  if (param_3 == 0) {
    TerminateProcess((HANDLE)0x42,param_1);
  }
  else {
    lpCriticalSection = (LPCRITICAL_SECTION)InterlockedExchange((LONG *)&DAT_c04654b0,0);
    if (lpCriticalSection != (LPCRITICAL_SECTION)0x0) {
      DeleteCriticalSection(lpCriticalSection);
      free(lpCriticalSection);
    }
  }
  return;
}



/* c04640fc FUN_c04640fc */

/* Boundary evidence: original MIPS .pdata c04640fc..c046411f. Semantic name remains unreviewed. */

void FUN_c04640fc(void)

{
  FUN_c0463fdc(0,0,1);
  return;
}



/* c0464120 FUN_c0464120 */

/* Boundary evidence: original MIPS .pdata c0464120..c0464173. Semantic name remains unreviewed. */

void FUN_c0464120(undefined4 *param_1,undefined4 *param_2)

{
  for (; param_1 < param_2; param_1 = param_1 + 1) {
    if ((code *)*param_1 != (code *)0x0) {
      (*(code *)*param_1)();
    }
  }
  return;
}



/* c0464174 FUN_c0464174 */

/* Boundary evidence: original MIPS .pdata c0464174..c04641af. Semantic name remains unreviewed. */

void FUN_c0464174(void)

{
  FUN_c0464120((undefined4 *)&DAT_c0461008,(undefined4 *)&DAT_c046100c);
  FUN_c0464120((undefined4 *)&DAT_c0461000,(undefined4 *)&DAT_c0461004);
  return;
}


