/* Automatic Ghidra pseudocode. Not original source; not runtime-verified. */

/* c05c147c FUN_c05c147c */

/* Boundary evidence: original MIPS .pdata c05c147c..c05c165f. Semantic name remains unreviewed. */

int FUN_c05c147c(char *param_1,int param_2,undefined4 *param_3)

{
  int iVar1;
  HLOCAL _Dst;
  undefined4 *puVar2;
  char *pcVar3;
  int iVar4;
  char *pcVar5;
  char *_Src;
  int iVar6;
  int *piVar7;
  size_t _Size;
  undefined **ppuVar8;
  
  iVar4 = 0;
  puVar2 = param_3;
  do {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  } while (puVar2 != param_3 + 3);
  if (param_2 != 0) {
    do {
      _Src = (char *)0x0;
      pcVar3 = param_1;
      pcVar5 = param_1;
      if (param_2 == 0) {
LAB_c05c1658:
        iVar4 = -0x7fffbffb;
      }
      else {
        do {
          pcVar5 = pcVar3 + 1;
          param_2 = param_2 + -1;
          if (*pcVar3 == ',') break;
          if (*pcVar3 == '=') {
            _Src = pcVar5;
          }
          pcVar3 = pcVar5;
        } while (param_2 != 0);
        if (_Src == (char *)0x0) goto LAB_c05c1658;
        _Size = (int)pcVar3 - (int)_Src;
        ppuVar8 = &PTR_s_networkid_c05c106c;
        iVar6 = 0;
        do {
          iVar1 = strncmp(*ppuVar8,param_1,(size_t)(_Src + (-1 - (int)param_1)));
          if (iVar1 == 0) break;
          ppuVar8 = ppuVar8 + 1;
          iVar6 = iVar6 + 1;
        } while ((int)ppuVar8 < -0x3fa3ef88);
        if (iVar6 < 3) {
          piVar7 = param_3 + iVar6;
          if (*piVar7 == 0) {
            _Dst = LocalAlloc(0x40,_Size + 1);
            *piVar7 = (int)_Dst;
            if (_Dst != (HLOCAL)0x0) {
              memcpy(_Dst,_Src,_Size);
              *(undefined1 *)(*piVar7 + _Size) = 0;
              goto LAB_c05c15ec;
            }
          }
          iVar4 = -0x7fffbffb;
        }
      }
LAB_c05c15ec:
      param_1 = pcVar5;
    } while (param_2 != 0);
    if (iVar4 != 0) {
      iVar6 = 3;
      do {
        LocalFree((HLOCAL)*param_3);
        iVar6 = iVar6 + -1;
        *param_3 = 0;
        param_3 = param_3 + 1;
      } while (iVar6 != 0);
    }
  }
  return iVar4;
}



/* c05c1660 FUN_c05c1660 */

/* Boundary evidence: original MIPS .pdata c05c1660..c05c168f. Semantic name remains unreviewed. */

void FUN_c05c1660(int param_1,undefined4 param_2,undefined4 param_3)

{
  EolSSConnectionDataSet
            (*(undefined4 *)(param_1 + 0x28),(uint)*(byte *)(*(int *)(param_1 + 0xf8) + 0xc4),
             param_2,param_3);
  return;
}



/* c05c1690 FUN_c05c1690 */

/* Boundary evidence: original MIPS .pdata c05c1690..c05c16bf. Semantic name remains unreviewed. */

void FUN_c05c1690(int param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_c05c2ea4(*(undefined4 *)(param_1 + 0x28),(uint)*(byte *)(*(int *)(param_1 + 0xf8) + 0xc4),
               param_2,param_3);
  return;
}



/* c05c16c8 FUN_c05c16c8 */

/* Boundary evidence: original MIPS .pdata c05c16c8..c05c1753. Semantic name remains unreviewed. */

undefined4 FUN_c05c16c8(int param_1)

{
  int *piVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c05ca1b0);
  piVar1 = (int *)DAT_c05ca1c8;
  do {
    if (piVar1 == (int *)0x0) {
LAB_c05c1730:
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c05ca1b0);
      return uVar2;
    }
    if (piVar1 == (int *)param_1) {
      piVar1[1] = piVar1[1] + 1;
      uVar2 = 1;
      goto LAB_c05c1730;
    }
    piVar1 = (int *)*piVar1;
  } while( true );
}



/* c05c1754 FUN_c05c1754 */

/* Boundary evidence: original MIPS .pdata c05c1754..c05c1867. Semantic name remains unreviewed. */

undefined4 FUN_c05c1754(int param_1,int param_2)

{
  undefined2 *puVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined2 uVar7;
  
  uVar4 = 0;
  if (param_2 == 0) {
    return 0;
  }
  iVar2 = *(int *)(param_2 + 0x1c);
  if ((iVar2 != 7) && (iVar2 != 6)) {
    return 0;
  }
  iVar3 = *(int *)(param_2 + 0x18);
  uVar5 = 2;
  if (iVar3 == 0) {
    uVar6 = 1;
LAB_c05c17cc:
    uVar7 = 1;
LAB_c05c17d0:
    if (iVar2 == 6) {
      uVar5 = 1;
    }
    else if (iVar2 != 7) goto LAB_c05c17e0;
    puVar1 = operator_new(0x148);
    if (puVar1 == (undefined2 *)0x0) {
      puVar1 = (undefined2 *)0x0;
    }
    else {
      puVar1 = FUN_c05c4b40(puVar1);
    }
    if (puVar1 == (undefined2 *)0x0) {
      uVar4 = 0xe;
    }
    else {
      FUN_c05c4b04(puVar1,uVar7);
      FUN_c05c4b0c((int)puVar1,uVar6,uVar5);
      *(undefined2 **)(param_1 + 0x148) = puVar1;
    }
  }
  else {
    uVar6 = 4;
    if (iVar3 == 4) {
      uVar6 = 2;
      goto LAB_c05c17cc;
    }
    if (iVar3 == 6) {
      uVar7 = 2;
      goto LAB_c05c17d0;
    }
LAB_c05c17e0:
    uVar4 = 0x57;
  }
  return uVar4;
}



/* c05c1868 EolSessionCreate */

/* Boundary evidence: original MIPS .pdata c05c1868..c05c1b17. Semantic name remains unreviewed. */

undefined4 *
EolSessionCreate(undefined4 param_1,undefined4 param_2,undefined4 param_3,uint param_4,
                undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 *param_8,
                undefined4 param_9)

{
  undefined4 *_Dst;
  int iVar1;
  
                    /* 0x1868  12  EolSessionCreate */
  if (param_4 < 0x10000) {
    _Dst = LocalAlloc(0x40,param_4 + 0x374);
    if (_Dst == (undefined4 *)0x0) {
      return (undefined4 *)0x0;
    }
    memset(_Dst,0,0x310);
    iVar1 = FUN_c05c1754((int)_Dst,(int)param_8);
    if (iVar1 == 0) {
      _Dst[1] = 1;
      _Dst[7] = param_2;
      InitializeCriticalSection((LPCRITICAL_SECTION)(_Dst + 2));
      CTEInitTimer(_Dst + 0xc);
      _Dst[0x15] = 3;
      _Dst[0x16] = 3;
      _Dst[0x17] = 500;
      _Dst[0x19] = 0x3c;
      _Dst[0xbd] = 5;
      _Dst[0xbf] = 0x10;
      _Dst[0x18] = 0x1e;
      _Dst[0xbe] = 0;
      _Dst[0x1a] = 0;
      RegReadValues(0x80000002,L"Comm\\EAPOL",L"MaxStart",4,0,_Dst + 0x15,4,L"StartPeriodSeconds",4,
                    0,_Dst + 0x16,4,L"StartDelayMilliseconds",4,0,_Dst + 0x17,4,L"AuthPeriodSeconds"
                    ,4,0,_Dst + 0x18,4,L"HeldPeriodSeconds",4,0,_Dst + 0x19,4,
                    L"ConfirmIdentityOnNewConnection",4,0,_Dst + 0x1a,4,L"WPAPeriodSeconds",4,0,
                    _Dst + 0xbd,4,L"WPAMediaSenseAutodetect",4,0,_Dst + 0xbe,4,
                    L"WPAMax4WayHandshakeFailures",4,0,_Dst + 0xbf,4,0);
      _Dst[0x1b] = param_1;
      _Dst[0x1c] = param_3;
      _Dst[0x1d] = param_4;
      _Dst[0x1f] = param_5;
      _Dst[0x20] = param_6;
      _Dst[0x21] = param_7;
      _Dst[0xc2] = param_9;
      FUN_c05c6388((int)_Dst,param_8);
      _Dst[0x1e] = (int)_Dst + param_4 + 0x310;
      EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c05ca1b0);
      *_Dst = DAT_c05ca1c8;
      DAT_c05ca1c8 = _Dst;
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c05ca1b0);
      return _Dst;
    }
    LocalFree(_Dst);
  }
  return (undefined4 *)0x0;
}



/* c05c1b18 EolSessionUserLogon */

/* Boundary evidence: original MIPS .pdata c05c1b18..c05c1b5b. Semantic name remains unreviewed. */

void EolSessionUserLogon(int *param_1)

{
                    /* 0x1b18  25  EolSessionUserLogon */
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 2));
  FUN_c05c76b4(param_1);
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 2));
  return;
}



/* c05c1b5c EolSessionUserLogoff */

/* Boundary evidence: original MIPS .pdata c05c1b5c..c05c1b9f. Semantic name remains unreviewed. */

void EolSessionUserLogoff(int *param_1)

{
                    /* 0x1b5c  24  EolSessionUserLogoff */
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 2));
  FUN_c05c76dc(param_1);
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 2));
  return;
}



/* c05c1ba0 FUN_c05c1ba0 */

/* Boundary evidence: original MIPS .pdata c05c1ba0..c05c1cdf. Semantic name remains unreviewed. */

undefined4 FUN_c05c1ba0(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  HLOCAL pvVar2;
  uint local_20;
  uint local_1c;
  
  local_20 = 0;
  local_1c = 0;
  pvVar2 = (HLOCAL)0x0;
  iVar1 = EolSSConnectionDataGet(param_2,param_3,0,&local_1c);
  if (iVar1 == 0x25b) {
    pvVar2 = LocalAlloc(0x40,local_1c);
    if (pvVar2 == (HLOCAL)0x0) {
      return 0xe;
    }
    iVar1 = EolSSConnectionDataGet(param_2,param_3,pvVar2,&local_1c);
  }
  if (iVar1 == 0) {
    EapSessionSetConnectionData(*(undefined4 *)(param_1 + 0xf8),pvVar2,local_1c);
  }
  LocalFree(pvVar2);
  local_20 = 0;
  pvVar2 = (HLOCAL)0x0;
  iVar1 = FUN_c05c2dc4(param_2,param_3,0,&local_20);
  if (iVar1 == 0x25b) {
    pvVar2 = LocalAlloc(0x40,local_20);
    if (pvVar2 == (HLOCAL)0x0) goto LAB_c05c1cb0;
    iVar1 = FUN_c05c2dc4(param_2,param_3,pvVar2,&local_20);
  }
  if (iVar1 == 0) {
    EapSessionSetUserData(*(undefined4 *)(param_1 + 0xf8),pvVar2,local_20);
  }
LAB_c05c1cb0:
  LocalFree(pvVar2);
  return 0;
}



/* c05c1ce0 FUN_c05c1ce0 */

/* Boundary evidence: original MIPS .pdata c05c1ce0..c05c1dbb. Semantic name remains unreviewed. */

undefined4 FUN_c05c1ce0(int *param_1,int *param_2,uint param_3)

{
  uint uVar1;
  uint uVar2;
  uint *puVar3;
  
  if ((3 < param_3) && (*param_2 == 0)) {
    uVar2 = param_3 - 4;
    for (puVar3 = (uint *)(param_2 + 1); ((uVar2 != 0 && (0xf < uVar2)) && (*puVar3 <= uVar2));
        puVar3 = (uint *)(*puVar3 + (int)puVar3)) {
      uVar1 = param_1[0xbc];
      if (2 < uVar1) {
        if (uVar1 < 5) {
          if (param_1[0x53] != 0) {
            FUN_c05c630c(param_1,puVar3[3] & 0xe);
          }
        }
        else if ((5 < uVar1) && (uVar1 < 8)) {
          FUN_c05c4c84((int)param_1,puVar3[3] & 0xe);
        }
      }
      uVar2 = uVar2 - *puVar3;
    }
  }
  return 0;
}



/* c05c1dbc EolSessionSetStartDelay */

void EolSessionSetStartDelay(int param_1,undefined4 param_2)

{
                    /* 0x1dbc  22  EolSessionSetStartDelay */
  *(undefined4 *)(param_1 + 0x5c) = param_2;
  return;
}



/* c05c1dc4 EolSessionGetSendKey */

/* Boundary evidence: original MIPS .pdata c05c1dc4..c05c1e3f. Semantic name remains unreviewed. */

undefined4 EolSessionGetSendKey(int param_1,void *param_2,uint *param_3)

{
  uint _Size;
  undefined4 uVar1;
  
                    /* 0x1dc4  14  EolSessionGetSendKey */
  _Size = *(uint *)(param_1 + 0xc4);
  uVar1 = 0;
  if (_Size == 0) {
    uVar1 = 0x490;
  }
  else if (*param_3 < _Size) {
    uVar1 = 0x25b;
  }
  else {
    memcpy(param_2,(void *)(param_1 + 0xa4),_Size);
    *param_3 = *(uint *)(param_1 + 0xc4);
  }
  return uVar1;
}



/* c05c1e40 FUN_c05c1e40 */

/* Boundary evidence: original MIPS .pdata c05c1e40..c05c1eaf. Semantic name remains unreviewed. */

void FUN_c05c1e40(void)

{
  if (DAT_c05ca1c4 == '\0') {
    DAT_c05ca1c8 = 0;
    InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_c05ca1b0);
    DAT_c05ca1c4 = '\x01';
    DAT_c05ca130 = CxLogRegister(&DAT_c05c1210,&PTR_DAT_c05ca128,1,&DAT_c05ca12c);
  }
  return;
}



/* c05c1eb0 DllEntry */

/* Boundary evidence: original MIPS .pdata c05c1eb0..c05c1f27. Semantic name remains unreviewed. */

undefined4 DllEntry(HMODULE param_1,int param_2)

{
                    /* 0x1eb0  1  DllEntry */
  if (param_2 == 0) {
    DAT_c05ca1c4 = 0;
    CxLogDeregister(DAT_c05ca130);
    DeleteCriticalSection((LPCRITICAL_SECTION)&DAT_c05ca1b0);
  }
  else if (param_2 == 1) {
    FUN_c05c1e40();
    DisableThreadLibraryCalls(param_1);
  }
  return 1;
}



/* c05c1f28 DllMain */

/* Boundary evidence: original MIPS .pdata c05c1f28..c05c1f43. Semantic name remains unreviewed. */

void DllMain(HMODULE param_1,int param_2)

{
                    /* 0x1f28  2  DllMain */
  DllEntry(param_1,param_2);
  return;
}



/* c05c1f44 FUN_c05c1f44 */

/* Boundary evidence: original MIPS .pdata c05c1f44..c05c2043. Semantic name remains unreviewed. */

void FUN_c05c1f44(int *param_1)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  void *pvVar4;
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_c05ca1b0);
  iVar1 = param_1[1];
  param_1[1] = iVar1 + -1;
  if (iVar1 + -1 == 0) {
    piVar3 = &DAT_c05ca1c8;
    do {
      piVar2 = piVar3;
      if (*piVar2 == 0) goto LAB_c05c2020;
      piVar3 = (int *)*piVar2;
    } while ((int *)*piVar2 != param_1);
    if (param_1[0x3e] != 0) {
      EapSessionDestroy();
      param_1[0x3e] = 0;
    }
    *piVar2 = *param_1;
    DeleteCriticalSection((LPCRITICAL_SECTION)(param_1 + 2));
    LocalFree((HLOCAL)param_1[10]);
    piVar3 = param_1 + 0x3b;
    iVar1 = 3;
    do {
      LocalFree((HLOCAL)*piVar3);
      iVar1 = iVar1 + -1;
      piVar3 = piVar3 + 1;
    } while (iVar1 != 0);
    pvVar4 = (void *)param_1[0x52];
    if (pvVar4 != (void *)0x0) {
      FUN_c05c4bf4((int)pvVar4);
      operator_delete(pvVar4);
    }
    LocalFree(param_1);
  }
LAB_c05c2020:
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_c05ca1b0);
  return;
}



/* c05c2044 EolSessionMediaConnect */

/* Boundary evidence: original MIPS .pdata c05c2044..c05c22cf. Semantic name remains unreviewed. */

int EolSessionMediaConnect(int *param_1,wchar_t *param_2)

{
  bool bVar1;
  int iVar2;
  size_t sVar3;
  HLOCAL _Dst;
  undefined *puVar4;
  int iVar5;
  wchar_t *pwVar6;
  uint local_28 [2];
  
                    /* 0x2044  16  EolSessionMediaConnect */
  iVar5 = 0;
  bVar1 = false;
  iVar2 = FUN_c05c16c8((int)param_1);
  if (iVar2 == 0) {
    return 0;
  }
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 2));
  if (param_2 == (wchar_t *)0x0) {
    param_2 = L"defaultSSID";
  }
  param_1[9] = 1;
  if (param_1[0x53] != 0) {
    (*(code *)param_1[0x24])(param_1[0x1b],(int)param_1 + 0x2c9,(int)param_1 + 0x2cf);
  }
  pwVar6 = (wchar_t *)param_1[10];
  if ((pwVar6 == (wchar_t *)0x0) || (iVar2 = wcscmp(param_2,pwVar6), iVar2 != 0)) {
    LocalFree(pwVar6);
    sVar3 = wcslen(param_2);
    pwVar6 = LocalAlloc(0x40,(sVar3 + 1) * 2);
    param_1[10] = (int)pwVar6;
    if (pwVar6 != (wchar_t *)0x0) {
      wcscpy(pwVar6,param_2);
      bVar1 = true;
      goto LAB_c05c213c;
    }
LAB_c05c2124:
    iVar5 = 0xe;
  }
  else {
    if (param_1[0x3f] != 0) {
      iVar5 = 0x4c7;
      goto LAB_c05c2294;
    }
LAB_c05c213c:
    EolSSEapTypeGet(param_2,local_28);
    if (param_1[0x1a] == 0) {
      FUN_c05c35c8(param_2,(uint *)(param_1 + 0x40));
    }
    else {
      param_1[0x40] = 0;
    }
    if (param_1[0x3e] == 0) {
      if ((param_1[0xbc] == 4) || (param_1[0xbc] == 7)) {
        FUN_c05c763c(param_1);
      }
      else {
        if ((param_1[0xc2] & 2U) == 0) {
          puVar4 = &DAT_c05ca134;
        }
        else {
          puVar4 = &DAT_c05ca158;
        }
        iVar2 = EapSessionCreate(param_1,param_1[0xc2] | 0x80,param_1[7],local_28[0] & 0xff,
                                 param_1[0x1c] + -4,param_1[0x1d] + 4,puVar4);
        param_1[0x3e] = iVar2;
        if (iVar2 == 0) goto LAB_c05c2124;
        bVar1 = true;
      }
    }
    else {
      EapSessionReset();
    }
    if ((param_1[7] != 0) && (param_1[0x3b] == 0)) {
      _Dst = LocalAlloc(0x40,0xf);
      param_1[0x3b] = (int)_Dst;
      if (_Dst != (HLOCAL)0x0) {
        memcpy(_Dst,"Test_NetworkId",0xf);
      }
    }
    if ((!bVar1) || (iVar5 = FUN_c05c1ba0((int)param_1,param_2,local_28[0]), iVar5 == 0)) {
      memset(param_1 + 0x27,0,8);
      FUN_c05c636c((int)param_1);
      FUN_c05c7728(param_1);
    }
  }
LAB_c05c2294:
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 2));
  FUN_c05c1f44(param_1);
  return iVar5;
}



/* c05c22d0 EolSessionMediaDisconnect */

/* Boundary evidence: original MIPS .pdata c05c22d0..c05c234b. Semantic name remains unreviewed. */

void EolSessionMediaDisconnect(int *param_1)

{
  int iVar1;
  
                    /* 0x22d0  17  EolSessionMediaDisconnect */
  iVar1 = FUN_c05c16c8((int)param_1);
  if (iVar1 != 0) {
    EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 2));
    param_1[9] = 0;
    FUN_c05c7764(param_1);
    if (param_1[0x3e] != 0) {
      EapSessionDestroy();
      param_1[0x3e] = 0;
    }
    param_1[0x3f] = 0;
    LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 2));
    FUN_c05c1f44(param_1);
  }
  return;
}



/* c05c234c EolSessionMediaSpecific */

/* Boundary evidence: original MIPS .pdata c05c234c..c05c23c7. Semantic name remains unreviewed. */

void EolSessionMediaSpecific(int *param_1,int *param_2,uint param_3)

{
  int iVar1;
  
                    /* 0x234c  18  EolSessionMediaSpecific */
  iVar1 = FUN_c05c16c8((int)param_1);
  if (iVar1 != 0) {
    EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 2));
    FUN_c05c1ce0(param_1,param_2,param_3);
    LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 2));
    FUN_c05c1f44(param_1);
  }
  return;
}



/* c05c23c8 EolSessionProcessRxPacket */

/* Boundary evidence: original MIPS .pdata c05c23c8..c05c245f. Semantic name remains unreviewed. */

void EolSessionProcessRxPacket(int *param_1,void *param_2,uint param_3)

{
  int iVar1;
  uint local_20 [2];
  
                    /* 0x23c8  19  EolSessionProcessRxPacket */
  iVar1 = FUN_c05c16c8((int)param_1);
  if (iVar1 != 0) {
    EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 2));
    iVar1 = FUN_c05c7be4(param_1,(int)param_2,param_3,local_20);
    if (iVar1 != 0) {
      FUN_c05c78f0(param_1,param_2,local_20[0]);
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 2));
    FUN_c05c1f44(param_1);
  }
  return;
}



/* c05c2460 FUN_c05c2460 */

/* Boundary evidence: original MIPS .pdata c05c2460..c05c26a7. Semantic name remains unreviewed. */

void FUN_c05c2460(int *param_1,char *param_2,int param_3,LPSTR param_4,int *param_5)

{
  char cVar1;
  int iVar2;
  DWORD DVar3;
  size_t cchWideChar;
  int iVar4;
  int *piVar5;
  int *piVar6;
  LPCRITICAL_SECTION lpCriticalSection;
  int local_468;
  int local_464;
  int local_460 [4];
  wchar_t awStack_450 [276];
  wchar_t awStack_228 [258];
  uint local_24;
  
  local_24 = DAT_c05ca1a8;
  iVar2 = FUN_c05c16c8((int)param_1);
  if (iVar2 != 0) {
    lpCriticalSection = (LPCRITICAL_SECTION)(param_1 + 2);
    EnterCriticalSection(lpCriticalSection);
    FUN_c05c712c(param_1);
    do {
      if (param_3 == 0) break;
      cVar1 = *param_2;
      param_3 = param_3 + -1;
      param_2 = param_2 + 1;
    } while (cVar1 != '\0');
    iVar2 = FUN_c05c147c(param_2,param_3,local_460);
    if (iVar2 == 0) {
      piVar6 = local_460;
      piVar5 = param_1 + 0x3b;
      iVar2 = 3;
      do {
        LocalFree((HLOCAL)*piVar5);
        iVar4 = *piVar6;
        piVar6 = piVar6 + 1;
        *piVar5 = iVar4;
        iVar2 = iVar2 + -1;
        piVar5 = piVar5 + 1;
      } while (iVar2 != 0);
    }
    FUN_c05c3178(param_1[10],awStack_450);
    local_468 = 0;
    DVar3 = FUN_c05c32e0(param_1[10],(BYTE *)awStack_228);
    if (DVar3 == 0) {
      local_468 = 1;
    }
    LeaveCriticalSection(lpCriticalSection);
    iVar2 = EapSessionGetIdentity
                      (param_1[0x3e],0,0,awStack_450,awStack_228,param_1[0x40] == 0,&local_468,
                       &local_464);
    EnterCriticalSection(lpCriticalSection);
    if (local_464 != 0) {
      param_1[0x40] = 0;
      FUN_c05c3670(param_1[10],0);
    }
    if (iVar2 == 0) {
      FUN_c05c3220(param_1[10],awStack_450);
      if (local_468 == 0) {
        FUN_c05c3550(param_1[10]);
      }
      else {
        FUN_c05c3418(param_1[10],awStack_228);
      }
      cchWideChar = wcslen(awStack_450);
      iVar2 = WideCharToMultiByte(1,0,awStack_450,cchWideChar,param_4,*param_5,(LPCSTR)0x0,
                                  (LPBOOL)0x0);
      *param_5 = iVar2;
      FUN_c05c7338(param_1);
    }
    else {
      FUN_c05c7a44(param_1,0,(undefined1 *)0x0,0,1,iVar2);
    }
    LeaveCriticalSection(lpCriticalSection);
    FUN_c05c1f44(param_1);
  }
  FUN_c05c8248(local_24);
  return;
}



/* c05c26a8 FUN_c05c26a8 */

/* Boundary evidence: original MIPS .pdata c05c26a8..c05c2723. Semantic name remains unreviewed. */

void FUN_c05c26a8(int *param_1,wchar_t *param_2,int param_3)

{
  int iVar1;
  
  iVar1 = FUN_c05c16c8((int)param_1);
  if (iVar1 != 0) {
    if ((param_3 == 0) || (param_1[10] == 0)) {
      FUN_c05c3550(param_1[10]);
    }
    else {
      FUN_c05c3418(param_1[10],param_2);
    }
    FUN_c05c1f44(param_1);
  }
  return;
}



/* c05c2724 FUN_c05c2724 */

/* Boundary evidence: original MIPS .pdata c05c2724..c05c290b. Semantic name remains unreviewed. */

void FUN_c05c2724(int *param_1,int param_2,int param_3,int param_4,int param_5)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 *puVar3;
  size_t local_70;
  undefined1 auStack_6c [32];
  undefined1 auStack_4c [32];
  uint local_2c;
  
  local_2c = DAT_c05ca1a8;
  puVar3 = (undefined1 *)0x0;
  iVar1 = FUN_c05c16c8((int)param_1);
  if (iVar1 == 0) goto LAB_c05c28d4;
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 2));
  if ((param_4 != 0) && (param_5 == 0)) {
    uVar2 = *(undefined4 *)(param_1[0x3e] + 0x74);
    EapUtilExtractMPPEKey(param_1 + 0x29,param_1 + 0x31,uVar2,0x137,0x10);
    EapUtilExtractMPPEKey(param_1 + 0x32,param_1 + 0x3a,uVar2,0x137,0x11);
    local_70 = param_1[0x31];
    if (0x20 < local_70) {
      local_70 = 0x20;
    }
    memcpy(auStack_6c,param_1 + 0x29,local_70);
    memcpy(auStack_4c,param_1 + 0x32,local_70);
    FUN_c05c3924((int)param_1,&local_70);
  }
  if (param_2 == 0) {
LAB_c05c284c:
    FUN_c05c7a44(param_1,0,puVar3,param_3,param_4,param_5);
  }
  else {
    iVar1 = FUN_c05c779c((int)param_1);
    if (iVar1 != 0) {
      puVar3 = (undefined1 *)(param_2 + -4);
      goto LAB_c05c284c;
    }
  }
  if (param_4 != 0) {
    EapSessionReset(param_1[0x3e]);
    param_1[0x40] = 0;
    if (param_5 == 0x4c7) {
      EolSessionMediaDisconnect(param_1);
      param_1[0x3f] = 1;
    }
    else if (param_5 == 0) {
      param_1[0x40] = 1;
    }
    else {
      FUN_c05c3550(param_1[10]);
    }
    FUN_c05c3670(param_1[10],param_1[0x40]);
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 2));
  FUN_c05c1f44(param_1);
LAB_c05c28d4:
  FUN_c05c8248(local_2c);
  return;
}



/* c05c290c EolSessionDestroy */

/* Boundary evidence: original MIPS .pdata c05c290c..c05c295b. Semantic name remains unreviewed. */

void EolSessionDestroy(int *param_1)

{
                    /* 0x290c  13  EolSessionDestroy */
  EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 2));
  EolSessionMediaDisconnect(param_1);
  param_1[0x1f] = 0;
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 2));
  FUN_c05c1f44(param_1);
  return;
}



/* c05c295c EolSS8021xEnableGet */

/* Boundary evidence: original MIPS .pdata c05c295c..c05c29e7. Semantic name remains unreviewed. */

undefined4 EolSS8021xEnableGet(undefined4 param_1,undefined4 *param_2)

{
  wchar_t awStack_218 [260];
  uint local_10;
  
                    /* 0x295c  4  EolSS8021xEnableGet */
  local_10 = DAT_c05ca1a8;
  *param_2 = 0;
  StringCchPrintfW(awStack_218,0x104,L"%s\\%s",L"Comm\\EAPOL\\Config",param_1);
  RegReadValues(0x80000001,awStack_218,L"Enable8021x",4,0,param_2,4,0);
  FUN_c05c8248(local_10);
  return 0;
}



/* c05c29e8 EolSS8021xEnableSet */

/* Boundary evidence: original MIPS .pdata c05c29e8..c05c2a6b. Semantic name remains unreviewed. */

undefined4 EolSS8021xEnableSet(undefined4 param_1,undefined4 param_2)

{
  undefined4 local_res4 [3];
  wchar_t awStack_218 [260];
  uint local_10;
  
                    /* 0x29e8  5  EolSS8021xEnableSet */
  local_10 = DAT_c05ca1a8;
  local_res4[0] = param_2;
  StringCchPrintfW(awStack_218,0x104,L"%s\\%s",L"Comm\\EAPOL\\Config",param_1);
  RegWriteValues(0x80000001,awStack_218,L"Enable8021x",4,0,local_res4,4,0);
  FUN_c05c8248(local_10);
  return 0;
}



/* c05c2a6c FUN_c05c2a6c */

/* Boundary evidence: original MIPS .pdata c05c2a6c..c05c2b4b. Semantic name remains unreviewed. */

undefined4 FUN_c05c2a6c(undefined4 param_1,undefined4 param_2,undefined4 param_3,uint *param_4)

{
  int iVar1;
  undefined4 uVar2;
  uint local_228 [2];
  wchar_t awStack_220 [260];
  uint local_18;
  
  local_18 = DAT_c05ca1a8;
  uVar2 = 0;
  StringCchPrintfW(awStack_220,0x104,L"%s\\%s\\%u",L"Comm\\EAPOL\\Config",param_1,param_2);
  local_228[0] = *param_4;
  iVar1 = RegReadValues(0x80000001,awStack_220,L"ConnectionData",3,0,param_3,local_228,0);
  if (iVar1 != 1) {
    if (*param_4 < local_228[0]) {
      uVar2 = 0x25b;
      *param_4 = local_228[0];
    }
    else {
      uVar2 = 0x490;
      *param_4 = 0;
    }
  }
  FUN_c05c8248(local_18);
  return uVar2;
}



/* c05c2b4c FUN_c05c2b4c */

/* Boundary evidence: original MIPS .pdata c05c2b4c..c05c2bfb. Semantic name remains unreviewed. */

undefined4 FUN_c05c2b4c(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  wchar_t awStack_220 [260];
  uint local_18;
  
  local_18 = DAT_c05ca1a8;
  uVar2 = 0;
  StringCchPrintfW(awStack_220,0x104,L"%s\\%s\\%u",L"Comm\\EAPOL\\Config",param_1,param_2);
  iVar1 = RegWriteValues(0x80000001,awStack_220,L"ConnectionData",3,0,param_3,param_4,0);
  if (iVar1 != 1) {
    uVar2 = 0xe;
  }
  FUN_c05c8248(local_18);
  return uVar2;
}



/* c05c2bfc FUN_c05c2bfc */

/* Boundary evidence: original MIPS .pdata c05c2bfc..c05c2c9b. Semantic name remains unreviewed. */

undefined4 FUN_c05c2bfc(undefined4 param_1,undefined4 *param_2)

{
  int iVar1;
  wchar_t awStack_218 [260];
  uint local_10;
  
  local_10 = DAT_c05ca1a8;
  StringCchPrintfW(awStack_218,0x104,L"%s\\%s",L"Comm\\EAPOL\\Config",param_1);
  iVar1 = RegReadValues(0x80000001,awStack_218,L"EapTypeId",4,0,param_2,4,0);
  if (iVar1 != 1) {
    *param_2 = DAT_c05ca17c;
  }
  FUN_c05c8248(local_10);
  return 0;
}



/* c05c2c9c FUN_c05c2c9c */

/* Boundary evidence: original MIPS .pdata c05c2c9c..c05c2d3b. Semantic name remains unreviewed. */

undefined4 FUN_c05c2c9c(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 local_res4 [3];
  wchar_t awStack_218 [260];
  uint local_10;
  
  local_10 = DAT_c05ca1a8;
  uVar2 = 0;
  local_res4[0] = param_2;
  StringCchPrintfW(awStack_218,0x104,L"%s\\%s",L"Comm\\EAPOL\\Config",param_1);
  iVar1 = RegWriteValues(0x80000001,awStack_218,L"EapTypeId",4,0,local_res4,4,0);
  if (iVar1 != 1) {
    uVar2 = 0xe;
  }
  FUN_c05c8248(local_10);
  return uVar2;
}



/* c05c2d3c EolSSConnectionDataGet */

/* Boundary evidence: original MIPS .pdata c05c2d3c..c05c2d57. Semantic name remains unreviewed. */

void EolSSConnectionDataGet(undefined4 param_1,undefined4 param_2,undefined4 param_3,uint *param_4)

{
                    /* 0x2d3c  6  EolSSConnectionDataGet */
  FUN_c05c2a6c(param_1,param_2,param_3,param_4);
  return;
}



/* c05c2d58 EolSSConnectionDataSet */

/* Boundary evidence: original MIPS .pdata c05c2d58..c05c2dc3. Semantic name remains unreviewed. */

void EolSSConnectionDataSet
               (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  
                    /* 0x2d58  7  EolSSConnectionDataSet */
  iVar1 = FUN_c05c2c9c(param_1,param_2);
  if (iVar1 == 0) {
    FUN_c05c2b4c(param_1,param_2,param_3,param_4);
  }
  return;
}



/* c05c2dc4 FUN_c05c2dc4 */

/* Boundary evidence: original MIPS .pdata c05c2dc4..c05c2ea3. Semantic name remains unreviewed. */

undefined4 FUN_c05c2dc4(undefined4 param_1,undefined4 param_2,undefined4 param_3,uint *param_4)

{
  int iVar1;
  undefined4 uVar2;
  uint local_228 [2];
  wchar_t awStack_220 [260];
  uint local_18;
  
  local_18 = DAT_c05ca1a8;
  uVar2 = 0;
  StringCchPrintfW(awStack_220,0x104,L"%s\\%s\\%u",L"Comm\\EAPOL\\Config",param_1,param_2);
  local_228[0] = *param_4;
  iVar1 = RegReadValues(0x80000001,awStack_220,L"UserData",3,0,param_3,local_228,0);
  if (iVar1 != 1) {
    if (*param_4 < local_228[0]) {
      uVar2 = 0x25b;
      *param_4 = local_228[0];
    }
    else {
      uVar2 = 0x490;
      *param_4 = 0;
    }
  }
  FUN_c05c8248(local_18);
  return uVar2;
}



/* c05c2ea4 FUN_c05c2ea4 */

/* Boundary evidence: original MIPS .pdata c05c2ea4..c05c2f53. Semantic name remains unreviewed. */

undefined4 FUN_c05c2ea4(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  wchar_t awStack_220 [260];
  uint local_18;
  
  local_18 = DAT_c05ca1a8;
  uVar2 = 0;
  StringCchPrintfW(awStack_220,0x104,L"%s\\%s\\%u",L"Comm\\EAPOL\\Config",param_1,param_2);
  iVar1 = RegWriteValues(0x80000001,awStack_220,L"UserData",3,0,param_3,param_4,0);
  if (iVar1 != 1) {
    uVar2 = 0xe;
  }
  FUN_c05c8248(local_18);
  return uVar2;
}



/* c05c2f54 EolSSEapTypeGet */

/* Boundary evidence: original MIPS .pdata c05c2f54..c05c2f6f. Semantic name remains unreviewed. */

void EolSSEapTypeGet(undefined4 param_1,undefined4 *param_2)

{
                    /* 0x2f54  9  EolSSEapTypeGet */
  FUN_c05c2bfc(param_1,param_2);
  return;
}



/* c05c2f70 EolSSEapTypeSet */

/* Boundary evidence: original MIPS .pdata c05c2f70..c05c2f8b. Semantic name remains unreviewed. */

void EolSSEapTypeSet(undefined4 param_1,undefined4 param_2)

{
                    /* 0x2f70  10  EolSSEapTypeSet */
  FUN_c05c2c9c(param_1,param_2);
  return;
}



/* c05c2f8c EolSSInvokeConfigUI */

/* Boundary evidence: original MIPS .pdata c05c2f8c..c05c3023. Semantic name remains unreviewed. */

int EolSSInvokeConfigUI(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                       undefined4 param_5,undefined4 param_6)

{
  int iVar1;
  undefined4 local_18;
  undefined4 local_14;
  
                    /* 0x2f8c  11  EolSSInvokeConfigUI */
  iVar1 = EapInvokeConfigUI(param_2,param_3,param_4,param_5,param_6,&local_18,&local_14);
  if (iVar1 == 0) {
    iVar1 = EolSSConnectionDataSet(param_1,param_2,local_18,local_14);
    EapFreeConnectionData(local_18);
  }
  return iVar1;
}



/* c05c3024 EolEnumExtensions */

/* Boundary evidence: original MIPS .pdata c05c3024..c05c303f. Semantic name remains unreviewed. */

void EolEnumExtensions(void)

{
                    /* 0x3024  3  EolEnumExtensions */
  EapEnumExtensions();
  return;
}



/* c05c3040 FUN_c05c3040 */

/* Boundary evidence: original MIPS .pdata c05c3040..c05c3177. Semantic name remains unreviewed. */

undefined4 FUN_c05c3040(undefined4 param_1,undefined4 *param_2)

{
  int iVar1;
  size_t sVar2;
  size_t sVar3;
  LPSTR lpMultiByteStr;
  undefined4 uVar4;
  wchar_t awStack_438 [260];
  undefined2 local_230;
  wchar_t awStack_228 [260];
  uint local_20;
  
  local_20 = DAT_c05ca1a8;
  uVar4 = 0;
  lpMultiByteStr = (LPSTR)0x0;
  StringCchPrintfW(awStack_228,0x104,L"%s\\%s",L"Comm\\EAPOL\\Config",param_1);
  iVar1 = RegReadValues(0x80000002,awStack_228,L"DisplayMessage",1,0,awStack_438,0x208,0);
  if (iVar1 == 1) {
    local_230 = 0;
    sVar2 = wcslen(awStack_438);
    sVar3 = wcslen(awStack_438);
    lpMultiByteStr = LocalAlloc(0x40,(sVar3 + 1) * 2);
    if (lpMultiByteStr == (LPSTR)0x0) {
      uVar4 = 0xe;
    }
    else {
      WideCharToMultiByte(1,0,awStack_438,-1,lpMultiByteStr,(sVar2 + 1) * 2,(LPCSTR)0x0,(LPBOOL)0x0)
      ;
    }
  }
  else {
    uVar4 = 0x490;
  }
  *param_2 = lpMultiByteStr;
  FUN_c05c8248(local_20);
  return uVar4;
}



/* c05c3178 FUN_c05c3178 */

/* Boundary evidence: original MIPS .pdata c05c3178..c05c321f. Semantic name remains unreviewed. */

undefined4 FUN_c05c3178(undefined4 param_1,undefined2 *param_2)

{
  int iVar1;
  undefined4 uVar2;
  wchar_t awStack_220 [262];
  uint local_14;
  
  local_14 = DAT_c05ca1a8;
  uVar2 = 0;
  StringCchPrintfW(awStack_220,0x104,L"%s\\%s",L"Comm\\EAPOL\\Config",param_1);
  *param_2 = 0;
  iVar1 = RegReadValues(0x80000001,awStack_220,L"Identity",1,0,param_2,0x222,0);
  if (iVar1 != 1) {
    uVar2 = 0x490;
  }
  FUN_c05c8248(local_14);
  return uVar2;
}



/* c05c3220 FUN_c05c3220 */

/* Boundary evidence: original MIPS .pdata c05c3220..c05c32df. Semantic name remains unreviewed. */

DWORD FUN_c05c3220(undefined4 param_1,wchar_t *param_2)

{
  size_t sVar1;
  int iVar2;
  DWORD DVar3;
  wchar_t awStack_220 [262];
  uint local_14;
  
  local_14 = DAT_c05ca1a8;
  DVar3 = 0;
  StringCchPrintfW(awStack_220,0x104,L"%s\\%s",L"Comm\\EAPOL\\Config",param_1);
  sVar1 = wcslen(param_2);
  iVar2 = RegWriteValues(0x80000001,awStack_220,L"Identity",1,0,param_2,(sVar1 + 1) * 2,0);
  if (iVar2 != 1) {
    DVar3 = GetLastError();
  }
  FUN_c05c8248(local_14);
  return DVar3;
}



/* c05c32e0 FUN_c05c32e0 */

/* Boundary evidence: original MIPS .pdata c05c32e0..c05c3417. Semantic name remains unreviewed. */

DWORD FUN_c05c32e0(undefined4 param_1,BYTE *param_2)

{
  int iVar1;
  BOOL BVar2;
  DWORD DVar3;
  DATA_BLOB local_230;
  DATA_BLOB local_228;
  wchar_t awStack_220 [262];
  uint local_14;
  
  local_14 = DAT_c05ca1a8;
  DVar3 = 0;
  param_2[0] = '\0';
  param_2[1] = '\0';
  StringCchPrintfW(awStack_220,0x104,L"%s\\%s",L"Comm\\EAPOL\\Config",param_1);
  local_230.cbData = 0;
  local_230.pbData = (BYTE *)0x0;
  iVar1 = RegReadValues(0x80000001,awStack_220,L"Password",3,1,&local_230.pbData,&local_230,0);
  if (iVar1 == 1) {
    local_228.cbData = 0x200;
    local_228.pbData = param_2;
    BVar2 = CryptUnprotectData(&local_230,(LPWSTR *)0x0,(DATA_BLOB *)0x0,(PVOID)0x0,
                               (CRYPTPROTECT_PROMPTSTRUCT *)0x0,0x20000000,&local_228);
    if (BVar2 == 0) {
      DVar3 = GetLastError();
    }
    else {
      (param_2 + (local_228.cbData & 0xfffffffe))[0] = '\0';
      (param_2 + (local_228.cbData & 0xfffffffe))[1] = '\0';
    }
    LocalFree(local_230.pbData);
  }
  else {
    DVar3 = 0x490;
  }
  FUN_c05c8248(local_14);
  return DVar3;
}



/* c05c3418 FUN_c05c3418 */

/* Boundary evidence: original MIPS .pdata c05c3418..c05c354f. Semantic name remains unreviewed. */

DWORD FUN_c05c3418(undefined4 param_1,wchar_t *param_2)

{
  size_t sVar1;
  BOOL BVar2;
  int iVar3;
  DWORD DVar4;
  DATA_BLOB local_230;
  DATA_BLOB local_228;
  wchar_t awStack_220 [262];
  uint local_14;
  
  local_14 = DAT_c05ca1a8;
  DVar4 = 0;
  sVar1 = wcslen(param_2);
  local_228.cbData = sVar1 << 1;
  local_230.cbData = 0;
  local_230.pbData = (BYTE *)0x0;
  local_228.pbData = (BYTE *)param_2;
  BVar2 = CryptProtectData(&local_228,L"EAPOL Password",(DATA_BLOB *)0x0,(PVOID)0x0,
                           (CRYPTPROTECT_PROMPTSTRUCT *)0x0,0x20000000,&local_230);
  if ((BVar2 != 0) || (DVar4 = GetLastError(), DVar4 == 0)) {
    StringCchPrintfW(awStack_220,0x104,L"%s\\%s",L"Comm\\EAPOL\\Config",param_1);
    iVar3 = RegWriteValues(0x80000001,awStack_220,L"Password",3,0,local_230.pbData,local_230.cbData,
                           0);
    if (iVar3 != 1) {
      DVar4 = GetLastError();
    }
    LocalFree(local_230.pbData);
  }
  FUN_c05c8248(local_14);
  return DVar4;
}



/* c05c3550 FUN_c05c3550 */

/* Boundary evidence: original MIPS .pdata c05c3550..c05c35c7. Semantic name remains unreviewed. */

undefined4 FUN_c05c3550(undefined4 param_1)

{
  wchar_t awStack_218 [262];
  uint local_c;
  
  local_c = DAT_c05ca1a8;
  StringCchPrintfW(awStack_218,0x104,L"%s\\%s",L"Comm\\EAPOL\\Config",param_1);
  RegWriteValues(0x80000001,awStack_218,L"Password",3,0,0,0,0);
  FUN_c05c8248(local_c);
  return 0;
}



/* c05c35c8 FUN_c05c35c8 */

/* Boundary evidence: original MIPS .pdata c05c35c8..c05c366f. Semantic name remains unreviewed. */

undefined4 FUN_c05c35c8(undefined4 param_1,uint *param_2)

{
  int local_220 [2];
  wchar_t awStack_218 [260];
  uint local_10;
  
  local_10 = DAT_c05ca1a8;
  local_220[0] = 0;
  StringCchPrintfW(awStack_218,0x104,L"%s\\%s",L"Comm\\EAPOL\\Config",param_1);
  RegReadValues(0x80000001,awStack_218,L"LastAuthSuccessful",4,0,local_220,4,0);
  *param_2 = (uint)(local_220[0] == 1);
  FUN_c05c8248(local_10);
  return 0;
}



/* c05c3670 FUN_c05c3670 */

/* Boundary evidence: original MIPS .pdata c05c3670..c05c371f. Semantic name remains unreviewed. */

undefined4 FUN_c05c3670(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 local_228 [2];
  wchar_t awStack_220 [260];
  uint local_18;
  
  local_18 = DAT_c05ca1a8;
  uVar2 = 0;
  if (param_1 != 0) {
    StringCchPrintfW(awStack_220,0x104,L"%s\\%s",L"Comm\\EAPOL\\Config",param_1);
    local_228[0] = param_2;
    iVar1 = RegWriteValues(0x80000001,awStack_220,L"LastAuthSuccessful",4,0,local_228,4,0);
    if (iVar1 != 1) {
      uVar2 = 0xe;
    }
  }
  FUN_c05c8248(local_18);
  return uVar2;
}



/* c05c3720 EolSSDelete */

/* Boundary evidence: original MIPS .pdata c05c3720..c05c3787. Semantic name remains unreviewed. */

undefined4 EolSSDelete(undefined4 param_1)

{
  undefined4 uVar1;
  wchar_t awStack_218 [260];
  uint local_10;
  
                    /* 0x3720  8  EolSSDelete */
  local_10 = DAT_c05ca1a8;
  StringCchPrintfW(awStack_218,0x104,L"%s\\%s",L"Comm\\EAPOL\\Config",param_1);
  uVar1 = RegDeleteKeyAndContents(0x80000001,awStack_218);
  FUN_c05c8248(local_10);
  return uVar1;
}



/* c05c3788 FUN_c05c3788 */

/* Boundary evidence: original MIPS .pdata c05c3788..c05c3923. Semantic name remains unreviewed. */

void FUN_c05c3788(undefined4 param_1,undefined4 param_2,undefined1 *param_3,uint param_4,
                 void *param_5)

{
  uint uVar1;
  byte *pbVar2;
  undefined1 auStack_130 [104];
  undefined1 auStack_c8 [16];
  undefined1 auStack_b8 [16];
  byte local_a8 [72];
  byte local_60 [68];
  uint local_1c;
  
  local_1c = DAT_c05ca1a8;
  if (0x40 < param_4) {
    FUN_c05c7d44();
    FUN_c05c7d34();
    FUN_c05c7d24();
    memcpy(auStack_b8,auStack_c8,0x10);
    param_3 = auStack_b8;
    param_4 = 0x10;
  }
  memset(local_60,0,0x41);
  memset(local_a8,0,0x41);
  memcpy(local_60,param_3,param_4);
  memcpy(local_a8,param_3,param_4);
  uVar1 = 0;
  do {
    pbVar2 = local_a8 + uVar1;
    local_60[uVar1] = local_60[uVar1] ^ 0x36;
    uVar1 = uVar1 + 1;
    *pbVar2 = *pbVar2 ^ 0x5c;
  } while (uVar1 < 0x40);
  FUN_c05c7d44();
  FUN_c05c7d34();
  FUN_c05c7d34();
  FUN_c05c7d24();
  memcpy(param_5,auStack_130,0x10);
  FUN_c05c7d44();
  FUN_c05c7d34();
  FUN_c05c7d34();
  FUN_c05c7d24();
  memcpy(param_5,auStack_130,0x10);
  FUN_c05c8248(local_1c);
  return;
}



/* c05c3924 FUN_c05c3924 */

/* Boundary evidence: original MIPS .pdata c05c3924..c05c3977. Semantic name remains unreviewed. */

undefined4 FUN_c05c3924(int param_1,void *param_2)

{
  memcpy((void *)(param_1 + 0x104),param_2,0x44);
  if (*(int *)(param_1 + 0x148) != 0) {
    FUN_c05c4b18(*(int *)(param_1 + 0x148),param_2);
  }
  return 0;
}



/* c05c3978 FUN_c05c3978 */

/* Boundary evidence: original MIPS .pdata c05c3978..c05c3b73. Semantic name remains unreviewed. */

undefined4 FUN_c05c3978(int param_1,int param_2,int param_3)

{
  int iVar1;
  size_t _Size;
  uint uVar2;
  uint uVar3;
  void *_Src;
  undefined4 uVar4;
  uint uVar5;
  undefined1 auStack_80 [16];
  undefined1 auStack_70 [16];
  undefined1 auStack_60 [16];
  undefined1 auStack_50 [32];
  uint local_30;
  
  local_30 = DAT_c05ca1a8;
  uVar4 = 0;
  if (0x2b < param_3 - 4U) {
    uVar3 = (uint)CONCAT11(*(undefined1 *)(param_2 + 5),*(undefined1 *)(param_2 + 6));
    iVar1 = memcmp((undefined4 *)(param_2 + 7),(undefined4 *)(param_1 + 0x9c),8);
    if ((0 < iVar1) && (*(int *)(param_1 + 0xe8) != 0)) {
      *(undefined4 *)(param_1 + 0x9c) = *(undefined4 *)(param_2 + 7);
      *(undefined4 *)(param_1 + 0xa0) = *(undefined4 *)(param_2 + 0xb);
      uVar2 = *(uint *)(param_1 + 0xc4);
      uVar5 = *(uint *)(param_1 + 0xe8);
      _Src = (void *)(param_1 + 0xa4);
      if (uVar5 != 0) {
        memcpy(auStack_80,(void *)(param_2 + 0x20),0x10);
        memset((void *)(param_2 + 0x20),0,0x10);
        FUN_c05c3788(param_2,param_3,(undefined1 *)(param_1 + 200),uVar5,auStack_70);
        iVar1 = memcmp(auStack_70,auStack_80,0x10);
        if ((iVar1 == 0) && (*(int *)(param_1 + 0xc4) != 0)) {
          if (param_3 == 0x30) {
            if (uVar2 < uVar3) {
              uVar3 = uVar2;
            }
          }
          else {
            memcpy(auStack_60,(void *)(param_2 + 0xf),0x10);
            _Size = 0x20;
            if (uVar2 < 0x21) {
              _Size = uVar2;
            }
            memcpy(auStack_50,_Src,_Size);
            FUN_c05c7d64();
            _Src = (void *)(param_2 + 0x30);
            FUN_c05c7d54();
          }
          uVar4 = (**(code **)(param_1 + 0x80))
                            (*(undefined4 *)(param_1 + 0x6c),_Src,uVar3,
                             *(undefined1 *)(param_2 + 0x1f));
        }
      }
    }
  }
  FUN_c05c8248(local_30);
  return uVar4;
}



/* c05c3b74 FUN_c05c3b74 */

/* Boundary evidence: original MIPS .pdata c05c3b74..c05c3cdf. Semantic name remains unreviewed. */

int FUN_c05c3b74(int *param_1,void *param_2,uint param_3)

{
  char cVar1;
  int iVar2;
  int local_28 [2];
  
  cVar1 = *(char *)((int)param_2 + 4);
  iVar2 = 0;
  if (cVar1 == '\x01') {
    iVar2 = FUN_c05c3978((int)param_1,(int)param_2,param_3);
  }
  else if (cVar1 == '\x02') {
    iVar2 = FUN_c05c5654(param_1,(int)param_2,param_3);
  }
  else if (cVar1 == -2) {
    if (param_1[0x53] == 0) {
      iVar2 = 0x32;
    }
    else {
      FUN_c05c712c(param_1);
      iVar2 = FUN_c05c6904(param_1,param_2,param_3,local_28);
      if (local_28[0] == 0) {
        (*(code *)param_1[0x1f])(param_1[0x1b],0,0,2,0);
        FUN_c05c7304(param_1);
      }
      else if (local_28[0] == 1) {
        FUN_c05c763c(param_1);
      }
      else if (local_28[0] == 2) {
        (*(code *)param_1[0x1f])(param_1[0x1b],0,0,3,0x4c7);
        EolSessionMediaDisconnect(param_1);
        FUN_c05c72a8(param_1);
      }
    }
  }
  return iVar2;
}



/* c05c3ce0 EolSessionKeyMaterialSet */

/* Boundary evidence: original MIPS .pdata c05c3ce0..c05c3d67. Semantic name remains unreviewed. */

undefined4 EolSessionKeyMaterialSet(int param_1,uint *param_2)

{
  undefined4 uVar1;
  
                    /* 0x3ce0  15  EolSessionKeyMaterialSet */
  uVar1 = 0;
  if (*param_2 < 0x21) {
    memcpy((void *)(param_1 + 0xa4),param_2 + 1,*param_2);
    *(uint *)(param_1 + 0xc4) = *param_2;
    memcpy((void *)(param_1 + 200),param_2 + 9,*param_2);
    *(uint *)(param_1 + 0xe8) = *param_2;
    FUN_c05c3924(param_1,param_2);
  }
  else {
    uVar1 = 0x57;
  }
  return uVar1;
}



/* c05c3d68 FUN_c05c3d68 */

/* Boundary evidence: original MIPS .pdata c05c3d68..c05c3e4b. Semantic name remains unreviewed. */

undefined4
FUN_c05c3d68(void *param_1,uint param_2,undefined4 *param_3,uint param_4,undefined4 *param_5,
            SIZE_T *param_6)

{
  bool bVar1;
  undefined3 extraout_var;
  undefined4 uVar2;
  HLOCAL hMem;
  
  hMem = (HLOCAL)0x0;
  if ((7 < param_4) && ((param_4 & 7) == 0)) {
    hMem = LocalAlloc(0x40,param_4 - 8);
    if (hMem == (HLOCAL)0x0) {
      uVar2 = 0xe;
      goto LAB_c05c3e18;
    }
    bVar1 = FUN_c05c5aa0(param_1,param_2,param_3,param_4,hMem);
    if (CONCAT31(extraout_var,bVar1) == 1) {
      *param_5 = hMem;
      *param_6 = param_4 - 8;
      return 0;
    }
  }
  uVar2 = 0xd;
LAB_c05c3e18:
  LocalFree(hMem);
  return uVar2;
}



/* c05c3e4c FUN_c05c3e4c */

/* Boundary evidence: original MIPS .pdata c05c3e4c..c05c3f83. Semantic name remains unreviewed. */

undefined4
FUN_c05c3e4c(void *param_1,size_t param_2,void *param_3,void *param_4,SIZE_T param_5,
            undefined4 *param_6,SIZE_T *param_7)

{
  HLOCAL _Dst;
  int iVar1;
  undefined4 uVar2;
  undefined1 auStack_70 [16];
  undefined1 auStack_60 [52];
  uint local_2c;
  
  local_2c = DAT_c05ca1a8;
  uVar2 = 0;
  _Dst = LocalAlloc(0x40,param_5);
  if (_Dst == (HLOCAL)0x0) {
    uVar2 = 0xe;
    LocalFree((HLOCAL)0x0);
  }
  else {
    memcpy(_Dst,param_4,param_5);
    iVar1 = 0x10;
    memcpy(auStack_70,param_3,0x10);
    memcpy(auStack_60,param_1,param_2);
    FUN_c05c7d64();
    do {
      FUN_c05c7d54();
      iVar1 = iVar1 + -1;
    } while (iVar1 != 0);
    FUN_c05c7d54();
    *param_6 = _Dst;
    *param_7 = param_5;
  }
  FUN_c05c8248(local_2c);
  return uVar2;
}



/* c05c3f84 FUN_c05c3f84 */

/* Boundary evidence: original MIPS .pdata c05c3f84..c05c411f. Semantic name remains unreviewed. */

undefined4
FUN_c05c3f84(undefined4 *param_1,undefined4 *param_2,uint *param_3,void *param_4,void *param_5,
            int param_6,int *param_7)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  void *_Src;
  undefined4 local_70;
  undefined1 local_6c;
  undefined1 local_6b;
  undefined4 local_6a;
  undefined1 local_66;
  undefined1 local_65;
  undefined1 auStack_64 [32];
  undefined1 auStack_44 [32];
  uint local_24;
  
  local_24 = DAT_c05ca1a8;
  iVar1 = memcmp(param_1,param_2,6);
  puVar3 = param_2;
  if (0 < iVar1) {
    puVar3 = param_1;
    param_1 = param_2;
  }
  iVar1 = memcmp(param_4,param_5,0x20);
  _Src = param_5;
  if (0 < iVar1) {
    _Src = param_4;
    param_4 = param_5;
  }
  local_70 = *param_1;
  local_6b = *(undefined1 *)((int)param_1 + 5);
  local_6c = *(undefined1 *)(param_1 + 1);
  local_65 = *(undefined1 *)((int)puVar3 + 5);
  local_66 = *(undefined1 *)(puVar3 + 1);
  local_6a = *puVar3;
  memcpy(auStack_64,param_4,0x20);
  memcpy(auStack_44,_Src,0x20);
  iVar1 = 0x4c;
  uVar2 = FUN_c05c5e90(param_3 + 1,*param_3,"Pairwise key expansion",0x16,&local_70,0x4c,
                       (undefined1 *)(param_7 + 1),param_6 + 0x20);
  *param_7 = param_6;
  puVar3 = &local_70;
  do {
    *(undefined1 *)puVar3 = 0;
    iVar1 = iVar1 + -1;
    puVar3 = (undefined4 *)((int)puVar3 + 1);
  } while (iVar1 != 0);
  FUN_c05c8248(local_24);
  return uVar2;
}



/* c05c4120 FUN_c05c4120 */

/* Boundary evidence: original MIPS .pdata c05c4120..c05c41b7. Semantic name remains unreviewed. */

void FUN_c05c4120(undefined1 *param_1,uint param_2,undefined4 param_3,undefined4 param_4,
                 char param_5,undefined1 *param_6)

{
  memset(param_6,0,0x28);
  if (param_5 == '\0') {
    FUN_c05c3788(param_3,param_4,param_1,param_2,param_6);
  }
  else {
    FUN_c05c7e54(param_3,param_4,param_1,param_2,param_6,0x14);
  }
  return;
}



/* c05c41b8 FUN_c05c41b8 */

/* Boundary evidence: original MIPS .pdata c05c41b8..c05c42a3. Semantic name remains unreviewed. */

undefined4
FUN_c05c41b8(undefined1 *param_1,uint param_2,int param_3,undefined4 param_4,char param_5)

{
  int iVar1;
  void *_Src;
  undefined4 uVar2;
  undefined1 auStack_60 [16];
  undefined1 auStack_50 [40];
  uint local_28;
  
  local_28 = DAT_c05ca1a8;
  uVar2 = 0;
  if (param_1 != (undefined1 *)0x0) {
    _Src = (void *)(param_3 + 0x51);
    memcpy(auStack_60,_Src,0x10);
    memset(_Src,0,0x10);
    FUN_c05c4120(param_1,param_2,param_3,param_4,param_5,auStack_50);
    memcpy(_Src,auStack_60,0x10);
    iVar1 = memcmp(auStack_50,_Src,0x10);
    if (iVar1 == 0) goto LAB_c05c4274;
  }
  uVar2 = 0x4dc;
LAB_c05c4274:
  FUN_c05c8248(local_28);
  return uVar2;
}



/* c05c42a4 FUN_c05c42a4 */

undefined4 FUN_c05c42a4(undefined4 *param_1,uint *param_2,int param_3,ushort *param_4)

{
  ushort uVar1;
  undefined4 uVar2;
  ushort *puVar3;
  uint uVar4;
  uint uVar5;
  
  uVar5 = *param_2;
  puVar3 = (ushort *)*param_1;
  uVar2 = 0;
  *param_4 = 0;
  param_4[2] = 0;
  param_4[3] = 0;
  if (1 < uVar5) {
    uVar1 = *puVar3;
    uVar4 = (uint)uVar1;
    uVar5 = uVar5 - 2;
    puVar3 = puVar3 + 1;
    if (uVar5 < uVar4 * param_3) {
      uVar2 = 0x3ea;
    }
    else {
      *param_4 = uVar1;
      if (uVar4 != 0) {
        *(ushort **)(param_4 + 2) = puVar3;
      }
      *param_1 = (ushort *)(uVar4 * param_3 + (int)puVar3);
      *param_2 = uVar5 - uVar4 * param_3;
    }
  }
  return uVar2;
}



/* c05c4324 FUN_c05c4324 */

/* Boundary evidence: original MIPS .pdata c05c4324..c05c447b. Semantic name remains unreviewed. */

int FUN_c05c4324(undefined4 *param_1,undefined1 *param_2)

{
  undefined1 uVar1;
  int iVar2;
  undefined1 *puVar3;
  uint uVar4;
  uint local_20;
  undefined1 *local_1c;
  
  puVar3 = (undefined1 *)*param_1;
  uVar4 = param_1[1];
  iVar2 = 0;
  memset(param_2,0,0x24);
  if (uVar4 < 2) {
    iVar2 = 0x3ea;
  }
  else {
    uVar1 = puVar3[1];
    *param_2 = *puVar3;
    param_2[1] = uVar1;
    if (3 < uVar4 - 2) {
      local_1c = puVar3 + 6;
      local_20 = uVar4 - 6;
      *(undefined1 **)(param_2 + 4) = puVar3 + 2;
      iVar2 = FUN_c05c42a4(&local_1c,&local_20,4,(ushort *)(param_2 + 8));
      if ((((iVar2 == 0) && (local_20 != 0)) &&
          (iVar2 = FUN_c05c42a4(&local_1c,&local_20,4,(ushort *)(param_2 + 0x10)), iVar2 == 0)) &&
         (1 < local_20)) {
        uVar1 = local_1c[1];
        param_2[0x18] = *local_1c;
        local_1c = local_1c + 2;
        local_20 = local_20 - 2;
        param_2[0x19] = uVar1;
        iVar2 = FUN_c05c42a4(&local_1c,&local_20,0x10,(ushort *)(param_2 + 0x1c));
      }
    }
  }
  return iVar2;
}



/* c05c447c FUN_c05c447c */

/* Boundary evidence: original MIPS .pdata c05c447c..c05c44eb. Semantic name remains unreviewed. */

void FUN_c05c447c(void *param_1,uint param_2,uint *param_3)

{
  int iVar1;
  
  *param_3 = param_2;
  iVar1 = memcmp(param_1,&DAT_c05c1370,3);
  if ((iVar1 == 0) && (*(byte *)((int)param_1 + 3) < param_2)) {
    *param_3 = (uint)*(byte *)((int)param_1 + 3);
  }
  return;
}



/* c05c44ec FUN_c05c44ec */

/* Boundary evidence: original MIPS .pdata c05c44ec..c05c456f. Semantic name remains unreviewed. */

void FUN_c05c44ec(ushort *param_1,uint param_2,uint *param_3)

{
  ushort uVar1;
  uint uVar2;
  void *pvVar3;
  uint local_20 [2];
  
  uVar1 = *param_1;
  pvVar3 = *(void **)(param_1 + 2);
  *param_3 = 0;
  for (uVar2 = (uint)uVar1; uVar2 != 0; uVar2 = uVar2 - 1) {
    FUN_c05c447c(pvVar3,param_2,local_20);
    *param_3 = 1 << (local_20[0] & 0x1f) | *param_3;
    pvVar3 = (void *)((int)pvVar3 + 4);
  }
  return;
}



/* c05c4570 FUN_c05c4570 */

/* Boundary evidence: original MIPS .pdata c05c4570..c05c464b. Semantic name remains unreviewed. */

int FUN_c05c4570(undefined4 *param_1,uint *param_2)

{
  int iVar1;
  ushort local_40 [2];
  void *local_3c;
  ushort local_38 [4];
  ushort local_30 [4];
  undefined2 local_28;
  undefined2 local_24;
  uint local_20;
  
  iVar1 = FUN_c05c4324(param_1,(undefined1 *)local_40);
  if (iVar1 == 0) {
    *param_2 = (uint)local_40[0];
    param_2[1] = 4;
    param_2[2] = 0x10;
    param_2[3] = 2;
    if (local_3c != (void *)0x0) {
      FUN_c05c447c(local_3c,6,param_2 + 1);
    }
    if (local_38[0] != 0) {
      FUN_c05c44ec(local_38,6,param_2 + 2);
    }
    if (local_30[0] != 0) {
      FUN_c05c44ec(local_30,3,param_2 + 3);
    }
    *(undefined2 *)(param_2 + 4) = local_28;
    *(undefined2 *)((int)param_2 + 0x12) = local_24;
    param_2[5] = local_20;
  }
  return iVar1;
}



/* c05c464c FUN_c05c464c */

undefined4 FUN_c05c464c(int *param_1,uint param_2)

{
  ushort uVar1;
  ushort uVar2;
  int iVar3;
  
  if (0x5e < (uint)param_1[1]) {
    iVar3 = *param_1;
    *(ushort *)(param_1 + 2) = CONCAT11(*(undefined1 *)(iVar3 + 1),*(undefined1 *)(iVar3 + 2));
    *(ushort *)((int)param_1 + 10) = CONCAT11(*(undefined1 *)(iVar3 + 3),*(undefined1 *)(iVar3 + 4))
    ;
    uVar1 = *(ushort *)(param_1 + 2);
    uVar2 = CONCAT11(*(undefined1 *)(iVar3 + 0x5d),*(undefined1 *)(iVar3 + 0x5e));
    *(ushort *)(param_1 + 3) = uVar2;
    if ((uVar1 & 0x800) != 0) {
      return 0x3ea;
    }
    if ((uVar1 & 7) != param_2) {
      return 0x32;
    }
    if ((uVar2 + 0x5f <= (uint)param_1[1]) &&
       (((uVar1 & 8) == 0 ||
        ((*(ushort *)((int)param_1 + 10) != 0 && (*(ushort *)((int)param_1 + 10) < 0x21)))))) {
      return 0;
    }
  }
  return 0x18;
}



/* c05c4714 FUN_c05c4714 */

/* Boundary evidence: original MIPS .pdata c05c4714..c05c4847. Semantic name remains unreviewed. */

undefined4 FUN_c05c4714(int param_1,void *param_2,uint param_3)

{
  int iVar1;
  uint _Size;
  byte *pbVar2;
  
  if (2 < param_3) {
    iVar1 = memcmp(param_2,&DAT_c05c1370,3);
    if (iVar1 != 0) {
      return 0;
    }
    if (param_3 != 3) {
      pbVar2 = (byte *)((int)param_2 + 4);
      if (*(char *)((int)param_2 + 3) != '\x01') {
        if (*(char *)((int)param_2 + 3) != '\x04') {
          return 0;
        }
        if (param_3 - 4 != 0x10) {
          return 0x18;
        }
        if (*(int *)(param_1 + 0x10) != 0) {
          return 0;
        }
        *(byte **)(param_1 + 0x10) = pbVar2;
        return 0;
      }
      if ((((*(ushort *)(param_1 + 8) & 0x1000) != 0) && (1 < param_3 - 4)) &&
         (_Size = param_3 - 6, _Size < 0x21)) {
        *(undefined1 *)(param_1 + 0x14) = 1;
        *(byte *)(param_1 + 0x18) = *pbVar2 & 3;
        *(bool *)(param_1 + 0x19) = (*pbVar2 & 4) != 0;
        *(uint *)(param_1 + 0x3c) = _Size;
        memcpy((void *)(param_1 + 0x1a),(void *)((int)param_2 + 6),_Size);
        return 0;
      }
    }
  }
  return 0x3ea;
}



/* c05c4848 FUN_c05c4848 */

/* Boundary evidence: original MIPS .pdata c05c4848..c05c4897. Semantic name remains unreviewed. */

bool FUN_c05c4848(int param_1,void *param_2)

{
  int iVar1;
  bool bVar2;
  
  bVar2 = true;
  if (*(void **)(param_1 + 0x10) != (void *)0x0) {
    iVar1 = memcmp(param_2,*(void **)(param_1 + 0x10),0x10);
    bVar2 = iVar1 == 0;
  }
  return bVar2;
}



/* c05c4898 FUN_c05c4898 */

/* Boundary evidence: original MIPS .pdata c05c4898..c05c4a43. Semantic name remains unreviewed. */

undefined4
FUN_c05c4898(undefined4 *param_1,undefined1 *param_2,uint param_3,void *param_4,void *param_5,
            ushort param_6,undefined1 *param_7,uint *param_8)

{
  uint uVar1;
  undefined4 uVar2;
  uint uVar3;
  undefined1 auStack_58 [40];
  uint local_30;
  
  local_30 = DAT_c05ca1a8;
  uVar1 = param_6 + 0x5f & 0xffff;
  uVar3 = uVar1 + 4;
  uVar2 = 0;
  if (*param_8 < uVar3) {
    uVar2 = 0x25b;
  }
  else {
    param_7[1] = 3;
    *param_7 = 1;
    param_7[2] = (char)(uVar1 >> 8);
    param_7[3] = (char)uVar1;
    memset(param_7 + 4,0,0x60);
    param_7[4] = 2;
    param_7[5] = (char)(param_3 >> 8);
    param_7[6] = (char)param_3;
    *(undefined4 *)(param_7 + 9) = *param_1;
    *(undefined4 *)(param_7 + 0xd) = param_1[1];
    if (param_4 != (void *)0x0) {
      memcpy(param_7 + 0x11,param_4,0x20);
    }
    param_7[0x61] = (char)(param_6 >> 8);
    param_7[0x62] = (char)param_6;
    if (param_5 != (void *)0x0) {
      memcpy(param_7 + 99,param_5,(uint)param_6);
    }
    FUN_c05c4120(param_2,0x10,param_7,uVar3,(param_3 & 7) == 2,auStack_58);
    memcpy(param_7 + 0x51,auStack_58,0x10);
    *param_8 = uVar3;
  }
  FUN_c05c8248(local_30);
  return uVar2;
}



/* c05c4a44 FUN_c05c4a44 */

/* Boundary evidence: original MIPS .pdata c05c4a44..c05c4b03. Semantic name remains unreviewed. */

void FUN_c05c4a44(ushort *param_1,undefined1 *param_2,uint *param_3,uint param_4)

{
  ushort uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint auStack_28 [2];
  uint local_20;
  
  local_20 = DAT_c05ca1a8;
  if ((char)param_1[0x8c] != '\0') {
    uVar1 = *param_1;
    uVar3 = *(uint *)(param_1 + 0xa0);
    uVar4 = *(uint *)(param_1 + 0xa2);
    *(uint *)(param_1 + 0xa0) = uVar3 + 1;
    *(uint *)(param_1 + 0xa2) = uVar4 + (uVar3 + 1 < uVar3);
    FUN_c05c5848(uVar3,uVar4,auStack_28);
    iVar2 = FUN_c05c4898(auStack_28,(undefined1 *)((int)param_1 + 0x119),param_4 | uVar1 | 0xb00,
                         (void *)0x0,(void *)0x0,0,param_2,param_3);
    if (iVar2 == 0) goto LAB_c05c4ae0;
  }
  *param_3 = 0;
LAB_c05c4ae0:
  FUN_c05c8248(local_20);
  return;
}



/* c05c4b04 FUN_c05c4b04 */

void FUN_c05c4b04(undefined2 *param_1,undefined2 param_2)

{
  *param_1 = param_2;
  return;
}



/* c05c4b0c FUN_c05c4b0c */

void FUN_c05c4b0c(int param_1,undefined4 param_2,undefined4 param_3)

{
  *(undefined4 *)(param_1 + 0x34) = param_2;
  *(undefined4 *)(param_1 + 0x38) = param_3;
  return;
}



/* c05c4b18 FUN_c05c4b18 */

/* Boundary evidence: original MIPS .pdata c05c4b18..c05c4b3f. Semantic name remains unreviewed. */

void FUN_c05c4b18(int param_1,void *param_2)

{
  *(undefined1 *)(param_1 + 0x118) = 0;
  *(undefined1 *)(param_1 + 0xc9) = 0;
  memcpy((void *)(param_1 + 0x3c),param_2,0x44);
  return;
}



/* c05c4b40 FUN_c05c4b40 */

/* Boundary evidence: original MIPS .pdata c05c4b40..c05c4bf3. Semantic name remains unreviewed. */

undefined2 * FUN_c05c4b40(undefined2 *param_1)

{
  *param_1 = 0;
  memset(param_1 + 0x1e,0,0x44);
  *(undefined4 *)(param_1 + 0x8a) = 0x10;
  *(undefined4 *)(param_1 + 8) = 0;
  *(undefined4 *)(param_1 + 10) = 0;
  *(undefined4 *)(param_1 + 0xc) = 0;
  *(undefined4 *)(param_1 + 0xe) = 0;
  *(undefined1 *)(param_1 + 0x10) = 0;
  *(undefined4 *)(param_1 + 0x88) = 0;
  RegReadValues(0x80000002,L"Comm\\EAPOL",L"WPA2Max4WayHandshakeFailures",4,0,param_1 + 0x8a,4,0);
  *(undefined1 *)((int)param_1 + 0xc9) = 0;
  *(undefined1 *)(param_1 + 0x8c) = 0;
  *(undefined1 *)(param_1 + 0x40) = 0;
  memset((void *)((int)param_1 + 0x81),0,8);
  *(undefined4 *)(param_1 + 0xa0) = 0;
  *(undefined4 *)(param_1 + 0xa2) = 0;
  return param_1;
}



/* c05c4bf4 FUN_c05c4bf4 */

/* Boundary evidence: original MIPS .pdata c05c4bf4..c05c4c83. Semantic name remains unreviewed. */

void FUN_c05c4bf4(int param_1)

{
  int iVar1;
  int iVar2;
  undefined1 *puVar3;
  
  LocalFree(*(HLOCAL *)(param_1 + 0x10));
  LocalFree(*(HLOCAL *)(param_1 + 0x18));
  iVar1 = 0x44;
  iVar2 = 0x44;
  puVar3 = (undefined1 *)(param_1 + 0x3c);
  do {
    *puVar3 = 0;
    iVar2 = iVar2 + -1;
    puVar3 = puVar3 + 1;
  } while (iVar2 != 0);
  puVar3 = (undefined1 *)(param_1 + 0xcc);
  do {
    *puVar3 = 0;
    iVar1 = iVar1 + -1;
    puVar3 = puVar3 + 1;
  } while (iVar1 != 0);
  iVar1 = 0x10;
  iVar2 = 0x10;
  puVar3 = (undefined1 *)(param_1 + 0x119);
  do {
    *puVar3 = 0;
    iVar2 = iVar2 + -1;
    puVar3 = puVar3 + 1;
  } while (iVar2 != 0);
  puVar3 = (undefined1 *)(param_1 + 0x129);
  do {
    *puVar3 = 0;
    iVar1 = iVar1 + -1;
    puVar3 = puVar3 + 1;
  } while (iVar1 != 0);
  return;
}



/* c05c4c84 FUN_c05c4c84 */

/* Boundary evidence: original MIPS .pdata c05c4c84..c05c4d27. Semantic name remains unreviewed. */

void FUN_c05c4c84(int param_1,int param_2)

{
  uint uVar1;
  undefined1 *puVar2;
  uint local_18 [2];
  
  puVar2 = *(undefined1 **)(param_1 + 0x78);
  if (*(ushort **)(param_1 + 0x148) != (ushort *)0x0) {
    if (param_2 == 2) {
      uVar1 = 0;
    }
    else if (param_2 == 6) {
      uVar1 = 0x408;
    }
    else {
      if (param_2 != 0xe) {
        return;
      }
      uVar1 = 0x400;
    }
    local_18[0] = 100;
    FUN_c05c4a44(*(ushort **)(param_1 + 0x148),puVar2,local_18,uVar1);
    if (local_18[0] != 0) {
      (**(code **)(param_1 + 0x7c))(*(undefined4 *)(param_1 + 0x6c),puVar2,local_18[0],0,0);
    }
  }
  return;
}



/* c05c4d28 EolSessionSetMACAddresses */

void EolSessionSetMACAddresses(int param_1,undefined4 *param_2,undefined4 *param_3)

{
  int iVar1;
  
                    /* 0x4d28  21  EolSessionSetMACAddresses */
  iVar1 = *(int *)(param_1 + 0x148);
  if (iVar1 != 0) {
    *(undefined4 *)(iVar1 + 2) = *param_3;
    *(undefined2 *)(iVar1 + 6) = *(undefined2 *)(param_3 + 1);
    *(undefined4 *)(iVar1 + 8) = *param_2;
    *(undefined2 *)(iVar1 + 0xc) = *(undefined2 *)(param_2 + 1);
    *(undefined1 *)(iVar1 + 0x80) = 0;
  }
  return;
}



/* c05c4d8c EolSessionSetExpectedPMKID */

/* Boundary evidence: original MIPS .pdata c05c4d8c..c05c4dcf. Semantic name remains unreviewed. */

void EolSessionSetExpectedPMKID(int param_1,void *param_2)

{
  int iVar1;
  
                    /* 0x4d8c  20  EolSessionSetExpectedPMKID */
  iVar1 = *(int *)(param_1 + 0x148);
  if ((iVar1 != 0) && (*(undefined1 *)(iVar1 + 0x20) = 0, param_2 != (void *)0x0)) {
    memcpy((void *)(iVar1 + 0x21),param_2,0x10);
    *(undefined1 *)(iVar1 + 0x20) = 1;
  }
  return;
}



/* c05c4dd0 FUN_c05c4dd0 */

/* Boundary evidence: original MIPS .pdata c05c4dd0..c05c4ee3. Semantic name remains unreviewed. */

int FUN_c05c4dd0(int *param_1,char *param_2,uint param_3)

{
  int iVar1;
  char *pcVar2;
  char *pcVar3;
  uint uVar4;
  uint uVar5;
  char *local_20;
  uint local_1c;
  
  iVar1 = 0;
  uVar4 = (uint)*(ushort *)(param_1 + 3);
  pcVar2 = (char *)(*param_1 + 0x5f);
  if (param_2 != (char *)0x0) {
    uVar4 = param_3;
    pcVar2 = param_2;
  }
  param_1[4] = 0;
  *(undefined1 *)(param_1 + 5) = 0;
  *(undefined1 *)(param_1 + 0x10) = 0;
  while( true ) {
    if (uVar4 == 0) {
      return iVar1;
    }
    if (uVar4 < 2) break;
    uVar5 = (uint)(byte)pcVar2[1];
    uVar4 = uVar4 - 2;
    pcVar3 = pcVar2 + 2;
    if (uVar4 < uVar5) {
      return 0x18;
    }
    if (*pcVar2 == '0') {
      local_20 = pcVar3;
      local_1c = uVar5;
      iVar1 = FUN_c05c4570(&local_20,(uint *)(param_1 + 0x11));
      if (iVar1 == 0) {
        *(undefined1 *)(param_1 + 0x10) = 1;
      }
    }
    else if (*pcVar2 == -0x23) {
      if (uVar5 == 0) {
        uVar4 = 0;
      }
      else {
        iVar1 = FUN_c05c4714((int)param_1,pcVar3,uVar5);
      }
    }
    uVar4 = uVar4 - uVar5;
    pcVar2 = pcVar3 + uVar5;
  }
  return 0x18;
}



/* c05c4ee4 FUN_c05c4ee4 */

/* Boundary evidence: original MIPS .pdata c05c4ee4..c05c5563. Semantic name remains unreviewed. */

int FUN_c05c4ee4(ushort *param_1,int param_2,int param_3,uint *param_4,undefined1 *param_5,
                uint *param_6,undefined4 *param_7,undefined4 *param_8,uint *param_9,void *param_10)

{
  bool bVar1;
  bool bVar2;
  undefined4 *puVar3;
  ushort uVar4;
  bool bVar5;
  int iVar6;
  undefined3 extraout_var;
  SIZE_T SVar7;
  ushort *puVar8;
  ushort *puVar9;
  char *hMem;
  ushort local_f6;
  ushort local_f4;
  char *local_f0;
  SIZE_T local_ec;
  undefined1 *local_e8;
  ushort *local_e4;
  void *local_e0;
  undefined4 *local_dc;
  int local_d8;
  uint local_d4;
  void *local_d0;
  undefined1 *local_cc;
  undefined4 *local_c8;
  int local_c4;
  uint *local_c0;
  uint local_bc;
  uint *local_b8;
  int local_b0;
  int local_ac;
  ushort local_a8;
  ushort local_a6;
  ushort local_a4;
  undefined4 local_a0;
  char local_9c;
  undefined1 auStack_98 [40];
  char local_70;
  uint local_64;
  uint local_60;
  undefined1 local_50;
  undefined1 auStack_4f [31];
  uint local_30;
  
  local_30 = DAT_c05ca1a8;
  local_b0 = param_2 + 4;
  local_cc = param_5;
  hMem = (char *)0x0;
  local_b8 = param_6;
  local_dc = param_7;
  local_d0 = param_10;
  local_ac = param_3 + -4;
  local_c8 = param_8;
  local_c0 = param_9;
  local_a8 = 0;
  local_a4 = 0;
  local_a0 = 0;
  local_9c = '\0';
  local_70 = '\0';
  local_f0 = (char *)0x0;
  local_bc = 0;
  local_ec = 0;
  local_e8 = (undefined1 *)0x0;
  local_50 = 0;
  local_d8 = param_2;
  local_c4 = param_3;
  memset(auStack_4f,0,0x1f);
  bVar2 = false;
  *param_4 = 0;
  *param_8 = 0;
  bVar1 = false;
  *param_9 = 0;
  local_e0 = (void *)0x0;
  local_f4 = 0;
  local_e4 = (ushort *)0x0;
  local_d4 = 0;
  iVar6 = FUN_c05c464c(&local_b0,(uint)*param_1);
  if (iVar6 != 0) goto LAB_c05c5520;
  iVar6 = memcmp((undefined4 *)(param_2 + 9),(void *)((int)param_1 + 0x81),8);
  uVar4 = local_a8;
  if (((char)param_1[0x40] == '\0') || (0 < iVar6)) {
    if ((local_a8 & 8) == 0) {
      if (((local_a8 & 0x1100) == 0x1100) && ((char)param_1[0x8c] != '\0')) {
        local_f6 = 0x300;
        puVar9 = (ushort *)((int)param_1 + 0x119);
LAB_c05c51bc:
        puVar8 = (ushort *)((int)param_1 + 0x129);
LAB_c05c51c0:
        if (((uVar4 & 0x100) != 0) &&
           (iVar6 = FUN_c05c41b8((undefined1 *)puVar9,0x10,local_d8,local_c4,(uVar4 & 7) == 2),
           iVar6 != 0)) goto LAB_c05c5520;
        SVar7 = local_bc;
        if ((uVar4 & 0x1000) != 0) {
          if (puVar8 == (ushort *)0x0) goto LAB_c05c5028;
          if ((uVar4 & 7) == 2) {
            iVar6 = FUN_c05c3d68(puVar8,0x10,(undefined4 *)(param_2 + 99),(uint)local_a4,&local_f0,
                                 &local_ec);
          }
          else {
            iVar6 = FUN_c05c3e4c(puVar8,0x10,(void *)(param_2 + 0x31),(void *)(param_2 + 99),
                                 (uint)local_a4,&local_f0,&local_ec);
          }
          SVar7 = local_ec;
          hMem = local_f0;
          if (iVar6 != 0) goto LAB_c05c5520;
        }
        iVar6 = FUN_c05c4dd0(&local_b0,hMem,SVar7);
        if (iVar6 != 0) goto LAB_c05c5520;
        if (((char)param_1[0x10] != '\0') &&
           (bVar5 = FUN_c05c4848((int)&local_b0,(void *)((int)param_1 + 0x21)),
           CONCAT31(extraout_var,bVar5) == 0)) goto LAB_c05c5068;
        if (bVar1) {
          if (local_70 == '\0') {
            *param_4 = 1;
            iVar6 = 0x3ea;
            goto LAB_c05c5520;
          }
          if (((1 << (*(uint *)(param_1 + 0x1a) & 0x1f) & local_64) != 0) &&
             ((1 << (*(uint *)(param_1 + 0x1c) & 0x1f) & local_60) != 0)) goto LAB_c05c5340;
LAB_c05c5310:
          iVar6 = 0x3ea;
          *param_4 = 1;
        }
        else {
LAB_c05c5340:
          if (bVar2) {
            if (local_9c == '\0') goto LAB_c05c5310;
LAB_c05c5364:
            memcpy(local_d0,auStack_98,0x28);
            *local_dc = *(undefined4 *)(param_2 + 0x41);
            local_dc[1] = *(undefined4 *)(param_2 + 0x45);
            *param_4 = *param_4 | 8;
          }
          else if (local_9c != '\0') goto LAB_c05c5364;
          uVar4 = local_a8;
          puVar3 = local_dc;
          if ((local_a8 & 0x80) != 0) {
            iVar6 = FUN_c05c4898((undefined4 *)(local_d8 + 9),(undefined1 *)puVar9,
                                 (uint)(*param_1 | local_f6),local_e8,local_e0,local_f4,local_cc,
                                 local_b8);
            if (iVar6 != 0) goto LAB_c05c5520;
            *param_4 = *param_4 | 2;
          }
          if (local_e8 != (undefined1 *)0x0) {
            memcpy((void *)((int)param_1 + 0xa9),local_e8,0x20);
          }
          memcpy((void *)((int)param_1 + 0x89),(void *)(param_2 + 0x11),0x20);
          if ((uVar4 & 0x108) == 0x108) {
            memcpy((void *)((int)param_1 + 0x119),param_1 + 0x68,0x10);
            memcpy((void *)((int)param_1 + 0x129),param_1 + 0x70,0x10);
            *(undefined1 *)(param_1 + 0x8c) = 1;
            param_1[0x88] = 0;
            param_1[0x89] = 0;
            if (((uVar4 & 0x40) != 0) && (local_e4 != (ushort *)0x0)) {
              *local_c8 = local_e4;
              *local_c0 = local_d4;
              *puVar3 = *(undefined4 *)(param_2 + 0x41);
              puVar3[1] = *(undefined4 *)(param_2 + 0x45);
              *param_4 = *param_4 | 4;
            }
          }
          if ((char)param_1[0x8c] != '\0') {
            *param_4 = *param_4 | 0x10;
          }
          *(undefined4 *)((int)param_1 + 0x81) = *(undefined4 *)(param_2 + 9);
          *(undefined4 *)((int)param_1 + 0x85) = *(undefined4 *)(param_2 + 0xd);
          *(undefined1 *)(param_1 + 0x40) = 1;
        }
        goto LAB_c05c5520;
      }
    }
    else {
      local_f6 = 0x108;
      if ((local_a8 & 0x100) == 0) {
        if (*(uint *)(param_1 + 0x1e) == 0) {
LAB_c05c5068:
          iVar6 = 0x572;
          goto LAB_c05c5520;
        }
        if (((local_a8 & 0x1000) == 0) || ((char)param_1[0x8c] != '\0')) {
          iVar6 = *(int *)(param_1 + 0x88);
          *(uint *)(param_1 + 0x88) = iVar6 + 1U;
          if (*(uint *)(param_1 + 0x8a) < iVar6 + 1U) {
            *param_4 = 1;
          }
          FUN_c05c59e8(&local_50);
          local_e8 = &local_50;
          iVar6 = FUN_c05c3f84((undefined4 *)(param_1 + 1),(undefined4 *)(param_1 + 4),
                               (uint *)(param_1 + 0x1e),&local_50,(void *)(param_2 + 0x11),
                               (uint)local_a6,(int *)(param_1 + 0x66));
          if (iVar6 != 0) goto LAB_c05c5520;
          local_e0 = *(void **)(param_1 + 0xc);
          local_f4 = param_1[0xe];
          puVar9 = param_1 + 0x68;
          *(undefined1 *)((int)param_1 + 0xc9) = 1;
          goto LAB_c05c51bc;
        }
      }
      else if (*(char *)((int)param_1 + 0xc9) != '\0') {
        iVar6 = memcmp((void *)(param_2 + 0x11),(void *)((int)param_1 + 0x89),0x20);
        if (iVar6 != 0) {
          *param_4 = 1;
          iVar6 = 0x3ea;
          goto LAB_c05c5520;
        }
        local_d4 = *(uint *)(param_1 + 0x66);
        if (local_a6 != local_d4) {
          *param_4 = 1;
          iVar6 = 0x3ea;
          goto LAB_c05c5520;
        }
        local_e4 = param_1 + 0x78;
        bVar2 = true;
        bVar1 = true;
        local_f6 = 0x308;
        puVar9 = param_1 + 0x68;
        puVar8 = param_1 + 0x70;
        goto LAB_c05c51c0;
      }
    }
  }
LAB_c05c5028:
  iVar6 = 0x3ea;
LAB_c05c5520:
  LocalFree(hMem);
  FUN_c05c8248(local_30);
  return iVar6;
}



/* c05c5564 FUN_c05c5564 */

/* Boundary evidence: original MIPS .pdata c05c5564..c05c5653. Semantic name remains unreviewed. */

int FUN_c05c5564(int param_1,void *param_2,uint param_3)

{
  HLOCAL _Dst;
  int iVar1;
  int local_38;
  int local_34;
  uint auStack_30 [4];
  short local_1e;
  void *local_1c;
  
  iVar1 = 0;
  LocalFree(*(HLOCAL *)(param_1 + 0x18));
  *(undefined4 *)(param_1 + 0x18) = 0;
  *(undefined4 *)(param_1 + 0x1c) = 0;
  *(undefined1 *)(param_1 + 0x20) = 0;
  if (param_2 != (void *)0x0) {
    _Dst = LocalAlloc(0x40,param_3);
    *(HLOCAL *)(param_1 + 0x18) = _Dst;
    if (_Dst == (HLOCAL)0x0) {
      iVar1 = 0xe;
    }
    else {
      memcpy(_Dst,param_2,param_3);
      *(uint *)(param_1 + 0x1c) = param_3;
      if (1 < param_3) {
        local_38 = *(int *)(param_1 + 0x18) + 2;
        local_34 = param_3 - 2;
        iVar1 = FUN_c05c4570(&local_38,auStack_30);
        if ((iVar1 == 0) && (local_1e != 0)) {
          *(undefined1 *)(param_1 + 0x20) = 0;
          if (local_1c != (void *)0x0) {
            memcpy((void *)(param_1 + 0x21),local_1c,0x10);
            *(undefined1 *)(param_1 + 0x20) = 1;
          }
        }
      }
    }
  }
  return iVar1;
}



/* c05c5654 FUN_c05c5654 */

/* Boundary evidence: original MIPS .pdata c05c5654..c05c581f. Semantic name remains unreviewed. */

int FUN_c05c5654(int *param_1,int param_2,int param_3)

{
  uint uVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint local_638;
  uint local_634;
  undefined4 local_630;
  uint local_62c;
  byte local_628 [2];
  undefined1 auStack_626 [34];
  undefined4 local_604;
  undefined4 auStack_600 [2];
  undefined1 auStack_5f8 [1500];
  uint local_1c;
  
  local_1c = DAT_c05ca1a8;
  local_638 = 0;
  if ((ushort *)param_1[0x52] == (ushort *)0x0) {
    iVar4 = 0x32;
  }
  else {
    uVar3 = param_1[0x1d];
    if (uVar3 < 0x5dd) {
      local_634 = 0x5dc - uVar3;
      iVar4 = FUN_c05c4ee4((ushort *)param_1[0x52],param_2,param_3,&local_638,auStack_5f8 + uVar3,
                           &local_634,auStack_600,&local_630,&local_62c,local_628);
      uVar1 = local_638;
      if (iVar4 == 0) {
        if ((local_638 & 1) == 0) {
          uVar5 = local_638 & 0x10;
          uVar2 = 0;
          if (uVar5 != 0) {
            FUN_c05c7304(param_1);
            uVar2 = 2;
          }
          if ((uVar1 & 2) != 0) {
            (*(code *)param_1[0x1f])(param_1[0x1b],auStack_5f8 + uVar3,local_634,uVar2,0);
          }
          if (((uVar1 & 4) != 0) && ((code *)param_1[0x21] != (code *)0x0)) {
            (*(code *)param_1[0x21])(param_1[0x1b],0xe0000000,0,local_630,local_62c);
          }
          if (((uVar1 & 8) != 0) && ((code *)param_1[0x21] != (code *)0x0)) {
            (*(code *)param_1[0x21])
                      (param_1[0x1b],local_628[0] | 0x20000000,auStack_600,auStack_626,local_604);
          }
          if (uVar5 == 0) {
            FUN_c05c763c(param_1);
          }
        }
        else {
          (*(code *)param_1[0x1f])(param_1[0x1b],0,0,3,0x30a);
        }
      }
    }
    else {
      iVar4 = 0x18;
    }
  }
  FUN_c05c8248(local_1c);
  return iVar4;
}



/* c05c5820 EolSessionSetStationRSNIE */

/* Boundary evidence: original MIPS .pdata c05c5820..c05c5847. Semantic name remains unreviewed. */

void EolSessionSetStationRSNIE(int param_1,void *param_2,uint param_3)

{
                    /* 0x5820  23  EolSessionSetStationRSNIE */
  if (*(int *)(param_1 + 0x148) != 0) {
    FUN_c05c5564(*(int *)(param_1 + 0x148),param_2,param_3);
  }
  return;
}



/* c05c5848 FUN_c05c5848 */

void FUN_c05c5848(uint param_1,uint param_2,uint *param_3)

{
  longlong lVar1;
  ulonglong uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  
  uVar2 = ((ulonglong)param_1 * 0x10000 + ((ulonglong)param_1 & 0xffffffff0000ff00) & 0xffffffff) *
          0x10000 + ((ulonglong)param_1 & 0xffffffff00ff0000);
  uVar2 = (uVar2 & 0xffffffff) * 0x10000 +
          (CONCAT44((int)(uVar2 >> 0x20) * 0x10000,param_1) & 0xffffffffff000000);
  lVar1 = (uVar2 & 0xffffffff) * 0x100 +
          (CONCAT44((int)(uVar2 >> 0x20) * 0x100,param_2 >> 8) & 0xffffffff0000ff00);
  uVar4 = (uint)lVar1;
  uVar6 = uVar4 + param_2 * 0x1000000;
  uVar5 = uVar6 + (param_2 & 0xff00) * 0x100;
  uVar3 = uVar5 + (param_2 >> 0x18);
  *param_3 = uVar3;
  param_3[1] = (int)((ulonglong)lVar1 >> 0x20) + (uint)(uVar6 < uVar4) + (uint)(uVar5 < uVar6) +
               (uint)(uVar3 < uVar5);
  return;
}



/* c05c596c FUN_c05c596c */

void FUN_c05c596c(byte *param_1,int param_2,uint param_3,int *param_4,int *param_5)

{
  byte *pbVar1;
  uint uVar2;
  
  uVar2 = 0;
  if (param_3 != 0) {
    pbVar1 = param_1;
    do {
      if (pbVar1[param_2 - (int)param_1] < *pbVar1) {
        *param_5 = (int)param_1;
        goto LAB_c05c59c0;
      }
      if (*pbVar1 < pbVar1[param_2 - (int)param_1]) {
        *param_4 = (int)param_1;
        *param_5 = param_2;
        return;
      }
      uVar2 = uVar2 + 1;
      pbVar1 = pbVar1 + 1;
    } while (uVar2 < param_3);
  }
  *param_5 = (int)param_1;
LAB_c05c59c0:
  *param_4 = param_2;
  return;
}



/* c05c59e8 FUN_c05c59e8 */

/* Boundary evidence: original MIPS .pdata c05c59e8..c05c5a57. Semantic name remains unreviewed. */

void FUN_c05c59e8(void *param_1)

{
  char *pcVar1;
  int iVar2;
  int iVar3;
  
  memcpy(param_1,&DAT_c05ca1cc,0x20);
  DAT_c05ca1eb = DAT_c05ca1eb + '\x01';
  iVar2 = 0x1f;
  do {
    if ((&DAT_c05ca1cc)[iVar2] != '\0') {
      return;
    }
    iVar3 = iVar2 + -1;
    pcVar1 = (char *)((int)&DAT_c05ca1c8 + iVar2 + 3);
    *pcVar1 = *pcVar1 + '\x01';
    iVar2 = iVar3;
  } while (iVar3 != 0);
  return;
}



/* c05c5a58 FUN_c05c5a58 */

/* Boundary evidence: original MIPS .pdata c05c5a58..c05c5a9f. Semantic name remains unreviewed. */

void FUN_c05c5a58(int param_1)

{
  CTEGenRandom(0x10,param_1 + 0x174);
  CTEGenRandom(0x10,param_1 + 0x150);
  CTEGenRandom(0x20,&DAT_c05ca1cc);
  return;
}



/* c05c5aa0 FUN_c05c5aa0 */

/* Boundary evidence: original MIPS .pdata c05c5aa0..c05c5e8f. Semantic name remains unreviewed. */

bool FUN_c05c5aa0(void *param_1,uint param_2,undefined4 *param_3,size_t param_4,void *param_5)

{
  undefined1 *puVar1;
  uint uVar2;
  uint uVar3;
  void *_Dst;
  BOOL BVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  DWORD DVar8;
  int iVar9;
  uint *puVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  HCRYPTKEY local_458;
  HCRYPTPROV local_454;
  BYTE local_450 [4];
  int local_44c;
  void *local_448;
  int local_444;
  size_t local_440;
  DWORD local_43c;
  undefined4 local_438;
  undefined1 local_434 [4];
  undefined1 auStack_430 [4];
  undefined1 auStack_42c [4];
  undefined4 local_428;
  uint local_424;
  uint local_420;
  uint local_41c;
  BYTE local_418 [4];
  undefined4 local_414;
  undefined1 auStack_410 [4];
  undefined1 auStack_40c [988];
  uint local_30;
  
  local_30 = DAT_c05ca1a8;
  iVar6 = param_4 - 8;
  local_448 = param_5;
  if (iVar6 < 0) {
    iVar6 = param_4 - 1;
  }
  iVar6 = iVar6 >> 3;
  local_454 = 0;
  DVar8 = 0;
  local_458 = 0;
  local_450[0] = '\0';
  local_450[1] = '\0';
  local_450[2] = '\0';
  local_450[3] = '\0';
  if ((param_4 == 0) || (_Dst = malloc(param_4), _Dst == (void *)0x0)) {
LAB_c05c5b18:
    FUN_c05c8248(local_30);
    return false;
  }
  BVar4 = CryptAcquireContextW(&local_454,(LPCWSTR)0x0,(LPCWSTR)0x0,0x18,0xf0000000);
  if (BVar4 == 0) {
    GetLastError();
    free(_Dst);
    goto LAB_c05c5b18;
  }
  if (param_2 == 0x10) {
    local_414 = 0x660e;
  }
  else {
    if (param_2 == 0x18) {
      local_414 = 0x660f;
      goto LAB_c05c5bc4;
    }
    local_414 = 0x6610;
  }
LAB_c05c5bc4:
  local_418[0] = '\b';
  local_418[2] = 0;
  puVar1 = auStack_410 + 3;
  uVar2 = (uint)puVar1 & 3;
  *(uint *)(puVar1 + -uVar2) =
       *(uint *)(puVar1 + -uVar2) & -1 << (uVar2 + 1) * 8 | param_2 >> (3 - uVar2) * 8;
  local_418[1] = 2;
  local_418[3] = 0;
  auStack_410 = (undefined1  [4])param_2;
  memcpy(auStack_40c,param_1,param_2);
  local_434 = (undefined1  [4])param_3[1];
  local_438 = *param_3;
  local_440 = param_4 - 8;
  memcpy(_Dst,param_3 + 2,local_440);
  iVar11 = 5;
  iVar12 = iVar6 * 5;
  iVar5 = iVar6 + -1;
  iVar6 = -iVar6;
  local_44c = iVar6;
  local_444 = iVar5;
  do {
    if (-1 < iVar5) {
      iVar13 = iVar12 + iVar5 + 1;
      puVar10 = (uint *)(iVar5 * 8 + (int)_Dst);
      iVar9 = iVar5;
      do {
        auStack_430 = (undefined1  [4])*puVar10;
        uVar7 = puVar10[1];
        puVar1 = auStack_430 + 3;
        uVar2 = (uint)puVar1 & 3;
        *(uint *)(puVar1 + -uVar2) =
             *(uint *)(puVar1 + -uVar2) & -1 << (uVar2 + 1) * 8 |
             (uint)auStack_430 >> (3 - uVar2) * 8;
        puVar1 = auStack_42c + 3;
        uVar2 = (uint)puVar1 & 3;
        *(uint *)(puVar1 + -uVar2) =
             *(uint *)(puVar1 + -uVar2) & -1 << (uVar2 + 1) * 8 | uVar7 >> (3 - uVar2) * 8;
        local_434[3] = local_434[3] ^ (byte)iVar13;
        auStack_42c = (undefined1  [4])uVar7;
        memcpy(&local_428,&local_438,0x10);
        BVar4 = CryptImportKey(local_454,local_418,param_2 + 0xc,0,0,&local_458);
        if (BVar4 == 0) {
LAB_c05c5df4:
          DVar8 = GetLastError();
          goto LAB_c05c5e14;
        }
        local_450[0] = '\x01';
        local_450[1] = '\0';
        local_450[2] = '\0';
        local_450[3] = '\0';
        BVar4 = CryptSetKeyParam(local_458,4,local_450,0);
        if (BVar4 == 0) goto LAB_c05c5df4;
        local_43c = 0x10;
        BVar4 = CryptDecrypt(local_458,0,0,0,(BYTE *)&local_428,&local_43c);
        if (BVar4 == 0) goto LAB_c05c5df4;
        CryptDestroyKey(local_458);
        uVar3 = local_41c;
        uVar7 = local_420;
        local_434 = (undefined1  [4])local_424;
        local_438 = local_428;
        iVar9 = iVar9 + -1;
        iVar13 = iVar13 + -1;
        puVar1 = local_434 + 3;
        uVar2 = (uint)puVar1 & 3;
        *(uint *)(puVar1 + -uVar2) =
             *(uint *)(puVar1 + -uVar2) & -1 << (uVar2 + 1) * 8 | local_424 >> (3 - uVar2) * 8;
        *puVar10 = uVar7;
        puVar10[1] = uVar3;
        puVar10 = puVar10 + -2;
        iVar5 = local_444;
        iVar6 = local_44c;
      } while (-1 < iVar9);
    }
    iVar11 = iVar11 + -1;
    iVar12 = iVar6 + iVar12;
  } while (-1 < iVar11);
  iVar6 = memcmp(&local_438,&DAT_c05ca180,8);
  if (iVar6 == 0) {
    memcpy(local_448,_Dst,local_440);
  }
  else {
    DVar8 = 0x1771;
LAB_c05c5e14:
    if (DVar8 != 0) {
      CryptDestroyKey(local_458);
    }
  }
  CryptReleaseContext(local_454,0);
  free(_Dst);
  FUN_c05c8248(local_30);
  return DVar8 == 0;
}



/* c05c5e90 FUN_c05c5e90 */

/* Boundary evidence: original MIPS .pdata c05c5e90..c05c5fc7. Semantic name remains unreviewed. */

undefined4
FUN_c05c5e90(void *param_1,uint param_2,void *param_3,uint param_4,void *param_5,size_t param_6,
            undefined1 *param_7,uint param_8)

{
  HLOCAL _Dst;
  undefined4 uVar1;
  uint uVar2;
  uint uBytes;
  uint uVar3;
  
  uVar2 = param_4 + param_6;
  if (((uVar2 < param_4) || (uBytes = uVar2 + 2, uBytes < uVar2)) ||
     (_Dst = LocalAlloc(0x40,uBytes), _Dst == (HLOCAL)0x0)) {
    uVar1 = 8;
  }
  else {
    memcpy(_Dst,param_3,param_4);
    *(undefined1 *)((int)_Dst + param_4) = 0;
    memcpy((undefined1 *)((int)_Dst + param_4) + 1,param_5,param_6);
    *(undefined1 *)((int)_Dst + uVar2 + 1) = 0;
    for (uVar3 = (param_8 + 0x13) / 0x14; uVar3 != 0; uVar3 = uVar3 - 1) {
      FUN_c05c7e54(_Dst,uBytes,param_1,param_2,param_7,param_8);
      *(char *)((int)_Dst + uVar2 + 1) = *(char *)((int)_Dst + uVar2 + 1) + '\x01';
      param_7 = param_7 + 0x14;
      param_8 = param_8 - 0x14;
    }
    LocalFree(_Dst);
    uVar1 = 0;
  }
  return uVar1;
}



/* c05c5fc8 FUN_c05c5fc8 */

/* Boundary evidence: original MIPS .pdata c05c5fc8..c05c6137. Semantic name remains unreviewed. */

void FUN_c05c5fc8(int param_1,undefined1 *param_2,undefined4 *param_3,void *param_4,ushort param_5,
                 ushort param_6,void *param_7)

{
  uint _Size;
  undefined1 auStack_38 [20];
  uint local_24;
  
  local_24 = DAT_c05ca1a8;
  *(undefined1 *)(param_1 + 4) = 0xfe;
  _Size = (uint)param_6;
  *(char *)(param_1 + 5) = (char)(param_5 >> 8);
  *(char *)(param_1 + 6) = (char)param_5;
  *(undefined1 *)(param_1 + 7) = 0;
  *(undefined1 *)(param_1 + 8) = 0;
  *(char *)(param_1 + 0x61) = (char)(param_6 >> 8);
  *(char *)(param_1 + 0x62) = (char)param_6;
  if ((_Size != 0) && (param_7 != (void *)0x0)) {
    memcpy((void *)(param_1 + 99),param_7,_Size);
  }
  *(undefined4 *)(param_1 + 9) = *param_3;
  *(undefined4 *)(param_1 + 0xd) = param_3[1];
  if (param_4 != (void *)0x0) {
    memcpy((void *)(param_1 + 0x11),param_4,0x20);
  }
  memset((void *)(param_1 + 0x51),0,0x10);
  memset(auStack_38,0,0x14);
  if ((param_5 & 7) == 2) {
    FUN_c05c7e54(param_1,_Size + 99,param_2,0x10,auStack_38,0x14);
  }
  else {
    FUN_c05c3788(param_1,_Size + 99,param_2,0x10,auStack_38);
  }
  memcpy((void *)(param_1 + 0x51),auStack_38,0x10);
  FUN_c05c8248(local_24);
  return;
}



/* c05c6138 FUN_c05c6138 */

/* Boundary evidence: original MIPS .pdata c05c6138..c05c627b. Semantic name remains unreviewed. */

undefined4
FUN_c05c6138(int *param_1,undefined1 *param_2,undefined4 *param_3,ushort param_4,void *param_5,
            ushort param_6,void *param_7)

{
  int iVar1;
  HLOCAL hMem;
  undefined4 uVar2;
  uint uVar3;
  uint uBytes;
  size_t _Size;
  undefined1 *_Dst;
  
  uVar3 = param_1[0x1d] + 99;
  if (((uVar3 < 99) || (uBytes = param_6 + uVar3, uBytes < uVar3)) ||
     (hMem = LocalAlloc(0x40,uBytes), hMem == (HLOCAL)0x0)) {
    uVar2 = 8;
  }
  else {
    _Dst = (undefined1 *)(param_1[0x1d] + (int)hMem);
    _Size = uBytes - param_1[0x1d];
    memset(_Dst,0,_Size);
    iVar1 = param_1[0xb2];
    _Dst[1] = 3;
    uVar3 = _Size + 0xfffc & 0xffff;
    *_Dst = (char)iVar1;
    _Dst[2] = (char)(uVar3 >> 8);
    _Dst[3] = (char)uVar3;
    FUN_c05c5fc8((int)_Dst,param_2,param_3,param_5,param_4,param_6,param_7);
    uVar2 = FUN_c05c7a44(param_1,3,_Dst,_Size - 4,0,0);
    LocalFree(hMem);
  }
  return uVar2;
}



/* c05c627c FUN_c05c627c */

/* Boundary evidence: original MIPS .pdata c05c627c..c05c630b. Semantic name remains unreviewed. */

void FUN_c05c627c(int *param_1,ushort param_2)

{
  uint uVar1;
  uint uVar2;
  uint auStack_20 [2];
  uint local_18;
  
  local_18 = DAT_c05ca1a8;
  uVar1 = param_1[0xae];
  uVar2 = param_1[0xaf];
  param_1[0xae] = uVar1 + 1;
  param_1[0xaf] = uVar2 + (uVar1 + 1 < uVar1);
  FUN_c05c5848(uVar1,uVar2,auStack_20);
  FUN_c05c6138(param_1,(undefined1 *)(param_1 + 0x54),auStack_20,
               *(ushort *)(param_1 + 0xb0) | param_2 | 0x900,(void *)0x0,0,(void *)0x0);
  FUN_c05c8248(local_18);
  return;
}



/* c05c630c FUN_c05c630c */

/* Boundary evidence: original MIPS .pdata c05c630c..c05c636b. Semantic name remains unreviewed. */

void FUN_c05c630c(int *param_1,int param_2)

{
  ushort uVar1;
  
  if (param_1[0xc1] != 0) {
    if (param_2 == 2) {
      uVar1 = 0;
    }
    else if (param_2 == 6) {
      uVar1 = 0x408;
    }
    else {
      if (param_2 != 0xe) {
        return;
      }
      uVar1 = 0x400;
    }
    FUN_c05c627c(param_1,uVar1);
  }
  return;
}



/* c05c636c FUN_c05c636c */

/* Boundary evidence: original MIPS .pdata c05c636c..c05c6387. Semantic name remains unreviewed. */

void FUN_c05c636c(int param_1)

{
  *(undefined4 *)(param_1 + 0x304) = 0;
  FUN_c05c5a58(param_1);
  return;
}



/* c05c6388 FUN_c05c6388 */

/* Boundary evidence: original MIPS .pdata c05c6388..c05c64ab. Semantic name remains unreviewed. */

void FUN_c05c6388(int param_1,undefined4 *param_2)

{
  int iVar1;
  
  *(undefined4 *)(param_1 + 0x14c) = 0;
  if (((((param_2 != (undefined4 *)0x0) && (param_2[1] != 0)) && (param_2[2] != 0)) &&
      ((param_2[3] != 0 && (param_2[4] != 0)))) && (param_2[5] != 0)) {
    *(undefined4 *)(param_1 + 0x14c) = *param_2;
    *(undefined4 *)(param_1 + 0x94) = param_2[1];
    *(undefined4 *)(param_1 + 0x88) = param_2[3];
    *(undefined4 *)(param_1 + 0x8c) = param_2[4];
    *(undefined4 *)(param_1 + 0x90) = param_2[5];
    *(undefined4 *)(param_1 + 0x98) = param_2[2];
    iVar1 = param_2[6];
    *(int *)(param_1 + 0x2ec) = iVar1;
    *(undefined4 *)(param_1 + 0x2f0) = param_2[7];
    if ((iVar1 == 0) || (iVar1 == 4)) {
      *(undefined2 *)(param_1 + 0x2c0) = 1;
    }
    else if (iVar1 == 6) {
      *(undefined2 *)(param_1 + 0x2c0) = 2;
    }
    FUN_c05c5a58(param_1);
    *(undefined4 *)(param_1 + 0x1b4) = 0;
    memset((void *)(param_1 + 0x1b8),0,0xff);
    *(undefined4 *)(param_1 + 0x304) = 0;
    *(undefined1 *)(param_1 + 0x2c8) = 1;
    *(undefined4 *)(param_1 + 0x2d8) = 0;
    *(undefined4 *)(param_1 + 0x2e8) = *(undefined4 *)(param_1 + 0x6c);
    (**(code **)(param_1 + 0x90))(*(undefined4 *)(param_1 + 0x6c),param_1 + 0x2c9,param_1 + 0x2cf);
    *(undefined4 *)(param_1 + 0x300) = 0;
  }
  return;
}



/* c05c64ac FUN_c05c64ac */

/* Boundary evidence: original MIPS .pdata c05c64ac..c05c6903. Semantic name remains unreviewed. */

int FUN_c05c64ac(int *param_1,int param_2,int param_3)

{
  byte bVar1;
  HLOCAL hMem;
  int iVar2;
  size_t *_Dst;
  int *_Src;
  size_t _Size;
  uint uVar3;
  uint uVar4;
  undefined4 *_Buf2;
  HLOCAL local_108;
  uint local_104;
  int local_100;
  undefined4 *local_fc;
  void *local_f8;
  undefined4 *local_f4;
  size_t local_f0;
  undefined1 auStack_ec [32];
  size_t asStack_cc [8];
  void *local_ac;
  undefined1 local_a8;
  undefined1 local_a7;
  undefined4 local_a0;
  undefined1 local_9c;
  undefined1 local_9b;
  undefined4 local_9a;
  undefined1 local_96;
  undefined1 local_95;
  undefined1 auStack_94 [32];
  undefined1 auStack_74 [36];
  undefined1 auStack_50 [32];
  uint local_30;
  
  local_30 = DAT_c05ca1a8;
  local_f0 = 0;
  memset(auStack_ec,0,0x40);
  uVar3 = (uint)*(byte *)(param_2 + 4) + (uint)*(byte *)(param_2 + 3) * 0x100;
  if ((uVar3 == 0) || (0x20 < uVar3)) {
    FUN_c05c8248(local_30);
    return 0x57;
  }
  uVar4 = param_1[0x31];
  if ((uVar4 == 0) || (param_1[0x3a] == 0)) {
    _Src = param_1 + 0x41;
    if (*_Src == 0) {
      FUN_c05c8248(local_30);
      return 0xd;
    }
    _Dst = &local_f0;
    _Size = 0x44;
  }
  else {
    local_f0 = 0x20;
    if (uVar4 < 0x21) {
      local_f0 = uVar4;
    }
    memcpy(auStack_ec,param_1 + 0x29,local_f0);
    _Src = param_1 + 0x32;
    _Dst = asStack_cc;
    _Size = local_f0;
  }
  memcpy(_Dst,_Src,_Size);
  local_104 = 2000;
  hMem = LocalAlloc(0x40,2000);
  if (hMem == (HLOCAL)0x0) {
LAB_c05c65b4:
    FUN_c05c8248(local_30);
    return 8;
  }
  iVar2 = (*(code *)param_1[0x23])(param_1[0xba],0xd01011f,hMem,&local_104,&local_100);
  if (local_100 == 0) {
    if (iVar2 == -0x3fffffdd) {
      LocalFree(hMem);
      local_104 = 4000;
      hMem = LocalAlloc(0x40,4000);
      if (hMem == (HLOCAL)0x0) goto LAB_c05c65b4;
      iVar2 = (*(code *)param_1[0x23])(param_1[0xba],0xd01011f,hMem,&local_104,&local_100);
    }
    if (iVar2 != 0) goto LAB_c05c66ac;
    if (0x27 < local_104) {
      local_108 = (HLOCAL)0x0;
      iVar2 = (*(code *)param_1[0x25])
                        (*(int *)((int)hMem + 0x14) + (int)hMem,*(undefined4 *)((int)hMem + 0x10),
                         &local_108);
      if (iVar2 != 0) goto LAB_c05c66ac;
      if (local_108 != (HLOCAL)0x0) {
        bVar1 = *(byte *)((int)local_108 + 1);
        goto LAB_c05c66d4;
      }
    }
    iVar2 = 0x32;
  }
  else {
    if (iVar2 != 0) goto LAB_c05c66ac;
    bVar1 = *(byte *)((int)hMem + 1);
    local_108 = hMem;
LAB_c05c66d4:
    memset(param_1 + 0x5c,0,0x44);
    param_1[0x5c] = uVar3;
    FUN_c05c59e8(auStack_50);
    if ((code *)param_1[0x24] != (code *)0x0) {
      _Buf2 = (undefined4 *)((int)param_1 + 0x2cf);
      local_ac = (void *)*_Buf2;
      local_a7 = (undefined1)param_1[0xb5];
      local_a8 = *(undefined1 *)((int)param_1 + 0x2d3);
      (*(code *)param_1[0x24])(param_1[0x1b],(int)param_1 + 0x2c9,_Buf2);
      if ((param_1[0xbe] != 0) && (iVar2 = memcmp(&local_ac,_Buf2,6), iVar2 != 0)) {
        param_1[0xc1] = 0;
        FUN_c05c5a58((int)param_1);
      }
    }
    FUN_c05c596c((byte *)((int)param_1 + 0x2c9),(int)param_1 + 0x2cf,6,(int *)&local_f4,
                 (int *)&local_fc);
    FUN_c05c596c((byte *)(param_2 + 0xd),(int)auStack_50,0x20,(int *)&local_f8,(int *)&local_ac);
    local_a0 = *local_f4;
    local_9b = *(undefined1 *)((int)local_f4 + 5);
    local_9a = *local_fc;
    local_9c = *(undefined1 *)(local_f4 + 1);
    local_95 = *(undefined1 *)((int)local_fc + 5);
    local_96 = *(undefined1 *)(local_fc + 1);
    memcpy(auStack_94,local_f8,0x20);
    memcpy(auStack_74,local_ac,0x20);
    iVar2 = FUN_c05c5e90(auStack_ec,local_f0,"Pairwise key expansion",0x16,&local_a0,0x4c,
                         (undefined1 *)(param_1 + 0x5d),uVar3 + 0x20);
    if ((iVar2 == 0) && (param_3 != 0)) {
      iVar2 = FUN_c05c6138(param_1,(undefined1 *)(param_1 + 0x5d),(undefined4 *)(param_2 + 5),
                           *(ushort *)(param_1 + 0xb0) | 0x108,auStack_50,bVar1 + 2,local_108);
    }
  }
LAB_c05c66ac:
  LocalFree(hMem);
  FUN_c05c8248(local_30);
  return iVar2;
}



/* c05c6904 FUN_c05c6904 */

/* WARNING: Removing unreachable block (ram,0xc05c6b38) */
/* Boundary evidence: original MIPS .pdata c05c6904..c05c712b. Semantic name remains unreviewed. */

int FUN_c05c6904(int *param_1,void *param_2,uint param_3,undefined4 *param_4)

{
  ulonglong uVar1;
  bool bVar2;
  HLOCAL _Dst;
  int iVar3;
  undefined3 extraout_var;
  SIZE_T *_Dst_00;
  SIZE_T SVar4;
  uint uVar5;
  uint uVar6;
  size_t sVar7;
  ushort uVar8;
  uint uVar9;
  int iVar10;
  int iVar11;
  size_t _Size;
  undefined4 *puVar12;
  int *piVar13;
  int *_Src;
  undefined1 auStack_240 [52];
  uint local_20c;
  undefined4 local_1e0;
  int local_1ac;
  uint local_70;
  uint local_6c;
  int aiStack_68 [6];
  undefined1 auStack_50 [16];
  undefined1 auStack_40 [16];
  uint local_30;
  
  local_30 = DAT_c05ca1a8;
  iVar11 = 0;
  _Size = 0;
  *param_4 = 1;
  uVar1 = (ulonglong)local_70 << 0x20;
  if (param_3 < 99) goto LAB_c05c70ec;
  uVar9 = (uint)*(byte *)((int)param_2 + 5) * 0x100 + (uint)*(byte *)((int)param_2 + 6);
  uVar5 = uVar9 & 7;
  if (uVar5 != *(ushort *)(param_1 + 0xb0)) {
    iVar11 = 0x32;
    goto LAB_c05c70f0;
  }
  uVar6 = *(uint *)((int)param_2 + 9);
  local_6c = *(uint *)((int)param_2 + 0xd);
  uVar1 = (ulonglong)
          ((((uVar6 & 0xff) * 0x100 + (uVar6 >> 8 & 0xff)) * 0x100 + (uVar6 >> 0x10 & 0xff)) * 0x100
          + (uVar6 >> 0x18)) * 0x100 + (ulonglong)(byte)local_6c;
  uVar1 = (uVar1 & 0xffffffff) * 0x100 +
          (CONCAT44((int)(uVar1 >> 0x20) * 0x100,local_6c >> 8) & 0xffffffff000000ff);
  uVar1 = (uVar1 & 0xffffffff) * 0x100 +
          (CONCAT44((int)(uVar1 >> 0x20) * 0x100,local_6c >> 0x10) & 0xffffffff000000ff);
  uVar1 = (uVar1 & 0xffffffff) * 0x100 + CONCAT44((int)(uVar1 >> 0x20) * 0x100,local_6c >> 0x18);
  iVar10 = (int)uVar1;
  local_70 = (uint)(uVar1 >> 0x20);
  if ((uVar9 & 0x100) == 0) {
LAB_c05c6b4c:
    if ((uVar9 & 8) == 8) {
      iVar10 = param_1[0xc0];
      param_1[0xc0] = iVar10 + 1U;
      if (iVar10 + 1U < (uint)param_1[0xbf]) {
        iVar11 = FUN_c05c64ac(param_1,(int)param_2 + 4,(uint)((uVar9 & 0x80) != 0));
        if (iVar11 != 0) {
          *param_4 = 2;
        }
      }
      else {
        *param_4 = 2;
      }
      goto LAB_c05c70f0;
    }
  }
  else {
    if ((param_1[0xc1] != 0) && (uVar1 <= *(ulonglong *)(param_1 + 0xb8))) goto LAB_c05c70f0;
    if ((uVar9 & 0x100) == 0) goto LAB_c05c6b4c;
    uVar6 = uVar9 & 8;
    piVar13 = param_1 + 0x5d;
    if (uVar6 != 8) {
      piVar13 = param_1 + 0x54;
    }
    SVar4 = (uint)*(byte *)((int)param_2 + 2) * 0x100 + (uint)*(byte *)((int)param_2 + 3) + 4;
    _Dst = LocalAlloc(0x40,SVar4);
    if (_Dst == (HLOCAL)0x0) {
LAB_c05c6c0c:
      iVar11 = 8;
      goto LAB_c05c70f0;
    }
    memcpy(_Dst,param_2,SVar4);
    memset((void *)((int)_Dst + 0x51),0,0x10);
    memset(aiStack_68,0,0x14);
    if (uVar5 == 2) {
      FUN_c05c7e54(_Dst,SVar4,piVar13,0x10,(undefined1 *)aiStack_68,0x14);
    }
    else {
      FUN_c05c3788(_Dst,SVar4,(undefined1 *)piVar13,0x10,aiStack_68);
    }
    LocalFree(_Dst);
    iVar3 = memcmp(aiStack_68,(void *)((int)param_2 + 0x51),0x10);
    if (iVar3 != 0) goto LAB_c05c70f0;
    param_1[0xb8] = iVar10;
    param_1[0xb9] = local_70;
    _Src = (int *)0x0;
    if (uVar6 == 8) {
      memset(auStack_240,0,0xc4);
      uVar5 = (uint)*(byte *)((int)param_2 + 0x61) * 0x100 + (uint)*(byte *)((int)param_2 + 0x62);
      local_1e0 = 1;
      if ((((param_3 < uVar5 + 99) || (uVar5 < 6)) || (*(char *)((int)param_2 + 99) != -0x23)) ||
         (((*(byte *)((int)param_2 + 100) + 2 != uVar5 ||
           (iVar11 = (*(code *)param_1[0x26])
                               ((int)param_2 + 0x65,(uint)*(byte *)((int)param_2 + 100),auStack_240)
           , iVar11 != 0)) || ((local_1ac != param_1[0xbc] || (local_20c < (uint)param_1[0xbb]))))))
      goto LAB_c05c70f0;
      param_1[0x54] = param_1[0x5d];
      param_1[0x55] = param_1[0x5e];
      param_1[0x56] = param_1[0x5f];
      param_1[0x57] = param_1[0x60];
      param_1[0x58] = param_1[0x61];
      param_1[0x59] = param_1[0x62];
      param_1[0x5a] = param_1[99];
      param_1[0x5b] = param_1[100];
      puVar12 = param_4;
      if ((uVar9 & 0x40) != 0) {
        _Size = param_1[0x5c];
        _Src = param_1 + 0x65;
        param_1[0xc1] = 1;
        puVar12 = (undefined4 *)0xe0000000;
      }
LAB_c05c6f18:
      if ((((uVar9 & 0x80) != 0) && (uVar6 == 8)) &&
         (iVar11 = FUN_c05c6138(param_1,(undefined1 *)piVar13,(undefined4 *)((int)param_2 + 9),
                                *(ushort *)(param_1 + 0xb0) | 0x108,(void *)0x0,0,(void *)0x0),
         iVar11 != 0)) goto LAB_c05c70f0;
      if (_Src != (int *)0x0) {
        SVar4 = _Size + 0x20;
        _Dst_00 = LocalAlloc(0x40,SVar4);
        if (_Dst_00 == (SIZE_T *)0x0) goto LAB_c05c6c0c;
        memset(_Dst_00,0,SVar4);
        *_Dst_00 = SVar4;
        _Dst_00[2] = _Size;
        _Dst_00[1] = (SIZE_T)puVar12;
        _Dst_00[3] = *(SIZE_T *)((int)param_1 + 0x2cf);
        *(undefined2 *)(_Dst_00 + 4) = *(undefined2 *)((int)param_1 + 0x2d3);
        memcpy(_Dst_00 + 8,_Src,_Size);
        _Dst_00[6] = *(SIZE_T *)((int)param_2 + 0x41);
        _Dst_00[7] = *(SIZE_T *)((int)param_2 + 0x45);
        iVar10 = (*(code *)param_1[0x22])(param_1[0xba],0xd01011d,_Dst_00,*_Dst_00);
        iVar11 = 0;
        if (iVar10 != 0) {
          if (uVar6 == 8) {
            puVar12 = (undefined4 *)0x80000000;
          }
          memset(_Dst_00,0,_Size + 0xc);
          *_Dst_00 = _Size + 0xc;
          _Dst_00[2] = _Size;
          _Dst_00[1] = (SIZE_T)puVar12;
          memcpy(_Dst_00 + 3,_Src,_Size);
          iVar11 = (*(code *)param_1[0x22])(param_1[0xba],0xd010113,_Dst_00,*_Dst_00);
        }
        LocalFree(_Dst_00);
      }
      if (((uVar9 & 0x80) != 0) && (uVar6 == 0)) {
        uVar8 = *(ushort *)(param_1 + 0xb0) | 0x100;
        if ((uVar9 & 0x200) != 0) {
          uVar8 = *(ushort *)(param_1 + 0xb0) | 0x300;
          *param_4 = 0;
          param_1[0xc0] = 0;
        }
        iVar11 = FUN_c05c6138(param_1,(undefined1 *)piVar13,(undefined4 *)((int)param_2 + 9),uVar8,
                              (void *)0x0,0,(void *)0x0);
      }
      goto LAB_c05c70f0;
    }
    _Size = (uint)*(byte *)((int)param_2 + 8) + (uint)*(byte *)((int)param_2 + 7) * 0x100;
    sVar7 = (uint)*(byte *)((int)param_2 + 0x61) * 0x100 + (uint)*(byte *)((int)param_2 + 0x62);
    if (uVar5 == 2) {
      uVar1 = CONCAT44(local_70,iVar10);
      if ((_Size + 8 == sVar7) && (uVar1 = CONCAT44(local_70,iVar10), sVar7 + 99 <= param_3)) {
        bVar2 = FUN_c05c5aa0(param_1 + 0x58,0x10,(undefined4 *)((int)param_2 + 99),sVar7,aiStack_68)
        ;
        uVar1 = CONCAT44(local_70,iVar10);
        if (CONCAT31(extraout_var,bVar2) == 1) {
          _Src = aiStack_68;
          goto LAB_c05c6ef4;
        }
      }
    }
    else {
      uVar1 = CONCAT44(local_70,iVar10);
      if ((_Size == sVar7) && (uVar1 = CONCAT44(local_70,iVar10), sVar7 + 99 <= param_3)) {
        memcpy(auStack_50,(void *)((int)param_2 + 0x31),0x10);
        memcpy(auStack_40,param_1 + 0x58,0x10);
        FUN_c05c7d64();
        iVar11 = 0x10;
        do {
          FUN_c05c7d54();
          iVar11 = iVar11 + -1;
        } while (iVar11 != 0);
        _Src = (int *)((int)param_2 + 99);
        FUN_c05c7d54();
LAB_c05c6ef4:
        iVar11 = 0;
        uVar5 = uVar9 >> 4 & 3;
        puVar12 = (undefined4 *)(uVar5 | 0x20000000);
        if ((uVar9 & 0x40) != 0) {
          puVar12 = (undefined4 *)(uVar5 | 0xa0000000);
        }
        goto LAB_c05c6f18;
      }
    }
  }
LAB_c05c70ec:
  local_70 = (uint)(uVar1 >> 0x20);
  iVar11 = 0x57;
LAB_c05c70f0:
  FUN_c05c8248(local_30);
  return iVar11;
}



/* c05c712c FUN_c05c712c */

/* Boundary evidence: original MIPS .pdata c05c712c..c05c7173. Semantic name remains unreviewed. */

void FUN_c05c712c(int *param_1)

{
  int iVar1;
  
  if ((param_1[0x13] != 0) && (iVar1 = CTEStopTimer(param_1 + 0xc), iVar1 != 0)) {
    param_1[0x13] = 0;
    FUN_c05c1f44(param_1);
  }
  return;
}



/* c05c7174 FUN_c05c7174 */

/* Boundary evidence: original MIPS .pdata c05c7174..c05c721f. Semantic name remains unreviewed. */

void FUN_c05c7174(int *param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = param_1[8];
  if ((1 < iVar1) && (((iVar1 < 5 || ((5 < iVar1 && (iVar1 < 8)))) && (param_1[0x1f] != 0)))) {
    FUN_c05c712c(param_1);
    FUN_c05c16c8((int)param_1);
    param_1[0x13] = 1;
    iVar1 = CTEStartTimer(param_1 + 0xc,param_2,FUN_c05c796c,param_1);
    if (iVar1 == 0) {
      param_1[0x13] = 0;
      FUN_c05c1f44(param_1);
    }
  }
  return;
}



/* c05c7220 FUN_c05c7220 */

/* Boundary evidence: original MIPS .pdata c05c7220..c05c72a7. Semantic name remains unreviewed. */

void FUN_c05c7220(int param_1,int param_2)

{
  if ((DAT_c05ca12c & 1) != 0) {
    CxLogMsg(DAT_c05ca130 << 0x18 | 0x30001,"State %hs --> %hs",
             (&PTR_s_Logoff_c05ca188)[*(int *)(param_1 + 0x20)],(&PTR_s_Logoff_c05ca188)[param_2]);
  }
  *(int *)(param_1 + 0x20) = param_2;
  return;
}



/* c05c72a8 FUN_c05c72a8 */

/* Boundary evidence: original MIPS .pdata c05c72a8..c05c7303. Semantic name remains unreviewed. */

void FUN_c05c72a8(int *param_1)

{
  uint uVar1;
  
  FUN_c05c7220((int)param_1,7);
  uVar1 = param_1[0x19];
  if (999999 < (uint)param_1[0x19]) {
    uVar1 = 1000000;
  }
  FUN_c05c7174(param_1,uVar1 * 1000);
  return;
}



/* c05c7304 FUN_c05c7304 */

/* Boundary evidence: original MIPS .pdata c05c7304..c05c7337. Semantic name remains unreviewed. */

void FUN_c05c7304(int *param_1)

{
  FUN_c05c7220((int)param_1,5);
  FUN_c05c712c(param_1);
  return;
}



/* c05c7338 FUN_c05c7338 */

/* Boundary evidence: original MIPS .pdata c05c7338..c05c7393. Semantic name remains unreviewed. */

void FUN_c05c7338(int *param_1)

{
  uint uVar1;
  
  FUN_c05c7220((int)param_1,3);
  param_1[0x14] = 0;
  uVar1 = param_1[0x18];
  if (999999 < (uint)param_1[0x18]) {
    uVar1 = 1000000;
  }
  FUN_c05c7174(param_1,uVar1 * 1000);
  return;
}



/* c05c7394 FUN_c05c7394 */

/* Boundary evidence: original MIPS .pdata c05c7394..c05c75f3. Semantic name remains unreviewed. */

void FUN_c05c7394(int *param_1)

{
  size_t sVar1;
  size_t sVar2;
  size_t sVar3;
  char *pcVar4;
  int iVar5;
  uint uVar6;
  char *pcVar7;
  char *pcVar8;
  int *piVar9;
  undefined **ppuVar10;
  int *piVar11;
  undefined **ppuVar12;
  int local_38;
  char *local_34;
  char *local_2c;
  
  FUN_c05c7220((int)param_1,2);
  if (param_1[7] == 0) {
    if ((param_1[0x3e] == 0) || (*(int *)(param_1[0x3e] + 0x144) == 0)) {
      iVar5 = param_1[0x14];
      param_1[0x14] = iVar5 + 1;
      if ((iVar5 + 1 == 1) && (param_1[0x17] != 0)) {
        FUN_c05c7174(param_1,param_1[0x17]);
      }
      else {
        uVar6 = param_1[0x16];
        if (999999 < (uint)param_1[0x16]) {
          uVar6 = 1000000;
        }
        FUN_c05c7174(param_1,uVar6 * 1000);
        FUN_c05c7b8c(param_1);
      }
    }
  }
  else {
    FUN_c05c3040(param_1[10],&local_2c);
    pcVar8 = "";
    pcVar7 = local_2c;
    if (local_2c == (char *)0x0) {
      pcVar7 = pcVar8;
    }
    sVar1 = strlen(pcVar7);
    ppuVar12 = &PTR_s_networkid_c05c106c;
    piVar11 = param_1 + 0x3b;
    iVar5 = sVar1 + 1;
    local_34 = ",";
    pcVar4 = pcVar8;
    piVar9 = piVar11;
    ppuVar10 = ppuVar12;
    local_38 = iVar5;
    do {
      if (*piVar9 != 0) {
        sVar1 = strlen(pcVar4);
        sVar2 = strlen(*ppuVar10);
        sVar3 = strlen((char *)*piVar9);
        iVar5 = sVar3 + sVar2 + sVar1 + local_38 + 1;
        pcVar4 = ",";
        local_38 = iVar5;
      }
      ppuVar10 = ppuVar10 + 1;
      piVar9 = piVar9 + 1;
    } while ((int)ppuVar10 < -0x3fa3ef88);
    pcVar4 = LocalAlloc(0x40,iVar5 + 1);
    if (pcVar4 != (char *)0x0) {
      strcpy(pcVar4,pcVar7);
      sVar1 = strlen(pcVar4);
      pcVar7 = pcVar4 + sVar1 + 1;
      do {
        if (*piVar11 != 0) {
          iVar5 = sprintf(pcVar7,"%s%s=%s",pcVar8,*ppuVar12,*piVar11);
          pcVar7 = pcVar7 + iVar5;
          pcVar8 = local_34;
        }
        ppuVar12 = ppuVar12 + 1;
        piVar11 = piVar11 + 1;
      } while ((int)ppuVar12 < -0x3fa3ef88);
      EapSessionSendIdentityRequest(param_1[0x3e],pcVar4,local_38);
      LocalFree(pcVar4);
    }
    LocalFree(local_2c);
  }
  return;
}



/* c05c75f4 FUN_c05c75f4 */

/* Boundary evidence: original MIPS .pdata c05c75f4..c05c763b. Semantic name remains unreviewed. */

void FUN_c05c75f4(int *param_1)

{
  FUN_c05c7220((int)param_1,1);
  FUN_c05c712c(param_1);
  param_1[0x14] = 0;
  if (param_1[9] != 0) {
    FUN_c05c7394(param_1);
  }
  return;
}



/* c05c763c FUN_c05c763c */

/* Boundary evidence: original MIPS .pdata c05c763c..c05c76b3. Semantic name remains unreviewed. */

void FUN_c05c763c(int *param_1)

{
  uint uVar1;
  
  if ((1 < param_1[8]) && (param_1[8] < 7)) {
    FUN_c05c7220((int)param_1,6);
    uVar1 = param_1[0xbd];
    if (999999 < (uint)param_1[0xbd]) {
      uVar1 = 1000000;
    }
    FUN_c05c7174(param_1,uVar1 * 1000);
  }
  return;
}



/* c05c76b4 FUN_c05c76b4 */

/* Boundary evidence: original MIPS .pdata c05c76b4..c05c76db. Semantic name remains unreviewed. */

void FUN_c05c76b4(int *param_1)

{
  if (param_1[8] == 0) {
    FUN_c05c75f4(param_1);
  }
  return;
}



/* c05c76dc FUN_c05c76dc */

/* Boundary evidence: original MIPS .pdata c05c76dc..c05c7727. Semantic name remains unreviewed. */

void FUN_c05c76dc(int *param_1)

{
  if ((0 < param_1[8]) && (param_1[8] < 8)) {
    FUN_c05c7220((int)param_1,0);
    FUN_c05c7bb8(param_1);
  }
  return;
}



/* c05c7728 FUN_c05c7728 */

/* Boundary evidence: original MIPS .pdata c05c7728..c05c7763. Semantic name remains unreviewed. */

void FUN_c05c7728(int *param_1)

{
  param_1[9] = 1;
  param_1[0x14] = 0;
  if ((0 < param_1[8]) && (param_1[8] < 7)) {
    FUN_c05c7394(param_1);
  }
  return;
}



/* c05c7764 FUN_c05c7764 */

/* Boundary evidence: original MIPS .pdata c05c7764..c05c779b. Semantic name remains unreviewed. */

void FUN_c05c7764(int *param_1)

{
  param_1[9] = 0;
  if ((1 < param_1[8]) && (param_1[8] < 8)) {
    FUN_c05c75f4(param_1);
  }
  return;
}



/* c05c779c FUN_c05c779c */

undefined4 FUN_c05c779c(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if ((1 < *(int *)(param_1 + 0x20)) && (*(int *)(param_1 + 0x20) < 7)) {
    uVar1 = 1;
  }
  return uVar1;
}



/* c05c77c4 FUN_c05c77c4 */

/* Boundary evidence: original MIPS .pdata c05c77c4..c05c784b. Semantic name remains unreviewed. */

undefined4 FUN_c05c77c4(int param_1)

{
  if ((((*(int *)(param_1 + 0xf8) != 0) && (-1 < *(int *)(param_1 + 0x20))) &&
      (*(int *)(param_1 + 0x20) < 6)) &&
     (((*(int *)(*(int *)(param_1 + 0xf8) + 0x144) == 0 &&
       (EapSessionProcessRxPacket(), *(int *)(param_1 + 0x1c) != 0)) &&
      (*(int *)(*(int *)(param_1 + 0xf8) + 200) == 1)))) {
    FUN_c05c7220(param_1,4);
  }
  return 0;
}



/* c05c784c FUN_c05c784c */

/* Boundary evidence: original MIPS .pdata c05c784c..c05c7893. Semantic name remains unreviewed. */

undefined4 FUN_c05c784c(int *param_1)

{
  int iVar1;
  
  iVar1 = param_1[8];
  if (((iVar1 == 2) || (iVar1 == 4)) || (iVar1 == 5)) {
    FUN_c05c7394(param_1);
  }
  return 0;
}



/* c05c7894 FUN_c05c7894 */

/* Boundary evidence: original MIPS .pdata c05c7894..c05c78ef. Semantic name remains unreviewed. */

int FUN_c05c7894(int *param_1,void *param_2,uint param_3)

{
  int iVar1;
  
  iVar1 = FUN_c05c3b74(param_1,param_2,param_3);
  if ((iVar1 == 0x572) && (param_1[8] == 2)) {
    FUN_c05c7b8c(param_1);
  }
  return iVar1;
}



/* c05c78f0 FUN_c05c78f0 */

/* Boundary evidence: original MIPS .pdata c05c78f0..c05c796b. Semantic name remains unreviewed. */

void FUN_c05c78f0(int *param_1,void *param_2,int param_3)

{
  char cVar1;
  
  cVar1 = *(char *)((int)param_2 + 1);
  if (cVar1 == '\0') {
    FUN_c05c77c4((int)param_1);
  }
  else if (cVar1 == '\x01') {
    if (param_1[7] != 0) {
      FUN_c05c784c(param_1);
    }
  }
  else if ((cVar1 != '\x02') && (cVar1 == '\x03')) {
    FUN_c05c7894(param_1,param_2,param_3 + 4);
  }
  return;
}



/* c05c796c FUN_c05c796c */

/* Boundary evidence: original MIPS .pdata c05c796c..c05c7a43. Semantic name remains unreviewed. */

void FUN_c05c796c(undefined4 param_1,int *param_2)

{
  int iVar1;
  
  EnterCriticalSection((LPCRITICAL_SECTION)(param_2 + 2));
  if (param_2[0x13] != 0) {
    iVar1 = param_2[8];
    param_2[0x13] = 0;
    if (iVar1 == 2) {
      if ((uint)param_2[0x15] <= (uint)param_2[0x14]) {
        FUN_c05c7a44(param_2,0,(undefined1 *)0x0,0,1,0);
        goto LAB_c05c7a20;
      }
    }
    else if ((iVar1 < 3) || ((4 < iVar1 && ((iVar1 < 6 || (7 < iVar1)))))) goto LAB_c05c7a20;
    FUN_c05c7394(param_2);
  }
LAB_c05c7a20:
  LeaveCriticalSection((LPCRITICAL_SECTION)(param_2 + 2));
  FUN_c05c1f44(param_2);
  return;
}



/* c05c7a44 FUN_c05c7a44 */

/* Boundary evidence: original MIPS .pdata c05c7a44..c05c7b8b. Semantic name remains unreviewed. */

undefined4
FUN_c05c7a44(int *param_1,undefined1 param_2,undefined1 *param_3,int param_4,int param_5,int param_6
            )

{
  int iVar1;
  undefined4 uVar2;
  code *pcVar3;
  int iVar4;
  
  iVar4 = 0;
  uVar2 = 0;
  if (param_1[9] == 0) {
    param_3 = (undefined1 *)0x0;
  }
  if (param_3 != (undefined1 *)0x0) {
    *param_3 = 1;
    param_3[1] = param_2;
    iVar4 = param_4 + 4;
    param_3[2] = (char)((uint)param_4 >> 8);
    param_3[3] = (char)param_4;
  }
  if (param_5 != 0) {
    if (param_6 == 0) {
      iVar1 = param_1[0xbc];
      if ((((iVar1 == 3) || (iVar1 == 4)) || (iVar1 == 6)) || (iVar1 == 7)) {
        FUN_c05c763c(param_1);
        uVar2 = 1;
      }
      else {
        FUN_c05c7304(param_1);
        uVar2 = 2;
      }
    }
    else {
      FUN_c05c72a8(param_1);
      uVar2 = 3;
    }
  }
  if (((param_3 != (undefined1 *)0x0) || (param_5 != 0)) &&
     (pcVar3 = (code *)param_1[0x1f], pcVar3 != (code *)0x0)) {
    LeaveCriticalSection((LPCRITICAL_SECTION)(param_1 + 2));
    (*pcVar3)(param_1[0x1b],param_3,iVar4,uVar2,param_6);
    EnterCriticalSection((LPCRITICAL_SECTION)(param_1 + 2));
  }
  return 0;
}



/* c05c7b8c FUN_c05c7b8c */

/* Boundary evidence: original MIPS .pdata c05c7b8c..c05c7bb7. Semantic name remains unreviewed. */

void FUN_c05c7b8c(int *param_1)

{
  FUN_c05c7a44(param_1,1,(undefined1 *)param_1[0x1e],0,0,0);
  return;
}



/* c05c7bb8 FUN_c05c7bb8 */

/* Boundary evidence: original MIPS .pdata c05c7bb8..c05c7be3. Semantic name remains unreviewed. */

void FUN_c05c7bb8(int *param_1)

{
  FUN_c05c7a44(param_1,2,(undefined1 *)param_1[0x1e],0,0,0);
  return;
}



/* c05c7be4 FUN_c05c7be4 */

undefined4 FUN_c05c7be4(undefined4 param_1,int param_2,uint param_3,uint *param_4)

{
  undefined4 uVar1;
  uint uVar2;
  
  uVar1 = 0;
  uVar2 = 0;
  if (((3 < param_3) && (*(byte *)(param_2 + 1) < 4)) &&
     (uVar2 = (uint)CONCAT11(*(undefined1 *)(param_2 + 2),*(undefined1 *)(param_2 + 3)),
     uVar2 + 4 <= param_3)) {
    uVar1 = 1;
  }
  *param_4 = uVar2;
  return uVar1;
}



/* c05c7d24 FUN_c05c7d24 */

void FUN_c05c7d24(void)

{
                    /* WARNING: Could not recover jumptable at 0xc05c7d2c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*DAT_c05ca120)();
  return;
}



/* c05c7d34 FUN_c05c7d34 */

void FUN_c05c7d34(void)

{
                    /* WARNING: Could not recover jumptable at 0xc05c7d3c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*DAT_c05ca104)();
  return;
}



/* c05c7d44 FUN_c05c7d44 */

void FUN_c05c7d44(void)

{
                    /* WARNING: Could not recover jumptable at 0xc05c7d4c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*DAT_c05ca108)();
  return;
}



/* c05c7d54 FUN_c05c7d54 */

void FUN_c05c7d54(void)

{
                    /* WARNING: Could not recover jumptable at 0xc05c7d5c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*DAT_c05ca10c)();
  return;
}



/* c05c7d64 FUN_c05c7d64 */

void FUN_c05c7d64(void)

{
                    /* WARNING: Could not recover jumptable at 0xc05c7d6c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*DAT_c05ca11c)();
  return;
}



/* c05c7e54 FUN_c05c7e54 */

/* Boundary evidence: original MIPS .pdata c05c7e54..c05c807f. Semantic name remains unreviewed. */

void FUN_c05c7e54(undefined4 param_1,undefined4 param_2,void *param_3,uint param_4,
                 undefined1 *param_5,uint param_6)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint *puVar5;
  undefined1 *puVar6;
  undefined1 *_Src;
  int iVar7;
  uint local_180 [16];
  uint local_140 [16];
  undefined1 local_100 [192];
  undefined1 auStack_40 [20];
  uint local_2c;
  
  local_2c = DAT_c05ca1a8;
  _Src = auStack_40;
  if (0x13 < param_6) {
    _Src = param_5;
  }
  if (0x40 < param_4) {
    FUN_c05c8828();
    FUN_c05c8818();
    FUN_c05c8808();
    param_4 = 0x14;
  }
  iVar7 = 0x40;
  memset(local_140,0,0x40);
  memset(local_180,0,0x40);
  memcpy(local_140,param_3,param_4);
  memcpy(local_180,param_3,param_4);
  uVar1 = 0;
  do {
    uVar4 = *(uint *)((int)local_180 + uVar1 + 4);
    *(uint *)((int)local_140 + uVar1 + 4) = *(uint *)((int)local_140 + uVar1 + 4) ^ 0x36363636;
    *(uint *)((int)local_140 + uVar1) = *(uint *)((int)local_140 + uVar1) ^ 0x36363636;
    uVar2 = uVar1 + 8;
    *(uint *)((int)local_180 + uVar1 + 4) = uVar4 ^ 0x5c5c5c5c;
    *(uint *)((int)local_180 + uVar1) = *(uint *)((int)local_180 + uVar1) ^ 0x5c5c5c5c;
    uVar1 = uVar2;
  } while (uVar2 < 0x40);
  FUN_c05c8828();
  FUN_c05c8818();
  FUN_c05c8818();
  FUN_c05c8808();
  FUN_c05c8828();
  FUN_c05c8818();
  FUN_c05c8818();
  FUN_c05c8808();
  iVar3 = 0x40;
  puVar5 = local_140;
  do {
    *(undefined1 *)puVar5 = 0;
    iVar3 = iVar3 + -1;
    puVar5 = (uint *)((int)puVar5 + 1);
  } while (iVar3 != 0);
  puVar5 = local_180;
  do {
    *(undefined1 *)puVar5 = 0;
    iVar7 = iVar7 + -1;
    puVar5 = (uint *)((int)puVar5 + 1);
  } while (iVar7 != 0);
  iVar7 = 0x5c;
  puVar6 = local_100;
  do {
    *puVar6 = 0;
    iVar7 = iVar7 + -1;
    puVar6 = puVar6 + 1;
  } while (iVar7 != 0);
  if (_Src != param_5) {
    memcpy(param_5,_Src,param_6);
  }
  FUN_c05c8248(local_2c);
  return;
}



/* c05c8080 FUN_c05c8080 */

/* Boundary evidence: original MIPS .pdata c05c8080..c05c80df. Semantic name remains unreviewed. */

undefined * FUN_c05c8080(void)

{
  if ((DAT_c05ca200 & 1) == 0) {
    DAT_c05ca200 = DAT_c05ca200 | 1;
    InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_c05ca1ec);
    FUN_c05c84d4(FUN_c05c8884);
  }
  return &DAT_c05ca1ec;
}



/* c05c80e0 entry */

/* Boundary evidence: original MIPS .pdata c05c80e0..c05c8153. Semantic name remains unreviewed. */

undefined4 entry(HMODULE param_1,int param_2)

{
  undefined4 uVar1;
  
  if (param_2 == 1) {
    FUN_c05c8154();
    FUN_c05c869c();
  }
  uVar1 = DllEntry(param_1,param_2);
  if (param_2 == 0) {
    FUN_c05c8624();
  }
  return uVar1;
}



/* c05c8154 FUN_c05c8154 */

/* Boundary evidence: original MIPS .pdata c05c8154..c05c81c7. Semantic name remains unreviewed. */

void FUN_c05c8154(void)

{
  uint uVar1;
  
  if ((DAT_c05ca1a8 == 0) || (DAT_c05ca1a8 == 0xb064)) {
    uVar1 = __security_gen_cookie2();
    DAT_c05ca1a8 = uVar1 >> 0x10 ^ uVar1 & 0xffff;
    if (DAT_c05ca1a8 == 0) {
      DAT_c05ca1a8 = 0xb064;
    }
  }
  DAT_c05ca1ac = ~DAT_c05ca1a8;
  return;
}



/* c05c81c8 FUN_c05c81c8 */

/* Boundary evidence: original MIPS .pdata c05c81c8..c05c821b. Semantic name remains unreviewed. */

void FUN_c05c81c8(int param_1,undefined4 param_2,uint *param_3)

{
  if ((*param_3 & 1) != 0) {
    param_1 = ((-param_3[2] & param_3[1] + param_1) - (param_3[1] + param_1)) + param_1;
  }
  FUN_c05c8248(*(uint *)(param_1 + (*param_3 & 0xfffffffc)));
  return;
}



/* c05c821c FUN_c05c821c */

/* Boundary evidence: original MIPS .pdata c05c821c..c05c8247. Semantic name remains unreviewed. */

undefined4 FUN_c05c821c(undefined4 param_1,int param_2,undefined4 param_3,int param_4)

{
  FUN_c05c81c8(param_2,param_4,*(uint **)(*(int *)(param_4 + 4) + 0xc));
  return 1;
}



/* c05c8248 FUN_c05c8248 */

/* Boundary evidence: original MIPS .pdata c05c8248..c05c828f. Semantic name remains unreviewed. */

void FUN_c05c8248(uint param_1)

{
  if ((param_1 == DAT_c05ca1a8) && (param_1 >> 0x10 == 0)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __report_gsfailure();
}



/* c05c8290 FUN_c05c8290 */

/* Boundary evidence: original MIPS .pdata c05c8290..c05c839b. Semantic name remains unreviewed. */

undefined4 FUN_c05c8290(undefined4 param_1)

{
  void *_Memory;
  uint uVar1;
  void *pvVar2;
  uint _NewSize;
  undefined4 *puVar3;
  int iVar4;
  
  _Memory = DAT_c05ca20c;
  puVar3 = DAT_c05ca208;
  iVar4 = (int)DAT_c05ca208 - (int)DAT_c05ca20c;
  uVar1 = 0;
  if (iVar4 < 0) {
LAB_c05c82d4:
    param_1 = 0;
  }
  else {
    if (DAT_c05ca20c != (void *)0x0) {
      uVar1 = _msize(DAT_c05ca20c);
    }
    pvVar2 = _Memory;
    if (uVar1 < iVar4 + 4U) {
      if (_Memory == (void *)0x0) {
        pvVar2 = malloc(0x10);
LAB_c05c8348:
        if (pvVar2 == (void *)0x0) goto LAB_c05c82d4;
      }
      else {
        _NewSize = uVar1 << 1;
        if (0x200 < uVar1) {
          _NewSize = uVar1 + 0x200;
        }
        if ((_NewSize <= uVar1) || (pvVar2 = realloc(_Memory,_NewSize), pvVar2 == (void *)0x0)) {
          pvVar2 = realloc(_Memory,iVar4 + 4U);
          goto LAB_c05c8348;
        }
      }
      puVar3 = (undefined4 *)((iVar4 >> 2) * 4 + (int)pvVar2);
    }
    DAT_c05ca208 = puVar3 + 1;
    *puVar3 = param_1;
    DAT_c05ca20c = pvVar2;
  }
  return param_1;
}



/* c05c839c FUN_c05c839c */

/* Boundary evidence: original MIPS .pdata c05c839c..c05c8487. Semantic name remains unreviewed. */

undefined4 FUN_c05c839c(undefined4 param_1)

{
  LPCRITICAL_SECTION lpCriticalSection;
  LONG LVar1;
  undefined4 uVar2;
  
  if (DAT_c05ca210 == (LPCRITICAL_SECTION)0x0) {
    lpCriticalSection = malloc(0x14);
    if (lpCriticalSection != (LPCRITICAL_SECTION)0x0) {
      InitializeCriticalSection(lpCriticalSection);
      LVar1 = InterlockedCompareExchange((LONG *)&DAT_c05ca210,(LONG)lpCriticalSection,0);
      if (LVar1 != 0) {
        DeleteCriticalSection(lpCriticalSection);
        free(lpCriticalSection);
      }
    }
    if (DAT_c05ca210 == (LPCRITICAL_SECTION)0x0) goto LAB_c05c8440;
  }
  EnterCriticalSection(DAT_c05ca210);
LAB_c05c8440:
  uVar2 = FUN_c05c8290(param_1);
  FUN_c05c8488();
  return uVar2;
}



/* c05c8488 FUN_c05c8488 */

/* Boundary evidence: original MIPS .pdata c05c8488..c05c84d3. Semantic name remains unreviewed. */

void FUN_c05c8488(void)

{
  if (DAT_c05ca210 != (LPCRITICAL_SECTION)0x0) {
    LeaveCriticalSection(DAT_c05ca210);
  }
  return;
}



/* c05c84d4 FUN_c05c84d4 */

/* Boundary evidence: original MIPS .pdata c05c84d4..c05c8503. Semantic name remains unreviewed. */

undefined4 FUN_c05c84d4(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_c05c839c(param_1);
  if (iVar1 == 0) {
    uVar2 = 0xffffffff;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}



/* c05c8504 FUN_c05c8504 */

/* Boundary evidence: original MIPS .pdata c05c8504..c05c8623. Semantic name remains unreviewed. */

void FUN_c05c8504(UINT param_1,int param_2,int param_3)

{
  LPCRITICAL_SECTION lpCriticalSection;
  undefined4 *_Memory;
  
  DAT_c05ca205 = (undefined1)param_3;
  if (param_2 == 0) {
    _Memory = DAT_c05ca20c;
    if (DAT_c05ca20c != (undefined4 *)0x0) {
      while (DAT_c05ca208 = DAT_c05ca208 + -1, _Memory <= DAT_c05ca208) {
        if ((code *)*DAT_c05ca208 != (code *)0x0) {
          (*(code *)*DAT_c05ca208)();
          _Memory = DAT_c05ca20c;
        }
      }
      free(_Memory);
      DAT_c05ca208 = (undefined4 *)0x0;
      DAT_c05ca20c = (undefined4 *)0x0;
    }
    FUN_c05c8648((undefined4 *)&DAT_c05c1014,(undefined4 *)&DAT_c05c1018);
  }
  FUN_c05c8648((undefined4 *)&DAT_c05c101c,(undefined4 *)&DAT_c05c1020);
  if (param_3 == 0) {
    TerminateProcess((HANDLE)0x42,param_1);
  }
  else {
    lpCriticalSection = (LPCRITICAL_SECTION)InterlockedExchange(&DAT_c05ca210,0);
    if (lpCriticalSection != (LPCRITICAL_SECTION)0x0) {
      DeleteCriticalSection(lpCriticalSection);
      free(lpCriticalSection);
    }
  }
  return;
}



/* c05c8624 FUN_c05c8624 */

/* Boundary evidence: original MIPS .pdata c05c8624..c05c8647. Semantic name remains unreviewed. */

void FUN_c05c8624(void)

{
  FUN_c05c8504(0,0,1);
  return;
}



/* c05c8648 FUN_c05c8648 */

/* Boundary evidence: original MIPS .pdata c05c8648..c05c869b. Semantic name remains unreviewed. */

void FUN_c05c8648(undefined4 *param_1,undefined4 *param_2)

{
  for (; param_1 < param_2; param_1 = param_1 + 1) {
    if ((code *)*param_1 != (code *)0x0) {
      (*(code *)*param_1)();
    }
  }
  return;
}



/* c05c869c FUN_c05c869c */

/* Boundary evidence: original MIPS .pdata c05c869c..c05c86d7. Semantic name remains unreviewed. */

void FUN_c05c869c(void)

{
  FUN_c05c8648((undefined4 *)&DAT_c05c100c,(undefined4 *)&DAT_c05c1010);
  FUN_c05c8648((undefined4 *)&DAT_c05c1000,(undefined4 *)&DAT_c05c1008);
  return;
}



/* c05c8808 FUN_c05c8808 */

void FUN_c05c8808(void)

{
                    /* WARNING: Could not recover jumptable at 0xc05c8810. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*DAT_c05ca110)();
  return;
}



/* c05c8818 FUN_c05c8818 */

void FUN_c05c8818(void)

{
                    /* WARNING: Could not recover jumptable at 0xc05c8820. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*DAT_c05ca114)();
  return;
}



/* c05c8828 FUN_c05c8828 */

void FUN_c05c8828(void)

{
                    /* WARNING: Could not recover jumptable at 0xc05c8830. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*DAT_c05ca118)();
  return;
}



/* c05c8868 FUN_c05c8868 */

/* Boundary evidence: original MIPS .pdata c05c8868..c05c8883. Semantic name remains unreviewed. */

void FUN_c05c8868(void)

{
  FUN_c05c8080();
  return;
}



/* c05c8884 FUN_c05c8884 */

/* Boundary evidence: original MIPS .pdata c05c8884..c05c88a3. Semantic name remains unreviewed. */

void FUN_c05c8884(void)

{
  DeleteCriticalSection((LPCRITICAL_SECTION)&DAT_c05ca1ec);
  return;
}


