/* Automatic Ghidra pseudocode. Not original source; not runtime-verified. */

/* 402a1078 WSPStartup */

/* Boundary evidence: original MIPS .pdata 402a1078..402a116f. Semantic name remains unreviewed. */

undefined4 WSPStartup(uint param_1,ushort *param_2,undefined4 param_3,undefined4 param_4)

{
  uint uVar1;
  undefined4 uVar2;
  undefined4 local_resc;
  void *in_stack_00000048;
  
                    /* 0x1078  1  WSPStartup */
  uVar2 = 0;
  local_resc = param_4;
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_402a3160);
  uVar1 = param_1 >> 8 & 0xff;
  if ((param_1 & 0xff) < 2) {
    uVar2 = 0x276c;
  }
  else {
    if (1 < uVar1) {
      uVar1 = 2;
    }
    *param_2 = (ushort)(uVar1 << 8) | 2;
    param_2[1] = 0x202;
    wcscpy((wchar_t *)(param_2 + 2),L"Winsock 2.2");
    DAT_402a3100 = DAT_402a3100 + 1;
    memcpy(&DAT_402a3120,&local_resc,0x3c);
    memcpy(in_stack_00000048,&PTR_FUN_402a3068,0x78);
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_402a3160);
  return uVar2;
}



/* 402a1170 FUN_402a1170 */

/* Boundary evidence: original MIPS .pdata 402a1170..402a11ef. Semantic name remains unreviewed. */

undefined4 FUN_402a1170(int *param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = 0;
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_402a3160);
  if (DAT_402a3100 < 1) {
    iVar1 = 0x276d;
  }
  else {
    DAT_402a3100 = DAT_402a3100 + -1;
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_402a3160);
  uVar2 = 0;
  if (iVar1 != 0) {
    *param_1 = iVar1;
    uVar2 = 0xffffffff;
  }
  return uVar2;
}



/* 402a11f0 FUN_402a11f0 */

/* Boundary evidence: original MIPS .pdata 402a11f0..402a1253. Semantic name remains unreviewed. */

undefined4 FUN_402a11f0(HMODULE param_1,int param_2)

{
  if (param_2 == 0) {
    DeleteCriticalSection((LPCRITICAL_SECTION)&DAT_402a3160);
  }
  else if (param_2 == 1) {
    InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_402a3160);
    DisableThreadLibraryCalls(param_1);
  }
  return 1;
}



/* 402a1254 FUN_402a1254 */

/* Boundary evidence: original MIPS .pdata 402a1254..402a1347. Semantic name remains unreviewed. */

undefined4 FUN_402a1254(short *param_1,uint *param_2,undefined4 param_3)

{
  byte bVar1;
  short *psVar2;
  uint uVar3;
  uint uVar4;
  short *psVar5;
  int iVar6;
  undefined4 uVar7;
  uint uVar8;
  undefined4 local_res8 [2];
  short local_30 [18];
  uint local_c;
  
  local_res8[0] = param_3;
  local_c = DAT_402a30e0;
  uVar7 = 0;
  iVar6 = 3;
  uVar4 = 0;
  psVar2 = local_30;
  do {
    do {
      psVar5 = psVar2;
      uVar3 = uVar4;
      bVar1 = *(byte *)((int)local_res8 + iVar6);
      uVar8 = bVar1 / 10;
      *psVar5 = (ushort)bVar1 % 10 + 0x30;
      *(byte *)((int)local_res8 + iVar6) = (byte)uVar8;
      uVar4 = uVar3 + 1;
      psVar2 = psVar5 + 1;
    } while (uVar8 != 0);
    psVar5[1] = 0x2e;
    uVar4 = uVar3 + 2;
    iVar6 = iVar6 + -1;
    psVar2 = psVar5 + 2;
  } while (-1 < iVar6);
  uVar8 = *param_2;
  *param_2 = uVar4;
  if (uVar8 < uVar4) {
    uVar7 = 8;
  }
  else {
    iVar6 = uVar3 + 1;
    if (iVar6 != 0) {
      psVar2 = local_30 + iVar6;
      do {
        psVar2 = psVar2 + -1;
        iVar6 = iVar6 + -1;
        *param_1 = *psVar2;
        param_1 = param_1 + 1;
      } while (iVar6 != 0);
    }
    *param_1 = 0;
  }
  FUN_402a2904(local_c);
  return uVar7;
}



/* 402a1348 FUN_402a1348 */

/* Boundary evidence: original MIPS .pdata 402a1348..402a140b. Semantic name remains unreviewed. */

undefined4 FUN_402a1348(uint param_1,short *param_2,int *param_3)

{
  int iVar1;
  short *psVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  short local_18 [6];
  uint local_c;
  
  local_c = DAT_402a30e0;
  uVar5 = 0;
  psVar2 = local_18;
  iVar4 = 0;
  do {
    iVar3 = iVar4;
    iVar4 = iVar3 + 1;
    *psVar2 = (short)((int)param_1 % 10) + 0x30;
    param_1 = (int)param_1 / 10 & 0xffff;
    psVar2 = psVar2 + 1;
  } while (param_1 != 0);
  iVar1 = *param_3;
  *param_3 = iVar3 + 2;
  if (iVar4 < iVar1) {
    if (iVar4 != 0) {
      psVar2 = local_18 + iVar4;
      do {
        psVar2 = psVar2 + -1;
        iVar4 = iVar4 + -1;
        *param_2 = *psVar2;
        param_2 = param_2 + 1;
      } while (iVar4 != 0);
    }
    *param_2 = 0;
  }
  else {
    uVar5 = 8;
  }
  FUN_402a2904(local_c);
  return uVar5;
}



/* 402a140c FUN_402a140c */

/* Boundary evidence: original MIPS .pdata 402a140c..402a1443. Semantic name remains unreviewed. */

undefined4 FUN_402a140c(undefined4 *param_1)

{
  (*(code *)*param_1)(param_1[3],param_1[1],param_1,param_1[2]);
  return 1;
}



/* 402a1444 FUN_402a1444 */

/* Boundary evidence: original MIPS .pdata 402a1444..402a1487. Semantic name remains unreviewed. */

void FUN_402a1444(undefined4 param_1)

{
  undefined4 uVar1;
  
  uVar1 = CeGetThreadPriority(0x41);
  CeSetThreadPriority(param_1,uVar1);
  return;
}



/* 402a1488 FUN_402a1488 */

/* Boundary evidence: original MIPS .pdata 402a1488..402a14f7. Semantic name remains unreviewed. */

DWORD FUN_402a1488(LPVOID param_1)

{
  HANDLE hObject;
  DWORD local_10 [2];
  
  local_10[0] = 0;
  hObject = CreateThread((LPSECURITY_ATTRIBUTES)0x0,0,FUN_402a140c,param_1,4,local_10);
  if (hObject != (HANDLE)0x0) {
    FUN_402a1444(hObject);
    CloseHandle(hObject);
  }
  return local_10[0];
}



/* 402a14f8 FUN_402a14f8 */

/* Boundary evidence: original MIPS .pdata 402a14f8..402a157f. Semantic name remains unreviewed. */

undefined4
FUN_402a14f8(undefined4 param_1,int param_2,int *param_3,undefined4 param_4,undefined4 param_5,
            int *param_6)

{
  int iVar1;
  undefined4 local_10 [2];
  
  if (param_2 == 0) {
    if (param_3 != (int *)0x0) {
      if (*param_3 != 0) goto LAB_402a152c;
      goto LAB_402a1510;
    }
    iVar1 = 0;
  }
  else {
    if (param_3 == (int *)0x0) {
LAB_402a152c:
      iVar1 = 0x271e;
      goto LAB_402a1560;
    }
LAB_402a1510:
    iVar1 = *param_3;
  }
  iVar1 = (*(code *)&SUB_ffff8ffa)(param_1,local_10,param_2,iVar1,param_3,param_4,param_5);
  if (iVar1 == 0) {
    return local_10[0];
  }
LAB_402a1560:
  *param_6 = iVar1;
  return 0xffffffff;
}



/* 402a1580 FUN_402a1580 */

/* Boundary evidence: original MIPS .pdata 402a1580..402a16f3. Semantic name remains unreviewed. */

undefined4
FUN_402a1580(short *param_1,uint param_2,undefined4 param_3,short *param_4,uint *param_5,
            int *param_6)

{
  short sVar1;
  ushort uVar2;
  uint uVar3;
  int iVar4;
  short *psVar5;
  uint local_res4 [3];
  int local_18;
  uint local_14;
  
  sVar1 = *param_1;
  local_res4[0] = param_2;
  if (sVar1 == 0x17) {
    iVar4 = (*(code *)&SUB_fffe6f82)
                      (1,0x17,param_1,param_2,local_res4,param_3,0x274,param_4,*param_5 << 1,param_5
                      );
  }
  else {
    if (((sVar1 != 0) && (sVar1 != 2)) || (param_2 < 0x10)) {
      iVar4 = 0x2726;
      goto LAB_402a16d0;
    }
    local_14 = *param_5;
    iVar4 = FUN_402a1254(param_4,&local_14,*(undefined4 *)(param_1 + 2));
    uVar3 = local_14;
    uVar2 = param_1[1];
    local_18 = 0;
    if (uVar2 != 0) {
      psVar5 = param_4;
      if (iVar4 == 0) {
        local_18 = *param_5 - local_14;
        psVar5 = param_4 + local_14;
      }
      iVar4 = FUN_402a1348((uVar2 & 0xff) << 8 | (uint)(uVar2 >> 8),psVar5,&local_18);
      if (iVar4 == 0) {
        param_4[uVar3 - 1] = 0x3a;
      }
    }
    *param_5 = local_18 + uVar3;
    if (iVar4 == 8) {
      iVar4 = 0x271e;
    }
  }
  if (iVar4 == 0) {
    return 0;
  }
LAB_402a16d0:
  *param_6 = iVar4;
  return 0xffffffff;
}



/* 402a1708 FUN_402a1708 */

/* Boundary evidence: original MIPS .pdata 402a1708..402a173f. Semantic name remains unreviewed. */

undefined4 FUN_402a1708(void)

{
  int iVar1;
  undefined4 uVar2;
  int *in_a3;
  
  iVar1 = (*(code *)&SUB_ffff8ff6)();
  uVar2 = 0;
  if (iVar1 != 0) {
    *in_a3 = iVar1;
    uVar2 = 0xffffffff;
  }
  return uVar2;
}



/* 402a1750 FUN_402a1750 */

/* Boundary evidence: original MIPS .pdata 402a1750..402a17bf. Semantic name remains unreviewed. */

undefined4 FUN_402a1750(HANDLE param_1,DWORD *param_2)

{
  int iVar1;
  undefined4 uVar2;
  DWORD DVar3;
  
  iVar1 = (*(code *)&SUB_ffff8fba)(param_1);
  if (iVar1 == 0) {
    DVar3 = GetLastError();
    *param_2 = DVar3;
    uVar2 = 0xffffffff;
  }
  else {
    CloseHandle(param_1);
    uVar2 = 0;
  }
  return uVar2;
}



/* 402a17c0 FUN_402a17c0 */

/* Boundary evidence: original MIPS .pdata 402a17c0..402a17f3. Semantic name remains unreviewed. */

undefined4 FUN_402a17c0(void)

{
  int iVar1;
  undefined4 uVar2;
  int *in_stack_0000001c;
  
  iVar1 = (*(code *)&SUB_ffff8ff2)();
  uVar2 = 0;
  if (iVar1 != 0) {
    *in_stack_0000001c = iVar1;
    uVar2 = 0xffffffff;
  }
  return uVar2;
}



/* 402a17f4 FUN_402a17f4 */

/* Boundary evidence: original MIPS .pdata 402a17f4..402a193b. Semantic name remains unreviewed. */

bool FUN_402a17f4(undefined4 param_1,int *param_2,int *param_3,int param_4,int *param_5,
                 DWORD *param_6)

{
  DWORD DVar1;
  bool bVar2;
  
  bVar2 = false;
  if (param_2 == (int *)0x0) {
    DVar1 = 0x2726;
    goto LAB_402a18b4;
  }
  if (*param_2 == 0x103) {
    if (param_4 == 0) {
      DVar1 = 0x3e4;
      goto LAB_402a18b4;
    }
    if ((HANDLE)param_2[4] == (HANDLE)0x0) {
      DVar1 = 6;
      goto LAB_402a18b4;
    }
    DVar1 = WaitForSingleObject((HANDLE)param_2[4],0xffffffff);
    if (DVar1 == 0xffffffff) {
      DVar1 = GetLastError();
      goto LAB_402a18b4;
    }
  }
  DVar1 = param_2[3];
LAB_402a18b4:
  if ((DVar1 == 0) || (DVar1 == 0x2738)) {
    *param_5 = param_2[2];
    *param_3 = param_2[1];
    bVar2 = DVar1 == 0;
  }
  *param_6 = DVar1;
  return bVar2;
}



/* 402a193c FUN_402a193c */

/* Boundary evidence: original MIPS .pdata 402a193c..402a1947. Semantic name remains unreviewed. */

undefined4 FUN_402a193c(void)

{
  return 1;
}



/* 402a1948 FUN_402a1948 */

/* Boundary evidence: original MIPS .pdata 402a1948..402a1987. Semantic name remains unreviewed. */

undefined4 FUN_402a1948(undefined4 param_1,undefined4 param_2,undefined4 *param_3,int *param_4)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = (*(code *)&SUB_ffff8fd6)(param_1,param_2,*param_3,param_3);
  uVar2 = 0;
  if (iVar1 != 0) {
    *param_4 = iVar1;
    uVar2 = 0xffffffff;
  }
  return uVar2;
}



/* 402a1988 FUN_402a1988 */

/* Boundary evidence: original MIPS .pdata 402a1988..402a19c7. Semantic name remains unreviewed. */

undefined4 FUN_402a1988(undefined4 param_1,undefined4 param_2,undefined4 *param_3,int *param_4)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = (*(code *)&SUB_ffff8fda)(param_1,param_2,*param_3,param_3);
  uVar2 = 0;
  if (iVar1 != 0) {
    *param_4 = iVar1;
    uVar2 = 0xffffffff;
  }
  return uVar2;
}



/* 402a19c8 FUN_402a19c8 */

/* Boundary evidence: original MIPS .pdata 402a19c8..402a1a07. Semantic name remains unreviewed. */

undefined4 FUN_402a19c8(void)

{
  int iVar1;
  undefined4 uVar2;
  int *in_stack_00000014;
  
  iVar1 = (*(code *)&SUB_ffff8fd2)();
  uVar2 = 0;
  if (iVar1 != 0) {
    *in_stack_00000014 = iVar1;
    uVar2 = 0xffffffff;
  }
  return uVar2;
}



/* 402a1a18 FUN_402a1a18 */

/* Boundary evidence: original MIPS .pdata 402a1a18..402a1b4f. Semantic name remains unreviewed. */

undefined4
FUN_402a1a18(undefined4 param_1,undefined4 *param_2,undefined4 param_3,LPVOID param_4,int param_5,
            undefined4 param_6,int *param_7)

{
  undefined1 *_Dst;
  int iVar1;
  DWORD local_58 [2];
  undefined1 auStack_50 [48];
  
  if (param_2 == (undefined4 *)0x0) {
    iVar1 = 0x271e;
  }
  else {
    if ((uint)param_2[3] < 7) {
      _Dst = auStack_50;
    }
    else {
      _Dst = LocalAlloc(0,param_2[3] << 3);
      if (_Dst == (undefined1 *)0x0) {
        iVar1 = 0x2747;
        goto LAB_402a1b1c;
      }
    }
    memcpy(_Dst,(void *)param_2[2],param_2[3] << 3);
    if ((param_4 != (LPVOID)0x0) && (param_5 != 0)) {
      local_58[0] = FUN_402a1488(param_4);
    }
    iVar1 = (*(code *)&SUB_ffff8fe6)
                      (param_1,_Dst,param_2[3],param_3,param_2 + 4,param_2 + 6,*param_2,param_2 + 1,
                       param_4,param_5,local_58);
    if (auStack_50 != _Dst) {
      LocalFree(_Dst);
    }
    if (iVar1 == 0) {
      return 0;
    }
  }
LAB_402a1b1c:
  *param_7 = iVar1;
  return 0xffffffff;
}



/* 402a1b50 FUN_402a1b50 */

/* Boundary evidence: original MIPS .pdata 402a1b50..402a1c7b. Semantic name remains unreviewed. */

undefined4
FUN_402a1b50(undefined4 param_1,int param_2,undefined4 *param_3,int param_4,undefined4 param_5,
            undefined4 param_6,undefined4 param_7,LPVOID param_8,int param_9,DWORD *param_10,
            int *param_11)

{
  undefined4 uVar1;
  int iVar2;
  DWORD local_28 [2];
  
  if (param_2 == -0x27ffbead) {
    if (param_4 == 0x1c) {
      uVar1 = FUN_402a1a18(param_1,param_3,param_7,param_8,param_9,param_10,param_11);
      return uVar1;
    }
    *param_11 = 0x271e;
  }
  else {
    if ((param_8 != (LPVOID)0x0) && (param_9 != 0)) {
      local_28[0] = FUN_402a1488(param_8);
      param_10 = local_28;
    }
    iVar2 = (*(code *)&SUB_ffff8fee)
                      (param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,param_9,
                       param_10);
    if (iVar2 == 0) {
      return 0;
    }
    *param_11 = iVar2;
  }
  return 0xffffffff;
}



/* 402a1c90 FUN_402a1c90 */

/* Boundary evidence: original MIPS .pdata 402a1c90..402a1cc7. Semantic name remains unreviewed. */

undefined4 FUN_402a1c90(undefined4 param_1,undefined4 param_2,int *param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = (*(code *)&SUB_ffff8fea)();
  uVar2 = 0;
  if (iVar1 != 0) {
    *param_3 = iVar1;
    uVar2 = 0xffffffff;
  }
  return uVar2;
}



/* 402a1cc8 FUN_402a1cc8 */

/* Boundary evidence: original MIPS .pdata 402a1cc8..402a1d93. Semantic name remains unreviewed. */

undefined4
FUN_402a1cc8(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,LPVOID param_6,int param_7,DWORD *param_8,int *param_9)

{
  int iVar1;
  undefined4 uVar2;
  DWORD local_28 [2];
  
  if ((param_6 != (LPVOID)0x0) && (param_7 != 0)) {
    local_28[0] = FUN_402a1488(param_6);
    param_8 = local_28;
  }
  iVar1 = (*(code *)&SUB_ffff8fe6)
                    (param_1,param_2,param_3,param_4,0,param_5,0,0,param_6,param_7,param_8);
  uVar2 = 0;
  if (iVar1 != 0) {
    *param_9 = iVar1;
    uVar2 = 0xffffffff;
  }
  return uVar2;
}



/* 402a1da4 FUN_402a1da4 */

/* Boundary evidence: original MIPS .pdata 402a1da4..402a1e77. Semantic name remains unreviewed. */

undefined4
FUN_402a1da4(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,undefined4 param_6,undefined4 param_7,LPVOID param_8,int param_9,
            DWORD *param_10,int *param_11)

{
  int iVar1;
  undefined4 uVar2;
  DWORD local_28 [2];
  
  if ((param_8 != (LPVOID)0x0) && (param_9 != 0)) {
    local_28[0] = FUN_402a1488(param_8);
    param_10 = local_28;
  }
  iVar1 = (*(code *)&SUB_ffff8fe6)
                    (param_1,param_2,param_3,param_4,0,param_5,param_6,param_7,param_8,param_9,
                     param_10);
  uVar2 = 0;
  if (iVar1 != 0) {
    *param_11 = iVar1;
    uVar2 = 0xffffffff;
  }
  return uVar2;
}



/* 402a1e78 FUN_402a1e78 */

/* Boundary evidence: original MIPS .pdata 402a1e78..402a1f3f. Semantic name remains unreviewed. */

undefined4
FUN_402a1e78(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,LPVOID param_6,int param_7,DWORD *param_8,int *param_9)

{
  int iVar1;
  undefined4 uVar2;
  DWORD local_28 [2];
  
  if ((param_6 != (LPVOID)0x0) && (param_7 != 0)) {
    local_28[0] = FUN_402a1488(param_6);
    param_8 = local_28;
  }
  iVar1 = (*(code *)&SUB_ffff8fe2)
                    (param_1,param_2,param_3,param_4,param_5,0,0,param_6,param_7,param_8);
  uVar2 = 0;
  if (iVar1 != 0) {
    *param_9 = iVar1;
    uVar2 = 0xffffffff;
  }
  return uVar2;
}



/* 402a1f40 FUN_402a1f40 */

/* Boundary evidence: original MIPS .pdata 402a1f40..402a200f. Semantic name remains unreviewed. */

undefined4
FUN_402a1f40(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,undefined4 param_6,undefined4 param_7,LPVOID param_8,int param_9,
            DWORD *param_10,int *param_11)

{
  int iVar1;
  undefined4 uVar2;
  DWORD local_28 [2];
  
  if ((param_8 != (LPVOID)0x0) && (param_9 != 0)) {
    local_28[0] = FUN_402a1488(param_8);
    param_10 = local_28;
  }
  iVar1 = (*(code *)&SUB_ffff8fe2)
                    (param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,param_9,
                     param_10);
  uVar2 = 0;
  if (iVar1 != 0) {
    *param_11 = iVar1;
    uVar2 = 0xffffffff;
  }
  return uVar2;
}



/* 402a2010 FUN_402a2010 */

/* Boundary evidence: original MIPS .pdata 402a2010..402a2047. Semantic name remains unreviewed. */

undefined4 FUN_402a2010(void)

{
  int iVar1;
  undefined4 uVar2;
  int *in_stack_00000014;
  
  iVar1 = (*(code *)&SUB_ffff8fce)();
  uVar2 = 0;
  if (iVar1 != 0) {
    *in_stack_00000014 = iVar1;
    uVar2 = 0xffffffff;
  }
  return uVar2;
}



/* 402a2048 FUN_402a2048 */

/* Boundary evidence: original MIPS .pdata 402a2048..402a207f. Semantic name remains unreviewed. */

undefined4 FUN_402a2048(undefined4 param_1,undefined4 param_2,int *param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = (*(code *)&SUB_ffff8fde)();
  uVar2 = 0;
  if (iVar1 != 0) {
    *param_3 = iVar1;
    uVar2 = 0xffffffff;
  }
  return uVar2;
}



/* 402a2080 FUN_402a2080 */

/* Boundary evidence: original MIPS .pdata 402a2080..402a2127. Semantic name remains unreviewed. */

int FUN_402a2080(int param_1,int param_2,int param_3,int param_4,undefined4 param_5,uint param_6,
                DWORD *param_7)

{
  int iVar1;
  DWORD DVar2;
  
  if ((param_6 & 0xfffffffe) == 0) {
    if (param_4 != 0) {
      if (param_1 == -1) {
        param_1 = *(int *)(param_4 + 0x4c);
      }
      if (param_2 == -1) {
        param_2 = *(int *)(param_4 + 0x58);
      }
      if (param_3 == -1) {
        param_3 = *(int *)(param_4 + 0x5c);
      }
    }
    iVar1 = AFDSocket(param_1,param_2,param_3,*(undefined4 *)(param_4 + 0x24),param_4 + 0x14);
    if (iVar1 == 0) {
      DVar2 = GetLastError();
      *param_7 = DVar2;
      iVar1 = -1;
    }
  }
  else {
    iVar1 = -1;
    *param_7 = 0x2726;
  }
  return iVar1;
}



/* 402a2128 FUN_402a2128 */

/* Boundary evidence: original MIPS .pdata 402a2128..402a21f7. Semantic name remains unreviewed. */

undefined4
FUN_402a2128(wchar_t *param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined4 *param_5,
            int *param_6)

{
  int iVar1;
  size_t sVar2;
  int local_20 [2];
  
  if (((param_2 == 0x17) || (param_2 == 2)) || (param_2 == 0)) {
    sVar2 = wcslen(param_1);
    local_20[0] = (sVar2 + 1) * 2;
    iVar1 = (*(code *)&SUB_fffe6f82)
                      (2,param_2,param_4,*param_5,param_5,param_3,0x274,param_1,local_20[0],local_20
                      );
    if (iVar1 == 0) {
      return 0;
    }
  }
  else {
    iVar1 = 0x2726;
  }
  *param_6 = iVar1;
  return 0xffffffff;
}



/* 402a21f8 FUN_402a21f8 */

/* Boundary evidence: original MIPS .pdata 402a21f8..402a2247. Semantic name remains unreviewed. */

undefined4 FUN_402a21f8(void)

{
  return 0;
}



/* 402a2248 FUN_402a2248 */

/* Boundary evidence: original MIPS .pdata 402a2248..402a2253. Semantic name remains unreviewed. */

undefined4 FUN_402a2248(void)

{
  return 1;
}



/* 402a2254 FUN_402a2254 */

/* Boundary evidence: original MIPS .pdata 402a2254..402a23c7. Semantic name remains unreviewed. */

undefined4 FUN_402a2254(uint *param_1,undefined4 *param_2,uint *param_3,uint param_4)

{
  uint *_Dst;
  undefined4 uVar1;
  uint uVar2;
  
  uVar1 = 0;
  if (param_3 == (uint *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = *param_3 & 0xffff;
  }
  if (uVar2 == 0) {
    *param_1 = 0;
    *param_2 = 0;
  }
  else {
    _Dst = LocalAlloc(0,uVar2 * 0x18);
    if (_Dst == (uint *)0x0) {
      uVar1 = 0x2747;
    }
    else {
      memset(_Dst,0,uVar2 * 0x18);
      *param_1 = uVar2;
      *param_2 = _Dst;
      while( true ) {
        param_3 = param_3 + 1;
        if (uVar2 == 0) break;
        _Dst[3] = *param_3;
        *_Dst = *param_3;
        _Dst[2] = param_4;
        _Dst = _Dst + 6;
        uVar2 = uVar2 - 1;
      }
    }
  }
  return uVar1;
}



/* 402a23c8 FUN_402a23c8 */

/* Boundary evidence: original MIPS .pdata 402a23c8..402a23d3. Semantic name remains unreviewed. */

undefined4 FUN_402a23c8(void)

{
  return 1;
}



/* 402a23d4 FUN_402a23d4 */

int FUN_402a23d4(int param_1,int param_2,int *param_3)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  
  if ((param_3 == (int *)0x0) || (param_1 == 0)) {
    iVar1 = 0;
  }
  else {
    piVar3 = param_3 + 1;
    piVar2 = (int *)(param_2 + 4);
    do {
      param_1 = param_1 + -1;
      if (*piVar2 != 0) {
        *piVar3 = piVar2[2];
        piVar3 = piVar3 + 1;
      }
      piVar2 = piVar2 + 6;
    } while (param_1 != 0);
    iVar1 = (int)piVar3 + (-4 - (int)param_3) >> 2;
    *param_3 = iVar1;
  }
  return iVar1;
}



/* 402a242c FUN_402a242c */

/* Boundary evidence: original MIPS .pdata 402a242c..402a2467. Semantic name remains unreviewed. */

undefined4 FUN_402a242c(void)

{
  int iVar1;
  undefined4 uVar2;
  int *in_a3;
  
  iVar1 = (*(code *)&SUB_ffff8fbe)();
  uVar2 = 0;
  if (iVar1 != 0) {
    *in_a3 = iVar1;
    uVar2 = 0xffffffff;
  }
  return uVar2;
}



/* 402a2468 FUN_402a2468 */

/* Boundary evidence: original MIPS .pdata 402a2468..402a24a3. Semantic name remains unreviewed. */

undefined4 FUN_402a2468(void)

{
  int iVar1;
  undefined4 uVar2;
  int *in_a3;
  
  iVar1 = (*(code *)&SUB_ffff8fc2)();
  uVar2 = 0;
  if (iVar1 != 0) {
    *in_a3 = iVar1;
    uVar2 = 0xffffffff;
  }
  return uVar2;
}



/* 402a24a4 FUN_402a24a4 */

/* Boundary evidence: original MIPS .pdata 402a24a4..402a26ff. Semantic name remains unreviewed. */

int FUN_402a24a4(undefined4 param_1,uint *param_2,uint *param_3,uint *param_4,int param_5,
                int *param_6)

{
  int iVar1;
  int iVar2;
  int iVar3;
  HLOCAL pvVar4;
  HLOCAL hMem;
  HLOCAL local_50;
  HLOCAL local_4c;
  HLOCAL local_48;
  int local_44;
  uint local_40;
  uint local_3c;
  uint local_38;
  uint *local_34;
  uint *local_30;
  
  local_48 = (HLOCAL)0x0;
  local_50 = (HLOCAL)0x0;
  hMem = (HLOCAL)0x0;
  local_4c = (HLOCAL)0x0;
  local_34 = param_2;
  local_30 = param_3;
  pvVar4 = (HLOCAL)0x0;
  if ((((param_5 == 0) || (iVar1 = FUN_402a21f8(), iVar1 == 0)) &&
      (iVar1 = FUN_402a2254(&local_38,&local_48,param_2,0x29), iVar1 == 0)) &&
     ((iVar1 = FUN_402a2254(&local_3c,&local_50,param_3,0x12), pvVar4 = local_50, iVar1 == 0 &&
      (iVar1 = FUN_402a2254(&local_40,&local_4c,param_4,0x104), hMem = local_4c, pvVar4 = local_50,
      iVar1 == 0)))) {
    if (local_40 + local_3c + local_38 == 0) {
      return 0;
    }
    iVar1 = AFDSelect(local_38,local_48,local_3c,local_50,local_40,local_4c,param_5);
    if (iVar1 == 0) {
      iVar2 = FUN_402a23d4(local_38,(int)local_48,(int *)local_34);
      local_44 = iVar2;
      iVar3 = FUN_402a23d4(local_3c,(int)pvVar4,(int *)local_30);
      local_44 = iVar3 + iVar2;
      local_44 = FUN_402a23d4(local_40,(int)hMem,(int *)param_4);
      local_44 = local_44 + iVar3 + iVar2;
    }
  }
  if (local_48 != (HLOCAL)0x0) {
    LocalFree(local_48);
  }
  if (pvVar4 != (HLOCAL)0x0) {
    LocalFree(pvVar4);
  }
  if (hMem != (HLOCAL)0x0) {
    LocalFree(hMem);
  }
  if (iVar1 != 0) {
    *param_6 = iVar1;
    local_44 = -1;
  }
  return local_44;
}



/* 402a2700 FUN_402a2700 */

/* Boundary evidence: original MIPS .pdata 402a2700..402a270b. Semantic name remains unreviewed. */

undefined4 FUN_402a2700(void)

{
  return 1;
}



/* 402a279c entry */

/* Boundary evidence: original MIPS .pdata 402a279c..402a280f. Semantic name remains unreviewed. */

undefined4 entry(HMODULE param_1,int param_2)

{
  undefined4 uVar1;
  
  if (param_2 == 1) {
    FUN_402a2810();
    FUN_402a2ae4();
  }
  uVar1 = FUN_402a11f0(param_1,param_2);
  if (param_2 == 0) {
    FUN_402a2a6c();
  }
  return uVar1;
}



/* 402a2810 FUN_402a2810 */

/* Boundary evidence: original MIPS .pdata 402a2810..402a2883. Semantic name remains unreviewed. */

void FUN_402a2810(void)

{
  uint uVar1;
  
  if ((DAT_402a30e0 == 0) || (DAT_402a30e0 == 0xb064)) {
    uVar1 = __security_gen_cookie2();
    DAT_402a30e0 = uVar1 >> 0x10 ^ uVar1 & 0xffff;
    if (DAT_402a30e0 == 0) {
      DAT_402a30e0 = 0xb064;
    }
  }
  DAT_402a30e4 = ~DAT_402a30e0;
  return;
}



/* 402a2884 FUN_402a2884 */

/* Boundary evidence: original MIPS .pdata 402a2884..402a28d7. Semantic name remains unreviewed. */

void FUN_402a2884(int param_1,undefined4 param_2,uint *param_3)

{
  if ((*param_3 & 1) != 0) {
    param_1 = ((-param_3[2] & param_3[1] + param_1) - (param_3[1] + param_1)) + param_1;
  }
  FUN_402a2904(*(uint *)(param_1 + (*param_3 & 0xfffffffc)));
  return;
}



/* 402a28d8 FUN_402a28d8 */

/* Boundary evidence: original MIPS .pdata 402a28d8..402a2903. Semantic name remains unreviewed. */

undefined4 FUN_402a28d8(undefined4 param_1,int param_2,undefined4 param_3,int param_4)

{
  FUN_402a2884(param_2,param_4,*(uint **)(*(int *)(param_4 + 4) + 0xc));
  return 1;
}



/* 402a2904 FUN_402a2904 */

/* Boundary evidence: original MIPS .pdata 402a2904..402a294b. Semantic name remains unreviewed. */

void FUN_402a2904(uint param_1)

{
  if ((param_1 == DAT_402a30e0) && (param_1 >> 0x10 == 0)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __report_gsfailure();
}



/* 402a294c FUN_402a294c */

/* Boundary evidence: original MIPS .pdata 402a294c..402a2a6b. Semantic name remains unreviewed. */

void FUN_402a294c(UINT param_1,int param_2,int param_3)

{
  LPCRITICAL_SECTION lpCriticalSection;
  undefined4 *_Memory;
  
  DAT_402a3104 = (undefined1)param_3;
  if (param_2 == 0) {
    _Memory = DAT_402a3178;
    if (DAT_402a3178 != (undefined4 *)0x0) {
      while (DAT_402a3174 = DAT_402a3174 + -1, _Memory <= DAT_402a3174) {
        if ((code *)*DAT_402a3174 != (code *)0x0) {
          (*(code *)*DAT_402a3174)();
          _Memory = DAT_402a3178;
        }
      }
      free(_Memory);
      DAT_402a3174 = (undefined4 *)0x0;
      DAT_402a3178 = (undefined4 *)0x0;
    }
    FUN_402a2a90((undefined4 *)&DAT_402a1010,(undefined4 *)&DAT_402a1014);
  }
  FUN_402a2a90((undefined4 *)&DAT_402a1018,(undefined4 *)&DAT_402a101c);
  if (param_3 == 0) {
    TerminateProcess((HANDLE)0x42,param_1);
  }
  else {
    lpCriticalSection = (LPCRITICAL_SECTION)InterlockedExchange((LONG *)&DAT_402a317c,0);
    if (lpCriticalSection != (LPCRITICAL_SECTION)0x0) {
      DeleteCriticalSection(lpCriticalSection);
      free(lpCriticalSection);
    }
  }
  return;
}



/* 402a2a6c FUN_402a2a6c */

/* Boundary evidence: original MIPS .pdata 402a2a6c..402a2a8f. Semantic name remains unreviewed. */

void FUN_402a2a6c(void)

{
  FUN_402a294c(0,0,1);
  return;
}



/* 402a2a90 FUN_402a2a90 */

/* Boundary evidence: original MIPS .pdata 402a2a90..402a2ae3. Semantic name remains unreviewed. */

void FUN_402a2a90(undefined4 *param_1,undefined4 *param_2)

{
  for (; param_1 < param_2; param_1 = param_1 + 1) {
    if ((code *)*param_1 != (code *)0x0) {
      (*(code *)*param_1)();
    }
  }
  return;
}



/* 402a2ae4 FUN_402a2ae4 */

/* Boundary evidence: original MIPS .pdata 402a2ae4..402a2b1f. Semantic name remains unreviewed. */

void FUN_402a2ae4(void)

{
  FUN_402a2a90((undefined4 *)&DAT_402a1008,(undefined4 *)&DAT_402a100c);
  FUN_402a2a90((undefined4 *)&DAT_402a1000,(undefined4 *)&DAT_402a1004);
  return;
}


