/* Automatic Ghidra pseudocode. Not original source; not runtime-verified. */

/* 40331064 DllMain */

/* Boundary evidence: original MIPS .pdata 40331064..4033109f. Semantic name remains unreviewed. */

undefined4 DllMain(HMODULE param_1,int param_2)

{
                    /* 0x1064  5  DllMain */
  if (param_2 == 1) {
    DAT_40333074 = param_1;
    DisableThreadLibraryCalls(param_1);
  }
  return 1;
}



/* 403310a0 FUN_403310a0 */

/* Boundary evidence: original MIPS .pdata 403310a0..40331233. Semantic name remains unreviewed. */

int FUN_403310a0(byte *param_1,int param_2,byte *param_3)

{
  byte bVar1;
  byte bVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  byte *pbVar6;
  
  iVar4 = 1;
  memset(param_3,0,0x1c);
  do {
    if (param_2 == 0) {
      return 0;
    }
    bVar1 = *param_1;
    pbVar6 = param_1 + 1;
    iVar5 = param_2 + -1;
    if (bVar1 != 0) {
      if (bVar1 == 0xff) {
        return iVar4;
      }
      if (iVar5 == 0) {
        return 0;
      }
      bVar2 = *pbVar6;
      uVar3 = (uint)bVar2;
      pbVar6 = param_1 + 2;
      if (param_2 - 2U < uVar3) {
        return 0;
      }
      if (bVar1 == 0x32) {
        if (uVar3 == 4) {
          *(byte **)(param_3 + 4) = pbVar6;
        }
        else {
LAB_403311f0:
          iVar4 = 0;
        }
      }
      else if (bVar1 == 0x35) {
        if (((uVar3 != 1) || (bVar1 = *pbVar6, bVar1 == 0)) || (8 < bVar1)) goto LAB_403311f0;
        *param_3 = bVar1;
      }
      else if (bVar1 == 0x36) {
        if (uVar3 != 4) goto LAB_403311f0;
        *(byte **)(param_3 + 8) = pbVar6;
      }
      else if (bVar1 == 0x37) {
        param_3[0x14] = bVar2;
        *(byte **)(param_3 + 0x18) = pbVar6;
      }
      else if (bVar1 == 0x3d) {
        if (uVar3 < 2) goto LAB_403311f0;
        bVar1 = *pbVar6;
        param_3[0xd] = bVar2 - 1;
        param_3[0xc] = bVar1;
        *(byte **)(param_3 + 0x10) = param_1 + 3;
      }
      pbVar6 = pbVar6 + uVar3;
      iVar5 = (param_2 - 2U) - uVar3;
    }
    param_2 = iVar5;
    param_1 = pbVar6;
    if (iVar4 == 0) {
      return 0;
    }
  } while( true );
}



/* 40331234 FUN_40331234 */

void FUN_40331234(undefined1 *param_1,undefined1 param_2,undefined4 *param_3,int param_4)

{
  undefined1 *puVar1;
  undefined4 uVar2;
  
  *param_1 = param_2;
  param_1[1] = (char)(param_4 << 2);
  puVar1 = param_1 + 2;
  for (; param_4 != 0; param_4 = param_4 + -1) {
    uVar2 = *param_3;
    *puVar1 = (char)((uint)uVar2 >> 0x18);
    puVar1[1] = (char)((uint)uVar2 >> 0x10);
    puVar1[2] = (char)((uint)uVar2 >> 8);
    param_3 = param_3 + 1;
    puVar1[3] = (char)uVar2;
    puVar1 = puVar1 + 4;
  }
  return;
}



/* 40331298 FUN_40331298 */

/* Boundary evidence: original MIPS .pdata 40331298..40331593. Semantic name remains unreviewed. */

byte * FUN_40331298(int *param_1,byte *param_2,void *param_3,uint param_4,void *param_5,
                   size_t param_6)

{
  byte bVar1;
  void *pvVar2;
  size_t sVar3;
  int *piVar4;
  int iVar5;
  uint uVar6;
  size_t _MaxCount;
  char *_Str;
  
  _MaxCount = 0;
  if (param_4 != 0) {
    do {
      bVar1 = *(byte *)(_MaxCount + (int)param_3);
      uVar6 = (uint)bVar1;
      pvVar2 = memchr(param_5,uVar6,param_6);
      if ((pvVar2 == (void *)0x0) &&
         (pvVar2 = memchr(param_3,uVar6,_MaxCount), pvVar2 == (void *)0x0)) {
        if (uVar6 < 0x2d) {
          if (uVar6 == 0x2c) {
            iVar5 = param_1[0x13];
            if (iVar5 != 0) {
              piVar4 = param_1 + 0xf;
LAB_403313c0:
              param_2 = (byte *)FUN_40331234(param_2,bVar1,piVar4,iVar5);
            }
          }
          else if (uVar6 == 1) {
            iVar5 = param_1[4];
            if (iVar5 != 0) goto LAB_40331510;
          }
          else if (uVar6 == 3) {
            iVar5 = param_1[3];
            if (iVar5 != 0) goto LAB_403313e0;
          }
          else if (uVar6 == 6) {
            iVar5 = param_1[10];
            if (iVar5 != 0) {
              piVar4 = param_1 + 6;
              goto LAB_403313c0;
            }
          }
          else if ((uVar6 == 0xf) && (_Str = (char *)param_1[0xb], _Str != (char *)0x0)) {
            sVar3 = strlen(_Str);
            *param_2 = bVar1;
            sVar3 = sVar3 + 1;
            param_2[1] = (byte)sVar3;
            memcpy(param_2 + 2,_Str,sVar3);
            param_2 = param_2 + 2 + sVar3;
          }
        }
        else {
          if (uVar6 == 0x33) {
            iVar5 = param_1[5];
LAB_40331510:
            *param_2 = bVar1;
            param_2[1] = 4;
            param_2[2] = (byte)((uint)iVar5 >> 0x18);
            param_2[3] = (byte)((uint)iVar5 >> 0x10);
            param_2[4] = (byte)((uint)iVar5 >> 8);
LAB_40331544:
            param_2[5] = (byte)iVar5;
          }
          else if (uVar6 == 0x36) {
            iVar5 = *param_1;
LAB_403313e0:
            *param_2 = bVar1;
            param_2[1] = 4;
            param_2[2] = (byte)((uint)iVar5 >> 0x18);
            param_2[3] = (byte)((uint)iVar5 >> 0x10);
            param_2[4] = (byte)((uint)iVar5 >> 8);
            param_2[5] = (byte)iVar5;
          }
          else {
            if (uVar6 != 0x3a) {
              if (uVar6 != 0x3b) goto LAB_4033154c;
              uVar6 = param_1[5];
              *param_2 = bVar1;
              iVar5 = (uVar6 >> 3) * 7;
              param_2[1] = 4;
              param_2[2] = (byte)((uint)iVar5 >> 0x18);
              param_2[3] = (byte)((uint)iVar5 >> 0x10);
              param_2[4] = (byte)((uint)iVar5 >> 8);
              goto LAB_40331544;
            }
            uVar6 = param_1[5];
            *param_2 = bVar1;
            param_2[1] = 4;
            param_2[2] = (byte)(uVar6 >> 0x19);
            param_2[3] = (byte)(uVar6 >> 0x11);
            param_2[4] = (byte)(uVar6 >> 9);
            param_2[5] = (byte)(uVar6 >> 1);
          }
          param_2 = param_2 + 6;
        }
      }
LAB_4033154c:
      _MaxCount = _MaxCount + 1;
    } while (_MaxCount < param_4);
  }
  return param_2;
}



/* 40331594 FUN_40331594 */

/* Boundary evidence: original MIPS .pdata 40331594..403315e7. Semantic name remains unreviewed. */

int FUN_40331594(int param_1)

{
  HLOCAL pvVar1;
  int iVar2;
  uint uVar3;
  
  uVar3 = *(uint *)(param_1 + 0x34);
  iVar2 = 0;
  if ((uVar3 < 0x1000000) && (pvVar1 = LocalAlloc(0,uVar3 + 0x228), pvVar1 != (HLOCAL)0x0)) {
    iVar2 = (int)pvVar1 + uVar3;
  }
  return iVar2;
}



/* 403315e8 DHCPServerFreePacket */

/* Boundary evidence: original MIPS .pdata 403315e8..40331607. Semantic name remains unreviewed. */

void DHCPServerFreePacket(int param_1,int param_2)

{
                    /* 0x15e8  1  DHCPServerFreePacket */
  LocalFree((HLOCAL)(param_2 - *(int *)(param_1 + 0x34)));
  return;
}



/* 40331608 FUN_40331608 */

/* Boundary evidence: original MIPS .pdata 40331608..4033168f. Semantic name remains unreviewed. */

void FUN_40331608(undefined4 param_1,int param_2,undefined1 *param_3)

{
  memset(param_3,0,0xf0);
  *param_3 = 2;
  param_3[1] = *(undefined1 *)(param_2 + 1);
  param_3[2] = *(undefined1 *)(param_2 + 2);
  *(undefined4 *)(param_3 + 4) = *(undefined4 *)(param_2 + 4);
  memcpy(param_3 + 0x1c,(void *)(param_2 + 0x1c),0x10);
  *(undefined4 *)(param_3 + 0xec) = 0x63538263;
  return;
}



/* 40331690 FUN_40331690 */

/* Boundary evidence: original MIPS .pdata 40331690..40331833. Semantic name remains unreviewed. */

undefined4 FUN_40331690(int *param_1,int param_2,int param_3)

{
  bool bVar1;
  undefined1 *puVar2;
  byte *pbVar3;
  int iVar4;
  undefined4 uVar5;
  
  uVar5 = 0;
  if (param_1[0x14] == 0) {
    bVar1 = true;
  }
  else {
    iVar4 = memcmp(param_1 + 0x15,(void *)(param_2 + 0x1c),6);
    bVar1 = true;
    if (iVar4 != 0) {
      bVar1 = false;
    }
  }
  if (bVar1) {
    puVar2 = (undefined1 *)FUN_40331594((int)param_1);
    if (puVar2 != (undefined1 *)0x0) {
      FUN_40331608(param_1,param_2,puVar2);
      iVar4 = param_1[1];
      puVar2[0x10] = (char)((uint)iVar4 >> 0x18);
      puVar2[0x11] = (char)((uint)iVar4 >> 0x10);
      puVar2[0x12] = (char)((uint)iVar4 >> 8);
      puVar2[0x13] = (char)iVar4;
      iVar4 = *param_1;
      puVar2[0x14] = (char)((uint)iVar4 >> 0x18);
      puVar2[0x15] = (char)((uint)iVar4 >> 0x10);
      puVar2[0x16] = (char)((uint)iVar4 >> 8);
      puVar2[0x17] = (char)iVar4;
      puVar2[0xf0] = 0x35;
      puVar2[0xf1] = 1;
      puVar2[0xf2] = 2;
      pbVar3 = FUN_40331298(param_1,puVar2 + 0xf3,&DAT_40333040,5,(void *)0x0,0);
      pbVar3 = FUN_40331298(param_1,pbVar3,*(void **)(param_3 + 0x18),
                            (uint)*(byte *)(param_3 + 0x14),&DAT_40333040,5);
      *pbVar3 = 0xff;
      (*(code *)param_1[0xe])(param_1[0xc],*param_1,param_1[1],puVar2,pbVar3 + (1 - (int)puVar2));
      uVar5 = 1;
    }
  }
  else {
    uVar5 = 0;
  }
  return uVar5;
}



/* 40331834 FUN_40331834 */

/* Boundary evidence: original MIPS .pdata 40331834..403319af. Semantic name remains unreviewed. */

undefined4 FUN_40331834(int *param_1,int param_2,int param_3)

{
  bool bVar1;
  undefined1 *puVar2;
  byte *pbVar3;
  int iVar4;
  undefined4 uVar5;
  
  uVar5 = 0;
  if (param_1[0x14] == 0) {
    bVar1 = true;
  }
  else {
    iVar4 = memcmp(param_1 + 0x15,(void *)(param_2 + 0x1c),6);
    bVar1 = true;
    if (iVar4 != 0) {
      bVar1 = false;
    }
  }
  if (bVar1) {
    puVar2 = (undefined1 *)FUN_40331594((int)param_1);
    if (puVar2 != (undefined1 *)0x0) {
      FUN_40331608(param_1,param_2,puVar2);
      iVar4 = param_1[1];
      puVar2[0x10] = (char)((uint)iVar4 >> 0x18);
      puVar2[0x11] = (char)((uint)iVar4 >> 0x10);
      puVar2[0x12] = (char)((uint)iVar4 >> 8);
      puVar2[0x13] = (char)iVar4;
      puVar2[0xf0] = 0x35;
      puVar2[0xf1] = 1;
      puVar2[0xf2] = 5;
      pbVar3 = FUN_40331298(param_1,puVar2 + 0xf3,&DAT_40333040,5,(void *)0x0,0);
      pbVar3 = FUN_40331298(param_1,pbVar3,*(void **)(param_3 + 0x18),
                            (uint)*(byte *)(param_3 + 0x14),&DAT_40333040,5);
      *pbVar3 = 0xff;
      (*(code *)param_1[0xe])(param_1[0xc],*param_1,param_1[1],puVar2,pbVar3 + (1 - (int)puVar2));
      uVar5 = 1;
    }
  }
  else {
    uVar5 = 0;
  }
  return uVar5;
}



/* 403319b8 DHCPServerProcessPacket */

/* Boundary evidence: original MIPS .pdata 403319b8..40331a7f. Semantic name remains unreviewed. */

undefined4 DHCPServerProcessPacket(undefined4 param_1,char *param_2,uint param_3)

{
  int iVar1;
  undefined4 uVar2;
  byte local_38 [32];
  
                    /* 0x19b8  2  DHCPServerProcessPacket */
  uVar2 = 0;
  if ((((0xef < param_3) && (*param_2 == '\x01')) &&
      (iVar1 = memcmp(param_2 + 0xec,&DAT_4033103c,4), iVar1 == 0)) &&
     ((iVar1 = FUN_403310a0((byte *)(param_2 + 0xf0),param_3 - 0xf0,local_38), iVar1 != 0 &&
      (*(code **)(&DAT_40333048 + (uint)local_38[0] * 4) != (code *)0x0)))) {
    uVar2 = (**(code **)(&DAT_40333048 + (uint)local_38[0] * 4))(param_1,param_2,local_38);
  }
  return uVar2;
}



/* 40331a80 DHCPServerSessionNew */

/* Boundary evidence: original MIPS .pdata 40331a80..40331b0f. Semantic name remains unreviewed. */

void DHCPServerSessionNew(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  
                    /* 0x1a80  4  DHCPServerSessionNew */
  puVar1 = LocalAlloc(0x40,0x5c);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = 0xc0a80001;
    puVar1[3] = 0xc0a80001;
    puVar1[1] = 0xc0a80002;
    puVar1[2] = 1;
    puVar1[4] = 0xffff0000;
    puVar1[5] = 0x278d00;
    puVar1[0xc] = param_1;
    puVar1[0xe] = param_2;
    puVar1[0xd] = param_3;
  }
  return;
}



/* 40331b10 DHCPServerSessionDelete */

/* Boundary evidence: original MIPS .pdata 40331b10..40331b3f. Semantic name remains unreviewed. */

void DHCPServerSessionDelete(HLOCAL param_1)

{
                    /* 0x1b10  3  DHCPServerSessionDelete */
  LocalFree(*(HLOCAL *)((int)param_1 + 0x2c));
  LocalFree(param_1);
  return;
}



/* 40331b60 FUN_40331b60 */

/* Boundary evidence: original MIPS .pdata 40331b60..40331c9b. Semantic name remains unreviewed. */

int FUN_40331b60(HMODULE param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 1;
  if (param_2 == 1) {
    if (DAT_40333088 != (code *)0x0) {
      iVar2 = (*DAT_40333088)(param_1,1,param_3);
    }
    iVar1 = 0;
    if (iVar2 == 0) goto LAB_40331c10;
    FUN_40331eb8();
  }
  iVar1 = 0;
  if (iVar2 != 0) {
    iVar1 = DllMain(param_1,param_2);
  }
LAB_40331c10:
  if (((param_2 == 0) && (FUN_40331e40(), iVar1 != 0)) && (DAT_40333088 != (code *)0x0)) {
    iVar1 = (*DAT_40333088)(param_1,0,param_3);
  }
  return iVar1;
}



/* 40331c9c FUN_40331c9c */

/* Boundary evidence: original MIPS .pdata 40331c9c..40331cc7. Semantic name remains unreviewed. */

void FUN_40331c9c(_EXCEPTION_POINTERS *param_1)

{
  _XcptFilter(param_1->ExceptionRecord->ExceptionCode,param_1);
  return;
}



/* 40331cc8 entry */

/* Boundary evidence: original MIPS .pdata 40331cc8..40331d1f. Semantic name remains unreviewed. */

void entry(HMODULE param_1,int param_2,undefined4 param_3)

{
  if (param_2 == 1) {
    FUN_40331ef4();
  }
  FUN_40331b60(param_1,param_2,param_3);
  return;
}



/* 40331d20 FUN_40331d20 */

/* Boundary evidence: original MIPS .pdata 40331d20..40331e3f. Semantic name remains unreviewed. */

void FUN_40331d20(UINT param_1,int param_2,int param_3)

{
  LPCRITICAL_SECTION lpCriticalSection;
  undefined4 *_Memory;
  
  DAT_40333078 = (undefined1)param_3;
  if (param_2 == 0) {
    _Memory = DAT_40333080;
    if (DAT_40333080 != (undefined4 *)0x0) {
      while (DAT_4033307c = DAT_4033307c + -1, _Memory <= DAT_4033307c) {
        if ((code *)*DAT_4033307c != (code *)0x0) {
          (*(code *)*DAT_4033307c)();
          _Memory = DAT_40333080;
        }
      }
      free(_Memory);
      DAT_4033307c = (undefined4 *)0x0;
      DAT_40333080 = (undefined4 *)0x0;
    }
    FUN_40331e64((undefined4 *)&DAT_40331010,(undefined4 *)&DAT_40331014);
  }
  FUN_40331e64((undefined4 *)&DAT_40331018,(undefined4 *)&DAT_4033101c);
  if (param_3 == 0) {
    TerminateProcess((HANDLE)0x42,param_1);
  }
  else {
    lpCriticalSection = (LPCRITICAL_SECTION)InterlockedExchange((LONG *)&DAT_40333084,0);
    if (lpCriticalSection != (LPCRITICAL_SECTION)0x0) {
      DeleteCriticalSection(lpCriticalSection);
      free(lpCriticalSection);
    }
  }
  return;
}



/* 40331e40 FUN_40331e40 */

/* Boundary evidence: original MIPS .pdata 40331e40..40331e63. Semantic name remains unreviewed. */

void FUN_40331e40(void)

{
  FUN_40331d20(0,0,1);
  return;
}



/* 40331e64 FUN_40331e64 */

/* Boundary evidence: original MIPS .pdata 40331e64..40331eb7. Semantic name remains unreviewed. */

void FUN_40331e64(undefined4 *param_1,undefined4 *param_2)

{
  for (; param_1 < param_2; param_1 = param_1 + 1) {
    if ((code *)*param_1 != (code *)0x0) {
      (*(code *)*param_1)();
    }
  }
  return;
}



/* 40331eb8 FUN_40331eb8 */

/* Boundary evidence: original MIPS .pdata 40331eb8..40331ef3. Semantic name remains unreviewed. */

void FUN_40331eb8(void)

{
  FUN_40331e64((undefined4 *)&DAT_40331008,(undefined4 *)&DAT_4033100c);
  FUN_40331e64((undefined4 *)&DAT_40331000,(undefined4 *)&DAT_40331004);
  return;
}



/* 40331ef4 FUN_40331ef4 */

/* Boundary evidence: original MIPS .pdata 40331ef4..40331f67. Semantic name remains unreviewed. */

void FUN_40331ef4(void)

{
  uint uVar1;
  
  if ((DAT_4033306c == 0) || (DAT_4033306c == 0xb064)) {
    uVar1 = __security_gen_cookie2();
    DAT_4033306c = uVar1 >> 0x10 ^ uVar1 & 0xffff;
    if (DAT_4033306c == 0) {
      DAT_4033306c = 0xb064;
    }
  }
  DAT_40333070 = ~DAT_4033306c;
  return;
}


